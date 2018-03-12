/* Compile with:
 *
 * glsl_compiler --version 130 --dump-builder float64.glsl > builtin_float64.h
 *
 */

#version 130
#extension GL_ARB_shader_bit_encoding : enable
#extension GL_EXT_shader_integer_mix : enable
#extension GL_MESA_shader_integer_functions : enable
/* Software IEEE floating-point rounding mode.
 * GLSL spec section "4.7.1 Range and Precision":
 * The rounding mode cannot be set and is undefined.
 * But here, we are able to define the rounding mode at the compilation time.
 */
#define FLOAT_ROUND_NEAREST_EVEN    0
#define FLOAT_ROUND_TO_ZERO         1
#define FLOAT_ROUND_DOWN            2
#define FLOAT_ROUND_UP              3
#define FLOAT_ROUNDING_MODE         FLOAT_ROUND_NEAREST_EVEN

/* Absolute value of a Float64 :
 * Clear the sign bit
 */
uvec2
fabs64(uvec2 a)
{
   a.y &= 0x7FFFFFFFu;
   return a;
}

/* Returns 1 if the double-precision floating-point value `a' is a NaN;
 * otherwise returns 0.
 */
bool
is_nan(uvec2 a)
{
   return (0xFFE00000u <= (a.y<<1)) &&
      ((a.x != 0u) || ((a.y & 0x000FFFFFu) != 0u));
}

/* Negate value of a Float64 :
 * Toggle the sign bit
 */
uvec2
fneg64(uvec2 a)
{
   uvec2 t = a;

   t.y ^= (1u << 31);
   a.y = mix(t.y, a.y, is_nan(a));
   return a;
}

uvec2
fsign64(uvec2 a)
{
   uvec2 retval;
   retval.x = 0u;
   retval.y = mix((a.y & 0x80000000u) | 0x3FF00000u, 0u, (a.y << 1 | a.x) == 0u);
   return retval;
}

/* Returns the fraction bits of the double-precision floating-point value `a'.*/
uint
extractFloat64FracLo(uvec2 a)
{
   return a.x;
}

uint
extractFloat64FracHi(uvec2 a)
{
   return a.y & 0x000FFFFFu;
}

/* Returns the exponent bits of the double-precision floating-point value `a'.*/
int
extractFloat64Exp(uvec2 a)
{
   return int((a.y>>20) & 0x7FFu);
}

/* Returns true if the double-precision floating-point value `a' is equal to the
 * corresponding value `b', and false otherwise.  The comparison is performed
 * according to the IEEE Standard for Floating-Point Arithmetic.
 */
bool
feq64(uvec2 a, uvec2 b)
{
   bool isaNaN;
   bool isbNaN;

   uint aFracLo = extractFloat64FracLo(a);
   uint aFracHi = extractFloat64FracHi(a);
   uint bFracLo = extractFloat64FracLo(b);
   uint bFracHi = extractFloat64FracHi(b);
   isaNaN = (extractFloat64Exp(a) == 0x7FF) &&
      ((aFracHi | aFracLo) != 0u);
   isbNaN = (extractFloat64Exp(b) == 0x7FF) &&
      ((bFracHi | bFracLo) != 0u);

   bool result = (a.x == b.x) &&
      ((a.y == b.y) || ((a.x == 0u) && (((a.y | b.y)<<1) == 0u)));
   return mix(result, false, isaNaN || isbNaN);
}

/* Returns the sign bit of the double-precision floating-point value `a'.*/
uint
extractFloat64Sign(uvec2 a)
{
   return (a.y>>31);
}

/* Returns true if the 64-bit value formed by concatenating `a0' and `a1' is less
 * than the 64-bit value formed by concatenating `b0' and `b1'.  Otherwise,
 * returns false.
 */
bool
lt64(uint a0, uint a1, uint b0, uint b1)
{
   return (a0 < b0) || ((a0 == b0) && (a1 < b1));
}

/* Returns true if the double-precision floating-point value `a' is less than
 * the corresponding value `b', and false otherwise.  The comparison is performed
 * according to the IEEE Standard for Floating-Point Arithmetic.
 */
bool
flt64(uvec2 a, uvec2 b)
{
   uint aSign;
   uint bSign;
   bool isaNaN;
   bool isbNaN;

   uint aFracLo = extractFloat64FracLo(a);
   uint aFracHi = extractFloat64FracHi(a);
   uint bFracLo = extractFloat64FracLo(b);
   uint bFracHi = extractFloat64FracHi(b);
   isaNaN = (extractFloat64Exp(a) == 0x7FF) &&
      ((aFracHi | aFracLo) != 0u);
   isbNaN = (extractFloat64Exp(b) == 0x7FF) &&
      ((bFracHi | bFracLo) != 0u);

   if (isaNaN || isbNaN)
      return false;

   aSign = extractFloat64Sign(a);
   bSign = extractFloat64Sign(b);
   if (aSign != bSign)
      return (aSign != 0u) && ((((a.y | b.y)<<1) | a.x | b.x) != 0u);

   return mix(lt64(a.y, a.x, b.y, b.x), lt64(b.y, b.x, a.y, a.x), aSign != 0u);
}

/* Adds the 64-bit value formed by concatenating `a0' and `a1' to the 64-bit
 * value formed by concatenating `b0' and `b1'.  Addition is modulo 2^64, so
 * any carry out is lost.  The result is broken into two 32-bit pieces which
 * are stored at the locations pointed to by `z0Ptr' and `z1Ptr'.
 */
void
add64(uint a0, uint a1, uint b0, uint b1,
      inout uint z0Ptr,
      inout uint z1Ptr)
{
   uint z1 = a1 + b1;
   z1Ptr = z1;
   z0Ptr = a0 + b0 + uint(z1 < a1);
}


/* Subtracts the 64-bit value formed by concatenating `b0' and `b1' from the
 * 64-bit value formed by concatenating `a0' and `a1'.  Subtraction is modulo
 * 2^64, so any borrow out (carry out) is lost.  The result is broken into two
 * 32-bit pieces which are stored at the locations pointed to by `z0Ptr' and
 * `z1Ptr'.
 */
void
sub64(uint a0, uint a1, uint b0, uint b1,
      inout uint z0Ptr,
      inout uint z1Ptr)
{
   z1Ptr = a1 - b1;
   z0Ptr = a0 - b0 - uint(a1 < b1);
}

/* Shifts the 64-bit value formed by concatenating `a0' and `a1' right by the
 * number of bits given in `count'.  If any nonzero bits are shifted off, they
 * are "jammed" into the least significant bit of the result by setting the
 * least significant bit to 1.  The value of `count' can be arbitrarily large;
 * in particular, if `count' is greater than 64, the result will be either 0
 * or 1, depending on whether the concatenation of `a0' and `a1' is zero or
 * nonzero.  The result is broken into two 32-bit pieces which are stored at
 * the locations pointed to by `z0Ptr' and `z1Ptr'.
 */
