/*
 * Copyright © 2012 Vincent Lejeune
 * Copyright © 2012 Intel Corporation
 * Copyright © 2018 Collabora, Ltd.
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

#include "ir.h"
#include "util/hash_table.h"

/**
 * \file lower_inout.cpp
 *
 * This pass split the inout declaration into input and output declaration.
 * It also replace variables in the main() function to relate the previous
 * modification of the shader inputs and outputs.
 */

namespace {

class lower_inout_to_in_out : public ir_hierarchical_visitor {
protected:
   /**
    * A hash table mapping from the original ir_variable shader outputs
    * (ir_var_shader_out mode) to the new temporaries to be used instead.
    */
   hash_table *replacements;

   unsigned stage;
public:
   lower_inout_to_in_out(unsigned stage);
   ~lower_inout_to_in_out();
   virtual ir_visitor_status visit(class ir_dereference_variable *);
   virtual ir_visitor_status visit_leave(class ir_function_signature *);
};

} /* anonymous namespace */

/**
 * Hash function for the output variables - computes the hash of the name.
 * NOTE: We're using the name string to ensure that the hash doesn't depend
 * on any random factors, otherwise the lower_inout_to_in_out could produce
 * the random order of the assignments.
 *
 * NOTE: If you want to reuse this function please take into account that
 * generally the names of the variables are non-unique.
 */
static unsigned
hash_table_var_hash(const void *key)
{
   const ir_variable * var = static_cast<const ir_variable *>(key);
   return _mesa_key_hash_string(var->name);
}

lower_inout_to_in_out::lower_inout_to_in_out(unsigned stage)
{
   this->stage = stage;
   replacements = _mesa_hash_table_create(NULL, hash_table_var_hash,
                                          _mesa_key_pointer_equal);
}

lower_inout_to_in_out::~lower_inout_to_in_out()
{
   _mesa_hash_table_destroy(replacements, NULL);
}

/**
 * Split the inout declaration in 2 pieces:
 * One input declaration and one output.
 */
ir_visitor_status
lower_inout_to_in_out::visit(ir_dereference_variable *ir)
{
   if (ir->var->data.mode != ir_var_shader_out &&
       !ir->var->data.fb_fetch_output)
      return visit_continue;

   hash_entry *entry = _mesa_hash_table_search(replacements, ir->var);
   ir_variable *new_input = entry ? (ir_variable *) entry->data : NULL;
   ir_variable *new_temp = entry ? (ir_variable *) entry->data : NULL;

   if (new_input == NULL && new_temp == NULL) {
      void *var_ctx = ralloc_parent(ir->var);

      /* Create a new input based on the inout */
      new_input = new(var_ctx) ir_variable(ir->var->type, "shader_in",
                                           ir_var_shader_in);
      new_input->data.location = ir->var->data.location;
      new_input->data.memory_coherent = ir->var->data.memory_coherent;
      new_input->data.fb_fetch_output = false;
      _mesa_hash_table_insert(replacements, ir->var, new_input);
      ir->var->insert_before(new_input);

      /* The shader output doesn't need to be tag as fb fetch output anymore*/
      ir->var->data.fb_fetch_output = false;

      /* Create a temporary */
      new_temp = new(var_ctx) ir_variable(ir->var->type, "shader_temp",
                                          ir_var_temporary);
      _mesa_hash_table_insert(replacements, ir->var, new_temp);
      ir->var->insert_after(new_temp);
   }

   /* Update the dereference to use the temporary */
   ir->var = new_temp;

   return visit_continue;
}

static ir_assignment *
copy(void *ctx, ir_variable *from, ir_variable *to)
{
   ir_dereference_variable *lhs;
   ir_dereference_variable *rhs;
   lhs = new(ctx) ir_dereference_variable(to);
   rhs = new(ctx) ir_dereference_variable(from);
   return new(ctx) ir_assignment(lhs, rhs);
}

/** Insert a copy-back assignment at the beginning of the main() function */
static void
emit_main_copy(const void *key, void *data, void *closure)
{
   ir_function_signature *sig = (ir_function_signature *) closure;
   sig->body.push_tail(copy(sig, (ir_variable *) data, (ir_variable *) key));
}

ir_visitor_status
lower_inout_to_in_out::visit_leave(ir_function_signature *sig)
{
   if (strcmp(sig->function_name(), "main") != 0)
      return visit_continue;

   hash_table_call_foreach(replacements, emit_main_copy, sig);
   return visit_continue;
}

void
lower_inout(unsigned stage, exec_list *instructions)
{
   /** We are using that lowering pass for framebuffer fetch.
    *  So only lower inout variable to in and out one in the fragment shader.
    */
   if (stage != MESA_SHADER_FRAGMENT)
      return;

   lower_inout_to_in_out v(stage);
   visit_list_elements(&v, instructions);
}
