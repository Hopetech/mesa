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