void
shift64RightJamming(uint a0,
                    uint a1,
                    int count,
                    inout uint z0Ptr,
                    inout uint z1Ptr)
{
   uint z0;
   uint z1;
   int negCount = (-count) & 31;

   z0 = mix(0u, a0, count == 0);
   z0 = mix(z0, (a0 >> count), count < 32);

   z1 = uint((a0 | a1) != 0u); /* count >= 64 */
   uint z1_lt64 = (a0>>(count & 31)) | uint(((a0<<negCount) | a1) != 0u);
   z1 = mix(z1, z1_lt64, count < 64);
   z1 = mix(z1, (a0 | uint(a1 != 0u)), count == 32);
   uint z1_lt32 = (a0<<negCount) | (a1>>count) | uint ((a1<<negCount) != 0u);
   z1 = mix(z1, z1_lt32, count < 32);
   z1 = mix(z1, a1, count == 0);
   z1Ptr = z1;
   z0Ptr = z0;
}

/* Shifts the 96-bit value formed by concatenating `a0', `a1', and `a2' right
 * by 32 _plus_ the number of bits given in `count'.  The shifted result is
 * at most 64 nonzero bits; these are broken into two 32-bit pieces which are
 * stored at the locations pointed to by `z0Ptr' and `z1Ptr'.  The bits shifted
 * off form a third 32-bit result as follows:  The _last_ bit shifted off is
 * the most-significant bit of the extra result, and the other 31 bits of the
 * extra result are all zero if and only if _all_but_the_last_ bits shifted off
 * were all zero.  This extra result is stored in the location pointed to by
 * `z2Ptr'.  The value of `count' can be arbitrarily large.
 *     (This routine makes more sense if `a0', `a1', and `a2' are considered
 * to form a fixed-point value with binary point between `a1' and `a2'.  This
 * fixed-point value is shifted right by the number of bits given in `count',
 * and the integer part of the result is returned at the locations pointed to
 * by `z0Ptr' and `z1Ptr'.  The fractional part of the result may be slightly
 * corrupted as described above, and is returned at the location pointed to by
 * `z2Ptr'.)
 */
void
shift64ExtraRightJamming(uint a0, uint a1, uint a2,
                         int count,
                         inout uint z0Ptr,
                         inout uint z1Ptr,
                         inout uint z2Ptr)
{
   uint z0 = 0u;
   uint z1;
   uint z2;
   int negCount = (-count) & 31;

   z2 = mix(uint(a0 != 0u), a0, count == 64);
   z2 = mix(z2, a0 << negCount, count < 64);
   z2 = mix(z2, a1 << negCount, count < 32);

   z1 = mix(0u, (a0 >> (count & 31)), count < 64);
   z1 = mix(z1, (a0<<negCount) | (a1>>count), count < 32);

   a2 = mix(a2 | a1, a2, count < 32);
   z0 = mix(z0, a0 >> count, count < 32);
   z2 |= uint(a2 != 0u);

   z0 = mix(z0, 0u, (count == 32));
   z1 = mix(z1, a0, (count == 32));
   z2 = mix(z2, a1, (count == 32));
   z0 = mix(z0, a0, (count == 0));
   z1 = mix(z1, a1, (count == 0));
   z2 = mix(z2, a2, (count == 0));
   z2Ptr = z2;
   z1Ptr = z1;
   z0Ptr = z0;
}

/* Shifts the 64-bit value formed by concatenating `a0' and `a1' left by the
 * number of bits given in `count'.  Any bits shifted off are lost.  The value
 * of `count' must be less than 32.  The result is broken into two 32-bit
 * pieces which are stored at the locations pointed to by `z0Ptr' and `z1Ptr'.
 */
void
shortShift64Left(uint a0, uint a1,
                 int count,
                 inout uint z0Ptr, inout uint z1Ptr)
{
   z1Ptr = a1<<count;
   z0Ptr = mix((a0 << count | (a1 >> ((-count) & 31))), a0, count == 0);
}

/* Packs the sign `zSign', the exponent `zExp', and the significand formed by
 * the concatenation of `zFrac0' and `zFrac1' into a double-precision floating-
 * point value, returning the result.  After being shifted into the proper
 * positions, the three fields `zSign', `zExp', and `zFrac0' are simply added
 * together to form the most significant 32 bits of the result.  This means
 * that any integer portion of `zFrac0' will be added into the exponent.  Since
 * a properly normalized significand will have an integer portion equal to 1,
 * the `zExp' input should be 1 less than the desired result exponent whenever
 * `zFrac0' and `zFrac1' concatenated form a complete, normalized significand.
 */
uvec2
packFloat64(uint zSign, int zExp, uint zFrac0, uint zFrac1)
{
   uvec2 z;

   z.y = (zSign<<31) + (uint(zExp)<<20) + zFrac0;
   z.x = zFrac1;
   return z;
}

/* Takes an abstract floating-point value having sign `zSign', exponent `zExp',
 * and extended significand formed by the concatenation of `zFrac0', `zFrac1',
 * and `zFrac2', and returns the proper double-precision floating-point value
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
 * significand is not normalized, `zExp' must be 0; in that case, the result
 * returned is a subnormal number, and it must not require rounding.  In the
 * usual case that the input significand is normalized, `zExp' must be 1 less
 * than the "true" floating-point exponent.  The handling of underflow and
 * overflow follows the IEEE Standard for Floating-Point Arithmetic.
 */
