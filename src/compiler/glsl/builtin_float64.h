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
ir_function_signature *
extractFloat64Frac(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r001E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r001E);
   ir_variable *const r001F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r001F);
   body.emit(assign(r001F, bit_and(swizzle_y(r001E), body.constant(1048575u)), 0x02));

   body.emit(assign(r001F, swizzle_x(r001E), 0x01));

   body.emit(ret(r001F));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
extractFloat64Exp(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::int_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0020 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0020);
   ir_expression *const r0021 = rshift(swizzle_y(r0020), body.constant(int(20)));
   ir_expression *const r0022 = bit_and(r0021, body.constant(2047u));
   ir_expression *const r0023 = expr(ir_unop_u2i, r0022);
   body.emit(ret(r0023));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
feq64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::bool_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0024 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0024);
   ir_variable *const r0025 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0025);
   ir_variable *const r0026 = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r0027 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r0027);
   ir_variable *const r0028 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0028);
   ir_variable *const r0029 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r0029);
   body.emit(assign(r0029, bit_and(swizzle_y(r0024), body.constant(1048575u)), 0x02));

   body.emit(assign(r0029, swizzle_x(r0024), 0x01));

   ir_variable *const r002A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r002A);
   body.emit(assign(r002A, bit_and(swizzle_y(r0025), body.constant(1048575u)), 0x02));

   body.emit(assign(r002A, swizzle_x(r0025), 0x01));

   ir_expression *const r002B = rshift(swizzle_y(r0024), body.constant(int(20)));
   ir_expression *const r002C = bit_and(r002B, body.constant(2047u));
   ir_expression *const r002D = expr(ir_unop_u2i, r002C);
   ir_expression *const r002E = equal(r002D, body.constant(int(2047)));
   ir_expression *const r002F = bit_or(swizzle_y(r0029), swizzle_x(r0024));
   ir_expression *const r0030 = nequal(r002F, body.constant(0u));
   body.emit(assign(r0028, logic_and(r002E, r0030), 0x01));

   ir_expression *const r0031 = rshift(swizzle_y(r0025), body.constant(int(20)));
   ir_expression *const r0032 = bit_and(r0031, body.constant(2047u));
   ir_expression *const r0033 = expr(ir_unop_u2i, r0032);
   ir_expression *const r0034 = equal(r0033, body.constant(int(2047)));
   ir_expression *const r0035 = bit_or(swizzle_y(r002A), swizzle_x(r0025));
   ir_expression *const r0036 = nequal(r0035, body.constant(0u));
   body.emit(assign(r0027, logic_and(r0034, r0036), 0x01));

   /* IF CONDITION */
   ir_expression *const r0038 = logic_or(r0028, r0027);
   ir_if *f0037 = new(mem_ctx) ir_if(operand(r0038).val);
   exec_list *const f0037_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0037->then_instructions;

      body.emit(assign(r0026, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0037->else_instructions;

      ir_expression *const r0039 = equal(swizzle_x(r0024), swizzle_x(r0025));
      ir_expression *const r003A = equal(swizzle_y(r0024), swizzle_y(r0025));
      ir_expression *const r003B = equal(swizzle_x(r0024), body.constant(0u));
      ir_expression *const r003C = bit_or(swizzle_y(r0024), swizzle_y(r0025));
      ir_expression *const r003D = lshift(r003C, body.constant(int(1)));
      ir_expression *const r003E = equal(r003D, body.constant(0u));
      ir_expression *const r003F = logic_and(r003B, r003E);
      ir_expression *const r0040 = logic_or(r003A, r003F);
      body.emit(assign(r0026, logic_and(r0039, r0040), 0x01));


   body.instructions = f0037_parent_instructions;
   body.emit(f0037);

   /* END IF */

   body.emit(ret(r0026));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
