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

uvec2
fsign64(uvec2 a)
{
   if ((a.y << 1 | a.x) == 0u)
      return uvec2(0u, 0u);

   uvec2 retval;
   retval.x = 0u;
   retval.y = (a.y & 0x80000000u) | 0x3FF00000u;
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
      return (aSign != 0u) || ((((a.y | b.y)<<1) | a.x | b.x) == 0u);

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
void
shortShift64Left(uint a0, uint a1,
                 int count,
                 inout uint z0Ptr, inout uint z1Ptr)
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
 * is a NaN, and returns the appropriate NaN result.
 */
uvec2
propagateFloat64NaN(uvec2 a, uvec2 b)
{
   bool aIsNaN = is_nan(a);
   bool bIsNaN = is_nan(b);
   a.y |= 0x00080000u;
   b.y |= 0x00080000u;
   if (aIsNaN)
      return (bIsNaN) ? b : a;
   else
      return b;
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

   if (aSign == bSign) {
      uint zFrac0 = 0u;
      uint zFrac1 = 0u;
      uint zFrac2 = 0u;
      int zExp;

      uint aFracLo = extractFloat64FracLo(a);
      uint aFracHi = extractFloat64FracHi(a);
      uint bFracLo = extractFloat64FracLo(b);
      uint bFracHi = extractFloat64FracHi(b);
      int aExp = extractFloat64Exp(a);
      int bExp = extractFloat64Exp(b);
      int expDiff = aExp - bExp;
      if (0 < expDiff) {
         if (aExp == 0x7FF) {
            if ((aFracHi | aFracLo) != 0u)
               return propagateFloat64NaN(a, b);
            return a;
         }
         if (bExp == 0)
            --expDiff;
         else
            bFracHi |= 0x00100000u;
         shift64ExtraRightJamming(
            bFracHi, bFracLo, 0u, expDiff, bFracHi, bFracLo, zFrac2);
         zExp = aExp;
      } else if (expDiff < 0) {
         if (bExp == 0x7FF) {
            if ((bFracHi | bFracLo) != 0u)
               return propagateFloat64NaN(a, b);
            return packFloat64(aSign, 0x7FF, 0u, 0u);
         }
         if (aExp == 0)
            ++expDiff;
         else
            aFracHi |= 0x00100000u;
         shift64ExtraRightJamming(
            aFracHi, aFracLo, 0u, - expDiff, aFracHi, aFracLo, zFrac2);
         zExp = bExp;
      } else {
         if (aExp == 0x7FF) {
            if ((aFracHi | aFracLo | bFracHi | bFracLo) != 0u)
               return propagateFloat64NaN(a, b);
            return a;
         }
         add64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
         if (aExp == 0)
            return packFloat64(aSign, 0, zFrac0, zFrac1);
         zFrac2 = 0u;
         zFrac0 |= 0x00200000u;
         zExp = aExp;
         shift64ExtraRightJamming(
            zFrac0, zFrac1, zFrac2, 1, zFrac0, zFrac1, zFrac2);
         return roundAndPackFloat64(aSign, zExp, zFrac0, zFrac1, zFrac2);
      }
      aFracHi |= 0x00100000u;
      add64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
      --zExp;
      if (zFrac0 < 0x00200000u)
         return roundAndPackFloat64(aSign, zExp, zFrac0, zFrac1, zFrac2);
      ++zExp;
      shift64ExtraRightJamming(zFrac0, zFrac1, zFrac2, 1, zFrac0, zFrac1, zFrac2);
      return roundAndPackFloat64(aSign, zExp, zFrac0, zFrac1, zFrac2);

   } else {
      uvec2 z;
      int zExp;
      uint zFrac0 = 0u;
      uint zFrac1 = 0u;

      uint aFracLo = extractFloat64FracLo(a);
      uint aFracHi = extractFloat64FracHi(a);
      uint bFracLo = extractFloat64FracLo(b);
      uint bFracHi = extractFloat64FracHi(b);
      int aExp = extractFloat64Exp(a);
      int bExp = extractFloat64Exp(b);
      int expDiff = aExp - bExp;
      shortShift64Left(aFracHi, aFracLo, 10, aFracHi, aFracLo);
      shortShift64Left(bFracHi, bFracLo, 10, bFracHi, bFracLo);
      if (0 < expDiff) {
         if (aExp == 0x7FF) {
            if ((aFracHi | aFracLo) != 0u) {
               return propagateFloat64NaN(a, b);
            }
            return a;
         }
         if (bExp == 0)
            --expDiff;
         else
            bFracHi |= 0x40000000u;
         shift64RightJamming(bFracHi, bFracLo, expDiff, bFracHi, bFracLo);
         aFracHi |= 0x40000000u;
         sub64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
         zExp = aExp;
         --zExp;
         return normalizeRoundAndPackFloat64(aSign, zExp - 10, zFrac0, zFrac1);
      }
      if (expDiff < 0) {
         if (bExp == 0x7FF) {
            if ((bFracHi | bFracLo) != 0u)
               return propagateFloat64NaN(a, b);
            return packFloat64(aSign ^ 1u, 0x7FF, 0u, 0u);
         }
         if (aExp == 0)
            ++expDiff;
         else
            aFracHi |= 0x40000000u;
         shift64RightJamming(aFracHi, aFracLo, - expDiff, aFracHi, aFracLo);
         bFracHi |= 0x40000000u;
         sub64(bFracHi, bFracLo, aFracHi, aFracLo, zFrac0, zFrac1);
         zExp = bExp;
         aSign ^= 1u;
         --zExp;
         return normalizeRoundAndPackFloat64(aSign, zExp - 10, zFrac0, zFrac1);
      }
      if (aExp == 0x7FF) {
         if ((aFracHi | aFracLo | bFracHi | bFracLo) != 0u)
            return propagateFloat64NaN(a, b);
         return uvec2(0xFFFFFFFFu, 0xFFFFFFFFu);
      }
      if (aExp == 0) {
         aExp = 1;
         bExp = 1;
      }
      if (bFracHi < aFracHi) {
         sub64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
         zExp = aExp;
         --zExp;
         return normalizeRoundAndPackFloat64(aSign, zExp - 10, zFrac0, zFrac1);
      }
      if (aFracHi < bFracHi) {
         sub64(bFracHi, bFracLo, aFracHi, aFracLo, zFrac0, zFrac1);
         zExp = bExp;
         aSign ^= 1u;
         --zExp;
         return normalizeRoundAndPackFloat64(aSign, zExp - 10, zFrac0, zFrac1);
      }
      if (bFracLo < aFracLo) {
         sub64(aFracHi, aFracLo, bFracHi, bFracLo, zFrac0, zFrac1);
         zExp = aExp;
         --zExp;
         return normalizeRoundAndPackFloat64(aSign, zExp - 10, zFrac0, zFrac1);
      }
      if (aFracLo < bFracLo) {
         sub64(bFracHi, bFracLo, aFracHi, aFracLo, zFrac0, zFrac1);
         zExp = bExp;
         aSign ^= 1u;
         --zExp;
         return normalizeRoundAndPackFloat64(aSign, zExp - 10, zFrac0, zFrac1);
      }
      return packFloat64(
         uint(FLOAT_ROUNDING_MODE == FLOAT_ROUND_DOWN), 0, 0u, 0u);
   }
}
