/* Compile with:
 *
 * glsl_compiler --version 130 --dump-builder float64.glsl > builtin_float64.h
 *
 */

#version 130

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
   a.x &= 0x7FFFFFFFu;
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

   a.x ^= (1u<<31);
   return a;
}

/* Returns the fraction bits of the double-precision floating-point value `a'.*/
uvec2
extractFloat64Frac(uvec2 a)
{
   return uvec2(a.x & 0x000FFFFFu, a.y);
}

/* Returns the exponent bits of the double-precision floating-point value `a'.*/
uint
extractFloat64Exp(uvec2 a)
{
   return (a.x>>20) & 0x7FFu;
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
   isaNaN = (extractFloat64Exp(a) == 0x7FFu) &&
      ((aFrac.x | aFrac.y) != 0u);
   isbNaN = (extractFloat64Exp(b) == 0x7FFu) &&
      ((bFrac.x | bFrac.y) != 0u);

   if (isaNaN || isbNaN)
      return false;

   return (a.y == b.y) &&
      ((a.x == b.x) || ((a.y == 0u) && (((a.x | b.x)<<1) == 0u)));
}

/* Returns the sign bit of the double-precision floating-point value `a'.*/
uint
extractFloat64Sign(uvec2 a)
{
   return (a.x>>31);
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
   isaNaN = (extractFloat64Exp(a) == 0x7FFu) &&
      ((aFrac.x | aFrac.y) != 0u);
   isbNaN = (extractFloat64Exp(b) == 0x7FFu) &&
      ((bFrac.x | bFrac.y) != 0u);

   if (isaNaN || isbNaN)
      return false;

   aSign = extractFloat64Sign(a);
   bSign = extractFloat64Sign(b);
   if (aSign != bSign)
      return (aSign != 0u) || (((((a.x | b.x)<<1)) | a.y | b.y) == 0u);

   return (aSign != 0u) ? le64(b.x, b.y, a.x, a.y)
      : le64(a.x, a.y, b.x, b.y);
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
   isaNaN = (extractFloat64Exp(a) == 0x7FFu) &&
      ((aFrac.x | aFrac.y) != 0u);
   isbNaN = (extractFloat64Exp(b) == 0x7FFu) &&
      ((bFrac.x | bFrac.y) != 0u);

   if (isaNaN || isbNaN)
      return false;

   aSign = extractFloat64Sign(a);
   bSign = extractFloat64Sign(b);
   if(aSign != bSign)
      return (aSign != 0u) && (((((a.x | b.x)<<1)) | a.y | b.y) != 0u);

   return (aSign != 0u) ? lt64(b.x, b.y, a.x, a.y)
      : lt64(a.x, a.y, b.x, b.y);
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

/* Shifts the 64-bit value formed by concatenating `a.x' and `a.y' right by the
 * number of bits given in `count'.  If any nonzero bits are shifted off, they
 * are "jammed" into the least significant bit of the result by setting the
 * least significant bit to 1.  The value of `count' can be arbitrarily large;
 * in particular, if `count' is greater than 64, the result will be either 0
 * or 1, depending on whether the concatenation of `a.x' and `a.y' is zero or
 * nonzero.  The result is broken into two 32-bit pieces which are stored at
 * the locations pointed to by `z0Ptr' and `z1Ptr'.
 */
void
shift64RightJamming(uvec2 a,
                    int count,
                    inout uint z0Ptr,
                    inout uint z1Ptr)
{
   uint z0;
   uint z1;
   int negCount = (-count) & 31;

   if (count == 0) {
      z1 = a.y;
      z0 = a.x;
   } else if (count < 32) {
      z1 = (a.x<<negCount) | (a.y>>count) | uint ((a.y<<negCount) != 0u);
      z0 = a.x>>count;
   } else {
      if (count == 32) {
         z1 = a.x | uint(a.y != 0u);
      } else if (count < 64) {
         z1 = (a.x>>(count & 31)) | uint(((a.x<<negCount) | a.y) != 0u);
      } else {
         z1 = uint((a.x | a.y) != 0u);
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
packFloat64(uint zSign, uint zExp, uint zFrac0, uint zFrac1)
{
   uvec2 z;

   z.x = (zSign<<31) + (zExp<<20) + zFrac0;
   z.y = zFrac1;
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
                    uint zExp,
                    uint zFrac0,
                    uint zFrac1,
                    uint zFrac2)
{
   uint roundNearestEven;
   uint increment;

   roundNearestEven = uint(FLOAT_ROUNDING_MODE == FLOAT_ROUND_NEAREST_EVEN);
   increment = uint(zFrac2 < 0u);
   if (roundNearestEven == 0u) {
      if (FLOAT_ROUNDING_MODE == FLOAT_ROUND_TO_ZERO) {
         increment = 0u;
      } else {
         if (zSign != 0u) {
            increment = uint((FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN) &&
               (zFrac2 != 0u));
         } else {
            increment = uint((FLOAT_ROUNDING_MODE == FLOAT_ROUND_UP) &&
               (zFrac2 != 0u));
         }
      }
   }
   if (0x7FDu <= zExp) {
      if ((0x7FDu < zExp) ||
         ((zExp == 0x7FDu) &&
            eq64(0x001FFFFFu, 0xFFFFFFFFu, zFrac0, zFrac1) &&
               (increment != 0u))) {
         if ((FLOAT_ROUNDING_MODE == FLOAT_ROUND_TO_ZERO) ||
            ((zSign != 0u) && (FLOAT_ROUNDING_MODE == FLOAT_ROUND_UP)) ||
               ((zSign == 0u) && (FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN))) {
            return packFloat64(zSign, 0x7FEu, 0x000FFFFFu, 0xFFFFFFFFu);
         }
         return packFloat64(zSign, 0x7FFu, 0u, 0u);
      }
      if (zExp < 0u) {
         shift64ExtraRightJamming(
            zFrac0, zFrac1, zFrac2, int(-zExp), zFrac0, zFrac1, zFrac2);
         zExp = 0u;
         if (roundNearestEven != 0u) {
            increment = uint(zFrac2 < 0u);
         } else {
            if (zSign != 0u) {
               increment = uint((FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN) &&
                  (zFrac2 != 0u));
            } else {
               increment = uint((FLOAT_ROUNDING_MODE == FLOAT_ROUND_UP) &&
                  (zFrac2 != 0u));
            }
         }
      }
   }
   if (increment != 0u) {
      add64(zFrac0, zFrac1, 0u, 1u, zFrac0, zFrac1);
      zFrac1 &= ~(uint(zFrac2 + zFrac2 == 0u) & roundNearestEven);
   } else {
      if ((zFrac0 | zFrac1) == 0u)
         zExp = 0u;
   }
   return packFloat64(zSign, zExp, zFrac0, zFrac1);
}

/* Returns the number of leading 0 bits before the most-significant 1 bit of
 * `a'.  If `a' is zero, 32 is returned.
 */
uint
countLeadingZeros32(uint a)
{
   if (a == 0u)
      return 32u;

   uint shiftCount = 0u;
   if ((a & 0xFFFF0000u) == 0u) {shiftCount += 16u; a <<= 16;}
   if ((a & 0xFF000000u) == 0u) {shiftCount += 8u; a <<= 8;}
   if ((a & 0xF0000000u) == 0u) {shiftCount += 4u; a <<= 4;}
   if ((a & 0xC0000000u) == 0u) {shiftCount += 2u; a <<= 2;}
   if ((a & 0x80000000u) == 0u) {shiftCount += 1u;}

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
                             uint zExp,
                             uint zFrac0,
                             uint zFrac1)
{
   int shiftCount;
   uint zFrac2;

   if (zFrac0 == 0u) {
      zFrac0 = zFrac1;
      zFrac1 = 0u;
      zExp -= 32u;
   }
   shiftCount = int(countLeadingZeros32(zFrac0)) - 11;
   if (0 <= shiftCount) {
      zFrac2 = 0u;
      shortShift64Left(zFrac0, zFrac1, shiftCount, zFrac0, zFrac1);
   } else {
      shift64ExtraRightJamming(
         zFrac0, zFrac1, 0u, -shiftCount, zFrac0, zFrac1, zFrac2);
   }
   zExp -= uint(shiftCount);
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
   uint zExp;

   uvec2 aFrac = extractFloat64Frac(a);
   uint aExp = extractFloat64Exp(a);
   uvec2 bFrac = extractFloat64Frac(b);
   uint bExp = extractFloat64Exp(b);
   int expDiff = int(aExp) - int(bExp);
   if (0 < expDiff) {
      if (aExp == 0x7FFu) {
         if ((aFrac.x | aFrac.y) != 0u)
            return propagateFloat64NaN(a, b);
         return a;
      }
      if (bExp == 0u)
         --expDiff;
      else
         bFrac.x |= 0x00100000u;
      shift64ExtraRightJamming(
         bFrac.x, bFrac.y, 0u, expDiff, bFrac.x, bFrac.y, zFrac2);
      zExp = aExp;
   } else if (expDiff < 0) {
      if (bExp == 0x7FFu) {
         if ((bFrac.x | bFrac.y) != 0u)
            return propagateFloat64NaN(a, b);
         return packFloat64(zSign, 0x7FFu, 0u, 0u);
      }
      if (aExp == 0u)
         ++expDiff;
      else
         aFrac.x |= 0x00100000u;
      shift64ExtraRightJamming(
         aFrac.x, aFrac.y, 0u, - expDiff, aFrac.x, aFrac.y, zFrac2);
      zExp = bExp;
   } else {
      if (aExp == 0x7FFu) {
         if ((aFrac.x | aFrac.y | bFrac.x | bFrac.y) != 0u)
            return propagateFloat64NaN(a, b);
         return a;
      }
      add64(aFrac.x, aFrac.y, bFrac.x, bFrac.y, zFrac0, zFrac1);
      if (aExp == 0u)
         return packFloat64(zSign, 0u, zFrac0, zFrac1);
      zFrac2 = 0u;
      zFrac0 |= 0x00200000u;
      zExp = aExp;
      shift64ExtraRightJamming(
         zFrac0, zFrac1, zFrac2, 1, zFrac0, zFrac1, zFrac2);
      return roundAndPackFloat64(zSign, zExp, zFrac0, zFrac1, zFrac2);
   }
   aFrac.x |= 0x00100000u;
   add64(aFrac.x, aFrac.y, bFrac.x, bFrac.y, zFrac0, zFrac1);
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
   uint zExp;
   uint zFrac0 = 0u;
   uint zFrac1 = 0u;

   uvec2 aFrac = extractFloat64Frac(a);
   uint aExp = extractFloat64Exp(a);
   uvec2 bFrac = extractFloat64Frac(b);
   uint bExp = extractFloat64Exp(b);
   int expDiff = int(aExp) - int(bExp);
   shortShift64Left(aFrac.x, aFrac.y, 10, aFrac.x, aFrac.y);
   shortShift64Left(bFrac.x, bFrac.y, 10, bFrac.x, bFrac.y);
   if (0 < expDiff) {
      if (aExp == 0x7FFu) {
         if ((aFrac.x | aFrac.y) != 0u) {
            return propagateFloat64NaN(a, b);
         }
         return a;
      }
      if (bExp == 0u)
         --expDiff;
      else
         bFrac.x |= 0x40000000u;
      shift64RightJamming(bFrac, expDiff, bFrac.x, bFrac.y);
      aFrac.x |= 0x40000000u;
      sub64(aFrac.x, aFrac.y, bFrac.x, bFrac.y, zFrac0, zFrac1);
      zExp = aExp;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10u, zFrac0, zFrac1);
   }
   if (expDiff < 0) {
      if (bExp == 0x7FFu) {
         if ((bFrac.x | bFrac.y) != 0u)
            return propagateFloat64NaN(a, b);
         return packFloat64(zSign ^ 1u, 0x7FFu, 0u, 0u);
      }
      if (aExp == 0u)
         ++expDiff;
      else
         aFrac.x |= 0x40000000u;
      shift64RightJamming(aFrac, - expDiff, aFrac.x, aFrac.y);
      bFrac.x |= 0x40000000u;
      sub64(bFrac.x, bFrac.y, aFrac.x, aFrac.y, zFrac0, zFrac1);
      zExp = bExp;
      zSign ^= 1u;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10u, zFrac0, zFrac1);
   }
   if (aExp == 0x7FFu) {
      if ((aFrac.x | aFrac.y | bFrac.x | bFrac.y) != 0u)
         return propagateFloat64NaN(a, b);
      return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
   }
   if (aExp == 0u) {
      aExp = 1u;
      bExp = 1u;
   }
   if (bFrac.x < aFrac.x) {
      sub64(aFrac.x, aFrac.y, bFrac.x, bFrac.y, zFrac0, zFrac1);
      zExp = aExp;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10u, zFrac0, zFrac1);
   }
   if (aFrac.x < bFrac.x) {
      sub64(bFrac.x, bFrac.y, aFrac.x, aFrac.y, zFrac0, zFrac1);
      zExp = bExp;
      zSign ^= 1u;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10u, zFrac0, zFrac1);
   }
   if (bFrac.y < aFrac.y) {
      sub64(aFrac.x, aFrac.y, bFrac.x, bFrac.y, zFrac0, zFrac1);
      zExp = aExp;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10u, zFrac0, zFrac1);
   }
   if (aFrac.y < bFrac.y) {
      sub64(bFrac.x, bFrac.y, aFrac.x, aFrac.y, zFrac0, zFrac1);
      zExp = bExp;
      zSign ^= 1u;
      --zExp;
      return normalizeRoundAndPackFloat64(zSign, zExp - 10u, zFrac0, zFrac1);
   }
   return packFloat64(
      uint(FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN), 0u, 0u, 0u);
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