uvec2
roundAndPackFloat64(uint zSign,
                    int zExp,
                    uint zFrac0,
                    uint zFrac1,
                    uint zFrac2)
{
   bool roundNearestEven;
   bool increment;

   roundNearestEven = FLOAT_ROUNDING_MODE == FLOAT_ROUND_NEAREST_EVEN;
   increment = int(zFrac2) < 0;
   if (!roundNearestEven) {
      if (FLOAT_ROUNDING_MODE == FLOAT_ROUND_TO_ZERO) {
         increment = false;
      } else {
         if (zSign != 0u) {
            increment = (FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN) &&
               (zFrac2 != 0u);
         } else {
            increment = (FLOAT_ROUNDING_MODE == FLOAT_ROUND_UP) &&
               (zFrac2 != 0u);
         }
      }
   }
   if (0x7FD <= zExp) {
      if ((0x7FD < zExp) ||
         ((zExp == 0x7FD) &&
            (0x001FFFFFu == zFrac0 && 0xFFFFFFFFu == zFrac1) &&
               increment)) {
         if ((FLOAT_ROUNDING_MODE == FLOAT_ROUND_TO_ZERO) ||
            ((zSign != 0u) && (FLOAT_ROUNDING_MODE == FLOAT_ROUND_UP)) ||
               ((zSign == 0u) && (FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN))) {
            return packFloat64(zSign, 0x7FE, 0x000FFFFFu, 0xFFFFFFFFu);
         }
         return packFloat64(zSign, 0x7FF, 0u, 0u);
      }
      if (zExp < 0) {
         shift64ExtraRightJamming(
            zFrac0, zFrac1, zFrac2, -zExp, zFrac0, zFrac1, zFrac2);
         zExp = 0;
         if (roundNearestEven) {
            increment = zFrac2 < 0u;
         } else {
            if (zSign != 0u) {
               increment = (FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN) &&
                  (zFrac2 != 0u);
            } else {
               increment = (FLOAT_ROUNDING_MODE == FLOAT_ROUND_UP) &&
                  (zFrac2 != 0u);
            }
         }
      }
   }
   if (increment) {
      add64(zFrac0, zFrac1, 0u, 1u, zFrac0, zFrac1);
      zFrac1 &= ~((zFrac2 + uint(zFrac2 == 0u)) & uint(roundNearestEven));
   } else {
      zExp = mix(zExp, 0, (zFrac0 | zFrac1) == 0u);
   }
   return packFloat64(zSign, zExp, zFrac0, zFrac1);
}

/* Returns the number of leading 0 bits before the most-significant 1 bit of
 * `a'.  If `a' is zero, 32 is returned.
 */
int
countLeadingZeros32(uint a)
{
   int shiftCount;
   shiftCount = mix(31 - findMSB(a), 32, a == 0u);
   return shiftCount;
}

/* Takes an abstract floating-point value having sign `zSign', exponent `zExp',
 * and significand formed by the concatenation of `zSig0' and `zSig1', and
 * returns the proper double-precision floating-point value corresponding
 * to the abstract input.  This routine is just like `roundAndPackFloat64'
 * except that the input significand has fewer bits and does not have to be
 * normalized.  In all cases, `zExp' must be 1 less than the "true" floating-
 * point exponent.
 */
uvec2
normalizeRoundAndPackFloat64(uint zSign,
                             int zExp,
                             uint zFrac0,
                             uint zFrac1)
{
   int shiftCount;
   uint zFrac2;

   zExp = mix(zExp, zExp - 32, zFrac0 == 0u);
   zFrac1 = mix(zFrac1, 0u, zFrac0 == 0u);
   zFrac0 = mix(zFrac0, zFrac1, zFrac0 == 0u);
   shiftCount = countLeadingZeros32(zFrac0) - 11;
   if (0 <= shiftCount) {
      zFrac2 = 0u;
      shortShift64Left(zFrac0, zFrac1, shiftCount, zFrac0, zFrac1);
   } else {
      shift64ExtraRightJamming(
         zFrac0, zFrac1, 0u, -shiftCount, zFrac0, zFrac1, zFrac2);
   }
   zExp -= shiftCount;
   return roundAndPackFloat64(zSign, zExp, zFrac0, zFrac1, zFrac2);
}

/* Takes two double-precision floating-point values `a' and `b', one of which
 * is a NaN, and returns the appropriate NaN result.
 */
uvec2
propagateFloat64NaN(uvec2 a, uvec2 b)
{
   bool aIsNaN = is_nan(a);
   bool bIsNaN = is_nan(b);
   a.y |= 0x00080000u;
   b.y |= 0x00080000u;

   return mix(b, mix(a, b, bvec2(bIsNaN, bIsNaN)), bvec2(aIsNaN, aIsNaN));
}

/* Returns the result of adding the double-precision floating-point values
 * `a' and `b'.  The operation is performed according to the IEEE Standard for
 * Floating-Point Arithmetic.
 */
