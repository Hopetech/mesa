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
   ir_expression *const r00CB = equal(r00C1, body.constant(int(0)));
   ir_if *f00CA = new(mem_ctx) ir_if(operand(r00CB).val);
   exec_list *const f00CA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00CA->then_instructions;

      body.emit(assign(r00C5, r00C0, 0x01));

      body.emit(assign(r00C6, r00BF, 0x01));

      body.emit(assign(r00C7, r00BE, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00CA->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00CD = less(r00C1, body.constant(int(32)));
      ir_if *f00CC = new(mem_ctx) ir_if(operand(r00CD).val);
      exec_list *const f00CC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00CC->then_instructions;

         body.emit(assign(r00C5, lshift(r00BF, r00C8), 0x01));

         ir_expression *const r00CE = lshift(r00BE, r00C8);
         ir_expression *const r00CF = rshift(r00BF, r00C1);
         body.emit(assign(r00C6, bit_or(r00CE, r00CF), 0x01));

         body.emit(assign(r00C7, rshift(r00BE, r00C1), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00CC->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00D1 = equal(r00C1, body.constant(int(32)));
         ir_if *f00D0 = new(mem_ctx) ir_if(operand(r00D1).val);
         exec_list *const f00D0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00D0->then_instructions;

            body.emit(assign(r00C5, r00BF, 0x01));

            body.emit(assign(r00C6, r00BE, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00D0->else_instructions;

            body.emit(assign(r00C0, bit_or(r00C0, r00BF), 0x01));

            ir_expression *const r00D2 = less(r00C1, body.constant(int(64)));
            ir_expression *const r00D3 = lshift(r00BE, r00C8);
            ir_expression *const r00D4 = equal(r00C1, body.constant(int(64)));
            ir_expression *const r00D5 = nequal(r00BE, body.constant(0u));
            ir_expression *const r00D6 = expr(ir_unop_b2i, r00D5);
            ir_expression *const r00D7 = expr(ir_unop_i2u, r00D6);
            ir_expression *const r00D8 = expr(ir_triop_csel, r00D4, r00BE, r00D7);
            body.emit(assign(r00C5, expr(ir_triop_csel, r00D2, r00D3, r00D8), 0x01));

            ir_expression *const r00D9 = less(r00C1, body.constant(int(64)));
            ir_expression *const r00DA = bit_and(r00C1, body.constant(int(31)));
            ir_expression *const r00DB = rshift(r00BE, r00DA);
            body.emit(assign(r00C6, expr(ir_triop_csel, r00D9, r00DB, body.constant(0u)), 0x01));


         body.instructions = f00D0_parent_instructions;
         body.emit(f00D0);

         /* END IF */

         body.emit(assign(r00C7, body.constant(0u), 0x01));


      body.instructions = f00CC_parent_instructions;
      body.emit(f00CC);

      /* END IF */

      ir_expression *const r00DC = nequal(r00C0, body.constant(0u));
      ir_expression *const r00DD = expr(ir_unop_b2i, r00DC);
      ir_expression *const r00DE = expr(ir_unop_i2u, r00DD);
      body.emit(assign(r00C5, bit_or(r00C5, r00DE), 0x01));


   body.instructions = f00CA_parent_instructions;
   body.emit(f00CA);

   /* END IF */

   body.emit(assign(r00C4, r00C5, 0x01));

   body.emit(assign(r00C3, r00C6, 0x01));

   body.emit(assign(r00C2, r00C7, 0x01));

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

   ir_variable *const r00DF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00DF);
   ir_variable *const r00E0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00E0);
   ir_variable *const r00E1 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00E1);
   ir_variable *const r00E2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00E2);
   ir_variable *const r00E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00E3);
   body.emit(assign(r00E3, lshift(r00E0, r00E1), 0x01));

   ir_expression *const r00E4 = equal(r00E1, body.constant(int(0)));
   ir_expression *const r00E5 = lshift(r00DF, r00E1);
   ir_expression *const r00E6 = neg(r00E1);
   ir_expression *const r00E7 = bit_and(r00E6, body.constant(int(31)));
   ir_expression *const r00E8 = rshift(r00E0, r00E7);
   ir_expression *const r00E9 = bit_or(r00E5, r00E8);
   body.emit(assign(r00E2, expr(ir_triop_csel, r00E4, r00DF, r00E9), 0x01));

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

   ir_variable *const r00EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00EA);
   ir_variable *const r00EB = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00EB);
   ir_variable *const r00EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00EC);
   ir_variable *const r00ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00ED);
   ir_variable *const r00EE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
   body.emit(r00EE);
   ir_expression *const r00EF = lshift(r00EA, body.constant(int(31)));
   ir_expression *const r00F0 = expr(ir_unop_i2u, r00EB);
   ir_expression *const r00F1 = lshift(r00F0, body.constant(int(20)));
   ir_expression *const r00F2 = add(r00EF, r00F1);
   body.emit(assign(r00EE, add(r00F2, r00EC), 0x02));

   body.emit(assign(r00EE, r00ED, 0x01));

   body.emit(ret(r00EE));

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

   ir_variable *const r00F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00F3);
   ir_variable *const r00F4 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00F4);
   ir_variable *const r00F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00F5);
   ir_variable *const r00F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00F6);
   ir_variable *const r00F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_function_in);
   sig_parameters.push_tail(r00F7);
   ir_variable *const r00F8 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r00F8, body.constant(true), 0x01));

   ir_variable *const r00F9 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r00FA = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r00FA);
   ir_expression *const r00FB = expr(ir_unop_u2i, r00F7);
   body.emit(assign(r00FA, less(r00FB, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00FD = gequal(r00F4, body.constant(int(2045)));
   ir_if *f00FC = new(mem_ctx) ir_if(operand(r00FD).val);
   exec_list *const f00FC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00FC->then_instructions;

      /* IF CONDITION */
      ir_expression *const r00FF = less(body.constant(int(2045)), r00F4);
      ir_expression *const r0100 = equal(r00F4, body.constant(int(2045)));
      ir_expression *const r0101 = equal(body.constant(2097151u), r00F5);
      ir_expression *const r0102 = equal(body.constant(4294967295u), r00F6);
      ir_expression *const r0103 = logic_and(r0101, r0102);
      ir_expression *const r0104 = logic_and(r0100, r0103);
      ir_expression *const r0105 = logic_and(r0104, r00FA);
      ir_expression *const r0106 = logic_or(r00FF, r0105);
      ir_if *f00FE = new(mem_ctx) ir_if(operand(r0106).val);
      exec_list *const f00FE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00FE->then_instructions;

         ir_variable *const r0107 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0107);
         ir_expression *const r0108 = lshift(r00F3, body.constant(int(31)));
         body.emit(assign(r0107, add(r0108, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0107, body.constant(0u), 0x01));

         body.emit(assign(r00F9, r0107, 0x03));

         body.emit(assign(r00F8, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00FE->else_instructions;

         /* IF CONDITION */
         ir_expression *const r010A = less(r00F4, body.constant(int(0)));
         ir_if *f0109 = new(mem_ctx) ir_if(operand(r010A).val);
         exec_list *const f0109_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0109->then_instructions;

            ir_variable *const r010B = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r010B, r00F7, 0x01));

            ir_variable *const r010C = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r010C, neg(r00F4), 0x01));

            ir_variable *const r010D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r010D);
            ir_variable *const r010E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r010E);
            ir_variable *const r010F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r010F);
            ir_variable *const r0110 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0111 = neg(r010C);
            body.emit(assign(r0110, bit_and(r0111, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0113 = equal(r010C, body.constant(int(0)));
            ir_if *f0112 = new(mem_ctx) ir_if(operand(r0113).val);
            exec_list *const f0112_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0112->then_instructions;

               body.emit(assign(r010D, r00F7, 0x01));

               body.emit(assign(r010E, r00F6, 0x01));

               body.emit(assign(r010F, r00F5, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0112->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0115 = less(r010C, body.constant(int(32)));
               ir_if *f0114 = new(mem_ctx) ir_if(operand(r0115).val);
               exec_list *const f0114_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0114->then_instructions;

                  body.emit(assign(r010D, lshift(r00F6, r0110), 0x01));

                  ir_expression *const r0116 = lshift(r00F5, r0110);
                  ir_expression *const r0117 = rshift(r00F6, r010C);
                  body.emit(assign(r010E, bit_or(r0116, r0117), 0x01));

                  body.emit(assign(r010F, rshift(r00F5, r010C), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0114->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0119 = equal(r010C, body.constant(int(32)));
                  ir_if *f0118 = new(mem_ctx) ir_if(operand(r0119).val);
                  exec_list *const f0118_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0118->then_instructions;

                     body.emit(assign(r010D, r00F6, 0x01));

                     body.emit(assign(r010E, r00F5, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0118->else_instructions;

                     body.emit(assign(r010B, bit_or(r00F7, r00F6), 0x01));

                     ir_expression *const r011A = less(r010C, body.constant(int(64)));
                     ir_expression *const r011B = lshift(r00F5, r0110);
                     ir_expression *const r011C = equal(r010C, body.constant(int(64)));
                     ir_expression *const r011D = nequal(r00F5, body.constant(0u));
                     ir_expression *const r011E = expr(ir_unop_b2i, r011D);
                     ir_expression *const r011F = expr(ir_unop_i2u, r011E);
                     ir_expression *const r0120 = expr(ir_triop_csel, r011C, r00F5, r011F);
                     body.emit(assign(r010D, expr(ir_triop_csel, r011A, r011B, r0120), 0x01));

                     ir_expression *const r0121 = less(r010C, body.constant(int(64)));
                     ir_expression *const r0122 = bit_and(r010C, body.constant(int(31)));
                     ir_expression *const r0123 = rshift(r00F5, r0122);
                     body.emit(assign(r010E, expr(ir_triop_csel, r0121, r0123, body.constant(0u)), 0x01));


                  body.instructions = f0118_parent_instructions;
                  body.emit(f0118);

                  /* END IF */

                  body.emit(assign(r010F, body.constant(0u), 0x01));


               body.instructions = f0114_parent_instructions;
               body.emit(f0114);

               /* END IF */

               ir_expression *const r0124 = nequal(r010B, body.constant(0u));
               ir_expression *const r0125 = expr(ir_unop_b2i, r0124);
               ir_expression *const r0126 = expr(ir_unop_i2u, r0125);
               body.emit(assign(r010D, bit_or(r010D, r0126), 0x01));


            body.instructions = f0112_parent_instructions;
            body.emit(f0112);

            /* END IF */

            body.emit(assign(r00F5, r010F, 0x01));

            body.emit(assign(r00F6, r010E, 0x01));

            body.emit(assign(r00F7, r010D, 0x01));

            body.emit(assign(r00F4, body.constant(int(0)), 0x01));

            body.emit(assign(r00FA, less(r010D, body.constant(0u)), 0x01));


         body.instructions = f0109_parent_instructions;
         body.emit(f0109);

         /* END IF */


      body.instructions = f00FE_parent_instructions;
      body.emit(f00FE);

      /* END IF */


   body.instructions = f00FC_parent_instructions;
   body.emit(f00FC);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0127 = new(mem_ctx) ir_if(operand(r00F8).val);
   exec_list *const f0127_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0127->then_instructions;

      /* IF CONDITION */
      ir_if *f0128 = new(mem_ctx) ir_if(operand(r00FA).val);
      exec_list *const f0128_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0128->then_instructions;

         ir_variable *const r0129 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0129, add(r00F6, body.constant(1u)), 0x01));

         ir_expression *const r012A = less(r0129, r00F6);
         ir_expression *const r012B = expr(ir_unop_b2i, r012A);
         ir_expression *const r012C = expr(ir_unop_i2u, r012B);
         body.emit(assign(r00F5, add(r00F5, r012C), 0x01));

         ir_expression *const r012D = equal(r00F7, body.constant(0u));
         ir_expression *const r012E = expr(ir_unop_b2i, r012D);
         ir_expression *const r012F = expr(ir_unop_i2u, r012E);
         ir_expression *const r0130 = add(r00F7, r012F);
         ir_expression *const r0131 = bit_and(r0130, body.constant(1u));
         ir_expression *const r0132 = expr(ir_unop_bit_not, r0131);
         body.emit(assign(r00F6, bit_and(r0129, r0132), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0128->else_instructions;

         ir_expression *const r0133 = bit_or(r00F5, r00F6);
         ir_expression *const r0134 = equal(r0133, body.constant(0u));
         body.emit(assign(r00F4, expr(ir_triop_csel, r0134, body.constant(int(0)), r00F4), 0x01));


      body.instructions = f0128_parent_instructions;
      body.emit(f0128);

      /* END IF */

      ir_variable *const r0135 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0135);
      ir_expression *const r0136 = lshift(r00F3, body.constant(int(31)));
      ir_expression *const r0137 = expr(ir_unop_i2u, r00F4);
      ir_expression *const r0138 = lshift(r0137, body.constant(int(20)));
      ir_expression *const r0139 = add(r0136, r0138);
      body.emit(assign(r0135, add(r0139, r00F5), 0x02));

      body.emit(assign(r0135, r00F6, 0x01));

      body.emit(assign(r00F9, r0135, 0x03));

      body.emit(assign(r00F8, body.constant(false), 0x01));


   body.instructions = f0127_parent_instructions;
   body.emit(f0127);

   /* END IF */

   body.emit(ret(r00F9));

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

   ir_variable *const r013A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r013A);
   ir_variable *const r013B = body.make_temp(glsl_type::int_type, "mix_retval");
   ir_expression *const r013C = equal(r013A, body.constant(0u));
   ir_expression *const r013D = expr(ir_unop_find_msb, r013A);
   ir_expression *const r013E = sub(body.constant(int(31)), r013D);
   body.emit(assign(r013B, expr(ir_triop_csel, r013C, body.constant(int(32)), r013E), 0x01));

   body.emit(ret(r013B));

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

   ir_variable *const r013F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r013F);
   ir_variable *const r0140 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0140);
   ir_variable *const r0141 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0141);
   ir_variable *const r0142 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0142);
   ir_variable *const r0143 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0143);
   ir_variable *const r0144 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0144);
   ir_expression *const r0145 = equal(r0141, body.constant(0u));
   ir_expression *const r0146 = add(r0140, body.constant(int(-32)));
   body.emit(assign(r0140, expr(ir_triop_csel, r0145, r0146, r0140), 0x01));

   ir_variable *const r0147 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r0148 = equal(r0141, body.constant(0u));
   body.emit(assign(r0147, expr(ir_triop_csel, r0148, body.constant(0u), r0142), 0x01));

   body.emit(assign(r0142, r0147, 0x01));

   ir_variable *const r0149 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r014A = equal(r0141, body.constant(0u));
   body.emit(assign(r0149, expr(ir_triop_csel, r014A, r0147, r0141), 0x01));

   body.emit(assign(r0141, r0149, 0x01));

   ir_expression *const r014B = equal(r0149, body.constant(0u));
   ir_expression *const r014C = expr(ir_unop_find_msb, r0149);
   ir_expression *const r014D = sub(body.constant(int(31)), r014C);
   ir_expression *const r014E = expr(ir_triop_csel, r014B, body.constant(int(32)), r014D);
   body.emit(assign(r0144, add(r014E, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0150 = gequal(r0144, body.constant(int(0)));
   ir_if *f014F = new(mem_ctx) ir_if(operand(r0150).val);
   exec_list *const f014F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f014F->then_instructions;

      body.emit(assign(r0143, body.constant(0u), 0x01));

      ir_expression *const r0151 = equal(r0144, body.constant(int(0)));
      ir_expression *const r0152 = lshift(r0149, r0144);
      ir_expression *const r0153 = neg(r0144);
      ir_expression *const r0154 = bit_and(r0153, body.constant(int(31)));
      ir_expression *const r0155 = rshift(r0147, r0154);
      ir_expression *const r0156 = bit_or(r0152, r0155);
      body.emit(assign(r0141, expr(ir_triop_csel, r0151, r0149, r0156), 0x01));

      body.emit(assign(r0142, lshift(r0147, r0144), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f014F->else_instructions;

      ir_variable *const r0157 = body.make_temp(glsl_type::uint_type, "a2");
      body.emit(assign(r0157, body.constant(0u), 0x01));

      ir_variable *const r0158 = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r0158, neg(r0144), 0x01));

      ir_variable *const r0159 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
      body.emit(r0159);
      ir_variable *const r015A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r015A);
      ir_variable *const r015B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r015B);
      ir_variable *const r015C = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r015D = neg(r0158);
      body.emit(assign(r015C, bit_and(r015D, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r015F = equal(r0158, body.constant(int(0)));
      ir_if *f015E = new(mem_ctx) ir_if(operand(r015F).val);
      exec_list *const f015E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f015E->then_instructions;

         body.emit(assign(r0159, r0157, 0x01));

         body.emit(assign(r015A, r0142, 0x01));

         body.emit(assign(r015B, r0141, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f015E->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0161 = less(r0158, body.constant(int(32)));
         ir_if *f0160 = new(mem_ctx) ir_if(operand(r0161).val);
         exec_list *const f0160_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0160->then_instructions;

            body.emit(assign(r0159, lshift(r0142, r015C), 0x01));

            ir_expression *const r0162 = lshift(r0141, r015C);
            ir_expression *const r0163 = rshift(r0142, r0158);
            body.emit(assign(r015A, bit_or(r0162, r0163), 0x01));

            body.emit(assign(r015B, rshift(r0141, r0158), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0160->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0165 = equal(r0158, body.constant(int(32)));
            ir_if *f0164 = new(mem_ctx) ir_if(operand(r0165).val);
            exec_list *const f0164_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0164->then_instructions;

               body.emit(assign(r0159, r0142, 0x01));

               body.emit(assign(r015A, r0141, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0164->else_instructions;

               body.emit(assign(r0157, bit_or(body.constant(0u), r0142), 0x01));

               ir_expression *const r0166 = less(r0158, body.constant(int(64)));
               ir_expression *const r0167 = lshift(r0141, r015C);
               ir_expression *const r0168 = equal(r0158, body.constant(int(64)));
               ir_expression *const r0169 = nequal(r0141, body.constant(0u));
               ir_expression *const r016A = expr(ir_unop_b2i, r0169);
               ir_expression *const r016B = expr(ir_unop_i2u, r016A);
               ir_expression *const r016C = expr(ir_triop_csel, r0168, r0141, r016B);
               body.emit(assign(r0159, expr(ir_triop_csel, r0166, r0167, r016C), 0x01));

               ir_expression *const r016D = less(r0158, body.constant(int(64)));
               ir_expression *const r016E = bit_and(r0158, body.constant(int(31)));
               ir_expression *const r016F = rshift(r0141, r016E);
               body.emit(assign(r015A, expr(ir_triop_csel, r016D, r016F, body.constant(0u)), 0x01));


            body.instructions = f0164_parent_instructions;
            body.emit(f0164);

            /* END IF */

            body.emit(assign(r015B, body.constant(0u), 0x01));


         body.instructions = f0160_parent_instructions;
         body.emit(f0160);

         /* END IF */

         ir_expression *const r0170 = nequal(r0157, body.constant(0u));
         ir_expression *const r0171 = expr(ir_unop_b2i, r0170);
         ir_expression *const r0172 = expr(ir_unop_i2u, r0171);
         body.emit(assign(r0159, bit_or(r0159, r0172), 0x01));


      body.instructions = f015E_parent_instructions;
      body.emit(f015E);

      /* END IF */

      body.emit(assign(r0141, r015B, 0x01));

      body.emit(assign(r0142, r015A, 0x01));

      body.emit(assign(r0143, r0159, 0x01));


   body.instructions = f014F_parent_instructions;
   body.emit(f014F);

   /* END IF */

   body.emit(assign(r0140, sub(r0140, r0144), 0x01));

   ir_variable *const r0173 = body.make_temp(glsl_type::int_type, "zExp");
   body.emit(assign(r0173, r0140, 0x01));

   ir_variable *const r0174 = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r0174, r0141, 0x01));

   ir_variable *const r0175 = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r0175, r0142, 0x01));

   ir_variable *const r0176 = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r0176, r0143, 0x01));

   ir_variable *const r0177 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0177, body.constant(true), 0x01));

   ir_variable *const r0178 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0179 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r0179);
   ir_expression *const r017A = expr(ir_unop_u2i, r0143);
   body.emit(assign(r0179, less(r017A, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r017C = gequal(r0140, body.constant(int(2045)));
   ir_if *f017B = new(mem_ctx) ir_if(operand(r017C).val);
   exec_list *const f017B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f017B->then_instructions;

      /* IF CONDITION */
      ir_expression *const r017E = less(body.constant(int(2045)), r0140);
      ir_expression *const r017F = equal(r0140, body.constant(int(2045)));
      ir_expression *const r0180 = equal(body.constant(2097151u), r0141);
      ir_expression *const r0181 = equal(body.constant(4294967295u), r0142);
      ir_expression *const r0182 = logic_and(r0180, r0181);
      ir_expression *const r0183 = logic_and(r017F, r0182);
      ir_expression *const r0184 = logic_and(r0183, r0179);
      ir_expression *const r0185 = logic_or(r017E, r0184);
      ir_if *f017D = new(mem_ctx) ir_if(operand(r0185).val);
      exec_list *const f017D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f017D->then_instructions;

         ir_variable *const r0186 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0186);
         ir_expression *const r0187 = lshift(r013F, body.constant(int(31)));
         body.emit(assign(r0186, add(r0187, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0186, body.constant(0u), 0x01));

         body.emit(assign(r0178, r0186, 0x03));

         body.emit(assign(r0177, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f017D->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0189 = less(r0140, body.constant(int(0)));
         ir_if *f0188 = new(mem_ctx) ir_if(operand(r0189).val);
         exec_list *const f0188_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0188->then_instructions;

            ir_variable *const r018A = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r018A, r0143, 0x01));

            ir_variable *const r018B = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r018B, neg(r0140), 0x01));

            ir_variable *const r018C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r018C);
            ir_variable *const r018D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r018D);
            ir_variable *const r018E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r018E);
            ir_variable *const r018F = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0190 = neg(r018B);
            body.emit(assign(r018F, bit_and(r0190, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0192 = equal(r018B, body.constant(int(0)));
            ir_if *f0191 = new(mem_ctx) ir_if(operand(r0192).val);
            exec_list *const f0191_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0191->then_instructions;

               body.emit(assign(r018C, r0143, 0x01));

               body.emit(assign(r018D, r0142, 0x01));

               body.emit(assign(r018E, r0141, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0191->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0194 = less(r018B, body.constant(int(32)));
               ir_if *f0193 = new(mem_ctx) ir_if(operand(r0194).val);
               exec_list *const f0193_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0193->then_instructions;

                  body.emit(assign(r018C, lshift(r0142, r018F), 0x01));

                  ir_expression *const r0195 = lshift(r0141, r018F);
                  ir_expression *const r0196 = rshift(r0142, r018B);
                  body.emit(assign(r018D, bit_or(r0195, r0196), 0x01));

                  body.emit(assign(r018E, rshift(r0141, r018B), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0193->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0198 = equal(r018B, body.constant(int(32)));
                  ir_if *f0197 = new(mem_ctx) ir_if(operand(r0198).val);
                  exec_list *const f0197_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0197->then_instructions;

                     body.emit(assign(r018C, r0142, 0x01));

                     body.emit(assign(r018D, r0141, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0197->else_instructions;

                     body.emit(assign(r018A, bit_or(r0143, r0142), 0x01));

                     ir_expression *const r0199 = less(r018B, body.constant(int(64)));
                     ir_expression *const r019A = lshift(r0141, r018F);
                     ir_expression *const r019B = equal(r018B, body.constant(int(64)));
                     ir_expression *const r019C = nequal(r0141, body.constant(0u));
                     ir_expression *const r019D = expr(ir_unop_b2i, r019C);
                     ir_expression *const r019E = expr(ir_unop_i2u, r019D);
                     ir_expression *const r019F = expr(ir_triop_csel, r019B, r0141, r019E);
                     body.emit(assign(r018C, expr(ir_triop_csel, r0199, r019A, r019F), 0x01));

                     ir_expression *const r01A0 = less(r018B, body.constant(int(64)));
                     ir_expression *const r01A1 = bit_and(r018B, body.constant(int(31)));
                     ir_expression *const r01A2 = rshift(r0141, r01A1);
                     body.emit(assign(r018D, expr(ir_triop_csel, r01A0, r01A2, body.constant(0u)), 0x01));


                  body.instructions = f0197_parent_instructions;
                  body.emit(f0197);

                  /* END IF */

                  body.emit(assign(r018E, body.constant(0u), 0x01));


               body.instructions = f0193_parent_instructions;
               body.emit(f0193);

               /* END IF */

               ir_expression *const r01A3 = nequal(r018A, body.constant(0u));
               ir_expression *const r01A4 = expr(ir_unop_b2i, r01A3);
               ir_expression *const r01A5 = expr(ir_unop_i2u, r01A4);
               body.emit(assign(r018C, bit_or(r018C, r01A5), 0x01));


            body.instructions = f0191_parent_instructions;
            body.emit(f0191);

            /* END IF */

            body.emit(assign(r0174, r018E, 0x01));

            body.emit(assign(r0175, r018D, 0x01));

            body.emit(assign(r0176, r018C, 0x01));

            body.emit(assign(r0173, body.constant(int(0)), 0x01));

            body.emit(assign(r0179, less(r018C, body.constant(0u)), 0x01));


         body.instructions = f0188_parent_instructions;
         body.emit(f0188);

         /* END IF */


      body.instructions = f017D_parent_instructions;
      body.emit(f017D);

      /* END IF */


   body.instructions = f017B_parent_instructions;
   body.emit(f017B);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01A6 = new(mem_ctx) ir_if(operand(r0177).val);
   exec_list *const f01A6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01A6->then_instructions;

      /* IF CONDITION */
      ir_if *f01A7 = new(mem_ctx) ir_if(operand(r0179).val);
      exec_list *const f01A7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01A7->then_instructions;

         ir_variable *const r01A8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01A8, add(r0175, body.constant(1u)), 0x01));

         ir_expression *const r01A9 = less(r01A8, r0175);
         ir_expression *const r01AA = expr(ir_unop_b2i, r01A9);
         ir_expression *const r01AB = expr(ir_unop_i2u, r01AA);
         body.emit(assign(r0174, add(r0174, r01AB), 0x01));

         ir_expression *const r01AC = equal(r0176, body.constant(0u));
         ir_expression *const r01AD = expr(ir_unop_b2i, r01AC);
         ir_expression *const r01AE = expr(ir_unop_i2u, r01AD);
         ir_expression *const r01AF = add(r0176, r01AE);
         ir_expression *const r01B0 = bit_and(r01AF, body.constant(1u));
         ir_expression *const r01B1 = expr(ir_unop_bit_not, r01B0);
         body.emit(assign(r0175, bit_and(r01A8, r01B1), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01A7->else_instructions;

         ir_expression *const r01B2 = bit_or(r0174, r0175);
         ir_expression *const r01B3 = equal(r01B2, body.constant(0u));
         body.emit(assign(r0173, expr(ir_triop_csel, r01B3, body.constant(int(0)), r0173), 0x01));


      body.instructions = f01A7_parent_instructions;
      body.emit(f01A7);

      /* END IF */

      ir_variable *const r01B4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r01B4);
      ir_expression *const r01B5 = lshift(r013F, body.constant(int(31)));
      ir_expression *const r01B6 = expr(ir_unop_i2u, r0173);
      ir_expression *const r01B7 = lshift(r01B6, body.constant(int(20)));
      ir_expression *const r01B8 = add(r01B5, r01B7);
      body.emit(assign(r01B4, add(r01B8, r0174), 0x02));

      body.emit(assign(r01B4, r0175, 0x01));

      body.emit(assign(r0178, r01B4, 0x03));

      body.emit(assign(r0177, body.constant(false), 0x01));


   body.instructions = f01A6_parent_instructions;
   body.emit(f01A6);

   /* END IF */

   body.emit(ret(r0178));

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

   ir_variable *const r01B9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01B9);
   ir_variable *const r01BA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01BA);
   ir_variable *const r01BB = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01BC = lshift(swizzle_y(r01B9), body.constant(int(1)));
   ir_expression *const r01BD = gequal(r01BC, body.constant(4292870144u));
   ir_expression *const r01BE = nequal(swizzle_x(r01B9), body.constant(0u));
   ir_expression *const r01BF = bit_and(swizzle_y(r01B9), body.constant(1048575u));
   ir_expression *const r01C0 = nequal(r01BF, body.constant(0u));
   ir_expression *const r01C1 = logic_or(r01BE, r01C0);
   body.emit(assign(r01BB, logic_and(r01BD, r01C1), 0x01));

   ir_variable *const r01C2 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01C3 = lshift(swizzle_y(r01BA), body.constant(int(1)));
   ir_expression *const r01C4 = gequal(r01C3, body.constant(4292870144u));
   ir_expression *const r01C5 = nequal(swizzle_x(r01BA), body.constant(0u));
   ir_expression *const r01C6 = bit_and(swizzle_y(r01BA), body.constant(1048575u));
   ir_expression *const r01C7 = nequal(r01C6, body.constant(0u));
   ir_expression *const r01C8 = logic_or(r01C5, r01C7);
   body.emit(assign(r01C2, logic_and(r01C4, r01C8), 0x01));

   body.emit(assign(r01B9, bit_or(swizzle_y(r01B9), body.constant(524288u)), 0x02));

   body.emit(assign(r01BA, bit_or(swizzle_y(r01BA), body.constant(524288u)), 0x02));

   ir_variable *const r01C9 = body.make_temp(glsl_type::uvec2_type, "mix_retval");
   ir_swizzle *const r01CA = swizzle(r01BB, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_swizzle *const r01CB = swizzle(r01C2, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_expression *const r01CC = expr(ir_triop_csel, r01CB, r01BA, r01B9);
   body.emit(assign(r01C9, expr(ir_triop_csel, r01CA, r01CC, r01BA), 0x03));

   body.emit(ret(r01C9));

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

   ir_variable *const r01CD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01CD);
   ir_variable *const r01CE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01CE);
   ir_variable *const r01CF = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01CF, body.constant(true), 0x01));

   ir_variable *const r01D0 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01D1 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
   body.emit(r01D1);
   ir_variable *const r01D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r01D2);
   ir_variable *const r01D3 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r01D3);
   ir_variable *const r01D4 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r01D4);
   ir_variable *const r01D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r01D5);
   ir_variable *const r01D6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r01D6);
   ir_variable *const r01D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r01D7);
   ir_variable *const r01D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r01D8);
   ir_variable *const r01D9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r01D9);
   ir_variable *const r01DA = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01DA, rshift(swizzle_y(r01CD), body.constant(int(31))), 0x01));

   body.emit(assign(r01D9, r01DA, 0x01));

   ir_variable *const r01DB = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01DB, rshift(swizzle_y(r01CE), body.constant(int(31))), 0x01));

   ir_variable *const r01DC = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r01DC, swizzle_x(r01CD), 0x01));

   body.emit(assign(r01D8, r01DC, 0x01));

   ir_variable *const r01DD = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r01DD, bit_and(swizzle_y(r01CD), body.constant(1048575u)), 0x01));

   body.emit(assign(r01D7, r01DD, 0x01));

   ir_variable *const r01DE = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r01DE, swizzle_x(r01CE), 0x01));

   body.emit(assign(r01D6, r01DE, 0x01));

   ir_variable *const r01DF = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r01DF, bit_and(swizzle_y(r01CE), body.constant(1048575u)), 0x01));

   body.emit(assign(r01D5, r01DF, 0x01));

   ir_variable *const r01E0 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r01E1 = rshift(swizzle_y(r01CD), body.constant(int(20)));
   ir_expression *const r01E2 = bit_and(r01E1, body.constant(2047u));
   body.emit(assign(r01E0, expr(ir_unop_u2i, r01E2), 0x01));

   body.emit(assign(r01D4, r01E0, 0x01));

   ir_variable *const r01E3 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r01E4 = rshift(swizzle_y(r01CE), body.constant(int(20)));
   ir_expression *const r01E5 = bit_and(r01E4, body.constant(2047u));
   body.emit(assign(r01E3, expr(ir_unop_u2i, r01E5), 0x01));

   body.emit(assign(r01D3, r01E3, 0x01));

   body.emit(assign(r01D2, body.constant(0u), 0x01));

   ir_variable *const r01E6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r01E6, sub(r01E0, r01E3), 0x01));

   body.emit(assign(r01D1, r01E6, 0x01));

   /* IF CONDITION */
   ir_expression *const r01E8 = equal(r01DA, r01DB);
   ir_if *f01E7 = new(mem_ctx) ir_if(operand(r01E8).val);
   exec_list *const f01E7_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01E7->then_instructions;

      ir_variable *const r01E9 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r01E9);
      ir_variable *const r01EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r01EA);
      body.emit(assign(r01EA, body.constant(0u), 0x01));

      /* IF CONDITION */
      ir_expression *const r01EC = less(body.constant(int(0)), r01E6);
      ir_if *f01EB = new(mem_ctx) ir_if(operand(r01EC).val);
      exec_list *const f01EB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01EB->then_instructions;

         /* IF CONDITION */
         ir_expression *const r01EE = equal(r01E0, body.constant(int(2047)));
         ir_if *f01ED = new(mem_ctx) ir_if(operand(r01EE).val);
         exec_list *const f01ED_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01ED->then_instructions;

            ir_variable *const r01EF = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r01EF, swizzle_x(r01CD), 0x01));

            ir_variable *const r01F0 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r01F0, swizzle_x(r01CE), 0x01));

            body.emit(assign(r01EF, bit_or(swizzle_y(r01CD), body.constant(524288u)), 0x02));

            body.emit(assign(r01F0, bit_or(swizzle_y(r01CE), body.constant(524288u)), 0x02));

            ir_expression *const r01F1 = bit_or(r01DD, swizzle_x(r01CD));
            ir_expression *const r01F2 = nequal(r01F1, body.constant(0u));
            ir_swizzle *const r01F3 = swizzle(r01F2, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r01F4 = lshift(swizzle_y(r01CD), body.constant(int(1)));
            ir_expression *const r01F5 = gequal(r01F4, body.constant(4292870144u));
            ir_expression *const r01F6 = nequal(swizzle_x(r01CD), body.constant(0u));
            ir_expression *const r01F7 = bit_and(swizzle_y(r01CD), body.constant(1048575u));
            ir_expression *const r01F8 = nequal(r01F7, body.constant(0u));
            ir_expression *const r01F9 = logic_or(r01F6, r01F8);
            ir_expression *const r01FA = logic_and(r01F5, r01F9);
            ir_swizzle *const r01FB = swizzle(r01FA, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r01FC = lshift(swizzle_y(r01CE), body.constant(int(1)));
            ir_expression *const r01FD = gequal(r01FC, body.constant(4292870144u));
            ir_expression *const r01FE = nequal(swizzle_x(r01CE), body.constant(0u));
            ir_expression *const r01FF = bit_and(swizzle_y(r01CE), body.constant(1048575u));
            ir_expression *const r0200 = nequal(r01FF, body.constant(0u));
            ir_expression *const r0201 = logic_or(r01FE, r0200);
            ir_expression *const r0202 = logic_and(r01FD, r0201);
            ir_swizzle *const r0203 = swizzle(r0202, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0204 = expr(ir_triop_csel, r0203, r01F0, r01EF);
            ir_expression *const r0205 = expr(ir_triop_csel, r01FB, r0204, r01F0);
            body.emit(assign(r01D0, expr(ir_triop_csel, r01F3, r0205, r01CD), 0x03));

            body.emit(assign(r01CF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f01ED->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0207 = equal(r01E3, body.constant(int(0)));
            ir_if *f0206 = new(mem_ctx) ir_if(operand(r0207).val);
            exec_list *const f0206_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0206->then_instructions;

               body.emit(assign(r01D1, add(r01E6, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0206->else_instructions;

               body.emit(assign(r01D5, bit_or(r01DF, body.constant(1048576u)), 0x01));


            body.instructions = f0206_parent_instructions;
            body.emit(f0206);

            /* END IF */

            ir_variable *const r0208 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0208, body.constant(0u), 0x01));

            ir_variable *const r0209 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0209);
            ir_variable *const r020A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r020A);
            ir_variable *const r020B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r020B);
            ir_variable *const r020C = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r020D = neg(r01D1);
            body.emit(assign(r020C, bit_and(r020D, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r020F = equal(r01D1, body.constant(int(0)));
            ir_if *f020E = new(mem_ctx) ir_if(operand(r020F).val);
            exec_list *const f020E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f020E->then_instructions;

               body.emit(assign(r0209, r0208, 0x01));

               body.emit(assign(r020A, r01DE, 0x01));

               body.emit(assign(r020B, r01D5, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f020E->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0211 = less(r01D1, body.constant(int(32)));
               ir_if *f0210 = new(mem_ctx) ir_if(operand(r0211).val);
               exec_list *const f0210_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0210->then_instructions;

                  body.emit(assign(r0209, lshift(swizzle_x(r01CE), r020C), 0x01));

                  ir_expression *const r0212 = lshift(r01D5, r020C);
                  ir_expression *const r0213 = rshift(swizzle_x(r01CE), r01D1);
                  body.emit(assign(r020A, bit_or(r0212, r0213), 0x01));

                  body.emit(assign(r020B, rshift(r01D5, r01D1), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0210->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0215 = equal(r01D1, body.constant(int(32)));
                  ir_if *f0214 = new(mem_ctx) ir_if(operand(r0215).val);
                  exec_list *const f0214_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0214->then_instructions;

                     body.emit(assign(r0209, r01DE, 0x01));

                     body.emit(assign(r020A, r01D5, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0214->else_instructions;

                     body.emit(assign(r0208, bit_or(body.constant(0u), swizzle_x(r01CE)), 0x01));

                     ir_expression *const r0216 = less(r01D1, body.constant(int(64)));
                     ir_expression *const r0217 = lshift(r01D5, r020C);
                     ir_expression *const r0218 = equal(r01D1, body.constant(int(64)));
                     ir_expression *const r0219 = nequal(r01D5, body.constant(0u));
                     ir_expression *const r021A = expr(ir_unop_b2i, r0219);
                     ir_expression *const r021B = expr(ir_unop_i2u, r021A);
                     ir_expression *const r021C = expr(ir_triop_csel, r0218, r01D5, r021B);
                     body.emit(assign(r0209, expr(ir_triop_csel, r0216, r0217, r021C), 0x01));

                     ir_expression *const r021D = less(r01D1, body.constant(int(64)));
                     ir_expression *const r021E = bit_and(r01D1, body.constant(int(31)));
                     ir_expression *const r021F = rshift(r01D5, r021E);
                     body.emit(assign(r020A, expr(ir_triop_csel, r021D, r021F, body.constant(0u)), 0x01));


                  body.instructions = f0214_parent_instructions;
                  body.emit(f0214);

                  /* END IF */

                  body.emit(assign(r020B, body.constant(0u), 0x01));


               body.instructions = f0210_parent_instructions;
               body.emit(f0210);

               /* END IF */

               ir_expression *const r0220 = nequal(r0208, body.constant(0u));
               ir_expression *const r0221 = expr(ir_unop_b2i, r0220);
               ir_expression *const r0222 = expr(ir_unop_i2u, r0221);
               body.emit(assign(r0209, bit_or(r0209, r0222), 0x01));


            body.instructions = f020E_parent_instructions;
            body.emit(f020E);

            /* END IF */

            body.emit(assign(r01D5, r020B, 0x01));

            body.emit(assign(r01D6, r020A, 0x01));

            body.emit(assign(r01EA, r0209, 0x01));

            body.emit(assign(r01E9, r01E0, 0x01));


         body.instructions = f01ED_parent_instructions;
         body.emit(f01ED);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01EB->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0224 = less(r01D1, body.constant(int(0)));
         ir_if *f0223 = new(mem_ctx) ir_if(operand(r0224).val);
         exec_list *const f0223_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0223->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0226 = equal(r01E3, body.constant(int(2047)));
            ir_if *f0225 = new(mem_ctx) ir_if(operand(r0226).val);
            exec_list *const f0225_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0225->then_instructions;

               ir_variable *const r0227 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0227);
               ir_expression *const r0228 = lshift(r01DA, body.constant(int(31)));
               body.emit(assign(r0227, add(r0228, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0227, body.constant(0u), 0x01));

               ir_variable *const r0229 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0229, swizzle_x(r01CD), 0x01));

               ir_variable *const r022A = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r022A, swizzle_x(r01CE), 0x01));

               body.emit(assign(r0229, bit_or(swizzle_y(r01CD), body.constant(524288u)), 0x02));

               body.emit(assign(r022A, bit_or(swizzle_y(r01CE), body.constant(524288u)), 0x02));

               ir_expression *const r022B = bit_or(r01D5, r01D6);
               ir_expression *const r022C = nequal(r022B, body.constant(0u));
               ir_swizzle *const r022D = swizzle(r022C, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r022E = lshift(swizzle_y(r01CD), body.constant(int(1)));
               ir_expression *const r022F = gequal(r022E, body.constant(4292870144u));
               ir_expression *const r0230 = nequal(swizzle_x(r01CD), body.constant(0u));
               ir_expression *const r0231 = bit_and(swizzle_y(r01CD), body.constant(1048575u));
               ir_expression *const r0232 = nequal(r0231, body.constant(0u));
               ir_expression *const r0233 = logic_or(r0230, r0232);
               ir_expression *const r0234 = logic_and(r022F, r0233);
               ir_swizzle *const r0235 = swizzle(r0234, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0236 = lshift(swizzle_y(r01CE), body.constant(int(1)));
               ir_expression *const r0237 = gequal(r0236, body.constant(4292870144u));
               ir_expression *const r0238 = nequal(swizzle_x(r01CE), body.constant(0u));
               ir_expression *const r0239 = bit_and(swizzle_y(r01CE), body.constant(1048575u));
               ir_expression *const r023A = nequal(r0239, body.constant(0u));
               ir_expression *const r023B = logic_or(r0238, r023A);
               ir_expression *const r023C = logic_and(r0237, r023B);
               ir_swizzle *const r023D = swizzle(r023C, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r023E = expr(ir_triop_csel, r023D, r022A, r0229);
               ir_expression *const r023F = expr(ir_triop_csel, r0235, r023E, r022A);
               body.emit(assign(r01D0, expr(ir_triop_csel, r022D, r023F, r0227), 0x03));

               body.emit(assign(r01CF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0225->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0241 = equal(r01E0, body.constant(int(0)));
               ir_if *f0240 = new(mem_ctx) ir_if(operand(r0241).val);
               exec_list *const f0240_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0240->then_instructions;

                  body.emit(assign(r01D1, add(r01D1, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0240->else_instructions;

                  body.emit(assign(r01D7, bit_or(r01DD, body.constant(1048576u)), 0x01));


               body.instructions = f0240_parent_instructions;
               body.emit(f0240);

               /* END IF */

               ir_variable *const r0242 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0242, body.constant(0u), 0x01));

               ir_variable *const r0243 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0243, neg(r01D1), 0x01));

               ir_variable *const r0244 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0244);
               ir_variable *const r0245 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0245);
               ir_variable *const r0246 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0246);
               ir_variable *const r0247 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0248 = neg(r0243);
               body.emit(assign(r0247, bit_and(r0248, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r024A = equal(r0243, body.constant(int(0)));
               ir_if *f0249 = new(mem_ctx) ir_if(operand(r024A).val);
               exec_list *const f0249_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0249->then_instructions;

                  body.emit(assign(r0244, r0242, 0x01));

                  body.emit(assign(r0245, r01DC, 0x01));

                  body.emit(assign(r0246, r01D7, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0249->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r024C = less(r0243, body.constant(int(32)));
                  ir_if *f024B = new(mem_ctx) ir_if(operand(r024C).val);
                  exec_list *const f024B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f024B->then_instructions;

                     body.emit(assign(r0244, lshift(swizzle_x(r01CD), r0247), 0x01));

                     ir_expression *const r024D = lshift(r01D7, r0247);
                     ir_expression *const r024E = rshift(swizzle_x(r01CD), r0243);
                     body.emit(assign(r0245, bit_or(r024D, r024E), 0x01));

                     body.emit(assign(r0246, rshift(r01D7, r0243), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f024B->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0250 = equal(r0243, body.constant(int(32)));
                     ir_if *f024F = new(mem_ctx) ir_if(operand(r0250).val);
                     exec_list *const f024F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f024F->then_instructions;

                        body.emit(assign(r0244, r01DC, 0x01));

                        body.emit(assign(r0245, r01D7, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f024F->else_instructions;

                        body.emit(assign(r0242, bit_or(body.constant(0u), swizzle_x(r01CD)), 0x01));

                        ir_expression *const r0251 = less(r0243, body.constant(int(64)));
                        ir_expression *const r0252 = lshift(r01D7, r0247);
                        ir_expression *const r0253 = equal(r0243, body.constant(int(64)));
                        ir_expression *const r0254 = nequal(r01D7, body.constant(0u));
                        ir_expression *const r0255 = expr(ir_unop_b2i, r0254);
                        ir_expression *const r0256 = expr(ir_unop_i2u, r0255);
                        ir_expression *const r0257 = expr(ir_triop_csel, r0253, r01D7, r0256);
                        body.emit(assign(r0244, expr(ir_triop_csel, r0251, r0252, r0257), 0x01));

                        ir_expression *const r0258 = less(r0243, body.constant(int(64)));
                        ir_expression *const r0259 = bit_and(r0243, body.constant(int(31)));
                        ir_expression *const r025A = rshift(r01D7, r0259);
                        body.emit(assign(r0245, expr(ir_triop_csel, r0258, r025A, body.constant(0u)), 0x01));


                     body.instructions = f024F_parent_instructions;
                     body.emit(f024F);

                     /* END IF */

                     body.emit(assign(r0246, body.constant(0u), 0x01));


                  body.instructions = f024B_parent_instructions;
                  body.emit(f024B);

                  /* END IF */

                  ir_expression *const r025B = nequal(r0242, body.constant(0u));
                  ir_expression *const r025C = expr(ir_unop_b2i, r025B);
                  ir_expression *const r025D = expr(ir_unop_i2u, r025C);
                  body.emit(assign(r0244, bit_or(r0244, r025D), 0x01));


               body.instructions = f0249_parent_instructions;
               body.emit(f0249);

               /* END IF */

               body.emit(assign(r01D7, r0246, 0x01));

               body.emit(assign(r01D8, r0245, 0x01));

               body.emit(assign(r01EA, r0244, 0x01));

               body.emit(assign(r01E9, r01E3, 0x01));


            body.instructions = f0225_parent_instructions;
            body.emit(f0225);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0223->else_instructions;

            /* IF CONDITION */
            ir_expression *const r025F = equal(r01E0, body.constant(int(2047)));
            ir_if *f025E = new(mem_ctx) ir_if(operand(r025F).val);
            exec_list *const f025E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f025E->then_instructions;

               ir_variable *const r0260 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0260, swizzle_x(r01CD), 0x01));

               ir_variable *const r0261 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0261, swizzle_x(r01CE), 0x01));

               body.emit(assign(r0260, bit_or(swizzle_y(r01CD), body.constant(524288u)), 0x02));

               body.emit(assign(r0261, bit_or(swizzle_y(r01CE), body.constant(524288u)), 0x02));

               ir_expression *const r0262 = bit_or(r01D7, r01D8);
               ir_expression *const r0263 = bit_or(r01D5, r01D6);
               ir_expression *const r0264 = bit_or(r0262, r0263);
               ir_expression *const r0265 = nequal(r0264, body.constant(0u));
               ir_swizzle *const r0266 = swizzle(r0265, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0267 = lshift(swizzle_y(r01CD), body.constant(int(1)));
               ir_expression *const r0268 = gequal(r0267, body.constant(4292870144u));
               ir_expression *const r0269 = nequal(swizzle_x(r01CD), body.constant(0u));
               ir_expression *const r026A = bit_and(swizzle_y(r01CD), body.constant(1048575u));
               ir_expression *const r026B = nequal(r026A, body.constant(0u));
               ir_expression *const r026C = logic_or(r0269, r026B);
               ir_expression *const r026D = logic_and(r0268, r026C);
               ir_swizzle *const r026E = swizzle(r026D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r026F = lshift(swizzle_y(r01CE), body.constant(int(1)));
               ir_expression *const r0270 = gequal(r026F, body.constant(4292870144u));
               ir_expression *const r0271 = nequal(swizzle_x(r01CE), body.constant(0u));
               ir_expression *const r0272 = bit_and(swizzle_y(r01CE), body.constant(1048575u));
               ir_expression *const r0273 = nequal(r0272, body.constant(0u));
               ir_expression *const r0274 = logic_or(r0271, r0273);
               ir_expression *const r0275 = logic_and(r0270, r0274);
               ir_swizzle *const r0276 = swizzle(r0275, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0277 = expr(ir_triop_csel, r0276, r0261, r0260);
               ir_expression *const r0278 = expr(ir_triop_csel, r026E, r0277, r0261);
               body.emit(assign(r01D0, expr(ir_triop_csel, r0266, r0278, r01CD), 0x03));

               body.emit(assign(r01CF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f025E->else_instructions;

               ir_variable *const r0279 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r027A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r027A, add(r01D8, r01D6), 0x01));

               ir_expression *const r027B = add(r01D7, r01D5);
               ir_expression *const r027C = less(r027A, r01D8);
               ir_expression *const r027D = expr(ir_unop_b2i, r027C);
               ir_expression *const r027E = expr(ir_unop_i2u, r027D);
               body.emit(assign(r0279, add(r027B, r027E), 0x01));

               body.emit(assign(r01D2, r0279, 0x01));

               /* IF CONDITION */
               ir_expression *const r0280 = equal(r01E0, body.constant(int(0)));
               ir_if *f027F = new(mem_ctx) ir_if(operand(r0280).val);
               exec_list *const f027F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f027F->then_instructions;

                  ir_variable *const r0281 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0281);
                  ir_expression *const r0282 = lshift(r01DA, body.constant(int(31)));
                  body.emit(assign(r0281, add(r0282, r0279), 0x02));

                  body.emit(assign(r0281, r027A, 0x01));

                  body.emit(assign(r01D0, r0281, 0x03));

                  body.emit(assign(r01CF, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f027F->else_instructions;

                  body.emit(assign(r01D2, bit_or(r0279, body.constant(2097152u)), 0x01));

                  body.emit(assign(r01E9, r01E0, 0x01));

                  ir_variable *const r0283 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0283);
                  ir_variable *const r0284 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r0284);
                  ir_variable *const r0285 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r0285);
                  body.emit(assign(r0283, lshift(r027A, body.constant(int(31))), 0x01));

                  ir_expression *const r0286 = lshift(r01D2, body.constant(int(31)));
                  ir_expression *const r0287 = rshift(r027A, body.constant(int(1)));
                  body.emit(assign(r0284, bit_or(r0286, r0287), 0x01));

                  body.emit(assign(r0285, rshift(r01D2, body.constant(int(1))), 0x01));

                  body.emit(assign(r0283, bit_or(r0283, body.constant(0u)), 0x01));

                  body.emit(assign(r01D2, r0285, 0x01));

                  body.emit(assign(r01EA, r0283, 0x01));

                  ir_variable *const r0288 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0288, r01E0, 0x01));

                  ir_variable *const r0289 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0289, r0285, 0x01));

                  ir_variable *const r028A = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r028A, r0284, 0x01));

                  ir_variable *const r028B = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r028B, r0283, 0x01));

                  ir_variable *const r028C = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r028C, body.constant(true), 0x01));

                  ir_variable *const r028D = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r028E = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r028E);
                  ir_expression *const r028F = expr(ir_unop_u2i, r0283);
                  body.emit(assign(r028E, less(r028F, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0291 = gequal(r01E0, body.constant(int(2045)));
                  ir_if *f0290 = new(mem_ctx) ir_if(operand(r0291).val);
                  exec_list *const f0290_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0290->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0293 = less(body.constant(int(2045)), r01E0);
                     ir_expression *const r0294 = equal(r01E0, body.constant(int(2045)));
                     ir_expression *const r0295 = equal(body.constant(2097151u), r0285);
                     ir_expression *const r0296 = equal(body.constant(4294967295u), r0284);
                     ir_expression *const r0297 = logic_and(r0295, r0296);
                     ir_expression *const r0298 = logic_and(r0294, r0297);
                     ir_expression *const r0299 = logic_and(r0298, r028E);
                     ir_expression *const r029A = logic_or(r0293, r0299);
                     ir_if *f0292 = new(mem_ctx) ir_if(operand(r029A).val);
                     exec_list *const f0292_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0292->then_instructions;

                        ir_variable *const r029B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r029B);
                        ir_expression *const r029C = lshift(r01DA, body.constant(int(31)));
                        body.emit(assign(r029B, add(r029C, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r029B, body.constant(0u), 0x01));

                        body.emit(assign(r028D, r029B, 0x03));

                        body.emit(assign(r028C, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0292->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r029E = less(r01E0, body.constant(int(0)));
                        ir_if *f029D = new(mem_ctx) ir_if(operand(r029E).val);
                        exec_list *const f029D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f029D->then_instructions;

                           ir_variable *const r029F = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r029F, r0283, 0x01));

                           ir_variable *const r02A0 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r02A0, neg(r01E0), 0x01));

                           ir_variable *const r02A1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r02A1);
                           ir_variable *const r02A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r02A2);
                           ir_variable *const r02A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r02A3);
                           ir_variable *const r02A4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02A5 = neg(r02A0);
                           body.emit(assign(r02A4, bit_and(r02A5, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02A7 = equal(r02A0, body.constant(int(0)));
                           ir_if *f02A6 = new(mem_ctx) ir_if(operand(r02A7).val);
                           exec_list *const f02A6_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02A6->then_instructions;

                              body.emit(assign(r02A1, r0283, 0x01));

                              body.emit(assign(r02A2, r0284, 0x01));

                              body.emit(assign(r02A3, r0285, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02A6->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02A9 = less(r02A0, body.constant(int(32)));
                              ir_if *f02A8 = new(mem_ctx) ir_if(operand(r02A9).val);
                              exec_list *const f02A8_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02A8->then_instructions;

                                 body.emit(assign(r02A1, lshift(r0284, r02A4), 0x01));

                                 ir_expression *const r02AA = lshift(r0285, r02A4);
                                 ir_expression *const r02AB = rshift(r0284, r02A0);
                                 body.emit(assign(r02A2, bit_or(r02AA, r02AB), 0x01));

                                 body.emit(assign(r02A3, rshift(r0285, r02A0), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02A8->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02AD = equal(r02A0, body.constant(int(32)));
                                 ir_if *f02AC = new(mem_ctx) ir_if(operand(r02AD).val);
                                 exec_list *const f02AC_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02AC->then_instructions;

                                    body.emit(assign(r02A1, r0284, 0x01));

                                    body.emit(assign(r02A2, r0285, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02AC->else_instructions;

                                    body.emit(assign(r029F, bit_or(r0283, r0284), 0x01));

                                    ir_expression *const r02AE = less(r02A0, body.constant(int(64)));
                                    ir_expression *const r02AF = lshift(r0285, r02A4);
                                    ir_expression *const r02B0 = equal(r02A0, body.constant(int(64)));
                                    ir_expression *const r02B1 = nequal(r0285, body.constant(0u));
                                    ir_expression *const r02B2 = expr(ir_unop_b2i, r02B1);
                                    ir_expression *const r02B3 = expr(ir_unop_i2u, r02B2);
                                    ir_expression *const r02B4 = expr(ir_triop_csel, r02B0, r0285, r02B3);
                                    body.emit(assign(r02A1, expr(ir_triop_csel, r02AE, r02AF, r02B4), 0x01));

                                    ir_expression *const r02B5 = less(r02A0, body.constant(int(64)));
                                    ir_expression *const r02B6 = bit_and(r02A0, body.constant(int(31)));
                                    ir_expression *const r02B7 = rshift(r0285, r02B6);
                                    body.emit(assign(r02A2, expr(ir_triop_csel, r02B5, r02B7, body.constant(0u)), 0x01));


                                 body.instructions = f02AC_parent_instructions;
                                 body.emit(f02AC);

                                 /* END IF */

                                 body.emit(assign(r02A3, body.constant(0u), 0x01));


                              body.instructions = f02A8_parent_instructions;
                              body.emit(f02A8);

                              /* END IF */

                              ir_expression *const r02B8 = nequal(r029F, body.constant(0u));
                              ir_expression *const r02B9 = expr(ir_unop_b2i, r02B8);
                              ir_expression *const r02BA = expr(ir_unop_i2u, r02B9);
                              body.emit(assign(r02A1, bit_or(r02A1, r02BA), 0x01));


                           body.instructions = f02A6_parent_instructions;
                           body.emit(f02A6);

                           /* END IF */

                           body.emit(assign(r0289, r02A3, 0x01));

                           body.emit(assign(r028A, r02A2, 0x01));

                           body.emit(assign(r028B, r02A1, 0x01));

                           body.emit(assign(r0288, body.constant(int(0)), 0x01));

                           body.emit(assign(r028E, less(r02A1, body.constant(0u)), 0x01));


                        body.instructions = f029D_parent_instructions;
                        body.emit(f029D);

                        /* END IF */


                     body.instructions = f0292_parent_instructions;
                     body.emit(f0292);

                     /* END IF */


                  body.instructions = f0290_parent_instructions;
                  body.emit(f0290);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02BB = new(mem_ctx) ir_if(operand(r028C).val);
                  exec_list *const f02BB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02BB->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02BC = new(mem_ctx) ir_if(operand(r028E).val);
                     exec_list *const f02BC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02BC->then_instructions;

                        ir_variable *const r02BD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02BD, add(r028A, body.constant(1u)), 0x01));

                        ir_expression *const r02BE = less(r02BD, r028A);
                        ir_expression *const r02BF = expr(ir_unop_b2i, r02BE);
                        ir_expression *const r02C0 = expr(ir_unop_i2u, r02BF);
                        body.emit(assign(r0289, add(r0289, r02C0), 0x01));

                        ir_expression *const r02C1 = equal(r028B, body.constant(0u));
                        ir_expression *const r02C2 = expr(ir_unop_b2i, r02C1);
                        ir_expression *const r02C3 = expr(ir_unop_i2u, r02C2);
                        ir_expression *const r02C4 = add(r028B, r02C3);
                        ir_expression *const r02C5 = bit_and(r02C4, body.constant(1u));
                        ir_expression *const r02C6 = expr(ir_unop_bit_not, r02C5);
                        body.emit(assign(r028A, bit_and(r02BD, r02C6), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02BC->else_instructions;

                        ir_expression *const r02C7 = bit_or(r0289, r028A);
                        ir_expression *const r02C8 = equal(r02C7, body.constant(0u));
                        body.emit(assign(r0288, expr(ir_triop_csel, r02C8, body.constant(int(0)), r0288), 0x01));


                     body.instructions = f02BC_parent_instructions;
                     body.emit(f02BC);

                     /* END IF */

                     ir_variable *const r02C9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r02C9);
                     ir_expression *const r02CA = lshift(r01DA, body.constant(int(31)));
                     ir_expression *const r02CB = expr(ir_unop_i2u, r0288);
                     ir_expression *const r02CC = lshift(r02CB, body.constant(int(20)));
                     ir_expression *const r02CD = add(r02CA, r02CC);
                     body.emit(assign(r02C9, add(r02CD, r0289), 0x02));

                     body.emit(assign(r02C9, r028A, 0x01));

                     body.emit(assign(r028D, r02C9, 0x03));

                     body.emit(assign(r028C, body.constant(false), 0x01));


                  body.instructions = f02BB_parent_instructions;
                  body.emit(f02BB);

                  /* END IF */

                  body.emit(assign(r01D0, r028D, 0x03));

                  body.emit(assign(r01CF, body.constant(false), 0x01));


               body.instructions = f027F_parent_instructions;
               body.emit(f027F);

               /* END IF */


            body.instructions = f025E_parent_instructions;
            body.emit(f025E);

            /* END IF */


         body.instructions = f0223_parent_instructions;
         body.emit(f0223);

         /* END IF */


      body.instructions = f01EB_parent_instructions;
      body.emit(f01EB);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02CE = new(mem_ctx) ir_if(operand(r01CF).val);
      exec_list *const f02CE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02CE->then_instructions;

         body.emit(assign(r01D7, bit_or(r01D7, body.constant(1048576u)), 0x01));

         ir_variable *const r02CF = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r02D0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r02D0, add(r01D8, r01D6), 0x01));

         ir_expression *const r02D1 = add(r01D7, r01D5);
         ir_expression *const r02D2 = less(r02D0, r01D8);
         ir_expression *const r02D3 = expr(ir_unop_b2i, r02D2);
         ir_expression *const r02D4 = expr(ir_unop_i2u, r02D3);
         body.emit(assign(r02CF, add(r02D1, r02D4), 0x01));

         body.emit(assign(r01D2, r02CF, 0x01));

         body.emit(assign(r01E9, add(r01E9, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r02D6 = less(r02CF, body.constant(2097152u));
         ir_if *f02D5 = new(mem_ctx) ir_if(operand(r02D6).val);
         exec_list *const f02D5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02D5->then_instructions;

            ir_variable *const r02D7 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r02D7, r01E9, 0x01));

            ir_variable *const r02D8 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r02D8, r02CF, 0x01));

            ir_variable *const r02D9 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r02D9, r02D0, 0x01));

            ir_variable *const r02DA = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r02DA, r01EA, 0x01));

            ir_variable *const r02DB = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r02DB, body.constant(true), 0x01));

            ir_variable *const r02DC = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r02DD = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r02DD);
            ir_expression *const r02DE = expr(ir_unop_u2i, r01EA);
            body.emit(assign(r02DD, less(r02DE, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02E0 = gequal(r01E9, body.constant(int(2045)));
            ir_if *f02DF = new(mem_ctx) ir_if(operand(r02E0).val);
            exec_list *const f02DF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02DF->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02E2 = less(body.constant(int(2045)), r01E9);
               ir_expression *const r02E3 = equal(r01E9, body.constant(int(2045)));
               ir_expression *const r02E4 = equal(body.constant(2097151u), r02CF);
               ir_expression *const r02E5 = equal(body.constant(4294967295u), r02D0);
               ir_expression *const r02E6 = logic_and(r02E4, r02E5);
               ir_expression *const r02E7 = logic_and(r02E3, r02E6);
               ir_expression *const r02E8 = logic_and(r02E7, r02DD);
               ir_expression *const r02E9 = logic_or(r02E2, r02E8);
               ir_if *f02E1 = new(mem_ctx) ir_if(operand(r02E9).val);
               exec_list *const f02E1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02E1->then_instructions;

                  ir_variable *const r02EA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02EA);
                  ir_expression *const r02EB = lshift(r01DA, body.constant(int(31)));
                  body.emit(assign(r02EA, add(r02EB, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r02EA, body.constant(0u), 0x01));

                  body.emit(assign(r02DC, r02EA, 0x03));

                  body.emit(assign(r02DB, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02E1->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r02ED = less(r01E9, body.constant(int(0)));
                  ir_if *f02EC = new(mem_ctx) ir_if(operand(r02ED).val);
                  exec_list *const f02EC_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02EC->then_instructions;

                     ir_variable *const r02EE = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r02EE, r01EA, 0x01));

                     ir_variable *const r02EF = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r02EF, neg(r01E9), 0x01));

                     ir_variable *const r02F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r02F0);
                     ir_variable *const r02F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r02F1);
                     ir_variable *const r02F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r02F2);
                     ir_variable *const r02F3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r02F4 = neg(r02EF);
                     body.emit(assign(r02F3, bit_and(r02F4, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r02F6 = equal(r02EF, body.constant(int(0)));
                     ir_if *f02F5 = new(mem_ctx) ir_if(operand(r02F6).val);
                     exec_list *const f02F5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02F5->then_instructions;

                        body.emit(assign(r02F0, r01EA, 0x01));

                        body.emit(assign(r02F1, r02D0, 0x01));

                        body.emit(assign(r02F2, r02CF, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02F5->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02F8 = less(r02EF, body.constant(int(32)));
                        ir_if *f02F7 = new(mem_ctx) ir_if(operand(r02F8).val);
                        exec_list *const f02F7_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02F7->then_instructions;

                           body.emit(assign(r02F0, lshift(r02D0, r02F3), 0x01));

                           ir_expression *const r02F9 = lshift(r02CF, r02F3);
                           ir_expression *const r02FA = rshift(r02D0, r02EF);
                           body.emit(assign(r02F1, bit_or(r02F9, r02FA), 0x01));

                           body.emit(assign(r02F2, rshift(r02CF, r02EF), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f02F7->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r02FC = equal(r02EF, body.constant(int(32)));
                           ir_if *f02FB = new(mem_ctx) ir_if(operand(r02FC).val);
                           exec_list *const f02FB_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02FB->then_instructions;

                              body.emit(assign(r02F0, r02D0, 0x01));

                              body.emit(assign(r02F1, r02CF, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02FB->else_instructions;

                              body.emit(assign(r02EE, bit_or(r01EA, r02D0), 0x01));

                              ir_expression *const r02FD = less(r02EF, body.constant(int(64)));
                              ir_expression *const r02FE = lshift(r02CF, r02F3);
                              ir_expression *const r02FF = equal(r02EF, body.constant(int(64)));
                              ir_expression *const r0300 = nequal(r02CF, body.constant(0u));
                              ir_expression *const r0301 = expr(ir_unop_b2i, r0300);
                              ir_expression *const r0302 = expr(ir_unop_i2u, r0301);
                              ir_expression *const r0303 = expr(ir_triop_csel, r02FF, r02CF, r0302);
                              body.emit(assign(r02F0, expr(ir_triop_csel, r02FD, r02FE, r0303), 0x01));

                              ir_expression *const r0304 = less(r02EF, body.constant(int(64)));
                              ir_expression *const r0305 = bit_and(r02EF, body.constant(int(31)));
                              ir_expression *const r0306 = rshift(r02CF, r0305);
                              body.emit(assign(r02F1, expr(ir_triop_csel, r0304, r0306, body.constant(0u)), 0x01));


                           body.instructions = f02FB_parent_instructions;
                           body.emit(f02FB);

                           /* END IF */

                           body.emit(assign(r02F2, body.constant(0u), 0x01));


                        body.instructions = f02F7_parent_instructions;
                        body.emit(f02F7);

                        /* END IF */

                        ir_expression *const r0307 = nequal(r02EE, body.constant(0u));
                        ir_expression *const r0308 = expr(ir_unop_b2i, r0307);
                        ir_expression *const r0309 = expr(ir_unop_i2u, r0308);
                        body.emit(assign(r02F0, bit_or(r02F0, r0309), 0x01));


                     body.instructions = f02F5_parent_instructions;
                     body.emit(f02F5);

                     /* END IF */

                     body.emit(assign(r02D8, r02F2, 0x01));

                     body.emit(assign(r02D9, r02F1, 0x01));

                     body.emit(assign(r02DA, r02F0, 0x01));

                     body.emit(assign(r02D7, body.constant(int(0)), 0x01));

                     body.emit(assign(r02DD, less(r02F0, body.constant(0u)), 0x01));


                  body.instructions = f02EC_parent_instructions;
                  body.emit(f02EC);

                  /* END IF */


               body.instructions = f02E1_parent_instructions;
               body.emit(f02E1);

               /* END IF */


            body.instructions = f02DF_parent_instructions;
            body.emit(f02DF);

            /* END IF */

            /* IF CONDITION */
            ir_if *f030A = new(mem_ctx) ir_if(operand(r02DB).val);
            exec_list *const f030A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f030A->then_instructions;

               /* IF CONDITION */
               ir_if *f030B = new(mem_ctx) ir_if(operand(r02DD).val);
               exec_list *const f030B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f030B->then_instructions;

                  ir_variable *const r030C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r030C, add(r02D9, body.constant(1u)), 0x01));

                  ir_expression *const r030D = less(r030C, r02D9);
                  ir_expression *const r030E = expr(ir_unop_b2i, r030D);
                  ir_expression *const r030F = expr(ir_unop_i2u, r030E);
                  body.emit(assign(r02D8, add(r02D8, r030F), 0x01));

                  ir_expression *const r0310 = equal(r02DA, body.constant(0u));
                  ir_expression *const r0311 = expr(ir_unop_b2i, r0310);
                  ir_expression *const r0312 = expr(ir_unop_i2u, r0311);
                  ir_expression *const r0313 = add(r02DA, r0312);
                  ir_expression *const r0314 = bit_and(r0313, body.constant(1u));
                  ir_expression *const r0315 = expr(ir_unop_bit_not, r0314);
                  body.emit(assign(r02D9, bit_and(r030C, r0315), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f030B->else_instructions;

                  ir_expression *const r0316 = bit_or(r02D8, r02D9);
                  ir_expression *const r0317 = equal(r0316, body.constant(0u));
                  body.emit(assign(r02D7, expr(ir_triop_csel, r0317, body.constant(int(0)), r02D7), 0x01));


               body.instructions = f030B_parent_instructions;
               body.emit(f030B);

               /* END IF */

               ir_variable *const r0318 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0318);
               ir_expression *const r0319 = lshift(r01DA, body.constant(int(31)));
               ir_expression *const r031A = expr(ir_unop_i2u, r02D7);
               ir_expression *const r031B = lshift(r031A, body.constant(int(20)));
               ir_expression *const r031C = add(r0319, r031B);
               body.emit(assign(r0318, add(r031C, r02D8), 0x02));

               body.emit(assign(r0318, r02D9, 0x01));

               body.emit(assign(r02DC, r0318, 0x03));

               body.emit(assign(r02DB, body.constant(false), 0x01));


            body.instructions = f030A_parent_instructions;
            body.emit(f030A);

            /* END IF */

            body.emit(assign(r01D0, r02DC, 0x03));

            body.emit(assign(r01CF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02D5->else_instructions;

            body.emit(assign(r01E9, add(r01E9, body.constant(int(1))), 0x01));

            ir_variable *const r031D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r031D);
            ir_variable *const r031E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r031E);
            ir_variable *const r031F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r031F);
            body.emit(assign(r031D, lshift(r02D0, body.constant(int(31))), 0x01));

            ir_expression *const r0320 = lshift(r02CF, body.constant(int(31)));
            ir_expression *const r0321 = rshift(r02D0, body.constant(int(1)));
            body.emit(assign(r031E, bit_or(r0320, r0321), 0x01));

            body.emit(assign(r031F, rshift(r02CF, body.constant(int(1))), 0x01));

            ir_expression *const r0322 = nequal(r01EA, body.constant(0u));
            ir_expression *const r0323 = expr(ir_unop_b2i, r0322);
            ir_expression *const r0324 = expr(ir_unop_i2u, r0323);
            body.emit(assign(r031D, bit_or(r031D, r0324), 0x01));

            body.emit(assign(r01D2, r031F, 0x01));

            body.emit(assign(r01EA, r031D, 0x01));

            ir_variable *const r0325 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0325, r01E9, 0x01));

            ir_variable *const r0326 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0326, r031F, 0x01));

            ir_variable *const r0327 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0327, r031E, 0x01));

            ir_variable *const r0328 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0328, r031D, 0x01));

            ir_variable *const r0329 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0329, body.constant(true), 0x01));

            ir_variable *const r032A = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r032B = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r032B);
            ir_expression *const r032C = expr(ir_unop_u2i, r031D);
            body.emit(assign(r032B, less(r032C, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r032E = gequal(r01E9, body.constant(int(2045)));
            ir_if *f032D = new(mem_ctx) ir_if(operand(r032E).val);
            exec_list *const f032D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f032D->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0330 = less(body.constant(int(2045)), r01E9);
               ir_expression *const r0331 = equal(r01E9, body.constant(int(2045)));
               ir_expression *const r0332 = equal(body.constant(2097151u), r031F);
               ir_expression *const r0333 = equal(body.constant(4294967295u), r031E);
               ir_expression *const r0334 = logic_and(r0332, r0333);
               ir_expression *const r0335 = logic_and(r0331, r0334);
               ir_expression *const r0336 = logic_and(r0335, r032B);
               ir_expression *const r0337 = logic_or(r0330, r0336);
               ir_if *f032F = new(mem_ctx) ir_if(operand(r0337).val);
               exec_list *const f032F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f032F->then_instructions;

                  ir_variable *const r0338 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0338);
                  ir_expression *const r0339 = lshift(r01DA, body.constant(int(31)));
                  body.emit(assign(r0338, add(r0339, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0338, body.constant(0u), 0x01));

                  body.emit(assign(r032A, r0338, 0x03));

                  body.emit(assign(r0329, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f032F->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r033B = less(r01E9, body.constant(int(0)));
                  ir_if *f033A = new(mem_ctx) ir_if(operand(r033B).val);
                  exec_list *const f033A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f033A->then_instructions;

                     ir_variable *const r033C = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r033C, r031D, 0x01));

                     ir_variable *const r033D = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r033D, neg(r01E9), 0x01));

                     ir_variable *const r033E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r033E);
                     ir_variable *const r033F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r033F);
                     ir_variable *const r0340 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0340);
                     ir_variable *const r0341 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0342 = neg(r033D);
                     body.emit(assign(r0341, bit_and(r0342, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0344 = equal(r033D, body.constant(int(0)));
                     ir_if *f0343 = new(mem_ctx) ir_if(operand(r0344).val);
                     exec_list *const f0343_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0343->then_instructions;

                        body.emit(assign(r033E, r031D, 0x01));

                        body.emit(assign(r033F, r031E, 0x01));

                        body.emit(assign(r0340, r031F, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0343->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0346 = less(r033D, body.constant(int(32)));
                        ir_if *f0345 = new(mem_ctx) ir_if(operand(r0346).val);
                        exec_list *const f0345_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0345->then_instructions;

                           body.emit(assign(r033E, lshift(r031E, r0341), 0x01));

                           ir_expression *const r0347 = lshift(r031F, r0341);
                           ir_expression *const r0348 = rshift(r031E, r033D);
                           body.emit(assign(r033F, bit_or(r0347, r0348), 0x01));

                           body.emit(assign(r0340, rshift(r031F, r033D), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0345->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r034A = equal(r033D, body.constant(int(32)));
                           ir_if *f0349 = new(mem_ctx) ir_if(operand(r034A).val);
                           exec_list *const f0349_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0349->then_instructions;

                              body.emit(assign(r033E, r031E, 0x01));

                              body.emit(assign(r033F, r031F, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0349->else_instructions;

                              body.emit(assign(r033C, bit_or(r031D, r031E), 0x01));

                              ir_expression *const r034B = less(r033D, body.constant(int(64)));
                              ir_expression *const r034C = lshift(r031F, r0341);
                              ir_expression *const r034D = equal(r033D, body.constant(int(64)));
                              ir_expression *const r034E = nequal(r031F, body.constant(0u));
                              ir_expression *const r034F = expr(ir_unop_b2i, r034E);
                              ir_expression *const r0350 = expr(ir_unop_i2u, r034F);
                              ir_expression *const r0351 = expr(ir_triop_csel, r034D, r031F, r0350);
                              body.emit(assign(r033E, expr(ir_triop_csel, r034B, r034C, r0351), 0x01));

                              ir_expression *const r0352 = less(r033D, body.constant(int(64)));
                              ir_expression *const r0353 = bit_and(r033D, body.constant(int(31)));
                              ir_expression *const r0354 = rshift(r031F, r0353);
                              body.emit(assign(r033F, expr(ir_triop_csel, r0352, r0354, body.constant(0u)), 0x01));


                           body.instructions = f0349_parent_instructions;
                           body.emit(f0349);

                           /* END IF */

                           body.emit(assign(r0340, body.constant(0u), 0x01));


                        body.instructions = f0345_parent_instructions;
                        body.emit(f0345);

                        /* END IF */

                        ir_expression *const r0355 = nequal(r033C, body.constant(0u));
                        ir_expression *const r0356 = expr(ir_unop_b2i, r0355);
                        ir_expression *const r0357 = expr(ir_unop_i2u, r0356);
                        body.emit(assign(r033E, bit_or(r033E, r0357), 0x01));


                     body.instructions = f0343_parent_instructions;
                     body.emit(f0343);

                     /* END IF */

                     body.emit(assign(r0326, r0340, 0x01));

                     body.emit(assign(r0327, r033F, 0x01));

                     body.emit(assign(r0328, r033E, 0x01));

                     body.emit(assign(r0325, body.constant(int(0)), 0x01));

                     body.emit(assign(r032B, less(r033E, body.constant(0u)), 0x01));


                  body.instructions = f033A_parent_instructions;
                  body.emit(f033A);

                  /* END IF */


               body.instructions = f032F_parent_instructions;
               body.emit(f032F);

               /* END IF */


            body.instructions = f032D_parent_instructions;
            body.emit(f032D);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0358 = new(mem_ctx) ir_if(operand(r0329).val);
            exec_list *const f0358_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0358->then_instructions;

               /* IF CONDITION */
               ir_if *f0359 = new(mem_ctx) ir_if(operand(r032B).val);
               exec_list *const f0359_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0359->then_instructions;

                  ir_variable *const r035A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r035A, add(r0327, body.constant(1u)), 0x01));

                  ir_expression *const r035B = less(r035A, r0327);
                  ir_expression *const r035C = expr(ir_unop_b2i, r035B);
                  ir_expression *const r035D = expr(ir_unop_i2u, r035C);
                  body.emit(assign(r0326, add(r0326, r035D), 0x01));

                  ir_expression *const r035E = equal(r0328, body.constant(0u));
                  ir_expression *const r035F = expr(ir_unop_b2i, r035E);
                  ir_expression *const r0360 = expr(ir_unop_i2u, r035F);
                  ir_expression *const r0361 = add(r0328, r0360);
                  ir_expression *const r0362 = bit_and(r0361, body.constant(1u));
                  ir_expression *const r0363 = expr(ir_unop_bit_not, r0362);
                  body.emit(assign(r0327, bit_and(r035A, r0363), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0359->else_instructions;

                  ir_expression *const r0364 = bit_or(r0326, r0327);
                  ir_expression *const r0365 = equal(r0364, body.constant(0u));
                  body.emit(assign(r0325, expr(ir_triop_csel, r0365, body.constant(int(0)), r0325), 0x01));


               body.instructions = f0359_parent_instructions;
               body.emit(f0359);

               /* END IF */

               ir_variable *const r0366 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0366);
               ir_expression *const r0367 = lshift(r01DA, body.constant(int(31)));
               ir_expression *const r0368 = expr(ir_unop_i2u, r0325);
               ir_expression *const r0369 = lshift(r0368, body.constant(int(20)));
               ir_expression *const r036A = add(r0367, r0369);
               body.emit(assign(r0366, add(r036A, r0326), 0x02));

               body.emit(assign(r0366, r0327, 0x01));

               body.emit(assign(r032A, r0366, 0x03));

               body.emit(assign(r0329, body.constant(false), 0x01));


            body.instructions = f0358_parent_instructions;
            body.emit(f0358);

            /* END IF */

            body.emit(assign(r01D0, r032A, 0x03));

            body.emit(assign(r01CF, body.constant(false), 0x01));


         body.instructions = f02D5_parent_instructions;
         body.emit(f02D5);

         /* END IF */


      body.instructions = f02CE_parent_instructions;
      body.emit(f02CE);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01E7->else_instructions;

      ir_variable *const r036B = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r036B);
      ir_variable *const r036C = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r036D = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r036D, lshift(r01D8, body.constant(int(10))), 0x01));

      ir_expression *const r036E = lshift(r01D7, body.constant(int(10)));
      ir_expression *const r036F = rshift(r01D8, body.constant(int(22)));
      body.emit(assign(r036C, bit_or(r036E, r036F), 0x01));

      body.emit(assign(r01D7, r036C, 0x01));

      body.emit(assign(r01D8, r036D, 0x01));

      ir_variable *const r0370 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r0371 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0371, lshift(r01D6, body.constant(int(10))), 0x01));

      ir_expression *const r0372 = lshift(r01D5, body.constant(int(10)));
      ir_expression *const r0373 = rshift(r01D6, body.constant(int(22)));
      body.emit(assign(r0370, bit_or(r0372, r0373), 0x01));

      body.emit(assign(r01D5, r0370, 0x01));

      body.emit(assign(r01D6, r0371, 0x01));

      /* IF CONDITION */
      ir_expression *const r0375 = less(body.constant(int(0)), r01D1);
      ir_if *f0374 = new(mem_ctx) ir_if(operand(r0375).val);
      exec_list *const f0374_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0374->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0377 = equal(r01E0, body.constant(int(2047)));
         ir_if *f0376 = new(mem_ctx) ir_if(operand(r0377).val);
         exec_list *const f0376_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0376->then_instructions;

            ir_variable *const r0378 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0378, swizzle_x(r01CD), 0x01));

            ir_variable *const r0379 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0379, swizzle_x(r01CE), 0x01));

            body.emit(assign(r0378, bit_or(swizzle_y(r01CD), body.constant(524288u)), 0x02));

            body.emit(assign(r0379, bit_or(swizzle_y(r01CE), body.constant(524288u)), 0x02));

            ir_expression *const r037A = bit_or(r036C, r036D);
            ir_expression *const r037B = nequal(r037A, body.constant(0u));
            ir_swizzle *const r037C = swizzle(r037B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r037D = lshift(swizzle_y(r01CD), body.constant(int(1)));
            ir_expression *const r037E = gequal(r037D, body.constant(4292870144u));
            ir_expression *const r037F = nequal(swizzle_x(r01CD), body.constant(0u));
            ir_expression *const r0380 = bit_and(swizzle_y(r01CD), body.constant(1048575u));
            ir_expression *const r0381 = nequal(r0380, body.constant(0u));
            ir_expression *const r0382 = logic_or(r037F, r0381);
            ir_expression *const r0383 = logic_and(r037E, r0382);
            ir_swizzle *const r0384 = swizzle(r0383, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0385 = lshift(swizzle_y(r01CE), body.constant(int(1)));
            ir_expression *const r0386 = gequal(r0385, body.constant(4292870144u));
            ir_expression *const r0387 = nequal(swizzle_x(r01CE), body.constant(0u));
            ir_expression *const r0388 = bit_and(swizzle_y(r01CE), body.constant(1048575u));
            ir_expression *const r0389 = nequal(r0388, body.constant(0u));
            ir_expression *const r038A = logic_or(r0387, r0389);
            ir_expression *const r038B = logic_and(r0386, r038A);
            ir_swizzle *const r038C = swizzle(r038B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r038D = expr(ir_triop_csel, r038C, r0379, r0378);
            ir_expression *const r038E = expr(ir_triop_csel, r0384, r038D, r0379);
            body.emit(assign(r01D0, expr(ir_triop_csel, r037C, r038E, r01CD), 0x03));

            body.emit(assign(r01CF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0376->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0390 = equal(r01E3, body.constant(int(0)));
            ir_if *f038F = new(mem_ctx) ir_if(operand(r0390).val);
            exec_list *const f038F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f038F->then_instructions;

               body.emit(assign(r01D1, add(r01D1, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f038F->else_instructions;

               body.emit(assign(r01D5, bit_or(r0370, body.constant(1073741824u)), 0x01));


            body.instructions = f038F_parent_instructions;
            body.emit(f038F);

            /* END IF */

            ir_variable *const r0391 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r0392 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0392);
            ir_variable *const r0393 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0394 = neg(r01D1);
            body.emit(assign(r0393, bit_and(r0394, body.constant(int(31))), 0x01));

            ir_expression *const r0395 = bit_or(r01D5, r0371);
            ir_expression *const r0396 = nequal(r0395, body.constant(0u));
            ir_expression *const r0397 = expr(ir_unop_b2i, r0396);
            body.emit(assign(r0392, expr(ir_unop_i2u, r0397), 0x01));

            ir_variable *const r0398 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0399 = equal(r01D1, body.constant(int(0)));
            ir_expression *const r039A = less(r01D1, body.constant(int(32)));
            ir_expression *const r039B = lshift(r01D5, r0393);
            ir_expression *const r039C = rshift(r0371, r01D1);
            ir_expression *const r039D = bit_or(r039B, r039C);
            ir_expression *const r039E = lshift(r0371, r0393);
            ir_expression *const r039F = nequal(r039E, body.constant(0u));
            ir_expression *const r03A0 = expr(ir_unop_b2i, r039F);
            ir_expression *const r03A1 = expr(ir_unop_i2u, r03A0);
            ir_expression *const r03A2 = bit_or(r039D, r03A1);
            ir_expression *const r03A3 = equal(r01D1, body.constant(int(32)));
            ir_expression *const r03A4 = nequal(r0371, body.constant(0u));
            ir_expression *const r03A5 = expr(ir_unop_b2i, r03A4);
            ir_expression *const r03A6 = expr(ir_unop_i2u, r03A5);
            ir_expression *const r03A7 = bit_or(r01D5, r03A6);
            ir_expression *const r03A8 = less(r01D1, body.constant(int(64)));
            ir_expression *const r03A9 = bit_and(r01D1, body.constant(int(31)));
            ir_expression *const r03AA = rshift(r01D5, r03A9);
            ir_expression *const r03AB = lshift(r01D5, r0393);
            ir_expression *const r03AC = bit_or(r03AB, r0371);
            ir_expression *const r03AD = nequal(r03AC, body.constant(0u));
            ir_expression *const r03AE = expr(ir_unop_b2i, r03AD);
            ir_expression *const r03AF = expr(ir_unop_i2u, r03AE);
            ir_expression *const r03B0 = bit_or(r03AA, r03AF);
            ir_expression *const r03B1 = expr(ir_triop_csel, r03A8, r03B0, r0392);
            ir_expression *const r03B2 = expr(ir_triop_csel, r03A3, r03A7, r03B1);
            ir_expression *const r03B3 = expr(ir_triop_csel, r039A, r03A2, r03B2);
            body.emit(assign(r0398, expr(ir_triop_csel, r0399, r0371, r03B3), 0x01));

            body.emit(assign(r0392, r0398, 0x01));

            ir_expression *const r03B4 = less(r01D1, body.constant(int(32)));
            ir_expression *const r03B5 = rshift(r01D5, r01D1);
            ir_expression *const r03B6 = equal(r01D1, body.constant(int(0)));
            ir_expression *const r03B7 = expr(ir_triop_csel, r03B6, r01D5, body.constant(0u));
            body.emit(assign(r0391, expr(ir_triop_csel, r03B4, r03B5, r03B7), 0x01));

            body.emit(assign(r01D5, r0391, 0x01));

            body.emit(assign(r01D6, r0398, 0x01));

            body.emit(assign(r01D7, bit_or(r036C, body.constant(1073741824u)), 0x01));

            ir_variable *const r03B8 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_expression *const r03B9 = sub(r01D7, r0391);
            ir_expression *const r03BA = less(r036D, r0398);
            ir_expression *const r03BB = expr(ir_unop_b2i, r03BA);
            ir_expression *const r03BC = expr(ir_unop_i2u, r03BB);
            body.emit(assign(r03B8, sub(r03B9, r03BC), 0x01));

            body.emit(assign(r01D2, r03B8, 0x01));

            body.emit(assign(r036B, add(r01E0, body.constant(int(-1))), 0x01));

            ir_variable *const r03BD = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03BD, add(r036B, body.constant(int(-10))), 0x01));

            ir_variable *const r03BE = body.make_temp(glsl_type::uint_type, "zFrac0");
            ir_variable *const r03BF = body.make_temp(glsl_type::uint_type, "zFrac1");
            ir_variable *const r03C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03C0);
            ir_variable *const r03C1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03C1);
            ir_expression *const r03C2 = equal(r03B8, body.constant(0u));
            ir_expression *const r03C3 = add(r03BD, body.constant(int(-32)));
            body.emit(assign(r03BD, expr(ir_triop_csel, r03C2, r03C3, r03BD), 0x01));

            ir_variable *const r03C4 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03C5 = equal(r03B8, body.constant(0u));
            ir_expression *const r03C6 = sub(r036D, r0398);
            body.emit(assign(r03C4, expr(ir_triop_csel, r03C5, body.constant(0u), r03C6), 0x01));

            body.emit(assign(r03BF, r03C4, 0x01));

            ir_variable *const r03C7 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03C8 = equal(r03B8, body.constant(0u));
            body.emit(assign(r03C7, expr(ir_triop_csel, r03C8, r03C4, r03B8), 0x01));

            body.emit(assign(r03BE, r03C7, 0x01));

            ir_expression *const r03C9 = equal(r03C7, body.constant(0u));
            ir_expression *const r03CA = expr(ir_unop_find_msb, r03C7);
            ir_expression *const r03CB = sub(body.constant(int(31)), r03CA);
            ir_expression *const r03CC = expr(ir_triop_csel, r03C9, body.constant(int(32)), r03CB);
            body.emit(assign(r03C1, add(r03CC, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03CE = gequal(r03C1, body.constant(int(0)));
            ir_if *f03CD = new(mem_ctx) ir_if(operand(r03CE).val);
            exec_list *const f03CD_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03CD->then_instructions;

               body.emit(assign(r03C0, body.constant(0u), 0x01));

               ir_expression *const r03CF = equal(r03C1, body.constant(int(0)));
               ir_expression *const r03D0 = lshift(r03C7, r03C1);
               ir_expression *const r03D1 = neg(r03C1);
               ir_expression *const r03D2 = bit_and(r03D1, body.constant(int(31)));
               ir_expression *const r03D3 = rshift(r03C4, r03D2);
               ir_expression *const r03D4 = bit_or(r03D0, r03D3);
               body.emit(assign(r03BE, expr(ir_triop_csel, r03CF, r03C7, r03D4), 0x01));

               body.emit(assign(r03BF, lshift(r03C4, r03C1), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03CD->else_instructions;

               ir_variable *const r03D5 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r03D5, body.constant(0u), 0x01));

               ir_variable *const r03D6 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r03D6, neg(r03C1), 0x01));

               ir_variable *const r03D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r03D7);
               ir_variable *const r03D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r03D8);
               ir_variable *const r03D9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r03D9);
               ir_variable *const r03DA = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r03DB = neg(r03D6);
               body.emit(assign(r03DA, bit_and(r03DB, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r03DD = equal(r03D6, body.constant(int(0)));
               ir_if *f03DC = new(mem_ctx) ir_if(operand(r03DD).val);
               exec_list *const f03DC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03DC->then_instructions;

                  body.emit(assign(r03D7, r03D5, 0x01));

                  body.emit(assign(r03D8, r03BF, 0x01));

                  body.emit(assign(r03D9, r03BE, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03DC->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03DF = less(r03D6, body.constant(int(32)));
                  ir_if *f03DE = new(mem_ctx) ir_if(operand(r03DF).val);
                  exec_list *const f03DE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03DE->then_instructions;

                     body.emit(assign(r03D7, lshift(r03BF, r03DA), 0x01));

                     ir_expression *const r03E0 = lshift(r03BE, r03DA);
                     ir_expression *const r03E1 = rshift(r03BF, r03D6);
                     body.emit(assign(r03D8, bit_or(r03E0, r03E1), 0x01));

                     body.emit(assign(r03D9, rshift(r03BE, r03D6), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03DE->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03E3 = equal(r03D6, body.constant(int(32)));
                     ir_if *f03E2 = new(mem_ctx) ir_if(operand(r03E3).val);
                     exec_list *const f03E2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03E2->then_instructions;

                        body.emit(assign(r03D7, r03BF, 0x01));

                        body.emit(assign(r03D8, r03BE, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03E2->else_instructions;

                        body.emit(assign(r03D5, bit_or(body.constant(0u), r03BF), 0x01));

                        ir_expression *const r03E4 = less(r03D6, body.constant(int(64)));
                        ir_expression *const r03E5 = lshift(r03BE, r03DA);
                        ir_expression *const r03E6 = equal(r03D6, body.constant(int(64)));
                        ir_expression *const r03E7 = nequal(r03BE, body.constant(0u));
                        ir_expression *const r03E8 = expr(ir_unop_b2i, r03E7);
                        ir_expression *const r03E9 = expr(ir_unop_i2u, r03E8);
                        ir_expression *const r03EA = expr(ir_triop_csel, r03E6, r03BE, r03E9);
                        body.emit(assign(r03D7, expr(ir_triop_csel, r03E4, r03E5, r03EA), 0x01));

                        ir_expression *const r03EB = less(r03D6, body.constant(int(64)));
                        ir_expression *const r03EC = bit_and(r03D6, body.constant(int(31)));
                        ir_expression *const r03ED = rshift(r03BE, r03EC);
                        body.emit(assign(r03D8, expr(ir_triop_csel, r03EB, r03ED, body.constant(0u)), 0x01));


                     body.instructions = f03E2_parent_instructions;
                     body.emit(f03E2);

                     /* END IF */

                     body.emit(assign(r03D9, body.constant(0u), 0x01));


                  body.instructions = f03DE_parent_instructions;
                  body.emit(f03DE);

                  /* END IF */

                  ir_expression *const r03EE = nequal(r03D5, body.constant(0u));
                  ir_expression *const r03EF = expr(ir_unop_b2i, r03EE);
                  ir_expression *const r03F0 = expr(ir_unop_i2u, r03EF);
                  body.emit(assign(r03D7, bit_or(r03D7, r03F0), 0x01));


               body.instructions = f03DC_parent_instructions;
               body.emit(f03DC);

               /* END IF */

               body.emit(assign(r03BE, r03D9, 0x01));

               body.emit(assign(r03BF, r03D8, 0x01));

               body.emit(assign(r03C0, r03D7, 0x01));


            body.instructions = f03CD_parent_instructions;
            body.emit(f03CD);

            /* END IF */

            body.emit(assign(r03BD, sub(r03BD, r03C1), 0x01));

            ir_variable *const r03F1 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03F1, r03BD, 0x01));

            ir_variable *const r03F2 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03F2, r03BE, 0x01));

            ir_variable *const r03F3 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03F3, r03BF, 0x01));

            ir_variable *const r03F4 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r03F4, r03C0, 0x01));

            ir_variable *const r03F5 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r03F5, body.constant(true), 0x01));

            ir_variable *const r03F6 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r03F7 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r03F7);
            ir_expression *const r03F8 = expr(ir_unop_u2i, r03C0);
            body.emit(assign(r03F7, less(r03F8, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03FA = gequal(r03BD, body.constant(int(2045)));
            ir_if *f03F9 = new(mem_ctx) ir_if(operand(r03FA).val);
            exec_list *const f03F9_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03F9->then_instructions;

               /* IF CONDITION */
               ir_expression *const r03FC = less(body.constant(int(2045)), r03BD);
               ir_expression *const r03FD = equal(r03BD, body.constant(int(2045)));
               ir_expression *const r03FE = equal(body.constant(2097151u), r03BE);
               ir_expression *const r03FF = equal(body.constant(4294967295u), r03BF);
               ir_expression *const r0400 = logic_and(r03FE, r03FF);
               ir_expression *const r0401 = logic_and(r03FD, r0400);
               ir_expression *const r0402 = logic_and(r0401, r03F7);
               ir_expression *const r0403 = logic_or(r03FC, r0402);
               ir_if *f03FB = new(mem_ctx) ir_if(operand(r0403).val);
               exec_list *const f03FB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03FB->then_instructions;

                  ir_variable *const r0404 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0404);
                  ir_expression *const r0405 = lshift(r01DA, body.constant(int(31)));
                  body.emit(assign(r0404, add(r0405, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0404, body.constant(0u), 0x01));

                  body.emit(assign(r03F6, r0404, 0x03));

                  body.emit(assign(r03F5, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03FB->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0407 = less(r03BD, body.constant(int(0)));
                  ir_if *f0406 = new(mem_ctx) ir_if(operand(r0407).val);
                  exec_list *const f0406_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0406->then_instructions;

                     ir_variable *const r0408 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0408, r03C0, 0x01));

                     ir_variable *const r0409 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0409, neg(r03BD), 0x01));

                     ir_variable *const r040A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r040A);
                     ir_variable *const r040B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r040B);
                     ir_variable *const r040C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r040C);
                     ir_variable *const r040D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r040E = neg(r0409);
                     body.emit(assign(r040D, bit_and(r040E, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0410 = equal(r0409, body.constant(int(0)));
                     ir_if *f040F = new(mem_ctx) ir_if(operand(r0410).val);
                     exec_list *const f040F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f040F->then_instructions;

                        body.emit(assign(r040A, r03C0, 0x01));

                        body.emit(assign(r040B, r03BF, 0x01));

                        body.emit(assign(r040C, r03BE, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f040F->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0412 = less(r0409, body.constant(int(32)));
                        ir_if *f0411 = new(mem_ctx) ir_if(operand(r0412).val);
                        exec_list *const f0411_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0411->then_instructions;

                           body.emit(assign(r040A, lshift(r03BF, r040D), 0x01));

                           ir_expression *const r0413 = lshift(r03BE, r040D);
                           ir_expression *const r0414 = rshift(r03BF, r0409);
                           body.emit(assign(r040B, bit_or(r0413, r0414), 0x01));

                           body.emit(assign(r040C, rshift(r03BE, r0409), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0411->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0416 = equal(r0409, body.constant(int(32)));
                           ir_if *f0415 = new(mem_ctx) ir_if(operand(r0416).val);
                           exec_list *const f0415_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0415->then_instructions;

                              body.emit(assign(r040A, r03BF, 0x01));

                              body.emit(assign(r040B, r03BE, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0415->else_instructions;

                              body.emit(assign(r0408, bit_or(r03C0, r03BF), 0x01));

                              ir_expression *const r0417 = less(r0409, body.constant(int(64)));
                              ir_expression *const r0418 = lshift(r03BE, r040D);
                              ir_expression *const r0419 = equal(r0409, body.constant(int(64)));
                              ir_expression *const r041A = nequal(r03BE, body.constant(0u));
                              ir_expression *const r041B = expr(ir_unop_b2i, r041A);
                              ir_expression *const r041C = expr(ir_unop_i2u, r041B);
                              ir_expression *const r041D = expr(ir_triop_csel, r0419, r03BE, r041C);
                              body.emit(assign(r040A, expr(ir_triop_csel, r0417, r0418, r041D), 0x01));

                              ir_expression *const r041E = less(r0409, body.constant(int(64)));
                              ir_expression *const r041F = bit_and(r0409, body.constant(int(31)));
                              ir_expression *const r0420 = rshift(r03BE, r041F);
                              body.emit(assign(r040B, expr(ir_triop_csel, r041E, r0420, body.constant(0u)), 0x01));


                           body.instructions = f0415_parent_instructions;
                           body.emit(f0415);

                           /* END IF */

                           body.emit(assign(r040C, body.constant(0u), 0x01));


                        body.instructions = f0411_parent_instructions;
                        body.emit(f0411);

                        /* END IF */

                        ir_expression *const r0421 = nequal(r0408, body.constant(0u));
                        ir_expression *const r0422 = expr(ir_unop_b2i, r0421);
                        ir_expression *const r0423 = expr(ir_unop_i2u, r0422);
                        body.emit(assign(r040A, bit_or(r040A, r0423), 0x01));


                     body.instructions = f040F_parent_instructions;
                     body.emit(f040F);

                     /* END IF */

                     body.emit(assign(r03F2, r040C, 0x01));

                     body.emit(assign(r03F3, r040B, 0x01));

                     body.emit(assign(r03F4, r040A, 0x01));

                     body.emit(assign(r03F1, body.constant(int(0)), 0x01));

                     body.emit(assign(r03F7, less(r040A, body.constant(0u)), 0x01));


                  body.instructions = f0406_parent_instructions;
                  body.emit(f0406);

                  /* END IF */


               body.instructions = f03FB_parent_instructions;
               body.emit(f03FB);

               /* END IF */


            body.instructions = f03F9_parent_instructions;
            body.emit(f03F9);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0424 = new(mem_ctx) ir_if(operand(r03F5).val);
            exec_list *const f0424_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0424->then_instructions;

               /* IF CONDITION */
               ir_if *f0425 = new(mem_ctx) ir_if(operand(r03F7).val);
               exec_list *const f0425_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0425->then_instructions;

                  ir_variable *const r0426 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0426, add(r03F3, body.constant(1u)), 0x01));

                  ir_expression *const r0427 = less(r0426, r03F3);
                  ir_expression *const r0428 = expr(ir_unop_b2i, r0427);
                  ir_expression *const r0429 = expr(ir_unop_i2u, r0428);
                  body.emit(assign(r03F2, add(r03F2, r0429), 0x01));

                  ir_expression *const r042A = equal(r03F4, body.constant(0u));
                  ir_expression *const r042B = expr(ir_unop_b2i, r042A);
                  ir_expression *const r042C = expr(ir_unop_i2u, r042B);
                  ir_expression *const r042D = add(r03F4, r042C);
                  ir_expression *const r042E = bit_and(r042D, body.constant(1u));
                  ir_expression *const r042F = expr(ir_unop_bit_not, r042E);
                  body.emit(assign(r03F3, bit_and(r0426, r042F), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0425->else_instructions;

                  ir_expression *const r0430 = bit_or(r03F2, r03F3);
                  ir_expression *const r0431 = equal(r0430, body.constant(0u));
                  body.emit(assign(r03F1, expr(ir_triop_csel, r0431, body.constant(int(0)), r03F1), 0x01));


               body.instructions = f0425_parent_instructions;
               body.emit(f0425);

               /* END IF */

               ir_variable *const r0432 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0432);
               ir_expression *const r0433 = lshift(r01DA, body.constant(int(31)));
               ir_expression *const r0434 = expr(ir_unop_i2u, r03F1);
               ir_expression *const r0435 = lshift(r0434, body.constant(int(20)));
               ir_expression *const r0436 = add(r0433, r0435);
               body.emit(assign(r0432, add(r0436, r03F2), 0x02));

               body.emit(assign(r0432, r03F3, 0x01));

               body.emit(assign(r03F6, r0432, 0x03));

               body.emit(assign(r03F5, body.constant(false), 0x01));


            body.instructions = f0424_parent_instructions;
            body.emit(f0424);

            /* END IF */

            body.emit(assign(r01D0, r03F6, 0x03));

            body.emit(assign(r01CF, body.constant(false), 0x01));


         body.instructions = f0376_parent_instructions;
         body.emit(f0376);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0374->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0438 = less(r01D1, body.constant(int(0)));
         ir_if *f0437 = new(mem_ctx) ir_if(operand(r0438).val);
         exec_list *const f0437_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0437->then_instructions;

            /* IF CONDITION */
            ir_expression *const r043A = equal(r01E3, body.constant(int(2047)));
            ir_if *f0439 = new(mem_ctx) ir_if(operand(r043A).val);
            exec_list *const f0439_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0439->then_instructions;

               ir_variable *const r043B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r043B);
               ir_expression *const r043C = bit_xor(r01DA, body.constant(1u));
               ir_expression *const r043D = lshift(r043C, body.constant(int(31)));
               body.emit(assign(r043B, add(r043D, body.constant(2146435072u)), 0x02));

               body.emit(assign(r043B, body.constant(0u), 0x01));

               ir_variable *const r043E = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r043E, swizzle_x(r01CD), 0x01));

               ir_variable *const r043F = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r043F, swizzle_x(r01CE), 0x01));

               body.emit(assign(r043E, bit_or(swizzle_y(r01CD), body.constant(524288u)), 0x02));

               body.emit(assign(r043F, bit_or(swizzle_y(r01CE), body.constant(524288u)), 0x02));

               ir_expression *const r0440 = bit_or(r01D5, r01D6);
               ir_expression *const r0441 = nequal(r0440, body.constant(0u));
               ir_swizzle *const r0442 = swizzle(r0441, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0443 = lshift(swizzle_y(r01CD), body.constant(int(1)));
               ir_expression *const r0444 = gequal(r0443, body.constant(4292870144u));
               ir_expression *const r0445 = nequal(swizzle_x(r01CD), body.constant(0u));
               ir_expression *const r0446 = bit_and(swizzle_y(r01CD), body.constant(1048575u));
               ir_expression *const r0447 = nequal(r0446, body.constant(0u));
               ir_expression *const r0448 = logic_or(r0445, r0447);
               ir_expression *const r0449 = logic_and(r0444, r0448);
               ir_swizzle *const r044A = swizzle(r0449, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r044B = lshift(swizzle_y(r01CE), body.constant(int(1)));
               ir_expression *const r044C = gequal(r044B, body.constant(4292870144u));
               ir_expression *const r044D = nequal(swizzle_x(r01CE), body.constant(0u));
               ir_expression *const r044E = bit_and(swizzle_y(r01CE), body.constant(1048575u));
               ir_expression *const r044F = nequal(r044E, body.constant(0u));
               ir_expression *const r0450 = logic_or(r044D, r044F);
               ir_expression *const r0451 = logic_and(r044C, r0450);
               ir_swizzle *const r0452 = swizzle(r0451, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0453 = expr(ir_triop_csel, r0452, r043F, r043E);
               ir_expression *const r0454 = expr(ir_triop_csel, r044A, r0453, r043F);
               body.emit(assign(r01D0, expr(ir_triop_csel, r0442, r0454, r043B), 0x03));

               body.emit(assign(r01CF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0439->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0456 = equal(r01E0, body.constant(int(0)));
               ir_if *f0455 = new(mem_ctx) ir_if(operand(r0456).val);
               exec_list *const f0455_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0455->then_instructions;

                  body.emit(assign(r01D1, add(r01D1, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0455->else_instructions;

                  body.emit(assign(r01D7, bit_or(r01D7, body.constant(1073741824u)), 0x01));


               body.instructions = f0455_parent_instructions;
               body.emit(f0455);

               /* END IF */

               ir_variable *const r0457 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0457, neg(r01D1), 0x01));

               ir_variable *const r0458 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0459 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0459);
               ir_variable *const r045A = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r045B = neg(r0457);
               body.emit(assign(r045A, bit_and(r045B, body.constant(int(31))), 0x01));

               ir_expression *const r045C = bit_or(r01D7, r036D);
               ir_expression *const r045D = nequal(r045C, body.constant(0u));
               ir_expression *const r045E = expr(ir_unop_b2i, r045D);
               body.emit(assign(r0459, expr(ir_unop_i2u, r045E), 0x01));

               ir_variable *const r045F = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0460 = equal(r0457, body.constant(int(0)));
               ir_expression *const r0461 = less(r0457, body.constant(int(32)));
               ir_expression *const r0462 = lshift(r01D7, r045A);
               ir_expression *const r0463 = rshift(r036D, r0457);
               ir_expression *const r0464 = bit_or(r0462, r0463);
               ir_expression *const r0465 = lshift(r036D, r045A);
               ir_expression *const r0466 = nequal(r0465, body.constant(0u));
               ir_expression *const r0467 = expr(ir_unop_b2i, r0466);
               ir_expression *const r0468 = expr(ir_unop_i2u, r0467);
               ir_expression *const r0469 = bit_or(r0464, r0468);
               ir_expression *const r046A = equal(r0457, body.constant(int(32)));
               ir_expression *const r046B = nequal(r036D, body.constant(0u));
               ir_expression *const r046C = expr(ir_unop_b2i, r046B);
               ir_expression *const r046D = expr(ir_unop_i2u, r046C);
               ir_expression *const r046E = bit_or(r01D7, r046D);
               ir_expression *const r046F = less(r0457, body.constant(int(64)));
               ir_expression *const r0470 = bit_and(r0457, body.constant(int(31)));
               ir_expression *const r0471 = rshift(r01D7, r0470);
               ir_expression *const r0472 = lshift(r01D7, r045A);
               ir_expression *const r0473 = bit_or(r0472, r036D);
               ir_expression *const r0474 = nequal(r0473, body.constant(0u));
               ir_expression *const r0475 = expr(ir_unop_b2i, r0474);
               ir_expression *const r0476 = expr(ir_unop_i2u, r0475);
               ir_expression *const r0477 = bit_or(r0471, r0476);
               ir_expression *const r0478 = expr(ir_triop_csel, r046F, r0477, r0459);
               ir_expression *const r0479 = expr(ir_triop_csel, r046A, r046E, r0478);
               ir_expression *const r047A = expr(ir_triop_csel, r0461, r0469, r0479);
               body.emit(assign(r045F, expr(ir_triop_csel, r0460, r036D, r047A), 0x01));

               body.emit(assign(r0459, r045F, 0x01));

               ir_expression *const r047B = less(r0457, body.constant(int(32)));
               ir_expression *const r047C = rshift(r01D7, r0457);
               ir_expression *const r047D = equal(r0457, body.constant(int(0)));
               ir_expression *const r047E = expr(ir_triop_csel, r047D, r01D7, body.constant(0u));
               body.emit(assign(r0458, expr(ir_triop_csel, r047B, r047C, r047E), 0x01));

               body.emit(assign(r01D7, r0458, 0x01));

               body.emit(assign(r01D8, r045F, 0x01));

               body.emit(assign(r01D5, bit_or(r01D5, body.constant(1073741824u)), 0x01));

               ir_variable *const r047F = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_expression *const r0480 = sub(r01D5, r0458);
               ir_expression *const r0481 = less(r01D6, r045F);
               ir_expression *const r0482 = expr(ir_unop_b2i, r0481);
               ir_expression *const r0483 = expr(ir_unop_i2u, r0482);
               body.emit(assign(r047F, sub(r0480, r0483), 0x01));

               body.emit(assign(r01D2, r047F, 0x01));

               body.emit(assign(r01D9, bit_xor(r01DA, body.constant(1u)), 0x01));

               body.emit(assign(r036B, add(r01E3, body.constant(int(-1))), 0x01));

               ir_variable *const r0484 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0484, add(r036B, body.constant(int(-10))), 0x01));

               ir_variable *const r0485 = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r0486 = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r0487 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r0487);
               ir_variable *const r0488 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0488);
               ir_expression *const r0489 = equal(r047F, body.constant(0u));
               ir_expression *const r048A = add(r0484, body.constant(int(-32)));
               body.emit(assign(r0484, expr(ir_triop_csel, r0489, r048A, r0484), 0x01));

               ir_variable *const r048B = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r048C = equal(r047F, body.constant(0u));
               ir_expression *const r048D = sub(r01D6, r045F);
               body.emit(assign(r048B, expr(ir_triop_csel, r048C, body.constant(0u), r048D), 0x01));

               body.emit(assign(r0486, r048B, 0x01));

               ir_variable *const r048E = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r048F = equal(r047F, body.constant(0u));
               body.emit(assign(r048E, expr(ir_triop_csel, r048F, r048B, r047F), 0x01));

               body.emit(assign(r0485, r048E, 0x01));

               ir_expression *const r0490 = equal(r048E, body.constant(0u));
               ir_expression *const r0491 = expr(ir_unop_find_msb, r048E);
               ir_expression *const r0492 = sub(body.constant(int(31)), r0491);
               ir_expression *const r0493 = expr(ir_triop_csel, r0490, body.constant(int(32)), r0492);
               body.emit(assign(r0488, add(r0493, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0495 = gequal(r0488, body.constant(int(0)));
               ir_if *f0494 = new(mem_ctx) ir_if(operand(r0495).val);
               exec_list *const f0494_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0494->then_instructions;

                  body.emit(assign(r0487, body.constant(0u), 0x01));

                  ir_expression *const r0496 = equal(r0488, body.constant(int(0)));
                  ir_expression *const r0497 = lshift(r048E, r0488);
                  ir_expression *const r0498 = neg(r0488);
                  ir_expression *const r0499 = bit_and(r0498, body.constant(int(31)));
                  ir_expression *const r049A = rshift(r048B, r0499);
                  ir_expression *const r049B = bit_or(r0497, r049A);
                  body.emit(assign(r0485, expr(ir_triop_csel, r0496, r048E, r049B), 0x01));

                  body.emit(assign(r0486, lshift(r048B, r0488), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0494->else_instructions;

                  ir_variable *const r049C = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r049C, body.constant(0u), 0x01));

                  ir_variable *const r049D = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r049D, neg(r0488), 0x01));

                  ir_variable *const r049E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r049E);
                  ir_variable *const r049F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r049F);
                  ir_variable *const r04A0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04A0);
                  ir_variable *const r04A1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04A2 = neg(r049D);
                  body.emit(assign(r04A1, bit_and(r04A2, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04A4 = equal(r049D, body.constant(int(0)));
                  ir_if *f04A3 = new(mem_ctx) ir_if(operand(r04A4).val);
                  exec_list *const f04A3_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A3->then_instructions;

                     body.emit(assign(r049E, r049C, 0x01));

                     body.emit(assign(r049F, r0486, 0x01));

                     body.emit(assign(r04A0, r0485, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04A3->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04A6 = less(r049D, body.constant(int(32)));
                     ir_if *f04A5 = new(mem_ctx) ir_if(operand(r04A6).val);
                     exec_list *const f04A5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04A5->then_instructions;

                        body.emit(assign(r049E, lshift(r0486, r04A1), 0x01));

                        ir_expression *const r04A7 = lshift(r0485, r04A1);
                        ir_expression *const r04A8 = rshift(r0486, r049D);
                        body.emit(assign(r049F, bit_or(r04A7, r04A8), 0x01));

                        body.emit(assign(r04A0, rshift(r0485, r049D), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04A5->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04AA = equal(r049D, body.constant(int(32)));
                        ir_if *f04A9 = new(mem_ctx) ir_if(operand(r04AA).val);
                        exec_list *const f04A9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04A9->then_instructions;

                           body.emit(assign(r049E, r0486, 0x01));

                           body.emit(assign(r049F, r0485, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04A9->else_instructions;

                           body.emit(assign(r049C, bit_or(body.constant(0u), r0486), 0x01));

                           ir_expression *const r04AB = less(r049D, body.constant(int(64)));
                           ir_expression *const r04AC = lshift(r0485, r04A1);
                           ir_expression *const r04AD = equal(r049D, body.constant(int(64)));
                           ir_expression *const r04AE = nequal(r0485, body.constant(0u));
                           ir_expression *const r04AF = expr(ir_unop_b2i, r04AE);
                           ir_expression *const r04B0 = expr(ir_unop_i2u, r04AF);
                           ir_expression *const r04B1 = expr(ir_triop_csel, r04AD, r0485, r04B0);
                           body.emit(assign(r049E, expr(ir_triop_csel, r04AB, r04AC, r04B1), 0x01));

                           ir_expression *const r04B2 = less(r049D, body.constant(int(64)));
                           ir_expression *const r04B3 = bit_and(r049D, body.constant(int(31)));
                           ir_expression *const r04B4 = rshift(r0485, r04B3);
                           body.emit(assign(r049F, expr(ir_triop_csel, r04B2, r04B4, body.constant(0u)), 0x01));


                        body.instructions = f04A9_parent_instructions;
                        body.emit(f04A9);

                        /* END IF */

                        body.emit(assign(r04A0, body.constant(0u), 0x01));


                     body.instructions = f04A5_parent_instructions;
                     body.emit(f04A5);

                     /* END IF */

                     ir_expression *const r04B5 = nequal(r049C, body.constant(0u));
                     ir_expression *const r04B6 = expr(ir_unop_b2i, r04B5);
                     ir_expression *const r04B7 = expr(ir_unop_i2u, r04B6);
                     body.emit(assign(r049E, bit_or(r049E, r04B7), 0x01));


                  body.instructions = f04A3_parent_instructions;
                  body.emit(f04A3);

                  /* END IF */

                  body.emit(assign(r0485, r04A0, 0x01));

                  body.emit(assign(r0486, r049F, 0x01));

                  body.emit(assign(r0487, r049E, 0x01));


               body.instructions = f0494_parent_instructions;
               body.emit(f0494);

               /* END IF */

               body.emit(assign(r0484, sub(r0484, r0488), 0x01));

               ir_variable *const r04B8 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04B8, r0484, 0x01));

               ir_variable *const r04B9 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04B9, r0485, 0x01));

               ir_variable *const r04BA = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04BA, r0486, 0x01));

               ir_variable *const r04BB = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r04BB, r0487, 0x01));

               ir_variable *const r04BC = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r04BC, body.constant(true), 0x01));

               ir_variable *const r04BD = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04BE = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r04BE);
               ir_expression *const r04BF = expr(ir_unop_u2i, r0487);
               body.emit(assign(r04BE, less(r04BF, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04C1 = gequal(r0484, body.constant(int(2045)));
               ir_if *f04C0 = new(mem_ctx) ir_if(operand(r04C1).val);
               exec_list *const f04C0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04C0->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04C3 = less(body.constant(int(2045)), r0484);
                  ir_expression *const r04C4 = equal(r0484, body.constant(int(2045)));
                  ir_expression *const r04C5 = equal(body.constant(2097151u), r0485);
                  ir_expression *const r04C6 = equal(body.constant(4294967295u), r0486);
                  ir_expression *const r04C7 = logic_and(r04C5, r04C6);
                  ir_expression *const r04C8 = logic_and(r04C4, r04C7);
                  ir_expression *const r04C9 = logic_and(r04C8, r04BE);
                  ir_expression *const r04CA = logic_or(r04C3, r04C9);
                  ir_if *f04C2 = new(mem_ctx) ir_if(operand(r04CA).val);
                  exec_list *const f04C2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C2->then_instructions;

                     ir_variable *const r04CB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r04CB);
                     ir_expression *const r04CC = lshift(r01D9, body.constant(int(31)));
                     body.emit(assign(r04CB, add(r04CC, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r04CB, body.constant(0u), 0x01));

                     body.emit(assign(r04BD, r04CB, 0x03));

                     body.emit(assign(r04BC, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04C2->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04CE = less(r0484, body.constant(int(0)));
                     ir_if *f04CD = new(mem_ctx) ir_if(operand(r04CE).val);
                     exec_list *const f04CD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04CD->then_instructions;

                        ir_variable *const r04CF = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r04CF, r0487, 0x01));

                        ir_variable *const r04D0 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r04D0, neg(r0484), 0x01));

                        ir_variable *const r04D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r04D1);
                        ir_variable *const r04D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r04D2);
                        ir_variable *const r04D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r04D3);
                        ir_variable *const r04D4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r04D5 = neg(r04D0);
                        body.emit(assign(r04D4, bit_and(r04D5, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r04D7 = equal(r04D0, body.constant(int(0)));
                        ir_if *f04D6 = new(mem_ctx) ir_if(operand(r04D7).val);
                        exec_list *const f04D6_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04D6->then_instructions;

                           body.emit(assign(r04D1, r0487, 0x01));

                           body.emit(assign(r04D2, r0486, 0x01));

                           body.emit(assign(r04D3, r0485, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04D6->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r04D9 = less(r04D0, body.constant(int(32)));
                           ir_if *f04D8 = new(mem_ctx) ir_if(operand(r04D9).val);
                           exec_list *const f04D8_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04D8->then_instructions;

                              body.emit(assign(r04D1, lshift(r0486, r04D4), 0x01));

                              ir_expression *const r04DA = lshift(r0485, r04D4);
                              ir_expression *const r04DB = rshift(r0486, r04D0);
                              body.emit(assign(r04D2, bit_or(r04DA, r04DB), 0x01));

                              body.emit(assign(r04D3, rshift(r0485, r04D0), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04D8->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r04DD = equal(r04D0, body.constant(int(32)));
                              ir_if *f04DC = new(mem_ctx) ir_if(operand(r04DD).val);
                              exec_list *const f04DC_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04DC->then_instructions;

                                 body.emit(assign(r04D1, r0486, 0x01));

                                 body.emit(assign(r04D2, r0485, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04DC->else_instructions;

                                 body.emit(assign(r04CF, bit_or(r0487, r0486), 0x01));

                                 ir_expression *const r04DE = less(r04D0, body.constant(int(64)));
                                 ir_expression *const r04DF = lshift(r0485, r04D4);
                                 ir_expression *const r04E0 = equal(r04D0, body.constant(int(64)));
                                 ir_expression *const r04E1 = nequal(r0485, body.constant(0u));
                                 ir_expression *const r04E2 = expr(ir_unop_b2i, r04E1);
                                 ir_expression *const r04E3 = expr(ir_unop_i2u, r04E2);
                                 ir_expression *const r04E4 = expr(ir_triop_csel, r04E0, r0485, r04E3);
                                 body.emit(assign(r04D1, expr(ir_triop_csel, r04DE, r04DF, r04E4), 0x01));

                                 ir_expression *const r04E5 = less(r04D0, body.constant(int(64)));
                                 ir_expression *const r04E6 = bit_and(r04D0, body.constant(int(31)));
                                 ir_expression *const r04E7 = rshift(r0485, r04E6);
                                 body.emit(assign(r04D2, expr(ir_triop_csel, r04E5, r04E7, body.constant(0u)), 0x01));


                              body.instructions = f04DC_parent_instructions;
                              body.emit(f04DC);

                              /* END IF */

                              body.emit(assign(r04D3, body.constant(0u), 0x01));


                           body.instructions = f04D8_parent_instructions;
                           body.emit(f04D8);

                           /* END IF */

                           ir_expression *const r04E8 = nequal(r04CF, body.constant(0u));
                           ir_expression *const r04E9 = expr(ir_unop_b2i, r04E8);
                           ir_expression *const r04EA = expr(ir_unop_i2u, r04E9);
                           body.emit(assign(r04D1, bit_or(r04D1, r04EA), 0x01));


                        body.instructions = f04D6_parent_instructions;
                        body.emit(f04D6);

                        /* END IF */

                        body.emit(assign(r04B9, r04D3, 0x01));

                        body.emit(assign(r04BA, r04D2, 0x01));

                        body.emit(assign(r04BB, r04D1, 0x01));

                        body.emit(assign(r04B8, body.constant(int(0)), 0x01));

                        body.emit(assign(r04BE, less(r04D1, body.constant(0u)), 0x01));


                     body.instructions = f04CD_parent_instructions;
                     body.emit(f04CD);

                     /* END IF */


                  body.instructions = f04C2_parent_instructions;
                  body.emit(f04C2);

                  /* END IF */


               body.instructions = f04C0_parent_instructions;
               body.emit(f04C0);

               /* END IF */

               /* IF CONDITION */
               ir_if *f04EB = new(mem_ctx) ir_if(operand(r04BC).val);
               exec_list *const f04EB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04EB->then_instructions;

                  /* IF CONDITION */
                  ir_if *f04EC = new(mem_ctx) ir_if(operand(r04BE).val);
                  exec_list *const f04EC_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04EC->then_instructions;

                     ir_variable *const r04ED = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r04ED, add(r04BA, body.constant(1u)), 0x01));

                     ir_expression *const r04EE = less(r04ED, r04BA);
                     ir_expression *const r04EF = expr(ir_unop_b2i, r04EE);
                     ir_expression *const r04F0 = expr(ir_unop_i2u, r04EF);
                     body.emit(assign(r04B9, add(r04B9, r04F0), 0x01));

                     ir_expression *const r04F1 = equal(r04BB, body.constant(0u));
                     ir_expression *const r04F2 = expr(ir_unop_b2i, r04F1);
                     ir_expression *const r04F3 = expr(ir_unop_i2u, r04F2);
                     ir_expression *const r04F4 = add(r04BB, r04F3);
                     ir_expression *const r04F5 = bit_and(r04F4, body.constant(1u));
                     ir_expression *const r04F6 = expr(ir_unop_bit_not, r04F5);
                     body.emit(assign(r04BA, bit_and(r04ED, r04F6), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04EC->else_instructions;

                     ir_expression *const r04F7 = bit_or(r04B9, r04BA);
                     ir_expression *const r04F8 = equal(r04F7, body.constant(0u));
                     body.emit(assign(r04B8, expr(ir_triop_csel, r04F8, body.constant(int(0)), r04B8), 0x01));


                  body.instructions = f04EC_parent_instructions;
                  body.emit(f04EC);

                  /* END IF */

                  ir_variable *const r04F9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r04F9);
                  ir_expression *const r04FA = lshift(r01D9, body.constant(int(31)));
                  ir_expression *const r04FB = expr(ir_unop_i2u, r04B8);
                  ir_expression *const r04FC = lshift(r04FB, body.constant(int(20)));
                  ir_expression *const r04FD = add(r04FA, r04FC);
                  body.emit(assign(r04F9, add(r04FD, r04B9), 0x02));

                  body.emit(assign(r04F9, r04BA, 0x01));

                  body.emit(assign(r04BD, r04F9, 0x03));

                  body.emit(assign(r04BC, body.constant(false), 0x01));


               body.instructions = f04EB_parent_instructions;
               body.emit(f04EB);

               /* END IF */

               body.emit(assign(r01D0, r04BD, 0x03));

               body.emit(assign(r01CF, body.constant(false), 0x01));


            body.instructions = f0439_parent_instructions;
            body.emit(f0439);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0437->else_instructions;

            /* IF CONDITION */
            ir_expression *const r04FF = equal(r01E0, body.constant(int(2047)));
            ir_if *f04FE = new(mem_ctx) ir_if(operand(r04FF).val);
            exec_list *const f04FE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f04FE->then_instructions;

               ir_variable *const r0500 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0500, swizzle_x(r01CD), 0x01));

               ir_variable *const r0501 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0501, swizzle_x(r01CE), 0x01));

               body.emit(assign(r0500, bit_or(swizzle_y(r01CD), body.constant(524288u)), 0x02));

               body.emit(assign(r0501, bit_or(swizzle_y(r01CE), body.constant(524288u)), 0x02));

               ir_expression *const r0502 = bit_or(r01D7, r01D8);
               ir_expression *const r0503 = bit_or(r01D5, r01D6);
               ir_expression *const r0504 = bit_or(r0502, r0503);
               ir_expression *const r0505 = nequal(r0504, body.constant(0u));
               ir_swizzle *const r0506 = swizzle(r0505, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0507 = lshift(swizzle_y(r01CD), body.constant(int(1)));
               ir_expression *const r0508 = gequal(r0507, body.constant(4292870144u));
               ir_expression *const r0509 = nequal(swizzle_x(r01CD), body.constant(0u));
               ir_expression *const r050A = bit_and(swizzle_y(r01CD), body.constant(1048575u));
               ir_expression *const r050B = nequal(r050A, body.constant(0u));
               ir_expression *const r050C = logic_or(r0509, r050B);
               ir_expression *const r050D = logic_and(r0508, r050C);
               ir_swizzle *const r050E = swizzle(r050D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r050F = lshift(swizzle_y(r01CE), body.constant(int(1)));
               ir_expression *const r0510 = gequal(r050F, body.constant(4292870144u));
               ir_expression *const r0511 = nequal(swizzle_x(r01CE), body.constant(0u));
               ir_expression *const r0512 = bit_and(swizzle_y(r01CE), body.constant(1048575u));
               ir_expression *const r0513 = nequal(r0512, body.constant(0u));
               ir_expression *const r0514 = logic_or(r0511, r0513);
               ir_expression *const r0515 = logic_and(r0510, r0514);
               ir_swizzle *const r0516 = swizzle(r0515, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0517 = expr(ir_triop_csel, r0516, r0501, r0500);
               ir_expression *const r0518 = expr(ir_triop_csel, r050E, r0517, r0501);
               ir_constant_data r0519_data;
               memset(&r0519_data, 0, sizeof(ir_constant_data));
               r0519_data.u[0] = 4294967295;
               r0519_data.u[1] = 4294967295;
               ir_constant *const r0519 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0519_data);
               body.emit(assign(r01D0, expr(ir_triop_csel, r0506, r0518, r0519), 0x03));

               body.emit(assign(r01CF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f04FE->else_instructions;

               ir_expression *const r051A = equal(r01E0, body.constant(int(0)));
               body.emit(assign(r01D3, expr(ir_triop_csel, r051A, body.constant(int(1)), r01E3), 0x01));

               ir_expression *const r051B = equal(r01E0, body.constant(int(0)));
               body.emit(assign(r01D4, expr(ir_triop_csel, r051B, body.constant(int(1)), r01E0), 0x01));

               /* IF CONDITION */
               ir_expression *const r051D = less(r01D5, r01D7);
               ir_if *f051C = new(mem_ctx) ir_if(operand(r051D).val);
               exec_list *const f051C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f051C->then_instructions;

                  ir_variable *const r051E = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_expression *const r051F = sub(r01D7, r01D5);
                  ir_expression *const r0520 = less(r01D8, r01D6);
                  ir_expression *const r0521 = expr(ir_unop_b2i, r0520);
                  ir_expression *const r0522 = expr(ir_unop_i2u, r0521);
                  body.emit(assign(r051E, sub(r051F, r0522), 0x01));

                  body.emit(assign(r01D2, r051E, 0x01));

                  body.emit(assign(r036B, add(r01D4, body.constant(int(-1))), 0x01));

                  ir_variable *const r0523 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0523, add(r036B, body.constant(int(-10))), 0x01));

                  ir_variable *const r0524 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  ir_variable *const r0525 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  ir_variable *const r0526 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r0526);
                  ir_variable *const r0527 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0527);
                  ir_expression *const r0528 = equal(r051E, body.constant(0u));
                  ir_expression *const r0529 = add(r0523, body.constant(int(-32)));
                  body.emit(assign(r0523, expr(ir_triop_csel, r0528, r0529, r0523), 0x01));

                  ir_variable *const r052A = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r052B = equal(r051E, body.constant(0u));
                  ir_expression *const r052C = sub(r01D8, r01D6);
                  body.emit(assign(r052A, expr(ir_triop_csel, r052B, body.constant(0u), r052C), 0x01));

                  body.emit(assign(r0525, r052A, 0x01));

                  ir_variable *const r052D = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r052E = equal(r051E, body.constant(0u));
                  body.emit(assign(r052D, expr(ir_triop_csel, r052E, r052A, r051E), 0x01));

                  body.emit(assign(r0524, r052D, 0x01));

                  ir_expression *const r052F = equal(r052D, body.constant(0u));
                  ir_expression *const r0530 = expr(ir_unop_find_msb, r052D);
                  ir_expression *const r0531 = sub(body.constant(int(31)), r0530);
                  ir_expression *const r0532 = expr(ir_triop_csel, r052F, body.constant(int(32)), r0531);
                  body.emit(assign(r0527, add(r0532, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0534 = gequal(r0527, body.constant(int(0)));
                  ir_if *f0533 = new(mem_ctx) ir_if(operand(r0534).val);
                  exec_list *const f0533_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0533->then_instructions;

                     body.emit(assign(r0526, body.constant(0u), 0x01));

                     ir_expression *const r0535 = equal(r0527, body.constant(int(0)));
                     ir_expression *const r0536 = lshift(r052D, r0527);
                     ir_expression *const r0537 = neg(r0527);
                     ir_expression *const r0538 = bit_and(r0537, body.constant(int(31)));
                     ir_expression *const r0539 = rshift(r052A, r0538);
                     ir_expression *const r053A = bit_or(r0536, r0539);
                     body.emit(assign(r0524, expr(ir_triop_csel, r0535, r052D, r053A), 0x01));

                     body.emit(assign(r0525, lshift(r052A, r0527), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0533->else_instructions;

                     ir_variable *const r053B = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r053B, body.constant(0u), 0x01));

                     ir_variable *const r053C = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r053C, neg(r0527), 0x01));

                     ir_variable *const r053D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r053D);
                     ir_variable *const r053E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r053E);
                     ir_variable *const r053F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r053F);
                     ir_variable *const r0540 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0541 = neg(r053C);
                     body.emit(assign(r0540, bit_and(r0541, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0543 = equal(r053C, body.constant(int(0)));
                     ir_if *f0542 = new(mem_ctx) ir_if(operand(r0543).val);
                     exec_list *const f0542_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0542->then_instructions;

                        body.emit(assign(r053D, r053B, 0x01));

                        body.emit(assign(r053E, r0525, 0x01));

                        body.emit(assign(r053F, r0524, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0542->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0545 = less(r053C, body.constant(int(32)));
                        ir_if *f0544 = new(mem_ctx) ir_if(operand(r0545).val);
                        exec_list *const f0544_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0544->then_instructions;

                           body.emit(assign(r053D, lshift(r0525, r0540), 0x01));

                           ir_expression *const r0546 = lshift(r0524, r0540);
                           ir_expression *const r0547 = rshift(r0525, r053C);
                           body.emit(assign(r053E, bit_or(r0546, r0547), 0x01));

                           body.emit(assign(r053F, rshift(r0524, r053C), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0544->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0549 = equal(r053C, body.constant(int(32)));
                           ir_if *f0548 = new(mem_ctx) ir_if(operand(r0549).val);
                           exec_list *const f0548_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0548->then_instructions;

                              body.emit(assign(r053D, r0525, 0x01));

                              body.emit(assign(r053E, r0524, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0548->else_instructions;

                              body.emit(assign(r053B, bit_or(body.constant(0u), r0525), 0x01));

                              ir_expression *const r054A = less(r053C, body.constant(int(64)));
                              ir_expression *const r054B = lshift(r0524, r0540);
                              ir_expression *const r054C = equal(r053C, body.constant(int(64)));
                              ir_expression *const r054D = nequal(r0524, body.constant(0u));
                              ir_expression *const r054E = expr(ir_unop_b2i, r054D);
                              ir_expression *const r054F = expr(ir_unop_i2u, r054E);
                              ir_expression *const r0550 = expr(ir_triop_csel, r054C, r0524, r054F);
                              body.emit(assign(r053D, expr(ir_triop_csel, r054A, r054B, r0550), 0x01));

                              ir_expression *const r0551 = less(r053C, body.constant(int(64)));
                              ir_expression *const r0552 = bit_and(r053C, body.constant(int(31)));
                              ir_expression *const r0553 = rshift(r0524, r0552);
                              body.emit(assign(r053E, expr(ir_triop_csel, r0551, r0553, body.constant(0u)), 0x01));


                           body.instructions = f0548_parent_instructions;
                           body.emit(f0548);

                           /* END IF */

                           body.emit(assign(r053F, body.constant(0u), 0x01));


                        body.instructions = f0544_parent_instructions;
                        body.emit(f0544);

                        /* END IF */

                        ir_expression *const r0554 = nequal(r053B, body.constant(0u));
                        ir_expression *const r0555 = expr(ir_unop_b2i, r0554);
                        ir_expression *const r0556 = expr(ir_unop_i2u, r0555);
                        body.emit(assign(r053D, bit_or(r053D, r0556), 0x01));


                     body.instructions = f0542_parent_instructions;
                     body.emit(f0542);

                     /* END IF */

                     body.emit(assign(r0524, r053F, 0x01));

                     body.emit(assign(r0525, r053E, 0x01));

                     body.emit(assign(r0526, r053D, 0x01));


                  body.instructions = f0533_parent_instructions;
                  body.emit(f0533);

                  /* END IF */

                  body.emit(assign(r0523, sub(r0523, r0527), 0x01));

                  ir_variable *const r0557 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0557, r0523, 0x01));

                  ir_variable *const r0558 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0558, r0524, 0x01));

                  ir_variable *const r0559 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0559, r0525, 0x01));

                  ir_variable *const r055A = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r055A, r0526, 0x01));

                  ir_variable *const r055B = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r055B, body.constant(true), 0x01));

                  ir_variable *const r055C = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r055D = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r055D);
                  ir_expression *const r055E = expr(ir_unop_u2i, r0526);
                  body.emit(assign(r055D, less(r055E, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0560 = gequal(r0523, body.constant(int(2045)));
                  ir_if *f055F = new(mem_ctx) ir_if(operand(r0560).val);
                  exec_list *const f055F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f055F->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0562 = less(body.constant(int(2045)), r0523);
                     ir_expression *const r0563 = equal(r0523, body.constant(int(2045)));
                     ir_expression *const r0564 = equal(body.constant(2097151u), r0524);
                     ir_expression *const r0565 = equal(body.constant(4294967295u), r0525);
                     ir_expression *const r0566 = logic_and(r0564, r0565);
                     ir_expression *const r0567 = logic_and(r0563, r0566);
                     ir_expression *const r0568 = logic_and(r0567, r055D);
                     ir_expression *const r0569 = logic_or(r0562, r0568);
                     ir_if *f0561 = new(mem_ctx) ir_if(operand(r0569).val);
                     exec_list *const f0561_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0561->then_instructions;

                        ir_variable *const r056A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r056A);
                        ir_expression *const r056B = lshift(r01D9, body.constant(int(31)));
                        body.emit(assign(r056A, add(r056B, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r056A, body.constant(0u), 0x01));

                        body.emit(assign(r055C, r056A, 0x03));

                        body.emit(assign(r055B, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0561->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r056D = less(r0523, body.constant(int(0)));
                        ir_if *f056C = new(mem_ctx) ir_if(operand(r056D).val);
                        exec_list *const f056C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f056C->then_instructions;

                           ir_variable *const r056E = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r056E, r0526, 0x01));

                           ir_variable *const r056F = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r056F, neg(r0523), 0x01));

                           ir_variable *const r0570 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0570);
                           ir_variable *const r0571 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0571);
                           ir_variable *const r0572 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0572);
                           ir_variable *const r0573 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0574 = neg(r056F);
                           body.emit(assign(r0573, bit_and(r0574, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0576 = equal(r056F, body.constant(int(0)));
                           ir_if *f0575 = new(mem_ctx) ir_if(operand(r0576).val);
                           exec_list *const f0575_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0575->then_instructions;

                              body.emit(assign(r0570, r0526, 0x01));

                              body.emit(assign(r0571, r0525, 0x01));

                              body.emit(assign(r0572, r0524, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0575->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0578 = less(r056F, body.constant(int(32)));
                              ir_if *f0577 = new(mem_ctx) ir_if(operand(r0578).val);
                              exec_list *const f0577_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0577->then_instructions;

                                 body.emit(assign(r0570, lshift(r0525, r0573), 0x01));

                                 ir_expression *const r0579 = lshift(r0524, r0573);
                                 ir_expression *const r057A = rshift(r0525, r056F);
                                 body.emit(assign(r0571, bit_or(r0579, r057A), 0x01));

                                 body.emit(assign(r0572, rshift(r0524, r056F), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0577->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r057C = equal(r056F, body.constant(int(32)));
                                 ir_if *f057B = new(mem_ctx) ir_if(operand(r057C).val);
                                 exec_list *const f057B_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f057B->then_instructions;

                                    body.emit(assign(r0570, r0525, 0x01));

                                    body.emit(assign(r0571, r0524, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f057B->else_instructions;

                                    body.emit(assign(r056E, bit_or(r0526, r0525), 0x01));

                                    ir_expression *const r057D = less(r056F, body.constant(int(64)));
                                    ir_expression *const r057E = lshift(r0524, r0573);
                                    ir_expression *const r057F = equal(r056F, body.constant(int(64)));
                                    ir_expression *const r0580 = nequal(r0524, body.constant(0u));
                                    ir_expression *const r0581 = expr(ir_unop_b2i, r0580);
                                    ir_expression *const r0582 = expr(ir_unop_i2u, r0581);
                                    ir_expression *const r0583 = expr(ir_triop_csel, r057F, r0524, r0582);
                                    body.emit(assign(r0570, expr(ir_triop_csel, r057D, r057E, r0583), 0x01));

                                    ir_expression *const r0584 = less(r056F, body.constant(int(64)));
                                    ir_expression *const r0585 = bit_and(r056F, body.constant(int(31)));
                                    ir_expression *const r0586 = rshift(r0524, r0585);
                                    body.emit(assign(r0571, expr(ir_triop_csel, r0584, r0586, body.constant(0u)), 0x01));


                                 body.instructions = f057B_parent_instructions;
                                 body.emit(f057B);

                                 /* END IF */

                                 body.emit(assign(r0572, body.constant(0u), 0x01));


                              body.instructions = f0577_parent_instructions;
                              body.emit(f0577);

                              /* END IF */

                              ir_expression *const r0587 = nequal(r056E, body.constant(0u));
                              ir_expression *const r0588 = expr(ir_unop_b2i, r0587);
                              ir_expression *const r0589 = expr(ir_unop_i2u, r0588);
                              body.emit(assign(r0570, bit_or(r0570, r0589), 0x01));


                           body.instructions = f0575_parent_instructions;
                           body.emit(f0575);

                           /* END IF */

                           body.emit(assign(r0558, r0572, 0x01));

                           body.emit(assign(r0559, r0571, 0x01));

                           body.emit(assign(r055A, r0570, 0x01));

                           body.emit(assign(r0557, body.constant(int(0)), 0x01));

                           body.emit(assign(r055D, less(r0570, body.constant(0u)), 0x01));


                        body.instructions = f056C_parent_instructions;
                        body.emit(f056C);

                        /* END IF */


                     body.instructions = f0561_parent_instructions;
                     body.emit(f0561);

                     /* END IF */


                  body.instructions = f055F_parent_instructions;
                  body.emit(f055F);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f058A = new(mem_ctx) ir_if(operand(r055B).val);
                  exec_list *const f058A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f058A->then_instructions;

                     /* IF CONDITION */
                     ir_if *f058B = new(mem_ctx) ir_if(operand(r055D).val);
                     exec_list *const f058B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f058B->then_instructions;

                        ir_variable *const r058C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r058C, add(r0559, body.constant(1u)), 0x01));

                        ir_expression *const r058D = less(r058C, r0559);
                        ir_expression *const r058E = expr(ir_unop_b2i, r058D);
                        ir_expression *const r058F = expr(ir_unop_i2u, r058E);
                        body.emit(assign(r0558, add(r0558, r058F), 0x01));

                        ir_expression *const r0590 = equal(r055A, body.constant(0u));
                        ir_expression *const r0591 = expr(ir_unop_b2i, r0590);
                        ir_expression *const r0592 = expr(ir_unop_i2u, r0591);
                        ir_expression *const r0593 = add(r055A, r0592);
                        ir_expression *const r0594 = bit_and(r0593, body.constant(1u));
                        ir_expression *const r0595 = expr(ir_unop_bit_not, r0594);
                        body.emit(assign(r0559, bit_and(r058C, r0595), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f058B->else_instructions;

                        ir_expression *const r0596 = bit_or(r0558, r0559);
                        ir_expression *const r0597 = equal(r0596, body.constant(0u));
                        body.emit(assign(r0557, expr(ir_triop_csel, r0597, body.constant(int(0)), r0557), 0x01));


                     body.instructions = f058B_parent_instructions;
                     body.emit(f058B);

                     /* END IF */

                     ir_variable *const r0598 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0598);
                     ir_expression *const r0599 = lshift(r01D9, body.constant(int(31)));
                     ir_expression *const r059A = expr(ir_unop_i2u, r0557);
                     ir_expression *const r059B = lshift(r059A, body.constant(int(20)));
                     ir_expression *const r059C = add(r0599, r059B);
                     body.emit(assign(r0598, add(r059C, r0558), 0x02));

                     body.emit(assign(r0598, r0559, 0x01));

                     body.emit(assign(r055C, r0598, 0x03));

                     body.emit(assign(r055B, body.constant(false), 0x01));


                  body.instructions = f058A_parent_instructions;
                  body.emit(f058A);

                  /* END IF */

                  body.emit(assign(r01D0, r055C, 0x03));

                  body.emit(assign(r01CF, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f051C->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r059E = less(r01D7, r01D5);
                  ir_if *f059D = new(mem_ctx) ir_if(operand(r059E).val);
                  exec_list *const f059D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f059D->then_instructions;

                     ir_variable *const r059F = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_expression *const r05A0 = sub(r01D5, r01D7);
                     ir_expression *const r05A1 = less(r01D6, r01D8);
                     ir_expression *const r05A2 = expr(ir_unop_b2i, r05A1);
                     ir_expression *const r05A3 = expr(ir_unop_i2u, r05A2);
                     body.emit(assign(r059F, sub(r05A0, r05A3), 0x01));

                     body.emit(assign(r01D2, r059F, 0x01));

                     body.emit(assign(r01D9, bit_xor(r01D9, body.constant(1u)), 0x01));

                     body.emit(assign(r036B, add(r01D3, body.constant(int(-1))), 0x01));

                     ir_variable *const r05A4 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05A4, add(r036B, body.constant(int(-10))), 0x01));

                     ir_variable *const r05A5 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     ir_variable *const r05A6 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     ir_variable *const r05A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r05A7);
                     ir_variable *const r05A8 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05A8);
                     ir_expression *const r05A9 = equal(r059F, body.constant(0u));
                     ir_expression *const r05AA = add(r05A4, body.constant(int(-32)));
                     body.emit(assign(r05A4, expr(ir_triop_csel, r05A9, r05AA, r05A4), 0x01));

                     ir_variable *const r05AB = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05AC = equal(r059F, body.constant(0u));
                     ir_expression *const r05AD = sub(r01D6, r01D8);
                     body.emit(assign(r05AB, expr(ir_triop_csel, r05AC, body.constant(0u), r05AD), 0x01));

                     body.emit(assign(r05A6, r05AB, 0x01));

                     ir_variable *const r05AE = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05AF = equal(r059F, body.constant(0u));
                     body.emit(assign(r05AE, expr(ir_triop_csel, r05AF, r05AB, r059F), 0x01));

                     body.emit(assign(r05A5, r05AE, 0x01));

                     ir_expression *const r05B0 = equal(r05AE, body.constant(0u));
                     ir_expression *const r05B1 = expr(ir_unop_find_msb, r05AE);
                     ir_expression *const r05B2 = sub(body.constant(int(31)), r05B1);
                     ir_expression *const r05B3 = expr(ir_triop_csel, r05B0, body.constant(int(32)), r05B2);
                     body.emit(assign(r05A8, add(r05B3, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05B5 = gequal(r05A8, body.constant(int(0)));
                     ir_if *f05B4 = new(mem_ctx) ir_if(operand(r05B5).val);
                     exec_list *const f05B4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05B4->then_instructions;

                        body.emit(assign(r05A7, body.constant(0u), 0x01));

                        ir_expression *const r05B6 = equal(r05A8, body.constant(int(0)));
                        ir_expression *const r05B7 = lshift(r05AE, r05A8);
                        ir_expression *const r05B8 = neg(r05A8);
                        ir_expression *const r05B9 = bit_and(r05B8, body.constant(int(31)));
                        ir_expression *const r05BA = rshift(r05AB, r05B9);
                        ir_expression *const r05BB = bit_or(r05B7, r05BA);
                        body.emit(assign(r05A5, expr(ir_triop_csel, r05B6, r05AE, r05BB), 0x01));

                        body.emit(assign(r05A6, lshift(r05AB, r05A8), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05B4->else_instructions;

                        ir_variable *const r05BC = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r05BC, body.constant(0u), 0x01));

                        ir_variable *const r05BD = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r05BD, neg(r05A8), 0x01));

                        ir_variable *const r05BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r05BE);
                        ir_variable *const r05BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r05BF);
                        ir_variable *const r05C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r05C0);
                        ir_variable *const r05C1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r05C2 = neg(r05BD);
                        body.emit(assign(r05C1, bit_and(r05C2, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05C4 = equal(r05BD, body.constant(int(0)));
                        ir_if *f05C3 = new(mem_ctx) ir_if(operand(r05C4).val);
                        exec_list *const f05C3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05C3->then_instructions;

                           body.emit(assign(r05BE, r05BC, 0x01));

                           body.emit(assign(r05BF, r05A6, 0x01));

                           body.emit(assign(r05C0, r05A5, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05C3->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05C6 = less(r05BD, body.constant(int(32)));
                           ir_if *f05C5 = new(mem_ctx) ir_if(operand(r05C6).val);
                           exec_list *const f05C5_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05C5->then_instructions;

                              body.emit(assign(r05BE, lshift(r05A6, r05C1), 0x01));

                              ir_expression *const r05C7 = lshift(r05A5, r05C1);
                              ir_expression *const r05C8 = rshift(r05A6, r05BD);
                              body.emit(assign(r05BF, bit_or(r05C7, r05C8), 0x01));

                              body.emit(assign(r05C0, rshift(r05A5, r05BD), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05C5->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05CA = equal(r05BD, body.constant(int(32)));
                              ir_if *f05C9 = new(mem_ctx) ir_if(operand(r05CA).val);
                              exec_list *const f05C9_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05C9->then_instructions;

                                 body.emit(assign(r05BE, r05A6, 0x01));

                                 body.emit(assign(r05BF, r05A5, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05C9->else_instructions;

                                 body.emit(assign(r05BC, bit_or(body.constant(0u), r05A6), 0x01));

                                 ir_expression *const r05CB = less(r05BD, body.constant(int(64)));
                                 ir_expression *const r05CC = lshift(r05A5, r05C1);
                                 ir_expression *const r05CD = equal(r05BD, body.constant(int(64)));
                                 ir_expression *const r05CE = nequal(r05A5, body.constant(0u));
                                 ir_expression *const r05CF = expr(ir_unop_b2i, r05CE);
                                 ir_expression *const r05D0 = expr(ir_unop_i2u, r05CF);
                                 ir_expression *const r05D1 = expr(ir_triop_csel, r05CD, r05A5, r05D0);
                                 body.emit(assign(r05BE, expr(ir_triop_csel, r05CB, r05CC, r05D1), 0x01));

                                 ir_expression *const r05D2 = less(r05BD, body.constant(int(64)));
                                 ir_expression *const r05D3 = bit_and(r05BD, body.constant(int(31)));
                                 ir_expression *const r05D4 = rshift(r05A5, r05D3);
                                 body.emit(assign(r05BF, expr(ir_triop_csel, r05D2, r05D4, body.constant(0u)), 0x01));


                              body.instructions = f05C9_parent_instructions;
                              body.emit(f05C9);

                              /* END IF */

                              body.emit(assign(r05C0, body.constant(0u), 0x01));


                           body.instructions = f05C5_parent_instructions;
                           body.emit(f05C5);

                           /* END IF */

                           ir_expression *const r05D5 = nequal(r05BC, body.constant(0u));
                           ir_expression *const r05D6 = expr(ir_unop_b2i, r05D5);
                           ir_expression *const r05D7 = expr(ir_unop_i2u, r05D6);
                           body.emit(assign(r05BE, bit_or(r05BE, r05D7), 0x01));


                        body.instructions = f05C3_parent_instructions;
                        body.emit(f05C3);

                        /* END IF */

                        body.emit(assign(r05A5, r05C0, 0x01));

                        body.emit(assign(r05A6, r05BF, 0x01));

                        body.emit(assign(r05A7, r05BE, 0x01));


                     body.instructions = f05B4_parent_instructions;
                     body.emit(f05B4);

                     /* END IF */

                     body.emit(assign(r05A4, sub(r05A4, r05A8), 0x01));

                     ir_variable *const r05D8 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05D8, r05A4, 0x01));

                     ir_variable *const r05D9 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r05D9, r05A5, 0x01));

                     ir_variable *const r05DA = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r05DA, r05A6, 0x01));

                     ir_variable *const r05DB = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r05DB, r05A7, 0x01));

                     ir_variable *const r05DC = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r05DC, body.constant(true), 0x01));

                     ir_variable *const r05DD = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r05DE = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r05DE);
                     ir_expression *const r05DF = expr(ir_unop_u2i, r05A7);
                     body.emit(assign(r05DE, less(r05DF, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05E1 = gequal(r05A4, body.constant(int(2045)));
                     ir_if *f05E0 = new(mem_ctx) ir_if(operand(r05E1).val);
                     exec_list *const f05E0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05E0->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05E3 = less(body.constant(int(2045)), r05A4);
                        ir_expression *const r05E4 = equal(r05A4, body.constant(int(2045)));
                        ir_expression *const r05E5 = equal(body.constant(2097151u), r05A5);
                        ir_expression *const r05E6 = equal(body.constant(4294967295u), r05A6);
                        ir_expression *const r05E7 = logic_and(r05E5, r05E6);
                        ir_expression *const r05E8 = logic_and(r05E4, r05E7);
                        ir_expression *const r05E9 = logic_and(r05E8, r05DE);
                        ir_expression *const r05EA = logic_or(r05E3, r05E9);
                        ir_if *f05E2 = new(mem_ctx) ir_if(operand(r05EA).val);
                        exec_list *const f05E2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E2->then_instructions;

                           ir_variable *const r05EB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r05EB);
                           ir_expression *const r05EC = lshift(r01D9, body.constant(int(31)));
                           body.emit(assign(r05EB, add(r05EC, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r05EB, body.constant(0u), 0x01));

                           body.emit(assign(r05DD, r05EB, 0x03));

                           body.emit(assign(r05DC, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05E2->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05EE = less(r05A4, body.constant(int(0)));
                           ir_if *f05ED = new(mem_ctx) ir_if(operand(r05EE).val);
                           exec_list *const f05ED_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05ED->then_instructions;

                              ir_variable *const r05EF = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r05EF, r05A7, 0x01));

                              ir_variable *const r05F0 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r05F0, neg(r05A4), 0x01));

                              ir_variable *const r05F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r05F1);
                              ir_variable *const r05F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r05F2);
                              ir_variable *const r05F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r05F3);
                              ir_variable *const r05F4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r05F5 = neg(r05F0);
                              body.emit(assign(r05F4, bit_and(r05F5, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r05F7 = equal(r05F0, body.constant(int(0)));
                              ir_if *f05F6 = new(mem_ctx) ir_if(operand(r05F7).val);
                              exec_list *const f05F6_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05F6->then_instructions;

                                 body.emit(assign(r05F1, r05A7, 0x01));

                                 body.emit(assign(r05F2, r05A6, 0x01));

                                 body.emit(assign(r05F3, r05A5, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05F6->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05F9 = less(r05F0, body.constant(int(32)));
                                 ir_if *f05F8 = new(mem_ctx) ir_if(operand(r05F9).val);
                                 exec_list *const f05F8_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05F8->then_instructions;

                                    body.emit(assign(r05F1, lshift(r05A6, r05F4), 0x01));

                                    ir_expression *const r05FA = lshift(r05A5, r05F4);
                                    ir_expression *const r05FB = rshift(r05A6, r05F0);
                                    body.emit(assign(r05F2, bit_or(r05FA, r05FB), 0x01));

                                    body.emit(assign(r05F3, rshift(r05A5, r05F0), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05F8->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r05FD = equal(r05F0, body.constant(int(32)));
                                    ir_if *f05FC = new(mem_ctx) ir_if(operand(r05FD).val);
                                    exec_list *const f05FC_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f05FC->then_instructions;

                                       body.emit(assign(r05F1, r05A6, 0x01));

                                       body.emit(assign(r05F2, r05A5, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f05FC->else_instructions;

                                       body.emit(assign(r05EF, bit_or(r05A7, r05A6), 0x01));

                                       ir_expression *const r05FE = less(r05F0, body.constant(int(64)));
                                       ir_expression *const r05FF = lshift(r05A5, r05F4);
                                       ir_expression *const r0600 = equal(r05F0, body.constant(int(64)));
                                       ir_expression *const r0601 = nequal(r05A5, body.constant(0u));
                                       ir_expression *const r0602 = expr(ir_unop_b2i, r0601);
                                       ir_expression *const r0603 = expr(ir_unop_i2u, r0602);
                                       ir_expression *const r0604 = expr(ir_triop_csel, r0600, r05A5, r0603);
                                       body.emit(assign(r05F1, expr(ir_triop_csel, r05FE, r05FF, r0604), 0x01));

                                       ir_expression *const r0605 = less(r05F0, body.constant(int(64)));
                                       ir_expression *const r0606 = bit_and(r05F0, body.constant(int(31)));
                                       ir_expression *const r0607 = rshift(r05A5, r0606);
                                       body.emit(assign(r05F2, expr(ir_triop_csel, r0605, r0607, body.constant(0u)), 0x01));


                                    body.instructions = f05FC_parent_instructions;
                                    body.emit(f05FC);

                                    /* END IF */

                                    body.emit(assign(r05F3, body.constant(0u), 0x01));


                                 body.instructions = f05F8_parent_instructions;
                                 body.emit(f05F8);

                                 /* END IF */

                                 ir_expression *const r0608 = nequal(r05EF, body.constant(0u));
                                 ir_expression *const r0609 = expr(ir_unop_b2i, r0608);
                                 ir_expression *const r060A = expr(ir_unop_i2u, r0609);
                                 body.emit(assign(r05F1, bit_or(r05F1, r060A), 0x01));


                              body.instructions = f05F6_parent_instructions;
                              body.emit(f05F6);

                              /* END IF */

                              body.emit(assign(r05D9, r05F3, 0x01));

                              body.emit(assign(r05DA, r05F2, 0x01));

                              body.emit(assign(r05DB, r05F1, 0x01));

                              body.emit(assign(r05D8, body.constant(int(0)), 0x01));

                              body.emit(assign(r05DE, less(r05F1, body.constant(0u)), 0x01));


                           body.instructions = f05ED_parent_instructions;
                           body.emit(f05ED);

                           /* END IF */


                        body.instructions = f05E2_parent_instructions;
                        body.emit(f05E2);

                        /* END IF */


                     body.instructions = f05E0_parent_instructions;
                     body.emit(f05E0);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f060B = new(mem_ctx) ir_if(operand(r05DC).val);
                     exec_list *const f060B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f060B->then_instructions;

                        /* IF CONDITION */
                        ir_if *f060C = new(mem_ctx) ir_if(operand(r05DE).val);
                        exec_list *const f060C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f060C->then_instructions;

                           ir_variable *const r060D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r060D, add(r05DA, body.constant(1u)), 0x01));

                           ir_expression *const r060E = less(r060D, r05DA);
                           ir_expression *const r060F = expr(ir_unop_b2i, r060E);
                           ir_expression *const r0610 = expr(ir_unop_i2u, r060F);
                           body.emit(assign(r05D9, add(r05D9, r0610), 0x01));

                           ir_expression *const r0611 = equal(r05DB, body.constant(0u));
                           ir_expression *const r0612 = expr(ir_unop_b2i, r0611);
                           ir_expression *const r0613 = expr(ir_unop_i2u, r0612);
                           ir_expression *const r0614 = add(r05DB, r0613);
                           ir_expression *const r0615 = bit_and(r0614, body.constant(1u));
                           ir_expression *const r0616 = expr(ir_unop_bit_not, r0615);
                           body.emit(assign(r05DA, bit_and(r060D, r0616), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f060C->else_instructions;

                           ir_expression *const r0617 = bit_or(r05D9, r05DA);
                           ir_expression *const r0618 = equal(r0617, body.constant(0u));
                           body.emit(assign(r05D8, expr(ir_triop_csel, r0618, body.constant(int(0)), r05D8), 0x01));


                        body.instructions = f060C_parent_instructions;
                        body.emit(f060C);

                        /* END IF */

                        ir_variable *const r0619 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0619);
                        ir_expression *const r061A = lshift(r01D9, body.constant(int(31)));
                        ir_expression *const r061B = expr(ir_unop_i2u, r05D8);
                        ir_expression *const r061C = lshift(r061B, body.constant(int(20)));
                        ir_expression *const r061D = add(r061A, r061C);
                        body.emit(assign(r0619, add(r061D, r05D9), 0x02));

                        body.emit(assign(r0619, r05DA, 0x01));

                        body.emit(assign(r05DD, r0619, 0x03));

                        body.emit(assign(r05DC, body.constant(false), 0x01));


                     body.instructions = f060B_parent_instructions;
                     body.emit(f060B);

                     /* END IF */

                     body.emit(assign(r01D0, r05DD, 0x03));

                     body.emit(assign(r01CF, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f059D->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r061F = less(r01D6, r01D8);
                     ir_if *f061E = new(mem_ctx) ir_if(operand(r061F).val);
                     exec_list *const f061E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f061E->then_instructions;

                        ir_variable *const r0620 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_expression *const r0621 = sub(r01D7, r01D5);
                        ir_expression *const r0622 = less(r01D8, r01D6);
                        ir_expression *const r0623 = expr(ir_unop_b2i, r0622);
                        ir_expression *const r0624 = expr(ir_unop_i2u, r0623);
                        body.emit(assign(r0620, sub(r0621, r0624), 0x01));

                        body.emit(assign(r01D2, r0620, 0x01));

                        body.emit(assign(r036B, add(r01D4, body.constant(int(-1))), 0x01));

                        ir_variable *const r0625 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0625, add(r036B, body.constant(int(-10))), 0x01));

                        ir_variable *const r0626 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        ir_variable *const r0627 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        ir_variable *const r0628 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0628);
                        ir_variable *const r0629 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0629);
                        ir_expression *const r062A = equal(r0620, body.constant(0u));
                        ir_expression *const r062B = add(r0625, body.constant(int(-32)));
                        body.emit(assign(r0625, expr(ir_triop_csel, r062A, r062B, r0625), 0x01));

                        ir_variable *const r062C = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r062D = equal(r0620, body.constant(0u));
                        ir_expression *const r062E = sub(r01D8, r01D6);
                        body.emit(assign(r062C, expr(ir_triop_csel, r062D, body.constant(0u), r062E), 0x01));

                        body.emit(assign(r0627, r062C, 0x01));

                        ir_variable *const r062F = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0630 = equal(r0620, body.constant(0u));
                        body.emit(assign(r062F, expr(ir_triop_csel, r0630, r062C, r0620), 0x01));

                        body.emit(assign(r0626, r062F, 0x01));

                        ir_expression *const r0631 = equal(r062F, body.constant(0u));
                        ir_expression *const r0632 = expr(ir_unop_find_msb, r062F);
                        ir_expression *const r0633 = sub(body.constant(int(31)), r0632);
                        ir_expression *const r0634 = expr(ir_triop_csel, r0631, body.constant(int(32)), r0633);
                        body.emit(assign(r0629, add(r0634, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0636 = gequal(r0629, body.constant(int(0)));
                        ir_if *f0635 = new(mem_ctx) ir_if(operand(r0636).val);
                        exec_list *const f0635_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0635->then_instructions;

                           body.emit(assign(r0628, body.constant(0u), 0x01));

                           ir_expression *const r0637 = equal(r0629, body.constant(int(0)));
                           ir_expression *const r0638 = lshift(r062F, r0629);
                           ir_expression *const r0639 = neg(r0629);
                           ir_expression *const r063A = bit_and(r0639, body.constant(int(31)));
                           ir_expression *const r063B = rshift(r062C, r063A);
                           ir_expression *const r063C = bit_or(r0638, r063B);
                           body.emit(assign(r0626, expr(ir_triop_csel, r0637, r062F, r063C), 0x01));

                           body.emit(assign(r0627, lshift(r062C, r0629), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0635->else_instructions;

                           ir_variable *const r063D = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r063D, body.constant(0u), 0x01));

                           ir_variable *const r063E = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r063E, neg(r0629), 0x01));

                           ir_variable *const r063F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r063F);
                           ir_variable *const r0640 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0640);
                           ir_variable *const r0641 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0641);
                           ir_variable *const r0642 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0643 = neg(r063E);
                           body.emit(assign(r0642, bit_and(r0643, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0645 = equal(r063E, body.constant(int(0)));
                           ir_if *f0644 = new(mem_ctx) ir_if(operand(r0645).val);
                           exec_list *const f0644_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0644->then_instructions;

                              body.emit(assign(r063F, r063D, 0x01));

                              body.emit(assign(r0640, r0627, 0x01));

                              body.emit(assign(r0641, r0626, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0644->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0647 = less(r063E, body.constant(int(32)));
                              ir_if *f0646 = new(mem_ctx) ir_if(operand(r0647).val);
                              exec_list *const f0646_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0646->then_instructions;

                                 body.emit(assign(r063F, lshift(r0627, r0642), 0x01));

                                 ir_expression *const r0648 = lshift(r0626, r0642);
                                 ir_expression *const r0649 = rshift(r0627, r063E);
                                 body.emit(assign(r0640, bit_or(r0648, r0649), 0x01));

                                 body.emit(assign(r0641, rshift(r0626, r063E), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0646->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r064B = equal(r063E, body.constant(int(32)));
                                 ir_if *f064A = new(mem_ctx) ir_if(operand(r064B).val);
                                 exec_list *const f064A_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f064A->then_instructions;

                                    body.emit(assign(r063F, r0627, 0x01));

                                    body.emit(assign(r0640, r0626, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f064A->else_instructions;

                                    body.emit(assign(r063D, bit_or(body.constant(0u), r0627), 0x01));

                                    ir_expression *const r064C = less(r063E, body.constant(int(64)));
                                    ir_expression *const r064D = lshift(r0626, r0642);
                                    ir_expression *const r064E = equal(r063E, body.constant(int(64)));
                                    ir_expression *const r064F = nequal(r0626, body.constant(0u));
                                    ir_expression *const r0650 = expr(ir_unop_b2i, r064F);
                                    ir_expression *const r0651 = expr(ir_unop_i2u, r0650);
                                    ir_expression *const r0652 = expr(ir_triop_csel, r064E, r0626, r0651);
                                    body.emit(assign(r063F, expr(ir_triop_csel, r064C, r064D, r0652), 0x01));

                                    ir_expression *const r0653 = less(r063E, body.constant(int(64)));
                                    ir_expression *const r0654 = bit_and(r063E, body.constant(int(31)));
                                    ir_expression *const r0655 = rshift(r0626, r0654);
                                    body.emit(assign(r0640, expr(ir_triop_csel, r0653, r0655, body.constant(0u)), 0x01));


                                 body.instructions = f064A_parent_instructions;
                                 body.emit(f064A);

                                 /* END IF */

                                 body.emit(assign(r0641, body.constant(0u), 0x01));


                              body.instructions = f0646_parent_instructions;
                              body.emit(f0646);

                              /* END IF */

                              ir_expression *const r0656 = nequal(r063D, body.constant(0u));
                              ir_expression *const r0657 = expr(ir_unop_b2i, r0656);
                              ir_expression *const r0658 = expr(ir_unop_i2u, r0657);
                              body.emit(assign(r063F, bit_or(r063F, r0658), 0x01));


                           body.instructions = f0644_parent_instructions;
                           body.emit(f0644);

                           /* END IF */

                           body.emit(assign(r0626, r0641, 0x01));

                           body.emit(assign(r0627, r0640, 0x01));

                           body.emit(assign(r0628, r063F, 0x01));


                        body.instructions = f0635_parent_instructions;
                        body.emit(f0635);

                        /* END IF */

                        body.emit(assign(r0625, sub(r0625, r0629), 0x01));

                        ir_variable *const r0659 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0659, r0625, 0x01));

                        ir_variable *const r065A = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r065A, r0626, 0x01));

                        ir_variable *const r065B = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r065B, r0627, 0x01));

                        ir_variable *const r065C = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r065C, r0628, 0x01));

                        ir_variable *const r065D = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r065D, body.constant(true), 0x01));

                        ir_variable *const r065E = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r065F = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r065F);
                        ir_expression *const r0660 = expr(ir_unop_u2i, r0628);
                        body.emit(assign(r065F, less(r0660, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0662 = gequal(r0625, body.constant(int(2045)));
                        ir_if *f0661 = new(mem_ctx) ir_if(operand(r0662).val);
                        exec_list *const f0661_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0661->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0664 = less(body.constant(int(2045)), r0625);
                           ir_expression *const r0665 = equal(r0625, body.constant(int(2045)));
                           ir_expression *const r0666 = equal(body.constant(2097151u), r0626);
                           ir_expression *const r0667 = equal(body.constant(4294967295u), r0627);
                           ir_expression *const r0668 = logic_and(r0666, r0667);
                           ir_expression *const r0669 = logic_and(r0665, r0668);
                           ir_expression *const r066A = logic_and(r0669, r065F);
                           ir_expression *const r066B = logic_or(r0664, r066A);
                           ir_if *f0663 = new(mem_ctx) ir_if(operand(r066B).val);
                           exec_list *const f0663_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0663->then_instructions;

                              ir_variable *const r066C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r066C);
                              ir_expression *const r066D = lshift(r01D9, body.constant(int(31)));
                              body.emit(assign(r066C, add(r066D, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r066C, body.constant(0u), 0x01));

                              body.emit(assign(r065E, r066C, 0x03));

                              body.emit(assign(r065D, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0663->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r066F = less(r0625, body.constant(int(0)));
                              ir_if *f066E = new(mem_ctx) ir_if(operand(r066F).val);
                              exec_list *const f066E_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f066E->then_instructions;

                                 ir_variable *const r0670 = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r0670, r0628, 0x01));

                                 ir_variable *const r0671 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r0671, neg(r0625), 0x01));

                                 ir_variable *const r0672 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r0672);
                                 ir_variable *const r0673 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r0673);
                                 ir_variable *const r0674 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r0674);
                                 ir_variable *const r0675 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r0676 = neg(r0671);
                                 body.emit(assign(r0675, bit_and(r0676, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0678 = equal(r0671, body.constant(int(0)));
                                 ir_if *f0677 = new(mem_ctx) ir_if(operand(r0678).val);
                                 exec_list *const f0677_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0677->then_instructions;

                                    body.emit(assign(r0672, r0628, 0x01));

                                    body.emit(assign(r0673, r0627, 0x01));

                                    body.emit(assign(r0674, r0626, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0677->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r067A = less(r0671, body.constant(int(32)));
                                    ir_if *f0679 = new(mem_ctx) ir_if(operand(r067A).val);
                                    exec_list *const f0679_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0679->then_instructions;

                                       body.emit(assign(r0672, lshift(r0627, r0675), 0x01));

                                       ir_expression *const r067B = lshift(r0626, r0675);
                                       ir_expression *const r067C = rshift(r0627, r0671);
                                       body.emit(assign(r0673, bit_or(r067B, r067C), 0x01));

                                       body.emit(assign(r0674, rshift(r0626, r0671), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0679->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r067E = equal(r0671, body.constant(int(32)));
                                       ir_if *f067D = new(mem_ctx) ir_if(operand(r067E).val);
                                       exec_list *const f067D_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f067D->then_instructions;

                                          body.emit(assign(r0672, r0627, 0x01));

                                          body.emit(assign(r0673, r0626, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f067D->else_instructions;

                                          body.emit(assign(r0670, bit_or(r0628, r0627), 0x01));

                                          ir_expression *const r067F = less(r0671, body.constant(int(64)));
                                          ir_expression *const r0680 = lshift(r0626, r0675);
                                          ir_expression *const r0681 = equal(r0671, body.constant(int(64)));
                                          ir_expression *const r0682 = nequal(r0626, body.constant(0u));
                                          ir_expression *const r0683 = expr(ir_unop_b2i, r0682);
                                          ir_expression *const r0684 = expr(ir_unop_i2u, r0683);
                                          ir_expression *const r0685 = expr(ir_triop_csel, r0681, r0626, r0684);
                                          body.emit(assign(r0672, expr(ir_triop_csel, r067F, r0680, r0685), 0x01));

                                          ir_expression *const r0686 = less(r0671, body.constant(int(64)));
                                          ir_expression *const r0687 = bit_and(r0671, body.constant(int(31)));
                                          ir_expression *const r0688 = rshift(r0626, r0687);
                                          body.emit(assign(r0673, expr(ir_triop_csel, r0686, r0688, body.constant(0u)), 0x01));


                                       body.instructions = f067D_parent_instructions;
                                       body.emit(f067D);

                                       /* END IF */

                                       body.emit(assign(r0674, body.constant(0u), 0x01));


                                    body.instructions = f0679_parent_instructions;
                                    body.emit(f0679);

                                    /* END IF */

                                    ir_expression *const r0689 = nequal(r0670, body.constant(0u));
                                    ir_expression *const r068A = expr(ir_unop_b2i, r0689);
                                    ir_expression *const r068B = expr(ir_unop_i2u, r068A);
                                    body.emit(assign(r0672, bit_or(r0672, r068B), 0x01));


                                 body.instructions = f0677_parent_instructions;
                                 body.emit(f0677);

                                 /* END IF */

                                 body.emit(assign(r065A, r0674, 0x01));

                                 body.emit(assign(r065B, r0673, 0x01));

                                 body.emit(assign(r065C, r0672, 0x01));

                                 body.emit(assign(r0659, body.constant(int(0)), 0x01));

                                 body.emit(assign(r065F, less(r0672, body.constant(0u)), 0x01));


                              body.instructions = f066E_parent_instructions;
                              body.emit(f066E);

                              /* END IF */


                           body.instructions = f0663_parent_instructions;
                           body.emit(f0663);

                           /* END IF */


                        body.instructions = f0661_parent_instructions;
                        body.emit(f0661);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f068C = new(mem_ctx) ir_if(operand(r065D).val);
                        exec_list *const f068C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f068C->then_instructions;

                           /* IF CONDITION */
                           ir_if *f068D = new(mem_ctx) ir_if(operand(r065F).val);
                           exec_list *const f068D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f068D->then_instructions;

                              ir_variable *const r068E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r068E, add(r065B, body.constant(1u)), 0x01));

                              ir_expression *const r068F = less(r068E, r065B);
                              ir_expression *const r0690 = expr(ir_unop_b2i, r068F);
                              ir_expression *const r0691 = expr(ir_unop_i2u, r0690);
                              body.emit(assign(r065A, add(r065A, r0691), 0x01));

                              ir_expression *const r0692 = equal(r065C, body.constant(0u));
                              ir_expression *const r0693 = expr(ir_unop_b2i, r0692);
                              ir_expression *const r0694 = expr(ir_unop_i2u, r0693);
                              ir_expression *const r0695 = add(r065C, r0694);
                              ir_expression *const r0696 = bit_and(r0695, body.constant(1u));
                              ir_expression *const r0697 = expr(ir_unop_bit_not, r0696);
                              body.emit(assign(r065B, bit_and(r068E, r0697), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f068D->else_instructions;

                              ir_expression *const r0698 = bit_or(r065A, r065B);
                              ir_expression *const r0699 = equal(r0698, body.constant(0u));
                              body.emit(assign(r0659, expr(ir_triop_csel, r0699, body.constant(int(0)), r0659), 0x01));


                           body.instructions = f068D_parent_instructions;
                           body.emit(f068D);

                           /* END IF */

                           ir_variable *const r069A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r069A);
                           ir_expression *const r069B = lshift(r01D9, body.constant(int(31)));
                           ir_expression *const r069C = expr(ir_unop_i2u, r0659);
                           ir_expression *const r069D = lshift(r069C, body.constant(int(20)));
                           ir_expression *const r069E = add(r069B, r069D);
                           body.emit(assign(r069A, add(r069E, r065A), 0x02));

                           body.emit(assign(r069A, r065B, 0x01));

                           body.emit(assign(r065E, r069A, 0x03));

                           body.emit(assign(r065D, body.constant(false), 0x01));


                        body.instructions = f068C_parent_instructions;
                        body.emit(f068C);

                        /* END IF */

                        body.emit(assign(r01D0, r065E, 0x03));

                        body.emit(assign(r01CF, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f061E->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r06A0 = less(r01D8, r01D6);
                        ir_if *f069F = new(mem_ctx) ir_if(operand(r06A0).val);
                        exec_list *const f069F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f069F->then_instructions;

                           ir_variable *const r06A1 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_expression *const r06A2 = sub(r01D5, r01D7);
                           ir_expression *const r06A3 = less(r01D6, r01D8);
                           ir_expression *const r06A4 = expr(ir_unop_b2i, r06A3);
                           ir_expression *const r06A5 = expr(ir_unop_i2u, r06A4);
                           body.emit(assign(r06A1, sub(r06A2, r06A5), 0x01));

                           body.emit(assign(r01D2, r06A1, 0x01));

                           body.emit(assign(r01D9, bit_xor(r01D9, body.constant(1u)), 0x01));

                           body.emit(assign(r036B, add(r01D3, body.constant(int(-1))), 0x01));

                           ir_variable *const r06A6 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06A6, add(r036B, body.constant(int(-10))), 0x01));

                           ir_variable *const r06A7 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           ir_variable *const r06A8 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           ir_variable *const r06A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r06A9);
                           ir_variable *const r06AA = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06AA);
                           ir_expression *const r06AB = equal(r06A1, body.constant(0u));
                           ir_expression *const r06AC = add(r06A6, body.constant(int(-32)));
                           body.emit(assign(r06A6, expr(ir_triop_csel, r06AB, r06AC, r06A6), 0x01));

                           ir_variable *const r06AD = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06AE = equal(r06A1, body.constant(0u));
                           ir_expression *const r06AF = sub(r01D6, r01D8);
                           body.emit(assign(r06AD, expr(ir_triop_csel, r06AE, body.constant(0u), r06AF), 0x01));

                           body.emit(assign(r06A8, r06AD, 0x01));

                           ir_variable *const r06B0 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06B1 = equal(r06A1, body.constant(0u));
                           body.emit(assign(r06B0, expr(ir_triop_csel, r06B1, r06AD, r06A1), 0x01));

                           body.emit(assign(r06A7, r06B0, 0x01));

                           ir_expression *const r06B2 = equal(r06B0, body.constant(0u));
                           ir_expression *const r06B3 = expr(ir_unop_find_msb, r06B0);
                           ir_expression *const r06B4 = sub(body.constant(int(31)), r06B3);
                           ir_expression *const r06B5 = expr(ir_triop_csel, r06B2, body.constant(int(32)), r06B4);
                           body.emit(assign(r06AA, add(r06B5, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06B7 = gequal(r06AA, body.constant(int(0)));
                           ir_if *f06B6 = new(mem_ctx) ir_if(operand(r06B7).val);
                           exec_list *const f06B6_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06B6->then_instructions;

                              body.emit(assign(r06A9, body.constant(0u), 0x01));

                              ir_expression *const r06B8 = equal(r06AA, body.constant(int(0)));
                              ir_expression *const r06B9 = lshift(r06B0, r06AA);
                              ir_expression *const r06BA = neg(r06AA);
                              ir_expression *const r06BB = bit_and(r06BA, body.constant(int(31)));
                              ir_expression *const r06BC = rshift(r06AD, r06BB);
                              ir_expression *const r06BD = bit_or(r06B9, r06BC);
                              body.emit(assign(r06A7, expr(ir_triop_csel, r06B8, r06B0, r06BD), 0x01));

                              body.emit(assign(r06A8, lshift(r06AD, r06AA), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06B6->else_instructions;

                              ir_variable *const r06BE = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r06BE, body.constant(0u), 0x01));

                              ir_variable *const r06BF = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r06BF, neg(r06AA), 0x01));

                              ir_variable *const r06C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r06C0);
                              ir_variable *const r06C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r06C1);
                              ir_variable *const r06C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r06C2);
                              ir_variable *const r06C3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r06C4 = neg(r06BF);
                              body.emit(assign(r06C3, bit_and(r06C4, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r06C6 = equal(r06BF, body.constant(int(0)));
                              ir_if *f06C5 = new(mem_ctx) ir_if(operand(r06C6).val);
                              exec_list *const f06C5_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06C5->then_instructions;

                                 body.emit(assign(r06C0, r06BE, 0x01));

                                 body.emit(assign(r06C1, r06A8, 0x01));

                                 body.emit(assign(r06C2, r06A7, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06C5->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06C8 = less(r06BF, body.constant(int(32)));
                                 ir_if *f06C7 = new(mem_ctx) ir_if(operand(r06C8).val);
                                 exec_list *const f06C7_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06C7->then_instructions;

                                    body.emit(assign(r06C0, lshift(r06A8, r06C3), 0x01));

                                    ir_expression *const r06C9 = lshift(r06A7, r06C3);
                                    ir_expression *const r06CA = rshift(r06A8, r06BF);
                                    body.emit(assign(r06C1, bit_or(r06C9, r06CA), 0x01));

                                    body.emit(assign(r06C2, rshift(r06A7, r06BF), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06C7->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06CC = equal(r06BF, body.constant(int(32)));
                                    ir_if *f06CB = new(mem_ctx) ir_if(operand(r06CC).val);
                                    exec_list *const f06CB_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06CB->then_instructions;

                                       body.emit(assign(r06C0, r06A8, 0x01));

                                       body.emit(assign(r06C1, r06A7, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06CB->else_instructions;

                                       body.emit(assign(r06BE, bit_or(body.constant(0u), r06A8), 0x01));

                                       ir_expression *const r06CD = less(r06BF, body.constant(int(64)));
                                       ir_expression *const r06CE = lshift(r06A7, r06C3);
                                       ir_expression *const r06CF = equal(r06BF, body.constant(int(64)));
                                       ir_expression *const r06D0 = nequal(r06A7, body.constant(0u));
                                       ir_expression *const r06D1 = expr(ir_unop_b2i, r06D0);
                                       ir_expression *const r06D2 = expr(ir_unop_i2u, r06D1);
                                       ir_expression *const r06D3 = expr(ir_triop_csel, r06CF, r06A7, r06D2);
                                       body.emit(assign(r06C0, expr(ir_triop_csel, r06CD, r06CE, r06D3), 0x01));

                                       ir_expression *const r06D4 = less(r06BF, body.constant(int(64)));
                                       ir_expression *const r06D5 = bit_and(r06BF, body.constant(int(31)));
                                       ir_expression *const r06D6 = rshift(r06A7, r06D5);
                                       body.emit(assign(r06C1, expr(ir_triop_csel, r06D4, r06D6, body.constant(0u)), 0x01));


                                    body.instructions = f06CB_parent_instructions;
                                    body.emit(f06CB);

                                    /* END IF */

                                    body.emit(assign(r06C2, body.constant(0u), 0x01));


                                 body.instructions = f06C7_parent_instructions;
                                 body.emit(f06C7);

                                 /* END IF */

                                 ir_expression *const r06D7 = nequal(r06BE, body.constant(0u));
                                 ir_expression *const r06D8 = expr(ir_unop_b2i, r06D7);
                                 ir_expression *const r06D9 = expr(ir_unop_i2u, r06D8);
                                 body.emit(assign(r06C0, bit_or(r06C0, r06D9), 0x01));


                              body.instructions = f06C5_parent_instructions;
                              body.emit(f06C5);

                              /* END IF */

                              body.emit(assign(r06A7, r06C2, 0x01));

                              body.emit(assign(r06A8, r06C1, 0x01));

                              body.emit(assign(r06A9, r06C0, 0x01));


                           body.instructions = f06B6_parent_instructions;
                           body.emit(f06B6);

                           /* END IF */

                           body.emit(assign(r06A6, sub(r06A6, r06AA), 0x01));

                           ir_variable *const r06DA = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06DA, r06A6, 0x01));

                           ir_variable *const r06DB = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r06DB, r06A7, 0x01));

                           ir_variable *const r06DC = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r06DC, r06A8, 0x01));

                           ir_variable *const r06DD = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r06DD, r06A9, 0x01));

                           ir_variable *const r06DE = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r06DE, body.constant(true), 0x01));

                           ir_variable *const r06DF = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r06E0 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r06E0);
                           ir_expression *const r06E1 = expr(ir_unop_u2i, r06A9);
                           body.emit(assign(r06E0, less(r06E1, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06E3 = gequal(r06A6, body.constant(int(2045)));
                           ir_if *f06E2 = new(mem_ctx) ir_if(operand(r06E3).val);
                           exec_list *const f06E2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06E2->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06E5 = less(body.constant(int(2045)), r06A6);
                              ir_expression *const r06E6 = equal(r06A6, body.constant(int(2045)));
                              ir_expression *const r06E7 = equal(body.constant(2097151u), r06A7);
                              ir_expression *const r06E8 = equal(body.constant(4294967295u), r06A8);
                              ir_expression *const r06E9 = logic_and(r06E7, r06E8);
                              ir_expression *const r06EA = logic_and(r06E6, r06E9);
                              ir_expression *const r06EB = logic_and(r06EA, r06E0);
                              ir_expression *const r06EC = logic_or(r06E5, r06EB);
                              ir_if *f06E4 = new(mem_ctx) ir_if(operand(r06EC).val);
                              exec_list *const f06E4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06E4->then_instructions;

                                 ir_variable *const r06ED = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r06ED);
                                 ir_expression *const r06EE = lshift(r01D9, body.constant(int(31)));
                                 body.emit(assign(r06ED, add(r06EE, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r06ED, body.constant(0u), 0x01));

                                 body.emit(assign(r06DF, r06ED, 0x03));

                                 body.emit(assign(r06DE, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06E4->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06F0 = less(r06A6, body.constant(int(0)));
                                 ir_if *f06EF = new(mem_ctx) ir_if(operand(r06F0).val);
                                 exec_list *const f06EF_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06EF->then_instructions;

                                    ir_variable *const r06F1 = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r06F1, r06A9, 0x01));

                                    ir_variable *const r06F2 = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r06F2, neg(r06A6), 0x01));

                                    ir_variable *const r06F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r06F3);
                                    ir_variable *const r06F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r06F4);
                                    ir_variable *const r06F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r06F5);
                                    ir_variable *const r06F6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r06F7 = neg(r06F2);
                                    body.emit(assign(r06F6, bit_and(r06F7, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r06F9 = equal(r06F2, body.constant(int(0)));
                                    ir_if *f06F8 = new(mem_ctx) ir_if(operand(r06F9).val);
                                    exec_list *const f06F8_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06F8->then_instructions;

                                       body.emit(assign(r06F3, r06A9, 0x01));

                                       body.emit(assign(r06F4, r06A8, 0x01));

                                       body.emit(assign(r06F5, r06A7, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06F8->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r06FB = less(r06F2, body.constant(int(32)));
                                       ir_if *f06FA = new(mem_ctx) ir_if(operand(r06FB).val);
                                       exec_list *const f06FA_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06FA->then_instructions;

                                          body.emit(assign(r06F3, lshift(r06A8, r06F6), 0x01));

                                          ir_expression *const r06FC = lshift(r06A7, r06F6);
                                          ir_expression *const r06FD = rshift(r06A8, r06F2);
                                          body.emit(assign(r06F4, bit_or(r06FC, r06FD), 0x01));

                                          body.emit(assign(r06F5, rshift(r06A7, r06F2), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06FA->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r06FF = equal(r06F2, body.constant(int(32)));
                                          ir_if *f06FE = new(mem_ctx) ir_if(operand(r06FF).val);
                                          exec_list *const f06FE_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f06FE->then_instructions;

                                             body.emit(assign(r06F3, r06A8, 0x01));

                                             body.emit(assign(r06F4, r06A7, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f06FE->else_instructions;

                                             body.emit(assign(r06F1, bit_or(r06A9, r06A8), 0x01));

                                             ir_expression *const r0700 = less(r06F2, body.constant(int(64)));
                                             ir_expression *const r0701 = lshift(r06A7, r06F6);
                                             ir_expression *const r0702 = equal(r06F2, body.constant(int(64)));
                                             ir_expression *const r0703 = nequal(r06A7, body.constant(0u));
                                             ir_expression *const r0704 = expr(ir_unop_b2i, r0703);
                                             ir_expression *const r0705 = expr(ir_unop_i2u, r0704);
                                             ir_expression *const r0706 = expr(ir_triop_csel, r0702, r06A7, r0705);
                                             body.emit(assign(r06F3, expr(ir_triop_csel, r0700, r0701, r0706), 0x01));

                                             ir_expression *const r0707 = less(r06F2, body.constant(int(64)));
                                             ir_expression *const r0708 = bit_and(r06F2, body.constant(int(31)));
                                             ir_expression *const r0709 = rshift(r06A7, r0708);
                                             body.emit(assign(r06F4, expr(ir_triop_csel, r0707, r0709, body.constant(0u)), 0x01));


                                          body.instructions = f06FE_parent_instructions;
                                          body.emit(f06FE);

                                          /* END IF */

                                          body.emit(assign(r06F5, body.constant(0u), 0x01));


                                       body.instructions = f06FA_parent_instructions;
                                       body.emit(f06FA);

                                       /* END IF */

                                       ir_expression *const r070A = nequal(r06F1, body.constant(0u));
                                       ir_expression *const r070B = expr(ir_unop_b2i, r070A);
                                       ir_expression *const r070C = expr(ir_unop_i2u, r070B);
                                       body.emit(assign(r06F3, bit_or(r06F3, r070C), 0x01));


                                    body.instructions = f06F8_parent_instructions;
                                    body.emit(f06F8);

                                    /* END IF */

                                    body.emit(assign(r06DB, r06F5, 0x01));

                                    body.emit(assign(r06DC, r06F4, 0x01));

                                    body.emit(assign(r06DD, r06F3, 0x01));

                                    body.emit(assign(r06DA, body.constant(int(0)), 0x01));

                                    body.emit(assign(r06E0, less(r06F3, body.constant(0u)), 0x01));


                                 body.instructions = f06EF_parent_instructions;
                                 body.emit(f06EF);

                                 /* END IF */


                              body.instructions = f06E4_parent_instructions;
                              body.emit(f06E4);

                              /* END IF */


                           body.instructions = f06E2_parent_instructions;
                           body.emit(f06E2);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f070D = new(mem_ctx) ir_if(operand(r06DE).val);
                           exec_list *const f070D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f070D->then_instructions;

                              /* IF CONDITION */
                              ir_if *f070E = new(mem_ctx) ir_if(operand(r06E0).val);
                              exec_list *const f070E_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f070E->then_instructions;

                                 ir_variable *const r070F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r070F, add(r06DC, body.constant(1u)), 0x01));

                                 ir_expression *const r0710 = less(r070F, r06DC);
                                 ir_expression *const r0711 = expr(ir_unop_b2i, r0710);
                                 ir_expression *const r0712 = expr(ir_unop_i2u, r0711);
                                 body.emit(assign(r06DB, add(r06DB, r0712), 0x01));

                                 ir_expression *const r0713 = equal(r06DD, body.constant(0u));
                                 ir_expression *const r0714 = expr(ir_unop_b2i, r0713);
                                 ir_expression *const r0715 = expr(ir_unop_i2u, r0714);
                                 ir_expression *const r0716 = add(r06DD, r0715);
                                 ir_expression *const r0717 = bit_and(r0716, body.constant(1u));
                                 ir_expression *const r0718 = expr(ir_unop_bit_not, r0717);
                                 body.emit(assign(r06DC, bit_and(r070F, r0718), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f070E->else_instructions;

                                 ir_expression *const r0719 = bit_or(r06DB, r06DC);
                                 ir_expression *const r071A = equal(r0719, body.constant(0u));
                                 body.emit(assign(r06DA, expr(ir_triop_csel, r071A, body.constant(int(0)), r06DA), 0x01));


                              body.instructions = f070E_parent_instructions;
                              body.emit(f070E);

                              /* END IF */

                              ir_variable *const r071B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r071B);
                              ir_expression *const r071C = lshift(r01D9, body.constant(int(31)));
                              ir_expression *const r071D = expr(ir_unop_i2u, r06DA);
                              ir_expression *const r071E = lshift(r071D, body.constant(int(20)));
                              ir_expression *const r071F = add(r071C, r071E);
                              body.emit(assign(r071B, add(r071F, r06DB), 0x02));

                              body.emit(assign(r071B, r06DC, 0x01));

                              body.emit(assign(r06DF, r071B, 0x03));

                              body.emit(assign(r06DE, body.constant(false), 0x01));


                           body.instructions = f070D_parent_instructions;
                           body.emit(f070D);

                           /* END IF */

                           body.emit(assign(r01D0, r06DF, 0x03));

                           body.emit(assign(r01CF, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f069F->else_instructions;

                           ir_variable *const r0720 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0720);
                           body.emit(assign(r0720, body.constant(0u), 0x02));

                           body.emit(assign(r0720, body.constant(0u), 0x01));

                           body.emit(assign(r01D0, r0720, 0x03));

                           body.emit(assign(r01CF, body.constant(false), 0x01));


                        body.instructions = f069F_parent_instructions;
                        body.emit(f069F);

                        /* END IF */


                     body.instructions = f061E_parent_instructions;
                     body.emit(f061E);

                     /* END IF */


                  body.instructions = f059D_parent_instructions;
                  body.emit(f059D);

                  /* END IF */


               body.instructions = f051C_parent_instructions;
               body.emit(f051C);

               /* END IF */


            body.instructions = f04FE_parent_instructions;
            body.emit(f04FE);

            /* END IF */


         body.instructions = f0437_parent_instructions;
         body.emit(f0437);

         /* END IF */


      body.instructions = f0374_parent_instructions;
      body.emit(f0374);

      /* END IF */


   body.instructions = f01E7_parent_instructions;
   body.emit(f01E7);

   /* END IF */

   body.emit(ret(r01D0));

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

   ir_variable *const r0721 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0721);
   ir_variable *const r0722 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0722);
   ir_variable *const r0723 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0723);
   ir_variable *const r0724 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0724);
   ir_variable *const r0725 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0725);
   ir_variable *const r0726 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0726);
   ir_variable *const r0727 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0727);
   ir_variable *const r0728 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0728, bit_and(r0721, body.constant(65535u)), 0x01));

   ir_variable *const r0729 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0729, rshift(r0721, body.constant(int(16))), 0x01));

   ir_variable *const r072A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r072A, bit_and(r0722, body.constant(65535u)), 0x01));

   ir_variable *const r072B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r072B, rshift(r0722, body.constant(int(16))), 0x01));

   ir_variable *const r072C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r072C, mul(r0729, r072A), 0x01));

   ir_expression *const r072D = mul(r0728, r072B);
   body.emit(assign(r0726, add(r072D, r072C), 0x01));

   ir_expression *const r072E = mul(r0729, r072B);
   ir_expression *const r072F = less(r0726, r072C);
   ir_expression *const r0730 = expr(ir_unop_b2i, r072F);
   ir_expression *const r0731 = expr(ir_unop_i2u, r0730);
   ir_expression *const r0732 = lshift(r0731, body.constant(int(16)));
   ir_expression *const r0733 = rshift(r0726, body.constant(int(16)));
   ir_expression *const r0734 = add(r0732, r0733);
   body.emit(assign(r0725, add(r072E, r0734), 0x01));

   body.emit(assign(r0726, lshift(r0726, body.constant(int(16))), 0x01));

   ir_expression *const r0735 = mul(r0728, r072A);
   body.emit(assign(r0727, add(r0735, r0726), 0x01));

   ir_expression *const r0736 = less(r0727, r0726);
   ir_expression *const r0737 = expr(ir_unop_b2i, r0736);
   ir_expression *const r0738 = expr(ir_unop_i2u, r0737);
   body.emit(assign(r0725, add(r0725, r0738), 0x01));

   body.emit(assign(r0724, r0727, 0x01));

   body.emit(assign(r0723, r0725, 0x01));

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

   ir_variable *const r0739 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0739);
   ir_variable *const r073A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r073A);
   ir_variable *const r073B = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r073B);
   ir_variable *const r073C = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r073C);
   ir_variable *const r073D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r073D);
   ir_variable *const r073E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r073E);
   ir_variable *const r073F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r073F);
   ir_variable *const r0740 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0740);
   ir_variable *const r0741 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0741);
   ir_variable *const r0742 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0742);
   ir_variable *const r0743 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0743);
   ir_variable *const r0744 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0744, bit_and(r073A, body.constant(65535u)), 0x01));

   ir_variable *const r0745 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0745, rshift(r073A, body.constant(int(16))), 0x01));

   ir_variable *const r0746 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0746, bit_and(r073C, body.constant(65535u)), 0x01));

   ir_variable *const r0747 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0747, rshift(r073C, body.constant(int(16))), 0x01));

   ir_variable *const r0748 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0748, mul(r0745, r0746), 0x01));

   ir_expression *const r0749 = mul(r0744, r0747);
   body.emit(assign(r0742, add(r0749, r0748), 0x01));

   ir_expression *const r074A = mul(r0745, r0747);
   ir_expression *const r074B = less(r0742, r0748);
   ir_expression *const r074C = expr(ir_unop_b2i, r074B);
   ir_expression *const r074D = expr(ir_unop_i2u, r074C);
   ir_expression *const r074E = lshift(r074D, body.constant(int(16)));
   ir_expression *const r074F = rshift(r0742, body.constant(int(16)));
   ir_expression *const r0750 = add(r074E, r074F);
   body.emit(assign(r0741, add(r074A, r0750), 0x01));

   body.emit(assign(r0742, lshift(r0742, body.constant(int(16))), 0x01));

   ir_expression *const r0751 = mul(r0744, r0746);
   body.emit(assign(r0743, add(r0751, r0742), 0x01));

   ir_expression *const r0752 = less(r0743, r0742);
   ir_expression *const r0753 = expr(ir_unop_b2i, r0752);
   ir_expression *const r0754 = expr(ir_unop_i2u, r0753);
   body.emit(assign(r0741, add(r0741, r0754), 0x01));

   ir_variable *const r0755 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0755);
   ir_variable *const r0756 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0756);
   ir_variable *const r0757 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0757);
   ir_variable *const r0758 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0758, bit_and(r073A, body.constant(65535u)), 0x01));

   ir_variable *const r0759 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0759, rshift(r073A, body.constant(int(16))), 0x01));

   ir_variable *const r075A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r075A, bit_and(r073B, body.constant(65535u)), 0x01));

   ir_variable *const r075B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r075B, rshift(r073B, body.constant(int(16))), 0x01));

   ir_variable *const r075C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r075C, mul(r0759, r075A), 0x01));

   ir_expression *const r075D = mul(r0758, r075B);
   body.emit(assign(r0756, add(r075D, r075C), 0x01));

   ir_expression *const r075E = mul(r0759, r075B);
   ir_expression *const r075F = less(r0756, r075C);
   ir_expression *const r0760 = expr(ir_unop_b2i, r075F);
   ir_expression *const r0761 = expr(ir_unop_i2u, r0760);
   ir_expression *const r0762 = lshift(r0761, body.constant(int(16)));
   ir_expression *const r0763 = rshift(r0756, body.constant(int(16)));
   ir_expression *const r0764 = add(r0762, r0763);
   body.emit(assign(r0755, add(r075E, r0764), 0x01));

   body.emit(assign(r0756, lshift(r0756, body.constant(int(16))), 0x01));

   ir_expression *const r0765 = mul(r0758, r075A);
   body.emit(assign(r0757, add(r0765, r0756), 0x01));

   ir_expression *const r0766 = less(r0757, r0756);
   ir_expression *const r0767 = expr(ir_unop_b2i, r0766);
   ir_expression *const r0768 = expr(ir_unop_i2u, r0767);
   body.emit(assign(r0755, add(r0755, r0768), 0x01));

   ir_variable *const r0769 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0769, add(r0757, r0741), 0x01));

   ir_variable *const r076A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r076A);
   ir_variable *const r076B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r076B);
   ir_variable *const r076C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r076C);
   ir_variable *const r076D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076D, bit_and(r0739, body.constant(65535u)), 0x01));

   ir_variable *const r076E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076E, rshift(r0739, body.constant(int(16))), 0x01));

   ir_variable *const r076F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076F, bit_and(r073B, body.constant(65535u)), 0x01));

   ir_variable *const r0770 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0770, rshift(r073B, body.constant(int(16))), 0x01));

   ir_variable *const r0771 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0771, mul(r076E, r076F), 0x01));

   ir_expression *const r0772 = mul(r076D, r0770);
   body.emit(assign(r076B, add(r0772, r0771), 0x01));

   ir_expression *const r0773 = mul(r076E, r0770);
   ir_expression *const r0774 = less(r076B, r0771);
   ir_expression *const r0775 = expr(ir_unop_b2i, r0774);
   ir_expression *const r0776 = expr(ir_unop_i2u, r0775);
   ir_expression *const r0777 = lshift(r0776, body.constant(int(16)));
   ir_expression *const r0778 = rshift(r076B, body.constant(int(16)));
   ir_expression *const r0779 = add(r0777, r0778);
   body.emit(assign(r076A, add(r0773, r0779), 0x01));

   body.emit(assign(r076B, lshift(r076B, body.constant(int(16))), 0x01));

   ir_expression *const r077A = mul(r076D, r076F);
   body.emit(assign(r076C, add(r077A, r076B), 0x01));

   ir_expression *const r077B = less(r076C, r076B);
   ir_expression *const r077C = expr(ir_unop_b2i, r077B);
   ir_expression *const r077D = expr(ir_unop_i2u, r077C);
   body.emit(assign(r076A, add(r076A, r077D), 0x01));

   ir_variable *const r077E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r077F = less(r0769, r0757);
   ir_expression *const r0780 = expr(ir_unop_b2i, r077F);
   ir_expression *const r0781 = expr(ir_unop_i2u, r0780);
   ir_expression *const r0782 = add(r0755, r0781);
   body.emit(assign(r077E, add(r076C, r0782), 0x01));

   ir_variable *const r0783 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0783);
   ir_variable *const r0784 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0784);
   ir_variable *const r0785 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0785);
   ir_variable *const r0786 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0786, bit_and(r0739, body.constant(65535u)), 0x01));

   ir_variable *const r0787 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0787, rshift(r0739, body.constant(int(16))), 0x01));

   ir_variable *const r0788 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0788, bit_and(r073C, body.constant(65535u)), 0x01));

   ir_variable *const r0789 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0789, rshift(r073C, body.constant(int(16))), 0x01));

   ir_variable *const r078A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078A, mul(r0787, r0788), 0x01));

   ir_expression *const r078B = mul(r0786, r0789);
   body.emit(assign(r0784, add(r078B, r078A), 0x01));

   ir_expression *const r078C = mul(r0787, r0789);
   ir_expression *const r078D = less(r0784, r078A);
   ir_expression *const r078E = expr(ir_unop_b2i, r078D);
   ir_expression *const r078F = expr(ir_unop_i2u, r078E);
   ir_expression *const r0790 = lshift(r078F, body.constant(int(16)));
   ir_expression *const r0791 = rshift(r0784, body.constant(int(16)));
   ir_expression *const r0792 = add(r0790, r0791);
   body.emit(assign(r0783, add(r078C, r0792), 0x01));

   body.emit(assign(r0784, lshift(r0784, body.constant(int(16))), 0x01));

   ir_expression *const r0793 = mul(r0786, r0788);
   body.emit(assign(r0785, add(r0793, r0784), 0x01));

   ir_expression *const r0794 = less(r0785, r0784);
   ir_expression *const r0795 = expr(ir_unop_b2i, r0794);
   ir_expression *const r0796 = expr(ir_unop_i2u, r0795);
   body.emit(assign(r0783, add(r0783, r0796), 0x01));

   ir_variable *const r0797 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0797, add(r0785, r0769), 0x01));

   ir_variable *const r0798 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0799 = less(r0797, r0785);
   ir_expression *const r079A = expr(ir_unop_b2i, r0799);
   ir_expression *const r079B = expr(ir_unop_i2u, r079A);
   ir_expression *const r079C = add(r0783, r079B);
   body.emit(assign(r0798, add(r077E, r079C), 0x01));

   body.emit(assign(r0740, r0743, 0x01));

   body.emit(assign(r073F, r0797, 0x01));

   body.emit(assign(r073E, r0798, 0x01));

   ir_expression *const r079D = less(r077E, r076C);
   ir_expression *const r079E = expr(ir_unop_b2i, r079D);
   ir_expression *const r079F = expr(ir_unop_i2u, r079E);
   ir_expression *const r07A0 = add(r076A, r079F);
   ir_expression *const r07A1 = less(r0798, r077E);
   ir_expression *const r07A2 = expr(ir_unop_b2i, r07A1);
   ir_expression *const r07A3 = expr(ir_unop_i2u, r07A2);
   body.emit(assign(r073D, add(r07A0, r07A3), 0x01));

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

   ir_variable *const r07A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r07A4);
   ir_variable *const r07A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r07A5);
   ir_variable *const r07A6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r07A6);
   ir_variable *const r07A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07A7);
   ir_variable *const r07A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07A8);
   ir_variable *const r07A9 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r07A9);
   /* IF CONDITION */
   ir_expression *const r07AB = equal(r07A4, body.constant(0u));
   ir_if *f07AA = new(mem_ctx) ir_if(operand(r07AB).val);
   exec_list *const f07AA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07AA->then_instructions;

      ir_expression *const r07AC = equal(r07A5, body.constant(0u));
      ir_expression *const r07AD = expr(ir_unop_find_msb, r07A5);
      ir_expression *const r07AE = sub(body.constant(int(31)), r07AD);
      ir_expression *const r07AF = expr(ir_triop_csel, r07AC, body.constant(int(32)), r07AE);
      body.emit(assign(r07A9, add(r07AF, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r07B1 = less(r07A9, body.constant(int(0)));
      ir_if *f07B0 = new(mem_ctx) ir_if(operand(r07B1).val);
      exec_list *const f07B0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07B0->then_instructions;

         ir_expression *const r07B2 = neg(r07A9);
         body.emit(assign(r07A7, rshift(r07A5, r07B2), 0x01));

         ir_expression *const r07B3 = bit_and(r07A9, body.constant(int(31)));
         body.emit(assign(r07A8, lshift(r07A5, r07B3), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07B0->else_instructions;

         body.emit(assign(r07A7, lshift(r07A5, r07A9), 0x01));

         body.emit(assign(r07A8, body.constant(0u), 0x01));


      body.instructions = f07B0_parent_instructions;
      body.emit(f07B0);

      /* END IF */

      body.emit(assign(r07A6, sub(body.constant(int(-31)), r07A9), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07AA->else_instructions;

      ir_expression *const r07B4 = equal(r07A4, body.constant(0u));
      ir_expression *const r07B5 = expr(ir_unop_find_msb, r07A4);
      ir_expression *const r07B6 = sub(body.constant(int(31)), r07B5);
      ir_expression *const r07B7 = expr(ir_triop_csel, r07B4, body.constant(int(32)), r07B6);
      body.emit(assign(r07A9, add(r07B7, body.constant(int(-11))), 0x01));

      ir_expression *const r07B8 = equal(r07A9, body.constant(int(0)));
      ir_expression *const r07B9 = lshift(r07A4, r07A9);
      ir_expression *const r07BA = neg(r07A9);
      ir_expression *const r07BB = bit_and(r07BA, body.constant(int(31)));
      ir_expression *const r07BC = rshift(r07A5, r07BB);
      ir_expression *const r07BD = bit_or(r07B9, r07BC);
      body.emit(assign(r07A7, expr(ir_triop_csel, r07B8, r07A4, r07BD), 0x01));

      body.emit(assign(r07A8, lshift(r07A5, r07A9), 0x01));

      body.emit(assign(r07A6, sub(body.constant(int(1)), r07A9), 0x01));


   body.instructions = f07AA_parent_instructions;
   body.emit(f07AA);

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

   ir_variable *const r07BE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r07BE);
   ir_variable *const r07BF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r07BF);
   ir_variable *const r07C0 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r07C0, body.constant(true), 0x01));

   ir_variable *const r07C1 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r07C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r07C2);
   ir_variable *const r07C3 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r07C3);
   ir_variable *const r07C4 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r07C4);
   ir_variable *const r07C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r07C5);
   ir_variable *const r07C6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r07C6);
   ir_variable *const r07C7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r07C7);
   ir_variable *const r07C8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r07C8);
   ir_variable *const r07C9 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r07C9);
   ir_variable *const r07CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r07CA);
   ir_variable *const r07CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r07CB);
   ir_variable *const r07CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r07CC);
   body.emit(assign(r07CC, body.constant(0u), 0x01));

   body.emit(assign(r07CB, body.constant(0u), 0x01));

   body.emit(assign(r07CA, body.constant(0u), 0x01));

   ir_variable *const r07CD = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r07CD, swizzle_x(r07BE), 0x01));

   body.emit(assign(r07C8, r07CD, 0x01));

   ir_variable *const r07CE = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r07CE, bit_and(swizzle_y(r07BE), body.constant(1048575u)), 0x01));

   body.emit(assign(r07C7, r07CE, 0x01));

   ir_variable *const r07CF = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r07CF, swizzle_x(r07BF), 0x01));

   body.emit(assign(r07C6, r07CF, 0x01));

   ir_variable *const r07D0 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r07D0, bit_and(swizzle_y(r07BF), body.constant(1048575u)), 0x01));

   body.emit(assign(r07C5, r07D0, 0x01));

   ir_variable *const r07D1 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r07D2 = rshift(swizzle_y(r07BE), body.constant(int(20)));
   ir_expression *const r07D3 = bit_and(r07D2, body.constant(2047u));
   body.emit(assign(r07D1, expr(ir_unop_u2i, r07D3), 0x01));

   body.emit(assign(r07C4, r07D1, 0x01));

   ir_variable *const r07D4 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r07D5 = rshift(swizzle_y(r07BF), body.constant(int(20)));
   ir_expression *const r07D6 = bit_and(r07D5, body.constant(2047u));
   body.emit(assign(r07D4, expr(ir_unop_u2i, r07D6), 0x01));

   body.emit(assign(r07C3, r07D4, 0x01));

   ir_expression *const r07D7 = rshift(swizzle_y(r07BE), body.constant(int(31)));
   ir_expression *const r07D8 = rshift(swizzle_y(r07BF), body.constant(int(31)));
   body.emit(assign(r07C2, bit_xor(r07D7, r07D8), 0x01));

   /* IF CONDITION */
   ir_expression *const r07DA = equal(r07D1, body.constant(int(2047)));
   ir_if *f07D9 = new(mem_ctx) ir_if(operand(r07DA).val);
   exec_list *const f07D9_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07D9->then_instructions;

      /* IF CONDITION */
      ir_expression *const r07DC = bit_or(r07CE, swizzle_x(r07BE));
      ir_expression *const r07DD = nequal(r07DC, body.constant(0u));
      ir_expression *const r07DE = equal(r07D4, body.constant(int(2047)));
      ir_expression *const r07DF = bit_or(r07D0, swizzle_x(r07BF));
      ir_expression *const r07E0 = nequal(r07DF, body.constant(0u));
      ir_expression *const r07E1 = logic_and(r07DE, r07E0);
      ir_expression *const r07E2 = logic_or(r07DD, r07E1);
      ir_if *f07DB = new(mem_ctx) ir_if(operand(r07E2).val);
      exec_list *const f07DB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07DB->then_instructions;

         ir_variable *const r07E3 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r07E3, swizzle_x(r07BE), 0x01));

         ir_variable *const r07E4 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r07E4, swizzle_x(r07BF), 0x01));

         body.emit(assign(r07E3, bit_or(swizzle_y(r07BE), body.constant(524288u)), 0x02));

         body.emit(assign(r07E4, bit_or(swizzle_y(r07BF), body.constant(524288u)), 0x02));

         ir_expression *const r07E5 = lshift(swizzle_y(r07BE), body.constant(int(1)));
         ir_expression *const r07E6 = gequal(r07E5, body.constant(4292870144u));
         ir_expression *const r07E7 = nequal(swizzle_x(r07BE), body.constant(0u));
         ir_expression *const r07E8 = bit_and(swizzle_y(r07BE), body.constant(1048575u));
         ir_expression *const r07E9 = nequal(r07E8, body.constant(0u));
         ir_expression *const r07EA = logic_or(r07E7, r07E9);
         ir_expression *const r07EB = logic_and(r07E6, r07EA);
         ir_swizzle *const r07EC = swizzle(r07EB, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r07ED = lshift(swizzle_y(r07BF), body.constant(int(1)));
         ir_expression *const r07EE = gequal(r07ED, body.constant(4292870144u));
         ir_expression *const r07EF = nequal(swizzle_x(r07BF), body.constant(0u));
         ir_expression *const r07F0 = bit_and(swizzle_y(r07BF), body.constant(1048575u));
         ir_expression *const r07F1 = nequal(r07F0, body.constant(0u));
         ir_expression *const r07F2 = logic_or(r07EF, r07F1);
         ir_expression *const r07F3 = logic_and(r07EE, r07F2);
         ir_swizzle *const r07F4 = swizzle(r07F3, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r07F5 = expr(ir_triop_csel, r07F4, r07E4, r07E3);
         body.emit(assign(r07C1, expr(ir_triop_csel, r07EC, r07F5, r07E4), 0x03));

         body.emit(assign(r07C0, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07DB->else_instructions;

         /* IF CONDITION */
         ir_expression *const r07F7 = expr(ir_unop_i2u, r07D4);
         ir_expression *const r07F8 = bit_or(r07F7, r07D0);
         ir_expression *const r07F9 = bit_or(r07F8, swizzle_x(r07BF));
         ir_expression *const r07FA = equal(r07F9, body.constant(0u));
         ir_if *f07F6 = new(mem_ctx) ir_if(operand(r07FA).val);
         exec_list *const f07F6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07F6->then_instructions;

            ir_constant_data r07FB_data;
            memset(&r07FB_data, 0, sizeof(ir_constant_data));
            r07FB_data.u[0] = 4294967295;
            r07FB_data.u[1] = 4294967295;
            ir_constant *const r07FB = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r07FB_data);
            body.emit(assign(r07C1, r07FB, 0x03));

            body.emit(assign(r07C0, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f07F6->else_instructions;

            ir_variable *const r07FC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r07FC);
            ir_expression *const r07FD = lshift(r07C2, body.constant(int(31)));
            body.emit(assign(r07FC, add(r07FD, body.constant(2146435072u)), 0x02));

            body.emit(assign(r07FC, body.constant(0u), 0x01));

            body.emit(assign(r07C1, r07FC, 0x03));

            body.emit(assign(r07C0, body.constant(false), 0x01));


         body.instructions = f07F6_parent_instructions;
         body.emit(f07F6);

         /* END IF */


      body.instructions = f07DB_parent_instructions;
      body.emit(f07DB);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07D9->else_instructions;

      /* IF CONDITION */
      ir_expression *const r07FF = equal(r07D4, body.constant(int(2047)));
      ir_if *f07FE = new(mem_ctx) ir_if(operand(r07FF).val);
      exec_list *const f07FE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07FE->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0801 = bit_or(r07D0, swizzle_x(r07BF));
         ir_expression *const r0802 = nequal(r0801, body.constant(0u));
         ir_if *f0800 = new(mem_ctx) ir_if(operand(r0802).val);
         exec_list *const f0800_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0800->then_instructions;

            ir_variable *const r0803 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0803, swizzle_x(r07BE), 0x01));

            ir_variable *const r0804 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0804, swizzle_x(r07BF), 0x01));

            body.emit(assign(r0803, bit_or(swizzle_y(r07BE), body.constant(524288u)), 0x02));

            body.emit(assign(r0804, bit_or(swizzle_y(r07BF), body.constant(524288u)), 0x02));

            ir_expression *const r0805 = lshift(swizzle_y(r07BE), body.constant(int(1)));
            ir_expression *const r0806 = gequal(r0805, body.constant(4292870144u));
            ir_expression *const r0807 = nequal(swizzle_x(r07BE), body.constant(0u));
            ir_expression *const r0808 = bit_and(swizzle_y(r07BE), body.constant(1048575u));
            ir_expression *const r0809 = nequal(r0808, body.constant(0u));
            ir_expression *const r080A = logic_or(r0807, r0809);
            ir_expression *const r080B = logic_and(r0806, r080A);
            ir_swizzle *const r080C = swizzle(r080B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r080D = lshift(swizzle_y(r07BF), body.constant(int(1)));
            ir_expression *const r080E = gequal(r080D, body.constant(4292870144u));
            ir_expression *const r080F = nequal(swizzle_x(r07BF), body.constant(0u));
            ir_expression *const r0810 = bit_and(swizzle_y(r07BF), body.constant(1048575u));
            ir_expression *const r0811 = nequal(r0810, body.constant(0u));
            ir_expression *const r0812 = logic_or(r080F, r0811);
            ir_expression *const r0813 = logic_and(r080E, r0812);
            ir_swizzle *const r0814 = swizzle(r0813, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0815 = expr(ir_triop_csel, r0814, r0804, r0803);
            body.emit(assign(r07C1, expr(ir_triop_csel, r080C, r0815, r0804), 0x03));

            body.emit(assign(r07C0, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0800->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0817 = expr(ir_unop_i2u, r07D1);
            ir_expression *const r0818 = bit_or(r0817, r07CE);
            ir_expression *const r0819 = bit_or(r0818, swizzle_x(r07BE));
            ir_expression *const r081A = equal(r0819, body.constant(0u));
            ir_if *f0816 = new(mem_ctx) ir_if(operand(r081A).val);
            exec_list *const f0816_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0816->then_instructions;

               ir_constant_data r081B_data;
               memset(&r081B_data, 0, sizeof(ir_constant_data));
               r081B_data.u[0] = 4294967295;
               r081B_data.u[1] = 4294967295;
               ir_constant *const r081B = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r081B_data);
               body.emit(assign(r07C1, r081B, 0x03));

               body.emit(assign(r07C0, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0816->else_instructions;

               ir_variable *const r081C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r081C);
               ir_expression *const r081D = lshift(r07C2, body.constant(int(31)));
               body.emit(assign(r081C, add(r081D, body.constant(2146435072u)), 0x02));

               body.emit(assign(r081C, body.constant(0u), 0x01));

               body.emit(assign(r07C1, r081C, 0x03));

               body.emit(assign(r07C0, body.constant(false), 0x01));


            body.instructions = f0816_parent_instructions;
            body.emit(f0816);

            /* END IF */


         body.instructions = f0800_parent_instructions;
         body.emit(f0800);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07FE->else_instructions;

         /* IF CONDITION */
         ir_expression *const r081F = equal(r07D1, body.constant(int(0)));
         ir_if *f081E = new(mem_ctx) ir_if(operand(r081F).val);
         exec_list *const f081E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f081E->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0821 = bit_or(r07CE, swizzle_x(r07BE));
            ir_expression *const r0822 = equal(r0821, body.constant(0u));
            ir_if *f0820 = new(mem_ctx) ir_if(operand(r0822).val);
            exec_list *const f0820_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0820->then_instructions;

               ir_variable *const r0823 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0823);
               body.emit(assign(r0823, lshift(r07C2, body.constant(int(31))), 0x02));

               body.emit(assign(r0823, body.constant(0u), 0x01));

               body.emit(assign(r07C1, r0823, 0x03));

               body.emit(assign(r07C0, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0820->else_instructions;

               ir_variable *const r0824 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r0824, r07D1, 0x01));

               ir_variable *const r0825 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r0825, r07CE, 0x01));

               ir_variable *const r0826 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r0826, r07CD, 0x01));

               ir_variable *const r0827 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0827);
               /* IF CONDITION */
               ir_expression *const r0829 = equal(r07CE, body.constant(0u));
               ir_if *f0828 = new(mem_ctx) ir_if(operand(r0829).val);
               exec_list *const f0828_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0828->then_instructions;

                  ir_expression *const r082A = equal(swizzle_x(r07BE), body.constant(0u));
                  ir_expression *const r082B = expr(ir_unop_find_msb, swizzle_x(r07BE));
                  ir_expression *const r082C = sub(body.constant(int(31)), r082B);
                  ir_expression *const r082D = expr(ir_triop_csel, r082A, body.constant(int(32)), r082C);
                  body.emit(assign(r0827, add(r082D, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r082F = less(r0827, body.constant(int(0)));
                  ir_if *f082E = new(mem_ctx) ir_if(operand(r082F).val);
                  exec_list *const f082E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f082E->then_instructions;

                     ir_expression *const r0830 = neg(r0827);
                     body.emit(assign(r0825, rshift(swizzle_x(r07BE), r0830), 0x01));

                     ir_expression *const r0831 = bit_and(r0827, body.constant(int(31)));
                     body.emit(assign(r0826, lshift(swizzle_x(r07BE), r0831), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f082E->else_instructions;

                     body.emit(assign(r0825, lshift(swizzle_x(r07BE), r0827), 0x01));

                     body.emit(assign(r0826, body.constant(0u), 0x01));


                  body.instructions = f082E_parent_instructions;
                  body.emit(f082E);

                  /* END IF */

                  body.emit(assign(r0824, sub(body.constant(int(-31)), r0827), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0828->else_instructions;

                  ir_expression *const r0832 = equal(r07CE, body.constant(0u));
                  ir_expression *const r0833 = expr(ir_unop_find_msb, r07CE);
                  ir_expression *const r0834 = sub(body.constant(int(31)), r0833);
                  ir_expression *const r0835 = expr(ir_triop_csel, r0832, body.constant(int(32)), r0834);
                  body.emit(assign(r0827, add(r0835, body.constant(int(-11))), 0x01));

                  ir_expression *const r0836 = equal(r0827, body.constant(int(0)));
                  ir_expression *const r0837 = lshift(r07CE, r0827);
                  ir_expression *const r0838 = neg(r0827);
                  ir_expression *const r0839 = bit_and(r0838, body.constant(int(31)));
                  ir_expression *const r083A = rshift(swizzle_x(r07BE), r0839);
                  ir_expression *const r083B = bit_or(r0837, r083A);
                  body.emit(assign(r0825, expr(ir_triop_csel, r0836, r07CE, r083B), 0x01));

                  body.emit(assign(r0826, lshift(swizzle_x(r07BE), r0827), 0x01));

                  body.emit(assign(r0824, sub(body.constant(int(1)), r0827), 0x01));


               body.instructions = f0828_parent_instructions;
               body.emit(f0828);

               /* END IF */

               body.emit(assign(r07C4, r0824, 0x01));

               body.emit(assign(r07C7, r0825, 0x01));

               body.emit(assign(r07C8, r0826, 0x01));


            body.instructions = f0820_parent_instructions;
            body.emit(f0820);

            /* END IF */


         body.instructions = f081E_parent_instructions;
         body.emit(f081E);

         /* END IF */

         /* IF CONDITION */
         ir_if *f083C = new(mem_ctx) ir_if(operand(r07C0).val);
         exec_list *const f083C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f083C->then_instructions;

            /* IF CONDITION */
            ir_expression *const r083E = equal(r07D4, body.constant(int(0)));
            ir_if *f083D = new(mem_ctx) ir_if(operand(r083E).val);
            exec_list *const f083D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f083D->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0840 = bit_or(r07D0, swizzle_x(r07BF));
               ir_expression *const r0841 = equal(r0840, body.constant(0u));
               ir_if *f083F = new(mem_ctx) ir_if(operand(r0841).val);
               exec_list *const f083F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f083F->then_instructions;

                  ir_variable *const r0842 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0842);
                  body.emit(assign(r0842, lshift(r07C2, body.constant(int(31))), 0x02));

                  body.emit(assign(r0842, body.constant(0u), 0x01));

                  body.emit(assign(r07C1, r0842, 0x03));

                  body.emit(assign(r07C0, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f083F->else_instructions;

                  ir_variable *const r0843 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r0843, r07D4, 0x01));

                  ir_variable *const r0844 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r0844, r07D0, 0x01));

                  ir_variable *const r0845 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r0845, r07CF, 0x01));

                  ir_variable *const r0846 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0846);
                  /* IF CONDITION */
                  ir_expression *const r0848 = equal(r07D0, body.constant(0u));
                  ir_if *f0847 = new(mem_ctx) ir_if(operand(r0848).val);
                  exec_list *const f0847_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0847->then_instructions;

                     ir_expression *const r0849 = equal(swizzle_x(r07BF), body.constant(0u));
                     ir_expression *const r084A = expr(ir_unop_find_msb, swizzle_x(r07BF));
                     ir_expression *const r084B = sub(body.constant(int(31)), r084A);
                     ir_expression *const r084C = expr(ir_triop_csel, r0849, body.constant(int(32)), r084B);
                     body.emit(assign(r0846, add(r084C, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r084E = less(r0846, body.constant(int(0)));
                     ir_if *f084D = new(mem_ctx) ir_if(operand(r084E).val);
                     exec_list *const f084D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f084D->then_instructions;

                        ir_expression *const r084F = neg(r0846);
                        body.emit(assign(r0844, rshift(swizzle_x(r07BF), r084F), 0x01));

                        ir_expression *const r0850 = bit_and(r0846, body.constant(int(31)));
                        body.emit(assign(r0845, lshift(swizzle_x(r07BF), r0850), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f084D->else_instructions;

                        body.emit(assign(r0844, lshift(swizzle_x(r07BF), r0846), 0x01));

                        body.emit(assign(r0845, body.constant(0u), 0x01));


                     body.instructions = f084D_parent_instructions;
                     body.emit(f084D);

                     /* END IF */

                     body.emit(assign(r0843, sub(body.constant(int(-31)), r0846), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0847->else_instructions;

                     ir_expression *const r0851 = equal(r07D0, body.constant(0u));
                     ir_expression *const r0852 = expr(ir_unop_find_msb, r07D0);
                     ir_expression *const r0853 = sub(body.constant(int(31)), r0852);
                     ir_expression *const r0854 = expr(ir_triop_csel, r0851, body.constant(int(32)), r0853);
                     body.emit(assign(r0846, add(r0854, body.constant(int(-11))), 0x01));

                     ir_expression *const r0855 = equal(r0846, body.constant(int(0)));
                     ir_expression *const r0856 = lshift(r07D0, r0846);
                     ir_expression *const r0857 = neg(r0846);
                     ir_expression *const r0858 = bit_and(r0857, body.constant(int(31)));
                     ir_expression *const r0859 = rshift(swizzle_x(r07BF), r0858);
                     ir_expression *const r085A = bit_or(r0856, r0859);
                     body.emit(assign(r0844, expr(ir_triop_csel, r0855, r07D0, r085A), 0x01));

                     body.emit(assign(r0845, lshift(swizzle_x(r07BF), r0846), 0x01));

                     body.emit(assign(r0843, sub(body.constant(int(1)), r0846), 0x01));


                  body.instructions = f0847_parent_instructions;
                  body.emit(f0847);

                  /* END IF */

                  body.emit(assign(r07C3, r0843, 0x01));

                  body.emit(assign(r07C5, r0844, 0x01));

                  body.emit(assign(r07C6, r0845, 0x01));


               body.instructions = f083F_parent_instructions;
               body.emit(f083F);

               /* END IF */


            body.instructions = f083D_parent_instructions;
            body.emit(f083D);

            /* END IF */

            /* IF CONDITION */
            ir_if *f085B = new(mem_ctx) ir_if(operand(r07C0).val);
            exec_list *const f085B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f085B->then_instructions;

               ir_expression *const r085C = add(r07C4, r07C3);
               body.emit(assign(r07C9, add(r085C, body.constant(int(-1024))), 0x01));

               body.emit(assign(r07C7, bit_or(r07C7, body.constant(1048576u)), 0x01));

               ir_variable *const r085D = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r085E = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r085E, lshift(r07C6, body.constant(int(12))), 0x01));

               ir_expression *const r085F = lshift(r07C5, body.constant(int(12)));
               ir_expression *const r0860 = rshift(r07C6, body.constant(int(20)));
               body.emit(assign(r085D, bit_or(r085F, r0860), 0x01));

               body.emit(assign(r07C5, r085D, 0x01));

               body.emit(assign(r07C6, r085E, 0x01));

               ir_variable *const r0861 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0861);
               ir_variable *const r0862 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0862);
               ir_variable *const r0863 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0863);
               ir_variable *const r0864 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0864, bit_and(r07C8, body.constant(65535u)), 0x01));

               ir_variable *const r0865 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0865, rshift(r07C8, body.constant(int(16))), 0x01));

               ir_variable *const r0866 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0866, bit_and(r085E, body.constant(65535u)), 0x01));

               ir_variable *const r0867 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0867, rshift(r085E, body.constant(int(16))), 0x01));

               ir_variable *const r0868 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0868, mul(r0865, r0866), 0x01));

               ir_expression *const r0869 = mul(r0864, r0867);
               body.emit(assign(r0862, add(r0869, r0868), 0x01));

               ir_expression *const r086A = mul(r0865, r0867);
               ir_expression *const r086B = less(r0862, r0868);
               ir_expression *const r086C = expr(ir_unop_b2i, r086B);
               ir_expression *const r086D = expr(ir_unop_i2u, r086C);
               ir_expression *const r086E = lshift(r086D, body.constant(int(16)));
               ir_expression *const r086F = rshift(r0862, body.constant(int(16)));
               ir_expression *const r0870 = add(r086E, r086F);
               body.emit(assign(r0861, add(r086A, r0870), 0x01));

               body.emit(assign(r0862, lshift(r0862, body.constant(int(16))), 0x01));

               ir_expression *const r0871 = mul(r0864, r0866);
               body.emit(assign(r0863, add(r0871, r0862), 0x01));

               ir_expression *const r0872 = less(r0863, r0862);
               ir_expression *const r0873 = expr(ir_unop_b2i, r0872);
               ir_expression *const r0874 = expr(ir_unop_i2u, r0873);
               body.emit(assign(r0861, add(r0861, r0874), 0x01));

               ir_variable *const r0875 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0875);
               ir_variable *const r0876 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0876);
               ir_variable *const r0877 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0877);
               ir_variable *const r0878 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0878, bit_and(r07C8, body.constant(65535u)), 0x01));

               ir_variable *const r0879 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0879, rshift(r07C8, body.constant(int(16))), 0x01));

               ir_variable *const r087A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r087A, bit_and(r085D, body.constant(65535u)), 0x01));

               ir_variable *const r087B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r087B, rshift(r085D, body.constant(int(16))), 0x01));

               ir_variable *const r087C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r087C, mul(r0879, r087A), 0x01));

               ir_expression *const r087D = mul(r0878, r087B);
               body.emit(assign(r0876, add(r087D, r087C), 0x01));

               ir_expression *const r087E = mul(r0879, r087B);
               ir_expression *const r087F = less(r0876, r087C);
               ir_expression *const r0880 = expr(ir_unop_b2i, r087F);
               ir_expression *const r0881 = expr(ir_unop_i2u, r0880);
               ir_expression *const r0882 = lshift(r0881, body.constant(int(16)));
               ir_expression *const r0883 = rshift(r0876, body.constant(int(16)));
               ir_expression *const r0884 = add(r0882, r0883);
               body.emit(assign(r0875, add(r087E, r0884), 0x01));

               body.emit(assign(r0876, lshift(r0876, body.constant(int(16))), 0x01));

               ir_expression *const r0885 = mul(r0878, r087A);
               body.emit(assign(r0877, add(r0885, r0876), 0x01));

               ir_expression *const r0886 = less(r0877, r0876);
               ir_expression *const r0887 = expr(ir_unop_b2i, r0886);
               ir_expression *const r0888 = expr(ir_unop_i2u, r0887);
               body.emit(assign(r0875, add(r0875, r0888), 0x01));

               ir_variable *const r0889 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0889, add(r0877, r0861), 0x01));

               ir_variable *const r088A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r088A);
               ir_variable *const r088B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r088B);
               ir_variable *const r088C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r088C);
               ir_variable *const r088D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r088D, bit_and(r07C7, body.constant(65535u)), 0x01));

               ir_variable *const r088E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r088E, rshift(r07C7, body.constant(int(16))), 0x01));

               ir_variable *const r088F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r088F, bit_and(r085D, body.constant(65535u)), 0x01));

               ir_variable *const r0890 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0890, rshift(r085D, body.constant(int(16))), 0x01));

               ir_variable *const r0891 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0891, mul(r088E, r088F), 0x01));

               ir_expression *const r0892 = mul(r088D, r0890);
               body.emit(assign(r088B, add(r0892, r0891), 0x01));

               ir_expression *const r0893 = mul(r088E, r0890);
               ir_expression *const r0894 = less(r088B, r0891);
               ir_expression *const r0895 = expr(ir_unop_b2i, r0894);
               ir_expression *const r0896 = expr(ir_unop_i2u, r0895);
               ir_expression *const r0897 = lshift(r0896, body.constant(int(16)));
               ir_expression *const r0898 = rshift(r088B, body.constant(int(16)));
               ir_expression *const r0899 = add(r0897, r0898);
               body.emit(assign(r088A, add(r0893, r0899), 0x01));

               body.emit(assign(r088B, lshift(r088B, body.constant(int(16))), 0x01));

               ir_expression *const r089A = mul(r088D, r088F);
               body.emit(assign(r088C, add(r089A, r088B), 0x01));

               ir_expression *const r089B = less(r088C, r088B);
               ir_expression *const r089C = expr(ir_unop_b2i, r089B);
               ir_expression *const r089D = expr(ir_unop_i2u, r089C);
               body.emit(assign(r088A, add(r088A, r089D), 0x01));

               ir_variable *const r089E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r089F = less(r0889, r0877);
               ir_expression *const r08A0 = expr(ir_unop_b2i, r089F);
               ir_expression *const r08A1 = expr(ir_unop_i2u, r08A0);
               ir_expression *const r08A2 = add(r0875, r08A1);
               body.emit(assign(r089E, add(r088C, r08A2), 0x01));

               ir_variable *const r08A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r08A3);
               ir_variable *const r08A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r08A4);
               ir_variable *const r08A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r08A5);
               ir_variable *const r08A6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A6, bit_and(r07C7, body.constant(65535u)), 0x01));

               ir_variable *const r08A7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A7, rshift(r07C7, body.constant(int(16))), 0x01));

               ir_variable *const r08A8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A8, bit_and(r085E, body.constant(65535u)), 0x01));

               ir_variable *const r08A9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A9, rshift(r085E, body.constant(int(16))), 0x01));

               ir_variable *const r08AA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08AA, mul(r08A7, r08A8), 0x01));

               ir_expression *const r08AB = mul(r08A6, r08A9);
               body.emit(assign(r08A4, add(r08AB, r08AA), 0x01));

               ir_expression *const r08AC = mul(r08A7, r08A9);
               ir_expression *const r08AD = less(r08A4, r08AA);
               ir_expression *const r08AE = expr(ir_unop_b2i, r08AD);
               ir_expression *const r08AF = expr(ir_unop_i2u, r08AE);
               ir_expression *const r08B0 = lshift(r08AF, body.constant(int(16)));
               ir_expression *const r08B1 = rshift(r08A4, body.constant(int(16)));
               ir_expression *const r08B2 = add(r08B0, r08B1);
               body.emit(assign(r08A3, add(r08AC, r08B2), 0x01));

               body.emit(assign(r08A4, lshift(r08A4, body.constant(int(16))), 0x01));

               ir_expression *const r08B3 = mul(r08A6, r08A8);
               body.emit(assign(r08A5, add(r08B3, r08A4), 0x01));

               ir_expression *const r08B4 = less(r08A5, r08A4);
               ir_expression *const r08B5 = expr(ir_unop_b2i, r08B4);
               ir_expression *const r08B6 = expr(ir_unop_i2u, r08B5);
               body.emit(assign(r08A3, add(r08A3, r08B6), 0x01));

               ir_variable *const r08B7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08B7, add(r08A5, r0889), 0x01));

               ir_variable *const r08B8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r08B9 = less(r08B7, r08A5);
               ir_expression *const r08BA = expr(ir_unop_b2i, r08B9);
               ir_expression *const r08BB = expr(ir_unop_i2u, r08BA);
               ir_expression *const r08BC = add(r08A3, r08BB);
               body.emit(assign(r08B8, add(r089E, r08BC), 0x01));

               ir_variable *const r08BD = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r08BE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08BE, add(r08B8, r07C8), 0x01));

               ir_expression *const r08BF = less(r089E, r088C);
               ir_expression *const r08C0 = expr(ir_unop_b2i, r08BF);
               ir_expression *const r08C1 = expr(ir_unop_i2u, r08C0);
               ir_expression *const r08C2 = add(r088A, r08C1);
               ir_expression *const r08C3 = less(r08B8, r089E);
               ir_expression *const r08C4 = expr(ir_unop_b2i, r08C3);
               ir_expression *const r08C5 = expr(ir_unop_i2u, r08C4);
               ir_expression *const r08C6 = add(r08C2, r08C5);
               ir_expression *const r08C7 = add(r08C6, r07C7);
               ir_expression *const r08C8 = less(r08BE, r08B8);
               ir_expression *const r08C9 = expr(ir_unop_b2i, r08C8);
               ir_expression *const r08CA = expr(ir_unop_i2u, r08C9);
               body.emit(assign(r08BD, add(r08C7, r08CA), 0x01));

               body.emit(assign(r07CC, r08BD, 0x01));

               body.emit(assign(r07CB, r08BE, 0x01));

               ir_expression *const r08CB = nequal(r0863, body.constant(0u));
               ir_expression *const r08CC = expr(ir_unop_b2i, r08CB);
               ir_expression *const r08CD = expr(ir_unop_i2u, r08CC);
               body.emit(assign(r07CA, bit_or(r08B7, r08CD), 0x01));

               /* IF CONDITION */
               ir_expression *const r08CF = gequal(r08BD, body.constant(2097152u));
               ir_if *f08CE = new(mem_ctx) ir_if(operand(r08CF).val);
               exec_list *const f08CE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08CE->then_instructions;

                  ir_variable *const r08D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r08D0);
                  body.emit(assign(r08D0, lshift(r08BE, body.constant(int(31))), 0x01));

                  ir_expression *const r08D1 = nequal(r07CA, body.constant(0u));
                  ir_expression *const r08D2 = expr(ir_unop_b2i, r08D1);
                  ir_expression *const r08D3 = expr(ir_unop_i2u, r08D2);
                  body.emit(assign(r08D0, bit_or(r08D0, r08D3), 0x01));

                  body.emit(assign(r07CC, rshift(r08BD, body.constant(int(1))), 0x01));

                  ir_expression *const r08D4 = lshift(r08BD, body.constant(int(31)));
                  ir_expression *const r08D5 = rshift(r08BE, body.constant(int(1)));
                  body.emit(assign(r07CB, bit_or(r08D4, r08D5), 0x01));

                  body.emit(assign(r07CA, r08D0, 0x01));

                  body.emit(assign(r07C9, add(r07C9, body.constant(int(1))), 0x01));


               body.instructions = f08CE_parent_instructions;
               body.emit(f08CE);

               /* END IF */

               ir_variable *const r08D6 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r08D6, r07C9, 0x01));

               ir_variable *const r08D7 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r08D7, r07CC, 0x01));

               ir_variable *const r08D8 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r08D8, r07CB, 0x01));

               ir_variable *const r08D9 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r08D9, r07CA, 0x01));

               ir_variable *const r08DA = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r08DA, body.constant(true), 0x01));

               ir_variable *const r08DB = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r08DC = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r08DC);
               ir_expression *const r08DD = expr(ir_unop_u2i, r07CA);
               body.emit(assign(r08DC, less(r08DD, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r08DF = gequal(r07C9, body.constant(int(2045)));
               ir_if *f08DE = new(mem_ctx) ir_if(operand(r08DF).val);
               exec_list *const f08DE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08DE->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r08E1 = less(body.constant(int(2045)), r07C9);
                  ir_expression *const r08E2 = equal(r07C9, body.constant(int(2045)));
                  ir_expression *const r08E3 = equal(body.constant(2097151u), r07CC);
                  ir_expression *const r08E4 = equal(body.constant(4294967295u), r07CB);
                  ir_expression *const r08E5 = logic_and(r08E3, r08E4);
                  ir_expression *const r08E6 = logic_and(r08E2, r08E5);
                  ir_expression *const r08E7 = logic_and(r08E6, r08DC);
                  ir_expression *const r08E8 = logic_or(r08E1, r08E7);
                  ir_if *f08E0 = new(mem_ctx) ir_if(operand(r08E8).val);
                  exec_list *const f08E0_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08E0->then_instructions;

                     ir_variable *const r08E9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r08E9);
                     ir_expression *const r08EA = lshift(r07C2, body.constant(int(31)));
                     body.emit(assign(r08E9, add(r08EA, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r08E9, body.constant(0u), 0x01));

                     body.emit(assign(r08DB, r08E9, 0x03));

                     body.emit(assign(r08DA, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08E0->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r08EC = less(r07C9, body.constant(int(0)));
                     ir_if *f08EB = new(mem_ctx) ir_if(operand(r08EC).val);
                     exec_list *const f08EB_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08EB->then_instructions;

                        ir_variable *const r08ED = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r08ED, r07CA, 0x01));

                        ir_variable *const r08EE = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r08EE, neg(r07C9), 0x01));

                        ir_variable *const r08EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r08EF);
                        ir_variable *const r08F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r08F0);
                        ir_variable *const r08F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r08F1);
                        ir_variable *const r08F2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r08F3 = neg(r08EE);
                        body.emit(assign(r08F2, bit_and(r08F3, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08F5 = equal(r08EE, body.constant(int(0)));
                        ir_if *f08F4 = new(mem_ctx) ir_if(operand(r08F5).val);
                        exec_list *const f08F4_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08F4->then_instructions;

                           body.emit(assign(r08EF, r07CA, 0x01));

                           body.emit(assign(r08F0, r07CB, 0x01));

                           body.emit(assign(r08F1, r07CC, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f08F4->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r08F7 = less(r08EE, body.constant(int(32)));
                           ir_if *f08F6 = new(mem_ctx) ir_if(operand(r08F7).val);
                           exec_list *const f08F6_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f08F6->then_instructions;

                              body.emit(assign(r08EF, lshift(r07CB, r08F2), 0x01));

                              ir_expression *const r08F8 = lshift(r07CC, r08F2);
                              ir_expression *const r08F9 = rshift(r07CB, r08EE);
                              body.emit(assign(r08F0, bit_or(r08F8, r08F9), 0x01));

                              body.emit(assign(r08F1, rshift(r07CC, r08EE), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f08F6->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r08FB = equal(r08EE, body.constant(int(32)));
                              ir_if *f08FA = new(mem_ctx) ir_if(operand(r08FB).val);
                              exec_list *const f08FA_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f08FA->then_instructions;

                                 body.emit(assign(r08EF, r07CB, 0x01));

                                 body.emit(assign(r08F0, r07CC, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f08FA->else_instructions;

                                 body.emit(assign(r08ED, bit_or(r07CA, r07CB), 0x01));

                                 ir_expression *const r08FC = less(r08EE, body.constant(int(64)));
                                 ir_expression *const r08FD = lshift(r07CC, r08F2);
                                 ir_expression *const r08FE = equal(r08EE, body.constant(int(64)));
                                 ir_expression *const r08FF = nequal(r07CC, body.constant(0u));
                                 ir_expression *const r0900 = expr(ir_unop_b2i, r08FF);
                                 ir_expression *const r0901 = expr(ir_unop_i2u, r0900);
                                 ir_expression *const r0902 = expr(ir_triop_csel, r08FE, r07CC, r0901);
                                 body.emit(assign(r08EF, expr(ir_triop_csel, r08FC, r08FD, r0902), 0x01));

                                 ir_expression *const r0903 = less(r08EE, body.constant(int(64)));
                                 ir_expression *const r0904 = bit_and(r08EE, body.constant(int(31)));
                                 ir_expression *const r0905 = rshift(r07CC, r0904);
                                 body.emit(assign(r08F0, expr(ir_triop_csel, r0903, r0905, body.constant(0u)), 0x01));


                              body.instructions = f08FA_parent_instructions;
                              body.emit(f08FA);

                              /* END IF */

                              body.emit(assign(r08F1, body.constant(0u), 0x01));


                           body.instructions = f08F6_parent_instructions;
                           body.emit(f08F6);

                           /* END IF */

                           ir_expression *const r0906 = nequal(r08ED, body.constant(0u));
                           ir_expression *const r0907 = expr(ir_unop_b2i, r0906);
                           ir_expression *const r0908 = expr(ir_unop_i2u, r0907);
                           body.emit(assign(r08EF, bit_or(r08EF, r0908), 0x01));


                        body.instructions = f08F4_parent_instructions;
                        body.emit(f08F4);

                        /* END IF */

                        body.emit(assign(r08D7, r08F1, 0x01));

                        body.emit(assign(r08D8, r08F0, 0x01));

                        body.emit(assign(r08D9, r08EF, 0x01));

                        body.emit(assign(r08D6, body.constant(int(0)), 0x01));

                        body.emit(assign(r08DC, less(r08EF, body.constant(0u)), 0x01));


                     body.instructions = f08EB_parent_instructions;
                     body.emit(f08EB);

                     /* END IF */


                  body.instructions = f08E0_parent_instructions;
                  body.emit(f08E0);

                  /* END IF */


               body.instructions = f08DE_parent_instructions;
               body.emit(f08DE);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0909 = new(mem_ctx) ir_if(operand(r08DA).val);
               exec_list *const f0909_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0909->then_instructions;

                  /* IF CONDITION */
                  ir_if *f090A = new(mem_ctx) ir_if(operand(r08DC).val);
                  exec_list *const f090A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f090A->then_instructions;

                     ir_variable *const r090B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r090B, add(r08D8, body.constant(1u)), 0x01));

                     ir_expression *const r090C = less(r090B, r08D8);
                     ir_expression *const r090D = expr(ir_unop_b2i, r090C);
                     ir_expression *const r090E = expr(ir_unop_i2u, r090D);
                     body.emit(assign(r08D7, add(r08D7, r090E), 0x01));

                     ir_expression *const r090F = equal(r08D9, body.constant(0u));
                     ir_expression *const r0910 = expr(ir_unop_b2i, r090F);
                     ir_expression *const r0911 = expr(ir_unop_i2u, r0910);
                     ir_expression *const r0912 = add(r08D9, r0911);
                     ir_expression *const r0913 = bit_and(r0912, body.constant(1u));
                     ir_expression *const r0914 = expr(ir_unop_bit_not, r0913);
                     body.emit(assign(r08D8, bit_and(r090B, r0914), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f090A->else_instructions;

                     ir_expression *const r0915 = bit_or(r08D7, r08D8);
                     ir_expression *const r0916 = equal(r0915, body.constant(0u));
                     body.emit(assign(r08D6, expr(ir_triop_csel, r0916, body.constant(int(0)), r08D6), 0x01));


                  body.instructions = f090A_parent_instructions;
                  body.emit(f090A);

                  /* END IF */

                  ir_variable *const r0917 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0917);
                  ir_expression *const r0918 = lshift(r07C2, body.constant(int(31)));
                  ir_expression *const r0919 = expr(ir_unop_i2u, r08D6);
                  ir_expression *const r091A = lshift(r0919, body.constant(int(20)));
                  ir_expression *const r091B = add(r0918, r091A);
                  body.emit(assign(r0917, add(r091B, r08D7), 0x02));

                  body.emit(assign(r0917, r08D8, 0x01));

                  body.emit(assign(r08DB, r0917, 0x03));

                  body.emit(assign(r08DA, body.constant(false), 0x01));


               body.instructions = f0909_parent_instructions;
               body.emit(f0909);

               /* END IF */

               body.emit(assign(r07C1, r08DB, 0x03));

               body.emit(assign(r07C0, body.constant(false), 0x01));


            body.instructions = f085B_parent_instructions;
            body.emit(f085B);

            /* END IF */


         body.instructions = f083C_parent_instructions;
         body.emit(f083C);

         /* END IF */


      body.instructions = f07FE_parent_instructions;
      body.emit(f07FE);

      /* END IF */


   body.instructions = f07D9_parent_instructions;
   body.emit(f07D9);

   /* END IF */

   body.emit(ret(r07C1));

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

   ir_variable *const r091C = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r091C);
   ir_variable *const r091D = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r091D);
   ir_variable *const r091E = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r091E);
   ir_variable *const r091F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r091F);
   ir_variable *const r0920 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0920);
   ir_expression *const r0921 = equal(r091E, body.constant(int(0)));
   ir_expression *const r0922 = less(r091E, body.constant(int(32)));
   ir_expression *const r0923 = neg(r091E);
   ir_expression *const r0924 = bit_and(r0923, body.constant(int(31)));
   ir_expression *const r0925 = lshift(r091C, r0924);
   ir_expression *const r0926 = rshift(r091D, r091E);
   ir_expression *const r0927 = bit_or(r0925, r0926);
   ir_expression *const r0928 = less(r091E, body.constant(int(64)));
   ir_expression *const r0929 = bit_and(r091E, body.constant(int(31)));
   ir_expression *const r092A = rshift(r091C, r0929);
   ir_expression *const r092B = expr(ir_triop_csel, r0928, r092A, body.constant(0u));
   ir_expression *const r092C = expr(ir_triop_csel, r0922, r0927, r092B);
   body.emit(assign(r0920, expr(ir_triop_csel, r0921, r091C, r092C), 0x01));

   ir_expression *const r092D = equal(r091E, body.constant(int(0)));
   ir_expression *const r092E = less(r091E, body.constant(int(32)));
   ir_expression *const r092F = rshift(r091C, r091E);
   ir_expression *const r0930 = expr(ir_triop_csel, r092E, r092F, body.constant(0u));
   body.emit(assign(r091F, expr(ir_triop_csel, r092D, r091C, r0930), 0x01));

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

   ir_variable *const r0931 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0931);
   ir_variable *const r0932 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0933 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0933);
   ir_variable *const r0934 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0934);
   body.emit(assign(r0934, swizzle_x(r0931), 0x01));

   ir_variable *const r0935 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0935, bit_and(swizzle_y(r0931), body.constant(1048575u)), 0x01));

   body.emit(assign(r0933, r0935, 0x01));

   ir_variable *const r0936 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0937 = rshift(swizzle_y(r0931), body.constant(int(20)));
   ir_expression *const r0938 = bit_and(r0937, body.constant(2047u));
   body.emit(assign(r0936, expr(ir_unop_u2i, r0938), 0x01));

   ir_variable *const r0939 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0939, rshift(swizzle_y(r0931), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r093B = nequal(r0939, body.constant(0u));
   ir_if *f093A = new(mem_ctx) ir_if(operand(r093B).val);
   exec_list *const f093A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f093A->then_instructions;

      body.emit(assign(r0932, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f093A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r093D = equal(r0936, body.constant(int(2047)));
      ir_expression *const r093E = bit_or(r0935, swizzle_x(r0931));
      ir_expression *const r093F = nequal(r093E, body.constant(0u));
      ir_expression *const r0940 = logic_and(r093D, r093F);
      ir_if *f093C = new(mem_ctx) ir_if(operand(r0940).val);
      exec_list *const f093C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f093C->then_instructions;

         body.emit(assign(r0932, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f093C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0942 = nequal(r0936, body.constant(int(0)));
         ir_if *f0941 = new(mem_ctx) ir_if(operand(r0942).val);
         exec_list *const f0941_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0941->then_instructions;

            body.emit(assign(r0933, bit_or(r0935, body.constant(1048576u)), 0x01));


         body.instructions = f0941_parent_instructions;
         body.emit(f0941);

         /* END IF */

         ir_variable *const r0943 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0943, sub(body.constant(int(1063)), r0936), 0x01));

         /* IF CONDITION */
         ir_expression *const r0945 = less(body.constant(int(0)), r0943);
         ir_if *f0944 = new(mem_ctx) ir_if(operand(r0945).val);
         exec_list *const f0944_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0944->then_instructions;

            ir_variable *const r0946 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0946);
            ir_variable *const r0947 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0948 = neg(r0943);
            body.emit(assign(r0947, bit_and(r0948, body.constant(int(31))), 0x01));

            ir_expression *const r0949 = bit_or(r0933, swizzle_x(r0931));
            ir_expression *const r094A = nequal(r0949, body.constant(0u));
            ir_expression *const r094B = expr(ir_unop_b2i, r094A);
            body.emit(assign(r0946, expr(ir_unop_i2u, r094B), 0x01));

            ir_variable *const r094C = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r094D = equal(r0943, body.constant(int(0)));
            ir_expression *const r094E = less(r0943, body.constant(int(32)));
            ir_expression *const r094F = lshift(r0933, r0947);
            ir_expression *const r0950 = rshift(swizzle_x(r0931), r0943);
            ir_expression *const r0951 = bit_or(r094F, r0950);
            ir_expression *const r0952 = lshift(swizzle_x(r0931), r0947);
            ir_expression *const r0953 = nequal(r0952, body.constant(0u));
            ir_expression *const r0954 = expr(ir_unop_b2i, r0953);
            ir_expression *const r0955 = expr(ir_unop_i2u, r0954);
            ir_expression *const r0956 = bit_or(r0951, r0955);
            ir_expression *const r0957 = equal(r0943, body.constant(int(32)));
            ir_expression *const r0958 = nequal(swizzle_x(r0931), body.constant(0u));
            ir_expression *const r0959 = expr(ir_unop_b2i, r0958);
            ir_expression *const r095A = expr(ir_unop_i2u, r0959);
            ir_expression *const r095B = bit_or(r0933, r095A);
            ir_expression *const r095C = less(r0943, body.constant(int(64)));
            ir_expression *const r095D = bit_and(r0943, body.constant(int(31)));
            ir_expression *const r095E = rshift(r0933, r095D);
            ir_expression *const r095F = lshift(r0933, r0947);
            ir_expression *const r0960 = bit_or(r095F, swizzle_x(r0931));
            ir_expression *const r0961 = nequal(r0960, body.constant(0u));
            ir_expression *const r0962 = expr(ir_unop_b2i, r0961);
            ir_expression *const r0963 = expr(ir_unop_i2u, r0962);
            ir_expression *const r0964 = bit_or(r095E, r0963);
            ir_expression *const r0965 = expr(ir_triop_csel, r095C, r0964, r0946);
            ir_expression *const r0966 = expr(ir_triop_csel, r0957, r095B, r0965);
            ir_expression *const r0967 = expr(ir_triop_csel, r094E, r0956, r0966);
            body.emit(assign(r094C, expr(ir_triop_csel, r094D, swizzle_x(r0931), r0967), 0x01));

            body.emit(assign(r0946, r094C, 0x01));

            ir_expression *const r0968 = less(r0943, body.constant(int(32)));
            ir_expression *const r0969 = rshift(r0933, r0943);
            ir_expression *const r096A = equal(r0943, body.constant(int(0)));
            ir_expression *const r096B = expr(ir_triop_csel, r096A, r0933, body.constant(0u));
            body.emit(assign(r0933, expr(ir_triop_csel, r0968, r0969, r096B), 0x01));

            body.emit(assign(r0934, r094C, 0x01));


         body.instructions = f0944_parent_instructions;
         body.emit(f0944);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r096D = bit_and(r0933, body.constant(4294963200u));
         ir_expression *const r096E = nequal(r096D, body.constant(0u));
         ir_if *f096C = new(mem_ctx) ir_if(operand(r096E).val);
         exec_list *const f096C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f096C->then_instructions;

            ir_variable *const r096F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0971 = nequal(r0939, body.constant(0u));
            ir_if *f0970 = new(mem_ctx) ir_if(operand(r0971).val);
            exec_list *const f0970_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0970->then_instructions;

               body.emit(assign(r096F, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0970->else_instructions;

               body.emit(assign(r096F, body.constant(4294967295u), 0x01));


            body.instructions = f0970_parent_instructions;
            body.emit(f0970);

            /* END IF */

            body.emit(assign(r0932, r096F, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f096C->else_instructions;

            ir_variable *const r0972 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r0973 = lshift(r0933, body.constant(int(20)));
            ir_expression *const r0974 = rshift(r0934, body.constant(int(12)));
            body.emit(assign(r0972, bit_or(r0973, r0974), 0x01));

            /* IF CONDITION */
            ir_expression *const r0976 = nequal(r0939, body.constant(0u));
            ir_expression *const r0977 = nequal(r0972, body.constant(0u));
            ir_expression *const r0978 = logic_and(r0976, r0977);
            ir_if *f0975 = new(mem_ctx) ir_if(operand(r0978).val);
            exec_list *const f0975_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0975->then_instructions;

               ir_variable *const r0979 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r097B = nequal(r0939, body.constant(0u));
               ir_if *f097A = new(mem_ctx) ir_if(operand(r097B).val);
               exec_list *const f097A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f097A->then_instructions;

                  body.emit(assign(r0979, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f097A->else_instructions;

                  body.emit(assign(r0979, body.constant(4294967295u), 0x01));


               body.instructions = f097A_parent_instructions;
               body.emit(f097A);

               /* END IF */

               body.emit(assign(r0932, r0979, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0975->else_instructions;

               body.emit(assign(r0932, r0972, 0x01));


            body.instructions = f0975_parent_instructions;
            body.emit(f0975);

            /* END IF */


         body.instructions = f096C_parent_instructions;
         body.emit(f096C);

         /* END IF */


      body.instructions = f093C_parent_instructions;
      body.emit(f093C);

      /* END IF */


   body.instructions = f093A_parent_instructions;
   body.emit(f093A);

   /* END IF */

   body.emit(ret(r0932));

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

   ir_variable *const r097C = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r097C);
   ir_variable *const r097D = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r097E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r097E);
   ir_variable *const r097F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r097F);
   /* IF CONDITION */
   ir_expression *const r0981 = equal(r097C, body.constant(0u));
   ir_if *f0980 = new(mem_ctx) ir_if(operand(r0981).val);
   exec_list *const f0980_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0980->then_instructions;

      body.emit(assign(r097D, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0980->else_instructions;

      ir_variable *const r0982 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0983 = equal(r097C, body.constant(0u));
      ir_expression *const r0984 = expr(ir_unop_find_msb, r097C);
      ir_expression *const r0985 = sub(body.constant(int(31)), r0984);
      ir_expression *const r0986 = expr(ir_triop_csel, r0983, body.constant(int(32)), r0985);
      body.emit(assign(r0982, add(r0986, body.constant(int(21))), 0x01));

      body.emit(assign(r097F, body.constant(0u), 0x01));

      body.emit(assign(r097E, body.constant(0u), 0x01));

      ir_variable *const r0987 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0988 = neg(r0982);
      body.emit(assign(r0987, bit_and(r0988, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r098A = equal(r0982, body.constant(int(0)));
      ir_if *f0989 = new(mem_ctx) ir_if(operand(r098A).val);
      exec_list *const f0989_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0989->then_instructions;

         body.emit(assign(r097F, body.constant(0u), 0x01));

         body.emit(assign(r097E, r097C, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0989->else_instructions;

         /* IF CONDITION */
         ir_expression *const r098C = less(r0982, body.constant(int(32)));
         ir_if *f098B = new(mem_ctx) ir_if(operand(r098C).val);
         exec_list *const f098B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f098B->then_instructions;

            body.emit(assign(r097F, rshift(r097C, r0987), 0x01));

            body.emit(assign(r097E, lshift(r097C, r0982), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f098B->else_instructions;

            ir_variable *const r098D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r098F = less(r0982, body.constant(int(64)));
            ir_if *f098E = new(mem_ctx) ir_if(operand(r098F).val);
            exec_list *const f098E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f098E->then_instructions;

               ir_expression *const r0990 = add(r0982, body.constant(int(-32)));
               body.emit(assign(r098D, lshift(r097C, r0990), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f098E->else_instructions;

               body.emit(assign(r098D, body.constant(0u), 0x01));


            body.instructions = f098E_parent_instructions;
            body.emit(f098E);

            /* END IF */

            body.emit(assign(r097F, r098D, 0x01));

            body.emit(assign(r097E, body.constant(0u), 0x01));


         body.instructions = f098B_parent_instructions;
         body.emit(f098B);

         /* END IF */


      body.instructions = f0989_parent_instructions;
      body.emit(f0989);

      /* END IF */

      ir_variable *const r0991 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0991);
      ir_expression *const r0992 = sub(body.constant(int(1074)), r0982);
      ir_expression *const r0993 = expr(ir_unop_i2u, r0992);
      ir_expression *const r0994 = lshift(r0993, body.constant(int(20)));
      body.emit(assign(r0991, add(r0994, r097F), 0x02));

      body.emit(assign(r0991, r097E, 0x01));

      body.emit(assign(r097D, r0991, 0x03));


   body.instructions = f0980_parent_instructions;
   body.emit(f0980);

   /* END IF */

   body.emit(ret(r097D));

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

   ir_variable *const r0995 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0995);
   ir_variable *const r0996 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0996, body.constant(true), 0x01));

   ir_variable *const r0997 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0998 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0998);
   ir_variable *const r0999 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0999);
   ir_variable *const r099A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r099A);
   ir_variable *const r099B = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r099B, bit_and(swizzle_y(r0995), body.constant(1048575u)), 0x01));

   body.emit(assign(r099A, r099B, 0x01));

   ir_variable *const r099C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r099D = rshift(swizzle_y(r0995), body.constant(int(20)));
   ir_expression *const r099E = bit_and(r099D, body.constant(2047u));
   body.emit(assign(r099C, expr(ir_unop_u2i, r099E), 0x01));

   body.emit(assign(r0999, rshift(swizzle_y(r0995), body.constant(int(31))), 0x01));

   body.emit(assign(r0998, body.constant(0u), 0x01));

   ir_variable *const r099F = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r099F, add(r099C, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r09A1 = gequal(r099F, body.constant(int(0)));
   ir_if *f09A0 = new(mem_ctx) ir_if(operand(r09A1).val);
   exec_list *const f09A0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09A0->then_instructions;

      /* IF CONDITION */
      ir_expression *const r09A3 = less(body.constant(int(1054)), r099C);
      ir_if *f09A2 = new(mem_ctx) ir_if(operand(r09A3).val);
      exec_list *const f09A2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09A2->then_instructions;

         /* IF CONDITION */
         ir_expression *const r09A5 = equal(r099C, body.constant(int(2047)));
         ir_expression *const r09A6 = bit_or(r099B, swizzle_x(r0995));
         ir_expression *const r09A7 = expr(ir_unop_u2i, r09A6);
         ir_expression *const r09A8 = expr(ir_unop_i2b, r09A7);
         ir_expression *const r09A9 = logic_and(r09A5, r09A8);
         ir_if *f09A4 = new(mem_ctx) ir_if(operand(r09A9).val);
         exec_list *const f09A4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09A4->then_instructions;

            body.emit(assign(r0999, body.constant(0u), 0x01));


         body.instructions = f09A4_parent_instructions;
         body.emit(f09A4);

         /* END IF */

         ir_variable *const r09AA = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09AC = expr(ir_unop_u2i, r0999);
         ir_expression *const r09AD = expr(ir_unop_i2b, r09AC);
         ir_if *f09AB = new(mem_ctx) ir_if(operand(r09AD).val);
         exec_list *const f09AB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09AB->then_instructions;

            body.emit(assign(r09AA, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09AB->else_instructions;

            body.emit(assign(r09AA, body.constant(int(2147483647)), 0x01));


         body.instructions = f09AB_parent_instructions;
         body.emit(f09AB);

         /* END IF */

         body.emit(assign(r0997, r09AA, 0x01));

         body.emit(assign(r0996, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09A2->else_instructions;

         ir_variable *const r09AE = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r09AE, bit_or(r099B, body.constant(1048576u)), 0x01));

         ir_expression *const r09AF = equal(r099F, body.constant(int(0)));
         ir_expression *const r09B0 = lshift(r09AE, r099F);
         ir_expression *const r09B1 = neg(r099F);
         ir_expression *const r09B2 = bit_and(r09B1, body.constant(int(31)));
         ir_expression *const r09B3 = rshift(swizzle_x(r0995), r09B2);
         ir_expression *const r09B4 = bit_or(r09B0, r09B3);
         body.emit(assign(r0998, expr(ir_triop_csel, r09AF, r09AE, r09B4), 0x01));


      body.instructions = f09A2_parent_instructions;
      body.emit(f09A2);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09A0->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09B6 = less(r099C, body.constant(int(1023)));
      ir_if *f09B5 = new(mem_ctx) ir_if(operand(r09B6).val);
      exec_list *const f09B5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09B5->then_instructions;

         body.emit(assign(r0997, body.constant(int(0)), 0x01));

         body.emit(assign(r0996, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09B5->else_instructions;

         body.emit(assign(r099A, bit_or(r099B, body.constant(1048576u)), 0x01));

         ir_expression *const r09B7 = neg(r099F);
         body.emit(assign(r0998, rshift(r099A, r09B7), 0x01));


      body.instructions = f09B5_parent_instructions;
      body.emit(f09B5);

      /* END IF */


   body.instructions = f09A0_parent_instructions;
   body.emit(f09A0);

   /* END IF */

   /* IF CONDITION */
   ir_if *f09B8 = new(mem_ctx) ir_if(operand(r0996).val);
   exec_list *const f09B8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09B8->then_instructions;

      ir_variable *const r09B9 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09BB = nequal(r0999, body.constant(0u));
      ir_if *f09BA = new(mem_ctx) ir_if(operand(r09BB).val);
      exec_list *const f09BA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09BA->then_instructions;

         ir_expression *const r09BC = expr(ir_unop_u2i, r0998);
         body.emit(assign(r09B9, neg(r09BC), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09BA->else_instructions;

         body.emit(assign(r09B9, expr(ir_unop_u2i, r0998), 0x01));


      body.instructions = f09BA_parent_instructions;
      body.emit(f09BA);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r09BE = less(r09B9, body.constant(int(0)));
      ir_expression *const r09BF = expr(ir_unop_b2i, r09BE);
      ir_expression *const r09C0 = expr(ir_unop_i2u, r09BF);
      ir_expression *const r09C1 = bit_xor(r0999, r09C0);
      ir_expression *const r09C2 = expr(ir_unop_u2i, r09C1);
      ir_expression *const r09C3 = expr(ir_unop_i2b, r09C2);
      ir_expression *const r09C4 = expr(ir_unop_i2b, r09B9);
      ir_expression *const r09C5 = logic_and(r09C3, r09C4);
      ir_if *f09BD = new(mem_ctx) ir_if(operand(r09C5).val);
      exec_list *const f09BD_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09BD->then_instructions;

         ir_variable *const r09C6 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09C8 = expr(ir_unop_u2i, r0999);
         ir_expression *const r09C9 = expr(ir_unop_i2b, r09C8);
         ir_if *f09C7 = new(mem_ctx) ir_if(operand(r09C9).val);
         exec_list *const f09C7_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09C7->then_instructions;

            body.emit(assign(r09C6, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09C7->else_instructions;

            body.emit(assign(r09C6, body.constant(int(2147483647)), 0x01));


         body.instructions = f09C7_parent_instructions;
         body.emit(f09C7);

         /* END IF */

         body.emit(assign(r0997, r09C6, 0x01));

         body.emit(assign(r0996, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09BD->else_instructions;

         body.emit(assign(r0997, r09B9, 0x01));

         body.emit(assign(r0996, body.constant(false), 0x01));


      body.instructions = f09BD_parent_instructions;
      body.emit(f09BD);

      /* END IF */


   body.instructions = f09B8_parent_instructions;
   body.emit(f09B8);

   /* END IF */

   body.emit(ret(r0997));

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

   ir_variable *const r09CA = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r09CA);
   ir_variable *const r09CB = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r09CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r09CC);
   ir_variable *const r09CD = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r09CD);
   ir_variable *const r09CE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r09CE);
   body.emit(assign(r09CE, body.constant(0u), 0x01));

   body.emit(assign(r09CD, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r09D0 = equal(r09CA, body.constant(int(0)));
   ir_if *f09CF = new(mem_ctx) ir_if(operand(r09D0).val);
   exec_list *const f09CF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09CF->then_instructions;

      ir_variable *const r09D1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r09D1);
      body.emit(assign(r09D1, body.constant(0u), 0x02));

      body.emit(assign(r09D1, body.constant(0u), 0x01));

      body.emit(assign(r09CB, r09D1, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09CF->else_instructions;

      ir_expression *const r09D2 = less(r09CA, body.constant(int(0)));
      ir_expression *const r09D3 = expr(ir_unop_b2i, r09D2);
      body.emit(assign(r09CC, expr(ir_unop_i2u, r09D3), 0x01));

      ir_variable *const r09D4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09D6 = less(r09CA, body.constant(int(0)));
      ir_if *f09D5 = new(mem_ctx) ir_if(operand(r09D6).val);
      exec_list *const f09D5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09D5->then_instructions;

         ir_expression *const r09D7 = neg(r09CA);
         body.emit(assign(r09D4, expr(ir_unop_i2u, r09D7), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09D5->else_instructions;

         body.emit(assign(r09D4, expr(ir_unop_i2u, r09CA), 0x01));


      body.instructions = f09D5_parent_instructions;
      body.emit(f09D5);

      /* END IF */

      ir_variable *const r09D8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r09D9 = equal(r09D4, body.constant(0u));
      ir_expression *const r09DA = expr(ir_unop_find_msb, r09D4);
      ir_expression *const r09DB = sub(body.constant(int(31)), r09DA);
      ir_expression *const r09DC = expr(ir_triop_csel, r09D9, body.constant(int(32)), r09DB);
      body.emit(assign(r09D8, add(r09DC, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r09DE = gequal(r09D8, body.constant(int(0)));
      ir_if *f09DD = new(mem_ctx) ir_if(operand(r09DE).val);
      exec_list *const f09DD_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09DD->then_instructions;

         body.emit(assign(r09CE, lshift(r09D4, r09D8), 0x01));

         body.emit(assign(r09CD, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09DD->else_instructions;

         ir_variable *const r09DF = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r09DF, neg(r09D8), 0x01));

         ir_expression *const r09E0 = equal(r09DF, body.constant(int(0)));
         ir_expression *const r09E1 = less(r09DF, body.constant(int(32)));
         ir_expression *const r09E2 = rshift(r09D4, r09DF);
         ir_expression *const r09E3 = expr(ir_triop_csel, r09E1, r09E2, body.constant(0u));
         body.emit(assign(r09CE, expr(ir_triop_csel, r09E0, r09D4, r09E3), 0x01));

         ir_expression *const r09E4 = equal(r09DF, body.constant(int(0)));
         ir_expression *const r09E5 = less(r09DF, body.constant(int(32)));
         ir_expression *const r09E6 = neg(r09DF);
         ir_expression *const r09E7 = bit_and(r09E6, body.constant(int(31)));
         ir_expression *const r09E8 = lshift(r09D4, r09E7);
         ir_expression *const r09E9 = bit_or(r09E8, body.constant(0u));
         ir_expression *const r09EA = less(r09DF, body.constant(int(64)));
         ir_expression *const r09EB = bit_and(r09DF, body.constant(int(31)));
         ir_expression *const r09EC = rshift(r09D4, r09EB);
         ir_expression *const r09ED = expr(ir_triop_csel, r09EA, r09EC, body.constant(0u));
         ir_expression *const r09EE = expr(ir_triop_csel, r09E5, r09E9, r09ED);
         body.emit(assign(r09CD, expr(ir_triop_csel, r09E4, r09D4, r09EE), 0x01));


      body.instructions = f09DD_parent_instructions;
      body.emit(f09DD);

      /* END IF */

      ir_variable *const r09EF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r09EF);
      ir_expression *const r09F0 = lshift(r09CC, body.constant(int(31)));
      ir_expression *const r09F1 = sub(body.constant(int(1042)), r09D8);
      ir_expression *const r09F2 = expr(ir_unop_i2u, r09F1);
      ir_expression *const r09F3 = lshift(r09F2, body.constant(int(20)));
      ir_expression *const r09F4 = add(r09F0, r09F3);
      body.emit(assign(r09EF, add(r09F4, r09CE), 0x02));

      body.emit(assign(r09EF, r09CD, 0x01));

      body.emit(assign(r09CB, r09EF, 0x03));


   body.instructions = f09CF_parent_instructions;
   body.emit(f09CF);

   /* END IF */

   body.emit(ret(r09CB));

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

   ir_variable *const r09F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r09F5);
   ir_variable *const r09F6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r09F6);
   ir_variable *const r09F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r09F7);
   ir_variable *const r09F8 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r09F9 = lshift(r09F5, body.constant(int(31)));
   ir_expression *const r09FA = expr(ir_unop_i2u, r09F6);
   ir_expression *const r09FB = lshift(r09FA, body.constant(int(23)));
   ir_expression *const r09FC = add(r09F9, r09FB);
   ir_expression *const r09FD = add(r09FC, r09F7);
   body.emit(assign(r09F8, expr(ir_unop_bitcast_u2f, r09FD), 0x01));

   body.emit(ret(r09F8));

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

   ir_variable *const r09FE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r09FE);
   ir_variable *const r09FF = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r09FF);
   ir_variable *const r0A00 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0A00);
   ir_variable *const r0A01 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A01, body.constant(true), 0x01));

   ir_variable *const r0A02 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A03 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0A03);
   ir_expression *const r0A04 = bit_and(r0A00, body.constant(127u));
   body.emit(assign(r0A03, expr(ir_unop_u2i, r0A04), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A06 = expr(ir_unop_i2u, r09FF);
   ir_expression *const r0A07 = gequal(r0A06, body.constant(253u));
   ir_if *f0A05 = new(mem_ctx) ir_if(operand(r0A07).val);
   exec_list *const f0A05_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A05->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A09 = less(body.constant(int(253)), r09FF);
      ir_expression *const r0A0A = equal(r09FF, body.constant(int(253)));
      ir_expression *const r0A0B = expr(ir_unop_u2i, r0A00);
      ir_expression *const r0A0C = less(r0A0B, body.constant(int(-64)));
      ir_expression *const r0A0D = logic_and(r0A0A, r0A0C);
      ir_expression *const r0A0E = logic_or(r0A09, r0A0D);
      ir_if *f0A08 = new(mem_ctx) ir_if(operand(r0A0E).val);
      exec_list *const f0A08_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A08->then_instructions;

         ir_expression *const r0A0F = lshift(r09FE, body.constant(int(31)));
         ir_expression *const r0A10 = add(r0A0F, body.constant(2139095040u));
         body.emit(assign(r0A02, expr(ir_unop_bitcast_u2f, r0A10), 0x01));

         body.emit(assign(r0A01, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A08->else_instructions;

         ir_variable *const r0A11 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0A11, neg(r09FF), 0x01));

         ir_variable *const r0A12 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
         body.emit(assign(r0A12, less(r09FF, body.constant(int(0))), 0x01));

         ir_variable *const r0A13 = body.make_temp(glsl_type::uint_type, "mix_retval");
         ir_expression *const r0A14 = neg(r09FF);
         ir_expression *const r0A15 = less(r0A14, body.constant(int(32)));
         ir_expression *const r0A16 = rshift(r0A00, r0A11);
         ir_expression *const r0A17 = neg(r0A11);
         ir_expression *const r0A18 = bit_and(r0A17, body.constant(int(31)));
         ir_expression *const r0A19 = lshift(r0A00, r0A18);
         ir_expression *const r0A1A = nequal(r0A19, body.constant(0u));
         ir_expression *const r0A1B = expr(ir_unop_b2i, r0A1A);
         ir_expression *const r0A1C = expr(ir_unop_i2u, r0A1B);
         ir_expression *const r0A1D = bit_or(r0A16, r0A1C);
         ir_expression *const r0A1E = nequal(r0A00, body.constant(0u));
         ir_expression *const r0A1F = expr(ir_unop_b2i, r0A1E);
         ir_expression *const r0A20 = expr(ir_unop_i2u, r0A1F);
         ir_expression *const r0A21 = expr(ir_triop_csel, r0A15, r0A1D, r0A20);
         body.emit(assign(r0A13, expr(ir_triop_csel, r0A12, r0A21, r0A00), 0x01));

         body.emit(assign(r0A00, r0A13, 0x01));

         ir_expression *const r0A22 = expr(ir_unop_u2i, r0A13);
         ir_expression *const r0A23 = bit_and(r0A22, body.constant(int(127)));
         body.emit(assign(r0A03, expr(ir_triop_csel, r0A12, r0A23, r0A03), 0x01));

         body.emit(assign(r09FF, expr(ir_triop_csel, r0A12, body.constant(int(0)), r09FF), 0x01));


      body.instructions = f0A08_parent_instructions;
      body.emit(f0A08);

      /* END IF */


   body.instructions = f0A05_parent_instructions;
   body.emit(f0A05);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0A24 = new(mem_ctx) ir_if(operand(r0A01).val);
   exec_list *const f0A24_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A24->then_instructions;

      ir_expression *const r0A25 = add(r0A00, body.constant(64u));
      body.emit(assign(r0A00, rshift(r0A25, body.constant(int(7))), 0x01));

      ir_expression *const r0A26 = bit_xor(r0A03, body.constant(int(64)));
      ir_expression *const r0A27 = equal(r0A26, body.constant(int(0)));
      ir_expression *const r0A28 = expr(ir_unop_b2i, r0A27);
      ir_expression *const r0A29 = expr(ir_unop_i2u, r0A28);
      ir_expression *const r0A2A = expr(ir_unop_bit_not, r0A29);
      body.emit(assign(r0A00, bit_and(r0A00, r0A2A), 0x01));

      ir_expression *const r0A2B = lshift(r09FE, body.constant(int(31)));
      ir_expression *const r0A2C = equal(r0A00, body.constant(0u));
      ir_expression *const r0A2D = expr(ir_triop_csel, r0A2C, body.constant(int(0)), r09FF);
      ir_expression *const r0A2E = expr(ir_unop_i2u, r0A2D);
      ir_expression *const r0A2F = lshift(r0A2E, body.constant(int(23)));
      ir_expression *const r0A30 = add(r0A2B, r0A2F);
      ir_expression *const r0A31 = add(r0A30, r0A00);
      body.emit(assign(r0A02, expr(ir_unop_bitcast_u2f, r0A31), 0x01));

      body.emit(assign(r0A01, body.constant(false), 0x01));


   body.instructions = f0A24_parent_instructions;
   body.emit(f0A24);

   /* END IF */

   body.emit(ret(r0A02));

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

   ir_variable *const r0A32 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A32);
   ir_variable *const r0A33 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A34 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0A34, swizzle_x(r0A32), 0x01));

   ir_variable *const r0A35 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A35, bit_and(swizzle_y(r0A32), body.constant(1048575u)), 0x01));

   ir_variable *const r0A36 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A37 = rshift(swizzle_y(r0A32), body.constant(int(20)));
   ir_expression *const r0A38 = bit_and(r0A37, body.constant(2047u));
   body.emit(assign(r0A36, expr(ir_unop_u2i, r0A38), 0x01));

   ir_variable *const r0A39 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A39, rshift(swizzle_y(r0A32), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A3B = equal(r0A36, body.constant(int(2047)));
   ir_if *f0A3A = new(mem_ctx) ir_if(operand(r0A3B).val);
   exec_list *const f0A3A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A3A->then_instructions;

      ir_variable *const r0A3C = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0A3C);
      ir_variable *const r0A3D = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0A3D, lshift(swizzle_x(r0A32), body.constant(int(12))), 0x01));

      ir_expression *const r0A3E = lshift(swizzle_y(r0A32), body.constant(int(12)));
      ir_expression *const r0A3F = rshift(swizzle_x(r0A32), body.constant(int(20)));
      body.emit(assign(r0A32, bit_or(r0A3E, r0A3F), 0x02));

      body.emit(assign(r0A32, r0A3D, 0x01));

      ir_expression *const r0A40 = lshift(r0A39, body.constant(int(31)));
      ir_expression *const r0A41 = bit_or(r0A40, body.constant(2143289344u));
      ir_expression *const r0A42 = rshift(swizzle_y(r0A32), body.constant(int(9)));
      ir_expression *const r0A43 = bit_or(r0A41, r0A42);
      body.emit(assign(r0A3C, expr(ir_unop_bitcast_u2f, r0A43), 0x01));

      ir_variable *const r0A44 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0A45 = bit_or(r0A35, r0A34);
      ir_expression *const r0A46 = nequal(r0A45, body.constant(0u));
      ir_expression *const r0A47 = lshift(r0A39, body.constant(int(31)));
      ir_expression *const r0A48 = add(r0A47, body.constant(2139095040u));
      ir_expression *const r0A49 = expr(ir_unop_bitcast_u2f, r0A48);
      body.emit(assign(r0A44, expr(ir_triop_csel, r0A46, r0A3C, r0A49), 0x01));

      body.emit(assign(r0A3C, r0A44, 0x01));

      body.emit(assign(r0A33, r0A44, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A3A->else_instructions;

      ir_variable *const r0A4A = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A4B = lshift(r0A35, body.constant(int(10)));
      ir_expression *const r0A4C = rshift(r0A34, body.constant(int(22)));
      ir_expression *const r0A4D = bit_or(r0A4B, r0A4C);
      ir_expression *const r0A4E = lshift(r0A34, body.constant(int(10)));
      ir_expression *const r0A4F = nequal(r0A4E, body.constant(0u));
      ir_expression *const r0A50 = expr(ir_unop_b2i, r0A4F);
      ir_expression *const r0A51 = expr(ir_unop_i2u, r0A50);
      body.emit(assign(r0A4A, bit_or(r0A4D, r0A51), 0x01));

      ir_variable *const r0A52 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A53 = nequal(r0A36, body.constant(int(0)));
      ir_expression *const r0A54 = bit_or(r0A4A, body.constant(1073741824u));
      body.emit(assign(r0A52, expr(ir_triop_csel, r0A53, r0A54, r0A4A), 0x01));

      ir_variable *const r0A55 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0A55, add(r0A36, body.constant(int(-897))), 0x01));

      ir_variable *const r0A56 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0A56, r0A52, 0x01));

      ir_variable *const r0A57 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0A57, body.constant(true), 0x01));

      ir_variable *const r0A58 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0A59 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0A59);
      ir_expression *const r0A5A = bit_and(r0A52, body.constant(127u));
      body.emit(assign(r0A59, expr(ir_unop_u2i, r0A5A), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A5C = expr(ir_unop_i2u, r0A55);
      ir_expression *const r0A5D = gequal(r0A5C, body.constant(253u));
      ir_if *f0A5B = new(mem_ctx) ir_if(operand(r0A5D).val);
      exec_list *const f0A5B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A5B->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A5F = less(body.constant(int(253)), r0A55);
         ir_expression *const r0A60 = equal(r0A55, body.constant(int(253)));
         ir_expression *const r0A61 = expr(ir_unop_u2i, r0A52);
         ir_expression *const r0A62 = less(r0A61, body.constant(int(-64)));
         ir_expression *const r0A63 = logic_and(r0A60, r0A62);
         ir_expression *const r0A64 = logic_or(r0A5F, r0A63);
         ir_if *f0A5E = new(mem_ctx) ir_if(operand(r0A64).val);
         exec_list *const f0A5E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A5E->then_instructions;

            ir_expression *const r0A65 = lshift(r0A39, body.constant(int(31)));
            ir_expression *const r0A66 = add(r0A65, body.constant(2139095040u));
            body.emit(assign(r0A58, expr(ir_unop_bitcast_u2f, r0A66), 0x01));

            body.emit(assign(r0A57, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A5E->else_instructions;

            ir_variable *const r0A67 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0A67, neg(r0A55), 0x01));

            ir_variable *const r0A68 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0A68, less(r0A55, body.constant(int(0))), 0x01));

            ir_variable *const r0A69 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0A6A = neg(r0A55);
            ir_expression *const r0A6B = less(r0A6A, body.constant(int(32)));
            ir_expression *const r0A6C = rshift(r0A52, r0A67);
            ir_expression *const r0A6D = neg(r0A67);
            ir_expression *const r0A6E = bit_and(r0A6D, body.constant(int(31)));
            ir_expression *const r0A6F = lshift(r0A52, r0A6E);
            ir_expression *const r0A70 = nequal(r0A6F, body.constant(0u));
            ir_expression *const r0A71 = expr(ir_unop_b2i, r0A70);
            ir_expression *const r0A72 = expr(ir_unop_i2u, r0A71);
            ir_expression *const r0A73 = bit_or(r0A6C, r0A72);
            ir_expression *const r0A74 = nequal(r0A52, body.constant(0u));
            ir_expression *const r0A75 = expr(ir_unop_b2i, r0A74);
            ir_expression *const r0A76 = expr(ir_unop_i2u, r0A75);
            ir_expression *const r0A77 = expr(ir_triop_csel, r0A6B, r0A73, r0A76);
            body.emit(assign(r0A69, expr(ir_triop_csel, r0A68, r0A77, r0A52), 0x01));

            body.emit(assign(r0A56, r0A69, 0x01));

            ir_expression *const r0A78 = expr(ir_unop_u2i, r0A69);
            ir_expression *const r0A79 = bit_and(r0A78, body.constant(int(127)));
            body.emit(assign(r0A59, expr(ir_triop_csel, r0A68, r0A79, r0A59), 0x01));

            body.emit(assign(r0A55, expr(ir_triop_csel, r0A68, body.constant(int(0)), r0A55), 0x01));


         body.instructions = f0A5E_parent_instructions;
         body.emit(f0A5E);

         /* END IF */


      body.instructions = f0A5B_parent_instructions;
      body.emit(f0A5B);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A7A = new(mem_ctx) ir_if(operand(r0A57).val);
      exec_list *const f0A7A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A7A->then_instructions;

         ir_expression *const r0A7B = add(r0A56, body.constant(64u));
         body.emit(assign(r0A56, rshift(r0A7B, body.constant(int(7))), 0x01));

         ir_expression *const r0A7C = bit_xor(r0A59, body.constant(int(64)));
         ir_expression *const r0A7D = equal(r0A7C, body.constant(int(0)));
         ir_expression *const r0A7E = expr(ir_unop_b2i, r0A7D);
         ir_expression *const r0A7F = expr(ir_unop_i2u, r0A7E);
         ir_expression *const r0A80 = expr(ir_unop_bit_not, r0A7F);
         body.emit(assign(r0A56, bit_and(r0A56, r0A80), 0x01));

         ir_expression *const r0A81 = lshift(r0A39, body.constant(int(31)));
         ir_expression *const r0A82 = equal(r0A56, body.constant(0u));
         ir_expression *const r0A83 = expr(ir_triop_csel, r0A82, body.constant(int(0)), r0A55);
         ir_expression *const r0A84 = expr(ir_unop_i2u, r0A83);
         ir_expression *const r0A85 = lshift(r0A84, body.constant(int(23)));
         ir_expression *const r0A86 = add(r0A81, r0A85);
         ir_expression *const r0A87 = add(r0A86, r0A56);
         body.emit(assign(r0A58, expr(ir_unop_bitcast_u2f, r0A87), 0x01));

         body.emit(assign(r0A57, body.constant(false), 0x01));


      body.instructions = f0A7A_parent_instructions;
      body.emit(f0A7A);

      /* END IF */

      body.emit(assign(r0A33, r0A58, 0x01));


   body.instructions = f0A3A_parent_instructions;
   body.emit(f0A3A);

   /* END IF */

   body.emit(ret(r0A33));

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

   ir_variable *const r0A88 = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0A88);
   ir_variable *const r0A89 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A89, body.constant(true), 0x01));

   ir_variable *const r0A8A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A8B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A8B);
   ir_variable *const r0A8C = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0A8C);
   ir_variable *const r0A8D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0A8D);
   ir_variable *const r0A8E = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0A8E, expr(ir_unop_bitcast_f2u, r0A88), 0x01));

   ir_variable *const r0A8F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0A8F, bit_and(r0A8E, body.constant(8388607u)), 0x01));

   body.emit(assign(r0A8D, r0A8F, 0x01));

   ir_variable *const r0A90 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A91 = rshift(r0A8E, body.constant(int(23)));
   ir_expression *const r0A92 = bit_and(r0A91, body.constant(255u));
   body.emit(assign(r0A90, expr(ir_unop_u2i, r0A92), 0x01));

   body.emit(assign(r0A8C, r0A90, 0x01));

   body.emit(assign(r0A8B, rshift(r0A8E, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A94 = equal(r0A90, body.constant(int(255)));
   ir_if *f0A93 = new(mem_ctx) ir_if(operand(r0A94).val);
   exec_list *const f0A93_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A93->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A96 = nequal(r0A8F, body.constant(0u));
      ir_if *f0A95 = new(mem_ctx) ir_if(operand(r0A96).val);
      exec_list *const f0A95_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A95->then_instructions;

         ir_variable *const r0A97 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0A97, lshift(r0A8E, body.constant(int(9))), 0x01));

         ir_variable *const r0A98 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0A99 = lshift(r0A97, body.constant(int(20)));
         body.emit(assign(r0A98, bit_or(r0A99, body.constant(0u)), 0x01));

         ir_expression *const r0A9A = rshift(r0A97, body.constant(int(12)));
         ir_expression *const r0A9B = lshift(r0A8B, body.constant(int(31)));
         ir_expression *const r0A9C = bit_or(r0A9B, body.constant(2146959360u));
         body.emit(assign(r0A98, bit_or(r0A9A, r0A9C), 0x02));

         body.emit(assign(r0A8A, r0A98, 0x03));

         body.emit(assign(r0A89, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A95->else_instructions;

         ir_variable *const r0A9D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0A9D);
         ir_expression *const r0A9E = lshift(r0A8B, body.constant(int(31)));
         body.emit(assign(r0A9D, add(r0A9E, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0A9D, body.constant(0u), 0x01));

         body.emit(assign(r0A8A, r0A9D, 0x03));

         body.emit(assign(r0A89, body.constant(false), 0x01));


      body.instructions = f0A95_parent_instructions;
      body.emit(f0A95);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A93->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0AA0 = equal(r0A90, body.constant(int(0)));
      ir_if *f0A9F = new(mem_ctx) ir_if(operand(r0AA0).val);
      exec_list *const f0A9F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A9F->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0AA2 = equal(r0A8F, body.constant(0u));
         ir_if *f0AA1 = new(mem_ctx) ir_if(operand(r0AA2).val);
         exec_list *const f0AA1_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA1->then_instructions;

            ir_variable *const r0AA3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0AA3);
            body.emit(assign(r0AA3, lshift(r0A8B, body.constant(int(31))), 0x02));

            body.emit(assign(r0AA3, body.constant(0u), 0x01));

            body.emit(assign(r0A8A, r0AA3, 0x03));

            body.emit(assign(r0A89, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AA1->else_instructions;

            ir_variable *const r0AA4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0AA5 = equal(r0A8F, body.constant(0u));
            ir_expression *const r0AA6 = expr(ir_unop_find_msb, r0A8F);
            ir_expression *const r0AA7 = sub(body.constant(int(31)), r0AA6);
            ir_expression *const r0AA8 = expr(ir_triop_csel, r0AA5, body.constant(int(32)), r0AA7);
            body.emit(assign(r0AA4, add(r0AA8, body.constant(int(-8))), 0x01));

            body.emit(assign(r0A8D, lshift(r0A8F, r0AA4), 0x01));

            body.emit(assign(r0A8C, sub(body.constant(int(1)), r0AA4), 0x01));

            body.emit(assign(r0A8C, add(r0A8C, body.constant(int(-1))), 0x01));


         body.instructions = f0AA1_parent_instructions;
         body.emit(f0AA1);

         /* END IF */


      body.instructions = f0A9F_parent_instructions;
      body.emit(f0A9F);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0AA9 = new(mem_ctx) ir_if(operand(r0A89).val);
      exec_list *const f0AA9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AA9->then_instructions;

         ir_variable *const r0AAA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0AAA);
         ir_expression *const r0AAB = lshift(r0A8B, body.constant(int(31)));
         ir_expression *const r0AAC = add(r0A8C, body.constant(int(896)));
         ir_expression *const r0AAD = expr(ir_unop_i2u, r0AAC);
         ir_expression *const r0AAE = lshift(r0AAD, body.constant(int(20)));
         ir_expression *const r0AAF = add(r0AAB, r0AAE);
         ir_expression *const r0AB0 = rshift(r0A8D, body.constant(int(3)));
         body.emit(assign(r0AAA, add(r0AAF, r0AB0), 0x02));

         ir_expression *const r0AB1 = lshift(r0A8D, body.constant(int(29)));
         body.emit(assign(r0AAA, bit_or(r0AB1, body.constant(0u)), 0x01));

         body.emit(assign(r0A8A, r0AAA, 0x03));

         body.emit(assign(r0A89, body.constant(false), 0x01));


      body.instructions = f0AA9_parent_instructions;
      body.emit(f0AA9);

      /* END IF */


   body.instructions = f0A93_parent_instructions;
   body.emit(f0A93);

   /* END IF */

   body.emit(ret(r0A8A));

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

   ir_variable *const r0AB2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0AB2);
   ir_variable *const r0AB3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0AB3);
   ir_variable *const r0AB4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0AB4);
   ir_variable *const r0AB5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0AB5);
   ir_variable *const r0AB6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0AB6);
   ir_variable *const r0AB7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0AB7);
   ir_variable *const r0AB8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AB8);
   ir_variable *const r0AB9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AB9);
   ir_variable *const r0ABA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0ABA);
   ir_variable *const r0ABB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0ABB);
   ir_variable *const r0ABC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0ABC);
   ir_variable *const r0ABD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0ABD, add(r0AB4, r0AB7), 0x01));

   ir_variable *const r0ABE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0ABF = less(r0ABD, r0AB4);
   ir_expression *const r0AC0 = expr(ir_unop_b2i, r0ABF);
   body.emit(assign(r0ABE, expr(ir_unop_i2u, r0AC0), 0x01));

   ir_variable *const r0AC1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0AC1, add(r0AB3, r0AB6), 0x01));

   body.emit(assign(r0ABC, add(r0AC1, r0ABE), 0x01));

   ir_expression *const r0AC2 = add(r0AB2, r0AB5);
   ir_expression *const r0AC3 = less(r0ABC, r0ABE);
   ir_expression *const r0AC4 = expr(ir_unop_b2i, r0AC3);
   ir_expression *const r0AC5 = expr(ir_unop_i2u, r0AC4);
   body.emit(assign(r0ABB, add(r0AC2, r0AC5), 0x01));

   ir_expression *const r0AC6 = less(r0AC1, r0AB3);
   ir_expression *const r0AC7 = expr(ir_unop_b2i, r0AC6);
   ir_expression *const r0AC8 = expr(ir_unop_i2u, r0AC7);
   body.emit(assign(r0ABB, add(r0ABB, r0AC8), 0x01));

   body.emit(assign(r0ABA, r0ABD, 0x01));

   body.emit(assign(r0AB9, r0ABC, 0x01));

   body.emit(assign(r0AB8, r0ABB, 0x01));

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

   ir_variable *const r0AC9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0AC9);
   ir_variable *const r0ACA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0ACA);
   ir_variable *const r0ACB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0ACB);
   ir_variable *const r0ACC = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0ACC);
   ir_variable *const r0ACD = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0ACD);
   ir_variable *const r0ACE = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0ACE);
   ir_variable *const r0ACF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0ACF);
   ir_variable *const r0AD0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AD0);
   ir_variable *const r0AD1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AD1);
   ir_variable *const r0AD2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0AD2);
   ir_variable *const r0AD3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0AD4 = less(r0ACB, r0ACE);
   ir_expression *const r0AD5 = expr(ir_unop_b2i, r0AD4);
   body.emit(assign(r0AD3, expr(ir_unop_i2u, r0AD5), 0x01));

   ir_variable *const r0AD6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0AD6, sub(r0ACA, r0ACD), 0x01));

   ir_expression *const r0AD7 = sub(r0AC9, r0ACC);
   ir_expression *const r0AD8 = less(r0AD6, r0AD3);
   ir_expression *const r0AD9 = expr(ir_unop_b2i, r0AD8);
   ir_expression *const r0ADA = expr(ir_unop_i2u, r0AD9);
   body.emit(assign(r0AD2, sub(r0AD7, r0ADA), 0x01));

   ir_expression *const r0ADB = less(r0ACA, r0ACD);
   ir_expression *const r0ADC = expr(ir_unop_b2i, r0ADB);
   ir_expression *const r0ADD = expr(ir_unop_i2u, r0ADC);
   body.emit(assign(r0AD2, sub(r0AD2, r0ADD), 0x01));

   body.emit(assign(r0AD1, sub(r0ACB, r0ACE), 0x01));

   body.emit(assign(r0AD0, sub(r0AD6, r0AD3), 0x01));

   body.emit(assign(r0ACF, r0AD2, 0x01));

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

   ir_variable *const r0ADE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0ADE);
   ir_variable *const r0ADF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0ADF);
   ir_variable *const r0AE0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0AE0);
   ir_variable *const r0AE1 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0AE2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0AE2);
   ir_variable *const r0AE3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0AE3);
   ir_variable *const r0AE4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0AE4);
   ir_variable *const r0AE5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0AE5);
   body.emit(assign(r0AE4, body.constant(0u), 0x01));

   body.emit(assign(r0AE3, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AE7 = gequal(r0ADE, r0AE0);
   ir_if *f0AE6 = new(mem_ctx) ir_if(operand(r0AE7).val);
   exec_list *const f0AE6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AE6->then_instructions;

      body.emit(assign(r0AE1, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AE6->else_instructions;

      body.emit(assign(r0AE5, rshift(r0AE0, body.constant(int(16))), 0x01));

      ir_variable *const r0AE8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0AEA = lshift(r0AE5, body.constant(int(16)));
      ir_expression *const r0AEB = gequal(r0ADE, r0AEA);
      ir_if *f0AE9 = new(mem_ctx) ir_if(operand(r0AEB).val);
      exec_list *const f0AE9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AE9->then_instructions;

         body.emit(assign(r0AE8, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AE9->else_instructions;

         ir_expression *const r0AEC = expr(ir_binop_div, r0ADE, r0AE5);
         body.emit(assign(r0AE8, lshift(r0AEC, body.constant(int(16))), 0x01));


      body.instructions = f0AE9_parent_instructions;
      body.emit(f0AE9);

      /* END IF */

      body.emit(assign(r0AE2, r0AE8, 0x01));

      ir_variable *const r0AED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0AED);
      ir_variable *const r0AEE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0AEE);
      ir_variable *const r0AEF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0AEF);
      ir_variable *const r0AF0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF0, bit_and(r0AE0, body.constant(65535u)), 0x01));

      ir_variable *const r0AF1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF1, rshift(r0AE0, body.constant(int(16))), 0x01));

      ir_variable *const r0AF2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF2, bit_and(r0AE8, body.constant(65535u)), 0x01));

      ir_variable *const r0AF3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF3, rshift(r0AE8, body.constant(int(16))), 0x01));

      ir_variable *const r0AF4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF4, mul(r0AF1, r0AF2), 0x01));

      ir_expression *const r0AF5 = mul(r0AF0, r0AF3);
      body.emit(assign(r0AEE, add(r0AF5, r0AF4), 0x01));

      ir_expression *const r0AF6 = mul(r0AF1, r0AF3);
      ir_expression *const r0AF7 = less(r0AEE, r0AF4);
      ir_expression *const r0AF8 = expr(ir_unop_b2i, r0AF7);
      ir_expression *const r0AF9 = expr(ir_unop_i2u, r0AF8);
      ir_expression *const r0AFA = lshift(r0AF9, body.constant(int(16)));
      ir_expression *const r0AFB = rshift(r0AEE, body.constant(int(16)));
      ir_expression *const r0AFC = add(r0AFA, r0AFB);
      body.emit(assign(r0AED, add(r0AF6, r0AFC), 0x01));

      body.emit(assign(r0AEE, lshift(r0AEE, body.constant(int(16))), 0x01));

      ir_expression *const r0AFD = mul(r0AF0, r0AF2);
      body.emit(assign(r0AEF, add(r0AFD, r0AEE), 0x01));

      ir_expression *const r0AFE = less(r0AEF, r0AEE);
      ir_expression *const r0AFF = expr(ir_unop_b2i, r0AFE);
      ir_expression *const r0B00 = expr(ir_unop_i2u, r0AFF);
      body.emit(assign(r0AED, add(r0AED, r0B00), 0x01));

      ir_expression *const r0B01 = sub(r0ADE, r0AED);
      ir_expression *const r0B02 = less(r0ADF, r0AEF);
      ir_expression *const r0B03 = expr(ir_unop_b2i, r0B02);
      ir_expression *const r0B04 = expr(ir_unop_i2u, r0B03);
      body.emit(assign(r0AE4, sub(r0B01, r0B04), 0x01));

      body.emit(assign(r0AE3, sub(r0ADF, r0AEF), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0B05 = new(mem_ctx) ir_loop();
      exec_list *const f0B05_parent_instructions = body.instructions;

         body.instructions = &f0B05->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0B07 = expr(ir_unop_u2i, r0AE4);
         ir_expression *const r0B08 = gequal(r0B07, body.constant(int(0)));
         ir_if *f0B06 = new(mem_ctx) ir_if(operand(r0B08).val);
         exec_list *const f0B06_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B06->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0B06_parent_instructions;
         body.emit(f0B06);

         /* END IF */

         body.emit(assign(r0AE2, add(r0AE2, body.constant(4294901760u)), 0x01));

         ir_variable *const r0B09 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0B0A = lshift(r0AE0, body.constant(int(16)));
         body.emit(assign(r0B09, add(r0AE3, r0B0A), 0x01));

         ir_expression *const r0B0B = add(r0AE4, r0AE5);
         ir_expression *const r0B0C = less(r0B09, r0AE3);
         ir_expression *const r0B0D = expr(ir_unop_b2i, r0B0C);
         ir_expression *const r0B0E = expr(ir_unop_i2u, r0B0D);
         body.emit(assign(r0AE4, add(r0B0B, r0B0E), 0x01));

         body.emit(assign(r0AE3, r0B09, 0x01));

      /* LOOP END */

      body.instructions = f0B05_parent_instructions;
      body.emit(f0B05);

      ir_expression *const r0B0F = lshift(r0AE4, body.constant(int(16)));
      ir_expression *const r0B10 = rshift(r0AE3, body.constant(int(16)));
      body.emit(assign(r0AE4, bit_or(r0B0F, r0B10), 0x01));

      ir_variable *const r0B11 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0B13 = lshift(r0AE5, body.constant(int(16)));
      ir_expression *const r0B14 = gequal(r0AE4, r0B13);
      ir_if *f0B12 = new(mem_ctx) ir_if(operand(r0B14).val);
      exec_list *const f0B12_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B12->then_instructions;

         body.emit(assign(r0B11, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B12->else_instructions;

         body.emit(assign(r0B11, expr(ir_binop_div, r0AE4, r0AE5), 0x01));


      body.instructions = f0B12_parent_instructions;
      body.emit(f0B12);

      /* END IF */

      body.emit(assign(r0AE2, bit_or(r0AE2, r0B11), 0x01));

      body.emit(assign(r0AE1, r0AE2, 0x01));


   body.instructions = f0AE6_parent_instructions;
   body.emit(f0AE6);

   /* END IF */

   body.emit(ret(r0AE1));

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

   ir_variable *const r0B15 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B15);
   ir_variable *const r0B16 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0B16, r0B15, 0x03));

   ir_variable *const r0B17 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B18 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B18, bit_and(swizzle_y(r0B15), body.constant(1048575u)), 0x01));

   ir_variable *const r0B19 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B1A = rshift(swizzle_y(r0B15), body.constant(int(20)));
   ir_expression *const r0B1B = bit_and(r0B1A, body.constant(2047u));
   body.emit(assign(r0B19, expr(ir_unop_u2i, r0B1B), 0x01));

   ir_variable *const r0B1C = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B1C, rshift(swizzle_y(r0B15), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B1E = equal(r0B19, body.constant(int(2047)));
   ir_if *f0B1D = new(mem_ctx) ir_if(operand(r0B1E).val);
   exec_list *const f0B1D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B1D->then_instructions;

      ir_variable *const r0B1F = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0B1F);
      ir_expression *const r0B20 = lshift(swizzle_y(r0B15), body.constant(int(12)));
      ir_expression *const r0B21 = rshift(swizzle_x(r0B15), body.constant(int(20)));
      body.emit(assign(r0B16, bit_or(r0B20, r0B21), 0x02));

      body.emit(assign(r0B16, lshift(swizzle_x(r0B15), body.constant(int(12))), 0x01));

      ir_expression *const r0B22 = lshift(r0B1C, body.constant(int(31)));
      ir_expression *const r0B23 = bit_or(r0B22, body.constant(2143289344u));
      ir_expression *const r0B24 = rshift(swizzle_y(r0B16), body.constant(int(9)));
      ir_expression *const r0B25 = bit_or(r0B23, r0B24);
      body.emit(assign(r0B1F, expr(ir_unop_bitcast_u2f, r0B25), 0x01));

      ir_variable *const r0B26 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0B27 = bit_or(r0B18, swizzle_x(r0B15));
      ir_expression *const r0B28 = nequal(r0B27, body.constant(0u));
      ir_expression *const r0B29 = lshift(r0B1C, body.constant(int(31)));
      ir_expression *const r0B2A = add(r0B29, body.constant(2139095040u));
      ir_expression *const r0B2B = expr(ir_unop_bitcast_u2f, r0B2A);
      body.emit(assign(r0B26, expr(ir_triop_csel, r0B28, r0B1F, r0B2B), 0x01));

      body.emit(assign(r0B1F, r0B26, 0x01));

      body.emit(assign(r0B17, r0B26, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B1D->else_instructions;

      ir_variable *const r0B2C = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0B2D = lshift(r0B18, body.constant(int(10)));
      ir_expression *const r0B2E = rshift(swizzle_x(r0B15), body.constant(int(22)));
      ir_expression *const r0B2F = bit_or(r0B2D, r0B2E);
      ir_expression *const r0B30 = lshift(swizzle_x(r0B15), body.constant(int(10)));
      ir_expression *const r0B31 = nequal(r0B30, body.constant(0u));
      ir_expression *const r0B32 = expr(ir_unop_b2i, r0B31);
      ir_expression *const r0B33 = expr(ir_unop_i2u, r0B32);
      body.emit(assign(r0B2C, bit_or(r0B2F, r0B33), 0x01));

      ir_variable *const r0B34 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0B35 = nequal(r0B19, body.constant(int(0)));
      ir_expression *const r0B36 = bit_or(r0B2C, body.constant(1073741824u));
      body.emit(assign(r0B34, expr(ir_triop_csel, r0B35, r0B36, r0B2C), 0x01));

      ir_variable *const r0B37 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B37, add(r0B19, body.constant(int(-897))), 0x01));

      ir_variable *const r0B38 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B38, r0B34, 0x01));

      ir_variable *const r0B39 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B39, body.constant(true), 0x01));

      ir_variable *const r0B3A = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B3B = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B3B);
      ir_expression *const r0B3C = bit_and(r0B34, body.constant(127u));
      body.emit(assign(r0B3B, expr(ir_unop_u2i, r0B3C), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B3E = expr(ir_unop_i2u, r0B37);
      ir_expression *const r0B3F = gequal(r0B3E, body.constant(253u));
      ir_if *f0B3D = new(mem_ctx) ir_if(operand(r0B3F).val);
      exec_list *const f0B3D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B3D->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B41 = less(body.constant(int(253)), r0B37);
         ir_expression *const r0B42 = equal(r0B37, body.constant(int(253)));
         ir_expression *const r0B43 = expr(ir_unop_u2i, r0B34);
         ir_expression *const r0B44 = less(r0B43, body.constant(int(-64)));
         ir_expression *const r0B45 = logic_and(r0B42, r0B44);
         ir_expression *const r0B46 = logic_or(r0B41, r0B45);
         ir_if *f0B40 = new(mem_ctx) ir_if(operand(r0B46).val);
         exec_list *const f0B40_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B40->then_instructions;

            ir_expression *const r0B47 = lshift(r0B1C, body.constant(int(31)));
            ir_expression *const r0B48 = add(r0B47, body.constant(2139095040u));
            body.emit(assign(r0B3A, expr(ir_unop_bitcast_u2f, r0B48), 0x01));

            body.emit(assign(r0B39, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B40->else_instructions;

            ir_variable *const r0B49 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B49, neg(r0B37), 0x01));

            ir_variable *const r0B4A = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0B4A, less(r0B37, body.constant(int(0))), 0x01));

            ir_variable *const r0B4B = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0B4C = neg(r0B37);
            ir_expression *const r0B4D = less(r0B4C, body.constant(int(32)));
            ir_expression *const r0B4E = rshift(r0B34, r0B49);
            ir_expression *const r0B4F = neg(r0B49);
            ir_expression *const r0B50 = bit_and(r0B4F, body.constant(int(31)));
            ir_expression *const r0B51 = lshift(r0B34, r0B50);
            ir_expression *const r0B52 = nequal(r0B51, body.constant(0u));
            ir_expression *const r0B53 = expr(ir_unop_b2i, r0B52);
            ir_expression *const r0B54 = expr(ir_unop_i2u, r0B53);
            ir_expression *const r0B55 = bit_or(r0B4E, r0B54);
            ir_expression *const r0B56 = nequal(r0B34, body.constant(0u));
            ir_expression *const r0B57 = expr(ir_unop_b2i, r0B56);
            ir_expression *const r0B58 = expr(ir_unop_i2u, r0B57);
            ir_expression *const r0B59 = expr(ir_triop_csel, r0B4D, r0B55, r0B58);
            body.emit(assign(r0B4B, expr(ir_triop_csel, r0B4A, r0B59, r0B34), 0x01));

            body.emit(assign(r0B38, r0B4B, 0x01));

            ir_expression *const r0B5A = expr(ir_unop_u2i, r0B4B);
            ir_expression *const r0B5B = bit_and(r0B5A, body.constant(int(127)));
            body.emit(assign(r0B3B, expr(ir_triop_csel, r0B4A, r0B5B, r0B3B), 0x01));

            body.emit(assign(r0B37, expr(ir_triop_csel, r0B4A, body.constant(int(0)), r0B37), 0x01));


         body.instructions = f0B40_parent_instructions;
         body.emit(f0B40);

         /* END IF */


      body.instructions = f0B3D_parent_instructions;
      body.emit(f0B3D);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B5C = new(mem_ctx) ir_if(operand(r0B39).val);
      exec_list *const f0B5C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B5C->then_instructions;

         ir_expression *const r0B5D = add(r0B38, body.constant(64u));
         body.emit(assign(r0B38, rshift(r0B5D, body.constant(int(7))), 0x01));

         ir_expression *const r0B5E = bit_xor(r0B3B, body.constant(int(64)));
         ir_expression *const r0B5F = equal(r0B5E, body.constant(int(0)));
         ir_expression *const r0B60 = expr(ir_unop_b2i, r0B5F);
         ir_expression *const r0B61 = expr(ir_unop_i2u, r0B60);
         ir_expression *const r0B62 = expr(ir_unop_bit_not, r0B61);
         body.emit(assign(r0B38, bit_and(r0B38, r0B62), 0x01));

         ir_expression *const r0B63 = lshift(r0B1C, body.constant(int(31)));
         ir_expression *const r0B64 = equal(r0B38, body.constant(0u));
         ir_expression *const r0B65 = expr(ir_triop_csel, r0B64, body.constant(int(0)), r0B37);
         ir_expression *const r0B66 = expr(ir_unop_i2u, r0B65);
         ir_expression *const r0B67 = lshift(r0B66, body.constant(int(23)));
         ir_expression *const r0B68 = add(r0B63, r0B67);
         ir_expression *const r0B69 = add(r0B68, r0B38);
         body.emit(assign(r0B3A, expr(ir_unop_bitcast_u2f, r0B69), 0x01));

         body.emit(assign(r0B39, body.constant(false), 0x01));


      body.instructions = f0B5C_parent_instructions;
      body.emit(f0B5C);

      /* END IF */

      body.emit(assign(r0B17, r0B3A, 0x01));


   body.instructions = f0B1D_parent_instructions;
   body.emit(f0B1D);

   /* END IF */

   ir_variable *const r0B6A = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B6A, body.constant(true), 0x01));

   ir_variable *const r0B6B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B6C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B6C);
   ir_variable *const r0B6D = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B6D);
   ir_variable *const r0B6E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B6E);
   ir_variable *const r0B6F = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0B70 = expr(ir_unop_sqrt, r0B17);
   body.emit(assign(r0B6F, expr(ir_unop_bitcast_f2u, r0B70), 0x01));

   ir_variable *const r0B71 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B71, bit_and(r0B6F, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B6E, r0B71, 0x01));

   ir_variable *const r0B72 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B73 = rshift(r0B6F, body.constant(int(23)));
   ir_expression *const r0B74 = bit_and(r0B73, body.constant(255u));
   body.emit(assign(r0B72, expr(ir_unop_u2i, r0B74), 0x01));

   body.emit(assign(r0B6D, r0B72, 0x01));

   body.emit(assign(r0B6C, rshift(r0B6F, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B76 = equal(r0B72, body.constant(int(255)));
   ir_if *f0B75 = new(mem_ctx) ir_if(operand(r0B76).val);
   exec_list *const f0B75_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B75->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B78 = nequal(r0B71, body.constant(0u));
      ir_if *f0B77 = new(mem_ctx) ir_if(operand(r0B78).val);
      exec_list *const f0B77_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B77->then_instructions;

         ir_variable *const r0B79 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B79, lshift(r0B6F, body.constant(int(9))), 0x01));

         ir_variable *const r0B7A = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B7B = lshift(r0B79, body.constant(int(20)));
         body.emit(assign(r0B7A, bit_or(r0B7B, body.constant(0u)), 0x01));

         ir_expression *const r0B7C = rshift(r0B79, body.constant(int(12)));
         ir_expression *const r0B7D = lshift(r0B6C, body.constant(int(31)));
         ir_expression *const r0B7E = bit_or(r0B7D, body.constant(2146959360u));
         body.emit(assign(r0B7A, bit_or(r0B7C, r0B7E), 0x02));

         body.emit(assign(r0B6B, r0B7A, 0x03));

         body.emit(assign(r0B6A, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B77->else_instructions;

         ir_variable *const r0B7F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B7F);
         ir_expression *const r0B80 = lshift(r0B6C, body.constant(int(31)));
         body.emit(assign(r0B7F, add(r0B80, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B7F, body.constant(0u), 0x01));

         body.emit(assign(r0B6B, r0B7F, 0x03));

         body.emit(assign(r0B6A, body.constant(false), 0x01));


      body.instructions = f0B77_parent_instructions;
      body.emit(f0B77);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B75->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B82 = equal(r0B72, body.constant(int(0)));
      ir_if *f0B81 = new(mem_ctx) ir_if(operand(r0B82).val);
      exec_list *const f0B81_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B81->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B84 = equal(r0B71, body.constant(0u));
         ir_if *f0B83 = new(mem_ctx) ir_if(operand(r0B84).val);
         exec_list *const f0B83_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B83->then_instructions;

            ir_variable *const r0B85 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B85);
            body.emit(assign(r0B85, lshift(r0B6C, body.constant(int(31))), 0x02));

            body.emit(assign(r0B85, body.constant(0u), 0x01));

            body.emit(assign(r0B6B, r0B85, 0x03));

            body.emit(assign(r0B6A, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B83->else_instructions;

            ir_variable *const r0B86 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0B87 = equal(r0B71, body.constant(0u));
            ir_expression *const r0B88 = expr(ir_unop_find_msb, r0B71);
            ir_expression *const r0B89 = sub(body.constant(int(31)), r0B88);
            ir_expression *const r0B8A = expr(ir_triop_csel, r0B87, body.constant(int(32)), r0B89);
            body.emit(assign(r0B86, add(r0B8A, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B6E, lshift(r0B71, r0B86), 0x01));

            body.emit(assign(r0B6D, sub(body.constant(int(1)), r0B86), 0x01));

            body.emit(assign(r0B6D, add(r0B6D, body.constant(int(-1))), 0x01));


         body.instructions = f0B83_parent_instructions;
         body.emit(f0B83);

         /* END IF */


      body.instructions = f0B81_parent_instructions;
      body.emit(f0B81);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B8B = new(mem_ctx) ir_if(operand(r0B6A).val);
      exec_list *const f0B8B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B8B->then_instructions;

         ir_variable *const r0B8C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B8C);
         ir_expression *const r0B8D = lshift(r0B6C, body.constant(int(31)));
         ir_expression *const r0B8E = add(r0B6D, body.constant(int(896)));
         ir_expression *const r0B8F = expr(ir_unop_i2u, r0B8E);
         ir_expression *const r0B90 = lshift(r0B8F, body.constant(int(20)));
         ir_expression *const r0B91 = add(r0B8D, r0B90);
         ir_expression *const r0B92 = rshift(r0B6E, body.constant(int(3)));
         body.emit(assign(r0B8C, add(r0B91, r0B92), 0x02));

         ir_expression *const r0B93 = lshift(r0B6E, body.constant(int(29)));
         body.emit(assign(r0B8C, bit_or(r0B93, body.constant(0u)), 0x01));

         body.emit(assign(r0B6B, r0B8C, 0x03));

         body.emit(assign(r0B6A, body.constant(false), 0x01));


      body.instructions = f0B8B_parent_instructions;
      body.emit(f0B8B);

      /* END IF */


   body.instructions = f0B75_parent_instructions;
   body.emit(f0B75);

   /* END IF */

   body.emit(ret(r0B6B));

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

   ir_variable *const r0B94 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B94);
   ir_variable *const r0B95 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B96 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B97 = rshift(swizzle_y(r0B94), body.constant(int(20)));
   ir_expression *const r0B98 = bit_and(r0B97, body.constant(2047u));
   ir_expression *const r0B99 = expr(ir_unop_u2i, r0B98);
   body.emit(assign(r0B96, add(r0B99, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B9B = less(r0B96, body.constant(int(0)));
   ir_if *f0B9A = new(mem_ctx) ir_if(operand(r0B9B).val);
   exec_list *const f0B9A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B9A->then_instructions;

      body.emit(assign(r0B95, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B9A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B9D = less(body.constant(int(52)), r0B96);
      ir_if *f0B9C = new(mem_ctx) ir_if(operand(r0B9D).val);
      exec_list *const f0B9C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B9C->then_instructions;

         body.emit(assign(r0B95, r0B94, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B9C->else_instructions;

         ir_variable *const r0B9E = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0B9E, sub(body.constant(int(52)), r0B96), 0x01));

         ir_variable *const r0B9F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0BA1 = gequal(r0B9E, body.constant(int(32)));
         ir_if *f0BA0 = new(mem_ctx) ir_if(operand(r0BA1).val);
         exec_list *const f0BA0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BA0->then_instructions;

            body.emit(assign(r0B9F, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BA0->else_instructions;

            body.emit(assign(r0B9F, lshift(body.constant(4294967295u), r0B9E), 0x01));


         body.instructions = f0BA0_parent_instructions;
         body.emit(f0BA0);

         /* END IF */

         ir_variable *const r0BA2 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0BA4 = less(r0B9E, body.constant(int(33)));
         ir_if *f0BA3 = new(mem_ctx) ir_if(operand(r0BA4).val);
         exec_list *const f0BA3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BA3->then_instructions;

            body.emit(assign(r0BA2, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BA3->else_instructions;

            ir_expression *const r0BA5 = add(r0B9E, body.constant(int(-32)));
            body.emit(assign(r0BA2, lshift(body.constant(4294967295u), r0BA5), 0x01));


         body.instructions = f0BA3_parent_instructions;
         body.emit(f0BA3);

         /* END IF */

         ir_variable *const r0BA6 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0BA6, bit_and(r0B9F, swizzle_x(r0B94)), 0x01));

         body.emit(assign(r0BA6, bit_and(r0BA2, swizzle_y(r0B94)), 0x02));

         body.emit(assign(r0B95, r0BA6, 0x03));


      body.instructions = f0B9C_parent_instructions;
      body.emit(f0B9C);

      /* END IF */


   body.instructions = f0B9A_parent_instructions;
   body.emit(f0B9A);

   /* END IF */

   body.emit(ret(r0B95));

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

   ir_variable *const r0BA7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BA7);
   ir_variable *const r0BA8 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0BA8, body.constant(true), 0x01));

   ir_variable *const r0BA9 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0BAA = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0BAA);
   ir_variable *const r0BAB = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0BAB);
   ir_variable *const r0BAC = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0BAD = rshift(swizzle_y(r0BA7), body.constant(int(20)));
   ir_expression *const r0BAE = bit_and(r0BAD, body.constant(2047u));
   ir_expression *const r0BAF = expr(ir_unop_u2i, r0BAE);
   body.emit(assign(r0BAC, add(r0BAF, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0BAB, swizzle_y(r0BA7), 0x01));

   body.emit(assign(r0BAA, swizzle_x(r0BA7), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BB1 = less(r0BAC, body.constant(int(20)));
   ir_if *f0BB0 = new(mem_ctx) ir_if(operand(r0BB1).val);
   exec_list *const f0BB0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BB0->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0BB3 = less(r0BAC, body.constant(int(0)));
      ir_if *f0BB2 = new(mem_ctx) ir_if(operand(r0BB3).val);
      exec_list *const f0BB2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BB2->then_instructions;

         body.emit(assign(r0BAB, bit_and(swizzle_y(r0BA7), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BB5 = equal(r0BAC, body.constant(int(-1)));
         ir_expression *const r0BB6 = nequal(swizzle_x(r0BA7), body.constant(0u));
         ir_expression *const r0BB7 = logic_and(r0BB5, r0BB6);
         ir_if *f0BB4 = new(mem_ctx) ir_if(operand(r0BB7).val);
         exec_list *const f0BB4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BB4->then_instructions;

            body.emit(assign(r0BAB, bit_or(r0BAB, body.constant(1072693248u)), 0x01));


         body.instructions = f0BB4_parent_instructions;
         body.emit(f0BB4);

         /* END IF */

         body.emit(assign(r0BAA, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BB2->else_instructions;

         ir_variable *const r0BB8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0BB8, rshift(body.constant(1048575u), r0BAC), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BBA = bit_and(r0BAB, r0BB8);
         ir_expression *const r0BBB = equal(r0BBA, body.constant(0u));
         ir_expression *const r0BBC = equal(r0BAA, body.constant(0u));
         ir_expression *const r0BBD = logic_and(r0BBB, r0BBC);
         ir_if *f0BB9 = new(mem_ctx) ir_if(operand(r0BBD).val);
         exec_list *const f0BB9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BB9->then_instructions;

            body.emit(assign(r0BA9, r0BA7, 0x03));

            body.emit(assign(r0BA8, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BB9->else_instructions;

            ir_expression *const r0BBE = rshift(body.constant(524288u), r0BAC);
            body.emit(assign(r0BAB, add(r0BAB, r0BBE), 0x01));

            ir_expression *const r0BBF = expr(ir_unop_bit_not, r0BB8);
            body.emit(assign(r0BAB, bit_and(r0BAB, r0BBF), 0x01));

            body.emit(assign(r0BAA, body.constant(0u), 0x01));


         body.instructions = f0BB9_parent_instructions;
         body.emit(f0BB9);

         /* END IF */


      body.instructions = f0BB2_parent_instructions;
      body.emit(f0BB2);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BB0->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0BC1 = less(body.constant(int(51)), r0BAC);
      ir_expression *const r0BC2 = equal(r0BAC, body.constant(int(1024)));
      ir_expression *const r0BC3 = logic_or(r0BC1, r0BC2);
      ir_if *f0BC0 = new(mem_ctx) ir_if(operand(r0BC3).val);
      exec_list *const f0BC0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BC0->then_instructions;

         body.emit(assign(r0BA9, r0BA7, 0x03));

         body.emit(assign(r0BA8, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BC0->else_instructions;

         ir_variable *const r0BC4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0BC5 = add(r0BAC, body.constant(int(-20)));
         body.emit(assign(r0BC4, rshift(body.constant(4294967295u), r0BC5), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BC7 = bit_and(r0BAA, r0BC4);
         ir_expression *const r0BC8 = equal(r0BC7, body.constant(0u));
         ir_if *f0BC6 = new(mem_ctx) ir_if(operand(r0BC8).val);
         exec_list *const f0BC6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BC6->then_instructions;

            body.emit(assign(r0BA9, r0BA7, 0x03));

            body.emit(assign(r0BA8, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BC6->else_instructions;

            ir_variable *const r0BC9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0BCA = sub(body.constant(int(51)), r0BAC);
            ir_expression *const r0BCB = lshift(body.constant(1u), r0BCA);
            body.emit(assign(r0BC9, add(r0BAA, r0BCB), 0x01));

            /* IF CONDITION */
            ir_expression *const r0BCD = less(r0BC9, r0BAA);
            ir_if *f0BCC = new(mem_ctx) ir_if(operand(r0BCD).val);
            exec_list *const f0BCC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0BCC->then_instructions;

               body.emit(assign(r0BAB, add(r0BAB, body.constant(1u)), 0x01));


            body.instructions = f0BCC_parent_instructions;
            body.emit(f0BCC);

            /* END IF */

            ir_expression *const r0BCE = expr(ir_unop_bit_not, r0BC4);
            body.emit(assign(r0BAA, bit_and(r0BC9, r0BCE), 0x01));


         body.instructions = f0BC6_parent_instructions;
         body.emit(f0BC6);

         /* END IF */


      body.instructions = f0BC0_parent_instructions;
      body.emit(f0BC0);

      /* END IF */


   body.instructions = f0BB0_parent_instructions;
   body.emit(f0BB0);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0BCF = new(mem_ctx) ir_if(operand(r0BA8).val);
   exec_list *const f0BCF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BCF->then_instructions;

      body.emit(assign(r0BA7, r0BAA, 0x01));

      body.emit(assign(r0BA7, r0BAB, 0x02));

      body.emit(assign(r0BA9, r0BA7, 0x03));

      body.emit(assign(r0BA8, body.constant(false), 0x01));


   body.instructions = f0BCF_parent_instructions;
   body.emit(f0BCF);

   /* END IF */

   body.emit(ret(r0BA9));

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

   ir_variable *const r0BD0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BD0);
   ir_variable *const r0BD1 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0BD1, r0BD0, 0x03));

   ir_variable *const r0BD2 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0BD3 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0BD3, bit_and(swizzle_y(r0BD0), body.constant(1048575u)), 0x01));

   ir_variable *const r0BD4 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0BD5 = rshift(swizzle_y(r0BD0), body.constant(int(20)));
   ir_expression *const r0BD6 = bit_and(r0BD5, body.constant(2047u));
   body.emit(assign(r0BD4, expr(ir_unop_u2i, r0BD6), 0x01));

   ir_variable *const r0BD7 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0BD7, rshift(swizzle_y(r0BD0), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BD9 = equal(r0BD4, body.constant(int(2047)));
   ir_if *f0BD8 = new(mem_ctx) ir_if(operand(r0BD9).val);
   exec_list *const f0BD8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BD8->then_instructions;

      ir_variable *const r0BDA = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0BDA);
      ir_expression *const r0BDB = lshift(swizzle_y(r0BD0), body.constant(int(12)));
      ir_expression *const r0BDC = rshift(swizzle_x(r0BD0), body.constant(int(20)));
      body.emit(assign(r0BD1, bit_or(r0BDB, r0BDC), 0x02));

      body.emit(assign(r0BD1, lshift(swizzle_x(r0BD0), body.constant(int(12))), 0x01));

      ir_expression *const r0BDD = lshift(r0BD7, body.constant(int(31)));
      ir_expression *const r0BDE = bit_or(r0BDD, body.constant(2143289344u));
      ir_expression *const r0BDF = rshift(swizzle_y(r0BD1), body.constant(int(9)));
      ir_expression *const r0BE0 = bit_or(r0BDE, r0BDF);
      body.emit(assign(r0BDA, expr(ir_unop_bitcast_u2f, r0BE0), 0x01));

      ir_variable *const r0BE1 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0BE2 = bit_or(r0BD3, swizzle_x(r0BD0));
      ir_expression *const r0BE3 = nequal(r0BE2, body.constant(0u));
      ir_expression *const r0BE4 = lshift(r0BD7, body.constant(int(31)));
      ir_expression *const r0BE5 = add(r0BE4, body.constant(2139095040u));
      ir_expression *const r0BE6 = expr(ir_unop_bitcast_u2f, r0BE5);
      body.emit(assign(r0BE1, expr(ir_triop_csel, r0BE3, r0BDA, r0BE6), 0x01));

      body.emit(assign(r0BDA, r0BE1, 0x01));

      body.emit(assign(r0BD2, r0BE1, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BD8->else_instructions;

      ir_variable *const r0BE7 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0BE8 = lshift(r0BD3, body.constant(int(10)));
      ir_expression *const r0BE9 = rshift(swizzle_x(r0BD0), body.constant(int(22)));
      ir_expression *const r0BEA = bit_or(r0BE8, r0BE9);
      ir_expression *const r0BEB = lshift(swizzle_x(r0BD0), body.constant(int(10)));
      ir_expression *const r0BEC = nequal(r0BEB, body.constant(0u));
      ir_expression *const r0BED = expr(ir_unop_b2i, r0BEC);
      ir_expression *const r0BEE = expr(ir_unop_i2u, r0BED);
      body.emit(assign(r0BE7, bit_or(r0BEA, r0BEE), 0x01));

      ir_variable *const r0BEF = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0BF0 = nequal(r0BD4, body.constant(int(0)));
      ir_expression *const r0BF1 = bit_or(r0BE7, body.constant(1073741824u));
      body.emit(assign(r0BEF, expr(ir_triop_csel, r0BF0, r0BF1, r0BE7), 0x01));

      ir_variable *const r0BF2 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0BF2, add(r0BD4, body.constant(int(-897))), 0x01));

      ir_variable *const r0BF3 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0BF3, r0BEF, 0x01));

      ir_variable *const r0BF4 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0BF4, body.constant(true), 0x01));

      ir_variable *const r0BF5 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0BF6 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0BF6);
      ir_expression *const r0BF7 = bit_and(r0BEF, body.constant(127u));
      body.emit(assign(r0BF6, expr(ir_unop_u2i, r0BF7), 0x01));

      /* IF CONDITION */
      ir_expression *const r0BF9 = expr(ir_unop_i2u, r0BF2);
      ir_expression *const r0BFA = gequal(r0BF9, body.constant(253u));
      ir_if *f0BF8 = new(mem_ctx) ir_if(operand(r0BFA).val);
      exec_list *const f0BF8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BF8->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0BFC = less(body.constant(int(253)), r0BF2);
         ir_expression *const r0BFD = equal(r0BF2, body.constant(int(253)));
         ir_expression *const r0BFE = expr(ir_unop_u2i, r0BEF);
         ir_expression *const r0BFF = less(r0BFE, body.constant(int(-64)));
         ir_expression *const r0C00 = logic_and(r0BFD, r0BFF);
         ir_expression *const r0C01 = logic_or(r0BFC, r0C00);
         ir_if *f0BFB = new(mem_ctx) ir_if(operand(r0C01).val);
         exec_list *const f0BFB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BFB->then_instructions;

            ir_expression *const r0C02 = lshift(r0BD7, body.constant(int(31)));
            ir_expression *const r0C03 = add(r0C02, body.constant(2139095040u));
            body.emit(assign(r0BF5, expr(ir_unop_bitcast_u2f, r0C03), 0x01));

            body.emit(assign(r0BF4, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BFB->else_instructions;

            ir_variable *const r0C04 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0C04, neg(r0BF2), 0x01));

            ir_variable *const r0C05 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0C05, less(r0BF2, body.constant(int(0))), 0x01));

            ir_variable *const r0C06 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0C07 = neg(r0BF2);
            ir_expression *const r0C08 = less(r0C07, body.constant(int(32)));
            ir_expression *const r0C09 = rshift(r0BEF, r0C04);
            ir_expression *const r0C0A = neg(r0C04);
            ir_expression *const r0C0B = bit_and(r0C0A, body.constant(int(31)));
            ir_expression *const r0C0C = lshift(r0BEF, r0C0B);
            ir_expression *const r0C0D = nequal(r0C0C, body.constant(0u));
            ir_expression *const r0C0E = expr(ir_unop_b2i, r0C0D);
            ir_expression *const r0C0F = expr(ir_unop_i2u, r0C0E);
            ir_expression *const r0C10 = bit_or(r0C09, r0C0F);
            ir_expression *const r0C11 = nequal(r0BEF, body.constant(0u));
            ir_expression *const r0C12 = expr(ir_unop_b2i, r0C11);
            ir_expression *const r0C13 = expr(ir_unop_i2u, r0C12);
            ir_expression *const r0C14 = expr(ir_triop_csel, r0C08, r0C10, r0C13);
            body.emit(assign(r0C06, expr(ir_triop_csel, r0C05, r0C14, r0BEF), 0x01));

            body.emit(assign(r0BF3, r0C06, 0x01));

            ir_expression *const r0C15 = expr(ir_unop_u2i, r0C06);
            ir_expression *const r0C16 = bit_and(r0C15, body.constant(int(127)));
            body.emit(assign(r0BF6, expr(ir_triop_csel, r0C05, r0C16, r0BF6), 0x01));

            body.emit(assign(r0BF2, expr(ir_triop_csel, r0C05, body.constant(int(0)), r0BF2), 0x01));


         body.instructions = f0BFB_parent_instructions;
         body.emit(f0BFB);

         /* END IF */


      body.instructions = f0BF8_parent_instructions;
      body.emit(f0BF8);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C17 = new(mem_ctx) ir_if(operand(r0BF4).val);
      exec_list *const f0C17_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C17->then_instructions;

         ir_expression *const r0C18 = add(r0BF3, body.constant(64u));
         body.emit(assign(r0BF3, rshift(r0C18, body.constant(int(7))), 0x01));

         ir_expression *const r0C19 = bit_xor(r0BF6, body.constant(int(64)));
         ir_expression *const r0C1A = equal(r0C19, body.constant(int(0)));
         ir_expression *const r0C1B = expr(ir_unop_b2i, r0C1A);
         ir_expression *const r0C1C = expr(ir_unop_i2u, r0C1B);
         ir_expression *const r0C1D = expr(ir_unop_bit_not, r0C1C);
         body.emit(assign(r0BF3, bit_and(r0BF3, r0C1D), 0x01));

         ir_expression *const r0C1E = lshift(r0BD7, body.constant(int(31)));
         ir_expression *const r0C1F = equal(r0BF3, body.constant(0u));
         ir_expression *const r0C20 = expr(ir_triop_csel, r0C1F, body.constant(int(0)), r0BF2);
         ir_expression *const r0C21 = expr(ir_unop_i2u, r0C20);
         ir_expression *const r0C22 = lshift(r0C21, body.constant(int(23)));
         ir_expression *const r0C23 = add(r0C1E, r0C22);
         ir_expression *const r0C24 = add(r0C23, r0BF3);
         body.emit(assign(r0BF5, expr(ir_unop_bitcast_u2f, r0C24), 0x01));

         body.emit(assign(r0BF4, body.constant(false), 0x01));


      body.instructions = f0C17_parent_instructions;
      body.emit(f0C17);

      /* END IF */

      body.emit(assign(r0BD2, r0BF5, 0x01));


   body.instructions = f0BD8_parent_instructions;
   body.emit(f0BD8);

   /* END IF */

   ir_variable *const r0C25 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C25, body.constant(true), 0x01));

   ir_variable *const r0C26 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C27 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C27);
   ir_variable *const r0C28 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C28);
   ir_variable *const r0C29 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C29);
   ir_variable *const r0C2A = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C2B = expr(ir_unop_rcp, r0BD2);
   body.emit(assign(r0C2A, expr(ir_unop_bitcast_f2u, r0C2B), 0x01));

   ir_variable *const r0C2C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C2C, bit_and(r0C2A, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C29, r0C2C, 0x01));

   ir_variable *const r0C2D = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C2E = rshift(r0C2A, body.constant(int(23)));
   ir_expression *const r0C2F = bit_and(r0C2E, body.constant(255u));
   body.emit(assign(r0C2D, expr(ir_unop_u2i, r0C2F), 0x01));

   body.emit(assign(r0C28, r0C2D, 0x01));

   body.emit(assign(r0C27, rshift(r0C2A, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C31 = equal(r0C2D, body.constant(int(255)));
   ir_if *f0C30 = new(mem_ctx) ir_if(operand(r0C31).val);
   exec_list *const f0C30_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C30->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C33 = nequal(r0C2C, body.constant(0u));
      ir_if *f0C32 = new(mem_ctx) ir_if(operand(r0C33).val);
      exec_list *const f0C32_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C32->then_instructions;

         ir_variable *const r0C34 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C34, lshift(r0C2A, body.constant(int(9))), 0x01));

         ir_variable *const r0C35 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C36 = lshift(r0C34, body.constant(int(20)));
         body.emit(assign(r0C35, bit_or(r0C36, body.constant(0u)), 0x01));

         ir_expression *const r0C37 = rshift(r0C34, body.constant(int(12)));
         ir_expression *const r0C38 = lshift(r0C27, body.constant(int(31)));
         ir_expression *const r0C39 = bit_or(r0C38, body.constant(2146959360u));
         body.emit(assign(r0C35, bit_or(r0C37, r0C39), 0x02));

         body.emit(assign(r0C26, r0C35, 0x03));

         body.emit(assign(r0C25, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C32->else_instructions;

         ir_variable *const r0C3A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C3A);
         ir_expression *const r0C3B = lshift(r0C27, body.constant(int(31)));
         body.emit(assign(r0C3A, add(r0C3B, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C3A, body.constant(0u), 0x01));

         body.emit(assign(r0C26, r0C3A, 0x03));

         body.emit(assign(r0C25, body.constant(false), 0x01));


      body.instructions = f0C32_parent_instructions;
      body.emit(f0C32);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C30->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C3D = equal(r0C2D, body.constant(int(0)));
      ir_if *f0C3C = new(mem_ctx) ir_if(operand(r0C3D).val);
      exec_list *const f0C3C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C3C->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C3F = equal(r0C2C, body.constant(0u));
         ir_if *f0C3E = new(mem_ctx) ir_if(operand(r0C3F).val);
         exec_list *const f0C3E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C3E->then_instructions;

            ir_variable *const r0C40 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C40);
            body.emit(assign(r0C40, lshift(r0C27, body.constant(int(31))), 0x02));

            body.emit(assign(r0C40, body.constant(0u), 0x01));

            body.emit(assign(r0C26, r0C40, 0x03));

            body.emit(assign(r0C25, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C3E->else_instructions;

            ir_variable *const r0C41 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0C42 = equal(r0C2C, body.constant(0u));
            ir_expression *const r0C43 = expr(ir_unop_find_msb, r0C2C);
            ir_expression *const r0C44 = sub(body.constant(int(31)), r0C43);
            ir_expression *const r0C45 = expr(ir_triop_csel, r0C42, body.constant(int(32)), r0C44);
            body.emit(assign(r0C41, add(r0C45, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C29, lshift(r0C2C, r0C41), 0x01));

            body.emit(assign(r0C28, sub(body.constant(int(1)), r0C41), 0x01));

            body.emit(assign(r0C28, add(r0C28, body.constant(int(-1))), 0x01));


         body.instructions = f0C3E_parent_instructions;
         body.emit(f0C3E);

         /* END IF */


      body.instructions = f0C3C_parent_instructions;
      body.emit(f0C3C);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C46 = new(mem_ctx) ir_if(operand(r0C25).val);
      exec_list *const f0C46_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C46->then_instructions;

         ir_variable *const r0C47 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C47);
         ir_expression *const r0C48 = lshift(r0C27, body.constant(int(31)));
         ir_expression *const r0C49 = add(r0C28, body.constant(int(896)));
         ir_expression *const r0C4A = expr(ir_unop_i2u, r0C49);
         ir_expression *const r0C4B = lshift(r0C4A, body.constant(int(20)));
         ir_expression *const r0C4C = add(r0C48, r0C4B);
         ir_expression *const r0C4D = rshift(r0C29, body.constant(int(3)));
         body.emit(assign(r0C47, add(r0C4C, r0C4D), 0x02));

         ir_expression *const r0C4E = lshift(r0C29, body.constant(int(29)));
         body.emit(assign(r0C47, bit_or(r0C4E, body.constant(0u)), 0x01));

         body.emit(assign(r0C26, r0C47, 0x03));

         body.emit(assign(r0C25, body.constant(false), 0x01));


      body.instructions = f0C46_parent_instructions;
      body.emit(f0C46);

      /* END IF */


   body.instructions = f0C30_parent_instructions;
   body.emit(f0C30);

   /* END IF */

   body.emit(ret(r0C26));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
