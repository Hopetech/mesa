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
fsign64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r001E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r001E);
   ir_variable *const r001F = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0020 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "retval", ir_var_auto);
   body.emit(r0020);
   /* IF CONDITION */
   ir_expression *const r0022 = lshift(swizzle_y(r001E), body.constant(int(1)));
   ir_expression *const r0023 = bit_or(r0022, swizzle_x(r001E));
   ir_expression *const r0024 = equal(r0023, body.constant(0u));
   ir_if *f0021 = new(mem_ctx) ir_if(operand(r0024).val);
   exec_list *const f0021_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0021->then_instructions;

      body.emit(assign(r001F, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0021->else_instructions;

      body.emit(assign(r0020, body.constant(0u), 0x01));

      ir_expression *const r0025 = bit_and(swizzle_y(r001E), body.constant(2147483648u));
      body.emit(assign(r0020, bit_or(r0025, body.constant(1072693248u)), 0x02));

      body.emit(assign(r001F, r0020, 0x03));


   body.instructions = f0021_parent_instructions;
   body.emit(f0021);

   /* END IF */

   body.emit(ret(r001F));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
extractFloat64FracLo(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uint_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0026 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0026);
   ir_swizzle *const r0027 = swizzle_x(r0026);
   body.emit(ret(r0027));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
extractFloat64FracHi(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uint_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0028 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0028);
   ir_expression *const r0029 = bit_and(swizzle_y(r0028), body.constant(1048575u));
   body.emit(ret(r0029));

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

   ir_variable *const r002A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r002A);
   ir_expression *const r002B = rshift(swizzle_y(r002A), body.constant(int(20)));
   ir_expression *const r002C = bit_and(r002B, body.constant(2047u));
   ir_expression *const r002D = expr(ir_unop_u2i, r002C);
   body.emit(ret(r002D));

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

   ir_variable *const r002E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r002E);
   ir_variable *const r002F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r002F);
   ir_variable *const r0030 = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r0031 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r0031);
   ir_variable *const r0032 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0032);
   ir_expression *const r0033 = rshift(swizzle_y(r002E), body.constant(int(20)));
   ir_expression *const r0034 = bit_and(r0033, body.constant(2047u));
   ir_expression *const r0035 = expr(ir_unop_u2i, r0034);
   ir_expression *const r0036 = equal(r0035, body.constant(int(2047)));
   ir_expression *const r0037 = bit_and(swizzle_y(r002E), body.constant(1048575u));
   ir_expression *const r0038 = bit_or(r0037, swizzle_x(r002E));
   ir_expression *const r0039 = nequal(r0038, body.constant(0u));
   body.emit(assign(r0032, logic_and(r0036, r0039), 0x01));

   ir_expression *const r003A = rshift(swizzle_y(r002F), body.constant(int(20)));
   ir_expression *const r003B = bit_and(r003A, body.constant(2047u));
   ir_expression *const r003C = expr(ir_unop_u2i, r003B);
   ir_expression *const r003D = equal(r003C, body.constant(int(2047)));
   ir_expression *const r003E = bit_and(swizzle_y(r002F), body.constant(1048575u));
   ir_expression *const r003F = bit_or(r003E, swizzle_x(r002F));
   ir_expression *const r0040 = nequal(r003F, body.constant(0u));
   body.emit(assign(r0031, logic_and(r003D, r0040), 0x01));

   /* IF CONDITION */
   ir_expression *const r0042 = logic_or(r0032, r0031);
   ir_if *f0041 = new(mem_ctx) ir_if(operand(r0042).val);
   exec_list *const f0041_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0041->then_instructions;

      body.emit(assign(r0030, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0041->else_instructions;

      ir_expression *const r0043 = equal(swizzle_x(r002E), swizzle_x(r002F));
      ir_expression *const r0044 = equal(swizzle_y(r002E), swizzle_y(r002F));
      ir_expression *const r0045 = equal(swizzle_x(r002E), body.constant(0u));
      ir_expression *const r0046 = bit_or(swizzle_y(r002E), swizzle_y(r002F));
      ir_expression *const r0047 = lshift(r0046, body.constant(int(1)));
      ir_expression *const r0048 = equal(r0047, body.constant(0u));
      ir_expression *const r0049 = logic_and(r0045, r0048);
      ir_expression *const r004A = logic_or(r0044, r0049);
      body.emit(assign(r0030, logic_and(r0043, r004A), 0x01));


   body.instructions = f0041_parent_instructions;
   body.emit(f0041);

   /* END IF */

   body.emit(ret(r0030));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