uvec2
fadd64(uvec2 a, uvec2 b)
{
   uint aSign = extractFloat64Sign(a);
   uint bSign = extractFloat64Sign(b);
   uint aFracLo = extractFloat64FracLo(a);
   uint aFracHi = extractFloat64FracHi(a);
   uint bFracLo = extractFloat64FracLo(b);
   uint bFracHi = extractFloat64FracHi(b);
   int aExp = extractFloat64Exp(a);
   int bExp = extractFloat64Exp(b);
   uint zFrac0 = 0u;
   uint zFrac1 = 0u;
   int expDiff = aExp - bExp;
   if (aSign == bSign) {
      uint zFrac2 = 0u;
      int zExp;
      bool orig_exp_diff_is_zero = (expDiff == 0);

      if (orig_exp_diff_is_zero) {
         if (aExp == 0x7FF) {
	    bool propagate = (aFracHi | aFracLo | bFracHi | bFracLo) != 0u;
	    return mix(a, propagateFloat64NaN(a, b), bvec2(propagate, propagate));
         }
         add64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
         if (aExp == 0)
            return packFloat64(aSign, 0, zFrac0, zFrac1);
         zFrac2 = 0u;
         zFrac0 |= 0x00200000u;
         zExp = aExp;
         shift64ExtraRightJamming(
            zFrac0, zFrac1, zFrac2, 1, zFrac0, zFrac1, zFrac2);
      } else if (0 < expDiff) {
         if (aExp == 0x7FF) {
	    bool propagate = (aFracHi | aFracLo) != 0u;
	    return mix(a, propagateFloat64NaN(a, b), bvec2(propagate, propagate));
         }

	 expDiff = mix(expDiff, expDiff - 1, bExp == 0);
	 bFracHi = mix(bFracHi | 0x00100000u, bFracHi, bExp == 0);
         shift64ExtraRightJamming(
            bFracHi, bFracLo, 0u, expDiff, bFracHi, bFracLo, zFrac2);
         zExp = aExp;
      } else if (expDiff < 0) {
         if (bExp == 0x7FF) {
	    bool propagate = (bFracHi | bFracLo) != 0u;
	    return mix(packFloat64(aSign, 0x7ff, 0u, 0u), propagateFloat64NaN(a, b), bvec2(propagate, propagate));
         }
	 expDiff = mix(expDiff, expDiff + 1, aExp == 0);
	 aFracHi = mix(aFracHi | 0x00100000u, aFracHi, aExp == 0);
         shift64ExtraRightJamming(
            aFracHi, aFracLo, 0u, - expDiff, aFracHi, aFracLo, zFrac2);
         zExp = bExp;
      }
      if (!orig_exp_diff_is_zero) {
         aFracHi |= 0x00100000u;
         add64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
         --zExp;
         if (!(zFrac0 < 0x00200000u)) {
            shift64ExtraRightJamming(zFrac0, zFrac1, zFrac2, 1, zFrac0, zFrac1, zFrac2);
            ++zExp;
         }
      }
      return roundAndPackFloat64(aSign, zExp, zFrac0, zFrac1, zFrac2);

   } else {
      uvec2 z;
      int zExp;

      shortShift64Left(aFracHi, aFracLo, 10, aFracHi, aFracLo);
      shortShift64Left(bFracHi, bFracLo, 10, bFracHi, bFracLo);
      if (0 < expDiff) {
         if (aExp == 0x7FF) {
 	    bool propagate = (aFracHi | aFracLo) != 0u;
	    return mix(a, propagateFloat64NaN(a, b), bvec2(propagate, propagate));
         }
         expDiff = mix(expDiff, expDiff - 1, bExp == 0);
         bFracHi = mix(bFracHi | 0x40000000u, bFracHi, bExp == 0);
         shift64RightJamming(bFracHi, bFracLo, expDiff, bFracHi, bFracLo);
         aFracHi |= 0x40000000u;
         sub64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
         zExp = aExp;
         --zExp;
         return normalizeRoundAndPackFloat64(aSign, zExp - 10, zFrac0, zFrac1);
      }
      if (expDiff < 0) {
         if (bExp == 0x7FF) {
 	    bool propagate = (bFracHi | bFracLo) != 0u;
	    return mix(packFloat64(aSign ^ 1u, 0x7ff, 0u, 0u), propagateFloat64NaN(a, b), bvec2(propagate, propagate));
         }
         expDiff = mix(expDiff, expDiff + 1, aExp == 0);
         aFracHi = mix(aFracHi | 0x40000000u, aFracHi, aExp == 0);
         shift64RightJamming(aFracHi, aFracLo, - expDiff, aFracHi, aFracLo);
         bFracHi |= 0x40000000u;
         sub64(bFracHi, bFracLo, aFracHi, aFracLo, zFrac0, zFrac1);
         zExp = bExp;
         aSign ^= 1u;
         --zExp;
         return normalizeRoundAndPackFloat64(aSign, zExp - 10, zFrac0, zFrac1);
      }
      if (aExp == 0x7FF) {
  	 bool propagate = (aFracHi | aFracLo | bFracHi | bFracLo) != 0u;
	 return mix(uvec2(0xFFFFFFFFu, 0xFFFFFFFFu), propagateFloat64NaN(a, b), bvec2(propagate, propagate));
      }
      bExp = mix(bExp, 1, aExp == 0);
      aExp = mix(aExp, 1, aExp == 0);
      bool zexp_normal = false;
      bool blta = true;
      if (bFracHi < aFracHi) {
         sub64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
         zexp_normal = true;
      }
      else if (aFracHi < bFracHi) {
         sub64(bFracHi, bFracLo, aFracHi, aFracLo, zFrac0, zFrac1);
         blta = false;
         zexp_normal = true;
      }
      else if (bFracLo < aFracLo) {
         sub64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
         zexp_normal = true;
      }
      else if (aFracLo < bFracLo) {
         sub64(bFracHi, bFracLo, aFracHi, aFracLo, zFrac0, zFrac1);
          blta = false;
          zexp_normal = true;
      }
      zExp = mix(bExp, aExp, blta);
      aSign = mix(aSign ^ 1u, aSign, blta);
      uvec2 retval_0 = packFloat64(uint(FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN), 0, 0u, 0u);
      uvec2 retval_1 = normalizeRoundAndPackFloat64(aSign, zExp - 11, zFrac0, zFrac1);
      return mix(retval_0, retval_1, bvec2(zexp_normal, zexp_normal));
   }
}

/* Multiplies `a' by `b' to obtain a 64-bit product.  The product is broken
 * into two 32-bit pieces which are stored at the locations pointed to by
 * `z0Ptr' and `z1Ptr'.
 */
void
mul32To64(uint a, uint b, inout uint z0Ptr, inout uint z1Ptr)
{
   uint aLow = a & 0x0000FFFFu;
   uint aHigh = a>>16;
   uint bLow = b & 0x0000FFFFu;
   uint bHigh = b>>16;
   uint z1 = aLow * bLow;
   uint zMiddleA = aLow * bHigh;
   uint zMiddleB = aHigh * bLow;
   uint z0 = aHigh * bHigh;
   zMiddleA += zMiddleB;
   z0 += ((uint(zMiddleA < zMiddleB)) << 16) + (zMiddleA >> 16);
   zMiddleA <<= 16;
   z1 += zMiddleA;
   z0 += uint(z1 < zMiddleA);
   z1Ptr = z1;
   z0Ptr = z0;
}

/* Multiplies the 64-bit value formed by concatenating `a0' and `a1' to the
 * 64-bit value formed by concatenating `b0' and `b1' to obtain a 128-bit
 * product.  The product is broken into four 32-bit pieces which are stored at
 * the locations pointed to by `z0Ptr', `z1Ptr', `z2Ptr', and `z3Ptr'.
 */
void
mul64To128(uint a0, uint a1, uint b0, uint b1,
           inout uint z0Ptr,
           inout uint z1Ptr,
           inout uint z2Ptr,
           inout uint z3Ptr )
{
   uint z0 = 0u;
   uint z1 = 0u;
   uint z2 = 0u;
   uint z3 = 0u;
   uint more1 = 0u;
   uint more2 = 0u;

   mul32To64(a1, b1, z2, z3);
   mul32To64(a1, b0, z1, more2);
   add64(z1, more2, 0u, z2, z1, z2);
   mul32To64(a0, b0, z0, more1);
   add64(z0, more1, 0u, z1, z0, z1);
   mul32To64(a0, b1, more1, more2);
   add64(more1, more2, 0u, z2, more1, z2);
   add64(z0, z1, 0u, more1, z0, z1);
   z3Ptr = z3;
   z2Ptr = z2;
   z1Ptr = z1;
   z0Ptr = z0;
}

/* Normalizes the subnormal double-precision floating-point value represented
 * by the denormalized significand formed by the concatenation of `aFrac0' and
 * `aFrac1'.  The normalized exponent is stored at the location pointed to by
 * `zExpPtr'.  The most significant 21 bits of the normalized significand are
 * stored at the location pointed to by `zFrac0Ptr', and the least significant
 * 32 bits of the normalized significand are stored at the location pointed to
 * by `zFrac1Ptr'.
 */
void
normalizeFloat64Subnormal(uint aFrac0, uint aFrac1,
                          inout int zExpPtr,
                          inout uint zFrac0Ptr,
                          inout uint zFrac1Ptr)
{
   int shiftCount;
   uint temp_zfrac0, temp_zfrac1;
   shiftCount = countLeadingZeros32(mix(aFrac0, aFrac1, aFrac0 == 0u)) - 11;
   zExpPtr = mix(1 - shiftCount, -shiftCount - 31, aFrac0 == 0u);

   temp_zfrac0 = mix(aFrac1<<shiftCount, aFrac1>>(-shiftCount), shiftCount < 0);
   temp_zfrac1 = mix(0u, aFrac1<<(shiftCount & 31), shiftCount < 0);

   shortShift64Left(aFrac0, aFrac1, shiftCount, zFrac0Ptr, zFrac1Ptr);

   zFrac0Ptr = mix(zFrac0Ptr, temp_zfrac0, aFrac0 == 0);
   zFrac1Ptr = mix(zFrac1Ptr, temp_zfrac1, aFrac0 == 0);
}

