/*
 * Copyright © 2015 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include "nir.h"
#include "nir_builder.h"
#include "c99_math.h"

/*
 * Lowers some unsupported double operations, using only:
 *
 * - pack/unpackDouble2x32
 * - conversion to/from single-precision
 * - double add, mul, and fma
 * - conditional select
 * - 32-bit integer and floating point arithmetic
 */

static nir_ssa_def *
get_sign(nir_builder *b, nir_ssa_def *src)
{
   /* get bits 32-63 */
   nir_ssa_def *hi = nir_unpack_64_2x32_split_y(b, src);

   /* extract bit 31 of the high word */
   return nir_ubitfield_extract(b, hi, nir_imm_int(b, 31), nir_imm_int(b, 1));
}

/* Creates a double with the exponent bits set to a given integer value */
static nir_ssa_def *
set_exponent(nir_builder *b, nir_ssa_def *src, nir_ssa_def *exp)
{
   /* Split into bits 0-31 and 32-63 */
   nir_ssa_def *lo = nir_unpack_64_2x32_split_x(b, src);
   nir_ssa_def *hi = nir_unpack_64_2x32_split_y(b, src);

   /* The exponent is bits 52-62, or 20-30 of the high word, so set the exponent
    * to 1023
    */
   nir_ssa_def *new_hi = nir_bfi(b, nir_imm_int(b, 0x7ff00000), exp, hi);
   /* recombine */
   return nir_pack_64_2x32_split(b, lo, new_hi);
}

static nir_ssa_def *
get_exponent(nir_builder *b, nir_ssa_def *src)
{
   /* get bits 32-63 */
   nir_ssa_def *hi = nir_unpack_64_2x32_split_y(b, src);

   /* extract bits 20-30 of the high word */
   return nir_ubitfield_extract(b, hi, nir_imm_int(b, 20), nir_imm_int(b, 11));
}

static nir_ssa_def *
get_frac_hi(nir_builder *b, nir_ssa_def *src)
{
   /* get bits 32-63 */
   nir_ssa_def *hi = nir_unpack_64_2x32_split_y(b, src);

   /* extract bits 0-19 of the high word */
   return nir_ubitfield_extract(b, hi, nir_imm_int(b, 0), nir_imm_int(b, 20));
}

static nir_ssa_def *
get_frac_lo(nir_builder *b, nir_ssa_def *src)
{
   /* get bits 0-31 */
   return nir_unpack_64_2x32_split_x(b, src);
}

static nir_ssa_def *
pack_fp64(nir_builder *b, nir_ssa_def *z_si,
                          nir_ssa_def *z_exp,
                          nir_ssa_def *z_frac_hi, nir_ssa_def *z_frac_lo)
{
   nir_ssa_def *lo = z_frac_lo;
   nir_ssa_def *hi = nir_iadd(b,
                              nir_iadd(b,
                                       nir_ishl(b, z_si, nir_imm_int(b, 31)),
                                       nir_ishl(b, z_exp, nir_imm_int(b, 20))),
                              z_frac_hi);
   return nir_pack_64_2x32_split(b, lo, hi);
}

static nir_ssa_def *
is_nan(nir_builder *b, nir_ssa_def *src)
{
   nir_ssa_def *src_lo = nir_unpack_64_2x32_split_x(b, src);
   nir_ssa_def *src_hi = nir_unpack_64_2x32_split_y(b, src);

   /* return (0xFFE00000 <= (src_hi<<1)) &&
    *    (src_lo || (src_hi & 0x000FFFFF));
    */
   return nir_iand(b,
                   nir_uge(b,
                           nir_ishl(b, src_hi, nir_imm_int(b, 1)),
                           nir_imm_int(b, 0xFFE00000)),
                   nir_ior(b, src_lo,
                              nir_iand(b, src_hi,
                                          nir_imm_int(b, 0x000FFFFF))));
}

static nir_ssa_def *
is_signaling_nan(nir_builder *b, nir_ssa_def *src)
{
   nir_ssa_def *src_lo = nir_unpack_64_2x32_split_x(b, src);
   nir_ssa_def *src_hi = nir_unpack_64_2x32_split_y(b, src);

   /* return (((src_hi>>19) & 0xFFF) == 0xFFE ) &&
    *    (src_lo || (src_hi & 0x0007FFFF));
    */
   return nir_iand(b,
                   nir_ieq(b,
                           nir_iand(b,
                                    nir_ushr(b, src_hi, nir_imm_int(b, 19)),
                                    nir_imm_int(b, 0xFFF)),
                           nir_imm_int(b, 0xFFE)),
                   nir_ior(b,
                           nir_i2b(b, src_lo),
                           nir_iand(b,
                                    src_hi,
                                    nir_imm_int(b, 0x0007FFFF))));
}

/* Takes two double-precision floating-point values `a' and `b', one of which
 * is a NaN, and returns the appropriate NaN result.
 */
static nir_ssa_def *
propagate_fp64_nan(nir_builder *b, nir_ssa_def *x, nir_ssa_def *y)
{
   nir_ssa_def *x_is_nan = is_nan(b, x);
   nir_ssa_def *x_is_signaling_nan = is_signaling_nan(b, x);
   nir_ssa_def *y_is_nan = is_nan(b, y);

   nir_ssa_def *x_lo = nir_unpack_64_2x32_split_x(b, x);
   nir_ssa_def *x_hi = nir_unpack_64_2x32_split_y(b, x);
   nir_ssa_def *y_lo = nir_unpack_64_2x32_split_x(b, y);
   nir_ssa_def *y_hi = nir_unpack_64_2x32_split_y(b, y);

   x_hi = nir_ior(b, x_hi, nir_imm_int(b, 0x00080000));
   y_hi = nir_ior(b, y_hi, nir_imm_int(b, 0x00080000));
   x =  nir_pack_64_2x32_split(b, x_lo, x_hi);
   y =  nir_pack_64_2x32_split(b, y_lo, y_hi);

   return
      nir_bcsel(b,
                x_is_nan,
                nir_bcsel(b, nir_iand(b, x_is_signaling_nan, y_is_nan), y, x),
                y);
}

/* Shifts the 64-bit value formed by concatenating `src_hi' and `src_lo' left
 * by the number of bits given in `count'.  Any bits shifted off are lost.
 * The value of `count' must be less than 32.  The result is broken into two
 * 32-bit pieces which are stored at the locations pointed to by
 * `z0Ptr' and `z1Ptr'.
 */
static void
short_shl64(nir_builder *b, nir_ssa_def *src_hi, nir_ssa_def *src_lo,
                            nir_ssa_def *count,
                            nir_ssa_def **z0Ptr, nir_ssa_def **z1Ptr)
{
   /* z1Ptr = src_lo << count */
   *z1Ptr = nir_ishl(b, src_lo, count);

   /* z0Ptr = (count == 0) ? src_hi
    *                      : (src_hi << count) | (src_lo >> ((-count) & 31))
    */
   *z0Ptr = nir_bcsel(b,
                      nir_ieq(b, count, nir_imm_int(b, 0)),
                      src_hi,
                      nir_ior(b,
                              nir_ishl(b, src_hi, count),
                              nir_ushr(b, src_lo,
                                          nir_iand(b,
                                                   nir_ineg(b, count),
                                                   nir_imm_int(b, 31)))));
}

/* Shifts the 64-bit value formed by concatenating `src_0' and `src_1' right by
 * the number of bits given in `count'.  If any nonzero bits are shifted off,
 * they are "jammed" into the least significant bit of the result by setting the
 * least significant bit to 1.  The value of `count' can be arbitrarily large;
 * in particular, if `count' is greater than 64, the result will be either 0
 * or 1, depending on whether the concatenation of `src_0' and `src_1' is zero
 * or nonzero.  The result is broken into two 32-bit pieces which are stored at
 * the locations pointed to by `z0Ptr' and `z1Ptr'.
 */
static void
shift64_right_jamming(nir_builder *b, nir_ssa_def *src_0, nir_ssa_def *src_1,
                      nir_ssa_def *count,
                      nir_ssa_def **z0Ptr, nir_ssa_def **z1Ptr)
{
   nir_ssa_def *neg_count = nir_iand(b, nir_ineg(b, count), nir_imm_int(b, 31));

   nir_ssa_def *zero = nir_imm_int(b, 0);

   nir_ssa_def *is_count_0 = nir_ieq(b, count, zero);
   nir_ssa_def *is_count_lt32 = nir_ilt(b, count, nir_imm_int(b, 32));
   nir_ssa_def *is_count_32 = nir_ieq(b, count, nir_imm_int(b, 32));
   nir_ssa_def *is_count_lt64 = nir_ilt(b, count, nir_imm_int(b, 64));

   *z0Ptr = nir_bcsel(b,
                      is_count_0,
                      src_0,
                      nir_bcsel(b,
                                is_count_lt32,
                                nir_ushr(b, src_0, count),
                                zero));

   nir_ssa_def *z1_1 =
      nir_ior(b,
              nir_ishl(b, src_0, neg_count),
              nir_ior(b,
                      nir_ushr(b, src_1, count),
                      nir_b2i(b, nir_ine(b,
                                         nir_ishl(b, src_1, neg_count),
                                         zero))));

   nir_ssa_def *z1_2 = nir_ior(b, src_0, nir_b2i(b, nir_ine(b, src_1, zero)));

   nir_ssa_def *z1_3 =
      nir_ior(b,
              nir_ushr(b, src_0, nir_iand(b, count, nir_imm_int(b, 31))),
              nir_b2i(b,
                      nir_ine(b,
                              nir_ior(b, nir_ishl(b, src_0, neg_count), src_1),
                              zero)));

   nir_ssa_def *z1_4 = nir_b2i(b, nir_ine(b, nir_ior(b, src_0, src_1), zero));

   *z1Ptr =
      nir_bcsel(b,
                is_count_0,
                src_1,
                nir_bcsel(b,
                          is_count_lt32,
                          z1_1,
                          nir_bcsel(b,
                                    is_count_32,
                                    z1_2,
                                    nir_bcsel(b,
                                              is_count_lt64,
                                              z1_3,
                                              z1_4))));
}

/* Shifts the 96-bit value formed by concatenating `frac_0', `frac_1', and `frac_2'
 * right by 32 _plus_ the number of bits given in `count'.  The shifted result
 * is at most 64 nonzero bits; these are broken into two 32-bit pieces which are
 * stored at the locations pointed to by `z0Ptr' and `z1Ptr'.  The bits shifted
 * off form a third 32-bit result as follows:  The _last_ bit shifted off is
 * the most-significant bit of the extra result, and the other 31 bits of the
 * extra result are all zero if and only if _all_but_the_last_ bits shifted off
 * were all zero.  This extra result is stored in the location pointed to by
 * `z2Ptr'.  The value of `count' can be arbitrarily large.
 * (This routine makes more sense if `frac_0', `frac_1', and `frac_2' are considered
 * to form a fixed-point value with binary point between `frac_1' and `frac_2'.
 * This fixed-point value is shifted right by the number of bits given in `count',
 * and the integer part of the result is returned at the locations pointed to
 * by `z0Ptr' and `z1Ptr'.  The fractional part of the result may be slightly
 * corrupted as described above, and is returned at the location pointed to by
 * `z2Ptr'.)
 */
