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
   ir_variable *const r00C6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r00C6);
   ir_variable *const r00C7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r00C7);
   ir_variable *const r00C8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r00C9 = neg(r00C1);
   body.emit(assign(r00C8, bit_and(r00C9, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00CB = less(r00C1, body.constant(int(32)));
   ir_if *f00CA = new(mem_ctx) ir_if(operand(r00CB).val);
   exec_list *const f00CA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00CA->then_instructions;

      body.emit(assign(r00C5, lshift(r00BF, r00C8), 0x01));

      ir_expression *const r00CC = lshift(r00BE, r00C8);
      ir_expression *const r00CD = rshift(r00BF, r00C1);
      body.emit(assign(r00C6, bit_or(r00CC, r00CD), 0x01));

      body.emit(assign(r00C7, rshift(r00BE, r00C1), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00CA->else_instructions;

      body.emit(assign(r00C0, bit_or(r00C0, r00BF), 0x01));

      ir_expression *const r00CE = less(r00C1, body.constant(int(64)));
      ir_expression *const r00CF = lshift(r00BE, r00C8);
      ir_expression *const r00D0 = equal(r00C1, body.constant(int(64)));
      ir_expression *const r00D1 = nequal(r00BE, body.constant(0u));
      ir_expression *const r00D2 = expr(ir_unop_b2i, r00D1);
      ir_expression *const r00D3 = expr(ir_unop_i2u, r00D2);
      ir_expression *const r00D4 = expr(ir_triop_csel, r00D0, r00BE, r00D3);
      body.emit(assign(r00C5, expr(ir_triop_csel, r00CE, r00CF, r00D4), 0x01));

      ir_expression *const r00D5 = less(r00C1, body.constant(int(64)));
      ir_expression *const r00D6 = bit_and(r00C1, body.constant(int(31)));
      ir_expression *const r00D7 = rshift(r00BE, r00D6);
      body.emit(assign(r00C6, expr(ir_triop_csel, r00D5, r00D7, body.constant(0u)), 0x01));

      body.emit(assign(r00C7, body.constant(0u), 0x01));


   body.instructions = f00CA_parent_instructions;
   body.emit(f00CA);

   /* END IF */

   ir_expression *const r00D8 = nequal(r00C0, body.constant(0u));
   ir_expression *const r00D9 = expr(ir_unop_b2i, r00D8);
   ir_expression *const r00DA = expr(ir_unop_i2u, r00D9);
   body.emit(assign(r00C5, bit_or(r00C5, r00DA), 0x01));

   ir_variable *const r00DB = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r00DC = equal(r00C1, body.constant(int(0)));
   ir_expression *const r00DD = equal(r00C1, body.constant(int(32)));
   ir_expression *const r00DE = expr(ir_triop_csel, r00DD, body.constant(0u), r00C7);
   body.emit(assign(r00DB, expr(ir_triop_csel, r00DC, r00BE, r00DE), 0x01));

   body.emit(assign(r00C7, r00DB, 0x01));

   ir_variable *const r00DF = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r00E0 = equal(r00C1, body.constant(int(0)));
   ir_expression *const r00E1 = equal(r00C1, body.constant(int(32)));
   ir_expression *const r00E2 = expr(ir_triop_csel, r00E1, r00BE, r00C6);
   body.emit(assign(r00DF, expr(ir_triop_csel, r00E0, r00BF, r00E2), 0x01));

   body.emit(assign(r00C6, r00DF, 0x01));

   ir_variable *const r00E3 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r00E4 = equal(r00C1, body.constant(int(0)));
   ir_expression *const r00E5 = equal(r00C1, body.constant(int(32)));
   ir_expression *const r00E6 = expr(ir_triop_csel, r00E5, r00BF, r00C5);
   body.emit(assign(r00E3, expr(ir_triop_csel, r00E4, r00C0, r00E6), 0x01));

   body.emit(assign(r00C5, r00E3, 0x01));

   body.emit(assign(r00C4, r00E3, 0x01));

   body.emit(assign(r00C3, r00DF, 0x01));

   body.emit(assign(r00C2, r00DB, 0x01));

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

   ir_variable *const r00E7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00E7);
   ir_variable *const r00E8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00E8);
   ir_variable *const r00E9 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00E9);
   ir_variable *const r00EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00EA);
   ir_variable *const r00EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00EB);
   body.emit(assign(r00EB, lshift(r00E8, r00E9), 0x01));

   ir_expression *const r00EC = equal(r00E9, body.constant(int(0)));
   ir_expression *const r00ED = lshift(r00E7, r00E9);
   ir_expression *const r00EE = neg(r00E9);
   ir_expression *const r00EF = bit_and(r00EE, body.constant(int(31)));
   ir_expression *const r00F0 = rshift(r00E8, r00EF);
   ir_expression *const r00F1 = bit_or(r00ED, r00F0);
   body.emit(assign(r00EA, expr(ir_triop_csel, r00EC, r00E7, r00F1), 0x01));

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

   ir_variable *const r00F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00F2);
   ir_variable *const r00F3 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00F3);
   ir_variable *const r00F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00F4);
   ir_variable *const r00F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00F5);
   ir_variable *const r00F6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
   body.emit(r00F6);
   ir_expression *const r00F7 = lshift(r00F2, body.constant(int(31)));
   ir_expression *const r00F8 = expr(ir_unop_i2u, r00F3);
   ir_expression *const r00F9 = lshift(r00F8, body.constant(int(20)));
   ir_expression *const r00FA = add(r00F7, r00F9);
   body.emit(assign(r00F6, add(r00FA, r00F4), 0x02));

   body.emit(assign(r00F6, r00F5, 0x01));

   body.emit(ret(r00F6));

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

   ir_variable *const r00FB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00FB);
   ir_variable *const r00FC = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00FC);
   ir_variable *const r00FD = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00FD);
   ir_variable *const r00FE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00FE);
   ir_variable *const r00FF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_function_in);
   sig_parameters.push_tail(r00FF);
   ir_variable *const r0100 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0100, body.constant(true), 0x01));

   ir_variable *const r0101 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0102 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r0102);
   ir_expression *const r0103 = expr(ir_unop_u2i, r00FF);
   body.emit(assign(r0102, less(r0103, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0105 = gequal(r00FC, body.constant(int(2045)));
   ir_if *f0104 = new(mem_ctx) ir_if(operand(r0105).val);
   exec_list *const f0104_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0104->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0107 = less(body.constant(int(2045)), r00FC);
      ir_expression *const r0108 = equal(r00FC, body.constant(int(2045)));
      ir_expression *const r0109 = equal(body.constant(2097151u), r00FD);
      ir_expression *const r010A = equal(body.constant(4294967295u), r00FE);
      ir_expression *const r010B = logic_and(r0109, r010A);
      ir_expression *const r010C = logic_and(r0108, r010B);
      ir_expression *const r010D = logic_and(r010C, r0102);
      ir_expression *const r010E = logic_or(r0107, r010D);
      ir_if *f0106 = new(mem_ctx) ir_if(operand(r010E).val);
      exec_list *const f0106_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0106->then_instructions;

         ir_variable *const r010F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r010F);
         ir_expression *const r0110 = lshift(r00FB, body.constant(int(31)));
         body.emit(assign(r010F, add(r0110, body.constant(2146435072u)), 0x02));

         body.emit(assign(r010F, body.constant(0u), 0x01));

         body.emit(assign(r0101, r010F, 0x03));

         body.emit(assign(r0100, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0106->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0112 = less(r00FC, body.constant(int(0)));
         ir_if *f0111 = new(mem_ctx) ir_if(operand(r0112).val);
         exec_list *const f0111_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0111->then_instructions;

            ir_variable *const r0113 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0113, r00FF, 0x01));

            ir_variable *const r0114 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r0114, neg(r00FC), 0x01));

            ir_variable *const r0115 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0115);
            ir_variable *const r0116 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0116);
            ir_variable *const r0117 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0117);
            ir_variable *const r0118 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0119 = neg(r0114);
            body.emit(assign(r0118, bit_and(r0119, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r011B = less(r0114, body.constant(int(32)));
            ir_if *f011A = new(mem_ctx) ir_if(operand(r011B).val);
            exec_list *const f011A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f011A->then_instructions;

               body.emit(assign(r0115, lshift(r00FE, r0118), 0x01));

               ir_expression *const r011C = lshift(r00FD, r0118);
               ir_expression *const r011D = rshift(r00FE, r0114);
               body.emit(assign(r0116, bit_or(r011C, r011D), 0x01));

               body.emit(assign(r0117, rshift(r00FD, r0114), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f011A->else_instructions;

               body.emit(assign(r0113, bit_or(r00FF, r00FE), 0x01));

               ir_expression *const r011E = less(r0114, body.constant(int(64)));
               ir_expression *const r011F = lshift(r00FD, r0118);
               ir_expression *const r0120 = equal(r0114, body.constant(int(64)));
               ir_expression *const r0121 = nequal(r00FD, body.constant(0u));
               ir_expression *const r0122 = expr(ir_unop_b2i, r0121);
               ir_expression *const r0123 = expr(ir_unop_i2u, r0122);
               ir_expression *const r0124 = expr(ir_triop_csel, r0120, r00FD, r0123);
               body.emit(assign(r0115, expr(ir_triop_csel, r011E, r011F, r0124), 0x01));

               ir_expression *const r0125 = less(r0114, body.constant(int(64)));
               ir_expression *const r0126 = bit_and(r0114, body.constant(int(31)));
               ir_expression *const r0127 = rshift(r00FD, r0126);
               body.emit(assign(r0116, expr(ir_triop_csel, r0125, r0127, body.constant(0u)), 0x01));

               body.emit(assign(r0117, body.constant(0u), 0x01));


            body.instructions = f011A_parent_instructions;
            body.emit(f011A);

            /* END IF */

            ir_expression *const r0128 = nequal(r0113, body.constant(0u));
            ir_expression *const r0129 = expr(ir_unop_b2i, r0128);
            ir_expression *const r012A = expr(ir_unop_i2u, r0129);
            body.emit(assign(r0115, bit_or(r0115, r012A), 0x01));

            ir_variable *const r012B = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r012C = equal(r0114, body.constant(int(0)));
            ir_expression *const r012D = equal(r0114, body.constant(int(32)));
            ir_expression *const r012E = expr(ir_triop_csel, r012D, body.constant(0u), r0117);
            body.emit(assign(r012B, expr(ir_triop_csel, r012C, r00FD, r012E), 0x01));

            body.emit(assign(r0117, r012B, 0x01));

            ir_variable *const r012F = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0130 = equal(r0114, body.constant(int(0)));
            ir_expression *const r0131 = equal(r0114, body.constant(int(32)));
            ir_expression *const r0132 = expr(ir_triop_csel, r0131, r00FD, r0116);
            body.emit(assign(r012F, expr(ir_triop_csel, r0130, r00FE, r0132), 0x01));

            body.emit(assign(r0116, r012F, 0x01));

            ir_variable *const r0133 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0134 = equal(r0114, body.constant(int(0)));
            ir_expression *const r0135 = equal(r0114, body.constant(int(32)));
            ir_expression *const r0136 = expr(ir_triop_csel, r0135, r00FE, r0115);
            body.emit(assign(r0133, expr(ir_triop_csel, r0134, r0113, r0136), 0x01));

            body.emit(assign(r0115, r0133, 0x01));

            body.emit(assign(r00FD, r012B, 0x01));

            body.emit(assign(r00FE, r012F, 0x01));

            body.emit(assign(r00FF, r0133, 0x01));

            body.emit(assign(r00FC, body.constant(int(0)), 0x01));

            body.emit(assign(r0102, less(r0133, body.constant(0u)), 0x01));


         body.instructions = f0111_parent_instructions;
         body.emit(f0111);

         /* END IF */


      body.instructions = f0106_parent_instructions;
      body.emit(f0106);

      /* END IF */


   body.instructions = f0104_parent_instructions;
   body.emit(f0104);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0137 = new(mem_ctx) ir_if(operand(r0100).val);
   exec_list *const f0137_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0137->then_instructions;

      /* IF CONDITION */
      ir_if *f0138 = new(mem_ctx) ir_if(operand(r0102).val);
      exec_list *const f0138_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0138->then_instructions;

         ir_variable *const r0139 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0139, add(r00FE, body.constant(1u)), 0x01));

         ir_expression *const r013A = less(r0139, r00FE);
         ir_expression *const r013B = expr(ir_unop_b2i, r013A);
         ir_expression *const r013C = expr(ir_unop_i2u, r013B);
         body.emit(assign(r00FD, add(r00FD, r013C), 0x01));

         ir_expression *const r013D = equal(r00FF, body.constant(0u));
         ir_expression *const r013E = expr(ir_unop_b2i, r013D);
         ir_expression *const r013F = expr(ir_unop_i2u, r013E);
         ir_expression *const r0140 = add(r00FF, r013F);
         ir_expression *const r0141 = bit_and(r0140, body.constant(1u));
         ir_expression *const r0142 = expr(ir_unop_bit_not, r0141);
         body.emit(assign(r00FE, bit_and(r0139, r0142), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0138->else_instructions;

         ir_expression *const r0143 = bit_or(r00FD, r00FE);
         ir_expression *const r0144 = equal(r0143, body.constant(0u));
         body.emit(assign(r00FC, expr(ir_triop_csel, r0144, body.constant(int(0)), r00FC), 0x01));


      body.instructions = f0138_parent_instructions;
      body.emit(f0138);

      /* END IF */

      ir_variable *const r0145 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0145);
      ir_expression *const r0146 = lshift(r00FB, body.constant(int(31)));
      ir_expression *const r0147 = expr(ir_unop_i2u, r00FC);
      ir_expression *const r0148 = lshift(r0147, body.constant(int(20)));
      ir_expression *const r0149 = add(r0146, r0148);
      body.emit(assign(r0145, add(r0149, r00FD), 0x02));

      body.emit(assign(r0145, r00FE, 0x01));

      body.emit(assign(r0101, r0145, 0x03));

      body.emit(assign(r0100, body.constant(false), 0x01));


   body.instructions = f0137_parent_instructions;
   body.emit(f0137);

   /* END IF */

   body.emit(ret(r0101));

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

   ir_variable *const r014A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r014A);
   ir_variable *const r014B = body.make_temp(glsl_type::int_type, "mix_retval");
   ir_expression *const r014C = equal(r014A, body.constant(0u));
   ir_expression *const r014D = expr(ir_unop_find_msb, r014A);
   ir_expression *const r014E = sub(body.constant(int(31)), r014D);
   body.emit(assign(r014B, expr(ir_triop_csel, r014C, body.constant(int(32)), r014E), 0x01));

   body.emit(ret(r014B));

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

   ir_variable *const r014F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r014F);
   ir_variable *const r0150 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0150);
   ir_variable *const r0151 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0151);
   ir_variable *const r0152 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0152);
   ir_variable *const r0153 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0153);
   ir_variable *const r0154 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0154);
   ir_expression *const r0155 = equal(r0151, body.constant(0u));
   ir_expression *const r0156 = add(r0150, body.constant(int(-32)));
   body.emit(assign(r0150, expr(ir_triop_csel, r0155, r0156, r0150), 0x01));

   ir_variable *const r0157 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r0158 = equal(r0151, body.constant(0u));
   body.emit(assign(r0157, expr(ir_triop_csel, r0158, body.constant(0u), r0152), 0x01));

   body.emit(assign(r0152, r0157, 0x01));

   ir_variable *const r0159 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r015A = equal(r0151, body.constant(0u));
   body.emit(assign(r0159, expr(ir_triop_csel, r015A, r0157, r0151), 0x01));

   body.emit(assign(r0151, r0159, 0x01));

   ir_expression *const r015B = equal(r0159, body.constant(0u));
   ir_expression *const r015C = expr(ir_unop_find_msb, r0159);
   ir_expression *const r015D = sub(body.constant(int(31)), r015C);
   ir_expression *const r015E = expr(ir_triop_csel, r015B, body.constant(int(32)), r015D);
   body.emit(assign(r0154, add(r015E, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0160 = gequal(r0154, body.constant(int(0)));
   ir_if *f015F = new(mem_ctx) ir_if(operand(r0160).val);
   exec_list *const f015F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f015F->then_instructions;

      body.emit(assign(r0153, body.constant(0u), 0x01));

      ir_expression *const r0161 = equal(r0154, body.constant(int(0)));
      ir_expression *const r0162 = lshift(r0159, r0154);
      ir_expression *const r0163 = neg(r0154);
      ir_expression *const r0164 = bit_and(r0163, body.constant(int(31)));
      ir_expression *const r0165 = rshift(r0157, r0164);
      ir_expression *const r0166 = bit_or(r0162, r0165);
      body.emit(assign(r0151, expr(ir_triop_csel, r0161, r0159, r0166), 0x01));

      body.emit(assign(r0152, lshift(r0157, r0154), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f015F->else_instructions;

      ir_variable *const r0167 = body.make_temp(glsl_type::uint_type, "a2");
      body.emit(assign(r0167, body.constant(0u), 0x01));

      ir_variable *const r0168 = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r0168, neg(r0154), 0x01));

      ir_variable *const r0169 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
      body.emit(r0169);
      ir_variable *const r016A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r016A);
      ir_variable *const r016B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r016B);
      ir_variable *const r016C = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r016D = neg(r0168);
      body.emit(assign(r016C, bit_and(r016D, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r016F = less(r0168, body.constant(int(32)));
      ir_if *f016E = new(mem_ctx) ir_if(operand(r016F).val);
      exec_list *const f016E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f016E->then_instructions;

         body.emit(assign(r0169, lshift(r0152, r016C), 0x01));

         ir_expression *const r0170 = lshift(r0151, r016C);
         ir_expression *const r0171 = rshift(r0152, r0168);
         body.emit(assign(r016A, bit_or(r0170, r0171), 0x01));

         body.emit(assign(r016B, rshift(r0151, r0168), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f016E->else_instructions;

         body.emit(assign(r0167, bit_or(body.constant(0u), r0152), 0x01));

         ir_expression *const r0172 = less(r0168, body.constant(int(64)));
         ir_expression *const r0173 = lshift(r0151, r016C);
         ir_expression *const r0174 = equal(r0168, body.constant(int(64)));
         ir_expression *const r0175 = nequal(r0151, body.constant(0u));
         ir_expression *const r0176 = expr(ir_unop_b2i, r0175);
         ir_expression *const r0177 = expr(ir_unop_i2u, r0176);
         ir_expression *const r0178 = expr(ir_triop_csel, r0174, r0151, r0177);
         body.emit(assign(r0169, expr(ir_triop_csel, r0172, r0173, r0178), 0x01));

         ir_expression *const r0179 = less(r0168, body.constant(int(64)));
         ir_expression *const r017A = bit_and(r0168, body.constant(int(31)));
         ir_expression *const r017B = rshift(r0151, r017A);
         body.emit(assign(r016A, expr(ir_triop_csel, r0179, r017B, body.constant(0u)), 0x01));

         body.emit(assign(r016B, body.constant(0u), 0x01));


      body.instructions = f016E_parent_instructions;
      body.emit(f016E);

      /* END IF */

      ir_expression *const r017C = nequal(r0167, body.constant(0u));
      ir_expression *const r017D = expr(ir_unop_b2i, r017C);
      ir_expression *const r017E = expr(ir_unop_i2u, r017D);
      body.emit(assign(r0169, bit_or(r0169, r017E), 0x01));

      ir_variable *const r017F = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0180 = equal(r0168, body.constant(int(0)));
      ir_expression *const r0181 = equal(r0168, body.constant(int(32)));
      ir_expression *const r0182 = expr(ir_triop_csel, r0181, body.constant(0u), r016B);
      body.emit(assign(r017F, expr(ir_triop_csel, r0180, r0151, r0182), 0x01));

      body.emit(assign(r016B, r017F, 0x01));

      ir_variable *const r0183 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0184 = equal(r0168, body.constant(int(0)));
      ir_expression *const r0185 = equal(r0168, body.constant(int(32)));
      ir_expression *const r0186 = expr(ir_triop_csel, r0185, r0151, r016A);
      body.emit(assign(r0183, expr(ir_triop_csel, r0184, r0152, r0186), 0x01));

      body.emit(assign(r016A, r0183, 0x01));

      ir_variable *const r0187 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0188 = equal(r0168, body.constant(int(0)));
      ir_expression *const r0189 = equal(r0168, body.constant(int(32)));
      ir_expression *const r018A = expr(ir_triop_csel, r0189, r0152, r0169);
      body.emit(assign(r0187, expr(ir_triop_csel, r0188, r0167, r018A), 0x01));

      body.emit(assign(r0169, r0187, 0x01));

      body.emit(assign(r0151, r017F, 0x01));

      body.emit(assign(r0152, r0183, 0x01));

      body.emit(assign(r0153, r0187, 0x01));


   body.instructions = f015F_parent_instructions;
   body.emit(f015F);

   /* END IF */

   body.emit(assign(r0150, sub(r0150, r0154), 0x01));

   ir_variable *const r018B = body.make_temp(glsl_type::int_type, "zExp");
   body.emit(assign(r018B, r0150, 0x01));

   ir_variable *const r018C = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r018C, r0151, 0x01));

   ir_variable *const r018D = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r018D, r0152, 0x01));

   ir_variable *const r018E = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r018E, r0153, 0x01));

   ir_variable *const r018F = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r018F, body.constant(true), 0x01));

   ir_variable *const r0190 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0191 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r0191);
   ir_expression *const r0192 = expr(ir_unop_u2i, r0153);
   body.emit(assign(r0191, less(r0192, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0194 = gequal(r0150, body.constant(int(2045)));
   ir_if *f0193 = new(mem_ctx) ir_if(operand(r0194).val);
   exec_list *const f0193_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0193->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0196 = less(body.constant(int(2045)), r0150);
      ir_expression *const r0197 = equal(r0150, body.constant(int(2045)));
      ir_expression *const r0198 = equal(body.constant(2097151u), r0151);
      ir_expression *const r0199 = equal(body.constant(4294967295u), r0152);
      ir_expression *const r019A = logic_and(r0198, r0199);
      ir_expression *const r019B = logic_and(r0197, r019A);
      ir_expression *const r019C = logic_and(r019B, r0191);
      ir_expression *const r019D = logic_or(r0196, r019C);
      ir_if *f0195 = new(mem_ctx) ir_if(operand(r019D).val);
      exec_list *const f0195_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0195->then_instructions;

         ir_variable *const r019E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r019E);
         ir_expression *const r019F = lshift(r014F, body.constant(int(31)));
         body.emit(assign(r019E, add(r019F, body.constant(2146435072u)), 0x02));

         body.emit(assign(r019E, body.constant(0u), 0x01));

         body.emit(assign(r0190, r019E, 0x03));

         body.emit(assign(r018F, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0195->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01A1 = less(r0150, body.constant(int(0)));
         ir_if *f01A0 = new(mem_ctx) ir_if(operand(r01A1).val);
         exec_list *const f01A0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01A0->then_instructions;

            ir_variable *const r01A2 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r01A2, r0153, 0x01));

            ir_variable *const r01A3 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r01A3, neg(r0150), 0x01));

            ir_variable *const r01A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r01A4);
            ir_variable *const r01A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r01A5);
            ir_variable *const r01A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r01A6);
            ir_variable *const r01A7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r01A8 = neg(r01A3);
            body.emit(assign(r01A7, bit_and(r01A8, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r01AA = less(r01A3, body.constant(int(32)));
            ir_if *f01A9 = new(mem_ctx) ir_if(operand(r01AA).val);
            exec_list *const f01A9_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01A9->then_instructions;

               body.emit(assign(r01A4, lshift(r0152, r01A7), 0x01));

               ir_expression *const r01AB = lshift(r0151, r01A7);
               ir_expression *const r01AC = rshift(r0152, r01A3);
               body.emit(assign(r01A5, bit_or(r01AB, r01AC), 0x01));

               body.emit(assign(r01A6, rshift(r0151, r01A3), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01A9->else_instructions;

               body.emit(assign(r01A2, bit_or(r0153, r0152), 0x01));

               ir_expression *const r01AD = less(r01A3, body.constant(int(64)));
               ir_expression *const r01AE = lshift(r0151, r01A7);
               ir_expression *const r01AF = equal(r01A3, body.constant(int(64)));
               ir_expression *const r01B0 = nequal(r0151, body.constant(0u));
               ir_expression *const r01B1 = expr(ir_unop_b2i, r01B0);
               ir_expression *const r01B2 = expr(ir_unop_i2u, r01B1);
               ir_expression *const r01B3 = expr(ir_triop_csel, r01AF, r0151, r01B2);
               body.emit(assign(r01A4, expr(ir_triop_csel, r01AD, r01AE, r01B3), 0x01));

               ir_expression *const r01B4 = less(r01A3, body.constant(int(64)));
               ir_expression *const r01B5 = bit_and(r01A3, body.constant(int(31)));
               ir_expression *const r01B6 = rshift(r0151, r01B5);
               body.emit(assign(r01A5, expr(ir_triop_csel, r01B4, r01B6, body.constant(0u)), 0x01));

               body.emit(assign(r01A6, body.constant(0u), 0x01));


            body.instructions = f01A9_parent_instructions;
            body.emit(f01A9);

            /* END IF */

            ir_expression *const r01B7 = nequal(r01A2, body.constant(0u));
            ir_expression *const r01B8 = expr(ir_unop_b2i, r01B7);
            ir_expression *const r01B9 = expr(ir_unop_i2u, r01B8);
            body.emit(assign(r01A4, bit_or(r01A4, r01B9), 0x01));

            ir_variable *const r01BA = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r01BB = equal(r01A3, body.constant(int(0)));
            ir_expression *const r01BC = equal(r01A3, body.constant(int(32)));
            ir_expression *const r01BD = expr(ir_triop_csel, r01BC, body.constant(0u), r01A6);
            body.emit(assign(r01BA, expr(ir_triop_csel, r01BB, r0151, r01BD), 0x01));

            body.emit(assign(r01A6, r01BA, 0x01));

            ir_variable *const r01BE = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r01BF = equal(r01A3, body.constant(int(0)));
            ir_expression *const r01C0 = equal(r01A3, body.constant(int(32)));
            ir_expression *const r01C1 = expr(ir_triop_csel, r01C0, r0151, r01A5);
            body.emit(assign(r01BE, expr(ir_triop_csel, r01BF, r0152, r01C1), 0x01));

            body.emit(assign(r01A5, r01BE, 0x01));

            ir_variable *const r01C2 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r01C3 = equal(r01A3, body.constant(int(0)));
            ir_expression *const r01C4 = equal(r01A3, body.constant(int(32)));
            ir_expression *const r01C5 = expr(ir_triop_csel, r01C4, r0152, r01A4);
            body.emit(assign(r01C2, expr(ir_triop_csel, r01C3, r01A2, r01C5), 0x01));

            body.emit(assign(r01A4, r01C2, 0x01));

            body.emit(assign(r018C, r01BA, 0x01));

            body.emit(assign(r018D, r01BE, 0x01));

            body.emit(assign(r018E, r01C2, 0x01));

            body.emit(assign(r018B, body.constant(int(0)), 0x01));

            body.emit(assign(r0191, less(r01C2, body.constant(0u)), 0x01));


         body.instructions = f01A0_parent_instructions;
         body.emit(f01A0);

         /* END IF */


      body.instructions = f0195_parent_instructions;
      body.emit(f0195);

      /* END IF */


   body.instructions = f0193_parent_instructions;
   body.emit(f0193);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01C6 = new(mem_ctx) ir_if(operand(r018F).val);
   exec_list *const f01C6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01C6->then_instructions;

      /* IF CONDITION */
      ir_if *f01C7 = new(mem_ctx) ir_if(operand(r0191).val);
      exec_list *const f01C7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01C7->then_instructions;

         ir_variable *const r01C8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01C8, add(r018D, body.constant(1u)), 0x01));

         ir_expression *const r01C9 = less(r01C8, r018D);
         ir_expression *const r01CA = expr(ir_unop_b2i, r01C9);
         ir_expression *const r01CB = expr(ir_unop_i2u, r01CA);
         body.emit(assign(r018C, add(r018C, r01CB), 0x01));

         ir_expression *const r01CC = equal(r018E, body.constant(0u));
         ir_expression *const r01CD = expr(ir_unop_b2i, r01CC);
         ir_expression *const r01CE = expr(ir_unop_i2u, r01CD);
         ir_expression *const r01CF = add(r018E, r01CE);
         ir_expression *const r01D0 = bit_and(r01CF, body.constant(1u));
         ir_expression *const r01D1 = expr(ir_unop_bit_not, r01D0);
         body.emit(assign(r018D, bit_and(r01C8, r01D1), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01C7->else_instructions;

         ir_expression *const r01D2 = bit_or(r018C, r018D);
         ir_expression *const r01D3 = equal(r01D2, body.constant(0u));
         body.emit(assign(r018B, expr(ir_triop_csel, r01D3, body.constant(int(0)), r018B), 0x01));


      body.instructions = f01C7_parent_instructions;
      body.emit(f01C7);

      /* END IF */

      ir_variable *const r01D4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r01D4);
      ir_expression *const r01D5 = lshift(r014F, body.constant(int(31)));
      ir_expression *const r01D6 = expr(ir_unop_i2u, r018B);
      ir_expression *const r01D7 = lshift(r01D6, body.constant(int(20)));
      ir_expression *const r01D8 = add(r01D5, r01D7);
      body.emit(assign(r01D4, add(r01D8, r018C), 0x02));

      body.emit(assign(r01D4, r018D, 0x01));

      body.emit(assign(r0190, r01D4, 0x03));

      body.emit(assign(r018F, body.constant(false), 0x01));


   body.instructions = f01C6_parent_instructions;
   body.emit(f01C6);

   /* END IF */

   body.emit(ret(r0190));

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

   ir_variable *const r01D9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01D9);
   ir_variable *const r01DA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01DA);
   ir_variable *const r01DB = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01DC = lshift(swizzle_y(r01D9), body.constant(int(1)));
   ir_expression *const r01DD = gequal(r01DC, body.constant(4292870144u));
   ir_expression *const r01DE = nequal(swizzle_x(r01D9), body.constant(0u));
   ir_expression *const r01DF = bit_and(swizzle_y(r01D9), body.constant(1048575u));
   ir_expression *const r01E0 = nequal(r01DF, body.constant(0u));
   ir_expression *const r01E1 = logic_or(r01DE, r01E0);
   body.emit(assign(r01DB, logic_and(r01DD, r01E1), 0x01));

   ir_variable *const r01E2 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01E3 = lshift(swizzle_y(r01DA), body.constant(int(1)));
   ir_expression *const r01E4 = gequal(r01E3, body.constant(4292870144u));
   ir_expression *const r01E5 = nequal(swizzle_x(r01DA), body.constant(0u));
   ir_expression *const r01E6 = bit_and(swizzle_y(r01DA), body.constant(1048575u));
   ir_expression *const r01E7 = nequal(r01E6, body.constant(0u));
   ir_expression *const r01E8 = logic_or(r01E5, r01E7);
   body.emit(assign(r01E2, logic_and(r01E4, r01E8), 0x01));

   body.emit(assign(r01D9, bit_or(swizzle_y(r01D9), body.constant(524288u)), 0x02));

   body.emit(assign(r01DA, bit_or(swizzle_y(r01DA), body.constant(524288u)), 0x02));

   ir_variable *const r01E9 = body.make_temp(glsl_type::uvec2_type, "mix_retval");
   ir_swizzle *const r01EA = swizzle(r01DB, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_swizzle *const r01EB = swizzle(r01E2, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_expression *const r01EC = expr(ir_triop_csel, r01EB, r01DA, r01D9);
   body.emit(assign(r01E9, expr(ir_triop_csel, r01EA, r01EC, r01DA), 0x03));

   body.emit(ret(r01E9));

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

   ir_variable *const r01ED = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01ED);
   ir_variable *const r01EE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01EE);
   ir_variable *const r01EF = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01EF, body.constant(true), 0x01));

   ir_variable *const r01F0 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01F1 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
   body.emit(r01F1);
   ir_variable *const r01F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r01F2);
   ir_variable *const r01F3 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r01F3);
   ir_variable *const r01F4 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r01F4);
   ir_variable *const r01F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r01F5);
   ir_variable *const r01F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r01F6);
   ir_variable *const r01F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r01F7);
   ir_variable *const r01F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r01F8);
   ir_variable *const r01F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r01F9);
   ir_variable *const r01FA = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01FA, rshift(swizzle_y(r01ED), body.constant(int(31))), 0x01));

   body.emit(assign(r01F9, r01FA, 0x01));

   ir_variable *const r01FB = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01FB, rshift(swizzle_y(r01EE), body.constant(int(31))), 0x01));

   body.emit(assign(r01F8, swizzle_x(r01ED), 0x01));

   ir_variable *const r01FC = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r01FC, bit_and(swizzle_y(r01ED), body.constant(1048575u)), 0x01));

   body.emit(assign(r01F7, r01FC, 0x01));

   body.emit(assign(r01F6, swizzle_x(r01EE), 0x01));

   ir_variable *const r01FD = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r01FD, bit_and(swizzle_y(r01EE), body.constant(1048575u)), 0x01));

   body.emit(assign(r01F5, r01FD, 0x01));

   ir_variable *const r01FE = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r01FF = rshift(swizzle_y(r01ED), body.constant(int(20)));
   ir_expression *const r0200 = bit_and(r01FF, body.constant(2047u));
   body.emit(assign(r01FE, expr(ir_unop_u2i, r0200), 0x01));

   body.emit(assign(r01F4, r01FE, 0x01));

   ir_variable *const r0201 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0202 = rshift(swizzle_y(r01EE), body.constant(int(20)));
   ir_expression *const r0203 = bit_and(r0202, body.constant(2047u));
   body.emit(assign(r0201, expr(ir_unop_u2i, r0203), 0x01));

   body.emit(assign(r01F3, r0201, 0x01));

   body.emit(assign(r01F2, body.constant(0u), 0x01));

   ir_variable *const r0204 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0204, sub(r01FE, r0201), 0x01));

   body.emit(assign(r01F1, r0204, 0x01));

   /* IF CONDITION */
   ir_expression *const r0206 = equal(r01FA, r01FB);
   ir_if *f0205 = new(mem_ctx) ir_if(operand(r0206).val);
   exec_list *const f0205_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0205->then_instructions;

      ir_variable *const r0207 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r0207);
      ir_variable *const r0208 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r0208);
      body.emit(assign(r0208, body.constant(0u), 0x01));

      /* IF CONDITION */
      ir_expression *const r020A = less(body.constant(int(0)), r0204);
      ir_if *f0209 = new(mem_ctx) ir_if(operand(r020A).val);
      exec_list *const f0209_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0209->then_instructions;

         /* IF CONDITION */
         ir_expression *const r020C = equal(r01FE, body.constant(int(2047)));
         ir_if *f020B = new(mem_ctx) ir_if(operand(r020C).val);
         exec_list *const f020B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f020B->then_instructions;

            ir_variable *const r020D = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r020D, swizzle_x(r01ED), 0x01));

            ir_variable *const r020E = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r020E, swizzle_x(r01EE), 0x01));

            body.emit(assign(r020D, bit_or(swizzle_y(r01ED), body.constant(524288u)), 0x02));

            body.emit(assign(r020E, bit_or(swizzle_y(r01EE), body.constant(524288u)), 0x02));

            ir_expression *const r020F = bit_or(r01FC, swizzle_x(r01ED));
            ir_expression *const r0210 = nequal(r020F, body.constant(0u));
            ir_swizzle *const r0211 = swizzle(r0210, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0212 = lshift(swizzle_y(r01ED), body.constant(int(1)));
            ir_expression *const r0213 = gequal(r0212, body.constant(4292870144u));
            ir_expression *const r0214 = nequal(swizzle_x(r01ED), body.constant(0u));
            ir_expression *const r0215 = bit_and(swizzle_y(r01ED), body.constant(1048575u));
            ir_expression *const r0216 = nequal(r0215, body.constant(0u));
            ir_expression *const r0217 = logic_or(r0214, r0216);
            ir_expression *const r0218 = logic_and(r0213, r0217);
            ir_swizzle *const r0219 = swizzle(r0218, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r021A = lshift(swizzle_y(r01EE), body.constant(int(1)));
            ir_expression *const r021B = gequal(r021A, body.constant(4292870144u));
            ir_expression *const r021C = nequal(swizzle_x(r01EE), body.constant(0u));
            ir_expression *const r021D = bit_and(swizzle_y(r01EE), body.constant(1048575u));
            ir_expression *const r021E = nequal(r021D, body.constant(0u));
            ir_expression *const r021F = logic_or(r021C, r021E);
            ir_expression *const r0220 = logic_and(r021B, r021F);
            ir_swizzle *const r0221 = swizzle(r0220, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0222 = expr(ir_triop_csel, r0221, r020E, r020D);
            ir_expression *const r0223 = expr(ir_triop_csel, r0219, r0222, r020E);
            body.emit(assign(r01F0, expr(ir_triop_csel, r0211, r0223, r01ED), 0x03));

            body.emit(assign(r01EF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f020B->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0225 = equal(r0201, body.constant(int(0)));
            ir_if *f0224 = new(mem_ctx) ir_if(operand(r0225).val);
            exec_list *const f0224_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0224->then_instructions;

               body.emit(assign(r01F1, add(r0204, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0224->else_instructions;

               body.emit(assign(r01F5, bit_or(r01FD, body.constant(1048576u)), 0x01));


            body.instructions = f0224_parent_instructions;
            body.emit(f0224);

            /* END IF */

            ir_variable *const r0226 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0226, body.constant(0u), 0x01));

            ir_variable *const r0227 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0227);
            ir_variable *const r0228 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0228);
            ir_variable *const r0229 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0229);
            ir_variable *const r022A = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r022B = neg(r01F1);
            body.emit(assign(r022A, bit_and(r022B, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r022D = less(r01F1, body.constant(int(32)));
            ir_if *f022C = new(mem_ctx) ir_if(operand(r022D).val);
            exec_list *const f022C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f022C->then_instructions;

               body.emit(assign(r0227, lshift(swizzle_x(r01EE), r022A), 0x01));

               ir_expression *const r022E = lshift(r01F5, r022A);
               ir_expression *const r022F = rshift(swizzle_x(r01EE), r01F1);
               body.emit(assign(r0228, bit_or(r022E, r022F), 0x01));

               body.emit(assign(r0229, rshift(r01F5, r01F1), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f022C->else_instructions;

               body.emit(assign(r0226, bit_or(body.constant(0u), swizzle_x(r01EE)), 0x01));

               ir_expression *const r0230 = less(r01F1, body.constant(int(64)));
               ir_expression *const r0231 = lshift(r01F5, r022A);
               ir_expression *const r0232 = equal(r01F1, body.constant(int(64)));
               ir_expression *const r0233 = nequal(r01F5, body.constant(0u));
               ir_expression *const r0234 = expr(ir_unop_b2i, r0233);
               ir_expression *const r0235 = expr(ir_unop_i2u, r0234);
               ir_expression *const r0236 = expr(ir_triop_csel, r0232, r01F5, r0235);
               body.emit(assign(r0227, expr(ir_triop_csel, r0230, r0231, r0236), 0x01));

               ir_expression *const r0237 = less(r01F1, body.constant(int(64)));
               ir_expression *const r0238 = bit_and(r01F1, body.constant(int(31)));
               ir_expression *const r0239 = rshift(r01F5, r0238);
               body.emit(assign(r0228, expr(ir_triop_csel, r0237, r0239, body.constant(0u)), 0x01));

               body.emit(assign(r0229, body.constant(0u), 0x01));


            body.instructions = f022C_parent_instructions;
            body.emit(f022C);

            /* END IF */

            ir_expression *const r023A = nequal(r0226, body.constant(0u));
            ir_expression *const r023B = expr(ir_unop_b2i, r023A);
            ir_expression *const r023C = expr(ir_unop_i2u, r023B);
            body.emit(assign(r0227, bit_or(r0227, r023C), 0x01));

            ir_variable *const r023D = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r023E = equal(r01F1, body.constant(int(0)));
            ir_expression *const r023F = equal(r01F1, body.constant(int(32)));
            ir_expression *const r0240 = expr(ir_triop_csel, r023F, body.constant(0u), r0229);
            body.emit(assign(r023D, expr(ir_triop_csel, r023E, r01F5, r0240), 0x01));

            body.emit(assign(r0229, r023D, 0x01));

            ir_variable *const r0241 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0242 = equal(r01F1, body.constant(int(0)));
            ir_expression *const r0243 = equal(r01F1, body.constant(int(32)));
            ir_expression *const r0244 = expr(ir_triop_csel, r0243, r01F5, r0228);
            body.emit(assign(r0241, expr(ir_triop_csel, r0242, swizzle_x(r01EE), r0244), 0x01));

            body.emit(assign(r0228, r0241, 0x01));

            ir_variable *const r0245 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0246 = equal(r01F1, body.constant(int(0)));
            ir_expression *const r0247 = equal(r01F1, body.constant(int(32)));
            ir_expression *const r0248 = expr(ir_triop_csel, r0247, swizzle_x(r01EE), r0227);
            body.emit(assign(r0245, expr(ir_triop_csel, r0246, r0226, r0248), 0x01));

            body.emit(assign(r0227, r0245, 0x01));

            body.emit(assign(r01F5, r023D, 0x01));

            body.emit(assign(r01F6, r0241, 0x01));

            body.emit(assign(r0208, r0245, 0x01));

            body.emit(assign(r0207, r01FE, 0x01));


         body.instructions = f020B_parent_instructions;
         body.emit(f020B);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0209->else_instructions;

         /* IF CONDITION */
         ir_expression *const r024A = less(r01F1, body.constant(int(0)));
         ir_if *f0249 = new(mem_ctx) ir_if(operand(r024A).val);
         exec_list *const f0249_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0249->then_instructions;

            /* IF CONDITION */
            ir_expression *const r024C = equal(r0201, body.constant(int(2047)));
            ir_if *f024B = new(mem_ctx) ir_if(operand(r024C).val);
            exec_list *const f024B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f024B->then_instructions;

               ir_variable *const r024D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r024D);
               ir_expression *const r024E = lshift(r01FA, body.constant(int(31)));
               body.emit(assign(r024D, add(r024E, body.constant(2146435072u)), 0x02));

               body.emit(assign(r024D, body.constant(0u), 0x01));

               ir_variable *const r024F = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r024F, swizzle_x(r01ED), 0x01));

               ir_variable *const r0250 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0250, swizzle_x(r01EE), 0x01));

               body.emit(assign(r024F, bit_or(swizzle_y(r01ED), body.constant(524288u)), 0x02));

               body.emit(assign(r0250, bit_or(swizzle_y(r01EE), body.constant(524288u)), 0x02));

               ir_expression *const r0251 = bit_or(r01F5, r01F6);
               ir_expression *const r0252 = nequal(r0251, body.constant(0u));
               ir_swizzle *const r0253 = swizzle(r0252, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0254 = lshift(swizzle_y(r01ED), body.constant(int(1)));
               ir_expression *const r0255 = gequal(r0254, body.constant(4292870144u));
               ir_expression *const r0256 = nequal(swizzle_x(r01ED), body.constant(0u));
               ir_expression *const r0257 = bit_and(swizzle_y(r01ED), body.constant(1048575u));
               ir_expression *const r0258 = nequal(r0257, body.constant(0u));
               ir_expression *const r0259 = logic_or(r0256, r0258);
               ir_expression *const r025A = logic_and(r0255, r0259);
               ir_swizzle *const r025B = swizzle(r025A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r025C = lshift(swizzle_y(r01EE), body.constant(int(1)));
               ir_expression *const r025D = gequal(r025C, body.constant(4292870144u));
               ir_expression *const r025E = nequal(swizzle_x(r01EE), body.constant(0u));
               ir_expression *const r025F = bit_and(swizzle_y(r01EE), body.constant(1048575u));
               ir_expression *const r0260 = nequal(r025F, body.constant(0u));
               ir_expression *const r0261 = logic_or(r025E, r0260);
               ir_expression *const r0262 = logic_and(r025D, r0261);
               ir_swizzle *const r0263 = swizzle(r0262, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0264 = expr(ir_triop_csel, r0263, r0250, r024F);
               ir_expression *const r0265 = expr(ir_triop_csel, r025B, r0264, r0250);
               body.emit(assign(r01F0, expr(ir_triop_csel, r0253, r0265, r024D), 0x03));

               body.emit(assign(r01EF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f024B->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0267 = equal(r01FE, body.constant(int(0)));
               ir_if *f0266 = new(mem_ctx) ir_if(operand(r0267).val);
               exec_list *const f0266_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0266->then_instructions;

                  body.emit(assign(r01F1, add(r01F1, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0266->else_instructions;

                  body.emit(assign(r01F7, bit_or(r01FC, body.constant(1048576u)), 0x01));


               body.instructions = f0266_parent_instructions;
               body.emit(f0266);

               /* END IF */

               ir_variable *const r0268 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0268, body.constant(0u), 0x01));

               ir_variable *const r0269 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0269, neg(r01F1), 0x01));

               ir_variable *const r026A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r026A);
               ir_variable *const r026B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r026B);
               ir_variable *const r026C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r026C);
               ir_variable *const r026D = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r026E = neg(r0269);
               body.emit(assign(r026D, bit_and(r026E, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0270 = less(r0269, body.constant(int(32)));
               ir_if *f026F = new(mem_ctx) ir_if(operand(r0270).val);
               exec_list *const f026F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f026F->then_instructions;

                  body.emit(assign(r026A, lshift(swizzle_x(r01ED), r026D), 0x01));

                  ir_expression *const r0271 = lshift(r01F7, r026D);
                  ir_expression *const r0272 = rshift(swizzle_x(r01ED), r0269);
                  body.emit(assign(r026B, bit_or(r0271, r0272), 0x01));

                  body.emit(assign(r026C, rshift(r01F7, r0269), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f026F->else_instructions;

                  body.emit(assign(r0268, bit_or(body.constant(0u), swizzle_x(r01ED)), 0x01));

                  ir_expression *const r0273 = less(r0269, body.constant(int(64)));
                  ir_expression *const r0274 = lshift(r01F7, r026D);
                  ir_expression *const r0275 = equal(r0269, body.constant(int(64)));
                  ir_expression *const r0276 = nequal(r01F7, body.constant(0u));
                  ir_expression *const r0277 = expr(ir_unop_b2i, r0276);
                  ir_expression *const r0278 = expr(ir_unop_i2u, r0277);
                  ir_expression *const r0279 = expr(ir_triop_csel, r0275, r01F7, r0278);
                  body.emit(assign(r026A, expr(ir_triop_csel, r0273, r0274, r0279), 0x01));

                  ir_expression *const r027A = less(r0269, body.constant(int(64)));
                  ir_expression *const r027B = bit_and(r0269, body.constant(int(31)));
                  ir_expression *const r027C = rshift(r01F7, r027B);
                  body.emit(assign(r026B, expr(ir_triop_csel, r027A, r027C, body.constant(0u)), 0x01));

                  body.emit(assign(r026C, body.constant(0u), 0x01));


               body.instructions = f026F_parent_instructions;
               body.emit(f026F);

               /* END IF */

               ir_expression *const r027D = nequal(r0268, body.constant(0u));
               ir_expression *const r027E = expr(ir_unop_b2i, r027D);
               ir_expression *const r027F = expr(ir_unop_i2u, r027E);
               body.emit(assign(r026A, bit_or(r026A, r027F), 0x01));

               ir_variable *const r0280 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0281 = equal(r0269, body.constant(int(0)));
               ir_expression *const r0282 = equal(r0269, body.constant(int(32)));
               ir_expression *const r0283 = expr(ir_triop_csel, r0282, body.constant(0u), r026C);
               body.emit(assign(r0280, expr(ir_triop_csel, r0281, r01F7, r0283), 0x01));

               body.emit(assign(r026C, r0280, 0x01));

               ir_variable *const r0284 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0285 = equal(r0269, body.constant(int(0)));
               ir_expression *const r0286 = equal(r0269, body.constant(int(32)));
               ir_expression *const r0287 = expr(ir_triop_csel, r0286, r01F7, r026B);
               body.emit(assign(r0284, expr(ir_triop_csel, r0285, swizzle_x(r01ED), r0287), 0x01));

               body.emit(assign(r026B, r0284, 0x01));

               ir_variable *const r0288 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0289 = equal(r0269, body.constant(int(0)));
               ir_expression *const r028A = equal(r0269, body.constant(int(32)));
               ir_expression *const r028B = expr(ir_triop_csel, r028A, swizzle_x(r01ED), r026A);
               body.emit(assign(r0288, expr(ir_triop_csel, r0289, r0268, r028B), 0x01));

               body.emit(assign(r026A, r0288, 0x01));

               body.emit(assign(r01F7, r0280, 0x01));

               body.emit(assign(r01F8, r0284, 0x01));

               body.emit(assign(r0208, r0288, 0x01));

               body.emit(assign(r0207, r0201, 0x01));


            body.instructions = f024B_parent_instructions;
            body.emit(f024B);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0249->else_instructions;

            /* IF CONDITION */
            ir_expression *const r028D = equal(r01FE, body.constant(int(2047)));
            ir_if *f028C = new(mem_ctx) ir_if(operand(r028D).val);
            exec_list *const f028C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f028C->then_instructions;

               ir_variable *const r028E = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r028E, swizzle_x(r01ED), 0x01));

               ir_variable *const r028F = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r028F, swizzle_x(r01EE), 0x01));

               body.emit(assign(r028E, bit_or(swizzle_y(r01ED), body.constant(524288u)), 0x02));

               body.emit(assign(r028F, bit_or(swizzle_y(r01EE), body.constant(524288u)), 0x02));

               ir_expression *const r0290 = bit_or(r01F7, r01F8);
               ir_expression *const r0291 = bit_or(r01F5, r01F6);
               ir_expression *const r0292 = bit_or(r0290, r0291);
               ir_expression *const r0293 = nequal(r0292, body.constant(0u));
               ir_swizzle *const r0294 = swizzle(r0293, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0295 = lshift(swizzle_y(r01ED), body.constant(int(1)));
               ir_expression *const r0296 = gequal(r0295, body.constant(4292870144u));
               ir_expression *const r0297 = nequal(swizzle_x(r01ED), body.constant(0u));
               ir_expression *const r0298 = bit_and(swizzle_y(r01ED), body.constant(1048575u));
               ir_expression *const r0299 = nequal(r0298, body.constant(0u));
               ir_expression *const r029A = logic_or(r0297, r0299);
               ir_expression *const r029B = logic_and(r0296, r029A);
               ir_swizzle *const r029C = swizzle(r029B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r029D = lshift(swizzle_y(r01EE), body.constant(int(1)));
               ir_expression *const r029E = gequal(r029D, body.constant(4292870144u));
               ir_expression *const r029F = nequal(swizzle_x(r01EE), body.constant(0u));
               ir_expression *const r02A0 = bit_and(swizzle_y(r01EE), body.constant(1048575u));
               ir_expression *const r02A1 = nequal(r02A0, body.constant(0u));
               ir_expression *const r02A2 = logic_or(r029F, r02A1);
               ir_expression *const r02A3 = logic_and(r029E, r02A2);
               ir_swizzle *const r02A4 = swizzle(r02A3, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r02A5 = expr(ir_triop_csel, r02A4, r028F, r028E);
               ir_expression *const r02A6 = expr(ir_triop_csel, r029C, r02A5, r028F);
               body.emit(assign(r01F0, expr(ir_triop_csel, r0294, r02A6, r01ED), 0x03));

               body.emit(assign(r01EF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f028C->else_instructions;

               ir_variable *const r02A7 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r02A8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r02A8, add(r01F8, r01F6), 0x01));

               ir_expression *const r02A9 = add(r01F7, r01F5);
               ir_expression *const r02AA = less(r02A8, r01F8);
               ir_expression *const r02AB = expr(ir_unop_b2i, r02AA);
               ir_expression *const r02AC = expr(ir_unop_i2u, r02AB);
               body.emit(assign(r02A7, add(r02A9, r02AC), 0x01));

               body.emit(assign(r01F2, r02A7, 0x01));

               /* IF CONDITION */
               ir_expression *const r02AE = equal(r01FE, body.constant(int(0)));
               ir_if *f02AD = new(mem_ctx) ir_if(operand(r02AE).val);
               exec_list *const f02AD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02AD->then_instructions;

                  ir_variable *const r02AF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02AF);
                  ir_expression *const r02B0 = lshift(r01FA, body.constant(int(31)));
                  body.emit(assign(r02AF, add(r02B0, r02A7), 0x02));

                  body.emit(assign(r02AF, r02A8, 0x01));

                  body.emit(assign(r01F0, r02AF, 0x03));

                  body.emit(assign(r01EF, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02AD->else_instructions;

                  body.emit(assign(r01F2, bit_or(r02A7, body.constant(2097152u)), 0x01));

                  body.emit(assign(r0207, r01FE, 0x01));

                  ir_variable *const r02B1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r02B1);
                  body.emit(assign(r02B1, lshift(r02A8, body.constant(int(31))), 0x01));

                  body.emit(assign(r02B1, bit_or(r02B1, body.constant(0u)), 0x01));

                  ir_variable *const r02B2 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  body.emit(assign(r02B2, rshift(r01F2, body.constant(int(1))), 0x01));

                  ir_variable *const r02B3 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r02B4 = lshift(r01F2, body.constant(int(31)));
                  ir_expression *const r02B5 = rshift(r02A8, body.constant(int(1)));
                  body.emit(assign(r02B3, bit_or(r02B4, r02B5), 0x01));

                  ir_variable *const r02B6 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  body.emit(assign(r02B6, r02B1, 0x01));

                  body.emit(assign(r01F2, r02B2, 0x01));

                  body.emit(assign(r0208, r02B6, 0x01));

                  ir_variable *const r02B7 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r02B7, r01FE, 0x01));

                  ir_variable *const r02B8 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r02B8, r02B2, 0x01));

                  ir_variable *const r02B9 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r02B9, r02B3, 0x01));

                  ir_variable *const r02BA = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r02BA, r02B6, 0x01));

                  ir_variable *const r02BB = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r02BB, body.constant(true), 0x01));

                  ir_variable *const r02BC = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r02BD = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r02BD);
                  ir_expression *const r02BE = expr(ir_unop_u2i, r02B6);
                  body.emit(assign(r02BD, less(r02BE, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r02C0 = gequal(r01FE, body.constant(int(2045)));
                  ir_if *f02BF = new(mem_ctx) ir_if(operand(r02C0).val);
                  exec_list *const f02BF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02BF->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r02C2 = less(body.constant(int(2045)), r01FE);
                     ir_expression *const r02C3 = equal(r01FE, body.constant(int(2045)));
                     ir_expression *const r02C4 = equal(body.constant(2097151u), r02B2);
                     ir_expression *const r02C5 = equal(body.constant(4294967295u), r02B3);
                     ir_expression *const r02C6 = logic_and(r02C4, r02C5);
                     ir_expression *const r02C7 = logic_and(r02C3, r02C6);
                     ir_expression *const r02C8 = logic_and(r02C7, r02BD);
                     ir_expression *const r02C9 = logic_or(r02C2, r02C8);
                     ir_if *f02C1 = new(mem_ctx) ir_if(operand(r02C9).val);
                     exec_list *const f02C1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02C1->then_instructions;

                        ir_variable *const r02CA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r02CA);
                        ir_expression *const r02CB = lshift(r01FA, body.constant(int(31)));
                        body.emit(assign(r02CA, add(r02CB, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r02CA, body.constant(0u), 0x01));

                        body.emit(assign(r02BC, r02CA, 0x03));

                        body.emit(assign(r02BB, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02C1->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02CD = less(r01FE, body.constant(int(0)));
                        ir_if *f02CC = new(mem_ctx) ir_if(operand(r02CD).val);
                        exec_list *const f02CC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02CC->then_instructions;

                           ir_variable *const r02CE = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r02CE, r02B6, 0x01));

                           ir_variable *const r02CF = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r02CF, neg(r01FE), 0x01));

                           ir_variable *const r02D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r02D0);
                           ir_variable *const r02D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r02D1);
                           ir_variable *const r02D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r02D2);
                           ir_variable *const r02D3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02D4 = neg(r02CF);
                           body.emit(assign(r02D3, bit_and(r02D4, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02D6 = less(r02CF, body.constant(int(32)));
                           ir_if *f02D5 = new(mem_ctx) ir_if(operand(r02D6).val);
                           exec_list *const f02D5_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02D5->then_instructions;

                              body.emit(assign(r02D0, lshift(r02B3, r02D3), 0x01));

                              ir_expression *const r02D7 = lshift(r02B2, r02D3);
                              ir_expression *const r02D8 = rshift(r02B3, r02CF);
                              body.emit(assign(r02D1, bit_or(r02D7, r02D8), 0x01));

                              body.emit(assign(r02D2, rshift(r02B2, r02CF), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02D5->else_instructions;

                              body.emit(assign(r02CE, bit_or(r02B6, r02B3), 0x01));

                              ir_expression *const r02D9 = less(r02CF, body.constant(int(64)));
                              ir_expression *const r02DA = lshift(r02B2, r02D3);
                              ir_expression *const r02DB = equal(r02CF, body.constant(int(64)));
                              ir_expression *const r02DC = nequal(r02B2, body.constant(0u));
                              ir_expression *const r02DD = expr(ir_unop_b2i, r02DC);
                              ir_expression *const r02DE = expr(ir_unop_i2u, r02DD);
                              ir_expression *const r02DF = expr(ir_triop_csel, r02DB, r02B2, r02DE);
                              body.emit(assign(r02D0, expr(ir_triop_csel, r02D9, r02DA, r02DF), 0x01));

                              ir_expression *const r02E0 = less(r02CF, body.constant(int(64)));
                              ir_expression *const r02E1 = bit_and(r02CF, body.constant(int(31)));
                              ir_expression *const r02E2 = rshift(r02B2, r02E1);
                              body.emit(assign(r02D1, expr(ir_triop_csel, r02E0, r02E2, body.constant(0u)), 0x01));

                              body.emit(assign(r02D2, body.constant(0u), 0x01));


                           body.instructions = f02D5_parent_instructions;
                           body.emit(f02D5);

                           /* END IF */

                           ir_expression *const r02E3 = nequal(r02CE, body.constant(0u));
                           ir_expression *const r02E4 = expr(ir_unop_b2i, r02E3);
                           ir_expression *const r02E5 = expr(ir_unop_i2u, r02E4);
                           body.emit(assign(r02D0, bit_or(r02D0, r02E5), 0x01));

                           ir_variable *const r02E6 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r02E7 = equal(r02CF, body.constant(int(0)));
                           ir_expression *const r02E8 = equal(r02CF, body.constant(int(32)));
                           ir_expression *const r02E9 = expr(ir_triop_csel, r02E8, body.constant(0u), r02D2);
                           body.emit(assign(r02E6, expr(ir_triop_csel, r02E7, r02B2, r02E9), 0x01));

                           body.emit(assign(r02D2, r02E6, 0x01));

                           ir_variable *const r02EA = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r02EB = equal(r02CF, body.constant(int(0)));
                           ir_expression *const r02EC = equal(r02CF, body.constant(int(32)));
                           ir_expression *const r02ED = expr(ir_triop_csel, r02EC, r02B2, r02D1);
                           body.emit(assign(r02EA, expr(ir_triop_csel, r02EB, r02B3, r02ED), 0x01));

                           body.emit(assign(r02D1, r02EA, 0x01));

                           ir_variable *const r02EE = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r02EF = equal(r02CF, body.constant(int(0)));
                           ir_expression *const r02F0 = equal(r02CF, body.constant(int(32)));
                           ir_expression *const r02F1 = expr(ir_triop_csel, r02F0, r02B3, r02D0);
                           body.emit(assign(r02EE, expr(ir_triop_csel, r02EF, r02CE, r02F1), 0x01));

                           body.emit(assign(r02D0, r02EE, 0x01));

                           body.emit(assign(r02B8, r02E6, 0x01));

                           body.emit(assign(r02B9, r02EA, 0x01));

                           body.emit(assign(r02BA, r02EE, 0x01));

                           body.emit(assign(r02B7, body.constant(int(0)), 0x01));

                           body.emit(assign(r02BD, less(r02EE, body.constant(0u)), 0x01));


                        body.instructions = f02CC_parent_instructions;
                        body.emit(f02CC);

                        /* END IF */


                     body.instructions = f02C1_parent_instructions;
                     body.emit(f02C1);

                     /* END IF */


                  body.instructions = f02BF_parent_instructions;
                  body.emit(f02BF);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02F2 = new(mem_ctx) ir_if(operand(r02BB).val);
                  exec_list *const f02F2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02F2->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02F3 = new(mem_ctx) ir_if(operand(r02BD).val);
                     exec_list *const f02F3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02F3->then_instructions;

                        ir_variable *const r02F4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02F4, add(r02B9, body.constant(1u)), 0x01));

                        ir_expression *const r02F5 = less(r02F4, r02B9);
                        ir_expression *const r02F6 = expr(ir_unop_b2i, r02F5);
                        ir_expression *const r02F7 = expr(ir_unop_i2u, r02F6);
                        body.emit(assign(r02B8, add(r02B8, r02F7), 0x01));

                        ir_expression *const r02F8 = equal(r02BA, body.constant(0u));
                        ir_expression *const r02F9 = expr(ir_unop_b2i, r02F8);
                        ir_expression *const r02FA = expr(ir_unop_i2u, r02F9);
                        ir_expression *const r02FB = add(r02BA, r02FA);
                        ir_expression *const r02FC = bit_and(r02FB, body.constant(1u));
                        ir_expression *const r02FD = expr(ir_unop_bit_not, r02FC);
                        body.emit(assign(r02B9, bit_and(r02F4, r02FD), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02F3->else_instructions;

                        ir_expression *const r02FE = bit_or(r02B8, r02B9);
                        ir_expression *const r02FF = equal(r02FE, body.constant(0u));
                        body.emit(assign(r02B7, expr(ir_triop_csel, r02FF, body.constant(int(0)), r02B7), 0x01));


                     body.instructions = f02F3_parent_instructions;
                     body.emit(f02F3);

                     /* END IF */

                     ir_variable *const r0300 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0300);
                     ir_expression *const r0301 = lshift(r01FA, body.constant(int(31)));
                     ir_expression *const r0302 = expr(ir_unop_i2u, r02B7);
                     ir_expression *const r0303 = lshift(r0302, body.constant(int(20)));
                     ir_expression *const r0304 = add(r0301, r0303);
                     body.emit(assign(r0300, add(r0304, r02B8), 0x02));

                     body.emit(assign(r0300, r02B9, 0x01));

                     body.emit(assign(r02BC, r0300, 0x03));

                     body.emit(assign(r02BB, body.constant(false), 0x01));


                  body.instructions = f02F2_parent_instructions;
                  body.emit(f02F2);

                  /* END IF */

                  body.emit(assign(r01F0, r02BC, 0x03));

                  body.emit(assign(r01EF, body.constant(false), 0x01));


               body.instructions = f02AD_parent_instructions;
               body.emit(f02AD);

               /* END IF */


            body.instructions = f028C_parent_instructions;
            body.emit(f028C);

            /* END IF */


         body.instructions = f0249_parent_instructions;
         body.emit(f0249);

         /* END IF */


      body.instructions = f0209_parent_instructions;
      body.emit(f0209);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0305 = new(mem_ctx) ir_if(operand(r01EF).val);
      exec_list *const f0305_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0305->then_instructions;

         body.emit(assign(r01F7, bit_or(r01F7, body.constant(1048576u)), 0x01));

         ir_variable *const r0306 = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r0307 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0307, add(r01F8, r01F6), 0x01));

         ir_expression *const r0308 = add(r01F7, r01F5);
         ir_expression *const r0309 = less(r0307, r01F8);
         ir_expression *const r030A = expr(ir_unop_b2i, r0309);
         ir_expression *const r030B = expr(ir_unop_i2u, r030A);
         body.emit(assign(r0306, add(r0308, r030B), 0x01));

         body.emit(assign(r01F2, r0306, 0x01));

         body.emit(assign(r0207, add(r0207, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r030D = less(r0306, body.constant(2097152u));
         ir_if *f030C = new(mem_ctx) ir_if(operand(r030D).val);
         exec_list *const f030C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f030C->then_instructions;

            ir_variable *const r030E = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r030E, r0207, 0x01));

            ir_variable *const r030F = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r030F, r0306, 0x01));

            ir_variable *const r0310 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0310, r0307, 0x01));

            ir_variable *const r0311 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0311, r0208, 0x01));

            ir_variable *const r0312 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0312, body.constant(true), 0x01));

            ir_variable *const r0313 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0314 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0314);
            ir_expression *const r0315 = expr(ir_unop_u2i, r0208);
            body.emit(assign(r0314, less(r0315, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0317 = gequal(r0207, body.constant(int(2045)));
            ir_if *f0316 = new(mem_ctx) ir_if(operand(r0317).val);
            exec_list *const f0316_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0316->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0319 = less(body.constant(int(2045)), r0207);
               ir_expression *const r031A = equal(r0207, body.constant(int(2045)));
               ir_expression *const r031B = equal(body.constant(2097151u), r0306);
               ir_expression *const r031C = equal(body.constant(4294967295u), r0307);
               ir_expression *const r031D = logic_and(r031B, r031C);
               ir_expression *const r031E = logic_and(r031A, r031D);
               ir_expression *const r031F = logic_and(r031E, r0314);
               ir_expression *const r0320 = logic_or(r0319, r031F);
               ir_if *f0318 = new(mem_ctx) ir_if(operand(r0320).val);
               exec_list *const f0318_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0318->then_instructions;

                  ir_variable *const r0321 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0321);
                  ir_expression *const r0322 = lshift(r01FA, body.constant(int(31)));
                  body.emit(assign(r0321, add(r0322, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0321, body.constant(0u), 0x01));

                  body.emit(assign(r0313, r0321, 0x03));

                  body.emit(assign(r0312, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0318->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0324 = less(r0207, body.constant(int(0)));
                  ir_if *f0323 = new(mem_ctx) ir_if(operand(r0324).val);
                  exec_list *const f0323_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0323->then_instructions;

                     ir_variable *const r0325 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0325, r0208, 0x01));

                     ir_variable *const r0326 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0326, neg(r0207), 0x01));

                     ir_variable *const r0327 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0327);
                     ir_variable *const r0328 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0328);
                     ir_variable *const r0329 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0329);
                     ir_variable *const r032A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r032B = neg(r0326);
                     body.emit(assign(r032A, bit_and(r032B, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r032D = less(r0326, body.constant(int(32)));
                     ir_if *f032C = new(mem_ctx) ir_if(operand(r032D).val);
                     exec_list *const f032C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f032C->then_instructions;

                        body.emit(assign(r0327, lshift(r0307, r032A), 0x01));

                        ir_expression *const r032E = lshift(r0306, r032A);
                        ir_expression *const r032F = rshift(r0307, r0326);
                        body.emit(assign(r0328, bit_or(r032E, r032F), 0x01));

                        body.emit(assign(r0329, rshift(r0306, r0326), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f032C->else_instructions;

                        body.emit(assign(r0325, bit_or(r0208, r0307), 0x01));

                        ir_expression *const r0330 = less(r0326, body.constant(int(64)));
                        ir_expression *const r0331 = lshift(r0306, r032A);
                        ir_expression *const r0332 = equal(r0326, body.constant(int(64)));
                        ir_expression *const r0333 = nequal(r0306, body.constant(0u));
                        ir_expression *const r0334 = expr(ir_unop_b2i, r0333);
                        ir_expression *const r0335 = expr(ir_unop_i2u, r0334);
                        ir_expression *const r0336 = expr(ir_triop_csel, r0332, r0306, r0335);
                        body.emit(assign(r0327, expr(ir_triop_csel, r0330, r0331, r0336), 0x01));

                        ir_expression *const r0337 = less(r0326, body.constant(int(64)));
                        ir_expression *const r0338 = bit_and(r0326, body.constant(int(31)));
                        ir_expression *const r0339 = rshift(r0306, r0338);
                        body.emit(assign(r0328, expr(ir_triop_csel, r0337, r0339, body.constant(0u)), 0x01));

                        body.emit(assign(r0329, body.constant(0u), 0x01));


                     body.instructions = f032C_parent_instructions;
                     body.emit(f032C);

                     /* END IF */

                     ir_expression *const r033A = nequal(r0325, body.constant(0u));
                     ir_expression *const r033B = expr(ir_unop_b2i, r033A);
                     ir_expression *const r033C = expr(ir_unop_i2u, r033B);
                     body.emit(assign(r0327, bit_or(r0327, r033C), 0x01));

                     ir_variable *const r033D = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r033E = equal(r0326, body.constant(int(0)));
                     ir_expression *const r033F = equal(r0326, body.constant(int(32)));
                     ir_expression *const r0340 = expr(ir_triop_csel, r033F, body.constant(0u), r0329);
                     body.emit(assign(r033D, expr(ir_triop_csel, r033E, r0306, r0340), 0x01));

                     body.emit(assign(r0329, r033D, 0x01));

                     ir_variable *const r0341 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0342 = equal(r0326, body.constant(int(0)));
                     ir_expression *const r0343 = equal(r0326, body.constant(int(32)));
                     ir_expression *const r0344 = expr(ir_triop_csel, r0343, r0306, r0328);
                     body.emit(assign(r0341, expr(ir_triop_csel, r0342, r0307, r0344), 0x01));

                     body.emit(assign(r0328, r0341, 0x01));

                     ir_variable *const r0345 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0346 = equal(r0326, body.constant(int(0)));
                     ir_expression *const r0347 = equal(r0326, body.constant(int(32)));
                     ir_expression *const r0348 = expr(ir_triop_csel, r0347, r0307, r0327);
                     body.emit(assign(r0345, expr(ir_triop_csel, r0346, r0325, r0348), 0x01));

                     body.emit(assign(r0327, r0345, 0x01));

                     body.emit(assign(r030F, r033D, 0x01));

                     body.emit(assign(r0310, r0341, 0x01));

                     body.emit(assign(r0311, r0345, 0x01));

                     body.emit(assign(r030E, body.constant(int(0)), 0x01));

                     body.emit(assign(r0314, less(r0345, body.constant(0u)), 0x01));


                  body.instructions = f0323_parent_instructions;
                  body.emit(f0323);

                  /* END IF */


               body.instructions = f0318_parent_instructions;
               body.emit(f0318);

               /* END IF */


            body.instructions = f0316_parent_instructions;
            body.emit(f0316);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0349 = new(mem_ctx) ir_if(operand(r0312).val);
            exec_list *const f0349_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0349->then_instructions;

               /* IF CONDITION */
               ir_if *f034A = new(mem_ctx) ir_if(operand(r0314).val);
               exec_list *const f034A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f034A->then_instructions;

                  ir_variable *const r034B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r034B, add(r0310, body.constant(1u)), 0x01));

                  ir_expression *const r034C = less(r034B, r0310);
                  ir_expression *const r034D = expr(ir_unop_b2i, r034C);
                  ir_expression *const r034E = expr(ir_unop_i2u, r034D);
                  body.emit(assign(r030F, add(r030F, r034E), 0x01));

                  ir_expression *const r034F = equal(r0311, body.constant(0u));
                  ir_expression *const r0350 = expr(ir_unop_b2i, r034F);
                  ir_expression *const r0351 = expr(ir_unop_i2u, r0350);
                  ir_expression *const r0352 = add(r0311, r0351);
                  ir_expression *const r0353 = bit_and(r0352, body.constant(1u));
                  ir_expression *const r0354 = expr(ir_unop_bit_not, r0353);
                  body.emit(assign(r0310, bit_and(r034B, r0354), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f034A->else_instructions;

                  ir_expression *const r0355 = bit_or(r030F, r0310);
                  ir_expression *const r0356 = equal(r0355, body.constant(0u));
                  body.emit(assign(r030E, expr(ir_triop_csel, r0356, body.constant(int(0)), r030E), 0x01));


               body.instructions = f034A_parent_instructions;
               body.emit(f034A);

               /* END IF */

               ir_variable *const r0357 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0357);
               ir_expression *const r0358 = lshift(r01FA, body.constant(int(31)));
               ir_expression *const r0359 = expr(ir_unop_i2u, r030E);
               ir_expression *const r035A = lshift(r0359, body.constant(int(20)));
               ir_expression *const r035B = add(r0358, r035A);
               body.emit(assign(r0357, add(r035B, r030F), 0x02));

               body.emit(assign(r0357, r0310, 0x01));

               body.emit(assign(r0313, r0357, 0x03));

               body.emit(assign(r0312, body.constant(false), 0x01));


            body.instructions = f0349_parent_instructions;
            body.emit(f0349);

            /* END IF */

            body.emit(assign(r01F0, r0313, 0x03));

            body.emit(assign(r01EF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f030C->else_instructions;

            body.emit(assign(r0207, add(r0207, body.constant(int(1))), 0x01));

            ir_variable *const r035C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r035C);
            body.emit(assign(r035C, lshift(r0307, body.constant(int(31))), 0x01));

            ir_expression *const r035D = nequal(r0208, body.constant(0u));
            ir_expression *const r035E = expr(ir_unop_b2i, r035D);
            ir_expression *const r035F = expr(ir_unop_i2u, r035E);
            body.emit(assign(r035C, bit_or(r035C, r035F), 0x01));

            ir_variable *const r0360 = body.make_temp(glsl_type::uint_type, "mix_retval");
            body.emit(assign(r0360, rshift(r0306, body.constant(int(1))), 0x01));

            ir_variable *const r0361 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0362 = lshift(r0306, body.constant(int(31)));
            ir_expression *const r0363 = rshift(r0307, body.constant(int(1)));
            body.emit(assign(r0361, bit_or(r0362, r0363), 0x01));

            ir_variable *const r0364 = body.make_temp(glsl_type::uint_type, "mix_retval");
            body.emit(assign(r0364, r035C, 0x01));

            body.emit(assign(r01F2, r0360, 0x01));

            body.emit(assign(r0208, r0364, 0x01));

            ir_variable *const r0365 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0365, r0207, 0x01));

            ir_variable *const r0366 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0366, r0360, 0x01));

            ir_variable *const r0367 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0367, r0361, 0x01));

            ir_variable *const r0368 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0368, r0364, 0x01));

            ir_variable *const r0369 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0369, body.constant(true), 0x01));

            ir_variable *const r036A = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r036B = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r036B);
            ir_expression *const r036C = expr(ir_unop_u2i, r0364);
            body.emit(assign(r036B, less(r036C, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r036E = gequal(r0207, body.constant(int(2045)));
            ir_if *f036D = new(mem_ctx) ir_if(operand(r036E).val);
            exec_list *const f036D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f036D->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0370 = less(body.constant(int(2045)), r0207);
               ir_expression *const r0371 = equal(r0207, body.constant(int(2045)));
               ir_expression *const r0372 = equal(body.constant(2097151u), r0360);
               ir_expression *const r0373 = equal(body.constant(4294967295u), r0361);
               ir_expression *const r0374 = logic_and(r0372, r0373);
               ir_expression *const r0375 = logic_and(r0371, r0374);
               ir_expression *const r0376 = logic_and(r0375, r036B);
               ir_expression *const r0377 = logic_or(r0370, r0376);
               ir_if *f036F = new(mem_ctx) ir_if(operand(r0377).val);
               exec_list *const f036F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f036F->then_instructions;

                  ir_variable *const r0378 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0378);
                  ir_expression *const r0379 = lshift(r01FA, body.constant(int(31)));
                  body.emit(assign(r0378, add(r0379, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0378, body.constant(0u), 0x01));

                  body.emit(assign(r036A, r0378, 0x03));

                  body.emit(assign(r0369, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f036F->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r037B = less(r0207, body.constant(int(0)));
                  ir_if *f037A = new(mem_ctx) ir_if(operand(r037B).val);
                  exec_list *const f037A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f037A->then_instructions;

                     ir_variable *const r037C = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r037C, r0364, 0x01));

                     ir_variable *const r037D = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r037D, neg(r0207), 0x01));

                     ir_variable *const r037E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r037E);
                     ir_variable *const r037F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r037F);
                     ir_variable *const r0380 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0380);
                     ir_variable *const r0381 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0382 = neg(r037D);
                     body.emit(assign(r0381, bit_and(r0382, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0384 = less(r037D, body.constant(int(32)));
                     ir_if *f0383 = new(mem_ctx) ir_if(operand(r0384).val);
                     exec_list *const f0383_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0383->then_instructions;

                        body.emit(assign(r037E, lshift(r0361, r0381), 0x01));

                        ir_expression *const r0385 = lshift(r0360, r0381);
                        ir_expression *const r0386 = rshift(r0361, r037D);
                        body.emit(assign(r037F, bit_or(r0385, r0386), 0x01));

                        body.emit(assign(r0380, rshift(r0360, r037D), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0383->else_instructions;

                        body.emit(assign(r037C, bit_or(r0364, r0361), 0x01));

                        ir_expression *const r0387 = less(r037D, body.constant(int(64)));
                        ir_expression *const r0388 = lshift(r0360, r0381);
                        ir_expression *const r0389 = equal(r037D, body.constant(int(64)));
                        ir_expression *const r038A = nequal(r0360, body.constant(0u));
                        ir_expression *const r038B = expr(ir_unop_b2i, r038A);
                        ir_expression *const r038C = expr(ir_unop_i2u, r038B);
                        ir_expression *const r038D = expr(ir_triop_csel, r0389, r0360, r038C);
                        body.emit(assign(r037E, expr(ir_triop_csel, r0387, r0388, r038D), 0x01));

                        ir_expression *const r038E = less(r037D, body.constant(int(64)));
                        ir_expression *const r038F = bit_and(r037D, body.constant(int(31)));
                        ir_expression *const r0390 = rshift(r0360, r038F);
                        body.emit(assign(r037F, expr(ir_triop_csel, r038E, r0390, body.constant(0u)), 0x01));

                        body.emit(assign(r0380, body.constant(0u), 0x01));


                     body.instructions = f0383_parent_instructions;
                     body.emit(f0383);

                     /* END IF */

                     ir_expression *const r0391 = nequal(r037C, body.constant(0u));
                     ir_expression *const r0392 = expr(ir_unop_b2i, r0391);
                     ir_expression *const r0393 = expr(ir_unop_i2u, r0392);
                     body.emit(assign(r037E, bit_or(r037E, r0393), 0x01));

                     ir_variable *const r0394 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0395 = equal(r037D, body.constant(int(0)));
                     ir_expression *const r0396 = equal(r037D, body.constant(int(32)));
                     ir_expression *const r0397 = expr(ir_triop_csel, r0396, body.constant(0u), r0380);
                     body.emit(assign(r0394, expr(ir_triop_csel, r0395, r0360, r0397), 0x01));

                     body.emit(assign(r0380, r0394, 0x01));

                     ir_variable *const r0398 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0399 = equal(r037D, body.constant(int(0)));
                     ir_expression *const r039A = equal(r037D, body.constant(int(32)));
                     ir_expression *const r039B = expr(ir_triop_csel, r039A, r0360, r037F);
                     body.emit(assign(r0398, expr(ir_triop_csel, r0399, r0361, r039B), 0x01));

                     body.emit(assign(r037F, r0398, 0x01));

                     ir_variable *const r039C = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r039D = equal(r037D, body.constant(int(0)));
                     ir_expression *const r039E = equal(r037D, body.constant(int(32)));
                     ir_expression *const r039F = expr(ir_triop_csel, r039E, r0361, r037E);
                     body.emit(assign(r039C, expr(ir_triop_csel, r039D, r037C, r039F), 0x01));

                     body.emit(assign(r037E, r039C, 0x01));

                     body.emit(assign(r0366, r0394, 0x01));

                     body.emit(assign(r0367, r0398, 0x01));

                     body.emit(assign(r0368, r039C, 0x01));

                     body.emit(assign(r0365, body.constant(int(0)), 0x01));

                     body.emit(assign(r036B, less(r039C, body.constant(0u)), 0x01));


                  body.instructions = f037A_parent_instructions;
                  body.emit(f037A);

                  /* END IF */


               body.instructions = f036F_parent_instructions;
               body.emit(f036F);

               /* END IF */


            body.instructions = f036D_parent_instructions;
            body.emit(f036D);

            /* END IF */

            /* IF CONDITION */
            ir_if *f03A0 = new(mem_ctx) ir_if(operand(r0369).val);
            exec_list *const f03A0_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03A0->then_instructions;

               /* IF CONDITION */
               ir_if *f03A1 = new(mem_ctx) ir_if(operand(r036B).val);
               exec_list *const f03A1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03A1->then_instructions;

                  ir_variable *const r03A2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r03A2, add(r0367, body.constant(1u)), 0x01));

                  ir_expression *const r03A3 = less(r03A2, r0367);
                  ir_expression *const r03A4 = expr(ir_unop_b2i, r03A3);
                  ir_expression *const r03A5 = expr(ir_unop_i2u, r03A4);
                  body.emit(assign(r0366, add(r0366, r03A5), 0x01));

                  ir_expression *const r03A6 = equal(r0368, body.constant(0u));
                  ir_expression *const r03A7 = expr(ir_unop_b2i, r03A6);
                  ir_expression *const r03A8 = expr(ir_unop_i2u, r03A7);
                  ir_expression *const r03A9 = add(r0368, r03A8);
                  ir_expression *const r03AA = bit_and(r03A9, body.constant(1u));
                  ir_expression *const r03AB = expr(ir_unop_bit_not, r03AA);
                  body.emit(assign(r0367, bit_and(r03A2, r03AB), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03A1->else_instructions;

                  ir_expression *const r03AC = bit_or(r0366, r0367);
                  ir_expression *const r03AD = equal(r03AC, body.constant(0u));
                  body.emit(assign(r0365, expr(ir_triop_csel, r03AD, body.constant(int(0)), r0365), 0x01));


               body.instructions = f03A1_parent_instructions;
               body.emit(f03A1);

               /* END IF */

               ir_variable *const r03AE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r03AE);
               ir_expression *const r03AF = lshift(r01FA, body.constant(int(31)));
               ir_expression *const r03B0 = expr(ir_unop_i2u, r0365);
               ir_expression *const r03B1 = lshift(r03B0, body.constant(int(20)));
               ir_expression *const r03B2 = add(r03AF, r03B1);
               body.emit(assign(r03AE, add(r03B2, r0366), 0x02));

               body.emit(assign(r03AE, r0367, 0x01));

               body.emit(assign(r036A, r03AE, 0x03));

               body.emit(assign(r0369, body.constant(false), 0x01));


            body.instructions = f03A0_parent_instructions;
            body.emit(f03A0);

            /* END IF */

            body.emit(assign(r01F0, r036A, 0x03));

            body.emit(assign(r01EF, body.constant(false), 0x01));


         body.instructions = f030C_parent_instructions;
         body.emit(f030C);

         /* END IF */


      body.instructions = f0305_parent_instructions;
      body.emit(f0305);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0205->else_instructions;

      ir_variable *const r03B3 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r03B3);
      ir_variable *const r03B4 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r03B5 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r03B5, lshift(r01F8, body.constant(int(10))), 0x01));

      ir_expression *const r03B6 = lshift(r01F7, body.constant(int(10)));
      ir_expression *const r03B7 = rshift(r01F8, body.constant(int(22)));
      body.emit(assign(r03B4, bit_or(r03B6, r03B7), 0x01));

      body.emit(assign(r01F7, r03B4, 0x01));

      body.emit(assign(r01F8, r03B5, 0x01));

      ir_variable *const r03B8 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r03B9 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r03B9, lshift(r01F6, body.constant(int(10))), 0x01));

      ir_expression *const r03BA = lshift(r01F5, body.constant(int(10)));
      ir_expression *const r03BB = rshift(r01F6, body.constant(int(22)));
      body.emit(assign(r03B8, bit_or(r03BA, r03BB), 0x01));

      body.emit(assign(r01F5, r03B8, 0x01));

      body.emit(assign(r01F6, r03B9, 0x01));

      /* IF CONDITION */
      ir_expression *const r03BD = less(body.constant(int(0)), r01F1);
      ir_if *f03BC = new(mem_ctx) ir_if(operand(r03BD).val);
      exec_list *const f03BC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f03BC->then_instructions;

         /* IF CONDITION */
         ir_expression *const r03BF = equal(r01FE, body.constant(int(2047)));
         ir_if *f03BE = new(mem_ctx) ir_if(operand(r03BF).val);
         exec_list *const f03BE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f03BE->then_instructions;

            ir_variable *const r03C0 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r03C0, swizzle_x(r01ED), 0x01));

            ir_variable *const r03C1 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r03C1, swizzle_x(r01EE), 0x01));

            body.emit(assign(r03C0, bit_or(swizzle_y(r01ED), body.constant(524288u)), 0x02));

            body.emit(assign(r03C1, bit_or(swizzle_y(r01EE), body.constant(524288u)), 0x02));

            ir_expression *const r03C2 = bit_or(r03B4, r03B5);
            ir_expression *const r03C3 = nequal(r03C2, body.constant(0u));
            ir_swizzle *const r03C4 = swizzle(r03C3, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r03C5 = lshift(swizzle_y(r01ED), body.constant(int(1)));
            ir_expression *const r03C6 = gequal(r03C5, body.constant(4292870144u));
            ir_expression *const r03C7 = nequal(swizzle_x(r01ED), body.constant(0u));
            ir_expression *const r03C8 = bit_and(swizzle_y(r01ED), body.constant(1048575u));
            ir_expression *const r03C9 = nequal(r03C8, body.constant(0u));
            ir_expression *const r03CA = logic_or(r03C7, r03C9);
            ir_expression *const r03CB = logic_and(r03C6, r03CA);
            ir_swizzle *const r03CC = swizzle(r03CB, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r03CD = lshift(swizzle_y(r01EE), body.constant(int(1)));
            ir_expression *const r03CE = gequal(r03CD, body.constant(4292870144u));
            ir_expression *const r03CF = nequal(swizzle_x(r01EE), body.constant(0u));
            ir_expression *const r03D0 = bit_and(swizzle_y(r01EE), body.constant(1048575u));
            ir_expression *const r03D1 = nequal(r03D0, body.constant(0u));
            ir_expression *const r03D2 = logic_or(r03CF, r03D1);
            ir_expression *const r03D3 = logic_and(r03CE, r03D2);
            ir_swizzle *const r03D4 = swizzle(r03D3, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r03D5 = expr(ir_triop_csel, r03D4, r03C1, r03C0);
            ir_expression *const r03D6 = expr(ir_triop_csel, r03CC, r03D5, r03C1);
            body.emit(assign(r01F0, expr(ir_triop_csel, r03C4, r03D6, r01ED), 0x03));

            body.emit(assign(r01EF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f03BE->else_instructions;

            /* IF CONDITION */
            ir_expression *const r03D8 = equal(r0201, body.constant(int(0)));
            ir_if *f03D7 = new(mem_ctx) ir_if(operand(r03D8).val);
            exec_list *const f03D7_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03D7->then_instructions;

               body.emit(assign(r01F1, add(r01F1, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03D7->else_instructions;

               body.emit(assign(r01F5, bit_or(r03B8, body.constant(1073741824u)), 0x01));


            body.instructions = f03D7_parent_instructions;
            body.emit(f03D7);

            /* END IF */

            ir_variable *const r03D9 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r03DA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r03DA);
            ir_variable *const r03DB = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r03DC = neg(r01F1);
            body.emit(assign(r03DB, bit_and(r03DC, body.constant(int(31))), 0x01));

            ir_expression *const r03DD = bit_or(r01F5, r03B9);
            ir_expression *const r03DE = nequal(r03DD, body.constant(0u));
            ir_expression *const r03DF = expr(ir_unop_b2i, r03DE);
            body.emit(assign(r03DA, expr(ir_unop_i2u, r03DF), 0x01));

            ir_variable *const r03E0 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03E1 = equal(r01F1, body.constant(int(0)));
            ir_expression *const r03E2 = less(r01F1, body.constant(int(32)));
            ir_expression *const r03E3 = lshift(r01F5, r03DB);
            ir_expression *const r03E4 = rshift(r03B9, r01F1);
            ir_expression *const r03E5 = bit_or(r03E3, r03E4);
            ir_expression *const r03E6 = lshift(r03B9, r03DB);
            ir_expression *const r03E7 = nequal(r03E6, body.constant(0u));
            ir_expression *const r03E8 = expr(ir_unop_b2i, r03E7);
            ir_expression *const r03E9 = expr(ir_unop_i2u, r03E8);
            ir_expression *const r03EA = bit_or(r03E5, r03E9);
            ir_expression *const r03EB = equal(r01F1, body.constant(int(32)));
            ir_expression *const r03EC = nequal(r03B9, body.constant(0u));
            ir_expression *const r03ED = expr(ir_unop_b2i, r03EC);
            ir_expression *const r03EE = expr(ir_unop_i2u, r03ED);
            ir_expression *const r03EF = bit_or(r01F5, r03EE);
            ir_expression *const r03F0 = less(r01F1, body.constant(int(64)));
            ir_expression *const r03F1 = bit_and(r01F1, body.constant(int(31)));
            ir_expression *const r03F2 = rshift(r01F5, r03F1);
            ir_expression *const r03F3 = lshift(r01F5, r03DB);
            ir_expression *const r03F4 = bit_or(r03F3, r03B9);
            ir_expression *const r03F5 = nequal(r03F4, body.constant(0u));
            ir_expression *const r03F6 = expr(ir_unop_b2i, r03F5);
            ir_expression *const r03F7 = expr(ir_unop_i2u, r03F6);
            ir_expression *const r03F8 = bit_or(r03F2, r03F7);
            ir_expression *const r03F9 = expr(ir_triop_csel, r03F0, r03F8, r03DA);
            ir_expression *const r03FA = expr(ir_triop_csel, r03EB, r03EF, r03F9);
            ir_expression *const r03FB = expr(ir_triop_csel, r03E2, r03EA, r03FA);
            body.emit(assign(r03E0, expr(ir_triop_csel, r03E1, r03B9, r03FB), 0x01));

            body.emit(assign(r03DA, r03E0, 0x01));

            ir_expression *const r03FC = less(r01F1, body.constant(int(32)));
            ir_expression *const r03FD = rshift(r01F5, r01F1);
            ir_expression *const r03FE = equal(r01F1, body.constant(int(0)));
            ir_expression *const r03FF = expr(ir_triop_csel, r03FE, r01F5, body.constant(0u));
            body.emit(assign(r03D9, expr(ir_triop_csel, r03FC, r03FD, r03FF), 0x01));

            body.emit(assign(r01F5, r03D9, 0x01));

            body.emit(assign(r01F6, r03E0, 0x01));

            body.emit(assign(r01F7, bit_or(r03B4, body.constant(1073741824u)), 0x01));

            ir_variable *const r0400 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_expression *const r0401 = sub(r01F7, r03D9);
            ir_expression *const r0402 = less(r03B5, r03E0);
            ir_expression *const r0403 = expr(ir_unop_b2i, r0402);
            ir_expression *const r0404 = expr(ir_unop_i2u, r0403);
            body.emit(assign(r0400, sub(r0401, r0404), 0x01));

            body.emit(assign(r01F2, r0400, 0x01));

            body.emit(assign(r03B3, add(r01FE, body.constant(int(-1))), 0x01));

            ir_variable *const r0405 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0405, add(r03B3, body.constant(int(-10))), 0x01));

            ir_variable *const r0406 = body.make_temp(glsl_type::uint_type, "zFrac0");
            ir_variable *const r0407 = body.make_temp(glsl_type::uint_type, "zFrac1");
            ir_variable *const r0408 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r0408);
            ir_variable *const r0409 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0409);
            ir_expression *const r040A = equal(r0400, body.constant(0u));
            ir_expression *const r040B = add(r0405, body.constant(int(-32)));
            body.emit(assign(r0405, expr(ir_triop_csel, r040A, r040B, r0405), 0x01));

            ir_variable *const r040C = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r040D = equal(r0400, body.constant(0u));
            ir_expression *const r040E = sub(r03B5, r03E0);
            body.emit(assign(r040C, expr(ir_triop_csel, r040D, body.constant(0u), r040E), 0x01));

            body.emit(assign(r0407, r040C, 0x01));

            ir_variable *const r040F = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0410 = equal(r0400, body.constant(0u));
            body.emit(assign(r040F, expr(ir_triop_csel, r0410, r040C, r0400), 0x01));

            body.emit(assign(r0406, r040F, 0x01));

            ir_expression *const r0411 = equal(r040F, body.constant(0u));
            ir_expression *const r0412 = expr(ir_unop_find_msb, r040F);
            ir_expression *const r0413 = sub(body.constant(int(31)), r0412);
            ir_expression *const r0414 = expr(ir_triop_csel, r0411, body.constant(int(32)), r0413);
            body.emit(assign(r0409, add(r0414, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0416 = gequal(r0409, body.constant(int(0)));
            ir_if *f0415 = new(mem_ctx) ir_if(operand(r0416).val);
            exec_list *const f0415_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0415->then_instructions;

               body.emit(assign(r0408, body.constant(0u), 0x01));

               ir_expression *const r0417 = equal(r0409, body.constant(int(0)));
               ir_expression *const r0418 = lshift(r040F, r0409);
               ir_expression *const r0419 = neg(r0409);
               ir_expression *const r041A = bit_and(r0419, body.constant(int(31)));
               ir_expression *const r041B = rshift(r040C, r041A);
               ir_expression *const r041C = bit_or(r0418, r041B);
               body.emit(assign(r0406, expr(ir_triop_csel, r0417, r040F, r041C), 0x01));

               body.emit(assign(r0407, lshift(r040C, r0409), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0415->else_instructions;

               ir_variable *const r041D = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r041D, body.constant(0u), 0x01));

               ir_variable *const r041E = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r041E, neg(r0409), 0x01));

               ir_variable *const r041F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r041F);
               ir_variable *const r0420 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0420);
               ir_variable *const r0421 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0421);
               ir_variable *const r0422 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0423 = neg(r041E);
               body.emit(assign(r0422, bit_and(r0423, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0425 = less(r041E, body.constant(int(32)));
               ir_if *f0424 = new(mem_ctx) ir_if(operand(r0425).val);
               exec_list *const f0424_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0424->then_instructions;

                  body.emit(assign(r041F, lshift(r0407, r0422), 0x01));

                  ir_expression *const r0426 = lshift(r0406, r0422);
                  ir_expression *const r0427 = rshift(r0407, r041E);
                  body.emit(assign(r0420, bit_or(r0426, r0427), 0x01));

                  body.emit(assign(r0421, rshift(r0406, r041E), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0424->else_instructions;

                  body.emit(assign(r041D, bit_or(body.constant(0u), r0407), 0x01));

                  ir_expression *const r0428 = less(r041E, body.constant(int(64)));
                  ir_expression *const r0429 = lshift(r0406, r0422);
                  ir_expression *const r042A = equal(r041E, body.constant(int(64)));
                  ir_expression *const r042B = nequal(r0406, body.constant(0u));
                  ir_expression *const r042C = expr(ir_unop_b2i, r042B);
                  ir_expression *const r042D = expr(ir_unop_i2u, r042C);
                  ir_expression *const r042E = expr(ir_triop_csel, r042A, r0406, r042D);
                  body.emit(assign(r041F, expr(ir_triop_csel, r0428, r0429, r042E), 0x01));

                  ir_expression *const r042F = less(r041E, body.constant(int(64)));
                  ir_expression *const r0430 = bit_and(r041E, body.constant(int(31)));
                  ir_expression *const r0431 = rshift(r0406, r0430);
                  body.emit(assign(r0420, expr(ir_triop_csel, r042F, r0431, body.constant(0u)), 0x01));

                  body.emit(assign(r0421, body.constant(0u), 0x01));


               body.instructions = f0424_parent_instructions;
               body.emit(f0424);

               /* END IF */

               ir_expression *const r0432 = nequal(r041D, body.constant(0u));
               ir_expression *const r0433 = expr(ir_unop_b2i, r0432);
               ir_expression *const r0434 = expr(ir_unop_i2u, r0433);
               body.emit(assign(r041F, bit_or(r041F, r0434), 0x01));

               ir_variable *const r0435 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0436 = equal(r041E, body.constant(int(0)));
               ir_expression *const r0437 = equal(r041E, body.constant(int(32)));
               ir_expression *const r0438 = expr(ir_triop_csel, r0437, body.constant(0u), r0421);
               body.emit(assign(r0435, expr(ir_triop_csel, r0436, r0406, r0438), 0x01));

               body.emit(assign(r0421, r0435, 0x01));

               ir_variable *const r0439 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r043A = equal(r041E, body.constant(int(0)));
               ir_expression *const r043B = equal(r041E, body.constant(int(32)));
               ir_expression *const r043C = expr(ir_triop_csel, r043B, r0406, r0420);
               body.emit(assign(r0439, expr(ir_triop_csel, r043A, r0407, r043C), 0x01));

               body.emit(assign(r0420, r0439, 0x01));

               ir_variable *const r043D = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r043E = equal(r041E, body.constant(int(0)));
               ir_expression *const r043F = equal(r041E, body.constant(int(32)));
               ir_expression *const r0440 = expr(ir_triop_csel, r043F, r0407, r041F);
               body.emit(assign(r043D, expr(ir_triop_csel, r043E, r041D, r0440), 0x01));

               body.emit(assign(r041F, r043D, 0x01));

               body.emit(assign(r0406, r0435, 0x01));

               body.emit(assign(r0407, r0439, 0x01));

               body.emit(assign(r0408, r043D, 0x01));


            body.instructions = f0415_parent_instructions;
            body.emit(f0415);

            /* END IF */

            body.emit(assign(r0405, sub(r0405, r0409), 0x01));

            ir_variable *const r0441 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0441, r0405, 0x01));

            ir_variable *const r0442 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0442, r0406, 0x01));

            ir_variable *const r0443 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0443, r0407, 0x01));

            ir_variable *const r0444 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0444, r0408, 0x01));

            ir_variable *const r0445 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0445, body.constant(true), 0x01));

            ir_variable *const r0446 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0447 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0447);
            ir_expression *const r0448 = expr(ir_unop_u2i, r0408);
            body.emit(assign(r0447, less(r0448, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r044A = gequal(r0405, body.constant(int(2045)));
            ir_if *f0449 = new(mem_ctx) ir_if(operand(r044A).val);
            exec_list *const f0449_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0449->then_instructions;

               /* IF CONDITION */
               ir_expression *const r044C = less(body.constant(int(2045)), r0405);
               ir_expression *const r044D = equal(r0405, body.constant(int(2045)));
               ir_expression *const r044E = equal(body.constant(2097151u), r0406);
               ir_expression *const r044F = equal(body.constant(4294967295u), r0407);
               ir_expression *const r0450 = logic_and(r044E, r044F);
               ir_expression *const r0451 = logic_and(r044D, r0450);
               ir_expression *const r0452 = logic_and(r0451, r0447);
               ir_expression *const r0453 = logic_or(r044C, r0452);
               ir_if *f044B = new(mem_ctx) ir_if(operand(r0453).val);
               exec_list *const f044B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f044B->then_instructions;

                  ir_variable *const r0454 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0454);
                  ir_expression *const r0455 = lshift(r01FA, body.constant(int(31)));
                  body.emit(assign(r0454, add(r0455, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0454, body.constant(0u), 0x01));

                  body.emit(assign(r0446, r0454, 0x03));

                  body.emit(assign(r0445, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f044B->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0457 = less(r0405, body.constant(int(0)));
                  ir_if *f0456 = new(mem_ctx) ir_if(operand(r0457).val);
                  exec_list *const f0456_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0456->then_instructions;

                     ir_variable *const r0458 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0458, r0408, 0x01));

                     ir_variable *const r0459 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0459, neg(r0405), 0x01));

                     ir_variable *const r045A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r045A);
                     ir_variable *const r045B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r045B);
                     ir_variable *const r045C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r045C);
                     ir_variable *const r045D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r045E = neg(r0459);
                     body.emit(assign(r045D, bit_and(r045E, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0460 = less(r0459, body.constant(int(32)));
                     ir_if *f045F = new(mem_ctx) ir_if(operand(r0460).val);
                     exec_list *const f045F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f045F->then_instructions;

                        body.emit(assign(r045A, lshift(r0407, r045D), 0x01));

                        ir_expression *const r0461 = lshift(r0406, r045D);
                        ir_expression *const r0462 = rshift(r0407, r0459);
                        body.emit(assign(r045B, bit_or(r0461, r0462), 0x01));

                        body.emit(assign(r045C, rshift(r0406, r0459), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f045F->else_instructions;

                        body.emit(assign(r0458, bit_or(r0408, r0407), 0x01));

                        ir_expression *const r0463 = less(r0459, body.constant(int(64)));
                        ir_expression *const r0464 = lshift(r0406, r045D);
                        ir_expression *const r0465 = equal(r0459, body.constant(int(64)));
                        ir_expression *const r0466 = nequal(r0406, body.constant(0u));
                        ir_expression *const r0467 = expr(ir_unop_b2i, r0466);
                        ir_expression *const r0468 = expr(ir_unop_i2u, r0467);
                        ir_expression *const r0469 = expr(ir_triop_csel, r0465, r0406, r0468);
                        body.emit(assign(r045A, expr(ir_triop_csel, r0463, r0464, r0469), 0x01));

                        ir_expression *const r046A = less(r0459, body.constant(int(64)));
                        ir_expression *const r046B = bit_and(r0459, body.constant(int(31)));
                        ir_expression *const r046C = rshift(r0406, r046B);
                        body.emit(assign(r045B, expr(ir_triop_csel, r046A, r046C, body.constant(0u)), 0x01));

                        body.emit(assign(r045C, body.constant(0u), 0x01));


                     body.instructions = f045F_parent_instructions;
                     body.emit(f045F);

                     /* END IF */

                     ir_expression *const r046D = nequal(r0458, body.constant(0u));
                     ir_expression *const r046E = expr(ir_unop_b2i, r046D);
                     ir_expression *const r046F = expr(ir_unop_i2u, r046E);
                     body.emit(assign(r045A, bit_or(r045A, r046F), 0x01));

                     ir_variable *const r0470 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0471 = equal(r0459, body.constant(int(0)));
                     ir_expression *const r0472 = equal(r0459, body.constant(int(32)));
                     ir_expression *const r0473 = expr(ir_triop_csel, r0472, body.constant(0u), r045C);
                     body.emit(assign(r0470, expr(ir_triop_csel, r0471, r0406, r0473), 0x01));

                     body.emit(assign(r045C, r0470, 0x01));

                     ir_variable *const r0474 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0475 = equal(r0459, body.constant(int(0)));
                     ir_expression *const r0476 = equal(r0459, body.constant(int(32)));
                     ir_expression *const r0477 = expr(ir_triop_csel, r0476, r0406, r045B);
                     body.emit(assign(r0474, expr(ir_triop_csel, r0475, r0407, r0477), 0x01));

                     body.emit(assign(r045B, r0474, 0x01));

                     ir_variable *const r0478 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0479 = equal(r0459, body.constant(int(0)));
                     ir_expression *const r047A = equal(r0459, body.constant(int(32)));
                     ir_expression *const r047B = expr(ir_triop_csel, r047A, r0407, r045A);
                     body.emit(assign(r0478, expr(ir_triop_csel, r0479, r0458, r047B), 0x01));

                     body.emit(assign(r045A, r0478, 0x01));

                     body.emit(assign(r0442, r0470, 0x01));

                     body.emit(assign(r0443, r0474, 0x01));

                     body.emit(assign(r0444, r0478, 0x01));

                     body.emit(assign(r0441, body.constant(int(0)), 0x01));

                     body.emit(assign(r0447, less(r0478, body.constant(0u)), 0x01));


                  body.instructions = f0456_parent_instructions;
                  body.emit(f0456);

                  /* END IF */


               body.instructions = f044B_parent_instructions;
               body.emit(f044B);

               /* END IF */


            body.instructions = f0449_parent_instructions;
            body.emit(f0449);

            /* END IF */

            /* IF CONDITION */
            ir_if *f047C = new(mem_ctx) ir_if(operand(r0445).val);
            exec_list *const f047C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f047C->then_instructions;

               /* IF CONDITION */
               ir_if *f047D = new(mem_ctx) ir_if(operand(r0447).val);
               exec_list *const f047D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f047D->then_instructions;

                  ir_variable *const r047E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r047E, add(r0443, body.constant(1u)), 0x01));

                  ir_expression *const r047F = less(r047E, r0443);
                  ir_expression *const r0480 = expr(ir_unop_b2i, r047F);
                  ir_expression *const r0481 = expr(ir_unop_i2u, r0480);
                  body.emit(assign(r0442, add(r0442, r0481), 0x01));

                  ir_expression *const r0482 = equal(r0444, body.constant(0u));
                  ir_expression *const r0483 = expr(ir_unop_b2i, r0482);
                  ir_expression *const r0484 = expr(ir_unop_i2u, r0483);
                  ir_expression *const r0485 = add(r0444, r0484);
                  ir_expression *const r0486 = bit_and(r0485, body.constant(1u));
                  ir_expression *const r0487 = expr(ir_unop_bit_not, r0486);
                  body.emit(assign(r0443, bit_and(r047E, r0487), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f047D->else_instructions;

                  ir_expression *const r0488 = bit_or(r0442, r0443);
                  ir_expression *const r0489 = equal(r0488, body.constant(0u));
                  body.emit(assign(r0441, expr(ir_triop_csel, r0489, body.constant(int(0)), r0441), 0x01));


               body.instructions = f047D_parent_instructions;
               body.emit(f047D);

               /* END IF */

               ir_variable *const r048A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r048A);
               ir_expression *const r048B = lshift(r01FA, body.constant(int(31)));
               ir_expression *const r048C = expr(ir_unop_i2u, r0441);
               ir_expression *const r048D = lshift(r048C, body.constant(int(20)));
               ir_expression *const r048E = add(r048B, r048D);
               body.emit(assign(r048A, add(r048E, r0442), 0x02));

               body.emit(assign(r048A, r0443, 0x01));

               body.emit(assign(r0446, r048A, 0x03));

               body.emit(assign(r0445, body.constant(false), 0x01));


            body.instructions = f047C_parent_instructions;
            body.emit(f047C);

            /* END IF */

            body.emit(assign(r01F0, r0446, 0x03));

            body.emit(assign(r01EF, body.constant(false), 0x01));


         body.instructions = f03BE_parent_instructions;
         body.emit(f03BE);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f03BC->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0490 = less(r01F1, body.constant(int(0)));
         ir_if *f048F = new(mem_ctx) ir_if(operand(r0490).val);
         exec_list *const f048F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f048F->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0492 = equal(r0201, body.constant(int(2047)));
            ir_if *f0491 = new(mem_ctx) ir_if(operand(r0492).val);
            exec_list *const f0491_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0491->then_instructions;

               ir_variable *const r0493 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0493);
               ir_expression *const r0494 = bit_xor(r01FA, body.constant(1u));
               ir_expression *const r0495 = lshift(r0494, body.constant(int(31)));
               body.emit(assign(r0493, add(r0495, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0493, body.constant(0u), 0x01));

               ir_variable *const r0496 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0496, swizzle_x(r01ED), 0x01));

               ir_variable *const r0497 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0497, swizzle_x(r01EE), 0x01));

               body.emit(assign(r0496, bit_or(swizzle_y(r01ED), body.constant(524288u)), 0x02));

               body.emit(assign(r0497, bit_or(swizzle_y(r01EE), body.constant(524288u)), 0x02));

               ir_expression *const r0498 = bit_or(r01F5, r01F6);
               ir_expression *const r0499 = nequal(r0498, body.constant(0u));
               ir_swizzle *const r049A = swizzle(r0499, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r049B = lshift(swizzle_y(r01ED), body.constant(int(1)));
               ir_expression *const r049C = gequal(r049B, body.constant(4292870144u));
               ir_expression *const r049D = nequal(swizzle_x(r01ED), body.constant(0u));
               ir_expression *const r049E = bit_and(swizzle_y(r01ED), body.constant(1048575u));
               ir_expression *const r049F = nequal(r049E, body.constant(0u));
               ir_expression *const r04A0 = logic_or(r049D, r049F);
               ir_expression *const r04A1 = logic_and(r049C, r04A0);
               ir_swizzle *const r04A2 = swizzle(r04A1, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r04A3 = lshift(swizzle_y(r01EE), body.constant(int(1)));
               ir_expression *const r04A4 = gequal(r04A3, body.constant(4292870144u));
               ir_expression *const r04A5 = nequal(swizzle_x(r01EE), body.constant(0u));
               ir_expression *const r04A6 = bit_and(swizzle_y(r01EE), body.constant(1048575u));
               ir_expression *const r04A7 = nequal(r04A6, body.constant(0u));
               ir_expression *const r04A8 = logic_or(r04A5, r04A7);
               ir_expression *const r04A9 = logic_and(r04A4, r04A8);
               ir_swizzle *const r04AA = swizzle(r04A9, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r04AB = expr(ir_triop_csel, r04AA, r0497, r0496);
               ir_expression *const r04AC = expr(ir_triop_csel, r04A2, r04AB, r0497);
               body.emit(assign(r01F0, expr(ir_triop_csel, r049A, r04AC, r0493), 0x03));

               body.emit(assign(r01EF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0491->else_instructions;

               /* IF CONDITION */
               ir_expression *const r04AE = equal(r01FE, body.constant(int(0)));
               ir_if *f04AD = new(mem_ctx) ir_if(operand(r04AE).val);
               exec_list *const f04AD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04AD->then_instructions;

                  body.emit(assign(r01F1, add(r01F1, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04AD->else_instructions;

                  body.emit(assign(r01F7, bit_or(r01F7, body.constant(1073741824u)), 0x01));


               body.instructions = f04AD_parent_instructions;
               body.emit(f04AD);

               /* END IF */

               ir_variable *const r04AF = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r04AF, neg(r01F1), 0x01));

               ir_variable *const r04B0 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r04B1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r04B1);
               ir_variable *const r04B2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r04B3 = neg(r04AF);
               body.emit(assign(r04B2, bit_and(r04B3, body.constant(int(31))), 0x01));

               ir_expression *const r04B4 = bit_or(r01F7, r03B5);
               ir_expression *const r04B5 = nequal(r04B4, body.constant(0u));
               ir_expression *const r04B6 = expr(ir_unop_b2i, r04B5);
               body.emit(assign(r04B1, expr(ir_unop_i2u, r04B6), 0x01));

               ir_variable *const r04B7 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04B8 = equal(r04AF, body.constant(int(0)));
               ir_expression *const r04B9 = less(r04AF, body.constant(int(32)));
               ir_expression *const r04BA = lshift(r01F7, r04B2);
               ir_expression *const r04BB = rshift(r03B5, r04AF);
               ir_expression *const r04BC = bit_or(r04BA, r04BB);
               ir_expression *const r04BD = lshift(r03B5, r04B2);
               ir_expression *const r04BE = nequal(r04BD, body.constant(0u));
               ir_expression *const r04BF = expr(ir_unop_b2i, r04BE);
               ir_expression *const r04C0 = expr(ir_unop_i2u, r04BF);
               ir_expression *const r04C1 = bit_or(r04BC, r04C0);
               ir_expression *const r04C2 = equal(r04AF, body.constant(int(32)));
               ir_expression *const r04C3 = nequal(r03B5, body.constant(0u));
               ir_expression *const r04C4 = expr(ir_unop_b2i, r04C3);
               ir_expression *const r04C5 = expr(ir_unop_i2u, r04C4);
               ir_expression *const r04C6 = bit_or(r01F7, r04C5);
               ir_expression *const r04C7 = less(r04AF, body.constant(int(64)));
               ir_expression *const r04C8 = bit_and(r04AF, body.constant(int(31)));
               ir_expression *const r04C9 = rshift(r01F7, r04C8);
               ir_expression *const r04CA = lshift(r01F7, r04B2);
               ir_expression *const r04CB = bit_or(r04CA, r03B5);
               ir_expression *const r04CC = nequal(r04CB, body.constant(0u));
               ir_expression *const r04CD = expr(ir_unop_b2i, r04CC);
               ir_expression *const r04CE = expr(ir_unop_i2u, r04CD);
               ir_expression *const r04CF = bit_or(r04C9, r04CE);
               ir_expression *const r04D0 = expr(ir_triop_csel, r04C7, r04CF, r04B1);
               ir_expression *const r04D1 = expr(ir_triop_csel, r04C2, r04C6, r04D0);
               ir_expression *const r04D2 = expr(ir_triop_csel, r04B9, r04C1, r04D1);
               body.emit(assign(r04B7, expr(ir_triop_csel, r04B8, r03B5, r04D2), 0x01));

               body.emit(assign(r04B1, r04B7, 0x01));

               ir_expression *const r04D3 = less(r04AF, body.constant(int(32)));
               ir_expression *const r04D4 = rshift(r01F7, r04AF);
               ir_expression *const r04D5 = equal(r04AF, body.constant(int(0)));
               ir_expression *const r04D6 = expr(ir_triop_csel, r04D5, r01F7, body.constant(0u));
               body.emit(assign(r04B0, expr(ir_triop_csel, r04D3, r04D4, r04D6), 0x01));

               body.emit(assign(r01F7, r04B0, 0x01));

               body.emit(assign(r01F8, r04B7, 0x01));

               body.emit(assign(r01F5, bit_or(r01F5, body.constant(1073741824u)), 0x01));

               ir_variable *const r04D7 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_expression *const r04D8 = sub(r01F5, r04B0);
               ir_expression *const r04D9 = less(r01F6, r04B7);
               ir_expression *const r04DA = expr(ir_unop_b2i, r04D9);
               ir_expression *const r04DB = expr(ir_unop_i2u, r04DA);
               body.emit(assign(r04D7, sub(r04D8, r04DB), 0x01));

               body.emit(assign(r01F2, r04D7, 0x01));

               body.emit(assign(r01F9, bit_xor(r01FA, body.constant(1u)), 0x01));

               body.emit(assign(r03B3, add(r0201, body.constant(int(-1))), 0x01));

               ir_variable *const r04DC = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04DC, add(r03B3, body.constant(int(-10))), 0x01));

               ir_variable *const r04DD = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r04DE = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r04DF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r04DF);
               ir_variable *const r04E0 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04E0);
               ir_expression *const r04E1 = equal(r04D7, body.constant(0u));
               ir_expression *const r04E2 = add(r04DC, body.constant(int(-32)));
               body.emit(assign(r04DC, expr(ir_triop_csel, r04E1, r04E2, r04DC), 0x01));

               ir_variable *const r04E3 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04E4 = equal(r04D7, body.constant(0u));
               ir_expression *const r04E5 = sub(r01F6, r04B7);
               body.emit(assign(r04E3, expr(ir_triop_csel, r04E4, body.constant(0u), r04E5), 0x01));

               body.emit(assign(r04DE, r04E3, 0x01));

               ir_variable *const r04E6 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04E7 = equal(r04D7, body.constant(0u));
               body.emit(assign(r04E6, expr(ir_triop_csel, r04E7, r04E3, r04D7), 0x01));

               body.emit(assign(r04DD, r04E6, 0x01));

               ir_expression *const r04E8 = equal(r04E6, body.constant(0u));
               ir_expression *const r04E9 = expr(ir_unop_find_msb, r04E6);
               ir_expression *const r04EA = sub(body.constant(int(31)), r04E9);
               ir_expression *const r04EB = expr(ir_triop_csel, r04E8, body.constant(int(32)), r04EA);
               body.emit(assign(r04E0, add(r04EB, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04ED = gequal(r04E0, body.constant(int(0)));
               ir_if *f04EC = new(mem_ctx) ir_if(operand(r04ED).val);
               exec_list *const f04EC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04EC->then_instructions;

                  body.emit(assign(r04DF, body.constant(0u), 0x01));

                  ir_expression *const r04EE = equal(r04E0, body.constant(int(0)));
                  ir_expression *const r04EF = lshift(r04E6, r04E0);
                  ir_expression *const r04F0 = neg(r04E0);
                  ir_expression *const r04F1 = bit_and(r04F0, body.constant(int(31)));
                  ir_expression *const r04F2 = rshift(r04E3, r04F1);
                  ir_expression *const r04F3 = bit_or(r04EF, r04F2);
                  body.emit(assign(r04DD, expr(ir_triop_csel, r04EE, r04E6, r04F3), 0x01));

                  body.emit(assign(r04DE, lshift(r04E3, r04E0), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04EC->else_instructions;

                  ir_variable *const r04F4 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r04F4, body.constant(0u), 0x01));

                  ir_variable *const r04F5 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r04F5, neg(r04E0), 0x01));

                  ir_variable *const r04F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04F6);
                  ir_variable *const r04F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r04F7);
                  ir_variable *const r04F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04F8);
                  ir_variable *const r04F9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04FA = neg(r04F5);
                  body.emit(assign(r04F9, bit_and(r04FA, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04FC = less(r04F5, body.constant(int(32)));
                  ir_if *f04FB = new(mem_ctx) ir_if(operand(r04FC).val);
                  exec_list *const f04FB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04FB->then_instructions;

                     body.emit(assign(r04F6, lshift(r04DE, r04F9), 0x01));

                     ir_expression *const r04FD = lshift(r04DD, r04F9);
                     ir_expression *const r04FE = rshift(r04DE, r04F5);
                     body.emit(assign(r04F7, bit_or(r04FD, r04FE), 0x01));

                     body.emit(assign(r04F8, rshift(r04DD, r04F5), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04FB->else_instructions;

                     body.emit(assign(r04F4, bit_or(body.constant(0u), r04DE), 0x01));

                     ir_expression *const r04FF = less(r04F5, body.constant(int(64)));
                     ir_expression *const r0500 = lshift(r04DD, r04F9);
                     ir_expression *const r0501 = equal(r04F5, body.constant(int(64)));
                     ir_expression *const r0502 = nequal(r04DD, body.constant(0u));
                     ir_expression *const r0503 = expr(ir_unop_b2i, r0502);
                     ir_expression *const r0504 = expr(ir_unop_i2u, r0503);
                     ir_expression *const r0505 = expr(ir_triop_csel, r0501, r04DD, r0504);
                     body.emit(assign(r04F6, expr(ir_triop_csel, r04FF, r0500, r0505), 0x01));

                     ir_expression *const r0506 = less(r04F5, body.constant(int(64)));
                     ir_expression *const r0507 = bit_and(r04F5, body.constant(int(31)));
                     ir_expression *const r0508 = rshift(r04DD, r0507);
                     body.emit(assign(r04F7, expr(ir_triop_csel, r0506, r0508, body.constant(0u)), 0x01));

                     body.emit(assign(r04F8, body.constant(0u), 0x01));


                  body.instructions = f04FB_parent_instructions;
                  body.emit(f04FB);

                  /* END IF */

                  ir_expression *const r0509 = nequal(r04F4, body.constant(0u));
                  ir_expression *const r050A = expr(ir_unop_b2i, r0509);
                  ir_expression *const r050B = expr(ir_unop_i2u, r050A);
                  body.emit(assign(r04F6, bit_or(r04F6, r050B), 0x01));

                  ir_variable *const r050C = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r050D = equal(r04F5, body.constant(int(0)));
                  ir_expression *const r050E = equal(r04F5, body.constant(int(32)));
                  ir_expression *const r050F = expr(ir_triop_csel, r050E, body.constant(0u), r04F8);
                  body.emit(assign(r050C, expr(ir_triop_csel, r050D, r04DD, r050F), 0x01));

                  body.emit(assign(r04F8, r050C, 0x01));

                  ir_variable *const r0510 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0511 = equal(r04F5, body.constant(int(0)));
                  ir_expression *const r0512 = equal(r04F5, body.constant(int(32)));
                  ir_expression *const r0513 = expr(ir_triop_csel, r0512, r04DD, r04F7);
                  body.emit(assign(r0510, expr(ir_triop_csel, r0511, r04DE, r0513), 0x01));

                  body.emit(assign(r04F7, r0510, 0x01));

                  ir_variable *const r0514 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0515 = equal(r04F5, body.constant(int(0)));
                  ir_expression *const r0516 = equal(r04F5, body.constant(int(32)));
                  ir_expression *const r0517 = expr(ir_triop_csel, r0516, r04DE, r04F6);
                  body.emit(assign(r0514, expr(ir_triop_csel, r0515, r04F4, r0517), 0x01));

                  body.emit(assign(r04F6, r0514, 0x01));

                  body.emit(assign(r04DD, r050C, 0x01));

                  body.emit(assign(r04DE, r0510, 0x01));

                  body.emit(assign(r04DF, r0514, 0x01));


               body.instructions = f04EC_parent_instructions;
               body.emit(f04EC);

               /* END IF */

               body.emit(assign(r04DC, sub(r04DC, r04E0), 0x01));

               ir_variable *const r0518 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0518, r04DC, 0x01));

               ir_variable *const r0519 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r0519, r04DD, 0x01));

               ir_variable *const r051A = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r051A, r04DE, 0x01));

               ir_variable *const r051B = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r051B, r04DF, 0x01));

               ir_variable *const r051C = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r051C, body.constant(true), 0x01));

               ir_variable *const r051D = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r051E = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r051E);
               ir_expression *const r051F = expr(ir_unop_u2i, r04DF);
               body.emit(assign(r051E, less(r051F, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0521 = gequal(r04DC, body.constant(int(2045)));
               ir_if *f0520 = new(mem_ctx) ir_if(operand(r0521).val);
               exec_list *const f0520_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0520->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0523 = less(body.constant(int(2045)), r04DC);
                  ir_expression *const r0524 = equal(r04DC, body.constant(int(2045)));
                  ir_expression *const r0525 = equal(body.constant(2097151u), r04DD);
                  ir_expression *const r0526 = equal(body.constant(4294967295u), r04DE);
                  ir_expression *const r0527 = logic_and(r0525, r0526);
                  ir_expression *const r0528 = logic_and(r0524, r0527);
                  ir_expression *const r0529 = logic_and(r0528, r051E);
                  ir_expression *const r052A = logic_or(r0523, r0529);
                  ir_if *f0522 = new(mem_ctx) ir_if(operand(r052A).val);
                  exec_list *const f0522_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0522->then_instructions;

                     ir_variable *const r052B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r052B);
                     ir_expression *const r052C = lshift(r01F9, body.constant(int(31)));
                     body.emit(assign(r052B, add(r052C, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r052B, body.constant(0u), 0x01));

                     body.emit(assign(r051D, r052B, 0x03));

                     body.emit(assign(r051C, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0522->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r052E = less(r04DC, body.constant(int(0)));
                     ir_if *f052D = new(mem_ctx) ir_if(operand(r052E).val);
                     exec_list *const f052D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f052D->then_instructions;

                        ir_variable *const r052F = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r052F, r04DF, 0x01));

                        ir_variable *const r0530 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0530, neg(r04DC), 0x01));

                        ir_variable *const r0531 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0531);
                        ir_variable *const r0532 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r0532);
                        ir_variable *const r0533 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0533);
                        ir_variable *const r0534 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0535 = neg(r0530);
                        body.emit(assign(r0534, bit_and(r0535, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0537 = less(r0530, body.constant(int(32)));
                        ir_if *f0536 = new(mem_ctx) ir_if(operand(r0537).val);
                        exec_list *const f0536_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0536->then_instructions;

                           body.emit(assign(r0531, lshift(r04DE, r0534), 0x01));

                           ir_expression *const r0538 = lshift(r04DD, r0534);
                           ir_expression *const r0539 = rshift(r04DE, r0530);
                           body.emit(assign(r0532, bit_or(r0538, r0539), 0x01));

                           body.emit(assign(r0533, rshift(r04DD, r0530), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0536->else_instructions;

                           body.emit(assign(r052F, bit_or(r04DF, r04DE), 0x01));

                           ir_expression *const r053A = less(r0530, body.constant(int(64)));
                           ir_expression *const r053B = lshift(r04DD, r0534);
                           ir_expression *const r053C = equal(r0530, body.constant(int(64)));
                           ir_expression *const r053D = nequal(r04DD, body.constant(0u));
                           ir_expression *const r053E = expr(ir_unop_b2i, r053D);
                           ir_expression *const r053F = expr(ir_unop_i2u, r053E);
                           ir_expression *const r0540 = expr(ir_triop_csel, r053C, r04DD, r053F);
                           body.emit(assign(r0531, expr(ir_triop_csel, r053A, r053B, r0540), 0x01));

                           ir_expression *const r0541 = less(r0530, body.constant(int(64)));
                           ir_expression *const r0542 = bit_and(r0530, body.constant(int(31)));
                           ir_expression *const r0543 = rshift(r04DD, r0542);
                           body.emit(assign(r0532, expr(ir_triop_csel, r0541, r0543, body.constant(0u)), 0x01));

                           body.emit(assign(r0533, body.constant(0u), 0x01));


                        body.instructions = f0536_parent_instructions;
                        body.emit(f0536);

                        /* END IF */

                        ir_expression *const r0544 = nequal(r052F, body.constant(0u));
                        ir_expression *const r0545 = expr(ir_unop_b2i, r0544);
                        ir_expression *const r0546 = expr(ir_unop_i2u, r0545);
                        body.emit(assign(r0531, bit_or(r0531, r0546), 0x01));

                        ir_variable *const r0547 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0548 = equal(r0530, body.constant(int(0)));
                        ir_expression *const r0549 = equal(r0530, body.constant(int(32)));
                        ir_expression *const r054A = expr(ir_triop_csel, r0549, body.constant(0u), r0533);
                        body.emit(assign(r0547, expr(ir_triop_csel, r0548, r04DD, r054A), 0x01));

                        body.emit(assign(r0533, r0547, 0x01));

                        ir_variable *const r054B = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r054C = equal(r0530, body.constant(int(0)));
                        ir_expression *const r054D = equal(r0530, body.constant(int(32)));
                        ir_expression *const r054E = expr(ir_triop_csel, r054D, r04DD, r0532);
                        body.emit(assign(r054B, expr(ir_triop_csel, r054C, r04DE, r054E), 0x01));

                        body.emit(assign(r0532, r054B, 0x01));

                        ir_variable *const r054F = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0550 = equal(r0530, body.constant(int(0)));
                        ir_expression *const r0551 = equal(r0530, body.constant(int(32)));
                        ir_expression *const r0552 = expr(ir_triop_csel, r0551, r04DE, r0531);
                        body.emit(assign(r054F, expr(ir_triop_csel, r0550, r052F, r0552), 0x01));

                        body.emit(assign(r0531, r054F, 0x01));

                        body.emit(assign(r0519, r0547, 0x01));

                        body.emit(assign(r051A, r054B, 0x01));

                        body.emit(assign(r051B, r054F, 0x01));

                        body.emit(assign(r0518, body.constant(int(0)), 0x01));

                        body.emit(assign(r051E, less(r054F, body.constant(0u)), 0x01));


                     body.instructions = f052D_parent_instructions;
                     body.emit(f052D);

                     /* END IF */


                  body.instructions = f0522_parent_instructions;
                  body.emit(f0522);

                  /* END IF */


               body.instructions = f0520_parent_instructions;
               body.emit(f0520);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0553 = new(mem_ctx) ir_if(operand(r051C).val);
               exec_list *const f0553_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0553->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0554 = new(mem_ctx) ir_if(operand(r051E).val);
                  exec_list *const f0554_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0554->then_instructions;

                     ir_variable *const r0555 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0555, add(r051A, body.constant(1u)), 0x01));

                     ir_expression *const r0556 = less(r0555, r051A);
                     ir_expression *const r0557 = expr(ir_unop_b2i, r0556);
                     ir_expression *const r0558 = expr(ir_unop_i2u, r0557);
                     body.emit(assign(r0519, add(r0519, r0558), 0x01));

                     ir_expression *const r0559 = equal(r051B, body.constant(0u));
                     ir_expression *const r055A = expr(ir_unop_b2i, r0559);
                     ir_expression *const r055B = expr(ir_unop_i2u, r055A);
                     ir_expression *const r055C = add(r051B, r055B);
                     ir_expression *const r055D = bit_and(r055C, body.constant(1u));
                     ir_expression *const r055E = expr(ir_unop_bit_not, r055D);
                     body.emit(assign(r051A, bit_and(r0555, r055E), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0554->else_instructions;

                     ir_expression *const r055F = bit_or(r0519, r051A);
                     ir_expression *const r0560 = equal(r055F, body.constant(0u));
                     body.emit(assign(r0518, expr(ir_triop_csel, r0560, body.constant(int(0)), r0518), 0x01));


                  body.instructions = f0554_parent_instructions;
                  body.emit(f0554);

                  /* END IF */

                  ir_variable *const r0561 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0561);
                  ir_expression *const r0562 = lshift(r01F9, body.constant(int(31)));
                  ir_expression *const r0563 = expr(ir_unop_i2u, r0518);
                  ir_expression *const r0564 = lshift(r0563, body.constant(int(20)));
                  ir_expression *const r0565 = add(r0562, r0564);
                  body.emit(assign(r0561, add(r0565, r0519), 0x02));

                  body.emit(assign(r0561, r051A, 0x01));

                  body.emit(assign(r051D, r0561, 0x03));

                  body.emit(assign(r051C, body.constant(false), 0x01));


               body.instructions = f0553_parent_instructions;
               body.emit(f0553);

               /* END IF */

               body.emit(assign(r01F0, r051D, 0x03));

               body.emit(assign(r01EF, body.constant(false), 0x01));


            body.instructions = f0491_parent_instructions;
            body.emit(f0491);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f048F->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0567 = equal(r01FE, body.constant(int(2047)));
            ir_if *f0566 = new(mem_ctx) ir_if(operand(r0567).val);
            exec_list *const f0566_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0566->then_instructions;

               ir_variable *const r0568 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0568, swizzle_x(r01ED), 0x01));

               ir_variable *const r0569 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0569, swizzle_x(r01EE), 0x01));

               body.emit(assign(r0568, bit_or(swizzle_y(r01ED), body.constant(524288u)), 0x02));

               body.emit(assign(r0569, bit_or(swizzle_y(r01EE), body.constant(524288u)), 0x02));

               ir_expression *const r056A = bit_or(r01F7, r01F8);
               ir_expression *const r056B = bit_or(r01F5, r01F6);
               ir_expression *const r056C = bit_or(r056A, r056B);
               ir_expression *const r056D = nequal(r056C, body.constant(0u));
               ir_swizzle *const r056E = swizzle(r056D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r056F = lshift(swizzle_y(r01ED), body.constant(int(1)));
               ir_expression *const r0570 = gequal(r056F, body.constant(4292870144u));
               ir_expression *const r0571 = nequal(swizzle_x(r01ED), body.constant(0u));
               ir_expression *const r0572 = bit_and(swizzle_y(r01ED), body.constant(1048575u));
               ir_expression *const r0573 = nequal(r0572, body.constant(0u));
               ir_expression *const r0574 = logic_or(r0571, r0573);
               ir_expression *const r0575 = logic_and(r0570, r0574);
               ir_swizzle *const r0576 = swizzle(r0575, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0577 = lshift(swizzle_y(r01EE), body.constant(int(1)));
               ir_expression *const r0578 = gequal(r0577, body.constant(4292870144u));
               ir_expression *const r0579 = nequal(swizzle_x(r01EE), body.constant(0u));
               ir_expression *const r057A = bit_and(swizzle_y(r01EE), body.constant(1048575u));
               ir_expression *const r057B = nequal(r057A, body.constant(0u));
               ir_expression *const r057C = logic_or(r0579, r057B);
               ir_expression *const r057D = logic_and(r0578, r057C);
               ir_swizzle *const r057E = swizzle(r057D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r057F = expr(ir_triop_csel, r057E, r0569, r0568);
               ir_expression *const r0580 = expr(ir_triop_csel, r0576, r057F, r0569);
               ir_constant_data r0581_data;
               memset(&r0581_data, 0, sizeof(ir_constant_data));
               r0581_data.u[0] = 4294967295;
               r0581_data.u[1] = 4294967295;
               ir_constant *const r0581 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0581_data);
               body.emit(assign(r01F0, expr(ir_triop_csel, r056E, r0580, r0581), 0x03));

               body.emit(assign(r01EF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0566->else_instructions;

               ir_expression *const r0582 = equal(r01FE, body.constant(int(0)));
               body.emit(assign(r01F3, expr(ir_triop_csel, r0582, body.constant(int(1)), r0201), 0x01));

               ir_expression *const r0583 = equal(r01FE, body.constant(int(0)));
               body.emit(assign(r01F4, expr(ir_triop_csel, r0583, body.constant(int(1)), r01FE), 0x01));

               /* IF CONDITION */
               ir_expression *const r0585 = less(r01F5, r01F7);
               ir_if *f0584 = new(mem_ctx) ir_if(operand(r0585).val);
               exec_list *const f0584_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0584->then_instructions;

                  ir_variable *const r0586 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_expression *const r0587 = sub(r01F7, r01F5);
                  ir_expression *const r0588 = less(r01F8, r01F6);
                  ir_expression *const r0589 = expr(ir_unop_b2i, r0588);
                  ir_expression *const r058A = expr(ir_unop_i2u, r0589);
                  body.emit(assign(r0586, sub(r0587, r058A), 0x01));

                  body.emit(assign(r01F2, r0586, 0x01));

                  body.emit(assign(r03B3, add(r01F4, body.constant(int(-1))), 0x01));

                  ir_variable *const r058B = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r058B, add(r03B3, body.constant(int(-10))), 0x01));

                  ir_variable *const r058C = body.make_temp(glsl_type::uint_type, "zFrac0");
                  ir_variable *const r058D = body.make_temp(glsl_type::uint_type, "zFrac1");
                  ir_variable *const r058E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r058E);
                  ir_variable *const r058F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r058F);
                  ir_expression *const r0590 = equal(r0586, body.constant(0u));
                  ir_expression *const r0591 = add(r058B, body.constant(int(-32)));
                  body.emit(assign(r058B, expr(ir_triop_csel, r0590, r0591, r058B), 0x01));

                  ir_variable *const r0592 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0593 = equal(r0586, body.constant(0u));
                  ir_expression *const r0594 = sub(r01F8, r01F6);
                  body.emit(assign(r0592, expr(ir_triop_csel, r0593, body.constant(0u), r0594), 0x01));

                  body.emit(assign(r058D, r0592, 0x01));

                  ir_variable *const r0595 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0596 = equal(r0586, body.constant(0u));
                  body.emit(assign(r0595, expr(ir_triop_csel, r0596, r0592, r0586), 0x01));

                  body.emit(assign(r058C, r0595, 0x01));

                  ir_expression *const r0597 = equal(r0595, body.constant(0u));
                  ir_expression *const r0598 = expr(ir_unop_find_msb, r0595);
                  ir_expression *const r0599 = sub(body.constant(int(31)), r0598);
                  ir_expression *const r059A = expr(ir_triop_csel, r0597, body.constant(int(32)), r0599);
                  body.emit(assign(r058F, add(r059A, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r059C = gequal(r058F, body.constant(int(0)));
                  ir_if *f059B = new(mem_ctx) ir_if(operand(r059C).val);
                  exec_list *const f059B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f059B->then_instructions;

                     body.emit(assign(r058E, body.constant(0u), 0x01));

                     ir_expression *const r059D = equal(r058F, body.constant(int(0)));
                     ir_expression *const r059E = lshift(r0595, r058F);
                     ir_expression *const r059F = neg(r058F);
                     ir_expression *const r05A0 = bit_and(r059F, body.constant(int(31)));
                     ir_expression *const r05A1 = rshift(r0592, r05A0);
                     ir_expression *const r05A2 = bit_or(r059E, r05A1);
                     body.emit(assign(r058C, expr(ir_triop_csel, r059D, r0595, r05A2), 0x01));

                     body.emit(assign(r058D, lshift(r0592, r058F), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f059B->else_instructions;

                     ir_variable *const r05A3 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r05A3, body.constant(0u), 0x01));

                     ir_variable *const r05A4 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r05A4, neg(r058F), 0x01));

                     ir_variable *const r05A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r05A5);
                     ir_variable *const r05A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r05A6);
                     ir_variable *const r05A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r05A7);
                     ir_variable *const r05A8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r05A9 = neg(r05A4);
                     body.emit(assign(r05A8, bit_and(r05A9, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05AB = less(r05A4, body.constant(int(32)));
                     ir_if *f05AA = new(mem_ctx) ir_if(operand(r05AB).val);
                     exec_list *const f05AA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05AA->then_instructions;

                        body.emit(assign(r05A5, lshift(r058D, r05A8), 0x01));

                        ir_expression *const r05AC = lshift(r058C, r05A8);
                        ir_expression *const r05AD = rshift(r058D, r05A4);
                        body.emit(assign(r05A6, bit_or(r05AC, r05AD), 0x01));

                        body.emit(assign(r05A7, rshift(r058C, r05A4), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05AA->else_instructions;

                        body.emit(assign(r05A3, bit_or(body.constant(0u), r058D), 0x01));

                        ir_expression *const r05AE = less(r05A4, body.constant(int(64)));
                        ir_expression *const r05AF = lshift(r058C, r05A8);
                        ir_expression *const r05B0 = equal(r05A4, body.constant(int(64)));
                        ir_expression *const r05B1 = nequal(r058C, body.constant(0u));
                        ir_expression *const r05B2 = expr(ir_unop_b2i, r05B1);
                        ir_expression *const r05B3 = expr(ir_unop_i2u, r05B2);
                        ir_expression *const r05B4 = expr(ir_triop_csel, r05B0, r058C, r05B3);
                        body.emit(assign(r05A5, expr(ir_triop_csel, r05AE, r05AF, r05B4), 0x01));

                        ir_expression *const r05B5 = less(r05A4, body.constant(int(64)));
                        ir_expression *const r05B6 = bit_and(r05A4, body.constant(int(31)));
                        ir_expression *const r05B7 = rshift(r058C, r05B6);
                        body.emit(assign(r05A6, expr(ir_triop_csel, r05B5, r05B7, body.constant(0u)), 0x01));

                        body.emit(assign(r05A7, body.constant(0u), 0x01));


                     body.instructions = f05AA_parent_instructions;
                     body.emit(f05AA);

                     /* END IF */

                     ir_expression *const r05B8 = nequal(r05A3, body.constant(0u));
                     ir_expression *const r05B9 = expr(ir_unop_b2i, r05B8);
                     ir_expression *const r05BA = expr(ir_unop_i2u, r05B9);
                     body.emit(assign(r05A5, bit_or(r05A5, r05BA), 0x01));

                     ir_variable *const r05BB = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05BC = equal(r05A4, body.constant(int(0)));
                     ir_expression *const r05BD = equal(r05A4, body.constant(int(32)));
                     ir_expression *const r05BE = expr(ir_triop_csel, r05BD, body.constant(0u), r05A7);
                     body.emit(assign(r05BB, expr(ir_triop_csel, r05BC, r058C, r05BE), 0x01));

                     body.emit(assign(r05A7, r05BB, 0x01));

                     ir_variable *const r05BF = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05C0 = equal(r05A4, body.constant(int(0)));
                     ir_expression *const r05C1 = equal(r05A4, body.constant(int(32)));
                     ir_expression *const r05C2 = expr(ir_triop_csel, r05C1, r058C, r05A6);
                     body.emit(assign(r05BF, expr(ir_triop_csel, r05C0, r058D, r05C2), 0x01));

                     body.emit(assign(r05A6, r05BF, 0x01));

                     ir_variable *const r05C3 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05C4 = equal(r05A4, body.constant(int(0)));
                     ir_expression *const r05C5 = equal(r05A4, body.constant(int(32)));
                     ir_expression *const r05C6 = expr(ir_triop_csel, r05C5, r058D, r05A5);
                     body.emit(assign(r05C3, expr(ir_triop_csel, r05C4, r05A3, r05C6), 0x01));

                     body.emit(assign(r05A5, r05C3, 0x01));

                     body.emit(assign(r058C, r05BB, 0x01));

                     body.emit(assign(r058D, r05BF, 0x01));

                     body.emit(assign(r058E, r05C3, 0x01));


                  body.instructions = f059B_parent_instructions;
                  body.emit(f059B);

                  /* END IF */

                  body.emit(assign(r058B, sub(r058B, r058F), 0x01));

                  ir_variable *const r05C7 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r05C7, r058B, 0x01));

                  ir_variable *const r05C8 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r05C8, r058C, 0x01));

                  ir_variable *const r05C9 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r05C9, r058D, 0x01));

                  ir_variable *const r05CA = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r05CA, r058E, 0x01));

                  ir_variable *const r05CB = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r05CB, body.constant(true), 0x01));

                  ir_variable *const r05CC = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r05CD = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r05CD);
                  ir_expression *const r05CE = expr(ir_unop_u2i, r058E);
                  body.emit(assign(r05CD, less(r05CE, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r05D0 = gequal(r058B, body.constant(int(2045)));
                  ir_if *f05CF = new(mem_ctx) ir_if(operand(r05D0).val);
                  exec_list *const f05CF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05CF->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r05D2 = less(body.constant(int(2045)), r058B);
                     ir_expression *const r05D3 = equal(r058B, body.constant(int(2045)));
                     ir_expression *const r05D4 = equal(body.constant(2097151u), r058C);
                     ir_expression *const r05D5 = equal(body.constant(4294967295u), r058D);
                     ir_expression *const r05D6 = logic_and(r05D4, r05D5);
                     ir_expression *const r05D7 = logic_and(r05D3, r05D6);
                     ir_expression *const r05D8 = logic_and(r05D7, r05CD);
                     ir_expression *const r05D9 = logic_or(r05D2, r05D8);
                     ir_if *f05D1 = new(mem_ctx) ir_if(operand(r05D9).val);
                     exec_list *const f05D1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05D1->then_instructions;

                        ir_variable *const r05DA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r05DA);
                        ir_expression *const r05DB = lshift(r01F9, body.constant(int(31)));
                        body.emit(assign(r05DA, add(r05DB, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r05DA, body.constant(0u), 0x01));

                        body.emit(assign(r05CC, r05DA, 0x03));

                        body.emit(assign(r05CB, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05D1->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05DD = less(r058B, body.constant(int(0)));
                        ir_if *f05DC = new(mem_ctx) ir_if(operand(r05DD).val);
                        exec_list *const f05DC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05DC->then_instructions;

                           ir_variable *const r05DE = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r05DE, r058E, 0x01));

                           ir_variable *const r05DF = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r05DF, neg(r058B), 0x01));

                           ir_variable *const r05E0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r05E0);
                           ir_variable *const r05E1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r05E1);
                           ir_variable *const r05E2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r05E2);
                           ir_variable *const r05E3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r05E4 = neg(r05DF);
                           body.emit(assign(r05E3, bit_and(r05E4, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r05E6 = less(r05DF, body.constant(int(32)));
                           ir_if *f05E5 = new(mem_ctx) ir_if(operand(r05E6).val);
                           exec_list *const f05E5_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05E5->then_instructions;

                              body.emit(assign(r05E0, lshift(r058D, r05E3), 0x01));

                              ir_expression *const r05E7 = lshift(r058C, r05E3);
                              ir_expression *const r05E8 = rshift(r058D, r05DF);
                              body.emit(assign(r05E1, bit_or(r05E7, r05E8), 0x01));

                              body.emit(assign(r05E2, rshift(r058C, r05DF), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05E5->else_instructions;

                              body.emit(assign(r05DE, bit_or(r058E, r058D), 0x01));

                              ir_expression *const r05E9 = less(r05DF, body.constant(int(64)));
                              ir_expression *const r05EA = lshift(r058C, r05E3);
                              ir_expression *const r05EB = equal(r05DF, body.constant(int(64)));
                              ir_expression *const r05EC = nequal(r058C, body.constant(0u));
                              ir_expression *const r05ED = expr(ir_unop_b2i, r05EC);
                              ir_expression *const r05EE = expr(ir_unop_i2u, r05ED);
                              ir_expression *const r05EF = expr(ir_triop_csel, r05EB, r058C, r05EE);
                              body.emit(assign(r05E0, expr(ir_triop_csel, r05E9, r05EA, r05EF), 0x01));

                              ir_expression *const r05F0 = less(r05DF, body.constant(int(64)));
                              ir_expression *const r05F1 = bit_and(r05DF, body.constant(int(31)));
                              ir_expression *const r05F2 = rshift(r058C, r05F1);
                              body.emit(assign(r05E1, expr(ir_triop_csel, r05F0, r05F2, body.constant(0u)), 0x01));

                              body.emit(assign(r05E2, body.constant(0u), 0x01));


                           body.instructions = f05E5_parent_instructions;
                           body.emit(f05E5);

                           /* END IF */

                           ir_expression *const r05F3 = nequal(r05DE, body.constant(0u));
                           ir_expression *const r05F4 = expr(ir_unop_b2i, r05F3);
                           ir_expression *const r05F5 = expr(ir_unop_i2u, r05F4);
                           body.emit(assign(r05E0, bit_or(r05E0, r05F5), 0x01));

                           ir_variable *const r05F6 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r05F7 = equal(r05DF, body.constant(int(0)));
                           ir_expression *const r05F8 = equal(r05DF, body.constant(int(32)));
                           ir_expression *const r05F9 = expr(ir_triop_csel, r05F8, body.constant(0u), r05E2);
                           body.emit(assign(r05F6, expr(ir_triop_csel, r05F7, r058C, r05F9), 0x01));

                           body.emit(assign(r05E2, r05F6, 0x01));

                           ir_variable *const r05FA = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r05FB = equal(r05DF, body.constant(int(0)));
                           ir_expression *const r05FC = equal(r05DF, body.constant(int(32)));
                           ir_expression *const r05FD = expr(ir_triop_csel, r05FC, r058C, r05E1);
                           body.emit(assign(r05FA, expr(ir_triop_csel, r05FB, r058D, r05FD), 0x01));

                           body.emit(assign(r05E1, r05FA, 0x01));

                           ir_variable *const r05FE = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r05FF = equal(r05DF, body.constant(int(0)));
                           ir_expression *const r0600 = equal(r05DF, body.constant(int(32)));
                           ir_expression *const r0601 = expr(ir_triop_csel, r0600, r058D, r05E0);
                           body.emit(assign(r05FE, expr(ir_triop_csel, r05FF, r05DE, r0601), 0x01));

                           body.emit(assign(r05E0, r05FE, 0x01));

                           body.emit(assign(r05C8, r05F6, 0x01));

                           body.emit(assign(r05C9, r05FA, 0x01));

                           body.emit(assign(r05CA, r05FE, 0x01));

                           body.emit(assign(r05C7, body.constant(int(0)), 0x01));

                           body.emit(assign(r05CD, less(r05FE, body.constant(0u)), 0x01));


                        body.instructions = f05DC_parent_instructions;
                        body.emit(f05DC);

                        /* END IF */


                     body.instructions = f05D1_parent_instructions;
                     body.emit(f05D1);

                     /* END IF */


                  body.instructions = f05CF_parent_instructions;
                  body.emit(f05CF);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0602 = new(mem_ctx) ir_if(operand(r05CB).val);
                  exec_list *const f0602_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0602->then_instructions;

                     /* IF CONDITION */
                     ir_if *f0603 = new(mem_ctx) ir_if(operand(r05CD).val);
                     exec_list *const f0603_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0603->then_instructions;

                        ir_variable *const r0604 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r0604, add(r05C9, body.constant(1u)), 0x01));

                        ir_expression *const r0605 = less(r0604, r05C9);
                        ir_expression *const r0606 = expr(ir_unop_b2i, r0605);
                        ir_expression *const r0607 = expr(ir_unop_i2u, r0606);
                        body.emit(assign(r05C8, add(r05C8, r0607), 0x01));

                        ir_expression *const r0608 = equal(r05CA, body.constant(0u));
                        ir_expression *const r0609 = expr(ir_unop_b2i, r0608);
                        ir_expression *const r060A = expr(ir_unop_i2u, r0609);
                        ir_expression *const r060B = add(r05CA, r060A);
                        ir_expression *const r060C = bit_and(r060B, body.constant(1u));
                        ir_expression *const r060D = expr(ir_unop_bit_not, r060C);
                        body.emit(assign(r05C9, bit_and(r0604, r060D), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0603->else_instructions;

                        ir_expression *const r060E = bit_or(r05C8, r05C9);
                        ir_expression *const r060F = equal(r060E, body.constant(0u));
                        body.emit(assign(r05C7, expr(ir_triop_csel, r060F, body.constant(int(0)), r05C7), 0x01));


                     body.instructions = f0603_parent_instructions;
                     body.emit(f0603);

                     /* END IF */

                     ir_variable *const r0610 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0610);
                     ir_expression *const r0611 = lshift(r01F9, body.constant(int(31)));
                     ir_expression *const r0612 = expr(ir_unop_i2u, r05C7);
                     ir_expression *const r0613 = lshift(r0612, body.constant(int(20)));
                     ir_expression *const r0614 = add(r0611, r0613);
                     body.emit(assign(r0610, add(r0614, r05C8), 0x02));

                     body.emit(assign(r0610, r05C9, 0x01));

                     body.emit(assign(r05CC, r0610, 0x03));

                     body.emit(assign(r05CB, body.constant(false), 0x01));


                  body.instructions = f0602_parent_instructions;
                  body.emit(f0602);

                  /* END IF */

                  body.emit(assign(r01F0, r05CC, 0x03));

                  body.emit(assign(r01EF, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0584->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0616 = less(r01F7, r01F5);
                  ir_if *f0615 = new(mem_ctx) ir_if(operand(r0616).val);
                  exec_list *const f0615_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0615->then_instructions;

                     ir_variable *const r0617 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_expression *const r0618 = sub(r01F5, r01F7);
                     ir_expression *const r0619 = less(r01F6, r01F8);
                     ir_expression *const r061A = expr(ir_unop_b2i, r0619);
                     ir_expression *const r061B = expr(ir_unop_i2u, r061A);
                     body.emit(assign(r0617, sub(r0618, r061B), 0x01));

                     body.emit(assign(r01F2, r0617, 0x01));

                     body.emit(assign(r01F9, bit_xor(r01F9, body.constant(1u)), 0x01));

                     body.emit(assign(r03B3, add(r01F3, body.constant(int(-1))), 0x01));

                     ir_variable *const r061C = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r061C, add(r03B3, body.constant(int(-10))), 0x01));

                     ir_variable *const r061D = body.make_temp(glsl_type::uint_type, "zFrac0");
                     ir_variable *const r061E = body.make_temp(glsl_type::uint_type, "zFrac1");
                     ir_variable *const r061F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r061F);
                     ir_variable *const r0620 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0620);
                     ir_expression *const r0621 = equal(r0617, body.constant(0u));
                     ir_expression *const r0622 = add(r061C, body.constant(int(-32)));
                     body.emit(assign(r061C, expr(ir_triop_csel, r0621, r0622, r061C), 0x01));

                     ir_variable *const r0623 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0624 = equal(r0617, body.constant(0u));
                     ir_expression *const r0625 = sub(r01F6, r01F8);
                     body.emit(assign(r0623, expr(ir_triop_csel, r0624, body.constant(0u), r0625), 0x01));

                     body.emit(assign(r061E, r0623, 0x01));

                     ir_variable *const r0626 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r0627 = equal(r0617, body.constant(0u));
                     body.emit(assign(r0626, expr(ir_triop_csel, r0627, r0623, r0617), 0x01));

                     body.emit(assign(r061D, r0626, 0x01));

                     ir_expression *const r0628 = equal(r0626, body.constant(0u));
                     ir_expression *const r0629 = expr(ir_unop_find_msb, r0626);
                     ir_expression *const r062A = sub(body.constant(int(31)), r0629);
                     ir_expression *const r062B = expr(ir_triop_csel, r0628, body.constant(int(32)), r062A);
                     body.emit(assign(r0620, add(r062B, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r062D = gequal(r0620, body.constant(int(0)));
                     ir_if *f062C = new(mem_ctx) ir_if(operand(r062D).val);
                     exec_list *const f062C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f062C->then_instructions;

                        body.emit(assign(r061F, body.constant(0u), 0x01));

                        ir_expression *const r062E = equal(r0620, body.constant(int(0)));
                        ir_expression *const r062F = lshift(r0626, r0620);
                        ir_expression *const r0630 = neg(r0620);
                        ir_expression *const r0631 = bit_and(r0630, body.constant(int(31)));
                        ir_expression *const r0632 = rshift(r0623, r0631);
                        ir_expression *const r0633 = bit_or(r062F, r0632);
                        body.emit(assign(r061D, expr(ir_triop_csel, r062E, r0626, r0633), 0x01));

                        body.emit(assign(r061E, lshift(r0623, r0620), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f062C->else_instructions;

                        ir_variable *const r0634 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0634, body.constant(0u), 0x01));

                        ir_variable *const r0635 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0635, neg(r0620), 0x01));

                        ir_variable *const r0636 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0636);
                        ir_variable *const r0637 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r0637);
                        ir_variable *const r0638 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0638);
                        ir_variable *const r0639 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r063A = neg(r0635);
                        body.emit(assign(r0639, bit_and(r063A, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r063C = less(r0635, body.constant(int(32)));
                        ir_if *f063B = new(mem_ctx) ir_if(operand(r063C).val);
                        exec_list *const f063B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f063B->then_instructions;

                           body.emit(assign(r0636, lshift(r061E, r0639), 0x01));

                           ir_expression *const r063D = lshift(r061D, r0639);
                           ir_expression *const r063E = rshift(r061E, r0635);
                           body.emit(assign(r0637, bit_or(r063D, r063E), 0x01));

                           body.emit(assign(r0638, rshift(r061D, r0635), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f063B->else_instructions;

                           body.emit(assign(r0634, bit_or(body.constant(0u), r061E), 0x01));

                           ir_expression *const r063F = less(r0635, body.constant(int(64)));
                           ir_expression *const r0640 = lshift(r061D, r0639);
                           ir_expression *const r0641 = equal(r0635, body.constant(int(64)));
                           ir_expression *const r0642 = nequal(r061D, body.constant(0u));
                           ir_expression *const r0643 = expr(ir_unop_b2i, r0642);
                           ir_expression *const r0644 = expr(ir_unop_i2u, r0643);
                           ir_expression *const r0645 = expr(ir_triop_csel, r0641, r061D, r0644);
                           body.emit(assign(r0636, expr(ir_triop_csel, r063F, r0640, r0645), 0x01));

                           ir_expression *const r0646 = less(r0635, body.constant(int(64)));
                           ir_expression *const r0647 = bit_and(r0635, body.constant(int(31)));
                           ir_expression *const r0648 = rshift(r061D, r0647);
                           body.emit(assign(r0637, expr(ir_triop_csel, r0646, r0648, body.constant(0u)), 0x01));

                           body.emit(assign(r0638, body.constant(0u), 0x01));


                        body.instructions = f063B_parent_instructions;
                        body.emit(f063B);

                        /* END IF */

                        ir_expression *const r0649 = nequal(r0634, body.constant(0u));
                        ir_expression *const r064A = expr(ir_unop_b2i, r0649);
                        ir_expression *const r064B = expr(ir_unop_i2u, r064A);
                        body.emit(assign(r0636, bit_or(r0636, r064B), 0x01));

                        ir_variable *const r064C = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r064D = equal(r0635, body.constant(int(0)));
                        ir_expression *const r064E = equal(r0635, body.constant(int(32)));
                        ir_expression *const r064F = expr(ir_triop_csel, r064E, body.constant(0u), r0638);
                        body.emit(assign(r064C, expr(ir_triop_csel, r064D, r061D, r064F), 0x01));

                        body.emit(assign(r0638, r064C, 0x01));

                        ir_variable *const r0650 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0651 = equal(r0635, body.constant(int(0)));
                        ir_expression *const r0652 = equal(r0635, body.constant(int(32)));
                        ir_expression *const r0653 = expr(ir_triop_csel, r0652, r061D, r0637);
                        body.emit(assign(r0650, expr(ir_triop_csel, r0651, r061E, r0653), 0x01));

                        body.emit(assign(r0637, r0650, 0x01));

                        ir_variable *const r0654 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0655 = equal(r0635, body.constant(int(0)));
                        ir_expression *const r0656 = equal(r0635, body.constant(int(32)));
                        ir_expression *const r0657 = expr(ir_triop_csel, r0656, r061E, r0636);
                        body.emit(assign(r0654, expr(ir_triop_csel, r0655, r0634, r0657), 0x01));

                        body.emit(assign(r0636, r0654, 0x01));

                        body.emit(assign(r061D, r064C, 0x01));

                        body.emit(assign(r061E, r0650, 0x01));

                        body.emit(assign(r061F, r0654, 0x01));


                     body.instructions = f062C_parent_instructions;
                     body.emit(f062C);

                     /* END IF */

                     body.emit(assign(r061C, sub(r061C, r0620), 0x01));

                     ir_variable *const r0658 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r0658, r061C, 0x01));

                     ir_variable *const r0659 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0659, r061D, 0x01));

                     ir_variable *const r065A = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r065A, r061E, 0x01));

                     ir_variable *const r065B = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r065B, r061F, 0x01));

                     ir_variable *const r065C = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r065C, body.constant(true), 0x01));

                     ir_variable *const r065D = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r065E = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r065E);
                     ir_expression *const r065F = expr(ir_unop_u2i, r061F);
                     body.emit(assign(r065E, less(r065F, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0661 = gequal(r061C, body.constant(int(2045)));
                     ir_if *f0660 = new(mem_ctx) ir_if(operand(r0661).val);
                     exec_list *const f0660_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0660->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0663 = less(body.constant(int(2045)), r061C);
                        ir_expression *const r0664 = equal(r061C, body.constant(int(2045)));
                        ir_expression *const r0665 = equal(body.constant(2097151u), r061D);
                        ir_expression *const r0666 = equal(body.constant(4294967295u), r061E);
                        ir_expression *const r0667 = logic_and(r0665, r0666);
                        ir_expression *const r0668 = logic_and(r0664, r0667);
                        ir_expression *const r0669 = logic_and(r0668, r065E);
                        ir_expression *const r066A = logic_or(r0663, r0669);
                        ir_if *f0662 = new(mem_ctx) ir_if(operand(r066A).val);
                        exec_list *const f0662_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0662->then_instructions;

                           ir_variable *const r066B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r066B);
                           ir_expression *const r066C = lshift(r01F9, body.constant(int(31)));
                           body.emit(assign(r066B, add(r066C, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r066B, body.constant(0u), 0x01));

                           body.emit(assign(r065D, r066B, 0x03));

                           body.emit(assign(r065C, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0662->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r066E = less(r061C, body.constant(int(0)));
                           ir_if *f066D = new(mem_ctx) ir_if(operand(r066E).val);
                           exec_list *const f066D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f066D->then_instructions;

                              ir_variable *const r066F = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r066F, r061F, 0x01));

                              ir_variable *const r0670 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0670, neg(r061C), 0x01));

                              ir_variable *const r0671 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0671);
                              ir_variable *const r0672 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0672);
                              ir_variable *const r0673 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0673);
                              ir_variable *const r0674 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0675 = neg(r0670);
                              body.emit(assign(r0674, bit_and(r0675, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0677 = less(r0670, body.constant(int(32)));
                              ir_if *f0676 = new(mem_ctx) ir_if(operand(r0677).val);
                              exec_list *const f0676_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0676->then_instructions;

                                 body.emit(assign(r0671, lshift(r061E, r0674), 0x01));

                                 ir_expression *const r0678 = lshift(r061D, r0674);
                                 ir_expression *const r0679 = rshift(r061E, r0670);
                                 body.emit(assign(r0672, bit_or(r0678, r0679), 0x01));

                                 body.emit(assign(r0673, rshift(r061D, r0670), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0676->else_instructions;

                                 body.emit(assign(r066F, bit_or(r061F, r061E), 0x01));

                                 ir_expression *const r067A = less(r0670, body.constant(int(64)));
                                 ir_expression *const r067B = lshift(r061D, r0674);
                                 ir_expression *const r067C = equal(r0670, body.constant(int(64)));
                                 ir_expression *const r067D = nequal(r061D, body.constant(0u));
                                 ir_expression *const r067E = expr(ir_unop_b2i, r067D);
                                 ir_expression *const r067F = expr(ir_unop_i2u, r067E);
                                 ir_expression *const r0680 = expr(ir_triop_csel, r067C, r061D, r067F);
                                 body.emit(assign(r0671, expr(ir_triop_csel, r067A, r067B, r0680), 0x01));

                                 ir_expression *const r0681 = less(r0670, body.constant(int(64)));
                                 ir_expression *const r0682 = bit_and(r0670, body.constant(int(31)));
                                 ir_expression *const r0683 = rshift(r061D, r0682);
                                 body.emit(assign(r0672, expr(ir_triop_csel, r0681, r0683, body.constant(0u)), 0x01));

                                 body.emit(assign(r0673, body.constant(0u), 0x01));


                              body.instructions = f0676_parent_instructions;
                              body.emit(f0676);

                              /* END IF */

                              ir_expression *const r0684 = nequal(r066F, body.constant(0u));
                              ir_expression *const r0685 = expr(ir_unop_b2i, r0684);
                              ir_expression *const r0686 = expr(ir_unop_i2u, r0685);
                              body.emit(assign(r0671, bit_or(r0671, r0686), 0x01));

                              ir_variable *const r0687 = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r0688 = equal(r0670, body.constant(int(0)));
                              ir_expression *const r0689 = equal(r0670, body.constant(int(32)));
                              ir_expression *const r068A = expr(ir_triop_csel, r0689, body.constant(0u), r0673);
                              body.emit(assign(r0687, expr(ir_triop_csel, r0688, r061D, r068A), 0x01));

                              body.emit(assign(r0673, r0687, 0x01));

                              ir_variable *const r068B = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r068C = equal(r0670, body.constant(int(0)));
                              ir_expression *const r068D = equal(r0670, body.constant(int(32)));
                              ir_expression *const r068E = expr(ir_triop_csel, r068D, r061D, r0672);
                              body.emit(assign(r068B, expr(ir_triop_csel, r068C, r061E, r068E), 0x01));

                              body.emit(assign(r0672, r068B, 0x01));

                              ir_variable *const r068F = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r0690 = equal(r0670, body.constant(int(0)));
                              ir_expression *const r0691 = equal(r0670, body.constant(int(32)));
                              ir_expression *const r0692 = expr(ir_triop_csel, r0691, r061E, r0671);
                              body.emit(assign(r068F, expr(ir_triop_csel, r0690, r066F, r0692), 0x01));

                              body.emit(assign(r0671, r068F, 0x01));

                              body.emit(assign(r0659, r0687, 0x01));

                              body.emit(assign(r065A, r068B, 0x01));

                              body.emit(assign(r065B, r068F, 0x01));

                              body.emit(assign(r0658, body.constant(int(0)), 0x01));

                              body.emit(assign(r065E, less(r068F, body.constant(0u)), 0x01));


                           body.instructions = f066D_parent_instructions;
                           body.emit(f066D);

                           /* END IF */


                        body.instructions = f0662_parent_instructions;
                        body.emit(f0662);

                        /* END IF */


                     body.instructions = f0660_parent_instructions;
                     body.emit(f0660);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0693 = new(mem_ctx) ir_if(operand(r065C).val);
                     exec_list *const f0693_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0693->then_instructions;

                        /* IF CONDITION */
                        ir_if *f0694 = new(mem_ctx) ir_if(operand(r065E).val);
                        exec_list *const f0694_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0694->then_instructions;

                           ir_variable *const r0695 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r0695, add(r065A, body.constant(1u)), 0x01));

                           ir_expression *const r0696 = less(r0695, r065A);
                           ir_expression *const r0697 = expr(ir_unop_b2i, r0696);
                           ir_expression *const r0698 = expr(ir_unop_i2u, r0697);
                           body.emit(assign(r0659, add(r0659, r0698), 0x01));

                           ir_expression *const r0699 = equal(r065B, body.constant(0u));
                           ir_expression *const r069A = expr(ir_unop_b2i, r0699);
                           ir_expression *const r069B = expr(ir_unop_i2u, r069A);
                           ir_expression *const r069C = add(r065B, r069B);
                           ir_expression *const r069D = bit_and(r069C, body.constant(1u));
                           ir_expression *const r069E = expr(ir_unop_bit_not, r069D);
                           body.emit(assign(r065A, bit_and(r0695, r069E), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0694->else_instructions;

                           ir_expression *const r069F = bit_or(r0659, r065A);
                           ir_expression *const r06A0 = equal(r069F, body.constant(0u));
                           body.emit(assign(r0658, expr(ir_triop_csel, r06A0, body.constant(int(0)), r0658), 0x01));


                        body.instructions = f0694_parent_instructions;
                        body.emit(f0694);

                        /* END IF */

                        ir_variable *const r06A1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r06A1);
                        ir_expression *const r06A2 = lshift(r01F9, body.constant(int(31)));
                        ir_expression *const r06A3 = expr(ir_unop_i2u, r0658);
                        ir_expression *const r06A4 = lshift(r06A3, body.constant(int(20)));
                        ir_expression *const r06A5 = add(r06A2, r06A4);
                        body.emit(assign(r06A1, add(r06A5, r0659), 0x02));

                        body.emit(assign(r06A1, r065A, 0x01));

                        body.emit(assign(r065D, r06A1, 0x03));

                        body.emit(assign(r065C, body.constant(false), 0x01));


                     body.instructions = f0693_parent_instructions;
                     body.emit(f0693);

                     /* END IF */

                     body.emit(assign(r01F0, r065D, 0x03));

                     body.emit(assign(r01EF, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0615->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r06A7 = less(r01F6, r01F8);
                     ir_if *f06A6 = new(mem_ctx) ir_if(operand(r06A7).val);
                     exec_list *const f06A6_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f06A6->then_instructions;

                        ir_variable *const r06A8 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_expression *const r06A9 = sub(r01F7, r01F5);
                        ir_expression *const r06AA = less(r01F8, r01F6);
                        ir_expression *const r06AB = expr(ir_unop_b2i, r06AA);
                        ir_expression *const r06AC = expr(ir_unop_i2u, r06AB);
                        body.emit(assign(r06A8, sub(r06A9, r06AC), 0x01));

                        body.emit(assign(r01F2, r06A8, 0x01));

                        body.emit(assign(r03B3, add(r01F4, body.constant(int(-1))), 0x01));

                        ir_variable *const r06AD = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r06AD, add(r03B3, body.constant(int(-10))), 0x01));

                        ir_variable *const r06AE = body.make_temp(glsl_type::uint_type, "zFrac0");
                        ir_variable *const r06AF = body.make_temp(glsl_type::uint_type, "zFrac1");
                        ir_variable *const r06B0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r06B0);
                        ir_variable *const r06B1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r06B1);
                        ir_expression *const r06B2 = equal(r06A8, body.constant(0u));
                        ir_expression *const r06B3 = add(r06AD, body.constant(int(-32)));
                        body.emit(assign(r06AD, expr(ir_triop_csel, r06B2, r06B3, r06AD), 0x01));

                        ir_variable *const r06B4 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r06B5 = equal(r06A8, body.constant(0u));
                        ir_expression *const r06B6 = sub(r01F8, r01F6);
                        body.emit(assign(r06B4, expr(ir_triop_csel, r06B5, body.constant(0u), r06B6), 0x01));

                        body.emit(assign(r06AF, r06B4, 0x01));

                        ir_variable *const r06B7 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r06B8 = equal(r06A8, body.constant(0u));
                        body.emit(assign(r06B7, expr(ir_triop_csel, r06B8, r06B4, r06A8), 0x01));

                        body.emit(assign(r06AE, r06B7, 0x01));

                        ir_expression *const r06B9 = equal(r06B7, body.constant(0u));
                        ir_expression *const r06BA = expr(ir_unop_find_msb, r06B7);
                        ir_expression *const r06BB = sub(body.constant(int(31)), r06BA);
                        ir_expression *const r06BC = expr(ir_triop_csel, r06B9, body.constant(int(32)), r06BB);
                        body.emit(assign(r06B1, add(r06BC, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r06BE = gequal(r06B1, body.constant(int(0)));
                        ir_if *f06BD = new(mem_ctx) ir_if(operand(r06BE).val);
                        exec_list *const f06BD_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06BD->then_instructions;

                           body.emit(assign(r06B0, body.constant(0u), 0x01));

                           ir_expression *const r06BF = equal(r06B1, body.constant(int(0)));
                           ir_expression *const r06C0 = lshift(r06B7, r06B1);
                           ir_expression *const r06C1 = neg(r06B1);
                           ir_expression *const r06C2 = bit_and(r06C1, body.constant(int(31)));
                           ir_expression *const r06C3 = rshift(r06B4, r06C2);
                           ir_expression *const r06C4 = bit_or(r06C0, r06C3);
                           body.emit(assign(r06AE, expr(ir_triop_csel, r06BF, r06B7, r06C4), 0x01));

                           body.emit(assign(r06AF, lshift(r06B4, r06B1), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06BD->else_instructions;

                           ir_variable *const r06C5 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r06C5, body.constant(0u), 0x01));

                           ir_variable *const r06C6 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r06C6, neg(r06B1), 0x01));

                           ir_variable *const r06C7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r06C7);
                           ir_variable *const r06C8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r06C8);
                           ir_variable *const r06C9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r06C9);
                           ir_variable *const r06CA = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r06CB = neg(r06C6);
                           body.emit(assign(r06CA, bit_and(r06CB, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06CD = less(r06C6, body.constant(int(32)));
                           ir_if *f06CC = new(mem_ctx) ir_if(operand(r06CD).val);
                           exec_list *const f06CC_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06CC->then_instructions;

                              body.emit(assign(r06C7, lshift(r06AF, r06CA), 0x01));

                              ir_expression *const r06CE = lshift(r06AE, r06CA);
                              ir_expression *const r06CF = rshift(r06AF, r06C6);
                              body.emit(assign(r06C8, bit_or(r06CE, r06CF), 0x01));

                              body.emit(assign(r06C9, rshift(r06AE, r06C6), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06CC->else_instructions;

                              body.emit(assign(r06C5, bit_or(body.constant(0u), r06AF), 0x01));

                              ir_expression *const r06D0 = less(r06C6, body.constant(int(64)));
                              ir_expression *const r06D1 = lshift(r06AE, r06CA);
                              ir_expression *const r06D2 = equal(r06C6, body.constant(int(64)));
                              ir_expression *const r06D3 = nequal(r06AE, body.constant(0u));
                              ir_expression *const r06D4 = expr(ir_unop_b2i, r06D3);
                              ir_expression *const r06D5 = expr(ir_unop_i2u, r06D4);
                              ir_expression *const r06D6 = expr(ir_triop_csel, r06D2, r06AE, r06D5);
                              body.emit(assign(r06C7, expr(ir_triop_csel, r06D0, r06D1, r06D6), 0x01));

                              ir_expression *const r06D7 = less(r06C6, body.constant(int(64)));
                              ir_expression *const r06D8 = bit_and(r06C6, body.constant(int(31)));
                              ir_expression *const r06D9 = rshift(r06AE, r06D8);
                              body.emit(assign(r06C8, expr(ir_triop_csel, r06D7, r06D9, body.constant(0u)), 0x01));

                              body.emit(assign(r06C9, body.constant(0u), 0x01));


                           body.instructions = f06CC_parent_instructions;
                           body.emit(f06CC);

                           /* END IF */

                           ir_expression *const r06DA = nequal(r06C5, body.constant(0u));
                           ir_expression *const r06DB = expr(ir_unop_b2i, r06DA);
                           ir_expression *const r06DC = expr(ir_unop_i2u, r06DB);
                           body.emit(assign(r06C7, bit_or(r06C7, r06DC), 0x01));

                           ir_variable *const r06DD = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06DE = equal(r06C6, body.constant(int(0)));
                           ir_expression *const r06DF = equal(r06C6, body.constant(int(32)));
                           ir_expression *const r06E0 = expr(ir_triop_csel, r06DF, body.constant(0u), r06C9);
                           body.emit(assign(r06DD, expr(ir_triop_csel, r06DE, r06AE, r06E0), 0x01));

                           body.emit(assign(r06C9, r06DD, 0x01));

                           ir_variable *const r06E1 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06E2 = equal(r06C6, body.constant(int(0)));
                           ir_expression *const r06E3 = equal(r06C6, body.constant(int(32)));
                           ir_expression *const r06E4 = expr(ir_triop_csel, r06E3, r06AE, r06C8);
                           body.emit(assign(r06E1, expr(ir_triop_csel, r06E2, r06AF, r06E4), 0x01));

                           body.emit(assign(r06C8, r06E1, 0x01));

                           ir_variable *const r06E5 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06E6 = equal(r06C6, body.constant(int(0)));
                           ir_expression *const r06E7 = equal(r06C6, body.constant(int(32)));
                           ir_expression *const r06E8 = expr(ir_triop_csel, r06E7, r06AF, r06C7);
                           body.emit(assign(r06E5, expr(ir_triop_csel, r06E6, r06C5, r06E8), 0x01));

                           body.emit(assign(r06C7, r06E5, 0x01));

                           body.emit(assign(r06AE, r06DD, 0x01));

                           body.emit(assign(r06AF, r06E1, 0x01));

                           body.emit(assign(r06B0, r06E5, 0x01));


                        body.instructions = f06BD_parent_instructions;
                        body.emit(f06BD);

                        /* END IF */

                        body.emit(assign(r06AD, sub(r06AD, r06B1), 0x01));

                        ir_variable *const r06E9 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r06E9, r06AD, 0x01));

                        ir_variable *const r06EA = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r06EA, r06AE, 0x01));

                        ir_variable *const r06EB = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r06EB, r06AF, 0x01));

                        ir_variable *const r06EC = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r06EC, r06B0, 0x01));

                        ir_variable *const r06ED = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r06ED, body.constant(true), 0x01));

                        ir_variable *const r06EE = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r06EF = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r06EF);
                        ir_expression *const r06F0 = expr(ir_unop_u2i, r06B0);
                        body.emit(assign(r06EF, less(r06F0, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r06F2 = gequal(r06AD, body.constant(int(2045)));
                        ir_if *f06F1 = new(mem_ctx) ir_if(operand(r06F2).val);
                        exec_list *const f06F1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06F1->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r06F4 = less(body.constant(int(2045)), r06AD);
                           ir_expression *const r06F5 = equal(r06AD, body.constant(int(2045)));
                           ir_expression *const r06F6 = equal(body.constant(2097151u), r06AE);
                           ir_expression *const r06F7 = equal(body.constant(4294967295u), r06AF);
                           ir_expression *const r06F8 = logic_and(r06F6, r06F7);
                           ir_expression *const r06F9 = logic_and(r06F5, r06F8);
                           ir_expression *const r06FA = logic_and(r06F9, r06EF);
                           ir_expression *const r06FB = logic_or(r06F4, r06FA);
                           ir_if *f06F3 = new(mem_ctx) ir_if(operand(r06FB).val);
                           exec_list *const f06F3_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06F3->then_instructions;

                              ir_variable *const r06FC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r06FC);
                              ir_expression *const r06FD = lshift(r01F9, body.constant(int(31)));
                              body.emit(assign(r06FC, add(r06FD, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r06FC, body.constant(0u), 0x01));

                              body.emit(assign(r06EE, r06FC, 0x03));

                              body.emit(assign(r06ED, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06F3->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06FF = less(r06AD, body.constant(int(0)));
                              ir_if *f06FE = new(mem_ctx) ir_if(operand(r06FF).val);
                              exec_list *const f06FE_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06FE->then_instructions;

                                 ir_variable *const r0700 = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r0700, r06B0, 0x01));

                                 ir_variable *const r0701 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r0701, neg(r06AD), 0x01));

                                 ir_variable *const r0702 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r0702);
                                 ir_variable *const r0703 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r0703);
                                 ir_variable *const r0704 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r0704);
                                 ir_variable *const r0705 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r0706 = neg(r0701);
                                 body.emit(assign(r0705, bit_and(r0706, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0708 = less(r0701, body.constant(int(32)));
                                 ir_if *f0707 = new(mem_ctx) ir_if(operand(r0708).val);
                                 exec_list *const f0707_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0707->then_instructions;

                                    body.emit(assign(r0702, lshift(r06AF, r0705), 0x01));

                                    ir_expression *const r0709 = lshift(r06AE, r0705);
                                    ir_expression *const r070A = rshift(r06AF, r0701);
                                    body.emit(assign(r0703, bit_or(r0709, r070A), 0x01));

                                    body.emit(assign(r0704, rshift(r06AE, r0701), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0707->else_instructions;

                                    body.emit(assign(r0700, bit_or(r06B0, r06AF), 0x01));

                                    ir_expression *const r070B = less(r0701, body.constant(int(64)));
                                    ir_expression *const r070C = lshift(r06AE, r0705);
                                    ir_expression *const r070D = equal(r0701, body.constant(int(64)));
                                    ir_expression *const r070E = nequal(r06AE, body.constant(0u));
                                    ir_expression *const r070F = expr(ir_unop_b2i, r070E);
                                    ir_expression *const r0710 = expr(ir_unop_i2u, r070F);
                                    ir_expression *const r0711 = expr(ir_triop_csel, r070D, r06AE, r0710);
                                    body.emit(assign(r0702, expr(ir_triop_csel, r070B, r070C, r0711), 0x01));

                                    ir_expression *const r0712 = less(r0701, body.constant(int(64)));
                                    ir_expression *const r0713 = bit_and(r0701, body.constant(int(31)));
                                    ir_expression *const r0714 = rshift(r06AE, r0713);
                                    body.emit(assign(r0703, expr(ir_triop_csel, r0712, r0714, body.constant(0u)), 0x01));

                                    body.emit(assign(r0704, body.constant(0u), 0x01));


                                 body.instructions = f0707_parent_instructions;
                                 body.emit(f0707);

                                 /* END IF */

                                 ir_expression *const r0715 = nequal(r0700, body.constant(0u));
                                 ir_expression *const r0716 = expr(ir_unop_b2i, r0715);
                                 ir_expression *const r0717 = expr(ir_unop_i2u, r0716);
                                 body.emit(assign(r0702, bit_or(r0702, r0717), 0x01));

                                 ir_variable *const r0718 = body.make_temp(glsl_type::uint_type, "mix_retval");
                                 ir_expression *const r0719 = equal(r0701, body.constant(int(0)));
                                 ir_expression *const r071A = equal(r0701, body.constant(int(32)));
                                 ir_expression *const r071B = expr(ir_triop_csel, r071A, body.constant(0u), r0704);
                                 body.emit(assign(r0718, expr(ir_triop_csel, r0719, r06AE, r071B), 0x01));

                                 body.emit(assign(r0704, r0718, 0x01));

                                 ir_variable *const r071C = body.make_temp(glsl_type::uint_type, "mix_retval");
                                 ir_expression *const r071D = equal(r0701, body.constant(int(0)));
                                 ir_expression *const r071E = equal(r0701, body.constant(int(32)));
                                 ir_expression *const r071F = expr(ir_triop_csel, r071E, r06AE, r0703);
                                 body.emit(assign(r071C, expr(ir_triop_csel, r071D, r06AF, r071F), 0x01));

                                 body.emit(assign(r0703, r071C, 0x01));

                                 ir_variable *const r0720 = body.make_temp(glsl_type::uint_type, "mix_retval");
                                 ir_expression *const r0721 = equal(r0701, body.constant(int(0)));
                                 ir_expression *const r0722 = equal(r0701, body.constant(int(32)));
                                 ir_expression *const r0723 = expr(ir_triop_csel, r0722, r06AF, r0702);
                                 body.emit(assign(r0720, expr(ir_triop_csel, r0721, r0700, r0723), 0x01));

                                 body.emit(assign(r0702, r0720, 0x01));

                                 body.emit(assign(r06EA, r0718, 0x01));

                                 body.emit(assign(r06EB, r071C, 0x01));

                                 body.emit(assign(r06EC, r0720, 0x01));

                                 body.emit(assign(r06E9, body.constant(int(0)), 0x01));

                                 body.emit(assign(r06EF, less(r0720, body.constant(0u)), 0x01));


                              body.instructions = f06FE_parent_instructions;
                              body.emit(f06FE);

                              /* END IF */


                           body.instructions = f06F3_parent_instructions;
                           body.emit(f06F3);

                           /* END IF */


                        body.instructions = f06F1_parent_instructions;
                        body.emit(f06F1);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f0724 = new(mem_ctx) ir_if(operand(r06ED).val);
                        exec_list *const f0724_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0724->then_instructions;

                           /* IF CONDITION */
                           ir_if *f0725 = new(mem_ctx) ir_if(operand(r06EF).val);
                           exec_list *const f0725_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0725->then_instructions;

                              ir_variable *const r0726 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r0726, add(r06EB, body.constant(1u)), 0x01));

                              ir_expression *const r0727 = less(r0726, r06EB);
                              ir_expression *const r0728 = expr(ir_unop_b2i, r0727);
                              ir_expression *const r0729 = expr(ir_unop_i2u, r0728);
                              body.emit(assign(r06EA, add(r06EA, r0729), 0x01));

                              ir_expression *const r072A = equal(r06EC, body.constant(0u));
                              ir_expression *const r072B = expr(ir_unop_b2i, r072A);
                              ir_expression *const r072C = expr(ir_unop_i2u, r072B);
                              ir_expression *const r072D = add(r06EC, r072C);
                              ir_expression *const r072E = bit_and(r072D, body.constant(1u));
                              ir_expression *const r072F = expr(ir_unop_bit_not, r072E);
                              body.emit(assign(r06EB, bit_and(r0726, r072F), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0725->else_instructions;

                              ir_expression *const r0730 = bit_or(r06EA, r06EB);
                              ir_expression *const r0731 = equal(r0730, body.constant(0u));
                              body.emit(assign(r06E9, expr(ir_triop_csel, r0731, body.constant(int(0)), r06E9), 0x01));


                           body.instructions = f0725_parent_instructions;
                           body.emit(f0725);

                           /* END IF */

                           ir_variable *const r0732 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0732);
                           ir_expression *const r0733 = lshift(r01F9, body.constant(int(31)));
                           ir_expression *const r0734 = expr(ir_unop_i2u, r06E9);
                           ir_expression *const r0735 = lshift(r0734, body.constant(int(20)));
                           ir_expression *const r0736 = add(r0733, r0735);
                           body.emit(assign(r0732, add(r0736, r06EA), 0x02));

                           body.emit(assign(r0732, r06EB, 0x01));

                           body.emit(assign(r06EE, r0732, 0x03));

                           body.emit(assign(r06ED, body.constant(false), 0x01));


                        body.instructions = f0724_parent_instructions;
                        body.emit(f0724);

                        /* END IF */

                        body.emit(assign(r01F0, r06EE, 0x03));

                        body.emit(assign(r01EF, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f06A6->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0738 = less(r01F8, r01F6);
                        ir_if *f0737 = new(mem_ctx) ir_if(operand(r0738).val);
                        exec_list *const f0737_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0737->then_instructions;

                           ir_variable *const r0739 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_expression *const r073A = sub(r01F5, r01F7);
                           ir_expression *const r073B = less(r01F6, r01F8);
                           ir_expression *const r073C = expr(ir_unop_b2i, r073B);
                           ir_expression *const r073D = expr(ir_unop_i2u, r073C);
                           body.emit(assign(r0739, sub(r073A, r073D), 0x01));

                           body.emit(assign(r01F2, r0739, 0x01));

                           body.emit(assign(r01F9, bit_xor(r01F9, body.constant(1u)), 0x01));

                           body.emit(assign(r03B3, add(r01F3, body.constant(int(-1))), 0x01));

                           ir_variable *const r073E = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r073E, add(r03B3, body.constant(int(-10))), 0x01));

                           ir_variable *const r073F = body.make_temp(glsl_type::uint_type, "zFrac0");
                           ir_variable *const r0740 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           ir_variable *const r0741 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r0741);
                           ir_variable *const r0742 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r0742);
                           ir_expression *const r0743 = equal(r0739, body.constant(0u));
                           ir_expression *const r0744 = add(r073E, body.constant(int(-32)));
                           body.emit(assign(r073E, expr(ir_triop_csel, r0743, r0744, r073E), 0x01));

                           ir_variable *const r0745 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r0746 = equal(r0739, body.constant(0u));
                           ir_expression *const r0747 = sub(r01F6, r01F8);
                           body.emit(assign(r0745, expr(ir_triop_csel, r0746, body.constant(0u), r0747), 0x01));

                           body.emit(assign(r0740, r0745, 0x01));

                           ir_variable *const r0748 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r0749 = equal(r0739, body.constant(0u));
                           body.emit(assign(r0748, expr(ir_triop_csel, r0749, r0745, r0739), 0x01));

                           body.emit(assign(r073F, r0748, 0x01));

                           ir_expression *const r074A = equal(r0748, body.constant(0u));
                           ir_expression *const r074B = expr(ir_unop_find_msb, r0748);
                           ir_expression *const r074C = sub(body.constant(int(31)), r074B);
                           ir_expression *const r074D = expr(ir_triop_csel, r074A, body.constant(int(32)), r074C);
                           body.emit(assign(r0742, add(r074D, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r074F = gequal(r0742, body.constant(int(0)));
                           ir_if *f074E = new(mem_ctx) ir_if(operand(r074F).val);
                           exec_list *const f074E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f074E->then_instructions;

                              body.emit(assign(r0741, body.constant(0u), 0x01));

                              ir_expression *const r0750 = equal(r0742, body.constant(int(0)));
                              ir_expression *const r0751 = lshift(r0748, r0742);
                              ir_expression *const r0752 = neg(r0742);
                              ir_expression *const r0753 = bit_and(r0752, body.constant(int(31)));
                              ir_expression *const r0754 = rshift(r0745, r0753);
                              ir_expression *const r0755 = bit_or(r0751, r0754);
                              body.emit(assign(r073F, expr(ir_triop_csel, r0750, r0748, r0755), 0x01));

                              body.emit(assign(r0740, lshift(r0745, r0742), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f074E->else_instructions;

                              ir_variable *const r0756 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r0756, body.constant(0u), 0x01));

                              ir_variable *const r0757 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0757, neg(r0742), 0x01));

                              ir_variable *const r0758 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0758);
                              ir_variable *const r0759 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0759);
                              ir_variable *const r075A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r075A);
                              ir_variable *const r075B = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r075C = neg(r0757);
                              body.emit(assign(r075B, bit_and(r075C, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r075E = less(r0757, body.constant(int(32)));
                              ir_if *f075D = new(mem_ctx) ir_if(operand(r075E).val);
                              exec_list *const f075D_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f075D->then_instructions;

                                 body.emit(assign(r0758, lshift(r0740, r075B), 0x01));

                                 ir_expression *const r075F = lshift(r073F, r075B);
                                 ir_expression *const r0760 = rshift(r0740, r0757);
                                 body.emit(assign(r0759, bit_or(r075F, r0760), 0x01));

                                 body.emit(assign(r075A, rshift(r073F, r0757), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f075D->else_instructions;

                                 body.emit(assign(r0756, bit_or(body.constant(0u), r0740), 0x01));

                                 ir_expression *const r0761 = less(r0757, body.constant(int(64)));
                                 ir_expression *const r0762 = lshift(r073F, r075B);
                                 ir_expression *const r0763 = equal(r0757, body.constant(int(64)));
                                 ir_expression *const r0764 = nequal(r073F, body.constant(0u));
                                 ir_expression *const r0765 = expr(ir_unop_b2i, r0764);
                                 ir_expression *const r0766 = expr(ir_unop_i2u, r0765);
                                 ir_expression *const r0767 = expr(ir_triop_csel, r0763, r073F, r0766);
                                 body.emit(assign(r0758, expr(ir_triop_csel, r0761, r0762, r0767), 0x01));

                                 ir_expression *const r0768 = less(r0757, body.constant(int(64)));
                                 ir_expression *const r0769 = bit_and(r0757, body.constant(int(31)));
                                 ir_expression *const r076A = rshift(r073F, r0769);
                                 body.emit(assign(r0759, expr(ir_triop_csel, r0768, r076A, body.constant(0u)), 0x01));

                                 body.emit(assign(r075A, body.constant(0u), 0x01));


                              body.instructions = f075D_parent_instructions;
                              body.emit(f075D);

                              /* END IF */

                              ir_expression *const r076B = nequal(r0756, body.constant(0u));
                              ir_expression *const r076C = expr(ir_unop_b2i, r076B);
                              ir_expression *const r076D = expr(ir_unop_i2u, r076C);
                              body.emit(assign(r0758, bit_or(r0758, r076D), 0x01));

                              ir_variable *const r076E = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r076F = equal(r0757, body.constant(int(0)));
                              ir_expression *const r0770 = equal(r0757, body.constant(int(32)));
                              ir_expression *const r0771 = expr(ir_triop_csel, r0770, body.constant(0u), r075A);
                              body.emit(assign(r076E, expr(ir_triop_csel, r076F, r073F, r0771), 0x01));

                              body.emit(assign(r075A, r076E, 0x01));

                              ir_variable *const r0772 = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r0773 = equal(r0757, body.constant(int(0)));
                              ir_expression *const r0774 = equal(r0757, body.constant(int(32)));
                              ir_expression *const r0775 = expr(ir_triop_csel, r0774, r073F, r0759);
                              body.emit(assign(r0772, expr(ir_triop_csel, r0773, r0740, r0775), 0x01));

                              body.emit(assign(r0759, r0772, 0x01));

                              ir_variable *const r0776 = body.make_temp(glsl_type::uint_type, "mix_retval");
                              ir_expression *const r0777 = equal(r0757, body.constant(int(0)));
                              ir_expression *const r0778 = equal(r0757, body.constant(int(32)));
                              ir_expression *const r0779 = expr(ir_triop_csel, r0778, r0740, r0758);
                              body.emit(assign(r0776, expr(ir_triop_csel, r0777, r0756, r0779), 0x01));

                              body.emit(assign(r0758, r0776, 0x01));

                              body.emit(assign(r073F, r076E, 0x01));

                              body.emit(assign(r0740, r0772, 0x01));

                              body.emit(assign(r0741, r0776, 0x01));


                           body.instructions = f074E_parent_instructions;
                           body.emit(f074E);

                           /* END IF */

                           body.emit(assign(r073E, sub(r073E, r0742), 0x01));

                           ir_variable *const r077A = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r077A, r073E, 0x01));

                           ir_variable *const r077B = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r077B, r073F, 0x01));

                           ir_variable *const r077C = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r077C, r0740, 0x01));

                           ir_variable *const r077D = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r077D, r0741, 0x01));

                           ir_variable *const r077E = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r077E, body.constant(true), 0x01));

                           ir_variable *const r077F = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r0780 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r0780);
                           ir_expression *const r0781 = expr(ir_unop_u2i, r0741);
                           body.emit(assign(r0780, less(r0781, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0783 = gequal(r073E, body.constant(int(2045)));
                           ir_if *f0782 = new(mem_ctx) ir_if(operand(r0783).val);
                           exec_list *const f0782_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0782->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0785 = less(body.constant(int(2045)), r073E);
                              ir_expression *const r0786 = equal(r073E, body.constant(int(2045)));
                              ir_expression *const r0787 = equal(body.constant(2097151u), r073F);
                              ir_expression *const r0788 = equal(body.constant(4294967295u), r0740);
                              ir_expression *const r0789 = logic_and(r0787, r0788);
                              ir_expression *const r078A = logic_and(r0786, r0789);
                              ir_expression *const r078B = logic_and(r078A, r0780);
                              ir_expression *const r078C = logic_or(r0785, r078B);
                              ir_if *f0784 = new(mem_ctx) ir_if(operand(r078C).val);
                              exec_list *const f0784_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0784->then_instructions;

                                 ir_variable *const r078D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r078D);
                                 ir_expression *const r078E = lshift(r01F9, body.constant(int(31)));
                                 body.emit(assign(r078D, add(r078E, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r078D, body.constant(0u), 0x01));

                                 body.emit(assign(r077F, r078D, 0x03));

                                 body.emit(assign(r077E, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0784->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0790 = less(r073E, body.constant(int(0)));
                                 ir_if *f078F = new(mem_ctx) ir_if(operand(r0790).val);
                                 exec_list *const f078F_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f078F->then_instructions;

                                    ir_variable *const r0791 = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r0791, r0741, 0x01));

                                    ir_variable *const r0792 = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r0792, neg(r073E), 0x01));

                                    ir_variable *const r0793 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r0793);
                                    ir_variable *const r0794 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r0794);
                                    ir_variable *const r0795 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r0795);
                                    ir_variable *const r0796 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r0797 = neg(r0792);
                                    body.emit(assign(r0796, bit_and(r0797, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0799 = less(r0792, body.constant(int(32)));
                                    ir_if *f0798 = new(mem_ctx) ir_if(operand(r0799).val);
                                    exec_list *const f0798_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0798->then_instructions;

                                       body.emit(assign(r0793, lshift(r0740, r0796), 0x01));

                                       ir_expression *const r079A = lshift(r073F, r0796);
                                       ir_expression *const r079B = rshift(r0740, r0792);
                                       body.emit(assign(r0794, bit_or(r079A, r079B), 0x01));

                                       body.emit(assign(r0795, rshift(r073F, r0792), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0798->else_instructions;

                                       body.emit(assign(r0791, bit_or(r0741, r0740), 0x01));

                                       ir_expression *const r079C = less(r0792, body.constant(int(64)));
                                       ir_expression *const r079D = lshift(r073F, r0796);
                                       ir_expression *const r079E = equal(r0792, body.constant(int(64)));
                                       ir_expression *const r079F = nequal(r073F, body.constant(0u));
                                       ir_expression *const r07A0 = expr(ir_unop_b2i, r079F);
                                       ir_expression *const r07A1 = expr(ir_unop_i2u, r07A0);
                                       ir_expression *const r07A2 = expr(ir_triop_csel, r079E, r073F, r07A1);
                                       body.emit(assign(r0793, expr(ir_triop_csel, r079C, r079D, r07A2), 0x01));

                                       ir_expression *const r07A3 = less(r0792, body.constant(int(64)));
                                       ir_expression *const r07A4 = bit_and(r0792, body.constant(int(31)));
                                       ir_expression *const r07A5 = rshift(r073F, r07A4);
                                       body.emit(assign(r0794, expr(ir_triop_csel, r07A3, r07A5, body.constant(0u)), 0x01));

                                       body.emit(assign(r0795, body.constant(0u), 0x01));


                                    body.instructions = f0798_parent_instructions;
                                    body.emit(f0798);

                                    /* END IF */

                                    ir_expression *const r07A6 = nequal(r0791, body.constant(0u));
                                    ir_expression *const r07A7 = expr(ir_unop_b2i, r07A6);
                                    ir_expression *const r07A8 = expr(ir_unop_i2u, r07A7);
                                    body.emit(assign(r0793, bit_or(r0793, r07A8), 0x01));

                                    ir_variable *const r07A9 = body.make_temp(glsl_type::uint_type, "mix_retval");
                                    ir_expression *const r07AA = equal(r0792, body.constant(int(0)));
                                    ir_expression *const r07AB = equal(r0792, body.constant(int(32)));
                                    ir_expression *const r07AC = expr(ir_triop_csel, r07AB, body.constant(0u), r0795);
                                    body.emit(assign(r07A9, expr(ir_triop_csel, r07AA, r073F, r07AC), 0x01));

                                    body.emit(assign(r0795, r07A9, 0x01));

                                    ir_variable *const r07AD = body.make_temp(glsl_type::uint_type, "mix_retval");
                                    ir_expression *const r07AE = equal(r0792, body.constant(int(0)));
                                    ir_expression *const r07AF = equal(r0792, body.constant(int(32)));
                                    ir_expression *const r07B0 = expr(ir_triop_csel, r07AF, r073F, r0794);
                                    body.emit(assign(r07AD, expr(ir_triop_csel, r07AE, r0740, r07B0), 0x01));

                                    body.emit(assign(r0794, r07AD, 0x01));

                                    ir_variable *const r07B1 = body.make_temp(glsl_type::uint_type, "mix_retval");
                                    ir_expression *const r07B2 = equal(r0792, body.constant(int(0)));
                                    ir_expression *const r07B3 = equal(r0792, body.constant(int(32)));
                                    ir_expression *const r07B4 = expr(ir_triop_csel, r07B3, r0740, r0793);
                                    body.emit(assign(r07B1, expr(ir_triop_csel, r07B2, r0791, r07B4), 0x01));

                                    body.emit(assign(r0793, r07B1, 0x01));

                                    body.emit(assign(r077B, r07A9, 0x01));

                                    body.emit(assign(r077C, r07AD, 0x01));

                                    body.emit(assign(r077D, r07B1, 0x01));

                                    body.emit(assign(r077A, body.constant(int(0)), 0x01));

                                    body.emit(assign(r0780, less(r07B1, body.constant(0u)), 0x01));


                                 body.instructions = f078F_parent_instructions;
                                 body.emit(f078F);

                                 /* END IF */


                              body.instructions = f0784_parent_instructions;
                              body.emit(f0784);

                              /* END IF */


                           body.instructions = f0782_parent_instructions;
                           body.emit(f0782);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f07B5 = new(mem_ctx) ir_if(operand(r077E).val);
                           exec_list *const f07B5_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07B5->then_instructions;

                              /* IF CONDITION */
                              ir_if *f07B6 = new(mem_ctx) ir_if(operand(r0780).val);
                              exec_list *const f07B6_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f07B6->then_instructions;

                                 ir_variable *const r07B7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r07B7, add(r077C, body.constant(1u)), 0x01));

                                 ir_expression *const r07B8 = less(r07B7, r077C);
                                 ir_expression *const r07B9 = expr(ir_unop_b2i, r07B8);
                                 ir_expression *const r07BA = expr(ir_unop_i2u, r07B9);
                                 body.emit(assign(r077B, add(r077B, r07BA), 0x01));

                                 ir_expression *const r07BB = equal(r077D, body.constant(0u));
                                 ir_expression *const r07BC = expr(ir_unop_b2i, r07BB);
                                 ir_expression *const r07BD = expr(ir_unop_i2u, r07BC);
                                 ir_expression *const r07BE = add(r077D, r07BD);
                                 ir_expression *const r07BF = bit_and(r07BE, body.constant(1u));
                                 ir_expression *const r07C0 = expr(ir_unop_bit_not, r07BF);
                                 body.emit(assign(r077C, bit_and(r07B7, r07C0), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f07B6->else_instructions;

                                 ir_expression *const r07C1 = bit_or(r077B, r077C);
                                 ir_expression *const r07C2 = equal(r07C1, body.constant(0u));
                                 body.emit(assign(r077A, expr(ir_triop_csel, r07C2, body.constant(int(0)), r077A), 0x01));


                              body.instructions = f07B6_parent_instructions;
                              body.emit(f07B6);

                              /* END IF */

                              ir_variable *const r07C3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r07C3);
                              ir_expression *const r07C4 = lshift(r01F9, body.constant(int(31)));
                              ir_expression *const r07C5 = expr(ir_unop_i2u, r077A);
                              ir_expression *const r07C6 = lshift(r07C5, body.constant(int(20)));
                              ir_expression *const r07C7 = add(r07C4, r07C6);
                              body.emit(assign(r07C3, add(r07C7, r077B), 0x02));

                              body.emit(assign(r07C3, r077C, 0x01));

                              body.emit(assign(r077F, r07C3, 0x03));

                              body.emit(assign(r077E, body.constant(false), 0x01));


                           body.instructions = f07B5_parent_instructions;
                           body.emit(f07B5);

                           /* END IF */

                           body.emit(assign(r01F0, r077F, 0x03));

                           body.emit(assign(r01EF, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0737->else_instructions;

                           ir_variable *const r07C8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r07C8);
                           body.emit(assign(r07C8, body.constant(0u), 0x02));

                           body.emit(assign(r07C8, body.constant(0u), 0x01));

                           body.emit(assign(r01F0, r07C8, 0x03));

                           body.emit(assign(r01EF, body.constant(false), 0x01));


                        body.instructions = f0737_parent_instructions;
                        body.emit(f0737);

                        /* END IF */


                     body.instructions = f06A6_parent_instructions;
                     body.emit(f06A6);

                     /* END IF */


                  body.instructions = f0615_parent_instructions;
                  body.emit(f0615);

                  /* END IF */


               body.instructions = f0584_parent_instructions;
               body.emit(f0584);

               /* END IF */


            body.instructions = f0566_parent_instructions;
            body.emit(f0566);

            /* END IF */


         body.instructions = f048F_parent_instructions;
         body.emit(f048F);

         /* END IF */


      body.instructions = f03BC_parent_instructions;
      body.emit(f03BC);

      /* END IF */


   body.instructions = f0205_parent_instructions;
   body.emit(f0205);

   /* END IF */

   body.emit(ret(r01F0));

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

   ir_variable *const r07C9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r07C9);
   ir_variable *const r07CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r07CA);
   ir_variable *const r07CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07CB);
   ir_variable *const r07CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07CC);
   ir_variable *const r07CD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07CD);
   ir_variable *const r07CE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07CE);
   ir_variable *const r07CF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07CF);
   ir_variable *const r07D0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D0, bit_and(r07C9, body.constant(65535u)), 0x01));

   ir_variable *const r07D1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D1, rshift(r07C9, body.constant(int(16))), 0x01));

   ir_variable *const r07D2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D2, bit_and(r07CA, body.constant(65535u)), 0x01));

   ir_variable *const r07D3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D3, rshift(r07CA, body.constant(int(16))), 0x01));

   ir_variable *const r07D4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D4, mul(r07D1, r07D2), 0x01));

   ir_expression *const r07D5 = mul(r07D0, r07D3);
   body.emit(assign(r07CE, add(r07D5, r07D4), 0x01));

   ir_expression *const r07D6 = mul(r07D1, r07D3);
   ir_expression *const r07D7 = less(r07CE, r07D4);
   ir_expression *const r07D8 = expr(ir_unop_b2i, r07D7);
   ir_expression *const r07D9 = expr(ir_unop_i2u, r07D8);
   ir_expression *const r07DA = lshift(r07D9, body.constant(int(16)));
   ir_expression *const r07DB = rshift(r07CE, body.constant(int(16)));
   ir_expression *const r07DC = add(r07DA, r07DB);
   body.emit(assign(r07CD, add(r07D6, r07DC), 0x01));

   body.emit(assign(r07CE, lshift(r07CE, body.constant(int(16))), 0x01));

   ir_expression *const r07DD = mul(r07D0, r07D2);
   body.emit(assign(r07CF, add(r07DD, r07CE), 0x01));

   ir_expression *const r07DE = less(r07CF, r07CE);
   ir_expression *const r07DF = expr(ir_unop_b2i, r07DE);
   ir_expression *const r07E0 = expr(ir_unop_i2u, r07DF);
   body.emit(assign(r07CD, add(r07CD, r07E0), 0x01));

   body.emit(assign(r07CC, r07CF, 0x01));

   body.emit(assign(r07CB, r07CD, 0x01));

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

   ir_variable *const r07E1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r07E1);
   ir_variable *const r07E2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r07E2);
   ir_variable *const r07E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r07E3);
   ir_variable *const r07E4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r07E4);
   ir_variable *const r07E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07E5);
   ir_variable *const r07E6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07E6);
   ir_variable *const r07E7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07E7);
   ir_variable *const r07E8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07E8);
   ir_variable *const r07E9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07E9);
   ir_variable *const r07EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07EA);
   ir_variable *const r07EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07EB);
   ir_variable *const r07EC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EC, bit_and(r07E2, body.constant(65535u)), 0x01));

   ir_variable *const r07ED = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07ED, rshift(r07E2, body.constant(int(16))), 0x01));

   ir_variable *const r07EE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EE, bit_and(r07E4, body.constant(65535u)), 0x01));

   ir_variable *const r07EF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EF, rshift(r07E4, body.constant(int(16))), 0x01));

   ir_variable *const r07F0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07F0, mul(r07ED, r07EE), 0x01));

   ir_expression *const r07F1 = mul(r07EC, r07EF);
   body.emit(assign(r07EA, add(r07F1, r07F0), 0x01));

   ir_expression *const r07F2 = mul(r07ED, r07EF);
   ir_expression *const r07F3 = less(r07EA, r07F0);
   ir_expression *const r07F4 = expr(ir_unop_b2i, r07F3);
   ir_expression *const r07F5 = expr(ir_unop_i2u, r07F4);
   ir_expression *const r07F6 = lshift(r07F5, body.constant(int(16)));
   ir_expression *const r07F7 = rshift(r07EA, body.constant(int(16)));
   ir_expression *const r07F8 = add(r07F6, r07F7);
   body.emit(assign(r07E9, add(r07F2, r07F8), 0x01));

   body.emit(assign(r07EA, lshift(r07EA, body.constant(int(16))), 0x01));

   ir_expression *const r07F9 = mul(r07EC, r07EE);
   body.emit(assign(r07EB, add(r07F9, r07EA), 0x01));

   ir_expression *const r07FA = less(r07EB, r07EA);
   ir_expression *const r07FB = expr(ir_unop_b2i, r07FA);
   ir_expression *const r07FC = expr(ir_unop_i2u, r07FB);
   body.emit(assign(r07E9, add(r07E9, r07FC), 0x01));

   ir_variable *const r07FD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07FD);
   ir_variable *const r07FE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07FE);
   ir_variable *const r07FF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07FF);
   ir_variable *const r0800 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0800, bit_and(r07E2, body.constant(65535u)), 0x01));

   ir_variable *const r0801 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0801, rshift(r07E2, body.constant(int(16))), 0x01));

   ir_variable *const r0802 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0802, bit_and(r07E3, body.constant(65535u)), 0x01));

   ir_variable *const r0803 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0803, rshift(r07E3, body.constant(int(16))), 0x01));

   ir_variable *const r0804 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0804, mul(r0801, r0802), 0x01));

   ir_expression *const r0805 = mul(r0800, r0803);
   body.emit(assign(r07FE, add(r0805, r0804), 0x01));

   ir_expression *const r0806 = mul(r0801, r0803);
   ir_expression *const r0807 = less(r07FE, r0804);
   ir_expression *const r0808 = expr(ir_unop_b2i, r0807);
   ir_expression *const r0809 = expr(ir_unop_i2u, r0808);
   ir_expression *const r080A = lshift(r0809, body.constant(int(16)));
   ir_expression *const r080B = rshift(r07FE, body.constant(int(16)));
   ir_expression *const r080C = add(r080A, r080B);
   body.emit(assign(r07FD, add(r0806, r080C), 0x01));

   body.emit(assign(r07FE, lshift(r07FE, body.constant(int(16))), 0x01));

   ir_expression *const r080D = mul(r0800, r0802);
   body.emit(assign(r07FF, add(r080D, r07FE), 0x01));

   ir_expression *const r080E = less(r07FF, r07FE);
   ir_expression *const r080F = expr(ir_unop_b2i, r080E);
   ir_expression *const r0810 = expr(ir_unop_i2u, r080F);
   body.emit(assign(r07FD, add(r07FD, r0810), 0x01));

   ir_variable *const r0811 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0811, add(r07FF, r07E9), 0x01));

   ir_variable *const r0812 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0812);
   ir_variable *const r0813 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0813);
   ir_variable *const r0814 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0814);
   ir_variable *const r0815 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0815, bit_and(r07E1, body.constant(65535u)), 0x01));

   ir_variable *const r0816 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0816, rshift(r07E1, body.constant(int(16))), 0x01));

   ir_variable *const r0817 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0817, bit_and(r07E3, body.constant(65535u)), 0x01));

   ir_variable *const r0818 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0818, rshift(r07E3, body.constant(int(16))), 0x01));

   ir_variable *const r0819 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0819, mul(r0816, r0817), 0x01));

   ir_expression *const r081A = mul(r0815, r0818);
   body.emit(assign(r0813, add(r081A, r0819), 0x01));

   ir_expression *const r081B = mul(r0816, r0818);
   ir_expression *const r081C = less(r0813, r0819);
   ir_expression *const r081D = expr(ir_unop_b2i, r081C);
   ir_expression *const r081E = expr(ir_unop_i2u, r081D);
   ir_expression *const r081F = lshift(r081E, body.constant(int(16)));
   ir_expression *const r0820 = rshift(r0813, body.constant(int(16)));
   ir_expression *const r0821 = add(r081F, r0820);
   body.emit(assign(r0812, add(r081B, r0821), 0x01));

   body.emit(assign(r0813, lshift(r0813, body.constant(int(16))), 0x01));

   ir_expression *const r0822 = mul(r0815, r0817);
   body.emit(assign(r0814, add(r0822, r0813), 0x01));

   ir_expression *const r0823 = less(r0814, r0813);
   ir_expression *const r0824 = expr(ir_unop_b2i, r0823);
   ir_expression *const r0825 = expr(ir_unop_i2u, r0824);
   body.emit(assign(r0812, add(r0812, r0825), 0x01));

   ir_variable *const r0826 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0827 = less(r0811, r07FF);
   ir_expression *const r0828 = expr(ir_unop_b2i, r0827);
   ir_expression *const r0829 = expr(ir_unop_i2u, r0828);
   ir_expression *const r082A = add(r07FD, r0829);
   body.emit(assign(r0826, add(r0814, r082A), 0x01));

   ir_variable *const r082B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r082B);
   ir_variable *const r082C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r082C);
   ir_variable *const r082D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r082D);
   ir_variable *const r082E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r082E, bit_and(r07E1, body.constant(65535u)), 0x01));

   ir_variable *const r082F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r082F, rshift(r07E1, body.constant(int(16))), 0x01));

   ir_variable *const r0830 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0830, bit_and(r07E4, body.constant(65535u)), 0x01));

   ir_variable *const r0831 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0831, rshift(r07E4, body.constant(int(16))), 0x01));

   ir_variable *const r0832 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0832, mul(r082F, r0830), 0x01));

   ir_expression *const r0833 = mul(r082E, r0831);
   body.emit(assign(r082C, add(r0833, r0832), 0x01));

   ir_expression *const r0834 = mul(r082F, r0831);
   ir_expression *const r0835 = less(r082C, r0832);
   ir_expression *const r0836 = expr(ir_unop_b2i, r0835);
   ir_expression *const r0837 = expr(ir_unop_i2u, r0836);
   ir_expression *const r0838 = lshift(r0837, body.constant(int(16)));
   ir_expression *const r0839 = rshift(r082C, body.constant(int(16)));
   ir_expression *const r083A = add(r0838, r0839);
   body.emit(assign(r082B, add(r0834, r083A), 0x01));

   body.emit(assign(r082C, lshift(r082C, body.constant(int(16))), 0x01));

   ir_expression *const r083B = mul(r082E, r0830);
   body.emit(assign(r082D, add(r083B, r082C), 0x01));

   ir_expression *const r083C = less(r082D, r082C);
   ir_expression *const r083D = expr(ir_unop_b2i, r083C);
   ir_expression *const r083E = expr(ir_unop_i2u, r083D);
   body.emit(assign(r082B, add(r082B, r083E), 0x01));

   ir_variable *const r083F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r083F, add(r082D, r0811), 0x01));

   ir_variable *const r0840 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0841 = less(r083F, r082D);
   ir_expression *const r0842 = expr(ir_unop_b2i, r0841);
   ir_expression *const r0843 = expr(ir_unop_i2u, r0842);
   ir_expression *const r0844 = add(r082B, r0843);
   body.emit(assign(r0840, add(r0826, r0844), 0x01));

   body.emit(assign(r07E8, r07EB, 0x01));

   body.emit(assign(r07E7, r083F, 0x01));

   body.emit(assign(r07E6, r0840, 0x01));

   ir_expression *const r0845 = less(r0826, r0814);
   ir_expression *const r0846 = expr(ir_unop_b2i, r0845);
   ir_expression *const r0847 = expr(ir_unop_i2u, r0846);
   ir_expression *const r0848 = add(r0812, r0847);
   ir_expression *const r0849 = less(r0840, r0826);
   ir_expression *const r084A = expr(ir_unop_b2i, r0849);
   ir_expression *const r084B = expr(ir_unop_i2u, r084A);
   body.emit(assign(r07E5, add(r0848, r084B), 0x01));

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

   ir_variable *const r084C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r084C);
   ir_variable *const r084D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r084D);
   ir_variable *const r084E = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r084E);
   ir_variable *const r084F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r084F);
   ir_variable *const r0850 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0850);
   ir_variable *const r0851 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0851);
   /* IF CONDITION */
   ir_expression *const r0853 = equal(r084C, body.constant(0u));
   ir_if *f0852 = new(mem_ctx) ir_if(operand(r0853).val);
   exec_list *const f0852_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0852->then_instructions;

      ir_expression *const r0854 = equal(r084D, body.constant(0u));
      ir_expression *const r0855 = expr(ir_unop_find_msb, r084D);
      ir_expression *const r0856 = sub(body.constant(int(31)), r0855);
      ir_expression *const r0857 = expr(ir_triop_csel, r0854, body.constant(int(32)), r0856);
      body.emit(assign(r0851, add(r0857, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0859 = less(r0851, body.constant(int(0)));
      ir_if *f0858 = new(mem_ctx) ir_if(operand(r0859).val);
      exec_list *const f0858_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0858->then_instructions;

         ir_expression *const r085A = neg(r0851);
         body.emit(assign(r084F, rshift(r084D, r085A), 0x01));

         ir_expression *const r085B = bit_and(r0851, body.constant(int(31)));
         body.emit(assign(r0850, lshift(r084D, r085B), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0858->else_instructions;

         body.emit(assign(r084F, lshift(r084D, r0851), 0x01));

         body.emit(assign(r0850, body.constant(0u), 0x01));


      body.instructions = f0858_parent_instructions;
      body.emit(f0858);

      /* END IF */

      body.emit(assign(r084E, sub(body.constant(int(-31)), r0851), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0852->else_instructions;

      ir_expression *const r085C = equal(r084C, body.constant(0u));
      ir_expression *const r085D = expr(ir_unop_find_msb, r084C);
      ir_expression *const r085E = sub(body.constant(int(31)), r085D);
      ir_expression *const r085F = expr(ir_triop_csel, r085C, body.constant(int(32)), r085E);
      body.emit(assign(r0851, add(r085F, body.constant(int(-11))), 0x01));

      ir_expression *const r0860 = equal(r0851, body.constant(int(0)));
      ir_expression *const r0861 = lshift(r084C, r0851);
      ir_expression *const r0862 = neg(r0851);
      ir_expression *const r0863 = bit_and(r0862, body.constant(int(31)));
      ir_expression *const r0864 = rshift(r084D, r0863);
      ir_expression *const r0865 = bit_or(r0861, r0864);
      body.emit(assign(r084F, expr(ir_triop_csel, r0860, r084C, r0865), 0x01));

      body.emit(assign(r0850, lshift(r084D, r0851), 0x01));

      body.emit(assign(r084E, sub(body.constant(int(1)), r0851), 0x01));


   body.instructions = f0852_parent_instructions;
   body.emit(f0852);

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

   ir_variable *const r0866 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0866);
   ir_variable *const r0867 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0867);
   ir_variable *const r0868 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0868, body.constant(true), 0x01));

   ir_variable *const r0869 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r086A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r086A);
   ir_variable *const r086B = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r086B);
   ir_variable *const r086C = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r086C);
   ir_variable *const r086D = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r086D);
   ir_variable *const r086E = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r086E);
   ir_variable *const r086F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r086F);
   ir_variable *const r0870 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0870);
   ir_variable *const r0871 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r0871);
   ir_variable *const r0872 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0872);
   ir_variable *const r0873 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0873);
   ir_variable *const r0874 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0874);
   body.emit(assign(r0874, body.constant(0u), 0x01));

   body.emit(assign(r0873, body.constant(0u), 0x01));

   body.emit(assign(r0872, body.constant(0u), 0x01));

   ir_variable *const r0875 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0875, swizzle_x(r0866), 0x01));

   body.emit(assign(r0870, r0875, 0x01));

   ir_variable *const r0876 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0876, bit_and(swizzle_y(r0866), body.constant(1048575u)), 0x01));

   body.emit(assign(r086F, r0876, 0x01));

   ir_variable *const r0877 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0877, swizzle_x(r0867), 0x01));

   body.emit(assign(r086E, r0877, 0x01));

   ir_variable *const r0878 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0878, bit_and(swizzle_y(r0867), body.constant(1048575u)), 0x01));

   body.emit(assign(r086D, r0878, 0x01));

   ir_variable *const r0879 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r087A = rshift(swizzle_y(r0866), body.constant(int(20)));
   ir_expression *const r087B = bit_and(r087A, body.constant(2047u));
   body.emit(assign(r0879, expr(ir_unop_u2i, r087B), 0x01));

   body.emit(assign(r086C, r0879, 0x01));

   ir_variable *const r087C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r087D = rshift(swizzle_y(r0867), body.constant(int(20)));
   ir_expression *const r087E = bit_and(r087D, body.constant(2047u));
   body.emit(assign(r087C, expr(ir_unop_u2i, r087E), 0x01));

   body.emit(assign(r086B, r087C, 0x01));

   ir_expression *const r087F = rshift(swizzle_y(r0866), body.constant(int(31)));
   ir_expression *const r0880 = rshift(swizzle_y(r0867), body.constant(int(31)));
   body.emit(assign(r086A, bit_xor(r087F, r0880), 0x01));

   /* IF CONDITION */
   ir_expression *const r0882 = equal(r0879, body.constant(int(2047)));
   ir_if *f0881 = new(mem_ctx) ir_if(operand(r0882).val);
   exec_list *const f0881_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0881->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0884 = bit_or(r0876, swizzle_x(r0866));
      ir_expression *const r0885 = nequal(r0884, body.constant(0u));
      ir_expression *const r0886 = equal(r087C, body.constant(int(2047)));
      ir_expression *const r0887 = bit_or(r0878, swizzle_x(r0867));
      ir_expression *const r0888 = nequal(r0887, body.constant(0u));
      ir_expression *const r0889 = logic_and(r0886, r0888);
      ir_expression *const r088A = logic_or(r0885, r0889);
      ir_if *f0883 = new(mem_ctx) ir_if(operand(r088A).val);
      exec_list *const f0883_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0883->then_instructions;

         ir_variable *const r088B = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r088B, swizzle_x(r0866), 0x01));

         ir_variable *const r088C = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r088C, swizzle_x(r0867), 0x01));

         body.emit(assign(r088B, bit_or(swizzle_y(r0866), body.constant(524288u)), 0x02));

         body.emit(assign(r088C, bit_or(swizzle_y(r0867), body.constant(524288u)), 0x02));

         ir_expression *const r088D = lshift(swizzle_y(r0866), body.constant(int(1)));
         ir_expression *const r088E = gequal(r088D, body.constant(4292870144u));
         ir_expression *const r088F = nequal(swizzle_x(r0866), body.constant(0u));
         ir_expression *const r0890 = bit_and(swizzle_y(r0866), body.constant(1048575u));
         ir_expression *const r0891 = nequal(r0890, body.constant(0u));
         ir_expression *const r0892 = logic_or(r088F, r0891);
         ir_expression *const r0893 = logic_and(r088E, r0892);
         ir_swizzle *const r0894 = swizzle(r0893, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r0895 = lshift(swizzle_y(r0867), body.constant(int(1)));
         ir_expression *const r0896 = gequal(r0895, body.constant(4292870144u));
         ir_expression *const r0897 = nequal(swizzle_x(r0867), body.constant(0u));
         ir_expression *const r0898 = bit_and(swizzle_y(r0867), body.constant(1048575u));
         ir_expression *const r0899 = nequal(r0898, body.constant(0u));
         ir_expression *const r089A = logic_or(r0897, r0899);
         ir_expression *const r089B = logic_and(r0896, r089A);
         ir_swizzle *const r089C = swizzle(r089B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r089D = expr(ir_triop_csel, r089C, r088C, r088B);
         body.emit(assign(r0869, expr(ir_triop_csel, r0894, r089D, r088C), 0x03));

         body.emit(assign(r0868, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0883->else_instructions;

         /* IF CONDITION */
         ir_expression *const r089F = expr(ir_unop_i2u, r087C);
         ir_expression *const r08A0 = bit_or(r089F, r0878);
         ir_expression *const r08A1 = bit_or(r08A0, swizzle_x(r0867));
         ir_expression *const r08A2 = equal(r08A1, body.constant(0u));
         ir_if *f089E = new(mem_ctx) ir_if(operand(r08A2).val);
         exec_list *const f089E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f089E->then_instructions;

            ir_constant_data r08A3_data;
            memset(&r08A3_data, 0, sizeof(ir_constant_data));
            r08A3_data.u[0] = 4294967295;
            r08A3_data.u[1] = 4294967295;
            ir_constant *const r08A3 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r08A3_data);
            body.emit(assign(r0869, r08A3, 0x03));

            body.emit(assign(r0868, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f089E->else_instructions;

            ir_variable *const r08A4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r08A4);
            ir_expression *const r08A5 = lshift(r086A, body.constant(int(31)));
            body.emit(assign(r08A4, add(r08A5, body.constant(2146435072u)), 0x02));

            body.emit(assign(r08A4, body.constant(0u), 0x01));

            body.emit(assign(r0869, r08A4, 0x03));

            body.emit(assign(r0868, body.constant(false), 0x01));


         body.instructions = f089E_parent_instructions;
         body.emit(f089E);

         /* END IF */


      body.instructions = f0883_parent_instructions;
      body.emit(f0883);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0881->else_instructions;

      /* IF CONDITION */
      ir_expression *const r08A7 = equal(r087C, body.constant(int(2047)));
      ir_if *f08A6 = new(mem_ctx) ir_if(operand(r08A7).val);
      exec_list *const f08A6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08A6->then_instructions;

         /* IF CONDITION */
         ir_expression *const r08A9 = bit_or(r0878, swizzle_x(r0867));
         ir_expression *const r08AA = nequal(r08A9, body.constant(0u));
         ir_if *f08A8 = new(mem_ctx) ir_if(operand(r08AA).val);
         exec_list *const f08A8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08A8->then_instructions;

            ir_variable *const r08AB = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r08AB, swizzle_x(r0866), 0x01));

            ir_variable *const r08AC = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r08AC, swizzle_x(r0867), 0x01));

            body.emit(assign(r08AB, bit_or(swizzle_y(r0866), body.constant(524288u)), 0x02));

            body.emit(assign(r08AC, bit_or(swizzle_y(r0867), body.constant(524288u)), 0x02));

            ir_expression *const r08AD = lshift(swizzle_y(r0866), body.constant(int(1)));
            ir_expression *const r08AE = gequal(r08AD, body.constant(4292870144u));
            ir_expression *const r08AF = nequal(swizzle_x(r0866), body.constant(0u));
            ir_expression *const r08B0 = bit_and(swizzle_y(r0866), body.constant(1048575u));
            ir_expression *const r08B1 = nequal(r08B0, body.constant(0u));
            ir_expression *const r08B2 = logic_or(r08AF, r08B1);
            ir_expression *const r08B3 = logic_and(r08AE, r08B2);
            ir_swizzle *const r08B4 = swizzle(r08B3, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r08B5 = lshift(swizzle_y(r0867), body.constant(int(1)));
            ir_expression *const r08B6 = gequal(r08B5, body.constant(4292870144u));
            ir_expression *const r08B7 = nequal(swizzle_x(r0867), body.constant(0u));
            ir_expression *const r08B8 = bit_and(swizzle_y(r0867), body.constant(1048575u));
            ir_expression *const r08B9 = nequal(r08B8, body.constant(0u));
            ir_expression *const r08BA = logic_or(r08B7, r08B9);
            ir_expression *const r08BB = logic_and(r08B6, r08BA);
            ir_swizzle *const r08BC = swizzle(r08BB, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r08BD = expr(ir_triop_csel, r08BC, r08AC, r08AB);
            body.emit(assign(r0869, expr(ir_triop_csel, r08B4, r08BD, r08AC), 0x03));

            body.emit(assign(r0868, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f08A8->else_instructions;

            /* IF CONDITION */
            ir_expression *const r08BF = expr(ir_unop_i2u, r0879);
            ir_expression *const r08C0 = bit_or(r08BF, r0876);
            ir_expression *const r08C1 = bit_or(r08C0, swizzle_x(r0866));
            ir_expression *const r08C2 = equal(r08C1, body.constant(0u));
            ir_if *f08BE = new(mem_ctx) ir_if(operand(r08C2).val);
            exec_list *const f08BE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08BE->then_instructions;

               ir_constant_data r08C3_data;
               memset(&r08C3_data, 0, sizeof(ir_constant_data));
               r08C3_data.u[0] = 4294967295;
               r08C3_data.u[1] = 4294967295;
               ir_constant *const r08C3 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r08C3_data);
               body.emit(assign(r0869, r08C3, 0x03));

               body.emit(assign(r0868, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08BE->else_instructions;

               ir_variable *const r08C4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r08C4);
               ir_expression *const r08C5 = lshift(r086A, body.constant(int(31)));
               body.emit(assign(r08C4, add(r08C5, body.constant(2146435072u)), 0x02));

               body.emit(assign(r08C4, body.constant(0u), 0x01));

               body.emit(assign(r0869, r08C4, 0x03));

               body.emit(assign(r0868, body.constant(false), 0x01));


            body.instructions = f08BE_parent_instructions;
            body.emit(f08BE);

            /* END IF */


         body.instructions = f08A8_parent_instructions;
         body.emit(f08A8);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08A6->else_instructions;

         /* IF CONDITION */
         ir_expression *const r08C7 = equal(r0879, body.constant(int(0)));
         ir_if *f08C6 = new(mem_ctx) ir_if(operand(r08C7).val);
         exec_list *const f08C6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08C6->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08C9 = bit_or(r0876, swizzle_x(r0866));
            ir_expression *const r08CA = equal(r08C9, body.constant(0u));
            ir_if *f08C8 = new(mem_ctx) ir_if(operand(r08CA).val);
            exec_list *const f08C8_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08C8->then_instructions;

               ir_variable *const r08CB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r08CB);
               body.emit(assign(r08CB, lshift(r086A, body.constant(int(31))), 0x02));

               body.emit(assign(r08CB, body.constant(0u), 0x01));

               body.emit(assign(r0869, r08CB, 0x03));

               body.emit(assign(r0868, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08C8->else_instructions;

               ir_variable *const r08CC = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r08CC, r0879, 0x01));

               ir_variable *const r08CD = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r08CD, r0876, 0x01));

               ir_variable *const r08CE = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r08CE, r0875, 0x01));

               ir_variable *const r08CF = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r08CF);
               /* IF CONDITION */
               ir_expression *const r08D1 = equal(r0876, body.constant(0u));
               ir_if *f08D0 = new(mem_ctx) ir_if(operand(r08D1).val);
               exec_list *const f08D0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08D0->then_instructions;

                  ir_expression *const r08D2 = equal(swizzle_x(r0866), body.constant(0u));
                  ir_expression *const r08D3 = expr(ir_unop_find_msb, swizzle_x(r0866));
                  ir_expression *const r08D4 = sub(body.constant(int(31)), r08D3);
                  ir_expression *const r08D5 = expr(ir_triop_csel, r08D2, body.constant(int(32)), r08D4);
                  body.emit(assign(r08CF, add(r08D5, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r08D7 = less(r08CF, body.constant(int(0)));
                  ir_if *f08D6 = new(mem_ctx) ir_if(operand(r08D7).val);
                  exec_list *const f08D6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08D6->then_instructions;

                     ir_expression *const r08D8 = neg(r08CF);
                     body.emit(assign(r08CD, rshift(swizzle_x(r0866), r08D8), 0x01));

                     ir_expression *const r08D9 = bit_and(r08CF, body.constant(int(31)));
                     body.emit(assign(r08CE, lshift(swizzle_x(r0866), r08D9), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08D6->else_instructions;

                     body.emit(assign(r08CD, lshift(swizzle_x(r0866), r08CF), 0x01));

                     body.emit(assign(r08CE, body.constant(0u), 0x01));


                  body.instructions = f08D6_parent_instructions;
                  body.emit(f08D6);

                  /* END IF */

                  body.emit(assign(r08CC, sub(body.constant(int(-31)), r08CF), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08D0->else_instructions;

                  ir_expression *const r08DA = equal(r0876, body.constant(0u));
                  ir_expression *const r08DB = expr(ir_unop_find_msb, r0876);
                  ir_expression *const r08DC = sub(body.constant(int(31)), r08DB);
                  ir_expression *const r08DD = expr(ir_triop_csel, r08DA, body.constant(int(32)), r08DC);
                  body.emit(assign(r08CF, add(r08DD, body.constant(int(-11))), 0x01));

                  ir_expression *const r08DE = equal(r08CF, body.constant(int(0)));
                  ir_expression *const r08DF = lshift(r0876, r08CF);
                  ir_expression *const r08E0 = neg(r08CF);
                  ir_expression *const r08E1 = bit_and(r08E0, body.constant(int(31)));
                  ir_expression *const r08E2 = rshift(swizzle_x(r0866), r08E1);
                  ir_expression *const r08E3 = bit_or(r08DF, r08E2);
                  body.emit(assign(r08CD, expr(ir_triop_csel, r08DE, r0876, r08E3), 0x01));

                  body.emit(assign(r08CE, lshift(swizzle_x(r0866), r08CF), 0x01));

                  body.emit(assign(r08CC, sub(body.constant(int(1)), r08CF), 0x01));


               body.instructions = f08D0_parent_instructions;
               body.emit(f08D0);

               /* END IF */

               body.emit(assign(r086C, r08CC, 0x01));

               body.emit(assign(r086F, r08CD, 0x01));

               body.emit(assign(r0870, r08CE, 0x01));


            body.instructions = f08C8_parent_instructions;
            body.emit(f08C8);

            /* END IF */


         body.instructions = f08C6_parent_instructions;
         body.emit(f08C6);

         /* END IF */

         /* IF CONDITION */
         ir_if *f08E4 = new(mem_ctx) ir_if(operand(r0868).val);
         exec_list *const f08E4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08E4->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08E6 = equal(r087C, body.constant(int(0)));
            ir_if *f08E5 = new(mem_ctx) ir_if(operand(r08E6).val);
            exec_list *const f08E5_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08E5->then_instructions;

               /* IF CONDITION */
               ir_expression *const r08E8 = bit_or(r0878, swizzle_x(r0867));
               ir_expression *const r08E9 = equal(r08E8, body.constant(0u));
               ir_if *f08E7 = new(mem_ctx) ir_if(operand(r08E9).val);
               exec_list *const f08E7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08E7->then_instructions;

                  ir_variable *const r08EA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r08EA);
                  body.emit(assign(r08EA, lshift(r086A, body.constant(int(31))), 0x02));

                  body.emit(assign(r08EA, body.constant(0u), 0x01));

                  body.emit(assign(r0869, r08EA, 0x03));

                  body.emit(assign(r0868, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08E7->else_instructions;

                  ir_variable *const r08EB = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r08EB, r087C, 0x01));

                  ir_variable *const r08EC = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r08EC, r0878, 0x01));

                  ir_variable *const r08ED = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r08ED, r0877, 0x01));

                  ir_variable *const r08EE = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08EE);
                  /* IF CONDITION */
                  ir_expression *const r08F0 = equal(r0878, body.constant(0u));
                  ir_if *f08EF = new(mem_ctx) ir_if(operand(r08F0).val);
                  exec_list *const f08EF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08EF->then_instructions;

                     ir_expression *const r08F1 = equal(swizzle_x(r0867), body.constant(0u));
                     ir_expression *const r08F2 = expr(ir_unop_find_msb, swizzle_x(r0867));
                     ir_expression *const r08F3 = sub(body.constant(int(31)), r08F2);
                     ir_expression *const r08F4 = expr(ir_triop_csel, r08F1, body.constant(int(32)), r08F3);
                     body.emit(assign(r08EE, add(r08F4, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08F6 = less(r08EE, body.constant(int(0)));
                     ir_if *f08F5 = new(mem_ctx) ir_if(operand(r08F6).val);
                     exec_list *const f08F5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F5->then_instructions;

                        ir_expression *const r08F7 = neg(r08EE);
                        body.emit(assign(r08EC, rshift(swizzle_x(r0867), r08F7), 0x01));

                        ir_expression *const r08F8 = bit_and(r08EE, body.constant(int(31)));
                        body.emit(assign(r08ED, lshift(swizzle_x(r0867), r08F8), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08F5->else_instructions;

                        body.emit(assign(r08EC, lshift(swizzle_x(r0867), r08EE), 0x01));

                        body.emit(assign(r08ED, body.constant(0u), 0x01));


                     body.instructions = f08F5_parent_instructions;
                     body.emit(f08F5);

                     /* END IF */

                     body.emit(assign(r08EB, sub(body.constant(int(-31)), r08EE), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08EF->else_instructions;

                     ir_expression *const r08F9 = equal(r0878, body.constant(0u));
                     ir_expression *const r08FA = expr(ir_unop_find_msb, r0878);
                     ir_expression *const r08FB = sub(body.constant(int(31)), r08FA);
                     ir_expression *const r08FC = expr(ir_triop_csel, r08F9, body.constant(int(32)), r08FB);
                     body.emit(assign(r08EE, add(r08FC, body.constant(int(-11))), 0x01));

                     ir_expression *const r08FD = equal(r08EE, body.constant(int(0)));
                     ir_expression *const r08FE = lshift(r0878, r08EE);
                     ir_expression *const r08FF = neg(r08EE);
                     ir_expression *const r0900 = bit_and(r08FF, body.constant(int(31)));
                     ir_expression *const r0901 = rshift(swizzle_x(r0867), r0900);
                     ir_expression *const r0902 = bit_or(r08FE, r0901);
                     body.emit(assign(r08EC, expr(ir_triop_csel, r08FD, r0878, r0902), 0x01));

                     body.emit(assign(r08ED, lshift(swizzle_x(r0867), r08EE), 0x01));

                     body.emit(assign(r08EB, sub(body.constant(int(1)), r08EE), 0x01));


                  body.instructions = f08EF_parent_instructions;
                  body.emit(f08EF);

                  /* END IF */

                  body.emit(assign(r086B, r08EB, 0x01));

                  body.emit(assign(r086D, r08EC, 0x01));

                  body.emit(assign(r086E, r08ED, 0x01));


               body.instructions = f08E7_parent_instructions;
               body.emit(f08E7);

               /* END IF */


            body.instructions = f08E5_parent_instructions;
            body.emit(f08E5);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0903 = new(mem_ctx) ir_if(operand(r0868).val);
            exec_list *const f0903_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0903->then_instructions;

               ir_expression *const r0904 = add(r086C, r086B);
               body.emit(assign(r0871, add(r0904, body.constant(int(-1024))), 0x01));

               body.emit(assign(r086F, bit_or(r086F, body.constant(1048576u)), 0x01));

               ir_variable *const r0905 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0906 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0906, lshift(r086E, body.constant(int(12))), 0x01));

               ir_expression *const r0907 = lshift(r086D, body.constant(int(12)));
               ir_expression *const r0908 = rshift(r086E, body.constant(int(20)));
               body.emit(assign(r0905, bit_or(r0907, r0908), 0x01));

               body.emit(assign(r086D, r0905, 0x01));

               body.emit(assign(r086E, r0906, 0x01));

               ir_variable *const r0909 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0909);
               ir_variable *const r090A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r090A);
               ir_variable *const r090B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r090B);
               ir_variable *const r090C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r090C, bit_and(r0870, body.constant(65535u)), 0x01));

               ir_variable *const r090D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r090D, rshift(r0870, body.constant(int(16))), 0x01));

               ir_variable *const r090E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r090E, bit_and(r0906, body.constant(65535u)), 0x01));

               ir_variable *const r090F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r090F, rshift(r0906, body.constant(int(16))), 0x01));

               ir_variable *const r0910 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0910, mul(r090D, r090E), 0x01));

               ir_expression *const r0911 = mul(r090C, r090F);
               body.emit(assign(r090A, add(r0911, r0910), 0x01));

               ir_expression *const r0912 = mul(r090D, r090F);
               ir_expression *const r0913 = less(r090A, r0910);
               ir_expression *const r0914 = expr(ir_unop_b2i, r0913);
               ir_expression *const r0915 = expr(ir_unop_i2u, r0914);
               ir_expression *const r0916 = lshift(r0915, body.constant(int(16)));
               ir_expression *const r0917 = rshift(r090A, body.constant(int(16)));
               ir_expression *const r0918 = add(r0916, r0917);
               body.emit(assign(r0909, add(r0912, r0918), 0x01));

               body.emit(assign(r090A, lshift(r090A, body.constant(int(16))), 0x01));

               ir_expression *const r0919 = mul(r090C, r090E);
               body.emit(assign(r090B, add(r0919, r090A), 0x01));

               ir_expression *const r091A = less(r090B, r090A);
               ir_expression *const r091B = expr(ir_unop_b2i, r091A);
               ir_expression *const r091C = expr(ir_unop_i2u, r091B);
               body.emit(assign(r0909, add(r0909, r091C), 0x01));

               ir_variable *const r091D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r091D);
               ir_variable *const r091E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r091E);
               ir_variable *const r091F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r091F);
               ir_variable *const r0920 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0920, bit_and(r0870, body.constant(65535u)), 0x01));

               ir_variable *const r0921 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0921, rshift(r0870, body.constant(int(16))), 0x01));

               ir_variable *const r0922 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0922, bit_and(r0905, body.constant(65535u)), 0x01));

               ir_variable *const r0923 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0923, rshift(r0905, body.constant(int(16))), 0x01));

               ir_variable *const r0924 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0924, mul(r0921, r0922), 0x01));

               ir_expression *const r0925 = mul(r0920, r0923);
               body.emit(assign(r091E, add(r0925, r0924), 0x01));

               ir_expression *const r0926 = mul(r0921, r0923);
               ir_expression *const r0927 = less(r091E, r0924);
               ir_expression *const r0928 = expr(ir_unop_b2i, r0927);
               ir_expression *const r0929 = expr(ir_unop_i2u, r0928);
               ir_expression *const r092A = lshift(r0929, body.constant(int(16)));
               ir_expression *const r092B = rshift(r091E, body.constant(int(16)));
               ir_expression *const r092C = add(r092A, r092B);
               body.emit(assign(r091D, add(r0926, r092C), 0x01));

               body.emit(assign(r091E, lshift(r091E, body.constant(int(16))), 0x01));

               ir_expression *const r092D = mul(r0920, r0922);
               body.emit(assign(r091F, add(r092D, r091E), 0x01));

               ir_expression *const r092E = less(r091F, r091E);
               ir_expression *const r092F = expr(ir_unop_b2i, r092E);
               ir_expression *const r0930 = expr(ir_unop_i2u, r092F);
               body.emit(assign(r091D, add(r091D, r0930), 0x01));

               ir_variable *const r0931 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0931, add(r091F, r0909), 0x01));

               ir_variable *const r0932 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0932);
               ir_variable *const r0933 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0933);
               ir_variable *const r0934 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0934);
               ir_variable *const r0935 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0935, bit_and(r086F, body.constant(65535u)), 0x01));

               ir_variable *const r0936 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0936, rshift(r086F, body.constant(int(16))), 0x01));

               ir_variable *const r0937 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0937, bit_and(r0905, body.constant(65535u)), 0x01));

               ir_variable *const r0938 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0938, rshift(r0905, body.constant(int(16))), 0x01));

               ir_variable *const r0939 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0939, mul(r0936, r0937), 0x01));

               ir_expression *const r093A = mul(r0935, r0938);
               body.emit(assign(r0933, add(r093A, r0939), 0x01));

               ir_expression *const r093B = mul(r0936, r0938);
               ir_expression *const r093C = less(r0933, r0939);
               ir_expression *const r093D = expr(ir_unop_b2i, r093C);
               ir_expression *const r093E = expr(ir_unop_i2u, r093D);
               ir_expression *const r093F = lshift(r093E, body.constant(int(16)));
               ir_expression *const r0940 = rshift(r0933, body.constant(int(16)));
               ir_expression *const r0941 = add(r093F, r0940);
               body.emit(assign(r0932, add(r093B, r0941), 0x01));

               body.emit(assign(r0933, lshift(r0933, body.constant(int(16))), 0x01));

               ir_expression *const r0942 = mul(r0935, r0937);
               body.emit(assign(r0934, add(r0942, r0933), 0x01));

               ir_expression *const r0943 = less(r0934, r0933);
               ir_expression *const r0944 = expr(ir_unop_b2i, r0943);
               ir_expression *const r0945 = expr(ir_unop_i2u, r0944);
               body.emit(assign(r0932, add(r0932, r0945), 0x01));

               ir_variable *const r0946 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0947 = less(r0931, r091F);
               ir_expression *const r0948 = expr(ir_unop_b2i, r0947);
               ir_expression *const r0949 = expr(ir_unop_i2u, r0948);
               ir_expression *const r094A = add(r091D, r0949);
               body.emit(assign(r0946, add(r0934, r094A), 0x01));

               ir_variable *const r094B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r094B);
               ir_variable *const r094C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r094C);
               ir_variable *const r094D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r094D);
               ir_variable *const r094E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r094E, bit_and(r086F, body.constant(65535u)), 0x01));

               ir_variable *const r094F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r094F, rshift(r086F, body.constant(int(16))), 0x01));

               ir_variable *const r0950 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0950, bit_and(r0906, body.constant(65535u)), 0x01));

               ir_variable *const r0951 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0951, rshift(r0906, body.constant(int(16))), 0x01));

               ir_variable *const r0952 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0952, mul(r094F, r0950), 0x01));

               ir_expression *const r0953 = mul(r094E, r0951);
               body.emit(assign(r094C, add(r0953, r0952), 0x01));

               ir_expression *const r0954 = mul(r094F, r0951);
               ir_expression *const r0955 = less(r094C, r0952);
               ir_expression *const r0956 = expr(ir_unop_b2i, r0955);
               ir_expression *const r0957 = expr(ir_unop_i2u, r0956);
               ir_expression *const r0958 = lshift(r0957, body.constant(int(16)));
               ir_expression *const r0959 = rshift(r094C, body.constant(int(16)));
               ir_expression *const r095A = add(r0958, r0959);
               body.emit(assign(r094B, add(r0954, r095A), 0x01));

               body.emit(assign(r094C, lshift(r094C, body.constant(int(16))), 0x01));

               ir_expression *const r095B = mul(r094E, r0950);
               body.emit(assign(r094D, add(r095B, r094C), 0x01));

               ir_expression *const r095C = less(r094D, r094C);
               ir_expression *const r095D = expr(ir_unop_b2i, r095C);
               ir_expression *const r095E = expr(ir_unop_i2u, r095D);
               body.emit(assign(r094B, add(r094B, r095E), 0x01));

               ir_variable *const r095F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095F, add(r094D, r0931), 0x01));

               ir_variable *const r0960 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0961 = less(r095F, r094D);
               ir_expression *const r0962 = expr(ir_unop_b2i, r0961);
               ir_expression *const r0963 = expr(ir_unop_i2u, r0962);
               ir_expression *const r0964 = add(r094B, r0963);
               body.emit(assign(r0960, add(r0946, r0964), 0x01));

               ir_variable *const r0965 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0966 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0966, add(r0960, r0870), 0x01));

               ir_expression *const r0967 = less(r0946, r0934);
               ir_expression *const r0968 = expr(ir_unop_b2i, r0967);
               ir_expression *const r0969 = expr(ir_unop_i2u, r0968);
               ir_expression *const r096A = add(r0932, r0969);
               ir_expression *const r096B = less(r0960, r0946);
               ir_expression *const r096C = expr(ir_unop_b2i, r096B);
               ir_expression *const r096D = expr(ir_unop_i2u, r096C);
               ir_expression *const r096E = add(r096A, r096D);
               ir_expression *const r096F = add(r096E, r086F);
               ir_expression *const r0970 = less(r0966, r0960);
               ir_expression *const r0971 = expr(ir_unop_b2i, r0970);
               ir_expression *const r0972 = expr(ir_unop_i2u, r0971);
               body.emit(assign(r0965, add(r096F, r0972), 0x01));

               body.emit(assign(r0874, r0965, 0x01));

               body.emit(assign(r0873, r0966, 0x01));

               ir_expression *const r0973 = nequal(r090B, body.constant(0u));
               ir_expression *const r0974 = expr(ir_unop_b2i, r0973);
               ir_expression *const r0975 = expr(ir_unop_i2u, r0974);
               body.emit(assign(r0872, bit_or(r095F, r0975), 0x01));

               /* IF CONDITION */
               ir_expression *const r0977 = gequal(r0965, body.constant(2097152u));
               ir_if *f0976 = new(mem_ctx) ir_if(operand(r0977).val);
               exec_list *const f0976_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0976->then_instructions;

                  ir_variable *const r0978 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0978);
                  body.emit(assign(r0978, lshift(r0966, body.constant(int(31))), 0x01));

                  ir_expression *const r0979 = nequal(r0872, body.constant(0u));
                  ir_expression *const r097A = expr(ir_unop_b2i, r0979);
                  ir_expression *const r097B = expr(ir_unop_i2u, r097A);
                  body.emit(assign(r0978, bit_or(r0978, r097B), 0x01));

                  body.emit(assign(r0874, rshift(r0965, body.constant(int(1))), 0x01));

                  ir_expression *const r097C = lshift(r0965, body.constant(int(31)));
                  ir_expression *const r097D = rshift(r0966, body.constant(int(1)));
                  body.emit(assign(r0873, bit_or(r097C, r097D), 0x01));

                  body.emit(assign(r0872, r0978, 0x01));

                  body.emit(assign(r0871, add(r0871, body.constant(int(1))), 0x01));


               body.instructions = f0976_parent_instructions;
               body.emit(f0976);

               /* END IF */

               ir_variable *const r097E = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r097E, r0871, 0x01));

               ir_variable *const r097F = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r097F, r0874, 0x01));

               ir_variable *const r0980 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0980, r0873, 0x01));

               ir_variable *const r0981 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r0981, r0872, 0x01));

               ir_variable *const r0982 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0982, body.constant(true), 0x01));

               ir_variable *const r0983 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0984 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0984);
               ir_expression *const r0985 = expr(ir_unop_u2i, r0872);
               body.emit(assign(r0984, less(r0985, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0987 = gequal(r0871, body.constant(int(2045)));
               ir_if *f0986 = new(mem_ctx) ir_if(operand(r0987).val);
               exec_list *const f0986_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0986->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0989 = less(body.constant(int(2045)), r0871);
                  ir_expression *const r098A = equal(r0871, body.constant(int(2045)));
                  ir_expression *const r098B = equal(body.constant(2097151u), r0874);
                  ir_expression *const r098C = equal(body.constant(4294967295u), r0873);
                  ir_expression *const r098D = logic_and(r098B, r098C);
                  ir_expression *const r098E = logic_and(r098A, r098D);
                  ir_expression *const r098F = logic_and(r098E, r0984);
                  ir_expression *const r0990 = logic_or(r0989, r098F);
                  ir_if *f0988 = new(mem_ctx) ir_if(operand(r0990).val);
                  exec_list *const f0988_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0988->then_instructions;

                     ir_variable *const r0991 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0991);
                     ir_expression *const r0992 = lshift(r086A, body.constant(int(31)));
                     body.emit(assign(r0991, add(r0992, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r0991, body.constant(0u), 0x01));

                     body.emit(assign(r0983, r0991, 0x03));

                     body.emit(assign(r0982, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0988->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0994 = less(r0871, body.constant(int(0)));
                     ir_if *f0993 = new(mem_ctx) ir_if(operand(r0994).val);
                     exec_list *const f0993_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0993->then_instructions;

                        ir_variable *const r0995 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0995, r0872, 0x01));

                        ir_variable *const r0996 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0996, neg(r0871), 0x01));

                        ir_variable *const r0997 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0997);
                        ir_variable *const r0998 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r0998);
                        ir_variable *const r0999 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0999);
                        ir_variable *const r099A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r099B = neg(r0996);
                        body.emit(assign(r099A, bit_and(r099B, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r099D = less(r0996, body.constant(int(32)));
                        ir_if *f099C = new(mem_ctx) ir_if(operand(r099D).val);
                        exec_list *const f099C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f099C->then_instructions;

                           body.emit(assign(r0997, lshift(r0873, r099A), 0x01));

                           ir_expression *const r099E = lshift(r0874, r099A);
                           ir_expression *const r099F = rshift(r0873, r0996);
                           body.emit(assign(r0998, bit_or(r099E, r099F), 0x01));

                           body.emit(assign(r0999, rshift(r0874, r0996), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f099C->else_instructions;

                           body.emit(assign(r0995, bit_or(r0872, r0873), 0x01));

                           ir_expression *const r09A0 = less(r0996, body.constant(int(64)));
                           ir_expression *const r09A1 = lshift(r0874, r099A);
                           ir_expression *const r09A2 = equal(r0996, body.constant(int(64)));
                           ir_expression *const r09A3 = nequal(r0874, body.constant(0u));
                           ir_expression *const r09A4 = expr(ir_unop_b2i, r09A3);
                           ir_expression *const r09A5 = expr(ir_unop_i2u, r09A4);
                           ir_expression *const r09A6 = expr(ir_triop_csel, r09A2, r0874, r09A5);
                           body.emit(assign(r0997, expr(ir_triop_csel, r09A0, r09A1, r09A6), 0x01));

                           ir_expression *const r09A7 = less(r0996, body.constant(int(64)));
                           ir_expression *const r09A8 = bit_and(r0996, body.constant(int(31)));
                           ir_expression *const r09A9 = rshift(r0874, r09A8);
                           body.emit(assign(r0998, expr(ir_triop_csel, r09A7, r09A9, body.constant(0u)), 0x01));

                           body.emit(assign(r0999, body.constant(0u), 0x01));


                        body.instructions = f099C_parent_instructions;
                        body.emit(f099C);

                        /* END IF */

                        ir_expression *const r09AA = nequal(r0995, body.constant(0u));
                        ir_expression *const r09AB = expr(ir_unop_b2i, r09AA);
                        ir_expression *const r09AC = expr(ir_unop_i2u, r09AB);
                        body.emit(assign(r0997, bit_or(r0997, r09AC), 0x01));

                        ir_variable *const r09AD = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r09AE = equal(r0996, body.constant(int(0)));
                        ir_expression *const r09AF = equal(r0996, body.constant(int(32)));
                        ir_expression *const r09B0 = expr(ir_triop_csel, r09AF, body.constant(0u), r0999);
                        body.emit(assign(r09AD, expr(ir_triop_csel, r09AE, r0874, r09B0), 0x01));

                        body.emit(assign(r0999, r09AD, 0x01));

                        ir_variable *const r09B1 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r09B2 = equal(r0996, body.constant(int(0)));
                        ir_expression *const r09B3 = equal(r0996, body.constant(int(32)));
                        ir_expression *const r09B4 = expr(ir_triop_csel, r09B3, r0874, r0998);
                        body.emit(assign(r09B1, expr(ir_triop_csel, r09B2, r0873, r09B4), 0x01));

                        body.emit(assign(r0998, r09B1, 0x01));

                        ir_variable *const r09B5 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r09B6 = equal(r0996, body.constant(int(0)));
                        ir_expression *const r09B7 = equal(r0996, body.constant(int(32)));
                        ir_expression *const r09B8 = expr(ir_triop_csel, r09B7, r0873, r0997);
                        body.emit(assign(r09B5, expr(ir_triop_csel, r09B6, r0995, r09B8), 0x01));

                        body.emit(assign(r0997, r09B5, 0x01));

                        body.emit(assign(r097F, r09AD, 0x01));

                        body.emit(assign(r0980, r09B1, 0x01));

                        body.emit(assign(r0981, r09B5, 0x01));

                        body.emit(assign(r097E, body.constant(int(0)), 0x01));

                        body.emit(assign(r0984, less(r09B5, body.constant(0u)), 0x01));


                     body.instructions = f0993_parent_instructions;
                     body.emit(f0993);

                     /* END IF */


                  body.instructions = f0988_parent_instructions;
                  body.emit(f0988);

                  /* END IF */


               body.instructions = f0986_parent_instructions;
               body.emit(f0986);

               /* END IF */

               /* IF CONDITION */
               ir_if *f09B9 = new(mem_ctx) ir_if(operand(r0982).val);
               exec_list *const f09B9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09B9->then_instructions;

                  /* IF CONDITION */
                  ir_if *f09BA = new(mem_ctx) ir_if(operand(r0984).val);
                  exec_list *const f09BA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09BA->then_instructions;

                     ir_variable *const r09BB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r09BB, add(r0980, body.constant(1u)), 0x01));

                     ir_expression *const r09BC = less(r09BB, r0980);
                     ir_expression *const r09BD = expr(ir_unop_b2i, r09BC);
                     ir_expression *const r09BE = expr(ir_unop_i2u, r09BD);
                     body.emit(assign(r097F, add(r097F, r09BE), 0x01));

                     ir_expression *const r09BF = equal(r0981, body.constant(0u));
                     ir_expression *const r09C0 = expr(ir_unop_b2i, r09BF);
                     ir_expression *const r09C1 = expr(ir_unop_i2u, r09C0);
                     ir_expression *const r09C2 = add(r0981, r09C1);
                     ir_expression *const r09C3 = bit_and(r09C2, body.constant(1u));
                     ir_expression *const r09C4 = expr(ir_unop_bit_not, r09C3);
                     body.emit(assign(r0980, bit_and(r09BB, r09C4), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09BA->else_instructions;

                     ir_expression *const r09C5 = bit_or(r097F, r0980);
                     ir_expression *const r09C6 = equal(r09C5, body.constant(0u));
                     body.emit(assign(r097E, expr(ir_triop_csel, r09C6, body.constant(int(0)), r097E), 0x01));


                  body.instructions = f09BA_parent_instructions;
                  body.emit(f09BA);

                  /* END IF */

                  ir_variable *const r09C7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r09C7);
                  ir_expression *const r09C8 = lshift(r086A, body.constant(int(31)));
                  ir_expression *const r09C9 = expr(ir_unop_i2u, r097E);
                  ir_expression *const r09CA = lshift(r09C9, body.constant(int(20)));
                  ir_expression *const r09CB = add(r09C8, r09CA);
                  body.emit(assign(r09C7, add(r09CB, r097F), 0x02));

                  body.emit(assign(r09C7, r0980, 0x01));

                  body.emit(assign(r0983, r09C7, 0x03));

                  body.emit(assign(r0982, body.constant(false), 0x01));


               body.instructions = f09B9_parent_instructions;
               body.emit(f09B9);

               /* END IF */

               body.emit(assign(r0869, r0983, 0x03));

               body.emit(assign(r0868, body.constant(false), 0x01));


            body.instructions = f0903_parent_instructions;
            body.emit(f0903);

            /* END IF */


         body.instructions = f08E4_parent_instructions;
         body.emit(f08E4);

         /* END IF */


      body.instructions = f08A6_parent_instructions;
      body.emit(f08A6);

      /* END IF */


   body.instructions = f0881_parent_instructions;
   body.emit(f0881);

   /* END IF */

   body.emit(ret(r0869));

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

   ir_variable *const r09CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09CC);
   ir_variable *const r09CD = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09CD);
   ir_variable *const r09CE = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r09CE);
   ir_variable *const r09CF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09CF);
   ir_variable *const r09D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09D0);
   ir_expression *const r09D1 = equal(r09CE, body.constant(int(0)));
   ir_expression *const r09D2 = less(r09CE, body.constant(int(32)));
   ir_expression *const r09D3 = neg(r09CE);
   ir_expression *const r09D4 = bit_and(r09D3, body.constant(int(31)));
   ir_expression *const r09D5 = lshift(r09CC, r09D4);
   ir_expression *const r09D6 = rshift(r09CD, r09CE);
   ir_expression *const r09D7 = bit_or(r09D5, r09D6);
   ir_expression *const r09D8 = less(r09CE, body.constant(int(64)));
   ir_expression *const r09D9 = bit_and(r09CE, body.constant(int(31)));
   ir_expression *const r09DA = rshift(r09CC, r09D9);
   ir_expression *const r09DB = expr(ir_triop_csel, r09D8, r09DA, body.constant(0u));
   ir_expression *const r09DC = expr(ir_triop_csel, r09D2, r09D7, r09DB);
   body.emit(assign(r09D0, expr(ir_triop_csel, r09D1, r09CC, r09DC), 0x01));

   ir_expression *const r09DD = equal(r09CE, body.constant(int(0)));
   ir_expression *const r09DE = less(r09CE, body.constant(int(32)));
   ir_expression *const r09DF = rshift(r09CC, r09CE);
   ir_expression *const r09E0 = expr(ir_triop_csel, r09DE, r09DF, body.constant(0u));
   body.emit(assign(r09CF, expr(ir_triop_csel, r09DD, r09CC, r09E0), 0x01));

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

   ir_variable *const r09E1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r09E1);
   ir_variable *const r09E2 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r09E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r09E3);
   ir_variable *const r09E4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r09E4);
   body.emit(assign(r09E4, swizzle_x(r09E1), 0x01));

   ir_variable *const r09E5 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r09E5, bit_and(swizzle_y(r09E1), body.constant(1048575u)), 0x01));

   body.emit(assign(r09E3, r09E5, 0x01));

   ir_variable *const r09E6 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r09E7 = rshift(swizzle_y(r09E1), body.constant(int(20)));
   ir_expression *const r09E8 = bit_and(r09E7, body.constant(2047u));
   body.emit(assign(r09E6, expr(ir_unop_u2i, r09E8), 0x01));

   ir_variable *const r09E9 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r09E9, rshift(swizzle_y(r09E1), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r09EB = nequal(r09E9, body.constant(0u));
   ir_if *f09EA = new(mem_ctx) ir_if(operand(r09EB).val);
   exec_list *const f09EA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09EA->then_instructions;

      body.emit(assign(r09E2, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09EA->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09ED = equal(r09E6, body.constant(int(2047)));
      ir_expression *const r09EE = bit_or(r09E5, swizzle_x(r09E1));
      ir_expression *const r09EF = nequal(r09EE, body.constant(0u));
      ir_expression *const r09F0 = logic_and(r09ED, r09EF);
      ir_if *f09EC = new(mem_ctx) ir_if(operand(r09F0).val);
      exec_list *const f09EC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09EC->then_instructions;

         body.emit(assign(r09E2, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09EC->else_instructions;

         /* IF CONDITION */
         ir_expression *const r09F2 = nequal(r09E6, body.constant(int(0)));
         ir_if *f09F1 = new(mem_ctx) ir_if(operand(r09F2).val);
         exec_list *const f09F1_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09F1->then_instructions;

            body.emit(assign(r09E3, bit_or(r09E5, body.constant(1048576u)), 0x01));


         body.instructions = f09F1_parent_instructions;
         body.emit(f09F1);

         /* END IF */

         ir_variable *const r09F3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r09F3, sub(body.constant(int(1063)), r09E6), 0x01));

         /* IF CONDITION */
         ir_expression *const r09F5 = less(body.constant(int(0)), r09F3);
         ir_if *f09F4 = new(mem_ctx) ir_if(operand(r09F5).val);
         exec_list *const f09F4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09F4->then_instructions;

            ir_variable *const r09F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r09F6);
            ir_variable *const r09F7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r09F8 = neg(r09F3);
            body.emit(assign(r09F7, bit_and(r09F8, body.constant(int(31))), 0x01));

            ir_expression *const r09F9 = bit_or(r09E3, swizzle_x(r09E1));
            ir_expression *const r09FA = nequal(r09F9, body.constant(0u));
            ir_expression *const r09FB = expr(ir_unop_b2i, r09FA);
            body.emit(assign(r09F6, expr(ir_unop_i2u, r09FB), 0x01));

            ir_variable *const r09FC = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r09FD = equal(r09F3, body.constant(int(0)));
            ir_expression *const r09FE = less(r09F3, body.constant(int(32)));
            ir_expression *const r09FF = lshift(r09E3, r09F7);
            ir_expression *const r0A00 = rshift(swizzle_x(r09E1), r09F3);
            ir_expression *const r0A01 = bit_or(r09FF, r0A00);
            ir_expression *const r0A02 = lshift(swizzle_x(r09E1), r09F7);
            ir_expression *const r0A03 = nequal(r0A02, body.constant(0u));
            ir_expression *const r0A04 = expr(ir_unop_b2i, r0A03);
            ir_expression *const r0A05 = expr(ir_unop_i2u, r0A04);
            ir_expression *const r0A06 = bit_or(r0A01, r0A05);
            ir_expression *const r0A07 = equal(r09F3, body.constant(int(32)));
            ir_expression *const r0A08 = nequal(swizzle_x(r09E1), body.constant(0u));
            ir_expression *const r0A09 = expr(ir_unop_b2i, r0A08);
            ir_expression *const r0A0A = expr(ir_unop_i2u, r0A09);
            ir_expression *const r0A0B = bit_or(r09E3, r0A0A);
            ir_expression *const r0A0C = less(r09F3, body.constant(int(64)));
            ir_expression *const r0A0D = bit_and(r09F3, body.constant(int(31)));
            ir_expression *const r0A0E = rshift(r09E3, r0A0D);
            ir_expression *const r0A0F = lshift(r09E3, r09F7);
            ir_expression *const r0A10 = bit_or(r0A0F, swizzle_x(r09E1));
            ir_expression *const r0A11 = nequal(r0A10, body.constant(0u));
            ir_expression *const r0A12 = expr(ir_unop_b2i, r0A11);
            ir_expression *const r0A13 = expr(ir_unop_i2u, r0A12);
            ir_expression *const r0A14 = bit_or(r0A0E, r0A13);
            ir_expression *const r0A15 = expr(ir_triop_csel, r0A0C, r0A14, r09F6);
            ir_expression *const r0A16 = expr(ir_triop_csel, r0A07, r0A0B, r0A15);
            ir_expression *const r0A17 = expr(ir_triop_csel, r09FE, r0A06, r0A16);
            body.emit(assign(r09FC, expr(ir_triop_csel, r09FD, swizzle_x(r09E1), r0A17), 0x01));

            body.emit(assign(r09F6, r09FC, 0x01));

            ir_expression *const r0A18 = less(r09F3, body.constant(int(32)));
            ir_expression *const r0A19 = rshift(r09E3, r09F3);
            ir_expression *const r0A1A = equal(r09F3, body.constant(int(0)));
            ir_expression *const r0A1B = expr(ir_triop_csel, r0A1A, r09E3, body.constant(0u));
            body.emit(assign(r09E3, expr(ir_triop_csel, r0A18, r0A19, r0A1B), 0x01));

            body.emit(assign(r09E4, r09FC, 0x01));


         body.instructions = f09F4_parent_instructions;
         body.emit(f09F4);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A1D = bit_and(r09E3, body.constant(4294963200u));
         ir_expression *const r0A1E = nequal(r0A1D, body.constant(0u));
         ir_if *f0A1C = new(mem_ctx) ir_if(operand(r0A1E).val);
         exec_list *const f0A1C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A1C->then_instructions;

            ir_variable *const r0A1F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A21 = nequal(r09E9, body.constant(0u));
            ir_if *f0A20 = new(mem_ctx) ir_if(operand(r0A21).val);
            exec_list *const f0A20_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A20->then_instructions;

               body.emit(assign(r0A1F, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A20->else_instructions;

               body.emit(assign(r0A1F, body.constant(4294967295u), 0x01));


            body.instructions = f0A20_parent_instructions;
            body.emit(f0A20);

            /* END IF */

            body.emit(assign(r09E2, r0A1F, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A1C->else_instructions;

            ir_variable *const r0A22 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r0A23 = lshift(r09E3, body.constant(int(20)));
            ir_expression *const r0A24 = rshift(r09E4, body.constant(int(12)));
            body.emit(assign(r0A22, bit_or(r0A23, r0A24), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A26 = nequal(r09E9, body.constant(0u));
            ir_expression *const r0A27 = nequal(r0A22, body.constant(0u));
            ir_expression *const r0A28 = logic_and(r0A26, r0A27);
            ir_if *f0A25 = new(mem_ctx) ir_if(operand(r0A28).val);
            exec_list *const f0A25_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A25->then_instructions;

               ir_variable *const r0A29 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0A2B = nequal(r09E9, body.constant(0u));
               ir_if *f0A2A = new(mem_ctx) ir_if(operand(r0A2B).val);
               exec_list *const f0A2A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A2A->then_instructions;

                  body.emit(assign(r0A29, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A2A->else_instructions;

                  body.emit(assign(r0A29, body.constant(4294967295u), 0x01));


               body.instructions = f0A2A_parent_instructions;
               body.emit(f0A2A);

               /* END IF */

               body.emit(assign(r09E2, r0A29, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A25->else_instructions;

               body.emit(assign(r09E2, r0A22, 0x01));


            body.instructions = f0A25_parent_instructions;
            body.emit(f0A25);

            /* END IF */


         body.instructions = f0A1C_parent_instructions;
         body.emit(f0A1C);

         /* END IF */


      body.instructions = f09EC_parent_instructions;
      body.emit(f09EC);

      /* END IF */


   body.instructions = f09EA_parent_instructions;
   body.emit(f09EA);

   /* END IF */

   body.emit(ret(r09E2));

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

   ir_variable *const r0A2C = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A2C);
   ir_variable *const r0A2D = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A2E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0A2E);
   ir_variable *const r0A2F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0A2F);
   /* IF CONDITION */
   ir_expression *const r0A31 = equal(r0A2C, body.constant(0u));
   ir_if *f0A30 = new(mem_ctx) ir_if(operand(r0A31).val);
   exec_list *const f0A30_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A30->then_instructions;

      body.emit(assign(r0A2D, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A30->else_instructions;

      ir_variable *const r0A32 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0A33 = equal(r0A2C, body.constant(0u));
      ir_expression *const r0A34 = expr(ir_unop_find_msb, r0A2C);
      ir_expression *const r0A35 = sub(body.constant(int(31)), r0A34);
      ir_expression *const r0A36 = expr(ir_triop_csel, r0A33, body.constant(int(32)), r0A35);
      body.emit(assign(r0A32, add(r0A36, body.constant(int(21))), 0x01));

      body.emit(assign(r0A2F, body.constant(0u), 0x01));

      body.emit(assign(r0A2E, body.constant(0u), 0x01));

      ir_variable *const r0A37 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0A38 = neg(r0A32);
      body.emit(assign(r0A37, bit_and(r0A38, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A3A = equal(r0A32, body.constant(int(0)));
      ir_if *f0A39 = new(mem_ctx) ir_if(operand(r0A3A).val);
      exec_list *const f0A39_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A39->then_instructions;

         body.emit(assign(r0A2F, body.constant(0u), 0x01));

         body.emit(assign(r0A2E, r0A2C, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A39->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A3C = less(r0A32, body.constant(int(32)));
         ir_if *f0A3B = new(mem_ctx) ir_if(operand(r0A3C).val);
         exec_list *const f0A3B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A3B->then_instructions;

            body.emit(assign(r0A2F, rshift(r0A2C, r0A37), 0x01));

            body.emit(assign(r0A2E, lshift(r0A2C, r0A32), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A3B->else_instructions;

            ir_variable *const r0A3D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A3F = less(r0A32, body.constant(int(64)));
            ir_if *f0A3E = new(mem_ctx) ir_if(operand(r0A3F).val);
            exec_list *const f0A3E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A3E->then_instructions;

               ir_expression *const r0A40 = add(r0A32, body.constant(int(-32)));
               body.emit(assign(r0A3D, lshift(r0A2C, r0A40), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A3E->else_instructions;

               body.emit(assign(r0A3D, body.constant(0u), 0x01));


            body.instructions = f0A3E_parent_instructions;
            body.emit(f0A3E);

            /* END IF */

            body.emit(assign(r0A2F, r0A3D, 0x01));

            body.emit(assign(r0A2E, body.constant(0u), 0x01));


         body.instructions = f0A3B_parent_instructions;
         body.emit(f0A3B);

         /* END IF */


      body.instructions = f0A39_parent_instructions;
      body.emit(f0A39);

      /* END IF */

      ir_variable *const r0A41 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A41);
      ir_expression *const r0A42 = sub(body.constant(int(1074)), r0A32);
      ir_expression *const r0A43 = expr(ir_unop_i2u, r0A42);
      ir_expression *const r0A44 = lshift(r0A43, body.constant(int(20)));
      body.emit(assign(r0A41, add(r0A44, r0A2F), 0x02));

      body.emit(assign(r0A41, r0A2E, 0x01));

      body.emit(assign(r0A2D, r0A41, 0x03));


   body.instructions = f0A30_parent_instructions;
   body.emit(f0A30);

   /* END IF */

   body.emit(ret(r0A2D));

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

   ir_variable *const r0A45 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A45);
   ir_variable *const r0A46 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A46, body.constant(true), 0x01));

   ir_variable *const r0A47 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0A48 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0A48);
   ir_variable *const r0A49 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A49);
   ir_variable *const r0A4A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A4A);
   ir_variable *const r0A4B = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A4B, bit_and(swizzle_y(r0A45), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A4A, r0A4B, 0x01));

   ir_variable *const r0A4C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A4D = rshift(swizzle_y(r0A45), body.constant(int(20)));
   ir_expression *const r0A4E = bit_and(r0A4D, body.constant(2047u));
   body.emit(assign(r0A4C, expr(ir_unop_u2i, r0A4E), 0x01));

   body.emit(assign(r0A49, rshift(swizzle_y(r0A45), body.constant(int(31))), 0x01));

   body.emit(assign(r0A48, body.constant(0u), 0x01));

   ir_variable *const r0A4F = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0A4F, add(r0A4C, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A51 = gequal(r0A4F, body.constant(int(0)));
   ir_if *f0A50 = new(mem_ctx) ir_if(operand(r0A51).val);
   exec_list *const f0A50_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A50->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A53 = less(body.constant(int(1054)), r0A4C);
      ir_if *f0A52 = new(mem_ctx) ir_if(operand(r0A53).val);
      exec_list *const f0A52_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A52->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A55 = equal(r0A4C, body.constant(int(2047)));
         ir_expression *const r0A56 = bit_or(r0A4B, swizzle_x(r0A45));
         ir_expression *const r0A57 = expr(ir_unop_u2i, r0A56);
         ir_expression *const r0A58 = expr(ir_unop_i2b, r0A57);
         ir_expression *const r0A59 = logic_and(r0A55, r0A58);
         ir_if *f0A54 = new(mem_ctx) ir_if(operand(r0A59).val);
         exec_list *const f0A54_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A54->then_instructions;

            body.emit(assign(r0A49, body.constant(0u), 0x01));


         body.instructions = f0A54_parent_instructions;
         body.emit(f0A54);

         /* END IF */

         ir_variable *const r0A5A = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A5C = expr(ir_unop_u2i, r0A49);
         ir_expression *const r0A5D = expr(ir_unop_i2b, r0A5C);
         ir_if *f0A5B = new(mem_ctx) ir_if(operand(r0A5D).val);
         exec_list *const f0A5B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A5B->then_instructions;

            body.emit(assign(r0A5A, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A5B->else_instructions;

            body.emit(assign(r0A5A, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A5B_parent_instructions;
         body.emit(f0A5B);

         /* END IF */

         body.emit(assign(r0A47, r0A5A, 0x01));

         body.emit(assign(r0A46, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A52->else_instructions;

         ir_variable *const r0A5E = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r0A5E, bit_or(r0A4B, body.constant(1048576u)), 0x01));

         ir_expression *const r0A5F = equal(r0A4F, body.constant(int(0)));
         ir_expression *const r0A60 = lshift(r0A5E, r0A4F);
         ir_expression *const r0A61 = neg(r0A4F);
         ir_expression *const r0A62 = bit_and(r0A61, body.constant(int(31)));
         ir_expression *const r0A63 = rshift(swizzle_x(r0A45), r0A62);
         ir_expression *const r0A64 = bit_or(r0A60, r0A63);
         body.emit(assign(r0A48, expr(ir_triop_csel, r0A5F, r0A5E, r0A64), 0x01));


      body.instructions = f0A52_parent_instructions;
      body.emit(f0A52);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A50->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A66 = less(r0A4C, body.constant(int(1023)));
      ir_if *f0A65 = new(mem_ctx) ir_if(operand(r0A66).val);
      exec_list *const f0A65_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A65->then_instructions;

         body.emit(assign(r0A47, body.constant(int(0)), 0x01));

         body.emit(assign(r0A46, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A65->else_instructions;

         body.emit(assign(r0A4A, bit_or(r0A4B, body.constant(1048576u)), 0x01));

         ir_expression *const r0A67 = neg(r0A4F);
         body.emit(assign(r0A48, rshift(r0A4A, r0A67), 0x01));


      body.instructions = f0A65_parent_instructions;
      body.emit(f0A65);

      /* END IF */


   body.instructions = f0A50_parent_instructions;
   body.emit(f0A50);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0A68 = new(mem_ctx) ir_if(operand(r0A46).val);
   exec_list *const f0A68_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A68->then_instructions;

      ir_variable *const r0A69 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A6B = nequal(r0A49, body.constant(0u));
      ir_if *f0A6A = new(mem_ctx) ir_if(operand(r0A6B).val);
      exec_list *const f0A6A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A6A->then_instructions;

         ir_expression *const r0A6C = expr(ir_unop_u2i, r0A48);
         body.emit(assign(r0A69, neg(r0A6C), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A6A->else_instructions;

         body.emit(assign(r0A69, expr(ir_unop_u2i, r0A48), 0x01));


      body.instructions = f0A6A_parent_instructions;
      body.emit(f0A6A);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0A6E = less(r0A69, body.constant(int(0)));
      ir_expression *const r0A6F = expr(ir_unop_b2i, r0A6E);
      ir_expression *const r0A70 = expr(ir_unop_i2u, r0A6F);
      ir_expression *const r0A71 = bit_xor(r0A49, r0A70);
      ir_expression *const r0A72 = expr(ir_unop_u2i, r0A71);
      ir_expression *const r0A73 = expr(ir_unop_i2b, r0A72);
      ir_expression *const r0A74 = expr(ir_unop_i2b, r0A69);
      ir_expression *const r0A75 = logic_and(r0A73, r0A74);
      ir_if *f0A6D = new(mem_ctx) ir_if(operand(r0A75).val);
      exec_list *const f0A6D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A6D->then_instructions;

         ir_variable *const r0A76 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A78 = expr(ir_unop_u2i, r0A49);
         ir_expression *const r0A79 = expr(ir_unop_i2b, r0A78);
         ir_if *f0A77 = new(mem_ctx) ir_if(operand(r0A79).val);
         exec_list *const f0A77_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A77->then_instructions;

            body.emit(assign(r0A76, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A77->else_instructions;

            body.emit(assign(r0A76, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A77_parent_instructions;
         body.emit(f0A77);

         /* END IF */

         body.emit(assign(r0A47, r0A76, 0x01));

         body.emit(assign(r0A46, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A6D->else_instructions;

         body.emit(assign(r0A47, r0A69, 0x01));

         body.emit(assign(r0A46, body.constant(false), 0x01));


      body.instructions = f0A6D_parent_instructions;
      body.emit(f0A6D);

      /* END IF */


   body.instructions = f0A68_parent_instructions;
   body.emit(f0A68);

   /* END IF */

   body.emit(ret(r0A47));

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

   ir_variable *const r0A7A = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A7A);
   ir_variable *const r0A7B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A7C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0A7C);
   ir_variable *const r0A7D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0A7D);
   ir_variable *const r0A7E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0A7E);
   body.emit(assign(r0A7E, body.constant(0u), 0x01));

   body.emit(assign(r0A7D, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A80 = equal(r0A7A, body.constant(int(0)));
   ir_if *f0A7F = new(mem_ctx) ir_if(operand(r0A80).val);
   exec_list *const f0A7F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A7F->then_instructions;

      ir_variable *const r0A81 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A81);
      body.emit(assign(r0A81, body.constant(0u), 0x02));

      body.emit(assign(r0A81, body.constant(0u), 0x01));

      body.emit(assign(r0A7B, r0A81, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A7F->else_instructions;

      ir_expression *const r0A82 = less(r0A7A, body.constant(int(0)));
      ir_expression *const r0A83 = expr(ir_unop_b2i, r0A82);
      body.emit(assign(r0A7C, expr(ir_unop_i2u, r0A83), 0x01));

      ir_variable *const r0A84 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A86 = less(r0A7A, body.constant(int(0)));
      ir_if *f0A85 = new(mem_ctx) ir_if(operand(r0A86).val);
      exec_list *const f0A85_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A85->then_instructions;

         ir_expression *const r0A87 = neg(r0A7A);
         body.emit(assign(r0A84, expr(ir_unop_i2u, r0A87), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A85->else_instructions;

         body.emit(assign(r0A84, expr(ir_unop_i2u, r0A7A), 0x01));


      body.instructions = f0A85_parent_instructions;
      body.emit(f0A85);

      /* END IF */

      ir_variable *const r0A88 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0A89 = equal(r0A84, body.constant(0u));
      ir_expression *const r0A8A = expr(ir_unop_find_msb, r0A84);
      ir_expression *const r0A8B = sub(body.constant(int(31)), r0A8A);
      ir_expression *const r0A8C = expr(ir_triop_csel, r0A89, body.constant(int(32)), r0A8B);
      body.emit(assign(r0A88, add(r0A8C, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A8E = gequal(r0A88, body.constant(int(0)));
      ir_if *f0A8D = new(mem_ctx) ir_if(operand(r0A8E).val);
      exec_list *const f0A8D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A8D->then_instructions;

         body.emit(assign(r0A7E, lshift(r0A84, r0A88), 0x01));

         body.emit(assign(r0A7D, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A8D->else_instructions;

         ir_variable *const r0A8F = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r0A8F, neg(r0A88), 0x01));

         ir_expression *const r0A90 = equal(r0A8F, body.constant(int(0)));
         ir_expression *const r0A91 = less(r0A8F, body.constant(int(32)));
         ir_expression *const r0A92 = rshift(r0A84, r0A8F);
         ir_expression *const r0A93 = expr(ir_triop_csel, r0A91, r0A92, body.constant(0u));
         body.emit(assign(r0A7E, expr(ir_triop_csel, r0A90, r0A84, r0A93), 0x01));

         ir_expression *const r0A94 = equal(r0A8F, body.constant(int(0)));
         ir_expression *const r0A95 = less(r0A8F, body.constant(int(32)));
         ir_expression *const r0A96 = neg(r0A8F);
         ir_expression *const r0A97 = bit_and(r0A96, body.constant(int(31)));
         ir_expression *const r0A98 = lshift(r0A84, r0A97);
         ir_expression *const r0A99 = bit_or(r0A98, body.constant(0u));
         ir_expression *const r0A9A = less(r0A8F, body.constant(int(64)));
         ir_expression *const r0A9B = bit_and(r0A8F, body.constant(int(31)));
         ir_expression *const r0A9C = rshift(r0A84, r0A9B);
         ir_expression *const r0A9D = expr(ir_triop_csel, r0A9A, r0A9C, body.constant(0u));
         ir_expression *const r0A9E = expr(ir_triop_csel, r0A95, r0A99, r0A9D);
         body.emit(assign(r0A7D, expr(ir_triop_csel, r0A94, r0A84, r0A9E), 0x01));


      body.instructions = f0A8D_parent_instructions;
      body.emit(f0A8D);

      /* END IF */

      ir_variable *const r0A9F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A9F);
      ir_expression *const r0AA0 = lshift(r0A7C, body.constant(int(31)));
      ir_expression *const r0AA1 = sub(body.constant(int(1042)), r0A88);
      ir_expression *const r0AA2 = expr(ir_unop_i2u, r0AA1);
      ir_expression *const r0AA3 = lshift(r0AA2, body.constant(int(20)));
      ir_expression *const r0AA4 = add(r0AA0, r0AA3);
      body.emit(assign(r0A9F, add(r0AA4, r0A7E), 0x02));

      body.emit(assign(r0A9F, r0A7D, 0x01));

      body.emit(assign(r0A7B, r0A9F, 0x03));


   body.instructions = f0A7F_parent_instructions;
   body.emit(f0A7F);

   /* END IF */

   body.emit(ret(r0A7B));

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

   ir_variable *const r0AA5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AA5);
   ir_variable *const r0AA6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AA6);
   ir_variable *const r0AA7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AA7);
   ir_variable *const r0AA8 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r0AA9 = lshift(r0AA5, body.constant(int(31)));
   ir_expression *const r0AAA = expr(ir_unop_i2u, r0AA6);
   ir_expression *const r0AAB = lshift(r0AAA, body.constant(int(23)));
   ir_expression *const r0AAC = add(r0AA9, r0AAB);
   ir_expression *const r0AAD = add(r0AAC, r0AA7);
   body.emit(assign(r0AA8, expr(ir_unop_bitcast_u2f, r0AAD), 0x01));

   body.emit(ret(r0AA8));

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

   ir_variable *const r0AAE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AAE);
   ir_variable *const r0AAF = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AAF);
   ir_variable *const r0AB0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AB0);
   ir_variable *const r0AB1 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0AB1, body.constant(true), 0x01));

   ir_variable *const r0AB2 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0AB3 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0AB3);
   ir_expression *const r0AB4 = bit_and(r0AB0, body.constant(127u));
   body.emit(assign(r0AB3, expr(ir_unop_u2i, r0AB4), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AB6 = expr(ir_unop_i2u, r0AAF);
   ir_expression *const r0AB7 = gequal(r0AB6, body.constant(253u));
   ir_if *f0AB5 = new(mem_ctx) ir_if(operand(r0AB7).val);
   exec_list *const f0AB5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AB5->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0AB9 = less(body.constant(int(253)), r0AAF);
      ir_expression *const r0ABA = equal(r0AAF, body.constant(int(253)));
      ir_expression *const r0ABB = expr(ir_unop_u2i, r0AB0);
      ir_expression *const r0ABC = less(r0ABB, body.constant(int(-64)));
      ir_expression *const r0ABD = logic_and(r0ABA, r0ABC);
      ir_expression *const r0ABE = logic_or(r0AB9, r0ABD);
      ir_if *f0AB8 = new(mem_ctx) ir_if(operand(r0ABE).val);
      exec_list *const f0AB8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AB8->then_instructions;

         ir_expression *const r0ABF = lshift(r0AAE, body.constant(int(31)));
         ir_expression *const r0AC0 = add(r0ABF, body.constant(2139095040u));
         body.emit(assign(r0AB2, expr(ir_unop_bitcast_u2f, r0AC0), 0x01));

         body.emit(assign(r0AB1, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AB8->else_instructions;

         ir_variable *const r0AC1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0AC1, neg(r0AAF), 0x01));

         ir_variable *const r0AC2 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
         body.emit(assign(r0AC2, less(r0AAF, body.constant(int(0))), 0x01));

         ir_variable *const r0AC3 = body.make_temp(glsl_type::uint_type, "mix_retval");
         ir_expression *const r0AC4 = neg(r0AAF);
         ir_expression *const r0AC5 = less(r0AC4, body.constant(int(32)));
         ir_expression *const r0AC6 = rshift(r0AB0, r0AC1);
         ir_expression *const r0AC7 = neg(r0AC1);
         ir_expression *const r0AC8 = bit_and(r0AC7, body.constant(int(31)));
         ir_expression *const r0AC9 = lshift(r0AB0, r0AC8);
         ir_expression *const r0ACA = nequal(r0AC9, body.constant(0u));
         ir_expression *const r0ACB = expr(ir_unop_b2i, r0ACA);
         ir_expression *const r0ACC = expr(ir_unop_i2u, r0ACB);
         ir_expression *const r0ACD = bit_or(r0AC6, r0ACC);
         ir_expression *const r0ACE = nequal(r0AB0, body.constant(0u));
         ir_expression *const r0ACF = expr(ir_unop_b2i, r0ACE);
         ir_expression *const r0AD0 = expr(ir_unop_i2u, r0ACF);
         ir_expression *const r0AD1 = expr(ir_triop_csel, r0AC5, r0ACD, r0AD0);
         body.emit(assign(r0AC3, expr(ir_triop_csel, r0AC2, r0AD1, r0AB0), 0x01));

         body.emit(assign(r0AB0, r0AC3, 0x01));

         ir_expression *const r0AD2 = expr(ir_unop_u2i, r0AC3);
         ir_expression *const r0AD3 = bit_and(r0AD2, body.constant(int(127)));
         body.emit(assign(r0AB3, expr(ir_triop_csel, r0AC2, r0AD3, r0AB3), 0x01));

         body.emit(assign(r0AAF, expr(ir_triop_csel, r0AC2, body.constant(int(0)), r0AAF), 0x01));


      body.instructions = f0AB8_parent_instructions;
      body.emit(f0AB8);

      /* END IF */


   body.instructions = f0AB5_parent_instructions;
   body.emit(f0AB5);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0AD4 = new(mem_ctx) ir_if(operand(r0AB1).val);
   exec_list *const f0AD4_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AD4->then_instructions;

      ir_expression *const r0AD5 = add(r0AB0, body.constant(64u));
      body.emit(assign(r0AB0, rshift(r0AD5, body.constant(int(7))), 0x01));

      ir_expression *const r0AD6 = bit_xor(r0AB3, body.constant(int(64)));
      ir_expression *const r0AD7 = equal(r0AD6, body.constant(int(0)));
      ir_expression *const r0AD8 = expr(ir_unop_b2i, r0AD7);
      ir_expression *const r0AD9 = expr(ir_unop_i2u, r0AD8);
      ir_expression *const r0ADA = expr(ir_unop_bit_not, r0AD9);
      body.emit(assign(r0AB0, bit_and(r0AB0, r0ADA), 0x01));

      ir_expression *const r0ADB = lshift(r0AAE, body.constant(int(31)));
      ir_expression *const r0ADC = equal(r0AB0, body.constant(0u));
      ir_expression *const r0ADD = expr(ir_triop_csel, r0ADC, body.constant(int(0)), r0AAF);
      ir_expression *const r0ADE = expr(ir_unop_i2u, r0ADD);
      ir_expression *const r0ADF = lshift(r0ADE, body.constant(int(23)));
      ir_expression *const r0AE0 = add(r0ADB, r0ADF);
      ir_expression *const r0AE1 = add(r0AE0, r0AB0);
      body.emit(assign(r0AB2, expr(ir_unop_bitcast_u2f, r0AE1), 0x01));

      body.emit(assign(r0AB1, body.constant(false), 0x01));


   body.instructions = f0AD4_parent_instructions;
   body.emit(f0AD4);

   /* END IF */

   body.emit(ret(r0AB2));

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

   ir_variable *const r0AE2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AE2);
   ir_variable *const r0AE3 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0AE4 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0AE4, swizzle_x(r0AE2), 0x01));

   ir_variable *const r0AE5 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0AE5, bit_and(swizzle_y(r0AE2), body.constant(1048575u)), 0x01));

   ir_variable *const r0AE6 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0AE7 = rshift(swizzle_y(r0AE2), body.constant(int(20)));
   ir_expression *const r0AE8 = bit_and(r0AE7, body.constant(2047u));
   body.emit(assign(r0AE6, expr(ir_unop_u2i, r0AE8), 0x01));

   ir_variable *const r0AE9 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0AE9, rshift(swizzle_y(r0AE2), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AEB = equal(r0AE6, body.constant(int(2047)));
   ir_if *f0AEA = new(mem_ctx) ir_if(operand(r0AEB).val);
   exec_list *const f0AEA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AEA->then_instructions;

      ir_variable *const r0AEC = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0AEC);
      ir_variable *const r0AED = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0AED, lshift(swizzle_x(r0AE2), body.constant(int(12))), 0x01));

      ir_expression *const r0AEE = lshift(swizzle_y(r0AE2), body.constant(int(12)));
      ir_expression *const r0AEF = rshift(swizzle_x(r0AE2), body.constant(int(20)));
      body.emit(assign(r0AE2, bit_or(r0AEE, r0AEF), 0x02));

      body.emit(assign(r0AE2, r0AED, 0x01));

      ir_expression *const r0AF0 = lshift(r0AE9, body.constant(int(31)));
      ir_expression *const r0AF1 = bit_or(r0AF0, body.constant(2143289344u));
      ir_expression *const r0AF2 = rshift(swizzle_y(r0AE2), body.constant(int(9)));
      ir_expression *const r0AF3 = bit_or(r0AF1, r0AF2);
      body.emit(assign(r0AEC, expr(ir_unop_bitcast_u2f, r0AF3), 0x01));

      ir_variable *const r0AF4 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0AF5 = bit_or(r0AE5, r0AE4);
      ir_expression *const r0AF6 = nequal(r0AF5, body.constant(0u));
      ir_expression *const r0AF7 = lshift(r0AE9, body.constant(int(31)));
      ir_expression *const r0AF8 = add(r0AF7, body.constant(2139095040u));
      ir_expression *const r0AF9 = expr(ir_unop_bitcast_u2f, r0AF8);
      body.emit(assign(r0AF4, expr(ir_triop_csel, r0AF6, r0AEC, r0AF9), 0x01));

      body.emit(assign(r0AEC, r0AF4, 0x01));

      body.emit(assign(r0AE3, r0AF4, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AEA->else_instructions;

      ir_variable *const r0AFA = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0AFB = lshift(r0AE5, body.constant(int(10)));
      ir_expression *const r0AFC = rshift(r0AE4, body.constant(int(22)));
      ir_expression *const r0AFD = bit_or(r0AFB, r0AFC);
      ir_expression *const r0AFE = lshift(r0AE4, body.constant(int(10)));
      ir_expression *const r0AFF = nequal(r0AFE, body.constant(0u));
      ir_expression *const r0B00 = expr(ir_unop_b2i, r0AFF);
      ir_expression *const r0B01 = expr(ir_unop_i2u, r0B00);
      body.emit(assign(r0AFA, bit_or(r0AFD, r0B01), 0x01));

      ir_variable *const r0B02 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0B03 = nequal(r0AE6, body.constant(int(0)));
      ir_expression *const r0B04 = bit_or(r0AFA, body.constant(1073741824u));
      body.emit(assign(r0B02, expr(ir_triop_csel, r0B03, r0B04, r0AFA), 0x01));

      ir_variable *const r0B05 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B05, add(r0AE6, body.constant(int(-897))), 0x01));

      ir_variable *const r0B06 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B06, r0B02, 0x01));

      ir_variable *const r0B07 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B07, body.constant(true), 0x01));

      ir_variable *const r0B08 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B09 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B09);
      ir_expression *const r0B0A = bit_and(r0B02, body.constant(127u));
      body.emit(assign(r0B09, expr(ir_unop_u2i, r0B0A), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B0C = expr(ir_unop_i2u, r0B05);
      ir_expression *const r0B0D = gequal(r0B0C, body.constant(253u));
      ir_if *f0B0B = new(mem_ctx) ir_if(operand(r0B0D).val);
      exec_list *const f0B0B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B0B->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B0F = less(body.constant(int(253)), r0B05);
         ir_expression *const r0B10 = equal(r0B05, body.constant(int(253)));
         ir_expression *const r0B11 = expr(ir_unop_u2i, r0B02);
         ir_expression *const r0B12 = less(r0B11, body.constant(int(-64)));
         ir_expression *const r0B13 = logic_and(r0B10, r0B12);
         ir_expression *const r0B14 = logic_or(r0B0F, r0B13);
         ir_if *f0B0E = new(mem_ctx) ir_if(operand(r0B14).val);
         exec_list *const f0B0E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B0E->then_instructions;

            ir_expression *const r0B15 = lshift(r0AE9, body.constant(int(31)));
            ir_expression *const r0B16 = add(r0B15, body.constant(2139095040u));
            body.emit(assign(r0B08, expr(ir_unop_bitcast_u2f, r0B16), 0x01));

            body.emit(assign(r0B07, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B0E->else_instructions;

            ir_variable *const r0B17 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B17, neg(r0B05), 0x01));

            ir_variable *const r0B18 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0B18, less(r0B05, body.constant(int(0))), 0x01));

            ir_variable *const r0B19 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0B1A = neg(r0B05);
            ir_expression *const r0B1B = less(r0B1A, body.constant(int(32)));
            ir_expression *const r0B1C = rshift(r0B02, r0B17);
            ir_expression *const r0B1D = neg(r0B17);
            ir_expression *const r0B1E = bit_and(r0B1D, body.constant(int(31)));
            ir_expression *const r0B1F = lshift(r0B02, r0B1E);
            ir_expression *const r0B20 = nequal(r0B1F, body.constant(0u));
            ir_expression *const r0B21 = expr(ir_unop_b2i, r0B20);
            ir_expression *const r0B22 = expr(ir_unop_i2u, r0B21);
            ir_expression *const r0B23 = bit_or(r0B1C, r0B22);
            ir_expression *const r0B24 = nequal(r0B02, body.constant(0u));
            ir_expression *const r0B25 = expr(ir_unop_b2i, r0B24);
            ir_expression *const r0B26 = expr(ir_unop_i2u, r0B25);
            ir_expression *const r0B27 = expr(ir_triop_csel, r0B1B, r0B23, r0B26);
            body.emit(assign(r0B19, expr(ir_triop_csel, r0B18, r0B27, r0B02), 0x01));

            body.emit(assign(r0B06, r0B19, 0x01));

            ir_expression *const r0B28 = expr(ir_unop_u2i, r0B19);
            ir_expression *const r0B29 = bit_and(r0B28, body.constant(int(127)));
            body.emit(assign(r0B09, expr(ir_triop_csel, r0B18, r0B29, r0B09), 0x01));

            body.emit(assign(r0B05, expr(ir_triop_csel, r0B18, body.constant(int(0)), r0B05), 0x01));


         body.instructions = f0B0E_parent_instructions;
         body.emit(f0B0E);

         /* END IF */


      body.instructions = f0B0B_parent_instructions;
      body.emit(f0B0B);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B2A = new(mem_ctx) ir_if(operand(r0B07).val);
      exec_list *const f0B2A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B2A->then_instructions;

         ir_expression *const r0B2B = add(r0B06, body.constant(64u));
         body.emit(assign(r0B06, rshift(r0B2B, body.constant(int(7))), 0x01));

         ir_expression *const r0B2C = bit_xor(r0B09, body.constant(int(64)));
         ir_expression *const r0B2D = equal(r0B2C, body.constant(int(0)));
         ir_expression *const r0B2E = expr(ir_unop_b2i, r0B2D);
         ir_expression *const r0B2F = expr(ir_unop_i2u, r0B2E);
         ir_expression *const r0B30 = expr(ir_unop_bit_not, r0B2F);
         body.emit(assign(r0B06, bit_and(r0B06, r0B30), 0x01));

         ir_expression *const r0B31 = lshift(r0AE9, body.constant(int(31)));
         ir_expression *const r0B32 = equal(r0B06, body.constant(0u));
         ir_expression *const r0B33 = expr(ir_triop_csel, r0B32, body.constant(int(0)), r0B05);
         ir_expression *const r0B34 = expr(ir_unop_i2u, r0B33);
         ir_expression *const r0B35 = lshift(r0B34, body.constant(int(23)));
         ir_expression *const r0B36 = add(r0B31, r0B35);
         ir_expression *const r0B37 = add(r0B36, r0B06);
         body.emit(assign(r0B08, expr(ir_unop_bitcast_u2f, r0B37), 0x01));

         body.emit(assign(r0B07, body.constant(false), 0x01));


      body.instructions = f0B2A_parent_instructions;
      body.emit(f0B2A);

      /* END IF */

      body.emit(assign(r0AE3, r0B08, 0x01));


   body.instructions = f0AEA_parent_instructions;
   body.emit(f0AEA);

   /* END IF */

   body.emit(ret(r0AE3));

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

   ir_variable *const r0B38 = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0B38);
   ir_variable *const r0B39 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B39, body.constant(true), 0x01));

   ir_variable *const r0B3A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B3B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B3B);
   ir_variable *const r0B3C = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B3C);
   ir_variable *const r0B3D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B3D);
   ir_variable *const r0B3E = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0B3E, expr(ir_unop_bitcast_f2u, r0B38), 0x01));

   ir_variable *const r0B3F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B3F, bit_and(r0B3E, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B3D, r0B3F, 0x01));

   ir_variable *const r0B40 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B41 = rshift(r0B3E, body.constant(int(23)));
   ir_expression *const r0B42 = bit_and(r0B41, body.constant(255u));
   body.emit(assign(r0B40, expr(ir_unop_u2i, r0B42), 0x01));

   body.emit(assign(r0B3C, r0B40, 0x01));

   body.emit(assign(r0B3B, rshift(r0B3E, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B44 = equal(r0B40, body.constant(int(255)));
   ir_if *f0B43 = new(mem_ctx) ir_if(operand(r0B44).val);
   exec_list *const f0B43_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B43->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B46 = nequal(r0B3F, body.constant(0u));
      ir_if *f0B45 = new(mem_ctx) ir_if(operand(r0B46).val);
      exec_list *const f0B45_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B45->then_instructions;

         ir_variable *const r0B47 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B47, lshift(r0B3E, body.constant(int(9))), 0x01));

         ir_variable *const r0B48 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B49 = lshift(r0B47, body.constant(int(20)));
         body.emit(assign(r0B48, bit_or(r0B49, body.constant(0u)), 0x01));

         ir_expression *const r0B4A = rshift(r0B47, body.constant(int(12)));
         ir_expression *const r0B4B = lshift(r0B3B, body.constant(int(31)));
         ir_expression *const r0B4C = bit_or(r0B4B, body.constant(2146959360u));
         body.emit(assign(r0B48, bit_or(r0B4A, r0B4C), 0x02));

         body.emit(assign(r0B3A, r0B48, 0x03));

         body.emit(assign(r0B39, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B45->else_instructions;

         ir_variable *const r0B4D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B4D);
         ir_expression *const r0B4E = lshift(r0B3B, body.constant(int(31)));
         body.emit(assign(r0B4D, add(r0B4E, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B4D, body.constant(0u), 0x01));

         body.emit(assign(r0B3A, r0B4D, 0x03));

         body.emit(assign(r0B39, body.constant(false), 0x01));


      body.instructions = f0B45_parent_instructions;
      body.emit(f0B45);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B43->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B50 = equal(r0B40, body.constant(int(0)));
      ir_if *f0B4F = new(mem_ctx) ir_if(operand(r0B50).val);
      exec_list *const f0B4F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B4F->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B52 = equal(r0B3F, body.constant(0u));
         ir_if *f0B51 = new(mem_ctx) ir_if(operand(r0B52).val);
         exec_list *const f0B51_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B51->then_instructions;

            ir_variable *const r0B53 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B53);
            body.emit(assign(r0B53, lshift(r0B3B, body.constant(int(31))), 0x02));

            body.emit(assign(r0B53, body.constant(0u), 0x01));

            body.emit(assign(r0B3A, r0B53, 0x03));

            body.emit(assign(r0B39, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B51->else_instructions;

            ir_variable *const r0B54 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0B55 = equal(r0B3F, body.constant(0u));
            ir_expression *const r0B56 = expr(ir_unop_find_msb, r0B3F);
            ir_expression *const r0B57 = sub(body.constant(int(31)), r0B56);
            ir_expression *const r0B58 = expr(ir_triop_csel, r0B55, body.constant(int(32)), r0B57);
            body.emit(assign(r0B54, add(r0B58, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B3D, lshift(r0B3F, r0B54), 0x01));

            body.emit(assign(r0B3C, sub(body.constant(int(1)), r0B54), 0x01));

            body.emit(assign(r0B3C, add(r0B3C, body.constant(int(-1))), 0x01));


         body.instructions = f0B51_parent_instructions;
         body.emit(f0B51);

         /* END IF */


      body.instructions = f0B4F_parent_instructions;
      body.emit(f0B4F);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B59 = new(mem_ctx) ir_if(operand(r0B39).val);
      exec_list *const f0B59_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B59->then_instructions;

         ir_variable *const r0B5A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B5A);
         ir_expression *const r0B5B = lshift(r0B3B, body.constant(int(31)));
         ir_expression *const r0B5C = add(r0B3C, body.constant(int(896)));
         ir_expression *const r0B5D = expr(ir_unop_i2u, r0B5C);
         ir_expression *const r0B5E = lshift(r0B5D, body.constant(int(20)));
         ir_expression *const r0B5F = add(r0B5B, r0B5E);
         ir_expression *const r0B60 = rshift(r0B3D, body.constant(int(3)));
         body.emit(assign(r0B5A, add(r0B5F, r0B60), 0x02));

         ir_expression *const r0B61 = lshift(r0B3D, body.constant(int(29)));
         body.emit(assign(r0B5A, bit_or(r0B61, body.constant(0u)), 0x01));

         body.emit(assign(r0B3A, r0B5A, 0x03));

         body.emit(assign(r0B39, body.constant(false), 0x01));


      body.instructions = f0B59_parent_instructions;
      body.emit(f0B59);

      /* END IF */


   body.instructions = f0B43_parent_instructions;
   body.emit(f0B43);

   /* END IF */

   body.emit(ret(r0B3A));

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

   ir_variable *const r0B62 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0B62);
   ir_variable *const r0B63 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0B63);
   ir_variable *const r0B64 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0B64);
   ir_variable *const r0B65 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0B65);
   ir_variable *const r0B66 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0B66);
   ir_variable *const r0B67 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0B67);
   ir_variable *const r0B68 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B68);
   ir_variable *const r0B69 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B69);
   ir_variable *const r0B6A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B6A);
   ir_variable *const r0B6B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0B6B);
   ir_variable *const r0B6C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0B6C);
   ir_variable *const r0B6D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B6D, add(r0B64, r0B67), 0x01));

   ir_variable *const r0B6E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0B6F = less(r0B6D, r0B64);
   ir_expression *const r0B70 = expr(ir_unop_b2i, r0B6F);
   body.emit(assign(r0B6E, expr(ir_unop_i2u, r0B70), 0x01));

   ir_variable *const r0B71 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B71, add(r0B63, r0B66), 0x01));

   body.emit(assign(r0B6C, add(r0B71, r0B6E), 0x01));

   ir_expression *const r0B72 = add(r0B62, r0B65);
   ir_expression *const r0B73 = less(r0B6C, r0B6E);
   ir_expression *const r0B74 = expr(ir_unop_b2i, r0B73);
   ir_expression *const r0B75 = expr(ir_unop_i2u, r0B74);
   body.emit(assign(r0B6B, add(r0B72, r0B75), 0x01));

   ir_expression *const r0B76 = less(r0B71, r0B63);
   ir_expression *const r0B77 = expr(ir_unop_b2i, r0B76);
   ir_expression *const r0B78 = expr(ir_unop_i2u, r0B77);
   body.emit(assign(r0B6B, add(r0B6B, r0B78), 0x01));

   body.emit(assign(r0B6A, r0B6D, 0x01));

   body.emit(assign(r0B69, r0B6C, 0x01));

   body.emit(assign(r0B68, r0B6B, 0x01));

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

   ir_variable *const r0B79 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0B79);
   ir_variable *const r0B7A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0B7A);
   ir_variable *const r0B7B = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0B7B);
   ir_variable *const r0B7C = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0B7C);
   ir_variable *const r0B7D = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0B7D);
   ir_variable *const r0B7E = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0B7E);
   ir_variable *const r0B7F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B7F);
   ir_variable *const r0B80 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B80);
   ir_variable *const r0B81 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B81);
   ir_variable *const r0B82 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0B82);
   ir_variable *const r0B83 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0B84 = less(r0B7B, r0B7E);
   ir_expression *const r0B85 = expr(ir_unop_b2i, r0B84);
   body.emit(assign(r0B83, expr(ir_unop_i2u, r0B85), 0x01));

   ir_variable *const r0B86 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B86, sub(r0B7A, r0B7D), 0x01));

   ir_expression *const r0B87 = sub(r0B79, r0B7C);
   ir_expression *const r0B88 = less(r0B86, r0B83);
   ir_expression *const r0B89 = expr(ir_unop_b2i, r0B88);
   ir_expression *const r0B8A = expr(ir_unop_i2u, r0B89);
   body.emit(assign(r0B82, sub(r0B87, r0B8A), 0x01));

   ir_expression *const r0B8B = less(r0B7A, r0B7D);
   ir_expression *const r0B8C = expr(ir_unop_b2i, r0B8B);
   ir_expression *const r0B8D = expr(ir_unop_i2u, r0B8C);
   body.emit(assign(r0B82, sub(r0B82, r0B8D), 0x01));

   body.emit(assign(r0B81, sub(r0B7B, r0B7E), 0x01));

   body.emit(assign(r0B80, sub(r0B86, r0B83), 0x01));

   body.emit(assign(r0B7F, r0B82, 0x01));

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

   ir_variable *const r0B8E = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0B8E);
   ir_variable *const r0B8F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0B8F);
   ir_variable *const r0B90 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0B90);
   ir_variable *const r0B91 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0B92 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0B92);
   ir_variable *const r0B93 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0B93);
   ir_variable *const r0B94 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0B94);
   ir_variable *const r0B95 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0B95);
   body.emit(assign(r0B94, body.constant(0u), 0x01));

   body.emit(assign(r0B93, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B97 = gequal(r0B8E, r0B90);
   ir_if *f0B96 = new(mem_ctx) ir_if(operand(r0B97).val);
   exec_list *const f0B96_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B96->then_instructions;

      body.emit(assign(r0B91, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B96->else_instructions;

      body.emit(assign(r0B95, rshift(r0B90, body.constant(int(16))), 0x01));

      ir_variable *const r0B98 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0B9A = lshift(r0B95, body.constant(int(16)));
      ir_expression *const r0B9B = gequal(r0B8E, r0B9A);
      ir_if *f0B99 = new(mem_ctx) ir_if(operand(r0B9B).val);
      exec_list *const f0B99_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B99->then_instructions;

         body.emit(assign(r0B98, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B99->else_instructions;

         ir_expression *const r0B9C = expr(ir_binop_div, r0B8E, r0B95);
         body.emit(assign(r0B98, lshift(r0B9C, body.constant(int(16))), 0x01));


      body.instructions = f0B99_parent_instructions;
      body.emit(f0B99);

      /* END IF */

      body.emit(assign(r0B92, r0B98, 0x01));

      ir_variable *const r0B9D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0B9D);
      ir_variable *const r0B9E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0B9E);
      ir_variable *const r0B9F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B9F);
      ir_variable *const r0BA0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BA0, bit_and(r0B90, body.constant(65535u)), 0x01));

      ir_variable *const r0BA1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BA1, rshift(r0B90, body.constant(int(16))), 0x01));

      ir_variable *const r0BA2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BA2, bit_and(r0B98, body.constant(65535u)), 0x01));

      ir_variable *const r0BA3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BA3, rshift(r0B98, body.constant(int(16))), 0x01));

      ir_variable *const r0BA4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BA4, mul(r0BA1, r0BA2), 0x01));

      ir_expression *const r0BA5 = mul(r0BA0, r0BA3);
      body.emit(assign(r0B9E, add(r0BA5, r0BA4), 0x01));

      ir_expression *const r0BA6 = mul(r0BA1, r0BA3);
      ir_expression *const r0BA7 = less(r0B9E, r0BA4);
      ir_expression *const r0BA8 = expr(ir_unop_b2i, r0BA7);
      ir_expression *const r0BA9 = expr(ir_unop_i2u, r0BA8);
      ir_expression *const r0BAA = lshift(r0BA9, body.constant(int(16)));
      ir_expression *const r0BAB = rshift(r0B9E, body.constant(int(16)));
      ir_expression *const r0BAC = add(r0BAA, r0BAB);
      body.emit(assign(r0B9D, add(r0BA6, r0BAC), 0x01));

      body.emit(assign(r0B9E, lshift(r0B9E, body.constant(int(16))), 0x01));

      ir_expression *const r0BAD = mul(r0BA0, r0BA2);
      body.emit(assign(r0B9F, add(r0BAD, r0B9E), 0x01));

      ir_expression *const r0BAE = less(r0B9F, r0B9E);
      ir_expression *const r0BAF = expr(ir_unop_b2i, r0BAE);
      ir_expression *const r0BB0 = expr(ir_unop_i2u, r0BAF);
      body.emit(assign(r0B9D, add(r0B9D, r0BB0), 0x01));

      ir_expression *const r0BB1 = sub(r0B8E, r0B9D);
      ir_expression *const r0BB2 = less(r0B8F, r0B9F);
      ir_expression *const r0BB3 = expr(ir_unop_b2i, r0BB2);
      ir_expression *const r0BB4 = expr(ir_unop_i2u, r0BB3);
      body.emit(assign(r0B94, sub(r0BB1, r0BB4), 0x01));

      body.emit(assign(r0B93, sub(r0B8F, r0B9F), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0BB5 = new(mem_ctx) ir_loop();
      exec_list *const f0BB5_parent_instructions = body.instructions;

         body.instructions = &f0BB5->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0BB7 = expr(ir_unop_u2i, r0B94);
         ir_expression *const r0BB8 = gequal(r0BB7, body.constant(int(0)));
         ir_if *f0BB6 = new(mem_ctx) ir_if(operand(r0BB8).val);
         exec_list *const f0BB6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BB6->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0BB6_parent_instructions;
         body.emit(f0BB6);

         /* END IF */

         body.emit(assign(r0B92, add(r0B92, body.constant(4294901760u)), 0x01));

         ir_variable *const r0BB9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0BBA = lshift(r0B90, body.constant(int(16)));
         body.emit(assign(r0BB9, add(r0B93, r0BBA), 0x01));

         ir_expression *const r0BBB = add(r0B94, r0B95);
         ir_expression *const r0BBC = less(r0BB9, r0B93);
         ir_expression *const r0BBD = expr(ir_unop_b2i, r0BBC);
         ir_expression *const r0BBE = expr(ir_unop_i2u, r0BBD);
         body.emit(assign(r0B94, add(r0BBB, r0BBE), 0x01));

         body.emit(assign(r0B93, r0BB9, 0x01));

      /* LOOP END */

      body.instructions = f0BB5_parent_instructions;
      body.emit(f0BB5);

      ir_expression *const r0BBF = lshift(r0B94, body.constant(int(16)));
      ir_expression *const r0BC0 = rshift(r0B93, body.constant(int(16)));
      body.emit(assign(r0B94, bit_or(r0BBF, r0BC0), 0x01));

      ir_variable *const r0BC1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BC3 = lshift(r0B95, body.constant(int(16)));
      ir_expression *const r0BC4 = gequal(r0B94, r0BC3);
      ir_if *f0BC2 = new(mem_ctx) ir_if(operand(r0BC4).val);
      exec_list *const f0BC2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BC2->then_instructions;

         body.emit(assign(r0BC1, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BC2->else_instructions;

         body.emit(assign(r0BC1, expr(ir_binop_div, r0B94, r0B95), 0x01));


      body.instructions = f0BC2_parent_instructions;
      body.emit(f0BC2);

      /* END IF */

      body.emit(assign(r0B92, bit_or(r0B92, r0BC1), 0x01));

      body.emit(assign(r0B91, r0B92, 0x01));


   body.instructions = f0B96_parent_instructions;
   body.emit(f0B96);

   /* END IF */

   body.emit(ret(r0B91));

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

   ir_variable *const r0BC5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BC5);
   ir_variable *const r0BC6 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0BC6, r0BC5, 0x03));

   ir_variable *const r0BC7 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0BC8 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0BC8, bit_and(swizzle_y(r0BC5), body.constant(1048575u)), 0x01));

   ir_variable *const r0BC9 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0BCA = rshift(swizzle_y(r0BC5), body.constant(int(20)));
   ir_expression *const r0BCB = bit_and(r0BCA, body.constant(2047u));
   body.emit(assign(r0BC9, expr(ir_unop_u2i, r0BCB), 0x01));

   ir_variable *const r0BCC = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0BCC, rshift(swizzle_y(r0BC5), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BCE = equal(r0BC9, body.constant(int(2047)));
   ir_if *f0BCD = new(mem_ctx) ir_if(operand(r0BCE).val);
   exec_list *const f0BCD_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BCD->then_instructions;

      ir_variable *const r0BCF = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0BCF);
      ir_expression *const r0BD0 = lshift(swizzle_y(r0BC5), body.constant(int(12)));
      ir_expression *const r0BD1 = rshift(swizzle_x(r0BC5), body.constant(int(20)));
      body.emit(assign(r0BC6, bit_or(r0BD0, r0BD1), 0x02));

      body.emit(assign(r0BC6, lshift(swizzle_x(r0BC5), body.constant(int(12))), 0x01));

      ir_expression *const r0BD2 = lshift(r0BCC, body.constant(int(31)));
      ir_expression *const r0BD3 = bit_or(r0BD2, body.constant(2143289344u));
      ir_expression *const r0BD4 = rshift(swizzle_y(r0BC6), body.constant(int(9)));
      ir_expression *const r0BD5 = bit_or(r0BD3, r0BD4);
      body.emit(assign(r0BCF, expr(ir_unop_bitcast_u2f, r0BD5), 0x01));

      ir_variable *const r0BD6 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0BD7 = bit_or(r0BC8, swizzle_x(r0BC5));
      ir_expression *const r0BD8 = nequal(r0BD7, body.constant(0u));
      ir_expression *const r0BD9 = lshift(r0BCC, body.constant(int(31)));
      ir_expression *const r0BDA = add(r0BD9, body.constant(2139095040u));
      ir_expression *const r0BDB = expr(ir_unop_bitcast_u2f, r0BDA);
      body.emit(assign(r0BD6, expr(ir_triop_csel, r0BD8, r0BCF, r0BDB), 0x01));

      body.emit(assign(r0BCF, r0BD6, 0x01));

      body.emit(assign(r0BC7, r0BD6, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BCD->else_instructions;

      ir_variable *const r0BDC = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0BDD = lshift(r0BC8, body.constant(int(10)));
      ir_expression *const r0BDE = rshift(swizzle_x(r0BC5), body.constant(int(22)));
      ir_expression *const r0BDF = bit_or(r0BDD, r0BDE);
      ir_expression *const r0BE0 = lshift(swizzle_x(r0BC5), body.constant(int(10)));
      ir_expression *const r0BE1 = nequal(r0BE0, body.constant(0u));
      ir_expression *const r0BE2 = expr(ir_unop_b2i, r0BE1);
      ir_expression *const r0BE3 = expr(ir_unop_i2u, r0BE2);
      body.emit(assign(r0BDC, bit_or(r0BDF, r0BE3), 0x01));

      ir_variable *const r0BE4 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0BE5 = nequal(r0BC9, body.constant(int(0)));
      ir_expression *const r0BE6 = bit_or(r0BDC, body.constant(1073741824u));
      body.emit(assign(r0BE4, expr(ir_triop_csel, r0BE5, r0BE6, r0BDC), 0x01));

      ir_variable *const r0BE7 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0BE7, add(r0BC9, body.constant(int(-897))), 0x01));

      ir_variable *const r0BE8 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0BE8, r0BE4, 0x01));

      ir_variable *const r0BE9 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0BE9, body.constant(true), 0x01));

      ir_variable *const r0BEA = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0BEB = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0BEB);
      ir_expression *const r0BEC = bit_and(r0BE4, body.constant(127u));
      body.emit(assign(r0BEB, expr(ir_unop_u2i, r0BEC), 0x01));

      /* IF CONDITION */
      ir_expression *const r0BEE = expr(ir_unop_i2u, r0BE7);
      ir_expression *const r0BEF = gequal(r0BEE, body.constant(253u));
      ir_if *f0BED = new(mem_ctx) ir_if(operand(r0BEF).val);
      exec_list *const f0BED_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BED->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0BF1 = less(body.constant(int(253)), r0BE7);
         ir_expression *const r0BF2 = equal(r0BE7, body.constant(int(253)));
         ir_expression *const r0BF3 = expr(ir_unop_u2i, r0BE4);
         ir_expression *const r0BF4 = less(r0BF3, body.constant(int(-64)));
         ir_expression *const r0BF5 = logic_and(r0BF2, r0BF4);
         ir_expression *const r0BF6 = logic_or(r0BF1, r0BF5);
         ir_if *f0BF0 = new(mem_ctx) ir_if(operand(r0BF6).val);
         exec_list *const f0BF0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BF0->then_instructions;

            ir_expression *const r0BF7 = lshift(r0BCC, body.constant(int(31)));
            ir_expression *const r0BF8 = add(r0BF7, body.constant(2139095040u));
            body.emit(assign(r0BEA, expr(ir_unop_bitcast_u2f, r0BF8), 0x01));

            body.emit(assign(r0BE9, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BF0->else_instructions;

            ir_variable *const r0BF9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0BF9, neg(r0BE7), 0x01));

            ir_variable *const r0BFA = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0BFA, less(r0BE7, body.constant(int(0))), 0x01));

            ir_variable *const r0BFB = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0BFC = neg(r0BE7);
            ir_expression *const r0BFD = less(r0BFC, body.constant(int(32)));
            ir_expression *const r0BFE = rshift(r0BE4, r0BF9);
            ir_expression *const r0BFF = neg(r0BF9);
            ir_expression *const r0C00 = bit_and(r0BFF, body.constant(int(31)));
            ir_expression *const r0C01 = lshift(r0BE4, r0C00);
            ir_expression *const r0C02 = nequal(r0C01, body.constant(0u));
            ir_expression *const r0C03 = expr(ir_unop_b2i, r0C02);
            ir_expression *const r0C04 = expr(ir_unop_i2u, r0C03);
            ir_expression *const r0C05 = bit_or(r0BFE, r0C04);
            ir_expression *const r0C06 = nequal(r0BE4, body.constant(0u));
            ir_expression *const r0C07 = expr(ir_unop_b2i, r0C06);
            ir_expression *const r0C08 = expr(ir_unop_i2u, r0C07);
            ir_expression *const r0C09 = expr(ir_triop_csel, r0BFD, r0C05, r0C08);
            body.emit(assign(r0BFB, expr(ir_triop_csel, r0BFA, r0C09, r0BE4), 0x01));

            body.emit(assign(r0BE8, r0BFB, 0x01));

            ir_expression *const r0C0A = expr(ir_unop_u2i, r0BFB);
            ir_expression *const r0C0B = bit_and(r0C0A, body.constant(int(127)));
            body.emit(assign(r0BEB, expr(ir_triop_csel, r0BFA, r0C0B, r0BEB), 0x01));

            body.emit(assign(r0BE7, expr(ir_triop_csel, r0BFA, body.constant(int(0)), r0BE7), 0x01));


         body.instructions = f0BF0_parent_instructions;
         body.emit(f0BF0);

         /* END IF */


      body.instructions = f0BED_parent_instructions;
      body.emit(f0BED);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C0C = new(mem_ctx) ir_if(operand(r0BE9).val);
      exec_list *const f0C0C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C0C->then_instructions;

         ir_expression *const r0C0D = add(r0BE8, body.constant(64u));
         body.emit(assign(r0BE8, rshift(r0C0D, body.constant(int(7))), 0x01));

         ir_expression *const r0C0E = bit_xor(r0BEB, body.constant(int(64)));
         ir_expression *const r0C0F = equal(r0C0E, body.constant(int(0)));
         ir_expression *const r0C10 = expr(ir_unop_b2i, r0C0F);
         ir_expression *const r0C11 = expr(ir_unop_i2u, r0C10);
         ir_expression *const r0C12 = expr(ir_unop_bit_not, r0C11);
         body.emit(assign(r0BE8, bit_and(r0BE8, r0C12), 0x01));

         ir_expression *const r0C13 = lshift(r0BCC, body.constant(int(31)));
         ir_expression *const r0C14 = equal(r0BE8, body.constant(0u));
         ir_expression *const r0C15 = expr(ir_triop_csel, r0C14, body.constant(int(0)), r0BE7);
         ir_expression *const r0C16 = expr(ir_unop_i2u, r0C15);
         ir_expression *const r0C17 = lshift(r0C16, body.constant(int(23)));
         ir_expression *const r0C18 = add(r0C13, r0C17);
         ir_expression *const r0C19 = add(r0C18, r0BE8);
         body.emit(assign(r0BEA, expr(ir_unop_bitcast_u2f, r0C19), 0x01));

         body.emit(assign(r0BE9, body.constant(false), 0x01));


      body.instructions = f0C0C_parent_instructions;
      body.emit(f0C0C);

      /* END IF */

      body.emit(assign(r0BC7, r0BEA, 0x01));


   body.instructions = f0BCD_parent_instructions;
   body.emit(f0BCD);

   /* END IF */

   ir_variable *const r0C1A = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C1A, body.constant(true), 0x01));

   ir_variable *const r0C1B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C1C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C1C);
   ir_variable *const r0C1D = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C1D);
   ir_variable *const r0C1E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C1E);
   ir_variable *const r0C1F = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C20 = expr(ir_unop_sqrt, r0BC7);
   body.emit(assign(r0C1F, expr(ir_unop_bitcast_f2u, r0C20), 0x01));

   ir_variable *const r0C21 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C21, bit_and(r0C1F, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C1E, r0C21, 0x01));

   ir_variable *const r0C22 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C23 = rshift(r0C1F, body.constant(int(23)));
   ir_expression *const r0C24 = bit_and(r0C23, body.constant(255u));
   body.emit(assign(r0C22, expr(ir_unop_u2i, r0C24), 0x01));

   body.emit(assign(r0C1D, r0C22, 0x01));

   body.emit(assign(r0C1C, rshift(r0C1F, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C26 = equal(r0C22, body.constant(int(255)));
   ir_if *f0C25 = new(mem_ctx) ir_if(operand(r0C26).val);
   exec_list *const f0C25_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C25->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C28 = nequal(r0C21, body.constant(0u));
      ir_if *f0C27 = new(mem_ctx) ir_if(operand(r0C28).val);
      exec_list *const f0C27_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C27->then_instructions;

         ir_variable *const r0C29 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C29, lshift(r0C1F, body.constant(int(9))), 0x01));

         ir_variable *const r0C2A = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C2B = lshift(r0C29, body.constant(int(20)));
         body.emit(assign(r0C2A, bit_or(r0C2B, body.constant(0u)), 0x01));

         ir_expression *const r0C2C = rshift(r0C29, body.constant(int(12)));
         ir_expression *const r0C2D = lshift(r0C1C, body.constant(int(31)));
         ir_expression *const r0C2E = bit_or(r0C2D, body.constant(2146959360u));
         body.emit(assign(r0C2A, bit_or(r0C2C, r0C2E), 0x02));

         body.emit(assign(r0C1B, r0C2A, 0x03));

         body.emit(assign(r0C1A, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C27->else_instructions;

         ir_variable *const r0C2F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C2F);
         ir_expression *const r0C30 = lshift(r0C1C, body.constant(int(31)));
         body.emit(assign(r0C2F, add(r0C30, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C2F, body.constant(0u), 0x01));

         body.emit(assign(r0C1B, r0C2F, 0x03));

         body.emit(assign(r0C1A, body.constant(false), 0x01));


      body.instructions = f0C27_parent_instructions;
      body.emit(f0C27);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C25->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C32 = equal(r0C22, body.constant(int(0)));
      ir_if *f0C31 = new(mem_ctx) ir_if(operand(r0C32).val);
      exec_list *const f0C31_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C31->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C34 = equal(r0C21, body.constant(0u));
         ir_if *f0C33 = new(mem_ctx) ir_if(operand(r0C34).val);
         exec_list *const f0C33_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C33->then_instructions;

            ir_variable *const r0C35 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C35);
            body.emit(assign(r0C35, lshift(r0C1C, body.constant(int(31))), 0x02));

            body.emit(assign(r0C35, body.constant(0u), 0x01));

            body.emit(assign(r0C1B, r0C35, 0x03));

            body.emit(assign(r0C1A, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C33->else_instructions;

            ir_variable *const r0C36 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0C37 = equal(r0C21, body.constant(0u));
            ir_expression *const r0C38 = expr(ir_unop_find_msb, r0C21);
            ir_expression *const r0C39 = sub(body.constant(int(31)), r0C38);
            ir_expression *const r0C3A = expr(ir_triop_csel, r0C37, body.constant(int(32)), r0C39);
            body.emit(assign(r0C36, add(r0C3A, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C1E, lshift(r0C21, r0C36), 0x01));

            body.emit(assign(r0C1D, sub(body.constant(int(1)), r0C36), 0x01));

            body.emit(assign(r0C1D, add(r0C1D, body.constant(int(-1))), 0x01));


         body.instructions = f0C33_parent_instructions;
         body.emit(f0C33);

         /* END IF */


      body.instructions = f0C31_parent_instructions;
      body.emit(f0C31);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C3B = new(mem_ctx) ir_if(operand(r0C1A).val);
      exec_list *const f0C3B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C3B->then_instructions;

         ir_variable *const r0C3C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C3C);
         ir_expression *const r0C3D = lshift(r0C1C, body.constant(int(31)));
         ir_expression *const r0C3E = add(r0C1D, body.constant(int(896)));
         ir_expression *const r0C3F = expr(ir_unop_i2u, r0C3E);
         ir_expression *const r0C40 = lshift(r0C3F, body.constant(int(20)));
         ir_expression *const r0C41 = add(r0C3D, r0C40);
         ir_expression *const r0C42 = rshift(r0C1E, body.constant(int(3)));
         body.emit(assign(r0C3C, add(r0C41, r0C42), 0x02));

         ir_expression *const r0C43 = lshift(r0C1E, body.constant(int(29)));
         body.emit(assign(r0C3C, bit_or(r0C43, body.constant(0u)), 0x01));

         body.emit(assign(r0C1B, r0C3C, 0x03));

         body.emit(assign(r0C1A, body.constant(false), 0x01));


      body.instructions = f0C3B_parent_instructions;
      body.emit(f0C3B);

      /* END IF */


   body.instructions = f0C25_parent_instructions;
   body.emit(f0C25);

   /* END IF */

   body.emit(ret(r0C1B));

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

   ir_variable *const r0C44 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C44);
   ir_variable *const r0C45 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C46 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C47 = rshift(swizzle_y(r0C44), body.constant(int(20)));
   ir_expression *const r0C48 = bit_and(r0C47, body.constant(2047u));
   ir_expression *const r0C49 = expr(ir_unop_u2i, r0C48);
   body.emit(assign(r0C46, add(r0C49, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C4B = less(r0C46, body.constant(int(0)));
   ir_if *f0C4A = new(mem_ctx) ir_if(operand(r0C4B).val);
   exec_list *const f0C4A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C4A->then_instructions;

      body.emit(assign(r0C45, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C4A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C4D = less(body.constant(int(52)), r0C46);
      ir_if *f0C4C = new(mem_ctx) ir_if(operand(r0C4D).val);
      exec_list *const f0C4C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C4C->then_instructions;

         body.emit(assign(r0C45, r0C44, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C4C->else_instructions;

         ir_variable *const r0C4E = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0C4E, sub(body.constant(int(52)), r0C46), 0x01));

         ir_variable *const r0C4F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0C51 = gequal(r0C4E, body.constant(int(32)));
         ir_if *f0C50 = new(mem_ctx) ir_if(operand(r0C51).val);
         exec_list *const f0C50_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C50->then_instructions;

            body.emit(assign(r0C4F, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C50->else_instructions;

            body.emit(assign(r0C4F, lshift(body.constant(4294967295u), r0C4E), 0x01));


         body.instructions = f0C50_parent_instructions;
         body.emit(f0C50);

         /* END IF */

         ir_variable *const r0C52 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0C54 = less(r0C4E, body.constant(int(33)));
         ir_if *f0C53 = new(mem_ctx) ir_if(operand(r0C54).val);
         exec_list *const f0C53_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C53->then_instructions;

            body.emit(assign(r0C52, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C53->else_instructions;

            ir_expression *const r0C55 = add(r0C4E, body.constant(int(-32)));
            body.emit(assign(r0C52, lshift(body.constant(4294967295u), r0C55), 0x01));


         body.instructions = f0C53_parent_instructions;
         body.emit(f0C53);

         /* END IF */

         ir_variable *const r0C56 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0C56, bit_and(r0C4F, swizzle_x(r0C44)), 0x01));

         body.emit(assign(r0C56, bit_and(r0C52, swizzle_y(r0C44)), 0x02));

         body.emit(assign(r0C45, r0C56, 0x03));


      body.instructions = f0C4C_parent_instructions;
      body.emit(f0C4C);

      /* END IF */


   body.instructions = f0C4A_parent_instructions;
   body.emit(f0C4A);

   /* END IF */

   body.emit(ret(r0C45));

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

   ir_variable *const r0C57 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C57);
   ir_variable *const r0C58 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C58, body.constant(true), 0x01));

   ir_variable *const r0C59 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C5A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0C5A);
   ir_variable *const r0C5B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0C5B);
   ir_variable *const r0C5C = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C5D = rshift(swizzle_y(r0C57), body.constant(int(20)));
   ir_expression *const r0C5E = bit_and(r0C5D, body.constant(2047u));
   ir_expression *const r0C5F = expr(ir_unop_u2i, r0C5E);
   body.emit(assign(r0C5C, add(r0C5F, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0C5B, swizzle_y(r0C57), 0x01));

   body.emit(assign(r0C5A, swizzle_x(r0C57), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C61 = less(r0C5C, body.constant(int(20)));
   ir_if *f0C60 = new(mem_ctx) ir_if(operand(r0C61).val);
   exec_list *const f0C60_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C60->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C63 = less(r0C5C, body.constant(int(0)));
      ir_if *f0C62 = new(mem_ctx) ir_if(operand(r0C63).val);
      exec_list *const f0C62_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C62->then_instructions;

         body.emit(assign(r0C5B, bit_and(swizzle_y(r0C57), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C65 = equal(r0C5C, body.constant(int(-1)));
         ir_expression *const r0C66 = nequal(swizzle_x(r0C57), body.constant(0u));
         ir_expression *const r0C67 = logic_and(r0C65, r0C66);
         ir_if *f0C64 = new(mem_ctx) ir_if(operand(r0C67).val);
         exec_list *const f0C64_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C64->then_instructions;

            body.emit(assign(r0C5B, bit_or(r0C5B, body.constant(1072693248u)), 0x01));


         body.instructions = f0C64_parent_instructions;
         body.emit(f0C64);

         /* END IF */

         body.emit(assign(r0C5A, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C62->else_instructions;

         ir_variable *const r0C68 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C68, rshift(body.constant(1048575u), r0C5C), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C6A = bit_and(r0C5B, r0C68);
         ir_expression *const r0C6B = equal(r0C6A, body.constant(0u));
         ir_expression *const r0C6C = equal(r0C5A, body.constant(0u));
         ir_expression *const r0C6D = logic_and(r0C6B, r0C6C);
         ir_if *f0C69 = new(mem_ctx) ir_if(operand(r0C6D).val);
         exec_list *const f0C69_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C69->then_instructions;

            body.emit(assign(r0C59, r0C57, 0x03));

            body.emit(assign(r0C58, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C69->else_instructions;

            ir_expression *const r0C6E = rshift(body.constant(524288u), r0C5C);
            body.emit(assign(r0C5B, add(r0C5B, r0C6E), 0x01));

            ir_expression *const r0C6F = expr(ir_unop_bit_not, r0C68);
            body.emit(assign(r0C5B, bit_and(r0C5B, r0C6F), 0x01));

            body.emit(assign(r0C5A, body.constant(0u), 0x01));


         body.instructions = f0C69_parent_instructions;
         body.emit(f0C69);

         /* END IF */


      body.instructions = f0C62_parent_instructions;
      body.emit(f0C62);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C60->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C71 = less(body.constant(int(51)), r0C5C);
      ir_expression *const r0C72 = equal(r0C5C, body.constant(int(1024)));
      ir_expression *const r0C73 = logic_or(r0C71, r0C72);
      ir_if *f0C70 = new(mem_ctx) ir_if(operand(r0C73).val);
      exec_list *const f0C70_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C70->then_instructions;

         body.emit(assign(r0C59, r0C57, 0x03));

         body.emit(assign(r0C58, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C70->else_instructions;

         ir_variable *const r0C74 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0C75 = add(r0C5C, body.constant(int(-20)));
         body.emit(assign(r0C74, rshift(body.constant(4294967295u), r0C75), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C77 = bit_and(r0C5A, r0C74);
         ir_expression *const r0C78 = equal(r0C77, body.constant(0u));
         ir_if *f0C76 = new(mem_ctx) ir_if(operand(r0C78).val);
         exec_list *const f0C76_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C76->then_instructions;

            body.emit(assign(r0C59, r0C57, 0x03));

            body.emit(assign(r0C58, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C76->else_instructions;

            ir_variable *const r0C79 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0C7A = sub(body.constant(int(51)), r0C5C);
            ir_expression *const r0C7B = lshift(body.constant(1u), r0C7A);
            body.emit(assign(r0C79, add(r0C5A, r0C7B), 0x01));

            /* IF CONDITION */
            ir_expression *const r0C7D = less(r0C79, r0C5A);
            ir_if *f0C7C = new(mem_ctx) ir_if(operand(r0C7D).val);
            exec_list *const f0C7C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C7C->then_instructions;

               body.emit(assign(r0C5B, add(r0C5B, body.constant(1u)), 0x01));


            body.instructions = f0C7C_parent_instructions;
            body.emit(f0C7C);

            /* END IF */

            ir_expression *const r0C7E = expr(ir_unop_bit_not, r0C74);
            body.emit(assign(r0C5A, bit_and(r0C79, r0C7E), 0x01));


         body.instructions = f0C76_parent_instructions;
         body.emit(f0C76);

         /* END IF */


      body.instructions = f0C70_parent_instructions;
      body.emit(f0C70);

      /* END IF */


   body.instructions = f0C60_parent_instructions;
   body.emit(f0C60);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0C7F = new(mem_ctx) ir_if(operand(r0C58).val);
   exec_list *const f0C7F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C7F->then_instructions;

      body.emit(assign(r0C57, r0C5A, 0x01));

      body.emit(assign(r0C57, r0C5B, 0x02));

      body.emit(assign(r0C59, r0C57, 0x03));

      body.emit(assign(r0C58, body.constant(false), 0x01));


   body.instructions = f0C7F_parent_instructions;
   body.emit(f0C7F);

   /* END IF */

   body.emit(ret(r0C59));

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

   ir_variable *const r0C80 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C80);
   ir_variable *const r0C81 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0C81, r0C80, 0x03));

   ir_variable *const r0C82 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0C83 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0C83, bit_and(swizzle_y(r0C80), body.constant(1048575u)), 0x01));

   ir_variable *const r0C84 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0C85 = rshift(swizzle_y(r0C80), body.constant(int(20)));
   ir_expression *const r0C86 = bit_and(r0C85, body.constant(2047u));
   body.emit(assign(r0C84, expr(ir_unop_u2i, r0C86), 0x01));

   ir_variable *const r0C87 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0C87, rshift(swizzle_y(r0C80), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C89 = equal(r0C84, body.constant(int(2047)));
   ir_if *f0C88 = new(mem_ctx) ir_if(operand(r0C89).val);
   exec_list *const f0C88_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C88->then_instructions;

      ir_variable *const r0C8A = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0C8A);
      ir_expression *const r0C8B = lshift(swizzle_y(r0C80), body.constant(int(12)));
      ir_expression *const r0C8C = rshift(swizzle_x(r0C80), body.constant(int(20)));
      body.emit(assign(r0C81, bit_or(r0C8B, r0C8C), 0x02));

      body.emit(assign(r0C81, lshift(swizzle_x(r0C80), body.constant(int(12))), 0x01));

      ir_expression *const r0C8D = lshift(r0C87, body.constant(int(31)));
      ir_expression *const r0C8E = bit_or(r0C8D, body.constant(2143289344u));
      ir_expression *const r0C8F = rshift(swizzle_y(r0C81), body.constant(int(9)));
      ir_expression *const r0C90 = bit_or(r0C8E, r0C8F);
      body.emit(assign(r0C8A, expr(ir_unop_bitcast_u2f, r0C90), 0x01));

      ir_variable *const r0C91 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0C92 = bit_or(r0C83, swizzle_x(r0C80));
      ir_expression *const r0C93 = nequal(r0C92, body.constant(0u));
      ir_expression *const r0C94 = lshift(r0C87, body.constant(int(31)));
      ir_expression *const r0C95 = add(r0C94, body.constant(2139095040u));
      ir_expression *const r0C96 = expr(ir_unop_bitcast_u2f, r0C95);
      body.emit(assign(r0C91, expr(ir_triop_csel, r0C93, r0C8A, r0C96), 0x01));

      body.emit(assign(r0C8A, r0C91, 0x01));

      body.emit(assign(r0C82, r0C91, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C88->else_instructions;

      ir_variable *const r0C97 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0C98 = lshift(r0C83, body.constant(int(10)));
      ir_expression *const r0C99 = rshift(swizzle_x(r0C80), body.constant(int(22)));
      ir_expression *const r0C9A = bit_or(r0C98, r0C99);
      ir_expression *const r0C9B = lshift(swizzle_x(r0C80), body.constant(int(10)));
      ir_expression *const r0C9C = nequal(r0C9B, body.constant(0u));
      ir_expression *const r0C9D = expr(ir_unop_b2i, r0C9C);
      ir_expression *const r0C9E = expr(ir_unop_i2u, r0C9D);
      body.emit(assign(r0C97, bit_or(r0C9A, r0C9E), 0x01));

      ir_variable *const r0C9F = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0CA0 = nequal(r0C84, body.constant(int(0)));
      ir_expression *const r0CA1 = bit_or(r0C97, body.constant(1073741824u));
      body.emit(assign(r0C9F, expr(ir_triop_csel, r0CA0, r0CA1, r0C97), 0x01));

      ir_variable *const r0CA2 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0CA2, add(r0C84, body.constant(int(-897))), 0x01));

      ir_variable *const r0CA3 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0CA3, r0C9F, 0x01));

      ir_variable *const r0CA4 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0CA4, body.constant(true), 0x01));

      ir_variable *const r0CA5 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0CA6 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0CA6);
      ir_expression *const r0CA7 = bit_and(r0C9F, body.constant(127u));
      body.emit(assign(r0CA6, expr(ir_unop_u2i, r0CA7), 0x01));

      /* IF CONDITION */
      ir_expression *const r0CA9 = expr(ir_unop_i2u, r0CA2);
      ir_expression *const r0CAA = gequal(r0CA9, body.constant(253u));
      ir_if *f0CA8 = new(mem_ctx) ir_if(operand(r0CAA).val);
      exec_list *const f0CA8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CA8->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0CAC = less(body.constant(int(253)), r0CA2);
         ir_expression *const r0CAD = equal(r0CA2, body.constant(int(253)));
         ir_expression *const r0CAE = expr(ir_unop_u2i, r0C9F);
         ir_expression *const r0CAF = less(r0CAE, body.constant(int(-64)));
         ir_expression *const r0CB0 = logic_and(r0CAD, r0CAF);
         ir_expression *const r0CB1 = logic_or(r0CAC, r0CB0);
         ir_if *f0CAB = new(mem_ctx) ir_if(operand(r0CB1).val);
         exec_list *const f0CAB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CAB->then_instructions;

            ir_expression *const r0CB2 = lshift(r0C87, body.constant(int(31)));
            ir_expression *const r0CB3 = add(r0CB2, body.constant(2139095040u));
            body.emit(assign(r0CA5, expr(ir_unop_bitcast_u2f, r0CB3), 0x01));

            body.emit(assign(r0CA4, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CAB->else_instructions;

            ir_variable *const r0CB4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0CB4, neg(r0CA2), 0x01));

            ir_variable *const r0CB5 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0CB5, less(r0CA2, body.constant(int(0))), 0x01));

            ir_variable *const r0CB6 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0CB7 = neg(r0CA2);
            ir_expression *const r0CB8 = less(r0CB7, body.constant(int(32)));
            ir_expression *const r0CB9 = rshift(r0C9F, r0CB4);
            ir_expression *const r0CBA = neg(r0CB4);
            ir_expression *const r0CBB = bit_and(r0CBA, body.constant(int(31)));
            ir_expression *const r0CBC = lshift(r0C9F, r0CBB);
            ir_expression *const r0CBD = nequal(r0CBC, body.constant(0u));
            ir_expression *const r0CBE = expr(ir_unop_b2i, r0CBD);
            ir_expression *const r0CBF = expr(ir_unop_i2u, r0CBE);
            ir_expression *const r0CC0 = bit_or(r0CB9, r0CBF);
            ir_expression *const r0CC1 = nequal(r0C9F, body.constant(0u));
            ir_expression *const r0CC2 = expr(ir_unop_b2i, r0CC1);
            ir_expression *const r0CC3 = expr(ir_unop_i2u, r0CC2);
            ir_expression *const r0CC4 = expr(ir_triop_csel, r0CB8, r0CC0, r0CC3);
            body.emit(assign(r0CB6, expr(ir_triop_csel, r0CB5, r0CC4, r0C9F), 0x01));

            body.emit(assign(r0CA3, r0CB6, 0x01));

            ir_expression *const r0CC5 = expr(ir_unop_u2i, r0CB6);
            ir_expression *const r0CC6 = bit_and(r0CC5, body.constant(int(127)));
            body.emit(assign(r0CA6, expr(ir_triop_csel, r0CB5, r0CC6, r0CA6), 0x01));

            body.emit(assign(r0CA2, expr(ir_triop_csel, r0CB5, body.constant(int(0)), r0CA2), 0x01));


         body.instructions = f0CAB_parent_instructions;
         body.emit(f0CAB);

         /* END IF */


      body.instructions = f0CA8_parent_instructions;
      body.emit(f0CA8);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0CC7 = new(mem_ctx) ir_if(operand(r0CA4).val);
      exec_list *const f0CC7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CC7->then_instructions;

         ir_expression *const r0CC8 = add(r0CA3, body.constant(64u));
         body.emit(assign(r0CA3, rshift(r0CC8, body.constant(int(7))), 0x01));

         ir_expression *const r0CC9 = bit_xor(r0CA6, body.constant(int(64)));
         ir_expression *const r0CCA = equal(r0CC9, body.constant(int(0)));
         ir_expression *const r0CCB = expr(ir_unop_b2i, r0CCA);
         ir_expression *const r0CCC = expr(ir_unop_i2u, r0CCB);
         ir_expression *const r0CCD = expr(ir_unop_bit_not, r0CCC);
         body.emit(assign(r0CA3, bit_and(r0CA3, r0CCD), 0x01));

         ir_expression *const r0CCE = lshift(r0C87, body.constant(int(31)));
         ir_expression *const r0CCF = equal(r0CA3, body.constant(0u));
         ir_expression *const r0CD0 = expr(ir_triop_csel, r0CCF, body.constant(int(0)), r0CA2);
         ir_expression *const r0CD1 = expr(ir_unop_i2u, r0CD0);
         ir_expression *const r0CD2 = lshift(r0CD1, body.constant(int(23)));
         ir_expression *const r0CD3 = add(r0CCE, r0CD2);
         ir_expression *const r0CD4 = add(r0CD3, r0CA3);
         body.emit(assign(r0CA5, expr(ir_unop_bitcast_u2f, r0CD4), 0x01));

         body.emit(assign(r0CA4, body.constant(false), 0x01));


      body.instructions = f0CC7_parent_instructions;
      body.emit(f0CC7);

      /* END IF */

      body.emit(assign(r0C82, r0CA5, 0x01));


   body.instructions = f0C88_parent_instructions;
   body.emit(f0C88);

   /* END IF */

   ir_variable *const r0CD5 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0CD5, body.constant(true), 0x01));

   ir_variable *const r0CD6 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CD7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0CD7);
   ir_variable *const r0CD8 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0CD8);
   ir_variable *const r0CD9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0CD9);
   ir_variable *const r0CDA = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0CDB = expr(ir_unop_rcp, r0C82);
   body.emit(assign(r0CDA, expr(ir_unop_bitcast_f2u, r0CDB), 0x01));

   ir_variable *const r0CDC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0CDC, bit_and(r0CDA, body.constant(8388607u)), 0x01));

   body.emit(assign(r0CD9, r0CDC, 0x01));

   ir_variable *const r0CDD = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0CDE = rshift(r0CDA, body.constant(int(23)));
   ir_expression *const r0CDF = bit_and(r0CDE, body.constant(255u));
   body.emit(assign(r0CDD, expr(ir_unop_u2i, r0CDF), 0x01));

   body.emit(assign(r0CD8, r0CDD, 0x01));

   body.emit(assign(r0CD7, rshift(r0CDA, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CE1 = equal(r0CDD, body.constant(int(255)));
   ir_if *f0CE0 = new(mem_ctx) ir_if(operand(r0CE1).val);
   exec_list *const f0CE0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CE0->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CE3 = nequal(r0CDC, body.constant(0u));
      ir_if *f0CE2 = new(mem_ctx) ir_if(operand(r0CE3).val);
      exec_list *const f0CE2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CE2->then_instructions;

         ir_variable *const r0CE4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0CE4, lshift(r0CDA, body.constant(int(9))), 0x01));

         ir_variable *const r0CE5 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0CE6 = lshift(r0CE4, body.constant(int(20)));
         body.emit(assign(r0CE5, bit_or(r0CE6, body.constant(0u)), 0x01));

         ir_expression *const r0CE7 = rshift(r0CE4, body.constant(int(12)));
         ir_expression *const r0CE8 = lshift(r0CD7, body.constant(int(31)));
         ir_expression *const r0CE9 = bit_or(r0CE8, body.constant(2146959360u));
         body.emit(assign(r0CE5, bit_or(r0CE7, r0CE9), 0x02));

         body.emit(assign(r0CD6, r0CE5, 0x03));

         body.emit(assign(r0CD5, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CE2->else_instructions;

         ir_variable *const r0CEA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0CEA);
         ir_expression *const r0CEB = lshift(r0CD7, body.constant(int(31)));
         body.emit(assign(r0CEA, add(r0CEB, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0CEA, body.constant(0u), 0x01));

         body.emit(assign(r0CD6, r0CEA, 0x03));

         body.emit(assign(r0CD5, body.constant(false), 0x01));


      body.instructions = f0CE2_parent_instructions;
      body.emit(f0CE2);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CE0->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CED = equal(r0CDD, body.constant(int(0)));
      ir_if *f0CEC = new(mem_ctx) ir_if(operand(r0CED).val);
      exec_list *const f0CEC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CEC->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0CEF = equal(r0CDC, body.constant(0u));
         ir_if *f0CEE = new(mem_ctx) ir_if(operand(r0CEF).val);
         exec_list *const f0CEE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CEE->then_instructions;

            ir_variable *const r0CF0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0CF0);
            body.emit(assign(r0CF0, lshift(r0CD7, body.constant(int(31))), 0x02));

            body.emit(assign(r0CF0, body.constant(0u), 0x01));

            body.emit(assign(r0CD6, r0CF0, 0x03));

            body.emit(assign(r0CD5, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CEE->else_instructions;

            ir_variable *const r0CF1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0CF2 = equal(r0CDC, body.constant(0u));
            ir_expression *const r0CF3 = expr(ir_unop_find_msb, r0CDC);
            ir_expression *const r0CF4 = sub(body.constant(int(31)), r0CF3);
            ir_expression *const r0CF5 = expr(ir_triop_csel, r0CF2, body.constant(int(32)), r0CF4);
            body.emit(assign(r0CF1, add(r0CF5, body.constant(int(-8))), 0x01));

            body.emit(assign(r0CD9, lshift(r0CDC, r0CF1), 0x01));

            body.emit(assign(r0CD8, sub(body.constant(int(1)), r0CF1), 0x01));

            body.emit(assign(r0CD8, add(r0CD8, body.constant(int(-1))), 0x01));


         body.instructions = f0CEE_parent_instructions;
         body.emit(f0CEE);

         /* END IF */


      body.instructions = f0CEC_parent_instructions;
      body.emit(f0CEC);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0CF6 = new(mem_ctx) ir_if(operand(r0CD5).val);
      exec_list *const f0CF6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CF6->then_instructions;

         ir_variable *const r0CF7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0CF7);
         ir_expression *const r0CF8 = lshift(r0CD7, body.constant(int(31)));
         ir_expression *const r0CF9 = add(r0CD8, body.constant(int(896)));
         ir_expression *const r0CFA = expr(ir_unop_i2u, r0CF9);
         ir_expression *const r0CFB = lshift(r0CFA, body.constant(int(20)));
         ir_expression *const r0CFC = add(r0CF8, r0CFB);
         ir_expression *const r0CFD = rshift(r0CD9, body.constant(int(3)));
         body.emit(assign(r0CF7, add(r0CFC, r0CFD), 0x02));

         ir_expression *const r0CFE = lshift(r0CD9, body.constant(int(29)));
         body.emit(assign(r0CF7, bit_or(r0CFE, body.constant(0u)), 0x01));

         body.emit(assign(r0CD6, r0CF7, 0x03));

         body.emit(assign(r0CD5, body.constant(false), 0x01));


      body.instructions = f0CF6_parent_instructions;
      body.emit(f0CF6);

      /* END IF */


   body.instructions = f0CE0_parent_instructions;
   body.emit(f0CE0);

   /* END IF */

   body.emit(ret(r0CD6));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
