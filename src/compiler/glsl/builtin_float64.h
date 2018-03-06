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
   ir_variable *const r01CF = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
   body.emit(r01CF);
   ir_variable *const r01D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r01D0);
   ir_variable *const r01D1 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r01D1);
   ir_variable *const r01D2 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r01D2);
   ir_variable *const r01D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r01D3);
   ir_variable *const r01D4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r01D4);
   ir_variable *const r01D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r01D5);
   ir_variable *const r01D6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r01D6);
   ir_variable *const r01D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r01D7);
   ir_variable *const r01D8 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01D8, rshift(swizzle_y(r01CB), body.constant(int(31))), 0x01));

   body.emit(assign(r01D7, r01D8, 0x01));

   ir_variable *const r01D9 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01D9, rshift(swizzle_y(r01CC), body.constant(int(31))), 0x01));

   ir_variable *const r01DA = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r01DA, swizzle_x(r01CB), 0x01));

   body.emit(assign(r01D6, r01DA, 0x01));

   ir_variable *const r01DB = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r01DB, bit_and(swizzle_y(r01CB), body.constant(1048575u)), 0x01));

   body.emit(assign(r01D5, r01DB, 0x01));

   ir_variable *const r01DC = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r01DC, swizzle_x(r01CC), 0x01));

   body.emit(assign(r01D4, r01DC, 0x01));

   ir_variable *const r01DD = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r01DD, bit_and(swizzle_y(r01CC), body.constant(1048575u)), 0x01));

   body.emit(assign(r01D3, r01DD, 0x01));

   ir_variable *const r01DE = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r01DF = rshift(swizzle_y(r01CB), body.constant(int(20)));
   ir_expression *const r01E0 = bit_and(r01DF, body.constant(2047u));
   body.emit(assign(r01DE, expr(ir_unop_u2i, r01E0), 0x01));

   body.emit(assign(r01D2, r01DE, 0x01));

   ir_variable *const r01E1 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r01E2 = rshift(swizzle_y(r01CC), body.constant(int(20)));
   ir_expression *const r01E3 = bit_and(r01E2, body.constant(2047u));
   body.emit(assign(r01E1, expr(ir_unop_u2i, r01E3), 0x01));

   body.emit(assign(r01D1, r01E1, 0x01));

   body.emit(assign(r01D0, body.constant(0u), 0x01));

   ir_variable *const r01E4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r01E4, sub(r01DE, r01E1), 0x01));

   body.emit(assign(r01CF, r01E4, 0x01));

   /* IF CONDITION */
   ir_expression *const r01E6 = equal(r01D8, r01D9);
   ir_if *f01E5 = new(mem_ctx) ir_if(operand(r01E6).val);
   exec_list *const f01E5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01E5->then_instructions;

      ir_variable *const r01E7 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r01E7);
      ir_variable *const r01E8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r01E8);
      body.emit(assign(r01E8, body.constant(0u), 0x01));

      /* IF CONDITION */
      ir_expression *const r01EA = less(body.constant(int(0)), r01E4);
      ir_if *f01E9 = new(mem_ctx) ir_if(operand(r01EA).val);
      exec_list *const f01E9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01E9->then_instructions;

         /* IF CONDITION */
         ir_expression *const r01EC = equal(r01DE, body.constant(int(2047)));
         ir_if *f01EB = new(mem_ctx) ir_if(operand(r01EC).val);
         exec_list *const f01EB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01EB->then_instructions;

            ir_variable *const r01ED = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r01ED, swizzle_x(r01CB), 0x01));

            ir_variable *const r01EE = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r01EE, swizzle_x(r01CC), 0x01));

            body.emit(assign(r01ED, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

            body.emit(assign(r01EE, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

            ir_expression *const r01EF = bit_or(r01DB, swizzle_x(r01CB));
            ir_expression *const r01F0 = nequal(r01EF, body.constant(0u));
            ir_swizzle *const r01F1 = swizzle(r01F0, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r01F2 = lshift(swizzle_y(r01CB), body.constant(int(1)));
            ir_expression *const r01F3 = gequal(r01F2, body.constant(4292870144u));
            ir_expression *const r01F4 = nequal(swizzle_x(r01CB), body.constant(0u));
            ir_expression *const r01F5 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
            ir_expression *const r01F6 = nequal(r01F5, body.constant(0u));
            ir_expression *const r01F7 = logic_or(r01F4, r01F6);
            ir_expression *const r01F8 = logic_and(r01F3, r01F7);
            ir_swizzle *const r01F9 = swizzle(r01F8, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r01FA = lshift(swizzle_y(r01CC), body.constant(int(1)));
            ir_expression *const r01FB = gequal(r01FA, body.constant(4292870144u));
            ir_expression *const r01FC = nequal(swizzle_x(r01CC), body.constant(0u));
            ir_expression *const r01FD = bit_and(swizzle_y(r01CC), body.constant(1048575u));
            ir_expression *const r01FE = nequal(r01FD, body.constant(0u));
            ir_expression *const r01FF = logic_or(r01FC, r01FE);
            ir_expression *const r0200 = logic_and(r01FB, r01FF);
            ir_swizzle *const r0201 = swizzle(r0200, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0202 = expr(ir_triop_csel, r0201, r01EE, r01ED);
            ir_expression *const r0203 = expr(ir_triop_csel, r01F9, r0202, r01EE);
            body.emit(assign(r01CE, expr(ir_triop_csel, r01F1, r0203, r01CB), 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f01EB->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0205 = equal(r01E1, body.constant(int(0)));
            ir_if *f0204 = new(mem_ctx) ir_if(operand(r0205).val);
            exec_list *const f0204_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0204->then_instructions;

               body.emit(assign(r01CF, add(r01E4, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0204->else_instructions;

               body.emit(assign(r01D3, bit_or(r01DD, body.constant(1048576u)), 0x01));


            body.instructions = f0204_parent_instructions;
            body.emit(f0204);

            /* END IF */

            ir_variable *const r0206 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0206, body.constant(0u), 0x01));

            ir_variable *const r0207 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0207);
            ir_variable *const r0208 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0208);
            ir_variable *const r0209 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0209);
            ir_variable *const r020A = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r020B = neg(r01CF);
            body.emit(assign(r020A, bit_and(r020B, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r020D = equal(r01CF, body.constant(int(0)));
            ir_if *f020C = new(mem_ctx) ir_if(operand(r020D).val);
            exec_list *const f020C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f020C->then_instructions;

               body.emit(assign(r0207, r0206, 0x01));

               body.emit(assign(r0208, r01DC, 0x01));

               body.emit(assign(r0209, r01D3, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f020C->else_instructions;

               /* IF CONDITION */
               ir_expression *const r020F = less(r01CF, body.constant(int(32)));
               ir_if *f020E = new(mem_ctx) ir_if(operand(r020F).val);
               exec_list *const f020E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f020E->then_instructions;

                  body.emit(assign(r0207, lshift(swizzle_x(r01CC), r020A), 0x01));

                  ir_expression *const r0210 = lshift(r01D3, r020A);
                  ir_expression *const r0211 = rshift(swizzle_x(r01CC), r01CF);
                  body.emit(assign(r0208, bit_or(r0210, r0211), 0x01));

                  body.emit(assign(r0209, rshift(r01D3, r01CF), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f020E->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0213 = equal(r01CF, body.constant(int(32)));
                  ir_if *f0212 = new(mem_ctx) ir_if(operand(r0213).val);
                  exec_list *const f0212_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0212->then_instructions;

                     body.emit(assign(r0207, r01DC, 0x01));

                     body.emit(assign(r0208, r01D3, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0212->else_instructions;

                     body.emit(assign(r0206, bit_or(body.constant(0u), swizzle_x(r01CC)), 0x01));

                     ir_expression *const r0214 = less(r01CF, body.constant(int(64)));
                     ir_expression *const r0215 = lshift(r01D3, r020A);
                     ir_expression *const r0216 = equal(r01CF, body.constant(int(64)));
                     ir_expression *const r0217 = nequal(r01D3, body.constant(0u));
                     ir_expression *const r0218 = expr(ir_unop_b2i, r0217);
                     ir_expression *const r0219 = expr(ir_unop_i2u, r0218);
                     ir_expression *const r021A = expr(ir_triop_csel, r0216, r01D3, r0219);
                     body.emit(assign(r0207, expr(ir_triop_csel, r0214, r0215, r021A), 0x01));

                     ir_expression *const r021B = less(r01CF, body.constant(int(64)));
                     ir_expression *const r021C = bit_and(r01CF, body.constant(int(31)));
                     ir_expression *const r021D = rshift(r01D3, r021C);
                     body.emit(assign(r0208, expr(ir_triop_csel, r021B, r021D, body.constant(0u)), 0x01));


                  body.instructions = f0212_parent_instructions;
                  body.emit(f0212);

                  /* END IF */

                  body.emit(assign(r0209, body.constant(0u), 0x01));


               body.instructions = f020E_parent_instructions;
               body.emit(f020E);

               /* END IF */

               ir_expression *const r021E = nequal(r0206, body.constant(0u));
               ir_expression *const r021F = expr(ir_unop_b2i, r021E);
               ir_expression *const r0220 = expr(ir_unop_i2u, r021F);
               body.emit(assign(r0207, bit_or(r0207, r0220), 0x01));


            body.instructions = f020C_parent_instructions;
            body.emit(f020C);

            /* END IF */

            body.emit(assign(r01D3, r0209, 0x01));

            body.emit(assign(r01D4, r0208, 0x01));

            body.emit(assign(r01E8, r0207, 0x01));

            body.emit(assign(r01E7, r01DE, 0x01));


         body.instructions = f01EB_parent_instructions;
         body.emit(f01EB);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01E9->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0222 = less(r01CF, body.constant(int(0)));
         ir_if *f0221 = new(mem_ctx) ir_if(operand(r0222).val);
         exec_list *const f0221_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0221->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0224 = equal(r01E1, body.constant(int(2047)));
            ir_if *f0223 = new(mem_ctx) ir_if(operand(r0224).val);
            exec_list *const f0223_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0223->then_instructions;

               ir_variable *const r0225 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0225);
               ir_expression *const r0226 = lshift(r01D8, body.constant(int(31)));
               body.emit(assign(r0225, add(r0226, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0225, body.constant(0u), 0x01));

               ir_variable *const r0227 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0227, swizzle_x(r01CB), 0x01));

               ir_variable *const r0228 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0228, swizzle_x(r01CC), 0x01));

               body.emit(assign(r0227, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r0228, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r0229 = bit_or(r01D3, r01D4);
               ir_expression *const r022A = nequal(r0229, body.constant(0u));
               ir_swizzle *const r022B = swizzle(r022A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r022C = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r022D = gequal(r022C, body.constant(4292870144u));
               ir_expression *const r022E = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r022F = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r0230 = nequal(r022F, body.constant(0u));
               ir_expression *const r0231 = logic_or(r022E, r0230);
               ir_expression *const r0232 = logic_and(r022D, r0231);
               ir_swizzle *const r0233 = swizzle(r0232, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0234 = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r0235 = gequal(r0234, body.constant(4292870144u));
               ir_expression *const r0236 = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r0237 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r0238 = nequal(r0237, body.constant(0u));
               ir_expression *const r0239 = logic_or(r0236, r0238);
               ir_expression *const r023A = logic_and(r0235, r0239);
               ir_swizzle *const r023B = swizzle(r023A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r023C = expr(ir_triop_csel, r023B, r0228, r0227);
               ir_expression *const r023D = expr(ir_triop_csel, r0233, r023C, r0228);
               body.emit(assign(r01CE, expr(ir_triop_csel, r022B, r023D, r0225), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0223->else_instructions;

               /* IF CONDITION */
               ir_expression *const r023F = equal(r01DE, body.constant(int(0)));
               ir_if *f023E = new(mem_ctx) ir_if(operand(r023F).val);
               exec_list *const f023E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f023E->then_instructions;

                  body.emit(assign(r01CF, add(r01CF, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f023E->else_instructions;

                  body.emit(assign(r01D5, bit_or(r01DB, body.constant(1048576u)), 0x01));


               body.instructions = f023E_parent_instructions;
               body.emit(f023E);

               /* END IF */

               ir_variable *const r0240 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0240, body.constant(0u), 0x01));

               ir_variable *const r0241 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0241, neg(r01CF), 0x01));

               ir_variable *const r0242 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0242);
               ir_variable *const r0243 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0243);
               ir_variable *const r0244 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0244);
               ir_variable *const r0245 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0246 = neg(r0241);
               body.emit(assign(r0245, bit_and(r0246, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0248 = equal(r0241, body.constant(int(0)));
               ir_if *f0247 = new(mem_ctx) ir_if(operand(r0248).val);
               exec_list *const f0247_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0247->then_instructions;

                  body.emit(assign(r0242, r0240, 0x01));

                  body.emit(assign(r0243, r01DA, 0x01));

                  body.emit(assign(r0244, r01D5, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0247->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r024A = less(r0241, body.constant(int(32)));
                  ir_if *f0249 = new(mem_ctx) ir_if(operand(r024A).val);
                  exec_list *const f0249_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0249->then_instructions;

                     body.emit(assign(r0242, lshift(swizzle_x(r01CB), r0245), 0x01));

                     ir_expression *const r024B = lshift(r01D5, r0245);
                     ir_expression *const r024C = rshift(swizzle_x(r01CB), r0241);
                     body.emit(assign(r0243, bit_or(r024B, r024C), 0x01));

                     body.emit(assign(r0244, rshift(r01D5, r0241), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0249->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r024E = equal(r0241, body.constant(int(32)));
                     ir_if *f024D = new(mem_ctx) ir_if(operand(r024E).val);
                     exec_list *const f024D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f024D->then_instructions;

                        body.emit(assign(r0242, r01DA, 0x01));

                        body.emit(assign(r0243, r01D5, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f024D->else_instructions;

                        body.emit(assign(r0240, bit_or(body.constant(0u), swizzle_x(r01CB)), 0x01));

                        ir_expression *const r024F = less(r0241, body.constant(int(64)));
                        ir_expression *const r0250 = lshift(r01D5, r0245);
                        ir_expression *const r0251 = equal(r0241, body.constant(int(64)));
                        ir_expression *const r0252 = nequal(r01D5, body.constant(0u));
                        ir_expression *const r0253 = expr(ir_unop_b2i, r0252);
                        ir_expression *const r0254 = expr(ir_unop_i2u, r0253);
                        ir_expression *const r0255 = expr(ir_triop_csel, r0251, r01D5, r0254);
                        body.emit(assign(r0242, expr(ir_triop_csel, r024F, r0250, r0255), 0x01));

                        ir_expression *const r0256 = less(r0241, body.constant(int(64)));
                        ir_expression *const r0257 = bit_and(r0241, body.constant(int(31)));
                        ir_expression *const r0258 = rshift(r01D5, r0257);
                        body.emit(assign(r0243, expr(ir_triop_csel, r0256, r0258, body.constant(0u)), 0x01));


                     body.instructions = f024D_parent_instructions;
                     body.emit(f024D);

                     /* END IF */

                     body.emit(assign(r0244, body.constant(0u), 0x01));


                  body.instructions = f0249_parent_instructions;
                  body.emit(f0249);

                  /* END IF */

                  ir_expression *const r0259 = nequal(r0240, body.constant(0u));
                  ir_expression *const r025A = expr(ir_unop_b2i, r0259);
                  ir_expression *const r025B = expr(ir_unop_i2u, r025A);
                  body.emit(assign(r0242, bit_or(r0242, r025B), 0x01));


               body.instructions = f0247_parent_instructions;
               body.emit(f0247);

               /* END IF */

               body.emit(assign(r01D5, r0244, 0x01));

               body.emit(assign(r01D6, r0243, 0x01));

               body.emit(assign(r01E8, r0242, 0x01));

               body.emit(assign(r01E7, r01E1, 0x01));


            body.instructions = f0223_parent_instructions;
            body.emit(f0223);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0221->else_instructions;

            /* IF CONDITION */
            ir_expression *const r025D = equal(r01DE, body.constant(int(2047)));
            ir_if *f025C = new(mem_ctx) ir_if(operand(r025D).val);
            exec_list *const f025C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f025C->then_instructions;

               ir_variable *const r025E = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r025E, swizzle_x(r01CB), 0x01));

               ir_variable *const r025F = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r025F, swizzle_x(r01CC), 0x01));

               body.emit(assign(r025E, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r025F, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r0260 = bit_or(r01D5, r01D6);
               ir_expression *const r0261 = bit_or(r01D3, r01D4);
               ir_expression *const r0262 = bit_or(r0260, r0261);
               ir_expression *const r0263 = nequal(r0262, body.constant(0u));
               ir_swizzle *const r0264 = swizzle(r0263, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0265 = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r0266 = gequal(r0265, body.constant(4292870144u));
               ir_expression *const r0267 = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r0268 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r0269 = nequal(r0268, body.constant(0u));
               ir_expression *const r026A = logic_or(r0267, r0269);
               ir_expression *const r026B = logic_and(r0266, r026A);
               ir_swizzle *const r026C = swizzle(r026B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r026D = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r026E = gequal(r026D, body.constant(4292870144u));
               ir_expression *const r026F = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r0270 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r0271 = nequal(r0270, body.constant(0u));
               ir_expression *const r0272 = logic_or(r026F, r0271);
               ir_expression *const r0273 = logic_and(r026E, r0272);
               ir_swizzle *const r0274 = swizzle(r0273, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0275 = expr(ir_triop_csel, r0274, r025F, r025E);
               ir_expression *const r0276 = expr(ir_triop_csel, r026C, r0275, r025F);
               body.emit(assign(r01CE, expr(ir_triop_csel, r0264, r0276, r01CB), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f025C->else_instructions;

               ir_variable *const r0277 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0278 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0278, add(r01D6, r01D4), 0x01));

               ir_expression *const r0279 = add(r01D5, r01D3);
               ir_expression *const r027A = less(r0278, r01D6);
               ir_expression *const r027B = expr(ir_unop_b2i, r027A);
               ir_expression *const r027C = expr(ir_unop_i2u, r027B);
               body.emit(assign(r0277, add(r0279, r027C), 0x01));

               body.emit(assign(r01D0, r0277, 0x01));

               /* IF CONDITION */
               ir_expression *const r027E = equal(r01DE, body.constant(int(0)));
               ir_if *f027D = new(mem_ctx) ir_if(operand(r027E).val);
               exec_list *const f027D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f027D->then_instructions;

                  ir_variable *const r027F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r027F);
                  ir_expression *const r0280 = lshift(r01D8, body.constant(int(31)));
                  body.emit(assign(r027F, add(r0280, r0277), 0x02));

                  body.emit(assign(r027F, r0278, 0x01));

                  body.emit(assign(r01CE, r027F, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f027D->else_instructions;

                  body.emit(assign(r01D0, bit_or(r0277, body.constant(2097152u)), 0x01));

                  body.emit(assign(r01E7, r01DE, 0x01));

                  ir_variable *const r0281 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0281);
                  ir_variable *const r0282 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r0282);
                  ir_variable *const r0283 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r0283);
                  body.emit(assign(r0281, lshift(r0278, body.constant(int(31))), 0x01));

                  ir_expression *const r0284 = lshift(r01D0, body.constant(int(31)));
                  ir_expression *const r0285 = rshift(r0278, body.constant(int(1)));
                  body.emit(assign(r0282, bit_or(r0284, r0285), 0x01));

                  body.emit(assign(r0283, rshift(r01D0, body.constant(int(1))), 0x01));

                  body.emit(assign(r0281, bit_or(r0281, body.constant(0u)), 0x01));

                  body.emit(assign(r01D0, r0283, 0x01));

                  body.emit(assign(r01E8, r0281, 0x01));

                  ir_variable *const r0286 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0286, r01DE, 0x01));

                  ir_variable *const r0287 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0287, r0283, 0x01));

                  ir_variable *const r0288 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0288, r0282, 0x01));

                  ir_variable *const r0289 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0289, r0281, 0x01));

                  ir_variable *const r028A = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r028A, body.constant(true), 0x01));

                  ir_variable *const r028B = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r028C = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r028C);
                  ir_expression *const r028D = expr(ir_unop_u2i, r0281);
                  body.emit(assign(r028C, less(r028D, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r028F = gequal(r01DE, body.constant(int(2045)));
                  ir_if *f028E = new(mem_ctx) ir_if(operand(r028F).val);
                  exec_list *const f028E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f028E->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0291 = less(body.constant(int(2045)), r01DE);
                     ir_expression *const r0292 = equal(r01DE, body.constant(int(2045)));
                     ir_expression *const r0293 = equal(body.constant(2097151u), r0283);
                     ir_expression *const r0294 = equal(body.constant(4294967295u), r0282);
                     ir_expression *const r0295 = logic_and(r0293, r0294);
                     ir_expression *const r0296 = logic_and(r0292, r0295);
                     ir_expression *const r0297 = logic_and(r0296, r028C);
                     ir_expression *const r0298 = logic_or(r0291, r0297);
                     ir_if *f0290 = new(mem_ctx) ir_if(operand(r0298).val);
                     exec_list *const f0290_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0290->then_instructions;

                        ir_variable *const r0299 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0299);
                        ir_expression *const r029A = lshift(r01D8, body.constant(int(31)));
                        body.emit(assign(r0299, add(r029A, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0299, body.constant(0u), 0x01));

                        body.emit(assign(r028B, r0299, 0x03));

                        body.emit(assign(r028A, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0290->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r029C = less(r01DE, body.constant(int(0)));
                        ir_if *f029B = new(mem_ctx) ir_if(operand(r029C).val);
                        exec_list *const f029B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f029B->then_instructions;

                           ir_variable *const r029D = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r029D, r0281, 0x01));

                           ir_variable *const r029E = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r029E, neg(r01DE), 0x01));

                           ir_variable *const r029F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r029F);
                           ir_variable *const r02A0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r02A0);
                           ir_variable *const r02A1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r02A1);
                           ir_variable *const r02A2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02A3 = neg(r029E);
                           body.emit(assign(r02A2, bit_and(r02A3, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02A5 = equal(r029E, body.constant(int(0)));
                           ir_if *f02A4 = new(mem_ctx) ir_if(operand(r02A5).val);
                           exec_list *const f02A4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02A4->then_instructions;

                              body.emit(assign(r029F, r0281, 0x01));

                              body.emit(assign(r02A0, r0282, 0x01));

                              body.emit(assign(r02A1, r0283, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02A4->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02A7 = less(r029E, body.constant(int(32)));
                              ir_if *f02A6 = new(mem_ctx) ir_if(operand(r02A7).val);
                              exec_list *const f02A6_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02A6->then_instructions;

                                 body.emit(assign(r029F, lshift(r0282, r02A2), 0x01));

                                 ir_expression *const r02A8 = lshift(r0283, r02A2);
                                 ir_expression *const r02A9 = rshift(r0282, r029E);
                                 body.emit(assign(r02A0, bit_or(r02A8, r02A9), 0x01));

                                 body.emit(assign(r02A1, rshift(r0283, r029E), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02A6->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02AB = equal(r029E, body.constant(int(32)));
                                 ir_if *f02AA = new(mem_ctx) ir_if(operand(r02AB).val);
                                 exec_list *const f02AA_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02AA->then_instructions;

                                    body.emit(assign(r029F, r0282, 0x01));

                                    body.emit(assign(r02A0, r0283, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02AA->else_instructions;

                                    body.emit(assign(r029D, bit_or(r0281, r0282), 0x01));

                                    ir_expression *const r02AC = less(r029E, body.constant(int(64)));
                                    ir_expression *const r02AD = lshift(r0283, r02A2);
                                    ir_expression *const r02AE = equal(r029E, body.constant(int(64)));
                                    ir_expression *const r02AF = nequal(r0283, body.constant(0u));
                                    ir_expression *const r02B0 = expr(ir_unop_b2i, r02AF);
                                    ir_expression *const r02B1 = expr(ir_unop_i2u, r02B0);
                                    ir_expression *const r02B2 = expr(ir_triop_csel, r02AE, r0283, r02B1);
                                    body.emit(assign(r029F, expr(ir_triop_csel, r02AC, r02AD, r02B2), 0x01));

                                    ir_expression *const r02B3 = less(r029E, body.constant(int(64)));
                                    ir_expression *const r02B4 = bit_and(r029E, body.constant(int(31)));
                                    ir_expression *const r02B5 = rshift(r0283, r02B4);
                                    body.emit(assign(r02A0, expr(ir_triop_csel, r02B3, r02B5, body.constant(0u)), 0x01));


                                 body.instructions = f02AA_parent_instructions;
                                 body.emit(f02AA);

                                 /* END IF */

                                 body.emit(assign(r02A1, body.constant(0u), 0x01));


                              body.instructions = f02A6_parent_instructions;
                              body.emit(f02A6);

                              /* END IF */

                              ir_expression *const r02B6 = nequal(r029D, body.constant(0u));
                              ir_expression *const r02B7 = expr(ir_unop_b2i, r02B6);
                              ir_expression *const r02B8 = expr(ir_unop_i2u, r02B7);
                              body.emit(assign(r029F, bit_or(r029F, r02B8), 0x01));


                           body.instructions = f02A4_parent_instructions;
                           body.emit(f02A4);

                           /* END IF */

                           body.emit(assign(r0287, r02A1, 0x01));

                           body.emit(assign(r0288, r02A0, 0x01));

                           body.emit(assign(r0289, r029F, 0x01));

                           body.emit(assign(r0286, body.constant(int(0)), 0x01));

                           body.emit(assign(r028C, less(r029F, body.constant(0u)), 0x01));


                        body.instructions = f029B_parent_instructions;
                        body.emit(f029B);

                        /* END IF */


                     body.instructions = f0290_parent_instructions;
                     body.emit(f0290);

                     /* END IF */


                  body.instructions = f028E_parent_instructions;
                  body.emit(f028E);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02B9 = new(mem_ctx) ir_if(operand(r028A).val);
                  exec_list *const f02B9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02B9->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02BA = new(mem_ctx) ir_if(operand(r028C).val);
                     exec_list *const f02BA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02BA->then_instructions;

                        ir_variable *const r02BB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02BB, add(r0288, body.constant(1u)), 0x01));

                        ir_expression *const r02BC = less(r02BB, r0288);
                        ir_expression *const r02BD = expr(ir_unop_b2i, r02BC);
                        ir_expression *const r02BE = expr(ir_unop_i2u, r02BD);
                        body.emit(assign(r0287, add(r0287, r02BE), 0x01));

                        ir_expression *const r02BF = equal(r0289, body.constant(0u));
                        ir_expression *const r02C0 = expr(ir_unop_b2i, r02BF);
                        ir_expression *const r02C1 = expr(ir_unop_i2u, r02C0);
                        ir_expression *const r02C2 = add(r0289, r02C1);
                        ir_expression *const r02C3 = bit_and(r02C2, body.constant(1u));
                        ir_expression *const r02C4 = expr(ir_unop_bit_not, r02C3);
                        body.emit(assign(r0288, bit_and(r02BB, r02C4), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02BA->else_instructions;

                        ir_expression *const r02C5 = bit_or(r0287, r0288);
                        ir_expression *const r02C6 = equal(r02C5, body.constant(0u));
                        body.emit(assign(r0286, expr(ir_triop_csel, r02C6, body.constant(int(0)), r0286), 0x01));


                     body.instructions = f02BA_parent_instructions;
                     body.emit(f02BA);

                     /* END IF */

                     ir_variable *const r02C7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r02C7);
                     ir_expression *const r02C8 = lshift(r01D8, body.constant(int(31)));
                     ir_expression *const r02C9 = expr(ir_unop_i2u, r0286);
                     ir_expression *const r02CA = lshift(r02C9, body.constant(int(20)));
                     ir_expression *const r02CB = add(r02C8, r02CA);
                     body.emit(assign(r02C7, add(r02CB, r0287), 0x02));

                     body.emit(assign(r02C7, r0288, 0x01));

                     body.emit(assign(r028B, r02C7, 0x03));

                     body.emit(assign(r028A, body.constant(false), 0x01));


                  body.instructions = f02B9_parent_instructions;
                  body.emit(f02B9);

                  /* END IF */

                  body.emit(assign(r01CE, r028B, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


               body.instructions = f027D_parent_instructions;
               body.emit(f027D);

               /* END IF */


            body.instructions = f025C_parent_instructions;
            body.emit(f025C);

            /* END IF */


         body.instructions = f0221_parent_instructions;
         body.emit(f0221);

         /* END IF */


      body.instructions = f01E9_parent_instructions;
      body.emit(f01E9);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02CC = new(mem_ctx) ir_if(operand(r01CD).val);
      exec_list *const f02CC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02CC->then_instructions;

         body.emit(assign(r01D5, bit_or(r01D5, body.constant(1048576u)), 0x01));

         ir_variable *const r02CD = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r02CE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r02CE, add(r01D6, r01D4), 0x01));

         ir_expression *const r02CF = add(r01D5, r01D3);
         ir_expression *const r02D0 = less(r02CE, r01D6);
         ir_expression *const r02D1 = expr(ir_unop_b2i, r02D0);
         ir_expression *const r02D2 = expr(ir_unop_i2u, r02D1);
         body.emit(assign(r02CD, add(r02CF, r02D2), 0x01));

         body.emit(assign(r01D0, r02CD, 0x01));

         body.emit(assign(r01E7, add(r01E7, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r02D4 = less(r02CD, body.constant(2097152u));
         ir_if *f02D3 = new(mem_ctx) ir_if(operand(r02D4).val);
         exec_list *const f02D3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02D3->then_instructions;

            ir_variable *const r02D5 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r02D5, r01E7, 0x01));

            ir_variable *const r02D6 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r02D6, r02CD, 0x01));

            ir_variable *const r02D7 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r02D7, r02CE, 0x01));

            ir_variable *const r02D8 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r02D8, r01E8, 0x01));

            ir_variable *const r02D9 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r02D9, body.constant(true), 0x01));

            ir_variable *const r02DA = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r02DB = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r02DB);
            ir_expression *const r02DC = expr(ir_unop_u2i, r01E8);
            body.emit(assign(r02DB, less(r02DC, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02DE = gequal(r01E7, body.constant(int(2045)));
            ir_if *f02DD = new(mem_ctx) ir_if(operand(r02DE).val);
            exec_list *const f02DD_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02DD->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02E0 = less(body.constant(int(2045)), r01E7);
               ir_expression *const r02E1 = equal(r01E7, body.constant(int(2045)));
               ir_expression *const r02E2 = equal(body.constant(2097151u), r02CD);
               ir_expression *const r02E3 = equal(body.constant(4294967295u), r02CE);
               ir_expression *const r02E4 = logic_and(r02E2, r02E3);
               ir_expression *const r02E5 = logic_and(r02E1, r02E4);
               ir_expression *const r02E6 = logic_and(r02E5, r02DB);
               ir_expression *const r02E7 = logic_or(r02E0, r02E6);
               ir_if *f02DF = new(mem_ctx) ir_if(operand(r02E7).val);
               exec_list *const f02DF_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02DF->then_instructions;

                  ir_variable *const r02E8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02E8);
                  ir_expression *const r02E9 = lshift(r01D8, body.constant(int(31)));
                  body.emit(assign(r02E8, add(r02E9, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r02E8, body.constant(0u), 0x01));

                  body.emit(assign(r02DA, r02E8, 0x03));

                  body.emit(assign(r02D9, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02DF->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r02EB = less(r01E7, body.constant(int(0)));
                  ir_if *f02EA = new(mem_ctx) ir_if(operand(r02EB).val);
                  exec_list *const f02EA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02EA->then_instructions;

                     ir_variable *const r02EC = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r02EC, r01E8, 0x01));

                     ir_variable *const r02ED = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r02ED, neg(r01E7), 0x01));

                     ir_variable *const r02EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r02EE);
                     ir_variable *const r02EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r02EF);
                     ir_variable *const r02F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r02F0);
                     ir_variable *const r02F1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r02F2 = neg(r02ED);
                     body.emit(assign(r02F1, bit_and(r02F2, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r02F4 = equal(r02ED, body.constant(int(0)));
                     ir_if *f02F3 = new(mem_ctx) ir_if(operand(r02F4).val);
                     exec_list *const f02F3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02F3->then_instructions;

                        body.emit(assign(r02EE, r01E8, 0x01));

                        body.emit(assign(r02EF, r02CE, 0x01));

                        body.emit(assign(r02F0, r02CD, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02F3->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02F6 = less(r02ED, body.constant(int(32)));
                        ir_if *f02F5 = new(mem_ctx) ir_if(operand(r02F6).val);
                        exec_list *const f02F5_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02F5->then_instructions;

                           body.emit(assign(r02EE, lshift(r02CE, r02F1), 0x01));

                           ir_expression *const r02F7 = lshift(r02CD, r02F1);
                           ir_expression *const r02F8 = rshift(r02CE, r02ED);
                           body.emit(assign(r02EF, bit_or(r02F7, r02F8), 0x01));

                           body.emit(assign(r02F0, rshift(r02CD, r02ED), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f02F5->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r02FA = equal(r02ED, body.constant(int(32)));
                           ir_if *f02F9 = new(mem_ctx) ir_if(operand(r02FA).val);
                           exec_list *const f02F9_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02F9->then_instructions;

                              body.emit(assign(r02EE, r02CE, 0x01));

                              body.emit(assign(r02EF, r02CD, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02F9->else_instructions;

                              body.emit(assign(r02EC, bit_or(r01E8, r02CE), 0x01));

                              ir_expression *const r02FB = less(r02ED, body.constant(int(64)));
                              ir_expression *const r02FC = lshift(r02CD, r02F1);
                              ir_expression *const r02FD = equal(r02ED, body.constant(int(64)));
                              ir_expression *const r02FE = nequal(r02CD, body.constant(0u));
                              ir_expression *const r02FF = expr(ir_unop_b2i, r02FE);
                              ir_expression *const r0300 = expr(ir_unop_i2u, r02FF);
                              ir_expression *const r0301 = expr(ir_triop_csel, r02FD, r02CD, r0300);
                              body.emit(assign(r02EE, expr(ir_triop_csel, r02FB, r02FC, r0301), 0x01));

                              ir_expression *const r0302 = less(r02ED, body.constant(int(64)));
                              ir_expression *const r0303 = bit_and(r02ED, body.constant(int(31)));
                              ir_expression *const r0304 = rshift(r02CD, r0303);
                              body.emit(assign(r02EF, expr(ir_triop_csel, r0302, r0304, body.constant(0u)), 0x01));


                           body.instructions = f02F9_parent_instructions;
                           body.emit(f02F9);

                           /* END IF */

                           body.emit(assign(r02F0, body.constant(0u), 0x01));


                        body.instructions = f02F5_parent_instructions;
                        body.emit(f02F5);

                        /* END IF */

                        ir_expression *const r0305 = nequal(r02EC, body.constant(0u));
                        ir_expression *const r0306 = expr(ir_unop_b2i, r0305);
                        ir_expression *const r0307 = expr(ir_unop_i2u, r0306);
                        body.emit(assign(r02EE, bit_or(r02EE, r0307), 0x01));


                     body.instructions = f02F3_parent_instructions;
                     body.emit(f02F3);

                     /* END IF */

                     body.emit(assign(r02D6, r02F0, 0x01));

                     body.emit(assign(r02D7, r02EF, 0x01));

                     body.emit(assign(r02D8, r02EE, 0x01));

                     body.emit(assign(r02D5, body.constant(int(0)), 0x01));

                     body.emit(assign(r02DB, less(r02EE, body.constant(0u)), 0x01));


                  body.instructions = f02EA_parent_instructions;
                  body.emit(f02EA);

                  /* END IF */


               body.instructions = f02DF_parent_instructions;
               body.emit(f02DF);

               /* END IF */


            body.instructions = f02DD_parent_instructions;
            body.emit(f02DD);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0308 = new(mem_ctx) ir_if(operand(r02D9).val);
            exec_list *const f0308_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0308->then_instructions;

               /* IF CONDITION */
               ir_if *f0309 = new(mem_ctx) ir_if(operand(r02DB).val);
               exec_list *const f0309_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0309->then_instructions;

                  ir_variable *const r030A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r030A, add(r02D7, body.constant(1u)), 0x01));

                  ir_expression *const r030B = less(r030A, r02D7);
                  ir_expression *const r030C = expr(ir_unop_b2i, r030B);
                  ir_expression *const r030D = expr(ir_unop_i2u, r030C);
                  body.emit(assign(r02D6, add(r02D6, r030D), 0x01));

                  ir_expression *const r030E = equal(r02D8, body.constant(0u));
                  ir_expression *const r030F = expr(ir_unop_b2i, r030E);
                  ir_expression *const r0310 = expr(ir_unop_i2u, r030F);
                  ir_expression *const r0311 = add(r02D8, r0310);
                  ir_expression *const r0312 = bit_and(r0311, body.constant(1u));
                  ir_expression *const r0313 = expr(ir_unop_bit_not, r0312);
                  body.emit(assign(r02D7, bit_and(r030A, r0313), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0309->else_instructions;

                  ir_expression *const r0314 = bit_or(r02D6, r02D7);
                  ir_expression *const r0315 = equal(r0314, body.constant(0u));
                  body.emit(assign(r02D5, expr(ir_triop_csel, r0315, body.constant(int(0)), r02D5), 0x01));


               body.instructions = f0309_parent_instructions;
               body.emit(f0309);

               /* END IF */

               ir_variable *const r0316 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0316);
               ir_expression *const r0317 = lshift(r01D8, body.constant(int(31)));
               ir_expression *const r0318 = expr(ir_unop_i2u, r02D5);
               ir_expression *const r0319 = lshift(r0318, body.constant(int(20)));
               ir_expression *const r031A = add(r0317, r0319);
               body.emit(assign(r0316, add(r031A, r02D6), 0x02));

               body.emit(assign(r0316, r02D7, 0x01));

               body.emit(assign(r02DA, r0316, 0x03));

               body.emit(assign(r02D9, body.constant(false), 0x01));


            body.instructions = f0308_parent_instructions;
            body.emit(f0308);

            /* END IF */

            body.emit(assign(r01CE, r02DA, 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02D3->else_instructions;

            body.emit(assign(r01E7, add(r01E7, body.constant(int(1))), 0x01));

            ir_variable *const r031B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r031B);
            ir_variable *const r031C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r031C);
            ir_variable *const r031D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r031D);
            body.emit(assign(r031B, lshift(r02CE, body.constant(int(31))), 0x01));

            ir_expression *const r031E = lshift(r02CD, body.constant(int(31)));
            ir_expression *const r031F = rshift(r02CE, body.constant(int(1)));
            body.emit(assign(r031C, bit_or(r031E, r031F), 0x01));

            body.emit(assign(r031D, rshift(r02CD, body.constant(int(1))), 0x01));

            ir_expression *const r0320 = nequal(r01E8, body.constant(0u));
            ir_expression *const r0321 = expr(ir_unop_b2i, r0320);
            ir_expression *const r0322 = expr(ir_unop_i2u, r0321);
            body.emit(assign(r031B, bit_or(r031B, r0322), 0x01));

            body.emit(assign(r01D0, r031D, 0x01));

            body.emit(assign(r01E8, r031B, 0x01));

            ir_variable *const r0323 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0323, r01E7, 0x01));

            ir_variable *const r0324 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0324, r031D, 0x01));

            ir_variable *const r0325 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0325, r031C, 0x01));

            ir_variable *const r0326 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0326, r031B, 0x01));

            ir_variable *const r0327 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0327, body.constant(true), 0x01));

            ir_variable *const r0328 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0329 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0329);
            ir_expression *const r032A = expr(ir_unop_u2i, r031B);
            body.emit(assign(r0329, less(r032A, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r032C = gequal(r01E7, body.constant(int(2045)));
            ir_if *f032B = new(mem_ctx) ir_if(operand(r032C).val);
            exec_list *const f032B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f032B->then_instructions;

               /* IF CONDITION */
               ir_expression *const r032E = less(body.constant(int(2045)), r01E7);
               ir_expression *const r032F = equal(r01E7, body.constant(int(2045)));
               ir_expression *const r0330 = equal(body.constant(2097151u), r031D);
               ir_expression *const r0331 = equal(body.constant(4294967295u), r031C);
               ir_expression *const r0332 = logic_and(r0330, r0331);
               ir_expression *const r0333 = logic_and(r032F, r0332);
               ir_expression *const r0334 = logic_and(r0333, r0329);
               ir_expression *const r0335 = logic_or(r032E, r0334);
               ir_if *f032D = new(mem_ctx) ir_if(operand(r0335).val);
               exec_list *const f032D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f032D->then_instructions;

                  ir_variable *const r0336 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0336);
                  ir_expression *const r0337 = lshift(r01D8, body.constant(int(31)));
                  body.emit(assign(r0336, add(r0337, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0336, body.constant(0u), 0x01));

                  body.emit(assign(r0328, r0336, 0x03));

                  body.emit(assign(r0327, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f032D->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0339 = less(r01E7, body.constant(int(0)));
                  ir_if *f0338 = new(mem_ctx) ir_if(operand(r0339).val);
                  exec_list *const f0338_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0338->then_instructions;

                     ir_variable *const r033A = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r033A, r031B, 0x01));

                     ir_variable *const r033B = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r033B, neg(r01E7), 0x01));

                     ir_variable *const r033C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r033C);
                     ir_variable *const r033D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r033D);
                     ir_variable *const r033E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r033E);
                     ir_variable *const r033F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0340 = neg(r033B);
                     body.emit(assign(r033F, bit_and(r0340, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0342 = equal(r033B, body.constant(int(0)));
                     ir_if *f0341 = new(mem_ctx) ir_if(operand(r0342).val);
                     exec_list *const f0341_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0341->then_instructions;

                        body.emit(assign(r033C, r031B, 0x01));

                        body.emit(assign(r033D, r031C, 0x01));

                        body.emit(assign(r033E, r031D, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0341->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0344 = less(r033B, body.constant(int(32)));
                        ir_if *f0343 = new(mem_ctx) ir_if(operand(r0344).val);
                        exec_list *const f0343_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0343->then_instructions;

                           body.emit(assign(r033C, lshift(r031C, r033F), 0x01));

                           ir_expression *const r0345 = lshift(r031D, r033F);
                           ir_expression *const r0346 = rshift(r031C, r033B);
                           body.emit(assign(r033D, bit_or(r0345, r0346), 0x01));

                           body.emit(assign(r033E, rshift(r031D, r033B), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0343->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0348 = equal(r033B, body.constant(int(32)));
                           ir_if *f0347 = new(mem_ctx) ir_if(operand(r0348).val);
                           exec_list *const f0347_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0347->then_instructions;

                              body.emit(assign(r033C, r031C, 0x01));

                              body.emit(assign(r033D, r031D, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0347->else_instructions;

                              body.emit(assign(r033A, bit_or(r031B, r031C), 0x01));

                              ir_expression *const r0349 = less(r033B, body.constant(int(64)));
                              ir_expression *const r034A = lshift(r031D, r033F);
                              ir_expression *const r034B = equal(r033B, body.constant(int(64)));
                              ir_expression *const r034C = nequal(r031D, body.constant(0u));
                              ir_expression *const r034D = expr(ir_unop_b2i, r034C);
                              ir_expression *const r034E = expr(ir_unop_i2u, r034D);
                              ir_expression *const r034F = expr(ir_triop_csel, r034B, r031D, r034E);
                              body.emit(assign(r033C, expr(ir_triop_csel, r0349, r034A, r034F), 0x01));

                              ir_expression *const r0350 = less(r033B, body.constant(int(64)));
                              ir_expression *const r0351 = bit_and(r033B, body.constant(int(31)));
                              ir_expression *const r0352 = rshift(r031D, r0351);
                              body.emit(assign(r033D, expr(ir_triop_csel, r0350, r0352, body.constant(0u)), 0x01));


                           body.instructions = f0347_parent_instructions;
                           body.emit(f0347);

                           /* END IF */

                           body.emit(assign(r033E, body.constant(0u), 0x01));


                        body.instructions = f0343_parent_instructions;
                        body.emit(f0343);

                        /* END IF */

                        ir_expression *const r0353 = nequal(r033A, body.constant(0u));
                        ir_expression *const r0354 = expr(ir_unop_b2i, r0353);
                        ir_expression *const r0355 = expr(ir_unop_i2u, r0354);
                        body.emit(assign(r033C, bit_or(r033C, r0355), 0x01));


                     body.instructions = f0341_parent_instructions;
                     body.emit(f0341);

                     /* END IF */

                     body.emit(assign(r0324, r033E, 0x01));

                     body.emit(assign(r0325, r033D, 0x01));

                     body.emit(assign(r0326, r033C, 0x01));

                     body.emit(assign(r0323, body.constant(int(0)), 0x01));

                     body.emit(assign(r0329, less(r033C, body.constant(0u)), 0x01));


                  body.instructions = f0338_parent_instructions;
                  body.emit(f0338);

                  /* END IF */


               body.instructions = f032D_parent_instructions;
               body.emit(f032D);

               /* END IF */


            body.instructions = f032B_parent_instructions;
            body.emit(f032B);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0356 = new(mem_ctx) ir_if(operand(r0327).val);
            exec_list *const f0356_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0356->then_instructions;

               /* IF CONDITION */
               ir_if *f0357 = new(mem_ctx) ir_if(operand(r0329).val);
               exec_list *const f0357_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0357->then_instructions;

                  ir_variable *const r0358 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0358, add(r0325, body.constant(1u)), 0x01));

                  ir_expression *const r0359 = less(r0358, r0325);
                  ir_expression *const r035A = expr(ir_unop_b2i, r0359);
                  ir_expression *const r035B = expr(ir_unop_i2u, r035A);
                  body.emit(assign(r0324, add(r0324, r035B), 0x01));

                  ir_expression *const r035C = equal(r0326, body.constant(0u));
                  ir_expression *const r035D = expr(ir_unop_b2i, r035C);
                  ir_expression *const r035E = expr(ir_unop_i2u, r035D);
                  ir_expression *const r035F = add(r0326, r035E);
                  ir_expression *const r0360 = bit_and(r035F, body.constant(1u));
                  ir_expression *const r0361 = expr(ir_unop_bit_not, r0360);
                  body.emit(assign(r0325, bit_and(r0358, r0361), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0357->else_instructions;

                  ir_expression *const r0362 = bit_or(r0324, r0325);
                  ir_expression *const r0363 = equal(r0362, body.constant(0u));
                  body.emit(assign(r0323, expr(ir_triop_csel, r0363, body.constant(int(0)), r0323), 0x01));


               body.instructions = f0357_parent_instructions;
               body.emit(f0357);

               /* END IF */

               ir_variable *const r0364 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0364);
               ir_expression *const r0365 = lshift(r01D8, body.constant(int(31)));
               ir_expression *const r0366 = expr(ir_unop_i2u, r0323);
               ir_expression *const r0367 = lshift(r0366, body.constant(int(20)));
               ir_expression *const r0368 = add(r0365, r0367);
               body.emit(assign(r0364, add(r0368, r0324), 0x02));

               body.emit(assign(r0364, r0325, 0x01));

               body.emit(assign(r0328, r0364, 0x03));

               body.emit(assign(r0327, body.constant(false), 0x01));


            body.instructions = f0356_parent_instructions;
            body.emit(f0356);

            /* END IF */

            body.emit(assign(r01CE, r0328, 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


         body.instructions = f02D3_parent_instructions;
         body.emit(f02D3);

         /* END IF */


      body.instructions = f02CC_parent_instructions;
      body.emit(f02CC);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01E5->else_instructions;

      ir_variable *const r0369 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r0369);
      ir_variable *const r036A = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r036B = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r036B, lshift(r01D6, body.constant(int(10))), 0x01));

      ir_expression *const r036C = lshift(r01D5, body.constant(int(10)));
      ir_expression *const r036D = rshift(r01D6, body.constant(int(22)));
      body.emit(assign(r036A, bit_or(r036C, r036D), 0x01));

      body.emit(assign(r01D5, r036A, 0x01));

      body.emit(assign(r01D6, r036B, 0x01));

      ir_variable *const r036E = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r036F = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r036F, lshift(r01D4, body.constant(int(10))), 0x01));

      ir_expression *const r0370 = lshift(r01D3, body.constant(int(10)));
      ir_expression *const r0371 = rshift(r01D4, body.constant(int(22)));
      body.emit(assign(r036E, bit_or(r0370, r0371), 0x01));

      body.emit(assign(r01D3, r036E, 0x01));

      body.emit(assign(r01D4, r036F, 0x01));

      /* IF CONDITION */
      ir_expression *const r0373 = less(body.constant(int(0)), r01CF);
      ir_if *f0372 = new(mem_ctx) ir_if(operand(r0373).val);
      exec_list *const f0372_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0372->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0375 = equal(r01DE, body.constant(int(2047)));
         ir_if *f0374 = new(mem_ctx) ir_if(operand(r0375).val);
         exec_list *const f0374_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0374->then_instructions;

            ir_variable *const r0376 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0376, swizzle_x(r01CB), 0x01));

            ir_variable *const r0377 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0377, swizzle_x(r01CC), 0x01));

            body.emit(assign(r0376, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

            body.emit(assign(r0377, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

            ir_expression *const r0378 = bit_or(r036A, r036B);
            ir_expression *const r0379 = nequal(r0378, body.constant(0u));
            ir_swizzle *const r037A = swizzle(r0379, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r037B = lshift(swizzle_y(r01CB), body.constant(int(1)));
            ir_expression *const r037C = gequal(r037B, body.constant(4292870144u));
            ir_expression *const r037D = nequal(swizzle_x(r01CB), body.constant(0u));
            ir_expression *const r037E = bit_and(swizzle_y(r01CB), body.constant(1048575u));
            ir_expression *const r037F = nequal(r037E, body.constant(0u));
            ir_expression *const r0380 = logic_or(r037D, r037F);
            ir_expression *const r0381 = logic_and(r037C, r0380);
            ir_swizzle *const r0382 = swizzle(r0381, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0383 = lshift(swizzle_y(r01CC), body.constant(int(1)));
            ir_expression *const r0384 = gequal(r0383, body.constant(4292870144u));
            ir_expression *const r0385 = nequal(swizzle_x(r01CC), body.constant(0u));
            ir_expression *const r0386 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
            ir_expression *const r0387 = nequal(r0386, body.constant(0u));
            ir_expression *const r0388 = logic_or(r0385, r0387);
            ir_expression *const r0389 = logic_and(r0384, r0388);
            ir_swizzle *const r038A = swizzle(r0389, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r038B = expr(ir_triop_csel, r038A, r0377, r0376);
            ir_expression *const r038C = expr(ir_triop_csel, r0382, r038B, r0377);
            body.emit(assign(r01CE, expr(ir_triop_csel, r037A, r038C, r01CB), 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0374->else_instructions;

            /* IF CONDITION */
            ir_expression *const r038E = equal(r01E1, body.constant(int(0)));
            ir_if *f038D = new(mem_ctx) ir_if(operand(r038E).val);
            exec_list *const f038D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f038D->then_instructions;

               body.emit(assign(r01CF, add(r01CF, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f038D->else_instructions;

               body.emit(assign(r01D3, bit_or(r036E, body.constant(1073741824u)), 0x01));


            body.instructions = f038D_parent_instructions;
            body.emit(f038D);

            /* END IF */

            ir_variable *const r038F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r038F);
            ir_variable *const r0390 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0391 = neg(r01CF);
            body.emit(assign(r0390, bit_and(r0391, body.constant(int(31))), 0x01));

            ir_variable *const r0392 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0393 = less(r01CF, body.constant(int(32)));
            ir_expression *const r0394 = rshift(r01D3, r01CF);
            ir_expression *const r0395 = equal(r01CF, body.constant(int(0)));
            ir_expression *const r0396 = expr(ir_triop_csel, r0395, r01D3, body.constant(0u));
            body.emit(assign(r0392, expr(ir_triop_csel, r0393, r0394, r0396), 0x01));

            /* IF CONDITION */
            ir_expression *const r0398 = equal(r01CF, body.constant(int(0)));
            ir_if *f0397 = new(mem_ctx) ir_if(operand(r0398).val);
            exec_list *const f0397_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0397->then_instructions;

               body.emit(assign(r038F, r036F, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0397->else_instructions;

               /* IF CONDITION */
               ir_expression *const r039A = less(r01CF, body.constant(int(32)));
               ir_if *f0399 = new(mem_ctx) ir_if(operand(r039A).val);
               exec_list *const f0399_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0399->then_instructions;

                  ir_expression *const r039B = lshift(r01D3, r0390);
                  ir_expression *const r039C = rshift(r036F, r01CF);
                  ir_expression *const r039D = bit_or(r039B, r039C);
                  ir_expression *const r039E = lshift(r036F, r0390);
                  ir_expression *const r039F = nequal(r039E, body.constant(0u));
                  ir_expression *const r03A0 = expr(ir_unop_b2i, r039F);
                  ir_expression *const r03A1 = expr(ir_unop_i2u, r03A0);
                  body.emit(assign(r038F, bit_or(r039D, r03A1), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0399->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03A3 = equal(r01CF, body.constant(int(32)));
                  ir_if *f03A2 = new(mem_ctx) ir_if(operand(r03A3).val);
                  exec_list *const f03A2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03A2->then_instructions;

                     ir_expression *const r03A4 = nequal(r036F, body.constant(0u));
                     ir_expression *const r03A5 = expr(ir_unop_b2i, r03A4);
                     ir_expression *const r03A6 = expr(ir_unop_i2u, r03A5);
                     body.emit(assign(r038F, bit_or(r01D3, r03A6), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03A2->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03A8 = less(r01CF, body.constant(int(64)));
                     ir_if *f03A7 = new(mem_ctx) ir_if(operand(r03A8).val);
                     exec_list *const f03A7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03A7->then_instructions;

                        ir_expression *const r03A9 = bit_and(r01CF, body.constant(int(31)));
                        ir_expression *const r03AA = rshift(r01D3, r03A9);
                        ir_expression *const r03AB = lshift(r01D3, r0390);
                        ir_expression *const r03AC = bit_or(r03AB, r036F);
                        ir_expression *const r03AD = nequal(r03AC, body.constant(0u));
                        ir_expression *const r03AE = expr(ir_unop_b2i, r03AD);
                        ir_expression *const r03AF = expr(ir_unop_i2u, r03AE);
                        body.emit(assign(r038F, bit_or(r03AA, r03AF), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03A7->else_instructions;

                        ir_expression *const r03B0 = bit_or(r01D3, r036F);
                        ir_expression *const r03B1 = nequal(r03B0, body.constant(0u));
                        ir_expression *const r03B2 = expr(ir_unop_b2i, r03B1);
                        body.emit(assign(r038F, expr(ir_unop_i2u, r03B2), 0x01));


                     body.instructions = f03A7_parent_instructions;
                     body.emit(f03A7);

                     /* END IF */


                  body.instructions = f03A2_parent_instructions;
                  body.emit(f03A2);

                  /* END IF */


               body.instructions = f0399_parent_instructions;
               body.emit(f0399);

               /* END IF */


            body.instructions = f0397_parent_instructions;
            body.emit(f0397);

            /* END IF */

            body.emit(assign(r01D3, r0392, 0x01));

            body.emit(assign(r01D4, r038F, 0x01));

            body.emit(assign(r01D5, bit_or(r036A, body.constant(1073741824u)), 0x01));

            ir_variable *const r03B3 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_expression *const r03B4 = sub(r01D5, r0392);
            ir_expression *const r03B5 = less(r036B, r038F);
            ir_expression *const r03B6 = expr(ir_unop_b2i, r03B5);
            ir_expression *const r03B7 = expr(ir_unop_i2u, r03B6);
            body.emit(assign(r03B3, sub(r03B4, r03B7), 0x01));

            body.emit(assign(r01D0, r03B3, 0x01));

            body.emit(assign(r0369, add(r01DE, body.constant(int(-1))), 0x01));

            ir_variable *const r03B8 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03B8, add(r0369, body.constant(int(-10))), 0x01));

            ir_variable *const r03B9 = body.make_temp(glsl_type::uint_type, "zFrac0");
            ir_variable *const r03BA = body.make_temp(glsl_type::uint_type, "zFrac1");
            ir_variable *const r03BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03BB);
            ir_variable *const r03BC = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03BC);
            ir_expression *const r03BD = equal(r03B3, body.constant(0u));
            ir_expression *const r03BE = add(r03B8, body.constant(int(-32)));
            body.emit(assign(r03B8, expr(ir_triop_csel, r03BD, r03BE, r03B8), 0x01));

            ir_variable *const r03BF = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03C0 = equal(r03B3, body.constant(0u));
            ir_expression *const r03C1 = sub(r036B, r038F);
            body.emit(assign(r03BF, expr(ir_triop_csel, r03C0, body.constant(0u), r03C1), 0x01));

            body.emit(assign(r03BA, r03BF, 0x01));

            ir_variable *const r03C2 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03C3 = equal(r03B3, body.constant(0u));
            body.emit(assign(r03C2, expr(ir_triop_csel, r03C3, r03BF, r03B3), 0x01));

            body.emit(assign(r03B9, r03C2, 0x01));

            ir_expression *const r03C4 = equal(r03C2, body.constant(0u));
            ir_expression *const r03C5 = expr(ir_unop_find_msb, r03C2);
            ir_expression *const r03C6 = sub(body.constant(int(31)), r03C5);
            ir_expression *const r03C7 = expr(ir_triop_csel, r03C4, body.constant(int(32)), r03C6);
            body.emit(assign(r03BC, add(r03C7, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03C9 = gequal(r03BC, body.constant(int(0)));
            ir_if *f03C8 = new(mem_ctx) ir_if(operand(r03C9).val);
            exec_list *const f03C8_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03C8->then_instructions;

               body.emit(assign(r03BB, body.constant(0u), 0x01));

               ir_expression *const r03CA = equal(r03BC, body.constant(int(0)));
               ir_expression *const r03CB = lshift(r03C2, r03BC);
               ir_expression *const r03CC = neg(r03BC);
               ir_expression *const r03CD = bit_and(r03CC, body.constant(int(31)));
               ir_expression *const r03CE = rshift(r03BF, r03CD);
               ir_expression *const r03CF = bit_or(r03CB, r03CE);
               body.emit(assign(r03B9, expr(ir_triop_csel, r03CA, r03C2, r03CF), 0x01));

               body.emit(assign(r03BA, lshift(r03BF, r03BC), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03C8->else_instructions;

               ir_variable *const r03D0 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r03D0, body.constant(0u), 0x01));

               ir_variable *const r03D1 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r03D1, neg(r03BC), 0x01));

               ir_variable *const r03D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r03D2);
               ir_variable *const r03D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r03D3);
               ir_variable *const r03D4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r03D4);
               ir_variable *const r03D5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r03D6 = neg(r03D1);
               body.emit(assign(r03D5, bit_and(r03D6, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r03D8 = equal(r03D1, body.constant(int(0)));
               ir_if *f03D7 = new(mem_ctx) ir_if(operand(r03D8).val);
               exec_list *const f03D7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03D7->then_instructions;

                  body.emit(assign(r03D2, r03D0, 0x01));

                  body.emit(assign(r03D3, r03BA, 0x01));

                  body.emit(assign(r03D4, r03B9, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03D7->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03DA = less(r03D1, body.constant(int(32)));
                  ir_if *f03D9 = new(mem_ctx) ir_if(operand(r03DA).val);
                  exec_list *const f03D9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03D9->then_instructions;

                     body.emit(assign(r03D2, lshift(r03BA, r03D5), 0x01));

                     ir_expression *const r03DB = lshift(r03B9, r03D5);
                     ir_expression *const r03DC = rshift(r03BA, r03D1);
                     body.emit(assign(r03D3, bit_or(r03DB, r03DC), 0x01));

                     body.emit(assign(r03D4, rshift(r03B9, r03D1), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03D9->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03DE = equal(r03D1, body.constant(int(32)));
                     ir_if *f03DD = new(mem_ctx) ir_if(operand(r03DE).val);
                     exec_list *const f03DD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03DD->then_instructions;

                        body.emit(assign(r03D2, r03BA, 0x01));

                        body.emit(assign(r03D3, r03B9, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03DD->else_instructions;

                        body.emit(assign(r03D0, bit_or(body.constant(0u), r03BA), 0x01));

                        ir_expression *const r03DF = less(r03D1, body.constant(int(64)));
                        ir_expression *const r03E0 = lshift(r03B9, r03D5);
                        ir_expression *const r03E1 = equal(r03D1, body.constant(int(64)));
                        ir_expression *const r03E2 = nequal(r03B9, body.constant(0u));
                        ir_expression *const r03E3 = expr(ir_unop_b2i, r03E2);
                        ir_expression *const r03E4 = expr(ir_unop_i2u, r03E3);
                        ir_expression *const r03E5 = expr(ir_triop_csel, r03E1, r03B9, r03E4);
                        body.emit(assign(r03D2, expr(ir_triop_csel, r03DF, r03E0, r03E5), 0x01));

                        ir_expression *const r03E6 = less(r03D1, body.constant(int(64)));
                        ir_expression *const r03E7 = bit_and(r03D1, body.constant(int(31)));
                        ir_expression *const r03E8 = rshift(r03B9, r03E7);
                        body.emit(assign(r03D3, expr(ir_triop_csel, r03E6, r03E8, body.constant(0u)), 0x01));


                     body.instructions = f03DD_parent_instructions;
                     body.emit(f03DD);

                     /* END IF */

                     body.emit(assign(r03D4, body.constant(0u), 0x01));


                  body.instructions = f03D9_parent_instructions;
                  body.emit(f03D9);

                  /* END IF */

                  ir_expression *const r03E9 = nequal(r03D0, body.constant(0u));
                  ir_expression *const r03EA = expr(ir_unop_b2i, r03E9);
                  ir_expression *const r03EB = expr(ir_unop_i2u, r03EA);
                  body.emit(assign(r03D2, bit_or(r03D2, r03EB), 0x01));


               body.instructions = f03D7_parent_instructions;
               body.emit(f03D7);

               /* END IF */

               body.emit(assign(r03B9, r03D4, 0x01));

               body.emit(assign(r03BA, r03D3, 0x01));

               body.emit(assign(r03BB, r03D2, 0x01));


            body.instructions = f03C8_parent_instructions;
            body.emit(f03C8);

            /* END IF */

            body.emit(assign(r03B8, sub(r03B8, r03BC), 0x01));

            ir_variable *const r03EC = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03EC, r03B8, 0x01));

            ir_variable *const r03ED = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03ED, r03B9, 0x01));

            ir_variable *const r03EE = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03EE, r03BA, 0x01));

            ir_variable *const r03EF = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r03EF, r03BB, 0x01));

            ir_variable *const r03F0 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r03F0, body.constant(true), 0x01));

            ir_variable *const r03F1 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r03F2 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r03F2);
            ir_expression *const r03F3 = expr(ir_unop_u2i, r03BB);
            body.emit(assign(r03F2, less(r03F3, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03F5 = gequal(r03B8, body.constant(int(2045)));
            ir_if *f03F4 = new(mem_ctx) ir_if(operand(r03F5).val);
            exec_list *const f03F4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03F4->then_instructions;

               /* IF CONDITION */
               ir_expression *const r03F7 = less(body.constant(int(2045)), r03B8);
               ir_expression *const r03F8 = equal(r03B8, body.constant(int(2045)));
               ir_expression *const r03F9 = equal(body.constant(2097151u), r03B9);
               ir_expression *const r03FA = equal(body.constant(4294967295u), r03BA);
               ir_expression *const r03FB = logic_and(r03F9, r03FA);
               ir_expression *const r03FC = logic_and(r03F8, r03FB);
               ir_expression *const r03FD = logic_and(r03FC, r03F2);
               ir_expression *const r03FE = logic_or(r03F7, r03FD);
               ir_if *f03F6 = new(mem_ctx) ir_if(operand(r03FE).val);
               exec_list *const f03F6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F6->then_instructions;

                  ir_variable *const r03FF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r03FF);
                  ir_expression *const r0400 = lshift(r01D8, body.constant(int(31)));
                  body.emit(assign(r03FF, add(r0400, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r03FF, body.constant(0u), 0x01));

                  body.emit(assign(r03F1, r03FF, 0x03));

                  body.emit(assign(r03F0, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03F6->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0402 = less(r03B8, body.constant(int(0)));
                  ir_if *f0401 = new(mem_ctx) ir_if(operand(r0402).val);
                  exec_list *const f0401_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0401->then_instructions;

                     ir_variable *const r0403 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0403, r03BB, 0x01));

                     ir_variable *const r0404 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0404, neg(r03B8), 0x01));

                     ir_variable *const r0405 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0405);
                     ir_variable *const r0406 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0406);
                     ir_variable *const r0407 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0407);
                     ir_variable *const r0408 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0409 = neg(r0404);
                     body.emit(assign(r0408, bit_and(r0409, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r040B = equal(r0404, body.constant(int(0)));
                     ir_if *f040A = new(mem_ctx) ir_if(operand(r040B).val);
                     exec_list *const f040A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f040A->then_instructions;

                        body.emit(assign(r0405, r03BB, 0x01));

                        body.emit(assign(r0406, r03BA, 0x01));

                        body.emit(assign(r0407, r03B9, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f040A->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r040D = less(r0404, body.constant(int(32)));
                        ir_if *f040C = new(mem_ctx) ir_if(operand(r040D).val);
                        exec_list *const f040C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f040C->then_instructions;

                           body.emit(assign(r0405, lshift(r03BA, r0408), 0x01));

                           ir_expression *const r040E = lshift(r03B9, r0408);
                           ir_expression *const r040F = rshift(r03BA, r0404);
                           body.emit(assign(r0406, bit_or(r040E, r040F), 0x01));

                           body.emit(assign(r0407, rshift(r03B9, r0404), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f040C->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0411 = equal(r0404, body.constant(int(32)));
                           ir_if *f0410 = new(mem_ctx) ir_if(operand(r0411).val);
                           exec_list *const f0410_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0410->then_instructions;

                              body.emit(assign(r0405, r03BA, 0x01));

                              body.emit(assign(r0406, r03B9, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0410->else_instructions;

                              body.emit(assign(r0403, bit_or(r03BB, r03BA), 0x01));

                              ir_expression *const r0412 = less(r0404, body.constant(int(64)));
                              ir_expression *const r0413 = lshift(r03B9, r0408);
                              ir_expression *const r0414 = equal(r0404, body.constant(int(64)));
                              ir_expression *const r0415 = nequal(r03B9, body.constant(0u));
                              ir_expression *const r0416 = expr(ir_unop_b2i, r0415);
                              ir_expression *const r0417 = expr(ir_unop_i2u, r0416);
                              ir_expression *const r0418 = expr(ir_triop_csel, r0414, r03B9, r0417);
                              body.emit(assign(r0405, expr(ir_triop_csel, r0412, r0413, r0418), 0x01));

                              ir_expression *const r0419 = less(r0404, body.constant(int(64)));
                              ir_expression *const r041A = bit_and(r0404, body.constant(int(31)));
                              ir_expression *const r041B = rshift(r03B9, r041A);
                              body.emit(assign(r0406, expr(ir_triop_csel, r0419, r041B, body.constant(0u)), 0x01));


                           body.instructions = f0410_parent_instructions;
                           body.emit(f0410);

                           /* END IF */

                           body.emit(assign(r0407, body.constant(0u), 0x01));


                        body.instructions = f040C_parent_instructions;
                        body.emit(f040C);

                        /* END IF */

                        ir_expression *const r041C = nequal(r0403, body.constant(0u));
                        ir_expression *const r041D = expr(ir_unop_b2i, r041C);
                        ir_expression *const r041E = expr(ir_unop_i2u, r041D);
                        body.emit(assign(r0405, bit_or(r0405, r041E), 0x01));


                     body.instructions = f040A_parent_instructions;
                     body.emit(f040A);

                     /* END IF */

                     body.emit(assign(r03ED, r0407, 0x01));

                     body.emit(assign(r03EE, r0406, 0x01));

                     body.emit(assign(r03EF, r0405, 0x01));

                     body.emit(assign(r03EC, body.constant(int(0)), 0x01));

                     body.emit(assign(r03F2, less(r0405, body.constant(0u)), 0x01));


                  body.instructions = f0401_parent_instructions;
                  body.emit(f0401);

                  /* END IF */


               body.instructions = f03F6_parent_instructions;
               body.emit(f03F6);

               /* END IF */


            body.instructions = f03F4_parent_instructions;
            body.emit(f03F4);

            /* END IF */

            /* IF CONDITION */
            ir_if *f041F = new(mem_ctx) ir_if(operand(r03F0).val);
            exec_list *const f041F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f041F->then_instructions;

               /* IF CONDITION */
               ir_if *f0420 = new(mem_ctx) ir_if(operand(r03F2).val);
               exec_list *const f0420_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0420->then_instructions;

                  ir_variable *const r0421 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0421, add(r03EE, body.constant(1u)), 0x01));

                  ir_expression *const r0422 = less(r0421, r03EE);
                  ir_expression *const r0423 = expr(ir_unop_b2i, r0422);
                  ir_expression *const r0424 = expr(ir_unop_i2u, r0423);
                  body.emit(assign(r03ED, add(r03ED, r0424), 0x01));

                  ir_expression *const r0425 = equal(r03EF, body.constant(0u));
                  ir_expression *const r0426 = expr(ir_unop_b2i, r0425);
                  ir_expression *const r0427 = expr(ir_unop_i2u, r0426);
                  ir_expression *const r0428 = add(r03EF, r0427);
                  ir_expression *const r0429 = bit_and(r0428, body.constant(1u));
                  ir_expression *const r042A = expr(ir_unop_bit_not, r0429);
                  body.emit(assign(r03EE, bit_and(r0421, r042A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0420->else_instructions;

                  ir_expression *const r042B = bit_or(r03ED, r03EE);
                  ir_expression *const r042C = equal(r042B, body.constant(0u));
                  body.emit(assign(r03EC, expr(ir_triop_csel, r042C, body.constant(int(0)), r03EC), 0x01));


               body.instructions = f0420_parent_instructions;
               body.emit(f0420);

               /* END IF */

               ir_variable *const r042D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r042D);
               ir_expression *const r042E = lshift(r01D8, body.constant(int(31)));
               ir_expression *const r042F = expr(ir_unop_i2u, r03EC);
               ir_expression *const r0430 = lshift(r042F, body.constant(int(20)));
               ir_expression *const r0431 = add(r042E, r0430);
               body.emit(assign(r042D, add(r0431, r03ED), 0x02));

               body.emit(assign(r042D, r03EE, 0x01));

               body.emit(assign(r03F1, r042D, 0x03));

               body.emit(assign(r03F0, body.constant(false), 0x01));


            body.instructions = f041F_parent_instructions;
            body.emit(f041F);

            /* END IF */

            body.emit(assign(r01CE, r03F1, 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


         body.instructions = f0374_parent_instructions;
         body.emit(f0374);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0372->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0433 = less(r01CF, body.constant(int(0)));
         ir_if *f0432 = new(mem_ctx) ir_if(operand(r0433).val);
         exec_list *const f0432_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0432->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0435 = equal(r01E1, body.constant(int(2047)));
            ir_if *f0434 = new(mem_ctx) ir_if(operand(r0435).val);
            exec_list *const f0434_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0434->then_instructions;

               ir_variable *const r0436 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0436);
               ir_expression *const r0437 = bit_xor(r01D8, body.constant(1u));
               ir_expression *const r0438 = lshift(r0437, body.constant(int(31)));
               body.emit(assign(r0436, add(r0438, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0436, body.constant(0u), 0x01));

               ir_variable *const r0439 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0439, swizzle_x(r01CB), 0x01));

               ir_variable *const r043A = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r043A, swizzle_x(r01CC), 0x01));

               body.emit(assign(r0439, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r043A, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r043B = bit_or(r01D3, r01D4);
               ir_expression *const r043C = nequal(r043B, body.constant(0u));
               ir_swizzle *const r043D = swizzle(r043C, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r043E = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r043F = gequal(r043E, body.constant(4292870144u));
               ir_expression *const r0440 = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r0441 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r0442 = nequal(r0441, body.constant(0u));
               ir_expression *const r0443 = logic_or(r0440, r0442);
               ir_expression *const r0444 = logic_and(r043F, r0443);
               ir_swizzle *const r0445 = swizzle(r0444, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0446 = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r0447 = gequal(r0446, body.constant(4292870144u));
               ir_expression *const r0448 = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r0449 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r044A = nequal(r0449, body.constant(0u));
               ir_expression *const r044B = logic_or(r0448, r044A);
               ir_expression *const r044C = logic_and(r0447, r044B);
               ir_swizzle *const r044D = swizzle(r044C, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r044E = expr(ir_triop_csel, r044D, r043A, r0439);
               ir_expression *const r044F = expr(ir_triop_csel, r0445, r044E, r043A);
               body.emit(assign(r01CE, expr(ir_triop_csel, r043D, r044F, r0436), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0434->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0451 = equal(r01DE, body.constant(int(0)));
               ir_if *f0450 = new(mem_ctx) ir_if(operand(r0451).val);
               exec_list *const f0450_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0450->then_instructions;

                  body.emit(assign(r01CF, add(r01CF, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0450->else_instructions;

                  body.emit(assign(r01D5, bit_or(r01D5, body.constant(1073741824u)), 0x01));


               body.instructions = f0450_parent_instructions;
               body.emit(f0450);

               /* END IF */

               ir_variable *const r0452 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0452, neg(r01CF), 0x01));

               ir_variable *const r0453 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0453);
               ir_variable *const r0454 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0455 = neg(r0452);
               body.emit(assign(r0454, bit_and(r0455, body.constant(int(31))), 0x01));

               ir_variable *const r0456 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0457 = less(r0452, body.constant(int(32)));
               ir_expression *const r0458 = rshift(r01D5, r0452);
               ir_expression *const r0459 = equal(r0452, body.constant(int(0)));
               ir_expression *const r045A = expr(ir_triop_csel, r0459, r01D5, body.constant(0u));
               body.emit(assign(r0456, expr(ir_triop_csel, r0457, r0458, r045A), 0x01));

               /* IF CONDITION */
               ir_expression *const r045C = equal(r0452, body.constant(int(0)));
               ir_if *f045B = new(mem_ctx) ir_if(operand(r045C).val);
               exec_list *const f045B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f045B->then_instructions;

                  body.emit(assign(r0453, r036B, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f045B->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r045E = less(r0452, body.constant(int(32)));
                  ir_if *f045D = new(mem_ctx) ir_if(operand(r045E).val);
                  exec_list *const f045D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f045D->then_instructions;

                     ir_expression *const r045F = lshift(r01D5, r0454);
                     ir_expression *const r0460 = rshift(r036B, r0452);
                     ir_expression *const r0461 = bit_or(r045F, r0460);
                     ir_expression *const r0462 = lshift(r036B, r0454);
                     ir_expression *const r0463 = nequal(r0462, body.constant(0u));
                     ir_expression *const r0464 = expr(ir_unop_b2i, r0463);
                     ir_expression *const r0465 = expr(ir_unop_i2u, r0464);
                     body.emit(assign(r0453, bit_or(r0461, r0465), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f045D->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0467 = equal(r0452, body.constant(int(32)));
                     ir_if *f0466 = new(mem_ctx) ir_if(operand(r0467).val);
                     exec_list *const f0466_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0466->then_instructions;

                        ir_expression *const r0468 = nequal(r036B, body.constant(0u));
                        ir_expression *const r0469 = expr(ir_unop_b2i, r0468);
                        ir_expression *const r046A = expr(ir_unop_i2u, r0469);
                        body.emit(assign(r0453, bit_or(r01D5, r046A), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0466->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r046C = less(r0452, body.constant(int(64)));
                        ir_if *f046B = new(mem_ctx) ir_if(operand(r046C).val);
                        exec_list *const f046B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f046B->then_instructions;

                           ir_expression *const r046D = bit_and(r0452, body.constant(int(31)));
                           ir_expression *const r046E = rshift(r01D5, r046D);
                           ir_expression *const r046F = lshift(r01D5, r0454);
                           ir_expression *const r0470 = bit_or(r046F, r036B);
                           ir_expression *const r0471 = nequal(r0470, body.constant(0u));
                           ir_expression *const r0472 = expr(ir_unop_b2i, r0471);
                           ir_expression *const r0473 = expr(ir_unop_i2u, r0472);
                           body.emit(assign(r0453, bit_or(r046E, r0473), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f046B->else_instructions;

                           ir_expression *const r0474 = bit_or(r01D5, r036B);
                           ir_expression *const r0475 = nequal(r0474, body.constant(0u));
                           ir_expression *const r0476 = expr(ir_unop_b2i, r0475);
                           body.emit(assign(r0453, expr(ir_unop_i2u, r0476), 0x01));


                        body.instructions = f046B_parent_instructions;
                        body.emit(f046B);

                        /* END IF */


                     body.instructions = f0466_parent_instructions;
                     body.emit(f0466);

                     /* END IF */


                  body.instructions = f045D_parent_instructions;
                  body.emit(f045D);

                  /* END IF */


               body.instructions = f045B_parent_instructions;
               body.emit(f045B);

               /* END IF */

               body.emit(assign(r01D5, r0456, 0x01));

               body.emit(assign(r01D6, r0453, 0x01));

               body.emit(assign(r01D3, bit_or(r01D3, body.constant(1073741824u)), 0x01));

               ir_variable *const r0477 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_expression *const r0478 = sub(r01D3, r0456);
               ir_expression *const r0479 = less(r01D4, r0453);
               ir_expression *const r047A = expr(ir_unop_b2i, r0479);
               ir_expression *const r047B = expr(ir_unop_i2u, r047A);
               body.emit(assign(r0477, sub(r0478, r047B), 0x01));

               body.emit(assign(r01D0, r0477, 0x01));

               body.emit(assign(r01D7, bit_xor(r01D8, body.constant(1u)), 0x01));

               body.emit(assign(r0369, add(r01E1, body.constant(int(-1))), 0x01));

               ir_variable *const r047C = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r047C, add(r0369, body.constant(int(-10))), 0x01));

               ir_variable *const r047D = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r047E = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r047F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r047F);
               ir_variable *const r0480 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0480);
               ir_expression *const r0481 = equal(r0477, body.constant(0u));
               ir_expression *const r0482 = add(r047C, body.constant(int(-32)));
               body.emit(assign(r047C, expr(ir_triop_csel, r0481, r0482, r047C), 0x01));

               ir_variable *const r0483 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0484 = equal(r0477, body.constant(0u));
               ir_expression *const r0485 = sub(r01D4, r0453);
               body.emit(assign(r0483, expr(ir_triop_csel, r0484, body.constant(0u), r0485), 0x01));

               body.emit(assign(r047E, r0483, 0x01));

               ir_variable *const r0486 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0487 = equal(r0477, body.constant(0u));
               body.emit(assign(r0486, expr(ir_triop_csel, r0487, r0483, r0477), 0x01));

               body.emit(assign(r047D, r0486, 0x01));

               ir_expression *const r0488 = equal(r0486, body.constant(0u));
               ir_expression *const r0489 = expr(ir_unop_find_msb, r0486);
               ir_expression *const r048A = sub(body.constant(int(31)), r0489);
               ir_expression *const r048B = expr(ir_triop_csel, r0488, body.constant(int(32)), r048A);
               body.emit(assign(r0480, add(r048B, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r048D = gequal(r0480, body.constant(int(0)));
               ir_if *f048C = new(mem_ctx) ir_if(operand(r048D).val);
               exec_list *const f048C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f048C->then_instructions;

                  body.emit(assign(r047F, body.constant(0u), 0x01));

                  ir_expression *const r048E = equal(r0480, body.constant(int(0)));
                  ir_expression *const r048F = lshift(r0486, r0480);
                  ir_expression *const r0490 = neg(r0480);
                  ir_expression *const r0491 = bit_and(r0490, body.constant(int(31)));
                  ir_expression *const r0492 = rshift(r0483, r0491);
                  ir_expression *const r0493 = bit_or(r048F, r0492);
                  body.emit(assign(r047D, expr(ir_triop_csel, r048E, r0486, r0493), 0x01));

                  body.emit(assign(r047E, lshift(r0483, r0480), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f048C->else_instructions;

                  ir_variable *const r0494 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r0494, body.constant(0u), 0x01));

                  ir_variable *const r0495 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r0495, neg(r0480), 0x01));

                  ir_variable *const r0496 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0496);
                  ir_variable *const r0497 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r0497);
                  ir_variable *const r0498 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r0498);
                  ir_variable *const r0499 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r049A = neg(r0495);
                  body.emit(assign(r0499, bit_and(r049A, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r049C = equal(r0495, body.constant(int(0)));
                  ir_if *f049B = new(mem_ctx) ir_if(operand(r049C).val);
                  exec_list *const f049B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f049B->then_instructions;

                     body.emit(assign(r0496, r0494, 0x01));

                     body.emit(assign(r0497, r047E, 0x01));

                     body.emit(assign(r0498, r047D, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f049B->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r049E = less(r0495, body.constant(int(32)));
                     ir_if *f049D = new(mem_ctx) ir_if(operand(r049E).val);
                     exec_list *const f049D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f049D->then_instructions;

                        body.emit(assign(r0496, lshift(r047E, r0499), 0x01));

                        ir_expression *const r049F = lshift(r047D, r0499);
                        ir_expression *const r04A0 = rshift(r047E, r0495);
                        body.emit(assign(r0497, bit_or(r049F, r04A0), 0x01));

                        body.emit(assign(r0498, rshift(r047D, r0495), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f049D->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04A2 = equal(r0495, body.constant(int(32)));
                        ir_if *f04A1 = new(mem_ctx) ir_if(operand(r04A2).val);
                        exec_list *const f04A1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04A1->then_instructions;

                           body.emit(assign(r0496, r047E, 0x01));

                           body.emit(assign(r0497, r047D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04A1->else_instructions;

                           body.emit(assign(r0494, bit_or(body.constant(0u), r047E), 0x01));

                           ir_expression *const r04A3 = less(r0495, body.constant(int(64)));
                           ir_expression *const r04A4 = lshift(r047D, r0499);
                           ir_expression *const r04A5 = equal(r0495, body.constant(int(64)));
                           ir_expression *const r04A6 = nequal(r047D, body.constant(0u));
                           ir_expression *const r04A7 = expr(ir_unop_b2i, r04A6);
                           ir_expression *const r04A8 = expr(ir_unop_i2u, r04A7);
                           ir_expression *const r04A9 = expr(ir_triop_csel, r04A5, r047D, r04A8);
                           body.emit(assign(r0496, expr(ir_triop_csel, r04A3, r04A4, r04A9), 0x01));

                           ir_expression *const r04AA = less(r0495, body.constant(int(64)));
                           ir_expression *const r04AB = bit_and(r0495, body.constant(int(31)));
                           ir_expression *const r04AC = rshift(r047D, r04AB);
                           body.emit(assign(r0497, expr(ir_triop_csel, r04AA, r04AC, body.constant(0u)), 0x01));


                        body.instructions = f04A1_parent_instructions;
                        body.emit(f04A1);

                        /* END IF */

                        body.emit(assign(r0498, body.constant(0u), 0x01));


                     body.instructions = f049D_parent_instructions;
                     body.emit(f049D);

                     /* END IF */

                     ir_expression *const r04AD = nequal(r0494, body.constant(0u));
                     ir_expression *const r04AE = expr(ir_unop_b2i, r04AD);
                     ir_expression *const r04AF = expr(ir_unop_i2u, r04AE);
                     body.emit(assign(r0496, bit_or(r0496, r04AF), 0x01));


                  body.instructions = f049B_parent_instructions;
                  body.emit(f049B);

                  /* END IF */

                  body.emit(assign(r047D, r0498, 0x01));

                  body.emit(assign(r047E, r0497, 0x01));

                  body.emit(assign(r047F, r0496, 0x01));


               body.instructions = f048C_parent_instructions;
               body.emit(f048C);

               /* END IF */

               body.emit(assign(r047C, sub(r047C, r0480), 0x01));

               ir_variable *const r04B0 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04B0, r047C, 0x01));

               ir_variable *const r04B1 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04B1, r047D, 0x01));

               ir_variable *const r04B2 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04B2, r047E, 0x01));

               ir_variable *const r04B3 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r04B3, r047F, 0x01));

               ir_variable *const r04B4 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r04B4, body.constant(true), 0x01));

               ir_variable *const r04B5 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04B6 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r04B6);
               ir_expression *const r04B7 = expr(ir_unop_u2i, r047F);
               body.emit(assign(r04B6, less(r04B7, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04B9 = gequal(r047C, body.constant(int(2045)));
               ir_if *f04B8 = new(mem_ctx) ir_if(operand(r04B9).val);
               exec_list *const f04B8_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04B8->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04BB = less(body.constant(int(2045)), r047C);
                  ir_expression *const r04BC = equal(r047C, body.constant(int(2045)));
                  ir_expression *const r04BD = equal(body.constant(2097151u), r047D);
                  ir_expression *const r04BE = equal(body.constant(4294967295u), r047E);
                  ir_expression *const r04BF = logic_and(r04BD, r04BE);
                  ir_expression *const r04C0 = logic_and(r04BC, r04BF);
                  ir_expression *const r04C1 = logic_and(r04C0, r04B6);
                  ir_expression *const r04C2 = logic_or(r04BB, r04C1);
                  ir_if *f04BA = new(mem_ctx) ir_if(operand(r04C2).val);
                  exec_list *const f04BA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04BA->then_instructions;

                     ir_variable *const r04C3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r04C3);
                     ir_expression *const r04C4 = lshift(r01D7, body.constant(int(31)));
                     body.emit(assign(r04C3, add(r04C4, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r04C3, body.constant(0u), 0x01));

                     body.emit(assign(r04B5, r04C3, 0x03));

                     body.emit(assign(r04B4, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04BA->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04C6 = less(r047C, body.constant(int(0)));
                     ir_if *f04C5 = new(mem_ctx) ir_if(operand(r04C6).val);
                     exec_list *const f04C5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04C5->then_instructions;

                        ir_variable *const r04C7 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r04C7, r047F, 0x01));

                        ir_variable *const r04C8 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r04C8, neg(r047C), 0x01));

                        ir_variable *const r04C9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r04C9);
                        ir_variable *const r04CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r04CA);
                        ir_variable *const r04CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r04CB);
                        ir_variable *const r04CC = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r04CD = neg(r04C8);
                        body.emit(assign(r04CC, bit_and(r04CD, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r04CF = equal(r04C8, body.constant(int(0)));
                        ir_if *f04CE = new(mem_ctx) ir_if(operand(r04CF).val);
                        exec_list *const f04CE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04CE->then_instructions;

                           body.emit(assign(r04C9, r047F, 0x01));

                           body.emit(assign(r04CA, r047E, 0x01));

                           body.emit(assign(r04CB, r047D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04CE->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r04D1 = less(r04C8, body.constant(int(32)));
                           ir_if *f04D0 = new(mem_ctx) ir_if(operand(r04D1).val);
                           exec_list *const f04D0_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04D0->then_instructions;

                              body.emit(assign(r04C9, lshift(r047E, r04CC), 0x01));

                              ir_expression *const r04D2 = lshift(r047D, r04CC);
                              ir_expression *const r04D3 = rshift(r047E, r04C8);
                              body.emit(assign(r04CA, bit_or(r04D2, r04D3), 0x01));

                              body.emit(assign(r04CB, rshift(r047D, r04C8), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04D0->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r04D5 = equal(r04C8, body.constant(int(32)));
                              ir_if *f04D4 = new(mem_ctx) ir_if(operand(r04D5).val);
                              exec_list *const f04D4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04D4->then_instructions;

                                 body.emit(assign(r04C9, r047E, 0x01));

                                 body.emit(assign(r04CA, r047D, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04D4->else_instructions;

                                 body.emit(assign(r04C7, bit_or(r047F, r047E), 0x01));

                                 ir_expression *const r04D6 = less(r04C8, body.constant(int(64)));
                                 ir_expression *const r04D7 = lshift(r047D, r04CC);
                                 ir_expression *const r04D8 = equal(r04C8, body.constant(int(64)));
                                 ir_expression *const r04D9 = nequal(r047D, body.constant(0u));
                                 ir_expression *const r04DA = expr(ir_unop_b2i, r04D9);
                                 ir_expression *const r04DB = expr(ir_unop_i2u, r04DA);
                                 ir_expression *const r04DC = expr(ir_triop_csel, r04D8, r047D, r04DB);
                                 body.emit(assign(r04C9, expr(ir_triop_csel, r04D6, r04D7, r04DC), 0x01));

                                 ir_expression *const r04DD = less(r04C8, body.constant(int(64)));
                                 ir_expression *const r04DE = bit_and(r04C8, body.constant(int(31)));
                                 ir_expression *const r04DF = rshift(r047D, r04DE);
                                 body.emit(assign(r04CA, expr(ir_triop_csel, r04DD, r04DF, body.constant(0u)), 0x01));


                              body.instructions = f04D4_parent_instructions;
                              body.emit(f04D4);

                              /* END IF */

                              body.emit(assign(r04CB, body.constant(0u), 0x01));


                           body.instructions = f04D0_parent_instructions;
                           body.emit(f04D0);

                           /* END IF */

                           ir_expression *const r04E0 = nequal(r04C7, body.constant(0u));
                           ir_expression *const r04E1 = expr(ir_unop_b2i, r04E0);
                           ir_expression *const r04E2 = expr(ir_unop_i2u, r04E1);
                           body.emit(assign(r04C9, bit_or(r04C9, r04E2), 0x01));


                        body.instructions = f04CE_parent_instructions;
                        body.emit(f04CE);

                        /* END IF */

                        body.emit(assign(r04B1, r04CB, 0x01));

                        body.emit(assign(r04B2, r04CA, 0x01));

                        body.emit(assign(r04B3, r04C9, 0x01));

                        body.emit(assign(r04B0, body.constant(int(0)), 0x01));

                        body.emit(assign(r04B6, less(r04C9, body.constant(0u)), 0x01));


                     body.instructions = f04C5_parent_instructions;
                     body.emit(f04C5);

                     /* END IF */


                  body.instructions = f04BA_parent_instructions;
                  body.emit(f04BA);

                  /* END IF */


               body.instructions = f04B8_parent_instructions;
               body.emit(f04B8);

               /* END IF */

               /* IF CONDITION */
               ir_if *f04E3 = new(mem_ctx) ir_if(operand(r04B4).val);
               exec_list *const f04E3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04E3->then_instructions;

                  /* IF CONDITION */
                  ir_if *f04E4 = new(mem_ctx) ir_if(operand(r04B6).val);
                  exec_list *const f04E4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04E4->then_instructions;

                     ir_variable *const r04E5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r04E5, add(r04B2, body.constant(1u)), 0x01));

                     ir_expression *const r04E6 = less(r04E5, r04B2);
                     ir_expression *const r04E7 = expr(ir_unop_b2i, r04E6);
                     ir_expression *const r04E8 = expr(ir_unop_i2u, r04E7);
                     body.emit(assign(r04B1, add(r04B1, r04E8), 0x01));

                     ir_expression *const r04E9 = equal(r04B3, body.constant(0u));
                     ir_expression *const r04EA = expr(ir_unop_b2i, r04E9);
                     ir_expression *const r04EB = expr(ir_unop_i2u, r04EA);
                     ir_expression *const r04EC = add(r04B3, r04EB);
                     ir_expression *const r04ED = bit_and(r04EC, body.constant(1u));
                     ir_expression *const r04EE = expr(ir_unop_bit_not, r04ED);
                     body.emit(assign(r04B2, bit_and(r04E5, r04EE), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04E4->else_instructions;

                     ir_expression *const r04EF = bit_or(r04B1, r04B2);
                     ir_expression *const r04F0 = equal(r04EF, body.constant(0u));
                     body.emit(assign(r04B0, expr(ir_triop_csel, r04F0, body.constant(int(0)), r04B0), 0x01));


                  body.instructions = f04E4_parent_instructions;
                  body.emit(f04E4);

                  /* END IF */

                  ir_variable *const r04F1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r04F1);
                  ir_expression *const r04F2 = lshift(r01D7, body.constant(int(31)));
                  ir_expression *const r04F3 = expr(ir_unop_i2u, r04B0);
                  ir_expression *const r04F4 = lshift(r04F3, body.constant(int(20)));
                  ir_expression *const r04F5 = add(r04F2, r04F4);
                  body.emit(assign(r04F1, add(r04F5, r04B1), 0x02));

                  body.emit(assign(r04F1, r04B2, 0x01));

                  body.emit(assign(r04B5, r04F1, 0x03));

                  body.emit(assign(r04B4, body.constant(false), 0x01));


               body.instructions = f04E3_parent_instructions;
               body.emit(f04E3);

               /* END IF */

               body.emit(assign(r01CE, r04B5, 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


            body.instructions = f0434_parent_instructions;
            body.emit(f0434);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0432->else_instructions;

            /* IF CONDITION */
            ir_expression *const r04F7 = equal(r01DE, body.constant(int(2047)));
            ir_if *f04F6 = new(mem_ctx) ir_if(operand(r04F7).val);
            exec_list *const f04F6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f04F6->then_instructions;

               ir_variable *const r04F8 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r04F8, swizzle_x(r01CB), 0x01));

               ir_variable *const r04F9 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r04F9, swizzle_x(r01CC), 0x01));

               body.emit(assign(r04F8, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r04F9, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r04FA = bit_or(r01D5, r01D6);
               ir_expression *const r04FB = bit_or(r01D3, r01D4);
               ir_expression *const r04FC = bit_or(r04FA, r04FB);
               ir_expression *const r04FD = nequal(r04FC, body.constant(0u));
               ir_swizzle *const r04FE = swizzle(r04FD, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r04FF = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r0500 = gequal(r04FF, body.constant(4292870144u));
               ir_expression *const r0501 = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r0502 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r0503 = nequal(r0502, body.constant(0u));
               ir_expression *const r0504 = logic_or(r0501, r0503);
               ir_expression *const r0505 = logic_and(r0500, r0504);
               ir_swizzle *const r0506 = swizzle(r0505, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0507 = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r0508 = gequal(r0507, body.constant(4292870144u));
               ir_expression *const r0509 = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r050A = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r050B = nequal(r050A, body.constant(0u));
               ir_expression *const r050C = logic_or(r0509, r050B);
               ir_expression *const r050D = logic_and(r0508, r050C);
               ir_swizzle *const r050E = swizzle(r050D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r050F = expr(ir_triop_csel, r050E, r04F9, r04F8);
               ir_expression *const r0510 = expr(ir_triop_csel, r0506, r050F, r04F9);
               ir_constant_data r0511_data;
               memset(&r0511_data, 0, sizeof(ir_constant_data));
               r0511_data.u[0] = 4294967295;
               r0511_data.u[1] = 4294967295;
               ir_constant *const r0511 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0511_data);
               body.emit(assign(r01CE, expr(ir_triop_csel, r04FE, r0510, r0511), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f04F6->else_instructions;

               ir_expression *const r0512 = equal(r01DE, body.constant(int(0)));
               body.emit(assign(r01D1, expr(ir_triop_csel, r0512, body.constant(int(1)), r01E1), 0x01));

               ir_expression *const r0513 = equal(r01DE, body.constant(int(0)));
               body.emit(assign(r01D2, expr(ir_triop_csel, r0513, body.constant(int(1)), r01DE), 0x01));

               /* IF CONDITION */
               ir_expression *const r0515 = less(r01D3, r01D5);
               ir_if *f0514 = new(mem_ctx) ir_if(operand(r0515).val);
               exec_list *const f0514_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0514->then_instructions;

                  ir_variable *const r0516 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_expression *const r0517 = sub(r01D5, r01D3);
                  ir_expression *const r0518 = less(r01D6, r01D4);
                  ir_expression *const r0519 = expr(ir_unop_b2i, r0518);
                  ir_expression *const r051A = expr(ir_unop_i2u, r0519);
                  body.emit(assign(r0516, sub(r0517, r051A), 0x01));

                  body.emit(assign(r01D0, r0516, 0x01));

                  body.emit(assign(r0369, add(r01D2, body.constant(int(-1))), 0x01));

                  ir_variable *const r051B = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r051B, add(r0369, body.constant(int(-10))), 0x01));

                  ir_variable *const r051C = body.make_temp(glsl_type::uint_type, "zFrac0");
                  ir_variable *const r051D = body.make_temp(glsl_type::uint_type, "zFrac1");
                  ir_variable *const r051E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r051E);
                  ir_variable *const r051F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r051F);
                  ir_expression *const r0520 = equal(r0516, body.constant(0u));
                  ir_expression *const r0521 = add(r051B, body.constant(int(-32)));
                  body.emit(assign(r051B, expr(ir_triop_csel, r0520, r0521, r051B), 0x01));

                  ir_variable *const r0522 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0523 = equal(r0516, body.constant(0u));
                  ir_expression *const r0524 = sub(r01D6, r01D4);
                  body.emit(assign(r0522, expr(ir_triop_csel, r0523, body.constant(0u), r0524), 0x01));

                  body.emit(assign(r051D, r0522, 0x01));

                  ir_variable *const r0525 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0526 = equal(r0516, body.constant(0u));
                  body.emit(assign(r0525, expr(ir_triop_csel, r0526, r0522, r0516), 0x01));

                  body.emit(assign(r051C, r0525, 0x01));

                  ir_expression *const r0527 = equal(r0525, body.constant(0u));
                  ir_expression *const r0528 = expr(ir_unop_find_msb, r0525);
                  ir_expression *const r0529 = sub(body.constant(int(31)), r0528);
                  ir_expression *const r052A = expr(ir_triop_csel, r0527, body.constant(int(32)), r0529);
                  body.emit(assign(r051F, add(r052A, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r052C = gequal(r051F, body.constant(int(0)));
                  ir_if *f052B = new(mem_ctx) ir_if(operand(r052C).val);
                  exec_list *const f052B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f052B->then_instructions;

                     body.emit(assign(r051E, body.constant(0u), 0x01));

                     ir_expression *const r052D = equal(r051F, body.constant(int(0)));
                     ir_expression *const r052E = lshift(r0525, r051F);
                     ir_expression *const r052F = neg(r051F);
                     ir_expression *const r0530 = bit_and(r052F, body.constant(int(31)));
                     ir_expression *const r0531 = rshift(r0522, r0530);
                     ir_expression *const r0532 = bit_or(r052E, r0531);
                     body.emit(assign(r051C, expr(ir_triop_csel, r052D, r0525, r0532), 0x01));

                     body.emit(assign(r051D, lshift(r0522, r051F), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f052B->else_instructions;

                     ir_variable *const r0533 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0533, body.constant(0u), 0x01));

                     ir_variable *const r0534 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0534, neg(r051F), 0x01));

                     ir_variable *const r0535 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0535);
                     ir_variable *const r0536 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0536);
                     ir_variable *const r0537 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0537);
                     ir_variable *const r0538 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0539 = neg(r0534);
                     body.emit(assign(r0538, bit_and(r0539, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r053B = equal(r0534, body.constant(int(0)));
                     ir_if *f053A = new(mem_ctx) ir_if(operand(r053B).val);
                     exec_list *const f053A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f053A->then_instructions;

                        body.emit(assign(r0535, r0533, 0x01));

                        body.emit(assign(r0536, r051D, 0x01));

                        body.emit(assign(r0537, r051C, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f053A->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r053D = less(r0534, body.constant(int(32)));
                        ir_if *f053C = new(mem_ctx) ir_if(operand(r053D).val);
                        exec_list *const f053C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f053C->then_instructions;

                           body.emit(assign(r0535, lshift(r051D, r0538), 0x01));

                           ir_expression *const r053E = lshift(r051C, r0538);
                           ir_expression *const r053F = rshift(r051D, r0534);
                           body.emit(assign(r0536, bit_or(r053E, r053F), 0x01));

                           body.emit(assign(r0537, rshift(r051C, r0534), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f053C->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0541 = equal(r0534, body.constant(int(32)));
                           ir_if *f0540 = new(mem_ctx) ir_if(operand(r0541).val);
                           exec_list *const f0540_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0540->then_instructions;

                              body.emit(assign(r0535, r051D, 0x01));

                              body.emit(assign(r0536, r051C, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0540->else_instructions;

                              body.emit(assign(r0533, bit_or(body.constant(0u), r051D), 0x01));

                              ir_expression *const r0542 = less(r0534, body.constant(int(64)));
                              ir_expression *const r0543 = lshift(r051C, r0538);
                              ir_expression *const r0544 = equal(r0534, body.constant(int(64)));
                              ir_expression *const r0545 = nequal(r051C, body.constant(0u));
                              ir_expression *const r0546 = expr(ir_unop_b2i, r0545);
                              ir_expression *const r0547 = expr(ir_unop_i2u, r0546);
                              ir_expression *const r0548 = expr(ir_triop_csel, r0544, r051C, r0547);
                              body.emit(assign(r0535, expr(ir_triop_csel, r0542, r0543, r0548), 0x01));

                              ir_expression *const r0549 = less(r0534, body.constant(int(64)));
                              ir_expression *const r054A = bit_and(r0534, body.constant(int(31)));
                              ir_expression *const r054B = rshift(r051C, r054A);
                              body.emit(assign(r0536, expr(ir_triop_csel, r0549, r054B, body.constant(0u)), 0x01));


                           body.instructions = f0540_parent_instructions;
                           body.emit(f0540);

                           /* END IF */

                           body.emit(assign(r0537, body.constant(0u), 0x01));


                        body.instructions = f053C_parent_instructions;
                        body.emit(f053C);

                        /* END IF */

                        ir_expression *const r054C = nequal(r0533, body.constant(0u));
                        ir_expression *const r054D = expr(ir_unop_b2i, r054C);
                        ir_expression *const r054E = expr(ir_unop_i2u, r054D);
                        body.emit(assign(r0535, bit_or(r0535, r054E), 0x01));


                     body.instructions = f053A_parent_instructions;
                     body.emit(f053A);

                     /* END IF */

                     body.emit(assign(r051C, r0537, 0x01));

                     body.emit(assign(r051D, r0536, 0x01));

                     body.emit(assign(r051E, r0535, 0x01));


                  body.instructions = f052B_parent_instructions;
                  body.emit(f052B);

                  /* END IF */

                  body.emit(assign(r051B, sub(r051B, r051F), 0x01));

                  ir_variable *const r054F = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r054F, r051B, 0x01));

                  ir_variable *const r0550 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0550, r051C, 0x01));

                  ir_variable *const r0551 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0551, r051D, 0x01));

                  ir_variable *const r0552 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0552, r051E, 0x01));

                  ir_variable *const r0553 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0553, body.constant(true), 0x01));

                  ir_variable *const r0554 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0555 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r0555);
                  ir_expression *const r0556 = expr(ir_unop_u2i, r051E);
                  body.emit(assign(r0555, less(r0556, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0558 = gequal(r051B, body.constant(int(2045)));
                  ir_if *f0557 = new(mem_ctx) ir_if(operand(r0558).val);
                  exec_list *const f0557_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0557->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r055A = less(body.constant(int(2045)), r051B);
                     ir_expression *const r055B = equal(r051B, body.constant(int(2045)));
                     ir_expression *const r055C = equal(body.constant(2097151u), r051C);
                     ir_expression *const r055D = equal(body.constant(4294967295u), r051D);
                     ir_expression *const r055E = logic_and(r055C, r055D);
                     ir_expression *const r055F = logic_and(r055B, r055E);
                     ir_expression *const r0560 = logic_and(r055F, r0555);
                     ir_expression *const r0561 = logic_or(r055A, r0560);
                     ir_if *f0559 = new(mem_ctx) ir_if(operand(r0561).val);
                     exec_list *const f0559_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0559->then_instructions;

                        ir_variable *const r0562 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0562);
                        ir_expression *const r0563 = lshift(r01D7, body.constant(int(31)));
                        body.emit(assign(r0562, add(r0563, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0562, body.constant(0u), 0x01));

                        body.emit(assign(r0554, r0562, 0x03));

                        body.emit(assign(r0553, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0559->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0565 = less(r051B, body.constant(int(0)));
                        ir_if *f0564 = new(mem_ctx) ir_if(operand(r0565).val);
                        exec_list *const f0564_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0564->then_instructions;

                           ir_variable *const r0566 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0566, r051E, 0x01));

                           ir_variable *const r0567 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0567, neg(r051B), 0x01));

                           ir_variable *const r0568 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0568);
                           ir_variable *const r0569 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0569);
                           ir_variable *const r056A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r056A);
                           ir_variable *const r056B = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r056C = neg(r0567);
                           body.emit(assign(r056B, bit_and(r056C, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r056E = equal(r0567, body.constant(int(0)));
                           ir_if *f056D = new(mem_ctx) ir_if(operand(r056E).val);
                           exec_list *const f056D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f056D->then_instructions;

                              body.emit(assign(r0568, r051E, 0x01));

                              body.emit(assign(r0569, r051D, 0x01));

                              body.emit(assign(r056A, r051C, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f056D->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0570 = less(r0567, body.constant(int(32)));
                              ir_if *f056F = new(mem_ctx) ir_if(operand(r0570).val);
                              exec_list *const f056F_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f056F->then_instructions;

                                 body.emit(assign(r0568, lshift(r051D, r056B), 0x01));

                                 ir_expression *const r0571 = lshift(r051C, r056B);
                                 ir_expression *const r0572 = rshift(r051D, r0567);
                                 body.emit(assign(r0569, bit_or(r0571, r0572), 0x01));

                                 body.emit(assign(r056A, rshift(r051C, r0567), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f056F->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0574 = equal(r0567, body.constant(int(32)));
                                 ir_if *f0573 = new(mem_ctx) ir_if(operand(r0574).val);
                                 exec_list *const f0573_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0573->then_instructions;

                                    body.emit(assign(r0568, r051D, 0x01));

                                    body.emit(assign(r0569, r051C, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0573->else_instructions;

                                    body.emit(assign(r0566, bit_or(r051E, r051D), 0x01));

                                    ir_expression *const r0575 = less(r0567, body.constant(int(64)));
                                    ir_expression *const r0576 = lshift(r051C, r056B);
                                    ir_expression *const r0577 = equal(r0567, body.constant(int(64)));
                                    ir_expression *const r0578 = nequal(r051C, body.constant(0u));
                                    ir_expression *const r0579 = expr(ir_unop_b2i, r0578);
                                    ir_expression *const r057A = expr(ir_unop_i2u, r0579);
                                    ir_expression *const r057B = expr(ir_triop_csel, r0577, r051C, r057A);
                                    body.emit(assign(r0568, expr(ir_triop_csel, r0575, r0576, r057B), 0x01));

                                    ir_expression *const r057C = less(r0567, body.constant(int(64)));
                                    ir_expression *const r057D = bit_and(r0567, body.constant(int(31)));
                                    ir_expression *const r057E = rshift(r051C, r057D);
                                    body.emit(assign(r0569, expr(ir_triop_csel, r057C, r057E, body.constant(0u)), 0x01));


                                 body.instructions = f0573_parent_instructions;
                                 body.emit(f0573);

                                 /* END IF */

                                 body.emit(assign(r056A, body.constant(0u), 0x01));


                              body.instructions = f056F_parent_instructions;
                              body.emit(f056F);

                              /* END IF */

                              ir_expression *const r057F = nequal(r0566, body.constant(0u));
                              ir_expression *const r0580 = expr(ir_unop_b2i, r057F);
                              ir_expression *const r0581 = expr(ir_unop_i2u, r0580);
                              body.emit(assign(r0568, bit_or(r0568, r0581), 0x01));


                           body.instructions = f056D_parent_instructions;
                           body.emit(f056D);

                           /* END IF */

                           body.emit(assign(r0550, r056A, 0x01));

                           body.emit(assign(r0551, r0569, 0x01));

                           body.emit(assign(r0552, r0568, 0x01));

                           body.emit(assign(r054F, body.constant(int(0)), 0x01));

                           body.emit(assign(r0555, less(r0568, body.constant(0u)), 0x01));


                        body.instructions = f0564_parent_instructions;
                        body.emit(f0564);

                        /* END IF */


                     body.instructions = f0559_parent_instructions;
                     body.emit(f0559);

                     /* END IF */


                  body.instructions = f0557_parent_instructions;
                  body.emit(f0557);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0582 = new(mem_ctx) ir_if(operand(r0553).val);
                  exec_list *const f0582_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0582->then_instructions;

                     /* IF CONDITION */
                     ir_if *f0583 = new(mem_ctx) ir_if(operand(r0555).val);
                     exec_list *const f0583_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0583->then_instructions;

                        ir_variable *const r0584 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r0584, add(r0551, body.constant(1u)), 0x01));

                        ir_expression *const r0585 = less(r0584, r0551);
                        ir_expression *const r0586 = expr(ir_unop_b2i, r0585);
                        ir_expression *const r0587 = expr(ir_unop_i2u, r0586);
                        body.emit(assign(r0550, add(r0550, r0587), 0x01));

                        ir_expression *const r0588 = equal(r0552, body.constant(0u));
                        ir_expression *const r0589 = expr(ir_unop_b2i, r0588);
                        ir_expression *const r058A = expr(ir_unop_i2u, r0589);
                        ir_expression *const r058B = add(r0552, r058A);
                        ir_expression *const r058C = bit_and(r058B, body.constant(1u));
                        ir_expression *const r058D = expr(ir_unop_bit_not, r058C);
                        body.emit(assign(r0551, bit_and(r0584, r058D), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0583->else_instructions;

                        ir_expression *const r058E = bit_or(r0550, r0551);
                        ir_expression *const r058F = equal(r058E, body.constant(0u));
                        body.emit(assign(r054F, expr(ir_triop_csel, r058F, body.constant(int(0)), r054F), 0x01));


                     body.instructions = f0583_parent_instructions;
                     body.emit(f0583);

                     /* END IF */

                     ir_variable *const r0590 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0590);
                     ir_expression *const r0591 = lshift(r01D7, body.constant(int(31)));
                     ir_expression *const r0592 = expr(ir_unop_i2u, r054F);
                     ir_expression *const r0593 = lshift(r0592, body.constant(int(20)));
                     ir_expression *const r0594 = add(r0591, r0593);
                     body.emit(assign(r0590, add(r0594, r0550), 0x02));

                     body.emit(assign(r0590, r0551, 0x01));

                     body.emit(assign(r0554, r0590, 0x03));

                     body.emit(assign(r0553, body.constant(false), 0x01));


                  body.instructions = f0582_parent_instructions;
                  body.emit(f0582);

                  /* END IF */

                  body.emit(assign(r01CE, r0554, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0514->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0596 = less(r01D5, r01D3);
                  ir_if *f0595 = new(mem_ctx) ir_if(operand(r0596).val);
                  exec_list *const f0595_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0595->then_instructions;

                     ir_variable *const r0597 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_expression *const r0598 = sub(r01D3, r01D5);
                     ir_expression *const r0599 = less(r01D4, r01D6);
                     ir_expression *const r059A = expr(ir_unop_b2i, r0599);
                     ir_expression *const r059B = expr(ir_unop_i2u, r059A);
                     body.emit(assign(r0597, sub(r0598, r059B), 0x01));

                     body.emit(assign(r01D0, r0597, 0x01));

                     body.emit(assign(r01D7, bit_xor(r01D7, body.constant(1u)), 0x01));

                     body.emit(assign(r0369, add(r01D1, body.constant(int(-1))), 0x01));

                     ir_variable *const r059C = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r059C, add(r0369, body.constant(int(-10))), 0x01));

                     ir_variable *const r059D = body.make_temp(glsl_type::uint_type, "zFrac0");
                     ir_variable *const r059E = body.make_temp(glsl_type::uint_type, "zFrac1");
                     ir_variable *const r059F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r059F);
                     ir_variable *const r05A0 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05A0);
                     ir_expression *const r05A1 = equal(r0597, body.constant(0u));
                     ir_expression *const r05A2 = add(r059C, body.constant(int(-32)));
                     body.emit(assign(r059C, expr(ir_triop_csel, r05A1, r05A2, r059C), 0x01));

                     ir_variable *const r05A3 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05A4 = equal(r0597, body.constant(0u));
                     ir_expression *const r05A5 = sub(r01D4, r01D6);
                     body.emit(assign(r05A3, expr(ir_triop_csel, r05A4, body.constant(0u), r05A5), 0x01));

                     body.emit(assign(r059E, r05A3, 0x01));

                     ir_variable *const r05A6 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05A7 = equal(r0597, body.constant(0u));
                     body.emit(assign(r05A6, expr(ir_triop_csel, r05A7, r05A3, r0597), 0x01));

                     body.emit(assign(r059D, r05A6, 0x01));

                     ir_expression *const r05A8 = equal(r05A6, body.constant(0u));
                     ir_expression *const r05A9 = expr(ir_unop_find_msb, r05A6);
                     ir_expression *const r05AA = sub(body.constant(int(31)), r05A9);
                     ir_expression *const r05AB = expr(ir_triop_csel, r05A8, body.constant(int(32)), r05AA);
                     body.emit(assign(r05A0, add(r05AB, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05AD = gequal(r05A0, body.constant(int(0)));
                     ir_if *f05AC = new(mem_ctx) ir_if(operand(r05AD).val);
                     exec_list *const f05AC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05AC->then_instructions;

                        body.emit(assign(r059F, body.constant(0u), 0x01));

                        ir_expression *const r05AE = equal(r05A0, body.constant(int(0)));
                        ir_expression *const r05AF = lshift(r05A6, r05A0);
                        ir_expression *const r05B0 = neg(r05A0);
                        ir_expression *const r05B1 = bit_and(r05B0, body.constant(int(31)));
                        ir_expression *const r05B2 = rshift(r05A3, r05B1);
                        ir_expression *const r05B3 = bit_or(r05AF, r05B2);
                        body.emit(assign(r059D, expr(ir_triop_csel, r05AE, r05A6, r05B3), 0x01));

                        body.emit(assign(r059E, lshift(r05A3, r05A0), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05AC->else_instructions;

                        ir_variable *const r05B4 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r05B4, body.constant(0u), 0x01));

                        ir_variable *const r05B5 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r05B5, neg(r05A0), 0x01));

                        ir_variable *const r05B6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r05B6);
                        ir_variable *const r05B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r05B7);
                        ir_variable *const r05B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r05B8);
                        ir_variable *const r05B9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r05BA = neg(r05B5);
                        body.emit(assign(r05B9, bit_and(r05BA, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05BC = equal(r05B5, body.constant(int(0)));
                        ir_if *f05BB = new(mem_ctx) ir_if(operand(r05BC).val);
                        exec_list *const f05BB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05BB->then_instructions;

                           body.emit(assign(r05B6, r05B4, 0x01));

                           body.emit(assign(r05B7, r059E, 0x01));

                           body.emit(assign(r05B8, r059D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05BB->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05BE = less(r05B5, body.constant(int(32)));
                           ir_if *f05BD = new(mem_ctx) ir_if(operand(r05BE).val);
                           exec_list *const f05BD_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05BD->then_instructions;

                              body.emit(assign(r05B6, lshift(r059E, r05B9), 0x01));

                              ir_expression *const r05BF = lshift(r059D, r05B9);
                              ir_expression *const r05C0 = rshift(r059E, r05B5);
                              body.emit(assign(r05B7, bit_or(r05BF, r05C0), 0x01));

                              body.emit(assign(r05B8, rshift(r059D, r05B5), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05BD->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05C2 = equal(r05B5, body.constant(int(32)));
                              ir_if *f05C1 = new(mem_ctx) ir_if(operand(r05C2).val);
                              exec_list *const f05C1_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05C1->then_instructions;

                                 body.emit(assign(r05B6, r059E, 0x01));

                                 body.emit(assign(r05B7, r059D, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05C1->else_instructions;

                                 body.emit(assign(r05B4, bit_or(body.constant(0u), r059E), 0x01));

                                 ir_expression *const r05C3 = less(r05B5, body.constant(int(64)));
                                 ir_expression *const r05C4 = lshift(r059D, r05B9);
                                 ir_expression *const r05C5 = equal(r05B5, body.constant(int(64)));
                                 ir_expression *const r05C6 = nequal(r059D, body.constant(0u));
                                 ir_expression *const r05C7 = expr(ir_unop_b2i, r05C6);
                                 ir_expression *const r05C8 = expr(ir_unop_i2u, r05C7);
                                 ir_expression *const r05C9 = expr(ir_triop_csel, r05C5, r059D, r05C8);
                                 body.emit(assign(r05B6, expr(ir_triop_csel, r05C3, r05C4, r05C9), 0x01));

                                 ir_expression *const r05CA = less(r05B5, body.constant(int(64)));
                                 ir_expression *const r05CB = bit_and(r05B5, body.constant(int(31)));
                                 ir_expression *const r05CC = rshift(r059D, r05CB);
                                 body.emit(assign(r05B7, expr(ir_triop_csel, r05CA, r05CC, body.constant(0u)), 0x01));


                              body.instructions = f05C1_parent_instructions;
                              body.emit(f05C1);

                              /* END IF */

                              body.emit(assign(r05B8, body.constant(0u), 0x01));


                           body.instructions = f05BD_parent_instructions;
                           body.emit(f05BD);

                           /* END IF */

                           ir_expression *const r05CD = nequal(r05B4, body.constant(0u));
                           ir_expression *const r05CE = expr(ir_unop_b2i, r05CD);
                           ir_expression *const r05CF = expr(ir_unop_i2u, r05CE);
                           body.emit(assign(r05B6, bit_or(r05B6, r05CF), 0x01));


                        body.instructions = f05BB_parent_instructions;
                        body.emit(f05BB);

                        /* END IF */

                        body.emit(assign(r059D, r05B8, 0x01));

                        body.emit(assign(r059E, r05B7, 0x01));

                        body.emit(assign(r059F, r05B6, 0x01));


                     body.instructions = f05AC_parent_instructions;
                     body.emit(f05AC);

                     /* END IF */

                     body.emit(assign(r059C, sub(r059C, r05A0), 0x01));

                     ir_variable *const r05D0 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05D0, r059C, 0x01));

                     ir_variable *const r05D1 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r05D1, r059D, 0x01));

                     ir_variable *const r05D2 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r05D2, r059E, 0x01));

                     ir_variable *const r05D3 = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r05D3, r059F, 0x01));

                     ir_variable *const r05D4 = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r05D4, body.constant(true), 0x01));

                     ir_variable *const r05D5 = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r05D6 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r05D6);
                     ir_expression *const r05D7 = expr(ir_unop_u2i, r059F);
                     body.emit(assign(r05D6, less(r05D7, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05D9 = gequal(r059C, body.constant(int(2045)));
                     ir_if *f05D8 = new(mem_ctx) ir_if(operand(r05D9).val);
                     exec_list *const f05D8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05D8->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05DB = less(body.constant(int(2045)), r059C);
                        ir_expression *const r05DC = equal(r059C, body.constant(int(2045)));
                        ir_expression *const r05DD = equal(body.constant(2097151u), r059D);
                        ir_expression *const r05DE = equal(body.constant(4294967295u), r059E);
                        ir_expression *const r05DF = logic_and(r05DD, r05DE);
                        ir_expression *const r05E0 = logic_and(r05DC, r05DF);
                        ir_expression *const r05E1 = logic_and(r05E0, r05D6);
                        ir_expression *const r05E2 = logic_or(r05DB, r05E1);
                        ir_if *f05DA = new(mem_ctx) ir_if(operand(r05E2).val);
                        exec_list *const f05DA_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05DA->then_instructions;

                           ir_variable *const r05E3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r05E3);
                           ir_expression *const r05E4 = lshift(r01D7, body.constant(int(31)));
                           body.emit(assign(r05E3, add(r05E4, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r05E3, body.constant(0u), 0x01));

                           body.emit(assign(r05D5, r05E3, 0x03));

                           body.emit(assign(r05D4, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05DA->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05E6 = less(r059C, body.constant(int(0)));
                           ir_if *f05E5 = new(mem_ctx) ir_if(operand(r05E6).val);
                           exec_list *const f05E5_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05E5->then_instructions;

                              ir_variable *const r05E7 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r05E7, r059F, 0x01));

                              ir_variable *const r05E8 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r05E8, neg(r059C), 0x01));

                              ir_variable *const r05E9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r05E9);
                              ir_variable *const r05EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r05EA);
                              ir_variable *const r05EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r05EB);
                              ir_variable *const r05EC = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r05ED = neg(r05E8);
                              body.emit(assign(r05EC, bit_and(r05ED, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r05EF = equal(r05E8, body.constant(int(0)));
                              ir_if *f05EE = new(mem_ctx) ir_if(operand(r05EF).val);
                              exec_list *const f05EE_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05EE->then_instructions;

                                 body.emit(assign(r05E9, r059F, 0x01));

                                 body.emit(assign(r05EA, r059E, 0x01));

                                 body.emit(assign(r05EB, r059D, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05EE->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05F1 = less(r05E8, body.constant(int(32)));
                                 ir_if *f05F0 = new(mem_ctx) ir_if(operand(r05F1).val);
                                 exec_list *const f05F0_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05F0->then_instructions;

                                    body.emit(assign(r05E9, lshift(r059E, r05EC), 0x01));

                                    ir_expression *const r05F2 = lshift(r059D, r05EC);
                                    ir_expression *const r05F3 = rshift(r059E, r05E8);
                                    body.emit(assign(r05EA, bit_or(r05F2, r05F3), 0x01));

                                    body.emit(assign(r05EB, rshift(r059D, r05E8), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05F0->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r05F5 = equal(r05E8, body.constant(int(32)));
                                    ir_if *f05F4 = new(mem_ctx) ir_if(operand(r05F5).val);
                                    exec_list *const f05F4_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f05F4->then_instructions;

                                       body.emit(assign(r05E9, r059E, 0x01));

                                       body.emit(assign(r05EA, r059D, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f05F4->else_instructions;

                                       body.emit(assign(r05E7, bit_or(r059F, r059E), 0x01));

                                       ir_expression *const r05F6 = less(r05E8, body.constant(int(64)));
                                       ir_expression *const r05F7 = lshift(r059D, r05EC);
                                       ir_expression *const r05F8 = equal(r05E8, body.constant(int(64)));
                                       ir_expression *const r05F9 = nequal(r059D, body.constant(0u));
                                       ir_expression *const r05FA = expr(ir_unop_b2i, r05F9);
                                       ir_expression *const r05FB = expr(ir_unop_i2u, r05FA);
                                       ir_expression *const r05FC = expr(ir_triop_csel, r05F8, r059D, r05FB);
                                       body.emit(assign(r05E9, expr(ir_triop_csel, r05F6, r05F7, r05FC), 0x01));

                                       ir_expression *const r05FD = less(r05E8, body.constant(int(64)));
                                       ir_expression *const r05FE = bit_and(r05E8, body.constant(int(31)));
                                       ir_expression *const r05FF = rshift(r059D, r05FE);
                                       body.emit(assign(r05EA, expr(ir_triop_csel, r05FD, r05FF, body.constant(0u)), 0x01));


                                    body.instructions = f05F4_parent_instructions;
                                    body.emit(f05F4);

                                    /* END IF */

                                    body.emit(assign(r05EB, body.constant(0u), 0x01));


                                 body.instructions = f05F0_parent_instructions;
                                 body.emit(f05F0);

                                 /* END IF */

                                 ir_expression *const r0600 = nequal(r05E7, body.constant(0u));
                                 ir_expression *const r0601 = expr(ir_unop_b2i, r0600);
                                 ir_expression *const r0602 = expr(ir_unop_i2u, r0601);
                                 body.emit(assign(r05E9, bit_or(r05E9, r0602), 0x01));


                              body.instructions = f05EE_parent_instructions;
                              body.emit(f05EE);

                              /* END IF */

                              body.emit(assign(r05D1, r05EB, 0x01));

                              body.emit(assign(r05D2, r05EA, 0x01));

                              body.emit(assign(r05D3, r05E9, 0x01));

                              body.emit(assign(r05D0, body.constant(int(0)), 0x01));

                              body.emit(assign(r05D6, less(r05E9, body.constant(0u)), 0x01));


                           body.instructions = f05E5_parent_instructions;
                           body.emit(f05E5);

                           /* END IF */


                        body.instructions = f05DA_parent_instructions;
                        body.emit(f05DA);

                        /* END IF */


                     body.instructions = f05D8_parent_instructions;
                     body.emit(f05D8);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0603 = new(mem_ctx) ir_if(operand(r05D4).val);
                     exec_list *const f0603_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0603->then_instructions;

                        /* IF CONDITION */
                        ir_if *f0604 = new(mem_ctx) ir_if(operand(r05D6).val);
                        exec_list *const f0604_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0604->then_instructions;

                           ir_variable *const r0605 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r0605, add(r05D2, body.constant(1u)), 0x01));

                           ir_expression *const r0606 = less(r0605, r05D2);
                           ir_expression *const r0607 = expr(ir_unop_b2i, r0606);
                           ir_expression *const r0608 = expr(ir_unop_i2u, r0607);
                           body.emit(assign(r05D1, add(r05D1, r0608), 0x01));

                           ir_expression *const r0609 = equal(r05D3, body.constant(0u));
                           ir_expression *const r060A = expr(ir_unop_b2i, r0609);
                           ir_expression *const r060B = expr(ir_unop_i2u, r060A);
                           ir_expression *const r060C = add(r05D3, r060B);
                           ir_expression *const r060D = bit_and(r060C, body.constant(1u));
                           ir_expression *const r060E = expr(ir_unop_bit_not, r060D);
                           body.emit(assign(r05D2, bit_and(r0605, r060E), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0604->else_instructions;

                           ir_expression *const r060F = bit_or(r05D1, r05D2);
                           ir_expression *const r0610 = equal(r060F, body.constant(0u));
                           body.emit(assign(r05D0, expr(ir_triop_csel, r0610, body.constant(int(0)), r05D0), 0x01));


                        body.instructions = f0604_parent_instructions;
                        body.emit(f0604);

                        /* END IF */

                        ir_variable *const r0611 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0611);
                        ir_expression *const r0612 = lshift(r01D7, body.constant(int(31)));
                        ir_expression *const r0613 = expr(ir_unop_i2u, r05D0);
                        ir_expression *const r0614 = lshift(r0613, body.constant(int(20)));
                        ir_expression *const r0615 = add(r0612, r0614);
                        body.emit(assign(r0611, add(r0615, r05D1), 0x02));

                        body.emit(assign(r0611, r05D2, 0x01));

                        body.emit(assign(r05D5, r0611, 0x03));

                        body.emit(assign(r05D4, body.constant(false), 0x01));


                     body.instructions = f0603_parent_instructions;
                     body.emit(f0603);

                     /* END IF */

                     body.emit(assign(r01CE, r05D5, 0x03));

                     body.emit(assign(r01CD, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0595->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0617 = less(r01D4, r01D6);
                     ir_if *f0616 = new(mem_ctx) ir_if(operand(r0617).val);
                     exec_list *const f0616_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0616->then_instructions;

                        ir_variable *const r0618 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_expression *const r0619 = sub(r01D5, r01D3);
                        ir_expression *const r061A = less(r01D6, r01D4);
                        ir_expression *const r061B = expr(ir_unop_b2i, r061A);
                        ir_expression *const r061C = expr(ir_unop_i2u, r061B);
                        body.emit(assign(r0618, sub(r0619, r061C), 0x01));

                        body.emit(assign(r01D0, r0618, 0x01));

                        body.emit(assign(r0369, add(r01D2, body.constant(int(-1))), 0x01));

                        ir_variable *const r061D = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r061D, add(r0369, body.constant(int(-10))), 0x01));

                        ir_variable *const r061E = body.make_temp(glsl_type::uint_type, "zFrac0");
                        ir_variable *const r061F = body.make_temp(glsl_type::uint_type, "zFrac1");
                        ir_variable *const r0620 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0620);
                        ir_variable *const r0621 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0621);
                        ir_expression *const r0622 = equal(r0618, body.constant(0u));
                        ir_expression *const r0623 = add(r061D, body.constant(int(-32)));
                        body.emit(assign(r061D, expr(ir_triop_csel, r0622, r0623, r061D), 0x01));

                        ir_variable *const r0624 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0625 = equal(r0618, body.constant(0u));
                        ir_expression *const r0626 = sub(r01D6, r01D4);
                        body.emit(assign(r0624, expr(ir_triop_csel, r0625, body.constant(0u), r0626), 0x01));

                        body.emit(assign(r061F, r0624, 0x01));

                        ir_variable *const r0627 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0628 = equal(r0618, body.constant(0u));
                        body.emit(assign(r0627, expr(ir_triop_csel, r0628, r0624, r0618), 0x01));

                        body.emit(assign(r061E, r0627, 0x01));

                        ir_expression *const r0629 = equal(r0627, body.constant(0u));
                        ir_expression *const r062A = expr(ir_unop_find_msb, r0627);
                        ir_expression *const r062B = sub(body.constant(int(31)), r062A);
                        ir_expression *const r062C = expr(ir_triop_csel, r0629, body.constant(int(32)), r062B);
                        body.emit(assign(r0621, add(r062C, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r062E = gequal(r0621, body.constant(int(0)));
                        ir_if *f062D = new(mem_ctx) ir_if(operand(r062E).val);
                        exec_list *const f062D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f062D->then_instructions;

                           body.emit(assign(r0620, body.constant(0u), 0x01));

                           ir_expression *const r062F = equal(r0621, body.constant(int(0)));
                           ir_expression *const r0630 = lshift(r0627, r0621);
                           ir_expression *const r0631 = neg(r0621);
                           ir_expression *const r0632 = bit_and(r0631, body.constant(int(31)));
                           ir_expression *const r0633 = rshift(r0624, r0632);
                           ir_expression *const r0634 = bit_or(r0630, r0633);
                           body.emit(assign(r061E, expr(ir_triop_csel, r062F, r0627, r0634), 0x01));

                           body.emit(assign(r061F, lshift(r0624, r0621), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f062D->else_instructions;

                           ir_variable *const r0635 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0635, body.constant(0u), 0x01));

                           ir_variable *const r0636 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0636, neg(r0621), 0x01));

                           ir_variable *const r0637 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0637);
                           ir_variable *const r0638 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0638);
                           ir_variable *const r0639 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0639);
                           ir_variable *const r063A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r063B = neg(r0636);
                           body.emit(assign(r063A, bit_and(r063B, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r063D = equal(r0636, body.constant(int(0)));
                           ir_if *f063C = new(mem_ctx) ir_if(operand(r063D).val);
                           exec_list *const f063C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f063C->then_instructions;

                              body.emit(assign(r0637, r0635, 0x01));

                              body.emit(assign(r0638, r061F, 0x01));

                              body.emit(assign(r0639, r061E, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f063C->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r063F = less(r0636, body.constant(int(32)));
                              ir_if *f063E = new(mem_ctx) ir_if(operand(r063F).val);
                              exec_list *const f063E_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f063E->then_instructions;

                                 body.emit(assign(r0637, lshift(r061F, r063A), 0x01));

                                 ir_expression *const r0640 = lshift(r061E, r063A);
                                 ir_expression *const r0641 = rshift(r061F, r0636);
                                 body.emit(assign(r0638, bit_or(r0640, r0641), 0x01));

                                 body.emit(assign(r0639, rshift(r061E, r0636), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f063E->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0643 = equal(r0636, body.constant(int(32)));
                                 ir_if *f0642 = new(mem_ctx) ir_if(operand(r0643).val);
                                 exec_list *const f0642_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0642->then_instructions;

                                    body.emit(assign(r0637, r061F, 0x01));

                                    body.emit(assign(r0638, r061E, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0642->else_instructions;

                                    body.emit(assign(r0635, bit_or(body.constant(0u), r061F), 0x01));

                                    ir_expression *const r0644 = less(r0636, body.constant(int(64)));
                                    ir_expression *const r0645 = lshift(r061E, r063A);
                                    ir_expression *const r0646 = equal(r0636, body.constant(int(64)));
                                    ir_expression *const r0647 = nequal(r061E, body.constant(0u));
                                    ir_expression *const r0648 = expr(ir_unop_b2i, r0647);
                                    ir_expression *const r0649 = expr(ir_unop_i2u, r0648);
                                    ir_expression *const r064A = expr(ir_triop_csel, r0646, r061E, r0649);
                                    body.emit(assign(r0637, expr(ir_triop_csel, r0644, r0645, r064A), 0x01));

                                    ir_expression *const r064B = less(r0636, body.constant(int(64)));
                                    ir_expression *const r064C = bit_and(r0636, body.constant(int(31)));
                                    ir_expression *const r064D = rshift(r061E, r064C);
                                    body.emit(assign(r0638, expr(ir_triop_csel, r064B, r064D, body.constant(0u)), 0x01));


                                 body.instructions = f0642_parent_instructions;
                                 body.emit(f0642);

                                 /* END IF */

                                 body.emit(assign(r0639, body.constant(0u), 0x01));


                              body.instructions = f063E_parent_instructions;
                              body.emit(f063E);

                              /* END IF */

                              ir_expression *const r064E = nequal(r0635, body.constant(0u));
                              ir_expression *const r064F = expr(ir_unop_b2i, r064E);
                              ir_expression *const r0650 = expr(ir_unop_i2u, r064F);
                              body.emit(assign(r0637, bit_or(r0637, r0650), 0x01));


                           body.instructions = f063C_parent_instructions;
                           body.emit(f063C);

                           /* END IF */

                           body.emit(assign(r061E, r0639, 0x01));

                           body.emit(assign(r061F, r0638, 0x01));

                           body.emit(assign(r0620, r0637, 0x01));


                        body.instructions = f062D_parent_instructions;
                        body.emit(f062D);

                        /* END IF */

                        body.emit(assign(r061D, sub(r061D, r0621), 0x01));

                        ir_variable *const r0651 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0651, r061D, 0x01));

                        ir_variable *const r0652 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r0652, r061E, 0x01));

                        ir_variable *const r0653 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0653, r061F, 0x01));

                        ir_variable *const r0654 = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r0654, r0620, 0x01));

                        ir_variable *const r0655 = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r0655, body.constant(true), 0x01));

                        ir_variable *const r0656 = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r0657 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r0657);
                        ir_expression *const r0658 = expr(ir_unop_u2i, r0620);
                        body.emit(assign(r0657, less(r0658, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r065A = gequal(r061D, body.constant(int(2045)));
                        ir_if *f0659 = new(mem_ctx) ir_if(operand(r065A).val);
                        exec_list *const f0659_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0659->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r065C = less(body.constant(int(2045)), r061D);
                           ir_expression *const r065D = equal(r061D, body.constant(int(2045)));
                           ir_expression *const r065E = equal(body.constant(2097151u), r061E);
                           ir_expression *const r065F = equal(body.constant(4294967295u), r061F);
                           ir_expression *const r0660 = logic_and(r065E, r065F);
                           ir_expression *const r0661 = logic_and(r065D, r0660);
                           ir_expression *const r0662 = logic_and(r0661, r0657);
                           ir_expression *const r0663 = logic_or(r065C, r0662);
                           ir_if *f065B = new(mem_ctx) ir_if(operand(r0663).val);
                           exec_list *const f065B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f065B->then_instructions;

                              ir_variable *const r0664 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0664);
                              ir_expression *const r0665 = lshift(r01D7, body.constant(int(31)));
                              body.emit(assign(r0664, add(r0665, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r0664, body.constant(0u), 0x01));

                              body.emit(assign(r0656, r0664, 0x03));

                              body.emit(assign(r0655, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f065B->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0667 = less(r061D, body.constant(int(0)));
                              ir_if *f0666 = new(mem_ctx) ir_if(operand(r0667).val);
                              exec_list *const f0666_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0666->then_instructions;

                                 ir_variable *const r0668 = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r0668, r0620, 0x01));

                                 ir_variable *const r0669 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r0669, neg(r061D), 0x01));

                                 ir_variable *const r066A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r066A);
                                 ir_variable *const r066B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r066B);
                                 ir_variable *const r066C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r066C);
                                 ir_variable *const r066D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r066E = neg(r0669);
                                 body.emit(assign(r066D, bit_and(r066E, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0670 = equal(r0669, body.constant(int(0)));
                                 ir_if *f066F = new(mem_ctx) ir_if(operand(r0670).val);
                                 exec_list *const f066F_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f066F->then_instructions;

                                    body.emit(assign(r066A, r0620, 0x01));

                                    body.emit(assign(r066B, r061F, 0x01));

                                    body.emit(assign(r066C, r061E, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f066F->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0672 = less(r0669, body.constant(int(32)));
                                    ir_if *f0671 = new(mem_ctx) ir_if(operand(r0672).val);
                                    exec_list *const f0671_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0671->then_instructions;

                                       body.emit(assign(r066A, lshift(r061F, r066D), 0x01));

                                       ir_expression *const r0673 = lshift(r061E, r066D);
                                       ir_expression *const r0674 = rshift(r061F, r0669);
                                       body.emit(assign(r066B, bit_or(r0673, r0674), 0x01));

                                       body.emit(assign(r066C, rshift(r061E, r0669), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0671->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r0676 = equal(r0669, body.constant(int(32)));
                                       ir_if *f0675 = new(mem_ctx) ir_if(operand(r0676).val);
                                       exec_list *const f0675_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0675->then_instructions;

                                          body.emit(assign(r066A, r061F, 0x01));

                                          body.emit(assign(r066B, r061E, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0675->else_instructions;

                                          body.emit(assign(r0668, bit_or(r0620, r061F), 0x01));

                                          ir_expression *const r0677 = less(r0669, body.constant(int(64)));
                                          ir_expression *const r0678 = lshift(r061E, r066D);
                                          ir_expression *const r0679 = equal(r0669, body.constant(int(64)));
                                          ir_expression *const r067A = nequal(r061E, body.constant(0u));
                                          ir_expression *const r067B = expr(ir_unop_b2i, r067A);
                                          ir_expression *const r067C = expr(ir_unop_i2u, r067B);
                                          ir_expression *const r067D = expr(ir_triop_csel, r0679, r061E, r067C);
                                          body.emit(assign(r066A, expr(ir_triop_csel, r0677, r0678, r067D), 0x01));

                                          ir_expression *const r067E = less(r0669, body.constant(int(64)));
                                          ir_expression *const r067F = bit_and(r0669, body.constant(int(31)));
                                          ir_expression *const r0680 = rshift(r061E, r067F);
                                          body.emit(assign(r066B, expr(ir_triop_csel, r067E, r0680, body.constant(0u)), 0x01));


                                       body.instructions = f0675_parent_instructions;
                                       body.emit(f0675);

                                       /* END IF */

                                       body.emit(assign(r066C, body.constant(0u), 0x01));


                                    body.instructions = f0671_parent_instructions;
                                    body.emit(f0671);

                                    /* END IF */

                                    ir_expression *const r0681 = nequal(r0668, body.constant(0u));
                                    ir_expression *const r0682 = expr(ir_unop_b2i, r0681);
                                    ir_expression *const r0683 = expr(ir_unop_i2u, r0682);
                                    body.emit(assign(r066A, bit_or(r066A, r0683), 0x01));


                                 body.instructions = f066F_parent_instructions;
                                 body.emit(f066F);

                                 /* END IF */

                                 body.emit(assign(r0652, r066C, 0x01));

                                 body.emit(assign(r0653, r066B, 0x01));

                                 body.emit(assign(r0654, r066A, 0x01));

                                 body.emit(assign(r0651, body.constant(int(0)), 0x01));

                                 body.emit(assign(r0657, less(r066A, body.constant(0u)), 0x01));


                              body.instructions = f0666_parent_instructions;
                              body.emit(f0666);

                              /* END IF */


                           body.instructions = f065B_parent_instructions;
                           body.emit(f065B);

                           /* END IF */


                        body.instructions = f0659_parent_instructions;
                        body.emit(f0659);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f0684 = new(mem_ctx) ir_if(operand(r0655).val);
                        exec_list *const f0684_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0684->then_instructions;

                           /* IF CONDITION */
                           ir_if *f0685 = new(mem_ctx) ir_if(operand(r0657).val);
                           exec_list *const f0685_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0685->then_instructions;

                              ir_variable *const r0686 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r0686, add(r0653, body.constant(1u)), 0x01));

                              ir_expression *const r0687 = less(r0686, r0653);
                              ir_expression *const r0688 = expr(ir_unop_b2i, r0687);
                              ir_expression *const r0689 = expr(ir_unop_i2u, r0688);
                              body.emit(assign(r0652, add(r0652, r0689), 0x01));

                              ir_expression *const r068A = equal(r0654, body.constant(0u));
                              ir_expression *const r068B = expr(ir_unop_b2i, r068A);
                              ir_expression *const r068C = expr(ir_unop_i2u, r068B);
                              ir_expression *const r068D = add(r0654, r068C);
                              ir_expression *const r068E = bit_and(r068D, body.constant(1u));
                              ir_expression *const r068F = expr(ir_unop_bit_not, r068E);
                              body.emit(assign(r0653, bit_and(r0686, r068F), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0685->else_instructions;

                              ir_expression *const r0690 = bit_or(r0652, r0653);
                              ir_expression *const r0691 = equal(r0690, body.constant(0u));
                              body.emit(assign(r0651, expr(ir_triop_csel, r0691, body.constant(int(0)), r0651), 0x01));


                           body.instructions = f0685_parent_instructions;
                           body.emit(f0685);

                           /* END IF */

                           ir_variable *const r0692 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0692);
                           ir_expression *const r0693 = lshift(r01D7, body.constant(int(31)));
                           ir_expression *const r0694 = expr(ir_unop_i2u, r0651);
                           ir_expression *const r0695 = lshift(r0694, body.constant(int(20)));
                           ir_expression *const r0696 = add(r0693, r0695);
                           body.emit(assign(r0692, add(r0696, r0652), 0x02));

                           body.emit(assign(r0692, r0653, 0x01));

                           body.emit(assign(r0656, r0692, 0x03));

                           body.emit(assign(r0655, body.constant(false), 0x01));


                        body.instructions = f0684_parent_instructions;
                        body.emit(f0684);

                        /* END IF */

                        body.emit(assign(r01CE, r0656, 0x03));

                        body.emit(assign(r01CD, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0616->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0698 = less(r01D6, r01D4);
                        ir_if *f0697 = new(mem_ctx) ir_if(operand(r0698).val);
                        exec_list *const f0697_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0697->then_instructions;

                           ir_variable *const r0699 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_expression *const r069A = sub(r01D3, r01D5);
                           ir_expression *const r069B = less(r01D4, r01D6);
                           ir_expression *const r069C = expr(ir_unop_b2i, r069B);
                           ir_expression *const r069D = expr(ir_unop_i2u, r069C);
                           body.emit(assign(r0699, sub(r069A, r069D), 0x01));

                           body.emit(assign(r01D0, r0699, 0x01));

                           body.emit(assign(r01D7, bit_xor(r01D7, body.constant(1u)), 0x01));

                           body.emit(assign(r0369, add(r01D1, body.constant(int(-1))), 0x01));

                           ir_variable *const r069E = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r069E, add(r0369, body.constant(int(-10))), 0x01));

                           ir_variable *const r069F = body.make_temp(glsl_type::uint_type, "zFrac0");
                           ir_variable *const r06A0 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           ir_variable *const r06A1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r06A1);
                           ir_variable *const r06A2 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06A2);
                           ir_expression *const r06A3 = equal(r0699, body.constant(0u));
                           ir_expression *const r06A4 = add(r069E, body.constant(int(-32)));
                           body.emit(assign(r069E, expr(ir_triop_csel, r06A3, r06A4, r069E), 0x01));

                           ir_variable *const r06A5 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06A6 = equal(r0699, body.constant(0u));
                           ir_expression *const r06A7 = sub(r01D4, r01D6);
                           body.emit(assign(r06A5, expr(ir_triop_csel, r06A6, body.constant(0u), r06A7), 0x01));

                           body.emit(assign(r06A0, r06A5, 0x01));

                           ir_variable *const r06A8 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06A9 = equal(r0699, body.constant(0u));
                           body.emit(assign(r06A8, expr(ir_triop_csel, r06A9, r06A5, r0699), 0x01));

                           body.emit(assign(r069F, r06A8, 0x01));

                           ir_expression *const r06AA = equal(r06A8, body.constant(0u));
                           ir_expression *const r06AB = expr(ir_unop_find_msb, r06A8);
                           ir_expression *const r06AC = sub(body.constant(int(31)), r06AB);
                           ir_expression *const r06AD = expr(ir_triop_csel, r06AA, body.constant(int(32)), r06AC);
                           body.emit(assign(r06A2, add(r06AD, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06AF = gequal(r06A2, body.constant(int(0)));
                           ir_if *f06AE = new(mem_ctx) ir_if(operand(r06AF).val);
                           exec_list *const f06AE_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06AE->then_instructions;

                              body.emit(assign(r06A1, body.constant(0u), 0x01));

                              ir_expression *const r06B0 = equal(r06A2, body.constant(int(0)));
                              ir_expression *const r06B1 = lshift(r06A8, r06A2);
                              ir_expression *const r06B2 = neg(r06A2);
                              ir_expression *const r06B3 = bit_and(r06B2, body.constant(int(31)));
                              ir_expression *const r06B4 = rshift(r06A5, r06B3);
                              ir_expression *const r06B5 = bit_or(r06B1, r06B4);
                              body.emit(assign(r069F, expr(ir_triop_csel, r06B0, r06A8, r06B5), 0x01));

                              body.emit(assign(r06A0, lshift(r06A5, r06A2), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06AE->else_instructions;

                              ir_variable *const r06B6 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r06B6, body.constant(0u), 0x01));

                              ir_variable *const r06B7 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r06B7, neg(r06A2), 0x01));

                              ir_variable *const r06B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r06B8);
                              ir_variable *const r06B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r06B9);
                              ir_variable *const r06BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r06BA);
                              ir_variable *const r06BB = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r06BC = neg(r06B7);
                              body.emit(assign(r06BB, bit_and(r06BC, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r06BE = equal(r06B7, body.constant(int(0)));
                              ir_if *f06BD = new(mem_ctx) ir_if(operand(r06BE).val);
                              exec_list *const f06BD_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06BD->then_instructions;

                                 body.emit(assign(r06B8, r06B6, 0x01));

                                 body.emit(assign(r06B9, r06A0, 0x01));

                                 body.emit(assign(r06BA, r069F, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06BD->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06C0 = less(r06B7, body.constant(int(32)));
                                 ir_if *f06BF = new(mem_ctx) ir_if(operand(r06C0).val);
                                 exec_list *const f06BF_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06BF->then_instructions;

                                    body.emit(assign(r06B8, lshift(r06A0, r06BB), 0x01));

                                    ir_expression *const r06C1 = lshift(r069F, r06BB);
                                    ir_expression *const r06C2 = rshift(r06A0, r06B7);
                                    body.emit(assign(r06B9, bit_or(r06C1, r06C2), 0x01));

                                    body.emit(assign(r06BA, rshift(r069F, r06B7), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06BF->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06C4 = equal(r06B7, body.constant(int(32)));
                                    ir_if *f06C3 = new(mem_ctx) ir_if(operand(r06C4).val);
                                    exec_list *const f06C3_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06C3->then_instructions;

                                       body.emit(assign(r06B8, r06A0, 0x01));

                                       body.emit(assign(r06B9, r069F, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06C3->else_instructions;

                                       body.emit(assign(r06B6, bit_or(body.constant(0u), r06A0), 0x01));

                                       ir_expression *const r06C5 = less(r06B7, body.constant(int(64)));
                                       ir_expression *const r06C6 = lshift(r069F, r06BB);
                                       ir_expression *const r06C7 = equal(r06B7, body.constant(int(64)));
                                       ir_expression *const r06C8 = nequal(r069F, body.constant(0u));
                                       ir_expression *const r06C9 = expr(ir_unop_b2i, r06C8);
                                       ir_expression *const r06CA = expr(ir_unop_i2u, r06C9);
                                       ir_expression *const r06CB = expr(ir_triop_csel, r06C7, r069F, r06CA);
                                       body.emit(assign(r06B8, expr(ir_triop_csel, r06C5, r06C6, r06CB), 0x01));

                                       ir_expression *const r06CC = less(r06B7, body.constant(int(64)));
                                       ir_expression *const r06CD = bit_and(r06B7, body.constant(int(31)));
                                       ir_expression *const r06CE = rshift(r069F, r06CD);
                                       body.emit(assign(r06B9, expr(ir_triop_csel, r06CC, r06CE, body.constant(0u)), 0x01));


                                    body.instructions = f06C3_parent_instructions;
                                    body.emit(f06C3);

                                    /* END IF */

                                    body.emit(assign(r06BA, body.constant(0u), 0x01));


                                 body.instructions = f06BF_parent_instructions;
                                 body.emit(f06BF);

                                 /* END IF */

                                 ir_expression *const r06CF = nequal(r06B6, body.constant(0u));
                                 ir_expression *const r06D0 = expr(ir_unop_b2i, r06CF);
                                 ir_expression *const r06D1 = expr(ir_unop_i2u, r06D0);
                                 body.emit(assign(r06B8, bit_or(r06B8, r06D1), 0x01));


                              body.instructions = f06BD_parent_instructions;
                              body.emit(f06BD);

                              /* END IF */

                              body.emit(assign(r069F, r06BA, 0x01));

                              body.emit(assign(r06A0, r06B9, 0x01));

                              body.emit(assign(r06A1, r06B8, 0x01));


                           body.instructions = f06AE_parent_instructions;
                           body.emit(f06AE);

                           /* END IF */

                           body.emit(assign(r069E, sub(r069E, r06A2), 0x01));

                           ir_variable *const r06D2 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06D2, r069E, 0x01));

                           ir_variable *const r06D3 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r06D3, r069F, 0x01));

                           ir_variable *const r06D4 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r06D4, r06A0, 0x01));

                           ir_variable *const r06D5 = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r06D5, r06A1, 0x01));

                           ir_variable *const r06D6 = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r06D6, body.constant(true), 0x01));

                           ir_variable *const r06D7 = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r06D8 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r06D8);
                           ir_expression *const r06D9 = expr(ir_unop_u2i, r06A1);
                           body.emit(assign(r06D8, less(r06D9, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06DB = gequal(r069E, body.constant(int(2045)));
                           ir_if *f06DA = new(mem_ctx) ir_if(operand(r06DB).val);
                           exec_list *const f06DA_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06DA->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06DD = less(body.constant(int(2045)), r069E);
                              ir_expression *const r06DE = equal(r069E, body.constant(int(2045)));
                              ir_expression *const r06DF = equal(body.constant(2097151u), r069F);
                              ir_expression *const r06E0 = equal(body.constant(4294967295u), r06A0);
                              ir_expression *const r06E1 = logic_and(r06DF, r06E0);
                              ir_expression *const r06E2 = logic_and(r06DE, r06E1);
                              ir_expression *const r06E3 = logic_and(r06E2, r06D8);
                              ir_expression *const r06E4 = logic_or(r06DD, r06E3);
                              ir_if *f06DC = new(mem_ctx) ir_if(operand(r06E4).val);
                              exec_list *const f06DC_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06DC->then_instructions;

                                 ir_variable *const r06E5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r06E5);
                                 ir_expression *const r06E6 = lshift(r01D7, body.constant(int(31)));
                                 body.emit(assign(r06E5, add(r06E6, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r06E5, body.constant(0u), 0x01));

                                 body.emit(assign(r06D7, r06E5, 0x03));

                                 body.emit(assign(r06D6, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06DC->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06E8 = less(r069E, body.constant(int(0)));
                                 ir_if *f06E7 = new(mem_ctx) ir_if(operand(r06E8).val);
                                 exec_list *const f06E7_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06E7->then_instructions;

                                    ir_variable *const r06E9 = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r06E9, r06A1, 0x01));

                                    ir_variable *const r06EA = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r06EA, neg(r069E), 0x01));

                                    ir_variable *const r06EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r06EB);
                                    ir_variable *const r06EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r06EC);
                                    ir_variable *const r06ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r06ED);
                                    ir_variable *const r06EE = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r06EF = neg(r06EA);
                                    body.emit(assign(r06EE, bit_and(r06EF, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r06F1 = equal(r06EA, body.constant(int(0)));
                                    ir_if *f06F0 = new(mem_ctx) ir_if(operand(r06F1).val);
                                    exec_list *const f06F0_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06F0->then_instructions;

                                       body.emit(assign(r06EB, r06A1, 0x01));

                                       body.emit(assign(r06EC, r06A0, 0x01));

                                       body.emit(assign(r06ED, r069F, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06F0->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r06F3 = less(r06EA, body.constant(int(32)));
                                       ir_if *f06F2 = new(mem_ctx) ir_if(operand(r06F3).val);
                                       exec_list *const f06F2_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06F2->then_instructions;

                                          body.emit(assign(r06EB, lshift(r06A0, r06EE), 0x01));

                                          ir_expression *const r06F4 = lshift(r069F, r06EE);
                                          ir_expression *const r06F5 = rshift(r06A0, r06EA);
                                          body.emit(assign(r06EC, bit_or(r06F4, r06F5), 0x01));

                                          body.emit(assign(r06ED, rshift(r069F, r06EA), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06F2->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r06F7 = equal(r06EA, body.constant(int(32)));
                                          ir_if *f06F6 = new(mem_ctx) ir_if(operand(r06F7).val);
                                          exec_list *const f06F6_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f06F6->then_instructions;

                                             body.emit(assign(r06EB, r06A0, 0x01));

                                             body.emit(assign(r06EC, r069F, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f06F6->else_instructions;

                                             body.emit(assign(r06E9, bit_or(r06A1, r06A0), 0x01));

                                             ir_expression *const r06F8 = less(r06EA, body.constant(int(64)));
                                             ir_expression *const r06F9 = lshift(r069F, r06EE);
                                             ir_expression *const r06FA = equal(r06EA, body.constant(int(64)));
                                             ir_expression *const r06FB = nequal(r069F, body.constant(0u));
                                             ir_expression *const r06FC = expr(ir_unop_b2i, r06FB);
                                             ir_expression *const r06FD = expr(ir_unop_i2u, r06FC);
                                             ir_expression *const r06FE = expr(ir_triop_csel, r06FA, r069F, r06FD);
                                             body.emit(assign(r06EB, expr(ir_triop_csel, r06F8, r06F9, r06FE), 0x01));

                                             ir_expression *const r06FF = less(r06EA, body.constant(int(64)));
                                             ir_expression *const r0700 = bit_and(r06EA, body.constant(int(31)));
                                             ir_expression *const r0701 = rshift(r069F, r0700);
                                             body.emit(assign(r06EC, expr(ir_triop_csel, r06FF, r0701, body.constant(0u)), 0x01));


                                          body.instructions = f06F6_parent_instructions;
                                          body.emit(f06F6);

                                          /* END IF */

                                          body.emit(assign(r06ED, body.constant(0u), 0x01));


                                       body.instructions = f06F2_parent_instructions;
                                       body.emit(f06F2);

                                       /* END IF */

                                       ir_expression *const r0702 = nequal(r06E9, body.constant(0u));
                                       ir_expression *const r0703 = expr(ir_unop_b2i, r0702);
                                       ir_expression *const r0704 = expr(ir_unop_i2u, r0703);
                                       body.emit(assign(r06EB, bit_or(r06EB, r0704), 0x01));


                                    body.instructions = f06F0_parent_instructions;
                                    body.emit(f06F0);

                                    /* END IF */

                                    body.emit(assign(r06D3, r06ED, 0x01));

                                    body.emit(assign(r06D4, r06EC, 0x01));

                                    body.emit(assign(r06D5, r06EB, 0x01));

                                    body.emit(assign(r06D2, body.constant(int(0)), 0x01));

                                    body.emit(assign(r06D8, less(r06EB, body.constant(0u)), 0x01));


                                 body.instructions = f06E7_parent_instructions;
                                 body.emit(f06E7);

                                 /* END IF */


                              body.instructions = f06DC_parent_instructions;
                              body.emit(f06DC);

                              /* END IF */


                           body.instructions = f06DA_parent_instructions;
                           body.emit(f06DA);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f0705 = new(mem_ctx) ir_if(operand(r06D6).val);
                           exec_list *const f0705_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0705->then_instructions;

                              /* IF CONDITION */
                              ir_if *f0706 = new(mem_ctx) ir_if(operand(r06D8).val);
                              exec_list *const f0706_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0706->then_instructions;

                                 ir_variable *const r0707 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r0707, add(r06D4, body.constant(1u)), 0x01));

                                 ir_expression *const r0708 = less(r0707, r06D4);
                                 ir_expression *const r0709 = expr(ir_unop_b2i, r0708);
                                 ir_expression *const r070A = expr(ir_unop_i2u, r0709);
                                 body.emit(assign(r06D3, add(r06D3, r070A), 0x01));

                                 ir_expression *const r070B = equal(r06D5, body.constant(0u));
                                 ir_expression *const r070C = expr(ir_unop_b2i, r070B);
                                 ir_expression *const r070D = expr(ir_unop_i2u, r070C);
                                 ir_expression *const r070E = add(r06D5, r070D);
                                 ir_expression *const r070F = bit_and(r070E, body.constant(1u));
                                 ir_expression *const r0710 = expr(ir_unop_bit_not, r070F);
                                 body.emit(assign(r06D4, bit_and(r0707, r0710), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0706->else_instructions;

                                 ir_expression *const r0711 = bit_or(r06D3, r06D4);
                                 ir_expression *const r0712 = equal(r0711, body.constant(0u));
                                 body.emit(assign(r06D2, expr(ir_triop_csel, r0712, body.constant(int(0)), r06D2), 0x01));


                              body.instructions = f0706_parent_instructions;
                              body.emit(f0706);

                              /* END IF */

                              ir_variable *const r0713 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0713);
                              ir_expression *const r0714 = lshift(r01D7, body.constant(int(31)));
                              ir_expression *const r0715 = expr(ir_unop_i2u, r06D2);
                              ir_expression *const r0716 = lshift(r0715, body.constant(int(20)));
                              ir_expression *const r0717 = add(r0714, r0716);
                              body.emit(assign(r0713, add(r0717, r06D3), 0x02));

                              body.emit(assign(r0713, r06D4, 0x01));

                              body.emit(assign(r06D7, r0713, 0x03));

                              body.emit(assign(r06D6, body.constant(false), 0x01));


                           body.instructions = f0705_parent_instructions;
                           body.emit(f0705);

                           /* END IF */

                           body.emit(assign(r01CE, r06D7, 0x03));

                           body.emit(assign(r01CD, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0697->else_instructions;

                           ir_variable *const r0718 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0718);
                           body.emit(assign(r0718, body.constant(0u), 0x02));

                           body.emit(assign(r0718, body.constant(0u), 0x01));

                           body.emit(assign(r01CE, r0718, 0x03));

                           body.emit(assign(r01CD, body.constant(false), 0x01));


                        body.instructions = f0697_parent_instructions;
                        body.emit(f0697);

                        /* END IF */


                     body.instructions = f0616_parent_instructions;
                     body.emit(f0616);

                     /* END IF */


                  body.instructions = f0595_parent_instructions;
                  body.emit(f0595);

                  /* END IF */


               body.instructions = f0514_parent_instructions;
               body.emit(f0514);

               /* END IF */


            body.instructions = f04F6_parent_instructions;
            body.emit(f04F6);

            /* END IF */


         body.instructions = f0432_parent_instructions;
         body.emit(f0432);

         /* END IF */


      body.instructions = f0372_parent_instructions;
      body.emit(f0372);

      /* END IF */


   body.instructions = f01E5_parent_instructions;
   body.emit(f01E5);

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

   ir_variable *const r0719 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0719);
   ir_variable *const r071A = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r071A);
   ir_variable *const r071B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r071B);
   ir_variable *const r071C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r071C);
   ir_variable *const r071D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r071D);
   ir_variable *const r071E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r071E);
   ir_variable *const r071F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r071F);
   ir_variable *const r0720 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0720, bit_and(r0719, body.constant(65535u)), 0x01));

   ir_variable *const r0721 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0721, rshift(r0719, body.constant(int(16))), 0x01));

   ir_variable *const r0722 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0722, bit_and(r071A, body.constant(65535u)), 0x01));

   ir_variable *const r0723 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0723, rshift(r071A, body.constant(int(16))), 0x01));

   ir_variable *const r0724 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0724, mul(r0721, r0722), 0x01));

   ir_expression *const r0725 = mul(r0720, r0723);
   body.emit(assign(r071E, add(r0725, r0724), 0x01));

   ir_expression *const r0726 = mul(r0721, r0723);
   ir_expression *const r0727 = less(r071E, r0724);
   ir_expression *const r0728 = expr(ir_unop_b2i, r0727);
   ir_expression *const r0729 = expr(ir_unop_i2u, r0728);
   ir_expression *const r072A = lshift(r0729, body.constant(int(16)));
   ir_expression *const r072B = rshift(r071E, body.constant(int(16)));
   ir_expression *const r072C = add(r072A, r072B);
   body.emit(assign(r071D, add(r0726, r072C), 0x01));

   body.emit(assign(r071E, lshift(r071E, body.constant(int(16))), 0x01));

   ir_expression *const r072D = mul(r0720, r0722);
   body.emit(assign(r071F, add(r072D, r071E), 0x01));

   ir_expression *const r072E = less(r071F, r071E);
   ir_expression *const r072F = expr(ir_unop_b2i, r072E);
   ir_expression *const r0730 = expr(ir_unop_i2u, r072F);
   body.emit(assign(r071D, add(r071D, r0730), 0x01));

   body.emit(assign(r071C, r071F, 0x01));

   body.emit(assign(r071B, r071D, 0x01));

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

   ir_variable *const r0731 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0731);
   ir_variable *const r0732 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0732);
   ir_variable *const r0733 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0733);
   ir_variable *const r0734 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0734);
   ir_variable *const r0735 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0735);
   ir_variable *const r0736 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0736);
   ir_variable *const r0737 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0737);
   ir_variable *const r0738 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0738);
   ir_variable *const r0739 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0739);
   ir_variable *const r073A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r073A);
   ir_variable *const r073B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r073B);
   ir_variable *const r073C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r073C, bit_and(r0732, body.constant(65535u)), 0x01));

   ir_variable *const r073D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r073D, rshift(r0732, body.constant(int(16))), 0x01));

   ir_variable *const r073E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r073E, bit_and(r0734, body.constant(65535u)), 0x01));

   ir_variable *const r073F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r073F, rshift(r0734, body.constant(int(16))), 0x01));

   ir_variable *const r0740 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0740, mul(r073D, r073E), 0x01));

   ir_expression *const r0741 = mul(r073C, r073F);
   body.emit(assign(r073A, add(r0741, r0740), 0x01));

   ir_expression *const r0742 = mul(r073D, r073F);
   ir_expression *const r0743 = less(r073A, r0740);
   ir_expression *const r0744 = expr(ir_unop_b2i, r0743);
   ir_expression *const r0745 = expr(ir_unop_i2u, r0744);
   ir_expression *const r0746 = lshift(r0745, body.constant(int(16)));
   ir_expression *const r0747 = rshift(r073A, body.constant(int(16)));
   ir_expression *const r0748 = add(r0746, r0747);
   body.emit(assign(r0739, add(r0742, r0748), 0x01));

   body.emit(assign(r073A, lshift(r073A, body.constant(int(16))), 0x01));

   ir_expression *const r0749 = mul(r073C, r073E);
   body.emit(assign(r073B, add(r0749, r073A), 0x01));

   ir_expression *const r074A = less(r073B, r073A);
   ir_expression *const r074B = expr(ir_unop_b2i, r074A);
   ir_expression *const r074C = expr(ir_unop_i2u, r074B);
   body.emit(assign(r0739, add(r0739, r074C), 0x01));

   ir_variable *const r074D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r074D);
   ir_variable *const r074E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r074E);
   ir_variable *const r074F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r074F);
   ir_variable *const r0750 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0750, bit_and(r0732, body.constant(65535u)), 0x01));

   ir_variable *const r0751 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0751, rshift(r0732, body.constant(int(16))), 0x01));

   ir_variable *const r0752 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0752, bit_and(r0733, body.constant(65535u)), 0x01));

   ir_variable *const r0753 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0753, rshift(r0733, body.constant(int(16))), 0x01));

   ir_variable *const r0754 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0754, mul(r0751, r0752), 0x01));

   ir_expression *const r0755 = mul(r0750, r0753);
   body.emit(assign(r074E, add(r0755, r0754), 0x01));

   ir_expression *const r0756 = mul(r0751, r0753);
   ir_expression *const r0757 = less(r074E, r0754);
   ir_expression *const r0758 = expr(ir_unop_b2i, r0757);
   ir_expression *const r0759 = expr(ir_unop_i2u, r0758);
   ir_expression *const r075A = lshift(r0759, body.constant(int(16)));
   ir_expression *const r075B = rshift(r074E, body.constant(int(16)));
   ir_expression *const r075C = add(r075A, r075B);
   body.emit(assign(r074D, add(r0756, r075C), 0x01));

   body.emit(assign(r074E, lshift(r074E, body.constant(int(16))), 0x01));

   ir_expression *const r075D = mul(r0750, r0752);
   body.emit(assign(r074F, add(r075D, r074E), 0x01));

   ir_expression *const r075E = less(r074F, r074E);
   ir_expression *const r075F = expr(ir_unop_b2i, r075E);
   ir_expression *const r0760 = expr(ir_unop_i2u, r075F);
   body.emit(assign(r074D, add(r074D, r0760), 0x01));

   ir_variable *const r0761 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0761, add(r074F, r0739), 0x01));

   ir_variable *const r0762 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0762);
   ir_variable *const r0763 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0763);
   ir_variable *const r0764 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0764);
   ir_variable *const r0765 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0765, bit_and(r0731, body.constant(65535u)), 0x01));

   ir_variable *const r0766 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0766, rshift(r0731, body.constant(int(16))), 0x01));

   ir_variable *const r0767 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0767, bit_and(r0733, body.constant(65535u)), 0x01));

   ir_variable *const r0768 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0768, rshift(r0733, body.constant(int(16))), 0x01));

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
   ir_expression *const r0777 = less(r0761, r074F);
   ir_expression *const r0778 = expr(ir_unop_b2i, r0777);
   ir_expression *const r0779 = expr(ir_unop_i2u, r0778);
   ir_expression *const r077A = add(r074D, r0779);
   body.emit(assign(r0776, add(r0764, r077A), 0x01));

   ir_variable *const r077B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r077B);
   ir_variable *const r077C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r077C);
   ir_variable *const r077D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r077D);
   ir_variable *const r077E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r077E, bit_and(r0731, body.constant(65535u)), 0x01));

   ir_variable *const r077F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r077F, rshift(r0731, body.constant(int(16))), 0x01));

   ir_variable *const r0780 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0780, bit_and(r0734, body.constant(65535u)), 0x01));

   ir_variable *const r0781 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0781, rshift(r0734, body.constant(int(16))), 0x01));

   ir_variable *const r0782 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0782, mul(r077F, r0780), 0x01));

   ir_expression *const r0783 = mul(r077E, r0781);
   body.emit(assign(r077C, add(r0783, r0782), 0x01));

   ir_expression *const r0784 = mul(r077F, r0781);
   ir_expression *const r0785 = less(r077C, r0782);
   ir_expression *const r0786 = expr(ir_unop_b2i, r0785);
   ir_expression *const r0787 = expr(ir_unop_i2u, r0786);
   ir_expression *const r0788 = lshift(r0787, body.constant(int(16)));
   ir_expression *const r0789 = rshift(r077C, body.constant(int(16)));
   ir_expression *const r078A = add(r0788, r0789);
   body.emit(assign(r077B, add(r0784, r078A), 0x01));

   body.emit(assign(r077C, lshift(r077C, body.constant(int(16))), 0x01));

   ir_expression *const r078B = mul(r077E, r0780);
   body.emit(assign(r077D, add(r078B, r077C), 0x01));

   ir_expression *const r078C = less(r077D, r077C);
   ir_expression *const r078D = expr(ir_unop_b2i, r078C);
   ir_expression *const r078E = expr(ir_unop_i2u, r078D);
   body.emit(assign(r077B, add(r077B, r078E), 0x01));

   ir_variable *const r078F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078F, add(r077D, r0761), 0x01));

   ir_variable *const r0790 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0791 = less(r078F, r077D);
   ir_expression *const r0792 = expr(ir_unop_b2i, r0791);
   ir_expression *const r0793 = expr(ir_unop_i2u, r0792);
   ir_expression *const r0794 = add(r077B, r0793);
   body.emit(assign(r0790, add(r0776, r0794), 0x01));

   body.emit(assign(r0738, r073B, 0x01));

   body.emit(assign(r0737, r078F, 0x01));

   body.emit(assign(r0736, r0790, 0x01));

   ir_expression *const r0795 = less(r0776, r0764);
   ir_expression *const r0796 = expr(ir_unop_b2i, r0795);
   ir_expression *const r0797 = expr(ir_unop_i2u, r0796);
   ir_expression *const r0798 = add(r0762, r0797);
   ir_expression *const r0799 = less(r0790, r0776);
   ir_expression *const r079A = expr(ir_unop_b2i, r0799);
   ir_expression *const r079B = expr(ir_unop_i2u, r079A);
   body.emit(assign(r0735, add(r0798, r079B), 0x01));

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

   ir_variable *const r079C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r079C);
   ir_variable *const r079D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r079D);
   ir_variable *const r079E = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r079E);
   ir_variable *const r079F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r079F);
   ir_variable *const r07A0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07A0);
   ir_variable *const r07A1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r07A1);
   /* IF CONDITION */
   ir_expression *const r07A3 = equal(r079C, body.constant(0u));
   ir_if *f07A2 = new(mem_ctx) ir_if(operand(r07A3).val);
   exec_list *const f07A2_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07A2->then_instructions;

      ir_expression *const r07A4 = equal(r079D, body.constant(0u));
      ir_expression *const r07A5 = expr(ir_unop_find_msb, r079D);
      ir_expression *const r07A6 = sub(body.constant(int(31)), r07A5);
      ir_expression *const r07A7 = expr(ir_triop_csel, r07A4, body.constant(int(32)), r07A6);
      body.emit(assign(r07A1, add(r07A7, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r07A9 = less(r07A1, body.constant(int(0)));
      ir_if *f07A8 = new(mem_ctx) ir_if(operand(r07A9).val);
      exec_list *const f07A8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07A8->then_instructions;

         ir_expression *const r07AA = neg(r07A1);
         body.emit(assign(r079F, rshift(r079D, r07AA), 0x01));

         ir_expression *const r07AB = bit_and(r07A1, body.constant(int(31)));
         body.emit(assign(r07A0, lshift(r079D, r07AB), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07A8->else_instructions;

         body.emit(assign(r079F, lshift(r079D, r07A1), 0x01));

         body.emit(assign(r07A0, body.constant(0u), 0x01));


      body.instructions = f07A8_parent_instructions;
      body.emit(f07A8);

      /* END IF */

      body.emit(assign(r079E, sub(body.constant(int(-31)), r07A1), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07A2->else_instructions;

      ir_expression *const r07AC = equal(r079C, body.constant(0u));
      ir_expression *const r07AD = expr(ir_unop_find_msb, r079C);
      ir_expression *const r07AE = sub(body.constant(int(31)), r07AD);
      ir_expression *const r07AF = expr(ir_triop_csel, r07AC, body.constant(int(32)), r07AE);
      body.emit(assign(r07A1, add(r07AF, body.constant(int(-11))), 0x01));

      ir_expression *const r07B0 = equal(r07A1, body.constant(int(0)));
      ir_expression *const r07B1 = lshift(r079C, r07A1);
      ir_expression *const r07B2 = neg(r07A1);
      ir_expression *const r07B3 = bit_and(r07B2, body.constant(int(31)));
      ir_expression *const r07B4 = rshift(r079D, r07B3);
      ir_expression *const r07B5 = bit_or(r07B1, r07B4);
      body.emit(assign(r079F, expr(ir_triop_csel, r07B0, r079C, r07B5), 0x01));

      body.emit(assign(r07A0, lshift(r079D, r07A1), 0x01));

      body.emit(assign(r079E, sub(body.constant(int(1)), r07A1), 0x01));


   body.instructions = f07A2_parent_instructions;
   body.emit(f07A2);

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

   ir_variable *const r07B6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r07B6);
   ir_variable *const r07B7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r07B7);
   ir_variable *const r07B8 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r07B8, body.constant(true), 0x01));

   ir_variable *const r07B9 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r07BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r07BA);
   ir_variable *const r07BB = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r07BB);
   ir_variable *const r07BC = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r07BC);
   ir_variable *const r07BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r07BD);
   ir_variable *const r07BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r07BE);
   ir_variable *const r07BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r07BF);
   ir_variable *const r07C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r07C0);
   ir_variable *const r07C1 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r07C1);
   ir_variable *const r07C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r07C2);
   ir_variable *const r07C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r07C3);
   ir_variable *const r07C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r07C4);
   body.emit(assign(r07C4, body.constant(0u), 0x01));

   body.emit(assign(r07C3, body.constant(0u), 0x01));

   body.emit(assign(r07C2, body.constant(0u), 0x01));

   ir_variable *const r07C5 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r07C5, swizzle_x(r07B6), 0x01));

   body.emit(assign(r07C0, r07C5, 0x01));

   ir_variable *const r07C6 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r07C6, bit_and(swizzle_y(r07B6), body.constant(1048575u)), 0x01));

   body.emit(assign(r07BF, r07C6, 0x01));

   ir_variable *const r07C7 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r07C7, swizzle_x(r07B7), 0x01));

   body.emit(assign(r07BE, r07C7, 0x01));

   ir_variable *const r07C8 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r07C8, bit_and(swizzle_y(r07B7), body.constant(1048575u)), 0x01));

   body.emit(assign(r07BD, r07C8, 0x01));

   ir_variable *const r07C9 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r07CA = rshift(swizzle_y(r07B6), body.constant(int(20)));
   ir_expression *const r07CB = bit_and(r07CA, body.constant(2047u));
   body.emit(assign(r07C9, expr(ir_unop_u2i, r07CB), 0x01));

   body.emit(assign(r07BC, r07C9, 0x01));

   ir_variable *const r07CC = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r07CD = rshift(swizzle_y(r07B7), body.constant(int(20)));
   ir_expression *const r07CE = bit_and(r07CD, body.constant(2047u));
   body.emit(assign(r07CC, expr(ir_unop_u2i, r07CE), 0x01));

   body.emit(assign(r07BB, r07CC, 0x01));

   ir_expression *const r07CF = rshift(swizzle_y(r07B6), body.constant(int(31)));
   ir_expression *const r07D0 = rshift(swizzle_y(r07B7), body.constant(int(31)));
   body.emit(assign(r07BA, bit_xor(r07CF, r07D0), 0x01));

   /* IF CONDITION */
   ir_expression *const r07D2 = equal(r07C9, body.constant(int(2047)));
   ir_if *f07D1 = new(mem_ctx) ir_if(operand(r07D2).val);
   exec_list *const f07D1_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07D1->then_instructions;

      /* IF CONDITION */
      ir_expression *const r07D4 = bit_or(r07C6, swizzle_x(r07B6));
      ir_expression *const r07D5 = nequal(r07D4, body.constant(0u));
      ir_expression *const r07D6 = equal(r07CC, body.constant(int(2047)));
      ir_expression *const r07D7 = bit_or(r07C8, swizzle_x(r07B7));
      ir_expression *const r07D8 = nequal(r07D7, body.constant(0u));
      ir_expression *const r07D9 = logic_and(r07D6, r07D8);
      ir_expression *const r07DA = logic_or(r07D5, r07D9);
      ir_if *f07D3 = new(mem_ctx) ir_if(operand(r07DA).val);
      exec_list *const f07D3_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07D3->then_instructions;

         ir_variable *const r07DB = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r07DB, swizzle_x(r07B6), 0x01));

         ir_variable *const r07DC = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r07DC, swizzle_x(r07B7), 0x01));

         body.emit(assign(r07DB, bit_or(swizzle_y(r07B6), body.constant(524288u)), 0x02));

         body.emit(assign(r07DC, bit_or(swizzle_y(r07B7), body.constant(524288u)), 0x02));

         ir_expression *const r07DD = lshift(swizzle_y(r07B6), body.constant(int(1)));
         ir_expression *const r07DE = gequal(r07DD, body.constant(4292870144u));
         ir_expression *const r07DF = nequal(swizzle_x(r07B6), body.constant(0u));
         ir_expression *const r07E0 = bit_and(swizzle_y(r07B6), body.constant(1048575u));
         ir_expression *const r07E1 = nequal(r07E0, body.constant(0u));
         ir_expression *const r07E2 = logic_or(r07DF, r07E1);
         ir_expression *const r07E3 = logic_and(r07DE, r07E2);
         ir_swizzle *const r07E4 = swizzle(r07E3, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r07E5 = lshift(swizzle_y(r07B7), body.constant(int(1)));
         ir_expression *const r07E6 = gequal(r07E5, body.constant(4292870144u));
         ir_expression *const r07E7 = nequal(swizzle_x(r07B7), body.constant(0u));
         ir_expression *const r07E8 = bit_and(swizzle_y(r07B7), body.constant(1048575u));
         ir_expression *const r07E9 = nequal(r07E8, body.constant(0u));
         ir_expression *const r07EA = logic_or(r07E7, r07E9);
         ir_expression *const r07EB = logic_and(r07E6, r07EA);
         ir_swizzle *const r07EC = swizzle(r07EB, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r07ED = expr(ir_triop_csel, r07EC, r07DC, r07DB);
         body.emit(assign(r07B9, expr(ir_triop_csel, r07E4, r07ED, r07DC), 0x03));

         body.emit(assign(r07B8, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07D3->else_instructions;

         /* IF CONDITION */
         ir_expression *const r07EF = expr(ir_unop_i2u, r07CC);
         ir_expression *const r07F0 = bit_or(r07EF, r07C8);
         ir_expression *const r07F1 = bit_or(r07F0, swizzle_x(r07B7));
         ir_expression *const r07F2 = equal(r07F1, body.constant(0u));
         ir_if *f07EE = new(mem_ctx) ir_if(operand(r07F2).val);
         exec_list *const f07EE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07EE->then_instructions;

            ir_constant_data r07F3_data;
            memset(&r07F3_data, 0, sizeof(ir_constant_data));
            r07F3_data.u[0] = 4294967295;
            r07F3_data.u[1] = 4294967295;
            ir_constant *const r07F3 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r07F3_data);
            body.emit(assign(r07B9, r07F3, 0x03));

            body.emit(assign(r07B8, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f07EE->else_instructions;

            ir_variable *const r07F4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r07F4);
            ir_expression *const r07F5 = lshift(r07BA, body.constant(int(31)));
            body.emit(assign(r07F4, add(r07F5, body.constant(2146435072u)), 0x02));

            body.emit(assign(r07F4, body.constant(0u), 0x01));

            body.emit(assign(r07B9, r07F4, 0x03));

            body.emit(assign(r07B8, body.constant(false), 0x01));


         body.instructions = f07EE_parent_instructions;
         body.emit(f07EE);

         /* END IF */


      body.instructions = f07D3_parent_instructions;
      body.emit(f07D3);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07D1->else_instructions;

      /* IF CONDITION */
      ir_expression *const r07F7 = equal(r07CC, body.constant(int(2047)));
      ir_if *f07F6 = new(mem_ctx) ir_if(operand(r07F7).val);
      exec_list *const f07F6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07F6->then_instructions;

         /* IF CONDITION */
         ir_expression *const r07F9 = bit_or(r07C8, swizzle_x(r07B7));
         ir_expression *const r07FA = nequal(r07F9, body.constant(0u));
         ir_if *f07F8 = new(mem_ctx) ir_if(operand(r07FA).val);
         exec_list *const f07F8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07F8->then_instructions;

            ir_variable *const r07FB = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r07FB, swizzle_x(r07B6), 0x01));

            ir_variable *const r07FC = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r07FC, swizzle_x(r07B7), 0x01));

            body.emit(assign(r07FB, bit_or(swizzle_y(r07B6), body.constant(524288u)), 0x02));

            body.emit(assign(r07FC, bit_or(swizzle_y(r07B7), body.constant(524288u)), 0x02));

            ir_expression *const r07FD = lshift(swizzle_y(r07B6), body.constant(int(1)));
            ir_expression *const r07FE = gequal(r07FD, body.constant(4292870144u));
            ir_expression *const r07FF = nequal(swizzle_x(r07B6), body.constant(0u));
            ir_expression *const r0800 = bit_and(swizzle_y(r07B6), body.constant(1048575u));
            ir_expression *const r0801 = nequal(r0800, body.constant(0u));
            ir_expression *const r0802 = logic_or(r07FF, r0801);
            ir_expression *const r0803 = logic_and(r07FE, r0802);
            ir_swizzle *const r0804 = swizzle(r0803, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0805 = lshift(swizzle_y(r07B7), body.constant(int(1)));
            ir_expression *const r0806 = gequal(r0805, body.constant(4292870144u));
            ir_expression *const r0807 = nequal(swizzle_x(r07B7), body.constant(0u));
            ir_expression *const r0808 = bit_and(swizzle_y(r07B7), body.constant(1048575u));
            ir_expression *const r0809 = nequal(r0808, body.constant(0u));
            ir_expression *const r080A = logic_or(r0807, r0809);
            ir_expression *const r080B = logic_and(r0806, r080A);
            ir_swizzle *const r080C = swizzle(r080B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r080D = expr(ir_triop_csel, r080C, r07FC, r07FB);
            body.emit(assign(r07B9, expr(ir_triop_csel, r0804, r080D, r07FC), 0x03));

            body.emit(assign(r07B8, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f07F8->else_instructions;

            /* IF CONDITION */
            ir_expression *const r080F = expr(ir_unop_i2u, r07C9);
            ir_expression *const r0810 = bit_or(r080F, r07C6);
            ir_expression *const r0811 = bit_or(r0810, swizzle_x(r07B6));
            ir_expression *const r0812 = equal(r0811, body.constant(0u));
            ir_if *f080E = new(mem_ctx) ir_if(operand(r0812).val);
            exec_list *const f080E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f080E->then_instructions;

               ir_constant_data r0813_data;
               memset(&r0813_data, 0, sizeof(ir_constant_data));
               r0813_data.u[0] = 4294967295;
               r0813_data.u[1] = 4294967295;
               ir_constant *const r0813 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0813_data);
               body.emit(assign(r07B9, r0813, 0x03));

               body.emit(assign(r07B8, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f080E->else_instructions;

               ir_variable *const r0814 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0814);
               ir_expression *const r0815 = lshift(r07BA, body.constant(int(31)));
               body.emit(assign(r0814, add(r0815, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0814, body.constant(0u), 0x01));

               body.emit(assign(r07B9, r0814, 0x03));

               body.emit(assign(r07B8, body.constant(false), 0x01));


            body.instructions = f080E_parent_instructions;
            body.emit(f080E);

            /* END IF */


         body.instructions = f07F8_parent_instructions;
         body.emit(f07F8);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07F6->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0817 = equal(r07C9, body.constant(int(0)));
         ir_if *f0816 = new(mem_ctx) ir_if(operand(r0817).val);
         exec_list *const f0816_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0816->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0819 = bit_or(r07C6, swizzle_x(r07B6));
            ir_expression *const r081A = equal(r0819, body.constant(0u));
            ir_if *f0818 = new(mem_ctx) ir_if(operand(r081A).val);
            exec_list *const f0818_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0818->then_instructions;

               ir_variable *const r081B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r081B);
               body.emit(assign(r081B, lshift(r07BA, body.constant(int(31))), 0x02));

               body.emit(assign(r081B, body.constant(0u), 0x01));

               body.emit(assign(r07B9, r081B, 0x03));

               body.emit(assign(r07B8, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0818->else_instructions;

               ir_variable *const r081C = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r081C, r07C9, 0x01));

               ir_variable *const r081D = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r081D, r07C6, 0x01));

               ir_variable *const r081E = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r081E, r07C5, 0x01));

               ir_variable *const r081F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r081F);
               /* IF CONDITION */
               ir_expression *const r0821 = equal(r07C6, body.constant(0u));
               ir_if *f0820 = new(mem_ctx) ir_if(operand(r0821).val);
               exec_list *const f0820_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0820->then_instructions;

                  ir_expression *const r0822 = equal(swizzle_x(r07B6), body.constant(0u));
                  ir_expression *const r0823 = expr(ir_unop_find_msb, swizzle_x(r07B6));
                  ir_expression *const r0824 = sub(body.constant(int(31)), r0823);
                  ir_expression *const r0825 = expr(ir_triop_csel, r0822, body.constant(int(32)), r0824);
                  body.emit(assign(r081F, add(r0825, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0827 = less(r081F, body.constant(int(0)));
                  ir_if *f0826 = new(mem_ctx) ir_if(operand(r0827).val);
                  exec_list *const f0826_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0826->then_instructions;

                     ir_expression *const r0828 = neg(r081F);
                     body.emit(assign(r081D, rshift(swizzle_x(r07B6), r0828), 0x01));

                     ir_expression *const r0829 = bit_and(r081F, body.constant(int(31)));
                     body.emit(assign(r081E, lshift(swizzle_x(r07B6), r0829), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0826->else_instructions;

                     body.emit(assign(r081D, lshift(swizzle_x(r07B6), r081F), 0x01));

                     body.emit(assign(r081E, body.constant(0u), 0x01));


                  body.instructions = f0826_parent_instructions;
                  body.emit(f0826);

                  /* END IF */

                  body.emit(assign(r081C, sub(body.constant(int(-31)), r081F), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0820->else_instructions;

                  ir_expression *const r082A = equal(r07C6, body.constant(0u));
                  ir_expression *const r082B = expr(ir_unop_find_msb, r07C6);
                  ir_expression *const r082C = sub(body.constant(int(31)), r082B);
                  ir_expression *const r082D = expr(ir_triop_csel, r082A, body.constant(int(32)), r082C);
                  body.emit(assign(r081F, add(r082D, body.constant(int(-11))), 0x01));

                  ir_expression *const r082E = equal(r081F, body.constant(int(0)));
                  ir_expression *const r082F = lshift(r07C6, r081F);
                  ir_expression *const r0830 = neg(r081F);
                  ir_expression *const r0831 = bit_and(r0830, body.constant(int(31)));
                  ir_expression *const r0832 = rshift(swizzle_x(r07B6), r0831);
                  ir_expression *const r0833 = bit_or(r082F, r0832);
                  body.emit(assign(r081D, expr(ir_triop_csel, r082E, r07C6, r0833), 0x01));

                  body.emit(assign(r081E, lshift(swizzle_x(r07B6), r081F), 0x01));

                  body.emit(assign(r081C, sub(body.constant(int(1)), r081F), 0x01));


               body.instructions = f0820_parent_instructions;
               body.emit(f0820);

               /* END IF */

               body.emit(assign(r07BC, r081C, 0x01));

               body.emit(assign(r07BF, r081D, 0x01));

               body.emit(assign(r07C0, r081E, 0x01));


            body.instructions = f0818_parent_instructions;
            body.emit(f0818);

            /* END IF */


         body.instructions = f0816_parent_instructions;
         body.emit(f0816);

         /* END IF */

         /* IF CONDITION */
         ir_if *f0834 = new(mem_ctx) ir_if(operand(r07B8).val);
         exec_list *const f0834_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0834->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0836 = equal(r07CC, body.constant(int(0)));
            ir_if *f0835 = new(mem_ctx) ir_if(operand(r0836).val);
            exec_list *const f0835_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0835->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0838 = bit_or(r07C8, swizzle_x(r07B7));
               ir_expression *const r0839 = equal(r0838, body.constant(0u));
               ir_if *f0837 = new(mem_ctx) ir_if(operand(r0839).val);
               exec_list *const f0837_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0837->then_instructions;

                  ir_variable *const r083A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r083A);
                  body.emit(assign(r083A, lshift(r07BA, body.constant(int(31))), 0x02));

                  body.emit(assign(r083A, body.constant(0u), 0x01));

                  body.emit(assign(r07B9, r083A, 0x03));

                  body.emit(assign(r07B8, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0837->else_instructions;

                  ir_variable *const r083B = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r083B, r07CC, 0x01));

                  ir_variable *const r083C = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r083C, r07C8, 0x01));

                  ir_variable *const r083D = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r083D, r07C7, 0x01));

                  ir_variable *const r083E = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r083E);
                  /* IF CONDITION */
                  ir_expression *const r0840 = equal(r07C8, body.constant(0u));
                  ir_if *f083F = new(mem_ctx) ir_if(operand(r0840).val);
                  exec_list *const f083F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f083F->then_instructions;

                     ir_expression *const r0841 = equal(swizzle_x(r07B7), body.constant(0u));
                     ir_expression *const r0842 = expr(ir_unop_find_msb, swizzle_x(r07B7));
                     ir_expression *const r0843 = sub(body.constant(int(31)), r0842);
                     ir_expression *const r0844 = expr(ir_triop_csel, r0841, body.constant(int(32)), r0843);
                     body.emit(assign(r083E, add(r0844, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0846 = less(r083E, body.constant(int(0)));
                     ir_if *f0845 = new(mem_ctx) ir_if(operand(r0846).val);
                     exec_list *const f0845_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0845->then_instructions;

                        ir_expression *const r0847 = neg(r083E);
                        body.emit(assign(r083C, rshift(swizzle_x(r07B7), r0847), 0x01));

                        ir_expression *const r0848 = bit_and(r083E, body.constant(int(31)));
                        body.emit(assign(r083D, lshift(swizzle_x(r07B7), r0848), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0845->else_instructions;

                        body.emit(assign(r083C, lshift(swizzle_x(r07B7), r083E), 0x01));

                        body.emit(assign(r083D, body.constant(0u), 0x01));


                     body.instructions = f0845_parent_instructions;
                     body.emit(f0845);

                     /* END IF */

                     body.emit(assign(r083B, sub(body.constant(int(-31)), r083E), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f083F->else_instructions;

                     ir_expression *const r0849 = equal(r07C8, body.constant(0u));
                     ir_expression *const r084A = expr(ir_unop_find_msb, r07C8);
                     ir_expression *const r084B = sub(body.constant(int(31)), r084A);
                     ir_expression *const r084C = expr(ir_triop_csel, r0849, body.constant(int(32)), r084B);
                     body.emit(assign(r083E, add(r084C, body.constant(int(-11))), 0x01));

                     ir_expression *const r084D = equal(r083E, body.constant(int(0)));
                     ir_expression *const r084E = lshift(r07C8, r083E);
                     ir_expression *const r084F = neg(r083E);
                     ir_expression *const r0850 = bit_and(r084F, body.constant(int(31)));
                     ir_expression *const r0851 = rshift(swizzle_x(r07B7), r0850);
                     ir_expression *const r0852 = bit_or(r084E, r0851);
                     body.emit(assign(r083C, expr(ir_triop_csel, r084D, r07C8, r0852), 0x01));

                     body.emit(assign(r083D, lshift(swizzle_x(r07B7), r083E), 0x01));

                     body.emit(assign(r083B, sub(body.constant(int(1)), r083E), 0x01));


                  body.instructions = f083F_parent_instructions;
                  body.emit(f083F);

                  /* END IF */

                  body.emit(assign(r07BB, r083B, 0x01));

                  body.emit(assign(r07BD, r083C, 0x01));

                  body.emit(assign(r07BE, r083D, 0x01));


               body.instructions = f0837_parent_instructions;
               body.emit(f0837);

               /* END IF */


            body.instructions = f0835_parent_instructions;
            body.emit(f0835);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0853 = new(mem_ctx) ir_if(operand(r07B8).val);
            exec_list *const f0853_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0853->then_instructions;

               ir_expression *const r0854 = add(r07BC, r07BB);
               body.emit(assign(r07C1, add(r0854, body.constant(int(-1024))), 0x01));

               body.emit(assign(r07BF, bit_or(r07BF, body.constant(1048576u)), 0x01));

               ir_variable *const r0855 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0856 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0856, lshift(r07BE, body.constant(int(12))), 0x01));

               ir_expression *const r0857 = lshift(r07BD, body.constant(int(12)));
               ir_expression *const r0858 = rshift(r07BE, body.constant(int(20)));
               body.emit(assign(r0855, bit_or(r0857, r0858), 0x01));

               body.emit(assign(r07BD, r0855, 0x01));

               body.emit(assign(r07BE, r0856, 0x01));

               ir_variable *const r0859 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0859);
               ir_variable *const r085A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r085A);
               ir_variable *const r085B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r085B);
               ir_variable *const r085C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r085C, bit_and(r07C0, body.constant(65535u)), 0x01));

               ir_variable *const r085D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r085D, rshift(r07C0, body.constant(int(16))), 0x01));

               ir_variable *const r085E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r085E, bit_and(r0856, body.constant(65535u)), 0x01));

               ir_variable *const r085F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r085F, rshift(r0856, body.constant(int(16))), 0x01));

               ir_variable *const r0860 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0860, mul(r085D, r085E), 0x01));

               ir_expression *const r0861 = mul(r085C, r085F);
               body.emit(assign(r085A, add(r0861, r0860), 0x01));

               ir_expression *const r0862 = mul(r085D, r085F);
               ir_expression *const r0863 = less(r085A, r0860);
               ir_expression *const r0864 = expr(ir_unop_b2i, r0863);
               ir_expression *const r0865 = expr(ir_unop_i2u, r0864);
               ir_expression *const r0866 = lshift(r0865, body.constant(int(16)));
               ir_expression *const r0867 = rshift(r085A, body.constant(int(16)));
               ir_expression *const r0868 = add(r0866, r0867);
               body.emit(assign(r0859, add(r0862, r0868), 0x01));

               body.emit(assign(r085A, lshift(r085A, body.constant(int(16))), 0x01));

               ir_expression *const r0869 = mul(r085C, r085E);
               body.emit(assign(r085B, add(r0869, r085A), 0x01));

               ir_expression *const r086A = less(r085B, r085A);
               ir_expression *const r086B = expr(ir_unop_b2i, r086A);
               ir_expression *const r086C = expr(ir_unop_i2u, r086B);
               body.emit(assign(r0859, add(r0859, r086C), 0x01));

               ir_variable *const r086D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r086D);
               ir_variable *const r086E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r086E);
               ir_variable *const r086F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r086F);
               ir_variable *const r0870 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0870, bit_and(r07C0, body.constant(65535u)), 0x01));

               ir_variable *const r0871 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0871, rshift(r07C0, body.constant(int(16))), 0x01));

               ir_variable *const r0872 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0872, bit_and(r0855, body.constant(65535u)), 0x01));

               ir_variable *const r0873 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0873, rshift(r0855, body.constant(int(16))), 0x01));

               ir_variable *const r0874 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0874, mul(r0871, r0872), 0x01));

               ir_expression *const r0875 = mul(r0870, r0873);
               body.emit(assign(r086E, add(r0875, r0874), 0x01));

               ir_expression *const r0876 = mul(r0871, r0873);
               ir_expression *const r0877 = less(r086E, r0874);
               ir_expression *const r0878 = expr(ir_unop_b2i, r0877);
               ir_expression *const r0879 = expr(ir_unop_i2u, r0878);
               ir_expression *const r087A = lshift(r0879, body.constant(int(16)));
               ir_expression *const r087B = rshift(r086E, body.constant(int(16)));
               ir_expression *const r087C = add(r087A, r087B);
               body.emit(assign(r086D, add(r0876, r087C), 0x01));

               body.emit(assign(r086E, lshift(r086E, body.constant(int(16))), 0x01));

               ir_expression *const r087D = mul(r0870, r0872);
               body.emit(assign(r086F, add(r087D, r086E), 0x01));

               ir_expression *const r087E = less(r086F, r086E);
               ir_expression *const r087F = expr(ir_unop_b2i, r087E);
               ir_expression *const r0880 = expr(ir_unop_i2u, r087F);
               body.emit(assign(r086D, add(r086D, r0880), 0x01));

               ir_variable *const r0881 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0881, add(r086F, r0859), 0x01));

               ir_variable *const r0882 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0882);
               ir_variable *const r0883 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0883);
               ir_variable *const r0884 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0884);
               ir_variable *const r0885 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0885, bit_and(r07BF, body.constant(65535u)), 0x01));

               ir_variable *const r0886 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0886, rshift(r07BF, body.constant(int(16))), 0x01));

               ir_variable *const r0887 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0887, bit_and(r0855, body.constant(65535u)), 0x01));

               ir_variable *const r0888 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0888, rshift(r0855, body.constant(int(16))), 0x01));

               ir_variable *const r0889 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0889, mul(r0886, r0887), 0x01));

               ir_expression *const r088A = mul(r0885, r0888);
               body.emit(assign(r0883, add(r088A, r0889), 0x01));

               ir_expression *const r088B = mul(r0886, r0888);
               ir_expression *const r088C = less(r0883, r0889);
               ir_expression *const r088D = expr(ir_unop_b2i, r088C);
               ir_expression *const r088E = expr(ir_unop_i2u, r088D);
               ir_expression *const r088F = lshift(r088E, body.constant(int(16)));
               ir_expression *const r0890 = rshift(r0883, body.constant(int(16)));
               ir_expression *const r0891 = add(r088F, r0890);
               body.emit(assign(r0882, add(r088B, r0891), 0x01));

               body.emit(assign(r0883, lshift(r0883, body.constant(int(16))), 0x01));

               ir_expression *const r0892 = mul(r0885, r0887);
               body.emit(assign(r0884, add(r0892, r0883), 0x01));

               ir_expression *const r0893 = less(r0884, r0883);
               ir_expression *const r0894 = expr(ir_unop_b2i, r0893);
               ir_expression *const r0895 = expr(ir_unop_i2u, r0894);
               body.emit(assign(r0882, add(r0882, r0895), 0x01));

               ir_variable *const r0896 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0897 = less(r0881, r086F);
               ir_expression *const r0898 = expr(ir_unop_b2i, r0897);
               ir_expression *const r0899 = expr(ir_unop_i2u, r0898);
               ir_expression *const r089A = add(r086D, r0899);
               body.emit(assign(r0896, add(r0884, r089A), 0x01));

               ir_variable *const r089B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r089B);
               ir_variable *const r089C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r089C);
               ir_variable *const r089D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r089D);
               ir_variable *const r089E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r089E, bit_and(r07BF, body.constant(65535u)), 0x01));

               ir_variable *const r089F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r089F, rshift(r07BF, body.constant(int(16))), 0x01));

               ir_variable *const r08A0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A0, bit_and(r0856, body.constant(65535u)), 0x01));

               ir_variable *const r08A1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08A1, rshift(r0856, body.constant(int(16))), 0x01));

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
               body.emit(assign(r08AF, add(r089D, r0881), 0x01));

               ir_variable *const r08B0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r08B1 = less(r08AF, r089D);
               ir_expression *const r08B2 = expr(ir_unop_b2i, r08B1);
               ir_expression *const r08B3 = expr(ir_unop_i2u, r08B2);
               ir_expression *const r08B4 = add(r089B, r08B3);
               body.emit(assign(r08B0, add(r0896, r08B4), 0x01));

               ir_variable *const r08B5 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r08B6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08B6, add(r08B0, r07C0), 0x01));

               ir_expression *const r08B7 = less(r0896, r0884);
               ir_expression *const r08B8 = expr(ir_unop_b2i, r08B7);
               ir_expression *const r08B9 = expr(ir_unop_i2u, r08B8);
               ir_expression *const r08BA = add(r0882, r08B9);
               ir_expression *const r08BB = less(r08B0, r0896);
               ir_expression *const r08BC = expr(ir_unop_b2i, r08BB);
               ir_expression *const r08BD = expr(ir_unop_i2u, r08BC);
               ir_expression *const r08BE = add(r08BA, r08BD);
               ir_expression *const r08BF = add(r08BE, r07BF);
               ir_expression *const r08C0 = less(r08B6, r08B0);
               ir_expression *const r08C1 = expr(ir_unop_b2i, r08C0);
               ir_expression *const r08C2 = expr(ir_unop_i2u, r08C1);
               body.emit(assign(r08B5, add(r08BF, r08C2), 0x01));

               body.emit(assign(r07C4, r08B5, 0x01));

               body.emit(assign(r07C3, r08B6, 0x01));

               ir_expression *const r08C3 = nequal(r085B, body.constant(0u));
               ir_expression *const r08C4 = expr(ir_unop_b2i, r08C3);
               ir_expression *const r08C5 = expr(ir_unop_i2u, r08C4);
               body.emit(assign(r07C2, bit_or(r08AF, r08C5), 0x01));

               /* IF CONDITION */
               ir_expression *const r08C7 = gequal(r08B5, body.constant(2097152u));
               ir_if *f08C6 = new(mem_ctx) ir_if(operand(r08C7).val);
               exec_list *const f08C6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08C6->then_instructions;

                  ir_variable *const r08C8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r08C8);
                  body.emit(assign(r08C8, lshift(r08B6, body.constant(int(31))), 0x01));

                  ir_expression *const r08C9 = nequal(r07C2, body.constant(0u));
                  ir_expression *const r08CA = expr(ir_unop_b2i, r08C9);
                  ir_expression *const r08CB = expr(ir_unop_i2u, r08CA);
                  body.emit(assign(r08C8, bit_or(r08C8, r08CB), 0x01));

                  body.emit(assign(r07C4, rshift(r08B5, body.constant(int(1))), 0x01));

                  ir_expression *const r08CC = lshift(r08B5, body.constant(int(31)));
                  ir_expression *const r08CD = rshift(r08B6, body.constant(int(1)));
                  body.emit(assign(r07C3, bit_or(r08CC, r08CD), 0x01));

                  body.emit(assign(r07C2, r08C8, 0x01));

                  body.emit(assign(r07C1, add(r07C1, body.constant(int(1))), 0x01));


               body.instructions = f08C6_parent_instructions;
               body.emit(f08C6);

               /* END IF */

               ir_variable *const r08CE = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r08CE, r07C1, 0x01));

               ir_variable *const r08CF = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r08CF, r07C4, 0x01));

               ir_variable *const r08D0 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r08D0, r07C3, 0x01));

               ir_variable *const r08D1 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r08D1, r07C2, 0x01));

               ir_variable *const r08D2 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r08D2, body.constant(true), 0x01));

               ir_variable *const r08D3 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r08D4 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r08D4);
               ir_expression *const r08D5 = expr(ir_unop_u2i, r07C2);
               body.emit(assign(r08D4, less(r08D5, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r08D7 = gequal(r07C1, body.constant(int(2045)));
               ir_if *f08D6 = new(mem_ctx) ir_if(operand(r08D7).val);
               exec_list *const f08D6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08D6->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r08D9 = less(body.constant(int(2045)), r07C1);
                  ir_expression *const r08DA = equal(r07C1, body.constant(int(2045)));
                  ir_expression *const r08DB = equal(body.constant(2097151u), r07C4);
                  ir_expression *const r08DC = equal(body.constant(4294967295u), r07C3);
                  ir_expression *const r08DD = logic_and(r08DB, r08DC);
                  ir_expression *const r08DE = logic_and(r08DA, r08DD);
                  ir_expression *const r08DF = logic_and(r08DE, r08D4);
                  ir_expression *const r08E0 = logic_or(r08D9, r08DF);
                  ir_if *f08D8 = new(mem_ctx) ir_if(operand(r08E0).val);
                  exec_list *const f08D8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08D8->then_instructions;

                     ir_variable *const r08E1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r08E1);
                     ir_expression *const r08E2 = lshift(r07BA, body.constant(int(31)));
                     body.emit(assign(r08E1, add(r08E2, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r08E1, body.constant(0u), 0x01));

                     body.emit(assign(r08D3, r08E1, 0x03));

                     body.emit(assign(r08D2, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08D8->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r08E4 = less(r07C1, body.constant(int(0)));
                     ir_if *f08E3 = new(mem_ctx) ir_if(operand(r08E4).val);
                     exec_list *const f08E3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08E3->then_instructions;

                        ir_variable *const r08E5 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r08E5, r07C2, 0x01));

                        ir_variable *const r08E6 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r08E6, neg(r07C1), 0x01));

                        ir_variable *const r08E7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r08E7);
                        ir_variable *const r08E8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r08E8);
                        ir_variable *const r08E9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r08E9);
                        ir_variable *const r08EA = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r08EB = neg(r08E6);
                        body.emit(assign(r08EA, bit_and(r08EB, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08ED = equal(r08E6, body.constant(int(0)));
                        ir_if *f08EC = new(mem_ctx) ir_if(operand(r08ED).val);
                        exec_list *const f08EC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08EC->then_instructions;

                           body.emit(assign(r08E7, r07C2, 0x01));

                           body.emit(assign(r08E8, r07C3, 0x01));

                           body.emit(assign(r08E9, r07C4, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f08EC->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r08EF = less(r08E6, body.constant(int(32)));
                           ir_if *f08EE = new(mem_ctx) ir_if(operand(r08EF).val);
                           exec_list *const f08EE_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f08EE->then_instructions;

                              body.emit(assign(r08E7, lshift(r07C3, r08EA), 0x01));

                              ir_expression *const r08F0 = lshift(r07C4, r08EA);
                              ir_expression *const r08F1 = rshift(r07C3, r08E6);
                              body.emit(assign(r08E8, bit_or(r08F0, r08F1), 0x01));

                              body.emit(assign(r08E9, rshift(r07C4, r08E6), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f08EE->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r08F3 = equal(r08E6, body.constant(int(32)));
                              ir_if *f08F2 = new(mem_ctx) ir_if(operand(r08F3).val);
                              exec_list *const f08F2_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f08F2->then_instructions;

                                 body.emit(assign(r08E7, r07C3, 0x01));

                                 body.emit(assign(r08E8, r07C4, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f08F2->else_instructions;

                                 body.emit(assign(r08E5, bit_or(r07C2, r07C3), 0x01));

                                 ir_expression *const r08F4 = less(r08E6, body.constant(int(64)));
                                 ir_expression *const r08F5 = lshift(r07C4, r08EA);
                                 ir_expression *const r08F6 = equal(r08E6, body.constant(int(64)));
                                 ir_expression *const r08F7 = nequal(r07C4, body.constant(0u));
                                 ir_expression *const r08F8 = expr(ir_unop_b2i, r08F7);
                                 ir_expression *const r08F9 = expr(ir_unop_i2u, r08F8);
                                 ir_expression *const r08FA = expr(ir_triop_csel, r08F6, r07C4, r08F9);
                                 body.emit(assign(r08E7, expr(ir_triop_csel, r08F4, r08F5, r08FA), 0x01));

                                 ir_expression *const r08FB = less(r08E6, body.constant(int(64)));
                                 ir_expression *const r08FC = bit_and(r08E6, body.constant(int(31)));
                                 ir_expression *const r08FD = rshift(r07C4, r08FC);
                                 body.emit(assign(r08E8, expr(ir_triop_csel, r08FB, r08FD, body.constant(0u)), 0x01));


                              body.instructions = f08F2_parent_instructions;
                              body.emit(f08F2);

                              /* END IF */

                              body.emit(assign(r08E9, body.constant(0u), 0x01));


                           body.instructions = f08EE_parent_instructions;
                           body.emit(f08EE);

                           /* END IF */

                           ir_expression *const r08FE = nequal(r08E5, body.constant(0u));
                           ir_expression *const r08FF = expr(ir_unop_b2i, r08FE);
                           ir_expression *const r0900 = expr(ir_unop_i2u, r08FF);
                           body.emit(assign(r08E7, bit_or(r08E7, r0900), 0x01));


                        body.instructions = f08EC_parent_instructions;
                        body.emit(f08EC);

                        /* END IF */

                        body.emit(assign(r08CF, r08E9, 0x01));

                        body.emit(assign(r08D0, r08E8, 0x01));

                        body.emit(assign(r08D1, r08E7, 0x01));

                        body.emit(assign(r08CE, body.constant(int(0)), 0x01));

                        body.emit(assign(r08D4, less(r08E7, body.constant(0u)), 0x01));


                     body.instructions = f08E3_parent_instructions;
                     body.emit(f08E3);

                     /* END IF */


                  body.instructions = f08D8_parent_instructions;
                  body.emit(f08D8);

                  /* END IF */


               body.instructions = f08D6_parent_instructions;
               body.emit(f08D6);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0901 = new(mem_ctx) ir_if(operand(r08D2).val);
               exec_list *const f0901_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0901->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0902 = new(mem_ctx) ir_if(operand(r08D4).val);
                  exec_list *const f0902_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0902->then_instructions;

                     ir_variable *const r0903 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0903, add(r08D0, body.constant(1u)), 0x01));

                     ir_expression *const r0904 = less(r0903, r08D0);
                     ir_expression *const r0905 = expr(ir_unop_b2i, r0904);
                     ir_expression *const r0906 = expr(ir_unop_i2u, r0905);
                     body.emit(assign(r08CF, add(r08CF, r0906), 0x01));

                     ir_expression *const r0907 = equal(r08D1, body.constant(0u));
                     ir_expression *const r0908 = expr(ir_unop_b2i, r0907);
                     ir_expression *const r0909 = expr(ir_unop_i2u, r0908);
                     ir_expression *const r090A = add(r08D1, r0909);
                     ir_expression *const r090B = bit_and(r090A, body.constant(1u));
                     ir_expression *const r090C = expr(ir_unop_bit_not, r090B);
                     body.emit(assign(r08D0, bit_and(r0903, r090C), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0902->else_instructions;

                     ir_expression *const r090D = bit_or(r08CF, r08D0);
                     ir_expression *const r090E = equal(r090D, body.constant(0u));
                     body.emit(assign(r08CE, expr(ir_triop_csel, r090E, body.constant(int(0)), r08CE), 0x01));


                  body.instructions = f0902_parent_instructions;
                  body.emit(f0902);

                  /* END IF */

                  ir_variable *const r090F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r090F);
                  ir_expression *const r0910 = lshift(r07BA, body.constant(int(31)));
                  ir_expression *const r0911 = expr(ir_unop_i2u, r08CE);
                  ir_expression *const r0912 = lshift(r0911, body.constant(int(20)));
                  ir_expression *const r0913 = add(r0910, r0912);
                  body.emit(assign(r090F, add(r0913, r08CF), 0x02));

                  body.emit(assign(r090F, r08D0, 0x01));

                  body.emit(assign(r08D3, r090F, 0x03));

                  body.emit(assign(r08D2, body.constant(false), 0x01));


               body.instructions = f0901_parent_instructions;
               body.emit(f0901);

               /* END IF */

               body.emit(assign(r07B9, r08D3, 0x03));

               body.emit(assign(r07B8, body.constant(false), 0x01));


            body.instructions = f0853_parent_instructions;
            body.emit(f0853);

            /* END IF */


         body.instructions = f0834_parent_instructions;
         body.emit(f0834);

         /* END IF */


      body.instructions = f07F6_parent_instructions;
      body.emit(f07F6);

      /* END IF */


   body.instructions = f07D1_parent_instructions;
   body.emit(f07D1);

   /* END IF */

   body.emit(ret(r07B9));

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

   ir_variable *const r0914 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0914);
   ir_variable *const r0915 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0915);
   ir_variable *const r0916 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r0916);
   ir_variable *const r0917 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0917);
   ir_variable *const r0918 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0918);
   ir_expression *const r0919 = equal(r0916, body.constant(int(0)));
   ir_expression *const r091A = less(r0916, body.constant(int(32)));
   ir_expression *const r091B = neg(r0916);
   ir_expression *const r091C = bit_and(r091B, body.constant(int(31)));
   ir_expression *const r091D = lshift(r0914, r091C);
   ir_expression *const r091E = rshift(r0915, r0916);
   ir_expression *const r091F = bit_or(r091D, r091E);
   ir_expression *const r0920 = less(r0916, body.constant(int(64)));
   ir_expression *const r0921 = bit_and(r0916, body.constant(int(31)));
   ir_expression *const r0922 = rshift(r0914, r0921);
   ir_expression *const r0923 = expr(ir_triop_csel, r0920, r0922, body.constant(0u));
   ir_expression *const r0924 = expr(ir_triop_csel, r091A, r091F, r0923);
   body.emit(assign(r0918, expr(ir_triop_csel, r0919, r0914, r0924), 0x01));

   ir_expression *const r0925 = equal(r0916, body.constant(int(0)));
   ir_expression *const r0926 = less(r0916, body.constant(int(32)));
   ir_expression *const r0927 = rshift(r0914, r0916);
   ir_expression *const r0928 = expr(ir_triop_csel, r0926, r0927, body.constant(0u));
   body.emit(assign(r0917, expr(ir_triop_csel, r0925, r0914, r0928), 0x01));

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

   ir_variable *const r0929 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0929);
   ir_variable *const r092A = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r092B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r092B);
   ir_variable *const r092C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r092C);
   ir_variable *const r092D = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r092D, swizzle_x(r0929), 0x01));

   body.emit(assign(r092C, r092D, 0x01));

   ir_variable *const r092E = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r092E, bit_and(swizzle_y(r0929), body.constant(1048575u)), 0x01));

   body.emit(assign(r092B, r092E, 0x01));

   ir_variable *const r092F = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0930 = rshift(swizzle_y(r0929), body.constant(int(20)));
   ir_expression *const r0931 = bit_and(r0930, body.constant(2047u));
   body.emit(assign(r092F, expr(ir_unop_u2i, r0931), 0x01));

   ir_variable *const r0932 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0932, rshift(swizzle_y(r0929), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0934 = nequal(r0932, body.constant(0u));
   ir_if *f0933 = new(mem_ctx) ir_if(operand(r0934).val);
   exec_list *const f0933_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0933->then_instructions;

      body.emit(assign(r092A, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0933->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0936 = equal(r092F, body.constant(int(2047)));
      ir_expression *const r0937 = bit_or(r092E, swizzle_x(r0929));
      ir_expression *const r0938 = nequal(r0937, body.constant(0u));
      ir_expression *const r0939 = logic_and(r0936, r0938);
      ir_if *f0935 = new(mem_ctx) ir_if(operand(r0939).val);
      exec_list *const f0935_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0935->then_instructions;

         body.emit(assign(r092A, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0935->else_instructions;

         /* IF CONDITION */
         ir_expression *const r093B = nequal(r092F, body.constant(int(0)));
         ir_if *f093A = new(mem_ctx) ir_if(operand(r093B).val);
         exec_list *const f093A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f093A->then_instructions;

            body.emit(assign(r092B, bit_or(r092E, body.constant(1048576u)), 0x01));


         body.instructions = f093A_parent_instructions;
         body.emit(f093A);

         /* END IF */

         ir_variable *const r093C = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r093C, sub(body.constant(int(1063)), r092F), 0x01));

         /* IF CONDITION */
         ir_expression *const r093E = less(body.constant(int(0)), r093C);
         ir_if *f093D = new(mem_ctx) ir_if(operand(r093E).val);
         exec_list *const f093D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f093D->then_instructions;

            ir_variable *const r093F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r093F);
            ir_variable *const r0940 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0941 = neg(r093C);
            body.emit(assign(r0940, bit_and(r0941, body.constant(int(31))), 0x01));

            ir_variable *const r0942 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0943 = less(r093C, body.constant(int(32)));
            ir_expression *const r0944 = rshift(r092B, r093C);
            ir_expression *const r0945 = equal(r093C, body.constant(int(0)));
            ir_expression *const r0946 = expr(ir_triop_csel, r0945, r092B, body.constant(0u));
            body.emit(assign(r0942, expr(ir_triop_csel, r0943, r0944, r0946), 0x01));

            /* IF CONDITION */
            ir_expression *const r0948 = equal(r093C, body.constant(int(0)));
            ir_if *f0947 = new(mem_ctx) ir_if(operand(r0948).val);
            exec_list *const f0947_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0947->then_instructions;

               body.emit(assign(r093F, r092D, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0947->else_instructions;

               /* IF CONDITION */
               ir_expression *const r094A = less(r093C, body.constant(int(32)));
               ir_if *f0949 = new(mem_ctx) ir_if(operand(r094A).val);
               exec_list *const f0949_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0949->then_instructions;

                  ir_expression *const r094B = lshift(r092B, r0940);
                  ir_expression *const r094C = rshift(swizzle_x(r0929), r093C);
                  ir_expression *const r094D = bit_or(r094B, r094C);
                  ir_expression *const r094E = lshift(swizzle_x(r0929), r0940);
                  ir_expression *const r094F = nequal(r094E, body.constant(0u));
                  ir_expression *const r0950 = expr(ir_unop_b2i, r094F);
                  ir_expression *const r0951 = expr(ir_unop_i2u, r0950);
                  body.emit(assign(r093F, bit_or(r094D, r0951), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0949->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0953 = equal(r093C, body.constant(int(32)));
                  ir_if *f0952 = new(mem_ctx) ir_if(operand(r0953).val);
                  exec_list *const f0952_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0952->then_instructions;

                     ir_expression *const r0954 = nequal(swizzle_x(r0929), body.constant(0u));
                     ir_expression *const r0955 = expr(ir_unop_b2i, r0954);
                     ir_expression *const r0956 = expr(ir_unop_i2u, r0955);
                     body.emit(assign(r093F, bit_or(r092B, r0956), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0952->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0958 = less(r093C, body.constant(int(64)));
                     ir_if *f0957 = new(mem_ctx) ir_if(operand(r0958).val);
                     exec_list *const f0957_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0957->then_instructions;

                        ir_expression *const r0959 = bit_and(r093C, body.constant(int(31)));
                        ir_expression *const r095A = rshift(r092B, r0959);
                        ir_expression *const r095B = lshift(r092B, r0940);
                        ir_expression *const r095C = bit_or(r095B, swizzle_x(r0929));
                        ir_expression *const r095D = nequal(r095C, body.constant(0u));
                        ir_expression *const r095E = expr(ir_unop_b2i, r095D);
                        ir_expression *const r095F = expr(ir_unop_i2u, r095E);
                        body.emit(assign(r093F, bit_or(r095A, r095F), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0957->else_instructions;

                        ir_expression *const r0960 = bit_or(r092B, swizzle_x(r0929));
                        ir_expression *const r0961 = nequal(r0960, body.constant(0u));
                        ir_expression *const r0962 = expr(ir_unop_b2i, r0961);
                        body.emit(assign(r093F, expr(ir_unop_i2u, r0962), 0x01));


                     body.instructions = f0957_parent_instructions;
                     body.emit(f0957);

                     /* END IF */


                  body.instructions = f0952_parent_instructions;
                  body.emit(f0952);

                  /* END IF */


               body.instructions = f0949_parent_instructions;
               body.emit(f0949);

               /* END IF */


            body.instructions = f0947_parent_instructions;
            body.emit(f0947);

            /* END IF */

            body.emit(assign(r092B, r0942, 0x01));

            body.emit(assign(r092C, r093F, 0x01));


         body.instructions = f093D_parent_instructions;
         body.emit(f093D);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0964 = bit_and(r092B, body.constant(4294963200u));
         ir_expression *const r0965 = nequal(r0964, body.constant(0u));
         ir_if *f0963 = new(mem_ctx) ir_if(operand(r0965).val);
         exec_list *const f0963_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0963->then_instructions;

            ir_variable *const r0966 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0968 = nequal(r0932, body.constant(0u));
            ir_if *f0967 = new(mem_ctx) ir_if(operand(r0968).val);
            exec_list *const f0967_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0967->then_instructions;

               body.emit(assign(r0966, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0967->else_instructions;

               body.emit(assign(r0966, body.constant(4294967295u), 0x01));


            body.instructions = f0967_parent_instructions;
            body.emit(f0967);

            /* END IF */

            body.emit(assign(r092A, r0966, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0963->else_instructions;

            ir_variable *const r0969 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r096A = lshift(r092B, body.constant(int(20)));
            ir_expression *const r096B = rshift(r092C, body.constant(int(12)));
            body.emit(assign(r0969, bit_or(r096A, r096B), 0x01));

            /* IF CONDITION */
            ir_expression *const r096D = nequal(r0932, body.constant(0u));
            ir_expression *const r096E = nequal(r0969, body.constant(0u));
            ir_expression *const r096F = logic_and(r096D, r096E);
            ir_if *f096C = new(mem_ctx) ir_if(operand(r096F).val);
            exec_list *const f096C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f096C->then_instructions;

               ir_variable *const r0970 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0972 = nequal(r0932, body.constant(0u));
               ir_if *f0971 = new(mem_ctx) ir_if(operand(r0972).val);
               exec_list *const f0971_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0971->then_instructions;

                  body.emit(assign(r0970, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0971->else_instructions;

                  body.emit(assign(r0970, body.constant(4294967295u), 0x01));


               body.instructions = f0971_parent_instructions;
               body.emit(f0971);

               /* END IF */

               body.emit(assign(r092A, r0970, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f096C->else_instructions;

               body.emit(assign(r092A, r0969, 0x01));


            body.instructions = f096C_parent_instructions;
            body.emit(f096C);

            /* END IF */


         body.instructions = f0963_parent_instructions;
         body.emit(f0963);

         /* END IF */


      body.instructions = f0935_parent_instructions;
      body.emit(f0935);

      /* END IF */


   body.instructions = f0933_parent_instructions;
   body.emit(f0933);

   /* END IF */

   body.emit(ret(r092A));

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

   ir_variable *const r0973 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0973);
   ir_variable *const r0974 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0975 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0975);
   ir_variable *const r0976 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0976);
   /* IF CONDITION */
   ir_expression *const r0978 = equal(r0973, body.constant(0u));
   ir_if *f0977 = new(mem_ctx) ir_if(operand(r0978).val);
   exec_list *const f0977_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0977->then_instructions;

      body.emit(assign(r0974, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0977->else_instructions;

      ir_variable *const r0979 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r097A = equal(r0973, body.constant(0u));
      ir_expression *const r097B = expr(ir_unop_find_msb, r0973);
      ir_expression *const r097C = sub(body.constant(int(31)), r097B);
      ir_expression *const r097D = expr(ir_triop_csel, r097A, body.constant(int(32)), r097C);
      body.emit(assign(r0979, add(r097D, body.constant(int(21))), 0x01));

      body.emit(assign(r0976, body.constant(0u), 0x01));

      body.emit(assign(r0975, body.constant(0u), 0x01));

      ir_variable *const r097E = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r097F = neg(r0979);
      body.emit(assign(r097E, bit_and(r097F, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0981 = equal(r0979, body.constant(int(0)));
      ir_if *f0980 = new(mem_ctx) ir_if(operand(r0981).val);
      exec_list *const f0980_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0980->then_instructions;

         body.emit(assign(r0976, body.constant(0u), 0x01));

         body.emit(assign(r0975, r0973, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0980->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0983 = less(r0979, body.constant(int(32)));
         ir_if *f0982 = new(mem_ctx) ir_if(operand(r0983).val);
         exec_list *const f0982_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0982->then_instructions;

            body.emit(assign(r0976, rshift(r0973, r097E), 0x01));

            body.emit(assign(r0975, lshift(r0973, r0979), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0982->else_instructions;

            ir_variable *const r0984 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0986 = less(r0979, body.constant(int(64)));
            ir_if *f0985 = new(mem_ctx) ir_if(operand(r0986).val);
            exec_list *const f0985_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0985->then_instructions;

               ir_expression *const r0987 = add(r0979, body.constant(int(-32)));
               body.emit(assign(r0984, lshift(r0973, r0987), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0985->else_instructions;

               body.emit(assign(r0984, body.constant(0u), 0x01));


            body.instructions = f0985_parent_instructions;
            body.emit(f0985);

            /* END IF */

            body.emit(assign(r0976, r0984, 0x01));

            body.emit(assign(r0975, body.constant(0u), 0x01));


         body.instructions = f0982_parent_instructions;
         body.emit(f0982);

         /* END IF */


      body.instructions = f0980_parent_instructions;
      body.emit(f0980);

      /* END IF */

      ir_variable *const r0988 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0988);
      ir_expression *const r0989 = sub(body.constant(int(1074)), r0979);
      ir_expression *const r098A = expr(ir_unop_i2u, r0989);
      ir_expression *const r098B = lshift(r098A, body.constant(int(20)));
      body.emit(assign(r0988, add(r098B, r0976), 0x02));

      body.emit(assign(r0988, r0975, 0x01));

      body.emit(assign(r0974, r0988, 0x03));


   body.instructions = f0977_parent_instructions;
   body.emit(f0977);

   /* END IF */

   body.emit(ret(r0974));

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

   ir_variable *const r098C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r098C);
   ir_variable *const r098D = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r098D, body.constant(true), 0x01));

   ir_variable *const r098E = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r098F = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r098F);
   ir_variable *const r0990 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0990);
   ir_variable *const r0991 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0991);
   ir_variable *const r0992 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0992, bit_and(swizzle_y(r098C), body.constant(1048575u)), 0x01));

   body.emit(assign(r0991, r0992, 0x01));

   ir_variable *const r0993 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0994 = rshift(swizzle_y(r098C), body.constant(int(20)));
   ir_expression *const r0995 = bit_and(r0994, body.constant(2047u));
   body.emit(assign(r0993, expr(ir_unop_u2i, r0995), 0x01));

   body.emit(assign(r0990, rshift(swizzle_y(r098C), body.constant(int(31))), 0x01));

   body.emit(assign(r098F, body.constant(0u), 0x01));

   ir_variable *const r0996 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0996, add(r0993, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0998 = gequal(r0996, body.constant(int(0)));
   ir_if *f0997 = new(mem_ctx) ir_if(operand(r0998).val);
   exec_list *const f0997_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0997->then_instructions;

      /* IF CONDITION */
      ir_expression *const r099A = less(body.constant(int(1054)), r0993);
      ir_if *f0999 = new(mem_ctx) ir_if(operand(r099A).val);
      exec_list *const f0999_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0999->then_instructions;

         /* IF CONDITION */
         ir_expression *const r099C = equal(r0993, body.constant(int(2047)));
         ir_expression *const r099D = bit_or(r0992, swizzle_x(r098C));
         ir_expression *const r099E = expr(ir_unop_u2i, r099D);
         ir_expression *const r099F = expr(ir_unop_i2b, r099E);
         ir_expression *const r09A0 = logic_and(r099C, r099F);
         ir_if *f099B = new(mem_ctx) ir_if(operand(r09A0).val);
         exec_list *const f099B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f099B->then_instructions;

            body.emit(assign(r0990, body.constant(0u), 0x01));


         body.instructions = f099B_parent_instructions;
         body.emit(f099B);

         /* END IF */

         ir_variable *const r09A1 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09A3 = expr(ir_unop_u2i, r0990);
         ir_expression *const r09A4 = expr(ir_unop_i2b, r09A3);
         ir_if *f09A2 = new(mem_ctx) ir_if(operand(r09A4).val);
         exec_list *const f09A2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09A2->then_instructions;

            body.emit(assign(r09A1, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09A2->else_instructions;

            body.emit(assign(r09A1, body.constant(int(2147483647)), 0x01));


         body.instructions = f09A2_parent_instructions;
         body.emit(f09A2);

         /* END IF */

         body.emit(assign(r098E, r09A1, 0x01));

         body.emit(assign(r098D, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0999->else_instructions;

         ir_variable *const r09A5 = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r09A5, bit_or(r0992, body.constant(1048576u)), 0x01));

         ir_expression *const r09A6 = equal(r0996, body.constant(int(0)));
         ir_expression *const r09A7 = lshift(r09A5, r0996);
         ir_expression *const r09A8 = neg(r0996);
         ir_expression *const r09A9 = bit_and(r09A8, body.constant(int(31)));
         ir_expression *const r09AA = rshift(swizzle_x(r098C), r09A9);
         ir_expression *const r09AB = bit_or(r09A7, r09AA);
         body.emit(assign(r098F, expr(ir_triop_csel, r09A6, r09A5, r09AB), 0x01));


      body.instructions = f0999_parent_instructions;
      body.emit(f0999);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0997->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09AD = less(r0993, body.constant(int(1023)));
      ir_if *f09AC = new(mem_ctx) ir_if(operand(r09AD).val);
      exec_list *const f09AC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09AC->then_instructions;

         body.emit(assign(r098E, body.constant(int(0)), 0x01));

         body.emit(assign(r098D, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09AC->else_instructions;

         body.emit(assign(r0991, bit_or(r0992, body.constant(1048576u)), 0x01));

         ir_expression *const r09AE = neg(r0996);
         body.emit(assign(r098F, rshift(r0991, r09AE), 0x01));


      body.instructions = f09AC_parent_instructions;
      body.emit(f09AC);

      /* END IF */


   body.instructions = f0997_parent_instructions;
   body.emit(f0997);

   /* END IF */

   /* IF CONDITION */
   ir_if *f09AF = new(mem_ctx) ir_if(operand(r098D).val);
   exec_list *const f09AF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09AF->then_instructions;

      ir_variable *const r09B0 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09B2 = nequal(r0990, body.constant(0u));
      ir_if *f09B1 = new(mem_ctx) ir_if(operand(r09B2).val);
      exec_list *const f09B1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09B1->then_instructions;

         ir_expression *const r09B3 = expr(ir_unop_u2i, r098F);
         body.emit(assign(r09B0, neg(r09B3), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09B1->else_instructions;

         body.emit(assign(r09B0, expr(ir_unop_u2i, r098F), 0x01));


      body.instructions = f09B1_parent_instructions;
      body.emit(f09B1);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r09B5 = less(r09B0, body.constant(int(0)));
      ir_expression *const r09B6 = expr(ir_unop_b2i, r09B5);
      ir_expression *const r09B7 = expr(ir_unop_i2u, r09B6);
      ir_expression *const r09B8 = bit_xor(r0990, r09B7);
      ir_expression *const r09B9 = expr(ir_unop_u2i, r09B8);
      ir_expression *const r09BA = expr(ir_unop_i2b, r09B9);
      ir_expression *const r09BB = expr(ir_unop_i2b, r09B0);
      ir_expression *const r09BC = logic_and(r09BA, r09BB);
      ir_if *f09B4 = new(mem_ctx) ir_if(operand(r09BC).val);
      exec_list *const f09B4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09B4->then_instructions;

         ir_variable *const r09BD = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09BF = expr(ir_unop_u2i, r0990);
         ir_expression *const r09C0 = expr(ir_unop_i2b, r09BF);
         ir_if *f09BE = new(mem_ctx) ir_if(operand(r09C0).val);
         exec_list *const f09BE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09BE->then_instructions;

            body.emit(assign(r09BD, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09BE->else_instructions;

            body.emit(assign(r09BD, body.constant(int(2147483647)), 0x01));


         body.instructions = f09BE_parent_instructions;
         body.emit(f09BE);

         /* END IF */

         body.emit(assign(r098E, r09BD, 0x01));

         body.emit(assign(r098D, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09B4->else_instructions;

         body.emit(assign(r098E, r09B0, 0x01));

         body.emit(assign(r098D, body.constant(false), 0x01));


      body.instructions = f09B4_parent_instructions;
      body.emit(f09B4);

      /* END IF */


   body.instructions = f09AF_parent_instructions;
   body.emit(f09AF);

   /* END IF */

   body.emit(ret(r098E));

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

   ir_variable *const r09C1 = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r09C1);
   ir_variable *const r09C2 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r09C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r09C3);
   ir_variable *const r09C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r09C4);
   ir_variable *const r09C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r09C5);
   body.emit(assign(r09C5, body.constant(0u), 0x01));

   body.emit(assign(r09C4, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r09C7 = equal(r09C1, body.constant(int(0)));
   ir_if *f09C6 = new(mem_ctx) ir_if(operand(r09C7).val);
   exec_list *const f09C6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09C6->then_instructions;

      ir_variable *const r09C8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r09C8);
      body.emit(assign(r09C8, body.constant(0u), 0x02));

      body.emit(assign(r09C8, body.constant(0u), 0x01));

      body.emit(assign(r09C2, r09C8, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09C6->else_instructions;

      ir_expression *const r09C9 = less(r09C1, body.constant(int(0)));
      ir_expression *const r09CA = expr(ir_unop_b2i, r09C9);
      body.emit(assign(r09C3, expr(ir_unop_i2u, r09CA), 0x01));

      ir_variable *const r09CB = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09CD = less(r09C1, body.constant(int(0)));
      ir_if *f09CC = new(mem_ctx) ir_if(operand(r09CD).val);
      exec_list *const f09CC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09CC->then_instructions;

         ir_expression *const r09CE = neg(r09C1);
         body.emit(assign(r09CB, expr(ir_unop_i2u, r09CE), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09CC->else_instructions;

         body.emit(assign(r09CB, expr(ir_unop_i2u, r09C1), 0x01));


      body.instructions = f09CC_parent_instructions;
      body.emit(f09CC);

      /* END IF */

      ir_variable *const r09CF = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r09D0 = equal(r09CB, body.constant(0u));
      ir_expression *const r09D1 = expr(ir_unop_find_msb, r09CB);
      ir_expression *const r09D2 = sub(body.constant(int(31)), r09D1);
      ir_expression *const r09D3 = expr(ir_triop_csel, r09D0, body.constant(int(32)), r09D2);
      body.emit(assign(r09CF, add(r09D3, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r09D5 = gequal(r09CF, body.constant(int(0)));
      ir_if *f09D4 = new(mem_ctx) ir_if(operand(r09D5).val);
      exec_list *const f09D4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09D4->then_instructions;

         body.emit(assign(r09C5, lshift(r09CB, r09CF), 0x01));

         body.emit(assign(r09C4, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09D4->else_instructions;

         ir_variable *const r09D6 = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r09D6, neg(r09CF), 0x01));

         ir_expression *const r09D7 = equal(r09D6, body.constant(int(0)));
         ir_expression *const r09D8 = less(r09D6, body.constant(int(32)));
         ir_expression *const r09D9 = rshift(r09CB, r09D6);
         ir_expression *const r09DA = expr(ir_triop_csel, r09D8, r09D9, body.constant(0u));
         body.emit(assign(r09C5, expr(ir_triop_csel, r09D7, r09CB, r09DA), 0x01));

         ir_expression *const r09DB = equal(r09D6, body.constant(int(0)));
         ir_expression *const r09DC = less(r09D6, body.constant(int(32)));
         ir_expression *const r09DD = neg(r09D6);
         ir_expression *const r09DE = bit_and(r09DD, body.constant(int(31)));
         ir_expression *const r09DF = lshift(r09CB, r09DE);
         ir_expression *const r09E0 = bit_or(r09DF, body.constant(0u));
         ir_expression *const r09E1 = less(r09D6, body.constant(int(64)));
         ir_expression *const r09E2 = bit_and(r09D6, body.constant(int(31)));
         ir_expression *const r09E3 = rshift(r09CB, r09E2);
         ir_expression *const r09E4 = expr(ir_triop_csel, r09E1, r09E3, body.constant(0u));
         ir_expression *const r09E5 = expr(ir_triop_csel, r09DC, r09E0, r09E4);
         body.emit(assign(r09C4, expr(ir_triop_csel, r09DB, r09CB, r09E5), 0x01));


      body.instructions = f09D4_parent_instructions;
      body.emit(f09D4);

      /* END IF */

      ir_variable *const r09E6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r09E6);
      ir_expression *const r09E7 = lshift(r09C3, body.constant(int(31)));
      ir_expression *const r09E8 = sub(body.constant(int(1042)), r09CF);
      ir_expression *const r09E9 = expr(ir_unop_i2u, r09E8);
      ir_expression *const r09EA = lshift(r09E9, body.constant(int(20)));
      ir_expression *const r09EB = add(r09E7, r09EA);
      body.emit(assign(r09E6, add(r09EB, r09C5), 0x02));

      body.emit(assign(r09E6, r09C4, 0x01));

      body.emit(assign(r09C2, r09E6, 0x03));


   body.instructions = f09C6_parent_instructions;
   body.emit(f09C6);

   /* END IF */

   body.emit(ret(r09C2));

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

   ir_variable *const r09EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r09EC);
   ir_variable *const r09ED = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r09ED);
   ir_variable *const r09EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r09EE);
   ir_variable *const r09EF = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r09F0 = lshift(r09EC, body.constant(int(31)));
   ir_expression *const r09F1 = expr(ir_unop_i2u, r09ED);
   ir_expression *const r09F2 = lshift(r09F1, body.constant(int(23)));
   ir_expression *const r09F3 = add(r09F0, r09F2);
   ir_expression *const r09F4 = add(r09F3, r09EE);
   body.emit(assign(r09EF, expr(ir_unop_bitcast_u2f, r09F4), 0x01));

   body.emit(ret(r09EF));

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

   ir_variable *const r09F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r09F5);
   ir_variable *const r09F6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r09F6);
   ir_variable *const r09F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r09F7);
   ir_variable *const r09F8 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r09F8, body.constant(true), 0x01));

   ir_variable *const r09F9 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r09FA = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r09FA);
   ir_expression *const r09FB = bit_and(r09F7, body.constant(127u));
   body.emit(assign(r09FA, expr(ir_unop_u2i, r09FB), 0x01));

   /* IF CONDITION */
   ir_expression *const r09FD = expr(ir_unop_i2u, r09F6);
   ir_expression *const r09FE = gequal(r09FD, body.constant(253u));
   ir_if *f09FC = new(mem_ctx) ir_if(operand(r09FE).val);
   exec_list *const f09FC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09FC->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A00 = less(body.constant(int(253)), r09F6);
      ir_expression *const r0A01 = equal(r09F6, body.constant(int(253)));
      ir_expression *const r0A02 = expr(ir_unop_u2i, r09F7);
      ir_expression *const r0A03 = less(r0A02, body.constant(int(-64)));
      ir_expression *const r0A04 = logic_and(r0A01, r0A03);
      ir_expression *const r0A05 = logic_or(r0A00, r0A04);
      ir_if *f09FF = new(mem_ctx) ir_if(operand(r0A05).val);
      exec_list *const f09FF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09FF->then_instructions;

         ir_expression *const r0A06 = lshift(r09F5, body.constant(int(31)));
         ir_expression *const r0A07 = add(r0A06, body.constant(2139095040u));
         body.emit(assign(r09F9, expr(ir_unop_bitcast_u2f, r0A07), 0x01));

         body.emit(assign(r09F8, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09FF->else_instructions;

         ir_variable *const r0A08 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0A08, neg(r09F6), 0x01));

         ir_variable *const r0A09 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
         body.emit(assign(r0A09, less(r09F6, body.constant(int(0))), 0x01));

         ir_variable *const r0A0A = body.make_temp(glsl_type::uint_type, "mix_retval");
         ir_expression *const r0A0B = neg(r09F6);
         ir_expression *const r0A0C = less(r0A0B, body.constant(int(32)));
         ir_expression *const r0A0D = rshift(r09F7, r0A08);
         ir_expression *const r0A0E = neg(r0A08);
         ir_expression *const r0A0F = bit_and(r0A0E, body.constant(int(31)));
         ir_expression *const r0A10 = lshift(r09F7, r0A0F);
         ir_expression *const r0A11 = nequal(r0A10, body.constant(0u));
         ir_expression *const r0A12 = expr(ir_unop_b2i, r0A11);
         ir_expression *const r0A13 = expr(ir_unop_i2u, r0A12);
         ir_expression *const r0A14 = bit_or(r0A0D, r0A13);
         ir_expression *const r0A15 = nequal(r09F7, body.constant(0u));
         ir_expression *const r0A16 = expr(ir_unop_b2i, r0A15);
         ir_expression *const r0A17 = expr(ir_unop_i2u, r0A16);
         ir_expression *const r0A18 = expr(ir_triop_csel, r0A0C, r0A14, r0A17);
         body.emit(assign(r0A0A, expr(ir_triop_csel, r0A09, r0A18, r09F7), 0x01));

         body.emit(assign(r09F7, r0A0A, 0x01));

         ir_expression *const r0A19 = expr(ir_unop_u2i, r0A0A);
         ir_expression *const r0A1A = bit_and(r0A19, body.constant(int(127)));
         body.emit(assign(r09FA, expr(ir_triop_csel, r0A09, r0A1A, r09FA), 0x01));

         body.emit(assign(r09F6, expr(ir_triop_csel, r0A09, body.constant(int(0)), r09F6), 0x01));


      body.instructions = f09FF_parent_instructions;
      body.emit(f09FF);

      /* END IF */


   body.instructions = f09FC_parent_instructions;
   body.emit(f09FC);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0A1B = new(mem_ctx) ir_if(operand(r09F8).val);
   exec_list *const f0A1B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A1B->then_instructions;

      ir_expression *const r0A1C = add(r09F7, body.constant(64u));
      body.emit(assign(r09F7, rshift(r0A1C, body.constant(int(7))), 0x01));

      ir_expression *const r0A1D = bit_xor(r09FA, body.constant(int(64)));
      ir_expression *const r0A1E = equal(r0A1D, body.constant(int(0)));
      ir_expression *const r0A1F = expr(ir_unop_b2i, r0A1E);
      ir_expression *const r0A20 = expr(ir_unop_i2u, r0A1F);
      ir_expression *const r0A21 = expr(ir_unop_bit_not, r0A20);
      body.emit(assign(r09F7, bit_and(r09F7, r0A21), 0x01));

      ir_expression *const r0A22 = lshift(r09F5, body.constant(int(31)));
      ir_expression *const r0A23 = equal(r09F7, body.constant(0u));
      ir_expression *const r0A24 = expr(ir_triop_csel, r0A23, body.constant(int(0)), r09F6);
      ir_expression *const r0A25 = expr(ir_unop_i2u, r0A24);
      ir_expression *const r0A26 = lshift(r0A25, body.constant(int(23)));
      ir_expression *const r0A27 = add(r0A22, r0A26);
      ir_expression *const r0A28 = add(r0A27, r09F7);
      body.emit(assign(r09F9, expr(ir_unop_bitcast_u2f, r0A28), 0x01));

      body.emit(assign(r09F8, body.constant(false), 0x01));


   body.instructions = f0A1B_parent_instructions;
   body.emit(f0A1B);

   /* END IF */

   body.emit(ret(r09F9));

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

   ir_variable *const r0A29 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A29);
   ir_variable *const r0A2A = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A2B = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0A2B, swizzle_x(r0A29), 0x01));

   ir_variable *const r0A2C = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A2C, bit_and(swizzle_y(r0A29), body.constant(1048575u)), 0x01));

   ir_variable *const r0A2D = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A2E = rshift(swizzle_y(r0A29), body.constant(int(20)));
   ir_expression *const r0A2F = bit_and(r0A2E, body.constant(2047u));
   body.emit(assign(r0A2D, expr(ir_unop_u2i, r0A2F), 0x01));

   ir_variable *const r0A30 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A30, rshift(swizzle_y(r0A29), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A32 = equal(r0A2D, body.constant(int(2047)));
   ir_if *f0A31 = new(mem_ctx) ir_if(operand(r0A32).val);
   exec_list *const f0A31_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A31->then_instructions;

      ir_variable *const r0A33 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0A33);
      ir_variable *const r0A34 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0A34, lshift(swizzle_x(r0A29), body.constant(int(12))), 0x01));

      ir_expression *const r0A35 = lshift(swizzle_y(r0A29), body.constant(int(12)));
      ir_expression *const r0A36 = rshift(swizzle_x(r0A29), body.constant(int(20)));
      body.emit(assign(r0A29, bit_or(r0A35, r0A36), 0x02));

      body.emit(assign(r0A29, r0A34, 0x01));

      ir_expression *const r0A37 = lshift(r0A30, body.constant(int(31)));
      ir_expression *const r0A38 = bit_or(r0A37, body.constant(2143289344u));
      ir_expression *const r0A39 = rshift(swizzle_y(r0A29), body.constant(int(9)));
      ir_expression *const r0A3A = bit_or(r0A38, r0A39);
      body.emit(assign(r0A33, expr(ir_unop_bitcast_u2f, r0A3A), 0x01));

      ir_variable *const r0A3B = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0A3C = bit_or(r0A2C, r0A2B);
      ir_expression *const r0A3D = nequal(r0A3C, body.constant(0u));
      ir_expression *const r0A3E = lshift(r0A30, body.constant(int(31)));
      ir_expression *const r0A3F = add(r0A3E, body.constant(2139095040u));
      ir_expression *const r0A40 = expr(ir_unop_bitcast_u2f, r0A3F);
      body.emit(assign(r0A3B, expr(ir_triop_csel, r0A3D, r0A33, r0A40), 0x01));

      body.emit(assign(r0A33, r0A3B, 0x01));

      body.emit(assign(r0A2A, r0A3B, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A31->else_instructions;

      ir_variable *const r0A41 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0A41);
      ir_variable *const r0A42 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0A42, rshift(r0A2C, body.constant(int(22))), 0x01));

      ir_expression *const r0A43 = lshift(r0A2C, body.constant(int(10)));
      ir_expression *const r0A44 = rshift(r0A2B, body.constant(int(22)));
      ir_expression *const r0A45 = bit_or(r0A43, r0A44);
      ir_expression *const r0A46 = lshift(r0A2B, body.constant(int(10)));
      ir_expression *const r0A47 = nequal(r0A46, body.constant(0u));
      ir_expression *const r0A48 = expr(ir_unop_b2i, r0A47);
      ir_expression *const r0A49 = expr(ir_unop_i2u, r0A48);
      body.emit(assign(r0A41, bit_or(r0A45, r0A49), 0x01));

      ir_variable *const r0A4A = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A4B = nequal(r0A2D, body.constant(int(0)));
      ir_expression *const r0A4C = bit_or(r0A41, body.constant(1073741824u));
      body.emit(assign(r0A4A, expr(ir_triop_csel, r0A4B, r0A4C, r0A41), 0x01));

      ir_variable *const r0A4D = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0A4D, add(r0A2D, body.constant(int(-897))), 0x01));

      ir_variable *const r0A4E = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0A4E, r0A4A, 0x01));

      ir_variable *const r0A4F = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0A4F, body.constant(true), 0x01));

      ir_variable *const r0A50 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0A51 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0A51);
      ir_expression *const r0A52 = bit_and(r0A4A, body.constant(127u));
      body.emit(assign(r0A51, expr(ir_unop_u2i, r0A52), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A54 = expr(ir_unop_i2u, r0A4D);
      ir_expression *const r0A55 = gequal(r0A54, body.constant(253u));
      ir_if *f0A53 = new(mem_ctx) ir_if(operand(r0A55).val);
      exec_list *const f0A53_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A53->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A57 = less(body.constant(int(253)), r0A4D);
         ir_expression *const r0A58 = equal(r0A4D, body.constant(int(253)));
         ir_expression *const r0A59 = expr(ir_unop_u2i, r0A4A);
         ir_expression *const r0A5A = less(r0A59, body.constant(int(-64)));
         ir_expression *const r0A5B = logic_and(r0A58, r0A5A);
         ir_expression *const r0A5C = logic_or(r0A57, r0A5B);
         ir_if *f0A56 = new(mem_ctx) ir_if(operand(r0A5C).val);
         exec_list *const f0A56_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A56->then_instructions;

            ir_expression *const r0A5D = lshift(r0A30, body.constant(int(31)));
            ir_expression *const r0A5E = add(r0A5D, body.constant(2139095040u));
            body.emit(assign(r0A50, expr(ir_unop_bitcast_u2f, r0A5E), 0x01));

            body.emit(assign(r0A4F, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A56->else_instructions;

            ir_variable *const r0A5F = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0A5F, neg(r0A4D), 0x01));

            ir_variable *const r0A60 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0A60, less(r0A4D, body.constant(int(0))), 0x01));

            ir_variable *const r0A61 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0A62 = neg(r0A4D);
            ir_expression *const r0A63 = less(r0A62, body.constant(int(32)));
            ir_expression *const r0A64 = rshift(r0A4A, r0A5F);
            ir_expression *const r0A65 = neg(r0A5F);
            ir_expression *const r0A66 = bit_and(r0A65, body.constant(int(31)));
            ir_expression *const r0A67 = lshift(r0A4A, r0A66);
            ir_expression *const r0A68 = nequal(r0A67, body.constant(0u));
            ir_expression *const r0A69 = expr(ir_unop_b2i, r0A68);
            ir_expression *const r0A6A = expr(ir_unop_i2u, r0A69);
            ir_expression *const r0A6B = bit_or(r0A64, r0A6A);
            ir_expression *const r0A6C = nequal(r0A4A, body.constant(0u));
            ir_expression *const r0A6D = expr(ir_unop_b2i, r0A6C);
            ir_expression *const r0A6E = expr(ir_unop_i2u, r0A6D);
            ir_expression *const r0A6F = expr(ir_triop_csel, r0A63, r0A6B, r0A6E);
            body.emit(assign(r0A61, expr(ir_triop_csel, r0A60, r0A6F, r0A4A), 0x01));

            body.emit(assign(r0A4E, r0A61, 0x01));

            ir_expression *const r0A70 = expr(ir_unop_u2i, r0A61);
            ir_expression *const r0A71 = bit_and(r0A70, body.constant(int(127)));
            body.emit(assign(r0A51, expr(ir_triop_csel, r0A60, r0A71, r0A51), 0x01));

            body.emit(assign(r0A4D, expr(ir_triop_csel, r0A60, body.constant(int(0)), r0A4D), 0x01));


         body.instructions = f0A56_parent_instructions;
         body.emit(f0A56);

         /* END IF */


      body.instructions = f0A53_parent_instructions;
      body.emit(f0A53);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A72 = new(mem_ctx) ir_if(operand(r0A4F).val);
      exec_list *const f0A72_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A72->then_instructions;

         ir_expression *const r0A73 = add(r0A4E, body.constant(64u));
         body.emit(assign(r0A4E, rshift(r0A73, body.constant(int(7))), 0x01));

         ir_expression *const r0A74 = bit_xor(r0A51, body.constant(int(64)));
         ir_expression *const r0A75 = equal(r0A74, body.constant(int(0)));
         ir_expression *const r0A76 = expr(ir_unop_b2i, r0A75);
         ir_expression *const r0A77 = expr(ir_unop_i2u, r0A76);
         ir_expression *const r0A78 = expr(ir_unop_bit_not, r0A77);
         body.emit(assign(r0A4E, bit_and(r0A4E, r0A78), 0x01));

         ir_expression *const r0A79 = lshift(r0A30, body.constant(int(31)));
         ir_expression *const r0A7A = equal(r0A4E, body.constant(0u));
         ir_expression *const r0A7B = expr(ir_triop_csel, r0A7A, body.constant(int(0)), r0A4D);
         ir_expression *const r0A7C = expr(ir_unop_i2u, r0A7B);
         ir_expression *const r0A7D = lshift(r0A7C, body.constant(int(23)));
         ir_expression *const r0A7E = add(r0A79, r0A7D);
         ir_expression *const r0A7F = add(r0A7E, r0A4E);
         body.emit(assign(r0A50, expr(ir_unop_bitcast_u2f, r0A7F), 0x01));

         body.emit(assign(r0A4F, body.constant(false), 0x01));


      body.instructions = f0A72_parent_instructions;
      body.emit(f0A72);

      /* END IF */

      body.emit(assign(r0A2A, r0A50, 0x01));


   body.instructions = f0A31_parent_instructions;
   body.emit(f0A31);

   /* END IF */

   body.emit(ret(r0A2A));

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

   ir_variable *const r0A80 = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0A80);
   ir_variable *const r0A81 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A81, body.constant(true), 0x01));

   ir_variable *const r0A82 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A83 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A83);
   ir_variable *const r0A84 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0A84);
   ir_variable *const r0A85 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0A85);
   ir_variable *const r0A86 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0A86, expr(ir_unop_bitcast_f2u, r0A80), 0x01));

   ir_variable *const r0A87 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0A87, bit_and(r0A86, body.constant(8388607u)), 0x01));

   body.emit(assign(r0A85, r0A87, 0x01));

   ir_variable *const r0A88 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A89 = rshift(r0A86, body.constant(int(23)));
   ir_expression *const r0A8A = bit_and(r0A89, body.constant(255u));
   body.emit(assign(r0A88, expr(ir_unop_u2i, r0A8A), 0x01));

   body.emit(assign(r0A84, r0A88, 0x01));

   body.emit(assign(r0A83, rshift(r0A86, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A8C = equal(r0A88, body.constant(int(255)));
   ir_if *f0A8B = new(mem_ctx) ir_if(operand(r0A8C).val);
   exec_list *const f0A8B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A8B->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A8E = nequal(r0A87, body.constant(0u));
      ir_if *f0A8D = new(mem_ctx) ir_if(operand(r0A8E).val);
      exec_list *const f0A8D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A8D->then_instructions;

         ir_variable *const r0A8F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0A8F, lshift(r0A86, body.constant(int(9))), 0x01));

         ir_variable *const r0A90 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0A91 = lshift(r0A8F, body.constant(int(20)));
         body.emit(assign(r0A90, bit_or(r0A91, body.constant(0u)), 0x01));

         ir_expression *const r0A92 = rshift(r0A8F, body.constant(int(12)));
         ir_expression *const r0A93 = lshift(r0A83, body.constant(int(31)));
         ir_expression *const r0A94 = bit_or(r0A93, body.constant(2146959360u));
         body.emit(assign(r0A90, bit_or(r0A92, r0A94), 0x02));

         body.emit(assign(r0A82, r0A90, 0x03));

         body.emit(assign(r0A81, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A8D->else_instructions;

         ir_variable *const r0A95 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0A95);
         ir_expression *const r0A96 = lshift(r0A83, body.constant(int(31)));
         body.emit(assign(r0A95, add(r0A96, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0A95, body.constant(0u), 0x01));

         body.emit(assign(r0A82, r0A95, 0x03));

         body.emit(assign(r0A81, body.constant(false), 0x01));


      body.instructions = f0A8D_parent_instructions;
      body.emit(f0A8D);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A8B->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A98 = equal(r0A88, body.constant(int(0)));
      ir_if *f0A97 = new(mem_ctx) ir_if(operand(r0A98).val);
      exec_list *const f0A97_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A97->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A9A = equal(r0A87, body.constant(0u));
         ir_if *f0A99 = new(mem_ctx) ir_if(operand(r0A9A).val);
         exec_list *const f0A99_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A99->then_instructions;

            ir_variable *const r0A9B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0A9B);
            body.emit(assign(r0A9B, lshift(r0A83, body.constant(int(31))), 0x02));

            body.emit(assign(r0A9B, body.constant(0u), 0x01));

            body.emit(assign(r0A82, r0A9B, 0x03));

            body.emit(assign(r0A81, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A99->else_instructions;

            ir_variable *const r0A9C = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0A9D = equal(r0A87, body.constant(0u));
            ir_expression *const r0A9E = expr(ir_unop_find_msb, r0A87);
            ir_expression *const r0A9F = sub(body.constant(int(31)), r0A9E);
            ir_expression *const r0AA0 = expr(ir_triop_csel, r0A9D, body.constant(int(32)), r0A9F);
            body.emit(assign(r0A9C, add(r0AA0, body.constant(int(-8))), 0x01));

            body.emit(assign(r0A85, lshift(r0A87, r0A9C), 0x01));

            body.emit(assign(r0A84, sub(body.constant(int(1)), r0A9C), 0x01));

            body.emit(assign(r0A84, add(r0A84, body.constant(int(-1))), 0x01));


         body.instructions = f0A99_parent_instructions;
         body.emit(f0A99);

         /* END IF */


      body.instructions = f0A97_parent_instructions;
      body.emit(f0A97);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0AA1 = new(mem_ctx) ir_if(operand(r0A81).val);
      exec_list *const f0AA1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AA1->then_instructions;

         ir_variable *const r0AA2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0AA2);
         ir_expression *const r0AA3 = lshift(r0A83, body.constant(int(31)));
         ir_expression *const r0AA4 = add(r0A84, body.constant(int(896)));
         ir_expression *const r0AA5 = expr(ir_unop_i2u, r0AA4);
         ir_expression *const r0AA6 = lshift(r0AA5, body.constant(int(20)));
         ir_expression *const r0AA7 = add(r0AA3, r0AA6);
         ir_expression *const r0AA8 = rshift(r0A85, body.constant(int(3)));
         body.emit(assign(r0AA2, add(r0AA7, r0AA8), 0x02));

         ir_expression *const r0AA9 = lshift(r0A85, body.constant(int(29)));
         body.emit(assign(r0AA2, bit_or(r0AA9, body.constant(0u)), 0x01));

         body.emit(assign(r0A82, r0AA2, 0x03));

         body.emit(assign(r0A81, body.constant(false), 0x01));


      body.instructions = f0AA1_parent_instructions;
      body.emit(f0AA1);

      /* END IF */


   body.instructions = f0A8B_parent_instructions;
   body.emit(f0A8B);

   /* END IF */

   body.emit(ret(r0A82));

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

   ir_variable *const r0AAA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0AAA);
   ir_variable *const r0AAB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0AAB);
   ir_variable *const r0AAC = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0AAC);
   ir_variable *const r0AAD = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0AAD);
   ir_variable *const r0AAE = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0AAE);
   ir_variable *const r0AAF = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0AAF);
   ir_variable *const r0AB0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AB0);
   ir_variable *const r0AB1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AB1);
   ir_variable *const r0AB2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AB2);
   ir_variable *const r0AB3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0AB3);
   ir_variable *const r0AB4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0AB4);
   ir_variable *const r0AB5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0AB5, add(r0AAC, r0AAF), 0x01));

   ir_variable *const r0AB6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0AB7 = less(r0AB5, r0AAC);
   ir_expression *const r0AB8 = expr(ir_unop_b2i, r0AB7);
   body.emit(assign(r0AB6, expr(ir_unop_i2u, r0AB8), 0x01));

   ir_variable *const r0AB9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0AB9, add(r0AAB, r0AAE), 0x01));

   body.emit(assign(r0AB4, add(r0AB9, r0AB6), 0x01));

   ir_expression *const r0ABA = add(r0AAA, r0AAD);
   ir_expression *const r0ABB = less(r0AB4, r0AB6);
   ir_expression *const r0ABC = expr(ir_unop_b2i, r0ABB);
   ir_expression *const r0ABD = expr(ir_unop_i2u, r0ABC);
   body.emit(assign(r0AB3, add(r0ABA, r0ABD), 0x01));

   ir_expression *const r0ABE = less(r0AB9, r0AAB);
   ir_expression *const r0ABF = expr(ir_unop_b2i, r0ABE);
   ir_expression *const r0AC0 = expr(ir_unop_i2u, r0ABF);
   body.emit(assign(r0AB3, add(r0AB3, r0AC0), 0x01));

   body.emit(assign(r0AB2, r0AB5, 0x01));

   body.emit(assign(r0AB1, r0AB4, 0x01));

   body.emit(assign(r0AB0, r0AB3, 0x01));

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

   ir_variable *const r0AC1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0AC1);
   ir_variable *const r0AC2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0AC2);
   ir_variable *const r0AC3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0AC3);
   ir_variable *const r0AC4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0AC4);
   ir_variable *const r0AC5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0AC5);
   ir_variable *const r0AC6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0AC6);
   ir_variable *const r0AC7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AC7);
   ir_variable *const r0AC8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AC8);
   ir_variable *const r0AC9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AC9);
   ir_variable *const r0ACA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0ACA);
   ir_variable *const r0ACB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0ACC = less(r0AC3, r0AC6);
   ir_expression *const r0ACD = expr(ir_unop_b2i, r0ACC);
   body.emit(assign(r0ACB, expr(ir_unop_i2u, r0ACD), 0x01));

   ir_variable *const r0ACE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0ACE, sub(r0AC2, r0AC5), 0x01));

   ir_expression *const r0ACF = sub(r0AC1, r0AC4);
   ir_expression *const r0AD0 = less(r0ACE, r0ACB);
   ir_expression *const r0AD1 = expr(ir_unop_b2i, r0AD0);
   ir_expression *const r0AD2 = expr(ir_unop_i2u, r0AD1);
   body.emit(assign(r0ACA, sub(r0ACF, r0AD2), 0x01));

   ir_expression *const r0AD3 = less(r0AC2, r0AC5);
   ir_expression *const r0AD4 = expr(ir_unop_b2i, r0AD3);
   ir_expression *const r0AD5 = expr(ir_unop_i2u, r0AD4);
   body.emit(assign(r0ACA, sub(r0ACA, r0AD5), 0x01));

   body.emit(assign(r0AC9, sub(r0AC3, r0AC6), 0x01));

   body.emit(assign(r0AC8, sub(r0ACE, r0ACB), 0x01));

   body.emit(assign(r0AC7, r0ACA, 0x01));

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

   ir_variable *const r0AD6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0AD6);
   ir_variable *const r0AD7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0AD7);
   ir_variable *const r0AD8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0AD8);
   ir_variable *const r0AD9 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0ADA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0ADA);
   ir_variable *const r0ADB = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0ADB);
   ir_variable *const r0ADC = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0ADC);
   ir_variable *const r0ADD = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0ADD);
   body.emit(assign(r0ADC, body.constant(0u), 0x01));

   body.emit(assign(r0ADB, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0ADF = gequal(r0AD6, r0AD8);
   ir_if *f0ADE = new(mem_ctx) ir_if(operand(r0ADF).val);
   exec_list *const f0ADE_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0ADE->then_instructions;

      body.emit(assign(r0AD9, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0ADE->else_instructions;

      body.emit(assign(r0ADD, rshift(r0AD8, body.constant(int(16))), 0x01));

      ir_variable *const r0AE0 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0AE2 = lshift(r0ADD, body.constant(int(16)));
      ir_expression *const r0AE3 = gequal(r0AD6, r0AE2);
      ir_if *f0AE1 = new(mem_ctx) ir_if(operand(r0AE3).val);
      exec_list *const f0AE1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AE1->then_instructions;

         body.emit(assign(r0AE0, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AE1->else_instructions;

         ir_expression *const r0AE4 = expr(ir_binop_div, r0AD6, r0ADD);
         body.emit(assign(r0AE0, lshift(r0AE4, body.constant(int(16))), 0x01));


      body.instructions = f0AE1_parent_instructions;
      body.emit(f0AE1);

      /* END IF */

      body.emit(assign(r0ADA, r0AE0, 0x01));

      ir_variable *const r0AE5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0AE5);
      ir_variable *const r0AE6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0AE6);
      ir_variable *const r0AE7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0AE7);
      ir_variable *const r0AE8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AE8, bit_and(r0AD8, body.constant(65535u)), 0x01));

      ir_variable *const r0AE9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AE9, rshift(r0AD8, body.constant(int(16))), 0x01));

      ir_variable *const r0AEA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AEA, bit_and(r0AE0, body.constant(65535u)), 0x01));

      ir_variable *const r0AEB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AEB, rshift(r0AE0, body.constant(int(16))), 0x01));

      ir_variable *const r0AEC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AEC, mul(r0AE9, r0AEA), 0x01));

      ir_expression *const r0AED = mul(r0AE8, r0AEB);
      body.emit(assign(r0AE6, add(r0AED, r0AEC), 0x01));

      ir_expression *const r0AEE = mul(r0AE9, r0AEB);
      ir_expression *const r0AEF = less(r0AE6, r0AEC);
      ir_expression *const r0AF0 = expr(ir_unop_b2i, r0AEF);
      ir_expression *const r0AF1 = expr(ir_unop_i2u, r0AF0);
      ir_expression *const r0AF2 = lshift(r0AF1, body.constant(int(16)));
      ir_expression *const r0AF3 = rshift(r0AE6, body.constant(int(16)));
      ir_expression *const r0AF4 = add(r0AF2, r0AF3);
      body.emit(assign(r0AE5, add(r0AEE, r0AF4), 0x01));

      body.emit(assign(r0AE6, lshift(r0AE6, body.constant(int(16))), 0x01));

      ir_expression *const r0AF5 = mul(r0AE8, r0AEA);
      body.emit(assign(r0AE7, add(r0AF5, r0AE6), 0x01));

      ir_expression *const r0AF6 = less(r0AE7, r0AE6);
      ir_expression *const r0AF7 = expr(ir_unop_b2i, r0AF6);
      ir_expression *const r0AF8 = expr(ir_unop_i2u, r0AF7);
      body.emit(assign(r0AE5, add(r0AE5, r0AF8), 0x01));

      ir_expression *const r0AF9 = sub(r0AD6, r0AE5);
      ir_expression *const r0AFA = less(r0AD7, r0AE7);
      ir_expression *const r0AFB = expr(ir_unop_b2i, r0AFA);
      ir_expression *const r0AFC = expr(ir_unop_i2u, r0AFB);
      body.emit(assign(r0ADC, sub(r0AF9, r0AFC), 0x01));

      body.emit(assign(r0ADB, sub(r0AD7, r0AE7), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0AFD = new(mem_ctx) ir_loop();
      exec_list *const f0AFD_parent_instructions = body.instructions;

         body.instructions = &f0AFD->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0AFF = expr(ir_unop_u2i, r0ADC);
         ir_expression *const r0B00 = gequal(r0AFF, body.constant(int(0)));
         ir_if *f0AFE = new(mem_ctx) ir_if(operand(r0B00).val);
         exec_list *const f0AFE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AFE->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0AFE_parent_instructions;
         body.emit(f0AFE);

         /* END IF */

         body.emit(assign(r0ADA, add(r0ADA, body.constant(4294901760u)), 0x01));

         ir_variable *const r0B01 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0B02 = lshift(r0AD8, body.constant(int(16)));
         body.emit(assign(r0B01, add(r0ADB, r0B02), 0x01));

         ir_expression *const r0B03 = add(r0ADC, r0ADD);
         ir_expression *const r0B04 = less(r0B01, r0ADB);
         ir_expression *const r0B05 = expr(ir_unop_b2i, r0B04);
         ir_expression *const r0B06 = expr(ir_unop_i2u, r0B05);
         body.emit(assign(r0ADC, add(r0B03, r0B06), 0x01));

         body.emit(assign(r0ADB, r0B01, 0x01));

      /* LOOP END */

      body.instructions = f0AFD_parent_instructions;
      body.emit(f0AFD);

      ir_expression *const r0B07 = lshift(r0ADC, body.constant(int(16)));
      ir_expression *const r0B08 = rshift(r0ADB, body.constant(int(16)));
      body.emit(assign(r0ADC, bit_or(r0B07, r0B08), 0x01));

      ir_variable *const r0B09 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0B0B = lshift(r0ADD, body.constant(int(16)));
      ir_expression *const r0B0C = gequal(r0ADC, r0B0B);
      ir_if *f0B0A = new(mem_ctx) ir_if(operand(r0B0C).val);
      exec_list *const f0B0A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B0A->then_instructions;

         body.emit(assign(r0B09, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B0A->else_instructions;

         body.emit(assign(r0B09, expr(ir_binop_div, r0ADC, r0ADD), 0x01));


      body.instructions = f0B0A_parent_instructions;
      body.emit(f0B0A);

      /* END IF */

      body.emit(assign(r0ADA, bit_or(r0ADA, r0B09), 0x01));

      body.emit(assign(r0AD9, r0ADA, 0x01));


   body.instructions = f0ADE_parent_instructions;
   body.emit(f0ADE);

   /* END IF */

   body.emit(ret(r0AD9));

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

   ir_variable *const r0B0D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B0D);
   ir_variable *const r0B0E = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0B0E, r0B0D, 0x03));

   ir_variable *const r0B0F = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B10 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B10, bit_and(swizzle_y(r0B0D), body.constant(1048575u)), 0x01));

   ir_variable *const r0B11 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B12 = rshift(swizzle_y(r0B0D), body.constant(int(20)));
   ir_expression *const r0B13 = bit_and(r0B12, body.constant(2047u));
   body.emit(assign(r0B11, expr(ir_unop_u2i, r0B13), 0x01));

   ir_variable *const r0B14 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B14, rshift(swizzle_y(r0B0D), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B16 = equal(r0B11, body.constant(int(2047)));
   ir_if *f0B15 = new(mem_ctx) ir_if(operand(r0B16).val);
   exec_list *const f0B15_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B15->then_instructions;

      ir_variable *const r0B17 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0B17);
      ir_expression *const r0B18 = lshift(swizzle_y(r0B0D), body.constant(int(12)));
      ir_expression *const r0B19 = rshift(swizzle_x(r0B0D), body.constant(int(20)));
      body.emit(assign(r0B0E, bit_or(r0B18, r0B19), 0x02));

      body.emit(assign(r0B0E, lshift(swizzle_x(r0B0D), body.constant(int(12))), 0x01));

      ir_expression *const r0B1A = lshift(r0B14, body.constant(int(31)));
      ir_expression *const r0B1B = bit_or(r0B1A, body.constant(2143289344u));
      ir_expression *const r0B1C = rshift(swizzle_y(r0B0E), body.constant(int(9)));
      ir_expression *const r0B1D = bit_or(r0B1B, r0B1C);
      body.emit(assign(r0B17, expr(ir_unop_bitcast_u2f, r0B1D), 0x01));

      ir_variable *const r0B1E = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0B1F = bit_or(r0B10, swizzle_x(r0B0D));
      ir_expression *const r0B20 = nequal(r0B1F, body.constant(0u));
      ir_expression *const r0B21 = lshift(r0B14, body.constant(int(31)));
      ir_expression *const r0B22 = add(r0B21, body.constant(2139095040u));
      ir_expression *const r0B23 = expr(ir_unop_bitcast_u2f, r0B22);
      body.emit(assign(r0B1E, expr(ir_triop_csel, r0B20, r0B17, r0B23), 0x01));

      body.emit(assign(r0B17, r0B1E, 0x01));

      body.emit(assign(r0B0F, r0B1E, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B15->else_instructions;

      ir_variable *const r0B24 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B24);
      ir_variable *const r0B25 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0B25, rshift(r0B10, body.constant(int(22))), 0x01));

      ir_expression *const r0B26 = lshift(r0B10, body.constant(int(10)));
      ir_expression *const r0B27 = rshift(swizzle_x(r0B0D), body.constant(int(22)));
      ir_expression *const r0B28 = bit_or(r0B26, r0B27);
      ir_expression *const r0B29 = lshift(swizzle_x(r0B0D), body.constant(int(10)));
      ir_expression *const r0B2A = nequal(r0B29, body.constant(0u));
      ir_expression *const r0B2B = expr(ir_unop_b2i, r0B2A);
      ir_expression *const r0B2C = expr(ir_unop_i2u, r0B2B);
      body.emit(assign(r0B24, bit_or(r0B28, r0B2C), 0x01));

      ir_variable *const r0B2D = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0B2E = nequal(r0B11, body.constant(int(0)));
      ir_expression *const r0B2F = bit_or(r0B24, body.constant(1073741824u));
      body.emit(assign(r0B2D, expr(ir_triop_csel, r0B2E, r0B2F, r0B24), 0x01));

      ir_variable *const r0B30 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B30, add(r0B11, body.constant(int(-897))), 0x01));

      ir_variable *const r0B31 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B31, r0B2D, 0x01));

      ir_variable *const r0B32 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B32, body.constant(true), 0x01));

      ir_variable *const r0B33 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B34 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B34);
      ir_expression *const r0B35 = bit_and(r0B2D, body.constant(127u));
      body.emit(assign(r0B34, expr(ir_unop_u2i, r0B35), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B37 = expr(ir_unop_i2u, r0B30);
      ir_expression *const r0B38 = gequal(r0B37, body.constant(253u));
      ir_if *f0B36 = new(mem_ctx) ir_if(operand(r0B38).val);
      exec_list *const f0B36_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B36->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B3A = less(body.constant(int(253)), r0B30);
         ir_expression *const r0B3B = equal(r0B30, body.constant(int(253)));
         ir_expression *const r0B3C = expr(ir_unop_u2i, r0B2D);
         ir_expression *const r0B3D = less(r0B3C, body.constant(int(-64)));
         ir_expression *const r0B3E = logic_and(r0B3B, r0B3D);
         ir_expression *const r0B3F = logic_or(r0B3A, r0B3E);
         ir_if *f0B39 = new(mem_ctx) ir_if(operand(r0B3F).val);
         exec_list *const f0B39_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B39->then_instructions;

            ir_expression *const r0B40 = lshift(r0B14, body.constant(int(31)));
            ir_expression *const r0B41 = add(r0B40, body.constant(2139095040u));
            body.emit(assign(r0B33, expr(ir_unop_bitcast_u2f, r0B41), 0x01));

            body.emit(assign(r0B32, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B39->else_instructions;

            ir_variable *const r0B42 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B42, neg(r0B30), 0x01));

            ir_variable *const r0B43 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0B43, less(r0B30, body.constant(int(0))), 0x01));

            ir_variable *const r0B44 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0B45 = neg(r0B30);
            ir_expression *const r0B46 = less(r0B45, body.constant(int(32)));
            ir_expression *const r0B47 = rshift(r0B2D, r0B42);
            ir_expression *const r0B48 = neg(r0B42);
            ir_expression *const r0B49 = bit_and(r0B48, body.constant(int(31)));
            ir_expression *const r0B4A = lshift(r0B2D, r0B49);
            ir_expression *const r0B4B = nequal(r0B4A, body.constant(0u));
            ir_expression *const r0B4C = expr(ir_unop_b2i, r0B4B);
            ir_expression *const r0B4D = expr(ir_unop_i2u, r0B4C);
            ir_expression *const r0B4E = bit_or(r0B47, r0B4D);
            ir_expression *const r0B4F = nequal(r0B2D, body.constant(0u));
            ir_expression *const r0B50 = expr(ir_unop_b2i, r0B4F);
            ir_expression *const r0B51 = expr(ir_unop_i2u, r0B50);
            ir_expression *const r0B52 = expr(ir_triop_csel, r0B46, r0B4E, r0B51);
            body.emit(assign(r0B44, expr(ir_triop_csel, r0B43, r0B52, r0B2D), 0x01));

            body.emit(assign(r0B31, r0B44, 0x01));

            ir_expression *const r0B53 = expr(ir_unop_u2i, r0B44);
            ir_expression *const r0B54 = bit_and(r0B53, body.constant(int(127)));
            body.emit(assign(r0B34, expr(ir_triop_csel, r0B43, r0B54, r0B34), 0x01));

            body.emit(assign(r0B30, expr(ir_triop_csel, r0B43, body.constant(int(0)), r0B30), 0x01));


         body.instructions = f0B39_parent_instructions;
         body.emit(f0B39);

         /* END IF */


      body.instructions = f0B36_parent_instructions;
      body.emit(f0B36);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B55 = new(mem_ctx) ir_if(operand(r0B32).val);
      exec_list *const f0B55_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B55->then_instructions;

         ir_expression *const r0B56 = add(r0B31, body.constant(64u));
         body.emit(assign(r0B31, rshift(r0B56, body.constant(int(7))), 0x01));

         ir_expression *const r0B57 = bit_xor(r0B34, body.constant(int(64)));
         ir_expression *const r0B58 = equal(r0B57, body.constant(int(0)));
         ir_expression *const r0B59 = expr(ir_unop_b2i, r0B58);
         ir_expression *const r0B5A = expr(ir_unop_i2u, r0B59);
         ir_expression *const r0B5B = expr(ir_unop_bit_not, r0B5A);
         body.emit(assign(r0B31, bit_and(r0B31, r0B5B), 0x01));

         ir_expression *const r0B5C = lshift(r0B14, body.constant(int(31)));
         ir_expression *const r0B5D = equal(r0B31, body.constant(0u));
         ir_expression *const r0B5E = expr(ir_triop_csel, r0B5D, body.constant(int(0)), r0B30);
         ir_expression *const r0B5F = expr(ir_unop_i2u, r0B5E);
         ir_expression *const r0B60 = lshift(r0B5F, body.constant(int(23)));
         ir_expression *const r0B61 = add(r0B5C, r0B60);
         ir_expression *const r0B62 = add(r0B61, r0B31);
         body.emit(assign(r0B33, expr(ir_unop_bitcast_u2f, r0B62), 0x01));

         body.emit(assign(r0B32, body.constant(false), 0x01));


      body.instructions = f0B55_parent_instructions;
      body.emit(f0B55);

      /* END IF */

      body.emit(assign(r0B0F, r0B33, 0x01));


   body.instructions = f0B15_parent_instructions;
   body.emit(f0B15);

   /* END IF */

   ir_variable *const r0B63 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B63, body.constant(true), 0x01));

   ir_variable *const r0B64 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B65 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B65);
   ir_variable *const r0B66 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B66);
   ir_variable *const r0B67 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B67);
   ir_variable *const r0B68 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0B69 = expr(ir_unop_sqrt, r0B0F);
   body.emit(assign(r0B68, expr(ir_unop_bitcast_f2u, r0B69), 0x01));

   ir_variable *const r0B6A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B6A, bit_and(r0B68, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B67, r0B6A, 0x01));

   ir_variable *const r0B6B = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B6C = rshift(r0B68, body.constant(int(23)));
   ir_expression *const r0B6D = bit_and(r0B6C, body.constant(255u));
   body.emit(assign(r0B6B, expr(ir_unop_u2i, r0B6D), 0x01));

   body.emit(assign(r0B66, r0B6B, 0x01));

   body.emit(assign(r0B65, rshift(r0B68, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B6F = equal(r0B6B, body.constant(int(255)));
   ir_if *f0B6E = new(mem_ctx) ir_if(operand(r0B6F).val);
   exec_list *const f0B6E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B6E->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B71 = nequal(r0B6A, body.constant(0u));
      ir_if *f0B70 = new(mem_ctx) ir_if(operand(r0B71).val);
      exec_list *const f0B70_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B70->then_instructions;

         ir_variable *const r0B72 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B72, lshift(r0B68, body.constant(int(9))), 0x01));

         ir_variable *const r0B73 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B74 = lshift(r0B72, body.constant(int(20)));
         body.emit(assign(r0B73, bit_or(r0B74, body.constant(0u)), 0x01));

         ir_expression *const r0B75 = rshift(r0B72, body.constant(int(12)));
         ir_expression *const r0B76 = lshift(r0B65, body.constant(int(31)));
         ir_expression *const r0B77 = bit_or(r0B76, body.constant(2146959360u));
         body.emit(assign(r0B73, bit_or(r0B75, r0B77), 0x02));

         body.emit(assign(r0B64, r0B73, 0x03));

         body.emit(assign(r0B63, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B70->else_instructions;

         ir_variable *const r0B78 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B78);
         ir_expression *const r0B79 = lshift(r0B65, body.constant(int(31)));
         body.emit(assign(r0B78, add(r0B79, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B78, body.constant(0u), 0x01));

         body.emit(assign(r0B64, r0B78, 0x03));

         body.emit(assign(r0B63, body.constant(false), 0x01));


      body.instructions = f0B70_parent_instructions;
      body.emit(f0B70);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B6E->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B7B = equal(r0B6B, body.constant(int(0)));
      ir_if *f0B7A = new(mem_ctx) ir_if(operand(r0B7B).val);
      exec_list *const f0B7A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B7A->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B7D = equal(r0B6A, body.constant(0u));
         ir_if *f0B7C = new(mem_ctx) ir_if(operand(r0B7D).val);
         exec_list *const f0B7C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B7C->then_instructions;

            ir_variable *const r0B7E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B7E);
            body.emit(assign(r0B7E, lshift(r0B65, body.constant(int(31))), 0x02));

            body.emit(assign(r0B7E, body.constant(0u), 0x01));

            body.emit(assign(r0B64, r0B7E, 0x03));

            body.emit(assign(r0B63, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B7C->else_instructions;

            ir_variable *const r0B7F = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0B80 = equal(r0B6A, body.constant(0u));
            ir_expression *const r0B81 = expr(ir_unop_find_msb, r0B6A);
            ir_expression *const r0B82 = sub(body.constant(int(31)), r0B81);
            ir_expression *const r0B83 = expr(ir_triop_csel, r0B80, body.constant(int(32)), r0B82);
            body.emit(assign(r0B7F, add(r0B83, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B67, lshift(r0B6A, r0B7F), 0x01));

            body.emit(assign(r0B66, sub(body.constant(int(1)), r0B7F), 0x01));

            body.emit(assign(r0B66, add(r0B66, body.constant(int(-1))), 0x01));


         body.instructions = f0B7C_parent_instructions;
         body.emit(f0B7C);

         /* END IF */


      body.instructions = f0B7A_parent_instructions;
      body.emit(f0B7A);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B84 = new(mem_ctx) ir_if(operand(r0B63).val);
      exec_list *const f0B84_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B84->then_instructions;

         ir_variable *const r0B85 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B85);
         ir_expression *const r0B86 = lshift(r0B65, body.constant(int(31)));
         ir_expression *const r0B87 = add(r0B66, body.constant(int(896)));
         ir_expression *const r0B88 = expr(ir_unop_i2u, r0B87);
         ir_expression *const r0B89 = lshift(r0B88, body.constant(int(20)));
         ir_expression *const r0B8A = add(r0B86, r0B89);
         ir_expression *const r0B8B = rshift(r0B67, body.constant(int(3)));
         body.emit(assign(r0B85, add(r0B8A, r0B8B), 0x02));

         ir_expression *const r0B8C = lshift(r0B67, body.constant(int(29)));
         body.emit(assign(r0B85, bit_or(r0B8C, body.constant(0u)), 0x01));

         body.emit(assign(r0B64, r0B85, 0x03));

         body.emit(assign(r0B63, body.constant(false), 0x01));


      body.instructions = f0B84_parent_instructions;
      body.emit(f0B84);

      /* END IF */


   body.instructions = f0B6E_parent_instructions;
   body.emit(f0B6E);

   /* END IF */

   body.emit(ret(r0B64));

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

   ir_variable *const r0B8D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B8D);
   ir_variable *const r0B8E = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B8F = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B90 = rshift(swizzle_y(r0B8D), body.constant(int(20)));
   ir_expression *const r0B91 = bit_and(r0B90, body.constant(2047u));
   ir_expression *const r0B92 = expr(ir_unop_u2i, r0B91);
   body.emit(assign(r0B8F, add(r0B92, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B94 = less(r0B8F, body.constant(int(0)));
   ir_if *f0B93 = new(mem_ctx) ir_if(operand(r0B94).val);
   exec_list *const f0B93_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B93->then_instructions;

      body.emit(assign(r0B8E, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B93->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B96 = less(body.constant(int(52)), r0B8F);
      ir_if *f0B95 = new(mem_ctx) ir_if(operand(r0B96).val);
      exec_list *const f0B95_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B95->then_instructions;

         body.emit(assign(r0B8E, r0B8D, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B95->else_instructions;

         ir_variable *const r0B97 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0B97, sub(body.constant(int(52)), r0B8F), 0x01));

         ir_variable *const r0B98 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0B9A = gequal(r0B97, body.constant(int(32)));
         ir_if *f0B99 = new(mem_ctx) ir_if(operand(r0B9A).val);
         exec_list *const f0B99_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B99->then_instructions;

            body.emit(assign(r0B98, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B99->else_instructions;

            body.emit(assign(r0B98, lshift(body.constant(4294967295u), r0B97), 0x01));


         body.instructions = f0B99_parent_instructions;
         body.emit(f0B99);

         /* END IF */

         ir_variable *const r0B9B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0B9D = less(r0B97, body.constant(int(33)));
         ir_if *f0B9C = new(mem_ctx) ir_if(operand(r0B9D).val);
         exec_list *const f0B9C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B9C->then_instructions;

            body.emit(assign(r0B9B, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B9C->else_instructions;

            ir_expression *const r0B9E = add(r0B97, body.constant(int(-32)));
            body.emit(assign(r0B9B, lshift(body.constant(4294967295u), r0B9E), 0x01));


         body.instructions = f0B9C_parent_instructions;
         body.emit(f0B9C);

         /* END IF */

         ir_variable *const r0B9F = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0B9F, bit_and(r0B98, swizzle_x(r0B8D)), 0x01));

         body.emit(assign(r0B9F, bit_and(r0B9B, swizzle_y(r0B8D)), 0x02));

         body.emit(assign(r0B8E, r0B9F, 0x03));


      body.instructions = f0B95_parent_instructions;
      body.emit(f0B95);

      /* END IF */


   body.instructions = f0B93_parent_instructions;
   body.emit(f0B93);

   /* END IF */

   body.emit(ret(r0B8E));

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

   ir_variable *const r0BA0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BA0);
   ir_variable *const r0BA1 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0BA1, body.constant(true), 0x01));

   ir_variable *const r0BA2 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0BA3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0BA3);
   ir_variable *const r0BA4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0BA4);
   ir_variable *const r0BA5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0BA6 = rshift(swizzle_y(r0BA0), body.constant(int(20)));
   ir_expression *const r0BA7 = bit_and(r0BA6, body.constant(2047u));
   ir_expression *const r0BA8 = expr(ir_unop_u2i, r0BA7);
   body.emit(assign(r0BA5, add(r0BA8, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0BA4, swizzle_y(r0BA0), 0x01));

   body.emit(assign(r0BA3, swizzle_x(r0BA0), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BAA = less(r0BA5, body.constant(int(20)));
   ir_if *f0BA9 = new(mem_ctx) ir_if(operand(r0BAA).val);
   exec_list *const f0BA9_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BA9->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0BAC = less(r0BA5, body.constant(int(0)));
      ir_if *f0BAB = new(mem_ctx) ir_if(operand(r0BAC).val);
      exec_list *const f0BAB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BAB->then_instructions;

         body.emit(assign(r0BA4, bit_and(swizzle_y(r0BA0), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BAE = equal(r0BA5, body.constant(int(-1)));
         ir_expression *const r0BAF = nequal(swizzle_x(r0BA0), body.constant(0u));
         ir_expression *const r0BB0 = logic_and(r0BAE, r0BAF);
         ir_if *f0BAD = new(mem_ctx) ir_if(operand(r0BB0).val);
         exec_list *const f0BAD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BAD->then_instructions;

            body.emit(assign(r0BA4, bit_or(r0BA4, body.constant(1072693248u)), 0x01));


         body.instructions = f0BAD_parent_instructions;
         body.emit(f0BAD);

         /* END IF */

         body.emit(assign(r0BA3, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BAB->else_instructions;

         ir_variable *const r0BB1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0BB1, rshift(body.constant(1048575u), r0BA5), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BB3 = bit_and(r0BA4, r0BB1);
         ir_expression *const r0BB4 = equal(r0BB3, body.constant(0u));
         ir_expression *const r0BB5 = equal(r0BA3, body.constant(0u));
         ir_expression *const r0BB6 = logic_and(r0BB4, r0BB5);
         ir_if *f0BB2 = new(mem_ctx) ir_if(operand(r0BB6).val);
         exec_list *const f0BB2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BB2->then_instructions;

            body.emit(assign(r0BA2, r0BA0, 0x03));

            body.emit(assign(r0BA1, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BB2->else_instructions;

            ir_expression *const r0BB7 = rshift(body.constant(524288u), r0BA5);
            body.emit(assign(r0BA4, add(r0BA4, r0BB7), 0x01));

            ir_expression *const r0BB8 = expr(ir_unop_bit_not, r0BB1);
            body.emit(assign(r0BA4, bit_and(r0BA4, r0BB8), 0x01));

            body.emit(assign(r0BA3, body.constant(0u), 0x01));


         body.instructions = f0BB2_parent_instructions;
         body.emit(f0BB2);

         /* END IF */


      body.instructions = f0BAB_parent_instructions;
      body.emit(f0BAB);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BA9->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0BBA = less(body.constant(int(51)), r0BA5);
      ir_expression *const r0BBB = equal(r0BA5, body.constant(int(1024)));
      ir_expression *const r0BBC = logic_or(r0BBA, r0BBB);
      ir_if *f0BB9 = new(mem_ctx) ir_if(operand(r0BBC).val);
      exec_list *const f0BB9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BB9->then_instructions;

         body.emit(assign(r0BA2, r0BA0, 0x03));

         body.emit(assign(r0BA1, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BB9->else_instructions;

         ir_variable *const r0BBD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0BBE = add(r0BA5, body.constant(int(-20)));
         body.emit(assign(r0BBD, rshift(body.constant(4294967295u), r0BBE), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BC0 = bit_and(r0BA3, r0BBD);
         ir_expression *const r0BC1 = equal(r0BC0, body.constant(0u));
         ir_if *f0BBF = new(mem_ctx) ir_if(operand(r0BC1).val);
         exec_list *const f0BBF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BBF->then_instructions;

            body.emit(assign(r0BA2, r0BA0, 0x03));

            body.emit(assign(r0BA1, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BBF->else_instructions;

            ir_variable *const r0BC2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0BC3 = sub(body.constant(int(51)), r0BA5);
            ir_expression *const r0BC4 = lshift(body.constant(1u), r0BC3);
            body.emit(assign(r0BC2, add(r0BA3, r0BC4), 0x01));

            /* IF CONDITION */
            ir_expression *const r0BC6 = less(r0BC2, r0BA3);
            ir_if *f0BC5 = new(mem_ctx) ir_if(operand(r0BC6).val);
            exec_list *const f0BC5_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0BC5->then_instructions;

               body.emit(assign(r0BA4, add(r0BA4, body.constant(1u)), 0x01));


            body.instructions = f0BC5_parent_instructions;
            body.emit(f0BC5);

            /* END IF */

            ir_expression *const r0BC7 = expr(ir_unop_bit_not, r0BBD);
            body.emit(assign(r0BA3, bit_and(r0BC2, r0BC7), 0x01));


         body.instructions = f0BBF_parent_instructions;
         body.emit(f0BBF);

         /* END IF */


      body.instructions = f0BB9_parent_instructions;
      body.emit(f0BB9);

      /* END IF */


   body.instructions = f0BA9_parent_instructions;
   body.emit(f0BA9);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0BC8 = new(mem_ctx) ir_if(operand(r0BA1).val);
   exec_list *const f0BC8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BC8->then_instructions;

      body.emit(assign(r0BA0, r0BA3, 0x01));

      body.emit(assign(r0BA0, r0BA4, 0x02));

      body.emit(assign(r0BA2, r0BA0, 0x03));

      body.emit(assign(r0BA1, body.constant(false), 0x01));


   body.instructions = f0BC8_parent_instructions;
   body.emit(f0BC8);

   /* END IF */

   body.emit(ret(r0BA2));

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

   ir_variable *const r0BC9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BC9);
   ir_variable *const r0BCA = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0BCA, r0BC9, 0x03));

   ir_variable *const r0BCB = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0BCC = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0BCC, bit_and(swizzle_y(r0BC9), body.constant(1048575u)), 0x01));

   ir_variable *const r0BCD = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0BCE = rshift(swizzle_y(r0BC9), body.constant(int(20)));
   ir_expression *const r0BCF = bit_and(r0BCE, body.constant(2047u));
   body.emit(assign(r0BCD, expr(ir_unop_u2i, r0BCF), 0x01));

   ir_variable *const r0BD0 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0BD0, rshift(swizzle_y(r0BC9), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BD2 = equal(r0BCD, body.constant(int(2047)));
   ir_if *f0BD1 = new(mem_ctx) ir_if(operand(r0BD2).val);
   exec_list *const f0BD1_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BD1->then_instructions;

      ir_variable *const r0BD3 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0BD3);
      ir_expression *const r0BD4 = lshift(swizzle_y(r0BC9), body.constant(int(12)));
      ir_expression *const r0BD5 = rshift(swizzle_x(r0BC9), body.constant(int(20)));
      body.emit(assign(r0BCA, bit_or(r0BD4, r0BD5), 0x02));

      body.emit(assign(r0BCA, lshift(swizzle_x(r0BC9), body.constant(int(12))), 0x01));

      ir_expression *const r0BD6 = lshift(r0BD0, body.constant(int(31)));
      ir_expression *const r0BD7 = bit_or(r0BD6, body.constant(2143289344u));
      ir_expression *const r0BD8 = rshift(swizzle_y(r0BCA), body.constant(int(9)));
      ir_expression *const r0BD9 = bit_or(r0BD7, r0BD8);
      body.emit(assign(r0BD3, expr(ir_unop_bitcast_u2f, r0BD9), 0x01));

      ir_variable *const r0BDA = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0BDB = bit_or(r0BCC, swizzle_x(r0BC9));
      ir_expression *const r0BDC = nequal(r0BDB, body.constant(0u));
      ir_expression *const r0BDD = lshift(r0BD0, body.constant(int(31)));
      ir_expression *const r0BDE = add(r0BDD, body.constant(2139095040u));
      ir_expression *const r0BDF = expr(ir_unop_bitcast_u2f, r0BDE);
      body.emit(assign(r0BDA, expr(ir_triop_csel, r0BDC, r0BD3, r0BDF), 0x01));

      body.emit(assign(r0BD3, r0BDA, 0x01));

      body.emit(assign(r0BCB, r0BDA, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BD1->else_instructions;

      ir_variable *const r0BE0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BE0);
      ir_variable *const r0BE1 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0BE1, rshift(r0BCC, body.constant(int(22))), 0x01));

      ir_expression *const r0BE2 = lshift(r0BCC, body.constant(int(10)));
      ir_expression *const r0BE3 = rshift(swizzle_x(r0BC9), body.constant(int(22)));
      ir_expression *const r0BE4 = bit_or(r0BE2, r0BE3);
      ir_expression *const r0BE5 = lshift(swizzle_x(r0BC9), body.constant(int(10)));
      ir_expression *const r0BE6 = nequal(r0BE5, body.constant(0u));
      ir_expression *const r0BE7 = expr(ir_unop_b2i, r0BE6);
      ir_expression *const r0BE8 = expr(ir_unop_i2u, r0BE7);
      body.emit(assign(r0BE0, bit_or(r0BE4, r0BE8), 0x01));

      ir_variable *const r0BE9 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0BEA = nequal(r0BCD, body.constant(int(0)));
      ir_expression *const r0BEB = bit_or(r0BE0, body.constant(1073741824u));
      body.emit(assign(r0BE9, expr(ir_triop_csel, r0BEA, r0BEB, r0BE0), 0x01));

      ir_variable *const r0BEC = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0BEC, add(r0BCD, body.constant(int(-897))), 0x01));

      ir_variable *const r0BED = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0BED, r0BE9, 0x01));

      ir_variable *const r0BEE = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0BEE, body.constant(true), 0x01));

      ir_variable *const r0BEF = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0BF0 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0BF0);
      ir_expression *const r0BF1 = bit_and(r0BE9, body.constant(127u));
      body.emit(assign(r0BF0, expr(ir_unop_u2i, r0BF1), 0x01));

      /* IF CONDITION */
      ir_expression *const r0BF3 = expr(ir_unop_i2u, r0BEC);
      ir_expression *const r0BF4 = gequal(r0BF3, body.constant(253u));
      ir_if *f0BF2 = new(mem_ctx) ir_if(operand(r0BF4).val);
      exec_list *const f0BF2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BF2->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0BF6 = less(body.constant(int(253)), r0BEC);
         ir_expression *const r0BF7 = equal(r0BEC, body.constant(int(253)));
         ir_expression *const r0BF8 = expr(ir_unop_u2i, r0BE9);
         ir_expression *const r0BF9 = less(r0BF8, body.constant(int(-64)));
         ir_expression *const r0BFA = logic_and(r0BF7, r0BF9);
         ir_expression *const r0BFB = logic_or(r0BF6, r0BFA);
         ir_if *f0BF5 = new(mem_ctx) ir_if(operand(r0BFB).val);
         exec_list *const f0BF5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BF5->then_instructions;

            ir_expression *const r0BFC = lshift(r0BD0, body.constant(int(31)));
            ir_expression *const r0BFD = add(r0BFC, body.constant(2139095040u));
            body.emit(assign(r0BEF, expr(ir_unop_bitcast_u2f, r0BFD), 0x01));

            body.emit(assign(r0BEE, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BF5->else_instructions;

            ir_variable *const r0BFE = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0BFE, neg(r0BEC), 0x01));

            ir_variable *const r0BFF = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0BFF, less(r0BEC, body.constant(int(0))), 0x01));

            ir_variable *const r0C00 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0C01 = neg(r0BEC);
            ir_expression *const r0C02 = less(r0C01, body.constant(int(32)));
            ir_expression *const r0C03 = rshift(r0BE9, r0BFE);
            ir_expression *const r0C04 = neg(r0BFE);
            ir_expression *const r0C05 = bit_and(r0C04, body.constant(int(31)));
            ir_expression *const r0C06 = lshift(r0BE9, r0C05);
            ir_expression *const r0C07 = nequal(r0C06, body.constant(0u));
            ir_expression *const r0C08 = expr(ir_unop_b2i, r0C07);
            ir_expression *const r0C09 = expr(ir_unop_i2u, r0C08);
            ir_expression *const r0C0A = bit_or(r0C03, r0C09);
            ir_expression *const r0C0B = nequal(r0BE9, body.constant(0u));
            ir_expression *const r0C0C = expr(ir_unop_b2i, r0C0B);
            ir_expression *const r0C0D = expr(ir_unop_i2u, r0C0C);
            ir_expression *const r0C0E = expr(ir_triop_csel, r0C02, r0C0A, r0C0D);
            body.emit(assign(r0C00, expr(ir_triop_csel, r0BFF, r0C0E, r0BE9), 0x01));

            body.emit(assign(r0BED, r0C00, 0x01));

            ir_expression *const r0C0F = expr(ir_unop_u2i, r0C00);
            ir_expression *const r0C10 = bit_and(r0C0F, body.constant(int(127)));
            body.emit(assign(r0BF0, expr(ir_triop_csel, r0BFF, r0C10, r0BF0), 0x01));

            body.emit(assign(r0BEC, expr(ir_triop_csel, r0BFF, body.constant(int(0)), r0BEC), 0x01));


         body.instructions = f0BF5_parent_instructions;
         body.emit(f0BF5);

         /* END IF */


      body.instructions = f0BF2_parent_instructions;
      body.emit(f0BF2);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C11 = new(mem_ctx) ir_if(operand(r0BEE).val);
      exec_list *const f0C11_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C11->then_instructions;

         ir_expression *const r0C12 = add(r0BED, body.constant(64u));
         body.emit(assign(r0BED, rshift(r0C12, body.constant(int(7))), 0x01));

         ir_expression *const r0C13 = bit_xor(r0BF0, body.constant(int(64)));
         ir_expression *const r0C14 = equal(r0C13, body.constant(int(0)));
         ir_expression *const r0C15 = expr(ir_unop_b2i, r0C14);
         ir_expression *const r0C16 = expr(ir_unop_i2u, r0C15);
         ir_expression *const r0C17 = expr(ir_unop_bit_not, r0C16);
         body.emit(assign(r0BED, bit_and(r0BED, r0C17), 0x01));

         ir_expression *const r0C18 = lshift(r0BD0, body.constant(int(31)));
         ir_expression *const r0C19 = equal(r0BED, body.constant(0u));
         ir_expression *const r0C1A = expr(ir_triop_csel, r0C19, body.constant(int(0)), r0BEC);
         ir_expression *const r0C1B = expr(ir_unop_i2u, r0C1A);
         ir_expression *const r0C1C = lshift(r0C1B, body.constant(int(23)));
         ir_expression *const r0C1D = add(r0C18, r0C1C);
         ir_expression *const r0C1E = add(r0C1D, r0BED);
         body.emit(assign(r0BEF, expr(ir_unop_bitcast_u2f, r0C1E), 0x01));

         body.emit(assign(r0BEE, body.constant(false), 0x01));


      body.instructions = f0C11_parent_instructions;
      body.emit(f0C11);

      /* END IF */

      body.emit(assign(r0BCB, r0BEF, 0x01));


   body.instructions = f0BD1_parent_instructions;
   body.emit(f0BD1);

   /* END IF */

   ir_variable *const r0C1F = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C1F, body.constant(true), 0x01));

   ir_variable *const r0C20 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C21 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C21);
   ir_variable *const r0C22 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C22);
   ir_variable *const r0C23 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C23);
   ir_variable *const r0C24 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C25 = expr(ir_unop_rcp, r0BCB);
   body.emit(assign(r0C24, expr(ir_unop_bitcast_f2u, r0C25), 0x01));

   ir_variable *const r0C26 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C26, bit_and(r0C24, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C23, r0C26, 0x01));

   ir_variable *const r0C27 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C28 = rshift(r0C24, body.constant(int(23)));
   ir_expression *const r0C29 = bit_and(r0C28, body.constant(255u));
   body.emit(assign(r0C27, expr(ir_unop_u2i, r0C29), 0x01));

   body.emit(assign(r0C22, r0C27, 0x01));

   body.emit(assign(r0C21, rshift(r0C24, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C2B = equal(r0C27, body.constant(int(255)));
   ir_if *f0C2A = new(mem_ctx) ir_if(operand(r0C2B).val);
   exec_list *const f0C2A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C2A->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C2D = nequal(r0C26, body.constant(0u));
      ir_if *f0C2C = new(mem_ctx) ir_if(operand(r0C2D).val);
      exec_list *const f0C2C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C2C->then_instructions;

         ir_variable *const r0C2E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C2E, lshift(r0C24, body.constant(int(9))), 0x01));

         ir_variable *const r0C2F = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C30 = lshift(r0C2E, body.constant(int(20)));
         body.emit(assign(r0C2F, bit_or(r0C30, body.constant(0u)), 0x01));

         ir_expression *const r0C31 = rshift(r0C2E, body.constant(int(12)));
         ir_expression *const r0C32 = lshift(r0C21, body.constant(int(31)));
         ir_expression *const r0C33 = bit_or(r0C32, body.constant(2146959360u));
         body.emit(assign(r0C2F, bit_or(r0C31, r0C33), 0x02));

         body.emit(assign(r0C20, r0C2F, 0x03));

         body.emit(assign(r0C1F, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C2C->else_instructions;

         ir_variable *const r0C34 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C34);
         ir_expression *const r0C35 = lshift(r0C21, body.constant(int(31)));
         body.emit(assign(r0C34, add(r0C35, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C34, body.constant(0u), 0x01));

         body.emit(assign(r0C20, r0C34, 0x03));

         body.emit(assign(r0C1F, body.constant(false), 0x01));


      body.instructions = f0C2C_parent_instructions;
      body.emit(f0C2C);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C2A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C37 = equal(r0C27, body.constant(int(0)));
      ir_if *f0C36 = new(mem_ctx) ir_if(operand(r0C37).val);
      exec_list *const f0C36_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C36->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C39 = equal(r0C26, body.constant(0u));
         ir_if *f0C38 = new(mem_ctx) ir_if(operand(r0C39).val);
         exec_list *const f0C38_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C38->then_instructions;

            ir_variable *const r0C3A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C3A);
            body.emit(assign(r0C3A, lshift(r0C21, body.constant(int(31))), 0x02));

            body.emit(assign(r0C3A, body.constant(0u), 0x01));

            body.emit(assign(r0C20, r0C3A, 0x03));

            body.emit(assign(r0C1F, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C38->else_instructions;

            ir_variable *const r0C3B = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0C3C = equal(r0C26, body.constant(0u));
            ir_expression *const r0C3D = expr(ir_unop_find_msb, r0C26);
            ir_expression *const r0C3E = sub(body.constant(int(31)), r0C3D);
            ir_expression *const r0C3F = expr(ir_triop_csel, r0C3C, body.constant(int(32)), r0C3E);
            body.emit(assign(r0C3B, add(r0C3F, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C23, lshift(r0C26, r0C3B), 0x01));

            body.emit(assign(r0C22, sub(body.constant(int(1)), r0C3B), 0x01));

            body.emit(assign(r0C22, add(r0C22, body.constant(int(-1))), 0x01));


         body.instructions = f0C38_parent_instructions;
         body.emit(f0C38);

         /* END IF */


      body.instructions = f0C36_parent_instructions;
      body.emit(f0C36);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C40 = new(mem_ctx) ir_if(operand(r0C1F).val);
      exec_list *const f0C40_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C40->then_instructions;

         ir_variable *const r0C41 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C41);
         ir_expression *const r0C42 = lshift(r0C21, body.constant(int(31)));
         ir_expression *const r0C43 = add(r0C22, body.constant(int(896)));
         ir_expression *const r0C44 = expr(ir_unop_i2u, r0C43);
         ir_expression *const r0C45 = lshift(r0C44, body.constant(int(20)));
         ir_expression *const r0C46 = add(r0C42, r0C45);
         ir_expression *const r0C47 = rshift(r0C23, body.constant(int(3)));
         body.emit(assign(r0C41, add(r0C46, r0C47), 0x02));

         ir_expression *const r0C48 = lshift(r0C23, body.constant(int(29)));
         body.emit(assign(r0C41, bit_or(r0C48, body.constant(0u)), 0x01));

         body.emit(assign(r0C20, r0C41, 0x03));

         body.emit(assign(r0C1F, body.constant(false), 0x01));


      body.instructions = f0C40_parent_instructions;
      body.emit(f0C40);

      /* END IF */


   body.instructions = f0C2A_parent_instructions;
   body.emit(f0C2A);

   /* END IF */

   body.emit(ret(r0C20));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
