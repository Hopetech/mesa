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

            ir_variable *const r01EB = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r01EB, swizzle_x(r01CB), 0x01));

            ir_variable *const r01EC = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r01EC, swizzle_x(r01CC), 0x01));

            body.emit(assign(r01EB, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

            body.emit(assign(r01EC, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

            ir_expression *const r01ED = bit_or(r01DD, swizzle_x(r01CB));
            ir_expression *const r01EE = nequal(r01ED, body.constant(0u));
            ir_swizzle *const r01EF = swizzle(r01EE, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
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
            ir_expression *const r0200 = expr(ir_triop_csel, r01FF, r01EC, r01EB);
            ir_expression *const r0201 = expr(ir_triop_csel, r01F7, r0200, r01EC);
            body.emit(assign(r01CE, expr(ir_triop_csel, r01EF, r0201, r01CB), 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f01E9->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0203 = equal(r01E3, body.constant(int(0)));
            ir_if *f0202 = new(mem_ctx) ir_if(operand(r0203).val);
            exec_list *const f0202_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0202->then_instructions;

               body.emit(assign(r01D4, add(r01E6, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0202->else_instructions;

               body.emit(assign(r01D5, bit_or(r01DF, body.constant(1048576u)), 0x01));


            body.instructions = f0202_parent_instructions;
            body.emit(f0202);

            /* END IF */

            ir_variable *const r0204 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0204, body.constant(0u), 0x01));

            ir_variable *const r0205 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0205);
            ir_variable *const r0206 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0206);
            ir_variable *const r0207 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0207);
            ir_variable *const r0208 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0209 = neg(r01D4);
            body.emit(assign(r0208, bit_and(r0209, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r020B = equal(r01D4, body.constant(int(0)));
            ir_if *f020A = new(mem_ctx) ir_if(operand(r020B).val);
            exec_list *const f020A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f020A->then_instructions;

               body.emit(assign(r0205, r0204, 0x01));

               body.emit(assign(r0206, r01DE, 0x01));

               body.emit(assign(r0207, r01D5, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f020A->else_instructions;

               /* IF CONDITION */
               ir_expression *const r020D = less(r01D4, body.constant(int(32)));
               ir_if *f020C = new(mem_ctx) ir_if(operand(r020D).val);
               exec_list *const f020C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f020C->then_instructions;

                  body.emit(assign(r0205, lshift(swizzle_x(r01CC), r0208), 0x01));

                  ir_expression *const r020E = lshift(r01D5, r0208);
                  ir_expression *const r020F = rshift(swizzle_x(r01CC), r01D4);
                  body.emit(assign(r0206, bit_or(r020E, r020F), 0x01));

                  body.emit(assign(r0207, rshift(r01D5, r01D4), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f020C->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0211 = equal(r01D4, body.constant(int(32)));
                  ir_if *f0210 = new(mem_ctx) ir_if(operand(r0211).val);
                  exec_list *const f0210_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0210->then_instructions;

                     body.emit(assign(r0205, r01DE, 0x01));

                     body.emit(assign(r0206, r01D5, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0210->else_instructions;

                     body.emit(assign(r0204, bit_or(body.constant(0u), swizzle_x(r01CC)), 0x01));

                     ir_expression *const r0212 = less(r01D4, body.constant(int(64)));
                     ir_expression *const r0213 = lshift(r01D5, r0208);
                     ir_expression *const r0214 = equal(r01D4, body.constant(int(64)));
                     ir_expression *const r0215 = nequal(r01D5, body.constant(0u));
                     ir_expression *const r0216 = expr(ir_unop_b2i, r0215);
                     ir_expression *const r0217 = expr(ir_unop_i2u, r0216);
                     ir_expression *const r0218 = expr(ir_triop_csel, r0214, r01D5, r0217);
                     body.emit(assign(r0205, expr(ir_triop_csel, r0212, r0213, r0218), 0x01));

                     ir_expression *const r0219 = less(r01D4, body.constant(int(64)));
                     ir_expression *const r021A = bit_and(r01D4, body.constant(int(31)));
                     ir_expression *const r021B = rshift(r01D5, r021A);
                     body.emit(assign(r0206, expr(ir_triop_csel, r0219, r021B, body.constant(0u)), 0x01));


                  body.instructions = f0210_parent_instructions;
                  body.emit(f0210);

                  /* END IF */

                  body.emit(assign(r0207, body.constant(0u), 0x01));


               body.instructions = f020C_parent_instructions;
               body.emit(f020C);

               /* END IF */

               ir_expression *const r021C = nequal(r0204, body.constant(0u));
               ir_expression *const r021D = expr(ir_unop_b2i, r021C);
               ir_expression *const r021E = expr(ir_unop_i2u, r021D);
               body.emit(assign(r0205, bit_or(r0205, r021E), 0x01));


            body.instructions = f020A_parent_instructions;
            body.emit(f020A);

            /* END IF */

            body.emit(assign(r01D5, r0207, 0x01));

            body.emit(assign(r01D6, r0206, 0x01));

            body.emit(assign(r01DA, r0205, 0x01));

            body.emit(assign(r01D9, r01E0, 0x01));


         body.instructions = f01E9_parent_instructions;
         body.emit(f01E9);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01E7->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0220 = less(r01D4, body.constant(int(0)));
         ir_if *f021F = new(mem_ctx) ir_if(operand(r0220).val);
         exec_list *const f021F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f021F->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0222 = equal(r01E3, body.constant(int(2047)));
            ir_if *f0221 = new(mem_ctx) ir_if(operand(r0222).val);
            exec_list *const f0221_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0221->then_instructions;

               ir_variable *const r0223 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0223);
               ir_expression *const r0224 = lshift(r01D0, body.constant(int(31)));
               body.emit(assign(r0223, add(r0224, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0223, body.constant(0u), 0x01));

               ir_variable *const r0225 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0225, swizzle_x(r01CB), 0x01));

               ir_variable *const r0226 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0226, swizzle_x(r01CC), 0x01));

               body.emit(assign(r0225, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r0226, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r0227 = bit_or(r01D5, r01D6);
               ir_expression *const r0228 = nequal(r0227, body.constant(0u));
               ir_swizzle *const r0229 = swizzle(r0228, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r022A = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r022B = gequal(r022A, body.constant(4292870144u));
               ir_expression *const r022C = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r022D = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r022E = nequal(r022D, body.constant(0u));
               ir_expression *const r022F = logic_or(r022C, r022E);
               ir_expression *const r0230 = logic_and(r022B, r022F);
               ir_swizzle *const r0231 = swizzle(r0230, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0232 = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r0233 = gequal(r0232, body.constant(4292870144u));
               ir_expression *const r0234 = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r0235 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r0236 = nequal(r0235, body.constant(0u));
               ir_expression *const r0237 = logic_or(r0234, r0236);
               ir_expression *const r0238 = logic_and(r0233, r0237);
               ir_swizzle *const r0239 = swizzle(r0238, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r023A = expr(ir_triop_csel, r0239, r0226, r0225);
               ir_expression *const r023B = expr(ir_triop_csel, r0231, r023A, r0226);
               body.emit(assign(r01CE, expr(ir_triop_csel, r0229, r023B, r0223), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0221->else_instructions;

               /* IF CONDITION */
               ir_expression *const r023D = equal(r01E0, body.constant(int(0)));
               ir_if *f023C = new(mem_ctx) ir_if(operand(r023D).val);
               exec_list *const f023C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f023C->then_instructions;

                  body.emit(assign(r01D4, add(r01D4, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f023C->else_instructions;

                  body.emit(assign(r01D7, bit_or(r01DD, body.constant(1048576u)), 0x01));


               body.instructions = f023C_parent_instructions;
               body.emit(f023C);

               /* END IF */

               ir_variable *const r023E = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r023E, body.constant(0u), 0x01));

               ir_variable *const r023F = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r023F, neg(r01D4), 0x01));

               ir_variable *const r0240 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0240);
               ir_variable *const r0241 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0241);
               ir_variable *const r0242 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0242);
               ir_variable *const r0243 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0244 = neg(r023F);
               body.emit(assign(r0243, bit_and(r0244, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0246 = equal(r023F, body.constant(int(0)));
               ir_if *f0245 = new(mem_ctx) ir_if(operand(r0246).val);
               exec_list *const f0245_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0245->then_instructions;

                  body.emit(assign(r0240, r023E, 0x01));

                  body.emit(assign(r0241, r01DC, 0x01));

                  body.emit(assign(r0242, r01D7, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0245->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0248 = less(r023F, body.constant(int(32)));
                  ir_if *f0247 = new(mem_ctx) ir_if(operand(r0248).val);
                  exec_list *const f0247_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0247->then_instructions;

                     body.emit(assign(r0240, lshift(swizzle_x(r01CB), r0243), 0x01));

                     ir_expression *const r0249 = lshift(r01D7, r0243);
                     ir_expression *const r024A = rshift(swizzle_x(r01CB), r023F);
                     body.emit(assign(r0241, bit_or(r0249, r024A), 0x01));

                     body.emit(assign(r0242, rshift(r01D7, r023F), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0247->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r024C = equal(r023F, body.constant(int(32)));
                     ir_if *f024B = new(mem_ctx) ir_if(operand(r024C).val);
                     exec_list *const f024B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f024B->then_instructions;

                        body.emit(assign(r0240, r01DC, 0x01));

                        body.emit(assign(r0241, r01D7, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f024B->else_instructions;

                        body.emit(assign(r023E, bit_or(body.constant(0u), swizzle_x(r01CB)), 0x01));

                        ir_expression *const r024D = less(r023F, body.constant(int(64)));
                        ir_expression *const r024E = lshift(r01D7, r0243);
                        ir_expression *const r024F = equal(r023F, body.constant(int(64)));
                        ir_expression *const r0250 = nequal(r01D7, body.constant(0u));
                        ir_expression *const r0251 = expr(ir_unop_b2i, r0250);
                        ir_expression *const r0252 = expr(ir_unop_i2u, r0251);
                        ir_expression *const r0253 = expr(ir_triop_csel, r024F, r01D7, r0252);
                        body.emit(assign(r0240, expr(ir_triop_csel, r024D, r024E, r0253), 0x01));

                        ir_expression *const r0254 = less(r023F, body.constant(int(64)));
                        ir_expression *const r0255 = bit_and(r023F, body.constant(int(31)));
                        ir_expression *const r0256 = rshift(r01D7, r0255);
                        body.emit(assign(r0241, expr(ir_triop_csel, r0254, r0256, body.constant(0u)), 0x01));


                     body.instructions = f024B_parent_instructions;
                     body.emit(f024B);

                     /* END IF */

                     body.emit(assign(r0242, body.constant(0u), 0x01));


                  body.instructions = f0247_parent_instructions;
                  body.emit(f0247);

                  /* END IF */

                  ir_expression *const r0257 = nequal(r023E, body.constant(0u));
                  ir_expression *const r0258 = expr(ir_unop_b2i, r0257);
                  ir_expression *const r0259 = expr(ir_unop_i2u, r0258);
                  body.emit(assign(r0240, bit_or(r0240, r0259), 0x01));


               body.instructions = f0245_parent_instructions;
               body.emit(f0245);

               /* END IF */

               body.emit(assign(r01D7, r0242, 0x01));

               body.emit(assign(r01D8, r0241, 0x01));

               body.emit(assign(r01DA, r0240, 0x01));

               body.emit(assign(r01D9, r01E3, 0x01));


            body.instructions = f0221_parent_instructions;
            body.emit(f0221);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f021F->else_instructions;

            /* IF CONDITION */
            ir_expression *const r025B = equal(r01E0, body.constant(int(2047)));
            ir_if *f025A = new(mem_ctx) ir_if(operand(r025B).val);
            exec_list *const f025A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f025A->then_instructions;

               ir_variable *const r025C = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r025C, swizzle_x(r01CB), 0x01));

               ir_variable *const r025D = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r025D, swizzle_x(r01CC), 0x01));

               body.emit(assign(r025C, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r025D, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r025E = bit_or(r01D7, r01D8);
               ir_expression *const r025F = bit_or(r01D5, r01D6);
               ir_expression *const r0260 = bit_or(r025E, r025F);
               ir_expression *const r0261 = nequal(r0260, body.constant(0u));
               ir_swizzle *const r0262 = swizzle(r0261, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0263 = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r0264 = gequal(r0263, body.constant(4292870144u));
               ir_expression *const r0265 = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r0266 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r0267 = nequal(r0266, body.constant(0u));
               ir_expression *const r0268 = logic_or(r0265, r0267);
               ir_expression *const r0269 = logic_and(r0264, r0268);
               ir_swizzle *const r026A = swizzle(r0269, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r026B = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r026C = gequal(r026B, body.constant(4292870144u));
               ir_expression *const r026D = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r026E = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r026F = nequal(r026E, body.constant(0u));
               ir_expression *const r0270 = logic_or(r026D, r026F);
               ir_expression *const r0271 = logic_and(r026C, r0270);
               ir_swizzle *const r0272 = swizzle(r0271, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0273 = expr(ir_triop_csel, r0272, r025D, r025C);
               ir_expression *const r0274 = expr(ir_triop_csel, r026A, r0273, r025D);
               body.emit(assign(r01CE, expr(ir_triop_csel, r0262, r0274, r01CB), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f025A->else_instructions;

               ir_variable *const r0275 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0276 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0276, add(r01D8, r01D6), 0x01));

               ir_expression *const r0277 = add(r01D7, r01D5);
               ir_expression *const r0278 = less(r0276, r01D8);
               ir_expression *const r0279 = expr(ir_unop_b2i, r0278);
               ir_expression *const r027A = expr(ir_unop_i2u, r0279);
               body.emit(assign(r0275, add(r0277, r027A), 0x01));

               body.emit(assign(r01DB, r0275, 0x01));

               /* IF CONDITION */
               ir_expression *const r027C = equal(r01E0, body.constant(int(0)));
               ir_if *f027B = new(mem_ctx) ir_if(operand(r027C).val);
               exec_list *const f027B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f027B->then_instructions;

                  ir_variable *const r027D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r027D);
                  ir_expression *const r027E = lshift(r01D0, body.constant(int(31)));
                  body.emit(assign(r027D, add(r027E, r0275), 0x02));

                  body.emit(assign(r027D, r0276, 0x01));

                  body.emit(assign(r01CE, r027D, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f027B->else_instructions;

                  body.emit(assign(r01DB, bit_or(r0275, body.constant(2097152u)), 0x01));

                  body.emit(assign(r01D9, r01E0, 0x01));

                  ir_variable *const r027F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r027F);
                  ir_variable *const r0280 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r0280);
                  ir_variable *const r0281 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r0281);
                  body.emit(assign(r027F, lshift(r0276, body.constant(int(31))), 0x01));

                  ir_expression *const r0282 = lshift(r01DB, body.constant(int(31)));
                  ir_expression *const r0283 = rshift(r0276, body.constant(int(1)));
                  body.emit(assign(r0280, bit_or(r0282, r0283), 0x01));

                  body.emit(assign(r0281, rshift(r01DB, body.constant(int(1))), 0x01));

                  body.emit(assign(r027F, bit_or(r027F, body.constant(0u)), 0x01));

                  body.emit(assign(r01DB, r0281, 0x01));

                  body.emit(assign(r01DA, r027F, 0x01));

                  ir_variable *const r0284 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0284, r01E0, 0x01));

                  ir_variable *const r0285 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0285, r0281, 0x01));

                  ir_variable *const r0286 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0286, r0280, 0x01));

                  ir_variable *const r0287 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0287, r027F, 0x01));

                  ir_variable *const r0288 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0288, body.constant(true), 0x01));

                  ir_variable *const r0289 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r028A = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r028A);
                  ir_expression *const r028B = expr(ir_unop_u2i, r027F);
                  body.emit(assign(r028A, less(r028B, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r028D = gequal(r01E0, body.constant(int(2045)));
                  ir_if *f028C = new(mem_ctx) ir_if(operand(r028D).val);
                  exec_list *const f028C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f028C->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r028F = less(body.constant(int(2045)), r01E0);
                     ir_expression *const r0290 = equal(r01E0, body.constant(int(2045)));
                     ir_expression *const r0291 = equal(body.constant(2097151u), r0281);
                     ir_expression *const r0292 = equal(body.constant(4294967295u), r0280);
                     ir_expression *const r0293 = logic_and(r0291, r0292);
                     ir_expression *const r0294 = logic_and(r0290, r0293);
                     ir_expression *const r0295 = logic_and(r0294, r028A);
                     ir_expression *const r0296 = logic_or(r028F, r0295);
                     ir_if *f028E = new(mem_ctx) ir_if(operand(r0296).val);
                     exec_list *const f028E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f028E->then_instructions;

                        ir_variable *const r0297 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0297);
                        ir_expression *const r0298 = lshift(r01D0, body.constant(int(31)));
                        body.emit(assign(r0297, add(r0298, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0297, body.constant(0u), 0x01));

                        body.emit(assign(r0289, r0297, 0x03));

                        body.emit(assign(r0288, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f028E->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r029A = less(r01E0, body.constant(int(0)));
                        ir_if *f0299 = new(mem_ctx) ir_if(operand(r029A).val);
                        exec_list *const f0299_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0299->then_instructions;

                           ir_variable *const r029B = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r029B, r027F, 0x01));

                           ir_variable *const r029C = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r029C, neg(r01E0), 0x01));

                           ir_variable *const r029D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r029D);
                           ir_variable *const r029E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r029E);
                           ir_variable *const r029F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r029F);
                           ir_variable *const r02A0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02A1 = neg(r029C);
                           body.emit(assign(r02A0, bit_and(r02A1, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02A3 = equal(r029C, body.constant(int(0)));
                           ir_if *f02A2 = new(mem_ctx) ir_if(operand(r02A3).val);
                           exec_list *const f02A2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02A2->then_instructions;

                              body.emit(assign(r029D, r027F, 0x01));

                              body.emit(assign(r029E, r0280, 0x01));

                              body.emit(assign(r029F, r0281, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02A2->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02A5 = less(r029C, body.constant(int(32)));
                              ir_if *f02A4 = new(mem_ctx) ir_if(operand(r02A5).val);
                              exec_list *const f02A4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02A4->then_instructions;

                                 body.emit(assign(r029D, lshift(r0280, r02A0), 0x01));

                                 ir_expression *const r02A6 = lshift(r0281, r02A0);
                                 ir_expression *const r02A7 = rshift(r0280, r029C);
                                 body.emit(assign(r029E, bit_or(r02A6, r02A7), 0x01));

                                 body.emit(assign(r029F, rshift(r0281, r029C), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02A4->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02A9 = equal(r029C, body.constant(int(32)));
                                 ir_if *f02A8 = new(mem_ctx) ir_if(operand(r02A9).val);
                                 exec_list *const f02A8_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02A8->then_instructions;

                                    body.emit(assign(r029D, r0280, 0x01));

                                    body.emit(assign(r029E, r0281, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02A8->else_instructions;

                                    body.emit(assign(r029B, bit_or(r027F, r0280), 0x01));

                                    ir_expression *const r02AA = less(r029C, body.constant(int(64)));
                                    ir_expression *const r02AB = lshift(r0281, r02A0);
                                    ir_expression *const r02AC = equal(r029C, body.constant(int(64)));
                                    ir_expression *const r02AD = nequal(r0281, body.constant(0u));
                                    ir_expression *const r02AE = expr(ir_unop_b2i, r02AD);
                                    ir_expression *const r02AF = expr(ir_unop_i2u, r02AE);
                                    ir_expression *const r02B0 = expr(ir_triop_csel, r02AC, r0281, r02AF);
                                    body.emit(assign(r029D, expr(ir_triop_csel, r02AA, r02AB, r02B0), 0x01));

                                    ir_expression *const r02B1 = less(r029C, body.constant(int(64)));
                                    ir_expression *const r02B2 = bit_and(r029C, body.constant(int(31)));
                                    ir_expression *const r02B3 = rshift(r0281, r02B2);
                                    body.emit(assign(r029E, expr(ir_triop_csel, r02B1, r02B3, body.constant(0u)), 0x01));


                                 body.instructions = f02A8_parent_instructions;
                                 body.emit(f02A8);

                                 /* END IF */

                                 body.emit(assign(r029F, body.constant(0u), 0x01));


                              body.instructions = f02A4_parent_instructions;
                              body.emit(f02A4);

                              /* END IF */

                              ir_expression *const r02B4 = nequal(r029B, body.constant(0u));
                              ir_expression *const r02B5 = expr(ir_unop_b2i, r02B4);
                              ir_expression *const r02B6 = expr(ir_unop_i2u, r02B5);
                              body.emit(assign(r029D, bit_or(r029D, r02B6), 0x01));


                           body.instructions = f02A2_parent_instructions;
                           body.emit(f02A2);

                           /* END IF */

                           body.emit(assign(r0285, r029F, 0x01));

                           body.emit(assign(r0286, r029E, 0x01));

                           body.emit(assign(r0287, r029D, 0x01));

                           body.emit(assign(r0284, body.constant(int(0)), 0x01));

                           body.emit(assign(r028A, less(r029D, body.constant(0u)), 0x01));


                        body.instructions = f0299_parent_instructions;
                        body.emit(f0299);

                        /* END IF */


                     body.instructions = f028E_parent_instructions;
                     body.emit(f028E);

                     /* END IF */


                  body.instructions = f028C_parent_instructions;
                  body.emit(f028C);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02B7 = new(mem_ctx) ir_if(operand(r0288).val);
                  exec_list *const f02B7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02B7->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02B8 = new(mem_ctx) ir_if(operand(r028A).val);
                     exec_list *const f02B8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02B8->then_instructions;

                        ir_variable *const r02B9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02B9, add(r0286, body.constant(1u)), 0x01));

                        ir_expression *const r02BA = less(r02B9, r0286);
                        ir_expression *const r02BB = expr(ir_unop_b2i, r02BA);
                        ir_expression *const r02BC = expr(ir_unop_i2u, r02BB);
                        body.emit(assign(r0285, add(r0285, r02BC), 0x01));

                        ir_expression *const r02BD = equal(r0287, body.constant(0u));
                        ir_expression *const r02BE = expr(ir_unop_b2i, r02BD);
                        ir_expression *const r02BF = expr(ir_unop_i2u, r02BE);
                        ir_expression *const r02C0 = add(r0287, r02BF);
                        ir_expression *const r02C1 = bit_and(r02C0, body.constant(1u));
                        ir_expression *const r02C2 = expr(ir_unop_bit_not, r02C1);
                        body.emit(assign(r0286, bit_and(r02B9, r02C2), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02B8->else_instructions;

                        ir_expression *const r02C3 = bit_or(r0285, r0286);
                        ir_expression *const r02C4 = equal(r02C3, body.constant(0u));
                        body.emit(assign(r0284, expr(ir_triop_csel, r02C4, body.constant(int(0)), r0284), 0x01));


                     body.instructions = f02B8_parent_instructions;
                     body.emit(f02B8);

                     /* END IF */

                     ir_variable *const r02C5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r02C5);
                     ir_expression *const r02C6 = lshift(r01D0, body.constant(int(31)));
                     ir_expression *const r02C7 = expr(ir_unop_i2u, r0284);
                     ir_expression *const r02C8 = lshift(r02C7, body.constant(int(20)));
                     ir_expression *const r02C9 = add(r02C6, r02C8);
                     body.emit(assign(r02C5, add(r02C9, r0285), 0x02));

                     body.emit(assign(r02C5, r0286, 0x01));

                     body.emit(assign(r0289, r02C5, 0x03));

                     body.emit(assign(r0288, body.constant(false), 0x01));


                  body.instructions = f02B7_parent_instructions;
                  body.emit(f02B7);

                  /* END IF */

                  body.emit(assign(r01CE, r0289, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


               body.instructions = f027B_parent_instructions;
               body.emit(f027B);

               /* END IF */


            body.instructions = f025A_parent_instructions;
            body.emit(f025A);

            /* END IF */


         body.instructions = f021F_parent_instructions;
         body.emit(f021F);

         /* END IF */


      body.instructions = f01E7_parent_instructions;
      body.emit(f01E7);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02CA = new(mem_ctx) ir_if(operand(r01CD).val);
      exec_list *const f02CA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02CA->then_instructions;

         body.emit(assign(r01D7, bit_or(r01D7, body.constant(1048576u)), 0x01));

         ir_variable *const r02CB = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r02CC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r02CC, add(r01D8, r01D6), 0x01));

         ir_expression *const r02CD = add(r01D7, r01D5);
         ir_expression *const r02CE = less(r02CC, r01D8);
         ir_expression *const r02CF = expr(ir_unop_b2i, r02CE);
         ir_expression *const r02D0 = expr(ir_unop_i2u, r02CF);
         body.emit(assign(r02CB, add(r02CD, r02D0), 0x01));

         body.emit(assign(r01DB, r02CB, 0x01));

         body.emit(assign(r01D9, add(r01D9, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r02D2 = less(r02CB, body.constant(2097152u));
         ir_if *f02D1 = new(mem_ctx) ir_if(operand(r02D2).val);
         exec_list *const f02D1_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02D1->then_instructions;

            ir_variable *const r02D3 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r02D3, r01D9, 0x01));

            ir_variable *const r02D4 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r02D4, r02CB, 0x01));

            ir_variable *const r02D5 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r02D5, r02CC, 0x01));

            ir_variable *const r02D6 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r02D6, r01DA, 0x01));

            ir_variable *const r02D7 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r02D7, body.constant(true), 0x01));

            ir_variable *const r02D8 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r02D9 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r02D9);
            ir_expression *const r02DA = expr(ir_unop_u2i, r01DA);
            body.emit(assign(r02D9, less(r02DA, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02DC = gequal(r01D9, body.constant(int(2045)));
            ir_if *f02DB = new(mem_ctx) ir_if(operand(r02DC).val);
            exec_list *const f02DB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02DB->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02DE = less(body.constant(int(2045)), r01D9);
               ir_expression *const r02DF = equal(r01D9, body.constant(int(2045)));
               ir_expression *const r02E0 = equal(body.constant(2097151u), r02CB);
               ir_expression *const r02E1 = equal(body.constant(4294967295u), r02CC);
               ir_expression *const r02E2 = logic_and(r02E0, r02E1);
               ir_expression *const r02E3 = logic_and(r02DF, r02E2);
               ir_expression *const r02E4 = logic_and(r02E3, r02D9);
               ir_expression *const r02E5 = logic_or(r02DE, r02E4);
               ir_if *f02DD = new(mem_ctx) ir_if(operand(r02E5).val);
               exec_list *const f02DD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02DD->then_instructions;

                  ir_variable *const r02E6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02E6);
                  ir_expression *const r02E7 = lshift(r01D0, body.constant(int(31)));
                  body.emit(assign(r02E6, add(r02E7, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r02E6, body.constant(0u), 0x01));

                  body.emit(assign(r02D8, r02E6, 0x03));

                  body.emit(assign(r02D7, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02DD->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r02E9 = less(r01D9, body.constant(int(0)));
                  ir_if *f02E8 = new(mem_ctx) ir_if(operand(r02E9).val);
                  exec_list *const f02E8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02E8->then_instructions;

                     ir_variable *const r02EA = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r02EA, r01DA, 0x01));

                     ir_variable *const r02EB = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r02EB, neg(r01D9), 0x01));

                     ir_variable *const r02EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r02EC);
                     ir_variable *const r02ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r02ED);
                     ir_variable *const r02EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r02EE);
                     ir_variable *const r02EF = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r02F0 = neg(r02EB);
                     body.emit(assign(r02EF, bit_and(r02F0, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r02F2 = equal(r02EB, body.constant(int(0)));
                     ir_if *f02F1 = new(mem_ctx) ir_if(operand(r02F2).val);
                     exec_list *const f02F1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02F1->then_instructions;

                        body.emit(assign(r02EC, r01DA, 0x01));

                        body.emit(assign(r02ED, r02CC, 0x01));

                        body.emit(assign(r02EE, r02CB, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02F1->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02F4 = less(r02EB, body.constant(int(32)));
                        ir_if *f02F3 = new(mem_ctx) ir_if(operand(r02F4).val);
                        exec_list *const f02F3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02F3->then_instructions;

                           body.emit(assign(r02EC, lshift(r02CC, r02EF), 0x01));

                           ir_expression *const r02F5 = lshift(r02CB, r02EF);
                           ir_expression *const r02F6 = rshift(r02CC, r02EB);
                           body.emit(assign(r02ED, bit_or(r02F5, r02F6), 0x01));

                           body.emit(assign(r02EE, rshift(r02CB, r02EB), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f02F3->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r02F8 = equal(r02EB, body.constant(int(32)));
                           ir_if *f02F7 = new(mem_ctx) ir_if(operand(r02F8).val);
                           exec_list *const f02F7_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02F7->then_instructions;

                              body.emit(assign(r02EC, r02CC, 0x01));

                              body.emit(assign(r02ED, r02CB, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02F7->else_instructions;

                              body.emit(assign(r02EA, bit_or(r01DA, r02CC), 0x01));

                              ir_expression *const r02F9 = less(r02EB, body.constant(int(64)));
                              ir_expression *const r02FA = lshift(r02CB, r02EF);
                              ir_expression *const r02FB = equal(r02EB, body.constant(int(64)));
                              ir_expression *const r02FC = nequal(r02CB, body.constant(0u));
                              ir_expression *const r02FD = expr(ir_unop_b2i, r02FC);
                              ir_expression *const r02FE = expr(ir_unop_i2u, r02FD);
                              ir_expression *const r02FF = expr(ir_triop_csel, r02FB, r02CB, r02FE);
                              body.emit(assign(r02EC, expr(ir_triop_csel, r02F9, r02FA, r02FF), 0x01));

                              ir_expression *const r0300 = less(r02EB, body.constant(int(64)));
                              ir_expression *const r0301 = bit_and(r02EB, body.constant(int(31)));
                              ir_expression *const r0302 = rshift(r02CB, r0301);
                              body.emit(assign(r02ED, expr(ir_triop_csel, r0300, r0302, body.constant(0u)), 0x01));


                           body.instructions = f02F7_parent_instructions;
                           body.emit(f02F7);

                           /* END IF */

                           body.emit(assign(r02EE, body.constant(0u), 0x01));


                        body.instructions = f02F3_parent_instructions;
                        body.emit(f02F3);

                        /* END IF */

                        ir_expression *const r0303 = nequal(r02EA, body.constant(0u));
                        ir_expression *const r0304 = expr(ir_unop_b2i, r0303);
                        ir_expression *const r0305 = expr(ir_unop_i2u, r0304);
                        body.emit(assign(r02EC, bit_or(r02EC, r0305), 0x01));


                     body.instructions = f02F1_parent_instructions;
                     body.emit(f02F1);

                     /* END IF */

                     body.emit(assign(r02D4, r02EE, 0x01));

                     body.emit(assign(r02D5, r02ED, 0x01));

                     body.emit(assign(r02D6, r02EC, 0x01));

                     body.emit(assign(r02D3, body.constant(int(0)), 0x01));

                     body.emit(assign(r02D9, less(r02EC, body.constant(0u)), 0x01));


                  body.instructions = f02E8_parent_instructions;
                  body.emit(f02E8);

                  /* END IF */


               body.instructions = f02DD_parent_instructions;
               body.emit(f02DD);

               /* END IF */


            body.instructions = f02DB_parent_instructions;
            body.emit(f02DB);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0306 = new(mem_ctx) ir_if(operand(r02D7).val);
            exec_list *const f0306_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0306->then_instructions;

               /* IF CONDITION */
               ir_if *f0307 = new(mem_ctx) ir_if(operand(r02D9).val);
               exec_list *const f0307_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0307->then_instructions;

                  ir_variable *const r0308 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0308, add(r02D5, body.constant(1u)), 0x01));

                  ir_expression *const r0309 = less(r0308, r02D5);
                  ir_expression *const r030A = expr(ir_unop_b2i, r0309);
                  ir_expression *const r030B = expr(ir_unop_i2u, r030A);
                  body.emit(assign(r02D4, add(r02D4, r030B), 0x01));

                  ir_expression *const r030C = equal(r02D6, body.constant(0u));
                  ir_expression *const r030D = expr(ir_unop_b2i, r030C);
                  ir_expression *const r030E = expr(ir_unop_i2u, r030D);
                  ir_expression *const r030F = add(r02D6, r030E);
                  ir_expression *const r0310 = bit_and(r030F, body.constant(1u));
                  ir_expression *const r0311 = expr(ir_unop_bit_not, r0310);
                  body.emit(assign(r02D5, bit_and(r0308, r0311), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0307->else_instructions;

                  ir_expression *const r0312 = bit_or(r02D4, r02D5);
                  ir_expression *const r0313 = equal(r0312, body.constant(0u));
                  body.emit(assign(r02D3, expr(ir_triop_csel, r0313, body.constant(int(0)), r02D3), 0x01));


               body.instructions = f0307_parent_instructions;
               body.emit(f0307);

               /* END IF */

               ir_variable *const r0314 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0314);
               ir_expression *const r0315 = lshift(r01D0, body.constant(int(31)));
               ir_expression *const r0316 = expr(ir_unop_i2u, r02D3);
               ir_expression *const r0317 = lshift(r0316, body.constant(int(20)));
               ir_expression *const r0318 = add(r0315, r0317);
               body.emit(assign(r0314, add(r0318, r02D4), 0x02));

               body.emit(assign(r0314, r02D5, 0x01));

               body.emit(assign(r02D8, r0314, 0x03));

               body.emit(assign(r02D7, body.constant(false), 0x01));


            body.instructions = f0306_parent_instructions;
            body.emit(f0306);

            /* END IF */

            body.emit(assign(r01CE, r02D8, 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02D1->else_instructions;

            body.emit(assign(r01D9, add(r01D9, body.constant(int(1))), 0x01));

            ir_variable *const r0319 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0319);
            ir_variable *const r031A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r031A);
            ir_variable *const r031B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r031B);
            body.emit(assign(r0319, lshift(r02CC, body.constant(int(31))), 0x01));

            ir_expression *const r031C = lshift(r02CB, body.constant(int(31)));
            ir_expression *const r031D = rshift(r02CC, body.constant(int(1)));
            body.emit(assign(r031A, bit_or(r031C, r031D), 0x01));

            body.emit(assign(r031B, rshift(r02CB, body.constant(int(1))), 0x01));

            ir_expression *const r031E = nequal(r01DA, body.constant(0u));
            ir_expression *const r031F = expr(ir_unop_b2i, r031E);
            ir_expression *const r0320 = expr(ir_unop_i2u, r031F);
            body.emit(assign(r0319, bit_or(r0319, r0320), 0x01));

            body.emit(assign(r01DB, r031B, 0x01));

            body.emit(assign(r01DA, r0319, 0x01));

            ir_variable *const r0321 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0321, r01D9, 0x01));

            ir_variable *const r0322 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0322, r031B, 0x01));

            ir_variable *const r0323 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0323, r031A, 0x01));

            ir_variable *const r0324 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0324, r0319, 0x01));

            ir_variable *const r0325 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0325, body.constant(true), 0x01));

            ir_variable *const r0326 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0327 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0327);
            ir_expression *const r0328 = expr(ir_unop_u2i, r0319);
            body.emit(assign(r0327, less(r0328, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r032A = gequal(r01D9, body.constant(int(2045)));
            ir_if *f0329 = new(mem_ctx) ir_if(operand(r032A).val);
            exec_list *const f0329_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0329->then_instructions;

               /* IF CONDITION */
               ir_expression *const r032C = less(body.constant(int(2045)), r01D9);
               ir_expression *const r032D = equal(r01D9, body.constant(int(2045)));
               ir_expression *const r032E = equal(body.constant(2097151u), r031B);
               ir_expression *const r032F = equal(body.constant(4294967295u), r031A);
               ir_expression *const r0330 = logic_and(r032E, r032F);
               ir_expression *const r0331 = logic_and(r032D, r0330);
               ir_expression *const r0332 = logic_and(r0331, r0327);
               ir_expression *const r0333 = logic_or(r032C, r0332);
               ir_if *f032B = new(mem_ctx) ir_if(operand(r0333).val);
               exec_list *const f032B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f032B->then_instructions;

                  ir_variable *const r0334 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0334);
                  ir_expression *const r0335 = lshift(r01D0, body.constant(int(31)));
                  body.emit(assign(r0334, add(r0335, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0334, body.constant(0u), 0x01));

                  body.emit(assign(r0326, r0334, 0x03));

                  body.emit(assign(r0325, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f032B->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0337 = less(r01D9, body.constant(int(0)));
                  ir_if *f0336 = new(mem_ctx) ir_if(operand(r0337).val);
                  exec_list *const f0336_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0336->then_instructions;

                     ir_variable *const r0338 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0338, r0319, 0x01));

                     ir_variable *const r0339 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0339, neg(r01D9), 0x01));

                     ir_variable *const r033A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r033A);
                     ir_variable *const r033B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r033B);
                     ir_variable *const r033C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r033C);
                     ir_variable *const r033D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r033E = neg(r0339);
                     body.emit(assign(r033D, bit_and(r033E, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0340 = equal(r0339, body.constant(int(0)));
                     ir_if *f033F = new(mem_ctx) ir_if(operand(r0340).val);
                     exec_list *const f033F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f033F->then_instructions;

                        body.emit(assign(r033A, r0319, 0x01));

                        body.emit(assign(r033B, r031A, 0x01));

                        body.emit(assign(r033C, r031B, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f033F->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0342 = less(r0339, body.constant(int(32)));
                        ir_if *f0341 = new(mem_ctx) ir_if(operand(r0342).val);
                        exec_list *const f0341_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0341->then_instructions;

                           body.emit(assign(r033A, lshift(r031A, r033D), 0x01));

                           ir_expression *const r0343 = lshift(r031B, r033D);
                           ir_expression *const r0344 = rshift(r031A, r0339);
                           body.emit(assign(r033B, bit_or(r0343, r0344), 0x01));

                           body.emit(assign(r033C, rshift(r031B, r0339), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0341->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0346 = equal(r0339, body.constant(int(32)));
                           ir_if *f0345 = new(mem_ctx) ir_if(operand(r0346).val);
                           exec_list *const f0345_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0345->then_instructions;

                              body.emit(assign(r033A, r031A, 0x01));

                              body.emit(assign(r033B, r031B, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0345->else_instructions;

                              body.emit(assign(r0338, bit_or(r0319, r031A), 0x01));

                              ir_expression *const r0347 = less(r0339, body.constant(int(64)));
                              ir_expression *const r0348 = lshift(r031B, r033D);
                              ir_expression *const r0349 = equal(r0339, body.constant(int(64)));
                              ir_expression *const r034A = nequal(r031B, body.constant(0u));
                              ir_expression *const r034B = expr(ir_unop_b2i, r034A);
                              ir_expression *const r034C = expr(ir_unop_i2u, r034B);
                              ir_expression *const r034D = expr(ir_triop_csel, r0349, r031B, r034C);
                              body.emit(assign(r033A, expr(ir_triop_csel, r0347, r0348, r034D), 0x01));

                              ir_expression *const r034E = less(r0339, body.constant(int(64)));
                              ir_expression *const r034F = bit_and(r0339, body.constant(int(31)));
                              ir_expression *const r0350 = rshift(r031B, r034F);
                              body.emit(assign(r033B, expr(ir_triop_csel, r034E, r0350, body.constant(0u)), 0x01));


                           body.instructions = f0345_parent_instructions;
                           body.emit(f0345);

                           /* END IF */

                           body.emit(assign(r033C, body.constant(0u), 0x01));


                        body.instructions = f0341_parent_instructions;
                        body.emit(f0341);

                        /* END IF */

                        ir_expression *const r0351 = nequal(r0338, body.constant(0u));
                        ir_expression *const r0352 = expr(ir_unop_b2i, r0351);
                        ir_expression *const r0353 = expr(ir_unop_i2u, r0352);
                        body.emit(assign(r033A, bit_or(r033A, r0353), 0x01));


                     body.instructions = f033F_parent_instructions;
                     body.emit(f033F);

                     /* END IF */

                     body.emit(assign(r0322, r033C, 0x01));

                     body.emit(assign(r0323, r033B, 0x01));

                     body.emit(assign(r0324, r033A, 0x01));

                     body.emit(assign(r0321, body.constant(int(0)), 0x01));

                     body.emit(assign(r0327, less(r033A, body.constant(0u)), 0x01));


                  body.instructions = f0336_parent_instructions;
                  body.emit(f0336);

                  /* END IF */


               body.instructions = f032B_parent_instructions;
               body.emit(f032B);

               /* END IF */


            body.instructions = f0329_parent_instructions;
            body.emit(f0329);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0354 = new(mem_ctx) ir_if(operand(r0325).val);
            exec_list *const f0354_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0354->then_instructions;

               /* IF CONDITION */
               ir_if *f0355 = new(mem_ctx) ir_if(operand(r0327).val);
               exec_list *const f0355_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0355->then_instructions;

                  ir_variable *const r0356 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0356, add(r0323, body.constant(1u)), 0x01));

                  ir_expression *const r0357 = less(r0356, r0323);
                  ir_expression *const r0358 = expr(ir_unop_b2i, r0357);
                  ir_expression *const r0359 = expr(ir_unop_i2u, r0358);
                  body.emit(assign(r0322, add(r0322, r0359), 0x01));

                  ir_expression *const r035A = equal(r0324, body.constant(0u));
                  ir_expression *const r035B = expr(ir_unop_b2i, r035A);
                  ir_expression *const r035C = expr(ir_unop_i2u, r035B);
                  ir_expression *const r035D = add(r0324, r035C);
                  ir_expression *const r035E = bit_and(r035D, body.constant(1u));
                  ir_expression *const r035F = expr(ir_unop_bit_not, r035E);
                  body.emit(assign(r0323, bit_and(r0356, r035F), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0355->else_instructions;

                  ir_expression *const r0360 = bit_or(r0322, r0323);
                  ir_expression *const r0361 = equal(r0360, body.constant(0u));
                  body.emit(assign(r0321, expr(ir_triop_csel, r0361, body.constant(int(0)), r0321), 0x01));


               body.instructions = f0355_parent_instructions;
               body.emit(f0355);

               /* END IF */

               ir_variable *const r0362 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0362);
               ir_expression *const r0363 = lshift(r01D0, body.constant(int(31)));
               ir_expression *const r0364 = expr(ir_unop_i2u, r0321);
               ir_expression *const r0365 = lshift(r0364, body.constant(int(20)));
               ir_expression *const r0366 = add(r0363, r0365);
               body.emit(assign(r0362, add(r0366, r0322), 0x02));

               body.emit(assign(r0362, r0323, 0x01));

               body.emit(assign(r0326, r0362, 0x03));

               body.emit(assign(r0325, body.constant(false), 0x01));


            body.instructions = f0354_parent_instructions;
            body.emit(f0354);

            /* END IF */

            body.emit(assign(r01CE, r0326, 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


         body.instructions = f02D1_parent_instructions;
         body.emit(f02D1);

         /* END IF */


      body.instructions = f02CA_parent_instructions;
      body.emit(f02CA);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01D2->else_instructions;

      ir_variable *const r0367 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r0367);
      ir_variable *const r0368 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
      body.emit(r0368);
      ir_variable *const r0369 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
      body.emit(r0369);
      ir_variable *const r036A = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r036A);
      ir_variable *const r036B = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r036B);
      ir_variable *const r036C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r036C);
      ir_variable *const r036D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r036D);
      ir_variable *const r036E = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r036E);
      ir_variable *const r036F = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r0370 = rshift(swizzle_y(r01CB), body.constant(int(20)));
      ir_expression *const r0371 = bit_and(r0370, body.constant(2047u));
      body.emit(assign(r036F, expr(ir_unop_u2i, r0371), 0x01));

      body.emit(assign(r0369, r036F, 0x01));

      ir_variable *const r0372 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r0373 = rshift(swizzle_y(r01CC), body.constant(int(20)));
      ir_expression *const r0374 = bit_and(r0373, body.constant(2047u));
      body.emit(assign(r0372, expr(ir_unop_u2i, r0374), 0x01));

      body.emit(assign(r0368, r0372, 0x01));

      body.emit(assign(r0367, sub(r036F, r0372), 0x01));

      ir_variable *const r0375 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r0376 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0376, lshift(swizzle_x(r01CB), body.constant(int(10))), 0x01));

      ir_expression *const r0377 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
      ir_expression *const r0378 = lshift(r0377, body.constant(int(10)));
      ir_expression *const r0379 = rshift(swizzle_x(r01CB), body.constant(int(22)));
      body.emit(assign(r0375, bit_or(r0378, r0379), 0x01));

      body.emit(assign(r036C, r0375, 0x01));

      body.emit(assign(r036D, r0376, 0x01));

      ir_variable *const r037A = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r037B = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r037B, lshift(swizzle_x(r01CC), body.constant(int(10))), 0x01));

      ir_expression *const r037C = bit_and(swizzle_y(r01CC), body.constant(1048575u));
      ir_expression *const r037D = lshift(r037C, body.constant(int(10)));
      ir_expression *const r037E = rshift(swizzle_x(r01CC), body.constant(int(22)));
      body.emit(assign(r037A, bit_or(r037D, r037E), 0x01));

      body.emit(assign(r036A, r037A, 0x01));

      body.emit(assign(r036B, r037B, 0x01));

      /* IF CONDITION */
      ir_expression *const r0380 = less(body.constant(int(0)), r0367);
      ir_if *f037F = new(mem_ctx) ir_if(operand(r0380).val);
      exec_list *const f037F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f037F->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0382 = equal(r036F, body.constant(int(2047)));
         ir_if *f0381 = new(mem_ctx) ir_if(operand(r0382).val);
         exec_list *const f0381_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0381->then_instructions;

            ir_variable *const r0383 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0383, swizzle_x(r01CB), 0x01));

            ir_variable *const r0384 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0384, swizzle_x(r01CC), 0x01));

            body.emit(assign(r0383, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

            body.emit(assign(r0384, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

            ir_expression *const r0385 = bit_or(r0375, r0376);
            ir_expression *const r0386 = nequal(r0385, body.constant(0u));
            ir_swizzle *const r0387 = swizzle(r0386, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0388 = lshift(swizzle_y(r01CB), body.constant(int(1)));
            ir_expression *const r0389 = gequal(r0388, body.constant(4292870144u));
            ir_expression *const r038A = nequal(swizzle_x(r01CB), body.constant(0u));
            ir_expression *const r038B = bit_and(swizzle_y(r01CB), body.constant(1048575u));
            ir_expression *const r038C = nequal(r038B, body.constant(0u));
            ir_expression *const r038D = logic_or(r038A, r038C);
            ir_expression *const r038E = logic_and(r0389, r038D);
            ir_swizzle *const r038F = swizzle(r038E, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0390 = lshift(swizzle_y(r01CC), body.constant(int(1)));
            ir_expression *const r0391 = gequal(r0390, body.constant(4292870144u));
            ir_expression *const r0392 = nequal(swizzle_x(r01CC), body.constant(0u));
            ir_expression *const r0393 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
            ir_expression *const r0394 = nequal(r0393, body.constant(0u));
            ir_expression *const r0395 = logic_or(r0392, r0394);
            ir_expression *const r0396 = logic_and(r0391, r0395);
            ir_swizzle *const r0397 = swizzle(r0396, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0398 = expr(ir_triop_csel, r0397, r0384, r0383);
            ir_expression *const r0399 = expr(ir_triop_csel, r038F, r0398, r0384);
            body.emit(assign(r01CE, expr(ir_triop_csel, r0387, r0399, r01CB), 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0381->else_instructions;

            /* IF CONDITION */
            ir_expression *const r039B = equal(r0372, body.constant(int(0)));
            ir_if *f039A = new(mem_ctx) ir_if(operand(r039B).val);
            exec_list *const f039A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f039A->then_instructions;

               body.emit(assign(r0367, add(r0367, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f039A->else_instructions;

               body.emit(assign(r036A, bit_or(r037A, body.constant(1073741824u)), 0x01));


            body.instructions = f039A_parent_instructions;
            body.emit(f039A);

            /* END IF */

            ir_variable *const r039C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r039C);
            ir_variable *const r039D = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r039E = neg(r0367);
            body.emit(assign(r039D, bit_and(r039E, body.constant(int(31))), 0x01));

            ir_variable *const r039F = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03A0 = less(r0367, body.constant(int(32)));
            ir_expression *const r03A1 = rshift(r036A, r0367);
            ir_expression *const r03A2 = equal(r0367, body.constant(int(0)));
            ir_expression *const r03A3 = expr(ir_triop_csel, r03A2, r036A, body.constant(0u));
            body.emit(assign(r039F, expr(ir_triop_csel, r03A0, r03A1, r03A3), 0x01));

            /* IF CONDITION */
            ir_expression *const r03A5 = equal(r0367, body.constant(int(0)));
            ir_if *f03A4 = new(mem_ctx) ir_if(operand(r03A5).val);
            exec_list *const f03A4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03A4->then_instructions;

               body.emit(assign(r039C, r037B, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03A4->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03A7 = less(r0367, body.constant(int(32)));
               ir_if *f03A6 = new(mem_ctx) ir_if(operand(r03A7).val);
               exec_list *const f03A6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03A6->then_instructions;

                  ir_expression *const r03A8 = lshift(r036A, r039D);
                  ir_expression *const r03A9 = rshift(r037B, r0367);
                  ir_expression *const r03AA = bit_or(r03A8, r03A9);
                  ir_expression *const r03AB = lshift(r037B, r039D);
                  ir_expression *const r03AC = nequal(r03AB, body.constant(0u));
                  ir_expression *const r03AD = expr(ir_unop_b2i, r03AC);
                  ir_expression *const r03AE = expr(ir_unop_i2u, r03AD);
                  body.emit(assign(r039C, bit_or(r03AA, r03AE), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03A6->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03B0 = equal(r0367, body.constant(int(32)));
                  ir_if *f03AF = new(mem_ctx) ir_if(operand(r03B0).val);
                  exec_list *const f03AF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03AF->then_instructions;

                     ir_expression *const r03B1 = nequal(r037B, body.constant(0u));
                     ir_expression *const r03B2 = expr(ir_unop_b2i, r03B1);
                     ir_expression *const r03B3 = expr(ir_unop_i2u, r03B2);
                     body.emit(assign(r039C, bit_or(r036A, r03B3), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03AF->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03B5 = less(r0367, body.constant(int(64)));
                     ir_if *f03B4 = new(mem_ctx) ir_if(operand(r03B5).val);
                     exec_list *const f03B4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03B4->then_instructions;

                        ir_expression *const r03B6 = bit_and(r0367, body.constant(int(31)));
                        ir_expression *const r03B7 = rshift(r036A, r03B6);
                        ir_expression *const r03B8 = lshift(r036A, r039D);
                        ir_expression *const r03B9 = bit_or(r03B8, r037B);
                        ir_expression *const r03BA = nequal(r03B9, body.constant(0u));
                        ir_expression *const r03BB = expr(ir_unop_b2i, r03BA);
                        ir_expression *const r03BC = expr(ir_unop_i2u, r03BB);
                        body.emit(assign(r039C, bit_or(r03B7, r03BC), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03B4->else_instructions;

                        ir_expression *const r03BD = bit_or(r036A, r037B);
                        ir_expression *const r03BE = nequal(r03BD, body.constant(0u));
                        ir_expression *const r03BF = expr(ir_unop_b2i, r03BE);
                        body.emit(assign(r039C, expr(ir_unop_i2u, r03BF), 0x01));


                     body.instructions = f03B4_parent_instructions;
                     body.emit(f03B4);

                     /* END IF */


                  body.instructions = f03AF_parent_instructions;
                  body.emit(f03AF);

                  /* END IF */


               body.instructions = f03A6_parent_instructions;
               body.emit(f03A6);

               /* END IF */


            body.instructions = f03A4_parent_instructions;
            body.emit(f03A4);

            /* END IF */

            body.emit(assign(r036A, r039F, 0x01));

            body.emit(assign(r036B, r039C, 0x01));

            body.emit(assign(r036C, bit_or(r0375, body.constant(1073741824u)), 0x01));

            ir_variable *const r03C0 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_expression *const r03C1 = sub(r036C, r039F);
            ir_expression *const r03C2 = less(r0376, r039C);
            ir_expression *const r03C3 = expr(ir_unop_b2i, r03C2);
            ir_expression *const r03C4 = expr(ir_unop_i2u, r03C3);
            body.emit(assign(r03C0, sub(r03C1, r03C4), 0x01));

            body.emit(assign(r036E, add(r036F, body.constant(int(-1))), 0x01));

            ir_variable *const r03C5 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03C5, add(r036E, body.constant(int(-10))), 0x01));

            ir_variable *const r03C6 = body.make_temp(glsl_type::uint_type, "zFrac0");
            ir_variable *const r03C7 = body.make_temp(glsl_type::uint_type, "zFrac1");
            ir_variable *const r03C8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03C8);
            ir_variable *const r03C9 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03C9);
            ir_expression *const r03CA = equal(r03C0, body.constant(0u));
            ir_expression *const r03CB = add(r03C5, body.constant(int(-32)));
            body.emit(assign(r03C5, expr(ir_triop_csel, r03CA, r03CB, r03C5), 0x01));

            ir_variable *const r03CC = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03CD = equal(r03C0, body.constant(0u));
            ir_expression *const r03CE = sub(r0376, r039C);
            body.emit(assign(r03CC, expr(ir_triop_csel, r03CD, body.constant(0u), r03CE), 0x01));

            body.emit(assign(r03C7, r03CC, 0x01));

            ir_variable *const r03CF = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03D0 = equal(r03C0, body.constant(0u));
            body.emit(assign(r03CF, expr(ir_triop_csel, r03D0, r03CC, r03C0), 0x01));

            body.emit(assign(r03C6, r03CF, 0x01));

            ir_expression *const r03D1 = equal(r03CF, body.constant(0u));
            ir_expression *const r03D2 = expr(ir_unop_find_msb, r03CF);
            ir_expression *const r03D3 = sub(body.constant(int(31)), r03D2);
            ir_expression *const r03D4 = expr(ir_triop_csel, r03D1, body.constant(int(32)), r03D3);
            body.emit(assign(r03C9, add(r03D4, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03D6 = gequal(r03C9, body.constant(int(0)));
            ir_if *f03D5 = new(mem_ctx) ir_if(operand(r03D6).val);
            exec_list *const f03D5_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03D5->then_instructions;

               body.emit(assign(r03C8, body.constant(0u), 0x01));

               ir_expression *const r03D7 = equal(r03C9, body.constant(int(0)));
               ir_expression *const r03D8 = lshift(r03CF, r03C9);
               ir_expression *const r03D9 = neg(r03C9);
               ir_expression *const r03DA = bit_and(r03D9, body.constant(int(31)));
               ir_expression *const r03DB = rshift(r03CC, r03DA);
               ir_expression *const r03DC = bit_or(r03D8, r03DB);
               body.emit(assign(r03C6, expr(ir_triop_csel, r03D7, r03CF, r03DC), 0x01));

               body.emit(assign(r03C7, lshift(r03CC, r03C9), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03D5->else_instructions;

               ir_variable *const r03DD = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r03DD, body.constant(0u), 0x01));

               ir_variable *const r03DE = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r03DE, neg(r03C9), 0x01));

               ir_variable *const r03DF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r03DF);
               ir_variable *const r03E0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r03E0);
               ir_variable *const r03E1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r03E1);
               ir_variable *const r03E2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r03E3 = neg(r03DE);
               body.emit(assign(r03E2, bit_and(r03E3, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r03E5 = equal(r03DE, body.constant(int(0)));
               ir_if *f03E4 = new(mem_ctx) ir_if(operand(r03E5).val);
               exec_list *const f03E4_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E4->then_instructions;

                  body.emit(assign(r03DF, r03DD, 0x01));

                  body.emit(assign(r03E0, r03C7, 0x01));

                  body.emit(assign(r03E1, r03C6, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03E4->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03E7 = less(r03DE, body.constant(int(32)));
                  ir_if *f03E6 = new(mem_ctx) ir_if(operand(r03E7).val);
                  exec_list *const f03E6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03E6->then_instructions;

                     body.emit(assign(r03DF, lshift(r03C7, r03E2), 0x01));

                     ir_expression *const r03E8 = lshift(r03C6, r03E2);
                     ir_expression *const r03E9 = rshift(r03C7, r03DE);
                     body.emit(assign(r03E0, bit_or(r03E8, r03E9), 0x01));

                     body.emit(assign(r03E1, rshift(r03C6, r03DE), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03E6->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03EB = equal(r03DE, body.constant(int(32)));
                     ir_if *f03EA = new(mem_ctx) ir_if(operand(r03EB).val);
                     exec_list *const f03EA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03EA->then_instructions;

                        body.emit(assign(r03DF, r03C7, 0x01));

                        body.emit(assign(r03E0, r03C6, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03EA->else_instructions;

                        body.emit(assign(r03DD, bit_or(body.constant(0u), r03C7), 0x01));

                        ir_expression *const r03EC = less(r03DE, body.constant(int(64)));
                        ir_expression *const r03ED = lshift(r03C6, r03E2);
                        ir_expression *const r03EE = equal(r03DE, body.constant(int(64)));
                        ir_expression *const r03EF = nequal(r03C6, body.constant(0u));
                        ir_expression *const r03F0 = expr(ir_unop_b2i, r03EF);
                        ir_expression *const r03F1 = expr(ir_unop_i2u, r03F0);
                        ir_expression *const r03F2 = expr(ir_triop_csel, r03EE, r03C6, r03F1);
                        body.emit(assign(r03DF, expr(ir_triop_csel, r03EC, r03ED, r03F2), 0x01));

                        ir_expression *const r03F3 = less(r03DE, body.constant(int(64)));
                        ir_expression *const r03F4 = bit_and(r03DE, body.constant(int(31)));
                        ir_expression *const r03F5 = rshift(r03C6, r03F4);
                        body.emit(assign(r03E0, expr(ir_triop_csel, r03F3, r03F5, body.constant(0u)), 0x01));


                     body.instructions = f03EA_parent_instructions;
                     body.emit(f03EA);

                     /* END IF */

                     body.emit(assign(r03E1, body.constant(0u), 0x01));


                  body.instructions = f03E6_parent_instructions;
                  body.emit(f03E6);

                  /* END IF */

                  ir_expression *const r03F6 = nequal(r03DD, body.constant(0u));
                  ir_expression *const r03F7 = expr(ir_unop_b2i, r03F6);
                  ir_expression *const r03F8 = expr(ir_unop_i2u, r03F7);
                  body.emit(assign(r03DF, bit_or(r03DF, r03F8), 0x01));


               body.instructions = f03E4_parent_instructions;
               body.emit(f03E4);

               /* END IF */

               body.emit(assign(r03C6, r03E1, 0x01));

               body.emit(assign(r03C7, r03E0, 0x01));

               body.emit(assign(r03C8, r03DF, 0x01));


            body.instructions = f03D5_parent_instructions;
            body.emit(f03D5);

            /* END IF */

            body.emit(assign(r03C5, sub(r03C5, r03C9), 0x01));

            ir_variable *const r03F9 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03F9, r03C5, 0x01));

            ir_variable *const r03FA = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03FA, r03C6, 0x01));

            ir_variable *const r03FB = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03FB, r03C7, 0x01));

            ir_variable *const r03FC = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r03FC, r03C8, 0x01));

            ir_variable *const r03FD = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r03FD, body.constant(true), 0x01));

            ir_variable *const r03FE = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r03FF = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r03FF);
            ir_expression *const r0400 = expr(ir_unop_u2i, r03C8);
            body.emit(assign(r03FF, less(r0400, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0402 = gequal(r03C5, body.constant(int(2045)));
            ir_if *f0401 = new(mem_ctx) ir_if(operand(r0402).val);
            exec_list *const f0401_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0401->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0404 = less(body.constant(int(2045)), r03C5);
               ir_expression *const r0405 = equal(r03C5, body.constant(int(2045)));
               ir_expression *const r0406 = equal(body.constant(2097151u), r03C6);
               ir_expression *const r0407 = equal(body.constant(4294967295u), r03C7);
               ir_expression *const r0408 = logic_and(r0406, r0407);
               ir_expression *const r0409 = logic_and(r0405, r0408);
               ir_expression *const r040A = logic_and(r0409, r03FF);
               ir_expression *const r040B = logic_or(r0404, r040A);
               ir_if *f0403 = new(mem_ctx) ir_if(operand(r040B).val);
               exec_list *const f0403_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0403->then_instructions;

                  ir_variable *const r040C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r040C);
                  ir_expression *const r040D = lshift(r01D0, body.constant(int(31)));
                  body.emit(assign(r040C, add(r040D, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r040C, body.constant(0u), 0x01));

                  body.emit(assign(r03FE, r040C, 0x03));

                  body.emit(assign(r03FD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0403->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r040F = less(r03C5, body.constant(int(0)));
                  ir_if *f040E = new(mem_ctx) ir_if(operand(r040F).val);
                  exec_list *const f040E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f040E->then_instructions;

                     ir_variable *const r0410 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0410, r03C8, 0x01));

                     ir_variable *const r0411 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0411, neg(r03C5), 0x01));

                     ir_variable *const r0412 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0412);
                     ir_variable *const r0413 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0413);
                     ir_variable *const r0414 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0414);
                     ir_variable *const r0415 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0416 = neg(r0411);
                     body.emit(assign(r0415, bit_and(r0416, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0418 = equal(r0411, body.constant(int(0)));
                     ir_if *f0417 = new(mem_ctx) ir_if(operand(r0418).val);
                     exec_list *const f0417_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0417->then_instructions;

                        body.emit(assign(r0412, r03C8, 0x01));

                        body.emit(assign(r0413, r03C7, 0x01));

                        body.emit(assign(r0414, r03C6, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0417->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r041A = less(r0411, body.constant(int(32)));
                        ir_if *f0419 = new(mem_ctx) ir_if(operand(r041A).val);
                        exec_list *const f0419_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0419->then_instructions;

                           body.emit(assign(r0412, lshift(r03C7, r0415), 0x01));

                           ir_expression *const r041B = lshift(r03C6, r0415);
                           ir_expression *const r041C = rshift(r03C7, r0411);
                           body.emit(assign(r0413, bit_or(r041B, r041C), 0x01));

                           body.emit(assign(r0414, rshift(r03C6, r0411), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0419->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r041E = equal(r0411, body.constant(int(32)));
                           ir_if *f041D = new(mem_ctx) ir_if(operand(r041E).val);
                           exec_list *const f041D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f041D->then_instructions;

                              body.emit(assign(r0412, r03C7, 0x01));

                              body.emit(assign(r0413, r03C6, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f041D->else_instructions;

                              body.emit(assign(r0410, bit_or(r03C8, r03C7), 0x01));

                              ir_expression *const r041F = less(r0411, body.constant(int(64)));
                              ir_expression *const r0420 = lshift(r03C6, r0415);
                              ir_expression *const r0421 = equal(r0411, body.constant(int(64)));
                              ir_expression *const r0422 = nequal(r03C6, body.constant(0u));
                              ir_expression *const r0423 = expr(ir_unop_b2i, r0422);
                              ir_expression *const r0424 = expr(ir_unop_i2u, r0423);
                              ir_expression *const r0425 = expr(ir_triop_csel, r0421, r03C6, r0424);
                              body.emit(assign(r0412, expr(ir_triop_csel, r041F, r0420, r0425), 0x01));

                              ir_expression *const r0426 = less(r0411, body.constant(int(64)));
                              ir_expression *const r0427 = bit_and(r0411, body.constant(int(31)));
                              ir_expression *const r0428 = rshift(r03C6, r0427);
                              body.emit(assign(r0413, expr(ir_triop_csel, r0426, r0428, body.constant(0u)), 0x01));


                           body.instructions = f041D_parent_instructions;
                           body.emit(f041D);

                           /* END IF */

                           body.emit(assign(r0414, body.constant(0u), 0x01));


                        body.instructions = f0419_parent_instructions;
                        body.emit(f0419);

                        /* END IF */

                        ir_expression *const r0429 = nequal(r0410, body.constant(0u));
                        ir_expression *const r042A = expr(ir_unop_b2i, r0429);
                        ir_expression *const r042B = expr(ir_unop_i2u, r042A);
                        body.emit(assign(r0412, bit_or(r0412, r042B), 0x01));


                     body.instructions = f0417_parent_instructions;
                     body.emit(f0417);

                     /* END IF */

                     body.emit(assign(r03FA, r0414, 0x01));

                     body.emit(assign(r03FB, r0413, 0x01));

                     body.emit(assign(r03FC, r0412, 0x01));

                     body.emit(assign(r03F9, body.constant(int(0)), 0x01));

                     body.emit(assign(r03FF, less(r0412, body.constant(0u)), 0x01));


                  body.instructions = f040E_parent_instructions;
                  body.emit(f040E);

                  /* END IF */


               body.instructions = f0403_parent_instructions;
               body.emit(f0403);

               /* END IF */


            body.instructions = f0401_parent_instructions;
            body.emit(f0401);

            /* END IF */

            /* IF CONDITION */
            ir_if *f042C = new(mem_ctx) ir_if(operand(r03FD).val);
            exec_list *const f042C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f042C->then_instructions;

               /* IF CONDITION */
               ir_if *f042D = new(mem_ctx) ir_if(operand(r03FF).val);
               exec_list *const f042D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f042D->then_instructions;

                  ir_variable *const r042E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r042E, add(r03FB, body.constant(1u)), 0x01));

                  ir_expression *const r042F = less(r042E, r03FB);
                  ir_expression *const r0430 = expr(ir_unop_b2i, r042F);
                  ir_expression *const r0431 = expr(ir_unop_i2u, r0430);
                  body.emit(assign(r03FA, add(r03FA, r0431), 0x01));

                  ir_expression *const r0432 = equal(r03FC, body.constant(0u));
                  ir_expression *const r0433 = expr(ir_unop_b2i, r0432);
                  ir_expression *const r0434 = expr(ir_unop_i2u, r0433);
                  ir_expression *const r0435 = add(r03FC, r0434);
                  ir_expression *const r0436 = bit_and(r0435, body.constant(1u));
                  ir_expression *const r0437 = expr(ir_unop_bit_not, r0436);
                  body.emit(assign(r03FB, bit_and(r042E, r0437), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f042D->else_instructions;

                  ir_expression *const r0438 = bit_or(r03FA, r03FB);
                  ir_expression *const r0439 = equal(r0438, body.constant(0u));
                  body.emit(assign(r03F9, expr(ir_triop_csel, r0439, body.constant(int(0)), r03F9), 0x01));


               body.instructions = f042D_parent_instructions;
               body.emit(f042D);

               /* END IF */

               ir_variable *const r043A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r043A);
               ir_expression *const r043B = lshift(r01D0, body.constant(int(31)));
               ir_expression *const r043C = expr(ir_unop_i2u, r03F9);
               ir_expression *const r043D = lshift(r043C, body.constant(int(20)));
               ir_expression *const r043E = add(r043B, r043D);
               body.emit(assign(r043A, add(r043E, r03FA), 0x02));

               body.emit(assign(r043A, r03FB, 0x01));

               body.emit(assign(r03FE, r043A, 0x03));

               body.emit(assign(r03FD, body.constant(false), 0x01));


            body.instructions = f042C_parent_instructions;
            body.emit(f042C);

            /* END IF */

            body.emit(assign(r01CE, r03FE, 0x03));

            body.emit(assign(r01CD, body.constant(false), 0x01));


         body.instructions = f0381_parent_instructions;
         body.emit(f0381);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f037F->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0440 = less(r0367, body.constant(int(0)));
         ir_if *f043F = new(mem_ctx) ir_if(operand(r0440).val);
         exec_list *const f043F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f043F->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0442 = equal(r0372, body.constant(int(2047)));
            ir_if *f0441 = new(mem_ctx) ir_if(operand(r0442).val);
            exec_list *const f0441_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0441->then_instructions;

               ir_variable *const r0443 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0443);
               ir_expression *const r0444 = bit_xor(r01D0, body.constant(1u));
               ir_expression *const r0445 = lshift(r0444, body.constant(int(31)));
               body.emit(assign(r0443, add(r0445, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0443, body.constant(0u), 0x01));

               ir_variable *const r0446 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0446, swizzle_x(r01CB), 0x01));

               ir_variable *const r0447 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0447, swizzle_x(r01CC), 0x01));

               body.emit(assign(r0446, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r0447, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r0448 = bit_or(r036A, r036B);
               ir_expression *const r0449 = nequal(r0448, body.constant(0u));
               ir_swizzle *const r044A = swizzle(r0449, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r044B = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r044C = gequal(r044B, body.constant(4292870144u));
               ir_expression *const r044D = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r044E = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r044F = nequal(r044E, body.constant(0u));
               ir_expression *const r0450 = logic_or(r044D, r044F);
               ir_expression *const r0451 = logic_and(r044C, r0450);
               ir_swizzle *const r0452 = swizzle(r0451, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0453 = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r0454 = gequal(r0453, body.constant(4292870144u));
               ir_expression *const r0455 = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r0456 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r0457 = nequal(r0456, body.constant(0u));
               ir_expression *const r0458 = logic_or(r0455, r0457);
               ir_expression *const r0459 = logic_and(r0454, r0458);
               ir_swizzle *const r045A = swizzle(r0459, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r045B = expr(ir_triop_csel, r045A, r0447, r0446);
               ir_expression *const r045C = expr(ir_triop_csel, r0452, r045B, r0447);
               body.emit(assign(r01CE, expr(ir_triop_csel, r044A, r045C, r0443), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0441->else_instructions;

               /* IF CONDITION */
               ir_expression *const r045E = equal(r036F, body.constant(int(0)));
               ir_if *f045D = new(mem_ctx) ir_if(operand(r045E).val);
               exec_list *const f045D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f045D->then_instructions;

                  body.emit(assign(r0367, add(r0367, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f045D->else_instructions;

                  body.emit(assign(r036C, bit_or(r036C, body.constant(1073741824u)), 0x01));


               body.instructions = f045D_parent_instructions;
               body.emit(f045D);

               /* END IF */

               ir_variable *const r045F = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r045F, neg(r0367), 0x01));

               ir_variable *const r0460 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0460);
               ir_variable *const r0461 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0462 = neg(r045F);
               body.emit(assign(r0461, bit_and(r0462, body.constant(int(31))), 0x01));

               ir_variable *const r0463 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0464 = less(r045F, body.constant(int(32)));
               ir_expression *const r0465 = rshift(r036C, r045F);
               ir_expression *const r0466 = equal(r045F, body.constant(int(0)));
               ir_expression *const r0467 = expr(ir_triop_csel, r0466, r036C, body.constant(0u));
               body.emit(assign(r0463, expr(ir_triop_csel, r0464, r0465, r0467), 0x01));

               /* IF CONDITION */
               ir_expression *const r0469 = equal(r045F, body.constant(int(0)));
               ir_if *f0468 = new(mem_ctx) ir_if(operand(r0469).val);
               exec_list *const f0468_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0468->then_instructions;

                  body.emit(assign(r0460, r0376, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0468->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r046B = less(r045F, body.constant(int(32)));
                  ir_if *f046A = new(mem_ctx) ir_if(operand(r046B).val);
                  exec_list *const f046A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f046A->then_instructions;

                     ir_expression *const r046C = lshift(r036C, r0461);
                     ir_expression *const r046D = rshift(r0376, r045F);
                     ir_expression *const r046E = bit_or(r046C, r046D);
                     ir_expression *const r046F = lshift(r0376, r0461);
                     ir_expression *const r0470 = nequal(r046F, body.constant(0u));
                     ir_expression *const r0471 = expr(ir_unop_b2i, r0470);
                     ir_expression *const r0472 = expr(ir_unop_i2u, r0471);
                     body.emit(assign(r0460, bit_or(r046E, r0472), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f046A->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0474 = equal(r045F, body.constant(int(32)));
                     ir_if *f0473 = new(mem_ctx) ir_if(operand(r0474).val);
                     exec_list *const f0473_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0473->then_instructions;

                        ir_expression *const r0475 = nequal(r0376, body.constant(0u));
                        ir_expression *const r0476 = expr(ir_unop_b2i, r0475);
                        ir_expression *const r0477 = expr(ir_unop_i2u, r0476);
                        body.emit(assign(r0460, bit_or(r036C, r0477), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0473->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0479 = less(r045F, body.constant(int(64)));
                        ir_if *f0478 = new(mem_ctx) ir_if(operand(r0479).val);
                        exec_list *const f0478_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0478->then_instructions;

                           ir_expression *const r047A = bit_and(r045F, body.constant(int(31)));
                           ir_expression *const r047B = rshift(r036C, r047A);
                           ir_expression *const r047C = lshift(r036C, r0461);
                           ir_expression *const r047D = bit_or(r047C, r0376);
                           ir_expression *const r047E = nequal(r047D, body.constant(0u));
                           ir_expression *const r047F = expr(ir_unop_b2i, r047E);
                           ir_expression *const r0480 = expr(ir_unop_i2u, r047F);
                           body.emit(assign(r0460, bit_or(r047B, r0480), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0478->else_instructions;

                           ir_expression *const r0481 = bit_or(r036C, r0376);
                           ir_expression *const r0482 = nequal(r0481, body.constant(0u));
                           ir_expression *const r0483 = expr(ir_unop_b2i, r0482);
                           body.emit(assign(r0460, expr(ir_unop_i2u, r0483), 0x01));


                        body.instructions = f0478_parent_instructions;
                        body.emit(f0478);

                        /* END IF */


                     body.instructions = f0473_parent_instructions;
                     body.emit(f0473);

                     /* END IF */


                  body.instructions = f046A_parent_instructions;
                  body.emit(f046A);

                  /* END IF */


               body.instructions = f0468_parent_instructions;
               body.emit(f0468);

               /* END IF */

               body.emit(assign(r036C, r0463, 0x01));

               body.emit(assign(r036D, r0460, 0x01));

               body.emit(assign(r036A, bit_or(r036A, body.constant(1073741824u)), 0x01));

               ir_variable *const r0484 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_expression *const r0485 = sub(r036A, r0463);
               ir_expression *const r0486 = less(r036B, r0460);
               ir_expression *const r0487 = expr(ir_unop_b2i, r0486);
               ir_expression *const r0488 = expr(ir_unop_i2u, r0487);
               body.emit(assign(r0484, sub(r0485, r0488), 0x01));

               body.emit(assign(r01CF, bit_xor(r01D0, body.constant(1u)), 0x01));

               body.emit(assign(r036E, add(r0372, body.constant(int(-1))), 0x01));

               ir_variable *const r0489 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0489, add(r036E, body.constant(int(-10))), 0x01));

               ir_variable *const r048A = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r048B = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r048C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r048C);
               ir_variable *const r048D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r048D);
               ir_expression *const r048E = equal(r0484, body.constant(0u));
               ir_expression *const r048F = add(r0489, body.constant(int(-32)));
               body.emit(assign(r0489, expr(ir_triop_csel, r048E, r048F, r0489), 0x01));

               ir_variable *const r0490 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0491 = equal(r0484, body.constant(0u));
               ir_expression *const r0492 = sub(r036B, r0460);
               body.emit(assign(r0490, expr(ir_triop_csel, r0491, body.constant(0u), r0492), 0x01));

               body.emit(assign(r048B, r0490, 0x01));

               ir_variable *const r0493 = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r0494 = equal(r0484, body.constant(0u));
               body.emit(assign(r0493, expr(ir_triop_csel, r0494, r0490, r0484), 0x01));

               body.emit(assign(r048A, r0493, 0x01));

               ir_expression *const r0495 = equal(r0493, body.constant(0u));
               ir_expression *const r0496 = expr(ir_unop_find_msb, r0493);
               ir_expression *const r0497 = sub(body.constant(int(31)), r0496);
               ir_expression *const r0498 = expr(ir_triop_csel, r0495, body.constant(int(32)), r0497);
               body.emit(assign(r048D, add(r0498, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r049A = gequal(r048D, body.constant(int(0)));
               ir_if *f0499 = new(mem_ctx) ir_if(operand(r049A).val);
               exec_list *const f0499_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0499->then_instructions;

                  body.emit(assign(r048C, body.constant(0u), 0x01));

                  ir_expression *const r049B = equal(r048D, body.constant(int(0)));
                  ir_expression *const r049C = lshift(r0493, r048D);
                  ir_expression *const r049D = neg(r048D);
                  ir_expression *const r049E = bit_and(r049D, body.constant(int(31)));
                  ir_expression *const r049F = rshift(r0490, r049E);
                  ir_expression *const r04A0 = bit_or(r049C, r049F);
                  body.emit(assign(r048A, expr(ir_triop_csel, r049B, r0493, r04A0), 0x01));

                  body.emit(assign(r048B, lshift(r0490, r048D), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0499->else_instructions;

                  ir_variable *const r04A1 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r04A1, body.constant(0u), 0x01));

                  ir_variable *const r04A2 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r04A2, neg(r048D), 0x01));

                  ir_variable *const r04A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04A3);
                  ir_variable *const r04A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r04A4);
                  ir_variable *const r04A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04A5);
                  ir_variable *const r04A6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04A7 = neg(r04A2);
                  body.emit(assign(r04A6, bit_and(r04A7, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04A9 = equal(r04A2, body.constant(int(0)));
                  ir_if *f04A8 = new(mem_ctx) ir_if(operand(r04A9).val);
                  exec_list *const f04A8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A8->then_instructions;

                     body.emit(assign(r04A3, r04A1, 0x01));

                     body.emit(assign(r04A4, r048B, 0x01));

                     body.emit(assign(r04A5, r048A, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04A8->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04AB = less(r04A2, body.constant(int(32)));
                     ir_if *f04AA = new(mem_ctx) ir_if(operand(r04AB).val);
                     exec_list *const f04AA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04AA->then_instructions;

                        body.emit(assign(r04A3, lshift(r048B, r04A6), 0x01));

                        ir_expression *const r04AC = lshift(r048A, r04A6);
                        ir_expression *const r04AD = rshift(r048B, r04A2);
                        body.emit(assign(r04A4, bit_or(r04AC, r04AD), 0x01));

                        body.emit(assign(r04A5, rshift(r048A, r04A2), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04AA->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04AF = equal(r04A2, body.constant(int(32)));
                        ir_if *f04AE = new(mem_ctx) ir_if(operand(r04AF).val);
                        exec_list *const f04AE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04AE->then_instructions;

                           body.emit(assign(r04A3, r048B, 0x01));

                           body.emit(assign(r04A4, r048A, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04AE->else_instructions;

                           body.emit(assign(r04A1, bit_or(body.constant(0u), r048B), 0x01));

                           ir_expression *const r04B0 = less(r04A2, body.constant(int(64)));
                           ir_expression *const r04B1 = lshift(r048A, r04A6);
                           ir_expression *const r04B2 = equal(r04A2, body.constant(int(64)));
                           ir_expression *const r04B3 = nequal(r048A, body.constant(0u));
                           ir_expression *const r04B4 = expr(ir_unop_b2i, r04B3);
                           ir_expression *const r04B5 = expr(ir_unop_i2u, r04B4);
                           ir_expression *const r04B6 = expr(ir_triop_csel, r04B2, r048A, r04B5);
                           body.emit(assign(r04A3, expr(ir_triop_csel, r04B0, r04B1, r04B6), 0x01));

                           ir_expression *const r04B7 = less(r04A2, body.constant(int(64)));
                           ir_expression *const r04B8 = bit_and(r04A2, body.constant(int(31)));
                           ir_expression *const r04B9 = rshift(r048A, r04B8);
                           body.emit(assign(r04A4, expr(ir_triop_csel, r04B7, r04B9, body.constant(0u)), 0x01));


                        body.instructions = f04AE_parent_instructions;
                        body.emit(f04AE);

                        /* END IF */

                        body.emit(assign(r04A5, body.constant(0u), 0x01));


                     body.instructions = f04AA_parent_instructions;
                     body.emit(f04AA);

                     /* END IF */

                     ir_expression *const r04BA = nequal(r04A1, body.constant(0u));
                     ir_expression *const r04BB = expr(ir_unop_b2i, r04BA);
                     ir_expression *const r04BC = expr(ir_unop_i2u, r04BB);
                     body.emit(assign(r04A3, bit_or(r04A3, r04BC), 0x01));


                  body.instructions = f04A8_parent_instructions;
                  body.emit(f04A8);

                  /* END IF */

                  body.emit(assign(r048A, r04A5, 0x01));

                  body.emit(assign(r048B, r04A4, 0x01));

                  body.emit(assign(r048C, r04A3, 0x01));


               body.instructions = f0499_parent_instructions;
               body.emit(f0499);

               /* END IF */

               body.emit(assign(r0489, sub(r0489, r048D), 0x01));

               ir_variable *const r04BD = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04BD, r0489, 0x01));

               ir_variable *const r04BE = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04BE, r048A, 0x01));

               ir_variable *const r04BF = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04BF, r048B, 0x01));

               ir_variable *const r04C0 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r04C0, r048C, 0x01));

               ir_variable *const r04C1 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r04C1, body.constant(true), 0x01));

               ir_variable *const r04C2 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04C3 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r04C3);
               ir_expression *const r04C4 = expr(ir_unop_u2i, r048C);
               body.emit(assign(r04C3, less(r04C4, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04C6 = gequal(r0489, body.constant(int(2045)));
               ir_if *f04C5 = new(mem_ctx) ir_if(operand(r04C6).val);
               exec_list *const f04C5_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04C5->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04C8 = less(body.constant(int(2045)), r0489);
                  ir_expression *const r04C9 = equal(r0489, body.constant(int(2045)));
                  ir_expression *const r04CA = equal(body.constant(2097151u), r048A);
                  ir_expression *const r04CB = equal(body.constant(4294967295u), r048B);
                  ir_expression *const r04CC = logic_and(r04CA, r04CB);
                  ir_expression *const r04CD = logic_and(r04C9, r04CC);
                  ir_expression *const r04CE = logic_and(r04CD, r04C3);
                  ir_expression *const r04CF = logic_or(r04C8, r04CE);
                  ir_if *f04C7 = new(mem_ctx) ir_if(operand(r04CF).val);
                  exec_list *const f04C7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C7->then_instructions;

                     ir_variable *const r04D0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r04D0);
                     ir_expression *const r04D1 = lshift(r01CF, body.constant(int(31)));
                     body.emit(assign(r04D0, add(r04D1, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r04D0, body.constant(0u), 0x01));

                     body.emit(assign(r04C2, r04D0, 0x03));

                     body.emit(assign(r04C1, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04C7->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04D3 = less(r0489, body.constant(int(0)));
                     ir_if *f04D2 = new(mem_ctx) ir_if(operand(r04D3).val);
                     exec_list *const f04D2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04D2->then_instructions;

                        ir_variable *const r04D4 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r04D4, r048C, 0x01));

                        ir_variable *const r04D5 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r04D5, neg(r0489), 0x01));

                        ir_variable *const r04D6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r04D6);
                        ir_variable *const r04D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r04D7);
                        ir_variable *const r04D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r04D8);
                        ir_variable *const r04D9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r04DA = neg(r04D5);
                        body.emit(assign(r04D9, bit_and(r04DA, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r04DC = equal(r04D5, body.constant(int(0)));
                        ir_if *f04DB = new(mem_ctx) ir_if(operand(r04DC).val);
                        exec_list *const f04DB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04DB->then_instructions;

                           body.emit(assign(r04D6, r048C, 0x01));

                           body.emit(assign(r04D7, r048B, 0x01));

                           body.emit(assign(r04D8, r048A, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04DB->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r04DE = less(r04D5, body.constant(int(32)));
                           ir_if *f04DD = new(mem_ctx) ir_if(operand(r04DE).val);
                           exec_list *const f04DD_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04DD->then_instructions;

                              body.emit(assign(r04D6, lshift(r048B, r04D9), 0x01));

                              ir_expression *const r04DF = lshift(r048A, r04D9);
                              ir_expression *const r04E0 = rshift(r048B, r04D5);
                              body.emit(assign(r04D7, bit_or(r04DF, r04E0), 0x01));

                              body.emit(assign(r04D8, rshift(r048A, r04D5), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04DD->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r04E2 = equal(r04D5, body.constant(int(32)));
                              ir_if *f04E1 = new(mem_ctx) ir_if(operand(r04E2).val);
                              exec_list *const f04E1_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04E1->then_instructions;

                                 body.emit(assign(r04D6, r048B, 0x01));

                                 body.emit(assign(r04D7, r048A, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04E1->else_instructions;

                                 body.emit(assign(r04D4, bit_or(r048C, r048B), 0x01));

                                 ir_expression *const r04E3 = less(r04D5, body.constant(int(64)));
                                 ir_expression *const r04E4 = lshift(r048A, r04D9);
                                 ir_expression *const r04E5 = equal(r04D5, body.constant(int(64)));
                                 ir_expression *const r04E6 = nequal(r048A, body.constant(0u));
                                 ir_expression *const r04E7 = expr(ir_unop_b2i, r04E6);
                                 ir_expression *const r04E8 = expr(ir_unop_i2u, r04E7);
                                 ir_expression *const r04E9 = expr(ir_triop_csel, r04E5, r048A, r04E8);
                                 body.emit(assign(r04D6, expr(ir_triop_csel, r04E3, r04E4, r04E9), 0x01));

                                 ir_expression *const r04EA = less(r04D5, body.constant(int(64)));
                                 ir_expression *const r04EB = bit_and(r04D5, body.constant(int(31)));
                                 ir_expression *const r04EC = rshift(r048A, r04EB);
                                 body.emit(assign(r04D7, expr(ir_triop_csel, r04EA, r04EC, body.constant(0u)), 0x01));


                              body.instructions = f04E1_parent_instructions;
                              body.emit(f04E1);

                              /* END IF */

                              body.emit(assign(r04D8, body.constant(0u), 0x01));


                           body.instructions = f04DD_parent_instructions;
                           body.emit(f04DD);

                           /* END IF */

                           ir_expression *const r04ED = nequal(r04D4, body.constant(0u));
                           ir_expression *const r04EE = expr(ir_unop_b2i, r04ED);
                           ir_expression *const r04EF = expr(ir_unop_i2u, r04EE);
                           body.emit(assign(r04D6, bit_or(r04D6, r04EF), 0x01));


                        body.instructions = f04DB_parent_instructions;
                        body.emit(f04DB);

                        /* END IF */

                        body.emit(assign(r04BE, r04D8, 0x01));

                        body.emit(assign(r04BF, r04D7, 0x01));

                        body.emit(assign(r04C0, r04D6, 0x01));

                        body.emit(assign(r04BD, body.constant(int(0)), 0x01));

                        body.emit(assign(r04C3, less(r04D6, body.constant(0u)), 0x01));


                     body.instructions = f04D2_parent_instructions;
                     body.emit(f04D2);

                     /* END IF */


                  body.instructions = f04C7_parent_instructions;
                  body.emit(f04C7);

                  /* END IF */


               body.instructions = f04C5_parent_instructions;
               body.emit(f04C5);

               /* END IF */

               /* IF CONDITION */
               ir_if *f04F0 = new(mem_ctx) ir_if(operand(r04C1).val);
               exec_list *const f04F0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04F0->then_instructions;

                  /* IF CONDITION */
                  ir_if *f04F1 = new(mem_ctx) ir_if(operand(r04C3).val);
                  exec_list *const f04F1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04F1->then_instructions;

                     ir_variable *const r04F2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r04F2, add(r04BF, body.constant(1u)), 0x01));

                     ir_expression *const r04F3 = less(r04F2, r04BF);
                     ir_expression *const r04F4 = expr(ir_unop_b2i, r04F3);
                     ir_expression *const r04F5 = expr(ir_unop_i2u, r04F4);
                     body.emit(assign(r04BE, add(r04BE, r04F5), 0x01));

                     ir_expression *const r04F6 = equal(r04C0, body.constant(0u));
                     ir_expression *const r04F7 = expr(ir_unop_b2i, r04F6);
                     ir_expression *const r04F8 = expr(ir_unop_i2u, r04F7);
                     ir_expression *const r04F9 = add(r04C0, r04F8);
                     ir_expression *const r04FA = bit_and(r04F9, body.constant(1u));
                     ir_expression *const r04FB = expr(ir_unop_bit_not, r04FA);
                     body.emit(assign(r04BF, bit_and(r04F2, r04FB), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04F1->else_instructions;

                     ir_expression *const r04FC = bit_or(r04BE, r04BF);
                     ir_expression *const r04FD = equal(r04FC, body.constant(0u));
                     body.emit(assign(r04BD, expr(ir_triop_csel, r04FD, body.constant(int(0)), r04BD), 0x01));


                  body.instructions = f04F1_parent_instructions;
                  body.emit(f04F1);

                  /* END IF */

                  ir_variable *const r04FE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r04FE);
                  ir_expression *const r04FF = lshift(r01CF, body.constant(int(31)));
                  ir_expression *const r0500 = expr(ir_unop_i2u, r04BD);
                  ir_expression *const r0501 = lshift(r0500, body.constant(int(20)));
                  ir_expression *const r0502 = add(r04FF, r0501);
                  body.emit(assign(r04FE, add(r0502, r04BE), 0x02));

                  body.emit(assign(r04FE, r04BF, 0x01));

                  body.emit(assign(r04C2, r04FE, 0x03));

                  body.emit(assign(r04C1, body.constant(false), 0x01));


               body.instructions = f04F0_parent_instructions;
               body.emit(f04F0);

               /* END IF */

               body.emit(assign(r01CE, r04C2, 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


            body.instructions = f0441_parent_instructions;
            body.emit(f0441);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f043F->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0504 = equal(r036F, body.constant(int(2047)));
            ir_if *f0503 = new(mem_ctx) ir_if(operand(r0504).val);
            exec_list *const f0503_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0503->then_instructions;

               ir_variable *const r0505 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0505, swizzle_x(r01CB), 0x01));

               ir_variable *const r0506 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0506, swizzle_x(r01CC), 0x01));

               body.emit(assign(r0505, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

               body.emit(assign(r0506, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

               ir_expression *const r0507 = bit_or(r036C, r036D);
               ir_expression *const r0508 = bit_or(r036A, r036B);
               ir_expression *const r0509 = bit_or(r0507, r0508);
               ir_expression *const r050A = nequal(r0509, body.constant(0u));
               ir_swizzle *const r050B = swizzle(r050A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r050C = lshift(swizzle_y(r01CB), body.constant(int(1)));
               ir_expression *const r050D = gequal(r050C, body.constant(4292870144u));
               ir_expression *const r050E = nequal(swizzle_x(r01CB), body.constant(0u));
               ir_expression *const r050F = bit_and(swizzle_y(r01CB), body.constant(1048575u));
               ir_expression *const r0510 = nequal(r050F, body.constant(0u));
               ir_expression *const r0511 = logic_or(r050E, r0510);
               ir_expression *const r0512 = logic_and(r050D, r0511);
               ir_swizzle *const r0513 = swizzle(r0512, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0514 = lshift(swizzle_y(r01CC), body.constant(int(1)));
               ir_expression *const r0515 = gequal(r0514, body.constant(4292870144u));
               ir_expression *const r0516 = nequal(swizzle_x(r01CC), body.constant(0u));
               ir_expression *const r0517 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
               ir_expression *const r0518 = nequal(r0517, body.constant(0u));
               ir_expression *const r0519 = logic_or(r0516, r0518);
               ir_expression *const r051A = logic_and(r0515, r0519);
               ir_swizzle *const r051B = swizzle(r051A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r051C = expr(ir_triop_csel, r051B, r0506, r0505);
               ir_expression *const r051D = expr(ir_triop_csel, r0513, r051C, r0506);
               ir_constant_data r051E_data;
               memset(&r051E_data, 0, sizeof(ir_constant_data));
               r051E_data.u[0] = 4294967295;
               r051E_data.u[1] = 4294967295;
               ir_constant *const r051E = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r051E_data);
               body.emit(assign(r01CE, expr(ir_triop_csel, r050B, r051D, r051E), 0x03));

               body.emit(assign(r01CD, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0503->else_instructions;

               ir_expression *const r051F = equal(r036F, body.constant(int(0)));
               body.emit(assign(r0368, expr(ir_triop_csel, r051F, body.constant(int(1)), r0372), 0x01));

               ir_expression *const r0520 = equal(r036F, body.constant(int(0)));
               body.emit(assign(r0369, expr(ir_triop_csel, r0520, body.constant(int(1)), r036F), 0x01));

               /* IF CONDITION */
               ir_expression *const r0522 = less(r036A, r036C);
               ir_if *f0521 = new(mem_ctx) ir_if(operand(r0522).val);
               exec_list *const f0521_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0521->then_instructions;

                  ir_variable *const r0523 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_expression *const r0524 = sub(r036C, r036A);
                  ir_expression *const r0525 = less(r036D, r036B);
                  ir_expression *const r0526 = expr(ir_unop_b2i, r0525);
                  ir_expression *const r0527 = expr(ir_unop_i2u, r0526);
                  body.emit(assign(r0523, sub(r0524, r0527), 0x01));

                  body.emit(assign(r036E, add(r0369, body.constant(int(-1))), 0x01));

                  ir_variable *const r0528 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0528, add(r036E, body.constant(int(-10))), 0x01));

                  ir_variable *const r0529 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  ir_variable *const r052A = body.make_temp(glsl_type::uint_type, "zFrac1");
                  ir_variable *const r052B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r052B);
                  ir_variable *const r052C = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r052C);
                  ir_expression *const r052D = equal(r0523, body.constant(0u));
                  ir_expression *const r052E = add(r0528, body.constant(int(-32)));
                  body.emit(assign(r0528, expr(ir_triop_csel, r052D, r052E, r0528), 0x01));

                  ir_variable *const r052F = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0530 = equal(r0523, body.constant(0u));
                  ir_expression *const r0531 = sub(r036D, r036B);
                  body.emit(assign(r052F, expr(ir_triop_csel, r0530, body.constant(0u), r0531), 0x01));

                  body.emit(assign(r052A, r052F, 0x01));

                  ir_variable *const r0532 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0533 = equal(r0523, body.constant(0u));
                  body.emit(assign(r0532, expr(ir_triop_csel, r0533, r052F, r0523), 0x01));

                  body.emit(assign(r0529, r0532, 0x01));

                  ir_expression *const r0534 = equal(r0532, body.constant(0u));
                  ir_expression *const r0535 = expr(ir_unop_find_msb, r0532);
                  ir_expression *const r0536 = sub(body.constant(int(31)), r0535);
                  ir_expression *const r0537 = expr(ir_triop_csel, r0534, body.constant(int(32)), r0536);
                  body.emit(assign(r052C, add(r0537, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0539 = gequal(r052C, body.constant(int(0)));
                  ir_if *f0538 = new(mem_ctx) ir_if(operand(r0539).val);
                  exec_list *const f0538_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0538->then_instructions;

                     body.emit(assign(r052B, body.constant(0u), 0x01));

                     ir_expression *const r053A = equal(r052C, body.constant(int(0)));
                     ir_expression *const r053B = lshift(r0532, r052C);
                     ir_expression *const r053C = neg(r052C);
                     ir_expression *const r053D = bit_and(r053C, body.constant(int(31)));
                     ir_expression *const r053E = rshift(r052F, r053D);
                     ir_expression *const r053F = bit_or(r053B, r053E);
                     body.emit(assign(r0529, expr(ir_triop_csel, r053A, r0532, r053F), 0x01));

                     body.emit(assign(r052A, lshift(r052F, r052C), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0538->else_instructions;

                     ir_variable *const r0540 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0540, body.constant(0u), 0x01));

                     ir_variable *const r0541 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0541, neg(r052C), 0x01));

                     ir_variable *const r0542 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0542);
                     ir_variable *const r0543 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0543);
                     ir_variable *const r0544 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0544);
                     ir_variable *const r0545 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0546 = neg(r0541);
                     body.emit(assign(r0545, bit_and(r0546, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0548 = equal(r0541, body.constant(int(0)));
                     ir_if *f0547 = new(mem_ctx) ir_if(operand(r0548).val);
                     exec_list *const f0547_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0547->then_instructions;

                        body.emit(assign(r0542, r0540, 0x01));

                        body.emit(assign(r0543, r052A, 0x01));

                        body.emit(assign(r0544, r0529, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0547->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r054A = less(r0541, body.constant(int(32)));
                        ir_if *f0549 = new(mem_ctx) ir_if(operand(r054A).val);
                        exec_list *const f0549_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0549->then_instructions;

                           body.emit(assign(r0542, lshift(r052A, r0545), 0x01));

                           ir_expression *const r054B = lshift(r0529, r0545);
                           ir_expression *const r054C = rshift(r052A, r0541);
                           body.emit(assign(r0543, bit_or(r054B, r054C), 0x01));

                           body.emit(assign(r0544, rshift(r0529, r0541), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0549->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r054E = equal(r0541, body.constant(int(32)));
                           ir_if *f054D = new(mem_ctx) ir_if(operand(r054E).val);
                           exec_list *const f054D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f054D->then_instructions;

                              body.emit(assign(r0542, r052A, 0x01));

                              body.emit(assign(r0543, r0529, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f054D->else_instructions;

                              body.emit(assign(r0540, bit_or(body.constant(0u), r052A), 0x01));

                              ir_expression *const r054F = less(r0541, body.constant(int(64)));
                              ir_expression *const r0550 = lshift(r0529, r0545);
                              ir_expression *const r0551 = equal(r0541, body.constant(int(64)));
                              ir_expression *const r0552 = nequal(r0529, body.constant(0u));
                              ir_expression *const r0553 = expr(ir_unop_b2i, r0552);
                              ir_expression *const r0554 = expr(ir_unop_i2u, r0553);
                              ir_expression *const r0555 = expr(ir_triop_csel, r0551, r0529, r0554);
                              body.emit(assign(r0542, expr(ir_triop_csel, r054F, r0550, r0555), 0x01));

                              ir_expression *const r0556 = less(r0541, body.constant(int(64)));
                              ir_expression *const r0557 = bit_and(r0541, body.constant(int(31)));
                              ir_expression *const r0558 = rshift(r0529, r0557);
                              body.emit(assign(r0543, expr(ir_triop_csel, r0556, r0558, body.constant(0u)), 0x01));


                           body.instructions = f054D_parent_instructions;
                           body.emit(f054D);

                           /* END IF */

                           body.emit(assign(r0544, body.constant(0u), 0x01));


                        body.instructions = f0549_parent_instructions;
                        body.emit(f0549);

                        /* END IF */

                        ir_expression *const r0559 = nequal(r0540, body.constant(0u));
                        ir_expression *const r055A = expr(ir_unop_b2i, r0559);
                        ir_expression *const r055B = expr(ir_unop_i2u, r055A);
                        body.emit(assign(r0542, bit_or(r0542, r055B), 0x01));


                     body.instructions = f0547_parent_instructions;
                     body.emit(f0547);

                     /* END IF */

                     body.emit(assign(r0529, r0544, 0x01));

                     body.emit(assign(r052A, r0543, 0x01));

                     body.emit(assign(r052B, r0542, 0x01));


                  body.instructions = f0538_parent_instructions;
                  body.emit(f0538);

                  /* END IF */

                  body.emit(assign(r0528, sub(r0528, r052C), 0x01));

                  ir_variable *const r055C = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r055C, r0528, 0x01));

                  ir_variable *const r055D = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r055D, r0529, 0x01));

                  ir_variable *const r055E = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r055E, r052A, 0x01));

                  ir_variable *const r055F = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r055F, r052B, 0x01));

                  ir_variable *const r0560 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0560, body.constant(true), 0x01));

                  ir_variable *const r0561 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0562 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r0562);
                  ir_expression *const r0563 = expr(ir_unop_u2i, r052B);
                  body.emit(assign(r0562, less(r0563, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0565 = gequal(r0528, body.constant(int(2045)));
                  ir_if *f0564 = new(mem_ctx) ir_if(operand(r0565).val);
                  exec_list *const f0564_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0564->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0567 = less(body.constant(int(2045)), r0528);
                     ir_expression *const r0568 = equal(r0528, body.constant(int(2045)));
                     ir_expression *const r0569 = equal(body.constant(2097151u), r0529);
                     ir_expression *const r056A = equal(body.constant(4294967295u), r052A);
                     ir_expression *const r056B = logic_and(r0569, r056A);
                     ir_expression *const r056C = logic_and(r0568, r056B);
                     ir_expression *const r056D = logic_and(r056C, r0562);
                     ir_expression *const r056E = logic_or(r0567, r056D);
                     ir_if *f0566 = new(mem_ctx) ir_if(operand(r056E).val);
                     exec_list *const f0566_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0566->then_instructions;

                        ir_variable *const r056F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r056F);
                        ir_expression *const r0570 = lshift(r01CF, body.constant(int(31)));
                        body.emit(assign(r056F, add(r0570, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r056F, body.constant(0u), 0x01));

                        body.emit(assign(r0561, r056F, 0x03));

                        body.emit(assign(r0560, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0566->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0572 = less(r0528, body.constant(int(0)));
                        ir_if *f0571 = new(mem_ctx) ir_if(operand(r0572).val);
                        exec_list *const f0571_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0571->then_instructions;

                           ir_variable *const r0573 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0573, r052B, 0x01));

                           ir_variable *const r0574 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0574, neg(r0528), 0x01));

                           ir_variable *const r0575 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0575);
                           ir_variable *const r0576 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0576);
                           ir_variable *const r0577 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0577);
                           ir_variable *const r0578 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0579 = neg(r0574);
                           body.emit(assign(r0578, bit_and(r0579, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r057B = equal(r0574, body.constant(int(0)));
                           ir_if *f057A = new(mem_ctx) ir_if(operand(r057B).val);
                           exec_list *const f057A_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f057A->then_instructions;

                              body.emit(assign(r0575, r052B, 0x01));

                              body.emit(assign(r0576, r052A, 0x01));

                              body.emit(assign(r0577, r0529, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f057A->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r057D = less(r0574, body.constant(int(32)));
                              ir_if *f057C = new(mem_ctx) ir_if(operand(r057D).val);
                              exec_list *const f057C_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f057C->then_instructions;

                                 body.emit(assign(r0575, lshift(r052A, r0578), 0x01));

                                 ir_expression *const r057E = lshift(r0529, r0578);
                                 ir_expression *const r057F = rshift(r052A, r0574);
                                 body.emit(assign(r0576, bit_or(r057E, r057F), 0x01));

                                 body.emit(assign(r0577, rshift(r0529, r0574), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f057C->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0581 = equal(r0574, body.constant(int(32)));
                                 ir_if *f0580 = new(mem_ctx) ir_if(operand(r0581).val);
                                 exec_list *const f0580_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0580->then_instructions;

                                    body.emit(assign(r0575, r052A, 0x01));

                                    body.emit(assign(r0576, r0529, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0580->else_instructions;

                                    body.emit(assign(r0573, bit_or(r052B, r052A), 0x01));

                                    ir_expression *const r0582 = less(r0574, body.constant(int(64)));
                                    ir_expression *const r0583 = lshift(r0529, r0578);
                                    ir_expression *const r0584 = equal(r0574, body.constant(int(64)));
                                    ir_expression *const r0585 = nequal(r0529, body.constant(0u));
                                    ir_expression *const r0586 = expr(ir_unop_b2i, r0585);
                                    ir_expression *const r0587 = expr(ir_unop_i2u, r0586);
                                    ir_expression *const r0588 = expr(ir_triop_csel, r0584, r0529, r0587);
                                    body.emit(assign(r0575, expr(ir_triop_csel, r0582, r0583, r0588), 0x01));

                                    ir_expression *const r0589 = less(r0574, body.constant(int(64)));
                                    ir_expression *const r058A = bit_and(r0574, body.constant(int(31)));
                                    ir_expression *const r058B = rshift(r0529, r058A);
                                    body.emit(assign(r0576, expr(ir_triop_csel, r0589, r058B, body.constant(0u)), 0x01));


                                 body.instructions = f0580_parent_instructions;
                                 body.emit(f0580);

                                 /* END IF */

                                 body.emit(assign(r0577, body.constant(0u), 0x01));


                              body.instructions = f057C_parent_instructions;
                              body.emit(f057C);

                              /* END IF */

                              ir_expression *const r058C = nequal(r0573, body.constant(0u));
                              ir_expression *const r058D = expr(ir_unop_b2i, r058C);
                              ir_expression *const r058E = expr(ir_unop_i2u, r058D);
                              body.emit(assign(r0575, bit_or(r0575, r058E), 0x01));


                           body.instructions = f057A_parent_instructions;
                           body.emit(f057A);

                           /* END IF */

                           body.emit(assign(r055D, r0577, 0x01));

                           body.emit(assign(r055E, r0576, 0x01));

                           body.emit(assign(r055F, r0575, 0x01));

                           body.emit(assign(r055C, body.constant(int(0)), 0x01));

                           body.emit(assign(r0562, less(r0575, body.constant(0u)), 0x01));


                        body.instructions = f0571_parent_instructions;
                        body.emit(f0571);

                        /* END IF */


                     body.instructions = f0566_parent_instructions;
                     body.emit(f0566);

                     /* END IF */


                  body.instructions = f0564_parent_instructions;
                  body.emit(f0564);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f058F = new(mem_ctx) ir_if(operand(r0560).val);
                  exec_list *const f058F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f058F->then_instructions;

                     /* IF CONDITION */
                     ir_if *f0590 = new(mem_ctx) ir_if(operand(r0562).val);
                     exec_list *const f0590_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0590->then_instructions;

                        ir_variable *const r0591 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r0591, add(r055E, body.constant(1u)), 0x01));

                        ir_expression *const r0592 = less(r0591, r055E);
                        ir_expression *const r0593 = expr(ir_unop_b2i, r0592);
                        ir_expression *const r0594 = expr(ir_unop_i2u, r0593);
                        body.emit(assign(r055D, add(r055D, r0594), 0x01));

                        ir_expression *const r0595 = equal(r055F, body.constant(0u));
                        ir_expression *const r0596 = expr(ir_unop_b2i, r0595);
                        ir_expression *const r0597 = expr(ir_unop_i2u, r0596);
                        ir_expression *const r0598 = add(r055F, r0597);
                        ir_expression *const r0599 = bit_and(r0598, body.constant(1u));
                        ir_expression *const r059A = expr(ir_unop_bit_not, r0599);
                        body.emit(assign(r055E, bit_and(r0591, r059A), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0590->else_instructions;

                        ir_expression *const r059B = bit_or(r055D, r055E);
                        ir_expression *const r059C = equal(r059B, body.constant(0u));
                        body.emit(assign(r055C, expr(ir_triop_csel, r059C, body.constant(int(0)), r055C), 0x01));


                     body.instructions = f0590_parent_instructions;
                     body.emit(f0590);

                     /* END IF */

                     ir_variable *const r059D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r059D);
                     ir_expression *const r059E = lshift(r01CF, body.constant(int(31)));
                     ir_expression *const r059F = expr(ir_unop_i2u, r055C);
                     ir_expression *const r05A0 = lshift(r059F, body.constant(int(20)));
                     ir_expression *const r05A1 = add(r059E, r05A0);
                     body.emit(assign(r059D, add(r05A1, r055D), 0x02));

                     body.emit(assign(r059D, r055E, 0x01));

                     body.emit(assign(r0561, r059D, 0x03));

                     body.emit(assign(r0560, body.constant(false), 0x01));


                  body.instructions = f058F_parent_instructions;
                  body.emit(f058F);

                  /* END IF */

                  body.emit(assign(r01CE, r0561, 0x03));

                  body.emit(assign(r01CD, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0521->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05A3 = less(r036C, r036A);
                  ir_if *f05A2 = new(mem_ctx) ir_if(operand(r05A3).val);
                  exec_list *const f05A2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05A2->then_instructions;

                     ir_variable *const r05A4 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_expression *const r05A5 = sub(r036A, r036C);
                     ir_expression *const r05A6 = less(r036B, r036D);
                     ir_expression *const r05A7 = expr(ir_unop_b2i, r05A6);
                     ir_expression *const r05A8 = expr(ir_unop_i2u, r05A7);
                     body.emit(assign(r05A4, sub(r05A5, r05A8), 0x01));

                     body.emit(assign(r01CF, bit_xor(r01CF, body.constant(1u)), 0x01));

                     body.emit(assign(r036E, add(r0368, body.constant(int(-1))), 0x01));

                     ir_variable *const r05A9 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05A9, add(r036E, body.constant(int(-10))), 0x01));

                     ir_variable *const r05AA = body.make_temp(glsl_type::uint_type, "zFrac0");
                     ir_variable *const r05AB = body.make_temp(glsl_type::uint_type, "zFrac1");
                     ir_variable *const r05AC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r05AC);
                     ir_variable *const r05AD = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05AD);
                     ir_expression *const r05AE = equal(r05A4, body.constant(0u));
                     ir_expression *const r05AF = add(r05A9, body.constant(int(-32)));
                     body.emit(assign(r05A9, expr(ir_triop_csel, r05AE, r05AF, r05A9), 0x01));

                     ir_variable *const r05B0 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05B1 = equal(r05A4, body.constant(0u));
                     ir_expression *const r05B2 = sub(r036B, r036D);
                     body.emit(assign(r05B0, expr(ir_triop_csel, r05B1, body.constant(0u), r05B2), 0x01));

                     body.emit(assign(r05AB, r05B0, 0x01));

                     ir_variable *const r05B3 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05B4 = equal(r05A4, body.constant(0u));
                     body.emit(assign(r05B3, expr(ir_triop_csel, r05B4, r05B0, r05A4), 0x01));

                     body.emit(assign(r05AA, r05B3, 0x01));

                     ir_expression *const r05B5 = equal(r05B3, body.constant(0u));
                     ir_expression *const r05B6 = expr(ir_unop_find_msb, r05B3);
                     ir_expression *const r05B7 = sub(body.constant(int(31)), r05B6);
                     ir_expression *const r05B8 = expr(ir_triop_csel, r05B5, body.constant(int(32)), r05B7);
                     body.emit(assign(r05AD, add(r05B8, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05BA = gequal(r05AD, body.constant(int(0)));
                     ir_if *f05B9 = new(mem_ctx) ir_if(operand(r05BA).val);
                     exec_list *const f05B9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05B9->then_instructions;

                        body.emit(assign(r05AC, body.constant(0u), 0x01));

                        ir_expression *const r05BB = equal(r05AD, body.constant(int(0)));
                        ir_expression *const r05BC = lshift(r05B3, r05AD);
                        ir_expression *const r05BD = neg(r05AD);
                        ir_expression *const r05BE = bit_and(r05BD, body.constant(int(31)));
                        ir_expression *const r05BF = rshift(r05B0, r05BE);
                        ir_expression *const r05C0 = bit_or(r05BC, r05BF);
                        body.emit(assign(r05AA, expr(ir_triop_csel, r05BB, r05B3, r05C0), 0x01));

                        body.emit(assign(r05AB, lshift(r05B0, r05AD), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05B9->else_instructions;

                        ir_variable *const r05C1 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r05C1, body.constant(0u), 0x01));

                        ir_variable *const r05C2 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r05C2, neg(r05AD), 0x01));

                        ir_variable *const r05C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r05C3);
                        ir_variable *const r05C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r05C4);
                        ir_variable *const r05C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r05C5);
                        ir_variable *const r05C6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r05C7 = neg(r05C2);
                        body.emit(assign(r05C6, bit_and(r05C7, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05C9 = equal(r05C2, body.constant(int(0)));
                        ir_if *f05C8 = new(mem_ctx) ir_if(operand(r05C9).val);
                        exec_list *const f05C8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05C8->then_instructions;

                           body.emit(assign(r05C3, r05C1, 0x01));

                           body.emit(assign(r05C4, r05AB, 0x01));

                           body.emit(assign(r05C5, r05AA, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05C8->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05CB = less(r05C2, body.constant(int(32)));
                           ir_if *f05CA = new(mem_ctx) ir_if(operand(r05CB).val);
                           exec_list *const f05CA_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05CA->then_instructions;

                              body.emit(assign(r05C3, lshift(r05AB, r05C6), 0x01));

                              ir_expression *const r05CC = lshift(r05AA, r05C6);
                              ir_expression *const r05CD = rshift(r05AB, r05C2);
                              body.emit(assign(r05C4, bit_or(r05CC, r05CD), 0x01));

                              body.emit(assign(r05C5, rshift(r05AA, r05C2), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05CA->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05CF = equal(r05C2, body.constant(int(32)));
                              ir_if *f05CE = new(mem_ctx) ir_if(operand(r05CF).val);
                              exec_list *const f05CE_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05CE->then_instructions;

                                 body.emit(assign(r05C3, r05AB, 0x01));

                                 body.emit(assign(r05C4, r05AA, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05CE->else_instructions;

                                 body.emit(assign(r05C1, bit_or(body.constant(0u), r05AB), 0x01));

                                 ir_expression *const r05D0 = less(r05C2, body.constant(int(64)));
                                 ir_expression *const r05D1 = lshift(r05AA, r05C6);
                                 ir_expression *const r05D2 = equal(r05C2, body.constant(int(64)));
                                 ir_expression *const r05D3 = nequal(r05AA, body.constant(0u));
                                 ir_expression *const r05D4 = expr(ir_unop_b2i, r05D3);
                                 ir_expression *const r05D5 = expr(ir_unop_i2u, r05D4);
                                 ir_expression *const r05D6 = expr(ir_triop_csel, r05D2, r05AA, r05D5);
                                 body.emit(assign(r05C3, expr(ir_triop_csel, r05D0, r05D1, r05D6), 0x01));

                                 ir_expression *const r05D7 = less(r05C2, body.constant(int(64)));
                                 ir_expression *const r05D8 = bit_and(r05C2, body.constant(int(31)));
                                 ir_expression *const r05D9 = rshift(r05AA, r05D8);
                                 body.emit(assign(r05C4, expr(ir_triop_csel, r05D7, r05D9, body.constant(0u)), 0x01));


                              body.instructions = f05CE_parent_instructions;
                              body.emit(f05CE);

                              /* END IF */

                              body.emit(assign(r05C5, body.constant(0u), 0x01));


                           body.instructions = f05CA_parent_instructions;
                           body.emit(f05CA);

                           /* END IF */

                           ir_expression *const r05DA = nequal(r05C1, body.constant(0u));
                           ir_expression *const r05DB = expr(ir_unop_b2i, r05DA);
                           ir_expression *const r05DC = expr(ir_unop_i2u, r05DB);
                           body.emit(assign(r05C3, bit_or(r05C3, r05DC), 0x01));


                        body.instructions = f05C8_parent_instructions;
                        body.emit(f05C8);

                        /* END IF */

                        body.emit(assign(r05AA, r05C5, 0x01));

                        body.emit(assign(r05AB, r05C4, 0x01));

                        body.emit(assign(r05AC, r05C3, 0x01));


                     body.instructions = f05B9_parent_instructions;
                     body.emit(f05B9);

                     /* END IF */

                     body.emit(assign(r05A9, sub(r05A9, r05AD), 0x01));

                     ir_variable *const r05DD = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05DD, r05A9, 0x01));

                     ir_variable *const r05DE = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r05DE, r05AA, 0x01));

                     ir_variable *const r05DF = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r05DF, r05AB, 0x01));

                     ir_variable *const r05E0 = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r05E0, r05AC, 0x01));

                     ir_variable *const r05E1 = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r05E1, body.constant(true), 0x01));

                     ir_variable *const r05E2 = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r05E3 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r05E3);
                     ir_expression *const r05E4 = expr(ir_unop_u2i, r05AC);
                     body.emit(assign(r05E3, less(r05E4, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05E6 = gequal(r05A9, body.constant(int(2045)));
                     ir_if *f05E5 = new(mem_ctx) ir_if(operand(r05E6).val);
                     exec_list *const f05E5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05E5->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05E8 = less(body.constant(int(2045)), r05A9);
                        ir_expression *const r05E9 = equal(r05A9, body.constant(int(2045)));
                        ir_expression *const r05EA = equal(body.constant(2097151u), r05AA);
                        ir_expression *const r05EB = equal(body.constant(4294967295u), r05AB);
                        ir_expression *const r05EC = logic_and(r05EA, r05EB);
                        ir_expression *const r05ED = logic_and(r05E9, r05EC);
                        ir_expression *const r05EE = logic_and(r05ED, r05E3);
                        ir_expression *const r05EF = logic_or(r05E8, r05EE);
                        ir_if *f05E7 = new(mem_ctx) ir_if(operand(r05EF).val);
                        exec_list *const f05E7_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E7->then_instructions;

                           ir_variable *const r05F0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r05F0);
                           ir_expression *const r05F1 = lshift(r01CF, body.constant(int(31)));
                           body.emit(assign(r05F0, add(r05F1, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r05F0, body.constant(0u), 0x01));

                           body.emit(assign(r05E2, r05F0, 0x03));

                           body.emit(assign(r05E1, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05E7->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05F3 = less(r05A9, body.constant(int(0)));
                           ir_if *f05F2 = new(mem_ctx) ir_if(operand(r05F3).val);
                           exec_list *const f05F2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05F2->then_instructions;

                              ir_variable *const r05F4 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r05F4, r05AC, 0x01));

                              ir_variable *const r05F5 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r05F5, neg(r05A9), 0x01));

                              ir_variable *const r05F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r05F6);
                              ir_variable *const r05F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r05F7);
                              ir_variable *const r05F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r05F8);
                              ir_variable *const r05F9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r05FA = neg(r05F5);
                              body.emit(assign(r05F9, bit_and(r05FA, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r05FC = equal(r05F5, body.constant(int(0)));
                              ir_if *f05FB = new(mem_ctx) ir_if(operand(r05FC).val);
                              exec_list *const f05FB_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05FB->then_instructions;

                                 body.emit(assign(r05F6, r05AC, 0x01));

                                 body.emit(assign(r05F7, r05AB, 0x01));

                                 body.emit(assign(r05F8, r05AA, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05FB->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05FE = less(r05F5, body.constant(int(32)));
                                 ir_if *f05FD = new(mem_ctx) ir_if(operand(r05FE).val);
                                 exec_list *const f05FD_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05FD->then_instructions;

                                    body.emit(assign(r05F6, lshift(r05AB, r05F9), 0x01));

                                    ir_expression *const r05FF = lshift(r05AA, r05F9);
                                    ir_expression *const r0600 = rshift(r05AB, r05F5);
                                    body.emit(assign(r05F7, bit_or(r05FF, r0600), 0x01));

                                    body.emit(assign(r05F8, rshift(r05AA, r05F5), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05FD->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0602 = equal(r05F5, body.constant(int(32)));
                                    ir_if *f0601 = new(mem_ctx) ir_if(operand(r0602).val);
                                    exec_list *const f0601_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0601->then_instructions;

                                       body.emit(assign(r05F6, r05AB, 0x01));

                                       body.emit(assign(r05F7, r05AA, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0601->else_instructions;

                                       body.emit(assign(r05F4, bit_or(r05AC, r05AB), 0x01));

                                       ir_expression *const r0603 = less(r05F5, body.constant(int(64)));
                                       ir_expression *const r0604 = lshift(r05AA, r05F9);
                                       ir_expression *const r0605 = equal(r05F5, body.constant(int(64)));
                                       ir_expression *const r0606 = nequal(r05AA, body.constant(0u));
                                       ir_expression *const r0607 = expr(ir_unop_b2i, r0606);
                                       ir_expression *const r0608 = expr(ir_unop_i2u, r0607);
                                       ir_expression *const r0609 = expr(ir_triop_csel, r0605, r05AA, r0608);
                                       body.emit(assign(r05F6, expr(ir_triop_csel, r0603, r0604, r0609), 0x01));

                                       ir_expression *const r060A = less(r05F5, body.constant(int(64)));
                                       ir_expression *const r060B = bit_and(r05F5, body.constant(int(31)));
                                       ir_expression *const r060C = rshift(r05AA, r060B);
                                       body.emit(assign(r05F7, expr(ir_triop_csel, r060A, r060C, body.constant(0u)), 0x01));


                                    body.instructions = f0601_parent_instructions;
                                    body.emit(f0601);

                                    /* END IF */

                                    body.emit(assign(r05F8, body.constant(0u), 0x01));


                                 body.instructions = f05FD_parent_instructions;
                                 body.emit(f05FD);

                                 /* END IF */

                                 ir_expression *const r060D = nequal(r05F4, body.constant(0u));
                                 ir_expression *const r060E = expr(ir_unop_b2i, r060D);
                                 ir_expression *const r060F = expr(ir_unop_i2u, r060E);
                                 body.emit(assign(r05F6, bit_or(r05F6, r060F), 0x01));


                              body.instructions = f05FB_parent_instructions;
                              body.emit(f05FB);

                              /* END IF */

                              body.emit(assign(r05DE, r05F8, 0x01));

                              body.emit(assign(r05DF, r05F7, 0x01));

                              body.emit(assign(r05E0, r05F6, 0x01));

                              body.emit(assign(r05DD, body.constant(int(0)), 0x01));

                              body.emit(assign(r05E3, less(r05F6, body.constant(0u)), 0x01));


                           body.instructions = f05F2_parent_instructions;
                           body.emit(f05F2);

                           /* END IF */


                        body.instructions = f05E7_parent_instructions;
                        body.emit(f05E7);

                        /* END IF */


                     body.instructions = f05E5_parent_instructions;
                     body.emit(f05E5);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0610 = new(mem_ctx) ir_if(operand(r05E1).val);
                     exec_list *const f0610_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0610->then_instructions;

                        /* IF CONDITION */
                        ir_if *f0611 = new(mem_ctx) ir_if(operand(r05E3).val);
                        exec_list *const f0611_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0611->then_instructions;

                           ir_variable *const r0612 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r0612, add(r05DF, body.constant(1u)), 0x01));

                           ir_expression *const r0613 = less(r0612, r05DF);
                           ir_expression *const r0614 = expr(ir_unop_b2i, r0613);
                           ir_expression *const r0615 = expr(ir_unop_i2u, r0614);
                           body.emit(assign(r05DE, add(r05DE, r0615), 0x01));

                           ir_expression *const r0616 = equal(r05E0, body.constant(0u));
                           ir_expression *const r0617 = expr(ir_unop_b2i, r0616);
                           ir_expression *const r0618 = expr(ir_unop_i2u, r0617);
                           ir_expression *const r0619 = add(r05E0, r0618);
                           ir_expression *const r061A = bit_and(r0619, body.constant(1u));
                           ir_expression *const r061B = expr(ir_unop_bit_not, r061A);
                           body.emit(assign(r05DF, bit_and(r0612, r061B), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0611->else_instructions;

                           ir_expression *const r061C = bit_or(r05DE, r05DF);
                           ir_expression *const r061D = equal(r061C, body.constant(0u));
                           body.emit(assign(r05DD, expr(ir_triop_csel, r061D, body.constant(int(0)), r05DD), 0x01));


                        body.instructions = f0611_parent_instructions;
                        body.emit(f0611);

                        /* END IF */

                        ir_variable *const r061E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r061E);
                        ir_expression *const r061F = lshift(r01CF, body.constant(int(31)));
                        ir_expression *const r0620 = expr(ir_unop_i2u, r05DD);
                        ir_expression *const r0621 = lshift(r0620, body.constant(int(20)));
                        ir_expression *const r0622 = add(r061F, r0621);
                        body.emit(assign(r061E, add(r0622, r05DE), 0x02));

                        body.emit(assign(r061E, r05DF, 0x01));

                        body.emit(assign(r05E2, r061E, 0x03));

                        body.emit(assign(r05E1, body.constant(false), 0x01));


                     body.instructions = f0610_parent_instructions;
                     body.emit(f0610);

                     /* END IF */

                     body.emit(assign(r01CE, r05E2, 0x03));

                     body.emit(assign(r01CD, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05A2->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0624 = less(r036B, r036D);
                     ir_if *f0623 = new(mem_ctx) ir_if(operand(r0624).val);
                     exec_list *const f0623_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0623->then_instructions;

                        ir_variable *const r0625 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_expression *const r0626 = sub(r036C, r036A);
                        ir_expression *const r0627 = less(r036D, r036B);
                        ir_expression *const r0628 = expr(ir_unop_b2i, r0627);
                        ir_expression *const r0629 = expr(ir_unop_i2u, r0628);
                        body.emit(assign(r0625, sub(r0626, r0629), 0x01));

                        body.emit(assign(r036E, add(r0369, body.constant(int(-1))), 0x01));

                        ir_variable *const r062A = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r062A, add(r036E, body.constant(int(-10))), 0x01));

                        ir_variable *const r062B = body.make_temp(glsl_type::uint_type, "zFrac0");
                        ir_variable *const r062C = body.make_temp(glsl_type::uint_type, "zFrac1");
                        ir_variable *const r062D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r062D);
                        ir_variable *const r062E = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r062E);
                        ir_expression *const r062F = equal(r0625, body.constant(0u));
                        ir_expression *const r0630 = add(r062A, body.constant(int(-32)));
                        body.emit(assign(r062A, expr(ir_triop_csel, r062F, r0630, r062A), 0x01));

                        ir_variable *const r0631 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0632 = equal(r0625, body.constant(0u));
                        ir_expression *const r0633 = sub(r036D, r036B);
                        body.emit(assign(r0631, expr(ir_triop_csel, r0632, body.constant(0u), r0633), 0x01));

                        body.emit(assign(r062C, r0631, 0x01));

                        ir_variable *const r0634 = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r0635 = equal(r0625, body.constant(0u));
                        body.emit(assign(r0634, expr(ir_triop_csel, r0635, r0631, r0625), 0x01));

                        body.emit(assign(r062B, r0634, 0x01));

                        ir_expression *const r0636 = equal(r0634, body.constant(0u));
                        ir_expression *const r0637 = expr(ir_unop_find_msb, r0634);
                        ir_expression *const r0638 = sub(body.constant(int(31)), r0637);
                        ir_expression *const r0639 = expr(ir_triop_csel, r0636, body.constant(int(32)), r0638);
                        body.emit(assign(r062E, add(r0639, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r063B = gequal(r062E, body.constant(int(0)));
                        ir_if *f063A = new(mem_ctx) ir_if(operand(r063B).val);
                        exec_list *const f063A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f063A->then_instructions;

                           body.emit(assign(r062D, body.constant(0u), 0x01));

                           ir_expression *const r063C = equal(r062E, body.constant(int(0)));
                           ir_expression *const r063D = lshift(r0634, r062E);
                           ir_expression *const r063E = neg(r062E);
                           ir_expression *const r063F = bit_and(r063E, body.constant(int(31)));
                           ir_expression *const r0640 = rshift(r0631, r063F);
                           ir_expression *const r0641 = bit_or(r063D, r0640);
                           body.emit(assign(r062B, expr(ir_triop_csel, r063C, r0634, r0641), 0x01));

                           body.emit(assign(r062C, lshift(r0631, r062E), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f063A->else_instructions;

                           ir_variable *const r0642 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0642, body.constant(0u), 0x01));

                           ir_variable *const r0643 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0643, neg(r062E), 0x01));

                           ir_variable *const r0644 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0644);
                           ir_variable *const r0645 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0645);
                           ir_variable *const r0646 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0646);
                           ir_variable *const r0647 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0648 = neg(r0643);
                           body.emit(assign(r0647, bit_and(r0648, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r064A = equal(r0643, body.constant(int(0)));
                           ir_if *f0649 = new(mem_ctx) ir_if(operand(r064A).val);
                           exec_list *const f0649_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0649->then_instructions;

                              body.emit(assign(r0644, r0642, 0x01));

                              body.emit(assign(r0645, r062C, 0x01));

                              body.emit(assign(r0646, r062B, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0649->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r064C = less(r0643, body.constant(int(32)));
                              ir_if *f064B = new(mem_ctx) ir_if(operand(r064C).val);
                              exec_list *const f064B_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f064B->then_instructions;

                                 body.emit(assign(r0644, lshift(r062C, r0647), 0x01));

                                 ir_expression *const r064D = lshift(r062B, r0647);
                                 ir_expression *const r064E = rshift(r062C, r0643);
                                 body.emit(assign(r0645, bit_or(r064D, r064E), 0x01));

                                 body.emit(assign(r0646, rshift(r062B, r0643), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f064B->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0650 = equal(r0643, body.constant(int(32)));
                                 ir_if *f064F = new(mem_ctx) ir_if(operand(r0650).val);
                                 exec_list *const f064F_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f064F->then_instructions;

                                    body.emit(assign(r0644, r062C, 0x01));

                                    body.emit(assign(r0645, r062B, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f064F->else_instructions;

                                    body.emit(assign(r0642, bit_or(body.constant(0u), r062C), 0x01));

                                    ir_expression *const r0651 = less(r0643, body.constant(int(64)));
                                    ir_expression *const r0652 = lshift(r062B, r0647);
                                    ir_expression *const r0653 = equal(r0643, body.constant(int(64)));
                                    ir_expression *const r0654 = nequal(r062B, body.constant(0u));
                                    ir_expression *const r0655 = expr(ir_unop_b2i, r0654);
                                    ir_expression *const r0656 = expr(ir_unop_i2u, r0655);
                                    ir_expression *const r0657 = expr(ir_triop_csel, r0653, r062B, r0656);
                                    body.emit(assign(r0644, expr(ir_triop_csel, r0651, r0652, r0657), 0x01));

                                    ir_expression *const r0658 = less(r0643, body.constant(int(64)));
                                    ir_expression *const r0659 = bit_and(r0643, body.constant(int(31)));
                                    ir_expression *const r065A = rshift(r062B, r0659);
                                    body.emit(assign(r0645, expr(ir_triop_csel, r0658, r065A, body.constant(0u)), 0x01));


                                 body.instructions = f064F_parent_instructions;
                                 body.emit(f064F);

                                 /* END IF */

                                 body.emit(assign(r0646, body.constant(0u), 0x01));


                              body.instructions = f064B_parent_instructions;
                              body.emit(f064B);

                              /* END IF */

                              ir_expression *const r065B = nequal(r0642, body.constant(0u));
                              ir_expression *const r065C = expr(ir_unop_b2i, r065B);
                              ir_expression *const r065D = expr(ir_unop_i2u, r065C);
                              body.emit(assign(r0644, bit_or(r0644, r065D), 0x01));


                           body.instructions = f0649_parent_instructions;
                           body.emit(f0649);

                           /* END IF */

                           body.emit(assign(r062B, r0646, 0x01));

                           body.emit(assign(r062C, r0645, 0x01));

                           body.emit(assign(r062D, r0644, 0x01));


                        body.instructions = f063A_parent_instructions;
                        body.emit(f063A);

                        /* END IF */

                        body.emit(assign(r062A, sub(r062A, r062E), 0x01));

                        ir_variable *const r065E = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r065E, r062A, 0x01));

                        ir_variable *const r065F = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r065F, r062B, 0x01));

                        ir_variable *const r0660 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0660, r062C, 0x01));

                        ir_variable *const r0661 = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r0661, r062D, 0x01));

                        ir_variable *const r0662 = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r0662, body.constant(true), 0x01));

                        ir_variable *const r0663 = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r0664 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r0664);
                        ir_expression *const r0665 = expr(ir_unop_u2i, r062D);
                        body.emit(assign(r0664, less(r0665, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0667 = gequal(r062A, body.constant(int(2045)));
                        ir_if *f0666 = new(mem_ctx) ir_if(operand(r0667).val);
                        exec_list *const f0666_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0666->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0669 = less(body.constant(int(2045)), r062A);
                           ir_expression *const r066A = equal(r062A, body.constant(int(2045)));
                           ir_expression *const r066B = equal(body.constant(2097151u), r062B);
                           ir_expression *const r066C = equal(body.constant(4294967295u), r062C);
                           ir_expression *const r066D = logic_and(r066B, r066C);
                           ir_expression *const r066E = logic_and(r066A, r066D);
                           ir_expression *const r066F = logic_and(r066E, r0664);
                           ir_expression *const r0670 = logic_or(r0669, r066F);
                           ir_if *f0668 = new(mem_ctx) ir_if(operand(r0670).val);
                           exec_list *const f0668_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0668->then_instructions;

                              ir_variable *const r0671 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0671);
                              ir_expression *const r0672 = lshift(r01CF, body.constant(int(31)));
                              body.emit(assign(r0671, add(r0672, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r0671, body.constant(0u), 0x01));

                              body.emit(assign(r0663, r0671, 0x03));

                              body.emit(assign(r0662, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0668->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0674 = less(r062A, body.constant(int(0)));
                              ir_if *f0673 = new(mem_ctx) ir_if(operand(r0674).val);
                              exec_list *const f0673_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0673->then_instructions;

                                 ir_variable *const r0675 = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r0675, r062D, 0x01));

                                 ir_variable *const r0676 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r0676, neg(r062A), 0x01));

                                 ir_variable *const r0677 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r0677);
                                 ir_variable *const r0678 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r0678);
                                 ir_variable *const r0679 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r0679);
                                 ir_variable *const r067A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r067B = neg(r0676);
                                 body.emit(assign(r067A, bit_and(r067B, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r067D = equal(r0676, body.constant(int(0)));
                                 ir_if *f067C = new(mem_ctx) ir_if(operand(r067D).val);
                                 exec_list *const f067C_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f067C->then_instructions;

                                    body.emit(assign(r0677, r062D, 0x01));

                                    body.emit(assign(r0678, r062C, 0x01));

                                    body.emit(assign(r0679, r062B, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f067C->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r067F = less(r0676, body.constant(int(32)));
                                    ir_if *f067E = new(mem_ctx) ir_if(operand(r067F).val);
                                    exec_list *const f067E_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f067E->then_instructions;

                                       body.emit(assign(r0677, lshift(r062C, r067A), 0x01));

                                       ir_expression *const r0680 = lshift(r062B, r067A);
                                       ir_expression *const r0681 = rshift(r062C, r0676);
                                       body.emit(assign(r0678, bit_or(r0680, r0681), 0x01));

                                       body.emit(assign(r0679, rshift(r062B, r0676), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f067E->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r0683 = equal(r0676, body.constant(int(32)));
                                       ir_if *f0682 = new(mem_ctx) ir_if(operand(r0683).val);
                                       exec_list *const f0682_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0682->then_instructions;

                                          body.emit(assign(r0677, r062C, 0x01));

                                          body.emit(assign(r0678, r062B, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0682->else_instructions;

                                          body.emit(assign(r0675, bit_or(r062D, r062C), 0x01));

                                          ir_expression *const r0684 = less(r0676, body.constant(int(64)));
                                          ir_expression *const r0685 = lshift(r062B, r067A);
                                          ir_expression *const r0686 = equal(r0676, body.constant(int(64)));
                                          ir_expression *const r0687 = nequal(r062B, body.constant(0u));
                                          ir_expression *const r0688 = expr(ir_unop_b2i, r0687);
                                          ir_expression *const r0689 = expr(ir_unop_i2u, r0688);
                                          ir_expression *const r068A = expr(ir_triop_csel, r0686, r062B, r0689);
                                          body.emit(assign(r0677, expr(ir_triop_csel, r0684, r0685, r068A), 0x01));

                                          ir_expression *const r068B = less(r0676, body.constant(int(64)));
                                          ir_expression *const r068C = bit_and(r0676, body.constant(int(31)));
                                          ir_expression *const r068D = rshift(r062B, r068C);
                                          body.emit(assign(r0678, expr(ir_triop_csel, r068B, r068D, body.constant(0u)), 0x01));


                                       body.instructions = f0682_parent_instructions;
                                       body.emit(f0682);

                                       /* END IF */

                                       body.emit(assign(r0679, body.constant(0u), 0x01));


                                    body.instructions = f067E_parent_instructions;
                                    body.emit(f067E);

                                    /* END IF */

                                    ir_expression *const r068E = nequal(r0675, body.constant(0u));
                                    ir_expression *const r068F = expr(ir_unop_b2i, r068E);
                                    ir_expression *const r0690 = expr(ir_unop_i2u, r068F);
                                    body.emit(assign(r0677, bit_or(r0677, r0690), 0x01));


                                 body.instructions = f067C_parent_instructions;
                                 body.emit(f067C);

                                 /* END IF */

                                 body.emit(assign(r065F, r0679, 0x01));

                                 body.emit(assign(r0660, r0678, 0x01));

                                 body.emit(assign(r0661, r0677, 0x01));

                                 body.emit(assign(r065E, body.constant(int(0)), 0x01));

                                 body.emit(assign(r0664, less(r0677, body.constant(0u)), 0x01));


                              body.instructions = f0673_parent_instructions;
                              body.emit(f0673);

                              /* END IF */


                           body.instructions = f0668_parent_instructions;
                           body.emit(f0668);

                           /* END IF */


                        body.instructions = f0666_parent_instructions;
                        body.emit(f0666);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f0691 = new(mem_ctx) ir_if(operand(r0662).val);
                        exec_list *const f0691_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0691->then_instructions;

                           /* IF CONDITION */
                           ir_if *f0692 = new(mem_ctx) ir_if(operand(r0664).val);
                           exec_list *const f0692_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0692->then_instructions;

                              ir_variable *const r0693 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r0693, add(r0660, body.constant(1u)), 0x01));

                              ir_expression *const r0694 = less(r0693, r0660);
                              ir_expression *const r0695 = expr(ir_unop_b2i, r0694);
                              ir_expression *const r0696 = expr(ir_unop_i2u, r0695);
                              body.emit(assign(r065F, add(r065F, r0696), 0x01));

                              ir_expression *const r0697 = equal(r0661, body.constant(0u));
                              ir_expression *const r0698 = expr(ir_unop_b2i, r0697);
                              ir_expression *const r0699 = expr(ir_unop_i2u, r0698);
                              ir_expression *const r069A = add(r0661, r0699);
                              ir_expression *const r069B = bit_and(r069A, body.constant(1u));
                              ir_expression *const r069C = expr(ir_unop_bit_not, r069B);
                              body.emit(assign(r0660, bit_and(r0693, r069C), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0692->else_instructions;

                              ir_expression *const r069D = bit_or(r065F, r0660);
                              ir_expression *const r069E = equal(r069D, body.constant(0u));
                              body.emit(assign(r065E, expr(ir_triop_csel, r069E, body.constant(int(0)), r065E), 0x01));


                           body.instructions = f0692_parent_instructions;
                           body.emit(f0692);

                           /* END IF */

                           ir_variable *const r069F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r069F);
                           ir_expression *const r06A0 = lshift(r01CF, body.constant(int(31)));
                           ir_expression *const r06A1 = expr(ir_unop_i2u, r065E);
                           ir_expression *const r06A2 = lshift(r06A1, body.constant(int(20)));
                           ir_expression *const r06A3 = add(r06A0, r06A2);
                           body.emit(assign(r069F, add(r06A3, r065F), 0x02));

                           body.emit(assign(r069F, r0660, 0x01));

                           body.emit(assign(r0663, r069F, 0x03));

                           body.emit(assign(r0662, body.constant(false), 0x01));


                        body.instructions = f0691_parent_instructions;
                        body.emit(f0691);

                        /* END IF */

                        body.emit(assign(r01CE, r0663, 0x03));

                        body.emit(assign(r01CD, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0623->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r06A5 = less(r036D, r036B);
                        ir_if *f06A4 = new(mem_ctx) ir_if(operand(r06A5).val);
                        exec_list *const f06A4_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06A4->then_instructions;

                           ir_variable *const r06A6 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_expression *const r06A7 = sub(r036A, r036C);
                           ir_expression *const r06A8 = less(r036B, r036D);
                           ir_expression *const r06A9 = expr(ir_unop_b2i, r06A8);
                           ir_expression *const r06AA = expr(ir_unop_i2u, r06A9);
                           body.emit(assign(r06A6, sub(r06A7, r06AA), 0x01));

                           body.emit(assign(r01CF, bit_xor(r01CF, body.constant(1u)), 0x01));

                           body.emit(assign(r036E, add(r0368, body.constant(int(-1))), 0x01));

                           ir_variable *const r06AB = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06AB, add(r036E, body.constant(int(-10))), 0x01));

                           ir_variable *const r06AC = body.make_temp(glsl_type::uint_type, "zFrac0");
                           ir_variable *const r06AD = body.make_temp(glsl_type::uint_type, "zFrac1");
                           ir_variable *const r06AE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r06AE);
                           ir_variable *const r06AF = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06AF);
                           ir_expression *const r06B0 = equal(r06A6, body.constant(0u));
                           ir_expression *const r06B1 = add(r06AB, body.constant(int(-32)));
                           body.emit(assign(r06AB, expr(ir_triop_csel, r06B0, r06B1, r06AB), 0x01));

                           ir_variable *const r06B2 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06B3 = equal(r06A6, body.constant(0u));
                           ir_expression *const r06B4 = sub(r036B, r036D);
                           body.emit(assign(r06B2, expr(ir_triop_csel, r06B3, body.constant(0u), r06B4), 0x01));

                           body.emit(assign(r06AD, r06B2, 0x01));

                           ir_variable *const r06B5 = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r06B6 = equal(r06A6, body.constant(0u));
                           body.emit(assign(r06B5, expr(ir_triop_csel, r06B6, r06B2, r06A6), 0x01));

                           body.emit(assign(r06AC, r06B5, 0x01));

                           ir_expression *const r06B7 = equal(r06B5, body.constant(0u));
                           ir_expression *const r06B8 = expr(ir_unop_find_msb, r06B5);
                           ir_expression *const r06B9 = sub(body.constant(int(31)), r06B8);
                           ir_expression *const r06BA = expr(ir_triop_csel, r06B7, body.constant(int(32)), r06B9);
                           body.emit(assign(r06AF, add(r06BA, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06BC = gequal(r06AF, body.constant(int(0)));
                           ir_if *f06BB = new(mem_ctx) ir_if(operand(r06BC).val);
                           exec_list *const f06BB_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06BB->then_instructions;

                              body.emit(assign(r06AE, body.constant(0u), 0x01));

                              ir_expression *const r06BD = equal(r06AF, body.constant(int(0)));
                              ir_expression *const r06BE = lshift(r06B5, r06AF);
                              ir_expression *const r06BF = neg(r06AF);
                              ir_expression *const r06C0 = bit_and(r06BF, body.constant(int(31)));
                              ir_expression *const r06C1 = rshift(r06B2, r06C0);
                              ir_expression *const r06C2 = bit_or(r06BE, r06C1);
                              body.emit(assign(r06AC, expr(ir_triop_csel, r06BD, r06B5, r06C2), 0x01));

                              body.emit(assign(r06AD, lshift(r06B2, r06AF), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06BB->else_instructions;

                              ir_variable *const r06C3 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r06C3, body.constant(0u), 0x01));

                              ir_variable *const r06C4 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r06C4, neg(r06AF), 0x01));

                              ir_variable *const r06C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r06C5);
                              ir_variable *const r06C6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r06C6);
                              ir_variable *const r06C7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r06C7);
                              ir_variable *const r06C8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r06C9 = neg(r06C4);
                              body.emit(assign(r06C8, bit_and(r06C9, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r06CB = equal(r06C4, body.constant(int(0)));
                              ir_if *f06CA = new(mem_ctx) ir_if(operand(r06CB).val);
                              exec_list *const f06CA_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06CA->then_instructions;

                                 body.emit(assign(r06C5, r06C3, 0x01));

                                 body.emit(assign(r06C6, r06AD, 0x01));

                                 body.emit(assign(r06C7, r06AC, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06CA->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06CD = less(r06C4, body.constant(int(32)));
                                 ir_if *f06CC = new(mem_ctx) ir_if(operand(r06CD).val);
                                 exec_list *const f06CC_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06CC->then_instructions;

                                    body.emit(assign(r06C5, lshift(r06AD, r06C8), 0x01));

                                    ir_expression *const r06CE = lshift(r06AC, r06C8);
                                    ir_expression *const r06CF = rshift(r06AD, r06C4);
                                    body.emit(assign(r06C6, bit_or(r06CE, r06CF), 0x01));

                                    body.emit(assign(r06C7, rshift(r06AC, r06C4), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06CC->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06D1 = equal(r06C4, body.constant(int(32)));
                                    ir_if *f06D0 = new(mem_ctx) ir_if(operand(r06D1).val);
                                    exec_list *const f06D0_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06D0->then_instructions;

                                       body.emit(assign(r06C5, r06AD, 0x01));

                                       body.emit(assign(r06C6, r06AC, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06D0->else_instructions;

                                       body.emit(assign(r06C3, bit_or(body.constant(0u), r06AD), 0x01));

                                       ir_expression *const r06D2 = less(r06C4, body.constant(int(64)));
                                       ir_expression *const r06D3 = lshift(r06AC, r06C8);
                                       ir_expression *const r06D4 = equal(r06C4, body.constant(int(64)));
                                       ir_expression *const r06D5 = nequal(r06AC, body.constant(0u));
                                       ir_expression *const r06D6 = expr(ir_unop_b2i, r06D5);
                                       ir_expression *const r06D7 = expr(ir_unop_i2u, r06D6);
                                       ir_expression *const r06D8 = expr(ir_triop_csel, r06D4, r06AC, r06D7);
                                       body.emit(assign(r06C5, expr(ir_triop_csel, r06D2, r06D3, r06D8), 0x01));

                                       ir_expression *const r06D9 = less(r06C4, body.constant(int(64)));
                                       ir_expression *const r06DA = bit_and(r06C4, body.constant(int(31)));
                                       ir_expression *const r06DB = rshift(r06AC, r06DA);
                                       body.emit(assign(r06C6, expr(ir_triop_csel, r06D9, r06DB, body.constant(0u)), 0x01));


                                    body.instructions = f06D0_parent_instructions;
                                    body.emit(f06D0);

                                    /* END IF */

                                    body.emit(assign(r06C7, body.constant(0u), 0x01));


                                 body.instructions = f06CC_parent_instructions;
                                 body.emit(f06CC);

                                 /* END IF */

                                 ir_expression *const r06DC = nequal(r06C3, body.constant(0u));
                                 ir_expression *const r06DD = expr(ir_unop_b2i, r06DC);
                                 ir_expression *const r06DE = expr(ir_unop_i2u, r06DD);
                                 body.emit(assign(r06C5, bit_or(r06C5, r06DE), 0x01));


                              body.instructions = f06CA_parent_instructions;
                              body.emit(f06CA);

                              /* END IF */

                              body.emit(assign(r06AC, r06C7, 0x01));

                              body.emit(assign(r06AD, r06C6, 0x01));

                              body.emit(assign(r06AE, r06C5, 0x01));


                           body.instructions = f06BB_parent_instructions;
                           body.emit(f06BB);

                           /* END IF */

                           body.emit(assign(r06AB, sub(r06AB, r06AF), 0x01));

                           ir_variable *const r06DF = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06DF, r06AB, 0x01));

                           ir_variable *const r06E0 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r06E0, r06AC, 0x01));

                           ir_variable *const r06E1 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r06E1, r06AD, 0x01));

                           ir_variable *const r06E2 = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r06E2, r06AE, 0x01));

                           ir_variable *const r06E3 = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r06E3, body.constant(true), 0x01));

                           ir_variable *const r06E4 = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r06E5 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r06E5);
                           ir_expression *const r06E6 = expr(ir_unop_u2i, r06AE);
                           body.emit(assign(r06E5, less(r06E6, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06E8 = gequal(r06AB, body.constant(int(2045)));
                           ir_if *f06E7 = new(mem_ctx) ir_if(operand(r06E8).val);
                           exec_list *const f06E7_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06E7->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06EA = less(body.constant(int(2045)), r06AB);
                              ir_expression *const r06EB = equal(r06AB, body.constant(int(2045)));
                              ir_expression *const r06EC = equal(body.constant(2097151u), r06AC);
                              ir_expression *const r06ED = equal(body.constant(4294967295u), r06AD);
                              ir_expression *const r06EE = logic_and(r06EC, r06ED);
                              ir_expression *const r06EF = logic_and(r06EB, r06EE);
                              ir_expression *const r06F0 = logic_and(r06EF, r06E5);
                              ir_expression *const r06F1 = logic_or(r06EA, r06F0);
                              ir_if *f06E9 = new(mem_ctx) ir_if(operand(r06F1).val);
                              exec_list *const f06E9_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06E9->then_instructions;

                                 ir_variable *const r06F2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r06F2);
                                 ir_expression *const r06F3 = lshift(r01CF, body.constant(int(31)));
                                 body.emit(assign(r06F2, add(r06F3, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r06F2, body.constant(0u), 0x01));

                                 body.emit(assign(r06E4, r06F2, 0x03));

                                 body.emit(assign(r06E3, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06E9->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06F5 = less(r06AB, body.constant(int(0)));
                                 ir_if *f06F4 = new(mem_ctx) ir_if(operand(r06F5).val);
                                 exec_list *const f06F4_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06F4->then_instructions;

                                    ir_variable *const r06F6 = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r06F6, r06AE, 0x01));

                                    ir_variable *const r06F7 = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r06F7, neg(r06AB), 0x01));

                                    ir_variable *const r06F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r06F8);
                                    ir_variable *const r06F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r06F9);
                                    ir_variable *const r06FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r06FA);
                                    ir_variable *const r06FB = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r06FC = neg(r06F7);
                                    body.emit(assign(r06FB, bit_and(r06FC, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r06FE = equal(r06F7, body.constant(int(0)));
                                    ir_if *f06FD = new(mem_ctx) ir_if(operand(r06FE).val);
                                    exec_list *const f06FD_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06FD->then_instructions;

                                       body.emit(assign(r06F8, r06AE, 0x01));

                                       body.emit(assign(r06F9, r06AD, 0x01));

                                       body.emit(assign(r06FA, r06AC, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06FD->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r0700 = less(r06F7, body.constant(int(32)));
                                       ir_if *f06FF = new(mem_ctx) ir_if(operand(r0700).val);
                                       exec_list *const f06FF_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06FF->then_instructions;

                                          body.emit(assign(r06F8, lshift(r06AD, r06FB), 0x01));

                                          ir_expression *const r0701 = lshift(r06AC, r06FB);
                                          ir_expression *const r0702 = rshift(r06AD, r06F7);
                                          body.emit(assign(r06F9, bit_or(r0701, r0702), 0x01));

                                          body.emit(assign(r06FA, rshift(r06AC, r06F7), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06FF->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r0704 = equal(r06F7, body.constant(int(32)));
                                          ir_if *f0703 = new(mem_ctx) ir_if(operand(r0704).val);
                                          exec_list *const f0703_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0703->then_instructions;

                                             body.emit(assign(r06F8, r06AD, 0x01));

                                             body.emit(assign(r06F9, r06AC, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0703->else_instructions;

                                             body.emit(assign(r06F6, bit_or(r06AE, r06AD), 0x01));

                                             ir_expression *const r0705 = less(r06F7, body.constant(int(64)));
                                             ir_expression *const r0706 = lshift(r06AC, r06FB);
                                             ir_expression *const r0707 = equal(r06F7, body.constant(int(64)));
                                             ir_expression *const r0708 = nequal(r06AC, body.constant(0u));
                                             ir_expression *const r0709 = expr(ir_unop_b2i, r0708);
                                             ir_expression *const r070A = expr(ir_unop_i2u, r0709);
                                             ir_expression *const r070B = expr(ir_triop_csel, r0707, r06AC, r070A);
                                             body.emit(assign(r06F8, expr(ir_triop_csel, r0705, r0706, r070B), 0x01));

                                             ir_expression *const r070C = less(r06F7, body.constant(int(64)));
                                             ir_expression *const r070D = bit_and(r06F7, body.constant(int(31)));
                                             ir_expression *const r070E = rshift(r06AC, r070D);
                                             body.emit(assign(r06F9, expr(ir_triop_csel, r070C, r070E, body.constant(0u)), 0x01));


                                          body.instructions = f0703_parent_instructions;
                                          body.emit(f0703);

                                          /* END IF */

                                          body.emit(assign(r06FA, body.constant(0u), 0x01));


                                       body.instructions = f06FF_parent_instructions;
                                       body.emit(f06FF);

                                       /* END IF */

                                       ir_expression *const r070F = nequal(r06F6, body.constant(0u));
                                       ir_expression *const r0710 = expr(ir_unop_b2i, r070F);
                                       ir_expression *const r0711 = expr(ir_unop_i2u, r0710);
                                       body.emit(assign(r06F8, bit_or(r06F8, r0711), 0x01));


                                    body.instructions = f06FD_parent_instructions;
                                    body.emit(f06FD);

                                    /* END IF */

                                    body.emit(assign(r06E0, r06FA, 0x01));

                                    body.emit(assign(r06E1, r06F9, 0x01));

                                    body.emit(assign(r06E2, r06F8, 0x01));

                                    body.emit(assign(r06DF, body.constant(int(0)), 0x01));

                                    body.emit(assign(r06E5, less(r06F8, body.constant(0u)), 0x01));


                                 body.instructions = f06F4_parent_instructions;
                                 body.emit(f06F4);

                                 /* END IF */


                              body.instructions = f06E9_parent_instructions;
                              body.emit(f06E9);

                              /* END IF */


                           body.instructions = f06E7_parent_instructions;
                           body.emit(f06E7);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f0712 = new(mem_ctx) ir_if(operand(r06E3).val);
                           exec_list *const f0712_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0712->then_instructions;

                              /* IF CONDITION */
                              ir_if *f0713 = new(mem_ctx) ir_if(operand(r06E5).val);
                              exec_list *const f0713_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0713->then_instructions;

                                 ir_variable *const r0714 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r0714, add(r06E1, body.constant(1u)), 0x01));

                                 ir_expression *const r0715 = less(r0714, r06E1);
                                 ir_expression *const r0716 = expr(ir_unop_b2i, r0715);
                                 ir_expression *const r0717 = expr(ir_unop_i2u, r0716);
                                 body.emit(assign(r06E0, add(r06E0, r0717), 0x01));

                                 ir_expression *const r0718 = equal(r06E2, body.constant(0u));
                                 ir_expression *const r0719 = expr(ir_unop_b2i, r0718);
                                 ir_expression *const r071A = expr(ir_unop_i2u, r0719);
                                 ir_expression *const r071B = add(r06E2, r071A);
                                 ir_expression *const r071C = bit_and(r071B, body.constant(1u));
                                 ir_expression *const r071D = expr(ir_unop_bit_not, r071C);
                                 body.emit(assign(r06E1, bit_and(r0714, r071D), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0713->else_instructions;

                                 ir_expression *const r071E = bit_or(r06E0, r06E1);
                                 ir_expression *const r071F = equal(r071E, body.constant(0u));
                                 body.emit(assign(r06DF, expr(ir_triop_csel, r071F, body.constant(int(0)), r06DF), 0x01));


                              body.instructions = f0713_parent_instructions;
                              body.emit(f0713);

                              /* END IF */

                              ir_variable *const r0720 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0720);
                              ir_expression *const r0721 = lshift(r01CF, body.constant(int(31)));
                              ir_expression *const r0722 = expr(ir_unop_i2u, r06DF);
                              ir_expression *const r0723 = lshift(r0722, body.constant(int(20)));
                              ir_expression *const r0724 = add(r0721, r0723);
                              body.emit(assign(r0720, add(r0724, r06E0), 0x02));

                              body.emit(assign(r0720, r06E1, 0x01));

                              body.emit(assign(r06E4, r0720, 0x03));

                              body.emit(assign(r06E3, body.constant(false), 0x01));


                           body.instructions = f0712_parent_instructions;
                           body.emit(f0712);

                           /* END IF */

                           body.emit(assign(r01CE, r06E4, 0x03));

                           body.emit(assign(r01CD, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06A4->else_instructions;

                           ir_variable *const r0725 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0725);
                           body.emit(assign(r0725, body.constant(0u), 0x02));

                           body.emit(assign(r0725, body.constant(0u), 0x01));

                           body.emit(assign(r01CE, r0725, 0x03));

                           body.emit(assign(r01CD, body.constant(false), 0x01));


                        body.instructions = f06A4_parent_instructions;
                        body.emit(f06A4);

                        /* END IF */


                     body.instructions = f0623_parent_instructions;
                     body.emit(f0623);

                     /* END IF */


                  body.instructions = f05A2_parent_instructions;
                  body.emit(f05A2);

                  /* END IF */


               body.instructions = f0521_parent_instructions;
               body.emit(f0521);

               /* END IF */


            body.instructions = f0503_parent_instructions;
            body.emit(f0503);

            /* END IF */


         body.instructions = f043F_parent_instructions;
         body.emit(f043F);

         /* END IF */


      body.instructions = f037F_parent_instructions;
      body.emit(f037F);

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

   ir_variable *const r0726 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0726);
   ir_variable *const r0727 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0727);
   ir_variable *const r0728 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0728);
   ir_variable *const r0729 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0729);
   ir_variable *const r072A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r072A);
   ir_variable *const r072B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r072B);
   ir_variable *const r072C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r072C);
   ir_variable *const r072D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r072D, bit_and(r0726, body.constant(65535u)), 0x01));

   ir_variable *const r072E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r072E, rshift(r0726, body.constant(int(16))), 0x01));

   ir_variable *const r072F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r072F, bit_and(r0727, body.constant(65535u)), 0x01));

   ir_variable *const r0730 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0730, rshift(r0727, body.constant(int(16))), 0x01));

   ir_variable *const r0731 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0731, mul(r072E, r072F), 0x01));

   ir_expression *const r0732 = mul(r072D, r0730);
   body.emit(assign(r072B, add(r0732, r0731), 0x01));

   ir_expression *const r0733 = mul(r072E, r0730);
   ir_expression *const r0734 = less(r072B, r0731);
   ir_expression *const r0735 = expr(ir_unop_b2i, r0734);
   ir_expression *const r0736 = expr(ir_unop_i2u, r0735);
   ir_expression *const r0737 = lshift(r0736, body.constant(int(16)));
   ir_expression *const r0738 = rshift(r072B, body.constant(int(16)));
   ir_expression *const r0739 = add(r0737, r0738);
   body.emit(assign(r072A, add(r0733, r0739), 0x01));

   body.emit(assign(r072B, lshift(r072B, body.constant(int(16))), 0x01));

   ir_expression *const r073A = mul(r072D, r072F);
   body.emit(assign(r072C, add(r073A, r072B), 0x01));

   ir_expression *const r073B = less(r072C, r072B);
   ir_expression *const r073C = expr(ir_unop_b2i, r073B);
   ir_expression *const r073D = expr(ir_unop_i2u, r073C);
   body.emit(assign(r072A, add(r072A, r073D), 0x01));

   body.emit(assign(r0729, r072C, 0x01));

   body.emit(assign(r0728, r072A, 0x01));

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

   ir_variable *const r073E = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r073E);
   ir_variable *const r073F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r073F);
   ir_variable *const r0740 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0740);
   ir_variable *const r0741 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0741);
   ir_variable *const r0742 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0742);
   ir_variable *const r0743 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0743);
   ir_variable *const r0744 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0744);
   ir_variable *const r0745 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0745);
   ir_variable *const r0746 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0746);
   ir_variable *const r0747 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0747);
   ir_variable *const r0748 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0748);
   ir_variable *const r0749 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0749, bit_and(r073F, body.constant(65535u)), 0x01));

   ir_variable *const r074A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r074A, rshift(r073F, body.constant(int(16))), 0x01));

   ir_variable *const r074B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r074B, bit_and(r0741, body.constant(65535u)), 0x01));

   ir_variable *const r074C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r074C, rshift(r0741, body.constant(int(16))), 0x01));

   ir_variable *const r074D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r074D, mul(r074A, r074B), 0x01));

   ir_expression *const r074E = mul(r0749, r074C);
   body.emit(assign(r0747, add(r074E, r074D), 0x01));

   ir_expression *const r074F = mul(r074A, r074C);
   ir_expression *const r0750 = less(r0747, r074D);
   ir_expression *const r0751 = expr(ir_unop_b2i, r0750);
   ir_expression *const r0752 = expr(ir_unop_i2u, r0751);
   ir_expression *const r0753 = lshift(r0752, body.constant(int(16)));
   ir_expression *const r0754 = rshift(r0747, body.constant(int(16)));
   ir_expression *const r0755 = add(r0753, r0754);
   body.emit(assign(r0746, add(r074F, r0755), 0x01));

   body.emit(assign(r0747, lshift(r0747, body.constant(int(16))), 0x01));

   ir_expression *const r0756 = mul(r0749, r074B);
   body.emit(assign(r0748, add(r0756, r0747), 0x01));

   ir_expression *const r0757 = less(r0748, r0747);
   ir_expression *const r0758 = expr(ir_unop_b2i, r0757);
   ir_expression *const r0759 = expr(ir_unop_i2u, r0758);
   body.emit(assign(r0746, add(r0746, r0759), 0x01));

   ir_variable *const r075A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r075A);
   ir_variable *const r075B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r075B);
   ir_variable *const r075C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r075C);
   ir_variable *const r075D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r075D, bit_and(r073F, body.constant(65535u)), 0x01));

   ir_variable *const r075E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r075E, rshift(r073F, body.constant(int(16))), 0x01));

   ir_variable *const r075F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r075F, bit_and(r0740, body.constant(65535u)), 0x01));

   ir_variable *const r0760 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0760, rshift(r0740, body.constant(int(16))), 0x01));

   ir_variable *const r0761 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0761, mul(r075E, r075F), 0x01));

   ir_expression *const r0762 = mul(r075D, r0760);
   body.emit(assign(r075B, add(r0762, r0761), 0x01));

   ir_expression *const r0763 = mul(r075E, r0760);
   ir_expression *const r0764 = less(r075B, r0761);
   ir_expression *const r0765 = expr(ir_unop_b2i, r0764);
   ir_expression *const r0766 = expr(ir_unop_i2u, r0765);
   ir_expression *const r0767 = lshift(r0766, body.constant(int(16)));
   ir_expression *const r0768 = rshift(r075B, body.constant(int(16)));
   ir_expression *const r0769 = add(r0767, r0768);
   body.emit(assign(r075A, add(r0763, r0769), 0x01));

   body.emit(assign(r075B, lshift(r075B, body.constant(int(16))), 0x01));

   ir_expression *const r076A = mul(r075D, r075F);
   body.emit(assign(r075C, add(r076A, r075B), 0x01));

   ir_expression *const r076B = less(r075C, r075B);
   ir_expression *const r076C = expr(ir_unop_b2i, r076B);
   ir_expression *const r076D = expr(ir_unop_i2u, r076C);
   body.emit(assign(r075A, add(r075A, r076D), 0x01));

   ir_variable *const r076E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076E, add(r075C, r0746), 0x01));

   ir_variable *const r076F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r076F);
   ir_variable *const r0770 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0770);
   ir_variable *const r0771 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0771);
   ir_variable *const r0772 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0772, bit_and(r073E, body.constant(65535u)), 0x01));

   ir_variable *const r0773 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0773, rshift(r073E, body.constant(int(16))), 0x01));

   ir_variable *const r0774 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0774, bit_and(r0740, body.constant(65535u)), 0x01));

   ir_variable *const r0775 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0775, rshift(r0740, body.constant(int(16))), 0x01));

   ir_variable *const r0776 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0776, mul(r0773, r0774), 0x01));

   ir_expression *const r0777 = mul(r0772, r0775);
   body.emit(assign(r0770, add(r0777, r0776), 0x01));

   ir_expression *const r0778 = mul(r0773, r0775);
   ir_expression *const r0779 = less(r0770, r0776);
   ir_expression *const r077A = expr(ir_unop_b2i, r0779);
   ir_expression *const r077B = expr(ir_unop_i2u, r077A);
   ir_expression *const r077C = lshift(r077B, body.constant(int(16)));
   ir_expression *const r077D = rshift(r0770, body.constant(int(16)));
   ir_expression *const r077E = add(r077C, r077D);
   body.emit(assign(r076F, add(r0778, r077E), 0x01));

   body.emit(assign(r0770, lshift(r0770, body.constant(int(16))), 0x01));

   ir_expression *const r077F = mul(r0772, r0774);
   body.emit(assign(r0771, add(r077F, r0770), 0x01));

   ir_expression *const r0780 = less(r0771, r0770);
   ir_expression *const r0781 = expr(ir_unop_b2i, r0780);
   ir_expression *const r0782 = expr(ir_unop_i2u, r0781);
   body.emit(assign(r076F, add(r076F, r0782), 0x01));

   ir_variable *const r0783 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0784 = less(r076E, r075C);
   ir_expression *const r0785 = expr(ir_unop_b2i, r0784);
   ir_expression *const r0786 = expr(ir_unop_i2u, r0785);
   ir_expression *const r0787 = add(r075A, r0786);
   body.emit(assign(r0783, add(r0771, r0787), 0x01));

   ir_variable *const r0788 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0788);
   ir_variable *const r0789 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0789);
   ir_variable *const r078A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r078A);
   ir_variable *const r078B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078B, bit_and(r073E, body.constant(65535u)), 0x01));

   ir_variable *const r078C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078C, rshift(r073E, body.constant(int(16))), 0x01));

   ir_variable *const r078D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078D, bit_and(r0741, body.constant(65535u)), 0x01));

   ir_variable *const r078E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078E, rshift(r0741, body.constant(int(16))), 0x01));

   ir_variable *const r078F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078F, mul(r078C, r078D), 0x01));

   ir_expression *const r0790 = mul(r078B, r078E);
   body.emit(assign(r0789, add(r0790, r078F), 0x01));

   ir_expression *const r0791 = mul(r078C, r078E);
   ir_expression *const r0792 = less(r0789, r078F);
   ir_expression *const r0793 = expr(ir_unop_b2i, r0792);
   ir_expression *const r0794 = expr(ir_unop_i2u, r0793);
   ir_expression *const r0795 = lshift(r0794, body.constant(int(16)));
   ir_expression *const r0796 = rshift(r0789, body.constant(int(16)));
   ir_expression *const r0797 = add(r0795, r0796);
   body.emit(assign(r0788, add(r0791, r0797), 0x01));

   body.emit(assign(r0789, lshift(r0789, body.constant(int(16))), 0x01));

   ir_expression *const r0798 = mul(r078B, r078D);
   body.emit(assign(r078A, add(r0798, r0789), 0x01));

   ir_expression *const r0799 = less(r078A, r0789);
   ir_expression *const r079A = expr(ir_unop_b2i, r0799);
   ir_expression *const r079B = expr(ir_unop_i2u, r079A);
   body.emit(assign(r0788, add(r0788, r079B), 0x01));

   ir_variable *const r079C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r079C, add(r078A, r076E), 0x01));

   ir_variable *const r079D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r079E = less(r079C, r078A);
   ir_expression *const r079F = expr(ir_unop_b2i, r079E);
   ir_expression *const r07A0 = expr(ir_unop_i2u, r079F);
   ir_expression *const r07A1 = add(r0788, r07A0);
   body.emit(assign(r079D, add(r0783, r07A1), 0x01));

   body.emit(assign(r0745, r0748, 0x01));

   body.emit(assign(r0744, r079C, 0x01));

   body.emit(assign(r0743, r079D, 0x01));

   ir_expression *const r07A2 = less(r0783, r0771);
   ir_expression *const r07A3 = expr(ir_unop_b2i, r07A2);
   ir_expression *const r07A4 = expr(ir_unop_i2u, r07A3);
   ir_expression *const r07A5 = add(r076F, r07A4);
   ir_expression *const r07A6 = less(r079D, r0783);
   ir_expression *const r07A7 = expr(ir_unop_b2i, r07A6);
   ir_expression *const r07A8 = expr(ir_unop_i2u, r07A7);
   body.emit(assign(r0742, add(r07A5, r07A8), 0x01));

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

   ir_variable *const r07A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r07A9);
   ir_variable *const r07AA = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r07AA);
   ir_variable *const r07AB = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r07AB);
   ir_variable *const r07AC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07AC);
   ir_variable *const r07AD = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07AD);
   ir_variable *const r07AE = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r07AE);
   /* IF CONDITION */
   ir_expression *const r07B0 = equal(r07A9, body.constant(0u));
   ir_if *f07AF = new(mem_ctx) ir_if(operand(r07B0).val);
   exec_list *const f07AF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07AF->then_instructions;

      ir_expression *const r07B1 = equal(r07AA, body.constant(0u));
      ir_expression *const r07B2 = expr(ir_unop_find_msb, r07AA);
      ir_expression *const r07B3 = sub(body.constant(int(31)), r07B2);
      ir_expression *const r07B4 = expr(ir_triop_csel, r07B1, body.constant(int(32)), r07B3);
      body.emit(assign(r07AE, add(r07B4, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r07B6 = less(r07AE, body.constant(int(0)));
      ir_if *f07B5 = new(mem_ctx) ir_if(operand(r07B6).val);
      exec_list *const f07B5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07B5->then_instructions;

         ir_expression *const r07B7 = neg(r07AE);
         body.emit(assign(r07AC, rshift(r07AA, r07B7), 0x01));

         ir_expression *const r07B8 = bit_and(r07AE, body.constant(int(31)));
         body.emit(assign(r07AD, lshift(r07AA, r07B8), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07B5->else_instructions;

         body.emit(assign(r07AC, lshift(r07AA, r07AE), 0x01));

         body.emit(assign(r07AD, body.constant(0u), 0x01));


      body.instructions = f07B5_parent_instructions;
      body.emit(f07B5);

      /* END IF */

      body.emit(assign(r07AB, sub(body.constant(int(-31)), r07AE), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07AF->else_instructions;

      ir_expression *const r07B9 = equal(r07A9, body.constant(0u));
      ir_expression *const r07BA = expr(ir_unop_find_msb, r07A9);
      ir_expression *const r07BB = sub(body.constant(int(31)), r07BA);
      ir_expression *const r07BC = expr(ir_triop_csel, r07B9, body.constant(int(32)), r07BB);
      body.emit(assign(r07AE, add(r07BC, body.constant(int(-11))), 0x01));

      ir_expression *const r07BD = equal(r07AE, body.constant(int(0)));
      ir_expression *const r07BE = lshift(r07A9, r07AE);
      ir_expression *const r07BF = neg(r07AE);
      ir_expression *const r07C0 = bit_and(r07BF, body.constant(int(31)));
      ir_expression *const r07C1 = rshift(r07AA, r07C0);
      ir_expression *const r07C2 = bit_or(r07BE, r07C1);
      body.emit(assign(r07AC, expr(ir_triop_csel, r07BD, r07A9, r07C2), 0x01));

      body.emit(assign(r07AD, lshift(r07AA, r07AE), 0x01));

      body.emit(assign(r07AB, sub(body.constant(int(1)), r07AE), 0x01));


   body.instructions = f07AF_parent_instructions;
   body.emit(f07AF);

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

   ir_variable *const r07C3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r07C3);
   ir_variable *const r07C4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r07C4);
   ir_variable *const r07C5 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r07C5, body.constant(true), 0x01));

   ir_variable *const r07C6 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r07C7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r07C7);
   ir_variable *const r07C8 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r07C8);
   ir_variable *const r07C9 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r07C9);
   ir_variable *const r07CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r07CA);
   ir_variable *const r07CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r07CB);
   ir_variable *const r07CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r07CC);
   ir_variable *const r07CD = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r07CD);
   ir_variable *const r07CE = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r07CE);
   ir_variable *const r07CF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r07CF);
   ir_variable *const r07D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r07D0);
   ir_variable *const r07D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r07D1);
   body.emit(assign(r07D1, body.constant(0u), 0x01));

   body.emit(assign(r07D0, body.constant(0u), 0x01));

   body.emit(assign(r07CF, body.constant(0u), 0x01));

   ir_variable *const r07D2 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r07D2, swizzle_x(r07C3), 0x01));

   body.emit(assign(r07CD, r07D2, 0x01));

   ir_variable *const r07D3 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r07D3, bit_and(swizzle_y(r07C3), body.constant(1048575u)), 0x01));

   body.emit(assign(r07CC, r07D3, 0x01));

   ir_variable *const r07D4 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r07D4, swizzle_x(r07C4), 0x01));

   body.emit(assign(r07CB, r07D4, 0x01));

   ir_variable *const r07D5 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r07D5, bit_and(swizzle_y(r07C4), body.constant(1048575u)), 0x01));

   body.emit(assign(r07CA, r07D5, 0x01));

   ir_variable *const r07D6 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r07D7 = rshift(swizzle_y(r07C3), body.constant(int(20)));
   ir_expression *const r07D8 = bit_and(r07D7, body.constant(2047u));
   body.emit(assign(r07D6, expr(ir_unop_u2i, r07D8), 0x01));

   body.emit(assign(r07C9, r07D6, 0x01));

   ir_variable *const r07D9 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r07DA = rshift(swizzle_y(r07C4), body.constant(int(20)));
   ir_expression *const r07DB = bit_and(r07DA, body.constant(2047u));
   body.emit(assign(r07D9, expr(ir_unop_u2i, r07DB), 0x01));

   body.emit(assign(r07C8, r07D9, 0x01));

   ir_expression *const r07DC = rshift(swizzle_y(r07C3), body.constant(int(31)));
   ir_expression *const r07DD = rshift(swizzle_y(r07C4), body.constant(int(31)));
   body.emit(assign(r07C7, bit_xor(r07DC, r07DD), 0x01));

   /* IF CONDITION */
   ir_expression *const r07DF = equal(r07D6, body.constant(int(2047)));
   ir_if *f07DE = new(mem_ctx) ir_if(operand(r07DF).val);
   exec_list *const f07DE_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07DE->then_instructions;

      /* IF CONDITION */
      ir_expression *const r07E1 = bit_or(r07D3, swizzle_x(r07C3));
      ir_expression *const r07E2 = nequal(r07E1, body.constant(0u));
      ir_expression *const r07E3 = equal(r07D9, body.constant(int(2047)));
      ir_expression *const r07E4 = bit_or(r07D5, swizzle_x(r07C4));
      ir_expression *const r07E5 = nequal(r07E4, body.constant(0u));
      ir_expression *const r07E6 = logic_and(r07E3, r07E5);
      ir_expression *const r07E7 = logic_or(r07E2, r07E6);
      ir_if *f07E0 = new(mem_ctx) ir_if(operand(r07E7).val);
      exec_list *const f07E0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07E0->then_instructions;

         ir_variable *const r07E8 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r07E8, swizzle_x(r07C3), 0x01));

         ir_variable *const r07E9 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r07E9, swizzle_x(r07C4), 0x01));

         body.emit(assign(r07E8, bit_or(swizzle_y(r07C3), body.constant(524288u)), 0x02));

         body.emit(assign(r07E9, bit_or(swizzle_y(r07C4), body.constant(524288u)), 0x02));

         ir_expression *const r07EA = lshift(swizzle_y(r07C3), body.constant(int(1)));
         ir_expression *const r07EB = gequal(r07EA, body.constant(4292870144u));
         ir_expression *const r07EC = nequal(swizzle_x(r07C3), body.constant(0u));
         ir_expression *const r07ED = bit_and(swizzle_y(r07C3), body.constant(1048575u));
         ir_expression *const r07EE = nequal(r07ED, body.constant(0u));
         ir_expression *const r07EF = logic_or(r07EC, r07EE);
         ir_expression *const r07F0 = logic_and(r07EB, r07EF);
         ir_swizzle *const r07F1 = swizzle(r07F0, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r07F2 = lshift(swizzle_y(r07C4), body.constant(int(1)));
         ir_expression *const r07F3 = gequal(r07F2, body.constant(4292870144u));
         ir_expression *const r07F4 = nequal(swizzle_x(r07C4), body.constant(0u));
         ir_expression *const r07F5 = bit_and(swizzle_y(r07C4), body.constant(1048575u));
         ir_expression *const r07F6 = nequal(r07F5, body.constant(0u));
         ir_expression *const r07F7 = logic_or(r07F4, r07F6);
         ir_expression *const r07F8 = logic_and(r07F3, r07F7);
         ir_swizzle *const r07F9 = swizzle(r07F8, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r07FA = expr(ir_triop_csel, r07F9, r07E9, r07E8);
         body.emit(assign(r07C6, expr(ir_triop_csel, r07F1, r07FA, r07E9), 0x03));

         body.emit(assign(r07C5, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07E0->else_instructions;

         /* IF CONDITION */
         ir_expression *const r07FC = expr(ir_unop_i2u, r07D9);
         ir_expression *const r07FD = bit_or(r07FC, r07D5);
         ir_expression *const r07FE = bit_or(r07FD, swizzle_x(r07C4));
         ir_expression *const r07FF = equal(r07FE, body.constant(0u));
         ir_if *f07FB = new(mem_ctx) ir_if(operand(r07FF).val);
         exec_list *const f07FB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07FB->then_instructions;

            ir_constant_data r0800_data;
            memset(&r0800_data, 0, sizeof(ir_constant_data));
            r0800_data.u[0] = 4294967295;
            r0800_data.u[1] = 4294967295;
            ir_constant *const r0800 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0800_data);
            body.emit(assign(r07C6, r0800, 0x03));

            body.emit(assign(r07C5, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f07FB->else_instructions;

            ir_variable *const r0801 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0801);
            ir_expression *const r0802 = lshift(r07C7, body.constant(int(31)));
            body.emit(assign(r0801, add(r0802, body.constant(2146435072u)), 0x02));

            body.emit(assign(r0801, body.constant(0u), 0x01));

            body.emit(assign(r07C6, r0801, 0x03));

            body.emit(assign(r07C5, body.constant(false), 0x01));


         body.instructions = f07FB_parent_instructions;
         body.emit(f07FB);

         /* END IF */


      body.instructions = f07E0_parent_instructions;
      body.emit(f07E0);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07DE->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0804 = equal(r07D9, body.constant(int(2047)));
      ir_if *f0803 = new(mem_ctx) ir_if(operand(r0804).val);
      exec_list *const f0803_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0803->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0806 = bit_or(r07D5, swizzle_x(r07C4));
         ir_expression *const r0807 = nequal(r0806, body.constant(0u));
         ir_if *f0805 = new(mem_ctx) ir_if(operand(r0807).val);
         exec_list *const f0805_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0805->then_instructions;

            ir_variable *const r0808 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0808, swizzle_x(r07C3), 0x01));

            ir_variable *const r0809 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0809, swizzle_x(r07C4), 0x01));

            body.emit(assign(r0808, bit_or(swizzle_y(r07C3), body.constant(524288u)), 0x02));

            body.emit(assign(r0809, bit_or(swizzle_y(r07C4), body.constant(524288u)), 0x02));

            ir_expression *const r080A = lshift(swizzle_y(r07C3), body.constant(int(1)));
            ir_expression *const r080B = gequal(r080A, body.constant(4292870144u));
            ir_expression *const r080C = nequal(swizzle_x(r07C3), body.constant(0u));
            ir_expression *const r080D = bit_and(swizzle_y(r07C3), body.constant(1048575u));
            ir_expression *const r080E = nequal(r080D, body.constant(0u));
            ir_expression *const r080F = logic_or(r080C, r080E);
            ir_expression *const r0810 = logic_and(r080B, r080F);
            ir_swizzle *const r0811 = swizzle(r0810, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0812 = lshift(swizzle_y(r07C4), body.constant(int(1)));
            ir_expression *const r0813 = gequal(r0812, body.constant(4292870144u));
            ir_expression *const r0814 = nequal(swizzle_x(r07C4), body.constant(0u));
            ir_expression *const r0815 = bit_and(swizzle_y(r07C4), body.constant(1048575u));
            ir_expression *const r0816 = nequal(r0815, body.constant(0u));
            ir_expression *const r0817 = logic_or(r0814, r0816);
            ir_expression *const r0818 = logic_and(r0813, r0817);
            ir_swizzle *const r0819 = swizzle(r0818, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r081A = expr(ir_triop_csel, r0819, r0809, r0808);
            body.emit(assign(r07C6, expr(ir_triop_csel, r0811, r081A, r0809), 0x03));

            body.emit(assign(r07C5, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0805->else_instructions;

            /* IF CONDITION */
            ir_expression *const r081C = expr(ir_unop_i2u, r07D6);
            ir_expression *const r081D = bit_or(r081C, r07D3);
            ir_expression *const r081E = bit_or(r081D, swizzle_x(r07C3));
            ir_expression *const r081F = equal(r081E, body.constant(0u));
            ir_if *f081B = new(mem_ctx) ir_if(operand(r081F).val);
            exec_list *const f081B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f081B->then_instructions;

               ir_constant_data r0820_data;
               memset(&r0820_data, 0, sizeof(ir_constant_data));
               r0820_data.u[0] = 4294967295;
               r0820_data.u[1] = 4294967295;
               ir_constant *const r0820 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0820_data);
               body.emit(assign(r07C6, r0820, 0x03));

               body.emit(assign(r07C5, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f081B->else_instructions;

               ir_variable *const r0821 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0821);
               ir_expression *const r0822 = lshift(r07C7, body.constant(int(31)));
               body.emit(assign(r0821, add(r0822, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0821, body.constant(0u), 0x01));

               body.emit(assign(r07C6, r0821, 0x03));

               body.emit(assign(r07C5, body.constant(false), 0x01));


            body.instructions = f081B_parent_instructions;
            body.emit(f081B);

            /* END IF */


         body.instructions = f0805_parent_instructions;
         body.emit(f0805);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0803->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0824 = equal(r07D6, body.constant(int(0)));
         ir_if *f0823 = new(mem_ctx) ir_if(operand(r0824).val);
         exec_list *const f0823_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0823->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0826 = bit_or(r07D3, swizzle_x(r07C3));
            ir_expression *const r0827 = equal(r0826, body.constant(0u));
            ir_if *f0825 = new(mem_ctx) ir_if(operand(r0827).val);
            exec_list *const f0825_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0825->then_instructions;

               ir_variable *const r0828 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0828);
               body.emit(assign(r0828, lshift(r07C7, body.constant(int(31))), 0x02));

               body.emit(assign(r0828, body.constant(0u), 0x01));

               body.emit(assign(r07C6, r0828, 0x03));

               body.emit(assign(r07C5, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0825->else_instructions;

               ir_variable *const r0829 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r0829, r07D6, 0x01));

               ir_variable *const r082A = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r082A, r07D3, 0x01));

               ir_variable *const r082B = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r082B, r07D2, 0x01));

               ir_variable *const r082C = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r082C);
               /* IF CONDITION */
               ir_expression *const r082E = equal(r07D3, body.constant(0u));
               ir_if *f082D = new(mem_ctx) ir_if(operand(r082E).val);
               exec_list *const f082D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f082D->then_instructions;

                  ir_expression *const r082F = equal(swizzle_x(r07C3), body.constant(0u));
                  ir_expression *const r0830 = expr(ir_unop_find_msb, swizzle_x(r07C3));
                  ir_expression *const r0831 = sub(body.constant(int(31)), r0830);
                  ir_expression *const r0832 = expr(ir_triop_csel, r082F, body.constant(int(32)), r0831);
                  body.emit(assign(r082C, add(r0832, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0834 = less(r082C, body.constant(int(0)));
                  ir_if *f0833 = new(mem_ctx) ir_if(operand(r0834).val);
                  exec_list *const f0833_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0833->then_instructions;

                     ir_expression *const r0835 = neg(r082C);
                     body.emit(assign(r082A, rshift(swizzle_x(r07C3), r0835), 0x01));

                     ir_expression *const r0836 = bit_and(r082C, body.constant(int(31)));
                     body.emit(assign(r082B, lshift(swizzle_x(r07C3), r0836), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0833->else_instructions;

                     body.emit(assign(r082A, lshift(swizzle_x(r07C3), r082C), 0x01));

                     body.emit(assign(r082B, body.constant(0u), 0x01));


                  body.instructions = f0833_parent_instructions;
                  body.emit(f0833);

                  /* END IF */

                  body.emit(assign(r0829, sub(body.constant(int(-31)), r082C), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f082D->else_instructions;

                  ir_expression *const r0837 = equal(r07D3, body.constant(0u));
                  ir_expression *const r0838 = expr(ir_unop_find_msb, r07D3);
                  ir_expression *const r0839 = sub(body.constant(int(31)), r0838);
                  ir_expression *const r083A = expr(ir_triop_csel, r0837, body.constant(int(32)), r0839);
                  body.emit(assign(r082C, add(r083A, body.constant(int(-11))), 0x01));

                  ir_expression *const r083B = equal(r082C, body.constant(int(0)));
                  ir_expression *const r083C = lshift(r07D3, r082C);
                  ir_expression *const r083D = neg(r082C);
                  ir_expression *const r083E = bit_and(r083D, body.constant(int(31)));
                  ir_expression *const r083F = rshift(swizzle_x(r07C3), r083E);
                  ir_expression *const r0840 = bit_or(r083C, r083F);
                  body.emit(assign(r082A, expr(ir_triop_csel, r083B, r07D3, r0840), 0x01));

                  body.emit(assign(r082B, lshift(swizzle_x(r07C3), r082C), 0x01));

                  body.emit(assign(r0829, sub(body.constant(int(1)), r082C), 0x01));


               body.instructions = f082D_parent_instructions;
               body.emit(f082D);

               /* END IF */

               body.emit(assign(r07C9, r0829, 0x01));

               body.emit(assign(r07CC, r082A, 0x01));

               body.emit(assign(r07CD, r082B, 0x01));


            body.instructions = f0825_parent_instructions;
            body.emit(f0825);

            /* END IF */


         body.instructions = f0823_parent_instructions;
         body.emit(f0823);

         /* END IF */

         /* IF CONDITION */
         ir_if *f0841 = new(mem_ctx) ir_if(operand(r07C5).val);
         exec_list *const f0841_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0841->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0843 = equal(r07D9, body.constant(int(0)));
            ir_if *f0842 = new(mem_ctx) ir_if(operand(r0843).val);
            exec_list *const f0842_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0842->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0845 = bit_or(r07D5, swizzle_x(r07C4));
               ir_expression *const r0846 = equal(r0845, body.constant(0u));
               ir_if *f0844 = new(mem_ctx) ir_if(operand(r0846).val);
               exec_list *const f0844_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0844->then_instructions;

                  ir_variable *const r0847 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0847);
                  body.emit(assign(r0847, lshift(r07C7, body.constant(int(31))), 0x02));

                  body.emit(assign(r0847, body.constant(0u), 0x01));

                  body.emit(assign(r07C6, r0847, 0x03));

                  body.emit(assign(r07C5, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0844->else_instructions;

                  ir_variable *const r0848 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r0848, r07D9, 0x01));

                  ir_variable *const r0849 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r0849, r07D5, 0x01));

                  ir_variable *const r084A = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r084A, r07D4, 0x01));

                  ir_variable *const r084B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r084B);
                  /* IF CONDITION */
                  ir_expression *const r084D = equal(r07D5, body.constant(0u));
                  ir_if *f084C = new(mem_ctx) ir_if(operand(r084D).val);
                  exec_list *const f084C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f084C->then_instructions;

                     ir_expression *const r084E = equal(swizzle_x(r07C4), body.constant(0u));
                     ir_expression *const r084F = expr(ir_unop_find_msb, swizzle_x(r07C4));
                     ir_expression *const r0850 = sub(body.constant(int(31)), r084F);
                     ir_expression *const r0851 = expr(ir_triop_csel, r084E, body.constant(int(32)), r0850);
                     body.emit(assign(r084B, add(r0851, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0853 = less(r084B, body.constant(int(0)));
                     ir_if *f0852 = new(mem_ctx) ir_if(operand(r0853).val);
                     exec_list *const f0852_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0852->then_instructions;

                        ir_expression *const r0854 = neg(r084B);
                        body.emit(assign(r0849, rshift(swizzle_x(r07C4), r0854), 0x01));

                        ir_expression *const r0855 = bit_and(r084B, body.constant(int(31)));
                        body.emit(assign(r084A, lshift(swizzle_x(r07C4), r0855), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0852->else_instructions;

                        body.emit(assign(r0849, lshift(swizzle_x(r07C4), r084B), 0x01));

                        body.emit(assign(r084A, body.constant(0u), 0x01));


                     body.instructions = f0852_parent_instructions;
                     body.emit(f0852);

                     /* END IF */

                     body.emit(assign(r0848, sub(body.constant(int(-31)), r084B), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f084C->else_instructions;

                     ir_expression *const r0856 = equal(r07D5, body.constant(0u));
                     ir_expression *const r0857 = expr(ir_unop_find_msb, r07D5);
                     ir_expression *const r0858 = sub(body.constant(int(31)), r0857);
                     ir_expression *const r0859 = expr(ir_triop_csel, r0856, body.constant(int(32)), r0858);
                     body.emit(assign(r084B, add(r0859, body.constant(int(-11))), 0x01));

                     ir_expression *const r085A = equal(r084B, body.constant(int(0)));
                     ir_expression *const r085B = lshift(r07D5, r084B);
                     ir_expression *const r085C = neg(r084B);
                     ir_expression *const r085D = bit_and(r085C, body.constant(int(31)));
                     ir_expression *const r085E = rshift(swizzle_x(r07C4), r085D);
                     ir_expression *const r085F = bit_or(r085B, r085E);
                     body.emit(assign(r0849, expr(ir_triop_csel, r085A, r07D5, r085F), 0x01));

                     body.emit(assign(r084A, lshift(swizzle_x(r07C4), r084B), 0x01));

                     body.emit(assign(r0848, sub(body.constant(int(1)), r084B), 0x01));


                  body.instructions = f084C_parent_instructions;
                  body.emit(f084C);

                  /* END IF */

                  body.emit(assign(r07C8, r0848, 0x01));

                  body.emit(assign(r07CA, r0849, 0x01));

                  body.emit(assign(r07CB, r084A, 0x01));


               body.instructions = f0844_parent_instructions;
               body.emit(f0844);

               /* END IF */


            body.instructions = f0842_parent_instructions;
            body.emit(f0842);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0860 = new(mem_ctx) ir_if(operand(r07C5).val);
            exec_list *const f0860_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0860->then_instructions;

               ir_expression *const r0861 = add(r07C9, r07C8);
               body.emit(assign(r07CE, add(r0861, body.constant(int(-1024))), 0x01));

               body.emit(assign(r07CC, bit_or(r07CC, body.constant(1048576u)), 0x01));

               ir_variable *const r0862 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0863 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0863, lshift(r07CB, body.constant(int(12))), 0x01));

               ir_expression *const r0864 = lshift(r07CA, body.constant(int(12)));
               ir_expression *const r0865 = rshift(r07CB, body.constant(int(20)));
               body.emit(assign(r0862, bit_or(r0864, r0865), 0x01));

               body.emit(assign(r07CA, r0862, 0x01));

               body.emit(assign(r07CB, r0863, 0x01));

               ir_variable *const r0866 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0866);
               ir_variable *const r0867 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0867);
               ir_variable *const r0868 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0868);
               ir_variable *const r0869 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0869, bit_and(r07CD, body.constant(65535u)), 0x01));

               ir_variable *const r086A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r086A, rshift(r07CD, body.constant(int(16))), 0x01));

               ir_variable *const r086B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r086B, bit_and(r0863, body.constant(65535u)), 0x01));

               ir_variable *const r086C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r086C, rshift(r0863, body.constant(int(16))), 0x01));

               ir_variable *const r086D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r086D, mul(r086A, r086B), 0x01));

               ir_expression *const r086E = mul(r0869, r086C);
               body.emit(assign(r0867, add(r086E, r086D), 0x01));

               ir_expression *const r086F = mul(r086A, r086C);
               ir_expression *const r0870 = less(r0867, r086D);
               ir_expression *const r0871 = expr(ir_unop_b2i, r0870);
               ir_expression *const r0872 = expr(ir_unop_i2u, r0871);
               ir_expression *const r0873 = lshift(r0872, body.constant(int(16)));
               ir_expression *const r0874 = rshift(r0867, body.constant(int(16)));
               ir_expression *const r0875 = add(r0873, r0874);
               body.emit(assign(r0866, add(r086F, r0875), 0x01));

               body.emit(assign(r0867, lshift(r0867, body.constant(int(16))), 0x01));

               ir_expression *const r0876 = mul(r0869, r086B);
               body.emit(assign(r0868, add(r0876, r0867), 0x01));

               ir_expression *const r0877 = less(r0868, r0867);
               ir_expression *const r0878 = expr(ir_unop_b2i, r0877);
               ir_expression *const r0879 = expr(ir_unop_i2u, r0878);
               body.emit(assign(r0866, add(r0866, r0879), 0x01));

               ir_variable *const r087A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r087A);
               ir_variable *const r087B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r087B);
               ir_variable *const r087C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r087C);
               ir_variable *const r087D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r087D, bit_and(r07CD, body.constant(65535u)), 0x01));

               ir_variable *const r087E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r087E, rshift(r07CD, body.constant(int(16))), 0x01));

               ir_variable *const r087F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r087F, bit_and(r0862, body.constant(65535u)), 0x01));

               ir_variable *const r0880 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0880, rshift(r0862, body.constant(int(16))), 0x01));

               ir_variable *const r0881 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0881, mul(r087E, r087F), 0x01));

               ir_expression *const r0882 = mul(r087D, r0880);
               body.emit(assign(r087B, add(r0882, r0881), 0x01));

               ir_expression *const r0883 = mul(r087E, r0880);
               ir_expression *const r0884 = less(r087B, r0881);
               ir_expression *const r0885 = expr(ir_unop_b2i, r0884);
               ir_expression *const r0886 = expr(ir_unop_i2u, r0885);
               ir_expression *const r0887 = lshift(r0886, body.constant(int(16)));
               ir_expression *const r0888 = rshift(r087B, body.constant(int(16)));
               ir_expression *const r0889 = add(r0887, r0888);
               body.emit(assign(r087A, add(r0883, r0889), 0x01));

               body.emit(assign(r087B, lshift(r087B, body.constant(int(16))), 0x01));

               ir_expression *const r088A = mul(r087D, r087F);
               body.emit(assign(r087C, add(r088A, r087B), 0x01));

               ir_expression *const r088B = less(r087C, r087B);
               ir_expression *const r088C = expr(ir_unop_b2i, r088B);
               ir_expression *const r088D = expr(ir_unop_i2u, r088C);
               body.emit(assign(r087A, add(r087A, r088D), 0x01));

               ir_variable *const r088E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r088E, add(r087C, r0866), 0x01));

               ir_variable *const r088F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r088F);
               ir_variable *const r0890 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0890);
               ir_variable *const r0891 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0891);
               ir_variable *const r0892 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0892, bit_and(r07CC, body.constant(65535u)), 0x01));

               ir_variable *const r0893 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0893, rshift(r07CC, body.constant(int(16))), 0x01));

               ir_variable *const r0894 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0894, bit_and(r0862, body.constant(65535u)), 0x01));

               ir_variable *const r0895 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0895, rshift(r0862, body.constant(int(16))), 0x01));

               ir_variable *const r0896 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0896, mul(r0893, r0894), 0x01));

               ir_expression *const r0897 = mul(r0892, r0895);
               body.emit(assign(r0890, add(r0897, r0896), 0x01));

               ir_expression *const r0898 = mul(r0893, r0895);
               ir_expression *const r0899 = less(r0890, r0896);
               ir_expression *const r089A = expr(ir_unop_b2i, r0899);
               ir_expression *const r089B = expr(ir_unop_i2u, r089A);
               ir_expression *const r089C = lshift(r089B, body.constant(int(16)));
               ir_expression *const r089D = rshift(r0890, body.constant(int(16)));
               ir_expression *const r089E = add(r089C, r089D);
               body.emit(assign(r088F, add(r0898, r089E), 0x01));

               body.emit(assign(r0890, lshift(r0890, body.constant(int(16))), 0x01));

               ir_expression *const r089F = mul(r0892, r0894);
               body.emit(assign(r0891, add(r089F, r0890), 0x01));

               ir_expression *const r08A0 = less(r0891, r0890);
               ir_expression *const r08A1 = expr(ir_unop_b2i, r08A0);
               ir_expression *const r08A2 = expr(ir_unop_i2u, r08A1);
               body.emit(assign(r088F, add(r088F, r08A2), 0x01));

               ir_variable *const r08A3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r08A4 = less(r088E, r087C);
               ir_expression *const r08A5 = expr(ir_unop_b2i, r08A4);
               ir_expression *const r08A6 = expr(ir_unop_i2u, r08A5);
               ir_expression *const r08A7 = add(r087A, r08A6);
               body.emit(assign(r08A3, add(r0891, r08A7), 0x01));

               ir_variable *const r08A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r08A8);
               ir_variable *const r08A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r08A9);
               ir_variable *const r08AA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r08AA);
               ir_variable *const r08AB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08AB, bit_and(r07CC, body.constant(65535u)), 0x01));

               ir_variable *const r08AC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08AC, rshift(r07CC, body.constant(int(16))), 0x01));

               ir_variable *const r08AD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08AD, bit_and(r0863, body.constant(65535u)), 0x01));

               ir_variable *const r08AE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08AE, rshift(r0863, body.constant(int(16))), 0x01));

               ir_variable *const r08AF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08AF, mul(r08AC, r08AD), 0x01));

               ir_expression *const r08B0 = mul(r08AB, r08AE);
               body.emit(assign(r08A9, add(r08B0, r08AF), 0x01));

               ir_expression *const r08B1 = mul(r08AC, r08AE);
               ir_expression *const r08B2 = less(r08A9, r08AF);
               ir_expression *const r08B3 = expr(ir_unop_b2i, r08B2);
               ir_expression *const r08B4 = expr(ir_unop_i2u, r08B3);
               ir_expression *const r08B5 = lshift(r08B4, body.constant(int(16)));
               ir_expression *const r08B6 = rshift(r08A9, body.constant(int(16)));
               ir_expression *const r08B7 = add(r08B5, r08B6);
               body.emit(assign(r08A8, add(r08B1, r08B7), 0x01));

               body.emit(assign(r08A9, lshift(r08A9, body.constant(int(16))), 0x01));

               ir_expression *const r08B8 = mul(r08AB, r08AD);
               body.emit(assign(r08AA, add(r08B8, r08A9), 0x01));

               ir_expression *const r08B9 = less(r08AA, r08A9);
               ir_expression *const r08BA = expr(ir_unop_b2i, r08B9);
               ir_expression *const r08BB = expr(ir_unop_i2u, r08BA);
               body.emit(assign(r08A8, add(r08A8, r08BB), 0x01));

               ir_variable *const r08BC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08BC, add(r08AA, r088E), 0x01));

               ir_variable *const r08BD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r08BE = less(r08BC, r08AA);
               ir_expression *const r08BF = expr(ir_unop_b2i, r08BE);
               ir_expression *const r08C0 = expr(ir_unop_i2u, r08BF);
               ir_expression *const r08C1 = add(r08A8, r08C0);
               body.emit(assign(r08BD, add(r08A3, r08C1), 0x01));

               ir_variable *const r08C2 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r08C3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08C3, add(r08BD, r07CD), 0x01));

               ir_expression *const r08C4 = less(r08A3, r0891);
               ir_expression *const r08C5 = expr(ir_unop_b2i, r08C4);
               ir_expression *const r08C6 = expr(ir_unop_i2u, r08C5);
               ir_expression *const r08C7 = add(r088F, r08C6);
               ir_expression *const r08C8 = less(r08BD, r08A3);
               ir_expression *const r08C9 = expr(ir_unop_b2i, r08C8);
               ir_expression *const r08CA = expr(ir_unop_i2u, r08C9);
               ir_expression *const r08CB = add(r08C7, r08CA);
               ir_expression *const r08CC = add(r08CB, r07CC);
               ir_expression *const r08CD = less(r08C3, r08BD);
               ir_expression *const r08CE = expr(ir_unop_b2i, r08CD);
               ir_expression *const r08CF = expr(ir_unop_i2u, r08CE);
               body.emit(assign(r08C2, add(r08CC, r08CF), 0x01));

               body.emit(assign(r07D1, r08C2, 0x01));

               body.emit(assign(r07D0, r08C3, 0x01));

               ir_expression *const r08D0 = nequal(r0868, body.constant(0u));
               ir_expression *const r08D1 = expr(ir_unop_b2i, r08D0);
               ir_expression *const r08D2 = expr(ir_unop_i2u, r08D1);
               body.emit(assign(r07CF, bit_or(r08BC, r08D2), 0x01));

               /* IF CONDITION */
               ir_expression *const r08D4 = gequal(r08C2, body.constant(2097152u));
               ir_if *f08D3 = new(mem_ctx) ir_if(operand(r08D4).val);
               exec_list *const f08D3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08D3->then_instructions;

                  ir_variable *const r08D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r08D5);
                  body.emit(assign(r08D5, lshift(r08C3, body.constant(int(31))), 0x01));

                  ir_expression *const r08D6 = nequal(r07CF, body.constant(0u));
                  ir_expression *const r08D7 = expr(ir_unop_b2i, r08D6);
                  ir_expression *const r08D8 = expr(ir_unop_i2u, r08D7);
                  body.emit(assign(r08D5, bit_or(r08D5, r08D8), 0x01));

                  body.emit(assign(r07D1, rshift(r08C2, body.constant(int(1))), 0x01));

                  ir_expression *const r08D9 = lshift(r08C2, body.constant(int(31)));
                  ir_expression *const r08DA = rshift(r08C3, body.constant(int(1)));
                  body.emit(assign(r07D0, bit_or(r08D9, r08DA), 0x01));

                  body.emit(assign(r07CF, r08D5, 0x01));

                  body.emit(assign(r07CE, add(r07CE, body.constant(int(1))), 0x01));


               body.instructions = f08D3_parent_instructions;
               body.emit(f08D3);

               /* END IF */

               ir_variable *const r08DB = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r08DB, r07CE, 0x01));

               ir_variable *const r08DC = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r08DC, r07D1, 0x01));

               ir_variable *const r08DD = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r08DD, r07D0, 0x01));

               ir_variable *const r08DE = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r08DE, r07CF, 0x01));

               ir_variable *const r08DF = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r08DF, body.constant(true), 0x01));

               ir_variable *const r08E0 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r08E1 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r08E1);
               ir_expression *const r08E2 = expr(ir_unop_u2i, r07CF);
               body.emit(assign(r08E1, less(r08E2, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r08E4 = gequal(r07CE, body.constant(int(2045)));
               ir_if *f08E3 = new(mem_ctx) ir_if(operand(r08E4).val);
               exec_list *const f08E3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08E3->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r08E6 = less(body.constant(int(2045)), r07CE);
                  ir_expression *const r08E7 = equal(r07CE, body.constant(int(2045)));
                  ir_expression *const r08E8 = equal(body.constant(2097151u), r07D1);
                  ir_expression *const r08E9 = equal(body.constant(4294967295u), r07D0);
                  ir_expression *const r08EA = logic_and(r08E8, r08E9);
                  ir_expression *const r08EB = logic_and(r08E7, r08EA);
                  ir_expression *const r08EC = logic_and(r08EB, r08E1);
                  ir_expression *const r08ED = logic_or(r08E6, r08EC);
                  ir_if *f08E5 = new(mem_ctx) ir_if(operand(r08ED).val);
                  exec_list *const f08E5_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08E5->then_instructions;

                     ir_variable *const r08EE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r08EE);
                     ir_expression *const r08EF = lshift(r07C7, body.constant(int(31)));
                     body.emit(assign(r08EE, add(r08EF, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r08EE, body.constant(0u), 0x01));

                     body.emit(assign(r08E0, r08EE, 0x03));

                     body.emit(assign(r08DF, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08E5->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r08F1 = less(r07CE, body.constant(int(0)));
                     ir_if *f08F0 = new(mem_ctx) ir_if(operand(r08F1).val);
                     exec_list *const f08F0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F0->then_instructions;

                        ir_variable *const r08F2 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r08F2, r07CF, 0x01));

                        ir_variable *const r08F3 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r08F3, neg(r07CE), 0x01));

                        ir_variable *const r08F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r08F4);
                        ir_variable *const r08F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r08F5);
                        ir_variable *const r08F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r08F6);
                        ir_variable *const r08F7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r08F8 = neg(r08F3);
                        body.emit(assign(r08F7, bit_and(r08F8, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08FA = equal(r08F3, body.constant(int(0)));
                        ir_if *f08F9 = new(mem_ctx) ir_if(operand(r08FA).val);
                        exec_list *const f08F9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08F9->then_instructions;

                           body.emit(assign(r08F4, r07CF, 0x01));

                           body.emit(assign(r08F5, r07D0, 0x01));

                           body.emit(assign(r08F6, r07D1, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f08F9->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r08FC = less(r08F3, body.constant(int(32)));
                           ir_if *f08FB = new(mem_ctx) ir_if(operand(r08FC).val);
                           exec_list *const f08FB_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f08FB->then_instructions;

                              body.emit(assign(r08F4, lshift(r07D0, r08F7), 0x01));

                              ir_expression *const r08FD = lshift(r07D1, r08F7);
                              ir_expression *const r08FE = rshift(r07D0, r08F3);
                              body.emit(assign(r08F5, bit_or(r08FD, r08FE), 0x01));

                              body.emit(assign(r08F6, rshift(r07D1, r08F3), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f08FB->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0900 = equal(r08F3, body.constant(int(32)));
                              ir_if *f08FF = new(mem_ctx) ir_if(operand(r0900).val);
                              exec_list *const f08FF_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f08FF->then_instructions;

                                 body.emit(assign(r08F4, r07D0, 0x01));

                                 body.emit(assign(r08F5, r07D1, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f08FF->else_instructions;

                                 body.emit(assign(r08F2, bit_or(r07CF, r07D0), 0x01));

                                 ir_expression *const r0901 = less(r08F3, body.constant(int(64)));
                                 ir_expression *const r0902 = lshift(r07D1, r08F7);
                                 ir_expression *const r0903 = equal(r08F3, body.constant(int(64)));
                                 ir_expression *const r0904 = nequal(r07D1, body.constant(0u));
                                 ir_expression *const r0905 = expr(ir_unop_b2i, r0904);
                                 ir_expression *const r0906 = expr(ir_unop_i2u, r0905);
                                 ir_expression *const r0907 = expr(ir_triop_csel, r0903, r07D1, r0906);
                                 body.emit(assign(r08F4, expr(ir_triop_csel, r0901, r0902, r0907), 0x01));

                                 ir_expression *const r0908 = less(r08F3, body.constant(int(64)));
                                 ir_expression *const r0909 = bit_and(r08F3, body.constant(int(31)));
                                 ir_expression *const r090A = rshift(r07D1, r0909);
                                 body.emit(assign(r08F5, expr(ir_triop_csel, r0908, r090A, body.constant(0u)), 0x01));


                              body.instructions = f08FF_parent_instructions;
                              body.emit(f08FF);

                              /* END IF */

                              body.emit(assign(r08F6, body.constant(0u), 0x01));


                           body.instructions = f08FB_parent_instructions;
                           body.emit(f08FB);

                           /* END IF */

                           ir_expression *const r090B = nequal(r08F2, body.constant(0u));
                           ir_expression *const r090C = expr(ir_unop_b2i, r090B);
                           ir_expression *const r090D = expr(ir_unop_i2u, r090C);
                           body.emit(assign(r08F4, bit_or(r08F4, r090D), 0x01));


                        body.instructions = f08F9_parent_instructions;
                        body.emit(f08F9);

                        /* END IF */

                        body.emit(assign(r08DC, r08F6, 0x01));

                        body.emit(assign(r08DD, r08F5, 0x01));

                        body.emit(assign(r08DE, r08F4, 0x01));

                        body.emit(assign(r08DB, body.constant(int(0)), 0x01));

                        body.emit(assign(r08E1, less(r08F4, body.constant(0u)), 0x01));


                     body.instructions = f08F0_parent_instructions;
                     body.emit(f08F0);

                     /* END IF */


                  body.instructions = f08E5_parent_instructions;
                  body.emit(f08E5);

                  /* END IF */


               body.instructions = f08E3_parent_instructions;
               body.emit(f08E3);

               /* END IF */

               /* IF CONDITION */
               ir_if *f090E = new(mem_ctx) ir_if(operand(r08DF).val);
               exec_list *const f090E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f090E->then_instructions;

                  /* IF CONDITION */
                  ir_if *f090F = new(mem_ctx) ir_if(operand(r08E1).val);
                  exec_list *const f090F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f090F->then_instructions;

                     ir_variable *const r0910 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0910, add(r08DD, body.constant(1u)), 0x01));

                     ir_expression *const r0911 = less(r0910, r08DD);
                     ir_expression *const r0912 = expr(ir_unop_b2i, r0911);
                     ir_expression *const r0913 = expr(ir_unop_i2u, r0912);
                     body.emit(assign(r08DC, add(r08DC, r0913), 0x01));

                     ir_expression *const r0914 = equal(r08DE, body.constant(0u));
                     ir_expression *const r0915 = expr(ir_unop_b2i, r0914);
                     ir_expression *const r0916 = expr(ir_unop_i2u, r0915);
                     ir_expression *const r0917 = add(r08DE, r0916);
                     ir_expression *const r0918 = bit_and(r0917, body.constant(1u));
                     ir_expression *const r0919 = expr(ir_unop_bit_not, r0918);
                     body.emit(assign(r08DD, bit_and(r0910, r0919), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f090F->else_instructions;

                     ir_expression *const r091A = bit_or(r08DC, r08DD);
                     ir_expression *const r091B = equal(r091A, body.constant(0u));
                     body.emit(assign(r08DB, expr(ir_triop_csel, r091B, body.constant(int(0)), r08DB), 0x01));


                  body.instructions = f090F_parent_instructions;
                  body.emit(f090F);

                  /* END IF */

                  ir_variable *const r091C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r091C);
                  ir_expression *const r091D = lshift(r07C7, body.constant(int(31)));
                  ir_expression *const r091E = expr(ir_unop_i2u, r08DB);
                  ir_expression *const r091F = lshift(r091E, body.constant(int(20)));
                  ir_expression *const r0920 = add(r091D, r091F);
                  body.emit(assign(r091C, add(r0920, r08DC), 0x02));

                  body.emit(assign(r091C, r08DD, 0x01));

                  body.emit(assign(r08E0, r091C, 0x03));

                  body.emit(assign(r08DF, body.constant(false), 0x01));


               body.instructions = f090E_parent_instructions;
               body.emit(f090E);

               /* END IF */

               body.emit(assign(r07C6, r08E0, 0x03));

               body.emit(assign(r07C5, body.constant(false), 0x01));


            body.instructions = f0860_parent_instructions;
            body.emit(f0860);

            /* END IF */


         body.instructions = f0841_parent_instructions;
         body.emit(f0841);

         /* END IF */


      body.instructions = f0803_parent_instructions;
      body.emit(f0803);

      /* END IF */


   body.instructions = f07DE_parent_instructions;
   body.emit(f07DE);

   /* END IF */

   body.emit(ret(r07C6));

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

   ir_variable *const r0921 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0921);
   ir_variable *const r0922 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0922);
   ir_variable *const r0923 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r0923);
   ir_variable *const r0924 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0924);
   ir_variable *const r0925 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0925);
   ir_expression *const r0926 = equal(r0923, body.constant(int(0)));
   ir_expression *const r0927 = less(r0923, body.constant(int(32)));
   ir_expression *const r0928 = neg(r0923);
   ir_expression *const r0929 = bit_and(r0928, body.constant(int(31)));
   ir_expression *const r092A = lshift(r0921, r0929);
   ir_expression *const r092B = rshift(r0922, r0923);
   ir_expression *const r092C = bit_or(r092A, r092B);
   ir_expression *const r092D = less(r0923, body.constant(int(64)));
   ir_expression *const r092E = bit_and(r0923, body.constant(int(31)));
   ir_expression *const r092F = rshift(r0921, r092E);
   ir_expression *const r0930 = expr(ir_triop_csel, r092D, r092F, body.constant(0u));
   ir_expression *const r0931 = expr(ir_triop_csel, r0927, r092C, r0930);
   body.emit(assign(r0925, expr(ir_triop_csel, r0926, r0921, r0931), 0x01));

   ir_expression *const r0932 = equal(r0923, body.constant(int(0)));
   ir_expression *const r0933 = less(r0923, body.constant(int(32)));
   ir_expression *const r0934 = rshift(r0921, r0923);
   ir_expression *const r0935 = expr(ir_triop_csel, r0933, r0934, body.constant(0u));
   body.emit(assign(r0924, expr(ir_triop_csel, r0932, r0921, r0935), 0x01));

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

   ir_variable *const r0936 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0936);
   ir_variable *const r0937 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0938 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0938);
   ir_variable *const r0939 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0939);
   ir_variable *const r093A = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r093A, swizzle_x(r0936), 0x01));

   body.emit(assign(r0939, r093A, 0x01));

   ir_variable *const r093B = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r093B, bit_and(swizzle_y(r0936), body.constant(1048575u)), 0x01));

   body.emit(assign(r0938, r093B, 0x01));

   ir_variable *const r093C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r093D = rshift(swizzle_y(r0936), body.constant(int(20)));
   ir_expression *const r093E = bit_and(r093D, body.constant(2047u));
   body.emit(assign(r093C, expr(ir_unop_u2i, r093E), 0x01));

   ir_variable *const r093F = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r093F, rshift(swizzle_y(r0936), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0941 = nequal(r093F, body.constant(0u));
   ir_if *f0940 = new(mem_ctx) ir_if(operand(r0941).val);
   exec_list *const f0940_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0940->then_instructions;

      body.emit(assign(r0937, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0940->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0943 = equal(r093C, body.constant(int(2047)));
      ir_expression *const r0944 = bit_or(r093B, swizzle_x(r0936));
      ir_expression *const r0945 = nequal(r0944, body.constant(0u));
      ir_expression *const r0946 = logic_and(r0943, r0945);
      ir_if *f0942 = new(mem_ctx) ir_if(operand(r0946).val);
      exec_list *const f0942_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0942->then_instructions;

         body.emit(assign(r0937, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0942->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0948 = nequal(r093C, body.constant(int(0)));
         ir_if *f0947 = new(mem_ctx) ir_if(operand(r0948).val);
         exec_list *const f0947_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0947->then_instructions;

            body.emit(assign(r0938, bit_or(r093B, body.constant(1048576u)), 0x01));


         body.instructions = f0947_parent_instructions;
         body.emit(f0947);

         /* END IF */

         ir_variable *const r0949 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0949, sub(body.constant(int(1063)), r093C), 0x01));

         /* IF CONDITION */
         ir_expression *const r094B = less(body.constant(int(0)), r0949);
         ir_if *f094A = new(mem_ctx) ir_if(operand(r094B).val);
         exec_list *const f094A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f094A->then_instructions;

            ir_variable *const r094C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r094C);
            ir_variable *const r094D = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r094E = neg(r0949);
            body.emit(assign(r094D, bit_and(r094E, body.constant(int(31))), 0x01));

            ir_variable *const r094F = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0950 = less(r0949, body.constant(int(32)));
            ir_expression *const r0951 = rshift(r0938, r0949);
            ir_expression *const r0952 = equal(r0949, body.constant(int(0)));
            ir_expression *const r0953 = expr(ir_triop_csel, r0952, r0938, body.constant(0u));
            body.emit(assign(r094F, expr(ir_triop_csel, r0950, r0951, r0953), 0x01));

            /* IF CONDITION */
            ir_expression *const r0955 = equal(r0949, body.constant(int(0)));
            ir_if *f0954 = new(mem_ctx) ir_if(operand(r0955).val);
            exec_list *const f0954_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0954->then_instructions;

               body.emit(assign(r094C, r093A, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0954->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0957 = less(r0949, body.constant(int(32)));
               ir_if *f0956 = new(mem_ctx) ir_if(operand(r0957).val);
               exec_list *const f0956_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0956->then_instructions;

                  ir_expression *const r0958 = lshift(r0938, r094D);
                  ir_expression *const r0959 = rshift(swizzle_x(r0936), r0949);
                  ir_expression *const r095A = bit_or(r0958, r0959);
                  ir_expression *const r095B = lshift(swizzle_x(r0936), r094D);
                  ir_expression *const r095C = nequal(r095B, body.constant(0u));
                  ir_expression *const r095D = expr(ir_unop_b2i, r095C);
                  ir_expression *const r095E = expr(ir_unop_i2u, r095D);
                  body.emit(assign(r094C, bit_or(r095A, r095E), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0956->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0960 = equal(r0949, body.constant(int(32)));
                  ir_if *f095F = new(mem_ctx) ir_if(operand(r0960).val);
                  exec_list *const f095F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f095F->then_instructions;

                     ir_expression *const r0961 = nequal(swizzle_x(r0936), body.constant(0u));
                     ir_expression *const r0962 = expr(ir_unop_b2i, r0961);
                     ir_expression *const r0963 = expr(ir_unop_i2u, r0962);
                     body.emit(assign(r094C, bit_or(r0938, r0963), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f095F->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0965 = less(r0949, body.constant(int(64)));
                     ir_if *f0964 = new(mem_ctx) ir_if(operand(r0965).val);
                     exec_list *const f0964_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0964->then_instructions;

                        ir_expression *const r0966 = bit_and(r0949, body.constant(int(31)));
                        ir_expression *const r0967 = rshift(r0938, r0966);
                        ir_expression *const r0968 = lshift(r0938, r094D);
                        ir_expression *const r0969 = bit_or(r0968, swizzle_x(r0936));
                        ir_expression *const r096A = nequal(r0969, body.constant(0u));
                        ir_expression *const r096B = expr(ir_unop_b2i, r096A);
                        ir_expression *const r096C = expr(ir_unop_i2u, r096B);
                        body.emit(assign(r094C, bit_or(r0967, r096C), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0964->else_instructions;

                        ir_expression *const r096D = bit_or(r0938, swizzle_x(r0936));
                        ir_expression *const r096E = nequal(r096D, body.constant(0u));
                        ir_expression *const r096F = expr(ir_unop_b2i, r096E);
                        body.emit(assign(r094C, expr(ir_unop_i2u, r096F), 0x01));


                     body.instructions = f0964_parent_instructions;
                     body.emit(f0964);

                     /* END IF */


                  body.instructions = f095F_parent_instructions;
                  body.emit(f095F);

                  /* END IF */


               body.instructions = f0956_parent_instructions;
               body.emit(f0956);

               /* END IF */


            body.instructions = f0954_parent_instructions;
            body.emit(f0954);

            /* END IF */

            body.emit(assign(r0938, r094F, 0x01));

            body.emit(assign(r0939, r094C, 0x01));


         body.instructions = f094A_parent_instructions;
         body.emit(f094A);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0971 = bit_and(r0938, body.constant(4294963200u));
         ir_expression *const r0972 = nequal(r0971, body.constant(0u));
         ir_if *f0970 = new(mem_ctx) ir_if(operand(r0972).val);
         exec_list *const f0970_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0970->then_instructions;

            ir_variable *const r0973 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0975 = nequal(r093F, body.constant(0u));
            ir_if *f0974 = new(mem_ctx) ir_if(operand(r0975).val);
            exec_list *const f0974_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0974->then_instructions;

               body.emit(assign(r0973, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0974->else_instructions;

               body.emit(assign(r0973, body.constant(4294967295u), 0x01));


            body.instructions = f0974_parent_instructions;
            body.emit(f0974);

            /* END IF */

            body.emit(assign(r0937, r0973, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0970->else_instructions;

            ir_variable *const r0976 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r0977 = lshift(r0938, body.constant(int(20)));
            ir_expression *const r0978 = rshift(r0939, body.constant(int(12)));
            body.emit(assign(r0976, bit_or(r0977, r0978), 0x01));

            /* IF CONDITION */
            ir_expression *const r097A = nequal(r093F, body.constant(0u));
            ir_expression *const r097B = nequal(r0976, body.constant(0u));
            ir_expression *const r097C = logic_and(r097A, r097B);
            ir_if *f0979 = new(mem_ctx) ir_if(operand(r097C).val);
            exec_list *const f0979_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0979->then_instructions;

               ir_variable *const r097D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r097F = nequal(r093F, body.constant(0u));
               ir_if *f097E = new(mem_ctx) ir_if(operand(r097F).val);
               exec_list *const f097E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f097E->then_instructions;

                  body.emit(assign(r097D, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f097E->else_instructions;

                  body.emit(assign(r097D, body.constant(4294967295u), 0x01));


               body.instructions = f097E_parent_instructions;
               body.emit(f097E);

               /* END IF */

               body.emit(assign(r0937, r097D, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0979->else_instructions;

               body.emit(assign(r0937, r0976, 0x01));


            body.instructions = f0979_parent_instructions;
            body.emit(f0979);

            /* END IF */


         body.instructions = f0970_parent_instructions;
         body.emit(f0970);

         /* END IF */


      body.instructions = f0942_parent_instructions;
      body.emit(f0942);

      /* END IF */


   body.instructions = f0940_parent_instructions;
   body.emit(f0940);

   /* END IF */

   body.emit(ret(r0937));

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

   ir_variable *const r0980 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0980);
   ir_variable *const r0981 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0982 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0982);
   ir_variable *const r0983 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0983);
   /* IF CONDITION */
   ir_expression *const r0985 = equal(r0980, body.constant(0u));
   ir_if *f0984 = new(mem_ctx) ir_if(operand(r0985).val);
   exec_list *const f0984_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0984->then_instructions;

      body.emit(assign(r0981, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0984->else_instructions;

      ir_variable *const r0986 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0987 = equal(r0980, body.constant(0u));
      ir_expression *const r0988 = expr(ir_unop_find_msb, r0980);
      ir_expression *const r0989 = sub(body.constant(int(31)), r0988);
      ir_expression *const r098A = expr(ir_triop_csel, r0987, body.constant(int(32)), r0989);
      body.emit(assign(r0986, add(r098A, body.constant(int(21))), 0x01));

      body.emit(assign(r0983, body.constant(0u), 0x01));

      body.emit(assign(r0982, body.constant(0u), 0x01));

      ir_variable *const r098B = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r098C = neg(r0986);
      body.emit(assign(r098B, bit_and(r098C, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r098E = equal(r0986, body.constant(int(0)));
      ir_if *f098D = new(mem_ctx) ir_if(operand(r098E).val);
      exec_list *const f098D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f098D->then_instructions;

         body.emit(assign(r0983, body.constant(0u), 0x01));

         body.emit(assign(r0982, r0980, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f098D->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0990 = less(r0986, body.constant(int(32)));
         ir_if *f098F = new(mem_ctx) ir_if(operand(r0990).val);
         exec_list *const f098F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f098F->then_instructions;

            body.emit(assign(r0983, rshift(r0980, r098B), 0x01));

            body.emit(assign(r0982, lshift(r0980, r0986), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f098F->else_instructions;

            ir_variable *const r0991 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0993 = less(r0986, body.constant(int(64)));
            ir_if *f0992 = new(mem_ctx) ir_if(operand(r0993).val);
            exec_list *const f0992_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0992->then_instructions;

               ir_expression *const r0994 = add(r0986, body.constant(int(-32)));
               body.emit(assign(r0991, lshift(r0980, r0994), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0992->else_instructions;

               body.emit(assign(r0991, body.constant(0u), 0x01));


            body.instructions = f0992_parent_instructions;
            body.emit(f0992);

            /* END IF */

            body.emit(assign(r0983, r0991, 0x01));

            body.emit(assign(r0982, body.constant(0u), 0x01));


         body.instructions = f098F_parent_instructions;
         body.emit(f098F);

         /* END IF */


      body.instructions = f098D_parent_instructions;
      body.emit(f098D);

      /* END IF */

      ir_variable *const r0995 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0995);
      ir_expression *const r0996 = sub(body.constant(int(1074)), r0986);
      ir_expression *const r0997 = expr(ir_unop_i2u, r0996);
      ir_expression *const r0998 = lshift(r0997, body.constant(int(20)));
      body.emit(assign(r0995, add(r0998, r0983), 0x02));

      body.emit(assign(r0995, r0982, 0x01));

      body.emit(assign(r0981, r0995, 0x03));


   body.instructions = f0984_parent_instructions;
   body.emit(f0984);

   /* END IF */

   body.emit(ret(r0981));

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

   ir_variable *const r0999 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0999);
   ir_variable *const r099A = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r099A, body.constant(true), 0x01));

   ir_variable *const r099B = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r099C = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r099C);
   ir_variable *const r099D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r099D);
   ir_variable *const r099E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r099E);
   ir_variable *const r099F = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r099F, bit_and(swizzle_y(r0999), body.constant(1048575u)), 0x01));

   body.emit(assign(r099E, r099F, 0x01));

   ir_variable *const r09A0 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r09A1 = rshift(swizzle_y(r0999), body.constant(int(20)));
   ir_expression *const r09A2 = bit_and(r09A1, body.constant(2047u));
   body.emit(assign(r09A0, expr(ir_unop_u2i, r09A2), 0x01));

   body.emit(assign(r099D, rshift(swizzle_y(r0999), body.constant(int(31))), 0x01));

   body.emit(assign(r099C, body.constant(0u), 0x01));

   ir_variable *const r09A3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r09A3, add(r09A0, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r09A5 = gequal(r09A3, body.constant(int(0)));
   ir_if *f09A4 = new(mem_ctx) ir_if(operand(r09A5).val);
   exec_list *const f09A4_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09A4->then_instructions;

      /* IF CONDITION */
      ir_expression *const r09A7 = less(body.constant(int(1054)), r09A0);
      ir_if *f09A6 = new(mem_ctx) ir_if(operand(r09A7).val);
      exec_list *const f09A6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09A6->then_instructions;

         /* IF CONDITION */
         ir_expression *const r09A9 = equal(r09A0, body.constant(int(2047)));
         ir_expression *const r09AA = bit_or(r099F, swizzle_x(r0999));
         ir_expression *const r09AB = expr(ir_unop_u2i, r09AA);
         ir_expression *const r09AC = expr(ir_unop_i2b, r09AB);
         ir_expression *const r09AD = logic_and(r09A9, r09AC);
         ir_if *f09A8 = new(mem_ctx) ir_if(operand(r09AD).val);
         exec_list *const f09A8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09A8->then_instructions;

            body.emit(assign(r099D, body.constant(0u), 0x01));


         body.instructions = f09A8_parent_instructions;
         body.emit(f09A8);

         /* END IF */

         ir_variable *const r09AE = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09B0 = expr(ir_unop_u2i, r099D);
         ir_expression *const r09B1 = expr(ir_unop_i2b, r09B0);
         ir_if *f09AF = new(mem_ctx) ir_if(operand(r09B1).val);
         exec_list *const f09AF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09AF->then_instructions;

            body.emit(assign(r09AE, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09AF->else_instructions;

            body.emit(assign(r09AE, body.constant(int(2147483647)), 0x01));


         body.instructions = f09AF_parent_instructions;
         body.emit(f09AF);

         /* END IF */

         body.emit(assign(r099B, r09AE, 0x01));

         body.emit(assign(r099A, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09A6->else_instructions;

         ir_variable *const r09B2 = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r09B2, bit_or(r099F, body.constant(1048576u)), 0x01));

         ir_expression *const r09B3 = equal(r09A3, body.constant(int(0)));
         ir_expression *const r09B4 = lshift(r09B2, r09A3);
         ir_expression *const r09B5 = neg(r09A3);
         ir_expression *const r09B6 = bit_and(r09B5, body.constant(int(31)));
         ir_expression *const r09B7 = rshift(swizzle_x(r0999), r09B6);
         ir_expression *const r09B8 = bit_or(r09B4, r09B7);
         body.emit(assign(r099C, expr(ir_triop_csel, r09B3, r09B2, r09B8), 0x01));


      body.instructions = f09A6_parent_instructions;
      body.emit(f09A6);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09A4->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09BA = less(r09A0, body.constant(int(1023)));
      ir_if *f09B9 = new(mem_ctx) ir_if(operand(r09BA).val);
      exec_list *const f09B9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09B9->then_instructions;

         body.emit(assign(r099B, body.constant(int(0)), 0x01));

         body.emit(assign(r099A, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09B9->else_instructions;

         body.emit(assign(r099E, bit_or(r099F, body.constant(1048576u)), 0x01));

         ir_expression *const r09BB = neg(r09A3);
         body.emit(assign(r099C, rshift(r099E, r09BB), 0x01));


      body.instructions = f09B9_parent_instructions;
      body.emit(f09B9);

      /* END IF */


   body.instructions = f09A4_parent_instructions;
   body.emit(f09A4);

   /* END IF */

   /* IF CONDITION */
   ir_if *f09BC = new(mem_ctx) ir_if(operand(r099A).val);
   exec_list *const f09BC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09BC->then_instructions;

      ir_variable *const r09BD = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09BF = nequal(r099D, body.constant(0u));
      ir_if *f09BE = new(mem_ctx) ir_if(operand(r09BF).val);
      exec_list *const f09BE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09BE->then_instructions;

         ir_expression *const r09C0 = expr(ir_unop_u2i, r099C);
         body.emit(assign(r09BD, neg(r09C0), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09BE->else_instructions;

         body.emit(assign(r09BD, expr(ir_unop_u2i, r099C), 0x01));


      body.instructions = f09BE_parent_instructions;
      body.emit(f09BE);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r09C2 = less(r09BD, body.constant(int(0)));
      ir_expression *const r09C3 = expr(ir_unop_b2i, r09C2);
      ir_expression *const r09C4 = expr(ir_unop_i2u, r09C3);
      ir_expression *const r09C5 = bit_xor(r099D, r09C4);
      ir_expression *const r09C6 = expr(ir_unop_u2i, r09C5);
      ir_expression *const r09C7 = expr(ir_unop_i2b, r09C6);
      ir_expression *const r09C8 = expr(ir_unop_i2b, r09BD);
      ir_expression *const r09C9 = logic_and(r09C7, r09C8);
      ir_if *f09C1 = new(mem_ctx) ir_if(operand(r09C9).val);
      exec_list *const f09C1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09C1->then_instructions;

         ir_variable *const r09CA = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09CC = expr(ir_unop_u2i, r099D);
         ir_expression *const r09CD = expr(ir_unop_i2b, r09CC);
         ir_if *f09CB = new(mem_ctx) ir_if(operand(r09CD).val);
         exec_list *const f09CB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09CB->then_instructions;

            body.emit(assign(r09CA, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09CB->else_instructions;

            body.emit(assign(r09CA, body.constant(int(2147483647)), 0x01));


         body.instructions = f09CB_parent_instructions;
         body.emit(f09CB);

         /* END IF */

         body.emit(assign(r099B, r09CA, 0x01));

         body.emit(assign(r099A, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09C1->else_instructions;

         body.emit(assign(r099B, r09BD, 0x01));

         body.emit(assign(r099A, body.constant(false), 0x01));


      body.instructions = f09C1_parent_instructions;
      body.emit(f09C1);

      /* END IF */


   body.instructions = f09BC_parent_instructions;
   body.emit(f09BC);

   /* END IF */

   body.emit(ret(r099B));

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

   ir_variable *const r09CE = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r09CE);
   ir_variable *const r09CF = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r09D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r09D0);
   ir_variable *const r09D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r09D1);
   ir_variable *const r09D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r09D2);
   body.emit(assign(r09D2, body.constant(0u), 0x01));

   body.emit(assign(r09D1, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r09D4 = equal(r09CE, body.constant(int(0)));
   ir_if *f09D3 = new(mem_ctx) ir_if(operand(r09D4).val);
   exec_list *const f09D3_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09D3->then_instructions;

      ir_variable *const r09D5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r09D5);
      body.emit(assign(r09D5, body.constant(0u), 0x02));

      body.emit(assign(r09D5, body.constant(0u), 0x01));

      body.emit(assign(r09CF, r09D5, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09D3->else_instructions;

      ir_expression *const r09D6 = less(r09CE, body.constant(int(0)));
      ir_expression *const r09D7 = expr(ir_unop_b2i, r09D6);
      body.emit(assign(r09D0, expr(ir_unop_i2u, r09D7), 0x01));

      ir_variable *const r09D8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r09DA = less(r09CE, body.constant(int(0)));
      ir_if *f09D9 = new(mem_ctx) ir_if(operand(r09DA).val);
      exec_list *const f09D9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09D9->then_instructions;

         ir_expression *const r09DB = neg(r09CE);
         body.emit(assign(r09D8, expr(ir_unop_i2u, r09DB), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09D9->else_instructions;

         body.emit(assign(r09D8, expr(ir_unop_i2u, r09CE), 0x01));


      body.instructions = f09D9_parent_instructions;
      body.emit(f09D9);

      /* END IF */

      ir_variable *const r09DC = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r09DD = equal(r09D8, body.constant(0u));
      ir_expression *const r09DE = expr(ir_unop_find_msb, r09D8);
      ir_expression *const r09DF = sub(body.constant(int(31)), r09DE);
      ir_expression *const r09E0 = expr(ir_triop_csel, r09DD, body.constant(int(32)), r09DF);
      body.emit(assign(r09DC, add(r09E0, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r09E2 = gequal(r09DC, body.constant(int(0)));
      ir_if *f09E1 = new(mem_ctx) ir_if(operand(r09E2).val);
      exec_list *const f09E1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09E1->then_instructions;

         body.emit(assign(r09D2, lshift(r09D8, r09DC), 0x01));

         body.emit(assign(r09D1, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09E1->else_instructions;

         ir_variable *const r09E3 = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r09E3, neg(r09DC), 0x01));

         ir_expression *const r09E4 = equal(r09E3, body.constant(int(0)));
         ir_expression *const r09E5 = less(r09E3, body.constant(int(32)));
         ir_expression *const r09E6 = rshift(r09D8, r09E3);
         ir_expression *const r09E7 = expr(ir_triop_csel, r09E5, r09E6, body.constant(0u));
         body.emit(assign(r09D2, expr(ir_triop_csel, r09E4, r09D8, r09E7), 0x01));

         ir_expression *const r09E8 = equal(r09E3, body.constant(int(0)));
         ir_expression *const r09E9 = less(r09E3, body.constant(int(32)));
         ir_expression *const r09EA = neg(r09E3);
         ir_expression *const r09EB = bit_and(r09EA, body.constant(int(31)));
         ir_expression *const r09EC = lshift(r09D8, r09EB);
         ir_expression *const r09ED = bit_or(r09EC, body.constant(0u));
         ir_expression *const r09EE = less(r09E3, body.constant(int(64)));
         ir_expression *const r09EF = bit_and(r09E3, body.constant(int(31)));
         ir_expression *const r09F0 = rshift(r09D8, r09EF);
         ir_expression *const r09F1 = expr(ir_triop_csel, r09EE, r09F0, body.constant(0u));
         ir_expression *const r09F2 = expr(ir_triop_csel, r09E9, r09ED, r09F1);
         body.emit(assign(r09D1, expr(ir_triop_csel, r09E8, r09D8, r09F2), 0x01));


      body.instructions = f09E1_parent_instructions;
      body.emit(f09E1);

      /* END IF */

      ir_variable *const r09F3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r09F3);
      ir_expression *const r09F4 = lshift(r09D0, body.constant(int(31)));
      ir_expression *const r09F5 = sub(body.constant(int(1042)), r09DC);
      ir_expression *const r09F6 = expr(ir_unop_i2u, r09F5);
      ir_expression *const r09F7 = lshift(r09F6, body.constant(int(20)));
      ir_expression *const r09F8 = add(r09F4, r09F7);
      body.emit(assign(r09F3, add(r09F8, r09D2), 0x02));

      body.emit(assign(r09F3, r09D1, 0x01));

      body.emit(assign(r09CF, r09F3, 0x03));


   body.instructions = f09D3_parent_instructions;
   body.emit(f09D3);

   /* END IF */

   body.emit(ret(r09CF));

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

   ir_variable *const r09F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r09F9);
   ir_variable *const r09FA = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r09FA);
   ir_variable *const r09FB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r09FB);
   ir_variable *const r09FC = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r09FD = lshift(r09F9, body.constant(int(31)));
   ir_expression *const r09FE = expr(ir_unop_i2u, r09FA);
   ir_expression *const r09FF = lshift(r09FE, body.constant(int(23)));
   ir_expression *const r0A00 = add(r09FD, r09FF);
   ir_expression *const r0A01 = add(r0A00, r09FB);
   body.emit(assign(r09FC, expr(ir_unop_bitcast_u2f, r0A01), 0x01));

   body.emit(ret(r09FC));

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

   ir_variable *const r0A02 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0A02);
   ir_variable *const r0A03 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0A03);
   ir_variable *const r0A04 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0A04);
   ir_variable *const r0A05 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A05, body.constant(true), 0x01));

   ir_variable *const r0A06 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A07 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0A07);
   ir_expression *const r0A08 = bit_and(r0A04, body.constant(127u));
   body.emit(assign(r0A07, expr(ir_unop_u2i, r0A08), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A0A = expr(ir_unop_i2u, r0A03);
   ir_expression *const r0A0B = gequal(r0A0A, body.constant(253u));
   ir_if *f0A09 = new(mem_ctx) ir_if(operand(r0A0B).val);
   exec_list *const f0A09_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A09->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A0D = less(body.constant(int(253)), r0A03);
      ir_expression *const r0A0E = equal(r0A03, body.constant(int(253)));
      ir_expression *const r0A0F = expr(ir_unop_u2i, r0A04);
      ir_expression *const r0A10 = less(r0A0F, body.constant(int(-64)));
      ir_expression *const r0A11 = logic_and(r0A0E, r0A10);
      ir_expression *const r0A12 = logic_or(r0A0D, r0A11);
      ir_if *f0A0C = new(mem_ctx) ir_if(operand(r0A12).val);
      exec_list *const f0A0C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A0C->then_instructions;

         ir_expression *const r0A13 = lshift(r0A02, body.constant(int(31)));
         ir_expression *const r0A14 = add(r0A13, body.constant(2139095040u));
         body.emit(assign(r0A06, expr(ir_unop_bitcast_u2f, r0A14), 0x01));

         body.emit(assign(r0A05, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A0C->else_instructions;

         ir_variable *const r0A15 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0A15, neg(r0A03), 0x01));

         ir_variable *const r0A16 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
         body.emit(assign(r0A16, less(r0A03, body.constant(int(0))), 0x01));

         ir_variable *const r0A17 = body.make_temp(glsl_type::uint_type, "mix_retval");
         ir_expression *const r0A18 = neg(r0A03);
         ir_expression *const r0A19 = less(r0A18, body.constant(int(32)));
         ir_expression *const r0A1A = rshift(r0A04, r0A15);
         ir_expression *const r0A1B = neg(r0A15);
         ir_expression *const r0A1C = bit_and(r0A1B, body.constant(int(31)));
         ir_expression *const r0A1D = lshift(r0A04, r0A1C);
         ir_expression *const r0A1E = nequal(r0A1D, body.constant(0u));
         ir_expression *const r0A1F = expr(ir_unop_b2i, r0A1E);
         ir_expression *const r0A20 = expr(ir_unop_i2u, r0A1F);
         ir_expression *const r0A21 = bit_or(r0A1A, r0A20);
         ir_expression *const r0A22 = nequal(r0A04, body.constant(0u));
         ir_expression *const r0A23 = expr(ir_unop_b2i, r0A22);
         ir_expression *const r0A24 = expr(ir_unop_i2u, r0A23);
         ir_expression *const r0A25 = expr(ir_triop_csel, r0A19, r0A21, r0A24);
         body.emit(assign(r0A17, expr(ir_triop_csel, r0A16, r0A25, r0A04), 0x01));

         body.emit(assign(r0A04, r0A17, 0x01));

         ir_expression *const r0A26 = expr(ir_unop_u2i, r0A17);
         ir_expression *const r0A27 = bit_and(r0A26, body.constant(int(127)));
         body.emit(assign(r0A07, expr(ir_triop_csel, r0A16, r0A27, r0A07), 0x01));

         body.emit(assign(r0A03, expr(ir_triop_csel, r0A16, body.constant(int(0)), r0A03), 0x01));


      body.instructions = f0A0C_parent_instructions;
      body.emit(f0A0C);

      /* END IF */


   body.instructions = f0A09_parent_instructions;
   body.emit(f0A09);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0A28 = new(mem_ctx) ir_if(operand(r0A05).val);
   exec_list *const f0A28_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A28->then_instructions;

      ir_expression *const r0A29 = add(r0A04, body.constant(64u));
      body.emit(assign(r0A04, rshift(r0A29, body.constant(int(7))), 0x01));

      ir_expression *const r0A2A = bit_xor(r0A07, body.constant(int(64)));
      ir_expression *const r0A2B = equal(r0A2A, body.constant(int(0)));
      ir_expression *const r0A2C = expr(ir_unop_b2i, r0A2B);
      ir_expression *const r0A2D = expr(ir_unop_i2u, r0A2C);
      ir_expression *const r0A2E = expr(ir_unop_bit_not, r0A2D);
      body.emit(assign(r0A04, bit_and(r0A04, r0A2E), 0x01));

      ir_expression *const r0A2F = lshift(r0A02, body.constant(int(31)));
      ir_expression *const r0A30 = equal(r0A04, body.constant(0u));
      ir_expression *const r0A31 = expr(ir_triop_csel, r0A30, body.constant(int(0)), r0A03);
      ir_expression *const r0A32 = expr(ir_unop_i2u, r0A31);
      ir_expression *const r0A33 = lshift(r0A32, body.constant(int(23)));
      ir_expression *const r0A34 = add(r0A2F, r0A33);
      ir_expression *const r0A35 = add(r0A34, r0A04);
      body.emit(assign(r0A06, expr(ir_unop_bitcast_u2f, r0A35), 0x01));

      body.emit(assign(r0A05, body.constant(false), 0x01));


   body.instructions = f0A28_parent_instructions;
   body.emit(f0A28);

   /* END IF */

   body.emit(ret(r0A06));

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

   ir_variable *const r0A36 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A36);
   ir_variable *const r0A37 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0A38 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0A38, swizzle_x(r0A36), 0x01));

   ir_variable *const r0A39 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A39, bit_and(swizzle_y(r0A36), body.constant(1048575u)), 0x01));

   ir_variable *const r0A3A = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A3B = rshift(swizzle_y(r0A36), body.constant(int(20)));
   ir_expression *const r0A3C = bit_and(r0A3B, body.constant(2047u));
   body.emit(assign(r0A3A, expr(ir_unop_u2i, r0A3C), 0x01));

   ir_variable *const r0A3D = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A3D, rshift(swizzle_y(r0A36), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A3F = equal(r0A3A, body.constant(int(2047)));
   ir_if *f0A3E = new(mem_ctx) ir_if(operand(r0A3F).val);
   exec_list *const f0A3E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A3E->then_instructions;

      ir_variable *const r0A40 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0A40);
      ir_variable *const r0A41 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0A41, lshift(swizzle_x(r0A36), body.constant(int(12))), 0x01));

      ir_expression *const r0A42 = lshift(swizzle_y(r0A36), body.constant(int(12)));
      ir_expression *const r0A43 = rshift(swizzle_x(r0A36), body.constant(int(20)));
      body.emit(assign(r0A36, bit_or(r0A42, r0A43), 0x02));

      body.emit(assign(r0A36, r0A41, 0x01));

      ir_expression *const r0A44 = lshift(r0A3D, body.constant(int(31)));
      ir_expression *const r0A45 = bit_or(r0A44, body.constant(2143289344u));
      ir_expression *const r0A46 = rshift(swizzle_y(r0A36), body.constant(int(9)));
      ir_expression *const r0A47 = bit_or(r0A45, r0A46);
      body.emit(assign(r0A40, expr(ir_unop_bitcast_u2f, r0A47), 0x01));

      ir_variable *const r0A48 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0A49 = bit_or(r0A39, r0A38);
      ir_expression *const r0A4A = nequal(r0A49, body.constant(0u));
      ir_expression *const r0A4B = lshift(r0A3D, body.constant(int(31)));
      ir_expression *const r0A4C = add(r0A4B, body.constant(2139095040u));
      ir_expression *const r0A4D = expr(ir_unop_bitcast_u2f, r0A4C);
      body.emit(assign(r0A48, expr(ir_triop_csel, r0A4A, r0A40, r0A4D), 0x01));

      body.emit(assign(r0A40, r0A48, 0x01));

      body.emit(assign(r0A37, r0A48, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A3E->else_instructions;

      ir_variable *const r0A4E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0A4E);
      ir_variable *const r0A4F = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0A4F, rshift(r0A39, body.constant(int(22))), 0x01));

      ir_expression *const r0A50 = lshift(r0A39, body.constant(int(10)));
      ir_expression *const r0A51 = rshift(r0A38, body.constant(int(22)));
      ir_expression *const r0A52 = bit_or(r0A50, r0A51);
      ir_expression *const r0A53 = lshift(r0A38, body.constant(int(10)));
      ir_expression *const r0A54 = nequal(r0A53, body.constant(0u));
      ir_expression *const r0A55 = expr(ir_unop_b2i, r0A54);
      ir_expression *const r0A56 = expr(ir_unop_i2u, r0A55);
      body.emit(assign(r0A4E, bit_or(r0A52, r0A56), 0x01));

      ir_variable *const r0A57 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0A58 = nequal(r0A3A, body.constant(int(0)));
      ir_expression *const r0A59 = bit_or(r0A4E, body.constant(1073741824u));
      body.emit(assign(r0A57, expr(ir_triop_csel, r0A58, r0A59, r0A4E), 0x01));

      ir_variable *const r0A5A = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0A5A, add(r0A3A, body.constant(int(-897))), 0x01));

      ir_variable *const r0A5B = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0A5B, r0A57, 0x01));

      ir_variable *const r0A5C = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0A5C, body.constant(true), 0x01));

      ir_variable *const r0A5D = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0A5E = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0A5E);
      ir_expression *const r0A5F = bit_and(r0A57, body.constant(127u));
      body.emit(assign(r0A5E, expr(ir_unop_u2i, r0A5F), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A61 = expr(ir_unop_i2u, r0A5A);
      ir_expression *const r0A62 = gequal(r0A61, body.constant(253u));
      ir_if *f0A60 = new(mem_ctx) ir_if(operand(r0A62).val);
      exec_list *const f0A60_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A60->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A64 = less(body.constant(int(253)), r0A5A);
         ir_expression *const r0A65 = equal(r0A5A, body.constant(int(253)));
         ir_expression *const r0A66 = expr(ir_unop_u2i, r0A57);
         ir_expression *const r0A67 = less(r0A66, body.constant(int(-64)));
         ir_expression *const r0A68 = logic_and(r0A65, r0A67);
         ir_expression *const r0A69 = logic_or(r0A64, r0A68);
         ir_if *f0A63 = new(mem_ctx) ir_if(operand(r0A69).val);
         exec_list *const f0A63_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A63->then_instructions;

            ir_expression *const r0A6A = lshift(r0A3D, body.constant(int(31)));
            ir_expression *const r0A6B = add(r0A6A, body.constant(2139095040u));
            body.emit(assign(r0A5D, expr(ir_unop_bitcast_u2f, r0A6B), 0x01));

            body.emit(assign(r0A5C, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A63->else_instructions;

            ir_variable *const r0A6C = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0A6C, neg(r0A5A), 0x01));

            ir_variable *const r0A6D = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0A6D, less(r0A5A, body.constant(int(0))), 0x01));

            ir_variable *const r0A6E = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0A6F = neg(r0A5A);
            ir_expression *const r0A70 = less(r0A6F, body.constant(int(32)));
            ir_expression *const r0A71 = rshift(r0A57, r0A6C);
            ir_expression *const r0A72 = neg(r0A6C);
            ir_expression *const r0A73 = bit_and(r0A72, body.constant(int(31)));
            ir_expression *const r0A74 = lshift(r0A57, r0A73);
            ir_expression *const r0A75 = nequal(r0A74, body.constant(0u));
            ir_expression *const r0A76 = expr(ir_unop_b2i, r0A75);
            ir_expression *const r0A77 = expr(ir_unop_i2u, r0A76);
            ir_expression *const r0A78 = bit_or(r0A71, r0A77);
            ir_expression *const r0A79 = nequal(r0A57, body.constant(0u));
            ir_expression *const r0A7A = expr(ir_unop_b2i, r0A79);
            ir_expression *const r0A7B = expr(ir_unop_i2u, r0A7A);
            ir_expression *const r0A7C = expr(ir_triop_csel, r0A70, r0A78, r0A7B);
            body.emit(assign(r0A6E, expr(ir_triop_csel, r0A6D, r0A7C, r0A57), 0x01));

            body.emit(assign(r0A5B, r0A6E, 0x01));

            ir_expression *const r0A7D = expr(ir_unop_u2i, r0A6E);
            ir_expression *const r0A7E = bit_and(r0A7D, body.constant(int(127)));
            body.emit(assign(r0A5E, expr(ir_triop_csel, r0A6D, r0A7E, r0A5E), 0x01));

            body.emit(assign(r0A5A, expr(ir_triop_csel, r0A6D, body.constant(int(0)), r0A5A), 0x01));


         body.instructions = f0A63_parent_instructions;
         body.emit(f0A63);

         /* END IF */


      body.instructions = f0A60_parent_instructions;
      body.emit(f0A60);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0A7F = new(mem_ctx) ir_if(operand(r0A5C).val);
      exec_list *const f0A7F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A7F->then_instructions;

         ir_expression *const r0A80 = add(r0A5B, body.constant(64u));
         body.emit(assign(r0A5B, rshift(r0A80, body.constant(int(7))), 0x01));

         ir_expression *const r0A81 = bit_xor(r0A5E, body.constant(int(64)));
         ir_expression *const r0A82 = equal(r0A81, body.constant(int(0)));
         ir_expression *const r0A83 = expr(ir_unop_b2i, r0A82);
         ir_expression *const r0A84 = expr(ir_unop_i2u, r0A83);
         ir_expression *const r0A85 = expr(ir_unop_bit_not, r0A84);
         body.emit(assign(r0A5B, bit_and(r0A5B, r0A85), 0x01));

         ir_expression *const r0A86 = lshift(r0A3D, body.constant(int(31)));
         ir_expression *const r0A87 = equal(r0A5B, body.constant(0u));
         ir_expression *const r0A88 = expr(ir_triop_csel, r0A87, body.constant(int(0)), r0A5A);
         ir_expression *const r0A89 = expr(ir_unop_i2u, r0A88);
         ir_expression *const r0A8A = lshift(r0A89, body.constant(int(23)));
         ir_expression *const r0A8B = add(r0A86, r0A8A);
         ir_expression *const r0A8C = add(r0A8B, r0A5B);
         body.emit(assign(r0A5D, expr(ir_unop_bitcast_u2f, r0A8C), 0x01));

         body.emit(assign(r0A5C, body.constant(false), 0x01));


      body.instructions = f0A7F_parent_instructions;
      body.emit(f0A7F);

      /* END IF */

      body.emit(assign(r0A37, r0A5D, 0x01));


   body.instructions = f0A3E_parent_instructions;
   body.emit(f0A3E);

   /* END IF */

   body.emit(ret(r0A37));

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

   ir_variable *const r0A8D = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0A8D);
   ir_variable *const r0A8E = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A8E, body.constant(true), 0x01));

   ir_variable *const r0A8F = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A90 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A90);
   ir_variable *const r0A91 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0A91);
   ir_variable *const r0A92 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0A92);
   ir_variable *const r0A93 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0A93, expr(ir_unop_bitcast_f2u, r0A8D), 0x01));

   ir_variable *const r0A94 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0A94, bit_and(r0A93, body.constant(8388607u)), 0x01));

   body.emit(assign(r0A92, r0A94, 0x01));

   ir_variable *const r0A95 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A96 = rshift(r0A93, body.constant(int(23)));
   ir_expression *const r0A97 = bit_and(r0A96, body.constant(255u));
   body.emit(assign(r0A95, expr(ir_unop_u2i, r0A97), 0x01));

   body.emit(assign(r0A91, r0A95, 0x01));

   body.emit(assign(r0A90, rshift(r0A93, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A99 = equal(r0A95, body.constant(int(255)));
   ir_if *f0A98 = new(mem_ctx) ir_if(operand(r0A99).val);
   exec_list *const f0A98_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A98->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A9B = nequal(r0A94, body.constant(0u));
      ir_if *f0A9A = new(mem_ctx) ir_if(operand(r0A9B).val);
      exec_list *const f0A9A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A9A->then_instructions;

         ir_variable *const r0A9C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0A9C, lshift(r0A93, body.constant(int(9))), 0x01));

         ir_variable *const r0A9D = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0A9E = lshift(r0A9C, body.constant(int(20)));
         body.emit(assign(r0A9D, bit_or(r0A9E, body.constant(0u)), 0x01));

         ir_expression *const r0A9F = rshift(r0A9C, body.constant(int(12)));
         ir_expression *const r0AA0 = lshift(r0A90, body.constant(int(31)));
         ir_expression *const r0AA1 = bit_or(r0AA0, body.constant(2146959360u));
         body.emit(assign(r0A9D, bit_or(r0A9F, r0AA1), 0x02));

         body.emit(assign(r0A8F, r0A9D, 0x03));

         body.emit(assign(r0A8E, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A9A->else_instructions;

         ir_variable *const r0AA2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0AA2);
         ir_expression *const r0AA3 = lshift(r0A90, body.constant(int(31)));
         body.emit(assign(r0AA2, add(r0AA3, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0AA2, body.constant(0u), 0x01));

         body.emit(assign(r0A8F, r0AA2, 0x03));

         body.emit(assign(r0A8E, body.constant(false), 0x01));


      body.instructions = f0A9A_parent_instructions;
      body.emit(f0A9A);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A98->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0AA5 = equal(r0A95, body.constant(int(0)));
      ir_if *f0AA4 = new(mem_ctx) ir_if(operand(r0AA5).val);
      exec_list *const f0AA4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AA4->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0AA7 = equal(r0A94, body.constant(0u));
         ir_if *f0AA6 = new(mem_ctx) ir_if(operand(r0AA7).val);
         exec_list *const f0AA6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA6->then_instructions;

            ir_variable *const r0AA8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0AA8);
            body.emit(assign(r0AA8, lshift(r0A90, body.constant(int(31))), 0x02));

            body.emit(assign(r0AA8, body.constant(0u), 0x01));

            body.emit(assign(r0A8F, r0AA8, 0x03));

            body.emit(assign(r0A8E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AA6->else_instructions;

            ir_variable *const r0AA9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0AAA = equal(r0A94, body.constant(0u));
            ir_expression *const r0AAB = expr(ir_unop_find_msb, r0A94);
            ir_expression *const r0AAC = sub(body.constant(int(31)), r0AAB);
            ir_expression *const r0AAD = expr(ir_triop_csel, r0AAA, body.constant(int(32)), r0AAC);
            body.emit(assign(r0AA9, add(r0AAD, body.constant(int(-8))), 0x01));

            body.emit(assign(r0A92, lshift(r0A94, r0AA9), 0x01));

            body.emit(assign(r0A91, sub(body.constant(int(1)), r0AA9), 0x01));

            body.emit(assign(r0A91, add(r0A91, body.constant(int(-1))), 0x01));


         body.instructions = f0AA6_parent_instructions;
         body.emit(f0AA6);

         /* END IF */


      body.instructions = f0AA4_parent_instructions;
      body.emit(f0AA4);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0AAE = new(mem_ctx) ir_if(operand(r0A8E).val);
      exec_list *const f0AAE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AAE->then_instructions;

         ir_variable *const r0AAF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0AAF);
         ir_expression *const r0AB0 = lshift(r0A90, body.constant(int(31)));
         ir_expression *const r0AB1 = add(r0A91, body.constant(int(896)));
         ir_expression *const r0AB2 = expr(ir_unop_i2u, r0AB1);
         ir_expression *const r0AB3 = lshift(r0AB2, body.constant(int(20)));
         ir_expression *const r0AB4 = add(r0AB0, r0AB3);
         ir_expression *const r0AB5 = rshift(r0A92, body.constant(int(3)));
         body.emit(assign(r0AAF, add(r0AB4, r0AB5), 0x02));

         ir_expression *const r0AB6 = lshift(r0A92, body.constant(int(29)));
         body.emit(assign(r0AAF, bit_or(r0AB6, body.constant(0u)), 0x01));

         body.emit(assign(r0A8F, r0AAF, 0x03));

         body.emit(assign(r0A8E, body.constant(false), 0x01));


      body.instructions = f0AAE_parent_instructions;
      body.emit(f0AAE);

      /* END IF */


   body.instructions = f0A98_parent_instructions;
   body.emit(f0A98);

   /* END IF */

   body.emit(ret(r0A8F));

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

   ir_variable *const r0AB7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0AB7);
   ir_variable *const r0AB8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0AB8);
   ir_variable *const r0AB9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0AB9);
   ir_variable *const r0ABA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0ABA);
   ir_variable *const r0ABB = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0ABB);
   ir_variable *const r0ABC = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0ABC);
   ir_variable *const r0ABD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0ABD);
   ir_variable *const r0ABE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0ABE);
   ir_variable *const r0ABF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0ABF);
   ir_variable *const r0AC0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0AC0);
   ir_variable *const r0AC1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0AC1);
   ir_variable *const r0AC2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0AC2, add(r0AB9, r0ABC), 0x01));

   ir_variable *const r0AC3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0AC4 = less(r0AC2, r0AB9);
   ir_expression *const r0AC5 = expr(ir_unop_b2i, r0AC4);
   body.emit(assign(r0AC3, expr(ir_unop_i2u, r0AC5), 0x01));

   ir_variable *const r0AC6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0AC6, add(r0AB8, r0ABB), 0x01));

   body.emit(assign(r0AC1, add(r0AC6, r0AC3), 0x01));

   ir_expression *const r0AC7 = add(r0AB7, r0ABA);
   ir_expression *const r0AC8 = less(r0AC1, r0AC3);
   ir_expression *const r0AC9 = expr(ir_unop_b2i, r0AC8);
   ir_expression *const r0ACA = expr(ir_unop_i2u, r0AC9);
   body.emit(assign(r0AC0, add(r0AC7, r0ACA), 0x01));

   ir_expression *const r0ACB = less(r0AC6, r0AB8);
   ir_expression *const r0ACC = expr(ir_unop_b2i, r0ACB);
   ir_expression *const r0ACD = expr(ir_unop_i2u, r0ACC);
   body.emit(assign(r0AC0, add(r0AC0, r0ACD), 0x01));

   body.emit(assign(r0ABF, r0AC2, 0x01));

   body.emit(assign(r0ABE, r0AC1, 0x01));

   body.emit(assign(r0ABD, r0AC0, 0x01));

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

   ir_variable *const r0ACE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0ACE);
   ir_variable *const r0ACF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0ACF);
   ir_variable *const r0AD0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0AD0);
   ir_variable *const r0AD1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0AD1);
   ir_variable *const r0AD2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0AD2);
   ir_variable *const r0AD3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0AD3);
   ir_variable *const r0AD4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AD4);
   ir_variable *const r0AD5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AD5);
   ir_variable *const r0AD6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0AD6);
   ir_variable *const r0AD7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0AD7);
   ir_variable *const r0AD8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0AD9 = less(r0AD0, r0AD3);
   ir_expression *const r0ADA = expr(ir_unop_b2i, r0AD9);
   body.emit(assign(r0AD8, expr(ir_unop_i2u, r0ADA), 0x01));

   ir_variable *const r0ADB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0ADB, sub(r0ACF, r0AD2), 0x01));

   ir_expression *const r0ADC = sub(r0ACE, r0AD1);
   ir_expression *const r0ADD = less(r0ADB, r0AD8);
   ir_expression *const r0ADE = expr(ir_unop_b2i, r0ADD);
   ir_expression *const r0ADF = expr(ir_unop_i2u, r0ADE);
   body.emit(assign(r0AD7, sub(r0ADC, r0ADF), 0x01));

   ir_expression *const r0AE0 = less(r0ACF, r0AD2);
   ir_expression *const r0AE1 = expr(ir_unop_b2i, r0AE0);
   ir_expression *const r0AE2 = expr(ir_unop_i2u, r0AE1);
   body.emit(assign(r0AD7, sub(r0AD7, r0AE2), 0x01));

   body.emit(assign(r0AD6, sub(r0AD0, r0AD3), 0x01));

   body.emit(assign(r0AD5, sub(r0ADB, r0AD8), 0x01));

   body.emit(assign(r0AD4, r0AD7, 0x01));

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

   ir_variable *const r0AE3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0AE3);
   ir_variable *const r0AE4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0AE4);
   ir_variable *const r0AE5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0AE5);
   ir_variable *const r0AE6 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0AE7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0AE7);
   ir_variable *const r0AE8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0AE8);
   ir_variable *const r0AE9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0AE9);
   ir_variable *const r0AEA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0AEA);
   body.emit(assign(r0AE9, body.constant(0u), 0x01));

   body.emit(assign(r0AE8, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AEC = gequal(r0AE3, r0AE5);
   ir_if *f0AEB = new(mem_ctx) ir_if(operand(r0AEC).val);
   exec_list *const f0AEB_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AEB->then_instructions;

      body.emit(assign(r0AE6, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AEB->else_instructions;

      body.emit(assign(r0AEA, rshift(r0AE5, body.constant(int(16))), 0x01));

      ir_variable *const r0AED = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0AEF = lshift(r0AEA, body.constant(int(16)));
      ir_expression *const r0AF0 = gequal(r0AE3, r0AEF);
      ir_if *f0AEE = new(mem_ctx) ir_if(operand(r0AF0).val);
      exec_list *const f0AEE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AEE->then_instructions;

         body.emit(assign(r0AED, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AEE->else_instructions;

         ir_expression *const r0AF1 = expr(ir_binop_div, r0AE3, r0AEA);
         body.emit(assign(r0AED, lshift(r0AF1, body.constant(int(16))), 0x01));


      body.instructions = f0AEE_parent_instructions;
      body.emit(f0AEE);

      /* END IF */

      body.emit(assign(r0AE7, r0AED, 0x01));

      ir_variable *const r0AF2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0AF2);
      ir_variable *const r0AF3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0AF3);
      ir_variable *const r0AF4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0AF4);
      ir_variable *const r0AF5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF5, bit_and(r0AE5, body.constant(65535u)), 0x01));

      ir_variable *const r0AF6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF6, rshift(r0AE5, body.constant(int(16))), 0x01));

      ir_variable *const r0AF7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF7, bit_and(r0AED, body.constant(65535u)), 0x01));

      ir_variable *const r0AF8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF8, rshift(r0AED, body.constant(int(16))), 0x01));

      ir_variable *const r0AF9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0AF9, mul(r0AF6, r0AF7), 0x01));

      ir_expression *const r0AFA = mul(r0AF5, r0AF8);
      body.emit(assign(r0AF3, add(r0AFA, r0AF9), 0x01));

      ir_expression *const r0AFB = mul(r0AF6, r0AF8);
      ir_expression *const r0AFC = less(r0AF3, r0AF9);
      ir_expression *const r0AFD = expr(ir_unop_b2i, r0AFC);
      ir_expression *const r0AFE = expr(ir_unop_i2u, r0AFD);
      ir_expression *const r0AFF = lshift(r0AFE, body.constant(int(16)));
      ir_expression *const r0B00 = rshift(r0AF3, body.constant(int(16)));
      ir_expression *const r0B01 = add(r0AFF, r0B00);
      body.emit(assign(r0AF2, add(r0AFB, r0B01), 0x01));

      body.emit(assign(r0AF3, lshift(r0AF3, body.constant(int(16))), 0x01));

      ir_expression *const r0B02 = mul(r0AF5, r0AF7);
      body.emit(assign(r0AF4, add(r0B02, r0AF3), 0x01));

      ir_expression *const r0B03 = less(r0AF4, r0AF3);
      ir_expression *const r0B04 = expr(ir_unop_b2i, r0B03);
      ir_expression *const r0B05 = expr(ir_unop_i2u, r0B04);
      body.emit(assign(r0AF2, add(r0AF2, r0B05), 0x01));

      ir_expression *const r0B06 = sub(r0AE3, r0AF2);
      ir_expression *const r0B07 = less(r0AE4, r0AF4);
      ir_expression *const r0B08 = expr(ir_unop_b2i, r0B07);
      ir_expression *const r0B09 = expr(ir_unop_i2u, r0B08);
      body.emit(assign(r0AE9, sub(r0B06, r0B09), 0x01));

      body.emit(assign(r0AE8, sub(r0AE4, r0AF4), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0B0A = new(mem_ctx) ir_loop();
      exec_list *const f0B0A_parent_instructions = body.instructions;

         body.instructions = &f0B0A->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0B0C = expr(ir_unop_u2i, r0AE9);
         ir_expression *const r0B0D = gequal(r0B0C, body.constant(int(0)));
         ir_if *f0B0B = new(mem_ctx) ir_if(operand(r0B0D).val);
         exec_list *const f0B0B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B0B->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0B0B_parent_instructions;
         body.emit(f0B0B);

         /* END IF */

         body.emit(assign(r0AE7, add(r0AE7, body.constant(4294901760u)), 0x01));

         ir_variable *const r0B0E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0B0F = lshift(r0AE5, body.constant(int(16)));
         body.emit(assign(r0B0E, add(r0AE8, r0B0F), 0x01));

         ir_expression *const r0B10 = add(r0AE9, r0AEA);
         ir_expression *const r0B11 = less(r0B0E, r0AE8);
         ir_expression *const r0B12 = expr(ir_unop_b2i, r0B11);
         ir_expression *const r0B13 = expr(ir_unop_i2u, r0B12);
         body.emit(assign(r0AE9, add(r0B10, r0B13), 0x01));

         body.emit(assign(r0AE8, r0B0E, 0x01));

      /* LOOP END */

      body.instructions = f0B0A_parent_instructions;
      body.emit(f0B0A);

      ir_expression *const r0B14 = lshift(r0AE9, body.constant(int(16)));
      ir_expression *const r0B15 = rshift(r0AE8, body.constant(int(16)));
      body.emit(assign(r0AE9, bit_or(r0B14, r0B15), 0x01));

      ir_variable *const r0B16 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0B18 = lshift(r0AEA, body.constant(int(16)));
      ir_expression *const r0B19 = gequal(r0AE9, r0B18);
      ir_if *f0B17 = new(mem_ctx) ir_if(operand(r0B19).val);
      exec_list *const f0B17_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B17->then_instructions;

         body.emit(assign(r0B16, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B17->else_instructions;

         body.emit(assign(r0B16, expr(ir_binop_div, r0AE9, r0AEA), 0x01));


      body.instructions = f0B17_parent_instructions;
      body.emit(f0B17);

      /* END IF */

      body.emit(assign(r0AE7, bit_or(r0AE7, r0B16), 0x01));

      body.emit(assign(r0AE6, r0AE7, 0x01));


   body.instructions = f0AEB_parent_instructions;
   body.emit(f0AEB);

   /* END IF */

   body.emit(ret(r0AE6));

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

   ir_variable *const r0B1A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B1A);
   ir_variable *const r0B1B = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0B1B, r0B1A, 0x03));

   ir_variable *const r0B1C = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B1D = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B1D, bit_and(swizzle_y(r0B1A), body.constant(1048575u)), 0x01));

   ir_variable *const r0B1E = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B1F = rshift(swizzle_y(r0B1A), body.constant(int(20)));
   ir_expression *const r0B20 = bit_and(r0B1F, body.constant(2047u));
   body.emit(assign(r0B1E, expr(ir_unop_u2i, r0B20), 0x01));

   ir_variable *const r0B21 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B21, rshift(swizzle_y(r0B1A), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B23 = equal(r0B1E, body.constant(int(2047)));
   ir_if *f0B22 = new(mem_ctx) ir_if(operand(r0B23).val);
   exec_list *const f0B22_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B22->then_instructions;

      ir_variable *const r0B24 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0B24);
      ir_expression *const r0B25 = lshift(swizzle_y(r0B1A), body.constant(int(12)));
      ir_expression *const r0B26 = rshift(swizzle_x(r0B1A), body.constant(int(20)));
      body.emit(assign(r0B1B, bit_or(r0B25, r0B26), 0x02));

      body.emit(assign(r0B1B, lshift(swizzle_x(r0B1A), body.constant(int(12))), 0x01));

      ir_expression *const r0B27 = lshift(r0B21, body.constant(int(31)));
      ir_expression *const r0B28 = bit_or(r0B27, body.constant(2143289344u));
      ir_expression *const r0B29 = rshift(swizzle_y(r0B1B), body.constant(int(9)));
      ir_expression *const r0B2A = bit_or(r0B28, r0B29);
      body.emit(assign(r0B24, expr(ir_unop_bitcast_u2f, r0B2A), 0x01));

      ir_variable *const r0B2B = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0B2C = bit_or(r0B1D, swizzle_x(r0B1A));
      ir_expression *const r0B2D = nequal(r0B2C, body.constant(0u));
      ir_expression *const r0B2E = lshift(r0B21, body.constant(int(31)));
      ir_expression *const r0B2F = add(r0B2E, body.constant(2139095040u));
      ir_expression *const r0B30 = expr(ir_unop_bitcast_u2f, r0B2F);
      body.emit(assign(r0B2B, expr(ir_triop_csel, r0B2D, r0B24, r0B30), 0x01));

      body.emit(assign(r0B24, r0B2B, 0x01));

      body.emit(assign(r0B1C, r0B2B, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B22->else_instructions;

      ir_variable *const r0B31 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B31);
      ir_variable *const r0B32 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0B32, rshift(r0B1D, body.constant(int(22))), 0x01));

      ir_expression *const r0B33 = lshift(r0B1D, body.constant(int(10)));
      ir_expression *const r0B34 = rshift(swizzle_x(r0B1A), body.constant(int(22)));
      ir_expression *const r0B35 = bit_or(r0B33, r0B34);
      ir_expression *const r0B36 = lshift(swizzle_x(r0B1A), body.constant(int(10)));
      ir_expression *const r0B37 = nequal(r0B36, body.constant(0u));
      ir_expression *const r0B38 = expr(ir_unop_b2i, r0B37);
      ir_expression *const r0B39 = expr(ir_unop_i2u, r0B38);
      body.emit(assign(r0B31, bit_or(r0B35, r0B39), 0x01));

      ir_variable *const r0B3A = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0B3B = nequal(r0B1E, body.constant(int(0)));
      ir_expression *const r0B3C = bit_or(r0B31, body.constant(1073741824u));
      body.emit(assign(r0B3A, expr(ir_triop_csel, r0B3B, r0B3C, r0B31), 0x01));

      ir_variable *const r0B3D = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B3D, add(r0B1E, body.constant(int(-897))), 0x01));

      ir_variable *const r0B3E = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B3E, r0B3A, 0x01));

      ir_variable *const r0B3F = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B3F, body.constant(true), 0x01));

      ir_variable *const r0B40 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B41 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B41);
      ir_expression *const r0B42 = bit_and(r0B3A, body.constant(127u));
      body.emit(assign(r0B41, expr(ir_unop_u2i, r0B42), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B44 = expr(ir_unop_i2u, r0B3D);
      ir_expression *const r0B45 = gequal(r0B44, body.constant(253u));
      ir_if *f0B43 = new(mem_ctx) ir_if(operand(r0B45).val);
      exec_list *const f0B43_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B43->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B47 = less(body.constant(int(253)), r0B3D);
         ir_expression *const r0B48 = equal(r0B3D, body.constant(int(253)));
         ir_expression *const r0B49 = expr(ir_unop_u2i, r0B3A);
         ir_expression *const r0B4A = less(r0B49, body.constant(int(-64)));
         ir_expression *const r0B4B = logic_and(r0B48, r0B4A);
         ir_expression *const r0B4C = logic_or(r0B47, r0B4B);
         ir_if *f0B46 = new(mem_ctx) ir_if(operand(r0B4C).val);
         exec_list *const f0B46_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B46->then_instructions;

            ir_expression *const r0B4D = lshift(r0B21, body.constant(int(31)));
            ir_expression *const r0B4E = add(r0B4D, body.constant(2139095040u));
            body.emit(assign(r0B40, expr(ir_unop_bitcast_u2f, r0B4E), 0x01));

            body.emit(assign(r0B3F, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B46->else_instructions;

            ir_variable *const r0B4F = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B4F, neg(r0B3D), 0x01));

            ir_variable *const r0B50 = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0B50, less(r0B3D, body.constant(int(0))), 0x01));

            ir_variable *const r0B51 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0B52 = neg(r0B3D);
            ir_expression *const r0B53 = less(r0B52, body.constant(int(32)));
            ir_expression *const r0B54 = rshift(r0B3A, r0B4F);
            ir_expression *const r0B55 = neg(r0B4F);
            ir_expression *const r0B56 = bit_and(r0B55, body.constant(int(31)));
            ir_expression *const r0B57 = lshift(r0B3A, r0B56);
            ir_expression *const r0B58 = nequal(r0B57, body.constant(0u));
            ir_expression *const r0B59 = expr(ir_unop_b2i, r0B58);
            ir_expression *const r0B5A = expr(ir_unop_i2u, r0B59);
            ir_expression *const r0B5B = bit_or(r0B54, r0B5A);
            ir_expression *const r0B5C = nequal(r0B3A, body.constant(0u));
            ir_expression *const r0B5D = expr(ir_unop_b2i, r0B5C);
            ir_expression *const r0B5E = expr(ir_unop_i2u, r0B5D);
            ir_expression *const r0B5F = expr(ir_triop_csel, r0B53, r0B5B, r0B5E);
            body.emit(assign(r0B51, expr(ir_triop_csel, r0B50, r0B5F, r0B3A), 0x01));

            body.emit(assign(r0B3E, r0B51, 0x01));

            ir_expression *const r0B60 = expr(ir_unop_u2i, r0B51);
            ir_expression *const r0B61 = bit_and(r0B60, body.constant(int(127)));
            body.emit(assign(r0B41, expr(ir_triop_csel, r0B50, r0B61, r0B41), 0x01));

            body.emit(assign(r0B3D, expr(ir_triop_csel, r0B50, body.constant(int(0)), r0B3D), 0x01));


         body.instructions = f0B46_parent_instructions;
         body.emit(f0B46);

         /* END IF */


      body.instructions = f0B43_parent_instructions;
      body.emit(f0B43);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B62 = new(mem_ctx) ir_if(operand(r0B3F).val);
      exec_list *const f0B62_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B62->then_instructions;

         ir_expression *const r0B63 = add(r0B3E, body.constant(64u));
         body.emit(assign(r0B3E, rshift(r0B63, body.constant(int(7))), 0x01));

         ir_expression *const r0B64 = bit_xor(r0B41, body.constant(int(64)));
         ir_expression *const r0B65 = equal(r0B64, body.constant(int(0)));
         ir_expression *const r0B66 = expr(ir_unop_b2i, r0B65);
         ir_expression *const r0B67 = expr(ir_unop_i2u, r0B66);
         ir_expression *const r0B68 = expr(ir_unop_bit_not, r0B67);
         body.emit(assign(r0B3E, bit_and(r0B3E, r0B68), 0x01));

         ir_expression *const r0B69 = lshift(r0B21, body.constant(int(31)));
         ir_expression *const r0B6A = equal(r0B3E, body.constant(0u));
         ir_expression *const r0B6B = expr(ir_triop_csel, r0B6A, body.constant(int(0)), r0B3D);
         ir_expression *const r0B6C = expr(ir_unop_i2u, r0B6B);
         ir_expression *const r0B6D = lshift(r0B6C, body.constant(int(23)));
         ir_expression *const r0B6E = add(r0B69, r0B6D);
         ir_expression *const r0B6F = add(r0B6E, r0B3E);
         body.emit(assign(r0B40, expr(ir_unop_bitcast_u2f, r0B6F), 0x01));

         body.emit(assign(r0B3F, body.constant(false), 0x01));


      body.instructions = f0B62_parent_instructions;
      body.emit(f0B62);

      /* END IF */

      body.emit(assign(r0B1C, r0B40, 0x01));


   body.instructions = f0B22_parent_instructions;
   body.emit(f0B22);

   /* END IF */

   ir_variable *const r0B70 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B70, body.constant(true), 0x01));

   ir_variable *const r0B71 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B72 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B72);
   ir_variable *const r0B73 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B73);
   ir_variable *const r0B74 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B74);
   ir_variable *const r0B75 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0B76 = expr(ir_unop_sqrt, r0B1C);
   body.emit(assign(r0B75, expr(ir_unop_bitcast_f2u, r0B76), 0x01));

   ir_variable *const r0B77 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B77, bit_and(r0B75, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B74, r0B77, 0x01));

   ir_variable *const r0B78 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B79 = rshift(r0B75, body.constant(int(23)));
   ir_expression *const r0B7A = bit_and(r0B79, body.constant(255u));
   body.emit(assign(r0B78, expr(ir_unop_u2i, r0B7A), 0x01));

   body.emit(assign(r0B73, r0B78, 0x01));

   body.emit(assign(r0B72, rshift(r0B75, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B7C = equal(r0B78, body.constant(int(255)));
   ir_if *f0B7B = new(mem_ctx) ir_if(operand(r0B7C).val);
   exec_list *const f0B7B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B7B->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B7E = nequal(r0B77, body.constant(0u));
      ir_if *f0B7D = new(mem_ctx) ir_if(operand(r0B7E).val);
      exec_list *const f0B7D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B7D->then_instructions;

         ir_variable *const r0B7F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B7F, lshift(r0B75, body.constant(int(9))), 0x01));

         ir_variable *const r0B80 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B81 = lshift(r0B7F, body.constant(int(20)));
         body.emit(assign(r0B80, bit_or(r0B81, body.constant(0u)), 0x01));

         ir_expression *const r0B82 = rshift(r0B7F, body.constant(int(12)));
         ir_expression *const r0B83 = lshift(r0B72, body.constant(int(31)));
         ir_expression *const r0B84 = bit_or(r0B83, body.constant(2146959360u));
         body.emit(assign(r0B80, bit_or(r0B82, r0B84), 0x02));

         body.emit(assign(r0B71, r0B80, 0x03));

         body.emit(assign(r0B70, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B7D->else_instructions;

         ir_variable *const r0B85 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B85);
         ir_expression *const r0B86 = lshift(r0B72, body.constant(int(31)));
         body.emit(assign(r0B85, add(r0B86, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B85, body.constant(0u), 0x01));

         body.emit(assign(r0B71, r0B85, 0x03));

         body.emit(assign(r0B70, body.constant(false), 0x01));


      body.instructions = f0B7D_parent_instructions;
      body.emit(f0B7D);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B7B->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B88 = equal(r0B78, body.constant(int(0)));
      ir_if *f0B87 = new(mem_ctx) ir_if(operand(r0B88).val);
      exec_list *const f0B87_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B87->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B8A = equal(r0B77, body.constant(0u));
         ir_if *f0B89 = new(mem_ctx) ir_if(operand(r0B8A).val);
         exec_list *const f0B89_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B89->then_instructions;

            ir_variable *const r0B8B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B8B);
            body.emit(assign(r0B8B, lshift(r0B72, body.constant(int(31))), 0x02));

            body.emit(assign(r0B8B, body.constant(0u), 0x01));

            body.emit(assign(r0B71, r0B8B, 0x03));

            body.emit(assign(r0B70, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B89->else_instructions;

            ir_variable *const r0B8C = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0B8D = equal(r0B77, body.constant(0u));
            ir_expression *const r0B8E = expr(ir_unop_find_msb, r0B77);
            ir_expression *const r0B8F = sub(body.constant(int(31)), r0B8E);
            ir_expression *const r0B90 = expr(ir_triop_csel, r0B8D, body.constant(int(32)), r0B8F);
            body.emit(assign(r0B8C, add(r0B90, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B74, lshift(r0B77, r0B8C), 0x01));

            body.emit(assign(r0B73, sub(body.constant(int(1)), r0B8C), 0x01));

            body.emit(assign(r0B73, add(r0B73, body.constant(int(-1))), 0x01));


         body.instructions = f0B89_parent_instructions;
         body.emit(f0B89);

         /* END IF */


      body.instructions = f0B87_parent_instructions;
      body.emit(f0B87);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B91 = new(mem_ctx) ir_if(operand(r0B70).val);
      exec_list *const f0B91_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B91->then_instructions;

         ir_variable *const r0B92 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B92);
         ir_expression *const r0B93 = lshift(r0B72, body.constant(int(31)));
         ir_expression *const r0B94 = add(r0B73, body.constant(int(896)));
         ir_expression *const r0B95 = expr(ir_unop_i2u, r0B94);
         ir_expression *const r0B96 = lshift(r0B95, body.constant(int(20)));
         ir_expression *const r0B97 = add(r0B93, r0B96);
         ir_expression *const r0B98 = rshift(r0B74, body.constant(int(3)));
         body.emit(assign(r0B92, add(r0B97, r0B98), 0x02));

         ir_expression *const r0B99 = lshift(r0B74, body.constant(int(29)));
         body.emit(assign(r0B92, bit_or(r0B99, body.constant(0u)), 0x01));

         body.emit(assign(r0B71, r0B92, 0x03));

         body.emit(assign(r0B70, body.constant(false), 0x01));


      body.instructions = f0B91_parent_instructions;
      body.emit(f0B91);

      /* END IF */


   body.instructions = f0B7B_parent_instructions;
   body.emit(f0B7B);

   /* END IF */

   body.emit(ret(r0B71));

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

   ir_variable *const r0B9A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B9A);
   ir_variable *const r0B9B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B9C = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B9D = rshift(swizzle_y(r0B9A), body.constant(int(20)));
   ir_expression *const r0B9E = bit_and(r0B9D, body.constant(2047u));
   ir_expression *const r0B9F = expr(ir_unop_u2i, r0B9E);
   body.emit(assign(r0B9C, add(r0B9F, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BA1 = less(r0B9C, body.constant(int(0)));
   ir_if *f0BA0 = new(mem_ctx) ir_if(operand(r0BA1).val);
   exec_list *const f0BA0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BA0->then_instructions;

      body.emit(assign(r0B9B, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BA0->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0BA3 = less(body.constant(int(52)), r0B9C);
      ir_if *f0BA2 = new(mem_ctx) ir_if(operand(r0BA3).val);
      exec_list *const f0BA2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BA2->then_instructions;

         body.emit(assign(r0B9B, r0B9A, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BA2->else_instructions;

         ir_variable *const r0BA4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0BA4, sub(body.constant(int(52)), r0B9C), 0x01));

         ir_variable *const r0BA5 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0BA7 = gequal(r0BA4, body.constant(int(32)));
         ir_if *f0BA6 = new(mem_ctx) ir_if(operand(r0BA7).val);
         exec_list *const f0BA6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BA6->then_instructions;

            body.emit(assign(r0BA5, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BA6->else_instructions;

            body.emit(assign(r0BA5, lshift(body.constant(4294967295u), r0BA4), 0x01));


         body.instructions = f0BA6_parent_instructions;
         body.emit(f0BA6);

         /* END IF */

         ir_variable *const r0BA8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0BAA = less(r0BA4, body.constant(int(33)));
         ir_if *f0BA9 = new(mem_ctx) ir_if(operand(r0BAA).val);
         exec_list *const f0BA9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BA9->then_instructions;

            body.emit(assign(r0BA8, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BA9->else_instructions;

            ir_expression *const r0BAB = add(r0BA4, body.constant(int(-32)));
            body.emit(assign(r0BA8, lshift(body.constant(4294967295u), r0BAB), 0x01));


         body.instructions = f0BA9_parent_instructions;
         body.emit(f0BA9);

         /* END IF */

         ir_variable *const r0BAC = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0BAC, bit_and(r0BA5, swizzle_x(r0B9A)), 0x01));

         body.emit(assign(r0BAC, bit_and(r0BA8, swizzle_y(r0B9A)), 0x02));

         body.emit(assign(r0B9B, r0BAC, 0x03));


      body.instructions = f0BA2_parent_instructions;
      body.emit(f0BA2);

      /* END IF */


   body.instructions = f0BA0_parent_instructions;
   body.emit(f0BA0);

   /* END IF */

   body.emit(ret(r0B9B));

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

   ir_variable *const r0BAD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BAD);
   ir_variable *const r0BAE = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0BAE, body.constant(true), 0x01));

   ir_variable *const r0BAF = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0BB0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0BB0);
   ir_variable *const r0BB1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0BB1);
   ir_variable *const r0BB2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0BB3 = rshift(swizzle_y(r0BAD), body.constant(int(20)));
   ir_expression *const r0BB4 = bit_and(r0BB3, body.constant(2047u));
   ir_expression *const r0BB5 = expr(ir_unop_u2i, r0BB4);
   body.emit(assign(r0BB2, add(r0BB5, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0BB1, swizzle_y(r0BAD), 0x01));

   body.emit(assign(r0BB0, swizzle_x(r0BAD), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BB7 = less(r0BB2, body.constant(int(20)));
   ir_if *f0BB6 = new(mem_ctx) ir_if(operand(r0BB7).val);
   exec_list *const f0BB6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BB6->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0BB9 = less(r0BB2, body.constant(int(0)));
      ir_if *f0BB8 = new(mem_ctx) ir_if(operand(r0BB9).val);
      exec_list *const f0BB8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BB8->then_instructions;

         body.emit(assign(r0BB1, bit_and(swizzle_y(r0BAD), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BBB = equal(r0BB2, body.constant(int(-1)));
         ir_expression *const r0BBC = nequal(swizzle_x(r0BAD), body.constant(0u));
         ir_expression *const r0BBD = logic_and(r0BBB, r0BBC);
         ir_if *f0BBA = new(mem_ctx) ir_if(operand(r0BBD).val);
         exec_list *const f0BBA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BBA->then_instructions;

            body.emit(assign(r0BB1, bit_or(r0BB1, body.constant(1072693248u)), 0x01));


         body.instructions = f0BBA_parent_instructions;
         body.emit(f0BBA);

         /* END IF */

         body.emit(assign(r0BB0, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BB8->else_instructions;

         ir_variable *const r0BBE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0BBE, rshift(body.constant(1048575u), r0BB2), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BC0 = bit_and(r0BB1, r0BBE);
         ir_expression *const r0BC1 = equal(r0BC0, body.constant(0u));
         ir_expression *const r0BC2 = equal(r0BB0, body.constant(0u));
         ir_expression *const r0BC3 = logic_and(r0BC1, r0BC2);
         ir_if *f0BBF = new(mem_ctx) ir_if(operand(r0BC3).val);
         exec_list *const f0BBF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BBF->then_instructions;

            body.emit(assign(r0BAF, r0BAD, 0x03));

            body.emit(assign(r0BAE, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BBF->else_instructions;

            ir_expression *const r0BC4 = rshift(body.constant(524288u), r0BB2);
            body.emit(assign(r0BB1, add(r0BB1, r0BC4), 0x01));

            ir_expression *const r0BC5 = expr(ir_unop_bit_not, r0BBE);
            body.emit(assign(r0BB1, bit_and(r0BB1, r0BC5), 0x01));

            body.emit(assign(r0BB0, body.constant(0u), 0x01));


         body.instructions = f0BBF_parent_instructions;
         body.emit(f0BBF);

         /* END IF */


      body.instructions = f0BB8_parent_instructions;
      body.emit(f0BB8);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BB6->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0BC7 = less(body.constant(int(51)), r0BB2);
      ir_expression *const r0BC8 = equal(r0BB2, body.constant(int(1024)));
      ir_expression *const r0BC9 = logic_or(r0BC7, r0BC8);
      ir_if *f0BC6 = new(mem_ctx) ir_if(operand(r0BC9).val);
      exec_list *const f0BC6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BC6->then_instructions;

         body.emit(assign(r0BAF, r0BAD, 0x03));

         body.emit(assign(r0BAE, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BC6->else_instructions;

         ir_variable *const r0BCA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0BCB = add(r0BB2, body.constant(int(-20)));
         body.emit(assign(r0BCA, rshift(body.constant(4294967295u), r0BCB), 0x01));

         /* IF CONDITION */
         ir_expression *const r0BCD = bit_and(r0BB0, r0BCA);
         ir_expression *const r0BCE = equal(r0BCD, body.constant(0u));
         ir_if *f0BCC = new(mem_ctx) ir_if(operand(r0BCE).val);
         exec_list *const f0BCC_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BCC->then_instructions;

            body.emit(assign(r0BAF, r0BAD, 0x03));

            body.emit(assign(r0BAE, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0BCC->else_instructions;

            ir_variable *const r0BCF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0BD0 = sub(body.constant(int(51)), r0BB2);
            ir_expression *const r0BD1 = lshift(body.constant(1u), r0BD0);
            body.emit(assign(r0BCF, add(r0BB0, r0BD1), 0x01));

            /* IF CONDITION */
            ir_expression *const r0BD3 = less(r0BCF, r0BB0);
            ir_if *f0BD2 = new(mem_ctx) ir_if(operand(r0BD3).val);
            exec_list *const f0BD2_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0BD2->then_instructions;

               body.emit(assign(r0BB1, add(r0BB1, body.constant(1u)), 0x01));


            body.instructions = f0BD2_parent_instructions;
            body.emit(f0BD2);

            /* END IF */

            ir_expression *const r0BD4 = expr(ir_unop_bit_not, r0BCA);
            body.emit(assign(r0BB0, bit_and(r0BCF, r0BD4), 0x01));


         body.instructions = f0BCC_parent_instructions;
         body.emit(f0BCC);

         /* END IF */


      body.instructions = f0BC6_parent_instructions;
      body.emit(f0BC6);

      /* END IF */


   body.instructions = f0BB6_parent_instructions;
   body.emit(f0BB6);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0BD5 = new(mem_ctx) ir_if(operand(r0BAE).val);
   exec_list *const f0BD5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BD5->then_instructions;

      body.emit(assign(r0BAD, r0BB0, 0x01));

      body.emit(assign(r0BAD, r0BB1, 0x02));

      body.emit(assign(r0BAF, r0BAD, 0x03));

      body.emit(assign(r0BAE, body.constant(false), 0x01));


   body.instructions = f0BD5_parent_instructions;
   body.emit(f0BD5);

   /* END IF */

   body.emit(ret(r0BAF));

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

   ir_variable *const r0BD6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BD6);
   ir_variable *const r0BD7 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0BD7, r0BD6, 0x03));

   ir_variable *const r0BD8 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0BD9 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0BD9, bit_and(swizzle_y(r0BD6), body.constant(1048575u)), 0x01));

   ir_variable *const r0BDA = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0BDB = rshift(swizzle_y(r0BD6), body.constant(int(20)));
   ir_expression *const r0BDC = bit_and(r0BDB, body.constant(2047u));
   body.emit(assign(r0BDA, expr(ir_unop_u2i, r0BDC), 0x01));

   ir_variable *const r0BDD = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0BDD, rshift(swizzle_y(r0BD6), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BDF = equal(r0BDA, body.constant(int(2047)));
   ir_if *f0BDE = new(mem_ctx) ir_if(operand(r0BDF).val);
   exec_list *const f0BDE_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BDE->then_instructions;

      ir_variable *const r0BE0 = new(mem_ctx) ir_variable(glsl_type::float_type, "rval", ir_var_auto);
      body.emit(r0BE0);
      ir_expression *const r0BE1 = lshift(swizzle_y(r0BD6), body.constant(int(12)));
      ir_expression *const r0BE2 = rshift(swizzle_x(r0BD6), body.constant(int(20)));
      body.emit(assign(r0BD7, bit_or(r0BE1, r0BE2), 0x02));

      body.emit(assign(r0BD7, lshift(swizzle_x(r0BD6), body.constant(int(12))), 0x01));

      ir_expression *const r0BE3 = lshift(r0BDD, body.constant(int(31)));
      ir_expression *const r0BE4 = bit_or(r0BE3, body.constant(2143289344u));
      ir_expression *const r0BE5 = rshift(swizzle_y(r0BD7), body.constant(int(9)));
      ir_expression *const r0BE6 = bit_or(r0BE4, r0BE5);
      body.emit(assign(r0BE0, expr(ir_unop_bitcast_u2f, r0BE6), 0x01));

      ir_variable *const r0BE7 = body.make_temp(glsl_type::float_type, "mix_retval");
      ir_expression *const r0BE8 = bit_or(r0BD9, swizzle_x(r0BD6));
      ir_expression *const r0BE9 = nequal(r0BE8, body.constant(0u));
      ir_expression *const r0BEA = lshift(r0BDD, body.constant(int(31)));
      ir_expression *const r0BEB = add(r0BEA, body.constant(2139095040u));
      ir_expression *const r0BEC = expr(ir_unop_bitcast_u2f, r0BEB);
      body.emit(assign(r0BE7, expr(ir_triop_csel, r0BE9, r0BE0, r0BEC), 0x01));

      body.emit(assign(r0BE0, r0BE7, 0x01));

      body.emit(assign(r0BD8, r0BE7, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BDE->else_instructions;

      ir_variable *const r0BED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BED);
      ir_variable *const r0BEE = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0BEE, rshift(r0BD9, body.constant(int(22))), 0x01));

      ir_expression *const r0BEF = lshift(r0BD9, body.constant(int(10)));
      ir_expression *const r0BF0 = rshift(swizzle_x(r0BD6), body.constant(int(22)));
      ir_expression *const r0BF1 = bit_or(r0BEF, r0BF0);
      ir_expression *const r0BF2 = lshift(swizzle_x(r0BD6), body.constant(int(10)));
      ir_expression *const r0BF3 = nequal(r0BF2, body.constant(0u));
      ir_expression *const r0BF4 = expr(ir_unop_b2i, r0BF3);
      ir_expression *const r0BF5 = expr(ir_unop_i2u, r0BF4);
      body.emit(assign(r0BED, bit_or(r0BF1, r0BF5), 0x01));

      ir_variable *const r0BF6 = body.make_temp(glsl_type::uint_type, "mix_retval");
      ir_expression *const r0BF7 = nequal(r0BDA, body.constant(int(0)));
      ir_expression *const r0BF8 = bit_or(r0BED, body.constant(1073741824u));
      body.emit(assign(r0BF6, expr(ir_triop_csel, r0BF7, r0BF8, r0BED), 0x01));

      ir_variable *const r0BF9 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0BF9, add(r0BDA, body.constant(int(-897))), 0x01));

      ir_variable *const r0BFA = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0BFA, r0BF6, 0x01));

      ir_variable *const r0BFB = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0BFB, body.constant(true), 0x01));

      ir_variable *const r0BFC = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0BFD = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0BFD);
      ir_expression *const r0BFE = bit_and(r0BF6, body.constant(127u));
      body.emit(assign(r0BFD, expr(ir_unop_u2i, r0BFE), 0x01));

      /* IF CONDITION */
      ir_expression *const r0C00 = expr(ir_unop_i2u, r0BF9);
      ir_expression *const r0C01 = gequal(r0C00, body.constant(253u));
      ir_if *f0BFF = new(mem_ctx) ir_if(operand(r0C01).val);
      exec_list *const f0BFF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BFF->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C03 = less(body.constant(int(253)), r0BF9);
         ir_expression *const r0C04 = equal(r0BF9, body.constant(int(253)));
         ir_expression *const r0C05 = expr(ir_unop_u2i, r0BF6);
         ir_expression *const r0C06 = less(r0C05, body.constant(int(-64)));
         ir_expression *const r0C07 = logic_and(r0C04, r0C06);
         ir_expression *const r0C08 = logic_or(r0C03, r0C07);
         ir_if *f0C02 = new(mem_ctx) ir_if(operand(r0C08).val);
         exec_list *const f0C02_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C02->then_instructions;

            ir_expression *const r0C09 = lshift(r0BDD, body.constant(int(31)));
            ir_expression *const r0C0A = add(r0C09, body.constant(2139095040u));
            body.emit(assign(r0BFC, expr(ir_unop_bitcast_u2f, r0C0A), 0x01));

            body.emit(assign(r0BFB, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C02->else_instructions;

            ir_variable *const r0C0B = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0C0B, neg(r0BF9), 0x01));

            ir_variable *const r0C0C = body.make_temp(glsl_type::bool_type, "assignment_tmp");
            body.emit(assign(r0C0C, less(r0BF9, body.constant(int(0))), 0x01));

            ir_variable *const r0C0D = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0C0E = neg(r0BF9);
            ir_expression *const r0C0F = less(r0C0E, body.constant(int(32)));
            ir_expression *const r0C10 = rshift(r0BF6, r0C0B);
            ir_expression *const r0C11 = neg(r0C0B);
            ir_expression *const r0C12 = bit_and(r0C11, body.constant(int(31)));
            ir_expression *const r0C13 = lshift(r0BF6, r0C12);
            ir_expression *const r0C14 = nequal(r0C13, body.constant(0u));
            ir_expression *const r0C15 = expr(ir_unop_b2i, r0C14);
            ir_expression *const r0C16 = expr(ir_unop_i2u, r0C15);
            ir_expression *const r0C17 = bit_or(r0C10, r0C16);
            ir_expression *const r0C18 = nequal(r0BF6, body.constant(0u));
            ir_expression *const r0C19 = expr(ir_unop_b2i, r0C18);
            ir_expression *const r0C1A = expr(ir_unop_i2u, r0C19);
            ir_expression *const r0C1B = expr(ir_triop_csel, r0C0F, r0C17, r0C1A);
            body.emit(assign(r0C0D, expr(ir_triop_csel, r0C0C, r0C1B, r0BF6), 0x01));

            body.emit(assign(r0BFA, r0C0D, 0x01));

            ir_expression *const r0C1C = expr(ir_unop_u2i, r0C0D);
            ir_expression *const r0C1D = bit_and(r0C1C, body.constant(int(127)));
            body.emit(assign(r0BFD, expr(ir_triop_csel, r0C0C, r0C1D, r0BFD), 0x01));

            body.emit(assign(r0BF9, expr(ir_triop_csel, r0C0C, body.constant(int(0)), r0BF9), 0x01));


         body.instructions = f0C02_parent_instructions;
         body.emit(f0C02);

         /* END IF */


      body.instructions = f0BFF_parent_instructions;
      body.emit(f0BFF);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C1E = new(mem_ctx) ir_if(operand(r0BFB).val);
      exec_list *const f0C1E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C1E->then_instructions;

         ir_expression *const r0C1F = add(r0BFA, body.constant(64u));
         body.emit(assign(r0BFA, rshift(r0C1F, body.constant(int(7))), 0x01));

         ir_expression *const r0C20 = bit_xor(r0BFD, body.constant(int(64)));
         ir_expression *const r0C21 = equal(r0C20, body.constant(int(0)));
         ir_expression *const r0C22 = expr(ir_unop_b2i, r0C21);
         ir_expression *const r0C23 = expr(ir_unop_i2u, r0C22);
         ir_expression *const r0C24 = expr(ir_unop_bit_not, r0C23);
         body.emit(assign(r0BFA, bit_and(r0BFA, r0C24), 0x01));

         ir_expression *const r0C25 = lshift(r0BDD, body.constant(int(31)));
         ir_expression *const r0C26 = equal(r0BFA, body.constant(0u));
         ir_expression *const r0C27 = expr(ir_triop_csel, r0C26, body.constant(int(0)), r0BF9);
         ir_expression *const r0C28 = expr(ir_unop_i2u, r0C27);
         ir_expression *const r0C29 = lshift(r0C28, body.constant(int(23)));
         ir_expression *const r0C2A = add(r0C25, r0C29);
         ir_expression *const r0C2B = add(r0C2A, r0BFA);
         body.emit(assign(r0BFC, expr(ir_unop_bitcast_u2f, r0C2B), 0x01));

         body.emit(assign(r0BFB, body.constant(false), 0x01));


      body.instructions = f0C1E_parent_instructions;
      body.emit(f0C1E);

      /* END IF */

      body.emit(assign(r0BD8, r0BFC, 0x01));


   body.instructions = f0BDE_parent_instructions;
   body.emit(f0BDE);

   /* END IF */

   ir_variable *const r0C2C = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C2C, body.constant(true), 0x01));

   ir_variable *const r0C2D = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C2E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C2E);
   ir_variable *const r0C2F = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C2F);
   ir_variable *const r0C30 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C30);
   ir_variable *const r0C31 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C32 = expr(ir_unop_rcp, r0BD8);
   body.emit(assign(r0C31, expr(ir_unop_bitcast_f2u, r0C32), 0x01));

   ir_variable *const r0C33 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C33, bit_and(r0C31, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C30, r0C33, 0x01));

   ir_variable *const r0C34 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C35 = rshift(r0C31, body.constant(int(23)));
   ir_expression *const r0C36 = bit_and(r0C35, body.constant(255u));
   body.emit(assign(r0C34, expr(ir_unop_u2i, r0C36), 0x01));

   body.emit(assign(r0C2F, r0C34, 0x01));

   body.emit(assign(r0C2E, rshift(r0C31, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C38 = equal(r0C34, body.constant(int(255)));
   ir_if *f0C37 = new(mem_ctx) ir_if(operand(r0C38).val);
   exec_list *const f0C37_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C37->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C3A = nequal(r0C33, body.constant(0u));
      ir_if *f0C39 = new(mem_ctx) ir_if(operand(r0C3A).val);
      exec_list *const f0C39_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C39->then_instructions;

         ir_variable *const r0C3B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C3B, lshift(r0C31, body.constant(int(9))), 0x01));

         ir_variable *const r0C3C = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C3D = lshift(r0C3B, body.constant(int(20)));
         body.emit(assign(r0C3C, bit_or(r0C3D, body.constant(0u)), 0x01));

         ir_expression *const r0C3E = rshift(r0C3B, body.constant(int(12)));
         ir_expression *const r0C3F = lshift(r0C2E, body.constant(int(31)));
         ir_expression *const r0C40 = bit_or(r0C3F, body.constant(2146959360u));
         body.emit(assign(r0C3C, bit_or(r0C3E, r0C40), 0x02));

         body.emit(assign(r0C2D, r0C3C, 0x03));

         body.emit(assign(r0C2C, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C39->else_instructions;

         ir_variable *const r0C41 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C41);
         ir_expression *const r0C42 = lshift(r0C2E, body.constant(int(31)));
         body.emit(assign(r0C41, add(r0C42, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C41, body.constant(0u), 0x01));

         body.emit(assign(r0C2D, r0C41, 0x03));

         body.emit(assign(r0C2C, body.constant(false), 0x01));


      body.instructions = f0C39_parent_instructions;
      body.emit(f0C39);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C37->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C44 = equal(r0C34, body.constant(int(0)));
      ir_if *f0C43 = new(mem_ctx) ir_if(operand(r0C44).val);
      exec_list *const f0C43_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C43->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C46 = equal(r0C33, body.constant(0u));
         ir_if *f0C45 = new(mem_ctx) ir_if(operand(r0C46).val);
         exec_list *const f0C45_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C45->then_instructions;

            ir_variable *const r0C47 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C47);
            body.emit(assign(r0C47, lshift(r0C2E, body.constant(int(31))), 0x02));

            body.emit(assign(r0C47, body.constant(0u), 0x01));

            body.emit(assign(r0C2D, r0C47, 0x03));

            body.emit(assign(r0C2C, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C45->else_instructions;

            ir_variable *const r0C48 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0C49 = equal(r0C33, body.constant(0u));
            ir_expression *const r0C4A = expr(ir_unop_find_msb, r0C33);
            ir_expression *const r0C4B = sub(body.constant(int(31)), r0C4A);
            ir_expression *const r0C4C = expr(ir_triop_csel, r0C49, body.constant(int(32)), r0C4B);
            body.emit(assign(r0C48, add(r0C4C, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C30, lshift(r0C33, r0C48), 0x01));

            body.emit(assign(r0C2F, sub(body.constant(int(1)), r0C48), 0x01));

            body.emit(assign(r0C2F, add(r0C2F, body.constant(int(-1))), 0x01));


         body.instructions = f0C45_parent_instructions;
         body.emit(f0C45);

         /* END IF */


      body.instructions = f0C43_parent_instructions;
      body.emit(f0C43);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C4D = new(mem_ctx) ir_if(operand(r0C2C).val);
      exec_list *const f0C4D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C4D->then_instructions;

         ir_variable *const r0C4E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C4E);
         ir_expression *const r0C4F = lshift(r0C2E, body.constant(int(31)));
         ir_expression *const r0C50 = add(r0C2F, body.constant(int(896)));
         ir_expression *const r0C51 = expr(ir_unop_i2u, r0C50);
         ir_expression *const r0C52 = lshift(r0C51, body.constant(int(20)));
         ir_expression *const r0C53 = add(r0C4F, r0C52);
         ir_expression *const r0C54 = rshift(r0C30, body.constant(int(3)));
         body.emit(assign(r0C4E, add(r0C53, r0C54), 0x02));

         ir_expression *const r0C55 = lshift(r0C30, body.constant(int(29)));
         body.emit(assign(r0C4E, bit_or(r0C55, body.constant(0u)), 0x01));

         body.emit(assign(r0C2D, r0C4E, 0x03));

         body.emit(assign(r0C2C, body.constant(false), 0x01));


      body.instructions = f0C4D_parent_instructions;
      body.emit(f0C4D);

      /* END IF */


   body.instructions = f0C37_parent_instructions;
   body.emit(f0C37);

   /* END IF */

   body.emit(ret(r0C2D));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