/* Returns the result of multiplying the double-precision floating-point values
 * `a' and `b'.  The operation is performed according to the IEEE Standard for
 * Floating-Point Arithmetic.
 */
uvec2
fmul64(uvec2 a, uvec2 b)
{
   uint zFrac0 = 0u;
   uint zFrac1 = 0u;
   uint zFrac2 = 0u;
   uint zFrac3 = 0u;
   int zExp;

   uint aFracLo = extractFloat64FracLo(a);
   uint aFracHi = extractFloat64FracHi(a);
   uint bFracLo = extractFloat64FracLo(b);
   uint bFracHi = extractFloat64FracHi(b);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);
   int bExp = extractFloat64Exp(b);
   uint bSign = extractFloat64Sign(b);
   uint zSign = aSign ^ bSign;
   if (aExp == 0x7FF) {
      if (((aFracHi | aFracLo) != 0u) ||
         ((bExp == 0x7FF) && ((bFracHi | bFracLo) != 0u))) {
         return propagateFloat64NaN(a, b);
      }
      if ((uint(bExp) | bFracHi | bFracLo) == 0u)
            return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
      return packFloat64(zSign, 0x7FF, 0u, 0u);
   }
   if (bExp == 0x7FF) {
      if ((bFracHi | bFracLo) != 0u)
         return propagateFloat64NaN(a, b);
      if ((uint(aExp) | aFracHi | aFracLo) == 0u)
         return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
      return packFloat64(zSign, 0x7FF, 0u, 0u);
   }
   if (aExp == 0) {
      if ((aFracHi | aFracLo) == 0u)
         return packFloat64(zSign, 0, 0u, 0u);
      normalizeFloat64Subnormal(aFracHi, aFracLo, aExp, aFracHi, aFracLo);
   }
   if (bExp == 0) {
      if ((bFracHi | bFracLo) == 0u)
         return packFloat64(zSign, 0, 0u, 0u);
      normalizeFloat64Subnormal(bFracHi, bFracLo, bExp, bFracHi, bFracLo);
   }
   zExp = aExp + bExp - 0x400;
   aFracHi |= 0x00100000u;
   shortShift64Left(bFracHi, bFracLo, 12, bFracHi, bFracLo);
   mul64To128(
      aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1, zFrac2, zFrac3);
   add64(zFrac0, zFrac1, aFracHi, aFracLo, zFrac0, zFrac1);
   zFrac2 |= uint(zFrac3 != 0u);
   if (0x00200000u <= zFrac0) {
      shift64ExtraRightJamming(
         zFrac0, zFrac1, zFrac2, 1, zFrac0, zFrac1, zFrac2);
      ++zExp;
   }
   return roundAndPackFloat64(zSign, zExp, zFrac0, zFrac1, zFrac2);
}

/* Shifts the 64-bit value formed by concatenating `a0' and `a1' right by the
 * number of bits given in `count'.  Any bits shifted off are lost.  The value
 * of `count' can be arbitrarily large; in particular, if `count' is greater
 * than 64, the result will be 0.  The result is broken into two 32-bit pieces
 * which are stored at the locations pointed to by `z0Ptr' and `z1Ptr'.
 */
void
shift64Right(uint a0, uint a1,
             int count,
             inout uint z0Ptr,
             inout uint z1Ptr)
{
   uint z0;
   uint z1;
   int negCount = (-count) & 31;

   z0 = 0u;
   z0 = mix(z0, (a0 >> count), count < 32);
   z0 = mix(z0, a0, count == 0);

   z1 = mix(0u, (a0 >> (count & 31)), count < 64);
   z1 = mix(z1, (a0<<negCount) | (a1>>count), count < 32);
   z1 = mix(z1, a0, count == 0);

   z1Ptr = z1;
   z0Ptr = z0;
}

/* Returns the result of converting the double-precision floating-point value
 * `a' to the unsigned integer format.  The conversion is performed according
 * to the IEEE Standard for Floating-Point Arithmetic.
 */
uint
fp64_to_uint(uvec2 a)
{
   uint aFracLo = extractFloat64FracLo(a);
   uint aFracHi = extractFloat64FracHi(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);

   if ((aExp == 0x7FF) && ((aFracHi | aFracLo) != 0u))
      return 0xFFFFFFFFu;

   if (aExp != 0)
      aFracHi |= 0x00100000u;

   int shiftDist = 0x427 - aExp;
   if (0 < shiftDist)
      shift64RightJamming(aFracHi, aFracLo, shiftDist, aFracHi, aFracLo);

   if ((aFracHi & 0xFFFFF000u) != 0u)
      return mix(~0u, 0u, (aSign != 0u));

   uint z = 0u;
   uint zero = 0u;
   shift64Right(aFracHi, aFracLo, 12, zero, z);

   if ((aSign != 0u) && (z != 0u))
      return mix(~0u, 0u, (aSign != 0u));

   return z;
}

uvec2
uint_to_fp64(uint a)
{
   if (a == 0u)
      return uvec2(0u, 0u);

   int shiftDist = countLeadingZeros32(a) + 21;

   uint aHigh = 0u;
   uint aLow = 0u;
   int negCount = (- shiftDist) & 31;

   aHigh = mix(0u, a<< shiftDist - 32, shiftDist < 64);
   aLow = 0u;
   aHigh = mix(aHigh, 0u, shiftDist == 0);
   aLow = mix(aLow, a, shiftDist ==0);
   aHigh = mix(aHigh, a >> negCount, shiftDist < 32);
   aLow = mix(aLow, a << shiftDist, shiftDist < 32);

   return packFloat64(0u, 0x432 - shiftDist, aHigh, aLow);
}

/* Returns the result of converting the double-precision floating-point value
 * `a' to the 32-bit two's complement integer format.  The conversion is
 * performed according to the IEEE Standard for Floating-Point Arithmetic---
 * which means in particular that the conversion is rounded according to the
 * current rounding mode.  If `a' is a NaN, the largest positive integer is
 * returned.  Otherwise, if the conversion overflows, the largest integer with
 * the same sign as `a' is returned.
 */
