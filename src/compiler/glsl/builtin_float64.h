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
   ir_variable *const r0211 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0211);
   ir_variable *const r0212 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r0212);
   ir_variable *const r0213 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0213);
   ir_variable *const r0214 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r0214);
   ir_variable *const r0215 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r0215);
   ir_variable *const r0216 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0216);
   ir_variable *const r0217 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0217);
   ir_variable *const r0218 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0218);
   ir_variable *const r0219 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0219, rshift(swizzle_y(r020C), body.constant(int(31))), 0x01));

   body.emit(assign(r0218, r0219, 0x01));

   ir_variable *const r021A = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r021A, rshift(swizzle_y(r020D), body.constant(int(31))), 0x01));

   body.emit(assign(r0217, swizzle_x(r020C), 0x01));

   ir_variable *const r021B = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r021B, bit_and(swizzle_y(r020C), body.constant(1048575u)), 0x01));

   body.emit(assign(r0216, r021B, 0x01));

   body.emit(assign(r0215, swizzle_x(r020D), 0x01));

   ir_variable *const r021C = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r021C, bit_and(swizzle_y(r020D), body.constant(1048575u)), 0x01));

   body.emit(assign(r0214, r021C, 0x01));

   ir_variable *const r021D = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r021E = rshift(swizzle_y(r020C), body.constant(int(20)));
   ir_expression *const r021F = bit_and(r021E, body.constant(2047u));
   body.emit(assign(r021D, expr(ir_unop_u2i, r021F), 0x01));

   body.emit(assign(r0213, r021D, 0x01));

   ir_variable *const r0220 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0221 = rshift(swizzle_y(r020D), body.constant(int(20)));
   ir_expression *const r0222 = bit_and(r0221, body.constant(2047u));
   body.emit(assign(r0220, expr(ir_unop_u2i, r0222), 0x01));

   body.emit(assign(r0212, r0220, 0x01));

   body.emit(assign(r0211, body.constant(0u), 0x01));

   ir_variable *const r0223 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0223, sub(r021D, r0220), 0x01));

   body.emit(assign(r0210, r0223, 0x01));

   /* IF CONDITION */
   ir_expression *const r0225 = equal(r0219, r021A);
   ir_if *f0224 = new(mem_ctx) ir_if(operand(r0225).val);
   exec_list *const f0224_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0224->then_instructions;

      ir_variable *const r0226 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r0226);
      ir_variable *const r0227 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r0227);
      body.emit(assign(r0227, body.constant(0u), 0x01));

      /* IF CONDITION */
      ir_expression *const r0229 = less(body.constant(int(0)), r0223);
      ir_if *f0228 = new(mem_ctx) ir_if(operand(r0229).val);
      exec_list *const f0228_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0228->then_instructions;

         /* IF CONDITION */
         ir_expression *const r022B = equal(r021D, body.constant(int(2047)));
         ir_if *f022A = new(mem_ctx) ir_if(operand(r022B).val);
         exec_list *const f022A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f022A->then_instructions;

            ir_variable *const r022C = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r022C, swizzle_x(r020C), 0x01));

            ir_variable *const r022D = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r022D, swizzle_x(r020D), 0x01));

            body.emit(assign(r022C, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

            body.emit(assign(r022D, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

            ir_expression *const r022E = bit_or(r021B, swizzle_x(r020C));
            ir_expression *const r022F = nequal(r022E, body.constant(0u));
            ir_swizzle *const r0230 = swizzle(r022F, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0231 = lshift(swizzle_y(r020C), body.constant(int(1)));
            ir_expression *const r0232 = gequal(r0231, body.constant(4292870144u));
            ir_expression *const r0233 = nequal(swizzle_x(r020C), body.constant(0u));
            ir_expression *const r0234 = bit_and(swizzle_y(r020C), body.constant(1048575u));
            ir_expression *const r0235 = nequal(r0234, body.constant(0u));
            ir_expression *const r0236 = logic_or(r0233, r0235);
            ir_expression *const r0237 = logic_and(r0232, r0236);
            ir_swizzle *const r0238 = swizzle(r0237, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0239 = lshift(swizzle_y(r020D), body.constant(int(1)));
            ir_expression *const r023A = gequal(r0239, body.constant(4292870144u));
            ir_expression *const r023B = nequal(swizzle_x(r020D), body.constant(0u));
            ir_expression *const r023C = bit_and(swizzle_y(r020D), body.constant(1048575u));
            ir_expression *const r023D = nequal(r023C, body.constant(0u));
            ir_expression *const r023E = logic_or(r023B, r023D);
            ir_expression *const r023F = logic_and(r023A, r023E);
            ir_swizzle *const r0240 = swizzle(r023F, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0241 = expr(ir_triop_csel, r0240, r022D, r022C);
            ir_expression *const r0242 = expr(ir_triop_csel, r0238, r0241, r022D);
            body.emit(assign(r020F, expr(ir_triop_csel, r0230, r0242, r020C), 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f022A->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0244 = equal(r0220, body.constant(int(0)));
            ir_if *f0243 = new(mem_ctx) ir_if(operand(r0244).val);
            exec_list *const f0243_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0243->then_instructions;

               body.emit(assign(r0210, add(r0223, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0243->else_instructions;

               body.emit(assign(r0214, bit_or(r021C, body.constant(1048576u)), 0x01));


            body.instructions = f0243_parent_instructions;
            body.emit(f0243);

            /* END IF */

            ir_variable *const r0245 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_variable *const r0246 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0246);
            ir_variable *const r0247 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0248 = neg(r0210);
            body.emit(assign(r0247, bit_and(r0248, body.constant(int(31))), 0x01));

            ir_variable *const r0249 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r024A = less(r0210, body.constant(int(32)));
            ir_expression *const r024B = bit_or(body.constant(0u), swizzle_x(r020D));
            body.emit(assign(r0249, expr(ir_triop_csel, r024A, body.constant(0u), r024B), 0x01));

            ir_expression *const r024C = less(r0210, body.constant(int(32)));
            ir_expression *const r024D = lshift(swizzle_x(r020D), r0247);
            ir_expression *const r024E = less(r0210, body.constant(int(64)));
            ir_expression *const r024F = lshift(r0214, r0247);
            ir_expression *const r0250 = equal(r0210, body.constant(int(64)));
            ir_expression *const r0251 = nequal(r0214, body.constant(0u));
            ir_expression *const r0252 = expr(ir_unop_b2i, r0251);
            ir_expression *const r0253 = expr(ir_unop_i2u, r0252);
            ir_expression *const r0254 = expr(ir_triop_csel, r0250, r0214, r0253);
            ir_expression *const r0255 = expr(ir_triop_csel, r024E, r024F, r0254);
            ir_expression *const r0256 = expr(ir_triop_csel, r024C, r024D, r0255);
            ir_expression *const r0257 = nequal(r0249, body.constant(0u));
            ir_expression *const r0258 = expr(ir_unop_b2i, r0257);
            ir_expression *const r0259 = expr(ir_unop_i2u, r0258);
            body.emit(assign(r0246, bit_or(r0256, r0259), 0x01));

            ir_variable *const r025A = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r025B = equal(r0210, body.constant(int(0)));
            ir_expression *const r025C = equal(r0210, body.constant(int(32)));
            ir_expression *const r025D = expr(ir_triop_csel, r025C, swizzle_x(r020D), r0246);
            body.emit(assign(r025A, expr(ir_triop_csel, r025B, r0249, r025D), 0x01));

            body.emit(assign(r0246, r025A, 0x01));

            ir_expression *const r025E = equal(r0210, body.constant(int(0)));
            ir_expression *const r025F = equal(r0210, body.constant(int(32)));
            ir_expression *const r0260 = less(r0210, body.constant(int(32)));
            ir_expression *const r0261 = lshift(r0214, r0247);
            ir_expression *const r0262 = rshift(swizzle_x(r020D), r0210);
            ir_expression *const r0263 = bit_or(r0261, r0262);
            ir_expression *const r0264 = less(r0210, body.constant(int(64)));
            ir_expression *const r0265 = bit_and(r0210, body.constant(int(31)));
            ir_expression *const r0266 = rshift(r0214, r0265);
            ir_expression *const r0267 = expr(ir_triop_csel, r0264, r0266, body.constant(0u));
            ir_expression *const r0268 = expr(ir_triop_csel, r0260, r0263, r0267);
            ir_expression *const r0269 = expr(ir_triop_csel, r025F, r0214, r0268);
            body.emit(assign(r0245, expr(ir_triop_csel, r025E, swizzle_x(r020D), r0269), 0x01));

            ir_expression *const r026A = equal(r0210, body.constant(int(0)));
            ir_expression *const r026B = equal(r0210, body.constant(int(32)));
            ir_expression *const r026C = less(r0210, body.constant(int(32)));
            ir_expression *const r026D = rshift(r0214, r0210);
            ir_expression *const r026E = expr(ir_triop_csel, r026C, r026D, body.constant(0u));
            ir_expression *const r026F = expr(ir_triop_csel, r026B, body.constant(0u), r026E);
            body.emit(assign(r0214, expr(ir_triop_csel, r026A, r0214, r026F), 0x01));

            body.emit(assign(r0215, r0245, 0x01));

            body.emit(assign(r0227, r025A, 0x01));

            body.emit(assign(r0226, r021D, 0x01));


         body.instructions = f022A_parent_instructions;
         body.emit(f022A);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0228->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0271 = less(r0210, body.constant(int(0)));
         ir_if *f0270 = new(mem_ctx) ir_if(operand(r0271).val);
         exec_list *const f0270_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0270->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0273 = equal(r0220, body.constant(int(2047)));
            ir_if *f0272 = new(mem_ctx) ir_if(operand(r0273).val);
            exec_list *const f0272_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0272->then_instructions;

               ir_variable *const r0274 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0274);
               ir_expression *const r0275 = lshift(r0219, body.constant(int(31)));
               body.emit(assign(r0274, add(r0275, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0274, body.constant(0u), 0x01));

               ir_variable *const r0276 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0276, swizzle_x(r020C), 0x01));

               ir_variable *const r0277 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0277, swizzle_x(r020D), 0x01));

               body.emit(assign(r0276, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r0277, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r0278 = bit_or(r0214, r0215);
               ir_expression *const r0279 = nequal(r0278, body.constant(0u));
               ir_swizzle *const r027A = swizzle(r0279, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r027B = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r027C = gequal(r027B, body.constant(4292870144u));
               ir_expression *const r027D = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r027E = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r027F = nequal(r027E, body.constant(0u));
               ir_expression *const r0280 = logic_or(r027D, r027F);
               ir_expression *const r0281 = logic_and(r027C, r0280);
               ir_swizzle *const r0282 = swizzle(r0281, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0283 = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r0284 = gequal(r0283, body.constant(4292870144u));
               ir_expression *const r0285 = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r0286 = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r0287 = nequal(r0286, body.constant(0u));
               ir_expression *const r0288 = logic_or(r0285, r0287);
               ir_expression *const r0289 = logic_and(r0284, r0288);
               ir_swizzle *const r028A = swizzle(r0289, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r028B = expr(ir_triop_csel, r028A, r0277, r0276);
               ir_expression *const r028C = expr(ir_triop_csel, r0282, r028B, r0277);
               body.emit(assign(r020F, expr(ir_triop_csel, r027A, r028C, r0274), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0272->else_instructions;

               /* IF CONDITION */
               ir_expression *const r028E = equal(r021D, body.constant(int(0)));
               ir_if *f028D = new(mem_ctx) ir_if(operand(r028E).val);
               exec_list *const f028D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f028D->then_instructions;

                  body.emit(assign(r0210, add(r0210, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f028D->else_instructions;

                  body.emit(assign(r0216, bit_or(r021B, body.constant(1048576u)), 0x01));


               body.instructions = f028D_parent_instructions;
               body.emit(f028D);

               /* END IF */

               ir_variable *const r028F = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r028F, neg(r0210), 0x01));

               ir_variable *const r0290 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               ir_variable *const r0291 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0291);
               ir_variable *const r0292 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0293 = neg(r028F);
               body.emit(assign(r0292, bit_and(r0293, body.constant(int(31))), 0x01));

               ir_variable *const r0294 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0295 = less(r028F, body.constant(int(32)));
               ir_expression *const r0296 = bit_or(body.constant(0u), swizzle_x(r020C));
               body.emit(assign(r0294, expr(ir_triop_csel, r0295, body.constant(0u), r0296), 0x01));

               ir_expression *const r0297 = less(r028F, body.constant(int(32)));
               ir_expression *const r0298 = lshift(swizzle_x(r020C), r0292);
               ir_expression *const r0299 = less(r028F, body.constant(int(64)));
               ir_expression *const r029A = lshift(r0216, r0292);
               ir_expression *const r029B = equal(r028F, body.constant(int(64)));
               ir_expression *const r029C = nequal(r0216, body.constant(0u));
               ir_expression *const r029D = expr(ir_unop_b2i, r029C);
               ir_expression *const r029E = expr(ir_unop_i2u, r029D);
               ir_expression *const r029F = expr(ir_triop_csel, r029B, r0216, r029E);
               ir_expression *const r02A0 = expr(ir_triop_csel, r0299, r029A, r029F);
               ir_expression *const r02A1 = expr(ir_triop_csel, r0297, r0298, r02A0);
               ir_expression *const r02A2 = nequal(r0294, body.constant(0u));
               ir_expression *const r02A3 = expr(ir_unop_b2i, r02A2);
               ir_expression *const r02A4 = expr(ir_unop_i2u, r02A3);
               body.emit(assign(r0291, bit_or(r02A1, r02A4), 0x01));

               ir_variable *const r02A5 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r02A6 = equal(r028F, body.constant(int(0)));
               ir_expression *const r02A7 = equal(r028F, body.constant(int(32)));
               ir_expression *const r02A8 = expr(ir_triop_csel, r02A7, swizzle_x(r020C), r0291);
               body.emit(assign(r02A5, expr(ir_triop_csel, r02A6, r0294, r02A8), 0x01));

               body.emit(assign(r0291, r02A5, 0x01));

               ir_expression *const r02A9 = equal(r028F, body.constant(int(0)));
               ir_expression *const r02AA = equal(r028F, body.constant(int(32)));
               ir_expression *const r02AB = less(r028F, body.constant(int(32)));
               ir_expression *const r02AC = lshift(r0216, r0292);
               ir_expression *const r02AD = rshift(swizzle_x(r020C), r028F);
               ir_expression *const r02AE = bit_or(r02AC, r02AD);
               ir_expression *const r02AF = less(r028F, body.constant(int(64)));
               ir_expression *const r02B0 = bit_and(r028F, body.constant(int(31)));
               ir_expression *const r02B1 = rshift(r0216, r02B0);
               ir_expression *const r02B2 = expr(ir_triop_csel, r02AF, r02B1, body.constant(0u));
               ir_expression *const r02B3 = expr(ir_triop_csel, r02AB, r02AE, r02B2);
               ir_expression *const r02B4 = expr(ir_triop_csel, r02AA, r0216, r02B3);
               body.emit(assign(r0290, expr(ir_triop_csel, r02A9, swizzle_x(r020C), r02B4), 0x01));

               ir_expression *const r02B5 = equal(r028F, body.constant(int(0)));
               ir_expression *const r02B6 = equal(r028F, body.constant(int(32)));
               ir_expression *const r02B7 = less(r028F, body.constant(int(32)));
               ir_expression *const r02B8 = rshift(r0216, r028F);
               ir_expression *const r02B9 = expr(ir_triop_csel, r02B7, r02B8, body.constant(0u));
               ir_expression *const r02BA = expr(ir_triop_csel, r02B6, body.constant(0u), r02B9);
               body.emit(assign(r0216, expr(ir_triop_csel, r02B5, r0216, r02BA), 0x01));

               body.emit(assign(r0217, r0290, 0x01));

               body.emit(assign(r0227, r02A5, 0x01));

               body.emit(assign(r0226, r0220, 0x01));


            body.instructions = f0272_parent_instructions;
            body.emit(f0272);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0270->else_instructions;

            /* IF CONDITION */
            ir_expression *const r02BC = equal(r021D, body.constant(int(2047)));
            ir_if *f02BB = new(mem_ctx) ir_if(operand(r02BC).val);
            exec_list *const f02BB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02BB->then_instructions;

               ir_variable *const r02BD = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r02BD, swizzle_x(r020C), 0x01));

               ir_variable *const r02BE = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r02BE, swizzle_x(r020D), 0x01));

               body.emit(assign(r02BD, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r02BE, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r02BF = bit_or(r0216, r0217);
               ir_expression *const r02C0 = bit_or(r0214, r0215);
               ir_expression *const r02C1 = bit_or(r02BF, r02C0);
               ir_expression *const r02C2 = nequal(r02C1, body.constant(0u));
               ir_swizzle *const r02C3 = swizzle(r02C2, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r02C4 = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r02C5 = gequal(r02C4, body.constant(4292870144u));
               ir_expression *const r02C6 = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r02C7 = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r02C8 = nequal(r02C7, body.constant(0u));
               ir_expression *const r02C9 = logic_or(r02C6, r02C8);
               ir_expression *const r02CA = logic_and(r02C5, r02C9);
               ir_swizzle *const r02CB = swizzle(r02CA, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r02CC = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r02CD = gequal(r02CC, body.constant(4292870144u));
               ir_expression *const r02CE = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r02CF = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r02D0 = nequal(r02CF, body.constant(0u));
               ir_expression *const r02D1 = logic_or(r02CE, r02D0);
               ir_expression *const r02D2 = logic_and(r02CD, r02D1);
               ir_swizzle *const r02D3 = swizzle(r02D2, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r02D4 = expr(ir_triop_csel, r02D3, r02BE, r02BD);
               ir_expression *const r02D5 = expr(ir_triop_csel, r02CB, r02D4, r02BE);
               body.emit(assign(r020F, expr(ir_triop_csel, r02C3, r02D5, r020C), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f02BB->else_instructions;

               ir_variable *const r02D6 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r02D7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r02D7, add(r0217, r0215), 0x01));

               ir_expression *const r02D8 = add(r0216, r0214);
               ir_expression *const r02D9 = less(r02D7, r0217);
               ir_expression *const r02DA = expr(ir_unop_b2i, r02D9);
               ir_expression *const r02DB = expr(ir_unop_i2u, r02DA);
               body.emit(assign(r02D6, add(r02D8, r02DB), 0x01));

               body.emit(assign(r0211, r02D6, 0x01));

               /* IF CONDITION */
               ir_expression *const r02DD = equal(r021D, body.constant(int(0)));
               ir_if *f02DC = new(mem_ctx) ir_if(operand(r02DD).val);
               exec_list *const f02DC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02DC->then_instructions;

                  ir_variable *const r02DE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02DE);
                  ir_expression *const r02DF = lshift(r0219, body.constant(int(31)));
                  body.emit(assign(r02DE, add(r02DF, r02D6), 0x02));

                  body.emit(assign(r02DE, r02D7, 0x01));

                  body.emit(assign(r020F, r02DE, 0x03));

                  body.emit(assign(r020E, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02DC->else_instructions;

                  body.emit(assign(r0211, bit_or(r02D6, body.constant(2097152u)), 0x01));

                  body.emit(assign(r0226, r021D, 0x01));

                  ir_variable *const r02E0 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_variable *const r02E1 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  ir_variable *const r02E2 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r02E3 = lshift(r02D7, body.constant(int(31)));
                  body.emit(assign(r02E2, bit_or(r02E3, body.constant(0u)), 0x01));

                  ir_expression *const r02E4 = lshift(r0211, body.constant(int(31)));
                  ir_expression *const r02E5 = rshift(r02D7, body.constant(int(1)));
                  body.emit(assign(r02E1, bit_or(r02E4, r02E5), 0x01));

                  body.emit(assign(r02E0, rshift(r0211, body.constant(int(1))), 0x01));

                  body.emit(assign(r0211, r02E0, 0x01));

                  body.emit(assign(r0227, r02E2, 0x01));

                  ir_variable *const r02E6 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r02E6, r021D, 0x01));

                  ir_variable *const r02E7 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r02E7, r02E0, 0x01));

                  ir_variable *const r02E8 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r02E8, r02E1, 0x01));

                  ir_variable *const r02E9 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r02E9, r02E2, 0x01));

                  ir_variable *const r02EA = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r02EA, body.constant(true), 0x01));

                  ir_variable *const r02EB = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r02EC = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r02EC);
                  ir_expression *const r02ED = expr(ir_unop_u2i, r02E2);
                  body.emit(assign(r02EC, less(r02ED, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r02EF = gequal(r021D, body.constant(int(2045)));
                  ir_if *f02EE = new(mem_ctx) ir_if(operand(r02EF).val);
                  exec_list *const f02EE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02EE->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r02F1 = less(body.constant(int(2045)), r021D);
                     ir_expression *const r02F2 = equal(r021D, body.constant(int(2045)));
                     ir_expression *const r02F3 = equal(body.constant(2097151u), r02E0);
                     ir_expression *const r02F4 = equal(body.constant(4294967295u), r02E1);
                     ir_expression *const r02F5 = logic_and(r02F3, r02F4);
                     ir_expression *const r02F6 = logic_and(r02F2, r02F5);
                     ir_expression *const r02F7 = logic_and(r02F6, r02EC);
                     ir_expression *const r02F8 = logic_or(r02F1, r02F7);
                     ir_if *f02F0 = new(mem_ctx) ir_if(operand(r02F8).val);
                     exec_list *const f02F0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02F0->then_instructions;

                        ir_variable *const r02F9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r02F9);
                        ir_expression *const r02FA = lshift(r0219, body.constant(int(31)));
                        body.emit(assign(r02F9, add(r02FA, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r02F9, body.constant(0u), 0x01));

                        body.emit(assign(r02EB, r02F9, 0x03));

                        body.emit(assign(r02EA, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02F0->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02FC = less(r021D, body.constant(int(0)));
                        ir_if *f02FB = new(mem_ctx) ir_if(operand(r02FC).val);
                        exec_list *const f02FB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02FB->then_instructions;

                           ir_variable *const r02FD = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r02FD, neg(r021D), 0x01));

                           ir_variable *const r02FE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r02FE);
                           ir_variable *const r02FF = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0300 = neg(r02FD);
                           body.emit(assign(r02FF, bit_and(r0300, body.constant(int(31))), 0x01));

                           ir_variable *const r0301 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r0302 = less(r02FD, body.constant(int(32)));
                           ir_expression *const r0303 = bit_or(r02E2, r02E1);
                           body.emit(assign(r0301, expr(ir_triop_csel, r0302, r02E2, r0303), 0x01));

                           ir_expression *const r0304 = less(r02FD, body.constant(int(32)));
                           ir_expression *const r0305 = lshift(r02E1, r02FF);
                           ir_expression *const r0306 = less(r02FD, body.constant(int(64)));
                           ir_expression *const r0307 = lshift(r02E0, r02FF);
                           ir_expression *const r0308 = equal(r02FD, body.constant(int(64)));
                           ir_expression *const r0309 = nequal(r02E0, body.constant(0u));
                           ir_expression *const r030A = expr(ir_unop_b2i, r0309);
                           ir_expression *const r030B = expr(ir_unop_i2u, r030A);
                           ir_expression *const r030C = expr(ir_triop_csel, r0308, r02E0, r030B);
                           ir_expression *const r030D = expr(ir_triop_csel, r0306, r0307, r030C);
                           ir_expression *const r030E = expr(ir_triop_csel, r0304, r0305, r030D);
                           ir_expression *const r030F = nequal(r0301, body.constant(0u));
                           ir_expression *const r0310 = expr(ir_unop_b2i, r030F);
                           ir_expression *const r0311 = expr(ir_unop_i2u, r0310);
                           body.emit(assign(r02FE, bit_or(r030E, r0311), 0x01));

                           ir_variable *const r0312 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r0313 = equal(r02FD, body.constant(int(0)));
                           ir_expression *const r0314 = equal(r02FD, body.constant(int(32)));
                           ir_expression *const r0315 = expr(ir_triop_csel, r0314, r02E1, r02FE);
                           body.emit(assign(r0312, expr(ir_triop_csel, r0313, r0301, r0315), 0x01));

                           body.emit(assign(r02FE, r0312, 0x01));

                           ir_expression *const r0316 = equal(r02FD, body.constant(int(0)));
                           ir_expression *const r0317 = equal(r02FD, body.constant(int(32)));
                           ir_expression *const r0318 = less(r02FD, body.constant(int(32)));
                           ir_expression *const r0319 = rshift(r02E0, r02FD);
                           ir_expression *const r031A = expr(ir_triop_csel, r0318, r0319, body.constant(0u));
                           ir_expression *const r031B = expr(ir_triop_csel, r0317, body.constant(0u), r031A);
                           body.emit(assign(r02E7, expr(ir_triop_csel, r0316, r02E0, r031B), 0x01));

                           ir_expression *const r031C = equal(r02FD, body.constant(int(0)));
                           ir_expression *const r031D = equal(r02FD, body.constant(int(32)));
                           ir_expression *const r031E = less(r02FD, body.constant(int(32)));
                           ir_expression *const r031F = lshift(r02E0, r02FF);
                           ir_expression *const r0320 = rshift(r02E1, r02FD);
                           ir_expression *const r0321 = bit_or(r031F, r0320);
                           ir_expression *const r0322 = less(r02FD, body.constant(int(64)));
                           ir_expression *const r0323 = bit_and(r02FD, body.constant(int(31)));
                           ir_expression *const r0324 = rshift(r02E0, r0323);
                           ir_expression *const r0325 = expr(ir_triop_csel, r0322, r0324, body.constant(0u));
                           ir_expression *const r0326 = expr(ir_triop_csel, r031E, r0321, r0325);
                           ir_expression *const r0327 = expr(ir_triop_csel, r031D, r02E0, r0326);
                           body.emit(assign(r02E8, expr(ir_triop_csel, r031C, r02E1, r0327), 0x01));

                           body.emit(assign(r02E9, r0312, 0x01));

                           body.emit(assign(r02E6, body.constant(int(0)), 0x01));

                           body.emit(assign(r02EC, less(r0312, body.constant(0u)), 0x01));


                        body.instructions = f02FB_parent_instructions;
                        body.emit(f02FB);

                        /* END IF */


                     body.instructions = f02F0_parent_instructions;
                     body.emit(f02F0);

                     /* END IF */


                  body.instructions = f02EE_parent_instructions;
                  body.emit(f02EE);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0328 = new(mem_ctx) ir_if(operand(r02EA).val);
                  exec_list *const f0328_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0328->then_instructions;

                     /* IF CONDITION */
                     ir_if *f0329 = new(mem_ctx) ir_if(operand(r02EC).val);
                     exec_list *const f0329_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0329->then_instructions;

                        ir_variable *const r032A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r032A, add(r02E8, body.constant(1u)), 0x01));

                        ir_expression *const r032B = less(r032A, r02E8);
                        ir_expression *const r032C = expr(ir_unop_b2i, r032B);
                        ir_expression *const r032D = expr(ir_unop_i2u, r032C);
                        body.emit(assign(r02E7, add(r02E7, r032D), 0x01));

                        ir_expression *const r032E = equal(r02E9, body.constant(0u));
                        ir_expression *const r032F = expr(ir_unop_b2i, r032E);
                        ir_expression *const r0330 = expr(ir_unop_i2u, r032F);
                        ir_expression *const r0331 = add(r02E9, r0330);
                        ir_expression *const r0332 = bit_and(r0331, body.constant(1u));
                        ir_expression *const r0333 = expr(ir_unop_bit_not, r0332);
                        body.emit(assign(r02E8, bit_and(r032A, r0333), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0329->else_instructions;

                        ir_expression *const r0334 = bit_or(r02E7, r02E8);
                        ir_expression *const r0335 = equal(r0334, body.constant(0u));
                        body.emit(assign(r02E6, expr(ir_triop_csel, r0335, body.constant(int(0)), r02E6), 0x01));


                     body.instructions = f0329_parent_instructions;
                     body.emit(f0329);

                     /* END IF */

                     ir_variable *const r0336 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0336);
                     ir_expression *const r0337 = lshift(r0219, body.constant(int(31)));
                     ir_expression *const r0338 = expr(ir_unop_i2u, r02E6);
                     ir_expression *const r0339 = lshift(r0338, body.constant(int(20)));
                     ir_expression *const r033A = add(r0337, r0339);
                     body.emit(assign(r0336, add(r033A, r02E7), 0x02));

                     body.emit(assign(r0336, r02E8, 0x01));

                     body.emit(assign(r02EB, r0336, 0x03));

                     body.emit(assign(r02EA, body.constant(false), 0x01));


                  body.instructions = f0328_parent_instructions;
                  body.emit(f0328);

                  /* END IF */

                  body.emit(assign(r020F, r02EB, 0x03));

                  body.emit(assign(r020E, body.constant(false), 0x01));


               body.instructions = f02DC_parent_instructions;
               body.emit(f02DC);

               /* END IF */


            body.instructions = f02BB_parent_instructions;
            body.emit(f02BB);

            /* END IF */


         body.instructions = f0270_parent_instructions;
         body.emit(f0270);

         /* END IF */


      body.instructions = f0228_parent_instructions;
      body.emit(f0228);

      /* END IF */

      /* IF CONDITION */
      ir_if *f033B = new(mem_ctx) ir_if(operand(r020E).val);
      exec_list *const f033B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f033B->then_instructions;

         body.emit(assign(r0216, bit_or(r0216, body.constant(1048576u)), 0x01));

         ir_variable *const r033C = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r033D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r033D, add(r0217, r0215), 0x01));

         ir_expression *const r033E = add(r0216, r0214);
         ir_expression *const r033F = less(r033D, r0217);
         ir_expression *const r0340 = expr(ir_unop_b2i, r033F);
         ir_expression *const r0341 = expr(ir_unop_i2u, r0340);
         body.emit(assign(r033C, add(r033E, r0341), 0x01));

         body.emit(assign(r0211, r033C, 0x01));

         body.emit(assign(r0226, add(r0226, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r0343 = less(r033C, body.constant(2097152u));
         ir_if *f0342 = new(mem_ctx) ir_if(operand(r0343).val);
         exec_list *const f0342_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0342->then_instructions;

            ir_variable *const r0344 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0344, r0226, 0x01));

            ir_variable *const r0345 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0345, r033C, 0x01));

            ir_variable *const r0346 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0346, r033D, 0x01));

            ir_variable *const r0347 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0347, r0227, 0x01));

            ir_variable *const r0348 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0348, body.constant(true), 0x01));

            ir_variable *const r0349 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r034A = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r034A);
            ir_expression *const r034B = expr(ir_unop_u2i, r0227);
            body.emit(assign(r034A, less(r034B, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r034D = gequal(r0226, body.constant(int(2045)));
            ir_if *f034C = new(mem_ctx) ir_if(operand(r034D).val);
            exec_list *const f034C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f034C->then_instructions;

               /* IF CONDITION */
               ir_expression *const r034F = less(body.constant(int(2045)), r0226);
               ir_expression *const r0350 = equal(r0226, body.constant(int(2045)));
               ir_expression *const r0351 = equal(body.constant(2097151u), r033C);
               ir_expression *const r0352 = equal(body.constant(4294967295u), r033D);
               ir_expression *const r0353 = logic_and(r0351, r0352);
               ir_expression *const r0354 = logic_and(r0350, r0353);
               ir_expression *const r0355 = logic_and(r0354, r034A);
               ir_expression *const r0356 = logic_or(r034F, r0355);
               ir_if *f034E = new(mem_ctx) ir_if(operand(r0356).val);
               exec_list *const f034E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f034E->then_instructions;

                  ir_variable *const r0357 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0357);
                  ir_expression *const r0358 = lshift(r0219, body.constant(int(31)));
                  body.emit(assign(r0357, add(r0358, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0357, body.constant(0u), 0x01));

                  body.emit(assign(r0349, r0357, 0x03));

                  body.emit(assign(r0348, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f034E->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r035A = less(r0226, body.constant(int(0)));
                  ir_if *f0359 = new(mem_ctx) ir_if(operand(r035A).val);
                  exec_list *const f0359_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0359->then_instructions;

                     ir_variable *const r035B = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r035B, neg(r0226), 0x01));

                     ir_variable *const r035C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r035C);
                     ir_variable *const r035D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r035E = neg(r035B);
                     body.emit(assign(r035D, bit_and(r035E, body.constant(int(31))), 0x01));

                     ir_variable *const r035F = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0360 = less(r035B, body.constant(int(32)));
                     ir_expression *const r0361 = bit_or(r0227, r033D);
                     body.emit(assign(r035F, expr(ir_triop_csel, r0360, r0227, r0361), 0x01));

                     ir_expression *const r0362 = less(r035B, body.constant(int(32)));
                     ir_expression *const r0363 = lshift(r033D, r035D);
                     ir_expression *const r0364 = less(r035B, body.constant(int(64)));
                     ir_expression *const r0365 = lshift(r033C, r035D);
                     ir_expression *const r0366 = equal(r035B, body.constant(int(64)));
                     ir_expression *const r0367 = nequal(r033C, body.constant(0u));
                     ir_expression *const r0368 = expr(ir_unop_b2i, r0367);
                     ir_expression *const r0369 = expr(ir_unop_i2u, r0368);
                     ir_expression *const r036A = expr(ir_triop_csel, r0366, r033C, r0369);
                     ir_expression *const r036B = expr(ir_triop_csel, r0364, r0365, r036A);
                     ir_expression *const r036C = expr(ir_triop_csel, r0362, r0363, r036B);
                     ir_expression *const r036D = nequal(r035F, body.constant(0u));
                     ir_expression *const r036E = expr(ir_unop_b2i, r036D);
                     ir_expression *const r036F = expr(ir_unop_i2u, r036E);
                     body.emit(assign(r035C, bit_or(r036C, r036F), 0x01));

                     ir_variable *const r0370 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0371 = equal(r035B, body.constant(int(0)));
                     ir_expression *const r0372 = equal(r035B, body.constant(int(32)));
                     ir_expression *const r0373 = expr(ir_triop_csel, r0372, r033D, r035C);
                     body.emit(assign(r0370, expr(ir_triop_csel, r0371, r035F, r0373), 0x01));

                     body.emit(assign(r035C, r0370, 0x01));

                     ir_expression *const r0374 = equal(r035B, body.constant(int(0)));
                     ir_expression *const r0375 = equal(r035B, body.constant(int(32)));
                     ir_expression *const r0376 = less(r035B, body.constant(int(32)));
                     ir_expression *const r0377 = rshift(r033C, r035B);
                     ir_expression *const r0378 = expr(ir_triop_csel, r0376, r0377, body.constant(0u));
                     ir_expression *const r0379 = expr(ir_triop_csel, r0375, body.constant(0u), r0378);
                     body.emit(assign(r0345, expr(ir_triop_csel, r0374, r033C, r0379), 0x01));

                     ir_expression *const r037A = equal(r035B, body.constant(int(0)));
                     ir_expression *const r037B = equal(r035B, body.constant(int(32)));
                     ir_expression *const r037C = less(r035B, body.constant(int(32)));
                     ir_expression *const r037D = lshift(r033C, r035D);
                     ir_expression *const r037E = rshift(r033D, r035B);
                     ir_expression *const r037F = bit_or(r037D, r037E);
                     ir_expression *const r0380 = less(r035B, body.constant(int(64)));
                     ir_expression *const r0381 = bit_and(r035B, body.constant(int(31)));
                     ir_expression *const r0382 = rshift(r033C, r0381);
                     ir_expression *const r0383 = expr(ir_triop_csel, r0380, r0382, body.constant(0u));
                     ir_expression *const r0384 = expr(ir_triop_csel, r037C, r037F, r0383);
                     ir_expression *const r0385 = expr(ir_triop_csel, r037B, r033C, r0384);
                     body.emit(assign(r0346, expr(ir_triop_csel, r037A, r033D, r0385), 0x01));

                     body.emit(assign(r0347, r0370, 0x01));

                     body.emit(assign(r0344, body.constant(int(0)), 0x01));

                     body.emit(assign(r034A, less(r0370, body.constant(0u)), 0x01));


                  body.instructions = f0359_parent_instructions;
                  body.emit(f0359);

                  /* END IF */


               body.instructions = f034E_parent_instructions;
               body.emit(f034E);

               /* END IF */


            body.instructions = f034C_parent_instructions;
            body.emit(f034C);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0386 = new(mem_ctx) ir_if(operand(r0348).val);
            exec_list *const f0386_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0386->then_instructions;

               /* IF CONDITION */
               ir_if *f0387 = new(mem_ctx) ir_if(operand(r034A).val);
               exec_list *const f0387_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0387->then_instructions;

                  ir_variable *const r0388 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0388, add(r0346, body.constant(1u)), 0x01));

                  ir_expression *const r0389 = less(r0388, r0346);
                  ir_expression *const r038A = expr(ir_unop_b2i, r0389);
                  ir_expression *const r038B = expr(ir_unop_i2u, r038A);
                  body.emit(assign(r0345, add(r0345, r038B), 0x01));

                  ir_expression *const r038C = equal(r0347, body.constant(0u));
                  ir_expression *const r038D = expr(ir_unop_b2i, r038C);
                  ir_expression *const r038E = expr(ir_unop_i2u, r038D);
                  ir_expression *const r038F = add(r0347, r038E);
                  ir_expression *const r0390 = bit_and(r038F, body.constant(1u));
                  ir_expression *const r0391 = expr(ir_unop_bit_not, r0390);
                  body.emit(assign(r0346, bit_and(r0388, r0391), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0387->else_instructions;

                  ir_expression *const r0392 = bit_or(r0345, r0346);
                  ir_expression *const r0393 = equal(r0392, body.constant(0u));
                  body.emit(assign(r0344, expr(ir_triop_csel, r0393, body.constant(int(0)), r0344), 0x01));


               body.instructions = f0387_parent_instructions;
               body.emit(f0387);

               /* END IF */

               ir_variable *const r0394 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0394);
               ir_expression *const r0395 = lshift(r0219, body.constant(int(31)));
               ir_expression *const r0396 = expr(ir_unop_i2u, r0344);
               ir_expression *const r0397 = lshift(r0396, body.constant(int(20)));
               ir_expression *const r0398 = add(r0395, r0397);
               body.emit(assign(r0394, add(r0398, r0345), 0x02));

               body.emit(assign(r0394, r0346, 0x01));

               body.emit(assign(r0349, r0394, 0x03));

               body.emit(assign(r0348, body.constant(false), 0x01));


            body.instructions = f0386_parent_instructions;
            body.emit(f0386);

            /* END IF */

            body.emit(assign(r020F, r0349, 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0342->else_instructions;

            body.emit(assign(r0226, add(r0226, body.constant(int(1))), 0x01));

            ir_variable *const r0399 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r039A = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_variable *const r039B = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r039C = lshift(r033D, body.constant(int(31)));
            ir_expression *const r039D = nequal(r0227, body.constant(0u));
            ir_expression *const r039E = expr(ir_unop_b2i, r039D);
            ir_expression *const r039F = expr(ir_unop_i2u, r039E);
            body.emit(assign(r039B, bit_or(r039C, r039F), 0x01));

            ir_expression *const r03A0 = lshift(r033C, body.constant(int(31)));
            ir_expression *const r03A1 = rshift(r033D, body.constant(int(1)));
            body.emit(assign(r039A, bit_or(r03A0, r03A1), 0x01));

            body.emit(assign(r0399, rshift(r033C, body.constant(int(1))), 0x01));

            body.emit(assign(r0211, r0399, 0x01));

            body.emit(assign(r0227, r039B, 0x01));

            ir_variable *const r03A2 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03A2, r0226, 0x01));

            ir_variable *const r03A3 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03A3, r0399, 0x01));

            ir_variable *const r03A4 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03A4, r039A, 0x01));

            ir_variable *const r03A5 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r03A5, r039B, 0x01));

            ir_variable *const r03A6 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r03A6, body.constant(true), 0x01));

            ir_variable *const r03A7 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r03A8 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r03A8);
            ir_expression *const r03A9 = expr(ir_unop_u2i, r039B);
            body.emit(assign(r03A8, less(r03A9, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03AB = gequal(r0226, body.constant(int(2045)));
            ir_if *f03AA = new(mem_ctx) ir_if(operand(r03AB).val);
            exec_list *const f03AA_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03AA->then_instructions;

               /* IF CONDITION */
               ir_expression *const r03AD = less(body.constant(int(2045)), r0226);
               ir_expression *const r03AE = equal(r0226, body.constant(int(2045)));
               ir_expression *const r03AF = equal(body.constant(2097151u), r0399);
               ir_expression *const r03B0 = equal(body.constant(4294967295u), r039A);
               ir_expression *const r03B1 = logic_and(r03AF, r03B0);
               ir_expression *const r03B2 = logic_and(r03AE, r03B1);
               ir_expression *const r03B3 = logic_and(r03B2, r03A8);
               ir_expression *const r03B4 = logic_or(r03AD, r03B3);
               ir_if *f03AC = new(mem_ctx) ir_if(operand(r03B4).val);
               exec_list *const f03AC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03AC->then_instructions;

                  ir_variable *const r03B5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r03B5);
                  ir_expression *const r03B6 = lshift(r0219, body.constant(int(31)));
                  body.emit(assign(r03B5, add(r03B6, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r03B5, body.constant(0u), 0x01));

                  body.emit(assign(r03A7, r03B5, 0x03));

                  body.emit(assign(r03A6, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03AC->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03B8 = less(r0226, body.constant(int(0)));
                  ir_if *f03B7 = new(mem_ctx) ir_if(operand(r03B8).val);
                  exec_list *const f03B7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03B7->then_instructions;

                     ir_variable *const r03B9 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r03B9, neg(r0226), 0x01));

                     ir_variable *const r03BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r03BA);
                     ir_variable *const r03BB = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r03BC = neg(r03B9);
                     body.emit(assign(r03BB, bit_and(r03BC, body.constant(int(31))), 0x01));

                     ir_variable *const r03BD = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r03BE = less(r03B9, body.constant(int(32)));
                     ir_expression *const r03BF = bit_or(r039B, r039A);
                     body.emit(assign(r03BD, expr(ir_triop_csel, r03BE, r039B, r03BF), 0x01));

                     ir_expression *const r03C0 = less(r03B9, body.constant(int(32)));
                     ir_expression *const r03C1 = lshift(r039A, r03BB);
                     ir_expression *const r03C2 = less(r03B9, body.constant(int(64)));
                     ir_expression *const r03C3 = lshift(r0399, r03BB);
                     ir_expression *const r03C4 = equal(r03B9, body.constant(int(64)));
                     ir_expression *const r03C5 = nequal(r0399, body.constant(0u));
                     ir_expression *const r03C6 = expr(ir_unop_b2i, r03C5);
                     ir_expression *const r03C7 = expr(ir_unop_i2u, r03C6);
                     ir_expression *const r03C8 = expr(ir_triop_csel, r03C4, r0399, r03C7);
                     ir_expression *const r03C9 = expr(ir_triop_csel, r03C2, r03C3, r03C8);
                     ir_expression *const r03CA = expr(ir_triop_csel, r03C0, r03C1, r03C9);
                     ir_expression *const r03CB = nequal(r03BD, body.constant(0u));
                     ir_expression *const r03CC = expr(ir_unop_b2i, r03CB);
                     ir_expression *const r03CD = expr(ir_unop_i2u, r03CC);
                     body.emit(assign(r03BA, bit_or(r03CA, r03CD), 0x01));

                     ir_variable *const r03CE = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r03CF = equal(r03B9, body.constant(int(0)));
                     ir_expression *const r03D0 = equal(r03B9, body.constant(int(32)));
                     ir_expression *const r03D1 = expr(ir_triop_csel, r03D0, r039A, r03BA);
                     body.emit(assign(r03CE, expr(ir_triop_csel, r03CF, r03BD, r03D1), 0x01));

                     body.emit(assign(r03BA, r03CE, 0x01));

                     ir_expression *const r03D2 = equal(r03B9, body.constant(int(0)));
                     ir_expression *const r03D3 = equal(r03B9, body.constant(int(32)));
                     ir_expression *const r03D4 = less(r03B9, body.constant(int(32)));
                     ir_expression *const r03D5 = rshift(r0399, r03B9);
                     ir_expression *const r03D6 = expr(ir_triop_csel, r03D4, r03D5, body.constant(0u));
                     ir_expression *const r03D7 = expr(ir_triop_csel, r03D3, body.constant(0u), r03D6);
                     body.emit(assign(r03A3, expr(ir_triop_csel, r03D2, r0399, r03D7), 0x01));

                     ir_expression *const r03D8 = equal(r03B9, body.constant(int(0)));
                     ir_expression *const r03D9 = equal(r03B9, body.constant(int(32)));
                     ir_expression *const r03DA = less(r03B9, body.constant(int(32)));
                     ir_expression *const r03DB = lshift(r0399, r03BB);
                     ir_expression *const r03DC = rshift(r039A, r03B9);
                     ir_expression *const r03DD = bit_or(r03DB, r03DC);
                     ir_expression *const r03DE = less(r03B9, body.constant(int(64)));
                     ir_expression *const r03DF = bit_and(r03B9, body.constant(int(31)));
                     ir_expression *const r03E0 = rshift(r0399, r03DF);
                     ir_expression *const r03E1 = expr(ir_triop_csel, r03DE, r03E0, body.constant(0u));
                     ir_expression *const r03E2 = expr(ir_triop_csel, r03DA, r03DD, r03E1);
                     ir_expression *const r03E3 = expr(ir_triop_csel, r03D9, r0399, r03E2);
                     body.emit(assign(r03A4, expr(ir_triop_csel, r03D8, r039A, r03E3), 0x01));

                     body.emit(assign(r03A5, r03CE, 0x01));

                     body.emit(assign(r03A2, body.constant(int(0)), 0x01));

                     body.emit(assign(r03A8, less(r03CE, body.constant(0u)), 0x01));


                  body.instructions = f03B7_parent_instructions;
                  body.emit(f03B7);

                  /* END IF */


               body.instructions = f03AC_parent_instructions;
               body.emit(f03AC);

               /* END IF */


            body.instructions = f03AA_parent_instructions;
            body.emit(f03AA);

            /* END IF */

            /* IF CONDITION */
            ir_if *f03E4 = new(mem_ctx) ir_if(operand(r03A6).val);
            exec_list *const f03E4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03E4->then_instructions;

               /* IF CONDITION */
               ir_if *f03E5 = new(mem_ctx) ir_if(operand(r03A8).val);
               exec_list *const f03E5_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E5->then_instructions;

                  ir_variable *const r03E6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r03E6, add(r03A4, body.constant(1u)), 0x01));

                  ir_expression *const r03E7 = less(r03E6, r03A4);
                  ir_expression *const r03E8 = expr(ir_unop_b2i, r03E7);
                  ir_expression *const r03E9 = expr(ir_unop_i2u, r03E8);
                  body.emit(assign(r03A3, add(r03A3, r03E9), 0x01));

                  ir_expression *const r03EA = equal(r03A5, body.constant(0u));
                  ir_expression *const r03EB = expr(ir_unop_b2i, r03EA);
                  ir_expression *const r03EC = expr(ir_unop_i2u, r03EB);
                  ir_expression *const r03ED = add(r03A5, r03EC);
                  ir_expression *const r03EE = bit_and(r03ED, body.constant(1u));
                  ir_expression *const r03EF = expr(ir_unop_bit_not, r03EE);
                  body.emit(assign(r03A4, bit_and(r03E6, r03EF), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03E5->else_instructions;

                  ir_expression *const r03F0 = bit_or(r03A3, r03A4);
                  ir_expression *const r03F1 = equal(r03F0, body.constant(0u));
                  body.emit(assign(r03A2, expr(ir_triop_csel, r03F1, body.constant(int(0)), r03A2), 0x01));


               body.instructions = f03E5_parent_instructions;
               body.emit(f03E5);

               /* END IF */

               ir_variable *const r03F2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r03F2);
               ir_expression *const r03F3 = lshift(r0219, body.constant(int(31)));
               ir_expression *const r03F4 = expr(ir_unop_i2u, r03A2);
               ir_expression *const r03F5 = lshift(r03F4, body.constant(int(20)));
               ir_expression *const r03F6 = add(r03F3, r03F5);
               body.emit(assign(r03F2, add(r03F6, r03A3), 0x02));

               body.emit(assign(r03F2, r03A4, 0x01));

               body.emit(assign(r03A7, r03F2, 0x03));

               body.emit(assign(r03A6, body.constant(false), 0x01));


            body.instructions = f03E4_parent_instructions;
            body.emit(f03E4);

            /* END IF */

            body.emit(assign(r020F, r03A7, 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


         body.instructions = f0342_parent_instructions;
         body.emit(f0342);

         /* END IF */


      body.instructions = f033B_parent_instructions;
      body.emit(f033B);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0224->else_instructions;

      ir_variable *const r03F7 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r03F7);
      ir_variable *const r03F8 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r03F9 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r03F9, lshift(r0217, body.constant(int(10))), 0x01));

      ir_expression *const r03FA = lshift(r0216, body.constant(int(10)));
      ir_expression *const r03FB = rshift(r0217, body.constant(int(22)));
      body.emit(assign(r03F8, bit_or(r03FA, r03FB), 0x01));

      body.emit(assign(r0216, r03F8, 0x01));

      body.emit(assign(r0217, r03F9, 0x01));

      ir_variable *const r03FC = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r03FD = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r03FD, lshift(r0215, body.constant(int(10))), 0x01));

      ir_expression *const r03FE = lshift(r0214, body.constant(int(10)));
      ir_expression *const r03FF = rshift(r0215, body.constant(int(22)));
      body.emit(assign(r03FC, bit_or(r03FE, r03FF), 0x01));

      body.emit(assign(r0214, r03FC, 0x01));

      body.emit(assign(r0215, r03FD, 0x01));

      /* IF CONDITION */
      ir_expression *const r0401 = less(body.constant(int(0)), r0210);
      ir_if *f0400 = new(mem_ctx) ir_if(operand(r0401).val);
      exec_list *const f0400_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0400->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0403 = equal(r021D, body.constant(int(2047)));
         ir_if *f0402 = new(mem_ctx) ir_if(operand(r0403).val);
         exec_list *const f0402_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0402->then_instructions;

            ir_variable *const r0404 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0404, swizzle_x(r020C), 0x01));

            ir_variable *const r0405 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0405, swizzle_x(r020D), 0x01));

            body.emit(assign(r0404, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

            body.emit(assign(r0405, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

            ir_expression *const r0406 = bit_or(r03F8, r03F9);
            ir_expression *const r0407 = nequal(r0406, body.constant(0u));
            ir_swizzle *const r0408 = swizzle(r0407, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0409 = lshift(swizzle_y(r020C), body.constant(int(1)));
            ir_expression *const r040A = gequal(r0409, body.constant(4292870144u));
            ir_expression *const r040B = nequal(swizzle_x(r020C), body.constant(0u));
            ir_expression *const r040C = bit_and(swizzle_y(r020C), body.constant(1048575u));
            ir_expression *const r040D = nequal(r040C, body.constant(0u));
            ir_expression *const r040E = logic_or(r040B, r040D);
            ir_expression *const r040F = logic_and(r040A, r040E);
            ir_swizzle *const r0410 = swizzle(r040F, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0411 = lshift(swizzle_y(r020D), body.constant(int(1)));
            ir_expression *const r0412 = gequal(r0411, body.constant(4292870144u));
            ir_expression *const r0413 = nequal(swizzle_x(r020D), body.constant(0u));
            ir_expression *const r0414 = bit_and(swizzle_y(r020D), body.constant(1048575u));
            ir_expression *const r0415 = nequal(r0414, body.constant(0u));
            ir_expression *const r0416 = logic_or(r0413, r0415);
            ir_expression *const r0417 = logic_and(r0412, r0416);
            ir_swizzle *const r0418 = swizzle(r0417, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0419 = expr(ir_triop_csel, r0418, r0405, r0404);
            ir_expression *const r041A = expr(ir_triop_csel, r0410, r0419, r0405);
            body.emit(assign(r020F, expr(ir_triop_csel, r0408, r041A, r020C), 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0402->else_instructions;

            /* IF CONDITION */
            ir_expression *const r041C = equal(r0220, body.constant(int(0)));
            ir_if *f041B = new(mem_ctx) ir_if(operand(r041C).val);
            exec_list *const f041B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f041B->then_instructions;

               body.emit(assign(r0210, add(r0210, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f041B->else_instructions;

               body.emit(assign(r0214, bit_or(r03FC, body.constant(1073741824u)), 0x01));


            body.instructions = f041B_parent_instructions;
            body.emit(f041B);

            /* END IF */

            ir_variable *const r041D = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r041E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r041E);
            ir_variable *const r041F = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0420 = neg(r0210);
            body.emit(assign(r041F, bit_and(r0420, body.constant(int(31))), 0x01));

            ir_expression *const r0421 = bit_or(r0214, r03FD);
            ir_expression *const r0422 = nequal(r0421, body.constant(0u));
            ir_expression *const r0423 = expr(ir_unop_b2i, r0422);
            body.emit(assign(r041E, expr(ir_unop_i2u, r0423), 0x01));

            ir_variable *const r0424 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0425 = equal(r0210, body.constant(int(0)));
            ir_expression *const r0426 = less(r0210, body.constant(int(32)));
            ir_expression *const r0427 = lshift(r0214, r041F);
            ir_expression *const r0428 = rshift(r03FD, r0210);
            ir_expression *const r0429 = bit_or(r0427, r0428);
            ir_expression *const r042A = lshift(r03FD, r041F);
            ir_expression *const r042B = nequal(r042A, body.constant(0u));
            ir_expression *const r042C = expr(ir_unop_b2i, r042B);
            ir_expression *const r042D = expr(ir_unop_i2u, r042C);
            ir_expression *const r042E = bit_or(r0429, r042D);
            ir_expression *const r042F = equal(r0210, body.constant(int(32)));
            ir_expression *const r0430 = nequal(r03FD, body.constant(0u));
            ir_expression *const r0431 = expr(ir_unop_b2i, r0430);
            ir_expression *const r0432 = expr(ir_unop_i2u, r0431);
            ir_expression *const r0433 = bit_or(r0214, r0432);
            ir_expression *const r0434 = less(r0210, body.constant(int(64)));
            ir_expression *const r0435 = bit_and(r0210, body.constant(int(31)));
            ir_expression *const r0436 = rshift(r0214, r0435);
            ir_expression *const r0437 = lshift(r0214, r041F);
            ir_expression *const r0438 = bit_or(r0437, r03FD);
            ir_expression *const r0439 = nequal(r0438, body.constant(0u));
            ir_expression *const r043A = expr(ir_unop_b2i, r0439);
            ir_expression *const r043B = expr(ir_unop_i2u, r043A);
            ir_expression *const r043C = bit_or(r0436, r043B);
            ir_expression *const r043D = expr(ir_triop_csel, r0434, r043C, r041E);
            ir_expression *const r043E = expr(ir_triop_csel, r042F, r0433, r043D);
            ir_expression *const r043F = expr(ir_triop_csel, r0426, r042E, r043E);
            body.emit(assign(r0424, expr(ir_triop_csel, r0425, r03FD, r043F), 0x01));

            body.emit(assign(r041E, r0424, 0x01));

            ir_expression *const r0440 = less(r0210, body.constant(int(32)));
            ir_expression *const r0441 = rshift(r0214, r0210);
            ir_expression *const r0442 = equal(r0210, body.constant(int(0)));
            ir_expression *const r0443 = expr(ir_triop_csel, r0442, r0214, body.constant(0u));
            body.emit(assign(r041D, expr(ir_triop_csel, r0440, r0441, r0443), 0x01));

            body.emit(assign(r0214, r041D, 0x01));

            body.emit(assign(r0215, r0424, 0x01));

            body.emit(assign(r0216, bit_or(r03F8, body.constant(1073741824u)), 0x01));

            ir_variable *const r0444 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_expression *const r0445 = sub(r0216, r041D);
            ir_expression *const r0446 = less(r03F9, r0424);
            ir_expression *const r0447 = expr(ir_unop_b2i, r0446);
            ir_expression *const r0448 = expr(ir_unop_i2u, r0447);
            body.emit(assign(r0444, sub(r0445, r0448), 0x01));

            body.emit(assign(r0211, r0444, 0x01));

            body.emit(assign(r03F7, add(r021D, body.constant(int(-1))), 0x01));

            ir_variable *const r0449 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0449, add(r03F7, body.constant(int(-10))), 0x01));

            ir_variable *const r044A = body.make_temp(glsl_type::uint_type, "zFrac0");
            ir_variable *const r044B = body.make_temp(glsl_type::uint_type, "zFrac1");
            ir_variable *const r044C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r044C);
            ir_variable *const r044D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r044D);
            ir_expression *const r044E = equal(r0444, body.constant(0u));
            ir_expression *const r044F = add(r0449, body.constant(int(-32)));
            body.emit(assign(r0449, expr(ir_triop_csel, r044E, r044F, r0449), 0x01));

            ir_variable *const r0450 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0451 = equal(r0444, body.constant(0u));
            ir_expression *const r0452 = sub(r03F9, r0424);
            body.emit(assign(r0450, expr(ir_triop_csel, r0451, body.constant(0u), r0452), 0x01));

            body.emit(assign(r044B, r0450, 0x01));

            ir_variable *const r0453 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0454 = equal(r0444, body.constant(0u));
            body.emit(assign(r0453, expr(ir_triop_csel, r0454, r0450, r0444), 0x01));

            body.emit(assign(r044A, r0453, 0x01));

            ir_expression *const r0455 = equal(r0453, body.constant(0u));
            ir_expression *const r0456 = expr(ir_unop_find_msb, r0453);
            ir_expression *const r0457 = sub(body.constant(int(31)), r0456);
            ir_expression *const r0458 = expr(ir_triop_csel, r0455, body.constant(int(32)), r0457);
            body.emit(assign(r044D, add(r0458, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r045A = gequal(r044D, body.constant(int(0)));
            ir_if *f0459 = new(mem_ctx) ir_if(operand(r045A).val);
            exec_list *const f0459_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0459->then_instructions;

               body.emit(assign(r044C, body.constant(0u), 0x01));

               ir_expression *const r045B = equal(r044D, body.constant(int(0)));
               ir_expression *const r045C = lshift(r0453, r044D);
               ir_expression *const r045D = neg(r044D);
               ir_expression *const r045E = bit_and(r045D, body.constant(int(31)));
               ir_expression *const r045F = rshift(r0450, r045E);
               ir_expression *const r0460 = bit_or(r045C, r045F);
               body.emit(assign(r044A, expr(ir_triop_csel, r045B, r0453, r0460), 0x01));

               body.emit(assign(r044B, lshift(r0450, r044D), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0459->else_instructions;

               ir_variable *const r0461 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0461, neg(r044D), 0x01));

               ir_variable *const r0462 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               ir_variable *const r0463 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0463);
               ir_variable *const r0464 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0465 = neg(r0461);
               body.emit(assign(r0464, bit_and(r0465, body.constant(int(31))), 0x01));

               ir_variable *const r0466 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0467 = less(r0461, body.constant(int(32)));
               ir_expression *const r0468 = bit_or(body.constant(0u), r044B);
               body.emit(assign(r0466, expr(ir_triop_csel, r0467, body.constant(0u), r0468), 0x01));

               ir_expression *const r0469 = less(r0461, body.constant(int(32)));
               ir_expression *const r046A = lshift(r044B, r0464);
               ir_expression *const r046B = less(r0461, body.constant(int(64)));
               ir_expression *const r046C = lshift(r044A, r0464);
               ir_expression *const r046D = equal(r0461, body.constant(int(64)));
               ir_expression *const r046E = nequal(r044A, body.constant(0u));
               ir_expression *const r046F = expr(ir_unop_b2i, r046E);
               ir_expression *const r0470 = expr(ir_unop_i2u, r046F);
               ir_expression *const r0471 = expr(ir_triop_csel, r046D, r044A, r0470);
               ir_expression *const r0472 = expr(ir_triop_csel, r046B, r046C, r0471);
               ir_expression *const r0473 = expr(ir_triop_csel, r0469, r046A, r0472);
               ir_expression *const r0474 = nequal(r0466, body.constant(0u));
               ir_expression *const r0475 = expr(ir_unop_b2i, r0474);
               ir_expression *const r0476 = expr(ir_unop_i2u, r0475);
               body.emit(assign(r0463, bit_or(r0473, r0476), 0x01));

               ir_variable *const r0477 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0478 = equal(r0461, body.constant(int(0)));
               ir_expression *const r0479 = equal(r0461, body.constant(int(32)));
               ir_expression *const r047A = expr(ir_triop_csel, r0479, r044B, r0463);
               body.emit(assign(r0477, expr(ir_triop_csel, r0478, r0466, r047A), 0x01));

               body.emit(assign(r0463, r0477, 0x01));

               ir_expression *const r047B = equal(r0461, body.constant(int(0)));
               ir_expression *const r047C = equal(r0461, body.constant(int(32)));
               ir_expression *const r047D = less(r0461, body.constant(int(32)));
               ir_expression *const r047E = lshift(r044A, r0464);
               ir_expression *const r047F = rshift(r044B, r0461);
               ir_expression *const r0480 = bit_or(r047E, r047F);
               ir_expression *const r0481 = less(r0461, body.constant(int(64)));
               ir_expression *const r0482 = bit_and(r0461, body.constant(int(31)));
               ir_expression *const r0483 = rshift(r044A, r0482);
               ir_expression *const r0484 = expr(ir_triop_csel, r0481, r0483, body.constant(0u));
               ir_expression *const r0485 = expr(ir_triop_csel, r047D, r0480, r0484);
               ir_expression *const r0486 = expr(ir_triop_csel, r047C, r044A, r0485);
               body.emit(assign(r0462, expr(ir_triop_csel, r047B, r044B, r0486), 0x01));

               ir_expression *const r0487 = equal(r0461, body.constant(int(0)));
               ir_expression *const r0488 = equal(r0461, body.constant(int(32)));
               ir_expression *const r0489 = less(r0461, body.constant(int(32)));
               ir_expression *const r048A = rshift(r044A, r0461);
               ir_expression *const r048B = expr(ir_triop_csel, r0489, r048A, body.constant(0u));
               ir_expression *const r048C = expr(ir_triop_csel, r0488, body.constant(0u), r048B);
               body.emit(assign(r044A, expr(ir_triop_csel, r0487, r044A, r048C), 0x01));

               body.emit(assign(r044B, r0462, 0x01));

               body.emit(assign(r044C, r0477, 0x01));


            body.instructions = f0459_parent_instructions;
            body.emit(f0459);

            /* END IF */

            body.emit(assign(r0449, sub(r0449, r044D), 0x01));

            ir_variable *const r048D = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r048D, r0449, 0x01));

            ir_variable *const r048E = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r048E, r044A, 0x01));

            ir_variable *const r048F = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r048F, r044B, 0x01));

            ir_variable *const r0490 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0490, r044C, 0x01));

            ir_variable *const r0491 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0491, body.constant(true), 0x01));

            ir_variable *const r0492 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0493 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0493);
            ir_expression *const r0494 = expr(ir_unop_u2i, r044C);
            body.emit(assign(r0493, less(r0494, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0496 = gequal(r0449, body.constant(int(2045)));
            ir_if *f0495 = new(mem_ctx) ir_if(operand(r0496).val);
            exec_list *const f0495_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0495->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0498 = less(body.constant(int(2045)), r0449);
               ir_expression *const r0499 = equal(r0449, body.constant(int(2045)));
               ir_expression *const r049A = equal(body.constant(2097151u), r044A);
               ir_expression *const r049B = equal(body.constant(4294967295u), r044B);
               ir_expression *const r049C = logic_and(r049A, r049B);
               ir_expression *const r049D = logic_and(r0499, r049C);
               ir_expression *const r049E = logic_and(r049D, r0493);
               ir_expression *const r049F = logic_or(r0498, r049E);
               ir_if *f0497 = new(mem_ctx) ir_if(operand(r049F).val);
               exec_list *const f0497_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0497->then_instructions;

                  ir_variable *const r04A0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r04A0);
                  ir_expression *const r04A1 = lshift(r0219, body.constant(int(31)));
                  body.emit(assign(r04A0, add(r04A1, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r04A0, body.constant(0u), 0x01));

                  body.emit(assign(r0492, r04A0, 0x03));

                  body.emit(assign(r0491, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0497->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04A3 = less(r0449, body.constant(int(0)));
                  ir_if *f04A2 = new(mem_ctx) ir_if(operand(r04A3).val);
                  exec_list *const f04A2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A2->then_instructions;

                     ir_variable *const r04A4 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r04A4, neg(r0449), 0x01));

                     ir_variable *const r04A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r04A5);
                     ir_variable *const r04A6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r04A7 = neg(r04A4);
                     body.emit(assign(r04A6, bit_and(r04A7, body.constant(int(31))), 0x01));

                     ir_variable *const r04A8 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r04A9 = less(r04A4, body.constant(int(32)));
                     ir_expression *const r04AA = bit_or(r044C, r044B);
                     body.emit(assign(r04A8, expr(ir_triop_csel, r04A9, r044C, r04AA), 0x01));

                     ir_expression *const r04AB = less(r04A4, body.constant(int(32)));
                     ir_expression *const r04AC = lshift(r044B, r04A6);
                     ir_expression *const r04AD = less(r04A4, body.constant(int(64)));
                     ir_expression *const r04AE = lshift(r044A, r04A6);
                     ir_expression *const r04AF = equal(r04A4, body.constant(int(64)));
                     ir_expression *const r04B0 = nequal(r044A, body.constant(0u));
                     ir_expression *const r04B1 = expr(ir_unop_b2i, r04B0);
                     ir_expression *const r04B2 = expr(ir_unop_i2u, r04B1);
                     ir_expression *const r04B3 = expr(ir_triop_csel, r04AF, r044A, r04B2);
                     ir_expression *const r04B4 = expr(ir_triop_csel, r04AD, r04AE, r04B3);
                     ir_expression *const r04B5 = expr(ir_triop_csel, r04AB, r04AC, r04B4);
                     ir_expression *const r04B6 = nequal(r04A8, body.constant(0u));
                     ir_expression *const r04B7 = expr(ir_unop_b2i, r04B6);
                     ir_expression *const r04B8 = expr(ir_unop_i2u, r04B7);
                     body.emit(assign(r04A5, bit_or(r04B5, r04B8), 0x01));

                     ir_variable *const r04B9 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r04BA = equal(r04A4, body.constant(int(0)));
                     ir_expression *const r04BB = equal(r04A4, body.constant(int(32)));
                     ir_expression *const r04BC = expr(ir_triop_csel, r04BB, r044B, r04A5);
                     body.emit(assign(r04B9, expr(ir_triop_csel, r04BA, r04A8, r04BC), 0x01));

                     body.emit(assign(r04A5, r04B9, 0x01));

                     ir_expression *const r04BD = equal(r04A4, body.constant(int(0)));
                     ir_expression *const r04BE = equal(r04A4, body.constant(int(32)));
                     ir_expression *const r04BF = less(r04A4, body.constant(int(32)));
                     ir_expression *const r04C0 = rshift(r044A, r04A4);
                     ir_expression *const r04C1 = expr(ir_triop_csel, r04BF, r04C0, body.constant(0u));
                     ir_expression *const r04C2 = expr(ir_triop_csel, r04BE, body.constant(0u), r04C1);
                     body.emit(assign(r048E, expr(ir_triop_csel, r04BD, r044A, r04C2), 0x01));

                     ir_expression *const r04C3 = equal(r04A4, body.constant(int(0)));
                     ir_expression *const r04C4 = equal(r04A4, body.constant(int(32)));
                     ir_expression *const r04C5 = less(r04A4, body.constant(int(32)));
                     ir_expression *const r04C6 = lshift(r044A, r04A6);
                     ir_expression *const r04C7 = rshift(r044B, r04A4);
                     ir_expression *const r04C8 = bit_or(r04C6, r04C7);
                     ir_expression *const r04C9 = less(r04A4, body.constant(int(64)));
                     ir_expression *const r04CA = bit_and(r04A4, body.constant(int(31)));
                     ir_expression *const r04CB = rshift(r044A, r04CA);
                     ir_expression *const r04CC = expr(ir_triop_csel, r04C9, r04CB, body.constant(0u));
                     ir_expression *const r04CD = expr(ir_triop_csel, r04C5, r04C8, r04CC);
                     ir_expression *const r04CE = expr(ir_triop_csel, r04C4, r044A, r04CD);
                     body.emit(assign(r048F, expr(ir_triop_csel, r04C3, r044B, r04CE), 0x01));

                     body.emit(assign(r0490, r04B9, 0x01));

                     body.emit(assign(r048D, body.constant(int(0)), 0x01));

                     body.emit(assign(r0493, less(r04B9, body.constant(0u)), 0x01));


                  body.instructions = f04A2_parent_instructions;
                  body.emit(f04A2);

                  /* END IF */


               body.instructions = f0497_parent_instructions;
               body.emit(f0497);

               /* END IF */


            body.instructions = f0495_parent_instructions;
            body.emit(f0495);

            /* END IF */

            /* IF CONDITION */
            ir_if *f04CF = new(mem_ctx) ir_if(operand(r0491).val);
            exec_list *const f04CF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f04CF->then_instructions;

               /* IF CONDITION */
               ir_if *f04D0 = new(mem_ctx) ir_if(operand(r0493).val);
               exec_list *const f04D0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04D0->then_instructions;

                  ir_variable *const r04D1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r04D1, add(r048F, body.constant(1u)), 0x01));

                  ir_expression *const r04D2 = less(r04D1, r048F);
                  ir_expression *const r04D3 = expr(ir_unop_b2i, r04D2);
                  ir_expression *const r04D4 = expr(ir_unop_i2u, r04D3);
                  body.emit(assign(r048E, add(r048E, r04D4), 0x01));

                  ir_expression *const r04D5 = equal(r0490, body.constant(0u));
                  ir_expression *const r04D6 = expr(ir_unop_b2i, r04D5);
                  ir_expression *const r04D7 = expr(ir_unop_i2u, r04D6);
                  ir_expression *const r04D8 = add(r0490, r04D7);
                  ir_expression *const r04D9 = bit_and(r04D8, body.constant(1u));
                  ir_expression *const r04DA = expr(ir_unop_bit_not, r04D9);
                  body.emit(assign(r048F, bit_and(r04D1, r04DA), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04D0->else_instructions;

                  ir_expression *const r04DB = bit_or(r048E, r048F);
                  ir_expression *const r04DC = equal(r04DB, body.constant(0u));
                  body.emit(assign(r048D, expr(ir_triop_csel, r04DC, body.constant(int(0)), r048D), 0x01));


               body.instructions = f04D0_parent_instructions;
               body.emit(f04D0);

               /* END IF */

               ir_variable *const r04DD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r04DD);
               ir_expression *const r04DE = lshift(r0219, body.constant(int(31)));
               ir_expression *const r04DF = expr(ir_unop_i2u, r048D);
               ir_expression *const r04E0 = lshift(r04DF, body.constant(int(20)));
               ir_expression *const r04E1 = add(r04DE, r04E0);
               body.emit(assign(r04DD, add(r04E1, r048E), 0x02));

               body.emit(assign(r04DD, r048F, 0x01));

               body.emit(assign(r0492, r04DD, 0x03));

               body.emit(assign(r0491, body.constant(false), 0x01));


            body.instructions = f04CF_parent_instructions;
            body.emit(f04CF);

            /* END IF */

            body.emit(assign(r020F, r0492, 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


         body.instructions = f0402_parent_instructions;
         body.emit(f0402);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0400->else_instructions;

         /* IF CONDITION */
         ir_expression *const r04E3 = less(r0210, body.constant(int(0)));
         ir_if *f04E2 = new(mem_ctx) ir_if(operand(r04E3).val);
         exec_list *const f04E2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f04E2->then_instructions;

            /* IF CONDITION */
            ir_expression *const r04E5 = equal(r0220, body.constant(int(2047)));
            ir_if *f04E4 = new(mem_ctx) ir_if(operand(r04E5).val);
            exec_list *const f04E4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f04E4->then_instructions;

               ir_variable *const r04E6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r04E6);
               ir_expression *const r04E7 = bit_xor(r0219, body.constant(1u));
               ir_expression *const r04E8 = lshift(r04E7, body.constant(int(31)));
               body.emit(assign(r04E6, add(r04E8, body.constant(2146435072u)), 0x02));

               body.emit(assign(r04E6, body.constant(0u), 0x01));

               ir_variable *const r04E9 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r04E9, swizzle_x(r020C), 0x01));

               ir_variable *const r04EA = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r04EA, swizzle_x(r020D), 0x01));

               body.emit(assign(r04E9, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r04EA, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r04EB = bit_or(r0214, r0215);
               ir_expression *const r04EC = nequal(r04EB, body.constant(0u));
               ir_swizzle *const r04ED = swizzle(r04EC, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r04EE = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r04EF = gequal(r04EE, body.constant(4292870144u));
               ir_expression *const r04F0 = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r04F1 = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r04F2 = nequal(r04F1, body.constant(0u));
               ir_expression *const r04F3 = logic_or(r04F0, r04F2);
               ir_expression *const r04F4 = logic_and(r04EF, r04F3);
               ir_swizzle *const r04F5 = swizzle(r04F4, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r04F6 = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r04F7 = gequal(r04F6, body.constant(4292870144u));
               ir_expression *const r04F8 = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r04F9 = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r04FA = nequal(r04F9, body.constant(0u));
               ir_expression *const r04FB = logic_or(r04F8, r04FA);
               ir_expression *const r04FC = logic_and(r04F7, r04FB);
               ir_swizzle *const r04FD = swizzle(r04FC, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r04FE = expr(ir_triop_csel, r04FD, r04EA, r04E9);
               ir_expression *const r04FF = expr(ir_triop_csel, r04F5, r04FE, r04EA);
               body.emit(assign(r020F, expr(ir_triop_csel, r04ED, r04FF, r04E6), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f04E4->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0501 = equal(r021D, body.constant(int(0)));
               ir_if *f0500 = new(mem_ctx) ir_if(operand(r0501).val);
               exec_list *const f0500_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0500->then_instructions;

                  body.emit(assign(r0210, add(r0210, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0500->else_instructions;

                  body.emit(assign(r0216, bit_or(r0216, body.constant(1073741824u)), 0x01));


               body.instructions = f0500_parent_instructions;
               body.emit(f0500);

               /* END IF */

               ir_variable *const r0502 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0502, neg(r0210), 0x01));

               ir_variable *const r0503 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0504 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0504);
               ir_variable *const r0505 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0506 = neg(r0502);
               body.emit(assign(r0505, bit_and(r0506, body.constant(int(31))), 0x01));

               ir_expression *const r0507 = bit_or(r0216, r03F9);
               ir_expression *const r0508 = nequal(r0507, body.constant(0u));
               ir_expression *const r0509 = expr(ir_unop_b2i, r0508);
               body.emit(assign(r0504, expr(ir_unop_i2u, r0509), 0x01));

               ir_variable *const r050A = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r050B = equal(r0502, body.constant(int(0)));
               ir_expression *const r050C = less(r0502, body.constant(int(32)));
               ir_expression *const r050D = lshift(r0216, r0505);
               ir_expression *const r050E = rshift(r03F9, r0502);
               ir_expression *const r050F = bit_or(r050D, r050E);
               ir_expression *const r0510 = lshift(r03F9, r0505);
               ir_expression *const r0511 = nequal(r0510, body.constant(0u));
               ir_expression *const r0512 = expr(ir_unop_b2i, r0511);
               ir_expression *const r0513 = expr(ir_unop_i2u, r0512);
               ir_expression *const r0514 = bit_or(r050F, r0513);
               ir_expression *const r0515 = equal(r0502, body.constant(int(32)));
               ir_expression *const r0516 = nequal(r03F9, body.constant(0u));
               ir_expression *const r0517 = expr(ir_unop_b2i, r0516);
               ir_expression *const r0518 = expr(ir_unop_i2u, r0517);
               ir_expression *const r0519 = bit_or(r0216, r0518);
               ir_expression *const r051A = less(r0502, body.constant(int(64)));
               ir_expression *const r051B = bit_and(r0502, body.constant(int(31)));
               ir_expression *const r051C = rshift(r0216, r051B);
               ir_expression *const r051D = lshift(r0216, r0505);
               ir_expression *const r051E = bit_or(r051D, r03F9);
               ir_expression *const r051F = nequal(r051E, body.constant(0u));
               ir_expression *const r0520 = expr(ir_unop_b2i, r051F);
               ir_expression *const r0521 = expr(ir_unop_i2u, r0520);
               ir_expression *const r0522 = bit_or(r051C, r0521);
               ir_expression *const r0523 = expr(ir_triop_csel, r051A, r0522, r0504);
               ir_expression *const r0524 = expr(ir_triop_csel, r0515, r0519, r0523);
               ir_expression *const r0525 = expr(ir_triop_csel, r050C, r0514, r0524);
               body.emit(assign(r050A, expr(ir_triop_csel, r050B, r03F9, r0525), 0x01));

               body.emit(assign(r0504, r050A, 0x01));

               ir_expression *const r0526 = less(r0502, body.constant(int(32)));
               ir_expression *const r0527 = rshift(r0216, r0502);
               ir_expression *const r0528 = equal(r0502, body.constant(int(0)));
               ir_expression *const r0529 = expr(ir_triop_csel, r0528, r0216, body.constant(0u));
               body.emit(assign(r0503, expr(ir_triop_csel, r0526, r0527, r0529), 0x01));

               body.emit(assign(r0216, r0503, 0x01));

               body.emit(assign(r0217, r050A, 0x01));

               body.emit(assign(r0214, bit_or(r0214, body.constant(1073741824u)), 0x01));

               ir_variable *const r052A = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_expression *const r052B = sub(r0214, r0503);
               ir_expression *const r052C = less(r0215, r050A);
               ir_expression *const r052D = expr(ir_unop_b2i, r052C);
               ir_expression *const r052E = expr(ir_unop_i2u, r052D);
               body.emit(assign(r052A, sub(r052B, r052E), 0x01));

               body.emit(assign(r0211, r052A, 0x01));

               body.emit(assign(r0218, bit_xor(r0219, body.constant(1u)), 0x01));

               body.emit(assign(r03F7, add(r0220, body.constant(int(-1))), 0x01));

               ir_variable *const r052F = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r052F, add(r03F7, body.constant(int(-10))), 0x01));

               ir_variable *const r0530 = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r0531 = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r0532 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r0532);
               ir_variable *const r0533 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0533);
               ir_expression *const r0534 = equal(r052A, body.constant(0u));
               ir_expression *const r0535 = add(r052F, body.constant(int(-32)));
               body.emit(assign(r052F, expr(ir_triop_csel, r0534, r0535, r052F), 0x01));

               ir_variable *const r0536 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0537 = equal(r052A, body.constant(0u));
               ir_expression *const r0538 = sub(r0215, r050A);
               body.emit(assign(r0536, expr(ir_triop_csel, r0537, body.constant(0u), r0538), 0x01));

               body.emit(assign(r0531, r0536, 0x01));

               ir_variable *const r0539 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r053A = equal(r052A, body.constant(0u));
               body.emit(assign(r0539, expr(ir_triop_csel, r053A, r0536, r052A), 0x01));

               body.emit(assign(r0530, r0539, 0x01));

               ir_expression *const r053B = equal(r0539, body.constant(0u));
               ir_expression *const r053C = expr(ir_unop_find_msb, r0539);
               ir_expression *const r053D = sub(body.constant(int(31)), r053C);
               ir_expression *const r053E = expr(ir_triop_csel, r053B, body.constant(int(32)), r053D);
               body.emit(assign(r0533, add(r053E, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0540 = gequal(r0533, body.constant(int(0)));
               ir_if *f053F = new(mem_ctx) ir_if(operand(r0540).val);
               exec_list *const f053F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f053F->then_instructions;

                  body.emit(assign(r0532, body.constant(0u), 0x01));

                  ir_expression *const r0541 = equal(r0533, body.constant(int(0)));
                  ir_expression *const r0542 = lshift(r0539, r0533);
                  ir_expression *const r0543 = neg(r0533);
                  ir_expression *const r0544 = bit_and(r0543, body.constant(int(31)));
                  ir_expression *const r0545 = rshift(r0536, r0544);
                  ir_expression *const r0546 = bit_or(r0542, r0545);
                  body.emit(assign(r0530, expr(ir_triop_csel, r0541, r0539, r0546), 0x01));

                  body.emit(assign(r0531, lshift(r0536, r0533), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f053F->else_instructions;

                  ir_variable *const r0547 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r0547, neg(r0533), 0x01));

                  ir_variable *const r0548 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  ir_variable *const r0549 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0549);
                  ir_variable *const r054A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r054B = neg(r0547);
                  body.emit(assign(r054A, bit_and(r054B, body.constant(int(31))), 0x01));

                  ir_variable *const r054C = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r054D = less(r0547, body.constant(int(32)));
                  ir_expression *const r054E = bit_or(body.constant(0u), r0531);
                  body.emit(assign(r054C, expr(ir_triop_csel, r054D, body.constant(0u), r054E), 0x01));

                  ir_expression *const r054F = less(r0547, body.constant(int(32)));
                  ir_expression *const r0550 = lshift(r0531, r054A);
                  ir_expression *const r0551 = less(r0547, body.constant(int(64)));
                  ir_expression *const r0552 = lshift(r0530, r054A);
                  ir_expression *const r0553 = equal(r0547, body.constant(int(64)));
                  ir_expression *const r0554 = nequal(r0530, body.constant(0u));
                  ir_expression *const r0555 = expr(ir_unop_b2i, r0554);
                  ir_expression *const r0556 = expr(ir_unop_i2u, r0555);
                  ir_expression *const r0557 = expr(ir_triop_csel, r0553, r0530, r0556);
                  ir_expression *const r0558 = expr(ir_triop_csel, r0551, r0552, r0557);
                  ir_expression *const r0559 = expr(ir_triop_csel, r054F, r0550, r0558);
                  ir_expression *const r055A = nequal(r054C, body.constant(0u));
                  ir_expression *const r055B = expr(ir_unop_b2i, r055A);
                  ir_expression *const r055C = expr(ir_unop_i2u, r055B);
                  body.emit(assign(r0549, bit_or(r0559, r055C), 0x01));

                  ir_variable *const r055D = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r055E = equal(r0547, body.constant(int(0)));
                  ir_expression *const r055F = equal(r0547, body.constant(int(32)));
                  ir_expression *const r0560 = expr(ir_triop_csel, r055F, r0531, r0549);
                  body.emit(assign(r055D, expr(ir_triop_csel, r055E, r054C, r0560), 0x01));

                  body.emit(assign(r0549, r055D, 0x01));

                  ir_expression *const r0561 = equal(r0547, body.constant(int(0)));
                  ir_expression *const r0562 = equal(r0547, body.constant(int(32)));
                  ir_expression *const r0563 = less(r0547, body.constant(int(32)));
                  ir_expression *const r0564 = lshift(r0530, r054A);
                  ir_expression *const r0565 = rshift(r0531, r0547);
                  ir_expression *const r0566 = bit_or(r0564, r0565);
                  ir_expression *const r0567 = less(r0547, body.constant(int(64)));
                  ir_expression *const r0568 = bit_and(r0547, body.constant(int(31)));
                  ir_expression *const r0569 = rshift(r0530, r0568);
                  ir_expression *const r056A = expr(ir_triop_csel, r0567, r0569, body.constant(0u));
                  ir_expression *const r056B = expr(ir_triop_csel, r0563, r0566, r056A);
                  ir_expression *const r056C = expr(ir_triop_csel, r0562, r0530, r056B);
                  body.emit(assign(r0548, expr(ir_triop_csel, r0561, r0531, r056C), 0x01));

                  ir_expression *const r056D = equal(r0547, body.constant(int(0)));
                  ir_expression *const r056E = equal(r0547, body.constant(int(32)));
                  ir_expression *const r056F = less(r0547, body.constant(int(32)));
                  ir_expression *const r0570 = rshift(r0530, r0547);
                  ir_expression *const r0571 = expr(ir_triop_csel, r056F, r0570, body.constant(0u));
                  ir_expression *const r0572 = expr(ir_triop_csel, r056E, body.constant(0u), r0571);
                  body.emit(assign(r0530, expr(ir_triop_csel, r056D, r0530, r0572), 0x01));

                  body.emit(assign(r0531, r0548, 0x01));

                  body.emit(assign(r0532, r055D, 0x01));


               body.instructions = f053F_parent_instructions;
               body.emit(f053F);

               /* END IF */

               body.emit(assign(r052F, sub(r052F, r0533), 0x01));

               ir_variable *const r0573 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0573, r052F, 0x01));

               ir_variable *const r0574 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r0574, r0530, 0x01));

               ir_variable *const r0575 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0575, r0531, 0x01));

               ir_variable *const r0576 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r0576, r0532, 0x01));

               ir_variable *const r0577 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0577, body.constant(true), 0x01));

               ir_variable *const r0578 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0579 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0579);
               ir_expression *const r057A = expr(ir_unop_u2i, r0532);
               body.emit(assign(r0579, less(r057A, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r057C = gequal(r052F, body.constant(int(2045)));
               ir_if *f057B = new(mem_ctx) ir_if(operand(r057C).val);
               exec_list *const f057B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f057B->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r057E = less(body.constant(int(2045)), r052F);
                  ir_expression *const r057F = equal(r052F, body.constant(int(2045)));
                  ir_expression *const r0580 = equal(body.constant(2097151u), r0530);
                  ir_expression *const r0581 = equal(body.constant(4294967295u), r0531);
                  ir_expression *const r0582 = logic_and(r0580, r0581);
                  ir_expression *const r0583 = logic_and(r057F, r0582);
                  ir_expression *const r0584 = logic_and(r0583, r0579);
                  ir_expression *const r0585 = logic_or(r057E, r0584);
                  ir_if *f057D = new(mem_ctx) ir_if(operand(r0585).val);
                  exec_list *const f057D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f057D->then_instructions;

                     ir_variable *const r0586 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0586);
                     ir_expression *const r0587 = lshift(r0218, body.constant(int(31)));
                     body.emit(assign(r0586, add(r0587, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r0586, body.constant(0u), 0x01));

                     body.emit(assign(r0578, r0586, 0x03));

                     body.emit(assign(r0577, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f057D->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0589 = less(r052F, body.constant(int(0)));
                     ir_if *f0588 = new(mem_ctx) ir_if(operand(r0589).val);
                     exec_list *const f0588_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0588->then_instructions;

                        ir_variable *const r058A = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r058A, neg(r052F), 0x01));

                        ir_variable *const r058B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r058B);
                        ir_variable *const r058C = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r058D = neg(r058A);
                        body.emit(assign(r058C, bit_and(r058D, body.constant(int(31))), 0x01));

                        ir_variable *const r058E = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r058F = less(r058A, body.constant(int(32)));
                        ir_expression *const r0590 = bit_or(r0532, r0531);
                        body.emit(assign(r058E, expr(ir_triop_csel, r058F, r0532, r0590), 0x01));

                        ir_expression *const r0591 = less(r058A, body.constant(int(32)));
                        ir_expression *const r0592 = lshift(r0531, r058C);
                        ir_expression *const r0593 = less(r058A, body.constant(int(64)));
                        ir_expression *const r0594 = lshift(r0530, r058C);
                        ir_expression *const r0595 = equal(r058A, body.constant(int(64)));
                        ir_expression *const r0596 = nequal(r0530, body.constant(0u));
                        ir_expression *const r0597 = expr(ir_unop_b2i, r0596);
                        ir_expression *const r0598 = expr(ir_unop_i2u, r0597);
                        ir_expression *const r0599 = expr(ir_triop_csel, r0595, r0530, r0598);
                        ir_expression *const r059A = expr(ir_triop_csel, r0593, r0594, r0599);
                        ir_expression *const r059B = expr(ir_triop_csel, r0591, r0592, r059A);
                        ir_expression *const r059C = nequal(r058E, body.constant(0u));
                        ir_expression *const r059D = expr(ir_unop_b2i, r059C);
                        ir_expression *const r059E = expr(ir_unop_i2u, r059D);
                        body.emit(assign(r058B, bit_or(r059B, r059E), 0x01));

                        ir_variable *const r059F = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r05A0 = equal(r058A, body.constant(int(0)));
                        ir_expression *const r05A1 = equal(r058A, body.constant(int(32)));
                        ir_expression *const r05A2 = expr(ir_triop_csel, r05A1, r0531, r058B);
                        body.emit(assign(r059F, expr(ir_triop_csel, r05A0, r058E, r05A2), 0x01));

                        body.emit(assign(r058B, r059F, 0x01));

                        ir_expression *const r05A3 = equal(r058A, body.constant(int(0)));
                        ir_expression *const r05A4 = equal(r058A, body.constant(int(32)));
                        ir_expression *const r05A5 = less(r058A, body.constant(int(32)));
                        ir_expression *const r05A6 = rshift(r0530, r058A);
                        ir_expression *const r05A7 = expr(ir_triop_csel, r05A5, r05A6, body.constant(0u));
                        ir_expression *const r05A8 = expr(ir_triop_csel, r05A4, body.constant(0u), r05A7);
                        body.emit(assign(r0574, expr(ir_triop_csel, r05A3, r0530, r05A8), 0x01));

                        ir_expression *const r05A9 = equal(r058A, body.constant(int(0)));
                        ir_expression *const r05AA = equal(r058A, body.constant(int(32)));
                        ir_expression *const r05AB = less(r058A, body.constant(int(32)));
                        ir_expression *const r05AC = lshift(r0530, r058C);
                        ir_expression *const r05AD = rshift(r0531, r058A);
                        ir_expression *const r05AE = bit_or(r05AC, r05AD);
                        ir_expression *const r05AF = less(r058A, body.constant(int(64)));
                        ir_expression *const r05B0 = bit_and(r058A, body.constant(int(31)));
                        ir_expression *const r05B1 = rshift(r0530, r05B0);
                        ir_expression *const r05B2 = expr(ir_triop_csel, r05AF, r05B1, body.constant(0u));
                        ir_expression *const r05B3 = expr(ir_triop_csel, r05AB, r05AE, r05B2);
                        ir_expression *const r05B4 = expr(ir_triop_csel, r05AA, r0530, r05B3);
                        body.emit(assign(r0575, expr(ir_triop_csel, r05A9, r0531, r05B4), 0x01));

                        body.emit(assign(r0576, r059F, 0x01));

                        body.emit(assign(r0573, body.constant(int(0)), 0x01));

                        body.emit(assign(r0579, less(r059F, body.constant(0u)), 0x01));


                     body.instructions = f0588_parent_instructions;
                     body.emit(f0588);

                     /* END IF */


                  body.instructions = f057D_parent_instructions;
                  body.emit(f057D);

                  /* END IF */


               body.instructions = f057B_parent_instructions;
               body.emit(f057B);

               /* END IF */

               /* IF CONDITION */
               ir_if *f05B5 = new(mem_ctx) ir_if(operand(r0577).val);
               exec_list *const f05B5_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f05B5->then_instructions;

                  /* IF CONDITION */
                  ir_if *f05B6 = new(mem_ctx) ir_if(operand(r0579).val);
                  exec_list *const f05B6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05B6->then_instructions;

                     ir_variable *const r05B7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r05B7, add(r0575, body.constant(1u)), 0x01));

                     ir_expression *const r05B8 = less(r05B7, r0575);
                     ir_expression *const r05B9 = expr(ir_unop_b2i, r05B8);
                     ir_expression *const r05BA = expr(ir_unop_i2u, r05B9);
                     body.emit(assign(r0574, add(r0574, r05BA), 0x01));

                     ir_expression *const r05BB = equal(r0576, body.constant(0u));
                     ir_expression *const r05BC = expr(ir_unop_b2i, r05BB);
                     ir_expression *const r05BD = expr(ir_unop_i2u, r05BC);
                     ir_expression *const r05BE = add(r0576, r05BD);
                     ir_expression *const r05BF = bit_and(r05BE, body.constant(1u));
                     ir_expression *const r05C0 = expr(ir_unop_bit_not, r05BF);
                     body.emit(assign(r0575, bit_and(r05B7, r05C0), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05B6->else_instructions;

                     ir_expression *const r05C1 = bit_or(r0574, r0575);
                     ir_expression *const r05C2 = equal(r05C1, body.constant(0u));
                     body.emit(assign(r0573, expr(ir_triop_csel, r05C2, body.constant(int(0)), r0573), 0x01));


                  body.instructions = f05B6_parent_instructions;
                  body.emit(f05B6);

                  /* END IF */

                  ir_variable *const r05C3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r05C3);
                  ir_expression *const r05C4 = lshift(r0218, body.constant(int(31)));
                  ir_expression *const r05C5 = expr(ir_unop_i2u, r0573);
                  ir_expression *const r05C6 = lshift(r05C5, body.constant(int(20)));
                  ir_expression *const r05C7 = add(r05C4, r05C6);
                  body.emit(assign(r05C3, add(r05C7, r0574), 0x02));

                  body.emit(assign(r05C3, r0575, 0x01));

                  body.emit(assign(r0578, r05C3, 0x03));

                  body.emit(assign(r0577, body.constant(false), 0x01));


               body.instructions = f05B5_parent_instructions;
               body.emit(f05B5);

               /* END IF */

               body.emit(assign(r020F, r0578, 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


            body.instructions = f04E4_parent_instructions;
            body.emit(f04E4);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f04E2->else_instructions;

            /* IF CONDITION */
            ir_expression *const r05C9 = equal(r021D, body.constant(int(2047)));
            ir_if *f05C8 = new(mem_ctx) ir_if(operand(r05C9).val);
            exec_list *const f05C8_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f05C8->then_instructions;

               ir_variable *const r05CA = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r05CA, swizzle_x(r020C), 0x01));

               ir_variable *const r05CB = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r05CB, swizzle_x(r020D), 0x01));

               body.emit(assign(r05CA, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r05CB, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r05CC = bit_or(r0216, r0217);
               ir_expression *const r05CD = bit_or(r0214, r0215);
               ir_expression *const r05CE = bit_or(r05CC, r05CD);
               ir_expression *const r05CF = nequal(r05CE, body.constant(0u));
               ir_swizzle *const r05D0 = swizzle(r05CF, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r05D1 = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r05D2 = gequal(r05D1, body.constant(4292870144u));
               ir_expression *const r05D3 = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r05D4 = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r05D5 = nequal(r05D4, body.constant(0u));
               ir_expression *const r05D6 = logic_or(r05D3, r05D5);
               ir_expression *const r05D7 = logic_and(r05D2, r05D6);
               ir_swizzle *const r05D8 = swizzle(r05D7, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r05D9 = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r05DA = gequal(r05D9, body.constant(4292870144u));
               ir_expression *const r05DB = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r05DC = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r05DD = nequal(r05DC, body.constant(0u));
               ir_expression *const r05DE = logic_or(r05DB, r05DD);
               ir_expression *const r05DF = logic_and(r05DA, r05DE);
               ir_swizzle *const r05E0 = swizzle(r05DF, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r05E1 = expr(ir_triop_csel, r05E0, r05CB, r05CA);
               ir_expression *const r05E2 = expr(ir_triop_csel, r05D8, r05E1, r05CB);
               ir_constant_data r05E3_data;
               memset(&r05E3_data, 0, sizeof(ir_constant_data));
               r05E3_data.u[0] = 4294967295;
               r05E3_data.u[1] = 4294967295;
               ir_constant *const r05E3 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r05E3_data);
               body.emit(assign(r020F, expr(ir_triop_csel, r05D0, r05E2, r05E3), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f05C8->else_instructions;

               ir_expression *const r05E4 = equal(r021D, body.constant(int(0)));
               body.emit(assign(r0212, expr(ir_triop_csel, r05E4, body.constant(int(1)), r0220), 0x01));

               ir_expression *const r05E5 = equal(r021D, body.constant(int(0)));
               body.emit(assign(r0213, expr(ir_triop_csel, r05E5, body.constant(int(1)), r021D), 0x01));

               /* IF CONDITION */
               ir_expression *const r05E7 = less(r0214, r0216);
               ir_if *f05E6 = new(mem_ctx) ir_if(operand(r05E7).val);
               exec_list *const f05E6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f05E6->then_instructions;

                  ir_variable *const r05E8 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_expression *const r05E9 = sub(r0216, r0214);
                  ir_expression *const r05EA = less(r0217, r0215);
                  ir_expression *const r05EB = expr(ir_unop_b2i, r05EA);
                  ir_expression *const r05EC = expr(ir_unop_i2u, r05EB);
                  body.emit(assign(r05E8, sub(r05E9, r05EC), 0x01));

                  body.emit(assign(r0211, r05E8, 0x01));

                  body.emit(assign(r03F7, add(r0213, body.constant(int(-1))), 0x01));

                  ir_variable *const r05ED = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r05ED, add(r03F7, body.constant(int(-10))), 0x01));

                  ir_variable *const r05EE = body.make_temp(glsl_type::uint_type, "zFrac0");
                  ir_variable *const r05EF = body.make_temp(glsl_type::uint_type, "zFrac1");
                  ir_variable *const r05F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r05F0);
                  ir_variable *const r05F1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r05F1);
                  ir_expression *const r05F2 = equal(r05E8, body.constant(0u));
                  ir_expression *const r05F3 = add(r05ED, body.constant(int(-32)));
                  body.emit(assign(r05ED, expr(ir_triop_csel, r05F2, r05F3, r05ED), 0x01));

                  ir_variable *const r05F4 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r05F5 = equal(r05E8, body.constant(0u));
                  ir_expression *const r05F6 = sub(r0217, r0215);
                  body.emit(assign(r05F4, expr(ir_triop_csel, r05F5, body.constant(0u), r05F6), 0x01));

                  body.emit(assign(r05EF, r05F4, 0x01));

                  ir_variable *const r05F7 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r05F8 = equal(r05E8, body.constant(0u));
                  body.emit(assign(r05F7, expr(ir_triop_csel, r05F8, r05F4, r05E8), 0x01));

                  body.emit(assign(r05EE, r05F7, 0x01));

                  ir_expression *const r05F9 = equal(r05F7, body.constant(0u));
                  ir_expression *const r05FA = expr(ir_unop_find_msb, r05F7);
                  ir_expression *const r05FB = sub(body.constant(int(31)), r05FA);
                  ir_expression *const r05FC = expr(ir_triop_csel, r05F9, body.constant(int(32)), r05FB);
                  body.emit(assign(r05F1, add(r05FC, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r05FE = gequal(r05F1, body.constant(int(0)));
                  ir_if *f05FD = new(mem_ctx) ir_if(operand(r05FE).val);
                  exec_list *const f05FD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05FD->then_instructions;

                     body.emit(assign(r05F0, body.constant(0u), 0x01));

                     ir_expression *const r05FF = equal(r05F1, body.constant(int(0)));
                     ir_expression *const r0600 = lshift(r05F7, r05F1);
                     ir_expression *const r0601 = neg(r05F1);
                     ir_expression *const r0602 = bit_and(r0601, body.constant(int(31)));
                     ir_expression *const r0603 = rshift(r05F4, r0602);
                     ir_expression *const r0604 = bit_or(r0600, r0603);
                     body.emit(assign(r05EE, expr(ir_triop_csel, r05FF, r05F7, r0604), 0x01));

                     body.emit(assign(r05EF, lshift(r05F4, r05F1), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05FD->else_instructions;

                     ir_variable *const r0605 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0605, neg(r05F1), 0x01));

                     ir_variable *const r0606 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     ir_variable *const r0607 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0607);
                     ir_variable *const r0608 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0609 = neg(r0605);
                     body.emit(assign(r0608, bit_and(r0609, body.constant(int(31))), 0x01));

                     ir_variable *const r060A = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r060B = less(r0605, body.constant(int(32)));
                     ir_expression *const r060C = bit_or(body.constant(0u), r05EF);
                     body.emit(assign(r060A, expr(ir_triop_csel, r060B, body.constant(0u), r060C), 0x01));

                     ir_expression *const r060D = less(r0605, body.constant(int(32)));
                     ir_expression *const r060E = lshift(r05EF, r0608);
                     ir_expression *const r060F = less(r0605, body.constant(int(64)));
                     ir_expression *const r0610 = lshift(r05EE, r0608);
                     ir_expression *const r0611 = equal(r0605, body.constant(int(64)));
                     ir_expression *const r0612 = nequal(r05EE, body.constant(0u));
                     ir_expression *const r0613 = expr(ir_unop_b2i, r0612);
                     ir_expression *const r0614 = expr(ir_unop_i2u, r0613);
                     ir_expression *const r0615 = expr(ir_triop_csel, r0611, r05EE, r0614);
                     ir_expression *const r0616 = expr(ir_triop_csel, r060F, r0610, r0615);
                     ir_expression *const r0617 = expr(ir_triop_csel, r060D, r060E, r0616);
                     ir_expression *const r0618 = nequal(r060A, body.constant(0u));
                     ir_expression *const r0619 = expr(ir_unop_b2i, r0618);
                     ir_expression *const r061A = expr(ir_unop_i2u, r0619);
                     body.emit(assign(r0607, bit_or(r0617, r061A), 0x01));

                     ir_variable *const r061B = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r061C = equal(r0605, body.constant(int(0)));
                     ir_expression *const r061D = equal(r0605, body.constant(int(32)));
                     ir_expression *const r061E = expr(ir_triop_csel, r061D, r05EF, r0607);
                     body.emit(assign(r061B, expr(ir_triop_csel, r061C, r060A, r061E), 0x01));

                     body.emit(assign(r0607, r061B, 0x01));

                     ir_expression *const r061F = equal(r0605, body.constant(int(0)));
                     ir_expression *const r0620 = equal(r0605, body.constant(int(32)));
                     ir_expression *const r0621 = less(r0605, body.constant(int(32)));
                     ir_expression *const r0622 = lshift(r05EE, r0608);
                     ir_expression *const r0623 = rshift(r05EF, r0605);
                     ir_expression *const r0624 = bit_or(r0622, r0623);
                     ir_expression *const r0625 = less(r0605, body.constant(int(64)));
                     ir_expression *const r0626 = bit_and(r0605, body.constant(int(31)));
                     ir_expression *const r0627 = rshift(r05EE, r0626);
                     ir_expression *const r0628 = expr(ir_triop_csel, r0625, r0627, body.constant(0u));
                     ir_expression *const r0629 = expr(ir_triop_csel, r0621, r0624, r0628);
                     ir_expression *const r062A = expr(ir_triop_csel, r0620, r05EE, r0629);
                     body.emit(assign(r0606, expr(ir_triop_csel, r061F, r05EF, r062A), 0x01));

                     ir_expression *const r062B = equal(r0605, body.constant(int(0)));
                     ir_expression *const r062C = equal(r0605, body.constant(int(32)));
                     ir_expression *const r062D = less(r0605, body.constant(int(32)));
                     ir_expression *const r062E = rshift(r05EE, r0605);
                     ir_expression *const r062F = expr(ir_triop_csel, r062D, r062E, body.constant(0u));
                     ir_expression *const r0630 = expr(ir_triop_csel, r062C, body.constant(0u), r062F);
                     body.emit(assign(r05EE, expr(ir_triop_csel, r062B, r05EE, r0630), 0x01));

                     body.emit(assign(r05EF, r0606, 0x01));

                     body.emit(assign(r05F0, r061B, 0x01));


                  body.instructions = f05FD_parent_instructions;
                  body.emit(f05FD);

                  /* END IF */

                  body.emit(assign(r05ED, sub(r05ED, r05F1), 0x01));

                  ir_variable *const r0631 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0631, r05ED, 0x01));

                  ir_variable *const r0632 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0632, r05EE, 0x01));

                  ir_variable *const r0633 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0633, r05EF, 0x01));

                  ir_variable *const r0634 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0634, r05F0, 0x01));

                  ir_variable *const r0635 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0635, body.constant(true), 0x01));

                  ir_variable *const r0636 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0637 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r0637);
                  ir_expression *const r0638 = expr(ir_unop_u2i, r05F0);
                  body.emit(assign(r0637, less(r0638, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r063A = gequal(r05ED, body.constant(int(2045)));
                  ir_if *f0639 = new(mem_ctx) ir_if(operand(r063A).val);
                  exec_list *const f0639_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0639->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r063C = less(body.constant(int(2045)), r05ED);
                     ir_expression *const r063D = equal(r05ED, body.constant(int(2045)));
                     ir_expression *const r063E = equal(body.constant(2097151u), r05EE);
                     ir_expression *const r063F = equal(body.constant(4294967295u), r05EF);
                     ir_expression *const r0640 = logic_and(r063E, r063F);
                     ir_expression *const r0641 = logic_and(r063D, r0640);
                     ir_expression *const r0642 = logic_and(r0641, r0637);
                     ir_expression *const r0643 = logic_or(r063C, r0642);
                     ir_if *f063B = new(mem_ctx) ir_if(operand(r0643).val);
                     exec_list *const f063B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f063B->then_instructions;

                        ir_variable *const r0644 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0644);
                        ir_expression *const r0645 = lshift(r0218, body.constant(int(31)));
                        body.emit(assign(r0644, add(r0645, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0644, body.constant(0u), 0x01));

                        body.emit(assign(r0636, r0644, 0x03));

                        body.emit(assign(r0635, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f063B->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0647 = less(r05ED, body.constant(int(0)));
                        ir_if *f0646 = new(mem_ctx) ir_if(operand(r0647).val);
                        exec_list *const f0646_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0646->then_instructions;

                           ir_variable *const r0648 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0648, neg(r05ED), 0x01));

                           ir_variable *const r0649 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0649);
                           ir_variable *const r064A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r064B = neg(r0648);
                           body.emit(assign(r064A, bit_and(r064B, body.constant(int(31))), 0x01));

                           ir_variable *const r064C = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r064D = less(r0648, body.constant(int(32)));
                           ir_expression *const r064E = bit_or(r05F0, r05EF);
                           body.emit(assign(r064C, expr(ir_triop_csel, r064D, r05F0, r064E), 0x01));

                           ir_expression *const r064F = less(r0648, body.constant(int(32)));
                           ir_expression *const r0650 = lshift(r05EF, r064A);
                           ir_expression *const r0651 = less(r0648, body.constant(int(64)));
                           ir_expression *const r0652 = lshift(r05EE, r064A);
                           ir_expression *const r0653 = equal(r0648, body.constant(int(64)));
                           ir_expression *const r0654 = nequal(r05EE, body.constant(0u));
                           ir_expression *const r0655 = expr(ir_unop_b2i, r0654);
                           ir_expression *const r0656 = expr(ir_unop_i2u, r0655);
                           ir_expression *const r0657 = expr(ir_triop_csel, r0653, r05EE, r0656);
                           ir_expression *const r0658 = expr(ir_triop_csel, r0651, r0652, r0657);
                           ir_expression *const r0659 = expr(ir_triop_csel, r064F, r0650, r0658);
                           ir_expression *const r065A = nequal(r064C, body.constant(0u));
                           ir_expression *const r065B = expr(ir_unop_b2i, r065A);
                           ir_expression *const r065C = expr(ir_unop_i2u, r065B);
                           body.emit(assign(r0649, bit_or(r0659, r065C), 0x01));

                           ir_variable *const r065D = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r065E = equal(r0648, body.constant(int(0)));
                           ir_expression *const r065F = equal(r0648, body.constant(int(32)));
                           ir_expression *const r0660 = expr(ir_triop_csel, r065F, r05EF, r0649);
                           body.emit(assign(r065D, expr(ir_triop_csel, r065E, r064C, r0660), 0x01));

                           body.emit(assign(r0649, r065D, 0x01));

                           ir_expression *const r0661 = equal(r0648, body.constant(int(0)));
                           ir_expression *const r0662 = equal(r0648, body.constant(int(32)));
                           ir_expression *const r0663 = less(r0648, body.constant(int(32)));
                           ir_expression *const r0664 = rshift(r05EE, r0648);
                           ir_expression *const r0665 = expr(ir_triop_csel, r0663, r0664, body.constant(0u));
                           ir_expression *const r0666 = expr(ir_triop_csel, r0662, body.constant(0u), r0665);
                           body.emit(assign(r0632, expr(ir_triop_csel, r0661, r05EE, r0666), 0x01));

                           ir_expression *const r0667 = equal(r0648, body.constant(int(0)));
                           ir_expression *const r0668 = equal(r0648, body.constant(int(32)));
                           ir_expression *const r0669 = less(r0648, body.constant(int(32)));
                           ir_expression *const r066A = lshift(r05EE, r064A);
                           ir_expression *const r066B = rshift(r05EF, r0648);
                           ir_expression *const r066C = bit_or(r066A, r066B);
                           ir_expression *const r066D = less(r0648, body.constant(int(64)));
                           ir_expression *const r066E = bit_and(r0648, body.constant(int(31)));
                           ir_expression *const r066F = rshift(r05EE, r066E);
                           ir_expression *const r0670 = expr(ir_triop_csel, r066D, r066F, body.constant(0u));
                           ir_expression *const r0671 = expr(ir_triop_csel, r0669, r066C, r0670);
                           ir_expression *const r0672 = expr(ir_triop_csel, r0668, r05EE, r0671);
                           body.emit(assign(r0633, expr(ir_triop_csel, r0667, r05EF, r0672), 0x01));

                           body.emit(assign(r0634, r065D, 0x01));

                           body.emit(assign(r0631, body.constant(int(0)), 0x01));

                           body.emit(assign(r0637, less(r065D, body.constant(0u)), 0x01));


                        body.instructions = f0646_parent_instructions;
                        body.emit(f0646);

                        /* END IF */


                     body.instructions = f063B_parent_instructions;
                     body.emit(f063B);

                     /* END IF */


                  body.instructions = f0639_parent_instructions;
                  body.emit(f0639);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0673 = new(mem_ctx) ir_if(operand(r0635).val);
                  exec_list *const f0673_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0673->then_instructions;

                     /* IF CONDITION */
                     ir_if *f0674 = new(mem_ctx) ir_if(operand(r0637).val);
                     exec_list *const f0674_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0674->then_instructions;

                        ir_variable *const r0675 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r0675, add(r0633, body.constant(1u)), 0x01));

                        ir_expression *const r0676 = less(r0675, r0633);
                        ir_expression *const r0677 = expr(ir_unop_b2i, r0676);
                        ir_expression *const r0678 = expr(ir_unop_i2u, r0677);
                        body.emit(assign(r0632, add(r0632, r0678), 0x01));

                        ir_expression *const r0679 = equal(r0634, body.constant(0u));
                        ir_expression *const r067A = expr(ir_unop_b2i, r0679);
                        ir_expression *const r067B = expr(ir_unop_i2u, r067A);
                        ir_expression *const r067C = add(r0634, r067B);
                        ir_expression *const r067D = bit_and(r067C, body.constant(1u));
                        ir_expression *const r067E = expr(ir_unop_bit_not, r067D);
                        body.emit(assign(r0633, bit_and(r0675, r067E), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0674->else_instructions;

                        ir_expression *const r067F = bit_or(r0632, r0633);
                        ir_expression *const r0680 = equal(r067F, body.constant(0u));
                        body.emit(assign(r0631, expr(ir_triop_csel, r0680, body.constant(int(0)), r0631), 0x01));


                     body.instructions = f0674_parent_instructions;
                     body.emit(f0674);

                     /* END IF */

                     ir_variable *const r0681 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0681);
                     ir_expression *const r0682 = lshift(r0218, body.constant(int(31)));
                     ir_expression *const r0683 = expr(ir_unop_i2u, r0631);
                     ir_expression *const r0684 = lshift(r0683, body.constant(int(20)));
                     ir_expression *const r0685 = add(r0682, r0684);
                     body.emit(assign(r0681, add(r0685, r0632), 0x02));

                     body.emit(assign(r0681, r0633, 0x01));

                     body.emit(assign(r0636, r0681, 0x03));

                     body.emit(assign(r0635, body.constant(false), 0x01));


                  body.instructions = f0673_parent_instructions;
                  body.emit(f0673);

                  /* END IF */

                  body.emit(assign(r020F, r0636, 0x03));

                  body.emit(assign(r020E, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f05E6->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0687 = less(r0216, r0214);
                  ir_if *f0686 = new(mem_ctx) ir_if(operand(r0687).val);
                  exec_list *const f0686_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0686->then_instructions;

                     ir_variable *const r0688 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_expression *const r0689 = sub(r0214, r0216);
                     ir_expression *const r068A = less(r0215, r0217);
                     ir_expression *const r068B = expr(ir_unop_b2i, r068A);
                     ir_expression *const r068C = expr(ir_unop_i2u, r068B);
                     body.emit(assign(r0688, sub(r0689, r068C), 0x01));

                     body.emit(assign(r0211, r0688, 0x01));

                     body.emit(assign(r0218, bit_xor(r0218, body.constant(1u)), 0x01));

                     body.emit(assign(r03F7, add(r0212, body.constant(int(-1))), 0x01));

                     ir_variable *const r068D = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r068D, add(r03F7, body.constant(int(-10))), 0x01));

                     ir_variable *const r068E = body.make_temp(glsl_type::uint_type, "zFrac0");
                     ir_variable *const r068F = body.make_temp(glsl_type::uint_type, "zFrac1");
                     ir_variable *const r0690 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r0690);
                     ir_variable *const r0691 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0691);
                     ir_expression *const r0692 = equal(r0688, body.constant(0u));
                     ir_expression *const r0693 = add(r068D, body.constant(int(-32)));
                     body.emit(assign(r068D, expr(ir_triop_csel, r0692, r0693, r068D), 0x01));

                     ir_variable *const r0694 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0695 = equal(r0688, body.constant(0u));
                     ir_expression *const r0696 = sub(r0215, r0217);
                     body.emit(assign(r0694, expr(ir_triop_csel, r0695, body.constant(0u), r0696), 0x01));

                     body.emit(assign(r068F, r0694, 0x01));

                     ir_variable *const r0697 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0698 = equal(r0688, body.constant(0u));
                     body.emit(assign(r0697, expr(ir_triop_csel, r0698, r0694, r0688), 0x01));

                     body.emit(assign(r068E, r0697, 0x01));

                     ir_expression *const r0699 = equal(r0697, body.constant(0u));
                     ir_expression *const r069A = expr(ir_unop_find_msb, r0697);
                     ir_expression *const r069B = sub(body.constant(int(31)), r069A);
                     ir_expression *const r069C = expr(ir_triop_csel, r0699, body.constant(int(32)), r069B);
                     body.emit(assign(r0691, add(r069C, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r069E = gequal(r0691, body.constant(int(0)));
                     ir_if *f069D = new(mem_ctx) ir_if(operand(r069E).val);
                     exec_list *const f069D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f069D->then_instructions;

                        body.emit(assign(r0690, body.constant(0u), 0x01));

                        ir_expression *const r069F = equal(r0691, body.constant(int(0)));
                        ir_expression *const r06A0 = lshift(r0697, r0691);
                        ir_expression *const r06A1 = neg(r0691);
                        ir_expression *const r06A2 = bit_and(r06A1, body.constant(int(31)));
                        ir_expression *const r06A3 = rshift(r0694, r06A2);
                        ir_expression *const r06A4 = bit_or(r06A0, r06A3);
                        body.emit(assign(r068E, expr(ir_triop_csel, r069F, r0697, r06A4), 0x01));

                        body.emit(assign(r068F, lshift(r0694, r0691), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f069D->else_instructions;

                        ir_variable *const r06A5 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r06A5, neg(r0691), 0x01));

                        ir_variable *const r06A6 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        ir_variable *const r06A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r06A7);
                        ir_variable *const r06A8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r06A9 = neg(r06A5);
                        body.emit(assign(r06A8, bit_and(r06A9, body.constant(int(31))), 0x01));

                        ir_variable *const r06AA = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r06AB = less(r06A5, body.constant(int(32)));
                        ir_expression *const r06AC = bit_or(body.constant(0u), r068F);
                        body.emit(assign(r06AA, expr(ir_triop_csel, r06AB, body.constant(0u), r06AC), 0x01));

                        ir_expression *const r06AD = less(r06A5, body.constant(int(32)));
                        ir_expression *const r06AE = lshift(r068F, r06A8);
                        ir_expression *const r06AF = less(r06A5, body.constant(int(64)));
                        ir_expression *const r06B0 = lshift(r068E, r06A8);
                        ir_expression *const r06B1 = equal(r06A5, body.constant(int(64)));
                        ir_expression *const r06B2 = nequal(r068E, body.constant(0u));
                        ir_expression *const r06B3 = expr(ir_unop_b2i, r06B2);
                        ir_expression *const r06B4 = expr(ir_unop_i2u, r06B3);
                        ir_expression *const r06B5 = expr(ir_triop_csel, r06B1, r068E, r06B4);
                        ir_expression *const r06B6 = expr(ir_triop_csel, r06AF, r06B0, r06B5);
                        ir_expression *const r06B7 = expr(ir_triop_csel, r06AD, r06AE, r06B6);
                        ir_expression *const r06B8 = nequal(r06AA, body.constant(0u));
                        ir_expression *const r06B9 = expr(ir_unop_b2i, r06B8);
                        ir_expression *const r06BA = expr(ir_unop_i2u, r06B9);
                        body.emit(assign(r06A7, bit_or(r06B7, r06BA), 0x01));

                        ir_variable *const r06BB = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r06BC = equal(r06A5, body.constant(int(0)));
                        ir_expression *const r06BD = equal(r06A5, body.constant(int(32)));
                        ir_expression *const r06BE = expr(ir_triop_csel, r06BD, r068F, r06A7);
                        body.emit(assign(r06BB, expr(ir_triop_csel, r06BC, r06AA, r06BE), 0x01));

                        body.emit(assign(r06A7, r06BB, 0x01));

                        ir_expression *const r06BF = equal(r06A5, body.constant(int(0)));
                        ir_expression *const r06C0 = equal(r06A5, body.constant(int(32)));
                        ir_expression *const r06C1 = less(r06A5, body.constant(int(32)));
                        ir_expression *const r06C2 = lshift(r068E, r06A8);
                        ir_expression *const r06C3 = rshift(r068F, r06A5);
                        ir_expression *const r06C4 = bit_or(r06C2, r06C3);
                        ir_expression *const r06C5 = less(r06A5, body.constant(int(64)));
                        ir_expression *const r06C6 = bit_and(r06A5, body.constant(int(31)));
                        ir_expression *const r06C7 = rshift(r068E, r06C6);
                        ir_expression *const r06C8 = expr(ir_triop_csel, r06C5, r06C7, body.constant(0u));
                        ir_expression *const r06C9 = expr(ir_triop_csel, r06C1, r06C4, r06C8);
                        ir_expression *const r06CA = expr(ir_triop_csel, r06C0, r068E, r06C9);
                        body.emit(assign(r06A6, expr(ir_triop_csel, r06BF, r068F, r06CA), 0x01));

                        ir_expression *const r06CB = equal(r06A5, body.constant(int(0)));
                        ir_expression *const r06CC = equal(r06A5, body.constant(int(32)));
                        ir_expression *const r06CD = less(r06A5, body.constant(int(32)));
                        ir_expression *const r06CE = rshift(r068E, r06A5);
                        ir_expression *const r06CF = expr(ir_triop_csel, r06CD, r06CE, body.constant(0u));
                        ir_expression *const r06D0 = expr(ir_triop_csel, r06CC, body.constant(0u), r06CF);
                        body.emit(assign(r068E, expr(ir_triop_csel, r06CB, r068E, r06D0), 0x01));

                        body.emit(assign(r068F, r06A6, 0x01));

                        body.emit(assign(r0690, r06BB, 0x01));


                     body.instructions = f069D_parent_instructions;
                     body.emit(f069D);

                     /* END IF */

                     body.emit(assign(r068D, sub(r068D, r0691), 0x01));

                     ir_variable *const r06D1 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r06D1, r068D, 0x01));

                     ir_variable *const r06D2 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r06D2, r068E, 0x01));

                     ir_variable *const r06D3 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r06D3, r068F, 0x01));

                     ir_variable *const r06D4 = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r06D4, r0690, 0x01));

                     ir_variable *const r06D5 = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r06D5, body.constant(true), 0x01));

                     ir_variable *const r06D6 = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r06D7 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r06D7);
                     ir_expression *const r06D8 = expr(ir_unop_u2i, r0690);
                     body.emit(assign(r06D7, less(r06D8, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r06DA = gequal(r068D, body.constant(int(2045)));
                     ir_if *f06D9 = new(mem_ctx) ir_if(operand(r06DA).val);
                     exec_list *const f06D9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f06D9->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r06DC = less(body.constant(int(2045)), r068D);
                        ir_expression *const r06DD = equal(r068D, body.constant(int(2045)));
                        ir_expression *const r06DE = equal(body.constant(2097151u), r068E);
                        ir_expression *const r06DF = equal(body.constant(4294967295u), r068F);
                        ir_expression *const r06E0 = logic_and(r06DE, r06DF);
                        ir_expression *const r06E1 = logic_and(r06DD, r06E0);
                        ir_expression *const r06E2 = logic_and(r06E1, r06D7);
                        ir_expression *const r06E3 = logic_or(r06DC, r06E2);
                        ir_if *f06DB = new(mem_ctx) ir_if(operand(r06E3).val);
                        exec_list *const f06DB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06DB->then_instructions;

                           ir_variable *const r06E4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r06E4);
                           ir_expression *const r06E5 = lshift(r0218, body.constant(int(31)));
                           body.emit(assign(r06E4, add(r06E5, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r06E4, body.constant(0u), 0x01));

                           body.emit(assign(r06D6, r06E4, 0x03));

                           body.emit(assign(r06D5, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06DB->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r06E7 = less(r068D, body.constant(int(0)));
                           ir_if *f06E6 = new(mem_ctx) ir_if(operand(r06E7).val);
                           exec_list *const f06E6_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06E6->then_instructions;

                              ir_variable *const r06E8 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r06E8, neg(r068D), 0x01));

                              ir_variable *const r06E9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r06E9);
                              ir_variable *const r06EA = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r06EB = neg(r06E8);
                              body.emit(assign(r06EA, bit_and(r06EB, body.constant(int(31))), 0x01));

                              ir_variable *const r06EC = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r06ED = less(r06E8, body.constant(int(32)));
                              ir_expression *const r06EE = bit_or(r0690, r068F);
                              body.emit(assign(r06EC, expr(ir_triop_csel, r06ED, r0690, r06EE), 0x01));

                              ir_expression *const r06EF = less(r06E8, body.constant(int(32)));
                              ir_expression *const r06F0 = lshift(r068F, r06EA);
                              ir_expression *const r06F1 = less(r06E8, body.constant(int(64)));
                              ir_expression *const r06F2 = lshift(r068E, r06EA);
                              ir_expression *const r06F3 = equal(r06E8, body.constant(int(64)));
                              ir_expression *const r06F4 = nequal(r068E, body.constant(0u));
                              ir_expression *const r06F5 = expr(ir_unop_b2i, r06F4);
                              ir_expression *const r06F6 = expr(ir_unop_i2u, r06F5);
                              ir_expression *const r06F7 = expr(ir_triop_csel, r06F3, r068E, r06F6);
                              ir_expression *const r06F8 = expr(ir_triop_csel, r06F1, r06F2, r06F7);
                              ir_expression *const r06F9 = expr(ir_triop_csel, r06EF, r06F0, r06F8);
                              ir_expression *const r06FA = nequal(r06EC, body.constant(0u));
                              ir_expression *const r06FB = expr(ir_unop_b2i, r06FA);
                              ir_expression *const r06FC = expr(ir_unop_i2u, r06FB);
                              body.emit(assign(r06E9, bit_or(r06F9, r06FC), 0x01));

                              ir_variable *const r06FD = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r06FE = equal(r06E8, body.constant(int(0)));
                              ir_expression *const r06FF = equal(r06E8, body.constant(int(32)));
                              ir_expression *const r0700 = expr(ir_triop_csel, r06FF, r068F, r06E9);
                              body.emit(assign(r06FD, expr(ir_triop_csel, r06FE, r06EC, r0700), 0x01));

                              body.emit(assign(r06E9, r06FD, 0x01));

                              ir_expression *const r0701 = equal(r06E8, body.constant(int(0)));
                              ir_expression *const r0702 = equal(r06E8, body.constant(int(32)));
                              ir_expression *const r0703 = less(r06E8, body.constant(int(32)));
                              ir_expression *const r0704 = rshift(r068E, r06E8);
                              ir_expression *const r0705 = expr(ir_triop_csel, r0703, r0704, body.constant(0u));
                              ir_expression *const r0706 = expr(ir_triop_csel, r0702, body.constant(0u), r0705);
                              body.emit(assign(r06D2, expr(ir_triop_csel, r0701, r068E, r0706), 0x01));

                              ir_expression *const r0707 = equal(r06E8, body.constant(int(0)));
                              ir_expression *const r0708 = equal(r06E8, body.constant(int(32)));
                              ir_expression *const r0709 = less(r06E8, body.constant(int(32)));
                              ir_expression *const r070A = lshift(r068E, r06EA);
                              ir_expression *const r070B = rshift(r068F, r06E8);
                              ir_expression *const r070C = bit_or(r070A, r070B);
                              ir_expression *const r070D = less(r06E8, body.constant(int(64)));
                              ir_expression *const r070E = bit_and(r06E8, body.constant(int(31)));
                              ir_expression *const r070F = rshift(r068E, r070E);
                              ir_expression *const r0710 = expr(ir_triop_csel, r070D, r070F, body.constant(0u));
                              ir_expression *const r0711 = expr(ir_triop_csel, r0709, r070C, r0710);
                              ir_expression *const r0712 = expr(ir_triop_csel, r0708, r068E, r0711);
                              body.emit(assign(r06D3, expr(ir_triop_csel, r0707, r068F, r0712), 0x01));

                              body.emit(assign(r06D4, r06FD, 0x01));

                              body.emit(assign(r06D1, body.constant(int(0)), 0x01));

                              body.emit(assign(r06D7, less(r06FD, body.constant(0u)), 0x01));


                           body.instructions = f06E6_parent_instructions;
                           body.emit(f06E6);

                           /* END IF */


                        body.instructions = f06DB_parent_instructions;
                        body.emit(f06DB);

                        /* END IF */


                     body.instructions = f06D9_parent_instructions;
                     body.emit(f06D9);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0713 = new(mem_ctx) ir_if(operand(r06D5).val);
                     exec_list *const f0713_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0713->then_instructions;

                        /* IF CONDITION */
                        ir_if *f0714 = new(mem_ctx) ir_if(operand(r06D7).val);
                        exec_list *const f0714_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0714->then_instructions;

                           ir_variable *const r0715 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r0715, add(r06D3, body.constant(1u)), 0x01));

                           ir_expression *const r0716 = less(r0715, r06D3);
                           ir_expression *const r0717 = expr(ir_unop_b2i, r0716);
                           ir_expression *const r0718 = expr(ir_unop_i2u, r0717);
                           body.emit(assign(r06D2, add(r06D2, r0718), 0x01));

                           ir_expression *const r0719 = equal(r06D4, body.constant(0u));
                           ir_expression *const r071A = expr(ir_unop_b2i, r0719);
                           ir_expression *const r071B = expr(ir_unop_i2u, r071A);
                           ir_expression *const r071C = add(r06D4, r071B);
                           ir_expression *const r071D = bit_and(r071C, body.constant(1u));
                           ir_expression *const r071E = expr(ir_unop_bit_not, r071D);
                           body.emit(assign(r06D3, bit_and(r0715, r071E), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0714->else_instructions;

                           ir_expression *const r071F = bit_or(r06D2, r06D3);
                           ir_expression *const r0720 = equal(r071F, body.constant(0u));
                           body.emit(assign(r06D1, expr(ir_triop_csel, r0720, body.constant(int(0)), r06D1), 0x01));


                        body.instructions = f0714_parent_instructions;
                        body.emit(f0714);

                        /* END IF */

                        ir_variable *const r0721 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0721);
                        ir_expression *const r0722 = lshift(r0218, body.constant(int(31)));
                        ir_expression *const r0723 = expr(ir_unop_i2u, r06D1);
                        ir_expression *const r0724 = lshift(r0723, body.constant(int(20)));
                        ir_expression *const r0725 = add(r0722, r0724);
                        body.emit(assign(r0721, add(r0725, r06D2), 0x02));

                        body.emit(assign(r0721, r06D3, 0x01));

                        body.emit(assign(r06D6, r0721, 0x03));

                        body.emit(assign(r06D5, body.constant(false), 0x01));


                     body.instructions = f0713_parent_instructions;
                     body.emit(f0713);

                     /* END IF */

                     body.emit(assign(r020F, r06D6, 0x03));

                     body.emit(assign(r020E, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0686->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0727 = less(r0215, r0217);
                     ir_if *f0726 = new(mem_ctx) ir_if(operand(r0727).val);
                     exec_list *const f0726_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0726->then_instructions;

                        ir_variable *const r0728 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_expression *const r0729 = sub(r0216, r0214);
                        ir_expression *const r072A = less(r0217, r0215);
                        ir_expression *const r072B = expr(ir_unop_b2i, r072A);
                        ir_expression *const r072C = expr(ir_unop_i2u, r072B);
                        body.emit(assign(r0728, sub(r0729, r072C), 0x01));

                        body.emit(assign(r0211, r0728, 0x01));

                        body.emit(assign(r03F7, add(r0213, body.constant(int(-1))), 0x01));

                        ir_variable *const r072D = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r072D, add(r03F7, body.constant(int(-10))), 0x01));

                        ir_variable *const r072E = body.make_temp(glsl_type::uint_type, "zFrac0");
                        ir_variable *const r072F = body.make_temp(glsl_type::uint_type, "zFrac1");
                        ir_variable *const r0730 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0730);
                        ir_variable *const r0731 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0731);
                        ir_expression *const r0732 = equal(r0728, body.constant(0u));
                        ir_expression *const r0733 = add(r072D, body.constant(int(-32)));
                        body.emit(assign(r072D, expr(ir_triop_csel, r0732, r0733, r072D), 0x01));

                        ir_variable *const r0734 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0735 = equal(r0728, body.constant(0u));
                        ir_expression *const r0736 = sub(r0217, r0215);
                        body.emit(assign(r0734, expr(ir_triop_csel, r0735, body.constant(0u), r0736), 0x01));

                        body.emit(assign(r072F, r0734, 0x01));

                        ir_variable *const r0737 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0738 = equal(r0728, body.constant(0u));
                        body.emit(assign(r0737, expr(ir_triop_csel, r0738, r0734, r0728), 0x01));

                        body.emit(assign(r072E, r0737, 0x01));

                        ir_expression *const r0739 = equal(r0737, body.constant(0u));
                        ir_expression *const r073A = expr(ir_unop_find_msb, r0737);
                        ir_expression *const r073B = sub(body.constant(int(31)), r073A);
                        ir_expression *const r073C = expr(ir_triop_csel, r0739, body.constant(int(32)), r073B);
                        body.emit(assign(r0731, add(r073C, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r073E = gequal(r0731, body.constant(int(0)));
                        ir_if *f073D = new(mem_ctx) ir_if(operand(r073E).val);
                        exec_list *const f073D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f073D->then_instructions;

                           body.emit(assign(r0730, body.constant(0u), 0x01));

                           ir_expression *const r073F = equal(r0731, body.constant(int(0)));
                           ir_expression *const r0740 = lshift(r0737, r0731);
                           ir_expression *const r0741 = neg(r0731);
                           ir_expression *const r0742 = bit_and(r0741, body.constant(int(31)));
                           ir_expression *const r0743 = rshift(r0734, r0742);
                           ir_expression *const r0744 = bit_or(r0740, r0743);
                           body.emit(assign(r072E, expr(ir_triop_csel, r073F, r0737, r0744), 0x01));

                           body.emit(assign(r072F, lshift(r0734, r0731), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f073D->else_instructions;

                           ir_variable *const r0745 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0745, neg(r0731), 0x01));

                           ir_variable *const r0746 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           ir_variable *const r0747 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0747);
                           ir_variable *const r0748 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0749 = neg(r0745);
                           body.emit(assign(r0748, bit_and(r0749, body.constant(int(31))), 0x01));

                           ir_variable *const r074A = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r074B = less(r0745, body.constant(int(32)));
                           ir_expression *const r074C = bit_or(body.constant(0u), r072F);
                           body.emit(assign(r074A, expr(ir_triop_csel, r074B, body.constant(0u), r074C), 0x01));

                           ir_expression *const r074D = less(r0745, body.constant(int(32)));
                           ir_expression *const r074E = lshift(r072F, r0748);
                           ir_expression *const r074F = less(r0745, body.constant(int(64)));
                           ir_expression *const r0750 = lshift(r072E, r0748);
                           ir_expression *const r0751 = equal(r0745, body.constant(int(64)));
                           ir_expression *const r0752 = nequal(r072E, body.constant(0u));
                           ir_expression *const r0753 = expr(ir_unop_b2i, r0752);
                           ir_expression *const r0754 = expr(ir_unop_i2u, r0753);
                           ir_expression *const r0755 = expr(ir_triop_csel, r0751, r072E, r0754);
                           ir_expression *const r0756 = expr(ir_triop_csel, r074F, r0750, r0755);
                           ir_expression *const r0757 = expr(ir_triop_csel, r074D, r074E, r0756);
                           ir_expression *const r0758 = nequal(r074A, body.constant(0u));
                           ir_expression *const r0759 = expr(ir_unop_b2i, r0758);
                           ir_expression *const r075A = expr(ir_unop_i2u, r0759);
                           body.emit(assign(r0747, bit_or(r0757, r075A), 0x01));

                           ir_variable *const r075B = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r075C = equal(r0745, body.constant(int(0)));
                           ir_expression *const r075D = equal(r0745, body.constant(int(32)));
                           ir_expression *const r075E = expr(ir_triop_csel, r075D, r072F, r0747);
                           body.emit(assign(r075B, expr(ir_triop_csel, r075C, r074A, r075E), 0x01));

                           body.emit(assign(r0747, r075B, 0x01));

                           ir_expression *const r075F = equal(r0745, body.constant(int(0)));
                           ir_expression *const r0760 = equal(r0745, body.constant(int(32)));
                           ir_expression *const r0761 = less(r0745, body.constant(int(32)));
                           ir_expression *const r0762 = lshift(r072E, r0748);
                           ir_expression *const r0763 = rshift(r072F, r0745);
                           ir_expression *const r0764 = bit_or(r0762, r0763);
                           ir_expression *const r0765 = less(r0745, body.constant(int(64)));
                           ir_expression *const r0766 = bit_and(r0745, body.constant(int(31)));
                           ir_expression *const r0767 = rshift(r072E, r0766);
                           ir_expression *const r0768 = expr(ir_triop_csel, r0765, r0767, body.constant(0u));
                           ir_expression *const r0769 = expr(ir_triop_csel, r0761, r0764, r0768);
                           ir_expression *const r076A = expr(ir_triop_csel, r0760, r072E, r0769);
                           body.emit(assign(r0746, expr(ir_triop_csel, r075F, r072F, r076A), 0x01));

                           ir_expression *const r076B = equal(r0745, body.constant(int(0)));
                           ir_expression *const r076C = equal(r0745, body.constant(int(32)));
                           ir_expression *const r076D = less(r0745, body.constant(int(32)));
                           ir_expression *const r076E = rshift(r072E, r0745);
                           ir_expression *const r076F = expr(ir_triop_csel, r076D, r076E, body.constant(0u));
                           ir_expression *const r0770 = expr(ir_triop_csel, r076C, body.constant(0u), r076F);
                           body.emit(assign(r072E, expr(ir_triop_csel, r076B, r072E, r0770), 0x01));

                           body.emit(assign(r072F, r0746, 0x01));

                           body.emit(assign(r0730, r075B, 0x01));


                        body.instructions = f073D_parent_instructions;
                        body.emit(f073D);

                        /* END IF */

                        body.emit(assign(r072D, sub(r072D, r0731), 0x01));

                        ir_variable *const r0771 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0771, r072D, 0x01));

                        ir_variable *const r0772 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r0772, r072E, 0x01));

                        ir_variable *const r0773 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0773, r072F, 0x01));

                        ir_variable *const r0774 = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r0774, r0730, 0x01));

                        ir_variable *const r0775 = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r0775, body.constant(true), 0x01));

                        ir_variable *const r0776 = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r0777 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r0777);
                        ir_expression *const r0778 = expr(ir_unop_u2i, r0730);
                        body.emit(assign(r0777, less(r0778, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r077A = gequal(r072D, body.constant(int(2045)));
                        ir_if *f0779 = new(mem_ctx) ir_if(operand(r077A).val);
                        exec_list *const f0779_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0779->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r077C = less(body.constant(int(2045)), r072D);
                           ir_expression *const r077D = equal(r072D, body.constant(int(2045)));
                           ir_expression *const r077E = equal(body.constant(2097151u), r072E);
                           ir_expression *const r077F = equal(body.constant(4294967295u), r072F);
                           ir_expression *const r0780 = logic_and(r077E, r077F);
                           ir_expression *const r0781 = logic_and(r077D, r0780);
                           ir_expression *const r0782 = logic_and(r0781, r0777);
                           ir_expression *const r0783 = logic_or(r077C, r0782);
                           ir_if *f077B = new(mem_ctx) ir_if(operand(r0783).val);
                           exec_list *const f077B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f077B->then_instructions;

                              ir_variable *const r0784 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0784);
                              ir_expression *const r0785 = lshift(r0218, body.constant(int(31)));
                              body.emit(assign(r0784, add(r0785, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r0784, body.constant(0u), 0x01));

                              body.emit(assign(r0776, r0784, 0x03));

                              body.emit(assign(r0775, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f077B->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0787 = less(r072D, body.constant(int(0)));
                              ir_if *f0786 = new(mem_ctx) ir_if(operand(r0787).val);
                              exec_list *const f0786_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0786->then_instructions;

                                 ir_variable *const r0788 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r0788, neg(r072D), 0x01));

                                 ir_variable *const r0789 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r0789);
                                 ir_variable *const r078A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r078B = neg(r0788);
                                 body.emit(assign(r078A, bit_and(r078B, body.constant(int(31))), 0x01));

                                 ir_variable *const r078C = body.make_temp(glsl_type::uint_type, "mix_retval");
                                 ir_expression *const r078D = less(r0788, body.constant(int(32)));
                                 ir_expression *const r078E = bit_or(r0730, r072F);
                                 body.emit(assign(r078C, expr(ir_triop_csel, r078D, r0730, r078E), 0x01));

                                 ir_expression *const r078F = less(r0788, body.constant(int(32)));
                                 ir_expression *const r0790 = lshift(r072F, r078A);
                                 ir_expression *const r0791 = less(r0788, body.constant(int(64)));
                                 ir_expression *const r0792 = lshift(r072E, r078A);
                                 ir_expression *const r0793 = equal(r0788, body.constant(int(64)));
                                 ir_expression *const r0794 = nequal(r072E, body.constant(0u));
                                 ir_expression *const r0795 = expr(ir_unop_b2i, r0794);
                                 ir_expression *const r0796 = expr(ir_unop_i2u, r0795);
                                 ir_expression *const r0797 = expr(ir_triop_csel, r0793, r072E, r0796);
                                 ir_expression *const r0798 = expr(ir_triop_csel, r0791, r0792, r0797);
                                 ir_expression *const r0799 = expr(ir_triop_csel, r078F, r0790, r0798);
                                 ir_expression *const r079A = nequal(r078C, body.constant(0u));
                                 ir_expression *const r079B = expr(ir_unop_b2i, r079A);
                                 ir_expression *const r079C = expr(ir_unop_i2u, r079B);
                                 body.emit(assign(r0789, bit_or(r0799, r079C), 0x01));

                                 ir_variable *const r079D = body.make_temp(glsl_type::uint_type, "mix_retval");
                                 ir_expression *const r079E = equal(r0788, body.constant(int(0)));
                                 ir_expression *const r079F = equal(r0788, body.constant(int(32)));
                                 ir_expression *const r07A0 = expr(ir_triop_csel, r079F, r072F, r0789);
                                 body.emit(assign(r079D, expr(ir_triop_csel, r079E, r078C, r07A0), 0x01));

                                 body.emit(assign(r0789, r079D, 0x01));

                                 ir_expression *const r07A1 = equal(r0788, body.constant(int(0)));
                                 ir_expression *const r07A2 = equal(r0788, body.constant(int(32)));
                                 ir_expression *const r07A3 = less(r0788, body.constant(int(32)));
                                 ir_expression *const r07A4 = rshift(r072E, r0788);
                                 ir_expression *const r07A5 = expr(ir_triop_csel, r07A3, r07A4, body.constant(0u));
                                 ir_expression *const r07A6 = expr(ir_triop_csel, r07A2, body.constant(0u), r07A5);
                                 body.emit(assign(r0772, expr(ir_triop_csel, r07A1, r072E, r07A6), 0x01));

                                 ir_expression *const r07A7 = equal(r0788, body.constant(int(0)));
                                 ir_expression *const r07A8 = equal(r0788, body.constant(int(32)));
                                 ir_expression *const r07A9 = less(r0788, body.constant(int(32)));
                                 ir_expression *const r07AA = lshift(r072E, r078A);
                                 ir_expression *const r07AB = rshift(r072F, r0788);
                                 ir_expression *const r07AC = bit_or(r07AA, r07AB);
                                 ir_expression *const r07AD = less(r0788, body.constant(int(64)));
                                 ir_expression *const r07AE = bit_and(r0788, body.constant(int(31)));
                                 ir_expression *const r07AF = rshift(r072E, r07AE);
                                 ir_expression *const r07B0 = expr(ir_triop_csel, r07AD, r07AF, body.constant(0u));
                                 ir_expression *const r07B1 = expr(ir_triop_csel, r07A9, r07AC, r07B0);
                                 ir_expression *const r07B2 = expr(ir_triop_csel, r07A8, r072E, r07B1);
                                 body.emit(assign(r0773, expr(ir_triop_csel, r07A7, r072F, r07B2), 0x01));

                                 body.emit(assign(r0774, r079D, 0x01));

                                 body.emit(assign(r0771, body.constant(int(0)), 0x01));

                                 body.emit(assign(r0777, less(r079D, body.constant(0u)), 0x01));


                              body.instructions = f0786_parent_instructions;
                              body.emit(f0786);

                              /* END IF */


                           body.instructions = f077B_parent_instructions;
                           body.emit(f077B);

                           /* END IF */


                        body.instructions = f0779_parent_instructions;
                        body.emit(f0779);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f07B3 = new(mem_ctx) ir_if(operand(r0775).val);
                        exec_list *const f07B3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f07B3->then_instructions;

                           /* IF CONDITION */
                           ir_if *f07B4 = new(mem_ctx) ir_if(operand(r0777).val);
                           exec_list *const f07B4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07B4->then_instructions;

                              ir_variable *const r07B5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r07B5, add(r0773, body.constant(1u)), 0x01));

                              ir_expression *const r07B6 = less(r07B5, r0773);
                              ir_expression *const r07B7 = expr(ir_unop_b2i, r07B6);
                              ir_expression *const r07B8 = expr(ir_unop_i2u, r07B7);
                              body.emit(assign(r0772, add(r0772, r07B8), 0x01));

                              ir_expression *const r07B9 = equal(r0774, body.constant(0u));
                              ir_expression *const r07BA = expr(ir_unop_b2i, r07B9);
                              ir_expression *const r07BB = expr(ir_unop_i2u, r07BA);
                              ir_expression *const r07BC = add(r0774, r07BB);
                              ir_expression *const r07BD = bit_and(r07BC, body.constant(1u));
                              ir_expression *const r07BE = expr(ir_unop_bit_not, r07BD);
                              body.emit(assign(r0773, bit_and(r07B5, r07BE), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f07B4->else_instructions;

                              ir_expression *const r07BF = bit_or(r0772, r0773);
                              ir_expression *const r07C0 = equal(r07BF, body.constant(0u));
                              body.emit(assign(r0771, expr(ir_triop_csel, r07C0, body.constant(int(0)), r0771), 0x01));


                           body.instructions = f07B4_parent_instructions;
                           body.emit(f07B4);

                           /* END IF */

                           ir_variable *const r07C1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r07C1);
                           ir_expression *const r07C2 = lshift(r0218, body.constant(int(31)));
                           ir_expression *const r07C3 = expr(ir_unop_i2u, r0771);
                           ir_expression *const r07C4 = lshift(r07C3, body.constant(int(20)));
                           ir_expression *const r07C5 = add(r07C2, r07C4);
                           body.emit(assign(r07C1, add(r07C5, r0772), 0x02));

                           body.emit(assign(r07C1, r0773, 0x01));

                           body.emit(assign(r0776, r07C1, 0x03));

                           body.emit(assign(r0775, body.constant(false), 0x01));


                        body.instructions = f07B3_parent_instructions;
                        body.emit(f07B3);

                        /* END IF */

                        body.emit(assign(r020F, r0776, 0x03));

                        body.emit(assign(r020E, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0726->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r07C7 = less(r0217, r0215);
                        ir_if *f07C6 = new(mem_ctx) ir_if(operand(r07C7).val);
                        exec_list *const f07C6_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f07C6->then_instructions;

                           ir_variable *const r07C8 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_expression *const r07C9 = sub(r0214, r0216);
                           ir_expression *const r07CA = less(r0215, r0217);
                           ir_expression *const r07CB = expr(ir_unop_b2i, r07CA);
                           ir_expression *const r07CC = expr(ir_unop_i2u, r07CB);
                           body.emit(assign(r07C8, sub(r07C9, r07CC), 0x01));

                           body.emit(assign(r0211, r07C8, 0x01));

                           body.emit(assign(r0218, bit_xor(r0218, body.constant(1u)), 0x01));

                           body.emit(assign(r03F7, add(r0212, body.constant(int(-1))), 0x01));

                           ir_variable *const r07CD = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r07CD, add(r03F7, body.constant(int(-10))), 0x01));

                           ir_variable *const r07CE = body.make_temp(glsl_type::uint_type, "zFrac0");
                           ir_variable *const r07CF = body.make_temp(glsl_type::uint_type, "zFrac1");
                           ir_variable *const r07D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r07D0);
                           ir_variable *const r07D1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r07D1);
                           ir_expression *const r07D2 = equal(r07C8, body.constant(0u));
                           ir_expression *const r07D3 = add(r07CD, body.constant(int(-32)));
                           body.emit(assign(r07CD, expr(ir_triop_csel, r07D2, r07D3, r07CD), 0x01));

                           ir_variable *const r07D4 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r07D5 = equal(r07C8, body.constant(0u));
                           ir_expression *const r07D6 = sub(r0215, r0217);
                           body.emit(assign(r07D4, expr(ir_triop_csel, r07D5, body.constant(0u), r07D6), 0x01));

                           body.emit(assign(r07CF, r07D4, 0x01));

                           ir_variable *const r07D7 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r07D8 = equal(r07C8, body.constant(0u));
                           body.emit(assign(r07D7, expr(ir_triop_csel, r07D8, r07D4, r07C8), 0x01));

                           body.emit(assign(r07CE, r07D7, 0x01));

                           ir_expression *const r07D9 = equal(r07D7, body.constant(0u));
                           ir_expression *const r07DA = expr(ir_unop_find_msb, r07D7);
                           ir_expression *const r07DB = sub(body.constant(int(31)), r07DA);
                           ir_expression *const r07DC = expr(ir_triop_csel, r07D9, body.constant(int(32)), r07DB);
                           body.emit(assign(r07D1, add(r07DC, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r07DE = gequal(r07D1, body.constant(int(0)));
                           ir_if *f07DD = new(mem_ctx) ir_if(operand(r07DE).val);
                           exec_list *const f07DD_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07DD->then_instructions;

                              body.emit(assign(r07D0, body.constant(0u), 0x01));

                              ir_expression *const r07DF = equal(r07D1, body.constant(int(0)));
                              ir_expression *const r07E0 = lshift(r07D7, r07D1);
                              ir_expression *const r07E1 = neg(r07D1);
                              ir_expression *const r07E2 = bit_and(r07E1, body.constant(int(31)));
                              ir_expression *const r07E3 = rshift(r07D4, r07E2);
                              ir_expression *const r07E4 = bit_or(r07E0, r07E3);
                              body.emit(assign(r07CE, expr(ir_triop_csel, r07DF, r07D7, r07E4), 0x01));

                              body.emit(assign(r07CF, lshift(r07D4, r07D1), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f07DD->else_instructions;

                              ir_variable *const r07E5 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r07E5, neg(r07D1), 0x01));

                              ir_variable *const r07E6 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                              ir_variable *const r07E7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r07E7);
                              ir_variable *const r07E8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r07E9 = neg(r07E5);
                              body.emit(assign(r07E8, bit_and(r07E9, body.constant(int(31))), 0x01));

                              ir_variable *const r07EA = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r07EB = less(r07E5, body.constant(int(32)));
                              ir_expression *const r07EC = bit_or(body.constant(0u), r07CF);
                              body.emit(assign(r07EA, expr(ir_triop_csel, r07EB, body.constant(0u), r07EC), 0x01));

                              ir_expression *const r07ED = less(r07E5, body.constant(int(32)));
                              ir_expression *const r07EE = lshift(r07CF, r07E8);
                              ir_expression *const r07EF = less(r07E5, body.constant(int(64)));
                              ir_expression *const r07F0 = lshift(r07CE, r07E8);
                              ir_expression *const r07F1 = equal(r07E5, body.constant(int(64)));
                              ir_expression *const r07F2 = nequal(r07CE, body.constant(0u));
                              ir_expression *const r07F3 = expr(ir_unop_b2i, r07F2);
                              ir_expression *const r07F4 = expr(ir_unop_i2u, r07F3);
                              ir_expression *const r07F5 = expr(ir_triop_csel, r07F1, r07CE, r07F4);
                              ir_expression *const r07F6 = expr(ir_triop_csel, r07EF, r07F0, r07F5);
                              ir_expression *const r07F7 = expr(ir_triop_csel, r07ED, r07EE, r07F6);
                              ir_expression *const r07F8 = nequal(r07EA, body.constant(0u));
                              ir_expression *const r07F9 = expr(ir_unop_b2i, r07F8);
                              ir_expression *const r07FA = expr(ir_unop_i2u, r07F9);
                              body.emit(assign(r07E7, bit_or(r07F7, r07FA), 0x01));

                              ir_variable *const r07FB = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r07FC = equal(r07E5, body.constant(int(0)));
                              ir_expression *const r07FD = equal(r07E5, body.constant(int(32)));
                              ir_expression *const r07FE = expr(ir_triop_csel, r07FD, r07CF, r07E7);
                              body.emit(assign(r07FB, expr(ir_triop_csel, r07FC, r07EA, r07FE), 0x01));

                              body.emit(assign(r07E7, r07FB, 0x01));

                              ir_expression *const r07FF = equal(r07E5, body.constant(int(0)));
                              ir_expression *const r0800 = equal(r07E5, body.constant(int(32)));
                              ir_expression *const r0801 = less(r07E5, body.constant(int(32)));
                              ir_expression *const r0802 = lshift(r07CE, r07E8);
                              ir_expression *const r0803 = rshift(r07CF, r07E5);
                              ir_expression *const r0804 = bit_or(r0802, r0803);
                              ir_expression *const r0805 = less(r07E5, body.constant(int(64)));
                              ir_expression *const r0806 = bit_and(r07E5, body.constant(int(31)));
                              ir_expression *const r0807 = rshift(r07CE, r0806);
                              ir_expression *const r0808 = expr(ir_triop_csel, r0805, r0807, body.constant(0u));
                              ir_expression *const r0809 = expr(ir_triop_csel, r0801, r0804, r0808);
                              ir_expression *const r080A = expr(ir_triop_csel, r0800, r07CE, r0809);
                              body.emit(assign(r07E6, expr(ir_triop_csel, r07FF, r07CF, r080A), 0x01));

                              ir_expression *const r080B = equal(r07E5, body.constant(int(0)));
                              ir_expression *const r080C = equal(r07E5, body.constant(int(32)));
                              ir_expression *const r080D = less(r07E5, body.constant(int(32)));
                              ir_expression *const r080E = rshift(r07CE, r07E5);
                              ir_expression *const r080F = expr(ir_triop_csel, r080D, r080E, body.constant(0u));
                              ir_expression *const r0810 = expr(ir_triop_csel, r080C, body.constant(0u), r080F);
                              body.emit(assign(r07CE, expr(ir_triop_csel, r080B, r07CE, r0810), 0x01));

                              body.emit(assign(r07CF, r07E6, 0x01));

                              body.emit(assign(r07D0, r07FB, 0x01));


                           body.instructions = f07DD_parent_instructions;
                           body.emit(f07DD);

                           /* END IF */

                           body.emit(assign(r07CD, sub(r07CD, r07D1), 0x01));

                           ir_variable *const r0811 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r0811, r07CD, 0x01));

                           ir_variable *const r0812 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r0812, r07CE, 0x01));

                           ir_variable *const r0813 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r0813, r07CF, 0x01));

                           ir_variable *const r0814 = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r0814, r07D0, 0x01));

                           ir_variable *const r0815 = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r0815, body.constant(true), 0x01));

                           ir_variable *const r0816 = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r0817 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r0817);
                           ir_expression *const r0818 = expr(ir_unop_u2i, r07D0);
                           body.emit(assign(r0817, less(r0818, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r081A = gequal(r07CD, body.constant(int(2045)));
                           ir_if *f0819 = new(mem_ctx) ir_if(operand(r081A).val);
                           exec_list *const f0819_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0819->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r081C = less(body.constant(int(2045)), r07CD);
                              ir_expression *const r081D = equal(r07CD, body.constant(int(2045)));
                              ir_expression *const r081E = equal(body.constant(2097151u), r07CE);
                              ir_expression *const r081F = equal(body.constant(4294967295u), r07CF);
                              ir_expression *const r0820 = logic_and(r081E, r081F);
                              ir_expression *const r0821 = logic_and(r081D, r0820);
                              ir_expression *const r0822 = logic_and(r0821, r0817);
                              ir_expression *const r0823 = logic_or(r081C, r0822);
                              ir_if *f081B = new(mem_ctx) ir_if(operand(r0823).val);
                              exec_list *const f081B_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f081B->then_instructions;

                                 ir_variable *const r0824 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r0824);
                                 ir_expression *const r0825 = lshift(r0218, body.constant(int(31)));
                                 body.emit(assign(r0824, add(r0825, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r0824, body.constant(0u), 0x01));

                                 body.emit(assign(r0816, r0824, 0x03));

                                 body.emit(assign(r0815, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f081B->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0827 = less(r07CD, body.constant(int(0)));
                                 ir_if *f0826 = new(mem_ctx) ir_if(operand(r0827).val);
                                 exec_list *const f0826_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0826->then_instructions;

                                    ir_variable *const r0828 = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r0828, neg(r07CD), 0x01));

                                    ir_variable *const r0829 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r0829);
                                    ir_variable *const r082A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r082B = neg(r0828);
                                    body.emit(assign(r082A, bit_and(r082B, body.constant(int(31))), 0x01));

                                    ir_variable *const r082C = body.make_temp(glsl_type::uint_type, "mix_retval");
                                    ir_expression *const r082D = less(r0828, body.constant(int(32)));
                                    ir_expression *const r082E = bit_or(r07D0, r07CF);
                                    body.emit(assign(r082C, expr(ir_triop_csel, r082D, r07D0, r082E), 0x01));

                                    ir_expression *const r082F = less(r0828, body.constant(int(32)));
                                    ir_expression *const r0830 = lshift(r07CF, r082A);
                                    ir_expression *const r0831 = less(r0828, body.constant(int(64)));
                                    ir_expression *const r0832 = lshift(r07CE, r082A);
                                    ir_expression *const r0833 = equal(r0828, body.constant(int(64)));
                                    ir_expression *const r0834 = nequal(r07CE, body.constant(0u));
                                    ir_expression *const r0835 = expr(ir_unop_b2i, r0834);
                                    ir_expression *const r0836 = expr(ir_unop_i2u, r0835);
                                    ir_expression *const r0837 = expr(ir_triop_csel, r0833, r07CE, r0836);
                                    ir_expression *const r0838 = expr(ir_triop_csel, r0831, r0832, r0837);
                                    ir_expression *const r0839 = expr(ir_triop_csel, r082F, r0830, r0838);
                                    ir_expression *const r083A = nequal(r082C, body.constant(0u));
                                    ir_expression *const r083B = expr(ir_unop_b2i, r083A);
                                    ir_expression *const r083C = expr(ir_unop_i2u, r083B);
                                    body.emit(assign(r0829, bit_or(r0839, r083C), 0x01));

                                    ir_variable *const r083D = body.make_temp(glsl_type::uint_type, "mix_retval");
                                    ir_expression *const r083E = equal(r0828, body.constant(int(0)));
                                    ir_expression *const r083F = equal(r0828, body.constant(int(32)));
                                    ir_expression *const r0840 = expr(ir_triop_csel, r083F, r07CF, r0829);
                                    body.emit(assign(r083D, expr(ir_triop_csel, r083E, r082C, r0840), 0x01));

                                    body.emit(assign(r0829, r083D, 0x01));

                                    ir_expression *const r0841 = equal(r0828, body.constant(int(0)));
                                    ir_expression *const r0842 = equal(r0828, body.constant(int(32)));
                                    ir_expression *const r0843 = less(r0828, body.constant(int(32)));
                                    ir_expression *const r0844 = rshift(r07CE, r0828);
                                    ir_expression *const r0845 = expr(ir_triop_csel, r0843, r0844, body.constant(0u));
                                    ir_expression *const r0846 = expr(ir_triop_csel, r0842, body.constant(0u), r0845);
                                    body.emit(assign(r0812, expr(ir_triop_csel, r0841, r07CE, r0846), 0x01));

                                    ir_expression *const r0847 = equal(r0828, body.constant(int(0)));
                                    ir_expression *const r0848 = equal(r0828, body.constant(int(32)));
                                    ir_expression *const r0849 = less(r0828, body.constant(int(32)));
                                    ir_expression *const r084A = lshift(r07CE, r082A);
                                    ir_expression *const r084B = rshift(r07CF, r0828);
                                    ir_expression *const r084C = bit_or(r084A, r084B);
                                    ir_expression *const r084D = less(r0828, body.constant(int(64)));
                                    ir_expression *const r084E = bit_and(r0828, body.constant(int(31)));
                                    ir_expression *const r084F = rshift(r07CE, r084E);
                                    ir_expression *const r0850 = expr(ir_triop_csel, r084D, r084F, body.constant(0u));
                                    ir_expression *const r0851 = expr(ir_triop_csel, r0849, r084C, r0850);
                                    ir_expression *const r0852 = expr(ir_triop_csel, r0848, r07CE, r0851);
                                    body.emit(assign(r0813, expr(ir_triop_csel, r0847, r07CF, r0852), 0x01));

                                    body.emit(assign(r0814, r083D, 0x01));

                                    body.emit(assign(r0811, body.constant(int(0)), 0x01));

                                    body.emit(assign(r0817, less(r083D, body.constant(0u)), 0x01));


                                 body.instructions = f0826_parent_instructions;
                                 body.emit(f0826);

                                 /* END IF */


                              body.instructions = f081B_parent_instructions;
                              body.emit(f081B);

                              /* END IF */


                           body.instructions = f0819_parent_instructions;
                           body.emit(f0819);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f0853 = new(mem_ctx) ir_if(operand(r0815).val);
                           exec_list *const f0853_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0853->then_instructions;

                              /* IF CONDITION */
                              ir_if *f0854 = new(mem_ctx) ir_if(operand(r0817).val);
                              exec_list *const f0854_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0854->then_instructions;

                                 ir_variable *const r0855 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r0855, add(r0813, body.constant(1u)), 0x01));

                                 ir_expression *const r0856 = less(r0855, r0813);
                                 ir_expression *const r0857 = expr(ir_unop_b2i, r0856);
                                 ir_expression *const r0858 = expr(ir_unop_i2u, r0857);
                                 body.emit(assign(r0812, add(r0812, r0858), 0x01));

                                 ir_expression *const r0859 = equal(r0814, body.constant(0u));
                                 ir_expression *const r085A = expr(ir_unop_b2i, r0859);
                                 ir_expression *const r085B = expr(ir_unop_i2u, r085A);
                                 ir_expression *const r085C = add(r0814, r085B);
                                 ir_expression *const r085D = bit_and(r085C, body.constant(1u));
                                 ir_expression *const r085E = expr(ir_unop_bit_not, r085D);
                                 body.emit(assign(r0813, bit_and(r0855, r085E), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0854->else_instructions;

                                 ir_expression *const r085F = bit_or(r0812, r0813);
                                 ir_expression *const r0860 = equal(r085F, body.constant(0u));
                                 body.emit(assign(r0811, expr(ir_triop_csel, r0860, body.constant(int(0)), r0811), 0x01));


                              body.instructions = f0854_parent_instructions;
                              body.emit(f0854);

                              /* END IF */

                              ir_variable *const r0861 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0861);
                              ir_expression *const r0862 = lshift(r0218, body.constant(int(31)));
                              ir_expression *const r0863 = expr(ir_unop_i2u, r0811);
                              ir_expression *const r0864 = lshift(r0863, body.constant(int(20)));
                              ir_expression *const r0865 = add(r0862, r0864);
                              body.emit(assign(r0861, add(r0865, r0812), 0x02));

                              body.emit(assign(r0861, r0813, 0x01));

                              body.emit(assign(r0816, r0861, 0x03));

                              body.emit(assign(r0815, body.constant(false), 0x01));


                           body.instructions = f0853_parent_instructions;
                           body.emit(f0853);

                           /* END IF */

                           body.emit(assign(r020F, r0816, 0x03));

                           body.emit(assign(r020E, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f07C6->else_instructions;

                           ir_variable *const r0866 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0866);
                           body.emit(assign(r0866, body.constant(0u), 0x02));

                           body.emit(assign(r0866, body.constant(0u), 0x01));

                           body.emit(assign(r020F, r0866, 0x03));

                           body.emit(assign(r020E, body.constant(false), 0x01));


                        body.instructions = f07C6_parent_instructions;
                        body.emit(f07C6);

                        /* END IF */


                     body.instructions = f0726_parent_instructions;
                     body.emit(f0726);

                     /* END IF */


                  body.instructions = f0686_parent_instructions;
                  body.emit(f0686);

                  /* END IF */


               body.instructions = f05E6_parent_instructions;
               body.emit(f05E6);

               /* END IF */


            body.instructions = f05C8_parent_instructions;
            body.emit(f05C8);

            /* END IF */


         body.instructions = f04E2_parent_instructions;
         body.emit(f04E2);

         /* END IF */


      body.instructions = f0400_parent_instructions;
      body.emit(f0400);

      /* END IF */


   body.instructions = f0224_parent_instructions;
   body.emit(f0224);

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

   ir_variable *const r0867 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0867);
   ir_variable *const r0868 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0868);
   ir_variable *const r0869 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0869);
   ir_variable *const r086A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r086A);
   ir_variable *const r086B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r086B);
   ir_variable *const r086C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r086C);
   ir_variable *const r086D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r086D);
   ir_variable *const r086E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r086E, bit_and(r0867, body.constant(65535u)), 0x01));

   ir_variable *const r086F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r086F, rshift(r0867, body.constant(int(16))), 0x01));

   ir_variable *const r0870 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0870, bit_and(r0868, body.constant(65535u)), 0x01));

   ir_variable *const r0871 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0871, rshift(r0868, body.constant(int(16))), 0x01));

   ir_variable *const r0872 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0872, mul(r086F, r0870), 0x01));

   ir_expression *const r0873 = mul(r086E, r0871);
   body.emit(assign(r086C, add(r0873, r0872), 0x01));

   ir_expression *const r0874 = mul(r086F, r0871);
   ir_expression *const r0875 = less(r086C, r0872);
   ir_expression *const r0876 = expr(ir_unop_b2i, r0875);
   ir_expression *const r0877 = expr(ir_unop_i2u, r0876);
   ir_expression *const r0878 = lshift(r0877, body.constant(int(16)));
   ir_expression *const r0879 = rshift(r086C, body.constant(int(16)));
   ir_expression *const r087A = add(r0878, r0879);
   body.emit(assign(r086B, add(r0874, r087A), 0x01));

   body.emit(assign(r086C, lshift(r086C, body.constant(int(16))), 0x01));

   ir_expression *const r087B = mul(r086E, r0870);
   body.emit(assign(r086D, add(r087B, r086C), 0x01));

   ir_expression *const r087C = less(r086D, r086C);
   ir_expression *const r087D = expr(ir_unop_b2i, r087C);
   ir_expression *const r087E = expr(ir_unop_i2u, r087D);
   body.emit(assign(r086B, add(r086B, r087E), 0x01));

   body.emit(assign(r086A, r086D, 0x01));

   body.emit(assign(r0869, r086B, 0x01));

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

   ir_variable *const r087F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r087F);
   ir_variable *const r0880 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0880);
   ir_variable *const r0881 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0881);
   ir_variable *const r0882 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0882);
   ir_variable *const r0883 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0883);
   ir_variable *const r0884 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0884);
   ir_variable *const r0885 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0885);
   ir_variable *const r0886 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0886);
   ir_variable *const r0887 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0887);
   ir_variable *const r0888 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0888);
   ir_variable *const r0889 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0889);
   ir_variable *const r088A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r088A, bit_and(r0880, body.constant(65535u)), 0x01));

   ir_variable *const r088B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r088B, rshift(r0880, body.constant(int(16))), 0x01));

   ir_variable *const r088C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r088C, bit_and(r0882, body.constant(65535u)), 0x01));

   ir_variable *const r088D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r088D, rshift(r0882, body.constant(int(16))), 0x01));

   ir_variable *const r088E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r088E, mul(r088B, r088C), 0x01));

   ir_expression *const r088F = mul(r088A, r088D);
   body.emit(assign(r0888, add(r088F, r088E), 0x01));

   ir_expression *const r0890 = mul(r088B, r088D);
   ir_expression *const r0891 = less(r0888, r088E);
   ir_expression *const r0892 = expr(ir_unop_b2i, r0891);
   ir_expression *const r0893 = expr(ir_unop_i2u, r0892);
   ir_expression *const r0894 = lshift(r0893, body.constant(int(16)));
   ir_expression *const r0895 = rshift(r0888, body.constant(int(16)));
   ir_expression *const r0896 = add(r0894, r0895);
   body.emit(assign(r0887, add(r0890, r0896), 0x01));

   body.emit(assign(r0888, lshift(r0888, body.constant(int(16))), 0x01));

   ir_expression *const r0897 = mul(r088A, r088C);
   body.emit(assign(r0889, add(r0897, r0888), 0x01));

   ir_expression *const r0898 = less(r0889, r0888);
   ir_expression *const r0899 = expr(ir_unop_b2i, r0898);
   ir_expression *const r089A = expr(ir_unop_i2u, r0899);
   body.emit(assign(r0887, add(r0887, r089A), 0x01));

   ir_variable *const r089B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r089B);
   ir_variable *const r089C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r089C);
   ir_variable *const r089D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r089D);
   ir_variable *const r089E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r089E, bit_and(r0880, body.constant(65535u)), 0x01));

   ir_variable *const r089F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r089F, rshift(r0880, body.constant(int(16))), 0x01));

   ir_variable *const r08A0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08A0, bit_and(r0881, body.constant(65535u)), 0x01));

   ir_variable *const r08A1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08A1, rshift(r0881, body.constant(int(16))), 0x01));

   ir_variable *const r08A2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08A2, mul(r089F, r08A0), 0x01));

   ir_expression *const r08A3 = mul(r089E, r08A1);
   body.emit(assign(r089C, add(r08A3, r08A2), 0x01));

   ir_expression *const r08A4 = mul(r089F, r08A1);
   ir_expression *const r08A5 = less(r089C, r08A2);
   ir_expression *const r08A6 = expr(ir_unop_b2i, r08A5);
   ir_expression *const r08A7 = expr(ir_unop_i2u, r08A6);
   ir_expression *const r08A8 = lshift(r08A7, body.constant(int(16)));
   ir_expression *const r08A9 = rshift(r089C, body.constant(int(16)));
   ir_expression *const r08AA = add(r08A8, r08A9);
   body.emit(assign(r089B, add(r08A4, r08AA), 0x01));

   body.emit(assign(r089C, lshift(r089C, body.constant(int(16))), 0x01));

   ir_expression *const r08AB = mul(r089E, r08A0);
   body.emit(assign(r089D, add(r08AB, r089C), 0x01));

   ir_expression *const r08AC = less(r089D, r089C);
   ir_expression *const r08AD = expr(ir_unop_b2i, r08AC);
   ir_expression *const r08AE = expr(ir_unop_i2u, r08AD);
   body.emit(assign(r089B, add(r089B, r08AE), 0x01));

   ir_variable *const r08AF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08AF, add(r089D, r0887), 0x01));

   ir_variable *const r08B0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r08B0);
   ir_variable *const r08B1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r08B1);
   ir_variable *const r08B2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r08B2);
   ir_variable *const r08B3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08B3, bit_and(r087F, body.constant(65535u)), 0x01));

   ir_variable *const r08B4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08B4, rshift(r087F, body.constant(int(16))), 0x01));

   ir_variable *const r08B5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08B5, bit_and(r0881, body.constant(65535u)), 0x01));

   ir_variable *const r08B6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08B6, rshift(r0881, body.constant(int(16))), 0x01));

   ir_variable *const r08B7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08B7, mul(r08B4, r08B5), 0x01));

   ir_expression *const r08B8 = mul(r08B3, r08B6);
   body.emit(assign(r08B1, add(r08B8, r08B7), 0x01));

   ir_expression *const r08B9 = mul(r08B4, r08B6);
   ir_expression *const r08BA = less(r08B1, r08B7);
   ir_expression *const r08BB = expr(ir_unop_b2i, r08BA);
   ir_expression *const r08BC = expr(ir_unop_i2u, r08BB);
   ir_expression *const r08BD = lshift(r08BC, body.constant(int(16)));
   ir_expression *const r08BE = rshift(r08B1, body.constant(int(16)));
   ir_expression *const r08BF = add(r08BD, r08BE);
   body.emit(assign(r08B0, add(r08B9, r08BF), 0x01));

   body.emit(assign(r08B1, lshift(r08B1, body.constant(int(16))), 0x01));

   ir_expression *const r08C0 = mul(r08B3, r08B5);
   body.emit(assign(r08B2, add(r08C0, r08B1), 0x01));

   ir_expression *const r08C1 = less(r08B2, r08B1);
   ir_expression *const r08C2 = expr(ir_unop_b2i, r08C1);
   ir_expression *const r08C3 = expr(ir_unop_i2u, r08C2);
   body.emit(assign(r08B0, add(r08B0, r08C3), 0x01));

   ir_variable *const r08C4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r08C5 = less(r08AF, r089D);
   ir_expression *const r08C6 = expr(ir_unop_b2i, r08C5);
   ir_expression *const r08C7 = expr(ir_unop_i2u, r08C6);
   ir_expression *const r08C8 = add(r089B, r08C7);
   body.emit(assign(r08C4, add(r08B2, r08C8), 0x01));

   ir_variable *const r08C9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r08C9);
   ir_variable *const r08CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r08CA);
   ir_variable *const r08CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r08CB);
   ir_variable *const r08CC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08CC, bit_and(r087F, body.constant(65535u)), 0x01));

   ir_variable *const r08CD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08CD, rshift(r087F, body.constant(int(16))), 0x01));

   ir_variable *const r08CE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08CE, bit_and(r0882, body.constant(65535u)), 0x01));

   ir_variable *const r08CF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08CF, rshift(r0882, body.constant(int(16))), 0x01));

   ir_variable *const r08D0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08D0, mul(r08CD, r08CE), 0x01));

   ir_expression *const r08D1 = mul(r08CC, r08CF);
   body.emit(assign(r08CA, add(r08D1, r08D0), 0x01));

   ir_expression *const r08D2 = mul(r08CD, r08CF);
   ir_expression *const r08D3 = less(r08CA, r08D0);
   ir_expression *const r08D4 = expr(ir_unop_b2i, r08D3);
   ir_expression *const r08D5 = expr(ir_unop_i2u, r08D4);
   ir_expression *const r08D6 = lshift(r08D5, body.constant(int(16)));
   ir_expression *const r08D7 = rshift(r08CA, body.constant(int(16)));
   ir_expression *const r08D8 = add(r08D6, r08D7);
   body.emit(assign(r08C9, add(r08D2, r08D8), 0x01));

   body.emit(assign(r08CA, lshift(r08CA, body.constant(int(16))), 0x01));

   ir_expression *const r08D9 = mul(r08CC, r08CE);
   body.emit(assign(r08CB, add(r08D9, r08CA), 0x01));

   ir_expression *const r08DA = less(r08CB, r08CA);
   ir_expression *const r08DB = expr(ir_unop_b2i, r08DA);
   ir_expression *const r08DC = expr(ir_unop_i2u, r08DB);
   body.emit(assign(r08C9, add(r08C9, r08DC), 0x01));

   ir_variable *const r08DD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r08DD, add(r08CB, r08AF), 0x01));

   ir_variable *const r08DE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r08DF = less(r08DD, r08CB);
   ir_expression *const r08E0 = expr(ir_unop_b2i, r08DF);
   ir_expression *const r08E1 = expr(ir_unop_i2u, r08E0);
   ir_expression *const r08E2 = add(r08C9, r08E1);
   body.emit(assign(r08DE, add(r08C4, r08E2), 0x01));

   body.emit(assign(r0886, r0889, 0x01));

   body.emit(assign(r0885, r08DD, 0x01));

   body.emit(assign(r0884, r08DE, 0x01));

   ir_expression *const r08E3 = less(r08C4, r08B2);
   ir_expression *const r08E4 = expr(ir_unop_b2i, r08E3);
   ir_expression *const r08E5 = expr(ir_unop_i2u, r08E4);
   ir_expression *const r08E6 = add(r08B0, r08E5);
   ir_expression *const r08E7 = less(r08DE, r08C4);
   ir_expression *const r08E8 = expr(ir_unop_b2i, r08E7);
   ir_expression *const r08E9 = expr(ir_unop_i2u, r08E8);
   body.emit(assign(r0883, add(r08E6, r08E9), 0x01));

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

   ir_variable *const r08EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r08EA);
   ir_variable *const r08EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r08EB);
   ir_variable *const r08EC = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r08EC);
   ir_variable *const r08ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r08ED);
   ir_variable *const r08EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r08EE);
   ir_variable *const r08EF = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r08EF);
   /* IF CONDITION */
   ir_expression *const r08F1 = equal(r08EA, body.constant(0u));
   ir_if *f08F0 = new(mem_ctx) ir_if(operand(r08F1).val);
   exec_list *const f08F0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08F0->then_instructions;

      ir_expression *const r08F2 = equal(r08EB, body.constant(0u));
      ir_expression *const r08F3 = expr(ir_unop_find_msb, r08EB);
      ir_expression *const r08F4 = sub(body.constant(int(31)), r08F3);
      ir_expression *const r08F5 = expr(ir_triop_csel, r08F2, body.constant(int(32)), r08F4);
      body.emit(assign(r08EF, add(r08F5, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r08F7 = less(r08EF, body.constant(int(0)));
      ir_if *f08F6 = new(mem_ctx) ir_if(operand(r08F7).val);
      exec_list *const f08F6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08F6->then_instructions;

         ir_expression *const r08F8 = neg(r08EF);
         body.emit(assign(r08ED, rshift(r08EB, r08F8), 0x01));

         ir_expression *const r08F9 = bit_and(r08EF, body.constant(int(31)));
         body.emit(assign(r08EE, lshift(r08EB, r08F9), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08F6->else_instructions;

         body.emit(assign(r08ED, lshift(r08EB, r08EF), 0x01));

         body.emit(assign(r08EE, body.constant(0u), 0x01));


      body.instructions = f08F6_parent_instructions;
      body.emit(f08F6);

      /* END IF */

      body.emit(assign(r08EC, sub(body.constant(int(-31)), r08EF), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f08F0->else_instructions;

      ir_expression *const r08FA = equal(r08EA, body.constant(0u));
      ir_expression *const r08FB = expr(ir_unop_find_msb, r08EA);
      ir_expression *const r08FC = sub(body.constant(int(31)), r08FB);
      ir_expression *const r08FD = expr(ir_triop_csel, r08FA, body.constant(int(32)), r08FC);
      body.emit(assign(r08EF, add(r08FD, body.constant(int(-11))), 0x01));

      ir_expression *const r08FE = equal(r08EF, body.constant(int(0)));
      ir_expression *const r08FF = lshift(r08EA, r08EF);
      ir_expression *const r0900 = neg(r08EF);
      ir_expression *const r0901 = bit_and(r0900, body.constant(int(31)));
      ir_expression *const r0902 = rshift(r08EB, r0901);
      ir_expression *const r0903 = bit_or(r08FF, r0902);
      body.emit(assign(r08ED, expr(ir_triop_csel, r08FE, r08EA, r0903), 0x01));

      body.emit(assign(r08EE, lshift(r08EB, r08EF), 0x01));

      body.emit(assign(r08EC, sub(body.constant(int(1)), r08EF), 0x01));


   body.instructions = f08F0_parent_instructions;
   body.emit(f08F0);

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

   ir_variable *const r0904 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0904);
   ir_variable *const r0905 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0905);
   ir_variable *const r0906 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0906, body.constant(true), 0x01));

   ir_variable *const r0907 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0908 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0908);
   ir_variable *const r0909 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r0909);
   ir_variable *const r090A = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r090A);
   ir_variable *const r090B = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r090B);
   ir_variable *const r090C = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r090C);
   ir_variable *const r090D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r090D);
   ir_variable *const r090E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r090E);
   ir_variable *const r090F = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r090F);
   ir_variable *const r0910 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0910);
   ir_variable *const r0911 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0911);
   ir_variable *const r0912 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0912);
   body.emit(assign(r0912, body.constant(0u), 0x01));

   body.emit(assign(r0911, body.constant(0u), 0x01));

   body.emit(assign(r0910, body.constant(0u), 0x01));

   ir_variable *const r0913 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0913, swizzle_x(r0904), 0x01));

   body.emit(assign(r090E, r0913, 0x01));

   ir_variable *const r0914 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0914, bit_and(swizzle_y(r0904), body.constant(1048575u)), 0x01));

   body.emit(assign(r090D, r0914, 0x01));

   ir_variable *const r0915 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0915, swizzle_x(r0905), 0x01));

   body.emit(assign(r090C, r0915, 0x01));

   ir_variable *const r0916 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0916, bit_and(swizzle_y(r0905), body.constant(1048575u)), 0x01));

   body.emit(assign(r090B, r0916, 0x01));

   ir_variable *const r0917 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0918 = rshift(swizzle_y(r0904), body.constant(int(20)));
   ir_expression *const r0919 = bit_and(r0918, body.constant(2047u));
   body.emit(assign(r0917, expr(ir_unop_u2i, r0919), 0x01));

   body.emit(assign(r090A, r0917, 0x01));

   ir_variable *const r091A = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r091B = rshift(swizzle_y(r0905), body.constant(int(20)));
   ir_expression *const r091C = bit_and(r091B, body.constant(2047u));
   body.emit(assign(r091A, expr(ir_unop_u2i, r091C), 0x01));

   body.emit(assign(r0909, r091A, 0x01));

   ir_expression *const r091D = rshift(swizzle_y(r0904), body.constant(int(31)));
   ir_expression *const r091E = rshift(swizzle_y(r0905), body.constant(int(31)));
   body.emit(assign(r0908, bit_xor(r091D, r091E), 0x01));

   /* IF CONDITION */
   ir_expression *const r0920 = equal(r0917, body.constant(int(2047)));
   ir_if *f091F = new(mem_ctx) ir_if(operand(r0920).val);
   exec_list *const f091F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f091F->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0922 = bit_or(r0914, swizzle_x(r0904));
      ir_expression *const r0923 = nequal(r0922, body.constant(0u));
      ir_expression *const r0924 = equal(r091A, body.constant(int(2047)));
      ir_expression *const r0925 = bit_or(r0916, swizzle_x(r0905));
      ir_expression *const r0926 = nequal(r0925, body.constant(0u));
      ir_expression *const r0927 = logic_and(r0924, r0926);
      ir_expression *const r0928 = logic_or(r0923, r0927);
      ir_if *f0921 = new(mem_ctx) ir_if(operand(r0928).val);
      exec_list *const f0921_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0921->then_instructions;

         ir_variable *const r0929 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r0929, swizzle_x(r0904), 0x01));

         ir_variable *const r092A = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r092A, swizzle_x(r0905), 0x01));

         body.emit(assign(r0929, bit_or(swizzle_y(r0904), body.constant(524288u)), 0x02));

         body.emit(assign(r092A, bit_or(swizzle_y(r0905), body.constant(524288u)), 0x02));

         ir_expression *const r092B = lshift(swizzle_y(r0904), body.constant(int(1)));
         ir_expression *const r092C = gequal(r092B, body.constant(4292870144u));
         ir_expression *const r092D = nequal(swizzle_x(r0904), body.constant(0u));
         ir_expression *const r092E = bit_and(swizzle_y(r0904), body.constant(1048575u));
         ir_expression *const r092F = nequal(r092E, body.constant(0u));
         ir_expression *const r0930 = logic_or(r092D, r092F);
         ir_expression *const r0931 = logic_and(r092C, r0930);
         ir_swizzle *const r0932 = swizzle(r0931, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r0933 = lshift(swizzle_y(r0905), body.constant(int(1)));
         ir_expression *const r0934 = gequal(r0933, body.constant(4292870144u));
         ir_expression *const r0935 = nequal(swizzle_x(r0905), body.constant(0u));
         ir_expression *const r0936 = bit_and(swizzle_y(r0905), body.constant(1048575u));
         ir_expression *const r0937 = nequal(r0936, body.constant(0u));
         ir_expression *const r0938 = logic_or(r0935, r0937);
         ir_expression *const r0939 = logic_and(r0934, r0938);
         ir_swizzle *const r093A = swizzle(r0939, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r093B = expr(ir_triop_csel, r093A, r092A, r0929);
         body.emit(assign(r0907, expr(ir_triop_csel, r0932, r093B, r092A), 0x03));

         body.emit(assign(r0906, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0921->else_instructions;

         /* IF CONDITION */
         ir_expression *const r093D = expr(ir_unop_i2u, r091A);
         ir_expression *const r093E = bit_or(r093D, r0916);
         ir_expression *const r093F = bit_or(r093E, swizzle_x(r0905));
         ir_expression *const r0940 = equal(r093F, body.constant(0u));
         ir_if *f093C = new(mem_ctx) ir_if(operand(r0940).val);
         exec_list *const f093C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f093C->then_instructions;

            ir_constant_data r0941_data;
            memset(&r0941_data, 0, sizeof(ir_constant_data));
            r0941_data.u[0] = 4294967295;
            r0941_data.u[1] = 4294967295;
            ir_constant *const r0941 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0941_data);
            body.emit(assign(r0907, r0941, 0x03));

            body.emit(assign(r0906, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f093C->else_instructions;

            ir_variable *const r0942 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0942);
            ir_expression *const r0943 = lshift(r0908, body.constant(int(31)));
            body.emit(assign(r0942, add(r0943, body.constant(2146435072u)), 0x02));

            body.emit(assign(r0942, body.constant(0u), 0x01));

            body.emit(assign(r0907, r0942, 0x03));

            body.emit(assign(r0906, body.constant(false), 0x01));


         body.instructions = f093C_parent_instructions;
         body.emit(f093C);

         /* END IF */


      body.instructions = f0921_parent_instructions;
      body.emit(f0921);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f091F->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0945 = equal(r091A, body.constant(int(2047)));
      ir_if *f0944 = new(mem_ctx) ir_if(operand(r0945).val);
      exec_list *const f0944_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0944->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0947 = bit_or(r0916, swizzle_x(r0905));
         ir_expression *const r0948 = nequal(r0947, body.constant(0u));
         ir_if *f0946 = new(mem_ctx) ir_if(operand(r0948).val);
         exec_list *const f0946_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0946->then_instructions;

            ir_variable *const r0949 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0949, swizzle_x(r0904), 0x01));

            ir_variable *const r094A = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r094A, swizzle_x(r0905), 0x01));

            body.emit(assign(r0949, bit_or(swizzle_y(r0904), body.constant(524288u)), 0x02));

            body.emit(assign(r094A, bit_or(swizzle_y(r0905), body.constant(524288u)), 0x02));

            ir_expression *const r094B = lshift(swizzle_y(r0904), body.constant(int(1)));
            ir_expression *const r094C = gequal(r094B, body.constant(4292870144u));
            ir_expression *const r094D = nequal(swizzle_x(r0904), body.constant(0u));
            ir_expression *const r094E = bit_and(swizzle_y(r0904), body.constant(1048575u));
            ir_expression *const r094F = nequal(r094E, body.constant(0u));
            ir_expression *const r0950 = logic_or(r094D, r094F);
            ir_expression *const r0951 = logic_and(r094C, r0950);
            ir_swizzle *const r0952 = swizzle(r0951, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0953 = lshift(swizzle_y(r0905), body.constant(int(1)));
            ir_expression *const r0954 = gequal(r0953, body.constant(4292870144u));
            ir_expression *const r0955 = nequal(swizzle_x(r0905), body.constant(0u));
            ir_expression *const r0956 = bit_and(swizzle_y(r0905), body.constant(1048575u));
            ir_expression *const r0957 = nequal(r0956, body.constant(0u));
            ir_expression *const r0958 = logic_or(r0955, r0957);
            ir_expression *const r0959 = logic_and(r0954, r0958);
            ir_swizzle *const r095A = swizzle(r0959, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r095B = expr(ir_triop_csel, r095A, r094A, r0949);
            body.emit(assign(r0907, expr(ir_triop_csel, r0952, r095B, r094A), 0x03));

            body.emit(assign(r0906, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0946->else_instructions;

            /* IF CONDITION */
            ir_expression *const r095D = expr(ir_unop_i2u, r0917);
            ir_expression *const r095E = bit_or(r095D, r0914);
            ir_expression *const r095F = bit_or(r095E, swizzle_x(r0904));
            ir_expression *const r0960 = equal(r095F, body.constant(0u));
            ir_if *f095C = new(mem_ctx) ir_if(operand(r0960).val);
            exec_list *const f095C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f095C->then_instructions;

               ir_constant_data r0961_data;
               memset(&r0961_data, 0, sizeof(ir_constant_data));
               r0961_data.u[0] = 4294967295;
               r0961_data.u[1] = 4294967295;
               ir_constant *const r0961 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0961_data);
               body.emit(assign(r0907, r0961, 0x03));

               body.emit(assign(r0906, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f095C->else_instructions;

               ir_variable *const r0962 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0962);
               ir_expression *const r0963 = lshift(r0908, body.constant(int(31)));
               body.emit(assign(r0962, add(r0963, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0962, body.constant(0u), 0x01));

               body.emit(assign(r0907, r0962, 0x03));

               body.emit(assign(r0906, body.constant(false), 0x01));


            body.instructions = f095C_parent_instructions;
            body.emit(f095C);

            /* END IF */


         body.instructions = f0946_parent_instructions;
         body.emit(f0946);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0944->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0965 = equal(r0917, body.constant(int(0)));
         ir_if *f0964 = new(mem_ctx) ir_if(operand(r0965).val);
         exec_list *const f0964_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0964->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0967 = bit_or(r0914, swizzle_x(r0904));
            ir_expression *const r0968 = equal(r0967, body.constant(0u));
            ir_if *f0966 = new(mem_ctx) ir_if(operand(r0968).val);
            exec_list *const f0966_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0966->then_instructions;

               ir_variable *const r0969 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0969);
               body.emit(assign(r0969, lshift(r0908, body.constant(int(31))), 0x02));

               body.emit(assign(r0969, body.constant(0u), 0x01));

               body.emit(assign(r0907, r0969, 0x03));

               body.emit(assign(r0906, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0966->else_instructions;

               ir_variable *const r096A = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r096A, r0917, 0x01));

               ir_variable *const r096B = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r096B, r0914, 0x01));

               ir_variable *const r096C = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r096C, r0913, 0x01));

               ir_variable *const r096D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r096D);
               /* IF CONDITION */
               ir_expression *const r096F = equal(r0914, body.constant(0u));
               ir_if *f096E = new(mem_ctx) ir_if(operand(r096F).val);
               exec_list *const f096E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f096E->then_instructions;

                  ir_expression *const r0970 = equal(swizzle_x(r0904), body.constant(0u));
                  ir_expression *const r0971 = expr(ir_unop_find_msb, swizzle_x(r0904));
                  ir_expression *const r0972 = sub(body.constant(int(31)), r0971);
                  ir_expression *const r0973 = expr(ir_triop_csel, r0970, body.constant(int(32)), r0972);
                  body.emit(assign(r096D, add(r0973, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0975 = less(r096D, body.constant(int(0)));
                  ir_if *f0974 = new(mem_ctx) ir_if(operand(r0975).val);
                  exec_list *const f0974_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0974->then_instructions;

                     ir_expression *const r0976 = neg(r096D);
                     body.emit(assign(r096B, rshift(swizzle_x(r0904), r0976), 0x01));

                     ir_expression *const r0977 = bit_and(r096D, body.constant(int(31)));
                     body.emit(assign(r096C, lshift(swizzle_x(r0904), r0977), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0974->else_instructions;

                     body.emit(assign(r096B, lshift(swizzle_x(r0904), r096D), 0x01));

                     body.emit(assign(r096C, body.constant(0u), 0x01));


                  body.instructions = f0974_parent_instructions;
                  body.emit(f0974);

                  /* END IF */

                  body.emit(assign(r096A, sub(body.constant(int(-31)), r096D), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f096E->else_instructions;

                  ir_expression *const r0978 = equal(r0914, body.constant(0u));
                  ir_expression *const r0979 = expr(ir_unop_find_msb, r0914);
                  ir_expression *const r097A = sub(body.constant(int(31)), r0979);
                  ir_expression *const r097B = expr(ir_triop_csel, r0978, body.constant(int(32)), r097A);
                  body.emit(assign(r096D, add(r097B, body.constant(int(-11))), 0x01));

                  ir_expression *const r097C = equal(r096D, body.constant(int(0)));
                  ir_expression *const r097D = lshift(r0914, r096D);
                  ir_expression *const r097E = neg(r096D);
                  ir_expression *const r097F = bit_and(r097E, body.constant(int(31)));
                  ir_expression *const r0980 = rshift(swizzle_x(r0904), r097F);
                  ir_expression *const r0981 = bit_or(r097D, r0980);
                  body.emit(assign(r096B, expr(ir_triop_csel, r097C, r0914, r0981), 0x01));

                  body.emit(assign(r096C, lshift(swizzle_x(r0904), r096D), 0x01));

                  body.emit(assign(r096A, sub(body.constant(int(1)), r096D), 0x01));


               body.instructions = f096E_parent_instructions;
               body.emit(f096E);

               /* END IF */

               body.emit(assign(r090A, r096A, 0x01));

               body.emit(assign(r090D, r096B, 0x01));

               body.emit(assign(r090E, r096C, 0x01));


            body.instructions = f0966_parent_instructions;
            body.emit(f0966);

            /* END IF */


         body.instructions = f0964_parent_instructions;
         body.emit(f0964);

         /* END IF */

         /* IF CONDITION */
         ir_if *f0982 = new(mem_ctx) ir_if(operand(r0906).val);
         exec_list *const f0982_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0982->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0984 = equal(r091A, body.constant(int(0)));
            ir_if *f0983 = new(mem_ctx) ir_if(operand(r0984).val);
            exec_list *const f0983_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0983->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0986 = bit_or(r0916, swizzle_x(r0905));
               ir_expression *const r0987 = equal(r0986, body.constant(0u));
               ir_if *f0985 = new(mem_ctx) ir_if(operand(r0987).val);
               exec_list *const f0985_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0985->then_instructions;

                  ir_variable *const r0988 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0988);
                  body.emit(assign(r0988, lshift(r0908, body.constant(int(31))), 0x02));

                  body.emit(assign(r0988, body.constant(0u), 0x01));

                  body.emit(assign(r0907, r0988, 0x03));

                  body.emit(assign(r0906, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0985->else_instructions;

                  ir_variable *const r0989 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r0989, r091A, 0x01));

                  ir_variable *const r098A = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r098A, r0916, 0x01));

                  ir_variable *const r098B = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r098B, r0915, 0x01));

                  ir_variable *const r098C = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r098C);
                  /* IF CONDITION */
                  ir_expression *const r098E = equal(r0916, body.constant(0u));
                  ir_if *f098D = new(mem_ctx) ir_if(operand(r098E).val);
                  exec_list *const f098D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f098D->then_instructions;

                     ir_expression *const r098F = equal(swizzle_x(r0905), body.constant(0u));
                     ir_expression *const r0990 = expr(ir_unop_find_msb, swizzle_x(r0905));
                     ir_expression *const r0991 = sub(body.constant(int(31)), r0990);
                     ir_expression *const r0992 = expr(ir_triop_csel, r098F, body.constant(int(32)), r0991);
                     body.emit(assign(r098C, add(r0992, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0994 = less(r098C, body.constant(int(0)));
                     ir_if *f0993 = new(mem_ctx) ir_if(operand(r0994).val);
                     exec_list *const f0993_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0993->then_instructions;

                        ir_expression *const r0995 = neg(r098C);
                        body.emit(assign(r098A, rshift(swizzle_x(r0905), r0995), 0x01));

                        ir_expression *const r0996 = bit_and(r098C, body.constant(int(31)));
                        body.emit(assign(r098B, lshift(swizzle_x(r0905), r0996), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0993->else_instructions;

                        body.emit(assign(r098A, lshift(swizzle_x(r0905), r098C), 0x01));

                        body.emit(assign(r098B, body.constant(0u), 0x01));


                     body.instructions = f0993_parent_instructions;
                     body.emit(f0993);

                     /* END IF */

                     body.emit(assign(r0989, sub(body.constant(int(-31)), r098C), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f098D->else_instructions;

                     ir_expression *const r0997 = equal(r0916, body.constant(0u));
                     ir_expression *const r0998 = expr(ir_unop_find_msb, r0916);
                     ir_expression *const r0999 = sub(body.constant(int(31)), r0998);
                     ir_expression *const r099A = expr(ir_triop_csel, r0997, body.constant(int(32)), r0999);
                     body.emit(assign(r098C, add(r099A, body.constant(int(-11))), 0x01));

                     ir_expression *const r099B = equal(r098C, body.constant(int(0)));
                     ir_expression *const r099C = lshift(r0916, r098C);
                     ir_expression *const r099D = neg(r098C);
                     ir_expression *const r099E = bit_and(r099D, body.constant(int(31)));
                     ir_expression *const r099F = rshift(swizzle_x(r0905), r099E);
                     ir_expression *const r09A0 = bit_or(r099C, r099F);
                     body.emit(assign(r098A, expr(ir_triop_csel, r099B, r0916, r09A0), 0x01));

                     body.emit(assign(r098B, lshift(swizzle_x(r0905), r098C), 0x01));

                     body.emit(assign(r0989, sub(body.constant(int(1)), r098C), 0x01));


                  body.instructions = f098D_parent_instructions;
                  body.emit(f098D);

                  /* END IF */

                  body.emit(assign(r0909, r0989, 0x01));

                  body.emit(assign(r090B, r098A, 0x01));

                  body.emit(assign(r090C, r098B, 0x01));


               body.instructions = f0985_parent_instructions;
               body.emit(f0985);

               /* END IF */


            body.instructions = f0983_parent_instructions;
            body.emit(f0983);

            /* END IF */

            /* IF CONDITION */
            ir_if *f09A1 = new(mem_ctx) ir_if(operand(r0906).val);
            exec_list *const f09A1_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f09A1->then_instructions;

               ir_expression *const r09A2 = add(r090A, r0909);
               body.emit(assign(r090F, add(r09A2, body.constant(int(-1024))), 0x01));

               body.emit(assign(r090D, bit_or(r090D, body.constant(1048576u)), 0x01));

               ir_variable *const r09A3 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r09A4 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r09A4, lshift(r090C, body.constant(int(12))), 0x01));

               ir_expression *const r09A5 = lshift(r090B, body.constant(int(12)));
               ir_expression *const r09A6 = rshift(r090C, body.constant(int(20)));
               body.emit(assign(r09A3, bit_or(r09A5, r09A6), 0x01));

               body.emit(assign(r090B, r09A3, 0x01));

               body.emit(assign(r090C, r09A4, 0x01));

               ir_variable *const r09A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r09A7);
               ir_variable *const r09A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r09A8);
               ir_variable *const r09A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r09A9);
               ir_variable *const r09AA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09AA, bit_and(r090E, body.constant(65535u)), 0x01));

               ir_variable *const r09AB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09AB, rshift(r090E, body.constant(int(16))), 0x01));

               ir_variable *const r09AC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09AC, bit_and(r09A4, body.constant(65535u)), 0x01));

               ir_variable *const r09AD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09AD, rshift(r09A4, body.constant(int(16))), 0x01));

               ir_variable *const r09AE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09AE, mul(r09AB, r09AC), 0x01));

               ir_expression *const r09AF = mul(r09AA, r09AD);
               body.emit(assign(r09A8, add(r09AF, r09AE), 0x01));

               ir_expression *const r09B0 = mul(r09AB, r09AD);
               ir_expression *const r09B1 = less(r09A8, r09AE);
               ir_expression *const r09B2 = expr(ir_unop_b2i, r09B1);
               ir_expression *const r09B3 = expr(ir_unop_i2u, r09B2);
               ir_expression *const r09B4 = lshift(r09B3, body.constant(int(16)));
               ir_expression *const r09B5 = rshift(r09A8, body.constant(int(16)));
               ir_expression *const r09B6 = add(r09B4, r09B5);
               body.emit(assign(r09A7, add(r09B0, r09B6), 0x01));

               body.emit(assign(r09A8, lshift(r09A8, body.constant(int(16))), 0x01));

               ir_expression *const r09B7 = mul(r09AA, r09AC);
               body.emit(assign(r09A9, add(r09B7, r09A8), 0x01));

               ir_expression *const r09B8 = less(r09A9, r09A8);
               ir_expression *const r09B9 = expr(ir_unop_b2i, r09B8);
               ir_expression *const r09BA = expr(ir_unop_i2u, r09B9);
               body.emit(assign(r09A7, add(r09A7, r09BA), 0x01));

               ir_variable *const r09BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r09BB);
               ir_variable *const r09BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r09BC);
               ir_variable *const r09BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r09BD);
               ir_variable *const r09BE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09BE, bit_and(r090E, body.constant(65535u)), 0x01));

               ir_variable *const r09BF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09BF, rshift(r090E, body.constant(int(16))), 0x01));

               ir_variable *const r09C0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09C0, bit_and(r09A3, body.constant(65535u)), 0x01));

               ir_variable *const r09C1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09C1, rshift(r09A3, body.constant(int(16))), 0x01));

               ir_variable *const r09C2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09C2, mul(r09BF, r09C0), 0x01));

               ir_expression *const r09C3 = mul(r09BE, r09C1);
               body.emit(assign(r09BC, add(r09C3, r09C2), 0x01));

               ir_expression *const r09C4 = mul(r09BF, r09C1);
               ir_expression *const r09C5 = less(r09BC, r09C2);
               ir_expression *const r09C6 = expr(ir_unop_b2i, r09C5);
               ir_expression *const r09C7 = expr(ir_unop_i2u, r09C6);
               ir_expression *const r09C8 = lshift(r09C7, body.constant(int(16)));
               ir_expression *const r09C9 = rshift(r09BC, body.constant(int(16)));
               ir_expression *const r09CA = add(r09C8, r09C9);
               body.emit(assign(r09BB, add(r09C4, r09CA), 0x01));

               body.emit(assign(r09BC, lshift(r09BC, body.constant(int(16))), 0x01));

               ir_expression *const r09CB = mul(r09BE, r09C0);
               body.emit(assign(r09BD, add(r09CB, r09BC), 0x01));

               ir_expression *const r09CC = less(r09BD, r09BC);
               ir_expression *const r09CD = expr(ir_unop_b2i, r09CC);
               ir_expression *const r09CE = expr(ir_unop_i2u, r09CD);
               body.emit(assign(r09BB, add(r09BB, r09CE), 0x01));

               ir_variable *const r09CF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09CF, add(r09BD, r09A7), 0x01));

               ir_variable *const r09D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r09D0);
               ir_variable *const r09D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r09D1);
               ir_variable *const r09D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r09D2);
               ir_variable *const r09D3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09D3, bit_and(r090D, body.constant(65535u)), 0x01));

               ir_variable *const r09D4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09D4, rshift(r090D, body.constant(int(16))), 0x01));

               ir_variable *const r09D5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09D5, bit_and(r09A3, body.constant(65535u)), 0x01));

               ir_variable *const r09D6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09D6, rshift(r09A3, body.constant(int(16))), 0x01));

               ir_variable *const r09D7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09D7, mul(r09D4, r09D5), 0x01));

               ir_expression *const r09D8 = mul(r09D3, r09D6);
               body.emit(assign(r09D1, add(r09D8, r09D7), 0x01));

               ir_expression *const r09D9 = mul(r09D4, r09D6);
               ir_expression *const r09DA = less(r09D1, r09D7);
               ir_expression *const r09DB = expr(ir_unop_b2i, r09DA);
               ir_expression *const r09DC = expr(ir_unop_i2u, r09DB);
               ir_expression *const r09DD = lshift(r09DC, body.constant(int(16)));
               ir_expression *const r09DE = rshift(r09D1, body.constant(int(16)));
               ir_expression *const r09DF = add(r09DD, r09DE);
               body.emit(assign(r09D0, add(r09D9, r09DF), 0x01));

               body.emit(assign(r09D1, lshift(r09D1, body.constant(int(16))), 0x01));

               ir_expression *const r09E0 = mul(r09D3, r09D5);
               body.emit(assign(r09D2, add(r09E0, r09D1), 0x01));

               ir_expression *const r09E1 = less(r09D2, r09D1);
               ir_expression *const r09E2 = expr(ir_unop_b2i, r09E1);
               ir_expression *const r09E3 = expr(ir_unop_i2u, r09E2);
               body.emit(assign(r09D0, add(r09D0, r09E3), 0x01));

               ir_variable *const r09E4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r09E5 = less(r09CF, r09BD);
               ir_expression *const r09E6 = expr(ir_unop_b2i, r09E5);
               ir_expression *const r09E7 = expr(ir_unop_i2u, r09E6);
               ir_expression *const r09E8 = add(r09BB, r09E7);
               body.emit(assign(r09E4, add(r09D2, r09E8), 0x01));

               ir_variable *const r09E9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r09E9);
               ir_variable *const r09EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r09EA);
               ir_variable *const r09EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r09EB);
               ir_variable *const r09EC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09EC, bit_and(r090D, body.constant(65535u)), 0x01));

               ir_variable *const r09ED = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09ED, rshift(r090D, body.constant(int(16))), 0x01));

               ir_variable *const r09EE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09EE, bit_and(r09A4, body.constant(65535u)), 0x01));

               ir_variable *const r09EF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09EF, rshift(r09A4, body.constant(int(16))), 0x01));

               ir_variable *const r09F0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09F0, mul(r09ED, r09EE), 0x01));

               ir_expression *const r09F1 = mul(r09EC, r09EF);
               body.emit(assign(r09EA, add(r09F1, r09F0), 0x01));

               ir_expression *const r09F2 = mul(r09ED, r09EF);
               ir_expression *const r09F3 = less(r09EA, r09F0);
               ir_expression *const r09F4 = expr(ir_unop_b2i, r09F3);
               ir_expression *const r09F5 = expr(ir_unop_i2u, r09F4);
               ir_expression *const r09F6 = lshift(r09F5, body.constant(int(16)));
               ir_expression *const r09F7 = rshift(r09EA, body.constant(int(16)));
               ir_expression *const r09F8 = add(r09F6, r09F7);
               body.emit(assign(r09E9, add(r09F2, r09F8), 0x01));

               body.emit(assign(r09EA, lshift(r09EA, body.constant(int(16))), 0x01));

               ir_expression *const r09F9 = mul(r09EC, r09EE);
               body.emit(assign(r09EB, add(r09F9, r09EA), 0x01));

               ir_expression *const r09FA = less(r09EB, r09EA);
               ir_expression *const r09FB = expr(ir_unop_b2i, r09FA);
               ir_expression *const r09FC = expr(ir_unop_i2u, r09FB);
               body.emit(assign(r09E9, add(r09E9, r09FC), 0x01));

               ir_variable *const r09FD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09FD, add(r09EB, r09CF), 0x01));

               ir_variable *const r09FE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r09FF = less(r09FD, r09EB);
               ir_expression *const r0A00 = expr(ir_unop_b2i, r09FF);
               ir_expression *const r0A01 = expr(ir_unop_i2u, r0A00);
               ir_expression *const r0A02 = add(r09E9, r0A01);
               body.emit(assign(r09FE, add(r09E4, r0A02), 0x01));

               ir_variable *const r0A03 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0A04 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0A04, add(r09FE, r090E), 0x01));

               ir_expression *const r0A05 = less(r09E4, r09D2);
               ir_expression *const r0A06 = expr(ir_unop_b2i, r0A05);
               ir_expression *const r0A07 = expr(ir_unop_i2u, r0A06);
               ir_expression *const r0A08 = add(r09D0, r0A07);
               ir_expression *const r0A09 = less(r09FE, r09E4);
               ir_expression *const r0A0A = expr(ir_unop_b2i, r0A09);
               ir_expression *const r0A0B = expr(ir_unop_i2u, r0A0A);
               ir_expression *const r0A0C = add(r0A08, r0A0B);
               ir_expression *const r0A0D = add(r0A0C, r090D);
               ir_expression *const r0A0E = less(r0A04, r09FE);
               ir_expression *const r0A0F = expr(ir_unop_b2i, r0A0E);
               ir_expression *const r0A10 = expr(ir_unop_i2u, r0A0F);
               body.emit(assign(r0A03, add(r0A0D, r0A10), 0x01));

               body.emit(assign(r0912, r0A03, 0x01));

               body.emit(assign(r0911, r0A04, 0x01));

               ir_expression *const r0A11 = nequal(r09A9, body.constant(0u));
               ir_expression *const r0A12 = expr(ir_unop_b2i, r0A11);
               ir_expression *const r0A13 = expr(ir_unop_i2u, r0A12);
               body.emit(assign(r0910, bit_or(r09FD, r0A13), 0x01));

               /* IF CONDITION */
               ir_expression *const r0A15 = gequal(r0A03, body.constant(2097152u));
               ir_if *f0A14 = new(mem_ctx) ir_if(operand(r0A15).val);
               exec_list *const f0A14_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A14->then_instructions;

                  body.emit(assign(r0912, rshift(r0A03, body.constant(int(1))), 0x01));

                  ir_expression *const r0A16 = lshift(r0A03, body.constant(int(31)));
                  ir_expression *const r0A17 = rshift(r0A04, body.constant(int(1)));
                  body.emit(assign(r0911, bit_or(r0A16, r0A17), 0x01));

                  ir_expression *const r0A18 = lshift(r0A04, body.constant(int(31)));
                  ir_expression *const r0A19 = nequal(r0910, body.constant(0u));
                  ir_expression *const r0A1A = expr(ir_unop_b2i, r0A19);
                  ir_expression *const r0A1B = expr(ir_unop_i2u, r0A1A);
                  body.emit(assign(r0910, bit_or(r0A18, r0A1B), 0x01));

                  body.emit(assign(r090F, add(r090F, body.constant(int(1))), 0x01));


               body.instructions = f0A14_parent_instructions;
               body.emit(f0A14);

               /* END IF */

               ir_variable *const r0A1C = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0A1C, r090F, 0x01));

               ir_variable *const r0A1D = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r0A1D, r0912, 0x01));

               ir_variable *const r0A1E = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0A1E, r0911, 0x01));

               ir_variable *const r0A1F = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r0A1F, r0910, 0x01));

               ir_variable *const r0A20 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0A20, body.constant(true), 0x01));

               ir_variable *const r0A21 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0A22 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0A22);
               ir_expression *const r0A23 = expr(ir_unop_u2i, r0910);
               body.emit(assign(r0A22, less(r0A23, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0A25 = gequal(r090F, body.constant(int(2045)));
               ir_if *f0A24 = new(mem_ctx) ir_if(operand(r0A25).val);
               exec_list *const f0A24_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A24->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A27 = less(body.constant(int(2045)), r090F);
                  ir_expression *const r0A28 = equal(r090F, body.constant(int(2045)));
                  ir_expression *const r0A29 = equal(body.constant(2097151u), r0912);
                  ir_expression *const r0A2A = equal(body.constant(4294967295u), r0911);
                  ir_expression *const r0A2B = logic_and(r0A29, r0A2A);
                  ir_expression *const r0A2C = logic_and(r0A28, r0A2B);
                  ir_expression *const r0A2D = logic_and(r0A2C, r0A22);
                  ir_expression *const r0A2E = logic_or(r0A27, r0A2D);
                  ir_if *f0A26 = new(mem_ctx) ir_if(operand(r0A2E).val);
                  exec_list *const f0A26_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A26->then_instructions;

                     ir_variable *const r0A2F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0A2F);
                     ir_expression *const r0A30 = lshift(r0908, body.constant(int(31)));
                     body.emit(assign(r0A2F, add(r0A30, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r0A2F, body.constant(0u), 0x01));

                     body.emit(assign(r0A21, r0A2F, 0x03));

                     body.emit(assign(r0A20, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A26->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0A32 = less(r090F, body.constant(int(0)));
                     ir_if *f0A31 = new(mem_ctx) ir_if(operand(r0A32).val);
                     exec_list *const f0A31_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0A31->then_instructions;

                        ir_variable *const r0A33 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0A33, neg(r090F), 0x01));

                        ir_variable *const r0A34 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0A34);
                        ir_variable *const r0A35 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0A36 = neg(r0A33);
                        body.emit(assign(r0A35, bit_and(r0A36, body.constant(int(31))), 0x01));

                        ir_variable *const r0A37 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0A38 = less(r0A33, body.constant(int(32)));
                        ir_expression *const r0A39 = bit_or(r0910, r0911);
                        body.emit(assign(r0A37, expr(ir_triop_csel, r0A38, r0910, r0A39), 0x01));

                        ir_expression *const r0A3A = less(r0A33, body.constant(int(32)));
                        ir_expression *const r0A3B = lshift(r0911, r0A35);
                        ir_expression *const r0A3C = less(r0A33, body.constant(int(64)));
                        ir_expression *const r0A3D = lshift(r0912, r0A35);
                        ir_expression *const r0A3E = equal(r0A33, body.constant(int(64)));
                        ir_expression *const r0A3F = nequal(r0912, body.constant(0u));
                        ir_expression *const r0A40 = expr(ir_unop_b2i, r0A3F);
                        ir_expression *const r0A41 = expr(ir_unop_i2u, r0A40);
                        ir_expression *const r0A42 = expr(ir_triop_csel, r0A3E, r0912, r0A41);
                        ir_expression *const r0A43 = expr(ir_triop_csel, r0A3C, r0A3D, r0A42);
                        ir_expression *const r0A44 = expr(ir_triop_csel, r0A3A, r0A3B, r0A43);
                        ir_expression *const r0A45 = nequal(r0A37, body.constant(0u));
                        ir_expression *const r0A46 = expr(ir_unop_b2i, r0A45);
                        ir_expression *const r0A47 = expr(ir_unop_i2u, r0A46);
                        body.emit(assign(r0A34, bit_or(r0A44, r0A47), 0x01));

                        ir_variable *const r0A48 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0A49 = equal(r0A33, body.constant(int(0)));
                        ir_expression *const r0A4A = equal(r0A33, body.constant(int(32)));
                        ir_expression *const r0A4B = expr(ir_triop_csel, r0A4A, r0911, r0A34);
                        body.emit(assign(r0A48, expr(ir_triop_csel, r0A49, r0A37, r0A4B), 0x01));

                        body.emit(assign(r0A34, r0A48, 0x01));

                        ir_expression *const r0A4C = equal(r0A33, body.constant(int(0)));
                        ir_expression *const r0A4D = equal(r0A33, body.constant(int(32)));
                        ir_expression *const r0A4E = less(r0A33, body.constant(int(32)));
                        ir_expression *const r0A4F = rshift(r0912, r0A33);
                        ir_expression *const r0A50 = expr(ir_triop_csel, r0A4E, r0A4F, body.constant(0u));
                        ir_expression *const r0A51 = expr(ir_triop_csel, r0A4D, body.constant(0u), r0A50);
                        body.emit(assign(r0A1D, expr(ir_triop_csel, r0A4C, r0912, r0A51), 0x01));

                        ir_expression *const r0A52 = equal(r0A33, body.constant(int(0)));
                        ir_expression *const r0A53 = equal(r0A33, body.constant(int(32)));
                        ir_expression *const r0A54 = less(r0A33, body.constant(int(32)));
                        ir_expression *const r0A55 = lshift(r0912, r0A35);
                        ir_expression *const r0A56 = rshift(r0911, r0A33);
                        ir_expression *const r0A57 = bit_or(r0A55, r0A56);
                        ir_expression *const r0A58 = less(r0A33, body.constant(int(64)));
                        ir_expression *const r0A59 = bit_and(r0A33, body.constant(int(31)));
                        ir_expression *const r0A5A = rshift(r0912, r0A59);
                        ir_expression *const r0A5B = expr(ir_triop_csel, r0A58, r0A5A, body.constant(0u));
                        ir_expression *const r0A5C = expr(ir_triop_csel, r0A54, r0A57, r0A5B);
                        ir_expression *const r0A5D = expr(ir_triop_csel, r0A53, r0912, r0A5C);
                        body.emit(assign(r0A1E, expr(ir_triop_csel, r0A52, r0911, r0A5D), 0x01));

                        body.emit(assign(r0A1F, r0A48, 0x01));

                        body.emit(assign(r0A1C, body.constant(int(0)), 0x01));

                        body.emit(assign(r0A22, less(r0A48, body.constant(0u)), 0x01));


                     body.instructions = f0A31_parent_instructions;
                     body.emit(f0A31);

                     /* END IF */


                  body.instructions = f0A26_parent_instructions;
                  body.emit(f0A26);

                  /* END IF */


               body.instructions = f0A24_parent_instructions;
               body.emit(f0A24);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0A5E = new(mem_ctx) ir_if(operand(r0A20).val);
               exec_list *const f0A5E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A5E->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0A5F = new(mem_ctx) ir_if(operand(r0A22).val);
                  exec_list *const f0A5F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A5F->then_instructions;

                     ir_variable *const r0A60 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0A60, add(r0A1E, body.constant(1u)), 0x01));

                     ir_expression *const r0A61 = less(r0A60, r0A1E);
                     ir_expression *const r0A62 = expr(ir_unop_b2i, r0A61);
                     ir_expression *const r0A63 = expr(ir_unop_i2u, r0A62);
                     body.emit(assign(r0A1D, add(r0A1D, r0A63), 0x01));

                     ir_expression *const r0A64 = equal(r0A1F, body.constant(0u));
                     ir_expression *const r0A65 = expr(ir_unop_b2i, r0A64);
                     ir_expression *const r0A66 = expr(ir_unop_i2u, r0A65);
                     ir_expression *const r0A67 = add(r0A1F, r0A66);
                     ir_expression *const r0A68 = bit_and(r0A67, body.constant(1u));
                     ir_expression *const r0A69 = expr(ir_unop_bit_not, r0A68);
                     body.emit(assign(r0A1E, bit_and(r0A60, r0A69), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A5F->else_instructions;

                     ir_expression *const r0A6A = bit_or(r0A1D, r0A1E);
                     ir_expression *const r0A6B = equal(r0A6A, body.constant(0u));
                     body.emit(assign(r0A1C, expr(ir_triop_csel, r0A6B, body.constant(int(0)), r0A1C), 0x01));


                  body.instructions = f0A5F_parent_instructions;
                  body.emit(f0A5F);

                  /* END IF */

                  ir_variable *const r0A6C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0A6C);
                  ir_expression *const r0A6D = lshift(r0908, body.constant(int(31)));
                  ir_expression *const r0A6E = expr(ir_unop_i2u, r0A1C);
                  ir_expression *const r0A6F = lshift(r0A6E, body.constant(int(20)));
                  ir_expression *const r0A70 = add(r0A6D, r0A6F);
                  body.emit(assign(r0A6C, add(r0A70, r0A1D), 0x02));

                  body.emit(assign(r0A6C, r0A1E, 0x01));

                  body.emit(assign(r0A21, r0A6C, 0x03));

                  body.emit(assign(r0A20, body.constant(false), 0x01));


               body.instructions = f0A5E_parent_instructions;
               body.emit(f0A5E);

               /* END IF */

               body.emit(assign(r0907, r0A21, 0x03));

               body.emit(assign(r0906, body.constant(false), 0x01));


            body.instructions = f09A1_parent_instructions;
            body.emit(f09A1);

            /* END IF */


         body.instructions = f0982_parent_instructions;
         body.emit(f0982);

         /* END IF */


      body.instructions = f0944_parent_instructions;
      body.emit(f0944);

      /* END IF */


   body.instructions = f091F_parent_instructions;
   body.emit(f091F);

   /* END IF */

   body.emit(ret(r0907));

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

   ir_variable *const r0A71 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0A71);
   ir_variable *const r0A72 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0A72);
   ir_variable *const r0A73 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r0A73);
   ir_variable *const r0A74 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0A74);
   ir_variable *const r0A75 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0A75);
   ir_expression *const r0A76 = equal(r0A73, body.constant(int(0)));
   ir_expression *const r0A77 = less(r0A73, body.constant(int(32)));
   ir_expression *const r0A78 = neg(r0A73);
   ir_expression *const r0A79 = bit_and(r0A78, body.constant(int(31)));
   ir_expression *const r0A7A = lshift(r0A71, r0A79);
   ir_expression *const r0A7B = rshift(r0A72, r0A73);
   ir_expression *const r0A7C = bit_or(r0A7A, r0A7B);
   ir_expression *const r0A7D = less(r0A73, body.constant(int(64)));
   ir_expression *const r0A7E = bit_and(r0A73, body.constant(int(31)));
   ir_expression *const r0A7F = rshift(r0A71, r0A7E);
   ir_expression *const r0A80 = expr(ir_triop_csel, r0A7D, r0A7F, body.constant(0u));
   ir_expression *const r0A81 = expr(ir_triop_csel, r0A77, r0A7C, r0A80);
   body.emit(assign(r0A75, expr(ir_triop_csel, r0A76, r0A71, r0A81), 0x01));

   ir_expression *const r0A82 = equal(r0A73, body.constant(int(0)));
   ir_expression *const r0A83 = less(r0A73, body.constant(int(32)));
   ir_expression *const r0A84 = rshift(r0A71, r0A73);
   ir_expression *const r0A85 = expr(ir_triop_csel, r0A83, r0A84, body.constant(0u));
   body.emit(assign(r0A74, expr(ir_triop_csel, r0A82, r0A71, r0A85), 0x01));

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

   ir_variable *const r0A86 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A86);
   ir_variable *const r0A87 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0A88 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A88);
   ir_variable *const r0A89 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0A89);
   body.emit(assign(r0A89, swizzle_x(r0A86), 0x01));

   ir_variable *const r0A8A = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A8A, bit_and(swizzle_y(r0A86), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A88, r0A8A, 0x01));

   ir_variable *const r0A8B = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A8C = rshift(swizzle_y(r0A86), body.constant(int(20)));
   ir_expression *const r0A8D = bit_and(r0A8C, body.constant(2047u));
   body.emit(assign(r0A8B, expr(ir_unop_u2i, r0A8D), 0x01));

   ir_variable *const r0A8E = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A8E, rshift(swizzle_y(r0A86), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A90 = nequal(r0A8E, body.constant(0u));
   ir_if *f0A8F = new(mem_ctx) ir_if(operand(r0A90).val);
   exec_list *const f0A8F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A8F->then_instructions;

      body.emit(assign(r0A87, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A8F->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A92 = equal(r0A8B, body.constant(int(2047)));
      ir_expression *const r0A93 = bit_or(r0A8A, swizzle_x(r0A86));
      ir_expression *const r0A94 = nequal(r0A93, body.constant(0u));
      ir_expression *const r0A95 = logic_and(r0A92, r0A94);
      ir_if *f0A91 = new(mem_ctx) ir_if(operand(r0A95).val);
      exec_list *const f0A91_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A91->then_instructions;

         body.emit(assign(r0A87, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A91->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A97 = nequal(r0A8B, body.constant(int(0)));
         ir_if *f0A96 = new(mem_ctx) ir_if(operand(r0A97).val);
         exec_list *const f0A96_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A96->then_instructions;

            body.emit(assign(r0A88, bit_or(r0A8A, body.constant(1048576u)), 0x01));


         body.instructions = f0A96_parent_instructions;
         body.emit(f0A96);

         /* END IF */

         ir_variable *const r0A98 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0A98, sub(body.constant(int(1063)), r0A8B), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A9A = less(body.constant(int(0)), r0A98);
         ir_if *f0A99 = new(mem_ctx) ir_if(operand(r0A9A).val);
         exec_list *const f0A99_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A99->then_instructions;

            ir_variable *const r0A9B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0A9B);
            ir_variable *const r0A9C = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0A9D = neg(r0A98);
            body.emit(assign(r0A9C, bit_and(r0A9D, body.constant(int(31))), 0x01));

            ir_expression *const r0A9E = bit_or(r0A88, swizzle_x(r0A86));
            ir_expression *const r0A9F = nequal(r0A9E, body.constant(0u));
            ir_expression *const r0AA0 = expr(ir_unop_b2i, r0A9F);
            body.emit(assign(r0A9B, expr(ir_unop_i2u, r0AA0), 0x01));

            ir_variable *const r0AA1 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0AA2 = equal(r0A98, body.constant(int(0)));
            ir_expression *const r0AA3 = less(r0A98, body.constant(int(32)));
            ir_expression *const r0AA4 = lshift(r0A88, r0A9C);
            ir_expression *const r0AA5 = rshift(swizzle_x(r0A86), r0A98);
            ir_expression *const r0AA6 = bit_or(r0AA4, r0AA5);
            ir_expression *const r0AA7 = lshift(swizzle_x(r0A86), r0A9C);
            ir_expression *const r0AA8 = nequal(r0AA7, body.constant(0u));
            ir_expression *const r0AA9 = expr(ir_unop_b2i, r0AA8);
            ir_expression *const r0AAA = expr(ir_unop_i2u, r0AA9);
            ir_expression *const r0AAB = bit_or(r0AA6, r0AAA);
            ir_expression *const r0AAC = equal(r0A98, body.constant(int(32)));
            ir_expression *const r0AAD = nequal(swizzle_x(r0A86), body.constant(0u));
            ir_expression *const r0AAE = expr(ir_unop_b2i, r0AAD);
            ir_expression *const r0AAF = expr(ir_unop_i2u, r0AAE);
            ir_expression *const r0AB0 = bit_or(r0A88, r0AAF);
            ir_expression *const r0AB1 = less(r0A98, body.constant(int(64)));
            ir_expression *const r0AB2 = bit_and(r0A98, body.constant(int(31)));
            ir_expression *const r0AB3 = rshift(r0A88, r0AB2);
            ir_expression *const r0AB4 = lshift(r0A88, r0A9C);
            ir_expression *const r0AB5 = bit_or(r0AB4, swizzle_x(r0A86));
            ir_expression *const r0AB6 = nequal(r0AB5, body.constant(0u));
            ir_expression *const r0AB7 = expr(ir_unop_b2i, r0AB6);
            ir_expression *const r0AB8 = expr(ir_unop_i2u, r0AB7);
            ir_expression *const r0AB9 = bit_or(r0AB3, r0AB8);
            ir_expression *const r0ABA = expr(ir_triop_csel, r0AB1, r0AB9, r0A9B);
            ir_expression *const r0ABB = expr(ir_triop_csel, r0AAC, r0AB0, r0ABA);
            ir_expression *const r0ABC = expr(ir_triop_csel, r0AA3, r0AAB, r0ABB);
            body.emit(assign(r0AA1, expr(ir_triop_csel, r0AA2, swizzle_x(r0A86), r0ABC), 0x01));

            body.emit(assign(r0A9B, r0AA1, 0x01));

            ir_expression *const r0ABD = less(r0A98, body.constant(int(32)));
            ir_expression *const r0ABE = rshift(r0A88, r0A98);
            ir_expression *const r0ABF = equal(r0A98, body.constant(int(0)));
            ir_expression *const r0AC0 = expr(ir_triop_csel, r0ABF, r0A88, body.constant(0u));
            body.emit(assign(r0A88, expr(ir_triop_csel, r0ABD, r0ABE, r0AC0), 0x01));

            body.emit(assign(r0A89, r0AA1, 0x01));


         body.instructions = f0A99_parent_instructions;
         body.emit(f0A99);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AC2 = bit_and(r0A88, body.constant(4294963200u));
         ir_expression *const r0AC3 = nequal(r0AC2, body.constant(0u));
         ir_if *f0AC1 = new(mem_ctx) ir_if(operand(r0AC3).val);
         exec_list *const f0AC1_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AC1->then_instructions;

            ir_variable *const r0AC4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0AC6 = nequal(r0A8E, body.constant(0u));
            ir_if *f0AC5 = new(mem_ctx) ir_if(operand(r0AC6).val);
            exec_list *const f0AC5_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AC5->then_instructions;

               body.emit(assign(r0AC4, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0AC5->else_instructions;

               body.emit(assign(r0AC4, body.constant(4294967295u), 0x01));


            body.instructions = f0AC5_parent_instructions;
            body.emit(f0AC5);

            /* END IF */

            body.emit(assign(r0A87, r0AC4, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AC1->else_instructions;

            ir_variable *const r0AC7 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r0AC8 = lshift(r0A88, body.constant(int(20)));
            ir_expression *const r0AC9 = rshift(r0A89, body.constant(int(12)));
            body.emit(assign(r0AC7, bit_or(r0AC8, r0AC9), 0x01));

            /* IF CONDITION */
            ir_expression *const r0ACB = nequal(r0A8E, body.constant(0u));
            ir_expression *const r0ACC = nequal(r0AC7, body.constant(0u));
            ir_expression *const r0ACD = logic_and(r0ACB, r0ACC);
            ir_if *f0ACA = new(mem_ctx) ir_if(operand(r0ACD).val);
            exec_list *const f0ACA_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0ACA->then_instructions;

               ir_variable *const r0ACE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0AD0 = nequal(r0A8E, body.constant(0u));
               ir_if *f0ACF = new(mem_ctx) ir_if(operand(r0AD0).val);
               exec_list *const f0ACF_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0ACF->then_instructions;

                  body.emit(assign(r0ACE, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0ACF->else_instructions;

                  body.emit(assign(r0ACE, body.constant(4294967295u), 0x01));


               body.instructions = f0ACF_parent_instructions;
               body.emit(f0ACF);

               /* END IF */

               body.emit(assign(r0A87, r0ACE, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0ACA->else_instructions;

               body.emit(assign(r0A87, r0AC7, 0x01));


            body.instructions = f0ACA_parent_instructions;
            body.emit(f0ACA);

            /* END IF */


         body.instructions = f0AC1_parent_instructions;
         body.emit(f0AC1);

         /* END IF */


      body.instructions = f0A91_parent_instructions;
      body.emit(f0A91);

      /* END IF */


   body.instructions = f0A8F_parent_instructions;
   body.emit(f0A8F);

   /* END IF */

   body.emit(ret(r0A87));

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

   ir_variable *const r0AD1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AD1);
   ir_variable *const r0AD2 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0AD3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0AD3);
   ir_variable *const r0AD4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0AD4);
   /* IF CONDITION */
   ir_expression *const r0AD6 = equal(r0AD1, body.constant(0u));
   ir_if *f0AD5 = new(mem_ctx) ir_if(operand(r0AD6).val);
   exec_list *const f0AD5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AD5->then_instructions;

      body.emit(assign(r0AD2, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AD5->else_instructions;

      ir_variable *const r0AD7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0AD8 = equal(r0AD1, body.constant(0u));
      ir_expression *const r0AD9 = expr(ir_unop_find_msb, r0AD1);
      ir_expression *const r0ADA = sub(body.constant(int(31)), r0AD9);
      ir_expression *const r0ADB = expr(ir_triop_csel, r0AD8, body.constant(int(32)), r0ADA);
      body.emit(assign(r0AD7, add(r0ADB, body.constant(int(21))), 0x01));

      body.emit(assign(r0AD4, body.constant(0u), 0x01));

      body.emit(assign(r0AD3, body.constant(0u), 0x01));

      ir_variable *const r0ADC = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0ADD = neg(r0AD7);
      body.emit(assign(r0ADC, bit_and(r0ADD, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0ADF = equal(r0AD7, body.constant(int(0)));
      ir_if *f0ADE = new(mem_ctx) ir_if(operand(r0ADF).val);
      exec_list *const f0ADE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0ADE->then_instructions;

         body.emit(assign(r0AD4, body.constant(0u), 0x01));

         body.emit(assign(r0AD3, r0AD1, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0ADE->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0AE1 = less(r0AD7, body.constant(int(32)));
         ir_if *f0AE0 = new(mem_ctx) ir_if(operand(r0AE1).val);
         exec_list *const f0AE0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AE0->then_instructions;

            body.emit(assign(r0AD4, rshift(r0AD1, r0ADC), 0x01));

            body.emit(assign(r0AD3, lshift(r0AD1, r0AD7), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AE0->else_instructions;

            ir_variable *const r0AE2 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0AE4 = less(r0AD7, body.constant(int(64)));
            ir_if *f0AE3 = new(mem_ctx) ir_if(operand(r0AE4).val);
            exec_list *const f0AE3_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AE3->then_instructions;

               ir_expression *const r0AE5 = add(r0AD7, body.constant(int(-32)));
               body.emit(assign(r0AE2, lshift(r0AD1, r0AE5), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0AE3->else_instructions;

               body.emit(assign(r0AE2, body.constant(0u), 0x01));


            body.instructions = f0AE3_parent_instructions;
            body.emit(f0AE3);

            /* END IF */

            body.emit(assign(r0AD4, r0AE2, 0x01));

            body.emit(assign(r0AD3, body.constant(0u), 0x01));


         body.instructions = f0AE0_parent_instructions;
         body.emit(f0AE0);

         /* END IF */


      body.instructions = f0ADE_parent_instructions;
      body.emit(f0ADE);

      /* END IF */

      ir_variable *const r0AE6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0AE6);
      ir_expression *const r0AE7 = sub(body.constant(int(1074)), r0AD7);
      ir_expression *const r0AE8 = expr(ir_unop_i2u, r0AE7);
      ir_expression *const r0AE9 = lshift(r0AE8, body.constant(int(20)));
      body.emit(assign(r0AE6, add(r0AE9, r0AD4), 0x02));

      body.emit(assign(r0AE6, r0AD3, 0x01));

      body.emit(assign(r0AD2, r0AE6, 0x03));


   body.instructions = f0AD5_parent_instructions;
   body.emit(f0AD5);

   /* END IF */

   body.emit(ret(r0AD2));

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

   ir_variable *const r0AEA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AEA);
   ir_variable *const r0AEB = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0AEB, body.constant(true), 0x01));

   ir_variable *const r0AEC = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0AED = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0AED);
   ir_variable *const r0AEE = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0AEE);
   ir_variable *const r0AEF = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0AEF);
   ir_variable *const r0AF0 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0AF0, bit_and(swizzle_y(r0AEA), body.constant(1048575u)), 0x01));

   body.emit(assign(r0AEF, r0AF0, 0x01));

   ir_variable *const r0AF1 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0AF2 = rshift(swizzle_y(r0AEA), body.constant(int(20)));
   ir_expression *const r0AF3 = bit_and(r0AF2, body.constant(2047u));
   body.emit(assign(r0AF1, expr(ir_unop_u2i, r0AF3), 0x01));

   body.emit(assign(r0AEE, rshift(swizzle_y(r0AEA), body.constant(int(31))), 0x01));

   body.emit(assign(r0AED, body.constant(0u), 0x01));

   ir_variable *const r0AF4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0AF4, add(r0AF1, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AF6 = gequal(r0AF4, body.constant(int(0)));
   ir_if *f0AF5 = new(mem_ctx) ir_if(operand(r0AF6).val);
   exec_list *const f0AF5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AF5->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0AF8 = less(body.constant(int(1054)), r0AF1);
      ir_if *f0AF7 = new(mem_ctx) ir_if(operand(r0AF8).val);
      exec_list *const f0AF7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AF7->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0AFA = equal(r0AF1, body.constant(int(2047)));
         ir_expression *const r0AFB = bit_or(r0AF0, swizzle_x(r0AEA));
         ir_expression *const r0AFC = expr(ir_unop_u2i, r0AFB);
         ir_expression *const r0AFD = expr(ir_unop_i2b, r0AFC);
         ir_expression *const r0AFE = logic_and(r0AFA, r0AFD);
         ir_if *f0AF9 = new(mem_ctx) ir_if(operand(r0AFE).val);
         exec_list *const f0AF9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AF9->then_instructions;

            body.emit(assign(r0AEE, body.constant(0u), 0x01));


         body.instructions = f0AF9_parent_instructions;
         body.emit(f0AF9);

         /* END IF */

         ir_variable *const r0AFF = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0B01 = expr(ir_unop_u2i, r0AEE);
         ir_expression *const r0B02 = expr(ir_unop_i2b, r0B01);
         ir_if *f0B00 = new(mem_ctx) ir_if(operand(r0B02).val);
         exec_list *const f0B00_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B00->then_instructions;

            body.emit(assign(r0AFF, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B00->else_instructions;

            body.emit(assign(r0AFF, body.constant(int(2147483647)), 0x01));


         body.instructions = f0B00_parent_instructions;
         body.emit(f0B00);

         /* END IF */

         body.emit(assign(r0AEC, r0AFF, 0x01));

         body.emit(assign(r0AEB, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AF7->else_instructions;

         ir_variable *const r0B03 = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r0B03, bit_or(r0AF0, body.constant(1048576u)), 0x01));

         ir_expression *const r0B04 = equal(r0AF4, body.constant(int(0)));
         ir_expression *const r0B05 = lshift(r0B03, r0AF4);
         ir_expression *const r0B06 = neg(r0AF4);
         ir_expression *const r0B07 = bit_and(r0B06, body.constant(int(31)));
         ir_expression *const r0B08 = rshift(swizzle_x(r0AEA), r0B07);
         ir_expression *const r0B09 = bit_or(r0B05, r0B08);
         body.emit(assign(r0AED, expr(ir_triop_csel, r0B04, r0B03, r0B09), 0x01));


      body.instructions = f0AF7_parent_instructions;
      body.emit(f0AF7);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AF5->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B0B = less(r0AF1, body.constant(int(1023)));
      ir_if *f0B0A = new(mem_ctx) ir_if(operand(r0B0B).val);
      exec_list *const f0B0A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B0A->then_instructions;

         body.emit(assign(r0AEC, body.constant(int(0)), 0x01));

         body.emit(assign(r0AEB, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B0A->else_instructions;

         body.emit(assign(r0AEF, bit_or(r0AF0, body.constant(1048576u)), 0x01));

         ir_expression *const r0B0C = neg(r0AF4);
         body.emit(assign(r0AED, rshift(r0AEF, r0B0C), 0x01));


      body.instructions = f0B0A_parent_instructions;
      body.emit(f0B0A);

      /* END IF */


   body.instructions = f0AF5_parent_instructions;
   body.emit(f0AF5);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0B0D = new(mem_ctx) ir_if(operand(r0AEB).val);
   exec_list *const f0B0D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B0D->then_instructions;

      ir_variable *const r0B0E = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0B10 = nequal(r0AEE, body.constant(0u));
      ir_if *f0B0F = new(mem_ctx) ir_if(operand(r0B10).val);
      exec_list *const f0B0F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B0F->then_instructions;

         ir_expression *const r0B11 = expr(ir_unop_u2i, r0AED);
         body.emit(assign(r0B0E, neg(r0B11), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B0F->else_instructions;

         body.emit(assign(r0B0E, expr(ir_unop_u2i, r0AED), 0x01));


      body.instructions = f0B0F_parent_instructions;
      body.emit(f0B0F);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0B13 = less(r0B0E, body.constant(int(0)));
      ir_expression *const r0B14 = expr(ir_unop_b2i, r0B13);
      ir_expression *const r0B15 = expr(ir_unop_i2u, r0B14);
      ir_expression *const r0B16 = bit_xor(r0AEE, r0B15);
      ir_expression *const r0B17 = expr(ir_unop_u2i, r0B16);
      ir_expression *const r0B18 = expr(ir_unop_i2b, r0B17);
      ir_expression *const r0B19 = expr(ir_unop_i2b, r0B0E);
      ir_expression *const r0B1A = logic_and(r0B18, r0B19);
      ir_if *f0B12 = new(mem_ctx) ir_if(operand(r0B1A).val);
      exec_list *const f0B12_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B12->then_instructions;

         ir_variable *const r0B1B = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0B1D = expr(ir_unop_u2i, r0AEE);
         ir_expression *const r0B1E = expr(ir_unop_i2b, r0B1D);
         ir_if *f0B1C = new(mem_ctx) ir_if(operand(r0B1E).val);
         exec_list *const f0B1C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B1C->then_instructions;

            body.emit(assign(r0B1B, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B1C->else_instructions;

            body.emit(assign(r0B1B, body.constant(int(2147483647)), 0x01));


         body.instructions = f0B1C_parent_instructions;
         body.emit(f0B1C);

         /* END IF */

         body.emit(assign(r0AEC, r0B1B, 0x01));

         body.emit(assign(r0AEB, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B12->else_instructions;

         body.emit(assign(r0AEC, r0B0E, 0x01));

         body.emit(assign(r0AEB, body.constant(false), 0x01));


      body.instructions = f0B12_parent_instructions;
      body.emit(f0B12);

      /* END IF */


   body.instructions = f0B0D_parent_instructions;
   body.emit(f0B0D);

   /* END IF */

   body.emit(ret(r0AEC));

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

   ir_variable *const r0B1F = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B1F);
   ir_variable *const r0B20 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B21 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0B21);
   ir_variable *const r0B22 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0B22);
   ir_variable *const r0B23 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0B23);
   body.emit(assign(r0B23, body.constant(0u), 0x01));

   body.emit(assign(r0B22, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B25 = equal(r0B1F, body.constant(int(0)));
   ir_if *f0B24 = new(mem_ctx) ir_if(operand(r0B25).val);
   exec_list *const f0B24_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B24->then_instructions;

      ir_variable *const r0B26 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0B26);
      body.emit(assign(r0B26, body.constant(0u), 0x02));

      body.emit(assign(r0B26, body.constant(0u), 0x01));

      body.emit(assign(r0B20, r0B26, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B24->else_instructions;

      ir_expression *const r0B27 = less(r0B1F, body.constant(int(0)));
      ir_expression *const r0B28 = expr(ir_unop_b2i, r0B27);
      body.emit(assign(r0B21, expr(ir_unop_i2u, r0B28), 0x01));

      ir_variable *const r0B29 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0B2B = less(r0B1F, body.constant(int(0)));
      ir_if *f0B2A = new(mem_ctx) ir_if(operand(r0B2B).val);
      exec_list *const f0B2A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B2A->then_instructions;

         ir_expression *const r0B2C = neg(r0B1F);
         body.emit(assign(r0B29, expr(ir_unop_i2u, r0B2C), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B2A->else_instructions;

         body.emit(assign(r0B29, expr(ir_unop_i2u, r0B1F), 0x01));


      body.instructions = f0B2A_parent_instructions;
      body.emit(f0B2A);

      /* END IF */

      ir_variable *const r0B2D = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0B2E = equal(r0B29, body.constant(0u));
      ir_expression *const r0B2F = expr(ir_unop_find_msb, r0B29);
      ir_expression *const r0B30 = sub(body.constant(int(31)), r0B2F);
      ir_expression *const r0B31 = expr(ir_triop_csel, r0B2E, body.constant(int(32)), r0B30);
      body.emit(assign(r0B2D, add(r0B31, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B33 = gequal(r0B2D, body.constant(int(0)));
      ir_if *f0B32 = new(mem_ctx) ir_if(operand(r0B33).val);
      exec_list *const f0B32_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B32->then_instructions;

         body.emit(assign(r0B23, lshift(r0B29, r0B2D), 0x01));

         body.emit(assign(r0B22, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B32->else_instructions;

         ir_variable *const r0B34 = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r0B34, neg(r0B2D), 0x01));

         ir_expression *const r0B35 = equal(r0B34, body.constant(int(0)));
         ir_expression *const r0B36 = less(r0B34, body.constant(int(32)));
         ir_expression *const r0B37 = rshift(r0B29, r0B34);
         ir_expression *const r0B38 = expr(ir_triop_csel, r0B36, r0B37, body.constant(0u));
         body.emit(assign(r0B23, expr(ir_triop_csel, r0B35, r0B29, r0B38), 0x01));

         ir_expression *const r0B39 = equal(r0B34, body.constant(int(0)));
         ir_expression *const r0B3A = less(r0B34, body.constant(int(32)));
         ir_expression *const r0B3B = neg(r0B34);
         ir_expression *const r0B3C = bit_and(r0B3B, body.constant(int(31)));
         ir_expression *const r0B3D = lshift(r0B29, r0B3C);
         ir_expression *const r0B3E = bit_or(r0B3D, body.constant(0u));
         ir_expression *const r0B3F = less(r0B34, body.constant(int(64)));
         ir_expression *const r0B40 = bit_and(r0B34, body.constant(int(31)));
         ir_expression *const r0B41 = rshift(r0B29, r0B40);
         ir_expression *const r0B42 = expr(ir_triop_csel, r0B3F, r0B41, body.constant(0u));
         ir_expression *const r0B43 = expr(ir_triop_csel, r0B3A, r0B3E, r0B42);
         body.emit(assign(r0B22, expr(ir_triop_csel, r0B39, r0B29, r0B43), 0x01));


      body.instructions = f0B32_parent_instructions;
      body.emit(f0B32);

      /* END IF */

      ir_variable *const r0B44 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0B44);
      ir_expression *const r0B45 = lshift(r0B21, body.constant(int(31)));
      ir_expression *const r0B46 = sub(body.constant(int(1042)), r0B2D);
      ir_expression *const r0B47 = expr(ir_unop_i2u, r0B46);
      ir_expression *const r0B48 = lshift(r0B47, body.constant(int(20)));
      ir_expression *const r0B49 = add(r0B45, r0B48);
      body.emit(assign(r0B44, add(r0B49, r0B23), 0x02));

      body.emit(assign(r0B44, r0B22, 0x01));

      body.emit(assign(r0B20, r0B44, 0x03));


   body.instructions = f0B24_parent_instructions;
   body.emit(f0B24);

   /* END IF */

   body.emit(ret(r0B20));

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

   ir_variable *const r0B4A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0B4A);
   ir_variable *const r0B4B = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0B4B);
   ir_variable *const r0B4C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0B4C);
   ir_variable *const r0B4D = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r0B4E = lshift(r0B4A, body.constant(int(31)));
   ir_expression *const r0B4F = expr(ir_unop_i2u, r0B4B);
   ir_expression *const r0B50 = lshift(r0B4F, body.constant(int(23)));
   ir_expression *const r0B51 = add(r0B4E, r0B50);
   ir_expression *const r0B52 = add(r0B51, r0B4C);
   body.emit(assign(r0B4D, expr(ir_unop_bitcast_u2f, r0B52), 0x01));

   body.emit(ret(r0B4D));

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

   ir_variable *const r0B53 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0B53);
   ir_variable *const r0B54 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0B54);
   ir_variable *const r0B55 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0B55);
   ir_variable *const r0B56 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B56, body.constant(true), 0x01));

   ir_variable *const r0B57 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B58 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0B58);
   ir_expression *const r0B59 = bit_and(r0B55, body.constant(127u));
   body.emit(assign(r0B58, expr(ir_unop_u2i, r0B59), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B5B = expr(ir_unop_i2u, r0B54);
   ir_expression *const r0B5C = gequal(r0B5B, body.constant(253u));
   ir_if *f0B5A = new(mem_ctx) ir_if(operand(r0B5C).val);
   exec_list *const f0B5A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B5A->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B5E = less(body.constant(int(253)), r0B54);
      ir_expression *const r0B5F = equal(r0B54, body.constant(int(253)));
      ir_expression *const r0B60 = expr(ir_unop_u2i, r0B55);
      ir_expression *const r0B61 = less(r0B60, body.constant(int(-64)));
      ir_expression *const r0B62 = logic_and(r0B5F, r0B61);
      ir_expression *const r0B63 = logic_or(r0B5E, r0B62);
      ir_if *f0B5D = new(mem_ctx) ir_if(operand(r0B63).val);
      exec_list *const f0B5D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B5D->then_instructions;

         ir_expression *const r0B64 = lshift(r0B53, body.constant(int(31)));
         ir_expression *const r0B65 = add(r0B64, body.constant(2139095040u));
         body.emit(assign(r0B57, expr(ir_unop_bitcast_u2f, r0B65), 0x01));

         body.emit(assign(r0B56, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B5D->else_instructions;

         ir_variable *const r0B66 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0B66, neg(r0B54), 0x01));

         ir_variable *const r0B67 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
         body.emit(assign(r0B67, less(r0B54, body.constant(int(0))), 0x01));

         ir_variable *const r0B68 = body.make_temp(glsl_type::uint_type, "mix_retval");
         ir_expression *const r0B69 = neg(r0B54);
         ir_expression *const r0B6A = less(r0B69, body.constant(int(32)));
         ir_expression *const r0B6B = rshift(r0B55, r0B66);
         ir_expression *const r0B6C = neg(r0B66);
         ir_expression *const r0B6D = bit_and(r0B6C, body.constant(int(31)));
         ir_expression *const r0B6E = lshift(r0B55, r0B6D);
         ir_expression *const r0B6F = nequal(r0B6E, body.constant(0u));
         ir_expression *const r0B70 = expr(ir_unop_b2i, r0B6F);
         ir_expression *const r0B71 = expr(ir_unop_i2u, r0B70);
         ir_expression *const r0B72 = bit_or(r0B6B, r0B71);
         ir_expression *const r0B73 = nequal(r0B55, body.constant(0u));
         ir_expression *const r0B74 = expr(ir_unop_b2i, r0B73);
         ir_expression *const r0B75 = expr(ir_unop_i2u, r0B74);
         ir_expression *const r0B76 = expr(ir_triop_csel, r0B6A, r0B72, r0B75);
         body.emit(assign(r0B68, expr(ir_triop_csel, r0B67, r0B76, r0B55), 0x01));

         body.emit(assign(r0B55, r0B68, 0x01));

         ir_expression *const r0B77 = expr(ir_unop_u2i, r0B68);
         ir_expression *const r0B78 = bit_and(r0B77, body.constant(int(127)));
         body.emit(assign(r0B58, expr(ir_triop_csel, r0B67, r0B78, r0B58), 0x01));

         body.emit(assign(r0B54, expr(ir_triop_csel, r0B67, body.constant(int(0)), r0B54), 0x01));


      body.instructions = f0B5D_parent_instructions;
      body.emit(f0B5D);

      /* END IF */


   body.instructions = f0B5A_parent_instructions;
   body.emit(f0B5A);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0B79 = new(mem_ctx) ir_if(operand(r0B56).val);
   exec_list *const f0B79_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B79->then_instructions;

      ir_expression *const r0B7A = add(r0B55, body.constant(64u));
      body.emit(assign(r0B55, rshift(r0B7A, body.constant(int(7))), 0x01));

      ir_expression *const r0B7B = bit_xor(r0B58, body.constant(int(64)));
      ir_expression *const r0B7C = equal(r0B7B, body.constant(int(0)));
      ir_expression *const r0B7D = expr(ir_unop_b2i, r0B7C);
      ir_expression *const r0B7E = expr(ir_unop_i2u, r0B7D);
      ir_expression *const r0B7F = expr(ir_unop_bit_not, r0B7E);
      body.emit(assign(r0B55, bit_and(r0B55, r0B7F), 0x01));

      ir_expression *const r0B80 = lshift(r0B53, body.constant(int(31)));
      ir_expression *const r0B81 = equal(r0B55, body.constant(0u));
      ir_expression *const r0B82 = expr(ir_triop_csel, r0B81, body.constant(int(0)), r0B54);
      ir_expression *const r0B83 = expr(ir_unop_i2u, r0B82);
      ir_expression *const r0B84 = lshift(r0B83, body.constant(int(23)));
      ir_expression *const r0B85 = add(r0B80, r0B84);
      ir_expression *const r0B86 = add(r0B85, r0B55);
      body.emit(assign(r0B57, expr(ir_unop_bitcast_u2f, r0B86), 0x01));

      body.emit(assign(r0B56, body.constant(false), 0x01));


   body.instructions = f0B79_parent_instructions;
   body.emit(f0B79);

   /* END IF */

   body.emit(ret(r0B57));

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

   ir_variable *const r0B87 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B87);
   ir_variable *const r0B88 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B89 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0B89, swizzle_x(r0B87), 0x01));

   ir_variable *const r0B8A = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B8A, bit_and(swizzle_y(r0B87), body.constant(1048575u)), 0x01));

   ir_variable *const r0B8B = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B8C = rshift(swizzle_y(r0B87), body.constant(int(20)));
   ir_expression *const r0B8D = bit_and(r0B8C, body.constant(2047u));
   body.emit(assign(r0B8B, expr(ir_unop_u2i, r0B8D), 0x01));

   ir_variable *const r0B8E = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B8E, rshift(swizzle_y(r0B87), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B90 = equal(r0B8B, body.constant(int(2047)));
   ir_if *f0B8F = new(mem_ctx) ir_if(operand(r0B90).val);
   exec_list *const f0B8F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B8F->then_instructions;

      ir_variable *const r0B91 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0B91);
      ir_variable *const r0B92 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0B92, lshift(swizzle_x(r0B87), body.constant(int(12))), 0x01));

      ir_expression *const r0B93 = lshift(swizzle_y(r0B87), body.constant(int(12)));
      ir_expression *const r0B94 = rshift(swizzle_x(r0B87), body.constant(int(20)));
      body.emit(assign(r0B87, bit_or(r0B93, r0B94), 0x02));

      body.emit(assign(r0B87, r0B92, 0x01));

      ir_expression *const r0B95 = lshift(r0B8E, body.constant(int(31)));
      ir_expression *const r0B96 = bit_or(r0B95, body.constant(2143289344u));
      ir_expression *const r0B97 = rshift(swizzle_y(r0B87), body.constant(int(9)));
      ir_expression *const r0B98 = bit_or(r0B96, r0B97);
      body.emit(assign(r0B91, expr(ir_unop_bitcast_u2f, r0B98), 0x01));

      ir_variable *const r0B99 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0B9A = bit_or(r0B8A, r0B89);
      ir_expression *const r0B9B = nequal(r0B9A, body.constant(0u));
      ir_expression *const r0B9C = lshift(r0B8E, body.constant(int(31)));
      ir_expression *const r0B9D = add(r0B9C, body.constant(2139095040u));
      ir_expression *const r0B9E = expr(ir_unop_bitcast_u2f, r0B9D);
      body.emit(assign(r0B99, expr(ir_triop_csel, r0B9B, r0B91, r0B9E), 0x01));

      body.emit(assign(r0B91, r0B99, 0x01));

      body.emit(assign(r0B88, r0B99, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B8F->else_instructions;

      ir_variable *const r0B9F = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0BA0 = lshift(r0B8A, body.constant(int(10)));
      ir_expression *const r0BA1 = rshift(r0B89, body.constant(int(22)));
      ir_expression *const r0BA2 = bit_or(r0BA0, r0BA1);
      ir_expression *const r0BA3 = lshift(r0B89, body.constant(int(10)));
      ir_expression *const r0BA4 = nequal(r0BA3, body.constant(0u));
      ir_expression *const r0BA5 = expr(ir_unop_b2i, r0BA4);
      ir_expression *const r0BA6 = expr(ir_unop_i2u, r0BA5);
      body.emit(assign(r0B9F, bit_or(r0BA2, r0BA6), 0x01));

      ir_variable *const r0BA7 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0BA8 = nequal(r0B8B, body.constant(int(0)));
      ir_expression *const r0BA9 = bit_or(r0B9F, body.constant(1073741824u));
      body.emit(assign(r0BA7, expr(ir_triop_csel, r0BA8, r0BA9, r0B9F), 0x01));

      ir_variable *const r0BAA = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0BAA, add(r0B8B, body.constant(int(-897))), 0x01));

      ir_variable *const r0BAB = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0BAB, r0BA7, 0x01));

      ir_variable *const r0BAC = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0BAC, body.constant(true), 0x01));

      ir_variable *const r0BAD = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0BAE = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0BAE);
      ir_expression *const r0BAF = bit_and(r0BA7, body.constant(127u));
      body.emit(assign(r0BAE, expr(ir_unop_u2i, r0BAF), 0x01));

      /* IF CONDITION */
      ir_expression *const r0BB1 = expr(ir_unop_i2u, r0BAA);
      ir_expression *const r0BB2 = gequal(r0BB1, body.constant(253u));
      ir_if *f0BB0 = new(mem_ctx) ir_if(operand(r0BB2).val);
      exec_list *const f0BB0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BB0->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0BB4 = less(body.constant(int(253)), r0BAA);
         ir_expression *const r0BB5 = equal(r0BAA, body.constant(int(253)));
         ir_expression *const r0BB6 = expr(ir_unop_u2i, r0BA7);
         ir_expression *const r0BB7 = less(r0BB6, body.constant(int(-64)));
         ir_expression *const r0BB8 = logic_and(r0BB5, r0BB7);
         ir_expression *const r0BB9 = logic_or(r0BB4, r0BB8);
         ir_if *f0BB3 = new(mem_ctx) ir_if(operand(r0BB9).val);
         exec_list *const f0BB3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BB3->then_instructions;

            ir_expression *const r0BBA = lshift(r0B8E, body.constant(int(31)));
            ir_expression *const r0BBB = add(r0BBA, body.constant(2139095040u));
            body.emit(assign(r0BAD, expr(ir_unop_bitcast_u2f, r0BBB), 0x01));

            body.emit(assign(r0BAC, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BB3->else_instructions;

            ir_variable *const r0BBC = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0BBC, neg(r0BAA), 0x01));

            ir_variable *const r0BBD = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0BBD, less(r0BAA, body.constant(int(0))), 0x01));

            ir_variable *const r0BBE = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0BBF = neg(r0BAA);
            ir_expression *const r0BC0 = less(r0BBF, body.constant(int(32)));
            ir_expression *const r0BC1 = rshift(r0BA7, r0BBC);
            ir_expression *const r0BC2 = neg(r0BBC);
            ir_expression *const r0BC3 = bit_and(r0BC2, body.constant(int(31)));
            ir_expression *const r0BC4 = lshift(r0BA7, r0BC3);
            ir_expression *const r0BC5 = nequal(r0BC4, body.constant(0u));
            ir_expression *const r0BC6 = expr(ir_unop_b2i, r0BC5);
            ir_expression *const r0BC7 = expr(ir_unop_i2u, r0BC6);
            ir_expression *const r0BC8 = bit_or(r0BC1, r0BC7);
            ir_expression *const r0BC9 = nequal(r0BA7, body.constant(0u));
            ir_expression *const r0BCA = expr(ir_unop_b2i, r0BC9);
            ir_expression *const r0BCB = expr(ir_unop_i2u, r0BCA);
            ir_expression *const r0BCC = expr(ir_triop_csel, r0BC0, r0BC8, r0BCB);
            body.emit(assign(r0BBE, expr(ir_triop_csel, r0BBD, r0BCC, r0BA7), 0x01));

            body.emit(assign(r0BAB, r0BBE, 0x01));

            ir_expression *const r0BCD = expr(ir_unop_u2i, r0BBE);
            ir_expression *const r0BCE = bit_and(r0BCD, body.constant(int(127)));
            body.emit(assign(r0BAE, expr(ir_triop_csel, r0BBD, r0BCE, r0BAE), 0x01));

            body.emit(assign(r0BAA, expr(ir_triop_csel, r0BBD, body.constant(int(0)), r0BAA), 0x01));


         body.instructions = f0BB3_parent_instructions;
         body.emit(f0BB3);

         /* END IF */


      body.instructions = f0BB0_parent_instructions;
      body.emit(f0BB0);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0BCF = new(mem_ctx) ir_if(operand(r0BAC).val);
      exec_list *const f0BCF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BCF->then_instructions;

         ir_expression *const r0BD0 = add(r0BAB, body.constant(64u));
         body.emit(assign(r0BAB, rshift(r0BD0, body.constant(int(7))), 0x01));

         ir_expression *const r0BD1 = bit_xor(r0BAE, body.constant(int(64)));
         ir_expression *const r0BD2 = equal(r0BD1, body.constant(int(0)));
         ir_expression *const r0BD3 = expr(ir_unop_b2i, r0BD2);
         ir_expression *const r0BD4 = expr(ir_unop_i2u, r0BD3);
         ir_expression *const r0BD5 = expr(ir_unop_bit_not, r0BD4);
         body.emit(assign(r0BAB, bit_and(r0BAB, r0BD5), 0x01));

         ir_expression *const r0BD6 = lshift(r0B8E, body.constant(int(31)));
         ir_expression *const r0BD7 = equal(r0BAB, body.constant(0u));
         ir_expression *const r0BD8 = expr(ir_triop_csel, r0BD7, body.constant(int(0)), r0BAA);
         ir_expression *const r0BD9 = expr(ir_unop_i2u, r0BD8);
         ir_expression *const r0BDA = lshift(r0BD9, body.constant(int(23)));
         ir_expression *const r0BDB = add(r0BD6, r0BDA);
         ir_expression *const r0BDC = add(r0BDB, r0BAB);
         body.emit(assign(r0BAD, expr(ir_unop_bitcast_u2f, r0BDC), 0x01));

         body.emit(assign(r0BAC, body.constant(false), 0x01));


      body.instructions = f0BCF_parent_instructions;
      body.emit(f0BCF);

      /* END IF */

      body.emit(assign(r0B88, r0BAD, 0x01));


   body.instructions = f0B8F_parent_instructions;
   body.emit(f0B8F);

   /* END IF */

   body.emit(ret(r0B88));

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

   ir_variable *const r0BDD = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0BDD);
   ir_variable *const r0BDE = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0BDE, body.constant(true), 0x01));

   ir_variable *const r0BDF = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0BE0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0BE0);
   ir_variable *const r0BE1 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0BE1);
   ir_variable *const r0BE2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0BE2);
   ir_variable *const r0BE3 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0BE3, expr(ir_unop_bitcast_f2u, r0BDD), 0x01));

   ir_variable *const r0BE4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BE4, bit_and(r0BE3, body.constant(8388607u)), 0x01));

   body.emit(assign(r0BE2, r0BE4, 0x01));

   ir_variable *const r0BE5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0BE6 = rshift(r0BE3, body.constant(int(23)));
   ir_expression *const r0BE7 = bit_and(r0BE6, body.constant(255u));
   body.emit(assign(r0BE5, expr(ir_unop_u2i, r0BE7), 0x01));

   body.emit(assign(r0BE1, r0BE5, 0x01));

   body.emit(assign(r0BE0, rshift(r0BE3, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BE9 = equal(r0BE5, body.constant(int(255)));
   ir_if *f0BE8 = new(mem_ctx) ir_if(operand(r0BE9).val);
   exec_list *const f0BE8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BE8->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0BEB = nequal(r0BE4, body.constant(0u));
      ir_if *f0BEA = new(mem_ctx) ir_if(operand(r0BEB).val);
      exec_list *const f0BEA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BEA->then_instructions;

         ir_variable *const r0BEC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0BEC, lshift(r0BE3, body.constant(int(9))), 0x01));

         ir_variable *const r0BED = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0BEE = lshift(r0BEC, body.constant(int(20)));
         body.emit(assign(r0BED, bit_or(r0BEE, body.constant(0u)), 0x01));

         ir_expression *const r0BEF = rshift(r0BEC, body.constant(int(12)));
         ir_expression *const r0BF0 = lshift(r0BE0, body.constant(int(31)));
         ir_expression *const r0BF1 = bit_or(r0BF0, body.constant(2146959360u));
         body.emit(assign(r0BED, bit_or(r0BEF, r0BF1), 0x02));

         body.emit(assign(r0BDF, r0BED, 0x03));

         body.emit(assign(r0BDE, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BEA->else_instructions;

         ir_variable *const r0BF2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0BF2);
         ir_expression *const r0BF3 = lshift(r0BE0, body.constant(int(31)));
         body.emit(assign(r0BF2, add(r0BF3, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0BF2, body.constant(0u), 0x01));

         body.emit(assign(r0BDF, r0BF2, 0x03));

         body.emit(assign(r0BDE, body.constant(false), 0x01));


      body.instructions = f0BEA_parent_instructions;
      body.emit(f0BEA);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BE8->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0BF5 = equal(r0BE5, body.constant(int(0)));
      ir_if *f0BF4 = new(mem_ctx) ir_if(operand(r0BF5).val);
      exec_list *const f0BF4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BF4->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0BF7 = equal(r0BE4, body.constant(0u));
         ir_if *f0BF6 = new(mem_ctx) ir_if(operand(r0BF7).val);
         exec_list *const f0BF6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BF6->then_instructions;

            ir_variable *const r0BF8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0BF8);
            body.emit(assign(r0BF8, lshift(r0BE0, body.constant(int(31))), 0x02));

            body.emit(assign(r0BF8, body.constant(0u), 0x01));

            body.emit(assign(r0BDF, r0BF8, 0x03));

            body.emit(assign(r0BDE, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BF6->else_instructions;

            ir_variable *const r0BF9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0BFA = equal(r0BE4, body.constant(0u));
            ir_expression *const r0BFB = expr(ir_unop_find_msb, r0BE4);
            ir_expression *const r0BFC = sub(body.constant(int(31)), r0BFB);
            ir_expression *const r0BFD = expr(ir_triop_csel, r0BFA, body.constant(int(32)), r0BFC);
            body.emit(assign(r0BF9, add(r0BFD, body.constant(int(-8))), 0x01));

            body.emit(assign(r0BE2, lshift(r0BE4, r0BF9), 0x01));

            body.emit(assign(r0BE1, sub(body.constant(int(1)), r0BF9), 0x01));

            body.emit(assign(r0BE1, add(r0BE1, body.constant(int(-1))), 0x01));


         body.instructions = f0BF6_parent_instructions;
         body.emit(f0BF6);

         /* END IF */


      body.instructions = f0BF4_parent_instructions;
      body.emit(f0BF4);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0BFE = new(mem_ctx) ir_if(operand(r0BDE).val);
      exec_list *const f0BFE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BFE->then_instructions;

         ir_variable *const r0BFF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0BFF);
         ir_expression *const r0C00 = lshift(r0BE0, body.constant(int(31)));
         ir_expression *const r0C01 = add(r0BE1, body.constant(int(896)));
         ir_expression *const r0C02 = expr(ir_unop_i2u, r0C01);
         ir_expression *const r0C03 = lshift(r0C02, body.constant(int(20)));
         ir_expression *const r0C04 = add(r0C00, r0C03);
         ir_expression *const r0C05 = rshift(r0BE2, body.constant(int(3)));
         body.emit(assign(r0BFF, add(r0C04, r0C05), 0x02));

         ir_expression *const r0C06 = lshift(r0BE2, body.constant(int(29)));
         body.emit(assign(r0BFF, bit_or(r0C06, body.constant(0u)), 0x01));

         body.emit(assign(r0BDF, r0BFF, 0x03));

         body.emit(assign(r0BDE, body.constant(false), 0x01));


      body.instructions = f0BFE_parent_instructions;
      body.emit(f0BFE);

      /* END IF */


   body.instructions = f0BE8_parent_instructions;
   body.emit(f0BE8);

   /* END IF */

   body.emit(ret(r0BDF));

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

   ir_variable *const r0C07 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0C07);
   ir_variable *const r0C08 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0C08);
   ir_variable *const r0C09 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0C09);
   ir_variable *const r0C0A = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0C0A);
   ir_variable *const r0C0B = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0C0B);
   ir_variable *const r0C0C = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0C0C);
   ir_variable *const r0C0D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0C0D);
   ir_variable *const r0C0E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0C0E);
   ir_variable *const r0C0F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0C0F);
   ir_variable *const r0C10 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0C10);
   ir_variable *const r0C11 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0C11);
   ir_variable *const r0C12 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C12, add(r0C09, r0C0C), 0x01));

   ir_variable *const r0C13 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0C14 = less(r0C12, r0C09);
   ir_expression *const r0C15 = expr(ir_unop_b2i, r0C14);
   body.emit(assign(r0C13, expr(ir_unop_i2u, r0C15), 0x01));

   ir_variable *const r0C16 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C16, add(r0C08, r0C0B), 0x01));

   body.emit(assign(r0C11, add(r0C16, r0C13), 0x01));

   ir_expression *const r0C17 = add(r0C07, r0C0A);
   ir_expression *const r0C18 = less(r0C11, r0C13);
   ir_expression *const r0C19 = expr(ir_unop_b2i, r0C18);
   ir_expression *const r0C1A = expr(ir_unop_i2u, r0C19);
   body.emit(assign(r0C10, add(r0C17, r0C1A), 0x01));

   ir_expression *const r0C1B = less(r0C16, r0C08);
   ir_expression *const r0C1C = expr(ir_unop_b2i, r0C1B);
   ir_expression *const r0C1D = expr(ir_unop_i2u, r0C1C);
   body.emit(assign(r0C10, add(r0C10, r0C1D), 0x01));

   body.emit(assign(r0C0F, r0C12, 0x01));

   body.emit(assign(r0C0E, r0C11, 0x01));

   body.emit(assign(r0C0D, r0C10, 0x01));

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

   ir_variable *const r0C1E = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0C1E);
   ir_variable *const r0C1F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0C1F);
   ir_variable *const r0C20 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0C20);
   ir_variable *const r0C21 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0C21);
   ir_variable *const r0C22 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0C22);
   ir_variable *const r0C23 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0C23);
   ir_variable *const r0C24 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0C24);
   ir_variable *const r0C25 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0C25);
   ir_variable *const r0C26 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0C26);
   ir_variable *const r0C27 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0C27);
   ir_variable *const r0C28 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0C29 = less(r0C20, r0C23);
   ir_expression *const r0C2A = expr(ir_unop_b2i, r0C29);
   body.emit(assign(r0C28, expr(ir_unop_i2u, r0C2A), 0x01));

   ir_variable *const r0C2B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C2B, sub(r0C1F, r0C22), 0x01));

   ir_expression *const r0C2C = sub(r0C1E, r0C21);
   ir_expression *const r0C2D = less(r0C2B, r0C28);
   ir_expression *const r0C2E = expr(ir_unop_b2i, r0C2D);
   ir_expression *const r0C2F = expr(ir_unop_i2u, r0C2E);
   body.emit(assign(r0C27, sub(r0C2C, r0C2F), 0x01));

   ir_expression *const r0C30 = less(r0C1F, r0C22);
   ir_expression *const r0C31 = expr(ir_unop_b2i, r0C30);
   ir_expression *const r0C32 = expr(ir_unop_i2u, r0C31);
   body.emit(assign(r0C27, sub(r0C27, r0C32), 0x01));

   body.emit(assign(r0C26, sub(r0C20, r0C23), 0x01));

   body.emit(assign(r0C25, sub(r0C2B, r0C28), 0x01));

   body.emit(assign(r0C24, r0C27, 0x01));

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

   ir_variable *const r0C33 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0C33);
   ir_variable *const r0C34 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0C34);
   ir_variable *const r0C35 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0C35);
   ir_variable *const r0C36 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0C37 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0C37);
   ir_variable *const r0C38 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0C38);
   ir_variable *const r0C39 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0C39);
   ir_variable *const r0C3A = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0C3A);
   body.emit(assign(r0C39, body.constant(0u), 0x01));

   body.emit(assign(r0C38, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C3C = gequal(r0C33, r0C35);
   ir_if *f0C3B = new(mem_ctx) ir_if(operand(r0C3C).val);
   exec_list *const f0C3B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C3B->then_instructions;

      body.emit(assign(r0C36, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C3B->else_instructions;

      body.emit(assign(r0C3A, rshift(r0C35, body.constant(int(16))), 0x01));

      ir_variable *const r0C3D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0C3F = lshift(r0C3A, body.constant(int(16)));
      ir_expression *const r0C40 = gequal(r0C33, r0C3F);
      ir_if *f0C3E = new(mem_ctx) ir_if(operand(r0C40).val);
      exec_list *const f0C3E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C3E->then_instructions;

         body.emit(assign(r0C3D, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C3E->else_instructions;

         ir_expression *const r0C41 = expr(ir_binop_div, r0C33, r0C3A);
         body.emit(assign(r0C3D, lshift(r0C41, body.constant(int(16))), 0x01));


      body.instructions = f0C3E_parent_instructions;
      body.emit(f0C3E);

      /* END IF */

      body.emit(assign(r0C37, r0C3D, 0x01));

      ir_variable *const r0C42 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0C42);
      ir_variable *const r0C43 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0C43);
      ir_variable *const r0C44 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0C44);
      ir_variable *const r0C45 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0C45, bit_and(r0C35, body.constant(65535u)), 0x01));

      ir_variable *const r0C46 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0C46, rshift(r0C35, body.constant(int(16))), 0x01));

      ir_variable *const r0C47 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0C47, bit_and(r0C3D, body.constant(65535u)), 0x01));

      ir_variable *const r0C48 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0C48, rshift(r0C3D, body.constant(int(16))), 0x01));

      ir_variable *const r0C49 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0C49, mul(r0C46, r0C47), 0x01));

      ir_expression *const r0C4A = mul(r0C45, r0C48);
      body.emit(assign(r0C43, add(r0C4A, r0C49), 0x01));

      ir_expression *const r0C4B = mul(r0C46, r0C48);
      ir_expression *const r0C4C = less(r0C43, r0C49);
      ir_expression *const r0C4D = expr(ir_unop_b2i, r0C4C);
      ir_expression *const r0C4E = expr(ir_unop_i2u, r0C4D);
      ir_expression *const r0C4F = lshift(r0C4E, body.constant(int(16)));
      ir_expression *const r0C50 = rshift(r0C43, body.constant(int(16)));
      ir_expression *const r0C51 = add(r0C4F, r0C50);
      body.emit(assign(r0C42, add(r0C4B, r0C51), 0x01));

      body.emit(assign(r0C43, lshift(r0C43, body.constant(int(16))), 0x01));

      ir_expression *const r0C52 = mul(r0C45, r0C47);
      body.emit(assign(r0C44, add(r0C52, r0C43), 0x01));

      ir_expression *const r0C53 = less(r0C44, r0C43);
      ir_expression *const r0C54 = expr(ir_unop_b2i, r0C53);
      ir_expression *const r0C55 = expr(ir_unop_i2u, r0C54);
      body.emit(assign(r0C42, add(r0C42, r0C55), 0x01));

      ir_expression *const r0C56 = sub(r0C33, r0C42);
      ir_expression *const r0C57 = less(r0C34, r0C44);
      ir_expression *const r0C58 = expr(ir_unop_b2i, r0C57);
      ir_expression *const r0C59 = expr(ir_unop_i2u, r0C58);
      body.emit(assign(r0C39, sub(r0C56, r0C59), 0x01));

      body.emit(assign(r0C38, sub(r0C34, r0C44), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0C5A = new(mem_ctx) ir_loop();
      exec_list *const f0C5A_parent_instructions = body.instructions;

         body.instructions = &f0C5A->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0C5C = expr(ir_unop_u2i, r0C39);
         ir_expression *const r0C5D = gequal(r0C5C, body.constant(int(0)));
         ir_if *f0C5B = new(mem_ctx) ir_if(operand(r0C5D).val);
         exec_list *const f0C5B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C5B->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0C5B_parent_instructions;
         body.emit(f0C5B);

         /* END IF */

         body.emit(assign(r0C37, add(r0C37, body.constant(4294901760u)), 0x01));

         ir_variable *const r0C5E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0C5F = lshift(r0C35, body.constant(int(16)));
         body.emit(assign(r0C5E, add(r0C38, r0C5F), 0x01));

         ir_expression *const r0C60 = add(r0C39, r0C3A);
         ir_expression *const r0C61 = less(r0C5E, r0C38);
         ir_expression *const r0C62 = expr(ir_unop_b2i, r0C61);
         ir_expression *const r0C63 = expr(ir_unop_i2u, r0C62);
         body.emit(assign(r0C39, add(r0C60, r0C63), 0x01));

         body.emit(assign(r0C38, r0C5E, 0x01));

      /* LOOP END */

      body.instructions = f0C5A_parent_instructions;
      body.emit(f0C5A);

      ir_expression *const r0C64 = lshift(r0C39, body.constant(int(16)));
      ir_expression *const r0C65 = rshift(r0C38, body.constant(int(16)));
      body.emit(assign(r0C39, bit_or(r0C64, r0C65), 0x01));

      ir_variable *const r0C66 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0C68 = lshift(r0C3A, body.constant(int(16)));
      ir_expression *const r0C69 = gequal(r0C39, r0C68);
      ir_if *f0C67 = new(mem_ctx) ir_if(operand(r0C69).val);
      exec_list *const f0C67_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C67->then_instructions;

         body.emit(assign(r0C66, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C67->else_instructions;

         body.emit(assign(r0C66, expr(ir_binop_div, r0C39, r0C3A), 0x01));


      body.instructions = f0C67_parent_instructions;
      body.emit(f0C67);

      /* END IF */

      body.emit(assign(r0C37, bit_or(r0C37, r0C66), 0x01));

      body.emit(assign(r0C36, r0C37, 0x01));


   body.instructions = f0C3B_parent_instructions;
   body.emit(f0C3B);

   /* END IF */

   body.emit(ret(r0C36));

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

   ir_variable *const r0C6A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C6A);
   ir_variable *const r0C6B = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0C6B, r0C6A, 0x03));

   ir_variable *const r0C6C = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0C6D = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0C6D, bit_and(swizzle_y(r0C6A), body.constant(1048575u)), 0x01));

   ir_variable *const r0C6E = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0C6F = rshift(swizzle_y(r0C6A), body.constant(int(20)));
   ir_expression *const r0C70 = bit_and(r0C6F, body.constant(2047u));
   body.emit(assign(r0C6E, expr(ir_unop_u2i, r0C70), 0x01));

   ir_variable *const r0C71 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0C71, rshift(swizzle_y(r0C6A), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C73 = equal(r0C6E, body.constant(int(2047)));
   ir_if *f0C72 = new(mem_ctx) ir_if(operand(r0C73).val);
   exec_list *const f0C72_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C72->then_instructions;

      ir_variable *const r0C74 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0C74);
      ir_expression *const r0C75 = lshift(swizzle_y(r0C6A), body.constant(int(12)));
      ir_expression *const r0C76 = rshift(swizzle_x(r0C6A), body.constant(int(20)));
      body.emit(assign(r0C6B, bit_or(r0C75, r0C76), 0x02));

      body.emit(assign(r0C6B, lshift(swizzle_x(r0C6A), body.constant(int(12))), 0x01));

      ir_expression *const r0C77 = lshift(r0C71, body.constant(int(31)));
      ir_expression *const r0C78 = bit_or(r0C77, body.constant(2143289344u));
      ir_expression *const r0C79 = rshift(swizzle_y(r0C6B), body.constant(int(9)));
      ir_expression *const r0C7A = bit_or(r0C78, r0C79);
      body.emit(assign(r0C74, expr(ir_unop_bitcast_u2f, r0C7A), 0x01));

      ir_variable *const r0C7B = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0C7C = bit_or(r0C6D, swizzle_x(r0C6A));
      ir_expression *const r0C7D = nequal(r0C7C, body.constant(0u));
      ir_expression *const r0C7E = lshift(r0C71, body.constant(int(31)));
      ir_expression *const r0C7F = add(r0C7E, body.constant(2139095040u));
      ir_expression *const r0C80 = expr(ir_unop_bitcast_u2f, r0C7F);
      body.emit(assign(r0C7B, expr(ir_triop_csel, r0C7D, r0C74, r0C80), 0x01));

      body.emit(assign(r0C74, r0C7B, 0x01));

      body.emit(assign(r0C6C, r0C7B, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C72->else_instructions;

      ir_variable *const r0C81 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0C82 = lshift(r0C6D, body.constant(int(10)));
      ir_expression *const r0C83 = rshift(swizzle_x(r0C6A), body.constant(int(22)));
      ir_expression *const r0C84 = bit_or(r0C82, r0C83);
      ir_expression *const r0C85 = lshift(swizzle_x(r0C6A), body.constant(int(10)));
      ir_expression *const r0C86 = nequal(r0C85, body.constant(0u));
      ir_expression *const r0C87 = expr(ir_unop_b2i, r0C86);
      ir_expression *const r0C88 = expr(ir_unop_i2u, r0C87);
      body.emit(assign(r0C81, bit_or(r0C84, r0C88), 0x01));

      ir_variable *const r0C89 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0C8A = nequal(r0C6E, body.constant(int(0)));
      ir_expression *const r0C8B = bit_or(r0C81, body.constant(1073741824u));
      body.emit(assign(r0C89, expr(ir_triop_csel, r0C8A, r0C8B, r0C81), 0x01));

      ir_variable *const r0C8C = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0C8C, add(r0C6E, body.constant(int(-897))), 0x01));

      ir_variable *const r0C8D = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0C8D, r0C89, 0x01));

      ir_variable *const r0C8E = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0C8E, body.constant(true), 0x01));

      ir_variable *const r0C8F = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0C90 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0C90);
      ir_expression *const r0C91 = bit_and(r0C89, body.constant(127u));
      body.emit(assign(r0C90, expr(ir_unop_u2i, r0C91), 0x01));

      /* IF CONDITION */
      ir_expression *const r0C93 = expr(ir_unop_i2u, r0C8C);
      ir_expression *const r0C94 = gequal(r0C93, body.constant(253u));
      ir_if *f0C92 = new(mem_ctx) ir_if(operand(r0C94).val);
      exec_list *const f0C92_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C92->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C96 = less(body.constant(int(253)), r0C8C);
         ir_expression *const r0C97 = equal(r0C8C, body.constant(int(253)));
         ir_expression *const r0C98 = expr(ir_unop_u2i, r0C89);
         ir_expression *const r0C99 = less(r0C98, body.constant(int(-64)));
         ir_expression *const r0C9A = logic_and(r0C97, r0C99);
         ir_expression *const r0C9B = logic_or(r0C96, r0C9A);
         ir_if *f0C95 = new(mem_ctx) ir_if(operand(r0C9B).val);
         exec_list *const f0C95_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C95->then_instructions;

            ir_expression *const r0C9C = lshift(r0C71, body.constant(int(31)));
            ir_expression *const r0C9D = add(r0C9C, body.constant(2139095040u));
            body.emit(assign(r0C8F, expr(ir_unop_bitcast_u2f, r0C9D), 0x01));

            body.emit(assign(r0C8E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C95->else_instructions;

            ir_variable *const r0C9E = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0C9E, neg(r0C8C), 0x01));

            ir_variable *const r0C9F = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0C9F, less(r0C8C, body.constant(int(0))), 0x01));

            ir_variable *const r0CA0 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0CA1 = neg(r0C8C);
            ir_expression *const r0CA2 = less(r0CA1, body.constant(int(32)));
            ir_expression *const r0CA3 = rshift(r0C89, r0C9E);
            ir_expression *const r0CA4 = neg(r0C9E);
            ir_expression *const r0CA5 = bit_and(r0CA4, body.constant(int(31)));
            ir_expression *const r0CA6 = lshift(r0C89, r0CA5);
            ir_expression *const r0CA7 = nequal(r0CA6, body.constant(0u));
            ir_expression *const r0CA8 = expr(ir_unop_b2i, r0CA7);
            ir_expression *const r0CA9 = expr(ir_unop_i2u, r0CA8);
            ir_expression *const r0CAA = bit_or(r0CA3, r0CA9);
            ir_expression *const r0CAB = nequal(r0C89, body.constant(0u));
            ir_expression *const r0CAC = expr(ir_unop_b2i, r0CAB);
            ir_expression *const r0CAD = expr(ir_unop_i2u, r0CAC);
            ir_expression *const r0CAE = expr(ir_triop_csel, r0CA2, r0CAA, r0CAD);
            body.emit(assign(r0CA0, expr(ir_triop_csel, r0C9F, r0CAE, r0C89), 0x01));

            body.emit(assign(r0C8D, r0CA0, 0x01));

            ir_expression *const r0CAF = expr(ir_unop_u2i, r0CA0);
            ir_expression *const r0CB0 = bit_and(r0CAF, body.constant(int(127)));
            body.emit(assign(r0C90, expr(ir_triop_csel, r0C9F, r0CB0, r0C90), 0x01));

            body.emit(assign(r0C8C, expr(ir_triop_csel, r0C9F, body.constant(int(0)), r0C8C), 0x01));


         body.instructions = f0C95_parent_instructions;
         body.emit(f0C95);

         /* END IF */


      body.instructions = f0C92_parent_instructions;
      body.emit(f0C92);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0CB1 = new(mem_ctx) ir_if(operand(r0C8E).val);
      exec_list *const f0CB1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CB1->then_instructions;

         ir_expression *const r0CB2 = add(r0C8D, body.constant(64u));
         body.emit(assign(r0C8D, rshift(r0CB2, body.constant(int(7))), 0x01));

         ir_expression *const r0CB3 = bit_xor(r0C90, body.constant(int(64)));
         ir_expression *const r0CB4 = equal(r0CB3, body.constant(int(0)));
         ir_expression *const r0CB5 = expr(ir_unop_b2i, r0CB4);
         ir_expression *const r0CB6 = expr(ir_unop_i2u, r0CB5);
         ir_expression *const r0CB7 = expr(ir_unop_bit_not, r0CB6);
         body.emit(assign(r0C8D, bit_and(r0C8D, r0CB7), 0x01));

         ir_expression *const r0CB8 = lshift(r0C71, body.constant(int(31)));
         ir_expression *const r0CB9 = equal(r0C8D, body.constant(0u));
         ir_expression *const r0CBA = expr(ir_triop_csel, r0CB9, body.constant(int(0)), r0C8C);
         ir_expression *const r0CBB = expr(ir_unop_i2u, r0CBA);
         ir_expression *const r0CBC = lshift(r0CBB, body.constant(int(23)));
         ir_expression *const r0CBD = add(r0CB8, r0CBC);
         ir_expression *const r0CBE = add(r0CBD, r0C8D);
         body.emit(assign(r0C8F, expr(ir_unop_bitcast_u2f, r0CBE), 0x01));

         body.emit(assign(r0C8E, body.constant(false), 0x01));


      body.instructions = f0CB1_parent_instructions;
      body.emit(f0CB1);

      /* END IF */

      body.emit(assign(r0C6C, r0C8F, 0x01));


   body.instructions = f0C72_parent_instructions;
   body.emit(f0C72);

   /* END IF */

   ir_variable *const r0CBF = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0CBF, body.constant(true), 0x01));

   ir_variable *const r0CC0 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CC1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0CC1);
   ir_variable *const r0CC2 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0CC2);
   ir_variable *const r0CC3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0CC3);
   ir_variable *const r0CC4 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0CC5 = expr(ir_unop_sqrt, r0C6C);
   body.emit(assign(r0CC4, expr(ir_unop_bitcast_f2u, r0CC5), 0x01));

   ir_variable *const r0CC6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0CC6, bit_and(r0CC4, body.constant(8388607u)), 0x01));

   body.emit(assign(r0CC3, r0CC6, 0x01));

   ir_variable *const r0CC7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0CC8 = rshift(r0CC4, body.constant(int(23)));
   ir_expression *const r0CC9 = bit_and(r0CC8, body.constant(255u));
   body.emit(assign(r0CC7, expr(ir_unop_u2i, r0CC9), 0x01));

   body.emit(assign(r0CC2, r0CC7, 0x01));

   body.emit(assign(r0CC1, rshift(r0CC4, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CCB = equal(r0CC7, body.constant(int(255)));
   ir_if *f0CCA = new(mem_ctx) ir_if(operand(r0CCB).val);
   exec_list *const f0CCA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CCA->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CCD = nequal(r0CC6, body.constant(0u));
      ir_if *f0CCC = new(mem_ctx) ir_if(operand(r0CCD).val);
      exec_list *const f0CCC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CCC->then_instructions;

         ir_variable *const r0CCE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0CCE, lshift(r0CC4, body.constant(int(9))), 0x01));

         ir_variable *const r0CCF = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0CD0 = lshift(r0CCE, body.constant(int(20)));
         body.emit(assign(r0CCF, bit_or(r0CD0, body.constant(0u)), 0x01));

         ir_expression *const r0CD1 = rshift(r0CCE, body.constant(int(12)));
         ir_expression *const r0CD2 = lshift(r0CC1, body.constant(int(31)));
         ir_expression *const r0CD3 = bit_or(r0CD2, body.constant(2146959360u));
         body.emit(assign(r0CCF, bit_or(r0CD1, r0CD3), 0x02));

         body.emit(assign(r0CC0, r0CCF, 0x03));

         body.emit(assign(r0CBF, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CCC->else_instructions;

         ir_variable *const r0CD4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0CD4);
         ir_expression *const r0CD5 = lshift(r0CC1, body.constant(int(31)));
         body.emit(assign(r0CD4, add(r0CD5, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0CD4, body.constant(0u), 0x01));

         body.emit(assign(r0CC0, r0CD4, 0x03));

         body.emit(assign(r0CBF, body.constant(false), 0x01));


      body.instructions = f0CCC_parent_instructions;
      body.emit(f0CCC);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CCA->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CD7 = equal(r0CC7, body.constant(int(0)));
      ir_if *f0CD6 = new(mem_ctx) ir_if(operand(r0CD7).val);
      exec_list *const f0CD6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CD6->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0CD9 = equal(r0CC6, body.constant(0u));
         ir_if *f0CD8 = new(mem_ctx) ir_if(operand(r0CD9).val);
         exec_list *const f0CD8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CD8->then_instructions;

            ir_variable *const r0CDA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0CDA);
            body.emit(assign(r0CDA, lshift(r0CC1, body.constant(int(31))), 0x02));

            body.emit(assign(r0CDA, body.constant(0u), 0x01));

            body.emit(assign(r0CC0, r0CDA, 0x03));

            body.emit(assign(r0CBF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CD8->else_instructions;

            ir_variable *const r0CDB = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0CDC = equal(r0CC6, body.constant(0u));
            ir_expression *const r0CDD = expr(ir_unop_find_msb, r0CC6);
            ir_expression *const r0CDE = sub(body.constant(int(31)), r0CDD);
            ir_expression *const r0CDF = expr(ir_triop_csel, r0CDC, body.constant(int(32)), r0CDE);
            body.emit(assign(r0CDB, add(r0CDF, body.constant(int(-8))), 0x01));

            body.emit(assign(r0CC3, lshift(r0CC6, r0CDB), 0x01));

            body.emit(assign(r0CC2, sub(body.constant(int(1)), r0CDB), 0x01));

            body.emit(assign(r0CC2, add(r0CC2, body.constant(int(-1))), 0x01));


         body.instructions = f0CD8_parent_instructions;
         body.emit(f0CD8);

         /* END IF */


      body.instructions = f0CD6_parent_instructions;
      body.emit(f0CD6);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0CE0 = new(mem_ctx) ir_if(operand(r0CBF).val);
      exec_list *const f0CE0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CE0->then_instructions;

         ir_variable *const r0CE1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0CE1);
         ir_expression *const r0CE2 = lshift(r0CC1, body.constant(int(31)));
         ir_expression *const r0CE3 = add(r0CC2, body.constant(int(896)));
         ir_expression *const r0CE4 = expr(ir_unop_i2u, r0CE3);
         ir_expression *const r0CE5 = lshift(r0CE4, body.constant(int(20)));
         ir_expression *const r0CE6 = add(r0CE2, r0CE5);
         ir_expression *const r0CE7 = rshift(r0CC3, body.constant(int(3)));
         body.emit(assign(r0CE1, add(r0CE6, r0CE7), 0x02));

         ir_expression *const r0CE8 = lshift(r0CC3, body.constant(int(29)));
         body.emit(assign(r0CE1, bit_or(r0CE8, body.constant(0u)), 0x01));

         body.emit(assign(r0CC0, r0CE1, 0x03));

         body.emit(assign(r0CBF, body.constant(false), 0x01));


      body.instructions = f0CE0_parent_instructions;
      body.emit(f0CE0);

      /* END IF */


   body.instructions = f0CCA_parent_instructions;
   body.emit(f0CCA);

   /* END IF */

   body.emit(ret(r0CC0));

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

   ir_variable *const r0CE9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CE9);
   ir_variable *const r0CEA = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CEB = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0CEC = rshift(swizzle_y(r0CE9), body.constant(int(20)));
   ir_expression *const r0CED = bit_and(r0CEC, body.constant(2047u));
   ir_expression *const r0CEE = expr(ir_unop_u2i, r0CED);
   body.emit(assign(r0CEB, add(r0CEE, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CF0 = less(r0CEB, body.constant(int(0)));
   ir_if *f0CEF = new(mem_ctx) ir_if(operand(r0CF0).val);
   exec_list *const f0CEF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CEF->then_instructions;

      body.emit(assign(r0CEA, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CEF->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CF2 = less(body.constant(int(52)), r0CEB);
      ir_if *f0CF1 = new(mem_ctx) ir_if(operand(r0CF2).val);
      exec_list *const f0CF1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CF1->then_instructions;

         body.emit(assign(r0CEA, r0CE9, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CF1->else_instructions;

         ir_variable *const r0CF3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0CF3, sub(body.constant(int(52)), r0CEB), 0x01));

         ir_variable *const r0CF4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0CF6 = gequal(r0CF3, body.constant(int(32)));
         ir_if *f0CF5 = new(mem_ctx) ir_if(operand(r0CF6).val);
         exec_list *const f0CF5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CF5->then_instructions;

            body.emit(assign(r0CF4, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CF5->else_instructions;

            body.emit(assign(r0CF4, lshift(body.constant(4294967295u), r0CF3), 0x01));


         body.instructions = f0CF5_parent_instructions;
         body.emit(f0CF5);

         /* END IF */

         ir_variable *const r0CF7 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0CF9 = less(r0CF3, body.constant(int(33)));
         ir_if *f0CF8 = new(mem_ctx) ir_if(operand(r0CF9).val);
         exec_list *const f0CF8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CF8->then_instructions;

            body.emit(assign(r0CF7, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CF8->else_instructions;

            ir_expression *const r0CFA = add(r0CF3, body.constant(int(-32)));
            body.emit(assign(r0CF7, lshift(body.constant(4294967295u), r0CFA), 0x01));


         body.instructions = f0CF8_parent_instructions;
         body.emit(f0CF8);

         /* END IF */

         ir_variable *const r0CFB = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0CFB, bit_and(r0CF4, swizzle_x(r0CE9)), 0x01));

         body.emit(assign(r0CFB, bit_and(r0CF7, swizzle_y(r0CE9)), 0x02));

         body.emit(assign(r0CEA, r0CFB, 0x03));


      body.instructions = f0CF1_parent_instructions;
      body.emit(f0CF1);

      /* END IF */


   body.instructions = f0CEF_parent_instructions;
   body.emit(f0CEF);

   /* END IF */

   body.emit(ret(r0CEA));

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

   ir_variable *const r0CFC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CFC);
   ir_variable *const r0CFD = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0CFD, body.constant(true), 0x01));

   ir_variable *const r0CFE = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CFF = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0CFF);
   ir_variable *const r0D00 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0D00);
   ir_variable *const r0D01 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0D02 = rshift(swizzle_y(r0CFC), body.constant(int(20)));
   ir_expression *const r0D03 = bit_and(r0D02, body.constant(2047u));
   ir_expression *const r0D04 = expr(ir_unop_u2i, r0D03);
   body.emit(assign(r0D01, add(r0D04, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0D00, swizzle_y(r0CFC), 0x01));

   body.emit(assign(r0CFF, swizzle_x(r0CFC), 0x01));

   /* IF CONDITION */
   ir_expression *const r0D06 = less(r0D01, body.constant(int(20)));
   ir_if *f0D05 = new(mem_ctx) ir_if(operand(r0D06).val);
   exec_list *const f0D05_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D05->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0D08 = less(r0D01, body.constant(int(0)));
      ir_if *f0D07 = new(mem_ctx) ir_if(operand(r0D08).val);
      exec_list *const f0D07_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D07->then_instructions;

         body.emit(assign(r0D00, bit_and(swizzle_y(r0CFC), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0D0A = equal(r0D01, body.constant(int(-1)));
         ir_expression *const r0D0B = nequal(swizzle_x(r0CFC), body.constant(0u));
         ir_expression *const r0D0C = logic_and(r0D0A, r0D0B);
         ir_if *f0D09 = new(mem_ctx) ir_if(operand(r0D0C).val);
         exec_list *const f0D09_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D09->then_instructions;

            body.emit(assign(r0D00, bit_or(r0D00, body.constant(1072693248u)), 0x01));


         body.instructions = f0D09_parent_instructions;
         body.emit(f0D09);

         /* END IF */

         body.emit(assign(r0CFF, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D07->else_instructions;

         ir_variable *const r0D0D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0D0D, rshift(body.constant(1048575u), r0D01), 0x01));

         /* IF CONDITION */
         ir_expression *const r0D0F = bit_and(r0D00, r0D0D);
         ir_expression *const r0D10 = equal(r0D0F, body.constant(0u));
         ir_expression *const r0D11 = equal(r0CFF, body.constant(0u));
         ir_expression *const r0D12 = logic_and(r0D10, r0D11);
         ir_if *f0D0E = new(mem_ctx) ir_if(operand(r0D12).val);
         exec_list *const f0D0E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D0E->then_instructions;

            body.emit(assign(r0CFE, r0CFC, 0x03));

            body.emit(assign(r0CFD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D0E->else_instructions;

            ir_expression *const r0D13 = rshift(body.constant(524288u), r0D01);
            body.emit(assign(r0D00, add(r0D00, r0D13), 0x01));

            ir_expression *const r0D14 = expr(ir_unop_bit_not, r0D0D);
            body.emit(assign(r0D00, bit_and(r0D00, r0D14), 0x01));

            body.emit(assign(r0CFF, body.constant(0u), 0x01));


         body.instructions = f0D0E_parent_instructions;
         body.emit(f0D0E);

         /* END IF */


      body.instructions = f0D07_parent_instructions;
      body.emit(f0D07);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0D05->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0D16 = less(body.constant(int(51)), r0D01);
      ir_expression *const r0D17 = equal(r0D01, body.constant(int(1024)));
      ir_expression *const r0D18 = logic_or(r0D16, r0D17);
      ir_if *f0D15 = new(mem_ctx) ir_if(operand(r0D18).val);
      exec_list *const f0D15_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D15->then_instructions;

         body.emit(assign(r0CFE, r0CFC, 0x03));

         body.emit(assign(r0CFD, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D15->else_instructions;

         ir_variable *const r0D19 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0D1A = add(r0D01, body.constant(int(-20)));
         body.emit(assign(r0D19, rshift(body.constant(4294967295u), r0D1A), 0x01));

         /* IF CONDITION */
         ir_expression *const r0D1C = bit_and(r0CFF, r0D19);
         ir_expression *const r0D1D = equal(r0D1C, body.constant(0u));
         ir_if *f0D1B = new(mem_ctx) ir_if(operand(r0D1D).val);
         exec_list *const f0D1B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D1B->then_instructions;

            body.emit(assign(r0CFE, r0CFC, 0x03));

            body.emit(assign(r0CFD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D1B->else_instructions;

            ir_variable *const r0D1E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0D1F = sub(body.constant(int(51)), r0D01);
            ir_expression *const r0D20 = lshift(body.constant(1u), r0D1F);
            body.emit(assign(r0D1E, add(r0CFF, r0D20), 0x01));

            /* IF CONDITION */
            ir_expression *const r0D22 = less(r0D1E, r0CFF);
            ir_if *f0D21 = new(mem_ctx) ir_if(operand(r0D22).val);
            exec_list *const f0D21_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D21->then_instructions;

               body.emit(assign(r0D00, add(r0D00, body.constant(1u)), 0x01));


            body.instructions = f0D21_parent_instructions;
            body.emit(f0D21);

            /* END IF */

            ir_expression *const r0D23 = expr(ir_unop_bit_not, r0D19);
            body.emit(assign(r0CFF, bit_and(r0D1E, r0D23), 0x01));


         body.instructions = f0D1B_parent_instructions;
         body.emit(f0D1B);

         /* END IF */


      body.instructions = f0D15_parent_instructions;
      body.emit(f0D15);

      /* END IF */


   body.instructions = f0D05_parent_instructions;
   body.emit(f0D05);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0D24 = new(mem_ctx) ir_if(operand(r0CFD).val);
   exec_list *const f0D24_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D24->then_instructions;

      body.emit(assign(r0CFC, r0CFF, 0x01));

      body.emit(assign(r0CFC, r0D00, 0x02));

      body.emit(assign(r0CFE, r0CFC, 0x03));

      body.emit(assign(r0CFD, body.constant(false), 0x01));


   body.instructions = f0D24_parent_instructions;
   body.emit(f0D24);

   /* END IF */

   body.emit(ret(r0CFE));

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

   ir_variable *const r0D25 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0D25);
   ir_variable *const r0D26 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0D26, r0D25, 0x03));

   ir_variable *const r0D27 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0D28 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0D28, bit_and(swizzle_y(r0D25), body.constant(1048575u)), 0x01));

   ir_variable *const r0D29 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0D2A = rshift(swizzle_y(r0D25), body.constant(int(20)));
   ir_expression *const r0D2B = bit_and(r0D2A, body.constant(2047u));
   body.emit(assign(r0D29, expr(ir_unop_u2i, r0D2B), 0x01));

   ir_variable *const r0D2C = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0D2C, rshift(swizzle_y(r0D25), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0D2E = equal(r0D29, body.constant(int(2047)));
   ir_if *f0D2D = new(mem_ctx) ir_if(operand(r0D2E).val);
   exec_list *const f0D2D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D2D->then_instructions;

      ir_variable *const r0D2F = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0D2F);
      ir_expression *const r0D30 = lshift(swizzle_y(r0D25), body.constant(int(12)));
      ir_expression *const r0D31 = rshift(swizzle_x(r0D25), body.constant(int(20)));
      body.emit(assign(r0D26, bit_or(r0D30, r0D31), 0x02));

      body.emit(assign(r0D26, lshift(swizzle_x(r0D25), body.constant(int(12))), 0x01));

      ir_expression *const r0D32 = lshift(r0D2C, body.constant(int(31)));
      ir_expression *const r0D33 = bit_or(r0D32, body.constant(2143289344u));
      ir_expression *const r0D34 = rshift(swizzle_y(r0D26), body.constant(int(9)));
      ir_expression *const r0D35 = bit_or(r0D33, r0D34);
      body.emit(assign(r0D2F, expr(ir_unop_bitcast_u2f, r0D35), 0x01));

      ir_variable *const r0D36 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0D37 = bit_or(r0D28, swizzle_x(r0D25));
      ir_expression *const r0D38 = nequal(r0D37, body.constant(0u));
      ir_expression *const r0D39 = lshift(r0D2C, body.constant(int(31)));
      ir_expression *const r0D3A = add(r0D39, body.constant(2139095040u));
      ir_expression *const r0D3B = expr(ir_unop_bitcast_u2f, r0D3A);
      body.emit(assign(r0D36, expr(ir_triop_csel, r0D38, r0D2F, r0D3B), 0x01));

      body.emit(assign(r0D2F, r0D36, 0x01));

      body.emit(assign(r0D27, r0D36, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0D2D->else_instructions;

      ir_variable *const r0D3C = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0D3D = lshift(r0D28, body.constant(int(10)));
      ir_expression *const r0D3E = rshift(swizzle_x(r0D25), body.constant(int(22)));
      ir_expression *const r0D3F = bit_or(r0D3D, r0D3E);
      ir_expression *const r0D40 = lshift(swizzle_x(r0D25), body.constant(int(10)));
      ir_expression *const r0D41 = nequal(r0D40, body.constant(0u));
      ir_expression *const r0D42 = expr(ir_unop_b2i, r0D41);
      ir_expression *const r0D43 = expr(ir_unop_i2u, r0D42);
      body.emit(assign(r0D3C, bit_or(r0D3F, r0D43), 0x01));

      ir_variable *const r0D44 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0D45 = nequal(r0D29, body.constant(int(0)));
      ir_expression *const r0D46 = bit_or(r0D3C, body.constant(1073741824u));
      body.emit(assign(r0D44, expr(ir_triop_csel, r0D45, r0D46, r0D3C), 0x01));

      ir_variable *const r0D47 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0D47, add(r0D29, body.constant(int(-897))), 0x01));

      ir_variable *const r0D48 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0D48, r0D44, 0x01));

      ir_variable *const r0D49 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0D49, body.constant(true), 0x01));

      ir_variable *const r0D4A = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0D4B = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0D4B);
      ir_expression *const r0D4C = bit_and(r0D44, body.constant(127u));
      body.emit(assign(r0D4B, expr(ir_unop_u2i, r0D4C), 0x01));

      /* IF CONDITION */
      ir_expression *const r0D4E = expr(ir_unop_i2u, r0D47);
      ir_expression *const r0D4F = gequal(r0D4E, body.constant(253u));
      ir_if *f0D4D = new(mem_ctx) ir_if(operand(r0D4F).val);
      exec_list *const f0D4D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D4D->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0D51 = less(body.constant(int(253)), r0D47);
         ir_expression *const r0D52 = equal(r0D47, body.constant(int(253)));
         ir_expression *const r0D53 = expr(ir_unop_u2i, r0D44);
         ir_expression *const r0D54 = less(r0D53, body.constant(int(-64)));
         ir_expression *const r0D55 = logic_and(r0D52, r0D54);
         ir_expression *const r0D56 = logic_or(r0D51, r0D55);
         ir_if *f0D50 = new(mem_ctx) ir_if(operand(r0D56).val);
         exec_list *const f0D50_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D50->then_instructions;

            ir_expression *const r0D57 = lshift(r0D2C, body.constant(int(31)));
            ir_expression *const r0D58 = add(r0D57, body.constant(2139095040u));
            body.emit(assign(r0D4A, expr(ir_unop_bitcast_u2f, r0D58), 0x01));

            body.emit(assign(r0D49, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D50->else_instructions;

            ir_variable *const r0D59 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0D59, neg(r0D47), 0x01));

            ir_variable *const r0D5A = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0D5A, less(r0D47, body.constant(int(0))), 0x01));

            ir_variable *const r0D5B = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0D5C = neg(r0D47);
            ir_expression *const r0D5D = less(r0D5C, body.constant(int(32)));
            ir_expression *const r0D5E = rshift(r0D44, r0D59);
            ir_expression *const r0D5F = neg(r0D59);
            ir_expression *const r0D60 = bit_and(r0D5F, body.constant(int(31)));
            ir_expression *const r0D61 = lshift(r0D44, r0D60);
            ir_expression *const r0D62 = nequal(r0D61, body.constant(0u));
            ir_expression *const r0D63 = expr(ir_unop_b2i, r0D62);
            ir_expression *const r0D64 = expr(ir_unop_i2u, r0D63);
            ir_expression *const r0D65 = bit_or(r0D5E, r0D64);
            ir_expression *const r0D66 = nequal(r0D44, body.constant(0u));
            ir_expression *const r0D67 = expr(ir_unop_b2i, r0D66);
            ir_expression *const r0D68 = expr(ir_unop_i2u, r0D67);
            ir_expression *const r0D69 = expr(ir_triop_csel, r0D5D, r0D65, r0D68);
            body.emit(assign(r0D5B, expr(ir_triop_csel, r0D5A, r0D69, r0D44), 0x01));

            body.emit(assign(r0D48, r0D5B, 0x01));

            ir_expression *const r0D6A = expr(ir_unop_u2i, r0D5B);
            ir_expression *const r0D6B = bit_and(r0D6A, body.constant(int(127)));
            body.emit(assign(r0D4B, expr(ir_triop_csel, r0D5A, r0D6B, r0D4B), 0x01));

            body.emit(assign(r0D47, expr(ir_triop_csel, r0D5A, body.constant(int(0)), r0D47), 0x01));


         body.instructions = f0D50_parent_instructions;
         body.emit(f0D50);

         /* END IF */


      body.instructions = f0D4D_parent_instructions;
      body.emit(f0D4D);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0D6C = new(mem_ctx) ir_if(operand(r0D49).val);
      exec_list *const f0D6C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D6C->then_instructions;

         ir_expression *const r0D6D = add(r0D48, body.constant(64u));
         body.emit(assign(r0D48, rshift(r0D6D, body.constant(int(7))), 0x01));

         ir_expression *const r0D6E = bit_xor(r0D4B, body.constant(int(64)));
         ir_expression *const r0D6F = equal(r0D6E, body.constant(int(0)));
         ir_expression *const r0D70 = expr(ir_unop_b2i, r0D6F);
         ir_expression *const r0D71 = expr(ir_unop_i2u, r0D70);
         ir_expression *const r0D72 = expr(ir_unop_bit_not, r0D71);
         body.emit(assign(r0D48, bit_and(r0D48, r0D72), 0x01));

         ir_expression *const r0D73 = lshift(r0D2C, body.constant(int(31)));
         ir_expression *const r0D74 = equal(r0D48, body.constant(0u));
         ir_expression *const r0D75 = expr(ir_triop_csel, r0D74, body.constant(int(0)), r0D47);
         ir_expression *const r0D76 = expr(ir_unop_i2u, r0D75);
         ir_expression *const r0D77 = lshift(r0D76, body.constant(int(23)));
         ir_expression *const r0D78 = add(r0D73, r0D77);
         ir_expression *const r0D79 = add(r0D78, r0D48);
         body.emit(assign(r0D4A, expr(ir_unop_bitcast_u2f, r0D79), 0x01));

         body.emit(assign(r0D49, body.constant(false), 0x01));


      body.instructions = f0D6C_parent_instructions;
      body.emit(f0D6C);

      /* END IF */

      body.emit(assign(r0D27, r0D4A, 0x01));


   body.instructions = f0D2D_parent_instructions;
   body.emit(f0D2D);

   /* END IF */

   ir_variable *const r0D7A = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0D7A, body.constant(true), 0x01));

   ir_variable *const r0D7B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0D7C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0D7C);
   ir_variable *const r0D7D = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0D7D);
   ir_variable *const r0D7E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0D7E);
   ir_variable *const r0D7F = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0D80 = expr(ir_unop_rcp, r0D27);
   body.emit(assign(r0D7F, expr(ir_unop_bitcast_f2u, r0D80), 0x01));

   ir_variable *const r0D81 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0D81, bit_and(r0D7F, body.constant(8388607u)), 0x01));

   body.emit(assign(r0D7E, r0D81, 0x01));

   ir_variable *const r0D82 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0D83 = rshift(r0D7F, body.constant(int(23)));
   ir_expression *const r0D84 = bit_and(r0D83, body.constant(255u));
   body.emit(assign(r0D82, expr(ir_unop_u2i, r0D84), 0x01));

   body.emit(assign(r0D7D, r0D82, 0x01));

   body.emit(assign(r0D7C, rshift(r0D7F, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0D86 = equal(r0D82, body.constant(int(255)));
   ir_if *f0D85 = new(mem_ctx) ir_if(operand(r0D86).val);
   exec_list *const f0D85_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D85->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0D88 = nequal(r0D81, body.constant(0u));
      ir_if *f0D87 = new(mem_ctx) ir_if(operand(r0D88).val);
      exec_list *const f0D87_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D87->then_instructions;

         ir_variable *const r0D89 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0D89, lshift(r0D7F, body.constant(int(9))), 0x01));

         ir_variable *const r0D8A = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0D8B = lshift(r0D89, body.constant(int(20)));
         body.emit(assign(r0D8A, bit_or(r0D8B, body.constant(0u)), 0x01));

         ir_expression *const r0D8C = rshift(r0D89, body.constant(int(12)));
         ir_expression *const r0D8D = lshift(r0D7C, body.constant(int(31)));
         ir_expression *const r0D8E = bit_or(r0D8D, body.constant(2146959360u));
         body.emit(assign(r0D8A, bit_or(r0D8C, r0D8E), 0x02));

         body.emit(assign(r0D7B, r0D8A, 0x03));

         body.emit(assign(r0D7A, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D87->else_instructions;

         ir_variable *const r0D8F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D8F);
         ir_expression *const r0D90 = lshift(r0D7C, body.constant(int(31)));
         body.emit(assign(r0D8F, add(r0D90, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0D8F, body.constant(0u), 0x01));

         body.emit(assign(r0D7B, r0D8F, 0x03));

         body.emit(assign(r0D7A, body.constant(false), 0x01));


      body.instructions = f0D87_parent_instructions;
      body.emit(f0D87);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0D85->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0D92 = equal(r0D82, body.constant(int(0)));
      ir_if *f0D91 = new(mem_ctx) ir_if(operand(r0D92).val);
      exec_list *const f0D91_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D91->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0D94 = equal(r0D81, body.constant(0u));
         ir_if *f0D93 = new(mem_ctx) ir_if(operand(r0D94).val);
         exec_list *const f0D93_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D93->then_instructions;

            ir_variable *const r0D95 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0D95);
            body.emit(assign(r0D95, lshift(r0D7C, body.constant(int(31))), 0x02));

            body.emit(assign(r0D95, body.constant(0u), 0x01));

            body.emit(assign(r0D7B, r0D95, 0x03));

            body.emit(assign(r0D7A, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D93->else_instructions;

            ir_variable *const r0D96 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0D97 = equal(r0D81, body.constant(0u));
            ir_expression *const r0D98 = expr(ir_unop_find_msb, r0D81);
            ir_expression *const r0D99 = sub(body.constant(int(31)), r0D98);
            ir_expression *const r0D9A = expr(ir_triop_csel, r0D97, body.constant(int(32)), r0D99);
            body.emit(assign(r0D96, add(r0D9A, body.constant(int(-8))), 0x01));

            body.emit(assign(r0D7E, lshift(r0D81, r0D96), 0x01));

            body.emit(assign(r0D7D, sub(body.constant(int(1)), r0D96), 0x01));

            body.emit(assign(r0D7D, add(r0D7D, body.constant(int(-1))), 0x01));


         body.instructions = f0D93_parent_instructions;
         body.emit(f0D93);

         /* END IF */


      body.instructions = f0D91_parent_instructions;
      body.emit(f0D91);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0D9B = new(mem_ctx) ir_if(operand(r0D7A).val);
      exec_list *const f0D9B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D9B->then_instructions;

         ir_variable *const r0D9C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D9C);
         ir_expression *const r0D9D = lshift(r0D7C, body.constant(int(31)));
         ir_expression *const r0D9E = add(r0D7D, body.constant(int(896)));
         ir_expression *const r0D9F = expr(ir_unop_i2u, r0D9E);
         ir_expression *const r0DA0 = lshift(r0D9F, body.constant(int(20)));
         ir_expression *const r0DA1 = add(r0D9D, r0DA0);
         ir_expression *const r0DA2 = rshift(r0D7E, body.constant(int(3)));
         body.emit(assign(r0D9C, add(r0DA1, r0DA2), 0x02));

         ir_expression *const r0DA3 = lshift(r0D7E, body.constant(int(29)));
         body.emit(assign(r0D9C, bit_or(r0DA3, body.constant(0u)), 0x01));

         body.emit(assign(r0D7B, r0D9C, 0x03));

         body.emit(assign(r0D7A, body.constant(false), 0x01));


      body.instructions = f0D9B_parent_instructions;
      body.emit(f0D9B);

      /* END IF */


   body.instructions = f0D85_parent_instructions;
   body.emit(f0D85);

   /* END IF */

   body.emit(ret(r0D7B));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