static void
shift64_extra_right_jamming(nir_builder *b,
                            nir_ssa_def *frac_0,
                            nir_ssa_def *frac_1,
                            nir_ssa_def *frac_2,
                            nir_ssa_def *count,
                            nir_ssa_def **z0Ptr,
                            nir_ssa_def **z1Ptr,
                            nir_ssa_def **z2Ptr)
{
   nir_ssa_def *zero = nir_imm_int(b, 0);
   nir_ssa_def *thirtyone = nir_imm_int(b, 31);
   nir_ssa_def *thirtytwo = nir_imm_int(b, 32);
   nir_ssa_def *sixtyfour = nir_imm_int(b, 64);

   nir_ssa_def *neg_count = nir_iand(b, nir_ineg(b, count), thirtyone);

   nir_ssa_def *is_count_0 = nir_ieq(b, count, zero);
   nir_ssa_def *is_count_lt32 = nir_ilt(b, count, thirtytwo);
   nir_ssa_def *is_count_32 = nir_ieq(b, count, thirtytwo);
   nir_ssa_def *is_count_lt64 = nir_ilt(b, count, sixtyfour);
   nir_ssa_def *is_count_64 = nir_ieq(b, count, sixtyfour);
   nir_ssa_def *is_frac_zero = nir_b2i(b, nir_ine(b, frac_0, zero));

   *z0Ptr = nir_bcsel(b,
                      is_count_0,
                      frac_0,
                      nir_bcsel(b,
                                is_count_lt32,
                                nir_ushr(b, frac_0, count),
                                zero));

   *z1Ptr =
      nir_bcsel(b,
                is_count_0,
                frac_1,
                nir_bcsel(b,
                          is_count_lt32,
                          nir_ior(b,
                                  nir_ishl(b, frac_0, neg_count),
                                  nir_ushr(b, frac_1, count)),
                          nir_bcsel(b,
                                    is_count_32,
                                    frac_0,
                                    nir_bcsel(b,
                                              is_count_lt64,
                                              nir_ushr(b,
                                                       frac_0,
                                                       nir_iand(b, count,
                                                                   thirtyone)),
                                              zero))));

   *z2Ptr =
      nir_bcsel(b,
                is_count_0,
                frac_2,
                nir_bcsel(b,
                          is_count_lt32,
                          nir_ior(b, nir_ishl(b, frac_1, neg_count),
                                     nir_b2i(b, nir_ine(b, frac_2, zero))),
                          nir_bcsel(b,
                                    is_count_32,
                                    nir_ior(b,
                                            frac_1,
                                            nir_b2i(b,
                                                    nir_ine(b, frac_2, zero))),
                                    nir_ior(b,
                                            nir_bcsel(b,
                                                      is_count_lt64,
                                                      nir_ishl(b, frac_0,
                                                                  neg_count),
                                                      nir_bcsel(b,
                                                                is_count_64,
                                                                frac_0,
                                                                is_frac_zero)),
                                            nir_b2i(b,
                                                    nir_ine(b,
                                                            nir_ior(b, frac_2,
                                                                       frac_1),
                                                            zero))))));
}

/* Returns the number of leading 0 bits before the most-significant 1 bit of
 * `src'.  If `src' is zero, 32 is returned.
 */
static nir_ssa_def *
count_leading_zeros(nir_builder *b, nir_ssa_def *src)
{
   return nir_isub(b, nir_imm_int(b, 31), nir_ufind_msb(b, src));
}

/* Normalizes the subnormal double-precision floating-point value represented
 * by the denormalized significand formed by the concatenation of `frac_hi' and
 * `frac_lo'.  The normalized exponent is stored at the location pointed to by
 * `zExpPtr'.  The most significant 21 bits of the normalized significand are
 * stored at the location pointed to by `zFrac0Ptr', and the least significant
 * 32 bits of the normalized significand are stored at the location pointed to
 * by `zFrac1Ptr'.
 */
static void
normalize_fp64_subnormal(nir_builder *b,
                         nir_ssa_def *frac_hi,
                         nir_ssa_def *frac_lo,
                         nir_ssa_def **zExpPtr,
                         nir_ssa_def **zFrac0Ptr,
                         nir_ssa_def **zFrac1Ptr)
{
   nir_ssa_def *shift_count_hi =
      nir_isub(b, count_leading_zeros(b, frac_hi), nir_imm_int(b, 11));
   nir_ssa_def *shift_count_lo =
      nir_isub(b, count_leading_zeros(b, frac_lo), nir_imm_int(b, 11));

   short_shl64(b, frac_hi, frac_lo, shift_count_hi, zFrac0Ptr, zFrac1Ptr);

   nir_ssa_def *is_frac_hi_zero = nir_ieq(b, frac_hi, nir_imm_int(b, 0));
   nir_ssa_def *is_shift_count_lo_neg = nir_ilt(b,
                                                shift_count_lo,
                                                nir_imm_int(b, 0));

   *zFrac0Ptr = nir_bcsel(b,
                          is_frac_hi_zero,
                          nir_bcsel(b,
                                    is_shift_count_lo_neg,
                                    nir_ushr(b, frac_lo,
                                                nir_ineg(b, shift_count_lo)),
                                    nir_ishl(b, frac_lo, shift_count_lo)),
                          *zFrac0Ptr);

   *zFrac1Ptr = nir_bcsel(b,
                          is_frac_hi_zero,
                          nir_bcsel(b,
                                    is_shift_count_lo_neg,
                                    nir_ishl(b, frac_lo,
                                                nir_iand(b,
                                                         shift_count_lo,
                                                         nir_imm_int(b, 31))),
                                    nir_imm_int(b, 0)),
                          *zFrac1Ptr);

   *zExpPtr = nir_bcsel(b,
                        is_frac_hi_zero,
                        nir_isub(b,
                                 nir_ineg(b, shift_count_lo),
                                 nir_imm_int(b, 31)),
                        nir_isub(b, nir_imm_int(b, 1), shift_count_hi));
}

/* Return infinity with the sign of the given source which is +/-0 */

static nir_ssa_def *
get_signed_inf(nir_builder *b, nir_ssa_def *zero)
{
   nir_ssa_def *zero_hi = nir_unpack_64_2x32_split_y(b, zero);

   /* The bit pattern for infinity is 0x7ff0000000000000, where the sign bit
    * is the highest bit. Only the sign bit can be non-zero in the passed in
    * source. So we essentially need to OR the infinity and the zero, except
    * the low 32 bits are always 0 so we can construct the correct high 32
    * bits and then pack it together with zero low 32 bits.
    */
   nir_ssa_def *inf_hi = nir_ior(b, nir_imm_int(b, 0x7ff00000), zero_hi);
   return nir_pack_64_2x32_split(b, nir_imm_int(b, 0), inf_hi);
}

/*
 * Generates the correctly-signed infinity if the source was zero, and flushes
 * the result to 0 if the source was infinity or the calculated exponent was
 * too small to be representable.
 */

static nir_ssa_def *
fix_inv_result(nir_builder *b, nir_ssa_def *res, nir_ssa_def *src,
               nir_ssa_def *exp)
{
   /* If the exponent is too small or the original input was infinity/NaN,
    * force the result to 0 (flush denorms) to avoid the work of handling
    * denorms properly. Note that this doesn't preserve positive/negative
    * zeros, but GLSL doesn't require it.
    */
   res = nir_bcsel(b, nir_ior(b, nir_ige(b, nir_imm_int(b, 0), exp),
                              nir_feq(b, nir_fabs(b, src),
                                      nir_imm_double(b, INFINITY))),
                   nir_imm_double(b, 0.0f), res);

   /* If the original input was 0, generate the correctly-signed infinity */
   res = nir_bcsel(b, nir_fne(b, src, nir_imm_double(b, 0.0f)),
                   res, get_signed_inf(b, src));

   return res;

}

static nir_ssa_def *
lt64(nir_builder *b, nir_ssa_def *x_hi, nir_ssa_def *x_lo,
                     nir_ssa_def *y_hi, nir_ssa_def *y_lo)
{
   nir_ssa_def *lt_hi = nir_ult(b, x_hi, y_hi);
   nir_ssa_def *eq_hi = nir_ieq(b, x_hi, y_hi);
   nir_ssa_def *lt_lo = nir_ult(b, x_lo, y_lo);

   /* return (x_hi < y_hi) || ((x_hi == y_hi) && (x_lo < y_lo)); */
   return nir_ior(b, lt_hi, nir_iand(b, eq_hi, lt_lo));
}

/* Adds the 64-bit value formed by concatenating `x_hi' and `x_lo' to the 64-bit
 * value formed by concatenating `b_hi' and `b_lo'.  Addition is modulo 2^64, so
 * any carry out is lost.  The result is broken into two 32-bit pieces which
 * are stored at the locations pointed to by `z0Ptr' and `z1Ptr'.
 */
static void
add64(nir_builder *b,
      nir_ssa_def *x_hi, nir_ssa_def *x_lo,
      nir_ssa_def *y_hi, nir_ssa_def *y_lo,
      nir_ssa_def **z0Ptr, nir_ssa_def **z1Ptr)
{
   nir_ssa_def *z = nir_iadd(b, x_lo, y_lo);
   *z1Ptr = z;
   *z0Ptr = nir_iadd(b, nir_iadd(b, x_hi, y_hi),
                        nir_b2i(b, nir_ult(b, z, x_lo)));
}

/* Subtracts the 64-bit value formed by concatenating `y_hi' and `y_lo' from the
 * 64-bit value formed by concatenating `x_hi' and `x_lo'.  Subtraction is modulo
 * 2^64, so any borrow out (carry out) is lost.  The result is broken into two
 * 32-bit pieces which are stored at the locations pointed to by `z0Ptr' and
 * `z1Ptr'.
 */
static void
sub64(nir_builder *b,
      nir_ssa_def *x_hi, nir_ssa_def *x_lo,
      nir_ssa_def *y_hi, nir_ssa_def *y_lo,
      nir_ssa_def **z0Ptr, nir_ssa_def **z1Ptr)
{
   *z1Ptr = nir_isub(b, x_lo, y_lo);
   *z0Ptr = nir_isub(b, nir_isub(b, x_hi, y_hi),
                        nir_b2i(b, nir_ult(b, x_lo, y_lo)));
}

