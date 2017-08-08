ir_function_signature *
fabs64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r000B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r000B);
   body.emit(assign(r000B, bit_and(swizzle_y(r000B), body.constant(2147483647u)), 0x02));

   body.emit(ret(r000B));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
is_nan(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::bool_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r000C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r000C);
   ir_expression *const r000D = lshift(swizzle_y(r000C), body.constant(int(1)));
   ir_expression *const r000E = lequal(body.constant(4292870144u), r000D);
   ir_expression *const r000F = nequal(swizzle_x(r000C), body.constant(0u));
   ir_expression *const r0010 = bit_and(swizzle_y(r000C), body.constant(1048575u));
   ir_expression *const r0011 = nequal(r0010, body.constant(0u));
   ir_expression *const r0012 = logic_or(r000F, r0011);
   ir_expression *const r0013 = logic_and(r000E, r0012);
   body.emit(ret(r0013));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fneg64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0014 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0014);
   ir_variable *const r0015 = body.make_temp(glsl_type::uvec2_type, "return_value");
   /* IF CONDITION */
   ir_expression *const r0017 = lshift(swizzle_y(r0014), body.constant(int(1)));
   ir_expression *const r0018 = lequal(body.constant(4292870144u), r0017);
   ir_expression *const r0019 = nequal(swizzle_x(r0014), body.constant(0u));
   ir_expression *const r001A = bit_and(swizzle_y(r0014), body.constant(1048575u));
   ir_expression *const r001B = nequal(r001A, body.constant(0u));
   ir_expression *const r001C = logic_or(r0019, r001B);
   ir_expression *const r001D = logic_and(r0018, r001C);
   ir_if *f0016 = new(mem_ctx) ir_if(operand(r001D).val);
   exec_list *const f0016_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0016->then_instructions;

      body.emit(assign(r0015, r0014, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0016->else_instructions;

      body.emit(assign(r0014, bit_xor(swizzle_y(r0014), body.constant(2147483648u)), 0x02));

      body.emit(assign(r0015, r0014, 0x03));


   body.instructions = f0016_parent_instructions;
   body.emit(f0016);

   /* END IF */

   body.emit(ret(r0015));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
