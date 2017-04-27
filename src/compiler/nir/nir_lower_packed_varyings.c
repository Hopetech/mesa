/*
 * Copyright © 2016 Intel Corporation
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
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/**
 * \file nir_lower_packed_varyings.cpp
 *
 * This lowering pass generates GLSL code that manually packs varyings into
 * vec4 slots, for the benefit of back-ends that don't support packed varyings
 * natively.
 *
 * For example, the following shader:
 *
 *   out mat3x2 foo;  // location=4, location_frac=0
 *   out vec3 bar[2]; // location=5, location_frac=2
 *
 *   main()
 *   {
 *     ...
 *   }
 *
 * Is rewritten to:
 *
 *   mat3x2 foo;
 *   vec3 bar[2];
 *   out vec4 packed4; // location=4, location_frac=0
 *   out vec4 packed5; // location=5, location_frac=0
 *   out vec4 packed6; // location=6, location_frac=0
 *
 *   main()
 *   {
 *     ...
 *     packed4.xy = foo[0];
 *     packed4.zw = foo[1];
 *     packed5.xy = foo[2];
 *     packed5.zw = bar[0].xy;
 *     packed6.x = bar[0].z;
 *     packed6.yzw = bar[1];
 *   }
 *
 * This lowering pass properly handles "double parking" of a varying vector
 * across two varying slots.  For example, in the code above, two of the
 * components of bar[0] are stored in packed5, and the remaining component is
 * stored in packed6.
 *
 * Note that in theory, the extra instructions may cause some loss of
 * performance.  However, hopefully in most cases the performance loss will
 * either be absorbed by a later optimization pass, or it will be offset by
 * memory bandwidth savings (because fewer varyings are used).
 *
 * This lowering pass also packs flat floats, ints, and uints together, by
 * using ivec4 as the base type of flat "varyings", and using appropriate
 * casts to convert floats and uints into ints.
 *
 * This lowering pass also handles varyings whose type is a struct or an array
 * of struct.  Structs are packed in order and with no gaps, so there may be a
 * performance penalty due to structure elements being double-parked.
 *
 * Lowering of geometry shader inputs is slightly more complex, since geometry
 * inputs are always arrays, so we need to lower arrays to arrays.  For
 * example, the following input:
 *
 *   in struct Foo {
 *     float f;
 *     vec3 v;
 *     vec2 a[2];
 *   } arr[3];         // location=4, location_frac=0
 *
 * Would get lowered like this if it occurred in a fragment shader:
 *
 *   struct Foo {
 *     float f;
 *     vec3 v;
 *     vec2 a[2];
 *   } arr[3];
 *   in vec4 packed4;  // location=4, location_frac=0
 *   in vec4 packed5;  // location=5, location_frac=0
 *   in vec4 packed6;  // location=6, location_frac=0
 *   in vec4 packed7;  // location=7, location_frac=0
 *   in vec4 packed8;  // location=8, location_frac=0
 *   in vec4 packed9;  // location=9, location_frac=0
 *
 *   main()
 *   {
 *     arr[0].f = packed4.x;
 *     arr[0].v = packed4.yzw;
 *     arr[0].a[0] = packed5.xy;
 *     arr[0].a[1] = packed5.zw;
 *     arr[1].f = packed6.x;
 *     arr[1].v = packed6.yzw;
 *     arr[1].a[0] = packed7.xy;
 *     arr[1].a[1] = packed7.zw;
 *     arr[2].f = packed8.x;
 *     arr[2].v = packed8.yzw;
 *     arr[2].a[0] = packed9.xy;
 *     arr[2].a[1] = packed9.zw;
 *     ...
 *   }
 *
 * But it would get lowered like this if it occurred in a geometry shader:
 *
 *   struct Foo {
 *     float f;
 *     vec3 v;
 *     vec2 a[2];
 *   } arr[3];
 *   in vec4 packed4[3];  // location=4, location_frac=0
 *   in vec4 packed5[3];  // location=5, location_frac=0
 *
 *   main()
 *   {
 *     arr[0].f = packed4[0].x;
 *     arr[0].v = packed4[0].yzw;
 *     arr[0].a[0] = packed5[0].xy;
 *     arr[0].a[1] = packed5[0].zw;
 *     arr[1].f = packed4[1].x;
 *     arr[1].v = packed4[1].yzw;
 *     arr[1].a[0] = packed5[1].xy;
 *     arr[1].a[1] = packed5[1].zw;
 *     arr[2].f = packed4[2].x;
 *     arr[2].v = packed4[2].yzw;
 *     arr[2].a[0] = packed5[2].xy;
 *     arr[2].a[1] = packed5[2].zw;
 *     ...
 *   }
 */

