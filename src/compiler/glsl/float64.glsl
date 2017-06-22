/* Compile with:
 *
 * glsl_compiler --version 130 --dump-builder float64.glsl > builtin_float64.h
 *
 */

#version 130
#extension GL_ARB_shader_bit_encoding : enable

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
   if(is_nan(a))
      return a;

   a.y ^= (1u<<31);
   return a;
}

/* Returns the fraction bits of the double-precision floating-point value `a'.*/
uvec2
extractFloat64Frac(uvec2 a)
{
   uvec2 frac;
   frac.y = a.y & 0x000FFFFFu;
   frac.x = a.x;
   return frac;
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
   uvec2 aFrac;
   uvec2 bFrac;
   bool isaNaN;
   bool isbNaN;

   aFrac = extractFloat64Frac(a);
   bFrac = extractFloat64Frac(b);
   isaNaN = (extractFloat64Exp(a) == 0x7FF) &&
      ((aFrac.y | aFrac.x) != 0u);
   isbNaN = (extractFloat64Exp(b) == 0x7FF) &&
      ((bFrac.y | bFrac.x) != 0u);

   if (isaNaN || isbNaN)
      return false;

   return (a.x == b.x) &&
      ((a.y == b.y) || ((a.x == 0u) && (((a.y | b.y)<<1) == 0u)));
}

/* Returns the sign bit of the double-precision floating-point value `a'.*/
uint
extractFloat64Sign(uvec2 a)
{
   return (a.y>>31);
}

/* Returns true if the 64-bit value formed by concatenating `a0' and `a1' is less
 * than or equal to the 64-bit value formed by concatenating `b0' and `b1'.
 * Otherwise, returns false.
 */
bool
le64(uint a0, uint a1, uint b0, uint b1)
{
   return (a0 < b0) || ((a0 == b0) && (a1 <= b1));
}

/* Returns true if the double-precision floating-point value `a' is less than or
 * equal to the corresponding value `b', and false otherwise.  The comparison is
 * performed according to the IEEE Standard for Floating-Point Arithmetic.
 */