/* Multiplies `x' by `y' to obtain a 64-bit product.  The product is broken
 * into two 32-bit pieces which are stored at the locations pointed to by
 * `z0Ptr' and `z1Ptr'.
 */
static void
mul32_to_64(nir_builder *b,
            nir_ssa_def *x, nir_ssa_def *y,
            nir_ssa_def **z0Ptr, nir_ssa_def **z1Ptr)
{
   nir_ssa_def *x_lo = nir_iand(b, x, nir_imm_int(b, 0x0000FFFF));
   nir_ssa_def *x_hi = nir_ushr(b, x, nir_imm_int(b, 16));
   nir_ssa_def *y_lo = nir_iand(b, y, nir_imm_int(b, 0x0000FFFF));
   nir_ssa_def *y_hi = nir_ushr(b, y, nir_imm_int(b, 16));
   nir_ssa_def *z1 = nir_imul(b, x_lo, y_lo);
   nir_ssa_def *z_mid_x = nir_imul(b, x_lo, y_hi);
   nir_ssa_def *z_mid_y = nir_imul(b, x_hi, y_lo);
   nir_ssa_def *z0 = nir_imul(b, x_hi, y_hi);
   z_mid_x = nir_iadd(b, z_mid_x, z_mid_y);
   z0 = nir_iadd(b, z0,
                    nir_iadd(b,
                             nir_ishl(b,
                                      nir_b2i(b, nir_ult(b, z_mid_x, z_mid_y)),
                                      nir_imm_int(b, 16)),
                             nir_ushr(b, z_mid_x, nir_imm_int(b, 16))));
   z_mid_x = nir_ishl(b, z_mid_x, nir_imm_int(b, 16));
   z1 = nir_iadd(b, z1, z_mid_x);
   z0 = nir_iadd(b, z0, nir_b2i(b, nir_ult(b, z1, z_mid_x)));
   *z1Ptr = z1;
   *z0Ptr = z0;
}

/* Multiplies the 64-bit value formed by concatenating `x_hi' and `x_lo' to the
 * 64-bit value formed by concatenating `y_hi' and `y_lo' to obtain a 128-bit
 * product.  The product is broken into four 32-bit pieces which are stored at
 * the locations pointed to by `z0Ptr', `z1Ptr', `z2Ptr', and `z3Ptr'.
 */
static void
mul64_to_128(nir_builder *b,
             nir_ssa_def *x_hi, nir_ssa_def *x_lo,
             nir_ssa_def *y_hi, nir_ssa_def *y_lo,
             nir_ssa_def **z0Ptr, nir_ssa_def **z1Ptr,
             nir_ssa_def **z2Ptr, nir_ssa_def **z3Ptr)
{
   nir_ssa_def *z0;
   nir_ssa_def *z1;
   nir_ssa_def *z2;
   nir_ssa_def *z3;
   nir_ssa_def *more1;
   nir_ssa_def *more2;
   nir_ssa_def *zero = nir_imm_int(b, 0);

   mul32_to_64(b, x_lo, y_lo, &z2, &z3);
   mul32_to_64(b, x_lo, y_hi, &z1, &more2);
   add64(b, z1, more2, zero, z2, &z1, &z2);
   mul32_to_64(b, x_hi, y_hi, &z0, &more1);
   add64(b, z0, more1, zero, z1, &z0, &z1);
   mul32_to_64(b, x_hi, y_lo, &more1, &more2);
   add64(b, more1, more2, zero, z2, &more1, &z2);
   add64(b, z0, z1, zero, more1, &z0, &z1);

   *z3Ptr = z3;
   *z2Ptr = z2;
   *z1Ptr = z1;
   *z0Ptr = z0;
}

static nir_ssa_def *
round_pack(nir_builder *b,
           nir_ssa_def *z_si,
           nir_ssa_def *z_exp,
           nir_ssa_def *z_frac_0,
           nir_ssa_def *z_frac_1,
           nir_ssa_def *z_frac_2,
           nir_ssa_def *increment,
           nir_ssa_def *round_nearest_even)
{
   nir_ssa_def *zero = nir_imm_int(b, 0);
   nir_ssa_def *one = nir_imm_int(b, 1);
   nir_ssa_def *z_frac_0_inc = z_frac_0;
   nir_ssa_def *z_frac_1_inc = z_frac_1;

   add64(b, z_frac_0, z_frac_1, zero, one, &z_frac_0_inc, &z_frac_1_inc);
   z_frac_1_inc =
      nir_iand(b,
               z_frac_1_inc,
               nir_inot(b,
                        nir_iand(b,
                                 nir_iadd(b, z_frac_2,
                                             nir_b2i(b, nir_ieq(b, z_frac_2,
                                                                   zero))),
                                 nir_b2i(b, round_nearest_even))));

   return nir_bcsel(b,
                    increment,
                    pack_fp64(b, z_si, z_exp, z_frac_0_inc, z_frac_1_inc),
                    nir_bcsel(b,
                              nir_ieq(b, nir_ior(b, z_frac_0, z_frac_1), zero),
                              pack_fp64(b, z_si, zero, z_frac_0, z_frac_1),
                              pack_fp64(b, z_si, z_exp, z_frac_0, z_frac_1)));
}

/* Takes an abstract floating-point value having sign `z_si', exponent `z_exp',
 * and extended significand formed by the concatenation of `z_frac_0', `z_frac_1',
 * and `z_frac_2', and returns the proper double-precision floating-point value
 * corresponding to the abstract input.  Ordinarily, the abstract value is
 * simply rounded and packed into the double-precision format, with the inexact
 * exception raised if the abstract input cannot be represented exactly.
 * However, if the abstract value is too large, the overflow and inexact
 * exceptions are raised and an infinity or maximal finite value is returned.
 * If the abstract value is too small, the input value is rounded to a
 * subnormal number, and the underflow and inexact exceptions are raised if the
 * abstract input cannot be represented exactly as a subnormal double-precision
 * floating-point number.
 *     The input significand must be normalized or smaller.  If the input
 * significand is not normalized, `z_exp' must be 0; in that case, the result
 * returned is a subnormal number, and it must not require rounding.  In the
 * usual case that the input significand is normalized, `z_exp' must be 1 less
 * than the "true" floating-point exponent.  The handling of underflow and
 * overflow follows the IEEE Standard for Floating-Point Arithmetic.
 */
static nir_ssa_def *
round_pack_fp64(nir_builder *b,
                nir_ssa_def *z_si,
                nir_ssa_def *z_exp,
                nir_ssa_def *z_frac_0,
                nir_ssa_def *z_frac_1,
                nir_ssa_def *z_frac_2)
{
   /* Software IEEE floating-point rounding mode.
    * GLSL spec section "4.7.1 Range and Precision":
    * The rounding mode cannot be set and is undefined.
    * But here, we are able to define the rounding mode at the compilation time.
    */
   nir_ssa_def *float_round_nearest_even = nir_imm_int(b, 0);
   nir_ssa_def *float_round_to_zero = nir_imm_int(b, 1);
   nir_ssa_def *float_round_down = nir_imm_int(b, 2);
   nir_ssa_def *float_round_up = nir_imm_int(b, 3);
   nir_ssa_def *rounding_mode = float_round_nearest_even;

   nir_ssa_def *round_nearest_even = nir_ieq(b, rounding_mode,
                                                float_round_nearest_even);

   nir_ssa_def *zero = nir_imm_int(b, 0);
   nir_ssa_def *increment =
      nir_bcsel(b,
                nir_ieq(b, round_nearest_even, zero),
                nir_bcsel(b,
                          nir_ieq(b, rounding_mode, float_round_to_zero),
                          zero,
                          nir_bcsel(b,
                                    nir_i2b(b, z_si),
                                    nir_iand(b,
                                             nir_ieq(b, rounding_mode,
                                                        float_round_down),
                                             nir_i2b(b, z_frac_2)),
                                    nir_iand(b,
                                             nir_ieq(b, rounding_mode,
                                                        float_round_up),
                                             nir_i2b(b, z_frac_2)))),
                nir_ilt(b, z_frac_2, zero));

   /* Handle NaN and Inf */
   nir_ssa_def *le_2045 = nir_ige(b, z_exp, nir_imm_int(b, 0x7FD));
   nir_ssa_def *lt_2045 = nir_ilt(b, nir_imm_int(b, 0x7FD), z_exp);
   nir_ssa_def *eq_2045 = nir_ieq(b, z_exp, nir_imm_int(b, 0x7FD));
   nir_ssa_def *frac_set = nir_iand(b,
                                    nir_ieq(b, z_frac_0,
                                               nir_imm_int(b, 0x001FFFFF)),
                                    nir_ieq(b, z_frac_1, nir_imm_int(b, ~0)));

   nir_ssa_def *cond_inf = nir_iand(b, lt_2045,
                                       nir_iand(b, eq_2045,
                                                   nir_iand(b, frac_set,
                                                               increment)));
   nir_ssa_def *cond_nan =
      nir_ior(b,
              nir_ior(b,
                      nir_ieq(b, rounding_mode, float_round_to_zero),
                      nir_iand(b,
                               nir_i2b(b, z_si),
                               nir_ieq(b, rounding_mode, float_round_up))),
              nir_iand(b,
                       nir_ieq(b, z_si, zero),
                       nir_ieq(b, rounding_mode, float_round_down)));

   nir_ssa_def *pack_nan =
      pack_fp64(b, z_si, nir_imm_int(b, 0x7FE),
                   nir_imm_int(b, 0x000FFFFF), nir_imm_int(b, ~0));
   nir_ssa_def *pack_inf =
      pack_fp64(b, z_si, nir_imm_int(b, 0x7FF), zero, zero);

   nir_ssa_def *z_frac_0_jam;
   nir_ssa_def *z_frac_1_jam;
   nir_ssa_def *z_frac_2_jam;
   shift64_extra_right_jamming(b, z_frac_0, z_frac_1, z_frac_2,
                                  nir_ineg(b, z_exp),
                                  &z_frac_0_jam, &z_frac_1_jam, &z_frac_2_jam);
   nir_ssa_def *inc_round_down =
      nir_iand(b, nir_ieq(b, rounding_mode, float_round_down), z_frac_2_jam);
   nir_ssa_def *inc_round_up =
      nir_iand(b, nir_ieq(b, rounding_mode, float_round_up), z_frac_2_jam);

   return
      nir_bcsel(b,
                le_2045,
                nir_bcsel(b,
                          cond_inf,
                          nir_bcsel(b, cond_nan, pack_nan, pack_inf),
                          nir_bcsel(b,
                                    nir_ilt(b, z_exp, zero),
                                    nir_bcsel(b,
                                              round_nearest_even,
                                              round_pack(b, z_si, zero,
                                                            z_frac_0_jam,
                                                            z_frac_1_jam,
                                                            z_frac_2_jam,
                                                            nir_ilt(b, z_frac_2_jam, zero),
                                                            round_nearest_even),
                                              nir_bcsel(b,
                                                        nir_i2b(b, z_si),
                                                        round_pack(b,
                                                                   z_si, zero,
                                                                   z_frac_0_jam,
                                                                   z_frac_1_jam,
                                                                   z_frac_2_jam,
                                                                   inc_round_down,
                                                                   round_nearest_even),
                                                        round_pack(b,
                                                                   z_si, zero,
                                                                   z_frac_0_jam,
                                                                   z_frac_1_jam,
                                                                   z_frac_2_jam,
                                                                   inc_round_up,
                                                                   round_nearest_even))),
                                    round_pack(b, z_si, z_exp,
                                                  z_frac_0, z_frac_1, z_frac_2,
                                                  increment, round_nearest_even))),
                round_pack(b, z_si, z_exp, z_frac_0, z_frac_1, z_frac_2,
                              increment, round_nearest_even));
}