#include "nir.h"
#include "nir_builder.h"

struct lower_packed_varyings_state {
   nir_shader *shader;
   struct exec_list new_ins;
   struct exec_list new_outs;
   bool disable_varying_packing;
   bool xfb_enabled;
};

//#define SWIZZLE_ZWZW MAKE_SWIZZLE4(SWIZZLE_Z, SWIZZLE_W, SWIZZLE_Z, SWIZZLE_W)

static nir_variable *
get_new_var(struct lower_packed_varyings_state *state, nir_variable *var,
            const struct glsl_type *deref_type, unsigned off)
{
   struct exec_list *list;

   if (var->data.mode == nir_var_shader_in) {
      list = &state->new_ins;
   } else {
      assert(var->data.mode == nir_var_shader_out);
      list = &state->new_outs;
   }

   nir_foreach_variable(nvar, list) {
      if (nvar->data.location == (var->data.location + off))
         return nvar;
   }

   nir_variable *nvar;
   if (state->shader->stage == MESA_SHADER_GEOMETRY) {
      /* Geometry inputs are always arrays, so we need to lower arrays of arrays */
      const struct glsl_type *ntype =
         glsl_vector_type(GLSL_TYPE_ARRAY,
                           glsl_get_vector_elements(deref_type));
      nvar = nir_variable_create(state->shader, var->data.mode, ntype, NULL);
   } else {
      const struct glsl_type *ntype =
         glsl_vector_type(glsl_get_base_type(deref_type),
                           glsl_get_vector_elements(deref_type));
      nvar = nir_variable_create(state->shader, var->data.mode, ntype, NULL);
   }

   nvar->name = ralloc_asprintf(nvar, "%s@%u", var->name, off);
   nvar->data = var->data;
   nvar->data.location += off;

   /* nir_variable_create is too clever for its own good: */
   exec_node_remove(&nvar->node);
   exec_node_self_link(&nvar->node);      /* no delinit() :-( */

   exec_list_push_tail(list, &nvar->node);

   /* remove existing var from input/output list: */
   exec_node_remove(&var->node);
   exec_node_self_link(&var->node);

   return nvar;
}

static unsigned
get_deref_offset(struct lower_packed_varyings_state *state, nir_deref *tail, bool vs_in)
{
   unsigned offset = 0;

   while (tail->child != NULL) {
      const struct glsl_type *parent_type = tail->type;
      tail = tail->child;

      if (tail->deref_type == nir_deref_type_array) {
         nir_deref_array *deref_array = nir_deref_as_array(tail);

         /* indirect inputs/outputs should already be lowered! */
         assert(deref_array->deref_array_type == nir_deref_array_type_direct);

         unsigned size = glsl_count_attribute_slots(tail->type, vs_in);

         offset += size * deref_array->base_offset;
      } else if (tail->deref_type == nir_deref_type_struct) {
         nir_deref_struct *deref_struct = nir_deref_as_struct(tail);

         for (unsigned i = 0; i < deref_struct->index; i++) {
            const struct glsl_type *ft = glsl_get_struct_field(parent_type, i);
            offset += glsl_count_attribute_slots(ft, vs_in);
         }
      }
   }

   return offset;
}

static bool
needs_lowering(nir_variable *var, struct lower_packed_varyings_state *state)
{
   /* Things composed of vec4's and varyings with explicitly assigned
    * locations don't need lowering.  Everything else does.
    */
   if (var->data.explicit_location)
      return false;

   /* Override disable_varying_packing if the var is only used by transform
    * feedback. Also override it if transform feedback is enabled and the
    * variable is an array, struct or matrix as the elements of these types
    * will always has the same interpolation and therefore asre safe to pack.
    */
   const struct glsl_type *type = var->type;
   if (state->disable_varying_packing && !var->data.is_xfb_only &&
       !((glsl_type_is_array(type) || glsl_type_is_struct(type) ||
          glsl_type_is_matrix(type)) &&
         state->xfb_enabled))
      return false;

   type = glsl_without_array(type);
   if (glsl_get_vector_elements(type) == 4 && !glsl_type_is_64bit(type))
      return false;
   return true;
}