bool
fle64(uvec2 a, uvec2 b)
{
   uint aSign;
   uint bSign;
   uvec2 aFrac;
   uvec2 bFrac;
   bool isaNaN;
   bool isbNaN;

   aFrac = extractFloat64Frac(a);
   bFrac = extractFloat64Frac(b);
   isaNaN = (extractFloat64Exp(a) == 0x7FF) &&
      ((aFrac.y | aFrac.x) != 0u);
   isbNaN = (extractFloat64Exp(b) == 0x7FF) &&
      ((bFrac.y | bFrac.x) != 0u);

   if (isaNaN || isbNaN)
      return false;

   aSign = extractFloat64Sign(a);
   bSign = extractFloat64Sign(b);
   if (aSign != bSign)
      return (aSign != 0u) || (((((a.y | b.y)<<1)) | a.x | b.x) == 0u);

   return (aSign != 0u) ? le64(b.y, b.x, a.y, a.x)
      : le64(a.y, a.x, b.y, b.x);
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
   uvec2 aFrac;
   uvec2 bFrac;
   bool isaNaN;
   bool isbNaN;

   aFrac = extractFloat64Frac(a);
   bFrac = extractFloat64Frac(b);
   isaNaN = (extractFloat64Exp(a) == 0x7FF) &&
      ((aFrac.y | aFrac.x) != 0u);
   isbNaN = (extractFloat64Exp(b) == 0x7FF) &&
      ((bFrac.y | bFrac.x) != 0u);

   if (isaNaN || isbNaN)
      return false;

   aSign = extractFloat64Sign(a);
   bSign = extractFloat64Sign(b);
   if (aSign != bSign)
      return (aSign != 0u) && (((((a.y | b.y)<<1)) | a.x | b.x) != 0u);

   return (aSign != 0u) ? lt64(b.y, b.x, a.y, a.x)
      : lt64(a.y, a.x, b.y, b.x);
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

/* Returns 1 if the 64-bit value formed by concatenating `a0' and `a1' is
 * equal to the 64-bit value formed by concatenating `b0' and `b1'.  Otherwise,
 * returns 0.
 */
bool
eq64(uint a0, uint a1, uint b0, uint b1)
{
   return (a0 == b0) && (a1 == b1);
}

/* Returns 1 if the double-precision floating-point value `a' is a signaling
 * NaN; otherwise returns 0.
 */
bool
float64_is_signaling_nan(uvec2 a)
{
   return (((a.y>>19) & 0xFFFu) == 0xFFEu) &&
      ((a.x != 0u) || ((a.y & 0x0007FFFFu) != 0u));
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

   if (count == 0) {
      z1 = a1;
      z0 = a0;
   } else if (count < 32) {
      z1 = (a0<<negCount) | (a1>>count) | uint ((a1<<negCount) != 0u);
      z0 = a0>>count;
   } else {
      if (count == 32) {
         z1 = a0 | uint(a1 != 0u);
      } else if (count < 64) {
         z1 = (a0>>(count & 31)) | uint(((a0<<negCount) | a1) != 0u);
      } else {
         z1 = uint((a0 | a1) != 0u);
      }
      z0 = 0u;
   }
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
   uint z0;
   uint z1;
   uint z2;
   int negCount = (-count) & 31;

   if (count == 0) {
      z2 = a2;
      z1 = a1;
      z0 = a0;
   } else {
      if (count < 32) {
         z2 = a1<<negCount;
         z1 = (a0<<negCount) | (a1>>count);
         z0 = a0>>count;
      } else {
         if (count == 32) {
            z2 = a1;
            z1 = a0;
         } else {
            a2 |= a1;
            if (count < 64) {
               z2 = a0<<negCount;
               z1 = a0>>(count & 31);
            } else {
               z2 = (count == 64) ? a0 : uint(a0 != 0u);
               z1 = 0u;
            }
         }
         z0 = 0u;
      }
      z2 |= uint(a2 != 0u);
   }
   z2Ptr = z2;
   z1Ptr = z1;
   z0Ptr = z0;
}

/* Shifts the 64-bit value formed by concatenating `a0' and `a1' left by the
 * number of bits given in `count'.  Any bits shifted off are lost.  The value
 * of `count' must be less than 32.  The result is broken into two 32-bit
 * pieces which are stored at the locations pointed to by `z0Ptr' and `z1Ptr'.
 */
void shortShift64Left(uint a0, uint a1,
                      int count,
                      inout uint z0Ptr,
                      inout uint z1Ptr)
{
   z1Ptr = a1<<count;
   z0Ptr = (count == 0) ? a0 : (a0<<count) | (a1>>((-count) & 31));
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
            eq64(0x001FFFFFu, 0xFFFFFFFFu, zFrac0, zFrac1) &&
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
      if ((zFrac0 | zFrac1) == 0u)
         zExp = 0;
   }
   return packFloat64(zSign, zExp, zFrac0, zFrac1);
}

/* Returns the number of leading 0 bits before the most-significant 1 bit of
 * `a'.  If `a' is zero, 32 is returned.
 */