int
fp64_to_int(uvec2 a)
{
   uint aFracLo = extractFloat64FracLo(a);
   uint aFracHi = extractFloat64FracHi(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);

   uint absZ = 0u;
   uint aFracExtra = 0u;
   int z;
   int shiftCount = aExp - 0x413;

   if (0 <= shiftCount) {
      if (0x41E < aExp) {
         if ((aExp == 0x7FF) && bool(aFracHi | aFracLo))
            aSign = 0u;
         return bool(aSign) ? 0x80000000 : 0x7FFFFFFF;
      }
      shortShift64Left(aFracHi | 0x00100000u, aFracLo, shiftCount, absZ, aFracExtra);
   } else {
      if (aExp < 0x3FF)
         return 0;

      aFracHi |= 0x00100000u;
      aFracExtra = ( aFracHi << (shiftCount & 31)) | aFracLo;
      absZ = aFracHi >> (- shiftCount);
   }

   z = (aSign != 0u) ? - int(absZ) : int(absZ);

   if (bool(aSign ^ uint(z < 0)) && bool(z))
      return bool(aSign) ? 0x80000000 : 0x7FFFFFFF;

   return z;
}

/* Returns the result of converting the 32-bit two's complement integer `a'
 * to the double-precision floating-point format.  The conversion is performed
 * according to the IEEE Standard for Floating-Point Arithmetic.
 */
uvec2
int_to_fp64(int a)
{
   uint zFrac0 = 0u;
   uint zFrac1 = 0u;
   if (a==0)
      return packFloat64(0u, 0, 0u, 0u);
   uint zSign = uint(a < 0);
   uint absA = a < 0 ? uint(-a) : uint(a);
   int shiftCount = countLeadingZeros32(absA) - 11;
   if (0 <= shiftCount) {
      zFrac0 = absA << shiftCount;
      zFrac1 = 0u;
   } else {
      shift64Right(absA, 0u, -shiftCount, zFrac0, zFrac1);
   }
   return packFloat64(zSign, 0x412 - shiftCount, zFrac0, zFrac1);
}

/* Packs the sign `zSign', exponent `zExp', and significand `zFrac' into a
 * single-precision floating-point value, returning the result.  After being
 * shifted into the proper positions, the three fields are simply added
 * together to form the result.  This means that any integer portion of `zSig'
 * will be added into the exponent.  Since a properly normalized significand
 * will have an integer portion equal to 1, the `zExp' input should be 1 less
 * than the desired result exponent whenever `zFrac' is a complete, normalized
 * significand.
 */
float
packFloat32(uint zSign, int zExp, uint zFrac)
{
   return uintBitsToFloat((zSign<<31) + (uint(zExp)<<23) + zFrac);
}

/* Takes an abstract floating-point value having sign `zSign', exponent `zExp',
 * and significand `zFrac', and returns the proper single-precision floating-
 * point value corresponding to the abstract input.  Ordinarily, the abstract
 * value is simply rounded and packed into the single-precision format, with
 * the inexact exception raised if the abstract input cannot be represented
 * exactly.  However, if the abstract value is too large, the overflow and
 * inexact exceptions are raised and an infinity or maximal finite value is
 * returned.  If the abstract value is too small, the input value is rounded to
 * a subnormal number, and the underflow and inexact exceptions are raised if
 * the abstract input cannot be represented exactly as a subnormal single-
 * precision floating-point number.
 *     The input significand `zFrac' has its binary point between bits 30
 * and 29, which is 7 bits to the left of the usual location.  This shifted
 * significand must be normalized or smaller.  If `zFrac' is not normalized,
 * `zExp' must be 0; in that case, the result returned is a subnormal number,
 * and it must not require rounding.  In the usual case that `zFrac' is
 * normalized, `zExp' must be 1 less than the "true" floating-point exponent.
 * The handling of underflow and overflow follows the IEEE Standard for
 * Floating-Point Arithmetic.
 */
float
roundAndPackFloat32(uint zSign, int zExp, uint zFrac)
{
   bool roundNearestEven;
   int roundIncrement;
   int roundBits;

   roundNearestEven = FLOAT_ROUNDING_MODE == FLOAT_ROUND_NEAREST_EVEN;
   roundIncrement = 0x40;
   if (!roundNearestEven) {
      if (FLOAT_ROUNDING_MODE == FLOAT_ROUND_TO_ZERO) {
         roundIncrement = 0;
      } else {
         roundIncrement = 0x7F;
         if (zSign != 0u) {
            if (FLOAT_ROUNDING_MODE == FLOAT_ROUND_UP)
               roundIncrement = 0;
         } else {
            if (FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN)
               roundIncrement = 0;
         }
      }
   }
   roundBits = int(zFrac & 0x7Fu);
   if (0xFDu <= uint(zExp)) {
      if ((0xFD < zExp) || ((zExp == 0xFD) && (int(zFrac) + roundIncrement) < 0))
         return packFloat32(zSign, 0xFF, 0u) - float(roundIncrement == 0);
      int count = -zExp;
      bool zexp_lt0 = zExp < 0;
      uint zFrac_lt0 = mix(uint(zFrac != 0u), (zFrac>>count) | uint((zFrac<<((-count) & 31)) != 0u), (-zExp) < 32);
      zFrac = mix(zFrac, zFrac_lt0, zexp_lt0);
      roundBits = mix(roundBits, int(zFrac) & 0x7f, zexp_lt0);
      zExp = mix(zExp, 0, zexp_lt0);
   }
   zFrac = (zFrac + uint(roundIncrement))>>7;
   zFrac &= ~uint(((roundBits ^ 0x40) == 0) && roundNearestEven);

   return packFloat32(zSign, mix(zExp, 0, zFrac == 0u), zFrac);
}

/* Returns the result of converting the double-precision floating-point value
 * `a' to the single-precision floating-point format.  The conversion is
 * performed according to the IEEE Standard for Floating-Point Arithmetic.
 */
float
fp64_to_fp32(uvec2 a)
{
   uint zFrac = 0u;
   uint allZero = 0u;

   uint aFracLo = extractFloat64FracLo(a);
   uint aFracHi = extractFloat64FracHi(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);
   if (aExp == 0x7FF) {
      shortShift64Left(a.y, a.x, 12, a.y, a.x);
      float rval = uintBitsToFloat((aSign<<31) | 0x7FC00000u | (a.y>>9));
      rval = mix(packFloat32(aSign, 0xFF, 0u), rval, (aFracHi | aFracLo) != 0u);
      return rval;
   }
   shift64RightJamming(aFracHi, aFracLo, 22, allZero, zFrac);
   zFrac = mix(zFrac, zFrac | 0x40000000u, aExp != 0);
   return roundAndPackFloat32(aSign, aExp - 0x381, zFrac);
}

/* Returns the result of converting the single-precision floating-point value
 * `a' to the double-precision floating-point format.
 */
