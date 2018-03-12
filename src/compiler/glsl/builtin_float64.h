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
   ir_expression *const r000E = gequal(r000D, body.constant(4292870144u));
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
   ir_variable *const r0015 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "t", ir_var_auto);
   body.emit(r0015);
   body.emit(assign(r0015, swizzle_x(r0014), 0x01));

   body.emit(assign(r0015, bit_xor(swizzle_y(r0014), body.constant(2147483648u)), 0x02));

   ir_expression *const r0016 = lshift(swizzle_y(r0014), body.constant(int(1)));
   ir_expression *const r0017 = gequal(r0016, body.constant(4292870144u));
   ir_expression *const r0018 = nequal(swizzle_x(r0014), body.constant(0u));
   ir_expression *const r0019 = bit_and(swizzle_y(r0014), body.constant(1048575u));
   ir_expression *const r001A = nequal(r0019, body.constant(0u));
   ir_expression *const r001B = logic_or(r0018, r001A);
   ir_expression *const r001C = logic_and(r0017, r001B);
   body.emit(assign(r0014, expr(ir_triop_csel, r001C, swizzle_y(r0014), swizzle_y(r0015)), 0x02));

   body.emit(ret(r0014));

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

   ir_variable *const r001D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r001D);
   ir_variable *const r001E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "retval", ir_var_auto);
   body.emit(r001E);
   body.emit(assign(r001E, body.constant(0u), 0x01));

   ir_expression *const r001F = lshift(swizzle_y(r001D), body.constant(int(1)));
   ir_expression *const r0020 = bit_or(r001F, swizzle_x(r001D));
   ir_expression *const r0021 = equal(r0020, body.constant(0u));
   ir_expression *const r0022 = bit_and(swizzle_y(r001D), body.constant(2147483648u));
   ir_expression *const r0023 = bit_or(r0022, body.constant(1072693248u));
   body.emit(assign(r001E, expr(ir_triop_csel, r0021, body.constant(0u), r0023), 0x02));

   body.emit(ret(r001E));

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

   ir_variable *const r0024 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0024);
   ir_swizzle *const r0025 = swizzle_x(r0024);
   body.emit(ret(r0025));

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

   ir_variable *const r0026 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0026);
   ir_expression *const r0027 = bit_and(swizzle_y(r0026), body.constant(1048575u));
   body.emit(ret(r0027));

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

   ir_variable *const r0028 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0028);
   ir_expression *const r0029 = rshift(swizzle_y(r0028), body.constant(int(20)));
   ir_expression *const r002A = bit_and(r0029, body.constant(2047u));
   ir_expression *const r002B = expr(ir_unop_u2i, r002A);
   body.emit(ret(r002B));

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

   ir_variable *const r002C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r002C);
   ir_variable *const r002D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r002D);
   ir_variable *const r002E = body.make_temp(glsl_type::bool_type, "mix_retval");
   ir_expression *const r002F = rshift(swizzle_y(r002C), body.constant(int(20)));
   ir_expression *const r0030 = bit_and(r002F, body.constant(2047u));
   ir_expression *const r0031 = expr(ir_unop_u2i, r0030);
   ir_expression *const r0032 = equal(r0031, body.constant(int(2047)));
   ir_expression *const r0033 = bit_and(swizzle_y(r002C), body.constant(1048575u));
   ir_expression *const r0034 = bit_or(r0033, swizzle_x(r002C));
   ir_expression *const r0035 = nequal(r0034, body.constant(0u));
   ir_expression *const r0036 = logic_and(r0032, r0035);
   ir_expression *const r0037 = rshift(swizzle_y(r002D), body.constant(int(20)));
   ir_expression *const r0038 = bit_and(r0037, body.constant(2047u));
   ir_expression *const r0039 = expr(ir_unop_u2i, r0038);
   ir_expression *const r003A = equal(r0039, body.constant(int(2047)));
   ir_expression *const r003B = bit_and(swizzle_y(r002D), body.constant(1048575u));
   ir_expression *const r003C = bit_or(r003B, swizzle_x(r002D));
   ir_expression *const r003D = nequal(r003C, body.constant(0u));
   ir_expression *const r003E = logic_and(r003A, r003D);
   ir_expression *const r003F = logic_or(r0036, r003E);
   ir_expression *const r0040 = equal(swizzle_x(r002C), swizzle_x(r002D));
   ir_expression *const r0041 = equal(swizzle_y(r002C), swizzle_y(r002D));
   ir_expression *const r0042 = equal(swizzle_x(r002C), body.constant(0u));
   ir_expression *const r0043 = bit_or(swizzle_y(r002C), swizzle_y(r002D));
   ir_expression *const r0044 = lshift(r0043, body.constant(int(1)));
   ir_expression *const r0045 = equal(r0044, body.constant(0u));
   ir_expression *const r0046 = logic_and(r0042, r0045);
   ir_expression *const r0047 = logic_or(r0041, r0046);
   ir_expression *const r0048 = logic_and(r0040, r0047);
   body.emit(assign(r002E, expr(ir_triop_csel, r003F, body.constant(false), r0048), 0x01));

   body.emit(ret(r002E));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
extractFloat64Sign(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uint_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0049 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0049);
   ir_expression *const r004A = rshift(swizzle_y(r0049), body.constant(int(31)));
   body.emit(ret(r004A));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
lt64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::bool_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r004B = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r004B);
   ir_variable *const r004C = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r004C);
   ir_variable *const r004D = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r004D);
   ir_variable *const r004E = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r004E);
   ir_expression *const r004F = less(r004B, r004D);
   ir_expression *const r0050 = equal(r004B, r004D);
   ir_expression *const r0051 = less(r004C, r004E);
   ir_expression *const r0052 = logic_and(r0050, r0051);
   ir_expression *const r0053 = logic_or(r004F, r0052);
   body.emit(ret(r0053));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
flt64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::bool_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0054 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0054);
   ir_variable *const r0055 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0055);
   ir_variable *const r0056 = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r0057 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r0057);
   ir_variable *const r0058 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0058);
   ir_expression *const r0059 = rshift(swizzle_y(r0054), body.constant(int(20)));
   ir_expression *const r005A = bit_and(r0059, body.constant(2047u));
   ir_expression *const r005B = expr(ir_unop_u2i, r005A);
   ir_expression *const r005C = equal(r005B, body.constant(int(2047)));
   ir_expression *const r005D = bit_and(swizzle_y(r0054), body.constant(1048575u));
   ir_expression *const r005E = bit_or(r005D, swizzle_x(r0054));
   ir_expression *const r005F = nequal(r005E, body.constant(0u));
   body.emit(assign(r0058, logic_and(r005C, r005F), 0x01));

   ir_expression *const r0060 = rshift(swizzle_y(r0055), body.constant(int(20)));
   ir_expression *const r0061 = bit_and(r0060, body.constant(2047u));
   ir_expression *const r0062 = expr(ir_unop_u2i, r0061);
   ir_expression *const r0063 = equal(r0062, body.constant(int(2047)));
   ir_expression *const r0064 = bit_and(swizzle_y(r0055), body.constant(1048575u));
   ir_expression *const r0065 = bit_or(r0064, swizzle_x(r0055));
   ir_expression *const r0066 = nequal(r0065, body.constant(0u));
   body.emit(assign(r0057, logic_and(r0063, r0066), 0x01));

   /* IF CONDITION */
   ir_expression *const r0068 = logic_or(r0058, r0057);
   ir_if *f0067 = new(mem_ctx) ir_if(operand(r0068).val);
   exec_list *const f0067_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0067->then_instructions;

      body.emit(assign(r0056, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0067->else_instructions;

      ir_variable *const r0069 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r0069, rshift(swizzle_y(r0054), body.constant(int(31))), 0x01));

      ir_variable *const r006A = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r006A, rshift(swizzle_y(r0055), body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r006C = nequal(r0069, r006A);
      ir_if *f006B = new(mem_ctx) ir_if(operand(r006C).val);
      exec_list *const f006B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f006B->then_instructions;

         ir_expression *const r006D = nequal(r0069, body.constant(0u));
         ir_expression *const r006E = bit_or(swizzle_y(r0054), swizzle_y(r0055));
         ir_expression *const r006F = lshift(r006E, body.constant(int(1)));
         ir_expression *const r0070 = bit_or(r006F, swizzle_x(r0054));
         ir_expression *const r0071 = bit_or(r0070, swizzle_x(r0055));
         ir_expression *const r0072 = nequal(r0071, body.constant(0u));
         body.emit(assign(r0056, logic_and(r006D, r0072), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f006B->else_instructions;

         ir_expression *const r0073 = nequal(r0069, body.constant(0u));
         ir_expression *const r0074 = less(swizzle_y(r0055), swizzle_y(r0054));
         ir_expression *const r0075 = equal(swizzle_y(r0055), swizzle_y(r0054));
         ir_expression *const r0076 = less(swizzle_x(r0055), swizzle_x(r0054));
         ir_expression *const r0077 = logic_and(r0075, r0076);
         ir_expression *const r0078 = logic_or(r0074, r0077);
         ir_expression *const r0079 = less(swizzle_y(r0054), swizzle_y(r0055));
         ir_expression *const r007A = equal(swizzle_y(r0054), swizzle_y(r0055));
         ir_expression *const r007B = less(swizzle_x(r0054), swizzle_x(r0055));
         ir_expression *const r007C = logic_and(r007A, r007B);
         ir_expression *const r007D = logic_or(r0079, r007C);
         body.emit(assign(r0056, expr(ir_triop_csel, r0073, r0078, r007D), 0x01));


      body.instructions = f006B_parent_instructions;
      body.emit(f006B);

      /* END IF */


   body.instructions = f0067_parent_instructions;
   body.emit(f0067);

   /* END IF */

   body.emit(ret(r0056));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
add64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r007E = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r007E);
   ir_variable *const r007F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r007F);
   ir_variable *const r0080 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0080);
   ir_variable *const r0081 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0081);
   ir_variable *const r0082 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0082);
   ir_variable *const r0083 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0083);
   ir_variable *const r0084 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0084, add(r007F, r0081), 0x01));

   body.emit(assign(r0083, r0084, 0x01));

   ir_expression *const r0085 = add(r007E, r0080);
   ir_expression *const r0086 = less(r0084, r007F);
   ir_expression *const r0087 = expr(ir_unop_b2i, r0086);
   ir_expression *const r0088 = expr(ir_unop_i2u, r0087);
   body.emit(assign(r0082, add(r0085, r0088), 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
sub64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0089 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0089);
   ir_variable *const r008A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r008A);
   ir_variable *const r008B = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r008B);
   ir_variable *const r008C = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r008C);
   ir_variable *const r008D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r008D);
   ir_variable *const r008E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r008E);
   body.emit(assign(r008E, sub(r008A, r008C), 0x01));

   ir_expression *const r008F = sub(r0089, r008B);
   ir_expression *const r0090 = less(r008A, r008C);
   ir_expression *const r0091 = expr(ir_unop_b2i, r0090);
   ir_expression *const r0092 = expr(ir_unop_i2u, r0091);
   body.emit(assign(r008D, sub(r008F, r0092), 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
shift64RightJamming(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0093 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0093);
   ir_variable *const r0094 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0094);
   ir_variable *const r0095 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r0095);
   ir_variable *const r0096 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0096);
   ir_variable *const r0097 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0097);
   ir_variable *const r0098 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0098);
   ir_variable *const r0099 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r009A = neg(r0095);
   body.emit(assign(r0099, bit_and(r009A, body.constant(int(31))), 0x01));

   ir_expression *const r009B = bit_or(r0093, r0094);
   ir_expression *const r009C = nequal(r009B, body.constant(0u));
   ir_expression *const r009D = expr(ir_unop_b2i, r009C);
   body.emit(assign(r0098, expr(ir_unop_i2u, r009D), 0x01));

   ir_variable *const r009E = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r009F = equal(r0095, body.constant(int(0)));
   ir_expression *const r00A0 = less(r0095, body.constant(int(32)));
   ir_expression *const r00A1 = lshift(r0093, r0099);
   ir_expression *const r00A2 = rshift(r0094, r0095);
   ir_expression *const r00A3 = bit_or(r00A1, r00A2);
   ir_expression *const r00A4 = lshift(r0094, r0099);
   ir_expression *const r00A5 = nequal(r00A4, body.constant(0u));
   ir_expression *const r00A6 = expr(ir_unop_b2i, r00A5);
   ir_expression *const r00A7 = expr(ir_unop_i2u, r00A6);
   ir_expression *const r00A8 = bit_or(r00A3, r00A7);
   ir_expression *const r00A9 = equal(r0095, body.constant(int(32)));
   ir_expression *const r00AA = nequal(r0094, body.constant(0u));
   ir_expression *const r00AB = expr(ir_unop_b2i, r00AA);
   ir_expression *const r00AC = expr(ir_unop_i2u, r00AB);
   ir_expression *const r00AD = bit_or(r0093, r00AC);
   ir_expression *const r00AE = less(r0095, body.constant(int(64)));
   ir_expression *const r00AF = bit_and(r0095, body.constant(int(31)));
   ir_expression *const r00B0 = rshift(r0093, r00AF);
   ir_expression *const r00B1 = lshift(r0093, r0099);
   ir_expression *const r00B2 = bit_or(r00B1, r0094);
   ir_expression *const r00B3 = nequal(r00B2, body.constant(0u));
   ir_expression *const r00B4 = expr(ir_unop_b2i, r00B3);
   ir_expression *const r00B5 = expr(ir_unop_i2u, r00B4);
   ir_expression *const r00B6 = bit_or(r00B0, r00B5);
   ir_expression *const r00B7 = expr(ir_triop_csel, r00AE, r00B6, r0098);
   ir_expression *const r00B8 = expr(ir_triop_csel, r00A9, r00AD, r00B7);
   ir_expression *const r00B9 = expr(ir_triop_csel, r00A0, r00A8, r00B8);
   body.emit(assign(r009E, expr(ir_triop_csel, r009F, r0094, r00B9), 0x01));

   body.emit(assign(r0098, r009E, 0x01));

   body.emit(assign(r0097, r009E, 0x01));

   ir_expression *const r00BA = less(r0095, body.constant(int(32)));
   ir_expression *const r00BB = rshift(r0093, r0095);
   ir_expression *const r00BC = equal(r0095, body.constant(int(0)));
   ir_expression *const r00BD = expr(ir_triop_csel, r00BC, r0093, body.constant(0u));
   body.emit(assign(r0096, expr(ir_triop_csel, r00BA, r00BB, r00BD), 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
shift64ExtraRightJamming(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r00BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00BE);
   ir_variable *const r00BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00BF);
   ir_variable *const r00C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r00C0);
   ir_variable *const r00C1 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00C1);
   ir_variable *const r00C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C2);
   ir_variable *const r00C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C3);
   ir_variable *const r00C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C4);
   ir_variable *const r00C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
   body.emit(r00C5);
   ir_variable *const r00C6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r00C7 = neg(r00C1);
   body.emit(assign(r00C6, bit_and(r00C7, body.constant(int(31))), 0x01));

   ir_variable *const r00C8 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r00C9 = less(r00C1, body.constant(int(32)));
   ir_expression *const r00CA = bit_or(r00C0, r00BF);
   body.emit(assign(r00C8, expr(ir_triop_csel, r00C9, r00C0, r00CA), 0x01));

   body.emit(assign(r00C0, r00C8, 0x01));

   ir_expression *const r00CB = less(r00C1, body.constant(int(32)));
   ir_expression *const r00CC = lshift(r00BF, r00C6);
   ir_expression *const r00CD = less(r00C1, body.constant(int(64)));
   ir_expression *const r00CE = lshift(r00BE, r00C6);
   ir_expression *const r00CF = equal(r00C1, body.constant(int(64)));
   ir_expression *const r00D0 = nequal(r00BE, body.constant(0u));
   ir_expression *const r00D1 = expr(ir_unop_b2i, r00D0);
   ir_expression *const r00D2 = expr(ir_unop_i2u, r00D1);
   ir_expression *const r00D3 = expr(ir_triop_csel, r00CF, r00BE, r00D2);
   ir_expression *const r00D4 = expr(ir_triop_csel, r00CD, r00CE, r00D3);
   ir_expression *const r00D5 = expr(ir_triop_csel, r00CB, r00CC, r00D4);
   ir_expression *const r00D6 = nequal(r00C8, body.constant(0u));
   ir_expression *const r00D7 = expr(ir_unop_b2i, r00D6);
   ir_expression *const r00D8 = expr(ir_unop_i2u, r00D7);
   body.emit(assign(r00C5, bit_or(r00D5, r00D8), 0x01));

   ir_variable *const r00D9 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r00DA = equal(r00C1, body.constant(int(0)));
   ir_expression *const r00DB = equal(r00C1, body.constant(int(32)));
   ir_expression *const r00DC = expr(ir_triop_csel, r00DB, r00BF, r00C5);
   body.emit(assign(r00D9, expr(ir_triop_csel, r00DA, r00C8, r00DC), 0x01));

   body.emit(assign(r00C5, r00D9, 0x01));

   body.emit(assign(r00C4, r00D9, 0x01));

   ir_expression *const r00DD = equal(r00C1, body.constant(int(0)));
   ir_expression *const r00DE = equal(r00C1, body.constant(int(32)));
   ir_expression *const r00DF = less(r00C1, body.constant(int(32)));
   ir_expression *const r00E0 = lshift(r00BE, r00C6);
   ir_expression *const r00E1 = rshift(r00BF, r00C1);
   ir_expression *const r00E2 = bit_or(r00E0, r00E1);
   ir_expression *const r00E3 = less(r00C1, body.constant(int(64)));
   ir_expression *const r00E4 = bit_and(r00C1, body.constant(int(31)));
   ir_expression *const r00E5 = rshift(r00BE, r00E4);
   ir_expression *const r00E6 = expr(ir_triop_csel, r00E3, r00E5, body.constant(0u));
   ir_expression *const r00E7 = expr(ir_triop_csel, r00DF, r00E2, r00E6);
   ir_expression *const r00E8 = expr(ir_triop_csel, r00DE, r00BE, r00E7);
   body.emit(assign(r00C3, expr(ir_triop_csel, r00DD, r00BF, r00E8), 0x01));

   ir_expression *const r00E9 = equal(r00C1, body.constant(int(0)));
   ir_expression *const r00EA = equal(r00C1, body.constant(int(32)));
   ir_expression *const r00EB = less(r00C1, body.constant(int(32)));
   ir_expression *const r00EC = rshift(r00BE, r00C1);
   ir_expression *const r00ED = expr(ir_triop_csel, r00EB, r00EC, body.constant(0u));
   ir_expression *const r00EE = expr(ir_triop_csel, r00EA, body.constant(0u), r00ED);
   body.emit(assign(r00C2, expr(ir_triop_csel, r00E9, r00BE, r00EE), 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
shortShift64Left(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r00EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00EF);
   ir_variable *const r00F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00F0);
   ir_variable *const r00F1 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00F1);
   ir_variable *const r00F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00F2);
   ir_variable *const r00F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00F3);
   body.emit(assign(r00F3, lshift(r00F0, r00F1), 0x01));

   ir_expression *const r00F4 = equal(r00F1, body.constant(int(0)));
   ir_expression *const r00F5 = lshift(r00EF, r00F1);
   ir_expression *const r00F6 = neg(r00F1);
   ir_expression *const r00F7 = bit_and(r00F6, body.constant(int(31)));
   ir_expression *const r00F8 = rshift(r00F0, r00F7);
   ir_expression *const r00F9 = bit_or(r00F5, r00F8);
   body.emit(assign(r00F2, expr(ir_triop_csel, r00F4, r00EF, r00F9), 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
packFloat64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r00FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00FA);
   ir_variable *const r00FB = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00FB);
   ir_variable *const r00FC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00FC);
   ir_variable *const r00FD = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00FD);
   ir_variable *const r00FE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
   body.emit(r00FE);
   ir_expression *const r00FF = lshift(r00FA, body.constant(int(31)));
   ir_expression *const r0100 = expr(ir_unop_i2u, r00FB);
   ir_expression *const r0101 = lshift(r0100, body.constant(int(20)));
   ir_expression *const r0102 = add(r00FF, r0101);
   body.emit(assign(r00FE, add(r0102, r00FC), 0x02));

   body.emit(assign(r00FE, r00FD, 0x01));

   body.emit(ret(r00FE));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