int
countLeadingZeros32(uint a)
{
   if (a == 0u)
      return 32;

   int shiftCount = 0;
   if ((a & 0xFFFF0000u) == 0u) {shiftCount += 16; a <<= 16;}
   if ((a & 0xFF000000u) == 0u) {shiftCount += 8; a <<= 8;}
   if ((a & 0xF0000000u) == 0u) {shiftCount += 4; a <<= 4;}
   if ((a & 0xC0000000u) == 0u) {shiftCount += 2; a <<= 2;}
   if ((a & 0x80000000u) == 0u) {shiftCount += 1;}

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

   if (zFrac0 == 0u) {
      zFrac0 = zFrac1;
      zFrac1 = 0u;
      zExp -= 32;
   }
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
 * is a NaN, and returns the appropriate NaN result.  If either `a' or `b' is
 * a signaling NaN, the invalid exception is raised.
 */
uvec2
propagateFloat64NaN(uvec2 a, uvec2 b)
{
   bool aIsNaN = is_nan(a);
   bool aIsSignalingNaN = float64_is_signaling_nan(a);
   bool bIsNaN = is_nan(b);
   bool bIsSignalingNaN = float64_is_signaling_nan(b);
   a.y |= 0x00080000u;
   b.y |= 0x00080000u;
   if (aIsNaN)
      return (aIsSignalingNaN && bIsNaN) ? b : a;
   else
      return b;
}

/* Returns the result of adding the absolute values of the double-precision
 * floating-point values `a' and `b'.  If `zSign' is 1, the sum is negated
 * before being returned.  `zSign' is ignored if the result is a NaN.  The
 * addition is performed according to the IEEE Standard for Floating-Point
 * Arithmetic.
 */
uvec2
addFloat64Fracs(uvec2 a, uvec2 b, uint zSign)
{
   uint zFrac0 = 0u;
   uint zFrac1 = 0u;
   uint zFrac2 = 0u;
   int zExp;

   uvec2 aFrac = extractFloat64Frac(a);
   int aExp = extractFloat64Exp(a);
   uvec2 bFrac = extractFloat64Frac(b);
   int bExp = extractFloat64Exp(b);
   int expDiff = aExp - bExp;
   if (0 < expDiff) {
      if (aExp == 0x7FF) {
         if ((aFrac.y | aFrac.x) != 0u)
            return propagateFloat64NaN(a, b);
         return a;
      }
      if (bExp == 0)
         --expDiff;
      else
         bFrac.y |= 0x00100000u;
      shift64ExtraRightJamming(
         bFrac.y, bFrac.x, 0u, expDiff, bFrac.y, bFrac.x, zFrac2);
      zExp = aExp;
   } else if (expDiff < 0) {
      if (bExp == 0x7FF) {
         if ((bFrac.y | bFrac.x) != 0u)
            return propagateFloat64NaN(a, b);
         return packFloat64(zSign, 0x7FF, 0u, 0u);
      }
      if (aExp == 0)
         ++expDiff;
      else
         aFrac.y |= 0x00100000u;
      shift64ExtraRightJamming(
         aFrac.y, aFrac.x, 0u, - expDiff, aFrac.y, aFrac.x, zFrac2);
      zExp = bExp;
   } else {
      if (aExp == 0x7FF) {
         if ((aFrac.y | aFrac.x | bFrac.y | bFrac.x) != 0u)
            return propagateFloat64NaN(a, b);
         return a;
      }
      add64(aFrac.y, aFrac.x, bFrac.y, bFrac.x, zFrac0, zFrac1);
      if (aExp == 0)
         return packFloat64(zSign, 0, zFrac0, zFrac1);
      zFrac2 = 0u;
      zFrac0 |= 0x00200000u;
      zExp = aExp;
      shift64ExtraRightJamming(
         zFrac0, zFrac1, zFrac2, 1, zFrac0, zFrac1, zFrac2);
      return roundAndPackFloat64(zSign, zExp, zFrac0, zFrac1, zFrac2);
   }
   aFrac.y |= 0x00100000u;
   add64(aFrac.y, aFrac.x, bFrac.y, bFrac.x, zFrac0, zFrac1);
   --zExp;
   if (zFrac0 < 0x00200000u)
      return roundAndPackFloat64(zSign, zExp, zFrac0, zFrac1, zFrac2);
   ++zExp;
   shift64ExtraRightJamming(zFrac0, zFrac1, zFrac2, 1, zFrac0, zFrac1, zFrac2);
   return roundAndPackFloat64(zSign, zExp, zFrac0, zFrac1, zFrac2);
}

/* Returns the result of subtracting the absolute values of the double-
 * precision floating-point values `a' and `b'.  If `zSign' is 1, the
 * difference is negated before being returned.  `zSign' is ignored if the
 * result is a NaN.  The subtraction is performed according to the IEEE
 * Standard for Floating-Point Arithmetic.
 */
uvec2
subFloat64Fracs(uvec2 a, uvec2 b, uint zSign)
{
   uvec2 z;
   int zExp;
   uint zFrac0 = 0u;
   uint zFrac1 = 0u;

   uvec2 aFrac = extractFloat64Frac(a);
   int aExp = extractFloat64Exp(a);
   uvec2 bFrac = extractFloat64Frac(b);
   int bExp = extractFloat64Exp(b);
   int expDiff = aExp - bExp;
   shortShift64Left(aFrac.y, aFrac.x, 10, aFrac.y, aFrac.x);
   shortShift64Left(bFrac.y, bFrac.x, 10, bFrac.y, bFrac.x);
   if (0 < expDiff) {
      if (aExp == 0x7FF) {
         if ((aFrac.y | aFrac.x) != 0u) {
            return propagateFloat64NaN(a, b);
         }
         return a;
      }
      if (bExp == 0)
         --expDiff;
      else
         bFrac.y |= 0x40000000u;
      shift64RightJamming(bFrac.y, bFrac.x, expDiff, bFrac.y, bFrac.x);
      aFrac.y |= 0x40000000u;
      sub64(aFrac.y, aFrac.x, bFrac.y, bFrac.x, zFrac0, zFrac1);
      zExp = aExp;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10, zFrac0, zFrac1);
   }
   if (expDiff < 0) {
      if (bExp == 0x7FF) {
         if ((bFrac.y | bFrac.x) != 0u)
            return propagateFloat64NaN(a, b);
         return packFloat64(zSign ^ 1u, 0x7FF, 0u, 0u);
      }
      if (aExp == 0)
         ++expDiff;
      else
         aFrac.y |= 0x40000000u;
      shift64RightJamming(aFrac.y, aFrac.x, - expDiff, aFrac.y, aFrac.x);
      bFrac.y |= 0x40000000u;
      sub64(bFrac.y, bFrac.x, aFrac.y, aFrac.x, zFrac0, zFrac1);
      zExp = bExp;
      zSign ^= 1u;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10, zFrac0, zFrac1);
   }
   if (aExp == 0x7FF) {
      if ((aFrac.y | aFrac.x | bFrac.y | bFrac.x) != 0u)
         return propagateFloat64NaN(a, b);
      return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
   }
   if (aExp == 0) {
      aExp = 1;
      bExp = 1;
   }
   if (bFrac.y < aFrac.y) {
      sub64(aFrac.y, aFrac.x, bFrac.y, bFrac.x, zFrac0, zFrac1);
      zExp = aExp;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10, zFrac0, zFrac1);
   }
   if (aFrac.y < bFrac.y) {
      sub64(bFrac.y, bFrac.x, aFrac.y, aFrac.x, zFrac0, zFrac1);
      zExp = bExp;
      zSign ^= 1u;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10, zFrac0, zFrac1);
   }
   if (bFrac.x < aFrac.x) {
      sub64(aFrac.y, aFrac.x, bFrac.y, bFrac.x, zFrac0, zFrac1);
      zExp = aExp;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10, zFrac0, zFrac1);
   }
   if (aFrac.x < bFrac.x) {
      sub64(bFrac.y, bFrac.x, aFrac.y, aFrac.x, zFrac0, zFrac1);
      zExp = bExp;
      zSign ^= 1u;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10, zFrac0, zFrac1);
   }
   return packFloat64(
      uint(FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN), 0, 0u, 0u);
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

   if (aSign == bSign)
      return addFloat64Fracs(a, b, aSign);
   else
      return subFloat64Fracs(a, b, aSign);
}