uvec2
fp32_to_fp64(float f)
{
   uint a = floatBitsToUint(f);
   uint aFrac = a & 0x007FFFFFu;
   int aExp = int((a>>23) & 0xFFu);
   uint aSign = a>>31;
   uint zFrac0 = 0u;
   uint zFrac1 = 0u;

   if (aExp == 0xFF) {
      if (aFrac != 0u) {
         uint nanLo = 0u;
         uint nanHi = a<<9;
         shift64Right(nanHi, nanLo, 12, nanHi, nanLo);
         nanHi |= ((aSign<<31) | 0x7FF80000u);
         return uvec2(nanLo, nanHi);
      }
      return packFloat64(aSign, 0x7FF, 0u, 0u);
    }

   if (aExp == 0) {
      if (aFrac == 0u)
         return packFloat64(aSign, 0, 0u, 0u);
      /* Normalize subnormal */
      int shiftCount = countLeadingZeros32(aFrac) - 8;
      aFrac <<= shiftCount;
      aExp = 1 - shiftCount;
      --aExp;
   }

   shift64Right(aFrac, 0u, 3, zFrac0, zFrac1);
   return packFloat64(aSign, aExp + 0x380, zFrac0, zFrac1);
}

/* Adds the 96-bit value formed by concatenating `a0', `a1', and `a2' to the
 * 96-bit value formed by concatenating `b0', `b1', and `b2'.  Addition is
 * modulo 2^96, so any carry out is lost.  The result is broken into three
 * 32-bit pieces which are stored at the locations pointed to by `z0Ptr',
 * `z1Ptr', and `z2Ptr'.
 */
void
add96(uint a0, uint a1, uint a2,
      uint b0, uint b1, uint b2,
      inout uint z0Ptr,
      inout uint z1Ptr,
      inout uint z2Ptr)
{
   uint z2 = a2 + b2;
   uint carry1 = uint(z2 < a2);
   uint z1 = a1 + b1;
   uint carry0 = uint(z1 < a1);
   uint z0 = a0 + b0;
   z1 += carry1;
   z0 += uint(z1 < carry1);
   z0 += carry0;
   z2Ptr = z2;
   z1Ptr = z1;
   z0Ptr = z0;
}

/* Subtracts the 96-bit value formed by concatenating `b0', `b1', and `b2' from
 * the 96-bit value formed by concatenating `a0', `a1', and `a2'.  Subtraction
 * is modulo 2^96, so any borrow out (carry out) is lost.  The result is broken
 * into three 32-bit pieces which are stored at the locations pointed to by
 * `z0Ptr', `z1Ptr', and `z2Ptr'.
 */
void
sub96(uint a0, uint a1, uint a2,
      uint b0, uint b1, uint b2,
      inout uint z0Ptr,
      inout uint z1Ptr,
      inout uint z2Ptr)
{
   uint z2 = a2 - b2;
   uint borrow1 = uint(a2 < b2);
   uint z1 = a1 - b1;
   uint borrow0 = uint(a1 < b1);
   uint z0 = a0 - b0;
   z0 -= uint(z1 < borrow1);
   z1 -= borrow1;
   z0 -= borrow0;
   z2Ptr = z2;
   z1Ptr = z1;
   z0Ptr = z0;
}

/* Returns an approximation to the 32-bit integer quotient obtained by dividing
 * `b' into the 64-bit value formed by concatenating `a0' and `a1'.  The
 * divisor `b' must be at least 2^31.  If q is the exact quotient truncated
 * toward zero, the approximation returned lies between q and q + 2 inclusive.
 * If the exact quotient q is larger than 32 bits, the maximum positive 32-bit
 * unsigned integer is returned.
 */
uint
estimateDiv64To32(uint a0, uint a1, uint b)
{
   uint b0;
   uint b1;
   uint rem0 = 0u;
   uint rem1 = 0u;
   uint term0 = 0u;
   uint term1 = 0u;
   uint z;

   if (b <= a0)
      return 0xFFFFFFFFu;
   b0 = b>>16;
   z = (b0<<16 <= a0) ? 0xFFFF0000u : (a0 / b0)<<16;
   mul32To64(b, z, term0, term1);
   sub64(a0, a1, term0, term1, rem0, rem1);
   while (int(rem0) < 0) {
      z -= 0x10000u;
      b1 = b<<16;
      add64(rem0, rem1, b0, b1, rem0, rem1);
   }
   rem0 = (rem0<<16) | (rem1>>16);
   z |= (b0<<16 <= rem0) ? 0xFFFFu : rem0 / b0;
   return z;
}

/*uint
sqrtOddAdjustments(int index)
{
   uint res = 0u;
   if (index == 0)
      res = 0x0004u;
   if (index == 1)
      res = 0x0022u;
   if (index == 2)
      res = 0x005Du;
   if (index == 3)
      res = 0x00B1u;
   if (index == 4)
      res = 0x011Du;
   if (index == 5)
      res = 0x019Fu;
   if (index == 6)
      res = 0x0236u;
   if (index == 7)
      res = 0x02E0u;
   if (index == 8)
      res = 0x039Cu;
   if (index == 9)
      res = 0x0468u;
   if (index == 10)
      res = 0x0545u;
   if (index == 11)
      res = 0x631u;
   if (index == 12)
      res = 0x072Bu;
   if (index == 13)
      res = 0x0832u;
   if (index == 14)
      res = 0x0946u;
   if (index == 15)
      res = 0x0A67u;

   return res;
}

uint
sqrtEvenAdjustments(int index)
{
   uint res = 0u;
   if (index == 0)
      res = 0x0A2Du;
   if (index == 1)
      res = 0x08AFu;
   if (index == 2)
      res = 0x075Au;
   if (index == 3)
      res = 0x0629u;
   if (index == 4)
      res = 0x051Au;
   if (index == 5)
      res = 0x0429u;
   if (index == 6)
      res = 0x0356u;
   if (index == 7)
      res = 0x029Eu;
   if (index == 8)
      res = 0x0200u;
   if (index == 9)
      res = 0x0179u;
   if (index == 10)
      res = 0x0109u;
   if (index == 11)
      res = 0x00AFu;
   if (index == 12)
      res = 0x0068u;
   if (index == 13)
      res = 0x0034u;
   if (index == 14)
      res = 0x0012u;
   if (index == 15)
      res = 0x0002u;

   return res;
}*/

/* Returns an approximation to the square root of the 32-bit significand given
 * by `a'.  Considered as an integer, `a' must be at least 2^31.  If bit 0 of
 * `aExp' (the least significant bit) is 1, the integer returned approximates
 * 2^31*sqrt(`a'/2^31), where `a' is considered an integer.  If bit 0 of `aExp'
 * is 0, the integer returned approximates 2^31*sqrt(`a'/2^30).  In either
 * case, the approximation returned lies strictly within +/-2 of the exact
 * value.
 */