roundAndPackFloat64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0103 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0103);
   ir_variable *const r0104 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0104);
   ir_variable *const r0105 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0105);
   ir_variable *const r0106 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0106);
   ir_variable *const r0107 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_function_in);
   sig_parameters.push_tail(r0107);
   ir_variable *const r0108 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0108, body.constant(true), 0x01));

   ir_variable *const r0109 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r010A = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r010A);
   ir_expression *const r010B = expr(ir_unop_u2i, r0107);
   body.emit(assign(r010A, less(r010B, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r010D = gequal(r0104, body.constant(int(2045)));
   ir_if *f010C = new(mem_ctx) ir_if(operand(r010D).val);
   exec_list *const f010C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f010C->then_instructions;

      /* IF CONDITION */
      ir_expression *const r010F = less(body.constant(int(2045)), r0104);
      ir_expression *const r0110 = equal(r0104, body.constant(int(2045)));
      ir_expression *const r0111 = equal(body.constant(2097151u), r0105);
      ir_expression *const r0112 = equal(body.constant(4294967295u), r0106);
      ir_expression *const r0113 = logic_and(r0111, r0112);
      ir_expression *const r0114 = logic_and(r0110, r0113);
      ir_expression *const r0115 = logic_and(r0114, r010A);
      ir_expression *const r0116 = logic_or(r010F, r0115);
      ir_if *f010E = new(mem_ctx) ir_if(operand(r0116).val);
      exec_list *const f010E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f010E->then_instructions;

         ir_variable *const r0117 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0117);
         ir_expression *const r0118 = lshift(r0103, body.constant(int(31)));
         body.emit(assign(r0117, add(r0118, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0117, body.constant(0u), 0x01));

         body.emit(assign(r0109, r0117, 0x03));

         body.emit(assign(r0108, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f010E->else_instructions;

         /* IF CONDITION */
         ir_expression *const r011A = less(r0104, body.constant(int(0)));
         ir_if *f0119 = new(mem_ctx) ir_if(operand(r011A).val);
         exec_list *const f0119_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0119->then_instructions;

            ir_variable *const r011B = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r011B, neg(r0104), 0x01));

            ir_variable *const r011C = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_variable *const r011D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r011D);
            ir_variable *const r011E = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r011F = neg(r011B);
            body.emit(assign(r011E, bit_and(r011F, body.constant(int(31))), 0x01));

            ir_variable *const r0120 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0121 = less(r011B, body.constant(int(32)));
            ir_expression *const r0122 = bit_or(r0107, r0106);
            body.emit(assign(r0120, expr(ir_triop_csel, r0121, r0107, r0122), 0x01));

            ir_expression *const r0123 = less(r011B, body.constant(int(32)));
            ir_expression *const r0124 = lshift(r0106, r011E);
            ir_expression *const r0125 = less(r011B, body.constant(int(64)));
            ir_expression *const r0126 = lshift(r0105, r011E);
            ir_expression *const r0127 = equal(r011B, body.constant(int(64)));
            ir_expression *const r0128 = nequal(r0105, body.constant(0u));
            ir_expression *const r0129 = expr(ir_unop_b2i, r0128);
            ir_expression *const r012A = expr(ir_unop_i2u, r0129);
            ir_expression *const r012B = expr(ir_triop_csel, r0127, r0105, r012A);
            ir_expression *const r012C = expr(ir_triop_csel, r0125, r0126, r012B);
            ir_expression *const r012D = expr(ir_triop_csel, r0123, r0124, r012C);
            ir_expression *const r012E = nequal(r0120, body.constant(0u));
            ir_expression *const r012F = expr(ir_unop_b2i, r012E);
            ir_expression *const r0130 = expr(ir_unop_i2u, r012F);
            body.emit(assign(r011D, bit_or(r012D, r0130), 0x01));

            ir_variable *const r0131 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0132 = equal(r011B, body.constant(int(0)));
            ir_expression *const r0133 = equal(r011B, body.constant(int(32)));
            ir_expression *const r0134 = expr(ir_triop_csel, r0133, r0106, r011D);
            body.emit(assign(r0131, expr(ir_triop_csel, r0132, r0120, r0134), 0x01));

            body.emit(assign(r011D, r0131, 0x01));

            ir_expression *const r0135 = equal(r011B, body.constant(int(0)));
            ir_expression *const r0136 = equal(r011B, body.constant(int(32)));
            ir_expression *const r0137 = less(r011B, body.constant(int(32)));
            ir_expression *const r0138 = lshift(r0105, r011E);
            ir_expression *const r0139 = rshift(r0106, r011B);
            ir_expression *const r013A = bit_or(r0138, r0139);
            ir_expression *const r013B = less(r011B, body.constant(int(64)));
            ir_expression *const r013C = bit_and(r011B, body.constant(int(31)));
            ir_expression *const r013D = rshift(r0105, r013C);
            ir_expression *const r013E = expr(ir_triop_csel, r013B, r013D, body.constant(0u));
            ir_expression *const r013F = expr(ir_triop_csel, r0137, r013A, r013E);
            ir_expression *const r0140 = expr(ir_triop_csel, r0136, r0105, r013F);
            body.emit(assign(r011C, expr(ir_triop_csel, r0135, r0106, r0140), 0x01));

            ir_expression *const r0141 = equal(r011B, body.constant(int(0)));
            ir_expression *const r0142 = equal(r011B, body.constant(int(32)));
            ir_expression *const r0143 = less(r011B, body.constant(int(32)));
            ir_expression *const r0144 = rshift(r0105, r011B);
            ir_expression *const r0145 = expr(ir_triop_csel, r0143, r0144, body.constant(0u));
            ir_expression *const r0146 = expr(ir_triop_csel, r0142, body.constant(0u), r0145);
            body.emit(assign(r0105, expr(ir_triop_csel, r0141, r0105, r0146), 0x01));

            body.emit(assign(r0106, r011C, 0x01));

            body.emit(assign(r0107, r0131, 0x01));

            body.emit(assign(r0104, body.constant(int(0)), 0x01));

            body.emit(assign(r010A, less(r0131, body.constant(0u)), 0x01));


         body.instructions = f0119_parent_instructions;
         body.emit(f0119);

         /* END IF */


      body.instructions = f010E_parent_instructions;
      body.emit(f010E);

      /* END IF */


   body.instructions = f010C_parent_instructions;
   body.emit(f010C);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0147 = new(mem_ctx) ir_if(operand(r0108).val);
   exec_list *const f0147_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0147->then_instructions;

      /* IF CONDITION */
      ir_if *f0148 = new(mem_ctx) ir_if(operand(r010A).val);
      exec_list *const f0148_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0148->then_instructions;

         ir_variable *const r0149 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0149, add(r0106, body.constant(1u)), 0x01));

         ir_expression *const r014A = less(r0149, r0106);
         ir_expression *const r014B = expr(ir_unop_b2i, r014A);
         ir_expression *const r014C = expr(ir_unop_i2u, r014B);
         body.emit(assign(r0105, add(r0105, r014C), 0x01));

         ir_expression *const r014D = equal(r0107, body.constant(0u));
         ir_expression *const r014E = expr(ir_unop_b2i, r014D);
         ir_expression *const r014F = expr(ir_unop_i2u, r014E);
         ir_expression *const r0150 = add(r0107, r014F);
         ir_expression *const r0151 = bit_and(r0150, body.constant(1u));
         ir_expression *const r0152 = expr(ir_unop_bit_not, r0151);
         body.emit(assign(r0106, bit_and(r0149, r0152), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0148->else_instructions;

         ir_expression *const r0153 = bit_or(r0105, r0106);
         ir_expression *const r0154 = equal(r0153, body.constant(0u));
         body.emit(assign(r0104, expr(ir_triop_csel, r0154, body.constant(int(0)), r0104), 0x01));


      body.instructions = f0148_parent_instructions;
      body.emit(f0148);

      /* END IF */

      ir_variable *const r0155 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0155);
      ir_expression *const r0156 = lshift(r0103, body.constant(int(31)));
      ir_expression *const r0157 = expr(ir_unop_i2u, r0104);
      ir_expression *const r0158 = lshift(r0157, body.constant(int(20)));
      ir_expression *const r0159 = add(r0156, r0158);
      body.emit(assign(r0155, add(r0159, r0105), 0x02));

      body.emit(assign(r0155, r0106, 0x01));

      body.emit(assign(r0109, r0155, 0x03));

      body.emit(assign(r0108, body.constant(false), 0x01));


   body.instructions = f0147_parent_instructions;
   body.emit(f0147);

   /* END IF */

   body.emit(ret(r0109));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
countLeadingZeros32(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::int_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r015A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r015A);
   ir_variable *const r015B = body.make_temp(glsl_type::int_type, "mix_retval");
   ir_expression *const r015C = equal(r015A, body.constant(0u));
   ir_expression *const r015D = expr(ir_unop_find_msb, r015A);
   ir_expression *const r015E = sub(body.constant(int(31)), r015D);
   body.emit(assign(r015B, expr(ir_triop_csel, r015C, body.constant(int(32)), r015E), 0x01));

   body.emit(ret(r015B));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
normalizeRoundAndPackFloat64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r015F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r015F);
   ir_variable *const r0160 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0160);
   ir_variable *const r0161 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0161);
   ir_variable *const r0162 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0162);
   ir_variable *const r0163 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0163);
   ir_variable *const r0164 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0164);
   ir_expression *const r0165 = equal(r0161, body.constant(0u));
   ir_expression *const r0166 = add(r0160, body.constant(int(-32)));
   body.emit(assign(r0160, expr(ir_triop_csel, r0165, r0166, r0160), 0x01));

   ir_variable *const r0167 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r0168 = equal(r0161, body.constant(0u));
   body.emit(assign(r0167, expr(ir_triop_csel, r0168, body.constant(0u), r0162), 0x01));

   body.emit(assign(r0162, r0167, 0x01));

   ir_variable *const r0169 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r016A = equal(r0161, body.constant(0u));
   body.emit(assign(r0169, expr(ir_triop_csel, r016A, r0167, r0161), 0x01));

   body.emit(assign(r0161, r0169, 0x01));

   ir_expression *const r016B = equal(r0169, body.constant(0u));
   ir_expression *const r016C = expr(ir_unop_find_msb, r0169);
   ir_expression *const r016D = sub(body.constant(int(31)), r016C);
   ir_expression *const r016E = expr(ir_triop_csel, r016B, body.constant(int(32)), r016D);
   body.emit(assign(r0164, add(r016E, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0170 = gequal(r0164, body.constant(int(0)));
   ir_if *f016F = new(mem_ctx) ir_if(operand(r0170).val);
   exec_list *const f016F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f016F->then_instructions;

      body.emit(assign(r0163, body.constant(0u), 0x01));

      ir_expression *const r0171 = equal(r0164, body.constant(int(0)));
      ir_expression *const r0172 = lshift(r0169, r0164);
      ir_expression *const r0173 = neg(r0164);
      ir_expression *const r0174 = bit_and(r0173, body.constant(int(31)));
      ir_expression *const r0175 = rshift(r0167, r0174);
      ir_expression *const r0176 = bit_or(r0172, r0175);
      body.emit(assign(r0161, expr(ir_triop_csel, r0171, r0169, r0176), 0x01));

      body.emit(assign(r0162, lshift(r0167, r0164), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f016F->else_instructions;

      ir_variable *const r0177 = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r0177, neg(r0164), 0x01));

      ir_variable *const r0178 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      ir_variable *const r0179 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
      body.emit(r0179);
      ir_variable *const r017A = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r017B = neg(r0177);
      body.emit(assign(r017A, bit_and(r017B, body.constant(int(31))), 0x01));

      ir_variable *const r017C = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r017D = less(r0177, body.constant(int(32)));
      ir_expression *const r017E = bit_or(body.constant(0u), r0162);
      body.emit(assign(r017C, expr(ir_triop_csel, r017D, body.constant(0u), r017E), 0x01));

      ir_expression *const r017F = less(r0177, body.constant(int(32)));
      ir_expression *const r0180 = lshift(r0162, r017A);
      ir_expression *const r0181 = less(r0177, body.constant(int(64)));
      ir_expression *const r0182 = lshift(r0161, r017A);
      ir_expression *const r0183 = equal(r0177, body.constant(int(64)));
      ir_expression *const r0184 = nequal(r0161, body.constant(0u));
      ir_expression *const r0185 = expr(ir_unop_b2i, r0184);
      ir_expression *const r0186 = expr(ir_unop_i2u, r0185);
      ir_expression *const r0187 = expr(ir_triop_csel, r0183, r0161, r0186);
      ir_expression *const r0188 = expr(ir_triop_csel, r0181, r0182, r0187);
      ir_expression *const r0189 = expr(ir_triop_csel, r017F, r0180, r0188);
      ir_expression *const r018A = nequal(r017C, body.constant(0u));
      ir_expression *const r018B = expr(ir_unop_b2i, r018A);
      ir_expression *const r018C = expr(ir_unop_i2u, r018B);
      body.emit(assign(r0179, bit_or(r0189, r018C), 0x01));

      ir_variable *const r018D = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r018E = equal(r0177, body.constant(int(0)));
      ir_expression *const r018F = equal(r0177, body.constant(int(32)));
      ir_expression *const r0190 = expr(ir_triop_csel, r018F, r0162, r0179);
      body.emit(assign(r018D, expr(ir_triop_csel, r018E, r017C, r0190), 0x01));

      body.emit(assign(r0179, r018D, 0x01));

      ir_expression *const r0191 = equal(r0177, body.constant(int(0)));
      ir_expression *const r0192 = equal(r0177, body.constant(int(32)));
      ir_expression *const r0193 = less(r0177, body.constant(int(32)));
      ir_expression *const r0194 = lshift(r0161, r017A);
      ir_expression *const r0195 = rshift(r0162, r0177);
      ir_expression *const r0196 = bit_or(r0194, r0195);
      ir_expression *const r0197 = less(r0177, body.constant(int(64)));
      ir_expression *const r0198 = bit_and(r0177, body.constant(int(31)));
      ir_expression *const r0199 = rshift(r0161, r0198);
      ir_expression *const r019A = expr(ir_triop_csel, r0197, r0199, body.constant(0u));
      ir_expression *const r019B = expr(ir_triop_csel, r0193, r0196, r019A);
      ir_expression *const r019C = expr(ir_triop_csel, r0192, r0161, r019B);
      body.emit(assign(r0178, expr(ir_triop_csel, r0191, r0162, r019C), 0x01));

      ir_expression *const r019D = equal(r0177, body.constant(int(0)));
      ir_expression *const r019E = equal(r0177, body.constant(int(32)));
      ir_expression *const r019F = less(r0177, body.constant(int(32)));
      ir_expression *const r01A0 = rshift(r0161, r0177);
      ir_expression *const r01A1 = expr(ir_triop_csel, r019F, r01A0, body.constant(0u));
      ir_expression *const r01A2 = expr(ir_triop_csel, r019E, body.constant(0u), r01A1);
      body.emit(assign(r0161, expr(ir_triop_csel, r019D, r0161, r01A2), 0x01));

      body.emit(assign(r0162, r0178, 0x01));

      body.emit(assign(r0163, r018D, 0x01));


   body.instructions = f016F_parent_instructions;
   body.emit(f016F);

   /* END IF */

   body.emit(assign(r0160, sub(r0160, r0164), 0x01));

   ir_variable *const r01A3 = body.make_temp(glsl_type::int_type, "zExp");
   body.emit(assign(r01A3, r0160, 0x01));

   ir_variable *const r01A4 = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r01A4, r0161, 0x01));

   ir_variable *const r01A5 = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r01A5, r0162, 0x01));

   ir_variable *const r01A6 = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r01A6, r0163, 0x01));

   ir_variable *const r01A7 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01A7, body.constant(true), 0x01));

   ir_variable *const r01A8 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01A9 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r01A9);
   ir_expression *const r01AA = expr(ir_unop_u2i, r0163);
   body.emit(assign(r01A9, less(r01AA, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r01AC = gequal(r0160, body.constant(int(2045)));
   ir_if *f01AB = new(mem_ctx) ir_if(operand(r01AC).val);
   exec_list *const f01AB_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01AB->then_instructions;

      /* IF CONDITION */
      ir_expression *const r01AE = less(body.constant(int(2045)), r0160);
      ir_expression *const r01AF = equal(r0160, body.constant(int(2045)));
      ir_expression *const r01B0 = equal(body.constant(2097151u), r0161);
      ir_expression *const r01B1 = equal(body.constant(4294967295u), r0162);
      ir_expression *const r01B2 = logic_and(r01B0, r01B1);
      ir_expression *const r01B3 = logic_and(r01AF, r01B2);
      ir_expression *const r01B4 = logic_and(r01B3, r01A9);
      ir_expression *const r01B5 = logic_or(r01AE, r01B4);
      ir_if *f01AD = new(mem_ctx) ir_if(operand(r01B5).val);
      exec_list *const f01AD_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01AD->then_instructions;

         ir_variable *const r01B6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r01B6);
         ir_expression *const r01B7 = lshift(r015F, body.constant(int(31)));
         body.emit(assign(r01B6, add(r01B7, body.constant(2146435072u)), 0x02));

         body.emit(assign(r01B6, body.constant(0u), 0x01));

         body.emit(assign(r01A8, r01B6, 0x03));

         body.emit(assign(r01A7, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01AD->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01B9 = less(r0160, body.constant(int(0)));
         ir_if *f01B8 = new(mem_ctx) ir_if(operand(r01B9).val);
         exec_list *const f01B8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01B8->then_instructions;

            ir_variable *const r01BA = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r01BA, neg(r0160), 0x01));

            ir_variable *const r01BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r01BB);
            ir_variable *const r01BC = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r01BD = neg(r01BA);
            body.emit(assign(r01BC, bit_and(r01BD, body.constant(int(31))), 0x01));

            ir_variable *const r01BE = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r01BF = less(r01BA, body.constant(int(32)));
            ir_expression *const r01C0 = bit_or(r0163, r0162);
            body.emit(assign(r01BE, expr(ir_triop_csel, r01BF, r0163, r01C0), 0x01));

            ir_expression *const r01C1 = less(r01BA, body.constant(int(32)));
            ir_expression *const r01C2 = lshift(r0162, r01BC);
            ir_expression *const r01C3 = less(r01BA, body.constant(int(64)));
            ir_expression *const r01C4 = lshift(r0161, r01BC);
            ir_expression *const r01C5 = equal(r01BA, body.constant(int(64)));
            ir_expression *const r01C6 = nequal(r0161, body.constant(0u));
            ir_expression *const r01C7 = expr(ir_unop_b2i, r01C6);
            ir_expression *const r01C8 = expr(ir_unop_i2u, r01C7);
            ir_expression *const r01C9 = expr(ir_triop_csel, r01C5, r0161, r01C8);
            ir_expression *const r01CA = expr(ir_triop_csel, r01C3, r01C4, r01C9);
            ir_expression *const r01CB = expr(ir_triop_csel, r01C1, r01C2, r01CA);
            ir_expression *const r01CC = nequal(r01BE, body.constant(0u));
            ir_expression *const r01CD = expr(ir_unop_b2i, r01CC);
            ir_expression *const r01CE = expr(ir_unop_i2u, r01CD);
            body.emit(assign(r01BB, bit_or(r01CB, r01CE), 0x01));

            ir_variable *const r01CF = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r01D0 = equal(r01BA, body.constant(int(0)));
            ir_expression *const r01D1 = equal(r01BA, body.constant(int(32)));
            ir_expression *const r01D2 = expr(ir_triop_csel, r01D1, r0162, r01BB);
            body.emit(assign(r01CF, expr(ir_triop_csel, r01D0, r01BE, r01D2), 0x01));

            body.emit(assign(r01BB, r01CF, 0x01));

            ir_expression *const r01D3 = equal(r01BA, body.constant(int(0)));
            ir_expression *const r01D4 = equal(r01BA, body.constant(int(32)));
            ir_expression *const r01D5 = less(r01BA, body.constant(int(32)));
            ir_expression *const r01D6 = rshift(r0161, r01BA);
            ir_expression *const r01D7 = expr(ir_triop_csel, r01D5, r01D6, body.constant(0u));
            ir_expression *const r01D8 = expr(ir_triop_csel, r01D4, body.constant(0u), r01D7);
            body.emit(assign(r01A4, expr(ir_triop_csel, r01D3, r0161, r01D8), 0x01));

            ir_expression *const r01D9 = equal(r01BA, body.constant(int(0)));
            ir_expression *const r01DA = equal(r01BA, body.constant(int(32)));
            ir_expression *const r01DB = less(r01BA, body.constant(int(32)));
            ir_expression *const r01DC = lshift(r0161, r01BC);
            ir_expression *const r01DD = rshift(r0162, r01BA);
            ir_expression *const r01DE = bit_or(r01DC, r01DD);
            ir_expression *const r01DF = less(r01BA, body.constant(int(64)));
            ir_expression *const r01E0 = bit_and(r01BA, body.constant(int(31)));
            ir_expression *const r01E1 = rshift(r0161, r01E0);
            ir_expression *const r01E2 = expr(ir_triop_csel, r01DF, r01E1, body.constant(0u));
            ir_expression *const r01E3 = expr(ir_triop_csel, r01DB, r01DE, r01E2);
            ir_expression *const r01E4 = expr(ir_triop_csel, r01DA, r0161, r01E3);
            body.emit(assign(r01A5, expr(ir_triop_csel, r01D9, r0162, r01E4), 0x01));

            body.emit(assign(r01A6, r01CF, 0x01));

            body.emit(assign(r01A3, body.constant(int(0)), 0x01));

            body.emit(assign(r01A9, less(r01CF, body.constant(0u)), 0x01));


         body.instructions = f01B8_parent_instructions;
         body.emit(f01B8);

         /* END IF */


      body.instructions = f01AD_parent_instructions;
      body.emit(f01AD);

      /* END IF */


   body.instructions = f01AB_parent_instructions;
   body.emit(f01AB);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01E5 = new(mem_ctx) ir_if(operand(r01A7).val);
   exec_list *const f01E5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01E5->then_instructions;

      /* IF CONDITION */
      ir_if *f01E6 = new(mem_ctx) ir_if(operand(r01A9).val);
      exec_list *const f01E6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01E6->then_instructions;

         ir_variable *const r01E7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01E7, add(r01A5, body.constant(1u)), 0x01));

         ir_expression *const r01E8 = less(r01E7, r01A5);
         ir_expression *const r01E9 = expr(ir_unop_b2i, r01E8);
         ir_expression *const r01EA = expr(ir_unop_i2u, r01E9);
         body.emit(assign(r01A4, add(r01A4, r01EA), 0x01));

         ir_expression *const r01EB = equal(r01A6, body.constant(0u));
         ir_expression *const r01EC = expr(ir_unop_b2i, r01EB);
         ir_expression *const r01ED = expr(ir_unop_i2u, r01EC);
         ir_expression *const r01EE = add(r01A6, r01ED);
         ir_expression *const r01EF = bit_and(r01EE, body.constant(1u));
         ir_expression *const r01F0 = expr(ir_unop_bit_not, r01EF);
         body.emit(assign(r01A5, bit_and(r01E7, r01F0), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01E6->else_instructions;

         ir_expression *const r01F1 = bit_or(r01A4, r01A5);
         ir_expression *const r01F2 = equal(r01F1, body.constant(0u));
         body.emit(assign(r01A3, expr(ir_triop_csel, r01F2, body.constant(int(0)), r01A3), 0x01));


      body.instructions = f01E6_parent_instructions;
      body.emit(f01E6);

      /* END IF */

      ir_variable *const r01F3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r01F3);
      ir_expression *const r01F4 = lshift(r015F, body.constant(int(31)));
      ir_expression *const r01F5 = expr(ir_unop_i2u, r01A3);
      ir_expression *const r01F6 = lshift(r01F5, body.constant(int(20)));
      ir_expression *const r01F7 = add(r01F4, r01F6);
      body.emit(assign(r01F3, add(r01F7, r01A4), 0x02));

      body.emit(assign(r01F3, r01A5, 0x01));

      body.emit(assign(r01A8, r01F3, 0x03));

      body.emit(assign(r01A7, body.constant(false), 0x01));


   body.instructions = f01E5_parent_instructions;
   body.emit(f01E5);

   /* END IF */

   body.emit(ret(r01A8));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
propagateFloat64NaN(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r01F8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01F8);
   ir_variable *const r01F9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01F9);
   ir_variable *const r01FA = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01FB = lshift(swizzle_y(r01F8), body.constant(int(1)));
   ir_expression *const r01FC = gequal(r01FB, body.constant(4292870144u));
   ir_expression *const r01FD = nequal(swizzle_x(r01F8), body.constant(0u));
   ir_expression *const r01FE = bit_and(swizzle_y(r01F8), body.constant(1048575u));
   ir_expression *const r01FF = nequal(r01FE, body.constant(0u));
   ir_expression *const r0200 = logic_or(r01FD, r01FF);
   body.emit(assign(r01FA, logic_and(r01FC, r0200), 0x01));

   ir_variable *const r0201 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r0202 = lshift(swizzle_y(r01F9), body.constant(int(1)));
   ir_expression *const r0203 = gequal(r0202, body.constant(4292870144u));
   ir_expression *const r0204 = nequal(swizzle_x(r01F9), body.constant(0u));
   ir_expression *const r0205 = bit_and(swizzle_y(r01F9), body.constant(1048575u));
   ir_expression *const r0206 = nequal(r0205, body.constant(0u));
   ir_expression *const r0207 = logic_or(r0204, r0206);
   body.emit(assign(r0201, logic_and(r0203, r0207), 0x01));

   body.emit(assign(r01F8, bit_or(swizzle_y(r01F8), body.constant(524288u)), 0x02));

   body.emit(assign(r01F9, bit_or(swizzle_y(r01F9), body.constant(524288u)), 0x02));

   ir_variable *const r0208 = body.make_temp(glsl_type::uvec2_type, "mix_retval");
   ir_swizzle *const r0209 = swizzle(r01FA, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_swizzle *const r020A = swizzle(r0201, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_expression *const r020B = expr(ir_triop_csel, r020A, r01F9, r01F8);
   body.emit(assign(r0208, expr(ir_triop_csel, r0209, r020B, r01F9), 0x03));

   body.emit(ret(r0208));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fadd64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r020C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r020C);
   ir_variable *const r020D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r020D);
   ir_variable *const r020E = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r020E, body.constant(true), 0x01));

   ir_variable *const r020F = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0210 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
   body.emit(r0210);
   ir_variable *const r0211 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0211);
   ir_variable *const r0212 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0212);
   ir_variable *const r0213 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r0213);
   ir_variable *const r0214 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0214);
   ir_variable *const r0215 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r0215);
   ir_variable *const r0216 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r0216);
   ir_variable *const r0217 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0217);
   ir_variable *const r0218 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0218);
   ir_variable *const r0219 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0219);
   ir_variable *const r021A = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r021A, rshift(swizzle_y(r020C), body.constant(int(31))), 0x01));

   body.emit(assign(r0219, r021A, 0x01));

   ir_variable *const r021B = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r021B, rshift(swizzle_y(r020D), body.constant(int(31))), 0x01));

   body.emit(assign(r0218, swizzle_x(r020C), 0x01));

   ir_variable *const r021C = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r021C, bit_and(swizzle_y(r020C), body.constant(1048575u)), 0x01));

   body.emit(assign(r0217, r021C, 0x01));

   body.emit(assign(r0216, swizzle_x(r020D), 0x01));

   ir_variable *const r021D = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r021D, bit_and(swizzle_y(r020D), body.constant(1048575u)), 0x01));

   body.emit(assign(r0215, r021D, 0x01));

   ir_variable *const r021E = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r021F = rshift(swizzle_y(r020C), body.constant(int(20)));
   ir_expression *const r0220 = bit_and(r021F, body.constant(2047u));
   body.emit(assign(r021E, expr(ir_unop_u2i, r0220), 0x01));

   body.emit(assign(r0214, r021E, 0x01));

   ir_variable *const r0221 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0222 = rshift(swizzle_y(r020D), body.constant(int(20)));
   ir_expression *const r0223 = bit_and(r0222, body.constant(2047u));
   body.emit(assign(r0221, expr(ir_unop_u2i, r0223), 0x01));

   body.emit(assign(r0213, r0221, 0x01));

   body.emit(assign(r0212, body.constant(0u), 0x01));

   body.emit(assign(r0211, body.constant(0u), 0x01));

   ir_variable *const r0224 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0224, sub(r021E, r0221), 0x01));

   body.emit(assign(r0210, r0224, 0x01));

   /* IF CONDITION */
   ir_expression *const r0226 = equal(r021A, r021B);
   ir_if *f0225 = new(mem_ctx) ir_if(operand(r0226).val);
   exec_list *const f0225_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0225->then_instructions;

      ir_variable *const r0227 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r0227);
      ir_variable *const r0228 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r0228);
      body.emit(assign(r0228, body.constant(0u), 0x01));

      ir_variable *const r0229 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
      body.emit(assign(r0229, equal(r0224, body.constant(int(0))), 0x01));

      /* IF CONDITION */
      ir_if *f022A = new(mem_ctx) ir_if(operand(r0229).val);
      exec_list *const f022A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f022A->then_instructions;

         /* IF CONDITION */
         ir_expression *const r022C = equal(r021E, body.constant(int(2047)));
         ir_if *f022B = new(mem_ctx) ir_if(operand(r022C).val);
         exec_list *const f022B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f022B->then_instructions;

            ir_variable *const r022D = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r022D, swizzle_x(r020C), 0x01));

            ir_variable *const r022E = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r022E, swizzle_x(r020D), 0x01));

            body.emit(assign(r022D, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

            body.emit(assign(r022E, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

            ir_expression *const r022F = bit_or(r021C, swizzle_x(r020C));
            ir_expression *const r0230 = bit_or(r021D, swizzle_x(r020D));
            ir_expression *const r0231 = bit_or(r022F, r0230);
            ir_expression *const r0232 = nequal(r0231, body.constant(0u));
            ir_swizzle *const r0233 = swizzle(r0232, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0234 = lshift(swizzle_y(r020C), body.constant(int(1)));
            ir_expression *const r0235 = gequal(r0234, body.constant(4292870144u));
            ir_expression *const r0236 = nequal(swizzle_x(r020C), body.constant(0u));
            ir_expression *const r0237 = bit_and(swizzle_y(r020C), body.constant(1048575u));
            ir_expression *const r0238 = nequal(r0237, body.constant(0u));
            ir_expression *const r0239 = logic_or(r0236, r0238);
            ir_expression *const r023A = logic_and(r0235, r0239);
            ir_swizzle *const r023B = swizzle(r023A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r023C = lshift(swizzle_y(r020D), body.constant(int(1)));
            ir_expression *const r023D = gequal(r023C, body.constant(4292870144u));
            ir_expression *const r023E = nequal(swizzle_x(r020D), body.constant(0u));
            ir_expression *const r023F = bit_and(swizzle_y(r020D), body.constant(1048575u));
            ir_expression *const r0240 = nequal(r023F, body.constant(0u));
            ir_expression *const r0241 = logic_or(r023E, r0240);
            ir_expression *const r0242 = logic_and(r023D, r0241);
            ir_swizzle *const r0243 = swizzle(r0242, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0244 = expr(ir_triop_csel, r0243, r022E, r022D);
            ir_expression *const r0245 = expr(ir_triop_csel, r023B, r0244, r022E);
            body.emit(assign(r020F, expr(ir_triop_csel, r0233, r0245, r020C), 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f022B->else_instructions;

            ir_variable *const r0246 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r0247 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            body.emit(assign(r0247, add(swizzle_x(r020C), swizzle_x(r020D)), 0x01));

            ir_expression *const r0248 = add(r021C, r021D);
            ir_expression *const r0249 = less(r0247, swizzle_x(r020C));
            ir_expression *const r024A = expr(ir_unop_b2i, r0249);
            ir_expression *const r024B = expr(ir_unop_i2u, r024A);
            body.emit(assign(r0246, add(r0248, r024B), 0x01));

            body.emit(assign(r0212, r0246, 0x01));

            body.emit(assign(r0211, r0247, 0x01));

            /* IF CONDITION */
            ir_expression *const r024D = equal(r021E, body.constant(int(0)));
            ir_if *f024C = new(mem_ctx) ir_if(operand(r024D).val);
            exec_list *const f024C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f024C->then_instructions;

               ir_variable *const r024E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r024E);
               ir_expression *const r024F = lshift(r021A, body.constant(int(31)));
               body.emit(assign(r024E, add(r024F, r0246), 0x02));

               body.emit(assign(r024E, r0247, 0x01));

               body.emit(assign(r020F, r024E, 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f024C->else_instructions;

               body.emit(assign(r0212, bit_or(r0246, body.constant(2097152u)), 0x01));

               body.emit(assign(r0227, r021E, 0x01));

               ir_variable *const r0250 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               ir_expression *const r0251 = lshift(r0212, body.constant(int(31)));
               ir_expression *const r0252 = rshift(r0247, body.constant(int(1)));
               body.emit(assign(r0250, bit_or(r0251, r0252), 0x01));

               body.emit(assign(r0212, rshift(r0212, body.constant(int(1))), 0x01));

               body.emit(assign(r0211, r0250, 0x01));

               ir_expression *const r0253 = lshift(r0247, body.constant(int(31)));
               body.emit(assign(r0228, bit_or(r0253, body.constant(0u)), 0x01));


            body.instructions = f024C_parent_instructions;
            body.emit(f024C);

            /* END IF */


         body.instructions = f022B_parent_instructions;
         body.emit(f022B);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f022A->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0255 = less(body.constant(int(0)), r0224);
         ir_if *f0254 = new(mem_ctx) ir_if(operand(r0255).val);
         exec_list *const f0254_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0254->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0257 = equal(r021E, body.constant(int(2047)));
            ir_if *f0256 = new(mem_ctx) ir_if(operand(r0257).val);
            exec_list *const f0256_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0256->then_instructions;

               ir_variable *const r0258 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0258, swizzle_x(r020C), 0x01));

               ir_variable *const r0259 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0259, swizzle_x(r020D), 0x01));

               body.emit(assign(r0258, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r0259, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r025A = bit_or(r021C, swizzle_x(r020C));
               ir_expression *const r025B = nequal(r025A, body.constant(0u));
               ir_swizzle *const r025C = swizzle(r025B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r025D = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r025E = gequal(r025D, body.constant(4292870144u));
               ir_expression *const r025F = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r0260 = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r0261 = nequal(r0260, body.constant(0u));
               ir_expression *const r0262 = logic_or(r025F, r0261);
               ir_expression *const r0263 = logic_and(r025E, r0262);
               ir_swizzle *const r0264 = swizzle(r0263, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0265 = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r0266 = gequal(r0265, body.constant(4292870144u));
               ir_expression *const r0267 = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r0268 = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r0269 = nequal(r0268, body.constant(0u));
               ir_expression *const r026A = logic_or(r0267, r0269);
               ir_expression *const r026B = logic_and(r0266, r026A);
               ir_swizzle *const r026C = swizzle(r026B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r026D = expr(ir_triop_csel, r026C, r0259, r0258);
               ir_expression *const r026E = expr(ir_triop_csel, r0264, r026D, r0259);
               body.emit(assign(r020F, expr(ir_triop_csel, r025C, r026E, r020C), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0256->else_instructions;

               ir_variable *const r026F = body.make_temp(glsl_type::int_type, "mix_retval");
               ir_expression *const r0270 = equal(r0221, body.constant(int(0)));
               ir_expression *const r0271 = add(r0224, body.constant(int(-1)));
               body.emit(assign(r026F, expr(ir_triop_csel, r0270, r0271, r0224), 0x01));

               body.emit(assign(r0210, r026F, 0x01));

               ir_variable *const r0272 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0273 = equal(r0221, body.constant(int(0)));
               ir_expression *const r0274 = bit_or(r021D, body.constant(1048576u));
               body.emit(assign(r0272, expr(ir_triop_csel, r0273, r021D, r0274), 0x01));

               ir_variable *const r0275 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0275);
               ir_variable *const r0276 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0277 = neg(r026F);
               body.emit(assign(r0276, bit_and(r0277, body.constant(int(31))), 0x01));

               ir_variable *const r0278 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0279 = less(r026F, body.constant(int(32)));
               ir_expression *const r027A = bit_or(body.constant(0u), swizzle_x(r020D));
               body.emit(assign(r0278, expr(ir_triop_csel, r0279, body.constant(0u), r027A), 0x01));

               ir_expression *const r027B = less(r026F, body.constant(int(32)));
               ir_expression *const r027C = lshift(swizzle_x(r020D), r0276);
               ir_expression *const r027D = less(r026F, body.constant(int(64)));
               ir_expression *const r027E = lshift(r0272, r0276);
               ir_expression *const r027F = equal(r026F, body.constant(int(64)));
               ir_expression *const r0280 = nequal(r0272, body.constant(0u));
               ir_expression *const r0281 = expr(ir_unop_b2i, r0280);
               ir_expression *const r0282 = expr(ir_unop_i2u, r0281);
               ir_expression *const r0283 = expr(ir_triop_csel, r027F, r0272, r0282);
               ir_expression *const r0284 = expr(ir_triop_csel, r027D, r027E, r0283);
               ir_expression *const r0285 = expr(ir_triop_csel, r027B, r027C, r0284);
               ir_expression *const r0286 = nequal(r0278, body.constant(0u));
               ir_expression *const r0287 = expr(ir_unop_b2i, r0286);
               ir_expression *const r0288 = expr(ir_unop_i2u, r0287);
               body.emit(assign(r0275, bit_or(r0285, r0288), 0x01));

               ir_variable *const r0289 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r028A = equal(r026F, body.constant(int(0)));
               ir_expression *const r028B = equal(r026F, body.constant(int(32)));
               ir_expression *const r028C = expr(ir_triop_csel, r028B, swizzle_x(r020D), r0275);
               body.emit(assign(r0289, expr(ir_triop_csel, r028A, r0278, r028C), 0x01));

               body.emit(assign(r0275, r0289, 0x01));

               ir_expression *const r028D = equal(r026F, body.constant(int(0)));
               ir_expression *const r028E = equal(r026F, body.constant(int(32)));
               ir_expression *const r028F = less(r026F, body.constant(int(32)));
               ir_expression *const r0290 = rshift(r0272, r026F);
               ir_expression *const r0291 = expr(ir_triop_csel, r028F, r0290, body.constant(0u));
               ir_expression *const r0292 = expr(ir_triop_csel, r028E, body.constant(0u), r0291);
               body.emit(assign(r0215, expr(ir_triop_csel, r028D, r0272, r0292), 0x01));

               ir_expression *const r0293 = equal(r026F, body.constant(int(0)));
               ir_expression *const r0294 = equal(r026F, body.constant(int(32)));
               ir_expression *const r0295 = less(r026F, body.constant(int(32)));
               ir_expression *const r0296 = lshift(r0272, r0276);
               ir_expression *const r0297 = rshift(swizzle_x(r020D), r026F);
               ir_expression *const r0298 = bit_or(r0296, r0297);
               ir_expression *const r0299 = less(r026F, body.constant(int(64)));
               ir_expression *const r029A = bit_and(r026F, body.constant(int(31)));
               ir_expression *const r029B = rshift(r0272, r029A);
               ir_expression *const r029C = expr(ir_triop_csel, r0299, r029B, body.constant(0u));
               ir_expression *const r029D = expr(ir_triop_csel, r0295, r0298, r029C);
               ir_expression *const r029E = expr(ir_triop_csel, r0294, r0272, r029D);
               body.emit(assign(r0216, expr(ir_triop_csel, r0293, swizzle_x(r020D), r029E), 0x01));

               body.emit(assign(r0228, r0289, 0x01));

               body.emit(assign(r0227, r021E, 0x01));


            body.instructions = f0256_parent_instructions;
            body.emit(f0256);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0254->else_instructions;

            /* IF CONDITION */
            ir_expression *const r02A0 = less(r0210, body.constant(int(0)));
            ir_if *f029F = new(mem_ctx) ir_if(operand(r02A0).val);
            exec_list *const f029F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f029F->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02A2 = equal(r0221, body.constant(int(2047)));
               ir_if *f02A1 = new(mem_ctx) ir_if(operand(r02A2).val);
               exec_list *const f02A1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02A1->then_instructions;

                  ir_variable *const r02A3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02A3);
                  ir_expression *const r02A4 = lshift(r021A, body.constant(int(31)));
                  body.emit(assign(r02A3, add(r02A4, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r02A3, body.constant(0u), 0x01));

                  ir_variable *const r02A5 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r02A5, swizzle_x(r020C), 0x01));

                  ir_variable *const r02A6 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r02A6, swizzle_x(r020D), 0x01));

                  body.emit(assign(r02A5, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

                  body.emit(assign(r02A6, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

                  ir_expression *const r02A7 = bit_or(r0215, r0216);
                  ir_expression *const r02A8 = nequal(r02A7, body.constant(0u));
                  ir_swizzle *const r02A9 = swizzle(r02A8, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r02AA = lshift(swizzle_y(r020C), body.constant(int(1)));
                  ir_expression *const r02AB = gequal(r02AA, body.constant(4292870144u));
                  ir_expression *const r02AC = nequal(swizzle_x(r020C), body.constant(0u));
                  ir_expression *const r02AD = bit_and(swizzle_y(r020C), body.constant(1048575u));
                  ir_expression *const r02AE = nequal(r02AD, body.constant(0u));
                  ir_expression *const r02AF = logic_or(r02AC, r02AE);
                  ir_expression *const r02B0 = logic_and(r02AB, r02AF);
                  ir_swizzle *const r02B1 = swizzle(r02B0, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r02B2 = lshift(swizzle_y(r020D), body.constant(int(1)));
                  ir_expression *const r02B3 = gequal(r02B2, body.constant(4292870144u));
                  ir_expression *const r02B4 = nequal(swizzle_x(r020D), body.constant(0u));
                  ir_expression *const r02B5 = bit_and(swizzle_y(r020D), body.constant(1048575u));
                  ir_expression *const r02B6 = nequal(r02B5, body.constant(0u));
                  ir_expression *const r02B7 = logic_or(r02B4, r02B6);
                  ir_expression *const r02B8 = logic_and(r02B3, r02B7);
                  ir_swizzle *const r02B9 = swizzle(r02B8, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r02BA = expr(ir_triop_csel, r02B9, r02A6, r02A5);
                  ir_expression *const r02BB = expr(ir_triop_csel, r02B1, r02BA, r02A6);
                  body.emit(assign(r020F, expr(ir_triop_csel, r02A9, r02BB, r02A3), 0x03));

                  body.emit(assign(r020E, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02A1->else_instructions;

                  ir_variable *const r02BC = body.make_temp(glsl_type::int_type, "mix_retval");
                  ir_expression *const r02BD = equal(r021E, body.constant(int(0)));
                  ir_expression *const r02BE = add(r0210, body.constant(int(1)));
                  body.emit(assign(r02BC, expr(ir_triop_csel, r02BD, r02BE, r0210), 0x01));

                  body.emit(assign(r0210, r02BC, 0x01));

                  ir_variable *const r02BF = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r02C0 = equal(r021E, body.constant(int(0)));
                  ir_expression *const r02C1 = bit_or(r021C, body.constant(1048576u));
                  body.emit(assign(r02BF, expr(ir_triop_csel, r02C0, r021C, r02C1), 0x01));

                  ir_variable *const r02C2 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r02C2, neg(r02BC), 0x01));

                  ir_variable *const r02C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r02C3);
                  ir_variable *const r02C4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r02C5 = neg(r02C2);
                  body.emit(assign(r02C4, bit_and(r02C5, body.constant(int(31))), 0x01));

                  ir_variable *const r02C6 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r02C7 = less(r02C2, body.constant(int(32)));
                  ir_expression *const r02C8 = bit_or(body.constant(0u), swizzle_x(r020C));
                  body.emit(assign(r02C6, expr(ir_triop_csel, r02C7, body.constant(0u), r02C8), 0x01));

                  ir_expression *const r02C9 = less(r02C2, body.constant(int(32)));
                  ir_expression *const r02CA = lshift(swizzle_x(r020C), r02C4);
                  ir_expression *const r02CB = less(r02C2, body.constant(int(64)));
                  ir_expression *const r02CC = lshift(r02BF, r02C4);
                  ir_expression *const r02CD = equal(r02C2, body.constant(int(64)));
                  ir_expression *const r02CE = nequal(r02BF, body.constant(0u));
                  ir_expression *const r02CF = expr(ir_unop_b2i, r02CE);
                  ir_expression *const r02D0 = expr(ir_unop_i2u, r02CF);
                  ir_expression *const r02D1 = expr(ir_triop_csel, r02CD, r02BF, r02D0);
                  ir_expression *const r02D2 = expr(ir_triop_csel, r02CB, r02CC, r02D1);
                  ir_expression *const r02D3 = expr(ir_triop_csel, r02C9, r02CA, r02D2);
                  ir_expression *const r02D4 = nequal(r02C6, body.constant(0u));
                  ir_expression *const r02D5 = expr(ir_unop_b2i, r02D4);
                  ir_expression *const r02D6 = expr(ir_unop_i2u, r02D5);
                  body.emit(assign(r02C3, bit_or(r02D3, r02D6), 0x01));

                  ir_variable *const r02D7 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r02D8 = equal(r02C2, body.constant(int(0)));
                  ir_expression *const r02D9 = equal(r02C2, body.constant(int(32)));
                  ir_expression *const r02DA = expr(ir_triop_csel, r02D9, swizzle_x(r020C), r02C3);
                  body.emit(assign(r02D7, expr(ir_triop_csel, r02D8, r02C6, r02DA), 0x01));

                  body.emit(assign(r02C3, r02D7, 0x01));

                  ir_expression *const r02DB = equal(r02C2, body.constant(int(0)));
                  ir_expression *const r02DC = equal(r02C2, body.constant(int(32)));
                  ir_expression *const r02DD = less(r02C2, body.constant(int(32)));
                  ir_expression *const r02DE = rshift(r02BF, r02C2);
                  ir_expression *const r02DF = expr(ir_triop_csel, r02DD, r02DE, body.constant(0u));
                  ir_expression *const r02E0 = expr(ir_triop_csel, r02DC, body.constant(0u), r02DF);
                  body.emit(assign(r0217, expr(ir_triop_csel, r02DB, r02BF, r02E0), 0x01));

                  ir_expression *const r02E1 = equal(r02C2, body.constant(int(0)));
                  ir_expression *const r02E2 = equal(r02C2, body.constant(int(32)));
                  ir_expression *const r02E3 = less(r02C2, body.constant(int(32)));
                  ir_expression *const r02E4 = lshift(r02BF, r02C4);
                  ir_expression *const r02E5 = rshift(swizzle_x(r020C), r02C2);
                  ir_expression *const r02E6 = bit_or(r02E4, r02E5);
                  ir_expression *const r02E7 = less(r02C2, body.constant(int(64)));
                  ir_expression *const r02E8 = bit_and(r02C2, body.constant(int(31)));
                  ir_expression *const r02E9 = rshift(r02BF, r02E8);
                  ir_expression *const r02EA = expr(ir_triop_csel, r02E7, r02E9, body.constant(0u));
                  ir_expression *const r02EB = expr(ir_triop_csel, r02E3, r02E6, r02EA);
                  ir_expression *const r02EC = expr(ir_triop_csel, r02E2, r02BF, r02EB);
                  body.emit(assign(r0218, expr(ir_triop_csel, r02E1, swizzle_x(r020C), r02EC), 0x01));

                  body.emit(assign(r0228, r02D7, 0x01));

                  body.emit(assign(r0227, r0221, 0x01));


               body.instructions = f02A1_parent_instructions;
               body.emit(f02A1);

               /* END IF */


            body.instructions = f029F_parent_instructions;
            body.emit(f029F);

            /* END IF */


         body.instructions = f0254_parent_instructions;
         body.emit(f0254);

         /* END IF */


      body.instructions = f022A_parent_instructions;
      body.emit(f022A);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02ED = new(mem_ctx) ir_if(operand(r020E).val);
      exec_list *const f02ED_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02ED->then_instructions;

         /* IF CONDITION */
         ir_expression *const r02EF = expr(ir_unop_logic_not, r0229);
         ir_if *f02EE = new(mem_ctx) ir_if(operand(r02EF).val);
         exec_list *const f02EE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02EE->then_instructions;

            body.emit(assign(r0217, bit_or(r0217, body.constant(1048576u)), 0x01));

            ir_variable *const r02F0 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r02F1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            body.emit(assign(r02F1, add(r0218, r0216), 0x01));

            ir_expression *const r02F2 = add(r0217, r0215);
            ir_expression *const r02F3 = less(r02F1, r0218);
            ir_expression *const r02F4 = expr(ir_unop_b2i, r02F3);
            ir_expression *const r02F5 = expr(ir_unop_i2u, r02F4);
            body.emit(assign(r02F0, add(r02F2, r02F5), 0x01));

            body.emit(assign(r0212, r02F0, 0x01));

            body.emit(assign(r0211, r02F1, 0x01));

            body.emit(assign(r0227, add(r0227, body.constant(int(-1))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02F7 = gequal(r02F0, body.constant(2097152u));
            ir_if *f02F6 = new(mem_ctx) ir_if(operand(r02F7).val);
            exec_list *const f02F6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02F6->then_instructions;

               body.emit(assign(r0212, rshift(r02F0, body.constant(int(1))), 0x01));

               ir_expression *const r02F8 = lshift(r02F0, body.constant(int(31)));
               ir_expression *const r02F9 = rshift(r02F1, body.constant(int(1)));
               body.emit(assign(r0211, bit_or(r02F8, r02F9), 0x01));

               ir_expression *const r02FA = lshift(r02F1, body.constant(int(31)));
               ir_expression *const r02FB = nequal(r0228, body.constant(0u));
               ir_expression *const r02FC = expr(ir_unop_b2i, r02FB);
               ir_expression *const r02FD = expr(ir_unop_i2u, r02FC);
               body.emit(assign(r0228, bit_or(r02FA, r02FD), 0x01));

               body.emit(assign(r0227, add(r0227, body.constant(int(1))), 0x01));


            body.instructions = f02F6_parent_instructions;
            body.emit(f02F6);

            /* END IF */


         body.instructions = f02EE_parent_instructions;
         body.emit(f02EE);

         /* END IF */

         ir_variable *const r02FE = body.make_temp(glsl_type::int_type, "zExp");
         body.emit(assign(r02FE, r0227, 0x01));

         ir_variable *const r02FF = body.make_temp(glsl_type::uint_type, "zFrac0");
         body.emit(assign(r02FF, r0212, 0x01));

         ir_variable *const r0300 = body.make_temp(glsl_type::uint_type, "zFrac1");
         body.emit(assign(r0300, r0211, 0x01));

         ir_variable *const r0301 = body.make_temp(glsl_type::uint_type, "zFrac2");
         body.emit(assign(r0301, r0228, 0x01));

         ir_variable *const r0302 = body.make_temp(glsl_type::bool_type, "execute_flag");
         body.emit(assign(r0302, body.constant(true), 0x01));

         ir_variable *const r0303 = body.make_temp(glsl_type::uvec2_type, "return_value");
         ir_variable *const r0304 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
         body.emit(r0304);
         ir_expression *const r0305 = expr(ir_unop_u2i, r0228);
         body.emit(assign(r0304, less(r0305, body.constant(int(0))), 0x01));

         /* IF CONDITION */
         ir_expression *const r0307 = gequal(r0227, body.constant(int(2045)));
         ir_if *f0306 = new(mem_ctx) ir_if(operand(r0307).val);
         exec_list *const f0306_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0306->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0309 = less(body.constant(int(2045)), r0227);
            ir_expression *const r030A = equal(r0227, body.constant(int(2045)));
            ir_expression *const r030B = equal(body.constant(2097151u), r0212);
            ir_expression *const r030C = equal(body.constant(4294967295u), r0211);
            ir_expression *const r030D = logic_and(r030B, r030C);
            ir_expression *const r030E = logic_and(r030A, r030D);
            ir_expression *const r030F = logic_and(r030E, r0304);
            ir_expression *const r0310 = logic_or(r0309, r030F);
            ir_if *f0308 = new(mem_ctx) ir_if(operand(r0310).val);
            exec_list *const f0308_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0308->then_instructions;

               ir_variable *const r0311 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0311);
               ir_expression *const r0312 = lshift(r021A, body.constant(int(31)));
               body.emit(assign(r0311, add(r0312, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0311, body.constant(0u), 0x01));

               body.emit(assign(r0303, r0311, 0x03));

               body.emit(assign(r0302, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0308->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0314 = less(r0227, body.constant(int(0)));
               ir_if *f0313 = new(mem_ctx) ir_if(operand(r0314).val);
               exec_list *const f0313_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0313->then_instructions;

                  ir_variable *const r0315 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r0315, neg(r0227), 0x01));

                  ir_variable *const r0316 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0316);
                  ir_variable *const r0317 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r0318 = neg(r0315);
                  body.emit(assign(r0317, bit_and(r0318, body.constant(int(31))), 0x01));

                  ir_variable *const r0319 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r031A = less(r0315, body.constant(int(32)));
                  ir_expression *const r031B = bit_or(r0228, r0211);
                  body.emit(assign(r0319, expr(ir_triop_csel, r031A, r0228, r031B), 0x01));

                  ir_expression *const r031C = less(r0315, body.constant(int(32)));
                  ir_expression *const r031D = lshift(r0211, r0317);
                  ir_expression *const r031E = less(r0315, body.constant(int(64)));
                  ir_expression *const r031F = lshift(r0212, r0317);
                  ir_expression *const r0320 = equal(r0315, body.constant(int(64)));
                  ir_expression *const r0321 = nequal(r0212, body.constant(0u));
                  ir_expression *const r0322 = expr(ir_unop_b2i, r0321);
                  ir_expression *const r0323 = expr(ir_unop_i2u, r0322);
                  ir_expression *const r0324 = expr(ir_triop_csel, r0320, r0212, r0323);
                  ir_expression *const r0325 = expr(ir_triop_csel, r031E, r031F, r0324);
                  ir_expression *const r0326 = expr(ir_triop_csel, r031C, r031D, r0325);
                  ir_expression *const r0327 = nequal(r0319, body.constant(0u));
                  ir_expression *const r0328 = expr(ir_unop_b2i, r0327);
                  ir_expression *const r0329 = expr(ir_unop_i2u, r0328);
                  body.emit(assign(r0316, bit_or(r0326, r0329), 0x01));

                  ir_variable *const r032A = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r032B = equal(r0315, body.constant(int(0)));
                  ir_expression *const r032C = equal(r0315, body.constant(int(32)));
                  ir_expression *const r032D = expr(ir_triop_csel, r032C, r0211, r0316);
                  body.emit(assign(r032A, expr(ir_triop_csel, r032B, r0319, r032D), 0x01));

                  body.emit(assign(r0316, r032A, 0x01));

                  ir_expression *const r032E = equal(r0315, body.constant(int(0)));
                  ir_expression *const r032F = equal(r0315, body.constant(int(32)));
                  ir_expression *const r0330 = less(r0315, body.constant(int(32)));
                  ir_expression *const r0331 = rshift(r0212, r0315);
                  ir_expression *const r0332 = expr(ir_triop_csel, r0330, r0331, body.constant(0u));
                  ir_expression *const r0333 = expr(ir_triop_csel, r032F, body.constant(0u), r0332);
                  body.emit(assign(r02FF, expr(ir_triop_csel, r032E, r0212, r0333), 0x01));

                  ir_expression *const r0334 = equal(r0315, body.constant(int(0)));
                  ir_expression *const r0335 = equal(r0315, body.constant(int(32)));
                  ir_expression *const r0336 = less(r0315, body.constant(int(32)));
                  ir_expression *const r0337 = lshift(r0212, r0317);
                  ir_expression *const r0338 = rshift(r0211, r0315);
                  ir_expression *const r0339 = bit_or(r0337, r0338);
                  ir_expression *const r033A = less(r0315, body.constant(int(64)));
                  ir_expression *const r033B = bit_and(r0315, body.constant(int(31)));
                  ir_expression *const r033C = rshift(r0212, r033B);
                  ir_expression *const r033D = expr(ir_triop_csel, r033A, r033C, body.constant(0u));
                  ir_expression *const r033E = expr(ir_triop_csel, r0336, r0339, r033D);
                  ir_expression *const r033F = expr(ir_triop_csel, r0335, r0212, r033E);
                  body.emit(assign(r0300, expr(ir_triop_csel, r0334, r0211, r033F), 0x01));

                  body.emit(assign(r0301, r032A, 0x01));

                  body.emit(assign(r02FE, body.constant(int(0)), 0x01));

                  body.emit(assign(r0304, less(r032A, body.constant(0u)), 0x01));


               body.instructions = f0313_parent_instructions;
               body.emit(f0313);

               /* END IF */


            body.instructions = f0308_parent_instructions;
            body.emit(f0308);

            /* END IF */


         body.instructions = f0306_parent_instructions;
         body.emit(f0306);

         /* END IF */

         /* IF CONDITION */
         ir_if *f0340 = new(mem_ctx) ir_if(operand(r0302).val);
         exec_list *const f0340_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0340->then_instructions;

            /* IF CONDITION */
            ir_if *f0341 = new(mem_ctx) ir_if(operand(r0304).val);
            exec_list *const f0341_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0341->then_instructions;

               ir_variable *const r0342 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0342, add(r0300, body.constant(1u)), 0x01));

               ir_expression *const r0343 = less(r0342, r0300);
               ir_expression *const r0344 = expr(ir_unop_b2i, r0343);
               ir_expression *const r0345 = expr(ir_unop_i2u, r0344);
               body.emit(assign(r02FF, add(r02FF, r0345), 0x01));

               ir_expression *const r0346 = equal(r0301, body.constant(0u));
               ir_expression *const r0347 = expr(ir_unop_b2i, r0346);
               ir_expression *const r0348 = expr(ir_unop_i2u, r0347);
               ir_expression *const r0349 = add(r0301, r0348);
               ir_expression *const r034A = bit_and(r0349, body.constant(1u));
               ir_expression *const r034B = expr(ir_unop_bit_not, r034A);
               body.emit(assign(r0300, bit_and(r0342, r034B), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0341->else_instructions;

               ir_expression *const r034C = bit_or(r02FF, r0300);
               ir_expression *const r034D = equal(r034C, body.constant(0u));
               body.emit(assign(r02FE, expr(ir_triop_csel, r034D, body.constant(int(0)), r02FE), 0x01));


            body.instructions = f0341_parent_instructions;
            body.emit(f0341);

            /* END IF */

            ir_variable *const r034E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r034E);
            ir_expression *const r034F = lshift(r021A, body.constant(int(31)));
            ir_expression *const r0350 = expr(ir_unop_i2u, r02FE);
            ir_expression *const r0351 = lshift(r0350, body.constant(int(20)));
            ir_expression *const r0352 = add(r034F, r0351);
            body.emit(assign(r034E, add(r0352, r02FF), 0x02));

            body.emit(assign(r034E, r0300, 0x01));

            body.emit(assign(r0303, r034E, 0x03));

            body.emit(assign(r0302, body.constant(false), 0x01));


         body.instructions = f0340_parent_instructions;
         body.emit(f0340);

         /* END IF */

         body.emit(assign(r020F, r0303, 0x03));

         body.emit(assign(r020E, body.constant(false), 0x01));


      body.instructions = f02ED_parent_instructions;
      body.emit(f02ED);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0225->else_instructions;

      ir_variable *const r0353 = new(mem_ctx) ir_variable(glsl_type::bool_type, "blta", ir_var_auto);
      body.emit(r0353);
      ir_variable *const r0354 = new(mem_ctx) ir_variable(glsl_type::bool_type, "zexp_normal", ir_var_auto);
      body.emit(r0354);
      ir_variable *const r0355 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r0355);
      ir_variable *const r0356 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r0357 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0357, lshift(r0218, body.constant(int(10))), 0x01));

      ir_expression *const r0358 = lshift(r0217, body.constant(int(10)));
      ir_expression *const r0359 = rshift(r0218, body.constant(int(22)));
      body.emit(assign(r0356, bit_or(r0358, r0359), 0x01));

      body.emit(assign(r0217, r0356, 0x01));

      body.emit(assign(r0218, r0357, 0x01));

      ir_variable *const r035A = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r035B = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r035B, lshift(r0216, body.constant(int(10))), 0x01));

      ir_expression *const r035C = lshift(r0215, body.constant(int(10)));
      ir_expression *const r035D = rshift(r0216, body.constant(int(22)));
      body.emit(assign(r035A, bit_or(r035C, r035D), 0x01));

      body.emit(assign(r0215, r035A, 0x01));

      body.emit(assign(r0216, r035B, 0x01));

      /* IF CONDITION */
      ir_expression *const r035F = less(body.constant(int(0)), r0210);
      ir_if *f035E = new(mem_ctx) ir_if(operand(r035F).val);
      exec_list *const f035E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f035E->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0361 = equal(r021E, body.constant(int(2047)));
         ir_if *f0360 = new(mem_ctx) ir_if(operand(r0361).val);
         exec_list *const f0360_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0360->then_instructions;

            ir_variable *const r0362 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0362, swizzle_x(r020C), 0x01));

            ir_variable *const r0363 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0363, swizzle_x(r020D), 0x01));

            body.emit(assign(r0362, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

            body.emit(assign(r0363, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

            ir_expression *const r0364 = bit_or(r0356, r0357);
            ir_expression *const r0365 = nequal(r0364, body.constant(0u));
            ir_swizzle *const r0366 = swizzle(r0365, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0367 = lshift(swizzle_y(r020C), body.constant(int(1)));
            ir_expression *const r0368 = gequal(r0367, body.constant(4292870144u));
            ir_expression *const r0369 = nequal(swizzle_x(r020C), body.constant(0u));
            ir_expression *const r036A = bit_and(swizzle_y(r020C), body.constant(1048575u));
            ir_expression *const r036B = nequal(r036A, body.constant(0u));
            ir_expression *const r036C = logic_or(r0369, r036B);
            ir_expression *const r036D = logic_and(r0368, r036C);
            ir_swizzle *const r036E = swizzle(r036D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r036F = lshift(swizzle_y(r020D), body.constant(int(1)));
            ir_expression *const r0370 = gequal(r036F, body.constant(4292870144u));
            ir_expression *const r0371 = nequal(swizzle_x(r020D), body.constant(0u));
            ir_expression *const r0372 = bit_and(swizzle_y(r020D), body.constant(1048575u));
            ir_expression *const r0373 = nequal(r0372, body.constant(0u));
            ir_expression *const r0374 = logic_or(r0371, r0373);
            ir_expression *const r0375 = logic_and(r0370, r0374);
            ir_swizzle *const r0376 = swizzle(r0375, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0377 = expr(ir_triop_csel, r0376, r0363, r0362);
            ir_expression *const r0378 = expr(ir_triop_csel, r036E, r0377, r0363);
            body.emit(assign(r020F, expr(ir_triop_csel, r0366, r0378, r020C), 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0360->else_instructions;

            ir_variable *const r0379 = body.make_temp(glsl_type::int_type, "mix_retval");
            ir_expression *const r037A = equal(r0221, body.constant(int(0)));
            ir_expression *const r037B = add(r0210, body.constant(int(-1)));
            body.emit(assign(r0379, expr(ir_triop_csel, r037A, r037B, r0210), 0x01));

            body.emit(assign(r0210, r0379, 0x01));

            ir_variable *const r037C = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r037D = equal(r0221, body.constant(int(0)));
            ir_expression *const r037E = bit_or(r035A, body.constant(1073741824u));
            body.emit(assign(r037C, expr(ir_triop_csel, r037D, r035A, r037E), 0x01));

            ir_variable *const r037F = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r0380 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0380);
            ir_variable *const r0381 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0382 = neg(r0379);
            body.emit(assign(r0381, bit_and(r0382, body.constant(int(31))), 0x01));

            ir_expression *const r0383 = bit_or(r037C, r035B);
            ir_expression *const r0384 = nequal(r0383, body.constant(0u));
            ir_expression *const r0385 = expr(ir_unop_b2i, r0384);
            body.emit(assign(r0380, expr(ir_unop_i2u, r0385), 0x01));

            ir_variable *const r0386 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0387 = equal(r0379, body.constant(int(0)));
            ir_expression *const r0388 = less(r0379, body.constant(int(32)));
            ir_expression *const r0389 = lshift(r037C, r0381);
            ir_expression *const r038A = rshift(r035B, r0379);
            ir_expression *const r038B = bit_or(r0389, r038A);
            ir_expression *const r038C = lshift(r035B, r0381);
            ir_expression *const r038D = nequal(r038C, body.constant(0u));
            ir_expression *const r038E = expr(ir_unop_b2i, r038D);
            ir_expression *const r038F = expr(ir_unop_i2u, r038E);
            ir_expression *const r0390 = bit_or(r038B, r038F);
            ir_expression *const r0391 = equal(r0379, body.constant(int(32)));
            ir_expression *const r0392 = nequal(r035B, body.constant(0u));
            ir_expression *const r0393 = expr(ir_unop_b2i, r0392);
            ir_expression *const r0394 = expr(ir_unop_i2u, r0393);
            ir_expression *const r0395 = bit_or(r037C, r0394);
            ir_expression *const r0396 = less(r0379, body.constant(int(64)));
            ir_expression *const r0397 = bit_and(r0379, body.constant(int(31)));
            ir_expression *const r0398 = rshift(r037C, r0397);
            ir_expression *const r0399 = lshift(r037C, r0381);
            ir_expression *const r039A = bit_or(r0399, r035B);
            ir_expression *const r039B = nequal(r039A, body.constant(0u));
            ir_expression *const r039C = expr(ir_unop_b2i, r039B);
            ir_expression *const r039D = expr(ir_unop_i2u, r039C);
            ir_expression *const r039E = bit_or(r0398, r039D);
            ir_expression *const r039F = expr(ir_triop_csel, r0396, r039E, r0380);
            ir_expression *const r03A0 = expr(ir_triop_csel, r0391, r0395, r039F);
            ir_expression *const r03A1 = expr(ir_triop_csel, r0388, r0390, r03A0);
            body.emit(assign(r0386, expr(ir_triop_csel, r0387, r035B, r03A1), 0x01));

            body.emit(assign(r0380, r0386, 0x01));

            ir_expression *const r03A2 = less(r0379, body.constant(int(32)));
            ir_expression *const r03A3 = rshift(r037C, r0379);
            ir_expression *const r03A4 = equal(r0379, body.constant(int(0)));
            ir_expression *const r03A5 = expr(ir_triop_csel, r03A4, r037C, body.constant(0u));
            body.emit(assign(r037F, expr(ir_triop_csel, r03A2, r03A3, r03A5), 0x01));

            body.emit(assign(r0215, r037F, 0x01));

            body.emit(assign(r0216, r0386, 0x01));

            body.emit(assign(r0217, bit_or(r0356, body.constant(1073741824u)), 0x01));

            ir_variable *const r03A6 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r03A7 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r03A7, sub(r0357, r0386), 0x01));

            ir_expression *const r03A8 = sub(r0217, r037F);
            ir_expression *const r03A9 = less(r0357, r0386);
            ir_expression *const r03AA = expr(ir_unop_b2i, r03A9);
            ir_expression *const r03AB = expr(ir_unop_i2u, r03AA);
            body.emit(assign(r03A6, sub(r03A8, r03AB), 0x01));

            body.emit(assign(r0212, r03A6, 0x01));

            body.emit(assign(r0211, r03A7, 0x01));

            body.emit(assign(r0355, add(r021E, body.constant(int(-1))), 0x01));

            ir_variable *const r03AC = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03AC, add(r0355, body.constant(int(-10))), 0x01));

            ir_variable *const r03AD = body.make_temp(glsl_type::uint_type, "zFrac0");
            ir_variable *const r03AE = body.make_temp(glsl_type::uint_type, "zFrac1");
            ir_variable *const r03AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03AF);
            ir_variable *const r03B0 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03B0);
            ir_expression *const r03B1 = equal(r03A6, body.constant(0u));
            ir_expression *const r03B2 = add(r03AC, body.constant(int(-32)));
            body.emit(assign(r03AC, expr(ir_triop_csel, r03B1, r03B2, r03AC), 0x01));

            ir_variable *const r03B3 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03B4 = equal(r03A6, body.constant(0u));
            body.emit(assign(r03B3, expr(ir_triop_csel, r03B4, body.constant(0u), r03A7), 0x01));

            body.emit(assign(r03AE, r03B3, 0x01));

            ir_variable *const r03B5 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03B6 = equal(r03A6, body.constant(0u));
            body.emit(assign(r03B5, expr(ir_triop_csel, r03B6, r03B3, r03A6), 0x01));

            body.emit(assign(r03AD, r03B5, 0x01));

            ir_expression *const r03B7 = equal(r03B5, body.constant(0u));
            ir_expression *const r03B8 = expr(ir_unop_find_msb, r03B5);
            ir_expression *const r03B9 = sub(body.constant(int(31)), r03B8);
            ir_expression *const r03BA = expr(ir_triop_csel, r03B7, body.constant(int(32)), r03B9);
            body.emit(assign(r03B0, add(r03BA, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03BC = gequal(r03B0, body.constant(int(0)));
            ir_if *f03BB = new(mem_ctx) ir_if(operand(r03BC).val);
            exec_list *const f03BB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03BB->then_instructions;

               body.emit(assign(r03AF, body.constant(0u), 0x01));

               ir_expression *const r03BD = equal(r03B0, body.constant(int(0)));
               ir_expression *const r03BE = lshift(r03B5, r03B0);
               ir_expression *const r03BF = neg(r03B0);
               ir_expression *const r03C0 = bit_and(r03BF, body.constant(int(31)));
               ir_expression *const r03C1 = rshift(r03B3, r03C0);
               ir_expression *const r03C2 = bit_or(r03BE, r03C1);
               body.emit(assign(r03AD, expr(ir_triop_csel, r03BD, r03B5, r03C2), 0x01));

               body.emit(assign(r03AE, lshift(r03B3, r03B0), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03BB->else_instructions;

               ir_variable *const r03C3 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r03C3, neg(r03B0), 0x01));

               ir_variable *const r03C4 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               ir_variable *const r03C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r03C5);
               ir_variable *const r03C6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r03C7 = neg(r03C3);
               body.emit(assign(r03C6, bit_and(r03C7, body.constant(int(31))), 0x01));

               ir_variable *const r03C8 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r03C9 = less(r03C3, body.constant(int(32)));
               ir_expression *const r03CA = bit_or(body.constant(0u), r03AE);
               body.emit(assign(r03C8, expr(ir_triop_csel, r03C9, body.constant(0u), r03CA), 0x01));

               ir_expression *const r03CB = less(r03C3, body.constant(int(32)));
               ir_expression *const r03CC = lshift(r03AE, r03C6);
               ir_expression *const r03CD = less(r03C3, body.constant(int(64)));
               ir_expression *const r03CE = lshift(r03AD, r03C6);
               ir_expression *const r03CF = equal(r03C3, body.constant(int(64)));
               ir_expression *const r03D0 = nequal(r03AD, body.constant(0u));
               ir_expression *const r03D1 = expr(ir_unop_b2i, r03D0);
               ir_expression *const r03D2 = expr(ir_unop_i2u, r03D1);
               ir_expression *const r03D3 = expr(ir_triop_csel, r03CF, r03AD, r03D2);
               ir_expression *const r03D4 = expr(ir_triop_csel, r03CD, r03CE, r03D3);
               ir_expression *const r03D5 = expr(ir_triop_csel, r03CB, r03CC, r03D4);
               ir_expression *const r03D6 = nequal(r03C8, body.constant(0u));
               ir_expression *const r03D7 = expr(ir_unop_b2i, r03D6);
               ir_expression *const r03D8 = expr(ir_unop_i2u, r03D7);
               body.emit(assign(r03C5, bit_or(r03D5, r03D8), 0x01));

               ir_variable *const r03D9 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r03DA = equal(r03C3, body.constant(int(0)));
               ir_expression *const r03DB = equal(r03C3, body.constant(int(32)));
               ir_expression *const r03DC = expr(ir_triop_csel, r03DB, r03AE, r03C5);
               body.emit(assign(r03D9, expr(ir_triop_csel, r03DA, r03C8, r03DC), 0x01));

               body.emit(assign(r03C5, r03D9, 0x01));

               ir_expression *const r03DD = equal(r03C3, body.constant(int(0)));
               ir_expression *const r03DE = equal(r03C3, body.constant(int(32)));
               ir_expression *const r03DF = less(r03C3, body.constant(int(32)));
               ir_expression *const r03E0 = lshift(r03AD, r03C6);
               ir_expression *const r03E1 = rshift(r03AE, r03C3);
               ir_expression *const r03E2 = bit_or(r03E0, r03E1);
               ir_expression *const r03E3 = less(r03C3, body.constant(int(64)));
               ir_expression *const r03E4 = bit_and(r03C3, body.constant(int(31)));
               ir_expression *const r03E5 = rshift(r03AD, r03E4);
               ir_expression *const r03E6 = expr(ir_triop_csel, r03E3, r03E5, body.constant(0u));
               ir_expression *const r03E7 = expr(ir_triop_csel, r03DF, r03E2, r03E6);
               ir_expression *const r03E8 = expr(ir_triop_csel, r03DE, r03AD, r03E7);
               body.emit(assign(r03C4, expr(ir_triop_csel, r03DD, r03AE, r03E8), 0x01));

               ir_expression *const r03E9 = equal(r03C3, body.constant(int(0)));
               ir_expression *const r03EA = equal(r03C3, body.constant(int(32)));
               ir_expression *const r03EB = less(r03C3, body.constant(int(32)));
               ir_expression *const r03EC = rshift(r03AD, r03C3);
               ir_expression *const r03ED = expr(ir_triop_csel, r03EB, r03EC, body.constant(0u));
               ir_expression *const r03EE = expr(ir_triop_csel, r03EA, body.constant(0u), r03ED);
               body.emit(assign(r03AD, expr(ir_triop_csel, r03E9, r03AD, r03EE), 0x01));

               body.emit(assign(r03AE, r03C4, 0x01));

               body.emit(assign(r03AF, r03D9, 0x01));


            body.instructions = f03BB_parent_instructions;
            body.emit(f03BB);

            /* END IF */

            body.emit(assign(r03AC, sub(r03AC, r03B0), 0x01));

            ir_variable *const r03EF = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03EF, r03AC, 0x01));

            ir_variable *const r03F0 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03F0, r03AD, 0x01));

            ir_variable *const r03F1 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03F1, r03AE, 0x01));

            ir_variable *const r03F2 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r03F2, r03AF, 0x01));

            ir_variable *const r03F3 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r03F3, body.constant(true), 0x01));

            ir_variable *const r03F4 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r03F5 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r03F5);
            ir_expression *const r03F6 = expr(ir_unop_u2i, r03AF);
            body.emit(assign(r03F5, less(r03F6, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03F8 = gequal(r03AC, body.constant(int(2045)));
            ir_if *f03F7 = new(mem_ctx) ir_if(operand(r03F8).val);
            exec_list *const f03F7_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03F7->then_instructions;

               /* IF CONDITION */
               ir_expression *const r03FA = less(body.constant(int(2045)), r03AC);
               ir_expression *const r03FB = equal(r03AC, body.constant(int(2045)));
               ir_expression *const r03FC = equal(body.constant(2097151u), r03AD);
               ir_expression *const r03FD = equal(body.constant(4294967295u), r03AE);
               ir_expression *const r03FE = logic_and(r03FC, r03FD);
               ir_expression *const r03FF = logic_and(r03FB, r03FE);
               ir_expression *const r0400 = logic_and(r03FF, r03F5);
               ir_expression *const r0401 = logic_or(r03FA, r0400);
               ir_if *f03F9 = new(mem_ctx) ir_if(operand(r0401).val);
               exec_list *const f03F9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F9->then_instructions;

                  ir_variable *const r0402 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0402);
                  ir_expression *const r0403 = lshift(r021A, body.constant(int(31)));
                  body.emit(assign(r0402, add(r0403, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0402, body.constant(0u), 0x01));

                  body.emit(assign(r03F4, r0402, 0x03));

                  body.emit(assign(r03F3, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03F9->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0405 = less(r03AC, body.constant(int(0)));
                  ir_if *f0404 = new(mem_ctx) ir_if(operand(r0405).val);
                  exec_list *const f0404_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0404->then_instructions;

                     ir_variable *const r0406 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0406, neg(r03AC), 0x01));

                     ir_variable *const r0407 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0407);
                     ir_variable *const r0408 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0409 = neg(r0406);
                     body.emit(assign(r0408, bit_and(r0409, body.constant(int(31))), 0x01));

                     ir_variable *const r040A = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r040B = less(r0406, body.constant(int(32)));
                     ir_expression *const r040C = bit_or(r03AF, r03AE);
                     body.emit(assign(r040A, expr(ir_triop_csel, r040B, r03AF, r040C), 0x01));

                     ir_expression *const r040D = less(r0406, body.constant(int(32)));
                     ir_expression *const r040E = lshift(r03AE, r0408);
                     ir_expression *const r040F = less(r0406, body.constant(int(64)));
                     ir_expression *const r0410 = lshift(r03AD, r0408);
                     ir_expression *const r0411 = equal(r0406, body.constant(int(64)));
                     ir_expression *const r0412 = nequal(r03AD, body.constant(0u));
                     ir_expression *const r0413 = expr(ir_unop_b2i, r0412);
                     ir_expression *const r0414 = expr(ir_unop_i2u, r0413);
                     ir_expression *const r0415 = expr(ir_triop_csel, r0411, r03AD, r0414);
                     ir_expression *const r0416 = expr(ir_triop_csel, r040F, r0410, r0415);
                     ir_expression *const r0417 = expr(ir_triop_csel, r040D, r040E, r0416);
                     ir_expression *const r0418 = nequal(r040A, body.constant(0u));
                     ir_expression *const r0419 = expr(ir_unop_b2i, r0418);
                     ir_expression *const r041A = expr(ir_unop_i2u, r0419);
                     body.emit(assign(r0407, bit_or(r0417, r041A), 0x01));

                     ir_variable *const r041B = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r041C = equal(r0406, body.constant(int(0)));
                     ir_expression *const r041D = equal(r0406, body.constant(int(32)));
                     ir_expression *const r041E = expr(ir_triop_csel, r041D, r03AE, r0407);
                     body.emit(assign(r041B, expr(ir_triop_csel, r041C, r040A, r041E), 0x01));

                     body.emit(assign(r0407, r041B, 0x01));

                     ir_expression *const r041F = equal(r0406, body.constant(int(0)));
                     ir_expression *const r0420 = equal(r0406, body.constant(int(32)));
                     ir_expression *const r0421 = less(r0406, body.constant(int(32)));
                     ir_expression *const r0422 = rshift(r03AD, r0406);
                     ir_expression *const r0423 = expr(ir_triop_csel, r0421, r0422, body.constant(0u));
                     ir_expression *const r0424 = expr(ir_triop_csel, r0420, body.constant(0u), r0423);
                     body.emit(assign(r03F0, expr(ir_triop_csel, r041F, r03AD, r0424), 0x01));

                     ir_expression *const r0425 = equal(r0406, body.constant(int(0)));
                     ir_expression *const r0426 = equal(r0406, body.constant(int(32)));
                     ir_expression *const r0427 = less(r0406, body.constant(int(32)));
                     ir_expression *const r0428 = lshift(r03AD, r0408);
                     ir_expression *const r0429 = rshift(r03AE, r0406);
                     ir_expression *const r042A = bit_or(r0428, r0429);
                     ir_expression *const r042B = less(r0406, body.constant(int(64)));
                     ir_expression *const r042C = bit_and(r0406, body.constant(int(31)));
                     ir_expression *const r042D = rshift(r03AD, r042C);
                     ir_expression *const r042E = expr(ir_triop_csel, r042B, r042D, body.constant(0u));
                     ir_expression *const r042F = expr(ir_triop_csel, r0427, r042A, r042E);
                     ir_expression *const r0430 = expr(ir_triop_csel, r0426, r03AD, r042F);
                     body.emit(assign(r03F1, expr(ir_triop_csel, r0425, r03AE, r0430), 0x01));

                     body.emit(assign(r03F2, r041B, 0x01));

                     body.emit(assign(r03EF, body.constant(int(0)), 0x01));

                     body.emit(assign(r03F5, less(r041B, body.constant(0u)), 0x01));


                  body.instructions = f0404_parent_instructions;
                  body.emit(f0404);

                  /* END IF */


               body.instructions = f03F9_parent_instructions;
               body.emit(f03F9);

               /* END IF */


            body.instructions = f03F7_parent_instructions;
            body.emit(f03F7);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0431 = new(mem_ctx) ir_if(operand(r03F3).val);
            exec_list *const f0431_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0431->then_instructions;

               /* IF CONDITION */
               ir_if *f0432 = new(mem_ctx) ir_if(operand(r03F5).val);
               exec_list *const f0432_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0432->then_instructions;

                  ir_variable *const r0433 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0433, add(r03F1, body.constant(1u)), 0x01));

                  ir_expression *const r0434 = less(r0433, r03F1);
                  ir_expression *const r0435 = expr(ir_unop_b2i, r0434);
                  ir_expression *const r0436 = expr(ir_unop_i2u, r0435);
                  body.emit(assign(r03F0, add(r03F0, r0436), 0x01));

                  ir_expression *const r0437 = equal(r03F2, body.constant(0u));
                  ir_expression *const r0438 = expr(ir_unop_b2i, r0437);
                  ir_expression *const r0439 = expr(ir_unop_i2u, r0438);
                  ir_expression *const r043A = add(r03F2, r0439);
                  ir_expression *const r043B = bit_and(r043A, body.constant(1u));
                  ir_expression *const r043C = expr(ir_unop_bit_not, r043B);
                  body.emit(assign(r03F1, bit_and(r0433, r043C), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0432->else_instructions;

                  ir_expression *const r043D = bit_or(r03F0, r03F1);
                  ir_expression *const r043E = equal(r043D, body.constant(0u));
                  body.emit(assign(r03EF, expr(ir_triop_csel, r043E, body.constant(int(0)), r03EF), 0x01));


               body.instructions = f0432_parent_instructions;
               body.emit(f0432);

               /* END IF */

               ir_variable *const r043F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r043F);
               ir_expression *const r0440 = lshift(r021A, body.constant(int(31)));
               ir_expression *const r0441 = expr(ir_unop_i2u, r03EF);
               ir_expression *const r0442 = lshift(r0441, body.constant(int(20)));
               ir_expression *const r0443 = add(r0440, r0442);
               body.emit(assign(r043F, add(r0443, r03F0), 0x02));

               body.emit(assign(r043F, r03F1, 0x01));

               body.emit(assign(r03F4, r043F, 0x03));

               body.emit(assign(r03F3, body.constant(false), 0x01));


            body.instructions = f0431_parent_instructions;
            body.emit(f0431);

            /* END IF */

            body.emit(assign(r020F, r03F4, 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


         body.instructions = f0360_parent_instructions;
         body.emit(f0360);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f035E->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0445 = less(r0210, body.constant(int(0)));
         ir_if *f0444 = new(mem_ctx) ir_if(operand(r0445).val);
         exec_list *const f0444_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0444->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0447 = equal(r0221, body.constant(int(2047)));
            ir_if *f0446 = new(mem_ctx) ir_if(operand(r0447).val);
            exec_list *const f0446_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0446->then_instructions;

               ir_variable *const r0448 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0448);
               ir_expression *const r0449 = bit_xor(r021A, body.constant(1u));
               ir_expression *const r044A = lshift(r0449, body.constant(int(31)));
               body.emit(assign(r0448, add(r044A, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0448, body.constant(0u), 0x01));

               ir_variable *const r044B = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r044B, swizzle_x(r020C), 0x01));

               ir_variable *const r044C = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r044C, swizzle_x(r020D), 0x01));

               body.emit(assign(r044B, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r044C, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r044D = bit_or(r0215, r0216);
               ir_expression *const r044E = nequal(r044D, body.constant(0u));
               ir_swizzle *const r044F = swizzle(r044E, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0450 = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r0451 = gequal(r0450, body.constant(4292870144u));
               ir_expression *const r0452 = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r0453 = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r0454 = nequal(r0453, body.constant(0u));
               ir_expression *const r0455 = logic_or(r0452, r0454);
               ir_expression *const r0456 = logic_and(r0451, r0455);
               ir_swizzle *const r0457 = swizzle(r0456, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0458 = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r0459 = gequal(r0458, body.constant(4292870144u));
               ir_expression *const r045A = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r045B = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r045C = nequal(r045B, body.constant(0u));
               ir_expression *const r045D = logic_or(r045A, r045C);
               ir_expression *const r045E = logic_and(r0459, r045D);
               ir_swizzle *const r045F = swizzle(r045E, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0460 = expr(ir_triop_csel, r045F, r044C, r044B);
               ir_expression *const r0461 = expr(ir_triop_csel, r0457, r0460, r044C);
               body.emit(assign(r020F, expr(ir_triop_csel, r044F, r0461, r0448), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0446->else_instructions;

               ir_variable *const r0462 = body.make_temp(glsl_type::int_type, "mix_retval");
               ir_expression *const r0463 = equal(r021E, body.constant(int(0)));
               ir_expression *const r0464 = add(r0210, body.constant(int(1)));
               body.emit(assign(r0462, expr(ir_triop_csel, r0463, r0464, r0210), 0x01));

               body.emit(assign(r0210, r0462, 0x01));

               ir_variable *const r0465 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0466 = equal(r021E, body.constant(int(0)));
               ir_expression *const r0467 = bit_or(r0217, body.constant(1073741824u));
               body.emit(assign(r0465, expr(ir_triop_csel, r0466, r0217, r0467), 0x01));

               ir_variable *const r0468 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0468, neg(r0462), 0x01));

               ir_variable *const r0469 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r046A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r046A);
               ir_variable *const r046B = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r046C = neg(r0468);
               body.emit(assign(r046B, bit_and(r046C, body.constant(int(31))), 0x01));

               ir_expression *const r046D = bit_or(r0465, r0357);
               ir_expression *const r046E = nequal(r046D, body.constant(0u));
               ir_expression *const r046F = expr(ir_unop_b2i, r046E);
               body.emit(assign(r046A, expr(ir_unop_i2u, r046F), 0x01));

               ir_variable *const r0470 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0471 = equal(r0468, body.constant(int(0)));
               ir_expression *const r0472 = less(r0468, body.constant(int(32)));
               ir_expression *const r0473 = lshift(r0465, r046B);
               ir_expression *const r0474 = rshift(r0357, r0468);
               ir_expression *const r0475 = bit_or(r0473, r0474);
               ir_expression *const r0476 = lshift(r0357, r046B);
               ir_expression *const r0477 = nequal(r0476, body.constant(0u));
               ir_expression *const r0478 = expr(ir_unop_b2i, r0477);
               ir_expression *const r0479 = expr(ir_unop_i2u, r0478);
               ir_expression *const r047A = bit_or(r0475, r0479);
               ir_expression *const r047B = equal(r0468, body.constant(int(32)));
               ir_expression *const r047C = nequal(r0357, body.constant(0u));
               ir_expression *const r047D = expr(ir_unop_b2i, r047C);
               ir_expression *const r047E = expr(ir_unop_i2u, r047D);
               ir_expression *const r047F = bit_or(r0465, r047E);
               ir_expression *const r0480 = less(r0468, body.constant(int(64)));
               ir_expression *const r0481 = bit_and(r0468, body.constant(int(31)));
               ir_expression *const r0482 = rshift(r0465, r0481);
               ir_expression *const r0483 = lshift(r0465, r046B);
               ir_expression *const r0484 = bit_or(r0483, r0357);
               ir_expression *const r0485 = nequal(r0484, body.constant(0u));
               ir_expression *const r0486 = expr(ir_unop_b2i, r0485);
               ir_expression *const r0487 = expr(ir_unop_i2u, r0486);
               ir_expression *const r0488 = bit_or(r0482, r0487);
               ir_expression *const r0489 = expr(ir_triop_csel, r0480, r0488, r046A);
               ir_expression *const r048A = expr(ir_triop_csel, r047B, r047F, r0489);
               ir_expression *const r048B = expr(ir_triop_csel, r0472, r047A, r048A);
               body.emit(assign(r0470, expr(ir_triop_csel, r0471, r0357, r048B), 0x01));

               body.emit(assign(r046A, r0470, 0x01));

               ir_expression *const r048C = less(r0468, body.constant(int(32)));
               ir_expression *const r048D = rshift(r0465, r0468);
               ir_expression *const r048E = equal(r0468, body.constant(int(0)));
               ir_expression *const r048F = expr(ir_triop_csel, r048E, r0465, body.constant(0u));
               body.emit(assign(r0469, expr(ir_triop_csel, r048C, r048D, r048F), 0x01));

               body.emit(assign(r0217, r0469, 0x01));

               body.emit(assign(r0218, r0470, 0x01));

               body.emit(assign(r0215, bit_or(r0215, body.constant(1073741824u)), 0x01));

               ir_variable *const r0490 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0491 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0491, sub(r0216, r0470), 0x01));

               ir_expression *const r0492 = sub(r0215, r0469);
               ir_expression *const r0493 = less(r0216, r0470);
               ir_expression *const r0494 = expr(ir_unop_b2i, r0493);
               ir_expression *const r0495 = expr(ir_unop_i2u, r0494);
               body.emit(assign(r0490, sub(r0492, r0495), 0x01));

               body.emit(assign(r0212, r0490, 0x01));

               body.emit(assign(r0211, r0491, 0x01));

               body.emit(assign(r0219, bit_xor(r021A, body.constant(1u)), 0x01));

               body.emit(assign(r0355, add(r0221, body.constant(int(-1))), 0x01));

               ir_variable *const r0496 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0496, add(r0355, body.constant(int(-10))), 0x01));

               ir_variable *const r0497 = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r0498 = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r0499 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r0499);
               ir_variable *const r049A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r049A);
               ir_expression *const r049B = equal(r0490, body.constant(0u));
               ir_expression *const r049C = add(r0496, body.constant(int(-32)));
               body.emit(assign(r0496, expr(ir_triop_csel, r049B, r049C, r0496), 0x01));

               ir_variable *const r049D = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r049E = equal(r0490, body.constant(0u));
               body.emit(assign(r049D, expr(ir_triop_csel, r049E, body.constant(0u), r0491), 0x01));

               body.emit(assign(r0498, r049D, 0x01));

               ir_variable *const r049F = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04A0 = equal(r0490, body.constant(0u));
               body.emit(assign(r049F, expr(ir_triop_csel, r04A0, r049D, r0490), 0x01));

               body.emit(assign(r0497, r049F, 0x01));

               ir_expression *const r04A1 = equal(r049F, body.constant(0u));
               ir_expression *const r04A2 = expr(ir_unop_find_msb, r049F);
               ir_expression *const r04A3 = sub(body.constant(int(31)), r04A2);
               ir_expression *const r04A4 = expr(ir_triop_csel, r04A1, body.constant(int(32)), r04A3);
               body.emit(assign(r049A, add(r04A4, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04A6 = gequal(r049A, body.constant(int(0)));
               ir_if *f04A5 = new(mem_ctx) ir_if(operand(r04A6).val);
               exec_list *const f04A5_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04A5->then_instructions;

                  body.emit(assign(r0499, body.constant(0u), 0x01));

                  ir_expression *const r04A7 = equal(r049A, body.constant(int(0)));
                  ir_expression *const r04A8 = lshift(r049F, r049A);
                  ir_expression *const r04A9 = neg(r049A);
                  ir_expression *const r04AA = bit_and(r04A9, body.constant(int(31)));
                  ir_expression *const r04AB = rshift(r049D, r04AA);
                  ir_expression *const r04AC = bit_or(r04A8, r04AB);
                  body.emit(assign(r0497, expr(ir_triop_csel, r04A7, r049F, r04AC), 0x01));

                  body.emit(assign(r0498, lshift(r049D, r049A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04A5->else_instructions;

                  ir_variable *const r04AD = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r04AD, neg(r049A), 0x01));

                  ir_variable *const r04AE = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  ir_variable *const r04AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04AF);
                  ir_variable *const r04B0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04B1 = neg(r04AD);
                  body.emit(assign(r04B0, bit_and(r04B1, body.constant(int(31))), 0x01));

                  ir_variable *const r04B2 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r04B3 = less(r04AD, body.constant(int(32)));
                  ir_expression *const r04B4 = bit_or(body.constant(0u), r0498);
                  body.emit(assign(r04B2, expr(ir_triop_csel, r04B3, body.constant(0u), r04B4), 0x01));

                  ir_expression *const r04B5 = less(r04AD, body.constant(int(32)));
                  ir_expression *const r04B6 = lshift(r0498, r04B0);
                  ir_expression *const r04B7 = less(r04AD, body.constant(int(64)));
                  ir_expression *const r04B8 = lshift(r0497, r04B0);
                  ir_expression *const r04B9 = equal(r04AD, body.constant(int(64)));
                  ir_expression *const r04BA = nequal(r0497, body.constant(0u));
                  ir_expression *const r04BB = expr(ir_unop_b2i, r04BA);
                  ir_expression *const r04BC = expr(ir_unop_i2u, r04BB);
                  ir_expression *const r04BD = expr(ir_triop_csel, r04B9, r0497, r04BC);
                  ir_expression *const r04BE = expr(ir_triop_csel, r04B7, r04B8, r04BD);
                  ir_expression *const r04BF = expr(ir_triop_csel, r04B5, r04B6, r04BE);
                  ir_expression *const r04C0 = nequal(r04B2, body.constant(0u));
                  ir_expression *const r04C1 = expr(ir_unop_b2i, r04C0);
                  ir_expression *const r04C2 = expr(ir_unop_i2u, r04C1);
                  body.emit(assign(r04AF, bit_or(r04BF, r04C2), 0x01));

                  ir_variable *const r04C3 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r04C4 = equal(r04AD, body.constant(int(0)));
                  ir_expression *const r04C5 = equal(r04AD, body.constant(int(32)));
                  ir_expression *const r04C6 = expr(ir_triop_csel, r04C5, r0498, r04AF);
                  body.emit(assign(r04C3, expr(ir_triop_csel, r04C4, r04B2, r04C6), 0x01));

                  body.emit(assign(r04AF, r04C3, 0x01));

                  ir_expression *const r04C7 = equal(r04AD, body.constant(int(0)));
                  ir_expression *const r04C8 = equal(r04AD, body.constant(int(32)));
                  ir_expression *const r04C9 = less(r04AD, body.constant(int(32)));
                  ir_expression *const r04CA = lshift(r0497, r04B0);
                  ir_expression *const r04CB = rshift(r0498, r04AD);
                  ir_expression *const r04CC = bit_or(r04CA, r04CB);
                  ir_expression *const r04CD = less(r04AD, body.constant(int(64)));
                  ir_expression *const r04CE = bit_and(r04AD, body.constant(int(31)));
                  ir_expression *const r04CF = rshift(r0497, r04CE);
                  ir_expression *const r04D0 = expr(ir_triop_csel, r04CD, r04CF, body.constant(0u));
                  ir_expression *const r04D1 = expr(ir_triop_csel, r04C9, r04CC, r04D0);
                  ir_expression *const r04D2 = expr(ir_triop_csel, r04C8, r0497, r04D1);
                  body.emit(assign(r04AE, expr(ir_triop_csel, r04C7, r0498, r04D2), 0x01));

                  ir_expression *const r04D3 = equal(r04AD, body.constant(int(0)));
                  ir_expression *const r04D4 = equal(r04AD, body.constant(int(32)));
                  ir_expression *const r04D5 = less(r04AD, body.constant(int(32)));
                  ir_expression *const r04D6 = rshift(r0497, r04AD);
                  ir_expression *const r04D7 = expr(ir_triop_csel, r04D5, r04D6, body.constant(0u));
                  ir_expression *const r04D8 = expr(ir_triop_csel, r04D4, body.constant(0u), r04D7);
                  body.emit(assign(r0497, expr(ir_triop_csel, r04D3, r0497, r04D8), 0x01));

                  body.emit(assign(r0498, r04AE, 0x01));

                  body.emit(assign(r0499, r04C3, 0x01));


               body.instructions = f04A5_parent_instructions;
               body.emit(f04A5);

               /* END IF */

               body.emit(assign(r0496, sub(r0496, r049A), 0x01));

               ir_variable *const r04D9 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04D9, r0496, 0x01));

               ir_variable *const r04DA = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04DA, r0497, 0x01));

               ir_variable *const r04DB = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04DB, r0498, 0x01));

               ir_variable *const r04DC = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r04DC, r0499, 0x01));

               ir_variable *const r04DD = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r04DD, body.constant(true), 0x01));

               ir_variable *const r04DE = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04DF = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r04DF);
               ir_expression *const r04E0 = expr(ir_unop_u2i, r0499);
               body.emit(assign(r04DF, less(r04E0, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04E2 = gequal(r0496, body.constant(int(2045)));
               ir_if *f04E1 = new(mem_ctx) ir_if(operand(r04E2).val);
               exec_list *const f04E1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04E1->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04E4 = less(body.constant(int(2045)), r0496);
                  ir_expression *const r04E5 = equal(r0496, body.constant(int(2045)));
                  ir_expression *const r04E6 = equal(body.constant(2097151u), r0497);
                  ir_expression *const r04E7 = equal(body.constant(4294967295u), r0498);
                  ir_expression *const r04E8 = logic_and(r04E6, r04E7);
                  ir_expression *const r04E9 = logic_and(r04E5, r04E8);
                  ir_expression *const r04EA = logic_and(r04E9, r04DF);
                  ir_expression *const r04EB = logic_or(r04E4, r04EA);
                  ir_if *f04E3 = new(mem_ctx) ir_if(operand(r04EB).val);
                  exec_list *const f04E3_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04E3->then_instructions;

                     ir_variable *const r04EC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r04EC);
                     ir_expression *const r04ED = lshift(r0219, body.constant(int(31)));
                     body.emit(assign(r04EC, add(r04ED, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r04EC, body.constant(0u), 0x01));

                     body.emit(assign(r04DE, r04EC, 0x03));

                     body.emit(assign(r04DD, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04E3->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04EF = less(r0496, body.constant(int(0)));
                     ir_if *f04EE = new(mem_ctx) ir_if(operand(r04EF).val);
                     exec_list *const f04EE_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04EE->then_instructions;

                        ir_variable *const r04F0 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r04F0, neg(r0496), 0x01));

                        ir_variable *const r04F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r04F1);
                        ir_variable *const r04F2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r04F3 = neg(r04F0);
                        body.emit(assign(r04F2, bit_and(r04F3, body.constant(int(31))), 0x01));

                        ir_variable *const r04F4 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r04F5 = less(r04F0, body.constant(int(32)));
                        ir_expression *const r04F6 = bit_or(r0499, r0498);
                        body.emit(assign(r04F4, expr(ir_triop_csel, r04F5, r0499, r04F6), 0x01));

                        ir_expression *const r04F7 = less(r04F0, body.constant(int(32)));
                        ir_expression *const r04F8 = lshift(r0498, r04F2);
                        ir_expression *const r04F9 = less(r04F0, body.constant(int(64)));
                        ir_expression *const r04FA = lshift(r0497, r04F2);
                        ir_expression *const r04FB = equal(r04F0, body.constant(int(64)));
                        ir_expression *const r04FC = nequal(r0497, body.constant(0u));
                        ir_expression *const r04FD = expr(ir_unop_b2i, r04FC);
                        ir_expression *const r04FE = expr(ir_unop_i2u, r04FD);
                        ir_expression *const r04FF = expr(ir_triop_csel, r04FB, r0497, r04FE);
                        ir_expression *const r0500 = expr(ir_triop_csel, r04F9, r04FA, r04FF);
                        ir_expression *const r0501 = expr(ir_triop_csel, r04F7, r04F8, r0500);
                        ir_expression *const r0502 = nequal(r04F4, body.constant(0u));
                        ir_expression *const r0503 = expr(ir_unop_b2i, r0502);
                        ir_expression *const r0504 = expr(ir_unop_i2u, r0503);
                        body.emit(assign(r04F1, bit_or(r0501, r0504), 0x01));

                        ir_variable *const r0505 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0506 = equal(r04F0, body.constant(int(0)));
                        ir_expression *const r0507 = equal(r04F0, body.constant(int(32)));
                        ir_expression *const r0508 = expr(ir_triop_csel, r0507, r0498, r04F1);
                        body.emit(assign(r0505, expr(ir_triop_csel, r0506, r04F4, r0508), 0x01));

                        body.emit(assign(r04F1, r0505, 0x01));

                        ir_expression *const r0509 = equal(r04F0, body.constant(int(0)));
                        ir_expression *const r050A = equal(r04F0, body.constant(int(32)));
                        ir_expression *const r050B = less(r04F0, body.constant(int(32)));
                        ir_expression *const r050C = rshift(r0497, r04F0);
                        ir_expression *const r050D = expr(ir_triop_csel, r050B, r050C, body.constant(0u));
                        ir_expression *const r050E = expr(ir_triop_csel, r050A, body.constant(0u), r050D);
                        body.emit(assign(r04DA, expr(ir_triop_csel, r0509, r0497, r050E), 0x01));

                        ir_expression *const r050F = equal(r04F0, body.constant(int(0)));
                        ir_expression *const r0510 = equal(r04F0, body.constant(int(32)));
                        ir_expression *const r0511 = less(r04F0, body.constant(int(32)));
                        ir_expression *const r0512 = lshift(r0497, r04F2);
                        ir_expression *const r0513 = rshift(r0498, r04F0);
                        ir_expression *const r0514 = bit_or(r0512, r0513);
                        ir_expression *const r0515 = less(r04F0, body.constant(int(64)));
                        ir_expression *const r0516 = bit_and(r04F0, body.constant(int(31)));
                        ir_expression *const r0517 = rshift(r0497, r0516);
                        ir_expression *const r0518 = expr(ir_triop_csel, r0515, r0517, body.constant(0u));
                        ir_expression *const r0519 = expr(ir_triop_csel, r0511, r0514, r0518);
                        ir_expression *const r051A = expr(ir_triop_csel, r0510, r0497, r0519);
                        body.emit(assign(r04DB, expr(ir_triop_csel, r050F, r0498, r051A), 0x01));

                        body.emit(assign(r04DC, r0505, 0x01));

                        body.emit(assign(r04D9, body.constant(int(0)), 0x01));

                        body.emit(assign(r04DF, less(r0505, body.constant(0u)), 0x01));


                     body.instructions = f04EE_parent_instructions;
                     body.emit(f04EE);

                     /* END IF */


                  body.instructions = f04E3_parent_instructions;
                  body.emit(f04E3);

                  /* END IF */


               body.instructions = f04E1_parent_instructions;
               body.emit(f04E1);

               /* END IF */

               /* IF CONDITION */
               ir_if *f051B = new(mem_ctx) ir_if(operand(r04DD).val);
               exec_list *const f051B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f051B->then_instructions;

                  /* IF CONDITION */
                  ir_if *f051C = new(mem_ctx) ir_if(operand(r04DF).val);
                  exec_list *const f051C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f051C->then_instructions;

                     ir_variable *const r051D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r051D, add(r04DB, body.constant(1u)), 0x01));

                     ir_expression *const r051E = less(r051D, r04DB);
                     ir_expression *const r051F = expr(ir_unop_b2i, r051E);
                     ir_expression *const r0520 = expr(ir_unop_i2u, r051F);
                     body.emit(assign(r04DA, add(r04DA, r0520), 0x01));

                     ir_expression *const r0521 = equal(r04DC, body.constant(0u));
                     ir_expression *const r0522 = expr(ir_unop_b2i, r0521);
                     ir_expression *const r0523 = expr(ir_unop_i2u, r0522);
                     ir_expression *const r0524 = add(r04DC, r0523);
                     ir_expression *const r0525 = bit_and(r0524, body.constant(1u));
                     ir_expression *const r0526 = expr(ir_unop_bit_not, r0525);
                     body.emit(assign(r04DB, bit_and(r051D, r0526), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f051C->else_instructions;

                     ir_expression *const r0527 = bit_or(r04DA, r04DB);
                     ir_expression *const r0528 = equal(r0527, body.constant(0u));
                     body.emit(assign(r04D9, expr(ir_triop_csel, r0528, body.constant(int(0)), r04D9), 0x01));


                  body.instructions = f051C_parent_instructions;
                  body.emit(f051C);

                  /* END IF */

                  ir_variable *const r0529 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0529);
                  ir_expression *const r052A = lshift(r0219, body.constant(int(31)));
                  ir_expression *const r052B = expr(ir_unop_i2u, r04D9);
                  ir_expression *const r052C = lshift(r052B, body.constant(int(20)));
                  ir_expression *const r052D = add(r052A, r052C);
                  body.emit(assign(r0529, add(r052D, r04DA), 0x02));

                  body.emit(assign(r0529, r04DB, 0x01));

                  body.emit(assign(r04DE, r0529, 0x03));

                  body.emit(assign(r04DD, body.constant(false), 0x01));


               body.instructions = f051B_parent_instructions;
               body.emit(f051B);

               /* END IF */

               body.emit(assign(r020F, r04DE, 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


            body.instructions = f0446_parent_instructions;
            body.emit(f0446);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0444->else_instructions;

            /* IF CONDITION */
            ir_expression *const r052F = equal(r021E, body.constant(int(2047)));
            ir_if *f052E = new(mem_ctx) ir_if(operand(r052F).val);
            exec_list *const f052E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f052E->then_instructions;

               ir_variable *const r0530 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0530, swizzle_x(r020C), 0x01));

               ir_variable *const r0531 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0531, swizzle_x(r020D), 0x01));

               body.emit(assign(r0530, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r0531, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r0532 = bit_or(r0217, r0218);
               ir_expression *const r0533 = bit_or(r0215, r0216);
               ir_expression *const r0534 = bit_or(r0532, r0533);
               ir_expression *const r0535 = nequal(r0534, body.constant(0u));
               ir_swizzle *const r0536 = swizzle(r0535, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0537 = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r0538 = gequal(r0537, body.constant(4292870144u));
               ir_expression *const r0539 = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r053A = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r053B = nequal(r053A, body.constant(0u));
               ir_expression *const r053C = logic_or(r0539, r053B);
               ir_expression *const r053D = logic_and(r0538, r053C);
               ir_swizzle *const r053E = swizzle(r053D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r053F = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r0540 = gequal(r053F, body.constant(4292870144u));
               ir_expression *const r0541 = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r0542 = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r0543 = nequal(r0542, body.constant(0u));
               ir_expression *const r0544 = logic_or(r0541, r0543);
               ir_expression *const r0545 = logic_and(r0540, r0544);
               ir_swizzle *const r0546 = swizzle(r0545, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0547 = expr(ir_triop_csel, r0546, r0531, r0530);
               ir_expression *const r0548 = expr(ir_triop_csel, r053E, r0547, r0531);
               ir_constant_data r0549_data;
               memset(&r0549_data, 0, sizeof(ir_constant_data));
               r0549_data.u[0] = 4294967295;
               r0549_data.u[1] = 4294967295;
               ir_constant *const r0549 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0549_data);
               body.emit(assign(r020F, expr(ir_triop_csel, r0536, r0548, r0549), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f052E->else_instructions;

               ir_expression *const r054A = equal(r021E, body.constant(int(0)));
               body.emit(assign(r0213, expr(ir_triop_csel, r054A, body.constant(int(1)), r0221), 0x01));

               ir_expression *const r054B = equal(r021E, body.constant(int(0)));
               body.emit(assign(r0214, expr(ir_triop_csel, r054B, body.constant(int(1)), r021E), 0x01));

               body.emit(assign(r0354, body.constant(false), 0x01));

               body.emit(assign(r0353, body.constant(true), 0x01));

               /* IF CONDITION */
               ir_expression *const r054D = less(r0215, r0217);
               ir_if *f054C = new(mem_ctx) ir_if(operand(r054D).val);
               exec_list *const f054C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f054C->then_instructions;

                  ir_expression *const r054E = sub(r0217, r0215);
                  ir_expression *const r054F = less(r0218, r0216);
                  ir_expression *const r0550 = expr(ir_unop_b2i, r054F);
                  ir_expression *const r0551 = expr(ir_unop_i2u, r0550);
                  body.emit(assign(r0212, sub(r054E, r0551), 0x01));

                  body.emit(assign(r0211, sub(r0218, r0216), 0x01));

                  body.emit(assign(r0354, body.constant(true), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f054C->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0553 = less(r0217, r0215);
                  ir_if *f0552 = new(mem_ctx) ir_if(operand(r0553).val);
                  exec_list *const f0552_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0552->then_instructions;

                     ir_expression *const r0554 = sub(r0215, r0217);
                     ir_expression *const r0555 = less(r0216, r0218);
                     ir_expression *const r0556 = expr(ir_unop_b2i, r0555);
                     ir_expression *const r0557 = expr(ir_unop_i2u, r0556);
                     body.emit(assign(r0212, sub(r0554, r0557), 0x01));

                     body.emit(assign(r0211, sub(r0216, r0218), 0x01));

                     body.emit(assign(r0353, body.constant(false), 0x01));

                     body.emit(assign(r0354, body.constant(true), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0552->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0559 = less(r0216, r0218);
                     ir_if *f0558 = new(mem_ctx) ir_if(operand(r0559).val);
                     exec_list *const f0558_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0558->then_instructions;

                        ir_expression *const r055A = sub(r0217, r0215);
                        ir_expression *const r055B = less(r0218, r0216);
                        ir_expression *const r055C = expr(ir_unop_b2i, r055B);
                        ir_expression *const r055D = expr(ir_unop_i2u, r055C);
                        body.emit(assign(r0212, sub(r055A, r055D), 0x01));

                        body.emit(assign(r0211, sub(r0218, r0216), 0x01));

                        body.emit(assign(r0354, body.constant(true), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0558->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r055F = less(r0218, r0216);
                        ir_if *f055E = new(mem_ctx) ir_if(operand(r055F).val);
                        exec_list *const f055E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f055E->then_instructions;

                           ir_expression *const r0560 = sub(r0215, r0217);
                           ir_expression *const r0561 = less(r0216, r0218);
                           ir_expression *const r0562 = expr(ir_unop_b2i, r0561);
                           ir_expression *const r0563 = expr(ir_unop_i2u, r0562);
                           body.emit(assign(r0212, sub(r0560, r0563), 0x01));

                           body.emit(assign(r0211, sub(r0216, r0218), 0x01));

                           body.emit(assign(r0353, body.constant(false), 0x01));

                           body.emit(assign(r0354, body.constant(true), 0x01));


                        body.instructions = f055E_parent_instructions;
                        body.emit(f055E);

                        /* END IF */


                     body.instructions = f0558_parent_instructions;
                     body.emit(f0558);

                     /* END IF */


                  body.instructions = f0552_parent_instructions;
                  body.emit(f0552);

                  /* END IF */


               body.instructions = f054C_parent_instructions;
               body.emit(f054C);

               /* END IF */

               body.emit(assign(r0355, expr(ir_triop_csel, r0353, r0214, r0213), 0x01));

               ir_expression *const r0564 = bit_xor(r0219, body.constant(1u));
               body.emit(assign(r0219, expr(ir_triop_csel, r0353, r0219, r0564), 0x01));

               ir_variable *const r0565 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0565, add(r0355, body.constant(int(-11))), 0x01));

               ir_variable *const r0566 = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r0567 = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r0568 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r0568);
               ir_variable *const r0569 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0569);
               ir_expression *const r056A = equal(r0212, body.constant(0u));
               ir_expression *const r056B = add(r0565, body.constant(int(-32)));
               body.emit(assign(r0565, expr(ir_triop_csel, r056A, r056B, r0565), 0x01));

               ir_variable *const r056C = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r056D = equal(r0212, body.constant(0u));
               body.emit(assign(r056C, expr(ir_triop_csel, r056D, body.constant(0u), r0211), 0x01));

               body.emit(assign(r0567, r056C, 0x01));

               ir_variable *const r056E = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r056F = equal(r0212, body.constant(0u));
               body.emit(assign(r056E, expr(ir_triop_csel, r056F, r056C, r0212), 0x01));

               body.emit(assign(r0566, r056E, 0x01));

               ir_expression *const r0570 = equal(r056E, body.constant(0u));
               ir_expression *const r0571 = expr(ir_unop_find_msb, r056E);
               ir_expression *const r0572 = sub(body.constant(int(31)), r0571);
               ir_expression *const r0573 = expr(ir_triop_csel, r0570, body.constant(int(32)), r0572);
               body.emit(assign(r0569, add(r0573, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0575 = gequal(r0569, body.constant(int(0)));
               ir_if *f0574 = new(mem_ctx) ir_if(operand(r0575).val);
               exec_list *const f0574_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0574->then_instructions;

                  body.emit(assign(r0568, body.constant(0u), 0x01));

                  ir_expression *const r0576 = equal(r0569, body.constant(int(0)));
                  ir_expression *const r0577 = lshift(r056E, r0569);
                  ir_expression *const r0578 = neg(r0569);
                  ir_expression *const r0579 = bit_and(r0578, body.constant(int(31)));
                  ir_expression *const r057A = rshift(r056C, r0579);
                  ir_expression *const r057B = bit_or(r0577, r057A);
                  body.emit(assign(r0566, expr(ir_triop_csel, r0576, r056E, r057B), 0x01));

                  body.emit(assign(r0567, lshift(r056C, r0569), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0574->else_instructions;

                  ir_variable *const r057C = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r057C, neg(r0569), 0x01));

                  ir_variable *const r057D = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  ir_variable *const r057E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r057E);
                  ir_variable *const r057F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r0580 = neg(r057C);
                  body.emit(assign(r057F, bit_and(r0580, body.constant(int(31))), 0x01));

                  ir_variable *const r0581 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0582 = less(r057C, body.constant(int(32)));
                  ir_expression *const r0583 = bit_or(body.constant(0u), r0567);
                  body.emit(assign(r0581, expr(ir_triop_csel, r0582, body.constant(0u), r0583), 0x01));

                  ir_expression *const r0584 = less(r057C, body.constant(int(32)));
                  ir_expression *const r0585 = lshift(r0567, r057F);
                  ir_expression *const r0586 = less(r057C, body.constant(int(64)));
                  ir_expression *const r0587 = lshift(r0566, r057F);
                  ir_expression *const r0588 = equal(r057C, body.constant(int(64)));
                  ir_expression *const r0589 = nequal(r0566, body.constant(0u));
                  ir_expression *const r058A = expr(ir_unop_b2i, r0589);
                  ir_expression *const r058B = expr(ir_unop_i2u, r058A);
                  ir_expression *const r058C = expr(ir_triop_csel, r0588, r0566, r058B);
                  ir_expression *const r058D = expr(ir_triop_csel, r0586, r0587, r058C);
                  ir_expression *const r058E = expr(ir_triop_csel, r0584, r0585, r058D);
                  ir_expression *const r058F = nequal(r0581, body.constant(0u));
                  ir_expression *const r0590 = expr(ir_unop_b2i, r058F);
                  ir_expression *const r0591 = expr(ir_unop_i2u, r0590);
                  body.emit(assign(r057E, bit_or(r058E, r0591), 0x01));

                  ir_variable *const r0592 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0593 = equal(r057C, body.constant(int(0)));
                  ir_expression *const r0594 = equal(r057C, body.constant(int(32)));
                  ir_expression *const r0595 = expr(ir_triop_csel, r0594, r0567, r057E);
                  body.emit(assign(r0592, expr(ir_triop_csel, r0593, r0581, r0595), 0x01));

                  body.emit(assign(r057E, r0592, 0x01));

                  ir_expression *const r0596 = equal(r057C, body.constant(int(0)));
                  ir_expression *const r0597 = equal(r057C, body.constant(int(32)));
                  ir_expression *const r0598 = less(r057C, body.constant(int(32)));
                  ir_expression *const r0599 = lshift(r0566, r057F);
                  ir_expression *const r059A = rshift(r0567, r057C);
                  ir_expression *const r059B = bit_or(r0599, r059A);
                  ir_expression *const r059C = less(r057C, body.constant(int(64)));
                  ir_expression *const r059D = bit_and(r057C, body.constant(int(31)));
                  ir_expression *const r059E = rshift(r0566, r059D);
                  ir_expression *const r059F = expr(ir_triop_csel, r059C, r059E, body.constant(0u));
                  ir_expression *const r05A0 = expr(ir_triop_csel, r0598, r059B, r059F);
                  ir_expression *const r05A1 = expr(ir_triop_csel, r0597, r0566, r05A0);
                  body.emit(assign(r057D, expr(ir_triop_csel, r0596, r0567, r05A1), 0x01));

                  ir_expression *const r05A2 = equal(r057C, body.constant(int(0)));
                  ir_expression *const r05A3 = equal(r057C, body.constant(int(32)));
                  ir_expression *const r05A4 = less(r057C, body.constant(int(32)));
                  ir_expression *const r05A5 = rshift(r0566, r057C);
                  ir_expression *const r05A6 = expr(ir_triop_csel, r05A4, r05A5, body.constant(0u));
                  ir_expression *const r05A7 = expr(ir_triop_csel, r05A3, body.constant(0u), r05A6);
                  body.emit(assign(r0566, expr(ir_triop_csel, r05A2, r0566, r05A7), 0x01));

                  body.emit(assign(r0567, r057D, 0x01));

                  body.emit(assign(r0568, r0592, 0x01));


               body.instructions = f0574_parent_instructions;
               body.emit(f0574);

               /* END IF */

               body.emit(assign(r0565, sub(r0565, r0569), 0x01));

               ir_variable *const r05A8 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r05A8, r0565, 0x01));

               ir_variable *const r05A9 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r05A9, r0566, 0x01));

               ir_variable *const r05AA = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r05AA, r0567, 0x01));

               ir_variable *const r05AB = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r05AB, r0568, 0x01));

               ir_variable *const r05AC = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r05AC, body.constant(true), 0x01));

               ir_variable *const r05AD = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r05AE = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r05AE);
               ir_expression *const r05AF = expr(ir_unop_u2i, r0568);
               body.emit(assign(r05AE, less(r05AF, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r05B1 = gequal(r0565, body.constant(int(2045)));
               ir_if *f05B0 = new(mem_ctx) ir_if(operand(r05B1).val);
               exec_list *const f05B0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f05B0->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05B3 = less(body.constant(int(2045)), r0565);
                  ir_expression *const r05B4 = equal(r0565, body.constant(int(2045)));
                  ir_expression *const r05B5 = equal(body.constant(2097151u), r0566);
                  ir_expression *const r05B6 = equal(body.constant(4294967295u), r0567);
                  ir_expression *const r05B7 = logic_and(r05B5, r05B6);
                  ir_expression *const r05B8 = logic_and(r05B4, r05B7);
                  ir_expression *const r05B9 = logic_and(r05B8, r05AE);
                  ir_expression *const r05BA = logic_or(r05B3, r05B9);
                  ir_if *f05B2 = new(mem_ctx) ir_if(operand(r05BA).val);
                  exec_list *const f05B2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05B2->then_instructions;

                     ir_variable *const r05BB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r05BB);
                     ir_expression *const r05BC = lshift(r0219, body.constant(int(31)));
                     body.emit(assign(r05BB, add(r05BC, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r05BB, body.constant(0u), 0x01));

                     body.emit(assign(r05AD, r05BB, 0x03));

                     body.emit(assign(r05AC, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05B2->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r05BE = less(r0565, body.constant(int(0)));
                     ir_if *f05BD = new(mem_ctx) ir_if(operand(r05BE).val);
                     exec_list *const f05BD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05BD->then_instructions;

                        ir_variable *const r05BF = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r05BF, neg(r0565), 0x01));

                        ir_variable *const r05C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r05C0);
                        ir_variable *const r05C1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r05C2 = neg(r05BF);
                        body.emit(assign(r05C1, bit_and(r05C2, body.constant(int(31))), 0x01));

                        ir_variable *const r05C3 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r05C4 = less(r05BF, body.constant(int(32)));
                        ir_expression *const r05C5 = bit_or(r0568, r0567);
                        body.emit(assign(r05C3, expr(ir_triop_csel, r05C4, r0568, r05C5), 0x01));

                        ir_expression *const r05C6 = less(r05BF, body.constant(int(32)));
                        ir_expression *const r05C7 = lshift(r0567, r05C1);
                        ir_expression *const r05C8 = less(r05BF, body.constant(int(64)));
                        ir_expression *const r05C9 = lshift(r0566, r05C1);
                        ir_expression *const r05CA = equal(r05BF, body.constant(int(64)));
                        ir_expression *const r05CB = nequal(r0566, body.constant(0u));
                        ir_expression *const r05CC = expr(ir_unop_b2i, r05CB);
                        ir_expression *const r05CD = expr(ir_unop_i2u, r05CC);
                        ir_expression *const r05CE = expr(ir_triop_csel, r05CA, r0566, r05CD);
                        ir_expression *const r05CF = expr(ir_triop_csel, r05C8, r05C9, r05CE);
                        ir_expression *const r05D0 = expr(ir_triop_csel, r05C6, r05C7, r05CF);
                        ir_expression *const r05D1 = nequal(r05C3, body.constant(0u));
                        ir_expression *const r05D2 = expr(ir_unop_b2i, r05D1);
                        ir_expression *const r05D3 = expr(ir_unop_i2u, r05D2);
                        body.emit(assign(r05C0, bit_or(r05D0, r05D3), 0x01));

                        ir_variable *const r05D4 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r05D5 = equal(r05BF, body.constant(int(0)));
                        ir_expression *const r05D6 = equal(r05BF, body.constant(int(32)));
                        ir_expression *const r05D7 = expr(ir_triop_csel, r05D6, r0567, r05C0);
                        body.emit(assign(r05D4, expr(ir_triop_csel, r05D5, r05C3, r05D7), 0x01));

                        body.emit(assign(r05C0, r05D4, 0x01));

                        ir_expression *const r05D8 = equal(r05BF, body.constant(int(0)));
                        ir_expression *const r05D9 = equal(r05BF, body.constant(int(32)));
                        ir_expression *const r05DA = less(r05BF, body.constant(int(32)));
                        ir_expression *const r05DB = rshift(r0566, r05BF);
                        ir_expression *const r05DC = expr(ir_triop_csel, r05DA, r05DB, body.constant(0u));
                        ir_expression *const r05DD = expr(ir_triop_csel, r05D9, body.constant(0u), r05DC);
                        body.emit(assign(r05A9, expr(ir_triop_csel, r05D8, r0566, r05DD), 0x01));

                        ir_expression *const r05DE = equal(r05BF, body.constant(int(0)));
                        ir_expression *const r05DF = equal(r05BF, body.constant(int(32)));
                        ir_expression *const r05E0 = less(r05BF, body.constant(int(32)));
                        ir_expression *const r05E1 = lshift(r0566, r05C1);
                        ir_expression *const r05E2 = rshift(r0567, r05BF);
                        ir_expression *const r05E3 = bit_or(r05E1, r05E2);
                        ir_expression *const r05E4 = less(r05BF, body.constant(int(64)));
                        ir_expression *const r05E5 = bit_and(r05BF, body.constant(int(31)));
                        ir_expression *const r05E6 = rshift(r0566, r05E5);
                        ir_expression *const r05E7 = expr(ir_triop_csel, r05E4, r05E6, body.constant(0u));
                        ir_expression *const r05E8 = expr(ir_triop_csel, r05E0, r05E3, r05E7);
                        ir_expression *const r05E9 = expr(ir_triop_csel, r05DF, r0566, r05E8);
                        body.emit(assign(r05AA, expr(ir_triop_csel, r05DE, r0567, r05E9), 0x01));

                        body.emit(assign(r05AB, r05D4, 0x01));

                        body.emit(assign(r05A8, body.constant(int(0)), 0x01));

                        body.emit(assign(r05AE, less(r05D4, body.constant(0u)), 0x01));


                     body.instructions = f05BD_parent_instructions;
                     body.emit(f05BD);

                     /* END IF */


                  body.instructions = f05B2_parent_instructions;
                  body.emit(f05B2);

                  /* END IF */


               body.instructions = f05B0_parent_instructions;
               body.emit(f05B0);

               /* END IF */

               /* IF CONDITION */
               ir_if *f05EA = new(mem_ctx) ir_if(operand(r05AC).val);
               exec_list *const f05EA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f05EA->then_instructions;

                  /* IF CONDITION */
                  ir_if *f05EB = new(mem_ctx) ir_if(operand(r05AE).val);
                  exec_list *const f05EB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05EB->then_instructions;

                     ir_variable *const r05EC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r05EC, add(r05AA, body.constant(1u)), 0x01));

                     ir_expression *const r05ED = less(r05EC, r05AA);
                     ir_expression *const r05EE = expr(ir_unop_b2i, r05ED);
                     ir_expression *const r05EF = expr(ir_unop_i2u, r05EE);
                     body.emit(assign(r05A9, add(r05A9, r05EF), 0x01));

                     ir_expression *const r05F0 = equal(r05AB, body.constant(0u));
                     ir_expression *const r05F1 = expr(ir_unop_b2i, r05F0);
                     ir_expression *const r05F2 = expr(ir_unop_i2u, r05F1);
                     ir_expression *const r05F3 = add(r05AB, r05F2);
                     ir_expression *const r05F4 = bit_and(r05F3, body.constant(1u));
                     ir_expression *const r05F5 = expr(ir_unop_bit_not, r05F4);
                     body.emit(assign(r05AA, bit_and(r05EC, r05F5), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05EB->else_instructions;

                     ir_expression *const r05F6 = bit_or(r05A9, r05AA);
                     ir_expression *const r05F7 = equal(r05F6, body.constant(0u));
                     body.emit(assign(r05A8, expr(ir_triop_csel, r05F7, body.constant(int(0)), r05A8), 0x01));


                  body.instructions = f05EB_parent_instructions;
                  body.emit(f05EB);

                  /* END IF */

                  ir_variable *const r05F8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r05F8);
                  ir_expression *const r05F9 = lshift(r0219, body.constant(int(31)));
                  ir_expression *const r05FA = expr(ir_unop_i2u, r05A8);
                  ir_expression *const r05FB = lshift(r05FA, body.constant(int(20)));
                  ir_expression *const r05FC = add(r05F9, r05FB);
                  body.emit(assign(r05F8, add(r05FC, r05A9), 0x02));

                  body.emit(assign(r05F8, r05AA, 0x01));

                  body.emit(assign(r05AD, r05F8, 0x03));

                  body.emit(assign(r05AC, body.constant(false), 0x01));


               body.instructions = f05EA_parent_instructions;
               body.emit(f05EA);

               /* END IF */

               ir_swizzle *const r05FD = swizzle(r0354, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               body.emit(assign(r020F, expr(ir_triop_csel, r05FD, r05AD, ir_constant::zero(mem_ctx, glsl_type::uvec2_type)), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


            body.instructions = f052E_parent_instructions;
            body.emit(f052E);

            /* END IF */


         body.instructions = f0444_parent_instructions;
         body.emit(f0444);

         /* END IF */


      body.instructions = f035E_parent_instructions;
      body.emit(f035E);

      /* END IF */


   body.instructions = f0225_parent_instructions;
   body.emit(f0225);

   /* END IF */

   body.emit(ret(r020F));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
mul32To64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r05FE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r05FE);
   ir_variable *const r05FF = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r05FF);
   ir_variable *const r0600 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0600);
   ir_variable *const r0601 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0601);
   ir_variable *const r0602 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0602);
   ir_variable *const r0603 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0603);
   ir_variable *const r0604 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0604);
   ir_variable *const r0605 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0605, bit_and(r05FE, body.constant(65535u)), 0x01));

   ir_variable *const r0606 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0606, rshift(r05FE, body.constant(int(16))), 0x01));

   ir_variable *const r0607 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0607, bit_and(r05FF, body.constant(65535u)), 0x01));

   ir_variable *const r0608 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0608, rshift(r05FF, body.constant(int(16))), 0x01));

   ir_variable *const r0609 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0609, mul(r0606, r0607), 0x01));

   ir_expression *const r060A = mul(r0605, r0608);
   body.emit(assign(r0603, add(r060A, r0609), 0x01));

   ir_expression *const r060B = mul(r0606, r0608);
   ir_expression *const r060C = less(r0603, r0609);
   ir_expression *const r060D = expr(ir_unop_b2i, r060C);
   ir_expression *const r060E = expr(ir_unop_i2u, r060D);
   ir_expression *const r060F = lshift(r060E, body.constant(int(16)));
   ir_expression *const r0610 = rshift(r0603, body.constant(int(16)));
   ir_expression *const r0611 = add(r060F, r0610);
   body.emit(assign(r0602, add(r060B, r0611), 0x01));

   body.emit(assign(r0603, lshift(r0603, body.constant(int(16))), 0x01));

   ir_expression *const r0612 = mul(r0605, r0607);
   body.emit(assign(r0604, add(r0612, r0603), 0x01));

   ir_expression *const r0613 = less(r0604, r0603);
   ir_expression *const r0614 = expr(ir_unop_b2i, r0613);
   ir_expression *const r0615 = expr(ir_unop_i2u, r0614);
   body.emit(assign(r0602, add(r0602, r0615), 0x01));

   body.emit(assign(r0601, r0604, 0x01));

   body.emit(assign(r0600, r0602, 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
mul64To128(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0616 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0616);
   ir_variable *const r0617 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0617);
   ir_variable *const r0618 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0618);
   ir_variable *const r0619 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0619);
   ir_variable *const r061A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r061A);
   ir_variable *const r061B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r061B);
   ir_variable *const r061C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r061C);
   ir_variable *const r061D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r061D);
   ir_variable *const r061E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r061E);
   ir_variable *const r061F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r061F);
   ir_variable *const r0620 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0620);
   ir_variable *const r0621 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0621, bit_and(r0617, body.constant(65535u)), 0x01));

   ir_variable *const r0622 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0622, rshift(r0617, body.constant(int(16))), 0x01));

   ir_variable *const r0623 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0623, bit_and(r0619, body.constant(65535u)), 0x01));

   ir_variable *const r0624 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0624, rshift(r0619, body.constant(int(16))), 0x01));

   ir_variable *const r0625 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0625, mul(r0622, r0623), 0x01));

   ir_expression *const r0626 = mul(r0621, r0624);
   body.emit(assign(r061F, add(r0626, r0625), 0x01));

   ir_expression *const r0627 = mul(r0622, r0624);
   ir_expression *const r0628 = less(r061F, r0625);
   ir_expression *const r0629 = expr(ir_unop_b2i, r0628);
   ir_expression *const r062A = expr(ir_unop_i2u, r0629);
   ir_expression *const r062B = lshift(r062A, body.constant(int(16)));
   ir_expression *const r062C = rshift(r061F, body.constant(int(16)));
   ir_expression *const r062D = add(r062B, r062C);
   body.emit(assign(r061E, add(r0627, r062D), 0x01));

   body.emit(assign(r061F, lshift(r061F, body.constant(int(16))), 0x01));

   ir_expression *const r062E = mul(r0621, r0623);
   body.emit(assign(r0620, add(r062E, r061F), 0x01));

   ir_expression *const r062F = less(r0620, r061F);
   ir_expression *const r0630 = expr(ir_unop_b2i, r062F);
   ir_expression *const r0631 = expr(ir_unop_i2u, r0630);
   body.emit(assign(r061E, add(r061E, r0631), 0x01));

   ir_variable *const r0632 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0632);
   ir_variable *const r0633 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0633);
   ir_variable *const r0634 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0634);
   ir_variable *const r0635 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0635, bit_and(r0617, body.constant(65535u)), 0x01));

   ir_variable *const r0636 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0636, rshift(r0617, body.constant(int(16))), 0x01));

   ir_variable *const r0637 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0637, bit_and(r0618, body.constant(65535u)), 0x01));

   ir_variable *const r0638 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0638, rshift(r0618, body.constant(int(16))), 0x01));

   ir_variable *const r0639 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0639, mul(r0636, r0637), 0x01));

   ir_expression *const r063A = mul(r0635, r0638);
   body.emit(assign(r0633, add(r063A, r0639), 0x01));

   ir_expression *const r063B = mul(r0636, r0638);
   ir_expression *const r063C = less(r0633, r0639);
   ir_expression *const r063D = expr(ir_unop_b2i, r063C);
   ir_expression *const r063E = expr(ir_unop_i2u, r063D);
   ir_expression *const r063F = lshift(r063E, body.constant(int(16)));
   ir_expression *const r0640 = rshift(r0633, body.constant(int(16)));
   ir_expression *const r0641 = add(r063F, r0640);
   body.emit(assign(r0632, add(r063B, r0641), 0x01));

   body.emit(assign(r0633, lshift(r0633, body.constant(int(16))), 0x01));

   ir_expression *const r0642 = mul(r0635, r0637);
   body.emit(assign(r0634, add(r0642, r0633), 0x01));

   ir_expression *const r0643 = less(r0634, r0633);
   ir_expression *const r0644 = expr(ir_unop_b2i, r0643);
   ir_expression *const r0645 = expr(ir_unop_i2u, r0644);
   body.emit(assign(r0632, add(r0632, r0645), 0x01));

   ir_variable *const r0646 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0646, add(r0634, r061E), 0x01));

   ir_variable *const r0647 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0647);
   ir_variable *const r0648 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0648);
   ir_variable *const r0649 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0649);
   ir_variable *const r064A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r064A, bit_and(r0616, body.constant(65535u)), 0x01));

   ir_variable *const r064B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r064B, rshift(r0616, body.constant(int(16))), 0x01));

   ir_variable *const r064C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r064C, bit_and(r0618, body.constant(65535u)), 0x01));

   ir_variable *const r064D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r064D, rshift(r0618, body.constant(int(16))), 0x01));

   ir_variable *const r064E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r064E, mul(r064B, r064C), 0x01));

   ir_expression *const r064F = mul(r064A, r064D);
   body.emit(assign(r0648, add(r064F, r064E), 0x01));

   ir_expression *const r0650 = mul(r064B, r064D);
   ir_expression *const r0651 = less(r0648, r064E);
   ir_expression *const r0652 = expr(ir_unop_b2i, r0651);
   ir_expression *const r0653 = expr(ir_unop_i2u, r0652);
   ir_expression *const r0654 = lshift(r0653, body.constant(int(16)));
   ir_expression *const r0655 = rshift(r0648, body.constant(int(16)));
   ir_expression *const r0656 = add(r0654, r0655);
   body.emit(assign(r0647, add(r0650, r0656), 0x01));

   body.emit(assign(r0648, lshift(r0648, body.constant(int(16))), 0x01));

   ir_expression *const r0657 = mul(r064A, r064C);
   body.emit(assign(r0649, add(r0657, r0648), 0x01));

   ir_expression *const r0658 = less(r0649, r0648);
   ir_expression *const r0659 = expr(ir_unop_b2i, r0658);
   ir_expression *const r065A = expr(ir_unop_i2u, r0659);
   body.emit(assign(r0647, add(r0647, r065A), 0x01));

   ir_variable *const r065B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r065C = less(r0646, r0634);
   ir_expression *const r065D = expr(ir_unop_b2i, r065C);
   ir_expression *const r065E = expr(ir_unop_i2u, r065D);
   ir_expression *const r065F = add(r0632, r065E);
   body.emit(assign(r065B, add(r0649, r065F), 0x01));

   ir_variable *const r0660 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0660);
   ir_variable *const r0661 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0661);
   ir_variable *const r0662 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0662);
   ir_variable *const r0663 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0663, bit_and(r0616, body.constant(65535u)), 0x01));

   ir_variable *const r0664 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0664, rshift(r0616, body.constant(int(16))), 0x01));

   ir_variable *const r0665 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0665, bit_and(r0619, body.constant(65535u)), 0x01));

   ir_variable *const r0666 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0666, rshift(r0619, body.constant(int(16))), 0x01));

   ir_variable *const r0667 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0667, mul(r0664, r0665), 0x01));

   ir_expression *const r0668 = mul(r0663, r0666);
   body.emit(assign(r0661, add(r0668, r0667), 0x01));

   ir_expression *const r0669 = mul(r0664, r0666);
   ir_expression *const r066A = less(r0661, r0667);
   ir_expression *const r066B = expr(ir_unop_b2i, r066A);
   ir_expression *const r066C = expr(ir_unop_i2u, r066B);
   ir_expression *const r066D = lshift(r066C, body.constant(int(16)));
   ir_expression *const r066E = rshift(r0661, body.constant(int(16)));
   ir_expression *const r066F = add(r066D, r066E);
   body.emit(assign(r0660, add(r0669, r066F), 0x01));

   body.emit(assign(r0661, lshift(r0661, body.constant(int(16))), 0x01));

   ir_expression *const r0670 = mul(r0663, r0665);
   body.emit(assign(r0662, add(r0670, r0661), 0x01));

   ir_expression *const r0671 = less(r0662, r0661);
   ir_expression *const r0672 = expr(ir_unop_b2i, r0671);
   ir_expression *const r0673 = expr(ir_unop_i2u, r0672);
   body.emit(assign(r0660, add(r0660, r0673), 0x01));

   ir_variable *const r0674 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0674, add(r0662, r0646), 0x01));

   ir_variable *const r0675 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0676 = less(r0674, r0662);
   ir_expression *const r0677 = expr(ir_unop_b2i, r0676);
   ir_expression *const r0678 = expr(ir_unop_i2u, r0677);
   ir_expression *const r0679 = add(r0660, r0678);
   body.emit(assign(r0675, add(r065B, r0679), 0x01));

   body.emit(assign(r061D, r0620, 0x01));

   body.emit(assign(r061C, r0674, 0x01));

   body.emit(assign(r061B, r0675, 0x01));

   ir_expression *const r067A = less(r065B, r0649);
   ir_expression *const r067B = expr(ir_unop_b2i, r067A);
   ir_expression *const r067C = expr(ir_unop_i2u, r067B);
   ir_expression *const r067D = add(r0647, r067C);
   ir_expression *const r067E = less(r0675, r065B);
   ir_expression *const r067F = expr(ir_unop_b2i, r067E);
   ir_expression *const r0680 = expr(ir_unop_i2u, r067F);
   body.emit(assign(r061A, add(r067D, r0680), 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
normalizeFloat64Subnormal(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0681 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0681);
   ir_variable *const r0682 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0682);
   ir_variable *const r0683 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r0683);
   ir_variable *const r0684 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0684);
   ir_variable *const r0685 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0685);
   ir_variable *const r0686 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0686);
   ir_variable *const r0687 = body.make_temp(glsl_type::uint_type, "a");
   ir_expression *const r0688 = equal(r0681, body.constant(0u));
   body.emit(assign(r0687, expr(ir_triop_csel, r0688, r0682, r0681), 0x01));

   ir_expression *const r0689 = equal(r0687, body.constant(0u));
   ir_expression *const r068A = expr(ir_unop_find_msb, r0687);
   ir_expression *const r068B = sub(body.constant(int(31)), r068A);
   ir_expression *const r068C = expr(ir_triop_csel, r0689, body.constant(int(32)), r068B);
   body.emit(assign(r0686, add(r068C, body.constant(int(-11))), 0x01));

   ir_expression *const r068D = equal(r0681, body.constant(0u));
   ir_expression *const r068E = sub(body.constant(int(-31)), r0686);
   ir_expression *const r068F = sub(body.constant(int(1)), r0686);
   body.emit(assign(r0683, expr(ir_triop_csel, r068D, r068E, r068F), 0x01));

   ir_expression *const r0690 = equal(r0681, body.constant(0u));
   ir_expression *const r0691 = less(r0686, body.constant(int(0)));
   ir_expression *const r0692 = neg(r0686);
   ir_expression *const r0693 = rshift(r0682, r0692);
   ir_expression *const r0694 = lshift(r0682, r0686);
   ir_expression *const r0695 = expr(ir_triop_csel, r0691, r0693, r0694);
   ir_expression *const r0696 = equal(r0686, body.constant(int(0)));
   ir_expression *const r0697 = lshift(r0681, r0686);
   ir_expression *const r0698 = neg(r0686);
   ir_expression *const r0699 = bit_and(r0698, body.constant(int(31)));
   ir_expression *const r069A = rshift(r0682, r0699);
   ir_expression *const r069B = bit_or(r0697, r069A);
   ir_expression *const r069C = expr(ir_triop_csel, r0696, r0681, r069B);
   body.emit(assign(r0684, expr(ir_triop_csel, r0690, r0695, r069C), 0x01));

   ir_expression *const r069D = equal(r0681, body.constant(0u));
   ir_expression *const r069E = less(r0686, body.constant(int(0)));
   ir_expression *const r069F = bit_and(r0686, body.constant(int(31)));
   ir_expression *const r06A0 = lshift(r0682, r069F);
   ir_expression *const r06A1 = expr(ir_triop_csel, r069E, r06A0, body.constant(0u));
   ir_expression *const r06A2 = lshift(r0682, r0686);
   body.emit(assign(r0685, expr(ir_triop_csel, r069D, r06A1, r06A2), 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fmul64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r06A3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r06A3);
   ir_variable *const r06A4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r06A4);
   ir_variable *const r06A5 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r06A5, body.constant(true), 0x01));

   ir_variable *const r06A6 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r06A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r06A7);
   ir_variable *const r06A8 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r06A8);
   ir_variable *const r06A9 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r06A9);
   ir_variable *const r06AA = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r06AA);
   ir_variable *const r06AB = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r06AB);
   ir_variable *const r06AC = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r06AC);
   ir_variable *const r06AD = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r06AD);
   ir_variable *const r06AE = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r06AE);
   ir_variable *const r06AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r06AF);
   ir_variable *const r06B0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r06B0);
   ir_variable *const r06B1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r06B1);
   body.emit(assign(r06B1, body.constant(0u), 0x01));

   body.emit(assign(r06B0, body.constant(0u), 0x01));

   body.emit(assign(r06AF, body.constant(0u), 0x01));

   body.emit(assign(r06AD, swizzle_x(r06A3), 0x01));

   ir_variable *const r06B2 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r06B2, bit_and(swizzle_y(r06A3), body.constant(1048575u)), 0x01));

   body.emit(assign(r06AC, r06B2, 0x01));

   body.emit(assign(r06AB, swizzle_x(r06A4), 0x01));

   ir_variable *const r06B3 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r06B3, bit_and(swizzle_y(r06A4), body.constant(1048575u)), 0x01));

   body.emit(assign(r06AA, r06B3, 0x01));

   ir_variable *const r06B4 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r06B5 = rshift(swizzle_y(r06A3), body.constant(int(20)));
   ir_expression *const r06B6 = bit_and(r06B5, body.constant(2047u));
   body.emit(assign(r06B4, expr(ir_unop_u2i, r06B6), 0x01));

   body.emit(assign(r06A9, r06B4, 0x01));

   ir_variable *const r06B7 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r06B8 = rshift(swizzle_y(r06A4), body.constant(int(20)));
   ir_expression *const r06B9 = bit_and(r06B8, body.constant(2047u));
   body.emit(assign(r06B7, expr(ir_unop_u2i, r06B9), 0x01));

   body.emit(assign(r06A8, r06B7, 0x01));

   ir_expression *const r06BA = rshift(swizzle_y(r06A3), body.constant(int(31)));
   ir_expression *const r06BB = rshift(swizzle_y(r06A4), body.constant(int(31)));
   body.emit(assign(r06A7, bit_xor(r06BA, r06BB), 0x01));

   /* IF CONDITION */
   ir_expression *const r06BD = equal(r06B4, body.constant(int(2047)));
   ir_if *f06BC = new(mem_ctx) ir_if(operand(r06BD).val);
   exec_list *const f06BC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f06BC->then_instructions;

      /* IF CONDITION */
      ir_expression *const r06BF = bit_or(r06B2, swizzle_x(r06A3));
      ir_expression *const r06C0 = nequal(r06BF, body.constant(0u));
      ir_expression *const r06C1 = equal(r06B7, body.constant(int(2047)));
      ir_expression *const r06C2 = bit_or(r06B3, swizzle_x(r06A4));
      ir_expression *const r06C3 = nequal(r06C2, body.constant(0u));
      ir_expression *const r06C4 = logic_and(r06C1, r06C3);
      ir_expression *const r06C5 = logic_or(r06C0, r06C4);
      ir_if *f06BE = new(mem_ctx) ir_if(operand(r06C5).val);
      exec_list *const f06BE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f06BE->then_instructions;

         ir_variable *const r06C6 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r06C6, swizzle_x(r06A3), 0x01));

         ir_variable *const r06C7 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r06C7, swizzle_x(r06A4), 0x01));

         body.emit(assign(r06C6, bit_or(swizzle_y(r06A3), body.constant(524288u)), 0x02));

         body.emit(assign(r06C7, bit_or(swizzle_y(r06A4), body.constant(524288u)), 0x02));

         ir_expression *const r06C8 = lshift(swizzle_y(r06A3), body.constant(int(1)));
         ir_expression *const r06C9 = gequal(r06C8, body.constant(4292870144u));
         ir_expression *const r06CA = nequal(swizzle_x(r06A3), body.constant(0u));
         ir_expression *const r06CB = bit_and(swizzle_y(r06A3), body.constant(1048575u));
         ir_expression *const r06CC = nequal(r06CB, body.constant(0u));
         ir_expression *const r06CD = logic_or(r06CA, r06CC);
         ir_expression *const r06CE = logic_and(r06C9, r06CD);
         ir_swizzle *const r06CF = swizzle(r06CE, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r06D0 = lshift(swizzle_y(r06A4), body.constant(int(1)));
         ir_expression *const r06D1 = gequal(r06D0, body.constant(4292870144u));
         ir_expression *const r06D2 = nequal(swizzle_x(r06A4), body.constant(0u));
         ir_expression *const r06D3 = bit_and(swizzle_y(r06A4), body.constant(1048575u));
         ir_expression *const r06D4 = nequal(r06D3, body.constant(0u));
         ir_expression *const r06D5 = logic_or(r06D2, r06D4);
         ir_expression *const r06D6 = logic_and(r06D1, r06D5);
         ir_swizzle *const r06D7 = swizzle(r06D6, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r06D8 = expr(ir_triop_csel, r06D7, r06C7, r06C6);
         body.emit(assign(r06A6, expr(ir_triop_csel, r06CF, r06D8, r06C7), 0x03));

         body.emit(assign(r06A5, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f06BE->else_instructions;

         /* IF CONDITION */
         ir_expression *const r06DA = expr(ir_unop_i2u, r06B7);
         ir_expression *const r06DB = bit_or(r06DA, r06B3);
         ir_expression *const r06DC = bit_or(r06DB, swizzle_x(r06A4));
         ir_expression *const r06DD = equal(r06DC, body.constant(0u));
         ir_if *f06D9 = new(mem_ctx) ir_if(operand(r06DD).val);
         exec_list *const f06D9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f06D9->then_instructions;

            ir_constant_data r06DE_data;
            memset(&r06DE_data, 0, sizeof(ir_constant_data));
            r06DE_data.u[0] = 4294967295;
            r06DE_data.u[1] = 4294967295;
            ir_constant *const r06DE = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r06DE_data);
            body.emit(assign(r06A6, r06DE, 0x03));

            body.emit(assign(r06A5, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f06D9->else_instructions;

            ir_variable *const r06DF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r06DF);
            ir_expression *const r06E0 = lshift(r06A7, body.constant(int(31)));
            body.emit(assign(r06DF, add(r06E0, body.constant(2146435072u)), 0x02));

            body.emit(assign(r06DF, body.constant(0u), 0x01));

            body.emit(assign(r06A6, r06DF, 0x03));

            body.emit(assign(r06A5, body.constant(false), 0x01));


         body.instructions = f06D9_parent_instructions;
         body.emit(f06D9);

         /* END IF */


      body.instructions = f06BE_parent_instructions;
      body.emit(f06BE);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f06BC->else_instructions;

      /* IF CONDITION */
      ir_expression *const r06E2 = equal(r06B7, body.constant(int(2047)));
      ir_if *f06E1 = new(mem_ctx) ir_if(operand(r06E2).val);
      exec_list *const f06E1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f06E1->then_instructions;

         /* IF CONDITION */
         ir_expression *const r06E4 = bit_or(r06B3, swizzle_x(r06A4));
         ir_expression *const r06E5 = nequal(r06E4, body.constant(0u));
         ir_if *f06E3 = new(mem_ctx) ir_if(operand(r06E5).val);
         exec_list *const f06E3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f06E3->then_instructions;

            ir_variable *const r06E6 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r06E6, swizzle_x(r06A3), 0x01));

            ir_variable *const r06E7 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r06E7, swizzle_x(r06A4), 0x01));

            body.emit(assign(r06E6, bit_or(swizzle_y(r06A3), body.constant(524288u)), 0x02));

            body.emit(assign(r06E7, bit_or(swizzle_y(r06A4), body.constant(524288u)), 0x02));

            ir_expression *const r06E8 = lshift(swizzle_y(r06A3), body.constant(int(1)));
            ir_expression *const r06E9 = gequal(r06E8, body.constant(4292870144u));
            ir_expression *const r06EA = nequal(swizzle_x(r06A3), body.constant(0u));
            ir_expression *const r06EB = bit_and(swizzle_y(r06A3), body.constant(1048575u));
            ir_expression *const r06EC = nequal(r06EB, body.constant(0u));
            ir_expression *const r06ED = logic_or(r06EA, r06EC);
            ir_expression *const r06EE = logic_and(r06E9, r06ED);
            ir_swizzle *const r06EF = swizzle(r06EE, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r06F0 = lshift(swizzle_y(r06A4), body.constant(int(1)));
            ir_expression *const r06F1 = gequal(r06F0, body.constant(4292870144u));
            ir_expression *const r06F2 = nequal(swizzle_x(r06A4), body.constant(0u));
            ir_expression *const r06F3 = bit_and(swizzle_y(r06A4), body.constant(1048575u));
            ir_expression *const r06F4 = nequal(r06F3, body.constant(0u));
            ir_expression *const r06F5 = logic_or(r06F2, r06F4);
            ir_expression *const r06F6 = logic_and(r06F1, r06F5);
            ir_swizzle *const r06F7 = swizzle(r06F6, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r06F8 = expr(ir_triop_csel, r06F7, r06E7, r06E6);
            body.emit(assign(r06A6, expr(ir_triop_csel, r06EF, r06F8, r06E7), 0x03));

            body.emit(assign(r06A5, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f06E3->else_instructions;

            /* IF CONDITION */
            ir_expression *const r06FA = expr(ir_unop_i2u, r06B4);
            ir_expression *const r06FB = bit_or(r06FA, r06B2);
            ir_expression *const r06FC = bit_or(r06FB, swizzle_x(r06A3));
            ir_expression *const r06FD = equal(r06FC, body.constant(0u));
            ir_if *f06F9 = new(mem_ctx) ir_if(operand(r06FD).val);
            exec_list *const f06F9_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f06F9->then_instructions;

               ir_constant_data r06FE_data;
               memset(&r06FE_data, 0, sizeof(ir_constant_data));
               r06FE_data.u[0] = 4294967295;
               r06FE_data.u[1] = 4294967295;
               ir_constant *const r06FE = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r06FE_data);
               body.emit(assign(r06A6, r06FE, 0x03));

               body.emit(assign(r06A5, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f06F9->else_instructions;

               ir_variable *const r06FF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r06FF);
               ir_expression *const r0700 = lshift(r06A7, body.constant(int(31)));
               body.emit(assign(r06FF, add(r0700, body.constant(2146435072u)), 0x02));

               body.emit(assign(r06FF, body.constant(0u), 0x01));

               body.emit(assign(r06A6, r06FF, 0x03));

               body.emit(assign(r06A5, body.constant(false), 0x01));


            body.instructions = f06F9_parent_instructions;
            body.emit(f06F9);

            /* END IF */


         body.instructions = f06E3_parent_instructions;
         body.emit(f06E3);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f06E1->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0702 = equal(r06B4, body.constant(int(0)));
         ir_if *f0701 = new(mem_ctx) ir_if(operand(r0702).val);
         exec_list *const f0701_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0701->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0704 = bit_or(r06B2, swizzle_x(r06A3));
            ir_expression *const r0705 = equal(r0704, body.constant(0u));
            ir_if *f0703 = new(mem_ctx) ir_if(operand(r0705).val);
            exec_list *const f0703_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0703->then_instructions;

               ir_variable *const r0706 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0706);
               body.emit(assign(r0706, lshift(r06A7, body.constant(int(31))), 0x02));

               body.emit(assign(r0706, body.constant(0u), 0x01));

               body.emit(assign(r06A6, r0706, 0x03));

               body.emit(assign(r06A5, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0703->else_instructions;

               ir_variable *const r0707 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0707);
               ir_variable *const r0708 = body.make_temp(glsl_type::uint_type, "a");
               ir_expression *const r0709 = equal(r06B2, body.constant(0u));
               body.emit(assign(r0708, expr(ir_triop_csel, r0709, swizzle_x(r06A3), r06B2), 0x01));

               ir_expression *const r070A = equal(r0708, body.constant(0u));
               ir_expression *const r070B = expr(ir_unop_find_msb, r0708);
               ir_expression *const r070C = sub(body.constant(int(31)), r070B);
               ir_expression *const r070D = expr(ir_triop_csel, r070A, body.constant(int(32)), r070C);
               body.emit(assign(r0707, add(r070D, body.constant(int(-11))), 0x01));

               ir_expression *const r070E = equal(r06B2, body.constant(0u));
               ir_expression *const r070F = sub(body.constant(int(-31)), r0707);
               ir_expression *const r0710 = sub(body.constant(int(1)), r0707);
               body.emit(assign(r06A9, expr(ir_triop_csel, r070E, r070F, r0710), 0x01));

               ir_expression *const r0711 = equal(r06B2, body.constant(0u));
               ir_expression *const r0712 = less(r0707, body.constant(int(0)));
               ir_expression *const r0713 = neg(r0707);
               ir_expression *const r0714 = rshift(swizzle_x(r06A3), r0713);
               ir_expression *const r0715 = lshift(swizzle_x(r06A3), r0707);
               ir_expression *const r0716 = expr(ir_triop_csel, r0712, r0714, r0715);
               ir_expression *const r0717 = equal(r0707, body.constant(int(0)));
               ir_expression *const r0718 = lshift(r06B2, r0707);
               ir_expression *const r0719 = neg(r0707);
               ir_expression *const r071A = bit_and(r0719, body.constant(int(31)));
               ir_expression *const r071B = rshift(swizzle_x(r06A3), r071A);
               ir_expression *const r071C = bit_or(r0718, r071B);
               ir_expression *const r071D = expr(ir_triop_csel, r0717, r06B2, r071C);
               body.emit(assign(r06AC, expr(ir_triop_csel, r0711, r0716, r071D), 0x01));

               ir_expression *const r071E = equal(r06B2, body.constant(0u));
               ir_expression *const r071F = less(r0707, body.constant(int(0)));
               ir_expression *const r0720 = bit_and(r0707, body.constant(int(31)));
               ir_expression *const r0721 = lshift(swizzle_x(r06A3), r0720);
               ir_expression *const r0722 = expr(ir_triop_csel, r071F, r0721, body.constant(0u));
               ir_expression *const r0723 = lshift(swizzle_x(r06A3), r0707);
               body.emit(assign(r06AD, expr(ir_triop_csel, r071E, r0722, r0723), 0x01));


            body.instructions = f0703_parent_instructions;
            body.emit(f0703);

            /* END IF */


         body.instructions = f0701_parent_instructions;
         body.emit(f0701);

         /* END IF */

         /* IF CONDITION */
         ir_if *f0724 = new(mem_ctx) ir_if(operand(r06A5).val);
         exec_list *const f0724_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0724->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0726 = equal(r06B7, body.constant(int(0)));
            ir_if *f0725 = new(mem_ctx) ir_if(operand(r0726).val);
            exec_list *const f0725_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0725->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0728 = bit_or(r06B3, swizzle_x(r06A4));
               ir_expression *const r0729 = equal(r0728, body.constant(0u));
               ir_if *f0727 = new(mem_ctx) ir_if(operand(r0729).val);
               exec_list *const f0727_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0727->then_instructions;

                  ir_variable *const r072A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r072A);
                  body.emit(assign(r072A, lshift(r06A7, body.constant(int(31))), 0x02));

                  body.emit(assign(r072A, body.constant(0u), 0x01));

                  body.emit(assign(r06A6, r072A, 0x03));

                  body.emit(assign(r06A5, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0727->else_instructions;

                  ir_variable *const r072B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r072B);
                  ir_variable *const r072C = body.make_temp(glsl_type::uint_type, "a");
                  ir_expression *const r072D = equal(r06B3, body.constant(0u));
                  body.emit(assign(r072C, expr(ir_triop_csel, r072D, swizzle_x(r06A4), r06B3), 0x01));

                  ir_expression *const r072E = equal(r072C, body.constant(0u));
                  ir_expression *const r072F = expr(ir_unop_find_msb, r072C);
                  ir_expression *const r0730 = sub(body.constant(int(31)), r072F);
                  ir_expression *const r0731 = expr(ir_triop_csel, r072E, body.constant(int(32)), r0730);
                  body.emit(assign(r072B, add(r0731, body.constant(int(-11))), 0x01));

                  ir_expression *const r0732 = equal(r06B3, body.constant(0u));
                  ir_expression *const r0733 = sub(body.constant(int(-31)), r072B);
                  ir_expression *const r0734 = sub(body.constant(int(1)), r072B);
                  body.emit(assign(r06A8, expr(ir_triop_csel, r0732, r0733, r0734), 0x01));

                  ir_expression *const r0735 = equal(r06B3, body.constant(0u));
                  ir_expression *const r0736 = less(r072B, body.constant(int(0)));
                  ir_expression *const r0737 = neg(r072B);
                  ir_expression *const r0738 = rshift(swizzle_x(r06A4), r0737);
                  ir_expression *const r0739 = lshift(swizzle_x(r06A4), r072B);
                  ir_expression *const r073A = expr(ir_triop_csel, r0736, r0738, r0739);
                  ir_expression *const r073B = equal(r072B, body.constant(int(0)));
                  ir_expression *const r073C = lshift(r06B3, r072B);
                  ir_expression *const r073D = neg(r072B);
                  ir_expression *const r073E = bit_and(r073D, body.constant(int(31)));
                  ir_expression *const r073F = rshift(swizzle_x(r06A4), r073E);
                  ir_expression *const r0740 = bit_or(r073C, r073F);
                  ir_expression *const r0741 = expr(ir_triop_csel, r073B, r06B3, r0740);
                  body.emit(assign(r06AA, expr(ir_triop_csel, r0735, r073A, r0741), 0x01));

                  ir_expression *const r0742 = equal(r06B3, body.constant(0u));
                  ir_expression *const r0743 = less(r072B, body.constant(int(0)));
                  ir_expression *const r0744 = bit_and(r072B, body.constant(int(31)));
                  ir_expression *const r0745 = lshift(swizzle_x(r06A4), r0744);
                  ir_expression *const r0746 = expr(ir_triop_csel, r0743, r0745, body.constant(0u));
                  ir_expression *const r0747 = lshift(swizzle_x(r06A4), r072B);
                  body.emit(assign(r06AB, expr(ir_triop_csel, r0742, r0746, r0747), 0x01));


               body.instructions = f0727_parent_instructions;
               body.emit(f0727);

               /* END IF */


            body.instructions = f0725_parent_instructions;
            body.emit(f0725);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0748 = new(mem_ctx) ir_if(operand(r06A5).val);
            exec_list *const f0748_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0748->then_instructions;

               ir_expression *const r0749 = add(r06A9, r06A8);
               body.emit(assign(r06AE, add(r0749, body.constant(int(-1024))), 0x01));

               body.emit(assign(r06AC, bit_or(r06AC, body.constant(1048576u)), 0x01));

               ir_variable *const r074A = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r074B = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r074B, lshift(r06AB, body.constant(int(12))), 0x01));

               ir_expression *const r074C = lshift(r06AA, body.constant(int(12)));
               ir_expression *const r074D = rshift(r06AB, body.constant(int(20)));
               body.emit(assign(r074A, bit_or(r074C, r074D), 0x01));

               body.emit(assign(r06AA, r074A, 0x01));

               body.emit(assign(r06AB, r074B, 0x01));

               ir_variable *const r074E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r074E);
               ir_variable *const r074F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r074F);
               ir_variable *const r0750 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0750);
               ir_variable *const r0751 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0751, bit_and(r06AD, body.constant(65535u)), 0x01));

               ir_variable *const r0752 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0752, rshift(r06AD, body.constant(int(16))), 0x01));

               ir_variable *const r0753 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0753, bit_and(r074B, body.constant(65535u)), 0x01));

               ir_variable *const r0754 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0754, rshift(r074B, body.constant(int(16))), 0x01));

               ir_variable *const r0755 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0755, mul(r0752, r0753), 0x01));

               ir_expression *const r0756 = mul(r0751, r0754);
               body.emit(assign(r074F, add(r0756, r0755), 0x01));

               ir_expression *const r0757 = mul(r0752, r0754);
               ir_expression *const r0758 = less(r074F, r0755);
               ir_expression *const r0759 = expr(ir_unop_b2i, r0758);
               ir_expression *const r075A = expr(ir_unop_i2u, r0759);
               ir_expression *const r075B = lshift(r075A, body.constant(int(16)));
               ir_expression *const r075C = rshift(r074F, body.constant(int(16)));
               ir_expression *const r075D = add(r075B, r075C);
               body.emit(assign(r074E, add(r0757, r075D), 0x01));

               body.emit(assign(r074F, lshift(r074F, body.constant(int(16))), 0x01));

               ir_expression *const r075E = mul(r0751, r0753);
               body.emit(assign(r0750, add(r075E, r074F), 0x01));

               ir_expression *const r075F = less(r0750, r074F);
               ir_expression *const r0760 = expr(ir_unop_b2i, r075F);
               ir_expression *const r0761 = expr(ir_unop_i2u, r0760);
               body.emit(assign(r074E, add(r074E, r0761), 0x01));

               ir_variable *const r0762 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0762);
               ir_variable *const r0763 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0763);
               ir_variable *const r0764 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0764);
               ir_variable *const r0765 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0765, bit_and(r06AD, body.constant(65535u)), 0x01));

               ir_variable *const r0766 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0766, rshift(r06AD, body.constant(int(16))), 0x01));

               ir_variable *const r0767 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0767, bit_and(r074A, body.constant(65535u)), 0x01));

               ir_variable *const r0768 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0768, rshift(r074A, body.constant(int(16))), 0x01));

               ir_variable *const r0769 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0769, mul(r0766, r0767), 0x01));

               ir_expression *const r076A = mul(r0765, r0768);
               body.emit(assign(r0763, add(r076A, r0769), 0x01));

               ir_expression *const r076B = mul(r0766, r0768);
               ir_expression *const r076C = less(r0763, r0769);
               ir_expression *const r076D = expr(ir_unop_b2i, r076C);
               ir_expression *const r076E = expr(ir_unop_i2u, r076D);
               ir_expression *const r076F = lshift(r076E, body.constant(int(16)));
               ir_expression *const r0770 = rshift(r0763, body.constant(int(16)));
               ir_expression *const r0771 = add(r076F, r0770);
               body.emit(assign(r0762, add(r076B, r0771), 0x01));

               body.emit(assign(r0763, lshift(r0763, body.constant(int(16))), 0x01));

               ir_expression *const r0772 = mul(r0765, r0767);
               body.emit(assign(r0764, add(r0772, r0763), 0x01));

               ir_expression *const r0773 = less(r0764, r0763);
               ir_expression *const r0774 = expr(ir_unop_b2i, r0773);
               ir_expression *const r0775 = expr(ir_unop_i2u, r0774);
               body.emit(assign(r0762, add(r0762, r0775), 0x01));

               ir_variable *const r0776 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0776, add(r0764, r074E), 0x01));

               ir_variable *const r0777 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0777);
               ir_variable *const r0778 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0778);
               ir_variable *const r0779 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0779);
               ir_variable *const r077A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r077A, bit_and(r06AC, body.constant(65535u)), 0x01));

               ir_variable *const r077B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r077B, rshift(r06AC, body.constant(int(16))), 0x01));

               ir_variable *const r077C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r077C, bit_and(r074A, body.constant(65535u)), 0x01));

               ir_variable *const r077D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r077D, rshift(r074A, body.constant(int(16))), 0x01));

               ir_variable *const r077E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r077E, mul(r077B, r077C), 0x01));

               ir_expression *const r077F = mul(r077A, r077D);
               body.emit(assign(r0778, add(r077F, r077E), 0x01));

               ir_expression *const r0780 = mul(r077B, r077D);
               ir_expression *const r0781 = less(r0778, r077E);
               ir_expression *const r0782 = expr(ir_unop_b2i, r0781);
               ir_expression *const r0783 = expr(ir_unop_i2u, r0782);
               ir_expression *const r0784 = lshift(r0783, body.constant(int(16)));
               ir_expression *const r0785 = rshift(r0778, body.constant(int(16)));
               ir_expression *const r0786 = add(r0784, r0785);
               body.emit(assign(r0777, add(r0780, r0786), 0x01));

               body.emit(assign(r0778, lshift(r0778, body.constant(int(16))), 0x01));

               ir_expression *const r0787 = mul(r077A, r077C);
               body.emit(assign(r0779, add(r0787, r0778), 0x01));

               ir_expression *const r0788 = less(r0779, r0778);
               ir_expression *const r0789 = expr(ir_unop_b2i, r0788);
               ir_expression *const r078A = expr(ir_unop_i2u, r0789);
               body.emit(assign(r0777, add(r0777, r078A), 0x01));

               ir_variable *const r078B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r078C = less(r0776, r0764);
               ir_expression *const r078D = expr(ir_unop_b2i, r078C);
               ir_expression *const r078E = expr(ir_unop_i2u, r078D);
               ir_expression *const r078F = add(r0762, r078E);
               body.emit(assign(r078B, add(r0779, r078F), 0x01));

               ir_variable *const r0790 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0790);
               ir_variable *const r0791 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0791);
               ir_variable *const r0792 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0792);
               ir_variable *const r0793 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0793, bit_and(r06AC, body.constant(65535u)), 0x01));

               ir_variable *const r0794 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0794, rshift(r06AC, body.constant(int(16))), 0x01));

               ir_variable *const r0795 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0795, bit_and(r074B, body.constant(65535u)), 0x01));

               ir_variable *const r0796 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0796, rshift(r074B, body.constant(int(16))), 0x01));

               ir_variable *const r0797 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0797, mul(r0794, r0795), 0x01));

               ir_expression *const r0798 = mul(r0793, r0796);
               body.emit(assign(r0791, add(r0798, r0797), 0x01));

               ir_expression *const r0799 = mul(r0794, r0796);
               ir_expression *const r079A = less(r0791, r0797);
               ir_expression *const r079B = expr(ir_unop_b2i, r079A);
               ir_expression *const r079C = expr(ir_unop_i2u, r079B);
               ir_expression *const r079D = lshift(r079C, body.constant(int(16)));
               ir_expression *const r079E = rshift(r0791, body.constant(int(16)));
               ir_expression *const r079F = add(r079D, r079E);
               body.emit(assign(r0790, add(r0799, r079F), 0x01));

               body.emit(assign(r0791, lshift(r0791, body.constant(int(16))), 0x01));

               ir_expression *const r07A0 = mul(r0793, r0795);
               body.emit(assign(r0792, add(r07A0, r0791), 0x01));

               ir_expression *const r07A1 = less(r0792, r0791);
               ir_expression *const r07A2 = expr(ir_unop_b2i, r07A1);
               ir_expression *const r07A3 = expr(ir_unop_i2u, r07A2);
               body.emit(assign(r0790, add(r0790, r07A3), 0x01));

               ir_variable *const r07A4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07A4, add(r0792, r0776), 0x01));

               ir_variable *const r07A5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r07A6 = less(r07A4, r0792);
               ir_expression *const r07A7 = expr(ir_unop_b2i, r07A6);
               ir_expression *const r07A8 = expr(ir_unop_i2u, r07A7);
               ir_expression *const r07A9 = add(r0790, r07A8);
               body.emit(assign(r07A5, add(r078B, r07A9), 0x01));

               ir_variable *const r07AA = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r07AB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07AB, add(r07A5, r06AD), 0x01));

               ir_expression *const r07AC = less(r078B, r0779);
               ir_expression *const r07AD = expr(ir_unop_b2i, r07AC);
               ir_expression *const r07AE = expr(ir_unop_i2u, r07AD);
               ir_expression *const r07AF = add(r0777, r07AE);
               ir_expression *const r07B0 = less(r07A5, r078B);
               ir_expression *const r07B1 = expr(ir_unop_b2i, r07B0);
               ir_expression *const r07B2 = expr(ir_unop_i2u, r07B1);
               ir_expression *const r07B3 = add(r07AF, r07B2);
               ir_expression *const r07B4 = add(r07B3, r06AC);
               ir_expression *const r07B5 = less(r07AB, r07A5);
               ir_expression *const r07B6 = expr(ir_unop_b2i, r07B5);
               ir_expression *const r07B7 = expr(ir_unop_i2u, r07B6);
               body.emit(assign(r07AA, add(r07B4, r07B7), 0x01));

               body.emit(assign(r06B1, r07AA, 0x01));

               body.emit(assign(r06B0, r07AB, 0x01));

               ir_expression *const r07B8 = nequal(r0750, body.constant(0u));
               ir_expression *const r07B9 = expr(ir_unop_b2i, r07B8);
               ir_expression *const r07BA = expr(ir_unop_i2u, r07B9);
               body.emit(assign(r06AF, bit_or(r07A4, r07BA), 0x01));

               /* IF CONDITION */
               ir_expression *const r07BC = gequal(r07AA, body.constant(2097152u));
               ir_if *f07BB = new(mem_ctx) ir_if(operand(r07BC).val);
               exec_list *const f07BB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f07BB->then_instructions;

                  body.emit(assign(r06B1, rshift(r07AA, body.constant(int(1))), 0x01));

                  ir_expression *const r07BD = lshift(r07AA, body.constant(int(31)));
                  ir_expression *const r07BE = rshift(r07AB, body.constant(int(1)));
                  body.emit(assign(r06B0, bit_or(r07BD, r07BE), 0x01));

                  ir_expression *const r07BF = lshift(r07AB, body.constant(int(31)));
                  ir_expression *const r07C0 = nequal(r06AF, body.constant(0u));
                  ir_expression *const r07C1 = expr(ir_unop_b2i, r07C0);
                  ir_expression *const r07C2 = expr(ir_unop_i2u, r07C1);
                  body.emit(assign(r06AF, bit_or(r07BF, r07C2), 0x01));

                  body.emit(assign(r06AE, add(r06AE, body.constant(int(1))), 0x01));


               body.instructions = f07BB_parent_instructions;
               body.emit(f07BB);

               /* END IF */

               ir_variable *const r07C3 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r07C3, r06AE, 0x01));

               ir_variable *const r07C4 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r07C4, r06B1, 0x01));

               ir_variable *const r07C5 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r07C5, r06B0, 0x01));

               ir_variable *const r07C6 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r07C6, r06AF, 0x01));

               ir_variable *const r07C7 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r07C7, body.constant(true), 0x01));

               ir_variable *const r07C8 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r07C9 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r07C9);
               ir_expression *const r07CA = expr(ir_unop_u2i, r06AF);
               body.emit(assign(r07C9, less(r07CA, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r07CC = gequal(r06AE, body.constant(int(2045)));
               ir_if *f07CB = new(mem_ctx) ir_if(operand(r07CC).val);
               exec_list *const f07CB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f07CB->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r07CE = less(body.constant(int(2045)), r06AE);
                  ir_expression *const r07CF = equal(r06AE, body.constant(int(2045)));
                  ir_expression *const r07D0 = equal(body.constant(2097151u), r06B1);
                  ir_expression *const r07D1 = equal(body.constant(4294967295u), r06B0);
                  ir_expression *const r07D2 = logic_and(r07D0, r07D1);
                  ir_expression *const r07D3 = logic_and(r07CF, r07D2);
                  ir_expression *const r07D4 = logic_and(r07D3, r07C9);
                  ir_expression *const r07D5 = logic_or(r07CE, r07D4);
                  ir_if *f07CD = new(mem_ctx) ir_if(operand(r07D5).val);
                  exec_list *const f07CD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f07CD->then_instructions;

                     ir_variable *const r07D6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r07D6);
                     ir_expression *const r07D7 = lshift(r06A7, body.constant(int(31)));
                     body.emit(assign(r07D6, add(r07D7, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r07D6, body.constant(0u), 0x01));

                     body.emit(assign(r07C8, r07D6, 0x03));

                     body.emit(assign(r07C7, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f07CD->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r07D9 = less(r06AE, body.constant(int(0)));
                     ir_if *f07D8 = new(mem_ctx) ir_if(operand(r07D9).val);
                     exec_list *const f07D8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f07D8->then_instructions;

                        ir_variable *const r07DA = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r07DA, neg(r06AE), 0x01));

                        ir_variable *const r07DB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r07DB);
                        ir_variable *const r07DC = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r07DD = neg(r07DA);
                        body.emit(assign(r07DC, bit_and(r07DD, body.constant(int(31))), 0x01));

                        ir_variable *const r07DE = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r07DF = less(r07DA, body.constant(int(32)));
                        ir_expression *const r07E0 = bit_or(r06AF, r06B0);
                        body.emit(assign(r07DE, expr(ir_triop_csel, r07DF, r06AF, r07E0), 0x01));

                        ir_expression *const r07E1 = less(r07DA, body.constant(int(32)));
                        ir_expression *const r07E2 = lshift(r06B0, r07DC);
                        ir_expression *const r07E3 = less(r07DA, body.constant(int(64)));
                        ir_expression *const r07E4 = lshift(r06B1, r07DC);
                        ir_expression *const r07E5 = equal(r07DA, body.constant(int(64)));
                        ir_expression *const r07E6 = nequal(r06B1, body.constant(0u));
                        ir_expression *const r07E7 = expr(ir_unop_b2i, r07E6);
                        ir_expression *const r07E8 = expr(ir_unop_i2u, r07E7);
                        ir_expression *const r07E9 = expr(ir_triop_csel, r07E5, r06B1, r07E8);
                        ir_expression *const r07EA = expr(ir_triop_csel, r07E3, r07E4, r07E9);
                        ir_expression *const r07EB = expr(ir_triop_csel, r07E1, r07E2, r07EA);
                        ir_expression *const r07EC = nequal(r07DE, body.constant(0u));
                        ir_expression *const r07ED = expr(ir_unop_b2i, r07EC);
                        ir_expression *const r07EE = expr(ir_unop_i2u, r07ED);
                        body.emit(assign(r07DB, bit_or(r07EB, r07EE), 0x01));

                        ir_variable *const r07EF = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r07F0 = equal(r07DA, body.constant(int(0)));
                        ir_expression *const r07F1 = equal(r07DA, body.constant(int(32)));
                        ir_expression *const r07F2 = expr(ir_triop_csel, r07F1, r06B0, r07DB);
                        body.emit(assign(r07EF, expr(ir_triop_csel, r07F0, r07DE, r07F2), 0x01));

                        body.emit(assign(r07DB, r07EF, 0x01));

                        ir_expression *const r07F3 = equal(r07DA, body.constant(int(0)));
                        ir_expression *const r07F4 = equal(r07DA, body.constant(int(32)));
                        ir_expression *const r07F5 = less(r07DA, body.constant(int(32)));
                        ir_expression *const r07F6 = rshift(r06B1, r07DA);
                        ir_expression *const r07F7 = expr(ir_triop_csel, r07F5, r07F6, body.constant(0u));
                        ir_expression *const r07F8 = expr(ir_triop_csel, r07F4, body.constant(0u), r07F7);
                        body.emit(assign(r07C4, expr(ir_triop_csel, r07F3, r06B1, r07F8), 0x01));

                        ir_expression *const r07F9 = equal(r07DA, body.constant(int(0)));
                        ir_expression *const r07FA = equal(r07DA, body.constant(int(32)));
                        ir_expression *const r07FB = less(r07DA, body.constant(int(32)));
                        ir_expression *const r07FC = lshift(r06B1, r07DC);
                        ir_expression *const r07FD = rshift(r06B0, r07DA);
                        ir_expression *const r07FE = bit_or(r07FC, r07FD);
                        ir_expression *const r07FF = less(r07DA, body.constant(int(64)));
                        ir_expression *const r0800 = bit_and(r07DA, body.constant(int(31)));
                        ir_expression *const r0801 = rshift(r06B1, r0800);
                        ir_expression *const r0802 = expr(ir_triop_csel, r07FF, r0801, body.constant(0u));
                        ir_expression *const r0803 = expr(ir_triop_csel, r07FB, r07FE, r0802);
                        ir_expression *const r0804 = expr(ir_triop_csel, r07FA, r06B1, r0803);
                        body.emit(assign(r07C5, expr(ir_triop_csel, r07F9, r06B0, r0804), 0x01));

                        body.emit(assign(r07C6, r07EF, 0x01));

                        body.emit(assign(r07C3, body.constant(int(0)), 0x01));

                        body.emit(assign(r07C9, less(r07EF, body.constant(0u)), 0x01));


                     body.instructions = f07D8_parent_instructions;
                     body.emit(f07D8);

                     /* END IF */


                  body.instructions = f07CD_parent_instructions;
                  body.emit(f07CD);

                  /* END IF */


               body.instructions = f07CB_parent_instructions;
               body.emit(f07CB);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0805 = new(mem_ctx) ir_if(operand(r07C7).val);
               exec_list *const f0805_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0805->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0806 = new(mem_ctx) ir_if(operand(r07C9).val);
                  exec_list *const f0806_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0806->then_instructions;

                     ir_variable *const r0807 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0807, add(r07C5, body.constant(1u)), 0x01));

                     ir_expression *const r0808 = less(r0807, r07C5);
                     ir_expression *const r0809 = expr(ir_unop_b2i, r0808);
                     ir_expression *const r080A = expr(ir_unop_i2u, r0809);
                     body.emit(assign(r07C4, add(r07C4, r080A), 0x01));

                     ir_expression *const r080B = equal(r07C6, body.constant(0u));
                     ir_expression *const r080C = expr(ir_unop_b2i, r080B);
                     ir_expression *const r080D = expr(ir_unop_i2u, r080C);
                     ir_expression *const r080E = add(r07C6, r080D);
                     ir_expression *const r080F = bit_and(r080E, body.constant(1u));
                     ir_expression *const r0810 = expr(ir_unop_bit_not, r080F);
                     body.emit(assign(r07C5, bit_and(r0807, r0810), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0806->else_instructions;

                     ir_expression *const r0811 = bit_or(r07C4, r07C5);
                     ir_expression *const r0812 = equal(r0811, body.constant(0u));
                     body.emit(assign(r07C3, expr(ir_triop_csel, r0812, body.constant(int(0)), r07C3), 0x01));


                  body.instructions = f0806_parent_instructions;
                  body.emit(f0806);

                  /* END IF */

                  ir_variable *const r0813 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0813);
                  ir_expression *const r0814 = lshift(r06A7, body.constant(int(31)));
                  ir_expression *const r0815 = expr(ir_unop_i2u, r07C3);
                  ir_expression *const r0816 = lshift(r0815, body.constant(int(20)));
                  ir_expression *const r0817 = add(r0814, r0816);
                  body.emit(assign(r0813, add(r0817, r07C4), 0x02));

                  body.emit(assign(r0813, r07C5, 0x01));

                  body.emit(assign(r07C8, r0813, 0x03));

                  body.emit(assign(r07C7, body.constant(false), 0x01));


               body.instructions = f0805_parent_instructions;
               body.emit(f0805);

               /* END IF */

               body.emit(assign(r06A6, r07C8, 0x03));

               body.emit(assign(r06A5, body.constant(false), 0x01));


            body.instructions = f0748_parent_instructions;
            body.emit(f0748);

            /* END IF */


         body.instructions = f0724_parent_instructions;
         body.emit(f0724);

         /* END IF */


      body.instructions = f06E1_parent_instructions;
      body.emit(f06E1);

      /* END IF */


   body.instructions = f06BC_parent_instructions;
   body.emit(f06BC);

   /* END IF */

   body.emit(ret(r06A6));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
shift64Right(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0818 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0818);
   ir_variable *const r0819 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0819);
   ir_variable *const r081A = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r081A);
   ir_variable *const r081B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r081B);
   ir_variable *const r081C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r081C);
   ir_expression *const r081D = equal(r081A, body.constant(int(0)));
   ir_expression *const r081E = less(r081A, body.constant(int(32)));
   ir_expression *const r081F = neg(r081A);
   ir_expression *const r0820 = bit_and(r081F, body.constant(int(31)));
   ir_expression *const r0821 = lshift(r0818, r0820);
   ir_expression *const r0822 = rshift(r0819, r081A);
   ir_expression *const r0823 = bit_or(r0821, r0822);
   ir_expression *const r0824 = less(r081A, body.constant(int(64)));
   ir_expression *const r0825 = bit_and(r081A, body.constant(int(31)));
   ir_expression *const r0826 = rshift(r0818, r0825);
   ir_expression *const r0827 = expr(ir_triop_csel, r0824, r0826, body.constant(0u));
   ir_expression *const r0828 = expr(ir_triop_csel, r081E, r0823, r0827);
   body.emit(assign(r081C, expr(ir_triop_csel, r081D, r0818, r0828), 0x01));

   ir_expression *const r0829 = equal(r081A, body.constant(int(0)));
   ir_expression *const r082A = less(r081A, body.constant(int(32)));
   ir_expression *const r082B = rshift(r0818, r081A);
   ir_expression *const r082C = expr(ir_triop_csel, r082A, r082B, body.constant(0u));
   body.emit(assign(r081B, expr(ir_triop_csel, r0829, r0818, r082C), 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fp64_to_uint(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uint_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r082D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r082D);
   ir_variable *const r082E = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r082F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r082F);
   ir_variable *const r0830 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0830);
   body.emit(assign(r0830, swizzle_x(r082D), 0x01));

   ir_variable *const r0831 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0831, bit_and(swizzle_y(r082D), body.constant(1048575u)), 0x01));

   body.emit(assign(r082F, r0831, 0x01));

   ir_variable *const r0832 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0833 = rshift(swizzle_y(r082D), body.constant(int(20)));
   ir_expression *const r0834 = bit_and(r0833, body.constant(2047u));
   body.emit(assign(r0832, expr(ir_unop_u2i, r0834), 0x01));

   ir_variable *const r0835 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0835, rshift(swizzle_y(r082D), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0837 = equal(r0832, body.constant(int(2047)));
   ir_expression *const r0838 = bit_or(r0831, swizzle_x(r082D));
   ir_expression *const r0839 = nequal(r0838, body.constant(0u));
   ir_expression *const r083A = logic_and(r0837, r0839);
   ir_if *f0836 = new(mem_ctx) ir_if(operand(r083A).val);
   exec_list *const f0836_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0836->then_instructions;

      body.emit(assign(r082E, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0836->else_instructions;

      /* IF CONDITION */
      ir_expression *const r083C = nequal(r0832, body.constant(int(0)));
      ir_if *f083B = new(mem_ctx) ir_if(operand(r083C).val);
      exec_list *const f083B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f083B->then_instructions;

         body.emit(assign(r082F, bit_or(r0831, body.constant(1048576u)), 0x01));


      body.instructions = f083B_parent_instructions;
      body.emit(f083B);

      /* END IF */

      ir_variable *const r083D = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r083D, sub(body.constant(int(1063)), r0832), 0x01));

      /* IF CONDITION */
      ir_expression *const r083F = less(body.constant(int(0)), r083D);
      ir_if *f083E = new(mem_ctx) ir_if(operand(r083F).val);
      exec_list *const f083E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f083E->then_instructions;

         ir_variable *const r0840 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
         body.emit(r0840);
         ir_variable *const r0841 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         ir_expression *const r0842 = neg(r083D);
         body.emit(assign(r0841, bit_and(r0842, body.constant(int(31))), 0x01));

         ir_expression *const r0843 = bit_or(r082F, swizzle_x(r082D));
         ir_expression *const r0844 = nequal(r0843, body.constant(0u));
         ir_expression *const r0845 = expr(ir_unop_b2i, r0844);
         body.emit(assign(r0840, expr(ir_unop_i2u, r0845), 0x01));

         ir_variable *const r0846 = body.make_temp(glsl_type::uint_type, "mix_retval");
         ir_expression *const r0847 = equal(r083D, body.constant(int(0)));
         ir_expression *const r0848 = less(r083D, body.constant(int(32)));
         ir_expression *const r0849 = lshift(r082F, r0841);
         ir_expression *const r084A = rshift(swizzle_x(r082D), r083D);
         ir_expression *const r084B = bit_or(r0849, r084A);
         ir_expression *const r084C = lshift(swizzle_x(r082D), r0841);
         ir_expression *const r084D = nequal(r084C, body.constant(0u));
         ir_expression *const r084E = expr(ir_unop_b2i, r084D);
         ir_expression *const r084F = expr(ir_unop_i2u, r084E);
         ir_expression *const r0850 = bit_or(r084B, r084F);
         ir_expression *const r0851 = equal(r083D, body.constant(int(32)));
         ir_expression *const r0852 = nequal(swizzle_x(r082D), body.constant(0u));
         ir_expression *const r0853 = expr(ir_unop_b2i, r0852);
         ir_expression *const r0854 = expr(ir_unop_i2u, r0853);
         ir_expression *const r0855 = bit_or(r082F, r0854);
         ir_expression *const r0856 = less(r083D, body.constant(int(64)));
         ir_expression *const r0857 = bit_and(r083D, body.constant(int(31)));
         ir_expression *const r0858 = rshift(r082F, r0857);
         ir_expression *const r0859 = lshift(r082F, r0841);
         ir_expression *const r085A = bit_or(r0859, swizzle_x(r082D));
         ir_expression *const r085B = nequal(r085A, body.constant(0u));
         ir_expression *const r085C = expr(ir_unop_b2i, r085B);
         ir_expression *const r085D = expr(ir_unop_i2u, r085C);
         ir_expression *const r085E = bit_or(r0858, r085D);
         ir_expression *const r085F = expr(ir_triop_csel, r0856, r085E, r0840);
         ir_expression *const r0860 = expr(ir_triop_csel, r0851, r0855, r085F);
         ir_expression *const r0861 = expr(ir_triop_csel, r0848, r0850, r0860);
         body.emit(assign(r0846, expr(ir_triop_csel, r0847, swizzle_x(r082D), r0861), 0x01));

         body.emit(assign(r0840, r0846, 0x01));

         ir_expression *const r0862 = less(r083D, body.constant(int(32)));
         ir_expression *const r0863 = rshift(r082F, r083D);
         ir_expression *const r0864 = equal(r083D, body.constant(int(0)));
         ir_expression *const r0865 = expr(ir_triop_csel, r0864, r082F, body.constant(0u));
         body.emit(assign(r082F, expr(ir_triop_csel, r0862, r0863, r0865), 0x01));

         body.emit(assign(r0830, r0846, 0x01));


      body.instructions = f083E_parent_instructions;
      body.emit(f083E);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0867 = bit_and(r082F, body.constant(4294963200u));
      ir_expression *const r0868 = nequal(r0867, body.constant(0u));
      ir_if *f0866 = new(mem_ctx) ir_if(operand(r0868).val);
      exec_list *const f0866_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0866->then_instructions;

         ir_expression *const r0869 = nequal(r0835, body.constant(0u));
         body.emit(assign(r082E, expr(ir_triop_csel, r0869, body.constant(0u), body.constant(4294967295u)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0866->else_instructions;

         ir_variable *const r086A = body.make_temp(glsl_type::uint_type, "z1Ptr");
         ir_expression *const r086B = lshift(r082F, body.constant(int(20)));
         ir_expression *const r086C = rshift(r0830, body.constant(int(12)));
         body.emit(assign(r086A, bit_or(r086B, r086C), 0x01));

         /* IF CONDITION */
         ir_expression *const r086E = nequal(r0835, body.constant(0u));
         ir_expression *const r086F = nequal(r086A, body.constant(0u));
         ir_expression *const r0870 = logic_and(r086E, r086F);
         ir_if *f086D = new(mem_ctx) ir_if(operand(r0870).val);
         exec_list *const f086D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f086D->then_instructions;

            ir_expression *const r0871 = nequal(r0835, body.constant(0u));
            body.emit(assign(r082E, expr(ir_triop_csel, r0871, body.constant(0u), body.constant(4294967295u)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f086D->else_instructions;

            body.emit(assign(r082E, r086A, 0x01));


         body.instructions = f086D_parent_instructions;
         body.emit(f086D);

         /* END IF */


      body.instructions = f0866_parent_instructions;
      body.emit(f0866);

      /* END IF */


   body.instructions = f0836_parent_instructions;
   body.emit(f0836);

   /* END IF */

   body.emit(ret(r082E));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
uint_to_fp64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0872 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0872);
   ir_variable *const r0873 = body.make_temp(glsl_type::uvec2_type, "return_value");
   /* IF CONDITION */
   ir_expression *const r0875 = equal(r0872, body.constant(0u));
   ir_if *f0874 = new(mem_ctx) ir_if(operand(r0875).val);
   exec_list *const f0874_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0874->then_instructions;

      body.emit(assign(r0873, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0874->else_instructions;

      ir_variable *const r0876 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0877 = equal(r0872, body.constant(0u));
      ir_expression *const r0878 = expr(ir_unop_find_msb, r0872);
      ir_expression *const r0879 = sub(body.constant(int(31)), r0878);
      ir_expression *const r087A = expr(ir_triop_csel, r0877, body.constant(int(32)), r0879);
      body.emit(assign(r0876, add(r087A, body.constant(int(21))), 0x01));

      ir_variable *const r087B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r087B);
      ir_expression *const r087C = sub(body.constant(int(1074)), r0876);
      ir_expression *const r087D = expr(ir_unop_i2u, r087C);
      ir_expression *const r087E = lshift(r087D, body.constant(int(20)));
      ir_expression *const r087F = less(r0876, body.constant(int(32)));
      ir_expression *const r0880 = neg(r0876);
      ir_expression *const r0881 = bit_and(r0880, body.constant(int(31)));
      ir_expression *const r0882 = rshift(r0872, r0881);
      ir_expression *const r0883 = equal(r0876, body.constant(int(0)));
      ir_expression *const r0884 = less(r0876, body.constant(int(64)));
      ir_expression *const r0885 = add(r0876, body.constant(int(-32)));
      ir_expression *const r0886 = lshift(r0872, r0885);
      ir_expression *const r0887 = expr(ir_triop_csel, r0884, r0886, body.constant(0u));
      ir_expression *const r0888 = expr(ir_triop_csel, r0883, body.constant(0u), r0887);
      ir_expression *const r0889 = expr(ir_triop_csel, r087F, r0882, r0888);
      body.emit(assign(r087B, add(r087E, r0889), 0x02));

      ir_expression *const r088A = less(r0876, body.constant(int(32)));
      ir_expression *const r088B = lshift(r0872, r0876);
      ir_expression *const r088C = equal(r0876, body.constant(int(0)));
      ir_expression *const r088D = expr(ir_triop_csel, r088C, r0872, body.constant(0u));
      body.emit(assign(r087B, expr(ir_triop_csel, r088A, r088B, r088D), 0x01));

      body.emit(assign(r0873, r087B, 0x03));


   body.instructions = f0874_parent_instructions;
   body.emit(f0874);

   /* END IF */

   body.emit(ret(r0873));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fp64_to_int(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::int_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r088E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r088E);
   ir_variable *const r088F = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r088F, body.constant(true), 0x01));

   ir_variable *const r0890 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0891 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0891);
   ir_variable *const r0892 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0892);
   ir_variable *const r0893 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0893);
   ir_variable *const r0894 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0894, bit_and(swizzle_y(r088E), body.constant(1048575u)), 0x01));

   body.emit(assign(r0893, r0894, 0x01));

   ir_variable *const r0895 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0896 = rshift(swizzle_y(r088E), body.constant(int(20)));
   ir_expression *const r0897 = bit_and(r0896, body.constant(2047u));
   body.emit(assign(r0895, expr(ir_unop_u2i, r0897), 0x01));

   body.emit(assign(r0892, rshift(swizzle_y(r088E), body.constant(int(31))), 0x01));

   body.emit(assign(r0891, body.constant(0u), 0x01));

   ir_variable *const r0898 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0898, add(r0895, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r089A = gequal(r0898, body.constant(int(0)));
   ir_if *f0899 = new(mem_ctx) ir_if(operand(r089A).val);
   exec_list *const f0899_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0899->then_instructions;

      /* IF CONDITION */
      ir_expression *const r089C = less(body.constant(int(1054)), r0895);
      ir_if *f089B = new(mem_ctx) ir_if(operand(r089C).val);
      exec_list *const f089B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f089B->then_instructions;

         /* IF CONDITION */
         ir_expression *const r089E = equal(r0895, body.constant(int(2047)));
         ir_expression *const r089F = bit_or(r0894, swizzle_x(r088E));
         ir_expression *const r08A0 = expr(ir_unop_u2i, r089F);
         ir_expression *const r08A1 = expr(ir_unop_i2b, r08A0);
         ir_expression *const r08A2 = logic_and(r089E, r08A1);
         ir_if *f089D = new(mem_ctx) ir_if(operand(r08A2).val);
         exec_list *const f089D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f089D->then_instructions;

            body.emit(assign(r0892, body.constant(0u), 0x01));


         body.instructions = f089D_parent_instructions;
         body.emit(f089D);

         /* END IF */

         ir_expression *const r08A3 = expr(ir_unop_u2i, r0892);
         ir_expression *const r08A4 = expr(ir_unop_i2b, r08A3);
         body.emit(assign(r0890, expr(ir_triop_csel, r08A4, body.constant(int(-2147483648)), body.constant(int(2147483647))), 0x01));

         body.emit(assign(r088F, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f089B->else_instructions;

         ir_variable *const r08A5 = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r08A5, bit_or(r0894, body.constant(1048576u)), 0x01));

         ir_expression *const r08A6 = equal(r0898, body.constant(int(0)));
         ir_expression *const r08A7 = lshift(r08A5, r0898);
         ir_expression *const r08A8 = neg(r0898);
         ir_expression *const r08A9 = bit_and(r08A8, body.constant(int(31)));
         ir_expression *const r08AA = rshift(swizzle_x(r088E), r08A9);
         ir_expression *const r08AB = bit_or(r08A7, r08AA);
         body.emit(assign(r0891, expr(ir_triop_csel, r08A6, r08A5, r08AB), 0x01));


      body.instructions = f089B_parent_instructions;
      body.emit(f089B);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0899->else_instructions;

      /* IF CONDITION */
      ir_expression *const r08AD = less(r0895, body.constant(int(1023)));
      ir_if *f08AC = new(mem_ctx) ir_if(operand(r08AD).val);
      exec_list *const f08AC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08AC->then_instructions;

         body.emit(assign(r0890, body.constant(int(0)), 0x01));

         body.emit(assign(r088F, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08AC->else_instructions;

         body.emit(assign(r0893, bit_or(r0894, body.constant(1048576u)), 0x01));

         ir_expression *const r08AE = neg(r0898);
         body.emit(assign(r0891, rshift(r0893, r08AE), 0x01));


      body.instructions = f08AC_parent_instructions;
      body.emit(f08AC);

      /* END IF */


   body.instructions = f0899_parent_instructions;
   body.emit(f0899);

   /* END IF */

   /* IF CONDITION */
   ir_if *f08AF = new(mem_ctx) ir_if(operand(r088F).val);
   exec_list *const f08AF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08AF->then_instructions;

      ir_variable *const r08B0 = body.make_temp(glsl_type::int_type, "mix_retval");
      ir_expression *const r08B1 = nequal(r0892, body.constant(0u));
      ir_expression *const r08B2 = expr(ir_unop_u2i, r0891);
      ir_expression *const r08B3 = neg(r08B2);
      ir_expression *const r08B4 = expr(ir_unop_u2i, r0891);
      body.emit(assign(r08B0, expr(ir_triop_csel, r08B1, r08B3, r08B4), 0x01));

      ir_expression *const r08B5 = less(r08B0, body.constant(int(0)));
      ir_expression *const r08B6 = expr(ir_unop_b2i, r08B5);
      ir_expression *const r08B7 = expr(ir_unop_i2u, r08B6);
      ir_expression *const r08B8 = bit_xor(r0892, r08B7);
      ir_expression *const r08B9 = expr(ir_unop_u2i, r08B8);
      ir_expression *const r08BA = expr(ir_unop_i2b, r08B9);
      ir_expression *const r08BB = expr(ir_unop_i2b, r08B0);
      ir_expression *const r08BC = logic_and(r08BA, r08BB);
      ir_expression *const r08BD = expr(ir_unop_u2i, r0892);
      ir_expression *const r08BE = expr(ir_unop_i2b, r08BD);
      ir_expression *const r08BF = expr(ir_triop_csel, r08BE, body.constant(int(-2147483648)), body.constant(int(2147483647)));
      body.emit(assign(r0890, expr(ir_triop_csel, r08BC, r08BF, r08B0), 0x01));

      body.emit(assign(r088F, body.constant(false), 0x01));


   body.instructions = f08AF_parent_instructions;
   body.emit(f08AF);

   /* END IF */

   body.emit(ret(r0890));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
int_to_fp64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r08C0 = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r08C0);
   ir_variable *const r08C1 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r08C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r08C2);
   ir_variable *const r08C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r08C3);
   ir_variable *const r08C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r08C4);
   body.emit(assign(r08C4, body.constant(0u), 0x01));

   body.emit(assign(r08C3, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r08C6 = equal(r08C0, body.constant(int(0)));
   ir_if *f08C5 = new(mem_ctx) ir_if(operand(r08C6).val);
   exec_list *const f08C5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08C5->then_instructions;

      ir_variable *const r08C7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r08C7);
      body.emit(assign(r08C7, body.constant(0u), 0x02));

      body.emit(assign(r08C7, body.constant(0u), 0x01));

      body.emit(assign(r08C1, r08C7, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f08C5->else_instructions;

      ir_expression *const r08C8 = less(r08C0, body.constant(int(0)));
      ir_expression *const r08C9 = expr(ir_unop_b2i, r08C8);
      body.emit(assign(r08C2, expr(ir_unop_i2u, r08C9), 0x01));

      ir_variable *const r08CA = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r08CB = less(r08C0, body.constant(int(0)));
      ir_expression *const r08CC = neg(r08C0);
      ir_expression *const r08CD = expr(ir_unop_i2u, r08CC);
      ir_expression *const r08CE = expr(ir_unop_i2u, r08C0);
      body.emit(assign(r08CA, expr(ir_triop_csel, r08CB, r08CD, r08CE), 0x01));

      ir_variable *const r08CF = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r08D0 = equal(r08CA, body.constant(0u));
      ir_expression *const r08D1 = expr(ir_unop_find_msb, r08CA);
      ir_expression *const r08D2 = sub(body.constant(int(31)), r08D1);
      ir_expression *const r08D3 = expr(ir_triop_csel, r08D0, body.constant(int(32)), r08D2);
      body.emit(assign(r08CF, add(r08D3, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r08D5 = gequal(r08CF, body.constant(int(0)));
      ir_if *f08D4 = new(mem_ctx) ir_if(operand(r08D5).val);
      exec_list *const f08D4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08D4->then_instructions;

         body.emit(assign(r08C4, lshift(r08CA, r08CF), 0x01));

         body.emit(assign(r08C3, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08D4->else_instructions;

         ir_variable *const r08D6 = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r08D6, neg(r08CF), 0x01));

         ir_expression *const r08D7 = equal(r08D6, body.constant(int(0)));
         ir_expression *const r08D8 = less(r08D6, body.constant(int(32)));
         ir_expression *const r08D9 = rshift(r08CA, r08D6);
         ir_expression *const r08DA = expr(ir_triop_csel, r08D8, r08D9, body.constant(0u));
         body.emit(assign(r08C4, expr(ir_triop_csel, r08D7, r08CA, r08DA), 0x01));

         ir_expression *const r08DB = equal(r08D6, body.constant(int(0)));
         ir_expression *const r08DC = less(r08D6, body.constant(int(32)));
         ir_expression *const r08DD = neg(r08D6);
         ir_expression *const r08DE = bit_and(r08DD, body.constant(int(31)));
         ir_expression *const r08DF = lshift(r08CA, r08DE);
         ir_expression *const r08E0 = bit_or(r08DF, body.constant(0u));
         ir_expression *const r08E1 = less(r08D6, body.constant(int(64)));
         ir_expression *const r08E2 = bit_and(r08D6, body.constant(int(31)));
         ir_expression *const r08E3 = rshift(r08CA, r08E2);
         ir_expression *const r08E4 = expr(ir_triop_csel, r08E1, r08E3, body.constant(0u));
         ir_expression *const r08E5 = expr(ir_triop_csel, r08DC, r08E0, r08E4);
         body.emit(assign(r08C3, expr(ir_triop_csel, r08DB, r08CA, r08E5), 0x01));


      body.instructions = f08D4_parent_instructions;
      body.emit(f08D4);

      /* END IF */

      ir_variable *const r08E6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r08E6);
      ir_expression *const r08E7 = lshift(r08C2, body.constant(int(31)));
      ir_expression *const r08E8 = sub(body.constant(int(1042)), r08CF);
      ir_expression *const r08E9 = expr(ir_unop_i2u, r08E8);
      ir_expression *const r08EA = lshift(r08E9, body.constant(int(20)));
      ir_expression *const r08EB = add(r08E7, r08EA);
      body.emit(assign(r08E6, add(r08EB, r08C4), 0x02));

      body.emit(assign(r08E6, r08C3, 0x01));

      body.emit(assign(r08C1, r08E6, 0x03));


   body.instructions = f08C5_parent_instructions;
   body.emit(f08C5);

   /* END IF */

   body.emit(ret(r08C1));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
packFloat32(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::float_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r08EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r08EC);
   ir_variable *const r08ED = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r08ED);
   ir_variable *const r08EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r08EE);
   ir_variable *const r08EF = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r08F0 = lshift(r08EC, body.constant(int(31)));
   ir_expression *const r08F1 = expr(ir_unop_i2u, r08ED);
   ir_expression *const r08F2 = lshift(r08F1, body.constant(int(23)));
   ir_expression *const r08F3 = add(r08F0, r08F2);
   ir_expression *const r08F4 = add(r08F3, r08EE);
   body.emit(assign(r08EF, expr(ir_unop_bitcast_u2f, r08F4), 0x01));

   body.emit(ret(r08EF));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
roundAndPackFloat32(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::float_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r08F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r08F5);
   ir_variable *const r08F6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r08F6);
   ir_variable *const r08F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r08F7);
   ir_variable *const r08F8 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r08F8, body.constant(true), 0x01));

   ir_variable *const r08F9 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r08FA = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r08FA);
   ir_expression *const r08FB = bit_and(r08F7, body.constant(127u));
   body.emit(assign(r08FA, expr(ir_unop_u2i, r08FB), 0x01));

   /* IF CONDITION */
   ir_expression *const r08FD = expr(ir_unop_i2u, r08F6);
   ir_expression *const r08FE = gequal(r08FD, body.constant(253u));
   ir_if *f08FC = new(mem_ctx) ir_if(operand(r08FE).val);
   exec_list *const f08FC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08FC->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0900 = less(body.constant(int(253)), r08F6);
      ir_expression *const r0901 = equal(r08F6, body.constant(int(253)));
      ir_expression *const r0902 = expr(ir_unop_u2i, r08F7);
      ir_expression *const r0903 = less(r0902, body.constant(int(-64)));
      ir_expression *const r0904 = logic_and(r0901, r0903);
      ir_expression *const r0905 = logic_or(r0900, r0904);
      ir_if *f08FF = new(mem_ctx) ir_if(operand(r0905).val);
      exec_list *const f08FF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08FF->then_instructions;

         ir_expression *const r0906 = lshift(r08F5, body.constant(int(31)));
         ir_expression *const r0907 = add(r0906, body.constant(2139095040u));
         body.emit(assign(r08F9, expr(ir_unop_bitcast_u2f, r0907), 0x01));

         body.emit(assign(r08F8, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08FF->else_instructions;

         ir_variable *const r0908 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0908, neg(r08F6), 0x01));

         ir_variable *const r0909 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
         body.emit(assign(r0909, less(r08F6, body.constant(int(0))), 0x01));

         ir_variable *const r090A = body.make_temp(glsl_type::uint_type, "mix_retval");
         ir_expression *const r090B = neg(r08F6);
         ir_expression *const r090C = less(r090B, body.constant(int(32)));
         ir_expression *const r090D = rshift(r08F7, r0908);
         ir_expression *const r090E = neg(r0908);
         ir_expression *const r090F = bit_and(r090E, body.constant(int(31)));
         ir_expression *const r0910 = lshift(r08F7, r090F);
         ir_expression *const r0911 = nequal(r0910, body.constant(0u));
         ir_expression *const r0912 = expr(ir_unop_b2i, r0911);
         ir_expression *const r0913 = expr(ir_unop_i2u, r0912);
         ir_expression *const r0914 = bit_or(r090D, r0913);
         ir_expression *const r0915 = nequal(r08F7, body.constant(0u));
         ir_expression *const r0916 = expr(ir_unop_b2i, r0915);
         ir_expression *const r0917 = expr(ir_unop_i2u, r0916);
         ir_expression *const r0918 = expr(ir_triop_csel, r090C, r0914, r0917);
         body.emit(assign(r090A, expr(ir_triop_csel, r0909, r0918, r08F7), 0x01));

         body.emit(assign(r08F7, r090A, 0x01));

         ir_expression *const r0919 = expr(ir_unop_u2i, r090A);
         ir_expression *const r091A = bit_and(r0919, body.constant(int(127)));
         body.emit(assign(r08FA, expr(ir_triop_csel, r0909, r091A, r08FA), 0x01));

         body.emit(assign(r08F6, expr(ir_triop_csel, r0909, body.constant(int(0)), r08F6), 0x01));


      body.instructions = f08FF_parent_instructions;
      body.emit(f08FF);

      /* END IF */


   body.instructions = f08FC_parent_instructions;
   body.emit(f08FC);

   /* END IF */

   /* IF CONDITION */
   ir_if *f091B = new(mem_ctx) ir_if(operand(r08F8).val);
   exec_list *const f091B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f091B->then_instructions;

      ir_expression *const r091C = add(r08F7, body.constant(64u));
      body.emit(assign(r08F7, rshift(r091C, body.constant(int(7))), 0x01));

      ir_expression *const r091D = bit_xor(r08FA, body.constant(int(64)));
      ir_expression *const r091E = equal(r091D, body.constant(int(0)));
      ir_expression *const r091F = expr(ir_unop_b2i, r091E);
      ir_expression *const r0920 = expr(ir_unop_i2u, r091F);
      ir_expression *const r0921 = expr(ir_unop_bit_not, r0920);
      body.emit(assign(r08F7, bit_and(r08F7, r0921), 0x01));

      ir_expression *const r0922 = lshift(r08F5, body.constant(int(31)));
      ir_expression *const r0923 = equal(r08F7, body.constant(0u));
      ir_expression *const r0924 = expr(ir_triop_csel, r0923, body.constant(int(0)), r08F6);
      ir_expression *const r0925 = expr(ir_unop_i2u, r0924);
      ir_expression *const r0926 = lshift(r0925, body.constant(int(23)));
      ir_expression *const r0927 = add(r0922, r0926);
      ir_expression *const r0928 = add(r0927, r08F7);
      body.emit(assign(r08F9, expr(ir_unop_bitcast_u2f, r0928), 0x01));

      body.emit(assign(r08F8, body.constant(false), 0x01));


   body.instructions = f091B_parent_instructions;
   body.emit(f091B);

   /* END IF */

   body.emit(ret(r08F9));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fp64_to_fp32(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::float_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0929 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0929);
   ir_variable *const r092A = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r092B = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r092B, swizzle_x(r0929), 0x01));

   ir_variable *const r092C = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r092C, bit_and(swizzle_y(r0929), body.constant(1048575u)), 0x01));

   ir_variable *const r092D = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r092E = rshift(swizzle_y(r0929), body.constant(int(20)));
   ir_expression *const r092F = bit_and(r092E, body.constant(2047u));
   body.emit(assign(r092D, expr(ir_unop_u2i, r092F), 0x01));

   ir_variable *const r0930 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0930, rshift(swizzle_y(r0929), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0932 = equal(r092D, body.constant(int(2047)));
   ir_if *f0931 = new(mem_ctx) ir_if(operand(r0932).val);
   exec_list *const f0931_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0931->then_instructions;

      ir_variable *const r0933 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0933);
      ir_variable *const r0934 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0934, lshift(swizzle_x(r0929), body.constant(int(12))), 0x01));

      ir_expression *const r0935 = lshift(swizzle_y(r0929), body.constant(int(12)));
      ir_expression *const r0936 = rshift(swizzle_x(r0929), body.constant(int(20)));
      body.emit(assign(r0929, bit_or(r0935, r0936), 0x02));

      body.emit(assign(r0929, r0934, 0x01));

      ir_expression *const r0937 = lshift(r0930, body.constant(int(31)));
      ir_expression *const r0938 = bit_or(r0937, body.constant(2143289344u));
      ir_expression *const r0939 = rshift(swizzle_y(r0929), body.constant(int(9)));
      ir_expression *const r093A = bit_or(r0938, r0939);
      body.emit(assign(r0933, expr(ir_unop_bitcast_u2f, r093A), 0x01));

      ir_variable *const r093B = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r093C = bit_or(r092C, r092B);
      ir_expression *const r093D = nequal(r093C, body.constant(0u));
      ir_expression *const r093E = lshift(r0930, body.constant(int(31)));
      ir_expression *const r093F = add(r093E, body.constant(2139095040u));
      ir_expression *const r0940 = expr(ir_unop_bitcast_u2f, r093F);
      body.emit(assign(r093B, expr(ir_triop_csel, r093D, r0933, r0940), 0x01));

      body.emit(assign(r0933, r093B, 0x01));

      body.emit(assign(r092A, r093B, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0931->else_instructions;

      ir_variable *const r0941 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0942 = lshift(r092C, body.constant(int(10)));
      ir_expression *const r0943 = rshift(r092B, body.constant(int(22)));
      ir_expression *const r0944 = bit_or(r0942, r0943);
      ir_expression *const r0945 = lshift(r092B, body.constant(int(10)));
      ir_expression *const r0946 = nequal(r0945, body.constant(0u));
      ir_expression *const r0947 = expr(ir_unop_b2i, r0946);
      ir_expression *const r0948 = expr(ir_unop_i2u, r0947);
      body.emit(assign(r0941, bit_or(r0944, r0948), 0x01));

      ir_variable *const r0949 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r094A = nequal(r092D, body.constant(int(0)));
      ir_expression *const r094B = bit_or(r0941, body.constant(1073741824u));
      body.emit(assign(r0949, expr(ir_triop_csel, r094A, r094B, r0941), 0x01));

      ir_variable *const r094C = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r094C, add(r092D, body.constant(int(-897))), 0x01));

      ir_variable *const r094D = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r094D, r0949, 0x01));

      ir_variable *const r094E = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r094E, body.constant(true), 0x01));

      ir_variable *const r094F = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0950 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0950);
      ir_expression *const r0951 = bit_and(r0949, body.constant(127u));
      body.emit(assign(r0950, expr(ir_unop_u2i, r0951), 0x01));

      /* IF CONDITION */
      ir_expression *const r0953 = expr(ir_unop_i2u, r094C);
      ir_expression *const r0954 = gequal(r0953, body.constant(253u));
      ir_if *f0952 = new(mem_ctx) ir_if(operand(r0954).val);
      exec_list *const f0952_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0952->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0956 = less(body.constant(int(253)), r094C);
         ir_expression *const r0957 = equal(r094C, body.constant(int(253)));
         ir_expression *const r0958 = expr(ir_unop_u2i, r0949);
         ir_expression *const r0959 = less(r0958, body.constant(int(-64)));
         ir_expression *const r095A = logic_and(r0957, r0959);
         ir_expression *const r095B = logic_or(r0956, r095A);
         ir_if *f0955 = new(mem_ctx) ir_if(operand(r095B).val);
         exec_list *const f0955_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0955->then_instructions;

            ir_expression *const r095C = lshift(r0930, body.constant(int(31)));
            ir_expression *const r095D = add(r095C, body.constant(2139095040u));
            body.emit(assign(r094F, expr(ir_unop_bitcast_u2f, r095D), 0x01));

            body.emit(assign(r094E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0955->else_instructions;

            ir_variable *const r095E = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r095E, neg(r094C), 0x01));

            ir_variable *const r095F = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r095F, less(r094C, body.constant(int(0))), 0x01));

            ir_variable *const r0960 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0961 = neg(r094C);
            ir_expression *const r0962 = less(r0961, body.constant(int(32)));
            ir_expression *const r0963 = rshift(r0949, r095E);
            ir_expression *const r0964 = neg(r095E);
            ir_expression *const r0965 = bit_and(r0964, body.constant(int(31)));
            ir_expression *const r0966 = lshift(r0949, r0965);
            ir_expression *const r0967 = nequal(r0966, body.constant(0u));
            ir_expression *const r0968 = expr(ir_unop_b2i, r0967);
            ir_expression *const r0969 = expr(ir_unop_i2u, r0968);
            ir_expression *const r096A = bit_or(r0963, r0969);
            ir_expression *const r096B = nequal(r0949, body.constant(0u));
            ir_expression *const r096C = expr(ir_unop_b2i, r096B);
            ir_expression *const r096D = expr(ir_unop_i2u, r096C);
            ir_expression *const r096E = expr(ir_triop_csel, r0962, r096A, r096D);
            body.emit(assign(r0960, expr(ir_triop_csel, r095F, r096E, r0949), 0x01));

            body.emit(assign(r094D, r0960, 0x01));

            ir_expression *const r096F = expr(ir_unop_u2i, r0960);
            ir_expression *const r0970 = bit_and(r096F, body.constant(int(127)));
            body.emit(assign(r0950, expr(ir_triop_csel, r095F, r0970, r0950), 0x01));

            body.emit(assign(r094C, expr(ir_triop_csel, r095F, body.constant(int(0)), r094C), 0x01));


         body.instructions = f0955_parent_instructions;
         body.emit(f0955);

         /* END IF */


      body.instructions = f0952_parent_instructions;
      body.emit(f0952);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0971 = new(mem_ctx) ir_if(operand(r094E).val);
      exec_list *const f0971_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0971->then_instructions;

         ir_expression *const r0972 = add(r094D, body.constant(64u));
         body.emit(assign(r094D, rshift(r0972, body.constant(int(7))), 0x01));

         ir_expression *const r0973 = bit_xor(r0950, body.constant(int(64)));
         ir_expression *const r0974 = equal(r0973, body.constant(int(0)));
         ir_expression *const r0975 = expr(ir_unop_b2i, r0974);
         ir_expression *const r0976 = expr(ir_unop_i2u, r0975);
         ir_expression *const r0977 = expr(ir_unop_bit_not, r0976);
         body.emit(assign(r094D, bit_and(r094D, r0977), 0x01));

         ir_expression *const r0978 = lshift(r0930, body.constant(int(31)));
         ir_expression *const r0979 = equal(r094D, body.constant(0u));
         ir_expression *const r097A = expr(ir_triop_csel, r0979, body.constant(int(0)), r094C);
         ir_expression *const r097B = expr(ir_unop_i2u, r097A);
         ir_expression *const r097C = lshift(r097B, body.constant(int(23)));
         ir_expression *const r097D = add(r0978, r097C);
         ir_expression *const r097E = add(r097D, r094D);
         body.emit(assign(r094F, expr(ir_unop_bitcast_u2f, r097E), 0x01));

         body.emit(assign(r094E, body.constant(false), 0x01));


      body.instructions = f0971_parent_instructions;
      body.emit(f0971);

      /* END IF */

      body.emit(assign(r092A, r094F, 0x01));


   body.instructions = f0931_parent_instructions;
   body.emit(f0931);

   /* END IF */

   body.emit(ret(r092A));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fp32_to_fp64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r097F = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r097F);
   ir_variable *const r0980 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0980, body.constant(true), 0x01));

   ir_variable *const r0981 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0982 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0982);
   ir_variable *const r0983 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0983);
   ir_variable *const r0984 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0984);
   ir_variable *const r0985 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0985, expr(ir_unop_bitcast_f2u, r097F), 0x01));

   ir_variable *const r0986 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0986, bit_and(r0985, body.constant(8388607u)), 0x01));

   body.emit(assign(r0984, r0986, 0x01));

   ir_variable *const r0987 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0988 = rshift(r0985, body.constant(int(23)));
   ir_expression *const r0989 = bit_and(r0988, body.constant(255u));
   body.emit(assign(r0987, expr(ir_unop_u2i, r0989), 0x01));

   body.emit(assign(r0983, r0987, 0x01));

   body.emit(assign(r0982, rshift(r0985, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r098B = equal(r0987, body.constant(int(255)));
   ir_if *f098A = new(mem_ctx) ir_if(operand(r098B).val);
   exec_list *const f098A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f098A->then_instructions;

      /* IF CONDITION */
      ir_expression *const r098D = nequal(r0986, body.constant(0u));
      ir_if *f098C = new(mem_ctx) ir_if(operand(r098D).val);
      exec_list *const f098C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f098C->then_instructions;

         ir_variable *const r098E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r098E, lshift(r0985, body.constant(int(9))), 0x01));

         ir_variable *const r098F = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0990 = lshift(r098E, body.constant(int(20)));
         body.emit(assign(r098F, bit_or(r0990, body.constant(0u)), 0x01));

         ir_expression *const r0991 = rshift(r098E, body.constant(int(12)));
         ir_expression *const r0992 = lshift(r0982, body.constant(int(31)));
         ir_expression *const r0993 = bit_or(r0992, body.constant(2146959360u));
         body.emit(assign(r098F, bit_or(r0991, r0993), 0x02));

         body.emit(assign(r0981, r098F, 0x03));

         body.emit(assign(r0980, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f098C->else_instructions;

         ir_variable *const r0994 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0994);
         ir_expression *const r0995 = lshift(r0982, body.constant(int(31)));
         body.emit(assign(r0994, add(r0995, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0994, body.constant(0u), 0x01));

         body.emit(assign(r0981, r0994, 0x03));

         body.emit(assign(r0980, body.constant(false), 0x01));


      body.instructions = f098C_parent_instructions;
      body.emit(f098C);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f098A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0997 = equal(r0987, body.constant(int(0)));
      ir_if *f0996 = new(mem_ctx) ir_if(operand(r0997).val);
      exec_list *const f0996_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0996->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0999 = equal(r0986, body.constant(0u));
         ir_if *f0998 = new(mem_ctx) ir_if(operand(r0999).val);
         exec_list *const f0998_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0998->then_instructions;

            ir_variable *const r099A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r099A);
            body.emit(assign(r099A, lshift(r0982, body.constant(int(31))), 0x02));

            body.emit(assign(r099A, body.constant(0u), 0x01));

            body.emit(assign(r0981, r099A, 0x03));

            body.emit(assign(r0980, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0998->else_instructions;

            ir_variable *const r099B = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r099C = equal(r0986, body.constant(0u));
            ir_expression *const r099D = expr(ir_unop_find_msb, r0986);
            ir_expression *const r099E = sub(body.constant(int(31)), r099D);
            ir_expression *const r099F = expr(ir_triop_csel, r099C, body.constant(int(32)), r099E);
            body.emit(assign(r099B, add(r099F, body.constant(int(-8))), 0x01));

            body.emit(assign(r0984, lshift(r0986, r099B), 0x01));

            body.emit(assign(r0983, sub(body.constant(int(1)), r099B), 0x01));

            body.emit(assign(r0983, add(r0983, body.constant(int(-1))), 0x01));


         body.instructions = f0998_parent_instructions;
         body.emit(f0998);

         /* END IF */


      body.instructions = f0996_parent_instructions;
      body.emit(f0996);

      /* END IF */

      /* IF CONDITION */
      ir_if *f09A0 = new(mem_ctx) ir_if(operand(r0980).val);
      exec_list *const f09A0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09A0->then_instructions;

         ir_variable *const r09A1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r09A1);
         ir_expression *const r09A2 = lshift(r0982, body.constant(int(31)));
         ir_expression *const r09A3 = add(r0983, body.constant(int(896)));
         ir_expression *const r09A4 = expr(ir_unop_i2u, r09A3);
         ir_expression *const r09A5 = lshift(r09A4, body.constant(int(20)));
         ir_expression *const r09A6 = add(r09A2, r09A5);
         ir_expression *const r09A7 = rshift(r0984, body.constant(int(3)));
         body.emit(assign(r09A1, add(r09A6, r09A7), 0x02));

         ir_expression *const r09A8 = lshift(r0984, body.constant(int(29)));
         body.emit(assign(r09A1, bit_or(r09A8, body.constant(0u)), 0x01));

         body.emit(assign(r0981, r09A1, 0x03));

         body.emit(assign(r0980, body.constant(false), 0x01));


      body.instructions = f09A0_parent_instructions;
      body.emit(f09A0);

      /* END IF */


   body.instructions = f098A_parent_instructions;
   body.emit(f098A);

   /* END IF */

   body.emit(ret(r0981));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
add96(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r09A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09A9);
   ir_variable *const r09AA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09AA);
   ir_variable *const r09AB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r09AB);
   ir_variable *const r09AC = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r09AC);
   ir_variable *const r09AD = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r09AD);
   ir_variable *const r09AE = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r09AE);
   ir_variable *const r09AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09AF);
   ir_variable *const r09B0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09B0);
   ir_variable *const r09B1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09B1);
   ir_variable *const r09B2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r09B2);
   ir_variable *const r09B3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r09B3);
   ir_variable *const r09B4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r09B4, add(r09AB, r09AE), 0x01));

   ir_variable *const r09B5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r09B6 = less(r09B4, r09AB);
   ir_expression *const r09B7 = expr(ir_unop_b2i, r09B6);
   body.emit(assign(r09B5, expr(ir_unop_i2u, r09B7), 0x01));

   ir_variable *const r09B8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r09B8, add(r09AA, r09AD), 0x01));

   body.emit(assign(r09B3, add(r09B8, r09B5), 0x01));

   ir_expression *const r09B9 = add(r09A9, r09AC);
   ir_expression *const r09BA = less(r09B3, r09B5);
   ir_expression *const r09BB = expr(ir_unop_b2i, r09BA);
   ir_expression *const r09BC = expr(ir_unop_i2u, r09BB);
   body.emit(assign(r09B2, add(r09B9, r09BC), 0x01));

   ir_expression *const r09BD = less(r09B8, r09AA);
   ir_expression *const r09BE = expr(ir_unop_b2i, r09BD);
   ir_expression *const r09BF = expr(ir_unop_i2u, r09BE);
   body.emit(assign(r09B2, add(r09B2, r09BF), 0x01));

   body.emit(assign(r09B1, r09B4, 0x01));

   body.emit(assign(r09B0, r09B3, 0x01));

   body.emit(assign(r09AF, r09B2, 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
sub96(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r09C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09C0);
   ir_variable *const r09C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09C1);
   ir_variable *const r09C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r09C2);
   ir_variable *const r09C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r09C3);
   ir_variable *const r09C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r09C4);
   ir_variable *const r09C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r09C5);
   ir_variable *const r09C6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09C6);
   ir_variable *const r09C7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09C7);
   ir_variable *const r09C8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09C8);
   ir_variable *const r09C9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r09C9);
   ir_variable *const r09CA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r09CB = less(r09C2, r09C5);
   ir_expression *const r09CC = expr(ir_unop_b2i, r09CB);
   body.emit(assign(r09CA, expr(ir_unop_i2u, r09CC), 0x01));

   ir_variable *const r09CD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r09CD, sub(r09C1, r09C4), 0x01));

   ir_expression *const r09CE = sub(r09C0, r09C3);
   ir_expression *const r09CF = less(r09CD, r09CA);
   ir_expression *const r09D0 = expr(ir_unop_b2i, r09CF);
   ir_expression *const r09D1 = expr(ir_unop_i2u, r09D0);
   body.emit(assign(r09C9, sub(r09CE, r09D1), 0x01));

   ir_expression *const r09D2 = less(r09C1, r09C4);
   ir_expression *const r09D3 = expr(ir_unop_b2i, r09D2);
   ir_expression *const r09D4 = expr(ir_unop_i2u, r09D3);
   body.emit(assign(r09C9, sub(r09C9, r09D4), 0x01));

   body.emit(assign(r09C8, sub(r09C2, r09C5), 0x01));

   body.emit(assign(r09C7, sub(r09CD, r09CA), 0x01));

   body.emit(assign(r09C6, r09C9, 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
estimateDiv64To32(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uint_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r09D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09D5);
   ir_variable *const r09D6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09D6);
   ir_variable *const r09D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r09D7);
   ir_variable *const r09D8 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r09D9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r09D9);
   ir_variable *const r09DA = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r09DA);
   ir_variable *const r09DB = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r09DB);
   ir_variable *const r09DC = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r09DC);
   body.emit(assign(r09DB, body.constant(0u), 0x01));

   body.emit(assign(r09DA, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r09DE = gequal(r09D5, r09D7);
   ir_if *f09DD = new(mem_ctx) ir_if(operand(r09DE).val);
   exec_list *const f09DD_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09DD->then_instructions;

      body.emit(assign(r09D8, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09DD->else_instructions;

      body.emit(assign(r09DC, rshift(r09D7, body.constant(int(16))), 0x01));

      ir_variable *const r09DF = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09E1 = lshift(r09DC, body.constant(int(16)));
      ir_expression *const r09E2 = gequal(r09D5, r09E1);
      ir_if *f09E0 = new(mem_ctx) ir_if(operand(r09E2).val);
      exec_list *const f09E0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09E0->then_instructions;

         body.emit(assign(r09DF, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09E0->else_instructions;

         ir_expression *const r09E3 = expr(ir_binop_div, r09D5, r09DC);
         body.emit(assign(r09DF, lshift(r09E3, body.constant(int(16))), 0x01));


      body.instructions = f09E0_parent_instructions;
      body.emit(f09E0);

      /* END IF */

      body.emit(assign(r09D9, r09DF, 0x01));

      ir_variable *const r09E4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r09E4);
      ir_variable *const r09E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r09E5);
      ir_variable *const r09E6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r09E6);
      ir_variable *const r09E7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09E7, bit_and(r09D7, body.constant(65535u)), 0x01));

      ir_variable *const r09E8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09E8, rshift(r09D7, body.constant(int(16))), 0x01));

      ir_variable *const r09E9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09E9, bit_and(r09DF, body.constant(65535u)), 0x01));

      ir_variable *const r09EA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09EA, rshift(r09DF, body.constant(int(16))), 0x01));

      ir_variable *const r09EB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09EB, mul(r09E8, r09E9), 0x01));

      ir_expression *const r09EC = mul(r09E7, r09EA);
      body.emit(assign(r09E5, add(r09EC, r09EB), 0x01));

      ir_expression *const r09ED = mul(r09E8, r09EA);
      ir_expression *const r09EE = less(r09E5, r09EB);
      ir_expression *const r09EF = expr(ir_unop_b2i, r09EE);
      ir_expression *const r09F0 = expr(ir_unop_i2u, r09EF);
      ir_expression *const r09F1 = lshift(r09F0, body.constant(int(16)));
      ir_expression *const r09F2 = rshift(r09E5, body.constant(int(16)));
      ir_expression *const r09F3 = add(r09F1, r09F2);
      body.emit(assign(r09E4, add(r09ED, r09F3), 0x01));

      body.emit(assign(r09E5, lshift(r09E5, body.constant(int(16))), 0x01));

      ir_expression *const r09F4 = mul(r09E7, r09E9);
      body.emit(assign(r09E6, add(r09F4, r09E5), 0x01));

      ir_expression *const r09F5 = less(r09E6, r09E5);
      ir_expression *const r09F6 = expr(ir_unop_b2i, r09F5);
      ir_expression *const r09F7 = expr(ir_unop_i2u, r09F6);
      body.emit(assign(r09E4, add(r09E4, r09F7), 0x01));

      ir_expression *const r09F8 = sub(r09D5, r09E4);
      ir_expression *const r09F9 = less(r09D6, r09E6);
      ir_expression *const r09FA = expr(ir_unop_b2i, r09F9);
      ir_expression *const r09FB = expr(ir_unop_i2u, r09FA);
      body.emit(assign(r09DB, sub(r09F8, r09FB), 0x01));

      body.emit(assign(r09DA, sub(r09D6, r09E6), 0x01));

      /* LOOP BEGIN */
      ir_loop *f09FC = new(mem_ctx) ir_loop();
      exec_list *const f09FC_parent_instructions = body.instructions;

         body.instructions = &f09FC->body_instructions;

         /* IF CONDITION */
         ir_expression *const r09FE = expr(ir_unop_u2i, r09DB);
         ir_expression *const r09FF = gequal(r09FE, body.constant(int(0)));
         ir_if *f09FD = new(mem_ctx) ir_if(operand(r09FF).val);
         exec_list *const f09FD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09FD->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f09FD_parent_instructions;
         body.emit(f09FD);

         /* END IF */

         body.emit(assign(r09D9, add(r09D9, body.constant(4294901760u)), 0x01));

         ir_variable *const r0A00 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0A01 = lshift(r09D7, body.constant(int(16)));
         body.emit(assign(r0A00, add(r09DA, r0A01), 0x01));

         ir_expression *const r0A02 = add(r09DB, r09DC);
         ir_expression *const r0A03 = less(r0A00, r09DA);
         ir_expression *const r0A04 = expr(ir_unop_b2i, r0A03);
         ir_expression *const r0A05 = expr(ir_unop_i2u, r0A04);
         body.emit(assign(r09DB, add(r0A02, r0A05), 0x01));

         body.emit(assign(r09DA, r0A00, 0x01));

      /* LOOP END */

      body.instructions = f09FC_parent_instructions;
      body.emit(f09FC);

      ir_expression *const r0A06 = lshift(r09DB, body.constant(int(16)));
      ir_expression *const r0A07 = rshift(r09DA, body.constant(int(16)));
      body.emit(assign(r09DB, bit_or(r0A06, r0A07), 0x01));

      ir_variable *const r0A08 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A0A = lshift(r09DC, body.constant(int(16)));
      ir_expression *const r0A0B = gequal(r09DB, r0A0A);
      ir_if *f0A09 = new(mem_ctx) ir_if(operand(r0A0B).val);
      exec_list *const f0A09_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A09->then_instructions;

         body.emit(assign(r0A08, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A09->else_instructions;

         body.emit(assign(r0A08, expr(ir_binop_div, r09DB, r09DC), 0x01));


      body.instructions = f0A09_parent_instructions;
      body.emit(f0A09);

      /* END IF */

      body.emit(assign(r09D9, bit_or(r09D9, r0A08), 0x01));

      body.emit(assign(r09D8, r09D9, 0x01));


   body.instructions = f09DD_parent_instructions;
   body.emit(f09DD);

   /* END IF */

   body.emit(ret(r09D8));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fsqrt64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0A0C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A0C);
   ir_variable *const r0A0D = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0A0D, r0A0C, 0x03));

   ir_variable *const r0A0E = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A0F = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A0F, bit_and(swizzle_y(r0A0C), body.constant(1048575u)), 0x01));

   ir_variable *const r0A10 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A11 = rshift(swizzle_y(r0A0C), body.constant(int(20)));
   ir_expression *const r0A12 = bit_and(r0A11, body.constant(2047u));
   body.emit(assign(r0A10, expr(ir_unop_u2i, r0A12), 0x01));

   ir_variable *const r0A13 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A13, rshift(swizzle_y(r0A0C), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A15 = equal(r0A10, body.constant(int(2047)));
   ir_if *f0A14 = new(mem_ctx) ir_if(operand(r0A15).val);
   exec_list *const f0A14_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A14->then_instructions;

      ir_variable *const r0A16 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0A16);
      ir_expression *const r0A17 = lshift(swizzle_y(r0A0C), body.constant(int(12)));
      ir_expression *const r0A18 = rshift(swizzle_x(r0A0C), body.constant(int(20)));
      body.emit(assign(r0A0D, bit_or(r0A17, r0A18), 0x02));

      body.emit(assign(r0A0D, lshift(swizzle_x(r0A0C), body.constant(int(12))), 0x01));

      ir_expression *const r0A19 = lshift(r0A13, body.constant(int(31)));
      ir_expression *const r0A1A = bit_or(r0A19, body.constant(2143289344u));
      ir_expression *const r0A1B = rshift(swizzle_y(r0A0D), body.constant(int(9)));
      ir_expression *const r0A1C = bit_or(r0A1A, r0A1B);
      body.emit(assign(r0A16, expr(ir_unop_bitcast_u2f, r0A1C), 0x01));

      ir_variable *const r0A1D = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0A1E = bit_or(r0A0F, swizzle_x(r0A0C));
      ir_expression *const r0A1F = nequal(r0A1E, body.constant(0u));
      ir_expression *const r0A20 = lshift(r0A13, body.constant(int(31)));
      ir_expression *const r0A21 = add(r0A20, body.constant(2139095040u));
      ir_expression *const r0A22 = expr(ir_unop_bitcast_u2f, r0A21);
      body.emit(assign(r0A1D, expr(ir_triop_csel, r0A1F, r0A16, r0A22), 0x01));

      body.emit(assign(r0A16, r0A1D, 0x01));

      body.emit(assign(r0A0E, r0A1D, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A14->else_instructions;

      ir_variable *const r0A23 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A24 = lshift(r0A0F, body.constant(int(10)));
      ir_expression *const r0A25 = rshift(swizzle_x(r0A0C), body.constant(int(22)));
      ir_expression *const r0A26 = bit_or(r0A24, r0A25);
      ir_expression *const r0A27 = lshift(swizzle_x(r0A0C), body.constant(int(10)));
      ir_expression *const r0A28 = nequal(r0A27, body.constant(0u));
      ir_expression *const r0A29 = expr(ir_unop_b2i, r0A28);
      ir_expression *const r0A2A = expr(ir_unop_i2u, r0A29);
      body.emit(assign(r0A23, bit_or(r0A26, r0A2A), 0x01));

      ir_variable *const r0A2B = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A2C = nequal(r0A10, body.constant(int(0)));
      ir_expression *const r0A2D = bit_or(r0A23, body.constant(1073741824u));
      body.emit(assign(r0A2B, expr(ir_triop_csel, r0A2C, r0A2D, r0A23), 0x01));

      ir_variable *const r0A2E = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0A2E, add(r0A10, body.constant(int(-897))), 0x01));

      ir_variable *const r0A2F = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0A2F, r0A2B, 0x01));

      ir_variable *const r0A30 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0A30, body.constant(true), 0x01));

      ir_variable *const r0A31 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0A32 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0A32);
      ir_expression *const r0A33 = bit_and(r0A2B, body.constant(127u));
      body.emit(assign(r0A32, expr(ir_unop_u2i, r0A33), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A35 = expr(ir_unop_i2u, r0A2E);
      ir_expression *const r0A36 = gequal(r0A35, body.constant(253u));
      ir_if *f0A34 = new(mem_ctx) ir_if(operand(r0A36).val);
      exec_list *const f0A34_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A34->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A38 = less(body.constant(int(253)), r0A2E);
         ir_expression *const r0A39 = equal(r0A2E, body.constant(int(253)));
         ir_expression *const r0A3A = expr(ir_unop_u2i, r0A2B);
         ir_expression *const r0A3B = less(r0A3A, body.constant(int(-64)));
         ir_expression *const r0A3C = logic_and(r0A39, r0A3B);
         ir_expression *const r0A3D = logic_or(r0A38, r0A3C);
         ir_if *f0A37 = new(mem_ctx) ir_if(operand(r0A3D).val);
         exec_list *const f0A37_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A37->then_instructions;

            ir_expression *const r0A3E = lshift(r0A13, body.constant(int(31)));
            ir_expression *const r0A3F = add(r0A3E, body.constant(2139095040u));
            body.emit(assign(r0A31, expr(ir_unop_bitcast_u2f, r0A3F), 0x01));

            body.emit(assign(r0A30, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A37->else_instructions;

            ir_variable *const r0A40 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0A40, neg(r0A2E), 0x01));

            ir_variable *const r0A41 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0A41, less(r0A2E, body.constant(int(0))), 0x01));

            ir_variable *const r0A42 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0A43 = neg(r0A2E);
            ir_expression *const r0A44 = less(r0A43, body.constant(int(32)));
            ir_expression *const r0A45 = rshift(r0A2B, r0A40);
            ir_expression *const r0A46 = neg(r0A40);
            ir_expression *const r0A47 = bit_and(r0A46, body.constant(int(31)));
            ir_expression *const r0A48 = lshift(r0A2B, r0A47);
            ir_expression *const r0A49 = nequal(r0A48, body.constant(0u));
            ir_expression *const r0A4A = expr(ir_unop_b2i, r0A49);
            ir_expression *const r0A4B = expr(ir_unop_i2u, r0A4A);
            ir_expression *const r0A4C = bit_or(r0A45, r0A4B);
            ir_expression *const r0A4D = nequal(r0A2B, body.constant(0u));
            ir_expression *const r0A4E = expr(ir_unop_b2i, r0A4D);
            ir_expression *const r0A4F = expr(ir_unop_i2u, r0A4E);
            ir_expression *const r0A50 = expr(ir_triop_csel, r0A44, r0A4C, r0A4F);
            body.emit(assign(r0A42, expr(ir_triop_csel, r0A41, r0A50, r0A2B), 0x01));

            body.emit(assign(r0A2F, r0A42, 0x01));

            ir_expression *const r0A51 = expr(ir_unop_u2i, r0A42);
            ir_expression *const r0A52 = bit_and(r0A51, body.constant(int(127)));
            body.emit(assign(r0A32, expr(ir_triop_csel, r0A41, r0A52, r0A32), 0x01));

            body.emit(assign(r0A2E, expr(ir_triop_csel, r0A41, body.constant(int(0)), r0A2E), 0x01));


         body.instructions = f0A37_parent_instructions;
         body.emit(f0A37);

         /* END IF */


      body.instructions = f0A34_parent_instructions;
      body.emit(f0A34);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A53 = new(mem_ctx) ir_if(operand(r0A30).val);
      exec_list *const f0A53_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A53->then_instructions;

         ir_expression *const r0A54 = add(r0A2F, body.constant(64u));
         body.emit(assign(r0A2F, rshift(r0A54, body.constant(int(7))), 0x01));

         ir_expression *const r0A55 = bit_xor(r0A32, body.constant(int(64)));
         ir_expression *const r0A56 = equal(r0A55, body.constant(int(0)));
         ir_expression *const r0A57 = expr(ir_unop_b2i, r0A56);
         ir_expression *const r0A58 = expr(ir_unop_i2u, r0A57);
         ir_expression *const r0A59 = expr(ir_unop_bit_not, r0A58);
         body.emit(assign(r0A2F, bit_and(r0A2F, r0A59), 0x01));

         ir_expression *const r0A5A = lshift(r0A13, body.constant(int(31)));
         ir_expression *const r0A5B = equal(r0A2F, body.constant(0u));
         ir_expression *const r0A5C = expr(ir_triop_csel, r0A5B, body.constant(int(0)), r0A2E);
         ir_expression *const r0A5D = expr(ir_unop_i2u, r0A5C);
         ir_expression *const r0A5E = lshift(r0A5D, body.constant(int(23)));
         ir_expression *const r0A5F = add(r0A5A, r0A5E);
         ir_expression *const r0A60 = add(r0A5F, r0A2F);
         body.emit(assign(r0A31, expr(ir_unop_bitcast_u2f, r0A60), 0x01));

         body.emit(assign(r0A30, body.constant(false), 0x01));


      body.instructions = f0A53_parent_instructions;
      body.emit(f0A53);

      /* END IF */

      body.emit(assign(r0A0E, r0A31, 0x01));


   body.instructions = f0A14_parent_instructions;
   body.emit(f0A14);

   /* END IF */

   ir_variable *const r0A61 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A61, body.constant(true), 0x01));

   ir_variable *const r0A62 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A63 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A63);
   ir_variable *const r0A64 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0A64);
   ir_variable *const r0A65 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0A65);
   ir_variable *const r0A66 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0A67 = expr(ir_unop_sqrt, r0A0E);
   body.emit(assign(r0A66, expr(ir_unop_bitcast_f2u, r0A67), 0x01));

   ir_variable *const r0A68 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0A68, bit_and(r0A66, body.constant(8388607u)), 0x01));

   body.emit(assign(r0A65, r0A68, 0x01));

   ir_variable *const r0A69 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A6A = rshift(r0A66, body.constant(int(23)));
   ir_expression *const r0A6B = bit_and(r0A6A, body.constant(255u));
   body.emit(assign(r0A69, expr(ir_unop_u2i, r0A6B), 0x01));

   body.emit(assign(r0A64, r0A69, 0x01));

   body.emit(assign(r0A63, rshift(r0A66, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A6D = equal(r0A69, body.constant(int(255)));
   ir_if *f0A6C = new(mem_ctx) ir_if(operand(r0A6D).val);
   exec_list *const f0A6C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A6C->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A6F = nequal(r0A68, body.constant(0u));
      ir_if *f0A6E = new(mem_ctx) ir_if(operand(r0A6F).val);
      exec_list *const f0A6E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A6E->then_instructions;

         ir_variable *const r0A70 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0A70, lshift(r0A66, body.constant(int(9))), 0x01));

         ir_variable *const r0A71 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0A72 = lshift(r0A70, body.constant(int(20)));
         body.emit(assign(r0A71, bit_or(r0A72, body.constant(0u)), 0x01));

         ir_expression *const r0A73 = rshift(r0A70, body.constant(int(12)));
         ir_expression *const r0A74 = lshift(r0A63, body.constant(int(31)));
         ir_expression *const r0A75 = bit_or(r0A74, body.constant(2146959360u));
         body.emit(assign(r0A71, bit_or(r0A73, r0A75), 0x02));

         body.emit(assign(r0A62, r0A71, 0x03));

         body.emit(assign(r0A61, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A6E->else_instructions;

         ir_variable *const r0A76 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0A76);
         ir_expression *const r0A77 = lshift(r0A63, body.constant(int(31)));
         body.emit(assign(r0A76, add(r0A77, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0A76, body.constant(0u), 0x01));

         body.emit(assign(r0A62, r0A76, 0x03));

         body.emit(assign(r0A61, body.constant(false), 0x01));


      body.instructions = f0A6E_parent_instructions;
      body.emit(f0A6E);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A6C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A79 = equal(r0A69, body.constant(int(0)));
      ir_if *f0A78 = new(mem_ctx) ir_if(operand(r0A79).val);
      exec_list *const f0A78_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A78->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A7B = equal(r0A68, body.constant(0u));
         ir_if *f0A7A = new(mem_ctx) ir_if(operand(r0A7B).val);
         exec_list *const f0A7A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A7A->then_instructions;

            ir_variable *const r0A7C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0A7C);
            body.emit(assign(r0A7C, lshift(r0A63, body.constant(int(31))), 0x02));

            body.emit(assign(r0A7C, body.constant(0u), 0x01));

            body.emit(assign(r0A62, r0A7C, 0x03));

            body.emit(assign(r0A61, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A7A->else_instructions;

            ir_variable *const r0A7D = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0A7E = equal(r0A68, body.constant(0u));
            ir_expression *const r0A7F = expr(ir_unop_find_msb, r0A68);
            ir_expression *const r0A80 = sub(body.constant(int(31)), r0A7F);
            ir_expression *const r0A81 = expr(ir_triop_csel, r0A7E, body.constant(int(32)), r0A80);
            body.emit(assign(r0A7D, add(r0A81, body.constant(int(-8))), 0x01));

            body.emit(assign(r0A65, lshift(r0A68, r0A7D), 0x01));

            body.emit(assign(r0A64, sub(body.constant(int(1)), r0A7D), 0x01));

            body.emit(assign(r0A64, add(r0A64, body.constant(int(-1))), 0x01));


         body.instructions = f0A7A_parent_instructions;
         body.emit(f0A7A);

         /* END IF */


      body.instructions = f0A78_parent_instructions;
      body.emit(f0A78);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A82 = new(mem_ctx) ir_if(operand(r0A61).val);
      exec_list *const f0A82_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A82->then_instructions;

         ir_variable *const r0A83 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0A83);
         ir_expression *const r0A84 = lshift(r0A63, body.constant(int(31)));
         ir_expression *const r0A85 = add(r0A64, body.constant(int(896)));
         ir_expression *const r0A86 = expr(ir_unop_i2u, r0A85);
         ir_expression *const r0A87 = lshift(r0A86, body.constant(int(20)));
         ir_expression *const r0A88 = add(r0A84, r0A87);
         ir_expression *const r0A89 = rshift(r0A65, body.constant(int(3)));
         body.emit(assign(r0A83, add(r0A88, r0A89), 0x02));

         ir_expression *const r0A8A = lshift(r0A65, body.constant(int(29)));
         body.emit(assign(r0A83, bit_or(r0A8A, body.constant(0u)), 0x01));

         body.emit(assign(r0A62, r0A83, 0x03));

         body.emit(assign(r0A61, body.constant(false), 0x01));


      body.instructions = f0A82_parent_instructions;
      body.emit(f0A82);

      /* END IF */


   body.instructions = f0A6C_parent_instructions;
   body.emit(f0A6C);

   /* END IF */

   body.emit(ret(r0A62));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
ftrunc64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0A8B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A8B);
   ir_variable *const r0A8C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zHi", ir_var_auto);
   body.emit(r0A8C);
   ir_variable *const r0A8D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zLo", ir_var_auto);
   body.emit(r0A8D);
   ir_variable *const r0A8E = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A8F = rshift(swizzle_y(r0A8B), body.constant(int(20)));
   ir_expression *const r0A90 = bit_and(r0A8F, body.constant(2047u));
   ir_expression *const r0A91 = expr(ir_unop_u2i, r0A90);
   body.emit(assign(r0A8E, add(r0A91, body.constant(int(-1023))), 0x01));

   ir_variable *const r0A92 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0A92, sub(body.constant(int(52)), r0A8E), 0x01));

   ir_variable *const r0A93 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
   /* IF CONDITION */
   ir_expression *const r0A95 = gequal(r0A92, body.constant(int(32)));
   ir_if *f0A94 = new(mem_ctx) ir_if(operand(r0A95).val);
   exec_list *const f0A94_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A94->then_instructions;

      body.emit(assign(r0A93, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A94->else_instructions;

      body.emit(assign(r0A93, lshift(body.constant(4294967295u), r0A92), 0x01));


   body.instructions = f0A94_parent_instructions;
   body.emit(f0A94);

   /* END IF */

   ir_variable *const r0A96 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
   /* IF CONDITION */
   ir_expression *const r0A98 = less(r0A92, body.constant(int(33)));
   ir_if *f0A97 = new(mem_ctx) ir_if(operand(r0A98).val);
   exec_list *const f0A97_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A97->then_instructions;

      body.emit(assign(r0A96, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A97->else_instructions;

      ir_expression *const r0A99 = add(r0A92, body.constant(int(-32)));
      body.emit(assign(r0A96, lshift(body.constant(4294967295u), r0A99), 0x01));


   body.instructions = f0A97_parent_instructions;
   body.emit(f0A97);

   /* END IF */

   body.emit(assign(r0A8D, bit_and(r0A93, swizzle_x(r0A8B)), 0x01));

   body.emit(assign(r0A8C, bit_and(r0A96, swizzle_y(r0A8B)), 0x01));

   ir_variable *const r0A9A = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r0A9B = less(body.constant(int(52)), r0A8E);
   ir_expression *const r0A9C = less(r0A8E, body.constant(int(0)));
   ir_expression *const r0A9D = expr(ir_triop_csel, r0A9C, body.constant(0u), r0A8D);
   body.emit(assign(r0A9A, expr(ir_triop_csel, r0A9B, swizzle_x(r0A8B), r0A9D), 0x01));

   body.emit(assign(r0A8D, r0A9A, 0x01));

   ir_variable *const r0A9E = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r0A9F = less(body.constant(int(52)), r0A8E);
   ir_expression *const r0AA0 = less(r0A8E, body.constant(int(0)));
   ir_expression *const r0AA1 = expr(ir_triop_csel, r0AA0, body.constant(0u), r0A8C);
   body.emit(assign(r0A9E, expr(ir_triop_csel, r0A9F, swizzle_y(r0A8B), r0AA1), 0x01));

   body.emit(assign(r0A8C, r0A9E, 0x01));

   ir_variable *const r0AA2 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r0AA2, r0A9A, 0x01));

   body.emit(assign(r0AA2, r0A9E, 0x02));

   body.emit(ret(r0AA2));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fround64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0AA3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AA3);
   ir_variable *const r0AA4 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0AA4, body.constant(true), 0x01));

   ir_variable *const r0AA5 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0AA6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0AA6);
   ir_variable *const r0AA7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0AA7);
   ir_variable *const r0AA8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0AA9 = rshift(swizzle_y(r0AA3), body.constant(int(20)));
   ir_expression *const r0AAA = bit_and(r0AA9, body.constant(2047u));
   ir_expression *const r0AAB = expr(ir_unop_u2i, r0AAA);
   body.emit(assign(r0AA8, add(r0AAB, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0AA7, swizzle_y(r0AA3), 0x01));

   body.emit(assign(r0AA6, swizzle_x(r0AA3), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AAD = less(r0AA8, body.constant(int(20)));
   ir_if *f0AAC = new(mem_ctx) ir_if(operand(r0AAD).val);
   exec_list *const f0AAC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AAC->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0AAF = less(r0AA8, body.constant(int(0)));
      ir_if *f0AAE = new(mem_ctx) ir_if(operand(r0AAF).val);
      exec_list *const f0AAE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AAE->then_instructions;

         body.emit(assign(r0AA7, bit_and(swizzle_y(r0AA3), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AB1 = equal(r0AA8, body.constant(int(-1)));
         ir_expression *const r0AB2 = nequal(swizzle_x(r0AA3), body.constant(0u));
         ir_expression *const r0AB3 = logic_and(r0AB1, r0AB2);
         ir_if *f0AB0 = new(mem_ctx) ir_if(operand(r0AB3).val);
         exec_list *const f0AB0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AB0->then_instructions;

            body.emit(assign(r0AA7, bit_or(r0AA7, body.constant(1072693248u)), 0x01));


         body.instructions = f0AB0_parent_instructions;
         body.emit(f0AB0);

         /* END IF */

         body.emit(assign(r0AA6, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AAE->else_instructions;

         ir_variable *const r0AB4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0AB4, rshift(body.constant(1048575u), r0AA8), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AB6 = bit_and(r0AA7, r0AB4);
         ir_expression *const r0AB7 = equal(r0AB6, body.constant(0u));
         ir_expression *const r0AB8 = equal(r0AA6, body.constant(0u));
         ir_expression *const r0AB9 = logic_and(r0AB7, r0AB8);
         ir_if *f0AB5 = new(mem_ctx) ir_if(operand(r0AB9).val);
         exec_list *const f0AB5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AB5->then_instructions;

            body.emit(assign(r0AA5, r0AA3, 0x03));

            body.emit(assign(r0AA4, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AB5->else_instructions;

            ir_expression *const r0ABA = rshift(body.constant(524288u), r0AA8);
            body.emit(assign(r0AA7, add(r0AA7, r0ABA), 0x01));

            ir_expression *const r0ABB = expr(ir_unop_bit_not, r0AB4);
            body.emit(assign(r0AA7, bit_and(r0AA7, r0ABB), 0x01));

            body.emit(assign(r0AA6, body.constant(0u), 0x01));


         body.instructions = f0AB5_parent_instructions;
         body.emit(f0AB5);

         /* END IF */


      body.instructions = f0AAE_parent_instructions;
      body.emit(f0AAE);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AAC->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0ABD = less(body.constant(int(51)), r0AA8);
      ir_expression *const r0ABE = equal(r0AA8, body.constant(int(1024)));
      ir_expression *const r0ABF = logic_or(r0ABD, r0ABE);
      ir_if *f0ABC = new(mem_ctx) ir_if(operand(r0ABF).val);
      exec_list *const f0ABC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0ABC->then_instructions;

         body.emit(assign(r0AA5, r0AA3, 0x03));

         body.emit(assign(r0AA4, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0ABC->else_instructions;

         ir_variable *const r0AC0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0AC1 = add(r0AA8, body.constant(int(-20)));
         body.emit(assign(r0AC0, rshift(body.constant(4294967295u), r0AC1), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AC3 = bit_and(r0AA6, r0AC0);
         ir_expression *const r0AC4 = equal(r0AC3, body.constant(0u));
         ir_if *f0AC2 = new(mem_ctx) ir_if(operand(r0AC4).val);
         exec_list *const f0AC2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AC2->then_instructions;

            body.emit(assign(r0AA5, r0AA3, 0x03));

            body.emit(assign(r0AA4, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AC2->else_instructions;

            ir_variable *const r0AC5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0AC6 = sub(body.constant(int(51)), r0AA8);
            ir_expression *const r0AC7 = lshift(body.constant(1u), r0AC6);
            body.emit(assign(r0AC5, add(r0AA6, r0AC7), 0x01));

            /* IF CONDITION */
            ir_expression *const r0AC9 = less(r0AC5, r0AA6);
            ir_if *f0AC8 = new(mem_ctx) ir_if(operand(r0AC9).val);
            exec_list *const f0AC8_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AC8->then_instructions;

               body.emit(assign(r0AA7, add(r0AA7, body.constant(1u)), 0x01));


            body.instructions = f0AC8_parent_instructions;
            body.emit(f0AC8);

            /* END IF */

            ir_expression *const r0ACA = expr(ir_unop_bit_not, r0AC0);
            body.emit(assign(r0AA6, bit_and(r0AC5, r0ACA), 0x01));


         body.instructions = f0AC2_parent_instructions;
         body.emit(f0AC2);

         /* END IF */


      body.instructions = f0ABC_parent_instructions;
      body.emit(f0ABC);

      /* END IF */


   body.instructions = f0AAC_parent_instructions;
   body.emit(f0AAC);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0ACB = new(mem_ctx) ir_if(operand(r0AA4).val);
   exec_list *const f0ACB_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0ACB->then_instructions;

      body.emit(assign(r0AA3, r0AA6, 0x01));

      body.emit(assign(r0AA3, r0AA7, 0x02));

      body.emit(assign(r0AA5, r0AA3, 0x03));

      body.emit(assign(r0AA4, body.constant(false), 0x01));


   body.instructions = f0ACB_parent_instructions;
   body.emit(f0ACB);

   /* END IF */

   body.emit(ret(r0AA5));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
frcp64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0ACC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0ACC);
   ir_variable *const r0ACD = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0ACD, r0ACC, 0x03));

   ir_variable *const r0ACE = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0ACF = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0ACF, bit_and(swizzle_y(r0ACC), body.constant(1048575u)), 0x01));

   ir_variable *const r0AD0 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0AD1 = rshift(swizzle_y(r0ACC), body.constant(int(20)));
   ir_expression *const r0AD2 = bit_and(r0AD1, body.constant(2047u));
   body.emit(assign(r0AD0, expr(ir_unop_u2i, r0AD2), 0x01));

   ir_variable *const r0AD3 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0AD3, rshift(swizzle_y(r0ACC), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AD5 = equal(r0AD0, body.constant(int(2047)));
   ir_if *f0AD4 = new(mem_ctx) ir_if(operand(r0AD5).val);
   exec_list *const f0AD4_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AD4->then_instructions;

      ir_variable *const r0AD6 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0AD6);
      ir_expression *const r0AD7 = lshift(swizzle_y(r0ACC), body.constant(int(12)));
      ir_expression *const r0AD8 = rshift(swizzle_x(r0ACC), body.constant(int(20)));
      body.emit(assign(r0ACD, bit_or(r0AD7, r0AD8), 0x02));

      body.emit(assign(r0ACD, lshift(swizzle_x(r0ACC), body.constant(int(12))), 0x01));

      ir_expression *const r0AD9 = lshift(r0AD3, body.constant(int(31)));
      ir_expression *const r0ADA = bit_or(r0AD9, body.constant(2143289344u));
      ir_expression *const r0ADB = rshift(swizzle_y(r0ACD), body.constant(int(9)));
      ir_expression *const r0ADC = bit_or(r0ADA, r0ADB);
      body.emit(assign(r0AD6, expr(ir_unop_bitcast_u2f, r0ADC), 0x01));

      ir_variable *const r0ADD = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0ADE = bit_or(r0ACF, swizzle_x(r0ACC));
      ir_expression *const r0ADF = nequal(r0ADE, body.constant(0u));
      ir_expression *const r0AE0 = lshift(r0AD3, body.constant(int(31)));
      ir_expression *const r0AE1 = add(r0AE0, body.constant(2139095040u));
      ir_expression *const r0AE2 = expr(ir_unop_bitcast_u2f, r0AE1);
      body.emit(assign(r0ADD, expr(ir_triop_csel, r0ADF, r0AD6, r0AE2), 0x01));

      body.emit(assign(r0AD6, r0ADD, 0x01));

      body.emit(assign(r0ACE, r0ADD, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AD4->else_instructions;

      ir_variable *const r0AE3 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0AE4 = lshift(r0ACF, body.constant(int(10)));
      ir_expression *const r0AE5 = rshift(swizzle_x(r0ACC), body.constant(int(22)));
      ir_expression *const r0AE6 = bit_or(r0AE4, r0AE5);
      ir_expression *const r0AE7 = lshift(swizzle_x(r0ACC), body.constant(int(10)));
      ir_expression *const r0AE8 = nequal(r0AE7, body.constant(0u));
      ir_expression *const r0AE9 = expr(ir_unop_b2i, r0AE8);
      ir_expression *const r0AEA = expr(ir_unop_i2u, r0AE9);
      body.emit(assign(r0AE3, bit_or(r0AE6, r0AEA), 0x01));

      ir_variable *const r0AEB = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0AEC = nequal(r0AD0, body.constant(int(0)));
      ir_expression *const r0AED = bit_or(r0AE3, body.constant(1073741824u));
      body.emit(assign(r0AEB, expr(ir_triop_csel, r0AEC, r0AED, r0AE3), 0x01));

      ir_variable *const r0AEE = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0AEE, add(r0AD0, body.constant(int(-897))), 0x01));

      ir_variable *const r0AEF = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0AEF, r0AEB, 0x01));

      ir_variable *const r0AF0 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0AF0, body.constant(true), 0x01));

      ir_variable *const r0AF1 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0AF2 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0AF2);
      ir_expression *const r0AF3 = bit_and(r0AEB, body.constant(127u));
      body.emit(assign(r0AF2, expr(ir_unop_u2i, r0AF3), 0x01));

      /* IF CONDITION */
      ir_expression *const r0AF5 = expr(ir_unop_i2u, r0AEE);
      ir_expression *const r0AF6 = gequal(r0AF5, body.constant(253u));
      ir_if *f0AF4 = new(mem_ctx) ir_if(operand(r0AF6).val);
      exec_list *const f0AF4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AF4->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0AF8 = less(body.constant(int(253)), r0AEE);
         ir_expression *const r0AF9 = equal(r0AEE, body.constant(int(253)));
         ir_expression *const r0AFA = expr(ir_unop_u2i, r0AEB);
         ir_expression *const r0AFB = less(r0AFA, body.constant(int(-64)));
         ir_expression *const r0AFC = logic_and(r0AF9, r0AFB);
         ir_expression *const r0AFD = logic_or(r0AF8, r0AFC);
         ir_if *f0AF7 = new(mem_ctx) ir_if(operand(r0AFD).val);
         exec_list *const f0AF7_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AF7->then_instructions;

            ir_expression *const r0AFE = lshift(r0AD3, body.constant(int(31)));
            ir_expression *const r0AFF = add(r0AFE, body.constant(2139095040u));
            body.emit(assign(r0AF1, expr(ir_unop_bitcast_u2f, r0AFF), 0x01));

            body.emit(assign(r0AF0, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AF7->else_instructions;

            ir_variable *const r0B00 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B00, neg(r0AEE), 0x01));

            ir_variable *const r0B01 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0B01, less(r0AEE, body.constant(int(0))), 0x01));

            ir_variable *const r0B02 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0B03 = neg(r0AEE);
            ir_expression *const r0B04 = less(r0B03, body.constant(int(32)));
            ir_expression *const r0B05 = rshift(r0AEB, r0B00);
            ir_expression *const r0B06 = neg(r0B00);
            ir_expression *const r0B07 = bit_and(r0B06, body.constant(int(31)));
            ir_expression *const r0B08 = lshift(r0AEB, r0B07);
            ir_expression *const r0B09 = nequal(r0B08, body.constant(0u));
            ir_expression *const r0B0A = expr(ir_unop_b2i, r0B09);
            ir_expression *const r0B0B = expr(ir_unop_i2u, r0B0A);
            ir_expression *const r0B0C = bit_or(r0B05, r0B0B);
            ir_expression *const r0B0D = nequal(r0AEB, body.constant(0u));
            ir_expression *const r0B0E = expr(ir_unop_b2i, r0B0D);
            ir_expression *const r0B0F = expr(ir_unop_i2u, r0B0E);
            ir_expression *const r0B10 = expr(ir_triop_csel, r0B04, r0B0C, r0B0F);
            body.emit(assign(r0B02, expr(ir_triop_csel, r0B01, r0B10, r0AEB), 0x01));

            body.emit(assign(r0AEF, r0B02, 0x01));

            ir_expression *const r0B11 = expr(ir_unop_u2i, r0B02);
            ir_expression *const r0B12 = bit_and(r0B11, body.constant(int(127)));
            body.emit(assign(r0AF2, expr(ir_triop_csel, r0B01, r0B12, r0AF2), 0x01));

            body.emit(assign(r0AEE, expr(ir_triop_csel, r0B01, body.constant(int(0)), r0AEE), 0x01));


         body.instructions = f0AF7_parent_instructions;
         body.emit(f0AF7);

         /* END IF */


      body.instructions = f0AF4_parent_instructions;
      body.emit(f0AF4);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B13 = new(mem_ctx) ir_if(operand(r0AF0).val);
      exec_list *const f0B13_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B13->then_instructions;

         ir_expression *const r0B14 = add(r0AEF, body.constant(64u));
         body.emit(assign(r0AEF, rshift(r0B14, body.constant(int(7))), 0x01));

         ir_expression *const r0B15 = bit_xor(r0AF2, body.constant(int(64)));
         ir_expression *const r0B16 = equal(r0B15, body.constant(int(0)));
         ir_expression *const r0B17 = expr(ir_unop_b2i, r0B16);
         ir_expression *const r0B18 = expr(ir_unop_i2u, r0B17);
         ir_expression *const r0B19 = expr(ir_unop_bit_not, r0B18);
         body.emit(assign(r0AEF, bit_and(r0AEF, r0B19), 0x01));

         ir_expression *const r0B1A = lshift(r0AD3, body.constant(int(31)));
         ir_expression *const r0B1B = equal(r0AEF, body.constant(0u));
         ir_expression *const r0B1C = expr(ir_triop_csel, r0B1B, body.constant(int(0)), r0AEE);
         ir_expression *const r0B1D = expr(ir_unop_i2u, r0B1C);
         ir_expression *const r0B1E = lshift(r0B1D, body.constant(int(23)));
         ir_expression *const r0B1F = add(r0B1A, r0B1E);
         ir_expression *const r0B20 = add(r0B1F, r0AEF);
         body.emit(assign(r0AF1, expr(ir_unop_bitcast_u2f, r0B20), 0x01));

         body.emit(assign(r0AF0, body.constant(false), 0x01));


      body.instructions = f0B13_parent_instructions;
      body.emit(f0B13);

      /* END IF */

      body.emit(assign(r0ACE, r0AF1, 0x01));


   body.instructions = f0AD4_parent_instructions;
   body.emit(f0AD4);

   /* END IF */

   ir_variable *const r0B21 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B21, body.constant(true), 0x01));

   ir_variable *const r0B22 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B23 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B23);
   ir_variable *const r0B24 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B24);
   ir_variable *const r0B25 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B25);
   ir_variable *const r0B26 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0B27 = expr(ir_unop_rcp, r0ACE);
   body.emit(assign(r0B26, expr(ir_unop_bitcast_f2u, r0B27), 0x01));

   ir_variable *const r0B28 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B28, bit_and(r0B26, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B25, r0B28, 0x01));

   ir_variable *const r0B29 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B2A = rshift(r0B26, body.constant(int(23)));
   ir_expression *const r0B2B = bit_and(r0B2A, body.constant(255u));
   body.emit(assign(r0B29, expr(ir_unop_u2i, r0B2B), 0x01));

   body.emit(assign(r0B24, r0B29, 0x01));

   body.emit(assign(r0B23, rshift(r0B26, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B2D = equal(r0B29, body.constant(int(255)));
   ir_if *f0B2C = new(mem_ctx) ir_if(operand(r0B2D).val);
   exec_list *const f0B2C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B2C->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B2F = nequal(r0B28, body.constant(0u));
      ir_if *f0B2E = new(mem_ctx) ir_if(operand(r0B2F).val);
      exec_list *const f0B2E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B2E->then_instructions;

         ir_variable *const r0B30 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B30, lshift(r0B26, body.constant(int(9))), 0x01));

         ir_variable *const r0B31 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B32 = lshift(r0B30, body.constant(int(20)));
         body.emit(assign(r0B31, bit_or(r0B32, body.constant(0u)), 0x01));

         ir_expression *const r0B33 = rshift(r0B30, body.constant(int(12)));
         ir_expression *const r0B34 = lshift(r0B23, body.constant(int(31)));
         ir_expression *const r0B35 = bit_or(r0B34, body.constant(2146959360u));
         body.emit(assign(r0B31, bit_or(r0B33, r0B35), 0x02));

         body.emit(assign(r0B22, r0B31, 0x03));

         body.emit(assign(r0B21, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B2E->else_instructions;

         ir_variable *const r0B36 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B36);
         ir_expression *const r0B37 = lshift(r0B23, body.constant(int(31)));
         body.emit(assign(r0B36, add(r0B37, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B36, body.constant(0u), 0x01));

         body.emit(assign(r0B22, r0B36, 0x03));

         body.emit(assign(r0B21, body.constant(false), 0x01));


      body.instructions = f0B2E_parent_instructions;
      body.emit(f0B2E);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B2C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B39 = equal(r0B29, body.constant(int(0)));
      ir_if *f0B38 = new(mem_ctx) ir_if(operand(r0B39).val);
      exec_list *const f0B38_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B38->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B3B = equal(r0B28, body.constant(0u));
         ir_if *f0B3A = new(mem_ctx) ir_if(operand(r0B3B).val);
         exec_list *const f0B3A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B3A->then_instructions;

            ir_variable *const r0B3C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B3C);
            body.emit(assign(r0B3C, lshift(r0B23, body.constant(int(31))), 0x02));

            body.emit(assign(r0B3C, body.constant(0u), 0x01));

            body.emit(assign(r0B22, r0B3C, 0x03));

            body.emit(assign(r0B21, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B3A->else_instructions;

            ir_variable *const r0B3D = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0B3E = equal(r0B28, body.constant(0u));
            ir_expression *const r0B3F = expr(ir_unop_find_msb, r0B28);
            ir_expression *const r0B40 = sub(body.constant(int(31)), r0B3F);
            ir_expression *const r0B41 = expr(ir_triop_csel, r0B3E, body.constant(int(32)), r0B40);
            body.emit(assign(r0B3D, add(r0B41, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B25, lshift(r0B28, r0B3D), 0x01));

            body.emit(assign(r0B24, sub(body.constant(int(1)), r0B3D), 0x01));

            body.emit(assign(r0B24, add(r0B24, body.constant(int(-1))), 0x01));


         body.instructions = f0B3A_parent_instructions;
         body.emit(f0B3A);

         /* END IF */


      body.instructions = f0B38_parent_instructions;
      body.emit(f0B38);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B42 = new(mem_ctx) ir_if(operand(r0B21).val);
      exec_list *const f0B42_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B42->then_instructions;

         ir_variable *const r0B43 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B43);
         ir_expression *const r0B44 = lshift(r0B23, body.constant(int(31)));
         ir_expression *const r0B45 = add(r0B24, body.constant(int(896)));
         ir_expression *const r0B46 = expr(ir_unop_i2u, r0B45);
         ir_expression *const r0B47 = lshift(r0B46, body.constant(int(20)));
         ir_expression *const r0B48 = add(r0B44, r0B47);
         ir_expression *const r0B49 = rshift(r0B25, body.constant(int(3)));
         body.emit(assign(r0B43, add(r0B48, r0B49), 0x02));

         ir_expression *const r0B4A = lshift(r0B25, body.constant(int(29)));
         body.emit(assign(r0B43, bit_or(r0B4A, body.constant(0u)), 0x01));

         body.emit(assign(r0B22, r0B43, 0x03));

         body.emit(assign(r0B21, body.constant(false), 0x01));


      body.instructions = f0B42_parent_instructions;
      body.emit(f0B42);

      /* END IF */


   body.instructions = f0B2C_parent_instructions;
   body.emit(f0B2C);

   /* END IF */

   body.emit(ret(r0B22));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
