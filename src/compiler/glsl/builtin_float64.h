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

   ir_variable *const r009B = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r009C = less(r0095, body.constant(int(32)));
   ir_expression *const r009D = rshift(r0093, r0095);
   ir_expression *const r009E = equal(r0095, body.constant(int(0)));
   ir_expression *const r009F = expr(ir_triop_csel, r009E, r0093, body.constant(0u));
   body.emit(assign(r009B, expr(ir_triop_csel, r009C, r009D, r009F), 0x01));

   /* IF CONDITION */
   ir_expression *const r00A1 = equal(r0095, body.constant(int(0)));
   ir_if *f00A0 = new(mem_ctx) ir_if(operand(r00A1).val);
   exec_list *const f00A0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00A0->then_instructions;

      body.emit(assign(r0098, r0094, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00A0->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00A3 = less(r0095, body.constant(int(32)));
      ir_if *f00A2 = new(mem_ctx) ir_if(operand(r00A3).val);
      exec_list *const f00A2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00A2->then_instructions;

         ir_expression *const r00A4 = lshift(r0093, r0099);
         ir_expression *const r00A5 = rshift(r0094, r0095);
         ir_expression *const r00A6 = bit_or(r00A4, r00A5);
         ir_expression *const r00A7 = lshift(r0094, r0099);
         ir_expression *const r00A8 = nequal(r00A7, body.constant(0u));
         ir_expression *const r00A9 = expr(ir_unop_b2i, r00A8);
         ir_expression *const r00AA = expr(ir_unop_i2u, r00A9);
         body.emit(assign(r0098, bit_or(r00A6, r00AA), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00A2->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00AC = equal(r0095, body.constant(int(32)));
         ir_if *f00AB = new(mem_ctx) ir_if(operand(r00AC).val);
         exec_list *const f00AB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00AB->then_instructions;

            ir_expression *const r00AD = nequal(r0094, body.constant(0u));
            ir_expression *const r00AE = expr(ir_unop_b2i, r00AD);
            ir_expression *const r00AF = expr(ir_unop_i2u, r00AE);
            body.emit(assign(r0098, bit_or(r0093, r00AF), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00AB->else_instructions;

            /* IF CONDITION */
            ir_expression *const r00B1 = less(r0095, body.constant(int(64)));
            ir_if *f00B0 = new(mem_ctx) ir_if(operand(r00B1).val);
            exec_list *const f00B0_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f00B0->then_instructions;

               ir_expression *const r00B2 = bit_and(r0095, body.constant(int(31)));
               ir_expression *const r00B3 = rshift(r0093, r00B2);
               ir_expression *const r00B4 = lshift(r0093, r0099);
               ir_expression *const r00B5 = bit_or(r00B4, r0094);
               ir_expression *const r00B6 = nequal(r00B5, body.constant(0u));
               ir_expression *const r00B7 = expr(ir_unop_b2i, r00B6);
               ir_expression *const r00B8 = expr(ir_unop_i2u, r00B7);
               body.emit(assign(r0098, bit_or(r00B3, r00B8), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f00B0->else_instructions;

               ir_expression *const r00B9 = bit_or(r0093, r0094);
               ir_expression *const r00BA = nequal(r00B9, body.constant(0u));
               ir_expression *const r00BB = expr(ir_unop_b2i, r00BA);
               body.emit(assign(r0098, expr(ir_unop_i2u, r00BB), 0x01));


            body.instructions = f00B0_parent_instructions;
            body.emit(f00B0);

            /* END IF */


         body.instructions = f00AB_parent_instructions;
         body.emit(f00AB);

         /* END IF */


      body.instructions = f00A2_parent_instructions;
      body.emit(f00A2);

      /* END IF */


   body.instructions = f00A0_parent_instructions;
   body.emit(f00A0);

   /* END IF */

   body.emit(assign(r0097, r0098, 0x01));

   body.emit(assign(r0096, r009B, 0x01));

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

   ir_variable *const r00BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00BC);
   ir_variable *const r00BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00BD);
   ir_variable *const r00BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r00BE);
   ir_variable *const r00BF = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00BF);
   ir_variable *const r00C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C0);
   ir_variable *const r00C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C1);
   ir_variable *const r00C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C2);
   ir_variable *const r00C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
   body.emit(r00C3);
   ir_variable *const r00C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r00C4);
   ir_variable *const r00C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r00C5);
   ir_variable *const r00C6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r00C7 = neg(r00BF);
   body.emit(assign(r00C6, bit_and(r00C7, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00C9 = equal(r00BF, body.constant(int(0)));
   ir_if *f00C8 = new(mem_ctx) ir_if(operand(r00C9).val);
   exec_list *const f00C8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00C8->then_instructions;

      body.emit(assign(r00C3, r00BE, 0x01));

      body.emit(assign(r00C4, r00BD, 0x01));

      body.emit(assign(r00C5, r00BC, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00C8->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00CB = less(r00BF, body.constant(int(32)));
      ir_if *f00CA = new(mem_ctx) ir_if(operand(r00CB).val);
      exec_list *const f00CA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00CA->then_instructions;

         body.emit(assign(r00C3, lshift(r00BD, r00C6), 0x01));

         ir_expression *const r00CC = lshift(r00BC, r00C6);
         ir_expression *const r00CD = rshift(r00BD, r00BF);
         body.emit(assign(r00C4, bit_or(r00CC, r00CD), 0x01));

         body.emit(assign(r00C5, rshift(r00BC, r00BF), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00CA->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00CF = equal(r00BF, body.constant(int(32)));
         ir_if *f00CE = new(mem_ctx) ir_if(operand(r00CF).val);
         exec_list *const f00CE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00CE->then_instructions;

            body.emit(assign(r00C3, r00BD, 0x01));

            body.emit(assign(r00C4, r00BC, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00CE->else_instructions;

            body.emit(assign(r00BE, bit_or(r00BE, r00BD), 0x01));

            ir_expression *const r00D0 = less(r00BF, body.constant(int(64)));
            ir_expression *const r00D1 = lshift(r00BC, r00C6);
            ir_expression *const r00D2 = equal(r00BF, body.constant(int(64)));
            ir_expression *const r00D3 = nequal(r00BC, body.constant(0u));
            ir_expression *const r00D4 = expr(ir_unop_b2i, r00D3);
            ir_expression *const r00D5 = expr(ir_unop_i2u, r00D4);
            ir_expression *const r00D6 = expr(ir_triop_csel, r00D2, r00BC, r00D5);
            body.emit(assign(r00C3, expr(ir_triop_csel, r00D0, r00D1, r00D6), 0x01));

            ir_expression *const r00D7 = less(r00BF, body.constant(int(64)));
            ir_expression *const r00D8 = bit_and(r00BF, body.constant(int(31)));
            ir_expression *const r00D9 = rshift(r00BC, r00D8);
            body.emit(assign(r00C4, expr(ir_triop_csel, r00D7, r00D9, body.constant(0u)), 0x01));


         body.instructions = f00CE_parent_instructions;
         body.emit(f00CE);

         /* END IF */

         body.emit(assign(r00C5, body.constant(0u), 0x01));


      body.instructions = f00CA_parent_instructions;
      body.emit(f00CA);

      /* END IF */

      ir_expression *const r00DA = nequal(r00BE, body.constant(0u));
      ir_expression *const r00DB = expr(ir_unop_b2i, r00DA);
      ir_expression *const r00DC = expr(ir_unop_i2u, r00DB);
      body.emit(assign(r00C3, bit_or(r00C3, r00DC), 0x01));


   body.instructions = f00C8_parent_instructions;
   body.emit(f00C8);

   /* END IF */

   body.emit(assign(r00C2, r00C3, 0x01));

   body.emit(assign(r00C1, r00C4, 0x01));

   body.emit(assign(r00C0, r00C5, 0x01));

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

   ir_variable *const r00DD = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00DD);
   ir_variable *const r00DE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00DE);
   ir_variable *const r00DF = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00DF);
   ir_variable *const r00E0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00E0);
   ir_variable *const r00E1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00E1);
   body.emit(assign(r00E1, lshift(r00DE, r00DF), 0x01));

   ir_expression *const r00E2 = equal(r00DF, body.constant(int(0)));
   ir_expression *const r00E3 = lshift(r00DD, r00DF);
   ir_expression *const r00E4 = neg(r00DF);
   ir_expression *const r00E5 = bit_and(r00E4, body.constant(int(31)));
   ir_expression *const r00E6 = rshift(r00DE, r00E5);
   ir_expression *const r00E7 = bit_or(r00E3, r00E6);
   body.emit(assign(r00E0, expr(ir_triop_csel, r00E2, r00DD, r00E7), 0x01));

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

   ir_variable *const r00E8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00E8);
   ir_variable *const r00E9 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00E9);
   ir_variable *const r00EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00EA);
   ir_variable *const r00EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00EB);
   ir_variable *const r00EC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
   body.emit(r00EC);
   ir_expression *const r00ED = lshift(r00E8, body.constant(int(31)));
   ir_expression *const r00EE = expr(ir_unop_i2u, r00E9);
   ir_expression *const r00EF = lshift(r00EE, body.constant(int(20)));
   ir_expression *const r00F0 = add(r00ED, r00EF);
   body.emit(assign(r00EC, add(r00F0, r00EA), 0x02));

   body.emit(assign(r00EC, r00EB, 0x01));

   body.emit(ret(r00EC));

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

   ir_variable *const r00F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00F1);
   ir_variable *const r00F2 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00F2);
   ir_variable *const r00F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00F3);
   ir_variable *const r00F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00F4);
   ir_variable *const r00F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_function_in);
   sig_parameters.push_tail(r00F5);
   ir_variable *const r00F6 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r00F6, body.constant(true), 0x01));

   ir_variable *const r00F7 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r00F8 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r00F8);
   ir_expression *const r00F9 = expr(ir_unop_u2i, r00F5);
   body.emit(assign(r00F8, less(r00F9, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00FB = gequal(r00F2, body.constant(int(2045)));
   ir_if *f00FA = new(mem_ctx) ir_if(operand(r00FB).val);
   exec_list *const f00FA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00FA->then_instructions;

      /* IF CONDITION */
      ir_expression *const r00FD = less(body.constant(int(2045)), r00F2);
      ir_expression *const r00FE = equal(r00F2, body.constant(int(2045)));
      ir_expression *const r00FF = equal(body.constant(2097151u), r00F3);
      ir_expression *const r0100 = equal(body.constant(4294967295u), r00F4);
      ir_expression *const r0101 = logic_and(r00FF, r0100);
      ir_expression *const r0102 = logic_and(r00FE, r0101);
      ir_expression *const r0103 = logic_and(r0102, r00F8);
      ir_expression *const r0104 = logic_or(r00FD, r0103);
      ir_if *f00FC = new(mem_ctx) ir_if(operand(r0104).val);
      exec_list *const f00FC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00FC->then_instructions;

         ir_variable *const r0105 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0105);
         ir_expression *const r0106 = lshift(r00F1, body.constant(int(31)));
         body.emit(assign(r0105, add(r0106, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0105, body.constant(0u), 0x01));

         body.emit(assign(r00F7, r0105, 0x03));

         body.emit(assign(r00F6, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00FC->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0108 = less(r00F2, body.constant(int(0)));
         ir_if *f0107 = new(mem_ctx) ir_if(operand(r0108).val);
         exec_list *const f0107_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0107->then_instructions;

            ir_variable *const r0109 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0109, r00F5, 0x01));

            ir_variable *const r010A = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r010A, neg(r00F2), 0x01));

            ir_variable *const r010B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r010B);
            ir_variable *const r010C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r010C);
            ir_variable *const r010D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r010D);
            ir_variable *const r010E = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r010F = neg(r010A);
            body.emit(assign(r010E, bit_and(r010F, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0111 = equal(r010A, body.constant(int(0)));
            ir_if *f0110 = new(mem_ctx) ir_if(operand(r0111).val);
            exec_list *const f0110_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0110->then_instructions;

               body.emit(assign(r010B, r00F5, 0x01));

               body.emit(assign(r010C, r00F4, 0x01));

               body.emit(assign(r010D, r00F3, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0110->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0113 = less(r010A, body.constant(int(32)));
               ir_if *f0112 = new(mem_ctx) ir_if(operand(r0113).val);
               exec_list *const f0112_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0112->then_instructions;

                  body.emit(assign(r010B, lshift(r00F4, r010E), 0x01));

                  ir_expression *const r0114 = lshift(r00F3, r010E);
                  ir_expression *const r0115 = rshift(r00F4, r010A);
                  body.emit(assign(r010C, bit_or(r0114, r0115), 0x01));

                  body.emit(assign(r010D, rshift(r00F3, r010A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0112->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0117 = equal(r010A, body.constant(int(32)));
                  ir_if *f0116 = new(mem_ctx) ir_if(operand(r0117).val);
                  exec_list *const f0116_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0116->then_instructions;

                     body.emit(assign(r010B, r00F4, 0x01));

                     body.emit(assign(r010C, r00F3, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0116->else_instructions;

                     body.emit(assign(r0109, bit_or(r00F5, r00F4), 0x01));

                     ir_expression *const r0118 = less(r010A, body.constant(int(64)));
                     ir_expression *const r0119 = lshift(r00F3, r010E);
                     ir_expression *const r011A = equal(r010A, body.constant(int(64)));
                     ir_expression *const r011B = nequal(r00F3, body.constant(0u));
                     ir_expression *const r011C = expr(ir_unop_b2i, r011B);
                     ir_expression *const r011D = expr(ir_unop_i2u, r011C);
                     ir_expression *const r011E = expr(ir_triop_csel, r011A, r00F3, r011D);
                     body.emit(assign(r010B, expr(ir_triop_csel, r0118, r0119, r011E), 0x01));

                     ir_expression *const r011F = less(r010A, body.constant(int(64)));
                     ir_expression *const r0120 = bit_and(r010A, body.constant(int(31)));
                     ir_expression *const r0121 = rshift(r00F3, r0120);
                     body.emit(assign(r010C, expr(ir_triop_csel, r011F, r0121, body.constant(0u)), 0x01));


                  body.instructions = f0116_parent_instructions;
                  body.emit(f0116);

                  /* END IF */

                  body.emit(assign(r010D, body.constant(0u), 0x01));


               body.instructions = f0112_parent_instructions;
               body.emit(f0112);

               /* END IF */

               ir_expression *const r0122 = nequal(r0109, body.constant(0u));
               ir_expression *const r0123 = expr(ir_unop_b2i, r0122);
               ir_expression *const r0124 = expr(ir_unop_i2u, r0123);
               body.emit(assign(r010B, bit_or(r010B, r0124), 0x01));


            body.instructions = f0110_parent_instructions;
            body.emit(f0110);

            /* END IF */

            body.emit(assign(r00F3, r010D, 0x01));

            body.emit(assign(r00F4, r010C, 0x01));

            body.emit(assign(r00F5, r010B, 0x01));

            body.emit(assign(r00F2, body.constant(int(0)), 0x01));

            body.emit(assign(r00F8, less(r010B, body.constant(0u)), 0x01));


         body.instructions = f0107_parent_instructions;
         body.emit(f0107);

         /* END IF */


      body.instructions = f00FC_parent_instructions;
      body.emit(f00FC);

      /* END IF */


   body.instructions = f00FA_parent_instructions;
   body.emit(f00FA);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0125 = new(mem_ctx) ir_if(operand(r00F6).val);
   exec_list *const f0125_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0125->then_instructions;

      /* IF CONDITION */
      ir_if *f0126 = new(mem_ctx) ir_if(operand(r00F8).val);
      exec_list *const f0126_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0126->then_instructions;

         ir_variable *const r0127 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0127, add(r00F4, body.constant(1u)), 0x01));

         ir_expression *const r0128 = less(r0127, r00F4);
         ir_expression *const r0129 = expr(ir_unop_b2i, r0128);
         ir_expression *const r012A = expr(ir_unop_i2u, r0129);
         body.emit(assign(r00F3, add(r00F3, r012A), 0x01));

         ir_expression *const r012B = equal(r00F5, body.constant(0u));
         ir_expression *const r012C = expr(ir_unop_b2i, r012B);
         ir_expression *const r012D = expr(ir_unop_i2u, r012C);
         ir_expression *const r012E = add(r00F5, r012D);
         ir_expression *const r012F = bit_and(r012E, body.constant(1u));
         ir_expression *const r0130 = expr(ir_unop_bit_not, r012F);
         body.emit(assign(r00F4, bit_and(r0127, r0130), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0126->else_instructions;

         ir_expression *const r0131 = bit_or(r00F3, r00F4);
         ir_expression *const r0132 = equal(r0131, body.constant(0u));
         body.emit(assign(r00F2, expr(ir_triop_csel, r0132, body.constant(int(0)), r00F2), 0x01));


      body.instructions = f0126_parent_instructions;
      body.emit(f0126);

      /* END IF */

      ir_variable *const r0133 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0133);
      ir_expression *const r0134 = lshift(r00F1, body.constant(int(31)));
      ir_expression *const r0135 = expr(ir_unop_i2u, r00F2);
      ir_expression *const r0136 = lshift(r0135, body.constant(int(20)));
      ir_expression *const r0137 = add(r0134, r0136);
      body.emit(assign(r0133, add(r0137, r00F3), 0x02));

      body.emit(assign(r0133, r00F4, 0x01));

      body.emit(assign(r00F7, r0133, 0x03));

      body.emit(assign(r00F6, body.constant(false), 0x01));


   body.instructions = f0125_parent_instructions;
   body.emit(f0125);

   /* END IF */

   body.emit(ret(r00F7));

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

   ir_variable *const r0138 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0138);
   ir_variable *const r0139 = body.make_temp(glsl_type::int_type, "mix_retval");
   ir_expression *const r013A = equal(r0138, body.constant(0u));
   ir_expression *const r013B = expr(ir_unop_find_msb, r0138);
   ir_expression *const r013C = sub(body.constant(int(31)), r013B);
   body.emit(assign(r0139, expr(ir_triop_csel, r013A, body.constant(int(32)), r013C), 0x01));

   body.emit(ret(r0139));

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

   ir_variable *const r013D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r013D);
   ir_variable *const r013E = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r013E);
   ir_variable *const r013F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r013F);
   ir_variable *const r0140 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0140);
   ir_variable *const r0141 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0141);
   ir_variable *const r0142 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0142);
   ir_expression *const r0143 = equal(r013F, body.constant(0u));
   ir_expression *const r0144 = add(r013E, body.constant(int(-32)));
   body.emit(assign(r013E, expr(ir_triop_csel, r0143, r0144, r013E), 0x01));

   ir_variable *const r0145 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r0146 = equal(r013F, body.constant(0u));
   body.emit(assign(r0145, expr(ir_triop_csel, r0146, body.constant(0u), r0140), 0x01));

   body.emit(assign(r0140, r0145, 0x01));

   ir_variable *const r0147 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r0148 = equal(r013F, body.constant(0u));
   body.emit(assign(r0147, expr(ir_triop_csel, r0148, r0145, r013F), 0x01));

   body.emit(assign(r013F, r0147, 0x01));

   ir_expression *const r0149 = equal(r0147, body.constant(0u));
   ir_expression *const r014A = expr(ir_unop_find_msb, r0147);
   ir_expression *const r014B = sub(body.constant(int(31)), r014A);
   ir_expression *const r014C = expr(ir_triop_csel, r0149, body.constant(int(32)), r014B);
   body.emit(assign(r0142, add(r014C, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r014E = gequal(r0142, body.constant(int(0)));
   ir_if *f014D = new(mem_ctx) ir_if(operand(r014E).val);
   exec_list *const f014D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f014D->then_instructions;

      body.emit(assign(r0141, body.constant(0u), 0x01));

      ir_expression *const r014F = equal(r0142, body.constant(int(0)));
      ir_expression *const r0150 = lshift(r0147, r0142);
      ir_expression *const r0151 = neg(r0142);
      ir_expression *const r0152 = bit_and(r0151, body.constant(int(31)));
      ir_expression *const r0153 = rshift(r0145, r0152);
      ir_expression *const r0154 = bit_or(r0150, r0153);
      body.emit(assign(r013F, expr(ir_triop_csel, r014F, r0147, r0154), 0x01));

      body.emit(assign(r0140, lshift(r0145, r0142), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f014D->else_instructions;

      ir_variable *const r0155 = body.make_temp(glsl_type::uint_type, "a2");
      body.emit(assign(r0155, body.constant(0u), 0x01));

      ir_variable *const r0156 = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r0156, neg(r0142), 0x01));

      ir_variable *const r0157 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
      body.emit(r0157);
      ir_variable *const r0158 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0158);
      ir_variable *const r0159 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0159);
      ir_variable *const r015A = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r015B = neg(r0156);
      body.emit(assign(r015A, bit_and(r015B, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r015D = equal(r0156, body.constant(int(0)));
      ir_if *f015C = new(mem_ctx) ir_if(operand(r015D).val);
      exec_list *const f015C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f015C->then_instructions;

         body.emit(assign(r0157, r0155, 0x01));

         body.emit(assign(r0158, r0140, 0x01));

         body.emit(assign(r0159, r013F, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f015C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r015F = less(r0156, body.constant(int(32)));
         ir_if *f015E = new(mem_ctx) ir_if(operand(r015F).val);
         exec_list *const f015E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f015E->then_instructions;

            body.emit(assign(r0157, lshift(r0140, r015A), 0x01));

            ir_expression *const r0160 = lshift(r013F, r015A);
            ir_expression *const r0161 = rshift(r0140, r0156);
            body.emit(assign(r0158, bit_or(r0160, r0161), 0x01));

            body.emit(assign(r0159, rshift(r013F, r0156), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f015E->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0163 = equal(r0156, body.constant(int(32)));
            ir_if *f0162 = new(mem_ctx) ir_if(operand(r0163).val);
            exec_list *const f0162_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0162->then_instructions;

               body.emit(assign(r0157, r0140, 0x01));

               body.emit(assign(r0158, r013F, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0162->else_instructions;

               body.emit(assign(r0155, bit_or(body.constant(0u), r0140), 0x01));

               ir_expression *const r0164 = less(r0156, body.constant(int(64)));
               ir_expression *const r0165 = lshift(r013F, r015A);
               ir_expression *const r0166 = equal(r0156, body.constant(int(64)));
               ir_expression *const r0167 = nequal(r013F, body.constant(0u));
               ir_expression *const r0168 = expr(ir_unop_b2i, r0167);
               ir_expression *const r0169 = expr(ir_unop_i2u, r0168);
               ir_expression *const r016A = expr(ir_triop_csel, r0166, r013F, r0169);
               body.emit(assign(r0157, expr(ir_triop_csel, r0164, r0165, r016A), 0x01));

               ir_expression *const r016B = less(r0156, body.constant(int(64)));
               ir_expression *const r016C = bit_and(r0156, body.constant(int(31)));
               ir_expression *const r016D = rshift(r013F, r016C);
               body.emit(assign(r0158, expr(ir_triop_csel, r016B, r016D, body.constant(0u)), 0x01));


            body.instructions = f0162_parent_instructions;
            body.emit(f0162);

            /* END IF */

            body.emit(assign(r0159, body.constant(0u), 0x01));


         body.instructions = f015E_parent_instructions;
         body.emit(f015E);

         /* END IF */

         ir_expression *const r016E = nequal(r0155, body.constant(0u));
         ir_expression *const r016F = expr(ir_unop_b2i, r016E);
         ir_expression *const r0170 = expr(ir_unop_i2u, r016F);
         body.emit(assign(r0157, bit_or(r0157, r0170), 0x01));


      body.instructions = f015C_parent_instructions;
      body.emit(f015C);

      /* END IF */

      body.emit(assign(r013F, r0159, 0x01));

      body.emit(assign(r0140, r0158, 0x01));

      body.emit(assign(r0141, r0157, 0x01));


   body.instructions = f014D_parent_instructions;
   body.emit(f014D);

   /* END IF */

   body.emit(assign(r013E, sub(r013E, r0142), 0x01));

   ir_variable *const r0171 = body.make_temp(glsl_type::int_type, "zExp");
   body.emit(assign(r0171, r013E, 0x01));

   ir_variable *const r0172 = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r0172, r013F, 0x01));

   ir_variable *const r0173 = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r0173, r0140, 0x01));

   ir_variable *const r0174 = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r0174, r0141, 0x01));

   ir_variable *const r0175 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0175, body.constant(true), 0x01));

   ir_variable *const r0176 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0177 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r0177);
   ir_expression *const r0178 = expr(ir_unop_u2i, r0141);
   body.emit(assign(r0177, less(r0178, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r017A = gequal(r013E, body.constant(int(2045)));
   ir_if *f0179 = new(mem_ctx) ir_if(operand(r017A).val);
   exec_list *const f0179_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0179->then_instructions;

      /* IF CONDITION */
      ir_expression *const r017C = less(body.constant(int(2045)), r013E);
      ir_expression *const r017D = equal(r013E, body.constant(int(2045)));
      ir_expression *const r017E = equal(body.constant(2097151u), r013F);
      ir_expression *const r017F = equal(body.constant(4294967295u), r0140);
      ir_expression *const r0180 = logic_and(r017E, r017F);
      ir_expression *const r0181 = logic_and(r017D, r0180);
      ir_expression *const r0182 = logic_and(r0181, r0177);
      ir_expression *const r0183 = logic_or(r017C, r0182);
      ir_if *f017B = new(mem_ctx) ir_if(operand(r0183).val);
      exec_list *const f017B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f017B->then_instructions;

         ir_variable *const r0184 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0184);
         ir_expression *const r0185 = lshift(r013D, body.constant(int(31)));
         body.emit(assign(r0184, add(r0185, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0184, body.constant(0u), 0x01));

         body.emit(assign(r0176, r0184, 0x03));

         body.emit(assign(r0175, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f017B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0187 = less(r013E, body.constant(int(0)));
         ir_if *f0186 = new(mem_ctx) ir_if(operand(r0187).val);
         exec_list *const f0186_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0186->then_instructions;

            ir_variable *const r0188 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0188, r0141, 0x01));

            ir_variable *const r0189 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r0189, neg(r013E), 0x01));

            ir_variable *const r018A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r018A);
            ir_variable *const r018B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r018B);
            ir_variable *const r018C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r018C);
            ir_variable *const r018D = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r018E = neg(r0189);
            body.emit(assign(r018D, bit_and(r018E, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0190 = equal(r0189, body.constant(int(0)));
            ir_if *f018F = new(mem_ctx) ir_if(operand(r0190).val);
            exec_list *const f018F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f018F->then_instructions;

               body.emit(assign(r018A, r0141, 0x01));

               body.emit(assign(r018B, r0140, 0x01));

               body.emit(assign(r018C, r013F, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f018F->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0192 = less(r0189, body.constant(int(32)));
               ir_if *f0191 = new(mem_ctx) ir_if(operand(r0192).val);
               exec_list *const f0191_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0191->then_instructions;

                  body.emit(assign(r018A, lshift(r0140, r018D), 0x01));

                  ir_expression *const r0193 = lshift(r013F, r018D);
                  ir_expression *const r0194 = rshift(r0140, r0189);
                  body.emit(assign(r018B, bit_or(r0193, r0194), 0x01));

                  body.emit(assign(r018C, rshift(r013F, r0189), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0191->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0196 = equal(r0189, body.constant(int(32)));
                  ir_if *f0195 = new(mem_ctx) ir_if(operand(r0196).val);
                  exec_list *const f0195_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0195->then_instructions;

                     body.emit(assign(r018A, r0140, 0x01));

                     body.emit(assign(r018B, r013F, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0195->else_instructions;

                     body.emit(assign(r0188, bit_or(r0141, r0140), 0x01));

                     ir_expression *const r0197 = less(r0189, body.constant(int(64)));
                     ir_expression *const r0198 = lshift(r013F, r018D);
                     ir_expression *const r0199 = equal(r0189, body.constant(int(64)));
                     ir_expression *const r019A = nequal(r013F, body.constant(0u));
                     ir_expression *const r019B = expr(ir_unop_b2i, r019A);
                     ir_expression *const r019C = expr(ir_unop_i2u, r019B);
                     ir_expression *const r019D = expr(ir_triop_csel, r0199, r013F, r019C);
                     body.emit(assign(r018A, expr(ir_triop_csel, r0197, r0198, r019D), 0x01));

                     ir_expression *const r019E = less(r0189, body.constant(int(64)));
                     ir_expression *const r019F = bit_and(r0189, body.constant(int(31)));
                     ir_expression *const r01A0 = rshift(r013F, r019F);
                     body.emit(assign(r018B, expr(ir_triop_csel, r019E, r01A0, body.constant(0u)), 0x01));


                  body.instructions = f0195_parent_instructions;
                  body.emit(f0195);

                  /* END IF */

                  body.emit(assign(r018C, body.constant(0u), 0x01));


               body.instructions = f0191_parent_instructions;
               body.emit(f0191);

               /* END IF */

               ir_expression *const r01A1 = nequal(r0188, body.constant(0u));
               ir_expression *const r01A2 = expr(ir_unop_b2i, r01A1);
               ir_expression *const r01A3 = expr(ir_unop_i2u, r01A2);
               body.emit(assign(r018A, bit_or(r018A, r01A3), 0x01));


            body.instructions = f018F_parent_instructions;
            body.emit(f018F);

            /* END IF */

            body.emit(assign(r0172, r018C, 0x01));

            body.emit(assign(r0173, r018B, 0x01));

            body.emit(assign(r0174, r018A, 0x01));

            body.emit(assign(r0171, body.constant(int(0)), 0x01));

            body.emit(assign(r0177, less(r018A, body.constant(0u)), 0x01));


         body.instructions = f0186_parent_instructions;
         body.emit(f0186);

         /* END IF */


      body.instructions = f017B_parent_instructions;
      body.emit(f017B);

      /* END IF */


   body.instructions = f0179_parent_instructions;
   body.emit(f0179);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01A4 = new(mem_ctx) ir_if(operand(r0175).val);
   exec_list *const f01A4_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01A4->then_instructions;

      /* IF CONDITION */
      ir_if *f01A5 = new(mem_ctx) ir_if(operand(r0177).val);
      exec_list *const f01A5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01A5->then_instructions;

         ir_variable *const r01A6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01A6, add(r0173, body.constant(1u)), 0x01));

         ir_expression *const r01A7 = less(r01A6, r0173);
         ir_expression *const r01A8 = expr(ir_unop_b2i, r01A7);
         ir_expression *const r01A9 = expr(ir_unop_i2u, r01A8);
         body.emit(assign(r0172, add(r0172, r01A9), 0x01));

         ir_expression *const r01AA = equal(r0174, body.constant(0u));
         ir_expression *const r01AB = expr(ir_unop_b2i, r01AA);
         ir_expression *const r01AC = expr(ir_unop_i2u, r01AB);
         ir_expression *const r01AD = add(r0174, r01AC);
         ir_expression *const r01AE = bit_and(r01AD, body.constant(1u));
         ir_expression *const r01AF = expr(ir_unop_bit_not, r01AE);
         body.emit(assign(r0173, bit_and(r01A6, r01AF), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01A5->else_instructions;

         ir_expression *const r01B0 = bit_or(r0172, r0173);
         ir_expression *const r01B1 = equal(r01B0, body.constant(0u));
         body.emit(assign(r0171, expr(ir_triop_csel, r01B1, body.constant(int(0)), r0171), 0x01));


      body.instructions = f01A5_parent_instructions;
      body.emit(f01A5);

      /* END IF */

      ir_variable *const r01B2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r01B2);
      ir_expression *const r01B3 = lshift(r013D, body.constant(int(31)));
      ir_expression *const r01B4 = expr(ir_unop_i2u, r0171);
      ir_expression *const r01B5 = lshift(r01B4, body.constant(int(20)));
      ir_expression *const r01B6 = add(r01B3, r01B5);
      body.emit(assign(r01B2, add(r01B6, r0172), 0x02));

      body.emit(assign(r01B2, r0173, 0x01));

      body.emit(assign(r0176, r01B2, 0x03));

      body.emit(assign(r0175, body.constant(false), 0x01));


   body.instructions = f01A4_parent_instructions;
   body.emit(f01A4);

   /* END IF */

   body.emit(ret(r0176));

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

   ir_variable *const r01B7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01B7);
   ir_variable *const r01B8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01B8);
   ir_variable *const r01B9 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01BA = lshift(swizzle_y(r01B7), body.constant(int(1)));
   ir_expression *const r01BB = gequal(r01BA, body.constant(4292870144u));
   ir_expression *const r01BC = nequal(swizzle_x(r01B7), body.constant(0u));
   ir_expression *const r01BD = bit_and(swizzle_y(r01B7), body.constant(1048575u));
   ir_expression *const r01BE = nequal(r01BD, body.constant(0u));
   ir_expression *const r01BF = logic_or(r01BC, r01BE);
   body.emit(assign(r01B9, logic_and(r01BB, r01BF), 0x01));

   ir_variable *const r01C0 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01C1 = lshift(swizzle_y(r01B8), body.constant(int(1)));
   ir_expression *const r01C2 = gequal(r01C1, body.constant(4292870144u));
   ir_expression *const r01C3 = nequal(swizzle_x(r01B8), body.constant(0u));
   ir_expression *const r01C4 = bit_and(swizzle_y(r01B8), body.constant(1048575u));
   ir_expression *const r01C5 = nequal(r01C4, body.constant(0u));
   ir_expression *const r01C6 = logic_or(r01C3, r01C5);
   body.emit(assign(r01C0, logic_and(r01C2, r01C6), 0x01));

   body.emit(assign(r01B7, bit_or(swizzle_y(r01B7), body.constant(524288u)), 0x02));

   body.emit(assign(r01B8, bit_or(swizzle_y(r01B8), body.constant(524288u)), 0x02));

   ir_variable *const r01C7 = body.make_temp(glsl_type::uvec2_type, "mix_retval");
   ir_swizzle *const r01C8 = swizzle(r01B9, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_swizzle *const r01C9 = swizzle(r01C0, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_expression *const r01CA = expr(ir_triop_csel, r01C9, r01B8, r01B7);
   body.emit(assign(r01C7, expr(ir_triop_csel, r01C8, r01CA, r01B8), 0x03));

   body.emit(ret(r01C7));

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

   ir_variable *const r01CB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01CB);
   ir_variable *const r01CC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01CC);
   ir_variable *const r01CD = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01CD, body.constant(true), 0x01));

   ir_variable *const r01CE = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01CF = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r01CF);
   ir_variable *const r01D0 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01D0, rshift(swizzle_y(r01CB), body.constant(int(31))), 0x01));

   body.emit(assign(r01CF, r01D0, 0x01));

   ir_variable *const r01D1 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01D1, rshift(swizzle_y(r01CC), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r01D3 = equal(r01D0, r01D1);
   ir_if *f01D2 = new(mem_ctx) ir_if(operand(r01D3).val);
   exec_list *const f01D2_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01D2->then_instructions;

      ir_variable *const r01D4 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r01D4);
      ir_variable *const r01D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r01D5);
      ir_variable *const r01D6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r01D6);
      ir_variable *const r01D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r01D7);
      ir_variable *const r01D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r01D8);
      ir_variable *const r01D9 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r01D9);
      ir_variable *const r01DA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r01DA);
      ir_variable *const r01DB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
      body.emit(r01DB);
      body.emit(assign(r01DB, body.constant(0u), 0x01));

      body.emit(assign(r01DA, body.constant(0u), 0x01));

      ir_variable *const r01DC = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01DC, swizzle_x(r01CB), 0x01));

      body.emit(assign(r01D8, r01DC, 0x01));

      ir_variable *const r01DD = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01DD, bit_and(swizzle_y(r01CB), body.constant(1048575u)), 0x01));

      body.emit(assign(r01D7, r01DD, 0x01));

      ir_variable *const r01DE = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01DE, swizzle_x(r01CC), 0x01));

      body.emit(assign(r01D6, r01DE, 0x01));

      ir_variable *const r01DF = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01DF, bit_and(swizzle_y(r01CC), body.constant(1048575u)), 0x01));

      body.emit(assign(r01D5, r01DF, 0x01));

      ir_variable *const r01E0 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r01E1 = rshift(swizzle_y(r01CB), body.constant(int(20)));
      ir_expression *const r01E2 = bit_and(r01E1, body.constant(2047u));
      body.emit(assign(r01E0, expr(ir_unop_u2i, r01E2), 0x01));

      ir_variable *const r01E3 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r01E4 = rshift(swizzle_y(r01CC), body.constant(int(20)));
      ir_expression *const r01E5 = bit_and(r01E4, body.constant(2047u));
      body.emit(assign(r01E3, expr(ir_unop_u2i, r01E5), 0x01));

      ir_variable *const r01E6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r01E6, sub(r01E0, r01E3), 0x01));

      body.emit(assign(r01D4, r01E6, 0x01));

      /* IF CONDITION */
      ir_expression *const r01E8 = less(body.constant(int(0)), r01E6);
      ir_if *f01E7 = new(mem_ctx) ir_if(operand(r01E8).val);
      exec_list *const f01E7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01E7->then_instructions;

         /* IF CONDITION */
         ir_expression *const r01EA = equal(r01E0, body.constant(int(2047)));
         ir_if *f01E9 = new(mem_ctx) ir_if(operand(r01EA).val);
         exec_list *const f01E9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01E9->then_instructions;

            /* IF CONDITION */
            ir_expression *const r01EC = bit_or(r01DD, swizzle_x(r01CB));
            ir_expression *const r01ED = nequal(r01EC, body.constant(0u));
            ir_if *f01EB = new(mem_ctx) ir_if(operand(r01ED).val);
            exec_list *const f01EB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01EB->then_instructions;

               ir_variable *const r01EE = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r01EE, swizzle_x(r01CB), 0x01));

               ir_variable *const r01EF = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r01EF, swizzle_x(r01CC), 0x01));

               body.emit(assign(r01EE, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r01EF, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r01F0 = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r01F1 = gequal(r01F0, body.constant(4292870144u));
               ir_expression *const r01F2 = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r01F3 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r01F4 = nequal(r01F3, body.constant(0u));
               ir_expression *const r01F5 = logic_or(r01F2, r01F4);
               ir_expression *const r01F6 = logic_and(r01F1, r01F5);
               ir_swizzle *const r01F7 = swizzle(r01F6, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r01F8 = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r01F9 = gequal(r01F8, body.constant(4292870144u));
               ir_expression *const r01FA = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r01FB = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r01FC = nequal(r01FB, body.constant(0u));
               ir_expression *const r01FD = logic_or(r01FA, r01FC);
               ir_expression *const r01FE = logic_and(r01F9, r01FD);
               ir_swizzle *const r01FF = swizzle(r01FE, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0200 = expr(ir_triop_csel, r01FF, r01EF, r01EE);
               body.emit(assign(r01CE, expr(ir_triop_csel, r01F7, r0200, r01EF), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01EB->else_instructions;

               body.emit(assign(r01CE, r01CB, 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


            body.instructions = f01EB_parent_instructions;
            body.emit(f01EB);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f01E9->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0202 = equal(r01E3, body.constant(int(0)));
            ir_if *f0201 = new(mem_ctx) ir_if(operand(r0202).val);
            exec_list *const f0201_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0201->then_instructions;

               body.emit(assign(r01D4, add(r01E6, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0201->else_instructions;

               body.emit(assign(r01D5, bit_or(r01DF, body.constant(1048576u)), 0x01));


            body.instructions = f0201_parent_instructions;
            body.emit(f0201);

            /* END IF */

            ir_variable *const r0203 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0203, body.constant(0u), 0x01));

            ir_variable *const r0204 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0204);
            ir_variable *const r0205 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0205);
            ir_variable *const r0206 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0206);
            ir_variable *const r0207 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0208 = neg(r01D4);
            body.emit(assign(r0207, bit_and(r0208, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r020A = equal(r01D4, body.constant(int(0)));
            ir_if *f0209 = new(mem_ctx) ir_if(operand(r020A).val);
            exec_list *const f0209_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0209->then_instructions;

               body.emit(assign(r0204, r0203, 0x01));

               body.emit(assign(r0205, r01DE, 0x01));

               body.emit(assign(r0206, r01D5, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0209->else_instructions;

               /* IF CONDITION */
               ir_expression *const r020C = less(r01D4, body.constant(int(32)));
               ir_if *f020B = new(mem_ctx) ir_if(operand(r020C).val);
               exec_list *const f020B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f020B->then_instructions;

                  body.emit(assign(r0204, lshift(swizzle_x(r01CC), r0207), 0x01));

                  ir_expression *const r020D = lshift(r01D5, r0207);
                  ir_expression *const r020E = rshift(swizzle_x(r01CC), r01D4);
                  body.emit(assign(r0205, bit_or(r020D, r020E), 0x01));

                  body.emit(assign(r0206, rshift(r01D5, r01D4), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f020B->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0210 = equal(r01D4, body.constant(int(32)));
                  ir_if *f020F = new(mem_ctx) ir_if(operand(r0210).val);
                  exec_list *const f020F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f020F->then_instructions;

                     body.emit(assign(r0204, r01DE, 0x01));

                     body.emit(assign(r0205, r01D5, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f020F->else_instructions;

                     body.emit(assign(r0203, bit_or(body.constant(0u), swizzle_x(r01CC)), 0x01));

                     ir_expression *const r0211 = less(r01D4, body.constant(int(64)));
                     ir_expression *const r0212 = lshift(r01D5, r0207);
                     ir_expression *const r0213 = equal(r01D4, body.constant(int(64)));
                     ir_expression *const r0214 = nequal(r01D5, body.constant(0u));
                     ir_expression *const r0215 = expr(ir_unop_b2i, r0214);
                     ir_expression *const r0216 = expr(ir_unop_i2u, r0215);
                     ir_expression *const r0217 = expr(ir_triop_csel, r0213, r01D5, r0216);
                     body.emit(assign(r0204, expr(ir_triop_csel, r0211, r0212, r0217), 0x01));

                     ir_expression *const r0218 = less(r01D4, body.constant(int(64)));
                     ir_expression *const r0219 = bit_and(r01D4, body.constant(int(31)));
                     ir_expression *const r021A = rshift(r01D5, r0219);
                     body.emit(assign(r0205, expr(ir_triop_csel, r0218, r021A, body.constant(0u)), 0x01));


                  body.instructions = f020F_parent_instructions;
                  body.emit(f020F);

                  /* END IF */

                  body.emit(assign(r0206, body.constant(0u), 0x01));


               body.instructions = f020B_parent_instructions;
               body.emit(f020B);

               /* END IF */

               ir_expression *const r021B = nequal(r0203, body.constant(0u));
               ir_expression *const r021C = expr(ir_unop_b2i, r021B);
               ir_expression *const r021D = expr(ir_unop_i2u, r021C);
               body.emit(assign(r0204, bit_or(r0204, r021D), 0x01));


            body.instructions = f0209_parent_instructions;
            body.emit(f0209);

            /* END IF */

            body.emit(assign(r01D5, r0206, 0x01));

            body.emit(assign(r01D6, r0205, 0x01));

            body.emit(assign(r01DA, r0204, 0x01));

            body.emit(assign(r01D9, r01E0, 0x01));


         body.instructions = f01E9_parent_instructions;
         body.emit(f01E9);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01E7->else_instructions;

         /* IF CONDITION */
         ir_expression *const r021F = less(r01D4, body.constant(int(0)));
         ir_if *f021E = new(mem_ctx) ir_if(operand(r021F).val);
         exec_list *const f021E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f021E->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0221 = equal(r01E3, body.constant(int(2047)));
            ir_if *f0220 = new(mem_ctx) ir_if(operand(r0221).val);
            exec_list *const f0220_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0220->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0223 = bit_or(r01D5, r01D6);
               ir_expression *const r0224 = nequal(r0223, body.constant(0u));
               ir_if *f0222 = new(mem_ctx) ir_if(operand(r0224).val);
               exec_list *const f0222_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0222->then_instructions;

                  ir_variable *const r0225 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0225, swizzle_x(r01CB), 0x01));

                  ir_variable *const r0226 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0226, swizzle_x(r01CC), 0x01));

                  body.emit(assign(r0225, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

                  body.emit(assign(r0226, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

                  ir_expression *const r0227 = lshift(swizzle_y(r01CB), body.constant(int(1)));
                  ir_expression *const r0228 = gequal(r0227, body.constant(4292870144u));
                  ir_expression *const r0229 = nequal(swizzle_x(r01CB), body.constant(0u));
                  ir_expression *const r022A = bit_and(swizzle_y(r01CB), body.constant(1048575u));
                  ir_expression *const r022B = nequal(r022A, body.constant(0u));
                  ir_expression *const r022C = logic_or(r0229, r022B);
                  ir_expression *const r022D = logic_and(r0228, r022C);
                  ir_swizzle *const r022E = swizzle(r022D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r022F = lshift(swizzle_y(r01CC), body.constant(int(1)));
                  ir_expression *const r0230 = gequal(r022F, body.constant(4292870144u));
                  ir_expression *const r0231 = nequal(swizzle_x(r01CC), body.constant(0u));
                  ir_expression *const r0232 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
                  ir_expression *const r0233 = nequal(r0232, body.constant(0u));
                  ir_expression *const r0234 = logic_or(r0231, r0233);
                  ir_expression *const r0235 = logic_and(r0230, r0234);
                  ir_swizzle *const r0236 = swizzle(r0235, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0237 = expr(ir_triop_csel, r0236, r0226, r0225);
                  body.emit(assign(r01CE, expr(ir_triop_csel, r022E, r0237, r0226), 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0222->else_instructions;

                  ir_variable *const r0238 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0238);
                  ir_expression *const r0239 = lshift(r01D0, body.constant(int(31)));
                  body.emit(assign(r0238, add(r0239, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0238, body.constant(0u), 0x01));

                  body.emit(assign(r01CE, r0238, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


               body.instructions = f0222_parent_instructions;
               body.emit(f0222);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0220->else_instructions;

               /* IF CONDITION */
               ir_expression *const r023B = equal(r01E0, body.constant(int(0)));
               ir_if *f023A = new(mem_ctx) ir_if(operand(r023B).val);
               exec_list *const f023A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f023A->then_instructions;

                  body.emit(assign(r01D4, add(r01D4, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f023A->else_instructions;

                  body.emit(assign(r01D7, bit_or(r01DD, body.constant(1048576u)), 0x01));


               body.instructions = f023A_parent_instructions;
               body.emit(f023A);

               /* END IF */

               ir_variable *const r023C = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r023C, body.constant(0u), 0x01));

               ir_variable *const r023D = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r023D, neg(r01D4), 0x01));

               ir_variable *const r023E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r023E);
               ir_variable *const r023F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r023F);
               ir_variable *const r0240 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0240);
               ir_variable *const r0241 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0242 = neg(r023D);
               body.emit(assign(r0241, bit_and(r0242, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0244 = equal(r023D, body.constant(int(0)));
               ir_if *f0243 = new(mem_ctx) ir_if(operand(r0244).val);
               exec_list *const f0243_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0243->then_instructions;

                  body.emit(assign(r023E, r023C, 0x01));

                  body.emit(assign(r023F, r01DC, 0x01));

                  body.emit(assign(r0240, r01D7, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0243->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0246 = less(r023D, body.constant(int(32)));
                  ir_if *f0245 = new(mem_ctx) ir_if(operand(r0246).val);
                  exec_list *const f0245_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0245->then_instructions;

                     body.emit(assign(r023E, lshift(swizzle_x(r01CB), r0241), 0x01));

                     ir_expression *const r0247 = lshift(r01D7, r0241);
                     ir_expression *const r0248 = rshift(swizzle_x(r01CB), r023D);
                     body.emit(assign(r023F, bit_or(r0247, r0248), 0x01));

                     body.emit(assign(r0240, rshift(r01D7, r023D), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0245->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r024A = equal(r023D, body.constant(int(32)));
                     ir_if *f0249 = new(mem_ctx) ir_if(operand(r024A).val);
                     exec_list *const f0249_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0249->then_instructions;

                        body.emit(assign(r023E, r01DC, 0x01));

                        body.emit(assign(r023F, r01D7, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0249->else_instructions;

                        body.emit(assign(r023C, bit_or(body.constant(0u), swizzle_x(r01CB)), 0x01));

                        ir_expression *const r024B = less(r023D, body.constant(int(64)));
                        ir_expression *const r024C = lshift(r01D7, r0241);
                        ir_expression *const r024D = equal(r023D, body.constant(int(64)));
                        ir_expression *const r024E = nequal(r01D7, body.constant(0u));
                        ir_expression *const r024F = expr(ir_unop_b2i, r024E);
                        ir_expression *const r0250 = expr(ir_unop_i2u, r024F);
                        ir_expression *const r0251 = expr(ir_triop_csel, r024D, r01D7, r0250);
                        body.emit(assign(r023E, expr(ir_triop_csel, r024B, r024C, r0251), 0x01));

                        ir_expression *const r0252 = less(r023D, body.constant(int(64)));
                        ir_expression *const r0253 = bit_and(r023D, body.constant(int(31)));
                        ir_expression *const r0254 = rshift(r01D7, r0253);
                        body.emit(assign(r023F, expr(ir_triop_csel, r0252, r0254, body.constant(0u)), 0x01));


                     body.instructions = f0249_parent_instructions;
                     body.emit(f0249);

                     /* END IF */

                     body.emit(assign(r0240, body.constant(0u), 0x01));


                  body.instructions = f0245_parent_instructions;
                  body.emit(f0245);

                  /* END IF */

                  ir_expression *const r0255 = nequal(r023C, body.constant(0u));
                  ir_expression *const r0256 = expr(ir_unop_b2i, r0255);
                  ir_expression *const r0257 = expr(ir_unop_i2u, r0256);
                  body.emit(assign(r023E, bit_or(r023E, r0257), 0x01));


               body.instructions = f0243_parent_instructions;
               body.emit(f0243);

               /* END IF */

               body.emit(assign(r01D7, r0240, 0x01));

               body.emit(assign(r01D8, r023F, 0x01));

               body.emit(assign(r01DA, r023E, 0x01));

               body.emit(assign(r01D9, r01E3, 0x01));


            body.instructions = f0220_parent_instructions;
            body.emit(f0220);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f021E->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0259 = equal(r01E0, body.constant(int(2047)));
            ir_if *f0258 = new(mem_ctx) ir_if(operand(r0259).val);
            exec_list *const f0258_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0258->then_instructions;

               /* IF CONDITION */
               ir_expression *const r025B = bit_or(r01D7, r01D8);
               ir_expression *const r025C = bit_or(r01D5, r01D6);
               ir_expression *const r025D = bit_or(r025B, r025C);
               ir_expression *const r025E = nequal(r025D, body.constant(0u));
               ir_if *f025A = new(mem_ctx) ir_if(operand(r025E).val);
               exec_list *const f025A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f025A->then_instructions;

                  ir_variable *const r025F = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r025F, swizzle_x(r01CB), 0x01));

                  ir_variable *const r0260 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0260, swizzle_x(r01CC), 0x01));

                  body.emit(assign(r025F, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

                  body.emit(assign(r0260, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

                  ir_expression *const r0261 = lshift(swizzle_y(r01CB), body.constant(int(1)));
                  ir_expression *const r0262 = gequal(r0261, body.constant(4292870144u));
                  ir_expression *const r0263 = nequal(swizzle_x(r01CB), body.constant(0u));
                  ir_expression *const r0264 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
                  ir_expression *const r0265 = nequal(r0264, body.constant(0u));
                  ir_expression *const r0266 = logic_or(r0263, r0265);
                  ir_expression *const r0267 = logic_and(r0262, r0266);
                  ir_swizzle *const r0268 = swizzle(r0267, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0269 = lshift(swizzle_y(r01CC), body.constant(int(1)));
                  ir_expression *const r026A = gequal(r0269, body.constant(4292870144u));
                  ir_expression *const r026B = nequal(swizzle_x(r01CC), body.constant(0u));
                  ir_expression *const r026C = bit_and(swizzle_y(r01CC), body.constant(1048575u));
                  ir_expression *const r026D = nequal(r026C, body.constant(0u));
                  ir_expression *const r026E = logic_or(r026B, r026D);
                  ir_expression *const r026F = logic_and(r026A, r026E);
                  ir_swizzle *const r0270 = swizzle(r026F, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0271 = expr(ir_triop_csel, r0270, r0260, r025F);
                  body.emit(assign(r01CE, expr(ir_triop_csel, r0268, r0271, r0260), 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f025A->else_instructions;

                  body.emit(assign(r01CE, r01CB, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


               body.instructions = f025A_parent_instructions;
               body.emit(f025A);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0258->else_instructions;

               ir_variable *const r0272 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0273 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0273, add(r01D8, r01D6), 0x01));

               ir_expression *const r0274 = add(r01D7, r01D5);
               ir_expression *const r0275 = less(r0273, r01D8);
               ir_expression *const r0276 = expr(ir_unop_b2i, r0275);
               ir_expression *const r0277 = expr(ir_unop_i2u, r0276);
               body.emit(assign(r0272, add(r0274, r0277), 0x01));

               body.emit(assign(r01DB, r0272, 0x01));

               /* IF CONDITION */
               ir_expression *const r0279 = equal(r01E0, body.constant(int(0)));
               ir_if *f0278 = new(mem_ctx) ir_if(operand(r0279).val);
               exec_list *const f0278_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0278->then_instructions;

                  ir_variable *const r027A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r027A);
                  ir_expression *const r027B = lshift(r01D0, body.constant(int(31)));
                  body.emit(assign(r027A, add(r027B, r0272), 0x02));

                  body.emit(assign(r027A, r0273, 0x01));

                  body.emit(assign(r01CE, r027A, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0278->else_instructions;

                  body.emit(assign(r01DB, bit_or(r0272, body.constant(2097152u)), 0x01));

                  body.emit(assign(r01D9, r01E0, 0x01));

                  ir_variable *const r027C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r027C);
                  ir_variable *const r027D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r027D);
                  ir_variable *const r027E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r027E);
                  body.emit(assign(r027C, lshift(r0273, body.constant(int(31))), 0x01));

                  ir_expression *const r027F = lshift(r01DB, body.constant(int(31)));
                  ir_expression *const r0280 = rshift(r0273, body.constant(int(1)));
                  body.emit(assign(r027D, bit_or(r027F, r0280), 0x01));

                  body.emit(assign(r027E, rshift(r01DB, body.constant(int(1))), 0x01));

                  body.emit(assign(r027C, bit_or(r027C, body.constant(0u)), 0x01));

                  body.emit(assign(r01DB, r027E, 0x01));

                  body.emit(assign(r01DA, r027C, 0x01));

                  ir_variable *const r0281 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0281, r01E0, 0x01));

                  ir_variable *const r0282 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0282, r027E, 0x01));

                  ir_variable *const r0283 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0283, r027D, 0x01));

                  ir_variable *const r0284 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0284, r027C, 0x01));

                  ir_variable *const r0285 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0285, body.constant(true), 0x01));

                  ir_variable *const r0286 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0287 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r0287);
                  ir_expression *const r0288 = expr(ir_unop_u2i, r027C);
                  body.emit(assign(r0287, less(r0288, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r028A = gequal(r01E0, body.constant(int(2045)));
                  ir_if *f0289 = new(mem_ctx) ir_if(operand(r028A).val);
                  exec_list *const f0289_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0289->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r028C = less(body.constant(int(2045)), r01E0);
                     ir_expression *const r028D = equal(r01E0, body.constant(int(2045)));
                     ir_expression *const r028E = equal(body.constant(2097151u), r027E);
                     ir_expression *const r028F = equal(body.constant(4294967295u), r027D);
                     ir_expression *const r0290 = logic_and(r028E, r028F);
                     ir_expression *const r0291 = logic_and(r028D, r0290);
                     ir_expression *const r0292 = logic_and(r0291, r0287);
                     ir_expression *const r0293 = logic_or(r028C, r0292);
                     ir_if *f028B = new(mem_ctx) ir_if(operand(r0293).val);
                     exec_list *const f028B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f028B->then_instructions;

                        ir_variable *const r0294 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0294);
                        ir_expression *const r0295 = lshift(r01D0, body.constant(int(31)));
                        body.emit(assign(r0294, add(r0295, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0294, body.constant(0u), 0x01));

                        body.emit(assign(r0286, r0294, 0x03));

                        body.emit(assign(r0285, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f028B->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0297 = less(r01E0, body.constant(int(0)));
                        ir_if *f0296 = new(mem_ctx) ir_if(operand(r0297).val);
                        exec_list *const f0296_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0296->then_instructions;

                           ir_variable *const r0298 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0298, r027C, 0x01));

                           ir_variable *const r0299 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0299, neg(r01E0), 0x01));

                           ir_variable *const r029A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r029A);
                           ir_variable *const r029B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r029B);
                           ir_variable *const r029C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r029C);
                           ir_variable *const r029D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r029E = neg(r0299);
                           body.emit(assign(r029D, bit_and(r029E, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02A0 = equal(r0299, body.constant(int(0)));
                           ir_if *f029F = new(mem_ctx) ir_if(operand(r02A0).val);
                           exec_list *const f029F_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f029F->then_instructions;

                              body.emit(assign(r029A, r027C, 0x01));

                              body.emit(assign(r029B, r027D, 0x01));

                              body.emit(assign(r029C, r027E, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f029F->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02A2 = less(r0299, body.constant(int(32)));
                              ir_if *f02A1 = new(mem_ctx) ir_if(operand(r02A2).val);
                              exec_list *const f02A1_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02A1->then_instructions;

                                 body.emit(assign(r029A, lshift(r027D, r029D), 0x01));

                                 ir_expression *const r02A3 = lshift(r027E, r029D);
                                 ir_expression *const r02A4 = rshift(r027D, r0299);
                                 body.emit(assign(r029B, bit_or(r02A3, r02A4), 0x01));

                                 body.emit(assign(r029C, rshift(r027E, r0299), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02A1->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02A6 = equal(r0299, body.constant(int(32)));
                                 ir_if *f02A5 = new(mem_ctx) ir_if(operand(r02A6).val);
                                 exec_list *const f02A5_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02A5->then_instructions;

                                    body.emit(assign(r029A, r027D, 0x01));

                                    body.emit(assign(r029B, r027E, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02A5->else_instructions;

                                    body.emit(assign(r0298, bit_or(r027C, r027D), 0x01));

                                    ir_expression *const r02A7 = less(r0299, body.constant(int(64)));
                                    ir_expression *const r02A8 = lshift(r027E, r029D);
                                    ir_expression *const r02A9 = equal(r0299, body.constant(int(64)));
                                    ir_expression *const r02AA = nequal(r027E, body.constant(0u));
                                    ir_expression *const r02AB = expr(ir_unop_b2i, r02AA);
                                    ir_expression *const r02AC = expr(ir_unop_i2u, r02AB);
                                    ir_expression *const r02AD = expr(ir_triop_csel, r02A9, r027E, r02AC);
                                    body.emit(assign(r029A, expr(ir_triop_csel, r02A7, r02A8, r02AD), 0x01));

                                    ir_expression *const r02AE = less(r0299, body.constant(int(64)));
                                    ir_expression *const r02AF = bit_and(r0299, body.constant(int(31)));
                                    ir_expression *const r02B0 = rshift(r027E, r02AF);
                                    body.emit(assign(r029B, expr(ir_triop_csel, r02AE, r02B0, body.constant(0u)), 0x01));


                                 body.instructions = f02A5_parent_instructions;
                                 body.emit(f02A5);

                                 /* END IF */

                                 body.emit(assign(r029C, body.constant(0u), 0x01));


                              body.instructions = f02A1_parent_instructions;
                              body.emit(f02A1);

                              /* END IF */

                              ir_expression *const r02B1 = nequal(r0298, body.constant(0u));
                              ir_expression *const r02B2 = expr(ir_unop_b2i, r02B1);
                              ir_expression *const r02B3 = expr(ir_unop_i2u, r02B2);
                              body.emit(assign(r029A, bit_or(r029A, r02B3), 0x01));


                           body.instructions = f029F_parent_instructions;
                           body.emit(f029F);

                           /* END IF */

                           body.emit(assign(r0282, r029C, 0x01));

                           body.emit(assign(r0283, r029B, 0x01));

                           body.emit(assign(r0284, r029A, 0x01));

                           body.emit(assign(r0281, body.constant(int(0)), 0x01));

                           body.emit(assign(r0287, less(r029A, body.constant(0u)), 0x01));


                        body.instructions = f0296_parent_instructions;
                        body.emit(f0296);

                        /* END IF */


                     body.instructions = f028B_parent_instructions;
                     body.emit(f028B);

                     /* END IF */


                  body.instructions = f0289_parent_instructions;
                  body.emit(f0289);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02B4 = new(mem_ctx) ir_if(operand(r0285).val);
                  exec_list *const f02B4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02B4->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02B5 = new(mem_ctx) ir_if(operand(r0287).val);
                     exec_list *const f02B5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02B5->then_instructions;

                        ir_variable *const r02B6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02B6, add(r0283, body.constant(1u)), 0x01));

                        ir_expression *const r02B7 = less(r02B6, r0283);
                        ir_expression *const r02B8 = expr(ir_unop_b2i, r02B7);
                        ir_expression *const r02B9 = expr(ir_unop_i2u, r02B8);
                        body.emit(assign(r0282, add(r0282, r02B9), 0x01));

                        ir_expression *const r02BA = equal(r0284, body.constant(0u));
                        ir_expression *const r02BB = expr(ir_unop_b2i, r02BA);
                        ir_expression *const r02BC = expr(ir_unop_i2u, r02BB);
                        ir_expression *const r02BD = add(r0284, r02BC);
                        ir_expression *const r02BE = bit_and(r02BD, body.constant(1u));
                        ir_expression *const r02BF = expr(ir_unop_bit_not, r02BE);
                        body.emit(assign(r0283, bit_and(r02B6, r02BF), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02B5->else_instructions;

                        ir_expression *const r02C0 = bit_or(r0282, r0283);
                        ir_expression *const r02C1 = equal(r02C0, body.constant(0u));
                        body.emit(assign(r0281, expr(ir_triop_csel, r02C1, body.constant(int(0)), r0281), 0x01));


                     body.instructions = f02B5_parent_instructions;
                     body.emit(f02B5);

                     /* END IF */

                     ir_variable *const r02C2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r02C2);
                     ir_expression *const r02C3 = lshift(r01D0, body.constant(int(31)));
                     ir_expression *const r02C4 = expr(ir_unop_i2u, r0281);
                     ir_expression *const r02C5 = lshift(r02C4, body.constant(int(20)));
                     ir_expression *const r02C6 = add(r02C3, r02C5);
                     body.emit(assign(r02C2, add(r02C6, r0282), 0x02));

                     body.emit(assign(r02C2, r0283, 0x01));

                     body.emit(assign(r0286, r02C2, 0x03));

                     body.emit(assign(r0285, body.constant(false), 0x01));


                  body.instructions = f02B4_parent_instructions;
                  body.emit(f02B4);

                  /* END IF */

                  body.emit(assign(r01CE, r0286, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


               body.instructions = f0278_parent_instructions;
               body.emit(f0278);

               /* END IF */


            body.instructions = f0258_parent_instructions;
            body.emit(f0258);

            /* END IF */


         body.instructions = f021E_parent_instructions;
         body.emit(f021E);

         /* END IF */


      body.instructions = f01E7_parent_instructions;
      body.emit(f01E7);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02C7 = new(mem_ctx) ir_if(operand(r01CD).val);
      exec_list *const f02C7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02C7->then_instructions;

         body.emit(assign(r01D7, bit_or(r01D7, body.constant(1048576u)), 0x01));

         ir_variable *const r02C8 = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r02C9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r02C9, add(r01D8, r01D6), 0x01));

         ir_expression *const r02CA = add(r01D7, r01D5);
         ir_expression *const r02CB = less(r02C9, r01D8);
         ir_expression *const r02CC = expr(ir_unop_b2i, r02CB);
         ir_expression *const r02CD = expr(ir_unop_i2u, r02CC);
         body.emit(assign(r02C8, add(r02CA, r02CD), 0x01));

         body.emit(assign(r01DB, r02C8, 0x01));

         body.emit(assign(r01D9, add(r01D9, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r02CF = less(r02C8, body.constant(2097152u));
         ir_if *f02CE = new(mem_ctx) ir_if(operand(r02CF).val);
         exec_list *const f02CE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02CE->then_instructions;

            ir_variable *const r02D0 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r02D0, r01D9, 0x01));

            ir_variable *const r02D1 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r02D1, r02C8, 0x01));

            ir_variable *const r02D2 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r02D2, r02C9, 0x01));

            ir_variable *const r02D3 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r02D3, r01DA, 0x01));

            ir_variable *const r02D4 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r02D4, body.constant(true), 0x01));

            ir_variable *const r02D5 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r02D6 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r02D6);
            ir_expression *const r02D7 = expr(ir_unop_u2i, r01DA);
            body.emit(assign(r02D6, less(r02D7, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02D9 = gequal(r01D9, body.constant(int(2045)));
            ir_if *f02D8 = new(mem_ctx) ir_if(operand(r02D9).val);
            exec_list *const f02D8_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02D8->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02DB = less(body.constant(int(2045)), r01D9);
               ir_expression *const r02DC = equal(r01D9, body.constant(int(2045)));
               ir_expression *const r02DD = equal(body.constant(2097151u), r02C8);
               ir_expression *const r02DE = equal(body.constant(4294967295u), r02C9);
               ir_expression *const r02DF = logic_and(r02DD, r02DE);
               ir_expression *const r02E0 = logic_and(r02DC, r02DF);
               ir_expression *const r02E1 = logic_and(r02E0, r02D6);
               ir_expression *const r02E2 = logic_or(r02DB, r02E1);
               ir_if *f02DA = new(mem_ctx) ir_if(operand(r02E2).val);
               exec_list *const f02DA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02DA->then_instructions;

                  ir_variable *const r02E3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02E3);
                  ir_expression *const r02E4 = lshift(r01D0, body.constant(int(31)));
                  body.emit(assign(r02E3, add(r02E4, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r02E3, body.constant(0u), 0x01));

                  body.emit(assign(r02D5, r02E3, 0x03));

                  body.emit(assign(r02D4, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02DA->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r02E6 = less(r01D9, body.constant(int(0)));
                  ir_if *f02E5 = new(mem_ctx) ir_if(operand(r02E6).val);
                  exec_list *const f02E5_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02E5->then_instructions;

                     ir_variable *const r02E7 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r02E7, r01DA, 0x01));

                     ir_variable *const r02E8 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r02E8, neg(r01D9), 0x01));

                     ir_variable *const r02E9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r02E9);
                     ir_variable *const r02EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r02EA);
                     ir_variable *const r02EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r02EB);
                     ir_variable *const r02EC = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r02ED = neg(r02E8);
                     body.emit(assign(r02EC, bit_and(r02ED, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r02EF = equal(r02E8, body.constant(int(0)));
                     ir_if *f02EE = new(mem_ctx) ir_if(operand(r02EF).val);
                     exec_list *const f02EE_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02EE->then_instructions;

                        body.emit(assign(r02E9, r01DA, 0x01));

                        body.emit(assign(r02EA, r02C9, 0x01));

                        body.emit(assign(r02EB, r02C8, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02EE->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02F1 = less(r02E8, body.constant(int(32)));
                        ir_if *f02F0 = new(mem_ctx) ir_if(operand(r02F1).val);
                        exec_list *const f02F0_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02F0->then_instructions;

                           body.emit(assign(r02E9, lshift(r02C9, r02EC), 0x01));

                           ir_expression *const r02F2 = lshift(r02C8, r02EC);
                           ir_expression *const r02F3 = rshift(r02C9, r02E8);
                           body.emit(assign(r02EA, bit_or(r02F2, r02F3), 0x01));

                           body.emit(assign(r02EB, rshift(r02C8, r02E8), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f02F0->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r02F5 = equal(r02E8, body.constant(int(32)));
                           ir_if *f02F4 = new(mem_ctx) ir_if(operand(r02F5).val);
                           exec_list *const f02F4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02F4->then_instructions;

                              body.emit(assign(r02E9, r02C9, 0x01));

                              body.emit(assign(r02EA, r02C8, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02F4->else_instructions;

                              body.emit(assign(r02E7, bit_or(r01DA, r02C9), 0x01));

                              ir_expression *const r02F6 = less(r02E8, body.constant(int(64)));
                              ir_expression *const r02F7 = lshift(r02C8, r02EC);
                              ir_expression *const r02F8 = equal(r02E8, body.constant(int(64)));
                              ir_expression *const r02F9 = nequal(r02C8, body.constant(0u));
                              ir_expression *const r02FA = expr(ir_unop_b2i, r02F9);
                              ir_expression *const r02FB = expr(ir_unop_i2u, r02FA);
                              ir_expression *const r02FC = expr(ir_triop_csel, r02F8, r02C8, r02FB);
                              body.emit(assign(r02E9, expr(ir_triop_csel, r02F6, r02F7, r02FC), 0x01));

                              ir_expression *const r02FD = less(r02E8, body.constant(int(64)));
                              ir_expression *const r02FE = bit_and(r02E8, body.constant(int(31)));
                              ir_expression *const r02FF = rshift(r02C8, r02FE);
                              body.emit(assign(r02EA, expr(ir_triop_csel, r02FD, r02FF, body.constant(0u)), 0x01));


                           body.instructions = f02F4_parent_instructions;
                           body.emit(f02F4);

                           /* END IF */

                           body.emit(assign(r02EB, body.constant(0u), 0x01));


                        body.instructions = f02F0_parent_instructions;
                        body.emit(f02F0);

                        /* END IF */

                        ir_expression *const r0300 = nequal(r02E7, body.constant(0u));
                        ir_expression *const r0301 = expr(ir_unop_b2i, r0300);
                        ir_expression *const r0302 = expr(ir_unop_i2u, r0301);
                        body.emit(assign(r02E9, bit_or(r02E9, r0302), 0x01));


                     body.instructions = f02EE_parent_instructions;
                     body.emit(f02EE);

                     /* END IF */

                     body.emit(assign(r02D1, r02EB, 0x01));

                     body.emit(assign(r02D2, r02EA, 0x01));

                     body.emit(assign(r02D3, r02E9, 0x01));

                     body.emit(assign(r02D0, body.constant(int(0)), 0x01));

                     body.emit(assign(r02D6, less(r02E9, body.constant(0u)), 0x01));


                  body.instructions = f02E5_parent_instructions;
                  body.emit(f02E5);

                  /* END IF */


               body.instructions = f02DA_parent_instructions;
               body.emit(f02DA);

               /* END IF */


            body.instructions = f02D8_parent_instructions;
            body.emit(f02D8);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0303 = new(mem_ctx) ir_if(operand(r02D4).val);
            exec_list *const f0303_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0303->then_instructions;

               /* IF CONDITION */
               ir_if *f0304 = new(mem_ctx) ir_if(operand(r02D6).val);
               exec_list *const f0304_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0304->then_instructions;

                  ir_variable *const r0305 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0305, add(r02D2, body.constant(1u)), 0x01));

                  ir_expression *const r0306 = less(r0305, r02D2);
                  ir_expression *const r0307 = expr(ir_unop_b2i, r0306);
                  ir_expression *const r0308 = expr(ir_unop_i2u, r0307);
                  body.emit(assign(r02D1, add(r02D1, r0308), 0x01));

                  ir_expression *const r0309 = equal(r02D3, body.constant(0u));
                  ir_expression *const r030A = expr(ir_unop_b2i, r0309);
                  ir_expression *const r030B = expr(ir_unop_i2u, r030A);
                  ir_expression *const r030C = add(r02D3, r030B);
                  ir_expression *const r030D = bit_and(r030C, body.constant(1u));
                  ir_expression *const r030E = expr(ir_unop_bit_not, r030D);
                  body.emit(assign(r02D2, bit_and(r0305, r030E), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0304->else_instructions;

                  ir_expression *const r030F = bit_or(r02D1, r02D2);
                  ir_expression *const r0310 = equal(r030F, body.constant(0u));
                  body.emit(assign(r02D0, expr(ir_triop_csel, r0310, body.constant(int(0)), r02D0), 0x01));


               body.instructions = f0304_parent_instructions;
               body.emit(f0304);

               /* END IF */

               ir_variable *const r0311 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0311);
               ir_expression *const r0312 = lshift(r01D0, body.constant(int(31)));
               ir_expression *const r0313 = expr(ir_unop_i2u, r02D0);
               ir_expression *const r0314 = lshift(r0313, body.constant(int(20)));
               ir_expression *const r0315 = add(r0312, r0314);
               body.emit(assign(r0311, add(r0315, r02D1), 0x02));

               body.emit(assign(r0311, r02D2, 0x01));

               body.emit(assign(r02D5, r0311, 0x03));

               body.emit(assign(r02D4, body.constant(false), 0x01));


            body.instructions = f0303_parent_instructions;
            body.emit(f0303);

            /* END IF */

            body.emit(assign(r01CE, r02D5, 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02CE->else_instructions;

            body.emit(assign(r01D9, add(r01D9, body.constant(int(1))), 0x01));

            ir_variable *const r0316 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0316);
            ir_variable *const r0317 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0317);
            ir_variable *const r0318 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0318);
            body.emit(assign(r0316, lshift(r02C9, body.constant(int(31))), 0x01));

            ir_expression *const r0319 = lshift(r02C8, body.constant(int(31)));
            ir_expression *const r031A = rshift(r02C9, body.constant(int(1)));
            body.emit(assign(r0317, bit_or(r0319, r031A), 0x01));

            body.emit(assign(r0318, rshift(r02C8, body.constant(int(1))), 0x01));

            ir_expression *const r031B = nequal(r01DA, body.constant(0u));
            ir_expression *const r031C = expr(ir_unop_b2i, r031B);
            ir_expression *const r031D = expr(ir_unop_i2u, r031C);
            body.emit(assign(r0316, bit_or(r0316, r031D), 0x01));

            body.emit(assign(r01DB, r0318, 0x01));

            body.emit(assign(r01DA, r0316, 0x01));

            ir_variable *const r031E = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r031E, r01D9, 0x01));

            ir_variable *const r031F = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r031F, r0318, 0x01));

            ir_variable *const r0320 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0320, r0317, 0x01));

            ir_variable *const r0321 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0321, r0316, 0x01));

            ir_variable *const r0322 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0322, body.constant(true), 0x01));

            ir_variable *const r0323 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0324 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0324);
            ir_expression *const r0325 = expr(ir_unop_u2i, r0316);
            body.emit(assign(r0324, less(r0325, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0327 = gequal(r01D9, body.constant(int(2045)));
            ir_if *f0326 = new(mem_ctx) ir_if(operand(r0327).val);
            exec_list *const f0326_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0326->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0329 = less(body.constant(int(2045)), r01D9);
               ir_expression *const r032A = equal(r01D9, body.constant(int(2045)));
               ir_expression *const r032B = equal(body.constant(2097151u), r0318);
               ir_expression *const r032C = equal(body.constant(4294967295u), r0317);
               ir_expression *const r032D = logic_and(r032B, r032C);
               ir_expression *const r032E = logic_and(r032A, r032D);
               ir_expression *const r032F = logic_and(r032E, r0324);
               ir_expression *const r0330 = logic_or(r0329, r032F);
               ir_if *f0328 = new(mem_ctx) ir_if(operand(r0330).val);
               exec_list *const f0328_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0328->then_instructions;

                  ir_variable *const r0331 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0331);
                  ir_expression *const r0332 = lshift(r01D0, body.constant(int(31)));
                  body.emit(assign(r0331, add(r0332, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0331, body.constant(0u), 0x01));

                  body.emit(assign(r0323, r0331, 0x03));

                  body.emit(assign(r0322, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0328->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0334 = less(r01D9, body.constant(int(0)));
                  ir_if *f0333 = new(mem_ctx) ir_if(operand(r0334).val);
                  exec_list *const f0333_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0333->then_instructions;

                     ir_variable *const r0335 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0335, r0316, 0x01));

                     ir_variable *const r0336 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0336, neg(r01D9), 0x01));

                     ir_variable *const r0337 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0337);
                     ir_variable *const r0338 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0338);
                     ir_variable *const r0339 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0339);
                     ir_variable *const r033A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r033B = neg(r0336);
                     body.emit(assign(r033A, bit_and(r033B, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r033D = equal(r0336, body.constant(int(0)));
                     ir_if *f033C = new(mem_ctx) ir_if(operand(r033D).val);
                     exec_list *const f033C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f033C->then_instructions;

                        body.emit(assign(r0337, r0316, 0x01));

                        body.emit(assign(r0338, r0317, 0x01));

                        body.emit(assign(r0339, r0318, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f033C->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r033F = less(r0336, body.constant(int(32)));
                        ir_if *f033E = new(mem_ctx) ir_if(operand(r033F).val);
                        exec_list *const f033E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f033E->then_instructions;

                           body.emit(assign(r0337, lshift(r0317, r033A), 0x01));

                           ir_expression *const r0340 = lshift(r0318, r033A);
                           ir_expression *const r0341 = rshift(r0317, r0336);
                           body.emit(assign(r0338, bit_or(r0340, r0341), 0x01));

                           body.emit(assign(r0339, rshift(r0318, r0336), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f033E->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0343 = equal(r0336, body.constant(int(32)));
                           ir_if *f0342 = new(mem_ctx) ir_if(operand(r0343).val);
                           exec_list *const f0342_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0342->then_instructions;

                              body.emit(assign(r0337, r0317, 0x01));

                              body.emit(assign(r0338, r0318, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0342->else_instructions;

                              body.emit(assign(r0335, bit_or(r0316, r0317), 0x01));

                              ir_expression *const r0344 = less(r0336, body.constant(int(64)));
                              ir_expression *const r0345 = lshift(r0318, r033A);
                              ir_expression *const r0346 = equal(r0336, body.constant(int(64)));
                              ir_expression *const r0347 = nequal(r0318, body.constant(0u));
                              ir_expression *const r0348 = expr(ir_unop_b2i, r0347);
                              ir_expression *const r0349 = expr(ir_unop_i2u, r0348);
                              ir_expression *const r034A = expr(ir_triop_csel, r0346, r0318, r0349);
                              body.emit(assign(r0337, expr(ir_triop_csel, r0344, r0345, r034A), 0x01));

                              ir_expression *const r034B = less(r0336, body.constant(int(64)));
                              ir_expression *const r034C = bit_and(r0336, body.constant(int(31)));
                              ir_expression *const r034D = rshift(r0318, r034C);
                              body.emit(assign(r0338, expr(ir_triop_csel, r034B, r034D, body.constant(0u)), 0x01));


                           body.instructions = f0342_parent_instructions;
                           body.emit(f0342);

                           /* END IF */

                           body.emit(assign(r0339, body.constant(0u), 0x01));


                        body.instructions = f033E_parent_instructions;
                        body.emit(f033E);

                        /* END IF */

                        ir_expression *const r034E = nequal(r0335, body.constant(0u));
                        ir_expression *const r034F = expr(ir_unop_b2i, r034E);
                        ir_expression *const r0350 = expr(ir_unop_i2u, r034F);
                        body.emit(assign(r0337, bit_or(r0337, r0350), 0x01));


                     body.instructions = f033C_parent_instructions;
                     body.emit(f033C);

                     /* END IF */

                     body.emit(assign(r031F, r0339, 0x01));

                     body.emit(assign(r0320, r0338, 0x01));

                     body.emit(assign(r0321, r0337, 0x01));

                     body.emit(assign(r031E, body.constant(int(0)), 0x01));

                     body.emit(assign(r0324, less(r0337, body.constant(0u)), 0x01));


                  body.instructions = f0333_parent_instructions;
                  body.emit(f0333);

                  /* END IF */


               body.instructions = f0328_parent_instructions;
               body.emit(f0328);

               /* END IF */


            body.instructions = f0326_parent_instructions;
            body.emit(f0326);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0351 = new(mem_ctx) ir_if(operand(r0322).val);
            exec_list *const f0351_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0351->then_instructions;

               /* IF CONDITION */
               ir_if *f0352 = new(mem_ctx) ir_if(operand(r0324).val);
               exec_list *const f0352_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0352->then_instructions;

                  ir_variable *const r0353 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0353, add(r0320, body.constant(1u)), 0x01));

                  ir_expression *const r0354 = less(r0353, r0320);
                  ir_expression *const r0355 = expr(ir_unop_b2i, r0354);
                  ir_expression *const r0356 = expr(ir_unop_i2u, r0355);
                  body.emit(assign(r031F, add(r031F, r0356), 0x01));

                  ir_expression *const r0357 = equal(r0321, body.constant(0u));
                  ir_expression *const r0358 = expr(ir_unop_b2i, r0357);
                  ir_expression *const r0359 = expr(ir_unop_i2u, r0358);
                  ir_expression *const r035A = add(r0321, r0359);
                  ir_expression *const r035B = bit_and(r035A, body.constant(1u));
                  ir_expression *const r035C = expr(ir_unop_bit_not, r035B);
                  body.emit(assign(r0320, bit_and(r0353, r035C), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0352->else_instructions;

                  ir_expression *const r035D = bit_or(r031F, r0320);
                  ir_expression *const r035E = equal(r035D, body.constant(0u));
                  body.emit(assign(r031E, expr(ir_triop_csel, r035E, body.constant(int(0)), r031E), 0x01));


               body.instructions = f0352_parent_instructions;
               body.emit(f0352);

               /* END IF */

               ir_variable *const r035F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r035F);
               ir_expression *const r0360 = lshift(r01D0, body.constant(int(31)));
               ir_expression *const r0361 = expr(ir_unop_i2u, r031E);
               ir_expression *const r0362 = lshift(r0361, body.constant(int(20)));
               ir_expression *const r0363 = add(r0360, r0362);
               body.emit(assign(r035F, add(r0363, r031F), 0x02));

               body.emit(assign(r035F, r0320, 0x01));

               body.emit(assign(r0323, r035F, 0x03));

               body.emit(assign(r0322, body.constant(false), 0x01));


            body.instructions = f0351_parent_instructions;
            body.emit(f0351);

            /* END IF */

            body.emit(assign(r01CE, r0323, 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


         body.instructions = f02CE_parent_instructions;
         body.emit(f02CE);

         /* END IF */


      body.instructions = f02C7_parent_instructions;
      body.emit(f02C7);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01D2->else_instructions;

      ir_variable *const r0364 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r0364);
      ir_variable *const r0365 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
      body.emit(r0365);
      ir_variable *const r0366 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
      body.emit(r0366);
      ir_variable *const r0367 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r0367);
      ir_variable *const r0368 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r0368);
      ir_variable *const r0369 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r0369);
      ir_variable *const r036A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r036A);
      ir_variable *const r036B = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r036B);
      ir_variable *const r036C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r036D = rshift(swizzle_y(r01CB), body.constant(int(20)));
      ir_expression *const r036E = bit_and(r036D, body.constant(2047u));
      body.emit(assign(r036C, expr(ir_unop_u2i, r036E), 0x01));

      body.emit(assign(r0366, r036C, 0x01));

      ir_variable *const r036F = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r0370 = rshift(swizzle_y(r01CC), body.constant(int(20)));
      ir_expression *const r0371 = bit_and(r0370, body.constant(2047u));
      body.emit(assign(r036F, expr(ir_unop_u2i, r0371), 0x01));

      body.emit(assign(r0365, r036F, 0x01));

      body.emit(assign(r0364, sub(r036C, r036F), 0x01));

      ir_variable *const r0372 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r0373 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0373, lshift(swizzle_x(r01CB), body.constant(int(10))), 0x01));

      ir_expression *const r0374 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
      ir_expression *const r0375 = lshift(r0374, body.constant(int(10)));
      ir_expression *const r0376 = rshift(swizzle_x(r01CB), body.constant(int(22)));
      body.emit(assign(r0372, bit_or(r0375, r0376), 0x01));

      body.emit(assign(r0369, r0372, 0x01));

      body.emit(assign(r036A, r0373, 0x01));

      ir_variable *const r0377 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r0378 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0378, lshift(swizzle_x(r01CC), body.constant(int(10))), 0x01));

      ir_expression *const r0379 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
      ir_expression *const r037A = lshift(r0379, body.constant(int(10)));
      ir_expression *const r037B = rshift(swizzle_x(r01CC), body.constant(int(22)));
      body.emit(assign(r0377, bit_or(r037A, r037B), 0x01));

      body.emit(assign(r0367, r0377, 0x01));

      body.emit(assign(r0368, r0378, 0x01));

      /* IF CONDITION */
      ir_expression *const r037D = less(body.constant(int(0)), r0364);
      ir_if *f037C = new(mem_ctx) ir_if(operand(r037D).val);
      exec_list *const f037C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f037C->then_instructions;

         /* IF CONDITION */
         ir_expression *const r037F = equal(r036C, body.constant(int(2047)));
         ir_if *f037E = new(mem_ctx) ir_if(operand(r037F).val);
         exec_list *const f037E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f037E->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0381 = bit_or(r0372, r0373);
            ir_expression *const r0382 = nequal(r0381, body.constant(0u));
            ir_if *f0380 = new(mem_ctx) ir_if(operand(r0382).val);
            exec_list *const f0380_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0380->then_instructions;

               ir_variable *const r0383 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0383, swizzle_x(r01CB), 0x01));

               ir_variable *const r0384 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0384, swizzle_x(r01CC), 0x01));

               body.emit(assign(r0383, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r0384, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r0385 = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r0386 = gequal(r0385, body.constant(4292870144u));
               ir_expression *const r0387 = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r0388 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r0389 = nequal(r0388, body.constant(0u));
               ir_expression *const r038A = logic_or(r0387, r0389);
               ir_expression *const r038B = logic_and(r0386, r038A);
               ir_swizzle *const r038C = swizzle(r038B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r038D = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r038E = gequal(r038D, body.constant(4292870144u));
               ir_expression *const r038F = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r0390 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r0391 = nequal(r0390, body.constant(0u));
               ir_expression *const r0392 = logic_or(r038F, r0391);
               ir_expression *const r0393 = logic_and(r038E, r0392);
               ir_swizzle *const r0394 = swizzle(r0393, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0395 = expr(ir_triop_csel, r0394, r0384, r0383);
               body.emit(assign(r01CE, expr(ir_triop_csel, r038C, r0395, r0384), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0380->else_instructions;

               body.emit(assign(r01CE, r01CB, 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


            body.instructions = f0380_parent_instructions;
            body.emit(f0380);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f037E->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0397 = equal(r036F, body.constant(int(0)));
            ir_if *f0396 = new(mem_ctx) ir_if(operand(r0397).val);
            exec_list *const f0396_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0396->then_instructions;

               body.emit(assign(r0364, add(r0364, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0396->else_instructions;

               body.emit(assign(r0367, bit_or(r0377, body.constant(1073741824u)), 0x01));


            body.instructions = f0396_parent_instructions;
            body.emit(f0396);

            /* END IF */

            ir_variable *const r0398 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0398);
            ir_variable *const r0399 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r039A = neg(r0364);
            body.emit(assign(r0399, bit_and(r039A, body.constant(int(31))), 0x01));

            ir_variable *const r039B = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r039C = less(r0364, body.constant(int(32)));
            ir_expression *const r039D = rshift(r0367, r0364);
            ir_expression *const r039E = equal(r0364, body.constant(int(0)));
            ir_expression *const r039F = expr(ir_triop_csel, r039E, r0367, body.constant(0u));
            body.emit(assign(r039B, expr(ir_triop_csel, r039C, r039D, r039F), 0x01));

            /* IF CONDITION */
            ir_expression *const r03A1 = equal(r0364, body.constant(int(0)));
            ir_if *f03A0 = new(mem_ctx) ir_if(operand(r03A1).val);
            exec_list *const f03A0_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03A0->then_instructions;

               body.emit(assign(r0398, r0378, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03A0->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03A3 = less(r0364, body.constant(int(32)));
               ir_if *f03A2 = new(mem_ctx) ir_if(operand(r03A3).val);
               exec_list *const f03A2_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03A2->then_instructions;

                  ir_expression *const r03A4 = lshift(r0367, r0399);
                  ir_expression *const r03A5 = rshift(r0378, r0364);
                  ir_expression *const r03A6 = bit_or(r03A4, r03A5);
                  ir_expression *const r03A7 = lshift(r0378, r0399);
                  ir_expression *const r03A8 = nequal(r03A7, body.constant(0u));
                  ir_expression *const r03A9 = expr(ir_unop_b2i, r03A8);
                  ir_expression *const r03AA = expr(ir_unop_i2u, r03A9);
                  body.emit(assign(r0398, bit_or(r03A6, r03AA), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03A2->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03AC = equal(r0364, body.constant(int(32)));
                  ir_if *f03AB = new(mem_ctx) ir_if(operand(r03AC).val);
                  exec_list *const f03AB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03AB->then_instructions;

                     ir_expression *const r03AD = nequal(r0378, body.constant(0u));
                     ir_expression *const r03AE = expr(ir_unop_b2i, r03AD);
                     ir_expression *const r03AF = expr(ir_unop_i2u, r03AE);
                     body.emit(assign(r0398, bit_or(r0367, r03AF), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03AB->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03B1 = less(r0364, body.constant(int(64)));
                     ir_if *f03B0 = new(mem_ctx) ir_if(operand(r03B1).val);
                     exec_list *const f03B0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03B0->then_instructions;

                        ir_expression *const r03B2 = bit_and(r0364, body.constant(int(31)));
                        ir_expression *const r03B3 = rshift(r0367, r03B2);
                        ir_expression *const r03B4 = lshift(r0367, r0399);
                        ir_expression *const r03B5 = bit_or(r03B4, r0378);
                        ir_expression *const r03B6 = nequal(r03B5, body.constant(0u));
                        ir_expression *const r03B7 = expr(ir_unop_b2i, r03B6);
                        ir_expression *const r03B8 = expr(ir_unop_i2u, r03B7);
                        body.emit(assign(r0398, bit_or(r03B3, r03B8), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03B0->else_instructions;

                        ir_expression *const r03B9 = bit_or(r0367, r0378);
                        ir_expression *const r03BA = nequal(r03B9, body.constant(0u));
                        ir_expression *const r03BB = expr(ir_unop_b2i, r03BA);
                        body.emit(assign(r0398, expr(ir_unop_i2u, r03BB), 0x01));


                     body.instructions = f03B0_parent_instructions;
                     body.emit(f03B0);

                     /* END IF */


                  body.instructions = f03AB_parent_instructions;
                  body.emit(f03AB);

                  /* END IF */


               body.instructions = f03A2_parent_instructions;
               body.emit(f03A2);

               /* END IF */


            body.instructions = f03A0_parent_instructions;
            body.emit(f03A0);

            /* END IF */

            body.emit(assign(r0367, r039B, 0x01));

            body.emit(assign(r0368, r0398, 0x01));

            body.emit(assign(r0369, bit_or(r0372, body.constant(1073741824u)), 0x01));

            ir_variable *const r03BC = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_expression *const r03BD = sub(r0369, r039B);
            ir_expression *const r03BE = less(r0373, r0398);
            ir_expression *const r03BF = expr(ir_unop_b2i, r03BE);
            ir_expression *const r03C0 = expr(ir_unop_i2u, r03BF);
            body.emit(assign(r03BC, sub(r03BD, r03C0), 0x01));

            body.emit(assign(r036B, add(r036C, body.constant(int(-1))), 0x01));

            ir_variable *const r03C1 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03C1, add(r036B, body.constant(int(-10))), 0x01));

            ir_variable *const r03C2 = body.make_temp(glsl_type::uint_type, "zFrac0");
            ir_variable *const r03C3 = body.make_temp(glsl_type::uint_type, "zFrac1");
            ir_variable *const r03C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03C4);
            ir_variable *const r03C5 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03C5);
            ir_expression *const r03C6 = equal(r03BC, body.constant(0u));
            ir_expression *const r03C7 = add(r03C1, body.constant(int(-32)));
            body.emit(assign(r03C1, expr(ir_triop_csel, r03C6, r03C7, r03C1), 0x01));

            ir_variable *const r03C8 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03C9 = equal(r03BC, body.constant(0u));
            ir_expression *const r03CA = sub(r0373, r0398);
            body.emit(assign(r03C8, expr(ir_triop_csel, r03C9, body.constant(0u), r03CA), 0x01));

            body.emit(assign(r03C3, r03C8, 0x01));

            ir_variable *const r03CB = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03CC = equal(r03BC, body.constant(0u));
            body.emit(assign(r03CB, expr(ir_triop_csel, r03CC, r03C8, r03BC), 0x01));

            body.emit(assign(r03C2, r03CB, 0x01));

            ir_expression *const r03CD = equal(r03CB, body.constant(0u));
            ir_expression *const r03CE = expr(ir_unop_find_msb, r03CB);
            ir_expression *const r03CF = sub(body.constant(int(31)), r03CE);
            ir_expression *const r03D0 = expr(ir_triop_csel, r03CD, body.constant(int(32)), r03CF);
            body.emit(assign(r03C5, add(r03D0, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03D2 = gequal(r03C5, body.constant(int(0)));
            ir_if *f03D1 = new(mem_ctx) ir_if(operand(r03D2).val);
            exec_list *const f03D1_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03D1->then_instructions;

               body.emit(assign(r03C4, body.constant(0u), 0x01));

               ir_expression *const r03D3 = equal(r03C5, body.constant(int(0)));
               ir_expression *const r03D4 = lshift(r03CB, r03C5);
               ir_expression *const r03D5 = neg(r03C5);
               ir_expression *const r03D6 = bit_and(r03D5, body.constant(int(31)));
               ir_expression *const r03D7 = rshift(r03C8, r03D6);
               ir_expression *const r03D8 = bit_or(r03D4, r03D7);
               body.emit(assign(r03C2, expr(ir_triop_csel, r03D3, r03CB, r03D8), 0x01));

               body.emit(assign(r03C3, lshift(r03C8, r03C5), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03D1->else_instructions;

               ir_variable *const r03D9 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r03D9, body.constant(0u), 0x01));

               ir_variable *const r03DA = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r03DA, neg(r03C5), 0x01));

               ir_variable *const r03DB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r03DB);
               ir_variable *const r03DC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r03DC);
               ir_variable *const r03DD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r03DD);
               ir_variable *const r03DE = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r03DF = neg(r03DA);
               body.emit(assign(r03DE, bit_and(r03DF, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r03E1 = equal(r03DA, body.constant(int(0)));
               ir_if *f03E0 = new(mem_ctx) ir_if(operand(r03E1).val);
               exec_list *const f03E0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E0->then_instructions;

                  body.emit(assign(r03DB, r03D9, 0x01));

                  body.emit(assign(r03DC, r03C3, 0x01));

                  body.emit(assign(r03DD, r03C2, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03E0->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03E3 = less(r03DA, body.constant(int(32)));
                  ir_if *f03E2 = new(mem_ctx) ir_if(operand(r03E3).val);
                  exec_list *const f03E2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03E2->then_instructions;

                     body.emit(assign(r03DB, lshift(r03C3, r03DE), 0x01));

                     ir_expression *const r03E4 = lshift(r03C2, r03DE);
                     ir_expression *const r03E5 = rshift(r03C3, r03DA);
                     body.emit(assign(r03DC, bit_or(r03E4, r03E5), 0x01));

                     body.emit(assign(r03DD, rshift(r03C2, r03DA), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03E2->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03E7 = equal(r03DA, body.constant(int(32)));
                     ir_if *f03E6 = new(mem_ctx) ir_if(operand(r03E7).val);
                     exec_list *const f03E6_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03E6->then_instructions;

                        body.emit(assign(r03DB, r03C3, 0x01));

                        body.emit(assign(r03DC, r03C2, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03E6->else_instructions;

                        body.emit(assign(r03D9, bit_or(body.constant(0u), r03C3), 0x01));

                        ir_expression *const r03E8 = less(r03DA, body.constant(int(64)));
                        ir_expression *const r03E9 = lshift(r03C2, r03DE);
                        ir_expression *const r03EA = equal(r03DA, body.constant(int(64)));
                        ir_expression *const r03EB = nequal(r03C2, body.constant(0u));
                        ir_expression *const r03EC = expr(ir_unop_b2i, r03EB);
                        ir_expression *const r03ED = expr(ir_unop_i2u, r03EC);
                        ir_expression *const r03EE = expr(ir_triop_csel, r03EA, r03C2, r03ED);
                        body.emit(assign(r03DB, expr(ir_triop_csel, r03E8, r03E9, r03EE), 0x01));

                        ir_expression *const r03EF = less(r03DA, body.constant(int(64)));
                        ir_expression *const r03F0 = bit_and(r03DA, body.constant(int(31)));
                        ir_expression *const r03F1 = rshift(r03C2, r03F0);
                        body.emit(assign(r03DC, expr(ir_triop_csel, r03EF, r03F1, body.constant(0u)), 0x01));


                     body.instructions = f03E6_parent_instructions;
                     body.emit(f03E6);

                     /* END IF */

                     body.emit(assign(r03DD, body.constant(0u), 0x01));


                  body.instructions = f03E2_parent_instructions;
                  body.emit(f03E2);

                  /* END IF */

                  ir_expression *const r03F2 = nequal(r03D9, body.constant(0u));
                  ir_expression *const r03F3 = expr(ir_unop_b2i, r03F2);
                  ir_expression *const r03F4 = expr(ir_unop_i2u, r03F3);
                  body.emit(assign(r03DB, bit_or(r03DB, r03F4), 0x01));


               body.instructions = f03E0_parent_instructions;
               body.emit(f03E0);

               /* END IF */

               body.emit(assign(r03C2, r03DD, 0x01));

               body.emit(assign(r03C3, r03DC, 0x01));

               body.emit(assign(r03C4, r03DB, 0x01));


            body.instructions = f03D1_parent_instructions;
            body.emit(f03D1);

            /* END IF */

            body.emit(assign(r03C1, sub(r03C1, r03C5), 0x01));

            ir_variable *const r03F5 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03F5, r03C1, 0x01));

            ir_variable *const r03F6 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03F6, r03C2, 0x01));

            ir_variable *const r03F7 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03F7, r03C3, 0x01));

            ir_variable *const r03F8 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r03F8, r03C4, 0x01));

            ir_variable *const r03F9 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r03F9, body.constant(true), 0x01));

            ir_variable *const r03FA = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r03FB = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r03FB);
            ir_expression *const r03FC = expr(ir_unop_u2i, r03C4);
            body.emit(assign(r03FB, less(r03FC, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03FE = gequal(r03C1, body.constant(int(2045)));
            ir_if *f03FD = new(mem_ctx) ir_if(operand(r03FE).val);
            exec_list *const f03FD_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03FD->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0400 = less(body.constant(int(2045)), r03C1);
               ir_expression *const r0401 = equal(r03C1, body.constant(int(2045)));
               ir_expression *const r0402 = equal(body.constant(2097151u), r03C2);
               ir_expression *const r0403 = equal(body.constant(4294967295u), r03C3);
               ir_expression *const r0404 = logic_and(r0402, r0403);
               ir_expression *const r0405 = logic_and(r0401, r0404);
               ir_expression *const r0406 = logic_and(r0405, r03FB);
               ir_expression *const r0407 = logic_or(r0400, r0406);
               ir_if *f03FF = new(mem_ctx) ir_if(operand(r0407).val);
               exec_list *const f03FF_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03FF->then_instructions;

                  ir_variable *const r0408 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0408);
                  ir_expression *const r0409 = lshift(r01D0, body.constant(int(31)));
                  body.emit(assign(r0408, add(r0409, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0408, body.constant(0u), 0x01));

                  body.emit(assign(r03FA, r0408, 0x03));

                  body.emit(assign(r03F9, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03FF->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r040B = less(r03C1, body.constant(int(0)));
                  ir_if *f040A = new(mem_ctx) ir_if(operand(r040B).val);
                  exec_list *const f040A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f040A->then_instructions;

                     ir_variable *const r040C = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r040C, r03C4, 0x01));

                     ir_variable *const r040D = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r040D, neg(r03C1), 0x01));

                     ir_variable *const r040E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r040E);
                     ir_variable *const r040F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r040F);
                     ir_variable *const r0410 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0410);
                     ir_variable *const r0411 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0412 = neg(r040D);
                     body.emit(assign(r0411, bit_and(r0412, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0414 = equal(r040D, body.constant(int(0)));
                     ir_if *f0413 = new(mem_ctx) ir_if(operand(r0414).val);
                     exec_list *const f0413_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0413->then_instructions;

                        body.emit(assign(r040E, r03C4, 0x01));

                        body.emit(assign(r040F, r03C3, 0x01));

                        body.emit(assign(r0410, r03C2, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0413->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0416 = less(r040D, body.constant(int(32)));
                        ir_if *f0415 = new(mem_ctx) ir_if(operand(r0416).val);
                        exec_list *const f0415_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0415->then_instructions;

                           body.emit(assign(r040E, lshift(r03C3, r0411), 0x01));

                           ir_expression *const r0417 = lshift(r03C2, r0411);
                           ir_expression *const r0418 = rshift(r03C3, r040D);
                           body.emit(assign(r040F, bit_or(r0417, r0418), 0x01));

                           body.emit(assign(r0410, rshift(r03C2, r040D), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0415->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r041A = equal(r040D, body.constant(int(32)));
                           ir_if *f0419 = new(mem_ctx) ir_if(operand(r041A).val);
                           exec_list *const f0419_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0419->then_instructions;

                              body.emit(assign(r040E, r03C3, 0x01));

                              body.emit(assign(r040F, r03C2, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0419->else_instructions;

                              body.emit(assign(r040C, bit_or(r03C4, r03C3), 0x01));

                              ir_expression *const r041B = less(r040D, body.constant(int(64)));
                              ir_expression *const r041C = lshift(r03C2, r0411);
                              ir_expression *const r041D = equal(r040D, body.constant(int(64)));
                              ir_expression *const r041E = nequal(r03C2, body.constant(0u));
                              ir_expression *const r041F = expr(ir_unop_b2i, r041E);
                              ir_expression *const r0420 = expr(ir_unop_i2u, r041F);
                              ir_expression *const r0421 = expr(ir_triop_csel, r041D, r03C2, r0420);
                              body.emit(assign(r040E, expr(ir_triop_csel, r041B, r041C, r0421), 0x01));

                              ir_expression *const r0422 = less(r040D, body.constant(int(64)));
                              ir_expression *const r0423 = bit_and(r040D, body.constant(int(31)));
                              ir_expression *const r0424 = rshift(r03C2, r0423);
                              body.emit(assign(r040F, expr(ir_triop_csel, r0422, r0424, body.constant(0u)), 0x01));


                           body.instructions = f0419_parent_instructions;
                           body.emit(f0419);

                           /* END IF */

                           body.emit(assign(r0410, body.constant(0u), 0x01));


                        body.instructions = f0415_parent_instructions;
                        body.emit(f0415);

                        /* END IF */

                        ir_expression *const r0425 = nequal(r040C, body.constant(0u));
                        ir_expression *const r0426 = expr(ir_unop_b2i, r0425);
                        ir_expression *const r0427 = expr(ir_unop_i2u, r0426);
                        body.emit(assign(r040E, bit_or(r040E, r0427), 0x01));


                     body.instructions = f0413_parent_instructions;
                     body.emit(f0413);

                     /* END IF */

                     body.emit(assign(r03F6, r0410, 0x01));

                     body.emit(assign(r03F7, r040F, 0x01));

                     body.emit(assign(r03F8, r040E, 0x01));

                     body.emit(assign(r03F5, body.constant(int(0)), 0x01));

                     body.emit(assign(r03FB, less(r040E, body.constant(0u)), 0x01));


                  body.instructions = f040A_parent_instructions;
                  body.emit(f040A);

                  /* END IF */


               body.instructions = f03FF_parent_instructions;
               body.emit(f03FF);

               /* END IF */


            body.instructions = f03FD_parent_instructions;
            body.emit(f03FD);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0428 = new(mem_ctx) ir_if(operand(r03F9).val);
            exec_list *const f0428_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0428->then_instructions;

               /* IF CONDITION */
               ir_if *f0429 = new(mem_ctx) ir_if(operand(r03FB).val);
               exec_list *const f0429_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0429->then_instructions;

                  ir_variable *const r042A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r042A, add(r03F7, body.constant(1u)), 0x01));

                  ir_expression *const r042B = less(r042A, r03F7);
                  ir_expression *const r042C = expr(ir_unop_b2i, r042B);
                  ir_expression *const r042D = expr(ir_unop_i2u, r042C);
                  body.emit(assign(r03F6, add(r03F6, r042D), 0x01));

                  ir_expression *const r042E = equal(r03F8, body.constant(0u));
                  ir_expression *const r042F = expr(ir_unop_b2i, r042E);
                  ir_expression *const r0430 = expr(ir_unop_i2u, r042F);
                  ir_expression *const r0431 = add(r03F8, r0430);
                  ir_expression *const r0432 = bit_and(r0431, body.constant(1u));
                  ir_expression *const r0433 = expr(ir_unop_bit_not, r0432);
                  body.emit(assign(r03F7, bit_and(r042A, r0433), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0429->else_instructions;

                  ir_expression *const r0434 = bit_or(r03F6, r03F7);
                  ir_expression *const r0435 = equal(r0434, body.constant(0u));
                  body.emit(assign(r03F5, expr(ir_triop_csel, r0435, body.constant(int(0)), r03F5), 0x01));


               body.instructions = f0429_parent_instructions;
               body.emit(f0429);

               /* END IF */

               ir_variable *const r0436 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0436);
               ir_expression *const r0437 = lshift(r01D0, body.constant(int(31)));
               ir_expression *const r0438 = expr(ir_unop_i2u, r03F5);
               ir_expression *const r0439 = lshift(r0438, body.constant(int(20)));
               ir_expression *const r043A = add(r0437, r0439);
               body.emit(assign(r0436, add(r043A, r03F6), 0x02));

               body.emit(assign(r0436, r03F7, 0x01));

               body.emit(assign(r03FA, r0436, 0x03));

               body.emit(assign(r03F9, body.constant(false), 0x01));


            body.instructions = f0428_parent_instructions;
            body.emit(f0428);

            /* END IF */

            body.emit(assign(r01CE, r03FA, 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


         body.instructions = f037E_parent_instructions;
         body.emit(f037E);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f037C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r043C = less(r0364, body.constant(int(0)));
         ir_if *f043B = new(mem_ctx) ir_if(operand(r043C).val);
         exec_list *const f043B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f043B->then_instructions;

            /* IF CONDITION */
            ir_expression *const r043E = equal(r036F, body.constant(int(2047)));
            ir_if *f043D = new(mem_ctx) ir_if(operand(r043E).val);
            exec_list *const f043D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f043D->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0440 = bit_or(r0367, r0368);
               ir_expression *const r0441 = nequal(r0440, body.constant(0u));
               ir_if *f043F = new(mem_ctx) ir_if(operand(r0441).val);
               exec_list *const f043F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f043F->then_instructions;

                  ir_variable *const r0442 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0442, swizzle_x(r01CB), 0x01));

                  ir_variable *const r0443 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0443, swizzle_x(r01CC), 0x01));

                  body.emit(assign(r0442, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

                  body.emit(assign(r0443, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

                  ir_expression *const r0444 = lshift(swizzle_y(r01CB), body.constant(int(1)));
                  ir_expression *const r0445 = gequal(r0444, body.constant(4292870144u));
                  ir_expression *const r0446 = nequal(swizzle_x(r01CB), body.constant(0u));
                  ir_expression *const r0447 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
                  ir_expression *const r0448 = nequal(r0447, body.constant(0u));
                  ir_expression *const r0449 = logic_or(r0446, r0448);
                  ir_expression *const r044A = logic_and(r0445, r0449);
                  ir_swizzle *const r044B = swizzle(r044A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r044C = lshift(swizzle_y(r01CC), body.constant(int(1)));
                  ir_expression *const r044D = gequal(r044C, body.constant(4292870144u));
                  ir_expression *const r044E = nequal(swizzle_x(r01CC), body.constant(0u));
                  ir_expression *const r044F = bit_and(swizzle_y(r01CC), body.constant(1048575u));
                  ir_expression *const r0450 = nequal(r044F, body.constant(0u));
                  ir_expression *const r0451 = logic_or(r044E, r0450);
                  ir_expression *const r0452 = logic_and(r044D, r0451);
                  ir_swizzle *const r0453 = swizzle(r0452, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0454 = expr(ir_triop_csel, r0453, r0443, r0442);
                  body.emit(assign(r01CE, expr(ir_triop_csel, r044B, r0454, r0443), 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f043F->else_instructions;

                  ir_variable *const r0455 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0455);
                  ir_expression *const r0456 = bit_xor(r01D0, body.constant(1u));
                  ir_expression *const r0457 = lshift(r0456, body.constant(int(31)));
                  body.emit(assign(r0455, add(r0457, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0455, body.constant(0u), 0x01));

                  body.emit(assign(r01CE, r0455, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


               body.instructions = f043F_parent_instructions;
               body.emit(f043F);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f043D->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0459 = equal(r036C, body.constant(int(0)));
               ir_if *f0458 = new(mem_ctx) ir_if(operand(r0459).val);
               exec_list *const f0458_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0458->then_instructions;

                  body.emit(assign(r0364, add(r0364, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0458->else_instructions;

                  body.emit(assign(r0369, bit_or(r0369, body.constant(1073741824u)), 0x01));


               body.instructions = f0458_parent_instructions;
               body.emit(f0458);

               /* END IF */

               ir_variable *const r045A = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r045A, neg(r0364), 0x01));

               ir_variable *const r045B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r045B);
               ir_variable *const r045C = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r045D = neg(r045A);
               body.emit(assign(r045C, bit_and(r045D, body.constant(int(31))), 0x01));

               ir_variable *const r045E = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r045F = less(r045A, body.constant(int(32)));
               ir_expression *const r0460 = rshift(r0369, r045A);
               ir_expression *const r0461 = equal(r045A, body.constant(int(0)));
               ir_expression *const r0462 = expr(ir_triop_csel, r0461, r0369, body.constant(0u));
               body.emit(assign(r045E, expr(ir_triop_csel, r045F, r0460, r0462), 0x01));

               /* IF CONDITION */
               ir_expression *const r0464 = equal(r045A, body.constant(int(0)));
               ir_if *f0463 = new(mem_ctx) ir_if(operand(r0464).val);
               exec_list *const f0463_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0463->then_instructions;

                  body.emit(assign(r045B, r0373, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0463->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0466 = less(r045A, body.constant(int(32)));
                  ir_if *f0465 = new(mem_ctx) ir_if(operand(r0466).val);
                  exec_list *const f0465_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0465->then_instructions;

                     ir_expression *const r0467 = lshift(r0369, r045C);
                     ir_expression *const r0468 = rshift(r0373, r045A);
                     ir_expression *const r0469 = bit_or(r0467, r0468);
                     ir_expression *const r046A = lshift(r0373, r045C);
                     ir_expression *const r046B = nequal(r046A, body.constant(0u));
                     ir_expression *const r046C = expr(ir_unop_b2i, r046B);
                     ir_expression *const r046D = expr(ir_unop_i2u, r046C);
                     body.emit(assign(r045B, bit_or(r0469, r046D), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0465->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r046F = equal(r045A, body.constant(int(32)));
                     ir_if *f046E = new(mem_ctx) ir_if(operand(r046F).val);
                     exec_list *const f046E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f046E->then_instructions;

                        ir_expression *const r0470 = nequal(r0373, body.constant(0u));
                        ir_expression *const r0471 = expr(ir_unop_b2i, r0470);
                        ir_expression *const r0472 = expr(ir_unop_i2u, r0471);
                        body.emit(assign(r045B, bit_or(r0369, r0472), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f046E->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0474 = less(r045A, body.constant(int(64)));
                        ir_if *f0473 = new(mem_ctx) ir_if(operand(r0474).val);
                        exec_list *const f0473_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0473->then_instructions;

                           ir_expression *const r0475 = bit_and(r045A, body.constant(int(31)));
                           ir_expression *const r0476 = rshift(r0369, r0475);
                           ir_expression *const r0477 = lshift(r0369, r045C);
                           ir_expression *const r0478 = bit_or(r0477, r0373);
                           ir_expression *const r0479 = nequal(r0478, body.constant(0u));
                           ir_expression *const r047A = expr(ir_unop_b2i, r0479);
                           ir_expression *const r047B = expr(ir_unop_i2u, r047A);
                           body.emit(assign(r045B, bit_or(r0476, r047B), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0473->else_instructions;

                           ir_expression *const r047C = bit_or(r0369, r0373);
                           ir_expression *const r047D = nequal(r047C, body.constant(0u));
                           ir_expression *const r047E = expr(ir_unop_b2i, r047D);
                           body.emit(assign(r045B, expr(ir_unop_i2u, r047E), 0x01));


                        body.instructions = f0473_parent_instructions;
                        body.emit(f0473);

                        /* END IF */


                     body.instructions = f046E_parent_instructions;
                     body.emit(f046E);

                     /* END IF */


                  body.instructions = f0465_parent_instructions;
                  body.emit(f0465);

                  /* END IF */


               body.instructions = f0463_parent_instructions;
               body.emit(f0463);

               /* END IF */

               body.emit(assign(r0369, r045E, 0x01));

               body.emit(assign(r036A, r045B, 0x01));

               body.emit(assign(r0367, bit_or(r0367, body.constant(1073741824u)), 0x01));

               ir_variable *const r047F = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_expression *const r0480 = sub(r0367, r045E);
               ir_expression *const r0481 = less(r0368, r045B);
               ir_expression *const r0482 = expr(ir_unop_b2i, r0481);
               ir_expression *const r0483 = expr(ir_unop_i2u, r0482);
               body.emit(assign(r047F, sub(r0480, r0483), 0x01));

               body.emit(assign(r01CF, bit_xor(r01D0, body.constant(1u)), 0x01));

               body.emit(assign(r036B, add(r036F, body.constant(int(-1))), 0x01));

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
               ir_expression *const r048D = sub(r0368, r045B);
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
                     ir_expression *const r04CC = lshift(r01CF, body.constant(int(31)));
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
                  ir_expression *const r04FA = lshift(r01CF, body.constant(int(31)));
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

               body.emit(assign(r01CE, r04BD, 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


            body.instructions = f043D_parent_instructions;
            body.emit(f043D);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f043B->else_instructions;

            /* IF CONDITION */
            ir_expression *const r04FF = equal(r036C, body.constant(int(2047)));
            ir_if *f04FE = new(mem_ctx) ir_if(operand(r04FF).val);
            exec_list *const f04FE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f04FE->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0501 = bit_or(r0369, r036A);
               ir_expression *const r0502 = bit_or(r0367, r0368);
               ir_expression *const r0503 = bit_or(r0501, r0502);
               ir_expression *const r0504 = nequal(r0503, body.constant(0u));
               ir_if *f0500 = new(mem_ctx) ir_if(operand(r0504).val);
               exec_list *const f0500_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0500->then_instructions;

                  ir_variable *const r0505 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0505, swizzle_x(r01CB), 0x01));

                  ir_variable *const r0506 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0506, swizzle_x(r01CC), 0x01));

                  body.emit(assign(r0505, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

                  body.emit(assign(r0506, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

                  ir_expression *const r0507 = lshift(swizzle_y(r01CB), body.constant(int(1)));
                  ir_expression *const r0508 = gequal(r0507, body.constant(4292870144u));
                  ir_expression *const r0509 = nequal(swizzle_x(r01CB), body.constant(0u));
                  ir_expression *const r050A = bit_and(swizzle_y(r01CB), body.constant(1048575u));
                  ir_expression *const r050B = nequal(r050A, body.constant(0u));
                  ir_expression *const r050C = logic_or(r0509, r050B);
                  ir_expression *const r050D = logic_and(r0508, r050C);
                  ir_swizzle *const r050E = swizzle(r050D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r050F = lshift(swizzle_y(r01CC), body.constant(int(1)));
                  ir_expression *const r0510 = gequal(r050F, body.constant(4292870144u));
                  ir_expression *const r0511 = nequal(swizzle_x(r01CC), body.constant(0u));
                  ir_expression *const r0512 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
                  ir_expression *const r0513 = nequal(r0512, body.constant(0u));
                  ir_expression *const r0514 = logic_or(r0511, r0513);
                  ir_expression *const r0515 = logic_and(r0510, r0514);
                  ir_swizzle *const r0516 = swizzle(r0515, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0517 = expr(ir_triop_csel, r0516, r0506, r0505);
                  body.emit(assign(r01CE, expr(ir_triop_csel, r050E, r0517, r0506), 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0500->else_instructions;

                  ir_constant_data r0518_data;
                  memset(&r0518_data, 0, sizeof(ir_constant_data));
                  r0518_data.u[0] = 4294967295;
                  r0518_data.u[1] = 4294967295;
                  ir_constant *const r0518 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0518_data);
                  body.emit(assign(r01CE, r0518, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


               body.instructions = f0500_parent_instructions;
               body.emit(f0500);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f04FE->else_instructions;

               ir_expression *const r0519 = equal(r036C, body.constant(int(0)));
               body.emit(assign(r0365, expr(ir_triop_csel, r0519, body.constant(int(1)), r036F), 0x01));

               ir_expression *const r051A = equal(r036C, body.constant(int(0)));
               body.emit(assign(r0366, expr(ir_triop_csel, r051A, body.constant(int(1)), r036C), 0x01));

               /* IF CONDITION */
               ir_expression *const r051C = less(r0367, r0369);
               ir_if *f051B = new(mem_ctx) ir_if(operand(r051C).val);
               exec_list *const f051B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f051B->then_instructions;

                  ir_variable *const r051D = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_expression *const r051E = sub(r0369, r0367);
                  ir_expression *const r051F = less(r036A, r0368);
                  ir_expression *const r0520 = expr(ir_unop_b2i, r051F);
                  ir_expression *const r0521 = expr(ir_unop_i2u, r0520);
                  body.emit(assign(r051D, sub(r051E, r0521), 0x01));

                  body.emit(assign(r036B, add(r0366, body.constant(int(-1))), 0x01));

                  ir_variable *const r0522 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0522, add(r036B, body.constant(int(-10))), 0x01));

                  ir_variable *const r0523 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  ir_variable *const r0524 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  ir_variable *const r0525 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r0525);
                  ir_variable *const r0526 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0526);
                  ir_expression *const r0527 = equal(r051D, body.constant(0u));
                  ir_expression *const r0528 = add(r0522, body.constant(int(-32)));
                  body.emit(assign(r0522, expr(ir_triop_csel, r0527, r0528, r0522), 0x01));

                  ir_variable *const r0529 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r052A = equal(r051D, body.constant(0u));
                  ir_expression *const r052B = sub(r036A, r0368);
                  body.emit(assign(r0529, expr(ir_triop_csel, r052A, body.constant(0u), r052B), 0x01));

                  body.emit(assign(r0524, r0529, 0x01));

                  ir_variable *const r052C = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r052D = equal(r051D, body.constant(0u));
                  body.emit(assign(r052C, expr(ir_triop_csel, r052D, r0529, r051D), 0x01));

                  body.emit(assign(r0523, r052C, 0x01));

                  ir_expression *const r052E = equal(r052C, body.constant(0u));
                  ir_expression *const r052F = expr(ir_unop_find_msb, r052C);
                  ir_expression *const r0530 = sub(body.constant(int(31)), r052F);
                  ir_expression *const r0531 = expr(ir_triop_csel, r052E, body.constant(int(32)), r0530);
                  body.emit(assign(r0526, add(r0531, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0533 = gequal(r0526, body.constant(int(0)));
                  ir_if *f0532 = new(mem_ctx) ir_if(operand(r0533).val);
                  exec_list *const f0532_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0532->then_instructions;

                     body.emit(assign(r0525, body.constant(0u), 0x01));

                     ir_expression *const r0534 = equal(r0526, body.constant(int(0)));
                     ir_expression *const r0535 = lshift(r052C, r0526);
                     ir_expression *const r0536 = neg(r0526);
                     ir_expression *const r0537 = bit_and(r0536, body.constant(int(31)));
                     ir_expression *const r0538 = rshift(r0529, r0537);
                     ir_expression *const r0539 = bit_or(r0535, r0538);
                     body.emit(assign(r0523, expr(ir_triop_csel, r0534, r052C, r0539), 0x01));

                     body.emit(assign(r0524, lshift(r0529, r0526), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0532->else_instructions;

                     ir_variable *const r053A = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r053A, body.constant(0u), 0x01));

                     ir_variable *const r053B = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r053B, neg(r0526), 0x01));

                     ir_variable *const r053C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r053C);
                     ir_variable *const r053D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r053D);
                     ir_variable *const r053E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r053E);
                     ir_variable *const r053F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0540 = neg(r053B);
                     body.emit(assign(r053F, bit_and(r0540, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0542 = equal(r053B, body.constant(int(0)));
                     ir_if *f0541 = new(mem_ctx) ir_if(operand(r0542).val);
                     exec_list *const f0541_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0541->then_instructions;

                        body.emit(assign(r053C, r053A, 0x01));

                        body.emit(assign(r053D, r0524, 0x01));

                        body.emit(assign(r053E, r0523, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0541->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0544 = less(r053B, body.constant(int(32)));
                        ir_if *f0543 = new(mem_ctx) ir_if(operand(r0544).val);
                        exec_list *const f0543_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0543->then_instructions;

                           body.emit(assign(r053C, lshift(r0524, r053F), 0x01));

                           ir_expression *const r0545 = lshift(r0523, r053F);
                           ir_expression *const r0546 = rshift(r0524, r053B);
                           body.emit(assign(r053D, bit_or(r0545, r0546), 0x01));

                           body.emit(assign(r053E, rshift(r0523, r053B), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0543->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0548 = equal(r053B, body.constant(int(32)));
                           ir_if *f0547 = new(mem_ctx) ir_if(operand(r0548).val);
                           exec_list *const f0547_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0547->then_instructions;

                              body.emit(assign(r053C, r0524, 0x01));

                              body.emit(assign(r053D, r0523, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0547->else_instructions;

                              body.emit(assign(r053A, bit_or(body.constant(0u), r0524), 0x01));

                              ir_expression *const r0549 = less(r053B, body.constant(int(64)));
                              ir_expression *const r054A = lshift(r0523, r053F);
                              ir_expression *const r054B = equal(r053B, body.constant(int(64)));
                              ir_expression *const r054C = nequal(r0523, body.constant(0u));
                              ir_expression *const r054D = expr(ir_unop_b2i, r054C);
                              ir_expression *const r054E = expr(ir_unop_i2u, r054D);
                              ir_expression *const r054F = expr(ir_triop_csel, r054B, r0523, r054E);
                              body.emit(assign(r053C, expr(ir_triop_csel, r0549, r054A, r054F), 0x01));

                              ir_expression *const r0550 = less(r053B, body.constant(int(64)));
                              ir_expression *const r0551 = bit_and(r053B, body.constant(int(31)));
                              ir_expression *const r0552 = rshift(r0523, r0551);
                              body.emit(assign(r053D, expr(ir_triop_csel, r0550, r0552, body.constant(0u)), 0x01));


                           body.instructions = f0547_parent_instructions;
                           body.emit(f0547);

                           /* END IF */

                           body.emit(assign(r053E, body.constant(0u), 0x01));


                        body.instructions = f0543_parent_instructions;
                        body.emit(f0543);

                        /* END IF */

                        ir_expression *const r0553 = nequal(r053A, body.constant(0u));
                        ir_expression *const r0554 = expr(ir_unop_b2i, r0553);
                        ir_expression *const r0555 = expr(ir_unop_i2u, r0554);
                        body.emit(assign(r053C, bit_or(r053C, r0555), 0x01));


                     body.instructions = f0541_parent_instructions;
                     body.emit(f0541);

                     /* END IF */

                     body.emit(assign(r0523, r053E, 0x01));

                     body.emit(assign(r0524, r053D, 0x01));

                     body.emit(assign(r0525, r053C, 0x01));


                  body.instructions = f0532_parent_instructions;
                  body.emit(f0532);

                  /* END IF */

                  body.emit(assign(r0522, sub(r0522, r0526), 0x01));

                  ir_variable *const r0556 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0556, r0522, 0x01));

                  ir_variable *const r0557 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0557, r0523, 0x01));

                  ir_variable *const r0558 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0558, r0524, 0x01));

                  ir_variable *const r0559 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0559, r0525, 0x01));

                  ir_variable *const r055A = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r055A, body.constant(true), 0x01));

                  ir_variable *const r055B = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r055C = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r055C);
                  ir_expression *const r055D = expr(ir_unop_u2i, r0525);
                  body.emit(assign(r055C, less(r055D, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r055F = gequal(r0522, body.constant(int(2045)));
                  ir_if *f055E = new(mem_ctx) ir_if(operand(r055F).val);
                  exec_list *const f055E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f055E->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0561 = less(body.constant(int(2045)), r0522);
                     ir_expression *const r0562 = equal(r0522, body.constant(int(2045)));
                     ir_expression *const r0563 = equal(body.constant(2097151u), r0523);
                     ir_expression *const r0564 = equal(body.constant(4294967295u), r0524);
                     ir_expression *const r0565 = logic_and(r0563, r0564);
                     ir_expression *const r0566 = logic_and(r0562, r0565);
                     ir_expression *const r0567 = logic_and(r0566, r055C);
                     ir_expression *const r0568 = logic_or(r0561, r0567);
                     ir_if *f0560 = new(mem_ctx) ir_if(operand(r0568).val);
                     exec_list *const f0560_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0560->then_instructions;

                        ir_variable *const r0569 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0569);
                        ir_expression *const r056A = lshift(r01CF, body.constant(int(31)));
                        body.emit(assign(r0569, add(r056A, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0569, body.constant(0u), 0x01));

                        body.emit(assign(r055B, r0569, 0x03));

                        body.emit(assign(r055A, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0560->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r056C = less(r0522, body.constant(int(0)));
                        ir_if *f056B = new(mem_ctx) ir_if(operand(r056C).val);
                        exec_list *const f056B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f056B->then_instructions;

                           ir_variable *const r056D = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r056D, r0525, 0x01));

                           ir_variable *const r056E = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r056E, neg(r0522), 0x01));

                           ir_variable *const r056F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r056F);
                           ir_variable *const r0570 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0570);
                           ir_variable *const r0571 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0571);
                           ir_variable *const r0572 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0573 = neg(r056E);
                           body.emit(assign(r0572, bit_and(r0573, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0575 = equal(r056E, body.constant(int(0)));
                           ir_if *f0574 = new(mem_ctx) ir_if(operand(r0575).val);
                           exec_list *const f0574_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0574->then_instructions;

                              body.emit(assign(r056F, r0525, 0x01));

                              body.emit(assign(r0570, r0524, 0x01));

                              body.emit(assign(r0571, r0523, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0574->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0577 = less(r056E, body.constant(int(32)));
                              ir_if *f0576 = new(mem_ctx) ir_if(operand(r0577).val);
                              exec_list *const f0576_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0576->then_instructions;

                                 body.emit(assign(r056F, lshift(r0524, r0572), 0x01));

                                 ir_expression *const r0578 = lshift(r0523, r0572);
                                 ir_expression *const r0579 = rshift(r0524, r056E);
                                 body.emit(assign(r0570, bit_or(r0578, r0579), 0x01));

                                 body.emit(assign(r0571, rshift(r0523, r056E), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0576->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r057B = equal(r056E, body.constant(int(32)));
                                 ir_if *f057A = new(mem_ctx) ir_if(operand(r057B).val);
                                 exec_list *const f057A_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f057A->then_instructions;

                                    body.emit(assign(r056F, r0524, 0x01));

                                    body.emit(assign(r0570, r0523, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f057A->else_instructions;

                                    body.emit(assign(r056D, bit_or(r0525, r0524), 0x01));

                                    ir_expression *const r057C = less(r056E, body.constant(int(64)));
                                    ir_expression *const r057D = lshift(r0523, r0572);
                                    ir_expression *const r057E = equal(r056E, body.constant(int(64)));
                                    ir_expression *const r057F = nequal(r0523, body.constant(0u));
                                    ir_expression *const r0580 = expr(ir_unop_b2i, r057F);
                                    ir_expression *const r0581 = expr(ir_unop_i2u, r0580);
                                    ir_expression *const r0582 = expr(ir_triop_csel, r057E, r0523, r0581);
                                    body.emit(assign(r056F, expr(ir_triop_csel, r057C, r057D, r0582), 0x01));

                                    ir_expression *const r0583 = less(r056E, body.constant(int(64)));
                                    ir_expression *const r0584 = bit_and(r056E, body.constant(int(31)));
                                    ir_expression *const r0585 = rshift(r0523, r0584);
                                    body.emit(assign(r0570, expr(ir_triop_csel, r0583, r0585, body.constant(0u)), 0x01));


                                 body.instructions = f057A_parent_instructions;
                                 body.emit(f057A);

                                 /* END IF */

                                 body.emit(assign(r0571, body.constant(0u), 0x01));


                              body.instructions = f0576_parent_instructions;
                              body.emit(f0576);

                              /* END IF */

                              ir_expression *const r0586 = nequal(r056D, body.constant(0u));
                              ir_expression *const r0587 = expr(ir_unop_b2i, r0586);
                              ir_expression *const r0588 = expr(ir_unop_i2u, r0587);
                              body.emit(assign(r056F, bit_or(r056F, r0588), 0x01));


                           body.instructions = f0574_parent_instructions;
                           body.emit(f0574);

                           /* END IF */

                           body.emit(assign(r0557, r0571, 0x01));

                           body.emit(assign(r0558, r0570, 0x01));

                           body.emit(assign(r0559, r056F, 0x01));

                           body.emit(assign(r0556, body.constant(int(0)), 0x01));

                           body.emit(assign(r055C, less(r056F, body.constant(0u)), 0x01));


                        body.instructions = f056B_parent_instructions;
                        body.emit(f056B);

                        /* END IF */


                     body.instructions = f0560_parent_instructions;
                     body.emit(f0560);

                     /* END IF */


                  body.instructions = f055E_parent_instructions;
                  body.emit(f055E);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0589 = new(mem_ctx) ir_if(operand(r055A).val);
                  exec_list *const f0589_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0589->then_instructions;

                     /* IF CONDITION */
                     ir_if *f058A = new(mem_ctx) ir_if(operand(r055C).val);
                     exec_list *const f058A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f058A->then_instructions;

                        ir_variable *const r058B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r058B, add(r0558, body.constant(1u)), 0x01));

                        ir_expression *const r058C = less(r058B, r0558);
                        ir_expression *const r058D = expr(ir_unop_b2i, r058C);
                        ir_expression *const r058E = expr(ir_unop_i2u, r058D);
                        body.emit(assign(r0557, add(r0557, r058E), 0x01));

                        ir_expression *const r058F = equal(r0559, body.constant(0u));
                        ir_expression *const r0590 = expr(ir_unop_b2i, r058F);
                        ir_expression *const r0591 = expr(ir_unop_i2u, r0590);
                        ir_expression *const r0592 = add(r0559, r0591);
                        ir_expression *const r0593 = bit_and(r0592, body.constant(1u));
                        ir_expression *const r0594 = expr(ir_unop_bit_not, r0593);
                        body.emit(assign(r0558, bit_and(r058B, r0594), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f058A->else_instructions;

                        ir_expression *const r0595 = bit_or(r0557, r0558);
                        ir_expression *const r0596 = equal(r0595, body.constant(0u));
                        body.emit(assign(r0556, expr(ir_triop_csel, r0596, body.constant(int(0)), r0556), 0x01));


                     body.instructions = f058A_parent_instructions;
                     body.emit(f058A);

                     /* END IF */

                     ir_variable *const r0597 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0597);
                     ir_expression *const r0598 = lshift(r01CF, body.constant(int(31)));
                     ir_expression *const r0599 = expr(ir_unop_i2u, r0556);
                     ir_expression *const r059A = lshift(r0599, body.constant(int(20)));
                     ir_expression *const r059B = add(r0598, r059A);
                     body.emit(assign(r0597, add(r059B, r0557), 0x02));

                     body.emit(assign(r0597, r0558, 0x01));

                     body.emit(assign(r055B, r0597, 0x03));

                     body.emit(assign(r055A, body.constant(false), 0x01));


                  body.instructions = f0589_parent_instructions;
                  body.emit(f0589);

                  /* END IF */

                  body.emit(assign(r01CE, r055B, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f051B->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r059D = less(r0369, r0367);
                  ir_if *f059C = new(mem_ctx) ir_if(operand(r059D).val);
                  exec_list *const f059C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f059C->then_instructions;

                     ir_variable *const r059E = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_expression *const r059F = sub(r0367, r0369);
                     ir_expression *const r05A0 = less(r0368, r036A);
                     ir_expression *const r05A1 = expr(ir_unop_b2i, r05A0);
                     ir_expression *const r05A2 = expr(ir_unop_i2u, r05A1);
                     body.emit(assign(r059E, sub(r059F, r05A2), 0x01));

                     body.emit(assign(r01CF, bit_xor(r01CF, body.constant(1u)), 0x01));

                     body.emit(assign(r036B, add(r0365, body.constant(int(-1))), 0x01));

                     ir_variable *const r05A3 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05A3, add(r036B, body.constant(int(-10))), 0x01));

                     ir_variable *const r05A4 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     ir_variable *const r05A5 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     ir_variable *const r05A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r05A6);
                     ir_variable *const r05A7 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05A7);
                     ir_expression *const r05A8 = equal(r059E, body.constant(0u));
                     ir_expression *const r05A9 = add(r05A3, body.constant(int(-32)));
                     body.emit(assign(r05A3, expr(ir_triop_csel, r05A8, r05A9, r05A3), 0x01));

                     ir_variable *const r05AA = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05AB = equal(r059E, body.constant(0u));
                     ir_expression *const r05AC = sub(r0368, r036A);
                     body.emit(assign(r05AA, expr(ir_triop_csel, r05AB, body.constant(0u), r05AC), 0x01));

                     body.emit(assign(r05A5, r05AA, 0x01));

                     ir_variable *const r05AD = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05AE = equal(r059E, body.constant(0u));
                     body.emit(assign(r05AD, expr(ir_triop_csel, r05AE, r05AA, r059E), 0x01));

                     body.emit(assign(r05A4, r05AD, 0x01));

                     ir_expression *const r05AF = equal(r05AD, body.constant(0u));
                     ir_expression *const r05B0 = expr(ir_unop_find_msb, r05AD);
                     ir_expression *const r05B1 = sub(body.constant(int(31)), r05B0);
                     ir_expression *const r05B2 = expr(ir_triop_csel, r05AF, body.constant(int(32)), r05B1);
                     body.emit(assign(r05A7, add(r05B2, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05B4 = gequal(r05A7, body.constant(int(0)));
                     ir_if *f05B3 = new(mem_ctx) ir_if(operand(r05B4).val);
                     exec_list *const f05B3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05B3->then_instructions;

                        body.emit(assign(r05A6, body.constant(0u), 0x01));

                        ir_expression *const r05B5 = equal(r05A7, body.constant(int(0)));
                        ir_expression *const r05B6 = lshift(r05AD, r05A7);
                        ir_expression *const r05B7 = neg(r05A7);
                        ir_expression *const r05B8 = bit_and(r05B7, body.constant(int(31)));
                        ir_expression *const r05B9 = rshift(r05AA, r05B8);
                        ir_expression *const r05BA = bit_or(r05B6, r05B9);
                        body.emit(assign(r05A4, expr(ir_triop_csel, r05B5, r05AD, r05BA), 0x01));

                        body.emit(assign(r05A5, lshift(r05AA, r05A7), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05B3->else_instructions;

                        ir_variable *const r05BB = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r05BB, body.constant(0u), 0x01));

                        ir_variable *const r05BC = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r05BC, neg(r05A7), 0x01));

                        ir_variable *const r05BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r05BD);
                        ir_variable *const r05BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r05BE);
                        ir_variable *const r05BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r05BF);
                        ir_variable *const r05C0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r05C1 = neg(r05BC);
                        body.emit(assign(r05C0, bit_and(r05C1, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05C3 = equal(r05BC, body.constant(int(0)));
                        ir_if *f05C2 = new(mem_ctx) ir_if(operand(r05C3).val);
                        exec_list *const f05C2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05C2->then_instructions;

                           body.emit(assign(r05BD, r05BB, 0x01));

                           body.emit(assign(r05BE, r05A5, 0x01));

                           body.emit(assign(r05BF, r05A4, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05C2->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05C5 = less(r05BC, body.constant(int(32)));
                           ir_if *f05C4 = new(mem_ctx) ir_if(operand(r05C5).val);
                           exec_list *const f05C4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05C4->then_instructions;

                              body.emit(assign(r05BD, lshift(r05A5, r05C0), 0x01));

                              ir_expression *const r05C6 = lshift(r05A4, r05C0);
                              ir_expression *const r05C7 = rshift(r05A5, r05BC);
                              body.emit(assign(r05BE, bit_or(r05C6, r05C7), 0x01));

                              body.emit(assign(r05BF, rshift(r05A4, r05BC), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05C4->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05C9 = equal(r05BC, body.constant(int(32)));
                              ir_if *f05C8 = new(mem_ctx) ir_if(operand(r05C9).val);
                              exec_list *const f05C8_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05C8->then_instructions;

                                 body.emit(assign(r05BD, r05A5, 0x01));

                                 body.emit(assign(r05BE, r05A4, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05C8->else_instructions;

                                 body.emit(assign(r05BB, bit_or(body.constant(0u), r05A5), 0x01));

                                 ir_expression *const r05CA = less(r05BC, body.constant(int(64)));
                                 ir_expression *const r05CB = lshift(r05A4, r05C0);
                                 ir_expression *const r05CC = equal(r05BC, body.constant(int(64)));
                                 ir_expression *const r05CD = nequal(r05A4, body.constant(0u));
                                 ir_expression *const r05CE = expr(ir_unop_b2i, r05CD);
                                 ir_expression *const r05CF = expr(ir_unop_i2u, r05CE);
                                 ir_expression *const r05D0 = expr(ir_triop_csel, r05CC, r05A4, r05CF);
                                 body.emit(assign(r05BD, expr(ir_triop_csel, r05CA, r05CB, r05D0), 0x01));

                                 ir_expression *const r05D1 = less(r05BC, body.constant(int(64)));
                                 ir_expression *const r05D2 = bit_and(r05BC, body.constant(int(31)));
                                 ir_expression *const r05D3 = rshift(r05A4, r05D2);
                                 body.emit(assign(r05BE, expr(ir_triop_csel, r05D1, r05D3, body.constant(0u)), 0x01));


                              body.instructions = f05C8_parent_instructions;
                              body.emit(f05C8);

                              /* END IF */

                              body.emit(assign(r05BF, body.constant(0u), 0x01));


                           body.instructions = f05C4_parent_instructions;
                           body.emit(f05C4);

                           /* END IF */

                           ir_expression *const r05D4 = nequal(r05BB, body.constant(0u));
                           ir_expression *const r05D5 = expr(ir_unop_b2i, r05D4);
                           ir_expression *const r05D6 = expr(ir_unop_i2u, r05D5);
                           body.emit(assign(r05BD, bit_or(r05BD, r05D6), 0x01));


                        body.instructions = f05C2_parent_instructions;
                        body.emit(f05C2);

                        /* END IF */

                        body.emit(assign(r05A4, r05BF, 0x01));

                        body.emit(assign(r05A5, r05BE, 0x01));

                        body.emit(assign(r05A6, r05BD, 0x01));


                     body.instructions = f05B3_parent_instructions;
                     body.emit(f05B3);

                     /* END IF */

                     body.emit(assign(r05A3, sub(r05A3, r05A7), 0x01));

                     ir_variable *const r05D7 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05D7, r05A3, 0x01));

                     ir_variable *const r05D8 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r05D8, r05A4, 0x01));

                     ir_variable *const r05D9 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r05D9, r05A5, 0x01));

                     ir_variable *const r05DA = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r05DA, r05A6, 0x01));

                     ir_variable *const r05DB = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r05DB, body.constant(true), 0x01));

                     ir_variable *const r05DC = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r05DD = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r05DD);
                     ir_expression *const r05DE = expr(ir_unop_u2i, r05A6);
                     body.emit(assign(r05DD, less(r05DE, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05E0 = gequal(r05A3, body.constant(int(2045)));
                     ir_if *f05DF = new(mem_ctx) ir_if(operand(r05E0).val);
                     exec_list *const f05DF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05DF->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05E2 = less(body.constant(int(2045)), r05A3);
                        ir_expression *const r05E3 = equal(r05A3, body.constant(int(2045)));
                        ir_expression *const r05E4 = equal(body.constant(2097151u), r05A4);
                        ir_expression *const r05E5 = equal(body.constant(4294967295u), r05A5);
                        ir_expression *const r05E6 = logic_and(r05E4, r05E5);
                        ir_expression *const r05E7 = logic_and(r05E3, r05E6);
                        ir_expression *const r05E8 = logic_and(r05E7, r05DD);
                        ir_expression *const r05E9 = logic_or(r05E2, r05E8);
                        ir_if *f05E1 = new(mem_ctx) ir_if(operand(r05E9).val);
                        exec_list *const f05E1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E1->then_instructions;

                           ir_variable *const r05EA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r05EA);
                           ir_expression *const r05EB = lshift(r01CF, body.constant(int(31)));
                           body.emit(assign(r05EA, add(r05EB, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r05EA, body.constant(0u), 0x01));

                           body.emit(assign(r05DC, r05EA, 0x03));

                           body.emit(assign(r05DB, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05E1->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05ED = less(r05A3, body.constant(int(0)));
                           ir_if *f05EC = new(mem_ctx) ir_if(operand(r05ED).val);
                           exec_list *const f05EC_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05EC->then_instructions;

                              ir_variable *const r05EE = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r05EE, r05A6, 0x01));

                              ir_variable *const r05EF = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r05EF, neg(r05A3), 0x01));

                              ir_variable *const r05F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r05F0);
                              ir_variable *const r05F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r05F1);
                              ir_variable *const r05F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r05F2);
                              ir_variable *const r05F3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r05F4 = neg(r05EF);
                              body.emit(assign(r05F3, bit_and(r05F4, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r05F6 = equal(r05EF, body.constant(int(0)));
                              ir_if *f05F5 = new(mem_ctx) ir_if(operand(r05F6).val);
                              exec_list *const f05F5_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05F5->then_instructions;

                                 body.emit(assign(r05F0, r05A6, 0x01));

                                 body.emit(assign(r05F1, r05A5, 0x01));

                                 body.emit(assign(r05F2, r05A4, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05F5->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05F8 = less(r05EF, body.constant(int(32)));
                                 ir_if *f05F7 = new(mem_ctx) ir_if(operand(r05F8).val);
                                 exec_list *const f05F7_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05F7->then_instructions;

                                    body.emit(assign(r05F0, lshift(r05A5, r05F3), 0x01));

                                    ir_expression *const r05F9 = lshift(r05A4, r05F3);
                                    ir_expression *const r05FA = rshift(r05A5, r05EF);
                                    body.emit(assign(r05F1, bit_or(r05F9, r05FA), 0x01));

                                    body.emit(assign(r05F2, rshift(r05A4, r05EF), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05F7->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r05FC = equal(r05EF, body.constant(int(32)));
                                    ir_if *f05FB = new(mem_ctx) ir_if(operand(r05FC).val);
                                    exec_list *const f05FB_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f05FB->then_instructions;

                                       body.emit(assign(r05F0, r05A5, 0x01));

                                       body.emit(assign(r05F1, r05A4, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f05FB->else_instructions;

                                       body.emit(assign(r05EE, bit_or(r05A6, r05A5), 0x01));

                                       ir_expression *const r05FD = less(r05EF, body.constant(int(64)));
                                       ir_expression *const r05FE = lshift(r05A4, r05F3);
                                       ir_expression *const r05FF = equal(r05EF, body.constant(int(64)));
                                       ir_expression *const r0600 = nequal(r05A4, body.constant(0u));
                                       ir_expression *const r0601 = expr(ir_unop_b2i, r0600);
                                       ir_expression *const r0602 = expr(ir_unop_i2u, r0601);
                                       ir_expression *const r0603 = expr(ir_triop_csel, r05FF, r05A4, r0602);
                                       body.emit(assign(r05F0, expr(ir_triop_csel, r05FD, r05FE, r0603), 0x01));

                                       ir_expression *const r0604 = less(r05EF, body.constant(int(64)));
                                       ir_expression *const r0605 = bit_and(r05EF, body.constant(int(31)));
                                       ir_expression *const r0606 = rshift(r05A4, r0605);
                                       body.emit(assign(r05F1, expr(ir_triop_csel, r0604, r0606, body.constant(0u)), 0x01));


                                    body.instructions = f05FB_parent_instructions;
                                    body.emit(f05FB);

                                    /* END IF */

                                    body.emit(assign(r05F2, body.constant(0u), 0x01));


                                 body.instructions = f05F7_parent_instructions;
                                 body.emit(f05F7);

                                 /* END IF */

                                 ir_expression *const r0607 = nequal(r05EE, body.constant(0u));
                                 ir_expression *const r0608 = expr(ir_unop_b2i, r0607);
                                 ir_expression *const r0609 = expr(ir_unop_i2u, r0608);
                                 body.emit(assign(r05F0, bit_or(r05F0, r0609), 0x01));


                              body.instructions = f05F5_parent_instructions;
                              body.emit(f05F5);

                              /* END IF */

                              body.emit(assign(r05D8, r05F2, 0x01));

                              body.emit(assign(r05D9, r05F1, 0x01));

                              body.emit(assign(r05DA, r05F0, 0x01));

                              body.emit(assign(r05D7, body.constant(int(0)), 0x01));

                              body.emit(assign(r05DD, less(r05F0, body.constant(0u)), 0x01));


                           body.instructions = f05EC_parent_instructions;
                           body.emit(f05EC);

                           /* END IF */


                        body.instructions = f05E1_parent_instructions;
                        body.emit(f05E1);

                        /* END IF */


                     body.instructions = f05DF_parent_instructions;
                     body.emit(f05DF);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f060A = new(mem_ctx) ir_if(operand(r05DB).val);
                     exec_list *const f060A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f060A->then_instructions;

                        /* IF CONDITION */
                        ir_if *f060B = new(mem_ctx) ir_if(operand(r05DD).val);
                        exec_list *const f060B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f060B->then_instructions;

                           ir_variable *const r060C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r060C, add(r05D9, body.constant(1u)), 0x01));

                           ir_expression *const r060D = less(r060C, r05D9);
                           ir_expression *const r060E = expr(ir_unop_b2i, r060D);
                           ir_expression *const r060F = expr(ir_unop_i2u, r060E);
                           body.emit(assign(r05D8, add(r05D8, r060F), 0x01));

                           ir_expression *const r0610 = equal(r05DA, body.constant(0u));
                           ir_expression *const r0611 = expr(ir_unop_b2i, r0610);
                           ir_expression *const r0612 = expr(ir_unop_i2u, r0611);
                           ir_expression *const r0613 = add(r05DA, r0612);
                           ir_expression *const r0614 = bit_and(r0613, body.constant(1u));
                           ir_expression *const r0615 = expr(ir_unop_bit_not, r0614);
                           body.emit(assign(r05D9, bit_and(r060C, r0615), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f060B->else_instructions;

                           ir_expression *const r0616 = bit_or(r05D8, r05D9);
                           ir_expression *const r0617 = equal(r0616, body.constant(0u));
                           body.emit(assign(r05D7, expr(ir_triop_csel, r0617, body.constant(int(0)), r05D7), 0x01));


                        body.instructions = f060B_parent_instructions;
                        body.emit(f060B);

                        /* END IF */

                        ir_variable *const r0618 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0618);
                        ir_expression *const r0619 = lshift(r01CF, body.constant(int(31)));
                        ir_expression *const r061A = expr(ir_unop_i2u, r05D7);
                        ir_expression *const r061B = lshift(r061A, body.constant(int(20)));
                        ir_expression *const r061C = add(r0619, r061B);
                        body.emit(assign(r0618, add(r061C, r05D8), 0x02));

                        body.emit(assign(r0618, r05D9, 0x01));

                        body.emit(assign(r05DC, r0618, 0x03));

                        body.emit(assign(r05DB, body.constant(false), 0x01));


                     body.instructions = f060A_parent_instructions;
                     body.emit(f060A);

                     /* END IF */

                     body.emit(assign(r01CE, r05DC, 0x03));

                     body.emit(assign(r01CD, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f059C->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r061E = less(r0368, r036A);
                     ir_if *f061D = new(mem_ctx) ir_if(operand(r061E).val);
                     exec_list *const f061D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f061D->then_instructions;

                        ir_variable *const r061F = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_expression *const r0620 = sub(r0369, r0367);
                        ir_expression *const r0621 = less(r036A, r0368);
                        ir_expression *const r0622 = expr(ir_unop_b2i, r0621);
                        ir_expression *const r0623 = expr(ir_unop_i2u, r0622);
                        body.emit(assign(r061F, sub(r0620, r0623), 0x01));

                        body.emit(assign(r036B, add(r0366, body.constant(int(-1))), 0x01));

                        ir_variable *const r0624 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0624, add(r036B, body.constant(int(-10))), 0x01));

                        ir_variable *const r0625 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        ir_variable *const r0626 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        ir_variable *const r0627 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0627);
                        ir_variable *const r0628 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0628);
                        ir_expression *const r0629 = equal(r061F, body.constant(0u));
                        ir_expression *const r062A = add(r0624, body.constant(int(-32)));
                        body.emit(assign(r0624, expr(ir_triop_csel, r0629, r062A, r0624), 0x01));

                        ir_variable *const r062B = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r062C = equal(r061F, body.constant(0u));
                        ir_expression *const r062D = sub(r036A, r0368);
                        body.emit(assign(r062B, expr(ir_triop_csel, r062C, body.constant(0u), r062D), 0x01));

                        body.emit(assign(r0626, r062B, 0x01));

                        ir_variable *const r062E = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r062F = equal(r061F, body.constant(0u));
                        body.emit(assign(r062E, expr(ir_triop_csel, r062F, r062B, r061F), 0x01));

                        body.emit(assign(r0625, r062E, 0x01));

                        ir_expression *const r0630 = equal(r062E, body.constant(0u));
                        ir_expression *const r0631 = expr(ir_unop_find_msb, r062E);
                        ir_expression *const r0632 = sub(body.constant(int(31)), r0631);
                        ir_expression *const r0633 = expr(ir_triop_csel, r0630, body.constant(int(32)), r0632);
                        body.emit(assign(r0628, add(r0633, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0635 = gequal(r0628, body.constant(int(0)));
                        ir_if *f0634 = new(mem_ctx) ir_if(operand(r0635).val);
                        exec_list *const f0634_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0634->then_instructions;

                           body.emit(assign(r0627, body.constant(0u), 0x01));

                           ir_expression *const r0636 = equal(r0628, body.constant(int(0)));
                           ir_expression *const r0637 = lshift(r062E, r0628);
                           ir_expression *const r0638 = neg(r0628);
                           ir_expression *const r0639 = bit_and(r0638, body.constant(int(31)));
                           ir_expression *const r063A = rshift(r062B, r0639);
                           ir_expression *const r063B = bit_or(r0637, r063A);
                           body.emit(assign(r0625, expr(ir_triop_csel, r0636, r062E, r063B), 0x01));

                           body.emit(assign(r0626, lshift(r062B, r0628), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0634->else_instructions;

                           ir_variable *const r063C = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r063C, body.constant(0u), 0x01));

                           ir_variable *const r063D = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r063D, neg(r0628), 0x01));

                           ir_variable *const r063E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r063E);
                           ir_variable *const r063F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r063F);
                           ir_variable *const r0640 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0640);
                           ir_variable *const r0641 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0642 = neg(r063D);
                           body.emit(assign(r0641, bit_and(r0642, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0644 = equal(r063D, body.constant(int(0)));
                           ir_if *f0643 = new(mem_ctx) ir_if(operand(r0644).val);
                           exec_list *const f0643_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0643->then_instructions;

                              body.emit(assign(r063E, r063C, 0x01));

                              body.emit(assign(r063F, r0626, 0x01));

                              body.emit(assign(r0640, r0625, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0643->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0646 = less(r063D, body.constant(int(32)));
                              ir_if *f0645 = new(mem_ctx) ir_if(operand(r0646).val);
                              exec_list *const f0645_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0645->then_instructions;

                                 body.emit(assign(r063E, lshift(r0626, r0641), 0x01));

                                 ir_expression *const r0647 = lshift(r0625, r0641);
                                 ir_expression *const r0648 = rshift(r0626, r063D);
                                 body.emit(assign(r063F, bit_or(r0647, r0648), 0x01));

                                 body.emit(assign(r0640, rshift(r0625, r063D), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0645->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r064A = equal(r063D, body.constant(int(32)));
                                 ir_if *f0649 = new(mem_ctx) ir_if(operand(r064A).val);
                                 exec_list *const f0649_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0649->then_instructions;

                                    body.emit(assign(r063E, r0626, 0x01));

                                    body.emit(assign(r063F, r0625, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0649->else_instructions;

                                    body.emit(assign(r063C, bit_or(body.constant(0u), r0626), 0x01));

                                    ir_expression *const r064B = less(r063D, body.constant(int(64)));
                                    ir_expression *const r064C = lshift(r0625, r0641);
                                    ir_expression *const r064D = equal(r063D, body.constant(int(64)));
                                    ir_expression *const r064E = nequal(r0625, body.constant(0u));
                                    ir_expression *const r064F = expr(ir_unop_b2i, r064E);
                                    ir_expression *const r0650 = expr(ir_unop_i2u, r064F);
                                    ir_expression *const r0651 = expr(ir_triop_csel, r064D, r0625, r0650);
                                    body.emit(assign(r063E, expr(ir_triop_csel, r064B, r064C, r0651), 0x01));

                                    ir_expression *const r0652 = less(r063D, body.constant(int(64)));
                                    ir_expression *const r0653 = bit_and(r063D, body.constant(int(31)));
                                    ir_expression *const r0654 = rshift(r0625, r0653);
                                    body.emit(assign(r063F, expr(ir_triop_csel, r0652, r0654, body.constant(0u)), 0x01));


                                 body.instructions = f0649_parent_instructions;
                                 body.emit(f0649);

                                 /* END IF */

                                 body.emit(assign(r0640, body.constant(0u), 0x01));


                              body.instructions = f0645_parent_instructions;
                              body.emit(f0645);

                              /* END IF */

                              ir_expression *const r0655 = nequal(r063C, body.constant(0u));
                              ir_expression *const r0656 = expr(ir_unop_b2i, r0655);
                              ir_expression *const r0657 = expr(ir_unop_i2u, r0656);
                              body.emit(assign(r063E, bit_or(r063E, r0657), 0x01));


                           body.instructions = f0643_parent_instructions;
                           body.emit(f0643);

                           /* END IF */

                           body.emit(assign(r0625, r0640, 0x01));

                           body.emit(assign(r0626, r063F, 0x01));

                           body.emit(assign(r0627, r063E, 0x01));


                        body.instructions = f0634_parent_instructions;
                        body.emit(f0634);

                        /* END IF */

                        body.emit(assign(r0624, sub(r0624, r0628), 0x01));

                        ir_variable *const r0658 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0658, r0624, 0x01));

                        ir_variable *const r0659 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r0659, r0625, 0x01));

                        ir_variable *const r065A = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r065A, r0626, 0x01));

                        ir_variable *const r065B = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r065B, r0627, 0x01));

                        ir_variable *const r065C = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r065C, body.constant(true), 0x01));

                        ir_variable *const r065D = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r065E = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r065E);
                        ir_expression *const r065F = expr(ir_unop_u2i, r0627);
                        body.emit(assign(r065E, less(r065F, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0661 = gequal(r0624, body.constant(int(2045)));
                        ir_if *f0660 = new(mem_ctx) ir_if(operand(r0661).val);
                        exec_list *const f0660_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0660->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0663 = less(body.constant(int(2045)), r0624);
                           ir_expression *const r0664 = equal(r0624, body.constant(int(2045)));
                           ir_expression *const r0665 = equal(body.constant(2097151u), r0625);
                           ir_expression *const r0666 = equal(body.constant(4294967295u), r0626);
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
                              ir_expression *const r066C = lshift(r01CF, body.constant(int(31)));
                              body.emit(assign(r066B, add(r066C, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r066B, body.constant(0u), 0x01));

                              body.emit(assign(r065D, r066B, 0x03));

                              body.emit(assign(r065C, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0662->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r066E = less(r0624, body.constant(int(0)));
                              ir_if *f066D = new(mem_ctx) ir_if(operand(r066E).val);
                              exec_list *const f066D_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f066D->then_instructions;

                                 ir_variable *const r066F = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r066F, r0627, 0x01));

                                 ir_variable *const r0670 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r0670, neg(r0624), 0x01));

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
                                 ir_expression *const r0677 = equal(r0670, body.constant(int(0)));
                                 ir_if *f0676 = new(mem_ctx) ir_if(operand(r0677).val);
                                 exec_list *const f0676_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0676->then_instructions;

                                    body.emit(assign(r0671, r0627, 0x01));

                                    body.emit(assign(r0672, r0626, 0x01));

                                    body.emit(assign(r0673, r0625, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0676->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0679 = less(r0670, body.constant(int(32)));
                                    ir_if *f0678 = new(mem_ctx) ir_if(operand(r0679).val);
                                    exec_list *const f0678_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0678->then_instructions;

                                       body.emit(assign(r0671, lshift(r0626, r0674), 0x01));

                                       ir_expression *const r067A = lshift(r0625, r0674);
                                       ir_expression *const r067B = rshift(r0626, r0670);
                                       body.emit(assign(r0672, bit_or(r067A, r067B), 0x01));

                                       body.emit(assign(r0673, rshift(r0625, r0670), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0678->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r067D = equal(r0670, body.constant(int(32)));
                                       ir_if *f067C = new(mem_ctx) ir_if(operand(r067D).val);
                                       exec_list *const f067C_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f067C->then_instructions;

                                          body.emit(assign(r0671, r0626, 0x01));

                                          body.emit(assign(r0672, r0625, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f067C->else_instructions;

                                          body.emit(assign(r066F, bit_or(r0627, r0626), 0x01));

                                          ir_expression *const r067E = less(r0670, body.constant(int(64)));
                                          ir_expression *const r067F = lshift(r0625, r0674);
                                          ir_expression *const r0680 = equal(r0670, body.constant(int(64)));
                                          ir_expression *const r0681 = nequal(r0625, body.constant(0u));
                                          ir_expression *const r0682 = expr(ir_unop_b2i, r0681);
                                          ir_expression *const r0683 = expr(ir_unop_i2u, r0682);
                                          ir_expression *const r0684 = expr(ir_triop_csel, r0680, r0625, r0683);
                                          body.emit(assign(r0671, expr(ir_triop_csel, r067E, r067F, r0684), 0x01));

                                          ir_expression *const r0685 = less(r0670, body.constant(int(64)));
                                          ir_expression *const r0686 = bit_and(r0670, body.constant(int(31)));
                                          ir_expression *const r0687 = rshift(r0625, r0686);
                                          body.emit(assign(r0672, expr(ir_triop_csel, r0685, r0687, body.constant(0u)), 0x01));


                                       body.instructions = f067C_parent_instructions;
                                       body.emit(f067C);

                                       /* END IF */

                                       body.emit(assign(r0673, body.constant(0u), 0x01));


                                    body.instructions = f0678_parent_instructions;
                                    body.emit(f0678);

                                    /* END IF */

                                    ir_expression *const r0688 = nequal(r066F, body.constant(0u));
                                    ir_expression *const r0689 = expr(ir_unop_b2i, r0688);
                                    ir_expression *const r068A = expr(ir_unop_i2u, r0689);
                                    body.emit(assign(r0671, bit_or(r0671, r068A), 0x01));


                                 body.instructions = f0676_parent_instructions;
                                 body.emit(f0676);

                                 /* END IF */

                                 body.emit(assign(r0659, r0673, 0x01));

                                 body.emit(assign(r065A, r0672, 0x01));

                                 body.emit(assign(r065B, r0671, 0x01));

                                 body.emit(assign(r0658, body.constant(int(0)), 0x01));

                                 body.emit(assign(r065E, less(r0671, body.constant(0u)), 0x01));


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
                        ir_if *f068B = new(mem_ctx) ir_if(operand(r065C).val);
                        exec_list *const f068B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f068B->then_instructions;

                           /* IF CONDITION */
                           ir_if *f068C = new(mem_ctx) ir_if(operand(r065E).val);
                           exec_list *const f068C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f068C->then_instructions;

                              ir_variable *const r068D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r068D, add(r065A, body.constant(1u)), 0x01));

                              ir_expression *const r068E = less(r068D, r065A);
                              ir_expression *const r068F = expr(ir_unop_b2i, r068E);
                              ir_expression *const r0690 = expr(ir_unop_i2u, r068F);
                              body.emit(assign(r0659, add(r0659, r0690), 0x01));

                              ir_expression *const r0691 = equal(r065B, body.constant(0u));
                              ir_expression *const r0692 = expr(ir_unop_b2i, r0691);
                              ir_expression *const r0693 = expr(ir_unop_i2u, r0692);
                              ir_expression *const r0694 = add(r065B, r0693);
                              ir_expression *const r0695 = bit_and(r0694, body.constant(1u));
                              ir_expression *const r0696 = expr(ir_unop_bit_not, r0695);
                              body.emit(assign(r065A, bit_and(r068D, r0696), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f068C->else_instructions;

                              ir_expression *const r0697 = bit_or(r0659, r065A);
                              ir_expression *const r0698 = equal(r0697, body.constant(0u));
                              body.emit(assign(r0658, expr(ir_triop_csel, r0698, body.constant(int(0)), r0658), 0x01));


                           body.instructions = f068C_parent_instructions;
                           body.emit(f068C);

                           /* END IF */

                           ir_variable *const r0699 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0699);
                           ir_expression *const r069A = lshift(r01CF, body.constant(int(31)));
                           ir_expression *const r069B = expr(ir_unop_i2u, r0658);
                           ir_expression *const r069C = lshift(r069B, body.constant(int(20)));
                           ir_expression *const r069D = add(r069A, r069C);
                           body.emit(assign(r0699, add(r069D, r0659), 0x02));

                           body.emit(assign(r0699, r065A, 0x01));

                           body.emit(assign(r065D, r0699, 0x03));

                           body.emit(assign(r065C, body.constant(false), 0x01));


                        body.instructions = f068B_parent_instructions;
                        body.emit(f068B);

                        /* END IF */

                        body.emit(assign(r01CE, r065D, 0x03));

                        body.emit(assign(r01CD, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f061D->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r069F = less(r036A, r0368);
                        ir_if *f069E = new(mem_ctx) ir_if(operand(r069F).val);
                        exec_list *const f069E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f069E->then_instructions;

                           ir_variable *const r06A0 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_expression *const r06A1 = sub(r0367, r0369);
                           ir_expression *const r06A2 = less(r0368, r036A);
                           ir_expression *const r06A3 = expr(ir_unop_b2i, r06A2);
                           ir_expression *const r06A4 = expr(ir_unop_i2u, r06A3);
                           body.emit(assign(r06A0, sub(r06A1, r06A4), 0x01));

                           body.emit(assign(r01CF, bit_xor(r01CF, body.constant(1u)), 0x01));

                           body.emit(assign(r036B, add(r0365, body.constant(int(-1))), 0x01));

                           ir_variable *const r06A5 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06A5, add(r036B, body.constant(int(-10))), 0x01));

                           ir_variable *const r06A6 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           ir_variable *const r06A7 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           ir_variable *const r06A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r06A8);
                           ir_variable *const r06A9 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06A9);
                           ir_expression *const r06AA = equal(r06A0, body.constant(0u));
                           ir_expression *const r06AB = add(r06A5, body.constant(int(-32)));
                           body.emit(assign(r06A5, expr(ir_triop_csel, r06AA, r06AB, r06A5), 0x01));

                           ir_variable *const r06AC = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06AD = equal(r06A0, body.constant(0u));
                           ir_expression *const r06AE = sub(r0368, r036A);
                           body.emit(assign(r06AC, expr(ir_triop_csel, r06AD, body.constant(0u), r06AE), 0x01));

                           body.emit(assign(r06A7, r06AC, 0x01));

                           ir_variable *const r06AF = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06B0 = equal(r06A0, body.constant(0u));
                           body.emit(assign(r06AF, expr(ir_triop_csel, r06B0, r06AC, r06A0), 0x01));

                           body.emit(assign(r06A6, r06AF, 0x01));

                           ir_expression *const r06B1 = equal(r06AF, body.constant(0u));
                           ir_expression *const r06B2 = expr(ir_unop_find_msb, r06AF);
                           ir_expression *const r06B3 = sub(body.constant(int(31)), r06B2);
                           ir_expression *const r06B4 = expr(ir_triop_csel, r06B1, body.constant(int(32)), r06B3);
                           body.emit(assign(r06A9, add(r06B4, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06B6 = gequal(r06A9, body.constant(int(0)));
                           ir_if *f06B5 = new(mem_ctx) ir_if(operand(r06B6).val);
                           exec_list *const f06B5_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06B5->then_instructions;

                              body.emit(assign(r06A8, body.constant(0u), 0x01));

                              ir_expression *const r06B7 = equal(r06A9, body.constant(int(0)));
                              ir_expression *const r06B8 = lshift(r06AF, r06A9);
                              ir_expression *const r06B9 = neg(r06A9);
                              ir_expression *const r06BA = bit_and(r06B9, body.constant(int(31)));
                              ir_expression *const r06BB = rshift(r06AC, r06BA);
                              ir_expression *const r06BC = bit_or(r06B8, r06BB);
                              body.emit(assign(r06A6, expr(ir_triop_csel, r06B7, r06AF, r06BC), 0x01));

                              body.emit(assign(r06A7, lshift(r06AC, r06A9), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06B5->else_instructions;

                              ir_variable *const r06BD = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r06BD, body.constant(0u), 0x01));

                              ir_variable *const r06BE = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r06BE, neg(r06A9), 0x01));

                              ir_variable *const r06BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r06BF);
                              ir_variable *const r06C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r06C0);
                              ir_variable *const r06C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r06C1);
                              ir_variable *const r06C2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r06C3 = neg(r06BE);
                              body.emit(assign(r06C2, bit_and(r06C3, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r06C5 = equal(r06BE, body.constant(int(0)));
                              ir_if *f06C4 = new(mem_ctx) ir_if(operand(r06C5).val);
                              exec_list *const f06C4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06C4->then_instructions;

                                 body.emit(assign(r06BF, r06BD, 0x01));

                                 body.emit(assign(r06C0, r06A7, 0x01));

                                 body.emit(assign(r06C1, r06A6, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06C4->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06C7 = less(r06BE, body.constant(int(32)));
                                 ir_if *f06C6 = new(mem_ctx) ir_if(operand(r06C7).val);
                                 exec_list *const f06C6_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06C6->then_instructions;

                                    body.emit(assign(r06BF, lshift(r06A7, r06C2), 0x01));

                                    ir_expression *const r06C8 = lshift(r06A6, r06C2);
                                    ir_expression *const r06C9 = rshift(r06A7, r06BE);
                                    body.emit(assign(r06C0, bit_or(r06C8, r06C9), 0x01));

                                    body.emit(assign(r06C1, rshift(r06A6, r06BE), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06C6->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06CB = equal(r06BE, body.constant(int(32)));
                                    ir_if *f06CA = new(mem_ctx) ir_if(operand(r06CB).val);
                                    exec_list *const f06CA_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06CA->then_instructions;

                                       body.emit(assign(r06BF, r06A7, 0x01));

                                       body.emit(assign(r06C0, r06A6, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06CA->else_instructions;

                                       body.emit(assign(r06BD, bit_or(body.constant(0u), r06A7), 0x01));

                                       ir_expression *const r06CC = less(r06BE, body.constant(int(64)));
                                       ir_expression *const r06CD = lshift(r06A6, r06C2);
                                       ir_expression *const r06CE = equal(r06BE, body.constant(int(64)));
                                       ir_expression *const r06CF = nequal(r06A6, body.constant(0u));
                                       ir_expression *const r06D0 = expr(ir_unop_b2i, r06CF);
                                       ir_expression *const r06D1 = expr(ir_unop_i2u, r06D0);
                                       ir_expression *const r06D2 = expr(ir_triop_csel, r06CE, r06A6, r06D1);
                                       body.emit(assign(r06BF, expr(ir_triop_csel, r06CC, r06CD, r06D2), 0x01));

                                       ir_expression *const r06D3 = less(r06BE, body.constant(int(64)));
                                       ir_expression *const r06D4 = bit_and(r06BE, body.constant(int(31)));
                                       ir_expression *const r06D5 = rshift(r06A6, r06D4);
                                       body.emit(assign(r06C0, expr(ir_triop_csel, r06D3, r06D5, body.constant(0u)), 0x01));


                                    body.instructions = f06CA_parent_instructions;
                                    body.emit(f06CA);

                                    /* END IF */

                                    body.emit(assign(r06C1, body.constant(0u), 0x01));


                                 body.instructions = f06C6_parent_instructions;
                                 body.emit(f06C6);

                                 /* END IF */

                                 ir_expression *const r06D6 = nequal(r06BD, body.constant(0u));
                                 ir_expression *const r06D7 = expr(ir_unop_b2i, r06D6);
                                 ir_expression *const r06D8 = expr(ir_unop_i2u, r06D7);
                                 body.emit(assign(r06BF, bit_or(r06BF, r06D8), 0x01));


                              body.instructions = f06C4_parent_instructions;
                              body.emit(f06C4);

                              /* END IF */

                              body.emit(assign(r06A6, r06C1, 0x01));

                              body.emit(assign(r06A7, r06C0, 0x01));

                              body.emit(assign(r06A8, r06BF, 0x01));


                           body.instructions = f06B5_parent_instructions;
                           body.emit(f06B5);

                           /* END IF */

                           body.emit(assign(r06A5, sub(r06A5, r06A9), 0x01));

                           ir_variable *const r06D9 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06D9, r06A5, 0x01));

                           ir_variable *const r06DA = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r06DA, r06A6, 0x01));

                           ir_variable *const r06DB = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r06DB, r06A7, 0x01));

                           ir_variable *const r06DC = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r06DC, r06A8, 0x01));

                           ir_variable *const r06DD = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r06DD, body.constant(true), 0x01));

                           ir_variable *const r06DE = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r06DF = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r06DF);
                           ir_expression *const r06E0 = expr(ir_unop_u2i, r06A8);
                           body.emit(assign(r06DF, less(r06E0, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06E2 = gequal(r06A5, body.constant(int(2045)));
                           ir_if *f06E1 = new(mem_ctx) ir_if(operand(r06E2).val);
                           exec_list *const f06E1_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06E1->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06E4 = less(body.constant(int(2045)), r06A5);
                              ir_expression *const r06E5 = equal(r06A5, body.constant(int(2045)));
                              ir_expression *const r06E6 = equal(body.constant(2097151u), r06A6);
                              ir_expression *const r06E7 = equal(body.constant(4294967295u), r06A7);
                              ir_expression *const r06E8 = logic_and(r06E6, r06E7);
                              ir_expression *const r06E9 = logic_and(r06E5, r06E8);
                              ir_expression *const r06EA = logic_and(r06E9, r06DF);
                              ir_expression *const r06EB = logic_or(r06E4, r06EA);
                              ir_if *f06E3 = new(mem_ctx) ir_if(operand(r06EB).val);
                              exec_list *const f06E3_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06E3->then_instructions;

                                 ir_variable *const r06EC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r06EC);
                                 ir_expression *const r06ED = lshift(r01CF, body.constant(int(31)));
                                 body.emit(assign(r06EC, add(r06ED, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r06EC, body.constant(0u), 0x01));

                                 body.emit(assign(r06DE, r06EC, 0x03));

                                 body.emit(assign(r06DD, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06E3->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06EF = less(r06A5, body.constant(int(0)));
                                 ir_if *f06EE = new(mem_ctx) ir_if(operand(r06EF).val);
                                 exec_list *const f06EE_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06EE->then_instructions;

                                    ir_variable *const r06F0 = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r06F0, r06A8, 0x01));

                                    ir_variable *const r06F1 = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r06F1, neg(r06A5), 0x01));

                                    ir_variable *const r06F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r06F2);
                                    ir_variable *const r06F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r06F3);
                                    ir_variable *const r06F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r06F4);
                                    ir_variable *const r06F5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r06F6 = neg(r06F1);
                                    body.emit(assign(r06F5, bit_and(r06F6, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r06F8 = equal(r06F1, body.constant(int(0)));
                                    ir_if *f06F7 = new(mem_ctx) ir_if(operand(r06F8).val);
                                    exec_list *const f06F7_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06F7->then_instructions;

                                       body.emit(assign(r06F2, r06A8, 0x01));

                                       body.emit(assign(r06F3, r06A7, 0x01));

                                       body.emit(assign(r06F4, r06A6, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06F7->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r06FA = less(r06F1, body.constant(int(32)));
                                       ir_if *f06F9 = new(mem_ctx) ir_if(operand(r06FA).val);
                                       exec_list *const f06F9_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06F9->then_instructions;

                                          body.emit(assign(r06F2, lshift(r06A7, r06F5), 0x01));

                                          ir_expression *const r06FB = lshift(r06A6, r06F5);
                                          ir_expression *const r06FC = rshift(r06A7, r06F1);
                                          body.emit(assign(r06F3, bit_or(r06FB, r06FC), 0x01));

                                          body.emit(assign(r06F4, rshift(r06A6, r06F1), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06F9->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r06FE = equal(r06F1, body.constant(int(32)));
                                          ir_if *f06FD = new(mem_ctx) ir_if(operand(r06FE).val);
                                          exec_list *const f06FD_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f06FD->then_instructions;

                                             body.emit(assign(r06F2, r06A7, 0x01));

                                             body.emit(assign(r06F3, r06A6, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f06FD->else_instructions;

                                             body.emit(assign(r06F0, bit_or(r06A8, r06A7), 0x01));

                                             ir_expression *const r06FF = less(r06F1, body.constant(int(64)));
                                             ir_expression *const r0700 = lshift(r06A6, r06F5);
                                             ir_expression *const r0701 = equal(r06F1, body.constant(int(64)));
                                             ir_expression *const r0702 = nequal(r06A6, body.constant(0u));
                                             ir_expression *const r0703 = expr(ir_unop_b2i, r0702);
                                             ir_expression *const r0704 = expr(ir_unop_i2u, r0703);
                                             ir_expression *const r0705 = expr(ir_triop_csel, r0701, r06A6, r0704);
                                             body.emit(assign(r06F2, expr(ir_triop_csel, r06FF, r0700, r0705), 0x01));

                                             ir_expression *const r0706 = less(r06F1, body.constant(int(64)));
                                             ir_expression *const r0707 = bit_and(r06F1, body.constant(int(31)));
                                             ir_expression *const r0708 = rshift(r06A6, r0707);
                                             body.emit(assign(r06F3, expr(ir_triop_csel, r0706, r0708, body.constant(0u)), 0x01));


                                          body.instructions = f06FD_parent_instructions;
                                          body.emit(f06FD);

                                          /* END IF */

                                          body.emit(assign(r06F4, body.constant(0u), 0x01));


                                       body.instructions = f06F9_parent_instructions;
                                       body.emit(f06F9);

                                       /* END IF */

                                       ir_expression *const r0709 = nequal(r06F0, body.constant(0u));
                                       ir_expression *const r070A = expr(ir_unop_b2i, r0709);
                                       ir_expression *const r070B = expr(ir_unop_i2u, r070A);
                                       body.emit(assign(r06F2, bit_or(r06F2, r070B), 0x01));


                                    body.instructions = f06F7_parent_instructions;
                                    body.emit(f06F7);

                                    /* END IF */

                                    body.emit(assign(r06DA, r06F4, 0x01));

                                    body.emit(assign(r06DB, r06F3, 0x01));

                                    body.emit(assign(r06DC, r06F2, 0x01));

                                    body.emit(assign(r06D9, body.constant(int(0)), 0x01));

                                    body.emit(assign(r06DF, less(r06F2, body.constant(0u)), 0x01));


                                 body.instructions = f06EE_parent_instructions;
                                 body.emit(f06EE);

                                 /* END IF */


                              body.instructions = f06E3_parent_instructions;
                              body.emit(f06E3);

                              /* END IF */


                           body.instructions = f06E1_parent_instructions;
                           body.emit(f06E1);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f070C = new(mem_ctx) ir_if(operand(r06DD).val);
                           exec_list *const f070C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f070C->then_instructions;

                              /* IF CONDITION */
                              ir_if *f070D = new(mem_ctx) ir_if(operand(r06DF).val);
                              exec_list *const f070D_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f070D->then_instructions;

                                 ir_variable *const r070E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r070E, add(r06DB, body.constant(1u)), 0x01));

                                 ir_expression *const r070F = less(r070E, r06DB);
                                 ir_expression *const r0710 = expr(ir_unop_b2i, r070F);
                                 ir_expression *const r0711 = expr(ir_unop_i2u, r0710);
                                 body.emit(assign(r06DA, add(r06DA, r0711), 0x01));

                                 ir_expression *const r0712 = equal(r06DC, body.constant(0u));
                                 ir_expression *const r0713 = expr(ir_unop_b2i, r0712);
                                 ir_expression *const r0714 = expr(ir_unop_i2u, r0713);
                                 ir_expression *const r0715 = add(r06DC, r0714);
                                 ir_expression *const r0716 = bit_and(r0715, body.constant(1u));
                                 ir_expression *const r0717 = expr(ir_unop_bit_not, r0716);
                                 body.emit(assign(r06DB, bit_and(r070E, r0717), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f070D->else_instructions;

                                 ir_expression *const r0718 = bit_or(r06DA, r06DB);
                                 ir_expression *const r0719 = equal(r0718, body.constant(0u));
                                 body.emit(assign(r06D9, expr(ir_triop_csel, r0719, body.constant(int(0)), r06D9), 0x01));


                              body.instructions = f070D_parent_instructions;
                              body.emit(f070D);

                              /* END IF */

                              ir_variable *const r071A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r071A);
                              ir_expression *const r071B = lshift(r01CF, body.constant(int(31)));
                              ir_expression *const r071C = expr(ir_unop_i2u, r06D9);
                              ir_expression *const r071D = lshift(r071C, body.constant(int(20)));
                              ir_expression *const r071E = add(r071B, r071D);
                              body.emit(assign(r071A, add(r071E, r06DA), 0x02));

                              body.emit(assign(r071A, r06DB, 0x01));

                              body.emit(assign(r06DE, r071A, 0x03));

                              body.emit(assign(r06DD, body.constant(false), 0x01));


                           body.instructions = f070C_parent_instructions;
                           body.emit(f070C);

                           /* END IF */

                           body.emit(assign(r01CE, r06DE, 0x03));

                           body.emit(assign(r01CD, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f069E->else_instructions;

                           ir_variable *const r071F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r071F);
                           body.emit(assign(r071F, body.constant(0u), 0x02));

                           body.emit(assign(r071F, body.constant(0u), 0x01));

                           body.emit(assign(r01CE, r071F, 0x03));

                           body.emit(assign(r01CD, body.constant(false), 0x01));


                        body.instructions = f069E_parent_instructions;
                        body.emit(f069E);

                        /* END IF */


                     body.instructions = f061D_parent_instructions;
                     body.emit(f061D);

                     /* END IF */


                  body.instructions = f059C_parent_instructions;
                  body.emit(f059C);

                  /* END IF */


               body.instructions = f051B_parent_instructions;
               body.emit(f051B);

               /* END IF */


            body.instructions = f04FE_parent_instructions;
            body.emit(f04FE);

            /* END IF */


         body.instructions = f043B_parent_instructions;
         body.emit(f043B);

         /* END IF */


      body.instructions = f037C_parent_instructions;
      body.emit(f037C);

      /* END IF */


   body.instructions = f01D2_parent_instructions;
   body.emit(f01D2);

   /* END IF */

   body.emit(ret(r01CE));

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

   ir_variable *const r0720 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0720);
   ir_variable *const r0721 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0721);
   ir_variable *const r0722 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0722);
   ir_variable *const r0723 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0723);
   ir_variable *const r0724 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0724);
   ir_variable *const r0725 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0725);
   ir_variable *const r0726 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0726);
   ir_variable *const r0727 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0727, bit_and(r0720, body.constant(65535u)), 0x01));

   ir_variable *const r0728 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0728, rshift(r0720, body.constant(int(16))), 0x01));

   ir_variable *const r0729 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0729, bit_and(r0721, body.constant(65535u)), 0x01));

   ir_variable *const r072A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r072A, rshift(r0721, body.constant(int(16))), 0x01));

   ir_variable *const r072B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r072B, mul(r0728, r0729), 0x01));

   ir_expression *const r072C = mul(r0727, r072A);
   body.emit(assign(r0725, add(r072C, r072B), 0x01));

   ir_expression *const r072D = mul(r0728, r072A);
   ir_expression *const r072E = less(r0725, r072B);
   ir_expression *const r072F = expr(ir_unop_b2i, r072E);
   ir_expression *const r0730 = expr(ir_unop_i2u, r072F);
   ir_expression *const r0731 = lshift(r0730, body.constant(int(16)));
   ir_expression *const r0732 = rshift(r0725, body.constant(int(16)));
   ir_expression *const r0733 = add(r0731, r0732);
   body.emit(assign(r0724, add(r072D, r0733), 0x01));

   body.emit(assign(r0725, lshift(r0725, body.constant(int(16))), 0x01));

   ir_expression *const r0734 = mul(r0727, r0729);
   body.emit(assign(r0726, add(r0734, r0725), 0x01));

   ir_expression *const r0735 = less(r0726, r0725);
   ir_expression *const r0736 = expr(ir_unop_b2i, r0735);
   ir_expression *const r0737 = expr(ir_unop_i2u, r0736);
   body.emit(assign(r0724, add(r0724, r0737), 0x01));

   body.emit(assign(r0723, r0726, 0x01));

   body.emit(assign(r0722, r0724, 0x01));

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

   ir_variable *const r0738 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0738);
   ir_variable *const r0739 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0739);
   ir_variable *const r073A = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r073A);
   ir_variable *const r073B = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r073B);
   ir_variable *const r073C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r073C);
   ir_variable *const r073D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r073D);
   ir_variable *const r073E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r073E);
   ir_variable *const r073F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r073F);
   ir_variable *const r0740 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0740);
   ir_variable *const r0741 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0741);
   ir_variable *const r0742 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0742);
   ir_variable *const r0743 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0743, bit_and(r0739, body.constant(65535u)), 0x01));

   ir_variable *const r0744 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0744, rshift(r0739, body.constant(int(16))), 0x01));

   ir_variable *const r0745 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0745, bit_and(r073B, body.constant(65535u)), 0x01));

   ir_variable *const r0746 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0746, rshift(r073B, body.constant(int(16))), 0x01));

   ir_variable *const r0747 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0747, mul(r0744, r0745), 0x01));

   ir_expression *const r0748 = mul(r0743, r0746);
   body.emit(assign(r0741, add(r0748, r0747), 0x01));

   ir_expression *const r0749 = mul(r0744, r0746);
   ir_expression *const r074A = less(r0741, r0747);
   ir_expression *const r074B = expr(ir_unop_b2i, r074A);
   ir_expression *const r074C = expr(ir_unop_i2u, r074B);
   ir_expression *const r074D = lshift(r074C, body.constant(int(16)));
   ir_expression *const r074E = rshift(r0741, body.constant(int(16)));
   ir_expression *const r074F = add(r074D, r074E);
   body.emit(assign(r0740, add(r0749, r074F), 0x01));

   body.emit(assign(r0741, lshift(r0741, body.constant(int(16))), 0x01));

   ir_expression *const r0750 = mul(r0743, r0745);
   body.emit(assign(r0742, add(r0750, r0741), 0x01));

   ir_expression *const r0751 = less(r0742, r0741);
   ir_expression *const r0752 = expr(ir_unop_b2i, r0751);
   ir_expression *const r0753 = expr(ir_unop_i2u, r0752);
   body.emit(assign(r0740, add(r0740, r0753), 0x01));

   ir_variable *const r0754 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0754);
   ir_variable *const r0755 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0755);
   ir_variable *const r0756 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0756);
   ir_variable *const r0757 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0757, bit_and(r0739, body.constant(65535u)), 0x01));

   ir_variable *const r0758 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0758, rshift(r0739, body.constant(int(16))), 0x01));

   ir_variable *const r0759 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0759, bit_and(r073A, body.constant(65535u)), 0x01));

   ir_variable *const r075A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r075A, rshift(r073A, body.constant(int(16))), 0x01));

   ir_variable *const r075B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r075B, mul(r0758, r0759), 0x01));

   ir_expression *const r075C = mul(r0757, r075A);
   body.emit(assign(r0755, add(r075C, r075B), 0x01));

   ir_expression *const r075D = mul(r0758, r075A);
   ir_expression *const r075E = less(r0755, r075B);
   ir_expression *const r075F = expr(ir_unop_b2i, r075E);
   ir_expression *const r0760 = expr(ir_unop_i2u, r075F);
   ir_expression *const r0761 = lshift(r0760, body.constant(int(16)));
   ir_expression *const r0762 = rshift(r0755, body.constant(int(16)));
   ir_expression *const r0763 = add(r0761, r0762);
   body.emit(assign(r0754, add(r075D, r0763), 0x01));

   body.emit(assign(r0755, lshift(r0755, body.constant(int(16))), 0x01));

   ir_expression *const r0764 = mul(r0757, r0759);
   body.emit(assign(r0756, add(r0764, r0755), 0x01));

   ir_expression *const r0765 = less(r0756, r0755);
   ir_expression *const r0766 = expr(ir_unop_b2i, r0765);
   ir_expression *const r0767 = expr(ir_unop_i2u, r0766);
   body.emit(assign(r0754, add(r0754, r0767), 0x01));

   ir_variable *const r0768 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0768, add(r0756, r0740), 0x01));

   ir_variable *const r0769 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0769);
   ir_variable *const r076A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r076A);
   ir_variable *const r076B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r076B);
   ir_variable *const r076C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076C, bit_and(r0738, body.constant(65535u)), 0x01));

   ir_variable *const r076D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076D, rshift(r0738, body.constant(int(16))), 0x01));

   ir_variable *const r076E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076E, bit_and(r073A, body.constant(65535u)), 0x01));

   ir_variable *const r076F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076F, rshift(r073A, body.constant(int(16))), 0x01));

   ir_variable *const r0770 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0770, mul(r076D, r076E), 0x01));

   ir_expression *const r0771 = mul(r076C, r076F);
   body.emit(assign(r076A, add(r0771, r0770), 0x01));

   ir_expression *const r0772 = mul(r076D, r076F);
   ir_expression *const r0773 = less(r076A, r0770);
   ir_expression *const r0774 = expr(ir_unop_b2i, r0773);
   ir_expression *const r0775 = expr(ir_unop_i2u, r0774);
   ir_expression *const r0776 = lshift(r0775, body.constant(int(16)));
   ir_expression *const r0777 = rshift(r076A, body.constant(int(16)));
   ir_expression *const r0778 = add(r0776, r0777);
   body.emit(assign(r0769, add(r0772, r0778), 0x01));

   body.emit(assign(r076A, lshift(r076A, body.constant(int(16))), 0x01));

   ir_expression *const r0779 = mul(r076C, r076E);
   body.emit(assign(r076B, add(r0779, r076A), 0x01));

   ir_expression *const r077A = less(r076B, r076A);
   ir_expression *const r077B = expr(ir_unop_b2i, r077A);
   ir_expression *const r077C = expr(ir_unop_i2u, r077B);
   body.emit(assign(r0769, add(r0769, r077C), 0x01));

   ir_variable *const r077D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r077E = less(r0768, r0756);
   ir_expression *const r077F = expr(ir_unop_b2i, r077E);
   ir_expression *const r0780 = expr(ir_unop_i2u, r077F);
   ir_expression *const r0781 = add(r0754, r0780);
   body.emit(assign(r077D, add(r076B, r0781), 0x01));

   ir_variable *const r0782 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0782);
   ir_variable *const r0783 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0783);
   ir_variable *const r0784 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0784);
   ir_variable *const r0785 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0785, bit_and(r0738, body.constant(65535u)), 0x01));

   ir_variable *const r0786 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0786, rshift(r0738, body.constant(int(16))), 0x01));

   ir_variable *const r0787 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0787, bit_and(r073B, body.constant(65535u)), 0x01));

   ir_variable *const r0788 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0788, rshift(r073B, body.constant(int(16))), 0x01));

   ir_variable *const r0789 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0789, mul(r0786, r0787), 0x01));

   ir_expression *const r078A = mul(r0785, r0788);
   body.emit(assign(r0783, add(r078A, r0789), 0x01));

   ir_expression *const r078B = mul(r0786, r0788);
   ir_expression *const r078C = less(r0783, r0789);
   ir_expression *const r078D = expr(ir_unop_b2i, r078C);
   ir_expression *const r078E = expr(ir_unop_i2u, r078D);
   ir_expression *const r078F = lshift(r078E, body.constant(int(16)));
   ir_expression *const r0790 = rshift(r0783, body.constant(int(16)));
   ir_expression *const r0791 = add(r078F, r0790);
   body.emit(assign(r0782, add(r078B, r0791), 0x01));

   body.emit(assign(r0783, lshift(r0783, body.constant(int(16))), 0x01));

   ir_expression *const r0792 = mul(r0785, r0787);
   body.emit(assign(r0784, add(r0792, r0783), 0x01));

   ir_expression *const r0793 = less(r0784, r0783);
   ir_expression *const r0794 = expr(ir_unop_b2i, r0793);
   ir_expression *const r0795 = expr(ir_unop_i2u, r0794);
   body.emit(assign(r0782, add(r0782, r0795), 0x01));

   ir_variable *const r0796 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0796, add(r0784, r0768), 0x01));

   ir_variable *const r0797 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0798 = less(r0796, r0784);
   ir_expression *const r0799 = expr(ir_unop_b2i, r0798);
   ir_expression *const r079A = expr(ir_unop_i2u, r0799);
   ir_expression *const r079B = add(r0782, r079A);
   body.emit(assign(r0797, add(r077D, r079B), 0x01));

   body.emit(assign(r073F, r0742, 0x01));

   body.emit(assign(r073E, r0796, 0x01));

   body.emit(assign(r073D, r0797, 0x01));

   ir_expression *const r079C = less(r077D, r076B);
   ir_expression *const r079D = expr(ir_unop_b2i, r079C);
   ir_expression *const r079E = expr(ir_unop_i2u, r079D);
   ir_expression *const r079F = add(r0769, r079E);
   ir_expression *const r07A0 = less(r0797, r077D);
   ir_expression *const r07A1 = expr(ir_unop_b2i, r07A0);
   ir_expression *const r07A2 = expr(ir_unop_i2u, r07A1);
   body.emit(assign(r073C, add(r079F, r07A2), 0x01));

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

   ir_variable *const r07A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r07A3);
   ir_variable *const r07A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r07A4);
   ir_variable *const r07A5 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r07A5);
   ir_variable *const r07A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07A6);
   ir_variable *const r07A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07A7);
   ir_variable *const r07A8 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r07A8);
   /* IF CONDITION */
   ir_expression *const r07AA = equal(r07A3, body.constant(0u));
   ir_if *f07A9 = new(mem_ctx) ir_if(operand(r07AA).val);
   exec_list *const f07A9_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07A9->then_instructions;

      ir_expression *const r07AB = equal(r07A4, body.constant(0u));
      ir_expression *const r07AC = expr(ir_unop_find_msb, r07A4);
      ir_expression *const r07AD = sub(body.constant(int(31)), r07AC);
      ir_expression *const r07AE = expr(ir_triop_csel, r07AB, body.constant(int(32)), r07AD);
      body.emit(assign(r07A8, add(r07AE, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r07B0 = less(r07A8, body.constant(int(0)));
      ir_if *f07AF = new(mem_ctx) ir_if(operand(r07B0).val);
      exec_list *const f07AF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07AF->then_instructions;

         ir_expression *const r07B1 = neg(r07A8);
         body.emit(assign(r07A6, rshift(r07A4, r07B1), 0x01));

         ir_expression *const r07B2 = bit_and(r07A8, body.constant(int(31)));
         body.emit(assign(r07A7, lshift(r07A4, r07B2), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07AF->else_instructions;

         body.emit(assign(r07A6, lshift(r07A4, r07A8), 0x01));

         body.emit(assign(r07A7, body.constant(0u), 0x01));


      body.instructions = f07AF_parent_instructions;
      body.emit(f07AF);

      /* END IF */

      body.emit(assign(r07A5, sub(body.constant(int(-31)), r07A8), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07A9->else_instructions;

      ir_expression *const r07B3 = equal(r07A3, body.constant(0u));
      ir_expression *const r07B4 = expr(ir_unop_find_msb, r07A3);
      ir_expression *const r07B5 = sub(body.constant(int(31)), r07B4);
      ir_expression *const r07B6 = expr(ir_triop_csel, r07B3, body.constant(int(32)), r07B5);
      body.emit(assign(r07A8, add(r07B6, body.constant(int(-11))), 0x01));

      ir_expression *const r07B7 = equal(r07A8, body.constant(int(0)));
      ir_expression *const r07B8 = lshift(r07A3, r07A8);
      ir_expression *const r07B9 = neg(r07A8);
      ir_expression *const r07BA = bit_and(r07B9, body.constant(int(31)));
      ir_expression *const r07BB = rshift(r07A4, r07BA);
      ir_expression *const r07BC = bit_or(r07B8, r07BB);
      body.emit(assign(r07A6, expr(ir_triop_csel, r07B7, r07A3, r07BC), 0x01));

      body.emit(assign(r07A7, lshift(r07A4, r07A8), 0x01));

      body.emit(assign(r07A5, sub(body.constant(int(1)), r07A8), 0x01));


   body.instructions = f07A9_parent_instructions;
   body.emit(f07A9);

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

   ir_variable *const r07BD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r07BD);
   ir_variable *const r07BE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r07BE);
   ir_variable *const r07BF = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r07BF, body.constant(true), 0x01));

   ir_variable *const r07C0 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r07C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r07C1);
   ir_variable *const r07C2 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r07C2);
   ir_variable *const r07C3 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r07C3);
   ir_variable *const r07C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r07C4);
   ir_variable *const r07C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r07C5);
   ir_variable *const r07C6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r07C6);
   ir_variable *const r07C7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r07C7);
   ir_variable *const r07C8 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r07C8);
   ir_variable *const r07C9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r07C9);
   ir_variable *const r07CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r07CA);
   ir_variable *const r07CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r07CB);
   body.emit(assign(r07CB, body.constant(0u), 0x01));

   body.emit(assign(r07CA, body.constant(0u), 0x01));

   body.emit(assign(r07C9, body.constant(0u), 0x01));

   ir_variable *const r07CC = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r07CC, swizzle_x(r07BD), 0x01));

   body.emit(assign(r07C7, r07CC, 0x01));

   ir_variable *const r07CD = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r07CD, bit_and(swizzle_y(r07BD), body.constant(1048575u)), 0x01));

   body.emit(assign(r07C6, r07CD, 0x01));

   ir_variable *const r07CE = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r07CE, swizzle_x(r07BE), 0x01));

   body.emit(assign(r07C5, r07CE, 0x01));

   ir_variable *const r07CF = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r07CF, bit_and(swizzle_y(r07BE), body.constant(1048575u)), 0x01));

   body.emit(assign(r07C4, r07CF, 0x01));

   ir_variable *const r07D0 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r07D1 = rshift(swizzle_y(r07BD), body.constant(int(20)));
   ir_expression *const r07D2 = bit_and(r07D1, body.constant(2047u));
   body.emit(assign(r07D0, expr(ir_unop_u2i, r07D2), 0x01));

   body.emit(assign(r07C3, r07D0, 0x01));

   ir_variable *const r07D3 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r07D4 = rshift(swizzle_y(r07BE), body.constant(int(20)));
   ir_expression *const r07D5 = bit_and(r07D4, body.constant(2047u));
   body.emit(assign(r07D3, expr(ir_unop_u2i, r07D5), 0x01));

   body.emit(assign(r07C2, r07D3, 0x01));

   ir_expression *const r07D6 = rshift(swizzle_y(r07BD), body.constant(int(31)));
   ir_expression *const r07D7 = rshift(swizzle_y(r07BE), body.constant(int(31)));
   body.emit(assign(r07C1, bit_xor(r07D6, r07D7), 0x01));

   /* IF CONDITION */
   ir_expression *const r07D9 = equal(r07D0, body.constant(int(2047)));
   ir_if *f07D8 = new(mem_ctx) ir_if(operand(r07D9).val);
   exec_list *const f07D8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07D8->then_instructions;

      /* IF CONDITION */
      ir_expression *const r07DB = bit_or(r07CD, swizzle_x(r07BD));
      ir_expression *const r07DC = nequal(r07DB, body.constant(0u));
      ir_expression *const r07DD = equal(r07D3, body.constant(int(2047)));
      ir_expression *const r07DE = bit_or(r07CF, swizzle_x(r07BE));
      ir_expression *const r07DF = nequal(r07DE, body.constant(0u));
      ir_expression *const r07E0 = logic_and(r07DD, r07DF);
      ir_expression *const r07E1 = logic_or(r07DC, r07E0);
      ir_if *f07DA = new(mem_ctx) ir_if(operand(r07E1).val);
      exec_list *const f07DA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07DA->then_instructions;

         ir_variable *const r07E2 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r07E2, swizzle_x(r07BD), 0x01));

         ir_variable *const r07E3 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r07E3, swizzle_x(r07BE), 0x01));

         body.emit(assign(r07E2, bit_or(swizzle_y(r07BD), body.constant(524288u)), 0x02));

         body.emit(assign(r07E3, bit_or(swizzle_y(r07BE), body.constant(524288u)), 0x02));

         ir_expression *const r07E4 = lshift(swizzle_y(r07BD), body.constant(int(1)));
         ir_expression *const r07E5 = gequal(r07E4, body.constant(4292870144u));
         ir_expression *const r07E6 = nequal(swizzle_x(r07BD), body.constant(0u));
         ir_expression *const r07E7 = bit_and(swizzle_y(r07BD), body.constant(1048575u));
         ir_expression *const r07E8 = nequal(r07E7, body.constant(0u));
         ir_expression *const r07E9 = logic_or(r07E6, r07E8);
         ir_expression *const r07EA = logic_and(r07E5, r07E9);
         ir_swizzle *const r07EB = swizzle(r07EA, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r07EC = lshift(swizzle_y(r07BE), body.constant(int(1)));
         ir_expression *const r07ED = gequal(r07EC, body.constant(4292870144u));
         ir_expression *const r07EE = nequal(swizzle_x(r07BE), body.constant(0u));
         ir_expression *const r07EF = bit_and(swizzle_y(r07BE), body.constant(1048575u));
         ir_expression *const r07F0 = nequal(r07EF, body.constant(0u));
         ir_expression *const r07F1 = logic_or(r07EE, r07F0);
         ir_expression *const r07F2 = logic_and(r07ED, r07F1);
         ir_swizzle *const r07F3 = swizzle(r07F2, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r07F4 = expr(ir_triop_csel, r07F3, r07E3, r07E2);
         body.emit(assign(r07C0, expr(ir_triop_csel, r07EB, r07F4, r07E3), 0x03));

         body.emit(assign(r07BF, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07DA->else_instructions;

         /* IF CONDITION */
         ir_expression *const r07F6 = expr(ir_unop_i2u, r07D3);
         ir_expression *const r07F7 = bit_or(r07F6, r07CF);
         ir_expression *const r07F8 = bit_or(r07F7, swizzle_x(r07BE));
         ir_expression *const r07F9 = equal(r07F8, body.constant(0u));
         ir_if *f07F5 = new(mem_ctx) ir_if(operand(r07F9).val);
         exec_list *const f07F5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07F5->then_instructions;

            ir_constant_data r07FA_data;
            memset(&r07FA_data, 0, sizeof(ir_constant_data));
            r07FA_data.u[0] = 4294967295;
            r07FA_data.u[1] = 4294967295;
            ir_constant *const r07FA = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r07FA_data);
            body.emit(assign(r07C0, r07FA, 0x03));

            body.emit(assign(r07BF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f07F5->else_instructions;

            ir_variable *const r07FB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r07FB);
            ir_expression *const r07FC = lshift(r07C1, body.constant(int(31)));
            body.emit(assign(r07FB, add(r07FC, body.constant(2146435072u)), 0x02));

            body.emit(assign(r07FB, body.constant(0u), 0x01));

            body.emit(assign(r07C0, r07FB, 0x03));

            body.emit(assign(r07BF, body.constant(false), 0x01));


         body.instructions = f07F5_parent_instructions;
         body.emit(f07F5);

         /* END IF */


      body.instructions = f07DA_parent_instructions;
      body.emit(f07DA);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07D8->else_instructions;

      /* IF CONDITION */
      ir_expression *const r07FE = equal(r07D3, body.constant(int(2047)));
      ir_if *f07FD = new(mem_ctx) ir_if(operand(r07FE).val);
      exec_list *const f07FD_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07FD->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0800 = bit_or(r07CF, swizzle_x(r07BE));
         ir_expression *const r0801 = nequal(r0800, body.constant(0u));
         ir_if *f07FF = new(mem_ctx) ir_if(operand(r0801).val);
         exec_list *const f07FF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07FF->then_instructions;

            ir_variable *const r0802 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0802, swizzle_x(r07BD), 0x01));

            ir_variable *const r0803 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0803, swizzle_x(r07BE), 0x01));

            body.emit(assign(r0802, bit_or(swizzle_y(r07BD), body.constant(524288u)), 0x02));

            body.emit(assign(r0803, bit_or(swizzle_y(r07BE), body.constant(524288u)), 0x02));

            ir_expression *const r0804 = lshift(swizzle_y(r07BD), body.constant(int(1)));
            ir_expression *const r0805 = gequal(r0804, body.constant(4292870144u));
            ir_expression *const r0806 = nequal(swizzle_x(r07BD), body.constant(0u));
            ir_expression *const r0807 = bit_and(swizzle_y(r07BD), body.constant(1048575u));
            ir_expression *const r0808 = nequal(r0807, body.constant(0u));
            ir_expression *const r0809 = logic_or(r0806, r0808);
            ir_expression *const r080A = logic_and(r0805, r0809);
            ir_swizzle *const r080B = swizzle(r080A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r080C = lshift(swizzle_y(r07BE), body.constant(int(1)));
            ir_expression *const r080D = gequal(r080C, body.constant(4292870144u));
            ir_expression *const r080E = nequal(swizzle_x(r07BE), body.constant(0u));
            ir_expression *const r080F = bit_and(swizzle_y(r07BE), body.constant(1048575u));
            ir_expression *const r0810 = nequal(r080F, body.constant(0u));
            ir_expression *const r0811 = logic_or(r080E, r0810);
            ir_expression *const r0812 = logic_and(r080D, r0811);
            ir_swizzle *const r0813 = swizzle(r0812, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0814 = expr(ir_triop_csel, r0813, r0803, r0802);
            body.emit(assign(r07C0, expr(ir_triop_csel, r080B, r0814, r0803), 0x03));

            body.emit(assign(r07BF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f07FF->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0816 = expr(ir_unop_i2u, r07D0);
            ir_expression *const r0817 = bit_or(r0816, r07CD);
            ir_expression *const r0818 = bit_or(r0817, swizzle_x(r07BD));
            ir_expression *const r0819 = equal(r0818, body.constant(0u));
            ir_if *f0815 = new(mem_ctx) ir_if(operand(r0819).val);
            exec_list *const f0815_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0815->then_instructions;

               ir_constant_data r081A_data;
               memset(&r081A_data, 0, sizeof(ir_constant_data));
               r081A_data.u[0] = 4294967295;
               r081A_data.u[1] = 4294967295;
               ir_constant *const r081A = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r081A_data);
               body.emit(assign(r07C0, r081A, 0x03));

               body.emit(assign(r07BF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0815->else_instructions;

               ir_variable *const r081B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r081B);
               ir_expression *const r081C = lshift(r07C1, body.constant(int(31)));
               body.emit(assign(r081B, add(r081C, body.constant(2146435072u)), 0x02));

               body.emit(assign(r081B, body.constant(0u), 0x01));

               body.emit(assign(r07C0, r081B, 0x03));

               body.emit(assign(r07BF, body.constant(false), 0x01));


            body.instructions = f0815_parent_instructions;
            body.emit(f0815);

            /* END IF */


         body.instructions = f07FF_parent_instructions;
         body.emit(f07FF);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07FD->else_instructions;

         /* IF CONDITION */
         ir_expression *const r081E = equal(r07D0, body.constant(int(0)));
         ir_if *f081D = new(mem_ctx) ir_if(operand(r081E).val);
         exec_list *const f081D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f081D->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0820 = bit_or(r07CD, swizzle_x(r07BD));
            ir_expression *const r0821 = equal(r0820, body.constant(0u));
            ir_if *f081F = new(mem_ctx) ir_if(operand(r0821).val);
            exec_list *const f081F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f081F->then_instructions;

               ir_variable *const r0822 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0822);
               body.emit(assign(r0822, lshift(r07C1, body.constant(int(31))), 0x02));

               body.emit(assign(r0822, body.constant(0u), 0x01));

               body.emit(assign(r07C0, r0822, 0x03));

               body.emit(assign(r07BF, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f081F->else_instructions;

               ir_variable *const r0823 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r0823, r07D0, 0x01));

               ir_variable *const r0824 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r0824, r07CD, 0x01));

               ir_variable *const r0825 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r0825, r07CC, 0x01));

               ir_variable *const r0826 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0826);
               /* IF CONDITION */
               ir_expression *const r0828 = equal(r07CD, body.constant(0u));
               ir_if *f0827 = new(mem_ctx) ir_if(operand(r0828).val);
               exec_list *const f0827_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0827->then_instructions;

                  ir_expression *const r0829 = equal(swizzle_x(r07BD), body.constant(0u));
                  ir_expression *const r082A = expr(ir_unop_find_msb, swizzle_x(r07BD));
                  ir_expression *const r082B = sub(body.constant(int(31)), r082A);
                  ir_expression *const r082C = expr(ir_triop_csel, r0829, body.constant(int(32)), r082B);
                  body.emit(assign(r0826, add(r082C, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r082E = less(r0826, body.constant(int(0)));
                  ir_if *f082D = new(mem_ctx) ir_if(operand(r082E).val);
                  exec_list *const f082D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f082D->then_instructions;

                     ir_expression *const r082F = neg(r0826);
                     body.emit(assign(r0824, rshift(swizzle_x(r07BD), r082F), 0x01));

                     ir_expression *const r0830 = bit_and(r0826, body.constant(int(31)));
                     body.emit(assign(r0825, lshift(swizzle_x(r07BD), r0830), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f082D->else_instructions;

                     body.emit(assign(r0824, lshift(swizzle_x(r07BD), r0826), 0x01));

                     body.emit(assign(r0825, body.constant(0u), 0x01));


                  body.instructions = f082D_parent_instructions;
                  body.emit(f082D);

                  /* END IF */

                  body.emit(assign(r0823, sub(body.constant(int(-31)), r0826), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0827->else_instructions;

                  ir_expression *const r0831 = equal(r07CD, body.constant(0u));
                  ir_expression *const r0832 = expr(ir_unop_find_msb, r07CD);
                  ir_expression *const r0833 = sub(body.constant(int(31)), r0832);
                  ir_expression *const r0834 = expr(ir_triop_csel, r0831, body.constant(int(32)), r0833);
                  body.emit(assign(r0826, add(r0834, body.constant(int(-11))), 0x01));

                  ir_expression *const r0835 = equal(r0826, body.constant(int(0)));
                  ir_expression *const r0836 = lshift(r07CD, r0826);
                  ir_expression *const r0837 = neg(r0826);
                  ir_expression *const r0838 = bit_and(r0837, body.constant(int(31)));
                  ir_expression *const r0839 = rshift(swizzle_x(r07BD), r0838);
                  ir_expression *const r083A = bit_or(r0836, r0839);
                  body.emit(assign(r0824, expr(ir_triop_csel, r0835, r07CD, r083A), 0x01));

                  body.emit(assign(r0825, lshift(swizzle_x(r07BD), r0826), 0x01));

                  body.emit(assign(r0823, sub(body.constant(int(1)), r0826), 0x01));


               body.instructions = f0827_parent_instructions;
               body.emit(f0827);

               /* END IF */

               body.emit(assign(r07C3, r0823, 0x01));

               body.emit(assign(r07C6, r0824, 0x01));

               body.emit(assign(r07C7, r0825, 0x01));


            body.instructions = f081F_parent_instructions;
            body.emit(f081F);

            /* END IF */


         body.instructions = f081D_parent_instructions;
         body.emit(f081D);

         /* END IF */

         /* IF CONDITION */
         ir_if *f083B = new(mem_ctx) ir_if(operand(r07BF).val);
         exec_list *const f083B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f083B->then_instructions;

            /* IF CONDITION */
            ir_expression *const r083D = equal(r07D3, body.constant(int(0)));
            ir_if *f083C = new(mem_ctx) ir_if(operand(r083D).val);
            exec_list *const f083C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f083C->then_instructions;

               /* IF CONDITION */
               ir_expression *const r083F = bit_or(r07CF, swizzle_x(r07BE));
               ir_expression *const r0840 = equal(r083F, body.constant(0u));
               ir_if *f083E = new(mem_ctx) ir_if(operand(r0840).val);
               exec_list *const f083E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f083E->then_instructions;

                  ir_variable *const r0841 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0841);
                  body.emit(assign(r0841, lshift(r07C1, body.constant(int(31))), 0x02));

                  body.emit(assign(r0841, body.constant(0u), 0x01));

                  body.emit(assign(r07C0, r0841, 0x03));

                  body.emit(assign(r07BF, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f083E->else_instructions;

                  ir_variable *const r0842 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r0842, r07D3, 0x01));

                  ir_variable *const r0843 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r0843, r07CF, 0x01));

                  ir_variable *const r0844 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r0844, r07CE, 0x01));

                  ir_variable *const r0845 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0845);
                  /* IF CONDITION */
                  ir_expression *const r0847 = equal(r07CF, body.constant(0u));
                  ir_if *f0846 = new(mem_ctx) ir_if(operand(r0847).val);
                  exec_list *const f0846_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0846->then_instructions;

                     ir_expression *const r0848 = equal(swizzle_x(r07BE), body.constant(0u));
                     ir_expression *const r0849 = expr(ir_unop_find_msb, swizzle_x(r07BE));
                     ir_expression *const r084A = sub(body.constant(int(31)), r0849);
                     ir_expression *const r084B = expr(ir_triop_csel, r0848, body.constant(int(32)), r084A);
                     body.emit(assign(r0845, add(r084B, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r084D = less(r0845, body.constant(int(0)));
                     ir_if *f084C = new(mem_ctx) ir_if(operand(r084D).val);
                     exec_list *const f084C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f084C->then_instructions;

                        ir_expression *const r084E = neg(r0845);
                        body.emit(assign(r0843, rshift(swizzle_x(r07BE), r084E), 0x01));

                        ir_expression *const r084F = bit_and(r0845, body.constant(int(31)));
                        body.emit(assign(r0844, lshift(swizzle_x(r07BE), r084F), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f084C->else_instructions;

                        body.emit(assign(r0843, lshift(swizzle_x(r07BE), r0845), 0x01));

                        body.emit(assign(r0844, body.constant(0u), 0x01));


                     body.instructions = f084C_parent_instructions;
                     body.emit(f084C);

                     /* END IF */

                     body.emit(assign(r0842, sub(body.constant(int(-31)), r0845), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0846->else_instructions;

                     ir_expression *const r0850 = equal(r07CF, body.constant(0u));
                     ir_expression *const r0851 = expr(ir_unop_find_msb, r07CF);
                     ir_expression *const r0852 = sub(body.constant(int(31)), r0851);
                     ir_expression *const r0853 = expr(ir_triop_csel, r0850, body.constant(int(32)), r0852);
                     body.emit(assign(r0845, add(r0853, body.constant(int(-11))), 0x01));

                     ir_expression *const r0854 = equal(r0845, body.constant(int(0)));
                     ir_expression *const r0855 = lshift(r07CF, r0845);
                     ir_expression *const r0856 = neg(r0845);
                     ir_expression *const r0857 = bit_and(r0856, body.constant(int(31)));
                     ir_expression *const r0858 = rshift(swizzle_x(r07BE), r0857);
                     ir_expression *const r0859 = bit_or(r0855, r0858);
                     body.emit(assign(r0843, expr(ir_triop_csel, r0854, r07CF, r0859), 0x01));

                     body.emit(assign(r0844, lshift(swizzle_x(r07BE), r0845), 0x01));

                     body.emit(assign(r0842, sub(body.constant(int(1)), r0845), 0x01));


                  body.instructions = f0846_parent_instructions;
                  body.emit(f0846);

                  /* END IF */

                  body.emit(assign(r07C2, r0842, 0x01));

                  body.emit(assign(r07C4, r0843, 0x01));

                  body.emit(assign(r07C5, r0844, 0x01));


               body.instructions = f083E_parent_instructions;
               body.emit(f083E);

               /* END IF */


            body.instructions = f083C_parent_instructions;
            body.emit(f083C);

            /* END IF */

            /* IF CONDITION */
            ir_if *f085A = new(mem_ctx) ir_if(operand(r07BF).val);
            exec_list *const f085A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f085A->then_instructions;

               ir_expression *const r085B = add(r07C3, r07C2);
               body.emit(assign(r07C8, add(r085B, body.constant(int(-1024))), 0x01));

               body.emit(assign(r07C6, bit_or(r07C6, body.constant(1048576u)), 0x01));

               ir_variable *const r085C = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r085D = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r085D, lshift(r07C5, body.constant(int(12))), 0x01));

               ir_expression *const r085E = lshift(r07C4, body.constant(int(12)));
               ir_expression *const r085F = rshift(r07C5, body.constant(int(20)));
               body.emit(assign(r085C, bit_or(r085E, r085F), 0x01));

               body.emit(assign(r07C4, r085C, 0x01));

               body.emit(assign(r07C5, r085D, 0x01));

               ir_variable *const r0860 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0860);
               ir_variable *const r0861 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0861);
               ir_variable *const r0862 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0862);
               ir_variable *const r0863 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0863, bit_and(r07C7, body.constant(65535u)), 0x01));

               ir_variable *const r0864 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0864, rshift(r07C7, body.constant(int(16))), 0x01));

               ir_variable *const r0865 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0865, bit_and(r085D, body.constant(65535u)), 0x01));

               ir_variable *const r0866 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0866, rshift(r085D, body.constant(int(16))), 0x01));

               ir_variable *const r0867 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0867, mul(r0864, r0865), 0x01));

               ir_expression *const r0868 = mul(r0863, r0866);
               body.emit(assign(r0861, add(r0868, r0867), 0x01));

               ir_expression *const r0869 = mul(r0864, r0866);
               ir_expression *const r086A = less(r0861, r0867);
               ir_expression *const r086B = expr(ir_unop_b2i, r086A);
               ir_expression *const r086C = expr(ir_unop_i2u, r086B);
               ir_expression *const r086D = lshift(r086C, body.constant(int(16)));
               ir_expression *const r086E = rshift(r0861, body.constant(int(16)));
               ir_expression *const r086F = add(r086D, r086E);
               body.emit(assign(r0860, add(r0869, r086F), 0x01));

               body.emit(assign(r0861, lshift(r0861, body.constant(int(16))), 0x01));

               ir_expression *const r0870 = mul(r0863, r0865);
               body.emit(assign(r0862, add(r0870, r0861), 0x01));

               ir_expression *const r0871 = less(r0862, r0861);
               ir_expression *const r0872 = expr(ir_unop_b2i, r0871);
               ir_expression *const r0873 = expr(ir_unop_i2u, r0872);
               body.emit(assign(r0860, add(r0860, r0873), 0x01));

               ir_variable *const r0874 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0874);
               ir_variable *const r0875 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0875);
               ir_variable *const r0876 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0876);
               ir_variable *const r0877 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0877, bit_and(r07C7, body.constant(65535u)), 0x01));

               ir_variable *const r0878 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0878, rshift(r07C7, body.constant(int(16))), 0x01));

               ir_variable *const r0879 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0879, bit_and(r085C, body.constant(65535u)), 0x01));

               ir_variable *const r087A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r087A, rshift(r085C, body.constant(int(16))), 0x01));

               ir_variable *const r087B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r087B, mul(r0878, r0879), 0x01));

               ir_expression *const r087C = mul(r0877, r087A);
               body.emit(assign(r0875, add(r087C, r087B), 0x01));

               ir_expression *const r087D = mul(r0878, r087A);
               ir_expression *const r087E = less(r0875, r087B);
               ir_expression *const r087F = expr(ir_unop_b2i, r087E);
               ir_expression *const r0880 = expr(ir_unop_i2u, r087F);
               ir_expression *const r0881 = lshift(r0880, body.constant(int(16)));
               ir_expression *const r0882 = rshift(r0875, body.constant(int(16)));
               ir_expression *const r0883 = add(r0881, r0882);
               body.emit(assign(r0874, add(r087D, r0883), 0x01));

               body.emit(assign(r0875, lshift(r0875, body.constant(int(16))), 0x01));

               ir_expression *const r0884 = mul(r0877, r0879);
               body.emit(assign(r0876, add(r0884, r0875), 0x01));

               ir_expression *const r0885 = less(r0876, r0875);
               ir_expression *const r0886 = expr(ir_unop_b2i, r0885);
               ir_expression *const r0887 = expr(ir_unop_i2u, r0886);
               body.emit(assign(r0874, add(r0874, r0887), 0x01));

               ir_variable *const r0888 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0888, add(r0876, r0860), 0x01));

               ir_variable *const r0889 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0889);
               ir_variable *const r088A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r088A);
               ir_variable *const r088B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r088B);
               ir_variable *const r088C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r088C, bit_and(r07C6, body.constant(65535u)), 0x01));

               ir_variable *const r088D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r088D, rshift(r07C6, body.constant(int(16))), 0x01));

               ir_variable *const r088E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r088E, bit_and(r085C, body.constant(65535u)), 0x01));

               ir_variable *const r088F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r088F, rshift(r085C, body.constant(int(16))), 0x01));

               ir_variable *const r0890 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0890, mul(r088D, r088E), 0x01));

               ir_expression *const r0891 = mul(r088C, r088F);
               body.emit(assign(r088A, add(r0891, r0890), 0x01));

               ir_expression *const r0892 = mul(r088D, r088F);
               ir_expression *const r0893 = less(r088A, r0890);
               ir_expression *const r0894 = expr(ir_unop_b2i, r0893);
               ir_expression *const r0895 = expr(ir_unop_i2u, r0894);
               ir_expression *const r0896 = lshift(r0895, body.constant(int(16)));
               ir_expression *const r0897 = rshift(r088A, body.constant(int(16)));
               ir_expression *const r0898 = add(r0896, r0897);
               body.emit(assign(r0889, add(r0892, r0898), 0x01));

               body.emit(assign(r088A, lshift(r088A, body.constant(int(16))), 0x01));

               ir_expression *const r0899 = mul(r088C, r088E);
               body.emit(assign(r088B, add(r0899, r088A), 0x01));

               ir_expression *const r089A = less(r088B, r088A);
               ir_expression *const r089B = expr(ir_unop_b2i, r089A);
               ir_expression *const r089C = expr(ir_unop_i2u, r089B);
               body.emit(assign(r0889, add(r0889, r089C), 0x01));

               ir_variable *const r089D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r089E = less(r0888, r0876);
               ir_expression *const r089F = expr(ir_unop_b2i, r089E);
               ir_expression *const r08A0 = expr(ir_unop_i2u, r089F);
               ir_expression *const r08A1 = add(r0874, r08A0);
               body.emit(assign(r089D, add(r088B, r08A1), 0x01));

               ir_variable *const r08A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r08A2);
               ir_variable *const r08A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r08A3);
               ir_variable *const r08A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r08A4);
               ir_variable *const r08A5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A5, bit_and(r07C6, body.constant(65535u)), 0x01));

               ir_variable *const r08A6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A6, rshift(r07C6, body.constant(int(16))), 0x01));

               ir_variable *const r08A7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A7, bit_and(r085D, body.constant(65535u)), 0x01));

               ir_variable *const r08A8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A8, rshift(r085D, body.constant(int(16))), 0x01));

               ir_variable *const r08A9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A9, mul(r08A6, r08A7), 0x01));

               ir_expression *const r08AA = mul(r08A5, r08A8);
               body.emit(assign(r08A3, add(r08AA, r08A9), 0x01));

               ir_expression *const r08AB = mul(r08A6, r08A8);
               ir_expression *const r08AC = less(r08A3, r08A9);
               ir_expression *const r08AD = expr(ir_unop_b2i, r08AC);
               ir_expression *const r08AE = expr(ir_unop_i2u, r08AD);
               ir_expression *const r08AF = lshift(r08AE, body.constant(int(16)));
               ir_expression *const r08B0 = rshift(r08A3, body.constant(int(16)));
               ir_expression *const r08B1 = add(r08AF, r08B0);
               body.emit(assign(r08A2, add(r08AB, r08B1), 0x01));

               body.emit(assign(r08A3, lshift(r08A3, body.constant(int(16))), 0x01));

               ir_expression *const r08B2 = mul(r08A5, r08A7);
               body.emit(assign(r08A4, add(r08B2, r08A3), 0x01));

               ir_expression *const r08B3 = less(r08A4, r08A3);
               ir_expression *const r08B4 = expr(ir_unop_b2i, r08B3);
               ir_expression *const r08B5 = expr(ir_unop_i2u, r08B4);
               body.emit(assign(r08A2, add(r08A2, r08B5), 0x01));

               ir_variable *const r08B6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08B6, add(r08A4, r0888), 0x01));

               ir_variable *const r08B7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r08B8 = less(r08B6, r08A4);
               ir_expression *const r08B9 = expr(ir_unop_b2i, r08B8);
               ir_expression *const r08BA = expr(ir_unop_i2u, r08B9);
               ir_expression *const r08BB = add(r08A2, r08BA);
               body.emit(assign(r08B7, add(r089D, r08BB), 0x01));

               ir_variable *const r08BC = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r08BD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08BD, add(r08B7, r07C7), 0x01));

               ir_expression *const r08BE = less(r089D, r088B);
               ir_expression *const r08BF = expr(ir_unop_b2i, r08BE);
               ir_expression *const r08C0 = expr(ir_unop_i2u, r08BF);
               ir_expression *const r08C1 = add(r0889, r08C0);
               ir_expression *const r08C2 = less(r08B7, r089D);
               ir_expression *const r08C3 = expr(ir_unop_b2i, r08C2);
               ir_expression *const r08C4 = expr(ir_unop_i2u, r08C3);
               ir_expression *const r08C5 = add(r08C1, r08C4);
               ir_expression *const r08C6 = add(r08C5, r07C6);
               ir_expression *const r08C7 = less(r08BD, r08B7);
               ir_expression *const r08C8 = expr(ir_unop_b2i, r08C7);
               ir_expression *const r08C9 = expr(ir_unop_i2u, r08C8);
               body.emit(assign(r08BC, add(r08C6, r08C9), 0x01));

               body.emit(assign(r07CB, r08BC, 0x01));

               body.emit(assign(r07CA, r08BD, 0x01));

               ir_expression *const r08CA = nequal(r0862, body.constant(0u));
               ir_expression *const r08CB = expr(ir_unop_b2i, r08CA);
               ir_expression *const r08CC = expr(ir_unop_i2u, r08CB);
               body.emit(assign(r07C9, bit_or(r08B6, r08CC), 0x01));

               /* IF CONDITION */
               ir_expression *const r08CE = gequal(r08BC, body.constant(2097152u));
               ir_if *f08CD = new(mem_ctx) ir_if(operand(r08CE).val);
               exec_list *const f08CD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08CD->then_instructions;

                  ir_variable *const r08CF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r08CF);
                  body.emit(assign(r08CF, lshift(r08BD, body.constant(int(31))), 0x01));

                  ir_expression *const r08D0 = nequal(r07C9, body.constant(0u));
                  ir_expression *const r08D1 = expr(ir_unop_b2i, r08D0);
                  ir_expression *const r08D2 = expr(ir_unop_i2u, r08D1);
                  body.emit(assign(r08CF, bit_or(r08CF, r08D2), 0x01));

                  body.emit(assign(r07CB, rshift(r08BC, body.constant(int(1))), 0x01));

                  ir_expression *const r08D3 = lshift(r08BC, body.constant(int(31)));
                  ir_expression *const r08D4 = rshift(r08BD, body.constant(int(1)));
                  body.emit(assign(r07CA, bit_or(r08D3, r08D4), 0x01));

                  body.emit(assign(r07C9, r08CF, 0x01));

                  body.emit(assign(r07C8, add(r07C8, body.constant(int(1))), 0x01));


               body.instructions = f08CD_parent_instructions;
               body.emit(f08CD);

               /* END IF */

               ir_variable *const r08D5 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r08D5, r07C8, 0x01));

               ir_variable *const r08D6 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r08D6, r07CB, 0x01));

               ir_variable *const r08D7 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r08D7, r07CA, 0x01));

               ir_variable *const r08D8 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r08D8, r07C9, 0x01));

               ir_variable *const r08D9 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r08D9, body.constant(true), 0x01));

               ir_variable *const r08DA = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r08DB = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r08DB);
               ir_expression *const r08DC = expr(ir_unop_u2i, r07C9);
               body.emit(assign(r08DB, less(r08DC, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r08DE = gequal(r07C8, body.constant(int(2045)));
               ir_if *f08DD = new(mem_ctx) ir_if(operand(r08DE).val);
               exec_list *const f08DD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08DD->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r08E0 = less(body.constant(int(2045)), r07C8);
                  ir_expression *const r08E1 = equal(r07C8, body.constant(int(2045)));
                  ir_expression *const r08E2 = equal(body.constant(2097151u), r07CB);
                  ir_expression *const r08E3 = equal(body.constant(4294967295u), r07CA);
                  ir_expression *const r08E4 = logic_and(r08E2, r08E3);
                  ir_expression *const r08E5 = logic_and(r08E1, r08E4);
                  ir_expression *const r08E6 = logic_and(r08E5, r08DB);
                  ir_expression *const r08E7 = logic_or(r08E0, r08E6);
                  ir_if *f08DF = new(mem_ctx) ir_if(operand(r08E7).val);
                  exec_list *const f08DF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08DF->then_instructions;

                     ir_variable *const r08E8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r08E8);
                     ir_expression *const r08E9 = lshift(r07C1, body.constant(int(31)));
                     body.emit(assign(r08E8, add(r08E9, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r08E8, body.constant(0u), 0x01));

                     body.emit(assign(r08DA, r08E8, 0x03));

                     body.emit(assign(r08D9, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08DF->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r08EB = less(r07C8, body.constant(int(0)));
                     ir_if *f08EA = new(mem_ctx) ir_if(operand(r08EB).val);
                     exec_list *const f08EA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08EA->then_instructions;

                        ir_variable *const r08EC = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r08EC, r07C9, 0x01));

                        ir_variable *const r08ED = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r08ED, neg(r07C8), 0x01));

                        ir_variable *const r08EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r08EE);
                        ir_variable *const r08EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r08EF);
                        ir_variable *const r08F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r08F0);
                        ir_variable *const r08F1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r08F2 = neg(r08ED);
                        body.emit(assign(r08F1, bit_and(r08F2, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08F4 = equal(r08ED, body.constant(int(0)));
                        ir_if *f08F3 = new(mem_ctx) ir_if(operand(r08F4).val);
                        exec_list *const f08F3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08F3->then_instructions;

                           body.emit(assign(r08EE, r07C9, 0x01));

                           body.emit(assign(r08EF, r07CA, 0x01));

                           body.emit(assign(r08F0, r07CB, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f08F3->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r08F6 = less(r08ED, body.constant(int(32)));
                           ir_if *f08F5 = new(mem_ctx) ir_if(operand(r08F6).val);
                           exec_list *const f08F5_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f08F5->then_instructions;

                              body.emit(assign(r08EE, lshift(r07CA, r08F1), 0x01));

                              ir_expression *const r08F7 = lshift(r07CB, r08F1);
                              ir_expression *const r08F8 = rshift(r07CA, r08ED);
                              body.emit(assign(r08EF, bit_or(r08F7, r08F8), 0x01));

                              body.emit(assign(r08F0, rshift(r07CB, r08ED), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f08F5->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r08FA = equal(r08ED, body.constant(int(32)));
                              ir_if *f08F9 = new(mem_ctx) ir_if(operand(r08FA).val);
                              exec_list *const f08F9_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f08F9->then_instructions;

                                 body.emit(assign(r08EE, r07CA, 0x01));

                                 body.emit(assign(r08EF, r07CB, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f08F9->else_instructions;

                                 body.emit(assign(r08EC, bit_or(r07C9, r07CA), 0x01));

                                 ir_expression *const r08FB = less(r08ED, body.constant(int(64)));
                                 ir_expression *const r08FC = lshift(r07CB, r08F1);
                                 ir_expression *const r08FD = equal(r08ED, body.constant(int(64)));
                                 ir_expression *const r08FE = nequal(r07CB, body.constant(0u));
                                 ir_expression *const r08FF = expr(ir_unop_b2i, r08FE);
                                 ir_expression *const r0900 = expr(ir_unop_i2u, r08FF);
                                 ir_expression *const r0901 = expr(ir_triop_csel, r08FD, r07CB, r0900);
                                 body.emit(assign(r08EE, expr(ir_triop_csel, r08FB, r08FC, r0901), 0x01));

                                 ir_expression *const r0902 = less(r08ED, body.constant(int(64)));
                                 ir_expression *const r0903 = bit_and(r08ED, body.constant(int(31)));
                                 ir_expression *const r0904 = rshift(r07CB, r0903);
                                 body.emit(assign(r08EF, expr(ir_triop_csel, r0902, r0904, body.constant(0u)), 0x01));


                              body.instructions = f08F9_parent_instructions;
                              body.emit(f08F9);

                              /* END IF */

                              body.emit(assign(r08F0, body.constant(0u), 0x01));


                           body.instructions = f08F5_parent_instructions;
                           body.emit(f08F5);

                           /* END IF */

                           ir_expression *const r0905 = nequal(r08EC, body.constant(0u));
                           ir_expression *const r0906 = expr(ir_unop_b2i, r0905);
                           ir_expression *const r0907 = expr(ir_unop_i2u, r0906);
                           body.emit(assign(r08EE, bit_or(r08EE, r0907), 0x01));


                        body.instructions = f08F3_parent_instructions;
                        body.emit(f08F3);

                        /* END IF */

                        body.emit(assign(r08D6, r08F0, 0x01));

                        body.emit(assign(r08D7, r08EF, 0x01));

                        body.emit(assign(r08D8, r08EE, 0x01));

                        body.emit(assign(r08D5, body.constant(int(0)), 0x01));

                        body.emit(assign(r08DB, less(r08EE, body.constant(0u)), 0x01));


                     body.instructions = f08EA_parent_instructions;
                     body.emit(f08EA);

                     /* END IF */


                  body.instructions = f08DF_parent_instructions;
                  body.emit(f08DF);

                  /* END IF */


               body.instructions = f08DD_parent_instructions;
               body.emit(f08DD);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0908 = new(mem_ctx) ir_if(operand(r08D9).val);
               exec_list *const f0908_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0908->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0909 = new(mem_ctx) ir_if(operand(r08DB).val);
                  exec_list *const f0909_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0909->then_instructions;

                     ir_variable *const r090A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r090A, add(r08D7, body.constant(1u)), 0x01));

                     ir_expression *const r090B = less(r090A, r08D7);
                     ir_expression *const r090C = expr(ir_unop_b2i, r090B);
                     ir_expression *const r090D = expr(ir_unop_i2u, r090C);
                     body.emit(assign(r08D6, add(r08D6, r090D), 0x01));

                     ir_expression *const r090E = equal(r08D8, body.constant(0u));
                     ir_expression *const r090F = expr(ir_unop_b2i, r090E);
                     ir_expression *const r0910 = expr(ir_unop_i2u, r090F);
                     ir_expression *const r0911 = add(r08D8, r0910);
                     ir_expression *const r0912 = bit_and(r0911, body.constant(1u));
                     ir_expression *const r0913 = expr(ir_unop_bit_not, r0912);
                     body.emit(assign(r08D7, bit_and(r090A, r0913), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0909->else_instructions;

                     ir_expression *const r0914 = bit_or(r08D6, r08D7);
                     ir_expression *const r0915 = equal(r0914, body.constant(0u));
                     body.emit(assign(r08D5, expr(ir_triop_csel, r0915, body.constant(int(0)), r08D5), 0x01));


                  body.instructions = f0909_parent_instructions;
                  body.emit(f0909);

                  /* END IF */

                  ir_variable *const r0916 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0916);
                  ir_expression *const r0917 = lshift(r07C1, body.constant(int(31)));
                  ir_expression *const r0918 = expr(ir_unop_i2u, r08D5);
                  ir_expression *const r0919 = lshift(r0918, body.constant(int(20)));
                  ir_expression *const r091A = add(r0917, r0919);
                  body.emit(assign(r0916, add(r091A, r08D6), 0x02));

                  body.emit(assign(r0916, r08D7, 0x01));

                  body.emit(assign(r08DA, r0916, 0x03));

                  body.emit(assign(r08D9, body.constant(false), 0x01));


               body.instructions = f0908_parent_instructions;
               body.emit(f0908);

               /* END IF */

               body.emit(assign(r07C0, r08DA, 0x03));

               body.emit(assign(r07BF, body.constant(false), 0x01));


            body.instructions = f085A_parent_instructions;
            body.emit(f085A);

            /* END IF */


         body.instructions = f083B_parent_instructions;
         body.emit(f083B);

         /* END IF */


      body.instructions = f07FD_parent_instructions;
      body.emit(f07FD);

      /* END IF */


   body.instructions = f07D8_parent_instructions;
   body.emit(f07D8);

   /* END IF */

   body.emit(ret(r07C0));

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

   ir_variable *const r091B = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r091B);
   ir_variable *const r091C = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r091C);
   ir_variable *const r091D = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r091D);
   ir_variable *const r091E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r091E);
   ir_variable *const r091F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r091F);
   ir_expression *const r0920 = equal(r091D, body.constant(int(0)));
   ir_expression *const r0921 = less(r091D, body.constant(int(32)));
   ir_expression *const r0922 = neg(r091D);
   ir_expression *const r0923 = bit_and(r0922, body.constant(int(31)));
   ir_expression *const r0924 = lshift(r091B, r0923);
   ir_expression *const r0925 = rshift(r091C, r091D);
   ir_expression *const r0926 = bit_or(r0924, r0925);
   ir_expression *const r0927 = less(r091D, body.constant(int(64)));
   ir_expression *const r0928 = bit_and(r091D, body.constant(int(31)));
   ir_expression *const r0929 = rshift(r091B, r0928);
   ir_expression *const r092A = expr(ir_triop_csel, r0927, r0929, body.constant(0u));
   ir_expression *const r092B = expr(ir_triop_csel, r0921, r0926, r092A);
   body.emit(assign(r091F, expr(ir_triop_csel, r0920, r091B, r092B), 0x01));

   ir_expression *const r092C = equal(r091D, body.constant(int(0)));
   ir_expression *const r092D = less(r091D, body.constant(int(32)));
   ir_expression *const r092E = rshift(r091B, r091D);
   ir_expression *const r092F = expr(ir_triop_csel, r092D, r092E, body.constant(0u));
   body.emit(assign(r091E, expr(ir_triop_csel, r092C, r091B, r092F), 0x01));

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

   ir_variable *const r0930 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0930);
   ir_variable *const r0931 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0932 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0932);
   ir_variable *const r0933 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0933);
   ir_variable *const r0934 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0934, swizzle_x(r0930), 0x01));

   body.emit(assign(r0933, r0934, 0x01));

   ir_variable *const r0935 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0935, bit_and(swizzle_y(r0930), body.constant(1048575u)), 0x01));

   body.emit(assign(r0932, r0935, 0x01));

   ir_variable *const r0936 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0937 = rshift(swizzle_y(r0930), body.constant(int(20)));
   ir_expression *const r0938 = bit_and(r0937, body.constant(2047u));
   body.emit(assign(r0936, expr(ir_unop_u2i, r0938), 0x01));

   ir_variable *const r0939 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0939, rshift(swizzle_y(r0930), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r093B = nequal(r0939, body.constant(0u));
   ir_if *f093A = new(mem_ctx) ir_if(operand(r093B).val);
   exec_list *const f093A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f093A->then_instructions;

      body.emit(assign(r0931, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f093A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r093D = equal(r0936, body.constant(int(2047)));
      ir_expression *const r093E = bit_or(r0935, swizzle_x(r0930));
      ir_expression *const r093F = nequal(r093E, body.constant(0u));
      ir_expression *const r0940 = logic_and(r093D, r093F);
      ir_if *f093C = new(mem_ctx) ir_if(operand(r0940).val);
      exec_list *const f093C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f093C->then_instructions;

         body.emit(assign(r0931, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f093C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0942 = nequal(r0936, body.constant(int(0)));
         ir_if *f0941 = new(mem_ctx) ir_if(operand(r0942).val);
         exec_list *const f0941_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0941->then_instructions;

            body.emit(assign(r0932, bit_or(r0935, body.constant(1048576u)), 0x01));


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

            ir_variable *const r0949 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r094A = less(r0943, body.constant(int(32)));
            ir_expression *const r094B = rshift(r0932, r0943);
            ir_expression *const r094C = equal(r0943, body.constant(int(0)));
            ir_expression *const r094D = expr(ir_triop_csel, r094C, r0932, body.constant(0u));
            body.emit(assign(r0949, expr(ir_triop_csel, r094A, r094B, r094D), 0x01));

            /* IF CONDITION */
            ir_expression *const r094F = equal(r0943, body.constant(int(0)));
            ir_if *f094E = new(mem_ctx) ir_if(operand(r094F).val);
            exec_list *const f094E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f094E->then_instructions;

               body.emit(assign(r0946, r0934, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f094E->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0951 = less(r0943, body.constant(int(32)));
               ir_if *f0950 = new(mem_ctx) ir_if(operand(r0951).val);
               exec_list *const f0950_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0950->then_instructions;

                  ir_expression *const r0952 = lshift(r0932, r0947);
                  ir_expression *const r0953 = rshift(swizzle_x(r0930), r0943);
                  ir_expression *const r0954 = bit_or(r0952, r0953);
                  ir_expression *const r0955 = lshift(swizzle_x(r0930), r0947);
                  ir_expression *const r0956 = nequal(r0955, body.constant(0u));
                  ir_expression *const r0957 = expr(ir_unop_b2i, r0956);
                  ir_expression *const r0958 = expr(ir_unop_i2u, r0957);
                  body.emit(assign(r0946, bit_or(r0954, r0958), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0950->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r095A = equal(r0943, body.constant(int(32)));
                  ir_if *f0959 = new(mem_ctx) ir_if(operand(r095A).val);
                  exec_list *const f0959_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0959->then_instructions;

                     ir_expression *const r095B = nequal(swizzle_x(r0930), body.constant(0u));
                     ir_expression *const r095C = expr(ir_unop_b2i, r095B);
                     ir_expression *const r095D = expr(ir_unop_i2u, r095C);
                     body.emit(assign(r0946, bit_or(r0932, r095D), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0959->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r095F = less(r0943, body.constant(int(64)));
                     ir_if *f095E = new(mem_ctx) ir_if(operand(r095F).val);
                     exec_list *const f095E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f095E->then_instructions;

                        ir_expression *const r0960 = bit_and(r0943, body.constant(int(31)));
                        ir_expression *const r0961 = rshift(r0932, r0960);
                        ir_expression *const r0962 = lshift(r0932, r0947);
                        ir_expression *const r0963 = bit_or(r0962, swizzle_x(r0930));
                        ir_expression *const r0964 = nequal(r0963, body.constant(0u));
                        ir_expression *const r0965 = expr(ir_unop_b2i, r0964);
                        ir_expression *const r0966 = expr(ir_unop_i2u, r0965);
                        body.emit(assign(r0946, bit_or(r0961, r0966), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f095E->else_instructions;

                        ir_expression *const r0967 = bit_or(r0932, swizzle_x(r0930));
                        ir_expression *const r0968 = nequal(r0967, body.constant(0u));
                        ir_expression *const r0969 = expr(ir_unop_b2i, r0968);
                        body.emit(assign(r0946, expr(ir_unop_i2u, r0969), 0x01));


                     body.instructions = f095E_parent_instructions;
                     body.emit(f095E);

                     /* END IF */


                  body.instructions = f0959_parent_instructions;
                  body.emit(f0959);

                  /* END IF */


               body.instructions = f0950_parent_instructions;
               body.emit(f0950);

               /* END IF */


            body.instructions = f094E_parent_instructions;
            body.emit(f094E);

            /* END IF */

            body.emit(assign(r0932, r0949, 0x01));

            body.emit(assign(r0933, r0946, 0x01));


         body.instructions = f0944_parent_instructions;
         body.emit(f0944);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r096B = bit_and(r0932, body.constant(4294963200u));
         ir_expression *const r096C = nequal(r096B, body.constant(0u));
         ir_if *f096A = new(mem_ctx) ir_if(operand(r096C).val);
         exec_list *const f096A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f096A->then_instructions;

            ir_variable *const r096D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r096F = nequal(r0939, body.constant(0u));
            ir_if *f096E = new(mem_ctx) ir_if(operand(r096F).val);
            exec_list *const f096E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f096E->then_instructions;

               body.emit(assign(r096D, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f096E->else_instructions;

               body.emit(assign(r096D, body.constant(4294967295u), 0x01));


            body.instructions = f096E_parent_instructions;
            body.emit(f096E);

            /* END IF */

            body.emit(assign(r0931, r096D, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f096A->else_instructions;

            ir_variable *const r0970 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r0971 = lshift(r0932, body.constant(int(20)));
            ir_expression *const r0972 = rshift(r0933, body.constant(int(12)));
            body.emit(assign(r0970, bit_or(r0971, r0972), 0x01));

            /* IF CONDITION */
            ir_expression *const r0974 = nequal(r0939, body.constant(0u));
            ir_expression *const r0975 = nequal(r0970, body.constant(0u));
            ir_expression *const r0976 = logic_and(r0974, r0975);
            ir_if *f0973 = new(mem_ctx) ir_if(operand(r0976).val);
            exec_list *const f0973_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0973->then_instructions;

               ir_variable *const r0977 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0979 = nequal(r0939, body.constant(0u));
               ir_if *f0978 = new(mem_ctx) ir_if(operand(r0979).val);
               exec_list *const f0978_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0978->then_instructions;

                  body.emit(assign(r0977, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0978->else_instructions;

                  body.emit(assign(r0977, body.constant(4294967295u), 0x01));


               body.instructions = f0978_parent_instructions;
               body.emit(f0978);

               /* END IF */

               body.emit(assign(r0931, r0977, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0973->else_instructions;

               body.emit(assign(r0931, r0970, 0x01));


            body.instructions = f0973_parent_instructions;
            body.emit(f0973);

            /* END IF */


         body.instructions = f096A_parent_instructions;
         body.emit(f096A);

         /* END IF */


      body.instructions = f093C_parent_instructions;
      body.emit(f093C);

      /* END IF */


   body.instructions = f093A_parent_instructions;
   body.emit(f093A);

   /* END IF */

   body.emit(ret(r0931));

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

   ir_variable *const r097A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r097A);
   ir_variable *const r097B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r097C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r097C);
   ir_variable *const r097D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r097D);
   /* IF CONDITION */
   ir_expression *const r097F = equal(r097A, body.constant(0u));
   ir_if *f097E = new(mem_ctx) ir_if(operand(r097F).val);
   exec_list *const f097E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f097E->then_instructions;

      body.emit(assign(r097B, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f097E->else_instructions;

      ir_variable *const r0980 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0981 = equal(r097A, body.constant(0u));
      ir_expression *const r0982 = expr(ir_unop_find_msb, r097A);
      ir_expression *const r0983 = sub(body.constant(int(31)), r0982);
      ir_expression *const r0984 = expr(ir_triop_csel, r0981, body.constant(int(32)), r0983);
      body.emit(assign(r0980, add(r0984, body.constant(int(21))), 0x01));

      body.emit(assign(r097D, body.constant(0u), 0x01));

      body.emit(assign(r097C, body.constant(0u), 0x01));

      ir_variable *const r0985 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0986 = neg(r0980);
      body.emit(assign(r0985, bit_and(r0986, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0988 = equal(r0980, body.constant(int(0)));
      ir_if *f0987 = new(mem_ctx) ir_if(operand(r0988).val);
      exec_list *const f0987_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0987->then_instructions;

         body.emit(assign(r097D, body.constant(0u), 0x01));

         body.emit(assign(r097C, r097A, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0987->else_instructions;

         /* IF CONDITION */
         ir_expression *const r098A = less(r0980, body.constant(int(32)));
         ir_if *f0989 = new(mem_ctx) ir_if(operand(r098A).val);
         exec_list *const f0989_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0989->then_instructions;

            body.emit(assign(r097D, rshift(r097A, r0985), 0x01));

            body.emit(assign(r097C, lshift(r097A, r0980), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0989->else_instructions;

            ir_variable *const r098B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r098D = less(r0980, body.constant(int(64)));
            ir_if *f098C = new(mem_ctx) ir_if(operand(r098D).val);
            exec_list *const f098C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f098C->then_instructions;

               ir_expression *const r098E = add(r0980, body.constant(int(-32)));
               body.emit(assign(r098B, lshift(r097A, r098E), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f098C->else_instructions;

               body.emit(assign(r098B, body.constant(0u), 0x01));


            body.instructions = f098C_parent_instructions;
            body.emit(f098C);

            /* END IF */

            body.emit(assign(r097D, r098B, 0x01));

            body.emit(assign(r097C, body.constant(0u), 0x01));


         body.instructions = f0989_parent_instructions;
         body.emit(f0989);

         /* END IF */


      body.instructions = f0987_parent_instructions;
      body.emit(f0987);

      /* END IF */

      ir_variable *const r098F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r098F);
      ir_expression *const r0990 = sub(body.constant(int(1074)), r0980);
      ir_expression *const r0991 = expr(ir_unop_i2u, r0990);
      ir_expression *const r0992 = lshift(r0991, body.constant(int(20)));
      body.emit(assign(r098F, add(r0992, r097D), 0x02));

      body.emit(assign(r098F, r097C, 0x01));

      body.emit(assign(r097B, r098F, 0x03));


   body.instructions = f097E_parent_instructions;
   body.emit(f097E);

   /* END IF */

   body.emit(ret(r097B));

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

   ir_variable *const r0993 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0993);
   ir_variable *const r0994 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0994, body.constant(true), 0x01));

   ir_variable *const r0995 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0996 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0996);
   ir_variable *const r0997 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0997);
   ir_variable *const r0998 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0998);
   ir_variable *const r0999 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0999, bit_and(swizzle_y(r0993), body.constant(1048575u)), 0x01));

   body.emit(assign(r0998, r0999, 0x01));

   ir_variable *const r099A = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r099B = rshift(swizzle_y(r0993), body.constant(int(20)));
   ir_expression *const r099C = bit_and(r099B, body.constant(2047u));
   body.emit(assign(r099A, expr(ir_unop_u2i, r099C), 0x01));

   body.emit(assign(r0997, rshift(swizzle_y(r0993), body.constant(int(31))), 0x01));

   body.emit(assign(r0996, body.constant(0u), 0x01));

   ir_variable *const r099D = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r099D, add(r099A, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r099F = gequal(r099D, body.constant(int(0)));
   ir_if *f099E = new(mem_ctx) ir_if(operand(r099F).val);
   exec_list *const f099E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f099E->then_instructions;

      /* IF CONDITION */
      ir_expression *const r09A1 = less(body.constant(int(1054)), r099A);
      ir_if *f09A0 = new(mem_ctx) ir_if(operand(r09A1).val);
      exec_list *const f09A0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09A0->then_instructions;

         /* IF CONDITION */
         ir_expression *const r09A3 = equal(r099A, body.constant(int(2047)));
         ir_expression *const r09A4 = bit_or(r0999, swizzle_x(r0993));
         ir_expression *const r09A5 = expr(ir_unop_u2i, r09A4);
         ir_expression *const r09A6 = expr(ir_unop_i2b, r09A5);
         ir_expression *const r09A7 = logic_and(r09A3, r09A6);
         ir_if *f09A2 = new(mem_ctx) ir_if(operand(r09A7).val);
         exec_list *const f09A2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09A2->then_instructions;

            body.emit(assign(r0997, body.constant(0u), 0x01));


         body.instructions = f09A2_parent_instructions;
         body.emit(f09A2);

         /* END IF */

         ir_variable *const r09A8 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09AA = expr(ir_unop_u2i, r0997);
         ir_expression *const r09AB = expr(ir_unop_i2b, r09AA);
         ir_if *f09A9 = new(mem_ctx) ir_if(operand(r09AB).val);
         exec_list *const f09A9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09A9->then_instructions;

            body.emit(assign(r09A8, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09A9->else_instructions;

            body.emit(assign(r09A8, body.constant(int(2147483647)), 0x01));


         body.instructions = f09A9_parent_instructions;
         body.emit(f09A9);

         /* END IF */

         body.emit(assign(r0995, r09A8, 0x01));

         body.emit(assign(r0994, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09A0->else_instructions;

         ir_variable *const r09AC = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r09AC, bit_or(r0999, body.constant(1048576u)), 0x01));

         ir_expression *const r09AD = equal(r099D, body.constant(int(0)));
         ir_expression *const r09AE = lshift(r09AC, r099D);
         ir_expression *const r09AF = neg(r099D);
         ir_expression *const r09B0 = bit_and(r09AF, body.constant(int(31)));
         ir_expression *const r09B1 = rshift(swizzle_x(r0993), r09B0);
         ir_expression *const r09B2 = bit_or(r09AE, r09B1);
         body.emit(assign(r0996, expr(ir_triop_csel, r09AD, r09AC, r09B2), 0x01));


      body.instructions = f09A0_parent_instructions;
      body.emit(f09A0);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f099E->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09B4 = less(r099A, body.constant(int(1023)));
      ir_if *f09B3 = new(mem_ctx) ir_if(operand(r09B4).val);
      exec_list *const f09B3_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09B3->then_instructions;

         body.emit(assign(r0995, body.constant(int(0)), 0x01));

         body.emit(assign(r0994, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09B3->else_instructions;

         body.emit(assign(r0998, bit_or(r0999, body.constant(1048576u)), 0x01));

         ir_expression *const r09B5 = neg(r099D);
         body.emit(assign(r0996, rshift(r0998, r09B5), 0x01));


      body.instructions = f09B3_parent_instructions;
      body.emit(f09B3);

      /* END IF */


   body.instructions = f099E_parent_instructions;
   body.emit(f099E);

   /* END IF */

   /* IF CONDITION */
   ir_if *f09B6 = new(mem_ctx) ir_if(operand(r0994).val);
   exec_list *const f09B6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09B6->then_instructions;

      ir_variable *const r09B7 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09B9 = nequal(r0997, body.constant(0u));
      ir_if *f09B8 = new(mem_ctx) ir_if(operand(r09B9).val);
      exec_list *const f09B8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09B8->then_instructions;

         ir_expression *const r09BA = expr(ir_unop_u2i, r0996);
         body.emit(assign(r09B7, neg(r09BA), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09B8->else_instructions;

         body.emit(assign(r09B7, expr(ir_unop_u2i, r0996), 0x01));


      body.instructions = f09B8_parent_instructions;
      body.emit(f09B8);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r09BC = less(r09B7, body.constant(int(0)));
      ir_expression *const r09BD = expr(ir_unop_b2i, r09BC);
      ir_expression *const r09BE = expr(ir_unop_i2u, r09BD);
      ir_expression *const r09BF = bit_xor(r0997, r09BE);
      ir_expression *const r09C0 = expr(ir_unop_u2i, r09BF);
      ir_expression *const r09C1 = expr(ir_unop_i2b, r09C0);
      ir_expression *const r09C2 = expr(ir_unop_i2b, r09B7);
      ir_expression *const r09C3 = logic_and(r09C1, r09C2);
      ir_if *f09BB = new(mem_ctx) ir_if(operand(r09C3).val);
      exec_list *const f09BB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09BB->then_instructions;

         ir_variable *const r09C4 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09C6 = expr(ir_unop_u2i, r0997);
         ir_expression *const r09C7 = expr(ir_unop_i2b, r09C6);
         ir_if *f09C5 = new(mem_ctx) ir_if(operand(r09C7).val);
         exec_list *const f09C5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09C5->then_instructions;

            body.emit(assign(r09C4, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09C5->else_instructions;

            body.emit(assign(r09C4, body.constant(int(2147483647)), 0x01));


         body.instructions = f09C5_parent_instructions;
         body.emit(f09C5);

         /* END IF */

         body.emit(assign(r0995, r09C4, 0x01));

         body.emit(assign(r0994, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09BB->else_instructions;

         body.emit(assign(r0995, r09B7, 0x01));

         body.emit(assign(r0994, body.constant(false), 0x01));


      body.instructions = f09BB_parent_instructions;
      body.emit(f09BB);

      /* END IF */


   body.instructions = f09B6_parent_instructions;
   body.emit(f09B6);

   /* END IF */

   body.emit(ret(r0995));

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

   ir_variable *const r09C8 = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r09C8);
   ir_variable *const r09C9 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r09CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r09CA);
   ir_variable *const r09CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r09CB);
   ir_variable *const r09CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r09CC);
   body.emit(assign(r09CC, body.constant(0u), 0x01));

   body.emit(assign(r09CB, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r09CE = equal(r09C8, body.constant(int(0)));
   ir_if *f09CD = new(mem_ctx) ir_if(operand(r09CE).val);
   exec_list *const f09CD_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09CD->then_instructions;

      ir_variable *const r09CF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r09CF);
      body.emit(assign(r09CF, body.constant(0u), 0x02));

      body.emit(assign(r09CF, body.constant(0u), 0x01));

      body.emit(assign(r09C9, r09CF, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09CD->else_instructions;

      ir_expression *const r09D0 = less(r09C8, body.constant(int(0)));
      ir_expression *const r09D1 = expr(ir_unop_b2i, r09D0);
      body.emit(assign(r09CA, expr(ir_unop_i2u, r09D1), 0x01));

      ir_variable *const r09D2 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09D4 = less(r09C8, body.constant(int(0)));
      ir_if *f09D3 = new(mem_ctx) ir_if(operand(r09D4).val);
      exec_list *const f09D3_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09D3->then_instructions;

         ir_expression *const r09D5 = neg(r09C8);
         body.emit(assign(r09D2, expr(ir_unop_i2u, r09D5), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09D3->else_instructions;

         body.emit(assign(r09D2, expr(ir_unop_i2u, r09C8), 0x01));


      body.instructions = f09D3_parent_instructions;
      body.emit(f09D3);

      /* END IF */

      ir_variable *const r09D6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r09D7 = equal(r09D2, body.constant(0u));
      ir_expression *const r09D8 = expr(ir_unop_find_msb, r09D2);
      ir_expression *const r09D9 = sub(body.constant(int(31)), r09D8);
      ir_expression *const r09DA = expr(ir_triop_csel, r09D7, body.constant(int(32)), r09D9);
      body.emit(assign(r09D6, add(r09DA, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r09DC = gequal(r09D6, body.constant(int(0)));
      ir_if *f09DB = new(mem_ctx) ir_if(operand(r09DC).val);
      exec_list *const f09DB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09DB->then_instructions;

         body.emit(assign(r09CC, lshift(r09D2, r09D6), 0x01));

         body.emit(assign(r09CB, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09DB->else_instructions;

         ir_variable *const r09DD = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r09DD, neg(r09D6), 0x01));

         ir_expression *const r09DE = equal(r09DD, body.constant(int(0)));
         ir_expression *const r09DF = less(r09DD, body.constant(int(32)));
         ir_expression *const r09E0 = rshift(r09D2, r09DD);
         ir_expression *const r09E1 = expr(ir_triop_csel, r09DF, r09E0, body.constant(0u));
         body.emit(assign(r09CC, expr(ir_triop_csel, r09DE, r09D2, r09E1), 0x01));

         ir_expression *const r09E2 = equal(r09DD, body.constant(int(0)));
         ir_expression *const r09E3 = less(r09DD, body.constant(int(32)));
         ir_expression *const r09E4 = neg(r09DD);
         ir_expression *const r09E5 = bit_and(r09E4, body.constant(int(31)));
         ir_expression *const r09E6 = lshift(r09D2, r09E5);
         ir_expression *const r09E7 = bit_or(r09E6, body.constant(0u));
         ir_expression *const r09E8 = less(r09DD, body.constant(int(64)));
         ir_expression *const r09E9 = bit_and(r09DD, body.constant(int(31)));
         ir_expression *const r09EA = rshift(r09D2, r09E9);
         ir_expression *const r09EB = expr(ir_triop_csel, r09E8, r09EA, body.constant(0u));
         ir_expression *const r09EC = expr(ir_triop_csel, r09E3, r09E7, r09EB);
         body.emit(assign(r09CB, expr(ir_triop_csel, r09E2, r09D2, r09EC), 0x01));


      body.instructions = f09DB_parent_instructions;
      body.emit(f09DB);

      /* END IF */

      ir_variable *const r09ED = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r09ED);
      ir_expression *const r09EE = lshift(r09CA, body.constant(int(31)));
      ir_expression *const r09EF = sub(body.constant(int(1042)), r09D6);
      ir_expression *const r09F0 = expr(ir_unop_i2u, r09EF);
      ir_expression *const r09F1 = lshift(r09F0, body.constant(int(20)));
      ir_expression *const r09F2 = add(r09EE, r09F1);
      body.emit(assign(r09ED, add(r09F2, r09CC), 0x02));

      body.emit(assign(r09ED, r09CB, 0x01));

      body.emit(assign(r09C9, r09ED, 0x03));


   body.instructions = f09CD_parent_instructions;
   body.emit(f09CD);

   /* END IF */

   body.emit(ret(r09C9));

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

   ir_variable *const r09F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r09F3);
   ir_variable *const r09F4 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r09F4);
   ir_variable *const r09F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r09F5);
   ir_variable *const r09F6 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r09F7 = lshift(r09F3, body.constant(int(31)));
   ir_expression *const r09F8 = expr(ir_unop_i2u, r09F4);
   ir_expression *const r09F9 = lshift(r09F8, body.constant(int(23)));
   ir_expression *const r09FA = add(r09F7, r09F9);
   ir_expression *const r09FB = add(r09FA, r09F5);
   body.emit(assign(r09F6, expr(ir_unop_bitcast_u2f, r09FB), 0x01));

   body.emit(ret(r09F6));

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

   ir_variable *const r09FC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r09FC);
   ir_variable *const r09FD = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r09FD);
   ir_variable *const r09FE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r09FE);
   ir_variable *const r09FF = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r09FF, body.constant(true), 0x01));

   ir_variable *const r0A00 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A01 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0A01);
   ir_expression *const r0A02 = bit_and(r09FE, body.constant(127u));
   body.emit(assign(r0A01, expr(ir_unop_u2i, r0A02), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A04 = expr(ir_unop_i2u, r09FD);
   ir_expression *const r0A05 = gequal(r0A04, body.constant(253u));
   ir_if *f0A03 = new(mem_ctx) ir_if(operand(r0A05).val);
   exec_list *const f0A03_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A03->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A07 = less(body.constant(int(253)), r09FD);
      ir_expression *const r0A08 = equal(r09FD, body.constant(int(253)));
      ir_expression *const r0A09 = expr(ir_unop_u2i, r09FE);
      ir_expression *const r0A0A = less(r0A09, body.constant(int(-64)));
      ir_expression *const r0A0B = logic_and(r0A08, r0A0A);
      ir_expression *const r0A0C = logic_or(r0A07, r0A0B);
      ir_if *f0A06 = new(mem_ctx) ir_if(operand(r0A0C).val);
      exec_list *const f0A06_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A06->then_instructions;

         ir_expression *const r0A0D = lshift(r09FC, body.constant(int(31)));
         ir_expression *const r0A0E = add(r0A0D, body.constant(2139095040u));
         body.emit(assign(r0A00, expr(ir_unop_bitcast_u2f, r0A0E), 0x01));

         body.emit(assign(r09FF, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A06->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A10 = less(r09FD, body.constant(int(0)));
         ir_if *f0A0F = new(mem_ctx) ir_if(operand(r0A10).val);
         exec_list *const f0A0F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A0F->then_instructions;

            ir_variable *const r0A11 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0A11, neg(r09FD), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A13 = less(r0A11, body.constant(int(32)));
            ir_if *f0A12 = new(mem_ctx) ir_if(operand(r0A13).val);
            exec_list *const f0A12_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A12->then_instructions;

               ir_expression *const r0A14 = rshift(r09FE, r0A11);
               ir_expression *const r0A15 = neg(r0A11);
               ir_expression *const r0A16 = bit_and(r0A15, body.constant(int(31)));
               ir_expression *const r0A17 = lshift(r09FE, r0A16);
               ir_expression *const r0A18 = nequal(r0A17, body.constant(0u));
               ir_expression *const r0A19 = expr(ir_unop_b2i, r0A18);
               ir_expression *const r0A1A = expr(ir_unop_i2u, r0A19);
               body.emit(assign(r09FE, bit_or(r0A14, r0A1A), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A12->else_instructions;

               ir_expression *const r0A1B = nequal(r09FE, body.constant(0u));
               ir_expression *const r0A1C = expr(ir_unop_b2i, r0A1B);
               body.emit(assign(r09FE, expr(ir_unop_i2u, r0A1C), 0x01));


            body.instructions = f0A12_parent_instructions;
            body.emit(f0A12);

            /* END IF */

            body.emit(assign(r09FD, body.constant(int(0)), 0x01));

            ir_expression *const r0A1D = expr(ir_unop_u2i, r09FE);
            body.emit(assign(r0A01, bit_and(r0A1D, body.constant(int(127))), 0x01));


         body.instructions = f0A0F_parent_instructions;
         body.emit(f0A0F);

         /* END IF */


      body.instructions = f0A06_parent_instructions;
      body.emit(f0A06);

      /* END IF */


   body.instructions = f0A03_parent_instructions;
   body.emit(f0A03);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0A1E = new(mem_ctx) ir_if(operand(r09FF).val);
   exec_list *const f0A1E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A1E->then_instructions;

      ir_expression *const r0A1F = add(r09FE, body.constant(64u));
      body.emit(assign(r09FE, rshift(r0A1F, body.constant(int(7))), 0x01));

      ir_expression *const r0A20 = bit_xor(r0A01, body.constant(int(64)));
      ir_expression *const r0A21 = equal(r0A20, body.constant(int(0)));
      ir_expression *const r0A22 = expr(ir_unop_b2i, r0A21);
      ir_expression *const r0A23 = expr(ir_unop_i2u, r0A22);
      ir_expression *const r0A24 = expr(ir_unop_bit_not, r0A23);
      body.emit(assign(r09FE, bit_and(r09FE, r0A24), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A26 = equal(r09FE, body.constant(0u));
      ir_if *f0A25 = new(mem_ctx) ir_if(operand(r0A26).val);
      exec_list *const f0A25_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A25->then_instructions;

         body.emit(assign(r09FD, body.constant(int(0)), 0x01));


      body.instructions = f0A25_parent_instructions;
      body.emit(f0A25);

      /* END IF */

      ir_expression *const r0A27 = lshift(r09FC, body.constant(int(31)));
      ir_expression *const r0A28 = expr(ir_unop_i2u, r09FD);
      ir_expression *const r0A29 = lshift(r0A28, body.constant(int(23)));
      ir_expression *const r0A2A = add(r0A27, r0A29);
      ir_expression *const r0A2B = add(r0A2A, r09FE);
      body.emit(assign(r0A00, expr(ir_unop_bitcast_u2f, r0A2B), 0x01));

      body.emit(assign(r09FF, body.constant(false), 0x01));


   body.instructions = f0A1E_parent_instructions;
   body.emit(f0A1E);

   /* END IF */

   body.emit(ret(r0A00));

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

   ir_variable *const r0A2C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A2C);
   ir_variable *const r0A2D = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A2E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0A2E);
   body.emit(assign(r0A2E, body.constant(0u), 0x01));

   ir_variable *const r0A2F = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0A2F, swizzle_x(r0A2C), 0x01));

   ir_variable *const r0A30 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A30, bit_and(swizzle_y(r0A2C), body.constant(1048575u)), 0x01));

   ir_variable *const r0A31 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A32 = rshift(swizzle_y(r0A2C), body.constant(int(20)));
   ir_expression *const r0A33 = bit_and(r0A32, body.constant(2047u));
   body.emit(assign(r0A31, expr(ir_unop_u2i, r0A33), 0x01));

   ir_variable *const r0A34 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A34, rshift(swizzle_y(r0A2C), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A36 = equal(r0A31, body.constant(int(2047)));
   ir_if *f0A35 = new(mem_ctx) ir_if(operand(r0A36).val);
   exec_list *const f0A35_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A35->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A38 = bit_or(r0A30, swizzle_x(r0A2C));
      ir_expression *const r0A39 = nequal(r0A38, body.constant(0u));
      ir_if *f0A37 = new(mem_ctx) ir_if(operand(r0A39).val);
      exec_list *const f0A37_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A37->then_instructions;

         ir_variable *const r0A3A = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0A3A, lshift(swizzle_x(r0A2C), body.constant(int(12))), 0x01));

         ir_expression *const r0A3B = lshift(swizzle_y(r0A2C), body.constant(int(12)));
         ir_expression *const r0A3C = rshift(swizzle_x(r0A2C), body.constant(int(20)));
         body.emit(assign(r0A2C, bit_or(r0A3B, r0A3C), 0x02));

         body.emit(assign(r0A2C, r0A3A, 0x01));

         ir_expression *const r0A3D = lshift(r0A34, body.constant(int(31)));
         ir_expression *const r0A3E = bit_or(r0A3D, body.constant(2143289344u));
         ir_expression *const r0A3F = rshift(swizzle_y(r0A2C), body.constant(int(9)));
         ir_expression *const r0A40 = bit_or(r0A3E, r0A3F);
         body.emit(assign(r0A2D, expr(ir_unop_bitcast_u2f, r0A40), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A37->else_instructions;

         ir_expression *const r0A41 = lshift(r0A34, body.constant(int(31)));
         ir_expression *const r0A42 = add(r0A41, body.constant(2139095040u));
         body.emit(assign(r0A2D, expr(ir_unop_bitcast_u2f, r0A42), 0x01));


      body.instructions = f0A37_parent_instructions;
      body.emit(f0A37);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A35->else_instructions;

      ir_variable *const r0A43 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0A43);
      ir_variable *const r0A44 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0A44, rshift(r0A30, body.constant(int(22))), 0x01));

      ir_expression *const r0A45 = lshift(r0A30, body.constant(int(10)));
      ir_expression *const r0A46 = rshift(r0A2F, body.constant(int(22)));
      ir_expression *const r0A47 = bit_or(r0A45, r0A46);
      ir_expression *const r0A48 = lshift(r0A2F, body.constant(int(10)));
      ir_expression *const r0A49 = nequal(r0A48, body.constant(0u));
      ir_expression *const r0A4A = expr(ir_unop_b2i, r0A49);
      ir_expression *const r0A4B = expr(ir_unop_i2u, r0A4A);
      body.emit(assign(r0A43, bit_or(r0A47, r0A4B), 0x01));

      body.emit(assign(r0A2E, r0A43, 0x01));

      /* IF CONDITION */
      ir_expression *const r0A4D = nequal(r0A31, body.constant(int(0)));
      ir_if *f0A4C = new(mem_ctx) ir_if(operand(r0A4D).val);
      exec_list *const f0A4C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A4C->then_instructions;

         body.emit(assign(r0A2E, bit_or(r0A43, body.constant(1073741824u)), 0x01));


      body.instructions = f0A4C_parent_instructions;
      body.emit(f0A4C);

      /* END IF */

      ir_variable *const r0A4E = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0A4E, add(r0A31, body.constant(int(-897))), 0x01));

      ir_variable *const r0A4F = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0A4F, r0A2E, 0x01));

      ir_variable *const r0A50 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0A50, body.constant(true), 0x01));

      ir_variable *const r0A51 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0A52 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0A52);
      ir_expression *const r0A53 = bit_and(r0A2E, body.constant(127u));
      body.emit(assign(r0A52, expr(ir_unop_u2i, r0A53), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A55 = expr(ir_unop_i2u, r0A4E);
      ir_expression *const r0A56 = gequal(r0A55, body.constant(253u));
      ir_if *f0A54 = new(mem_ctx) ir_if(operand(r0A56).val);
      exec_list *const f0A54_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A54->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A58 = less(body.constant(int(253)), r0A4E);
         ir_expression *const r0A59 = equal(r0A4E, body.constant(int(253)));
         ir_expression *const r0A5A = expr(ir_unop_u2i, r0A2E);
         ir_expression *const r0A5B = less(r0A5A, body.constant(int(-64)));
         ir_expression *const r0A5C = logic_and(r0A59, r0A5B);
         ir_expression *const r0A5D = logic_or(r0A58, r0A5C);
         ir_if *f0A57 = new(mem_ctx) ir_if(operand(r0A5D).val);
         exec_list *const f0A57_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A57->then_instructions;

            ir_expression *const r0A5E = lshift(r0A34, body.constant(int(31)));
            ir_expression *const r0A5F = add(r0A5E, body.constant(2139095040u));
            body.emit(assign(r0A51, expr(ir_unop_bitcast_u2f, r0A5F), 0x01));

            body.emit(assign(r0A50, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A57->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0A61 = less(r0A4E, body.constant(int(0)));
            ir_if *f0A60 = new(mem_ctx) ir_if(operand(r0A61).val);
            exec_list *const f0A60_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A60->then_instructions;

               ir_variable *const r0A62 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0A62, neg(r0A4E), 0x01));

               /* IF CONDITION */
               ir_expression *const r0A64 = less(r0A62, body.constant(int(32)));
               ir_if *f0A63 = new(mem_ctx) ir_if(operand(r0A64).val);
               exec_list *const f0A63_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A63->then_instructions;

                  ir_expression *const r0A65 = rshift(r0A2E, r0A62);
                  ir_expression *const r0A66 = neg(r0A62);
                  ir_expression *const r0A67 = bit_and(r0A66, body.constant(int(31)));
                  ir_expression *const r0A68 = lshift(r0A2E, r0A67);
                  ir_expression *const r0A69 = nequal(r0A68, body.constant(0u));
                  ir_expression *const r0A6A = expr(ir_unop_b2i, r0A69);
                  ir_expression *const r0A6B = expr(ir_unop_i2u, r0A6A);
                  body.emit(assign(r0A4F, bit_or(r0A65, r0A6B), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A63->else_instructions;

                  ir_expression *const r0A6C = nequal(r0A4F, body.constant(0u));
                  ir_expression *const r0A6D = expr(ir_unop_b2i, r0A6C);
                  body.emit(assign(r0A4F, expr(ir_unop_i2u, r0A6D), 0x01));


               body.instructions = f0A63_parent_instructions;
               body.emit(f0A63);

               /* END IF */

               body.emit(assign(r0A4E, body.constant(int(0)), 0x01));

               ir_expression *const r0A6E = expr(ir_unop_u2i, r0A4F);
               body.emit(assign(r0A52, bit_and(r0A6E, body.constant(int(127))), 0x01));


            body.instructions = f0A60_parent_instructions;
            body.emit(f0A60);

            /* END IF */


         body.instructions = f0A57_parent_instructions;
         body.emit(f0A57);

         /* END IF */


      body.instructions = f0A54_parent_instructions;
      body.emit(f0A54);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A6F = new(mem_ctx) ir_if(operand(r0A50).val);
      exec_list *const f0A6F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A6F->then_instructions;

         ir_expression *const r0A70 = add(r0A4F, body.constant(64u));
         body.emit(assign(r0A4F, rshift(r0A70, body.constant(int(7))), 0x01));

         ir_expression *const r0A71 = bit_xor(r0A52, body.constant(int(64)));
         ir_expression *const r0A72 = equal(r0A71, body.constant(int(0)));
         ir_expression *const r0A73 = expr(ir_unop_b2i, r0A72);
         ir_expression *const r0A74 = expr(ir_unop_i2u, r0A73);
         ir_expression *const r0A75 = expr(ir_unop_bit_not, r0A74);
         body.emit(assign(r0A4F, bit_and(r0A4F, r0A75), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A77 = equal(r0A4F, body.constant(0u));
         ir_if *f0A76 = new(mem_ctx) ir_if(operand(r0A77).val);
         exec_list *const f0A76_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A76->then_instructions;

            body.emit(assign(r0A4E, body.constant(int(0)), 0x01));


         body.instructions = f0A76_parent_instructions;
         body.emit(f0A76);

         /* END IF */

         ir_expression *const r0A78 = lshift(r0A34, body.constant(int(31)));
         ir_expression *const r0A79 = expr(ir_unop_i2u, r0A4E);
         ir_expression *const r0A7A = lshift(r0A79, body.constant(int(23)));
         ir_expression *const r0A7B = add(r0A78, r0A7A);
         ir_expression *const r0A7C = add(r0A7B, r0A4F);
         body.emit(assign(r0A51, expr(ir_unop_bitcast_u2f, r0A7C), 0x01));

         body.emit(assign(r0A50, body.constant(false), 0x01));


      body.instructions = f0A6F_parent_instructions;
      body.emit(f0A6F);

      /* END IF */

      body.emit(assign(r0A2D, r0A51, 0x01));


   body.instructions = f0A35_parent_instructions;
   body.emit(f0A35);

   /* END IF */

   body.emit(ret(r0A2D));

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

   ir_variable *const r0A7D = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0A7D);
   ir_variable *const r0A7E = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A7E, body.constant(true), 0x01));

   ir_variable *const r0A7F = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A80 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A80);
   ir_variable *const r0A81 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0A81);
   ir_variable *const r0A82 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0A82);
   ir_variable *const r0A83 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0A83, expr(ir_unop_bitcast_f2u, r0A7D), 0x01));

   ir_variable *const r0A84 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0A84, bit_and(r0A83, body.constant(8388607u)), 0x01));

   body.emit(assign(r0A82, r0A84, 0x01));

   ir_variable *const r0A85 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A86 = rshift(r0A83, body.constant(int(23)));
   ir_expression *const r0A87 = bit_and(r0A86, body.constant(255u));
   body.emit(assign(r0A85, expr(ir_unop_u2i, r0A87), 0x01));

   body.emit(assign(r0A81, r0A85, 0x01));

   body.emit(assign(r0A80, rshift(r0A83, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A89 = equal(r0A85, body.constant(int(255)));
   ir_if *f0A88 = new(mem_ctx) ir_if(operand(r0A89).val);
   exec_list *const f0A88_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A88->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A8B = nequal(r0A84, body.constant(0u));
      ir_if *f0A8A = new(mem_ctx) ir_if(operand(r0A8B).val);
      exec_list *const f0A8A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A8A->then_instructions;

         ir_variable *const r0A8C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0A8C, lshift(r0A83, body.constant(int(9))), 0x01));

         ir_variable *const r0A8D = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0A8E = lshift(r0A8C, body.constant(int(20)));
         body.emit(assign(r0A8D, bit_or(r0A8E, body.constant(0u)), 0x01));

         ir_expression *const r0A8F = rshift(r0A8C, body.constant(int(12)));
         ir_expression *const r0A90 = lshift(r0A80, body.constant(int(31)));
         ir_expression *const r0A91 = bit_or(r0A90, body.constant(2146959360u));
         body.emit(assign(r0A8D, bit_or(r0A8F, r0A91), 0x02));

         body.emit(assign(r0A7F, r0A8D, 0x03));

         body.emit(assign(r0A7E, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A8A->else_instructions;

         ir_variable *const r0A92 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0A92);
         ir_expression *const r0A93 = lshift(r0A80, body.constant(int(31)));
         body.emit(assign(r0A92, add(r0A93, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0A92, body.constant(0u), 0x01));

         body.emit(assign(r0A7F, r0A92, 0x03));

         body.emit(assign(r0A7E, body.constant(false), 0x01));


      body.instructions = f0A8A_parent_instructions;
      body.emit(f0A8A);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A88->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A95 = equal(r0A85, body.constant(int(0)));
      ir_if *f0A94 = new(mem_ctx) ir_if(operand(r0A95).val);
      exec_list *const f0A94_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A94->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A97 = equal(r0A84, body.constant(0u));
         ir_if *f0A96 = new(mem_ctx) ir_if(operand(r0A97).val);
         exec_list *const f0A96_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A96->then_instructions;

            ir_variable *const r0A98 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0A98);
            body.emit(assign(r0A98, lshift(r0A80, body.constant(int(31))), 0x02));

            body.emit(assign(r0A98, body.constant(0u), 0x01));

            body.emit(assign(r0A7F, r0A98, 0x03));

            body.emit(assign(r0A7E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A96->else_instructions;

            ir_variable *const r0A99 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0A9A = equal(r0A84, body.constant(0u));
            ir_expression *const r0A9B = expr(ir_unop_find_msb, r0A84);
            ir_expression *const r0A9C = sub(body.constant(int(31)), r0A9B);
            ir_expression *const r0A9D = expr(ir_triop_csel, r0A9A, body.constant(int(32)), r0A9C);
            body.emit(assign(r0A99, add(r0A9D, body.constant(int(-8))), 0x01));

            body.emit(assign(r0A82, lshift(r0A84, r0A99), 0x01));

            body.emit(assign(r0A81, sub(body.constant(int(1)), r0A99), 0x01));

            body.emit(assign(r0A81, add(r0A81, body.constant(int(-1))), 0x01));


         body.instructions = f0A96_parent_instructions;
         body.emit(f0A96);

         /* END IF */


      body.instructions = f0A94_parent_instructions;
      body.emit(f0A94);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A9E = new(mem_ctx) ir_if(operand(r0A7E).val);
      exec_list *const f0A9E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A9E->then_instructions;

         ir_variable *const r0A9F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0A9F);
         ir_expression *const r0AA0 = lshift(r0A80, body.constant(int(31)));
         ir_expression *const r0AA1 = add(r0A81, body.constant(int(896)));
         ir_expression *const r0AA2 = expr(ir_unop_i2u, r0AA1);
         ir_expression *const r0AA3 = lshift(r0AA2, body.constant(int(20)));
         ir_expression *const r0AA4 = add(r0AA0, r0AA3);
         ir_expression *const r0AA5 = rshift(r0A82, body.constant(int(3)));
         body.emit(assign(r0A9F, add(r0AA4, r0AA5), 0x02));

         ir_expression *const r0AA6 = lshift(r0A82, body.constant(int(29)));
         body.emit(assign(r0A9F, bit_or(r0AA6, body.constant(0u)), 0x01));

         body.emit(assign(r0A7F, r0A9F, 0x03));

         body.emit(assign(r0A7E, body.constant(false), 0x01));


      body.instructions = f0A9E_parent_instructions;
      body.emit(f0A9E);

      /* END IF */


   body.instructions = f0A88_parent_instructions;
   body.emit(f0A88);

   /* END IF */

   body.emit(ret(r0A7F));

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

   ir_variable *const r0AA7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0AA7);
   ir_variable *const r0AA8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0AA8);
   ir_variable *const r0AA9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0AA9);
   ir_variable *const r0AAA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0AAA);
   ir_variable *const r0AAB = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0AAB);
   ir_variable *const r0AAC = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0AAC);
   ir_variable *const r0AAD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AAD);
   ir_variable *const r0AAE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AAE);
   ir_variable *const r0AAF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AAF);
   ir_variable *const r0AB0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0AB0);
   ir_variable *const r0AB1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0AB1);
   ir_variable *const r0AB2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0AB2, add(r0AA9, r0AAC), 0x01));

   ir_variable *const r0AB3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0AB4 = less(r0AB2, r0AA9);
   ir_expression *const r0AB5 = expr(ir_unop_b2i, r0AB4);
   body.emit(assign(r0AB3, expr(ir_unop_i2u, r0AB5), 0x01));

   ir_variable *const r0AB6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0AB6, add(r0AA8, r0AAB), 0x01));

   body.emit(assign(r0AB1, add(r0AB6, r0AB3), 0x01));

   ir_expression *const r0AB7 = add(r0AA7, r0AAA);
   ir_expression *const r0AB8 = less(r0AB1, r0AB3);
   ir_expression *const r0AB9 = expr(ir_unop_b2i, r0AB8);
   ir_expression *const r0ABA = expr(ir_unop_i2u, r0AB9);
   body.emit(assign(r0AB0, add(r0AB7, r0ABA), 0x01));

   ir_expression *const r0ABB = less(r0AB6, r0AA8);
   ir_expression *const r0ABC = expr(ir_unop_b2i, r0ABB);
   ir_expression *const r0ABD = expr(ir_unop_i2u, r0ABC);
   body.emit(assign(r0AB0, add(r0AB0, r0ABD), 0x01));

   body.emit(assign(r0AAF, r0AB2, 0x01));

   body.emit(assign(r0AAE, r0AB1, 0x01));

   body.emit(assign(r0AAD, r0AB0, 0x01));

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

   ir_variable *const r0ABE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0ABE);
   ir_variable *const r0ABF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0ABF);
   ir_variable *const r0AC0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0AC0);
   ir_variable *const r0AC1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0AC1);
   ir_variable *const r0AC2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0AC2);
   ir_variable *const r0AC3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0AC3);
   ir_variable *const r0AC4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AC4);
   ir_variable *const r0AC5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AC5);
   ir_variable *const r0AC6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AC6);
   ir_variable *const r0AC7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0AC7);
   ir_variable *const r0AC8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0AC9 = less(r0AC0, r0AC3);
   ir_expression *const r0ACA = expr(ir_unop_b2i, r0AC9);
   body.emit(assign(r0AC8, expr(ir_unop_i2u, r0ACA), 0x01));

   ir_variable *const r0ACB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0ACB, sub(r0ABF, r0AC2), 0x01));

   ir_expression *const r0ACC = sub(r0ABE, r0AC1);
   ir_expression *const r0ACD = less(r0ACB, r0AC8);
   ir_expression *const r0ACE = expr(ir_unop_b2i, r0ACD);
   ir_expression *const r0ACF = expr(ir_unop_i2u, r0ACE);
   body.emit(assign(r0AC7, sub(r0ACC, r0ACF), 0x01));

   ir_expression *const r0AD0 = less(r0ABF, r0AC2);
   ir_expression *const r0AD1 = expr(ir_unop_b2i, r0AD0);
   ir_expression *const r0AD2 = expr(ir_unop_i2u, r0AD1);
   body.emit(assign(r0AC7, sub(r0AC7, r0AD2), 0x01));

   body.emit(assign(r0AC6, sub(r0AC0, r0AC3), 0x01));

   body.emit(assign(r0AC5, sub(r0ACB, r0AC8), 0x01));

   body.emit(assign(r0AC4, r0AC7, 0x01));

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

   ir_variable *const r0AD3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0AD3);
   ir_variable *const r0AD4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0AD4);
   ir_variable *const r0AD5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0AD5);
   ir_variable *const r0AD6 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0AD7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0AD7);
   ir_variable *const r0AD8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0AD8);
   ir_variable *const r0AD9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0AD9);
   ir_variable *const r0ADA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0ADA);
   body.emit(assign(r0AD9, body.constant(0u), 0x01));

   body.emit(assign(r0AD8, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0ADC = gequal(r0AD3, r0AD5);
   ir_if *f0ADB = new(mem_ctx) ir_if(operand(r0ADC).val);
   exec_list *const f0ADB_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0ADB->then_instructions;

      body.emit(assign(r0AD6, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0ADB->else_instructions;

      body.emit(assign(r0ADA, rshift(r0AD5, body.constant(int(16))), 0x01));

      ir_variable *const r0ADD = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0ADF = lshift(r0ADA, body.constant(int(16)));
      ir_expression *const r0AE0 = gequal(r0AD3, r0ADF);
      ir_if *f0ADE = new(mem_ctx) ir_if(operand(r0AE0).val);
      exec_list *const f0ADE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0ADE->then_instructions;

         body.emit(assign(r0ADD, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0ADE->else_instructions;

         ir_expression *const r0AE1 = expr(ir_binop_div, r0AD3, r0ADA);
         body.emit(assign(r0ADD, lshift(r0AE1, body.constant(int(16))), 0x01));


      body.instructions = f0ADE_parent_instructions;
      body.emit(f0ADE);

      /* END IF */

      body.emit(assign(r0AD7, r0ADD, 0x01));

      ir_variable *const r0AE2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0AE2);
      ir_variable *const r0AE3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0AE3);
      ir_variable *const r0AE4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0AE4);
      ir_variable *const r0AE5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AE5, bit_and(r0AD5, body.constant(65535u)), 0x01));

      ir_variable *const r0AE6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AE6, rshift(r0AD5, body.constant(int(16))), 0x01));

      ir_variable *const r0AE7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AE7, bit_and(r0ADD, body.constant(65535u)), 0x01));

      ir_variable *const r0AE8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AE8, rshift(r0ADD, body.constant(int(16))), 0x01));

      ir_variable *const r0AE9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AE9, mul(r0AE6, r0AE7), 0x01));

      ir_expression *const r0AEA = mul(r0AE5, r0AE8);
      body.emit(assign(r0AE3, add(r0AEA, r0AE9), 0x01));

      ir_expression *const r0AEB = mul(r0AE6, r0AE8);
      ir_expression *const r0AEC = less(r0AE3, r0AE9);
      ir_expression *const r0AED = expr(ir_unop_b2i, r0AEC);
      ir_expression *const r0AEE = expr(ir_unop_i2u, r0AED);
      ir_expression *const r0AEF = lshift(r0AEE, body.constant(int(16)));
      ir_expression *const r0AF0 = rshift(r0AE3, body.constant(int(16)));
      ir_expression *const r0AF1 = add(r0AEF, r0AF0);
      body.emit(assign(r0AE2, add(r0AEB, r0AF1), 0x01));

      body.emit(assign(r0AE3, lshift(r0AE3, body.constant(int(16))), 0x01));

      ir_expression *const r0AF2 = mul(r0AE5, r0AE7);
      body.emit(assign(r0AE4, add(r0AF2, r0AE3), 0x01));

      ir_expression *const r0AF3 = less(r0AE4, r0AE3);
      ir_expression *const r0AF4 = expr(ir_unop_b2i, r0AF3);
      ir_expression *const r0AF5 = expr(ir_unop_i2u, r0AF4);
      body.emit(assign(r0AE2, add(r0AE2, r0AF5), 0x01));

      ir_expression *const r0AF6 = sub(r0AD3, r0AE2);
      ir_expression *const r0AF7 = less(r0AD4, r0AE4);
      ir_expression *const r0AF8 = expr(ir_unop_b2i, r0AF7);
      ir_expression *const r0AF9 = expr(ir_unop_i2u, r0AF8);
      body.emit(assign(r0AD9, sub(r0AF6, r0AF9), 0x01));

      body.emit(assign(r0AD8, sub(r0AD4, r0AE4), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0AFA = new(mem_ctx) ir_loop();
      exec_list *const f0AFA_parent_instructions = body.instructions;

         body.instructions = &f0AFA->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0AFC = expr(ir_unop_u2i, r0AD9);
         ir_expression *const r0AFD = gequal(r0AFC, body.constant(int(0)));
         ir_if *f0AFB = new(mem_ctx) ir_if(operand(r0AFD).val);
         exec_list *const f0AFB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AFB->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0AFB_parent_instructions;
         body.emit(f0AFB);

         /* END IF */

         body.emit(assign(r0AD7, add(r0AD7, body.constant(4294901760u)), 0x01));

         ir_variable *const r0AFE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0AFF = lshift(r0AD5, body.constant(int(16)));
         body.emit(assign(r0AFE, add(r0AD8, r0AFF), 0x01));

         ir_expression *const r0B00 = add(r0AD9, r0ADA);
         ir_expression *const r0B01 = less(r0AFE, r0AD8);
         ir_expression *const r0B02 = expr(ir_unop_b2i, r0B01);
         ir_expression *const r0B03 = expr(ir_unop_i2u, r0B02);
         body.emit(assign(r0AD9, add(r0B00, r0B03), 0x01));

         body.emit(assign(r0AD8, r0AFE, 0x01));

      /* LOOP END */

      body.instructions = f0AFA_parent_instructions;
      body.emit(f0AFA);

      ir_expression *const r0B04 = lshift(r0AD9, body.constant(int(16)));
      ir_expression *const r0B05 = rshift(r0AD8, body.constant(int(16)));
      body.emit(assign(r0AD9, bit_or(r0B04, r0B05), 0x01));

      ir_variable *const r0B06 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0B08 = lshift(r0ADA, body.constant(int(16)));
      ir_expression *const r0B09 = gequal(r0AD9, r0B08);
      ir_if *f0B07 = new(mem_ctx) ir_if(operand(r0B09).val);
      exec_list *const f0B07_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B07->then_instructions;

         body.emit(assign(r0B06, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B07->else_instructions;

         body.emit(assign(r0B06, expr(ir_binop_div, r0AD9, r0ADA), 0x01));


      body.instructions = f0B07_parent_instructions;
      body.emit(f0B07);

      /* END IF */

      body.emit(assign(r0AD7, bit_or(r0AD7, r0B06), 0x01));

      body.emit(assign(r0AD6, r0AD7, 0x01));


   body.instructions = f0ADB_parent_instructions;
   body.emit(f0ADB);

   /* END IF */

   body.emit(ret(r0AD6));

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

   ir_variable *const r0B0A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B0A);
   ir_variable *const r0B0B = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0B0B, r0B0A, 0x03));

   ir_variable *const r0B0C = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B0D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0B0D);
   body.emit(assign(r0B0D, body.constant(0u), 0x01));

   ir_variable *const r0B0E = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B0E, bit_and(swizzle_y(r0B0A), body.constant(1048575u)), 0x01));

   ir_variable *const r0B0F = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B10 = rshift(swizzle_y(r0B0A), body.constant(int(20)));
   ir_expression *const r0B11 = bit_and(r0B10, body.constant(2047u));
   body.emit(assign(r0B0F, expr(ir_unop_u2i, r0B11), 0x01));

   ir_variable *const r0B12 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B12, rshift(swizzle_y(r0B0A), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B14 = equal(r0B0F, body.constant(int(2047)));
   ir_if *f0B13 = new(mem_ctx) ir_if(operand(r0B14).val);
   exec_list *const f0B13_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B13->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B16 = bit_or(r0B0E, swizzle_x(r0B0A));
      ir_expression *const r0B17 = nequal(r0B16, body.constant(0u));
      ir_if *f0B15 = new(mem_ctx) ir_if(operand(r0B17).val);
      exec_list *const f0B15_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B15->then_instructions;

         ir_expression *const r0B18 = lshift(swizzle_y(r0B0A), body.constant(int(12)));
         ir_expression *const r0B19 = rshift(swizzle_x(r0B0A), body.constant(int(20)));
         body.emit(assign(r0B0B, bit_or(r0B18, r0B19), 0x02));

         body.emit(assign(r0B0B, lshift(swizzle_x(r0B0A), body.constant(int(12))), 0x01));

         ir_expression *const r0B1A = lshift(r0B12, body.constant(int(31)));
         ir_expression *const r0B1B = bit_or(r0B1A, body.constant(2143289344u));
         ir_expression *const r0B1C = rshift(swizzle_y(r0B0B), body.constant(int(9)));
         ir_expression *const r0B1D = bit_or(r0B1B, r0B1C);
         body.emit(assign(r0B0C, expr(ir_unop_bitcast_u2f, r0B1D), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B15->else_instructions;

         ir_expression *const r0B1E = lshift(r0B12, body.constant(int(31)));
         ir_expression *const r0B1F = add(r0B1E, body.constant(2139095040u));
         body.emit(assign(r0B0C, expr(ir_unop_bitcast_u2f, r0B1F), 0x01));


      body.instructions = f0B15_parent_instructions;
      body.emit(f0B15);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B13->else_instructions;

      ir_variable *const r0B20 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B20);
      ir_variable *const r0B21 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0B21, rshift(r0B0E, body.constant(int(22))), 0x01));

      ir_expression *const r0B22 = lshift(r0B0E, body.constant(int(10)));
      ir_expression *const r0B23 = rshift(swizzle_x(r0B0A), body.constant(int(22)));
      ir_expression *const r0B24 = bit_or(r0B22, r0B23);
      ir_expression *const r0B25 = lshift(swizzle_x(r0B0A), body.constant(int(10)));
      ir_expression *const r0B26 = nequal(r0B25, body.constant(0u));
      ir_expression *const r0B27 = expr(ir_unop_b2i, r0B26);
      ir_expression *const r0B28 = expr(ir_unop_i2u, r0B27);
      body.emit(assign(r0B20, bit_or(r0B24, r0B28), 0x01));

      body.emit(assign(r0B0D, r0B20, 0x01));

      /* IF CONDITION */
      ir_expression *const r0B2A = nequal(r0B0F, body.constant(int(0)));
      ir_if *f0B29 = new(mem_ctx) ir_if(operand(r0B2A).val);
      exec_list *const f0B29_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B29->then_instructions;

         body.emit(assign(r0B0D, bit_or(r0B20, body.constant(1073741824u)), 0x01));


      body.instructions = f0B29_parent_instructions;
      body.emit(f0B29);

      /* END IF */

      ir_variable *const r0B2B = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B2B, add(r0B0F, body.constant(int(-897))), 0x01));

      ir_variable *const r0B2C = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B2C, r0B0D, 0x01));

      ir_variable *const r0B2D = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B2D, body.constant(true), 0x01));

      ir_variable *const r0B2E = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B2F = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B2F);
      ir_expression *const r0B30 = bit_and(r0B0D, body.constant(127u));
      body.emit(assign(r0B2F, expr(ir_unop_u2i, r0B30), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B32 = expr(ir_unop_i2u, r0B2B);
      ir_expression *const r0B33 = gequal(r0B32, body.constant(253u));
      ir_if *f0B31 = new(mem_ctx) ir_if(operand(r0B33).val);
      exec_list *const f0B31_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B31->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B35 = less(body.constant(int(253)), r0B2B);
         ir_expression *const r0B36 = equal(r0B2B, body.constant(int(253)));
         ir_expression *const r0B37 = expr(ir_unop_u2i, r0B0D);
         ir_expression *const r0B38 = less(r0B37, body.constant(int(-64)));
         ir_expression *const r0B39 = logic_and(r0B36, r0B38);
         ir_expression *const r0B3A = logic_or(r0B35, r0B39);
         ir_if *f0B34 = new(mem_ctx) ir_if(operand(r0B3A).val);
         exec_list *const f0B34_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B34->then_instructions;

            ir_expression *const r0B3B = lshift(r0B12, body.constant(int(31)));
            ir_expression *const r0B3C = add(r0B3B, body.constant(2139095040u));
            body.emit(assign(r0B2E, expr(ir_unop_bitcast_u2f, r0B3C), 0x01));

            body.emit(assign(r0B2D, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B34->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0B3E = less(r0B2B, body.constant(int(0)));
            ir_if *f0B3D = new(mem_ctx) ir_if(operand(r0B3E).val);
            exec_list *const f0B3D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B3D->then_instructions;

               ir_variable *const r0B3F = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0B3F, neg(r0B2B), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B41 = less(r0B3F, body.constant(int(32)));
               ir_if *f0B40 = new(mem_ctx) ir_if(operand(r0B41).val);
               exec_list *const f0B40_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B40->then_instructions;

                  ir_expression *const r0B42 = rshift(r0B0D, r0B3F);
                  ir_expression *const r0B43 = neg(r0B3F);
                  ir_expression *const r0B44 = bit_and(r0B43, body.constant(int(31)));
                  ir_expression *const r0B45 = lshift(r0B0D, r0B44);
                  ir_expression *const r0B46 = nequal(r0B45, body.constant(0u));
                  ir_expression *const r0B47 = expr(ir_unop_b2i, r0B46);
                  ir_expression *const r0B48 = expr(ir_unop_i2u, r0B47);
                  body.emit(assign(r0B2C, bit_or(r0B42, r0B48), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0B40->else_instructions;

                  ir_expression *const r0B49 = nequal(r0B2C, body.constant(0u));
                  ir_expression *const r0B4A = expr(ir_unop_b2i, r0B49);
                  body.emit(assign(r0B2C, expr(ir_unop_i2u, r0B4A), 0x01));


               body.instructions = f0B40_parent_instructions;
               body.emit(f0B40);

               /* END IF */

               body.emit(assign(r0B2B, body.constant(int(0)), 0x01));

               ir_expression *const r0B4B = expr(ir_unop_u2i, r0B2C);
               body.emit(assign(r0B2F, bit_and(r0B4B, body.constant(int(127))), 0x01));


            body.instructions = f0B3D_parent_instructions;
            body.emit(f0B3D);

            /* END IF */


         body.instructions = f0B34_parent_instructions;
         body.emit(f0B34);

         /* END IF */


      body.instructions = f0B31_parent_instructions;
      body.emit(f0B31);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B4C = new(mem_ctx) ir_if(operand(r0B2D).val);
      exec_list *const f0B4C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B4C->then_instructions;

         ir_expression *const r0B4D = add(r0B2C, body.constant(64u));
         body.emit(assign(r0B2C, rshift(r0B4D, body.constant(int(7))), 0x01));

         ir_expression *const r0B4E = bit_xor(r0B2F, body.constant(int(64)));
         ir_expression *const r0B4F = equal(r0B4E, body.constant(int(0)));
         ir_expression *const r0B50 = expr(ir_unop_b2i, r0B4F);
         ir_expression *const r0B51 = expr(ir_unop_i2u, r0B50);
         ir_expression *const r0B52 = expr(ir_unop_bit_not, r0B51);
         body.emit(assign(r0B2C, bit_and(r0B2C, r0B52), 0x01));

         /* IF CONDITION */
         ir_expression *const r0B54 = equal(r0B2C, body.constant(0u));
         ir_if *f0B53 = new(mem_ctx) ir_if(operand(r0B54).val);
         exec_list *const f0B53_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B53->then_instructions;

            body.emit(assign(r0B2B, body.constant(int(0)), 0x01));


         body.instructions = f0B53_parent_instructions;
         body.emit(f0B53);

         /* END IF */

         ir_expression *const r0B55 = lshift(r0B12, body.constant(int(31)));
         ir_expression *const r0B56 = expr(ir_unop_i2u, r0B2B);
         ir_expression *const r0B57 = lshift(r0B56, body.constant(int(23)));
         ir_expression *const r0B58 = add(r0B55, r0B57);
         ir_expression *const r0B59 = add(r0B58, r0B2C);
         body.emit(assign(r0B2E, expr(ir_unop_bitcast_u2f, r0B59), 0x01));

         body.emit(assign(r0B2D, body.constant(false), 0x01));


      body.instructions = f0B4C_parent_instructions;
      body.emit(f0B4C);

      /* END IF */

      body.emit(assign(r0B0C, r0B2E, 0x01));


   body.instructions = f0B13_parent_instructions;
   body.emit(f0B13);

   /* END IF */

   ir_variable *const r0B5A = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B5A, body.constant(true), 0x01));

   ir_variable *const r0B5B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B5C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B5C);
   ir_variable *const r0B5D = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B5D);
   ir_variable *const r0B5E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B5E);
   ir_variable *const r0B5F = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0B60 = expr(ir_unop_sqrt, r0B0C);
   body.emit(assign(r0B5F, expr(ir_unop_bitcast_f2u, r0B60), 0x01));

   ir_variable *const r0B61 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B61, bit_and(r0B5F, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B5E, r0B61, 0x01));

   ir_variable *const r0B62 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B63 = rshift(r0B5F, body.constant(int(23)));
   ir_expression *const r0B64 = bit_and(r0B63, body.constant(255u));
   body.emit(assign(r0B62, expr(ir_unop_u2i, r0B64), 0x01));

   body.emit(assign(r0B5D, r0B62, 0x01));

   body.emit(assign(r0B5C, rshift(r0B5F, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B66 = equal(r0B62, body.constant(int(255)));
   ir_if *f0B65 = new(mem_ctx) ir_if(operand(r0B66).val);
   exec_list *const f0B65_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B65->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B68 = nequal(r0B61, body.constant(0u));
      ir_if *f0B67 = new(mem_ctx) ir_if(operand(r0B68).val);
      exec_list *const f0B67_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B67->then_instructions;

         ir_variable *const r0B69 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B69, lshift(r0B5F, body.constant(int(9))), 0x01));

         ir_variable *const r0B6A = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B6B = lshift(r0B69, body.constant(int(20)));
         body.emit(assign(r0B6A, bit_or(r0B6B, body.constant(0u)), 0x01));

         ir_expression *const r0B6C = rshift(r0B69, body.constant(int(12)));
         ir_expression *const r0B6D = lshift(r0B5C, body.constant(int(31)));
         ir_expression *const r0B6E = bit_or(r0B6D, body.constant(2146959360u));
         body.emit(assign(r0B6A, bit_or(r0B6C, r0B6E), 0x02));

         body.emit(assign(r0B5B, r0B6A, 0x03));

         body.emit(assign(r0B5A, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B67->else_instructions;

         ir_variable *const r0B6F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B6F);
         ir_expression *const r0B70 = lshift(r0B5C, body.constant(int(31)));
         body.emit(assign(r0B6F, add(r0B70, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B6F, body.constant(0u), 0x01));

         body.emit(assign(r0B5B, r0B6F, 0x03));

         body.emit(assign(r0B5A, body.constant(false), 0x01));


      body.instructions = f0B67_parent_instructions;
      body.emit(f0B67);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B65->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B72 = equal(r0B62, body.constant(int(0)));
      ir_if *f0B71 = new(mem_ctx) ir_if(operand(r0B72).val);
      exec_list *const f0B71_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B71->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B74 = equal(r0B61, body.constant(0u));
         ir_if *f0B73 = new(mem_ctx) ir_if(operand(r0B74).val);
         exec_list *const f0B73_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B73->then_instructions;

            ir_variable *const r0B75 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B75);
            body.emit(assign(r0B75, lshift(r0B5C, body.constant(int(31))), 0x02));

            body.emit(assign(r0B75, body.constant(0u), 0x01));

            body.emit(assign(r0B5B, r0B75, 0x03));

            body.emit(assign(r0B5A, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B73->else_instructions;

            ir_variable *const r0B76 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0B77 = equal(r0B61, body.constant(0u));
            ir_expression *const r0B78 = expr(ir_unop_find_msb, r0B61);
            ir_expression *const r0B79 = sub(body.constant(int(31)), r0B78);
            ir_expression *const r0B7A = expr(ir_triop_csel, r0B77, body.constant(int(32)), r0B79);
            body.emit(assign(r0B76, add(r0B7A, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B5E, lshift(r0B61, r0B76), 0x01));

            body.emit(assign(r0B5D, sub(body.constant(int(1)), r0B76), 0x01));

            body.emit(assign(r0B5D, add(r0B5D, body.constant(int(-1))), 0x01));


         body.instructions = f0B73_parent_instructions;
         body.emit(f0B73);

         /* END IF */


      body.instructions = f0B71_parent_instructions;
      body.emit(f0B71);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B7B = new(mem_ctx) ir_if(operand(r0B5A).val);
      exec_list *const f0B7B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B7B->then_instructions;

         ir_variable *const r0B7C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B7C);
         ir_expression *const r0B7D = lshift(r0B5C, body.constant(int(31)));
         ir_expression *const r0B7E = add(r0B5D, body.constant(int(896)));
         ir_expression *const r0B7F = expr(ir_unop_i2u, r0B7E);
         ir_expression *const r0B80 = lshift(r0B7F, body.constant(int(20)));
         ir_expression *const r0B81 = add(r0B7D, r0B80);
         ir_expression *const r0B82 = rshift(r0B5E, body.constant(int(3)));
         body.emit(assign(r0B7C, add(r0B81, r0B82), 0x02));

         ir_expression *const r0B83 = lshift(r0B5E, body.constant(int(29)));
         body.emit(assign(r0B7C, bit_or(r0B83, body.constant(0u)), 0x01));

         body.emit(assign(r0B5B, r0B7C, 0x03));

         body.emit(assign(r0B5A, body.constant(false), 0x01));


      body.instructions = f0B7B_parent_instructions;
      body.emit(f0B7B);

      /* END IF */


   body.instructions = f0B65_parent_instructions;
   body.emit(f0B65);

   /* END IF */

   body.emit(ret(r0B5B));

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

   ir_variable *const r0B84 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B84);
   ir_variable *const r0B85 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B86 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B87 = rshift(swizzle_y(r0B84), body.constant(int(20)));
   ir_expression *const r0B88 = bit_and(r0B87, body.constant(2047u));
   ir_expression *const r0B89 = expr(ir_unop_u2i, r0B88);
   body.emit(assign(r0B86, add(r0B89, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B8B = less(r0B86, body.constant(int(0)));
   ir_if *f0B8A = new(mem_ctx) ir_if(operand(r0B8B).val);
   exec_list *const f0B8A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B8A->then_instructions;

      body.emit(assign(r0B85, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B8A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B8D = less(body.constant(int(52)), r0B86);
      ir_if *f0B8C = new(mem_ctx) ir_if(operand(r0B8D).val);
      exec_list *const f0B8C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B8C->then_instructions;

         body.emit(assign(r0B85, r0B84, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B8C->else_instructions;

         ir_variable *const r0B8E = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0B8E, sub(body.constant(int(52)), r0B86), 0x01));

         ir_variable *const r0B8F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0B91 = gequal(r0B8E, body.constant(int(32)));
         ir_if *f0B90 = new(mem_ctx) ir_if(operand(r0B91).val);
         exec_list *const f0B90_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B90->then_instructions;

            body.emit(assign(r0B8F, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B90->else_instructions;

            body.emit(assign(r0B8F, lshift(body.constant(4294967295u), r0B8E), 0x01));


         body.instructions = f0B90_parent_instructions;
         body.emit(f0B90);

         /* END IF */

         ir_variable *const r0B92 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0B94 = less(r0B8E, body.constant(int(33)));
         ir_if *f0B93 = new(mem_ctx) ir_if(operand(r0B94).val);
         exec_list *const f0B93_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B93->then_instructions;

            body.emit(assign(r0B92, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B93->else_instructions;

            ir_expression *const r0B95 = add(r0B8E, body.constant(int(-32)));
            body.emit(assign(r0B92, lshift(body.constant(4294967295u), r0B95), 0x01));


         body.instructions = f0B93_parent_instructions;
         body.emit(f0B93);

         /* END IF */

         ir_variable *const r0B96 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0B96, bit_and(r0B8F, swizzle_x(r0B84)), 0x01));

         body.emit(assign(r0B96, bit_and(r0B92, swizzle_y(r0B84)), 0x02));

         body.emit(assign(r0B85, r0B96, 0x03));


      body.instructions = f0B8C_parent_instructions;
      body.emit(f0B8C);

      /* END IF */


   body.instructions = f0B8A_parent_instructions;
   body.emit(f0B8A);

   /* END IF */

   body.emit(ret(r0B85));

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

   ir_variable *const r0B97 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B97);
   ir_variable *const r0B98 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B98, body.constant(true), 0x01));

   ir_variable *const r0B99 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B9A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0B9A);
   ir_variable *const r0B9B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0B9B);
   ir_variable *const r0B9C = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B9D = rshift(swizzle_y(r0B97), body.constant(int(20)));
   ir_expression *const r0B9E = bit_and(r0B9D, body.constant(2047u));
   ir_expression *const r0B9F = expr(ir_unop_u2i, r0B9E);
   body.emit(assign(r0B9C, add(r0B9F, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0B9B, swizzle_y(r0B97), 0x01));

   body.emit(assign(r0B9A, swizzle_x(r0B97), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BA1 = less(r0B9C, body.constant(int(20)));
   ir_if *f0BA0 = new(mem_ctx) ir_if(operand(r0BA1).val);
   exec_list *const f0BA0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BA0->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0BA3 = less(r0B9C, body.constant(int(0)));
      ir_if *f0BA2 = new(mem_ctx) ir_if(operand(r0BA3).val);
      exec_list *const f0BA2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BA2->then_instructions;

         body.emit(assign(r0B9B, bit_and(swizzle_y(r0B97), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BA5 = equal(r0B9C, body.constant(int(-1)));
         ir_expression *const r0BA6 = nequal(swizzle_x(r0B97), body.constant(0u));
         ir_expression *const r0BA7 = logic_and(r0BA5, r0BA6);
         ir_if *f0BA4 = new(mem_ctx) ir_if(operand(r0BA7).val);
         exec_list *const f0BA4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BA4->then_instructions;

            body.emit(assign(r0B9B, bit_or(r0B9B, body.constant(1072693248u)), 0x01));


         body.instructions = f0BA4_parent_instructions;
         body.emit(f0BA4);

         /* END IF */

         body.emit(assign(r0B9A, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BA2->else_instructions;

         ir_variable *const r0BA8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0BA8, rshift(body.constant(1048575u), r0B9C), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BAA = bit_and(r0B9B, r0BA8);
         ir_expression *const r0BAB = equal(r0BAA, body.constant(0u));
         ir_expression *const r0BAC = equal(r0B9A, body.constant(0u));
         ir_expression *const r0BAD = logic_and(r0BAB, r0BAC);
         ir_if *f0BA9 = new(mem_ctx) ir_if(operand(r0BAD).val);
         exec_list *const f0BA9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BA9->then_instructions;

            body.emit(assign(r0B99, r0B97, 0x03));

            body.emit(assign(r0B98, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BA9->else_instructions;

            ir_expression *const r0BAE = rshift(body.constant(524288u), r0B9C);
            body.emit(assign(r0B9B, add(r0B9B, r0BAE), 0x01));

            ir_expression *const r0BAF = expr(ir_unop_bit_not, r0BA8);
            body.emit(assign(r0B9B, bit_and(r0B9B, r0BAF), 0x01));

            body.emit(assign(r0B9A, body.constant(0u), 0x01));


         body.instructions = f0BA9_parent_instructions;
         body.emit(f0BA9);

         /* END IF */


      body.instructions = f0BA2_parent_instructions;
      body.emit(f0BA2);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BA0->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0BB1 = less(body.constant(int(51)), r0B9C);
      ir_expression *const r0BB2 = equal(r0B9C, body.constant(int(1024)));
      ir_expression *const r0BB3 = logic_or(r0BB1, r0BB2);
      ir_if *f0BB0 = new(mem_ctx) ir_if(operand(r0BB3).val);
      exec_list *const f0BB0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BB0->then_instructions;

         body.emit(assign(r0B99, r0B97, 0x03));

         body.emit(assign(r0B98, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BB0->else_instructions;

         ir_variable *const r0BB4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0BB5 = add(r0B9C, body.constant(int(-20)));
         body.emit(assign(r0BB4, rshift(body.constant(4294967295u), r0BB5), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BB7 = bit_and(r0B9A, r0BB4);
         ir_expression *const r0BB8 = equal(r0BB7, body.constant(0u));
         ir_if *f0BB6 = new(mem_ctx) ir_if(operand(r0BB8).val);
         exec_list *const f0BB6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BB6->then_instructions;

            body.emit(assign(r0B99, r0B97, 0x03));

            body.emit(assign(r0B98, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BB6->else_instructions;

            ir_variable *const r0BB9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0BBA = sub(body.constant(int(51)), r0B9C);
            ir_expression *const r0BBB = lshift(body.constant(1u), r0BBA);
            body.emit(assign(r0BB9, add(r0B9A, r0BBB), 0x01));

            /* IF CONDITION */
            ir_expression *const r0BBD = less(r0BB9, r0B9A);
            ir_if *f0BBC = new(mem_ctx) ir_if(operand(r0BBD).val);
            exec_list *const f0BBC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0BBC->then_instructions;

               body.emit(assign(r0B9B, add(r0B9B, body.constant(1u)), 0x01));


            body.instructions = f0BBC_parent_instructions;
            body.emit(f0BBC);

            /* END IF */

            ir_expression *const r0BBE = expr(ir_unop_bit_not, r0BB4);
            body.emit(assign(r0B9A, bit_and(r0BB9, r0BBE), 0x01));


         body.instructions = f0BB6_parent_instructions;
         body.emit(f0BB6);

         /* END IF */


      body.instructions = f0BB0_parent_instructions;
      body.emit(f0BB0);

      /* END IF */


   body.instructions = f0BA0_parent_instructions;
   body.emit(f0BA0);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0BBF = new(mem_ctx) ir_if(operand(r0B98).val);
   exec_list *const f0BBF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BBF->then_instructions;

      body.emit(assign(r0B97, r0B9A, 0x01));

      body.emit(assign(r0B97, r0B9B, 0x02));

      body.emit(assign(r0B99, r0B97, 0x03));

      body.emit(assign(r0B98, body.constant(false), 0x01));


   body.instructions = f0BBF_parent_instructions;
   body.emit(f0BBF);

   /* END IF */

   body.emit(ret(r0B99));

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

   ir_variable *const r0BC0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BC0);
   ir_variable *const r0BC1 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0BC1, r0BC0, 0x03));

   ir_variable *const r0BC2 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0BC3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0BC3);
   body.emit(assign(r0BC3, body.constant(0u), 0x01));

   ir_variable *const r0BC4 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0BC4, bit_and(swizzle_y(r0BC0), body.constant(1048575u)), 0x01));

   ir_variable *const r0BC5 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0BC6 = rshift(swizzle_y(r0BC0), body.constant(int(20)));
   ir_expression *const r0BC7 = bit_and(r0BC6, body.constant(2047u));
   body.emit(assign(r0BC5, expr(ir_unop_u2i, r0BC7), 0x01));

   ir_variable *const r0BC8 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0BC8, rshift(swizzle_y(r0BC0), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BCA = equal(r0BC5, body.constant(int(2047)));
   ir_if *f0BC9 = new(mem_ctx) ir_if(operand(r0BCA).val);
   exec_list *const f0BC9_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BC9->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0BCC = bit_or(r0BC4, swizzle_x(r0BC0));
      ir_expression *const r0BCD = nequal(r0BCC, body.constant(0u));
      ir_if *f0BCB = new(mem_ctx) ir_if(operand(r0BCD).val);
      exec_list *const f0BCB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BCB->then_instructions;

         ir_expression *const r0BCE = lshift(swizzle_y(r0BC0), body.constant(int(12)));
         ir_expression *const r0BCF = rshift(swizzle_x(r0BC0), body.constant(int(20)));
         body.emit(assign(r0BC1, bit_or(r0BCE, r0BCF), 0x02));

         body.emit(assign(r0BC1, lshift(swizzle_x(r0BC0), body.constant(int(12))), 0x01));

         ir_expression *const r0BD0 = lshift(r0BC8, body.constant(int(31)));
         ir_expression *const r0BD1 = bit_or(r0BD0, body.constant(2143289344u));
         ir_expression *const r0BD2 = rshift(swizzle_y(r0BC1), body.constant(int(9)));
         ir_expression *const r0BD3 = bit_or(r0BD1, r0BD2);
         body.emit(assign(r0BC2, expr(ir_unop_bitcast_u2f, r0BD3), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BCB->else_instructions;

         ir_expression *const r0BD4 = lshift(r0BC8, body.constant(int(31)));
         ir_expression *const r0BD5 = add(r0BD4, body.constant(2139095040u));
         body.emit(assign(r0BC2, expr(ir_unop_bitcast_u2f, r0BD5), 0x01));


      body.instructions = f0BCB_parent_instructions;
      body.emit(f0BCB);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BC9->else_instructions;

      ir_variable *const r0BD6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BD6);
      ir_variable *const r0BD7 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0BD7, rshift(r0BC4, body.constant(int(22))), 0x01));

      ir_expression *const r0BD8 = lshift(r0BC4, body.constant(int(10)));
      ir_expression *const r0BD9 = rshift(swizzle_x(r0BC0), body.constant(int(22)));
      ir_expression *const r0BDA = bit_or(r0BD8, r0BD9);
      ir_expression *const r0BDB = lshift(swizzle_x(r0BC0), body.constant(int(10)));
      ir_expression *const r0BDC = nequal(r0BDB, body.constant(0u));
      ir_expression *const r0BDD = expr(ir_unop_b2i, r0BDC);
      ir_expression *const r0BDE = expr(ir_unop_i2u, r0BDD);
      body.emit(assign(r0BD6, bit_or(r0BDA, r0BDE), 0x01));

      body.emit(assign(r0BC3, r0BD6, 0x01));

      /* IF CONDITION */
      ir_expression *const r0BE0 = nequal(r0BC5, body.constant(int(0)));
      ir_if *f0BDF = new(mem_ctx) ir_if(operand(r0BE0).val);
      exec_list *const f0BDF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BDF->then_instructions;

         body.emit(assign(r0BC3, bit_or(r0BD6, body.constant(1073741824u)), 0x01));


      body.instructions = f0BDF_parent_instructions;
      body.emit(f0BDF);

      /* END IF */

      ir_variable *const r0BE1 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0BE1, add(r0BC5, body.constant(int(-897))), 0x01));

      ir_variable *const r0BE2 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0BE2, r0BC3, 0x01));

      ir_variable *const r0BE3 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0BE3, body.constant(true), 0x01));

      ir_variable *const r0BE4 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0BE5 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0BE5);
      ir_expression *const r0BE6 = bit_and(r0BC3, body.constant(127u));
      body.emit(assign(r0BE5, expr(ir_unop_u2i, r0BE6), 0x01));

      /* IF CONDITION */
      ir_expression *const r0BE8 = expr(ir_unop_i2u, r0BE1);
      ir_expression *const r0BE9 = gequal(r0BE8, body.constant(253u));
      ir_if *f0BE7 = new(mem_ctx) ir_if(operand(r0BE9).val);
      exec_list *const f0BE7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BE7->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0BEB = less(body.constant(int(253)), r0BE1);
         ir_expression *const r0BEC = equal(r0BE1, body.constant(int(253)));
         ir_expression *const r0BED = expr(ir_unop_u2i, r0BC3);
         ir_expression *const r0BEE = less(r0BED, body.constant(int(-64)));
         ir_expression *const r0BEF = logic_and(r0BEC, r0BEE);
         ir_expression *const r0BF0 = logic_or(r0BEB, r0BEF);
         ir_if *f0BEA = new(mem_ctx) ir_if(operand(r0BF0).val);
         exec_list *const f0BEA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BEA->then_instructions;

            ir_expression *const r0BF1 = lshift(r0BC8, body.constant(int(31)));
            ir_expression *const r0BF2 = add(r0BF1, body.constant(2139095040u));
            body.emit(assign(r0BE4, expr(ir_unop_bitcast_u2f, r0BF2), 0x01));

            body.emit(assign(r0BE3, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BEA->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0BF4 = less(r0BE1, body.constant(int(0)));
            ir_if *f0BF3 = new(mem_ctx) ir_if(operand(r0BF4).val);
            exec_list *const f0BF3_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0BF3->then_instructions;

               ir_variable *const r0BF5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0BF5, neg(r0BE1), 0x01));

               /* IF CONDITION */
               ir_expression *const r0BF7 = less(r0BF5, body.constant(int(32)));
               ir_if *f0BF6 = new(mem_ctx) ir_if(operand(r0BF7).val);
               exec_list *const f0BF6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BF6->then_instructions;

                  ir_expression *const r0BF8 = rshift(r0BC3, r0BF5);
                  ir_expression *const r0BF9 = neg(r0BF5);
                  ir_expression *const r0BFA = bit_and(r0BF9, body.constant(int(31)));
                  ir_expression *const r0BFB = lshift(r0BC3, r0BFA);
                  ir_expression *const r0BFC = nequal(r0BFB, body.constant(0u));
                  ir_expression *const r0BFD = expr(ir_unop_b2i, r0BFC);
                  ir_expression *const r0BFE = expr(ir_unop_i2u, r0BFD);
                  body.emit(assign(r0BE2, bit_or(r0BF8, r0BFE), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0BF6->else_instructions;

                  ir_expression *const r0BFF = nequal(r0BE2, body.constant(0u));
                  ir_expression *const r0C00 = expr(ir_unop_b2i, r0BFF);
                  body.emit(assign(r0BE2, expr(ir_unop_i2u, r0C00), 0x01));


               body.instructions = f0BF6_parent_instructions;
               body.emit(f0BF6);

               /* END IF */

               body.emit(assign(r0BE1, body.constant(int(0)), 0x01));

               ir_expression *const r0C01 = expr(ir_unop_u2i, r0BE2);
               body.emit(assign(r0BE5, bit_and(r0C01, body.constant(int(127))), 0x01));


            body.instructions = f0BF3_parent_instructions;
            body.emit(f0BF3);

            /* END IF */


         body.instructions = f0BEA_parent_instructions;
         body.emit(f0BEA);

         /* END IF */


      body.instructions = f0BE7_parent_instructions;
      body.emit(f0BE7);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C02 = new(mem_ctx) ir_if(operand(r0BE3).val);
      exec_list *const f0C02_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C02->then_instructions;

         ir_expression *const r0C03 = add(r0BE2, body.constant(64u));
         body.emit(assign(r0BE2, rshift(r0C03, body.constant(int(7))), 0x01));

         ir_expression *const r0C04 = bit_xor(r0BE5, body.constant(int(64)));
         ir_expression *const r0C05 = equal(r0C04, body.constant(int(0)));
         ir_expression *const r0C06 = expr(ir_unop_b2i, r0C05);
         ir_expression *const r0C07 = expr(ir_unop_i2u, r0C06);
         ir_expression *const r0C08 = expr(ir_unop_bit_not, r0C07);
         body.emit(assign(r0BE2, bit_and(r0BE2, r0C08), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C0A = equal(r0BE2, body.constant(0u));
         ir_if *f0C09 = new(mem_ctx) ir_if(operand(r0C0A).val);
         exec_list *const f0C09_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C09->then_instructions;

            body.emit(assign(r0BE1, body.constant(int(0)), 0x01));


         body.instructions = f0C09_parent_instructions;
         body.emit(f0C09);

         /* END IF */

         ir_expression *const r0C0B = lshift(r0BC8, body.constant(int(31)));
         ir_expression *const r0C0C = expr(ir_unop_i2u, r0BE1);
         ir_expression *const r0C0D = lshift(r0C0C, body.constant(int(23)));
         ir_expression *const r0C0E = add(r0C0B, r0C0D);
         ir_expression *const r0C0F = add(r0C0E, r0BE2);
         body.emit(assign(r0BE4, expr(ir_unop_bitcast_u2f, r0C0F), 0x01));

         body.emit(assign(r0BE3, body.constant(false), 0x01));


      body.instructions = f0C02_parent_instructions;
      body.emit(f0C02);

      /* END IF */

      body.emit(assign(r0BC2, r0BE4, 0x01));


   body.instructions = f0BC9_parent_instructions;
   body.emit(f0BC9);

   /* END IF */

   ir_variable *const r0C10 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C10, body.constant(true), 0x01));

   ir_variable *const r0C11 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C12 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C12);
   ir_variable *const r0C13 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C13);
   ir_variable *const r0C14 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C14);
   ir_variable *const r0C15 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C16 = expr(ir_unop_rcp, r0BC2);
   body.emit(assign(r0C15, expr(ir_unop_bitcast_f2u, r0C16), 0x01));

   ir_variable *const r0C17 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C17, bit_and(r0C15, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C14, r0C17, 0x01));

   ir_variable *const r0C18 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C19 = rshift(r0C15, body.constant(int(23)));
   ir_expression *const r0C1A = bit_and(r0C19, body.constant(255u));
   body.emit(assign(r0C18, expr(ir_unop_u2i, r0C1A), 0x01));

   body.emit(assign(r0C13, r0C18, 0x01));

   body.emit(assign(r0C12, rshift(r0C15, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C1C = equal(r0C18, body.constant(int(255)));
   ir_if *f0C1B = new(mem_ctx) ir_if(operand(r0C1C).val);
   exec_list *const f0C1B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C1B->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C1E = nequal(r0C17, body.constant(0u));
      ir_if *f0C1D = new(mem_ctx) ir_if(operand(r0C1E).val);
      exec_list *const f0C1D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C1D->then_instructions;

         ir_variable *const r0C1F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C1F, lshift(r0C15, body.constant(int(9))), 0x01));

         ir_variable *const r0C20 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C21 = lshift(r0C1F, body.constant(int(20)));
         body.emit(assign(r0C20, bit_or(r0C21, body.constant(0u)), 0x01));

         ir_expression *const r0C22 = rshift(r0C1F, body.constant(int(12)));
         ir_expression *const r0C23 = lshift(r0C12, body.constant(int(31)));
         ir_expression *const r0C24 = bit_or(r0C23, body.constant(2146959360u));
         body.emit(assign(r0C20, bit_or(r0C22, r0C24), 0x02));

         body.emit(assign(r0C11, r0C20, 0x03));

         body.emit(assign(r0C10, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C1D->else_instructions;

         ir_variable *const r0C25 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C25);
         ir_expression *const r0C26 = lshift(r0C12, body.constant(int(31)));
         body.emit(assign(r0C25, add(r0C26, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C25, body.constant(0u), 0x01));

         body.emit(assign(r0C11, r0C25, 0x03));

         body.emit(assign(r0C10, body.constant(false), 0x01));


      body.instructions = f0C1D_parent_instructions;
      body.emit(f0C1D);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C1B->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C28 = equal(r0C18, body.constant(int(0)));
      ir_if *f0C27 = new(mem_ctx) ir_if(operand(r0C28).val);
      exec_list *const f0C27_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C27->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C2A = equal(r0C17, body.constant(0u));
         ir_if *f0C29 = new(mem_ctx) ir_if(operand(r0C2A).val);
         exec_list *const f0C29_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C29->then_instructions;

            ir_variable *const r0C2B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C2B);
            body.emit(assign(r0C2B, lshift(r0C12, body.constant(int(31))), 0x02));

            body.emit(assign(r0C2B, body.constant(0u), 0x01));

            body.emit(assign(r0C11, r0C2B, 0x03));

            body.emit(assign(r0C10, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C29->else_instructions;

            ir_variable *const r0C2C = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0C2D = equal(r0C17, body.constant(0u));
            ir_expression *const r0C2E = expr(ir_unop_find_msb, r0C17);
            ir_expression *const r0C2F = sub(body.constant(int(31)), r0C2E);
            ir_expression *const r0C30 = expr(ir_triop_csel, r0C2D, body.constant(int(32)), r0C2F);
            body.emit(assign(r0C2C, add(r0C30, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C14, lshift(r0C17, r0C2C), 0x01));

            body.emit(assign(r0C13, sub(body.constant(int(1)), r0C2C), 0x01));

            body.emit(assign(r0C13, add(r0C13, body.constant(int(-1))), 0x01));


         body.instructions = f0C29_parent_instructions;
         body.emit(f0C29);

         /* END IF */


      body.instructions = f0C27_parent_instructions;
      body.emit(f0C27);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C31 = new(mem_ctx) ir_if(operand(r0C10).val);
      exec_list *const f0C31_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C31->then_instructions;

         ir_variable *const r0C32 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C32);
         ir_expression *const r0C33 = lshift(r0C12, body.constant(int(31)));
         ir_expression *const r0C34 = add(r0C13, body.constant(int(896)));
         ir_expression *const r0C35 = expr(ir_unop_i2u, r0C34);
         ir_expression *const r0C36 = lshift(r0C35, body.constant(int(20)));
         ir_expression *const r0C37 = add(r0C33, r0C36);
         ir_expression *const r0C38 = rshift(r0C14, body.constant(int(3)));
         body.emit(assign(r0C32, add(r0C37, r0C38), 0x02));

         ir_expression *const r0C39 = lshift(r0C14, body.constant(int(29)));
         body.emit(assign(r0C32, bit_or(r0C39, body.constant(0u)), 0x01));

         body.emit(assign(r0C11, r0C32, 0x03));

         body.emit(assign(r0C10, body.constant(false), 0x01));


      body.instructions = f0C31_parent_instructions;
      body.emit(f0C31);

      /* END IF */


   body.instructions = f0C1B_parent_instructions;
   body.emit(f0C1B);

   /* END IF */

   body.emit(ret(r0C11));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