/* Takes an abstract floating-point value having sign `z_si', exponent `z_exp',
 * and significand formed by the concatenation of `z_frac_hi' and `z_frac_lo',
 * and returns the proper double-precision floating-point value corresponding
 * to the abstract input.  This routine is just like `roundAndPackFloat64'
 * except that the input significand has fewer bits and does not have to be
 * normalized.  In all cases, `z_exp' must be 1 less than the "true" floating-
 * point exponent.
 */
static nir_ssa_def *
normalize_round_pack_fp64(nir_builder *b,
                          nir_ssa_def *z_si,
                          nir_ssa_def *z_exp,
                          nir_ssa_def *z_frac_hi,
                          nir_ssa_def *z_frac_lo)
{
   nir_ssa_def *zero = nir_imm_int(b, 0);
   nir_ssa_def *thirtytwo = nir_imm_int(b, 32);
   nir_ssa_def *is_z_frac_hi_zero = nir_ieq(b, z_frac_hi, zero);

   z_frac_hi =
      nir_bcsel(b, is_z_frac_hi_zero, z_frac_lo, z_frac_hi);

   z_frac_lo =
      nir_bcsel(b, is_z_frac_hi_zero, zero, z_frac_lo);

   z_exp =
      nir_bcsel(b, is_z_frac_hi_zero, nir_isub(b, z_exp, thirtytwo), z_exp);

   nir_ssa_def *shift_count =
      nir_isub(b, count_leading_zeros(b, z_frac_hi), nir_imm_int(b, 11));

   z_exp = nir_isub(b, z_exp, shift_count);

   nir_ssa_def *z_frac_hi_shl;
   nir_ssa_def *z_frac_lo_shl;
   nir_ssa_def *z_frac_tmp;

   /* Case 0 <= shift_count */
   short_shl64(b, z_frac_hi, z_frac_lo,
                  shift_count,
                  &z_frac_hi_shl, &z_frac_lo_shl);
   nir_ssa_def *pack_shl =
      round_pack_fp64(b, z_si, z_exp, z_frac_hi_shl, z_frac_lo_shl, zero);

   /* Case shift_count < 0 */
   shift64_extra_right_jamming(b, z_frac_hi, z_frac_lo,
                                  zero,
                                  nir_ineg(b, shift_count),
                                  &z_frac_hi, &z_frac_lo, &z_frac_tmp);
   nir_ssa_def *pack_shr =
      round_pack_fp64(b, z_si, z_exp, z_frac_hi, z_frac_lo, z_frac_tmp);

   return nir_bcsel(b, nir_ige(b, shift_count, zero), pack_shl, pack_shr);
}

static nir_ssa_def *
lower_rcp(nir_builder *b, nir_ssa_def *src)
{
   /* normalize the input to avoid range issues */
   nir_ssa_def *src_norm = set_exponent(b, src, nir_imm_int(b, 1023));

   /* cast to float, do an rcp, and then cast back to get an approximate
    * result
    */
   nir_ssa_def *ra = nir_f2f64(b, nir_frcp(b, nir_f2f32(b, src_norm)));

   /* Fixup the exponent of the result - note that we check if this is too
    * small below.
    */
   nir_ssa_def *new_exp = nir_isub(b, get_exponent(b, ra),
                                   nir_isub(b, get_exponent(b, src),
                                            nir_imm_int(b, 1023)));

   ra = set_exponent(b, ra, new_exp);

   /* Do a few Newton-Raphson steps to improve precision.
    *
    * Each step doubles the precision, and we started off with around 24 bits,
    * so we only need to do 2 steps to get to full precision. The step is:
    *
    * x_new = x * (2 - x*src)
    *
    * But we can re-arrange this to improve precision by using another fused
    * multiply-add:
    *
    * x_new = x + x * (1 - x*src)
    *
    * See https://en.wikipedia.org/wiki/Division_algorithm for more details.
    */

   ra = nir_ffma(b, ra, nir_ffma(b, ra, src, nir_imm_double(b, -1)), ra);
   ra = nir_ffma(b, ra, nir_ffma(b, ra, src, nir_imm_double(b, -1)), ra);

   return fix_inv_result(b, ra, src, new_exp);
}

static nir_ssa_def *
lower_sqrt_rsq(nir_builder *b, nir_ssa_def *src, bool sqrt)
{
   /* We want to compute:
    *
    * 1/sqrt(m * 2^e)
    *
    * When the exponent is even, this is equivalent to:
    *
    * 1/sqrt(m) * 2^(-e/2)
    *
    * and then the exponent is odd, this is equal to:
    *
    * 1/sqrt(m * 2) * 2^(-(e - 1)/2)
    *
    * where the m * 2 is absorbed into the exponent. So we want the exponent
    * inside the square root to be 1 if e is odd and 0 if e is even, and we
    * want to subtract off e/2 from the final exponent, rounded to negative
    * infinity. We can do the former by first computing the unbiased exponent,
    * and then AND'ing it with 1 to get 0 or 1, and we can do the latter by
    * shifting right by 1.
    */

   nir_ssa_def *unbiased_exp = nir_isub(b, get_exponent(b, src),
                                        nir_imm_int(b, 1023));
   nir_ssa_def *even = nir_iand(b, unbiased_exp, nir_imm_int(b, 1));
   nir_ssa_def *half = nir_ishr(b, unbiased_exp, nir_imm_int(b, 1));

   nir_ssa_def *src_norm = set_exponent(b, src,
                                        nir_iadd(b, nir_imm_int(b, 1023),
                                                 even));

   nir_ssa_def *ra = nir_f2f64(b, nir_frsq(b, nir_f2f32(b, src_norm)));
   nir_ssa_def *new_exp = nir_isub(b, get_exponent(b, ra), half);
   ra = set_exponent(b, ra, new_exp);

   /*
    * The following implements an iterative algorithm that's very similar
    * between sqrt and rsqrt. We start with an iteration of Goldschmit's
    * algorithm, which looks like:
    *
    * a = the source
    * y_0 = initial (single-precision) rsqrt estimate
    *
    * h_0 = .5 * y_0
    * g_0 = a * y_0
    * r_0 = .5 - h_0 * g_0
    * g_1 = g_0 * r_0 + g_0
    * h_1 = h_0 * r_0 + h_0
    *
    * Now g_1 ~= sqrt(a), and h_1 ~= 1/(2 * sqrt(a)). We could continue
    * applying another round of Goldschmit, but since we would never refer
    * back to a (the original source), we would add too much rounding error.
    * So instead, we do one last round of Newton-Raphson, which has better
    * rounding characteristics, to get the final rounding correct. This is
    * split into two cases:
    *
    * 1. sqrt
    *
    * Normally, doing a round of Newton-Raphson for sqrt involves taking a
    * reciprocal of the original estimate, which is slow since it isn't
    * supported in HW. But we can take advantage of the fact that we already
    * computed a good estimate of 1/(2 * g_1) by rearranging it like so:
    *
    * g_2 = .5 * (g_1 + a / g_1)
    *     = g_1 + .5 * (a / g_1 - g_1)
    *     = g_1 + (.5 / g_1) * (a - g_1^2)
    *     = g_1 + h_1 * (a - g_1^2)
    *
    * The second term represents the error, and by splitting it out we can get
    * better precision by computing it as part of a fused multiply-add. Since
    * both Newton-Raphson and Goldschmit approximately double the precision of
    * the result, these two steps should be enough.
    *
    * 2. rsqrt
    *
    * First off, note that the first round of the Goldschmit algorithm is
    * really just a Newton-Raphson step in disguise:
    *
    * h_1 = h_0 * (.5 - h_0 * g_0) + h_0
    *     = h_0 * (1.5 - h_0 * g_0)
    *     = h_0 * (1.5 - .5 * a * y_0^2)
    *     = (.5 * y_0) * (1.5 - .5 * a * y_0^2)
    *
    * which is the standard formula multiplied by .5. Unlike in the sqrt case,
    * we don't need the inverse to do a Newton-Raphson step; we just need h_1,
    * so we can skip the calculation of g_1. Instead, we simply do another
    * Newton-Raphson step:
    *
    * y_1 = 2 * h_1
    * r_1 = .5 - h_1 * y_1 * a
    * y_2 = y_1 * r_1 + y_1
    *
    * Where the difference from Goldschmit is that we calculate y_1 * a
    * instead of using g_1. Doing it this way should be as fast as computing
    * y_1 up front instead of h_1, and it lets us share the code for the
    * initial Goldschmit step with the sqrt case.
    *
    * Putting it together, the computations are:
    *
    * h_0 = .5 * y_0
    * g_0 = a * y_0
    * r_0 = .5 - h_0 * g_0
    * h_1 = h_0 * r_0 + h_0
    * if sqrt:
    *    g_1 = g_0 * r_0 + g_0
    *    r_1 = a - g_1 * g_1
    *    g_2 = h_1 * r_1 + g_1
    * else:
    *    y_1 = 2 * h_1
    *    r_1 = .5 - y_1 * (h_1 * a)
    *    y_2 = y_1 * r_1 + y_1
    *
    * For more on the ideas behind this, see "Software Division and Square
    * Root Using Goldschmit's Algorithms" by Markstein and the Wikipedia page
    * on square roots
    * (https://en.wikipedia.org/wiki/Methods_of_computing_square_roots).
    */

   nir_ssa_def *one_half = nir_imm_double(b, 0.5);
   nir_ssa_def *h_0 = nir_fmul(b, one_half, ra);
   nir_ssa_def *g_0 = nir_fmul(b, src, ra);
   nir_ssa_def *r_0 = nir_ffma(b, nir_fneg(b, h_0), g_0, one_half);
   nir_ssa_def *h_1 = nir_ffma(b, h_0, r_0, h_0);
   nir_ssa_def *res;
   if (sqrt) {
      nir_ssa_def *g_1 = nir_ffma(b, g_0, r_0, g_0);
      nir_ssa_def *r_1 = nir_ffma(b, nir_fneg(b, g_1), g_1, src);
      res = nir_ffma(b, h_1, r_1, g_1);
   } else {
      nir_ssa_def *y_1 = nir_fmul(b, nir_imm_double(b, 2.0), h_1);
      nir_ssa_def *r_1 = nir_ffma(b, nir_fneg(b, y_1), nir_fmul(b, h_1, src),
                                  one_half);
      res = nir_ffma(b, y_1, r_1, y_1);
   }

   if (sqrt) {
      /* Here, the special cases we need to handle are
       * 0 -> 0 and
       * +inf -> +inf
       */
      res = nir_bcsel(b, nir_ior(b, nir_feq(b, src, nir_imm_double(b, 0.0)),
                                 nir_feq(b, src, nir_imm_double(b, INFINITY))),
                                 src, res);
   } else {
      res = fix_inv_result(b, res, src, new_exp);
   }

   return res;
}

