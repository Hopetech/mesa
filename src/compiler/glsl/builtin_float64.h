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
   ir_variable *const r002E = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r002F = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r002F);
   ir_variable *const r0030 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0030);
   ir_expression *const r0031 = rshift(swizzle_y(r002C), body.constant(int(20)));
   ir_expression *const r0032 = bit_and(r0031, body.constant(2047u));
   ir_expression *const r0033 = expr(ir_unop_u2i, r0032);
   ir_expression *const r0034 = equal(r0033, body.constant(int(2047)));
   ir_expression *const r0035 = bit_and(swizzle_y(r002C), body.constant(1048575u));
   ir_expression *const r0036 = bit_or(r0035, swizzle_x(r002C));
   ir_expression *const r0037 = nequal(r0036, body.constant(0u));
   body.emit(assign(r0030, logic_and(r0034, r0037), 0x01));

   ir_expression *const r0038 = rshift(swizzle_y(r002D), body.constant(int(20)));
   ir_expression *const r0039 = bit_and(r0038, body.constant(2047u));
   ir_expression *const r003A = expr(ir_unop_u2i, r0039);
   ir_expression *const r003B = equal(r003A, body.constant(int(2047)));
   ir_expression *const r003C = bit_and(swizzle_y(r002D), body.constant(1048575u));
   ir_expression *const r003D = bit_or(r003C, swizzle_x(r002D));
   ir_expression *const r003E = nequal(r003D, body.constant(0u));
   body.emit(assign(r002F, logic_and(r003B, r003E), 0x01));

   /* IF CONDITION */
   ir_expression *const r0040 = logic_or(r0030, r002F);
   ir_if *f003F = new(mem_ctx) ir_if(operand(r0040).val);
   exec_list *const f003F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f003F->then_instructions;

      body.emit(assign(r002E, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f003F->else_instructions;

      ir_expression *const r0041 = equal(swizzle_x(r002C), swizzle_x(r002D));
      ir_expression *const r0042 = equal(swizzle_y(r002C), swizzle_y(r002D));
      ir_expression *const r0043 = equal(swizzle_x(r002C), body.constant(0u));
      ir_expression *const r0044 = bit_or(swizzle_y(r002C), swizzle_y(r002D));
      ir_expression *const r0045 = lshift(r0044, body.constant(int(1)));
      ir_expression *const r0046 = equal(r0045, body.constant(0u));
      ir_expression *const r0047 = logic_and(r0043, r0046);
      ir_expression *const r0048 = logic_or(r0042, r0047);
      body.emit(assign(r002E, logic_and(r0041, r0048), 0x01));


   body.instructions = f003F_parent_instructions;
   body.emit(f003F);

   /* END IF */

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
   ir_variable *const r0139 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r013A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r013A);
   /* IF CONDITION */
   ir_expression *const r013C = equal(r0138, body.constant(0u));
   ir_if *f013B = new(mem_ctx) ir_if(operand(r013C).val);
   exec_list *const f013B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f013B->then_instructions;

      body.emit(assign(r0139, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f013B->else_instructions;

      body.emit(assign(r013A, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r013E = bit_and(r0138, body.constant(4294901760u));
      ir_expression *const r013F = equal(r013E, body.constant(0u));
      ir_if *f013D = new(mem_ctx) ir_if(operand(r013F).val);
      exec_list *const f013D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f013D->then_instructions;

         body.emit(assign(r013A, body.constant(int(16)), 0x01));

         body.emit(assign(r0138, lshift(r0138, body.constant(int(16))), 0x01));


      body.instructions = f013D_parent_instructions;
      body.emit(f013D);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0141 = bit_and(r0138, body.constant(4278190080u));
      ir_expression *const r0142 = equal(r0141, body.constant(0u));
      ir_if *f0140 = new(mem_ctx) ir_if(operand(r0142).val);
      exec_list *const f0140_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0140->then_instructions;

         body.emit(assign(r013A, add(r013A, body.constant(int(8))), 0x01));

         body.emit(assign(r0138, lshift(r0138, body.constant(int(8))), 0x01));


      body.instructions = f0140_parent_instructions;
      body.emit(f0140);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0144 = bit_and(r0138, body.constant(4026531840u));
      ir_expression *const r0145 = equal(r0144, body.constant(0u));
      ir_if *f0143 = new(mem_ctx) ir_if(operand(r0145).val);
      exec_list *const f0143_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0143->then_instructions;

         body.emit(assign(r013A, add(r013A, body.constant(int(4))), 0x01));

         body.emit(assign(r0138, lshift(r0138, body.constant(int(4))), 0x01));


      body.instructions = f0143_parent_instructions;
      body.emit(f0143);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0147 = bit_and(r0138, body.constant(3221225472u));
      ir_expression *const r0148 = equal(r0147, body.constant(0u));
      ir_if *f0146 = new(mem_ctx) ir_if(operand(r0148).val);
      exec_list *const f0146_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0146->then_instructions;

         body.emit(assign(r013A, add(r013A, body.constant(int(2))), 0x01));

         body.emit(assign(r0138, lshift(r0138, body.constant(int(2))), 0x01));


      body.instructions = f0146_parent_instructions;
      body.emit(f0146);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r014A = bit_and(r0138, body.constant(2147483648u));
      ir_expression *const r014B = equal(r014A, body.constant(0u));
      ir_if *f0149 = new(mem_ctx) ir_if(operand(r014B).val);
      exec_list *const f0149_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0149->then_instructions;

         body.emit(assign(r013A, add(r013A, body.constant(int(1))), 0x01));


      body.instructions = f0149_parent_instructions;
      body.emit(f0149);

      /* END IF */

      body.emit(assign(r0139, r013A, 0x01));


   body.instructions = f013B_parent_instructions;
   body.emit(f013B);

   /* END IF */

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

   ir_variable *const r014C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r014C);
   ir_variable *const r014D = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r014D);
   ir_variable *const r014E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r014E);
   ir_variable *const r014F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r014F);
   ir_variable *const r0150 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0150);
   ir_variable *const r0151 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0151);
   ir_expression *const r0152 = equal(r014E, body.constant(0u));
   ir_expression *const r0153 = add(r014D, body.constant(int(-32)));
   body.emit(assign(r014D, expr(ir_triop_csel, r0152, r0153, r014D), 0x01));

   ir_variable *const r0154 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r0155 = equal(r014E, body.constant(0u));
   body.emit(assign(r0154, expr(ir_triop_csel, r0155, body.constant(0u), r014F), 0x01));

   body.emit(assign(r014F, r0154, 0x01));

   ir_variable *const r0156 = body.make_temp(glsl_type::uint_type, "mix_retval");
   ir_expression *const r0157 = equal(r014E, body.constant(0u));
   body.emit(assign(r0156, expr(ir_triop_csel, r0157, r0154, r014E), 0x01));

   body.emit(assign(r014E, r0156, 0x01));

   ir_variable *const r0158 = body.make_temp(glsl_type::uint_type, "a");
   body.emit(assign(r0158, r0156, 0x01));

   ir_variable *const r0159 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r015A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r015A);
   /* IF CONDITION */
   ir_expression *const r015C = equal(r0156, body.constant(0u));
   ir_if *f015B = new(mem_ctx) ir_if(operand(r015C).val);
   exec_list *const f015B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f015B->then_instructions;

      body.emit(assign(r0159, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f015B->else_instructions;

      body.emit(assign(r015A, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r015E = bit_and(r0156, body.constant(4294901760u));
      ir_expression *const r015F = equal(r015E, body.constant(0u));
      ir_if *f015D = new(mem_ctx) ir_if(operand(r015F).val);
      exec_list *const f015D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f015D->then_instructions;

         body.emit(assign(r015A, body.constant(int(16)), 0x01));

         body.emit(assign(r0158, lshift(r0156, body.constant(int(16))), 0x01));


      body.instructions = f015D_parent_instructions;
      body.emit(f015D);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0161 = bit_and(r0158, body.constant(4278190080u));
      ir_expression *const r0162 = equal(r0161, body.constant(0u));
      ir_if *f0160 = new(mem_ctx) ir_if(operand(r0162).val);
      exec_list *const f0160_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0160->then_instructions;

         body.emit(assign(r015A, add(r015A, body.constant(int(8))), 0x01));

         body.emit(assign(r0158, lshift(r0158, body.constant(int(8))), 0x01));


      body.instructions = f0160_parent_instructions;
      body.emit(f0160);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0164 = bit_and(r0158, body.constant(4026531840u));
      ir_expression *const r0165 = equal(r0164, body.constant(0u));
      ir_if *f0163 = new(mem_ctx) ir_if(operand(r0165).val);
      exec_list *const f0163_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0163->then_instructions;

         body.emit(assign(r015A, add(r015A, body.constant(int(4))), 0x01));

         body.emit(assign(r0158, lshift(r0158, body.constant(int(4))), 0x01));


      body.instructions = f0163_parent_instructions;
      body.emit(f0163);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0167 = bit_and(r0158, body.constant(3221225472u));
      ir_expression *const r0168 = equal(r0167, body.constant(0u));
      ir_if *f0166 = new(mem_ctx) ir_if(operand(r0168).val);
      exec_list *const f0166_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0166->then_instructions;

         body.emit(assign(r015A, add(r015A, body.constant(int(2))), 0x01));

         body.emit(assign(r0158, lshift(r0158, body.constant(int(2))), 0x01));


      body.instructions = f0166_parent_instructions;
      body.emit(f0166);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r016A = bit_and(r0158, body.constant(2147483648u));
      ir_expression *const r016B = equal(r016A, body.constant(0u));
      ir_if *f0169 = new(mem_ctx) ir_if(operand(r016B).val);
      exec_list *const f0169_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0169->then_instructions;

         body.emit(assign(r015A, add(r015A, body.constant(int(1))), 0x01));


      body.instructions = f0169_parent_instructions;
      body.emit(f0169);

      /* END IF */

      body.emit(assign(r0159, r015A, 0x01));


   body.instructions = f015B_parent_instructions;
   body.emit(f015B);

   /* END IF */

   body.emit(assign(r0151, add(r0159, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r016D = gequal(r0151, body.constant(int(0)));
   ir_if *f016C = new(mem_ctx) ir_if(operand(r016D).val);
   exec_list *const f016C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f016C->then_instructions;

      body.emit(assign(r0150, body.constant(0u), 0x01));

      ir_expression *const r016E = equal(r0151, body.constant(int(0)));
      ir_expression *const r016F = lshift(r0156, r0151);
      ir_expression *const r0170 = neg(r0151);
      ir_expression *const r0171 = bit_and(r0170, body.constant(int(31)));
      ir_expression *const r0172 = rshift(r0154, r0171);
      ir_expression *const r0173 = bit_or(r016F, r0172);
      body.emit(assign(r014E, expr(ir_triop_csel, r016E, r0156, r0173), 0x01));

      body.emit(assign(r014F, lshift(r0154, r0151), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f016C->else_instructions;

      ir_variable *const r0174 = body.make_temp(glsl_type::uint_type, "a2");
      body.emit(assign(r0174, body.constant(0u), 0x01));

      ir_variable *const r0175 = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r0175, neg(r0151), 0x01));

      ir_variable *const r0176 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
      body.emit(r0176);
      ir_variable *const r0177 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0177);
      ir_variable *const r0178 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0178);
      ir_variable *const r0179 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r017A = neg(r0175);
      body.emit(assign(r0179, bit_and(r017A, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r017C = equal(r0175, body.constant(int(0)));
      ir_if *f017B = new(mem_ctx) ir_if(operand(r017C).val);
      exec_list *const f017B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f017B->then_instructions;

         body.emit(assign(r0176, r0174, 0x01));

         body.emit(assign(r0177, r014F, 0x01));

         body.emit(assign(r0178, r014E, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f017B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r017E = less(r0175, body.constant(int(32)));
         ir_if *f017D = new(mem_ctx) ir_if(operand(r017E).val);
         exec_list *const f017D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f017D->then_instructions;

            body.emit(assign(r0176, lshift(r014F, r0179), 0x01));

            ir_expression *const r017F = lshift(r014E, r0179);
            ir_expression *const r0180 = rshift(r014F, r0175);
            body.emit(assign(r0177, bit_or(r017F, r0180), 0x01));

            body.emit(assign(r0178, rshift(r014E, r0175), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f017D->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0182 = equal(r0175, body.constant(int(32)));
            ir_if *f0181 = new(mem_ctx) ir_if(operand(r0182).val);
            exec_list *const f0181_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0181->then_instructions;

               body.emit(assign(r0176, r014F, 0x01));

               body.emit(assign(r0177, r014E, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0181->else_instructions;

               body.emit(assign(r0174, bit_or(body.constant(0u), r014F), 0x01));

               ir_expression *const r0183 = less(r0175, body.constant(int(64)));
               ir_expression *const r0184 = lshift(r014E, r0179);
               ir_expression *const r0185 = equal(r0175, body.constant(int(64)));
               ir_expression *const r0186 = nequal(r014E, body.constant(0u));
               ir_expression *const r0187 = expr(ir_unop_b2i, r0186);
               ir_expression *const r0188 = expr(ir_unop_i2u, r0187);
               ir_expression *const r0189 = expr(ir_triop_csel, r0185, r014E, r0188);
               body.emit(assign(r0176, expr(ir_triop_csel, r0183, r0184, r0189), 0x01));

               ir_expression *const r018A = less(r0175, body.constant(int(64)));
               ir_expression *const r018B = bit_and(r0175, body.constant(int(31)));
               ir_expression *const r018C = rshift(r014E, r018B);
               body.emit(assign(r0177, expr(ir_triop_csel, r018A, r018C, body.constant(0u)), 0x01));


            body.instructions = f0181_parent_instructions;
            body.emit(f0181);

            /* END IF */

            body.emit(assign(r0178, body.constant(0u), 0x01));


         body.instructions = f017D_parent_instructions;
         body.emit(f017D);

         /* END IF */

         ir_expression *const r018D = nequal(r0174, body.constant(0u));
         ir_expression *const r018E = expr(ir_unop_b2i, r018D);
         ir_expression *const r018F = expr(ir_unop_i2u, r018E);
         body.emit(assign(r0176, bit_or(r0176, r018F), 0x01));


      body.instructions = f017B_parent_instructions;
      body.emit(f017B);

      /* END IF */

      body.emit(assign(r014E, r0178, 0x01));

      body.emit(assign(r014F, r0177, 0x01));

      body.emit(assign(r0150, r0176, 0x01));


   body.instructions = f016C_parent_instructions;
   body.emit(f016C);

   /* END IF */

   body.emit(assign(r014D, sub(r014D, r0151), 0x01));

   ir_variable *const r0190 = body.make_temp(glsl_type::int_type, "zExp");
   body.emit(assign(r0190, r014D, 0x01));

   ir_variable *const r0191 = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r0191, r014E, 0x01));

   ir_variable *const r0192 = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r0192, r014F, 0x01));

   ir_variable *const r0193 = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r0193, r0150, 0x01));

   ir_variable *const r0194 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0194, body.constant(true), 0x01));

   ir_variable *const r0195 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0196 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r0196);
   ir_expression *const r0197 = expr(ir_unop_u2i, r0150);
   body.emit(assign(r0196, less(r0197, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0199 = gequal(r014D, body.constant(int(2045)));
   ir_if *f0198 = new(mem_ctx) ir_if(operand(r0199).val);
   exec_list *const f0198_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0198->then_instructions;

      /* IF CONDITION */
      ir_expression *const r019B = less(body.constant(int(2045)), r014D);
      ir_expression *const r019C = equal(r014D, body.constant(int(2045)));
      ir_expression *const r019D = equal(body.constant(2097151u), r014E);
      ir_expression *const r019E = equal(body.constant(4294967295u), r014F);
      ir_expression *const r019F = logic_and(r019D, r019E);
      ir_expression *const r01A0 = logic_and(r019C, r019F);
      ir_expression *const r01A1 = logic_and(r01A0, r0196);
      ir_expression *const r01A2 = logic_or(r019B, r01A1);
      ir_if *f019A = new(mem_ctx) ir_if(operand(r01A2).val);
      exec_list *const f019A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f019A->then_instructions;

         ir_variable *const r01A3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r01A3);
         ir_expression *const r01A4 = lshift(r014C, body.constant(int(31)));
         body.emit(assign(r01A3, add(r01A4, body.constant(2146435072u)), 0x02));

         body.emit(assign(r01A3, body.constant(0u), 0x01));

         body.emit(assign(r0195, r01A3, 0x03));

         body.emit(assign(r0194, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f019A->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01A6 = less(r014D, body.constant(int(0)));
         ir_if *f01A5 = new(mem_ctx) ir_if(operand(r01A6).val);
         exec_list *const f01A5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01A5->then_instructions;

            ir_variable *const r01A7 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r01A7, r0150, 0x01));

            ir_variable *const r01A8 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r01A8, neg(r014D), 0x01));

            ir_variable *const r01A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r01A9);
            ir_variable *const r01AA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r01AA);
            ir_variable *const r01AB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r01AB);
            ir_variable *const r01AC = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r01AD = neg(r01A8);
            body.emit(assign(r01AC, bit_and(r01AD, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r01AF = equal(r01A8, body.constant(int(0)));
            ir_if *f01AE = new(mem_ctx) ir_if(operand(r01AF).val);
            exec_list *const f01AE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01AE->then_instructions;

               body.emit(assign(r01A9, r0150, 0x01));

               body.emit(assign(r01AA, r014F, 0x01));

               body.emit(assign(r01AB, r014E, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01AE->else_instructions;

               /* IF CONDITION */
               ir_expression *const r01B1 = less(r01A8, body.constant(int(32)));
               ir_if *f01B0 = new(mem_ctx) ir_if(operand(r01B1).val);
               exec_list *const f01B0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f01B0->then_instructions;

                  body.emit(assign(r01A9, lshift(r014F, r01AC), 0x01));

                  ir_expression *const r01B2 = lshift(r014E, r01AC);
                  ir_expression *const r01B3 = rshift(r014F, r01A8);
                  body.emit(assign(r01AA, bit_or(r01B2, r01B3), 0x01));

                  body.emit(assign(r01AB, rshift(r014E, r01A8), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f01B0->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r01B5 = equal(r01A8, body.constant(int(32)));
                  ir_if *f01B4 = new(mem_ctx) ir_if(operand(r01B5).val);
                  exec_list *const f01B4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f01B4->then_instructions;

                     body.emit(assign(r01A9, r014F, 0x01));

                     body.emit(assign(r01AA, r014E, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f01B4->else_instructions;

                     body.emit(assign(r01A7, bit_or(r0150, r014F), 0x01));

                     ir_expression *const r01B6 = less(r01A8, body.constant(int(64)));
                     ir_expression *const r01B7 = lshift(r014E, r01AC);
                     ir_expression *const r01B8 = equal(r01A8, body.constant(int(64)));
                     ir_expression *const r01B9 = nequal(r014E, body.constant(0u));
                     ir_expression *const r01BA = expr(ir_unop_b2i, r01B9);
                     ir_expression *const r01BB = expr(ir_unop_i2u, r01BA);
                     ir_expression *const r01BC = expr(ir_triop_csel, r01B8, r014E, r01BB);
                     body.emit(assign(r01A9, expr(ir_triop_csel, r01B6, r01B7, r01BC), 0x01));

                     ir_expression *const r01BD = less(r01A8, body.constant(int(64)));
                     ir_expression *const r01BE = bit_and(r01A8, body.constant(int(31)));
                     ir_expression *const r01BF = rshift(r014E, r01BE);
                     body.emit(assign(r01AA, expr(ir_triop_csel, r01BD, r01BF, body.constant(0u)), 0x01));


                  body.instructions = f01B4_parent_instructions;
                  body.emit(f01B4);

                  /* END IF */

                  body.emit(assign(r01AB, body.constant(0u), 0x01));


               body.instructions = f01B0_parent_instructions;
               body.emit(f01B0);

               /* END IF */

               ir_expression *const r01C0 = nequal(r01A7, body.constant(0u));
               ir_expression *const r01C1 = expr(ir_unop_b2i, r01C0);
               ir_expression *const r01C2 = expr(ir_unop_i2u, r01C1);
               body.emit(assign(r01A9, bit_or(r01A9, r01C2), 0x01));


            body.instructions = f01AE_parent_instructions;
            body.emit(f01AE);

            /* END IF */

            body.emit(assign(r0191, r01AB, 0x01));

            body.emit(assign(r0192, r01AA, 0x01));

            body.emit(assign(r0193, r01A9, 0x01));

            body.emit(assign(r0190, body.constant(int(0)), 0x01));

            body.emit(assign(r0196, less(r01A9, body.constant(0u)), 0x01));


         body.instructions = f01A5_parent_instructions;
         body.emit(f01A5);

         /* END IF */


      body.instructions = f019A_parent_instructions;
      body.emit(f019A);

      /* END IF */


   body.instructions = f0198_parent_instructions;
   body.emit(f0198);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01C3 = new(mem_ctx) ir_if(operand(r0194).val);
   exec_list *const f01C3_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01C3->then_instructions;

      /* IF CONDITION */
      ir_if *f01C4 = new(mem_ctx) ir_if(operand(r0196).val);
      exec_list *const f01C4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01C4->then_instructions;

         ir_variable *const r01C5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01C5, add(r0192, body.constant(1u)), 0x01));

         ir_expression *const r01C6 = less(r01C5, r0192);
         ir_expression *const r01C7 = expr(ir_unop_b2i, r01C6);
         ir_expression *const r01C8 = expr(ir_unop_i2u, r01C7);
         body.emit(assign(r0191, add(r0191, r01C8), 0x01));

         ir_expression *const r01C9 = equal(r0193, body.constant(0u));
         ir_expression *const r01CA = expr(ir_unop_b2i, r01C9);
         ir_expression *const r01CB = expr(ir_unop_i2u, r01CA);
         ir_expression *const r01CC = add(r0193, r01CB);
         ir_expression *const r01CD = bit_and(r01CC, body.constant(1u));
         ir_expression *const r01CE = expr(ir_unop_bit_not, r01CD);
         body.emit(assign(r0192, bit_and(r01C5, r01CE), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01C4->else_instructions;

         ir_expression *const r01CF = bit_or(r0191, r0192);
         ir_expression *const r01D0 = equal(r01CF, body.constant(0u));
         body.emit(assign(r0190, expr(ir_triop_csel, r01D0, body.constant(int(0)), r0190), 0x01));


      body.instructions = f01C4_parent_instructions;
      body.emit(f01C4);

      /* END IF */

      ir_variable *const r01D1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r01D1);
      ir_expression *const r01D2 = lshift(r014C, body.constant(int(31)));
      ir_expression *const r01D3 = expr(ir_unop_i2u, r0190);
      ir_expression *const r01D4 = lshift(r01D3, body.constant(int(20)));
      ir_expression *const r01D5 = add(r01D2, r01D4);
      body.emit(assign(r01D1, add(r01D5, r0191), 0x02));

      body.emit(assign(r01D1, r0192, 0x01));

      body.emit(assign(r0195, r01D1, 0x03));

      body.emit(assign(r0194, body.constant(false), 0x01));


   body.instructions = f01C3_parent_instructions;
   body.emit(f01C3);

   /* END IF */

   body.emit(ret(r0195));

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

   ir_variable *const r01D6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01D6);
   ir_variable *const r01D7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01D7);
   ir_variable *const r01D8 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01D9 = lshift(swizzle_y(r01D6), body.constant(int(1)));
   ir_expression *const r01DA = gequal(r01D9, body.constant(4292870144u));
   ir_expression *const r01DB = nequal(swizzle_x(r01D6), body.constant(0u));
   ir_expression *const r01DC = bit_and(swizzle_y(r01D6), body.constant(1048575u));
   ir_expression *const r01DD = nequal(r01DC, body.constant(0u));
   ir_expression *const r01DE = logic_or(r01DB, r01DD);
   body.emit(assign(r01D8, logic_and(r01DA, r01DE), 0x01));

   ir_variable *const r01DF = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01E0 = lshift(swizzle_y(r01D7), body.constant(int(1)));
   ir_expression *const r01E1 = gequal(r01E0, body.constant(4292870144u));
   ir_expression *const r01E2 = nequal(swizzle_x(r01D7), body.constant(0u));
   ir_expression *const r01E3 = bit_and(swizzle_y(r01D7), body.constant(1048575u));
   ir_expression *const r01E4 = nequal(r01E3, body.constant(0u));
   ir_expression *const r01E5 = logic_or(r01E2, r01E4);
   body.emit(assign(r01DF, logic_and(r01E1, r01E5), 0x01));

   body.emit(assign(r01D6, bit_or(swizzle_y(r01D6), body.constant(524288u)), 0x02));

   body.emit(assign(r01D7, bit_or(swizzle_y(r01D7), body.constant(524288u)), 0x02));

   ir_variable *const r01E6 = body.make_temp(glsl_type::uvec2_type, "mix_retval");
   ir_swizzle *const r01E7 = swizzle(r01D8, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_swizzle *const r01E8 = swizzle(r01DF, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_expression *const r01E9 = expr(ir_triop_csel, r01E8, r01D7, r01D6);
   body.emit(assign(r01E6, expr(ir_triop_csel, r01E7, r01E9, r01D7), 0x03));

   body.emit(ret(r01E6));

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

   ir_variable *const r01EA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01EA);
   ir_variable *const r01EB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01EB);
   ir_variable *const r01EC = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01EC, body.constant(true), 0x01));

   ir_variable *const r01ED = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r01EE);
   ir_variable *const r01EF = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01EF, rshift(swizzle_y(r01EA), body.constant(int(31))), 0x01));

   body.emit(assign(r01EE, r01EF, 0x01));

   ir_variable *const r01F0 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01F0, rshift(swizzle_y(r01EB), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r01F2 = equal(r01EF, r01F0);
   ir_if *f01F1 = new(mem_ctx) ir_if(operand(r01F2).val);
   exec_list *const f01F1_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01F1->then_instructions;

      ir_variable *const r01F3 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r01F3);
      ir_variable *const r01F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r01F4);
      ir_variable *const r01F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r01F5);
      ir_variable *const r01F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r01F6);
      ir_variable *const r01F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r01F7);
      ir_variable *const r01F8 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r01F8);
      ir_variable *const r01F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r01F9);
      ir_variable *const r01FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
      body.emit(r01FA);
      body.emit(assign(r01FA, body.constant(0u), 0x01));

      body.emit(assign(r01F9, body.constant(0u), 0x01));

      ir_variable *const r01FB = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01FB, swizzle_x(r01EA), 0x01));

      body.emit(assign(r01F7, r01FB, 0x01));

      ir_variable *const r01FC = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01FC, bit_and(swizzle_y(r01EA), body.constant(1048575u)), 0x01));

      body.emit(assign(r01F6, r01FC, 0x01));

      ir_variable *const r01FD = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01FD, swizzle_x(r01EB), 0x01));

      body.emit(assign(r01F5, r01FD, 0x01));

      ir_variable *const r01FE = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01FE, bit_and(swizzle_y(r01EB), body.constant(1048575u)), 0x01));

      body.emit(assign(r01F4, r01FE, 0x01));

      ir_variable *const r01FF = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r0200 = rshift(swizzle_y(r01EA), body.constant(int(20)));
      ir_expression *const r0201 = bit_and(r0200, body.constant(2047u));
      body.emit(assign(r01FF, expr(ir_unop_u2i, r0201), 0x01));

      ir_variable *const r0202 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r0203 = rshift(swizzle_y(r01EB), body.constant(int(20)));
      ir_expression *const r0204 = bit_and(r0203, body.constant(2047u));
      body.emit(assign(r0202, expr(ir_unop_u2i, r0204), 0x01));

      ir_variable *const r0205 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0205, sub(r01FF, r0202), 0x01));

      body.emit(assign(r01F3, r0205, 0x01));

      /* IF CONDITION */
      ir_expression *const r0207 = less(body.constant(int(0)), r0205);
      ir_if *f0206 = new(mem_ctx) ir_if(operand(r0207).val);
      exec_list *const f0206_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0206->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0209 = equal(r01FF, body.constant(int(2047)));
         ir_if *f0208 = new(mem_ctx) ir_if(operand(r0209).val);
         exec_list *const f0208_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0208->then_instructions;

            /* IF CONDITION */
            ir_expression *const r020B = bit_or(r01FC, swizzle_x(r01EA));
            ir_expression *const r020C = nequal(r020B, body.constant(0u));
            ir_if *f020A = new(mem_ctx) ir_if(operand(r020C).val);
            exec_list *const f020A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f020A->then_instructions;

               ir_variable *const r020D = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r020D, swizzle_x(r01EA), 0x01));

               ir_variable *const r020E = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r020E, swizzle_x(r01EB), 0x01));

               body.emit(assign(r020D, bit_or(swizzle_y(r01EA), body.constant(524288u)), 0x02));

               body.emit(assign(r020E, bit_or(swizzle_y(r01EB), body.constant(524288u)), 0x02));

               ir_expression *const r020F = lshift(swizzle_y(r01EA), body.constant(int(1)));
               ir_expression *const r0210 = gequal(r020F, body.constant(4292870144u));
               ir_expression *const r0211 = nequal(swizzle_x(r01EA), body.constant(0u));
               ir_expression *const r0212 = bit_and(swizzle_y(r01EA), body.constant(1048575u));
               ir_expression *const r0213 = nequal(r0212, body.constant(0u));
               ir_expression *const r0214 = logic_or(r0211, r0213);
               ir_expression *const r0215 = logic_and(r0210, r0214);
               ir_swizzle *const r0216 = swizzle(r0215, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0217 = lshift(swizzle_y(r01EB), body.constant(int(1)));
               ir_expression *const r0218 = gequal(r0217, body.constant(4292870144u));
               ir_expression *const r0219 = nequal(swizzle_x(r01EB), body.constant(0u));
               ir_expression *const r021A = bit_and(swizzle_y(r01EB), body.constant(1048575u));
               ir_expression *const r021B = nequal(r021A, body.constant(0u));
               ir_expression *const r021C = logic_or(r0219, r021B);
               ir_expression *const r021D = logic_and(r0218, r021C);
               ir_swizzle *const r021E = swizzle(r021D, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r021F = expr(ir_triop_csel, r021E, r020E, r020D);
               body.emit(assign(r01ED, expr(ir_triop_csel, r0216, r021F, r020E), 0x03));

               body.emit(assign(r01EC, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f020A->else_instructions;

               body.emit(assign(r01ED, r01EA, 0x03));

               body.emit(assign(r01EC, body.constant(false), 0x01));


            body.instructions = f020A_parent_instructions;
            body.emit(f020A);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0208->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0221 = equal(r0202, body.constant(int(0)));
            ir_if *f0220 = new(mem_ctx) ir_if(operand(r0221).val);
            exec_list *const f0220_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0220->then_instructions;

               body.emit(assign(r01F3, add(r0205, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0220->else_instructions;

               body.emit(assign(r01F4, bit_or(r01FE, body.constant(1048576u)), 0x01));


            body.instructions = f0220_parent_instructions;
            body.emit(f0220);

            /* END IF */

            ir_variable *const r0222 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0222, body.constant(0u), 0x01));

            ir_variable *const r0223 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0223);
            ir_variable *const r0224 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0224);
            ir_variable *const r0225 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0225);
            ir_variable *const r0226 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0227 = neg(r01F3);
            body.emit(assign(r0226, bit_and(r0227, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0229 = equal(r01F3, body.constant(int(0)));
            ir_if *f0228 = new(mem_ctx) ir_if(operand(r0229).val);
            exec_list *const f0228_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0228->then_instructions;

               body.emit(assign(r0223, r0222, 0x01));

               body.emit(assign(r0224, r01FD, 0x01));

               body.emit(assign(r0225, r01F4, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0228->else_instructions;

               /* IF CONDITION */
               ir_expression *const r022B = less(r01F3, body.constant(int(32)));
               ir_if *f022A = new(mem_ctx) ir_if(operand(r022B).val);
               exec_list *const f022A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f022A->then_instructions;

                  body.emit(assign(r0223, lshift(swizzle_x(r01EB), r0226), 0x01));

                  ir_expression *const r022C = lshift(r01F4, r0226);
                  ir_expression *const r022D = rshift(swizzle_x(r01EB), r01F3);
                  body.emit(assign(r0224, bit_or(r022C, r022D), 0x01));

                  body.emit(assign(r0225, rshift(r01F4, r01F3), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f022A->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r022F = equal(r01F3, body.constant(int(32)));
                  ir_if *f022E = new(mem_ctx) ir_if(operand(r022F).val);
                  exec_list *const f022E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f022E->then_instructions;

                     body.emit(assign(r0223, r01FD, 0x01));

                     body.emit(assign(r0224, r01F4, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f022E->else_instructions;

                     body.emit(assign(r0222, bit_or(body.constant(0u), swizzle_x(r01EB)), 0x01));

                     ir_expression *const r0230 = less(r01F3, body.constant(int(64)));
                     ir_expression *const r0231 = lshift(r01F4, r0226);
                     ir_expression *const r0232 = equal(r01F3, body.constant(int(64)));
                     ir_expression *const r0233 = nequal(r01F4, body.constant(0u));
                     ir_expression *const r0234 = expr(ir_unop_b2i, r0233);
                     ir_expression *const r0235 = expr(ir_unop_i2u, r0234);
                     ir_expression *const r0236 = expr(ir_triop_csel, r0232, r01F4, r0235);
                     body.emit(assign(r0223, expr(ir_triop_csel, r0230, r0231, r0236), 0x01));

                     ir_expression *const r0237 = less(r01F3, body.constant(int(64)));
                     ir_expression *const r0238 = bit_and(r01F3, body.constant(int(31)));
                     ir_expression *const r0239 = rshift(r01F4, r0238);
                     body.emit(assign(r0224, expr(ir_triop_csel, r0237, r0239, body.constant(0u)), 0x01));


                  body.instructions = f022E_parent_instructions;
                  body.emit(f022E);

                  /* END IF */

                  body.emit(assign(r0225, body.constant(0u), 0x01));


               body.instructions = f022A_parent_instructions;
               body.emit(f022A);

               /* END IF */

               ir_expression *const r023A = nequal(r0222, body.constant(0u));
               ir_expression *const r023B = expr(ir_unop_b2i, r023A);
               ir_expression *const r023C = expr(ir_unop_i2u, r023B);
               body.emit(assign(r0223, bit_or(r0223, r023C), 0x01));


            body.instructions = f0228_parent_instructions;
            body.emit(f0228);

            /* END IF */

            body.emit(assign(r01F4, r0225, 0x01));

            body.emit(assign(r01F5, r0224, 0x01));

            body.emit(assign(r01F9, r0223, 0x01));

            body.emit(assign(r01F8, r01FF, 0x01));


         body.instructions = f0208_parent_instructions;
         body.emit(f0208);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0206->else_instructions;

         /* IF CONDITION */
         ir_expression *const r023E = less(r01F3, body.constant(int(0)));
         ir_if *f023D = new(mem_ctx) ir_if(operand(r023E).val);
         exec_list *const f023D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f023D->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0240 = equal(r0202, body.constant(int(2047)));
            ir_if *f023F = new(mem_ctx) ir_if(operand(r0240).val);
            exec_list *const f023F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f023F->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0242 = bit_or(r01F4, r01F5);
               ir_expression *const r0243 = nequal(r0242, body.constant(0u));
               ir_if *f0241 = new(mem_ctx) ir_if(operand(r0243).val);
               exec_list *const f0241_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0241->then_instructions;

                  ir_variable *const r0244 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0244, swizzle_x(r01EA), 0x01));

                  ir_variable *const r0245 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0245, swizzle_x(r01EB), 0x01));

                  body.emit(assign(r0244, bit_or(swizzle_y(r01EA), body.constant(524288u)), 0x02));

                  body.emit(assign(r0245, bit_or(swizzle_y(r01EB), body.constant(524288u)), 0x02));

                  ir_expression *const r0246 = lshift(swizzle_y(r01EA), body.constant(int(1)));
                  ir_expression *const r0247 = gequal(r0246, body.constant(4292870144u));
                  ir_expression *const r0248 = nequal(swizzle_x(r01EA), body.constant(0u));
                  ir_expression *const r0249 = bit_and(swizzle_y(r01EA), body.constant(1048575u));
                  ir_expression *const r024A = nequal(r0249, body.constant(0u));
                  ir_expression *const r024B = logic_or(r0248, r024A);
                  ir_expression *const r024C = logic_and(r0247, r024B);
                  ir_swizzle *const r024D = swizzle(r024C, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r024E = lshift(swizzle_y(r01EB), body.constant(int(1)));
                  ir_expression *const r024F = gequal(r024E, body.constant(4292870144u));
                  ir_expression *const r0250 = nequal(swizzle_x(r01EB), body.constant(0u));
                  ir_expression *const r0251 = bit_and(swizzle_y(r01EB), body.constant(1048575u));
                  ir_expression *const r0252 = nequal(r0251, body.constant(0u));
                  ir_expression *const r0253 = logic_or(r0250, r0252);
                  ir_expression *const r0254 = logic_and(r024F, r0253);
                  ir_swizzle *const r0255 = swizzle(r0254, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0256 = expr(ir_triop_csel, r0255, r0245, r0244);
                  body.emit(assign(r01ED, expr(ir_triop_csel, r024D, r0256, r0245), 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0241->else_instructions;

                  ir_variable *const r0257 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0257);
                  ir_expression *const r0258 = lshift(r01EF, body.constant(int(31)));
                  body.emit(assign(r0257, add(r0258, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0257, body.constant(0u), 0x01));

                  body.emit(assign(r01ED, r0257, 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


               body.instructions = f0241_parent_instructions;
               body.emit(f0241);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f023F->else_instructions;

               /* IF CONDITION */
               ir_expression *const r025A = equal(r01FF, body.constant(int(0)));
               ir_if *f0259 = new(mem_ctx) ir_if(operand(r025A).val);
               exec_list *const f0259_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0259->then_instructions;

                  body.emit(assign(r01F3, add(r01F3, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0259->else_instructions;

                  body.emit(assign(r01F6, bit_or(r01FC, body.constant(1048576u)), 0x01));


               body.instructions = f0259_parent_instructions;
               body.emit(f0259);

               /* END IF */

               ir_variable *const r025B = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r025B, body.constant(0u), 0x01));

               ir_variable *const r025C = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r025C, neg(r01F3), 0x01));

               ir_variable *const r025D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r025D);
               ir_variable *const r025E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r025E);
               ir_variable *const r025F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r025F);
               ir_variable *const r0260 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0261 = neg(r025C);
               body.emit(assign(r0260, bit_and(r0261, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0263 = equal(r025C, body.constant(int(0)));
               ir_if *f0262 = new(mem_ctx) ir_if(operand(r0263).val);
               exec_list *const f0262_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0262->then_instructions;

                  body.emit(assign(r025D, r025B, 0x01));

                  body.emit(assign(r025E, r01FB, 0x01));

                  body.emit(assign(r025F, r01F6, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0262->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0265 = less(r025C, body.constant(int(32)));
                  ir_if *f0264 = new(mem_ctx) ir_if(operand(r0265).val);
                  exec_list *const f0264_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0264->then_instructions;

                     body.emit(assign(r025D, lshift(swizzle_x(r01EA), r0260), 0x01));

                     ir_expression *const r0266 = lshift(r01F6, r0260);
                     ir_expression *const r0267 = rshift(swizzle_x(r01EA), r025C);
                     body.emit(assign(r025E, bit_or(r0266, r0267), 0x01));

                     body.emit(assign(r025F, rshift(r01F6, r025C), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0264->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0269 = equal(r025C, body.constant(int(32)));
                     ir_if *f0268 = new(mem_ctx) ir_if(operand(r0269).val);
                     exec_list *const f0268_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0268->then_instructions;

                        body.emit(assign(r025D, r01FB, 0x01));

                        body.emit(assign(r025E, r01F6, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0268->else_instructions;

                        body.emit(assign(r025B, bit_or(body.constant(0u), swizzle_x(r01EA)), 0x01));

                        ir_expression *const r026A = less(r025C, body.constant(int(64)));
                        ir_expression *const r026B = lshift(r01F6, r0260);
                        ir_expression *const r026C = equal(r025C, body.constant(int(64)));
                        ir_expression *const r026D = nequal(r01F6, body.constant(0u));
                        ir_expression *const r026E = expr(ir_unop_b2i, r026D);
                        ir_expression *const r026F = expr(ir_unop_i2u, r026E);
                        ir_expression *const r0270 = expr(ir_triop_csel, r026C, r01F6, r026F);
                        body.emit(assign(r025D, expr(ir_triop_csel, r026A, r026B, r0270), 0x01));

                        ir_expression *const r0271 = less(r025C, body.constant(int(64)));
                        ir_expression *const r0272 = bit_and(r025C, body.constant(int(31)));
                        ir_expression *const r0273 = rshift(r01F6, r0272);
                        body.emit(assign(r025E, expr(ir_triop_csel, r0271, r0273, body.constant(0u)), 0x01));


                     body.instructions = f0268_parent_instructions;
                     body.emit(f0268);

                     /* END IF */

                     body.emit(assign(r025F, body.constant(0u), 0x01));


                  body.instructions = f0264_parent_instructions;
                  body.emit(f0264);

                  /* END IF */

                  ir_expression *const r0274 = nequal(r025B, body.constant(0u));
                  ir_expression *const r0275 = expr(ir_unop_b2i, r0274);
                  ir_expression *const r0276 = expr(ir_unop_i2u, r0275);
                  body.emit(assign(r025D, bit_or(r025D, r0276), 0x01));


               body.instructions = f0262_parent_instructions;
               body.emit(f0262);

               /* END IF */

               body.emit(assign(r01F6, r025F, 0x01));

               body.emit(assign(r01F7, r025E, 0x01));

               body.emit(assign(r01F9, r025D, 0x01));

               body.emit(assign(r01F8, r0202, 0x01));


            body.instructions = f023F_parent_instructions;
            body.emit(f023F);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f023D->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0278 = equal(r01FF, body.constant(int(2047)));
            ir_if *f0277 = new(mem_ctx) ir_if(operand(r0278).val);
            exec_list *const f0277_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0277->then_instructions;

               /* IF CONDITION */
               ir_expression *const r027A = bit_or(r01F6, r01F7);
               ir_expression *const r027B = bit_or(r01F4, r01F5);
               ir_expression *const r027C = bit_or(r027A, r027B);
               ir_expression *const r027D = nequal(r027C, body.constant(0u));
               ir_if *f0279 = new(mem_ctx) ir_if(operand(r027D).val);
               exec_list *const f0279_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0279->then_instructions;

                  ir_variable *const r027E = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r027E, swizzle_x(r01EA), 0x01));

                  ir_variable *const r027F = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r027F, swizzle_x(r01EB), 0x01));

                  body.emit(assign(r027E, bit_or(swizzle_y(r01EA), body.constant(524288u)), 0x02));

                  body.emit(assign(r027F, bit_or(swizzle_y(r01EB), body.constant(524288u)), 0x02));

                  ir_expression *const r0280 = lshift(swizzle_y(r01EA), body.constant(int(1)));
                  ir_expression *const r0281 = gequal(r0280, body.constant(4292870144u));
                  ir_expression *const r0282 = nequal(swizzle_x(r01EA), body.constant(0u));
                  ir_expression *const r0283 = bit_and(swizzle_y(r01EA), body.constant(1048575u));
                  ir_expression *const r0284 = nequal(r0283, body.constant(0u));
                  ir_expression *const r0285 = logic_or(r0282, r0284);
                  ir_expression *const r0286 = logic_and(r0281, r0285);
                  ir_swizzle *const r0287 = swizzle(r0286, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0288 = lshift(swizzle_y(r01EB), body.constant(int(1)));
                  ir_expression *const r0289 = gequal(r0288, body.constant(4292870144u));
                  ir_expression *const r028A = nequal(swizzle_x(r01EB), body.constant(0u));
                  ir_expression *const r028B = bit_and(swizzle_y(r01EB), body.constant(1048575u));
                  ir_expression *const r028C = nequal(r028B, body.constant(0u));
                  ir_expression *const r028D = logic_or(r028A, r028C);
                  ir_expression *const r028E = logic_and(r0289, r028D);
                  ir_swizzle *const r028F = swizzle(r028E, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0290 = expr(ir_triop_csel, r028F, r027F, r027E);
                  body.emit(assign(r01ED, expr(ir_triop_csel, r0287, r0290, r027F), 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0279->else_instructions;

                  body.emit(assign(r01ED, r01EA, 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


               body.instructions = f0279_parent_instructions;
               body.emit(f0279);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0277->else_instructions;

               ir_variable *const r0291 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0292 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0292, add(r01F7, r01F5), 0x01));

               ir_expression *const r0293 = add(r01F6, r01F4);
               ir_expression *const r0294 = less(r0292, r01F7);
               ir_expression *const r0295 = expr(ir_unop_b2i, r0294);
               ir_expression *const r0296 = expr(ir_unop_i2u, r0295);
               body.emit(assign(r0291, add(r0293, r0296), 0x01));

               body.emit(assign(r01FA, r0291, 0x01));

               /* IF CONDITION */
               ir_expression *const r0298 = equal(r01FF, body.constant(int(0)));
               ir_if *f0297 = new(mem_ctx) ir_if(operand(r0298).val);
               exec_list *const f0297_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0297->then_instructions;

                  ir_variable *const r0299 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0299);
                  ir_expression *const r029A = lshift(r01EF, body.constant(int(31)));
                  body.emit(assign(r0299, add(r029A, r0291), 0x02));

                  body.emit(assign(r0299, r0292, 0x01));

                  body.emit(assign(r01ED, r0299, 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0297->else_instructions;

                  body.emit(assign(r01FA, bit_or(r0291, body.constant(2097152u)), 0x01));

                  body.emit(assign(r01F8, r01FF, 0x01));

                  ir_variable *const r029B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r029B);
                  ir_variable *const r029C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r029C);
                  ir_variable *const r029D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r029D);
                  body.emit(assign(r029B, lshift(r0292, body.constant(int(31))), 0x01));

                  ir_expression *const r029E = lshift(r01FA, body.constant(int(31)));
                  ir_expression *const r029F = rshift(r0292, body.constant(int(1)));
                  body.emit(assign(r029C, bit_or(r029E, r029F), 0x01));

                  body.emit(assign(r029D, rshift(r01FA, body.constant(int(1))), 0x01));

                  body.emit(assign(r029B, bit_or(r029B, body.constant(0u)), 0x01));

                  body.emit(assign(r01FA, r029D, 0x01));

                  body.emit(assign(r01F9, r029B, 0x01));

                  ir_variable *const r02A0 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r02A0, r01FF, 0x01));

                  ir_variable *const r02A1 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r02A1, r029D, 0x01));

                  ir_variable *const r02A2 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r02A2, r029C, 0x01));

                  ir_variable *const r02A3 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r02A3, r029B, 0x01));

                  ir_variable *const r02A4 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r02A4, body.constant(true), 0x01));

                  ir_variable *const r02A5 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r02A6 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r02A6);
                  ir_expression *const r02A7 = expr(ir_unop_u2i, r029B);
                  body.emit(assign(r02A6, less(r02A7, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r02A9 = gequal(r01FF, body.constant(int(2045)));
                  ir_if *f02A8 = new(mem_ctx) ir_if(operand(r02A9).val);
                  exec_list *const f02A8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02A8->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r02AB = less(body.constant(int(2045)), r01FF);
                     ir_expression *const r02AC = equal(r01FF, body.constant(int(2045)));
                     ir_expression *const r02AD = equal(body.constant(2097151u), r029D);
                     ir_expression *const r02AE = equal(body.constant(4294967295u), r029C);
                     ir_expression *const r02AF = logic_and(r02AD, r02AE);
                     ir_expression *const r02B0 = logic_and(r02AC, r02AF);
                     ir_expression *const r02B1 = logic_and(r02B0, r02A6);
                     ir_expression *const r02B2 = logic_or(r02AB, r02B1);
                     ir_if *f02AA = new(mem_ctx) ir_if(operand(r02B2).val);
                     exec_list *const f02AA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02AA->then_instructions;

                        ir_variable *const r02B3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r02B3);
                        ir_expression *const r02B4 = lshift(r01EF, body.constant(int(31)));
                        body.emit(assign(r02B3, add(r02B4, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r02B3, body.constant(0u), 0x01));

                        body.emit(assign(r02A5, r02B3, 0x03));

                        body.emit(assign(r02A4, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02AA->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02B6 = less(r01FF, body.constant(int(0)));
                        ir_if *f02B5 = new(mem_ctx) ir_if(operand(r02B6).val);
                        exec_list *const f02B5_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02B5->then_instructions;

                           ir_variable *const r02B7 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r02B7, r029B, 0x01));

                           ir_variable *const r02B8 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r02B8, neg(r01FF), 0x01));

                           ir_variable *const r02B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r02B9);
                           ir_variable *const r02BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r02BA);
                           ir_variable *const r02BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r02BB);
                           ir_variable *const r02BC = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02BD = neg(r02B8);
                           body.emit(assign(r02BC, bit_and(r02BD, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02BF = equal(r02B8, body.constant(int(0)));
                           ir_if *f02BE = new(mem_ctx) ir_if(operand(r02BF).val);
                           exec_list *const f02BE_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02BE->then_instructions;

                              body.emit(assign(r02B9, r029B, 0x01));

                              body.emit(assign(r02BA, r029C, 0x01));

                              body.emit(assign(r02BB, r029D, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02BE->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02C1 = less(r02B8, body.constant(int(32)));
                              ir_if *f02C0 = new(mem_ctx) ir_if(operand(r02C1).val);
                              exec_list *const f02C0_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02C0->then_instructions;

                                 body.emit(assign(r02B9, lshift(r029C, r02BC), 0x01));

                                 ir_expression *const r02C2 = lshift(r029D, r02BC);
                                 ir_expression *const r02C3 = rshift(r029C, r02B8);
                                 body.emit(assign(r02BA, bit_or(r02C2, r02C3), 0x01));

                                 body.emit(assign(r02BB, rshift(r029D, r02B8), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02C0->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02C5 = equal(r02B8, body.constant(int(32)));
                                 ir_if *f02C4 = new(mem_ctx) ir_if(operand(r02C5).val);
                                 exec_list *const f02C4_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02C4->then_instructions;

                                    body.emit(assign(r02B9, r029C, 0x01));

                                    body.emit(assign(r02BA, r029D, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02C4->else_instructions;

                                    body.emit(assign(r02B7, bit_or(r029B, r029C), 0x01));

                                    ir_expression *const r02C6 = less(r02B8, body.constant(int(64)));
                                    ir_expression *const r02C7 = lshift(r029D, r02BC);
                                    ir_expression *const r02C8 = equal(r02B8, body.constant(int(64)));
                                    ir_expression *const r02C9 = nequal(r029D, body.constant(0u));
                                    ir_expression *const r02CA = expr(ir_unop_b2i, r02C9);
                                    ir_expression *const r02CB = expr(ir_unop_i2u, r02CA);
                                    ir_expression *const r02CC = expr(ir_triop_csel, r02C8, r029D, r02CB);
                                    body.emit(assign(r02B9, expr(ir_triop_csel, r02C6, r02C7, r02CC), 0x01));

                                    ir_expression *const r02CD = less(r02B8, body.constant(int(64)));
                                    ir_expression *const r02CE = bit_and(r02B8, body.constant(int(31)));
                                    ir_expression *const r02CF = rshift(r029D, r02CE);
                                    body.emit(assign(r02BA, expr(ir_triop_csel, r02CD, r02CF, body.constant(0u)), 0x01));


                                 body.instructions = f02C4_parent_instructions;
                                 body.emit(f02C4);

                                 /* END IF */

                                 body.emit(assign(r02BB, body.constant(0u), 0x01));


                              body.instructions = f02C0_parent_instructions;
                              body.emit(f02C0);

                              /* END IF */

                              ir_expression *const r02D0 = nequal(r02B7, body.constant(0u));
                              ir_expression *const r02D1 = expr(ir_unop_b2i, r02D0);
                              ir_expression *const r02D2 = expr(ir_unop_i2u, r02D1);
                              body.emit(assign(r02B9, bit_or(r02B9, r02D2), 0x01));


                           body.instructions = f02BE_parent_instructions;
                           body.emit(f02BE);

                           /* END IF */

                           body.emit(assign(r02A1, r02BB, 0x01));

                           body.emit(assign(r02A2, r02BA, 0x01));

                           body.emit(assign(r02A3, r02B9, 0x01));

                           body.emit(assign(r02A0, body.constant(int(0)), 0x01));

                           body.emit(assign(r02A6, less(r02B9, body.constant(0u)), 0x01));


                        body.instructions = f02B5_parent_instructions;
                        body.emit(f02B5);

                        /* END IF */


                     body.instructions = f02AA_parent_instructions;
                     body.emit(f02AA);

                     /* END IF */


                  body.instructions = f02A8_parent_instructions;
                  body.emit(f02A8);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02D3 = new(mem_ctx) ir_if(operand(r02A4).val);
                  exec_list *const f02D3_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02D3->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02D4 = new(mem_ctx) ir_if(operand(r02A6).val);
                     exec_list *const f02D4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02D4->then_instructions;

                        ir_variable *const r02D5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02D5, add(r02A2, body.constant(1u)), 0x01));

                        ir_expression *const r02D6 = less(r02D5, r02A2);
                        ir_expression *const r02D7 = expr(ir_unop_b2i, r02D6);
                        ir_expression *const r02D8 = expr(ir_unop_i2u, r02D7);
                        body.emit(assign(r02A1, add(r02A1, r02D8), 0x01));

                        ir_expression *const r02D9 = equal(r02A3, body.constant(0u));
                        ir_expression *const r02DA = expr(ir_unop_b2i, r02D9);
                        ir_expression *const r02DB = expr(ir_unop_i2u, r02DA);
                        ir_expression *const r02DC = add(r02A3, r02DB);
                        ir_expression *const r02DD = bit_and(r02DC, body.constant(1u));
                        ir_expression *const r02DE = expr(ir_unop_bit_not, r02DD);
                        body.emit(assign(r02A2, bit_and(r02D5, r02DE), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02D4->else_instructions;

                        ir_expression *const r02DF = bit_or(r02A1, r02A2);
                        ir_expression *const r02E0 = equal(r02DF, body.constant(0u));
                        body.emit(assign(r02A0, expr(ir_triop_csel, r02E0, body.constant(int(0)), r02A0), 0x01));


                     body.instructions = f02D4_parent_instructions;
                     body.emit(f02D4);

                     /* END IF */

                     ir_variable *const r02E1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r02E1);
                     ir_expression *const r02E2 = lshift(r01EF, body.constant(int(31)));
                     ir_expression *const r02E3 = expr(ir_unop_i2u, r02A0);
                     ir_expression *const r02E4 = lshift(r02E3, body.constant(int(20)));
                     ir_expression *const r02E5 = add(r02E2, r02E4);
                     body.emit(assign(r02E1, add(r02E5, r02A1), 0x02));

                     body.emit(assign(r02E1, r02A2, 0x01));

                     body.emit(assign(r02A5, r02E1, 0x03));

                     body.emit(assign(r02A4, body.constant(false), 0x01));


                  body.instructions = f02D3_parent_instructions;
                  body.emit(f02D3);

                  /* END IF */

                  body.emit(assign(r01ED, r02A5, 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


               body.instructions = f0297_parent_instructions;
               body.emit(f0297);

               /* END IF */


            body.instructions = f0277_parent_instructions;
            body.emit(f0277);

            /* END IF */


         body.instructions = f023D_parent_instructions;
         body.emit(f023D);

         /* END IF */


      body.instructions = f0206_parent_instructions;
      body.emit(f0206);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02E6 = new(mem_ctx) ir_if(operand(r01EC).val);
      exec_list *const f02E6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02E6->then_instructions;

         body.emit(assign(r01F6, bit_or(r01F6, body.constant(1048576u)), 0x01));

         ir_variable *const r02E7 = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r02E8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r02E8, add(r01F7, r01F5), 0x01));

         ir_expression *const r02E9 = add(r01F6, r01F4);
         ir_expression *const r02EA = less(r02E8, r01F7);
         ir_expression *const r02EB = expr(ir_unop_b2i, r02EA);
         ir_expression *const r02EC = expr(ir_unop_i2u, r02EB);
         body.emit(assign(r02E7, add(r02E9, r02EC), 0x01));

         body.emit(assign(r01FA, r02E7, 0x01));

         body.emit(assign(r01F8, add(r01F8, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r02EE = less(r02E7, body.constant(2097152u));
         ir_if *f02ED = new(mem_ctx) ir_if(operand(r02EE).val);
         exec_list *const f02ED_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02ED->then_instructions;

            ir_variable *const r02EF = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r02EF, r01F8, 0x01));

            ir_variable *const r02F0 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r02F0, r02E7, 0x01));

            ir_variable *const r02F1 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r02F1, r02E8, 0x01));

            ir_variable *const r02F2 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r02F2, r01F9, 0x01));

            ir_variable *const r02F3 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r02F3, body.constant(true), 0x01));

            ir_variable *const r02F4 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r02F5 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r02F5);
            ir_expression *const r02F6 = expr(ir_unop_u2i, r01F9);
            body.emit(assign(r02F5, less(r02F6, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02F8 = gequal(r01F8, body.constant(int(2045)));
            ir_if *f02F7 = new(mem_ctx) ir_if(operand(r02F8).val);
            exec_list *const f02F7_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02F7->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02FA = less(body.constant(int(2045)), r01F8);
               ir_expression *const r02FB = equal(r01F8, body.constant(int(2045)));
               ir_expression *const r02FC = equal(body.constant(2097151u), r02E7);
               ir_expression *const r02FD = equal(body.constant(4294967295u), r02E8);
               ir_expression *const r02FE = logic_and(r02FC, r02FD);
               ir_expression *const r02FF = logic_and(r02FB, r02FE);
               ir_expression *const r0300 = logic_and(r02FF, r02F5);
               ir_expression *const r0301 = logic_or(r02FA, r0300);
               ir_if *f02F9 = new(mem_ctx) ir_if(operand(r0301).val);
               exec_list *const f02F9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02F9->then_instructions;

                  ir_variable *const r0302 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0302);
                  ir_expression *const r0303 = lshift(r01EF, body.constant(int(31)));
                  body.emit(assign(r0302, add(r0303, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0302, body.constant(0u), 0x01));

                  body.emit(assign(r02F4, r0302, 0x03));

                  body.emit(assign(r02F3, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02F9->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0305 = less(r01F8, body.constant(int(0)));
                  ir_if *f0304 = new(mem_ctx) ir_if(operand(r0305).val);
                  exec_list *const f0304_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0304->then_instructions;

                     ir_variable *const r0306 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0306, r01F9, 0x01));

                     ir_variable *const r0307 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0307, neg(r01F8), 0x01));

                     ir_variable *const r0308 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0308);
                     ir_variable *const r0309 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0309);
                     ir_variable *const r030A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r030A);
                     ir_variable *const r030B = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r030C = neg(r0307);
                     body.emit(assign(r030B, bit_and(r030C, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r030E = equal(r0307, body.constant(int(0)));
                     ir_if *f030D = new(mem_ctx) ir_if(operand(r030E).val);
                     exec_list *const f030D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f030D->then_instructions;

                        body.emit(assign(r0308, r01F9, 0x01));

                        body.emit(assign(r0309, r02E8, 0x01));

                        body.emit(assign(r030A, r02E7, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f030D->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0310 = less(r0307, body.constant(int(32)));
                        ir_if *f030F = new(mem_ctx) ir_if(operand(r0310).val);
                        exec_list *const f030F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f030F->then_instructions;

                           body.emit(assign(r0308, lshift(r02E8, r030B), 0x01));

                           ir_expression *const r0311 = lshift(r02E7, r030B);
                           ir_expression *const r0312 = rshift(r02E8, r0307);
                           body.emit(assign(r0309, bit_or(r0311, r0312), 0x01));

                           body.emit(assign(r030A, rshift(r02E7, r0307), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f030F->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0314 = equal(r0307, body.constant(int(32)));
                           ir_if *f0313 = new(mem_ctx) ir_if(operand(r0314).val);
                           exec_list *const f0313_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0313->then_instructions;

                              body.emit(assign(r0308, r02E8, 0x01));

                              body.emit(assign(r0309, r02E7, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0313->else_instructions;

                              body.emit(assign(r0306, bit_or(r01F9, r02E8), 0x01));

                              ir_expression *const r0315 = less(r0307, body.constant(int(64)));
                              ir_expression *const r0316 = lshift(r02E7, r030B);
                              ir_expression *const r0317 = equal(r0307, body.constant(int(64)));
                              ir_expression *const r0318 = nequal(r02E7, body.constant(0u));
                              ir_expression *const r0319 = expr(ir_unop_b2i, r0318);
                              ir_expression *const r031A = expr(ir_unop_i2u, r0319);
                              ir_expression *const r031B = expr(ir_triop_csel, r0317, r02E7, r031A);
                              body.emit(assign(r0308, expr(ir_triop_csel, r0315, r0316, r031B), 0x01));

                              ir_expression *const r031C = less(r0307, body.constant(int(64)));
                              ir_expression *const r031D = bit_and(r0307, body.constant(int(31)));
                              ir_expression *const r031E = rshift(r02E7, r031D);
                              body.emit(assign(r0309, expr(ir_triop_csel, r031C, r031E, body.constant(0u)), 0x01));


                           body.instructions = f0313_parent_instructions;
                           body.emit(f0313);

                           /* END IF */

                           body.emit(assign(r030A, body.constant(0u), 0x01));


                        body.instructions = f030F_parent_instructions;
                        body.emit(f030F);

                        /* END IF */

                        ir_expression *const r031F = nequal(r0306, body.constant(0u));
                        ir_expression *const r0320 = expr(ir_unop_b2i, r031F);
                        ir_expression *const r0321 = expr(ir_unop_i2u, r0320);
                        body.emit(assign(r0308, bit_or(r0308, r0321), 0x01));


                     body.instructions = f030D_parent_instructions;
                     body.emit(f030D);

                     /* END IF */

                     body.emit(assign(r02F0, r030A, 0x01));

                     body.emit(assign(r02F1, r0309, 0x01));

                     body.emit(assign(r02F2, r0308, 0x01));

                     body.emit(assign(r02EF, body.constant(int(0)), 0x01));

                     body.emit(assign(r02F5, less(r0308, body.constant(0u)), 0x01));


                  body.instructions = f0304_parent_instructions;
                  body.emit(f0304);

                  /* END IF */


               body.instructions = f02F9_parent_instructions;
               body.emit(f02F9);

               /* END IF */


            body.instructions = f02F7_parent_instructions;
            body.emit(f02F7);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0322 = new(mem_ctx) ir_if(operand(r02F3).val);
            exec_list *const f0322_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0322->then_instructions;

               /* IF CONDITION */
               ir_if *f0323 = new(mem_ctx) ir_if(operand(r02F5).val);
               exec_list *const f0323_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0323->then_instructions;

                  ir_variable *const r0324 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0324, add(r02F1, body.constant(1u)), 0x01));

                  ir_expression *const r0325 = less(r0324, r02F1);
                  ir_expression *const r0326 = expr(ir_unop_b2i, r0325);
                  ir_expression *const r0327 = expr(ir_unop_i2u, r0326);
                  body.emit(assign(r02F0, add(r02F0, r0327), 0x01));

                  ir_expression *const r0328 = equal(r02F2, body.constant(0u));
                  ir_expression *const r0329 = expr(ir_unop_b2i, r0328);
                  ir_expression *const r032A = expr(ir_unop_i2u, r0329);
                  ir_expression *const r032B = add(r02F2, r032A);
                  ir_expression *const r032C = bit_and(r032B, body.constant(1u));
                  ir_expression *const r032D = expr(ir_unop_bit_not, r032C);
                  body.emit(assign(r02F1, bit_and(r0324, r032D), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0323->else_instructions;

                  ir_expression *const r032E = bit_or(r02F0, r02F1);
                  ir_expression *const r032F = equal(r032E, body.constant(0u));
                  body.emit(assign(r02EF, expr(ir_triop_csel, r032F, body.constant(int(0)), r02EF), 0x01));


               body.instructions = f0323_parent_instructions;
               body.emit(f0323);

               /* END IF */

               ir_variable *const r0330 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0330);
               ir_expression *const r0331 = lshift(r01EF, body.constant(int(31)));
               ir_expression *const r0332 = expr(ir_unop_i2u, r02EF);
               ir_expression *const r0333 = lshift(r0332, body.constant(int(20)));
               ir_expression *const r0334 = add(r0331, r0333);
               body.emit(assign(r0330, add(r0334, r02F0), 0x02));

               body.emit(assign(r0330, r02F1, 0x01));

               body.emit(assign(r02F4, r0330, 0x03));

               body.emit(assign(r02F3, body.constant(false), 0x01));


            body.instructions = f0322_parent_instructions;
            body.emit(f0322);

            /* END IF */

            body.emit(assign(r01ED, r02F4, 0x03));

            body.emit(assign(r01EC, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02ED->else_instructions;

            body.emit(assign(r01F8, add(r01F8, body.constant(int(1))), 0x01));

            ir_variable *const r0335 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0335);
            ir_variable *const r0336 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0336);
            ir_variable *const r0337 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0337);
            body.emit(assign(r0335, lshift(r02E8, body.constant(int(31))), 0x01));

            ir_expression *const r0338 = lshift(r02E7, body.constant(int(31)));
            ir_expression *const r0339 = rshift(r02E8, body.constant(int(1)));
            body.emit(assign(r0336, bit_or(r0338, r0339), 0x01));

            body.emit(assign(r0337, rshift(r02E7, body.constant(int(1))), 0x01));

            ir_expression *const r033A = nequal(r01F9, body.constant(0u));
            ir_expression *const r033B = expr(ir_unop_b2i, r033A);
            ir_expression *const r033C = expr(ir_unop_i2u, r033B);
            body.emit(assign(r0335, bit_or(r0335, r033C), 0x01));

            body.emit(assign(r01FA, r0337, 0x01));

            body.emit(assign(r01F9, r0335, 0x01));

            ir_variable *const r033D = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r033D, r01F8, 0x01));

            ir_variable *const r033E = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r033E, r0337, 0x01));

            ir_variable *const r033F = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r033F, r0336, 0x01));

            ir_variable *const r0340 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0340, r0335, 0x01));

            ir_variable *const r0341 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0341, body.constant(true), 0x01));

            ir_variable *const r0342 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0343 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0343);
            ir_expression *const r0344 = expr(ir_unop_u2i, r0335);
            body.emit(assign(r0343, less(r0344, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0346 = gequal(r01F8, body.constant(int(2045)));
            ir_if *f0345 = new(mem_ctx) ir_if(operand(r0346).val);
            exec_list *const f0345_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0345->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0348 = less(body.constant(int(2045)), r01F8);
               ir_expression *const r0349 = equal(r01F8, body.constant(int(2045)));
               ir_expression *const r034A = equal(body.constant(2097151u), r0337);
               ir_expression *const r034B = equal(body.constant(4294967295u), r0336);
               ir_expression *const r034C = logic_and(r034A, r034B);
               ir_expression *const r034D = logic_and(r0349, r034C);
               ir_expression *const r034E = logic_and(r034D, r0343);
               ir_expression *const r034F = logic_or(r0348, r034E);
               ir_if *f0347 = new(mem_ctx) ir_if(operand(r034F).val);
               exec_list *const f0347_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0347->then_instructions;

                  ir_variable *const r0350 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0350);
                  ir_expression *const r0351 = lshift(r01EF, body.constant(int(31)));
                  body.emit(assign(r0350, add(r0351, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0350, body.constant(0u), 0x01));

                  body.emit(assign(r0342, r0350, 0x03));

                  body.emit(assign(r0341, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0347->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0353 = less(r01F8, body.constant(int(0)));
                  ir_if *f0352 = new(mem_ctx) ir_if(operand(r0353).val);
                  exec_list *const f0352_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0352->then_instructions;

                     ir_variable *const r0354 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0354, r0335, 0x01));

                     ir_variable *const r0355 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0355, neg(r01F8), 0x01));

                     ir_variable *const r0356 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0356);
                     ir_variable *const r0357 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0357);
                     ir_variable *const r0358 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0358);
                     ir_variable *const r0359 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r035A = neg(r0355);
                     body.emit(assign(r0359, bit_and(r035A, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r035C = equal(r0355, body.constant(int(0)));
                     ir_if *f035B = new(mem_ctx) ir_if(operand(r035C).val);
                     exec_list *const f035B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f035B->then_instructions;

                        body.emit(assign(r0356, r0335, 0x01));

                        body.emit(assign(r0357, r0336, 0x01));

                        body.emit(assign(r0358, r0337, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f035B->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r035E = less(r0355, body.constant(int(32)));
                        ir_if *f035D = new(mem_ctx) ir_if(operand(r035E).val);
                        exec_list *const f035D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f035D->then_instructions;

                           body.emit(assign(r0356, lshift(r0336, r0359), 0x01));

                           ir_expression *const r035F = lshift(r0337, r0359);
                           ir_expression *const r0360 = rshift(r0336, r0355);
                           body.emit(assign(r0357, bit_or(r035F, r0360), 0x01));

                           body.emit(assign(r0358, rshift(r0337, r0355), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f035D->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0362 = equal(r0355, body.constant(int(32)));
                           ir_if *f0361 = new(mem_ctx) ir_if(operand(r0362).val);
                           exec_list *const f0361_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0361->then_instructions;

                              body.emit(assign(r0356, r0336, 0x01));

                              body.emit(assign(r0357, r0337, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0361->else_instructions;

                              body.emit(assign(r0354, bit_or(r0335, r0336), 0x01));

                              ir_expression *const r0363 = less(r0355, body.constant(int(64)));
                              ir_expression *const r0364 = lshift(r0337, r0359);
                              ir_expression *const r0365 = equal(r0355, body.constant(int(64)));
                              ir_expression *const r0366 = nequal(r0337, body.constant(0u));
                              ir_expression *const r0367 = expr(ir_unop_b2i, r0366);
                              ir_expression *const r0368 = expr(ir_unop_i2u, r0367);
                              ir_expression *const r0369 = expr(ir_triop_csel, r0365, r0337, r0368);
                              body.emit(assign(r0356, expr(ir_triop_csel, r0363, r0364, r0369), 0x01));

                              ir_expression *const r036A = less(r0355, body.constant(int(64)));
                              ir_expression *const r036B = bit_and(r0355, body.constant(int(31)));
                              ir_expression *const r036C = rshift(r0337, r036B);
                              body.emit(assign(r0357, expr(ir_triop_csel, r036A, r036C, body.constant(0u)), 0x01));


                           body.instructions = f0361_parent_instructions;
                           body.emit(f0361);

                           /* END IF */

                           body.emit(assign(r0358, body.constant(0u), 0x01));


                        body.instructions = f035D_parent_instructions;
                        body.emit(f035D);

                        /* END IF */

                        ir_expression *const r036D = nequal(r0354, body.constant(0u));
                        ir_expression *const r036E = expr(ir_unop_b2i, r036D);
                        ir_expression *const r036F = expr(ir_unop_i2u, r036E);
                        body.emit(assign(r0356, bit_or(r0356, r036F), 0x01));


                     body.instructions = f035B_parent_instructions;
                     body.emit(f035B);

                     /* END IF */

                     body.emit(assign(r033E, r0358, 0x01));

                     body.emit(assign(r033F, r0357, 0x01));

                     body.emit(assign(r0340, r0356, 0x01));

                     body.emit(assign(r033D, body.constant(int(0)), 0x01));

                     body.emit(assign(r0343, less(r0356, body.constant(0u)), 0x01));


                  body.instructions = f0352_parent_instructions;
                  body.emit(f0352);

                  /* END IF */


               body.instructions = f0347_parent_instructions;
               body.emit(f0347);

               /* END IF */


            body.instructions = f0345_parent_instructions;
            body.emit(f0345);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0370 = new(mem_ctx) ir_if(operand(r0341).val);
            exec_list *const f0370_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0370->then_instructions;

               /* IF CONDITION */
               ir_if *f0371 = new(mem_ctx) ir_if(operand(r0343).val);
               exec_list *const f0371_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0371->then_instructions;

                  ir_variable *const r0372 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0372, add(r033F, body.constant(1u)), 0x01));

                  ir_expression *const r0373 = less(r0372, r033F);
                  ir_expression *const r0374 = expr(ir_unop_b2i, r0373);
                  ir_expression *const r0375 = expr(ir_unop_i2u, r0374);
                  body.emit(assign(r033E, add(r033E, r0375), 0x01));

                  ir_expression *const r0376 = equal(r0340, body.constant(0u));
                  ir_expression *const r0377 = expr(ir_unop_b2i, r0376);
                  ir_expression *const r0378 = expr(ir_unop_i2u, r0377);
                  ir_expression *const r0379 = add(r0340, r0378);
                  ir_expression *const r037A = bit_and(r0379, body.constant(1u));
                  ir_expression *const r037B = expr(ir_unop_bit_not, r037A);
                  body.emit(assign(r033F, bit_and(r0372, r037B), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0371->else_instructions;

                  ir_expression *const r037C = bit_or(r033E, r033F);
                  ir_expression *const r037D = equal(r037C, body.constant(0u));
                  body.emit(assign(r033D, expr(ir_triop_csel, r037D, body.constant(int(0)), r033D), 0x01));


               body.instructions = f0371_parent_instructions;
               body.emit(f0371);

               /* END IF */

               ir_variable *const r037E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r037E);
               ir_expression *const r037F = lshift(r01EF, body.constant(int(31)));
               ir_expression *const r0380 = expr(ir_unop_i2u, r033D);
               ir_expression *const r0381 = lshift(r0380, body.constant(int(20)));
               ir_expression *const r0382 = add(r037F, r0381);
               body.emit(assign(r037E, add(r0382, r033E), 0x02));

               body.emit(assign(r037E, r033F, 0x01));

               body.emit(assign(r0342, r037E, 0x03));

               body.emit(assign(r0341, body.constant(false), 0x01));


            body.instructions = f0370_parent_instructions;
            body.emit(f0370);

            /* END IF */

            body.emit(assign(r01ED, r0342, 0x03));

            body.emit(assign(r01EC, body.constant(false), 0x01));


         body.instructions = f02ED_parent_instructions;
         body.emit(f02ED);

         /* END IF */


      body.instructions = f02E6_parent_instructions;
      body.emit(f02E6);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01F1->else_instructions;

      ir_variable *const r0383 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r0383);
      ir_variable *const r0384 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
      body.emit(r0384);
      ir_variable *const r0385 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
      body.emit(r0385);
      ir_variable *const r0386 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r0386);
      ir_variable *const r0387 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r0387);
      ir_variable *const r0388 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r0388);
      ir_variable *const r0389 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r0389);
      ir_variable *const r038A = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r038A);
      ir_variable *const r038B = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r038C = rshift(swizzle_y(r01EA), body.constant(int(20)));
      ir_expression *const r038D = bit_and(r038C, body.constant(2047u));
      body.emit(assign(r038B, expr(ir_unop_u2i, r038D), 0x01));

      body.emit(assign(r0385, r038B, 0x01));

      ir_variable *const r038E = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r038F = rshift(swizzle_y(r01EB), body.constant(int(20)));
      ir_expression *const r0390 = bit_and(r038F, body.constant(2047u));
      body.emit(assign(r038E, expr(ir_unop_u2i, r0390), 0x01));

      body.emit(assign(r0384, r038E, 0x01));

      body.emit(assign(r0383, sub(r038B, r038E), 0x01));

      ir_variable *const r0391 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r0392 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0392, lshift(swizzle_x(r01EA), body.constant(int(10))), 0x01));

      ir_expression *const r0393 = bit_and(swizzle_y(r01EA), body.constant(1048575u));
      ir_expression *const r0394 = lshift(r0393, body.constant(int(10)));
      ir_expression *const r0395 = rshift(swizzle_x(r01EA), body.constant(int(22)));
      body.emit(assign(r0391, bit_or(r0394, r0395), 0x01));

      body.emit(assign(r0388, r0391, 0x01));

      body.emit(assign(r0389, r0392, 0x01));

      ir_variable *const r0396 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r0397 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0397, lshift(swizzle_x(r01EB), body.constant(int(10))), 0x01));

      ir_expression *const r0398 = bit_and(swizzle_y(r01EB), body.constant(1048575u));
      ir_expression *const r0399 = lshift(r0398, body.constant(int(10)));
      ir_expression *const r039A = rshift(swizzle_x(r01EB), body.constant(int(22)));
      body.emit(assign(r0396, bit_or(r0399, r039A), 0x01));

      body.emit(assign(r0386, r0396, 0x01));

      body.emit(assign(r0387, r0397, 0x01));

      /* IF CONDITION */
      ir_expression *const r039C = less(body.constant(int(0)), r0383);
      ir_if *f039B = new(mem_ctx) ir_if(operand(r039C).val);
      exec_list *const f039B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f039B->then_instructions;

         /* IF CONDITION */
         ir_expression *const r039E = equal(r038B, body.constant(int(2047)));
         ir_if *f039D = new(mem_ctx) ir_if(operand(r039E).val);
         exec_list *const f039D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f039D->then_instructions;

            /* IF CONDITION */
            ir_expression *const r03A0 = bit_or(r0391, r0392);
            ir_expression *const r03A1 = nequal(r03A0, body.constant(0u));
            ir_if *f039F = new(mem_ctx) ir_if(operand(r03A1).val);
            exec_list *const f039F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f039F->then_instructions;

               ir_variable *const r03A2 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r03A2, swizzle_x(r01EA), 0x01));

               ir_variable *const r03A3 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r03A3, swizzle_x(r01EB), 0x01));

               body.emit(assign(r03A2, bit_or(swizzle_y(r01EA), body.constant(524288u)), 0x02));

               body.emit(assign(r03A3, bit_or(swizzle_y(r01EB), body.constant(524288u)), 0x02));

               ir_expression *const r03A4 = lshift(swizzle_y(r01EA), body.constant(int(1)));
               ir_expression *const r03A5 = gequal(r03A4, body.constant(4292870144u));
               ir_expression *const r03A6 = nequal(swizzle_x(r01EA), body.constant(0u));
               ir_expression *const r03A7 = bit_and(swizzle_y(r01EA), body.constant(1048575u));
               ir_expression *const r03A8 = nequal(r03A7, body.constant(0u));
               ir_expression *const r03A9 = logic_or(r03A6, r03A8);
               ir_expression *const r03AA = logic_and(r03A5, r03A9);
               ir_swizzle *const r03AB = swizzle(r03AA, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r03AC = lshift(swizzle_y(r01EB), body.constant(int(1)));
               ir_expression *const r03AD = gequal(r03AC, body.constant(4292870144u));
               ir_expression *const r03AE = nequal(swizzle_x(r01EB), body.constant(0u));
               ir_expression *const r03AF = bit_and(swizzle_y(r01EB), body.constant(1048575u));
               ir_expression *const r03B0 = nequal(r03AF, body.constant(0u));
               ir_expression *const r03B1 = logic_or(r03AE, r03B0);
               ir_expression *const r03B2 = logic_and(r03AD, r03B1);
               ir_swizzle *const r03B3 = swizzle(r03B2, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r03B4 = expr(ir_triop_csel, r03B3, r03A3, r03A2);
               body.emit(assign(r01ED, expr(ir_triop_csel, r03AB, r03B4, r03A3), 0x03));

               body.emit(assign(r01EC, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f039F->else_instructions;

               body.emit(assign(r01ED, r01EA, 0x03));

               body.emit(assign(r01EC, body.constant(false), 0x01));


            body.instructions = f039F_parent_instructions;
            body.emit(f039F);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f039D->else_instructions;

            /* IF CONDITION */
            ir_expression *const r03B6 = equal(r038E, body.constant(int(0)));
            ir_if *f03B5 = new(mem_ctx) ir_if(operand(r03B6).val);
            exec_list *const f03B5_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03B5->then_instructions;

               body.emit(assign(r0383, add(r0383, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03B5->else_instructions;

               body.emit(assign(r0386, bit_or(r0396, body.constant(1073741824u)), 0x01));


            body.instructions = f03B5_parent_instructions;
            body.emit(f03B5);

            /* END IF */

            ir_variable *const r03B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r03B7);
            ir_variable *const r03B8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r03B9 = neg(r0383);
            body.emit(assign(r03B8, bit_and(r03B9, body.constant(int(31))), 0x01));

            ir_variable *const r03BA = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03BB = less(r0383, body.constant(int(32)));
            ir_expression *const r03BC = rshift(r0386, r0383);
            ir_expression *const r03BD = equal(r0383, body.constant(int(0)));
            ir_expression *const r03BE = expr(ir_triop_csel, r03BD, r0386, body.constant(0u));
            body.emit(assign(r03BA, expr(ir_triop_csel, r03BB, r03BC, r03BE), 0x01));

            /* IF CONDITION */
            ir_expression *const r03C0 = equal(r0383, body.constant(int(0)));
            ir_if *f03BF = new(mem_ctx) ir_if(operand(r03C0).val);
            exec_list *const f03BF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03BF->then_instructions;

               body.emit(assign(r03B7, r0397, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03BF->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03C2 = less(r0383, body.constant(int(32)));
               ir_if *f03C1 = new(mem_ctx) ir_if(operand(r03C2).val);
               exec_list *const f03C1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03C1->then_instructions;

                  ir_expression *const r03C3 = lshift(r0386, r03B8);
                  ir_expression *const r03C4 = rshift(r0397, r0383);
                  ir_expression *const r03C5 = bit_or(r03C3, r03C4);
                  ir_expression *const r03C6 = lshift(r0397, r03B8);
                  ir_expression *const r03C7 = nequal(r03C6, body.constant(0u));
                  ir_expression *const r03C8 = expr(ir_unop_b2i, r03C7);
                  ir_expression *const r03C9 = expr(ir_unop_i2u, r03C8);
                  body.emit(assign(r03B7, bit_or(r03C5, r03C9), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03C1->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03CB = equal(r0383, body.constant(int(32)));
                  ir_if *f03CA = new(mem_ctx) ir_if(operand(r03CB).val);
                  exec_list *const f03CA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03CA->then_instructions;

                     ir_expression *const r03CC = nequal(r0397, body.constant(0u));
                     ir_expression *const r03CD = expr(ir_unop_b2i, r03CC);
                     ir_expression *const r03CE = expr(ir_unop_i2u, r03CD);
                     body.emit(assign(r03B7, bit_or(r0386, r03CE), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03CA->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03D0 = less(r0383, body.constant(int(64)));
                     ir_if *f03CF = new(mem_ctx) ir_if(operand(r03D0).val);
                     exec_list *const f03CF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03CF->then_instructions;

                        ir_expression *const r03D1 = bit_and(r0383, body.constant(int(31)));
                        ir_expression *const r03D2 = rshift(r0386, r03D1);
                        ir_expression *const r03D3 = lshift(r0386, r03B8);
                        ir_expression *const r03D4 = bit_or(r03D3, r0397);
                        ir_expression *const r03D5 = nequal(r03D4, body.constant(0u));
                        ir_expression *const r03D6 = expr(ir_unop_b2i, r03D5);
                        ir_expression *const r03D7 = expr(ir_unop_i2u, r03D6);
                        body.emit(assign(r03B7, bit_or(r03D2, r03D7), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03CF->else_instructions;

                        ir_expression *const r03D8 = bit_or(r0386, r0397);
                        ir_expression *const r03D9 = nequal(r03D8, body.constant(0u));
                        ir_expression *const r03DA = expr(ir_unop_b2i, r03D9);
                        body.emit(assign(r03B7, expr(ir_unop_i2u, r03DA), 0x01));


                     body.instructions = f03CF_parent_instructions;
                     body.emit(f03CF);

                     /* END IF */


                  body.instructions = f03CA_parent_instructions;
                  body.emit(f03CA);

                  /* END IF */


               body.instructions = f03C1_parent_instructions;
               body.emit(f03C1);

               /* END IF */


            body.instructions = f03BF_parent_instructions;
            body.emit(f03BF);

            /* END IF */

            body.emit(assign(r0386, r03BA, 0x01));

            body.emit(assign(r0387, r03B7, 0x01));

            body.emit(assign(r0388, bit_or(r0391, body.constant(1073741824u)), 0x01));

            ir_variable *const r03DB = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_expression *const r03DC = sub(r0388, r03BA);
            ir_expression *const r03DD = less(r0392, r03B7);
            ir_expression *const r03DE = expr(ir_unop_b2i, r03DD);
            ir_expression *const r03DF = expr(ir_unop_i2u, r03DE);
            body.emit(assign(r03DB, sub(r03DC, r03DF), 0x01));

            body.emit(assign(r038A, add(r038B, body.constant(int(-1))), 0x01));

            ir_variable *const r03E0 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03E0, add(r038A, body.constant(int(-10))), 0x01));

            ir_variable *const r03E1 = body.make_temp(glsl_type::uint_type, "zFrac0");
            ir_variable *const r03E2 = body.make_temp(glsl_type::uint_type, "zFrac1");
            ir_variable *const r03E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03E3);
            ir_variable *const r03E4 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03E4);
            ir_expression *const r03E5 = equal(r03DB, body.constant(0u));
            ir_expression *const r03E6 = add(r03E0, body.constant(int(-32)));
            body.emit(assign(r03E0, expr(ir_triop_csel, r03E5, r03E6, r03E0), 0x01));

            ir_variable *const r03E7 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03E8 = equal(r03DB, body.constant(0u));
            ir_expression *const r03E9 = sub(r0392, r03B7);
            body.emit(assign(r03E7, expr(ir_triop_csel, r03E8, body.constant(0u), r03E9), 0x01));

            body.emit(assign(r03E2, r03E7, 0x01));

            ir_variable *const r03EA = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03EB = equal(r03DB, body.constant(0u));
            body.emit(assign(r03EA, expr(ir_triop_csel, r03EB, r03E7, r03DB), 0x01));

            body.emit(assign(r03E1, r03EA, 0x01));

            ir_variable *const r03EC = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r03EC, r03EA, 0x01));

            ir_variable *const r03ED = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r03EE = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03EE);
            /* IF CONDITION */
            ir_expression *const r03F0 = equal(r03EA, body.constant(0u));
            ir_if *f03EF = new(mem_ctx) ir_if(operand(r03F0).val);
            exec_list *const f03EF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03EF->then_instructions;

               body.emit(assign(r03ED, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03EF->else_instructions;

               body.emit(assign(r03EE, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r03F2 = bit_and(r03EA, body.constant(4294901760u));
               ir_expression *const r03F3 = equal(r03F2, body.constant(0u));
               ir_if *f03F1 = new(mem_ctx) ir_if(operand(r03F3).val);
               exec_list *const f03F1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F1->then_instructions;

                  body.emit(assign(r03EE, body.constant(int(16)), 0x01));

                  body.emit(assign(r03EC, lshift(r03EA, body.constant(int(16))), 0x01));


               body.instructions = f03F1_parent_instructions;
               body.emit(f03F1);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03F5 = bit_and(r03EC, body.constant(4278190080u));
               ir_expression *const r03F6 = equal(r03F5, body.constant(0u));
               ir_if *f03F4 = new(mem_ctx) ir_if(operand(r03F6).val);
               exec_list *const f03F4_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F4->then_instructions;

                  body.emit(assign(r03EE, add(r03EE, body.constant(int(8))), 0x01));

                  body.emit(assign(r03EC, lshift(r03EC, body.constant(int(8))), 0x01));


               body.instructions = f03F4_parent_instructions;
               body.emit(f03F4);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03F8 = bit_and(r03EC, body.constant(4026531840u));
               ir_expression *const r03F9 = equal(r03F8, body.constant(0u));
               ir_if *f03F7 = new(mem_ctx) ir_if(operand(r03F9).val);
               exec_list *const f03F7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F7->then_instructions;

                  body.emit(assign(r03EE, add(r03EE, body.constant(int(4))), 0x01));

                  body.emit(assign(r03EC, lshift(r03EC, body.constant(int(4))), 0x01));


               body.instructions = f03F7_parent_instructions;
               body.emit(f03F7);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03FB = bit_and(r03EC, body.constant(3221225472u));
               ir_expression *const r03FC = equal(r03FB, body.constant(0u));
               ir_if *f03FA = new(mem_ctx) ir_if(operand(r03FC).val);
               exec_list *const f03FA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03FA->then_instructions;

                  body.emit(assign(r03EE, add(r03EE, body.constant(int(2))), 0x01));

                  body.emit(assign(r03EC, lshift(r03EC, body.constant(int(2))), 0x01));


               body.instructions = f03FA_parent_instructions;
               body.emit(f03FA);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03FE = bit_and(r03EC, body.constant(2147483648u));
               ir_expression *const r03FF = equal(r03FE, body.constant(0u));
               ir_if *f03FD = new(mem_ctx) ir_if(operand(r03FF).val);
               exec_list *const f03FD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03FD->then_instructions;

                  body.emit(assign(r03EE, add(r03EE, body.constant(int(1))), 0x01));


               body.instructions = f03FD_parent_instructions;
               body.emit(f03FD);

               /* END IF */

               body.emit(assign(r03ED, r03EE, 0x01));


            body.instructions = f03EF_parent_instructions;
            body.emit(f03EF);

            /* END IF */

            body.emit(assign(r03E4, add(r03ED, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0401 = gequal(r03E4, body.constant(int(0)));
            ir_if *f0400 = new(mem_ctx) ir_if(operand(r0401).val);
            exec_list *const f0400_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0400->then_instructions;

               body.emit(assign(r03E3, body.constant(0u), 0x01));

               ir_expression *const r0402 = equal(r03E4, body.constant(int(0)));
               ir_expression *const r0403 = lshift(r03EA, r03E4);
               ir_expression *const r0404 = neg(r03E4);
               ir_expression *const r0405 = bit_and(r0404, body.constant(int(31)));
               ir_expression *const r0406 = rshift(r03E7, r0405);
               ir_expression *const r0407 = bit_or(r0403, r0406);
               body.emit(assign(r03E1, expr(ir_triop_csel, r0402, r03EA, r0407), 0x01));

               body.emit(assign(r03E2, lshift(r03E7, r03E4), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0400->else_instructions;

               ir_variable *const r0408 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0408, body.constant(0u), 0x01));

               ir_variable *const r0409 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0409, neg(r03E4), 0x01));

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

                  body.emit(assign(r040A, r0408, 0x01));

                  body.emit(assign(r040B, r03E2, 0x01));

                  body.emit(assign(r040C, r03E1, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f040F->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0412 = less(r0409, body.constant(int(32)));
                  ir_if *f0411 = new(mem_ctx) ir_if(operand(r0412).val);
                  exec_list *const f0411_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0411->then_instructions;

                     body.emit(assign(r040A, lshift(r03E2, r040D), 0x01));

                     ir_expression *const r0413 = lshift(r03E1, r040D);
                     ir_expression *const r0414 = rshift(r03E2, r0409);
                     body.emit(assign(r040B, bit_or(r0413, r0414), 0x01));

                     body.emit(assign(r040C, rshift(r03E1, r0409), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0411->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0416 = equal(r0409, body.constant(int(32)));
                     ir_if *f0415 = new(mem_ctx) ir_if(operand(r0416).val);
                     exec_list *const f0415_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0415->then_instructions;

                        body.emit(assign(r040A, r03E2, 0x01));

                        body.emit(assign(r040B, r03E1, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0415->else_instructions;

                        body.emit(assign(r0408, bit_or(body.constant(0u), r03E2), 0x01));

                        ir_expression *const r0417 = less(r0409, body.constant(int(64)));
                        ir_expression *const r0418 = lshift(r03E1, r040D);
                        ir_expression *const r0419 = equal(r0409, body.constant(int(64)));
                        ir_expression *const r041A = nequal(r03E1, body.constant(0u));
                        ir_expression *const r041B = expr(ir_unop_b2i, r041A);
                        ir_expression *const r041C = expr(ir_unop_i2u, r041B);
                        ir_expression *const r041D = expr(ir_triop_csel, r0419, r03E1, r041C);
                        body.emit(assign(r040A, expr(ir_triop_csel, r0417, r0418, r041D), 0x01));

                        ir_expression *const r041E = less(r0409, body.constant(int(64)));
                        ir_expression *const r041F = bit_and(r0409, body.constant(int(31)));
                        ir_expression *const r0420 = rshift(r03E1, r041F);
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

               body.emit(assign(r03E1, r040C, 0x01));

               body.emit(assign(r03E2, r040B, 0x01));

               body.emit(assign(r03E3, r040A, 0x01));


            body.instructions = f0400_parent_instructions;
            body.emit(f0400);

            /* END IF */

            body.emit(assign(r03E0, sub(r03E0, r03E4), 0x01));

            ir_variable *const r0424 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0424, r03E0, 0x01));

            ir_variable *const r0425 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0425, r03E1, 0x01));

            ir_variable *const r0426 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0426, r03E2, 0x01));

            ir_variable *const r0427 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0427, r03E3, 0x01));

            ir_variable *const r0428 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0428, body.constant(true), 0x01));

            ir_variable *const r0429 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r042A = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r042A);
            ir_expression *const r042B = expr(ir_unop_u2i, r03E3);
            body.emit(assign(r042A, less(r042B, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r042D = gequal(r03E0, body.constant(int(2045)));
            ir_if *f042C = new(mem_ctx) ir_if(operand(r042D).val);
            exec_list *const f042C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f042C->then_instructions;

               /* IF CONDITION */
               ir_expression *const r042F = less(body.constant(int(2045)), r03E0);
               ir_expression *const r0430 = equal(r03E0, body.constant(int(2045)));
               ir_expression *const r0431 = equal(body.constant(2097151u), r03E1);
               ir_expression *const r0432 = equal(body.constant(4294967295u), r03E2);
               ir_expression *const r0433 = logic_and(r0431, r0432);
               ir_expression *const r0434 = logic_and(r0430, r0433);
               ir_expression *const r0435 = logic_and(r0434, r042A);
               ir_expression *const r0436 = logic_or(r042F, r0435);
               ir_if *f042E = new(mem_ctx) ir_if(operand(r0436).val);
               exec_list *const f042E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f042E->then_instructions;

                  ir_variable *const r0437 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0437);
                  ir_expression *const r0438 = lshift(r01EF, body.constant(int(31)));
                  body.emit(assign(r0437, add(r0438, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0437, body.constant(0u), 0x01));

                  body.emit(assign(r0429, r0437, 0x03));

                  body.emit(assign(r0428, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f042E->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r043A = less(r03E0, body.constant(int(0)));
                  ir_if *f0439 = new(mem_ctx) ir_if(operand(r043A).val);
                  exec_list *const f0439_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0439->then_instructions;

                     ir_variable *const r043B = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r043B, r03E3, 0x01));

                     ir_variable *const r043C = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r043C, neg(r03E0), 0x01));

                     ir_variable *const r043D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r043D);
                     ir_variable *const r043E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r043E);
                     ir_variable *const r043F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r043F);
                     ir_variable *const r0440 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0441 = neg(r043C);
                     body.emit(assign(r0440, bit_and(r0441, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0443 = equal(r043C, body.constant(int(0)));
                     ir_if *f0442 = new(mem_ctx) ir_if(operand(r0443).val);
                     exec_list *const f0442_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0442->then_instructions;

                        body.emit(assign(r043D, r03E3, 0x01));

                        body.emit(assign(r043E, r03E2, 0x01));

                        body.emit(assign(r043F, r03E1, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0442->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0445 = less(r043C, body.constant(int(32)));
                        ir_if *f0444 = new(mem_ctx) ir_if(operand(r0445).val);
                        exec_list *const f0444_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0444->then_instructions;

                           body.emit(assign(r043D, lshift(r03E2, r0440), 0x01));

                           ir_expression *const r0446 = lshift(r03E1, r0440);
                           ir_expression *const r0447 = rshift(r03E2, r043C);
                           body.emit(assign(r043E, bit_or(r0446, r0447), 0x01));

                           body.emit(assign(r043F, rshift(r03E1, r043C), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0444->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0449 = equal(r043C, body.constant(int(32)));
                           ir_if *f0448 = new(mem_ctx) ir_if(operand(r0449).val);
                           exec_list *const f0448_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0448->then_instructions;

                              body.emit(assign(r043D, r03E2, 0x01));

                              body.emit(assign(r043E, r03E1, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0448->else_instructions;

                              body.emit(assign(r043B, bit_or(r03E3, r03E2), 0x01));

                              ir_expression *const r044A = less(r043C, body.constant(int(64)));
                              ir_expression *const r044B = lshift(r03E1, r0440);
                              ir_expression *const r044C = equal(r043C, body.constant(int(64)));
                              ir_expression *const r044D = nequal(r03E1, body.constant(0u));
                              ir_expression *const r044E = expr(ir_unop_b2i, r044D);
                              ir_expression *const r044F = expr(ir_unop_i2u, r044E);
                              ir_expression *const r0450 = expr(ir_triop_csel, r044C, r03E1, r044F);
                              body.emit(assign(r043D, expr(ir_triop_csel, r044A, r044B, r0450), 0x01));

                              ir_expression *const r0451 = less(r043C, body.constant(int(64)));
                              ir_expression *const r0452 = bit_and(r043C, body.constant(int(31)));
                              ir_expression *const r0453 = rshift(r03E1, r0452);
                              body.emit(assign(r043E, expr(ir_triop_csel, r0451, r0453, body.constant(0u)), 0x01));


                           body.instructions = f0448_parent_instructions;
                           body.emit(f0448);

                           /* END IF */

                           body.emit(assign(r043F, body.constant(0u), 0x01));


                        body.instructions = f0444_parent_instructions;
                        body.emit(f0444);

                        /* END IF */

                        ir_expression *const r0454 = nequal(r043B, body.constant(0u));
                        ir_expression *const r0455 = expr(ir_unop_b2i, r0454);
                        ir_expression *const r0456 = expr(ir_unop_i2u, r0455);
                        body.emit(assign(r043D, bit_or(r043D, r0456), 0x01));


                     body.instructions = f0442_parent_instructions;
                     body.emit(f0442);

                     /* END IF */

                     body.emit(assign(r0425, r043F, 0x01));

                     body.emit(assign(r0426, r043E, 0x01));

                     body.emit(assign(r0427, r043D, 0x01));

                     body.emit(assign(r0424, body.constant(int(0)), 0x01));

                     body.emit(assign(r042A, less(r043D, body.constant(0u)), 0x01));


                  body.instructions = f0439_parent_instructions;
                  body.emit(f0439);

                  /* END IF */


               body.instructions = f042E_parent_instructions;
               body.emit(f042E);

               /* END IF */


            body.instructions = f042C_parent_instructions;
            body.emit(f042C);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0457 = new(mem_ctx) ir_if(operand(r0428).val);
            exec_list *const f0457_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0457->then_instructions;

               /* IF CONDITION */
               ir_if *f0458 = new(mem_ctx) ir_if(operand(r042A).val);
               exec_list *const f0458_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0458->then_instructions;

                  ir_variable *const r0459 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0459, add(r0426, body.constant(1u)), 0x01));

                  ir_expression *const r045A = less(r0459, r0426);
                  ir_expression *const r045B = expr(ir_unop_b2i, r045A);
                  ir_expression *const r045C = expr(ir_unop_i2u, r045B);
                  body.emit(assign(r0425, add(r0425, r045C), 0x01));

                  ir_expression *const r045D = equal(r0427, body.constant(0u));
                  ir_expression *const r045E = expr(ir_unop_b2i, r045D);
                  ir_expression *const r045F = expr(ir_unop_i2u, r045E);
                  ir_expression *const r0460 = add(r0427, r045F);
                  ir_expression *const r0461 = bit_and(r0460, body.constant(1u));
                  ir_expression *const r0462 = expr(ir_unop_bit_not, r0461);
                  body.emit(assign(r0426, bit_and(r0459, r0462), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0458->else_instructions;

                  ir_expression *const r0463 = bit_or(r0425, r0426);
                  ir_expression *const r0464 = equal(r0463, body.constant(0u));
                  body.emit(assign(r0424, expr(ir_triop_csel, r0464, body.constant(int(0)), r0424), 0x01));


               body.instructions = f0458_parent_instructions;
               body.emit(f0458);

               /* END IF */

               ir_variable *const r0465 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0465);
               ir_expression *const r0466 = lshift(r01EF, body.constant(int(31)));
               ir_expression *const r0467 = expr(ir_unop_i2u, r0424);
               ir_expression *const r0468 = lshift(r0467, body.constant(int(20)));
               ir_expression *const r0469 = add(r0466, r0468);
               body.emit(assign(r0465, add(r0469, r0425), 0x02));

               body.emit(assign(r0465, r0426, 0x01));

               body.emit(assign(r0429, r0465, 0x03));

               body.emit(assign(r0428, body.constant(false), 0x01));


            body.instructions = f0457_parent_instructions;
            body.emit(f0457);

            /* END IF */

            body.emit(assign(r01ED, r0429, 0x03));

            body.emit(assign(r01EC, body.constant(false), 0x01));


         body.instructions = f039D_parent_instructions;
         body.emit(f039D);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f039B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r046B = less(r0383, body.constant(int(0)));
         ir_if *f046A = new(mem_ctx) ir_if(operand(r046B).val);
         exec_list *const f046A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f046A->then_instructions;

            /* IF CONDITION */
            ir_expression *const r046D = equal(r038E, body.constant(int(2047)));
            ir_if *f046C = new(mem_ctx) ir_if(operand(r046D).val);
            exec_list *const f046C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f046C->then_instructions;

               /* IF CONDITION */
               ir_expression *const r046F = bit_or(r0386, r0387);
               ir_expression *const r0470 = nequal(r046F, body.constant(0u));
               ir_if *f046E = new(mem_ctx) ir_if(operand(r0470).val);
               exec_list *const f046E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f046E->then_instructions;

                  ir_variable *const r0471 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0471, swizzle_x(r01EA), 0x01));

                  ir_variable *const r0472 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0472, swizzle_x(r01EB), 0x01));

                  body.emit(assign(r0471, bit_or(swizzle_y(r01EA), body.constant(524288u)), 0x02));

                  body.emit(assign(r0472, bit_or(swizzle_y(r01EB), body.constant(524288u)), 0x02));

                  ir_expression *const r0473 = lshift(swizzle_y(r01EA), body.constant(int(1)));
                  ir_expression *const r0474 = gequal(r0473, body.constant(4292870144u));
                  ir_expression *const r0475 = nequal(swizzle_x(r01EA), body.constant(0u));
                  ir_expression *const r0476 = bit_and(swizzle_y(r01EA), body.constant(1048575u));
                  ir_expression *const r0477 = nequal(r0476, body.constant(0u));
                  ir_expression *const r0478 = logic_or(r0475, r0477);
                  ir_expression *const r0479 = logic_and(r0474, r0478);
                  ir_swizzle *const r047A = swizzle(r0479, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r047B = lshift(swizzle_y(r01EB), body.constant(int(1)));
                  ir_expression *const r047C = gequal(r047B, body.constant(4292870144u));
                  ir_expression *const r047D = nequal(swizzle_x(r01EB), body.constant(0u));
                  ir_expression *const r047E = bit_and(swizzle_y(r01EB), body.constant(1048575u));
                  ir_expression *const r047F = nequal(r047E, body.constant(0u));
                  ir_expression *const r0480 = logic_or(r047D, r047F);
                  ir_expression *const r0481 = logic_and(r047C, r0480);
                  ir_swizzle *const r0482 = swizzle(r0481, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0483 = expr(ir_triop_csel, r0482, r0472, r0471);
                  body.emit(assign(r01ED, expr(ir_triop_csel, r047A, r0483, r0472), 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f046E->else_instructions;

                  ir_variable *const r0484 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0484);
                  ir_expression *const r0485 = bit_xor(r01EF, body.constant(1u));
                  ir_expression *const r0486 = lshift(r0485, body.constant(int(31)));
                  body.emit(assign(r0484, add(r0486, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0484, body.constant(0u), 0x01));

                  body.emit(assign(r01ED, r0484, 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


               body.instructions = f046E_parent_instructions;
               body.emit(f046E);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f046C->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0488 = equal(r038B, body.constant(int(0)));
               ir_if *f0487 = new(mem_ctx) ir_if(operand(r0488).val);
               exec_list *const f0487_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0487->then_instructions;

                  body.emit(assign(r0383, add(r0383, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0487->else_instructions;

                  body.emit(assign(r0388, bit_or(r0388, body.constant(1073741824u)), 0x01));


               body.instructions = f0487_parent_instructions;
               body.emit(f0487);

               /* END IF */

               ir_variable *const r0489 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0489, neg(r0383), 0x01));

               ir_variable *const r048A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r048A);
               ir_variable *const r048B = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r048C = neg(r0489);
               body.emit(assign(r048B, bit_and(r048C, body.constant(int(31))), 0x01));

               ir_variable *const r048D = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r048E = less(r0489, body.constant(int(32)));
               ir_expression *const r048F = rshift(r0388, r0489);
               ir_expression *const r0490 = equal(r0489, body.constant(int(0)));
               ir_expression *const r0491 = expr(ir_triop_csel, r0490, r0388, body.constant(0u));
               body.emit(assign(r048D, expr(ir_triop_csel, r048E, r048F, r0491), 0x01));

               /* IF CONDITION */
               ir_expression *const r0493 = equal(r0489, body.constant(int(0)));
               ir_if *f0492 = new(mem_ctx) ir_if(operand(r0493).val);
               exec_list *const f0492_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0492->then_instructions;

                  body.emit(assign(r048A, r0392, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0492->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0495 = less(r0489, body.constant(int(32)));
                  ir_if *f0494 = new(mem_ctx) ir_if(operand(r0495).val);
                  exec_list *const f0494_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0494->then_instructions;

                     ir_expression *const r0496 = lshift(r0388, r048B);
                     ir_expression *const r0497 = rshift(r0392, r0489);
                     ir_expression *const r0498 = bit_or(r0496, r0497);
                     ir_expression *const r0499 = lshift(r0392, r048B);
                     ir_expression *const r049A = nequal(r0499, body.constant(0u));
                     ir_expression *const r049B = expr(ir_unop_b2i, r049A);
                     ir_expression *const r049C = expr(ir_unop_i2u, r049B);
                     body.emit(assign(r048A, bit_or(r0498, r049C), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0494->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r049E = equal(r0489, body.constant(int(32)));
                     ir_if *f049D = new(mem_ctx) ir_if(operand(r049E).val);
                     exec_list *const f049D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f049D->then_instructions;

                        ir_expression *const r049F = nequal(r0392, body.constant(0u));
                        ir_expression *const r04A0 = expr(ir_unop_b2i, r049F);
                        ir_expression *const r04A1 = expr(ir_unop_i2u, r04A0);
                        body.emit(assign(r048A, bit_or(r0388, r04A1), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f049D->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04A3 = less(r0489, body.constant(int(64)));
                        ir_if *f04A2 = new(mem_ctx) ir_if(operand(r04A3).val);
                        exec_list *const f04A2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04A2->then_instructions;

                           ir_expression *const r04A4 = bit_and(r0489, body.constant(int(31)));
                           ir_expression *const r04A5 = rshift(r0388, r04A4);
                           ir_expression *const r04A6 = lshift(r0388, r048B);
                           ir_expression *const r04A7 = bit_or(r04A6, r0392);
                           ir_expression *const r04A8 = nequal(r04A7, body.constant(0u));
                           ir_expression *const r04A9 = expr(ir_unop_b2i, r04A8);
                           ir_expression *const r04AA = expr(ir_unop_i2u, r04A9);
                           body.emit(assign(r048A, bit_or(r04A5, r04AA), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04A2->else_instructions;

                           ir_expression *const r04AB = bit_or(r0388, r0392);
                           ir_expression *const r04AC = nequal(r04AB, body.constant(0u));
                           ir_expression *const r04AD = expr(ir_unop_b2i, r04AC);
                           body.emit(assign(r048A, expr(ir_unop_i2u, r04AD), 0x01));


                        body.instructions = f04A2_parent_instructions;
                        body.emit(f04A2);

                        /* END IF */


                     body.instructions = f049D_parent_instructions;
                     body.emit(f049D);

                     /* END IF */


                  body.instructions = f0494_parent_instructions;
                  body.emit(f0494);

                  /* END IF */


               body.instructions = f0492_parent_instructions;
               body.emit(f0492);

               /* END IF */

               body.emit(assign(r0388, r048D, 0x01));

               body.emit(assign(r0389, r048A, 0x01));

               body.emit(assign(r0386, bit_or(r0386, body.constant(1073741824u)), 0x01));

               ir_variable *const r04AE = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_expression *const r04AF = sub(r0386, r048D);
               ir_expression *const r04B0 = less(r0387, r048A);
               ir_expression *const r04B1 = expr(ir_unop_b2i, r04B0);
               ir_expression *const r04B2 = expr(ir_unop_i2u, r04B1);
               body.emit(assign(r04AE, sub(r04AF, r04B2), 0x01));

               body.emit(assign(r01EE, bit_xor(r01EF, body.constant(1u)), 0x01));

               body.emit(assign(r038A, add(r038E, body.constant(int(-1))), 0x01));

               ir_variable *const r04B3 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04B3, add(r038A, body.constant(int(-10))), 0x01));

               ir_variable *const r04B4 = body.make_temp(glsl_type::uint_type, "zFrac0");
               ir_variable *const r04B5 = body.make_temp(glsl_type::uint_type, "zFrac1");
               ir_variable *const r04B6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r04B6);
               ir_variable *const r04B7 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04B7);
               ir_expression *const r04B8 = equal(r04AE, body.constant(0u));
               ir_expression *const r04B9 = add(r04B3, body.constant(int(-32)));
               body.emit(assign(r04B3, expr(ir_triop_csel, r04B8, r04B9, r04B3), 0x01));

               ir_variable *const r04BA = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04BB = equal(r04AE, body.constant(0u));
               ir_expression *const r04BC = sub(r0387, r048A);
               body.emit(assign(r04BA, expr(ir_triop_csel, r04BB, body.constant(0u), r04BC), 0x01));

               body.emit(assign(r04B5, r04BA, 0x01));

               ir_variable *const r04BD = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r04BE = equal(r04AE, body.constant(0u));
               body.emit(assign(r04BD, expr(ir_triop_csel, r04BE, r04BA, r04AE), 0x01));

               body.emit(assign(r04B4, r04BD, 0x01));

               ir_variable *const r04BF = body.make_temp(glsl_type::uint_type, "a");
               body.emit(assign(r04BF, r04BD, 0x01));

               ir_variable *const r04C0 = body.make_temp(glsl_type::int_type, "return_value");
               ir_variable *const r04C1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04C1);
               /* IF CONDITION */
               ir_expression *const r04C3 = equal(r04BD, body.constant(0u));
               ir_if *f04C2 = new(mem_ctx) ir_if(operand(r04C3).val);
               exec_list *const f04C2_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04C2->then_instructions;

                  body.emit(assign(r04C0, body.constant(int(32)), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04C2->else_instructions;

                  body.emit(assign(r04C1, body.constant(int(0)), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04C5 = bit_and(r04BD, body.constant(4294901760u));
                  ir_expression *const r04C6 = equal(r04C5, body.constant(0u));
                  ir_if *f04C4 = new(mem_ctx) ir_if(operand(r04C6).val);
                  exec_list *const f04C4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C4->then_instructions;

                     body.emit(assign(r04C1, body.constant(int(16)), 0x01));

                     body.emit(assign(r04BF, lshift(r04BD, body.constant(int(16))), 0x01));


                  body.instructions = f04C4_parent_instructions;
                  body.emit(f04C4);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04C8 = bit_and(r04BF, body.constant(4278190080u));
                  ir_expression *const r04C9 = equal(r04C8, body.constant(0u));
                  ir_if *f04C7 = new(mem_ctx) ir_if(operand(r04C9).val);
                  exec_list *const f04C7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C7->then_instructions;

                     body.emit(assign(r04C1, add(r04C1, body.constant(int(8))), 0x01));

                     body.emit(assign(r04BF, lshift(r04BF, body.constant(int(8))), 0x01));


                  body.instructions = f04C7_parent_instructions;
                  body.emit(f04C7);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04CB = bit_and(r04BF, body.constant(4026531840u));
                  ir_expression *const r04CC = equal(r04CB, body.constant(0u));
                  ir_if *f04CA = new(mem_ctx) ir_if(operand(r04CC).val);
                  exec_list *const f04CA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04CA->then_instructions;

                     body.emit(assign(r04C1, add(r04C1, body.constant(int(4))), 0x01));

                     body.emit(assign(r04BF, lshift(r04BF, body.constant(int(4))), 0x01));


                  body.instructions = f04CA_parent_instructions;
                  body.emit(f04CA);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04CE = bit_and(r04BF, body.constant(3221225472u));
                  ir_expression *const r04CF = equal(r04CE, body.constant(0u));
                  ir_if *f04CD = new(mem_ctx) ir_if(operand(r04CF).val);
                  exec_list *const f04CD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04CD->then_instructions;

                     body.emit(assign(r04C1, add(r04C1, body.constant(int(2))), 0x01));

                     body.emit(assign(r04BF, lshift(r04BF, body.constant(int(2))), 0x01));


                  body.instructions = f04CD_parent_instructions;
                  body.emit(f04CD);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04D1 = bit_and(r04BF, body.constant(2147483648u));
                  ir_expression *const r04D2 = equal(r04D1, body.constant(0u));
                  ir_if *f04D0 = new(mem_ctx) ir_if(operand(r04D2).val);
                  exec_list *const f04D0_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04D0->then_instructions;

                     body.emit(assign(r04C1, add(r04C1, body.constant(int(1))), 0x01));


                  body.instructions = f04D0_parent_instructions;
                  body.emit(f04D0);

                  /* END IF */

                  body.emit(assign(r04C0, r04C1, 0x01));


               body.instructions = f04C2_parent_instructions;
               body.emit(f04C2);

               /* END IF */

               body.emit(assign(r04B7, add(r04C0, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04D4 = gequal(r04B7, body.constant(int(0)));
               ir_if *f04D3 = new(mem_ctx) ir_if(operand(r04D4).val);
               exec_list *const f04D3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04D3->then_instructions;

                  body.emit(assign(r04B6, body.constant(0u), 0x01));

                  ir_expression *const r04D5 = equal(r04B7, body.constant(int(0)));
                  ir_expression *const r04D6 = lshift(r04BD, r04B7);
                  ir_expression *const r04D7 = neg(r04B7);
                  ir_expression *const r04D8 = bit_and(r04D7, body.constant(int(31)));
                  ir_expression *const r04D9 = rshift(r04BA, r04D8);
                  ir_expression *const r04DA = bit_or(r04D6, r04D9);
                  body.emit(assign(r04B4, expr(ir_triop_csel, r04D5, r04BD, r04DA), 0x01));

                  body.emit(assign(r04B5, lshift(r04BA, r04B7), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04D3->else_instructions;

                  ir_variable *const r04DB = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r04DB, body.constant(0u), 0x01));

                  ir_variable *const r04DC = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r04DC, neg(r04B7), 0x01));

                  ir_variable *const r04DD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04DD);
                  ir_variable *const r04DE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r04DE);
                  ir_variable *const r04DF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04DF);
                  ir_variable *const r04E0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04E1 = neg(r04DC);
                  body.emit(assign(r04E0, bit_and(r04E1, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04E3 = equal(r04DC, body.constant(int(0)));
                  ir_if *f04E2 = new(mem_ctx) ir_if(operand(r04E3).val);
                  exec_list *const f04E2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04E2->then_instructions;

                     body.emit(assign(r04DD, r04DB, 0x01));

                     body.emit(assign(r04DE, r04B5, 0x01));

                     body.emit(assign(r04DF, r04B4, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04E2->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04E5 = less(r04DC, body.constant(int(32)));
                     ir_if *f04E4 = new(mem_ctx) ir_if(operand(r04E5).val);
                     exec_list *const f04E4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04E4->then_instructions;

                        body.emit(assign(r04DD, lshift(r04B5, r04E0), 0x01));

                        ir_expression *const r04E6 = lshift(r04B4, r04E0);
                        ir_expression *const r04E7 = rshift(r04B5, r04DC);
                        body.emit(assign(r04DE, bit_or(r04E6, r04E7), 0x01));

                        body.emit(assign(r04DF, rshift(r04B4, r04DC), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04E4->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04E9 = equal(r04DC, body.constant(int(32)));
                        ir_if *f04E8 = new(mem_ctx) ir_if(operand(r04E9).val);
                        exec_list *const f04E8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04E8->then_instructions;

                           body.emit(assign(r04DD, r04B5, 0x01));

                           body.emit(assign(r04DE, r04B4, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04E8->else_instructions;

                           body.emit(assign(r04DB, bit_or(body.constant(0u), r04B5), 0x01));

                           ir_expression *const r04EA = less(r04DC, body.constant(int(64)));
                           ir_expression *const r04EB = lshift(r04B4, r04E0);
                           ir_expression *const r04EC = equal(r04DC, body.constant(int(64)));
                           ir_expression *const r04ED = nequal(r04B4, body.constant(0u));
                           ir_expression *const r04EE = expr(ir_unop_b2i, r04ED);
                           ir_expression *const r04EF = expr(ir_unop_i2u, r04EE);
                           ir_expression *const r04F0 = expr(ir_triop_csel, r04EC, r04B4, r04EF);
                           body.emit(assign(r04DD, expr(ir_triop_csel, r04EA, r04EB, r04F0), 0x01));

                           ir_expression *const r04F1 = less(r04DC, body.constant(int(64)));
                           ir_expression *const r04F2 = bit_and(r04DC, body.constant(int(31)));
                           ir_expression *const r04F3 = rshift(r04B4, r04F2);
                           body.emit(assign(r04DE, expr(ir_triop_csel, r04F1, r04F3, body.constant(0u)), 0x01));


                        body.instructions = f04E8_parent_instructions;
                        body.emit(f04E8);

                        /* END IF */

                        body.emit(assign(r04DF, body.constant(0u), 0x01));


                     body.instructions = f04E4_parent_instructions;
                     body.emit(f04E4);

                     /* END IF */

                     ir_expression *const r04F4 = nequal(r04DB, body.constant(0u));
                     ir_expression *const r04F5 = expr(ir_unop_b2i, r04F4);
                     ir_expression *const r04F6 = expr(ir_unop_i2u, r04F5);
                     body.emit(assign(r04DD, bit_or(r04DD, r04F6), 0x01));


                  body.instructions = f04E2_parent_instructions;
                  body.emit(f04E2);

                  /* END IF */

                  body.emit(assign(r04B4, r04DF, 0x01));

                  body.emit(assign(r04B5, r04DE, 0x01));

                  body.emit(assign(r04B6, r04DD, 0x01));


               body.instructions = f04D3_parent_instructions;
               body.emit(f04D3);

               /* END IF */

               body.emit(assign(r04B3, sub(r04B3, r04B7), 0x01));

               ir_variable *const r04F7 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04F7, r04B3, 0x01));

               ir_variable *const r04F8 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04F8, r04B4, 0x01));

               ir_variable *const r04F9 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04F9, r04B5, 0x01));

               ir_variable *const r04FA = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r04FA, r04B6, 0x01));

               ir_variable *const r04FB = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r04FB, body.constant(true), 0x01));

               ir_variable *const r04FC = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04FD = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r04FD);
               ir_expression *const r04FE = expr(ir_unop_u2i, r04B6);
               body.emit(assign(r04FD, less(r04FE, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0500 = gequal(r04B3, body.constant(int(2045)));
               ir_if *f04FF = new(mem_ctx) ir_if(operand(r0500).val);
               exec_list *const f04FF_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04FF->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0502 = less(body.constant(int(2045)), r04B3);
                  ir_expression *const r0503 = equal(r04B3, body.constant(int(2045)));
                  ir_expression *const r0504 = equal(body.constant(2097151u), r04B4);
                  ir_expression *const r0505 = equal(body.constant(4294967295u), r04B5);
                  ir_expression *const r0506 = logic_and(r0504, r0505);
                  ir_expression *const r0507 = logic_and(r0503, r0506);
                  ir_expression *const r0508 = logic_and(r0507, r04FD);
                  ir_expression *const r0509 = logic_or(r0502, r0508);
                  ir_if *f0501 = new(mem_ctx) ir_if(operand(r0509).val);
                  exec_list *const f0501_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0501->then_instructions;

                     ir_variable *const r050A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r050A);
                     ir_expression *const r050B = lshift(r01EE, body.constant(int(31)));
                     body.emit(assign(r050A, add(r050B, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r050A, body.constant(0u), 0x01));

                     body.emit(assign(r04FC, r050A, 0x03));

                     body.emit(assign(r04FB, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0501->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r050D = less(r04B3, body.constant(int(0)));
                     ir_if *f050C = new(mem_ctx) ir_if(operand(r050D).val);
                     exec_list *const f050C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f050C->then_instructions;

                        ir_variable *const r050E = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r050E, r04B6, 0x01));

                        ir_variable *const r050F = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r050F, neg(r04B3), 0x01));

                        ir_variable *const r0510 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0510);
                        ir_variable *const r0511 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r0511);
                        ir_variable *const r0512 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0512);
                        ir_variable *const r0513 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0514 = neg(r050F);
                        body.emit(assign(r0513, bit_and(r0514, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0516 = equal(r050F, body.constant(int(0)));
                        ir_if *f0515 = new(mem_ctx) ir_if(operand(r0516).val);
                        exec_list *const f0515_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0515->then_instructions;

                           body.emit(assign(r0510, r04B6, 0x01));

                           body.emit(assign(r0511, r04B5, 0x01));

                           body.emit(assign(r0512, r04B4, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0515->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0518 = less(r050F, body.constant(int(32)));
                           ir_if *f0517 = new(mem_ctx) ir_if(operand(r0518).val);
                           exec_list *const f0517_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0517->then_instructions;

                              body.emit(assign(r0510, lshift(r04B5, r0513), 0x01));

                              ir_expression *const r0519 = lshift(r04B4, r0513);
                              ir_expression *const r051A = rshift(r04B5, r050F);
                              body.emit(assign(r0511, bit_or(r0519, r051A), 0x01));

                              body.emit(assign(r0512, rshift(r04B4, r050F), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0517->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r051C = equal(r050F, body.constant(int(32)));
                              ir_if *f051B = new(mem_ctx) ir_if(operand(r051C).val);
                              exec_list *const f051B_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f051B->then_instructions;

                                 body.emit(assign(r0510, r04B5, 0x01));

                                 body.emit(assign(r0511, r04B4, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f051B->else_instructions;

                                 body.emit(assign(r050E, bit_or(r04B6, r04B5), 0x01));

                                 ir_expression *const r051D = less(r050F, body.constant(int(64)));
                                 ir_expression *const r051E = lshift(r04B4, r0513);
                                 ir_expression *const r051F = equal(r050F, body.constant(int(64)));
                                 ir_expression *const r0520 = nequal(r04B4, body.constant(0u));
                                 ir_expression *const r0521 = expr(ir_unop_b2i, r0520);
                                 ir_expression *const r0522 = expr(ir_unop_i2u, r0521);
                                 ir_expression *const r0523 = expr(ir_triop_csel, r051F, r04B4, r0522);
                                 body.emit(assign(r0510, expr(ir_triop_csel, r051D, r051E, r0523), 0x01));

                                 ir_expression *const r0524 = less(r050F, body.constant(int(64)));
                                 ir_expression *const r0525 = bit_and(r050F, body.constant(int(31)));
                                 ir_expression *const r0526 = rshift(r04B4, r0525);
                                 body.emit(assign(r0511, expr(ir_triop_csel, r0524, r0526, body.constant(0u)), 0x01));


                              body.instructions = f051B_parent_instructions;
                              body.emit(f051B);

                              /* END IF */

                              body.emit(assign(r0512, body.constant(0u), 0x01));


                           body.instructions = f0517_parent_instructions;
                           body.emit(f0517);

                           /* END IF */

                           ir_expression *const r0527 = nequal(r050E, body.constant(0u));
                           ir_expression *const r0528 = expr(ir_unop_b2i, r0527);
                           ir_expression *const r0529 = expr(ir_unop_i2u, r0528);
                           body.emit(assign(r0510, bit_or(r0510, r0529), 0x01));


                        body.instructions = f0515_parent_instructions;
                        body.emit(f0515);

                        /* END IF */

                        body.emit(assign(r04F8, r0512, 0x01));

                        body.emit(assign(r04F9, r0511, 0x01));

                        body.emit(assign(r04FA, r0510, 0x01));

                        body.emit(assign(r04F7, body.constant(int(0)), 0x01));

                        body.emit(assign(r04FD, less(r0510, body.constant(0u)), 0x01));


                     body.instructions = f050C_parent_instructions;
                     body.emit(f050C);

                     /* END IF */


                  body.instructions = f0501_parent_instructions;
                  body.emit(f0501);

                  /* END IF */


               body.instructions = f04FF_parent_instructions;
               body.emit(f04FF);

               /* END IF */

               /* IF CONDITION */
               ir_if *f052A = new(mem_ctx) ir_if(operand(r04FB).val);
               exec_list *const f052A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f052A->then_instructions;

                  /* IF CONDITION */
                  ir_if *f052B = new(mem_ctx) ir_if(operand(r04FD).val);
                  exec_list *const f052B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f052B->then_instructions;

                     ir_variable *const r052C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r052C, add(r04F9, body.constant(1u)), 0x01));

                     ir_expression *const r052D = less(r052C, r04F9);
                     ir_expression *const r052E = expr(ir_unop_b2i, r052D);
                     ir_expression *const r052F = expr(ir_unop_i2u, r052E);
                     body.emit(assign(r04F8, add(r04F8, r052F), 0x01));

                     ir_expression *const r0530 = equal(r04FA, body.constant(0u));
                     ir_expression *const r0531 = expr(ir_unop_b2i, r0530);
                     ir_expression *const r0532 = expr(ir_unop_i2u, r0531);
                     ir_expression *const r0533 = add(r04FA, r0532);
                     ir_expression *const r0534 = bit_and(r0533, body.constant(1u));
                     ir_expression *const r0535 = expr(ir_unop_bit_not, r0534);
                     body.emit(assign(r04F9, bit_and(r052C, r0535), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f052B->else_instructions;

                     ir_expression *const r0536 = bit_or(r04F8, r04F9);
                     ir_expression *const r0537 = equal(r0536, body.constant(0u));
                     body.emit(assign(r04F7, expr(ir_triop_csel, r0537, body.constant(int(0)), r04F7), 0x01));


                  body.instructions = f052B_parent_instructions;
                  body.emit(f052B);

                  /* END IF */

                  ir_variable *const r0538 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0538);
                  ir_expression *const r0539 = lshift(r01EE, body.constant(int(31)));
                  ir_expression *const r053A = expr(ir_unop_i2u, r04F7);
                  ir_expression *const r053B = lshift(r053A, body.constant(int(20)));
                  ir_expression *const r053C = add(r0539, r053B);
                  body.emit(assign(r0538, add(r053C, r04F8), 0x02));

                  body.emit(assign(r0538, r04F9, 0x01));

                  body.emit(assign(r04FC, r0538, 0x03));

                  body.emit(assign(r04FB, body.constant(false), 0x01));


               body.instructions = f052A_parent_instructions;
               body.emit(f052A);

               /* END IF */

               body.emit(assign(r01ED, r04FC, 0x03));

               body.emit(assign(r01EC, body.constant(false), 0x01));


            body.instructions = f046C_parent_instructions;
            body.emit(f046C);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f046A->else_instructions;

            /* IF CONDITION */
            ir_expression *const r053E = equal(r038B, body.constant(int(2047)));
            ir_if *f053D = new(mem_ctx) ir_if(operand(r053E).val);
            exec_list *const f053D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f053D->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0540 = bit_or(r0388, r0389);
               ir_expression *const r0541 = bit_or(r0386, r0387);
               ir_expression *const r0542 = bit_or(r0540, r0541);
               ir_expression *const r0543 = nequal(r0542, body.constant(0u));
               ir_if *f053F = new(mem_ctx) ir_if(operand(r0543).val);
               exec_list *const f053F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f053F->then_instructions;

                  ir_variable *const r0544 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0544, swizzle_x(r01EA), 0x01));

                  ir_variable *const r0545 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0545, swizzle_x(r01EB), 0x01));

                  body.emit(assign(r0544, bit_or(swizzle_y(r01EA), body.constant(524288u)), 0x02));

                  body.emit(assign(r0545, bit_or(swizzle_y(r01EB), body.constant(524288u)), 0x02));

                  ir_expression *const r0546 = lshift(swizzle_y(r01EA), body.constant(int(1)));
                  ir_expression *const r0547 = gequal(r0546, body.constant(4292870144u));
                  ir_expression *const r0548 = nequal(swizzle_x(r01EA), body.constant(0u));
                  ir_expression *const r0549 = bit_and(swizzle_y(r01EA), body.constant(1048575u));
                  ir_expression *const r054A = nequal(r0549, body.constant(0u));
                  ir_expression *const r054B = logic_or(r0548, r054A);
                  ir_expression *const r054C = logic_and(r0547, r054B);
                  ir_swizzle *const r054D = swizzle(r054C, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r054E = lshift(swizzle_y(r01EB), body.constant(int(1)));
                  ir_expression *const r054F = gequal(r054E, body.constant(4292870144u));
                  ir_expression *const r0550 = nequal(swizzle_x(r01EB), body.constant(0u));
                  ir_expression *const r0551 = bit_and(swizzle_y(r01EB), body.constant(1048575u));
                  ir_expression *const r0552 = nequal(r0551, body.constant(0u));
                  ir_expression *const r0553 = logic_or(r0550, r0552);
                  ir_expression *const r0554 = logic_and(r054F, r0553);
                  ir_swizzle *const r0555 = swizzle(r0554, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0556 = expr(ir_triop_csel, r0555, r0545, r0544);
                  body.emit(assign(r01ED, expr(ir_triop_csel, r054D, r0556, r0545), 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f053F->else_instructions;

                  ir_constant_data r0557_data;
                  memset(&r0557_data, 0, sizeof(ir_constant_data));
                  r0557_data.u[0] = 4294967295;
                  r0557_data.u[1] = 4294967295;
                  ir_constant *const r0557 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0557_data);
                  body.emit(assign(r01ED, r0557, 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


               body.instructions = f053F_parent_instructions;
               body.emit(f053F);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f053D->else_instructions;

               ir_expression *const r0558 = equal(r038B, body.constant(int(0)));
               body.emit(assign(r0384, expr(ir_triop_csel, r0558, body.constant(int(1)), r038E), 0x01));

               ir_expression *const r0559 = equal(r038B, body.constant(int(0)));
               body.emit(assign(r0385, expr(ir_triop_csel, r0559, body.constant(int(1)), r038B), 0x01));

               /* IF CONDITION */
               ir_expression *const r055B = less(r0386, r0388);
               ir_if *f055A = new(mem_ctx) ir_if(operand(r055B).val);
               exec_list *const f055A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f055A->then_instructions;

                  ir_variable *const r055C = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_expression *const r055D = sub(r0388, r0386);
                  ir_expression *const r055E = less(r0389, r0387);
                  ir_expression *const r055F = expr(ir_unop_b2i, r055E);
                  ir_expression *const r0560 = expr(ir_unop_i2u, r055F);
                  body.emit(assign(r055C, sub(r055D, r0560), 0x01));

                  body.emit(assign(r038A, add(r0385, body.constant(int(-1))), 0x01));

                  ir_variable *const r0561 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0561, add(r038A, body.constant(int(-10))), 0x01));

                  ir_variable *const r0562 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  ir_variable *const r0563 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  ir_variable *const r0564 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r0564);
                  ir_variable *const r0565 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0565);
                  ir_expression *const r0566 = equal(r055C, body.constant(0u));
                  ir_expression *const r0567 = add(r0561, body.constant(int(-32)));
                  body.emit(assign(r0561, expr(ir_triop_csel, r0566, r0567, r0561), 0x01));

                  ir_variable *const r0568 = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r0569 = equal(r055C, body.constant(0u));
                  ir_expression *const r056A = sub(r0389, r0387);
                  body.emit(assign(r0568, expr(ir_triop_csel, r0569, body.constant(0u), r056A), 0x01));

                  body.emit(assign(r0563, r0568, 0x01));

                  ir_variable *const r056B = body.make_temp(glsl_type::uint_type, "mix_retval");
                  ir_expression *const r056C = equal(r055C, body.constant(0u));
                  body.emit(assign(r056B, expr(ir_triop_csel, r056C, r0568, r055C), 0x01));

                  body.emit(assign(r0562, r056B, 0x01));

                  ir_variable *const r056D = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r056D, r056B, 0x01));

                  ir_variable *const r056E = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r056F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r056F);
                  /* IF CONDITION */
                  ir_expression *const r0571 = equal(r056B, body.constant(0u));
                  ir_if *f0570 = new(mem_ctx) ir_if(operand(r0571).val);
                  exec_list *const f0570_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0570->then_instructions;

                     body.emit(assign(r056E, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0570->else_instructions;

                     body.emit(assign(r056F, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0573 = bit_and(r056B, body.constant(4294901760u));
                     ir_expression *const r0574 = equal(r0573, body.constant(0u));
                     ir_if *f0572 = new(mem_ctx) ir_if(operand(r0574).val);
                     exec_list *const f0572_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0572->then_instructions;

                        body.emit(assign(r056F, body.constant(int(16)), 0x01));

                        body.emit(assign(r056D, lshift(r056B, body.constant(int(16))), 0x01));


                     body.instructions = f0572_parent_instructions;
                     body.emit(f0572);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0576 = bit_and(r056D, body.constant(4278190080u));
                     ir_expression *const r0577 = equal(r0576, body.constant(0u));
                     ir_if *f0575 = new(mem_ctx) ir_if(operand(r0577).val);
                     exec_list *const f0575_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0575->then_instructions;

                        body.emit(assign(r056F, add(r056F, body.constant(int(8))), 0x01));

                        body.emit(assign(r056D, lshift(r056D, body.constant(int(8))), 0x01));


                     body.instructions = f0575_parent_instructions;
                     body.emit(f0575);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0579 = bit_and(r056D, body.constant(4026531840u));
                     ir_expression *const r057A = equal(r0579, body.constant(0u));
                     ir_if *f0578 = new(mem_ctx) ir_if(operand(r057A).val);
                     exec_list *const f0578_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0578->then_instructions;

                        body.emit(assign(r056F, add(r056F, body.constant(int(4))), 0x01));

                        body.emit(assign(r056D, lshift(r056D, body.constant(int(4))), 0x01));


                     body.instructions = f0578_parent_instructions;
                     body.emit(f0578);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r057C = bit_and(r056D, body.constant(3221225472u));
                     ir_expression *const r057D = equal(r057C, body.constant(0u));
                     ir_if *f057B = new(mem_ctx) ir_if(operand(r057D).val);
                     exec_list *const f057B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f057B->then_instructions;

                        body.emit(assign(r056F, add(r056F, body.constant(int(2))), 0x01));

                        body.emit(assign(r056D, lshift(r056D, body.constant(int(2))), 0x01));


                     body.instructions = f057B_parent_instructions;
                     body.emit(f057B);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r057F = bit_and(r056D, body.constant(2147483648u));
                     ir_expression *const r0580 = equal(r057F, body.constant(0u));
                     ir_if *f057E = new(mem_ctx) ir_if(operand(r0580).val);
                     exec_list *const f057E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f057E->then_instructions;

                        body.emit(assign(r056F, add(r056F, body.constant(int(1))), 0x01));


                     body.instructions = f057E_parent_instructions;
                     body.emit(f057E);

                     /* END IF */

                     body.emit(assign(r056E, r056F, 0x01));


                  body.instructions = f0570_parent_instructions;
                  body.emit(f0570);

                  /* END IF */

                  body.emit(assign(r0565, add(r056E, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0582 = gequal(r0565, body.constant(int(0)));
                  ir_if *f0581 = new(mem_ctx) ir_if(operand(r0582).val);
                  exec_list *const f0581_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0581->then_instructions;

                     body.emit(assign(r0564, body.constant(0u), 0x01));

                     ir_expression *const r0583 = equal(r0565, body.constant(int(0)));
                     ir_expression *const r0584 = lshift(r056B, r0565);
                     ir_expression *const r0585 = neg(r0565);
                     ir_expression *const r0586 = bit_and(r0585, body.constant(int(31)));
                     ir_expression *const r0587 = rshift(r0568, r0586);
                     ir_expression *const r0588 = bit_or(r0584, r0587);
                     body.emit(assign(r0562, expr(ir_triop_csel, r0583, r056B, r0588), 0x01));

                     body.emit(assign(r0563, lshift(r0568, r0565), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0581->else_instructions;

                     ir_variable *const r0589 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0589, body.constant(0u), 0x01));

                     ir_variable *const r058A = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r058A, neg(r0565), 0x01));

                     ir_variable *const r058B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r058B);
                     ir_variable *const r058C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r058C);
                     ir_variable *const r058D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r058D);
                     ir_variable *const r058E = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r058F = neg(r058A);
                     body.emit(assign(r058E, bit_and(r058F, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0591 = equal(r058A, body.constant(int(0)));
                     ir_if *f0590 = new(mem_ctx) ir_if(operand(r0591).val);
                     exec_list *const f0590_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0590->then_instructions;

                        body.emit(assign(r058B, r0589, 0x01));

                        body.emit(assign(r058C, r0563, 0x01));

                        body.emit(assign(r058D, r0562, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0590->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0593 = less(r058A, body.constant(int(32)));
                        ir_if *f0592 = new(mem_ctx) ir_if(operand(r0593).val);
                        exec_list *const f0592_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0592->then_instructions;

                           body.emit(assign(r058B, lshift(r0563, r058E), 0x01));

                           ir_expression *const r0594 = lshift(r0562, r058E);
                           ir_expression *const r0595 = rshift(r0563, r058A);
                           body.emit(assign(r058C, bit_or(r0594, r0595), 0x01));

                           body.emit(assign(r058D, rshift(r0562, r058A), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0592->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0597 = equal(r058A, body.constant(int(32)));
                           ir_if *f0596 = new(mem_ctx) ir_if(operand(r0597).val);
                           exec_list *const f0596_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0596->then_instructions;

                              body.emit(assign(r058B, r0563, 0x01));

                              body.emit(assign(r058C, r0562, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0596->else_instructions;

                              body.emit(assign(r0589, bit_or(body.constant(0u), r0563), 0x01));

                              ir_expression *const r0598 = less(r058A, body.constant(int(64)));
                              ir_expression *const r0599 = lshift(r0562, r058E);
                              ir_expression *const r059A = equal(r058A, body.constant(int(64)));
                              ir_expression *const r059B = nequal(r0562, body.constant(0u));
                              ir_expression *const r059C = expr(ir_unop_b2i, r059B);
                              ir_expression *const r059D = expr(ir_unop_i2u, r059C);
                              ir_expression *const r059E = expr(ir_triop_csel, r059A, r0562, r059D);
                              body.emit(assign(r058B, expr(ir_triop_csel, r0598, r0599, r059E), 0x01));

                              ir_expression *const r059F = less(r058A, body.constant(int(64)));
                              ir_expression *const r05A0 = bit_and(r058A, body.constant(int(31)));
                              ir_expression *const r05A1 = rshift(r0562, r05A0);
                              body.emit(assign(r058C, expr(ir_triop_csel, r059F, r05A1, body.constant(0u)), 0x01));


                           body.instructions = f0596_parent_instructions;
                           body.emit(f0596);

                           /* END IF */

                           body.emit(assign(r058D, body.constant(0u), 0x01));


                        body.instructions = f0592_parent_instructions;
                        body.emit(f0592);

                        /* END IF */

                        ir_expression *const r05A2 = nequal(r0589, body.constant(0u));
                        ir_expression *const r05A3 = expr(ir_unop_b2i, r05A2);
                        ir_expression *const r05A4 = expr(ir_unop_i2u, r05A3);
                        body.emit(assign(r058B, bit_or(r058B, r05A4), 0x01));


                     body.instructions = f0590_parent_instructions;
                     body.emit(f0590);

                     /* END IF */

                     body.emit(assign(r0562, r058D, 0x01));

                     body.emit(assign(r0563, r058C, 0x01));

                     body.emit(assign(r0564, r058B, 0x01));


                  body.instructions = f0581_parent_instructions;
                  body.emit(f0581);

                  /* END IF */

                  body.emit(assign(r0561, sub(r0561, r0565), 0x01));

                  ir_variable *const r05A5 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r05A5, r0561, 0x01));

                  ir_variable *const r05A6 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r05A6, r0562, 0x01));

                  ir_variable *const r05A7 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r05A7, r0563, 0x01));

                  ir_variable *const r05A8 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r05A8, r0564, 0x01));

                  ir_variable *const r05A9 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r05A9, body.constant(true), 0x01));

                  ir_variable *const r05AA = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r05AB = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r05AB);
                  ir_expression *const r05AC = expr(ir_unop_u2i, r0564);
                  body.emit(assign(r05AB, less(r05AC, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r05AE = gequal(r0561, body.constant(int(2045)));
                  ir_if *f05AD = new(mem_ctx) ir_if(operand(r05AE).val);
                  exec_list *const f05AD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05AD->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r05B0 = less(body.constant(int(2045)), r0561);
                     ir_expression *const r05B1 = equal(r0561, body.constant(int(2045)));
                     ir_expression *const r05B2 = equal(body.constant(2097151u), r0562);
                     ir_expression *const r05B3 = equal(body.constant(4294967295u), r0563);
                     ir_expression *const r05B4 = logic_and(r05B2, r05B3);
                     ir_expression *const r05B5 = logic_and(r05B1, r05B4);
                     ir_expression *const r05B6 = logic_and(r05B5, r05AB);
                     ir_expression *const r05B7 = logic_or(r05B0, r05B6);
                     ir_if *f05AF = new(mem_ctx) ir_if(operand(r05B7).val);
                     exec_list *const f05AF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05AF->then_instructions;

                        ir_variable *const r05B8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r05B8);
                        ir_expression *const r05B9 = lshift(r01EE, body.constant(int(31)));
                        body.emit(assign(r05B8, add(r05B9, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r05B8, body.constant(0u), 0x01));

                        body.emit(assign(r05AA, r05B8, 0x03));

                        body.emit(assign(r05A9, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05AF->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05BB = less(r0561, body.constant(int(0)));
                        ir_if *f05BA = new(mem_ctx) ir_if(operand(r05BB).val);
                        exec_list *const f05BA_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05BA->then_instructions;

                           ir_variable *const r05BC = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r05BC, r0564, 0x01));

                           ir_variable *const r05BD = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r05BD, neg(r0561), 0x01));

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

                              body.emit(assign(r05BE, r0564, 0x01));

                              body.emit(assign(r05BF, r0563, 0x01));

                              body.emit(assign(r05C0, r0562, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05C3->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05C6 = less(r05BD, body.constant(int(32)));
                              ir_if *f05C5 = new(mem_ctx) ir_if(operand(r05C6).val);
                              exec_list *const f05C5_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05C5->then_instructions;

                                 body.emit(assign(r05BE, lshift(r0563, r05C1), 0x01));

                                 ir_expression *const r05C7 = lshift(r0562, r05C1);
                                 ir_expression *const r05C8 = rshift(r0563, r05BD);
                                 body.emit(assign(r05BF, bit_or(r05C7, r05C8), 0x01));

                                 body.emit(assign(r05C0, rshift(r0562, r05BD), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05C5->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05CA = equal(r05BD, body.constant(int(32)));
                                 ir_if *f05C9 = new(mem_ctx) ir_if(operand(r05CA).val);
                                 exec_list *const f05C9_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05C9->then_instructions;

                                    body.emit(assign(r05BE, r0563, 0x01));

                                    body.emit(assign(r05BF, r0562, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05C9->else_instructions;

                                    body.emit(assign(r05BC, bit_or(r0564, r0563), 0x01));

                                    ir_expression *const r05CB = less(r05BD, body.constant(int(64)));
                                    ir_expression *const r05CC = lshift(r0562, r05C1);
                                    ir_expression *const r05CD = equal(r05BD, body.constant(int(64)));
                                    ir_expression *const r05CE = nequal(r0562, body.constant(0u));
                                    ir_expression *const r05CF = expr(ir_unop_b2i, r05CE);
                                    ir_expression *const r05D0 = expr(ir_unop_i2u, r05CF);
                                    ir_expression *const r05D1 = expr(ir_triop_csel, r05CD, r0562, r05D0);
                                    body.emit(assign(r05BE, expr(ir_triop_csel, r05CB, r05CC, r05D1), 0x01));

                                    ir_expression *const r05D2 = less(r05BD, body.constant(int(64)));
                                    ir_expression *const r05D3 = bit_and(r05BD, body.constant(int(31)));
                                    ir_expression *const r05D4 = rshift(r0562, r05D3);
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

                           body.emit(assign(r05A6, r05C0, 0x01));

                           body.emit(assign(r05A7, r05BF, 0x01));

                           body.emit(assign(r05A8, r05BE, 0x01));

                           body.emit(assign(r05A5, body.constant(int(0)), 0x01));

                           body.emit(assign(r05AB, less(r05BE, body.constant(0u)), 0x01));


                        body.instructions = f05BA_parent_instructions;
                        body.emit(f05BA);

                        /* END IF */


                     body.instructions = f05AF_parent_instructions;
                     body.emit(f05AF);

                     /* END IF */


                  body.instructions = f05AD_parent_instructions;
                  body.emit(f05AD);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f05D8 = new(mem_ctx) ir_if(operand(r05A9).val);
                  exec_list *const f05D8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05D8->then_instructions;

                     /* IF CONDITION */
                     ir_if *f05D9 = new(mem_ctx) ir_if(operand(r05AB).val);
                     exec_list *const f05D9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05D9->then_instructions;

                        ir_variable *const r05DA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r05DA, add(r05A7, body.constant(1u)), 0x01));

                        ir_expression *const r05DB = less(r05DA, r05A7);
                        ir_expression *const r05DC = expr(ir_unop_b2i, r05DB);
                        ir_expression *const r05DD = expr(ir_unop_i2u, r05DC);
                        body.emit(assign(r05A6, add(r05A6, r05DD), 0x01));

                        ir_expression *const r05DE = equal(r05A8, body.constant(0u));
                        ir_expression *const r05DF = expr(ir_unop_b2i, r05DE);
                        ir_expression *const r05E0 = expr(ir_unop_i2u, r05DF);
                        ir_expression *const r05E1 = add(r05A8, r05E0);
                        ir_expression *const r05E2 = bit_and(r05E1, body.constant(1u));
                        ir_expression *const r05E3 = expr(ir_unop_bit_not, r05E2);
                        body.emit(assign(r05A7, bit_and(r05DA, r05E3), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05D9->else_instructions;

                        ir_expression *const r05E4 = bit_or(r05A6, r05A7);
                        ir_expression *const r05E5 = equal(r05E4, body.constant(0u));
                        body.emit(assign(r05A5, expr(ir_triop_csel, r05E5, body.constant(int(0)), r05A5), 0x01));


                     body.instructions = f05D9_parent_instructions;
                     body.emit(f05D9);

                     /* END IF */

                     ir_variable *const r05E6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r05E6);
                     ir_expression *const r05E7 = lshift(r01EE, body.constant(int(31)));
                     ir_expression *const r05E8 = expr(ir_unop_i2u, r05A5);
                     ir_expression *const r05E9 = lshift(r05E8, body.constant(int(20)));
                     ir_expression *const r05EA = add(r05E7, r05E9);
                     body.emit(assign(r05E6, add(r05EA, r05A6), 0x02));

                     body.emit(assign(r05E6, r05A7, 0x01));

                     body.emit(assign(r05AA, r05E6, 0x03));

                     body.emit(assign(r05A9, body.constant(false), 0x01));


                  body.instructions = f05D8_parent_instructions;
                  body.emit(f05D8);

                  /* END IF */

                  body.emit(assign(r01ED, r05AA, 0x03));

                  body.emit(assign(r01EC, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f055A->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05EC = less(r0388, r0386);
                  ir_if *f05EB = new(mem_ctx) ir_if(operand(r05EC).val);
                  exec_list *const f05EB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05EB->then_instructions;

                     ir_variable *const r05ED = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_expression *const r05EE = sub(r0386, r0388);
                     ir_expression *const r05EF = less(r0387, r0389);
                     ir_expression *const r05F0 = expr(ir_unop_b2i, r05EF);
                     ir_expression *const r05F1 = expr(ir_unop_i2u, r05F0);
                     body.emit(assign(r05ED, sub(r05EE, r05F1), 0x01));

                     body.emit(assign(r01EE, bit_xor(r01EE, body.constant(1u)), 0x01));

                     body.emit(assign(r038A, add(r0384, body.constant(int(-1))), 0x01));

                     ir_variable *const r05F2 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05F2, add(r038A, body.constant(int(-10))), 0x01));

                     ir_variable *const r05F3 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     ir_variable *const r05F4 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     ir_variable *const r05F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r05F5);
                     ir_variable *const r05F6 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05F6);
                     ir_expression *const r05F7 = equal(r05ED, body.constant(0u));
                     ir_expression *const r05F8 = add(r05F2, body.constant(int(-32)));
                     body.emit(assign(r05F2, expr(ir_triop_csel, r05F7, r05F8, r05F2), 0x01));

                     ir_variable *const r05F9 = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05FA = equal(r05ED, body.constant(0u));
                     ir_expression *const r05FB = sub(r0387, r0389);
                     body.emit(assign(r05F9, expr(ir_triop_csel, r05FA, body.constant(0u), r05FB), 0x01));

                     body.emit(assign(r05F4, r05F9, 0x01));

                     ir_variable *const r05FC = body.make_temp(glsl_type::uint_type, "mix_retval");
                     ir_expression *const r05FD = equal(r05ED, body.constant(0u));
                     body.emit(assign(r05FC, expr(ir_triop_csel, r05FD, r05F9, r05ED), 0x01));

                     body.emit(assign(r05F3, r05FC, 0x01));

                     ir_variable *const r05FE = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r05FE, r05FC, 0x01));

                     ir_variable *const r05FF = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r0600 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0600);
                     /* IF CONDITION */
                     ir_expression *const r0602 = equal(r05FC, body.constant(0u));
                     ir_if *f0601 = new(mem_ctx) ir_if(operand(r0602).val);
                     exec_list *const f0601_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0601->then_instructions;

                        body.emit(assign(r05FF, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0601->else_instructions;

                        body.emit(assign(r0600, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0604 = bit_and(r05FC, body.constant(4294901760u));
                        ir_expression *const r0605 = equal(r0604, body.constant(0u));
                        ir_if *f0603 = new(mem_ctx) ir_if(operand(r0605).val);
                        exec_list *const f0603_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0603->then_instructions;

                           body.emit(assign(r0600, body.constant(int(16)), 0x01));

                           body.emit(assign(r05FE, lshift(r05FC, body.constant(int(16))), 0x01));


                        body.instructions = f0603_parent_instructions;
                        body.emit(f0603);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0607 = bit_and(r05FE, body.constant(4278190080u));
                        ir_expression *const r0608 = equal(r0607, body.constant(0u));
                        ir_if *f0606 = new(mem_ctx) ir_if(operand(r0608).val);
                        exec_list *const f0606_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0606->then_instructions;

                           body.emit(assign(r0600, add(r0600, body.constant(int(8))), 0x01));

                           body.emit(assign(r05FE, lshift(r05FE, body.constant(int(8))), 0x01));


                        body.instructions = f0606_parent_instructions;
                        body.emit(f0606);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r060A = bit_and(r05FE, body.constant(4026531840u));
                        ir_expression *const r060B = equal(r060A, body.constant(0u));
                        ir_if *f0609 = new(mem_ctx) ir_if(operand(r060B).val);
                        exec_list *const f0609_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0609->then_instructions;

                           body.emit(assign(r0600, add(r0600, body.constant(int(4))), 0x01));

                           body.emit(assign(r05FE, lshift(r05FE, body.constant(int(4))), 0x01));


                        body.instructions = f0609_parent_instructions;
                        body.emit(f0609);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r060D = bit_and(r05FE, body.constant(3221225472u));
                        ir_expression *const r060E = equal(r060D, body.constant(0u));
                        ir_if *f060C = new(mem_ctx) ir_if(operand(r060E).val);
                        exec_list *const f060C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f060C->then_instructions;

                           body.emit(assign(r0600, add(r0600, body.constant(int(2))), 0x01));

                           body.emit(assign(r05FE, lshift(r05FE, body.constant(int(2))), 0x01));


                        body.instructions = f060C_parent_instructions;
                        body.emit(f060C);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0610 = bit_and(r05FE, body.constant(2147483648u));
                        ir_expression *const r0611 = equal(r0610, body.constant(0u));
                        ir_if *f060F = new(mem_ctx) ir_if(operand(r0611).val);
                        exec_list *const f060F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f060F->then_instructions;

                           body.emit(assign(r0600, add(r0600, body.constant(int(1))), 0x01));


                        body.instructions = f060F_parent_instructions;
                        body.emit(f060F);

                        /* END IF */

                        body.emit(assign(r05FF, r0600, 0x01));


                     body.instructions = f0601_parent_instructions;
                     body.emit(f0601);

                     /* END IF */

                     body.emit(assign(r05F6, add(r05FF, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0613 = gequal(r05F6, body.constant(int(0)));
                     ir_if *f0612 = new(mem_ctx) ir_if(operand(r0613).val);
                     exec_list *const f0612_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0612->then_instructions;

                        body.emit(assign(r05F5, body.constant(0u), 0x01));

                        ir_expression *const r0614 = equal(r05F6, body.constant(int(0)));
                        ir_expression *const r0615 = lshift(r05FC, r05F6);
                        ir_expression *const r0616 = neg(r05F6);
                        ir_expression *const r0617 = bit_and(r0616, body.constant(int(31)));
                        ir_expression *const r0618 = rshift(r05F9, r0617);
                        ir_expression *const r0619 = bit_or(r0615, r0618);
                        body.emit(assign(r05F3, expr(ir_triop_csel, r0614, r05FC, r0619), 0x01));

                        body.emit(assign(r05F4, lshift(r05F9, r05F6), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0612->else_instructions;

                        ir_variable *const r061A = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r061A, body.constant(0u), 0x01));

                        ir_variable *const r061B = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r061B, neg(r05F6), 0x01));

                        ir_variable *const r061C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r061C);
                        ir_variable *const r061D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r061D);
                        ir_variable *const r061E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r061E);
                        ir_variable *const r061F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0620 = neg(r061B);
                        body.emit(assign(r061F, bit_and(r0620, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0622 = equal(r061B, body.constant(int(0)));
                        ir_if *f0621 = new(mem_ctx) ir_if(operand(r0622).val);
                        exec_list *const f0621_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0621->then_instructions;

                           body.emit(assign(r061C, r061A, 0x01));

                           body.emit(assign(r061D, r05F4, 0x01));

                           body.emit(assign(r061E, r05F3, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0621->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0624 = less(r061B, body.constant(int(32)));
                           ir_if *f0623 = new(mem_ctx) ir_if(operand(r0624).val);
                           exec_list *const f0623_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0623->then_instructions;

                              body.emit(assign(r061C, lshift(r05F4, r061F), 0x01));

                              ir_expression *const r0625 = lshift(r05F3, r061F);
                              ir_expression *const r0626 = rshift(r05F4, r061B);
                              body.emit(assign(r061D, bit_or(r0625, r0626), 0x01));

                              body.emit(assign(r061E, rshift(r05F3, r061B), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0623->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0628 = equal(r061B, body.constant(int(32)));
                              ir_if *f0627 = new(mem_ctx) ir_if(operand(r0628).val);
                              exec_list *const f0627_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0627->then_instructions;

                                 body.emit(assign(r061C, r05F4, 0x01));

                                 body.emit(assign(r061D, r05F3, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0627->else_instructions;

                                 body.emit(assign(r061A, bit_or(body.constant(0u), r05F4), 0x01));

                                 ir_expression *const r0629 = less(r061B, body.constant(int(64)));
                                 ir_expression *const r062A = lshift(r05F3, r061F);
                                 ir_expression *const r062B = equal(r061B, body.constant(int(64)));
                                 ir_expression *const r062C = nequal(r05F3, body.constant(0u));
                                 ir_expression *const r062D = expr(ir_unop_b2i, r062C);
                                 ir_expression *const r062E = expr(ir_unop_i2u, r062D);
                                 ir_expression *const r062F = expr(ir_triop_csel, r062B, r05F3, r062E);
                                 body.emit(assign(r061C, expr(ir_triop_csel, r0629, r062A, r062F), 0x01));

                                 ir_expression *const r0630 = less(r061B, body.constant(int(64)));
                                 ir_expression *const r0631 = bit_and(r061B, body.constant(int(31)));
                                 ir_expression *const r0632 = rshift(r05F3, r0631);
                                 body.emit(assign(r061D, expr(ir_triop_csel, r0630, r0632, body.constant(0u)), 0x01));


                              body.instructions = f0627_parent_instructions;
                              body.emit(f0627);

                              /* END IF */

                              body.emit(assign(r061E, body.constant(0u), 0x01));


                           body.instructions = f0623_parent_instructions;
                           body.emit(f0623);

                           /* END IF */

                           ir_expression *const r0633 = nequal(r061A, body.constant(0u));
                           ir_expression *const r0634 = expr(ir_unop_b2i, r0633);
                           ir_expression *const r0635 = expr(ir_unop_i2u, r0634);
                           body.emit(assign(r061C, bit_or(r061C, r0635), 0x01));


                        body.instructions = f0621_parent_instructions;
                        body.emit(f0621);

                        /* END IF */

                        body.emit(assign(r05F3, r061E, 0x01));

                        body.emit(assign(r05F4, r061D, 0x01));

                        body.emit(assign(r05F5, r061C, 0x01));


                     body.instructions = f0612_parent_instructions;
                     body.emit(f0612);

                     /* END IF */

                     body.emit(assign(r05F2, sub(r05F2, r05F6), 0x01));

                     ir_variable *const r0636 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r0636, r05F2, 0x01));

                     ir_variable *const r0637 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0637, r05F3, 0x01));

                     ir_variable *const r0638 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r0638, r05F4, 0x01));

                     ir_variable *const r0639 = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r0639, r05F5, 0x01));

                     ir_variable *const r063A = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r063A, body.constant(true), 0x01));

                     ir_variable *const r063B = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r063C = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r063C);
                     ir_expression *const r063D = expr(ir_unop_u2i, r05F5);
                     body.emit(assign(r063C, less(r063D, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r063F = gequal(r05F2, body.constant(int(2045)));
                     ir_if *f063E = new(mem_ctx) ir_if(operand(r063F).val);
                     exec_list *const f063E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f063E->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0641 = less(body.constant(int(2045)), r05F2);
                        ir_expression *const r0642 = equal(r05F2, body.constant(int(2045)));
                        ir_expression *const r0643 = equal(body.constant(2097151u), r05F3);
                        ir_expression *const r0644 = equal(body.constant(4294967295u), r05F4);
                        ir_expression *const r0645 = logic_and(r0643, r0644);
                        ir_expression *const r0646 = logic_and(r0642, r0645);
                        ir_expression *const r0647 = logic_and(r0646, r063C);
                        ir_expression *const r0648 = logic_or(r0641, r0647);
                        ir_if *f0640 = new(mem_ctx) ir_if(operand(r0648).val);
                        exec_list *const f0640_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0640->then_instructions;

                           ir_variable *const r0649 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0649);
                           ir_expression *const r064A = lshift(r01EE, body.constant(int(31)));
                           body.emit(assign(r0649, add(r064A, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r0649, body.constant(0u), 0x01));

                           body.emit(assign(r063B, r0649, 0x03));

                           body.emit(assign(r063A, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0640->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r064C = less(r05F2, body.constant(int(0)));
                           ir_if *f064B = new(mem_ctx) ir_if(operand(r064C).val);
                           exec_list *const f064B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f064B->then_instructions;

                              ir_variable *const r064D = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r064D, r05F5, 0x01));

                              ir_variable *const r064E = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r064E, neg(r05F2), 0x01));

                              ir_variable *const r064F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r064F);
                              ir_variable *const r0650 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0650);
                              ir_variable *const r0651 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0651);
                              ir_variable *const r0652 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0653 = neg(r064E);
                              body.emit(assign(r0652, bit_and(r0653, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0655 = equal(r064E, body.constant(int(0)));
                              ir_if *f0654 = new(mem_ctx) ir_if(operand(r0655).val);
                              exec_list *const f0654_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0654->then_instructions;

                                 body.emit(assign(r064F, r05F5, 0x01));

                                 body.emit(assign(r0650, r05F4, 0x01));

                                 body.emit(assign(r0651, r05F3, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0654->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0657 = less(r064E, body.constant(int(32)));
                                 ir_if *f0656 = new(mem_ctx) ir_if(operand(r0657).val);
                                 exec_list *const f0656_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0656->then_instructions;

                                    body.emit(assign(r064F, lshift(r05F4, r0652), 0x01));

                                    ir_expression *const r0658 = lshift(r05F3, r0652);
                                    ir_expression *const r0659 = rshift(r05F4, r064E);
                                    body.emit(assign(r0650, bit_or(r0658, r0659), 0x01));

                                    body.emit(assign(r0651, rshift(r05F3, r064E), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0656->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r065B = equal(r064E, body.constant(int(32)));
                                    ir_if *f065A = new(mem_ctx) ir_if(operand(r065B).val);
                                    exec_list *const f065A_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f065A->then_instructions;

                                       body.emit(assign(r064F, r05F4, 0x01));

                                       body.emit(assign(r0650, r05F3, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f065A->else_instructions;

                                       body.emit(assign(r064D, bit_or(r05F5, r05F4), 0x01));

                                       ir_expression *const r065C = less(r064E, body.constant(int(64)));
                                       ir_expression *const r065D = lshift(r05F3, r0652);
                                       ir_expression *const r065E = equal(r064E, body.constant(int(64)));
                                       ir_expression *const r065F = nequal(r05F3, body.constant(0u));
                                       ir_expression *const r0660 = expr(ir_unop_b2i, r065F);
                                       ir_expression *const r0661 = expr(ir_unop_i2u, r0660);
                                       ir_expression *const r0662 = expr(ir_triop_csel, r065E, r05F3, r0661);
                                       body.emit(assign(r064F, expr(ir_triop_csel, r065C, r065D, r0662), 0x01));

                                       ir_expression *const r0663 = less(r064E, body.constant(int(64)));
                                       ir_expression *const r0664 = bit_and(r064E, body.constant(int(31)));
                                       ir_expression *const r0665 = rshift(r05F3, r0664);
                                       body.emit(assign(r0650, expr(ir_triop_csel, r0663, r0665, body.constant(0u)), 0x01));


                                    body.instructions = f065A_parent_instructions;
                                    body.emit(f065A);

                                    /* END IF */

                                    body.emit(assign(r0651, body.constant(0u), 0x01));


                                 body.instructions = f0656_parent_instructions;
                                 body.emit(f0656);

                                 /* END IF */

                                 ir_expression *const r0666 = nequal(r064D, body.constant(0u));
                                 ir_expression *const r0667 = expr(ir_unop_b2i, r0666);
                                 ir_expression *const r0668 = expr(ir_unop_i2u, r0667);
                                 body.emit(assign(r064F, bit_or(r064F, r0668), 0x01));


                              body.instructions = f0654_parent_instructions;
                              body.emit(f0654);

                              /* END IF */

                              body.emit(assign(r0637, r0651, 0x01));

                              body.emit(assign(r0638, r0650, 0x01));

                              body.emit(assign(r0639, r064F, 0x01));

                              body.emit(assign(r0636, body.constant(int(0)), 0x01));

                              body.emit(assign(r063C, less(r064F, body.constant(0u)), 0x01));


                           body.instructions = f064B_parent_instructions;
                           body.emit(f064B);

                           /* END IF */


                        body.instructions = f0640_parent_instructions;
                        body.emit(f0640);

                        /* END IF */


                     body.instructions = f063E_parent_instructions;
                     body.emit(f063E);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0669 = new(mem_ctx) ir_if(operand(r063A).val);
                     exec_list *const f0669_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0669->then_instructions;

                        /* IF CONDITION */
                        ir_if *f066A = new(mem_ctx) ir_if(operand(r063C).val);
                        exec_list *const f066A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f066A->then_instructions;

                           ir_variable *const r066B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r066B, add(r0638, body.constant(1u)), 0x01));

                           ir_expression *const r066C = less(r066B, r0638);
                           ir_expression *const r066D = expr(ir_unop_b2i, r066C);
                           ir_expression *const r066E = expr(ir_unop_i2u, r066D);
                           body.emit(assign(r0637, add(r0637, r066E), 0x01));

                           ir_expression *const r066F = equal(r0639, body.constant(0u));
                           ir_expression *const r0670 = expr(ir_unop_b2i, r066F);
                           ir_expression *const r0671 = expr(ir_unop_i2u, r0670);
                           ir_expression *const r0672 = add(r0639, r0671);
                           ir_expression *const r0673 = bit_and(r0672, body.constant(1u));
                           ir_expression *const r0674 = expr(ir_unop_bit_not, r0673);
                           body.emit(assign(r0638, bit_and(r066B, r0674), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f066A->else_instructions;

                           ir_expression *const r0675 = bit_or(r0637, r0638);
                           ir_expression *const r0676 = equal(r0675, body.constant(0u));
                           body.emit(assign(r0636, expr(ir_triop_csel, r0676, body.constant(int(0)), r0636), 0x01));


                        body.instructions = f066A_parent_instructions;
                        body.emit(f066A);

                        /* END IF */

                        ir_variable *const r0677 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0677);
                        ir_expression *const r0678 = lshift(r01EE, body.constant(int(31)));
                        ir_expression *const r0679 = expr(ir_unop_i2u, r0636);
                        ir_expression *const r067A = lshift(r0679, body.constant(int(20)));
                        ir_expression *const r067B = add(r0678, r067A);
                        body.emit(assign(r0677, add(r067B, r0637), 0x02));

                        body.emit(assign(r0677, r0638, 0x01));

                        body.emit(assign(r063B, r0677, 0x03));

                        body.emit(assign(r063A, body.constant(false), 0x01));


                     body.instructions = f0669_parent_instructions;
                     body.emit(f0669);

                     /* END IF */

                     body.emit(assign(r01ED, r063B, 0x03));

                     body.emit(assign(r01EC, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05EB->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r067D = less(r0387, r0389);
                     ir_if *f067C = new(mem_ctx) ir_if(operand(r067D).val);
                     exec_list *const f067C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f067C->then_instructions;

                        ir_variable *const r067E = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_expression *const r067F = sub(r0388, r0386);
                        ir_expression *const r0680 = less(r0389, r0387);
                        ir_expression *const r0681 = expr(ir_unop_b2i, r0680);
                        ir_expression *const r0682 = expr(ir_unop_i2u, r0681);
                        body.emit(assign(r067E, sub(r067F, r0682), 0x01));

                        body.emit(assign(r038A, add(r0385, body.constant(int(-1))), 0x01));

                        ir_variable *const r0683 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0683, add(r038A, body.constant(int(-10))), 0x01));

                        ir_variable *const r0684 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        ir_variable *const r0685 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        ir_variable *const r0686 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0686);
                        ir_variable *const r0687 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0687);
                        ir_expression *const r0688 = equal(r067E, body.constant(0u));
                        ir_expression *const r0689 = add(r0683, body.constant(int(-32)));
                        body.emit(assign(r0683, expr(ir_triop_csel, r0688, r0689, r0683), 0x01));

                        ir_variable *const r068A = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r068B = equal(r067E, body.constant(0u));
                        ir_expression *const r068C = sub(r0389, r0387);
                        body.emit(assign(r068A, expr(ir_triop_csel, r068B, body.constant(0u), r068C), 0x01));

                        body.emit(assign(r0685, r068A, 0x01));

                        ir_variable *const r068D = body.make_temp(glsl_type::uint_type, "mix_retval");
                        ir_expression *const r068E = equal(r067E, body.constant(0u));
                        body.emit(assign(r068D, expr(ir_triop_csel, r068E, r068A, r067E), 0x01));

                        body.emit(assign(r0684, r068D, 0x01));

                        ir_variable *const r068F = body.make_temp(glsl_type::uint_type, "a");
                        body.emit(assign(r068F, r068D, 0x01));

                        ir_variable *const r0690 = body.make_temp(glsl_type::int_type, "return_value");
                        ir_variable *const r0691 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0691);
                        /* IF CONDITION */
                        ir_expression *const r0693 = equal(r068D, body.constant(0u));
                        ir_if *f0692 = new(mem_ctx) ir_if(operand(r0693).val);
                        exec_list *const f0692_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0692->then_instructions;

                           body.emit(assign(r0690, body.constant(int(32)), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0692->else_instructions;

                           body.emit(assign(r0691, body.constant(int(0)), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0695 = bit_and(r068D, body.constant(4294901760u));
                           ir_expression *const r0696 = equal(r0695, body.constant(0u));
                           ir_if *f0694 = new(mem_ctx) ir_if(operand(r0696).val);
                           exec_list *const f0694_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0694->then_instructions;

                              body.emit(assign(r0691, body.constant(int(16)), 0x01));

                              body.emit(assign(r068F, lshift(r068D, body.constant(int(16))), 0x01));


                           body.instructions = f0694_parent_instructions;
                           body.emit(f0694);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0698 = bit_and(r068F, body.constant(4278190080u));
                           ir_expression *const r0699 = equal(r0698, body.constant(0u));
                           ir_if *f0697 = new(mem_ctx) ir_if(operand(r0699).val);
                           exec_list *const f0697_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0697->then_instructions;

                              body.emit(assign(r0691, add(r0691, body.constant(int(8))), 0x01));

                              body.emit(assign(r068F, lshift(r068F, body.constant(int(8))), 0x01));


                           body.instructions = f0697_parent_instructions;
                           body.emit(f0697);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r069B = bit_and(r068F, body.constant(4026531840u));
                           ir_expression *const r069C = equal(r069B, body.constant(0u));
                           ir_if *f069A = new(mem_ctx) ir_if(operand(r069C).val);
                           exec_list *const f069A_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f069A->then_instructions;

                              body.emit(assign(r0691, add(r0691, body.constant(int(4))), 0x01));

                              body.emit(assign(r068F, lshift(r068F, body.constant(int(4))), 0x01));


                           body.instructions = f069A_parent_instructions;
                           body.emit(f069A);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r069E = bit_and(r068F, body.constant(3221225472u));
                           ir_expression *const r069F = equal(r069E, body.constant(0u));
                           ir_if *f069D = new(mem_ctx) ir_if(operand(r069F).val);
                           exec_list *const f069D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f069D->then_instructions;

                              body.emit(assign(r0691, add(r0691, body.constant(int(2))), 0x01));

                              body.emit(assign(r068F, lshift(r068F, body.constant(int(2))), 0x01));


                           body.instructions = f069D_parent_instructions;
                           body.emit(f069D);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r06A1 = bit_and(r068F, body.constant(2147483648u));
                           ir_expression *const r06A2 = equal(r06A1, body.constant(0u));
                           ir_if *f06A0 = new(mem_ctx) ir_if(operand(r06A2).val);
                           exec_list *const f06A0_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06A0->then_instructions;

                              body.emit(assign(r0691, add(r0691, body.constant(int(1))), 0x01));


                           body.instructions = f06A0_parent_instructions;
                           body.emit(f06A0);

                           /* END IF */

                           body.emit(assign(r0690, r0691, 0x01));


                        body.instructions = f0692_parent_instructions;
                        body.emit(f0692);

                        /* END IF */

                        body.emit(assign(r0687, add(r0690, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r06A4 = gequal(r0687, body.constant(int(0)));
                        ir_if *f06A3 = new(mem_ctx) ir_if(operand(r06A4).val);
                        exec_list *const f06A3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06A3->then_instructions;

                           body.emit(assign(r0686, body.constant(0u), 0x01));

                           ir_expression *const r06A5 = equal(r0687, body.constant(int(0)));
                           ir_expression *const r06A6 = lshift(r068D, r0687);
                           ir_expression *const r06A7 = neg(r0687);
                           ir_expression *const r06A8 = bit_and(r06A7, body.constant(int(31)));
                           ir_expression *const r06A9 = rshift(r068A, r06A8);
                           ir_expression *const r06AA = bit_or(r06A6, r06A9);
                           body.emit(assign(r0684, expr(ir_triop_csel, r06A5, r068D, r06AA), 0x01));

                           body.emit(assign(r0685, lshift(r068A, r0687), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06A3->else_instructions;

                           ir_variable *const r06AB = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r06AB, body.constant(0u), 0x01));

                           ir_variable *const r06AC = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r06AC, neg(r0687), 0x01));

                           ir_variable *const r06AD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r06AD);
                           ir_variable *const r06AE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r06AE);
                           ir_variable *const r06AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r06AF);
                           ir_variable *const r06B0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r06B1 = neg(r06AC);
                           body.emit(assign(r06B0, bit_and(r06B1, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06B3 = equal(r06AC, body.constant(int(0)));
                           ir_if *f06B2 = new(mem_ctx) ir_if(operand(r06B3).val);
                           exec_list *const f06B2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06B2->then_instructions;

                              body.emit(assign(r06AD, r06AB, 0x01));

                              body.emit(assign(r06AE, r0685, 0x01));

                              body.emit(assign(r06AF, r0684, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06B2->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06B5 = less(r06AC, body.constant(int(32)));
                              ir_if *f06B4 = new(mem_ctx) ir_if(operand(r06B5).val);
                              exec_list *const f06B4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06B4->then_instructions;

                                 body.emit(assign(r06AD, lshift(r0685, r06B0), 0x01));

                                 ir_expression *const r06B6 = lshift(r0684, r06B0);
                                 ir_expression *const r06B7 = rshift(r0685, r06AC);
                                 body.emit(assign(r06AE, bit_or(r06B6, r06B7), 0x01));

                                 body.emit(assign(r06AF, rshift(r0684, r06AC), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06B4->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06B9 = equal(r06AC, body.constant(int(32)));
                                 ir_if *f06B8 = new(mem_ctx) ir_if(operand(r06B9).val);
                                 exec_list *const f06B8_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06B8->then_instructions;

                                    body.emit(assign(r06AD, r0685, 0x01));

                                    body.emit(assign(r06AE, r0684, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06B8->else_instructions;

                                    body.emit(assign(r06AB, bit_or(body.constant(0u), r0685), 0x01));

                                    ir_expression *const r06BA = less(r06AC, body.constant(int(64)));
                                    ir_expression *const r06BB = lshift(r0684, r06B0);
                                    ir_expression *const r06BC = equal(r06AC, body.constant(int(64)));
                                    ir_expression *const r06BD = nequal(r0684, body.constant(0u));
                                    ir_expression *const r06BE = expr(ir_unop_b2i, r06BD);
                                    ir_expression *const r06BF = expr(ir_unop_i2u, r06BE);
                                    ir_expression *const r06C0 = expr(ir_triop_csel, r06BC, r0684, r06BF);
                                    body.emit(assign(r06AD, expr(ir_triop_csel, r06BA, r06BB, r06C0), 0x01));

                                    ir_expression *const r06C1 = less(r06AC, body.constant(int(64)));
                                    ir_expression *const r06C2 = bit_and(r06AC, body.constant(int(31)));
                                    ir_expression *const r06C3 = rshift(r0684, r06C2);
                                    body.emit(assign(r06AE, expr(ir_triop_csel, r06C1, r06C3, body.constant(0u)), 0x01));


                                 body.instructions = f06B8_parent_instructions;
                                 body.emit(f06B8);

                                 /* END IF */

                                 body.emit(assign(r06AF, body.constant(0u), 0x01));


                              body.instructions = f06B4_parent_instructions;
                              body.emit(f06B4);

                              /* END IF */

                              ir_expression *const r06C4 = nequal(r06AB, body.constant(0u));
                              ir_expression *const r06C5 = expr(ir_unop_b2i, r06C4);
                              ir_expression *const r06C6 = expr(ir_unop_i2u, r06C5);
                              body.emit(assign(r06AD, bit_or(r06AD, r06C6), 0x01));


                           body.instructions = f06B2_parent_instructions;
                           body.emit(f06B2);

                           /* END IF */

                           body.emit(assign(r0684, r06AF, 0x01));

                           body.emit(assign(r0685, r06AE, 0x01));

                           body.emit(assign(r0686, r06AD, 0x01));


                        body.instructions = f06A3_parent_instructions;
                        body.emit(f06A3);

                        /* END IF */

                        body.emit(assign(r0683, sub(r0683, r0687), 0x01));

                        ir_variable *const r06C7 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r06C7, r0683, 0x01));

                        ir_variable *const r06C8 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r06C8, r0684, 0x01));

                        ir_variable *const r06C9 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r06C9, r0685, 0x01));

                        ir_variable *const r06CA = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r06CA, r0686, 0x01));

                        ir_variable *const r06CB = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r06CB, body.constant(true), 0x01));

                        ir_variable *const r06CC = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r06CD = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r06CD);
                        ir_expression *const r06CE = expr(ir_unop_u2i, r0686);
                        body.emit(assign(r06CD, less(r06CE, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r06D0 = gequal(r0683, body.constant(int(2045)));
                        ir_if *f06CF = new(mem_ctx) ir_if(operand(r06D0).val);
                        exec_list *const f06CF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06CF->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r06D2 = less(body.constant(int(2045)), r0683);
                           ir_expression *const r06D3 = equal(r0683, body.constant(int(2045)));
                           ir_expression *const r06D4 = equal(body.constant(2097151u), r0684);
                           ir_expression *const r06D5 = equal(body.constant(4294967295u), r0685);
                           ir_expression *const r06D6 = logic_and(r06D4, r06D5);
                           ir_expression *const r06D7 = logic_and(r06D3, r06D6);
                           ir_expression *const r06D8 = logic_and(r06D7, r06CD);
                           ir_expression *const r06D9 = logic_or(r06D2, r06D8);
                           ir_if *f06D1 = new(mem_ctx) ir_if(operand(r06D9).val);
                           exec_list *const f06D1_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06D1->then_instructions;

                              ir_variable *const r06DA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r06DA);
                              ir_expression *const r06DB = lshift(r01EE, body.constant(int(31)));
                              body.emit(assign(r06DA, add(r06DB, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r06DA, body.constant(0u), 0x01));

                              body.emit(assign(r06CC, r06DA, 0x03));

                              body.emit(assign(r06CB, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06D1->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06DD = less(r0683, body.constant(int(0)));
                              ir_if *f06DC = new(mem_ctx) ir_if(operand(r06DD).val);
                              exec_list *const f06DC_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06DC->then_instructions;

                                 ir_variable *const r06DE = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r06DE, r0686, 0x01));

                                 ir_variable *const r06DF = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r06DF, neg(r0683), 0x01));

                                 ir_variable *const r06E0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r06E0);
                                 ir_variable *const r06E1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r06E1);
                                 ir_variable *const r06E2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r06E2);
                                 ir_variable *const r06E3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r06E4 = neg(r06DF);
                                 body.emit(assign(r06E3, bit_and(r06E4, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r06E6 = equal(r06DF, body.constant(int(0)));
                                 ir_if *f06E5 = new(mem_ctx) ir_if(operand(r06E6).val);
                                 exec_list *const f06E5_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06E5->then_instructions;

                                    body.emit(assign(r06E0, r0686, 0x01));

                                    body.emit(assign(r06E1, r0685, 0x01));

                                    body.emit(assign(r06E2, r0684, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06E5->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06E8 = less(r06DF, body.constant(int(32)));
                                    ir_if *f06E7 = new(mem_ctx) ir_if(operand(r06E8).val);
                                    exec_list *const f06E7_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06E7->then_instructions;

                                       body.emit(assign(r06E0, lshift(r0685, r06E3), 0x01));

                                       ir_expression *const r06E9 = lshift(r0684, r06E3);
                                       ir_expression *const r06EA = rshift(r0685, r06DF);
                                       body.emit(assign(r06E1, bit_or(r06E9, r06EA), 0x01));

                                       body.emit(assign(r06E2, rshift(r0684, r06DF), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06E7->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r06EC = equal(r06DF, body.constant(int(32)));
                                       ir_if *f06EB = new(mem_ctx) ir_if(operand(r06EC).val);
                                       exec_list *const f06EB_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06EB->then_instructions;

                                          body.emit(assign(r06E0, r0685, 0x01));

                                          body.emit(assign(r06E1, r0684, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06EB->else_instructions;

                                          body.emit(assign(r06DE, bit_or(r0686, r0685), 0x01));

                                          ir_expression *const r06ED = less(r06DF, body.constant(int(64)));
                                          ir_expression *const r06EE = lshift(r0684, r06E3);
                                          ir_expression *const r06EF = equal(r06DF, body.constant(int(64)));
                                          ir_expression *const r06F0 = nequal(r0684, body.constant(0u));
                                          ir_expression *const r06F1 = expr(ir_unop_b2i, r06F0);
                                          ir_expression *const r06F2 = expr(ir_unop_i2u, r06F1);
                                          ir_expression *const r06F3 = expr(ir_triop_csel, r06EF, r0684, r06F2);
                                          body.emit(assign(r06E0, expr(ir_triop_csel, r06ED, r06EE, r06F3), 0x01));

                                          ir_expression *const r06F4 = less(r06DF, body.constant(int(64)));
                                          ir_expression *const r06F5 = bit_and(r06DF, body.constant(int(31)));
                                          ir_expression *const r06F6 = rshift(r0684, r06F5);
                                          body.emit(assign(r06E1, expr(ir_triop_csel, r06F4, r06F6, body.constant(0u)), 0x01));


                                       body.instructions = f06EB_parent_instructions;
                                       body.emit(f06EB);

                                       /* END IF */

                                       body.emit(assign(r06E2, body.constant(0u), 0x01));


                                    body.instructions = f06E7_parent_instructions;
                                    body.emit(f06E7);

                                    /* END IF */

                                    ir_expression *const r06F7 = nequal(r06DE, body.constant(0u));
                                    ir_expression *const r06F8 = expr(ir_unop_b2i, r06F7);
                                    ir_expression *const r06F9 = expr(ir_unop_i2u, r06F8);
                                    body.emit(assign(r06E0, bit_or(r06E0, r06F9), 0x01));


                                 body.instructions = f06E5_parent_instructions;
                                 body.emit(f06E5);

                                 /* END IF */

                                 body.emit(assign(r06C8, r06E2, 0x01));

                                 body.emit(assign(r06C9, r06E1, 0x01));

                                 body.emit(assign(r06CA, r06E0, 0x01));

                                 body.emit(assign(r06C7, body.constant(int(0)), 0x01));

                                 body.emit(assign(r06CD, less(r06E0, body.constant(0u)), 0x01));


                              body.instructions = f06DC_parent_instructions;
                              body.emit(f06DC);

                              /* END IF */


                           body.instructions = f06D1_parent_instructions;
                           body.emit(f06D1);

                           /* END IF */


                        body.instructions = f06CF_parent_instructions;
                        body.emit(f06CF);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f06FA = new(mem_ctx) ir_if(operand(r06CB).val);
                        exec_list *const f06FA_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06FA->then_instructions;

                           /* IF CONDITION */
                           ir_if *f06FB = new(mem_ctx) ir_if(operand(r06CD).val);
                           exec_list *const f06FB_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06FB->then_instructions;

                              ir_variable *const r06FC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r06FC, add(r06C9, body.constant(1u)), 0x01));

                              ir_expression *const r06FD = less(r06FC, r06C9);
                              ir_expression *const r06FE = expr(ir_unop_b2i, r06FD);
                              ir_expression *const r06FF = expr(ir_unop_i2u, r06FE);
                              body.emit(assign(r06C8, add(r06C8, r06FF), 0x01));

                              ir_expression *const r0700 = equal(r06CA, body.constant(0u));
                              ir_expression *const r0701 = expr(ir_unop_b2i, r0700);
                              ir_expression *const r0702 = expr(ir_unop_i2u, r0701);
                              ir_expression *const r0703 = add(r06CA, r0702);
                              ir_expression *const r0704 = bit_and(r0703, body.constant(1u));
                              ir_expression *const r0705 = expr(ir_unop_bit_not, r0704);
                              body.emit(assign(r06C9, bit_and(r06FC, r0705), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06FB->else_instructions;

                              ir_expression *const r0706 = bit_or(r06C8, r06C9);
                              ir_expression *const r0707 = equal(r0706, body.constant(0u));
                              body.emit(assign(r06C7, expr(ir_triop_csel, r0707, body.constant(int(0)), r06C7), 0x01));


                           body.instructions = f06FB_parent_instructions;
                           body.emit(f06FB);

                           /* END IF */

                           ir_variable *const r0708 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0708);
                           ir_expression *const r0709 = lshift(r01EE, body.constant(int(31)));
                           ir_expression *const r070A = expr(ir_unop_i2u, r06C7);
                           ir_expression *const r070B = lshift(r070A, body.constant(int(20)));
                           ir_expression *const r070C = add(r0709, r070B);
                           body.emit(assign(r0708, add(r070C, r06C8), 0x02));

                           body.emit(assign(r0708, r06C9, 0x01));

                           body.emit(assign(r06CC, r0708, 0x03));

                           body.emit(assign(r06CB, body.constant(false), 0x01));


                        body.instructions = f06FA_parent_instructions;
                        body.emit(f06FA);

                        /* END IF */

                        body.emit(assign(r01ED, r06CC, 0x03));

                        body.emit(assign(r01EC, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f067C->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r070E = less(r0389, r0387);
                        ir_if *f070D = new(mem_ctx) ir_if(operand(r070E).val);
                        exec_list *const f070D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f070D->then_instructions;

                           ir_variable *const r070F = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_expression *const r0710 = sub(r0386, r0388);
                           ir_expression *const r0711 = less(r0387, r0389);
                           ir_expression *const r0712 = expr(ir_unop_b2i, r0711);
                           ir_expression *const r0713 = expr(ir_unop_i2u, r0712);
                           body.emit(assign(r070F, sub(r0710, r0713), 0x01));

                           body.emit(assign(r01EE, bit_xor(r01EE, body.constant(1u)), 0x01));

                           body.emit(assign(r038A, add(r0384, body.constant(int(-1))), 0x01));

                           ir_variable *const r0714 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r0714, add(r038A, body.constant(int(-10))), 0x01));

                           ir_variable *const r0715 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           ir_variable *const r0716 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           ir_variable *const r0717 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r0717);
                           ir_variable *const r0718 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r0718);
                           ir_expression *const r0719 = equal(r070F, body.constant(0u));
                           ir_expression *const r071A = add(r0714, body.constant(int(-32)));
                           body.emit(assign(r0714, expr(ir_triop_csel, r0719, r071A, r0714), 0x01));

                           ir_variable *const r071B = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r071C = equal(r070F, body.constant(0u));
                           ir_expression *const r071D = sub(r0387, r0389);
                           body.emit(assign(r071B, expr(ir_triop_csel, r071C, body.constant(0u), r071D), 0x01));

                           body.emit(assign(r0716, r071B, 0x01));

                           ir_variable *const r071E = body.make_temp(glsl_type::uint_type, "mix_retval");
                           ir_expression *const r071F = equal(r070F, body.constant(0u));
                           body.emit(assign(r071E, expr(ir_triop_csel, r071F, r071B, r070F), 0x01));

                           body.emit(assign(r0715, r071E, 0x01));

                           ir_variable *const r0720 = body.make_temp(glsl_type::uint_type, "a");
                           body.emit(assign(r0720, r071E, 0x01));

                           ir_variable *const r0721 = body.make_temp(glsl_type::int_type, "return_value");
                           ir_variable *const r0722 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r0722);
                           /* IF CONDITION */
                           ir_expression *const r0724 = equal(r071E, body.constant(0u));
                           ir_if *f0723 = new(mem_ctx) ir_if(operand(r0724).val);
                           exec_list *const f0723_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0723->then_instructions;

                              body.emit(assign(r0721, body.constant(int(32)), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0723->else_instructions;

                              body.emit(assign(r0722, body.constant(int(0)), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0726 = bit_and(r071E, body.constant(4294901760u));
                              ir_expression *const r0727 = equal(r0726, body.constant(0u));
                              ir_if *f0725 = new(mem_ctx) ir_if(operand(r0727).val);
                              exec_list *const f0725_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0725->then_instructions;

                                 body.emit(assign(r0722, body.constant(int(16)), 0x01));

                                 body.emit(assign(r0720, lshift(r071E, body.constant(int(16))), 0x01));


                              body.instructions = f0725_parent_instructions;
                              body.emit(f0725);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0729 = bit_and(r0720, body.constant(4278190080u));
                              ir_expression *const r072A = equal(r0729, body.constant(0u));
                              ir_if *f0728 = new(mem_ctx) ir_if(operand(r072A).val);
                              exec_list *const f0728_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0728->then_instructions;

                                 body.emit(assign(r0722, add(r0722, body.constant(int(8))), 0x01));

                                 body.emit(assign(r0720, lshift(r0720, body.constant(int(8))), 0x01));


                              body.instructions = f0728_parent_instructions;
                              body.emit(f0728);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r072C = bit_and(r0720, body.constant(4026531840u));
                              ir_expression *const r072D = equal(r072C, body.constant(0u));
                              ir_if *f072B = new(mem_ctx) ir_if(operand(r072D).val);
                              exec_list *const f072B_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f072B->then_instructions;

                                 body.emit(assign(r0722, add(r0722, body.constant(int(4))), 0x01));

                                 body.emit(assign(r0720, lshift(r0720, body.constant(int(4))), 0x01));


                              body.instructions = f072B_parent_instructions;
                              body.emit(f072B);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r072F = bit_and(r0720, body.constant(3221225472u));
                              ir_expression *const r0730 = equal(r072F, body.constant(0u));
                              ir_if *f072E = new(mem_ctx) ir_if(operand(r0730).val);
                              exec_list *const f072E_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f072E->then_instructions;

                                 body.emit(assign(r0722, add(r0722, body.constant(int(2))), 0x01));

                                 body.emit(assign(r0720, lshift(r0720, body.constant(int(2))), 0x01));


                              body.instructions = f072E_parent_instructions;
                              body.emit(f072E);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0732 = bit_and(r0720, body.constant(2147483648u));
                              ir_expression *const r0733 = equal(r0732, body.constant(0u));
                              ir_if *f0731 = new(mem_ctx) ir_if(operand(r0733).val);
                              exec_list *const f0731_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0731->then_instructions;

                                 body.emit(assign(r0722, add(r0722, body.constant(int(1))), 0x01));


                              body.instructions = f0731_parent_instructions;
                              body.emit(f0731);

                              /* END IF */

                              body.emit(assign(r0721, r0722, 0x01));


                           body.instructions = f0723_parent_instructions;
                           body.emit(f0723);

                           /* END IF */

                           body.emit(assign(r0718, add(r0721, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0735 = gequal(r0718, body.constant(int(0)));
                           ir_if *f0734 = new(mem_ctx) ir_if(operand(r0735).val);
                           exec_list *const f0734_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0734->then_instructions;

                              body.emit(assign(r0717, body.constant(0u), 0x01));

                              ir_expression *const r0736 = equal(r0718, body.constant(int(0)));
                              ir_expression *const r0737 = lshift(r071E, r0718);
                              ir_expression *const r0738 = neg(r0718);
                              ir_expression *const r0739 = bit_and(r0738, body.constant(int(31)));
                              ir_expression *const r073A = rshift(r071B, r0739);
                              ir_expression *const r073B = bit_or(r0737, r073A);
                              body.emit(assign(r0715, expr(ir_triop_csel, r0736, r071E, r073B), 0x01));

                              body.emit(assign(r0716, lshift(r071B, r0718), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0734->else_instructions;

                              ir_variable *const r073C = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r073C, body.constant(0u), 0x01));

                              ir_variable *const r073D = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r073D, neg(r0718), 0x01));

                              ir_variable *const r073E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r073E);
                              ir_variable *const r073F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r073F);
                              ir_variable *const r0740 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0740);
                              ir_variable *const r0741 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0742 = neg(r073D);
                              body.emit(assign(r0741, bit_and(r0742, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0744 = equal(r073D, body.constant(int(0)));
                              ir_if *f0743 = new(mem_ctx) ir_if(operand(r0744).val);
                              exec_list *const f0743_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0743->then_instructions;

                                 body.emit(assign(r073E, r073C, 0x01));

                                 body.emit(assign(r073F, r0716, 0x01));

                                 body.emit(assign(r0740, r0715, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0743->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0746 = less(r073D, body.constant(int(32)));
                                 ir_if *f0745 = new(mem_ctx) ir_if(operand(r0746).val);
                                 exec_list *const f0745_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0745->then_instructions;

                                    body.emit(assign(r073E, lshift(r0716, r0741), 0x01));

                                    ir_expression *const r0747 = lshift(r0715, r0741);
                                    ir_expression *const r0748 = rshift(r0716, r073D);
                                    body.emit(assign(r073F, bit_or(r0747, r0748), 0x01));

                                    body.emit(assign(r0740, rshift(r0715, r073D), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0745->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r074A = equal(r073D, body.constant(int(32)));
                                    ir_if *f0749 = new(mem_ctx) ir_if(operand(r074A).val);
                                    exec_list *const f0749_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0749->then_instructions;

                                       body.emit(assign(r073E, r0716, 0x01));

                                       body.emit(assign(r073F, r0715, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0749->else_instructions;

                                       body.emit(assign(r073C, bit_or(body.constant(0u), r0716), 0x01));

                                       ir_expression *const r074B = less(r073D, body.constant(int(64)));
                                       ir_expression *const r074C = lshift(r0715, r0741);
                                       ir_expression *const r074D = equal(r073D, body.constant(int(64)));
                                       ir_expression *const r074E = nequal(r0715, body.constant(0u));
                                       ir_expression *const r074F = expr(ir_unop_b2i, r074E);
                                       ir_expression *const r0750 = expr(ir_unop_i2u, r074F);
                                       ir_expression *const r0751 = expr(ir_triop_csel, r074D, r0715, r0750);
                                       body.emit(assign(r073E, expr(ir_triop_csel, r074B, r074C, r0751), 0x01));

                                       ir_expression *const r0752 = less(r073D, body.constant(int(64)));
                                       ir_expression *const r0753 = bit_and(r073D, body.constant(int(31)));
                                       ir_expression *const r0754 = rshift(r0715, r0753);
                                       body.emit(assign(r073F, expr(ir_triop_csel, r0752, r0754, body.constant(0u)), 0x01));


                                    body.instructions = f0749_parent_instructions;
                                    body.emit(f0749);

                                    /* END IF */

                                    body.emit(assign(r0740, body.constant(0u), 0x01));


                                 body.instructions = f0745_parent_instructions;
                                 body.emit(f0745);

                                 /* END IF */

                                 ir_expression *const r0755 = nequal(r073C, body.constant(0u));
                                 ir_expression *const r0756 = expr(ir_unop_b2i, r0755);
                                 ir_expression *const r0757 = expr(ir_unop_i2u, r0756);
                                 body.emit(assign(r073E, bit_or(r073E, r0757), 0x01));


                              body.instructions = f0743_parent_instructions;
                              body.emit(f0743);

                              /* END IF */

                              body.emit(assign(r0715, r0740, 0x01));

                              body.emit(assign(r0716, r073F, 0x01));

                              body.emit(assign(r0717, r073E, 0x01));


                           body.instructions = f0734_parent_instructions;
                           body.emit(f0734);

                           /* END IF */

                           body.emit(assign(r0714, sub(r0714, r0718), 0x01));

                           ir_variable *const r0758 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r0758, r0714, 0x01));

                           ir_variable *const r0759 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r0759, r0715, 0x01));

                           ir_variable *const r075A = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r075A, r0716, 0x01));

                           ir_variable *const r075B = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r075B, r0717, 0x01));

                           ir_variable *const r075C = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r075C, body.constant(true), 0x01));

                           ir_variable *const r075D = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r075E = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r075E);
                           ir_expression *const r075F = expr(ir_unop_u2i, r0717);
                           body.emit(assign(r075E, less(r075F, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0761 = gequal(r0714, body.constant(int(2045)));
                           ir_if *f0760 = new(mem_ctx) ir_if(operand(r0761).val);
                           exec_list *const f0760_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0760->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0763 = less(body.constant(int(2045)), r0714);
                              ir_expression *const r0764 = equal(r0714, body.constant(int(2045)));
                              ir_expression *const r0765 = equal(body.constant(2097151u), r0715);
                              ir_expression *const r0766 = equal(body.constant(4294967295u), r0716);
                              ir_expression *const r0767 = logic_and(r0765, r0766);
                              ir_expression *const r0768 = logic_and(r0764, r0767);
                              ir_expression *const r0769 = logic_and(r0768, r075E);
                              ir_expression *const r076A = logic_or(r0763, r0769);
                              ir_if *f0762 = new(mem_ctx) ir_if(operand(r076A).val);
                              exec_list *const f0762_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0762->then_instructions;

                                 ir_variable *const r076B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r076B);
                                 ir_expression *const r076C = lshift(r01EE, body.constant(int(31)));
                                 body.emit(assign(r076B, add(r076C, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r076B, body.constant(0u), 0x01));

                                 body.emit(assign(r075D, r076B, 0x03));

                                 body.emit(assign(r075C, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0762->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r076E = less(r0714, body.constant(int(0)));
                                 ir_if *f076D = new(mem_ctx) ir_if(operand(r076E).val);
                                 exec_list *const f076D_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f076D->then_instructions;

                                    ir_variable *const r076F = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r076F, r0717, 0x01));

                                    ir_variable *const r0770 = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r0770, neg(r0714), 0x01));

                                    ir_variable *const r0771 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r0771);
                                    ir_variable *const r0772 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r0772);
                                    ir_variable *const r0773 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r0773);
                                    ir_variable *const r0774 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r0775 = neg(r0770);
                                    body.emit(assign(r0774, bit_and(r0775, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0777 = equal(r0770, body.constant(int(0)));
                                    ir_if *f0776 = new(mem_ctx) ir_if(operand(r0777).val);
                                    exec_list *const f0776_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0776->then_instructions;

                                       body.emit(assign(r0771, r0717, 0x01));

                                       body.emit(assign(r0772, r0716, 0x01));

                                       body.emit(assign(r0773, r0715, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0776->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r0779 = less(r0770, body.constant(int(32)));
                                       ir_if *f0778 = new(mem_ctx) ir_if(operand(r0779).val);
                                       exec_list *const f0778_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0778->then_instructions;

                                          body.emit(assign(r0771, lshift(r0716, r0774), 0x01));

                                          ir_expression *const r077A = lshift(r0715, r0774);
                                          ir_expression *const r077B = rshift(r0716, r0770);
                                          body.emit(assign(r0772, bit_or(r077A, r077B), 0x01));

                                          body.emit(assign(r0773, rshift(r0715, r0770), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0778->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r077D = equal(r0770, body.constant(int(32)));
                                          ir_if *f077C = new(mem_ctx) ir_if(operand(r077D).val);
                                          exec_list *const f077C_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f077C->then_instructions;

                                             body.emit(assign(r0771, r0716, 0x01));

                                             body.emit(assign(r0772, r0715, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f077C->else_instructions;

                                             body.emit(assign(r076F, bit_or(r0717, r0716), 0x01));

                                             ir_expression *const r077E = less(r0770, body.constant(int(64)));
                                             ir_expression *const r077F = lshift(r0715, r0774);
                                             ir_expression *const r0780 = equal(r0770, body.constant(int(64)));
                                             ir_expression *const r0781 = nequal(r0715, body.constant(0u));
                                             ir_expression *const r0782 = expr(ir_unop_b2i, r0781);
                                             ir_expression *const r0783 = expr(ir_unop_i2u, r0782);
                                             ir_expression *const r0784 = expr(ir_triop_csel, r0780, r0715, r0783);
                                             body.emit(assign(r0771, expr(ir_triop_csel, r077E, r077F, r0784), 0x01));

                                             ir_expression *const r0785 = less(r0770, body.constant(int(64)));
                                             ir_expression *const r0786 = bit_and(r0770, body.constant(int(31)));
                                             ir_expression *const r0787 = rshift(r0715, r0786);
                                             body.emit(assign(r0772, expr(ir_triop_csel, r0785, r0787, body.constant(0u)), 0x01));


                                          body.instructions = f077C_parent_instructions;
                                          body.emit(f077C);

                                          /* END IF */

                                          body.emit(assign(r0773, body.constant(0u), 0x01));


                                       body.instructions = f0778_parent_instructions;
                                       body.emit(f0778);

                                       /* END IF */

                                       ir_expression *const r0788 = nequal(r076F, body.constant(0u));
                                       ir_expression *const r0789 = expr(ir_unop_b2i, r0788);
                                       ir_expression *const r078A = expr(ir_unop_i2u, r0789);
                                       body.emit(assign(r0771, bit_or(r0771, r078A), 0x01));


                                    body.instructions = f0776_parent_instructions;
                                    body.emit(f0776);

                                    /* END IF */

                                    body.emit(assign(r0759, r0773, 0x01));

                                    body.emit(assign(r075A, r0772, 0x01));

                                    body.emit(assign(r075B, r0771, 0x01));

                                    body.emit(assign(r0758, body.constant(int(0)), 0x01));

                                    body.emit(assign(r075E, less(r0771, body.constant(0u)), 0x01));


                                 body.instructions = f076D_parent_instructions;
                                 body.emit(f076D);

                                 /* END IF */


                              body.instructions = f0762_parent_instructions;
                              body.emit(f0762);

                              /* END IF */


                           body.instructions = f0760_parent_instructions;
                           body.emit(f0760);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f078B = new(mem_ctx) ir_if(operand(r075C).val);
                           exec_list *const f078B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f078B->then_instructions;

                              /* IF CONDITION */
                              ir_if *f078C = new(mem_ctx) ir_if(operand(r075E).val);
                              exec_list *const f078C_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f078C->then_instructions;

                                 ir_variable *const r078D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r078D, add(r075A, body.constant(1u)), 0x01));

                                 ir_expression *const r078E = less(r078D, r075A);
                                 ir_expression *const r078F = expr(ir_unop_b2i, r078E);
                                 ir_expression *const r0790 = expr(ir_unop_i2u, r078F);
                                 body.emit(assign(r0759, add(r0759, r0790), 0x01));

                                 ir_expression *const r0791 = equal(r075B, body.constant(0u));
                                 ir_expression *const r0792 = expr(ir_unop_b2i, r0791);
                                 ir_expression *const r0793 = expr(ir_unop_i2u, r0792);
                                 ir_expression *const r0794 = add(r075B, r0793);
                                 ir_expression *const r0795 = bit_and(r0794, body.constant(1u));
                                 ir_expression *const r0796 = expr(ir_unop_bit_not, r0795);
                                 body.emit(assign(r075A, bit_and(r078D, r0796), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f078C->else_instructions;

                                 ir_expression *const r0797 = bit_or(r0759, r075A);
                                 ir_expression *const r0798 = equal(r0797, body.constant(0u));
                                 body.emit(assign(r0758, expr(ir_triop_csel, r0798, body.constant(int(0)), r0758), 0x01));


                              body.instructions = f078C_parent_instructions;
                              body.emit(f078C);

                              /* END IF */

                              ir_variable *const r0799 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0799);
                              ir_expression *const r079A = lshift(r01EE, body.constant(int(31)));
                              ir_expression *const r079B = expr(ir_unop_i2u, r0758);
                              ir_expression *const r079C = lshift(r079B, body.constant(int(20)));
                              ir_expression *const r079D = add(r079A, r079C);
                              body.emit(assign(r0799, add(r079D, r0759), 0x02));

                              body.emit(assign(r0799, r075A, 0x01));

                              body.emit(assign(r075D, r0799, 0x03));

                              body.emit(assign(r075C, body.constant(false), 0x01));


                           body.instructions = f078B_parent_instructions;
                           body.emit(f078B);

                           /* END IF */

                           body.emit(assign(r01ED, r075D, 0x03));

                           body.emit(assign(r01EC, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f070D->else_instructions;

                           ir_variable *const r079E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r079E);
                           body.emit(assign(r079E, body.constant(0u), 0x02));

                           body.emit(assign(r079E, body.constant(0u), 0x01));

                           body.emit(assign(r01ED, r079E, 0x03));

                           body.emit(assign(r01EC, body.constant(false), 0x01));


                        body.instructions = f070D_parent_instructions;
                        body.emit(f070D);

                        /* END IF */


                     body.instructions = f067C_parent_instructions;
                     body.emit(f067C);

                     /* END IF */


                  body.instructions = f05EB_parent_instructions;
                  body.emit(f05EB);

                  /* END IF */


               body.instructions = f055A_parent_instructions;
               body.emit(f055A);

               /* END IF */


            body.instructions = f053D_parent_instructions;
            body.emit(f053D);

            /* END IF */


         body.instructions = f046A_parent_instructions;
         body.emit(f046A);

         /* END IF */


      body.instructions = f039B_parent_instructions;
      body.emit(f039B);

      /* END IF */


   body.instructions = f01F1_parent_instructions;
   body.emit(f01F1);

   /* END IF */

   body.emit(ret(r01ED));

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

   ir_variable *const r079F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r079F);
   ir_variable *const r07A0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r07A0);
   ir_variable *const r07A1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07A1);
   ir_variable *const r07A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07A2);
   ir_variable *const r07A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07A3);
   ir_variable *const r07A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07A4);
   ir_variable *const r07A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07A5);
   ir_variable *const r07A6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A6, bit_and(r079F, body.constant(65535u)), 0x01));

   ir_variable *const r07A7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A7, rshift(r079F, body.constant(int(16))), 0x01));

   ir_variable *const r07A8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A8, bit_and(r07A0, body.constant(65535u)), 0x01));

   ir_variable *const r07A9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A9, rshift(r07A0, body.constant(int(16))), 0x01));

   ir_variable *const r07AA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07AA, mul(r07A7, r07A8), 0x01));

   ir_expression *const r07AB = mul(r07A6, r07A9);
   body.emit(assign(r07A4, add(r07AB, r07AA), 0x01));

   ir_expression *const r07AC = mul(r07A7, r07A9);
   ir_expression *const r07AD = less(r07A4, r07AA);
   ir_expression *const r07AE = expr(ir_unop_b2i, r07AD);
   ir_expression *const r07AF = expr(ir_unop_i2u, r07AE);
   ir_expression *const r07B0 = lshift(r07AF, body.constant(int(16)));
   ir_expression *const r07B1 = rshift(r07A4, body.constant(int(16)));
   ir_expression *const r07B2 = add(r07B0, r07B1);
   body.emit(assign(r07A3, add(r07AC, r07B2), 0x01));

   body.emit(assign(r07A4, lshift(r07A4, body.constant(int(16))), 0x01));

   ir_expression *const r07B3 = mul(r07A6, r07A8);
   body.emit(assign(r07A5, add(r07B3, r07A4), 0x01));

   ir_expression *const r07B4 = less(r07A5, r07A4);
   ir_expression *const r07B5 = expr(ir_unop_b2i, r07B4);
   ir_expression *const r07B6 = expr(ir_unop_i2u, r07B5);
   body.emit(assign(r07A3, add(r07A3, r07B6), 0x01));

   body.emit(assign(r07A2, r07A5, 0x01));

   body.emit(assign(r07A1, r07A3, 0x01));

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

   ir_variable *const r07B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r07B7);
   ir_variable *const r07B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r07B8);
   ir_variable *const r07B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r07B9);
   ir_variable *const r07BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r07BA);
   ir_variable *const r07BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07BB);
   ir_variable *const r07BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07BC);
   ir_variable *const r07BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07BD);
   ir_variable *const r07BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07BE);
   ir_variable *const r07BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07BF);
   ir_variable *const r07C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07C0);
   ir_variable *const r07C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07C1);
   ir_variable *const r07C2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C2, bit_and(r07B8, body.constant(65535u)), 0x01));

   ir_variable *const r07C3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C3, rshift(r07B8, body.constant(int(16))), 0x01));

   ir_variable *const r07C4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C4, bit_and(r07BA, body.constant(65535u)), 0x01));

   ir_variable *const r07C5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C5, rshift(r07BA, body.constant(int(16))), 0x01));

   ir_variable *const r07C6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C6, mul(r07C3, r07C4), 0x01));

   ir_expression *const r07C7 = mul(r07C2, r07C5);
   body.emit(assign(r07C0, add(r07C7, r07C6), 0x01));

   ir_expression *const r07C8 = mul(r07C3, r07C5);
   ir_expression *const r07C9 = less(r07C0, r07C6);
   ir_expression *const r07CA = expr(ir_unop_b2i, r07C9);
   ir_expression *const r07CB = expr(ir_unop_i2u, r07CA);
   ir_expression *const r07CC = lshift(r07CB, body.constant(int(16)));
   ir_expression *const r07CD = rshift(r07C0, body.constant(int(16)));
   ir_expression *const r07CE = add(r07CC, r07CD);
   body.emit(assign(r07BF, add(r07C8, r07CE), 0x01));

   body.emit(assign(r07C0, lshift(r07C0, body.constant(int(16))), 0x01));

   ir_expression *const r07CF = mul(r07C2, r07C4);
   body.emit(assign(r07C1, add(r07CF, r07C0), 0x01));

   ir_expression *const r07D0 = less(r07C1, r07C0);
   ir_expression *const r07D1 = expr(ir_unop_b2i, r07D0);
   ir_expression *const r07D2 = expr(ir_unop_i2u, r07D1);
   body.emit(assign(r07BF, add(r07BF, r07D2), 0x01));

   ir_variable *const r07D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07D3);
   ir_variable *const r07D4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07D4);
   ir_variable *const r07D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07D5);
   ir_variable *const r07D6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D6, bit_and(r07B8, body.constant(65535u)), 0x01));

   ir_variable *const r07D7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D7, rshift(r07B8, body.constant(int(16))), 0x01));

   ir_variable *const r07D8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D8, bit_and(r07B9, body.constant(65535u)), 0x01));

   ir_variable *const r07D9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D9, rshift(r07B9, body.constant(int(16))), 0x01));

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
   body.emit(assign(r07E7, add(r07D5, r07BF), 0x01));

   ir_variable *const r07E8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07E8);
   ir_variable *const r07E9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07E9);
   ir_variable *const r07EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07EA);
   ir_variable *const r07EB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EB, bit_and(r07B7, body.constant(65535u)), 0x01));

   ir_variable *const r07EC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EC, rshift(r07B7, body.constant(int(16))), 0x01));

   ir_variable *const r07ED = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07ED, bit_and(r07B9, body.constant(65535u)), 0x01));

   ir_variable *const r07EE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EE, rshift(r07B9, body.constant(int(16))), 0x01));

   ir_variable *const r07EF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EF, mul(r07EC, r07ED), 0x01));

   ir_expression *const r07F0 = mul(r07EB, r07EE);
   body.emit(assign(r07E9, add(r07F0, r07EF), 0x01));

   ir_expression *const r07F1 = mul(r07EC, r07EE);
   ir_expression *const r07F2 = less(r07E9, r07EF);
   ir_expression *const r07F3 = expr(ir_unop_b2i, r07F2);
   ir_expression *const r07F4 = expr(ir_unop_i2u, r07F3);
   ir_expression *const r07F5 = lshift(r07F4, body.constant(int(16)));
   ir_expression *const r07F6 = rshift(r07E9, body.constant(int(16)));
   ir_expression *const r07F7 = add(r07F5, r07F6);
   body.emit(assign(r07E8, add(r07F1, r07F7), 0x01));

   body.emit(assign(r07E9, lshift(r07E9, body.constant(int(16))), 0x01));

   ir_expression *const r07F8 = mul(r07EB, r07ED);
   body.emit(assign(r07EA, add(r07F8, r07E9), 0x01));

   ir_expression *const r07F9 = less(r07EA, r07E9);
   ir_expression *const r07FA = expr(ir_unop_b2i, r07F9);
   ir_expression *const r07FB = expr(ir_unop_i2u, r07FA);
   body.emit(assign(r07E8, add(r07E8, r07FB), 0x01));

   ir_variable *const r07FC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r07FD = less(r07E7, r07D5);
   ir_expression *const r07FE = expr(ir_unop_b2i, r07FD);
   ir_expression *const r07FF = expr(ir_unop_i2u, r07FE);
   ir_expression *const r0800 = add(r07D3, r07FF);
   body.emit(assign(r07FC, add(r07EA, r0800), 0x01));

   ir_variable *const r0801 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0801);
   ir_variable *const r0802 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0802);
   ir_variable *const r0803 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0803);
   ir_variable *const r0804 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0804, bit_and(r07B7, body.constant(65535u)), 0x01));

   ir_variable *const r0805 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0805, rshift(r07B7, body.constant(int(16))), 0x01));

   ir_variable *const r0806 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0806, bit_and(r07BA, body.constant(65535u)), 0x01));

   ir_variable *const r0807 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0807, rshift(r07BA, body.constant(int(16))), 0x01));

   ir_variable *const r0808 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0808, mul(r0805, r0806), 0x01));

   ir_expression *const r0809 = mul(r0804, r0807);
   body.emit(assign(r0802, add(r0809, r0808), 0x01));

   ir_expression *const r080A = mul(r0805, r0807);
   ir_expression *const r080B = less(r0802, r0808);
   ir_expression *const r080C = expr(ir_unop_b2i, r080B);
   ir_expression *const r080D = expr(ir_unop_i2u, r080C);
   ir_expression *const r080E = lshift(r080D, body.constant(int(16)));
   ir_expression *const r080F = rshift(r0802, body.constant(int(16)));
   ir_expression *const r0810 = add(r080E, r080F);
   body.emit(assign(r0801, add(r080A, r0810), 0x01));

   body.emit(assign(r0802, lshift(r0802, body.constant(int(16))), 0x01));

   ir_expression *const r0811 = mul(r0804, r0806);
   body.emit(assign(r0803, add(r0811, r0802), 0x01));

   ir_expression *const r0812 = less(r0803, r0802);
   ir_expression *const r0813 = expr(ir_unop_b2i, r0812);
   ir_expression *const r0814 = expr(ir_unop_i2u, r0813);
   body.emit(assign(r0801, add(r0801, r0814), 0x01));

   ir_variable *const r0815 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0815, add(r0803, r07E7), 0x01));

   ir_variable *const r0816 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0817 = less(r0815, r0803);
   ir_expression *const r0818 = expr(ir_unop_b2i, r0817);
   ir_expression *const r0819 = expr(ir_unop_i2u, r0818);
   ir_expression *const r081A = add(r0801, r0819);
   body.emit(assign(r0816, add(r07FC, r081A), 0x01));

   body.emit(assign(r07BE, r07C1, 0x01));

   body.emit(assign(r07BD, r0815, 0x01));

   body.emit(assign(r07BC, r0816, 0x01));

   ir_expression *const r081B = less(r07FC, r07EA);
   ir_expression *const r081C = expr(ir_unop_b2i, r081B);
   ir_expression *const r081D = expr(ir_unop_i2u, r081C);
   ir_expression *const r081E = add(r07E8, r081D);
   ir_expression *const r081F = less(r0816, r07FC);
   ir_expression *const r0820 = expr(ir_unop_b2i, r081F);
   ir_expression *const r0821 = expr(ir_unop_i2u, r0820);
   body.emit(assign(r07BB, add(r081E, r0821), 0x01));

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

   ir_variable *const r0822 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0822);
   ir_variable *const r0823 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0823);
   ir_variable *const r0824 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r0824);
   ir_variable *const r0825 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0825);
   ir_variable *const r0826 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0826);
   ir_variable *const r0827 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0827);
   /* IF CONDITION */
   ir_expression *const r0829 = equal(r0822, body.constant(0u));
   ir_if *f0828 = new(mem_ctx) ir_if(operand(r0829).val);
   exec_list *const f0828_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0828->then_instructions;

      ir_variable *const r082A = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r082A, r0823, 0x01));

      ir_variable *const r082B = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r082C = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r082C);
      /* IF CONDITION */
      ir_expression *const r082E = equal(r0823, body.constant(0u));
      ir_if *f082D = new(mem_ctx) ir_if(operand(r082E).val);
      exec_list *const f082D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f082D->then_instructions;

         body.emit(assign(r082B, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f082D->else_instructions;

         body.emit(assign(r082C, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0830 = bit_and(r0823, body.constant(4294901760u));
         ir_expression *const r0831 = equal(r0830, body.constant(0u));
         ir_if *f082F = new(mem_ctx) ir_if(operand(r0831).val);
         exec_list *const f082F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f082F->then_instructions;

            body.emit(assign(r082C, body.constant(int(16)), 0x01));

            body.emit(assign(r082A, lshift(r0823, body.constant(int(16))), 0x01));


         body.instructions = f082F_parent_instructions;
         body.emit(f082F);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0833 = bit_and(r082A, body.constant(4278190080u));
         ir_expression *const r0834 = equal(r0833, body.constant(0u));
         ir_if *f0832 = new(mem_ctx) ir_if(operand(r0834).val);
         exec_list *const f0832_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0832->then_instructions;

            body.emit(assign(r082C, add(r082C, body.constant(int(8))), 0x01));

            body.emit(assign(r082A, lshift(r082A, body.constant(int(8))), 0x01));


         body.instructions = f0832_parent_instructions;
         body.emit(f0832);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0836 = bit_and(r082A, body.constant(4026531840u));
         ir_expression *const r0837 = equal(r0836, body.constant(0u));
         ir_if *f0835 = new(mem_ctx) ir_if(operand(r0837).val);
         exec_list *const f0835_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0835->then_instructions;

            body.emit(assign(r082C, add(r082C, body.constant(int(4))), 0x01));

            body.emit(assign(r082A, lshift(r082A, body.constant(int(4))), 0x01));


         body.instructions = f0835_parent_instructions;
         body.emit(f0835);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0839 = bit_and(r082A, body.constant(3221225472u));
         ir_expression *const r083A = equal(r0839, body.constant(0u));
         ir_if *f0838 = new(mem_ctx) ir_if(operand(r083A).val);
         exec_list *const f0838_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0838->then_instructions;

            body.emit(assign(r082C, add(r082C, body.constant(int(2))), 0x01));

            body.emit(assign(r082A, lshift(r082A, body.constant(int(2))), 0x01));


         body.instructions = f0838_parent_instructions;
         body.emit(f0838);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r083C = bit_and(r082A, body.constant(2147483648u));
         ir_expression *const r083D = equal(r083C, body.constant(0u));
         ir_if *f083B = new(mem_ctx) ir_if(operand(r083D).val);
         exec_list *const f083B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f083B->then_instructions;

            body.emit(assign(r082C, add(r082C, body.constant(int(1))), 0x01));


         body.instructions = f083B_parent_instructions;
         body.emit(f083B);

         /* END IF */

         body.emit(assign(r082B, r082C, 0x01));


      body.instructions = f082D_parent_instructions;
      body.emit(f082D);

      /* END IF */

      body.emit(assign(r0827, add(r082B, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r083F = less(r0827, body.constant(int(0)));
      ir_if *f083E = new(mem_ctx) ir_if(operand(r083F).val);
      exec_list *const f083E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f083E->then_instructions;

         ir_expression *const r0840 = neg(r0827);
         body.emit(assign(r0825, rshift(r0823, r0840), 0x01));

         ir_expression *const r0841 = bit_and(r0827, body.constant(int(31)));
         body.emit(assign(r0826, lshift(r0823, r0841), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f083E->else_instructions;

         body.emit(assign(r0825, lshift(r0823, r0827), 0x01));

         body.emit(assign(r0826, body.constant(0u), 0x01));


      body.instructions = f083E_parent_instructions;
      body.emit(f083E);

      /* END IF */

      body.emit(assign(r0824, sub(body.constant(int(-31)), r0827), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0828->else_instructions;

      ir_variable *const r0842 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0842, r0822, 0x01));

      ir_variable *const r0843 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0844 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0844);
      /* IF CONDITION */
      ir_expression *const r0846 = equal(r0822, body.constant(0u));
      ir_if *f0845 = new(mem_ctx) ir_if(operand(r0846).val);
      exec_list *const f0845_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0845->then_instructions;

         body.emit(assign(r0843, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0845->else_instructions;

         body.emit(assign(r0844, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0848 = bit_and(r0822, body.constant(4294901760u));
         ir_expression *const r0849 = equal(r0848, body.constant(0u));
         ir_if *f0847 = new(mem_ctx) ir_if(operand(r0849).val);
         exec_list *const f0847_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0847->then_instructions;

            body.emit(assign(r0844, body.constant(int(16)), 0x01));

            body.emit(assign(r0842, lshift(r0822, body.constant(int(16))), 0x01));


         body.instructions = f0847_parent_instructions;
         body.emit(f0847);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r084B = bit_and(r0842, body.constant(4278190080u));
         ir_expression *const r084C = equal(r084B, body.constant(0u));
         ir_if *f084A = new(mem_ctx) ir_if(operand(r084C).val);
         exec_list *const f084A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f084A->then_instructions;

            body.emit(assign(r0844, add(r0844, body.constant(int(8))), 0x01));

            body.emit(assign(r0842, lshift(r0842, body.constant(int(8))), 0x01));


         body.instructions = f084A_parent_instructions;
         body.emit(f084A);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r084E = bit_and(r0842, body.constant(4026531840u));
         ir_expression *const r084F = equal(r084E, body.constant(0u));
         ir_if *f084D = new(mem_ctx) ir_if(operand(r084F).val);
         exec_list *const f084D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f084D->then_instructions;

            body.emit(assign(r0844, add(r0844, body.constant(int(4))), 0x01));

            body.emit(assign(r0842, lshift(r0842, body.constant(int(4))), 0x01));


         body.instructions = f084D_parent_instructions;
         body.emit(f084D);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0851 = bit_and(r0842, body.constant(3221225472u));
         ir_expression *const r0852 = equal(r0851, body.constant(0u));
         ir_if *f0850 = new(mem_ctx) ir_if(operand(r0852).val);
         exec_list *const f0850_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0850->then_instructions;

            body.emit(assign(r0844, add(r0844, body.constant(int(2))), 0x01));

            body.emit(assign(r0842, lshift(r0842, body.constant(int(2))), 0x01));


         body.instructions = f0850_parent_instructions;
         body.emit(f0850);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0854 = bit_and(r0842, body.constant(2147483648u));
         ir_expression *const r0855 = equal(r0854, body.constant(0u));
         ir_if *f0853 = new(mem_ctx) ir_if(operand(r0855).val);
         exec_list *const f0853_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0853->then_instructions;

            body.emit(assign(r0844, add(r0844, body.constant(int(1))), 0x01));


         body.instructions = f0853_parent_instructions;
         body.emit(f0853);

         /* END IF */

         body.emit(assign(r0843, r0844, 0x01));


      body.instructions = f0845_parent_instructions;
      body.emit(f0845);

      /* END IF */

      body.emit(assign(r0827, add(r0843, body.constant(int(-11))), 0x01));

      ir_expression *const r0856 = equal(r0827, body.constant(int(0)));
      ir_expression *const r0857 = lshift(r0822, r0827);
      ir_expression *const r0858 = neg(r0827);
      ir_expression *const r0859 = bit_and(r0858, body.constant(int(31)));
      ir_expression *const r085A = rshift(r0823, r0859);
      ir_expression *const r085B = bit_or(r0857, r085A);
      body.emit(assign(r0825, expr(ir_triop_csel, r0856, r0822, r085B), 0x01));

      body.emit(assign(r0826, lshift(r0823, r0827), 0x01));

      body.emit(assign(r0824, sub(body.constant(int(1)), r0827), 0x01));


   body.instructions = f0828_parent_instructions;
   body.emit(f0828);

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

   ir_variable *const r085C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r085C);
   ir_variable *const r085D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r085D);
   ir_variable *const r085E = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r085E, body.constant(true), 0x01));

   ir_variable *const r085F = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0860 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0860);
   ir_variable *const r0861 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r0861);
   ir_variable *const r0862 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0862);
   ir_variable *const r0863 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r0863);
   ir_variable *const r0864 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r0864);
   ir_variable *const r0865 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0865);
   ir_variable *const r0866 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0866);
   ir_variable *const r0867 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r0867);
   ir_variable *const r0868 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0868);
   ir_variable *const r0869 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0869);
   ir_variable *const r086A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r086A);
   body.emit(assign(r086A, body.constant(0u), 0x01));

   body.emit(assign(r0869, body.constant(0u), 0x01));

   body.emit(assign(r0868, body.constant(0u), 0x01));

   ir_variable *const r086B = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r086B, swizzle_x(r085C), 0x01));

   body.emit(assign(r0866, r086B, 0x01));

   ir_variable *const r086C = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r086C, bit_and(swizzle_y(r085C), body.constant(1048575u)), 0x01));

   body.emit(assign(r0865, r086C, 0x01));

   ir_variable *const r086D = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r086D, swizzle_x(r085D), 0x01));

   body.emit(assign(r0864, r086D, 0x01));

   ir_variable *const r086E = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r086E, bit_and(swizzle_y(r085D), body.constant(1048575u)), 0x01));

   body.emit(assign(r0863, r086E, 0x01));

   ir_variable *const r086F = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0870 = rshift(swizzle_y(r085C), body.constant(int(20)));
   ir_expression *const r0871 = bit_and(r0870, body.constant(2047u));
   body.emit(assign(r086F, expr(ir_unop_u2i, r0871), 0x01));

   body.emit(assign(r0862, r086F, 0x01));

   ir_variable *const r0872 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0873 = rshift(swizzle_y(r085D), body.constant(int(20)));
   ir_expression *const r0874 = bit_and(r0873, body.constant(2047u));
   body.emit(assign(r0872, expr(ir_unop_u2i, r0874), 0x01));

   body.emit(assign(r0861, r0872, 0x01));

   ir_expression *const r0875 = rshift(swizzle_y(r085C), body.constant(int(31)));
   ir_expression *const r0876 = rshift(swizzle_y(r085D), body.constant(int(31)));
   body.emit(assign(r0860, bit_xor(r0875, r0876), 0x01));

   /* IF CONDITION */
   ir_expression *const r0878 = equal(r086F, body.constant(int(2047)));
   ir_if *f0877 = new(mem_ctx) ir_if(operand(r0878).val);
   exec_list *const f0877_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0877->then_instructions;

      /* IF CONDITION */
      ir_expression *const r087A = bit_or(r086C, swizzle_x(r085C));
      ir_expression *const r087B = nequal(r087A, body.constant(0u));
      ir_expression *const r087C = equal(r0872, body.constant(int(2047)));
      ir_expression *const r087D = bit_or(r086E, swizzle_x(r085D));
      ir_expression *const r087E = nequal(r087D, body.constant(0u));
      ir_expression *const r087F = logic_and(r087C, r087E);
      ir_expression *const r0880 = logic_or(r087B, r087F);
      ir_if *f0879 = new(mem_ctx) ir_if(operand(r0880).val);
      exec_list *const f0879_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0879->then_instructions;

         ir_variable *const r0881 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r0881, swizzle_x(r085C), 0x01));

         ir_variable *const r0882 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r0882, swizzle_x(r085D), 0x01));

         body.emit(assign(r0881, bit_or(swizzle_y(r085C), body.constant(524288u)), 0x02));

         body.emit(assign(r0882, bit_or(swizzle_y(r085D), body.constant(524288u)), 0x02));

         ir_expression *const r0883 = lshift(swizzle_y(r085C), body.constant(int(1)));
         ir_expression *const r0884 = gequal(r0883, body.constant(4292870144u));
         ir_expression *const r0885 = nequal(swizzle_x(r085C), body.constant(0u));
         ir_expression *const r0886 = bit_and(swizzle_y(r085C), body.constant(1048575u));
         ir_expression *const r0887 = nequal(r0886, body.constant(0u));
         ir_expression *const r0888 = logic_or(r0885, r0887);
         ir_expression *const r0889 = logic_and(r0884, r0888);
         ir_swizzle *const r088A = swizzle(r0889, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r088B = lshift(swizzle_y(r085D), body.constant(int(1)));
         ir_expression *const r088C = gequal(r088B, body.constant(4292870144u));
         ir_expression *const r088D = nequal(swizzle_x(r085D), body.constant(0u));
         ir_expression *const r088E = bit_and(swizzle_y(r085D), body.constant(1048575u));
         ir_expression *const r088F = nequal(r088E, body.constant(0u));
         ir_expression *const r0890 = logic_or(r088D, r088F);
         ir_expression *const r0891 = logic_and(r088C, r0890);
         ir_swizzle *const r0892 = swizzle(r0891, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r0893 = expr(ir_triop_csel, r0892, r0882, r0881);
         body.emit(assign(r085F, expr(ir_triop_csel, r088A, r0893, r0882), 0x03));

         body.emit(assign(r085E, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0879->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0895 = expr(ir_unop_i2u, r0872);
         ir_expression *const r0896 = bit_or(r0895, r086E);
         ir_expression *const r0897 = bit_or(r0896, swizzle_x(r085D));
         ir_expression *const r0898 = equal(r0897, body.constant(0u));
         ir_if *f0894 = new(mem_ctx) ir_if(operand(r0898).val);
         exec_list *const f0894_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0894->then_instructions;

            ir_constant_data r0899_data;
            memset(&r0899_data, 0, sizeof(ir_constant_data));
            r0899_data.u[0] = 4294967295;
            r0899_data.u[1] = 4294967295;
            ir_constant *const r0899 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0899_data);
            body.emit(assign(r085F, r0899, 0x03));

            body.emit(assign(r085E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0894->else_instructions;

            ir_variable *const r089A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r089A);
            ir_expression *const r089B = lshift(r0860, body.constant(int(31)));
            body.emit(assign(r089A, add(r089B, body.constant(2146435072u)), 0x02));

            body.emit(assign(r089A, body.constant(0u), 0x01));

            body.emit(assign(r085F, r089A, 0x03));

            body.emit(assign(r085E, body.constant(false), 0x01));


         body.instructions = f0894_parent_instructions;
         body.emit(f0894);

         /* END IF */


      body.instructions = f0879_parent_instructions;
      body.emit(f0879);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0877->else_instructions;

      /* IF CONDITION */
      ir_expression *const r089D = equal(r0872, body.constant(int(2047)));
      ir_if *f089C = new(mem_ctx) ir_if(operand(r089D).val);
      exec_list *const f089C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f089C->then_instructions;

         /* IF CONDITION */
         ir_expression *const r089F = bit_or(r086E, swizzle_x(r085D));
         ir_expression *const r08A0 = nequal(r089F, body.constant(0u));
         ir_if *f089E = new(mem_ctx) ir_if(operand(r08A0).val);
         exec_list *const f089E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f089E->then_instructions;

            ir_variable *const r08A1 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r08A1, swizzle_x(r085C), 0x01));

            ir_variable *const r08A2 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r08A2, swizzle_x(r085D), 0x01));

            body.emit(assign(r08A1, bit_or(swizzle_y(r085C), body.constant(524288u)), 0x02));

            body.emit(assign(r08A2, bit_or(swizzle_y(r085D), body.constant(524288u)), 0x02));

            ir_expression *const r08A3 = lshift(swizzle_y(r085C), body.constant(int(1)));
            ir_expression *const r08A4 = gequal(r08A3, body.constant(4292870144u));
            ir_expression *const r08A5 = nequal(swizzle_x(r085C), body.constant(0u));
            ir_expression *const r08A6 = bit_and(swizzle_y(r085C), body.constant(1048575u));
            ir_expression *const r08A7 = nequal(r08A6, body.constant(0u));
            ir_expression *const r08A8 = logic_or(r08A5, r08A7);
            ir_expression *const r08A9 = logic_and(r08A4, r08A8);
            ir_swizzle *const r08AA = swizzle(r08A9, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r08AB = lshift(swizzle_y(r085D), body.constant(int(1)));
            ir_expression *const r08AC = gequal(r08AB, body.constant(4292870144u));
            ir_expression *const r08AD = nequal(swizzle_x(r085D), body.constant(0u));
            ir_expression *const r08AE = bit_and(swizzle_y(r085D), body.constant(1048575u));
            ir_expression *const r08AF = nequal(r08AE, body.constant(0u));
            ir_expression *const r08B0 = logic_or(r08AD, r08AF);
            ir_expression *const r08B1 = logic_and(r08AC, r08B0);
            ir_swizzle *const r08B2 = swizzle(r08B1, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r08B3 = expr(ir_triop_csel, r08B2, r08A2, r08A1);
            body.emit(assign(r085F, expr(ir_triop_csel, r08AA, r08B3, r08A2), 0x03));

            body.emit(assign(r085E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f089E->else_instructions;

            /* IF CONDITION */
            ir_expression *const r08B5 = expr(ir_unop_i2u, r086F);
            ir_expression *const r08B6 = bit_or(r08B5, r086C);
            ir_expression *const r08B7 = bit_or(r08B6, swizzle_x(r085C));
            ir_expression *const r08B8 = equal(r08B7, body.constant(0u));
            ir_if *f08B4 = new(mem_ctx) ir_if(operand(r08B8).val);
            exec_list *const f08B4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08B4->then_instructions;

               ir_constant_data r08B9_data;
               memset(&r08B9_data, 0, sizeof(ir_constant_data));
               r08B9_data.u[0] = 4294967295;
               r08B9_data.u[1] = 4294967295;
               ir_constant *const r08B9 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r08B9_data);
               body.emit(assign(r085F, r08B9, 0x03));

               body.emit(assign(r085E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08B4->else_instructions;

               ir_variable *const r08BA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r08BA);
               ir_expression *const r08BB = lshift(r0860, body.constant(int(31)));
               body.emit(assign(r08BA, add(r08BB, body.constant(2146435072u)), 0x02));

               body.emit(assign(r08BA, body.constant(0u), 0x01));

               body.emit(assign(r085F, r08BA, 0x03));

               body.emit(assign(r085E, body.constant(false), 0x01));


            body.instructions = f08B4_parent_instructions;
            body.emit(f08B4);

            /* END IF */


         body.instructions = f089E_parent_instructions;
         body.emit(f089E);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f089C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r08BD = equal(r086F, body.constant(int(0)));
         ir_if *f08BC = new(mem_ctx) ir_if(operand(r08BD).val);
         exec_list *const f08BC_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08BC->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08BF = bit_or(r086C, swizzle_x(r085C));
            ir_expression *const r08C0 = equal(r08BF, body.constant(0u));
            ir_if *f08BE = new(mem_ctx) ir_if(operand(r08C0).val);
            exec_list *const f08BE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08BE->then_instructions;

               ir_variable *const r08C1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r08C1);
               body.emit(assign(r08C1, lshift(r0860, body.constant(int(31))), 0x02));

               body.emit(assign(r08C1, body.constant(0u), 0x01));

               body.emit(assign(r085F, r08C1, 0x03));

               body.emit(assign(r085E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08BE->else_instructions;

               ir_variable *const r08C2 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r08C2, r086F, 0x01));

               ir_variable *const r08C3 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r08C3, r086C, 0x01));

               ir_variable *const r08C4 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r08C4, r086B, 0x01));

               ir_variable *const r08C5 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r08C5);
               /* IF CONDITION */
               ir_expression *const r08C7 = equal(r086C, body.constant(0u));
               ir_if *f08C6 = new(mem_ctx) ir_if(operand(r08C7).val);
               exec_list *const f08C6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08C6->then_instructions;

                  ir_variable *const r08C8 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r08C8, r086B, 0x01));

                  ir_variable *const r08C9 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r08CA = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08CA);
                  /* IF CONDITION */
                  ir_expression *const r08CC = equal(swizzle_x(r085C), body.constant(0u));
                  ir_if *f08CB = new(mem_ctx) ir_if(operand(r08CC).val);
                  exec_list *const f08CB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08CB->then_instructions;

                     body.emit(assign(r08C9, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08CB->else_instructions;

                     body.emit(assign(r08CA, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08CE = bit_and(swizzle_x(r085C), body.constant(4294901760u));
                     ir_expression *const r08CF = equal(r08CE, body.constant(0u));
                     ir_if *f08CD = new(mem_ctx) ir_if(operand(r08CF).val);
                     exec_list *const f08CD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08CD->then_instructions;

                        body.emit(assign(r08CA, body.constant(int(16)), 0x01));

                        body.emit(assign(r08C8, lshift(swizzle_x(r085C), body.constant(int(16))), 0x01));


                     body.instructions = f08CD_parent_instructions;
                     body.emit(f08CD);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08D1 = bit_and(r08C8, body.constant(4278190080u));
                     ir_expression *const r08D2 = equal(r08D1, body.constant(0u));
                     ir_if *f08D0 = new(mem_ctx) ir_if(operand(r08D2).val);
                     exec_list *const f08D0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08D0->then_instructions;

                        body.emit(assign(r08CA, add(r08CA, body.constant(int(8))), 0x01));

                        body.emit(assign(r08C8, lshift(r08C8, body.constant(int(8))), 0x01));


                     body.instructions = f08D0_parent_instructions;
                     body.emit(f08D0);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08D4 = bit_and(r08C8, body.constant(4026531840u));
                     ir_expression *const r08D5 = equal(r08D4, body.constant(0u));
                     ir_if *f08D3 = new(mem_ctx) ir_if(operand(r08D5).val);
                     exec_list *const f08D3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08D3->then_instructions;

                        body.emit(assign(r08CA, add(r08CA, body.constant(int(4))), 0x01));

                        body.emit(assign(r08C8, lshift(r08C8, body.constant(int(4))), 0x01));


                     body.instructions = f08D3_parent_instructions;
                     body.emit(f08D3);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08D7 = bit_and(r08C8, body.constant(3221225472u));
                     ir_expression *const r08D8 = equal(r08D7, body.constant(0u));
                     ir_if *f08D6 = new(mem_ctx) ir_if(operand(r08D8).val);
                     exec_list *const f08D6_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08D6->then_instructions;

                        body.emit(assign(r08CA, add(r08CA, body.constant(int(2))), 0x01));

                        body.emit(assign(r08C8, lshift(r08C8, body.constant(int(2))), 0x01));


                     body.instructions = f08D6_parent_instructions;
                     body.emit(f08D6);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08DA = bit_and(r08C8, body.constant(2147483648u));
                     ir_expression *const r08DB = equal(r08DA, body.constant(0u));
                     ir_if *f08D9 = new(mem_ctx) ir_if(operand(r08DB).val);
                     exec_list *const f08D9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08D9->then_instructions;

                        body.emit(assign(r08CA, add(r08CA, body.constant(int(1))), 0x01));


                     body.instructions = f08D9_parent_instructions;
                     body.emit(f08D9);

                     /* END IF */

                     body.emit(assign(r08C9, r08CA, 0x01));


                  body.instructions = f08CB_parent_instructions;
                  body.emit(f08CB);

                  /* END IF */

                  body.emit(assign(r08C5, add(r08C9, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r08DD = less(r08C5, body.constant(int(0)));
                  ir_if *f08DC = new(mem_ctx) ir_if(operand(r08DD).val);
                  exec_list *const f08DC_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08DC->then_instructions;

                     ir_expression *const r08DE = neg(r08C5);
                     body.emit(assign(r08C3, rshift(swizzle_x(r085C), r08DE), 0x01));

                     ir_expression *const r08DF = bit_and(r08C5, body.constant(int(31)));
                     body.emit(assign(r08C4, lshift(swizzle_x(r085C), r08DF), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08DC->else_instructions;

                     body.emit(assign(r08C3, lshift(swizzle_x(r085C), r08C5), 0x01));

                     body.emit(assign(r08C4, body.constant(0u), 0x01));


                  body.instructions = f08DC_parent_instructions;
                  body.emit(f08DC);

                  /* END IF */

                  body.emit(assign(r08C2, sub(body.constant(int(-31)), r08C5), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08C6->else_instructions;

                  ir_variable *const r08E0 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r08E0, r086C, 0x01));

                  ir_variable *const r08E1 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r08E2 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08E2);
                  /* IF CONDITION */
                  ir_expression *const r08E4 = equal(r086C, body.constant(0u));
                  ir_if *f08E3 = new(mem_ctx) ir_if(operand(r08E4).val);
                  exec_list *const f08E3_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08E3->then_instructions;

                     body.emit(assign(r08E1, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08E3->else_instructions;

                     body.emit(assign(r08E2, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08E6 = bit_and(r086C, body.constant(4294901760u));
                     ir_expression *const r08E7 = equal(r08E6, body.constant(0u));
                     ir_if *f08E5 = new(mem_ctx) ir_if(operand(r08E7).val);
                     exec_list *const f08E5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08E5->then_instructions;

                        body.emit(assign(r08E2, body.constant(int(16)), 0x01));

                        body.emit(assign(r08E0, lshift(r086C, body.constant(int(16))), 0x01));


                     body.instructions = f08E5_parent_instructions;
                     body.emit(f08E5);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08E9 = bit_and(r08E0, body.constant(4278190080u));
                     ir_expression *const r08EA = equal(r08E9, body.constant(0u));
                     ir_if *f08E8 = new(mem_ctx) ir_if(operand(r08EA).val);
                     exec_list *const f08E8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08E8->then_instructions;

                        body.emit(assign(r08E2, add(r08E2, body.constant(int(8))), 0x01));

                        body.emit(assign(r08E0, lshift(r08E0, body.constant(int(8))), 0x01));


                     body.instructions = f08E8_parent_instructions;
                     body.emit(f08E8);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08EC = bit_and(r08E0, body.constant(4026531840u));
                     ir_expression *const r08ED = equal(r08EC, body.constant(0u));
                     ir_if *f08EB = new(mem_ctx) ir_if(operand(r08ED).val);
                     exec_list *const f08EB_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08EB->then_instructions;

                        body.emit(assign(r08E2, add(r08E2, body.constant(int(4))), 0x01));

                        body.emit(assign(r08E0, lshift(r08E0, body.constant(int(4))), 0x01));


                     body.instructions = f08EB_parent_instructions;
                     body.emit(f08EB);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08EF = bit_and(r08E0, body.constant(3221225472u));
                     ir_expression *const r08F0 = equal(r08EF, body.constant(0u));
                     ir_if *f08EE = new(mem_ctx) ir_if(operand(r08F0).val);
                     exec_list *const f08EE_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08EE->then_instructions;

                        body.emit(assign(r08E2, add(r08E2, body.constant(int(2))), 0x01));

                        body.emit(assign(r08E0, lshift(r08E0, body.constant(int(2))), 0x01));


                     body.instructions = f08EE_parent_instructions;
                     body.emit(f08EE);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08F2 = bit_and(r08E0, body.constant(2147483648u));
                     ir_expression *const r08F3 = equal(r08F2, body.constant(0u));
                     ir_if *f08F1 = new(mem_ctx) ir_if(operand(r08F3).val);
                     exec_list *const f08F1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F1->then_instructions;

                        body.emit(assign(r08E2, add(r08E2, body.constant(int(1))), 0x01));


                     body.instructions = f08F1_parent_instructions;
                     body.emit(f08F1);

                     /* END IF */

                     body.emit(assign(r08E1, r08E2, 0x01));


                  body.instructions = f08E3_parent_instructions;
                  body.emit(f08E3);

                  /* END IF */

                  body.emit(assign(r08C5, add(r08E1, body.constant(int(-11))), 0x01));

                  ir_expression *const r08F4 = equal(r08C5, body.constant(int(0)));
                  ir_expression *const r08F5 = lshift(r086C, r08C5);
                  ir_expression *const r08F6 = neg(r08C5);
                  ir_expression *const r08F7 = bit_and(r08F6, body.constant(int(31)));
                  ir_expression *const r08F8 = rshift(swizzle_x(r085C), r08F7);
                  ir_expression *const r08F9 = bit_or(r08F5, r08F8);
                  body.emit(assign(r08C3, expr(ir_triop_csel, r08F4, r086C, r08F9), 0x01));

                  body.emit(assign(r08C4, lshift(swizzle_x(r085C), r08C5), 0x01));

                  body.emit(assign(r08C2, sub(body.constant(int(1)), r08C5), 0x01));


               body.instructions = f08C6_parent_instructions;
               body.emit(f08C6);

               /* END IF */

               body.emit(assign(r0862, r08C2, 0x01));

               body.emit(assign(r0865, r08C3, 0x01));

               body.emit(assign(r0866, r08C4, 0x01));


            body.instructions = f08BE_parent_instructions;
            body.emit(f08BE);

            /* END IF */


         body.instructions = f08BC_parent_instructions;
         body.emit(f08BC);

         /* END IF */

         /* IF CONDITION */
         ir_if *f08FA = new(mem_ctx) ir_if(operand(r085E).val);
         exec_list *const f08FA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08FA->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08FC = equal(r0872, body.constant(int(0)));
            ir_if *f08FB = new(mem_ctx) ir_if(operand(r08FC).val);
            exec_list *const f08FB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08FB->then_instructions;

               /* IF CONDITION */
               ir_expression *const r08FE = bit_or(r086E, swizzle_x(r085D));
               ir_expression *const r08FF = equal(r08FE, body.constant(0u));
               ir_if *f08FD = new(mem_ctx) ir_if(operand(r08FF).val);
               exec_list *const f08FD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08FD->then_instructions;

                  ir_variable *const r0900 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0900);
                  body.emit(assign(r0900, lshift(r0860, body.constant(int(31))), 0x02));

                  body.emit(assign(r0900, body.constant(0u), 0x01));

                  body.emit(assign(r085F, r0900, 0x03));

                  body.emit(assign(r085E, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08FD->else_instructions;

                  ir_variable *const r0901 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r0901, r0872, 0x01));

                  ir_variable *const r0902 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r0902, r086E, 0x01));

                  ir_variable *const r0903 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r0903, r086D, 0x01));

                  ir_variable *const r0904 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0904);
                  /* IF CONDITION */
                  ir_expression *const r0906 = equal(r086E, body.constant(0u));
                  ir_if *f0905 = new(mem_ctx) ir_if(operand(r0906).val);
                  exec_list *const f0905_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0905->then_instructions;

                     ir_variable *const r0907 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r0907, r086D, 0x01));

                     ir_variable *const r0908 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r0909 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0909);
                     /* IF CONDITION */
                     ir_expression *const r090B = equal(swizzle_x(r085D), body.constant(0u));
                     ir_if *f090A = new(mem_ctx) ir_if(operand(r090B).val);
                     exec_list *const f090A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f090A->then_instructions;

                        body.emit(assign(r0908, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f090A->else_instructions;

                        body.emit(assign(r0909, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r090D = bit_and(swizzle_x(r085D), body.constant(4294901760u));
                        ir_expression *const r090E = equal(r090D, body.constant(0u));
                        ir_if *f090C = new(mem_ctx) ir_if(operand(r090E).val);
                        exec_list *const f090C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f090C->then_instructions;

                           body.emit(assign(r0909, body.constant(int(16)), 0x01));

                           body.emit(assign(r0907, lshift(swizzle_x(r085D), body.constant(int(16))), 0x01));


                        body.instructions = f090C_parent_instructions;
                        body.emit(f090C);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0910 = bit_and(r0907, body.constant(4278190080u));
                        ir_expression *const r0911 = equal(r0910, body.constant(0u));
                        ir_if *f090F = new(mem_ctx) ir_if(operand(r0911).val);
                        exec_list *const f090F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f090F->then_instructions;

                           body.emit(assign(r0909, add(r0909, body.constant(int(8))), 0x01));

                           body.emit(assign(r0907, lshift(r0907, body.constant(int(8))), 0x01));


                        body.instructions = f090F_parent_instructions;
                        body.emit(f090F);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0913 = bit_and(r0907, body.constant(4026531840u));
                        ir_expression *const r0914 = equal(r0913, body.constant(0u));
                        ir_if *f0912 = new(mem_ctx) ir_if(operand(r0914).val);
                        exec_list *const f0912_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0912->then_instructions;

                           body.emit(assign(r0909, add(r0909, body.constant(int(4))), 0x01));

                           body.emit(assign(r0907, lshift(r0907, body.constant(int(4))), 0x01));


                        body.instructions = f0912_parent_instructions;
                        body.emit(f0912);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0916 = bit_and(r0907, body.constant(3221225472u));
                        ir_expression *const r0917 = equal(r0916, body.constant(0u));
                        ir_if *f0915 = new(mem_ctx) ir_if(operand(r0917).val);
                        exec_list *const f0915_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0915->then_instructions;

                           body.emit(assign(r0909, add(r0909, body.constant(int(2))), 0x01));

                           body.emit(assign(r0907, lshift(r0907, body.constant(int(2))), 0x01));


                        body.instructions = f0915_parent_instructions;
                        body.emit(f0915);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0919 = bit_and(r0907, body.constant(2147483648u));
                        ir_expression *const r091A = equal(r0919, body.constant(0u));
                        ir_if *f0918 = new(mem_ctx) ir_if(operand(r091A).val);
                        exec_list *const f0918_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0918->then_instructions;

                           body.emit(assign(r0909, add(r0909, body.constant(int(1))), 0x01));


                        body.instructions = f0918_parent_instructions;
                        body.emit(f0918);

                        /* END IF */

                        body.emit(assign(r0908, r0909, 0x01));


                     body.instructions = f090A_parent_instructions;
                     body.emit(f090A);

                     /* END IF */

                     body.emit(assign(r0904, add(r0908, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r091C = less(r0904, body.constant(int(0)));
                     ir_if *f091B = new(mem_ctx) ir_if(operand(r091C).val);
                     exec_list *const f091B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f091B->then_instructions;

                        ir_expression *const r091D = neg(r0904);
                        body.emit(assign(r0902, rshift(swizzle_x(r085D), r091D), 0x01));

                        ir_expression *const r091E = bit_and(r0904, body.constant(int(31)));
                        body.emit(assign(r0903, lshift(swizzle_x(r085D), r091E), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f091B->else_instructions;

                        body.emit(assign(r0902, lshift(swizzle_x(r085D), r0904), 0x01));

                        body.emit(assign(r0903, body.constant(0u), 0x01));


                     body.instructions = f091B_parent_instructions;
                     body.emit(f091B);

                     /* END IF */

                     body.emit(assign(r0901, sub(body.constant(int(-31)), r0904), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0905->else_instructions;

                     ir_variable *const r091F = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r091F, r086E, 0x01));

                     ir_variable *const r0920 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r0921 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0921);
                     /* IF CONDITION */
                     ir_expression *const r0923 = equal(r086E, body.constant(0u));
                     ir_if *f0922 = new(mem_ctx) ir_if(operand(r0923).val);
                     exec_list *const f0922_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0922->then_instructions;

                        body.emit(assign(r0920, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0922->else_instructions;

                        body.emit(assign(r0921, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0925 = bit_and(r086E, body.constant(4294901760u));
                        ir_expression *const r0926 = equal(r0925, body.constant(0u));
                        ir_if *f0924 = new(mem_ctx) ir_if(operand(r0926).val);
                        exec_list *const f0924_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0924->then_instructions;

                           body.emit(assign(r0921, body.constant(int(16)), 0x01));

                           body.emit(assign(r091F, lshift(r086E, body.constant(int(16))), 0x01));


                        body.instructions = f0924_parent_instructions;
                        body.emit(f0924);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0928 = bit_and(r091F, body.constant(4278190080u));
                        ir_expression *const r0929 = equal(r0928, body.constant(0u));
                        ir_if *f0927 = new(mem_ctx) ir_if(operand(r0929).val);
                        exec_list *const f0927_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0927->then_instructions;

                           body.emit(assign(r0921, add(r0921, body.constant(int(8))), 0x01));

                           body.emit(assign(r091F, lshift(r091F, body.constant(int(8))), 0x01));


                        body.instructions = f0927_parent_instructions;
                        body.emit(f0927);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r092B = bit_and(r091F, body.constant(4026531840u));
                        ir_expression *const r092C = equal(r092B, body.constant(0u));
                        ir_if *f092A = new(mem_ctx) ir_if(operand(r092C).val);
                        exec_list *const f092A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f092A->then_instructions;

                           body.emit(assign(r0921, add(r0921, body.constant(int(4))), 0x01));

                           body.emit(assign(r091F, lshift(r091F, body.constant(int(4))), 0x01));


                        body.instructions = f092A_parent_instructions;
                        body.emit(f092A);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r092E = bit_and(r091F, body.constant(3221225472u));
                        ir_expression *const r092F = equal(r092E, body.constant(0u));
                        ir_if *f092D = new(mem_ctx) ir_if(operand(r092F).val);
                        exec_list *const f092D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f092D->then_instructions;

                           body.emit(assign(r0921, add(r0921, body.constant(int(2))), 0x01));

                           body.emit(assign(r091F, lshift(r091F, body.constant(int(2))), 0x01));


                        body.instructions = f092D_parent_instructions;
                        body.emit(f092D);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0931 = bit_and(r091F, body.constant(2147483648u));
                        ir_expression *const r0932 = equal(r0931, body.constant(0u));
                        ir_if *f0930 = new(mem_ctx) ir_if(operand(r0932).val);
                        exec_list *const f0930_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0930->then_instructions;

                           body.emit(assign(r0921, add(r0921, body.constant(int(1))), 0x01));


                        body.instructions = f0930_parent_instructions;
                        body.emit(f0930);

                        /* END IF */

                        body.emit(assign(r0920, r0921, 0x01));


                     body.instructions = f0922_parent_instructions;
                     body.emit(f0922);

                     /* END IF */

                     body.emit(assign(r0904, add(r0920, body.constant(int(-11))), 0x01));

                     ir_expression *const r0933 = equal(r0904, body.constant(int(0)));
                     ir_expression *const r0934 = lshift(r086E, r0904);
                     ir_expression *const r0935 = neg(r0904);
                     ir_expression *const r0936 = bit_and(r0935, body.constant(int(31)));
                     ir_expression *const r0937 = rshift(swizzle_x(r085D), r0936);
                     ir_expression *const r0938 = bit_or(r0934, r0937);
                     body.emit(assign(r0902, expr(ir_triop_csel, r0933, r086E, r0938), 0x01));

                     body.emit(assign(r0903, lshift(swizzle_x(r085D), r0904), 0x01));

                     body.emit(assign(r0901, sub(body.constant(int(1)), r0904), 0x01));


                  body.instructions = f0905_parent_instructions;
                  body.emit(f0905);

                  /* END IF */

                  body.emit(assign(r0861, r0901, 0x01));

                  body.emit(assign(r0863, r0902, 0x01));

                  body.emit(assign(r0864, r0903, 0x01));


               body.instructions = f08FD_parent_instructions;
               body.emit(f08FD);

               /* END IF */


            body.instructions = f08FB_parent_instructions;
            body.emit(f08FB);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0939 = new(mem_ctx) ir_if(operand(r085E).val);
            exec_list *const f0939_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0939->then_instructions;

               ir_expression *const r093A = add(r0862, r0861);
               body.emit(assign(r0867, add(r093A, body.constant(int(-1024))), 0x01));

               body.emit(assign(r0865, bit_or(r0865, body.constant(1048576u)), 0x01));

               ir_variable *const r093B = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r093C = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r093C, lshift(r0864, body.constant(int(12))), 0x01));

               ir_expression *const r093D = lshift(r0863, body.constant(int(12)));
               ir_expression *const r093E = rshift(r0864, body.constant(int(20)));
               body.emit(assign(r093B, bit_or(r093D, r093E), 0x01));

               body.emit(assign(r0863, r093B, 0x01));

               body.emit(assign(r0864, r093C, 0x01));

               ir_variable *const r093F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r093F);
               ir_variable *const r0940 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0940);
               ir_variable *const r0941 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0941);
               ir_variable *const r0942 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0942, bit_and(r0866, body.constant(65535u)), 0x01));

               ir_variable *const r0943 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0943, rshift(r0866, body.constant(int(16))), 0x01));

               ir_variable *const r0944 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0944, bit_and(r093C, body.constant(65535u)), 0x01));

               ir_variable *const r0945 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0945, rshift(r093C, body.constant(int(16))), 0x01));

               ir_variable *const r0946 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0946, mul(r0943, r0944), 0x01));

               ir_expression *const r0947 = mul(r0942, r0945);
               body.emit(assign(r0940, add(r0947, r0946), 0x01));

               ir_expression *const r0948 = mul(r0943, r0945);
               ir_expression *const r0949 = less(r0940, r0946);
               ir_expression *const r094A = expr(ir_unop_b2i, r0949);
               ir_expression *const r094B = expr(ir_unop_i2u, r094A);
               ir_expression *const r094C = lshift(r094B, body.constant(int(16)));
               ir_expression *const r094D = rshift(r0940, body.constant(int(16)));
               ir_expression *const r094E = add(r094C, r094D);
               body.emit(assign(r093F, add(r0948, r094E), 0x01));

               body.emit(assign(r0940, lshift(r0940, body.constant(int(16))), 0x01));

               ir_expression *const r094F = mul(r0942, r0944);
               body.emit(assign(r0941, add(r094F, r0940), 0x01));

               ir_expression *const r0950 = less(r0941, r0940);
               ir_expression *const r0951 = expr(ir_unop_b2i, r0950);
               ir_expression *const r0952 = expr(ir_unop_i2u, r0951);
               body.emit(assign(r093F, add(r093F, r0952), 0x01));

               ir_variable *const r0953 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0953);
               ir_variable *const r0954 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0954);
               ir_variable *const r0955 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0955);
               ir_variable *const r0956 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0956, bit_and(r0866, body.constant(65535u)), 0x01));

               ir_variable *const r0957 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0957, rshift(r0866, body.constant(int(16))), 0x01));

               ir_variable *const r0958 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0958, bit_and(r093B, body.constant(65535u)), 0x01));

               ir_variable *const r0959 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0959, rshift(r093B, body.constant(int(16))), 0x01));

               ir_variable *const r095A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095A, mul(r0957, r0958), 0x01));

               ir_expression *const r095B = mul(r0956, r0959);
               body.emit(assign(r0954, add(r095B, r095A), 0x01));

               ir_expression *const r095C = mul(r0957, r0959);
               ir_expression *const r095D = less(r0954, r095A);
               ir_expression *const r095E = expr(ir_unop_b2i, r095D);
               ir_expression *const r095F = expr(ir_unop_i2u, r095E);
               ir_expression *const r0960 = lshift(r095F, body.constant(int(16)));
               ir_expression *const r0961 = rshift(r0954, body.constant(int(16)));
               ir_expression *const r0962 = add(r0960, r0961);
               body.emit(assign(r0953, add(r095C, r0962), 0x01));

               body.emit(assign(r0954, lshift(r0954, body.constant(int(16))), 0x01));

               ir_expression *const r0963 = mul(r0956, r0958);
               body.emit(assign(r0955, add(r0963, r0954), 0x01));

               ir_expression *const r0964 = less(r0955, r0954);
               ir_expression *const r0965 = expr(ir_unop_b2i, r0964);
               ir_expression *const r0966 = expr(ir_unop_i2u, r0965);
               body.emit(assign(r0953, add(r0953, r0966), 0x01));

               ir_variable *const r0967 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0967, add(r0955, r093F), 0x01));

               ir_variable *const r0968 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0968);
               ir_variable *const r0969 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0969);
               ir_variable *const r096A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r096A);
               ir_variable *const r096B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r096B, bit_and(r0865, body.constant(65535u)), 0x01));

               ir_variable *const r096C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r096C, rshift(r0865, body.constant(int(16))), 0x01));

               ir_variable *const r096D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r096D, bit_and(r093B, body.constant(65535u)), 0x01));

               ir_variable *const r096E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r096E, rshift(r093B, body.constant(int(16))), 0x01));

               ir_variable *const r096F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r096F, mul(r096C, r096D), 0x01));

               ir_expression *const r0970 = mul(r096B, r096E);
               body.emit(assign(r0969, add(r0970, r096F), 0x01));

               ir_expression *const r0971 = mul(r096C, r096E);
               ir_expression *const r0972 = less(r0969, r096F);
               ir_expression *const r0973 = expr(ir_unop_b2i, r0972);
               ir_expression *const r0974 = expr(ir_unop_i2u, r0973);
               ir_expression *const r0975 = lshift(r0974, body.constant(int(16)));
               ir_expression *const r0976 = rshift(r0969, body.constant(int(16)));
               ir_expression *const r0977 = add(r0975, r0976);
               body.emit(assign(r0968, add(r0971, r0977), 0x01));

               body.emit(assign(r0969, lshift(r0969, body.constant(int(16))), 0x01));

               ir_expression *const r0978 = mul(r096B, r096D);
               body.emit(assign(r096A, add(r0978, r0969), 0x01));

               ir_expression *const r0979 = less(r096A, r0969);
               ir_expression *const r097A = expr(ir_unop_b2i, r0979);
               ir_expression *const r097B = expr(ir_unop_i2u, r097A);
               body.emit(assign(r0968, add(r0968, r097B), 0x01));

               ir_variable *const r097C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r097D = less(r0967, r0955);
               ir_expression *const r097E = expr(ir_unop_b2i, r097D);
               ir_expression *const r097F = expr(ir_unop_i2u, r097E);
               ir_expression *const r0980 = add(r0953, r097F);
               body.emit(assign(r097C, add(r096A, r0980), 0x01));

               ir_variable *const r0981 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0981);
               ir_variable *const r0982 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0982);
               ir_variable *const r0983 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0983);
               ir_variable *const r0984 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0984, bit_and(r0865, body.constant(65535u)), 0x01));

               ir_variable *const r0985 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0985, rshift(r0865, body.constant(int(16))), 0x01));

               ir_variable *const r0986 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0986, bit_and(r093C, body.constant(65535u)), 0x01));

               ir_variable *const r0987 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0987, rshift(r093C, body.constant(int(16))), 0x01));

               ir_variable *const r0988 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0988, mul(r0985, r0986), 0x01));

               ir_expression *const r0989 = mul(r0984, r0987);
               body.emit(assign(r0982, add(r0989, r0988), 0x01));

               ir_expression *const r098A = mul(r0985, r0987);
               ir_expression *const r098B = less(r0982, r0988);
               ir_expression *const r098C = expr(ir_unop_b2i, r098B);
               ir_expression *const r098D = expr(ir_unop_i2u, r098C);
               ir_expression *const r098E = lshift(r098D, body.constant(int(16)));
               ir_expression *const r098F = rshift(r0982, body.constant(int(16)));
               ir_expression *const r0990 = add(r098E, r098F);
               body.emit(assign(r0981, add(r098A, r0990), 0x01));

               body.emit(assign(r0982, lshift(r0982, body.constant(int(16))), 0x01));

               ir_expression *const r0991 = mul(r0984, r0986);
               body.emit(assign(r0983, add(r0991, r0982), 0x01));

               ir_expression *const r0992 = less(r0983, r0982);
               ir_expression *const r0993 = expr(ir_unop_b2i, r0992);
               ir_expression *const r0994 = expr(ir_unop_i2u, r0993);
               body.emit(assign(r0981, add(r0981, r0994), 0x01));

               ir_variable *const r0995 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0995, add(r0983, r0967), 0x01));

               ir_variable *const r0996 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0997 = less(r0995, r0983);
               ir_expression *const r0998 = expr(ir_unop_b2i, r0997);
               ir_expression *const r0999 = expr(ir_unop_i2u, r0998);
               ir_expression *const r099A = add(r0981, r0999);
               body.emit(assign(r0996, add(r097C, r099A), 0x01));

               ir_variable *const r099B = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r099C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r099C, add(r0996, r0866), 0x01));

               ir_expression *const r099D = less(r097C, r096A);
               ir_expression *const r099E = expr(ir_unop_b2i, r099D);
               ir_expression *const r099F = expr(ir_unop_i2u, r099E);
               ir_expression *const r09A0 = add(r0968, r099F);
               ir_expression *const r09A1 = less(r0996, r097C);
               ir_expression *const r09A2 = expr(ir_unop_b2i, r09A1);
               ir_expression *const r09A3 = expr(ir_unop_i2u, r09A2);
               ir_expression *const r09A4 = add(r09A0, r09A3);
               ir_expression *const r09A5 = add(r09A4, r0865);
               ir_expression *const r09A6 = less(r099C, r0996);
               ir_expression *const r09A7 = expr(ir_unop_b2i, r09A6);
               ir_expression *const r09A8 = expr(ir_unop_i2u, r09A7);
               body.emit(assign(r099B, add(r09A5, r09A8), 0x01));

               body.emit(assign(r086A, r099B, 0x01));

               body.emit(assign(r0869, r099C, 0x01));

               ir_expression *const r09A9 = nequal(r0941, body.constant(0u));
               ir_expression *const r09AA = expr(ir_unop_b2i, r09A9);
               ir_expression *const r09AB = expr(ir_unop_i2u, r09AA);
               body.emit(assign(r0868, bit_or(r0995, r09AB), 0x01));

               /* IF CONDITION */
               ir_expression *const r09AD = gequal(r099B, body.constant(2097152u));
               ir_if *f09AC = new(mem_ctx) ir_if(operand(r09AD).val);
               exec_list *const f09AC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09AC->then_instructions;

                  ir_variable *const r09AE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r09AE);
                  body.emit(assign(r09AE, lshift(r099C, body.constant(int(31))), 0x01));

                  ir_expression *const r09AF = nequal(r0868, body.constant(0u));
                  ir_expression *const r09B0 = expr(ir_unop_b2i, r09AF);
                  ir_expression *const r09B1 = expr(ir_unop_i2u, r09B0);
                  body.emit(assign(r09AE, bit_or(r09AE, r09B1), 0x01));

                  body.emit(assign(r086A, rshift(r099B, body.constant(int(1))), 0x01));

                  ir_expression *const r09B2 = lshift(r099B, body.constant(int(31)));
                  ir_expression *const r09B3 = rshift(r099C, body.constant(int(1)));
                  body.emit(assign(r0869, bit_or(r09B2, r09B3), 0x01));

                  body.emit(assign(r0868, r09AE, 0x01));

                  body.emit(assign(r0867, add(r0867, body.constant(int(1))), 0x01));


               body.instructions = f09AC_parent_instructions;
               body.emit(f09AC);

               /* END IF */

               ir_variable *const r09B4 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r09B4, r0867, 0x01));

               ir_variable *const r09B5 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r09B5, r086A, 0x01));

               ir_variable *const r09B6 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r09B6, r0869, 0x01));

               ir_variable *const r09B7 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r09B7, r0868, 0x01));

               ir_variable *const r09B8 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r09B8, body.constant(true), 0x01));

               ir_variable *const r09B9 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r09BA = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r09BA);
               ir_expression *const r09BB = expr(ir_unop_u2i, r0868);
               body.emit(assign(r09BA, less(r09BB, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r09BD = gequal(r0867, body.constant(int(2045)));
               ir_if *f09BC = new(mem_ctx) ir_if(operand(r09BD).val);
               exec_list *const f09BC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09BC->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r09BF = less(body.constant(int(2045)), r0867);
                  ir_expression *const r09C0 = equal(r0867, body.constant(int(2045)));
                  ir_expression *const r09C1 = equal(body.constant(2097151u), r086A);
                  ir_expression *const r09C2 = equal(body.constant(4294967295u), r0869);
                  ir_expression *const r09C3 = logic_and(r09C1, r09C2);
                  ir_expression *const r09C4 = logic_and(r09C0, r09C3);
                  ir_expression *const r09C5 = logic_and(r09C4, r09BA);
                  ir_expression *const r09C6 = logic_or(r09BF, r09C5);
                  ir_if *f09BE = new(mem_ctx) ir_if(operand(r09C6).val);
                  exec_list *const f09BE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09BE->then_instructions;

                     ir_variable *const r09C7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r09C7);
                     ir_expression *const r09C8 = lshift(r0860, body.constant(int(31)));
                     body.emit(assign(r09C7, add(r09C8, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r09C7, body.constant(0u), 0x01));

                     body.emit(assign(r09B9, r09C7, 0x03));

                     body.emit(assign(r09B8, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09BE->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09CA = less(r0867, body.constant(int(0)));
                     ir_if *f09C9 = new(mem_ctx) ir_if(operand(r09CA).val);
                     exec_list *const f09C9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09C9->then_instructions;

                        ir_variable *const r09CB = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r09CB, r0868, 0x01));

                        ir_variable *const r09CC = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r09CC, neg(r0867), 0x01));

                        ir_variable *const r09CD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r09CD);
                        ir_variable *const r09CE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r09CE);
                        ir_variable *const r09CF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r09CF);
                        ir_variable *const r09D0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r09D1 = neg(r09CC);
                        body.emit(assign(r09D0, bit_and(r09D1, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r09D3 = equal(r09CC, body.constant(int(0)));
                        ir_if *f09D2 = new(mem_ctx) ir_if(operand(r09D3).val);
                        exec_list *const f09D2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f09D2->then_instructions;

                           body.emit(assign(r09CD, r0868, 0x01));

                           body.emit(assign(r09CE, r0869, 0x01));

                           body.emit(assign(r09CF, r086A, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f09D2->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r09D5 = less(r09CC, body.constant(int(32)));
                           ir_if *f09D4 = new(mem_ctx) ir_if(operand(r09D5).val);
                           exec_list *const f09D4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f09D4->then_instructions;

                              body.emit(assign(r09CD, lshift(r0869, r09D0), 0x01));

                              ir_expression *const r09D6 = lshift(r086A, r09D0);
                              ir_expression *const r09D7 = rshift(r0869, r09CC);
                              body.emit(assign(r09CE, bit_or(r09D6, r09D7), 0x01));

                              body.emit(assign(r09CF, rshift(r086A, r09CC), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f09D4->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r09D9 = equal(r09CC, body.constant(int(32)));
                              ir_if *f09D8 = new(mem_ctx) ir_if(operand(r09D9).val);
                              exec_list *const f09D8_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f09D8->then_instructions;

                                 body.emit(assign(r09CD, r0869, 0x01));

                                 body.emit(assign(r09CE, r086A, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f09D8->else_instructions;

                                 body.emit(assign(r09CB, bit_or(r0868, r0869), 0x01));

                                 ir_expression *const r09DA = less(r09CC, body.constant(int(64)));
                                 ir_expression *const r09DB = lshift(r086A, r09D0);
                                 ir_expression *const r09DC = equal(r09CC, body.constant(int(64)));
                                 ir_expression *const r09DD = nequal(r086A, body.constant(0u));
                                 ir_expression *const r09DE = expr(ir_unop_b2i, r09DD);
                                 ir_expression *const r09DF = expr(ir_unop_i2u, r09DE);
                                 ir_expression *const r09E0 = expr(ir_triop_csel, r09DC, r086A, r09DF);
                                 body.emit(assign(r09CD, expr(ir_triop_csel, r09DA, r09DB, r09E0), 0x01));

                                 ir_expression *const r09E1 = less(r09CC, body.constant(int(64)));
                                 ir_expression *const r09E2 = bit_and(r09CC, body.constant(int(31)));
                                 ir_expression *const r09E3 = rshift(r086A, r09E2);
                                 body.emit(assign(r09CE, expr(ir_triop_csel, r09E1, r09E3, body.constant(0u)), 0x01));


                              body.instructions = f09D8_parent_instructions;
                              body.emit(f09D8);

                              /* END IF */

                              body.emit(assign(r09CF, body.constant(0u), 0x01));


                           body.instructions = f09D4_parent_instructions;
                           body.emit(f09D4);

                           /* END IF */

                           ir_expression *const r09E4 = nequal(r09CB, body.constant(0u));
                           ir_expression *const r09E5 = expr(ir_unop_b2i, r09E4);
                           ir_expression *const r09E6 = expr(ir_unop_i2u, r09E5);
                           body.emit(assign(r09CD, bit_or(r09CD, r09E6), 0x01));


                        body.instructions = f09D2_parent_instructions;
                        body.emit(f09D2);

                        /* END IF */

                        body.emit(assign(r09B5, r09CF, 0x01));

                        body.emit(assign(r09B6, r09CE, 0x01));

                        body.emit(assign(r09B7, r09CD, 0x01));

                        body.emit(assign(r09B4, body.constant(int(0)), 0x01));

                        body.emit(assign(r09BA, less(r09CD, body.constant(0u)), 0x01));


                     body.instructions = f09C9_parent_instructions;
                     body.emit(f09C9);

                     /* END IF */


                  body.instructions = f09BE_parent_instructions;
                  body.emit(f09BE);

                  /* END IF */


               body.instructions = f09BC_parent_instructions;
               body.emit(f09BC);

               /* END IF */

               /* IF CONDITION */
               ir_if *f09E7 = new(mem_ctx) ir_if(operand(r09B8).val);
               exec_list *const f09E7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09E7->then_instructions;

                  /* IF CONDITION */
                  ir_if *f09E8 = new(mem_ctx) ir_if(operand(r09BA).val);
                  exec_list *const f09E8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09E8->then_instructions;

                     ir_variable *const r09E9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r09E9, add(r09B6, body.constant(1u)), 0x01));

                     ir_expression *const r09EA = less(r09E9, r09B6);
                     ir_expression *const r09EB = expr(ir_unop_b2i, r09EA);
                     ir_expression *const r09EC = expr(ir_unop_i2u, r09EB);
                     body.emit(assign(r09B5, add(r09B5, r09EC), 0x01));

                     ir_expression *const r09ED = equal(r09B7, body.constant(0u));
                     ir_expression *const r09EE = expr(ir_unop_b2i, r09ED);
                     ir_expression *const r09EF = expr(ir_unop_i2u, r09EE);
                     ir_expression *const r09F0 = add(r09B7, r09EF);
                     ir_expression *const r09F1 = bit_and(r09F0, body.constant(1u));
                     ir_expression *const r09F2 = expr(ir_unop_bit_not, r09F1);
                     body.emit(assign(r09B6, bit_and(r09E9, r09F2), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09E8->else_instructions;

                     ir_expression *const r09F3 = bit_or(r09B5, r09B6);
                     ir_expression *const r09F4 = equal(r09F3, body.constant(0u));
                     body.emit(assign(r09B4, expr(ir_triop_csel, r09F4, body.constant(int(0)), r09B4), 0x01));


                  body.instructions = f09E8_parent_instructions;
                  body.emit(f09E8);

                  /* END IF */

                  ir_variable *const r09F5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r09F5);
                  ir_expression *const r09F6 = lshift(r0860, body.constant(int(31)));
                  ir_expression *const r09F7 = expr(ir_unop_i2u, r09B4);
                  ir_expression *const r09F8 = lshift(r09F7, body.constant(int(20)));
                  ir_expression *const r09F9 = add(r09F6, r09F8);
                  body.emit(assign(r09F5, add(r09F9, r09B5), 0x02));

                  body.emit(assign(r09F5, r09B6, 0x01));

                  body.emit(assign(r09B9, r09F5, 0x03));

                  body.emit(assign(r09B8, body.constant(false), 0x01));


               body.instructions = f09E7_parent_instructions;
               body.emit(f09E7);

               /* END IF */

               body.emit(assign(r085F, r09B9, 0x03));

               body.emit(assign(r085E, body.constant(false), 0x01));


            body.instructions = f0939_parent_instructions;
            body.emit(f0939);

            /* END IF */


         body.instructions = f08FA_parent_instructions;
         body.emit(f08FA);

         /* END IF */


      body.instructions = f089C_parent_instructions;
      body.emit(f089C);

      /* END IF */


   body.instructions = f0877_parent_instructions;
   body.emit(f0877);

   /* END IF */

   body.emit(ret(r085F));

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

   ir_variable *const r09FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09FA);
   ir_variable *const r09FB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09FB);
   ir_variable *const r09FC = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r09FC);
   ir_variable *const r09FD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09FD);
   ir_variable *const r09FE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09FE);
   ir_expression *const r09FF = equal(r09FC, body.constant(int(0)));
   ir_expression *const r0A00 = less(r09FC, body.constant(int(32)));
   ir_expression *const r0A01 = neg(r09FC);
   ir_expression *const r0A02 = bit_and(r0A01, body.constant(int(31)));
   ir_expression *const r0A03 = lshift(r09FA, r0A02);
   ir_expression *const r0A04 = rshift(r09FB, r09FC);
   ir_expression *const r0A05 = bit_or(r0A03, r0A04);
   ir_expression *const r0A06 = less(r09FC, body.constant(int(64)));
   ir_expression *const r0A07 = bit_and(r09FC, body.constant(int(31)));
   ir_expression *const r0A08 = rshift(r09FA, r0A07);
   ir_expression *const r0A09 = expr(ir_triop_csel, r0A06, r0A08, body.constant(0u));
   ir_expression *const r0A0A = expr(ir_triop_csel, r0A00, r0A05, r0A09);
   body.emit(assign(r09FE, expr(ir_triop_csel, r09FF, r09FA, r0A0A), 0x01));

   ir_expression *const r0A0B = equal(r09FC, body.constant(int(0)));
   ir_expression *const r0A0C = less(r09FC, body.constant(int(32)));
   ir_expression *const r0A0D = rshift(r09FA, r09FC);
   ir_expression *const r0A0E = expr(ir_triop_csel, r0A0C, r0A0D, body.constant(0u));
   body.emit(assign(r09FD, expr(ir_triop_csel, r0A0B, r09FA, r0A0E), 0x01));

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

   ir_variable *const r0A0F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A0F);
   ir_variable *const r0A10 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0A11 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A11);
   ir_variable *const r0A12 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0A12);
   ir_variable *const r0A13 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0A13, swizzle_x(r0A0F), 0x01));

   body.emit(assign(r0A12, r0A13, 0x01));

   ir_variable *const r0A14 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A14, bit_and(swizzle_y(r0A0F), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A11, r0A14, 0x01));

   ir_variable *const r0A15 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A16 = rshift(swizzle_y(r0A0F), body.constant(int(20)));
   ir_expression *const r0A17 = bit_and(r0A16, body.constant(2047u));
   body.emit(assign(r0A15, expr(ir_unop_u2i, r0A17), 0x01));

   ir_variable *const r0A18 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A18, rshift(swizzle_y(r0A0F), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A1A = nequal(r0A18, body.constant(0u));
   ir_if *f0A19 = new(mem_ctx) ir_if(operand(r0A1A).val);
   exec_list *const f0A19_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A19->then_instructions;

      body.emit(assign(r0A10, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A19->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A1C = equal(r0A15, body.constant(int(2047)));
      ir_expression *const r0A1D = bit_or(r0A14, swizzle_x(r0A0F));
      ir_expression *const r0A1E = nequal(r0A1D, body.constant(0u));
      ir_expression *const r0A1F = logic_and(r0A1C, r0A1E);
      ir_if *f0A1B = new(mem_ctx) ir_if(operand(r0A1F).val);
      exec_list *const f0A1B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A1B->then_instructions;

         body.emit(assign(r0A10, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A1B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A21 = nequal(r0A15, body.constant(int(0)));
         ir_if *f0A20 = new(mem_ctx) ir_if(operand(r0A21).val);
         exec_list *const f0A20_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A20->then_instructions;

            body.emit(assign(r0A11, bit_or(r0A14, body.constant(1048576u)), 0x01));


         body.instructions = f0A20_parent_instructions;
         body.emit(f0A20);

         /* END IF */

         ir_variable *const r0A22 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0A22, sub(body.constant(int(1063)), r0A15), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A24 = less(body.constant(int(0)), r0A22);
         ir_if *f0A23 = new(mem_ctx) ir_if(operand(r0A24).val);
         exec_list *const f0A23_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A23->then_instructions;

            ir_variable *const r0A25 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0A25);
            ir_variable *const r0A26 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0A27 = neg(r0A22);
            body.emit(assign(r0A26, bit_and(r0A27, body.constant(int(31))), 0x01));

            ir_variable *const r0A28 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0A29 = less(r0A22, body.constant(int(32)));
            ir_expression *const r0A2A = rshift(r0A11, r0A22);
            ir_expression *const r0A2B = equal(r0A22, body.constant(int(0)));
            ir_expression *const r0A2C = expr(ir_triop_csel, r0A2B, r0A11, body.constant(0u));
            body.emit(assign(r0A28, expr(ir_triop_csel, r0A29, r0A2A, r0A2C), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A2E = equal(r0A22, body.constant(int(0)));
            ir_if *f0A2D = new(mem_ctx) ir_if(operand(r0A2E).val);
            exec_list *const f0A2D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A2D->then_instructions;

               body.emit(assign(r0A25, r0A13, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A2D->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0A30 = less(r0A22, body.constant(int(32)));
               ir_if *f0A2F = new(mem_ctx) ir_if(operand(r0A30).val);
               exec_list *const f0A2F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A2F->then_instructions;

                  ir_expression *const r0A31 = lshift(r0A11, r0A26);
                  ir_expression *const r0A32 = rshift(swizzle_x(r0A0F), r0A22);
                  ir_expression *const r0A33 = bit_or(r0A31, r0A32);
                  ir_expression *const r0A34 = lshift(swizzle_x(r0A0F), r0A26);
                  ir_expression *const r0A35 = nequal(r0A34, body.constant(0u));
                  ir_expression *const r0A36 = expr(ir_unop_b2i, r0A35);
                  ir_expression *const r0A37 = expr(ir_unop_i2u, r0A36);
                  body.emit(assign(r0A25, bit_or(r0A33, r0A37), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A2F->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A39 = equal(r0A22, body.constant(int(32)));
                  ir_if *f0A38 = new(mem_ctx) ir_if(operand(r0A39).val);
                  exec_list *const f0A38_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A38->then_instructions;

                     ir_expression *const r0A3A = nequal(swizzle_x(r0A0F), body.constant(0u));
                     ir_expression *const r0A3B = expr(ir_unop_b2i, r0A3A);
                     ir_expression *const r0A3C = expr(ir_unop_i2u, r0A3B);
                     body.emit(assign(r0A25, bit_or(r0A11, r0A3C), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A38->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0A3E = less(r0A22, body.constant(int(64)));
                     ir_if *f0A3D = new(mem_ctx) ir_if(operand(r0A3E).val);
                     exec_list *const f0A3D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0A3D->then_instructions;

                        ir_expression *const r0A3F = bit_and(r0A22, body.constant(int(31)));
                        ir_expression *const r0A40 = rshift(r0A11, r0A3F);
                        ir_expression *const r0A41 = lshift(r0A11, r0A26);
                        ir_expression *const r0A42 = bit_or(r0A41, swizzle_x(r0A0F));
                        ir_expression *const r0A43 = nequal(r0A42, body.constant(0u));
                        ir_expression *const r0A44 = expr(ir_unop_b2i, r0A43);
                        ir_expression *const r0A45 = expr(ir_unop_i2u, r0A44);
                        body.emit(assign(r0A25, bit_or(r0A40, r0A45), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0A3D->else_instructions;

                        ir_expression *const r0A46 = bit_or(r0A11, swizzle_x(r0A0F));
                        ir_expression *const r0A47 = nequal(r0A46, body.constant(0u));
                        ir_expression *const r0A48 = expr(ir_unop_b2i, r0A47);
                        body.emit(assign(r0A25, expr(ir_unop_i2u, r0A48), 0x01));


                     body.instructions = f0A3D_parent_instructions;
                     body.emit(f0A3D);

                     /* END IF */


                  body.instructions = f0A38_parent_instructions;
                  body.emit(f0A38);

                  /* END IF */


               body.instructions = f0A2F_parent_instructions;
               body.emit(f0A2F);

               /* END IF */


            body.instructions = f0A2D_parent_instructions;
            body.emit(f0A2D);

            /* END IF */

            body.emit(assign(r0A11, r0A28, 0x01));

            body.emit(assign(r0A12, r0A25, 0x01));


         body.instructions = f0A23_parent_instructions;
         body.emit(f0A23);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A4A = bit_and(r0A11, body.constant(4294963200u));
         ir_expression *const r0A4B = nequal(r0A4A, body.constant(0u));
         ir_if *f0A49 = new(mem_ctx) ir_if(operand(r0A4B).val);
         exec_list *const f0A49_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A49->then_instructions;

            ir_variable *const r0A4C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A4E = nequal(r0A18, body.constant(0u));
            ir_if *f0A4D = new(mem_ctx) ir_if(operand(r0A4E).val);
            exec_list *const f0A4D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A4D->then_instructions;

               body.emit(assign(r0A4C, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A4D->else_instructions;

               body.emit(assign(r0A4C, body.constant(4294967295u), 0x01));


            body.instructions = f0A4D_parent_instructions;
            body.emit(f0A4D);

            /* END IF */

            body.emit(assign(r0A10, r0A4C, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A49->else_instructions;

            ir_variable *const r0A4F = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r0A50 = lshift(r0A11, body.constant(int(20)));
            ir_expression *const r0A51 = rshift(r0A12, body.constant(int(12)));
            body.emit(assign(r0A4F, bit_or(r0A50, r0A51), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A53 = nequal(r0A18, body.constant(0u));
            ir_expression *const r0A54 = nequal(r0A4F, body.constant(0u));
            ir_expression *const r0A55 = logic_and(r0A53, r0A54);
            ir_if *f0A52 = new(mem_ctx) ir_if(operand(r0A55).val);
            exec_list *const f0A52_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A52->then_instructions;

               ir_variable *const r0A56 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0A58 = nequal(r0A18, body.constant(0u));
               ir_if *f0A57 = new(mem_ctx) ir_if(operand(r0A58).val);
               exec_list *const f0A57_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A57->then_instructions;

                  body.emit(assign(r0A56, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A57->else_instructions;

                  body.emit(assign(r0A56, body.constant(4294967295u), 0x01));


               body.instructions = f0A57_parent_instructions;
               body.emit(f0A57);

               /* END IF */

               body.emit(assign(r0A10, r0A56, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A52->else_instructions;

               body.emit(assign(r0A10, r0A4F, 0x01));


            body.instructions = f0A52_parent_instructions;
            body.emit(f0A52);

            /* END IF */


         body.instructions = f0A49_parent_instructions;
         body.emit(f0A49);

         /* END IF */


      body.instructions = f0A1B_parent_instructions;
      body.emit(f0A1B);

      /* END IF */


   body.instructions = f0A19_parent_instructions;
   body.emit(f0A19);

   /* END IF */

   body.emit(ret(r0A10));

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

   ir_variable *const r0A59 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A59);
   ir_variable *const r0A5A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A5B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0A5B);
   ir_variable *const r0A5C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0A5C);
   /* IF CONDITION */
   ir_expression *const r0A5E = equal(r0A59, body.constant(0u));
   ir_if *f0A5D = new(mem_ctx) ir_if(operand(r0A5E).val);
   exec_list *const f0A5D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A5D->then_instructions;

      body.emit(assign(r0A5A, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A5D->else_instructions;

      ir_variable *const r0A5F = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0A5F, r0A59, 0x01));

      ir_variable *const r0A60 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0A61 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0A61);
      /* IF CONDITION */
      ir_expression *const r0A63 = equal(r0A59, body.constant(0u));
      ir_if *f0A62 = new(mem_ctx) ir_if(operand(r0A63).val);
      exec_list *const f0A62_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A62->then_instructions;

         body.emit(assign(r0A60, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A62->else_instructions;

         body.emit(assign(r0A61, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A65 = bit_and(r0A59, body.constant(4294901760u));
         ir_expression *const r0A66 = equal(r0A65, body.constant(0u));
         ir_if *f0A64 = new(mem_ctx) ir_if(operand(r0A66).val);
         exec_list *const f0A64_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A64->then_instructions;

            body.emit(assign(r0A61, body.constant(int(16)), 0x01));

            body.emit(assign(r0A5F, lshift(r0A59, body.constant(int(16))), 0x01));


         body.instructions = f0A64_parent_instructions;
         body.emit(f0A64);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A68 = bit_and(r0A5F, body.constant(4278190080u));
         ir_expression *const r0A69 = equal(r0A68, body.constant(0u));
         ir_if *f0A67 = new(mem_ctx) ir_if(operand(r0A69).val);
         exec_list *const f0A67_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A67->then_instructions;

            body.emit(assign(r0A61, add(r0A61, body.constant(int(8))), 0x01));

            body.emit(assign(r0A5F, lshift(r0A5F, body.constant(int(8))), 0x01));


         body.instructions = f0A67_parent_instructions;
         body.emit(f0A67);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A6B = bit_and(r0A5F, body.constant(4026531840u));
         ir_expression *const r0A6C = equal(r0A6B, body.constant(0u));
         ir_if *f0A6A = new(mem_ctx) ir_if(operand(r0A6C).val);
         exec_list *const f0A6A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A6A->then_instructions;

            body.emit(assign(r0A61, add(r0A61, body.constant(int(4))), 0x01));

            body.emit(assign(r0A5F, lshift(r0A5F, body.constant(int(4))), 0x01));


         body.instructions = f0A6A_parent_instructions;
         body.emit(f0A6A);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A6E = bit_and(r0A5F, body.constant(3221225472u));
         ir_expression *const r0A6F = equal(r0A6E, body.constant(0u));
         ir_if *f0A6D = new(mem_ctx) ir_if(operand(r0A6F).val);
         exec_list *const f0A6D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A6D->then_instructions;

            body.emit(assign(r0A61, add(r0A61, body.constant(int(2))), 0x01));

            body.emit(assign(r0A5F, lshift(r0A5F, body.constant(int(2))), 0x01));


         body.instructions = f0A6D_parent_instructions;
         body.emit(f0A6D);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A71 = bit_and(r0A5F, body.constant(2147483648u));
         ir_expression *const r0A72 = equal(r0A71, body.constant(0u));
         ir_if *f0A70 = new(mem_ctx) ir_if(operand(r0A72).val);
         exec_list *const f0A70_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A70->then_instructions;

            body.emit(assign(r0A61, add(r0A61, body.constant(int(1))), 0x01));


         body.instructions = f0A70_parent_instructions;
         body.emit(f0A70);

         /* END IF */

         body.emit(assign(r0A60, r0A61, 0x01));


      body.instructions = f0A62_parent_instructions;
      body.emit(f0A62);

      /* END IF */

      ir_variable *const r0A73 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0A73, add(r0A60, body.constant(int(21))), 0x01));

      body.emit(assign(r0A5C, body.constant(0u), 0x01));

      body.emit(assign(r0A5B, body.constant(0u), 0x01));

      ir_variable *const r0A74 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0A75 = neg(r0A73);
      body.emit(assign(r0A74, bit_and(r0A75, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A77 = equal(r0A73, body.constant(int(0)));
      ir_if *f0A76 = new(mem_ctx) ir_if(operand(r0A77).val);
      exec_list *const f0A76_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A76->then_instructions;

         body.emit(assign(r0A5C, body.constant(0u), 0x01));

         body.emit(assign(r0A5B, r0A59, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A76->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A79 = less(r0A73, body.constant(int(32)));
         ir_if *f0A78 = new(mem_ctx) ir_if(operand(r0A79).val);
         exec_list *const f0A78_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A78->then_instructions;

            body.emit(assign(r0A5C, rshift(r0A59, r0A74), 0x01));

            body.emit(assign(r0A5B, lshift(r0A59, r0A73), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A78->else_instructions;

            ir_variable *const r0A7A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A7C = less(r0A73, body.constant(int(64)));
            ir_if *f0A7B = new(mem_ctx) ir_if(operand(r0A7C).val);
            exec_list *const f0A7B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A7B->then_instructions;

               ir_expression *const r0A7D = add(r0A73, body.constant(int(-32)));
               body.emit(assign(r0A7A, lshift(r0A59, r0A7D), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A7B->else_instructions;

               body.emit(assign(r0A7A, body.constant(0u), 0x01));


            body.instructions = f0A7B_parent_instructions;
            body.emit(f0A7B);

            /* END IF */

            body.emit(assign(r0A5C, r0A7A, 0x01));

            body.emit(assign(r0A5B, body.constant(0u), 0x01));


         body.instructions = f0A78_parent_instructions;
         body.emit(f0A78);

         /* END IF */


      body.instructions = f0A76_parent_instructions;
      body.emit(f0A76);

      /* END IF */

      ir_variable *const r0A7E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A7E);
      ir_expression *const r0A7F = sub(body.constant(int(1074)), r0A73);
      ir_expression *const r0A80 = expr(ir_unop_i2u, r0A7F);
      ir_expression *const r0A81 = lshift(r0A80, body.constant(int(20)));
      body.emit(assign(r0A7E, add(r0A81, r0A5C), 0x02));

      body.emit(assign(r0A7E, r0A5B, 0x01));

      body.emit(assign(r0A5A, r0A7E, 0x03));


   body.instructions = f0A5D_parent_instructions;
   body.emit(f0A5D);

   /* END IF */

   body.emit(ret(r0A5A));

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

   ir_variable *const r0A82 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A82);
   ir_variable *const r0A83 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A83, body.constant(true), 0x01));

   ir_variable *const r0A84 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0A85 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0A85);
   ir_variable *const r0A86 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A86);
   ir_variable *const r0A87 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A87);
   ir_variable *const r0A88 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A88, bit_and(swizzle_y(r0A82), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A87, r0A88, 0x01));

   ir_variable *const r0A89 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A8A = rshift(swizzle_y(r0A82), body.constant(int(20)));
   ir_expression *const r0A8B = bit_and(r0A8A, body.constant(2047u));
   body.emit(assign(r0A89, expr(ir_unop_u2i, r0A8B), 0x01));

   body.emit(assign(r0A86, rshift(swizzle_y(r0A82), body.constant(int(31))), 0x01));

   body.emit(assign(r0A85, body.constant(0u), 0x01));

   ir_variable *const r0A8C = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0A8C, add(r0A89, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A8E = gequal(r0A8C, body.constant(int(0)));
   ir_if *f0A8D = new(mem_ctx) ir_if(operand(r0A8E).val);
   exec_list *const f0A8D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A8D->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A90 = less(body.constant(int(1054)), r0A89);
      ir_if *f0A8F = new(mem_ctx) ir_if(operand(r0A90).val);
      exec_list *const f0A8F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A8F->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A92 = equal(r0A89, body.constant(int(2047)));
         ir_expression *const r0A93 = bit_or(r0A88, swizzle_x(r0A82));
         ir_expression *const r0A94 = expr(ir_unop_u2i, r0A93);
         ir_expression *const r0A95 = expr(ir_unop_i2b, r0A94);
         ir_expression *const r0A96 = logic_and(r0A92, r0A95);
         ir_if *f0A91 = new(mem_ctx) ir_if(operand(r0A96).val);
         exec_list *const f0A91_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A91->then_instructions;

            body.emit(assign(r0A86, body.constant(0u), 0x01));


         body.instructions = f0A91_parent_instructions;
         body.emit(f0A91);

         /* END IF */

         ir_variable *const r0A97 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A99 = expr(ir_unop_u2i, r0A86);
         ir_expression *const r0A9A = expr(ir_unop_i2b, r0A99);
         ir_if *f0A98 = new(mem_ctx) ir_if(operand(r0A9A).val);
         exec_list *const f0A98_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A98->then_instructions;

            body.emit(assign(r0A97, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A98->else_instructions;

            body.emit(assign(r0A97, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A98_parent_instructions;
         body.emit(f0A98);

         /* END IF */

         body.emit(assign(r0A84, r0A97, 0x01));

         body.emit(assign(r0A83, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A8F->else_instructions;

         ir_variable *const r0A9B = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r0A9B, bit_or(r0A88, body.constant(1048576u)), 0x01));

         ir_expression *const r0A9C = equal(r0A8C, body.constant(int(0)));
         ir_expression *const r0A9D = lshift(r0A9B, r0A8C);
         ir_expression *const r0A9E = neg(r0A8C);
         ir_expression *const r0A9F = bit_and(r0A9E, body.constant(int(31)));
         ir_expression *const r0AA0 = rshift(swizzle_x(r0A82), r0A9F);
         ir_expression *const r0AA1 = bit_or(r0A9D, r0AA0);
         body.emit(assign(r0A85, expr(ir_triop_csel, r0A9C, r0A9B, r0AA1), 0x01));


      body.instructions = f0A8F_parent_instructions;
      body.emit(f0A8F);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A8D->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0AA3 = less(r0A89, body.constant(int(1023)));
      ir_if *f0AA2 = new(mem_ctx) ir_if(operand(r0AA3).val);
      exec_list *const f0AA2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AA2->then_instructions;

         body.emit(assign(r0A84, body.constant(int(0)), 0x01));

         body.emit(assign(r0A83, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AA2->else_instructions;

         body.emit(assign(r0A87, bit_or(r0A88, body.constant(1048576u)), 0x01));

         ir_expression *const r0AA4 = neg(r0A8C);
         body.emit(assign(r0A85, rshift(r0A87, r0AA4), 0x01));


      body.instructions = f0AA2_parent_instructions;
      body.emit(f0AA2);

      /* END IF */


   body.instructions = f0A8D_parent_instructions;
   body.emit(f0A8D);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0AA5 = new(mem_ctx) ir_if(operand(r0A83).val);
   exec_list *const f0AA5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AA5->then_instructions;

      ir_variable *const r0AA6 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0AA8 = nequal(r0A86, body.constant(0u));
      ir_if *f0AA7 = new(mem_ctx) ir_if(operand(r0AA8).val);
      exec_list *const f0AA7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AA7->then_instructions;

         ir_expression *const r0AA9 = expr(ir_unop_u2i, r0A85);
         body.emit(assign(r0AA6, neg(r0AA9), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AA7->else_instructions;

         body.emit(assign(r0AA6, expr(ir_unop_u2i, r0A85), 0x01));


      body.instructions = f0AA7_parent_instructions;
      body.emit(f0AA7);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0AAB = less(r0AA6, body.constant(int(0)));
      ir_expression *const r0AAC = expr(ir_unop_b2i, r0AAB);
      ir_expression *const r0AAD = expr(ir_unop_i2u, r0AAC);
      ir_expression *const r0AAE = bit_xor(r0A86, r0AAD);
      ir_expression *const r0AAF = expr(ir_unop_u2i, r0AAE);
      ir_expression *const r0AB0 = expr(ir_unop_i2b, r0AAF);
      ir_expression *const r0AB1 = expr(ir_unop_i2b, r0AA6);
      ir_expression *const r0AB2 = logic_and(r0AB0, r0AB1);
      ir_if *f0AAA = new(mem_ctx) ir_if(operand(r0AB2).val);
      exec_list *const f0AAA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AAA->then_instructions;

         ir_variable *const r0AB3 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0AB5 = expr(ir_unop_u2i, r0A86);
         ir_expression *const r0AB6 = expr(ir_unop_i2b, r0AB5);
         ir_if *f0AB4 = new(mem_ctx) ir_if(operand(r0AB6).val);
         exec_list *const f0AB4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AB4->then_instructions;

            body.emit(assign(r0AB3, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AB4->else_instructions;

            body.emit(assign(r0AB3, body.constant(int(2147483647)), 0x01));


         body.instructions = f0AB4_parent_instructions;
         body.emit(f0AB4);

         /* END IF */

         body.emit(assign(r0A84, r0AB3, 0x01));

         body.emit(assign(r0A83, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AAA->else_instructions;

         body.emit(assign(r0A84, r0AA6, 0x01));

         body.emit(assign(r0A83, body.constant(false), 0x01));


      body.instructions = f0AAA_parent_instructions;
      body.emit(f0AAA);

      /* END IF */


   body.instructions = f0AA5_parent_instructions;
   body.emit(f0AA5);

   /* END IF */

   body.emit(ret(r0A84));

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

   ir_variable *const r0AB7 = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AB7);
   ir_variable *const r0AB8 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0AB9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0AB9);
   ir_variable *const r0ABA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0ABA);
   ir_variable *const r0ABB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0ABB);
   body.emit(assign(r0ABB, body.constant(0u), 0x01));

   body.emit(assign(r0ABA, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0ABD = equal(r0AB7, body.constant(int(0)));
   ir_if *f0ABC = new(mem_ctx) ir_if(operand(r0ABD).val);
   exec_list *const f0ABC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0ABC->then_instructions;

      ir_variable *const r0ABE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0ABE);
      body.emit(assign(r0ABE, body.constant(0u), 0x02));

      body.emit(assign(r0ABE, body.constant(0u), 0x01));

      body.emit(assign(r0AB8, r0ABE, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0ABC->else_instructions;

      ir_expression *const r0ABF = less(r0AB7, body.constant(int(0)));
      ir_expression *const r0AC0 = expr(ir_unop_b2i, r0ABF);
      body.emit(assign(r0AB9, expr(ir_unop_i2u, r0AC0), 0x01));

      ir_variable *const r0AC1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0AC3 = less(r0AB7, body.constant(int(0)));
      ir_if *f0AC2 = new(mem_ctx) ir_if(operand(r0AC3).val);
      exec_list *const f0AC2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AC2->then_instructions;

         ir_expression *const r0AC4 = neg(r0AB7);
         body.emit(assign(r0AC1, expr(ir_unop_i2u, r0AC4), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AC2->else_instructions;

         body.emit(assign(r0AC1, expr(ir_unop_i2u, r0AB7), 0x01));


      body.instructions = f0AC2_parent_instructions;
      body.emit(f0AC2);

      /* END IF */

      ir_variable *const r0AC5 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0AC5, r0AC1, 0x01));

      ir_variable *const r0AC6 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0AC7 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0AC7);
      /* IF CONDITION */
      ir_expression *const r0AC9 = equal(r0AC1, body.constant(0u));
      ir_if *f0AC8 = new(mem_ctx) ir_if(operand(r0AC9).val);
      exec_list *const f0AC8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AC8->then_instructions;

         body.emit(assign(r0AC6, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AC8->else_instructions;

         body.emit(assign(r0AC7, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0ACB = bit_and(r0AC1, body.constant(4294901760u));
         ir_expression *const r0ACC = equal(r0ACB, body.constant(0u));
         ir_if *f0ACA = new(mem_ctx) ir_if(operand(r0ACC).val);
         exec_list *const f0ACA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ACA->then_instructions;

            body.emit(assign(r0AC7, body.constant(int(16)), 0x01));

            body.emit(assign(r0AC5, lshift(r0AC1, body.constant(int(16))), 0x01));


         body.instructions = f0ACA_parent_instructions;
         body.emit(f0ACA);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0ACE = bit_and(r0AC5, body.constant(4278190080u));
         ir_expression *const r0ACF = equal(r0ACE, body.constant(0u));
         ir_if *f0ACD = new(mem_ctx) ir_if(operand(r0ACF).val);
         exec_list *const f0ACD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ACD->then_instructions;

            body.emit(assign(r0AC7, add(r0AC7, body.constant(int(8))), 0x01));

            body.emit(assign(r0AC5, lshift(r0AC5, body.constant(int(8))), 0x01));


         body.instructions = f0ACD_parent_instructions;
         body.emit(f0ACD);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AD1 = bit_and(r0AC5, body.constant(4026531840u));
         ir_expression *const r0AD2 = equal(r0AD1, body.constant(0u));
         ir_if *f0AD0 = new(mem_ctx) ir_if(operand(r0AD2).val);
         exec_list *const f0AD0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AD0->then_instructions;

            body.emit(assign(r0AC7, add(r0AC7, body.constant(int(4))), 0x01));

            body.emit(assign(r0AC5, lshift(r0AC5, body.constant(int(4))), 0x01));


         body.instructions = f0AD0_parent_instructions;
         body.emit(f0AD0);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AD4 = bit_and(r0AC5, body.constant(3221225472u));
         ir_expression *const r0AD5 = equal(r0AD4, body.constant(0u));
         ir_if *f0AD3 = new(mem_ctx) ir_if(operand(r0AD5).val);
         exec_list *const f0AD3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AD3->then_instructions;

            body.emit(assign(r0AC7, add(r0AC7, body.constant(int(2))), 0x01));

            body.emit(assign(r0AC5, lshift(r0AC5, body.constant(int(2))), 0x01));


         body.instructions = f0AD3_parent_instructions;
         body.emit(f0AD3);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AD7 = bit_and(r0AC5, body.constant(2147483648u));
         ir_expression *const r0AD8 = equal(r0AD7, body.constant(0u));
         ir_if *f0AD6 = new(mem_ctx) ir_if(operand(r0AD8).val);
         exec_list *const f0AD6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AD6->then_instructions;

            body.emit(assign(r0AC7, add(r0AC7, body.constant(int(1))), 0x01));


         body.instructions = f0AD6_parent_instructions;
         body.emit(f0AD6);

         /* END IF */

         body.emit(assign(r0AC6, r0AC7, 0x01));


      body.instructions = f0AC8_parent_instructions;
      body.emit(f0AC8);

      /* END IF */

      ir_variable *const r0AD9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0AD9, add(r0AC6, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0ADB = gequal(r0AD9, body.constant(int(0)));
      ir_if *f0ADA = new(mem_ctx) ir_if(operand(r0ADB).val);
      exec_list *const f0ADA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0ADA->then_instructions;

         body.emit(assign(r0ABB, lshift(r0AC1, r0AD9), 0x01));

         body.emit(assign(r0ABA, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0ADA->else_instructions;

         ir_variable *const r0ADC = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r0ADC, neg(r0AD9), 0x01));

         ir_expression *const r0ADD = equal(r0ADC, body.constant(int(0)));
         ir_expression *const r0ADE = less(r0ADC, body.constant(int(32)));
         ir_expression *const r0ADF = rshift(r0AC1, r0ADC);
         ir_expression *const r0AE0 = expr(ir_triop_csel, r0ADE, r0ADF, body.constant(0u));
         body.emit(assign(r0ABB, expr(ir_triop_csel, r0ADD, r0AC1, r0AE0), 0x01));

         ir_expression *const r0AE1 = equal(r0ADC, body.constant(int(0)));
         ir_expression *const r0AE2 = less(r0ADC, body.constant(int(32)));
         ir_expression *const r0AE3 = neg(r0ADC);
         ir_expression *const r0AE4 = bit_and(r0AE3, body.constant(int(31)));
         ir_expression *const r0AE5 = lshift(r0AC1, r0AE4);
         ir_expression *const r0AE6 = bit_or(r0AE5, body.constant(0u));
         ir_expression *const r0AE7 = less(r0ADC, body.constant(int(64)));
         ir_expression *const r0AE8 = bit_and(r0ADC, body.constant(int(31)));
         ir_expression *const r0AE9 = rshift(r0AC1, r0AE8);
         ir_expression *const r0AEA = expr(ir_triop_csel, r0AE7, r0AE9, body.constant(0u));
         ir_expression *const r0AEB = expr(ir_triop_csel, r0AE2, r0AE6, r0AEA);
         body.emit(assign(r0ABA, expr(ir_triop_csel, r0AE1, r0AC1, r0AEB), 0x01));


      body.instructions = f0ADA_parent_instructions;
      body.emit(f0ADA);

      /* END IF */

      ir_variable *const r0AEC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0AEC);
      ir_expression *const r0AED = lshift(r0AB9, body.constant(int(31)));
      ir_expression *const r0AEE = sub(body.constant(int(1042)), r0AD9);
      ir_expression *const r0AEF = expr(ir_unop_i2u, r0AEE);
      ir_expression *const r0AF0 = lshift(r0AEF, body.constant(int(20)));
      ir_expression *const r0AF1 = add(r0AED, r0AF0);
      body.emit(assign(r0AEC, add(r0AF1, r0ABB), 0x02));

      body.emit(assign(r0AEC, r0ABA, 0x01));

      body.emit(assign(r0AB8, r0AEC, 0x03));


   body.instructions = f0ABC_parent_instructions;
   body.emit(f0ABC);

   /* END IF */

   body.emit(ret(r0AB8));

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

   ir_variable *const r0AF2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AF2);
   ir_variable *const r0AF3 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AF3);
   ir_variable *const r0AF4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AF4);
   ir_variable *const r0AF5 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r0AF6 = lshift(r0AF2, body.constant(int(31)));
   ir_expression *const r0AF7 = expr(ir_unop_i2u, r0AF3);
   ir_expression *const r0AF8 = lshift(r0AF7, body.constant(int(23)));
   ir_expression *const r0AF9 = add(r0AF6, r0AF8);
   ir_expression *const r0AFA = add(r0AF9, r0AF4);
   body.emit(assign(r0AF5, expr(ir_unop_bitcast_u2f, r0AFA), 0x01));

   body.emit(ret(r0AF5));

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

   ir_variable *const r0AFB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AFB);
   ir_variable *const r0AFC = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AFC);
   ir_variable *const r0AFD = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AFD);
   ir_variable *const r0AFE = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0AFE, body.constant(true), 0x01));

   ir_variable *const r0AFF = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B00 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0B00);
   ir_expression *const r0B01 = bit_and(r0AFD, body.constant(127u));
   body.emit(assign(r0B00, expr(ir_unop_u2i, r0B01), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B03 = expr(ir_unop_i2u, r0AFC);
   ir_expression *const r0B04 = gequal(r0B03, body.constant(253u));
   ir_if *f0B02 = new(mem_ctx) ir_if(operand(r0B04).val);
   exec_list *const f0B02_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B02->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B06 = less(body.constant(int(253)), r0AFC);
      ir_expression *const r0B07 = equal(r0AFC, body.constant(int(253)));
      ir_expression *const r0B08 = expr(ir_unop_u2i, r0AFD);
      ir_expression *const r0B09 = less(r0B08, body.constant(int(-64)));
      ir_expression *const r0B0A = logic_and(r0B07, r0B09);
      ir_expression *const r0B0B = logic_or(r0B06, r0B0A);
      ir_if *f0B05 = new(mem_ctx) ir_if(operand(r0B0B).val);
      exec_list *const f0B05_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B05->then_instructions;

         ir_expression *const r0B0C = lshift(r0AFB, body.constant(int(31)));
         ir_expression *const r0B0D = add(r0B0C, body.constant(2139095040u));
         body.emit(assign(r0AFF, expr(ir_unop_bitcast_u2f, r0B0D), 0x01));

         body.emit(assign(r0AFE, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B05->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0B0F = less(r0AFC, body.constant(int(0)));
         ir_if *f0B0E = new(mem_ctx) ir_if(operand(r0B0F).val);
         exec_list *const f0B0E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B0E->then_instructions;

            ir_variable *const r0B10 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B10, neg(r0AFC), 0x01));

            /* IF CONDITION */
            ir_expression *const r0B12 = less(r0B10, body.constant(int(32)));
            ir_if *f0B11 = new(mem_ctx) ir_if(operand(r0B12).val);
            exec_list *const f0B11_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B11->then_instructions;

               ir_expression *const r0B13 = rshift(r0AFD, r0B10);
               ir_expression *const r0B14 = neg(r0B10);
               ir_expression *const r0B15 = bit_and(r0B14, body.constant(int(31)));
               ir_expression *const r0B16 = lshift(r0AFD, r0B15);
               ir_expression *const r0B17 = nequal(r0B16, body.constant(0u));
               ir_expression *const r0B18 = expr(ir_unop_b2i, r0B17);
               ir_expression *const r0B19 = expr(ir_unop_i2u, r0B18);
               body.emit(assign(r0AFD, bit_or(r0B13, r0B19), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0B11->else_instructions;

               ir_expression *const r0B1A = nequal(r0AFD, body.constant(0u));
               ir_expression *const r0B1B = expr(ir_unop_b2i, r0B1A);
               body.emit(assign(r0AFD, expr(ir_unop_i2u, r0B1B), 0x01));


            body.instructions = f0B11_parent_instructions;
            body.emit(f0B11);

            /* END IF */

            body.emit(assign(r0AFC, body.constant(int(0)), 0x01));

            ir_expression *const r0B1C = expr(ir_unop_u2i, r0AFD);
            body.emit(assign(r0B00, bit_and(r0B1C, body.constant(int(127))), 0x01));


         body.instructions = f0B0E_parent_instructions;
         body.emit(f0B0E);

         /* END IF */


      body.instructions = f0B05_parent_instructions;
      body.emit(f0B05);

      /* END IF */


   body.instructions = f0B02_parent_instructions;
   body.emit(f0B02);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0B1D = new(mem_ctx) ir_if(operand(r0AFE).val);
   exec_list *const f0B1D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B1D->then_instructions;

      ir_expression *const r0B1E = add(r0AFD, body.constant(64u));
      body.emit(assign(r0AFD, rshift(r0B1E, body.constant(int(7))), 0x01));

      ir_expression *const r0B1F = bit_xor(r0B00, body.constant(int(64)));
      ir_expression *const r0B20 = equal(r0B1F, body.constant(int(0)));
      ir_expression *const r0B21 = expr(ir_unop_b2i, r0B20);
      ir_expression *const r0B22 = expr(ir_unop_i2u, r0B21);
      ir_expression *const r0B23 = expr(ir_unop_bit_not, r0B22);
      body.emit(assign(r0AFD, bit_and(r0AFD, r0B23), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B25 = equal(r0AFD, body.constant(0u));
      ir_if *f0B24 = new(mem_ctx) ir_if(operand(r0B25).val);
      exec_list *const f0B24_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B24->then_instructions;

         body.emit(assign(r0AFC, body.constant(int(0)), 0x01));


      body.instructions = f0B24_parent_instructions;
      body.emit(f0B24);

      /* END IF */

      ir_expression *const r0B26 = lshift(r0AFB, body.constant(int(31)));
      ir_expression *const r0B27 = expr(ir_unop_i2u, r0AFC);
      ir_expression *const r0B28 = lshift(r0B27, body.constant(int(23)));
      ir_expression *const r0B29 = add(r0B26, r0B28);
      ir_expression *const r0B2A = add(r0B29, r0AFD);
      body.emit(assign(r0AFF, expr(ir_unop_bitcast_u2f, r0B2A), 0x01));

      body.emit(assign(r0AFE, body.constant(false), 0x01));


   body.instructions = f0B1D_parent_instructions;
   body.emit(f0B1D);

   /* END IF */

   body.emit(ret(r0AFF));

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

   ir_variable *const r0B2B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B2B);
   ir_variable *const r0B2C = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B2D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0B2D);
   body.emit(assign(r0B2D, body.constant(0u), 0x01));

   ir_variable *const r0B2E = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0B2E, swizzle_x(r0B2B), 0x01));

   ir_variable *const r0B2F = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B2F, bit_and(swizzle_y(r0B2B), body.constant(1048575u)), 0x01));

   ir_variable *const r0B30 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B31 = rshift(swizzle_y(r0B2B), body.constant(int(20)));
   ir_expression *const r0B32 = bit_and(r0B31, body.constant(2047u));
   body.emit(assign(r0B30, expr(ir_unop_u2i, r0B32), 0x01));

   ir_variable *const r0B33 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B33, rshift(swizzle_y(r0B2B), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B35 = equal(r0B30, body.constant(int(2047)));
   ir_if *f0B34 = new(mem_ctx) ir_if(operand(r0B35).val);
   exec_list *const f0B34_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B34->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B37 = bit_or(r0B2F, swizzle_x(r0B2B));
      ir_expression *const r0B38 = nequal(r0B37, body.constant(0u));
      ir_if *f0B36 = new(mem_ctx) ir_if(operand(r0B38).val);
      exec_list *const f0B36_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B36->then_instructions;

         ir_variable *const r0B39 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0B39, lshift(swizzle_x(r0B2B), body.constant(int(12))), 0x01));

         ir_expression *const r0B3A = lshift(swizzle_y(r0B2B), body.constant(int(12)));
         ir_expression *const r0B3B = rshift(swizzle_x(r0B2B), body.constant(int(20)));
         body.emit(assign(r0B2B, bit_or(r0B3A, r0B3B), 0x02));

         body.emit(assign(r0B2B, r0B39, 0x01));

         ir_expression *const r0B3C = lshift(r0B33, body.constant(int(31)));
         ir_expression *const r0B3D = bit_or(r0B3C, body.constant(2143289344u));
         ir_expression *const r0B3E = rshift(swizzle_y(r0B2B), body.constant(int(9)));
         ir_expression *const r0B3F = bit_or(r0B3D, r0B3E);
         body.emit(assign(r0B2C, expr(ir_unop_bitcast_u2f, r0B3F), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B36->else_instructions;

         ir_expression *const r0B40 = lshift(r0B33, body.constant(int(31)));
         ir_expression *const r0B41 = add(r0B40, body.constant(2139095040u));
         body.emit(assign(r0B2C, expr(ir_unop_bitcast_u2f, r0B41), 0x01));


      body.instructions = f0B36_parent_instructions;
      body.emit(f0B36);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B34->else_instructions;

      ir_variable *const r0B42 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B42);
      ir_variable *const r0B43 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0B43, rshift(r0B2F, body.constant(int(22))), 0x01));

      ir_expression *const r0B44 = lshift(r0B2F, body.constant(int(10)));
      ir_expression *const r0B45 = rshift(r0B2E, body.constant(int(22)));
      ir_expression *const r0B46 = bit_or(r0B44, r0B45);
      ir_expression *const r0B47 = lshift(r0B2E, body.constant(int(10)));
      ir_expression *const r0B48 = nequal(r0B47, body.constant(0u));
      ir_expression *const r0B49 = expr(ir_unop_b2i, r0B48);
      ir_expression *const r0B4A = expr(ir_unop_i2u, r0B49);
      body.emit(assign(r0B42, bit_or(r0B46, r0B4A), 0x01));

      body.emit(assign(r0B2D, r0B42, 0x01));

      /* IF CONDITION */
      ir_expression *const r0B4C = nequal(r0B30, body.constant(int(0)));
      ir_if *f0B4B = new(mem_ctx) ir_if(operand(r0B4C).val);
      exec_list *const f0B4B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B4B->then_instructions;

         body.emit(assign(r0B2D, bit_or(r0B42, body.constant(1073741824u)), 0x01));


      body.instructions = f0B4B_parent_instructions;
      body.emit(f0B4B);

      /* END IF */

      ir_variable *const r0B4D = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B4D, add(r0B30, body.constant(int(-897))), 0x01));

      ir_variable *const r0B4E = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B4E, r0B2D, 0x01));

      ir_variable *const r0B4F = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B4F, body.constant(true), 0x01));

      ir_variable *const r0B50 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B51 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B51);
      ir_expression *const r0B52 = bit_and(r0B2D, body.constant(127u));
      body.emit(assign(r0B51, expr(ir_unop_u2i, r0B52), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B54 = expr(ir_unop_i2u, r0B4D);
      ir_expression *const r0B55 = gequal(r0B54, body.constant(253u));
      ir_if *f0B53 = new(mem_ctx) ir_if(operand(r0B55).val);
      exec_list *const f0B53_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B53->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B57 = less(body.constant(int(253)), r0B4D);
         ir_expression *const r0B58 = equal(r0B4D, body.constant(int(253)));
         ir_expression *const r0B59 = expr(ir_unop_u2i, r0B2D);
         ir_expression *const r0B5A = less(r0B59, body.constant(int(-64)));
         ir_expression *const r0B5B = logic_and(r0B58, r0B5A);
         ir_expression *const r0B5C = logic_or(r0B57, r0B5B);
         ir_if *f0B56 = new(mem_ctx) ir_if(operand(r0B5C).val);
         exec_list *const f0B56_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B56->then_instructions;

            ir_expression *const r0B5D = lshift(r0B33, body.constant(int(31)));
            ir_expression *const r0B5E = add(r0B5D, body.constant(2139095040u));
            body.emit(assign(r0B50, expr(ir_unop_bitcast_u2f, r0B5E), 0x01));

            body.emit(assign(r0B4F, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B56->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0B60 = less(r0B4D, body.constant(int(0)));
            ir_if *f0B5F = new(mem_ctx) ir_if(operand(r0B60).val);
            exec_list *const f0B5F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B5F->then_instructions;

               ir_variable *const r0B61 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0B61, neg(r0B4D), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B63 = less(r0B61, body.constant(int(32)));
               ir_if *f0B62 = new(mem_ctx) ir_if(operand(r0B63).val);
               exec_list *const f0B62_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B62->then_instructions;

                  ir_expression *const r0B64 = rshift(r0B2D, r0B61);
                  ir_expression *const r0B65 = neg(r0B61);
                  ir_expression *const r0B66 = bit_and(r0B65, body.constant(int(31)));
                  ir_expression *const r0B67 = lshift(r0B2D, r0B66);
                  ir_expression *const r0B68 = nequal(r0B67, body.constant(0u));
                  ir_expression *const r0B69 = expr(ir_unop_b2i, r0B68);
                  ir_expression *const r0B6A = expr(ir_unop_i2u, r0B69);
                  body.emit(assign(r0B4E, bit_or(r0B64, r0B6A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0B62->else_instructions;

                  ir_expression *const r0B6B = nequal(r0B4E, body.constant(0u));
                  ir_expression *const r0B6C = expr(ir_unop_b2i, r0B6B);
                  body.emit(assign(r0B4E, expr(ir_unop_i2u, r0B6C), 0x01));


               body.instructions = f0B62_parent_instructions;
               body.emit(f0B62);

               /* END IF */

               body.emit(assign(r0B4D, body.constant(int(0)), 0x01));

               ir_expression *const r0B6D = expr(ir_unop_u2i, r0B4E);
               body.emit(assign(r0B51, bit_and(r0B6D, body.constant(int(127))), 0x01));


            body.instructions = f0B5F_parent_instructions;
            body.emit(f0B5F);

            /* END IF */


         body.instructions = f0B56_parent_instructions;
         body.emit(f0B56);

         /* END IF */


      body.instructions = f0B53_parent_instructions;
      body.emit(f0B53);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B6E = new(mem_ctx) ir_if(operand(r0B4F).val);
      exec_list *const f0B6E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B6E->then_instructions;

         ir_expression *const r0B6F = add(r0B4E, body.constant(64u));
         body.emit(assign(r0B4E, rshift(r0B6F, body.constant(int(7))), 0x01));

         ir_expression *const r0B70 = bit_xor(r0B51, body.constant(int(64)));
         ir_expression *const r0B71 = equal(r0B70, body.constant(int(0)));
         ir_expression *const r0B72 = expr(ir_unop_b2i, r0B71);
         ir_expression *const r0B73 = expr(ir_unop_i2u, r0B72);
         ir_expression *const r0B74 = expr(ir_unop_bit_not, r0B73);
         body.emit(assign(r0B4E, bit_and(r0B4E, r0B74), 0x01));

         /* IF CONDITION */
         ir_expression *const r0B76 = equal(r0B4E, body.constant(0u));
         ir_if *f0B75 = new(mem_ctx) ir_if(operand(r0B76).val);
         exec_list *const f0B75_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B75->then_instructions;

            body.emit(assign(r0B4D, body.constant(int(0)), 0x01));


         body.instructions = f0B75_parent_instructions;
         body.emit(f0B75);

         /* END IF */

         ir_expression *const r0B77 = lshift(r0B33, body.constant(int(31)));
         ir_expression *const r0B78 = expr(ir_unop_i2u, r0B4D);
         ir_expression *const r0B79 = lshift(r0B78, body.constant(int(23)));
         ir_expression *const r0B7A = add(r0B77, r0B79);
         ir_expression *const r0B7B = add(r0B7A, r0B4E);
         body.emit(assign(r0B50, expr(ir_unop_bitcast_u2f, r0B7B), 0x01));

         body.emit(assign(r0B4F, body.constant(false), 0x01));


      body.instructions = f0B6E_parent_instructions;
      body.emit(f0B6E);

      /* END IF */

      body.emit(assign(r0B2C, r0B50, 0x01));


   body.instructions = f0B34_parent_instructions;
   body.emit(f0B34);

   /* END IF */

   body.emit(ret(r0B2C));

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

   ir_variable *const r0B7C = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0B7C);
   ir_variable *const r0B7D = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B7D, body.constant(true), 0x01));

   ir_variable *const r0B7E = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B7F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B7F);
   ir_variable *const r0B80 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B80);
   ir_variable *const r0B81 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B81);
   ir_variable *const r0B82 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0B82, expr(ir_unop_bitcast_f2u, r0B7C), 0x01));

   ir_variable *const r0B83 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B83, bit_and(r0B82, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B81, r0B83, 0x01));

   ir_variable *const r0B84 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B85 = rshift(r0B82, body.constant(int(23)));
   ir_expression *const r0B86 = bit_and(r0B85, body.constant(255u));
   body.emit(assign(r0B84, expr(ir_unop_u2i, r0B86), 0x01));

   body.emit(assign(r0B80, r0B84, 0x01));

   body.emit(assign(r0B7F, rshift(r0B82, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B88 = equal(r0B84, body.constant(int(255)));
   ir_if *f0B87 = new(mem_ctx) ir_if(operand(r0B88).val);
   exec_list *const f0B87_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B87->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B8A = nequal(r0B83, body.constant(0u));
      ir_if *f0B89 = new(mem_ctx) ir_if(operand(r0B8A).val);
      exec_list *const f0B89_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B89->then_instructions;

         ir_variable *const r0B8B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B8B, lshift(r0B82, body.constant(int(9))), 0x01));

         ir_variable *const r0B8C = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B8D = lshift(r0B8B, body.constant(int(20)));
         body.emit(assign(r0B8C, bit_or(r0B8D, body.constant(0u)), 0x01));

         ir_expression *const r0B8E = rshift(r0B8B, body.constant(int(12)));
         ir_expression *const r0B8F = lshift(r0B7F, body.constant(int(31)));
         ir_expression *const r0B90 = bit_or(r0B8F, body.constant(2146959360u));
         body.emit(assign(r0B8C, bit_or(r0B8E, r0B90), 0x02));

         body.emit(assign(r0B7E, r0B8C, 0x03));

         body.emit(assign(r0B7D, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B89->else_instructions;

         ir_variable *const r0B91 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B91);
         ir_expression *const r0B92 = lshift(r0B7F, body.constant(int(31)));
         body.emit(assign(r0B91, add(r0B92, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B91, body.constant(0u), 0x01));

         body.emit(assign(r0B7E, r0B91, 0x03));

         body.emit(assign(r0B7D, body.constant(false), 0x01));


      body.instructions = f0B89_parent_instructions;
      body.emit(f0B89);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B87->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B94 = equal(r0B84, body.constant(int(0)));
      ir_if *f0B93 = new(mem_ctx) ir_if(operand(r0B94).val);
      exec_list *const f0B93_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B93->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B96 = equal(r0B83, body.constant(0u));
         ir_if *f0B95 = new(mem_ctx) ir_if(operand(r0B96).val);
         exec_list *const f0B95_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B95->then_instructions;

            ir_variable *const r0B97 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B97);
            body.emit(assign(r0B97, lshift(r0B7F, body.constant(int(31))), 0x02));

            body.emit(assign(r0B97, body.constant(0u), 0x01));

            body.emit(assign(r0B7E, r0B97, 0x03));

            body.emit(assign(r0B7D, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B95->else_instructions;

            ir_variable *const r0B98 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0B98, r0B83, 0x01));

            ir_variable *const r0B99 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0B9A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0B9A);
            /* IF CONDITION */
            ir_expression *const r0B9C = equal(r0B83, body.constant(0u));
            ir_if *f0B9B = new(mem_ctx) ir_if(operand(r0B9C).val);
            exec_list *const f0B9B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B9B->then_instructions;

               body.emit(assign(r0B99, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0B9B->else_instructions;

               body.emit(assign(r0B9A, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B9E = bit_and(r0B83, body.constant(4294901760u));
               ir_expression *const r0B9F = equal(r0B9E, body.constant(0u));
               ir_if *f0B9D = new(mem_ctx) ir_if(operand(r0B9F).val);
               exec_list *const f0B9D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B9D->then_instructions;

                  body.emit(assign(r0B9A, body.constant(int(16)), 0x01));

                  body.emit(assign(r0B98, lshift(r0B83, body.constant(int(16))), 0x01));


               body.instructions = f0B9D_parent_instructions;
               body.emit(f0B9D);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0BA1 = bit_and(r0B98, body.constant(4278190080u));
               ir_expression *const r0BA2 = equal(r0BA1, body.constant(0u));
               ir_if *f0BA0 = new(mem_ctx) ir_if(operand(r0BA2).val);
               exec_list *const f0BA0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BA0->then_instructions;

                  body.emit(assign(r0B9A, add(r0B9A, body.constant(int(8))), 0x01));

                  body.emit(assign(r0B98, lshift(r0B98, body.constant(int(8))), 0x01));


               body.instructions = f0BA0_parent_instructions;
               body.emit(f0BA0);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0BA4 = bit_and(r0B98, body.constant(4026531840u));
               ir_expression *const r0BA5 = equal(r0BA4, body.constant(0u));
               ir_if *f0BA3 = new(mem_ctx) ir_if(operand(r0BA5).val);
               exec_list *const f0BA3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BA3->then_instructions;

                  body.emit(assign(r0B9A, add(r0B9A, body.constant(int(4))), 0x01));

                  body.emit(assign(r0B98, lshift(r0B98, body.constant(int(4))), 0x01));


               body.instructions = f0BA3_parent_instructions;
               body.emit(f0BA3);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0BA7 = bit_and(r0B98, body.constant(3221225472u));
               ir_expression *const r0BA8 = equal(r0BA7, body.constant(0u));
               ir_if *f0BA6 = new(mem_ctx) ir_if(operand(r0BA8).val);
               exec_list *const f0BA6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BA6->then_instructions;

                  body.emit(assign(r0B9A, add(r0B9A, body.constant(int(2))), 0x01));

                  body.emit(assign(r0B98, lshift(r0B98, body.constant(int(2))), 0x01));


               body.instructions = f0BA6_parent_instructions;
               body.emit(f0BA6);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0BAA = bit_and(r0B98, body.constant(2147483648u));
               ir_expression *const r0BAB = equal(r0BAA, body.constant(0u));
               ir_if *f0BA9 = new(mem_ctx) ir_if(operand(r0BAB).val);
               exec_list *const f0BA9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BA9->then_instructions;

                  body.emit(assign(r0B9A, add(r0B9A, body.constant(int(1))), 0x01));


               body.instructions = f0BA9_parent_instructions;
               body.emit(f0BA9);

               /* END IF */

               body.emit(assign(r0B99, r0B9A, 0x01));


            body.instructions = f0B9B_parent_instructions;
            body.emit(f0B9B);

            /* END IF */

            ir_variable *const r0BAC = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0BAC, add(r0B99, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B81, lshift(r0B83, r0BAC), 0x01));

            body.emit(assign(r0B80, sub(body.constant(int(1)), r0BAC), 0x01));

            body.emit(assign(r0B80, add(r0B80, body.constant(int(-1))), 0x01));


         body.instructions = f0B95_parent_instructions;
         body.emit(f0B95);

         /* END IF */


      body.instructions = f0B93_parent_instructions;
      body.emit(f0B93);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0BAD = new(mem_ctx) ir_if(operand(r0B7D).val);
      exec_list *const f0BAD_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BAD->then_instructions;

         ir_variable *const r0BAE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0BAE);
         ir_expression *const r0BAF = lshift(r0B7F, body.constant(int(31)));
         ir_expression *const r0BB0 = add(r0B80, body.constant(int(896)));
         ir_expression *const r0BB1 = expr(ir_unop_i2u, r0BB0);
         ir_expression *const r0BB2 = lshift(r0BB1, body.constant(int(20)));
         ir_expression *const r0BB3 = add(r0BAF, r0BB2);
         ir_expression *const r0BB4 = rshift(r0B81, body.constant(int(3)));
         body.emit(assign(r0BAE, add(r0BB3, r0BB4), 0x02));

         ir_expression *const r0BB5 = lshift(r0B81, body.constant(int(29)));
         body.emit(assign(r0BAE, bit_or(r0BB5, body.constant(0u)), 0x01));

         body.emit(assign(r0B7E, r0BAE, 0x03));

         body.emit(assign(r0B7D, body.constant(false), 0x01));


      body.instructions = f0BAD_parent_instructions;
      body.emit(f0BAD);

      /* END IF */


   body.instructions = f0B87_parent_instructions;
   body.emit(f0B87);

   /* END IF */

   body.emit(ret(r0B7E));

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

   ir_variable *const r0BB6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BB6);
   ir_variable *const r0BB7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BB7);
   ir_variable *const r0BB8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0BB8);
   ir_variable *const r0BB9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0BB9);
   ir_variable *const r0BBA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0BBA);
   ir_variable *const r0BBB = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0BBB);
   ir_variable *const r0BBC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BBC);
   ir_variable *const r0BBD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BBD);
   ir_variable *const r0BBE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BBE);
   ir_variable *const r0BBF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0BBF);
   ir_variable *const r0BC0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0BC0);
   ir_variable *const r0BC1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BC1, add(r0BB8, r0BBB), 0x01));

   ir_variable *const r0BC2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0BC3 = less(r0BC1, r0BB8);
   ir_expression *const r0BC4 = expr(ir_unop_b2i, r0BC3);
   body.emit(assign(r0BC2, expr(ir_unop_i2u, r0BC4), 0x01));

   ir_variable *const r0BC5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BC5, add(r0BB7, r0BBA), 0x01));

   body.emit(assign(r0BC0, add(r0BC5, r0BC2), 0x01));

   ir_expression *const r0BC6 = add(r0BB6, r0BB9);
   ir_expression *const r0BC7 = less(r0BC0, r0BC2);
   ir_expression *const r0BC8 = expr(ir_unop_b2i, r0BC7);
   ir_expression *const r0BC9 = expr(ir_unop_i2u, r0BC8);
   body.emit(assign(r0BBF, add(r0BC6, r0BC9), 0x01));

   ir_expression *const r0BCA = less(r0BC5, r0BB7);
   ir_expression *const r0BCB = expr(ir_unop_b2i, r0BCA);
   ir_expression *const r0BCC = expr(ir_unop_i2u, r0BCB);
   body.emit(assign(r0BBF, add(r0BBF, r0BCC), 0x01));

   body.emit(assign(r0BBE, r0BC1, 0x01));

   body.emit(assign(r0BBD, r0BC0, 0x01));

   body.emit(assign(r0BBC, r0BBF, 0x01));

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

   ir_variable *const r0BCD = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BCD);
   ir_variable *const r0BCE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BCE);
   ir_variable *const r0BCF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0BCF);
   ir_variable *const r0BD0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0BD0);
   ir_variable *const r0BD1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0BD1);
   ir_variable *const r0BD2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0BD2);
   ir_variable *const r0BD3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BD3);
   ir_variable *const r0BD4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BD4);
   ir_variable *const r0BD5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BD5);
   ir_variable *const r0BD6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0BD6);
   ir_variable *const r0BD7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0BD8 = less(r0BCF, r0BD2);
   ir_expression *const r0BD9 = expr(ir_unop_b2i, r0BD8);
   body.emit(assign(r0BD7, expr(ir_unop_i2u, r0BD9), 0x01));

   ir_variable *const r0BDA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BDA, sub(r0BCE, r0BD1), 0x01));

   ir_expression *const r0BDB = sub(r0BCD, r0BD0);
   ir_expression *const r0BDC = less(r0BDA, r0BD7);
   ir_expression *const r0BDD = expr(ir_unop_b2i, r0BDC);
   ir_expression *const r0BDE = expr(ir_unop_i2u, r0BDD);
   body.emit(assign(r0BD6, sub(r0BDB, r0BDE), 0x01));

   ir_expression *const r0BDF = less(r0BCE, r0BD1);
   ir_expression *const r0BE0 = expr(ir_unop_b2i, r0BDF);
   ir_expression *const r0BE1 = expr(ir_unop_i2u, r0BE0);
   body.emit(assign(r0BD6, sub(r0BD6, r0BE1), 0x01));

   body.emit(assign(r0BD5, sub(r0BCF, r0BD2), 0x01));

   body.emit(assign(r0BD4, sub(r0BDA, r0BD7), 0x01));

   body.emit(assign(r0BD3, r0BD6, 0x01));

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

   ir_variable *const r0BE2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BE2);
   ir_variable *const r0BE3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BE3);
   ir_variable *const r0BE4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0BE4);
   ir_variable *const r0BE5 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0BE6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0BE6);
   ir_variable *const r0BE7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0BE7);
   ir_variable *const r0BE8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0BE8);
   ir_variable *const r0BE9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0BE9);
   body.emit(assign(r0BE8, body.constant(0u), 0x01));

   body.emit(assign(r0BE7, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BEB = gequal(r0BE2, r0BE4);
   ir_if *f0BEA = new(mem_ctx) ir_if(operand(r0BEB).val);
   exec_list *const f0BEA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BEA->then_instructions;

      body.emit(assign(r0BE5, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BEA->else_instructions;

      body.emit(assign(r0BE9, rshift(r0BE4, body.constant(int(16))), 0x01));

      ir_variable *const r0BEC = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BEE = lshift(r0BE9, body.constant(int(16)));
      ir_expression *const r0BEF = gequal(r0BE2, r0BEE);
      ir_if *f0BED = new(mem_ctx) ir_if(operand(r0BEF).val);
      exec_list *const f0BED_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BED->then_instructions;

         body.emit(assign(r0BEC, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BED->else_instructions;

         ir_expression *const r0BF0 = expr(ir_binop_div, r0BE2, r0BE9);
         body.emit(assign(r0BEC, lshift(r0BF0, body.constant(int(16))), 0x01));


      body.instructions = f0BED_parent_instructions;
      body.emit(f0BED);

      /* END IF */

      body.emit(assign(r0BE6, r0BEC, 0x01));

      ir_variable *const r0BF1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0BF1);
      ir_variable *const r0BF2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0BF2);
      ir_variable *const r0BF3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BF3);
      ir_variable *const r0BF4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BF4, bit_and(r0BE4, body.constant(65535u)), 0x01));

      ir_variable *const r0BF5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BF5, rshift(r0BE4, body.constant(int(16))), 0x01));

      ir_variable *const r0BF6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BF6, bit_and(r0BEC, body.constant(65535u)), 0x01));

      ir_variable *const r0BF7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BF7, rshift(r0BEC, body.constant(int(16))), 0x01));

      ir_variable *const r0BF8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BF8, mul(r0BF5, r0BF6), 0x01));

      ir_expression *const r0BF9 = mul(r0BF4, r0BF7);
      body.emit(assign(r0BF2, add(r0BF9, r0BF8), 0x01));

      ir_expression *const r0BFA = mul(r0BF5, r0BF7);
      ir_expression *const r0BFB = less(r0BF2, r0BF8);
      ir_expression *const r0BFC = expr(ir_unop_b2i, r0BFB);
      ir_expression *const r0BFD = expr(ir_unop_i2u, r0BFC);
      ir_expression *const r0BFE = lshift(r0BFD, body.constant(int(16)));
      ir_expression *const r0BFF = rshift(r0BF2, body.constant(int(16)));
      ir_expression *const r0C00 = add(r0BFE, r0BFF);
      body.emit(assign(r0BF1, add(r0BFA, r0C00), 0x01));

      body.emit(assign(r0BF2, lshift(r0BF2, body.constant(int(16))), 0x01));

      ir_expression *const r0C01 = mul(r0BF4, r0BF6);
      body.emit(assign(r0BF3, add(r0C01, r0BF2), 0x01));

      ir_expression *const r0C02 = less(r0BF3, r0BF2);
      ir_expression *const r0C03 = expr(ir_unop_b2i, r0C02);
      ir_expression *const r0C04 = expr(ir_unop_i2u, r0C03);
      body.emit(assign(r0BF1, add(r0BF1, r0C04), 0x01));

      ir_expression *const r0C05 = sub(r0BE2, r0BF1);
      ir_expression *const r0C06 = less(r0BE3, r0BF3);
      ir_expression *const r0C07 = expr(ir_unop_b2i, r0C06);
      ir_expression *const r0C08 = expr(ir_unop_i2u, r0C07);
      body.emit(assign(r0BE8, sub(r0C05, r0C08), 0x01));

      body.emit(assign(r0BE7, sub(r0BE3, r0BF3), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0C09 = new(mem_ctx) ir_loop();
      exec_list *const f0C09_parent_instructions = body.instructions;

         body.instructions = &f0C09->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0C0B = expr(ir_unop_u2i, r0BE8);
         ir_expression *const r0C0C = gequal(r0C0B, body.constant(int(0)));
         ir_if *f0C0A = new(mem_ctx) ir_if(operand(r0C0C).val);
         exec_list *const f0C0A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C0A->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0C0A_parent_instructions;
         body.emit(f0C0A);

         /* END IF */

         body.emit(assign(r0BE6, add(r0BE6, body.constant(4294901760u)), 0x01));

         ir_variable *const r0C0D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0C0E = lshift(r0BE4, body.constant(int(16)));
         body.emit(assign(r0C0D, add(r0BE7, r0C0E), 0x01));

         ir_expression *const r0C0F = add(r0BE8, r0BE9);
         ir_expression *const r0C10 = less(r0C0D, r0BE7);
         ir_expression *const r0C11 = expr(ir_unop_b2i, r0C10);
         ir_expression *const r0C12 = expr(ir_unop_i2u, r0C11);
         body.emit(assign(r0BE8, add(r0C0F, r0C12), 0x01));

         body.emit(assign(r0BE7, r0C0D, 0x01));

      /* LOOP END */

      body.instructions = f0C09_parent_instructions;
      body.emit(f0C09);

      ir_expression *const r0C13 = lshift(r0BE8, body.constant(int(16)));
      ir_expression *const r0C14 = rshift(r0BE7, body.constant(int(16)));
      body.emit(assign(r0BE8, bit_or(r0C13, r0C14), 0x01));

      ir_variable *const r0C15 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0C17 = lshift(r0BE9, body.constant(int(16)));
      ir_expression *const r0C18 = gequal(r0BE8, r0C17);
      ir_if *f0C16 = new(mem_ctx) ir_if(operand(r0C18).val);
      exec_list *const f0C16_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C16->then_instructions;

         body.emit(assign(r0C15, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C16->else_instructions;

         body.emit(assign(r0C15, expr(ir_binop_div, r0BE8, r0BE9), 0x01));


      body.instructions = f0C16_parent_instructions;
      body.emit(f0C16);

      /* END IF */

      body.emit(assign(r0BE6, bit_or(r0BE6, r0C15), 0x01));

      body.emit(assign(r0BE5, r0BE6, 0x01));


   body.instructions = f0BEA_parent_instructions;
   body.emit(f0BEA);

   /* END IF */

   body.emit(ret(r0BE5));

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

   ir_variable *const r0C19 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C19);
   ir_variable *const r0C1A = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0C1A, r0C19, 0x03));

   ir_variable *const r0C1B = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0C1C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0C1C);
   body.emit(assign(r0C1C, body.constant(0u), 0x01));

   ir_variable *const r0C1D = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0C1D, bit_and(swizzle_y(r0C19), body.constant(1048575u)), 0x01));

   ir_variable *const r0C1E = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0C1F = rshift(swizzle_y(r0C19), body.constant(int(20)));
   ir_expression *const r0C20 = bit_and(r0C1F, body.constant(2047u));
   body.emit(assign(r0C1E, expr(ir_unop_u2i, r0C20), 0x01));

   ir_variable *const r0C21 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0C21, rshift(swizzle_y(r0C19), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C23 = equal(r0C1E, body.constant(int(2047)));
   ir_if *f0C22 = new(mem_ctx) ir_if(operand(r0C23).val);
   exec_list *const f0C22_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C22->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C25 = bit_or(r0C1D, swizzle_x(r0C19));
      ir_expression *const r0C26 = nequal(r0C25, body.constant(0u));
      ir_if *f0C24 = new(mem_ctx) ir_if(operand(r0C26).val);
      exec_list *const f0C24_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C24->then_instructions;

         ir_expression *const r0C27 = lshift(swizzle_y(r0C19), body.constant(int(12)));
         ir_expression *const r0C28 = rshift(swizzle_x(r0C19), body.constant(int(20)));
         body.emit(assign(r0C1A, bit_or(r0C27, r0C28), 0x02));

         body.emit(assign(r0C1A, lshift(swizzle_x(r0C19), body.constant(int(12))), 0x01));

         ir_expression *const r0C29 = lshift(r0C21, body.constant(int(31)));
         ir_expression *const r0C2A = bit_or(r0C29, body.constant(2143289344u));
         ir_expression *const r0C2B = rshift(swizzle_y(r0C1A), body.constant(int(9)));
         ir_expression *const r0C2C = bit_or(r0C2A, r0C2B);
         body.emit(assign(r0C1B, expr(ir_unop_bitcast_u2f, r0C2C), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C24->else_instructions;

         ir_expression *const r0C2D = lshift(r0C21, body.constant(int(31)));
         ir_expression *const r0C2E = add(r0C2D, body.constant(2139095040u));
         body.emit(assign(r0C1B, expr(ir_unop_bitcast_u2f, r0C2E), 0x01));


      body.instructions = f0C24_parent_instructions;
      body.emit(f0C24);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C22->else_instructions;

      ir_variable *const r0C2F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0C2F);
      ir_variable *const r0C30 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0C30, rshift(r0C1D, body.constant(int(22))), 0x01));

      ir_expression *const r0C31 = lshift(r0C1D, body.constant(int(10)));
      ir_expression *const r0C32 = rshift(swizzle_x(r0C19), body.constant(int(22)));
      ir_expression *const r0C33 = bit_or(r0C31, r0C32);
      ir_expression *const r0C34 = lshift(swizzle_x(r0C19), body.constant(int(10)));
      ir_expression *const r0C35 = nequal(r0C34, body.constant(0u));
      ir_expression *const r0C36 = expr(ir_unop_b2i, r0C35);
      ir_expression *const r0C37 = expr(ir_unop_i2u, r0C36);
      body.emit(assign(r0C2F, bit_or(r0C33, r0C37), 0x01));

      body.emit(assign(r0C1C, r0C2F, 0x01));

      /* IF CONDITION */
      ir_expression *const r0C39 = nequal(r0C1E, body.constant(int(0)));
      ir_if *f0C38 = new(mem_ctx) ir_if(operand(r0C39).val);
      exec_list *const f0C38_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C38->then_instructions;

         body.emit(assign(r0C1C, bit_or(r0C2F, body.constant(1073741824u)), 0x01));


      body.instructions = f0C38_parent_instructions;
      body.emit(f0C38);

      /* END IF */

      ir_variable *const r0C3A = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0C3A, add(r0C1E, body.constant(int(-897))), 0x01));

      ir_variable *const r0C3B = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0C3B, r0C1C, 0x01));

      ir_variable *const r0C3C = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0C3C, body.constant(true), 0x01));

      ir_variable *const r0C3D = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0C3E = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0C3E);
      ir_expression *const r0C3F = bit_and(r0C1C, body.constant(127u));
      body.emit(assign(r0C3E, expr(ir_unop_u2i, r0C3F), 0x01));

      /* IF CONDITION */
      ir_expression *const r0C41 = expr(ir_unop_i2u, r0C3A);
      ir_expression *const r0C42 = gequal(r0C41, body.constant(253u));
      ir_if *f0C40 = new(mem_ctx) ir_if(operand(r0C42).val);
      exec_list *const f0C40_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C40->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C44 = less(body.constant(int(253)), r0C3A);
         ir_expression *const r0C45 = equal(r0C3A, body.constant(int(253)));
         ir_expression *const r0C46 = expr(ir_unop_u2i, r0C1C);
         ir_expression *const r0C47 = less(r0C46, body.constant(int(-64)));
         ir_expression *const r0C48 = logic_and(r0C45, r0C47);
         ir_expression *const r0C49 = logic_or(r0C44, r0C48);
         ir_if *f0C43 = new(mem_ctx) ir_if(operand(r0C49).val);
         exec_list *const f0C43_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C43->then_instructions;

            ir_expression *const r0C4A = lshift(r0C21, body.constant(int(31)));
            ir_expression *const r0C4B = add(r0C4A, body.constant(2139095040u));
            body.emit(assign(r0C3D, expr(ir_unop_bitcast_u2f, r0C4B), 0x01));

            body.emit(assign(r0C3C, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C43->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0C4D = less(r0C3A, body.constant(int(0)));
            ir_if *f0C4C = new(mem_ctx) ir_if(operand(r0C4D).val);
            exec_list *const f0C4C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C4C->then_instructions;

               ir_variable *const r0C4E = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0C4E, neg(r0C3A), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C50 = less(r0C4E, body.constant(int(32)));
               ir_if *f0C4F = new(mem_ctx) ir_if(operand(r0C50).val);
               exec_list *const f0C4F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C4F->then_instructions;

                  ir_expression *const r0C51 = rshift(r0C1C, r0C4E);
                  ir_expression *const r0C52 = neg(r0C4E);
                  ir_expression *const r0C53 = bit_and(r0C52, body.constant(int(31)));
                  ir_expression *const r0C54 = lshift(r0C1C, r0C53);
                  ir_expression *const r0C55 = nequal(r0C54, body.constant(0u));
                  ir_expression *const r0C56 = expr(ir_unop_b2i, r0C55);
                  ir_expression *const r0C57 = expr(ir_unop_i2u, r0C56);
                  body.emit(assign(r0C3B, bit_or(r0C51, r0C57), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0C4F->else_instructions;

                  ir_expression *const r0C58 = nequal(r0C3B, body.constant(0u));
                  ir_expression *const r0C59 = expr(ir_unop_b2i, r0C58);
                  body.emit(assign(r0C3B, expr(ir_unop_i2u, r0C59), 0x01));


               body.instructions = f0C4F_parent_instructions;
               body.emit(f0C4F);

               /* END IF */

               body.emit(assign(r0C3A, body.constant(int(0)), 0x01));

               ir_expression *const r0C5A = expr(ir_unop_u2i, r0C3B);
               body.emit(assign(r0C3E, bit_and(r0C5A, body.constant(int(127))), 0x01));


            body.instructions = f0C4C_parent_instructions;
            body.emit(f0C4C);

            /* END IF */


         body.instructions = f0C43_parent_instructions;
         body.emit(f0C43);

         /* END IF */


      body.instructions = f0C40_parent_instructions;
      body.emit(f0C40);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C5B = new(mem_ctx) ir_if(operand(r0C3C).val);
      exec_list *const f0C5B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C5B->then_instructions;

         ir_expression *const r0C5C = add(r0C3B, body.constant(64u));
         body.emit(assign(r0C3B, rshift(r0C5C, body.constant(int(7))), 0x01));

         ir_expression *const r0C5D = bit_xor(r0C3E, body.constant(int(64)));
         ir_expression *const r0C5E = equal(r0C5D, body.constant(int(0)));
         ir_expression *const r0C5F = expr(ir_unop_b2i, r0C5E);
         ir_expression *const r0C60 = expr(ir_unop_i2u, r0C5F);
         ir_expression *const r0C61 = expr(ir_unop_bit_not, r0C60);
         body.emit(assign(r0C3B, bit_and(r0C3B, r0C61), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C63 = equal(r0C3B, body.constant(0u));
         ir_if *f0C62 = new(mem_ctx) ir_if(operand(r0C63).val);
         exec_list *const f0C62_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C62->then_instructions;

            body.emit(assign(r0C3A, body.constant(int(0)), 0x01));


         body.instructions = f0C62_parent_instructions;
         body.emit(f0C62);

         /* END IF */

         ir_expression *const r0C64 = lshift(r0C21, body.constant(int(31)));
         ir_expression *const r0C65 = expr(ir_unop_i2u, r0C3A);
         ir_expression *const r0C66 = lshift(r0C65, body.constant(int(23)));
         ir_expression *const r0C67 = add(r0C64, r0C66);
         ir_expression *const r0C68 = add(r0C67, r0C3B);
         body.emit(assign(r0C3D, expr(ir_unop_bitcast_u2f, r0C68), 0x01));

         body.emit(assign(r0C3C, body.constant(false), 0x01));


      body.instructions = f0C5B_parent_instructions;
      body.emit(f0C5B);

      /* END IF */

      body.emit(assign(r0C1B, r0C3D, 0x01));


   body.instructions = f0C22_parent_instructions;
   body.emit(f0C22);

   /* END IF */

   ir_variable *const r0C69 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C69, body.constant(true), 0x01));

   ir_variable *const r0C6A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C6B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C6B);
   ir_variable *const r0C6C = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C6C);
   ir_variable *const r0C6D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C6D);
   ir_variable *const r0C6E = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C6F = expr(ir_unop_sqrt, r0C1B);
   body.emit(assign(r0C6E, expr(ir_unop_bitcast_f2u, r0C6F), 0x01));

   ir_variable *const r0C70 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C70, bit_and(r0C6E, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C6D, r0C70, 0x01));

   ir_variable *const r0C71 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C72 = rshift(r0C6E, body.constant(int(23)));
   ir_expression *const r0C73 = bit_and(r0C72, body.constant(255u));
   body.emit(assign(r0C71, expr(ir_unop_u2i, r0C73), 0x01));

   body.emit(assign(r0C6C, r0C71, 0x01));

   body.emit(assign(r0C6B, rshift(r0C6E, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C75 = equal(r0C71, body.constant(int(255)));
   ir_if *f0C74 = new(mem_ctx) ir_if(operand(r0C75).val);
   exec_list *const f0C74_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C74->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C77 = nequal(r0C70, body.constant(0u));
      ir_if *f0C76 = new(mem_ctx) ir_if(operand(r0C77).val);
      exec_list *const f0C76_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C76->then_instructions;

         ir_variable *const r0C78 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C78, lshift(r0C6E, body.constant(int(9))), 0x01));

         ir_variable *const r0C79 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C7A = lshift(r0C78, body.constant(int(20)));
         body.emit(assign(r0C79, bit_or(r0C7A, body.constant(0u)), 0x01));

         ir_expression *const r0C7B = rshift(r0C78, body.constant(int(12)));
         ir_expression *const r0C7C = lshift(r0C6B, body.constant(int(31)));
         ir_expression *const r0C7D = bit_or(r0C7C, body.constant(2146959360u));
         body.emit(assign(r0C79, bit_or(r0C7B, r0C7D), 0x02));

         body.emit(assign(r0C6A, r0C79, 0x03));

         body.emit(assign(r0C69, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C76->else_instructions;

         ir_variable *const r0C7E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C7E);
         ir_expression *const r0C7F = lshift(r0C6B, body.constant(int(31)));
         body.emit(assign(r0C7E, add(r0C7F, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C7E, body.constant(0u), 0x01));

         body.emit(assign(r0C6A, r0C7E, 0x03));

         body.emit(assign(r0C69, body.constant(false), 0x01));


      body.instructions = f0C76_parent_instructions;
      body.emit(f0C76);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C74->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C81 = equal(r0C71, body.constant(int(0)));
      ir_if *f0C80 = new(mem_ctx) ir_if(operand(r0C81).val);
      exec_list *const f0C80_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C80->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C83 = equal(r0C70, body.constant(0u));
         ir_if *f0C82 = new(mem_ctx) ir_if(operand(r0C83).val);
         exec_list *const f0C82_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C82->then_instructions;

            ir_variable *const r0C84 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C84);
            body.emit(assign(r0C84, lshift(r0C6B, body.constant(int(31))), 0x02));

            body.emit(assign(r0C84, body.constant(0u), 0x01));

            body.emit(assign(r0C6A, r0C84, 0x03));

            body.emit(assign(r0C69, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C82->else_instructions;

            ir_variable *const r0C85 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0C85, r0C70, 0x01));

            ir_variable *const r0C86 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0C87 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0C87);
            /* IF CONDITION */
            ir_expression *const r0C89 = equal(r0C70, body.constant(0u));
            ir_if *f0C88 = new(mem_ctx) ir_if(operand(r0C89).val);
            exec_list *const f0C88_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C88->then_instructions;

               body.emit(assign(r0C86, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0C88->else_instructions;

               body.emit(assign(r0C87, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C8B = bit_and(r0C70, body.constant(4294901760u));
               ir_expression *const r0C8C = equal(r0C8B, body.constant(0u));
               ir_if *f0C8A = new(mem_ctx) ir_if(operand(r0C8C).val);
               exec_list *const f0C8A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C8A->then_instructions;

                  body.emit(assign(r0C87, body.constant(int(16)), 0x01));

                  body.emit(assign(r0C85, lshift(r0C70, body.constant(int(16))), 0x01));


               body.instructions = f0C8A_parent_instructions;
               body.emit(f0C8A);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C8E = bit_and(r0C85, body.constant(4278190080u));
               ir_expression *const r0C8F = equal(r0C8E, body.constant(0u));
               ir_if *f0C8D = new(mem_ctx) ir_if(operand(r0C8F).val);
               exec_list *const f0C8D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C8D->then_instructions;

                  body.emit(assign(r0C87, add(r0C87, body.constant(int(8))), 0x01));

                  body.emit(assign(r0C85, lshift(r0C85, body.constant(int(8))), 0x01));


               body.instructions = f0C8D_parent_instructions;
               body.emit(f0C8D);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C91 = bit_and(r0C85, body.constant(4026531840u));
               ir_expression *const r0C92 = equal(r0C91, body.constant(0u));
               ir_if *f0C90 = new(mem_ctx) ir_if(operand(r0C92).val);
               exec_list *const f0C90_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C90->then_instructions;

                  body.emit(assign(r0C87, add(r0C87, body.constant(int(4))), 0x01));

                  body.emit(assign(r0C85, lshift(r0C85, body.constant(int(4))), 0x01));


               body.instructions = f0C90_parent_instructions;
               body.emit(f0C90);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C94 = bit_and(r0C85, body.constant(3221225472u));
               ir_expression *const r0C95 = equal(r0C94, body.constant(0u));
               ir_if *f0C93 = new(mem_ctx) ir_if(operand(r0C95).val);
               exec_list *const f0C93_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C93->then_instructions;

                  body.emit(assign(r0C87, add(r0C87, body.constant(int(2))), 0x01));

                  body.emit(assign(r0C85, lshift(r0C85, body.constant(int(2))), 0x01));


               body.instructions = f0C93_parent_instructions;
               body.emit(f0C93);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C97 = bit_and(r0C85, body.constant(2147483648u));
               ir_expression *const r0C98 = equal(r0C97, body.constant(0u));
               ir_if *f0C96 = new(mem_ctx) ir_if(operand(r0C98).val);
               exec_list *const f0C96_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C96->then_instructions;

                  body.emit(assign(r0C87, add(r0C87, body.constant(int(1))), 0x01));


               body.instructions = f0C96_parent_instructions;
               body.emit(f0C96);

               /* END IF */

               body.emit(assign(r0C86, r0C87, 0x01));


            body.instructions = f0C88_parent_instructions;
            body.emit(f0C88);

            /* END IF */

            ir_variable *const r0C99 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0C99, add(r0C86, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C6D, lshift(r0C70, r0C99), 0x01));

            body.emit(assign(r0C6C, sub(body.constant(int(1)), r0C99), 0x01));

            body.emit(assign(r0C6C, add(r0C6C, body.constant(int(-1))), 0x01));


         body.instructions = f0C82_parent_instructions;
         body.emit(f0C82);

         /* END IF */


      body.instructions = f0C80_parent_instructions;
      body.emit(f0C80);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C9A = new(mem_ctx) ir_if(operand(r0C69).val);
      exec_list *const f0C9A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C9A->then_instructions;

         ir_variable *const r0C9B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C9B);
         ir_expression *const r0C9C = lshift(r0C6B, body.constant(int(31)));
         ir_expression *const r0C9D = add(r0C6C, body.constant(int(896)));
         ir_expression *const r0C9E = expr(ir_unop_i2u, r0C9D);
         ir_expression *const r0C9F = lshift(r0C9E, body.constant(int(20)));
         ir_expression *const r0CA0 = add(r0C9C, r0C9F);
         ir_expression *const r0CA1 = rshift(r0C6D, body.constant(int(3)));
         body.emit(assign(r0C9B, add(r0CA0, r0CA1), 0x02));

         ir_expression *const r0CA2 = lshift(r0C6D, body.constant(int(29)));
         body.emit(assign(r0C9B, bit_or(r0CA2, body.constant(0u)), 0x01));

         body.emit(assign(r0C6A, r0C9B, 0x03));

         body.emit(assign(r0C69, body.constant(false), 0x01));


      body.instructions = f0C9A_parent_instructions;
      body.emit(f0C9A);

      /* END IF */


   body.instructions = f0C74_parent_instructions;
   body.emit(f0C74);

   /* END IF */

   body.emit(ret(r0C6A));

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

   ir_variable *const r0CA3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CA3);
   ir_variable *const r0CA4 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CA5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0CA6 = rshift(swizzle_y(r0CA3), body.constant(int(20)));
   ir_expression *const r0CA7 = bit_and(r0CA6, body.constant(2047u));
   ir_expression *const r0CA8 = expr(ir_unop_u2i, r0CA7);
   body.emit(assign(r0CA5, add(r0CA8, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CAA = less(r0CA5, body.constant(int(0)));
   ir_if *f0CA9 = new(mem_ctx) ir_if(operand(r0CAA).val);
   exec_list *const f0CA9_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CA9->then_instructions;

      body.emit(assign(r0CA4, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CA9->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CAC = less(body.constant(int(52)), r0CA5);
      ir_if *f0CAB = new(mem_ctx) ir_if(operand(r0CAC).val);
      exec_list *const f0CAB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CAB->then_instructions;

         body.emit(assign(r0CA4, r0CA3, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CAB->else_instructions;

         ir_variable *const r0CAD = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0CAD, sub(body.constant(int(52)), r0CA5), 0x01));

         ir_variable *const r0CAE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0CB0 = gequal(r0CAD, body.constant(int(32)));
         ir_if *f0CAF = new(mem_ctx) ir_if(operand(r0CB0).val);
         exec_list *const f0CAF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CAF->then_instructions;

            body.emit(assign(r0CAE, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CAF->else_instructions;

            body.emit(assign(r0CAE, lshift(body.constant(4294967295u), r0CAD), 0x01));


         body.instructions = f0CAF_parent_instructions;
         body.emit(f0CAF);

         /* END IF */

         ir_variable *const r0CB1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0CB3 = less(r0CAD, body.constant(int(33)));
         ir_if *f0CB2 = new(mem_ctx) ir_if(operand(r0CB3).val);
         exec_list *const f0CB2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CB2->then_instructions;

            body.emit(assign(r0CB1, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CB2->else_instructions;

            ir_expression *const r0CB4 = add(r0CAD, body.constant(int(-32)));
            body.emit(assign(r0CB1, lshift(body.constant(4294967295u), r0CB4), 0x01));


         body.instructions = f0CB2_parent_instructions;
         body.emit(f0CB2);

         /* END IF */

         ir_variable *const r0CB5 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0CB5, bit_and(r0CAE, swizzle_x(r0CA3)), 0x01));

         body.emit(assign(r0CB5, bit_and(r0CB1, swizzle_y(r0CA3)), 0x02));

         body.emit(assign(r0CA4, r0CB5, 0x03));


      body.instructions = f0CAB_parent_instructions;
      body.emit(f0CAB);

      /* END IF */


   body.instructions = f0CA9_parent_instructions;
   body.emit(f0CA9);

   /* END IF */

   body.emit(ret(r0CA4));

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

   ir_variable *const r0CB6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CB6);
   ir_variable *const r0CB7 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0CB7, body.constant(true), 0x01));

   ir_variable *const r0CB8 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CB9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0CB9);
   ir_variable *const r0CBA = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0CBA);
   ir_variable *const r0CBB = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0CBC = rshift(swizzle_y(r0CB6), body.constant(int(20)));
   ir_expression *const r0CBD = bit_and(r0CBC, body.constant(2047u));
   ir_expression *const r0CBE = expr(ir_unop_u2i, r0CBD);
   body.emit(assign(r0CBB, add(r0CBE, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0CBA, swizzle_y(r0CB6), 0x01));

   body.emit(assign(r0CB9, swizzle_x(r0CB6), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CC0 = less(r0CBB, body.constant(int(20)));
   ir_if *f0CBF = new(mem_ctx) ir_if(operand(r0CC0).val);
   exec_list *const f0CBF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CBF->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CC2 = less(r0CBB, body.constant(int(0)));
      ir_if *f0CC1 = new(mem_ctx) ir_if(operand(r0CC2).val);
      exec_list *const f0CC1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CC1->then_instructions;

         body.emit(assign(r0CBA, bit_and(swizzle_y(r0CB6), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CC4 = equal(r0CBB, body.constant(int(-1)));
         ir_expression *const r0CC5 = nequal(swizzle_x(r0CB6), body.constant(0u));
         ir_expression *const r0CC6 = logic_and(r0CC4, r0CC5);
         ir_if *f0CC3 = new(mem_ctx) ir_if(operand(r0CC6).val);
         exec_list *const f0CC3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CC3->then_instructions;

            body.emit(assign(r0CBA, bit_or(r0CBA, body.constant(1072693248u)), 0x01));


         body.instructions = f0CC3_parent_instructions;
         body.emit(f0CC3);

         /* END IF */

         body.emit(assign(r0CB9, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CC1->else_instructions;

         ir_variable *const r0CC7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0CC7, rshift(body.constant(1048575u), r0CBB), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CC9 = bit_and(r0CBA, r0CC7);
         ir_expression *const r0CCA = equal(r0CC9, body.constant(0u));
         ir_expression *const r0CCB = equal(r0CB9, body.constant(0u));
         ir_expression *const r0CCC = logic_and(r0CCA, r0CCB);
         ir_if *f0CC8 = new(mem_ctx) ir_if(operand(r0CCC).val);
         exec_list *const f0CC8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CC8->then_instructions;

            body.emit(assign(r0CB8, r0CB6, 0x03));

            body.emit(assign(r0CB7, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CC8->else_instructions;

            ir_expression *const r0CCD = rshift(body.constant(524288u), r0CBB);
            body.emit(assign(r0CBA, add(r0CBA, r0CCD), 0x01));

            ir_expression *const r0CCE = expr(ir_unop_bit_not, r0CC7);
            body.emit(assign(r0CBA, bit_and(r0CBA, r0CCE), 0x01));

            body.emit(assign(r0CB9, body.constant(0u), 0x01));


         body.instructions = f0CC8_parent_instructions;
         body.emit(f0CC8);

         /* END IF */


      body.instructions = f0CC1_parent_instructions;
      body.emit(f0CC1);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CBF->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CD0 = less(body.constant(int(51)), r0CBB);
      ir_expression *const r0CD1 = equal(r0CBB, body.constant(int(1024)));
      ir_expression *const r0CD2 = logic_or(r0CD0, r0CD1);
      ir_if *f0CCF = new(mem_ctx) ir_if(operand(r0CD2).val);
      exec_list *const f0CCF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CCF->then_instructions;

         body.emit(assign(r0CB8, r0CB6, 0x03));

         body.emit(assign(r0CB7, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CCF->else_instructions;

         ir_variable *const r0CD3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0CD4 = add(r0CBB, body.constant(int(-20)));
         body.emit(assign(r0CD3, rshift(body.constant(4294967295u), r0CD4), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CD6 = bit_and(r0CB9, r0CD3);
         ir_expression *const r0CD7 = equal(r0CD6, body.constant(0u));
         ir_if *f0CD5 = new(mem_ctx) ir_if(operand(r0CD7).val);
         exec_list *const f0CD5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CD5->then_instructions;

            body.emit(assign(r0CB8, r0CB6, 0x03));

            body.emit(assign(r0CB7, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CD5->else_instructions;

            ir_variable *const r0CD8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0CD9 = sub(body.constant(int(51)), r0CBB);
            ir_expression *const r0CDA = lshift(body.constant(1u), r0CD9);
            body.emit(assign(r0CD8, add(r0CB9, r0CDA), 0x01));

            /* IF CONDITION */
            ir_expression *const r0CDC = less(r0CD8, r0CB9);
            ir_if *f0CDB = new(mem_ctx) ir_if(operand(r0CDC).val);
            exec_list *const f0CDB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0CDB->then_instructions;

               body.emit(assign(r0CBA, add(r0CBA, body.constant(1u)), 0x01));


            body.instructions = f0CDB_parent_instructions;
            body.emit(f0CDB);

            /* END IF */

            ir_expression *const r0CDD = expr(ir_unop_bit_not, r0CD3);
            body.emit(assign(r0CB9, bit_and(r0CD8, r0CDD), 0x01));


         body.instructions = f0CD5_parent_instructions;
         body.emit(f0CD5);

         /* END IF */


      body.instructions = f0CCF_parent_instructions;
      body.emit(f0CCF);

      /* END IF */


   body.instructions = f0CBF_parent_instructions;
   body.emit(f0CBF);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0CDE = new(mem_ctx) ir_if(operand(r0CB7).val);
   exec_list *const f0CDE_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CDE->then_instructions;

      body.emit(assign(r0CB6, r0CB9, 0x01));

      body.emit(assign(r0CB6, r0CBA, 0x02));

      body.emit(assign(r0CB8, r0CB6, 0x03));

      body.emit(assign(r0CB7, body.constant(false), 0x01));


   body.instructions = f0CDE_parent_instructions;
   body.emit(f0CDE);

   /* END IF */

   body.emit(ret(r0CB8));

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

   ir_variable *const r0CDF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CDF);
   ir_variable *const r0CE0 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0CE0, r0CDF, 0x03));

   ir_variable *const r0CE1 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0CE2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0CE2);
   body.emit(assign(r0CE2, body.constant(0u), 0x01));

   ir_variable *const r0CE3 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0CE3, bit_and(swizzle_y(r0CDF), body.constant(1048575u)), 0x01));

   ir_variable *const r0CE4 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0CE5 = rshift(swizzle_y(r0CDF), body.constant(int(20)));
   ir_expression *const r0CE6 = bit_and(r0CE5, body.constant(2047u));
   body.emit(assign(r0CE4, expr(ir_unop_u2i, r0CE6), 0x01));

   ir_variable *const r0CE7 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0CE7, rshift(swizzle_y(r0CDF), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CE9 = equal(r0CE4, body.constant(int(2047)));
   ir_if *f0CE8 = new(mem_ctx) ir_if(operand(r0CE9).val);
   exec_list *const f0CE8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CE8->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CEB = bit_or(r0CE3, swizzle_x(r0CDF));
      ir_expression *const r0CEC = nequal(r0CEB, body.constant(0u));
      ir_if *f0CEA = new(mem_ctx) ir_if(operand(r0CEC).val);
      exec_list *const f0CEA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CEA->then_instructions;

         ir_expression *const r0CED = lshift(swizzle_y(r0CDF), body.constant(int(12)));
         ir_expression *const r0CEE = rshift(swizzle_x(r0CDF), body.constant(int(20)));
         body.emit(assign(r0CE0, bit_or(r0CED, r0CEE), 0x02));

         body.emit(assign(r0CE0, lshift(swizzle_x(r0CDF), body.constant(int(12))), 0x01));

         ir_expression *const r0CEF = lshift(r0CE7, body.constant(int(31)));
         ir_expression *const r0CF0 = bit_or(r0CEF, body.constant(2143289344u));
         ir_expression *const r0CF1 = rshift(swizzle_y(r0CE0), body.constant(int(9)));
         ir_expression *const r0CF2 = bit_or(r0CF0, r0CF1);
         body.emit(assign(r0CE1, expr(ir_unop_bitcast_u2f, r0CF2), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CEA->else_instructions;

         ir_expression *const r0CF3 = lshift(r0CE7, body.constant(int(31)));
         ir_expression *const r0CF4 = add(r0CF3, body.constant(2139095040u));
         body.emit(assign(r0CE1, expr(ir_unop_bitcast_u2f, r0CF4), 0x01));


      body.instructions = f0CEA_parent_instructions;
      body.emit(f0CEA);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CE8->else_instructions;

      ir_variable *const r0CF5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0CF5);
      ir_variable *const r0CF6 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0CF6, rshift(r0CE3, body.constant(int(22))), 0x01));

      ir_expression *const r0CF7 = lshift(r0CE3, body.constant(int(10)));
      ir_expression *const r0CF8 = rshift(swizzle_x(r0CDF), body.constant(int(22)));
      ir_expression *const r0CF9 = bit_or(r0CF7, r0CF8);
      ir_expression *const r0CFA = lshift(swizzle_x(r0CDF), body.constant(int(10)));
      ir_expression *const r0CFB = nequal(r0CFA, body.constant(0u));
      ir_expression *const r0CFC = expr(ir_unop_b2i, r0CFB);
      ir_expression *const r0CFD = expr(ir_unop_i2u, r0CFC);
      body.emit(assign(r0CF5, bit_or(r0CF9, r0CFD), 0x01));

      body.emit(assign(r0CE2, r0CF5, 0x01));

      /* IF CONDITION */
      ir_expression *const r0CFF = nequal(r0CE4, body.constant(int(0)));
      ir_if *f0CFE = new(mem_ctx) ir_if(operand(r0CFF).val);
      exec_list *const f0CFE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CFE->then_instructions;

         body.emit(assign(r0CE2, bit_or(r0CF5, body.constant(1073741824u)), 0x01));


      body.instructions = f0CFE_parent_instructions;
      body.emit(f0CFE);

      /* END IF */

      ir_variable *const r0D00 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0D00, add(r0CE4, body.constant(int(-897))), 0x01));

      ir_variable *const r0D01 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0D01, r0CE2, 0x01));

      ir_variable *const r0D02 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0D02, body.constant(true), 0x01));

      ir_variable *const r0D03 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0D04 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0D04);
      ir_expression *const r0D05 = bit_and(r0CE2, body.constant(127u));
      body.emit(assign(r0D04, expr(ir_unop_u2i, r0D05), 0x01));

      /* IF CONDITION */
      ir_expression *const r0D07 = expr(ir_unop_i2u, r0D00);
      ir_expression *const r0D08 = gequal(r0D07, body.constant(253u));
      ir_if *f0D06 = new(mem_ctx) ir_if(operand(r0D08).val);
      exec_list *const f0D06_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D06->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0D0A = less(body.constant(int(253)), r0D00);
         ir_expression *const r0D0B = equal(r0D00, body.constant(int(253)));
         ir_expression *const r0D0C = expr(ir_unop_u2i, r0CE2);
         ir_expression *const r0D0D = less(r0D0C, body.constant(int(-64)));
         ir_expression *const r0D0E = logic_and(r0D0B, r0D0D);
         ir_expression *const r0D0F = logic_or(r0D0A, r0D0E);
         ir_if *f0D09 = new(mem_ctx) ir_if(operand(r0D0F).val);
         exec_list *const f0D09_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D09->then_instructions;

            ir_expression *const r0D10 = lshift(r0CE7, body.constant(int(31)));
            ir_expression *const r0D11 = add(r0D10, body.constant(2139095040u));
            body.emit(assign(r0D03, expr(ir_unop_bitcast_u2f, r0D11), 0x01));

            body.emit(assign(r0D02, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D09->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0D13 = less(r0D00, body.constant(int(0)));
            ir_if *f0D12 = new(mem_ctx) ir_if(operand(r0D13).val);
            exec_list *const f0D12_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D12->then_instructions;

               ir_variable *const r0D14 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0D14, neg(r0D00), 0x01));

               /* IF CONDITION */
               ir_expression *const r0D16 = less(r0D14, body.constant(int(32)));
               ir_if *f0D15 = new(mem_ctx) ir_if(operand(r0D16).val);
               exec_list *const f0D15_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D15->then_instructions;

                  ir_expression *const r0D17 = rshift(r0CE2, r0D14);
                  ir_expression *const r0D18 = neg(r0D14);
                  ir_expression *const r0D19 = bit_and(r0D18, body.constant(int(31)));
                  ir_expression *const r0D1A = lshift(r0CE2, r0D19);
                  ir_expression *const r0D1B = nequal(r0D1A, body.constant(0u));
                  ir_expression *const r0D1C = expr(ir_unop_b2i, r0D1B);
                  ir_expression *const r0D1D = expr(ir_unop_i2u, r0D1C);
                  body.emit(assign(r0D01, bit_or(r0D17, r0D1D), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0D15->else_instructions;

                  ir_expression *const r0D1E = nequal(r0D01, body.constant(0u));
                  ir_expression *const r0D1F = expr(ir_unop_b2i, r0D1E);
                  body.emit(assign(r0D01, expr(ir_unop_i2u, r0D1F), 0x01));


               body.instructions = f0D15_parent_instructions;
               body.emit(f0D15);

               /* END IF */

               body.emit(assign(r0D00, body.constant(int(0)), 0x01));

               ir_expression *const r0D20 = expr(ir_unop_u2i, r0D01);
               body.emit(assign(r0D04, bit_and(r0D20, body.constant(int(127))), 0x01));


            body.instructions = f0D12_parent_instructions;
            body.emit(f0D12);

            /* END IF */


         body.instructions = f0D09_parent_instructions;
         body.emit(f0D09);

         /* END IF */


      body.instructions = f0D06_parent_instructions;
      body.emit(f0D06);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0D21 = new(mem_ctx) ir_if(operand(r0D02).val);
      exec_list *const f0D21_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D21->then_instructions;

         ir_expression *const r0D22 = add(r0D01, body.constant(64u));
         body.emit(assign(r0D01, rshift(r0D22, body.constant(int(7))), 0x01));

         ir_expression *const r0D23 = bit_xor(r0D04, body.constant(int(64)));
         ir_expression *const r0D24 = equal(r0D23, body.constant(int(0)));
         ir_expression *const r0D25 = expr(ir_unop_b2i, r0D24);
         ir_expression *const r0D26 = expr(ir_unop_i2u, r0D25);
         ir_expression *const r0D27 = expr(ir_unop_bit_not, r0D26);
         body.emit(assign(r0D01, bit_and(r0D01, r0D27), 0x01));

         /* IF CONDITION */
         ir_expression *const r0D29 = equal(r0D01, body.constant(0u));
         ir_if *f0D28 = new(mem_ctx) ir_if(operand(r0D29).val);
         exec_list *const f0D28_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D28->then_instructions;

            body.emit(assign(r0D00, body.constant(int(0)), 0x01));


         body.instructions = f0D28_parent_instructions;
         body.emit(f0D28);

         /* END IF */

         ir_expression *const r0D2A = lshift(r0CE7, body.constant(int(31)));
         ir_expression *const r0D2B = expr(ir_unop_i2u, r0D00);
         ir_expression *const r0D2C = lshift(r0D2B, body.constant(int(23)));
         ir_expression *const r0D2D = add(r0D2A, r0D2C);
         ir_expression *const r0D2E = add(r0D2D, r0D01);
         body.emit(assign(r0D03, expr(ir_unop_bitcast_u2f, r0D2E), 0x01));

         body.emit(assign(r0D02, body.constant(false), 0x01));


      body.instructions = f0D21_parent_instructions;
      body.emit(f0D21);

      /* END IF */

      body.emit(assign(r0CE1, r0D03, 0x01));


   body.instructions = f0CE8_parent_instructions;
   body.emit(f0CE8);

   /* END IF */

   ir_variable *const r0D2F = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0D2F, body.constant(true), 0x01));

   ir_variable *const r0D30 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0D31 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0D31);
   ir_variable *const r0D32 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0D32);
   ir_variable *const r0D33 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0D33);
   ir_variable *const r0D34 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0D35 = expr(ir_unop_rcp, r0CE1);
   body.emit(assign(r0D34, expr(ir_unop_bitcast_f2u, r0D35), 0x01));

   ir_variable *const r0D36 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0D36, bit_and(r0D34, body.constant(8388607u)), 0x01));

   body.emit(assign(r0D33, r0D36, 0x01));

   ir_variable *const r0D37 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0D38 = rshift(r0D34, body.constant(int(23)));
   ir_expression *const r0D39 = bit_and(r0D38, body.constant(255u));
   body.emit(assign(r0D37, expr(ir_unop_u2i, r0D39), 0x01));

   body.emit(assign(r0D32, r0D37, 0x01));

   body.emit(assign(r0D31, rshift(r0D34, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0D3B = equal(r0D37, body.constant(int(255)));
   ir_if *f0D3A = new(mem_ctx) ir_if(operand(r0D3B).val);
   exec_list *const f0D3A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D3A->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0D3D = nequal(r0D36, body.constant(0u));
      ir_if *f0D3C = new(mem_ctx) ir_if(operand(r0D3D).val);
      exec_list *const f0D3C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D3C->then_instructions;

         ir_variable *const r0D3E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0D3E, lshift(r0D34, body.constant(int(9))), 0x01));

         ir_variable *const r0D3F = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0D40 = lshift(r0D3E, body.constant(int(20)));
         body.emit(assign(r0D3F, bit_or(r0D40, body.constant(0u)), 0x01));

         ir_expression *const r0D41 = rshift(r0D3E, body.constant(int(12)));
         ir_expression *const r0D42 = lshift(r0D31, body.constant(int(31)));
         ir_expression *const r0D43 = bit_or(r0D42, body.constant(2146959360u));
         body.emit(assign(r0D3F, bit_or(r0D41, r0D43), 0x02));

         body.emit(assign(r0D30, r0D3F, 0x03));

         body.emit(assign(r0D2F, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D3C->else_instructions;

         ir_variable *const r0D44 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D44);
         ir_expression *const r0D45 = lshift(r0D31, body.constant(int(31)));
         body.emit(assign(r0D44, add(r0D45, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0D44, body.constant(0u), 0x01));

         body.emit(assign(r0D30, r0D44, 0x03));

         body.emit(assign(r0D2F, body.constant(false), 0x01));


      body.instructions = f0D3C_parent_instructions;
      body.emit(f0D3C);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0D3A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0D47 = equal(r0D37, body.constant(int(0)));
      ir_if *f0D46 = new(mem_ctx) ir_if(operand(r0D47).val);
      exec_list *const f0D46_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D46->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0D49 = equal(r0D36, body.constant(0u));
         ir_if *f0D48 = new(mem_ctx) ir_if(operand(r0D49).val);
         exec_list *const f0D48_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D48->then_instructions;

            ir_variable *const r0D4A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0D4A);
            body.emit(assign(r0D4A, lshift(r0D31, body.constant(int(31))), 0x02));

            body.emit(assign(r0D4A, body.constant(0u), 0x01));

            body.emit(assign(r0D30, r0D4A, 0x03));

            body.emit(assign(r0D2F, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D48->else_instructions;

            ir_variable *const r0D4B = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0D4B, r0D36, 0x01));

            ir_variable *const r0D4C = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0D4D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0D4D);
            /* IF CONDITION */
            ir_expression *const r0D4F = equal(r0D36, body.constant(0u));
            ir_if *f0D4E = new(mem_ctx) ir_if(operand(r0D4F).val);
            exec_list *const f0D4E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D4E->then_instructions;

               body.emit(assign(r0D4C, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0D4E->else_instructions;

               body.emit(assign(r0D4D, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0D51 = bit_and(r0D36, body.constant(4294901760u));
               ir_expression *const r0D52 = equal(r0D51, body.constant(0u));
               ir_if *f0D50 = new(mem_ctx) ir_if(operand(r0D52).val);
               exec_list *const f0D50_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D50->then_instructions;

                  body.emit(assign(r0D4D, body.constant(int(16)), 0x01));

                  body.emit(assign(r0D4B, lshift(r0D36, body.constant(int(16))), 0x01));


               body.instructions = f0D50_parent_instructions;
               body.emit(f0D50);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D54 = bit_and(r0D4B, body.constant(4278190080u));
               ir_expression *const r0D55 = equal(r0D54, body.constant(0u));
               ir_if *f0D53 = new(mem_ctx) ir_if(operand(r0D55).val);
               exec_list *const f0D53_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D53->then_instructions;

                  body.emit(assign(r0D4D, add(r0D4D, body.constant(int(8))), 0x01));

                  body.emit(assign(r0D4B, lshift(r0D4B, body.constant(int(8))), 0x01));


               body.instructions = f0D53_parent_instructions;
               body.emit(f0D53);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D57 = bit_and(r0D4B, body.constant(4026531840u));
               ir_expression *const r0D58 = equal(r0D57, body.constant(0u));
               ir_if *f0D56 = new(mem_ctx) ir_if(operand(r0D58).val);
               exec_list *const f0D56_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D56->then_instructions;

                  body.emit(assign(r0D4D, add(r0D4D, body.constant(int(4))), 0x01));

                  body.emit(assign(r0D4B, lshift(r0D4B, body.constant(int(4))), 0x01));


               body.instructions = f0D56_parent_instructions;
               body.emit(f0D56);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D5A = bit_and(r0D4B, body.constant(3221225472u));
               ir_expression *const r0D5B = equal(r0D5A, body.constant(0u));
               ir_if *f0D59 = new(mem_ctx) ir_if(operand(r0D5B).val);
               exec_list *const f0D59_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D59->then_instructions;

                  body.emit(assign(r0D4D, add(r0D4D, body.constant(int(2))), 0x01));

                  body.emit(assign(r0D4B, lshift(r0D4B, body.constant(int(2))), 0x01));


               body.instructions = f0D59_parent_instructions;
               body.emit(f0D59);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D5D = bit_and(r0D4B, body.constant(2147483648u));
               ir_expression *const r0D5E = equal(r0D5D, body.constant(0u));
               ir_if *f0D5C = new(mem_ctx) ir_if(operand(r0D5E).val);
               exec_list *const f0D5C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D5C->then_instructions;

                  body.emit(assign(r0D4D, add(r0D4D, body.constant(int(1))), 0x01));


               body.instructions = f0D5C_parent_instructions;
               body.emit(f0D5C);

               /* END IF */

               body.emit(assign(r0D4C, r0D4D, 0x01));


            body.instructions = f0D4E_parent_instructions;
            body.emit(f0D4E);

            /* END IF */

            ir_variable *const r0D5F = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0D5F, add(r0D4C, body.constant(int(-8))), 0x01));

            body.emit(assign(r0D33, lshift(r0D36, r0D5F), 0x01));

            body.emit(assign(r0D32, sub(body.constant(int(1)), r0D5F), 0x01));

            body.emit(assign(r0D32, add(r0D32, body.constant(int(-1))), 0x01));


         body.instructions = f0D48_parent_instructions;
         body.emit(f0D48);

         /* END IF */


      body.instructions = f0D46_parent_instructions;
      body.emit(f0D46);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0D60 = new(mem_ctx) ir_if(operand(r0D2F).val);
      exec_list *const f0D60_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D60->then_instructions;

         ir_variable *const r0D61 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D61);
         ir_expression *const r0D62 = lshift(r0D31, body.constant(int(31)));
         ir_expression *const r0D63 = add(r0D32, body.constant(int(896)));
         ir_expression *const r0D64 = expr(ir_unop_i2u, r0D63);
         ir_expression *const r0D65 = lshift(r0D64, body.constant(int(20)));
         ir_expression *const r0D66 = add(r0D62, r0D65);
         ir_expression *const r0D67 = rshift(r0D33, body.constant(int(3)));
         body.emit(assign(r0D61, add(r0D66, r0D67), 0x02));

         ir_expression *const r0D68 = lshift(r0D33, body.constant(int(29)));
         body.emit(assign(r0D61, bit_or(r0D68, body.constant(0u)), 0x01));

         body.emit(assign(r0D30, r0D61, 0x03));

         body.emit(assign(r0D2F, body.constant(false), 0x01));


      body.instructions = f0D60_parent_instructions;
      body.emit(f0D60);

      /* END IF */


   body.instructions = f0D3A_parent_instructions;
   body.emit(f0D3A);

   /* END IF */

   body.emit(ret(r0D30));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