/*uint estimateSqrt32(int aExp, uint a)
{
   uint z;

   int index = int(a>>27 & 15u);
   if ((aExp & 1) != 0) {
      z = 0x4000u + (a>>17) - sqrtOddAdjustments(index);
      z = ((a / z)<<14) + (z<<15);
      a >>= 1;
   } else {
      z = 0x8000u + (a>>17) - sqrtEvenAdjustments(index);
      z = a / z + z;
      z = (0x20000u <= z) ? 0xFFFF8000u : (z<<15);
      if (z <= a)
         return uint(int(a)>>1);
   }
   return ((estimateDiv64To32(a, 0u, z))>>1) + (z>>1);
}*/

/* Returns the square root of the double-precision floating-point value `a'.
 * The operation is performed according to the IEEE Standard for Floating-Point
 * Arithmetic.
 */
uvec2
fsqrt64(uvec2 a)
{
/*   uint zFrac0 = 0u;
   uint zFrac1 = 0u;
   uint zFrac2 = 0u;
   uint doubleZFrac0 = 0u;
   uint rem0 = 0u;
   uint rem1 = 0u;
   uint rem2 = 0u;
   uint rem3 = 0u;
   uint term0 = 0u;
   uint term1 = 0u;
   uint term2 = 0u;
   uint term3 = 0u;
   uvec2 default_nan;
   default_nan.y = 0xFFFFFFFFu;
   default_nan.x = 0xFFFFFFFFu;

   uint aFracLo = extractFloat64FracLo(a);
   uint aFracHi = extractFloat64FracHi(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);
   if (aExp == 0x7FF) {
      if ((aFracHi | aFracLo) != 0u)
         return propagateFloat64NaN(a, a);
      if (aSign == 0u)
         return a;
      return default_nan;
   }
   if (aSign != 0u) {
      if ((uint(aExp) | aFracHi | aFracLo) == 0u)
         return a;
      return default_nan;
   }
   if (aExp == 0) {
      if ((aFracHi | aFracLo) == 0u)
         return packFloat64(0u, 0, 0u, 0u);
      normalizeFloat64Subnormal(aFracHi, aFracLo, aExp, aFracHi, aFracLo);
   }
   int zExp = ((aExp - 0x3FF)>>1) + 0x3FE;
   aFracHi |= 0x00100000u;
   shortShift64Left(aFracHi, aFracLo, 11, term0, term1);
   zFrac0 = (estimateSqrt32(aExp, term0)>>1) + 1u;
   if (zFrac0 == 0u)
      zFrac0 = 0x7FFFFFFFu;
   doubleZFrac0 = zFrac0 + zFrac0;
   shortShift64Left(aFracHi, aFracLo, 9 - (aExp & 1), aFracHi, aFracLo);
   mul32To64(zFrac0, zFrac0, term0, term1);
   sub64(aFracHi, aFracLo, term0, term1, rem0, rem1);
   while (int(rem0) < 0) {
      --zFrac0;
      doubleZFrac0 -= 2u;
      add64(rem0, rem1, 0u, doubleZFrac0 | 1u, rem0, rem1);
   }
   zFrac1 = estimateDiv64To32(rem1, 0u, doubleZFrac0);
   if ((zFrac1 & 0x1FFu) <= 5u) {
      if (zFrac1 == 0u)
         zFrac1 = 1u;
      mul32To64(doubleZFrac0, zFrac1, term1, term2);
      sub64(rem1, 0u, term1, term2, rem1, rem2);
      mul32To64(zFrac1, zFrac1, term2, term3);
      sub96(rem1, rem2, 0u, 0u, term2, term3, rem1, rem2, rem3);
      while (int(rem1) < 0) {
         --zFrac1;
         shortShift64Left(0u, zFrac1, 1, term2, term3);
         term3 |= 1u;
         term2 |= doubleZFrac0;
         add96(rem1, rem2, rem3, 0u, term2, term3, rem1, rem2, rem3);
      }
      zFrac1 |= uint((rem1 | rem2 | rem3) != 0u);
   }
   shift64ExtraRightJamming(zFrac0, zFrac1, 0u, 10, zFrac0, zFrac1, zFrac2);
   return roundAndPackFloat64(0u, zExp, zFrac0, zFrac1, zFrac2);*/

   return fp32_to_fp64(sqrt(fp64_to_fp32(a)));
}

uvec2
ftrunc64(uvec2 a)
{
   int aExp = extractFloat64Exp(a);
   uint zLo;
   uint zHi;

   int unbiasedExp = aExp - 1023;
   int fracBits = 52 - unbiasedExp;
   uint maskLo = (fracBits >= 32) ? 0u : (~0u << fracBits);
   uint maskHi = (fracBits < 33) ? ~0u : (~0u << (fracBits - 32));
   zLo = maskLo & a.x;
   zHi = maskHi & a.y;

   zLo = mix(zLo, 0u, unbiasedExp < 0);
   zHi = mix(zHi, 0u, unbiasedExp < 0);
   zLo = mix(zLo, a.x, unbiasedExp > 52);
   zHi = mix(zHi, a.y, unbiasedExp > 52);
   return uvec2(zLo, zHi);
}

uvec2
fround64(uvec2 a)
{
   int unbiasedExp = extractFloat64Exp(a) - 1023;
   uint aHi = a.y;
   uint aLo = a.x;

   if (unbiasedExp < 20) {
      if (unbiasedExp < 0) {
         aHi &= 0x80000000u;
         if (unbiasedExp == -1 && aLo != 0u)
            aHi |= (1023u << 20);
         aLo = 0u;
      } else {
         uint maskExp = 0x000FFFFFu >> unbiasedExp;
         /* a is an integral value */
         if (((aHi & maskExp) == 0u) && (aLo == 0u))
            return a;

         aHi += 0x00080000u >> unbiasedExp;
         aHi &= ~maskExp;
         aLo = 0u;
      }
   } else if (unbiasedExp > 51 || unbiasedExp == 1024) {
      return a;
   } else {
      uint maskExp = 0xFFFFFFFFu >> (unbiasedExp - 20);
      if ((aLo & maskExp) == 0u)
         return a;
      uint tmp = aLo + (1u << (51 - unbiasedExp));
      if(tmp < aLo)
         aHi += 1u;
      aLo = tmp;
      aLo &= ~maskExp;
   }

   a.x = aLo;
   a.y = aHi;
   return a;
}

uvec2
frcp64(uvec2 a)
{
   /* pow(x, -0,5) */
//   sub64(0xBFCDD6A1u, 0x8F6A6F52u, a.y, a.x, a.y, a.x);
//   shift64Right(a.y, a.x, 1, a.y, a.x);
   /* pow(pow(x, -0.5), 2) = pow(x, -1) = 1/x */
//   return fmul64(a, a);

   return fp32_to_fp64(1.0/fp64_to_fp32(a));
}