static nir_ssa_def *
lower_trunc(nir_builder *b, nir_ssa_def *src)
{
   nir_ssa_def *unbiased_exp = nir_isub(b, get_exponent(b, src),
                                        nir_imm_int(b, 1023));

   nir_ssa_def *frac_bits = nir_isub(b, nir_imm_int(b, 52), unbiased_exp);

   /*
    * Decide the operation to apply depending on the unbiased exponent:
    *
    * if (unbiased_exp < 0)
    *    return 0
    * else if (unbiased_exp > 52)
    *    return src
    * else
    *    return src & (~0 << frac_bits)
    *
    * Notice that the else branch is a 64-bit integer operation that we need
    * to implement in terms of 32-bit integer arithmetics (at least until we
    * support 64-bit integer arithmetics).
    */

   /* Compute "~0 << frac_bits" in terms of hi/lo 32-bit integer math */
   nir_ssa_def *mask_lo =
      nir_bcsel(b,
                nir_ige(b, frac_bits, nir_imm_int(b, 32)),
                nir_imm_int(b, 0),
                nir_ishl(b, nir_imm_int(b, ~0), frac_bits));

   nir_ssa_def *mask_hi =
      nir_bcsel(b,
                nir_ilt(b, frac_bits, nir_imm_int(b, 33)),
                nir_imm_int(b, ~0),
                nir_ishl(b,
                         nir_imm_int(b, ~0),
                         nir_isub(b, frac_bits, nir_imm_int(b, 32))));

   nir_ssa_def *src_lo = nir_unpack_64_2x32_split_x(b, src);
   nir_ssa_def *src_hi = nir_unpack_64_2x32_split_y(b, src);

   return
      nir_bcsel(b,
                nir_ilt(b, unbiased_exp, nir_imm_int(b, 0)),
                nir_imm_double(b, 0.0),
                nir_bcsel(b, nir_ige(b, unbiased_exp, nir_imm_int(b, 53)),
                          src,
                          nir_pack_64_2x32_split(b,
                                                 nir_iand(b, mask_lo, src_lo),
                                                 nir_iand(b, mask_hi, src_hi))));
}

static nir_ssa_def *
lower_floor(nir_builder *b, nir_ssa_def *src)
{
   /*
    * For x >= 0, floor(x) = trunc(x)
    * For x < 0,
    *    - if x is integer, floor(x) = x
    *    - otherwise, floor(x) = trunc(x) - 1
    */
   nir_ssa_def *tr = nir_ftrunc(b, src);
   nir_ssa_def *positive = nir_fge(b, src, nir_imm_double(b, 0.0));
   return nir_bcsel(b,
                    nir_ior(b, positive, nir_feq(b, src, tr)),
                    tr,
                    nir_fsub(b, tr, nir_imm_double(b, 1.0)));
}

static nir_ssa_def *
lower_ceil(nir_builder *b, nir_ssa_def *src)
{
   /* if x < 0,                    ceil(x) = trunc(x)
    * else if (x - trunc(x) == 0), ceil(x) = x
    * else,                        ceil(x) = trunc(x) + 1
    */
   nir_ssa_def *tr = nir_ftrunc(b, src);
   nir_ssa_def *negative = nir_flt(b, src, nir_imm_double(b, 0.0));
   return nir_bcsel(b,
                    nir_ior(b, negative, nir_feq(b, src, tr)),
                    tr,
                    nir_fadd(b, tr, nir_imm_double(b, 1.0)));
}

static nir_ssa_def *
lower_fract(nir_builder *b, nir_ssa_def *src)
{
   return nir_fsub(b, src, nir_ffloor(b, src));
}

static nir_ssa_def *
lower_round_even(nir_builder *b, nir_ssa_def *src)
{
   /* If fract(src) == 0.5, then we will have to decide the rounding direction.
    * We will do this by computing the mod(abs(src), 2) and testing if it
    * is < 1 or not.
    *
    * We compute mod(abs(src), 2) as:
    * abs(src) - 2.0 * floor(abs(src) / 2.0)
    */
   nir_ssa_def *two = nir_imm_double(b, 2.0);
   nir_ssa_def *abs_src = nir_fabs(b, src);
   nir_ssa_def *mod =
      nir_fsub(b,
               abs_src,
               nir_fmul(b,
                        two,
                        nir_ffloor(b,
                                   nir_fmul(b,
                                            abs_src,
                                            nir_imm_double(b, 0.5)))));

   /*
    * If fract(src) != 0.5, then we round as floor(src + 0.5)
    *
    * If fract(src) == 0.5, then we have to check the modulo:
    *
    *   if it is < 1 we need a trunc operation so we get:
    *      0.5 -> 0,   -0.5 -> -0
    *      2.5 -> 2,   -2.5 -> -2
    *
    *   otherwise we need to check if src >= 0, in which case we need to round
    *   upwards, or not, in which case we need to round downwards so we get:
    *      1.5 -> 2,   -1.5 -> -2
    *      3.5 -> 4,   -3.5 -> -4
    */
   nir_ssa_def *fract = nir_ffract(b, src);
   return nir_bcsel(b,
                    nir_fne(b, fract, nir_imm_double(b, 0.5)),
                    nir_ffloor(b, nir_fadd(b, src, nir_imm_double(b, 0.5))),
                    nir_bcsel(b,
                              nir_flt(b, mod, nir_imm_double(b, 1.0)),
                              nir_ftrunc(b, src),
                              nir_bcsel(b,
                                        nir_fge(b, src, nir_imm_double(b, 0.0)),
                                        nir_fadd(b, src, nir_imm_double(b, 0.5)),
                                        nir_fsub(b, src, nir_imm_double(b, 0.5)))));
}

static nir_ssa_def *
lower_mod(nir_builder *b, nir_ssa_def *src0, nir_ssa_def *src1)
{
   /* mod(x,y) = x - y * floor(x/y)
    *
    * If the division is lowered, it could add some rounding errors that make
    * floor() to return the quotient minus one when x = N * y. If this is the
    * case, we return zero because mod(x, y) output value is [0, y).
    */
   nir_ssa_def *floor = nir_ffloor(b, nir_fdiv(b, src0, src1));
   nir_ssa_def *mod = nir_fsub(b, src0, nir_fmul(b, src1, floor));

   return nir_bcsel(b,
                    nir_fne(b, mod, src1),
                    mod,
                    nir_imm_double(b, 0.0));
}

static nir_ssa_def *
lower_fabs64(nir_builder *b, nir_ssa_def *src)
{
   nir_ssa_def *src_lo = nir_unpack_64_2x32_split_x(b, src);
   nir_ssa_def *src_hi = nir_unpack_64_2x32_split_y(b, src);
   /* Clear the sign bit */
   nir_ssa_def *new_src_hi = nir_iand(b, src_hi, nir_imm_int(b, 0x7FFFFFFF));
   return nir_pack_64_2x32_split(b, src_lo, new_src_hi);
}

static nir_ssa_def *
lower_fneg64(nir_builder *b, nir_ssa_def *src)
{
   nir_ssa_def *src_lo = nir_unpack_64_2x32_split_x(b, src);
   nir_ssa_def *src_hi = nir_unpack_64_2x32_split_y(b, src);
   src_hi = nir_ixor(b, src_hi,
                        nir_ishl(b,
                                 nir_imm_int(b, 1),
                                 nir_imm_int(b, 31)));

   /* Return the negate value of the src.
    * If the src is not a number (NaN), return the src.
    */
   return nir_bcsel(b, is_nan(b, src),
                       src,
                       nir_pack_64_2x32_split(b, src_lo, src_hi));
}

static nir_ssa_def *
lower_fsign64(nir_builder *b, nir_ssa_def *src)
{
   nir_ssa_def *src_lo = nir_unpack_64_2x32_split_x(b, src);
   nir_ssa_def *src_hi = nir_unpack_64_2x32_split_y(b, src);

   nir_ssa_def *is_zero = nir_ieq(b,
                                  nir_ior(b,
                                          nir_ishl(b, src_hi,
                                                      nir_imm_int(b, 1)),
                                          src_lo),
                                  nir_imm_int(b, 0));

   nir_ssa_def *sign = nir_iand(b, src_hi, nir_imm_int(b, 0x80000000));
   /* High part of the number one in double precision */
   nir_ssa_def *one = nir_imm_int(b, 0x3FF00000);

   return nir_bcsel(b,
                    is_zero,
                    nir_imm_double(b, 0),
                    nir_pack_64_2x32_split(b,
                                           nir_imm_int(b, 0),
                                           nir_ior(b, sign, one)));
}

static nir_ssa_def *
lower_feq64(nir_builder *b, nir_ssa_def *x, nir_ssa_def *y)
{
   nir_ssa_def *x_lo = nir_unpack_64_2x32_split_x(b, x);
   nir_ssa_def *x_hi = nir_unpack_64_2x32_split_y(b, x);
   nir_ssa_def *y_lo = nir_unpack_64_2x32_split_x(b, y);
   nir_ssa_def *y_hi = nir_unpack_64_2x32_split_y(b, y);

   nir_ssa_def *eq_lo = nir_ieq(b, x_lo, y_lo);
   nir_ssa_def *eq_hi = nir_ieq(b, x_hi, y_hi);
   nir_ssa_def *eq_x_lo = nir_ieq(b, x_lo, nir_imm_int(b, 0));
   nir_ssa_def *eq_xy_hi = nir_ieq(b, nir_ishl(b, nir_ior(b, x_hi, y_hi),
                                                  nir_imm_int(b, 1)),
                                      nir_imm_int(b, 0));
   /* if x or y is a nan
    *    return false;
    * else
    *    return (x_lo == y_lo) &&
    *       ((x_hi == y_hi) ||
    *       ((x_lo == 0) && (((x_hi | y_hi)<<1) == 0)));
    */
   return nir_bcsel(b, nir_ior(b, is_nan(b, x), is_nan(b, y)),
                       nir_imm_int(b, NIR_FALSE),
                       nir_iand(b, eq_lo,
                                   nir_ior(b,
                                           eq_hi,
                                           nir_iand(b, eq_x_lo, eq_xy_hi))));
}

