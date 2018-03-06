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

      /* IF CONDITION */
      ir_expression *const r022A = less(body.constant(int(0)), r0224);
      ir_if *f0229 = new(mem_ctx) ir_if(operand(r022A).val);
      exec_list *const f0229_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0229->then_instructions;

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
            ir_expression *const r0230 = nequal(r022F, body.constant(0u));
            ir_swizzle *const r0231 = swizzle(r0230, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0232 = lshift(swizzle_y(r020C), body.constant(int(1)));
            ir_expression *const r0233 = gequal(r0232, body.constant(4292870144u));
            ir_expression *const r0234 = nequal(swizzle_x(r020C), body.constant(0u));
            ir_expression *const r0235 = bit_and(swizzle_y(r020C), body.constant(1048575u));
            ir_expression *const r0236 = nequal(r0235, body.constant(0u));
            ir_expression *const r0237 = logic_or(r0234, r0236);
            ir_expression *const r0238 = logic_and(r0233, r0237);
            ir_swizzle *const r0239 = swizzle(r0238, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r023A = lshift(swizzle_y(r020D), body.constant(int(1)));
            ir_expression *const r023B = gequal(r023A, body.constant(4292870144u));
            ir_expression *const r023C = nequal(swizzle_x(r020D), body.constant(0u));
            ir_expression *const r023D = bit_and(swizzle_y(r020D), body.constant(1048575u));
            ir_expression *const r023E = nequal(r023D, body.constant(0u));
            ir_expression *const r023F = logic_or(r023C, r023E);
            ir_expression *const r0240 = logic_and(r023B, r023F);
            ir_swizzle *const r0241 = swizzle(r0240, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0242 = expr(ir_triop_csel, r0241, r022E, r022D);
            ir_expression *const r0243 = expr(ir_triop_csel, r0239, r0242, r022E);
            body.emit(assign(r020F, expr(ir_triop_csel, r0231, r0243, r020C), 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f022B->else_instructions;

            ir_variable *const r0244 = body.make_temp(glsl_type::int_type, "mix_retval");
            ir_expression *const r0245 = equal(r0221, body.constant(int(0)));
            ir_expression *const r0246 = add(r0224, body.constant(int(-1)));
            body.emit(assign(r0244, expr(ir_triop_csel, r0245, r0246, r0224), 0x01));

            body.emit(assign(r0210, r0244, 0x01));

            ir_variable *const r0247 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0248 = equal(r0221, body.constant(int(0)));
            ir_expression *const r0249 = bit_or(r021D, body.constant(1048576u));
            body.emit(assign(r0247, expr(ir_triop_csel, r0248, r021D, r0249), 0x01));

            ir_variable *const r024A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r024A);
            ir_variable *const r024B = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r024C = neg(r0244);
            body.emit(assign(r024B, bit_and(r024C, body.constant(int(31))), 0x01));

            ir_variable *const r024D = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r024E = less(r0244, body.constant(int(32)));
            ir_expression *const r024F = bit_or(body.constant(0u), swizzle_x(r020D));
            body.emit(assign(r024D, expr(ir_triop_csel, r024E, body.constant(0u), r024F), 0x01));

            ir_expression *const r0250 = less(r0244, body.constant(int(32)));
            ir_expression *const r0251 = lshift(swizzle_x(r020D), r024B);
            ir_expression *const r0252 = less(r0244, body.constant(int(64)));
            ir_expression *const r0253 = lshift(r0247, r024B);
            ir_expression *const r0254 = equal(r0244, body.constant(int(64)));
            ir_expression *const r0255 = nequal(r0247, body.constant(0u));
            ir_expression *const r0256 = expr(ir_unop_b2i, r0255);
            ir_expression *const r0257 = expr(ir_unop_i2u, r0256);
            ir_expression *const r0258 = expr(ir_triop_csel, r0254, r0247, r0257);
            ir_expression *const r0259 = expr(ir_triop_csel, r0252, r0253, r0258);
            ir_expression *const r025A = expr(ir_triop_csel, r0250, r0251, r0259);
            ir_expression *const r025B = nequal(r024D, body.constant(0u));
            ir_expression *const r025C = expr(ir_unop_b2i, r025B);
            ir_expression *const r025D = expr(ir_unop_i2u, r025C);
            body.emit(assign(r024A, bit_or(r025A, r025D), 0x01));

            ir_variable *const r025E = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r025F = equal(r0244, body.constant(int(0)));
            ir_expression *const r0260 = equal(r0244, body.constant(int(32)));
            ir_expression *const r0261 = expr(ir_triop_csel, r0260, swizzle_x(r020D), r024A);
            body.emit(assign(r025E, expr(ir_triop_csel, r025F, r024D, r0261), 0x01));

            body.emit(assign(r024A, r025E, 0x01));

            ir_expression *const r0262 = equal(r0244, body.constant(int(0)));
            ir_expression *const r0263 = equal(r0244, body.constant(int(32)));
            ir_expression *const r0264 = less(r0244, body.constant(int(32)));
            ir_expression *const r0265 = rshift(r0247, r0244);
            ir_expression *const r0266 = expr(ir_triop_csel, r0264, r0265, body.constant(0u));
            ir_expression *const r0267 = expr(ir_triop_csel, r0263, body.constant(0u), r0266);
            body.emit(assign(r0215, expr(ir_triop_csel, r0262, r0247, r0267), 0x01));

            ir_expression *const r0268 = equal(r0244, body.constant(int(0)));
            ir_expression *const r0269 = equal(r0244, body.constant(int(32)));
            ir_expression *const r026A = less(r0244, body.constant(int(32)));
            ir_expression *const r026B = lshift(r0247, r024B);
            ir_expression *const r026C = rshift(swizzle_x(r020D), r0244);
            ir_expression *const r026D = bit_or(r026B, r026C);
            ir_expression *const r026E = less(r0244, body.constant(int(64)));
            ir_expression *const r026F = bit_and(r0244, body.constant(int(31)));
            ir_expression *const r0270 = rshift(r0247, r026F);
            ir_expression *const r0271 = expr(ir_triop_csel, r026E, r0270, body.constant(0u));
            ir_expression *const r0272 = expr(ir_triop_csel, r026A, r026D, r0271);
            ir_expression *const r0273 = expr(ir_triop_csel, r0269, r0247, r0272);
            body.emit(assign(r0216, expr(ir_triop_csel, r0268, swizzle_x(r020D), r0273), 0x01));

            body.emit(assign(r0228, r025E, 0x01));

            body.emit(assign(r0227, r021E, 0x01));


         body.instructions = f022B_parent_instructions;
         body.emit(f022B);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0229->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0275 = less(r0210, body.constant(int(0)));
         ir_if *f0274 = new(mem_ctx) ir_if(operand(r0275).val);
         exec_list *const f0274_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0274->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0277 = equal(r0221, body.constant(int(2047)));
            ir_if *f0276 = new(mem_ctx) ir_if(operand(r0277).val);
            exec_list *const f0276_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0276->then_instructions;

               ir_variable *const r0278 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0278);
               ir_expression *const r0279 = lshift(r021A, body.constant(int(31)));
               body.emit(assign(r0278, add(r0279, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0278, body.constant(0u), 0x01));

               ir_variable *const r027A = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r027A, swizzle_x(r020C), 0x01));

               ir_variable *const r027B = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r027B, swizzle_x(r020D), 0x01));

               body.emit(assign(r027A, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r027B, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r027C = bit_or(r0215, r0216);
               ir_expression *const r027D = nequal(r027C, body.constant(0u));
               ir_swizzle *const r027E = swizzle(r027D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r027F = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r0280 = gequal(r027F, body.constant(4292870144u));
               ir_expression *const r0281 = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r0282 = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r0283 = nequal(r0282, body.constant(0u));
               ir_expression *const r0284 = logic_or(r0281, r0283);
               ir_expression *const r0285 = logic_and(r0280, r0284);
               ir_swizzle *const r0286 = swizzle(r0285, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0287 = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r0288 = gequal(r0287, body.constant(4292870144u));
               ir_expression *const r0289 = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r028A = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r028B = nequal(r028A, body.constant(0u));
               ir_expression *const r028C = logic_or(r0289, r028B);
               ir_expression *const r028D = logic_and(r0288, r028C);
               ir_swizzle *const r028E = swizzle(r028D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r028F = expr(ir_triop_csel, r028E, r027B, r027A);
               ir_expression *const r0290 = expr(ir_triop_csel, r0286, r028F, r027B);
               body.emit(assign(r020F, expr(ir_triop_csel, r027E, r0290, r0278), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0276->else_instructions;

               ir_variable *const r0291 = body.make_temp(glsl_type::int_type, "mix_retval");
               ir_expression *const r0292 = equal(r021E, body.constant(int(0)));
               ir_expression *const r0293 = add(r0210, body.constant(int(1)));
               body.emit(assign(r0291, expr(ir_triop_csel, r0292, r0293, r0210), 0x01));

               body.emit(assign(r0210, r0291, 0x01));

               ir_variable *const r0294 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0295 = equal(r021E, body.constant(int(0)));
               ir_expression *const r0296 = bit_or(r021C, body.constant(1048576u));
               body.emit(assign(r0294, expr(ir_triop_csel, r0295, r021C, r0296), 0x01));

               ir_variable *const r0297 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0297, neg(r0291), 0x01));

               ir_variable *const r0298 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0298);
               ir_variable *const r0299 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r029A = neg(r0297);
               body.emit(assign(r0299, bit_and(r029A, body.constant(int(31))), 0x01));

               ir_variable *const r029B = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r029C = less(r0297, body.constant(int(32)));
               ir_expression *const r029D = bit_or(body.constant(0u), swizzle_x(r020C));
               body.emit(assign(r029B, expr(ir_triop_csel, r029C, body.constant(0u), r029D), 0x01));

               ir_expression *const r029E = less(r0297, body.constant(int(32)));
               ir_expression *const r029F = lshift(swizzle_x(r020C), r0299);
               ir_expression *const r02A0 = less(r0297, body.constant(int(64)));
               ir_expression *const r02A1 = lshift(r0294, r0299);
               ir_expression *const r02A2 = equal(r0297, body.constant(int(64)));
               ir_expression *const r02A3 = nequal(r0294, body.constant(0u));
               ir_expression *const r02A4 = expr(ir_unop_b2i, r02A3);
               ir_expression *const r02A5 = expr(ir_unop_i2u, r02A4);
               ir_expression *const r02A6 = expr(ir_triop_csel, r02A2, r0294, r02A5);
               ir_expression *const r02A7 = expr(ir_triop_csel, r02A0, r02A1, r02A6);
               ir_expression *const r02A8 = expr(ir_triop_csel, r029E, r029F, r02A7);
               ir_expression *const r02A9 = nequal(r029B, body.constant(0u));
               ir_expression *const r02AA = expr(ir_unop_b2i, r02A9);
               ir_expression *const r02AB = expr(ir_unop_i2u, r02AA);
               body.emit(assign(r0298, bit_or(r02A8, r02AB), 0x01));

               ir_variable *const r02AC = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r02AD = equal(r0297, body.constant(int(0)));
               ir_expression *const r02AE = equal(r0297, body.constant(int(32)));
               ir_expression *const r02AF = expr(ir_triop_csel, r02AE, swizzle_x(r020C), r0298);
               body.emit(assign(r02AC, expr(ir_triop_csel, r02AD, r029B, r02AF), 0x01));

               body.emit(assign(r0298, r02AC, 0x01));

               ir_expression *const r02B0 = equal(r0297, body.constant(int(0)));
               ir_expression *const r02B1 = equal(r0297, body.constant(int(32)));
               ir_expression *const r02B2 = less(r0297, body.constant(int(32)));
               ir_expression *const r02B3 = rshift(r0294, r0297);
               ir_expression *const r02B4 = expr(ir_triop_csel, r02B2, r02B3, body.constant(0u));
               ir_expression *const r02B5 = expr(ir_triop_csel, r02B1, body.constant(0u), r02B4);
               body.emit(assign(r0217, expr(ir_triop_csel, r02B0, r0294, r02B5), 0x01));

               ir_expression *const r02B6 = equal(r0297, body.constant(int(0)));
               ir_expression *const r02B7 = equal(r0297, body.constant(int(32)));
               ir_expression *const r02B8 = less(r0297, body.constant(int(32)));
               ir_expression *const r02B9 = lshift(r0294, r0299);
               ir_expression *const r02BA = rshift(swizzle_x(r020C), r0297);
               ir_expression *const r02BB = bit_or(r02B9, r02BA);
               ir_expression *const r02BC = less(r0297, body.constant(int(64)));
               ir_expression *const r02BD = bit_and(r0297, body.constant(int(31)));
               ir_expression *const r02BE = rshift(r0294, r02BD);
               ir_expression *const r02BF = expr(ir_triop_csel, r02BC, r02BE, body.constant(0u));
               ir_expression *const r02C0 = expr(ir_triop_csel, r02B8, r02BB, r02BF);
               ir_expression *const r02C1 = expr(ir_triop_csel, r02B7, r0294, r02C0);
               body.emit(assign(r0218, expr(ir_triop_csel, r02B6, swizzle_x(r020C), r02C1), 0x01));

               body.emit(assign(r0228, r02AC, 0x01));

               body.emit(assign(r0227, r0221, 0x01));


            body.instructions = f0276_parent_instructions;
            body.emit(f0276);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0274->else_instructions;

            /* IF CONDITION */
            ir_expression *const r02C3 = equal(r021E, body.constant(int(2047)));
            ir_if *f02C2 = new(mem_ctx) ir_if(operand(r02C3).val);
            exec_list *const f02C2_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02C2->then_instructions;

               ir_variable *const r02C4 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r02C4, swizzle_x(r020C), 0x01));

               ir_variable *const r02C5 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r02C5, swizzle_x(r020D), 0x01));

               body.emit(assign(r02C4, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r02C5, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r02C6 = bit_or(r0217, r0218);
               ir_expression *const r02C7 = bit_or(r0215, r0216);
               ir_expression *const r02C8 = bit_or(r02C6, r02C7);
               ir_expression *const r02C9 = nequal(r02C8, body.constant(0u));
               ir_swizzle *const r02CA = swizzle(r02C9, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r02CB = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r02CC = gequal(r02CB, body.constant(4292870144u));
               ir_expression *const r02CD = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r02CE = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r02CF = nequal(r02CE, body.constant(0u));
               ir_expression *const r02D0 = logic_or(r02CD, r02CF);
               ir_expression *const r02D1 = logic_and(r02CC, r02D0);
               ir_swizzle *const r02D2 = swizzle(r02D1, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r02D3 = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r02D4 = gequal(r02D3, body.constant(4292870144u));
               ir_expression *const r02D5 = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r02D6 = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r02D7 = nequal(r02D6, body.constant(0u));
               ir_expression *const r02D8 = logic_or(r02D5, r02D7);
               ir_expression *const r02D9 = logic_and(r02D4, r02D8);
               ir_swizzle *const r02DA = swizzle(r02D9, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r02DB = expr(ir_triop_csel, r02DA, r02C5, r02C4);
               ir_expression *const r02DC = expr(ir_triop_csel, r02D2, r02DB, r02C5);
               body.emit(assign(r020F, expr(ir_triop_csel, r02CA, r02DC, r020C), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f02C2->else_instructions;

               ir_variable *const r02DD = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r02DE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r02DE, add(r0218, r0216), 0x01));

               ir_expression *const r02DF = add(r0217, r0215);
               ir_expression *const r02E0 = less(r02DE, r0218);
               ir_expression *const r02E1 = expr(ir_unop_b2i, r02E0);
               ir_expression *const r02E2 = expr(ir_unop_i2u, r02E1);
               body.emit(assign(r02DD, add(r02DF, r02E2), 0x01));

               body.emit(assign(r0212, r02DD, 0x01));

               body.emit(assign(r0211, r02DE, 0x01));

               /* IF CONDITION */
               ir_expression *const r02E4 = equal(r021E, body.constant(int(0)));
               ir_if *f02E3 = new(mem_ctx) ir_if(operand(r02E4).val);
               exec_list *const f02E3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02E3->then_instructions;

                  ir_variable *const r02E5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02E5);
                  ir_expression *const r02E6 = lshift(r021A, body.constant(int(31)));
                  body.emit(assign(r02E5, add(r02E6, r02DD), 0x02));

                  body.emit(assign(r02E5, r02DE, 0x01));

                  body.emit(assign(r020F, r02E5, 0x03));

                  body.emit(assign(r020E, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02E3->else_instructions;

                  body.emit(assign(r0212, bit_or(r02DD, body.constant(2097152u)), 0x01));

                  body.emit(assign(r0227, r021E, 0x01));

                  ir_variable *const r02E7 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_variable *const r02E8 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  ir_variable *const r02E9 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r02EA = lshift(r02DE, body.constant(int(31)));
                  body.emit(assign(r02E9, bit_or(r02EA, body.constant(0u)), 0x01));

                  ir_expression *const r02EB = lshift(r0212, body.constant(int(31)));
                  ir_expression *const r02EC = rshift(r02DE, body.constant(int(1)));
                  body.emit(assign(r02E8, bit_or(r02EB, r02EC), 0x01));

                  body.emit(assign(r02E7, rshift(r0212, body.constant(int(1))), 0x01));

                  body.emit(assign(r0212, r02E7, 0x01));

                  body.emit(assign(r0211, r02E8, 0x01));

                  body.emit(assign(r0228, r02E9, 0x01));

                  ir_variable *const r02ED = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r02ED, r021E, 0x01));

                  ir_variable *const r02EE = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r02EE, r02E7, 0x01));

                  ir_variable *const r02EF = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r02EF, r02E8, 0x01));

                  ir_variable *const r02F0 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r02F0, r02E9, 0x01));

                  ir_variable *const r02F1 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r02F1, body.constant(true), 0x01));

                  ir_variable *const r02F2 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r02F3 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r02F3);
                  ir_expression *const r02F4 = expr(ir_unop_u2i, r02E9);
                  body.emit(assign(r02F3, less(r02F4, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r02F6 = gequal(r021E, body.constant(int(2045)));
                  ir_if *f02F5 = new(mem_ctx) ir_if(operand(r02F6).val);
                  exec_list *const f02F5_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02F5->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r02F8 = less(body.constant(int(2045)), r021E);
                     ir_expression *const r02F9 = equal(r021E, body.constant(int(2045)));
                     ir_expression *const r02FA = equal(body.constant(2097151u), r02E7);
                     ir_expression *const r02FB = equal(body.constant(4294967295u), r02E8);
                     ir_expression *const r02FC = logic_and(r02FA, r02FB);
                     ir_expression *const r02FD = logic_and(r02F9, r02FC);
                     ir_expression *const r02FE = logic_and(r02FD, r02F3);
                     ir_expression *const r02FF = logic_or(r02F8, r02FE);
                     ir_if *f02F7 = new(mem_ctx) ir_if(operand(r02FF).val);
                     exec_list *const f02F7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02F7->then_instructions;

                        ir_variable *const r0300 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0300);
                        ir_expression *const r0301 = lshift(r021A, body.constant(int(31)));
                        body.emit(assign(r0300, add(r0301, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0300, body.constant(0u), 0x01));

                        body.emit(assign(r02F2, r0300, 0x03));

                        body.emit(assign(r02F1, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02F7->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0303 = less(r021E, body.constant(int(0)));
                        ir_if *f0302 = new(mem_ctx) ir_if(operand(r0303).val);
                        exec_list *const f0302_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0302->then_instructions;

                           ir_variable *const r0304 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0304, neg(r021E), 0x01));

                           ir_variable *const r0305 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0305);
                           ir_variable *const r0306 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0307 = neg(r0304);
                           body.emit(assign(r0306, bit_and(r0307, body.constant(int(31))), 0x01));

                           ir_variable *const r0308 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r0309 = less(r0304, body.constant(int(32)));
                           ir_expression *const r030A = bit_or(r02E9, r02E8);
                           body.emit(assign(r0308, expr(ir_triop_csel, r0309, r02E9, r030A), 0x01));

                           ir_expression *const r030B = less(r0304, body.constant(int(32)));
                           ir_expression *const r030C = lshift(r02E8, r0306);
                           ir_expression *const r030D = less(r0304, body.constant(int(64)));
                           ir_expression *const r030E = lshift(r02E7, r0306);
                           ir_expression *const r030F = equal(r0304, body.constant(int(64)));
                           ir_expression *const r0310 = nequal(r02E7, body.constant(0u));
                           ir_expression *const r0311 = expr(ir_unop_b2i, r0310);
                           ir_expression *const r0312 = expr(ir_unop_i2u, r0311);
                           ir_expression *const r0313 = expr(ir_triop_csel, r030F, r02E7, r0312);
                           ir_expression *const r0314 = expr(ir_triop_csel, r030D, r030E, r0313);
                           ir_expression *const r0315 = expr(ir_triop_csel, r030B, r030C, r0314);
                           ir_expression *const r0316 = nequal(r0308, body.constant(0u));
                           ir_expression *const r0317 = expr(ir_unop_b2i, r0316);
                           ir_expression *const r0318 = expr(ir_unop_i2u, r0317);
                           body.emit(assign(r0305, bit_or(r0315, r0318), 0x01));

                           ir_variable *const r0319 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r031A = equal(r0304, body.constant(int(0)));
                           ir_expression *const r031B = equal(r0304, body.constant(int(32)));
                           ir_expression *const r031C = expr(ir_triop_csel, r031B, r02E8, r0305);
                           body.emit(assign(r0319, expr(ir_triop_csel, r031A, r0308, r031C), 0x01));

                           body.emit(assign(r0305, r0319, 0x01));

                           ir_expression *const r031D = equal(r0304, body.constant(int(0)));
                           ir_expression *const r031E = equal(r0304, body.constant(int(32)));
                           ir_expression *const r031F = less(r0304, body.constant(int(32)));
                           ir_expression *const r0320 = rshift(r02E7, r0304);
                           ir_expression *const r0321 = expr(ir_triop_csel, r031F, r0320, body.constant(0u));
                           ir_expression *const r0322 = expr(ir_triop_csel, r031E, body.constant(0u), r0321);
                           body.emit(assign(r02EE, expr(ir_triop_csel, r031D, r02E7, r0322), 0x01));

                           ir_expression *const r0323 = equal(r0304, body.constant(int(0)));
                           ir_expression *const r0324 = equal(r0304, body.constant(int(32)));
                           ir_expression *const r0325 = less(r0304, body.constant(int(32)));
                           ir_expression *const r0326 = lshift(r02E7, r0306);
                           ir_expression *const r0327 = rshift(r02E8, r0304);
                           ir_expression *const r0328 = bit_or(r0326, r0327);
                           ir_expression *const r0329 = less(r0304, body.constant(int(64)));
                           ir_expression *const r032A = bit_and(r0304, body.constant(int(31)));
                           ir_expression *const r032B = rshift(r02E7, r032A);
                           ir_expression *const r032C = expr(ir_triop_csel, r0329, r032B, body.constant(0u));
                           ir_expression *const r032D = expr(ir_triop_csel, r0325, r0328, r032C);
                           ir_expression *const r032E = expr(ir_triop_csel, r0324, r02E7, r032D);
                           body.emit(assign(r02EF, expr(ir_triop_csel, r0323, r02E8, r032E), 0x01));

                           body.emit(assign(r02F0, r0319, 0x01));

                           body.emit(assign(r02ED, body.constant(int(0)), 0x01));

                           body.emit(assign(r02F3, less(r0319, body.constant(0u)), 0x01));


                        body.instructions = f0302_parent_instructions;
                        body.emit(f0302);

                        /* END IF */


                     body.instructions = f02F7_parent_instructions;
                     body.emit(f02F7);

                     /* END IF */


                  body.instructions = f02F5_parent_instructions;
                  body.emit(f02F5);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f032F = new(mem_ctx) ir_if(operand(r02F1).val);
                  exec_list *const f032F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f032F->then_instructions;

                     /* IF CONDITION */
                     ir_if *f0330 = new(mem_ctx) ir_if(operand(r02F3).val);
                     exec_list *const f0330_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0330->then_instructions;

                        ir_variable *const r0331 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r0331, add(r02EF, body.constant(1u)), 0x01));

                        ir_expression *const r0332 = less(r0331, r02EF);
                        ir_expression *const r0333 = expr(ir_unop_b2i, r0332);
                        ir_expression *const r0334 = expr(ir_unop_i2u, r0333);
                        body.emit(assign(r02EE, add(r02EE, r0334), 0x01));

                        ir_expression *const r0335 = equal(r02F0, body.constant(0u));
                        ir_expression *const r0336 = expr(ir_unop_b2i, r0335);
                        ir_expression *const r0337 = expr(ir_unop_i2u, r0336);
                        ir_expression *const r0338 = add(r02F0, r0337);
                        ir_expression *const r0339 = bit_and(r0338, body.constant(1u));
                        ir_expression *const r033A = expr(ir_unop_bit_not, r0339);
                        body.emit(assign(r02EF, bit_and(r0331, r033A), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0330->else_instructions;

                        ir_expression *const r033B = bit_or(r02EE, r02EF);
                        ir_expression *const r033C = equal(r033B, body.constant(0u));
                        body.emit(assign(r02ED, expr(ir_triop_csel, r033C, body.constant(int(0)), r02ED), 0x01));


                     body.instructions = f0330_parent_instructions;
                     body.emit(f0330);

                     /* END IF */

                     ir_variable *const r033D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r033D);
                     ir_expression *const r033E = lshift(r021A, body.constant(int(31)));
                     ir_expression *const r033F = expr(ir_unop_i2u, r02ED);
                     ir_expression *const r0340 = lshift(r033F, body.constant(int(20)));
                     ir_expression *const r0341 = add(r033E, r0340);
                     body.emit(assign(r033D, add(r0341, r02EE), 0x02));

                     body.emit(assign(r033D, r02EF, 0x01));

                     body.emit(assign(r02F2, r033D, 0x03));

                     body.emit(assign(r02F1, body.constant(false), 0x01));


                  body.instructions = f032F_parent_instructions;
                  body.emit(f032F);

                  /* END IF */

                  body.emit(assign(r020F, r02F2, 0x03));

                  body.emit(assign(r020E, body.constant(false), 0x01));


               body.instructions = f02E3_parent_instructions;
               body.emit(f02E3);

               /* END IF */


            body.instructions = f02C2_parent_instructions;
            body.emit(f02C2);

            /* END IF */


         body.instructions = f0274_parent_instructions;
         body.emit(f0274);

         /* END IF */


      body.instructions = f0229_parent_instructions;
      body.emit(f0229);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0342 = new(mem_ctx) ir_if(operand(r020E).val);
      exec_list *const f0342_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0342->then_instructions;

         body.emit(assign(r0217, bit_or(r0217, body.constant(1048576u)), 0x01));

         ir_variable *const r0343 = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r0344 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0344, add(r0218, r0216), 0x01));

         ir_expression *const r0345 = add(r0217, r0215);
         ir_expression *const r0346 = less(r0344, r0218);
         ir_expression *const r0347 = expr(ir_unop_b2i, r0346);
         ir_expression *const r0348 = expr(ir_unop_i2u, r0347);
         body.emit(assign(r0343, add(r0345, r0348), 0x01));

         body.emit(assign(r0212, r0343, 0x01));

         body.emit(assign(r0211, r0344, 0x01));

         body.emit(assign(r0227, add(r0227, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r034A = gequal(r0343, body.constant(2097152u));
         ir_if *f0349 = new(mem_ctx) ir_if(operand(r034A).val);
         exec_list *const f0349_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0349->then_instructions;

            body.emit(assign(r0212, rshift(r0343, body.constant(int(1))), 0x01));

            ir_expression *const r034B = lshift(r0343, body.constant(int(31)));
            ir_expression *const r034C = rshift(r0344, body.constant(int(1)));
            body.emit(assign(r0211, bit_or(r034B, r034C), 0x01));

            ir_expression *const r034D = lshift(r0344, body.constant(int(31)));
            ir_expression *const r034E = nequal(r0228, body.constant(0u));
            ir_expression *const r034F = expr(ir_unop_b2i, r034E);
            ir_expression *const r0350 = expr(ir_unop_i2u, r034F);
            body.emit(assign(r0228, bit_or(r034D, r0350), 0x01));

            body.emit(assign(r0227, add(r0227, body.constant(int(1))), 0x01));


         body.instructions = f0349_parent_instructions;
         body.emit(f0349);

         /* END IF */

         ir_variable *const r0351 = body.make_temp(glsl_type::int_type, "zExp");
         body.emit(assign(r0351, r0227, 0x01));

         ir_variable *const r0352 = body.make_temp(glsl_type::uint_type, "zFrac0");
         body.emit(assign(r0352, r0212, 0x01));

         ir_variable *const r0353 = body.make_temp(glsl_type::uint_type, "zFrac1");
         body.emit(assign(r0353, r0211, 0x01));

         ir_variable *const r0354 = body.make_temp(glsl_type::uint_type, "zFrac2");
         body.emit(assign(r0354, r0228, 0x01));

         ir_variable *const r0355 = body.make_temp(glsl_type::bool_type, "execute_flag");
         body.emit(assign(r0355, body.constant(true), 0x01));

         ir_variable *const r0356 = body.make_temp(glsl_type::uvec2_type, "return_value");
         ir_variable *const r0357 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
         body.emit(r0357);
         ir_expression *const r0358 = expr(ir_unop_u2i, r0228);
         body.emit(assign(r0357, less(r0358, body.constant(int(0))), 0x01));

         /* IF CONDITION */
         ir_expression *const r035A = gequal(r0227, body.constant(int(2045)));
         ir_if *f0359 = new(mem_ctx) ir_if(operand(r035A).val);
         exec_list *const f0359_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0359->then_instructions;

            /* IF CONDITION */
            ir_expression *const r035C = less(body.constant(int(2045)), r0227);
            ir_expression *const r035D = equal(r0227, body.constant(int(2045)));
            ir_expression *const r035E = equal(body.constant(2097151u), r0212);
            ir_expression *const r035F = equal(body.constant(4294967295u), r0211);
            ir_expression *const r0360 = logic_and(r035E, r035F);
            ir_expression *const r0361 = logic_and(r035D, r0360);
            ir_expression *const r0362 = logic_and(r0361, r0357);
            ir_expression *const r0363 = logic_or(r035C, r0362);
            ir_if *f035B = new(mem_ctx) ir_if(operand(r0363).val);
            exec_list *const f035B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f035B->then_instructions;

               ir_variable *const r0364 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0364);
               ir_expression *const r0365 = lshift(r021A, body.constant(int(31)));
               body.emit(assign(r0364, add(r0365, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0364, body.constant(0u), 0x01));

               body.emit(assign(r0356, r0364, 0x03));

               body.emit(assign(r0355, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f035B->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0367 = less(r0227, body.constant(int(0)));
               ir_if *f0366 = new(mem_ctx) ir_if(operand(r0367).val);
               exec_list *const f0366_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0366->then_instructions;

                  ir_variable *const r0368 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r0368, neg(r0227), 0x01));

                  ir_variable *const r0369 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0369);
                  ir_variable *const r036A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r036B = neg(r0368);
                  body.emit(assign(r036A, bit_and(r036B, body.constant(int(31))), 0x01));

                  ir_variable *const r036C = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r036D = less(r0368, body.constant(int(32)));
                  ir_expression *const r036E = bit_or(r0228, r0211);
                  body.emit(assign(r036C, expr(ir_triop_csel, r036D, r0228, r036E), 0x01));

                  ir_expression *const r036F = less(r0368, body.constant(int(32)));
                  ir_expression *const r0370 = lshift(r0211, r036A);
                  ir_expression *const r0371 = less(r0368, body.constant(int(64)));
                  ir_expression *const r0372 = lshift(r0212, r036A);
                  ir_expression *const r0373 = equal(r0368, body.constant(int(64)));
                  ir_expression *const r0374 = nequal(r0212, body.constant(0u));
                  ir_expression *const r0375 = expr(ir_unop_b2i, r0374);
                  ir_expression *const r0376 = expr(ir_unop_i2u, r0375);
                  ir_expression *const r0377 = expr(ir_triop_csel, r0373, r0212, r0376);
                  ir_expression *const r0378 = expr(ir_triop_csel, r0371, r0372, r0377);
                  ir_expression *const r0379 = expr(ir_triop_csel, r036F, r0370, r0378);
                  ir_expression *const r037A = nequal(r036C, body.constant(0u));
                  ir_expression *const r037B = expr(ir_unop_b2i, r037A);
                  ir_expression *const r037C = expr(ir_unop_i2u, r037B);
                  body.emit(assign(r0369, bit_or(r0379, r037C), 0x01));

                  ir_variable *const r037D = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r037E = equal(r0368, body.constant(int(0)));
                  ir_expression *const r037F = equal(r0368, body.constant(int(32)));
                  ir_expression *const r0380 = expr(ir_triop_csel, r037F, r0211, r0369);
                  body.emit(assign(r037D, expr(ir_triop_csel, r037E, r036C, r0380), 0x01));

                  body.emit(assign(r0369, r037D, 0x01));

                  ir_expression *const r0381 = equal(r0368, body.constant(int(0)));
                  ir_expression *const r0382 = equal(r0368, body.constant(int(32)));
                  ir_expression *const r0383 = less(r0368, body.constant(int(32)));
                  ir_expression *const r0384 = rshift(r0212, r0368);
                  ir_expression *const r0385 = expr(ir_triop_csel, r0383, r0384, body.constant(0u));
                  ir_expression *const r0386 = expr(ir_triop_csel, r0382, body.constant(0u), r0385);
                  body.emit(assign(r0352, expr(ir_triop_csel, r0381, r0212, r0386), 0x01));

                  ir_expression *const r0387 = equal(r0368, body.constant(int(0)));
                  ir_expression *const r0388 = equal(r0368, body.constant(int(32)));
                  ir_expression *const r0389 = less(r0368, body.constant(int(32)));
                  ir_expression *const r038A = lshift(r0212, r036A);
                  ir_expression *const r038B = rshift(r0211, r0368);
                  ir_expression *const r038C = bit_or(r038A, r038B);
                  ir_expression *const r038D = less(r0368, body.constant(int(64)));
                  ir_expression *const r038E = bit_and(r0368, body.constant(int(31)));
                  ir_expression *const r038F = rshift(r0212, r038E);
                  ir_expression *const r0390 = expr(ir_triop_csel, r038D, r038F, body.constant(0u));
                  ir_expression *const r0391 = expr(ir_triop_csel, r0389, r038C, r0390);
                  ir_expression *const r0392 = expr(ir_triop_csel, r0388, r0212, r0391);
                  body.emit(assign(r0353, expr(ir_triop_csel, r0387, r0211, r0392), 0x01));

                  body.emit(assign(r0354, r037D, 0x01));

                  body.emit(assign(r0351, body.constant(int(0)), 0x01));

                  body.emit(assign(r0357, less(r037D, body.constant(0u)), 0x01));


               body.instructions = f0366_parent_instructions;
               body.emit(f0366);

               /* END IF */


            body.instructions = f035B_parent_instructions;
            body.emit(f035B);

            /* END IF */


         body.instructions = f0359_parent_instructions;
         body.emit(f0359);

         /* END IF */

         /* IF CONDITION */
         ir_if *f0393 = new(mem_ctx) ir_if(operand(r0355).val);
         exec_list *const f0393_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0393->then_instructions;

            /* IF CONDITION */
            ir_if *f0394 = new(mem_ctx) ir_if(operand(r0357).val);
            exec_list *const f0394_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0394->then_instructions;

               ir_variable *const r0395 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0395, add(r0353, body.constant(1u)), 0x01));

               ir_expression *const r0396 = less(r0395, r0353);
               ir_expression *const r0397 = expr(ir_unop_b2i, r0396);
               ir_expression *const r0398 = expr(ir_unop_i2u, r0397);
               body.emit(assign(r0352, add(r0352, r0398), 0x01));

               ir_expression *const r0399 = equal(r0354, body.constant(0u));
               ir_expression *const r039A = expr(ir_unop_b2i, r0399);
               ir_expression *const r039B = expr(ir_unop_i2u, r039A);
               ir_expression *const r039C = add(r0354, r039B);
               ir_expression *const r039D = bit_and(r039C, body.constant(1u));
               ir_expression *const r039E = expr(ir_unop_bit_not, r039D);
               body.emit(assign(r0353, bit_and(r0395, r039E), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0394->else_instructions;

               ir_expression *const r039F = bit_or(r0352, r0353);
               ir_expression *const r03A0 = equal(r039F, body.constant(0u));
               body.emit(assign(r0351, expr(ir_triop_csel, r03A0, body.constant(int(0)), r0351), 0x01));


            body.instructions = f0394_parent_instructions;
            body.emit(f0394);

            /* END IF */

            ir_variable *const r03A1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r03A1);
            ir_expression *const r03A2 = lshift(r021A, body.constant(int(31)));
            ir_expression *const r03A3 = expr(ir_unop_i2u, r0351);
            ir_expression *const r03A4 = lshift(r03A3, body.constant(int(20)));
            ir_expression *const r03A5 = add(r03A2, r03A4);
            body.emit(assign(r03A1, add(r03A5, r0352), 0x02));

            body.emit(assign(r03A1, r0353, 0x01));

            body.emit(assign(r0356, r03A1, 0x03));

            body.emit(assign(r0355, body.constant(false), 0x01));


         body.instructions = f0393_parent_instructions;
         body.emit(f0393);

         /* END IF */

         body.emit(assign(r020F, r0356, 0x03));

         body.emit(assign(r020E, body.constant(false), 0x01));


      body.instructions = f0342_parent_instructions;
      body.emit(f0342);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0225->else_instructions;

      ir_variable *const r03A6 = new(mem_ctx) ir_variable(glsl_type::bool_type, "blta", ir_var_auto);
      body.emit(r03A6);
      ir_variable *const r03A7 = new(mem_ctx) ir_variable(glsl_type::bool_type, "zexp_normal", ir_var_auto);
      body.emit(r03A7);
      ir_variable *const r03A8 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r03A8);
      ir_variable *const r03A9 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r03AA = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r03AA, lshift(r0218, body.constant(int(10))), 0x01));

      ir_expression *const r03AB = lshift(r0217, body.constant(int(10)));
      ir_expression *const r03AC = rshift(r0218, body.constant(int(22)));
      body.emit(assign(r03A9, bit_or(r03AB, r03AC), 0x01));

      body.emit(assign(r0217, r03A9, 0x01));

      body.emit(assign(r0218, r03AA, 0x01));

      ir_variable *const r03AD = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r03AE = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r03AE, lshift(r0216, body.constant(int(10))), 0x01));

      ir_expression *const r03AF = lshift(r0215, body.constant(int(10)));
      ir_expression *const r03B0 = rshift(r0216, body.constant(int(22)));
      body.emit(assign(r03AD, bit_or(r03AF, r03B0), 0x01));

      body.emit(assign(r0215, r03AD, 0x01));

      body.emit(assign(r0216, r03AE, 0x01));

      /* IF CONDITION */
      ir_expression *const r03B2 = less(body.constant(int(0)), r0210);
      ir_if *f03B1 = new(mem_ctx) ir_if(operand(r03B2).val);
      exec_list *const f03B1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f03B1->then_instructions;

         /* IF CONDITION */
         ir_expression *const r03B4 = equal(r021E, body.constant(int(2047)));
         ir_if *f03B3 = new(mem_ctx) ir_if(operand(r03B4).val);
         exec_list *const f03B3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f03B3->then_instructions;

            ir_variable *const r03B5 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r03B5, swizzle_x(r020C), 0x01));

            ir_variable *const r03B6 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r03B6, swizzle_x(r020D), 0x01));

            body.emit(assign(r03B5, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

            body.emit(assign(r03B6, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

            ir_expression *const r03B7 = bit_or(r03A9, r03AA);
            ir_expression *const r03B8 = nequal(r03B7, body.constant(0u));
            ir_swizzle *const r03B9 = swizzle(r03B8, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r03BA = lshift(swizzle_y(r020C), body.constant(int(1)));
            ir_expression *const r03BB = gequal(r03BA, body.constant(4292870144u));
            ir_expression *const r03BC = nequal(swizzle_x(r020C), body.constant(0u));
            ir_expression *const r03BD = bit_and(swizzle_y(r020C), body.constant(1048575u));
            ir_expression *const r03BE = nequal(r03BD, body.constant(0u));
            ir_expression *const r03BF = logic_or(r03BC, r03BE);
            ir_expression *const r03C0 = logic_and(r03BB, r03BF);
            ir_swizzle *const r03C1 = swizzle(r03C0, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r03C2 = lshift(swizzle_y(r020D), body.constant(int(1)));
            ir_expression *const r03C3 = gequal(r03C2, body.constant(4292870144u));
            ir_expression *const r03C4 = nequal(swizzle_x(r020D), body.constant(0u));
            ir_expression *const r03C5 = bit_and(swizzle_y(r020D), body.constant(1048575u));
            ir_expression *const r03C6 = nequal(r03C5, body.constant(0u));
            ir_expression *const r03C7 = logic_or(r03C4, r03C6);
            ir_expression *const r03C8 = logic_and(r03C3, r03C7);
            ir_swizzle *const r03C9 = swizzle(r03C8, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r03CA = expr(ir_triop_csel, r03C9, r03B6, r03B5);
            ir_expression *const r03CB = expr(ir_triop_csel, r03C1, r03CA, r03B6);
            body.emit(assign(r020F, expr(ir_triop_csel, r03B9, r03CB, r020C), 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f03B3->else_instructions;

            ir_variable *const r03CC = body.make_temp(glsl_type::int_type, "mix_retval");
            ir_expression *const r03CD = equal(r0221, body.constant(int(0)));
            ir_expression *const r03CE = add(r0210, body.constant(int(-1)));
            body.emit(assign(r03CC, expr(ir_triop_csel, r03CD, r03CE, r0210), 0x01));

            body.emit(assign(r0210, r03CC, 0x01));

            ir_variable *const r03CF = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03D0 = equal(r0221, body.constant(int(0)));
            ir_expression *const r03D1 = bit_or(r03AD, body.constant(1073741824u));
            body.emit(assign(r03CF, expr(ir_triop_csel, r03D0, r03AD, r03D1), 0x01));

            ir_variable *const r03D2 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r03D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r03D3);
            ir_variable *const r03D4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r03D5 = neg(r03CC);
            body.emit(assign(r03D4, bit_and(r03D5, body.constant(int(31))), 0x01));

            ir_expression *const r03D6 = bit_or(r03CF, r03AE);
            ir_expression *const r03D7 = nequal(r03D6, body.constant(0u));
            ir_expression *const r03D8 = expr(ir_unop_b2i, r03D7);
            body.emit(assign(r03D3, expr(ir_unop_i2u, r03D8), 0x01));

            ir_variable *const r03D9 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03DA = equal(r03CC, body.constant(int(0)));
            ir_expression *const r03DB = less(r03CC, body.constant(int(32)));
            ir_expression *const r03DC = lshift(r03CF, r03D4);
            ir_expression *const r03DD = rshift(r03AE, r03CC);
            ir_expression *const r03DE = bit_or(r03DC, r03DD);
            ir_expression *const r03DF = lshift(r03AE, r03D4);
            ir_expression *const r03E0 = nequal(r03DF, body.constant(0u));
            ir_expression *const r03E1 = expr(ir_unop_b2i, r03E0);
            ir_expression *const r03E2 = expr(ir_unop_i2u, r03E1);
            ir_expression *const r03E3 = bit_or(r03DE, r03E2);
            ir_expression *const r03E4 = equal(r03CC, body.constant(int(32)));
            ir_expression *const r03E5 = nequal(r03AE, body.constant(0u));
            ir_expression *const r03E6 = expr(ir_unop_b2i, r03E5);
            ir_expression *const r03E7 = expr(ir_unop_i2u, r03E6);
            ir_expression *const r03E8 = bit_or(r03CF, r03E7);
            ir_expression *const r03E9 = less(r03CC, body.constant(int(64)));
            ir_expression *const r03EA = bit_and(r03CC, body.constant(int(31)));
            ir_expression *const r03EB = rshift(r03CF, r03EA);
            ir_expression *const r03EC = lshift(r03CF, r03D4);
            ir_expression *const r03ED = bit_or(r03EC, r03AE);
            ir_expression *const r03EE = nequal(r03ED, body.constant(0u));
            ir_expression *const r03EF = expr(ir_unop_b2i, r03EE);
            ir_expression *const r03F0 = expr(ir_unop_i2u, r03EF);
            ir_expression *const r03F1 = bit_or(r03EB, r03F0);
            ir_expression *const r03F2 = expr(ir_triop_csel, r03E9, r03F1, r03D3);
            ir_expression *const r03F3 = expr(ir_triop_csel, r03E4, r03E8, r03F2);
            ir_expression *const r03F4 = expr(ir_triop_csel, r03DB, r03E3, r03F3);
            body.emit(assign(r03D9, expr(ir_triop_csel, r03DA, r03AE, r03F4), 0x01));

            body.emit(assign(r03D3, r03D9, 0x01));

            ir_expression *const r03F5 = less(r03CC, body.constant(int(32)));
            ir_expression *const r03F6 = rshift(r03CF, r03CC);
            ir_expression *const r03F7 = equal(r03CC, body.constant(int(0)));
            ir_expression *const r03F8 = expr(ir_triop_csel, r03F7, r03CF, body.constant(0u));
            body.emit(assign(r03D2, expr(ir_triop_csel, r03F5, r03F6, r03F8), 0x01));

            body.emit(assign(r0215, r03D2, 0x01));

            body.emit(assign(r0216, r03D9, 0x01));

            body.emit(assign(r0217, bit_or(r03A9, body.constant(1073741824u)), 0x01));

            ir_variable *const r03F9 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r03FA = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r03FA, sub(r03AA, r03D9), 0x01));

            ir_expression *const r03FB = sub(r0217, r03D2);
            ir_expression *const r03FC = less(r03AA, r03D9);
            ir_expression *const r03FD = expr(ir_unop_b2i, r03FC);
            ir_expression *const r03FE = expr(ir_unop_i2u, r03FD);
            body.emit(assign(r03F9, sub(r03FB, r03FE), 0x01));

            body.emit(assign(r0212, r03F9, 0x01));

            body.emit(assign(r0211, r03FA, 0x01));

            body.emit(assign(r03A8, add(r021E, body.constant(int(-1))), 0x01));

            ir_variable *const r03FF = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03FF, add(r03A8, body.constant(int(-10))), 0x01));

            ir_variable *const r0400 = body.make_temp(glsl_type::uint_type, "zFrac0");
            ir_variable *const r0401 = body.make_temp(glsl_type::uint_type, "zFrac1");
            ir_variable *const r0402 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r0402);
            ir_variable *const r0403 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0403);
            ir_expression *const r0404 = equal(r03F9, body.constant(0u));
            ir_expression *const r0405 = add(r03FF, body.constant(int(-32)));
            body.emit(assign(r03FF, expr(ir_triop_csel, r0404, r0405, r03FF), 0x01));

            ir_variable *const r0406 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0407 = equal(r03F9, body.constant(0u));
            body.emit(assign(r0406, expr(ir_triop_csel, r0407, body.constant(0u), r03FA), 0x01));

            body.emit(assign(r0401, r0406, 0x01));

            ir_variable *const r0408 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0409 = equal(r03F9, body.constant(0u));
            body.emit(assign(r0408, expr(ir_triop_csel, r0409, r0406, r03F9), 0x01));

            body.emit(assign(r0400, r0408, 0x01));

            ir_expression *const r040A = equal(r0408, body.constant(0u));
            ir_expression *const r040B = expr(ir_unop_find_msb, r0408);
            ir_expression *const r040C = sub(body.constant(int(31)), r040B);
            ir_expression *const r040D = expr(ir_triop_csel, r040A, body.constant(int(32)), r040C);
            body.emit(assign(r0403, add(r040D, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r040F = gequal(r0403, body.constant(int(0)));
            ir_if *f040E = new(mem_ctx) ir_if(operand(r040F).val);
            exec_list *const f040E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f040E->then_instructions;

               body.emit(assign(r0402, body.constant(0u), 0x01));

               ir_expression *const r0410 = equal(r0403, body.constant(int(0)));
               ir_expression *const r0411 = lshift(r0408, r0403);
               ir_expression *const r0412 = neg(r0403);
               ir_expression *const r0413 = bit_and(r0412, body.constant(int(31)));
               ir_expression *const r0414 = rshift(r0406, r0413);
               ir_expression *const r0415 = bit_or(r0411, r0414);
               body.emit(assign(r0400, expr(ir_triop_csel, r0410, r0408, r0415), 0x01));

               body.emit(assign(r0401, lshift(r0406, r0403), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f040E->else_instructions;

               ir_variable *const r0416 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0416, neg(r0403), 0x01));

               ir_variable *const r0417 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               ir_variable *const r0418 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0418);
               ir_variable *const r0419 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r041A = neg(r0416);
               body.emit(assign(r0419, bit_and(r041A, body.constant(int(31))), 0x01));

               ir_variable *const r041B = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r041C = less(r0416, body.constant(int(32)));
               ir_expression *const r041D = bit_or(body.constant(0u), r0401);
               body.emit(assign(r041B, expr(ir_triop_csel, r041C, body.constant(0u), r041D), 0x01));

               ir_expression *const r041E = less(r0416, body.constant(int(32)));
               ir_expression *const r041F = lshift(r0401, r0419);
               ir_expression *const r0420 = less(r0416, body.constant(int(64)));
               ir_expression *const r0421 = lshift(r0400, r0419);
               ir_expression *const r0422 = equal(r0416, body.constant(int(64)));
               ir_expression *const r0423 = nequal(r0400, body.constant(0u));
               ir_expression *const r0424 = expr(ir_unop_b2i, r0423);
               ir_expression *const r0425 = expr(ir_unop_i2u, r0424);
               ir_expression *const r0426 = expr(ir_triop_csel, r0422, r0400, r0425);
               ir_expression *const r0427 = expr(ir_triop_csel, r0420, r0421, r0426);
               ir_expression *const r0428 = expr(ir_triop_csel, r041E, r041F, r0427);
               ir_expression *const r0429 = nequal(r041B, body.constant(0u));
               ir_expression *const r042A = expr(ir_unop_b2i, r0429);
               ir_expression *const r042B = expr(ir_unop_i2u, r042A);
               body.emit(assign(r0418, bit_or(r0428, r042B), 0x01));

               ir_variable *const r042C = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r042D = equal(r0416, body.constant(int(0)));
               ir_expression *const r042E = equal(r0416, body.constant(int(32)));
               ir_expression *const r042F = expr(ir_triop_csel, r042E, r0401, r0418);
               body.emit(assign(r042C, expr(ir_triop_csel, r042D, r041B, r042F), 0x01));

               body.emit(assign(r0418, r042C, 0x01));

               ir_expression *const r0430 = equal(r0416, body.constant(int(0)));
               ir_expression *const r0431 = equal(r0416, body.constant(int(32)));
               ir_expression *const r0432 = less(r0416, body.constant(int(32)));
               ir_expression *const r0433 = lshift(r0400, r0419);
               ir_expression *const r0434 = rshift(r0401, r0416);
               ir_expression *const r0435 = bit_or(r0433, r0434);
               ir_expression *const r0436 = less(r0416, body.constant(int(64)));
               ir_expression *const r0437 = bit_and(r0416, body.constant(int(31)));
               ir_expression *const r0438 = rshift(r0400, r0437);
               ir_expression *const r0439 = expr(ir_triop_csel, r0436, r0438, body.constant(0u));
               ir_expression *const r043A = expr(ir_triop_csel, r0432, r0435, r0439);
               ir_expression *const r043B = expr(ir_triop_csel, r0431, r0400, r043A);
               body.emit(assign(r0417, expr(ir_triop_csel, r0430, r0401, r043B), 0x01));

               ir_expression *const r043C = equal(r0416, body.constant(int(0)));
               ir_expression *const r043D = equal(r0416, body.constant(int(32)));
               ir_expression *const r043E = less(r0416, body.constant(int(32)));
               ir_expression *const r043F = rshift(r0400, r0416);
               ir_expression *const r0440 = expr(ir_triop_csel, r043E, r043F, body.constant(0u));
               ir_expression *const r0441 = expr(ir_triop_csel, r043D, body.constant(0u), r0440);
               body.emit(assign(r0400, expr(ir_triop_csel, r043C, r0400, r0441), 0x01));

               body.emit(assign(r0401, r0417, 0x01));

               body.emit(assign(r0402, r042C, 0x01));


            body.instructions = f040E_parent_instructions;
            body.emit(f040E);

            /* END IF */

            body.emit(assign(r03FF, sub(r03FF, r0403), 0x01));

            ir_variable *const r0442 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0442, r03FF, 0x01));

            ir_variable *const r0443 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0443, r0400, 0x01));

            ir_variable *const r0444 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0444, r0401, 0x01));

            ir_variable *const r0445 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0445, r0402, 0x01));

            ir_variable *const r0446 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0446, body.constant(true), 0x01));

            ir_variable *const r0447 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0448 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0448);
            ir_expression *const r0449 = expr(ir_unop_u2i, r0402);
            body.emit(assign(r0448, less(r0449, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r044B = gequal(r03FF, body.constant(int(2045)));
            ir_if *f044A = new(mem_ctx) ir_if(operand(r044B).val);
            exec_list *const f044A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f044A->then_instructions;

               /* IF CONDITION */
               ir_expression *const r044D = less(body.constant(int(2045)), r03FF);
               ir_expression *const r044E = equal(r03FF, body.constant(int(2045)));
               ir_expression *const r044F = equal(body.constant(2097151u), r0400);
               ir_expression *const r0450 = equal(body.constant(4294967295u), r0401);
               ir_expression *const r0451 = logic_and(r044F, r0450);
               ir_expression *const r0452 = logic_and(r044E, r0451);
               ir_expression *const r0453 = logic_and(r0452, r0448);
               ir_expression *const r0454 = logic_or(r044D, r0453);
               ir_if *f044C = new(mem_ctx) ir_if(operand(r0454).val);
               exec_list *const f044C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f044C->then_instructions;

                  ir_variable *const r0455 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0455);
                  ir_expression *const r0456 = lshift(r021A, body.constant(int(31)));
                  body.emit(assign(r0455, add(r0456, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0455, body.constant(0u), 0x01));

                  body.emit(assign(r0447, r0455, 0x03));

                  body.emit(assign(r0446, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f044C->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0458 = less(r03FF, body.constant(int(0)));
                  ir_if *f0457 = new(mem_ctx) ir_if(operand(r0458).val);
                  exec_list *const f0457_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0457->then_instructions;

                     ir_variable *const r0459 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0459, neg(r03FF), 0x01));

                     ir_variable *const r045A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r045A);
                     ir_variable *const r045B = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r045C = neg(r0459);
                     body.emit(assign(r045B, bit_and(r045C, body.constant(int(31))), 0x01));

                     ir_variable *const r045D = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r045E = less(r0459, body.constant(int(32)));
                     ir_expression *const r045F = bit_or(r0402, r0401);
                     body.emit(assign(r045D, expr(ir_triop_csel, r045E, r0402, r045F), 0x01));

                     ir_expression *const r0460 = less(r0459, body.constant(int(32)));
                     ir_expression *const r0461 = lshift(r0401, r045B);
                     ir_expression *const r0462 = less(r0459, body.constant(int(64)));
                     ir_expression *const r0463 = lshift(r0400, r045B);
                     ir_expression *const r0464 = equal(r0459, body.constant(int(64)));
                     ir_expression *const r0465 = nequal(r0400, body.constant(0u));
                     ir_expression *const r0466 = expr(ir_unop_b2i, r0465);
                     ir_expression *const r0467 = expr(ir_unop_i2u, r0466);
                     ir_expression *const r0468 = expr(ir_triop_csel, r0464, r0400, r0467);
                     ir_expression *const r0469 = expr(ir_triop_csel, r0462, r0463, r0468);
                     ir_expression *const r046A = expr(ir_triop_csel, r0460, r0461, r0469);
                     ir_expression *const r046B = nequal(r045D, body.constant(0u));
                     ir_expression *const r046C = expr(ir_unop_b2i, r046B);
                     ir_expression *const r046D = expr(ir_unop_i2u, r046C);
                     body.emit(assign(r045A, bit_or(r046A, r046D), 0x01));

                     ir_variable *const r046E = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r046F = equal(r0459, body.constant(int(0)));
                     ir_expression *const r0470 = equal(r0459, body.constant(int(32)));
                     ir_expression *const r0471 = expr(ir_triop_csel, r0470, r0401, r045A);
                     body.emit(assign(r046E, expr(ir_triop_csel, r046F, r045D, r0471), 0x01));

                     body.emit(assign(r045A, r046E, 0x01));

                     ir_expression *const r0472 = equal(r0459, body.constant(int(0)));
                     ir_expression *const r0473 = equal(r0459, body.constant(int(32)));
                     ir_expression *const r0474 = less(r0459, body.constant(int(32)));
                     ir_expression *const r0475 = rshift(r0400, r0459);
                     ir_expression *const r0476 = expr(ir_triop_csel, r0474, r0475, body.constant(0u));
                     ir_expression *const r0477 = expr(ir_triop_csel, r0473, body.constant(0u), r0476);
                     body.emit(assign(r0443, expr(ir_triop_csel, r0472, r0400, r0477), 0x01));

                     ir_expression *const r0478 = equal(r0459, body.constant(int(0)));
                     ir_expression *const r0479 = equal(r0459, body.constant(int(32)));
                     ir_expression *const r047A = less(r0459, body.constant(int(32)));
                     ir_expression *const r047B = lshift(r0400, r045B);
                     ir_expression *const r047C = rshift(r0401, r0459);
                     ir_expression *const r047D = bit_or(r047B, r047C);
                     ir_expression *const r047E = less(r0459, body.constant(int(64)));
                     ir_expression *const r047F = bit_and(r0459, body.constant(int(31)));
                     ir_expression *const r0480 = rshift(r0400, r047F);
                     ir_expression *const r0481 = expr(ir_triop_csel, r047E, r0480, body.constant(0u));
                     ir_expression *const r0482 = expr(ir_triop_csel, r047A, r047D, r0481);
                     ir_expression *const r0483 = expr(ir_triop_csel, r0479, r0400, r0482);
                     body.emit(assign(r0444, expr(ir_triop_csel, r0478, r0401, r0483), 0x01));

                     body.emit(assign(r0445, r046E, 0x01));

                     body.emit(assign(r0442, body.constant(int(0)), 0x01));

                     body.emit(assign(r0448, less(r046E, body.constant(0u)), 0x01));


                  body.instructions = f0457_parent_instructions;
                  body.emit(f0457);

                  /* END IF */


               body.instructions = f044C_parent_instructions;
               body.emit(f044C);

               /* END IF */


            body.instructions = f044A_parent_instructions;
            body.emit(f044A);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0484 = new(mem_ctx) ir_if(operand(r0446).val);
            exec_list *const f0484_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0484->then_instructions;

               /* IF CONDITION */
               ir_if *f0485 = new(mem_ctx) ir_if(operand(r0448).val);
               exec_list *const f0485_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0485->then_instructions;

                  ir_variable *const r0486 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0486, add(r0444, body.constant(1u)), 0x01));

                  ir_expression *const r0487 = less(r0486, r0444);
                  ir_expression *const r0488 = expr(ir_unop_b2i, r0487);
                  ir_expression *const r0489 = expr(ir_unop_i2u, r0488);
                  body.emit(assign(r0443, add(r0443, r0489), 0x01));

                  ir_expression *const r048A = equal(r0445, body.constant(0u));
                  ir_expression *const r048B = expr(ir_unop_b2i, r048A);
                  ir_expression *const r048C = expr(ir_unop_i2u, r048B);
                  ir_expression *const r048D = add(r0445, r048C);
                  ir_expression *const r048E = bit_and(r048D, body.constant(1u));
                  ir_expression *const r048F = expr(ir_unop_bit_not, r048E);
                  body.emit(assign(r0444, bit_and(r0486, r048F), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0485->else_instructions;

                  ir_expression *const r0490 = bit_or(r0443, r0444);
                  ir_expression *const r0491 = equal(r0490, body.constant(0u));
                  body.emit(assign(r0442, expr(ir_triop_csel, r0491, body.constant(int(0)), r0442), 0x01));


               body.instructions = f0485_parent_instructions;
               body.emit(f0485);

               /* END IF */

               ir_variable *const r0492 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0492);
               ir_expression *const r0493 = lshift(r021A, body.constant(int(31)));
               ir_expression *const r0494 = expr(ir_unop_i2u, r0442);
               ir_expression *const r0495 = lshift(r0494, body.constant(int(20)));
               ir_expression *const r0496 = add(r0493, r0495);
               body.emit(assign(r0492, add(r0496, r0443), 0x02));

               body.emit(assign(r0492, r0444, 0x01));

               body.emit(assign(r0447, r0492, 0x03));

               body.emit(assign(r0446, body.constant(false), 0x01));


            body.instructions = f0484_parent_instructions;
            body.emit(f0484);

            /* END IF */

            body.emit(assign(r020F, r0447, 0x03));

            body.emit(assign(r020E, body.constant(false), 0x01));


         body.instructions = f03B3_parent_instructions;
         body.emit(f03B3);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f03B1->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0498 = less(r0210, body.constant(int(0)));
         ir_if *f0497 = new(mem_ctx) ir_if(operand(r0498).val);
         exec_list *const f0497_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0497->then_instructions;

            /* IF CONDITION */
            ir_expression *const r049A = equal(r0221, body.constant(int(2047)));
            ir_if *f0499 = new(mem_ctx) ir_if(operand(r049A).val);
            exec_list *const f0499_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0499->then_instructions;

               ir_variable *const r049B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r049B);
               ir_expression *const r049C = bit_xor(r021A, body.constant(1u));
               ir_expression *const r049D = lshift(r049C, body.constant(int(31)));
               body.emit(assign(r049B, add(r049D, body.constant(2146435072u)), 0x02));

               body.emit(assign(r049B, body.constant(0u), 0x01));

               ir_variable *const r049E = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r049E, swizzle_x(r020C), 0x01));

               ir_variable *const r049F = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r049F, swizzle_x(r020D), 0x01));

               body.emit(assign(r049E, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r049F, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r04A0 = bit_or(r0215, r0216);
               ir_expression *const r04A1 = nequal(r04A0, body.constant(0u));
               ir_swizzle *const r04A2 = swizzle(r04A1, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r04A3 = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r04A4 = gequal(r04A3, body.constant(4292870144u));
               ir_expression *const r04A5 = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r04A6 = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r04A7 = nequal(r04A6, body.constant(0u));
               ir_expression *const r04A8 = logic_or(r04A5, r04A7);
               ir_expression *const r04A9 = logic_and(r04A4, r04A8);
               ir_swizzle *const r04AA = swizzle(r04A9, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r04AB = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r04AC = gequal(r04AB, body.constant(4292870144u));
               ir_expression *const r04AD = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r04AE = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r04AF = nequal(r04AE, body.constant(0u));
               ir_expression *const r04B0 = logic_or(r04AD, r04AF);
               ir_expression *const r04B1 = logic_and(r04AC, r04B0);
               ir_swizzle *const r04B2 = swizzle(r04B1, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r04B3 = expr(ir_triop_csel, r04B2, r049F, r049E);
               ir_expression *const r04B4 = expr(ir_triop_csel, r04AA, r04B3, r049F);
               body.emit(assign(r020F, expr(ir_triop_csel, r04A2, r04B4, r049B), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0499->else_instructions;

               ir_variable *const r04B5 = body.make_temp(glsl_type::int_type, "mix_retval");
               ir_expression *const r04B6 = equal(r021E, body.constant(int(0)));
               ir_expression *const r04B7 = add(r0210, body.constant(int(1)));
               body.emit(assign(r04B5, expr(ir_triop_csel, r04B6, r04B7, r0210), 0x01));

               body.emit(assign(r0210, r04B5, 0x01));

               ir_variable *const r04B8 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04B9 = equal(r021E, body.constant(int(0)));
               ir_expression *const r04BA = bit_or(r0217, body.constant(1073741824u));
               body.emit(assign(r04B8, expr(ir_triop_csel, r04B9, r0217, r04BA), 0x01));

               ir_variable *const r04BB = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r04BB, neg(r04B5), 0x01));

               ir_variable *const r04BC = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r04BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r04BD);
               ir_variable *const r04BE = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r04BF = neg(r04BB);
               body.emit(assign(r04BE, bit_and(r04BF, body.constant(int(31))), 0x01));

               ir_expression *const r04C0 = bit_or(r04B8, r03AA);
               ir_expression *const r04C1 = nequal(r04C0, body.constant(0u));
               ir_expression *const r04C2 = expr(ir_unop_b2i, r04C1);
               body.emit(assign(r04BD, expr(ir_unop_i2u, r04C2), 0x01));

               ir_variable *const r04C3 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04C4 = equal(r04BB, body.constant(int(0)));
               ir_expression *const r04C5 = less(r04BB, body.constant(int(32)));
               ir_expression *const r04C6 = lshift(r04B8, r04BE);
               ir_expression *const r04C7 = rshift(r03AA, r04BB);
               ir_expression *const r04C8 = bit_or(r04C6, r04C7);
               ir_expression *const r04C9 = lshift(r03AA, r04BE);
               ir_expression *const r04CA = nequal(r04C9, body.constant(0u));
               ir_expression *const r04CB = expr(ir_unop_b2i, r04CA);
               ir_expression *const r04CC = expr(ir_unop_i2u, r04CB);
               ir_expression *const r04CD = bit_or(r04C8, r04CC);
               ir_expression *const r04CE = equal(r04BB, body.constant(int(32)));
               ir_expression *const r04CF = nequal(r03AA, body.constant(0u));
               ir_expression *const r04D0 = expr(ir_unop_b2i, r04CF);
               ir_expression *const r04D1 = expr(ir_unop_i2u, r04D0);
               ir_expression *const r04D2 = bit_or(r04B8, r04D1);
               ir_expression *const r04D3 = less(r04BB, body.constant(int(64)));
               ir_expression *const r04D4 = bit_and(r04BB, body.constant(int(31)));
               ir_expression *const r04D5 = rshift(r04B8, r04D4);
               ir_expression *const r04D6 = lshift(r04B8, r04BE);
               ir_expression *const r04D7 = bit_or(r04D6, r03AA);
               ir_expression *const r04D8 = nequal(r04D7, body.constant(0u));
               ir_expression *const r04D9 = expr(ir_unop_b2i, r04D8);
               ir_expression *const r04DA = expr(ir_unop_i2u, r04D9);
               ir_expression *const r04DB = bit_or(r04D5, r04DA);
               ir_expression *const r04DC = expr(ir_triop_csel, r04D3, r04DB, r04BD);
               ir_expression *const r04DD = expr(ir_triop_csel, r04CE, r04D2, r04DC);
               ir_expression *const r04DE = expr(ir_triop_csel, r04C5, r04CD, r04DD);
               body.emit(assign(r04C3, expr(ir_triop_csel, r04C4, r03AA, r04DE), 0x01));

               body.emit(assign(r04BD, r04C3, 0x01));

               ir_expression *const r04DF = less(r04BB, body.constant(int(32)));
               ir_expression *const r04E0 = rshift(r04B8, r04BB);
               ir_expression *const r04E1 = equal(r04BB, body.constant(int(0)));
               ir_expression *const r04E2 = expr(ir_triop_csel, r04E1, r04B8, body.constant(0u));
               body.emit(assign(r04BC, expr(ir_triop_csel, r04DF, r04E0, r04E2), 0x01));

               body.emit(assign(r0217, r04BC, 0x01));

               body.emit(assign(r0218, r04C3, 0x01));

               body.emit(assign(r0215, bit_or(r0215, body.constant(1073741824u)), 0x01));

               ir_variable *const r04E3 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r04E4 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r04E4, sub(r0216, r04C3), 0x01));

               ir_expression *const r04E5 = sub(r0215, r04BC);
               ir_expression *const r04E6 = less(r0216, r04C3);
               ir_expression *const r04E7 = expr(ir_unop_b2i, r04E6);
               ir_expression *const r04E8 = expr(ir_unop_i2u, r04E7);
               body.emit(assign(r04E3, sub(r04E5, r04E8), 0x01));

               body.emit(assign(r0212, r04E3, 0x01));

               body.emit(assign(r0211, r04E4, 0x01));

               body.emit(assign(r0219, bit_xor(r021A, body.constant(1u)), 0x01));

               body.emit(assign(r03A8, add(r0221, body.constant(int(-1))), 0x01));

               ir_variable *const r04E9 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04E9, add(r03A8, body.constant(int(-10))), 0x01));

               ir_variable *const r04EA = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r04EB = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r04EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r04EC);
               ir_variable *const r04ED = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04ED);
               ir_expression *const r04EE = equal(r04E3, body.constant(0u));
               ir_expression *const r04EF = add(r04E9, body.constant(int(-32)));
               body.emit(assign(r04E9, expr(ir_triop_csel, r04EE, r04EF, r04E9), 0x01));

               ir_variable *const r04F0 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04F1 = equal(r04E3, body.constant(0u));
               body.emit(assign(r04F0, expr(ir_triop_csel, r04F1, body.constant(0u), r04E4), 0x01));

               body.emit(assign(r04EB, r04F0, 0x01));

               ir_variable *const r04F2 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04F3 = equal(r04E3, body.constant(0u));
               body.emit(assign(r04F2, expr(ir_triop_csel, r04F3, r04F0, r04E3), 0x01));

               body.emit(assign(r04EA, r04F2, 0x01));

               ir_expression *const r04F4 = equal(r04F2, body.constant(0u));
               ir_expression *const r04F5 = expr(ir_unop_find_msb, r04F2);
               ir_expression *const r04F6 = sub(body.constant(int(31)), r04F5);
               ir_expression *const r04F7 = expr(ir_triop_csel, r04F4, body.constant(int(32)), r04F6);
               body.emit(assign(r04ED, add(r04F7, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04F9 = gequal(r04ED, body.constant(int(0)));
               ir_if *f04F8 = new(mem_ctx) ir_if(operand(r04F9).val);
               exec_list *const f04F8_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04F8->then_instructions;

                  body.emit(assign(r04EC, body.constant(0u), 0x01));

                  ir_expression *const r04FA = equal(r04ED, body.constant(int(0)));
                  ir_expression *const r04FB = lshift(r04F2, r04ED);
                  ir_expression *const r04FC = neg(r04ED);
                  ir_expression *const r04FD = bit_and(r04FC, body.constant(int(31)));
                  ir_expression *const r04FE = rshift(r04F0, r04FD);
                  ir_expression *const r04FF = bit_or(r04FB, r04FE);
                  body.emit(assign(r04EA, expr(ir_triop_csel, r04FA, r04F2, r04FF), 0x01));

                  body.emit(assign(r04EB, lshift(r04F0, r04ED), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04F8->else_instructions;

                  ir_variable *const r0500 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r0500, neg(r04ED), 0x01));

                  ir_variable *const r0501 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  ir_variable *const r0502 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0502);
                  ir_variable *const r0503 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r0504 = neg(r0500);
                  body.emit(assign(r0503, bit_and(r0504, body.constant(int(31))), 0x01));

                  ir_variable *const r0505 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0506 = less(r0500, body.constant(int(32)));
                  ir_expression *const r0507 = bit_or(body.constant(0u), r04EB);
                  body.emit(assign(r0505, expr(ir_triop_csel, r0506, body.constant(0u), r0507), 0x01));

                  ir_expression *const r0508 = less(r0500, body.constant(int(32)));
                  ir_expression *const r0509 = lshift(r04EB, r0503);
                  ir_expression *const r050A = less(r0500, body.constant(int(64)));
                  ir_expression *const r050B = lshift(r04EA, r0503);
                  ir_expression *const r050C = equal(r0500, body.constant(int(64)));
                  ir_expression *const r050D = nequal(r04EA, body.constant(0u));
                  ir_expression *const r050E = expr(ir_unop_b2i, r050D);
                  ir_expression *const r050F = expr(ir_unop_i2u, r050E);
                  ir_expression *const r0510 = expr(ir_triop_csel, r050C, r04EA, r050F);
                  ir_expression *const r0511 = expr(ir_triop_csel, r050A, r050B, r0510);
                  ir_expression *const r0512 = expr(ir_triop_csel, r0508, r0509, r0511);
                  ir_expression *const r0513 = nequal(r0505, body.constant(0u));
                  ir_expression *const r0514 = expr(ir_unop_b2i, r0513);
                  ir_expression *const r0515 = expr(ir_unop_i2u, r0514);
                  body.emit(assign(r0502, bit_or(r0512, r0515), 0x01));

                  ir_variable *const r0516 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0517 = equal(r0500, body.constant(int(0)));
                  ir_expression *const r0518 = equal(r0500, body.constant(int(32)));
                  ir_expression *const r0519 = expr(ir_triop_csel, r0518, r04EB, r0502);
                  body.emit(assign(r0516, expr(ir_triop_csel, r0517, r0505, r0519), 0x01));

                  body.emit(assign(r0502, r0516, 0x01));

                  ir_expression *const r051A = equal(r0500, body.constant(int(0)));
                  ir_expression *const r051B = equal(r0500, body.constant(int(32)));
                  ir_expression *const r051C = less(r0500, body.constant(int(32)));
                  ir_expression *const r051D = lshift(r04EA, r0503);
                  ir_expression *const r051E = rshift(r04EB, r0500);
                  ir_expression *const r051F = bit_or(r051D, r051E);
                  ir_expression *const r0520 = less(r0500, body.constant(int(64)));
                  ir_expression *const r0521 = bit_and(r0500, body.constant(int(31)));
                  ir_expression *const r0522 = rshift(r04EA, r0521);
                  ir_expression *const r0523 = expr(ir_triop_csel, r0520, r0522, body.constant(0u));
                  ir_expression *const r0524 = expr(ir_triop_csel, r051C, r051F, r0523);
                  ir_expression *const r0525 = expr(ir_triop_csel, r051B, r04EA, r0524);
                  body.emit(assign(r0501, expr(ir_triop_csel, r051A, r04EB, r0525), 0x01));

                  ir_expression *const r0526 = equal(r0500, body.constant(int(0)));
                  ir_expression *const r0527 = equal(r0500, body.constant(int(32)));
                  ir_expression *const r0528 = less(r0500, body.constant(int(32)));
                  ir_expression *const r0529 = rshift(r04EA, r0500);
                  ir_expression *const r052A = expr(ir_triop_csel, r0528, r0529, body.constant(0u));
                  ir_expression *const r052B = expr(ir_triop_csel, r0527, body.constant(0u), r052A);
                  body.emit(assign(r04EA, expr(ir_triop_csel, r0526, r04EA, r052B), 0x01));

                  body.emit(assign(r04EB, r0501, 0x01));

                  body.emit(assign(r04EC, r0516, 0x01));


               body.instructions = f04F8_parent_instructions;
               body.emit(f04F8);

               /* END IF */

               body.emit(assign(r04E9, sub(r04E9, r04ED), 0x01));

               ir_variable *const r052C = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r052C, r04E9, 0x01));

               ir_variable *const r052D = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r052D, r04EA, 0x01));

               ir_variable *const r052E = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r052E, r04EB, 0x01));

               ir_variable *const r052F = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r052F, r04EC, 0x01));

               ir_variable *const r0530 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0530, body.constant(true), 0x01));

               ir_variable *const r0531 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0532 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0532);
               ir_expression *const r0533 = expr(ir_unop_u2i, r04EC);
               body.emit(assign(r0532, less(r0533, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0535 = gequal(r04E9, body.constant(int(2045)));
               ir_if *f0534 = new(mem_ctx) ir_if(operand(r0535).val);
               exec_list *const f0534_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0534->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0537 = less(body.constant(int(2045)), r04E9);
                  ir_expression *const r0538 = equal(r04E9, body.constant(int(2045)));
                  ir_expression *const r0539 = equal(body.constant(2097151u), r04EA);
                  ir_expression *const r053A = equal(body.constant(4294967295u), r04EB);
                  ir_expression *const r053B = logic_and(r0539, r053A);
                  ir_expression *const r053C = logic_and(r0538, r053B);
                  ir_expression *const r053D = logic_and(r053C, r0532);
                  ir_expression *const r053E = logic_or(r0537, r053D);
                  ir_if *f0536 = new(mem_ctx) ir_if(operand(r053E).val);
                  exec_list *const f0536_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0536->then_instructions;

                     ir_variable *const r053F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r053F);
                     ir_expression *const r0540 = lshift(r0219, body.constant(int(31)));
                     body.emit(assign(r053F, add(r0540, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r053F, body.constant(0u), 0x01));

                     body.emit(assign(r0531, r053F, 0x03));

                     body.emit(assign(r0530, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0536->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0542 = less(r04E9, body.constant(int(0)));
                     ir_if *f0541 = new(mem_ctx) ir_if(operand(r0542).val);
                     exec_list *const f0541_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0541->then_instructions;

                        ir_variable *const r0543 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0543, neg(r04E9), 0x01));

                        ir_variable *const r0544 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0544);
                        ir_variable *const r0545 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0546 = neg(r0543);
                        body.emit(assign(r0545, bit_and(r0546, body.constant(int(31))), 0x01));

                        ir_variable *const r0547 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0548 = less(r0543, body.constant(int(32)));
                        ir_expression *const r0549 = bit_or(r04EC, r04EB);
                        body.emit(assign(r0547, expr(ir_triop_csel, r0548, r04EC, r0549), 0x01));

                        ir_expression *const r054A = less(r0543, body.constant(int(32)));
                        ir_expression *const r054B = lshift(r04EB, r0545);
                        ir_expression *const r054C = less(r0543, body.constant(int(64)));
                        ir_expression *const r054D = lshift(r04EA, r0545);
                        ir_expression *const r054E = equal(r0543, body.constant(int(64)));
                        ir_expression *const r054F = nequal(r04EA, body.constant(0u));
                        ir_expression *const r0550 = expr(ir_unop_b2i, r054F);
                        ir_expression *const r0551 = expr(ir_unop_i2u, r0550);
                        ir_expression *const r0552 = expr(ir_triop_csel, r054E, r04EA, r0551);
                        ir_expression *const r0553 = expr(ir_triop_csel, r054C, r054D, r0552);
                        ir_expression *const r0554 = expr(ir_triop_csel, r054A, r054B, r0553);
                        ir_expression *const r0555 = nequal(r0547, body.constant(0u));
                        ir_expression *const r0556 = expr(ir_unop_b2i, r0555);
                        ir_expression *const r0557 = expr(ir_unop_i2u, r0556);
                        body.emit(assign(r0544, bit_or(r0554, r0557), 0x01));

                        ir_variable *const r0558 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0559 = equal(r0543, body.constant(int(0)));
                        ir_expression *const r055A = equal(r0543, body.constant(int(32)));
                        ir_expression *const r055B = expr(ir_triop_csel, r055A, r04EB, r0544);
                        body.emit(assign(r0558, expr(ir_triop_csel, r0559, r0547, r055B), 0x01));

                        body.emit(assign(r0544, r0558, 0x01));

                        ir_expression *const r055C = equal(r0543, body.constant(int(0)));
                        ir_expression *const r055D = equal(r0543, body.constant(int(32)));
                        ir_expression *const r055E = less(r0543, body.constant(int(32)));
                        ir_expression *const r055F = rshift(r04EA, r0543);
                        ir_expression *const r0560 = expr(ir_triop_csel, r055E, r055F, body.constant(0u));
                        ir_expression *const r0561 = expr(ir_triop_csel, r055D, body.constant(0u), r0560);
                        body.emit(assign(r052D, expr(ir_triop_csel, r055C, r04EA, r0561), 0x01));

                        ir_expression *const r0562 = equal(r0543, body.constant(int(0)));
                        ir_expression *const r0563 = equal(r0543, body.constant(int(32)));
                        ir_expression *const r0564 = less(r0543, body.constant(int(32)));
                        ir_expression *const r0565 = lshift(r04EA, r0545);
                        ir_expression *const r0566 = rshift(r04EB, r0543);
                        ir_expression *const r0567 = bit_or(r0565, r0566);
                        ir_expression *const r0568 = less(r0543, body.constant(int(64)));
                        ir_expression *const r0569 = bit_and(r0543, body.constant(int(31)));
                        ir_expression *const r056A = rshift(r04EA, r0569);
                        ir_expression *const r056B = expr(ir_triop_csel, r0568, r056A, body.constant(0u));
                        ir_expression *const r056C = expr(ir_triop_csel, r0564, r0567, r056B);
                        ir_expression *const r056D = expr(ir_triop_csel, r0563, r04EA, r056C);
                        body.emit(assign(r052E, expr(ir_triop_csel, r0562, r04EB, r056D), 0x01));

                        body.emit(assign(r052F, r0558, 0x01));

                        body.emit(assign(r052C, body.constant(int(0)), 0x01));

                        body.emit(assign(r0532, less(r0558, body.constant(0u)), 0x01));


                     body.instructions = f0541_parent_instructions;
                     body.emit(f0541);

                     /* END IF */


                  body.instructions = f0536_parent_instructions;
                  body.emit(f0536);

                  /* END IF */


               body.instructions = f0534_parent_instructions;
               body.emit(f0534);

               /* END IF */

               /* IF CONDITION */
               ir_if *f056E = new(mem_ctx) ir_if(operand(r0530).val);
               exec_list *const f056E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f056E->then_instructions;

                  /* IF CONDITION */
                  ir_if *f056F = new(mem_ctx) ir_if(operand(r0532).val);
                  exec_list *const f056F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f056F->then_instructions;

                     ir_variable *const r0570 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0570, add(r052E, body.constant(1u)), 0x01));

                     ir_expression *const r0571 = less(r0570, r052E);
                     ir_expression *const r0572 = expr(ir_unop_b2i, r0571);
                     ir_expression *const r0573 = expr(ir_unop_i2u, r0572);
                     body.emit(assign(r052D, add(r052D, r0573), 0x01));

                     ir_expression *const r0574 = equal(r052F, body.constant(0u));
                     ir_expression *const r0575 = expr(ir_unop_b2i, r0574);
                     ir_expression *const r0576 = expr(ir_unop_i2u, r0575);
                     ir_expression *const r0577 = add(r052F, r0576);
                     ir_expression *const r0578 = bit_and(r0577, body.constant(1u));
                     ir_expression *const r0579 = expr(ir_unop_bit_not, r0578);
                     body.emit(assign(r052E, bit_and(r0570, r0579), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f056F->else_instructions;

                     ir_expression *const r057A = bit_or(r052D, r052E);
                     ir_expression *const r057B = equal(r057A, body.constant(0u));
                     body.emit(assign(r052C, expr(ir_triop_csel, r057B, body.constant(int(0)), r052C), 0x01));


                  body.instructions = f056F_parent_instructions;
                  body.emit(f056F);

                  /* END IF */

                  ir_variable *const r057C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r057C);
                  ir_expression *const r057D = lshift(r0219, body.constant(int(31)));
                  ir_expression *const r057E = expr(ir_unop_i2u, r052C);
                  ir_expression *const r057F = lshift(r057E, body.constant(int(20)));
                  ir_expression *const r0580 = add(r057D, r057F);
                  body.emit(assign(r057C, add(r0580, r052D), 0x02));

                  body.emit(assign(r057C, r052E, 0x01));

                  body.emit(assign(r0531, r057C, 0x03));

                  body.emit(assign(r0530, body.constant(false), 0x01));


               body.instructions = f056E_parent_instructions;
               body.emit(f056E);

               /* END IF */

               body.emit(assign(r020F, r0531, 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


            body.instructions = f0499_parent_instructions;
            body.emit(f0499);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0497->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0582 = equal(r021E, body.constant(int(2047)));
            ir_if *f0581 = new(mem_ctx) ir_if(operand(r0582).val);
            exec_list *const f0581_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0581->then_instructions;

               ir_variable *const r0583 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0583, swizzle_x(r020C), 0x01));

               ir_variable *const r0584 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0584, swizzle_x(r020D), 0x01));

               body.emit(assign(r0583, bit_or(swizzle_y(r020C), body.constant(524288u)), 0x02));

               body.emit(assign(r0584, bit_or(swizzle_y(r020D), body.constant(524288u)), 0x02));

               ir_expression *const r0585 = bit_or(r0217, r0218);
               ir_expression *const r0586 = bit_or(r0215, r0216);
               ir_expression *const r0587 = bit_or(r0585, r0586);
               ir_expression *const r0588 = nequal(r0587, body.constant(0u));
               ir_swizzle *const r0589 = swizzle(r0588, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r058A = lshift(swizzle_y(r020C), body.constant(int(1)));
               ir_expression *const r058B = gequal(r058A, body.constant(4292870144u));
               ir_expression *const r058C = nequal(swizzle_x(r020C), body.constant(0u));
               ir_expression *const r058D = bit_and(swizzle_y(r020C), body.constant(1048575u));
               ir_expression *const r058E = nequal(r058D, body.constant(0u));
               ir_expression *const r058F = logic_or(r058C, r058E);
               ir_expression *const r0590 = logic_and(r058B, r058F);
               ir_swizzle *const r0591 = swizzle(r0590, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0592 = lshift(swizzle_y(r020D), body.constant(int(1)));
               ir_expression *const r0593 = gequal(r0592, body.constant(4292870144u));
               ir_expression *const r0594 = nequal(swizzle_x(r020D), body.constant(0u));
               ir_expression *const r0595 = bit_and(swizzle_y(r020D), body.constant(1048575u));
               ir_expression *const r0596 = nequal(r0595, body.constant(0u));
               ir_expression *const r0597 = logic_or(r0594, r0596);
               ir_expression *const r0598 = logic_and(r0593, r0597);
               ir_swizzle *const r0599 = swizzle(r0598, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r059A = expr(ir_triop_csel, r0599, r0584, r0583);
               ir_expression *const r059B = expr(ir_triop_csel, r0591, r059A, r0584);
               ir_constant_data r059C_data;
               memset(&r059C_data, 0, sizeof(ir_constant_data));
               r059C_data.u[0] = 4294967295;
               r059C_data.u[1] = 4294967295;
               ir_constant *const r059C = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r059C_data);
               body.emit(assign(r020F, expr(ir_triop_csel, r0589, r059B, r059C), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0581->else_instructions;

               ir_expression *const r059D = equal(r021E, body.constant(int(0)));
               body.emit(assign(r0213, expr(ir_triop_csel, r059D, body.constant(int(1)), r0221), 0x01));

               ir_expression *const r059E = equal(r021E, body.constant(int(0)));
               body.emit(assign(r0214, expr(ir_triop_csel, r059E, body.constant(int(1)), r021E), 0x01));

               body.emit(assign(r03A7, body.constant(false), 0x01));

               body.emit(assign(r03A6, body.constant(true), 0x01));

               /* IF CONDITION */
               ir_expression *const r05A0 = less(r0215, r0217);
               ir_if *f059F = new(mem_ctx) ir_if(operand(r05A0).val);
               exec_list *const f059F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f059F->then_instructions;

                  ir_expression *const r05A1 = sub(r0217, r0215);
                  ir_expression *const r05A2 = less(r0218, r0216);
                  ir_expression *const r05A3 = expr(ir_unop_b2i, r05A2);
                  ir_expression *const r05A4 = expr(ir_unop_i2u, r05A3);
                  body.emit(assign(r0212, sub(r05A1, r05A4), 0x01));

                  body.emit(assign(r0211, sub(r0218, r0216), 0x01));

                  body.emit(assign(r03A7, body.constant(true), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f059F->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05A6 = less(r0217, r0215);
                  ir_if *f05A5 = new(mem_ctx) ir_if(operand(r05A6).val);
                  exec_list *const f05A5_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05A5->then_instructions;

                     ir_expression *const r05A7 = sub(r0215, r0217);
                     ir_expression *const r05A8 = less(r0216, r0218);
                     ir_expression *const r05A9 = expr(ir_unop_b2i, r05A8);
                     ir_expression *const r05AA = expr(ir_unop_i2u, r05A9);
                     body.emit(assign(r0212, sub(r05A7, r05AA), 0x01));

                     body.emit(assign(r0211, sub(r0216, r0218), 0x01));

                     body.emit(assign(r03A6, body.constant(false), 0x01));

                     body.emit(assign(r03A7, body.constant(true), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05A5->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r05AC = less(r0216, r0218);
                     ir_if *f05AB = new(mem_ctx) ir_if(operand(r05AC).val);
                     exec_list *const f05AB_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05AB->then_instructions;

                        ir_expression *const r05AD = sub(r0217, r0215);
                        ir_expression *const r05AE = less(r0218, r0216);
                        ir_expression *const r05AF = expr(ir_unop_b2i, r05AE);
                        ir_expression *const r05B0 = expr(ir_unop_i2u, r05AF);
                        body.emit(assign(r0212, sub(r05AD, r05B0), 0x01));

                        body.emit(assign(r0211, sub(r0218, r0216), 0x01));

                        body.emit(assign(r03A7, body.constant(true), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05AB->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05B2 = less(r0218, r0216);
                        ir_if *f05B1 = new(mem_ctx) ir_if(operand(r05B2).val);
                        exec_list *const f05B1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05B1->then_instructions;

                           ir_expression *const r05B3 = sub(r0215, r0217);
                           ir_expression *const r05B4 = less(r0216, r0218);
                           ir_expression *const r05B5 = expr(ir_unop_b2i, r05B4);
                           ir_expression *const r05B6 = expr(ir_unop_i2u, r05B5);
                           body.emit(assign(r0212, sub(r05B3, r05B6), 0x01));

                           body.emit(assign(r0211, sub(r0216, r0218), 0x01));

                           body.emit(assign(r03A6, body.constant(false), 0x01));

                           body.emit(assign(r03A7, body.constant(true), 0x01));


                        body.instructions = f05B1_parent_instructions;
                        body.emit(f05B1);

                        /* END IF */


                     body.instructions = f05AB_parent_instructions;
                     body.emit(f05AB);

                     /* END IF */


                  body.instructions = f05A5_parent_instructions;
                  body.emit(f05A5);

                  /* END IF */


               body.instructions = f059F_parent_instructions;
               body.emit(f059F);

               /* END IF */

               body.emit(assign(r03A8, expr(ir_triop_csel, r03A6, r0214, r0213), 0x01));

               ir_expression *const r05B7 = bit_xor(r0219, body.constant(1u));
               body.emit(assign(r0219, expr(ir_triop_csel, r03A6, r0219, r05B7), 0x01));

               ir_variable *const r05B8 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r05B8, add(r03A8, body.constant(int(-11))), 0x01));

               ir_variable *const r05B9 = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r05BA = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r05BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r05BB);
               ir_variable *const r05BC = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r05BC);
               ir_expression *const r05BD = equal(r0212, body.constant(0u));
               ir_expression *const r05BE = add(r05B8, body.constant(int(-32)));
               body.emit(assign(r05B8, expr(ir_triop_csel, r05BD, r05BE, r05B8), 0x01));

               ir_variable *const r05BF = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r05C0 = equal(r0212, body.constant(0u));
               body.emit(assign(r05BF, expr(ir_triop_csel, r05C0, body.constant(0u), r0211), 0x01));

               body.emit(assign(r05BA, r05BF, 0x01));

               ir_variable *const r05C1 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r05C2 = equal(r0212, body.constant(0u));
               body.emit(assign(r05C1, expr(ir_triop_csel, r05C2, r05BF, r0212), 0x01));

               body.emit(assign(r05B9, r05C1, 0x01));

               ir_expression *const r05C3 = equal(r05C1, body.constant(0u));
               ir_expression *const r05C4 = expr(ir_unop_find_msb, r05C1);
               ir_expression *const r05C5 = sub(body.constant(int(31)), r05C4);
               ir_expression *const r05C6 = expr(ir_triop_csel, r05C3, body.constant(int(32)), r05C5);
               body.emit(assign(r05BC, add(r05C6, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r05C8 = gequal(r05BC, body.constant(int(0)));
               ir_if *f05C7 = new(mem_ctx) ir_if(operand(r05C8).val);
               exec_list *const f05C7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f05C7->then_instructions;

                  body.emit(assign(r05BB, body.constant(0u), 0x01));

                  ir_expression *const r05C9 = equal(r05BC, body.constant(int(0)));
                  ir_expression *const r05CA = lshift(r05C1, r05BC);
                  ir_expression *const r05CB = neg(r05BC);
                  ir_expression *const r05CC = bit_and(r05CB, body.constant(int(31)));
                  ir_expression *const r05CD = rshift(r05BF, r05CC);
                  ir_expression *const r05CE = bit_or(r05CA, r05CD);
                  body.emit(assign(r05B9, expr(ir_triop_csel, r05C9, r05C1, r05CE), 0x01));

                  body.emit(assign(r05BA, lshift(r05BF, r05BC), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f05C7->else_instructions;

                  ir_variable *const r05CF = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r05CF, neg(r05BC), 0x01));

                  ir_variable *const r05D0 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  ir_variable *const r05D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r05D1);
                  ir_variable *const r05D2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r05D3 = neg(r05CF);
                  body.emit(assign(r05D2, bit_and(r05D3, body.constant(int(31))), 0x01));

                  ir_variable *const r05D4 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r05D5 = less(r05CF, body.constant(int(32)));
                  ir_expression *const r05D6 = bit_or(body.constant(0u), r05BA);
                  body.emit(assign(r05D4, expr(ir_triop_csel, r05D5, body.constant(0u), r05D6), 0x01));

                  ir_expression *const r05D7 = less(r05CF, body.constant(int(32)));
                  ir_expression *const r05D8 = lshift(r05BA, r05D2);
                  ir_expression *const r05D9 = less(r05CF, body.constant(int(64)));
                  ir_expression *const r05DA = lshift(r05B9, r05D2);
                  ir_expression *const r05DB = equal(r05CF, body.constant(int(64)));
                  ir_expression *const r05DC = nequal(r05B9, body.constant(0u));
                  ir_expression *const r05DD = expr(ir_unop_b2i, r05DC);
                  ir_expression *const r05DE = expr(ir_unop_i2u, r05DD);
                  ir_expression *const r05DF = expr(ir_triop_csel, r05DB, r05B9, r05DE);
                  ir_expression *const r05E0 = expr(ir_triop_csel, r05D9, r05DA, r05DF);
                  ir_expression *const r05E1 = expr(ir_triop_csel, r05D7, r05D8, r05E0);
                  ir_expression *const r05E2 = nequal(r05D4, body.constant(0u));
                  ir_expression *const r05E3 = expr(ir_unop_b2i, r05E2);
                  ir_expression *const r05E4 = expr(ir_unop_i2u, r05E3);
                  body.emit(assign(r05D1, bit_or(r05E1, r05E4), 0x01));

                  ir_variable *const r05E5 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r05E6 = equal(r05CF, body.constant(int(0)));
                  ir_expression *const r05E7 = equal(r05CF, body.constant(int(32)));
                  ir_expression *const r05E8 = expr(ir_triop_csel, r05E7, r05BA, r05D1);
                  body.emit(assign(r05E5, expr(ir_triop_csel, r05E6, r05D4, r05E8), 0x01));

                  body.emit(assign(r05D1, r05E5, 0x01));

                  ir_expression *const r05E9 = equal(r05CF, body.constant(int(0)));
                  ir_expression *const r05EA = equal(r05CF, body.constant(int(32)));
                  ir_expression *const r05EB = less(r05CF, body.constant(int(32)));
                  ir_expression *const r05EC = lshift(r05B9, r05D2);
                  ir_expression *const r05ED = rshift(r05BA, r05CF);
                  ir_expression *const r05EE = bit_or(r05EC, r05ED);
                  ir_expression *const r05EF = less(r05CF, body.constant(int(64)));
                  ir_expression *const r05F0 = bit_and(r05CF, body.constant(int(31)));
                  ir_expression *const r05F1 = rshift(r05B9, r05F0);
                  ir_expression *const r05F2 = expr(ir_triop_csel, r05EF, r05F1, body.constant(0u));
                  ir_expression *const r05F3 = expr(ir_triop_csel, r05EB, r05EE, r05F2);
                  ir_expression *const r05F4 = expr(ir_triop_csel, r05EA, r05B9, r05F3);
                  body.emit(assign(r05D0, expr(ir_triop_csel, r05E9, r05BA, r05F4), 0x01));

                  ir_expression *const r05F5 = equal(r05CF, body.constant(int(0)));
                  ir_expression *const r05F6 = equal(r05CF, body.constant(int(32)));
                  ir_expression *const r05F7 = less(r05CF, body.constant(int(32)));
                  ir_expression *const r05F8 = rshift(r05B9, r05CF);
                  ir_expression *const r05F9 = expr(ir_triop_csel, r05F7, r05F8, body.constant(0u));
                  ir_expression *const r05FA = expr(ir_triop_csel, r05F6, body.constant(0u), r05F9);
                  body.emit(assign(r05B9, expr(ir_triop_csel, r05F5, r05B9, r05FA), 0x01));

                  body.emit(assign(r05BA, r05D0, 0x01));

                  body.emit(assign(r05BB, r05E5, 0x01));


               body.instructions = f05C7_parent_instructions;
               body.emit(f05C7);

               /* END IF */

               body.emit(assign(r05B8, sub(r05B8, r05BC), 0x01));

               ir_variable *const r05FB = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r05FB, r05B8, 0x01));

               ir_variable *const r05FC = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r05FC, r05B9, 0x01));

               ir_variable *const r05FD = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r05FD, r05BA, 0x01));

               ir_variable *const r05FE = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r05FE, r05BB, 0x01));

               ir_variable *const r05FF = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r05FF, body.constant(true), 0x01));

               ir_variable *const r0600 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0601 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0601);
               ir_expression *const r0602 = expr(ir_unop_u2i, r05BB);
               body.emit(assign(r0601, less(r0602, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0604 = gequal(r05B8, body.constant(int(2045)));
               ir_if *f0603 = new(mem_ctx) ir_if(operand(r0604).val);
               exec_list *const f0603_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0603->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0606 = less(body.constant(int(2045)), r05B8);
                  ir_expression *const r0607 = equal(r05B8, body.constant(int(2045)));
                  ir_expression *const r0608 = equal(body.constant(2097151u), r05B9);
                  ir_expression *const r0609 = equal(body.constant(4294967295u), r05BA);
                  ir_expression *const r060A = logic_and(r0608, r0609);
                  ir_expression *const r060B = logic_and(r0607, r060A);
                  ir_expression *const r060C = logic_and(r060B, r0601);
                  ir_expression *const r060D = logic_or(r0606, r060C);
                  ir_if *f0605 = new(mem_ctx) ir_if(operand(r060D).val);
                  exec_list *const f0605_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0605->then_instructions;

                     ir_variable *const r060E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r060E);
                     ir_expression *const r060F = lshift(r0219, body.constant(int(31)));
                     body.emit(assign(r060E, add(r060F, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r060E, body.constant(0u), 0x01));

                     body.emit(assign(r0600, r060E, 0x03));

                     body.emit(assign(r05FF, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0605->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0611 = less(r05B8, body.constant(int(0)));
                     ir_if *f0610 = new(mem_ctx) ir_if(operand(r0611).val);
                     exec_list *const f0610_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0610->then_instructions;

                        ir_variable *const r0612 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0612, neg(r05B8), 0x01));

                        ir_variable *const r0613 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0613);
                        ir_variable *const r0614 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0615 = neg(r0612);
                        body.emit(assign(r0614, bit_and(r0615, body.constant(int(31))), 0x01));

                        ir_variable *const r0616 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0617 = less(r0612, body.constant(int(32)));
                        ir_expression *const r0618 = bit_or(r05BB, r05BA);
                        body.emit(assign(r0616, expr(ir_triop_csel, r0617, r05BB, r0618), 0x01));

                        ir_expression *const r0619 = less(r0612, body.constant(int(32)));
                        ir_expression *const r061A = lshift(r05BA, r0614);
                        ir_expression *const r061B = less(r0612, body.constant(int(64)));
                        ir_expression *const r061C = lshift(r05B9, r0614);
                        ir_expression *const r061D = equal(r0612, body.constant(int(64)));
                        ir_expression *const r061E = nequal(r05B9, body.constant(0u));
                        ir_expression *const r061F = expr(ir_unop_b2i, r061E);
                        ir_expression *const r0620 = expr(ir_unop_i2u, r061F);
                        ir_expression *const r0621 = expr(ir_triop_csel, r061D, r05B9, r0620);
                        ir_expression *const r0622 = expr(ir_triop_csel, r061B, r061C, r0621);
                        ir_expression *const r0623 = expr(ir_triop_csel, r0619, r061A, r0622);
                        ir_expression *const r0624 = nequal(r0616, body.constant(0u));
                        ir_expression *const r0625 = expr(ir_unop_b2i, r0624);
                        ir_expression *const r0626 = expr(ir_unop_i2u, r0625);
                        body.emit(assign(r0613, bit_or(r0623, r0626), 0x01));

                        ir_variable *const r0627 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0628 = equal(r0612, body.constant(int(0)));
                        ir_expression *const r0629 = equal(r0612, body.constant(int(32)));
                        ir_expression *const r062A = expr(ir_triop_csel, r0629, r05BA, r0613);
                        body.emit(assign(r0627, expr(ir_triop_csel, r0628, r0616, r062A), 0x01));

                        body.emit(assign(r0613, r0627, 0x01));

                        ir_expression *const r062B = equal(r0612, body.constant(int(0)));
                        ir_expression *const r062C = equal(r0612, body.constant(int(32)));
                        ir_expression *const r062D = less(r0612, body.constant(int(32)));
                        ir_expression *const r062E = rshift(r05B9, r0612);
                        ir_expression *const r062F = expr(ir_triop_csel, r062D, r062E, body.constant(0u));
                        ir_expression *const r0630 = expr(ir_triop_csel, r062C, body.constant(0u), r062F);
                        body.emit(assign(r05FC, expr(ir_triop_csel, r062B, r05B9, r0630), 0x01));

                        ir_expression *const r0631 = equal(r0612, body.constant(int(0)));
                        ir_expression *const r0632 = equal(r0612, body.constant(int(32)));
                        ir_expression *const r0633 = less(r0612, body.constant(int(32)));
                        ir_expression *const r0634 = lshift(r05B9, r0614);
                        ir_expression *const r0635 = rshift(r05BA, r0612);
                        ir_expression *const r0636 = bit_or(r0634, r0635);
                        ir_expression *const r0637 = less(r0612, body.constant(int(64)));
                        ir_expression *const r0638 = bit_and(r0612, body.constant(int(31)));
                        ir_expression *const r0639 = rshift(r05B9, r0638);
                        ir_expression *const r063A = expr(ir_triop_csel, r0637, r0639, body.constant(0u));
                        ir_expression *const r063B = expr(ir_triop_csel, r0633, r0636, r063A);
                        ir_expression *const r063C = expr(ir_triop_csel, r0632, r05B9, r063B);
                        body.emit(assign(r05FD, expr(ir_triop_csel, r0631, r05BA, r063C), 0x01));

                        body.emit(assign(r05FE, r0627, 0x01));

                        body.emit(assign(r05FB, body.constant(int(0)), 0x01));

                        body.emit(assign(r0601, less(r0627, body.constant(0u)), 0x01));


                     body.instructions = f0610_parent_instructions;
                     body.emit(f0610);

                     /* END IF */


                  body.instructions = f0605_parent_instructions;
                  body.emit(f0605);

                  /* END IF */


               body.instructions = f0603_parent_instructions;
               body.emit(f0603);

               /* END IF */

               /* IF CONDITION */
               ir_if *f063D = new(mem_ctx) ir_if(operand(r05FF).val);
               exec_list *const f063D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f063D->then_instructions;

                  /* IF CONDITION */
                  ir_if *f063E = new(mem_ctx) ir_if(operand(r0601).val);
                  exec_list *const f063E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f063E->then_instructions;

                     ir_variable *const r063F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r063F, add(r05FD, body.constant(1u)), 0x01));

                     ir_expression *const r0640 = less(r063F, r05FD);
                     ir_expression *const r0641 = expr(ir_unop_b2i, r0640);
                     ir_expression *const r0642 = expr(ir_unop_i2u, r0641);
                     body.emit(assign(r05FC, add(r05FC, r0642), 0x01));

                     ir_expression *const r0643 = equal(r05FE, body.constant(0u));
                     ir_expression *const r0644 = expr(ir_unop_b2i, r0643);
                     ir_expression *const r0645 = expr(ir_unop_i2u, r0644);
                     ir_expression *const r0646 = add(r05FE, r0645);
                     ir_expression *const r0647 = bit_and(r0646, body.constant(1u));
                     ir_expression *const r0648 = expr(ir_unop_bit_not, r0647);
                     body.emit(assign(r05FD, bit_and(r063F, r0648), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f063E->else_instructions;

                     ir_expression *const r0649 = bit_or(r05FC, r05FD);
                     ir_expression *const r064A = equal(r0649, body.constant(0u));
                     body.emit(assign(r05FB, expr(ir_triop_csel, r064A, body.constant(int(0)), r05FB), 0x01));


                  body.instructions = f063E_parent_instructions;
                  body.emit(f063E);

                  /* END IF */

                  ir_variable *const r064B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r064B);
                  ir_expression *const r064C = lshift(r0219, body.constant(int(31)));
                  ir_expression *const r064D = expr(ir_unop_i2u, r05FB);
                  ir_expression *const r064E = lshift(r064D, body.constant(int(20)));
                  ir_expression *const r064F = add(r064C, r064E);
                  body.emit(assign(r064B, add(r064F, r05FC), 0x02));

                  body.emit(assign(r064B, r05FD, 0x01));

                  body.emit(assign(r0600, r064B, 0x03));

                  body.emit(assign(r05FF, body.constant(false), 0x01));


               body.instructions = f063D_parent_instructions;
               body.emit(f063D);

               /* END IF */

               ir_swizzle *const r0650 = swizzle(r03A7, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               body.emit(assign(r020F, expr(ir_triop_csel, r0650, r0600, ir_constant::zero(mem_ctx, glsl_type::uvec2_type)), 0x03));

               body.emit(assign(r020E, body.constant(false), 0x01));


            body.instructions = f0581_parent_instructions;
            body.emit(f0581);

            /* END IF */


         body.instructions = f0497_parent_instructions;
         body.emit(f0497);

         /* END IF */


      body.instructions = f03B1_parent_instructions;
      body.emit(f03B1);

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

   ir_variable *const r0651 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0651);
   ir_variable *const r0652 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0652);
   ir_variable *const r0653 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0653);
   ir_variable *const r0654 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0654);
   ir_variable *const r0655 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0655);
   ir_variable *const r0656 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0656);
   ir_variable *const r0657 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0657);
   ir_variable *const r0658 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0658, bit_and(r0651, body.constant(65535u)), 0x01));

   ir_variable *const r0659 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0659, rshift(r0651, body.constant(int(16))), 0x01));

   ir_variable *const r065A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r065A, bit_and(r0652, body.constant(65535u)), 0x01));

   ir_variable *const r065B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r065B, rshift(r0652, body.constant(int(16))), 0x01));

   ir_variable *const r065C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r065C, mul(r0659, r065A), 0x01));

   ir_expression *const r065D = mul(r0658, r065B);
   body.emit(assign(r0656, add(r065D, r065C), 0x01));

   ir_expression *const r065E = mul(r0659, r065B);
   ir_expression *const r065F = less(r0656, r065C);
   ir_expression *const r0660 = expr(ir_unop_b2i, r065F);
   ir_expression *const r0661 = expr(ir_unop_i2u, r0660);
   ir_expression *const r0662 = lshift(r0661, body.constant(int(16)));
   ir_expression *const r0663 = rshift(r0656, body.constant(int(16)));
   ir_expression *const r0664 = add(r0662, r0663);
   body.emit(assign(r0655, add(r065E, r0664), 0x01));

   body.emit(assign(r0656, lshift(r0656, body.constant(int(16))), 0x01));

   ir_expression *const r0665 = mul(r0658, r065A);
   body.emit(assign(r0657, add(r0665, r0656), 0x01));

   ir_expression *const r0666 = less(r0657, r0656);
   ir_expression *const r0667 = expr(ir_unop_b2i, r0666);
   ir_expression *const r0668 = expr(ir_unop_i2u, r0667);
   body.emit(assign(r0655, add(r0655, r0668), 0x01));

   body.emit(assign(r0654, r0657, 0x01));

   body.emit(assign(r0653, r0655, 0x01));

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

   ir_variable *const r0669 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0669);
   ir_variable *const r066A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r066A);
   ir_variable *const r066B = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r066B);
   ir_variable *const r066C = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r066C);
   ir_variable *const r066D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r066D);
   ir_variable *const r066E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r066E);
   ir_variable *const r066F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r066F);
   ir_variable *const r0670 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0670);
   ir_variable *const r0671 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0671);
   ir_variable *const r0672 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0672);
   ir_variable *const r0673 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0673);
   ir_variable *const r0674 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0674, bit_and(r066A, body.constant(65535u)), 0x01));

   ir_variable *const r0675 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0675, rshift(r066A, body.constant(int(16))), 0x01));

   ir_variable *const r0676 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0676, bit_and(r066C, body.constant(65535u)), 0x01));

   ir_variable *const r0677 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0677, rshift(r066C, body.constant(int(16))), 0x01));

   ir_variable *const r0678 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0678, mul(r0675, r0676), 0x01));

   ir_expression *const r0679 = mul(r0674, r0677);
   body.emit(assign(r0672, add(r0679, r0678), 0x01));

   ir_expression *const r067A = mul(r0675, r0677);
   ir_expression *const r067B = less(r0672, r0678);
   ir_expression *const r067C = expr(ir_unop_b2i, r067B);
   ir_expression *const r067D = expr(ir_unop_i2u, r067C);
   ir_expression *const r067E = lshift(r067D, body.constant(int(16)));
   ir_expression *const r067F = rshift(r0672, body.constant(int(16)));
   ir_expression *const r0680 = add(r067E, r067F);
   body.emit(assign(r0671, add(r067A, r0680), 0x01));

   body.emit(assign(r0672, lshift(r0672, body.constant(int(16))), 0x01));

   ir_expression *const r0681 = mul(r0674, r0676);
   body.emit(assign(r0673, add(r0681, r0672), 0x01));

   ir_expression *const r0682 = less(r0673, r0672);
   ir_expression *const r0683 = expr(ir_unop_b2i, r0682);
   ir_expression *const r0684 = expr(ir_unop_i2u, r0683);
   body.emit(assign(r0671, add(r0671, r0684), 0x01));

   ir_variable *const r0685 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0685);
   ir_variable *const r0686 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0686);
   ir_variable *const r0687 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0687);
   ir_variable *const r0688 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0688, bit_and(r066A, body.constant(65535u)), 0x01));

   ir_variable *const r0689 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0689, rshift(r066A, body.constant(int(16))), 0x01));

   ir_variable *const r068A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r068A, bit_and(r066B, body.constant(65535u)), 0x01));

   ir_variable *const r068B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r068B, rshift(r066B, body.constant(int(16))), 0x01));

   ir_variable *const r068C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r068C, mul(r0689, r068A), 0x01));

   ir_expression *const r068D = mul(r0688, r068B);
   body.emit(assign(r0686, add(r068D, r068C), 0x01));

   ir_expression *const r068E = mul(r0689, r068B);
   ir_expression *const r068F = less(r0686, r068C);
   ir_expression *const r0690 = expr(ir_unop_b2i, r068F);
   ir_expression *const r0691 = expr(ir_unop_i2u, r0690);
   ir_expression *const r0692 = lshift(r0691, body.constant(int(16)));
   ir_expression *const r0693 = rshift(r0686, body.constant(int(16)));
   ir_expression *const r0694 = add(r0692, r0693);
   body.emit(assign(r0685, add(r068E, r0694), 0x01));

   body.emit(assign(r0686, lshift(r0686, body.constant(int(16))), 0x01));

   ir_expression *const r0695 = mul(r0688, r068A);
   body.emit(assign(r0687, add(r0695, r0686), 0x01));

   ir_expression *const r0696 = less(r0687, r0686);
   ir_expression *const r0697 = expr(ir_unop_b2i, r0696);
   ir_expression *const r0698 = expr(ir_unop_i2u, r0697);
   body.emit(assign(r0685, add(r0685, r0698), 0x01));

   ir_variable *const r0699 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0699, add(r0687, r0671), 0x01));

   ir_variable *const r069A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r069A);
   ir_variable *const r069B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r069B);
   ir_variable *const r069C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r069C);
   ir_variable *const r069D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r069D, bit_and(r0669, body.constant(65535u)), 0x01));

   ir_variable *const r069E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r069E, rshift(r0669, body.constant(int(16))), 0x01));

   ir_variable *const r069F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r069F, bit_and(r066B, body.constant(65535u)), 0x01));

   ir_variable *const r06A0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r06A0, rshift(r066B, body.constant(int(16))), 0x01));

   ir_variable *const r06A1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r06A1, mul(r069E, r069F), 0x01));

   ir_expression *const r06A2 = mul(r069D, r06A0);
   body.emit(assign(r069B, add(r06A2, r06A1), 0x01));

   ir_expression *const r06A3 = mul(r069E, r06A0);
   ir_expression *const r06A4 = less(r069B, r06A1);
   ir_expression *const r06A5 = expr(ir_unop_b2i, r06A4);
   ir_expression *const r06A6 = expr(ir_unop_i2u, r06A5);
   ir_expression *const r06A7 = lshift(r06A6, body.constant(int(16)));
   ir_expression *const r06A8 = rshift(r069B, body.constant(int(16)));
   ir_expression *const r06A9 = add(r06A7, r06A8);
   body.emit(assign(r069A, add(r06A3, r06A9), 0x01));

   body.emit(assign(r069B, lshift(r069B, body.constant(int(16))), 0x01));

   ir_expression *const r06AA = mul(r069D, r069F);
   body.emit(assign(r069C, add(r06AA, r069B), 0x01));

   ir_expression *const r06AB = less(r069C, r069B);
   ir_expression *const r06AC = expr(ir_unop_b2i, r06AB);
   ir_expression *const r06AD = expr(ir_unop_i2u, r06AC);
   body.emit(assign(r069A, add(r069A, r06AD), 0x01));

   ir_variable *const r06AE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r06AF = less(r0699, r0687);
   ir_expression *const r06B0 = expr(ir_unop_b2i, r06AF);
   ir_expression *const r06B1 = expr(ir_unop_i2u, r06B0);
   ir_expression *const r06B2 = add(r0685, r06B1);
   body.emit(assign(r06AE, add(r069C, r06B2), 0x01));

   ir_variable *const r06B3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r06B3);
   ir_variable *const r06B4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r06B4);
   ir_variable *const r06B5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r06B5);
   ir_variable *const r06B6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r06B6, bit_and(r0669, body.constant(65535u)), 0x01));

   ir_variable *const r06B7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r06B7, rshift(r0669, body.constant(int(16))), 0x01));

   ir_variable *const r06B8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r06B8, bit_and(r066C, body.constant(65535u)), 0x01));

   ir_variable *const r06B9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r06B9, rshift(r066C, body.constant(int(16))), 0x01));

   ir_variable *const r06BA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r06BA, mul(r06B7, r06B8), 0x01));

   ir_expression *const r06BB = mul(r06B6, r06B9);
   body.emit(assign(r06B4, add(r06BB, r06BA), 0x01));

   ir_expression *const r06BC = mul(r06B7, r06B9);
   ir_expression *const r06BD = less(r06B4, r06BA);
   ir_expression *const r06BE = expr(ir_unop_b2i, r06BD);
   ir_expression *const r06BF = expr(ir_unop_i2u, r06BE);
   ir_expression *const r06C0 = lshift(r06BF, body.constant(int(16)));
   ir_expression *const r06C1 = rshift(r06B4, body.constant(int(16)));
   ir_expression *const r06C2 = add(r06C0, r06C1);
   body.emit(assign(r06B3, add(r06BC, r06C2), 0x01));

   body.emit(assign(r06B4, lshift(r06B4, body.constant(int(16))), 0x01));

   ir_expression *const r06C3 = mul(r06B6, r06B8);
   body.emit(assign(r06B5, add(r06C3, r06B4), 0x01));

   ir_expression *const r06C4 = less(r06B5, r06B4);
   ir_expression *const r06C5 = expr(ir_unop_b2i, r06C4);
   ir_expression *const r06C6 = expr(ir_unop_i2u, r06C5);
   body.emit(assign(r06B3, add(r06B3, r06C6), 0x01));

   ir_variable *const r06C7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r06C7, add(r06B5, r0699), 0x01));

   ir_variable *const r06C8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r06C9 = less(r06C7, r06B5);
   ir_expression *const r06CA = expr(ir_unop_b2i, r06C9);
   ir_expression *const r06CB = expr(ir_unop_i2u, r06CA);
   ir_expression *const r06CC = add(r06B3, r06CB);
   body.emit(assign(r06C8, add(r06AE, r06CC), 0x01));

   body.emit(assign(r0670, r0673, 0x01));

   body.emit(assign(r066F, r06C7, 0x01));

   body.emit(assign(r066E, r06C8, 0x01));

   ir_expression *const r06CD = less(r06AE, r069C);
   ir_expression *const r06CE = expr(ir_unop_b2i, r06CD);
   ir_expression *const r06CF = expr(ir_unop_i2u, r06CE);
   ir_expression *const r06D0 = add(r069A, r06CF);
   ir_expression *const r06D1 = less(r06C8, r06AE);
   ir_expression *const r06D2 = expr(ir_unop_b2i, r06D1);
   ir_expression *const r06D3 = expr(ir_unop_i2u, r06D2);
   body.emit(assign(r066D, add(r06D0, r06D3), 0x01));

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

   ir_variable *const r06D4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r06D4);
   ir_variable *const r06D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r06D5);
   ir_variable *const r06D6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r06D6);
   ir_variable *const r06D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r06D7);
   ir_variable *const r06D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r06D8);
   ir_variable *const r06D9 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r06D9);
   /* IF CONDITION */
   ir_expression *const r06DB = equal(r06D4, body.constant(0u));
   ir_if *f06DA = new(mem_ctx) ir_if(operand(r06DB).val);
   exec_list *const f06DA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f06DA->then_instructions;

      ir_expression *const r06DC = equal(r06D5, body.constant(0u));
      ir_expression *const r06DD = expr(ir_unop_find_msb, r06D5);
      ir_expression *const r06DE = sub(body.constant(int(31)), r06DD);
      ir_expression *const r06DF = expr(ir_triop_csel, r06DC, body.constant(int(32)), r06DE);
      body.emit(assign(r06D9, add(r06DF, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r06E1 = less(r06D9, body.constant(int(0)));
      ir_if *f06E0 = new(mem_ctx) ir_if(operand(r06E1).val);
      exec_list *const f06E0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f06E0->then_instructions;

         ir_expression *const r06E2 = neg(r06D9);
         body.emit(assign(r06D7, rshift(r06D5, r06E2), 0x01));

         ir_expression *const r06E3 = bit_and(r06D9, body.constant(int(31)));
         body.emit(assign(r06D8, lshift(r06D5, r06E3), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f06E0->else_instructions;

         body.emit(assign(r06D7, lshift(r06D5, r06D9), 0x01));

         body.emit(assign(r06D8, body.constant(0u), 0x01));


      body.instructions = f06E0_parent_instructions;
      body.emit(f06E0);

      /* END IF */

      body.emit(assign(r06D6, sub(body.constant(int(-31)), r06D9), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f06DA->else_instructions;

      ir_expression *const r06E4 = equal(r06D4, body.constant(0u));
      ir_expression *const r06E5 = expr(ir_unop_find_msb, r06D4);
      ir_expression *const r06E6 = sub(body.constant(int(31)), r06E5);
      ir_expression *const r06E7 = expr(ir_triop_csel, r06E4, body.constant(int(32)), r06E6);
      body.emit(assign(r06D9, add(r06E7, body.constant(int(-11))), 0x01));

      ir_expression *const r06E8 = equal(r06D9, body.constant(int(0)));
      ir_expression *const r06E9 = lshift(r06D4, r06D9);
      ir_expression *const r06EA = neg(r06D9);
      ir_expression *const r06EB = bit_and(r06EA, body.constant(int(31)));
      ir_expression *const r06EC = rshift(r06D5, r06EB);
      ir_expression *const r06ED = bit_or(r06E9, r06EC);
      body.emit(assign(r06D7, expr(ir_triop_csel, r06E8, r06D4, r06ED), 0x01));

      body.emit(assign(r06D8, lshift(r06D5, r06D9), 0x01));

      body.emit(assign(r06D6, sub(body.constant(int(1)), r06D9), 0x01));


   body.instructions = f06DA_parent_instructions;
   body.emit(f06DA);

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

   ir_variable *const r06EE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r06EE);
   ir_variable *const r06EF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r06EF);
   ir_variable *const r06F0 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r06F0, body.constant(true), 0x01));

   ir_variable *const r06F1 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r06F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r06F2);
   ir_variable *const r06F3 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r06F3);
   ir_variable *const r06F4 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r06F4);
   ir_variable *const r06F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r06F5);
   ir_variable *const r06F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r06F6);
   ir_variable *const r06F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r06F7);
   ir_variable *const r06F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r06F8);
   ir_variable *const r06F9 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r06F9);
   ir_variable *const r06FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r06FA);
   ir_variable *const r06FB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r06FB);
   ir_variable *const r06FC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r06FC);
   body.emit(assign(r06FC, body.constant(0u), 0x01));

   body.emit(assign(r06FB, body.constant(0u), 0x01));

   body.emit(assign(r06FA, body.constant(0u), 0x01));

   ir_variable *const r06FD = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r06FD, swizzle_x(r06EE), 0x01));

   body.emit(assign(r06F8, r06FD, 0x01));

   ir_variable *const r06FE = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r06FE, bit_and(swizzle_y(r06EE), body.constant(1048575u)), 0x01));

   body.emit(assign(r06F7, r06FE, 0x01));

   ir_variable *const r06FF = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r06FF, swizzle_x(r06EF), 0x01));

   body.emit(assign(r06F6, r06FF, 0x01));

   ir_variable *const r0700 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0700, bit_and(swizzle_y(r06EF), body.constant(1048575u)), 0x01));

   body.emit(assign(r06F5, r0700, 0x01));

   ir_variable *const r0701 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0702 = rshift(swizzle_y(r06EE), body.constant(int(20)));
   ir_expression *const r0703 = bit_and(r0702, body.constant(2047u));
   body.emit(assign(r0701, expr(ir_unop_u2i, r0703), 0x01));

   body.emit(assign(r06F4, r0701, 0x01));

   ir_variable *const r0704 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0705 = rshift(swizzle_y(r06EF), body.constant(int(20)));
   ir_expression *const r0706 = bit_and(r0705, body.constant(2047u));
   body.emit(assign(r0704, expr(ir_unop_u2i, r0706), 0x01));

   body.emit(assign(r06F3, r0704, 0x01));

   ir_expression *const r0707 = rshift(swizzle_y(r06EE), body.constant(int(31)));
   ir_expression *const r0708 = rshift(swizzle_y(r06EF), body.constant(int(31)));
   body.emit(assign(r06F2, bit_xor(r0707, r0708), 0x01));

   /* IF CONDITION */
   ir_expression *const r070A = equal(r0701, body.constant(int(2047)));
   ir_if *f0709 = new(mem_ctx) ir_if(operand(r070A).val);
   exec_list *const f0709_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0709->then_instructions;

      /* IF CONDITION */
      ir_expression *const r070C = bit_or(r06FE, swizzle_x(r06EE));
      ir_expression *const r070D = nequal(r070C, body.constant(0u));
      ir_expression *const r070E = equal(r0704, body.constant(int(2047)));
      ir_expression *const r070F = bit_or(r0700, swizzle_x(r06EF));
      ir_expression *const r0710 = nequal(r070F, body.constant(0u));
      ir_expression *const r0711 = logic_and(r070E, r0710);
      ir_expression *const r0712 = logic_or(r070D, r0711);
      ir_if *f070B = new(mem_ctx) ir_if(operand(r0712).val);
      exec_list *const f070B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f070B->then_instructions;

         ir_variable *const r0713 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r0713, swizzle_x(r06EE), 0x01));

         ir_variable *const r0714 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r0714, swizzle_x(r06EF), 0x01));

         body.emit(assign(r0713, bit_or(swizzle_y(r06EE), body.constant(524288u)), 0x02));

         body.emit(assign(r0714, bit_or(swizzle_y(r06EF), body.constant(524288u)), 0x02));

         ir_expression *const r0715 = lshift(swizzle_y(r06EE), body.constant(int(1)));
         ir_expression *const r0716 = gequal(r0715, body.constant(4292870144u));
         ir_expression *const r0717 = nequal(swizzle_x(r06EE), body.constant(0u));
         ir_expression *const r0718 = bit_and(swizzle_y(r06EE), body.constant(1048575u));
         ir_expression *const r0719 = nequal(r0718, body.constant(0u));
         ir_expression *const r071A = logic_or(r0717, r0719);
         ir_expression *const r071B = logic_and(r0716, r071A);
         ir_swizzle *const r071C = swizzle(r071B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r071D = lshift(swizzle_y(r06EF), body.constant(int(1)));
         ir_expression *const r071E = gequal(r071D, body.constant(4292870144u));
         ir_expression *const r071F = nequal(swizzle_x(r06EF), body.constant(0u));
         ir_expression *const r0720 = bit_and(swizzle_y(r06EF), body.constant(1048575u));
         ir_expression *const r0721 = nequal(r0720, body.constant(0u));
         ir_expression *const r0722 = logic_or(r071F, r0721);
         ir_expression *const r0723 = logic_and(r071E, r0722);
         ir_swizzle *const r0724 = swizzle(r0723, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r0725 = expr(ir_triop_csel, r0724, r0714, r0713);
         body.emit(assign(r06F1, expr(ir_triop_csel, r071C, r0725, r0714), 0x03));

         body.emit(assign(r06F0, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f070B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0727 = expr(ir_unop_i2u, r0704);
         ir_expression *const r0728 = bit_or(r0727, r0700);
         ir_expression *const r0729 = bit_or(r0728, swizzle_x(r06EF));
         ir_expression *const r072A = equal(r0729, body.constant(0u));
         ir_if *f0726 = new(mem_ctx) ir_if(operand(r072A).val);
         exec_list *const f0726_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0726->then_instructions;

            ir_constant_data r072B_data;
            memset(&r072B_data, 0, sizeof(ir_constant_data));
            r072B_data.u[0] = 4294967295;
            r072B_data.u[1] = 4294967295;
            ir_constant *const r072B = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r072B_data);
            body.emit(assign(r06F1, r072B, 0x03));

            body.emit(assign(r06F0, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0726->else_instructions;

            ir_variable *const r072C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r072C);
            ir_expression *const r072D = lshift(r06F2, body.constant(int(31)));
            body.emit(assign(r072C, add(r072D, body.constant(2146435072u)), 0x02));

            body.emit(assign(r072C, body.constant(0u), 0x01));

            body.emit(assign(r06F1, r072C, 0x03));

            body.emit(assign(r06F0, body.constant(false), 0x01));


         body.instructions = f0726_parent_instructions;
         body.emit(f0726);

         /* END IF */


      body.instructions = f070B_parent_instructions;
      body.emit(f070B);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0709->else_instructions;

      /* IF CONDITION */
      ir_expression *const r072F = equal(r0704, body.constant(int(2047)));
      ir_if *f072E = new(mem_ctx) ir_if(operand(r072F).val);
      exec_list *const f072E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f072E->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0731 = bit_or(r0700, swizzle_x(r06EF));
         ir_expression *const r0732 = nequal(r0731, body.constant(0u));
         ir_if *f0730 = new(mem_ctx) ir_if(operand(r0732).val);
         exec_list *const f0730_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0730->then_instructions;

            ir_variable *const r0733 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0733, swizzle_x(r06EE), 0x01));

            ir_variable *const r0734 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0734, swizzle_x(r06EF), 0x01));

            body.emit(assign(r0733, bit_or(swizzle_y(r06EE), body.constant(524288u)), 0x02));

            body.emit(assign(r0734, bit_or(swizzle_y(r06EF), body.constant(524288u)), 0x02));

            ir_expression *const r0735 = lshift(swizzle_y(r06EE), body.constant(int(1)));
            ir_expression *const r0736 = gequal(r0735, body.constant(4292870144u));
            ir_expression *const r0737 = nequal(swizzle_x(r06EE), body.constant(0u));
            ir_expression *const r0738 = bit_and(swizzle_y(r06EE), body.constant(1048575u));
            ir_expression *const r0739 = nequal(r0738, body.constant(0u));
            ir_expression *const r073A = logic_or(r0737, r0739);
            ir_expression *const r073B = logic_and(r0736, r073A);
            ir_swizzle *const r073C = swizzle(r073B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r073D = lshift(swizzle_y(r06EF), body.constant(int(1)));
            ir_expression *const r073E = gequal(r073D, body.constant(4292870144u));
            ir_expression *const r073F = nequal(swizzle_x(r06EF), body.constant(0u));
            ir_expression *const r0740 = bit_and(swizzle_y(r06EF), body.constant(1048575u));
            ir_expression *const r0741 = nequal(r0740, body.constant(0u));
            ir_expression *const r0742 = logic_or(r073F, r0741);
            ir_expression *const r0743 = logic_and(r073E, r0742);
            ir_swizzle *const r0744 = swizzle(r0743, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0745 = expr(ir_triop_csel, r0744, r0734, r0733);
            body.emit(assign(r06F1, expr(ir_triop_csel, r073C, r0745, r0734), 0x03));

            body.emit(assign(r06F0, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0730->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0747 = expr(ir_unop_i2u, r0701);
            ir_expression *const r0748 = bit_or(r0747, r06FE);
            ir_expression *const r0749 = bit_or(r0748, swizzle_x(r06EE));
            ir_expression *const r074A = equal(r0749, body.constant(0u));
            ir_if *f0746 = new(mem_ctx) ir_if(operand(r074A).val);
            exec_list *const f0746_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0746->then_instructions;

               ir_constant_data r074B_data;
               memset(&r074B_data, 0, sizeof(ir_constant_data));
               r074B_data.u[0] = 4294967295;
               r074B_data.u[1] = 4294967295;
               ir_constant *const r074B = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r074B_data);
               body.emit(assign(r06F1, r074B, 0x03));

               body.emit(assign(r06F0, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0746->else_instructions;

               ir_variable *const r074C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r074C);
               ir_expression *const r074D = lshift(r06F2, body.constant(int(31)));
               body.emit(assign(r074C, add(r074D, body.constant(2146435072u)), 0x02));

               body.emit(assign(r074C, body.constant(0u), 0x01));

               body.emit(assign(r06F1, r074C, 0x03));

               body.emit(assign(r06F0, body.constant(false), 0x01));


            body.instructions = f0746_parent_instructions;
            body.emit(f0746);

            /* END IF */


         body.instructions = f0730_parent_instructions;
         body.emit(f0730);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f072E->else_instructions;

         /* IF CONDITION */
         ir_expression *const r074F = equal(r0701, body.constant(int(0)));
         ir_if *f074E = new(mem_ctx) ir_if(operand(r074F).val);
         exec_list *const f074E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f074E->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0751 = bit_or(r06FE, swizzle_x(r06EE));
            ir_expression *const r0752 = equal(r0751, body.constant(0u));
            ir_if *f0750 = new(mem_ctx) ir_if(operand(r0752).val);
            exec_list *const f0750_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0750->then_instructions;

               ir_variable *const r0753 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0753);
               body.emit(assign(r0753, lshift(r06F2, body.constant(int(31))), 0x02));

               body.emit(assign(r0753, body.constant(0u), 0x01));

               body.emit(assign(r06F1, r0753, 0x03));

               body.emit(assign(r06F0, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0750->else_instructions;

               ir_variable *const r0754 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r0754, r0701, 0x01));

               ir_variable *const r0755 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r0755, r06FE, 0x01));

               ir_variable *const r0756 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r0756, r06FD, 0x01));

               ir_variable *const r0757 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0757);
               /* IF CONDITION */
               ir_expression *const r0759 = equal(r06FE, body.constant(0u));
               ir_if *f0758 = new(mem_ctx) ir_if(operand(r0759).val);
               exec_list *const f0758_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0758->then_instructions;

                  ir_expression *const r075A = equal(swizzle_x(r06EE), body.constant(0u));
                  ir_expression *const r075B = expr(ir_unop_find_msb, swizzle_x(r06EE));
                  ir_expression *const r075C = sub(body.constant(int(31)), r075B);
                  ir_expression *const r075D = expr(ir_triop_csel, r075A, body.constant(int(32)), r075C);
                  body.emit(assign(r0757, add(r075D, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r075F = less(r0757, body.constant(int(0)));
                  ir_if *f075E = new(mem_ctx) ir_if(operand(r075F).val);
                  exec_list *const f075E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f075E->then_instructions;

                     ir_expression *const r0760 = neg(r0757);
                     body.emit(assign(r0755, rshift(swizzle_x(r06EE), r0760), 0x01));

                     ir_expression *const r0761 = bit_and(r0757, body.constant(int(31)));
                     body.emit(assign(r0756, lshift(swizzle_x(r06EE), r0761), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f075E->else_instructions;

                     body.emit(assign(r0755, lshift(swizzle_x(r06EE), r0757), 0x01));

                     body.emit(assign(r0756, body.constant(0u), 0x01));


                  body.instructions = f075E_parent_instructions;
                  body.emit(f075E);

                  /* END IF */

                  body.emit(assign(r0754, sub(body.constant(int(-31)), r0757), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0758->else_instructions;

                  ir_expression *const r0762 = equal(r06FE, body.constant(0u));
                  ir_expression *const r0763 = expr(ir_unop_find_msb, r06FE);
                  ir_expression *const r0764 = sub(body.constant(int(31)), r0763);
                  ir_expression *const r0765 = expr(ir_triop_csel, r0762, body.constant(int(32)), r0764);
                  body.emit(assign(r0757, add(r0765, body.constant(int(-11))), 0x01));

                  ir_expression *const r0766 = equal(r0757, body.constant(int(0)));
                  ir_expression *const r0767 = lshift(r06FE, r0757);
                  ir_expression *const r0768 = neg(r0757);
                  ir_expression *const r0769 = bit_and(r0768, body.constant(int(31)));
                  ir_expression *const r076A = rshift(swizzle_x(r06EE), r0769);
                  ir_expression *const r076B = bit_or(r0767, r076A);
                  body.emit(assign(r0755, expr(ir_triop_csel, r0766, r06FE, r076B), 0x01));

                  body.emit(assign(r0756, lshift(swizzle_x(r06EE), r0757), 0x01));

                  body.emit(assign(r0754, sub(body.constant(int(1)), r0757), 0x01));


               body.instructions = f0758_parent_instructions;
               body.emit(f0758);

               /* END IF */

               body.emit(assign(r06F4, r0754, 0x01));

               body.emit(assign(r06F7, r0755, 0x01));

               body.emit(assign(r06F8, r0756, 0x01));


            body.instructions = f0750_parent_instructions;
            body.emit(f0750);

            /* END IF */


         body.instructions = f074E_parent_instructions;
         body.emit(f074E);

         /* END IF */

         /* IF CONDITION */
         ir_if *f076C = new(mem_ctx) ir_if(operand(r06F0).val);
         exec_list *const f076C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f076C->then_instructions;

            /* IF CONDITION */
            ir_expression *const r076E = equal(r0704, body.constant(int(0)));
            ir_if *f076D = new(mem_ctx) ir_if(operand(r076E).val);
            exec_list *const f076D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f076D->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0770 = bit_or(r0700, swizzle_x(r06EF));
               ir_expression *const r0771 = equal(r0770, body.constant(0u));
               ir_if *f076F = new(mem_ctx) ir_if(operand(r0771).val);
               exec_list *const f076F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f076F->then_instructions;

                  ir_variable *const r0772 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0772);
                  body.emit(assign(r0772, lshift(r06F2, body.constant(int(31))), 0x02));

                  body.emit(assign(r0772, body.constant(0u), 0x01));

                  body.emit(assign(r06F1, r0772, 0x03));

                  body.emit(assign(r06F0, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f076F->else_instructions;

                  ir_variable *const r0773 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r0773, r0704, 0x01));

                  ir_variable *const r0774 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r0774, r0700, 0x01));

                  ir_variable *const r0775 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r0775, r06FF, 0x01));

                  ir_variable *const r0776 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0776);
                  /* IF CONDITION */
                  ir_expression *const r0778 = equal(r0700, body.constant(0u));
                  ir_if *f0777 = new(mem_ctx) ir_if(operand(r0778).val);
                  exec_list *const f0777_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0777->then_instructions;

                     ir_expression *const r0779 = equal(swizzle_x(r06EF), body.constant(0u));
                     ir_expression *const r077A = expr(ir_unop_find_msb, swizzle_x(r06EF));
                     ir_expression *const r077B = sub(body.constant(int(31)), r077A);
                     ir_expression *const r077C = expr(ir_triop_csel, r0779, body.constant(int(32)), r077B);
                     body.emit(assign(r0776, add(r077C, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r077E = less(r0776, body.constant(int(0)));
                     ir_if *f077D = new(mem_ctx) ir_if(operand(r077E).val);
                     exec_list *const f077D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f077D->then_instructions;

                        ir_expression *const r077F = neg(r0776);
                        body.emit(assign(r0774, rshift(swizzle_x(r06EF), r077F), 0x01));

                        ir_expression *const r0780 = bit_and(r0776, body.constant(int(31)));
                        body.emit(assign(r0775, lshift(swizzle_x(r06EF), r0780), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f077D->else_instructions;

                        body.emit(assign(r0774, lshift(swizzle_x(r06EF), r0776), 0x01));

                        body.emit(assign(r0775, body.constant(0u), 0x01));


                     body.instructions = f077D_parent_instructions;
                     body.emit(f077D);

                     /* END IF */

                     body.emit(assign(r0773, sub(body.constant(int(-31)), r0776), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0777->else_instructions;

                     ir_expression *const r0781 = equal(r0700, body.constant(0u));
                     ir_expression *const r0782 = expr(ir_unop_find_msb, r0700);
                     ir_expression *const r0783 = sub(body.constant(int(31)), r0782);
                     ir_expression *const r0784 = expr(ir_triop_csel, r0781, body.constant(int(32)), r0783);
                     body.emit(assign(r0776, add(r0784, body.constant(int(-11))), 0x01));

                     ir_expression *const r0785 = equal(r0776, body.constant(int(0)));
                     ir_expression *const r0786 = lshift(r0700, r0776);
                     ir_expression *const r0787 = neg(r0776);
                     ir_expression *const r0788 = bit_and(r0787, body.constant(int(31)));
                     ir_expression *const r0789 = rshift(swizzle_x(r06EF), r0788);
                     ir_expression *const r078A = bit_or(r0786, r0789);
                     body.emit(assign(r0774, expr(ir_triop_csel, r0785, r0700, r078A), 0x01));

                     body.emit(assign(r0775, lshift(swizzle_x(r06EF), r0776), 0x01));

                     body.emit(assign(r0773, sub(body.constant(int(1)), r0776), 0x01));


                  body.instructions = f0777_parent_instructions;
                  body.emit(f0777);

                  /* END IF */

                  body.emit(assign(r06F3, r0773, 0x01));

                  body.emit(assign(r06F5, r0774, 0x01));

                  body.emit(assign(r06F6, r0775, 0x01));


               body.instructions = f076F_parent_instructions;
               body.emit(f076F);

               /* END IF */


            body.instructions = f076D_parent_instructions;
            body.emit(f076D);

            /* END IF */

            /* IF CONDITION */
            ir_if *f078B = new(mem_ctx) ir_if(operand(r06F0).val);
            exec_list *const f078B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f078B->then_instructions;

               ir_expression *const r078C = add(r06F4, r06F3);
               body.emit(assign(r06F9, add(r078C, body.constant(int(-1024))), 0x01));

               body.emit(assign(r06F7, bit_or(r06F7, body.constant(1048576u)), 0x01));

               ir_variable *const r078D = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r078E = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r078E, lshift(r06F6, body.constant(int(12))), 0x01));

               ir_expression *const r078F = lshift(r06F5, body.constant(int(12)));
               ir_expression *const r0790 = rshift(r06F6, body.constant(int(20)));
               body.emit(assign(r078D, bit_or(r078F, r0790), 0x01));

               body.emit(assign(r06F5, r078D, 0x01));

               body.emit(assign(r06F6, r078E, 0x01));

               ir_variable *const r0791 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0791);
               ir_variable *const r0792 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0792);
               ir_variable *const r0793 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0793);
               ir_variable *const r0794 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0794, bit_and(r06F8, body.constant(65535u)), 0x01));

               ir_variable *const r0795 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0795, rshift(r06F8, body.constant(int(16))), 0x01));

               ir_variable *const r0796 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0796, bit_and(r078E, body.constant(65535u)), 0x01));

               ir_variable *const r0797 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0797, rshift(r078E, body.constant(int(16))), 0x01));

               ir_variable *const r0798 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0798, mul(r0795, r0796), 0x01));

               ir_expression *const r0799 = mul(r0794, r0797);
               body.emit(assign(r0792, add(r0799, r0798), 0x01));

               ir_expression *const r079A = mul(r0795, r0797);
               ir_expression *const r079B = less(r0792, r0798);
               ir_expression *const r079C = expr(ir_unop_b2i, r079B);
               ir_expression *const r079D = expr(ir_unop_i2u, r079C);
               ir_expression *const r079E = lshift(r079D, body.constant(int(16)));
               ir_expression *const r079F = rshift(r0792, body.constant(int(16)));
               ir_expression *const r07A0 = add(r079E, r079F);
               body.emit(assign(r0791, add(r079A, r07A0), 0x01));

               body.emit(assign(r0792, lshift(r0792, body.constant(int(16))), 0x01));

               ir_expression *const r07A1 = mul(r0794, r0796);
               body.emit(assign(r0793, add(r07A1, r0792), 0x01));

               ir_expression *const r07A2 = less(r0793, r0792);
               ir_expression *const r07A3 = expr(ir_unop_b2i, r07A2);
               ir_expression *const r07A4 = expr(ir_unop_i2u, r07A3);
               body.emit(assign(r0791, add(r0791, r07A4), 0x01));

               ir_variable *const r07A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r07A5);
               ir_variable *const r07A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r07A6);
               ir_variable *const r07A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r07A7);
               ir_variable *const r07A8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07A8, bit_and(r06F8, body.constant(65535u)), 0x01));

               ir_variable *const r07A9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07A9, rshift(r06F8, body.constant(int(16))), 0x01));

               ir_variable *const r07AA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07AA, bit_and(r078D, body.constant(65535u)), 0x01));

               ir_variable *const r07AB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07AB, rshift(r078D, body.constant(int(16))), 0x01));

               ir_variable *const r07AC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07AC, mul(r07A9, r07AA), 0x01));

               ir_expression *const r07AD = mul(r07A8, r07AB);
               body.emit(assign(r07A6, add(r07AD, r07AC), 0x01));

               ir_expression *const r07AE = mul(r07A9, r07AB);
               ir_expression *const r07AF = less(r07A6, r07AC);
               ir_expression *const r07B0 = expr(ir_unop_b2i, r07AF);
               ir_expression *const r07B1 = expr(ir_unop_i2u, r07B0);
               ir_expression *const r07B2 = lshift(r07B1, body.constant(int(16)));
               ir_expression *const r07B3 = rshift(r07A6, body.constant(int(16)));
               ir_expression *const r07B4 = add(r07B2, r07B3);
               body.emit(assign(r07A5, add(r07AE, r07B4), 0x01));

               body.emit(assign(r07A6, lshift(r07A6, body.constant(int(16))), 0x01));

               ir_expression *const r07B5 = mul(r07A8, r07AA);
               body.emit(assign(r07A7, add(r07B5, r07A6), 0x01));

               ir_expression *const r07B6 = less(r07A7, r07A6);
               ir_expression *const r07B7 = expr(ir_unop_b2i, r07B6);
               ir_expression *const r07B8 = expr(ir_unop_i2u, r07B7);
               body.emit(assign(r07A5, add(r07A5, r07B8), 0x01));

               ir_variable *const r07B9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07B9, add(r07A7, r0791), 0x01));

               ir_variable *const r07BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r07BA);
               ir_variable *const r07BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r07BB);
               ir_variable *const r07BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r07BC);
               ir_variable *const r07BD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07BD, bit_and(r06F7, body.constant(65535u)), 0x01));

               ir_variable *const r07BE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07BE, rshift(r06F7, body.constant(int(16))), 0x01));

               ir_variable *const r07BF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07BF, bit_and(r078D, body.constant(65535u)), 0x01));

               ir_variable *const r07C0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07C0, rshift(r078D, body.constant(int(16))), 0x01));

               ir_variable *const r07C1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07C1, mul(r07BE, r07BF), 0x01));

               ir_expression *const r07C2 = mul(r07BD, r07C0);
               body.emit(assign(r07BB, add(r07C2, r07C1), 0x01));

               ir_expression *const r07C3 = mul(r07BE, r07C0);
               ir_expression *const r07C4 = less(r07BB, r07C1);
               ir_expression *const r07C5 = expr(ir_unop_b2i, r07C4);
               ir_expression *const r07C6 = expr(ir_unop_i2u, r07C5);
               ir_expression *const r07C7 = lshift(r07C6, body.constant(int(16)));
               ir_expression *const r07C8 = rshift(r07BB, body.constant(int(16)));
               ir_expression *const r07C9 = add(r07C7, r07C8);
               body.emit(assign(r07BA, add(r07C3, r07C9), 0x01));

               body.emit(assign(r07BB, lshift(r07BB, body.constant(int(16))), 0x01));

               ir_expression *const r07CA = mul(r07BD, r07BF);
               body.emit(assign(r07BC, add(r07CA, r07BB), 0x01));

               ir_expression *const r07CB = less(r07BC, r07BB);
               ir_expression *const r07CC = expr(ir_unop_b2i, r07CB);
               ir_expression *const r07CD = expr(ir_unop_i2u, r07CC);
               body.emit(assign(r07BA, add(r07BA, r07CD), 0x01));

               ir_variable *const r07CE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r07CF = less(r07B9, r07A7);
               ir_expression *const r07D0 = expr(ir_unop_b2i, r07CF);
               ir_expression *const r07D1 = expr(ir_unop_i2u, r07D0);
               ir_expression *const r07D2 = add(r07A5, r07D1);
               body.emit(assign(r07CE, add(r07BC, r07D2), 0x01));

               ir_variable *const r07D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r07D3);
               ir_variable *const r07D4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r07D4);
               ir_variable *const r07D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r07D5);
               ir_variable *const r07D6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07D6, bit_and(r06F7, body.constant(65535u)), 0x01));

               ir_variable *const r07D7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07D7, rshift(r06F7, body.constant(int(16))), 0x01));

               ir_variable *const r07D8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07D8, bit_and(r078E, body.constant(65535u)), 0x01));

               ir_variable *const r07D9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07D9, rshift(r078E, body.constant(int(16))), 0x01));

               ir_variable *const r07DA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07DA, mul(r07D7, r07D8), 0x01));

               ir_expression *const r07DB = mul(r07D6, r07D9);
               body.emit(assign(r07D4, add(r07DB, r07DA), 0x01));

               ir_expression *const r07DC = mul(r07D7, r07D9);
               ir_expression *const r07DD = less(r07D4, r07DA);
               ir_expression *const r07DE = expr(ir_unop_b2i, r07DD);
               ir_expression *const r07DF = expr(ir_unop_i2u, r07DE);
               ir_expression *const r07E0 = lshift(r07DF, body.constant(int(16)));
               ir_expression *const r07E1 = rshift(r07D4, body.constant(int(16)));
               ir_expression *const r07E2 = add(r07E0, r07E1);
               body.emit(assign(r07D3, add(r07DC, r07E2), 0x01));

               body.emit(assign(r07D4, lshift(r07D4, body.constant(int(16))), 0x01));

               ir_expression *const r07E3 = mul(r07D6, r07D8);
               body.emit(assign(r07D5, add(r07E3, r07D4), 0x01));

               ir_expression *const r07E4 = less(r07D5, r07D4);
               ir_expression *const r07E5 = expr(ir_unop_b2i, r07E4);
               ir_expression *const r07E6 = expr(ir_unop_i2u, r07E5);
               body.emit(assign(r07D3, add(r07D3, r07E6), 0x01));

               ir_variable *const r07E7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07E7, add(r07D5, r07B9), 0x01));

               ir_variable *const r07E8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r07E9 = less(r07E7, r07D5);
               ir_expression *const r07EA = expr(ir_unop_b2i, r07E9);
               ir_expression *const r07EB = expr(ir_unop_i2u, r07EA);
               ir_expression *const r07EC = add(r07D3, r07EB);
               body.emit(assign(r07E8, add(r07CE, r07EC), 0x01));

               ir_variable *const r07ED = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r07EE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r07EE, add(r07E8, r06F8), 0x01));

               ir_expression *const r07EF = less(r07CE, r07BC);
               ir_expression *const r07F0 = expr(ir_unop_b2i, r07EF);
               ir_expression *const r07F1 = expr(ir_unop_i2u, r07F0);
               ir_expression *const r07F2 = add(r07BA, r07F1);
               ir_expression *const r07F3 = less(r07E8, r07CE);
               ir_expression *const r07F4 = expr(ir_unop_b2i, r07F3);
               ir_expression *const r07F5 = expr(ir_unop_i2u, r07F4);
               ir_expression *const r07F6 = add(r07F2, r07F5);
               ir_expression *const r07F7 = add(r07F6, r06F7);
               ir_expression *const r07F8 = less(r07EE, r07E8);
               ir_expression *const r07F9 = expr(ir_unop_b2i, r07F8);
               ir_expression *const r07FA = expr(ir_unop_i2u, r07F9);
               body.emit(assign(r07ED, add(r07F7, r07FA), 0x01));

               body.emit(assign(r06FC, r07ED, 0x01));

               body.emit(assign(r06FB, r07EE, 0x01));

               ir_expression *const r07FB = nequal(r0793, body.constant(0u));
               ir_expression *const r07FC = expr(ir_unop_b2i, r07FB);
               ir_expression *const r07FD = expr(ir_unop_i2u, r07FC);
               body.emit(assign(r06FA, bit_or(r07E7, r07FD), 0x01));

               /* IF CONDITION */
               ir_expression *const r07FF = gequal(r07ED, body.constant(2097152u));
               ir_if *f07FE = new(mem_ctx) ir_if(operand(r07FF).val);
               exec_list *const f07FE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f07FE->then_instructions;

                  body.emit(assign(r06FC, rshift(r07ED, body.constant(int(1))), 0x01));

                  ir_expression *const r0800 = lshift(r07ED, body.constant(int(31)));
                  ir_expression *const r0801 = rshift(r07EE, body.constant(int(1)));
                  body.emit(assign(r06FB, bit_or(r0800, r0801), 0x01));

                  ir_expression *const r0802 = lshift(r07EE, body.constant(int(31)));
                  ir_expression *const r0803 = nequal(r06FA, body.constant(0u));
                  ir_expression *const r0804 = expr(ir_unop_b2i, r0803);
                  ir_expression *const r0805 = expr(ir_unop_i2u, r0804);
                  body.emit(assign(r06FA, bit_or(r0802, r0805), 0x01));

                  body.emit(assign(r06F9, add(r06F9, body.constant(int(1))), 0x01));


               body.instructions = f07FE_parent_instructions;
               body.emit(f07FE);

               /* END IF */

               ir_variable *const r0806 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0806, r06F9, 0x01));

               ir_variable *const r0807 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r0807, r06FC, 0x01));

               ir_variable *const r0808 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0808, r06FB, 0x01));

               ir_variable *const r0809 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r0809, r06FA, 0x01));

               ir_variable *const r080A = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r080A, body.constant(true), 0x01));

               ir_variable *const r080B = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r080C = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r080C);
               ir_expression *const r080D = expr(ir_unop_u2i, r06FA);
               body.emit(assign(r080C, less(r080D, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r080F = gequal(r06F9, body.constant(int(2045)));
               ir_if *f080E = new(mem_ctx) ir_if(operand(r080F).val);
               exec_list *const f080E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f080E->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0811 = less(body.constant(int(2045)), r06F9);
                  ir_expression *const r0812 = equal(r06F9, body.constant(int(2045)));
                  ir_expression *const r0813 = equal(body.constant(2097151u), r06FC);
                  ir_expression *const r0814 = equal(body.constant(4294967295u), r06FB);
                  ir_expression *const r0815 = logic_and(r0813, r0814);
                  ir_expression *const r0816 = logic_and(r0812, r0815);
                  ir_expression *const r0817 = logic_and(r0816, r080C);
                  ir_expression *const r0818 = logic_or(r0811, r0817);
                  ir_if *f0810 = new(mem_ctx) ir_if(operand(r0818).val);
                  exec_list *const f0810_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0810->then_instructions;

                     ir_variable *const r0819 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0819);
                     ir_expression *const r081A = lshift(r06F2, body.constant(int(31)));
                     body.emit(assign(r0819, add(r081A, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r0819, body.constant(0u), 0x01));

                     body.emit(assign(r080B, r0819, 0x03));

                     body.emit(assign(r080A, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0810->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r081C = less(r06F9, body.constant(int(0)));
                     ir_if *f081B = new(mem_ctx) ir_if(operand(r081C).val);
                     exec_list *const f081B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f081B->then_instructions;

                        ir_variable *const r081D = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r081D, neg(r06F9), 0x01));

                        ir_variable *const r081E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r081E);
                        ir_variable *const r081F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0820 = neg(r081D);
                        body.emit(assign(r081F, bit_and(r0820, body.constant(int(31))), 0x01));

                        ir_variable *const r0821 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0822 = less(r081D, body.constant(int(32)));
                        ir_expression *const r0823 = bit_or(r06FA, r06FB);
                        body.emit(assign(r0821, expr(ir_triop_csel, r0822, r06FA, r0823), 0x01));

                        ir_expression *const r0824 = less(r081D, body.constant(int(32)));
                        ir_expression *const r0825 = lshift(r06FB, r081F);
                        ir_expression *const r0826 = less(r081D, body.constant(int(64)));
                        ir_expression *const r0827 = lshift(r06FC, r081F);
                        ir_expression *const r0828 = equal(r081D, body.constant(int(64)));
                        ir_expression *const r0829 = nequal(r06FC, body.constant(0u));
                        ir_expression *const r082A = expr(ir_unop_b2i, r0829);
                        ir_expression *const r082B = expr(ir_unop_i2u, r082A);
                        ir_expression *const r082C = expr(ir_triop_csel, r0828, r06FC, r082B);
                        ir_expression *const r082D = expr(ir_triop_csel, r0826, r0827, r082C);
                        ir_expression *const r082E = expr(ir_triop_csel, r0824, r0825, r082D);
                        ir_expression *const r082F = nequal(r0821, body.constant(0u));
                        ir_expression *const r0830 = expr(ir_unop_b2i, r082F);
                        ir_expression *const r0831 = expr(ir_unop_i2u, r0830);
                        body.emit(assign(r081E, bit_or(r082E, r0831), 0x01));

                        ir_variable *const r0832 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0833 = equal(r081D, body.constant(int(0)));
                        ir_expression *const r0834 = equal(r081D, body.constant(int(32)));
                        ir_expression *const r0835 = expr(ir_triop_csel, r0834, r06FB, r081E);
                        body.emit(assign(r0832, expr(ir_triop_csel, r0833, r0821, r0835), 0x01));

                        body.emit(assign(r081E, r0832, 0x01));

                        ir_expression *const r0836 = equal(r081D, body.constant(int(0)));
                        ir_expression *const r0837 = equal(r081D, body.constant(int(32)));
                        ir_expression *const r0838 = less(r081D, body.constant(int(32)));
                        ir_expression *const r0839 = rshift(r06FC, r081D);
                        ir_expression *const r083A = expr(ir_triop_csel, r0838, r0839, body.constant(0u));
                        ir_expression *const r083B = expr(ir_triop_csel, r0837, body.constant(0u), r083A);
                        body.emit(assign(r0807, expr(ir_triop_csel, r0836, r06FC, r083B), 0x01));

                        ir_expression *const r083C = equal(r081D, body.constant(int(0)));
                        ir_expression *const r083D = equal(r081D, body.constant(int(32)));
                        ir_expression *const r083E = less(r081D, body.constant(int(32)));
                        ir_expression *const r083F = lshift(r06FC, r081F);
                        ir_expression *const r0840 = rshift(r06FB, r081D);
                        ir_expression *const r0841 = bit_or(r083F, r0840);
                        ir_expression *const r0842 = less(r081D, body.constant(int(64)));
                        ir_expression *const r0843 = bit_and(r081D, body.constant(int(31)));
                        ir_expression *const r0844 = rshift(r06FC, r0843);
                        ir_expression *const r0845 = expr(ir_triop_csel, r0842, r0844, body.constant(0u));
                        ir_expression *const r0846 = expr(ir_triop_csel, r083E, r0841, r0845);
                        ir_expression *const r0847 = expr(ir_triop_csel, r083D, r06FC, r0846);
                        body.emit(assign(r0808, expr(ir_triop_csel, r083C, r06FB, r0847), 0x01));

                        body.emit(assign(r0809, r0832, 0x01));

                        body.emit(assign(r0806, body.constant(int(0)), 0x01));

                        body.emit(assign(r080C, less(r0832, body.constant(0u)), 0x01));


                     body.instructions = f081B_parent_instructions;
                     body.emit(f081B);

                     /* END IF */


                  body.instructions = f0810_parent_instructions;
                  body.emit(f0810);

                  /* END IF */


               body.instructions = f080E_parent_instructions;
               body.emit(f080E);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0848 = new(mem_ctx) ir_if(operand(r080A).val);
               exec_list *const f0848_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0848->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0849 = new(mem_ctx) ir_if(operand(r080C).val);
                  exec_list *const f0849_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0849->then_instructions;

                     ir_variable *const r084A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r084A, add(r0808, body.constant(1u)), 0x01));

                     ir_expression *const r084B = less(r084A, r0808);
                     ir_expression *const r084C = expr(ir_unop_b2i, r084B);
                     ir_expression *const r084D = expr(ir_unop_i2u, r084C);
                     body.emit(assign(r0807, add(r0807, r084D), 0x01));

                     ir_expression *const r084E = equal(r0809, body.constant(0u));
                     ir_expression *const r084F = expr(ir_unop_b2i, r084E);
                     ir_expression *const r0850 = expr(ir_unop_i2u, r084F);
                     ir_expression *const r0851 = add(r0809, r0850);
                     ir_expression *const r0852 = bit_and(r0851, body.constant(1u));
                     ir_expression *const r0853 = expr(ir_unop_bit_not, r0852);
                     body.emit(assign(r0808, bit_and(r084A, r0853), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0849->else_instructions;

                     ir_expression *const r0854 = bit_or(r0807, r0808);
                     ir_expression *const r0855 = equal(r0854, body.constant(0u));
                     body.emit(assign(r0806, expr(ir_triop_csel, r0855, body.constant(int(0)), r0806), 0x01));


                  body.instructions = f0849_parent_instructions;
                  body.emit(f0849);

                  /* END IF */

                  ir_variable *const r0856 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0856);
                  ir_expression *const r0857 = lshift(r06F2, body.constant(int(31)));
                  ir_expression *const r0858 = expr(ir_unop_i2u, r0806);
                  ir_expression *const r0859 = lshift(r0858, body.constant(int(20)));
                  ir_expression *const r085A = add(r0857, r0859);
                  body.emit(assign(r0856, add(r085A, r0807), 0x02));

                  body.emit(assign(r0856, r0808, 0x01));

                  body.emit(assign(r080B, r0856, 0x03));

                  body.emit(assign(r080A, body.constant(false), 0x01));


               body.instructions = f0848_parent_instructions;
               body.emit(f0848);

               /* END IF */

               body.emit(assign(r06F1, r080B, 0x03));

               body.emit(assign(r06F0, body.constant(false), 0x01));


            body.instructions = f078B_parent_instructions;
            body.emit(f078B);

            /* END IF */


         body.instructions = f076C_parent_instructions;
         body.emit(f076C);

         /* END IF */


      body.instructions = f072E_parent_instructions;
      body.emit(f072E);

      /* END IF */


   body.instructions = f0709_parent_instructions;
   body.emit(f0709);

   /* END IF */

   body.emit(ret(r06F1));

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

   ir_variable *const r085B = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r085B);
   ir_variable *const r085C = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r085C);
   ir_variable *const r085D = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r085D);
   ir_variable *const r085E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r085E);
   ir_variable *const r085F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r085F);
   ir_expression *const r0860 = equal(r085D, body.constant(int(0)));
   ir_expression *const r0861 = less(r085D, body.constant(int(32)));
   ir_expression *const r0862 = neg(r085D);
   ir_expression *const r0863 = bit_and(r0862, body.constant(int(31)));
   ir_expression *const r0864 = lshift(r085B, r0863);
   ir_expression *const r0865 = rshift(r085C, r085D);
   ir_expression *const r0866 = bit_or(r0864, r0865);
   ir_expression *const r0867 = less(r085D, body.constant(int(64)));
   ir_expression *const r0868 = bit_and(r085D, body.constant(int(31)));
   ir_expression *const r0869 = rshift(r085B, r0868);
   ir_expression *const r086A = expr(ir_triop_csel, r0867, r0869, body.constant(0u));
   ir_expression *const r086B = expr(ir_triop_csel, r0861, r0866, r086A);
   body.emit(assign(r085F, expr(ir_triop_csel, r0860, r085B, r086B), 0x01));

   ir_expression *const r086C = equal(r085D, body.constant(int(0)));
   ir_expression *const r086D = less(r085D, body.constant(int(32)));
   ir_expression *const r086E = rshift(r085B, r085D);
   ir_expression *const r086F = expr(ir_triop_csel, r086D, r086E, body.constant(0u));
   body.emit(assign(r085E, expr(ir_triop_csel, r086C, r085B, r086F), 0x01));

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

   ir_variable *const r0870 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0870);
   ir_variable *const r0871 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0872 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0872);
   ir_variable *const r0873 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0873);
   body.emit(assign(r0873, swizzle_x(r0870), 0x01));

   ir_variable *const r0874 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0874, bit_and(swizzle_y(r0870), body.constant(1048575u)), 0x01));

   body.emit(assign(r0872, r0874, 0x01));

   ir_variable *const r0875 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0876 = rshift(swizzle_y(r0870), body.constant(int(20)));
   ir_expression *const r0877 = bit_and(r0876, body.constant(2047u));
   body.emit(assign(r0875, expr(ir_unop_u2i, r0877), 0x01));

   ir_variable *const r0878 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0878, rshift(swizzle_y(r0870), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r087A = nequal(r0878, body.constant(0u));
   ir_if *f0879 = new(mem_ctx) ir_if(operand(r087A).val);
   exec_list *const f0879_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0879->then_instructions;

      body.emit(assign(r0871, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0879->else_instructions;

      /* IF CONDITION */
      ir_expression *const r087C = equal(r0875, body.constant(int(2047)));
      ir_expression *const r087D = bit_or(r0874, swizzle_x(r0870));
      ir_expression *const r087E = nequal(r087D, body.constant(0u));
      ir_expression *const r087F = logic_and(r087C, r087E);
      ir_if *f087B = new(mem_ctx) ir_if(operand(r087F).val);
      exec_list *const f087B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f087B->then_instructions;

         body.emit(assign(r0871, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f087B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0881 = nequal(r0875, body.constant(int(0)));
         ir_if *f0880 = new(mem_ctx) ir_if(operand(r0881).val);
         exec_list *const f0880_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0880->then_instructions;

            body.emit(assign(r0872, bit_or(r0874, body.constant(1048576u)), 0x01));


         body.instructions = f0880_parent_instructions;
         body.emit(f0880);

         /* END IF */

         ir_variable *const r0882 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0882, sub(body.constant(int(1063)), r0875), 0x01));

         /* IF CONDITION */
         ir_expression *const r0884 = less(body.constant(int(0)), r0882);
         ir_if *f0883 = new(mem_ctx) ir_if(operand(r0884).val);
         exec_list *const f0883_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0883->then_instructions;

            ir_variable *const r0885 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0885);
            ir_variable *const r0886 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0887 = neg(r0882);
            body.emit(assign(r0886, bit_and(r0887, body.constant(int(31))), 0x01));

            ir_expression *const r0888 = bit_or(r0872, swizzle_x(r0870));
            ir_expression *const r0889 = nequal(r0888, body.constant(0u));
            ir_expression *const r088A = expr(ir_unop_b2i, r0889);
            body.emit(assign(r0885, expr(ir_unop_i2u, r088A), 0x01));

            ir_variable *const r088B = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r088C = equal(r0882, body.constant(int(0)));
            ir_expression *const r088D = less(r0882, body.constant(int(32)));
            ir_expression *const r088E = lshift(r0872, r0886);
            ir_expression *const r088F = rshift(swizzle_x(r0870), r0882);
            ir_expression *const r0890 = bit_or(r088E, r088F);
            ir_expression *const r0891 = lshift(swizzle_x(r0870), r0886);
            ir_expression *const r0892 = nequal(r0891, body.constant(0u));
            ir_expression *const r0893 = expr(ir_unop_b2i, r0892);
            ir_expression *const r0894 = expr(ir_unop_i2u, r0893);
            ir_expression *const r0895 = bit_or(r0890, r0894);
            ir_expression *const r0896 = equal(r0882, body.constant(int(32)));
            ir_expression *const r0897 = nequal(swizzle_x(r0870), body.constant(0u));
            ir_expression *const r0898 = expr(ir_unop_b2i, r0897);
            ir_expression *const r0899 = expr(ir_unop_i2u, r0898);
            ir_expression *const r089A = bit_or(r0872, r0899);
            ir_expression *const r089B = less(r0882, body.constant(int(64)));
            ir_expression *const r089C = bit_and(r0882, body.constant(int(31)));
            ir_expression *const r089D = rshift(r0872, r089C);
            ir_expression *const r089E = lshift(r0872, r0886);
            ir_expression *const r089F = bit_or(r089E, swizzle_x(r0870));
            ir_expression *const r08A0 = nequal(r089F, body.constant(0u));
            ir_expression *const r08A1 = expr(ir_unop_b2i, r08A0);
            ir_expression *const r08A2 = expr(ir_unop_i2u, r08A1);
            ir_expression *const r08A3 = bit_or(r089D, r08A2);
            ir_expression *const r08A4 = expr(ir_triop_csel, r089B, r08A3, r0885);
            ir_expression *const r08A5 = expr(ir_triop_csel, r0896, r089A, r08A4);
            ir_expression *const r08A6 = expr(ir_triop_csel, r088D, r0895, r08A5);
            body.emit(assign(r088B, expr(ir_triop_csel, r088C, swizzle_x(r0870), r08A6), 0x01));

            body.emit(assign(r0885, r088B, 0x01));

            ir_expression *const r08A7 = less(r0882, body.constant(int(32)));
            ir_expression *const r08A8 = rshift(r0872, r0882);
            ir_expression *const r08A9 = equal(r0882, body.constant(int(0)));
            ir_expression *const r08AA = expr(ir_triop_csel, r08A9, r0872, body.constant(0u));
            body.emit(assign(r0872, expr(ir_triop_csel, r08A7, r08A8, r08AA), 0x01));

            body.emit(assign(r0873, r088B, 0x01));


         body.instructions = f0883_parent_instructions;
         body.emit(f0883);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r08AC = bit_and(r0872, body.constant(4294963200u));
         ir_expression *const r08AD = nequal(r08AC, body.constant(0u));
         ir_if *f08AB = new(mem_ctx) ir_if(operand(r08AD).val);
         exec_list *const f08AB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08AB->then_instructions;

            ir_variable *const r08AE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r08B0 = nequal(r0878, body.constant(0u));
            ir_if *f08AF = new(mem_ctx) ir_if(operand(r08B0).val);
            exec_list *const f08AF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08AF->then_instructions;

               body.emit(assign(r08AE, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08AF->else_instructions;

               body.emit(assign(r08AE, body.constant(4294967295u), 0x01));


            body.instructions = f08AF_parent_instructions;
            body.emit(f08AF);

            /* END IF */

            body.emit(assign(r0871, r08AE, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f08AB->else_instructions;

            ir_variable *const r08B1 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r08B2 = lshift(r0872, body.constant(int(20)));
            ir_expression *const r08B3 = rshift(r0873, body.constant(int(12)));
            body.emit(assign(r08B1, bit_or(r08B2, r08B3), 0x01));

            /* IF CONDITION */
            ir_expression *const r08B5 = nequal(r0878, body.constant(0u));
            ir_expression *const r08B6 = nequal(r08B1, body.constant(0u));
            ir_expression *const r08B7 = logic_and(r08B5, r08B6);
            ir_if *f08B4 = new(mem_ctx) ir_if(operand(r08B7).val);
            exec_list *const f08B4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08B4->then_instructions;

               ir_variable *const r08B8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r08BA = nequal(r0878, body.constant(0u));
               ir_if *f08B9 = new(mem_ctx) ir_if(operand(r08BA).val);
               exec_list *const f08B9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08B9->then_instructions;

                  body.emit(assign(r08B8, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08B9->else_instructions;

                  body.emit(assign(r08B8, body.constant(4294967295u), 0x01));


               body.instructions = f08B9_parent_instructions;
               body.emit(f08B9);

               /* END IF */

               body.emit(assign(r0871, r08B8, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08B4->else_instructions;

               body.emit(assign(r0871, r08B1, 0x01));


            body.instructions = f08B4_parent_instructions;
            body.emit(f08B4);

            /* END IF */


         body.instructions = f08AB_parent_instructions;
         body.emit(f08AB);

         /* END IF */


      body.instructions = f087B_parent_instructions;
      body.emit(f087B);

      /* END IF */


   body.instructions = f0879_parent_instructions;
   body.emit(f0879);

   /* END IF */

   body.emit(ret(r0871));

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

   ir_variable *const r08BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r08BB);
   ir_variable *const r08BC = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r08BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r08BD);
   ir_variable *const r08BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r08BE);
   /* IF CONDITION */
   ir_expression *const r08C0 = equal(r08BB, body.constant(0u));
   ir_if *f08BF = new(mem_ctx) ir_if(operand(r08C0).val);
   exec_list *const f08BF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08BF->then_instructions;

      body.emit(assign(r08BC, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f08BF->else_instructions;

      ir_variable *const r08C1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r08C2 = equal(r08BB, body.constant(0u));
      ir_expression *const r08C3 = expr(ir_unop_find_msb, r08BB);
      ir_expression *const r08C4 = sub(body.constant(int(31)), r08C3);
      ir_expression *const r08C5 = expr(ir_triop_csel, r08C2, body.constant(int(32)), r08C4);
      body.emit(assign(r08C1, add(r08C5, body.constant(int(21))), 0x01));

      body.emit(assign(r08BE, body.constant(0u), 0x01));

      body.emit(assign(r08BD, body.constant(0u), 0x01));

      ir_variable *const r08C6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r08C7 = neg(r08C1);
      body.emit(assign(r08C6, bit_and(r08C7, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r08C9 = equal(r08C1, body.constant(int(0)));
      ir_if *f08C8 = new(mem_ctx) ir_if(operand(r08C9).val);
      exec_list *const f08C8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08C8->then_instructions;

         body.emit(assign(r08BE, body.constant(0u), 0x01));

         body.emit(assign(r08BD, r08BB, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08C8->else_instructions;

         /* IF CONDITION */
         ir_expression *const r08CB = less(r08C1, body.constant(int(32)));
         ir_if *f08CA = new(mem_ctx) ir_if(operand(r08CB).val);
         exec_list *const f08CA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08CA->then_instructions;

            body.emit(assign(r08BE, rshift(r08BB, r08C6), 0x01));

            body.emit(assign(r08BD, lshift(r08BB, r08C1), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f08CA->else_instructions;

            ir_variable *const r08CC = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r08CE = less(r08C1, body.constant(int(64)));
            ir_if *f08CD = new(mem_ctx) ir_if(operand(r08CE).val);
            exec_list *const f08CD_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08CD->then_instructions;

               ir_expression *const r08CF = add(r08C1, body.constant(int(-32)));
               body.emit(assign(r08CC, lshift(r08BB, r08CF), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08CD->else_instructions;

               body.emit(assign(r08CC, body.constant(0u), 0x01));


            body.instructions = f08CD_parent_instructions;
            body.emit(f08CD);

            /* END IF */

            body.emit(assign(r08BE, r08CC, 0x01));

            body.emit(assign(r08BD, body.constant(0u), 0x01));


         body.instructions = f08CA_parent_instructions;
         body.emit(f08CA);

         /* END IF */


      body.instructions = f08C8_parent_instructions;
      body.emit(f08C8);

      /* END IF */

      ir_variable *const r08D0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r08D0);
      ir_expression *const r08D1 = sub(body.constant(int(1074)), r08C1);
      ir_expression *const r08D2 = expr(ir_unop_i2u, r08D1);
      ir_expression *const r08D3 = lshift(r08D2, body.constant(int(20)));
      body.emit(assign(r08D0, add(r08D3, r08BE), 0x02));

      body.emit(assign(r08D0, r08BD, 0x01));

      body.emit(assign(r08BC, r08D0, 0x03));


   body.instructions = f08BF_parent_instructions;
   body.emit(f08BF);

   /* END IF */

   body.emit(ret(r08BC));

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

   ir_variable *const r08D4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r08D4);
   ir_variable *const r08D5 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r08D5, body.constant(true), 0x01));

   ir_variable *const r08D6 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r08D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r08D7);
   ir_variable *const r08D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r08D8);
   ir_variable *const r08D9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r08D9);
   ir_variable *const r08DA = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r08DA, bit_and(swizzle_y(r08D4), body.constant(1048575u)), 0x01));

   body.emit(assign(r08D9, r08DA, 0x01));

   ir_variable *const r08DB = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r08DC = rshift(swizzle_y(r08D4), body.constant(int(20)));
   ir_expression *const r08DD = bit_and(r08DC, body.constant(2047u));
   body.emit(assign(r08DB, expr(ir_unop_u2i, r08DD), 0x01));

   body.emit(assign(r08D8, rshift(swizzle_y(r08D4), body.constant(int(31))), 0x01));

   body.emit(assign(r08D7, body.constant(0u), 0x01));

   ir_variable *const r08DE = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r08DE, add(r08DB, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r08E0 = gequal(r08DE, body.constant(int(0)));
   ir_if *f08DF = new(mem_ctx) ir_if(operand(r08E0).val);
   exec_list *const f08DF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08DF->then_instructions;

      /* IF CONDITION */
      ir_expression *const r08E2 = less(body.constant(int(1054)), r08DB);
      ir_if *f08E1 = new(mem_ctx) ir_if(operand(r08E2).val);
      exec_list *const f08E1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08E1->then_instructions;

         /* IF CONDITION */
         ir_expression *const r08E4 = equal(r08DB, body.constant(int(2047)));
         ir_expression *const r08E5 = bit_or(r08DA, swizzle_x(r08D4));
         ir_expression *const r08E6 = expr(ir_unop_u2i, r08E5);
         ir_expression *const r08E7 = expr(ir_unop_i2b, r08E6);
         ir_expression *const r08E8 = logic_and(r08E4, r08E7);
         ir_if *f08E3 = new(mem_ctx) ir_if(operand(r08E8).val);
         exec_list *const f08E3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08E3->then_instructions;

            body.emit(assign(r08D8, body.constant(0u), 0x01));


         body.instructions = f08E3_parent_instructions;
         body.emit(f08E3);

         /* END IF */

         ir_variable *const r08E9 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r08EB = expr(ir_unop_u2i, r08D8);
         ir_expression *const r08EC = expr(ir_unop_i2b, r08EB);
         ir_if *f08EA = new(mem_ctx) ir_if(operand(r08EC).val);
         exec_list *const f08EA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08EA->then_instructions;

            body.emit(assign(r08E9, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f08EA->else_instructions;

            body.emit(assign(r08E9, body.constant(int(2147483647)), 0x01));


         body.instructions = f08EA_parent_instructions;
         body.emit(f08EA);

         /* END IF */

         body.emit(assign(r08D6, r08E9, 0x01));

         body.emit(assign(r08D5, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08E1->else_instructions;

         ir_variable *const r08ED = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r08ED, bit_or(r08DA, body.constant(1048576u)), 0x01));

         ir_expression *const r08EE = equal(r08DE, body.constant(int(0)));
         ir_expression *const r08EF = lshift(r08ED, r08DE);
         ir_expression *const r08F0 = neg(r08DE);
         ir_expression *const r08F1 = bit_and(r08F0, body.constant(int(31)));
         ir_expression *const r08F2 = rshift(swizzle_x(r08D4), r08F1);
         ir_expression *const r08F3 = bit_or(r08EF, r08F2);
         body.emit(assign(r08D7, expr(ir_triop_csel, r08EE, r08ED, r08F3), 0x01));


      body.instructions = f08E1_parent_instructions;
      body.emit(f08E1);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f08DF->else_instructions;

      /* IF CONDITION */
      ir_expression *const r08F5 = less(r08DB, body.constant(int(1023)));
      ir_if *f08F4 = new(mem_ctx) ir_if(operand(r08F5).val);
      exec_list *const f08F4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08F4->then_instructions;

         body.emit(assign(r08D6, body.constant(int(0)), 0x01));

         body.emit(assign(r08D5, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08F4->else_instructions;

         body.emit(assign(r08D9, bit_or(r08DA, body.constant(1048576u)), 0x01));

         ir_expression *const r08F6 = neg(r08DE);
         body.emit(assign(r08D7, rshift(r08D9, r08F6), 0x01));


      body.instructions = f08F4_parent_instructions;
      body.emit(f08F4);

      /* END IF */


   body.instructions = f08DF_parent_instructions;
   body.emit(f08DF);

   /* END IF */

   /* IF CONDITION */
   ir_if *f08F7 = new(mem_ctx) ir_if(operand(r08D5).val);
   exec_list *const f08F7_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f08F7->then_instructions;

      ir_variable *const r08F8 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r08FA = nequal(r08D8, body.constant(0u));
      ir_if *f08F9 = new(mem_ctx) ir_if(operand(r08FA).val);
      exec_list *const f08F9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08F9->then_instructions;

         ir_expression *const r08FB = expr(ir_unop_u2i, r08D7);
         body.emit(assign(r08F8, neg(r08FB), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08F9->else_instructions;

         body.emit(assign(r08F8, expr(ir_unop_u2i, r08D7), 0x01));


      body.instructions = f08F9_parent_instructions;
      body.emit(f08F9);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r08FD = less(r08F8, body.constant(int(0)));
      ir_expression *const r08FE = expr(ir_unop_b2i, r08FD);
      ir_expression *const r08FF = expr(ir_unop_i2u, r08FE);
      ir_expression *const r0900 = bit_xor(r08D8, r08FF);
      ir_expression *const r0901 = expr(ir_unop_u2i, r0900);
      ir_expression *const r0902 = expr(ir_unop_i2b, r0901);
      ir_expression *const r0903 = expr(ir_unop_i2b, r08F8);
      ir_expression *const r0904 = logic_and(r0902, r0903);
      ir_if *f08FC = new(mem_ctx) ir_if(operand(r0904).val);
      exec_list *const f08FC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08FC->then_instructions;

         ir_variable *const r0905 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0907 = expr(ir_unop_u2i, r08D8);
         ir_expression *const r0908 = expr(ir_unop_i2b, r0907);
         ir_if *f0906 = new(mem_ctx) ir_if(operand(r0908).val);
         exec_list *const f0906_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0906->then_instructions;

            body.emit(assign(r0905, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0906->else_instructions;

            body.emit(assign(r0905, body.constant(int(2147483647)), 0x01));


         body.instructions = f0906_parent_instructions;
         body.emit(f0906);

         /* END IF */

         body.emit(assign(r08D6, r0905, 0x01));

         body.emit(assign(r08D5, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08FC->else_instructions;

         body.emit(assign(r08D6, r08F8, 0x01));

         body.emit(assign(r08D5, body.constant(false), 0x01));


      body.instructions = f08FC_parent_instructions;
      body.emit(f08FC);

      /* END IF */


   body.instructions = f08F7_parent_instructions;
   body.emit(f08F7);

   /* END IF */

   body.emit(ret(r08D6));

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

   ir_variable *const r0909 = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0909);
   ir_variable *const r090A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r090B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r090B);
   ir_variable *const r090C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r090C);
   ir_variable *const r090D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r090D);
   body.emit(assign(r090D, body.constant(0u), 0x01));

   body.emit(assign(r090C, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r090F = equal(r0909, body.constant(int(0)));
   ir_if *f090E = new(mem_ctx) ir_if(operand(r090F).val);
   exec_list *const f090E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f090E->then_instructions;

      ir_variable *const r0910 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0910);
      body.emit(assign(r0910, body.constant(0u), 0x02));

      body.emit(assign(r0910, body.constant(0u), 0x01));

      body.emit(assign(r090A, r0910, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f090E->else_instructions;

      ir_expression *const r0911 = less(r0909, body.constant(int(0)));
      ir_expression *const r0912 = expr(ir_unop_b2i, r0911);
      body.emit(assign(r090B, expr(ir_unop_i2u, r0912), 0x01));

      ir_variable *const r0913 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0915 = less(r0909, body.constant(int(0)));
      ir_if *f0914 = new(mem_ctx) ir_if(operand(r0915).val);
      exec_list *const f0914_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0914->then_instructions;

         ir_expression *const r0916 = neg(r0909);
         body.emit(assign(r0913, expr(ir_unop_i2u, r0916), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0914->else_instructions;

         body.emit(assign(r0913, expr(ir_unop_i2u, r0909), 0x01));


      body.instructions = f0914_parent_instructions;
      body.emit(f0914);

      /* END IF */

      ir_variable *const r0917 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0918 = equal(r0913, body.constant(0u));
      ir_expression *const r0919 = expr(ir_unop_find_msb, r0913);
      ir_expression *const r091A = sub(body.constant(int(31)), r0919);
      ir_expression *const r091B = expr(ir_triop_csel, r0918, body.constant(int(32)), r091A);
      body.emit(assign(r0917, add(r091B, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r091D = gequal(r0917, body.constant(int(0)));
      ir_if *f091C = new(mem_ctx) ir_if(operand(r091D).val);
      exec_list *const f091C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f091C->then_instructions;

         body.emit(assign(r090D, lshift(r0913, r0917), 0x01));

         body.emit(assign(r090C, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f091C->else_instructions;

         ir_variable *const r091E = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r091E, neg(r0917), 0x01));

         ir_expression *const r091F = equal(r091E, body.constant(int(0)));
         ir_expression *const r0920 = less(r091E, body.constant(int(32)));
         ir_expression *const r0921 = rshift(r0913, r091E);
         ir_expression *const r0922 = expr(ir_triop_csel, r0920, r0921, body.constant(0u));
         body.emit(assign(r090D, expr(ir_triop_csel, r091F, r0913, r0922), 0x01));

         ir_expression *const r0923 = equal(r091E, body.constant(int(0)));
         ir_expression *const r0924 = less(r091E, body.constant(int(32)));
         ir_expression *const r0925 = neg(r091E);
         ir_expression *const r0926 = bit_and(r0925, body.constant(int(31)));
         ir_expression *const r0927 = lshift(r0913, r0926);
         ir_expression *const r0928 = bit_or(r0927, body.constant(0u));
         ir_expression *const r0929 = less(r091E, body.constant(int(64)));
         ir_expression *const r092A = bit_and(r091E, body.constant(int(31)));
         ir_expression *const r092B = rshift(r0913, r092A);
         ir_expression *const r092C = expr(ir_triop_csel, r0929, r092B, body.constant(0u));
         ir_expression *const r092D = expr(ir_triop_csel, r0924, r0928, r092C);
         body.emit(assign(r090C, expr(ir_triop_csel, r0923, r0913, r092D), 0x01));


      body.instructions = f091C_parent_instructions;
      body.emit(f091C);

      /* END IF */

      ir_variable *const r092E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r092E);
      ir_expression *const r092F = lshift(r090B, body.constant(int(31)));
      ir_expression *const r0930 = sub(body.constant(int(1042)), r0917);
      ir_expression *const r0931 = expr(ir_unop_i2u, r0930);
      ir_expression *const r0932 = lshift(r0931, body.constant(int(20)));
      ir_expression *const r0933 = add(r092F, r0932);
      body.emit(assign(r092E, add(r0933, r090D), 0x02));

      body.emit(assign(r092E, r090C, 0x01));

      body.emit(assign(r090A, r092E, 0x03));


   body.instructions = f090E_parent_instructions;
   body.emit(f090E);

   /* END IF */

   body.emit(ret(r090A));

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

   ir_variable *const r0934 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0934);
   ir_variable *const r0935 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0935);
   ir_variable *const r0936 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0936);
   ir_variable *const r0937 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r0938 = lshift(r0934, body.constant(int(31)));
   ir_expression *const r0939 = expr(ir_unop_i2u, r0935);
   ir_expression *const r093A = lshift(r0939, body.constant(int(23)));
   ir_expression *const r093B = add(r0938, r093A);
   ir_expression *const r093C = add(r093B, r0936);
   body.emit(assign(r0937, expr(ir_unop_bitcast_u2f, r093C), 0x01));

   body.emit(ret(r0937));

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

   ir_variable *const r093D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r093D);
   ir_variable *const r093E = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r093E);
   ir_variable *const r093F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r093F);
   ir_variable *const r0940 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0940, body.constant(true), 0x01));

   ir_variable *const r0941 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0942 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0942);
   ir_expression *const r0943 = bit_and(r093F, body.constant(127u));
   body.emit(assign(r0942, expr(ir_unop_u2i, r0943), 0x01));

   /* IF CONDITION */
   ir_expression *const r0945 = expr(ir_unop_i2u, r093E);
   ir_expression *const r0946 = gequal(r0945, body.constant(253u));
   ir_if *f0944 = new(mem_ctx) ir_if(operand(r0946).val);
   exec_list *const f0944_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0944->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0948 = less(body.constant(int(253)), r093E);
      ir_expression *const r0949 = equal(r093E, body.constant(int(253)));
      ir_expression *const r094A = expr(ir_unop_u2i, r093F);
      ir_expression *const r094B = less(r094A, body.constant(int(-64)));
      ir_expression *const r094C = logic_and(r0949, r094B);
      ir_expression *const r094D = logic_or(r0948, r094C);
      ir_if *f0947 = new(mem_ctx) ir_if(operand(r094D).val);
      exec_list *const f0947_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0947->then_instructions;

         ir_expression *const r094E = lshift(r093D, body.constant(int(31)));
         ir_expression *const r094F = add(r094E, body.constant(2139095040u));
         body.emit(assign(r0941, expr(ir_unop_bitcast_u2f, r094F), 0x01));

         body.emit(assign(r0940, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0947->else_instructions;

         ir_variable *const r0950 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0950, neg(r093E), 0x01));

         ir_variable *const r0951 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
         body.emit(assign(r0951, less(r093E, body.constant(int(0))), 0x01));

         ir_variable *const r0952 = body.make_temp(glsl_type::uint_type, "mix_retval");
         ir_expression *const r0953 = neg(r093E);
         ir_expression *const r0954 = less(r0953, body.constant(int(32)));
         ir_expression *const r0955 = rshift(r093F, r0950);
         ir_expression *const r0956 = neg(r0950);
         ir_expression *const r0957 = bit_and(r0956, body.constant(int(31)));
         ir_expression *const r0958 = lshift(r093F, r0957);
         ir_expression *const r0959 = nequal(r0958, body.constant(0u));
         ir_expression *const r095A = expr(ir_unop_b2i, r0959);
         ir_expression *const r095B = expr(ir_unop_i2u, r095A);
         ir_expression *const r095C = bit_or(r0955, r095B);
         ir_expression *const r095D = nequal(r093F, body.constant(0u));
         ir_expression *const r095E = expr(ir_unop_b2i, r095D);
         ir_expression *const r095F = expr(ir_unop_i2u, r095E);
         ir_expression *const r0960 = expr(ir_triop_csel, r0954, r095C, r095F);
         body.emit(assign(r0952, expr(ir_triop_csel, r0951, r0960, r093F), 0x01));

         body.emit(assign(r093F, r0952, 0x01));

         ir_expression *const r0961 = expr(ir_unop_u2i, r0952);
         ir_expression *const r0962 = bit_and(r0961, body.constant(int(127)));
         body.emit(assign(r0942, expr(ir_triop_csel, r0951, r0962, r0942), 0x01));

         body.emit(assign(r093E, expr(ir_triop_csel, r0951, body.constant(int(0)), r093E), 0x01));


      body.instructions = f0947_parent_instructions;
      body.emit(f0947);

      /* END IF */


   body.instructions = f0944_parent_instructions;
   body.emit(f0944);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0963 = new(mem_ctx) ir_if(operand(r0940).val);
   exec_list *const f0963_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0963->then_instructions;

      ir_expression *const r0964 = add(r093F, body.constant(64u));
      body.emit(assign(r093F, rshift(r0964, body.constant(int(7))), 0x01));

      ir_expression *const r0965 = bit_xor(r0942, body.constant(int(64)));
      ir_expression *const r0966 = equal(r0965, body.constant(int(0)));
      ir_expression *const r0967 = expr(ir_unop_b2i, r0966);
      ir_expression *const r0968 = expr(ir_unop_i2u, r0967);
      ir_expression *const r0969 = expr(ir_unop_bit_not, r0968);
      body.emit(assign(r093F, bit_and(r093F, r0969), 0x01));

      ir_expression *const r096A = lshift(r093D, body.constant(int(31)));
      ir_expression *const r096B = equal(r093F, body.constant(0u));
      ir_expression *const r096C = expr(ir_triop_csel, r096B, body.constant(int(0)), r093E);
      ir_expression *const r096D = expr(ir_unop_i2u, r096C);
      ir_expression *const r096E = lshift(r096D, body.constant(int(23)));
      ir_expression *const r096F = add(r096A, r096E);
      ir_expression *const r0970 = add(r096F, r093F);
      body.emit(assign(r0941, expr(ir_unop_bitcast_u2f, r0970), 0x01));

      body.emit(assign(r0940, body.constant(false), 0x01));


   body.instructions = f0963_parent_instructions;
   body.emit(f0963);

   /* END IF */

   body.emit(ret(r0941));

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

   ir_variable *const r0971 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0971);
   ir_variable *const r0972 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0973 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0973, swizzle_x(r0971), 0x01));

   ir_variable *const r0974 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0974, bit_and(swizzle_y(r0971), body.constant(1048575u)), 0x01));

   ir_variable *const r0975 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0976 = rshift(swizzle_y(r0971), body.constant(int(20)));
   ir_expression *const r0977 = bit_and(r0976, body.constant(2047u));
   body.emit(assign(r0975, expr(ir_unop_u2i, r0977), 0x01));

   ir_variable *const r0978 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0978, rshift(swizzle_y(r0971), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r097A = equal(r0975, body.constant(int(2047)));
   ir_if *f0979 = new(mem_ctx) ir_if(operand(r097A).val);
   exec_list *const f0979_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0979->then_instructions;

      ir_variable *const r097B = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r097B);
      ir_variable *const r097C = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r097C, lshift(swizzle_x(r0971), body.constant(int(12))), 0x01));

      ir_expression *const r097D = lshift(swizzle_y(r0971), body.constant(int(12)));
      ir_expression *const r097E = rshift(swizzle_x(r0971), body.constant(int(20)));
      body.emit(assign(r0971, bit_or(r097D, r097E), 0x02));

      body.emit(assign(r0971, r097C, 0x01));

      ir_expression *const r097F = lshift(r0978, body.constant(int(31)));
      ir_expression *const r0980 = bit_or(r097F, body.constant(2143289344u));
      ir_expression *const r0981 = rshift(swizzle_y(r0971), body.constant(int(9)));
      ir_expression *const r0982 = bit_or(r0980, r0981);
      body.emit(assign(r097B, expr(ir_unop_bitcast_u2f, r0982), 0x01));

      ir_variable *const r0983 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0984 = bit_or(r0974, r0973);
      ir_expression *const r0985 = nequal(r0984, body.constant(0u));
      ir_expression *const r0986 = lshift(r0978, body.constant(int(31)));
      ir_expression *const r0987 = add(r0986, body.constant(2139095040u));
      ir_expression *const r0988 = expr(ir_unop_bitcast_u2f, r0987);
      body.emit(assign(r0983, expr(ir_triop_csel, r0985, r097B, r0988), 0x01));

      body.emit(assign(r097B, r0983, 0x01));

      body.emit(assign(r0972, r0983, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0979->else_instructions;

      ir_variable *const r0989 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r098A = lshift(r0974, body.constant(int(10)));
      ir_expression *const r098B = rshift(r0973, body.constant(int(22)));
      ir_expression *const r098C = bit_or(r098A, r098B);
      ir_expression *const r098D = lshift(r0973, body.constant(int(10)));
      ir_expression *const r098E = nequal(r098D, body.constant(0u));
      ir_expression *const r098F = expr(ir_unop_b2i, r098E);
      ir_expression *const r0990 = expr(ir_unop_i2u, r098F);
      body.emit(assign(r0989, bit_or(r098C, r0990), 0x01));

      ir_variable *const r0991 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0992 = nequal(r0975, body.constant(int(0)));
      ir_expression *const r0993 = bit_or(r0989, body.constant(1073741824u));
      body.emit(assign(r0991, expr(ir_triop_csel, r0992, r0993, r0989), 0x01));

      ir_variable *const r0994 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0994, add(r0975, body.constant(int(-897))), 0x01));

      ir_variable *const r0995 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0995, r0991, 0x01));

      ir_variable *const r0996 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0996, body.constant(true), 0x01));

      ir_variable *const r0997 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0998 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0998);
      ir_expression *const r0999 = bit_and(r0991, body.constant(127u));
      body.emit(assign(r0998, expr(ir_unop_u2i, r0999), 0x01));

      /* IF CONDITION */
      ir_expression *const r099B = expr(ir_unop_i2u, r0994);
      ir_expression *const r099C = gequal(r099B, body.constant(253u));
      ir_if *f099A = new(mem_ctx) ir_if(operand(r099C).val);
      exec_list *const f099A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f099A->then_instructions;

         /* IF CONDITION */
         ir_expression *const r099E = less(body.constant(int(253)), r0994);
         ir_expression *const r099F = equal(r0994, body.constant(int(253)));
         ir_expression *const r09A0 = expr(ir_unop_u2i, r0991);
         ir_expression *const r09A1 = less(r09A0, body.constant(int(-64)));
         ir_expression *const r09A2 = logic_and(r099F, r09A1);
         ir_expression *const r09A3 = logic_or(r099E, r09A2);
         ir_if *f099D = new(mem_ctx) ir_if(operand(r09A3).val);
         exec_list *const f099D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f099D->then_instructions;

            ir_expression *const r09A4 = lshift(r0978, body.constant(int(31)));
            ir_expression *const r09A5 = add(r09A4, body.constant(2139095040u));
            body.emit(assign(r0997, expr(ir_unop_bitcast_u2f, r09A5), 0x01));

            body.emit(assign(r0996, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f099D->else_instructions;

            ir_variable *const r09A6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r09A6, neg(r0994), 0x01));

            ir_variable *const r09A7 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r09A7, less(r0994, body.constant(int(0))), 0x01));

            ir_variable *const r09A8 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r09A9 = neg(r0994);
            ir_expression *const r09AA = less(r09A9, body.constant(int(32)));
            ir_expression *const r09AB = rshift(r0991, r09A6);
            ir_expression *const r09AC = neg(r09A6);
            ir_expression *const r09AD = bit_and(r09AC, body.constant(int(31)));
            ir_expression *const r09AE = lshift(r0991, r09AD);
            ir_expression *const r09AF = nequal(r09AE, body.constant(0u));
            ir_expression *const r09B0 = expr(ir_unop_b2i, r09AF);
            ir_expression *const r09B1 = expr(ir_unop_i2u, r09B0);
            ir_expression *const r09B2 = bit_or(r09AB, r09B1);
            ir_expression *const r09B3 = nequal(r0991, body.constant(0u));
            ir_expression *const r09B4 = expr(ir_unop_b2i, r09B3);
            ir_expression *const r09B5 = expr(ir_unop_i2u, r09B4);
            ir_expression *const r09B6 = expr(ir_triop_csel, r09AA, r09B2, r09B5);
            body.emit(assign(r09A8, expr(ir_triop_csel, r09A7, r09B6, r0991), 0x01));

            body.emit(assign(r0995, r09A8, 0x01));

            ir_expression *const r09B7 = expr(ir_unop_u2i, r09A8);
            ir_expression *const r09B8 = bit_and(r09B7, body.constant(int(127)));
            body.emit(assign(r0998, expr(ir_triop_csel, r09A7, r09B8, r0998), 0x01));

            body.emit(assign(r0994, expr(ir_triop_csel, r09A7, body.constant(int(0)), r0994), 0x01));


         body.instructions = f099D_parent_instructions;
         body.emit(f099D);

         /* END IF */


      body.instructions = f099A_parent_instructions;
      body.emit(f099A);

      /* END IF */

      /* IF CONDITION */
      ir_if *f09B9 = new(mem_ctx) ir_if(operand(r0996).val);
      exec_list *const f09B9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09B9->then_instructions;

         ir_expression *const r09BA = add(r0995, body.constant(64u));
         body.emit(assign(r0995, rshift(r09BA, body.constant(int(7))), 0x01));

         ir_expression *const r09BB = bit_xor(r0998, body.constant(int(64)));
         ir_expression *const r09BC = equal(r09BB, body.constant(int(0)));
         ir_expression *const r09BD = expr(ir_unop_b2i, r09BC);
         ir_expression *const r09BE = expr(ir_unop_i2u, r09BD);
         ir_expression *const r09BF = expr(ir_unop_bit_not, r09BE);
         body.emit(assign(r0995, bit_and(r0995, r09BF), 0x01));

         ir_expression *const r09C0 = lshift(r0978, body.constant(int(31)));
         ir_expression *const r09C1 = equal(r0995, body.constant(0u));
         ir_expression *const r09C2 = expr(ir_triop_csel, r09C1, body.constant(int(0)), r0994);
         ir_expression *const r09C3 = expr(ir_unop_i2u, r09C2);
         ir_expression *const r09C4 = lshift(r09C3, body.constant(int(23)));
         ir_expression *const r09C5 = add(r09C0, r09C4);
         ir_expression *const r09C6 = add(r09C5, r0995);
         body.emit(assign(r0997, expr(ir_unop_bitcast_u2f, r09C6), 0x01));

         body.emit(assign(r0996, body.constant(false), 0x01));


      body.instructions = f09B9_parent_instructions;
      body.emit(f09B9);

      /* END IF */

      body.emit(assign(r0972, r0997, 0x01));


   body.instructions = f0979_parent_instructions;
   body.emit(f0979);

   /* END IF */

   body.emit(ret(r0972));

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

   ir_variable *const r09C7 = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r09C7);
   ir_variable *const r09C8 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r09C8, body.constant(true), 0x01));

   ir_variable *const r09C9 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r09CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r09CA);
   ir_variable *const r09CB = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r09CB);
   ir_variable *const r09CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r09CC);
   ir_variable *const r09CD = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r09CD, expr(ir_unop_bitcast_f2u, r09C7), 0x01));

   ir_variable *const r09CE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r09CE, bit_and(r09CD, body.constant(8388607u)), 0x01));

   body.emit(assign(r09CC, r09CE, 0x01));

   ir_variable *const r09CF = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r09D0 = rshift(r09CD, body.constant(int(23)));
   ir_expression *const r09D1 = bit_and(r09D0, body.constant(255u));
   body.emit(assign(r09CF, expr(ir_unop_u2i, r09D1), 0x01));

   body.emit(assign(r09CB, r09CF, 0x01));

   body.emit(assign(r09CA, rshift(r09CD, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r09D3 = equal(r09CF, body.constant(int(255)));
   ir_if *f09D2 = new(mem_ctx) ir_if(operand(r09D3).val);
   exec_list *const f09D2_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09D2->then_instructions;

      /* IF CONDITION */
      ir_expression *const r09D5 = nequal(r09CE, body.constant(0u));
      ir_if *f09D4 = new(mem_ctx) ir_if(operand(r09D5).val);
      exec_list *const f09D4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09D4->then_instructions;

         ir_variable *const r09D6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r09D6, lshift(r09CD, body.constant(int(9))), 0x01));

         ir_variable *const r09D7 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r09D8 = lshift(r09D6, body.constant(int(20)));
         body.emit(assign(r09D7, bit_or(r09D8, body.constant(0u)), 0x01));

         ir_expression *const r09D9 = rshift(r09D6, body.constant(int(12)));
         ir_expression *const r09DA = lshift(r09CA, body.constant(int(31)));
         ir_expression *const r09DB = bit_or(r09DA, body.constant(2146959360u));
         body.emit(assign(r09D7, bit_or(r09D9, r09DB), 0x02));

         body.emit(assign(r09C9, r09D7, 0x03));

         body.emit(assign(r09C8, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09D4->else_instructions;

         ir_variable *const r09DC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r09DC);
         ir_expression *const r09DD = lshift(r09CA, body.constant(int(31)));
         body.emit(assign(r09DC, add(r09DD, body.constant(2146435072u)), 0x02));

         body.emit(assign(r09DC, body.constant(0u), 0x01));

         body.emit(assign(r09C9, r09DC, 0x03));

         body.emit(assign(r09C8, body.constant(false), 0x01));


      body.instructions = f09D4_parent_instructions;
      body.emit(f09D4);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09D2->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09DF = equal(r09CF, body.constant(int(0)));
      ir_if *f09DE = new(mem_ctx) ir_if(operand(r09DF).val);
      exec_list *const f09DE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09DE->then_instructions;

         /* IF CONDITION */
         ir_expression *const r09E1 = equal(r09CE, body.constant(0u));
         ir_if *f09E0 = new(mem_ctx) ir_if(operand(r09E1).val);
         exec_list *const f09E0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09E0->then_instructions;

            ir_variable *const r09E2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r09E2);
            body.emit(assign(r09E2, lshift(r09CA, body.constant(int(31))), 0x02));

            body.emit(assign(r09E2, body.constant(0u), 0x01));

            body.emit(assign(r09C9, r09E2, 0x03));

            body.emit(assign(r09C8, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09E0->else_instructions;

            ir_variable *const r09E3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r09E4 = equal(r09CE, body.constant(0u));
            ir_expression *const r09E5 = expr(ir_unop_find_msb, r09CE);
            ir_expression *const r09E6 = sub(body.constant(int(31)), r09E5);
            ir_expression *const r09E7 = expr(ir_triop_csel, r09E4, body.constant(int(32)), r09E6);
            body.emit(assign(r09E3, add(r09E7, body.constant(int(-8))), 0x01));

            body.emit(assign(r09CC, lshift(r09CE, r09E3), 0x01));

            body.emit(assign(r09CB, sub(body.constant(int(1)), r09E3), 0x01));

            body.emit(assign(r09CB, add(r09CB, body.constant(int(-1))), 0x01));


         body.instructions = f09E0_parent_instructions;
         body.emit(f09E0);

         /* END IF */


      body.instructions = f09DE_parent_instructions;
      body.emit(f09DE);

      /* END IF */

      /* IF CONDITION */
      ir_if *f09E8 = new(mem_ctx) ir_if(operand(r09C8).val);
      exec_list *const f09E8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09E8->then_instructions;

         ir_variable *const r09E9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r09E9);
         ir_expression *const r09EA = lshift(r09CA, body.constant(int(31)));
         ir_expression *const r09EB = add(r09CB, body.constant(int(896)));
         ir_expression *const r09EC = expr(ir_unop_i2u, r09EB);
         ir_expression *const r09ED = lshift(r09EC, body.constant(int(20)));
         ir_expression *const r09EE = add(r09EA, r09ED);
         ir_expression *const r09EF = rshift(r09CC, body.constant(int(3)));
         body.emit(assign(r09E9, add(r09EE, r09EF), 0x02));

         ir_expression *const r09F0 = lshift(r09CC, body.constant(int(29)));
         body.emit(assign(r09E9, bit_or(r09F0, body.constant(0u)), 0x01));

         body.emit(assign(r09C9, r09E9, 0x03));

         body.emit(assign(r09C8, body.constant(false), 0x01));


      body.instructions = f09E8_parent_instructions;
      body.emit(f09E8);

      /* END IF */


   body.instructions = f09D2_parent_instructions;
   body.emit(f09D2);

   /* END IF */

   body.emit(ret(r09C9));

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

   ir_variable *const r09F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09F1);
   ir_variable *const r09F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09F2);
   ir_variable *const r09F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r09F3);
   ir_variable *const r09F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r09F4);
   ir_variable *const r09F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r09F5);
   ir_variable *const r09F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r09F6);
   ir_variable *const r09F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09F7);
   ir_variable *const r09F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09F8);
   ir_variable *const r09F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09F9);
   ir_variable *const r09FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r09FA);
   ir_variable *const r09FB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r09FB);
   ir_variable *const r09FC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r09FC, add(r09F3, r09F6), 0x01));

   ir_variable *const r09FD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r09FE = less(r09FC, r09F3);
   ir_expression *const r09FF = expr(ir_unop_b2i, r09FE);
   body.emit(assign(r09FD, expr(ir_unop_i2u, r09FF), 0x01));

   ir_variable *const r0A00 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0A00, add(r09F2, r09F5), 0x01));

   body.emit(assign(r09FB, add(r0A00, r09FD), 0x01));

   ir_expression *const r0A01 = add(r09F1, r09F4);
   ir_expression *const r0A02 = less(r09FB, r09FD);
   ir_expression *const r0A03 = expr(ir_unop_b2i, r0A02);
   ir_expression *const r0A04 = expr(ir_unop_i2u, r0A03);
   body.emit(assign(r09FA, add(r0A01, r0A04), 0x01));

   ir_expression *const r0A05 = less(r0A00, r09F2);
   ir_expression *const r0A06 = expr(ir_unop_b2i, r0A05);
   ir_expression *const r0A07 = expr(ir_unop_i2u, r0A06);
   body.emit(assign(r09FA, add(r09FA, r0A07), 0x01));

   body.emit(assign(r09F9, r09FC, 0x01));

   body.emit(assign(r09F8, r09FB, 0x01));

   body.emit(assign(r09F7, r09FA, 0x01));

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

   ir_variable *const r0A08 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0A08);
   ir_variable *const r0A09 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0A09);
   ir_variable *const r0A0A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0A0A);
   ir_variable *const r0A0B = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0A0B);
   ir_variable *const r0A0C = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0A0C);
   ir_variable *const r0A0D = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0A0D);
   ir_variable *const r0A0E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0A0E);
   ir_variable *const r0A0F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0A0F);
   ir_variable *const r0A10 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0A10);
   ir_variable *const r0A11 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0A11);
   ir_variable *const r0A12 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0A13 = less(r0A0A, r0A0D);
   ir_expression *const r0A14 = expr(ir_unop_b2i, r0A13);
   body.emit(assign(r0A12, expr(ir_unop_i2u, r0A14), 0x01));

   ir_variable *const r0A15 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0A15, sub(r0A09, r0A0C), 0x01));

   ir_expression *const r0A16 = sub(r0A08, r0A0B);
   ir_expression *const r0A17 = less(r0A15, r0A12);
   ir_expression *const r0A18 = expr(ir_unop_b2i, r0A17);
   ir_expression *const r0A19 = expr(ir_unop_i2u, r0A18);
   body.emit(assign(r0A11, sub(r0A16, r0A19), 0x01));

   ir_expression *const r0A1A = less(r0A09, r0A0C);
   ir_expression *const r0A1B = expr(ir_unop_b2i, r0A1A);
   ir_expression *const r0A1C = expr(ir_unop_i2u, r0A1B);
   body.emit(assign(r0A11, sub(r0A11, r0A1C), 0x01));

   body.emit(assign(r0A10, sub(r0A0A, r0A0D), 0x01));

   body.emit(assign(r0A0F, sub(r0A15, r0A12), 0x01));

   body.emit(assign(r0A0E, r0A11, 0x01));

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

   ir_variable *const r0A1D = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0A1D);
   ir_variable *const r0A1E = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0A1E);
   ir_variable *const r0A1F = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0A1F);
   ir_variable *const r0A20 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0A21 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0A21);
   ir_variable *const r0A22 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0A22);
   ir_variable *const r0A23 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0A23);
   ir_variable *const r0A24 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0A24);
   body.emit(assign(r0A23, body.constant(0u), 0x01));

   body.emit(assign(r0A22, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A26 = gequal(r0A1D, r0A1F);
   ir_if *f0A25 = new(mem_ctx) ir_if(operand(r0A26).val);
   exec_list *const f0A25_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A25->then_instructions;

      body.emit(assign(r0A20, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A25->else_instructions;

      body.emit(assign(r0A24, rshift(r0A1F, body.constant(int(16))), 0x01));

      ir_variable *const r0A27 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A29 = lshift(r0A24, body.constant(int(16)));
      ir_expression *const r0A2A = gequal(r0A1D, r0A29);
      ir_if *f0A28 = new(mem_ctx) ir_if(operand(r0A2A).val);
      exec_list *const f0A28_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A28->then_instructions;

         body.emit(assign(r0A27, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A28->else_instructions;

         ir_expression *const r0A2B = expr(ir_binop_div, r0A1D, r0A24);
         body.emit(assign(r0A27, lshift(r0A2B, body.constant(int(16))), 0x01));


      body.instructions = f0A28_parent_instructions;
      body.emit(f0A28);

      /* END IF */

      body.emit(assign(r0A21, r0A27, 0x01));

      ir_variable *const r0A2C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0A2C);
      ir_variable *const r0A2D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0A2D);
      ir_variable *const r0A2E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0A2E);
      ir_variable *const r0A2F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0A2F, bit_and(r0A1F, body.constant(65535u)), 0x01));

      ir_variable *const r0A30 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0A30, rshift(r0A1F, body.constant(int(16))), 0x01));

      ir_variable *const r0A31 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0A31, bit_and(r0A27, body.constant(65535u)), 0x01));

      ir_variable *const r0A32 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0A32, rshift(r0A27, body.constant(int(16))), 0x01));

      ir_variable *const r0A33 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0A33, mul(r0A30, r0A31), 0x01));

      ir_expression *const r0A34 = mul(r0A2F, r0A32);
      body.emit(assign(r0A2D, add(r0A34, r0A33), 0x01));

      ir_expression *const r0A35 = mul(r0A30, r0A32);
      ir_expression *const r0A36 = less(r0A2D, r0A33);
      ir_expression *const r0A37 = expr(ir_unop_b2i, r0A36);
      ir_expression *const r0A38 = expr(ir_unop_i2u, r0A37);
      ir_expression *const r0A39 = lshift(r0A38, body.constant(int(16)));
      ir_expression *const r0A3A = rshift(r0A2D, body.constant(int(16)));
      ir_expression *const r0A3B = add(r0A39, r0A3A);
      body.emit(assign(r0A2C, add(r0A35, r0A3B), 0x01));

      body.emit(assign(r0A2D, lshift(r0A2D, body.constant(int(16))), 0x01));

      ir_expression *const r0A3C = mul(r0A2F, r0A31);
      body.emit(assign(r0A2E, add(r0A3C, r0A2D), 0x01));

      ir_expression *const r0A3D = less(r0A2E, r0A2D);
      ir_expression *const r0A3E = expr(ir_unop_b2i, r0A3D);
      ir_expression *const r0A3F = expr(ir_unop_i2u, r0A3E);
      body.emit(assign(r0A2C, add(r0A2C, r0A3F), 0x01));

      ir_expression *const r0A40 = sub(r0A1D, r0A2C);
      ir_expression *const r0A41 = less(r0A1E, r0A2E);
      ir_expression *const r0A42 = expr(ir_unop_b2i, r0A41);
      ir_expression *const r0A43 = expr(ir_unop_i2u, r0A42);
      body.emit(assign(r0A23, sub(r0A40, r0A43), 0x01));

      body.emit(assign(r0A22, sub(r0A1E, r0A2E), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0A44 = new(mem_ctx) ir_loop();
      exec_list *const f0A44_parent_instructions = body.instructions;

         body.instructions = &f0A44->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0A46 = expr(ir_unop_u2i, r0A23);
         ir_expression *const r0A47 = gequal(r0A46, body.constant(int(0)));
         ir_if *f0A45 = new(mem_ctx) ir_if(operand(r0A47).val);
         exec_list *const f0A45_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A45->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0A45_parent_instructions;
         body.emit(f0A45);

         /* END IF */

         body.emit(assign(r0A21, add(r0A21, body.constant(4294901760u)), 0x01));

         ir_variable *const r0A48 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0A49 = lshift(r0A1F, body.constant(int(16)));
         body.emit(assign(r0A48, add(r0A22, r0A49), 0x01));

         ir_expression *const r0A4A = add(r0A23, r0A24);
         ir_expression *const r0A4B = less(r0A48, r0A22);
         ir_expression *const r0A4C = expr(ir_unop_b2i, r0A4B);
         ir_expression *const r0A4D = expr(ir_unop_i2u, r0A4C);
         body.emit(assign(r0A23, add(r0A4A, r0A4D), 0x01));

         body.emit(assign(r0A22, r0A48, 0x01));

      /* LOOP END */

      body.instructions = f0A44_parent_instructions;
      body.emit(f0A44);

      ir_expression *const r0A4E = lshift(r0A23, body.constant(int(16)));
      ir_expression *const r0A4F = rshift(r0A22, body.constant(int(16)));
      body.emit(assign(r0A23, bit_or(r0A4E, r0A4F), 0x01));

      ir_variable *const r0A50 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A52 = lshift(r0A24, body.constant(int(16)));
      ir_expression *const r0A53 = gequal(r0A23, r0A52);
      ir_if *f0A51 = new(mem_ctx) ir_if(operand(r0A53).val);
      exec_list *const f0A51_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A51->then_instructions;

         body.emit(assign(r0A50, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A51->else_instructions;

         body.emit(assign(r0A50, expr(ir_binop_div, r0A23, r0A24), 0x01));


      body.instructions = f0A51_parent_instructions;
      body.emit(f0A51);

      /* END IF */

      body.emit(assign(r0A21, bit_or(r0A21, r0A50), 0x01));

      body.emit(assign(r0A20, r0A21, 0x01));


   body.instructions = f0A25_parent_instructions;
   body.emit(f0A25);

   /* END IF */

   body.emit(ret(r0A20));

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

   ir_variable *const r0A54 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A54);
   ir_variable *const r0A55 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0A55, r0A54, 0x03));

   ir_variable *const r0A56 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A57 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A57, bit_and(swizzle_y(r0A54), body.constant(1048575u)), 0x01));

   ir_variable *const r0A58 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A59 = rshift(swizzle_y(r0A54), body.constant(int(20)));
   ir_expression *const r0A5A = bit_and(r0A59, body.constant(2047u));
   body.emit(assign(r0A58, expr(ir_unop_u2i, r0A5A), 0x01));

   ir_variable *const r0A5B = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A5B, rshift(swizzle_y(r0A54), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A5D = equal(r0A58, body.constant(int(2047)));
   ir_if *f0A5C = new(mem_ctx) ir_if(operand(r0A5D).val);
   exec_list *const f0A5C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A5C->then_instructions;

      ir_variable *const r0A5E = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0A5E);
      ir_expression *const r0A5F = lshift(swizzle_y(r0A54), body.constant(int(12)));
      ir_expression *const r0A60 = rshift(swizzle_x(r0A54), body.constant(int(20)));
      body.emit(assign(r0A55, bit_or(r0A5F, r0A60), 0x02));

      body.emit(assign(r0A55, lshift(swizzle_x(r0A54), body.constant(int(12))), 0x01));

      ir_expression *const r0A61 = lshift(r0A5B, body.constant(int(31)));
      ir_expression *const r0A62 = bit_or(r0A61, body.constant(2143289344u));
      ir_expression *const r0A63 = rshift(swizzle_y(r0A55), body.constant(int(9)));
      ir_expression *const r0A64 = bit_or(r0A62, r0A63);
      body.emit(assign(r0A5E, expr(ir_unop_bitcast_u2f, r0A64), 0x01));

      ir_variable *const r0A65 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0A66 = bit_or(r0A57, swizzle_x(r0A54));
      ir_expression *const r0A67 = nequal(r0A66, body.constant(0u));
      ir_expression *const r0A68 = lshift(r0A5B, body.constant(int(31)));
      ir_expression *const r0A69 = add(r0A68, body.constant(2139095040u));
      ir_expression *const r0A6A = expr(ir_unop_bitcast_u2f, r0A69);
      body.emit(assign(r0A65, expr(ir_triop_csel, r0A67, r0A5E, r0A6A), 0x01));

      body.emit(assign(r0A5E, r0A65, 0x01));

      body.emit(assign(r0A56, r0A65, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A5C->else_instructions;

      ir_variable *const r0A6B = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A6C = lshift(r0A57, body.constant(int(10)));
      ir_expression *const r0A6D = rshift(swizzle_x(r0A54), body.constant(int(22)));
      ir_expression *const r0A6E = bit_or(r0A6C, r0A6D);
      ir_expression *const r0A6F = lshift(swizzle_x(r0A54), body.constant(int(10)));
      ir_expression *const r0A70 = nequal(r0A6F, body.constant(0u));
      ir_expression *const r0A71 = expr(ir_unop_b2i, r0A70);
      ir_expression *const r0A72 = expr(ir_unop_i2u, r0A71);
      body.emit(assign(r0A6B, bit_or(r0A6E, r0A72), 0x01));

      ir_variable *const r0A73 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A74 = nequal(r0A58, body.constant(int(0)));
      ir_expression *const r0A75 = bit_or(r0A6B, body.constant(1073741824u));
      body.emit(assign(r0A73, expr(ir_triop_csel, r0A74, r0A75, r0A6B), 0x01));

      ir_variable *const r0A76 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0A76, add(r0A58, body.constant(int(-897))), 0x01));

      ir_variable *const r0A77 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0A77, r0A73, 0x01));

      ir_variable *const r0A78 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0A78, body.constant(true), 0x01));

      ir_variable *const r0A79 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0A7A = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0A7A);
      ir_expression *const r0A7B = bit_and(r0A73, body.constant(127u));
      body.emit(assign(r0A7A, expr(ir_unop_u2i, r0A7B), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A7D = expr(ir_unop_i2u, r0A76);
      ir_expression *const r0A7E = gequal(r0A7D, body.constant(253u));
      ir_if *f0A7C = new(mem_ctx) ir_if(operand(r0A7E).val);
      exec_list *const f0A7C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A7C->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A80 = less(body.constant(int(253)), r0A76);
         ir_expression *const r0A81 = equal(r0A76, body.constant(int(253)));
         ir_expression *const r0A82 = expr(ir_unop_u2i, r0A73);
         ir_expression *const r0A83 = less(r0A82, body.constant(int(-64)));
         ir_expression *const r0A84 = logic_and(r0A81, r0A83);
         ir_expression *const r0A85 = logic_or(r0A80, r0A84);
         ir_if *f0A7F = new(mem_ctx) ir_if(operand(r0A85).val);
         exec_list *const f0A7F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A7F->then_instructions;

            ir_expression *const r0A86 = lshift(r0A5B, body.constant(int(31)));
            ir_expression *const r0A87 = add(r0A86, body.constant(2139095040u));
            body.emit(assign(r0A79, expr(ir_unop_bitcast_u2f, r0A87), 0x01));

            body.emit(assign(r0A78, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A7F->else_instructions;

            ir_variable *const r0A88 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0A88, neg(r0A76), 0x01));

            ir_variable *const r0A89 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0A89, less(r0A76, body.constant(int(0))), 0x01));

            ir_variable *const r0A8A = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0A8B = neg(r0A76);
            ir_expression *const r0A8C = less(r0A8B, body.constant(int(32)));
            ir_expression *const r0A8D = rshift(r0A73, r0A88);
            ir_expression *const r0A8E = neg(r0A88);
            ir_expression *const r0A8F = bit_and(r0A8E, body.constant(int(31)));
            ir_expression *const r0A90 = lshift(r0A73, r0A8F);
            ir_expression *const r0A91 = nequal(r0A90, body.constant(0u));
            ir_expression *const r0A92 = expr(ir_unop_b2i, r0A91);
            ir_expression *const r0A93 = expr(ir_unop_i2u, r0A92);
            ir_expression *const r0A94 = bit_or(r0A8D, r0A93);
            ir_expression *const r0A95 = nequal(r0A73, body.constant(0u));
            ir_expression *const r0A96 = expr(ir_unop_b2i, r0A95);
            ir_expression *const r0A97 = expr(ir_unop_i2u, r0A96);
            ir_expression *const r0A98 = expr(ir_triop_csel, r0A8C, r0A94, r0A97);
            body.emit(assign(r0A8A, expr(ir_triop_csel, r0A89, r0A98, r0A73), 0x01));

            body.emit(assign(r0A77, r0A8A, 0x01));

            ir_expression *const r0A99 = expr(ir_unop_u2i, r0A8A);
            ir_expression *const r0A9A = bit_and(r0A99, body.constant(int(127)));
            body.emit(assign(r0A7A, expr(ir_triop_csel, r0A89, r0A9A, r0A7A), 0x01));

            body.emit(assign(r0A76, expr(ir_triop_csel, r0A89, body.constant(int(0)), r0A76), 0x01));


         body.instructions = f0A7F_parent_instructions;
         body.emit(f0A7F);

         /* END IF */


      body.instructions = f0A7C_parent_instructions;
      body.emit(f0A7C);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A9B = new(mem_ctx) ir_if(operand(r0A78).val);
      exec_list *const f0A9B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A9B->then_instructions;

         ir_expression *const r0A9C = add(r0A77, body.constant(64u));
         body.emit(assign(r0A77, rshift(r0A9C, body.constant(int(7))), 0x01));

         ir_expression *const r0A9D = bit_xor(r0A7A, body.constant(int(64)));
         ir_expression *const r0A9E = equal(r0A9D, body.constant(int(0)));
         ir_expression *const r0A9F = expr(ir_unop_b2i, r0A9E);
         ir_expression *const r0AA0 = expr(ir_unop_i2u, r0A9F);
         ir_expression *const r0AA1 = expr(ir_unop_bit_not, r0AA0);
         body.emit(assign(r0A77, bit_and(r0A77, r0AA1), 0x01));

         ir_expression *const r0AA2 = lshift(r0A5B, body.constant(int(31)));
         ir_expression *const r0AA3 = equal(r0A77, body.constant(0u));
         ir_expression *const r0AA4 = expr(ir_triop_csel, r0AA3, body.constant(int(0)), r0A76);
         ir_expression *const r0AA5 = expr(ir_unop_i2u, r0AA4);
         ir_expression *const r0AA6 = lshift(r0AA5, body.constant(int(23)));
         ir_expression *const r0AA7 = add(r0AA2, r0AA6);
         ir_expression *const r0AA8 = add(r0AA7, r0A77);
         body.emit(assign(r0A79, expr(ir_unop_bitcast_u2f, r0AA8), 0x01));

         body.emit(assign(r0A78, body.constant(false), 0x01));


      body.instructions = f0A9B_parent_instructions;
      body.emit(f0A9B);

      /* END IF */

      body.emit(assign(r0A56, r0A79, 0x01));


   body.instructions = f0A5C_parent_instructions;
   body.emit(f0A5C);

   /* END IF */

   ir_variable *const r0AA9 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0AA9, body.constant(true), 0x01));

   ir_variable *const r0AAA = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0AAB = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0AAB);
   ir_variable *const r0AAC = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0AAC);
   ir_variable *const r0AAD = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0AAD);
   ir_variable *const r0AAE = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0AAF = expr(ir_unop_sqrt, r0A56);
   body.emit(assign(r0AAE, expr(ir_unop_bitcast_f2u, r0AAF), 0x01));

   ir_variable *const r0AB0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0AB0, bit_and(r0AAE, body.constant(8388607u)), 0x01));

   body.emit(assign(r0AAD, r0AB0, 0x01));

   ir_variable *const r0AB1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0AB2 = rshift(r0AAE, body.constant(int(23)));
   ir_expression *const r0AB3 = bit_and(r0AB2, body.constant(255u));
   body.emit(assign(r0AB1, expr(ir_unop_u2i, r0AB3), 0x01));

   body.emit(assign(r0AAC, r0AB1, 0x01));

   body.emit(assign(r0AAB, rshift(r0AAE, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AB5 = equal(r0AB1, body.constant(int(255)));
   ir_if *f0AB4 = new(mem_ctx) ir_if(operand(r0AB5).val);
   exec_list *const f0AB4_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AB4->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0AB7 = nequal(r0AB0, body.constant(0u));
      ir_if *f0AB6 = new(mem_ctx) ir_if(operand(r0AB7).val);
      exec_list *const f0AB6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AB6->then_instructions;

         ir_variable *const r0AB8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0AB8, lshift(r0AAE, body.constant(int(9))), 0x01));

         ir_variable *const r0AB9 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0ABA = lshift(r0AB8, body.constant(int(20)));
         body.emit(assign(r0AB9, bit_or(r0ABA, body.constant(0u)), 0x01));

         ir_expression *const r0ABB = rshift(r0AB8, body.constant(int(12)));
         ir_expression *const r0ABC = lshift(r0AAB, body.constant(int(31)));
         ir_expression *const r0ABD = bit_or(r0ABC, body.constant(2146959360u));
         body.emit(assign(r0AB9, bit_or(r0ABB, r0ABD), 0x02));

         body.emit(assign(r0AAA, r0AB9, 0x03));

         body.emit(assign(r0AA9, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AB6->else_instructions;

         ir_variable *const r0ABE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0ABE);
         ir_expression *const r0ABF = lshift(r0AAB, body.constant(int(31)));
         body.emit(assign(r0ABE, add(r0ABF, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0ABE, body.constant(0u), 0x01));

         body.emit(assign(r0AAA, r0ABE, 0x03));

         body.emit(assign(r0AA9, body.constant(false), 0x01));


      body.instructions = f0AB6_parent_instructions;
      body.emit(f0AB6);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AB4->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0AC1 = equal(r0AB1, body.constant(int(0)));
      ir_if *f0AC0 = new(mem_ctx) ir_if(operand(r0AC1).val);
      exec_list *const f0AC0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AC0->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0AC3 = equal(r0AB0, body.constant(0u));
         ir_if *f0AC2 = new(mem_ctx) ir_if(operand(r0AC3).val);
         exec_list *const f0AC2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AC2->then_instructions;

            ir_variable *const r0AC4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0AC4);
            body.emit(assign(r0AC4, lshift(r0AAB, body.constant(int(31))), 0x02));

            body.emit(assign(r0AC4, body.constant(0u), 0x01));

            body.emit(assign(r0AAA, r0AC4, 0x03));

            body.emit(assign(r0AA9, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AC2->else_instructions;

            ir_variable *const r0AC5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0AC6 = equal(r0AB0, body.constant(0u));
            ir_expression *const r0AC7 = expr(ir_unop_find_msb, r0AB0);
            ir_expression *const r0AC8 = sub(body.constant(int(31)), r0AC7);
            ir_expression *const r0AC9 = expr(ir_triop_csel, r0AC6, body.constant(int(32)), r0AC8);
            body.emit(assign(r0AC5, add(r0AC9, body.constant(int(-8))), 0x01));

            body.emit(assign(r0AAD, lshift(r0AB0, r0AC5), 0x01));

            body.emit(assign(r0AAC, sub(body.constant(int(1)), r0AC5), 0x01));

            body.emit(assign(r0AAC, add(r0AAC, body.constant(int(-1))), 0x01));


         body.instructions = f0AC2_parent_instructions;
         body.emit(f0AC2);

         /* END IF */


      body.instructions = f0AC0_parent_instructions;
      body.emit(f0AC0);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0ACA = new(mem_ctx) ir_if(operand(r0AA9).val);
      exec_list *const f0ACA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0ACA->then_instructions;

         ir_variable *const r0ACB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0ACB);
         ir_expression *const r0ACC = lshift(r0AAB, body.constant(int(31)));
         ir_expression *const r0ACD = add(r0AAC, body.constant(int(896)));
         ir_expression *const r0ACE = expr(ir_unop_i2u, r0ACD);
         ir_expression *const r0ACF = lshift(r0ACE, body.constant(int(20)));
         ir_expression *const r0AD0 = add(r0ACC, r0ACF);
         ir_expression *const r0AD1 = rshift(r0AAD, body.constant(int(3)));
         body.emit(assign(r0ACB, add(r0AD0, r0AD1), 0x02));

         ir_expression *const r0AD2 = lshift(r0AAD, body.constant(int(29)));
         body.emit(assign(r0ACB, bit_or(r0AD2, body.constant(0u)), 0x01));

         body.emit(assign(r0AAA, r0ACB, 0x03));

         body.emit(assign(r0AA9, body.constant(false), 0x01));


      body.instructions = f0ACA_parent_instructions;
      body.emit(f0ACA);

      /* END IF */


   body.instructions = f0AB4_parent_instructions;
   body.emit(f0AB4);

   /* END IF */

   body.emit(ret(r0AAA));

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

   ir_variable *const r0AD3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AD3);
   ir_variable *const r0AD4 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0AD5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0AD6 = rshift(swizzle_y(r0AD3), body.constant(int(20)));
   ir_expression *const r0AD7 = bit_and(r0AD6, body.constant(2047u));
   ir_expression *const r0AD8 = expr(ir_unop_u2i, r0AD7);
   body.emit(assign(r0AD5, add(r0AD8, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0ADA = less(r0AD5, body.constant(int(0)));
   ir_if *f0AD9 = new(mem_ctx) ir_if(operand(r0ADA).val);
   exec_list *const f0AD9_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AD9->then_instructions;

      body.emit(assign(r0AD4, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AD9->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0ADC = less(body.constant(int(52)), r0AD5);
      ir_if *f0ADB = new(mem_ctx) ir_if(operand(r0ADC).val);
      exec_list *const f0ADB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0ADB->then_instructions;

         body.emit(assign(r0AD4, r0AD3, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0ADB->else_instructions;

         ir_variable *const r0ADD = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0ADD, sub(body.constant(int(52)), r0AD5), 0x01));

         ir_variable *const r0ADE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0AE0 = gequal(r0ADD, body.constant(int(32)));
         ir_if *f0ADF = new(mem_ctx) ir_if(operand(r0AE0).val);
         exec_list *const f0ADF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ADF->then_instructions;

            body.emit(assign(r0ADE, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0ADF->else_instructions;

            body.emit(assign(r0ADE, lshift(body.constant(4294967295u), r0ADD), 0x01));


         body.instructions = f0ADF_parent_instructions;
         body.emit(f0ADF);

         /* END IF */

         ir_variable *const r0AE1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0AE3 = less(r0ADD, body.constant(int(33)));
         ir_if *f0AE2 = new(mem_ctx) ir_if(operand(r0AE3).val);
         exec_list *const f0AE2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AE2->then_instructions;

            body.emit(assign(r0AE1, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AE2->else_instructions;

            ir_expression *const r0AE4 = add(r0ADD, body.constant(int(-32)));
            body.emit(assign(r0AE1, lshift(body.constant(4294967295u), r0AE4), 0x01));


         body.instructions = f0AE2_parent_instructions;
         body.emit(f0AE2);

         /* END IF */

         ir_variable *const r0AE5 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0AE5, bit_and(r0ADE, swizzle_x(r0AD3)), 0x01));

         body.emit(assign(r0AE5, bit_and(r0AE1, swizzle_y(r0AD3)), 0x02));

         body.emit(assign(r0AD4, r0AE5, 0x03));


      body.instructions = f0ADB_parent_instructions;
      body.emit(f0ADB);

      /* END IF */


   body.instructions = f0AD9_parent_instructions;
   body.emit(f0AD9);

   /* END IF */

   body.emit(ret(r0AD4));

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

   ir_variable *const r0AE6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AE6);
   ir_variable *const r0AE7 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0AE7, body.constant(true), 0x01));

   ir_variable *const r0AE8 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0AE9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0AE9);
   ir_variable *const r0AEA = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0AEA);
   ir_variable *const r0AEB = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0AEC = rshift(swizzle_y(r0AE6), body.constant(int(20)));
   ir_expression *const r0AED = bit_and(r0AEC, body.constant(2047u));
   ir_expression *const r0AEE = expr(ir_unop_u2i, r0AED);
   body.emit(assign(r0AEB, add(r0AEE, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0AEA, swizzle_y(r0AE6), 0x01));

   body.emit(assign(r0AE9, swizzle_x(r0AE6), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AF0 = less(r0AEB, body.constant(int(20)));
   ir_if *f0AEF = new(mem_ctx) ir_if(operand(r0AF0).val);
   exec_list *const f0AEF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AEF->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0AF2 = less(r0AEB, body.constant(int(0)));
      ir_if *f0AF1 = new(mem_ctx) ir_if(operand(r0AF2).val);
      exec_list *const f0AF1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AF1->then_instructions;

         body.emit(assign(r0AEA, bit_and(swizzle_y(r0AE6), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AF4 = equal(r0AEB, body.constant(int(-1)));
         ir_expression *const r0AF5 = nequal(swizzle_x(r0AE6), body.constant(0u));
         ir_expression *const r0AF6 = logic_and(r0AF4, r0AF5);
         ir_if *f0AF3 = new(mem_ctx) ir_if(operand(r0AF6).val);
         exec_list *const f0AF3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AF3->then_instructions;

            body.emit(assign(r0AEA, bit_or(r0AEA, body.constant(1072693248u)), 0x01));


         body.instructions = f0AF3_parent_instructions;
         body.emit(f0AF3);

         /* END IF */

         body.emit(assign(r0AE9, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AF1->else_instructions;

         ir_variable *const r0AF7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0AF7, rshift(body.constant(1048575u), r0AEB), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AF9 = bit_and(r0AEA, r0AF7);
         ir_expression *const r0AFA = equal(r0AF9, body.constant(0u));
         ir_expression *const r0AFB = equal(r0AE9, body.constant(0u));
         ir_expression *const r0AFC = logic_and(r0AFA, r0AFB);
         ir_if *f0AF8 = new(mem_ctx) ir_if(operand(r0AFC).val);
         exec_list *const f0AF8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AF8->then_instructions;

            body.emit(assign(r0AE8, r0AE6, 0x03));

            body.emit(assign(r0AE7, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AF8->else_instructions;

            ir_expression *const r0AFD = rshift(body.constant(524288u), r0AEB);
            body.emit(assign(r0AEA, add(r0AEA, r0AFD), 0x01));

            ir_expression *const r0AFE = expr(ir_unop_bit_not, r0AF7);
            body.emit(assign(r0AEA, bit_and(r0AEA, r0AFE), 0x01));

            body.emit(assign(r0AE9, body.constant(0u), 0x01));


         body.instructions = f0AF8_parent_instructions;
         body.emit(f0AF8);

         /* END IF */


      body.instructions = f0AF1_parent_instructions;
      body.emit(f0AF1);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AEF->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B00 = less(body.constant(int(51)), r0AEB);
      ir_expression *const r0B01 = equal(r0AEB, body.constant(int(1024)));
      ir_expression *const r0B02 = logic_or(r0B00, r0B01);
      ir_if *f0AFF = new(mem_ctx) ir_if(operand(r0B02).val);
      exec_list *const f0AFF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AFF->then_instructions;

         body.emit(assign(r0AE8, r0AE6, 0x03));

         body.emit(assign(r0AE7, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AFF->else_instructions;

         ir_variable *const r0B03 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0B04 = add(r0AEB, body.constant(int(-20)));
         body.emit(assign(r0B03, rshift(body.constant(4294967295u), r0B04), 0x01));

         /* IF CONDITION */
         ir_expression *const r0B06 = bit_and(r0AE9, r0B03);
         ir_expression *const r0B07 = equal(r0B06, body.constant(0u));
         ir_if *f0B05 = new(mem_ctx) ir_if(operand(r0B07).val);
         exec_list *const f0B05_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B05->then_instructions;

            body.emit(assign(r0AE8, r0AE6, 0x03));

            body.emit(assign(r0AE7, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B05->else_instructions;

            ir_variable *const r0B08 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0B09 = sub(body.constant(int(51)), r0AEB);
            ir_expression *const r0B0A = lshift(body.constant(1u), r0B09);
            body.emit(assign(r0B08, add(r0AE9, r0B0A), 0x01));

            /* IF CONDITION */
            ir_expression *const r0B0C = less(r0B08, r0AE9);
            ir_if *f0B0B = new(mem_ctx) ir_if(operand(r0B0C).val);
            exec_list *const f0B0B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B0B->then_instructions;

               body.emit(assign(r0AEA, add(r0AEA, body.constant(1u)), 0x01));


            body.instructions = f0B0B_parent_instructions;
            body.emit(f0B0B);

            /* END IF */

            ir_expression *const r0B0D = expr(ir_unop_bit_not, r0B03);
            body.emit(assign(r0AE9, bit_and(r0B08, r0B0D), 0x01));


         body.instructions = f0B05_parent_instructions;
         body.emit(f0B05);

         /* END IF */


      body.instructions = f0AFF_parent_instructions;
      body.emit(f0AFF);

      /* END IF */


   body.instructions = f0AEF_parent_instructions;
   body.emit(f0AEF);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0B0E = new(mem_ctx) ir_if(operand(r0AE7).val);
   exec_list *const f0B0E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B0E->then_instructions;

      body.emit(assign(r0AE6, r0AE9, 0x01));

      body.emit(assign(r0AE6, r0AEA, 0x02));

      body.emit(assign(r0AE8, r0AE6, 0x03));

      body.emit(assign(r0AE7, body.constant(false), 0x01));


   body.instructions = f0B0E_parent_instructions;
   body.emit(f0B0E);

   /* END IF */

   body.emit(ret(r0AE8));

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

   ir_variable *const r0B0F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B0F);
   ir_variable *const r0B10 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0B10, r0B0F, 0x03));

   ir_variable *const r0B11 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B12 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B12, bit_and(swizzle_y(r0B0F), body.constant(1048575u)), 0x01));

   ir_variable *const r0B13 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B14 = rshift(swizzle_y(r0B0F), body.constant(int(20)));
   ir_expression *const r0B15 = bit_and(r0B14, body.constant(2047u));
   body.emit(assign(r0B13, expr(ir_unop_u2i, r0B15), 0x01));

   ir_variable *const r0B16 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B16, rshift(swizzle_y(r0B0F), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B18 = equal(r0B13, body.constant(int(2047)));
   ir_if *f0B17 = new(mem_ctx) ir_if(operand(r0B18).val);
   exec_list *const f0B17_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B17->then_instructions;

      ir_variable *const r0B19 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0B19);
      ir_expression *const r0B1A = lshift(swizzle_y(r0B0F), body.constant(int(12)));
      ir_expression *const r0B1B = rshift(swizzle_x(r0B0F), body.constant(int(20)));
      body.emit(assign(r0B10, bit_or(r0B1A, r0B1B), 0x02));

      body.emit(assign(r0B10, lshift(swizzle_x(r0B0F), body.constant(int(12))), 0x01));

      ir_expression *const r0B1C = lshift(r0B16, body.constant(int(31)));
      ir_expression *const r0B1D = bit_or(r0B1C, body.constant(2143289344u));
      ir_expression *const r0B1E = rshift(swizzle_y(r0B10), body.constant(int(9)));
      ir_expression *const r0B1F = bit_or(r0B1D, r0B1E);
      body.emit(assign(r0B19, expr(ir_unop_bitcast_u2f, r0B1F), 0x01));

      ir_variable *const r0B20 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0B21 = bit_or(r0B12, swizzle_x(r0B0F));
      ir_expression *const r0B22 = nequal(r0B21, body.constant(0u));
      ir_expression *const r0B23 = lshift(r0B16, body.constant(int(31)));
      ir_expression *const r0B24 = add(r0B23, body.constant(2139095040u));
      ir_expression *const r0B25 = expr(ir_unop_bitcast_u2f, r0B24);
      body.emit(assign(r0B20, expr(ir_triop_csel, r0B22, r0B19, r0B25), 0x01));

      body.emit(assign(r0B19, r0B20, 0x01));

      body.emit(assign(r0B11, r0B20, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B17->else_instructions;

      ir_variable *const r0B26 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0B27 = lshift(r0B12, body.constant(int(10)));
      ir_expression *const r0B28 = rshift(swizzle_x(r0B0F), body.constant(int(22)));
      ir_expression *const r0B29 = bit_or(r0B27, r0B28);
      ir_expression *const r0B2A = lshift(swizzle_x(r0B0F), body.constant(int(10)));
      ir_expression *const r0B2B = nequal(r0B2A, body.constant(0u));
      ir_expression *const r0B2C = expr(ir_unop_b2i, r0B2B);
      ir_expression *const r0B2D = expr(ir_unop_i2u, r0B2C);
      body.emit(assign(r0B26, bit_or(r0B29, r0B2D), 0x01));

      ir_variable *const r0B2E = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0B2F = nequal(r0B13, body.constant(int(0)));
      ir_expression *const r0B30 = bit_or(r0B26, body.constant(1073741824u));
      body.emit(assign(r0B2E, expr(ir_triop_csel, r0B2F, r0B30, r0B26), 0x01));

      ir_variable *const r0B31 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B31, add(r0B13, body.constant(int(-897))), 0x01));

      ir_variable *const r0B32 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B32, r0B2E, 0x01));

      ir_variable *const r0B33 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B33, body.constant(true), 0x01));

      ir_variable *const r0B34 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B35 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B35);
      ir_expression *const r0B36 = bit_and(r0B2E, body.constant(127u));
      body.emit(assign(r0B35, expr(ir_unop_u2i, r0B36), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B38 = expr(ir_unop_i2u, r0B31);
      ir_expression *const r0B39 = gequal(r0B38, body.constant(253u));
      ir_if *f0B37 = new(mem_ctx) ir_if(operand(r0B39).val);
      exec_list *const f0B37_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B37->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B3B = less(body.constant(int(253)), r0B31);
         ir_expression *const r0B3C = equal(r0B31, body.constant(int(253)));
         ir_expression *const r0B3D = expr(ir_unop_u2i, r0B2E);
         ir_expression *const r0B3E = less(r0B3D, body.constant(int(-64)));
         ir_expression *const r0B3F = logic_and(r0B3C, r0B3E);
         ir_expression *const r0B40 = logic_or(r0B3B, r0B3F);
         ir_if *f0B3A = new(mem_ctx) ir_if(operand(r0B40).val);
         exec_list *const f0B3A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B3A->then_instructions;

            ir_expression *const r0B41 = lshift(r0B16, body.constant(int(31)));
            ir_expression *const r0B42 = add(r0B41, body.constant(2139095040u));
            body.emit(assign(r0B34, expr(ir_unop_bitcast_u2f, r0B42), 0x01));

            body.emit(assign(r0B33, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B3A->else_instructions;

            ir_variable *const r0B43 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B43, neg(r0B31), 0x01));

            ir_variable *const r0B44 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0B44, less(r0B31, body.constant(int(0))), 0x01));

            ir_variable *const r0B45 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0B46 = neg(r0B31);
            ir_expression *const r0B47 = less(r0B46, body.constant(int(32)));
            ir_expression *const r0B48 = rshift(r0B2E, r0B43);
            ir_expression *const r0B49 = neg(r0B43);
            ir_expression *const r0B4A = bit_and(r0B49, body.constant(int(31)));
            ir_expression *const r0B4B = lshift(r0B2E, r0B4A);
            ir_expression *const r0B4C = nequal(r0B4B, body.constant(0u));
            ir_expression *const r0B4D = expr(ir_unop_b2i, r0B4C);
            ir_expression *const r0B4E = expr(ir_unop_i2u, r0B4D);
            ir_expression *const r0B4F = bit_or(r0B48, r0B4E);
            ir_expression *const r0B50 = nequal(r0B2E, body.constant(0u));
            ir_expression *const r0B51 = expr(ir_unop_b2i, r0B50);
            ir_expression *const r0B52 = expr(ir_unop_i2u, r0B51);
            ir_expression *const r0B53 = expr(ir_triop_csel, r0B47, r0B4F, r0B52);
            body.emit(assign(r0B45, expr(ir_triop_csel, r0B44, r0B53, r0B2E), 0x01));

            body.emit(assign(r0B32, r0B45, 0x01));

            ir_expression *const r0B54 = expr(ir_unop_u2i, r0B45);
            ir_expression *const r0B55 = bit_and(r0B54, body.constant(int(127)));
            body.emit(assign(r0B35, expr(ir_triop_csel, r0B44, r0B55, r0B35), 0x01));

            body.emit(assign(r0B31, expr(ir_triop_csel, r0B44, body.constant(int(0)), r0B31), 0x01));


         body.instructions = f0B3A_parent_instructions;
         body.emit(f0B3A);

         /* END IF */


      body.instructions = f0B37_parent_instructions;
      body.emit(f0B37);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B56 = new(mem_ctx) ir_if(operand(r0B33).val);
      exec_list *const f0B56_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B56->then_instructions;

         ir_expression *const r0B57 = add(r0B32, body.constant(64u));
         body.emit(assign(r0B32, rshift(r0B57, body.constant(int(7))), 0x01));

         ir_expression *const r0B58 = bit_xor(r0B35, body.constant(int(64)));
         ir_expression *const r0B59 = equal(r0B58, body.constant(int(0)));
         ir_expression *const r0B5A = expr(ir_unop_b2i, r0B59);
         ir_expression *const r0B5B = expr(ir_unop_i2u, r0B5A);
         ir_expression *const r0B5C = expr(ir_unop_bit_not, r0B5B);
         body.emit(assign(r0B32, bit_and(r0B32, r0B5C), 0x01));

         ir_expression *const r0B5D = lshift(r0B16, body.constant(int(31)));
         ir_expression *const r0B5E = equal(r0B32, body.constant(0u));
         ir_expression *const r0B5F = expr(ir_triop_csel, r0B5E, body.constant(int(0)), r0B31);
         ir_expression *const r0B60 = expr(ir_unop_i2u, r0B5F);
         ir_expression *const r0B61 = lshift(r0B60, body.constant(int(23)));
         ir_expression *const r0B62 = add(r0B5D, r0B61);
         ir_expression *const r0B63 = add(r0B62, r0B32);
         body.emit(assign(r0B34, expr(ir_unop_bitcast_u2f, r0B63), 0x01));

         body.emit(assign(r0B33, body.constant(false), 0x01));


      body.instructions = f0B56_parent_instructions;
      body.emit(f0B56);

      /* END IF */

      body.emit(assign(r0B11, r0B34, 0x01));


   body.instructions = f0B17_parent_instructions;
   body.emit(f0B17);

   /* END IF */

   ir_variable *const r0B64 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B64, body.constant(true), 0x01));

   ir_variable *const r0B65 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B66 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B66);
   ir_variable *const r0B67 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B67);
   ir_variable *const r0B68 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B68);
   ir_variable *const r0B69 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0B6A = expr(ir_unop_rcp, r0B11);
   body.emit(assign(r0B69, expr(ir_unop_bitcast_f2u, r0B6A), 0x01));

   ir_variable *const r0B6B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B6B, bit_and(r0B69, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B68, r0B6B, 0x01));

   ir_variable *const r0B6C = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B6D = rshift(r0B69, body.constant(int(23)));
   ir_expression *const r0B6E = bit_and(r0B6D, body.constant(255u));
   body.emit(assign(r0B6C, expr(ir_unop_u2i, r0B6E), 0x01));

   body.emit(assign(r0B67, r0B6C, 0x01));

   body.emit(assign(r0B66, rshift(r0B69, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B70 = equal(r0B6C, body.constant(int(255)));
   ir_if *f0B6F = new(mem_ctx) ir_if(operand(r0B70).val);
   exec_list *const f0B6F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B6F->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B72 = nequal(r0B6B, body.constant(0u));
      ir_if *f0B71 = new(mem_ctx) ir_if(operand(r0B72).val);
      exec_list *const f0B71_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B71->then_instructions;

         ir_variable *const r0B73 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B73, lshift(r0B69, body.constant(int(9))), 0x01));

         ir_variable *const r0B74 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B75 = lshift(r0B73, body.constant(int(20)));
         body.emit(assign(r0B74, bit_or(r0B75, body.constant(0u)), 0x01));

         ir_expression *const r0B76 = rshift(r0B73, body.constant(int(12)));
         ir_expression *const r0B77 = lshift(r0B66, body.constant(int(31)));
         ir_expression *const r0B78 = bit_or(r0B77, body.constant(2146959360u));
         body.emit(assign(r0B74, bit_or(r0B76, r0B78), 0x02));

         body.emit(assign(r0B65, r0B74, 0x03));

         body.emit(assign(r0B64, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B71->else_instructions;

         ir_variable *const r0B79 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B79);
         ir_expression *const r0B7A = lshift(r0B66, body.constant(int(31)));
         body.emit(assign(r0B79, add(r0B7A, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B79, body.constant(0u), 0x01));

         body.emit(assign(r0B65, r0B79, 0x03));

         body.emit(assign(r0B64, body.constant(false), 0x01));


      body.instructions = f0B71_parent_instructions;
      body.emit(f0B71);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B6F->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B7C = equal(r0B6C, body.constant(int(0)));
      ir_if *f0B7B = new(mem_ctx) ir_if(operand(r0B7C).val);
      exec_list *const f0B7B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B7B->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B7E = equal(r0B6B, body.constant(0u));
         ir_if *f0B7D = new(mem_ctx) ir_if(operand(r0B7E).val);
         exec_list *const f0B7D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B7D->then_instructions;

            ir_variable *const r0B7F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B7F);
            body.emit(assign(r0B7F, lshift(r0B66, body.constant(int(31))), 0x02));

            body.emit(assign(r0B7F, body.constant(0u), 0x01));

            body.emit(assign(r0B65, r0B7F, 0x03));

            body.emit(assign(r0B64, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B7D->else_instructions;

            ir_variable *const r0B80 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0B81 = equal(r0B6B, body.constant(0u));
            ir_expression *const r0B82 = expr(ir_unop_find_msb, r0B6B);
            ir_expression *const r0B83 = sub(body.constant(int(31)), r0B82);
            ir_expression *const r0B84 = expr(ir_triop_csel, r0B81, body.constant(int(32)), r0B83);
            body.emit(assign(r0B80, add(r0B84, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B68, lshift(r0B6B, r0B80), 0x01));

            body.emit(assign(r0B67, sub(body.constant(int(1)), r0B80), 0x01));

            body.emit(assign(r0B67, add(r0B67, body.constant(int(-1))), 0x01));


         body.instructions = f0B7D_parent_instructions;
         body.emit(f0B7D);

         /* END IF */


      body.instructions = f0B7B_parent_instructions;
      body.emit(f0B7B);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B85 = new(mem_ctx) ir_if(operand(r0B64).val);
      exec_list *const f0B85_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B85->then_instructions;

         ir_variable *const r0B86 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B86);
         ir_expression *const r0B87 = lshift(r0B66, body.constant(int(31)));
         ir_expression *const r0B88 = add(r0B67, body.constant(int(896)));
         ir_expression *const r0B89 = expr(ir_unop_i2u, r0B88);
         ir_expression *const r0B8A = lshift(r0B89, body.constant(int(20)));
         ir_expression *const r0B8B = add(r0B87, r0B8A);
         ir_expression *const r0B8C = rshift(r0B68, body.constant(int(3)));
         body.emit(assign(r0B86, add(r0B8B, r0B8C), 0x02));

         ir_expression *const r0B8D = lshift(r0B68, body.constant(int(29)));
         body.emit(assign(r0B86, bit_or(r0B8D, body.constant(0u)), 0x01));

         body.emit(assign(r0B65, r0B86, 0x03));

         body.emit(assign(r0B64, body.constant(false), 0x01));


      body.instructions = f0B85_parent_instructions;
      body.emit(f0B85);

      /* END IF */


   body.instructions = f0B6F_parent_instructions;
   body.emit(f0B6F);

   /* END IF */

   body.emit(ret(r0B65));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