/* Returns the result of subtracting the double-precision floating-point values
 * `a' and `b'.  The operation is performed according to the IEEE Standard for
 * Floating-Point Arithmetic.
 */
uvec2
fsub64(uvec2 a, uvec2 b)
{
   uint aSign = extractFloat64Sign(a);
   uint bSign = extractFloat64Sign(b);

   if (aSign == bSign)
      return subFloat64Fracs(a, b, aSign);
   else
      return addFloat64Fracs(a, b, aSign);
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

   if (aFrac0 == 0u) {
      shiftCount = countLeadingZeros32(aFrac1) - 11;
      if (shiftCount < 0) {
         zFrac0Ptr = aFrac1>>(-shiftCount);
         zFrac1Ptr = aFrac1<<(shiftCount & 31);
      } else {
         zFrac0Ptr = aFrac1<<shiftCount;
         zFrac1Ptr = 0u;
      }
      zExpPtr = -shiftCount - 31;
   } else {
      shiftCount = countLeadingZeros32(aFrac0) - 11;
      shortShift64Left(aFrac0, aFrac1, shiftCount, zFrac0Ptr, zFrac1Ptr);
      zExpPtr = 1 - shiftCount;
   }
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

   uvec2 aFrac = extractFloat64Frac(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);
   uvec2 bFrac = extractFloat64Frac(b);
   int bExp = extractFloat64Exp(b);
   uint bSign = extractFloat64Sign(b);
   uint zSign = aSign ^ bSign;
   if (aExp == 0x7FF) {
      if (((aFrac.y | aFrac.x) != 0u) ||
         ((bExp == 0x7FF) && ((bFrac.y | bFrac.x) != 0u))) {
         return propagateFloat64NaN(a, b);
      }
      if ((uint(bExp) | bFrac.y | bFrac.x) == 0u)
            return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
      return packFloat64(zSign, 0x7FF, 0u, 0u);
   }
   if (bExp == 0x7FF) {
      if ((bFrac.y | bFrac.x) != 0u)
         return propagateFloat64NaN(a, b);
      if ((uint(aExp) | aFrac.y | aFrac.x) == 0u)
         return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
      return packFloat64(zSign, 0x7FF, 0u, 0u);
   }
   if (aExp == 0) {
      if ((aFrac.y | aFrac.x) == 0u)
         return packFloat64(zSign, 0, 0u, 0u);
      normalizeFloat64Subnormal(aFrac.y, aFrac.x, aExp, aFrac.y, aFrac.x);
   }
   if (bExp == 0) {
      if ((bFrac.y | bFrac.x) == 0u)
         return packFloat64(zSign, 0, 0u, 0u);
      normalizeFloat64Subnormal(bFrac.y, bFrac.x, bExp, bFrac.y, bFrac.x);
   }
   zExp = aExp + bExp - 0x400;
   aFrac.y |= 0x00100000u;
   shortShift64Left(bFrac.y, bFrac.x, 12, bFrac.y, bFrac.x);
   mul64To128(
      aFrac.y, aFrac.x, bFrac.y, bFrac.x, zFrac0, zFrac1, zFrac2, zFrac3);
   add64(zFrac0, zFrac1, aFrac.y, aFrac.x, zFrac0, zFrac1);
   zFrac2 |= uint(zFrac3 != 0u);
   if (0x00200000u <= zFrac0) {
      shift64ExtraRightJamming(
         zFrac0, zFrac1, zFrac2, 1, zFrac0, zFrac1, zFrac2);
      ++zExp;
   }
   return roundAndPackFloat64(zSign, zExp, zFrac0, zFrac1, zFrac2);
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

   if (count == 0) {
      z1 = a1;
      z0 = a0;
   } else if (count < 32) {
      z1 = (a0<<negCount) | (a1>>count);
      z0 = a0>>count;
   } else {
      z1 = (count < 64) ? (a0>>(count & 31)) : 0u;
      z0 = 0u;
   }
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

/* Multiplies the 64-bit value formed by concatenating `a0' and `a1' by `b'
 * to obtain a 96-bit product.  The product is broken into three 32-bit pieces
 * which are stored at the locations pointed to by `z0Ptr', `z1Ptr', and
 * `z2Ptr'.
 */
void
mul64By32To96(uint a0, uint a1,
              uint b,
              inout uint z0Ptr,
              inout uint z1Ptr,
              inout uint z2Ptr)
{
   uint z0 = 0u;
   uint z1 = 0u;
   uint z2 = 0u;
   uint more1 = 0u;

   mul32To64(a1, b, z1, z2);
   mul32To64(a0, b, z0, more1);
   add64(z0, more1, 0u, z1, z0, z1);
   z2Ptr = z2;
   z1Ptr = z1;
   z0Ptr = z0;
}

/* Returns the result of dividing the double-precision floating-point value
 * `a' by the corresponding value `b'. The operation is performed according to
 * the IEEE Standard for Floating-Point Arithmetic.
 */
uvec2
fdiv64(uvec2 a, uvec2 b)
{
   int zExp;
   uint zFrac0 = 0u;
   uint zFrac1 = 0u;
   uint zFrac2 = 0u;
   uint rem0 = 0u;
   uint rem1 = 0u;
   uint rem2 = 0u;
   uint rem3 = 0u;
   uint term0 = 0u;
   uint term1 = 0u;
   uint term2 = 0u;
   uint term3 = 0u;

   uvec2 aFrac = extractFloat64Frac(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);
   uvec2 bFrac = extractFloat64Frac(b);
   int bExp = extractFloat64Exp(b);
   uint bSign = extractFloat64Sign(b);
   uint zSign = aSign ^ bSign;
   if (aExp == 0x7FF) {
      if ((aFrac.y | aFrac.x) != 0u)
         return propagateFloat64NaN(a, b);
      if (bExp == 0x7FF) {
         if ((bFrac.y | bFrac.x) != 0u)
            return propagateFloat64NaN(a, b);
         return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
      }
      return packFloat64(zSign, 0x7FF, 0u, 0u);
   }
   if (bExp == 0x7FF) {
      if ((bFrac.y | bFrac.x) != 0u)
         return propagateFloat64NaN(a, b);
      return packFloat64(zSign, 0, 0u, 0u);
   }
   if (bExp == 0) {
      if ((bFrac.y | bFrac.x) == 0u) {
         if ((uint(aExp) | aFrac.y | aFrac.x) == 0u)
            return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
         return packFloat64(zSign, 0x7FF, 0u, 0u);
      }
      normalizeFloat64Subnormal(bFrac.y, bFrac.x, bExp, bFrac.y, bFrac.x);
   }
   if (aExp == 0) {
      if ((aFrac.y | aFrac.x) == 0u)
         return packFloat64(zSign, 0, 0u, 0u);
      normalizeFloat64Subnormal(aFrac.y, aFrac.x, aExp, aFrac.y, aFrac.x);
   }
   zExp = aExp - bExp + 0x3FD;
   shortShift64Left(aFrac.y | 0x00100000u, aFrac.x, 11, aFrac.y, aFrac.x);
   shortShift64Left(bFrac.y | 0x00100000u, bFrac.x, 11, bFrac.y, bFrac.x);
   if (le64(bFrac.y, bFrac.x, aFrac.y, aFrac.x)) {
      shift64Right(aFrac.y, aFrac.x, 1, aFrac.y, aFrac.x);
      ++zExp;
   }
   zFrac0 = estimateDiv64To32(aFrac.y, aFrac.x, bFrac.y);
   mul64By32To96(bFrac.y, bFrac.x, zFrac0, term0, term1, term2);
   sub96(aFrac.y, aFrac.x, 0u, term0, term1, term2, rem0, rem1, rem2);
   while (int(rem0) < 0) {
      --zFrac0;
      add96(rem0, rem1, rem2, 0u, bFrac.y, bFrac.x, rem0, rem1, rem2);
   }
   zFrac1 = estimateDiv64To32(rem1, rem2, bFrac.y);
   if ((zFrac1 & 0x3FFu) <= 4u) {
      mul64By32To96(bFrac.y, bFrac.x, zFrac1, term1, term2, term3);
      sub96(rem1, rem2, 0u, term1, term2, term3, rem1, rem2, rem3);
      while (int(rem1) < 0) {
         --zFrac1;
         add96(rem1, rem2, rem3, 0u, bFrac.y, bFrac.x, rem1, rem2, rem3);
      }
      zFrac1 |= uint(((rem1 | rem2 | rem3) != 0u));
   }
   shift64ExtraRightJamming(zFrac0, zFrac1, 0u, 11, zFrac0, zFrac1, zFrac2);
   return roundAndPackFloat64(zSign, zExp, zFrac0, zFrac1, zFrac2);
}

/* Normalizes the subnormal single-precision floating-point value represented
 * by the denormalized significand `aFrac'.  The normalized exponent and
 * significand are stored at the locations pointed to by `zExpPtr' and
 * `zFracPtr', respectively.
 */
void
normalizeFloat32Subnormal(uint aFrac,
                          inout int zExpPtr,
                          inout uint zFracPtr)
{
   int shiftCount = countLeadingZeros32(aFrac) - 8;
   zFracPtr = aFrac<<shiftCount;
   zExpPtr = 1 - shiftCount;
}

/* Returns the fraction bits of the single-precision floating-point value `a'.*/
uint
extractFloat32Frac(uint a)
{
   return a & 0x007FFFFFu;
}

/* Returns the exponent bits of the single-precision floating-point value `a'.*/
int
extractFloat32Exp(uint a)
{
   return int((a>>23) & 0xFFu);
}

/* Returns the sign bit of the single-precision floating-point value `a'.*/
uint
extractFloat32Sign(uint a)
{
   return a>>31;
}

/* Returns the result of converting the single-precision floating-point value
 * `a' to the double-precision floating-point format.
 */
uvec2
fp32_to_fp64(float f)
{
   uint a = floatBitsToUint(f);
   uint aFrac = extractFloat32Frac(a);
   int aExp = extractFloat32Exp(a);
   uint aSign = extractFloat32Sign(a);
   uint zFrac0 = 0u;
   uint zFrac1 = 0u;

   if (aExp == 0xFF) {
      if (aFrac != 0u) {
         uvec2 nan;
         nan.x = 0u;
         nan.y = a<<9;
         shift64Right(nan.y, nan.x, 12, nan.y, nan.x);
         nan.y |= ((aSign<<31) | 0x7FF80000u);
         return nan;
      }
      return packFloat64(aSign, 0x7FF, 0u, 0u);
    }

   if (aExp == 0) {
      if (aFrac == 0u)
         return packFloat64(aSign, 0, 0u, 0u);
      normalizeFloat32Subnormal(aFrac, aExp, aFrac);
      --aExp;
   }

   shift64Right(aFrac, 0u, 3, zFrac0, zFrac1);
   return packFloat64(aSign, aExp + 0x380, zFrac0, zFrac1);
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
uint
packFloat32(uint zSign, int zExp, uint zFrac)
{
   return (zSign<<31) + (uint(zExp)<<23) + zFrac;
}

/* Shifts `a' right by the number of bits given in `count'.  If any nonzero
 * bits are shifted off, they are "jammed" into the least significant bit of
 * the result by setting the least significant bit to 1.  The value of `count'
 * can be arbitrarily large; in particular, if `count' is greater than 32, the
 * result will be either 0 or 1, depending on whether `a' is zero or nonzero.
 * The result is stored in the location pointed to by `zPtr'.
 */
void
shift32RightJamming(uint a, int count, inout uint zPtr)
{
   uint z;

   if (count == 0) {
      z = a;
   } else if (count < 32) {
      z = (a>>count) | uint((a<<((-count) & 31)) != 0u);
   } else {
      z = uint(a != 0u);
   }
   zPtr = z;
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
uint
roundAndPackFloat32(uint zSign, int zExp, uint zFrac)
{
   bool roundNearestEven;
   uint roundIncrement;
   int roundBits;

   roundNearestEven = FLOAT_ROUNDING_MODE == FLOAT_ROUND_NEAREST_EVEN;
   roundIncrement = 0x40u;
   if (!roundNearestEven) {
      if (FLOAT_ROUNDING_MODE == FLOAT_ROUND_TO_ZERO) {
         roundIncrement = 0u;
      } else {
         roundIncrement = 0x7Fu;
         if (zSign != 0u) {
            if (FLOAT_ROUNDING_MODE == FLOAT_ROUND_UP)
               roundIncrement = 0u;
         } else {
            if (FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN)
               roundIncrement = 0u;
         }
      }
   }
   roundBits = int(zFrac) & 0x7F;
   if (0xFDu <= uint(zExp)) {
      if ((0xFD < zExp) || ((zExp == 0xFD) && (int(zFrac + roundIncrement) < 0)))
            return packFloat32(zSign, 0xFF, 0u) - uint(roundIncrement == 0u);
      if (zExp < 0) {
         shift32RightJamming(zFrac, -zExp, zFrac);
         zExp = 0;
         roundBits = int(zFrac) & 0x7F;
      }
   }
   zFrac = (zFrac + roundIncrement)>>7;
   zFrac &= ~(uint((roundBits ^ 0x40) == 0) & uint(roundNearestEven));
   if (zFrac == 0u)
      zExp = 0;

   return packFloat32(zSign, zExp, zFrac);
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

   uvec2 aFrac = extractFloat64Frac(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);
   if (aExp == 0x7FF) {
      if ((aFrac.y | aFrac.x) != 0u) {
         shortShift64Left(a.y, a.x, 12, a.y, a.x);
         return uintBitsToFloat((aSign<<31) | 0x7FC00000u | (a.y>>9));
      }
      return uintBitsToFloat(packFloat32(aSign, 0xFF, 0u));
   }
   shift64RightJamming(aFrac.y, aFrac.x, 22, allZero, zFrac);
   if (aExp != 0)
      zFrac |= 0x40000000u;

   return uintBitsToFloat(roundAndPackFloat32(aSign, aExp - 0x381, zFrac));
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
   uvec2 aFrac = extractFloat64Frac(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);

   int z;
   uint absZ = 0u;
   uint aFracExtra = 0u;
   int shiftCount = aExp - 0x413;
   if (0 <= shiftCount) {
      if (0x41E < aExp) {
         if ((aExp == 0x7FF) && ((aFrac.y | aFrac.x) != 0u))
            aSign = 0u;
         return (aSign != 0u) ? 0x80000000 : 0x7FFFFFFF;
      }
      shortShift64Left(aFrac.y | 0x00100000u, aFrac.x, shiftCount, absZ, aFracExtra);
      if (0x80000000u < absZ)
         return (aSign != 0u) ? 0x80000000 : 0x7FFFFFFF;
   } else {
      aFrac.x = uint(aFrac.x != 0u);
      if (aExp < 0x3FE) {
         aFracExtra = uint(aExp) | aFrac.y | aFrac.x;
         absZ = 0u;
      } else {
            aFrac.y |= 0x00100000u;
            aFracExtra = (aFrac.y << (shiftCount & 31)) | aFrac.x;
            absZ = aFrac.y >> (- shiftCount);
      }
   }
   if (FLOAT_ROUNDING_MODE == FLOAT_ROUND_NEAREST_EVEN) {
      if (int(aFracExtra) < 0) {
         ++absZ;
         if ((aFracExtra << 1) == 0u)
            absZ &= ~1u;
      }
      z = (aSign != 0u) ? - int(absZ) : int(absZ);
   } else {
      aFracExtra = uint(aFracExtra != 0u);
      if (aSign != 0u) {
         z = -int(absZ + (uint(FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN) & aFracExtra));
      } else {
         z = int(absZ + (uint(FLOAT_ROUNDING_MODE == FLOAT_ROUND_UP) & aFracExtra));
      }
   }
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

/* Returns true if the double-precision floating-point value `a' is greater than
 * the corresponding value `b', and false otherwise.  The comparison is performed
 * according to the IEEE Standard for Floating-Point Arithmetic.
 */
bool
fgt64(uvec2 a, uvec2 b)
{
   return flt64(b, a);
}

uvec2
ffma64(uvec2 a, uvec2 b, uvec2 c)
{
   return fadd64(fmul64(a, b), c);
}

/*
uint
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
}
*/
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
         return uint(((int(a))>>1));
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
/*
   uint zFrac0 = 0u;
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

   uvec2 aFrac = extractFloat64Frac(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);
   if (aExp == 0x7FF) {
      if ((aFrac.y | aFrac.x) != 0u)
         return propagateFloat64NaN(a, a);
      if (aSign == 0u)
         return a;
      return default_nan;
   }
   if (aSign != 0u) {
      if ((uint(aExp) | aFrac.y | aFrac.x) == 0u)
         return a;
      return default_nan;
   }
   if (aExp == 0) {
      if ((aFrac.y | aFrac.x) == 0u)
         return packFloat64(0u, 0, 0u, 0u);
      normalizeFloat64Subnormal(aFrac.y, aFrac.x, aExp, aFrac.y, aFrac.x);
   }
   int zExp = ((aExp - 0x3FF)>>1) + 0x3FE;
   aFrac.y |= 0x00100000u;
   shortShift64Left(aFrac.y, aFrac.x, 11, term0, term1);
   zFrac0 = (estimateSqrt32(aExp, term0)>>1) + 1u;
   if (zFrac0 == 0u)
      zFrac0 = 0x7FFFFFFFu;
   doubleZFrac0 = zFrac0 + zFrac0;
   shortShift64Left(aFrac.y, aFrac.x, 9 - (aExp & 1), aFrac.y, aFrac.x);
   mul32To64(zFrac0, zFrac0, term0, term1);
   sub64(aFrac.y, aFrac.x, term0, term1, rem0, rem1);
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
   return roundAndPackFloat64(0u, zExp, zFrac0, zFrac1, zFrac2);
*/
   return fp32_to_fp64(sqrt(fp64_to_fp32(a)));
}

uvec2
uint_to_fp64(uint a)
{
   if (a == 0u)
      return uvec2(0u, 0u);

   int shiftDist = countLeadingZeros32(a) + 21;

   uint aHigh = 0u;
   uint aLow = 0u;

   aHigh = a >> (32 - shiftDist);
   aLow = a << shiftDist;

   return packFloat64(0u, 0x432- shiftDist, aHigh, aLow);
}

uint
roundToUint(uint zSign, uint zFrac0, uint zFrac1)
{
   bool roundNearEven = FLOAT_ROUNDING_MODE == FLOAT_ROUND_NEAREST_EVEN;
   uint roundIncrement = 0x800u;
   uint z;

   add64(zFrac0, zFrac1, 0u, roundIncrement, zFrac0, zFrac1);

   if ((zFrac0 & 0xFFFFF000u) != 0u)
      return (zSign != 0u) ? 0u : ~0u;

   z = (zFrac1 >> 12) | ((zFrac0 & 0x00000FFFu) << 20);
   z &= ~ uint(!bool((zFrac1 & 0xFFFu) ^ 0x800u)) & uint(roundNearEven);
   if ((zSign != 0u) && (z != 0u))
      return (zSign != 0u) ? 0u : ~0u;
   return z;
}

uint
fp64_to_uint(uvec2 a)
{
   uvec2 aFrac = extractFloat64Frac(a);
   int aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);

   if (aSign != 0u)
      return 0u;

   if ((aExp == 0x7FF) && ((aFrac.y | aFrac.x) != 0u))
      return 0xFFFFFFFFu;

   if (aExp != 0)
      aFrac.y |= 0x00100000u;

   int shiftDist = 0x427 - aExp;
   if (0 < shiftDist)
      shift64RightJamming(aFrac.y, aFrac.x, shiftDist, aFrac.y, aFrac.x);

   return roundToUint(aSign, aFrac.y, aFrac.x);

}
