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

         ir_variable *const r0073 = body.make_temp(glsl_type::bool_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0075 = nequal(r0069, body.constant(0u));
         ir_if *f0074 = new(mem_ctx) ir_if(operand(r0075).val);
         exec_list *const f0074_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0074->then_instructions;

            ir_expression *const r0076 = less(swizzle_y(r0055), swizzle_y(r0054));
            ir_expression *const r0077 = equal(swizzle_y(r0055), swizzle_y(r0054));
            ir_expression *const r0078 = less(swizzle_x(r0055), swizzle_x(r0054));
            ir_expression *const r0079 = logic_and(r0077, r0078);
            body.emit(assign(r0073, logic_or(r0076, r0079), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0074->else_instructions;

            ir_expression *const r007A = less(swizzle_y(r0054), swizzle_y(r0055));
            ir_expression *const r007B = equal(swizzle_y(r0054), swizzle_y(r0055));
            ir_expression *const r007C = less(swizzle_x(r0054), swizzle_x(r0055));
            ir_expression *const r007D = logic_and(r007B, r007C);
            body.emit(assign(r0073, logic_or(r007A, r007D), 0x01));


         body.instructions = f0074_parent_instructions;
         body.emit(f0074);

         /* END IF */

         body.emit(assign(r0056, r0073, 0x01));


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
   /* IF CONDITION */
   ir_expression *const r0688 = equal(r0681, body.constant(0u));
   ir_if *f0687 = new(mem_ctx) ir_if(operand(r0688).val);
   exec_list *const f0687_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0687->then_instructions;

      ir_expression *const r0689 = equal(r0682, body.constant(0u));
      ir_expression *const r068A = expr(ir_unop_find_msb, r0682);
      ir_expression *const r068B = sub(body.constant(int(31)), r068A);
      ir_expression *const r068C = expr(ir_triop_csel, r0689, body.constant(int(32)), r068B);
      body.emit(assign(r0686, add(r068C, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r068E = less(r0686, body.constant(int(0)));
      ir_if *f068D = new(mem_ctx) ir_if(operand(r068E).val);
      exec_list *const f068D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f068D->then_instructions;

         ir_expression *const r068F = neg(r0686);
         body.emit(assign(r0684, rshift(r0682, r068F), 0x01));

         ir_expression *const r0690 = bit_and(r0686, body.constant(int(31)));
         body.emit(assign(r0685, lshift(r0682, r0690), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f068D->else_instructions;

         body.emit(assign(r0684, lshift(r0682, r0686), 0x01));

         body.emit(assign(r0685, body.constant(0u), 0x01));


      body.instructions = f068D_parent_instructions;
      body.emit(f068D);

      /* END IF */

      body.emit(assign(r0683, sub(body.constant(int(-31)), r0686), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0687->else_instructions;

      ir_expression *const r0691 = equal(r0681, body.constant(0u));
      ir_expression *const r0692 = expr(ir_unop_find_msb, r0681);
      ir_expression *const r0693 = sub(body.constant(int(31)), r0692);
      ir_expression *const r0694 = expr(ir_triop_csel, r0691, body.constant(int(32)), r0693);
      body.emit(assign(r0686, add(r0694, body.constant(int(-11))), 0x01));

      ir_expression *const r0695 = equal(r0686, body.constant(int(0)));
      ir_expression *const r0696 = lshift(r0681, r0686);
      ir_expression *const r0697 = neg(r0686);
      ir_expression *const r0698 = bit_and(r0697, body.constant(int(31)));
      ir_expression *const r0699 = rshift(r0682, r0698);
      ir_expression *const r069A = bit_or(r0696, r0699);
      body.emit(assign(r0684, expr(ir_triop_csel, r0695, r0681, r069A), 0x01));

      body.emit(assign(r0685, lshift(r0682, r0686), 0x01));

      body.emit(assign(r0683, sub(body.constant(int(1)), r0686), 0x01));


   body.instructions = f0687_parent_instructions;
   body.emit(f0687);

   /* END IF */

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

   ir_variable *const r069B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r069B);
   ir_variable *const r069C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r069C);
   ir_variable *const r069D = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r069D, body.constant(true), 0x01));

   ir_variable *const r069E = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r069F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r069F);
   ir_variable *const r06A0 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r06A0);
   ir_variable *const r06A1 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r06A1);
   ir_variable *const r06A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r06A2);
   ir_variable *const r06A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r06A3);
   ir_variable *const r06A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r06A4);
   ir_variable *const r06A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r06A5);
   ir_variable *const r06A6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r06A6);
   ir_variable *const r06A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r06A7);
   ir_variable *const r06A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r06A8);
   ir_variable *const r06A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r06A9);
   body.emit(assign(r06A9, body.constant(0u), 0x01));

   body.emit(assign(r06A8, body.constant(0u), 0x01));

   body.emit(assign(r06A7, body.constant(0u), 0x01));

   ir_variable *const r06AA = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r06AA, swizzle_x(r069B), 0x01));

   body.emit(assign(r06A5, r06AA, 0x01));

   ir_variable *const r06AB = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r06AB, bit_and(swizzle_y(r069B), body.constant(1048575u)), 0x01));

   body.emit(assign(r06A4, r06AB, 0x01));

   ir_variable *const r06AC = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r06AC, swizzle_x(r069C), 0x01));

   body.emit(assign(r06A3, r06AC, 0x01));

   ir_variable *const r06AD = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r06AD, bit_and(swizzle_y(r069C), body.constant(1048575u)), 0x01));

   body.emit(assign(r06A2, r06AD, 0x01));

   ir_variable *const r06AE = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r06AF = rshift(swizzle_y(r069B), body.constant(int(20)));
   ir_expression *const r06B0 = bit_and(r06AF, body.constant(2047u));
   body.emit(assign(r06AE, expr(ir_unop_u2i, r06B0), 0x01));

   body.emit(assign(r06A1, r06AE, 0x01));

   ir_variable *const r06B1 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r06B2 = rshift(swizzle_y(r069C), body.constant(int(20)));
   ir_expression *const r06B3 = bit_and(r06B2, body.constant(2047u));
   body.emit(assign(r06B1, expr(ir_unop_u2i, r06B3), 0x01));

   body.emit(assign(r06A0, r06B1, 0x01));

   ir_expression *const r06B4 = rshift(swizzle_y(r069B), body.constant(int(31)));
   ir_expression *const r06B5 = rshift(swizzle_y(r069C), body.constant(int(31)));
   body.emit(assign(r069F, bit_xor(r06B4, r06B5), 0x01));

   /* IF CONDITION */
   ir_expression *const r06B7 = equal(r06AE, body.constant(int(2047)));
   ir_if *f06B6 = new(mem_ctx) ir_if(operand(r06B7).val);
   exec_list *const f06B6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f06B6->then_instructions;

      /* IF CONDITION */
      ir_expression *const r06B9 = bit_or(r06AB, swizzle_x(r069B));
      ir_expression *const r06BA = nequal(r06B9, body.constant(0u));
      ir_expression *const r06BB = equal(r06B1, body.constant(int(2047)));
      ir_expression *const r06BC = bit_or(r06AD, swizzle_x(r069C));
      ir_expression *const r06BD = nequal(r06BC, body.constant(0u));
      ir_expression *const r06BE = logic_and(r06BB, r06BD);
      ir_expression *const r06BF = logic_or(r06BA, r06BE);
      ir_if *f06B8 = new(mem_ctx) ir_if(operand(r06BF).val);
      exec_list *const f06B8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f06B8->then_instructions;

         ir_variable *const r06C0 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r06C0, swizzle_x(r069B), 0x01));

         ir_variable *const r06C1 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r06C1, swizzle_x(r069C), 0x01));

         body.emit(assign(r06C0, bit_or(swizzle_y(r069B), body.constant(524288u)), 0x02));

         body.emit(assign(r06C1, bit_or(swizzle_y(r069C), body.constant(524288u)), 0x02));

         ir_expression *const r06C2 = lshift(swizzle_y(r069B), body.constant(int(1)));
         ir_expression *const r06C3 = gequal(r06C2, body.constant(4292870144u));
         ir_expression *const r06C4 = nequal(swizzle_x(r069B), body.constant(0u));
         ir_expression *const r06C5 = bit_and(swizzle_y(r069B), body.constant(1048575u));
         ir_expression *const r06C6 = nequal(r06C5, body.constant(0u));
         ir_expression *const r06C7 = logic_or(r06C4, r06C6);
         ir_expression *const r06C8 = logic_and(r06C3, r06C7);
         ir_swizzle *const r06C9 = swizzle(r06C8, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r06CA = lshift(swizzle_y(r069C), body.constant(int(1)));
         ir_expression *const r06CB = gequal(r06CA, body.constant(4292870144u));
         ir_expression *const r06CC = nequal(swizzle_x(r069C), body.constant(0u));
         ir_expression *const r06CD = bit_and(swizzle_y(r069C), body.constant(1048575u));
         ir_expression *const r06CE = nequal(r06CD, body.constant(0u));
         ir_expression *const r06CF = logic_or(r06CC, r06CE);
         ir_expression *const r06D0 = logic_and(r06CB, r06CF);
         ir_swizzle *const r06D1 = swizzle(r06D0, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r06D2 = expr(ir_triop_csel, r06D1, r06C1, r06C0);
         body.emit(assign(r069E, expr(ir_triop_csel, r06C9, r06D2, r06C1), 0x03));

         body.emit(assign(r069D, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f06B8->else_instructions;

         /* IF CONDITION */
         ir_expression *const r06D4 = expr(ir_unop_i2u, r06B1);
         ir_expression *const r06D5 = bit_or(r06D4, r06AD);
         ir_expression *const r06D6 = bit_or(r06D5, swizzle_x(r069C));
         ir_expression *const r06D7 = equal(r06D6, body.constant(0u));
         ir_if *f06D3 = new(mem_ctx) ir_if(operand(r06D7).val);
         exec_list *const f06D3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f06D3->then_instructions;

            ir_constant_data r06D8_data;
            memset(&r06D8_data, 0, sizeof(ir_constant_data));
            r06D8_data.u[0] = 4294967295;
            r06D8_data.u[1] = 4294967295;
            ir_constant *const r06D8 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r06D8_data);
            body.emit(assign(r069E, r06D8, 0x03));

            body.emit(assign(r069D, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f06D3->else_instructions;

            ir_variable *const r06D9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r06D9);
            ir_expression *const r06DA = lshift(r069F, body.constant(int(31)));
            body.emit(assign(r06D9, add(r06DA, body.constant(2146435072u)), 0x02));

            body.emit(assign(r06D9, body.constant(0u), 0x01));

            body.emit(assign(r069E, r06D9, 0x03));

            body.emit(assign(r069D, body.constant(false), 0x01));


         body.instructions = f06D3_parent_instructions;
         body.emit(f06D3);

         /* END IF */


      body.instructions = f06B8_parent_instructions;
      body.emit(f06B8);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f06B6->else_instructions;

      /* IF CONDITION */
      ir_expression *const r06DC = equal(r06B1, body.constant(int(2047)));
      ir_if *f06DB = new(mem_ctx) ir_if(operand(r06DC).val);
      exec_list *const f06DB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f06DB->then_instructions;

         /* IF CONDITION */
         ir_expression *const r06DE = bit_or(r06AD, swizzle_x(r069C));
         ir_expression *const r06DF = nequal(r06DE, body.constant(0u));
         ir_if *f06DD = new(mem_ctx) ir_if(operand(r06DF).val);
         exec_list *const f06DD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f06DD->then_instructions;

            ir_variable *const r06E0 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r06E0, swizzle_x(r069B), 0x01));

            ir_variable *const r06E1 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r06E1, swizzle_x(r069C), 0x01));

            body.emit(assign(r06E0, bit_or(swizzle_y(r069B), body.constant(524288u)), 0x02));

            body.emit(assign(r06E1, bit_or(swizzle_y(r069C), body.constant(524288u)), 0x02));

            ir_expression *const r06E2 = lshift(swizzle_y(r069B), body.constant(int(1)));
            ir_expression *const r06E3 = gequal(r06E2, body.constant(4292870144u));
            ir_expression *const r06E4 = nequal(swizzle_x(r069B), body.constant(0u));
            ir_expression *const r06E5 = bit_and(swizzle_y(r069B), body.constant(1048575u));
            ir_expression *const r06E6 = nequal(r06E5, body.constant(0u));
            ir_expression *const r06E7 = logic_or(r06E4, r06E6);
            ir_expression *const r06E8 = logic_and(r06E3, r06E7);
            ir_swizzle *const r06E9 = swizzle(r06E8, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r06EA = lshift(swizzle_y(r069C), body.constant(int(1)));
            ir_expression *const r06EB = gequal(r06EA, body.constant(4292870144u));
            ir_expression *const r06EC = nequal(swizzle_x(r069C), body.constant(0u));
            ir_expression *const r06ED = bit_and(swizzle_y(r069C), body.constant(1048575u));
            ir_expression *const r06EE = nequal(r06ED, body.constant(0u));
            ir_expression *const r06EF = logic_or(r06EC, r06EE);
            ir_expression *const r06F0 = logic_and(r06EB, r06EF);
            ir_swizzle *const r06F1 = swizzle(r06F0, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r06F2 = expr(ir_triop_csel, r06F1, r06E1, r06E0);
            body.emit(assign(r069E, expr(ir_triop_csel, r06E9, r06F2, r06E1), 0x03));

            body.emit(assign(r069D, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f06DD->else_instructions;

            /* IF CONDITION */
            ir_expression *const r06F4 = expr(ir_unop_i2u, r06AE);
            ir_expression *const r06F5 = bit_or(r06F4, r06AB);
            ir_expression *const r06F6 = bit_or(r06F5, swizzle_x(r069B));
            ir_expression *const r06F7 = equal(r06F6, body.constant(0u));
            ir_if *f06F3 = new(mem_ctx) ir_if(operand(r06F7).val);
            exec_list *const f06F3_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f06F3->then_instructions;

               ir_constant_data r06F8_data;
               memset(&r06F8_data, 0, sizeof(ir_constant_data));
               r06F8_data.u[0] = 4294967295;
               r06F8_data.u[1] = 4294967295;
               ir_constant *const r06F8 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r06F8_data);
               body.emit(assign(r069E, r06F8, 0x03));

               body.emit(assign(r069D, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f06F3->else_instructions;

               ir_variable *const r06F9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r06F9);
               ir_expression *const r06FA = lshift(r069F, body.constant(int(31)));
               body.emit(assign(r06F9, add(r06FA, body.constant(2146435072u)), 0x02));

               body.emit(assign(r06F9, body.constant(0u), 0x01));

               body.emit(assign(r069E, r06F9, 0x03));

               body.emit(assign(r069D, body.constant(false), 0x01));


            body.instructions = f06F3_parent_instructions;
            body.emit(f06F3);

            /* END IF */


         body.instructions = f06DD_parent_instructions;
         body.emit(f06DD);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f06DB->else_instructions;

         /* IF CONDITION */
         ir_expression *const r06FC = equal(r06AE, body.constant(int(0)));
         ir_if *f06FB = new(mem_ctx) ir_if(operand(r06FC).val);
         exec_list *const f06FB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f06FB->then_instructions;

            /* IF CONDITION */
            ir_expression *const r06FE = bit_or(r06AB, swizzle_x(r069B));
            ir_expression *const r06FF = equal(r06FE, body.constant(0u));
            ir_if *f06FD = new(mem_ctx) ir_if(operand(r06FF).val);
            exec_list *const f06FD_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f06FD->then_instructions;

               ir_variable *const r0700 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0700);
               body.emit(assign(r0700, lshift(r069F, body.constant(int(31))), 0x02));

               body.emit(assign(r0700, body.constant(0u), 0x01));

               body.emit(assign(r069E, r0700, 0x03));

               body.emit(assign(r069D, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f06FD->else_instructions;

               ir_variable *const r0701 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r0701, r06AE, 0x01));

               ir_variable *const r0702 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r0702, r06AB, 0x01));

               ir_variable *const r0703 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r0703, r06AA, 0x01));

               ir_variable *const r0704 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0704);
               /* IF CONDITION */
               ir_expression *const r0706 = equal(r06AB, body.constant(0u));
               ir_if *f0705 = new(mem_ctx) ir_if(operand(r0706).val);
               exec_list *const f0705_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0705->then_instructions;

                  ir_expression *const r0707 = equal(swizzle_x(r069B), body.constant(0u));
                  ir_expression *const r0708 = expr(ir_unop_find_msb, swizzle_x(r069B));
                  ir_expression *const r0709 = sub(body.constant(int(31)), r0708);
                  ir_expression *const r070A = expr(ir_triop_csel, r0707, body.constant(int(32)), r0709);
                  body.emit(assign(r0704, add(r070A, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r070C = less(r0704, body.constant(int(0)));
                  ir_if *f070B = new(mem_ctx) ir_if(operand(r070C).val);
                  exec_list *const f070B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f070B->then_instructions;

                     ir_expression *const r070D = neg(r0704);
                     body.emit(assign(r0702, rshift(swizzle_x(r069B), r070D), 0x01));

                     ir_expression *const r070E = bit_and(r0704, body.constant(int(31)));
                     body.emit(assign(r0703, lshift(swizzle_x(r069B), r070E), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f070B->else_instructions;

                     body.emit(assign(r0702, lshift(swizzle_x(r069B), r0704), 0x01));

                     body.emit(assign(r0703, body.constant(0u), 0x01));


                  body.instructions = f070B_parent_instructions;
                  body.emit(f070B);

                  /* END IF */

                  body.emit(assign(r0701, sub(body.constant(int(-31)), r0704), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0705->else_instructions;

                  ir_expression *const r070F = equal(r06AB, body.constant(0u));
                  ir_expression *const r0710 = expr(ir_unop_find_msb, r06AB);
                  ir_expression *const r0711 = sub(body.constant(int(31)), r0710);
                  ir_expression *const r0712 = expr(ir_triop_csel, r070F, body.constant(int(32)), r0711);
                  body.emit(assign(r0704, add(r0712, body.constant(int(-11))), 0x01));

                  ir_expression *const r0713 = equal(r0704, body.constant(int(0)));
                  ir_expression *const r0714 = lshift(r06AB, r0704);
                  ir_expression *const r0715 = neg(r0704);
                  ir_expression *const r0716 = bit_and(r0715, body.constant(int(31)));
                  ir_expression *const r0717 = rshift(swizzle_x(r069B), r0716);
                  ir_expression *const r0718 = bit_or(r0714, r0717);
                  body.emit(assign(r0702, expr(ir_triop_csel, r0713, r06AB, r0718), 0x01));

                  body.emit(assign(r0703, lshift(swizzle_x(r069B), r0704), 0x01));

                  body.emit(assign(r0701, sub(body.constant(int(1)), r0704), 0x01));


               body.instructions = f0705_parent_instructions;
               body.emit(f0705);

               /* END IF */

               body.emit(assign(r06A1, r0701, 0x01));

               body.emit(assign(r06A4, r0702, 0x01));

               body.emit(assign(r06A5, r0703, 0x01));


            body.instructions = f06FD_parent_instructions;
            body.emit(f06FD);

            /* END IF */


         body.instructions = f06FB_parent_instructions;
         body.emit(f06FB);

         /* END IF */

         /* IF CONDITION */
         ir_if *f0719 = new(mem_ctx) ir_if(operand(r069D).val);
         exec_list *const f0719_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0719->then_instructions;

            /* IF CONDITION */
            ir_expression *const r071B = equal(r06B1, body.constant(int(0)));
            ir_if *f071A = new(mem_ctx) ir_if(operand(r071B).val);
            exec_list *const f071A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f071A->then_instructions;

               /* IF CONDITION */
               ir_expression *const r071D = bit_or(r06AD, swizzle_x(r069C));
               ir_expression *const r071E = equal(r071D, body.constant(0u));
               ir_if *f071C = new(mem_ctx) ir_if(operand(r071E).val);
               exec_list *const f071C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f071C->then_instructions;

                  ir_variable *const r071F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r071F);
                  body.emit(assign(r071F, lshift(r069F, body.constant(int(31))), 0x02));

                  body.emit(assign(r071F, body.constant(0u), 0x01));

                  body.emit(assign(r069E, r071F, 0x03));

                  body.emit(assign(r069D, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f071C->else_instructions;

                  ir_variable *const r0720 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r0720, r06B1, 0x01));

                  ir_variable *const r0721 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r0721, r06AD, 0x01));

                  ir_variable *const r0722 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r0722, r06AC, 0x01));

                  ir_variable *const r0723 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0723);
                  /* IF CONDITION */
                  ir_expression *const r0725 = equal(r06AD, body.constant(0u));
                  ir_if *f0724 = new(mem_ctx) ir_if(operand(r0725).val);
                  exec_list *const f0724_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0724->then_instructions;

                     ir_expression *const r0726 = equal(swizzle_x(r069C), body.constant(0u));
                     ir_expression *const r0727 = expr(ir_unop_find_msb, swizzle_x(r069C));
                     ir_expression *const r0728 = sub(body.constant(int(31)), r0727);
                     ir_expression *const r0729 = expr(ir_triop_csel, r0726, body.constant(int(32)), r0728);
                     body.emit(assign(r0723, add(r0729, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r072B = less(r0723, body.constant(int(0)));
                     ir_if *f072A = new(mem_ctx) ir_if(operand(r072B).val);
                     exec_list *const f072A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f072A->then_instructions;

                        ir_expression *const r072C = neg(r0723);
                        body.emit(assign(r0721, rshift(swizzle_x(r069C), r072C), 0x01));

                        ir_expression *const r072D = bit_and(r0723, body.constant(int(31)));
                        body.emit(assign(r0722, lshift(swizzle_x(r069C), r072D), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f072A->else_instructions;

                        body.emit(assign(r0721, lshift(swizzle_x(r069C), r0723), 0x01));

                        body.emit(assign(r0722, body.constant(0u), 0x01));


                     body.instructions = f072A_parent_instructions;
                     body.emit(f072A);

                     /* END IF */

                     body.emit(assign(r0720, sub(body.constant(int(-31)), r0723), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0724->else_instructions;

                     ir_expression *const r072E = equal(r06AD, body.constant(0u));
                     ir_expression *const r072F = expr(ir_unop_find_msb, r06AD);
                     ir_expression *const r0730 = sub(body.constant(int(31)), r072F);
                     ir_expression *const r0731 = expr(ir_triop_csel, r072E, body.constant(int(32)), r0730);
                     body.emit(assign(r0723, add(r0731, body.constant(int(-11))), 0x01));

                     ir_expression *const r0732 = equal(r0723, body.constant(int(0)));
                     ir_expression *const r0733 = lshift(r06AD, r0723);
                     ir_expression *const r0734 = neg(r0723);
                     ir_expression *const r0735 = bit_and(r0734, body.constant(int(31)));
                     ir_expression *const r0736 = rshift(swizzle_x(r069C), r0735);
                     ir_expression *const r0737 = bit_or(r0733, r0736);
                     body.emit(assign(r0721, expr(ir_triop_csel, r0732, r06AD, r0737), 0x01));

                     body.emit(assign(r0722, lshift(swizzle_x(r069C), r0723), 0x01));

                     body.emit(assign(r0720, sub(body.constant(int(1)), r0723), 0x01));


                  body.instructions = f0724_parent_instructions;
                  body.emit(f0724);

                  /* END IF */

                  body.emit(assign(r06A0, r0720, 0x01));

                  body.emit(assign(r06A2, r0721, 0x01));

                  body.emit(assign(r06A3, r0722, 0x01));


               body.instructions = f071C_parent_instructions;
               body.emit(f071C);

               /* END IF */


            body.instructions = f071A_parent_instructions;
            body.emit(f071A);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0738 = new(mem_ctx) ir_if(operand(r069D).val);
            exec_list *const f0738_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0738->then_instructions;

               ir_expression *const r0739 = add(r06A1, r06A0);
               body.emit(assign(r06A6, add(r0739, body.constant(int(-1024))), 0x01));

               body.emit(assign(r06A4, bit_or(r06A4, body.constant(1048576u)), 0x01));

               ir_variable *const r073A = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r073B = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r073B, lshift(r06A3, body.constant(int(12))), 0x01));

               ir_expression *const r073C = lshift(r06A2, body.constant(int(12)));
               ir_expression *const r073D = rshift(r06A3, body.constant(int(20)));
               body.emit(assign(r073A, bit_or(r073C, r073D), 0x01));

               body.emit(assign(r06A2, r073A, 0x01));

               body.emit(assign(r06A3, r073B, 0x01));

               ir_variable *const r073E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r073E);
               ir_variable *const r073F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r073F);
               ir_variable *const r0740 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0740);
               ir_variable *const r0741 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0741, bit_and(r06A5, body.constant(65535u)), 0x01));

               ir_variable *const r0742 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0742, rshift(r06A5, body.constant(int(16))), 0x01));

               ir_variable *const r0743 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0743, bit_and(r073B, body.constant(65535u)), 0x01));

               ir_variable *const r0744 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0744, rshift(r073B, body.constant(int(16))), 0x01));

               ir_variable *const r0745 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0745, mul(r0742, r0743), 0x01));

               ir_expression *const r0746 = mul(r0741, r0744);
               body.emit(assign(r073F, add(r0746, r0745), 0x01));

               ir_expression *const r0747 = mul(r0742, r0744);
               ir_expression *const r0748 = less(r073F, r0745);
               ir_expression *const r0749 = expr(ir_unop_b2i, r0748);
               ir_expression *const r074A = expr(ir_unop_i2u, r0749);
               ir_expression *const r074B = lshift(r074A, body.constant(int(16)));
               ir_expression *const r074C = rshift(r073F, body.constant(int(16)));
               ir_expression *const r074D = add(r074B, r074C);
               body.emit(assign(r073E, add(r0747, r074D), 0x01));

               body.emit(assign(r073F, lshift(r073F, body.constant(int(16))), 0x01));

               ir_expression *const r074E = mul(r0741, r0743);
               body.emit(assign(r0740, add(r074E, r073F), 0x01));

               ir_expression *const r074F = less(r0740, r073F);
               ir_expression *const r0750 = expr(ir_unop_b2i, r074F);
               ir_expression *const r0751 = expr(ir_unop_i2u, r0750);
               body.emit(assign(r073E, add(r073E, r0751), 0x01));

               ir_variable *const r0752 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0752);
               ir_variable *const r0753 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0753);
               ir_variable *const r0754 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0754);
               ir_variable *const r0755 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0755, bit_and(r06A5, body.constant(65535u)), 0x01));

               ir_variable *const r0756 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0756, rshift(r06A5, body.constant(int(16))), 0x01));

               ir_variable *const r0757 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0757, bit_and(r073A, body.constant(65535u)), 0x01));

               ir_variable *const r0758 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0758, rshift(r073A, body.constant(int(16))), 0x01));

               ir_variable *const r0759 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0759, mul(r0756, r0757), 0x01));

               ir_expression *const r075A = mul(r0755, r0758);
               body.emit(assign(r0753, add(r075A, r0759), 0x01));

               ir_expression *const r075B = mul(r0756, r0758);
               ir_expression *const r075C = less(r0753, r0759);
               ir_expression *const r075D = expr(ir_unop_b2i, r075C);
               ir_expression *const r075E = expr(ir_unop_i2u, r075D);
               ir_expression *const r075F = lshift(r075E, body.constant(int(16)));
               ir_expression *const r0760 = rshift(r0753, body.constant(int(16)));
               ir_expression *const r0761 = add(r075F, r0760);
               body.emit(assign(r0752, add(r075B, r0761), 0x01));

               body.emit(assign(r0753, lshift(r0753, body.constant(int(16))), 0x01));

               ir_expression *const r0762 = mul(r0755, r0757);
               body.emit(assign(r0754, add(r0762, r0753), 0x01));

               ir_expression *const r0763 = less(r0754, r0753);
               ir_expression *const r0764 = expr(ir_unop_b2i, r0763);
               ir_expression *const r0765 = expr(ir_unop_i2u, r0764);
               body.emit(assign(r0752, add(r0752, r0765), 0x01));

               ir_variable *const r0766 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0766, add(r0754, r073E), 0x01));

               ir_variable *const r0767 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0767);
               ir_variable *const r0768 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0768);
               ir_variable *const r0769 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0769);
               ir_variable *const r076A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r076A, bit_and(r06A4, body.constant(65535u)), 0x01));

               ir_variable *const r076B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r076B, rshift(r06A4, body.constant(int(16))), 0x01));

               ir_variable *const r076C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r076C, bit_and(r073A, body.constant(65535u)), 0x01));

               ir_variable *const r076D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r076D, rshift(r073A, body.constant(int(16))), 0x01));

               ir_variable *const r076E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r076E, mul(r076B, r076C), 0x01));

               ir_expression *const r076F = mul(r076A, r076D);
               body.emit(assign(r0768, add(r076F, r076E), 0x01));

               ir_expression *const r0770 = mul(r076B, r076D);
               ir_expression *const r0771 = less(r0768, r076E);
               ir_expression *const r0772 = expr(ir_unop_b2i, r0771);
               ir_expression *const r0773 = expr(ir_unop_i2u, r0772);
               ir_expression *const r0774 = lshift(r0773, body.constant(int(16)));
               ir_expression *const r0775 = rshift(r0768, body.constant(int(16)));
               ir_expression *const r0776 = add(r0774, r0775);
               body.emit(assign(r0767, add(r0770, r0776), 0x01));

               body.emit(assign(r0768, lshift(r0768, body.constant(int(16))), 0x01));

               ir_expression *const r0777 = mul(r076A, r076C);
               body.emit(assign(r0769, add(r0777, r0768), 0x01));

               ir_expression *const r0778 = less(r0769, r0768);
               ir_expression *const r0779 = expr(ir_unop_b2i, r0778);
               ir_expression *const r077A = expr(ir_unop_i2u, r0779);
               body.emit(assign(r0767, add(r0767, r077A), 0x01));

               ir_variable *const r077B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r077C = less(r0766, r0754);
               ir_expression *const r077D = expr(ir_unop_b2i, r077C);
               ir_expression *const r077E = expr(ir_unop_i2u, r077D);
               ir_expression *const r077F = add(r0752, r077E);
               body.emit(assign(r077B, add(r0769, r077F), 0x01));

               ir_variable *const r0780 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0780);
               ir_variable *const r0781 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0781);
               ir_variable *const r0782 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0782);
               ir_variable *const r0783 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0783, bit_and(r06A4, body.constant(65535u)), 0x01));

               ir_variable *const r0784 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0784, rshift(r06A4, body.constant(int(16))), 0x01));

               ir_variable *const r0785 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0785, bit_and(r073B, body.constant(65535u)), 0x01));

               ir_variable *const r0786 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0786, rshift(r073B, body.constant(int(16))), 0x01));

               ir_variable *const r0787 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0787, mul(r0784, r0785), 0x01));

               ir_expression *const r0788 = mul(r0783, r0786);
               body.emit(assign(r0781, add(r0788, r0787), 0x01));

               ir_expression *const r0789 = mul(r0784, r0786);
               ir_expression *const r078A = less(r0781, r0787);
               ir_expression *const r078B = expr(ir_unop_b2i, r078A);
               ir_expression *const r078C = expr(ir_unop_i2u, r078B);
               ir_expression *const r078D = lshift(r078C, body.constant(int(16)));
               ir_expression *const r078E = rshift(r0781, body.constant(int(16)));
               ir_expression *const r078F = add(r078D, r078E);
               body.emit(assign(r0780, add(r0789, r078F), 0x01));

               body.emit(assign(r0781, lshift(r0781, body.constant(int(16))), 0x01));

               ir_expression *const r0790 = mul(r0783, r0785);
               body.emit(assign(r0782, add(r0790, r0781), 0x01));

               ir_expression *const r0791 = less(r0782, r0781);
               ir_expression *const r0792 = expr(ir_unop_b2i, r0791);
               ir_expression *const r0793 = expr(ir_unop_i2u, r0792);
               body.emit(assign(r0780, add(r0780, r0793), 0x01));

               ir_variable *const r0794 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0794, add(r0782, r0766), 0x01));

               ir_variable *const r0795 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0796 = less(r0794, r0782);
               ir_expression *const r0797 = expr(ir_unop_b2i, r0796);
               ir_expression *const r0798 = expr(ir_unop_i2u, r0797);
               ir_expression *const r0799 = add(r0780, r0798);
               body.emit(assign(r0795, add(r077B, r0799), 0x01));

               ir_variable *const r079A = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r079B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r079B, add(r0795, r06A5), 0x01));

               ir_expression *const r079C = less(r077B, r0769);
               ir_expression *const r079D = expr(ir_unop_b2i, r079C);
               ir_expression *const r079E = expr(ir_unop_i2u, r079D);
               ir_expression *const r079F = add(r0767, r079E);
               ir_expression *const r07A0 = less(r0795, r077B);
               ir_expression *const r07A1 = expr(ir_unop_b2i, r07A0);
               ir_expression *const r07A2 = expr(ir_unop_i2u, r07A1);
               ir_expression *const r07A3 = add(r079F, r07A2);
               ir_expression *const r07A4 = add(r07A3, r06A4);
               ir_expression *const r07A5 = less(r079B, r0795);
               ir_expression *const r07A6 = expr(ir_unop_b2i, r07A5);
               ir_expression *const r07A7 = expr(ir_unop_i2u, r07A6);
               body.emit(assign(r079A, add(r07A4, r07A7), 0x01));

               body.emit(assign(r06A9, r079A, 0x01));

               body.emit(assign(r06A8, r079B, 0x01));

               ir_expression *const r07A8 = nequal(r0740, body.constant(0u));
               ir_expression *const r07A9 = expr(ir_unop_b2i, r07A8);
               ir_expression *const r07AA = expr(ir_unop_i2u, r07A9);
               body.emit(assign(r06A7, bit_or(r0794, r07AA), 0x01));

               /* IF CONDITION */
               ir_expression *const r07AC = gequal(r079A, body.constant(2097152u));
               ir_if *f07AB = new(mem_ctx) ir_if(operand(r07AC).val);
               exec_list *const f07AB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f07AB->then_instructions;

                  body.emit(assign(r06A9, rshift(r079A, body.constant(int(1))), 0x01));

                  ir_expression *const r07AD = lshift(r079A, body.constant(int(31)));
                  ir_expression *const r07AE = rshift(r079B, body.constant(int(1)));
                  body.emit(assign(r06A8, bit_or(r07AD, r07AE), 0x01));

                  ir_expression *const r07AF = lshift(r079B, body.constant(int(31)));
                  ir_expression *const r07B0 = nequal(r06A7, body.constant(0u));
                  ir_expression *const r07B1 = expr(ir_unop_b2i, r07B0);
                  ir_expression *const r07B2 = expr(ir_unop_i2u, r07B1);
                  body.emit(assign(r06A7, bit_or(r07AF, r07B2), 0x01));

                  body.emit(assign(r06A6, add(r06A6, body.constant(int(1))), 0x01));


               body.instructions = f07AB_parent_instructions;
               body.emit(f07AB);

               /* END IF */

               ir_variable *const r07B3 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r07B3, r06A6, 0x01));

               ir_variable *const r07B4 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r07B4, r06A9, 0x01));

               ir_variable *const r07B5 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r07B5, r06A8, 0x01));

               ir_variable *const r07B6 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r07B6, r06A7, 0x01));

               ir_variable *const r07B7 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r07B7, body.constant(true), 0x01));

               ir_variable *const r07B8 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r07B9 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r07B9);
               ir_expression *const r07BA = expr(ir_unop_u2i, r06A7);
               body.emit(assign(r07B9, less(r07BA, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r07BC = gequal(r06A6, body.constant(int(2045)));
               ir_if *f07BB = new(mem_ctx) ir_if(operand(r07BC).val);
               exec_list *const f07BB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f07BB->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r07BE = less(body.constant(int(2045)), r06A6);
                  ir_expression *const r07BF = equal(r06A6, body.constant(int(2045)));
                  ir_expression *const r07C0 = equal(body.constant(2097151u), r06A9);
                  ir_expression *const r07C1 = equal(body.constant(4294967295u), r06A8);
                  ir_expression *const r07C2 = logic_and(r07C0, r07C1);
                  ir_expression *const r07C3 = logic_and(r07BF, r07C2);
                  ir_expression *const r07C4 = logic_and(r07C3, r07B9);
                  ir_expression *const r07C5 = logic_or(r07BE, r07C4);
                  ir_if *f07BD = new(mem_ctx) ir_if(operand(r07C5).val);
                  exec_list *const f07BD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f07BD->then_instructions;

                     ir_variable *const r07C6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r07C6);
                     ir_expression *const r07C7 = lshift(r069F, body.constant(int(31)));
                     body.emit(assign(r07C6, add(r07C7, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r07C6, body.constant(0u), 0x01));

                     body.emit(assign(r07B8, r07C6, 0x03));

                     body.emit(assign(r07B7, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f07BD->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r07C9 = less(r06A6, body.constant(int(0)));
                     ir_if *f07C8 = new(mem_ctx) ir_if(operand(r07C9).val);
                     exec_list *const f07C8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f07C8->then_instructions;

                        ir_variable *const r07CA = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r07CA, neg(r06A6), 0x01));

                        ir_variable *const r07CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r07CB);
                        ir_variable *const r07CC = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r07CD = neg(r07CA);
                        body.emit(assign(r07CC, bit_and(r07CD, body.constant(int(31))), 0x01));

                        ir_variable *const r07CE = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r07CF = less(r07CA, body.constant(int(32)));
                        ir_expression *const r07D0 = bit_or(r06A7, r06A8);
                        body.emit(assign(r07CE, expr(ir_triop_csel, r07CF, r06A7, r07D0), 0x01));

                        ir_expression *const r07D1 = less(r07CA, body.constant(int(32)));
                        ir_expression *const r07D2 = lshift(r06A8, r07CC);
                        ir_expression *const r07D3 = less(r07CA, body.constant(int(64)));
                        ir_expression *const r07D4 = lshift(r06A9, r07CC);
                        ir_expression *const r07D5 = equal(r07CA, body.constant(int(64)));
                        ir_expression *const r07D6 = nequal(r06A9, body.constant(0u));
                        ir_expression *const r07D7 = expr(ir_unop_b2i, r07D6);
                        ir_expression *const r07D8 = expr(ir_unop_i2u, r07D7);
                        ir_expression *const r07D9 = expr(ir_triop_csel, r07D5, r06A9, r07D8);
                        ir_expression *const r07DA = expr(ir_triop_csel, r07D3, r07D4, r07D9);
                        ir_expression *const r07DB = expr(ir_triop_csel, r07D1, r07D2, r07DA);
                        ir_expression *const r07DC = nequal(r07CE, body.constant(0u));
                        ir_expression *const r07DD = expr(ir_unop_b2i, r07DC);
                        ir_expression *const r07DE = expr(ir_unop_i2u, r07DD);
                        body.emit(assign(r07CB, bit_or(r07DB, r07DE), 0x01));

                        ir_variable *const r07DF = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r07E0 = equal(r07CA, body.constant(int(0)));
                        ir_expression *const r07E1 = equal(r07CA, body.constant(int(32)));
                        ir_expression *const r07E2 = expr(ir_triop_csel, r07E1, r06A8, r07CB);
                        body.emit(assign(r07DF, expr(ir_triop_csel, r07E0, r07CE, r07E2), 0x01));

                        body.emit(assign(r07CB, r07DF, 0x01));

                        ir_expression *const r07E3 = equal(r07CA, body.constant(int(0)));
                        ir_expression *const r07E4 = equal(r07CA, body.constant(int(32)));
                        ir_expression *const r07E5 = less(r07CA, body.constant(int(32)));
                        ir_expression *const r07E6 = rshift(r06A9, r07CA);
                        ir_expression *const r07E7 = expr(ir_triop_csel, r07E5, r07E6, body.constant(0u));
                        ir_expression *const r07E8 = expr(ir_triop_csel, r07E4, body.constant(0u), r07E7);
                        body.emit(assign(r07B4, expr(ir_triop_csel, r07E3, r06A9, r07E8), 0x01));

                        ir_expression *const r07E9 = equal(r07CA, body.constant(int(0)));
                        ir_expression *const r07EA = equal(r07CA, body.constant(int(32)));
                        ir_expression *const r07EB = less(r07CA, body.constant(int(32)));
                        ir_expression *const r07EC = lshift(r06A9, r07CC);
                        ir_expression *const r07ED = rshift(r06A8, r07CA);
                        ir_expression *const r07EE = bit_or(r07EC, r07ED);
                        ir_expression *const r07EF = less(r07CA, body.constant(int(64)));
                        ir_expression *const r07F0 = bit_and(r07CA, body.constant(int(31)));
                        ir_expression *const r07F1 = rshift(r06A9, r07F0);
                        ir_expression *const r07F2 = expr(ir_triop_csel, r07EF, r07F1, body.constant(0u));
                        ir_expression *const r07F3 = expr(ir_triop_csel, r07EB, r07EE, r07F2);
                        ir_expression *const r07F4 = expr(ir_triop_csel, r07EA, r06A9, r07F3);
                        body.emit(assign(r07B5, expr(ir_triop_csel, r07E9, r06A8, r07F4), 0x01));

                        body.emit(assign(r07B6, r07DF, 0x01));

                        body.emit(assign(r07B3, body.constant(int(0)), 0x01));

                        body.emit(assign(r07B9, less(r07DF, body.constant(0u)), 0x01));


                     body.instructions = f07C8_parent_instructions;
                     body.emit(f07C8);

                     /* END IF */


                  body.instructions = f07BD_parent_instructions;
                  body.emit(f07BD);

                  /* END IF */


               body.instructions = f07BB_parent_instructions;
               body.emit(f07BB);

               /* END IF */

               /* IF CONDITION */
               ir_if *f07F5 = new(mem_ctx) ir_if(operand(r07B7).val);
               exec_list *const f07F5_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f07F5->then_instructions;

                  /* IF CONDITION */
                  ir_if *f07F6 = new(mem_ctx) ir_if(operand(r07B9).val);
                  exec_list *const f07F6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f07F6->then_instructions;

                     ir_variable *const r07F7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r07F7, add(r07B5, body.constant(1u)), 0x01));

                     ir_expression *const r07F8 = less(r07F7, r07B5);
                     ir_expression *const r07F9 = expr(ir_unop_b2i, r07F8);
                     ir_expression *const r07FA = expr(ir_unop_i2u, r07F9);
                     body.emit(assign(r07B4, add(r07B4, r07FA), 0x01));

                     ir_expression *const r07FB = equal(r07B6, body.constant(0u));
                     ir_expression *const r07FC = expr(ir_unop_b2i, r07FB);
                     ir_expression *const r07FD = expr(ir_unop_i2u, r07FC);
                     ir_expression *const r07FE = add(r07B6, r07FD);
                     ir_expression *const r07FF = bit_and(r07FE, body.constant(1u));
                     ir_expression *const r0800 = expr(ir_unop_bit_not, r07FF);
                     body.emit(assign(r07B5, bit_and(r07F7, r0800), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f07F6->else_instructions;

                     ir_expression *const r0801 = bit_or(r07B4, r07B5);
                     ir_expression *const r0802 = equal(r0801, body.constant(0u));
                     body.emit(assign(r07B3, expr(ir_triop_csel, r0802, body.constant(int(0)), r07B3), 0x01));


                  body.instructions = f07F6_parent_instructions;
                  body.emit(f07F6);

                  /* END IF */

                  ir_variable *const r0803 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0803);
                  ir_expression *const r0804 = lshift(r069F, body.constant(int(31)));
                  ir_expression *const r0805 = expr(ir_unop_i2u, r07B3);
                  ir_expression *const r0806 = lshift(r0805, body.constant(int(20)));
                  ir_expression *const r0807 = add(r0804, r0806);
                  body.emit(assign(r0803, add(r0807, r07B4), 0x02));

                  body.emit(assign(r0803, r07B5, 0x01));

                  body.emit(assign(r07B8, r0803, 0x03));

                  body.emit(assign(r07B7, body.constant(false), 0x01));


               body.instructions = f07F5_parent_instructions;
               body.emit(f07F5);

               /* END IF */

               body.emit(assign(r069E, r07B8, 0x03));

               body.emit(assign(r069D, body.constant(false), 0x01));


            body.instructions = f0738_parent_instructions;
            body.emit(f0738);

            /* END IF */


         body.instructions = f0719_parent_instructions;
         body.emit(f0719);

         /* END IF */


      body.instructions = f06DB_parent_instructions;
      body.emit(f06DB);

      /* END IF */


   body.instructions = f06B6_parent_instructions;
   body.emit(f06B6);

   /* END IF */

   body.emit(ret(r069E));

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

   ir_variable *const r0808 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0808);
   ir_variable *const r0809 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0809);
   ir_variable *const r080A = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r080A);
   ir_variable *const r080B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r080B);
   ir_variable *const r080C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r080C);
   ir_expression *const r080D = equal(r080A, body.constant(int(0)));
   ir_expression *const r080E = less(r080A, body.constant(int(32)));
   ir_expression *const r080F = neg(r080A);
   ir_expression *const r0810 = bit_and(r080F, body.constant(int(31)));
   ir_expression *const r0811 = lshift(r0808, r0810);
   ir_expression *const r0812 = rshift(r0809, r080A);
   ir_expression *const r0813 = bit_or(r0811, r0812);
   ir_expression *const r0814 = less(r080A, body.constant(int(64)));
   ir_expression *const r0815 = bit_and(r080A, body.constant(int(31)));
   ir_expression *const r0816 = rshift(r0808, r0815);
   ir_expression *const r0817 = expr(ir_triop_csel, r0814, r0816, body.constant(0u));
   ir_expression *const r0818 = expr(ir_triop_csel, r080E, r0813, r0817);
   body.emit(assign(r080C, expr(ir_triop_csel, r080D, r0808, r0818), 0x01));

   ir_expression *const r0819 = equal(r080A, body.constant(int(0)));
   ir_expression *const r081A = less(r080A, body.constant(int(32)));
   ir_expression *const r081B = rshift(r0808, r080A);
   ir_expression *const r081C = expr(ir_triop_csel, r081A, r081B, body.constant(0u));
   body.emit(assign(r080B, expr(ir_triop_csel, r0819, r0808, r081C), 0x01));

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

   ir_variable *const r081D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r081D);
   ir_variable *const r081E = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r081F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r081F);
   ir_variable *const r0820 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0820);
   body.emit(assign(r0820, swizzle_x(r081D), 0x01));

   ir_variable *const r0821 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0821, bit_and(swizzle_y(r081D), body.constant(1048575u)), 0x01));

   body.emit(assign(r081F, r0821, 0x01));

   ir_variable *const r0822 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0823 = rshift(swizzle_y(r081D), body.constant(int(20)));
   ir_expression *const r0824 = bit_and(r0823, body.constant(2047u));
   body.emit(assign(r0822, expr(ir_unop_u2i, r0824), 0x01));

   ir_variable *const r0825 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0825, rshift(swizzle_y(r081D), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0827 = nequal(r0825, body.constant(0u));
   ir_if *f0826 = new(mem_ctx) ir_if(operand(r0827).val);
   exec_list *const f0826_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0826->then_instructions;

      body.emit(assign(r081E, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0826->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0829 = equal(r0822, body.constant(int(2047)));
      ir_expression *const r082A = bit_or(r0821, swizzle_x(r081D));
      ir_expression *const r082B = nequal(r082A, body.constant(0u));
      ir_expression *const r082C = logic_and(r0829, r082B);
      ir_if *f0828 = new(mem_ctx) ir_if(operand(r082C).val);
      exec_list *const f0828_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0828->then_instructions;

         body.emit(assign(r081E, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0828->else_instructions;

         /* IF CONDITION */
         ir_expression *const r082E = nequal(r0822, body.constant(int(0)));
         ir_if *f082D = new(mem_ctx) ir_if(operand(r082E).val);
         exec_list *const f082D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f082D->then_instructions;

            body.emit(assign(r081F, bit_or(r0821, body.constant(1048576u)), 0x01));


         body.instructions = f082D_parent_instructions;
         body.emit(f082D);

         /* END IF */

         ir_variable *const r082F = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r082F, sub(body.constant(int(1063)), r0822), 0x01));

         /* IF CONDITION */
         ir_expression *const r0831 = less(body.constant(int(0)), r082F);
         ir_if *f0830 = new(mem_ctx) ir_if(operand(r0831).val);
         exec_list *const f0830_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0830->then_instructions;

            ir_variable *const r0832 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0832);
            ir_variable *const r0833 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0834 = neg(r082F);
            body.emit(assign(r0833, bit_and(r0834, body.constant(int(31))), 0x01));

            ir_expression *const r0835 = bit_or(r081F, swizzle_x(r081D));
            ir_expression *const r0836 = nequal(r0835, body.constant(0u));
            ir_expression *const r0837 = expr(ir_unop_b2i, r0836);
            body.emit(assign(r0832, expr(ir_unop_i2u, r0837), 0x01));

            ir_variable *const r0838 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0839 = equal(r082F, body.constant(int(0)));
            ir_expression *const r083A = less(r082F, body.constant(int(32)));
            ir_expression *const r083B = lshift(r081F, r0833);
            ir_expression *const r083C = rshift(swizzle_x(r081D), r082F);
            ir_expression *const r083D = bit_or(r083B, r083C);
            ir_expression *const r083E = lshift(swizzle_x(r081D), r0833);
            ir_expression *const r083F = nequal(r083E, body.constant(0u));
            ir_expression *const r0840 = expr(ir_unop_b2i, r083F);
            ir_expression *const r0841 = expr(ir_unop_i2u, r0840);
            ir_expression *const r0842 = bit_or(r083D, r0841);
            ir_expression *const r0843 = equal(r082F, body.constant(int(32)));
            ir_expression *const r0844 = nequal(swizzle_x(r081D), body.constant(0u));
            ir_expression *const r0845 = expr(ir_unop_b2i, r0844);
            ir_expression *const r0846 = expr(ir_unop_i2u, r0845);
            ir_expression *const r0847 = bit_or(r081F, r0846);
            ir_expression *const r0848 = less(r082F, body.constant(int(64)));
            ir_expression *const r0849 = bit_and(r082F, body.constant(int(31)));
            ir_expression *const r084A = rshift(r081F, r0849);
            ir_expression *const r084B = lshift(r081F, r0833);
            ir_expression *const r084C = bit_or(r084B, swizzle_x(r081D));
            ir_expression *const r084D = nequal(r084C, body.constant(0u));
            ir_expression *const r084E = expr(ir_unop_b2i, r084D);
            ir_expression *const r084F = expr(ir_unop_i2u, r084E);
            ir_expression *const r0850 = bit_or(r084A, r084F);
            ir_expression *const r0851 = expr(ir_triop_csel, r0848, r0850, r0832);
            ir_expression *const r0852 = expr(ir_triop_csel, r0843, r0847, r0851);
            ir_expression *const r0853 = expr(ir_triop_csel, r083A, r0842, r0852);
            body.emit(assign(r0838, expr(ir_triop_csel, r0839, swizzle_x(r081D), r0853), 0x01));

            body.emit(assign(r0832, r0838, 0x01));

            ir_expression *const r0854 = less(r082F, body.constant(int(32)));
            ir_expression *const r0855 = rshift(r081F, r082F);
            ir_expression *const r0856 = equal(r082F, body.constant(int(0)));
            ir_expression *const r0857 = expr(ir_triop_csel, r0856, r081F, body.constant(0u));
            body.emit(assign(r081F, expr(ir_triop_csel, r0854, r0855, r0857), 0x01));

            body.emit(assign(r0820, r0838, 0x01));


         body.instructions = f0830_parent_instructions;
         body.emit(f0830);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0859 = bit_and(r081F, body.constant(4294963200u));
         ir_expression *const r085A = nequal(r0859, body.constant(0u));
         ir_if *f0858 = new(mem_ctx) ir_if(operand(r085A).val);
         exec_list *const f0858_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0858->then_instructions;

            ir_variable *const r085B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r085D = nequal(r0825, body.constant(0u));
            ir_if *f085C = new(mem_ctx) ir_if(operand(r085D).val);
            exec_list *const f085C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f085C->then_instructions;

               body.emit(assign(r085B, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f085C->else_instructions;

               body.emit(assign(r085B, body.constant(4294967295u), 0x01));


            body.instructions = f085C_parent_instructions;
            body.emit(f085C);

            /* END IF */

            body.emit(assign(r081E, r085B, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0858->else_instructions;

            ir_variable *const r085E = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r085F = lshift(r081F, body.constant(int(20)));
            ir_expression *const r0860 = rshift(r0820, body.constant(int(12)));
            body.emit(assign(r085E, bit_or(r085F, r0860), 0x01));

            /* IF CONDITION */
            ir_expression *const r0862 = nequal(r0825, body.constant(0u));
            ir_expression *const r0863 = nequal(r085E, body.constant(0u));
            ir_expression *const r0864 = logic_and(r0862, r0863);
            ir_if *f0861 = new(mem_ctx) ir_if(operand(r0864).val);
            exec_list *const f0861_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0861->then_instructions;

               ir_variable *const r0865 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0867 = nequal(r0825, body.constant(0u));
               ir_if *f0866 = new(mem_ctx) ir_if(operand(r0867).val);
               exec_list *const f0866_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0866->then_instructions;

                  body.emit(assign(r0865, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0866->else_instructions;

                  body.emit(assign(r0865, body.constant(4294967295u), 0x01));


               body.instructions = f0866_parent_instructions;
               body.emit(f0866);

               /* END IF */

               body.emit(assign(r081E, r0865, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0861->else_instructions;

               body.emit(assign(r081E, r085E, 0x01));


            body.instructions = f0861_parent_instructions;
            body.emit(f0861);

            /* END IF */


         body.instructions = f0858_parent_instructions;
         body.emit(f0858);

         /* END IF */


      body.instructions = f0828_parent_instructions;
      body.emit(f0828);

      /* END IF */


   body.instructions = f0826_parent_instructions;
   body.emit(f0826);

   /* END IF */

   body.emit(ret(r081E));

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

   ir_variable *const r0868 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0868);
   ir_variable *const r0869 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r086A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r086A);
   ir_variable *const r086B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r086B);
   /* IF CONDITION */
   ir_expression *const r086D = equal(r0868, body.constant(0u));
   ir_if *f086C = new(mem_ctx) ir_if(operand(r086D).val);
   exec_list *const f086C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f086C->then_instructions;

      body.emit(assign(r0869, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f086C->else_instructions;

      ir_variable *const r086E = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r086F = equal(r0868, body.constant(0u));
      ir_expression *const r0870 = expr(ir_unop_find_msb, r0868);
      ir_expression *const r0871 = sub(body.constant(int(31)), r0870);
      ir_expression *const r0872 = expr(ir_triop_csel, r086F, body.constant(int(32)), r0871);
      body.emit(assign(r086E, add(r0872, body.constant(int(21))), 0x01));

      body.emit(assign(r086B, body.constant(0u), 0x01));

      body.emit(assign(r086A, body.constant(0u), 0x01));

      ir_variable *const r0873 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0874 = neg(r086E);
      body.emit(assign(r0873, bit_and(r0874, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0876 = equal(r086E, body.constant(int(0)));
      ir_if *f0875 = new(mem_ctx) ir_if(operand(r0876).val);
      exec_list *const f0875_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0875->then_instructions;

         body.emit(assign(r086B, body.constant(0u), 0x01));

         body.emit(assign(r086A, r0868, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0875->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0878 = less(r086E, body.constant(int(32)));
         ir_if *f0877 = new(mem_ctx) ir_if(operand(r0878).val);
         exec_list *const f0877_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0877->then_instructions;

            body.emit(assign(r086B, rshift(r0868, r0873), 0x01));

            body.emit(assign(r086A, lshift(r0868, r086E), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0877->else_instructions;

            ir_variable *const r0879 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r087B = less(r086E, body.constant(int(64)));
            ir_if *f087A = new(mem_ctx) ir_if(operand(r087B).val);
            exec_list *const f087A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f087A->then_instructions;

               ir_expression *const r087C = add(r086E, body.constant(int(-32)));
               body.emit(assign(r0879, lshift(r0868, r087C), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f087A->else_instructions;

               body.emit(assign(r0879, body.constant(0u), 0x01));


            body.instructions = f087A_parent_instructions;
            body.emit(f087A);

            /* END IF */

            body.emit(assign(r086B, r0879, 0x01));

            body.emit(assign(r086A, body.constant(0u), 0x01));


         body.instructions = f0877_parent_instructions;
         body.emit(f0877);

         /* END IF */


      body.instructions = f0875_parent_instructions;
      body.emit(f0875);

      /* END IF */

      ir_variable *const r087D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r087D);
      ir_expression *const r087E = sub(body.constant(int(1074)), r086E);
      ir_expression *const r087F = expr(ir_unop_i2u, r087E);
      ir_expression *const r0880 = lshift(r087F, body.constant(int(20)));
      body.emit(assign(r087D, add(r0880, r086B), 0x02));

      body.emit(assign(r087D, r086A, 0x01));

      body.emit(assign(r0869, r087D, 0x03));


   body.instructions = f086C_parent_instructions;
   body.emit(f086C);

   /* END IF */

   body.emit(ret(r0869));

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

   ir_variable *const r0881 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0881);
   ir_variable *const r0882 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0882, body.constant(true), 0x01));

   ir_variable *const r0883 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0884 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0884);
   ir_variable *const r0885 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0885);
   ir_variable *const r0886 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0886);
   ir_variable *const r0887 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0887, bit_and(swizzle_y(r0881), body.constant(1048575u)), 0x01));

   body.emit(assign(r0886, r0887, 0x01));

   ir_variable *const r0888 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0889 = rshift(swizzle_y(r0881), body.constant(int(20)));
   ir_expression *const r088A = bit_and(r0889, body.constant(2047u));
   body.emit(assign(r0888, expr(ir_unop_u2i, r088A), 0x01));

   body.emit(assign(r0885, rshift(swizzle_y(r0881), body.constant(int(31))), 0x01));

   body.emit(assign(r0884, body.constant(0u), 0x01));

   ir_variable *const r088B = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r088B, add(r0888, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r088D = gequal(r088B, body.constant(int(0)));
   ir_if *f088C = new(mem_ctx) ir_if(operand(r088D).val);
   exec_list *const f088C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f088C->then_instructions;

      /* IF CONDITION */
      ir_expression *const r088F = less(body.constant(int(1054)), r0888);
      ir_if *f088E = new(mem_ctx) ir_if(operand(r088F).val);
      exec_list *const f088E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f088E->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0891 = equal(r0888, body.constant(int(2047)));
         ir_expression *const r0892 = bit_or(r0887, swizzle_x(r0881));
         ir_expression *const r0893 = expr(ir_unop_u2i, r0892);
         ir_expression *const r0894 = expr(ir_unop_i2b, r0893);
         ir_expression *const r0895 = logic_and(r0891, r0894);
         ir_if *f0890 = new(mem_ctx) ir_if(operand(r0895).val);
         exec_list *const f0890_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0890->then_instructions;

            body.emit(assign(r0885, body.constant(0u), 0x01));


         body.instructions = f0890_parent_instructions;
         body.emit(f0890);

         /* END IF */

         ir_variable *const r0896 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0898 = expr(ir_unop_u2i, r0885);
         ir_expression *const r0899 = expr(ir_unop_i2b, r0898);
         ir_if *f0897 = new(mem_ctx) ir_if(operand(r0899).val);
         exec_list *const f0897_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0897->then_instructions;

            body.emit(assign(r0896, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0897->else_instructions;

            body.emit(assign(r0896, body.constant(int(2147483647)), 0x01));


         body.instructions = f0897_parent_instructions;
         body.emit(f0897);

         /* END IF */

         body.emit(assign(r0883, r0896, 0x01));

         body.emit(assign(r0882, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f088E->else_instructions;

         ir_variable *const r089A = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r089A, bit_or(r0887, body.constant(1048576u)), 0x01));

         ir_expression *const r089B = equal(r088B, body.constant(int(0)));
         ir_expression *const r089C = lshift(r089A, r088B);
         ir_expression *const r089D = neg(r088B);
         ir_expression *const r089E = bit_and(r089D, body.constant(int(31)));
         ir_expression *const r089F = rshift(swizzle_x(r0881), r089E);
         ir_expression *const r08A0 = bit_or(r089C, r089F);
         body.emit(assign(r0884, expr(ir_triop_csel, r089B, r089A, r08A0), 0x01));


      body.instructions = f088E_parent_instructions;
      body.emit(f088E);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f088C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r08A2 = less(r0888, body.constant(int(1023)));
      ir_if *f08A1 = new(mem_ctx) ir_if(operand(r08A2).val);
      exec_list *const f08A1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08A1->then_instructions;

         body.emit(assign(r0883, body.constant(int(0)), 0x01));

         body.emit(assign(r0882, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08A1->else_instructions;

         body.emit(assign(r0886, bit_or(r0887, body.constant(1048576u)), 0x01));

         ir_expression *const r08A3 = neg(r088B);
         body.emit(assign(r0884, rshift(r0886, r08A3), 0x01));


      body.instructions = f08A1_parent_instructions;
      body.emit(f08A1);

      /* END IF */


   body.instructions = f088C_parent_instructions;
   body.emit(f088C);

   /* END IF */

   /* IF CONDITION */
   ir_if *f08A4 = new(mem_ctx) ir_if(operand(r0882).val);
   exec_list *const f08A4_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08A4->then_instructions;

      ir_variable *const r08A5 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r08A7 = nequal(r0885, body.constant(0u));
      ir_if *f08A6 = new(mem_ctx) ir_if(operand(r08A7).val);
      exec_list *const f08A6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08A6->then_instructions;

         ir_expression *const r08A8 = expr(ir_unop_u2i, r0884);
         body.emit(assign(r08A5, neg(r08A8), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08A6->else_instructions;

         body.emit(assign(r08A5, expr(ir_unop_u2i, r0884), 0x01));


      body.instructions = f08A6_parent_instructions;
      body.emit(f08A6);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r08AA = less(r08A5, body.constant(int(0)));
      ir_expression *const r08AB = expr(ir_unop_b2i, r08AA);
      ir_expression *const r08AC = expr(ir_unop_i2u, r08AB);
      ir_expression *const r08AD = bit_xor(r0885, r08AC);
      ir_expression *const r08AE = expr(ir_unop_u2i, r08AD);
      ir_expression *const r08AF = expr(ir_unop_i2b, r08AE);
      ir_expression *const r08B0 = expr(ir_unop_i2b, r08A5);
      ir_expression *const r08B1 = logic_and(r08AF, r08B0);
      ir_if *f08A9 = new(mem_ctx) ir_if(operand(r08B1).val);
      exec_list *const f08A9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08A9->then_instructions;

         ir_variable *const r08B2 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r08B4 = expr(ir_unop_u2i, r0885);
         ir_expression *const r08B5 = expr(ir_unop_i2b, r08B4);
         ir_if *f08B3 = new(mem_ctx) ir_if(operand(r08B5).val);
         exec_list *const f08B3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08B3->then_instructions;

            body.emit(assign(r08B2, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f08B3->else_instructions;

            body.emit(assign(r08B2, body.constant(int(2147483647)), 0x01));


         body.instructions = f08B3_parent_instructions;
         body.emit(f08B3);

         /* END IF */

         body.emit(assign(r0883, r08B2, 0x01));

         body.emit(assign(r0882, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08A9->else_instructions;

         body.emit(assign(r0883, r08A5, 0x01));

         body.emit(assign(r0882, body.constant(false), 0x01));


      body.instructions = f08A9_parent_instructions;
      body.emit(f08A9);

      /* END IF */


   body.instructions = f08A4_parent_instructions;
   body.emit(f08A4);

   /* END IF */

   body.emit(ret(r0883));

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

   ir_variable *const r08B6 = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r08B6);
   ir_variable *const r08B7 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r08B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r08B8);
   ir_variable *const r08B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r08B9);
   ir_variable *const r08BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r08BA);
   body.emit(assign(r08BA, body.constant(0u), 0x01));

   body.emit(assign(r08B9, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r08BC = equal(r08B6, body.constant(int(0)));
   ir_if *f08BB = new(mem_ctx) ir_if(operand(r08BC).val);
   exec_list *const f08BB_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08BB->then_instructions;

      ir_variable *const r08BD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r08BD);
      body.emit(assign(r08BD, body.constant(0u), 0x02));

      body.emit(assign(r08BD, body.constant(0u), 0x01));

      body.emit(assign(r08B7, r08BD, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f08BB->else_instructions;

      ir_expression *const r08BE = less(r08B6, body.constant(int(0)));
      ir_expression *const r08BF = expr(ir_unop_b2i, r08BE);
      body.emit(assign(r08B8, expr(ir_unop_i2u, r08BF), 0x01));

      ir_variable *const r08C0 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r08C2 = less(r08B6, body.constant(int(0)));
      ir_if *f08C1 = new(mem_ctx) ir_if(operand(r08C2).val);
      exec_list *const f08C1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08C1->then_instructions;

         ir_expression *const r08C3 = neg(r08B6);
         body.emit(assign(r08C0, expr(ir_unop_i2u, r08C3), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08C1->else_instructions;

         body.emit(assign(r08C0, expr(ir_unop_i2u, r08B6), 0x01));


      body.instructions = f08C1_parent_instructions;
      body.emit(f08C1);

      /* END IF */

      ir_variable *const r08C4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r08C5 = equal(r08C0, body.constant(0u));
      ir_expression *const r08C6 = expr(ir_unop_find_msb, r08C0);
      ir_expression *const r08C7 = sub(body.constant(int(31)), r08C6);
      ir_expression *const r08C8 = expr(ir_triop_csel, r08C5, body.constant(int(32)), r08C7);
      body.emit(assign(r08C4, add(r08C8, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r08CA = gequal(r08C4, body.constant(int(0)));
      ir_if *f08C9 = new(mem_ctx) ir_if(operand(r08CA).val);
      exec_list *const f08C9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08C9->then_instructions;

         body.emit(assign(r08BA, lshift(r08C0, r08C4), 0x01));

         body.emit(assign(r08B9, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08C9->else_instructions;

         ir_variable *const r08CB = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r08CB, neg(r08C4), 0x01));

         ir_expression *const r08CC = equal(r08CB, body.constant(int(0)));
         ir_expression *const r08CD = less(r08CB, body.constant(int(32)));
         ir_expression *const r08CE = rshift(r08C0, r08CB);
         ir_expression *const r08CF = expr(ir_triop_csel, r08CD, r08CE, body.constant(0u));
         body.emit(assign(r08BA, expr(ir_triop_csel, r08CC, r08C0, r08CF), 0x01));

         ir_expression *const r08D0 = equal(r08CB, body.constant(int(0)));
         ir_expression *const r08D1 = less(r08CB, body.constant(int(32)));
         ir_expression *const r08D2 = neg(r08CB);
         ir_expression *const r08D3 = bit_and(r08D2, body.constant(int(31)));
         ir_expression *const r08D4 = lshift(r08C0, r08D3);
         ir_expression *const r08D5 = bit_or(r08D4, body.constant(0u));
         ir_expression *const r08D6 = less(r08CB, body.constant(int(64)));
         ir_expression *const r08D7 = bit_and(r08CB, body.constant(int(31)));
         ir_expression *const r08D8 = rshift(r08C0, r08D7);
         ir_expression *const r08D9 = expr(ir_triop_csel, r08D6, r08D8, body.constant(0u));
         ir_expression *const r08DA = expr(ir_triop_csel, r08D1, r08D5, r08D9);
         body.emit(assign(r08B9, expr(ir_triop_csel, r08D0, r08C0, r08DA), 0x01));


      body.instructions = f08C9_parent_instructions;
      body.emit(f08C9);

      /* END IF */

      ir_variable *const r08DB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r08DB);
      ir_expression *const r08DC = lshift(r08B8, body.constant(int(31)));
      ir_expression *const r08DD = sub(body.constant(int(1042)), r08C4);
      ir_expression *const r08DE = expr(ir_unop_i2u, r08DD);
      ir_expression *const r08DF = lshift(r08DE, body.constant(int(20)));
      ir_expression *const r08E0 = add(r08DC, r08DF);
      body.emit(assign(r08DB, add(r08E0, r08BA), 0x02));

      body.emit(assign(r08DB, r08B9, 0x01));

      body.emit(assign(r08B7, r08DB, 0x03));


   body.instructions = f08BB_parent_instructions;
   body.emit(f08BB);

   /* END IF */

   body.emit(ret(r08B7));

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

   ir_variable *const r08E1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r08E1);
   ir_variable *const r08E2 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r08E2);
   ir_variable *const r08E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r08E3);
   ir_variable *const r08E4 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r08E5 = lshift(r08E1, body.constant(int(31)));
   ir_expression *const r08E6 = expr(ir_unop_i2u, r08E2);
   ir_expression *const r08E7 = lshift(r08E6, body.constant(int(23)));
   ir_expression *const r08E8 = add(r08E5, r08E7);
   ir_expression *const r08E9 = add(r08E8, r08E3);
   body.emit(assign(r08E4, expr(ir_unop_bitcast_u2f, r08E9), 0x01));

   body.emit(ret(r08E4));

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

   ir_variable *const r08EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r08EA);
   ir_variable *const r08EB = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r08EB);
   ir_variable *const r08EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r08EC);
   ir_variable *const r08ED = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r08ED, body.constant(true), 0x01));

   ir_variable *const r08EE = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r08EF = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r08EF);
   ir_expression *const r08F0 = bit_and(r08EC, body.constant(127u));
   body.emit(assign(r08EF, expr(ir_unop_u2i, r08F0), 0x01));

   /* IF CONDITION */
   ir_expression *const r08F2 = expr(ir_unop_i2u, r08EB);
   ir_expression *const r08F3 = gequal(r08F2, body.constant(253u));
   ir_if *f08F1 = new(mem_ctx) ir_if(operand(r08F3).val);
   exec_list *const f08F1_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08F1->then_instructions;

      /* IF CONDITION */
      ir_expression *const r08F5 = less(body.constant(int(253)), r08EB);
      ir_expression *const r08F6 = equal(r08EB, body.constant(int(253)));
      ir_expression *const r08F7 = expr(ir_unop_u2i, r08EC);
      ir_expression *const r08F8 = less(r08F7, body.constant(int(-64)));
      ir_expression *const r08F9 = logic_and(r08F6, r08F8);
      ir_expression *const r08FA = logic_or(r08F5, r08F9);
      ir_if *f08F4 = new(mem_ctx) ir_if(operand(r08FA).val);
      exec_list *const f08F4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08F4->then_instructions;

         ir_expression *const r08FB = lshift(r08EA, body.constant(int(31)));
         ir_expression *const r08FC = add(r08FB, body.constant(2139095040u));
         body.emit(assign(r08EE, expr(ir_unop_bitcast_u2f, r08FC), 0x01));

         body.emit(assign(r08ED, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08F4->else_instructions;

         ir_variable *const r08FD = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r08FD, neg(r08EB), 0x01));

         ir_variable *const r08FE = body.make_temp(glsl_type::bool_type, "assignment_tmp");
         body.emit(assign(r08FE, less(r08EB, body.constant(int(0))), 0x01));

         ir_variable *const r08FF = body.make_temp(glsl_type::uint_type, "mix_retval");
         ir_expression *const r0900 = neg(r08EB);
         ir_expression *const r0901 = less(r0900, body.constant(int(32)));
         ir_expression *const r0902 = rshift(r08EC, r08FD);
         ir_expression *const r0903 = neg(r08FD);
         ir_expression *const r0904 = bit_and(r0903, body.constant(int(31)));
         ir_expression *const r0905 = lshift(r08EC, r0904);
         ir_expression *const r0906 = nequal(r0905, body.constant(0u));
         ir_expression *const r0907 = expr(ir_unop_b2i, r0906);
         ir_expression *const r0908 = expr(ir_unop_i2u, r0907);
         ir_expression *const r0909 = bit_or(r0902, r0908);
         ir_expression *const r090A = nequal(r08EC, body.constant(0u));
         ir_expression *const r090B = expr(ir_unop_b2i, r090A);
         ir_expression *const r090C = expr(ir_unop_i2u, r090B);
         ir_expression *const r090D = expr(ir_triop_csel, r0901, r0909, r090C);
         body.emit(assign(r08FF, expr(ir_triop_csel, r08FE, r090D, r08EC), 0x01));

         body.emit(assign(r08EC, r08FF, 0x01));

         ir_expression *const r090E = expr(ir_unop_u2i, r08FF);
         ir_expression *const r090F = bit_and(r090E, body.constant(int(127)));
         body.emit(assign(r08EF, expr(ir_triop_csel, r08FE, r090F, r08EF), 0x01));

         body.emit(assign(r08EB, expr(ir_triop_csel, r08FE, body.constant(int(0)), r08EB), 0x01));


      body.instructions = f08F4_parent_instructions;
      body.emit(f08F4);

      /* END IF */


   body.instructions = f08F1_parent_instructions;
   body.emit(f08F1);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0910 = new(mem_ctx) ir_if(operand(r08ED).val);
   exec_list *const f0910_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0910->then_instructions;

      ir_expression *const r0911 = add(r08EC, body.constant(64u));
      body.emit(assign(r08EC, rshift(r0911, body.constant(int(7))), 0x01));

      ir_expression *const r0912 = bit_xor(r08EF, body.constant(int(64)));
      ir_expression *const r0913 = equal(r0912, body.constant(int(0)));
      ir_expression *const r0914 = expr(ir_unop_b2i, r0913);
      ir_expression *const r0915 = expr(ir_unop_i2u, r0914);
      ir_expression *const r0916 = expr(ir_unop_bit_not, r0915);
      body.emit(assign(r08EC, bit_and(r08EC, r0916), 0x01));

      ir_expression *const r0917 = lshift(r08EA, body.constant(int(31)));
      ir_expression *const r0918 = equal(r08EC, body.constant(0u));
      ir_expression *const r0919 = expr(ir_triop_csel, r0918, body.constant(int(0)), r08EB);
      ir_expression *const r091A = expr(ir_unop_i2u, r0919);
      ir_expression *const r091B = lshift(r091A, body.constant(int(23)));
      ir_expression *const r091C = add(r0917, r091B);
      ir_expression *const r091D = add(r091C, r08EC);
      body.emit(assign(r08EE, expr(ir_unop_bitcast_u2f, r091D), 0x01));

      body.emit(assign(r08ED, body.constant(false), 0x01));


   body.instructions = f0910_parent_instructions;
   body.emit(f0910);

   /* END IF */

   body.emit(ret(r08EE));

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

   ir_variable *const r091E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r091E);
   ir_variable *const r091F = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0920 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0920, swizzle_x(r091E), 0x01));

   ir_variable *const r0921 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0921, bit_and(swizzle_y(r091E), body.constant(1048575u)), 0x01));

   ir_variable *const r0922 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0923 = rshift(swizzle_y(r091E), body.constant(int(20)));
   ir_expression *const r0924 = bit_and(r0923, body.constant(2047u));
   body.emit(assign(r0922, expr(ir_unop_u2i, r0924), 0x01));

   ir_variable *const r0925 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0925, rshift(swizzle_y(r091E), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0927 = equal(r0922, body.constant(int(2047)));
   ir_if *f0926 = new(mem_ctx) ir_if(operand(r0927).val);
   exec_list *const f0926_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0926->then_instructions;

      ir_variable *const r0928 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0928);
      ir_variable *const r0929 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0929, lshift(swizzle_x(r091E), body.constant(int(12))), 0x01));

      ir_expression *const r092A = lshift(swizzle_y(r091E), body.constant(int(12)));
      ir_expression *const r092B = rshift(swizzle_x(r091E), body.constant(int(20)));
      body.emit(assign(r091E, bit_or(r092A, r092B), 0x02));

      body.emit(assign(r091E, r0929, 0x01));

      ir_expression *const r092C = lshift(r0925, body.constant(int(31)));
      ir_expression *const r092D = bit_or(r092C, body.constant(2143289344u));
      ir_expression *const r092E = rshift(swizzle_y(r091E), body.constant(int(9)));
      ir_expression *const r092F = bit_or(r092D, r092E);
      body.emit(assign(r0928, expr(ir_unop_bitcast_u2f, r092F), 0x01));

      ir_variable *const r0930 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0931 = bit_or(r0921, r0920);
      ir_expression *const r0932 = nequal(r0931, body.constant(0u));
      ir_expression *const r0933 = lshift(r0925, body.constant(int(31)));
      ir_expression *const r0934 = add(r0933, body.constant(2139095040u));
      ir_expression *const r0935 = expr(ir_unop_bitcast_u2f, r0934);
      body.emit(assign(r0930, expr(ir_triop_csel, r0932, r0928, r0935), 0x01));

      body.emit(assign(r0928, r0930, 0x01));

      body.emit(assign(r091F, r0930, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0926->else_instructions;

      ir_variable *const r0936 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0937 = lshift(r0921, body.constant(int(10)));
      ir_expression *const r0938 = rshift(r0920, body.constant(int(22)));
      ir_expression *const r0939 = bit_or(r0937, r0938);
      ir_expression *const r093A = lshift(r0920, body.constant(int(10)));
      ir_expression *const r093B = nequal(r093A, body.constant(0u));
      ir_expression *const r093C = expr(ir_unop_b2i, r093B);
      ir_expression *const r093D = expr(ir_unop_i2u, r093C);
      body.emit(assign(r0936, bit_or(r0939, r093D), 0x01));

      ir_variable *const r093E = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r093F = nequal(r0922, body.constant(int(0)));
      ir_expression *const r0940 = bit_or(r0936, body.constant(1073741824u));
      body.emit(assign(r093E, expr(ir_triop_csel, r093F, r0940, r0936), 0x01));

      ir_variable *const r0941 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0941, add(r0922, body.constant(int(-897))), 0x01));

      ir_variable *const r0942 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0942, r093E, 0x01));

      ir_variable *const r0943 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0943, body.constant(true), 0x01));

      ir_variable *const r0944 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0945 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0945);
      ir_expression *const r0946 = bit_and(r093E, body.constant(127u));
      body.emit(assign(r0945, expr(ir_unop_u2i, r0946), 0x01));

      /* IF CONDITION */
      ir_expression *const r0948 = expr(ir_unop_i2u, r0941);
      ir_expression *const r0949 = gequal(r0948, body.constant(253u));
      ir_if *f0947 = new(mem_ctx) ir_if(operand(r0949).val);
      exec_list *const f0947_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0947->then_instructions;

         /* IF CONDITION */
         ir_expression *const r094B = less(body.constant(int(253)), r0941);
         ir_expression *const r094C = equal(r0941, body.constant(int(253)));
         ir_expression *const r094D = expr(ir_unop_u2i, r093E);
         ir_expression *const r094E = less(r094D, body.constant(int(-64)));
         ir_expression *const r094F = logic_and(r094C, r094E);
         ir_expression *const r0950 = logic_or(r094B, r094F);
         ir_if *f094A = new(mem_ctx) ir_if(operand(r0950).val);
         exec_list *const f094A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f094A->then_instructions;

            ir_expression *const r0951 = lshift(r0925, body.constant(int(31)));
            ir_expression *const r0952 = add(r0951, body.constant(2139095040u));
            body.emit(assign(r0944, expr(ir_unop_bitcast_u2f, r0952), 0x01));

            body.emit(assign(r0943, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f094A->else_instructions;

            ir_variable *const r0953 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0953, neg(r0941), 0x01));

            ir_variable *const r0954 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0954, less(r0941, body.constant(int(0))), 0x01));

            ir_variable *const r0955 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0956 = neg(r0941);
            ir_expression *const r0957 = less(r0956, body.constant(int(32)));
            ir_expression *const r0958 = rshift(r093E, r0953);
            ir_expression *const r0959 = neg(r0953);
            ir_expression *const r095A = bit_and(r0959, body.constant(int(31)));
            ir_expression *const r095B = lshift(r093E, r095A);
            ir_expression *const r095C = nequal(r095B, body.constant(0u));
            ir_expression *const r095D = expr(ir_unop_b2i, r095C);
            ir_expression *const r095E = expr(ir_unop_i2u, r095D);
            ir_expression *const r095F = bit_or(r0958, r095E);
            ir_expression *const r0960 = nequal(r093E, body.constant(0u));
            ir_expression *const r0961 = expr(ir_unop_b2i, r0960);
            ir_expression *const r0962 = expr(ir_unop_i2u, r0961);
            ir_expression *const r0963 = expr(ir_triop_csel, r0957, r095F, r0962);
            body.emit(assign(r0955, expr(ir_triop_csel, r0954, r0963, r093E), 0x01));

            body.emit(assign(r0942, r0955, 0x01));

            ir_expression *const r0964 = expr(ir_unop_u2i, r0955);
            ir_expression *const r0965 = bit_and(r0964, body.constant(int(127)));
            body.emit(assign(r0945, expr(ir_triop_csel, r0954, r0965, r0945), 0x01));

            body.emit(assign(r0941, expr(ir_triop_csel, r0954, body.constant(int(0)), r0941), 0x01));


         body.instructions = f094A_parent_instructions;
         body.emit(f094A);

         /* END IF */


      body.instructions = f0947_parent_instructions;
      body.emit(f0947);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0966 = new(mem_ctx) ir_if(operand(r0943).val);
      exec_list *const f0966_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0966->then_instructions;

         ir_expression *const r0967 = add(r0942, body.constant(64u));
         body.emit(assign(r0942, rshift(r0967, body.constant(int(7))), 0x01));

         ir_expression *const r0968 = bit_xor(r0945, body.constant(int(64)));
         ir_expression *const r0969 = equal(r0968, body.constant(int(0)));
         ir_expression *const r096A = expr(ir_unop_b2i, r0969);
         ir_expression *const r096B = expr(ir_unop_i2u, r096A);
         ir_expression *const r096C = expr(ir_unop_bit_not, r096B);
         body.emit(assign(r0942, bit_and(r0942, r096C), 0x01));

         ir_expression *const r096D = lshift(r0925, body.constant(int(31)));
         ir_expression *const r096E = equal(r0942, body.constant(0u));
         ir_expression *const r096F = expr(ir_triop_csel, r096E, body.constant(int(0)), r0941);
         ir_expression *const r0970 = expr(ir_unop_i2u, r096F);
         ir_expression *const r0971 = lshift(r0970, body.constant(int(23)));
         ir_expression *const r0972 = add(r096D, r0971);
         ir_expression *const r0973 = add(r0972, r0942);
         body.emit(assign(r0944, expr(ir_unop_bitcast_u2f, r0973), 0x01));

         body.emit(assign(r0943, body.constant(false), 0x01));


      body.instructions = f0966_parent_instructions;
      body.emit(f0966);

      /* END IF */

      body.emit(assign(r091F, r0944, 0x01));


   body.instructions = f0926_parent_instructions;
   body.emit(f0926);

   /* END IF */

   body.emit(ret(r091F));

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

   ir_variable *const r0974 = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0974);
   ir_variable *const r0975 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0975, body.constant(true), 0x01));

   ir_variable *const r0976 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0977 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0977);
   ir_variable *const r0978 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0978);
   ir_variable *const r0979 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0979);
   ir_variable *const r097A = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r097A, expr(ir_unop_bitcast_f2u, r0974), 0x01));

   ir_variable *const r097B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r097B, bit_and(r097A, body.constant(8388607u)), 0x01));

   body.emit(assign(r0979, r097B, 0x01));

   ir_variable *const r097C = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r097D = rshift(r097A, body.constant(int(23)));
   ir_expression *const r097E = bit_and(r097D, body.constant(255u));
   body.emit(assign(r097C, expr(ir_unop_u2i, r097E), 0x01));

   body.emit(assign(r0978, r097C, 0x01));

   body.emit(assign(r0977, rshift(r097A, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0980 = equal(r097C, body.constant(int(255)));
   ir_if *f097F = new(mem_ctx) ir_if(operand(r0980).val);
   exec_list *const f097F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f097F->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0982 = nequal(r097B, body.constant(0u));
      ir_if *f0981 = new(mem_ctx) ir_if(operand(r0982).val);
      exec_list *const f0981_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0981->then_instructions;

         ir_variable *const r0983 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0983, lshift(r097A, body.constant(int(9))), 0x01));

         ir_variable *const r0984 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0985 = lshift(r0983, body.constant(int(20)));
         body.emit(assign(r0984, bit_or(r0985, body.constant(0u)), 0x01));

         ir_expression *const r0986 = rshift(r0983, body.constant(int(12)));
         ir_expression *const r0987 = lshift(r0977, body.constant(int(31)));
         ir_expression *const r0988 = bit_or(r0987, body.constant(2146959360u));
         body.emit(assign(r0984, bit_or(r0986, r0988), 0x02));

         body.emit(assign(r0976, r0984, 0x03));

         body.emit(assign(r0975, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0981->else_instructions;

         ir_variable *const r0989 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0989);
         ir_expression *const r098A = lshift(r0977, body.constant(int(31)));
         body.emit(assign(r0989, add(r098A, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0989, body.constant(0u), 0x01));

         body.emit(assign(r0976, r0989, 0x03));

         body.emit(assign(r0975, body.constant(false), 0x01));


      body.instructions = f0981_parent_instructions;
      body.emit(f0981);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f097F->else_instructions;

      /* IF CONDITION */
      ir_expression *const r098C = equal(r097C, body.constant(int(0)));
      ir_if *f098B = new(mem_ctx) ir_if(operand(r098C).val);
      exec_list *const f098B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f098B->then_instructions;

         /* IF CONDITION */
         ir_expression *const r098E = equal(r097B, body.constant(0u));
         ir_if *f098D = new(mem_ctx) ir_if(operand(r098E).val);
         exec_list *const f098D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f098D->then_instructions;

            ir_variable *const r098F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r098F);
            body.emit(assign(r098F, lshift(r0977, body.constant(int(31))), 0x02));

            body.emit(assign(r098F, body.constant(0u), 0x01));

            body.emit(assign(r0976, r098F, 0x03));

            body.emit(assign(r0975, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f098D->else_instructions;

            ir_variable *const r0990 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0991 = equal(r097B, body.constant(0u));
            ir_expression *const r0992 = expr(ir_unop_find_msb, r097B);
            ir_expression *const r0993 = sub(body.constant(int(31)), r0992);
            ir_expression *const r0994 = expr(ir_triop_csel, r0991, body.constant(int(32)), r0993);
            body.emit(assign(r0990, add(r0994, body.constant(int(-8))), 0x01));

            body.emit(assign(r0979, lshift(r097B, r0990), 0x01));

            body.emit(assign(r0978, sub(body.constant(int(1)), r0990), 0x01));

            body.emit(assign(r0978, add(r0978, body.constant(int(-1))), 0x01));


         body.instructions = f098D_parent_instructions;
         body.emit(f098D);

         /* END IF */


      body.instructions = f098B_parent_instructions;
      body.emit(f098B);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0995 = new(mem_ctx) ir_if(operand(r0975).val);
      exec_list *const f0995_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0995->then_instructions;

         ir_variable *const r0996 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0996);
         ir_expression *const r0997 = lshift(r0977, body.constant(int(31)));
         ir_expression *const r0998 = add(r0978, body.constant(int(896)));
         ir_expression *const r0999 = expr(ir_unop_i2u, r0998);
         ir_expression *const r099A = lshift(r0999, body.constant(int(20)));
         ir_expression *const r099B = add(r0997, r099A);
         ir_expression *const r099C = rshift(r0979, body.constant(int(3)));
         body.emit(assign(r0996, add(r099B, r099C), 0x02));

         ir_expression *const r099D = lshift(r0979, body.constant(int(29)));
         body.emit(assign(r0996, bit_or(r099D, body.constant(0u)), 0x01));

         body.emit(assign(r0976, r0996, 0x03));

         body.emit(assign(r0975, body.constant(false), 0x01));


      body.instructions = f0995_parent_instructions;
      body.emit(f0995);

      /* END IF */


   body.instructions = f097F_parent_instructions;
   body.emit(f097F);

   /* END IF */

   body.emit(ret(r0976));

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

   ir_variable *const r099E = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r099E);
   ir_variable *const r099F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r099F);
   ir_variable *const r09A0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r09A0);
   ir_variable *const r09A1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r09A1);
   ir_variable *const r09A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r09A2);
   ir_variable *const r09A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r09A3);
   ir_variable *const r09A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09A4);
   ir_variable *const r09A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09A5);
   ir_variable *const r09A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09A6);
   ir_variable *const r09A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r09A7);
   ir_variable *const r09A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r09A8);
   ir_variable *const r09A9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r09A9, add(r09A0, r09A3), 0x01));

   ir_variable *const r09AA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r09AB = less(r09A9, r09A0);
   ir_expression *const r09AC = expr(ir_unop_b2i, r09AB);
   body.emit(assign(r09AA, expr(ir_unop_i2u, r09AC), 0x01));

   ir_variable *const r09AD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r09AD, add(r099F, r09A2), 0x01));

   body.emit(assign(r09A8, add(r09AD, r09AA), 0x01));

   ir_expression *const r09AE = add(r099E, r09A1);
   ir_expression *const r09AF = less(r09A8, r09AA);
   ir_expression *const r09B0 = expr(ir_unop_b2i, r09AF);
   ir_expression *const r09B1 = expr(ir_unop_i2u, r09B0);
   body.emit(assign(r09A7, add(r09AE, r09B1), 0x01));

   ir_expression *const r09B2 = less(r09AD, r099F);
   ir_expression *const r09B3 = expr(ir_unop_b2i, r09B2);
   ir_expression *const r09B4 = expr(ir_unop_i2u, r09B3);
   body.emit(assign(r09A7, add(r09A7, r09B4), 0x01));

   body.emit(assign(r09A6, r09A9, 0x01));

   body.emit(assign(r09A5, r09A8, 0x01));

   body.emit(assign(r09A4, r09A7, 0x01));

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

   ir_variable *const r09B5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09B5);
   ir_variable *const r09B6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09B6);
   ir_variable *const r09B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r09B7);
   ir_variable *const r09B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r09B8);
   ir_variable *const r09B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r09B9);
   ir_variable *const r09BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r09BA);
   ir_variable *const r09BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09BB);
   ir_variable *const r09BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09BC);
   ir_variable *const r09BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09BD);
   ir_variable *const r09BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r09BE);
   ir_variable *const r09BF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r09C0 = less(r09B7, r09BA);
   ir_expression *const r09C1 = expr(ir_unop_b2i, r09C0);
   body.emit(assign(r09BF, expr(ir_unop_i2u, r09C1), 0x01));

   ir_variable *const r09C2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r09C2, sub(r09B6, r09B9), 0x01));

   ir_expression *const r09C3 = sub(r09B5, r09B8);
   ir_expression *const r09C4 = less(r09C2, r09BF);
   ir_expression *const r09C5 = expr(ir_unop_b2i, r09C4);
   ir_expression *const r09C6 = expr(ir_unop_i2u, r09C5);
   body.emit(assign(r09BE, sub(r09C3, r09C6), 0x01));

   ir_expression *const r09C7 = less(r09B6, r09B9);
   ir_expression *const r09C8 = expr(ir_unop_b2i, r09C7);
   ir_expression *const r09C9 = expr(ir_unop_i2u, r09C8);
   body.emit(assign(r09BE, sub(r09BE, r09C9), 0x01));

   body.emit(assign(r09BD, sub(r09B7, r09BA), 0x01));

   body.emit(assign(r09BC, sub(r09C2, r09BF), 0x01));

   body.emit(assign(r09BB, r09BE, 0x01));

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

   ir_variable *const r09CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09CA);
   ir_variable *const r09CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09CB);
   ir_variable *const r09CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r09CC);
   ir_variable *const r09CD = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r09CE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r09CE);
   ir_variable *const r09CF = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r09CF);
   ir_variable *const r09D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r09D0);
   ir_variable *const r09D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r09D1);
   body.emit(assign(r09D0, body.constant(0u), 0x01));

   body.emit(assign(r09CF, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r09D3 = gequal(r09CA, r09CC);
   ir_if *f09D2 = new(mem_ctx) ir_if(operand(r09D3).val);
   exec_list *const f09D2_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09D2->then_instructions;

      body.emit(assign(r09CD, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09D2->else_instructions;

      body.emit(assign(r09D1, rshift(r09CC, body.constant(int(16))), 0x01));

      ir_variable *const r09D4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09D6 = lshift(r09D1, body.constant(int(16)));
      ir_expression *const r09D7 = gequal(r09CA, r09D6);
      ir_if *f09D5 = new(mem_ctx) ir_if(operand(r09D7).val);
      exec_list *const f09D5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09D5->then_instructions;

         body.emit(assign(r09D4, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09D5->else_instructions;

         ir_expression *const r09D8 = expr(ir_binop_div, r09CA, r09D1);
         body.emit(assign(r09D4, lshift(r09D8, body.constant(int(16))), 0x01));


      body.instructions = f09D5_parent_instructions;
      body.emit(f09D5);

      /* END IF */

      body.emit(assign(r09CE, r09D4, 0x01));

      ir_variable *const r09D9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r09D9);
      ir_variable *const r09DA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r09DA);
      ir_variable *const r09DB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r09DB);
      ir_variable *const r09DC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09DC, bit_and(r09CC, body.constant(65535u)), 0x01));

      ir_variable *const r09DD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09DD, rshift(r09CC, body.constant(int(16))), 0x01));

      ir_variable *const r09DE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09DE, bit_and(r09D4, body.constant(65535u)), 0x01));

      ir_variable *const r09DF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09DF, rshift(r09D4, body.constant(int(16))), 0x01));

      ir_variable *const r09E0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r09E0, mul(r09DD, r09DE), 0x01));

      ir_expression *const r09E1 = mul(r09DC, r09DF);
      body.emit(assign(r09DA, add(r09E1, r09E0), 0x01));

      ir_expression *const r09E2 = mul(r09DD, r09DF);
      ir_expression *const r09E3 = less(r09DA, r09E0);
      ir_expression *const r09E4 = expr(ir_unop_b2i, r09E3);
      ir_expression *const r09E5 = expr(ir_unop_i2u, r09E4);
      ir_expression *const r09E6 = lshift(r09E5, body.constant(int(16)));
      ir_expression *const r09E7 = rshift(r09DA, body.constant(int(16)));
      ir_expression *const r09E8 = add(r09E6, r09E7);
      body.emit(assign(r09D9, add(r09E2, r09E8), 0x01));

      body.emit(assign(r09DA, lshift(r09DA, body.constant(int(16))), 0x01));

      ir_expression *const r09E9 = mul(r09DC, r09DE);
      body.emit(assign(r09DB, add(r09E9, r09DA), 0x01));

      ir_expression *const r09EA = less(r09DB, r09DA);
      ir_expression *const r09EB = expr(ir_unop_b2i, r09EA);
      ir_expression *const r09EC = expr(ir_unop_i2u, r09EB);
      body.emit(assign(r09D9, add(r09D9, r09EC), 0x01));

      ir_expression *const r09ED = sub(r09CA, r09D9);
      ir_expression *const r09EE = less(r09CB, r09DB);
      ir_expression *const r09EF = expr(ir_unop_b2i, r09EE);
      ir_expression *const r09F0 = expr(ir_unop_i2u, r09EF);
      body.emit(assign(r09D0, sub(r09ED, r09F0), 0x01));

      body.emit(assign(r09CF, sub(r09CB, r09DB), 0x01));

      /* LOOP BEGIN */
      ir_loop *f09F1 = new(mem_ctx) ir_loop();
      exec_list *const f09F1_parent_instructions = body.instructions;

         body.instructions = &f09F1->body_instructions;

         /* IF CONDITION */
         ir_expression *const r09F3 = expr(ir_unop_u2i, r09D0);
         ir_expression *const r09F4 = gequal(r09F3, body.constant(int(0)));
         ir_if *f09F2 = new(mem_ctx) ir_if(operand(r09F4).val);
         exec_list *const f09F2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09F2->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f09F2_parent_instructions;
         body.emit(f09F2);

         /* END IF */

         body.emit(assign(r09CE, add(r09CE, body.constant(4294901760u)), 0x01));

         ir_variable *const r09F5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r09F6 = lshift(r09CC, body.constant(int(16)));
         body.emit(assign(r09F5, add(r09CF, r09F6), 0x01));

         ir_expression *const r09F7 = add(r09D0, r09D1);
         ir_expression *const r09F8 = less(r09F5, r09CF);
         ir_expression *const r09F9 = expr(ir_unop_b2i, r09F8);
         ir_expression *const r09FA = expr(ir_unop_i2u, r09F9);
         body.emit(assign(r09D0, add(r09F7, r09FA), 0x01));

         body.emit(assign(r09CF, r09F5, 0x01));

      /* LOOP END */

      body.instructions = f09F1_parent_instructions;
      body.emit(f09F1);

      ir_expression *const r09FB = lshift(r09D0, body.constant(int(16)));
      ir_expression *const r09FC = rshift(r09CF, body.constant(int(16)));
      body.emit(assign(r09D0, bit_or(r09FB, r09FC), 0x01));

      ir_variable *const r09FD = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09FF = lshift(r09D1, body.constant(int(16)));
      ir_expression *const r0A00 = gequal(r09D0, r09FF);
      ir_if *f09FE = new(mem_ctx) ir_if(operand(r0A00).val);
      exec_list *const f09FE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09FE->then_instructions;

         body.emit(assign(r09FD, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09FE->else_instructions;

         body.emit(assign(r09FD, expr(ir_binop_div, r09D0, r09D1), 0x01));


      body.instructions = f09FE_parent_instructions;
      body.emit(f09FE);

      /* END IF */

      body.emit(assign(r09CE, bit_or(r09CE, r09FD), 0x01));

      body.emit(assign(r09CD, r09CE, 0x01));


   body.instructions = f09D2_parent_instructions;
   body.emit(f09D2);

   /* END IF */

   body.emit(ret(r09CD));

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

   ir_variable *const r0A01 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A01);
   ir_variable *const r0A02 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0A02, r0A01, 0x03));

   ir_variable *const r0A03 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A04 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A04, bit_and(swizzle_y(r0A01), body.constant(1048575u)), 0x01));

   ir_variable *const r0A05 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A06 = rshift(swizzle_y(r0A01), body.constant(int(20)));
   ir_expression *const r0A07 = bit_and(r0A06, body.constant(2047u));
   body.emit(assign(r0A05, expr(ir_unop_u2i, r0A07), 0x01));

   ir_variable *const r0A08 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A08, rshift(swizzle_y(r0A01), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A0A = equal(r0A05, body.constant(int(2047)));
   ir_if *f0A09 = new(mem_ctx) ir_if(operand(r0A0A).val);
   exec_list *const f0A09_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A09->then_instructions;

      ir_variable *const r0A0B = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0A0B);
      ir_expression *const r0A0C = lshift(swizzle_y(r0A01), body.constant(int(12)));
      ir_expression *const r0A0D = rshift(swizzle_x(r0A01), body.constant(int(20)));
      body.emit(assign(r0A02, bit_or(r0A0C, r0A0D), 0x02));

      body.emit(assign(r0A02, lshift(swizzle_x(r0A01), body.constant(int(12))), 0x01));

      ir_expression *const r0A0E = lshift(r0A08, body.constant(int(31)));
      ir_expression *const r0A0F = bit_or(r0A0E, body.constant(2143289344u));
      ir_expression *const r0A10 = rshift(swizzle_y(r0A02), body.constant(int(9)));
      ir_expression *const r0A11 = bit_or(r0A0F, r0A10);
      body.emit(assign(r0A0B, expr(ir_unop_bitcast_u2f, r0A11), 0x01));

      ir_variable *const r0A12 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0A13 = bit_or(r0A04, swizzle_x(r0A01));
      ir_expression *const r0A14 = nequal(r0A13, body.constant(0u));
      ir_expression *const r0A15 = lshift(r0A08, body.constant(int(31)));
      ir_expression *const r0A16 = add(r0A15, body.constant(2139095040u));
      ir_expression *const r0A17 = expr(ir_unop_bitcast_u2f, r0A16);
      body.emit(assign(r0A12, expr(ir_triop_csel, r0A14, r0A0B, r0A17), 0x01));

      body.emit(assign(r0A0B, r0A12, 0x01));

      body.emit(assign(r0A03, r0A12, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A09->else_instructions;

      ir_variable *const r0A18 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A19 = lshift(r0A04, body.constant(int(10)));
      ir_expression *const r0A1A = rshift(swizzle_x(r0A01), body.constant(int(22)));
      ir_expression *const r0A1B = bit_or(r0A19, r0A1A);
      ir_expression *const r0A1C = lshift(swizzle_x(r0A01), body.constant(int(10)));
      ir_expression *const r0A1D = nequal(r0A1C, body.constant(0u));
      ir_expression *const r0A1E = expr(ir_unop_b2i, r0A1D);
      ir_expression *const r0A1F = expr(ir_unop_i2u, r0A1E);
      body.emit(assign(r0A18, bit_or(r0A1B, r0A1F), 0x01));

      ir_variable *const r0A20 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A21 = nequal(r0A05, body.constant(int(0)));
      ir_expression *const r0A22 = bit_or(r0A18, body.constant(1073741824u));
      body.emit(assign(r0A20, expr(ir_triop_csel, r0A21, r0A22, r0A18), 0x01));

      ir_variable *const r0A23 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0A23, add(r0A05, body.constant(int(-897))), 0x01));

      ir_variable *const r0A24 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0A24, r0A20, 0x01));

      ir_variable *const r0A25 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0A25, body.constant(true), 0x01));

      ir_variable *const r0A26 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0A27 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0A27);
      ir_expression *const r0A28 = bit_and(r0A20, body.constant(127u));
      body.emit(assign(r0A27, expr(ir_unop_u2i, r0A28), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A2A = expr(ir_unop_i2u, r0A23);
      ir_expression *const r0A2B = gequal(r0A2A, body.constant(253u));
      ir_if *f0A29 = new(mem_ctx) ir_if(operand(r0A2B).val);
      exec_list *const f0A29_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A29->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A2D = less(body.constant(int(253)), r0A23);
         ir_expression *const r0A2E = equal(r0A23, body.constant(int(253)));
         ir_expression *const r0A2F = expr(ir_unop_u2i, r0A20);
         ir_expression *const r0A30 = less(r0A2F, body.constant(int(-64)));
         ir_expression *const r0A31 = logic_and(r0A2E, r0A30);
         ir_expression *const r0A32 = logic_or(r0A2D, r0A31);
         ir_if *f0A2C = new(mem_ctx) ir_if(operand(r0A32).val);
         exec_list *const f0A2C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A2C->then_instructions;

            ir_expression *const r0A33 = lshift(r0A08, body.constant(int(31)));
            ir_expression *const r0A34 = add(r0A33, body.constant(2139095040u));
            body.emit(assign(r0A26, expr(ir_unop_bitcast_u2f, r0A34), 0x01));

            body.emit(assign(r0A25, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A2C->else_instructions;

            ir_variable *const r0A35 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0A35, neg(r0A23), 0x01));

            ir_variable *const r0A36 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0A36, less(r0A23, body.constant(int(0))), 0x01));

            ir_variable *const r0A37 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0A38 = neg(r0A23);
            ir_expression *const r0A39 = less(r0A38, body.constant(int(32)));
            ir_expression *const r0A3A = rshift(r0A20, r0A35);
            ir_expression *const r0A3B = neg(r0A35);
            ir_expression *const r0A3C = bit_and(r0A3B, body.constant(int(31)));
            ir_expression *const r0A3D = lshift(r0A20, r0A3C);
            ir_expression *const r0A3E = nequal(r0A3D, body.constant(0u));
            ir_expression *const r0A3F = expr(ir_unop_b2i, r0A3E);
            ir_expression *const r0A40 = expr(ir_unop_i2u, r0A3F);
            ir_expression *const r0A41 = bit_or(r0A3A, r0A40);
            ir_expression *const r0A42 = nequal(r0A20, body.constant(0u));
            ir_expression *const r0A43 = expr(ir_unop_b2i, r0A42);
            ir_expression *const r0A44 = expr(ir_unop_i2u, r0A43);
            ir_expression *const r0A45 = expr(ir_triop_csel, r0A39, r0A41, r0A44);
            body.emit(assign(r0A37, expr(ir_triop_csel, r0A36, r0A45, r0A20), 0x01));

            body.emit(assign(r0A24, r0A37, 0x01));

            ir_expression *const r0A46 = expr(ir_unop_u2i, r0A37);
            ir_expression *const r0A47 = bit_and(r0A46, body.constant(int(127)));
            body.emit(assign(r0A27, expr(ir_triop_csel, r0A36, r0A47, r0A27), 0x01));

            body.emit(assign(r0A23, expr(ir_triop_csel, r0A36, body.constant(int(0)), r0A23), 0x01));


         body.instructions = f0A2C_parent_instructions;
         body.emit(f0A2C);

         /* END IF */


      body.instructions = f0A29_parent_instructions;
      body.emit(f0A29);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A48 = new(mem_ctx) ir_if(operand(r0A25).val);
      exec_list *const f0A48_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A48->then_instructions;

         ir_expression *const r0A49 = add(r0A24, body.constant(64u));
         body.emit(assign(r0A24, rshift(r0A49, body.constant(int(7))), 0x01));

         ir_expression *const r0A4A = bit_xor(r0A27, body.constant(int(64)));
         ir_expression *const r0A4B = equal(r0A4A, body.constant(int(0)));
         ir_expression *const r0A4C = expr(ir_unop_b2i, r0A4B);
         ir_expression *const r0A4D = expr(ir_unop_i2u, r0A4C);
         ir_expression *const r0A4E = expr(ir_unop_bit_not, r0A4D);
         body.emit(assign(r0A24, bit_and(r0A24, r0A4E), 0x01));

         ir_expression *const r0A4F = lshift(r0A08, body.constant(int(31)));
         ir_expression *const r0A50 = equal(r0A24, body.constant(0u));
         ir_expression *const r0A51 = expr(ir_triop_csel, r0A50, body.constant(int(0)), r0A23);
         ir_expression *const r0A52 = expr(ir_unop_i2u, r0A51);
         ir_expression *const r0A53 = lshift(r0A52, body.constant(int(23)));
         ir_expression *const r0A54 = add(r0A4F, r0A53);
         ir_expression *const r0A55 = add(r0A54, r0A24);
         body.emit(assign(r0A26, expr(ir_unop_bitcast_u2f, r0A55), 0x01));

         body.emit(assign(r0A25, body.constant(false), 0x01));


      body.instructions = f0A48_parent_instructions;
      body.emit(f0A48);

      /* END IF */

      body.emit(assign(r0A03, r0A26, 0x01));


   body.instructions = f0A09_parent_instructions;
   body.emit(f0A09);

   /* END IF */

   ir_variable *const r0A56 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A56, body.constant(true), 0x01));

   ir_variable *const r0A57 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A58 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A58);
   ir_variable *const r0A59 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0A59);
   ir_variable *const r0A5A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0A5A);
   ir_variable *const r0A5B = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0A5C = expr(ir_unop_sqrt, r0A03);
   body.emit(assign(r0A5B, expr(ir_unop_bitcast_f2u, r0A5C), 0x01));

   ir_variable *const r0A5D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0A5D, bit_and(r0A5B, body.constant(8388607u)), 0x01));

   body.emit(assign(r0A5A, r0A5D, 0x01));

   ir_variable *const r0A5E = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A5F = rshift(r0A5B, body.constant(int(23)));
   ir_expression *const r0A60 = bit_and(r0A5F, body.constant(255u));
   body.emit(assign(r0A5E, expr(ir_unop_u2i, r0A60), 0x01));

   body.emit(assign(r0A59, r0A5E, 0x01));

   body.emit(assign(r0A58, rshift(r0A5B, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A62 = equal(r0A5E, body.constant(int(255)));
   ir_if *f0A61 = new(mem_ctx) ir_if(operand(r0A62).val);
   exec_list *const f0A61_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A61->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A64 = nequal(r0A5D, body.constant(0u));
      ir_if *f0A63 = new(mem_ctx) ir_if(operand(r0A64).val);
      exec_list *const f0A63_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A63->then_instructions;

         ir_variable *const r0A65 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0A65, lshift(r0A5B, body.constant(int(9))), 0x01));

         ir_variable *const r0A66 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0A67 = lshift(r0A65, body.constant(int(20)));
         body.emit(assign(r0A66, bit_or(r0A67, body.constant(0u)), 0x01));

         ir_expression *const r0A68 = rshift(r0A65, body.constant(int(12)));
         ir_expression *const r0A69 = lshift(r0A58, body.constant(int(31)));
         ir_expression *const r0A6A = bit_or(r0A69, body.constant(2146959360u));
         body.emit(assign(r0A66, bit_or(r0A68, r0A6A), 0x02));

         body.emit(assign(r0A57, r0A66, 0x03));

         body.emit(assign(r0A56, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A63->else_instructions;

         ir_variable *const r0A6B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0A6B);
         ir_expression *const r0A6C = lshift(r0A58, body.constant(int(31)));
         body.emit(assign(r0A6B, add(r0A6C, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0A6B, body.constant(0u), 0x01));

         body.emit(assign(r0A57, r0A6B, 0x03));

         body.emit(assign(r0A56, body.constant(false), 0x01));


      body.instructions = f0A63_parent_instructions;
      body.emit(f0A63);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A61->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A6E = equal(r0A5E, body.constant(int(0)));
      ir_if *f0A6D = new(mem_ctx) ir_if(operand(r0A6E).val);
      exec_list *const f0A6D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A6D->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A70 = equal(r0A5D, body.constant(0u));
         ir_if *f0A6F = new(mem_ctx) ir_if(operand(r0A70).val);
         exec_list *const f0A6F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A6F->then_instructions;

            ir_variable *const r0A71 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0A71);
            body.emit(assign(r0A71, lshift(r0A58, body.constant(int(31))), 0x02));

            body.emit(assign(r0A71, body.constant(0u), 0x01));

            body.emit(assign(r0A57, r0A71, 0x03));

            body.emit(assign(r0A56, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A6F->else_instructions;

            ir_variable *const r0A72 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0A73 = equal(r0A5D, body.constant(0u));
            ir_expression *const r0A74 = expr(ir_unop_find_msb, r0A5D);
            ir_expression *const r0A75 = sub(body.constant(int(31)), r0A74);
            ir_expression *const r0A76 = expr(ir_triop_csel, r0A73, body.constant(int(32)), r0A75);
            body.emit(assign(r0A72, add(r0A76, body.constant(int(-8))), 0x01));

            body.emit(assign(r0A5A, lshift(r0A5D, r0A72), 0x01));

            body.emit(assign(r0A59, sub(body.constant(int(1)), r0A72), 0x01));

            body.emit(assign(r0A59, add(r0A59, body.constant(int(-1))), 0x01));


         body.instructions = f0A6F_parent_instructions;
         body.emit(f0A6F);

         /* END IF */


      body.instructions = f0A6D_parent_instructions;
      body.emit(f0A6D);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A77 = new(mem_ctx) ir_if(operand(r0A56).val);
      exec_list *const f0A77_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A77->then_instructions;

         ir_variable *const r0A78 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0A78);
         ir_expression *const r0A79 = lshift(r0A58, body.constant(int(31)));
         ir_expression *const r0A7A = add(r0A59, body.constant(int(896)));
         ir_expression *const r0A7B = expr(ir_unop_i2u, r0A7A);
         ir_expression *const r0A7C = lshift(r0A7B, body.constant(int(20)));
         ir_expression *const r0A7D = add(r0A79, r0A7C);
         ir_expression *const r0A7E = rshift(r0A5A, body.constant(int(3)));
         body.emit(assign(r0A78, add(r0A7D, r0A7E), 0x02));

         ir_expression *const r0A7F = lshift(r0A5A, body.constant(int(29)));
         body.emit(assign(r0A78, bit_or(r0A7F, body.constant(0u)), 0x01));

         body.emit(assign(r0A57, r0A78, 0x03));

         body.emit(assign(r0A56, body.constant(false), 0x01));


      body.instructions = f0A77_parent_instructions;
      body.emit(f0A77);

      /* END IF */


   body.instructions = f0A61_parent_instructions;
   body.emit(f0A61);

   /* END IF */

   body.emit(ret(r0A57));

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

   ir_variable *const r0A80 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A80);
   ir_variable *const r0A81 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A82 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A83 = rshift(swizzle_y(r0A80), body.constant(int(20)));
   ir_expression *const r0A84 = bit_and(r0A83, body.constant(2047u));
   ir_expression *const r0A85 = expr(ir_unop_u2i, r0A84);
   body.emit(assign(r0A82, add(r0A85, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A87 = less(r0A82, body.constant(int(0)));
   ir_if *f0A86 = new(mem_ctx) ir_if(operand(r0A87).val);
   exec_list *const f0A86_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A86->then_instructions;

      body.emit(assign(r0A81, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A86->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A89 = less(body.constant(int(52)), r0A82);
      ir_if *f0A88 = new(mem_ctx) ir_if(operand(r0A89).val);
      exec_list *const f0A88_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A88->then_instructions;

         body.emit(assign(r0A81, r0A80, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A88->else_instructions;

         ir_variable *const r0A8A = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0A8A, sub(body.constant(int(52)), r0A82), 0x01));

         ir_variable *const r0A8B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A8D = gequal(r0A8A, body.constant(int(32)));
         ir_if *f0A8C = new(mem_ctx) ir_if(operand(r0A8D).val);
         exec_list *const f0A8C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A8C->then_instructions;

            body.emit(assign(r0A8B, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A8C->else_instructions;

            body.emit(assign(r0A8B, lshift(body.constant(4294967295u), r0A8A), 0x01));


         body.instructions = f0A8C_parent_instructions;
         body.emit(f0A8C);

         /* END IF */

         ir_variable *const r0A8E = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A90 = less(r0A8A, body.constant(int(33)));
         ir_if *f0A8F = new(mem_ctx) ir_if(operand(r0A90).val);
         exec_list *const f0A8F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A8F->then_instructions;

            body.emit(assign(r0A8E, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A8F->else_instructions;

            ir_expression *const r0A91 = add(r0A8A, body.constant(int(-32)));
            body.emit(assign(r0A8E, lshift(body.constant(4294967295u), r0A91), 0x01));


         body.instructions = f0A8F_parent_instructions;
         body.emit(f0A8F);

         /* END IF */

         ir_variable *const r0A92 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0A92, bit_and(r0A8B, swizzle_x(r0A80)), 0x01));

         body.emit(assign(r0A92, bit_and(r0A8E, swizzle_y(r0A80)), 0x02));

         body.emit(assign(r0A81, r0A92, 0x03));


      body.instructions = f0A88_parent_instructions;
      body.emit(f0A88);

      /* END IF */


   body.instructions = f0A86_parent_instructions;
   body.emit(f0A86);

   /* END IF */

   body.emit(ret(r0A81));

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

   ir_variable *const r0A93 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A93);
   ir_variable *const r0A94 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A94, body.constant(true), 0x01));

   ir_variable *const r0A95 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A96 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0A96);
   ir_variable *const r0A97 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0A97);
   ir_variable *const r0A98 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A99 = rshift(swizzle_y(r0A93), body.constant(int(20)));
   ir_expression *const r0A9A = bit_and(r0A99, body.constant(2047u));
   ir_expression *const r0A9B = expr(ir_unop_u2i, r0A9A);
   body.emit(assign(r0A98, add(r0A9B, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0A97, swizzle_y(r0A93), 0x01));

   body.emit(assign(r0A96, swizzle_x(r0A93), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A9D = less(r0A98, body.constant(int(20)));
   ir_if *f0A9C = new(mem_ctx) ir_if(operand(r0A9D).val);
   exec_list *const f0A9C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A9C->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A9F = less(r0A98, body.constant(int(0)));
      ir_if *f0A9E = new(mem_ctx) ir_if(operand(r0A9F).val);
      exec_list *const f0A9E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A9E->then_instructions;

         body.emit(assign(r0A97, bit_and(swizzle_y(r0A93), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AA1 = equal(r0A98, body.constant(int(-1)));
         ir_expression *const r0AA2 = nequal(swizzle_x(r0A93), body.constant(0u));
         ir_expression *const r0AA3 = logic_and(r0AA1, r0AA2);
         ir_if *f0AA0 = new(mem_ctx) ir_if(operand(r0AA3).val);
         exec_list *const f0AA0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA0->then_instructions;

            body.emit(assign(r0A97, bit_or(r0A97, body.constant(1072693248u)), 0x01));


         body.instructions = f0AA0_parent_instructions;
         body.emit(f0AA0);

         /* END IF */

         body.emit(assign(r0A96, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A9E->else_instructions;

         ir_variable *const r0AA4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0AA4, rshift(body.constant(1048575u), r0A98), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AA6 = bit_and(r0A97, r0AA4);
         ir_expression *const r0AA7 = equal(r0AA6, body.constant(0u));
         ir_expression *const r0AA8 = equal(r0A96, body.constant(0u));
         ir_expression *const r0AA9 = logic_and(r0AA7, r0AA8);
         ir_if *f0AA5 = new(mem_ctx) ir_if(operand(r0AA9).val);
         exec_list *const f0AA5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA5->then_instructions;

            body.emit(assign(r0A95, r0A93, 0x03));

            body.emit(assign(r0A94, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AA5->else_instructions;

            ir_expression *const r0AAA = rshift(body.constant(524288u), r0A98);
            body.emit(assign(r0A97, add(r0A97, r0AAA), 0x01));

            ir_expression *const r0AAB = expr(ir_unop_bit_not, r0AA4);
            body.emit(assign(r0A97, bit_and(r0A97, r0AAB), 0x01));

            body.emit(assign(r0A96, body.constant(0u), 0x01));


         body.instructions = f0AA5_parent_instructions;
         body.emit(f0AA5);

         /* END IF */


      body.instructions = f0A9E_parent_instructions;
      body.emit(f0A9E);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A9C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0AAD = less(body.constant(int(51)), r0A98);
      ir_expression *const r0AAE = equal(r0A98, body.constant(int(1024)));
      ir_expression *const r0AAF = logic_or(r0AAD, r0AAE);
      ir_if *f0AAC = new(mem_ctx) ir_if(operand(r0AAF).val);
      exec_list *const f0AAC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AAC->then_instructions;

         body.emit(assign(r0A95, r0A93, 0x03));

         body.emit(assign(r0A94, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AAC->else_instructions;

         ir_variable *const r0AB0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0AB1 = add(r0A98, body.constant(int(-20)));
         body.emit(assign(r0AB0, rshift(body.constant(4294967295u), r0AB1), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AB3 = bit_and(r0A96, r0AB0);
         ir_expression *const r0AB4 = equal(r0AB3, body.constant(0u));
         ir_if *f0AB2 = new(mem_ctx) ir_if(operand(r0AB4).val);
         exec_list *const f0AB2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AB2->then_instructions;

            body.emit(assign(r0A95, r0A93, 0x03));

            body.emit(assign(r0A94, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AB2->else_instructions;

            ir_variable *const r0AB5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0AB6 = sub(body.constant(int(51)), r0A98);
            ir_expression *const r0AB7 = lshift(body.constant(1u), r0AB6);
            body.emit(assign(r0AB5, add(r0A96, r0AB7), 0x01));

            /* IF CONDITION */
            ir_expression *const r0AB9 = less(r0AB5, r0A96);
            ir_if *f0AB8 = new(mem_ctx) ir_if(operand(r0AB9).val);
            exec_list *const f0AB8_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AB8->then_instructions;

               body.emit(assign(r0A97, add(r0A97, body.constant(1u)), 0x01));


            body.instructions = f0AB8_parent_instructions;
            body.emit(f0AB8);

            /* END IF */

            ir_expression *const r0ABA = expr(ir_unop_bit_not, r0AB0);
            body.emit(assign(r0A96, bit_and(r0AB5, r0ABA), 0x01));


         body.instructions = f0AB2_parent_instructions;
         body.emit(f0AB2);

         /* END IF */


      body.instructions = f0AAC_parent_instructions;
      body.emit(f0AAC);

      /* END IF */


   body.instructions = f0A9C_parent_instructions;
   body.emit(f0A9C);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0ABB = new(mem_ctx) ir_if(operand(r0A94).val);
   exec_list *const f0ABB_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0ABB->then_instructions;

      body.emit(assign(r0A93, r0A96, 0x01));

      body.emit(assign(r0A93, r0A97, 0x02));

      body.emit(assign(r0A95, r0A93, 0x03));

      body.emit(assign(r0A94, body.constant(false), 0x01));


   body.instructions = f0ABB_parent_instructions;
   body.emit(f0ABB);

   /* END IF */

   body.emit(ret(r0A95));

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

   ir_variable *const r0ABC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0ABC);
   ir_variable *const r0ABD = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0ABD, r0ABC, 0x03));

   ir_variable *const r0ABE = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0ABF = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0ABF, bit_and(swizzle_y(r0ABC), body.constant(1048575u)), 0x01));

   ir_variable *const r0AC0 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0AC1 = rshift(swizzle_y(r0ABC), body.constant(int(20)));
   ir_expression *const r0AC2 = bit_and(r0AC1, body.constant(2047u));
   body.emit(assign(r0AC0, expr(ir_unop_u2i, r0AC2), 0x01));

   ir_variable *const r0AC3 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0AC3, rshift(swizzle_y(r0ABC), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AC5 = equal(r0AC0, body.constant(int(2047)));
   ir_if *f0AC4 = new(mem_ctx) ir_if(operand(r0AC5).val);
   exec_list *const f0AC4_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AC4->then_instructions;

      ir_variable *const r0AC6 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0AC6);
      ir_expression *const r0AC7 = lshift(swizzle_y(r0ABC), body.constant(int(12)));
      ir_expression *const r0AC8 = rshift(swizzle_x(r0ABC), body.constant(int(20)));
      body.emit(assign(r0ABD, bit_or(r0AC7, r0AC8), 0x02));

      body.emit(assign(r0ABD, lshift(swizzle_x(r0ABC), body.constant(int(12))), 0x01));

      ir_expression *const r0AC9 = lshift(r0AC3, body.constant(int(31)));
      ir_expression *const r0ACA = bit_or(r0AC9, body.constant(2143289344u));
      ir_expression *const r0ACB = rshift(swizzle_y(r0ABD), body.constant(int(9)));
      ir_expression *const r0ACC = bit_or(r0ACA, r0ACB);
      body.emit(assign(r0AC6, expr(ir_unop_bitcast_u2f, r0ACC), 0x01));

      ir_variable *const r0ACD = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0ACE = bit_or(r0ABF, swizzle_x(r0ABC));
      ir_expression *const r0ACF = nequal(r0ACE, body.constant(0u));
      ir_expression *const r0AD0 = lshift(r0AC3, body.constant(int(31)));
      ir_expression *const r0AD1 = add(r0AD0, body.constant(2139095040u));
      ir_expression *const r0AD2 = expr(ir_unop_bitcast_u2f, r0AD1);
      body.emit(assign(r0ACD, expr(ir_triop_csel, r0ACF, r0AC6, r0AD2), 0x01));

      body.emit(assign(r0AC6, r0ACD, 0x01));

      body.emit(assign(r0ABE, r0ACD, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AC4->else_instructions;

      ir_variable *const r0AD3 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0AD4 = lshift(r0ABF, body.constant(int(10)));
      ir_expression *const r0AD5 = rshift(swizzle_x(r0ABC), body.constant(int(22)));
      ir_expression *const r0AD6 = bit_or(r0AD4, r0AD5);
      ir_expression *const r0AD7 = lshift(swizzle_x(r0ABC), body.constant(int(10)));
      ir_expression *const r0AD8 = nequal(r0AD7, body.constant(0u));
      ir_expression *const r0AD9 = expr(ir_unop_b2i, r0AD8);
      ir_expression *const r0ADA = expr(ir_unop_i2u, r0AD9);
      body.emit(assign(r0AD3, bit_or(r0AD6, r0ADA), 0x01));

      ir_variable *const r0ADB = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0ADC = nequal(r0AC0, body.constant(int(0)));
      ir_expression *const r0ADD = bit_or(r0AD3, body.constant(1073741824u));
      body.emit(assign(r0ADB, expr(ir_triop_csel, r0ADC, r0ADD, r0AD3), 0x01));

      ir_variable *const r0ADE = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0ADE, add(r0AC0, body.constant(int(-897))), 0x01));

      ir_variable *const r0ADF = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0ADF, r0ADB, 0x01));

      ir_variable *const r0AE0 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0AE0, body.constant(true), 0x01));

      ir_variable *const r0AE1 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0AE2 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0AE2);
      ir_expression *const r0AE3 = bit_and(r0ADB, body.constant(127u));
      body.emit(assign(r0AE2, expr(ir_unop_u2i, r0AE3), 0x01));

      /* IF CONDITION */
      ir_expression *const r0AE5 = expr(ir_unop_i2u, r0ADE);
      ir_expression *const r0AE6 = gequal(r0AE5, body.constant(253u));
      ir_if *f0AE4 = new(mem_ctx) ir_if(operand(r0AE6).val);
      exec_list *const f0AE4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AE4->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0AE8 = less(body.constant(int(253)), r0ADE);
         ir_expression *const r0AE9 = equal(r0ADE, body.constant(int(253)));
         ir_expression *const r0AEA = expr(ir_unop_u2i, r0ADB);
         ir_expression *const r0AEB = less(r0AEA, body.constant(int(-64)));
         ir_expression *const r0AEC = logic_and(r0AE9, r0AEB);
         ir_expression *const r0AED = logic_or(r0AE8, r0AEC);
         ir_if *f0AE7 = new(mem_ctx) ir_if(operand(r0AED).val);
         exec_list *const f0AE7_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AE7->then_instructions;

            ir_expression *const r0AEE = lshift(r0AC3, body.constant(int(31)));
            ir_expression *const r0AEF = add(r0AEE, body.constant(2139095040u));
            body.emit(assign(r0AE1, expr(ir_unop_bitcast_u2f, r0AEF), 0x01));

            body.emit(assign(r0AE0, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AE7->else_instructions;

            ir_variable *const r0AF0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0AF0, neg(r0ADE), 0x01));

            ir_variable *const r0AF1 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0AF1, less(r0ADE, body.constant(int(0))), 0x01));

            ir_variable *const r0AF2 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0AF3 = neg(r0ADE);
            ir_expression *const r0AF4 = less(r0AF3, body.constant(int(32)));
            ir_expression *const r0AF5 = rshift(r0ADB, r0AF0);
            ir_expression *const r0AF6 = neg(r0AF0);
            ir_expression *const r0AF7 = bit_and(r0AF6, body.constant(int(31)));
            ir_expression *const r0AF8 = lshift(r0ADB, r0AF7);
            ir_expression *const r0AF9 = nequal(r0AF8, body.constant(0u));
            ir_expression *const r0AFA = expr(ir_unop_b2i, r0AF9);
            ir_expression *const r0AFB = expr(ir_unop_i2u, r0AFA);
            ir_expression *const r0AFC = bit_or(r0AF5, r0AFB);
            ir_expression *const r0AFD = nequal(r0ADB, body.constant(0u));
            ir_expression *const r0AFE = expr(ir_unop_b2i, r0AFD);
            ir_expression *const r0AFF = expr(ir_unop_i2u, r0AFE);
            ir_expression *const r0B00 = expr(ir_triop_csel, r0AF4, r0AFC, r0AFF);
            body.emit(assign(r0AF2, expr(ir_triop_csel, r0AF1, r0B00, r0ADB), 0x01));

            body.emit(assign(r0ADF, r0AF2, 0x01));

            ir_expression *const r0B01 = expr(ir_unop_u2i, r0AF2);
            ir_expression *const r0B02 = bit_and(r0B01, body.constant(int(127)));
            body.emit(assign(r0AE2, expr(ir_triop_csel, r0AF1, r0B02, r0AE2), 0x01));

            body.emit(assign(r0ADE, expr(ir_triop_csel, r0AF1, body.constant(int(0)), r0ADE), 0x01));


         body.instructions = f0AE7_parent_instructions;
         body.emit(f0AE7);

         /* END IF */


      body.instructions = f0AE4_parent_instructions;
      body.emit(f0AE4);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B03 = new(mem_ctx) ir_if(operand(r0AE0).val);
      exec_list *const f0B03_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B03->then_instructions;

         ir_expression *const r0B04 = add(r0ADF, body.constant(64u));
         body.emit(assign(r0ADF, rshift(r0B04, body.constant(int(7))), 0x01));

         ir_expression *const r0B05 = bit_xor(r0AE2, body.constant(int(64)));
         ir_expression *const r0B06 = equal(r0B05, body.constant(int(0)));
         ir_expression *const r0B07 = expr(ir_unop_b2i, r0B06);
         ir_expression *const r0B08 = expr(ir_unop_i2u, r0B07);
         ir_expression *const r0B09 = expr(ir_unop_bit_not, r0B08);
         body.emit(assign(r0ADF, bit_and(r0ADF, r0B09), 0x01));

         ir_expression *const r0B0A = lshift(r0AC3, body.constant(int(31)));
         ir_expression *const r0B0B = equal(r0ADF, body.constant(0u));
         ir_expression *const r0B0C = expr(ir_triop_csel, r0B0B, body.constant(int(0)), r0ADE);
         ir_expression *const r0B0D = expr(ir_unop_i2u, r0B0C);
         ir_expression *const r0B0E = lshift(r0B0D, body.constant(int(23)));
         ir_expression *const r0B0F = add(r0B0A, r0B0E);
         ir_expression *const r0B10 = add(r0B0F, r0ADF);
         body.emit(assign(r0AE1, expr(ir_unop_bitcast_u2f, r0B10), 0x01));

         body.emit(assign(r0AE0, body.constant(false), 0x01));


      body.instructions = f0B03_parent_instructions;
      body.emit(f0B03);

      /* END IF */

      body.emit(assign(r0ABE, r0AE1, 0x01));


   body.instructions = f0AC4_parent_instructions;
   body.emit(f0AC4);

   /* END IF */

   ir_variable *const r0B11 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B11, body.constant(true), 0x01));

   ir_variable *const r0B12 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B13 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B13);
   ir_variable *const r0B14 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B14);
   ir_variable *const r0B15 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B15);
   ir_variable *const r0B16 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0B17 = expr(ir_unop_rcp, r0ABE);
   body.emit(assign(r0B16, expr(ir_unop_bitcast_f2u, r0B17), 0x01));

   ir_variable *const r0B18 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B18, bit_and(r0B16, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B15, r0B18, 0x01));

   ir_variable *const r0B19 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B1A = rshift(r0B16, body.constant(int(23)));
   ir_expression *const r0B1B = bit_and(r0B1A, body.constant(255u));
   body.emit(assign(r0B19, expr(ir_unop_u2i, r0B1B), 0x01));

   body.emit(assign(r0B14, r0B19, 0x01));

   body.emit(assign(r0B13, rshift(r0B16, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B1D = equal(r0B19, body.constant(int(255)));
   ir_if *f0B1C = new(mem_ctx) ir_if(operand(r0B1D).val);
   exec_list *const f0B1C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B1C->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B1F = nequal(r0B18, body.constant(0u));
      ir_if *f0B1E = new(mem_ctx) ir_if(operand(r0B1F).val);
      exec_list *const f0B1E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B1E->then_instructions;

         ir_variable *const r0B20 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B20, lshift(r0B16, body.constant(int(9))), 0x01));

         ir_variable *const r0B21 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B22 = lshift(r0B20, body.constant(int(20)));
         body.emit(assign(r0B21, bit_or(r0B22, body.constant(0u)), 0x01));

         ir_expression *const r0B23 = rshift(r0B20, body.constant(int(12)));
         ir_expression *const r0B24 = lshift(r0B13, body.constant(int(31)));
         ir_expression *const r0B25 = bit_or(r0B24, body.constant(2146959360u));
         body.emit(assign(r0B21, bit_or(r0B23, r0B25), 0x02));

         body.emit(assign(r0B12, r0B21, 0x03));

         body.emit(assign(r0B11, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B1E->else_instructions;

         ir_variable *const r0B26 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B26);
         ir_expression *const r0B27 = lshift(r0B13, body.constant(int(31)));
         body.emit(assign(r0B26, add(r0B27, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B26, body.constant(0u), 0x01));

         body.emit(assign(r0B12, r0B26, 0x03));

         body.emit(assign(r0B11, body.constant(false), 0x01));


      body.instructions = f0B1E_parent_instructions;
      body.emit(f0B1E);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B1C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B29 = equal(r0B19, body.constant(int(0)));
      ir_if *f0B28 = new(mem_ctx) ir_if(operand(r0B29).val);
      exec_list *const f0B28_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B28->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B2B = equal(r0B18, body.constant(0u));
         ir_if *f0B2A = new(mem_ctx) ir_if(operand(r0B2B).val);
         exec_list *const f0B2A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B2A->then_instructions;

            ir_variable *const r0B2C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B2C);
            body.emit(assign(r0B2C, lshift(r0B13, body.constant(int(31))), 0x02));

            body.emit(assign(r0B2C, body.constant(0u), 0x01));

            body.emit(assign(r0B12, r0B2C, 0x03));

            body.emit(assign(r0B11, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B2A->else_instructions;

            ir_variable *const r0B2D = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0B2E = equal(r0B18, body.constant(0u));
            ir_expression *const r0B2F = expr(ir_unop_find_msb, r0B18);
            ir_expression *const r0B30 = sub(body.constant(int(31)), r0B2F);
            ir_expression *const r0B31 = expr(ir_triop_csel, r0B2E, body.constant(int(32)), r0B30);
            body.emit(assign(r0B2D, add(r0B31, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B15, lshift(r0B18, r0B2D), 0x01));

            body.emit(assign(r0B14, sub(body.constant(int(1)), r0B2D), 0x01));

            body.emit(assign(r0B14, add(r0B14, body.constant(int(-1))), 0x01));


         body.instructions = f0B2A_parent_instructions;
         body.emit(f0B2A);

         /* END IF */


      body.instructions = f0B28_parent_instructions;
      body.emit(f0B28);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B32 = new(mem_ctx) ir_if(operand(r0B11).val);
      exec_list *const f0B32_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B32->then_instructions;

         ir_variable *const r0B33 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B33);
         ir_expression *const r0B34 = lshift(r0B13, body.constant(int(31)));
         ir_expression *const r0B35 = add(r0B14, body.constant(int(896)));
         ir_expression *const r0B36 = expr(ir_unop_i2u, r0B35);
         ir_expression *const r0B37 = lshift(r0B36, body.constant(int(20)));
         ir_expression *const r0B38 = add(r0B34, r0B37);
         ir_expression *const r0B39 = rshift(r0B15, body.constant(int(3)));
         body.emit(assign(r0B33, add(r0B38, r0B39), 0x02));

         ir_expression *const r0B3A = lshift(r0B15, body.constant(int(29)));
         body.emit(assign(r0B33, bit_or(r0B3A, body.constant(0u)), 0x01));

         body.emit(assign(r0B12, r0B33, 0x03));

         body.emit(assign(r0B11, body.constant(false), 0x01));


      body.instructions = f0B32_parent_instructions;
      body.emit(f0B32);

      /* END IF */


   body.instructions = f0B1C_parent_instructions;
   body.emit(f0B1C);

   /* END IF */

   body.emit(ret(r0B12));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