static bool
nir_lower_packed_varyings_block(struct lower_packed_varyings_state *state,
                                nir_block *block)
{
   bool progress = false;

   nir_foreach_instr(instr, block) {
      if (instr->type != nir_instr_type_intrinsic)
         continue;

      nir_intrinsic_instr *intr = nir_instr_as_intrinsic(instr);

      if ((intr->intrinsic != nir_intrinsic_load_var) &&
          (intr->intrinsic != nir_intrinsic_store_var))
         continue;

      nir_variable *var = intr->variables[0]->var;
      if (var == NULL)
         continue;

      if ((var->data.mode != nir_var_shader_in) &&
          (var->data.mode != nir_var_shader_out))
         continue;

      if (var->data.location < VARYING_SLOT_VAR0 ||
          !needs_lowering(var, state))
         continue;

      /* This lowering pass is only capable of packing floats and ints
       * together when their interpolation mode is "flat".  Treat integers as
       * being flat when the interpolation mode is none.
       */
      assert(var->data.interpolation = INTERP_MODE_FLAT ||
             var->data.interpolation = INTERP_MODE_NONE ||
             !var->type->contains_integer());

      bool vs_in = (state->shader->stage == MESA_SHADER_VERTEX) &&
                   (var->data.mode == nir_var_shader_in);
      if (glsl_count_attribute_slots(var->type, vs_in) == 1)
         continue;

      /* Transform the old varying into an ordinary global */
      //var->data.mode = nir_var_global;

      unsigned off = get_deref_offset(state, &intr->variables[0]->deref, vs_in);
      const struct glsl_type *deref_type =
         nir_deref_tail(&intr->variables[0]->deref)->type;
      nir_variable *nvar = get_new_var(state, var, deref_type, off);

      /* and then re-write the load/store_var deref: */
      intr->variables[0] = nir_deref_var_create(intr, nvar);

      progress = true;
   }

   return progress;
}

static bool
nir_lower_packed_varyings_impl(nir_function_impl *impl,
                               struct lower_packed_varyings_state *state)
{
   bool progress = false;

   nir_foreach_block(block, impl) {
      progress |= nir_lower_packed_varyings_block(state, block);
   }

   nir_metadata_preserve(impl, nir_metadata_block_index |
                               nir_metadata_dominance);
   return progress;
}

bool
nir_lower_packed_varyings(nir_shader *shader, bool xfb_enabled)
{
   //nir_print_shader(shader, stderr);
   printf("%s\n", __func__);
   bool progress = false;
   struct lower_packed_varyings_state state;

   state.shader = shader;
   state.xfb_enabled = xfb_enabled;
   exec_list_make_empty(&state.new_ins);
   exec_list_make_empty(&state.new_outs);

   nir_foreach_function(function, shader) {

      if (strcmp(function->name, "main"))
         nir_function *main_func = function;

      if (function->impl)
         progress |= nir_lower_packed_varyings_impl(function->impl, &state);
   }

//   if (mode == ir_var_shader_out) {
//      if (state.shader->state == MESA_SHADER_GEOMETRY) {
         /* For geometry shaders, outputs need to be lowered before each call
          * to EmitVertex()
          */

         /* Add all the variables in first */

         /* Now update all the EmitVertex instances */
//      } else {
         /* For other shader types, outputs need to be lowered before each
          * return statement and at the end of main()
          */

         /* Lower outputs at the end of main() if the last instructions is not
          * a return statement
          */

//      }

//   } else {
      /* move new in/out vars to shader's lists: */
      exec_list_append(&shader->inputs, &state.new_ins);
      exec_list_append(&shader->outputs, &state.new_outs);
//   }

   //nir_print_shader(shader, stderr);
   return progress;
}