static nir_ssa_def *
lower_flt64(nir_builder *b, nir_ssa_def *x, nir_ssa_def *y)
{
   nir_ssa_def *x_si = get_sign(b, x);
   nir_ssa_def *x_lo = nir_unpack_64_2x32_split_x(b, x);
   nir_ssa_def *x_hi = nir_unpack_64_2x32_split_y(b, x);
   nir_ssa_def *y_si = get_sign(b, y);
   nir_ssa_def *y_lo = nir_unpack_64_2x32_split_x(b, y);
   nir_ssa_def *y_hi = nir_unpack_64_2x32_split_y(b, y);

   nir_ssa_def *xy_lo = nir_ior(b, x_lo, y_lo);
   nir_ssa_def *xy_hi = nir_ior(b, x_hi, y_hi);
   nir_ssa_def *shl_xy_hi = nir_ishl(b, xy_hi, nir_imm_int(b, 1));
   nir_ssa_def *xy_hi_lo_si = nir_ior(b, shl_xy_hi, xy_lo);
   nir_ssa_def *ne_xy = nir_ine(b, xy_hi_lo_si, nir_imm_int(b, 0));

   /* if x or y is a nan
    *    return false;
    * if (x_si != y_si)
    *    return x_si && (((((x_hi | y_hi)<<1)) | x_lo | y_lo) != 0);
    * return
    *      x_si ? lt64(y_hi, y_lo, x_hi, x_lo) : lt64(x_hi, x_lo, y_hi, y_lo);
    */
   return nir_bcsel(b,
                    nir_ior(b, is_nan(b, x), is_nan(b, y)),
                    nir_imm_int(b, NIR_FALSE),
                    nir_bcsel(b,
                              nir_ine(b, x_si, y_si),
                              nir_iand(b, x_si, ne_xy),
                              nir_bcsel(b, x_si,
                                           lt64(b, y_hi, y_lo, x_hi, x_lo),
                                           lt64(b, x_hi, x_lo, y_hi, y_lo))));
}

static nir_ssa_def *
mul64(nir_builder *b,
      nir_ssa_def *z_si,
      nir_ssa_def *x_frac_hi, nir_ssa_def *x_frac_lo, nir_ssa_def *x_exp,
      nir_ssa_def *y_frac_hi, nir_ssa_def *y_frac_lo, nir_ssa_def *y_exp)
{
   nir_ssa_def *z_frac_0;
   nir_ssa_def *z_frac_1;
   nir_ssa_def *z_frac_2;
   nir_ssa_def *z_frac_3;

   nir_ssa_def *z_frac_0_shift;
   nir_ssa_def *z_frac_1_shift;
   nir_ssa_def *z_frac_2_shift;

   nir_ssa_def *z_exp = nir_isub(b, nir_iadd(b, x_exp, y_exp),
                                    nir_imm_int(b, 0x400));

   x_frac_hi = nir_ior(b, x_frac_hi, nir_imm_int(b, 0x00100000));

   short_shl64(b, y_frac_hi, y_frac_lo,
                  nir_imm_int(b, 12),
                  &y_frac_hi, &y_frac_lo);

   mul64_to_128(b, x_frac_hi, x_frac_lo, y_frac_hi, y_frac_lo,
                   &z_frac_0, &z_frac_1, &z_frac_2, &z_frac_3);

   add64(b, z_frac_0, z_frac_1,
            x_frac_hi, x_frac_lo,
            &z_frac_0, &z_frac_1);

   z_frac_2 = nir_ior(b, z_frac_2,
                         nir_b2i(b, nir_ine(b, z_frac_3, nir_imm_int(b, 0))));

   shift64_extra_right_jamming(b, z_frac_0, z_frac_1, z_frac_2,
                                  nir_imm_int(b, 1),
                                  &z_frac_0_shift,
                                  &z_frac_1_shift,
                                  &z_frac_2_shift);

   return
      nir_bcsel(b,
                nir_uge(b, z_frac_0, nir_imm_int(b, 0x00200000)),
                round_pack_fp64(b, z_si,
                                   nir_iadd(b, z_exp, nir_imm_int(b, 1)),
                                   z_frac_0_shift,
                                   z_frac_1_shift,
                                   z_frac_2_shift),
                round_pack_fp64(b, z_si, z_exp, z_frac_0, z_frac_1, z_frac_2));
}

static nir_ssa_def *
lower_fmul64(nir_builder *b, nir_ssa_def *x, nir_ssa_def *y)
{
   nir_ssa_def *x_si = get_sign(b, x);
   nir_ssa_def *x_exp = get_exponent(b, x);
   nir_ssa_def *x_frac_lo = get_frac_lo(b, x);
   nir_ssa_def *x_frac_hi = get_frac_hi(b, x);
   nir_ssa_def *y_si = get_sign(b, y);
   nir_ssa_def *y_exp = get_exponent(b, y);
   nir_ssa_def *y_frac_lo = get_frac_lo(b, y);
   nir_ssa_def *y_frac_hi = get_frac_hi(b, y);

   nir_ssa_def *z_si = nir_ixor(b, x_si, y_si);
   nir_ssa_def *x_frac = nir_ior(b, x_frac_hi, x_frac_lo);
   nir_ssa_def *x_exp_frac = nir_ior(b, x_exp, x_frac);
   nir_ssa_def *y_frac = nir_ior(b, y_frac_hi, y_frac_lo);
   nir_ssa_def *y_exp_frac = nir_ior(b, y_exp, y_frac);
   nir_ssa_def *y_nan = nir_iand(b, nir_ieq(b, y_exp, nir_imm_int(b, 0x7FF)),
                                    nir_i2b(b, y_frac));

   nir_ssa_def *zero = nir_imm_int(b, 0);

   /* Result of NaN, Inf and subnormal multiply */
   /* NaN */
   nir_ssa_def *propagate_nan = propagate_fp64_nan(b, x, y);

   nir_ssa_def *default_nan =
      nir_pack_64_2x32_split(b, nir_imm_int(b, ~0), nir_imm_int(b, ~0));

   /* Infinite */
   nir_ssa_def *pack_inf_fp64 =
      pack_fp64(b, z_si, nir_imm_int(b, 0x7FF), zero, zero);

   /* Zero */
   nir_ssa_def *pack_zero_fp64 =
      pack_fp64(b, z_si, zero, zero, zero);

   /* X subnormal */
   nir_ssa_def *x_exp_sub = x_exp;
   nir_ssa_def *x_frac_hi_sub = x_frac_hi;
   nir_ssa_def *x_frac_lo_sub = x_frac_lo;
   normalize_fp64_subnormal(b, x_frac_hi, x_frac_lo,
                               &x_exp_sub, &x_frac_hi_sub, &x_frac_lo_sub);
   nir_ssa_def *normalize_x =
      mul64(b, z_si, x_frac_hi_sub, x_frac_lo_sub, x_exp_sub,
                     y_frac_hi, y_frac_lo, y_exp);

   /* Y subnormal */
   nir_ssa_def *y_exp_sub = y_exp;
   nir_ssa_def *y_frac_hi_sub = y_frac_hi;
   nir_ssa_def *y_frac_lo_sub = y_frac_lo;
   normalize_fp64_subnormal(b, y_frac_hi, y_frac_lo,
                               &y_exp_sub, &y_frac_hi_sub, &y_frac_lo_sub);
   nir_ssa_def *normalize_y =
      mul64(b, z_si, x_frac_hi, x_frac_lo, x_exp,
                     y_frac_hi_sub, y_frac_lo_sub, y_exp_sub);

   /*
    * Handle the different exeption before compute the multiply.
    *
    * If x * Inf or Inf * y, return Inf.
    * If Inf * Inf, return Inf.
    * If Inf * 0, we return a default NaN (0xFFFFFFFFFFFFFFFF)
    *
    * If x * NaN or NaN * y, we propagate the NaN.
    * If NaN * NaN, we select the correct NaN to propagate.
    *
    * If x or y is equal to 0, we return 0.
    *
    * If x or y is a subnormal (exponent == 0 and significant != 0),
    * we normalize this entry and realize the multiply.
    */
   return
      nir_bcsel(b,
                nir_ieq(b, x_exp, nir_imm_int(b, 0x7FF)),
                nir_bcsel(b,
                          nir_ior(b, x_frac, y_nan),
                          propagate_nan,
                          nir_bcsel(b,
                                    nir_ieq(b, y_exp_frac, zero),
                                    default_nan,
                                    pack_inf_fp64)),
                nir_bcsel(b,
                          nir_ieq(b, y_exp, nir_imm_int(b, 0x7FF)),
                          nir_bcsel(b,
                                    y_frac,
                                    propagate_nan,
                                    nir_bcsel(b,
                                              nir_ieq(b, x_exp_frac, zero),
                                              default_nan,
                                              pack_inf_fp64)),
                          nir_bcsel(b,
                                    nir_ieq(b, x_exp, zero),
                                    nir_bcsel(b,
                                              nir_ieq(b, x_frac, zero),
                                              pack_zero_fp64,
                                              normalize_x),
                                    nir_bcsel(b,
                                              nir_ieq(b, y_exp, zero),
                                              nir_bcsel(b,
                                                        nir_ieq(b, y_frac,
                                                                   zero),
                                                        pack_zero_fp64,
                                                        normalize_y),
                                              mul64(b, z_si,
                                                       x_frac_hi, x_frac_lo,
                                                       x_exp,
                                                       y_frac_hi, y_frac_lo,
                                                       y_exp)))));
}

static nir_ssa_def *
add_frac(nir_builder *b,
         nir_ssa_def *x_frac_hi,
         nir_ssa_def *x_frac_lo,
         nir_ssa_def *y_frac_hi,
         nir_ssa_def *y_frac_lo,
         nir_ssa_def *z_si,
         nir_ssa_def *z_exp,
         nir_ssa_def *z_frac_2)
{
   nir_ssa_def *z_frac_0;
   nir_ssa_def *z_frac_0_tmp;
   nir_ssa_def *z_frac_1;

   x_frac_hi = nir_ior(b, x_frac_hi, nir_imm_int(b, 0x00100000));
   add64(b, x_frac_hi, x_frac_lo, y_frac_hi, y_frac_lo, &z_frac_0, &z_frac_1);

   z_frac_0_tmp = z_frac_0;

   nir_ssa_def *without_shift =
      round_pack_fp64(b, z_si, nir_isub(b, z_exp, nir_imm_int(b, 1)),
                         z_frac_0, z_frac_1, z_frac_2);

   shift64_extra_right_jamming(b, z_frac_0, z_frac_1, z_frac_2,
                                  nir_imm_int(b, 1),
                                  &z_frac_0, &z_frac_1, &z_frac_2);

   nir_ssa_def *with_shift =
      round_pack_fp64(b, z_si, z_exp, z_frac_0, z_frac_1, z_frac_2);

   return nir_bcsel(b,
                    nir_ult(b, z_frac_0_tmp, nir_imm_int(b, 0x00200000)),
                    without_shift,
                    with_shift);
}