/* Multiplies `a' by `b' to obtain a 64-bit product.  The product is broken
 * into two 32-bit pieces which are stored at the locations pointed to by
 * `z0Ptr' and `z1Ptr'.
 */
void
mul32To64(uint a, uint b, inout uint z0Ptr, inout uint z1Ptr)
{
   uint aLow = a;
   uint aHigh = a>>16;
   uint bLow = b;
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
                          inout uint zExpPtr,
                          inout uint zFrac0Ptr,
                          inout uint zFrac1Ptr)
{
   int shiftCount;

   if (aFrac0 == 0u) {
      shiftCount = int(countLeadingZeros32(aFrac1)) - 11;
      if (shiftCount < 0) {
         zFrac0Ptr = aFrac1>>(-shiftCount);
         zFrac1Ptr = aFrac1<<(shiftCount & 31);
      } else {
         zFrac0Ptr = aFrac1<<shiftCount;
         zFrac1Ptr = 0u;
      }
      zExpPtr = uint(-shiftCount - 31);
   } else {
      shiftCount = int(countLeadingZeros32(aFrac0)) - 11;
      shortShift64Left(aFrac0, aFrac1, shiftCount, zFrac0Ptr, zFrac1Ptr);
      zExpPtr = 1u - uint(shiftCount);
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
   uint zExp;

   uvec2 aFrac = extractFloat64Frac(a);
   uint aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);
   uvec2 bFrac = extractFloat64Frac(b);
   uint bExp = extractFloat64Exp(b);
   uint bSign = extractFloat64Sign(b);
   uint zSign = aSign ^ bSign;
   if (aExp == 0x7FFu) {
      if (((aFrac.x | aFrac.y) != 0u) ||
         ((bExp == 0x7FFu) && ((bFrac.x | bFrac.y) != 0u))) {
         return propagateFloat64NaN(a, b);
      }
      if ((bExp | bFrac.x | bFrac.y) == 0u)
            return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
      return packFloat64(zSign, 0x7FFu, 0u, 0u);
   }
   if (bExp == 0x7FFu) {
      if ((bFrac.x | bFrac.y) != 0u)
         return propagateFloat64NaN(a, b);
      if ((aExp | aFrac.x | aFrac.y) == 0u)
         return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
      return packFloat64(zSign, 0x7FFu, 0u, 0u);
   }
   if (aExp == 0u) {
      if ((aFrac.x | aFrac.y) == 0u)
         return packFloat64(zSign, 0u, 0u, 0u);
      normalizeFloat64Subnormal(aFrac.x, aFrac.y, aExp, aFrac.x, aFrac.y);
   }
   if (bExp == 0u) {
      if ((bFrac.x | bFrac.y) == 0u)
         return packFloat64(zSign, 0u, 0u, 0u);
      normalizeFloat64Subnormal(bFrac.x, bFrac.y, bExp, bFrac.x, bFrac.y);
   }
   zExp = uint(int(aExp + bExp) - 0x400);
   aFrac.x |= 0x00100000u;
   shortShift64Left(bFrac.x, bFrac.y, 12, bFrac.x, bFrac.y);
   mul64To128(
      aFrac.x, aFrac.y, bFrac.x, bFrac.y, zFrac0, zFrac1, zFrac2, zFrac3);
   add64(zFrac0, zFrac1, aFrac.x, aFrac.y, zFrac0, zFrac1);
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
   while (rem0 < 0u) {
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
   uint zExp;
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
   uint aExp = extractFloat64Exp(a);
   uint aSign = extractFloat64Sign(a);
   uvec2 bFrac = extractFloat64Frac(b);
   uint bExp = extractFloat64Exp(b);
   uint bSign = extractFloat64Sign(b);
   uint zSign = aSign ^ bSign;
   if (aExp == 0x7FFu) {
      if ((aFrac.x | aFrac.y) != 0u)
         return propagateFloat64NaN(a, b);
      if (bExp == 0x7FFu) {
         if ((bFrac.x | bFrac.y) != 0u)
            return propagateFloat64NaN(a, b);
         return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
      }
      return packFloat64(zSign, 0x7FFu, 0u, 0u);
   }
   if (bExp == 0x7FFu) {
      if ((bFrac.x | bFrac.y) != 0u)
         return propagateFloat64NaN(a, b);
      return packFloat64(zSign, 0u, 0u, 0u);
   }
   if (bExp == 0u) {
      if ((bFrac.x | bFrac.y) == 0u) {
         if ((aExp | aFrac.x | aFrac.y) == 0u)
            return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
         return packFloat64(zSign, 0x7FFu, 0u, 0u);
      }
      normalizeFloat64Subnormal(bFrac.x, bFrac.y, bExp, bFrac.x, bFrac.y);
   }
   if (aExp == 0u) {
      if ((aFrac.x | aFrac.y) == 0u)
         return packFloat64(zSign, 0u, 0u, 0u);
      normalizeFloat64Subnormal(aFrac.x, aFrac.y, aExp, aFrac.x, aFrac.y);
   }
   zExp = aExp - bExp + 0x3FDu;
   shortShift64Left(aFrac.x | 0x00100000u, aFrac.y, 11, aFrac.x, aFrac.y);
   shortShift64Left(bFrac.x | 0x00100000u, bFrac.y, 11, bFrac.x, bFrac.y);
   if (le64(bFrac.x, bFrac.y, aFrac.x, aFrac.y)) {
      shift64Right(aFrac.x, aFrac.y, 1, aFrac.x, aFrac.y);
      ++zExp;
   }
   zFrac0 = estimateDiv64To32(aFrac.x, aFrac.y, bFrac.x);
   mul64By32To96(bFrac.x, bFrac.y, zFrac0, term0, term1, term2);
   sub96(aFrac.x, aFrac.y, 0u, term0, term1, term2, rem0, rem1, rem2);
   while (rem0 < 0u) {
      --zFrac0;
      add96(rem0, rem1, rem2, 0u, bFrac.x, bFrac.y, rem0, rem1, rem2);
   }
   zFrac1 = estimateDiv64To32(rem1, rem2, bFrac.x);
   if ((zFrac1 & 0x3FFu) <= 4u) {
      mul64By32To96(bFrac.x, bFrac.y, zFrac1, term1, term2, term3);
      sub96(rem1, rem2, 0u, term1, term2, term3, rem1, rem2, rem3);
      while (rem1 < 0u) {
         --zFrac1;
         add96(rem1, rem2, rem3, 0u, bFrac.x, bFrac.y, rem1, rem2, rem3);
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
                          inout uint zExpPtr,
                          inout uint zFracPtr)
{
   uint shiftCount = countLeadingZeros32(aFrac) - 8u;
   zFracPtr = aFrac<<shiftCount;
   zExpPtr = 1u - shiftCount;
}

/* Returns the fraction bits of the single-precision floating-point value `a'.*/
uint
extractFloat32Frac(uint a)
{
   return a & 0x007FFFFFu;
}

/* Returns the exponent bits of the single-precision floating-point value `a'.*/
uint
extractFloat32Exp(uint a)
{
   return (a>>23) & 0xFFu;
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
fp32_to_fp64(uint a)
{
   uint aFrac = extractFloat32Frac(a);
   uint aExp = extractFloat32Exp(a);
   uint aSign = extractFloat32Sign(a);

   if (aExp == 0xFFu) {
      if (aFrac != 0u)
         return uvec2(((aSign<<31) | 0x7FF00000u | (aFrac>>3)), (aFrac<<29));
      return packFloat64(aSign, 0x7FFu, 0u, 0u);
    }

   if (aExp == 0u) {
      if (aFrac != 0u) {
         normalizeFloat32Subnormal(aFrac, aExp, aFrac);
         --aExp;
      }
      return packFloat64(aSign, 0u, 0u, 0u);
   }

   return packFloat64(aSign, aExp + 0x380u, aFrac>>3, aFrac<<29);
}
