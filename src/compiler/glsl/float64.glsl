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