/* Returns the result of adding the absolute values of the double-precision
 * floating-point values `x' and `y'.  If `z_si' is 1, the sum is negated
 * before being returned.  `z_si' is ignored if the result is a NaN.  The
 * addition is performed according to the IEEE Standard for Floating-Point
 * Arithmetic.
 */
static nir_ssa_def *
add_frac_fp64(nir_builder *b, nir_ssa_def *z_si, nir_ssa_def *x, nir_ssa_def *y)
{
   nir_ssa_def *x_exp = get_exponent(b, x);
   nir_ssa_def *x_frac_lo = get_frac_lo(b, x);
   nir_ssa_def *x_frac_hi = get_frac_hi(b, x);
   nir_ssa_def *y_exp = get_exponent(b, y);
   nir_ssa_def *y_frac_lo = get_frac_lo(b, y);
   nir_ssa_def *y_frac_hi = get_frac_hi(b, y);

   nir_ssa_def *exp_diff = nir_isub(b, x_exp, y_exp);

   nir_ssa_def *x_frac = nir_ior(b, x_frac_hi, x_frac_lo);
   nir_ssa_def *y_frac = nir_ior(b, y_frac_hi, y_frac_lo);
   nir_ssa_def *x_y_frac = nir_ior(b, x_frac, y_frac);

   /* Result of NaN, Inf and subnormal addition */
   /* NaN */
   nir_ssa_def *propagate_nan = propagate_fp64_nan(b, x, y);

   /* Zero */
   nir_ssa_def *zero = nir_imm_int(b, 0);

   /* Infinite */
   nir_ssa_def *pack_inf_fp64 =
      pack_fp64(b, z_si, nir_imm_int(b, 0x7FF), zero, zero);

   /* Case (0 < exp_diff) && (y_exp == 0) */
   nir_ssa_def *y_frac_hi_tmp;
   nir_ssa_def *y_frac_lo_tmp;
   nir_ssa_def *z_frac_0;
   nir_ssa_def *z_frac_1;
   nir_ssa_def *z_frac_2;
   nir_ssa_def *exp_diff_tmp = nir_isub(b, exp_diff, nir_imm_int(b, 1));
   shift64_extra_right_jamming(b, y_frac_hi, y_frac_lo, zero,
                                  exp_diff_tmp,
                                  &y_frac_hi_tmp, &y_frac_lo_tmp, &z_frac_2);

   nir_ssa_def *case_1 =
      add_frac(b, x_frac_hi, x_frac_lo,
                  y_frac_hi_tmp, y_frac_lo_tmp,
                  z_si, x_exp, z_frac_2);

   /* Case (0 < exp_diff) && (y_exp != 0) */
   y_frac_hi_tmp = nir_ior(b, y_frac_hi, nir_imm_int(b, 0x00100000));
   shift64_extra_right_jamming(b, y_frac_hi_tmp, y_frac_lo, zero,
                                  exp_diff,
                                  &y_frac_hi_tmp, &y_frac_lo_tmp, &z_frac_2);

   nir_ssa_def *case_2 =
      add_frac(b, x_frac_hi, x_frac_lo,
                  y_frac_hi_tmp, y_frac_lo_tmp,
                  z_si, x_exp, z_frac_2);

   /* Case (exp_diff < 0) && (x_exp == 0) */
   nir_ssa_def *x_frac_hi_tmp = x_frac_hi;
   nir_ssa_def *x_frac_lo_tmp = x_frac_lo;
   exp_diff_tmp = exp_diff;
   exp_diff_tmp = nir_iadd(b, exp_diff_tmp, nir_imm_int(b, 1));
   shift64_extra_right_jamming(b, x_frac_hi, x_frac_lo, zero,
                                  nir_ineg(b, exp_diff_tmp),
                                  &x_frac_hi_tmp, &x_frac_lo_tmp, &z_frac_2);

   nir_ssa_def *case_3 =
      add_frac(b, x_frac_hi_tmp, x_frac_lo_tmp,
                  y_frac_hi, y_frac_lo,
                  z_si, y_exp, z_frac_2);

   /* Case (exp_diff < 0) && (x_exp != 0) */
   x_frac_hi_tmp = nir_ior(b, x_frac_hi, nir_imm_int(b, 0x00100000));
   shift64_extra_right_jamming(b, x_frac_hi_tmp, x_frac_lo, zero,
                                  nir_ineg(b, exp_diff),
                                  &x_frac_hi_tmp, &x_frac_lo_tmp, &z_frac_2);

   nir_ssa_def *case_4 =
      add_frac(b, x_frac_hi_tmp, x_frac_lo_tmp,
                  y_frac_hi, y_frac_lo,
                  z_si, y_exp, z_frac_2);

   /* Case (exp_diff == 0) && (x_exp != 0x7FF) */
   add64(b, x_frac_hi, x_frac_lo, y_frac_hi, y_frac_lo, &z_frac_0, &z_frac_1);
   nir_ssa_def *res = pack_fp64(b, z_si, zero, z_frac_0, z_frac_1);
   z_frac_0 = nir_ior(b, z_frac_0, nir_imm_int(b, 0x00200000));

   shift64_extra_right_jamming(b,
                               z_frac_0, z_frac_1, zero,
                               nir_imm_int(b, 1),
                               &z_frac_0, &z_frac_1, &z_frac_2);

   return
      nir_bcsel(b,
                nir_ilt(b, zero, exp_diff),
                nir_bcsel(b,
                          nir_ieq(b, x_exp, nir_imm_int(b, 0x7FF)),
                          nir_bcsel(b, x_frac, propagate_nan, x),
                          nir_bcsel(b,
                                    nir_ieq(b, y_exp, zero),
                                    case_1,
                                    case_2)),
                nir_bcsel(b,
                          nir_ilt(b, exp_diff, zero),
                          nir_bcsel(b,
                                    nir_ieq(b, y_exp, nir_imm_int(b, 0x7FF)),
                                    nir_bcsel(b,
                                              y_frac,
                                              propagate_nan,
                                              pack_inf_fp64),
                                    nir_bcsel(b,
                                              nir_ieq(b, x_exp, zero),
                                              case_3,
                                              case_4)),
                          nir_bcsel(b,
                                    nir_ieq(b, x_exp, nir_imm_int(b, 0x7FF)),
                                    nir_bcsel(b, x_y_frac, propagate_nan, x),
                                    nir_bcsel(b,
                                              nir_ieq(b, x_exp, zero),
                                              res,
                                              round_pack_fp64(b, z_si,
                                                                 x_exp,
                                                                 z_frac_0,
                                                                 z_frac_1,
                                                                 z_frac_2)))));
}

