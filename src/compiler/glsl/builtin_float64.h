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
   body.emit(assign(r000B, bit_and(swizzle_x(r000B), body.constant(2147483647u)), 0x01));

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

      body.emit(assign(r0014, bit_xor(swizzle_x(r0014), body.constant(2147483648u)), 0x01));

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
   ir_variable *const r001F = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r001F, bit_and(swizzle_x(r001E), body.constant(1048575u)), 0x01));

   body.emit(assign(r001F, swizzle_y(r001E), 0x02));

   body.emit(ret(r001F));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
extractFloat64Exp(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uint_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0020 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0020);
   ir_expression *const r0021 = rshift(swizzle_x(r0020), body.constant(int(20)));
   ir_expression *const r0022 = bit_and(r0021, body.constant(2047u));
   body.emit(ret(r0022));

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

   ir_variable *const r0023 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0023);
   ir_variable *const r0024 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0024);
   ir_variable *const r0025 = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r0026 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r0026);
   ir_variable *const r0027 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0027);
   ir_variable *const r0028 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r0028, bit_and(swizzle_x(r0023), body.constant(1048575u)), 0x01));

   body.emit(assign(r0028, swizzle_y(r0023), 0x02));

   ir_variable *const r0029 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r0029, bit_and(swizzle_x(r0024), body.constant(1048575u)), 0x01));

   body.emit(assign(r0029, swizzle_y(r0024), 0x02));

   ir_expression *const r002A = rshift(swizzle_x(r0023), body.constant(int(20)));
   ir_expression *const r002B = bit_and(r002A, body.constant(2047u));
   ir_expression *const r002C = equal(r002B, body.constant(2047u));
   ir_expression *const r002D = bit_or(swizzle_x(r0028), swizzle_y(r0023));
   ir_expression *const r002E = nequal(r002D, body.constant(0u));
   body.emit(assign(r0027, logic_and(r002C, r002E), 0x01));

   ir_expression *const r002F = rshift(swizzle_x(r0024), body.constant(int(20)));
   ir_expression *const r0030 = bit_and(r002F, body.constant(2047u));
   ir_expression *const r0031 = equal(r0030, body.constant(2047u));
   ir_expression *const r0032 = bit_or(swizzle_x(r0029), swizzle_y(r0024));
   ir_expression *const r0033 = nequal(r0032, body.constant(0u));
   body.emit(assign(r0026, logic_and(r0031, r0033), 0x01));

   /* IF CONDITION */
   ir_expression *const r0035 = logic_or(r0027, r0026);
   ir_if *f0034 = new(mem_ctx) ir_if(operand(r0035).val);
   exec_list *const f0034_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0034->then_instructions;

      body.emit(assign(r0025, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0034->else_instructions;

      ir_expression *const r0036 = equal(swizzle_y(r0023), swizzle_y(r0024));
      ir_expression *const r0037 = equal(swizzle_x(r0023), swizzle_x(r0024));
      ir_expression *const r0038 = equal(swizzle_y(r0023), body.constant(0u));
      ir_expression *const r0039 = bit_or(swizzle_x(r0023), swizzle_x(r0024));
      ir_expression *const r003A = lshift(r0039, body.constant(int(1)));
      ir_expression *const r003B = equal(r003A, body.constant(0u));
      ir_expression *const r003C = logic_and(r0038, r003B);
      ir_expression *const r003D = logic_or(r0037, r003C);
      body.emit(assign(r0025, logic_and(r0036, r003D), 0x01));


   body.instructions = f0034_parent_instructions;
   body.emit(f0034);

   /* END IF */

   body.emit(ret(r0025));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