static nir_ssa_def *
sub_frac_fp64(nir_builder *b, nir_ssa_def *z_si, nir_ssa_def *x, nir_ssa_def *y)
{
   nir_ssa_def *x_exp = get_exponent(b, x);
   nir_ssa_def *x_frac_lo = get_frac_lo(b, x);
   nir_ssa_def *x_frac_hi = get_frac_hi(b, x);
   nir_ssa_def *y_exp = get_exponent(b, y);
   nir_ssa_def *y_frac_lo = get_frac_lo(b, y);
   nir_ssa_def *y_frac_hi = get_frac_hi(b, y);

   nir_ssa_def *zero = nir_imm_int(b, 0);
   nir_ssa_def *one = nir_imm_int(b, 1);
   nir_ssa_def *ten = nir_imm_int(b, 10);
   nir_ssa_def *eleven = nir_imm_int(b, 11);

   nir_ssa_def *x_frac = nir_ior(b, x_frac_hi, x_frac_lo);
   nir_ssa_def *y_frac = nir_ior(b, y_frac_hi, y_frac_lo);
   nir_ssa_def *x_y_frac = nir_ior(b, x_frac, y_frac);

   nir_ssa_def *z_frac_hi;
   nir_ssa_def *z_frac_lo;
   nir_ssa_def *y_frac_hi_tmp;
   nir_ssa_def *y_frac_lo_tmp;

   nir_ssa_def *exp_diff = nir_isub(b, x_exp, y_exp);
   short_shl64(b, x_frac_hi, x_frac_lo, ten, &x_frac_hi, &x_frac_lo);
   short_shl64(b, y_frac_hi, y_frac_lo, ten, &y_frac_hi, &y_frac_lo);

   /* Result of NaN and Zero */
   /* NaN */
   nir_ssa_def *propagate_nan = propagate_fp64_nan(b, x, y);

   nir_ssa_def *default_nan =
      nir_pack_64_2x32_split(b, nir_imm_int(b, ~0), nir_imm_int(b, ~0));

   /* Zero */
   nir_ssa_def *pack_zero_fp64 = pack_fp64(b, zero, zero, zero, zero);

   /* x exp bigger */
   /* if (y_exp == 0) */
   shift64_right_jamming(b, y_frac_hi, y_frac_lo,
                            nir_isub(b, exp_diff, one),
                            &y_frac_hi_tmp, &y_frac_lo_tmp);
   nir_ssa_def *x_frac_hi_ior =
      nir_ior(b, x_frac_hi, nir_imm_int(b, 0x40000000));
   sub64(b, x_frac_hi_ior, x_frac_lo,
            y_frac_hi_tmp, y_frac_lo_tmp,
            &z_frac_hi, &z_frac_lo);
   nir_ssa_def *case_1 =
      normalize_round_pack_fp64(b, z_si,
                                   nir_isub(b, x_exp, eleven),
                                   z_frac_hi, z_frac_lo);

   /* if (y_exp != 0) */
   nir_ssa_def *y_frac_hi_ior =
      nir_ior(b, y_frac_hi, nir_imm_int(b, 0x40000000));
   shift64_right_jamming(b, y_frac_hi_ior, y_frac_lo,
                            exp_diff,
                            &y_frac_hi_tmp, &y_frac_lo_tmp);
   sub64(b, x_frac_hi_ior, x_frac_lo,
            y_frac_hi_tmp, y_frac_lo_tmp,
            &z_frac_hi, &z_frac_lo);
   nir_ssa_def *case_2 =
      normalize_round_pack_fp64(b, z_si,
                                   nir_isub(b, x_exp, eleven),
                                   z_frac_hi, z_frac_lo);

   nir_ssa_def *x_exp_bigger =
      nir_bcsel(b,
                nir_ieq(b, x_exp, nir_imm_int(b, 0x7FF)),
                nir_bcsel(b, x_frac, propagate_nan, x),
                nir_bcsel(b, nir_ieq(b, y_exp, zero), case_1, case_2));

   /* y exp bigger */
   /* x_exp < y_exp */
   nir_ssa_def *x_frac_hi_tmp;
   nir_ssa_def *x_frac_lo_tmp;

   /* if (x_exp == 0) */
   shift64_right_jamming(b, x_frac_hi, x_frac_lo,
                            nir_ineg(b, nir_iadd(b, exp_diff, one)),
                            &x_frac_hi_tmp, &x_frac_lo_tmp);
   sub64(b, y_frac_hi_ior, y_frac_lo,
            x_frac_hi_tmp, x_frac_lo_tmp,
            &z_frac_hi, &z_frac_lo);
   nir_ssa_def *case_3 =
      normalize_round_pack_fp64(b, nir_ixor(b, z_si, one),
                                   nir_isub(b, y_exp, eleven),
                                   z_frac_hi, z_frac_lo);

   /* if (x_exp != 0) */
   shift64_right_jamming(b, x_frac_hi_ior, x_frac_lo,
                            nir_ineg(b, exp_diff),
                            &x_frac_hi_tmp, &x_frac_lo_tmp);
   sub64(b, y_frac_hi_ior, y_frac_lo,
            x_frac_hi_tmp, x_frac_lo_tmp,
            &z_frac_hi, &z_frac_lo);
   nir_ssa_def *case_4 =
      normalize_round_pack_fp64(b, nir_ixor(b, z_si, one),
                                   nir_isub(b, y_exp, eleven),
                                   z_frac_hi, z_frac_lo);

   nir_ssa_def *y_exp_bigger =
      nir_bcsel(b,
                nir_ieq(b, y_exp, nir_imm_int(b, 0x7FF)),
                nir_bcsel(b, y_frac,
                             propagate_nan,
                             pack_fp64(b,
                                       nir_ixor(b, z_si, one),
                                       nir_imm_int(b, 0x7FF),
                                       zero,
                                       zero)),
                nir_bcsel(b, nir_ieq(b, x_exp, zero), case_3, case_4));

   /* x bigger */
   /* x_frac_hi > y_frac_hi or x_frac_lo > y_frac_lo */
   sub64(b, x_frac_hi, x_frac_lo, y_frac_hi, y_frac_lo, &z_frac_hi, &z_frac_lo);
   nir_ssa_def *x_bigger =
      nir_bcsel(b,
                nir_ieq(b, x_exp, zero),
                normalize_round_pack_fp64(b,
                                          z_si,
                                          nir_imm_int(b, -10),
                                          z_frac_hi, z_frac_lo),
                normalize_round_pack_fp64(b,
                                          z_si,
                                          nir_isub(b, x_exp, eleven),
                                          z_frac_hi, z_frac_lo));

   /* y bigger */
   /* x_frac_hi < y_frac_lo or x_frac_lo < y_frac_lo */
   sub64(b, y_frac_hi, y_frac_lo, x_frac_hi, x_frac_lo, &z_frac_hi, &z_frac_lo);
   nir_ssa_def *y_bigger =
      nir_bcsel(b,
                nir_ieq(b, x_exp, zero),
                normalize_round_pack_fp64(b,
                                          nir_ixor(b, z_si, one),
                                          nir_imm_int(b, -10),
                                          z_frac_hi, z_frac_lo),
                normalize_round_pack_fp64(b,
                                          nir_ixor(b, z_si, one),
                                          nir_isub(b, y_exp, eleven),
                                          z_frac_hi, z_frac_lo));

   /* Select the value to return */
   return
      nir_bcsel(b,
                nir_ilt(b, zero, exp_diff),
                x_exp_bigger,
                nir_bcsel(b,
                          nir_ilt(b, exp_diff, zero),
                          y_exp_bigger,
                          nir_bcsel(b,
                                    nir_ieq(b, x_exp, nir_imm_int(b, 0x7FF)),
                                    nir_bcsel(b,
                                              nir_i2b(b, x_y_frac),
                                              propagate_nan,
                                              default_nan),
                                    nir_bcsel(b,
                                              nir_ult(b, y_frac_hi, x_frac_hi),
                                              x_bigger,
                                              nir_bcsel(b,
                                                        nir_ult(b, x_frac_hi, y_frac_hi),
                                                        y_bigger,
                                                        nir_bcsel(b,
                                                                  nir_ult(b, y_frac_lo, x_frac_lo),
                                                                  x_bigger,
                                                                  nir_bcsel(b,
                                                                            nir_ult(b, x_frac_lo, y_frac_lo),
                                                                            y_bigger,
                                                                            pack_zero_fp64)))))));
}

static nir_ssa_def *
lower_fadd64(nir_builder *b, nir_ssa_def *x, nir_ssa_def *y)
{
   nir_ssa_def *x_si = get_sign(b, x);
   nir_ssa_def *y_si = get_sign(b, y);

   return nir_bcsel(b,
                    nir_ieq(b, x_si, y_si),
                    add_frac_fp64(b, x_si, x, y),
                    sub_frac_fp64(b, x_si, x, y));
}

static bool
lower_doubles_instr(nir_alu_instr *instr, nir_lower_doubles_options options)
{
   assert(instr->dest.dest.is_ssa);
   if (instr->dest.dest.ssa.bit_size != 64)
      return false;

   switch (instr->op) {
   case nir_op_frcp:
      if (!(options & nir_lower_drcp))
         return false;
      break;

   case nir_op_fsqrt:
      if (!(options & nir_lower_dsqrt))
         return false;
      break;

   case nir_op_frsq:
      if (!(options & nir_lower_drsq))
         return false;
      break;

   case nir_op_ftrunc:
      if (!(options & nir_lower_dtrunc))
         return false;
      break;

   case nir_op_ffloor:
      if (!(options & nir_lower_dfloor))
         return false;
      break;

   case nir_op_fceil:
      if (!(options & nir_lower_dceil))
         return false;
      break;

   case nir_op_ffract:
      if (!(options & nir_lower_dfract))
         return false;
      break;

   case nir_op_fround_even:
      if (!(options & nir_lower_dround_even))
         return false;
      break;

   case nir_op_fmod:
      if (!(options & nir_lower_dmod))
         return false;
      break;

   case nir_op_fabs:
      if (!(options & nir_lower_dabs))
         return false;
      break;

   case nir_op_fneg:
      if (!(options & nir_lower_dneg))
         return false;
      break;

   case nir_op_fsign:
      if (!(options & nir_lower_dsign))
         return false;
      break;

   case nir_op_feq:
      if (!(options & nir_lower_deq))
         return false;
      break;

   case nir_op_flt:
      if (!(options & nir_lower_dlt))
         return false;
      break;

   case nir_op_fmul:
      if (!(options & nir_lower_dmul))
         return false;
      break;

   case nir_op_fadd:
      if (!(options & nir_lower_dadd))
         return false;
      break;

   default:
      return false;
   }

   nir_builder bld;
   nir_builder_init(&bld, nir_cf_node_get_function(&instr->instr.block->cf_node));
   bld.cursor = nir_before_instr(&instr->instr);

   nir_ssa_def *src = nir_fmov_alu(&bld, instr->src[0],
                                   instr->dest.dest.ssa.num_components);

   nir_ssa_def *result;

   switch (instr->op) {
   case nir_op_frcp:
      result = lower_rcp(&bld, src);
      break;
   case nir_op_fsqrt:
      result = lower_sqrt_rsq(&bld, src, true);
      break;
   case nir_op_frsq:
      result = lower_sqrt_rsq(&bld, src, false);
      break;
   case nir_op_ftrunc:
      result = lower_trunc(&bld, src);
      break;
   case nir_op_ffloor:
      result = lower_floor(&bld, src);
      break;
   case nir_op_fceil:
      result = lower_ceil(&bld, src);
      break;
   case nir_op_ffract:
      result = lower_fract(&bld, src);
      break;
   case nir_op_fround_even:
      result = lower_round_even(&bld, src);
      break;

   case nir_op_fmod: {
      nir_ssa_def *src1 = nir_fmov_alu(&bld, instr->src[1],
                                      instr->dest.dest.ssa.num_components);
      result = lower_mod(&bld, src, src1);
   }
      break;

   case nir_op_fabs:
      result = lower_fabs64(&bld, src);
      break;

   case nir_op_fneg:
      result = lower_fneg64(&bld, src);
      break;

   case nir_op_fsign:
      result = lower_fsign64(&bld, src);
      break;

   case nir_op_feq: {
      nir_ssa_def *src1 = nir_fmov_alu(&bld, instr->src[1],
                                      instr->dest.dest.ssa.num_components);
      result = lower_feq64(&bld, src, src1);
   }
      break;

   case nir_op_flt: {
      nir_ssa_def *src1 = nir_fmov_alu(&bld, instr->src[1],
                                      instr->dest.dest.ssa.num_components);
      result = lower_flt64(&bld, src, src1);
   }
      break;

   case nir_op_fmul: {
      nir_ssa_def *src1 = nir_fmov_alu(&bld, instr->src[1],
                                      instr->dest.dest.ssa.num_components);
      result = lower_fmul64(&bld, src, src1);
   }
      break;

   case nir_op_fadd: {
      nir_ssa_def *src1 = nir_fmov_alu(&bld, instr->src[1],
                                      instr->dest.dest.ssa.num_components);
      result = lower_fadd64(&bld, src, src1);
   }
      break;

   default:
      unreachable("unhandled opcode");
   }

   nir_ssa_def_rewrite_uses(&instr->dest.dest.ssa, nir_src_for_ssa(result));
   nir_instr_remove(&instr->instr);
   return true;
}

static bool
nir_lower_doubles_impl(nir_function_impl *impl,
                       nir_lower_doubles_options options)
{
   bool progress = false;

   nir_foreach_block(block, impl) {
      nir_foreach_instr_safe(instr, block) {
         if (instr->type == nir_instr_type_alu)
            progress |= lower_doubles_instr(nir_instr_as_alu(instr),
                                            options);
      }
   }

   if (progress)
      nir_metadata_preserve(impl, nir_metadata_block_index |
                                  nir_metadata_dominance);

   return progress;
}

bool
nir_lower_doubles(nir_shader *shader, nir_lower_doubles_options options)
{
   bool progress = false;

   nir_foreach_function(function, shader) {
      if (function->impl) {
         progress |= nir_lower_doubles_impl(function->impl, options);
      }
   }

   return progress;
}
