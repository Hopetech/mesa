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

         /* IF CONDITION */
         ir_expression *const r0132 = bit_or(r00F3, r00F4);
         ir_expression *const r0133 = equal(r0132, body.constant(0u));
         ir_if *f0131 = new(mem_ctx) ir_if(operand(r0133).val);
         exec_list *const f0131_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0131->then_instructions;

            body.emit(assign(r00F2, body.constant(int(0)), 0x01));


         body.instructions = f0131_parent_instructions;
         body.emit(f0131);

         /* END IF */


      body.instructions = f0126_parent_instructions;
      body.emit(f0126);

      /* END IF */

      ir_variable *const r0134 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0134);
      ir_expression *const r0135 = lshift(r00F1, body.constant(int(31)));
      ir_expression *const r0136 = expr(ir_unop_i2u, r00F2);
      ir_expression *const r0137 = lshift(r0136, body.constant(int(20)));
      ir_expression *const r0138 = add(r0135, r0137);
      body.emit(assign(r0134, add(r0138, r00F3), 0x02));

      body.emit(assign(r0134, r00F4, 0x01));

      body.emit(assign(r00F7, r0134, 0x03));

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

   ir_variable *const r0139 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0139);
   ir_variable *const r013A = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r013B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r013B);
   /* IF CONDITION */
   ir_expression *const r013D = equal(r0139, body.constant(0u));
   ir_if *f013C = new(mem_ctx) ir_if(operand(r013D).val);
   exec_list *const f013C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f013C->then_instructions;

      body.emit(assign(r013A, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f013C->else_instructions;

      body.emit(assign(r013B, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r013F = bit_and(r0139, body.constant(4294901760u));
      ir_expression *const r0140 = equal(r013F, body.constant(0u));
      ir_if *f013E = new(mem_ctx) ir_if(operand(r0140).val);
      exec_list *const f013E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f013E->then_instructions;

         body.emit(assign(r013B, body.constant(int(16)), 0x01));

         body.emit(assign(r0139, lshift(r0139, body.constant(int(16))), 0x01));


      body.instructions = f013E_parent_instructions;
      body.emit(f013E);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0142 = bit_and(r0139, body.constant(4278190080u));
      ir_expression *const r0143 = equal(r0142, body.constant(0u));
      ir_if *f0141 = new(mem_ctx) ir_if(operand(r0143).val);
      exec_list *const f0141_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0141->then_instructions;

         body.emit(assign(r013B, add(r013B, body.constant(int(8))), 0x01));

         body.emit(assign(r0139, lshift(r0139, body.constant(int(8))), 0x01));


      body.instructions = f0141_parent_instructions;
      body.emit(f0141);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0145 = bit_and(r0139, body.constant(4026531840u));
      ir_expression *const r0146 = equal(r0145, body.constant(0u));
      ir_if *f0144 = new(mem_ctx) ir_if(operand(r0146).val);
      exec_list *const f0144_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0144->then_instructions;

         body.emit(assign(r013B, add(r013B, body.constant(int(4))), 0x01));

         body.emit(assign(r0139, lshift(r0139, body.constant(int(4))), 0x01));


      body.instructions = f0144_parent_instructions;
      body.emit(f0144);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0148 = bit_and(r0139, body.constant(3221225472u));
      ir_expression *const r0149 = equal(r0148, body.constant(0u));
      ir_if *f0147 = new(mem_ctx) ir_if(operand(r0149).val);
      exec_list *const f0147_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0147->then_instructions;

         body.emit(assign(r013B, add(r013B, body.constant(int(2))), 0x01));

         body.emit(assign(r0139, lshift(r0139, body.constant(int(2))), 0x01));


      body.instructions = f0147_parent_instructions;
      body.emit(f0147);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r014B = bit_and(r0139, body.constant(2147483648u));
      ir_expression *const r014C = equal(r014B, body.constant(0u));
      ir_if *f014A = new(mem_ctx) ir_if(operand(r014C).val);
      exec_list *const f014A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f014A->then_instructions;

         body.emit(assign(r013B, add(r013B, body.constant(int(1))), 0x01));


      body.instructions = f014A_parent_instructions;
      body.emit(f014A);

      /* END IF */

      body.emit(assign(r013A, r013B, 0x01));


   body.instructions = f013C_parent_instructions;
   body.emit(f013C);

   /* END IF */

   body.emit(ret(r013A));

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

   ir_variable *const r014D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r014D);
   ir_variable *const r014E = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r014E);
   ir_variable *const r014F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r014F);
   ir_variable *const r0150 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0150);
   ir_variable *const r0151 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0151);
   ir_variable *const r0152 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0152);
   /* IF CONDITION */
   ir_expression *const r0154 = equal(r014F, body.constant(0u));
   ir_if *f0153 = new(mem_ctx) ir_if(operand(r0154).val);
   exec_list *const f0153_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0153->then_instructions;

      body.emit(assign(r014F, r0150, 0x01));

      body.emit(assign(r0150, body.constant(0u), 0x01));

      body.emit(assign(r014E, add(r014E, body.constant(int(-32))), 0x01));


   body.instructions = f0153_parent_instructions;
   body.emit(f0153);

   /* END IF */

   ir_variable *const r0155 = body.make_temp(glsl_type::uint_type, "a");
   body.emit(assign(r0155, r014F, 0x01));

   ir_variable *const r0156 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0157 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0157);
   /* IF CONDITION */
   ir_expression *const r0159 = equal(r014F, body.constant(0u));
   ir_if *f0158 = new(mem_ctx) ir_if(operand(r0159).val);
   exec_list *const f0158_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0158->then_instructions;

      body.emit(assign(r0156, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0158->else_instructions;

      body.emit(assign(r0157, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r015B = bit_and(r014F, body.constant(4294901760u));
      ir_expression *const r015C = equal(r015B, body.constant(0u));
      ir_if *f015A = new(mem_ctx) ir_if(operand(r015C).val);
      exec_list *const f015A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f015A->then_instructions;

         body.emit(assign(r0157, body.constant(int(16)), 0x01));

         body.emit(assign(r0155, lshift(r014F, body.constant(int(16))), 0x01));


      body.instructions = f015A_parent_instructions;
      body.emit(f015A);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r015E = bit_and(r0155, body.constant(4278190080u));
      ir_expression *const r015F = equal(r015E, body.constant(0u));
      ir_if *f015D = new(mem_ctx) ir_if(operand(r015F).val);
      exec_list *const f015D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f015D->then_instructions;

         body.emit(assign(r0157, add(r0157, body.constant(int(8))), 0x01));

         body.emit(assign(r0155, lshift(r0155, body.constant(int(8))), 0x01));


      body.instructions = f015D_parent_instructions;
      body.emit(f015D);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0161 = bit_and(r0155, body.constant(4026531840u));
      ir_expression *const r0162 = equal(r0161, body.constant(0u));
      ir_if *f0160 = new(mem_ctx) ir_if(operand(r0162).val);
      exec_list *const f0160_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0160->then_instructions;

         body.emit(assign(r0157, add(r0157, body.constant(int(4))), 0x01));

         body.emit(assign(r0155, lshift(r0155, body.constant(int(4))), 0x01));


      body.instructions = f0160_parent_instructions;
      body.emit(f0160);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0164 = bit_and(r0155, body.constant(3221225472u));
      ir_expression *const r0165 = equal(r0164, body.constant(0u));
      ir_if *f0163 = new(mem_ctx) ir_if(operand(r0165).val);
      exec_list *const f0163_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0163->then_instructions;

         body.emit(assign(r0157, add(r0157, body.constant(int(2))), 0x01));

         body.emit(assign(r0155, lshift(r0155, body.constant(int(2))), 0x01));


      body.instructions = f0163_parent_instructions;
      body.emit(f0163);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0167 = bit_and(r0155, body.constant(2147483648u));
      ir_expression *const r0168 = equal(r0167, body.constant(0u));
      ir_if *f0166 = new(mem_ctx) ir_if(operand(r0168).val);
      exec_list *const f0166_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0166->then_instructions;

         body.emit(assign(r0157, add(r0157, body.constant(int(1))), 0x01));


      body.instructions = f0166_parent_instructions;
      body.emit(f0166);

      /* END IF */

      body.emit(assign(r0156, r0157, 0x01));


   body.instructions = f0158_parent_instructions;
   body.emit(f0158);

   /* END IF */

   body.emit(assign(r0152, add(r0156, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r016A = gequal(r0152, body.constant(int(0)));
   ir_if *f0169 = new(mem_ctx) ir_if(operand(r016A).val);
   exec_list *const f0169_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0169->then_instructions;

      body.emit(assign(r0151, body.constant(0u), 0x01));

      ir_expression *const r016B = equal(r0152, body.constant(int(0)));
      ir_expression *const r016C = lshift(r014F, r0152);
      ir_expression *const r016D = neg(r0152);
      ir_expression *const r016E = bit_and(r016D, body.constant(int(31)));
      ir_expression *const r016F = rshift(r0150, r016E);
      ir_expression *const r0170 = bit_or(r016C, r016F);
      body.emit(assign(r014F, expr(ir_triop_csel, r016B, r014F, r0170), 0x01));

      body.emit(assign(r0150, lshift(r0150, r0152), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0169->else_instructions;

      ir_variable *const r0171 = body.make_temp(glsl_type::uint_type, "a2");
      body.emit(assign(r0171, body.constant(0u), 0x01));

      ir_variable *const r0172 = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r0172, neg(r0152), 0x01));

      ir_variable *const r0173 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
      body.emit(r0173);
      ir_variable *const r0174 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0174);
      ir_variable *const r0175 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0175);
      ir_variable *const r0176 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0177 = neg(r0172);
      body.emit(assign(r0176, bit_and(r0177, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0179 = equal(r0172, body.constant(int(0)));
      ir_if *f0178 = new(mem_ctx) ir_if(operand(r0179).val);
      exec_list *const f0178_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0178->then_instructions;

         body.emit(assign(r0173, r0171, 0x01));

         body.emit(assign(r0174, r0150, 0x01));

         body.emit(assign(r0175, r014F, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0178->else_instructions;

         /* IF CONDITION */
         ir_expression *const r017B = less(r0172, body.constant(int(32)));
         ir_if *f017A = new(mem_ctx) ir_if(operand(r017B).val);
         exec_list *const f017A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f017A->then_instructions;

            body.emit(assign(r0173, lshift(r0150, r0176), 0x01));

            ir_expression *const r017C = lshift(r014F, r0176);
            ir_expression *const r017D = rshift(r0150, r0172);
            body.emit(assign(r0174, bit_or(r017C, r017D), 0x01));

            body.emit(assign(r0175, rshift(r014F, r0172), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f017A->else_instructions;

            /* IF CONDITION */
            ir_expression *const r017F = equal(r0172, body.constant(int(32)));
            ir_if *f017E = new(mem_ctx) ir_if(operand(r017F).val);
            exec_list *const f017E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f017E->then_instructions;

               body.emit(assign(r0173, r0150, 0x01));

               body.emit(assign(r0174, r014F, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f017E->else_instructions;

               body.emit(assign(r0171, bit_or(body.constant(0u), r0150), 0x01));

               ir_expression *const r0180 = less(r0172, body.constant(int(64)));
               ir_expression *const r0181 = lshift(r014F, r0176);
               ir_expression *const r0182 = equal(r0172, body.constant(int(64)));
               ir_expression *const r0183 = nequal(r014F, body.constant(0u));
               ir_expression *const r0184 = expr(ir_unop_b2i, r0183);
               ir_expression *const r0185 = expr(ir_unop_i2u, r0184);
               ir_expression *const r0186 = expr(ir_triop_csel, r0182, r014F, r0185);
               body.emit(assign(r0173, expr(ir_triop_csel, r0180, r0181, r0186), 0x01));

               ir_expression *const r0187 = less(r0172, body.constant(int(64)));
               ir_expression *const r0188 = bit_and(r0172, body.constant(int(31)));
               ir_expression *const r0189 = rshift(r014F, r0188);
               body.emit(assign(r0174, expr(ir_triop_csel, r0187, r0189, body.constant(0u)), 0x01));


            body.instructions = f017E_parent_instructions;
            body.emit(f017E);

            /* END IF */

            body.emit(assign(r0175, body.constant(0u), 0x01));


         body.instructions = f017A_parent_instructions;
         body.emit(f017A);

         /* END IF */

         ir_expression *const r018A = nequal(r0171, body.constant(0u));
         ir_expression *const r018B = expr(ir_unop_b2i, r018A);
         ir_expression *const r018C = expr(ir_unop_i2u, r018B);
         body.emit(assign(r0173, bit_or(r0173, r018C), 0x01));


      body.instructions = f0178_parent_instructions;
      body.emit(f0178);

      /* END IF */

      body.emit(assign(r014F, r0175, 0x01));

      body.emit(assign(r0150, r0174, 0x01));

      body.emit(assign(r0151, r0173, 0x01));


   body.instructions = f0169_parent_instructions;
   body.emit(f0169);

   /* END IF */

   body.emit(assign(r014E, sub(r014E, r0152), 0x01));

   ir_variable *const r018D = body.make_temp(glsl_type::int_type, "zExp");
   body.emit(assign(r018D, r014E, 0x01));

   ir_variable *const r018E = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r018E, r014F, 0x01));

   ir_variable *const r018F = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r018F, r0150, 0x01));

   ir_variable *const r0190 = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r0190, r0151, 0x01));

   ir_variable *const r0191 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0191, body.constant(true), 0x01));

   ir_variable *const r0192 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0193 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r0193);
   ir_expression *const r0194 = expr(ir_unop_u2i, r0151);
   body.emit(assign(r0193, less(r0194, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0196 = gequal(r014E, body.constant(int(2045)));
   ir_if *f0195 = new(mem_ctx) ir_if(operand(r0196).val);
   exec_list *const f0195_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0195->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0198 = less(body.constant(int(2045)), r014E);
      ir_expression *const r0199 = equal(r014E, body.constant(int(2045)));
      ir_expression *const r019A = equal(body.constant(2097151u), r014F);
      ir_expression *const r019B = equal(body.constant(4294967295u), r0150);
      ir_expression *const r019C = logic_and(r019A, r019B);
      ir_expression *const r019D = logic_and(r0199, r019C);
      ir_expression *const r019E = logic_and(r019D, r0193);
      ir_expression *const r019F = logic_or(r0198, r019E);
      ir_if *f0197 = new(mem_ctx) ir_if(operand(r019F).val);
      exec_list *const f0197_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0197->then_instructions;

         ir_variable *const r01A0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r01A0);
         ir_expression *const r01A1 = lshift(r014D, body.constant(int(31)));
         body.emit(assign(r01A0, add(r01A1, body.constant(2146435072u)), 0x02));

         body.emit(assign(r01A0, body.constant(0u), 0x01));

         body.emit(assign(r0192, r01A0, 0x03));

         body.emit(assign(r0191, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0197->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01A3 = less(r014E, body.constant(int(0)));
         ir_if *f01A2 = new(mem_ctx) ir_if(operand(r01A3).val);
         exec_list *const f01A2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01A2->then_instructions;

            ir_variable *const r01A4 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r01A4, r0151, 0x01));

            ir_variable *const r01A5 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r01A5, neg(r014E), 0x01));

            ir_variable *const r01A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r01A6);
            ir_variable *const r01A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r01A7);
            ir_variable *const r01A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r01A8);
            ir_variable *const r01A9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r01AA = neg(r01A5);
            body.emit(assign(r01A9, bit_and(r01AA, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r01AC = equal(r01A5, body.constant(int(0)));
            ir_if *f01AB = new(mem_ctx) ir_if(operand(r01AC).val);
            exec_list *const f01AB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01AB->then_instructions;

               body.emit(assign(r01A6, r0151, 0x01));

               body.emit(assign(r01A7, r0150, 0x01));

               body.emit(assign(r01A8, r014F, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01AB->else_instructions;

               /* IF CONDITION */
               ir_expression *const r01AE = less(r01A5, body.constant(int(32)));
               ir_if *f01AD = new(mem_ctx) ir_if(operand(r01AE).val);
               exec_list *const f01AD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f01AD->then_instructions;

                  body.emit(assign(r01A6, lshift(r0150, r01A9), 0x01));

                  ir_expression *const r01AF = lshift(r014F, r01A9);
                  ir_expression *const r01B0 = rshift(r0150, r01A5);
                  body.emit(assign(r01A7, bit_or(r01AF, r01B0), 0x01));

                  body.emit(assign(r01A8, rshift(r014F, r01A5), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f01AD->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r01B2 = equal(r01A5, body.constant(int(32)));
                  ir_if *f01B1 = new(mem_ctx) ir_if(operand(r01B2).val);
                  exec_list *const f01B1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f01B1->then_instructions;

                     body.emit(assign(r01A6, r0150, 0x01));

                     body.emit(assign(r01A7, r014F, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f01B1->else_instructions;

                     body.emit(assign(r01A4, bit_or(r0151, r0150), 0x01));

                     ir_expression *const r01B3 = less(r01A5, body.constant(int(64)));
                     ir_expression *const r01B4 = lshift(r014F, r01A9);
                     ir_expression *const r01B5 = equal(r01A5, body.constant(int(64)));
                     ir_expression *const r01B6 = nequal(r014F, body.constant(0u));
                     ir_expression *const r01B7 = expr(ir_unop_b2i, r01B6);
                     ir_expression *const r01B8 = expr(ir_unop_i2u, r01B7);
                     ir_expression *const r01B9 = expr(ir_triop_csel, r01B5, r014F, r01B8);
                     body.emit(assign(r01A6, expr(ir_triop_csel, r01B3, r01B4, r01B9), 0x01));

                     ir_expression *const r01BA = less(r01A5, body.constant(int(64)));
                     ir_expression *const r01BB = bit_and(r01A5, body.constant(int(31)));
                     ir_expression *const r01BC = rshift(r014F, r01BB);
                     body.emit(assign(r01A7, expr(ir_triop_csel, r01BA, r01BC, body.constant(0u)), 0x01));


                  body.instructions = f01B1_parent_instructions;
                  body.emit(f01B1);

                  /* END IF */

                  body.emit(assign(r01A8, body.constant(0u), 0x01));


               body.instructions = f01AD_parent_instructions;
               body.emit(f01AD);

               /* END IF */

               ir_expression *const r01BD = nequal(r01A4, body.constant(0u));
               ir_expression *const r01BE = expr(ir_unop_b2i, r01BD);
               ir_expression *const r01BF = expr(ir_unop_i2u, r01BE);
               body.emit(assign(r01A6, bit_or(r01A6, r01BF), 0x01));


            body.instructions = f01AB_parent_instructions;
            body.emit(f01AB);

            /* END IF */

            body.emit(assign(r018E, r01A8, 0x01));

            body.emit(assign(r018F, r01A7, 0x01));

            body.emit(assign(r0190, r01A6, 0x01));

            body.emit(assign(r018D, body.constant(int(0)), 0x01));

            body.emit(assign(r0193, less(r01A6, body.constant(0u)), 0x01));


         body.instructions = f01A2_parent_instructions;
         body.emit(f01A2);

         /* END IF */


      body.instructions = f0197_parent_instructions;
      body.emit(f0197);

      /* END IF */


   body.instructions = f0195_parent_instructions;
   body.emit(f0195);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01C0 = new(mem_ctx) ir_if(operand(r0191).val);
   exec_list *const f01C0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01C0->then_instructions;

      /* IF CONDITION */
      ir_if *f01C1 = new(mem_ctx) ir_if(operand(r0193).val);
      exec_list *const f01C1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01C1->then_instructions;

         ir_variable *const r01C2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01C2, add(r018F, body.constant(1u)), 0x01));

         ir_expression *const r01C3 = less(r01C2, r018F);
         ir_expression *const r01C4 = expr(ir_unop_b2i, r01C3);
         ir_expression *const r01C5 = expr(ir_unop_i2u, r01C4);
         body.emit(assign(r018E, add(r018E, r01C5), 0x01));

         ir_expression *const r01C6 = equal(r0190, body.constant(0u));
         ir_expression *const r01C7 = expr(ir_unop_b2i, r01C6);
         ir_expression *const r01C8 = expr(ir_unop_i2u, r01C7);
         ir_expression *const r01C9 = add(r0190, r01C8);
         ir_expression *const r01CA = bit_and(r01C9, body.constant(1u));
         ir_expression *const r01CB = expr(ir_unop_bit_not, r01CA);
         body.emit(assign(r018F, bit_and(r01C2, r01CB), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01C1->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01CD = bit_or(r018E, r018F);
         ir_expression *const r01CE = equal(r01CD, body.constant(0u));
         ir_if *f01CC = new(mem_ctx) ir_if(operand(r01CE).val);
         exec_list *const f01CC_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01CC->then_instructions;

            body.emit(assign(r018D, body.constant(int(0)), 0x01));


         body.instructions = f01CC_parent_instructions;
         body.emit(f01CC);

         /* END IF */


      body.instructions = f01C1_parent_instructions;
      body.emit(f01C1);

      /* END IF */

      ir_variable *const r01CF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r01CF);
      ir_expression *const r01D0 = lshift(r014D, body.constant(int(31)));
      ir_expression *const r01D1 = expr(ir_unop_i2u, r018D);
      ir_expression *const r01D2 = lshift(r01D1, body.constant(int(20)));
      ir_expression *const r01D3 = add(r01D0, r01D2);
      body.emit(assign(r01CF, add(r01D3, r018E), 0x02));

      body.emit(assign(r01CF, r018F, 0x01));

      body.emit(assign(r0192, r01CF, 0x03));

      body.emit(assign(r0191, body.constant(false), 0x01));


   body.instructions = f01C0_parent_instructions;
   body.emit(f01C0);

   /* END IF */

   body.emit(ret(r0192));

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

   ir_variable *const r01D4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01D4);
   ir_variable *const r01D5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01D5);
   ir_variable *const r01D6 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01D7 = lshift(swizzle_y(r01D4), body.constant(int(1)));
   ir_expression *const r01D8 = gequal(r01D7, body.constant(4292870144u));
   ir_expression *const r01D9 = nequal(swizzle_x(r01D4), body.constant(0u));
   ir_expression *const r01DA = bit_and(swizzle_y(r01D4), body.constant(1048575u));
   ir_expression *const r01DB = nequal(r01DA, body.constant(0u));
   ir_expression *const r01DC = logic_or(r01D9, r01DB);
   body.emit(assign(r01D6, logic_and(r01D8, r01DC), 0x01));

   ir_variable *const r01DD = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01DE = lshift(swizzle_y(r01D5), body.constant(int(1)));
   ir_expression *const r01DF = gequal(r01DE, body.constant(4292870144u));
   ir_expression *const r01E0 = nequal(swizzle_x(r01D5), body.constant(0u));
   ir_expression *const r01E1 = bit_and(swizzle_y(r01D5), body.constant(1048575u));
   ir_expression *const r01E2 = nequal(r01E1, body.constant(0u));
   ir_expression *const r01E3 = logic_or(r01E0, r01E2);
   body.emit(assign(r01DD, logic_and(r01DF, r01E3), 0x01));

   body.emit(assign(r01D4, bit_or(swizzle_y(r01D4), body.constant(524288u)), 0x02));

   body.emit(assign(r01D5, bit_or(swizzle_y(r01D5), body.constant(524288u)), 0x02));

   ir_variable *const r01E4 = body.make_temp(glsl_type::uvec2_type, "mix_retval");
   ir_swizzle *const r01E5 = swizzle(r01D6, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_swizzle *const r01E6 = swizzle(r01DD, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_expression *const r01E7 = expr(ir_triop_csel, r01E6, r01D5, r01D4);
   body.emit(assign(r01E4, expr(ir_triop_csel, r01E5, r01E7, r01D5), 0x03));

   body.emit(ret(r01E4));

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

   ir_variable *const r01E8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01E8);
   ir_variable *const r01E9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01E9);
   ir_variable *const r01EA = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01EA, body.constant(true), 0x01));

   ir_variable *const r01EB = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r01EC);
   ir_variable *const r01ED = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01ED, rshift(swizzle_y(r01E8), body.constant(int(31))), 0x01));

   body.emit(assign(r01EC, r01ED, 0x01));

   ir_variable *const r01EE = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01EE, rshift(swizzle_y(r01E9), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r01F0 = equal(r01ED, r01EE);
   ir_if *f01EF = new(mem_ctx) ir_if(operand(r01F0).val);
   exec_list *const f01EF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01EF->then_instructions;

      ir_variable *const r01F1 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r01F1);
      ir_variable *const r01F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r01F2);
      ir_variable *const r01F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r01F3);
      ir_variable *const r01F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r01F4);
      ir_variable *const r01F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r01F5);
      ir_variable *const r01F6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r01F6);
      ir_variable *const r01F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r01F7);
      ir_variable *const r01F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
      body.emit(r01F8);
      body.emit(assign(r01F8, body.constant(0u), 0x01));

      body.emit(assign(r01F7, body.constant(0u), 0x01));

      ir_variable *const r01F9 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01F9, swizzle_x(r01E8), 0x01));

      body.emit(assign(r01F5, r01F9, 0x01));

      ir_variable *const r01FA = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01FA, bit_and(swizzle_y(r01E8), body.constant(1048575u)), 0x01));

      body.emit(assign(r01F4, r01FA, 0x01));

      ir_variable *const r01FB = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01FB, swizzle_x(r01E9), 0x01));

      body.emit(assign(r01F3, r01FB, 0x01));

      ir_variable *const r01FC = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01FC, bit_and(swizzle_y(r01E9), body.constant(1048575u)), 0x01));

      body.emit(assign(r01F2, r01FC, 0x01));

      ir_variable *const r01FD = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r01FE = rshift(swizzle_y(r01E8), body.constant(int(20)));
      ir_expression *const r01FF = bit_and(r01FE, body.constant(2047u));
      body.emit(assign(r01FD, expr(ir_unop_u2i, r01FF), 0x01));

      ir_variable *const r0200 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r0201 = rshift(swizzle_y(r01E9), body.constant(int(20)));
      ir_expression *const r0202 = bit_and(r0201, body.constant(2047u));
      body.emit(assign(r0200, expr(ir_unop_u2i, r0202), 0x01));

      ir_variable *const r0203 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0203, sub(r01FD, r0200), 0x01));

      body.emit(assign(r01F1, r0203, 0x01));

      /* IF CONDITION */
      ir_expression *const r0205 = less(body.constant(int(0)), r0203);
      ir_if *f0204 = new(mem_ctx) ir_if(operand(r0205).val);
      exec_list *const f0204_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0204->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0207 = equal(r01FD, body.constant(int(2047)));
         ir_if *f0206 = new(mem_ctx) ir_if(operand(r0207).val);
         exec_list *const f0206_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0206->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0209 = bit_or(r01FA, swizzle_x(r01E8));
            ir_expression *const r020A = nequal(r0209, body.constant(0u));
            ir_if *f0208 = new(mem_ctx) ir_if(operand(r020A).val);
            exec_list *const f0208_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0208->then_instructions;

               ir_variable *const r020B = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r020B, swizzle_x(r01E8), 0x01));

               ir_variable *const r020C = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r020C, swizzle_x(r01E9), 0x01));

               body.emit(assign(r020B, bit_or(swizzle_y(r01E8), body.constant(524288u)), 0x02));

               body.emit(assign(r020C, bit_or(swizzle_y(r01E9), body.constant(524288u)), 0x02));

               ir_expression *const r020D = lshift(swizzle_y(r01E8), body.constant(int(1)));
               ir_expression *const r020E = gequal(r020D, body.constant(4292870144u));
               ir_expression *const r020F = nequal(swizzle_x(r01E8), body.constant(0u));
               ir_expression *const r0210 = bit_and(swizzle_y(r01E8), body.constant(1048575u));
               ir_expression *const r0211 = nequal(r0210, body.constant(0u));
               ir_expression *const r0212 = logic_or(r020F, r0211);
               ir_expression *const r0213 = logic_and(r020E, r0212);
               ir_swizzle *const r0214 = swizzle(r0213, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0215 = lshift(swizzle_y(r01E9), body.constant(int(1)));
               ir_expression *const r0216 = gequal(r0215, body.constant(4292870144u));
               ir_expression *const r0217 = nequal(swizzle_x(r01E9), body.constant(0u));
               ir_expression *const r0218 = bit_and(swizzle_y(r01E9), body.constant(1048575u));
               ir_expression *const r0219 = nequal(r0218, body.constant(0u));
               ir_expression *const r021A = logic_or(r0217, r0219);
               ir_expression *const r021B = logic_and(r0216, r021A);
               ir_swizzle *const r021C = swizzle(r021B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r021D = expr(ir_triop_csel, r021C, r020C, r020B);
               body.emit(assign(r01EB, expr(ir_triop_csel, r0214, r021D, r020C), 0x03));

               body.emit(assign(r01EA, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0208->else_instructions;

               body.emit(assign(r01EB, r01E8, 0x03));

               body.emit(assign(r01EA, body.constant(false), 0x01));


            body.instructions = f0208_parent_instructions;
            body.emit(f0208);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0206->else_instructions;

            /* IF CONDITION */
            ir_expression *const r021F = equal(r0200, body.constant(int(0)));
            ir_if *f021E = new(mem_ctx) ir_if(operand(r021F).val);
            exec_list *const f021E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f021E->then_instructions;

               body.emit(assign(r01F1, add(r0203, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f021E->else_instructions;

               body.emit(assign(r01F2, bit_or(r01FC, body.constant(1048576u)), 0x01));


            body.instructions = f021E_parent_instructions;
            body.emit(f021E);

            /* END IF */

            ir_variable *const r0220 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0220, body.constant(0u), 0x01));

            ir_variable *const r0221 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0221);
            ir_variable *const r0222 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0222);
            ir_variable *const r0223 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0223);
            ir_variable *const r0224 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0225 = neg(r01F1);
            body.emit(assign(r0224, bit_and(r0225, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0227 = equal(r01F1, body.constant(int(0)));
            ir_if *f0226 = new(mem_ctx) ir_if(operand(r0227).val);
            exec_list *const f0226_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0226->then_instructions;

               body.emit(assign(r0221, r0220, 0x01));

               body.emit(assign(r0222, r01FB, 0x01));

               body.emit(assign(r0223, r01F2, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0226->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0229 = less(r01F1, body.constant(int(32)));
               ir_if *f0228 = new(mem_ctx) ir_if(operand(r0229).val);
               exec_list *const f0228_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0228->then_instructions;

                  body.emit(assign(r0221, lshift(swizzle_x(r01E9), r0224), 0x01));

                  ir_expression *const r022A = lshift(r01F2, r0224);
                  ir_expression *const r022B = rshift(swizzle_x(r01E9), r01F1);
                  body.emit(assign(r0222, bit_or(r022A, r022B), 0x01));

                  body.emit(assign(r0223, rshift(r01F2, r01F1), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0228->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r022D = equal(r01F1, body.constant(int(32)));
                  ir_if *f022C = new(mem_ctx) ir_if(operand(r022D).val);
                  exec_list *const f022C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f022C->then_instructions;

                     body.emit(assign(r0221, r01FB, 0x01));

                     body.emit(assign(r0222, r01F2, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f022C->else_instructions;

                     body.emit(assign(r0220, bit_or(body.constant(0u), swizzle_x(r01E9)), 0x01));

                     ir_expression *const r022E = less(r01F1, body.constant(int(64)));
                     ir_expression *const r022F = lshift(r01F2, r0224);
                     ir_expression *const r0230 = equal(r01F1, body.constant(int(64)));
                     ir_expression *const r0231 = nequal(r01F2, body.constant(0u));
                     ir_expression *const r0232 = expr(ir_unop_b2i, r0231);
                     ir_expression *const r0233 = expr(ir_unop_i2u, r0232);
                     ir_expression *const r0234 = expr(ir_triop_csel, r0230, r01F2, r0233);
                     body.emit(assign(r0221, expr(ir_triop_csel, r022E, r022F, r0234), 0x01));

                     ir_expression *const r0235 = less(r01F1, body.constant(int(64)));
                     ir_expression *const r0236 = bit_and(r01F1, body.constant(int(31)));
                     ir_expression *const r0237 = rshift(r01F2, r0236);
                     body.emit(assign(r0222, expr(ir_triop_csel, r0235, r0237, body.constant(0u)), 0x01));


                  body.instructions = f022C_parent_instructions;
                  body.emit(f022C);

                  /* END IF */

                  body.emit(assign(r0223, body.constant(0u), 0x01));


               body.instructions = f0228_parent_instructions;
               body.emit(f0228);

               /* END IF */

               ir_expression *const r0238 = nequal(r0220, body.constant(0u));
               ir_expression *const r0239 = expr(ir_unop_b2i, r0238);
               ir_expression *const r023A = expr(ir_unop_i2u, r0239);
               body.emit(assign(r0221, bit_or(r0221, r023A), 0x01));


            body.instructions = f0226_parent_instructions;
            body.emit(f0226);

            /* END IF */

            body.emit(assign(r01F2, r0223, 0x01));

            body.emit(assign(r01F3, r0222, 0x01));

            body.emit(assign(r01F7, r0221, 0x01));

            body.emit(assign(r01F6, r01FD, 0x01));


         body.instructions = f0206_parent_instructions;
         body.emit(f0206);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0204->else_instructions;

         /* IF CONDITION */
         ir_expression *const r023C = less(r01F1, body.constant(int(0)));
         ir_if *f023B = new(mem_ctx) ir_if(operand(r023C).val);
         exec_list *const f023B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f023B->then_instructions;

            /* IF CONDITION */
            ir_expression *const r023E = equal(r0200, body.constant(int(2047)));
            ir_if *f023D = new(mem_ctx) ir_if(operand(r023E).val);
            exec_list *const f023D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f023D->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0240 = bit_or(r01F2, r01F3);
               ir_expression *const r0241 = nequal(r0240, body.constant(0u));
               ir_if *f023F = new(mem_ctx) ir_if(operand(r0241).val);
               exec_list *const f023F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f023F->then_instructions;

                  ir_variable *const r0242 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0242, swizzle_x(r01E8), 0x01));

                  ir_variable *const r0243 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0243, swizzle_x(r01E9), 0x01));

                  body.emit(assign(r0242, bit_or(swizzle_y(r01E8), body.constant(524288u)), 0x02));

                  body.emit(assign(r0243, bit_or(swizzle_y(r01E9), body.constant(524288u)), 0x02));

                  ir_expression *const r0244 = lshift(swizzle_y(r01E8), body.constant(int(1)));
                  ir_expression *const r0245 = gequal(r0244, body.constant(4292870144u));
                  ir_expression *const r0246 = nequal(swizzle_x(r01E8), body.constant(0u));
                  ir_expression *const r0247 = bit_and(swizzle_y(r01E8), body.constant(1048575u));
                  ir_expression *const r0248 = nequal(r0247, body.constant(0u));
                  ir_expression *const r0249 = logic_or(r0246, r0248);
                  ir_expression *const r024A = logic_and(r0245, r0249);
                  ir_swizzle *const r024B = swizzle(r024A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r024C = lshift(swizzle_y(r01E9), body.constant(int(1)));
                  ir_expression *const r024D = gequal(r024C, body.constant(4292870144u));
                  ir_expression *const r024E = nequal(swizzle_x(r01E9), body.constant(0u));
                  ir_expression *const r024F = bit_and(swizzle_y(r01E9), body.constant(1048575u));
                  ir_expression *const r0250 = nequal(r024F, body.constant(0u));
                  ir_expression *const r0251 = logic_or(r024E, r0250);
                  ir_expression *const r0252 = logic_and(r024D, r0251);
                  ir_swizzle *const r0253 = swizzle(r0252, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0254 = expr(ir_triop_csel, r0253, r0243, r0242);
                  body.emit(assign(r01EB, expr(ir_triop_csel, r024B, r0254, r0243), 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f023F->else_instructions;

                  ir_variable *const r0255 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0255);
                  ir_expression *const r0256 = lshift(r01ED, body.constant(int(31)));
                  body.emit(assign(r0255, add(r0256, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0255, body.constant(0u), 0x01));

                  body.emit(assign(r01EB, r0255, 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


               body.instructions = f023F_parent_instructions;
               body.emit(f023F);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f023D->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0258 = equal(r01FD, body.constant(int(0)));
               ir_if *f0257 = new(mem_ctx) ir_if(operand(r0258).val);
               exec_list *const f0257_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0257->then_instructions;

                  body.emit(assign(r01F1, add(r01F1, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0257->else_instructions;

                  body.emit(assign(r01F4, bit_or(r01FA, body.constant(1048576u)), 0x01));


               body.instructions = f0257_parent_instructions;
               body.emit(f0257);

               /* END IF */

               ir_variable *const r0259 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0259, body.constant(0u), 0x01));

               ir_variable *const r025A = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r025A, neg(r01F1), 0x01));

               ir_variable *const r025B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r025B);
               ir_variable *const r025C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r025C);
               ir_variable *const r025D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r025D);
               ir_variable *const r025E = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r025F = neg(r025A);
               body.emit(assign(r025E, bit_and(r025F, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0261 = equal(r025A, body.constant(int(0)));
               ir_if *f0260 = new(mem_ctx) ir_if(operand(r0261).val);
               exec_list *const f0260_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0260->then_instructions;

                  body.emit(assign(r025B, r0259, 0x01));

                  body.emit(assign(r025C, r01F9, 0x01));

                  body.emit(assign(r025D, r01F4, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0260->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0263 = less(r025A, body.constant(int(32)));
                  ir_if *f0262 = new(mem_ctx) ir_if(operand(r0263).val);
                  exec_list *const f0262_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0262->then_instructions;

                     body.emit(assign(r025B, lshift(swizzle_x(r01E8), r025E), 0x01));

                     ir_expression *const r0264 = lshift(r01F4, r025E);
                     ir_expression *const r0265 = rshift(swizzle_x(r01E8), r025A);
                     body.emit(assign(r025C, bit_or(r0264, r0265), 0x01));

                     body.emit(assign(r025D, rshift(r01F4, r025A), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0262->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0267 = equal(r025A, body.constant(int(32)));
                     ir_if *f0266 = new(mem_ctx) ir_if(operand(r0267).val);
                     exec_list *const f0266_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0266->then_instructions;

                        body.emit(assign(r025B, r01F9, 0x01));

                        body.emit(assign(r025C, r01F4, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0266->else_instructions;

                        body.emit(assign(r0259, bit_or(body.constant(0u), swizzle_x(r01E8)), 0x01));

                        ir_expression *const r0268 = less(r025A, body.constant(int(64)));
                        ir_expression *const r0269 = lshift(r01F4, r025E);
                        ir_expression *const r026A = equal(r025A, body.constant(int(64)));
                        ir_expression *const r026B = nequal(r01F4, body.constant(0u));
                        ir_expression *const r026C = expr(ir_unop_b2i, r026B);
                        ir_expression *const r026D = expr(ir_unop_i2u, r026C);
                        ir_expression *const r026E = expr(ir_triop_csel, r026A, r01F4, r026D);
                        body.emit(assign(r025B, expr(ir_triop_csel, r0268, r0269, r026E), 0x01));

                        ir_expression *const r026F = less(r025A, body.constant(int(64)));
                        ir_expression *const r0270 = bit_and(r025A, body.constant(int(31)));
                        ir_expression *const r0271 = rshift(r01F4, r0270);
                        body.emit(assign(r025C, expr(ir_triop_csel, r026F, r0271, body.constant(0u)), 0x01));


                     body.instructions = f0266_parent_instructions;
                     body.emit(f0266);

                     /* END IF */

                     body.emit(assign(r025D, body.constant(0u), 0x01));


                  body.instructions = f0262_parent_instructions;
                  body.emit(f0262);

                  /* END IF */

                  ir_expression *const r0272 = nequal(r0259, body.constant(0u));
                  ir_expression *const r0273 = expr(ir_unop_b2i, r0272);
                  ir_expression *const r0274 = expr(ir_unop_i2u, r0273);
                  body.emit(assign(r025B, bit_or(r025B, r0274), 0x01));


               body.instructions = f0260_parent_instructions;
               body.emit(f0260);

               /* END IF */

               body.emit(assign(r01F4, r025D, 0x01));

               body.emit(assign(r01F5, r025C, 0x01));

               body.emit(assign(r01F7, r025B, 0x01));

               body.emit(assign(r01F6, r0200, 0x01));


            body.instructions = f023D_parent_instructions;
            body.emit(f023D);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f023B->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0276 = equal(r01FD, body.constant(int(2047)));
            ir_if *f0275 = new(mem_ctx) ir_if(operand(r0276).val);
            exec_list *const f0275_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0275->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0278 = bit_or(r01F4, r01F5);
               ir_expression *const r0279 = bit_or(r01F2, r01F3);
               ir_expression *const r027A = bit_or(r0278, r0279);
               ir_expression *const r027B = nequal(r027A, body.constant(0u));
               ir_if *f0277 = new(mem_ctx) ir_if(operand(r027B).val);
               exec_list *const f0277_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0277->then_instructions;

                  ir_variable *const r027C = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r027C, swizzle_x(r01E8), 0x01));

                  ir_variable *const r027D = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r027D, swizzle_x(r01E9), 0x01));

                  body.emit(assign(r027C, bit_or(swizzle_y(r01E8), body.constant(524288u)), 0x02));

                  body.emit(assign(r027D, bit_or(swizzle_y(r01E9), body.constant(524288u)), 0x02));

                  ir_expression *const r027E = lshift(swizzle_y(r01E8), body.constant(int(1)));
                  ir_expression *const r027F = gequal(r027E, body.constant(4292870144u));
                  ir_expression *const r0280 = nequal(swizzle_x(r01E8), body.constant(0u));
                  ir_expression *const r0281 = bit_and(swizzle_y(r01E8), body.constant(1048575u));
                  ir_expression *const r0282 = nequal(r0281, body.constant(0u));
                  ir_expression *const r0283 = logic_or(r0280, r0282);
                  ir_expression *const r0284 = logic_and(r027F, r0283);
                  ir_swizzle *const r0285 = swizzle(r0284, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0286 = lshift(swizzle_y(r01E9), body.constant(int(1)));
                  ir_expression *const r0287 = gequal(r0286, body.constant(4292870144u));
                  ir_expression *const r0288 = nequal(swizzle_x(r01E9), body.constant(0u));
                  ir_expression *const r0289 = bit_and(swizzle_y(r01E9), body.constant(1048575u));
                  ir_expression *const r028A = nequal(r0289, body.constant(0u));
                  ir_expression *const r028B = logic_or(r0288, r028A);
                  ir_expression *const r028C = logic_and(r0287, r028B);
                  ir_swizzle *const r028D = swizzle(r028C, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r028E = expr(ir_triop_csel, r028D, r027D, r027C);
                  body.emit(assign(r01EB, expr(ir_triop_csel, r0285, r028E, r027D), 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0277->else_instructions;

                  body.emit(assign(r01EB, r01E8, 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


               body.instructions = f0277_parent_instructions;
               body.emit(f0277);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0275->else_instructions;

               ir_variable *const r028F = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0290 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0290, add(r01F5, r01F3), 0x01));

               ir_expression *const r0291 = add(r01F4, r01F2);
               ir_expression *const r0292 = less(r0290, r01F5);
               ir_expression *const r0293 = expr(ir_unop_b2i, r0292);
               ir_expression *const r0294 = expr(ir_unop_i2u, r0293);
               body.emit(assign(r028F, add(r0291, r0294), 0x01));

               body.emit(assign(r01F8, r028F, 0x01));

               /* IF CONDITION */
               ir_expression *const r0296 = equal(r01FD, body.constant(int(0)));
               ir_if *f0295 = new(mem_ctx) ir_if(operand(r0296).val);
               exec_list *const f0295_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0295->then_instructions;

                  ir_variable *const r0297 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0297);
                  ir_expression *const r0298 = lshift(r01ED, body.constant(int(31)));
                  body.emit(assign(r0297, add(r0298, r028F), 0x02));

                  body.emit(assign(r0297, r0290, 0x01));

                  body.emit(assign(r01EB, r0297, 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0295->else_instructions;

                  body.emit(assign(r01F8, bit_or(r028F, body.constant(2097152u)), 0x01));

                  body.emit(assign(r01F6, r01FD, 0x01));

                  ir_variable *const r0299 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0299);
                  ir_variable *const r029A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r029A);
                  ir_variable *const r029B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r029B);
                  body.emit(assign(r0299, lshift(r0290, body.constant(int(31))), 0x01));

                  ir_expression *const r029C = lshift(r01F8, body.constant(int(31)));
                  ir_expression *const r029D = rshift(r0290, body.constant(int(1)));
                  body.emit(assign(r029A, bit_or(r029C, r029D), 0x01));

                  body.emit(assign(r029B, rshift(r01F8, body.constant(int(1))), 0x01));

                  body.emit(assign(r0299, bit_or(r0299, body.constant(0u)), 0x01));

                  body.emit(assign(r01F8, r029B, 0x01));

                  body.emit(assign(r01F7, r0299, 0x01));

                  ir_variable *const r029E = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r029E, r01FD, 0x01));

                  ir_variable *const r029F = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r029F, r029B, 0x01));

                  ir_variable *const r02A0 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r02A0, r029A, 0x01));

                  ir_variable *const r02A1 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r02A1, r0299, 0x01));

                  ir_variable *const r02A2 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r02A2, body.constant(true), 0x01));

                  ir_variable *const r02A3 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r02A4 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r02A4);
                  ir_expression *const r02A5 = expr(ir_unop_u2i, r0299);
                  body.emit(assign(r02A4, less(r02A5, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r02A7 = gequal(r01FD, body.constant(int(2045)));
                  ir_if *f02A6 = new(mem_ctx) ir_if(operand(r02A7).val);
                  exec_list *const f02A6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02A6->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r02A9 = less(body.constant(int(2045)), r01FD);
                     ir_expression *const r02AA = equal(r01FD, body.constant(int(2045)));
                     ir_expression *const r02AB = equal(body.constant(2097151u), r029B);
                     ir_expression *const r02AC = equal(body.constant(4294967295u), r029A);
                     ir_expression *const r02AD = logic_and(r02AB, r02AC);
                     ir_expression *const r02AE = logic_and(r02AA, r02AD);
                     ir_expression *const r02AF = logic_and(r02AE, r02A4);
                     ir_expression *const r02B0 = logic_or(r02A9, r02AF);
                     ir_if *f02A8 = new(mem_ctx) ir_if(operand(r02B0).val);
                     exec_list *const f02A8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02A8->then_instructions;

                        ir_variable *const r02B1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r02B1);
                        ir_expression *const r02B2 = lshift(r01ED, body.constant(int(31)));
                        body.emit(assign(r02B1, add(r02B2, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r02B1, body.constant(0u), 0x01));

                        body.emit(assign(r02A3, r02B1, 0x03));

                        body.emit(assign(r02A2, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02A8->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02B4 = less(r01FD, body.constant(int(0)));
                        ir_if *f02B3 = new(mem_ctx) ir_if(operand(r02B4).val);
                        exec_list *const f02B3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02B3->then_instructions;

                           ir_variable *const r02B5 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r02B5, r0299, 0x01));

                           ir_variable *const r02B6 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r02B6, neg(r01FD), 0x01));

                           ir_variable *const r02B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r02B7);
                           ir_variable *const r02B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r02B8);
                           ir_variable *const r02B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r02B9);
                           ir_variable *const r02BA = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02BB = neg(r02B6);
                           body.emit(assign(r02BA, bit_and(r02BB, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02BD = equal(r02B6, body.constant(int(0)));
                           ir_if *f02BC = new(mem_ctx) ir_if(operand(r02BD).val);
                           exec_list *const f02BC_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02BC->then_instructions;

                              body.emit(assign(r02B7, r0299, 0x01));

                              body.emit(assign(r02B8, r029A, 0x01));

                              body.emit(assign(r02B9, r029B, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02BC->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02BF = less(r02B6, body.constant(int(32)));
                              ir_if *f02BE = new(mem_ctx) ir_if(operand(r02BF).val);
                              exec_list *const f02BE_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02BE->then_instructions;

                                 body.emit(assign(r02B7, lshift(r029A, r02BA), 0x01));

                                 ir_expression *const r02C0 = lshift(r029B, r02BA);
                                 ir_expression *const r02C1 = rshift(r029A, r02B6);
                                 body.emit(assign(r02B8, bit_or(r02C0, r02C1), 0x01));

                                 body.emit(assign(r02B9, rshift(r029B, r02B6), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02BE->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02C3 = equal(r02B6, body.constant(int(32)));
                                 ir_if *f02C2 = new(mem_ctx) ir_if(operand(r02C3).val);
                                 exec_list *const f02C2_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02C2->then_instructions;

                                    body.emit(assign(r02B7, r029A, 0x01));

                                    body.emit(assign(r02B8, r029B, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02C2->else_instructions;

                                    body.emit(assign(r02B5, bit_or(r0299, r029A), 0x01));

                                    ir_expression *const r02C4 = less(r02B6, body.constant(int(64)));
                                    ir_expression *const r02C5 = lshift(r029B, r02BA);
                                    ir_expression *const r02C6 = equal(r02B6, body.constant(int(64)));
                                    ir_expression *const r02C7 = nequal(r029B, body.constant(0u));
                                    ir_expression *const r02C8 = expr(ir_unop_b2i, r02C7);
                                    ir_expression *const r02C9 = expr(ir_unop_i2u, r02C8);
                                    ir_expression *const r02CA = expr(ir_triop_csel, r02C6, r029B, r02C9);
                                    body.emit(assign(r02B7, expr(ir_triop_csel, r02C4, r02C5, r02CA), 0x01));

                                    ir_expression *const r02CB = less(r02B6, body.constant(int(64)));
                                    ir_expression *const r02CC = bit_and(r02B6, body.constant(int(31)));
                                    ir_expression *const r02CD = rshift(r029B, r02CC);
                                    body.emit(assign(r02B8, expr(ir_triop_csel, r02CB, r02CD, body.constant(0u)), 0x01));


                                 body.instructions = f02C2_parent_instructions;
                                 body.emit(f02C2);

                                 /* END IF */

                                 body.emit(assign(r02B9, body.constant(0u), 0x01));


                              body.instructions = f02BE_parent_instructions;
                              body.emit(f02BE);

                              /* END IF */

                              ir_expression *const r02CE = nequal(r02B5, body.constant(0u));
                              ir_expression *const r02CF = expr(ir_unop_b2i, r02CE);
                              ir_expression *const r02D0 = expr(ir_unop_i2u, r02CF);
                              body.emit(assign(r02B7, bit_or(r02B7, r02D0), 0x01));


                           body.instructions = f02BC_parent_instructions;
                           body.emit(f02BC);

                           /* END IF */

                           body.emit(assign(r029F, r02B9, 0x01));

                           body.emit(assign(r02A0, r02B8, 0x01));

                           body.emit(assign(r02A1, r02B7, 0x01));

                           body.emit(assign(r029E, body.constant(int(0)), 0x01));

                           body.emit(assign(r02A4, less(r02B7, body.constant(0u)), 0x01));


                        body.instructions = f02B3_parent_instructions;
                        body.emit(f02B3);

                        /* END IF */


                     body.instructions = f02A8_parent_instructions;
                     body.emit(f02A8);

                     /* END IF */


                  body.instructions = f02A6_parent_instructions;
                  body.emit(f02A6);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02D1 = new(mem_ctx) ir_if(operand(r02A2).val);
                  exec_list *const f02D1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02D1->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02D2 = new(mem_ctx) ir_if(operand(r02A4).val);
                     exec_list *const f02D2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02D2->then_instructions;

                        ir_variable *const r02D3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02D3, add(r02A0, body.constant(1u)), 0x01));

                        ir_expression *const r02D4 = less(r02D3, r02A0);
                        ir_expression *const r02D5 = expr(ir_unop_b2i, r02D4);
                        ir_expression *const r02D6 = expr(ir_unop_i2u, r02D5);
                        body.emit(assign(r029F, add(r029F, r02D6), 0x01));

                        ir_expression *const r02D7 = equal(r02A1, body.constant(0u));
                        ir_expression *const r02D8 = expr(ir_unop_b2i, r02D7);
                        ir_expression *const r02D9 = expr(ir_unop_i2u, r02D8);
                        ir_expression *const r02DA = add(r02A1, r02D9);
                        ir_expression *const r02DB = bit_and(r02DA, body.constant(1u));
                        ir_expression *const r02DC = expr(ir_unop_bit_not, r02DB);
                        body.emit(assign(r02A0, bit_and(r02D3, r02DC), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02D2->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02DE = bit_or(r029F, r02A0);
                        ir_expression *const r02DF = equal(r02DE, body.constant(0u));
                        ir_if *f02DD = new(mem_ctx) ir_if(operand(r02DF).val);
                        exec_list *const f02DD_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02DD->then_instructions;

                           body.emit(assign(r029E, body.constant(int(0)), 0x01));


                        body.instructions = f02DD_parent_instructions;
                        body.emit(f02DD);

                        /* END IF */


                     body.instructions = f02D2_parent_instructions;
                     body.emit(f02D2);

                     /* END IF */

                     ir_variable *const r02E0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r02E0);
                     ir_expression *const r02E1 = lshift(r01ED, body.constant(int(31)));
                     ir_expression *const r02E2 = expr(ir_unop_i2u, r029E);
                     ir_expression *const r02E3 = lshift(r02E2, body.constant(int(20)));
                     ir_expression *const r02E4 = add(r02E1, r02E3);
                     body.emit(assign(r02E0, add(r02E4, r029F), 0x02));

                     body.emit(assign(r02E0, r02A0, 0x01));

                     body.emit(assign(r02A3, r02E0, 0x03));

                     body.emit(assign(r02A2, body.constant(false), 0x01));


                  body.instructions = f02D1_parent_instructions;
                  body.emit(f02D1);

                  /* END IF */

                  body.emit(assign(r01EB, r02A3, 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


               body.instructions = f0295_parent_instructions;
               body.emit(f0295);

               /* END IF */


            body.instructions = f0275_parent_instructions;
            body.emit(f0275);

            /* END IF */


         body.instructions = f023B_parent_instructions;
         body.emit(f023B);

         /* END IF */


      body.instructions = f0204_parent_instructions;
      body.emit(f0204);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02E5 = new(mem_ctx) ir_if(operand(r01EA).val);
      exec_list *const f02E5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02E5->then_instructions;

         body.emit(assign(r01F4, bit_or(r01F4, body.constant(1048576u)), 0x01));

         ir_variable *const r02E6 = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r02E7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r02E7, add(r01F5, r01F3), 0x01));

         ir_expression *const r02E8 = add(r01F4, r01F2);
         ir_expression *const r02E9 = less(r02E7, r01F5);
         ir_expression *const r02EA = expr(ir_unop_b2i, r02E9);
         ir_expression *const r02EB = expr(ir_unop_i2u, r02EA);
         body.emit(assign(r02E6, add(r02E8, r02EB), 0x01));

         body.emit(assign(r01F8, r02E6, 0x01));

         body.emit(assign(r01F6, add(r01F6, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r02ED = less(r02E6, body.constant(2097152u));
         ir_if *f02EC = new(mem_ctx) ir_if(operand(r02ED).val);
         exec_list *const f02EC_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02EC->then_instructions;

            ir_variable *const r02EE = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r02EE, r01F6, 0x01));

            ir_variable *const r02EF = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r02EF, r02E6, 0x01));

            ir_variable *const r02F0 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r02F0, r02E7, 0x01));

            ir_variable *const r02F1 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r02F1, r01F7, 0x01));

            ir_variable *const r02F2 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r02F2, body.constant(true), 0x01));

            ir_variable *const r02F3 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r02F4 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r02F4);
            ir_expression *const r02F5 = expr(ir_unop_u2i, r01F7);
            body.emit(assign(r02F4, less(r02F5, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02F7 = gequal(r01F6, body.constant(int(2045)));
            ir_if *f02F6 = new(mem_ctx) ir_if(operand(r02F7).val);
            exec_list *const f02F6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02F6->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02F9 = less(body.constant(int(2045)), r01F6);
               ir_expression *const r02FA = equal(r01F6, body.constant(int(2045)));
               ir_expression *const r02FB = equal(body.constant(2097151u), r02E6);
               ir_expression *const r02FC = equal(body.constant(4294967295u), r02E7);
               ir_expression *const r02FD = logic_and(r02FB, r02FC);
               ir_expression *const r02FE = logic_and(r02FA, r02FD);
               ir_expression *const r02FF = logic_and(r02FE, r02F4);
               ir_expression *const r0300 = logic_or(r02F9, r02FF);
               ir_if *f02F8 = new(mem_ctx) ir_if(operand(r0300).val);
               exec_list *const f02F8_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02F8->then_instructions;

                  ir_variable *const r0301 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0301);
                  ir_expression *const r0302 = lshift(r01ED, body.constant(int(31)));
                  body.emit(assign(r0301, add(r0302, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0301, body.constant(0u), 0x01));

                  body.emit(assign(r02F3, r0301, 0x03));

                  body.emit(assign(r02F2, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02F8->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0304 = less(r01F6, body.constant(int(0)));
                  ir_if *f0303 = new(mem_ctx) ir_if(operand(r0304).val);
                  exec_list *const f0303_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0303->then_instructions;

                     ir_variable *const r0305 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0305, r01F7, 0x01));

                     ir_variable *const r0306 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0306, neg(r01F6), 0x01));

                     ir_variable *const r0307 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0307);
                     ir_variable *const r0308 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0308);
                     ir_variable *const r0309 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0309);
                     ir_variable *const r030A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r030B = neg(r0306);
                     body.emit(assign(r030A, bit_and(r030B, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r030D = equal(r0306, body.constant(int(0)));
                     ir_if *f030C = new(mem_ctx) ir_if(operand(r030D).val);
                     exec_list *const f030C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f030C->then_instructions;

                        body.emit(assign(r0307, r01F7, 0x01));

                        body.emit(assign(r0308, r02E7, 0x01));

                        body.emit(assign(r0309, r02E6, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f030C->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r030F = less(r0306, body.constant(int(32)));
                        ir_if *f030E = new(mem_ctx) ir_if(operand(r030F).val);
                        exec_list *const f030E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f030E->then_instructions;

                           body.emit(assign(r0307, lshift(r02E7, r030A), 0x01));

                           ir_expression *const r0310 = lshift(r02E6, r030A);
                           ir_expression *const r0311 = rshift(r02E7, r0306);
                           body.emit(assign(r0308, bit_or(r0310, r0311), 0x01));

                           body.emit(assign(r0309, rshift(r02E6, r0306), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f030E->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0313 = equal(r0306, body.constant(int(32)));
                           ir_if *f0312 = new(mem_ctx) ir_if(operand(r0313).val);
                           exec_list *const f0312_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0312->then_instructions;

                              body.emit(assign(r0307, r02E7, 0x01));

                              body.emit(assign(r0308, r02E6, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0312->else_instructions;

                              body.emit(assign(r0305, bit_or(r01F7, r02E7), 0x01));

                              ir_expression *const r0314 = less(r0306, body.constant(int(64)));
                              ir_expression *const r0315 = lshift(r02E6, r030A);
                              ir_expression *const r0316 = equal(r0306, body.constant(int(64)));
                              ir_expression *const r0317 = nequal(r02E6, body.constant(0u));
                              ir_expression *const r0318 = expr(ir_unop_b2i, r0317);
                              ir_expression *const r0319 = expr(ir_unop_i2u, r0318);
                              ir_expression *const r031A = expr(ir_triop_csel, r0316, r02E6, r0319);
                              body.emit(assign(r0307, expr(ir_triop_csel, r0314, r0315, r031A), 0x01));

                              ir_expression *const r031B = less(r0306, body.constant(int(64)));
                              ir_expression *const r031C = bit_and(r0306, body.constant(int(31)));
                              ir_expression *const r031D = rshift(r02E6, r031C);
                              body.emit(assign(r0308, expr(ir_triop_csel, r031B, r031D, body.constant(0u)), 0x01));


                           body.instructions = f0312_parent_instructions;
                           body.emit(f0312);

                           /* END IF */

                           body.emit(assign(r0309, body.constant(0u), 0x01));


                        body.instructions = f030E_parent_instructions;
                        body.emit(f030E);

                        /* END IF */

                        ir_expression *const r031E = nequal(r0305, body.constant(0u));
                        ir_expression *const r031F = expr(ir_unop_b2i, r031E);
                        ir_expression *const r0320 = expr(ir_unop_i2u, r031F);
                        body.emit(assign(r0307, bit_or(r0307, r0320), 0x01));


                     body.instructions = f030C_parent_instructions;
                     body.emit(f030C);

                     /* END IF */

                     body.emit(assign(r02EF, r0309, 0x01));

                     body.emit(assign(r02F0, r0308, 0x01));

                     body.emit(assign(r02F1, r0307, 0x01));

                     body.emit(assign(r02EE, body.constant(int(0)), 0x01));

                     body.emit(assign(r02F4, less(r0307, body.constant(0u)), 0x01));


                  body.instructions = f0303_parent_instructions;
                  body.emit(f0303);

                  /* END IF */


               body.instructions = f02F8_parent_instructions;
               body.emit(f02F8);

               /* END IF */


            body.instructions = f02F6_parent_instructions;
            body.emit(f02F6);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0321 = new(mem_ctx) ir_if(operand(r02F2).val);
            exec_list *const f0321_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0321->then_instructions;

               /* IF CONDITION */
               ir_if *f0322 = new(mem_ctx) ir_if(operand(r02F4).val);
               exec_list *const f0322_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0322->then_instructions;

                  ir_variable *const r0323 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0323, add(r02F0, body.constant(1u)), 0x01));

                  ir_expression *const r0324 = less(r0323, r02F0);
                  ir_expression *const r0325 = expr(ir_unop_b2i, r0324);
                  ir_expression *const r0326 = expr(ir_unop_i2u, r0325);
                  body.emit(assign(r02EF, add(r02EF, r0326), 0x01));

                  ir_expression *const r0327 = equal(r02F1, body.constant(0u));
                  ir_expression *const r0328 = expr(ir_unop_b2i, r0327);
                  ir_expression *const r0329 = expr(ir_unop_i2u, r0328);
                  ir_expression *const r032A = add(r02F1, r0329);
                  ir_expression *const r032B = bit_and(r032A, body.constant(1u));
                  ir_expression *const r032C = expr(ir_unop_bit_not, r032B);
                  body.emit(assign(r02F0, bit_and(r0323, r032C), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0322->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r032E = bit_or(r02EF, r02F0);
                  ir_expression *const r032F = equal(r032E, body.constant(0u));
                  ir_if *f032D = new(mem_ctx) ir_if(operand(r032F).val);
                  exec_list *const f032D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f032D->then_instructions;

                     body.emit(assign(r02EE, body.constant(int(0)), 0x01));


                  body.instructions = f032D_parent_instructions;
                  body.emit(f032D);

                  /* END IF */


               body.instructions = f0322_parent_instructions;
               body.emit(f0322);

               /* END IF */

               ir_variable *const r0330 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0330);
               ir_expression *const r0331 = lshift(r01ED, body.constant(int(31)));
               ir_expression *const r0332 = expr(ir_unop_i2u, r02EE);
               ir_expression *const r0333 = lshift(r0332, body.constant(int(20)));
               ir_expression *const r0334 = add(r0331, r0333);
               body.emit(assign(r0330, add(r0334, r02EF), 0x02));

               body.emit(assign(r0330, r02F0, 0x01));

               body.emit(assign(r02F3, r0330, 0x03));

               body.emit(assign(r02F2, body.constant(false), 0x01));


            body.instructions = f0321_parent_instructions;
            body.emit(f0321);

            /* END IF */

            body.emit(assign(r01EB, r02F3, 0x03));

            body.emit(assign(r01EA, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02EC->else_instructions;

            body.emit(assign(r01F6, add(r01F6, body.constant(int(1))), 0x01));

            ir_variable *const r0335 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0335);
            ir_variable *const r0336 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0336);
            ir_variable *const r0337 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0337);
            body.emit(assign(r0335, lshift(r02E7, body.constant(int(31))), 0x01));

            ir_expression *const r0338 = lshift(r02E6, body.constant(int(31)));
            ir_expression *const r0339 = rshift(r02E7, body.constant(int(1)));
            body.emit(assign(r0336, bit_or(r0338, r0339), 0x01));

            body.emit(assign(r0337, rshift(r02E6, body.constant(int(1))), 0x01));

            ir_expression *const r033A = nequal(r01F7, body.constant(0u));
            ir_expression *const r033B = expr(ir_unop_b2i, r033A);
            ir_expression *const r033C = expr(ir_unop_i2u, r033B);
            body.emit(assign(r0335, bit_or(r0335, r033C), 0x01));

            body.emit(assign(r01F8, r0337, 0x01));

            body.emit(assign(r01F7, r0335, 0x01));

            ir_variable *const r033D = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r033D, r01F6, 0x01));

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
            ir_expression *const r0346 = gequal(r01F6, body.constant(int(2045)));
            ir_if *f0345 = new(mem_ctx) ir_if(operand(r0346).val);
            exec_list *const f0345_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0345->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0348 = less(body.constant(int(2045)), r01F6);
               ir_expression *const r0349 = equal(r01F6, body.constant(int(2045)));
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
                  ir_expression *const r0351 = lshift(r01ED, body.constant(int(31)));
                  body.emit(assign(r0350, add(r0351, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0350, body.constant(0u), 0x01));

                  body.emit(assign(r0342, r0350, 0x03));

                  body.emit(assign(r0341, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0347->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0353 = less(r01F6, body.constant(int(0)));
                  ir_if *f0352 = new(mem_ctx) ir_if(operand(r0353).val);
                  exec_list *const f0352_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0352->then_instructions;

                     ir_variable *const r0354 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0354, r0335, 0x01));

                     ir_variable *const r0355 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0355, neg(r01F6), 0x01));

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

                  /* IF CONDITION */
                  ir_expression *const r037D = bit_or(r033E, r033F);
                  ir_expression *const r037E = equal(r037D, body.constant(0u));
                  ir_if *f037C = new(mem_ctx) ir_if(operand(r037E).val);
                  exec_list *const f037C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f037C->then_instructions;

                     body.emit(assign(r033D, body.constant(int(0)), 0x01));


                  body.instructions = f037C_parent_instructions;
                  body.emit(f037C);

                  /* END IF */


               body.instructions = f0371_parent_instructions;
               body.emit(f0371);

               /* END IF */

               ir_variable *const r037F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r037F);
               ir_expression *const r0380 = lshift(r01ED, body.constant(int(31)));
               ir_expression *const r0381 = expr(ir_unop_i2u, r033D);
               ir_expression *const r0382 = lshift(r0381, body.constant(int(20)));
               ir_expression *const r0383 = add(r0380, r0382);
               body.emit(assign(r037F, add(r0383, r033E), 0x02));

               body.emit(assign(r037F, r033F, 0x01));

               body.emit(assign(r0342, r037F, 0x03));

               body.emit(assign(r0341, body.constant(false), 0x01));


            body.instructions = f0370_parent_instructions;
            body.emit(f0370);

            /* END IF */

            body.emit(assign(r01EB, r0342, 0x03));

            body.emit(assign(r01EA, body.constant(false), 0x01));


         body.instructions = f02EC_parent_instructions;
         body.emit(f02EC);

         /* END IF */


      body.instructions = f02E5_parent_instructions;
      body.emit(f02E5);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01EF->else_instructions;

      ir_variable *const r0384 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r0384);
      ir_variable *const r0385 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
      body.emit(r0385);
      ir_variable *const r0386 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
      body.emit(r0386);
      ir_variable *const r0387 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r0387);
      ir_variable *const r0388 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r0388);
      ir_variable *const r0389 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r0389);
      ir_variable *const r038A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r038A);
      ir_variable *const r038B = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r038B);
      ir_variable *const r038C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r038D = rshift(swizzle_y(r01E8), body.constant(int(20)));
      ir_expression *const r038E = bit_and(r038D, body.constant(2047u));
      body.emit(assign(r038C, expr(ir_unop_u2i, r038E), 0x01));

      body.emit(assign(r0386, r038C, 0x01));

      ir_variable *const r038F = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r0390 = rshift(swizzle_y(r01E9), body.constant(int(20)));
      ir_expression *const r0391 = bit_and(r0390, body.constant(2047u));
      body.emit(assign(r038F, expr(ir_unop_u2i, r0391), 0x01));

      body.emit(assign(r0385, r038F, 0x01));

      body.emit(assign(r0384, sub(r038C, r038F), 0x01));

      ir_variable *const r0392 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r0393 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0393, lshift(swizzle_x(r01E8), body.constant(int(10))), 0x01));

      ir_expression *const r0394 = bit_and(swizzle_y(r01E8), body.constant(1048575u));
      ir_expression *const r0395 = lshift(r0394, body.constant(int(10)));
      ir_expression *const r0396 = rshift(swizzle_x(r01E8), body.constant(int(22)));
      body.emit(assign(r0392, bit_or(r0395, r0396), 0x01));

      body.emit(assign(r0389, r0392, 0x01));

      body.emit(assign(r038A, r0393, 0x01));

      ir_variable *const r0397 = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r0398 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0398, lshift(swizzle_x(r01E9), body.constant(int(10))), 0x01));

      ir_expression *const r0399 = bit_and(swizzle_y(r01E9), body.constant(1048575u));
      ir_expression *const r039A = lshift(r0399, body.constant(int(10)));
      ir_expression *const r039B = rshift(swizzle_x(r01E9), body.constant(int(22)));
      body.emit(assign(r0397, bit_or(r039A, r039B), 0x01));

      body.emit(assign(r0387, r0397, 0x01));

      body.emit(assign(r0388, r0398, 0x01));

      /* IF CONDITION */
      ir_expression *const r039D = less(body.constant(int(0)), r0384);
      ir_if *f039C = new(mem_ctx) ir_if(operand(r039D).val);
      exec_list *const f039C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f039C->then_instructions;

         /* IF CONDITION */
         ir_expression *const r039F = equal(r038C, body.constant(int(2047)));
         ir_if *f039E = new(mem_ctx) ir_if(operand(r039F).val);
         exec_list *const f039E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f039E->then_instructions;

            /* IF CONDITION */
            ir_expression *const r03A1 = bit_or(r0392, r0393);
            ir_expression *const r03A2 = nequal(r03A1, body.constant(0u));
            ir_if *f03A0 = new(mem_ctx) ir_if(operand(r03A2).val);
            exec_list *const f03A0_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03A0->then_instructions;

               ir_variable *const r03A3 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r03A3, swizzle_x(r01E8), 0x01));

               ir_variable *const r03A4 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r03A4, swizzle_x(r01E9), 0x01));

               body.emit(assign(r03A3, bit_or(swizzle_y(r01E8), body.constant(524288u)), 0x02));

               body.emit(assign(r03A4, bit_or(swizzle_y(r01E9), body.constant(524288u)), 0x02));

               ir_expression *const r03A5 = lshift(swizzle_y(r01E8), body.constant(int(1)));
               ir_expression *const r03A6 = gequal(r03A5, body.constant(4292870144u));
               ir_expression *const r03A7 = nequal(swizzle_x(r01E8), body.constant(0u));
               ir_expression *const r03A8 = bit_and(swizzle_y(r01E8), body.constant(1048575u));
               ir_expression *const r03A9 = nequal(r03A8, body.constant(0u));
               ir_expression *const r03AA = logic_or(r03A7, r03A9);
               ir_expression *const r03AB = logic_and(r03A6, r03AA);
               ir_swizzle *const r03AC = swizzle(r03AB, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r03AD = lshift(swizzle_y(r01E9), body.constant(int(1)));
               ir_expression *const r03AE = gequal(r03AD, body.constant(4292870144u));
               ir_expression *const r03AF = nequal(swizzle_x(r01E9), body.constant(0u));
               ir_expression *const r03B0 = bit_and(swizzle_y(r01E9), body.constant(1048575u));
               ir_expression *const r03B1 = nequal(r03B0, body.constant(0u));
               ir_expression *const r03B2 = logic_or(r03AF, r03B1);
               ir_expression *const r03B3 = logic_and(r03AE, r03B2);
               ir_swizzle *const r03B4 = swizzle(r03B3, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r03B5 = expr(ir_triop_csel, r03B4, r03A4, r03A3);
               body.emit(assign(r01EB, expr(ir_triop_csel, r03AC, r03B5, r03A4), 0x03));

               body.emit(assign(r01EA, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03A0->else_instructions;

               body.emit(assign(r01EB, r01E8, 0x03));

               body.emit(assign(r01EA, body.constant(false), 0x01));


            body.instructions = f03A0_parent_instructions;
            body.emit(f03A0);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f039E->else_instructions;

            /* IF CONDITION */
            ir_expression *const r03B7 = equal(r038F, body.constant(int(0)));
            ir_if *f03B6 = new(mem_ctx) ir_if(operand(r03B7).val);
            exec_list *const f03B6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03B6->then_instructions;

               body.emit(assign(r0384, add(r0384, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03B6->else_instructions;

               body.emit(assign(r0387, bit_or(r0397, body.constant(1073741824u)), 0x01));


            body.instructions = f03B6_parent_instructions;
            body.emit(f03B6);

            /* END IF */

            ir_variable *const r03B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r03B8);
            ir_variable *const r03B9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r03BA = neg(r0384);
            body.emit(assign(r03B9, bit_and(r03BA, body.constant(int(31))), 0x01));

            ir_variable *const r03BB = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r03BC = less(r0384, body.constant(int(32)));
            ir_expression *const r03BD = rshift(r0387, r0384);
            ir_expression *const r03BE = equal(r0384, body.constant(int(0)));
            ir_expression *const r03BF = expr(ir_triop_csel, r03BE, r0387, body.constant(0u));
            body.emit(assign(r03BB, expr(ir_triop_csel, r03BC, r03BD, r03BF), 0x01));

            /* IF CONDITION */
            ir_expression *const r03C1 = equal(r0384, body.constant(int(0)));
            ir_if *f03C0 = new(mem_ctx) ir_if(operand(r03C1).val);
            exec_list *const f03C0_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03C0->then_instructions;

               body.emit(assign(r03B8, r0398, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03C0->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03C3 = less(r0384, body.constant(int(32)));
               ir_if *f03C2 = new(mem_ctx) ir_if(operand(r03C3).val);
               exec_list *const f03C2_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03C2->then_instructions;

                  ir_expression *const r03C4 = lshift(r0387, r03B9);
                  ir_expression *const r03C5 = rshift(r0398, r0384);
                  ir_expression *const r03C6 = bit_or(r03C4, r03C5);
                  ir_expression *const r03C7 = lshift(r0398, r03B9);
                  ir_expression *const r03C8 = nequal(r03C7, body.constant(0u));
                  ir_expression *const r03C9 = expr(ir_unop_b2i, r03C8);
                  ir_expression *const r03CA = expr(ir_unop_i2u, r03C9);
                  body.emit(assign(r03B8, bit_or(r03C6, r03CA), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03C2->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03CC = equal(r0384, body.constant(int(32)));
                  ir_if *f03CB = new(mem_ctx) ir_if(operand(r03CC).val);
                  exec_list *const f03CB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03CB->then_instructions;

                     ir_expression *const r03CD = nequal(r0398, body.constant(0u));
                     ir_expression *const r03CE = expr(ir_unop_b2i, r03CD);
                     ir_expression *const r03CF = expr(ir_unop_i2u, r03CE);
                     body.emit(assign(r03B8, bit_or(r0387, r03CF), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03CB->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03D1 = less(r0384, body.constant(int(64)));
                     ir_if *f03D0 = new(mem_ctx) ir_if(operand(r03D1).val);
                     exec_list *const f03D0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03D0->then_instructions;

                        ir_expression *const r03D2 = bit_and(r0384, body.constant(int(31)));
                        ir_expression *const r03D3 = rshift(r0387, r03D2);
                        ir_expression *const r03D4 = lshift(r0387, r03B9);
                        ir_expression *const r03D5 = bit_or(r03D4, r0398);
                        ir_expression *const r03D6 = nequal(r03D5, body.constant(0u));
                        ir_expression *const r03D7 = expr(ir_unop_b2i, r03D6);
                        ir_expression *const r03D8 = expr(ir_unop_i2u, r03D7);
                        body.emit(assign(r03B8, bit_or(r03D3, r03D8), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03D0->else_instructions;

                        ir_expression *const r03D9 = bit_or(r0387, r0398);
                        ir_expression *const r03DA = nequal(r03D9, body.constant(0u));
                        ir_expression *const r03DB = expr(ir_unop_b2i, r03DA);
                        body.emit(assign(r03B8, expr(ir_unop_i2u, r03DB), 0x01));


                     body.instructions = f03D0_parent_instructions;
                     body.emit(f03D0);

                     /* END IF */


                  body.instructions = f03CB_parent_instructions;
                  body.emit(f03CB);

                  /* END IF */


               body.instructions = f03C2_parent_instructions;
               body.emit(f03C2);

               /* END IF */


            body.instructions = f03C0_parent_instructions;
            body.emit(f03C0);

            /* END IF */

            body.emit(assign(r0387, r03BB, 0x01));

            body.emit(assign(r0388, r03B8, 0x01));

            body.emit(assign(r0389, bit_or(r0392, body.constant(1073741824u)), 0x01));

            ir_variable *const r03DC = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r03DD = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r03DD, sub(r0393, r03B8), 0x01));

            ir_expression *const r03DE = sub(r0389, r03BB);
            ir_expression *const r03DF = less(r0393, r03B8);
            ir_expression *const r03E0 = expr(ir_unop_b2i, r03DF);
            ir_expression *const r03E1 = expr(ir_unop_i2u, r03E0);
            body.emit(assign(r03DC, sub(r03DE, r03E1), 0x01));

            body.emit(assign(r038B, add(r038C, body.constant(int(-1))), 0x01));

            ir_variable *const r03E2 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03E2, add(r038B, body.constant(int(-10))), 0x01));

            ir_variable *const r03E3 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03E3, r03DC, 0x01));

            ir_variable *const r03E4 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03E4, r03DD, 0x01));

            ir_variable *const r03E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03E5);
            ir_variable *const r03E6 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03E6);
            /* IF CONDITION */
            ir_expression *const r03E8 = equal(r03DC, body.constant(0u));
            ir_if *f03E7 = new(mem_ctx) ir_if(operand(r03E8).val);
            exec_list *const f03E7_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03E7->then_instructions;

               body.emit(assign(r03E3, r03DD, 0x01));

               body.emit(assign(r03E4, body.constant(0u), 0x01));

               body.emit(assign(r03E2, add(r03E2, body.constant(int(-32))), 0x01));


            body.instructions = f03E7_parent_instructions;
            body.emit(f03E7);

            /* END IF */

            ir_variable *const r03E9 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r03E9, r03E3, 0x01));

            ir_variable *const r03EA = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r03EB = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03EB);
            /* IF CONDITION */
            ir_expression *const r03ED = equal(r03E3, body.constant(0u));
            ir_if *f03EC = new(mem_ctx) ir_if(operand(r03ED).val);
            exec_list *const f03EC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03EC->then_instructions;

               body.emit(assign(r03EA, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03EC->else_instructions;

               body.emit(assign(r03EB, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r03EF = bit_and(r03E3, body.constant(4294901760u));
               ir_expression *const r03F0 = equal(r03EF, body.constant(0u));
               ir_if *f03EE = new(mem_ctx) ir_if(operand(r03F0).val);
               exec_list *const f03EE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03EE->then_instructions;

                  body.emit(assign(r03EB, body.constant(int(16)), 0x01));

                  body.emit(assign(r03E9, lshift(r03E3, body.constant(int(16))), 0x01));


               body.instructions = f03EE_parent_instructions;
               body.emit(f03EE);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03F2 = bit_and(r03E9, body.constant(4278190080u));
               ir_expression *const r03F3 = equal(r03F2, body.constant(0u));
               ir_if *f03F1 = new(mem_ctx) ir_if(operand(r03F3).val);
               exec_list *const f03F1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F1->then_instructions;

                  body.emit(assign(r03EB, add(r03EB, body.constant(int(8))), 0x01));

                  body.emit(assign(r03E9, lshift(r03E9, body.constant(int(8))), 0x01));


               body.instructions = f03F1_parent_instructions;
               body.emit(f03F1);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03F5 = bit_and(r03E9, body.constant(4026531840u));
               ir_expression *const r03F6 = equal(r03F5, body.constant(0u));
               ir_if *f03F4 = new(mem_ctx) ir_if(operand(r03F6).val);
               exec_list *const f03F4_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F4->then_instructions;

                  body.emit(assign(r03EB, add(r03EB, body.constant(int(4))), 0x01));

                  body.emit(assign(r03E9, lshift(r03E9, body.constant(int(4))), 0x01));


               body.instructions = f03F4_parent_instructions;
               body.emit(f03F4);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03F8 = bit_and(r03E9, body.constant(3221225472u));
               ir_expression *const r03F9 = equal(r03F8, body.constant(0u));
               ir_if *f03F7 = new(mem_ctx) ir_if(operand(r03F9).val);
               exec_list *const f03F7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F7->then_instructions;

                  body.emit(assign(r03EB, add(r03EB, body.constant(int(2))), 0x01));

                  body.emit(assign(r03E9, lshift(r03E9, body.constant(int(2))), 0x01));


               body.instructions = f03F7_parent_instructions;
               body.emit(f03F7);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03FB = bit_and(r03E9, body.constant(2147483648u));
               ir_expression *const r03FC = equal(r03FB, body.constant(0u));
               ir_if *f03FA = new(mem_ctx) ir_if(operand(r03FC).val);
               exec_list *const f03FA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03FA->then_instructions;

                  body.emit(assign(r03EB, add(r03EB, body.constant(int(1))), 0x01));


               body.instructions = f03FA_parent_instructions;
               body.emit(f03FA);

               /* END IF */

               body.emit(assign(r03EA, r03EB, 0x01));


            body.instructions = f03EC_parent_instructions;
            body.emit(f03EC);

            /* END IF */

            body.emit(assign(r03E6, add(r03EA, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03FE = gequal(r03E6, body.constant(int(0)));
            ir_if *f03FD = new(mem_ctx) ir_if(operand(r03FE).val);
            exec_list *const f03FD_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03FD->then_instructions;

               body.emit(assign(r03E5, body.constant(0u), 0x01));

               ir_expression *const r03FF = equal(r03E6, body.constant(int(0)));
               ir_expression *const r0400 = lshift(r03E3, r03E6);
               ir_expression *const r0401 = neg(r03E6);
               ir_expression *const r0402 = bit_and(r0401, body.constant(int(31)));
               ir_expression *const r0403 = rshift(r03E4, r0402);
               ir_expression *const r0404 = bit_or(r0400, r0403);
               body.emit(assign(r03E3, expr(ir_triop_csel, r03FF, r03E3, r0404), 0x01));

               body.emit(assign(r03E4, lshift(r03E4, r03E6), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03FD->else_instructions;

               ir_variable *const r0405 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0405, body.constant(0u), 0x01));

               ir_variable *const r0406 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0406, neg(r03E6), 0x01));

               ir_variable *const r0407 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0407);
               ir_variable *const r0408 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0408);
               ir_variable *const r0409 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0409);
               ir_variable *const r040A = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r040B = neg(r0406);
               body.emit(assign(r040A, bit_and(r040B, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r040D = equal(r0406, body.constant(int(0)));
               ir_if *f040C = new(mem_ctx) ir_if(operand(r040D).val);
               exec_list *const f040C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f040C->then_instructions;

                  body.emit(assign(r0407, r0405, 0x01));

                  body.emit(assign(r0408, r03E4, 0x01));

                  body.emit(assign(r0409, r03E3, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f040C->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r040F = less(r0406, body.constant(int(32)));
                  ir_if *f040E = new(mem_ctx) ir_if(operand(r040F).val);
                  exec_list *const f040E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f040E->then_instructions;

                     body.emit(assign(r0407, lshift(r03E4, r040A), 0x01));

                     ir_expression *const r0410 = lshift(r03E3, r040A);
                     ir_expression *const r0411 = rshift(r03E4, r0406);
                     body.emit(assign(r0408, bit_or(r0410, r0411), 0x01));

                     body.emit(assign(r0409, rshift(r03E3, r0406), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f040E->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0413 = equal(r0406, body.constant(int(32)));
                     ir_if *f0412 = new(mem_ctx) ir_if(operand(r0413).val);
                     exec_list *const f0412_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0412->then_instructions;

                        body.emit(assign(r0407, r03E4, 0x01));

                        body.emit(assign(r0408, r03E3, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0412->else_instructions;

                        body.emit(assign(r0405, bit_or(body.constant(0u), r03E4), 0x01));

                        ir_expression *const r0414 = less(r0406, body.constant(int(64)));
                        ir_expression *const r0415 = lshift(r03E3, r040A);
                        ir_expression *const r0416 = equal(r0406, body.constant(int(64)));
                        ir_expression *const r0417 = nequal(r03E3, body.constant(0u));
                        ir_expression *const r0418 = expr(ir_unop_b2i, r0417);
                        ir_expression *const r0419 = expr(ir_unop_i2u, r0418);
                        ir_expression *const r041A = expr(ir_triop_csel, r0416, r03E3, r0419);
                        body.emit(assign(r0407, expr(ir_triop_csel, r0414, r0415, r041A), 0x01));

                        ir_expression *const r041B = less(r0406, body.constant(int(64)));
                        ir_expression *const r041C = bit_and(r0406, body.constant(int(31)));
                        ir_expression *const r041D = rshift(r03E3, r041C);
                        body.emit(assign(r0408, expr(ir_triop_csel, r041B, r041D, body.constant(0u)), 0x01));


                     body.instructions = f0412_parent_instructions;
                     body.emit(f0412);

                     /* END IF */

                     body.emit(assign(r0409, body.constant(0u), 0x01));


                  body.instructions = f040E_parent_instructions;
                  body.emit(f040E);

                  /* END IF */

                  ir_expression *const r041E = nequal(r0405, body.constant(0u));
                  ir_expression *const r041F = expr(ir_unop_b2i, r041E);
                  ir_expression *const r0420 = expr(ir_unop_i2u, r041F);
                  body.emit(assign(r0407, bit_or(r0407, r0420), 0x01));


               body.instructions = f040C_parent_instructions;
               body.emit(f040C);

               /* END IF */

               body.emit(assign(r03E3, r0409, 0x01));

               body.emit(assign(r03E4, r0408, 0x01));

               body.emit(assign(r03E5, r0407, 0x01));


            body.instructions = f03FD_parent_instructions;
            body.emit(f03FD);

            /* END IF */

            body.emit(assign(r03E2, sub(r03E2, r03E6), 0x01));

            ir_variable *const r0421 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0421, r03E2, 0x01));

            ir_variable *const r0422 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0422, r03E3, 0x01));

            ir_variable *const r0423 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0423, r03E4, 0x01));

            ir_variable *const r0424 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0424, r03E5, 0x01));

            ir_variable *const r0425 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0425, body.constant(true), 0x01));

            ir_variable *const r0426 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0427 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0427);
            ir_expression *const r0428 = expr(ir_unop_u2i, r03E5);
            body.emit(assign(r0427, less(r0428, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r042A = gequal(r03E2, body.constant(int(2045)));
            ir_if *f0429 = new(mem_ctx) ir_if(operand(r042A).val);
            exec_list *const f0429_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0429->then_instructions;

               /* IF CONDITION */
               ir_expression *const r042C = less(body.constant(int(2045)), r03E2);
               ir_expression *const r042D = equal(r03E2, body.constant(int(2045)));
               ir_expression *const r042E = equal(body.constant(2097151u), r03E3);
               ir_expression *const r042F = equal(body.constant(4294967295u), r03E4);
               ir_expression *const r0430 = logic_and(r042E, r042F);
               ir_expression *const r0431 = logic_and(r042D, r0430);
               ir_expression *const r0432 = logic_and(r0431, r0427);
               ir_expression *const r0433 = logic_or(r042C, r0432);
               ir_if *f042B = new(mem_ctx) ir_if(operand(r0433).val);
               exec_list *const f042B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f042B->then_instructions;

                  ir_variable *const r0434 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0434);
                  ir_expression *const r0435 = lshift(r01ED, body.constant(int(31)));
                  body.emit(assign(r0434, add(r0435, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0434, body.constant(0u), 0x01));

                  body.emit(assign(r0426, r0434, 0x03));

                  body.emit(assign(r0425, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f042B->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0437 = less(r03E2, body.constant(int(0)));
                  ir_if *f0436 = new(mem_ctx) ir_if(operand(r0437).val);
                  exec_list *const f0436_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0436->then_instructions;

                     ir_variable *const r0438 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0438, r03E5, 0x01));

                     ir_variable *const r0439 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0439, neg(r03E2), 0x01));

                     ir_variable *const r043A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r043A);
                     ir_variable *const r043B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r043B);
                     ir_variable *const r043C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r043C);
                     ir_variable *const r043D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r043E = neg(r0439);
                     body.emit(assign(r043D, bit_and(r043E, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0440 = equal(r0439, body.constant(int(0)));
                     ir_if *f043F = new(mem_ctx) ir_if(operand(r0440).val);
                     exec_list *const f043F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f043F->then_instructions;

                        body.emit(assign(r043A, r03E5, 0x01));

                        body.emit(assign(r043B, r03E4, 0x01));

                        body.emit(assign(r043C, r03E3, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f043F->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0442 = less(r0439, body.constant(int(32)));
                        ir_if *f0441 = new(mem_ctx) ir_if(operand(r0442).val);
                        exec_list *const f0441_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0441->then_instructions;

                           body.emit(assign(r043A, lshift(r03E4, r043D), 0x01));

                           ir_expression *const r0443 = lshift(r03E3, r043D);
                           ir_expression *const r0444 = rshift(r03E4, r0439);
                           body.emit(assign(r043B, bit_or(r0443, r0444), 0x01));

                           body.emit(assign(r043C, rshift(r03E3, r0439), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0441->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0446 = equal(r0439, body.constant(int(32)));
                           ir_if *f0445 = new(mem_ctx) ir_if(operand(r0446).val);
                           exec_list *const f0445_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0445->then_instructions;

                              body.emit(assign(r043A, r03E4, 0x01));

                              body.emit(assign(r043B, r03E3, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0445->else_instructions;

                              body.emit(assign(r0438, bit_or(r03E5, r03E4), 0x01));

                              ir_expression *const r0447 = less(r0439, body.constant(int(64)));
                              ir_expression *const r0448 = lshift(r03E3, r043D);
                              ir_expression *const r0449 = equal(r0439, body.constant(int(64)));
                              ir_expression *const r044A = nequal(r03E3, body.constant(0u));
                              ir_expression *const r044B = expr(ir_unop_b2i, r044A);
                              ir_expression *const r044C = expr(ir_unop_i2u, r044B);
                              ir_expression *const r044D = expr(ir_triop_csel, r0449, r03E3, r044C);
                              body.emit(assign(r043A, expr(ir_triop_csel, r0447, r0448, r044D), 0x01));

                              ir_expression *const r044E = less(r0439, body.constant(int(64)));
                              ir_expression *const r044F = bit_and(r0439, body.constant(int(31)));
                              ir_expression *const r0450 = rshift(r03E3, r044F);
                              body.emit(assign(r043B, expr(ir_triop_csel, r044E, r0450, body.constant(0u)), 0x01));


                           body.instructions = f0445_parent_instructions;
                           body.emit(f0445);

                           /* END IF */

                           body.emit(assign(r043C, body.constant(0u), 0x01));


                        body.instructions = f0441_parent_instructions;
                        body.emit(f0441);

                        /* END IF */

                        ir_expression *const r0451 = nequal(r0438, body.constant(0u));
                        ir_expression *const r0452 = expr(ir_unop_b2i, r0451);
                        ir_expression *const r0453 = expr(ir_unop_i2u, r0452);
                        body.emit(assign(r043A, bit_or(r043A, r0453), 0x01));


                     body.instructions = f043F_parent_instructions;
                     body.emit(f043F);

                     /* END IF */

                     body.emit(assign(r0422, r043C, 0x01));

                     body.emit(assign(r0423, r043B, 0x01));

                     body.emit(assign(r0424, r043A, 0x01));

                     body.emit(assign(r0421, body.constant(int(0)), 0x01));

                     body.emit(assign(r0427, less(r043A, body.constant(0u)), 0x01));


                  body.instructions = f0436_parent_instructions;
                  body.emit(f0436);

                  /* END IF */


               body.instructions = f042B_parent_instructions;
               body.emit(f042B);

               /* END IF */


            body.instructions = f0429_parent_instructions;
            body.emit(f0429);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0454 = new(mem_ctx) ir_if(operand(r0425).val);
            exec_list *const f0454_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0454->then_instructions;

               /* IF CONDITION */
               ir_if *f0455 = new(mem_ctx) ir_if(operand(r0427).val);
               exec_list *const f0455_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0455->then_instructions;

                  ir_variable *const r0456 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0456, add(r0423, body.constant(1u)), 0x01));

                  ir_expression *const r0457 = less(r0456, r0423);
                  ir_expression *const r0458 = expr(ir_unop_b2i, r0457);
                  ir_expression *const r0459 = expr(ir_unop_i2u, r0458);
                  body.emit(assign(r0422, add(r0422, r0459), 0x01));

                  ir_expression *const r045A = equal(r0424, body.constant(0u));
                  ir_expression *const r045B = expr(ir_unop_b2i, r045A);
                  ir_expression *const r045C = expr(ir_unop_i2u, r045B);
                  ir_expression *const r045D = add(r0424, r045C);
                  ir_expression *const r045E = bit_and(r045D, body.constant(1u));
                  ir_expression *const r045F = expr(ir_unop_bit_not, r045E);
                  body.emit(assign(r0423, bit_and(r0456, r045F), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0455->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0461 = bit_or(r0422, r0423);
                  ir_expression *const r0462 = equal(r0461, body.constant(0u));
                  ir_if *f0460 = new(mem_ctx) ir_if(operand(r0462).val);
                  exec_list *const f0460_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0460->then_instructions;

                     body.emit(assign(r0421, body.constant(int(0)), 0x01));


                  body.instructions = f0460_parent_instructions;
                  body.emit(f0460);

                  /* END IF */


               body.instructions = f0455_parent_instructions;
               body.emit(f0455);

               /* END IF */

               ir_variable *const r0463 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0463);
               ir_expression *const r0464 = lshift(r01ED, body.constant(int(31)));
               ir_expression *const r0465 = expr(ir_unop_i2u, r0421);
               ir_expression *const r0466 = lshift(r0465, body.constant(int(20)));
               ir_expression *const r0467 = add(r0464, r0466);
               body.emit(assign(r0463, add(r0467, r0422), 0x02));

               body.emit(assign(r0463, r0423, 0x01));

               body.emit(assign(r0426, r0463, 0x03));

               body.emit(assign(r0425, body.constant(false), 0x01));


            body.instructions = f0454_parent_instructions;
            body.emit(f0454);

            /* END IF */

            body.emit(assign(r01EB, r0426, 0x03));

            body.emit(assign(r01EA, body.constant(false), 0x01));


         body.instructions = f039E_parent_instructions;
         body.emit(f039E);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f039C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0469 = less(r0384, body.constant(int(0)));
         ir_if *f0468 = new(mem_ctx) ir_if(operand(r0469).val);
         exec_list *const f0468_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0468->then_instructions;

            /* IF CONDITION */
            ir_expression *const r046B = equal(r038F, body.constant(int(2047)));
            ir_if *f046A = new(mem_ctx) ir_if(operand(r046B).val);
            exec_list *const f046A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f046A->then_instructions;

               /* IF CONDITION */
               ir_expression *const r046D = bit_or(r0387, r0388);
               ir_expression *const r046E = nequal(r046D, body.constant(0u));
               ir_if *f046C = new(mem_ctx) ir_if(operand(r046E).val);
               exec_list *const f046C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f046C->then_instructions;

                  ir_variable *const r046F = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r046F, swizzle_x(r01E8), 0x01));

                  ir_variable *const r0470 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0470, swizzle_x(r01E9), 0x01));

                  body.emit(assign(r046F, bit_or(swizzle_y(r01E8), body.constant(524288u)), 0x02));

                  body.emit(assign(r0470, bit_or(swizzle_y(r01E9), body.constant(524288u)), 0x02));

                  ir_expression *const r0471 = lshift(swizzle_y(r01E8), body.constant(int(1)));
                  ir_expression *const r0472 = gequal(r0471, body.constant(4292870144u));
                  ir_expression *const r0473 = nequal(swizzle_x(r01E8), body.constant(0u));
                  ir_expression *const r0474 = bit_and(swizzle_y(r01E8), body.constant(1048575u));
                  ir_expression *const r0475 = nequal(r0474, body.constant(0u));
                  ir_expression *const r0476 = logic_or(r0473, r0475);
                  ir_expression *const r0477 = logic_and(r0472, r0476);
                  ir_swizzle *const r0478 = swizzle(r0477, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0479 = lshift(swizzle_y(r01E9), body.constant(int(1)));
                  ir_expression *const r047A = gequal(r0479, body.constant(4292870144u));
                  ir_expression *const r047B = nequal(swizzle_x(r01E9), body.constant(0u));
                  ir_expression *const r047C = bit_and(swizzle_y(r01E9), body.constant(1048575u));
                  ir_expression *const r047D = nequal(r047C, body.constant(0u));
                  ir_expression *const r047E = logic_or(r047B, r047D);
                  ir_expression *const r047F = logic_and(r047A, r047E);
                  ir_swizzle *const r0480 = swizzle(r047F, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0481 = expr(ir_triop_csel, r0480, r0470, r046F);
                  body.emit(assign(r01EB, expr(ir_triop_csel, r0478, r0481, r0470), 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f046C->else_instructions;

                  ir_variable *const r0482 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0482);
                  ir_expression *const r0483 = bit_xor(r01ED, body.constant(1u));
                  ir_expression *const r0484 = lshift(r0483, body.constant(int(31)));
                  body.emit(assign(r0482, add(r0484, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0482, body.constant(0u), 0x01));

                  body.emit(assign(r01EB, r0482, 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


               body.instructions = f046C_parent_instructions;
               body.emit(f046C);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f046A->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0486 = equal(r038C, body.constant(int(0)));
               ir_if *f0485 = new(mem_ctx) ir_if(operand(r0486).val);
               exec_list *const f0485_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0485->then_instructions;

                  body.emit(assign(r0384, add(r0384, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0485->else_instructions;

                  body.emit(assign(r0389, bit_or(r0389, body.constant(1073741824u)), 0x01));


               body.instructions = f0485_parent_instructions;
               body.emit(f0485);

               /* END IF */

               ir_variable *const r0487 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0487, neg(r0384), 0x01));

               ir_variable *const r0488 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0488);
               ir_variable *const r0489 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r048A = neg(r0487);
               body.emit(assign(r0489, bit_and(r048A, body.constant(int(31))), 0x01));

               ir_variable *const r048B = body.make_temp(glsl_type::uint_type, "mix_retval");
               ir_expression *const r048C = less(r0487, body.constant(int(32)));
               ir_expression *const r048D = rshift(r0389, r0487);
               ir_expression *const r048E = equal(r0487, body.constant(int(0)));
               ir_expression *const r048F = expr(ir_triop_csel, r048E, r0389, body.constant(0u));
               body.emit(assign(r048B, expr(ir_triop_csel, r048C, r048D, r048F), 0x01));

               /* IF CONDITION */
               ir_expression *const r0491 = equal(r0487, body.constant(int(0)));
               ir_if *f0490 = new(mem_ctx) ir_if(operand(r0491).val);
               exec_list *const f0490_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0490->then_instructions;

                  body.emit(assign(r0488, r0393, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0490->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0493 = less(r0487, body.constant(int(32)));
                  ir_if *f0492 = new(mem_ctx) ir_if(operand(r0493).val);
                  exec_list *const f0492_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0492->then_instructions;

                     ir_expression *const r0494 = lshift(r0389, r0489);
                     ir_expression *const r0495 = rshift(r0393, r0487);
                     ir_expression *const r0496 = bit_or(r0494, r0495);
                     ir_expression *const r0497 = lshift(r0393, r0489);
                     ir_expression *const r0498 = nequal(r0497, body.constant(0u));
                     ir_expression *const r0499 = expr(ir_unop_b2i, r0498);
                     ir_expression *const r049A = expr(ir_unop_i2u, r0499);
                     body.emit(assign(r0488, bit_or(r0496, r049A), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0492->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r049C = equal(r0487, body.constant(int(32)));
                     ir_if *f049B = new(mem_ctx) ir_if(operand(r049C).val);
                     exec_list *const f049B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f049B->then_instructions;

                        ir_expression *const r049D = nequal(r0393, body.constant(0u));
                        ir_expression *const r049E = expr(ir_unop_b2i, r049D);
                        ir_expression *const r049F = expr(ir_unop_i2u, r049E);
                        body.emit(assign(r0488, bit_or(r0389, r049F), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f049B->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04A1 = less(r0487, body.constant(int(64)));
                        ir_if *f04A0 = new(mem_ctx) ir_if(operand(r04A1).val);
                        exec_list *const f04A0_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04A0->then_instructions;

                           ir_expression *const r04A2 = bit_and(r0487, body.constant(int(31)));
                           ir_expression *const r04A3 = rshift(r0389, r04A2);
                           ir_expression *const r04A4 = lshift(r0389, r0489);
                           ir_expression *const r04A5 = bit_or(r04A4, r0393);
                           ir_expression *const r04A6 = nequal(r04A5, body.constant(0u));
                           ir_expression *const r04A7 = expr(ir_unop_b2i, r04A6);
                           ir_expression *const r04A8 = expr(ir_unop_i2u, r04A7);
                           body.emit(assign(r0488, bit_or(r04A3, r04A8), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04A0->else_instructions;

                           ir_expression *const r04A9 = bit_or(r0389, r0393);
                           ir_expression *const r04AA = nequal(r04A9, body.constant(0u));
                           ir_expression *const r04AB = expr(ir_unop_b2i, r04AA);
                           body.emit(assign(r0488, expr(ir_unop_i2u, r04AB), 0x01));


                        body.instructions = f04A0_parent_instructions;
                        body.emit(f04A0);

                        /* END IF */


                     body.instructions = f049B_parent_instructions;
                     body.emit(f049B);

                     /* END IF */


                  body.instructions = f0492_parent_instructions;
                  body.emit(f0492);

                  /* END IF */


               body.instructions = f0490_parent_instructions;
               body.emit(f0490);

               /* END IF */

               body.emit(assign(r0389, r048B, 0x01));

               body.emit(assign(r038A, r0488, 0x01));

               body.emit(assign(r0387, bit_or(r0387, body.constant(1073741824u)), 0x01));

               ir_variable *const r04AC = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r04AD = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r04AD, sub(r0388, r0488), 0x01));

               ir_expression *const r04AE = sub(r0387, r048B);
               ir_expression *const r04AF = less(r0388, r0488);
               ir_expression *const r04B0 = expr(ir_unop_b2i, r04AF);
               ir_expression *const r04B1 = expr(ir_unop_i2u, r04B0);
               body.emit(assign(r04AC, sub(r04AE, r04B1), 0x01));

               body.emit(assign(r01EC, bit_xor(r01ED, body.constant(1u)), 0x01));

               body.emit(assign(r038B, add(r038F, body.constant(int(-1))), 0x01));

               ir_variable *const r04B2 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04B2, add(r038B, body.constant(int(-10))), 0x01));

               ir_variable *const r04B3 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04B3, r04AC, 0x01));

               ir_variable *const r04B4 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04B4, r04AD, 0x01));

               ir_variable *const r04B5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r04B5);
               ir_variable *const r04B6 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04B6);
               /* IF CONDITION */
               ir_expression *const r04B8 = equal(r04AC, body.constant(0u));
               ir_if *f04B7 = new(mem_ctx) ir_if(operand(r04B8).val);
               exec_list *const f04B7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04B7->then_instructions;

                  body.emit(assign(r04B3, r04AD, 0x01));

                  body.emit(assign(r04B4, body.constant(0u), 0x01));

                  body.emit(assign(r04B2, add(r04B2, body.constant(int(-32))), 0x01));


               body.instructions = f04B7_parent_instructions;
               body.emit(f04B7);

               /* END IF */

               ir_variable *const r04B9 = body.make_temp(glsl_type::uint_type, "a");
               body.emit(assign(r04B9, r04B3, 0x01));

               ir_variable *const r04BA = body.make_temp(glsl_type::int_type, "return_value");
               ir_variable *const r04BB = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04BB);
               /* IF CONDITION */
               ir_expression *const r04BD = equal(r04B3, body.constant(0u));
               ir_if *f04BC = new(mem_ctx) ir_if(operand(r04BD).val);
               exec_list *const f04BC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04BC->then_instructions;

                  body.emit(assign(r04BA, body.constant(int(32)), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04BC->else_instructions;

                  body.emit(assign(r04BB, body.constant(int(0)), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04BF = bit_and(r04B3, body.constant(4294901760u));
                  ir_expression *const r04C0 = equal(r04BF, body.constant(0u));
                  ir_if *f04BE = new(mem_ctx) ir_if(operand(r04C0).val);
                  exec_list *const f04BE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04BE->then_instructions;

                     body.emit(assign(r04BB, body.constant(int(16)), 0x01));

                     body.emit(assign(r04B9, lshift(r04B3, body.constant(int(16))), 0x01));


                  body.instructions = f04BE_parent_instructions;
                  body.emit(f04BE);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04C2 = bit_and(r04B9, body.constant(4278190080u));
                  ir_expression *const r04C3 = equal(r04C2, body.constant(0u));
                  ir_if *f04C1 = new(mem_ctx) ir_if(operand(r04C3).val);
                  exec_list *const f04C1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C1->then_instructions;

                     body.emit(assign(r04BB, add(r04BB, body.constant(int(8))), 0x01));

                     body.emit(assign(r04B9, lshift(r04B9, body.constant(int(8))), 0x01));


                  body.instructions = f04C1_parent_instructions;
                  body.emit(f04C1);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04C5 = bit_and(r04B9, body.constant(4026531840u));
                  ir_expression *const r04C6 = equal(r04C5, body.constant(0u));
                  ir_if *f04C4 = new(mem_ctx) ir_if(operand(r04C6).val);
                  exec_list *const f04C4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C4->then_instructions;

                     body.emit(assign(r04BB, add(r04BB, body.constant(int(4))), 0x01));

                     body.emit(assign(r04B9, lshift(r04B9, body.constant(int(4))), 0x01));


                  body.instructions = f04C4_parent_instructions;
                  body.emit(f04C4);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04C8 = bit_and(r04B9, body.constant(3221225472u));
                  ir_expression *const r04C9 = equal(r04C8, body.constant(0u));
                  ir_if *f04C7 = new(mem_ctx) ir_if(operand(r04C9).val);
                  exec_list *const f04C7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C7->then_instructions;

                     body.emit(assign(r04BB, add(r04BB, body.constant(int(2))), 0x01));

                     body.emit(assign(r04B9, lshift(r04B9, body.constant(int(2))), 0x01));


                  body.instructions = f04C7_parent_instructions;
                  body.emit(f04C7);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04CB = bit_and(r04B9, body.constant(2147483648u));
                  ir_expression *const r04CC = equal(r04CB, body.constant(0u));
                  ir_if *f04CA = new(mem_ctx) ir_if(operand(r04CC).val);
                  exec_list *const f04CA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04CA->then_instructions;

                     body.emit(assign(r04BB, add(r04BB, body.constant(int(1))), 0x01));


                  body.instructions = f04CA_parent_instructions;
                  body.emit(f04CA);

                  /* END IF */

                  body.emit(assign(r04BA, r04BB, 0x01));


               body.instructions = f04BC_parent_instructions;
               body.emit(f04BC);

               /* END IF */

               body.emit(assign(r04B6, add(r04BA, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04CE = gequal(r04B6, body.constant(int(0)));
               ir_if *f04CD = new(mem_ctx) ir_if(operand(r04CE).val);
               exec_list *const f04CD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04CD->then_instructions;

                  body.emit(assign(r04B5, body.constant(0u), 0x01));

                  ir_expression *const r04CF = equal(r04B6, body.constant(int(0)));
                  ir_expression *const r04D0 = lshift(r04B3, r04B6);
                  ir_expression *const r04D1 = neg(r04B6);
                  ir_expression *const r04D2 = bit_and(r04D1, body.constant(int(31)));
                  ir_expression *const r04D3 = rshift(r04B4, r04D2);
                  ir_expression *const r04D4 = bit_or(r04D0, r04D3);
                  body.emit(assign(r04B3, expr(ir_triop_csel, r04CF, r04B3, r04D4), 0x01));

                  body.emit(assign(r04B4, lshift(r04B4, r04B6), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04CD->else_instructions;

                  ir_variable *const r04D5 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r04D5, body.constant(0u), 0x01));

                  ir_variable *const r04D6 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r04D6, neg(r04B6), 0x01));

                  ir_variable *const r04D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04D7);
                  ir_variable *const r04D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r04D8);
                  ir_variable *const r04D9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04D9);
                  ir_variable *const r04DA = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04DB = neg(r04D6);
                  body.emit(assign(r04DA, bit_and(r04DB, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04DD = equal(r04D6, body.constant(int(0)));
                  ir_if *f04DC = new(mem_ctx) ir_if(operand(r04DD).val);
                  exec_list *const f04DC_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04DC->then_instructions;

                     body.emit(assign(r04D7, r04D5, 0x01));

                     body.emit(assign(r04D8, r04B4, 0x01));

                     body.emit(assign(r04D9, r04B3, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04DC->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04DF = less(r04D6, body.constant(int(32)));
                     ir_if *f04DE = new(mem_ctx) ir_if(operand(r04DF).val);
                     exec_list *const f04DE_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04DE->then_instructions;

                        body.emit(assign(r04D7, lshift(r04B4, r04DA), 0x01));

                        ir_expression *const r04E0 = lshift(r04B3, r04DA);
                        ir_expression *const r04E1 = rshift(r04B4, r04D6);
                        body.emit(assign(r04D8, bit_or(r04E0, r04E1), 0x01));

                        body.emit(assign(r04D9, rshift(r04B3, r04D6), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04DE->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04E3 = equal(r04D6, body.constant(int(32)));
                        ir_if *f04E2 = new(mem_ctx) ir_if(operand(r04E3).val);
                        exec_list *const f04E2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04E2->then_instructions;

                           body.emit(assign(r04D7, r04B4, 0x01));

                           body.emit(assign(r04D8, r04B3, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04E2->else_instructions;

                           body.emit(assign(r04D5, bit_or(body.constant(0u), r04B4), 0x01));

                           ir_expression *const r04E4 = less(r04D6, body.constant(int(64)));
                           ir_expression *const r04E5 = lshift(r04B3, r04DA);
                           ir_expression *const r04E6 = equal(r04D6, body.constant(int(64)));
                           ir_expression *const r04E7 = nequal(r04B3, body.constant(0u));
                           ir_expression *const r04E8 = expr(ir_unop_b2i, r04E7);
                           ir_expression *const r04E9 = expr(ir_unop_i2u, r04E8);
                           ir_expression *const r04EA = expr(ir_triop_csel, r04E6, r04B3, r04E9);
                           body.emit(assign(r04D7, expr(ir_triop_csel, r04E4, r04E5, r04EA), 0x01));

                           ir_expression *const r04EB = less(r04D6, body.constant(int(64)));
                           ir_expression *const r04EC = bit_and(r04D6, body.constant(int(31)));
                           ir_expression *const r04ED = rshift(r04B3, r04EC);
                           body.emit(assign(r04D8, expr(ir_triop_csel, r04EB, r04ED, body.constant(0u)), 0x01));


                        body.instructions = f04E2_parent_instructions;
                        body.emit(f04E2);

                        /* END IF */

                        body.emit(assign(r04D9, body.constant(0u), 0x01));


                     body.instructions = f04DE_parent_instructions;
                     body.emit(f04DE);

                     /* END IF */

                     ir_expression *const r04EE = nequal(r04D5, body.constant(0u));
                     ir_expression *const r04EF = expr(ir_unop_b2i, r04EE);
                     ir_expression *const r04F0 = expr(ir_unop_i2u, r04EF);
                     body.emit(assign(r04D7, bit_or(r04D7, r04F0), 0x01));


                  body.instructions = f04DC_parent_instructions;
                  body.emit(f04DC);

                  /* END IF */

                  body.emit(assign(r04B3, r04D9, 0x01));

                  body.emit(assign(r04B4, r04D8, 0x01));

                  body.emit(assign(r04B5, r04D7, 0x01));


               body.instructions = f04CD_parent_instructions;
               body.emit(f04CD);

               /* END IF */

               body.emit(assign(r04B2, sub(r04B2, r04B6), 0x01));

               ir_variable *const r04F1 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04F1, r04B2, 0x01));

               ir_variable *const r04F2 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04F2, r04B3, 0x01));

               ir_variable *const r04F3 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04F3, r04B4, 0x01));

               ir_variable *const r04F4 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r04F4, r04B5, 0x01));

               ir_variable *const r04F5 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r04F5, body.constant(true), 0x01));

               ir_variable *const r04F6 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04F7 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r04F7);
               ir_expression *const r04F8 = expr(ir_unop_u2i, r04B5);
               body.emit(assign(r04F7, less(r04F8, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04FA = gequal(r04B2, body.constant(int(2045)));
               ir_if *f04F9 = new(mem_ctx) ir_if(operand(r04FA).val);
               exec_list *const f04F9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04F9->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04FC = less(body.constant(int(2045)), r04B2);
                  ir_expression *const r04FD = equal(r04B2, body.constant(int(2045)));
                  ir_expression *const r04FE = equal(body.constant(2097151u), r04B3);
                  ir_expression *const r04FF = equal(body.constant(4294967295u), r04B4);
                  ir_expression *const r0500 = logic_and(r04FE, r04FF);
                  ir_expression *const r0501 = logic_and(r04FD, r0500);
                  ir_expression *const r0502 = logic_and(r0501, r04F7);
                  ir_expression *const r0503 = logic_or(r04FC, r0502);
                  ir_if *f04FB = new(mem_ctx) ir_if(operand(r0503).val);
                  exec_list *const f04FB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04FB->then_instructions;

                     ir_variable *const r0504 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0504);
                     ir_expression *const r0505 = lshift(r01EC, body.constant(int(31)));
                     body.emit(assign(r0504, add(r0505, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r0504, body.constant(0u), 0x01));

                     body.emit(assign(r04F6, r0504, 0x03));

                     body.emit(assign(r04F5, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04FB->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0507 = less(r04B2, body.constant(int(0)));
                     ir_if *f0506 = new(mem_ctx) ir_if(operand(r0507).val);
                     exec_list *const f0506_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0506->then_instructions;

                        ir_variable *const r0508 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0508, r04B5, 0x01));

                        ir_variable *const r0509 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0509, neg(r04B2), 0x01));

                        ir_variable *const r050A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r050A);
                        ir_variable *const r050B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r050B);
                        ir_variable *const r050C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r050C);
                        ir_variable *const r050D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r050E = neg(r0509);
                        body.emit(assign(r050D, bit_and(r050E, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0510 = equal(r0509, body.constant(int(0)));
                        ir_if *f050F = new(mem_ctx) ir_if(operand(r0510).val);
                        exec_list *const f050F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f050F->then_instructions;

                           body.emit(assign(r050A, r04B5, 0x01));

                           body.emit(assign(r050B, r04B4, 0x01));

                           body.emit(assign(r050C, r04B3, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f050F->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0512 = less(r0509, body.constant(int(32)));
                           ir_if *f0511 = new(mem_ctx) ir_if(operand(r0512).val);
                           exec_list *const f0511_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0511->then_instructions;

                              body.emit(assign(r050A, lshift(r04B4, r050D), 0x01));

                              ir_expression *const r0513 = lshift(r04B3, r050D);
                              ir_expression *const r0514 = rshift(r04B4, r0509);
                              body.emit(assign(r050B, bit_or(r0513, r0514), 0x01));

                              body.emit(assign(r050C, rshift(r04B3, r0509), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0511->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0516 = equal(r0509, body.constant(int(32)));
                              ir_if *f0515 = new(mem_ctx) ir_if(operand(r0516).val);
                              exec_list *const f0515_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0515->then_instructions;

                                 body.emit(assign(r050A, r04B4, 0x01));

                                 body.emit(assign(r050B, r04B3, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0515->else_instructions;

                                 body.emit(assign(r0508, bit_or(r04B5, r04B4), 0x01));

                                 ir_expression *const r0517 = less(r0509, body.constant(int(64)));
                                 ir_expression *const r0518 = lshift(r04B3, r050D);
                                 ir_expression *const r0519 = equal(r0509, body.constant(int(64)));
                                 ir_expression *const r051A = nequal(r04B3, body.constant(0u));
                                 ir_expression *const r051B = expr(ir_unop_b2i, r051A);
                                 ir_expression *const r051C = expr(ir_unop_i2u, r051B);
                                 ir_expression *const r051D = expr(ir_triop_csel, r0519, r04B3, r051C);
                                 body.emit(assign(r050A, expr(ir_triop_csel, r0517, r0518, r051D), 0x01));

                                 ir_expression *const r051E = less(r0509, body.constant(int(64)));
                                 ir_expression *const r051F = bit_and(r0509, body.constant(int(31)));
                                 ir_expression *const r0520 = rshift(r04B3, r051F);
                                 body.emit(assign(r050B, expr(ir_triop_csel, r051E, r0520, body.constant(0u)), 0x01));


                              body.instructions = f0515_parent_instructions;
                              body.emit(f0515);

                              /* END IF */

                              body.emit(assign(r050C, body.constant(0u), 0x01));


                           body.instructions = f0511_parent_instructions;
                           body.emit(f0511);

                           /* END IF */

                           ir_expression *const r0521 = nequal(r0508, body.constant(0u));
                           ir_expression *const r0522 = expr(ir_unop_b2i, r0521);
                           ir_expression *const r0523 = expr(ir_unop_i2u, r0522);
                           body.emit(assign(r050A, bit_or(r050A, r0523), 0x01));


                        body.instructions = f050F_parent_instructions;
                        body.emit(f050F);

                        /* END IF */

                        body.emit(assign(r04F2, r050C, 0x01));

                        body.emit(assign(r04F3, r050B, 0x01));

                        body.emit(assign(r04F4, r050A, 0x01));

                        body.emit(assign(r04F1, body.constant(int(0)), 0x01));

                        body.emit(assign(r04F7, less(r050A, body.constant(0u)), 0x01));


                     body.instructions = f0506_parent_instructions;
                     body.emit(f0506);

                     /* END IF */


                  body.instructions = f04FB_parent_instructions;
                  body.emit(f04FB);

                  /* END IF */


               body.instructions = f04F9_parent_instructions;
               body.emit(f04F9);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0524 = new(mem_ctx) ir_if(operand(r04F5).val);
               exec_list *const f0524_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0524->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0525 = new(mem_ctx) ir_if(operand(r04F7).val);
                  exec_list *const f0525_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0525->then_instructions;

                     ir_variable *const r0526 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0526, add(r04F3, body.constant(1u)), 0x01));

                     ir_expression *const r0527 = less(r0526, r04F3);
                     ir_expression *const r0528 = expr(ir_unop_b2i, r0527);
                     ir_expression *const r0529 = expr(ir_unop_i2u, r0528);
                     body.emit(assign(r04F2, add(r04F2, r0529), 0x01));

                     ir_expression *const r052A = equal(r04F4, body.constant(0u));
                     ir_expression *const r052B = expr(ir_unop_b2i, r052A);
                     ir_expression *const r052C = expr(ir_unop_i2u, r052B);
                     ir_expression *const r052D = add(r04F4, r052C);
                     ir_expression *const r052E = bit_and(r052D, body.constant(1u));
                     ir_expression *const r052F = expr(ir_unop_bit_not, r052E);
                     body.emit(assign(r04F3, bit_and(r0526, r052F), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0525->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0531 = bit_or(r04F2, r04F3);
                     ir_expression *const r0532 = equal(r0531, body.constant(0u));
                     ir_if *f0530 = new(mem_ctx) ir_if(operand(r0532).val);
                     exec_list *const f0530_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0530->then_instructions;

                        body.emit(assign(r04F1, body.constant(int(0)), 0x01));


                     body.instructions = f0530_parent_instructions;
                     body.emit(f0530);

                     /* END IF */


                  body.instructions = f0525_parent_instructions;
                  body.emit(f0525);

                  /* END IF */

                  ir_variable *const r0533 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0533);
                  ir_expression *const r0534 = lshift(r01EC, body.constant(int(31)));
                  ir_expression *const r0535 = expr(ir_unop_i2u, r04F1);
                  ir_expression *const r0536 = lshift(r0535, body.constant(int(20)));
                  ir_expression *const r0537 = add(r0534, r0536);
                  body.emit(assign(r0533, add(r0537, r04F2), 0x02));

                  body.emit(assign(r0533, r04F3, 0x01));

                  body.emit(assign(r04F6, r0533, 0x03));

                  body.emit(assign(r04F5, body.constant(false), 0x01));


               body.instructions = f0524_parent_instructions;
               body.emit(f0524);

               /* END IF */

               body.emit(assign(r01EB, r04F6, 0x03));

               body.emit(assign(r01EA, body.constant(false), 0x01));


            body.instructions = f046A_parent_instructions;
            body.emit(f046A);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0468->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0539 = equal(r038C, body.constant(int(2047)));
            ir_if *f0538 = new(mem_ctx) ir_if(operand(r0539).val);
            exec_list *const f0538_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0538->then_instructions;

               /* IF CONDITION */
               ir_expression *const r053B = bit_or(r0389, r038A);
               ir_expression *const r053C = bit_or(r0387, r0388);
               ir_expression *const r053D = bit_or(r053B, r053C);
               ir_expression *const r053E = nequal(r053D, body.constant(0u));
               ir_if *f053A = new(mem_ctx) ir_if(operand(r053E).val);
               exec_list *const f053A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f053A->then_instructions;

                  ir_variable *const r053F = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r053F, swizzle_x(r01E8), 0x01));

                  ir_variable *const r0540 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0540, swizzle_x(r01E9), 0x01));

                  body.emit(assign(r053F, bit_or(swizzle_y(r01E8), body.constant(524288u)), 0x02));

                  body.emit(assign(r0540, bit_or(swizzle_y(r01E9), body.constant(524288u)), 0x02));

                  ir_expression *const r0541 = lshift(swizzle_y(r01E8), body.constant(int(1)));
                  ir_expression *const r0542 = gequal(r0541, body.constant(4292870144u));
                  ir_expression *const r0543 = nequal(swizzle_x(r01E8), body.constant(0u));
                  ir_expression *const r0544 = bit_and(swizzle_y(r01E8), body.constant(1048575u));
                  ir_expression *const r0545 = nequal(r0544, body.constant(0u));
                  ir_expression *const r0546 = logic_or(r0543, r0545);
                  ir_expression *const r0547 = logic_and(r0542, r0546);
                  ir_swizzle *const r0548 = swizzle(r0547, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0549 = lshift(swizzle_y(r01E9), body.constant(int(1)));
                  ir_expression *const r054A = gequal(r0549, body.constant(4292870144u));
                  ir_expression *const r054B = nequal(swizzle_x(r01E9), body.constant(0u));
                  ir_expression *const r054C = bit_and(swizzle_y(r01E9), body.constant(1048575u));
                  ir_expression *const r054D = nequal(r054C, body.constant(0u));
                  ir_expression *const r054E = logic_or(r054B, r054D);
                  ir_expression *const r054F = logic_and(r054A, r054E);
                  ir_swizzle *const r0550 = swizzle(r054F, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0551 = expr(ir_triop_csel, r0550, r0540, r053F);
                  body.emit(assign(r01EB, expr(ir_triop_csel, r0548, r0551, r0540), 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f053A->else_instructions;

                  ir_constant_data r0552_data;
                  memset(&r0552_data, 0, sizeof(ir_constant_data));
                  r0552_data.u[0] = 4294967295;
                  r0552_data.u[1] = 4294967295;
                  ir_constant *const r0552 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0552_data);
                  body.emit(assign(r01EB, r0552, 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


               body.instructions = f053A_parent_instructions;
               body.emit(f053A);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0538->else_instructions;

               ir_expression *const r0553 = equal(r038C, body.constant(int(0)));
               body.emit(assign(r0385, expr(ir_triop_csel, r0553, body.constant(int(1)), r038F), 0x01));

               ir_expression *const r0554 = equal(r038C, body.constant(int(0)));
               body.emit(assign(r0386, expr(ir_triop_csel, r0554, body.constant(int(1)), r038C), 0x01));

               /* IF CONDITION */
               ir_expression *const r0556 = less(r0387, r0389);
               ir_if *f0555 = new(mem_ctx) ir_if(operand(r0556).val);
               exec_list *const f0555_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0555->then_instructions;

                  ir_variable *const r0557 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_variable *const r0558 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r0558, sub(r038A, r0388), 0x01));

                  ir_expression *const r0559 = sub(r0389, r0387);
                  ir_expression *const r055A = less(r038A, r0388);
                  ir_expression *const r055B = expr(ir_unop_b2i, r055A);
                  ir_expression *const r055C = expr(ir_unop_i2u, r055B);
                  body.emit(assign(r0557, sub(r0559, r055C), 0x01));

                  body.emit(assign(r038B, add(r0386, body.constant(int(-1))), 0x01));

                  ir_variable *const r055D = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r055D, add(r038B, body.constant(int(-10))), 0x01));

                  ir_variable *const r055E = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r055E, r0557, 0x01));

                  ir_variable *const r055F = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r055F, r0558, 0x01));

                  ir_variable *const r0560 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r0560);
                  ir_variable *const r0561 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0561);
                  /* IF CONDITION */
                  ir_expression *const r0563 = equal(r0557, body.constant(0u));
                  ir_if *f0562 = new(mem_ctx) ir_if(operand(r0563).val);
                  exec_list *const f0562_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0562->then_instructions;

                     body.emit(assign(r055E, r0558, 0x01));

                     body.emit(assign(r055F, body.constant(0u), 0x01));

                     body.emit(assign(r055D, add(r055D, body.constant(int(-32))), 0x01));


                  body.instructions = f0562_parent_instructions;
                  body.emit(f0562);

                  /* END IF */

                  ir_variable *const r0564 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r0564, r055E, 0x01));

                  ir_variable *const r0565 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r0566 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0566);
                  /* IF CONDITION */
                  ir_expression *const r0568 = equal(r055E, body.constant(0u));
                  ir_if *f0567 = new(mem_ctx) ir_if(operand(r0568).val);
                  exec_list *const f0567_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0567->then_instructions;

                     body.emit(assign(r0565, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0567->else_instructions;

                     body.emit(assign(r0566, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r056A = bit_and(r055E, body.constant(4294901760u));
                     ir_expression *const r056B = equal(r056A, body.constant(0u));
                     ir_if *f0569 = new(mem_ctx) ir_if(operand(r056B).val);
                     exec_list *const f0569_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0569->then_instructions;

                        body.emit(assign(r0566, body.constant(int(16)), 0x01));

                        body.emit(assign(r0564, lshift(r055E, body.constant(int(16))), 0x01));


                     body.instructions = f0569_parent_instructions;
                     body.emit(f0569);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r056D = bit_and(r0564, body.constant(4278190080u));
                     ir_expression *const r056E = equal(r056D, body.constant(0u));
                     ir_if *f056C = new(mem_ctx) ir_if(operand(r056E).val);
                     exec_list *const f056C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f056C->then_instructions;

                        body.emit(assign(r0566, add(r0566, body.constant(int(8))), 0x01));

                        body.emit(assign(r0564, lshift(r0564, body.constant(int(8))), 0x01));


                     body.instructions = f056C_parent_instructions;
                     body.emit(f056C);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0570 = bit_and(r0564, body.constant(4026531840u));
                     ir_expression *const r0571 = equal(r0570, body.constant(0u));
                     ir_if *f056F = new(mem_ctx) ir_if(operand(r0571).val);
                     exec_list *const f056F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f056F->then_instructions;

                        body.emit(assign(r0566, add(r0566, body.constant(int(4))), 0x01));

                        body.emit(assign(r0564, lshift(r0564, body.constant(int(4))), 0x01));


                     body.instructions = f056F_parent_instructions;
                     body.emit(f056F);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0573 = bit_and(r0564, body.constant(3221225472u));
                     ir_expression *const r0574 = equal(r0573, body.constant(0u));
                     ir_if *f0572 = new(mem_ctx) ir_if(operand(r0574).val);
                     exec_list *const f0572_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0572->then_instructions;

                        body.emit(assign(r0566, add(r0566, body.constant(int(2))), 0x01));

                        body.emit(assign(r0564, lshift(r0564, body.constant(int(2))), 0x01));


                     body.instructions = f0572_parent_instructions;
                     body.emit(f0572);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0576 = bit_and(r0564, body.constant(2147483648u));
                     ir_expression *const r0577 = equal(r0576, body.constant(0u));
                     ir_if *f0575 = new(mem_ctx) ir_if(operand(r0577).val);
                     exec_list *const f0575_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0575->then_instructions;

                        body.emit(assign(r0566, add(r0566, body.constant(int(1))), 0x01));


                     body.instructions = f0575_parent_instructions;
                     body.emit(f0575);

                     /* END IF */

                     body.emit(assign(r0565, r0566, 0x01));


                  body.instructions = f0567_parent_instructions;
                  body.emit(f0567);

                  /* END IF */

                  body.emit(assign(r0561, add(r0565, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0579 = gequal(r0561, body.constant(int(0)));
                  ir_if *f0578 = new(mem_ctx) ir_if(operand(r0579).val);
                  exec_list *const f0578_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0578->then_instructions;

                     body.emit(assign(r0560, body.constant(0u), 0x01));

                     ir_expression *const r057A = equal(r0561, body.constant(int(0)));
                     ir_expression *const r057B = lshift(r055E, r0561);
                     ir_expression *const r057C = neg(r0561);
                     ir_expression *const r057D = bit_and(r057C, body.constant(int(31)));
                     ir_expression *const r057E = rshift(r055F, r057D);
                     ir_expression *const r057F = bit_or(r057B, r057E);
                     body.emit(assign(r055E, expr(ir_triop_csel, r057A, r055E, r057F), 0x01));

                     body.emit(assign(r055F, lshift(r055F, r0561), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0578->else_instructions;

                     ir_variable *const r0580 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0580, body.constant(0u), 0x01));

                     ir_variable *const r0581 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0581, neg(r0561), 0x01));

                     ir_variable *const r0582 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0582);
                     ir_variable *const r0583 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0583);
                     ir_variable *const r0584 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0584);
                     ir_variable *const r0585 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0586 = neg(r0581);
                     body.emit(assign(r0585, bit_and(r0586, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0588 = equal(r0581, body.constant(int(0)));
                     ir_if *f0587 = new(mem_ctx) ir_if(operand(r0588).val);
                     exec_list *const f0587_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0587->then_instructions;

                        body.emit(assign(r0582, r0580, 0x01));

                        body.emit(assign(r0583, r055F, 0x01));

                        body.emit(assign(r0584, r055E, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0587->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r058A = less(r0581, body.constant(int(32)));
                        ir_if *f0589 = new(mem_ctx) ir_if(operand(r058A).val);
                        exec_list *const f0589_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0589->then_instructions;

                           body.emit(assign(r0582, lshift(r055F, r0585), 0x01));

                           ir_expression *const r058B = lshift(r055E, r0585);
                           ir_expression *const r058C = rshift(r055F, r0581);
                           body.emit(assign(r0583, bit_or(r058B, r058C), 0x01));

                           body.emit(assign(r0584, rshift(r055E, r0581), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0589->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r058E = equal(r0581, body.constant(int(32)));
                           ir_if *f058D = new(mem_ctx) ir_if(operand(r058E).val);
                           exec_list *const f058D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f058D->then_instructions;

                              body.emit(assign(r0582, r055F, 0x01));

                              body.emit(assign(r0583, r055E, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f058D->else_instructions;

                              body.emit(assign(r0580, bit_or(body.constant(0u), r055F), 0x01));

                              ir_expression *const r058F = less(r0581, body.constant(int(64)));
                              ir_expression *const r0590 = lshift(r055E, r0585);
                              ir_expression *const r0591 = equal(r0581, body.constant(int(64)));
                              ir_expression *const r0592 = nequal(r055E, body.constant(0u));
                              ir_expression *const r0593 = expr(ir_unop_b2i, r0592);
                              ir_expression *const r0594 = expr(ir_unop_i2u, r0593);
                              ir_expression *const r0595 = expr(ir_triop_csel, r0591, r055E, r0594);
                              body.emit(assign(r0582, expr(ir_triop_csel, r058F, r0590, r0595), 0x01));

                              ir_expression *const r0596 = less(r0581, body.constant(int(64)));
                              ir_expression *const r0597 = bit_and(r0581, body.constant(int(31)));
                              ir_expression *const r0598 = rshift(r055E, r0597);
                              body.emit(assign(r0583, expr(ir_triop_csel, r0596, r0598, body.constant(0u)), 0x01));


                           body.instructions = f058D_parent_instructions;
                           body.emit(f058D);

                           /* END IF */

                           body.emit(assign(r0584, body.constant(0u), 0x01));


                        body.instructions = f0589_parent_instructions;
                        body.emit(f0589);

                        /* END IF */

                        ir_expression *const r0599 = nequal(r0580, body.constant(0u));
                        ir_expression *const r059A = expr(ir_unop_b2i, r0599);
                        ir_expression *const r059B = expr(ir_unop_i2u, r059A);
                        body.emit(assign(r0582, bit_or(r0582, r059B), 0x01));


                     body.instructions = f0587_parent_instructions;
                     body.emit(f0587);

                     /* END IF */

                     body.emit(assign(r055E, r0584, 0x01));

                     body.emit(assign(r055F, r0583, 0x01));

                     body.emit(assign(r0560, r0582, 0x01));


                  body.instructions = f0578_parent_instructions;
                  body.emit(f0578);

                  /* END IF */

                  body.emit(assign(r055D, sub(r055D, r0561), 0x01));

                  ir_variable *const r059C = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r059C, r055D, 0x01));

                  ir_variable *const r059D = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r059D, r055E, 0x01));

                  ir_variable *const r059E = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r059E, r055F, 0x01));

                  ir_variable *const r059F = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r059F, r0560, 0x01));

                  ir_variable *const r05A0 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r05A0, body.constant(true), 0x01));

                  ir_variable *const r05A1 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r05A2 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r05A2);
                  ir_expression *const r05A3 = expr(ir_unop_u2i, r0560);
                  body.emit(assign(r05A2, less(r05A3, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r05A5 = gequal(r055D, body.constant(int(2045)));
                  ir_if *f05A4 = new(mem_ctx) ir_if(operand(r05A5).val);
                  exec_list *const f05A4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05A4->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r05A7 = less(body.constant(int(2045)), r055D);
                     ir_expression *const r05A8 = equal(r055D, body.constant(int(2045)));
                     ir_expression *const r05A9 = equal(body.constant(2097151u), r055E);
                     ir_expression *const r05AA = equal(body.constant(4294967295u), r055F);
                     ir_expression *const r05AB = logic_and(r05A9, r05AA);
                     ir_expression *const r05AC = logic_and(r05A8, r05AB);
                     ir_expression *const r05AD = logic_and(r05AC, r05A2);
                     ir_expression *const r05AE = logic_or(r05A7, r05AD);
                     ir_if *f05A6 = new(mem_ctx) ir_if(operand(r05AE).val);
                     exec_list *const f05A6_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05A6->then_instructions;

                        ir_variable *const r05AF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r05AF);
                        ir_expression *const r05B0 = lshift(r01EC, body.constant(int(31)));
                        body.emit(assign(r05AF, add(r05B0, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r05AF, body.constant(0u), 0x01));

                        body.emit(assign(r05A1, r05AF, 0x03));

                        body.emit(assign(r05A0, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05A6->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05B2 = less(r055D, body.constant(int(0)));
                        ir_if *f05B1 = new(mem_ctx) ir_if(operand(r05B2).val);
                        exec_list *const f05B1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05B1->then_instructions;

                           ir_variable *const r05B3 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r05B3, r0560, 0x01));

                           ir_variable *const r05B4 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r05B4, neg(r055D), 0x01));

                           ir_variable *const r05B5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r05B5);
                           ir_variable *const r05B6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r05B6);
                           ir_variable *const r05B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r05B7);
                           ir_variable *const r05B8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r05B9 = neg(r05B4);
                           body.emit(assign(r05B8, bit_and(r05B9, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r05BB = equal(r05B4, body.constant(int(0)));
                           ir_if *f05BA = new(mem_ctx) ir_if(operand(r05BB).val);
                           exec_list *const f05BA_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05BA->then_instructions;

                              body.emit(assign(r05B5, r0560, 0x01));

                              body.emit(assign(r05B6, r055F, 0x01));

                              body.emit(assign(r05B7, r055E, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05BA->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05BD = less(r05B4, body.constant(int(32)));
                              ir_if *f05BC = new(mem_ctx) ir_if(operand(r05BD).val);
                              exec_list *const f05BC_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05BC->then_instructions;

                                 body.emit(assign(r05B5, lshift(r055F, r05B8), 0x01));

                                 ir_expression *const r05BE = lshift(r055E, r05B8);
                                 ir_expression *const r05BF = rshift(r055F, r05B4);
                                 body.emit(assign(r05B6, bit_or(r05BE, r05BF), 0x01));

                                 body.emit(assign(r05B7, rshift(r055E, r05B4), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05BC->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05C1 = equal(r05B4, body.constant(int(32)));
                                 ir_if *f05C0 = new(mem_ctx) ir_if(operand(r05C1).val);
                                 exec_list *const f05C0_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05C0->then_instructions;

                                    body.emit(assign(r05B5, r055F, 0x01));

                                    body.emit(assign(r05B6, r055E, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05C0->else_instructions;

                                    body.emit(assign(r05B3, bit_or(r0560, r055F), 0x01));

                                    ir_expression *const r05C2 = less(r05B4, body.constant(int(64)));
                                    ir_expression *const r05C3 = lshift(r055E, r05B8);
                                    ir_expression *const r05C4 = equal(r05B4, body.constant(int(64)));
                                    ir_expression *const r05C5 = nequal(r055E, body.constant(0u));
                                    ir_expression *const r05C6 = expr(ir_unop_b2i, r05C5);
                                    ir_expression *const r05C7 = expr(ir_unop_i2u, r05C6);
                                    ir_expression *const r05C8 = expr(ir_triop_csel, r05C4, r055E, r05C7);
                                    body.emit(assign(r05B5, expr(ir_triop_csel, r05C2, r05C3, r05C8), 0x01));

                                    ir_expression *const r05C9 = less(r05B4, body.constant(int(64)));
                                    ir_expression *const r05CA = bit_and(r05B4, body.constant(int(31)));
                                    ir_expression *const r05CB = rshift(r055E, r05CA);
                                    body.emit(assign(r05B6, expr(ir_triop_csel, r05C9, r05CB, body.constant(0u)), 0x01));


                                 body.instructions = f05C0_parent_instructions;
                                 body.emit(f05C0);

                                 /* END IF */

                                 body.emit(assign(r05B7, body.constant(0u), 0x01));


                              body.instructions = f05BC_parent_instructions;
                              body.emit(f05BC);

                              /* END IF */

                              ir_expression *const r05CC = nequal(r05B3, body.constant(0u));
                              ir_expression *const r05CD = expr(ir_unop_b2i, r05CC);
                              ir_expression *const r05CE = expr(ir_unop_i2u, r05CD);
                              body.emit(assign(r05B5, bit_or(r05B5, r05CE), 0x01));


                           body.instructions = f05BA_parent_instructions;
                           body.emit(f05BA);

                           /* END IF */

                           body.emit(assign(r059D, r05B7, 0x01));

                           body.emit(assign(r059E, r05B6, 0x01));

                           body.emit(assign(r059F, r05B5, 0x01));

                           body.emit(assign(r059C, body.constant(int(0)), 0x01));

                           body.emit(assign(r05A2, less(r05B5, body.constant(0u)), 0x01));


                        body.instructions = f05B1_parent_instructions;
                        body.emit(f05B1);

                        /* END IF */


                     body.instructions = f05A6_parent_instructions;
                     body.emit(f05A6);

                     /* END IF */


                  body.instructions = f05A4_parent_instructions;
                  body.emit(f05A4);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f05CF = new(mem_ctx) ir_if(operand(r05A0).val);
                  exec_list *const f05CF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05CF->then_instructions;

                     /* IF CONDITION */
                     ir_if *f05D0 = new(mem_ctx) ir_if(operand(r05A2).val);
                     exec_list *const f05D0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05D0->then_instructions;

                        ir_variable *const r05D1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r05D1, add(r059E, body.constant(1u)), 0x01));

                        ir_expression *const r05D2 = less(r05D1, r059E);
                        ir_expression *const r05D3 = expr(ir_unop_b2i, r05D2);
                        ir_expression *const r05D4 = expr(ir_unop_i2u, r05D3);
                        body.emit(assign(r059D, add(r059D, r05D4), 0x01));

                        ir_expression *const r05D5 = equal(r059F, body.constant(0u));
                        ir_expression *const r05D6 = expr(ir_unop_b2i, r05D5);
                        ir_expression *const r05D7 = expr(ir_unop_i2u, r05D6);
                        ir_expression *const r05D8 = add(r059F, r05D7);
                        ir_expression *const r05D9 = bit_and(r05D8, body.constant(1u));
                        ir_expression *const r05DA = expr(ir_unop_bit_not, r05D9);
                        body.emit(assign(r059E, bit_and(r05D1, r05DA), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05D0->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05DC = bit_or(r059D, r059E);
                        ir_expression *const r05DD = equal(r05DC, body.constant(0u));
                        ir_if *f05DB = new(mem_ctx) ir_if(operand(r05DD).val);
                        exec_list *const f05DB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05DB->then_instructions;

                           body.emit(assign(r059C, body.constant(int(0)), 0x01));


                        body.instructions = f05DB_parent_instructions;
                        body.emit(f05DB);

                        /* END IF */


                     body.instructions = f05D0_parent_instructions;
                     body.emit(f05D0);

                     /* END IF */

                     ir_variable *const r05DE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r05DE);
                     ir_expression *const r05DF = lshift(r01EC, body.constant(int(31)));
                     ir_expression *const r05E0 = expr(ir_unop_i2u, r059C);
                     ir_expression *const r05E1 = lshift(r05E0, body.constant(int(20)));
                     ir_expression *const r05E2 = add(r05DF, r05E1);
                     body.emit(assign(r05DE, add(r05E2, r059D), 0x02));

                     body.emit(assign(r05DE, r059E, 0x01));

                     body.emit(assign(r05A1, r05DE, 0x03));

                     body.emit(assign(r05A0, body.constant(false), 0x01));


                  body.instructions = f05CF_parent_instructions;
                  body.emit(f05CF);

                  /* END IF */

                  body.emit(assign(r01EB, r05A1, 0x03));

                  body.emit(assign(r01EA, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0555->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05E4 = less(r0389, r0387);
                  ir_if *f05E3 = new(mem_ctx) ir_if(operand(r05E4).val);
                  exec_list *const f05E3_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05E3->then_instructions;

                     ir_variable *const r05E5 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_variable *const r05E6 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r05E6, sub(r0388, r038A), 0x01));

                     ir_expression *const r05E7 = sub(r0387, r0389);
                     ir_expression *const r05E8 = less(r0388, r038A);
                     ir_expression *const r05E9 = expr(ir_unop_b2i, r05E8);
                     ir_expression *const r05EA = expr(ir_unop_i2u, r05E9);
                     body.emit(assign(r05E5, sub(r05E7, r05EA), 0x01));

                     body.emit(assign(r01EC, bit_xor(r01EC, body.constant(1u)), 0x01));

                     body.emit(assign(r038B, add(r0385, body.constant(int(-1))), 0x01));

                     ir_variable *const r05EB = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05EB, add(r038B, body.constant(int(-10))), 0x01));

                     ir_variable *const r05EC = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r05EC, r05E5, 0x01));

                     ir_variable *const r05ED = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r05ED, r05E6, 0x01));

                     ir_variable *const r05EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r05EE);
                     ir_variable *const r05EF = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05EF);
                     /* IF CONDITION */
                     ir_expression *const r05F1 = equal(r05E5, body.constant(0u));
                     ir_if *f05F0 = new(mem_ctx) ir_if(operand(r05F1).val);
                     exec_list *const f05F0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05F0->then_instructions;

                        body.emit(assign(r05EC, r05E6, 0x01));

                        body.emit(assign(r05ED, body.constant(0u), 0x01));

                        body.emit(assign(r05EB, add(r05EB, body.constant(int(-32))), 0x01));


                     body.instructions = f05F0_parent_instructions;
                     body.emit(f05F0);

                     /* END IF */

                     ir_variable *const r05F2 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r05F2, r05EC, 0x01));

                     ir_variable *const r05F3 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r05F4 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05F4);
                     /* IF CONDITION */
                     ir_expression *const r05F6 = equal(r05EC, body.constant(0u));
                     ir_if *f05F5 = new(mem_ctx) ir_if(operand(r05F6).val);
                     exec_list *const f05F5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05F5->then_instructions;

                        body.emit(assign(r05F3, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05F5->else_instructions;

                        body.emit(assign(r05F4, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05F8 = bit_and(r05EC, body.constant(4294901760u));
                        ir_expression *const r05F9 = equal(r05F8, body.constant(0u));
                        ir_if *f05F7 = new(mem_ctx) ir_if(operand(r05F9).val);
                        exec_list *const f05F7_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05F7->then_instructions;

                           body.emit(assign(r05F4, body.constant(int(16)), 0x01));

                           body.emit(assign(r05F2, lshift(r05EC, body.constant(int(16))), 0x01));


                        body.instructions = f05F7_parent_instructions;
                        body.emit(f05F7);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05FB = bit_and(r05F2, body.constant(4278190080u));
                        ir_expression *const r05FC = equal(r05FB, body.constant(0u));
                        ir_if *f05FA = new(mem_ctx) ir_if(operand(r05FC).val);
                        exec_list *const f05FA_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05FA->then_instructions;

                           body.emit(assign(r05F4, add(r05F4, body.constant(int(8))), 0x01));

                           body.emit(assign(r05F2, lshift(r05F2, body.constant(int(8))), 0x01));


                        body.instructions = f05FA_parent_instructions;
                        body.emit(f05FA);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05FE = bit_and(r05F2, body.constant(4026531840u));
                        ir_expression *const r05FF = equal(r05FE, body.constant(0u));
                        ir_if *f05FD = new(mem_ctx) ir_if(operand(r05FF).val);
                        exec_list *const f05FD_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05FD->then_instructions;

                           body.emit(assign(r05F4, add(r05F4, body.constant(int(4))), 0x01));

                           body.emit(assign(r05F2, lshift(r05F2, body.constant(int(4))), 0x01));


                        body.instructions = f05FD_parent_instructions;
                        body.emit(f05FD);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0601 = bit_and(r05F2, body.constant(3221225472u));
                        ir_expression *const r0602 = equal(r0601, body.constant(0u));
                        ir_if *f0600 = new(mem_ctx) ir_if(operand(r0602).val);
                        exec_list *const f0600_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0600->then_instructions;

                           body.emit(assign(r05F4, add(r05F4, body.constant(int(2))), 0x01));

                           body.emit(assign(r05F2, lshift(r05F2, body.constant(int(2))), 0x01));


                        body.instructions = f0600_parent_instructions;
                        body.emit(f0600);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0604 = bit_and(r05F2, body.constant(2147483648u));
                        ir_expression *const r0605 = equal(r0604, body.constant(0u));
                        ir_if *f0603 = new(mem_ctx) ir_if(operand(r0605).val);
                        exec_list *const f0603_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0603->then_instructions;

                           body.emit(assign(r05F4, add(r05F4, body.constant(int(1))), 0x01));


                        body.instructions = f0603_parent_instructions;
                        body.emit(f0603);

                        /* END IF */

                        body.emit(assign(r05F3, r05F4, 0x01));


                     body.instructions = f05F5_parent_instructions;
                     body.emit(f05F5);

                     /* END IF */

                     body.emit(assign(r05EF, add(r05F3, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0607 = gequal(r05EF, body.constant(int(0)));
                     ir_if *f0606 = new(mem_ctx) ir_if(operand(r0607).val);
                     exec_list *const f0606_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0606->then_instructions;

                        body.emit(assign(r05EE, body.constant(0u), 0x01));

                        ir_expression *const r0608 = equal(r05EF, body.constant(int(0)));
                        ir_expression *const r0609 = lshift(r05EC, r05EF);
                        ir_expression *const r060A = neg(r05EF);
                        ir_expression *const r060B = bit_and(r060A, body.constant(int(31)));
                        ir_expression *const r060C = rshift(r05ED, r060B);
                        ir_expression *const r060D = bit_or(r0609, r060C);
                        body.emit(assign(r05EC, expr(ir_triop_csel, r0608, r05EC, r060D), 0x01));

                        body.emit(assign(r05ED, lshift(r05ED, r05EF), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0606->else_instructions;

                        ir_variable *const r060E = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r060E, body.constant(0u), 0x01));

                        ir_variable *const r060F = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r060F, neg(r05EF), 0x01));

                        ir_variable *const r0610 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0610);
                        ir_variable *const r0611 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r0611);
                        ir_variable *const r0612 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0612);
                        ir_variable *const r0613 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0614 = neg(r060F);
                        body.emit(assign(r0613, bit_and(r0614, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0616 = equal(r060F, body.constant(int(0)));
                        ir_if *f0615 = new(mem_ctx) ir_if(operand(r0616).val);
                        exec_list *const f0615_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0615->then_instructions;

                           body.emit(assign(r0610, r060E, 0x01));

                           body.emit(assign(r0611, r05ED, 0x01));

                           body.emit(assign(r0612, r05EC, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0615->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0618 = less(r060F, body.constant(int(32)));
                           ir_if *f0617 = new(mem_ctx) ir_if(operand(r0618).val);
                           exec_list *const f0617_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0617->then_instructions;

                              body.emit(assign(r0610, lshift(r05ED, r0613), 0x01));

                              ir_expression *const r0619 = lshift(r05EC, r0613);
                              ir_expression *const r061A = rshift(r05ED, r060F);
                              body.emit(assign(r0611, bit_or(r0619, r061A), 0x01));

                              body.emit(assign(r0612, rshift(r05EC, r060F), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0617->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r061C = equal(r060F, body.constant(int(32)));
                              ir_if *f061B = new(mem_ctx) ir_if(operand(r061C).val);
                              exec_list *const f061B_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f061B->then_instructions;

                                 body.emit(assign(r0610, r05ED, 0x01));

                                 body.emit(assign(r0611, r05EC, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f061B->else_instructions;

                                 body.emit(assign(r060E, bit_or(body.constant(0u), r05ED), 0x01));

                                 ir_expression *const r061D = less(r060F, body.constant(int(64)));
                                 ir_expression *const r061E = lshift(r05EC, r0613);
                                 ir_expression *const r061F = equal(r060F, body.constant(int(64)));
                                 ir_expression *const r0620 = nequal(r05EC, body.constant(0u));
                                 ir_expression *const r0621 = expr(ir_unop_b2i, r0620);
                                 ir_expression *const r0622 = expr(ir_unop_i2u, r0621);
                                 ir_expression *const r0623 = expr(ir_triop_csel, r061F, r05EC, r0622);
                                 body.emit(assign(r0610, expr(ir_triop_csel, r061D, r061E, r0623), 0x01));

                                 ir_expression *const r0624 = less(r060F, body.constant(int(64)));
                                 ir_expression *const r0625 = bit_and(r060F, body.constant(int(31)));
                                 ir_expression *const r0626 = rshift(r05EC, r0625);
                                 body.emit(assign(r0611, expr(ir_triop_csel, r0624, r0626, body.constant(0u)), 0x01));


                              body.instructions = f061B_parent_instructions;
                              body.emit(f061B);

                              /* END IF */

                              body.emit(assign(r0612, body.constant(0u), 0x01));


                           body.instructions = f0617_parent_instructions;
                           body.emit(f0617);

                           /* END IF */

                           ir_expression *const r0627 = nequal(r060E, body.constant(0u));
                           ir_expression *const r0628 = expr(ir_unop_b2i, r0627);
                           ir_expression *const r0629 = expr(ir_unop_i2u, r0628);
                           body.emit(assign(r0610, bit_or(r0610, r0629), 0x01));


                        body.instructions = f0615_parent_instructions;
                        body.emit(f0615);

                        /* END IF */

                        body.emit(assign(r05EC, r0612, 0x01));

                        body.emit(assign(r05ED, r0611, 0x01));

                        body.emit(assign(r05EE, r0610, 0x01));


                     body.instructions = f0606_parent_instructions;
                     body.emit(f0606);

                     /* END IF */

                     body.emit(assign(r05EB, sub(r05EB, r05EF), 0x01));

                     ir_variable *const r062A = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r062A, r05EB, 0x01));

                     ir_variable *const r062B = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r062B, r05EC, 0x01));

                     ir_variable *const r062C = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r062C, r05ED, 0x01));

                     ir_variable *const r062D = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r062D, r05EE, 0x01));

                     ir_variable *const r062E = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r062E, body.constant(true), 0x01));

                     ir_variable *const r062F = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r0630 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r0630);
                     ir_expression *const r0631 = expr(ir_unop_u2i, r05EE);
                     body.emit(assign(r0630, less(r0631, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0633 = gequal(r05EB, body.constant(int(2045)));
                     ir_if *f0632 = new(mem_ctx) ir_if(operand(r0633).val);
                     exec_list *const f0632_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0632->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0635 = less(body.constant(int(2045)), r05EB);
                        ir_expression *const r0636 = equal(r05EB, body.constant(int(2045)));
                        ir_expression *const r0637 = equal(body.constant(2097151u), r05EC);
                        ir_expression *const r0638 = equal(body.constant(4294967295u), r05ED);
                        ir_expression *const r0639 = logic_and(r0637, r0638);
                        ir_expression *const r063A = logic_and(r0636, r0639);
                        ir_expression *const r063B = logic_and(r063A, r0630);
                        ir_expression *const r063C = logic_or(r0635, r063B);
                        ir_if *f0634 = new(mem_ctx) ir_if(operand(r063C).val);
                        exec_list *const f0634_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0634->then_instructions;

                           ir_variable *const r063D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r063D);
                           ir_expression *const r063E = lshift(r01EC, body.constant(int(31)));
                           body.emit(assign(r063D, add(r063E, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r063D, body.constant(0u), 0x01));

                           body.emit(assign(r062F, r063D, 0x03));

                           body.emit(assign(r062E, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0634->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0640 = less(r05EB, body.constant(int(0)));
                           ir_if *f063F = new(mem_ctx) ir_if(operand(r0640).val);
                           exec_list *const f063F_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f063F->then_instructions;

                              ir_variable *const r0641 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r0641, r05EE, 0x01));

                              ir_variable *const r0642 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0642, neg(r05EB), 0x01));

                              ir_variable *const r0643 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0643);
                              ir_variable *const r0644 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0644);
                              ir_variable *const r0645 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0645);
                              ir_variable *const r0646 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0647 = neg(r0642);
                              body.emit(assign(r0646, bit_and(r0647, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0649 = equal(r0642, body.constant(int(0)));
                              ir_if *f0648 = new(mem_ctx) ir_if(operand(r0649).val);
                              exec_list *const f0648_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0648->then_instructions;

                                 body.emit(assign(r0643, r05EE, 0x01));

                                 body.emit(assign(r0644, r05ED, 0x01));

                                 body.emit(assign(r0645, r05EC, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0648->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r064B = less(r0642, body.constant(int(32)));
                                 ir_if *f064A = new(mem_ctx) ir_if(operand(r064B).val);
                                 exec_list *const f064A_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f064A->then_instructions;

                                    body.emit(assign(r0643, lshift(r05ED, r0646), 0x01));

                                    ir_expression *const r064C = lshift(r05EC, r0646);
                                    ir_expression *const r064D = rshift(r05ED, r0642);
                                    body.emit(assign(r0644, bit_or(r064C, r064D), 0x01));

                                    body.emit(assign(r0645, rshift(r05EC, r0642), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f064A->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r064F = equal(r0642, body.constant(int(32)));
                                    ir_if *f064E = new(mem_ctx) ir_if(operand(r064F).val);
                                    exec_list *const f064E_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f064E->then_instructions;

                                       body.emit(assign(r0643, r05ED, 0x01));

                                       body.emit(assign(r0644, r05EC, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f064E->else_instructions;

                                       body.emit(assign(r0641, bit_or(r05EE, r05ED), 0x01));

                                       ir_expression *const r0650 = less(r0642, body.constant(int(64)));
                                       ir_expression *const r0651 = lshift(r05EC, r0646);
                                       ir_expression *const r0652 = equal(r0642, body.constant(int(64)));
                                       ir_expression *const r0653 = nequal(r05EC, body.constant(0u));
                                       ir_expression *const r0654 = expr(ir_unop_b2i, r0653);
                                       ir_expression *const r0655 = expr(ir_unop_i2u, r0654);
                                       ir_expression *const r0656 = expr(ir_triop_csel, r0652, r05EC, r0655);
                                       body.emit(assign(r0643, expr(ir_triop_csel, r0650, r0651, r0656), 0x01));

                                       ir_expression *const r0657 = less(r0642, body.constant(int(64)));
                                       ir_expression *const r0658 = bit_and(r0642, body.constant(int(31)));
                                       ir_expression *const r0659 = rshift(r05EC, r0658);
                                       body.emit(assign(r0644, expr(ir_triop_csel, r0657, r0659, body.constant(0u)), 0x01));


                                    body.instructions = f064E_parent_instructions;
                                    body.emit(f064E);

                                    /* END IF */

                                    body.emit(assign(r0645, body.constant(0u), 0x01));


                                 body.instructions = f064A_parent_instructions;
                                 body.emit(f064A);

                                 /* END IF */

                                 ir_expression *const r065A = nequal(r0641, body.constant(0u));
                                 ir_expression *const r065B = expr(ir_unop_b2i, r065A);
                                 ir_expression *const r065C = expr(ir_unop_i2u, r065B);
                                 body.emit(assign(r0643, bit_or(r0643, r065C), 0x01));


                              body.instructions = f0648_parent_instructions;
                              body.emit(f0648);

                              /* END IF */

                              body.emit(assign(r062B, r0645, 0x01));

                              body.emit(assign(r062C, r0644, 0x01));

                              body.emit(assign(r062D, r0643, 0x01));

                              body.emit(assign(r062A, body.constant(int(0)), 0x01));

                              body.emit(assign(r0630, less(r0643, body.constant(0u)), 0x01));


                           body.instructions = f063F_parent_instructions;
                           body.emit(f063F);

                           /* END IF */


                        body.instructions = f0634_parent_instructions;
                        body.emit(f0634);

                        /* END IF */


                     body.instructions = f0632_parent_instructions;
                     body.emit(f0632);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f065D = new(mem_ctx) ir_if(operand(r062E).val);
                     exec_list *const f065D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f065D->then_instructions;

                        /* IF CONDITION */
                        ir_if *f065E = new(mem_ctx) ir_if(operand(r0630).val);
                        exec_list *const f065E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f065E->then_instructions;

                           ir_variable *const r065F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r065F, add(r062C, body.constant(1u)), 0x01));

                           ir_expression *const r0660 = less(r065F, r062C);
                           ir_expression *const r0661 = expr(ir_unop_b2i, r0660);
                           ir_expression *const r0662 = expr(ir_unop_i2u, r0661);
                           body.emit(assign(r062B, add(r062B, r0662), 0x01));

                           ir_expression *const r0663 = equal(r062D, body.constant(0u));
                           ir_expression *const r0664 = expr(ir_unop_b2i, r0663);
                           ir_expression *const r0665 = expr(ir_unop_i2u, r0664);
                           ir_expression *const r0666 = add(r062D, r0665);
                           ir_expression *const r0667 = bit_and(r0666, body.constant(1u));
                           ir_expression *const r0668 = expr(ir_unop_bit_not, r0667);
                           body.emit(assign(r062C, bit_and(r065F, r0668), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f065E->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r066A = bit_or(r062B, r062C);
                           ir_expression *const r066B = equal(r066A, body.constant(0u));
                           ir_if *f0669 = new(mem_ctx) ir_if(operand(r066B).val);
                           exec_list *const f0669_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0669->then_instructions;

                              body.emit(assign(r062A, body.constant(int(0)), 0x01));


                           body.instructions = f0669_parent_instructions;
                           body.emit(f0669);

                           /* END IF */


                        body.instructions = f065E_parent_instructions;
                        body.emit(f065E);

                        /* END IF */

                        ir_variable *const r066C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r066C);
                        ir_expression *const r066D = lshift(r01EC, body.constant(int(31)));
                        ir_expression *const r066E = expr(ir_unop_i2u, r062A);
                        ir_expression *const r066F = lshift(r066E, body.constant(int(20)));
                        ir_expression *const r0670 = add(r066D, r066F);
                        body.emit(assign(r066C, add(r0670, r062B), 0x02));

                        body.emit(assign(r066C, r062C, 0x01));

                        body.emit(assign(r062F, r066C, 0x03));

                        body.emit(assign(r062E, body.constant(false), 0x01));


                     body.instructions = f065D_parent_instructions;
                     body.emit(f065D);

                     /* END IF */

                     body.emit(assign(r01EB, r062F, 0x03));

                     body.emit(assign(r01EA, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05E3->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0672 = less(r0388, r038A);
                     ir_if *f0671 = new(mem_ctx) ir_if(operand(r0672).val);
                     exec_list *const f0671_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0671->then_instructions;

                        ir_variable *const r0673 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_variable *const r0674 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r0674, sub(r038A, r0388), 0x01));

                        ir_expression *const r0675 = sub(r0389, r0387);
                        ir_expression *const r0676 = less(r038A, r0388);
                        ir_expression *const r0677 = expr(ir_unop_b2i, r0676);
                        ir_expression *const r0678 = expr(ir_unop_i2u, r0677);
                        body.emit(assign(r0673, sub(r0675, r0678), 0x01));

                        body.emit(assign(r038B, add(r0386, body.constant(int(-1))), 0x01));

                        ir_variable *const r0679 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0679, add(r038B, body.constant(int(-10))), 0x01));

                        ir_variable *const r067A = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r067A, r0673, 0x01));

                        ir_variable *const r067B = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r067B, r0674, 0x01));

                        ir_variable *const r067C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r067C);
                        ir_variable *const r067D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r067D);
                        /* IF CONDITION */
                        ir_expression *const r067F = equal(r0673, body.constant(0u));
                        ir_if *f067E = new(mem_ctx) ir_if(operand(r067F).val);
                        exec_list *const f067E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f067E->then_instructions;

                           body.emit(assign(r067A, r0674, 0x01));

                           body.emit(assign(r067B, body.constant(0u), 0x01));

                           body.emit(assign(r0679, add(r0679, body.constant(int(-32))), 0x01));


                        body.instructions = f067E_parent_instructions;
                        body.emit(f067E);

                        /* END IF */

                        ir_variable *const r0680 = body.make_temp(glsl_type::uint_type, "a");
                        body.emit(assign(r0680, r067A, 0x01));

                        ir_variable *const r0681 = body.make_temp(glsl_type::int_type, "return_value");
                        ir_variable *const r0682 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0682);
                        /* IF CONDITION */
                        ir_expression *const r0684 = equal(r067A, body.constant(0u));
                        ir_if *f0683 = new(mem_ctx) ir_if(operand(r0684).val);
                        exec_list *const f0683_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0683->then_instructions;

                           body.emit(assign(r0681, body.constant(int(32)), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0683->else_instructions;

                           body.emit(assign(r0682, body.constant(int(0)), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0686 = bit_and(r067A, body.constant(4294901760u));
                           ir_expression *const r0687 = equal(r0686, body.constant(0u));
                           ir_if *f0685 = new(mem_ctx) ir_if(operand(r0687).val);
                           exec_list *const f0685_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0685->then_instructions;

                              body.emit(assign(r0682, body.constant(int(16)), 0x01));

                              body.emit(assign(r0680, lshift(r067A, body.constant(int(16))), 0x01));


                           body.instructions = f0685_parent_instructions;
                           body.emit(f0685);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0689 = bit_and(r0680, body.constant(4278190080u));
                           ir_expression *const r068A = equal(r0689, body.constant(0u));
                           ir_if *f0688 = new(mem_ctx) ir_if(operand(r068A).val);
                           exec_list *const f0688_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0688->then_instructions;

                              body.emit(assign(r0682, add(r0682, body.constant(int(8))), 0x01));

                              body.emit(assign(r0680, lshift(r0680, body.constant(int(8))), 0x01));


                           body.instructions = f0688_parent_instructions;
                           body.emit(f0688);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r068C = bit_and(r0680, body.constant(4026531840u));
                           ir_expression *const r068D = equal(r068C, body.constant(0u));
                           ir_if *f068B = new(mem_ctx) ir_if(operand(r068D).val);
                           exec_list *const f068B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f068B->then_instructions;

                              body.emit(assign(r0682, add(r0682, body.constant(int(4))), 0x01));

                              body.emit(assign(r0680, lshift(r0680, body.constant(int(4))), 0x01));


                           body.instructions = f068B_parent_instructions;
                           body.emit(f068B);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r068F = bit_and(r0680, body.constant(3221225472u));
                           ir_expression *const r0690 = equal(r068F, body.constant(0u));
                           ir_if *f068E = new(mem_ctx) ir_if(operand(r0690).val);
                           exec_list *const f068E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f068E->then_instructions;

                              body.emit(assign(r0682, add(r0682, body.constant(int(2))), 0x01));

                              body.emit(assign(r0680, lshift(r0680, body.constant(int(2))), 0x01));


                           body.instructions = f068E_parent_instructions;
                           body.emit(f068E);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0692 = bit_and(r0680, body.constant(2147483648u));
                           ir_expression *const r0693 = equal(r0692, body.constant(0u));
                           ir_if *f0691 = new(mem_ctx) ir_if(operand(r0693).val);
                           exec_list *const f0691_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0691->then_instructions;

                              body.emit(assign(r0682, add(r0682, body.constant(int(1))), 0x01));


                           body.instructions = f0691_parent_instructions;
                           body.emit(f0691);

                           /* END IF */

                           body.emit(assign(r0681, r0682, 0x01));


                        body.instructions = f0683_parent_instructions;
                        body.emit(f0683);

                        /* END IF */

                        body.emit(assign(r067D, add(r0681, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0695 = gequal(r067D, body.constant(int(0)));
                        ir_if *f0694 = new(mem_ctx) ir_if(operand(r0695).val);
                        exec_list *const f0694_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0694->then_instructions;

                           body.emit(assign(r067C, body.constant(0u), 0x01));

                           ir_expression *const r0696 = equal(r067D, body.constant(int(0)));
                           ir_expression *const r0697 = lshift(r067A, r067D);
                           ir_expression *const r0698 = neg(r067D);
                           ir_expression *const r0699 = bit_and(r0698, body.constant(int(31)));
                           ir_expression *const r069A = rshift(r067B, r0699);
                           ir_expression *const r069B = bit_or(r0697, r069A);
                           body.emit(assign(r067A, expr(ir_triop_csel, r0696, r067A, r069B), 0x01));

                           body.emit(assign(r067B, lshift(r067B, r067D), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0694->else_instructions;

                           ir_variable *const r069C = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r069C, body.constant(0u), 0x01));

                           ir_variable *const r069D = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r069D, neg(r067D), 0x01));

                           ir_variable *const r069E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r069E);
                           ir_variable *const r069F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r069F);
                           ir_variable *const r06A0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r06A0);
                           ir_variable *const r06A1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r06A2 = neg(r069D);
                           body.emit(assign(r06A1, bit_and(r06A2, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06A4 = equal(r069D, body.constant(int(0)));
                           ir_if *f06A3 = new(mem_ctx) ir_if(operand(r06A4).val);
                           exec_list *const f06A3_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06A3->then_instructions;

                              body.emit(assign(r069E, r069C, 0x01));

                              body.emit(assign(r069F, r067B, 0x01));

                              body.emit(assign(r06A0, r067A, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06A3->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06A6 = less(r069D, body.constant(int(32)));
                              ir_if *f06A5 = new(mem_ctx) ir_if(operand(r06A6).val);
                              exec_list *const f06A5_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06A5->then_instructions;

                                 body.emit(assign(r069E, lshift(r067B, r06A1), 0x01));

                                 ir_expression *const r06A7 = lshift(r067A, r06A1);
                                 ir_expression *const r06A8 = rshift(r067B, r069D);
                                 body.emit(assign(r069F, bit_or(r06A7, r06A8), 0x01));

                                 body.emit(assign(r06A0, rshift(r067A, r069D), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06A5->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06AA = equal(r069D, body.constant(int(32)));
                                 ir_if *f06A9 = new(mem_ctx) ir_if(operand(r06AA).val);
                                 exec_list *const f06A9_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06A9->then_instructions;

                                    body.emit(assign(r069E, r067B, 0x01));

                                    body.emit(assign(r069F, r067A, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06A9->else_instructions;

                                    body.emit(assign(r069C, bit_or(body.constant(0u), r067B), 0x01));

                                    ir_expression *const r06AB = less(r069D, body.constant(int(64)));
                                    ir_expression *const r06AC = lshift(r067A, r06A1);
                                    ir_expression *const r06AD = equal(r069D, body.constant(int(64)));
                                    ir_expression *const r06AE = nequal(r067A, body.constant(0u));
                                    ir_expression *const r06AF = expr(ir_unop_b2i, r06AE);
                                    ir_expression *const r06B0 = expr(ir_unop_i2u, r06AF);
                                    ir_expression *const r06B1 = expr(ir_triop_csel, r06AD, r067A, r06B0);
                                    body.emit(assign(r069E, expr(ir_triop_csel, r06AB, r06AC, r06B1), 0x01));

                                    ir_expression *const r06B2 = less(r069D, body.constant(int(64)));
                                    ir_expression *const r06B3 = bit_and(r069D, body.constant(int(31)));
                                    ir_expression *const r06B4 = rshift(r067A, r06B3);
                                    body.emit(assign(r069F, expr(ir_triop_csel, r06B2, r06B4, body.constant(0u)), 0x01));


                                 body.instructions = f06A9_parent_instructions;
                                 body.emit(f06A9);

                                 /* END IF */

                                 body.emit(assign(r06A0, body.constant(0u), 0x01));


                              body.instructions = f06A5_parent_instructions;
                              body.emit(f06A5);

                              /* END IF */

                              ir_expression *const r06B5 = nequal(r069C, body.constant(0u));
                              ir_expression *const r06B6 = expr(ir_unop_b2i, r06B5);
                              ir_expression *const r06B7 = expr(ir_unop_i2u, r06B6);
                              body.emit(assign(r069E, bit_or(r069E, r06B7), 0x01));


                           body.instructions = f06A3_parent_instructions;
                           body.emit(f06A3);

                           /* END IF */

                           body.emit(assign(r067A, r06A0, 0x01));

                           body.emit(assign(r067B, r069F, 0x01));

                           body.emit(assign(r067C, r069E, 0x01));


                        body.instructions = f0694_parent_instructions;
                        body.emit(f0694);

                        /* END IF */

                        body.emit(assign(r0679, sub(r0679, r067D), 0x01));

                        ir_variable *const r06B8 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r06B8, r0679, 0x01));

                        ir_variable *const r06B9 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r06B9, r067A, 0x01));

                        ir_variable *const r06BA = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r06BA, r067B, 0x01));

                        ir_variable *const r06BB = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r06BB, r067C, 0x01));

                        ir_variable *const r06BC = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r06BC, body.constant(true), 0x01));

                        ir_variable *const r06BD = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r06BE = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r06BE);
                        ir_expression *const r06BF = expr(ir_unop_u2i, r067C);
                        body.emit(assign(r06BE, less(r06BF, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r06C1 = gequal(r0679, body.constant(int(2045)));
                        ir_if *f06C0 = new(mem_ctx) ir_if(operand(r06C1).val);
                        exec_list *const f06C0_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06C0->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r06C3 = less(body.constant(int(2045)), r0679);
                           ir_expression *const r06C4 = equal(r0679, body.constant(int(2045)));
                           ir_expression *const r06C5 = equal(body.constant(2097151u), r067A);
                           ir_expression *const r06C6 = equal(body.constant(4294967295u), r067B);
                           ir_expression *const r06C7 = logic_and(r06C5, r06C6);
                           ir_expression *const r06C8 = logic_and(r06C4, r06C7);
                           ir_expression *const r06C9 = logic_and(r06C8, r06BE);
                           ir_expression *const r06CA = logic_or(r06C3, r06C9);
                           ir_if *f06C2 = new(mem_ctx) ir_if(operand(r06CA).val);
                           exec_list *const f06C2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06C2->then_instructions;

                              ir_variable *const r06CB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r06CB);
                              ir_expression *const r06CC = lshift(r01EC, body.constant(int(31)));
                              body.emit(assign(r06CB, add(r06CC, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r06CB, body.constant(0u), 0x01));

                              body.emit(assign(r06BD, r06CB, 0x03));

                              body.emit(assign(r06BC, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06C2->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06CE = less(r0679, body.constant(int(0)));
                              ir_if *f06CD = new(mem_ctx) ir_if(operand(r06CE).val);
                              exec_list *const f06CD_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06CD->then_instructions;

                                 ir_variable *const r06CF = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r06CF, r067C, 0x01));

                                 ir_variable *const r06D0 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r06D0, neg(r0679), 0x01));

                                 ir_variable *const r06D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r06D1);
                                 ir_variable *const r06D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r06D2);
                                 ir_variable *const r06D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r06D3);
                                 ir_variable *const r06D4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r06D5 = neg(r06D0);
                                 body.emit(assign(r06D4, bit_and(r06D5, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r06D7 = equal(r06D0, body.constant(int(0)));
                                 ir_if *f06D6 = new(mem_ctx) ir_if(operand(r06D7).val);
                                 exec_list *const f06D6_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06D6->then_instructions;

                                    body.emit(assign(r06D1, r067C, 0x01));

                                    body.emit(assign(r06D2, r067B, 0x01));

                                    body.emit(assign(r06D3, r067A, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06D6->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06D9 = less(r06D0, body.constant(int(32)));
                                    ir_if *f06D8 = new(mem_ctx) ir_if(operand(r06D9).val);
                                    exec_list *const f06D8_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06D8->then_instructions;

                                       body.emit(assign(r06D1, lshift(r067B, r06D4), 0x01));

                                       ir_expression *const r06DA = lshift(r067A, r06D4);
                                       ir_expression *const r06DB = rshift(r067B, r06D0);
                                       body.emit(assign(r06D2, bit_or(r06DA, r06DB), 0x01));

                                       body.emit(assign(r06D3, rshift(r067A, r06D0), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06D8->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r06DD = equal(r06D0, body.constant(int(32)));
                                       ir_if *f06DC = new(mem_ctx) ir_if(operand(r06DD).val);
                                       exec_list *const f06DC_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06DC->then_instructions;

                                          body.emit(assign(r06D1, r067B, 0x01));

                                          body.emit(assign(r06D2, r067A, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06DC->else_instructions;

                                          body.emit(assign(r06CF, bit_or(r067C, r067B), 0x01));

                                          ir_expression *const r06DE = less(r06D0, body.constant(int(64)));
                                          ir_expression *const r06DF = lshift(r067A, r06D4);
                                          ir_expression *const r06E0 = equal(r06D0, body.constant(int(64)));
                                          ir_expression *const r06E1 = nequal(r067A, body.constant(0u));
                                          ir_expression *const r06E2 = expr(ir_unop_b2i, r06E1);
                                          ir_expression *const r06E3 = expr(ir_unop_i2u, r06E2);
                                          ir_expression *const r06E4 = expr(ir_triop_csel, r06E0, r067A, r06E3);
                                          body.emit(assign(r06D1, expr(ir_triop_csel, r06DE, r06DF, r06E4), 0x01));

                                          ir_expression *const r06E5 = less(r06D0, body.constant(int(64)));
                                          ir_expression *const r06E6 = bit_and(r06D0, body.constant(int(31)));
                                          ir_expression *const r06E7 = rshift(r067A, r06E6);
                                          body.emit(assign(r06D2, expr(ir_triop_csel, r06E5, r06E7, body.constant(0u)), 0x01));


                                       body.instructions = f06DC_parent_instructions;
                                       body.emit(f06DC);

                                       /* END IF */

                                       body.emit(assign(r06D3, body.constant(0u), 0x01));


                                    body.instructions = f06D8_parent_instructions;
                                    body.emit(f06D8);

                                    /* END IF */

                                    ir_expression *const r06E8 = nequal(r06CF, body.constant(0u));
                                    ir_expression *const r06E9 = expr(ir_unop_b2i, r06E8);
                                    ir_expression *const r06EA = expr(ir_unop_i2u, r06E9);
                                    body.emit(assign(r06D1, bit_or(r06D1, r06EA), 0x01));


                                 body.instructions = f06D6_parent_instructions;
                                 body.emit(f06D6);

                                 /* END IF */

                                 body.emit(assign(r06B9, r06D3, 0x01));

                                 body.emit(assign(r06BA, r06D2, 0x01));

                                 body.emit(assign(r06BB, r06D1, 0x01));

                                 body.emit(assign(r06B8, body.constant(int(0)), 0x01));

                                 body.emit(assign(r06BE, less(r06D1, body.constant(0u)), 0x01));


                              body.instructions = f06CD_parent_instructions;
                              body.emit(f06CD);

                              /* END IF */


                           body.instructions = f06C2_parent_instructions;
                           body.emit(f06C2);

                           /* END IF */


                        body.instructions = f06C0_parent_instructions;
                        body.emit(f06C0);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f06EB = new(mem_ctx) ir_if(operand(r06BC).val);
                        exec_list *const f06EB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06EB->then_instructions;

                           /* IF CONDITION */
                           ir_if *f06EC = new(mem_ctx) ir_if(operand(r06BE).val);
                           exec_list *const f06EC_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06EC->then_instructions;

                              ir_variable *const r06ED = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r06ED, add(r06BA, body.constant(1u)), 0x01));

                              ir_expression *const r06EE = less(r06ED, r06BA);
                              ir_expression *const r06EF = expr(ir_unop_b2i, r06EE);
                              ir_expression *const r06F0 = expr(ir_unop_i2u, r06EF);
                              body.emit(assign(r06B9, add(r06B9, r06F0), 0x01));

                              ir_expression *const r06F1 = equal(r06BB, body.constant(0u));
                              ir_expression *const r06F2 = expr(ir_unop_b2i, r06F1);
                              ir_expression *const r06F3 = expr(ir_unop_i2u, r06F2);
                              ir_expression *const r06F4 = add(r06BB, r06F3);
                              ir_expression *const r06F5 = bit_and(r06F4, body.constant(1u));
                              ir_expression *const r06F6 = expr(ir_unop_bit_not, r06F5);
                              body.emit(assign(r06BA, bit_and(r06ED, r06F6), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06EC->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06F8 = bit_or(r06B9, r06BA);
                              ir_expression *const r06F9 = equal(r06F8, body.constant(0u));
                              ir_if *f06F7 = new(mem_ctx) ir_if(operand(r06F9).val);
                              exec_list *const f06F7_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06F7->then_instructions;

                                 body.emit(assign(r06B8, body.constant(int(0)), 0x01));


                              body.instructions = f06F7_parent_instructions;
                              body.emit(f06F7);

                              /* END IF */


                           body.instructions = f06EC_parent_instructions;
                           body.emit(f06EC);

                           /* END IF */

                           ir_variable *const r06FA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r06FA);
                           ir_expression *const r06FB = lshift(r01EC, body.constant(int(31)));
                           ir_expression *const r06FC = expr(ir_unop_i2u, r06B8);
                           ir_expression *const r06FD = lshift(r06FC, body.constant(int(20)));
                           ir_expression *const r06FE = add(r06FB, r06FD);
                           body.emit(assign(r06FA, add(r06FE, r06B9), 0x02));

                           body.emit(assign(r06FA, r06BA, 0x01));

                           body.emit(assign(r06BD, r06FA, 0x03));

                           body.emit(assign(r06BC, body.constant(false), 0x01));


                        body.instructions = f06EB_parent_instructions;
                        body.emit(f06EB);

                        /* END IF */

                        body.emit(assign(r01EB, r06BD, 0x03));

                        body.emit(assign(r01EA, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0671->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0700 = less(r038A, r0388);
                        ir_if *f06FF = new(mem_ctx) ir_if(operand(r0700).val);
                        exec_list *const f06FF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06FF->then_instructions;

                           ir_variable *const r0701 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_variable *const r0702 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r0702, sub(r0388, r038A), 0x01));

                           ir_expression *const r0703 = sub(r0387, r0389);
                           ir_expression *const r0704 = less(r0388, r038A);
                           ir_expression *const r0705 = expr(ir_unop_b2i, r0704);
                           ir_expression *const r0706 = expr(ir_unop_i2u, r0705);
                           body.emit(assign(r0701, sub(r0703, r0706), 0x01));

                           body.emit(assign(r01EC, bit_xor(r01EC, body.constant(1u)), 0x01));

                           body.emit(assign(r038B, add(r0385, body.constant(int(-1))), 0x01));

                           ir_variable *const r0707 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r0707, add(r038B, body.constant(int(-10))), 0x01));

                           ir_variable *const r0708 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r0708, r0701, 0x01));

                           ir_variable *const r0709 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r0709, r0702, 0x01));

                           ir_variable *const r070A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r070A);
                           ir_variable *const r070B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r070B);
                           /* IF CONDITION */
                           ir_expression *const r070D = equal(r0701, body.constant(0u));
                           ir_if *f070C = new(mem_ctx) ir_if(operand(r070D).val);
                           exec_list *const f070C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f070C->then_instructions;

                              body.emit(assign(r0708, r0702, 0x01));

                              body.emit(assign(r0709, body.constant(0u), 0x01));

                              body.emit(assign(r0707, add(r0707, body.constant(int(-32))), 0x01));


                           body.instructions = f070C_parent_instructions;
                           body.emit(f070C);

                           /* END IF */

                           ir_variable *const r070E = body.make_temp(glsl_type::uint_type, "a");
                           body.emit(assign(r070E, r0708, 0x01));

                           ir_variable *const r070F = body.make_temp(glsl_type::int_type, "return_value");
                           ir_variable *const r0710 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r0710);
                           /* IF CONDITION */
                           ir_expression *const r0712 = equal(r0708, body.constant(0u));
                           ir_if *f0711 = new(mem_ctx) ir_if(operand(r0712).val);
                           exec_list *const f0711_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0711->then_instructions;

                              body.emit(assign(r070F, body.constant(int(32)), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0711->else_instructions;

                              body.emit(assign(r0710, body.constant(int(0)), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0714 = bit_and(r0708, body.constant(4294901760u));
                              ir_expression *const r0715 = equal(r0714, body.constant(0u));
                              ir_if *f0713 = new(mem_ctx) ir_if(operand(r0715).val);
                              exec_list *const f0713_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0713->then_instructions;

                                 body.emit(assign(r0710, body.constant(int(16)), 0x01));

                                 body.emit(assign(r070E, lshift(r0708, body.constant(int(16))), 0x01));


                              body.instructions = f0713_parent_instructions;
                              body.emit(f0713);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0717 = bit_and(r070E, body.constant(4278190080u));
                              ir_expression *const r0718 = equal(r0717, body.constant(0u));
                              ir_if *f0716 = new(mem_ctx) ir_if(operand(r0718).val);
                              exec_list *const f0716_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0716->then_instructions;

                                 body.emit(assign(r0710, add(r0710, body.constant(int(8))), 0x01));

                                 body.emit(assign(r070E, lshift(r070E, body.constant(int(8))), 0x01));


                              body.instructions = f0716_parent_instructions;
                              body.emit(f0716);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r071A = bit_and(r070E, body.constant(4026531840u));
                              ir_expression *const r071B = equal(r071A, body.constant(0u));
                              ir_if *f0719 = new(mem_ctx) ir_if(operand(r071B).val);
                              exec_list *const f0719_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0719->then_instructions;

                                 body.emit(assign(r0710, add(r0710, body.constant(int(4))), 0x01));

                                 body.emit(assign(r070E, lshift(r070E, body.constant(int(4))), 0x01));


                              body.instructions = f0719_parent_instructions;
                              body.emit(f0719);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r071D = bit_and(r070E, body.constant(3221225472u));
                              ir_expression *const r071E = equal(r071D, body.constant(0u));
                              ir_if *f071C = new(mem_ctx) ir_if(operand(r071E).val);
                              exec_list *const f071C_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f071C->then_instructions;

                                 body.emit(assign(r0710, add(r0710, body.constant(int(2))), 0x01));

                                 body.emit(assign(r070E, lshift(r070E, body.constant(int(2))), 0x01));


                              body.instructions = f071C_parent_instructions;
                              body.emit(f071C);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0720 = bit_and(r070E, body.constant(2147483648u));
                              ir_expression *const r0721 = equal(r0720, body.constant(0u));
                              ir_if *f071F = new(mem_ctx) ir_if(operand(r0721).val);
                              exec_list *const f071F_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f071F->then_instructions;

                                 body.emit(assign(r0710, add(r0710, body.constant(int(1))), 0x01));


                              body.instructions = f071F_parent_instructions;
                              body.emit(f071F);

                              /* END IF */

                              body.emit(assign(r070F, r0710, 0x01));


                           body.instructions = f0711_parent_instructions;
                           body.emit(f0711);

                           /* END IF */

                           body.emit(assign(r070B, add(r070F, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0723 = gequal(r070B, body.constant(int(0)));
                           ir_if *f0722 = new(mem_ctx) ir_if(operand(r0723).val);
                           exec_list *const f0722_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0722->then_instructions;

                              body.emit(assign(r070A, body.constant(0u), 0x01));

                              ir_expression *const r0724 = equal(r070B, body.constant(int(0)));
                              ir_expression *const r0725 = lshift(r0708, r070B);
                              ir_expression *const r0726 = neg(r070B);
                              ir_expression *const r0727 = bit_and(r0726, body.constant(int(31)));
                              ir_expression *const r0728 = rshift(r0709, r0727);
                              ir_expression *const r0729 = bit_or(r0725, r0728);
                              body.emit(assign(r0708, expr(ir_triop_csel, r0724, r0708, r0729), 0x01));

                              body.emit(assign(r0709, lshift(r0709, r070B), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0722->else_instructions;

                              ir_variable *const r072A = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r072A, body.constant(0u), 0x01));

                              ir_variable *const r072B = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r072B, neg(r070B), 0x01));

                              ir_variable *const r072C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r072C);
                              ir_variable *const r072D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r072D);
                              ir_variable *const r072E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r072E);
                              ir_variable *const r072F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0730 = neg(r072B);
                              body.emit(assign(r072F, bit_and(r0730, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0732 = equal(r072B, body.constant(int(0)));
                              ir_if *f0731 = new(mem_ctx) ir_if(operand(r0732).val);
                              exec_list *const f0731_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0731->then_instructions;

                                 body.emit(assign(r072C, r072A, 0x01));

                                 body.emit(assign(r072D, r0709, 0x01));

                                 body.emit(assign(r072E, r0708, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0731->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0734 = less(r072B, body.constant(int(32)));
                                 ir_if *f0733 = new(mem_ctx) ir_if(operand(r0734).val);
                                 exec_list *const f0733_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0733->then_instructions;

                                    body.emit(assign(r072C, lshift(r0709, r072F), 0x01));

                                    ir_expression *const r0735 = lshift(r0708, r072F);
                                    ir_expression *const r0736 = rshift(r0709, r072B);
                                    body.emit(assign(r072D, bit_or(r0735, r0736), 0x01));

                                    body.emit(assign(r072E, rshift(r0708, r072B), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0733->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0738 = equal(r072B, body.constant(int(32)));
                                    ir_if *f0737 = new(mem_ctx) ir_if(operand(r0738).val);
                                    exec_list *const f0737_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0737->then_instructions;

                                       body.emit(assign(r072C, r0709, 0x01));

                                       body.emit(assign(r072D, r0708, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0737->else_instructions;

                                       body.emit(assign(r072A, bit_or(body.constant(0u), r0709), 0x01));

                                       ir_expression *const r0739 = less(r072B, body.constant(int(64)));
                                       ir_expression *const r073A = lshift(r0708, r072F);
                                       ir_expression *const r073B = equal(r072B, body.constant(int(64)));
                                       ir_expression *const r073C = nequal(r0708, body.constant(0u));
                                       ir_expression *const r073D = expr(ir_unop_b2i, r073C);
                                       ir_expression *const r073E = expr(ir_unop_i2u, r073D);
                                       ir_expression *const r073F = expr(ir_triop_csel, r073B, r0708, r073E);
                                       body.emit(assign(r072C, expr(ir_triop_csel, r0739, r073A, r073F), 0x01));

                                       ir_expression *const r0740 = less(r072B, body.constant(int(64)));
                                       ir_expression *const r0741 = bit_and(r072B, body.constant(int(31)));
                                       ir_expression *const r0742 = rshift(r0708, r0741);
                                       body.emit(assign(r072D, expr(ir_triop_csel, r0740, r0742, body.constant(0u)), 0x01));


                                    body.instructions = f0737_parent_instructions;
                                    body.emit(f0737);

                                    /* END IF */

                                    body.emit(assign(r072E, body.constant(0u), 0x01));


                                 body.instructions = f0733_parent_instructions;
                                 body.emit(f0733);

                                 /* END IF */

                                 ir_expression *const r0743 = nequal(r072A, body.constant(0u));
                                 ir_expression *const r0744 = expr(ir_unop_b2i, r0743);
                                 ir_expression *const r0745 = expr(ir_unop_i2u, r0744);
                                 body.emit(assign(r072C, bit_or(r072C, r0745), 0x01));


                              body.instructions = f0731_parent_instructions;
                              body.emit(f0731);

                              /* END IF */

                              body.emit(assign(r0708, r072E, 0x01));

                              body.emit(assign(r0709, r072D, 0x01));

                              body.emit(assign(r070A, r072C, 0x01));


                           body.instructions = f0722_parent_instructions;
                           body.emit(f0722);

                           /* END IF */

                           body.emit(assign(r0707, sub(r0707, r070B), 0x01));

                           ir_variable *const r0746 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r0746, r0707, 0x01));

                           ir_variable *const r0747 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r0747, r0708, 0x01));

                           ir_variable *const r0748 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r0748, r0709, 0x01));

                           ir_variable *const r0749 = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r0749, r070A, 0x01));

                           ir_variable *const r074A = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r074A, body.constant(true), 0x01));

                           ir_variable *const r074B = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r074C = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r074C);
                           ir_expression *const r074D = expr(ir_unop_u2i, r070A);
                           body.emit(assign(r074C, less(r074D, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r074F = gequal(r0707, body.constant(int(2045)));
                           ir_if *f074E = new(mem_ctx) ir_if(operand(r074F).val);
                           exec_list *const f074E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f074E->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0751 = less(body.constant(int(2045)), r0707);
                              ir_expression *const r0752 = equal(r0707, body.constant(int(2045)));
                              ir_expression *const r0753 = equal(body.constant(2097151u), r0708);
                              ir_expression *const r0754 = equal(body.constant(4294967295u), r0709);
                              ir_expression *const r0755 = logic_and(r0753, r0754);
                              ir_expression *const r0756 = logic_and(r0752, r0755);
                              ir_expression *const r0757 = logic_and(r0756, r074C);
                              ir_expression *const r0758 = logic_or(r0751, r0757);
                              ir_if *f0750 = new(mem_ctx) ir_if(operand(r0758).val);
                              exec_list *const f0750_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0750->then_instructions;

                                 ir_variable *const r0759 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r0759);
                                 ir_expression *const r075A = lshift(r01EC, body.constant(int(31)));
                                 body.emit(assign(r0759, add(r075A, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r0759, body.constant(0u), 0x01));

                                 body.emit(assign(r074B, r0759, 0x03));

                                 body.emit(assign(r074A, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0750->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r075C = less(r0707, body.constant(int(0)));
                                 ir_if *f075B = new(mem_ctx) ir_if(operand(r075C).val);
                                 exec_list *const f075B_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f075B->then_instructions;

                                    ir_variable *const r075D = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r075D, r070A, 0x01));

                                    ir_variable *const r075E = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r075E, neg(r0707), 0x01));

                                    ir_variable *const r075F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r075F);
                                    ir_variable *const r0760 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r0760);
                                    ir_variable *const r0761 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r0761);
                                    ir_variable *const r0762 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r0763 = neg(r075E);
                                    body.emit(assign(r0762, bit_and(r0763, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0765 = equal(r075E, body.constant(int(0)));
                                    ir_if *f0764 = new(mem_ctx) ir_if(operand(r0765).val);
                                    exec_list *const f0764_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0764->then_instructions;

                                       body.emit(assign(r075F, r070A, 0x01));

                                       body.emit(assign(r0760, r0709, 0x01));

                                       body.emit(assign(r0761, r0708, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0764->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r0767 = less(r075E, body.constant(int(32)));
                                       ir_if *f0766 = new(mem_ctx) ir_if(operand(r0767).val);
                                       exec_list *const f0766_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0766->then_instructions;

                                          body.emit(assign(r075F, lshift(r0709, r0762), 0x01));

                                          ir_expression *const r0768 = lshift(r0708, r0762);
                                          ir_expression *const r0769 = rshift(r0709, r075E);
                                          body.emit(assign(r0760, bit_or(r0768, r0769), 0x01));

                                          body.emit(assign(r0761, rshift(r0708, r075E), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0766->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r076B = equal(r075E, body.constant(int(32)));
                                          ir_if *f076A = new(mem_ctx) ir_if(operand(r076B).val);
                                          exec_list *const f076A_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f076A->then_instructions;

                                             body.emit(assign(r075F, r0709, 0x01));

                                             body.emit(assign(r0760, r0708, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f076A->else_instructions;

                                             body.emit(assign(r075D, bit_or(r070A, r0709), 0x01));

                                             ir_expression *const r076C = less(r075E, body.constant(int(64)));
                                             ir_expression *const r076D = lshift(r0708, r0762);
                                             ir_expression *const r076E = equal(r075E, body.constant(int(64)));
                                             ir_expression *const r076F = nequal(r0708, body.constant(0u));
                                             ir_expression *const r0770 = expr(ir_unop_b2i, r076F);
                                             ir_expression *const r0771 = expr(ir_unop_i2u, r0770);
                                             ir_expression *const r0772 = expr(ir_triop_csel, r076E, r0708, r0771);
                                             body.emit(assign(r075F, expr(ir_triop_csel, r076C, r076D, r0772), 0x01));

                                             ir_expression *const r0773 = less(r075E, body.constant(int(64)));
                                             ir_expression *const r0774 = bit_and(r075E, body.constant(int(31)));
                                             ir_expression *const r0775 = rshift(r0708, r0774);
                                             body.emit(assign(r0760, expr(ir_triop_csel, r0773, r0775, body.constant(0u)), 0x01));


                                          body.instructions = f076A_parent_instructions;
                                          body.emit(f076A);

                                          /* END IF */

                                          body.emit(assign(r0761, body.constant(0u), 0x01));


                                       body.instructions = f0766_parent_instructions;
                                       body.emit(f0766);

                                       /* END IF */

                                       ir_expression *const r0776 = nequal(r075D, body.constant(0u));
                                       ir_expression *const r0777 = expr(ir_unop_b2i, r0776);
                                       ir_expression *const r0778 = expr(ir_unop_i2u, r0777);
                                       body.emit(assign(r075F, bit_or(r075F, r0778), 0x01));


                                    body.instructions = f0764_parent_instructions;
                                    body.emit(f0764);

                                    /* END IF */

                                    body.emit(assign(r0747, r0761, 0x01));

                                    body.emit(assign(r0748, r0760, 0x01));

                                    body.emit(assign(r0749, r075F, 0x01));

                                    body.emit(assign(r0746, body.constant(int(0)), 0x01));

                                    body.emit(assign(r074C, less(r075F, body.constant(0u)), 0x01));


                                 body.instructions = f075B_parent_instructions;
                                 body.emit(f075B);

                                 /* END IF */


                              body.instructions = f0750_parent_instructions;
                              body.emit(f0750);

                              /* END IF */


                           body.instructions = f074E_parent_instructions;
                           body.emit(f074E);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f0779 = new(mem_ctx) ir_if(operand(r074A).val);
                           exec_list *const f0779_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0779->then_instructions;

                              /* IF CONDITION */
                              ir_if *f077A = new(mem_ctx) ir_if(operand(r074C).val);
                              exec_list *const f077A_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f077A->then_instructions;

                                 ir_variable *const r077B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r077B, add(r0748, body.constant(1u)), 0x01));

                                 ir_expression *const r077C = less(r077B, r0748);
                                 ir_expression *const r077D = expr(ir_unop_b2i, r077C);
                                 ir_expression *const r077E = expr(ir_unop_i2u, r077D);
                                 body.emit(assign(r0747, add(r0747, r077E), 0x01));

                                 ir_expression *const r077F = equal(r0749, body.constant(0u));
                                 ir_expression *const r0780 = expr(ir_unop_b2i, r077F);
                                 ir_expression *const r0781 = expr(ir_unop_i2u, r0780);
                                 ir_expression *const r0782 = add(r0749, r0781);
                                 ir_expression *const r0783 = bit_and(r0782, body.constant(1u));
                                 ir_expression *const r0784 = expr(ir_unop_bit_not, r0783);
                                 body.emit(assign(r0748, bit_and(r077B, r0784), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f077A->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0786 = bit_or(r0747, r0748);
                                 ir_expression *const r0787 = equal(r0786, body.constant(0u));
                                 ir_if *f0785 = new(mem_ctx) ir_if(operand(r0787).val);
                                 exec_list *const f0785_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0785->then_instructions;

                                    body.emit(assign(r0746, body.constant(int(0)), 0x01));


                                 body.instructions = f0785_parent_instructions;
                                 body.emit(f0785);

                                 /* END IF */


                              body.instructions = f077A_parent_instructions;
                              body.emit(f077A);

                              /* END IF */

                              ir_variable *const r0788 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0788);
                              ir_expression *const r0789 = lshift(r01EC, body.constant(int(31)));
                              ir_expression *const r078A = expr(ir_unop_i2u, r0746);
                              ir_expression *const r078B = lshift(r078A, body.constant(int(20)));
                              ir_expression *const r078C = add(r0789, r078B);
                              body.emit(assign(r0788, add(r078C, r0747), 0x02));

                              body.emit(assign(r0788, r0748, 0x01));

                              body.emit(assign(r074B, r0788, 0x03));

                              body.emit(assign(r074A, body.constant(false), 0x01));


                           body.instructions = f0779_parent_instructions;
                           body.emit(f0779);

                           /* END IF */

                           body.emit(assign(r01EB, r074B, 0x03));

                           body.emit(assign(r01EA, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06FF->else_instructions;

                           ir_variable *const r078D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r078D);
                           body.emit(assign(r078D, body.constant(0u), 0x02));

                           body.emit(assign(r078D, body.constant(0u), 0x01));

                           body.emit(assign(r01EB, r078D, 0x03));

                           body.emit(assign(r01EA, body.constant(false), 0x01));


                        body.instructions = f06FF_parent_instructions;
                        body.emit(f06FF);

                        /* END IF */


                     body.instructions = f0671_parent_instructions;
                     body.emit(f0671);

                     /* END IF */


                  body.instructions = f05E3_parent_instructions;
                  body.emit(f05E3);

                  /* END IF */


               body.instructions = f0555_parent_instructions;
               body.emit(f0555);

               /* END IF */


            body.instructions = f0538_parent_instructions;
            body.emit(f0538);

            /* END IF */


         body.instructions = f0468_parent_instructions;
         body.emit(f0468);

         /* END IF */


      body.instructions = f039C_parent_instructions;
      body.emit(f039C);

      /* END IF */


   body.instructions = f01EF_parent_instructions;
   body.emit(f01EF);

   /* END IF */

   body.emit(ret(r01EB));

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

   ir_variable *const r078E = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r078E);
   ir_variable *const r078F = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r078F);
   ir_variable *const r0790 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0790);
   ir_variable *const r0791 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0791);
   ir_variable *const r0792 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0792);
   ir_variable *const r0793 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0793);
   ir_variable *const r0794 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0794);
   ir_variable *const r0795 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0795, bit_and(r078E, body.constant(65535u)), 0x01));

   ir_variable *const r0796 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0796, rshift(r078E, body.constant(int(16))), 0x01));

   ir_variable *const r0797 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0797, bit_and(r078F, body.constant(65535u)), 0x01));

   ir_variable *const r0798 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0798, rshift(r078F, body.constant(int(16))), 0x01));

   ir_variable *const r0799 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0799, mul(r0796, r0797), 0x01));

   ir_expression *const r079A = mul(r0795, r0798);
   body.emit(assign(r0793, add(r079A, r0799), 0x01));

   ir_expression *const r079B = mul(r0796, r0798);
   ir_expression *const r079C = less(r0793, r0799);
   ir_expression *const r079D = expr(ir_unop_b2i, r079C);
   ir_expression *const r079E = expr(ir_unop_i2u, r079D);
   ir_expression *const r079F = lshift(r079E, body.constant(int(16)));
   ir_expression *const r07A0 = rshift(r0793, body.constant(int(16)));
   ir_expression *const r07A1 = add(r079F, r07A0);
   body.emit(assign(r0792, add(r079B, r07A1), 0x01));

   body.emit(assign(r0793, lshift(r0793, body.constant(int(16))), 0x01));

   ir_expression *const r07A2 = mul(r0795, r0797);
   body.emit(assign(r0794, add(r07A2, r0793), 0x01));

   ir_expression *const r07A3 = less(r0794, r0793);
   ir_expression *const r07A4 = expr(ir_unop_b2i, r07A3);
   ir_expression *const r07A5 = expr(ir_unop_i2u, r07A4);
   body.emit(assign(r0792, add(r0792, r07A5), 0x01));

   body.emit(assign(r0791, r0794, 0x01));

   body.emit(assign(r0790, r0792, 0x01));

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

   ir_variable *const r07A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r07A6);
   ir_variable *const r07A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r07A7);
   ir_variable *const r07A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r07A8);
   ir_variable *const r07A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r07A9);
   ir_variable *const r07AA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07AA);
   ir_variable *const r07AB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07AB);
   ir_variable *const r07AC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07AC);
   ir_variable *const r07AD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07AD);
   ir_variable *const r07AE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07AE);
   ir_variable *const r07AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07AF);
   ir_variable *const r07B0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07B0);
   ir_variable *const r07B1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B1, bit_and(r07A7, body.constant(65535u)), 0x01));

   ir_variable *const r07B2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B2, rshift(r07A7, body.constant(int(16))), 0x01));

   ir_variable *const r07B3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B3, bit_and(r07A9, body.constant(65535u)), 0x01));

   ir_variable *const r07B4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B4, rshift(r07A9, body.constant(int(16))), 0x01));

   ir_variable *const r07B5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B5, mul(r07B2, r07B3), 0x01));

   ir_expression *const r07B6 = mul(r07B1, r07B4);
   body.emit(assign(r07AF, add(r07B6, r07B5), 0x01));

   ir_expression *const r07B7 = mul(r07B2, r07B4);
   ir_expression *const r07B8 = less(r07AF, r07B5);
   ir_expression *const r07B9 = expr(ir_unop_b2i, r07B8);
   ir_expression *const r07BA = expr(ir_unop_i2u, r07B9);
   ir_expression *const r07BB = lshift(r07BA, body.constant(int(16)));
   ir_expression *const r07BC = rshift(r07AF, body.constant(int(16)));
   ir_expression *const r07BD = add(r07BB, r07BC);
   body.emit(assign(r07AE, add(r07B7, r07BD), 0x01));

   body.emit(assign(r07AF, lshift(r07AF, body.constant(int(16))), 0x01));

   ir_expression *const r07BE = mul(r07B1, r07B3);
   body.emit(assign(r07B0, add(r07BE, r07AF), 0x01));

   ir_expression *const r07BF = less(r07B0, r07AF);
   ir_expression *const r07C0 = expr(ir_unop_b2i, r07BF);
   ir_expression *const r07C1 = expr(ir_unop_i2u, r07C0);
   body.emit(assign(r07AE, add(r07AE, r07C1), 0x01));

   ir_variable *const r07C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07C2);
   ir_variable *const r07C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07C3);
   ir_variable *const r07C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07C4);
   ir_variable *const r07C5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C5, bit_and(r07A7, body.constant(65535u)), 0x01));

   ir_variable *const r07C6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C6, rshift(r07A7, body.constant(int(16))), 0x01));

   ir_variable *const r07C7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C7, bit_and(r07A8, body.constant(65535u)), 0x01));

   ir_variable *const r07C8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C8, rshift(r07A8, body.constant(int(16))), 0x01));

   ir_variable *const r07C9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C9, mul(r07C6, r07C7), 0x01));

   ir_expression *const r07CA = mul(r07C5, r07C8);
   body.emit(assign(r07C3, add(r07CA, r07C9), 0x01));

   ir_expression *const r07CB = mul(r07C6, r07C8);
   ir_expression *const r07CC = less(r07C3, r07C9);
   ir_expression *const r07CD = expr(ir_unop_b2i, r07CC);
   ir_expression *const r07CE = expr(ir_unop_i2u, r07CD);
   ir_expression *const r07CF = lshift(r07CE, body.constant(int(16)));
   ir_expression *const r07D0 = rshift(r07C3, body.constant(int(16)));
   ir_expression *const r07D1 = add(r07CF, r07D0);
   body.emit(assign(r07C2, add(r07CB, r07D1), 0x01));

   body.emit(assign(r07C3, lshift(r07C3, body.constant(int(16))), 0x01));

   ir_expression *const r07D2 = mul(r07C5, r07C7);
   body.emit(assign(r07C4, add(r07D2, r07C3), 0x01));

   ir_expression *const r07D3 = less(r07C4, r07C3);
   ir_expression *const r07D4 = expr(ir_unop_b2i, r07D3);
   ir_expression *const r07D5 = expr(ir_unop_i2u, r07D4);
   body.emit(assign(r07C2, add(r07C2, r07D5), 0x01));

   ir_variable *const r07D6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D6, add(r07C4, r07AE), 0x01));

   ir_variable *const r07D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07D7);
   ir_variable *const r07D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07D8);
   ir_variable *const r07D9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07D9);
   ir_variable *const r07DA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DA, bit_and(r07A6, body.constant(65535u)), 0x01));

   ir_variable *const r07DB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DB, rshift(r07A6, body.constant(int(16))), 0x01));

   ir_variable *const r07DC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DC, bit_and(r07A8, body.constant(65535u)), 0x01));

   ir_variable *const r07DD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DD, rshift(r07A8, body.constant(int(16))), 0x01));

   ir_variable *const r07DE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DE, mul(r07DB, r07DC), 0x01));

   ir_expression *const r07DF = mul(r07DA, r07DD);
   body.emit(assign(r07D8, add(r07DF, r07DE), 0x01));

   ir_expression *const r07E0 = mul(r07DB, r07DD);
   ir_expression *const r07E1 = less(r07D8, r07DE);
   ir_expression *const r07E2 = expr(ir_unop_b2i, r07E1);
   ir_expression *const r07E3 = expr(ir_unop_i2u, r07E2);
   ir_expression *const r07E4 = lshift(r07E3, body.constant(int(16)));
   ir_expression *const r07E5 = rshift(r07D8, body.constant(int(16)));
   ir_expression *const r07E6 = add(r07E4, r07E5);
   body.emit(assign(r07D7, add(r07E0, r07E6), 0x01));

   body.emit(assign(r07D8, lshift(r07D8, body.constant(int(16))), 0x01));

   ir_expression *const r07E7 = mul(r07DA, r07DC);
   body.emit(assign(r07D9, add(r07E7, r07D8), 0x01));

   ir_expression *const r07E8 = less(r07D9, r07D8);
   ir_expression *const r07E9 = expr(ir_unop_b2i, r07E8);
   ir_expression *const r07EA = expr(ir_unop_i2u, r07E9);
   body.emit(assign(r07D7, add(r07D7, r07EA), 0x01));

   ir_variable *const r07EB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r07EC = less(r07D6, r07C4);
   ir_expression *const r07ED = expr(ir_unop_b2i, r07EC);
   ir_expression *const r07EE = expr(ir_unop_i2u, r07ED);
   ir_expression *const r07EF = add(r07C2, r07EE);
   body.emit(assign(r07EB, add(r07D9, r07EF), 0x01));

   ir_variable *const r07F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07F0);
   ir_variable *const r07F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07F1);
   ir_variable *const r07F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07F2);
   ir_variable *const r07F3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07F3, bit_and(r07A6, body.constant(65535u)), 0x01));

   ir_variable *const r07F4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07F4, rshift(r07A6, body.constant(int(16))), 0x01));

   ir_variable *const r07F5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07F5, bit_and(r07A9, body.constant(65535u)), 0x01));

   ir_variable *const r07F6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07F6, rshift(r07A9, body.constant(int(16))), 0x01));

   ir_variable *const r07F7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07F7, mul(r07F4, r07F5), 0x01));

   ir_expression *const r07F8 = mul(r07F3, r07F6);
   body.emit(assign(r07F1, add(r07F8, r07F7), 0x01));

   ir_expression *const r07F9 = mul(r07F4, r07F6);
   ir_expression *const r07FA = less(r07F1, r07F7);
   ir_expression *const r07FB = expr(ir_unop_b2i, r07FA);
   ir_expression *const r07FC = expr(ir_unop_i2u, r07FB);
   ir_expression *const r07FD = lshift(r07FC, body.constant(int(16)));
   ir_expression *const r07FE = rshift(r07F1, body.constant(int(16)));
   ir_expression *const r07FF = add(r07FD, r07FE);
   body.emit(assign(r07F0, add(r07F9, r07FF), 0x01));

   body.emit(assign(r07F1, lshift(r07F1, body.constant(int(16))), 0x01));

   ir_expression *const r0800 = mul(r07F3, r07F5);
   body.emit(assign(r07F2, add(r0800, r07F1), 0x01));

   ir_expression *const r0801 = less(r07F2, r07F1);
   ir_expression *const r0802 = expr(ir_unop_b2i, r0801);
   ir_expression *const r0803 = expr(ir_unop_i2u, r0802);
   body.emit(assign(r07F0, add(r07F0, r0803), 0x01));

   ir_variable *const r0804 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0804, add(r07F2, r07D6), 0x01));

   ir_variable *const r0805 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0806 = less(r0804, r07F2);
   ir_expression *const r0807 = expr(ir_unop_b2i, r0806);
   ir_expression *const r0808 = expr(ir_unop_i2u, r0807);
   ir_expression *const r0809 = add(r07F0, r0808);
   body.emit(assign(r0805, add(r07EB, r0809), 0x01));

   body.emit(assign(r07AD, r07B0, 0x01));

   body.emit(assign(r07AC, r0804, 0x01));

   body.emit(assign(r07AB, r0805, 0x01));

   ir_expression *const r080A = less(r07EB, r07D9);
   ir_expression *const r080B = expr(ir_unop_b2i, r080A);
   ir_expression *const r080C = expr(ir_unop_i2u, r080B);
   ir_expression *const r080D = add(r07D7, r080C);
   ir_expression *const r080E = less(r0805, r07EB);
   ir_expression *const r080F = expr(ir_unop_b2i, r080E);
   ir_expression *const r0810 = expr(ir_unop_i2u, r080F);
   body.emit(assign(r07AA, add(r080D, r0810), 0x01));

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

   ir_variable *const r0811 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0811);
   ir_variable *const r0812 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0812);
   ir_variable *const r0813 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r0813);
   ir_variable *const r0814 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0814);
   ir_variable *const r0815 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0815);
   ir_variable *const r0816 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0816);
   /* IF CONDITION */
   ir_expression *const r0818 = equal(r0811, body.constant(0u));
   ir_if *f0817 = new(mem_ctx) ir_if(operand(r0818).val);
   exec_list *const f0817_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0817->then_instructions;

      ir_variable *const r0819 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0819, r0812, 0x01));

      ir_variable *const r081A = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r081B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r081B);
      /* IF CONDITION */
      ir_expression *const r081D = equal(r0812, body.constant(0u));
      ir_if *f081C = new(mem_ctx) ir_if(operand(r081D).val);
      exec_list *const f081C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f081C->then_instructions;

         body.emit(assign(r081A, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f081C->else_instructions;

         body.emit(assign(r081B, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r081F = bit_and(r0812, body.constant(4294901760u));
         ir_expression *const r0820 = equal(r081F, body.constant(0u));
         ir_if *f081E = new(mem_ctx) ir_if(operand(r0820).val);
         exec_list *const f081E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f081E->then_instructions;

            body.emit(assign(r081B, body.constant(int(16)), 0x01));

            body.emit(assign(r0819, lshift(r0812, body.constant(int(16))), 0x01));


         body.instructions = f081E_parent_instructions;
         body.emit(f081E);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0822 = bit_and(r0819, body.constant(4278190080u));
         ir_expression *const r0823 = equal(r0822, body.constant(0u));
         ir_if *f0821 = new(mem_ctx) ir_if(operand(r0823).val);
         exec_list *const f0821_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0821->then_instructions;

            body.emit(assign(r081B, add(r081B, body.constant(int(8))), 0x01));

            body.emit(assign(r0819, lshift(r0819, body.constant(int(8))), 0x01));


         body.instructions = f0821_parent_instructions;
         body.emit(f0821);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0825 = bit_and(r0819, body.constant(4026531840u));
         ir_expression *const r0826 = equal(r0825, body.constant(0u));
         ir_if *f0824 = new(mem_ctx) ir_if(operand(r0826).val);
         exec_list *const f0824_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0824->then_instructions;

            body.emit(assign(r081B, add(r081B, body.constant(int(4))), 0x01));

            body.emit(assign(r0819, lshift(r0819, body.constant(int(4))), 0x01));


         body.instructions = f0824_parent_instructions;
         body.emit(f0824);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0828 = bit_and(r0819, body.constant(3221225472u));
         ir_expression *const r0829 = equal(r0828, body.constant(0u));
         ir_if *f0827 = new(mem_ctx) ir_if(operand(r0829).val);
         exec_list *const f0827_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0827->then_instructions;

            body.emit(assign(r081B, add(r081B, body.constant(int(2))), 0x01));

            body.emit(assign(r0819, lshift(r0819, body.constant(int(2))), 0x01));


         body.instructions = f0827_parent_instructions;
         body.emit(f0827);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r082B = bit_and(r0819, body.constant(2147483648u));
         ir_expression *const r082C = equal(r082B, body.constant(0u));
         ir_if *f082A = new(mem_ctx) ir_if(operand(r082C).val);
         exec_list *const f082A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f082A->then_instructions;

            body.emit(assign(r081B, add(r081B, body.constant(int(1))), 0x01));


         body.instructions = f082A_parent_instructions;
         body.emit(f082A);

         /* END IF */

         body.emit(assign(r081A, r081B, 0x01));


      body.instructions = f081C_parent_instructions;
      body.emit(f081C);

      /* END IF */

      body.emit(assign(r0816, add(r081A, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r082E = less(r0816, body.constant(int(0)));
      ir_if *f082D = new(mem_ctx) ir_if(operand(r082E).val);
      exec_list *const f082D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f082D->then_instructions;

         ir_expression *const r082F = neg(r0816);
         body.emit(assign(r0814, rshift(r0812, r082F), 0x01));

         ir_expression *const r0830 = bit_and(r0816, body.constant(int(31)));
         body.emit(assign(r0815, lshift(r0812, r0830), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f082D->else_instructions;

         body.emit(assign(r0814, lshift(r0812, r0816), 0x01));

         body.emit(assign(r0815, body.constant(0u), 0x01));


      body.instructions = f082D_parent_instructions;
      body.emit(f082D);

      /* END IF */

      body.emit(assign(r0813, sub(body.constant(int(-31)), r0816), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0817->else_instructions;

      ir_variable *const r0831 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0831, r0811, 0x01));

      ir_variable *const r0832 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0833 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0833);
      /* IF CONDITION */
      ir_expression *const r0835 = equal(r0811, body.constant(0u));
      ir_if *f0834 = new(mem_ctx) ir_if(operand(r0835).val);
      exec_list *const f0834_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0834->then_instructions;

         body.emit(assign(r0832, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0834->else_instructions;

         body.emit(assign(r0833, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0837 = bit_and(r0811, body.constant(4294901760u));
         ir_expression *const r0838 = equal(r0837, body.constant(0u));
         ir_if *f0836 = new(mem_ctx) ir_if(operand(r0838).val);
         exec_list *const f0836_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0836->then_instructions;

            body.emit(assign(r0833, body.constant(int(16)), 0x01));

            body.emit(assign(r0831, lshift(r0811, body.constant(int(16))), 0x01));


         body.instructions = f0836_parent_instructions;
         body.emit(f0836);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r083A = bit_and(r0831, body.constant(4278190080u));
         ir_expression *const r083B = equal(r083A, body.constant(0u));
         ir_if *f0839 = new(mem_ctx) ir_if(operand(r083B).val);
         exec_list *const f0839_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0839->then_instructions;

            body.emit(assign(r0833, add(r0833, body.constant(int(8))), 0x01));

            body.emit(assign(r0831, lshift(r0831, body.constant(int(8))), 0x01));


         body.instructions = f0839_parent_instructions;
         body.emit(f0839);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r083D = bit_and(r0831, body.constant(4026531840u));
         ir_expression *const r083E = equal(r083D, body.constant(0u));
         ir_if *f083C = new(mem_ctx) ir_if(operand(r083E).val);
         exec_list *const f083C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f083C->then_instructions;

            body.emit(assign(r0833, add(r0833, body.constant(int(4))), 0x01));

            body.emit(assign(r0831, lshift(r0831, body.constant(int(4))), 0x01));


         body.instructions = f083C_parent_instructions;
         body.emit(f083C);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0840 = bit_and(r0831, body.constant(3221225472u));
         ir_expression *const r0841 = equal(r0840, body.constant(0u));
         ir_if *f083F = new(mem_ctx) ir_if(operand(r0841).val);
         exec_list *const f083F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f083F->then_instructions;

            body.emit(assign(r0833, add(r0833, body.constant(int(2))), 0x01));

            body.emit(assign(r0831, lshift(r0831, body.constant(int(2))), 0x01));


         body.instructions = f083F_parent_instructions;
         body.emit(f083F);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0843 = bit_and(r0831, body.constant(2147483648u));
         ir_expression *const r0844 = equal(r0843, body.constant(0u));
         ir_if *f0842 = new(mem_ctx) ir_if(operand(r0844).val);
         exec_list *const f0842_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0842->then_instructions;

            body.emit(assign(r0833, add(r0833, body.constant(int(1))), 0x01));


         body.instructions = f0842_parent_instructions;
         body.emit(f0842);

         /* END IF */

         body.emit(assign(r0832, r0833, 0x01));


      body.instructions = f0834_parent_instructions;
      body.emit(f0834);

      /* END IF */

      body.emit(assign(r0816, add(r0832, body.constant(int(-11))), 0x01));

      ir_expression *const r0845 = equal(r0816, body.constant(int(0)));
      ir_expression *const r0846 = lshift(r0811, r0816);
      ir_expression *const r0847 = neg(r0816);
      ir_expression *const r0848 = bit_and(r0847, body.constant(int(31)));
      ir_expression *const r0849 = rshift(r0812, r0848);
      ir_expression *const r084A = bit_or(r0846, r0849);
      body.emit(assign(r0814, expr(ir_triop_csel, r0845, r0811, r084A), 0x01));

      body.emit(assign(r0815, lshift(r0812, r0816), 0x01));

      body.emit(assign(r0813, sub(body.constant(int(1)), r0816), 0x01));


   body.instructions = f0817_parent_instructions;
   body.emit(f0817);

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

   ir_variable *const r084B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r084B);
   ir_variable *const r084C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r084C);
   ir_variable *const r084D = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r084D, body.constant(true), 0x01));

   ir_variable *const r084E = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r084F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r084F);
   ir_variable *const r0850 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r0850);
   ir_variable *const r0851 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0851);
   ir_variable *const r0852 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r0852);
   ir_variable *const r0853 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r0853);
   ir_variable *const r0854 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0854);
   ir_variable *const r0855 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0855);
   ir_variable *const r0856 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r0856);
   ir_variable *const r0857 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0857);
   ir_variable *const r0858 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0858);
   ir_variable *const r0859 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0859);
   body.emit(assign(r0859, body.constant(0u), 0x01));

   body.emit(assign(r0858, body.constant(0u), 0x01));

   body.emit(assign(r0857, body.constant(0u), 0x01));

   ir_variable *const r085A = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r085A, swizzle_x(r084B), 0x01));

   body.emit(assign(r0855, r085A, 0x01));

   ir_variable *const r085B = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r085B, bit_and(swizzle_y(r084B), body.constant(1048575u)), 0x01));

   body.emit(assign(r0854, r085B, 0x01));

   ir_variable *const r085C = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r085C, swizzle_x(r084C), 0x01));

   body.emit(assign(r0853, r085C, 0x01));

   ir_variable *const r085D = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r085D, bit_and(swizzle_y(r084C), body.constant(1048575u)), 0x01));

   body.emit(assign(r0852, r085D, 0x01));

   ir_variable *const r085E = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r085F = rshift(swizzle_y(r084B), body.constant(int(20)));
   ir_expression *const r0860 = bit_and(r085F, body.constant(2047u));
   body.emit(assign(r085E, expr(ir_unop_u2i, r0860), 0x01));

   body.emit(assign(r0851, r085E, 0x01));

   ir_variable *const r0861 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0862 = rshift(swizzle_y(r084C), body.constant(int(20)));
   ir_expression *const r0863 = bit_and(r0862, body.constant(2047u));
   body.emit(assign(r0861, expr(ir_unop_u2i, r0863), 0x01));

   body.emit(assign(r0850, r0861, 0x01));

   ir_expression *const r0864 = rshift(swizzle_y(r084B), body.constant(int(31)));
   ir_expression *const r0865 = rshift(swizzle_y(r084C), body.constant(int(31)));
   body.emit(assign(r084F, bit_xor(r0864, r0865), 0x01));

   /* IF CONDITION */
   ir_expression *const r0867 = equal(r085E, body.constant(int(2047)));
   ir_if *f0866 = new(mem_ctx) ir_if(operand(r0867).val);
   exec_list *const f0866_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0866->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0869 = bit_or(r085B, swizzle_x(r084B));
      ir_expression *const r086A = nequal(r0869, body.constant(0u));
      ir_expression *const r086B = equal(r0861, body.constant(int(2047)));
      ir_expression *const r086C = bit_or(r085D, swizzle_x(r084C));
      ir_expression *const r086D = nequal(r086C, body.constant(0u));
      ir_expression *const r086E = logic_and(r086B, r086D);
      ir_expression *const r086F = logic_or(r086A, r086E);
      ir_if *f0868 = new(mem_ctx) ir_if(operand(r086F).val);
      exec_list *const f0868_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0868->then_instructions;

         ir_variable *const r0870 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r0870, swizzle_x(r084B), 0x01));

         ir_variable *const r0871 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r0871, swizzle_x(r084C), 0x01));

         body.emit(assign(r0870, bit_or(swizzle_y(r084B), body.constant(524288u)), 0x02));

         body.emit(assign(r0871, bit_or(swizzle_y(r084C), body.constant(524288u)), 0x02));

         ir_expression *const r0872 = lshift(swizzle_y(r084B), body.constant(int(1)));
         ir_expression *const r0873 = gequal(r0872, body.constant(4292870144u));
         ir_expression *const r0874 = nequal(swizzle_x(r084B), body.constant(0u));
         ir_expression *const r0875 = bit_and(swizzle_y(r084B), body.constant(1048575u));
         ir_expression *const r0876 = nequal(r0875, body.constant(0u));
         ir_expression *const r0877 = logic_or(r0874, r0876);
         ir_expression *const r0878 = logic_and(r0873, r0877);
         ir_swizzle *const r0879 = swizzle(r0878, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r087A = lshift(swizzle_y(r084C), body.constant(int(1)));
         ir_expression *const r087B = gequal(r087A, body.constant(4292870144u));
         ir_expression *const r087C = nequal(swizzle_x(r084C), body.constant(0u));
         ir_expression *const r087D = bit_and(swizzle_y(r084C), body.constant(1048575u));
         ir_expression *const r087E = nequal(r087D, body.constant(0u));
         ir_expression *const r087F = logic_or(r087C, r087E);
         ir_expression *const r0880 = logic_and(r087B, r087F);
         ir_swizzle *const r0881 = swizzle(r0880, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r0882 = expr(ir_triop_csel, r0881, r0871, r0870);
         body.emit(assign(r084E, expr(ir_triop_csel, r0879, r0882, r0871), 0x03));

         body.emit(assign(r084D, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0868->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0884 = expr(ir_unop_i2u, r0861);
         ir_expression *const r0885 = bit_or(r0884, r085D);
         ir_expression *const r0886 = bit_or(r0885, swizzle_x(r084C));
         ir_expression *const r0887 = equal(r0886, body.constant(0u));
         ir_if *f0883 = new(mem_ctx) ir_if(operand(r0887).val);
         exec_list *const f0883_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0883->then_instructions;

            ir_constant_data r0888_data;
            memset(&r0888_data, 0, sizeof(ir_constant_data));
            r0888_data.u[0] = 4294967295;
            r0888_data.u[1] = 4294967295;
            ir_constant *const r0888 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0888_data);
            body.emit(assign(r084E, r0888, 0x03));

            body.emit(assign(r084D, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0883->else_instructions;

            ir_variable *const r0889 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0889);
            ir_expression *const r088A = lshift(r084F, body.constant(int(31)));
            body.emit(assign(r0889, add(r088A, body.constant(2146435072u)), 0x02));

            body.emit(assign(r0889, body.constant(0u), 0x01));

            body.emit(assign(r084E, r0889, 0x03));

            body.emit(assign(r084D, body.constant(false), 0x01));


         body.instructions = f0883_parent_instructions;
         body.emit(f0883);

         /* END IF */


      body.instructions = f0868_parent_instructions;
      body.emit(f0868);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0866->else_instructions;

      /* IF CONDITION */
      ir_expression *const r088C = equal(r0861, body.constant(int(2047)));
      ir_if *f088B = new(mem_ctx) ir_if(operand(r088C).val);
      exec_list *const f088B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f088B->then_instructions;

         /* IF CONDITION */
         ir_expression *const r088E = bit_or(r085D, swizzle_x(r084C));
         ir_expression *const r088F = nequal(r088E, body.constant(0u));
         ir_if *f088D = new(mem_ctx) ir_if(operand(r088F).val);
         exec_list *const f088D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f088D->then_instructions;

            ir_variable *const r0890 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0890, swizzle_x(r084B), 0x01));

            ir_variable *const r0891 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0891, swizzle_x(r084C), 0x01));

            body.emit(assign(r0890, bit_or(swizzle_y(r084B), body.constant(524288u)), 0x02));

            body.emit(assign(r0891, bit_or(swizzle_y(r084C), body.constant(524288u)), 0x02));

            ir_expression *const r0892 = lshift(swizzle_y(r084B), body.constant(int(1)));
            ir_expression *const r0893 = gequal(r0892, body.constant(4292870144u));
            ir_expression *const r0894 = nequal(swizzle_x(r084B), body.constant(0u));
            ir_expression *const r0895 = bit_and(swizzle_y(r084B), body.constant(1048575u));
            ir_expression *const r0896 = nequal(r0895, body.constant(0u));
            ir_expression *const r0897 = logic_or(r0894, r0896);
            ir_expression *const r0898 = logic_and(r0893, r0897);
            ir_swizzle *const r0899 = swizzle(r0898, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r089A = lshift(swizzle_y(r084C), body.constant(int(1)));
            ir_expression *const r089B = gequal(r089A, body.constant(4292870144u));
            ir_expression *const r089C = nequal(swizzle_x(r084C), body.constant(0u));
            ir_expression *const r089D = bit_and(swizzle_y(r084C), body.constant(1048575u));
            ir_expression *const r089E = nequal(r089D, body.constant(0u));
            ir_expression *const r089F = logic_or(r089C, r089E);
            ir_expression *const r08A0 = logic_and(r089B, r089F);
            ir_swizzle *const r08A1 = swizzle(r08A0, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r08A2 = expr(ir_triop_csel, r08A1, r0891, r0890);
            body.emit(assign(r084E, expr(ir_triop_csel, r0899, r08A2, r0891), 0x03));

            body.emit(assign(r084D, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f088D->else_instructions;

            /* IF CONDITION */
            ir_expression *const r08A4 = expr(ir_unop_i2u, r085E);
            ir_expression *const r08A5 = bit_or(r08A4, r085B);
            ir_expression *const r08A6 = bit_or(r08A5, swizzle_x(r084B));
            ir_expression *const r08A7 = equal(r08A6, body.constant(0u));
            ir_if *f08A3 = new(mem_ctx) ir_if(operand(r08A7).val);
            exec_list *const f08A3_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08A3->then_instructions;

               ir_constant_data r08A8_data;
               memset(&r08A8_data, 0, sizeof(ir_constant_data));
               r08A8_data.u[0] = 4294967295;
               r08A8_data.u[1] = 4294967295;
               ir_constant *const r08A8 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r08A8_data);
               body.emit(assign(r084E, r08A8, 0x03));

               body.emit(assign(r084D, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08A3->else_instructions;

               ir_variable *const r08A9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r08A9);
               ir_expression *const r08AA = lshift(r084F, body.constant(int(31)));
               body.emit(assign(r08A9, add(r08AA, body.constant(2146435072u)), 0x02));

               body.emit(assign(r08A9, body.constant(0u), 0x01));

               body.emit(assign(r084E, r08A9, 0x03));

               body.emit(assign(r084D, body.constant(false), 0x01));


            body.instructions = f08A3_parent_instructions;
            body.emit(f08A3);

            /* END IF */


         body.instructions = f088D_parent_instructions;
         body.emit(f088D);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f088B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r08AC = equal(r085E, body.constant(int(0)));
         ir_if *f08AB = new(mem_ctx) ir_if(operand(r08AC).val);
         exec_list *const f08AB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08AB->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08AE = bit_or(r085B, swizzle_x(r084B));
            ir_expression *const r08AF = equal(r08AE, body.constant(0u));
            ir_if *f08AD = new(mem_ctx) ir_if(operand(r08AF).val);
            exec_list *const f08AD_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08AD->then_instructions;

               ir_variable *const r08B0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r08B0);
               body.emit(assign(r08B0, lshift(r084F, body.constant(int(31))), 0x02));

               body.emit(assign(r08B0, body.constant(0u), 0x01));

               body.emit(assign(r084E, r08B0, 0x03));

               body.emit(assign(r084D, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08AD->else_instructions;

               ir_variable *const r08B1 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r08B1, r085E, 0x01));

               ir_variable *const r08B2 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r08B2, r085B, 0x01));

               ir_variable *const r08B3 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r08B3, r085A, 0x01));

               ir_variable *const r08B4 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r08B4);
               /* IF CONDITION */
               ir_expression *const r08B6 = equal(r085B, body.constant(0u));
               ir_if *f08B5 = new(mem_ctx) ir_if(operand(r08B6).val);
               exec_list *const f08B5_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08B5->then_instructions;

                  ir_variable *const r08B7 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r08B7, r085A, 0x01));

                  ir_variable *const r08B8 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r08B9 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08B9);
                  /* IF CONDITION */
                  ir_expression *const r08BB = equal(swizzle_x(r084B), body.constant(0u));
                  ir_if *f08BA = new(mem_ctx) ir_if(operand(r08BB).val);
                  exec_list *const f08BA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08BA->then_instructions;

                     body.emit(assign(r08B8, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08BA->else_instructions;

                     body.emit(assign(r08B9, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08BD = bit_and(swizzle_x(r084B), body.constant(4294901760u));
                     ir_expression *const r08BE = equal(r08BD, body.constant(0u));
                     ir_if *f08BC = new(mem_ctx) ir_if(operand(r08BE).val);
                     exec_list *const f08BC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08BC->then_instructions;

                        body.emit(assign(r08B9, body.constant(int(16)), 0x01));

                        body.emit(assign(r08B7, lshift(swizzle_x(r084B), body.constant(int(16))), 0x01));


                     body.instructions = f08BC_parent_instructions;
                     body.emit(f08BC);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08C0 = bit_and(r08B7, body.constant(4278190080u));
                     ir_expression *const r08C1 = equal(r08C0, body.constant(0u));
                     ir_if *f08BF = new(mem_ctx) ir_if(operand(r08C1).val);
                     exec_list *const f08BF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08BF->then_instructions;

                        body.emit(assign(r08B9, add(r08B9, body.constant(int(8))), 0x01));

                        body.emit(assign(r08B7, lshift(r08B7, body.constant(int(8))), 0x01));


                     body.instructions = f08BF_parent_instructions;
                     body.emit(f08BF);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08C3 = bit_and(r08B7, body.constant(4026531840u));
                     ir_expression *const r08C4 = equal(r08C3, body.constant(0u));
                     ir_if *f08C2 = new(mem_ctx) ir_if(operand(r08C4).val);
                     exec_list *const f08C2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08C2->then_instructions;

                        body.emit(assign(r08B9, add(r08B9, body.constant(int(4))), 0x01));

                        body.emit(assign(r08B7, lshift(r08B7, body.constant(int(4))), 0x01));


                     body.instructions = f08C2_parent_instructions;
                     body.emit(f08C2);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08C6 = bit_and(r08B7, body.constant(3221225472u));
                     ir_expression *const r08C7 = equal(r08C6, body.constant(0u));
                     ir_if *f08C5 = new(mem_ctx) ir_if(operand(r08C7).val);
                     exec_list *const f08C5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08C5->then_instructions;

                        body.emit(assign(r08B9, add(r08B9, body.constant(int(2))), 0x01));

                        body.emit(assign(r08B7, lshift(r08B7, body.constant(int(2))), 0x01));


                     body.instructions = f08C5_parent_instructions;
                     body.emit(f08C5);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08C9 = bit_and(r08B7, body.constant(2147483648u));
                     ir_expression *const r08CA = equal(r08C9, body.constant(0u));
                     ir_if *f08C8 = new(mem_ctx) ir_if(operand(r08CA).val);
                     exec_list *const f08C8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08C8->then_instructions;

                        body.emit(assign(r08B9, add(r08B9, body.constant(int(1))), 0x01));


                     body.instructions = f08C8_parent_instructions;
                     body.emit(f08C8);

                     /* END IF */

                     body.emit(assign(r08B8, r08B9, 0x01));


                  body.instructions = f08BA_parent_instructions;
                  body.emit(f08BA);

                  /* END IF */

                  body.emit(assign(r08B4, add(r08B8, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r08CC = less(r08B4, body.constant(int(0)));
                  ir_if *f08CB = new(mem_ctx) ir_if(operand(r08CC).val);
                  exec_list *const f08CB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08CB->then_instructions;

                     ir_expression *const r08CD = neg(r08B4);
                     body.emit(assign(r08B2, rshift(swizzle_x(r084B), r08CD), 0x01));

                     ir_expression *const r08CE = bit_and(r08B4, body.constant(int(31)));
                     body.emit(assign(r08B3, lshift(swizzle_x(r084B), r08CE), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08CB->else_instructions;

                     body.emit(assign(r08B2, lshift(swizzle_x(r084B), r08B4), 0x01));

                     body.emit(assign(r08B3, body.constant(0u), 0x01));


                  body.instructions = f08CB_parent_instructions;
                  body.emit(f08CB);

                  /* END IF */

                  body.emit(assign(r08B1, sub(body.constant(int(-31)), r08B4), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08B5->else_instructions;

                  ir_variable *const r08CF = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r08CF, r085B, 0x01));

                  ir_variable *const r08D0 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r08D1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08D1);
                  /* IF CONDITION */
                  ir_expression *const r08D3 = equal(r085B, body.constant(0u));
                  ir_if *f08D2 = new(mem_ctx) ir_if(operand(r08D3).val);
                  exec_list *const f08D2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08D2->then_instructions;

                     body.emit(assign(r08D0, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08D2->else_instructions;

                     body.emit(assign(r08D1, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08D5 = bit_and(r085B, body.constant(4294901760u));
                     ir_expression *const r08D6 = equal(r08D5, body.constant(0u));
                     ir_if *f08D4 = new(mem_ctx) ir_if(operand(r08D6).val);
                     exec_list *const f08D4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08D4->then_instructions;

                        body.emit(assign(r08D1, body.constant(int(16)), 0x01));

                        body.emit(assign(r08CF, lshift(r085B, body.constant(int(16))), 0x01));


                     body.instructions = f08D4_parent_instructions;
                     body.emit(f08D4);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08D8 = bit_and(r08CF, body.constant(4278190080u));
                     ir_expression *const r08D9 = equal(r08D8, body.constant(0u));
                     ir_if *f08D7 = new(mem_ctx) ir_if(operand(r08D9).val);
                     exec_list *const f08D7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08D7->then_instructions;

                        body.emit(assign(r08D1, add(r08D1, body.constant(int(8))), 0x01));

                        body.emit(assign(r08CF, lshift(r08CF, body.constant(int(8))), 0x01));


                     body.instructions = f08D7_parent_instructions;
                     body.emit(f08D7);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08DB = bit_and(r08CF, body.constant(4026531840u));
                     ir_expression *const r08DC = equal(r08DB, body.constant(0u));
                     ir_if *f08DA = new(mem_ctx) ir_if(operand(r08DC).val);
                     exec_list *const f08DA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08DA->then_instructions;

                        body.emit(assign(r08D1, add(r08D1, body.constant(int(4))), 0x01));

                        body.emit(assign(r08CF, lshift(r08CF, body.constant(int(4))), 0x01));


                     body.instructions = f08DA_parent_instructions;
                     body.emit(f08DA);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08DE = bit_and(r08CF, body.constant(3221225472u));
                     ir_expression *const r08DF = equal(r08DE, body.constant(0u));
                     ir_if *f08DD = new(mem_ctx) ir_if(operand(r08DF).val);
                     exec_list *const f08DD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08DD->then_instructions;

                        body.emit(assign(r08D1, add(r08D1, body.constant(int(2))), 0x01));

                        body.emit(assign(r08CF, lshift(r08CF, body.constant(int(2))), 0x01));


                     body.instructions = f08DD_parent_instructions;
                     body.emit(f08DD);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08E1 = bit_and(r08CF, body.constant(2147483648u));
                     ir_expression *const r08E2 = equal(r08E1, body.constant(0u));
                     ir_if *f08E0 = new(mem_ctx) ir_if(operand(r08E2).val);
                     exec_list *const f08E0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08E0->then_instructions;

                        body.emit(assign(r08D1, add(r08D1, body.constant(int(1))), 0x01));


                     body.instructions = f08E0_parent_instructions;
                     body.emit(f08E0);

                     /* END IF */

                     body.emit(assign(r08D0, r08D1, 0x01));


                  body.instructions = f08D2_parent_instructions;
                  body.emit(f08D2);

                  /* END IF */

                  body.emit(assign(r08B4, add(r08D0, body.constant(int(-11))), 0x01));

                  ir_expression *const r08E3 = equal(r08B4, body.constant(int(0)));
                  ir_expression *const r08E4 = lshift(r085B, r08B4);
                  ir_expression *const r08E5 = neg(r08B4);
                  ir_expression *const r08E6 = bit_and(r08E5, body.constant(int(31)));
                  ir_expression *const r08E7 = rshift(swizzle_x(r084B), r08E6);
                  ir_expression *const r08E8 = bit_or(r08E4, r08E7);
                  body.emit(assign(r08B2, expr(ir_triop_csel, r08E3, r085B, r08E8), 0x01));

                  body.emit(assign(r08B3, lshift(swizzle_x(r084B), r08B4), 0x01));

                  body.emit(assign(r08B1, sub(body.constant(int(1)), r08B4), 0x01));


               body.instructions = f08B5_parent_instructions;
               body.emit(f08B5);

               /* END IF */

               body.emit(assign(r0851, r08B1, 0x01));

               body.emit(assign(r0854, r08B2, 0x01));

               body.emit(assign(r0855, r08B3, 0x01));


            body.instructions = f08AD_parent_instructions;
            body.emit(f08AD);

            /* END IF */


         body.instructions = f08AB_parent_instructions;
         body.emit(f08AB);

         /* END IF */

         /* IF CONDITION */
         ir_if *f08E9 = new(mem_ctx) ir_if(operand(r084D).val);
         exec_list *const f08E9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08E9->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08EB = equal(r0861, body.constant(int(0)));
            ir_if *f08EA = new(mem_ctx) ir_if(operand(r08EB).val);
            exec_list *const f08EA_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08EA->then_instructions;

               /* IF CONDITION */
               ir_expression *const r08ED = bit_or(r085D, swizzle_x(r084C));
               ir_expression *const r08EE = equal(r08ED, body.constant(0u));
               ir_if *f08EC = new(mem_ctx) ir_if(operand(r08EE).val);
               exec_list *const f08EC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08EC->then_instructions;

                  ir_variable *const r08EF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r08EF);
                  body.emit(assign(r08EF, lshift(r084F, body.constant(int(31))), 0x02));

                  body.emit(assign(r08EF, body.constant(0u), 0x01));

                  body.emit(assign(r084E, r08EF, 0x03));

                  body.emit(assign(r084D, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08EC->else_instructions;

                  ir_variable *const r08F0 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r08F0, r0861, 0x01));

                  ir_variable *const r08F1 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r08F1, r085D, 0x01));

                  ir_variable *const r08F2 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r08F2, r085C, 0x01));

                  ir_variable *const r08F3 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08F3);
                  /* IF CONDITION */
                  ir_expression *const r08F5 = equal(r085D, body.constant(0u));
                  ir_if *f08F4 = new(mem_ctx) ir_if(operand(r08F5).val);
                  exec_list *const f08F4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08F4->then_instructions;

                     ir_variable *const r08F6 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r08F6, r085C, 0x01));

                     ir_variable *const r08F7 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r08F8 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r08F8);
                     /* IF CONDITION */
                     ir_expression *const r08FA = equal(swizzle_x(r084C), body.constant(0u));
                     ir_if *f08F9 = new(mem_ctx) ir_if(operand(r08FA).val);
                     exec_list *const f08F9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F9->then_instructions;

                        body.emit(assign(r08F7, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08F9->else_instructions;

                        body.emit(assign(r08F8, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08FC = bit_and(swizzle_x(r084C), body.constant(4294901760u));
                        ir_expression *const r08FD = equal(r08FC, body.constant(0u));
                        ir_if *f08FB = new(mem_ctx) ir_if(operand(r08FD).val);
                        exec_list *const f08FB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08FB->then_instructions;

                           body.emit(assign(r08F8, body.constant(int(16)), 0x01));

                           body.emit(assign(r08F6, lshift(swizzle_x(r084C), body.constant(int(16))), 0x01));


                        body.instructions = f08FB_parent_instructions;
                        body.emit(f08FB);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08FF = bit_and(r08F6, body.constant(4278190080u));
                        ir_expression *const r0900 = equal(r08FF, body.constant(0u));
                        ir_if *f08FE = new(mem_ctx) ir_if(operand(r0900).val);
                        exec_list *const f08FE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08FE->then_instructions;

                           body.emit(assign(r08F8, add(r08F8, body.constant(int(8))), 0x01));

                           body.emit(assign(r08F6, lshift(r08F6, body.constant(int(8))), 0x01));


                        body.instructions = f08FE_parent_instructions;
                        body.emit(f08FE);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0902 = bit_and(r08F6, body.constant(4026531840u));
                        ir_expression *const r0903 = equal(r0902, body.constant(0u));
                        ir_if *f0901 = new(mem_ctx) ir_if(operand(r0903).val);
                        exec_list *const f0901_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0901->then_instructions;

                           body.emit(assign(r08F8, add(r08F8, body.constant(int(4))), 0x01));

                           body.emit(assign(r08F6, lshift(r08F6, body.constant(int(4))), 0x01));


                        body.instructions = f0901_parent_instructions;
                        body.emit(f0901);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0905 = bit_and(r08F6, body.constant(3221225472u));
                        ir_expression *const r0906 = equal(r0905, body.constant(0u));
                        ir_if *f0904 = new(mem_ctx) ir_if(operand(r0906).val);
                        exec_list *const f0904_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0904->then_instructions;

                           body.emit(assign(r08F8, add(r08F8, body.constant(int(2))), 0x01));

                           body.emit(assign(r08F6, lshift(r08F6, body.constant(int(2))), 0x01));


                        body.instructions = f0904_parent_instructions;
                        body.emit(f0904);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0908 = bit_and(r08F6, body.constant(2147483648u));
                        ir_expression *const r0909 = equal(r0908, body.constant(0u));
                        ir_if *f0907 = new(mem_ctx) ir_if(operand(r0909).val);
                        exec_list *const f0907_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0907->then_instructions;

                           body.emit(assign(r08F8, add(r08F8, body.constant(int(1))), 0x01));


                        body.instructions = f0907_parent_instructions;
                        body.emit(f0907);

                        /* END IF */

                        body.emit(assign(r08F7, r08F8, 0x01));


                     body.instructions = f08F9_parent_instructions;
                     body.emit(f08F9);

                     /* END IF */

                     body.emit(assign(r08F3, add(r08F7, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r090B = less(r08F3, body.constant(int(0)));
                     ir_if *f090A = new(mem_ctx) ir_if(operand(r090B).val);
                     exec_list *const f090A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f090A->then_instructions;

                        ir_expression *const r090C = neg(r08F3);
                        body.emit(assign(r08F1, rshift(swizzle_x(r084C), r090C), 0x01));

                        ir_expression *const r090D = bit_and(r08F3, body.constant(int(31)));
                        body.emit(assign(r08F2, lshift(swizzle_x(r084C), r090D), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f090A->else_instructions;

                        body.emit(assign(r08F1, lshift(swizzle_x(r084C), r08F3), 0x01));

                        body.emit(assign(r08F2, body.constant(0u), 0x01));


                     body.instructions = f090A_parent_instructions;
                     body.emit(f090A);

                     /* END IF */

                     body.emit(assign(r08F0, sub(body.constant(int(-31)), r08F3), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08F4->else_instructions;

                     ir_variable *const r090E = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r090E, r085D, 0x01));

                     ir_variable *const r090F = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r0910 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0910);
                     /* IF CONDITION */
                     ir_expression *const r0912 = equal(r085D, body.constant(0u));
                     ir_if *f0911 = new(mem_ctx) ir_if(operand(r0912).val);
                     exec_list *const f0911_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0911->then_instructions;

                        body.emit(assign(r090F, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0911->else_instructions;

                        body.emit(assign(r0910, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0914 = bit_and(r085D, body.constant(4294901760u));
                        ir_expression *const r0915 = equal(r0914, body.constant(0u));
                        ir_if *f0913 = new(mem_ctx) ir_if(operand(r0915).val);
                        exec_list *const f0913_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0913->then_instructions;

                           body.emit(assign(r0910, body.constant(int(16)), 0x01));

                           body.emit(assign(r090E, lshift(r085D, body.constant(int(16))), 0x01));


                        body.instructions = f0913_parent_instructions;
                        body.emit(f0913);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0917 = bit_and(r090E, body.constant(4278190080u));
                        ir_expression *const r0918 = equal(r0917, body.constant(0u));
                        ir_if *f0916 = new(mem_ctx) ir_if(operand(r0918).val);
                        exec_list *const f0916_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0916->then_instructions;

                           body.emit(assign(r0910, add(r0910, body.constant(int(8))), 0x01));

                           body.emit(assign(r090E, lshift(r090E, body.constant(int(8))), 0x01));


                        body.instructions = f0916_parent_instructions;
                        body.emit(f0916);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r091A = bit_and(r090E, body.constant(4026531840u));
                        ir_expression *const r091B = equal(r091A, body.constant(0u));
                        ir_if *f0919 = new(mem_ctx) ir_if(operand(r091B).val);
                        exec_list *const f0919_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0919->then_instructions;

                           body.emit(assign(r0910, add(r0910, body.constant(int(4))), 0x01));

                           body.emit(assign(r090E, lshift(r090E, body.constant(int(4))), 0x01));


                        body.instructions = f0919_parent_instructions;
                        body.emit(f0919);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r091D = bit_and(r090E, body.constant(3221225472u));
                        ir_expression *const r091E = equal(r091D, body.constant(0u));
                        ir_if *f091C = new(mem_ctx) ir_if(operand(r091E).val);
                        exec_list *const f091C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f091C->then_instructions;

                           body.emit(assign(r0910, add(r0910, body.constant(int(2))), 0x01));

                           body.emit(assign(r090E, lshift(r090E, body.constant(int(2))), 0x01));


                        body.instructions = f091C_parent_instructions;
                        body.emit(f091C);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0920 = bit_and(r090E, body.constant(2147483648u));
                        ir_expression *const r0921 = equal(r0920, body.constant(0u));
                        ir_if *f091F = new(mem_ctx) ir_if(operand(r0921).val);
                        exec_list *const f091F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f091F->then_instructions;

                           body.emit(assign(r0910, add(r0910, body.constant(int(1))), 0x01));


                        body.instructions = f091F_parent_instructions;
                        body.emit(f091F);

                        /* END IF */

                        body.emit(assign(r090F, r0910, 0x01));


                     body.instructions = f0911_parent_instructions;
                     body.emit(f0911);

                     /* END IF */

                     body.emit(assign(r08F3, add(r090F, body.constant(int(-11))), 0x01));

                     ir_expression *const r0922 = equal(r08F3, body.constant(int(0)));
                     ir_expression *const r0923 = lshift(r085D, r08F3);
                     ir_expression *const r0924 = neg(r08F3);
                     ir_expression *const r0925 = bit_and(r0924, body.constant(int(31)));
                     ir_expression *const r0926 = rshift(swizzle_x(r084C), r0925);
                     ir_expression *const r0927 = bit_or(r0923, r0926);
                     body.emit(assign(r08F1, expr(ir_triop_csel, r0922, r085D, r0927), 0x01));

                     body.emit(assign(r08F2, lshift(swizzle_x(r084C), r08F3), 0x01));

                     body.emit(assign(r08F0, sub(body.constant(int(1)), r08F3), 0x01));


                  body.instructions = f08F4_parent_instructions;
                  body.emit(f08F4);

                  /* END IF */

                  body.emit(assign(r0850, r08F0, 0x01));

                  body.emit(assign(r0852, r08F1, 0x01));

                  body.emit(assign(r0853, r08F2, 0x01));


               body.instructions = f08EC_parent_instructions;
               body.emit(f08EC);

               /* END IF */


            body.instructions = f08EA_parent_instructions;
            body.emit(f08EA);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0928 = new(mem_ctx) ir_if(operand(r084D).val);
            exec_list *const f0928_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0928->then_instructions;

               ir_expression *const r0929 = add(r0851, r0850);
               body.emit(assign(r0856, add(r0929, body.constant(int(-1024))), 0x01));

               body.emit(assign(r0854, bit_or(r0854, body.constant(1048576u)), 0x01));

               ir_variable *const r092A = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r092B = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r092B, lshift(r0853, body.constant(int(12))), 0x01));

               ir_expression *const r092C = lshift(r0852, body.constant(int(12)));
               ir_expression *const r092D = rshift(r0853, body.constant(int(20)));
               body.emit(assign(r092A, bit_or(r092C, r092D), 0x01));

               body.emit(assign(r0852, r092A, 0x01));

               body.emit(assign(r0853, r092B, 0x01));

               ir_variable *const r092E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r092E);
               ir_variable *const r092F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r092F);
               ir_variable *const r0930 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0930);
               ir_variable *const r0931 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0931, bit_and(r0855, body.constant(65535u)), 0x01));

               ir_variable *const r0932 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0932, rshift(r0855, body.constant(int(16))), 0x01));

               ir_variable *const r0933 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0933, bit_and(r092B, body.constant(65535u)), 0x01));

               ir_variable *const r0934 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0934, rshift(r092B, body.constant(int(16))), 0x01));

               ir_variable *const r0935 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0935, mul(r0932, r0933), 0x01));

               ir_expression *const r0936 = mul(r0931, r0934);
               body.emit(assign(r092F, add(r0936, r0935), 0x01));

               ir_expression *const r0937 = mul(r0932, r0934);
               ir_expression *const r0938 = less(r092F, r0935);
               ir_expression *const r0939 = expr(ir_unop_b2i, r0938);
               ir_expression *const r093A = expr(ir_unop_i2u, r0939);
               ir_expression *const r093B = lshift(r093A, body.constant(int(16)));
               ir_expression *const r093C = rshift(r092F, body.constant(int(16)));
               ir_expression *const r093D = add(r093B, r093C);
               body.emit(assign(r092E, add(r0937, r093D), 0x01));

               body.emit(assign(r092F, lshift(r092F, body.constant(int(16))), 0x01));

               ir_expression *const r093E = mul(r0931, r0933);
               body.emit(assign(r0930, add(r093E, r092F), 0x01));

               ir_expression *const r093F = less(r0930, r092F);
               ir_expression *const r0940 = expr(ir_unop_b2i, r093F);
               ir_expression *const r0941 = expr(ir_unop_i2u, r0940);
               body.emit(assign(r092E, add(r092E, r0941), 0x01));

               ir_variable *const r0942 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0942);
               ir_variable *const r0943 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0943);
               ir_variable *const r0944 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0944);
               ir_variable *const r0945 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0945, bit_and(r0855, body.constant(65535u)), 0x01));

               ir_variable *const r0946 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0946, rshift(r0855, body.constant(int(16))), 0x01));

               ir_variable *const r0947 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0947, bit_and(r092A, body.constant(65535u)), 0x01));

               ir_variable *const r0948 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0948, rshift(r092A, body.constant(int(16))), 0x01));

               ir_variable *const r0949 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0949, mul(r0946, r0947), 0x01));

               ir_expression *const r094A = mul(r0945, r0948);
               body.emit(assign(r0943, add(r094A, r0949), 0x01));

               ir_expression *const r094B = mul(r0946, r0948);
               ir_expression *const r094C = less(r0943, r0949);
               ir_expression *const r094D = expr(ir_unop_b2i, r094C);
               ir_expression *const r094E = expr(ir_unop_i2u, r094D);
               ir_expression *const r094F = lshift(r094E, body.constant(int(16)));
               ir_expression *const r0950 = rshift(r0943, body.constant(int(16)));
               ir_expression *const r0951 = add(r094F, r0950);
               body.emit(assign(r0942, add(r094B, r0951), 0x01));

               body.emit(assign(r0943, lshift(r0943, body.constant(int(16))), 0x01));

               ir_expression *const r0952 = mul(r0945, r0947);
               body.emit(assign(r0944, add(r0952, r0943), 0x01));

               ir_expression *const r0953 = less(r0944, r0943);
               ir_expression *const r0954 = expr(ir_unop_b2i, r0953);
               ir_expression *const r0955 = expr(ir_unop_i2u, r0954);
               body.emit(assign(r0942, add(r0942, r0955), 0x01));

               ir_variable *const r0956 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0956, add(r0944, r092E), 0x01));

               ir_variable *const r0957 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0957);
               ir_variable *const r0958 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0958);
               ir_variable *const r0959 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0959);
               ir_variable *const r095A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095A, bit_and(r0854, body.constant(65535u)), 0x01));

               ir_variable *const r095B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095B, rshift(r0854, body.constant(int(16))), 0x01));

               ir_variable *const r095C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095C, bit_and(r092A, body.constant(65535u)), 0x01));

               ir_variable *const r095D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095D, rshift(r092A, body.constant(int(16))), 0x01));

               ir_variable *const r095E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095E, mul(r095B, r095C), 0x01));

               ir_expression *const r095F = mul(r095A, r095D);
               body.emit(assign(r0958, add(r095F, r095E), 0x01));

               ir_expression *const r0960 = mul(r095B, r095D);
               ir_expression *const r0961 = less(r0958, r095E);
               ir_expression *const r0962 = expr(ir_unop_b2i, r0961);
               ir_expression *const r0963 = expr(ir_unop_i2u, r0962);
               ir_expression *const r0964 = lshift(r0963, body.constant(int(16)));
               ir_expression *const r0965 = rshift(r0958, body.constant(int(16)));
               ir_expression *const r0966 = add(r0964, r0965);
               body.emit(assign(r0957, add(r0960, r0966), 0x01));

               body.emit(assign(r0958, lshift(r0958, body.constant(int(16))), 0x01));

               ir_expression *const r0967 = mul(r095A, r095C);
               body.emit(assign(r0959, add(r0967, r0958), 0x01));

               ir_expression *const r0968 = less(r0959, r0958);
               ir_expression *const r0969 = expr(ir_unop_b2i, r0968);
               ir_expression *const r096A = expr(ir_unop_i2u, r0969);
               body.emit(assign(r0957, add(r0957, r096A), 0x01));

               ir_variable *const r096B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r096C = less(r0956, r0944);
               ir_expression *const r096D = expr(ir_unop_b2i, r096C);
               ir_expression *const r096E = expr(ir_unop_i2u, r096D);
               ir_expression *const r096F = add(r0942, r096E);
               body.emit(assign(r096B, add(r0959, r096F), 0x01));

               ir_variable *const r0970 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0970);
               ir_variable *const r0971 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0971);
               ir_variable *const r0972 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0972);
               ir_variable *const r0973 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0973, bit_and(r0854, body.constant(65535u)), 0x01));

               ir_variable *const r0974 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0974, rshift(r0854, body.constant(int(16))), 0x01));

               ir_variable *const r0975 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0975, bit_and(r092B, body.constant(65535u)), 0x01));

               ir_variable *const r0976 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0976, rshift(r092B, body.constant(int(16))), 0x01));

               ir_variable *const r0977 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0977, mul(r0974, r0975), 0x01));

               ir_expression *const r0978 = mul(r0973, r0976);
               body.emit(assign(r0971, add(r0978, r0977), 0x01));

               ir_expression *const r0979 = mul(r0974, r0976);
               ir_expression *const r097A = less(r0971, r0977);
               ir_expression *const r097B = expr(ir_unop_b2i, r097A);
               ir_expression *const r097C = expr(ir_unop_i2u, r097B);
               ir_expression *const r097D = lshift(r097C, body.constant(int(16)));
               ir_expression *const r097E = rshift(r0971, body.constant(int(16)));
               ir_expression *const r097F = add(r097D, r097E);
               body.emit(assign(r0970, add(r0979, r097F), 0x01));

               body.emit(assign(r0971, lshift(r0971, body.constant(int(16))), 0x01));

               ir_expression *const r0980 = mul(r0973, r0975);
               body.emit(assign(r0972, add(r0980, r0971), 0x01));

               ir_expression *const r0981 = less(r0972, r0971);
               ir_expression *const r0982 = expr(ir_unop_b2i, r0981);
               ir_expression *const r0983 = expr(ir_unop_i2u, r0982);
               body.emit(assign(r0970, add(r0970, r0983), 0x01));

               ir_variable *const r0984 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0984, add(r0972, r0956), 0x01));

               ir_variable *const r0985 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0986 = less(r0984, r0972);
               ir_expression *const r0987 = expr(ir_unop_b2i, r0986);
               ir_expression *const r0988 = expr(ir_unop_i2u, r0987);
               ir_expression *const r0989 = add(r0970, r0988);
               body.emit(assign(r0985, add(r096B, r0989), 0x01));

               ir_variable *const r098A = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r098B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r098B, add(r0985, r0855), 0x01));

               ir_expression *const r098C = less(r096B, r0959);
               ir_expression *const r098D = expr(ir_unop_b2i, r098C);
               ir_expression *const r098E = expr(ir_unop_i2u, r098D);
               ir_expression *const r098F = add(r0957, r098E);
               ir_expression *const r0990 = less(r0985, r096B);
               ir_expression *const r0991 = expr(ir_unop_b2i, r0990);
               ir_expression *const r0992 = expr(ir_unop_i2u, r0991);
               ir_expression *const r0993 = add(r098F, r0992);
               ir_expression *const r0994 = add(r0993, r0854);
               ir_expression *const r0995 = less(r098B, r0985);
               ir_expression *const r0996 = expr(ir_unop_b2i, r0995);
               ir_expression *const r0997 = expr(ir_unop_i2u, r0996);
               body.emit(assign(r098A, add(r0994, r0997), 0x01));

               body.emit(assign(r0859, r098A, 0x01));

               body.emit(assign(r0858, r098B, 0x01));

               ir_expression *const r0998 = nequal(r0930, body.constant(0u));
               ir_expression *const r0999 = expr(ir_unop_b2i, r0998);
               ir_expression *const r099A = expr(ir_unop_i2u, r0999);
               body.emit(assign(r0857, bit_or(r0984, r099A), 0x01));

               /* IF CONDITION */
               ir_expression *const r099C = gequal(r098A, body.constant(2097152u));
               ir_if *f099B = new(mem_ctx) ir_if(operand(r099C).val);
               exec_list *const f099B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f099B->then_instructions;

                  ir_variable *const r099D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r099D);
                  body.emit(assign(r099D, lshift(r098B, body.constant(int(31))), 0x01));

                  ir_expression *const r099E = nequal(r0857, body.constant(0u));
                  ir_expression *const r099F = expr(ir_unop_b2i, r099E);
                  ir_expression *const r09A0 = expr(ir_unop_i2u, r099F);
                  body.emit(assign(r099D, bit_or(r099D, r09A0), 0x01));

                  body.emit(assign(r0859, rshift(r098A, body.constant(int(1))), 0x01));

                  ir_expression *const r09A1 = lshift(r098A, body.constant(int(31)));
                  ir_expression *const r09A2 = rshift(r098B, body.constant(int(1)));
                  body.emit(assign(r0858, bit_or(r09A1, r09A2), 0x01));

                  body.emit(assign(r0857, r099D, 0x01));

                  body.emit(assign(r0856, add(r0856, body.constant(int(1))), 0x01));


               body.instructions = f099B_parent_instructions;
               body.emit(f099B);

               /* END IF */

               ir_variable *const r09A3 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r09A3, r0856, 0x01));

               ir_variable *const r09A4 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r09A4, r0859, 0x01));

               ir_variable *const r09A5 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r09A5, r0858, 0x01));

               ir_variable *const r09A6 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r09A6, r0857, 0x01));

               ir_variable *const r09A7 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r09A7, body.constant(true), 0x01));

               ir_variable *const r09A8 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r09A9 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r09A9);
               ir_expression *const r09AA = expr(ir_unop_u2i, r0857);
               body.emit(assign(r09A9, less(r09AA, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r09AC = gequal(r0856, body.constant(int(2045)));
               ir_if *f09AB = new(mem_ctx) ir_if(operand(r09AC).val);
               exec_list *const f09AB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09AB->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r09AE = less(body.constant(int(2045)), r0856);
                  ir_expression *const r09AF = equal(r0856, body.constant(int(2045)));
                  ir_expression *const r09B0 = equal(body.constant(2097151u), r0859);
                  ir_expression *const r09B1 = equal(body.constant(4294967295u), r0858);
                  ir_expression *const r09B2 = logic_and(r09B0, r09B1);
                  ir_expression *const r09B3 = logic_and(r09AF, r09B2);
                  ir_expression *const r09B4 = logic_and(r09B3, r09A9);
                  ir_expression *const r09B5 = logic_or(r09AE, r09B4);
                  ir_if *f09AD = new(mem_ctx) ir_if(operand(r09B5).val);
                  exec_list *const f09AD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09AD->then_instructions;

                     ir_variable *const r09B6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r09B6);
                     ir_expression *const r09B7 = lshift(r084F, body.constant(int(31)));
                     body.emit(assign(r09B6, add(r09B7, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r09B6, body.constant(0u), 0x01));

                     body.emit(assign(r09A8, r09B6, 0x03));

                     body.emit(assign(r09A7, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09AD->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09B9 = less(r0856, body.constant(int(0)));
                     ir_if *f09B8 = new(mem_ctx) ir_if(operand(r09B9).val);
                     exec_list *const f09B8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09B8->then_instructions;

                        ir_variable *const r09BA = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r09BA, r0857, 0x01));

                        ir_variable *const r09BB = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r09BB, neg(r0856), 0x01));

                        ir_variable *const r09BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r09BC);
                        ir_variable *const r09BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r09BD);
                        ir_variable *const r09BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r09BE);
                        ir_variable *const r09BF = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r09C0 = neg(r09BB);
                        body.emit(assign(r09BF, bit_and(r09C0, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r09C2 = equal(r09BB, body.constant(int(0)));
                        ir_if *f09C1 = new(mem_ctx) ir_if(operand(r09C2).val);
                        exec_list *const f09C1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f09C1->then_instructions;

                           body.emit(assign(r09BC, r0857, 0x01));

                           body.emit(assign(r09BD, r0858, 0x01));

                           body.emit(assign(r09BE, r0859, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f09C1->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r09C4 = less(r09BB, body.constant(int(32)));
                           ir_if *f09C3 = new(mem_ctx) ir_if(operand(r09C4).val);
                           exec_list *const f09C3_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f09C3->then_instructions;

                              body.emit(assign(r09BC, lshift(r0858, r09BF), 0x01));

                              ir_expression *const r09C5 = lshift(r0859, r09BF);
                              ir_expression *const r09C6 = rshift(r0858, r09BB);
                              body.emit(assign(r09BD, bit_or(r09C5, r09C6), 0x01));

                              body.emit(assign(r09BE, rshift(r0859, r09BB), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f09C3->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r09C8 = equal(r09BB, body.constant(int(32)));
                              ir_if *f09C7 = new(mem_ctx) ir_if(operand(r09C8).val);
                              exec_list *const f09C7_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f09C7->then_instructions;

                                 body.emit(assign(r09BC, r0858, 0x01));

                                 body.emit(assign(r09BD, r0859, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f09C7->else_instructions;

                                 body.emit(assign(r09BA, bit_or(r0857, r0858), 0x01));

                                 ir_expression *const r09C9 = less(r09BB, body.constant(int(64)));
                                 ir_expression *const r09CA = lshift(r0859, r09BF);
                                 ir_expression *const r09CB = equal(r09BB, body.constant(int(64)));
                                 ir_expression *const r09CC = nequal(r0859, body.constant(0u));
                                 ir_expression *const r09CD = expr(ir_unop_b2i, r09CC);
                                 ir_expression *const r09CE = expr(ir_unop_i2u, r09CD);
                                 ir_expression *const r09CF = expr(ir_triop_csel, r09CB, r0859, r09CE);
                                 body.emit(assign(r09BC, expr(ir_triop_csel, r09C9, r09CA, r09CF), 0x01));

                                 ir_expression *const r09D0 = less(r09BB, body.constant(int(64)));
                                 ir_expression *const r09D1 = bit_and(r09BB, body.constant(int(31)));
                                 ir_expression *const r09D2 = rshift(r0859, r09D1);
                                 body.emit(assign(r09BD, expr(ir_triop_csel, r09D0, r09D2, body.constant(0u)), 0x01));


                              body.instructions = f09C7_parent_instructions;
                              body.emit(f09C7);

                              /* END IF */

                              body.emit(assign(r09BE, body.constant(0u), 0x01));


                           body.instructions = f09C3_parent_instructions;
                           body.emit(f09C3);

                           /* END IF */

                           ir_expression *const r09D3 = nequal(r09BA, body.constant(0u));
                           ir_expression *const r09D4 = expr(ir_unop_b2i, r09D3);
                           ir_expression *const r09D5 = expr(ir_unop_i2u, r09D4);
                           body.emit(assign(r09BC, bit_or(r09BC, r09D5), 0x01));


                        body.instructions = f09C1_parent_instructions;
                        body.emit(f09C1);

                        /* END IF */

                        body.emit(assign(r09A4, r09BE, 0x01));

                        body.emit(assign(r09A5, r09BD, 0x01));

                        body.emit(assign(r09A6, r09BC, 0x01));

                        body.emit(assign(r09A3, body.constant(int(0)), 0x01));

                        body.emit(assign(r09A9, less(r09BC, body.constant(0u)), 0x01));


                     body.instructions = f09B8_parent_instructions;
                     body.emit(f09B8);

                     /* END IF */


                  body.instructions = f09AD_parent_instructions;
                  body.emit(f09AD);

                  /* END IF */


               body.instructions = f09AB_parent_instructions;
               body.emit(f09AB);

               /* END IF */

               /* IF CONDITION */
               ir_if *f09D6 = new(mem_ctx) ir_if(operand(r09A7).val);
               exec_list *const f09D6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09D6->then_instructions;

                  /* IF CONDITION */
                  ir_if *f09D7 = new(mem_ctx) ir_if(operand(r09A9).val);
                  exec_list *const f09D7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09D7->then_instructions;

                     ir_variable *const r09D8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r09D8, add(r09A5, body.constant(1u)), 0x01));

                     ir_expression *const r09D9 = less(r09D8, r09A5);
                     ir_expression *const r09DA = expr(ir_unop_b2i, r09D9);
                     ir_expression *const r09DB = expr(ir_unop_i2u, r09DA);
                     body.emit(assign(r09A4, add(r09A4, r09DB), 0x01));

                     ir_expression *const r09DC = equal(r09A6, body.constant(0u));
                     ir_expression *const r09DD = expr(ir_unop_b2i, r09DC);
                     ir_expression *const r09DE = expr(ir_unop_i2u, r09DD);
                     ir_expression *const r09DF = add(r09A6, r09DE);
                     ir_expression *const r09E0 = bit_and(r09DF, body.constant(1u));
                     ir_expression *const r09E1 = expr(ir_unop_bit_not, r09E0);
                     body.emit(assign(r09A5, bit_and(r09D8, r09E1), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09D7->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09E3 = bit_or(r09A4, r09A5);
                     ir_expression *const r09E4 = equal(r09E3, body.constant(0u));
                     ir_if *f09E2 = new(mem_ctx) ir_if(operand(r09E4).val);
                     exec_list *const f09E2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09E2->then_instructions;

                        body.emit(assign(r09A3, body.constant(int(0)), 0x01));


                     body.instructions = f09E2_parent_instructions;
                     body.emit(f09E2);

                     /* END IF */


                  body.instructions = f09D7_parent_instructions;
                  body.emit(f09D7);

                  /* END IF */

                  ir_variable *const r09E5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r09E5);
                  ir_expression *const r09E6 = lshift(r084F, body.constant(int(31)));
                  ir_expression *const r09E7 = expr(ir_unop_i2u, r09A3);
                  ir_expression *const r09E8 = lshift(r09E7, body.constant(int(20)));
                  ir_expression *const r09E9 = add(r09E6, r09E8);
                  body.emit(assign(r09E5, add(r09E9, r09A4), 0x02));

                  body.emit(assign(r09E5, r09A5, 0x01));

                  body.emit(assign(r09A8, r09E5, 0x03));

                  body.emit(assign(r09A7, body.constant(false), 0x01));


               body.instructions = f09D6_parent_instructions;
               body.emit(f09D6);

               /* END IF */

               body.emit(assign(r084E, r09A8, 0x03));

               body.emit(assign(r084D, body.constant(false), 0x01));


            body.instructions = f0928_parent_instructions;
            body.emit(f0928);

            /* END IF */


         body.instructions = f08E9_parent_instructions;
         body.emit(f08E9);

         /* END IF */


      body.instructions = f088B_parent_instructions;
      body.emit(f088B);

      /* END IF */


   body.instructions = f0866_parent_instructions;
   body.emit(f0866);

   /* END IF */

   body.emit(ret(r084E));

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

   ir_variable *const r09EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09EA);
   ir_variable *const r09EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09EB);
   ir_variable *const r09EC = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r09EC);
   ir_variable *const r09ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09ED);
   ir_variable *const r09EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09EE);
   ir_expression *const r09EF = equal(r09EC, body.constant(int(0)));
   ir_expression *const r09F0 = less(r09EC, body.constant(int(32)));
   ir_expression *const r09F1 = neg(r09EC);
   ir_expression *const r09F2 = bit_and(r09F1, body.constant(int(31)));
   ir_expression *const r09F3 = lshift(r09EA, r09F2);
   ir_expression *const r09F4 = rshift(r09EB, r09EC);
   ir_expression *const r09F5 = bit_or(r09F3, r09F4);
   ir_expression *const r09F6 = less(r09EC, body.constant(int(64)));
   ir_expression *const r09F7 = bit_and(r09EC, body.constant(int(31)));
   ir_expression *const r09F8 = rshift(r09EA, r09F7);
   ir_expression *const r09F9 = expr(ir_triop_csel, r09F6, r09F8, body.constant(0u));
   ir_expression *const r09FA = expr(ir_triop_csel, r09F0, r09F5, r09F9);
   body.emit(assign(r09EE, expr(ir_triop_csel, r09EF, r09EA, r09FA), 0x01));

   ir_expression *const r09FB = equal(r09EC, body.constant(int(0)));
   ir_expression *const r09FC = less(r09EC, body.constant(int(32)));
   ir_expression *const r09FD = rshift(r09EA, r09EC);
   ir_expression *const r09FE = expr(ir_triop_csel, r09FC, r09FD, body.constant(0u));
   body.emit(assign(r09ED, expr(ir_triop_csel, r09FB, r09EA, r09FE), 0x01));

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

   ir_variable *const r09FF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r09FF);
   ir_variable *const r0A00 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0A01 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A01);
   ir_variable *const r0A02 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0A02);
   ir_variable *const r0A03 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0A03, swizzle_x(r09FF), 0x01));

   body.emit(assign(r0A02, r0A03, 0x01));

   ir_variable *const r0A04 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A04, bit_and(swizzle_y(r09FF), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A01, r0A04, 0x01));

   ir_variable *const r0A05 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A06 = rshift(swizzle_y(r09FF), body.constant(int(20)));
   ir_expression *const r0A07 = bit_and(r0A06, body.constant(2047u));
   body.emit(assign(r0A05, expr(ir_unop_u2i, r0A07), 0x01));

   ir_variable *const r0A08 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A08, rshift(swizzle_y(r09FF), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A0A = nequal(r0A08, body.constant(0u));
   ir_if *f0A09 = new(mem_ctx) ir_if(operand(r0A0A).val);
   exec_list *const f0A09_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A09->then_instructions;

      body.emit(assign(r0A00, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A09->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A0C = equal(r0A05, body.constant(int(2047)));
      ir_expression *const r0A0D = bit_or(r0A04, swizzle_x(r09FF));
      ir_expression *const r0A0E = nequal(r0A0D, body.constant(0u));
      ir_expression *const r0A0F = logic_and(r0A0C, r0A0E);
      ir_if *f0A0B = new(mem_ctx) ir_if(operand(r0A0F).val);
      exec_list *const f0A0B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A0B->then_instructions;

         body.emit(assign(r0A00, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A0B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A11 = nequal(r0A05, body.constant(int(0)));
         ir_if *f0A10 = new(mem_ctx) ir_if(operand(r0A11).val);
         exec_list *const f0A10_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A10->then_instructions;

            body.emit(assign(r0A01, bit_or(r0A04, body.constant(1048576u)), 0x01));


         body.instructions = f0A10_parent_instructions;
         body.emit(f0A10);

         /* END IF */

         ir_variable *const r0A12 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0A12, sub(body.constant(int(1063)), r0A05), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A14 = less(body.constant(int(0)), r0A12);
         ir_if *f0A13 = new(mem_ctx) ir_if(operand(r0A14).val);
         exec_list *const f0A13_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A13->then_instructions;

            ir_variable *const r0A15 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0A15);
            ir_variable *const r0A16 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0A17 = neg(r0A12);
            body.emit(assign(r0A16, bit_and(r0A17, body.constant(int(31))), 0x01));

            ir_variable *const r0A18 = body.make_temp(glsl_type::uint_type, "mix_retval");
            ir_expression *const r0A19 = less(r0A12, body.constant(int(32)));
            ir_expression *const r0A1A = rshift(r0A01, r0A12);
            ir_expression *const r0A1B = equal(r0A12, body.constant(int(0)));
            ir_expression *const r0A1C = expr(ir_triop_csel, r0A1B, r0A01, body.constant(0u));
            body.emit(assign(r0A18, expr(ir_triop_csel, r0A19, r0A1A, r0A1C), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A1E = equal(r0A12, body.constant(int(0)));
            ir_if *f0A1D = new(mem_ctx) ir_if(operand(r0A1E).val);
            exec_list *const f0A1D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A1D->then_instructions;

               body.emit(assign(r0A15, r0A03, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A1D->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0A20 = less(r0A12, body.constant(int(32)));
               ir_if *f0A1F = new(mem_ctx) ir_if(operand(r0A20).val);
               exec_list *const f0A1F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A1F->then_instructions;

                  ir_expression *const r0A21 = lshift(r0A01, r0A16);
                  ir_expression *const r0A22 = rshift(swizzle_x(r09FF), r0A12);
                  ir_expression *const r0A23 = bit_or(r0A21, r0A22);
                  ir_expression *const r0A24 = lshift(swizzle_x(r09FF), r0A16);
                  ir_expression *const r0A25 = nequal(r0A24, body.constant(0u));
                  ir_expression *const r0A26 = expr(ir_unop_b2i, r0A25);
                  ir_expression *const r0A27 = expr(ir_unop_i2u, r0A26);
                  body.emit(assign(r0A15, bit_or(r0A23, r0A27), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A1F->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A29 = equal(r0A12, body.constant(int(32)));
                  ir_if *f0A28 = new(mem_ctx) ir_if(operand(r0A29).val);
                  exec_list *const f0A28_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A28->then_instructions;

                     ir_expression *const r0A2A = nequal(swizzle_x(r09FF), body.constant(0u));
                     ir_expression *const r0A2B = expr(ir_unop_b2i, r0A2A);
                     ir_expression *const r0A2C = expr(ir_unop_i2u, r0A2B);
                     body.emit(assign(r0A15, bit_or(r0A01, r0A2C), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A28->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0A2E = less(r0A12, body.constant(int(64)));
                     ir_if *f0A2D = new(mem_ctx) ir_if(operand(r0A2E).val);
                     exec_list *const f0A2D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0A2D->then_instructions;

                        ir_expression *const r0A2F = bit_and(r0A12, body.constant(int(31)));
                        ir_expression *const r0A30 = rshift(r0A01, r0A2F);
                        ir_expression *const r0A31 = lshift(r0A01, r0A16);
                        ir_expression *const r0A32 = bit_or(r0A31, swizzle_x(r09FF));
                        ir_expression *const r0A33 = nequal(r0A32, body.constant(0u));
                        ir_expression *const r0A34 = expr(ir_unop_b2i, r0A33);
                        ir_expression *const r0A35 = expr(ir_unop_i2u, r0A34);
                        body.emit(assign(r0A15, bit_or(r0A30, r0A35), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0A2D->else_instructions;

                        ir_expression *const r0A36 = bit_or(r0A01, swizzle_x(r09FF));
                        ir_expression *const r0A37 = nequal(r0A36, body.constant(0u));
                        ir_expression *const r0A38 = expr(ir_unop_b2i, r0A37);
                        body.emit(assign(r0A15, expr(ir_unop_i2u, r0A38), 0x01));


                     body.instructions = f0A2D_parent_instructions;
                     body.emit(f0A2D);

                     /* END IF */


                  body.instructions = f0A28_parent_instructions;
                  body.emit(f0A28);

                  /* END IF */


               body.instructions = f0A1F_parent_instructions;
               body.emit(f0A1F);

               /* END IF */


            body.instructions = f0A1D_parent_instructions;
            body.emit(f0A1D);

            /* END IF */

            body.emit(assign(r0A01, r0A18, 0x01));

            body.emit(assign(r0A02, r0A15, 0x01));


         body.instructions = f0A13_parent_instructions;
         body.emit(f0A13);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A3A = bit_and(r0A01, body.constant(4294963200u));
         ir_expression *const r0A3B = nequal(r0A3A, body.constant(0u));
         ir_if *f0A39 = new(mem_ctx) ir_if(operand(r0A3B).val);
         exec_list *const f0A39_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A39->then_instructions;

            ir_variable *const r0A3C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A3E = nequal(r0A08, body.constant(0u));
            ir_if *f0A3D = new(mem_ctx) ir_if(operand(r0A3E).val);
            exec_list *const f0A3D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A3D->then_instructions;

               body.emit(assign(r0A3C, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A3D->else_instructions;

               body.emit(assign(r0A3C, body.constant(4294967295u), 0x01));


            body.instructions = f0A3D_parent_instructions;
            body.emit(f0A3D);

            /* END IF */

            body.emit(assign(r0A00, r0A3C, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A39->else_instructions;

            ir_variable *const r0A3F = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r0A40 = lshift(r0A01, body.constant(int(20)));
            ir_expression *const r0A41 = rshift(r0A02, body.constant(int(12)));
            body.emit(assign(r0A3F, bit_or(r0A40, r0A41), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A43 = nequal(r0A08, body.constant(0u));
            ir_expression *const r0A44 = nequal(r0A3F, body.constant(0u));
            ir_expression *const r0A45 = logic_and(r0A43, r0A44);
            ir_if *f0A42 = new(mem_ctx) ir_if(operand(r0A45).val);
            exec_list *const f0A42_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A42->then_instructions;

               ir_variable *const r0A46 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0A48 = nequal(r0A08, body.constant(0u));
               ir_if *f0A47 = new(mem_ctx) ir_if(operand(r0A48).val);
               exec_list *const f0A47_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A47->then_instructions;

                  body.emit(assign(r0A46, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A47->else_instructions;

                  body.emit(assign(r0A46, body.constant(4294967295u), 0x01));


               body.instructions = f0A47_parent_instructions;
               body.emit(f0A47);

               /* END IF */

               body.emit(assign(r0A00, r0A46, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A42->else_instructions;

               body.emit(assign(r0A00, r0A3F, 0x01));


            body.instructions = f0A42_parent_instructions;
            body.emit(f0A42);

            /* END IF */


         body.instructions = f0A39_parent_instructions;
         body.emit(f0A39);

         /* END IF */


      body.instructions = f0A0B_parent_instructions;
      body.emit(f0A0B);

      /* END IF */


   body.instructions = f0A09_parent_instructions;
   body.emit(f0A09);

   /* END IF */

   body.emit(ret(r0A00));

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

   ir_variable *const r0A49 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A49);
   ir_variable *const r0A4A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A4B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0A4B);
   ir_variable *const r0A4C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0A4C);
   /* IF CONDITION */
   ir_expression *const r0A4E = equal(r0A49, body.constant(0u));
   ir_if *f0A4D = new(mem_ctx) ir_if(operand(r0A4E).val);
   exec_list *const f0A4D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A4D->then_instructions;

      body.emit(assign(r0A4A, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A4D->else_instructions;

      ir_variable *const r0A4F = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0A4F, r0A49, 0x01));

      ir_variable *const r0A50 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0A51 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0A51);
      /* IF CONDITION */
      ir_expression *const r0A53 = equal(r0A49, body.constant(0u));
      ir_if *f0A52 = new(mem_ctx) ir_if(operand(r0A53).val);
      exec_list *const f0A52_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A52->then_instructions;

         body.emit(assign(r0A50, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A52->else_instructions;

         body.emit(assign(r0A51, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A55 = bit_and(r0A49, body.constant(4294901760u));
         ir_expression *const r0A56 = equal(r0A55, body.constant(0u));
         ir_if *f0A54 = new(mem_ctx) ir_if(operand(r0A56).val);
         exec_list *const f0A54_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A54->then_instructions;

            body.emit(assign(r0A51, body.constant(int(16)), 0x01));

            body.emit(assign(r0A4F, lshift(r0A49, body.constant(int(16))), 0x01));


         body.instructions = f0A54_parent_instructions;
         body.emit(f0A54);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A58 = bit_and(r0A4F, body.constant(4278190080u));
         ir_expression *const r0A59 = equal(r0A58, body.constant(0u));
         ir_if *f0A57 = new(mem_ctx) ir_if(operand(r0A59).val);
         exec_list *const f0A57_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A57->then_instructions;

            body.emit(assign(r0A51, add(r0A51, body.constant(int(8))), 0x01));

            body.emit(assign(r0A4F, lshift(r0A4F, body.constant(int(8))), 0x01));


         body.instructions = f0A57_parent_instructions;
         body.emit(f0A57);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A5B = bit_and(r0A4F, body.constant(4026531840u));
         ir_expression *const r0A5C = equal(r0A5B, body.constant(0u));
         ir_if *f0A5A = new(mem_ctx) ir_if(operand(r0A5C).val);
         exec_list *const f0A5A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A5A->then_instructions;

            body.emit(assign(r0A51, add(r0A51, body.constant(int(4))), 0x01));

            body.emit(assign(r0A4F, lshift(r0A4F, body.constant(int(4))), 0x01));


         body.instructions = f0A5A_parent_instructions;
         body.emit(f0A5A);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A5E = bit_and(r0A4F, body.constant(3221225472u));
         ir_expression *const r0A5F = equal(r0A5E, body.constant(0u));
         ir_if *f0A5D = new(mem_ctx) ir_if(operand(r0A5F).val);
         exec_list *const f0A5D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A5D->then_instructions;

            body.emit(assign(r0A51, add(r0A51, body.constant(int(2))), 0x01));

            body.emit(assign(r0A4F, lshift(r0A4F, body.constant(int(2))), 0x01));


         body.instructions = f0A5D_parent_instructions;
         body.emit(f0A5D);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A61 = bit_and(r0A4F, body.constant(2147483648u));
         ir_expression *const r0A62 = equal(r0A61, body.constant(0u));
         ir_if *f0A60 = new(mem_ctx) ir_if(operand(r0A62).val);
         exec_list *const f0A60_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A60->then_instructions;

            body.emit(assign(r0A51, add(r0A51, body.constant(int(1))), 0x01));


         body.instructions = f0A60_parent_instructions;
         body.emit(f0A60);

         /* END IF */

         body.emit(assign(r0A50, r0A51, 0x01));


      body.instructions = f0A52_parent_instructions;
      body.emit(f0A52);

      /* END IF */

      ir_variable *const r0A63 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0A63, add(r0A50, body.constant(int(21))), 0x01));

      body.emit(assign(r0A4C, body.constant(0u), 0x01));

      body.emit(assign(r0A4B, body.constant(0u), 0x01));

      ir_variable *const r0A64 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0A65 = neg(r0A63);
      body.emit(assign(r0A64, bit_and(r0A65, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A67 = equal(r0A63, body.constant(int(0)));
      ir_if *f0A66 = new(mem_ctx) ir_if(operand(r0A67).val);
      exec_list *const f0A66_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A66->then_instructions;

         body.emit(assign(r0A4C, body.constant(0u), 0x01));

         body.emit(assign(r0A4B, r0A49, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A66->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A69 = less(r0A63, body.constant(int(32)));
         ir_if *f0A68 = new(mem_ctx) ir_if(operand(r0A69).val);
         exec_list *const f0A68_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A68->then_instructions;

            body.emit(assign(r0A4C, rshift(r0A49, r0A64), 0x01));

            body.emit(assign(r0A4B, lshift(r0A49, r0A63), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A68->else_instructions;

            ir_variable *const r0A6A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A6C = less(r0A63, body.constant(int(64)));
            ir_if *f0A6B = new(mem_ctx) ir_if(operand(r0A6C).val);
            exec_list *const f0A6B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A6B->then_instructions;

               ir_expression *const r0A6D = add(r0A63, body.constant(int(-32)));
               body.emit(assign(r0A6A, lshift(r0A49, r0A6D), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A6B->else_instructions;

               body.emit(assign(r0A6A, body.constant(0u), 0x01));


            body.instructions = f0A6B_parent_instructions;
            body.emit(f0A6B);

            /* END IF */

            body.emit(assign(r0A4C, r0A6A, 0x01));

            body.emit(assign(r0A4B, body.constant(0u), 0x01));


         body.instructions = f0A68_parent_instructions;
         body.emit(f0A68);

         /* END IF */


      body.instructions = f0A66_parent_instructions;
      body.emit(f0A66);

      /* END IF */

      ir_variable *const r0A6E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A6E);
      ir_expression *const r0A6F = sub(body.constant(int(1074)), r0A63);
      ir_expression *const r0A70 = expr(ir_unop_i2u, r0A6F);
      ir_expression *const r0A71 = lshift(r0A70, body.constant(int(20)));
      body.emit(assign(r0A6E, add(r0A71, r0A4C), 0x02));

      body.emit(assign(r0A6E, r0A4B, 0x01));

      body.emit(assign(r0A4A, r0A6E, 0x03));


   body.instructions = f0A4D_parent_instructions;
   body.emit(f0A4D);

   /* END IF */

   body.emit(ret(r0A4A));

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

   ir_variable *const r0A72 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A72);
   ir_variable *const r0A73 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A73, body.constant(true), 0x01));

   ir_variable *const r0A74 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0A75 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0A75);
   ir_variable *const r0A76 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A76);
   ir_variable *const r0A77 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A77);
   ir_variable *const r0A78 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A78, bit_and(swizzle_y(r0A72), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A77, r0A78, 0x01));

   ir_variable *const r0A79 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A7A = rshift(swizzle_y(r0A72), body.constant(int(20)));
   ir_expression *const r0A7B = bit_and(r0A7A, body.constant(2047u));
   body.emit(assign(r0A79, expr(ir_unop_u2i, r0A7B), 0x01));

   body.emit(assign(r0A76, rshift(swizzle_y(r0A72), body.constant(int(31))), 0x01));

   body.emit(assign(r0A75, body.constant(0u), 0x01));

   ir_variable *const r0A7C = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0A7C, add(r0A79, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A7E = gequal(r0A7C, body.constant(int(0)));
   ir_if *f0A7D = new(mem_ctx) ir_if(operand(r0A7E).val);
   exec_list *const f0A7D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A7D->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A80 = less(body.constant(int(1054)), r0A79);
      ir_if *f0A7F = new(mem_ctx) ir_if(operand(r0A80).val);
      exec_list *const f0A7F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A7F->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A82 = equal(r0A79, body.constant(int(2047)));
         ir_expression *const r0A83 = bit_or(r0A78, swizzle_x(r0A72));
         ir_expression *const r0A84 = expr(ir_unop_u2i, r0A83);
         ir_expression *const r0A85 = expr(ir_unop_i2b, r0A84);
         ir_expression *const r0A86 = logic_and(r0A82, r0A85);
         ir_if *f0A81 = new(mem_ctx) ir_if(operand(r0A86).val);
         exec_list *const f0A81_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A81->then_instructions;

            body.emit(assign(r0A76, body.constant(0u), 0x01));


         body.instructions = f0A81_parent_instructions;
         body.emit(f0A81);

         /* END IF */

         ir_variable *const r0A87 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A89 = expr(ir_unop_u2i, r0A76);
         ir_expression *const r0A8A = expr(ir_unop_i2b, r0A89);
         ir_if *f0A88 = new(mem_ctx) ir_if(operand(r0A8A).val);
         exec_list *const f0A88_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A88->then_instructions;

            body.emit(assign(r0A87, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A88->else_instructions;

            body.emit(assign(r0A87, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A88_parent_instructions;
         body.emit(f0A88);

         /* END IF */

         body.emit(assign(r0A74, r0A87, 0x01));

         body.emit(assign(r0A73, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A7F->else_instructions;

         ir_variable *const r0A8B = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r0A8B, bit_or(r0A78, body.constant(1048576u)), 0x01));

         ir_expression *const r0A8C = equal(r0A7C, body.constant(int(0)));
         ir_expression *const r0A8D = lshift(r0A8B, r0A7C);
         ir_expression *const r0A8E = neg(r0A7C);
         ir_expression *const r0A8F = bit_and(r0A8E, body.constant(int(31)));
         ir_expression *const r0A90 = rshift(swizzle_x(r0A72), r0A8F);
         ir_expression *const r0A91 = bit_or(r0A8D, r0A90);
         body.emit(assign(r0A75, expr(ir_triop_csel, r0A8C, r0A8B, r0A91), 0x01));


      body.instructions = f0A7F_parent_instructions;
      body.emit(f0A7F);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A7D->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A93 = less(r0A79, body.constant(int(1023)));
      ir_if *f0A92 = new(mem_ctx) ir_if(operand(r0A93).val);
      exec_list *const f0A92_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A92->then_instructions;

         body.emit(assign(r0A74, body.constant(int(0)), 0x01));

         body.emit(assign(r0A73, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A92->else_instructions;

         body.emit(assign(r0A77, bit_or(r0A78, body.constant(1048576u)), 0x01));

         ir_expression *const r0A94 = neg(r0A7C);
         body.emit(assign(r0A75, rshift(r0A77, r0A94), 0x01));


      body.instructions = f0A92_parent_instructions;
      body.emit(f0A92);

      /* END IF */


   body.instructions = f0A7D_parent_instructions;
   body.emit(f0A7D);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0A95 = new(mem_ctx) ir_if(operand(r0A73).val);
   exec_list *const f0A95_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A95->then_instructions;

      ir_variable *const r0A96 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A98 = nequal(r0A76, body.constant(0u));
      ir_if *f0A97 = new(mem_ctx) ir_if(operand(r0A98).val);
      exec_list *const f0A97_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A97->then_instructions;

         ir_expression *const r0A99 = expr(ir_unop_u2i, r0A75);
         body.emit(assign(r0A96, neg(r0A99), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A97->else_instructions;

         body.emit(assign(r0A96, expr(ir_unop_u2i, r0A75), 0x01));


      body.instructions = f0A97_parent_instructions;
      body.emit(f0A97);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0A9B = less(r0A96, body.constant(int(0)));
      ir_expression *const r0A9C = expr(ir_unop_b2i, r0A9B);
      ir_expression *const r0A9D = expr(ir_unop_i2u, r0A9C);
      ir_expression *const r0A9E = bit_xor(r0A76, r0A9D);
      ir_expression *const r0A9F = expr(ir_unop_u2i, r0A9E);
      ir_expression *const r0AA0 = expr(ir_unop_i2b, r0A9F);
      ir_expression *const r0AA1 = expr(ir_unop_i2b, r0A96);
      ir_expression *const r0AA2 = logic_and(r0AA0, r0AA1);
      ir_if *f0A9A = new(mem_ctx) ir_if(operand(r0AA2).val);
      exec_list *const f0A9A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A9A->then_instructions;

         ir_variable *const r0AA3 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0AA5 = expr(ir_unop_u2i, r0A76);
         ir_expression *const r0AA6 = expr(ir_unop_i2b, r0AA5);
         ir_if *f0AA4 = new(mem_ctx) ir_if(operand(r0AA6).val);
         exec_list *const f0AA4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA4->then_instructions;

            body.emit(assign(r0AA3, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AA4->else_instructions;

            body.emit(assign(r0AA3, body.constant(int(2147483647)), 0x01));


         body.instructions = f0AA4_parent_instructions;
         body.emit(f0AA4);

         /* END IF */

         body.emit(assign(r0A74, r0AA3, 0x01));

         body.emit(assign(r0A73, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A9A->else_instructions;

         body.emit(assign(r0A74, r0A96, 0x01));

         body.emit(assign(r0A73, body.constant(false), 0x01));


      body.instructions = f0A9A_parent_instructions;
      body.emit(f0A9A);

      /* END IF */


   body.instructions = f0A95_parent_instructions;
   body.emit(f0A95);

   /* END IF */

   body.emit(ret(r0A74));

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

   ir_variable *const r0AA7 = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AA7);
   ir_variable *const r0AA8 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0AA9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0AA9);
   ir_variable *const r0AAA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0AAA);
   ir_variable *const r0AAB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0AAB);
   body.emit(assign(r0AAB, body.constant(0u), 0x01));

   body.emit(assign(r0AAA, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AAD = equal(r0AA7, body.constant(int(0)));
   ir_if *f0AAC = new(mem_ctx) ir_if(operand(r0AAD).val);
   exec_list *const f0AAC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AAC->then_instructions;

      ir_variable *const r0AAE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0AAE);
      body.emit(assign(r0AAE, body.constant(0u), 0x02));

      body.emit(assign(r0AAE, body.constant(0u), 0x01));

      body.emit(assign(r0AA8, r0AAE, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AAC->else_instructions;

      ir_expression *const r0AAF = less(r0AA7, body.constant(int(0)));
      ir_expression *const r0AB0 = expr(ir_unop_b2i, r0AAF);
      body.emit(assign(r0AA9, expr(ir_unop_i2u, r0AB0), 0x01));

      ir_variable *const r0AB1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0AB3 = less(r0AA7, body.constant(int(0)));
      ir_if *f0AB2 = new(mem_ctx) ir_if(operand(r0AB3).val);
      exec_list *const f0AB2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AB2->then_instructions;

         ir_expression *const r0AB4 = neg(r0AA7);
         body.emit(assign(r0AB1, expr(ir_unop_i2u, r0AB4), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AB2->else_instructions;

         body.emit(assign(r0AB1, expr(ir_unop_i2u, r0AA7), 0x01));


      body.instructions = f0AB2_parent_instructions;
      body.emit(f0AB2);

      /* END IF */

      ir_variable *const r0AB5 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0AB5, r0AB1, 0x01));

      ir_variable *const r0AB6 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0AB7 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0AB7);
      /* IF CONDITION */
      ir_expression *const r0AB9 = equal(r0AB1, body.constant(0u));
      ir_if *f0AB8 = new(mem_ctx) ir_if(operand(r0AB9).val);
      exec_list *const f0AB8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AB8->then_instructions;

         body.emit(assign(r0AB6, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AB8->else_instructions;

         body.emit(assign(r0AB7, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0ABB = bit_and(r0AB1, body.constant(4294901760u));
         ir_expression *const r0ABC = equal(r0ABB, body.constant(0u));
         ir_if *f0ABA = new(mem_ctx) ir_if(operand(r0ABC).val);
         exec_list *const f0ABA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ABA->then_instructions;

            body.emit(assign(r0AB7, body.constant(int(16)), 0x01));

            body.emit(assign(r0AB5, lshift(r0AB1, body.constant(int(16))), 0x01));


         body.instructions = f0ABA_parent_instructions;
         body.emit(f0ABA);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0ABE = bit_and(r0AB5, body.constant(4278190080u));
         ir_expression *const r0ABF = equal(r0ABE, body.constant(0u));
         ir_if *f0ABD = new(mem_ctx) ir_if(operand(r0ABF).val);
         exec_list *const f0ABD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ABD->then_instructions;

            body.emit(assign(r0AB7, add(r0AB7, body.constant(int(8))), 0x01));

            body.emit(assign(r0AB5, lshift(r0AB5, body.constant(int(8))), 0x01));


         body.instructions = f0ABD_parent_instructions;
         body.emit(f0ABD);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AC1 = bit_and(r0AB5, body.constant(4026531840u));
         ir_expression *const r0AC2 = equal(r0AC1, body.constant(0u));
         ir_if *f0AC0 = new(mem_ctx) ir_if(operand(r0AC2).val);
         exec_list *const f0AC0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AC0->then_instructions;

            body.emit(assign(r0AB7, add(r0AB7, body.constant(int(4))), 0x01));

            body.emit(assign(r0AB5, lshift(r0AB5, body.constant(int(4))), 0x01));


         body.instructions = f0AC0_parent_instructions;
         body.emit(f0AC0);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AC4 = bit_and(r0AB5, body.constant(3221225472u));
         ir_expression *const r0AC5 = equal(r0AC4, body.constant(0u));
         ir_if *f0AC3 = new(mem_ctx) ir_if(operand(r0AC5).val);
         exec_list *const f0AC3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AC3->then_instructions;

            body.emit(assign(r0AB7, add(r0AB7, body.constant(int(2))), 0x01));

            body.emit(assign(r0AB5, lshift(r0AB5, body.constant(int(2))), 0x01));


         body.instructions = f0AC3_parent_instructions;
         body.emit(f0AC3);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AC7 = bit_and(r0AB5, body.constant(2147483648u));
         ir_expression *const r0AC8 = equal(r0AC7, body.constant(0u));
         ir_if *f0AC6 = new(mem_ctx) ir_if(operand(r0AC8).val);
         exec_list *const f0AC6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AC6->then_instructions;

            body.emit(assign(r0AB7, add(r0AB7, body.constant(int(1))), 0x01));


         body.instructions = f0AC6_parent_instructions;
         body.emit(f0AC6);

         /* END IF */

         body.emit(assign(r0AB6, r0AB7, 0x01));


      body.instructions = f0AB8_parent_instructions;
      body.emit(f0AB8);

      /* END IF */

      ir_variable *const r0AC9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0AC9, add(r0AB6, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0ACB = gequal(r0AC9, body.constant(int(0)));
      ir_if *f0ACA = new(mem_ctx) ir_if(operand(r0ACB).val);
      exec_list *const f0ACA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0ACA->then_instructions;

         body.emit(assign(r0AAB, lshift(r0AB1, r0AC9), 0x01));

         body.emit(assign(r0AAA, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0ACA->else_instructions;

         ir_variable *const r0ACC = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r0ACC, neg(r0AC9), 0x01));

         ir_expression *const r0ACD = equal(r0ACC, body.constant(int(0)));
         ir_expression *const r0ACE = less(r0ACC, body.constant(int(32)));
         ir_expression *const r0ACF = rshift(r0AB1, r0ACC);
         ir_expression *const r0AD0 = expr(ir_triop_csel, r0ACE, r0ACF, body.constant(0u));
         body.emit(assign(r0AAB, expr(ir_triop_csel, r0ACD, r0AB1, r0AD0), 0x01));

         ir_expression *const r0AD1 = equal(r0ACC, body.constant(int(0)));
         ir_expression *const r0AD2 = less(r0ACC, body.constant(int(32)));
         ir_expression *const r0AD3 = neg(r0ACC);
         ir_expression *const r0AD4 = bit_and(r0AD3, body.constant(int(31)));
         ir_expression *const r0AD5 = lshift(r0AB1, r0AD4);
         ir_expression *const r0AD6 = bit_or(r0AD5, body.constant(0u));
         ir_expression *const r0AD7 = less(r0ACC, body.constant(int(64)));
         ir_expression *const r0AD8 = bit_and(r0ACC, body.constant(int(31)));
         ir_expression *const r0AD9 = rshift(r0AB1, r0AD8);
         ir_expression *const r0ADA = expr(ir_triop_csel, r0AD7, r0AD9, body.constant(0u));
         ir_expression *const r0ADB = expr(ir_triop_csel, r0AD2, r0AD6, r0ADA);
         body.emit(assign(r0AAA, expr(ir_triop_csel, r0AD1, r0AB1, r0ADB), 0x01));


      body.instructions = f0ACA_parent_instructions;
      body.emit(f0ACA);

      /* END IF */

      ir_variable *const r0ADC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0ADC);
      ir_expression *const r0ADD = lshift(r0AA9, body.constant(int(31)));
      ir_expression *const r0ADE = sub(body.constant(int(1042)), r0AC9);
      ir_expression *const r0ADF = expr(ir_unop_i2u, r0ADE);
      ir_expression *const r0AE0 = lshift(r0ADF, body.constant(int(20)));
      ir_expression *const r0AE1 = add(r0ADD, r0AE0);
      body.emit(assign(r0ADC, add(r0AE1, r0AAB), 0x02));

      body.emit(assign(r0ADC, r0AAA, 0x01));

      body.emit(assign(r0AA8, r0ADC, 0x03));


   body.instructions = f0AAC_parent_instructions;
   body.emit(f0AAC);

   /* END IF */

   body.emit(ret(r0AA8));

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

   ir_variable *const r0AE2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AE2);
   ir_variable *const r0AE3 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AE3);
   ir_variable *const r0AE4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AE4);
   ir_variable *const r0AE5 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r0AE6 = lshift(r0AE2, body.constant(int(31)));
   ir_expression *const r0AE7 = expr(ir_unop_i2u, r0AE3);
   ir_expression *const r0AE8 = lshift(r0AE7, body.constant(int(23)));
   ir_expression *const r0AE9 = add(r0AE6, r0AE8);
   ir_expression *const r0AEA = add(r0AE9, r0AE4);
   body.emit(assign(r0AE5, expr(ir_unop_bitcast_u2f, r0AEA), 0x01));

   body.emit(ret(r0AE5));

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

   ir_variable *const r0AEB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AEB);
   ir_variable *const r0AEC = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AEC);
   ir_variable *const r0AED = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AED);
   ir_variable *const r0AEE = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0AEE, body.constant(true), 0x01));

   ir_variable *const r0AEF = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0AF0 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0AF0);
   ir_expression *const r0AF1 = bit_and(r0AED, body.constant(127u));
   body.emit(assign(r0AF0, expr(ir_unop_u2i, r0AF1), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AF3 = expr(ir_unop_i2u, r0AEC);
   ir_expression *const r0AF4 = gequal(r0AF3, body.constant(253u));
   ir_if *f0AF2 = new(mem_ctx) ir_if(operand(r0AF4).val);
   exec_list *const f0AF2_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AF2->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0AF6 = less(body.constant(int(253)), r0AEC);
      ir_expression *const r0AF7 = equal(r0AEC, body.constant(int(253)));
      ir_expression *const r0AF8 = expr(ir_unop_u2i, r0AED);
      ir_expression *const r0AF9 = less(r0AF8, body.constant(int(-64)));
      ir_expression *const r0AFA = logic_and(r0AF7, r0AF9);
      ir_expression *const r0AFB = logic_or(r0AF6, r0AFA);
      ir_if *f0AF5 = new(mem_ctx) ir_if(operand(r0AFB).val);
      exec_list *const f0AF5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AF5->then_instructions;

         ir_expression *const r0AFC = lshift(r0AEB, body.constant(int(31)));
         ir_expression *const r0AFD = add(r0AFC, body.constant(2139095040u));
         body.emit(assign(r0AEF, expr(ir_unop_bitcast_u2f, r0AFD), 0x01));

         body.emit(assign(r0AEE, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AF5->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0AFF = less(r0AEC, body.constant(int(0)));
         ir_if *f0AFE = new(mem_ctx) ir_if(operand(r0AFF).val);
         exec_list *const f0AFE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AFE->then_instructions;

            ir_variable *const r0B00 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B00, neg(r0AEC), 0x01));

            /* IF CONDITION */
            ir_expression *const r0B02 = less(r0B00, body.constant(int(32)));
            ir_if *f0B01 = new(mem_ctx) ir_if(operand(r0B02).val);
            exec_list *const f0B01_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B01->then_instructions;

               ir_expression *const r0B03 = rshift(r0AED, r0B00);
               ir_expression *const r0B04 = neg(r0B00);
               ir_expression *const r0B05 = bit_and(r0B04, body.constant(int(31)));
               ir_expression *const r0B06 = lshift(r0AED, r0B05);
               ir_expression *const r0B07 = nequal(r0B06, body.constant(0u));
               ir_expression *const r0B08 = expr(ir_unop_b2i, r0B07);
               ir_expression *const r0B09 = expr(ir_unop_i2u, r0B08);
               body.emit(assign(r0AED, bit_or(r0B03, r0B09), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0B01->else_instructions;

               ir_expression *const r0B0A = nequal(r0AED, body.constant(0u));
               ir_expression *const r0B0B = expr(ir_unop_b2i, r0B0A);
               body.emit(assign(r0AED, expr(ir_unop_i2u, r0B0B), 0x01));


            body.instructions = f0B01_parent_instructions;
            body.emit(f0B01);

            /* END IF */

            body.emit(assign(r0AEC, body.constant(int(0)), 0x01));

            ir_expression *const r0B0C = expr(ir_unop_u2i, r0AED);
            body.emit(assign(r0AF0, bit_and(r0B0C, body.constant(int(127))), 0x01));


         body.instructions = f0AFE_parent_instructions;
         body.emit(f0AFE);

         /* END IF */


      body.instructions = f0AF5_parent_instructions;
      body.emit(f0AF5);

      /* END IF */


   body.instructions = f0AF2_parent_instructions;
   body.emit(f0AF2);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0B0D = new(mem_ctx) ir_if(operand(r0AEE).val);
   exec_list *const f0B0D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B0D->then_instructions;

      ir_expression *const r0B0E = add(r0AED, body.constant(64u));
      body.emit(assign(r0AED, rshift(r0B0E, body.constant(int(7))), 0x01));

      ir_expression *const r0B0F = bit_xor(r0AF0, body.constant(int(64)));
      ir_expression *const r0B10 = equal(r0B0F, body.constant(int(0)));
      ir_expression *const r0B11 = expr(ir_unop_b2i, r0B10);
      ir_expression *const r0B12 = expr(ir_unop_i2u, r0B11);
      ir_expression *const r0B13 = expr(ir_unop_bit_not, r0B12);
      body.emit(assign(r0AED, bit_and(r0AED, r0B13), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B15 = equal(r0AED, body.constant(0u));
      ir_if *f0B14 = new(mem_ctx) ir_if(operand(r0B15).val);
      exec_list *const f0B14_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B14->then_instructions;

         body.emit(assign(r0AEC, body.constant(int(0)), 0x01));


      body.instructions = f0B14_parent_instructions;
      body.emit(f0B14);

      /* END IF */

      ir_expression *const r0B16 = lshift(r0AEB, body.constant(int(31)));
      ir_expression *const r0B17 = expr(ir_unop_i2u, r0AEC);
      ir_expression *const r0B18 = lshift(r0B17, body.constant(int(23)));
      ir_expression *const r0B19 = add(r0B16, r0B18);
      ir_expression *const r0B1A = add(r0B19, r0AED);
      body.emit(assign(r0AEF, expr(ir_unop_bitcast_u2f, r0B1A), 0x01));

      body.emit(assign(r0AEE, body.constant(false), 0x01));


   body.instructions = f0B0D_parent_instructions;
   body.emit(f0B0D);

   /* END IF */

   body.emit(ret(r0AEF));

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

   ir_variable *const r0B1B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B1B);
   ir_variable *const r0B1C = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B1D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0B1D);
   body.emit(assign(r0B1D, body.constant(0u), 0x01));

   ir_variable *const r0B1E = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0B1E, swizzle_x(r0B1B), 0x01));

   ir_variable *const r0B1F = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B1F, bit_and(swizzle_y(r0B1B), body.constant(1048575u)), 0x01));

   ir_variable *const r0B20 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B21 = rshift(swizzle_y(r0B1B), body.constant(int(20)));
   ir_expression *const r0B22 = bit_and(r0B21, body.constant(2047u));
   body.emit(assign(r0B20, expr(ir_unop_u2i, r0B22), 0x01));

   ir_variable *const r0B23 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B23, rshift(swizzle_y(r0B1B), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B25 = equal(r0B20, body.constant(int(2047)));
   ir_if *f0B24 = new(mem_ctx) ir_if(operand(r0B25).val);
   exec_list *const f0B24_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B24->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B27 = bit_or(r0B1F, swizzle_x(r0B1B));
      ir_expression *const r0B28 = nequal(r0B27, body.constant(0u));
      ir_if *f0B26 = new(mem_ctx) ir_if(operand(r0B28).val);
      exec_list *const f0B26_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B26->then_instructions;

         ir_variable *const r0B29 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0B29, lshift(swizzle_x(r0B1B), body.constant(int(12))), 0x01));

         ir_expression *const r0B2A = lshift(swizzle_y(r0B1B), body.constant(int(12)));
         ir_expression *const r0B2B = rshift(swizzle_x(r0B1B), body.constant(int(20)));
         body.emit(assign(r0B1B, bit_or(r0B2A, r0B2B), 0x02));

         body.emit(assign(r0B1B, r0B29, 0x01));

         ir_expression *const r0B2C = lshift(r0B23, body.constant(int(31)));
         ir_expression *const r0B2D = bit_or(r0B2C, body.constant(2143289344u));
         ir_expression *const r0B2E = rshift(swizzle_y(r0B1B), body.constant(int(9)));
         ir_expression *const r0B2F = bit_or(r0B2D, r0B2E);
         body.emit(assign(r0B1C, expr(ir_unop_bitcast_u2f, r0B2F), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B26->else_instructions;

         ir_expression *const r0B30 = lshift(r0B23, body.constant(int(31)));
         ir_expression *const r0B31 = add(r0B30, body.constant(2139095040u));
         body.emit(assign(r0B1C, expr(ir_unop_bitcast_u2f, r0B31), 0x01));


      body.instructions = f0B26_parent_instructions;
      body.emit(f0B26);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B24->else_instructions;

      ir_variable *const r0B32 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B32);
      ir_variable *const r0B33 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0B33, rshift(r0B1F, body.constant(int(22))), 0x01));

      ir_expression *const r0B34 = lshift(r0B1F, body.constant(int(10)));
      ir_expression *const r0B35 = rshift(r0B1E, body.constant(int(22)));
      ir_expression *const r0B36 = bit_or(r0B34, r0B35);
      ir_expression *const r0B37 = lshift(r0B1E, body.constant(int(10)));
      ir_expression *const r0B38 = nequal(r0B37, body.constant(0u));
      ir_expression *const r0B39 = expr(ir_unop_b2i, r0B38);
      ir_expression *const r0B3A = expr(ir_unop_i2u, r0B39);
      body.emit(assign(r0B32, bit_or(r0B36, r0B3A), 0x01));

      body.emit(assign(r0B1D, r0B32, 0x01));

      /* IF CONDITION */
      ir_expression *const r0B3C = nequal(r0B20, body.constant(int(0)));
      ir_if *f0B3B = new(mem_ctx) ir_if(operand(r0B3C).val);
      exec_list *const f0B3B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B3B->then_instructions;

         body.emit(assign(r0B1D, bit_or(r0B32, body.constant(1073741824u)), 0x01));


      body.instructions = f0B3B_parent_instructions;
      body.emit(f0B3B);

      /* END IF */

      ir_variable *const r0B3D = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B3D, add(r0B20, body.constant(int(-897))), 0x01));

      ir_variable *const r0B3E = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B3E, r0B1D, 0x01));

      ir_variable *const r0B3F = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B3F, body.constant(true), 0x01));

      ir_variable *const r0B40 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B41 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B41);
      ir_expression *const r0B42 = bit_and(r0B1D, body.constant(127u));
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
         ir_expression *const r0B49 = expr(ir_unop_u2i, r0B1D);
         ir_expression *const r0B4A = less(r0B49, body.constant(int(-64)));
         ir_expression *const r0B4B = logic_and(r0B48, r0B4A);
         ir_expression *const r0B4C = logic_or(r0B47, r0B4B);
         ir_if *f0B46 = new(mem_ctx) ir_if(operand(r0B4C).val);
         exec_list *const f0B46_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B46->then_instructions;

            ir_expression *const r0B4D = lshift(r0B23, body.constant(int(31)));
            ir_expression *const r0B4E = add(r0B4D, body.constant(2139095040u));
            body.emit(assign(r0B40, expr(ir_unop_bitcast_u2f, r0B4E), 0x01));

            body.emit(assign(r0B3F, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B46->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0B50 = less(r0B3D, body.constant(int(0)));
            ir_if *f0B4F = new(mem_ctx) ir_if(operand(r0B50).val);
            exec_list *const f0B4F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B4F->then_instructions;

               ir_variable *const r0B51 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0B51, neg(r0B3D), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B53 = less(r0B51, body.constant(int(32)));
               ir_if *f0B52 = new(mem_ctx) ir_if(operand(r0B53).val);
               exec_list *const f0B52_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B52->then_instructions;

                  ir_expression *const r0B54 = rshift(r0B1D, r0B51);
                  ir_expression *const r0B55 = neg(r0B51);
                  ir_expression *const r0B56 = bit_and(r0B55, body.constant(int(31)));
                  ir_expression *const r0B57 = lshift(r0B1D, r0B56);
                  ir_expression *const r0B58 = nequal(r0B57, body.constant(0u));
                  ir_expression *const r0B59 = expr(ir_unop_b2i, r0B58);
                  ir_expression *const r0B5A = expr(ir_unop_i2u, r0B59);
                  body.emit(assign(r0B3E, bit_or(r0B54, r0B5A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0B52->else_instructions;

                  ir_expression *const r0B5B = nequal(r0B3E, body.constant(0u));
                  ir_expression *const r0B5C = expr(ir_unop_b2i, r0B5B);
                  body.emit(assign(r0B3E, expr(ir_unop_i2u, r0B5C), 0x01));


               body.instructions = f0B52_parent_instructions;
               body.emit(f0B52);

               /* END IF */

               body.emit(assign(r0B3D, body.constant(int(0)), 0x01));

               ir_expression *const r0B5D = expr(ir_unop_u2i, r0B3E);
               body.emit(assign(r0B41, bit_and(r0B5D, body.constant(int(127))), 0x01));


            body.instructions = f0B4F_parent_instructions;
            body.emit(f0B4F);

            /* END IF */


         body.instructions = f0B46_parent_instructions;
         body.emit(f0B46);

         /* END IF */


      body.instructions = f0B43_parent_instructions;
      body.emit(f0B43);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B5E = new(mem_ctx) ir_if(operand(r0B3F).val);
      exec_list *const f0B5E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B5E->then_instructions;

         ir_expression *const r0B5F = add(r0B3E, body.constant(64u));
         body.emit(assign(r0B3E, rshift(r0B5F, body.constant(int(7))), 0x01));

         ir_expression *const r0B60 = bit_xor(r0B41, body.constant(int(64)));
         ir_expression *const r0B61 = equal(r0B60, body.constant(int(0)));
         ir_expression *const r0B62 = expr(ir_unop_b2i, r0B61);
         ir_expression *const r0B63 = expr(ir_unop_i2u, r0B62);
         ir_expression *const r0B64 = expr(ir_unop_bit_not, r0B63);
         body.emit(assign(r0B3E, bit_and(r0B3E, r0B64), 0x01));

         /* IF CONDITION */
         ir_expression *const r0B66 = equal(r0B3E, body.constant(0u));
         ir_if *f0B65 = new(mem_ctx) ir_if(operand(r0B66).val);
         exec_list *const f0B65_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B65->then_instructions;

            body.emit(assign(r0B3D, body.constant(int(0)), 0x01));


         body.instructions = f0B65_parent_instructions;
         body.emit(f0B65);

         /* END IF */

         ir_expression *const r0B67 = lshift(r0B23, body.constant(int(31)));
         ir_expression *const r0B68 = expr(ir_unop_i2u, r0B3D);
         ir_expression *const r0B69 = lshift(r0B68, body.constant(int(23)));
         ir_expression *const r0B6A = add(r0B67, r0B69);
         ir_expression *const r0B6B = add(r0B6A, r0B3E);
         body.emit(assign(r0B40, expr(ir_unop_bitcast_u2f, r0B6B), 0x01));

         body.emit(assign(r0B3F, body.constant(false), 0x01));


      body.instructions = f0B5E_parent_instructions;
      body.emit(f0B5E);

      /* END IF */

      body.emit(assign(r0B1C, r0B40, 0x01));


   body.instructions = f0B24_parent_instructions;
   body.emit(f0B24);

   /* END IF */

   body.emit(ret(r0B1C));

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

   ir_variable *const r0B6C = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0B6C);
   ir_variable *const r0B6D = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B6D, body.constant(true), 0x01));

   ir_variable *const r0B6E = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B6F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B6F);
   ir_variable *const r0B70 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B70);
   ir_variable *const r0B71 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B71);
   ir_variable *const r0B72 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0B72, expr(ir_unop_bitcast_f2u, r0B6C), 0x01));

   ir_variable *const r0B73 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B73, bit_and(r0B72, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B71, r0B73, 0x01));

   ir_variable *const r0B74 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B75 = rshift(r0B72, body.constant(int(23)));
   ir_expression *const r0B76 = bit_and(r0B75, body.constant(255u));
   body.emit(assign(r0B74, expr(ir_unop_u2i, r0B76), 0x01));

   body.emit(assign(r0B70, r0B74, 0x01));

   body.emit(assign(r0B6F, rshift(r0B72, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B78 = equal(r0B74, body.constant(int(255)));
   ir_if *f0B77 = new(mem_ctx) ir_if(operand(r0B78).val);
   exec_list *const f0B77_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B77->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B7A = nequal(r0B73, body.constant(0u));
      ir_if *f0B79 = new(mem_ctx) ir_if(operand(r0B7A).val);
      exec_list *const f0B79_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B79->then_instructions;

         ir_variable *const r0B7B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B7B, lshift(r0B72, body.constant(int(9))), 0x01));

         ir_variable *const r0B7C = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B7D = lshift(r0B7B, body.constant(int(20)));
         body.emit(assign(r0B7C, bit_or(r0B7D, body.constant(0u)), 0x01));

         ir_expression *const r0B7E = rshift(r0B7B, body.constant(int(12)));
         ir_expression *const r0B7F = lshift(r0B6F, body.constant(int(31)));
         ir_expression *const r0B80 = bit_or(r0B7F, body.constant(2146959360u));
         body.emit(assign(r0B7C, bit_or(r0B7E, r0B80), 0x02));

         body.emit(assign(r0B6E, r0B7C, 0x03));

         body.emit(assign(r0B6D, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B79->else_instructions;

         ir_variable *const r0B81 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B81);
         ir_expression *const r0B82 = lshift(r0B6F, body.constant(int(31)));
         body.emit(assign(r0B81, add(r0B82, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B81, body.constant(0u), 0x01));

         body.emit(assign(r0B6E, r0B81, 0x03));

         body.emit(assign(r0B6D, body.constant(false), 0x01));


      body.instructions = f0B79_parent_instructions;
      body.emit(f0B79);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B77->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B84 = equal(r0B74, body.constant(int(0)));
      ir_if *f0B83 = new(mem_ctx) ir_if(operand(r0B84).val);
      exec_list *const f0B83_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B83->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B86 = equal(r0B73, body.constant(0u));
         ir_if *f0B85 = new(mem_ctx) ir_if(operand(r0B86).val);
         exec_list *const f0B85_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B85->then_instructions;

            ir_variable *const r0B87 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B87);
            body.emit(assign(r0B87, lshift(r0B6F, body.constant(int(31))), 0x02));

            body.emit(assign(r0B87, body.constant(0u), 0x01));

            body.emit(assign(r0B6E, r0B87, 0x03));

            body.emit(assign(r0B6D, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B85->else_instructions;

            ir_variable *const r0B88 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0B88, r0B73, 0x01));

            ir_variable *const r0B89 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0B8A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0B8A);
            /* IF CONDITION */
            ir_expression *const r0B8C = equal(r0B73, body.constant(0u));
            ir_if *f0B8B = new(mem_ctx) ir_if(operand(r0B8C).val);
            exec_list *const f0B8B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B8B->then_instructions;

               body.emit(assign(r0B89, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0B8B->else_instructions;

               body.emit(assign(r0B8A, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B8E = bit_and(r0B73, body.constant(4294901760u));
               ir_expression *const r0B8F = equal(r0B8E, body.constant(0u));
               ir_if *f0B8D = new(mem_ctx) ir_if(operand(r0B8F).val);
               exec_list *const f0B8D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B8D->then_instructions;

                  body.emit(assign(r0B8A, body.constant(int(16)), 0x01));

                  body.emit(assign(r0B88, lshift(r0B73, body.constant(int(16))), 0x01));


               body.instructions = f0B8D_parent_instructions;
               body.emit(f0B8D);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B91 = bit_and(r0B88, body.constant(4278190080u));
               ir_expression *const r0B92 = equal(r0B91, body.constant(0u));
               ir_if *f0B90 = new(mem_ctx) ir_if(operand(r0B92).val);
               exec_list *const f0B90_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B90->then_instructions;

                  body.emit(assign(r0B8A, add(r0B8A, body.constant(int(8))), 0x01));

                  body.emit(assign(r0B88, lshift(r0B88, body.constant(int(8))), 0x01));


               body.instructions = f0B90_parent_instructions;
               body.emit(f0B90);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B94 = bit_and(r0B88, body.constant(4026531840u));
               ir_expression *const r0B95 = equal(r0B94, body.constant(0u));
               ir_if *f0B93 = new(mem_ctx) ir_if(operand(r0B95).val);
               exec_list *const f0B93_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B93->then_instructions;

                  body.emit(assign(r0B8A, add(r0B8A, body.constant(int(4))), 0x01));

                  body.emit(assign(r0B88, lshift(r0B88, body.constant(int(4))), 0x01));


               body.instructions = f0B93_parent_instructions;
               body.emit(f0B93);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B97 = bit_and(r0B88, body.constant(3221225472u));
               ir_expression *const r0B98 = equal(r0B97, body.constant(0u));
               ir_if *f0B96 = new(mem_ctx) ir_if(operand(r0B98).val);
               exec_list *const f0B96_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B96->then_instructions;

                  body.emit(assign(r0B8A, add(r0B8A, body.constant(int(2))), 0x01));

                  body.emit(assign(r0B88, lshift(r0B88, body.constant(int(2))), 0x01));


               body.instructions = f0B96_parent_instructions;
               body.emit(f0B96);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B9A = bit_and(r0B88, body.constant(2147483648u));
               ir_expression *const r0B9B = equal(r0B9A, body.constant(0u));
               ir_if *f0B99 = new(mem_ctx) ir_if(operand(r0B9B).val);
               exec_list *const f0B99_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B99->then_instructions;

                  body.emit(assign(r0B8A, add(r0B8A, body.constant(int(1))), 0x01));


               body.instructions = f0B99_parent_instructions;
               body.emit(f0B99);

               /* END IF */

               body.emit(assign(r0B89, r0B8A, 0x01));


            body.instructions = f0B8B_parent_instructions;
            body.emit(f0B8B);

            /* END IF */

            ir_variable *const r0B9C = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B9C, add(r0B89, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B71, lshift(r0B73, r0B9C), 0x01));

            body.emit(assign(r0B70, sub(body.constant(int(1)), r0B9C), 0x01));

            body.emit(assign(r0B70, add(r0B70, body.constant(int(-1))), 0x01));


         body.instructions = f0B85_parent_instructions;
         body.emit(f0B85);

         /* END IF */


      body.instructions = f0B83_parent_instructions;
      body.emit(f0B83);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B9D = new(mem_ctx) ir_if(operand(r0B6D).val);
      exec_list *const f0B9D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B9D->then_instructions;

         ir_variable *const r0B9E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B9E);
         ir_expression *const r0B9F = lshift(r0B6F, body.constant(int(31)));
         ir_expression *const r0BA0 = add(r0B70, body.constant(int(896)));
         ir_expression *const r0BA1 = expr(ir_unop_i2u, r0BA0);
         ir_expression *const r0BA2 = lshift(r0BA1, body.constant(int(20)));
         ir_expression *const r0BA3 = add(r0B9F, r0BA2);
         ir_expression *const r0BA4 = rshift(r0B71, body.constant(int(3)));
         body.emit(assign(r0B9E, add(r0BA3, r0BA4), 0x02));

         ir_expression *const r0BA5 = lshift(r0B71, body.constant(int(29)));
         body.emit(assign(r0B9E, bit_or(r0BA5, body.constant(0u)), 0x01));

         body.emit(assign(r0B6E, r0B9E, 0x03));

         body.emit(assign(r0B6D, body.constant(false), 0x01));


      body.instructions = f0B9D_parent_instructions;
      body.emit(f0B9D);

      /* END IF */


   body.instructions = f0B77_parent_instructions;
   body.emit(f0B77);

   /* END IF */

   body.emit(ret(r0B6E));

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

   ir_variable *const r0BA6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BA6);
   ir_variable *const r0BA7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BA7);
   ir_variable *const r0BA8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0BA8);
   ir_variable *const r0BA9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0BA9);
   ir_variable *const r0BAA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0BAA);
   ir_variable *const r0BAB = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0BAB);
   ir_variable *const r0BAC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BAC);
   ir_variable *const r0BAD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BAD);
   ir_variable *const r0BAE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BAE);
   ir_variable *const r0BAF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0BAF);
   ir_variable *const r0BB0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0BB0);
   ir_variable *const r0BB1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BB1, add(r0BA8, r0BAB), 0x01));

   ir_variable *const r0BB2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0BB3 = less(r0BB1, r0BA8);
   ir_expression *const r0BB4 = expr(ir_unop_b2i, r0BB3);
   body.emit(assign(r0BB2, expr(ir_unop_i2u, r0BB4), 0x01));

   ir_variable *const r0BB5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BB5, add(r0BA7, r0BAA), 0x01));

   body.emit(assign(r0BB0, add(r0BB5, r0BB2), 0x01));

   ir_expression *const r0BB6 = add(r0BA6, r0BA9);
   ir_expression *const r0BB7 = less(r0BB0, r0BB2);
   ir_expression *const r0BB8 = expr(ir_unop_b2i, r0BB7);
   ir_expression *const r0BB9 = expr(ir_unop_i2u, r0BB8);
   body.emit(assign(r0BAF, add(r0BB6, r0BB9), 0x01));

   ir_expression *const r0BBA = less(r0BB5, r0BA7);
   ir_expression *const r0BBB = expr(ir_unop_b2i, r0BBA);
   ir_expression *const r0BBC = expr(ir_unop_i2u, r0BBB);
   body.emit(assign(r0BAF, add(r0BAF, r0BBC), 0x01));

   body.emit(assign(r0BAE, r0BB1, 0x01));

   body.emit(assign(r0BAD, r0BB0, 0x01));

   body.emit(assign(r0BAC, r0BAF, 0x01));

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

   ir_variable *const r0BBD = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BBD);
   ir_variable *const r0BBE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BBE);
   ir_variable *const r0BBF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0BBF);
   ir_variable *const r0BC0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0BC0);
   ir_variable *const r0BC1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0BC1);
   ir_variable *const r0BC2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0BC2);
   ir_variable *const r0BC3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BC3);
   ir_variable *const r0BC4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BC4);
   ir_variable *const r0BC5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BC5);
   ir_variable *const r0BC6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0BC6);
   ir_variable *const r0BC7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0BC8 = less(r0BBF, r0BC2);
   ir_expression *const r0BC9 = expr(ir_unop_b2i, r0BC8);
   body.emit(assign(r0BC7, expr(ir_unop_i2u, r0BC9), 0x01));

   ir_variable *const r0BCA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BCA, sub(r0BBE, r0BC1), 0x01));

   ir_expression *const r0BCB = sub(r0BBD, r0BC0);
   ir_expression *const r0BCC = less(r0BCA, r0BC7);
   ir_expression *const r0BCD = expr(ir_unop_b2i, r0BCC);
   ir_expression *const r0BCE = expr(ir_unop_i2u, r0BCD);
   body.emit(assign(r0BC6, sub(r0BCB, r0BCE), 0x01));

   ir_expression *const r0BCF = less(r0BBE, r0BC1);
   ir_expression *const r0BD0 = expr(ir_unop_b2i, r0BCF);
   ir_expression *const r0BD1 = expr(ir_unop_i2u, r0BD0);
   body.emit(assign(r0BC6, sub(r0BC6, r0BD1), 0x01));

   body.emit(assign(r0BC5, sub(r0BBF, r0BC2), 0x01));

   body.emit(assign(r0BC4, sub(r0BCA, r0BC7), 0x01));

   body.emit(assign(r0BC3, r0BC6, 0x01));

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

   ir_variable *const r0BD2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BD2);
   ir_variable *const r0BD3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BD3);
   ir_variable *const r0BD4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0BD4);
   ir_variable *const r0BD5 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0BD6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0BD6);
   ir_variable *const r0BD7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0BD7);
   ir_variable *const r0BD8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0BD8);
   ir_variable *const r0BD9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0BD9);
   body.emit(assign(r0BD8, body.constant(0u), 0x01));

   body.emit(assign(r0BD7, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BDB = gequal(r0BD2, r0BD4);
   ir_if *f0BDA = new(mem_ctx) ir_if(operand(r0BDB).val);
   exec_list *const f0BDA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BDA->then_instructions;

      body.emit(assign(r0BD5, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BDA->else_instructions;

      body.emit(assign(r0BD9, rshift(r0BD4, body.constant(int(16))), 0x01));

      ir_variable *const r0BDC = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BDE = lshift(r0BD9, body.constant(int(16)));
      ir_expression *const r0BDF = gequal(r0BD2, r0BDE);
      ir_if *f0BDD = new(mem_ctx) ir_if(operand(r0BDF).val);
      exec_list *const f0BDD_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BDD->then_instructions;

         body.emit(assign(r0BDC, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BDD->else_instructions;

         ir_expression *const r0BE0 = expr(ir_binop_div, r0BD2, r0BD9);
         body.emit(assign(r0BDC, lshift(r0BE0, body.constant(int(16))), 0x01));


      body.instructions = f0BDD_parent_instructions;
      body.emit(f0BDD);

      /* END IF */

      body.emit(assign(r0BD6, r0BDC, 0x01));

      ir_variable *const r0BE1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0BE1);
      ir_variable *const r0BE2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0BE2);
      ir_variable *const r0BE3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BE3);
      ir_variable *const r0BE4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BE4, bit_and(r0BD4, body.constant(65535u)), 0x01));

      ir_variable *const r0BE5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BE5, rshift(r0BD4, body.constant(int(16))), 0x01));

      ir_variable *const r0BE6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BE6, bit_and(r0BDC, body.constant(65535u)), 0x01));

      ir_variable *const r0BE7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BE7, rshift(r0BDC, body.constant(int(16))), 0x01));

      ir_variable *const r0BE8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BE8, mul(r0BE5, r0BE6), 0x01));

      ir_expression *const r0BE9 = mul(r0BE4, r0BE7);
      body.emit(assign(r0BE2, add(r0BE9, r0BE8), 0x01));

      ir_expression *const r0BEA = mul(r0BE5, r0BE7);
      ir_expression *const r0BEB = less(r0BE2, r0BE8);
      ir_expression *const r0BEC = expr(ir_unop_b2i, r0BEB);
      ir_expression *const r0BED = expr(ir_unop_i2u, r0BEC);
      ir_expression *const r0BEE = lshift(r0BED, body.constant(int(16)));
      ir_expression *const r0BEF = rshift(r0BE2, body.constant(int(16)));
      ir_expression *const r0BF0 = add(r0BEE, r0BEF);
      body.emit(assign(r0BE1, add(r0BEA, r0BF0), 0x01));

      body.emit(assign(r0BE2, lshift(r0BE2, body.constant(int(16))), 0x01));

      ir_expression *const r0BF1 = mul(r0BE4, r0BE6);
      body.emit(assign(r0BE3, add(r0BF1, r0BE2), 0x01));

      ir_expression *const r0BF2 = less(r0BE3, r0BE2);
      ir_expression *const r0BF3 = expr(ir_unop_b2i, r0BF2);
      ir_expression *const r0BF4 = expr(ir_unop_i2u, r0BF3);
      body.emit(assign(r0BE1, add(r0BE1, r0BF4), 0x01));

      ir_expression *const r0BF5 = sub(r0BD2, r0BE1);
      ir_expression *const r0BF6 = less(r0BD3, r0BE3);
      ir_expression *const r0BF7 = expr(ir_unop_b2i, r0BF6);
      ir_expression *const r0BF8 = expr(ir_unop_i2u, r0BF7);
      body.emit(assign(r0BD8, sub(r0BF5, r0BF8), 0x01));

      body.emit(assign(r0BD7, sub(r0BD3, r0BE3), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0BF9 = new(mem_ctx) ir_loop();
      exec_list *const f0BF9_parent_instructions = body.instructions;

         body.instructions = &f0BF9->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0BFB = expr(ir_unop_u2i, r0BD8);
         ir_expression *const r0BFC = gequal(r0BFB, body.constant(int(0)));
         ir_if *f0BFA = new(mem_ctx) ir_if(operand(r0BFC).val);
         exec_list *const f0BFA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BFA->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0BFA_parent_instructions;
         body.emit(f0BFA);

         /* END IF */

         body.emit(assign(r0BD6, add(r0BD6, body.constant(4294901760u)), 0x01));

         ir_variable *const r0BFD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0BFE = lshift(r0BD4, body.constant(int(16)));
         body.emit(assign(r0BFD, add(r0BD7, r0BFE), 0x01));

         ir_expression *const r0BFF = add(r0BD8, r0BD9);
         ir_expression *const r0C00 = less(r0BFD, r0BD7);
         ir_expression *const r0C01 = expr(ir_unop_b2i, r0C00);
         ir_expression *const r0C02 = expr(ir_unop_i2u, r0C01);
         body.emit(assign(r0BD8, add(r0BFF, r0C02), 0x01));

         body.emit(assign(r0BD7, r0BFD, 0x01));

      /* LOOP END */

      body.instructions = f0BF9_parent_instructions;
      body.emit(f0BF9);

      ir_expression *const r0C03 = lshift(r0BD8, body.constant(int(16)));
      ir_expression *const r0C04 = rshift(r0BD7, body.constant(int(16)));
      body.emit(assign(r0BD8, bit_or(r0C03, r0C04), 0x01));

      ir_variable *const r0C05 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0C07 = lshift(r0BD9, body.constant(int(16)));
      ir_expression *const r0C08 = gequal(r0BD8, r0C07);
      ir_if *f0C06 = new(mem_ctx) ir_if(operand(r0C08).val);
      exec_list *const f0C06_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C06->then_instructions;

         body.emit(assign(r0C05, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C06->else_instructions;

         body.emit(assign(r0C05, expr(ir_binop_div, r0BD8, r0BD9), 0x01));


      body.instructions = f0C06_parent_instructions;
      body.emit(f0C06);

      /* END IF */

      body.emit(assign(r0BD6, bit_or(r0BD6, r0C05), 0x01));

      body.emit(assign(r0BD5, r0BD6, 0x01));


   body.instructions = f0BDA_parent_instructions;
   body.emit(f0BDA);

   /* END IF */

   body.emit(ret(r0BD5));

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

   ir_variable *const r0C09 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C09);
   ir_variable *const r0C0A = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0C0A, r0C09, 0x03));

   ir_variable *const r0C0B = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0C0C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0C0C);
   body.emit(assign(r0C0C, body.constant(0u), 0x01));

   ir_variable *const r0C0D = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0C0D, bit_and(swizzle_y(r0C09), body.constant(1048575u)), 0x01));

   ir_variable *const r0C0E = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0C0F = rshift(swizzle_y(r0C09), body.constant(int(20)));
   ir_expression *const r0C10 = bit_and(r0C0F, body.constant(2047u));
   body.emit(assign(r0C0E, expr(ir_unop_u2i, r0C10), 0x01));

   ir_variable *const r0C11 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0C11, rshift(swizzle_y(r0C09), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C13 = equal(r0C0E, body.constant(int(2047)));
   ir_if *f0C12 = new(mem_ctx) ir_if(operand(r0C13).val);
   exec_list *const f0C12_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C12->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C15 = bit_or(r0C0D, swizzle_x(r0C09));
      ir_expression *const r0C16 = nequal(r0C15, body.constant(0u));
      ir_if *f0C14 = new(mem_ctx) ir_if(operand(r0C16).val);
      exec_list *const f0C14_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C14->then_instructions;

         ir_expression *const r0C17 = lshift(swizzle_y(r0C09), body.constant(int(12)));
         ir_expression *const r0C18 = rshift(swizzle_x(r0C09), body.constant(int(20)));
         body.emit(assign(r0C0A, bit_or(r0C17, r0C18), 0x02));

         body.emit(assign(r0C0A, lshift(swizzle_x(r0C09), body.constant(int(12))), 0x01));

         ir_expression *const r0C19 = lshift(r0C11, body.constant(int(31)));
         ir_expression *const r0C1A = bit_or(r0C19, body.constant(2143289344u));
         ir_expression *const r0C1B = rshift(swizzle_y(r0C0A), body.constant(int(9)));
         ir_expression *const r0C1C = bit_or(r0C1A, r0C1B);
         body.emit(assign(r0C0B, expr(ir_unop_bitcast_u2f, r0C1C), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C14->else_instructions;

         ir_expression *const r0C1D = lshift(r0C11, body.constant(int(31)));
         ir_expression *const r0C1E = add(r0C1D, body.constant(2139095040u));
         body.emit(assign(r0C0B, expr(ir_unop_bitcast_u2f, r0C1E), 0x01));


      body.instructions = f0C14_parent_instructions;
      body.emit(f0C14);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C12->else_instructions;

      ir_variable *const r0C1F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0C1F);
      ir_variable *const r0C20 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0C20, rshift(r0C0D, body.constant(int(22))), 0x01));

      ir_expression *const r0C21 = lshift(r0C0D, body.constant(int(10)));
      ir_expression *const r0C22 = rshift(swizzle_x(r0C09), body.constant(int(22)));
      ir_expression *const r0C23 = bit_or(r0C21, r0C22);
      ir_expression *const r0C24 = lshift(swizzle_x(r0C09), body.constant(int(10)));
      ir_expression *const r0C25 = nequal(r0C24, body.constant(0u));
      ir_expression *const r0C26 = expr(ir_unop_b2i, r0C25);
      ir_expression *const r0C27 = expr(ir_unop_i2u, r0C26);
      body.emit(assign(r0C1F, bit_or(r0C23, r0C27), 0x01));

      body.emit(assign(r0C0C, r0C1F, 0x01));

      /* IF CONDITION */
      ir_expression *const r0C29 = nequal(r0C0E, body.constant(int(0)));
      ir_if *f0C28 = new(mem_ctx) ir_if(operand(r0C29).val);
      exec_list *const f0C28_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C28->then_instructions;

         body.emit(assign(r0C0C, bit_or(r0C1F, body.constant(1073741824u)), 0x01));


      body.instructions = f0C28_parent_instructions;
      body.emit(f0C28);

      /* END IF */

      ir_variable *const r0C2A = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0C2A, add(r0C0E, body.constant(int(-897))), 0x01));

      ir_variable *const r0C2B = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0C2B, r0C0C, 0x01));

      ir_variable *const r0C2C = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0C2C, body.constant(true), 0x01));

      ir_variable *const r0C2D = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0C2E = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0C2E);
      ir_expression *const r0C2F = bit_and(r0C0C, body.constant(127u));
      body.emit(assign(r0C2E, expr(ir_unop_u2i, r0C2F), 0x01));

      /* IF CONDITION */
      ir_expression *const r0C31 = expr(ir_unop_i2u, r0C2A);
      ir_expression *const r0C32 = gequal(r0C31, body.constant(253u));
      ir_if *f0C30 = new(mem_ctx) ir_if(operand(r0C32).val);
      exec_list *const f0C30_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C30->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C34 = less(body.constant(int(253)), r0C2A);
         ir_expression *const r0C35 = equal(r0C2A, body.constant(int(253)));
         ir_expression *const r0C36 = expr(ir_unop_u2i, r0C0C);
         ir_expression *const r0C37 = less(r0C36, body.constant(int(-64)));
         ir_expression *const r0C38 = logic_and(r0C35, r0C37);
         ir_expression *const r0C39 = logic_or(r0C34, r0C38);
         ir_if *f0C33 = new(mem_ctx) ir_if(operand(r0C39).val);
         exec_list *const f0C33_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C33->then_instructions;

            ir_expression *const r0C3A = lshift(r0C11, body.constant(int(31)));
            ir_expression *const r0C3B = add(r0C3A, body.constant(2139095040u));
            body.emit(assign(r0C2D, expr(ir_unop_bitcast_u2f, r0C3B), 0x01));

            body.emit(assign(r0C2C, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C33->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0C3D = less(r0C2A, body.constant(int(0)));
            ir_if *f0C3C = new(mem_ctx) ir_if(operand(r0C3D).val);
            exec_list *const f0C3C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C3C->then_instructions;

               ir_variable *const r0C3E = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0C3E, neg(r0C2A), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C40 = less(r0C3E, body.constant(int(32)));
               ir_if *f0C3F = new(mem_ctx) ir_if(operand(r0C40).val);
               exec_list *const f0C3F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C3F->then_instructions;

                  ir_expression *const r0C41 = rshift(r0C0C, r0C3E);
                  ir_expression *const r0C42 = neg(r0C3E);
                  ir_expression *const r0C43 = bit_and(r0C42, body.constant(int(31)));
                  ir_expression *const r0C44 = lshift(r0C0C, r0C43);
                  ir_expression *const r0C45 = nequal(r0C44, body.constant(0u));
                  ir_expression *const r0C46 = expr(ir_unop_b2i, r0C45);
                  ir_expression *const r0C47 = expr(ir_unop_i2u, r0C46);
                  body.emit(assign(r0C2B, bit_or(r0C41, r0C47), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0C3F->else_instructions;

                  ir_expression *const r0C48 = nequal(r0C2B, body.constant(0u));
                  ir_expression *const r0C49 = expr(ir_unop_b2i, r0C48);
                  body.emit(assign(r0C2B, expr(ir_unop_i2u, r0C49), 0x01));


               body.instructions = f0C3F_parent_instructions;
               body.emit(f0C3F);

               /* END IF */

               body.emit(assign(r0C2A, body.constant(int(0)), 0x01));

               ir_expression *const r0C4A = expr(ir_unop_u2i, r0C2B);
               body.emit(assign(r0C2E, bit_and(r0C4A, body.constant(int(127))), 0x01));


            body.instructions = f0C3C_parent_instructions;
            body.emit(f0C3C);

            /* END IF */


         body.instructions = f0C33_parent_instructions;
         body.emit(f0C33);

         /* END IF */


      body.instructions = f0C30_parent_instructions;
      body.emit(f0C30);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C4B = new(mem_ctx) ir_if(operand(r0C2C).val);
      exec_list *const f0C4B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C4B->then_instructions;

         ir_expression *const r0C4C = add(r0C2B, body.constant(64u));
         body.emit(assign(r0C2B, rshift(r0C4C, body.constant(int(7))), 0x01));

         ir_expression *const r0C4D = bit_xor(r0C2E, body.constant(int(64)));
         ir_expression *const r0C4E = equal(r0C4D, body.constant(int(0)));
         ir_expression *const r0C4F = expr(ir_unop_b2i, r0C4E);
         ir_expression *const r0C50 = expr(ir_unop_i2u, r0C4F);
         ir_expression *const r0C51 = expr(ir_unop_bit_not, r0C50);
         body.emit(assign(r0C2B, bit_and(r0C2B, r0C51), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C53 = equal(r0C2B, body.constant(0u));
         ir_if *f0C52 = new(mem_ctx) ir_if(operand(r0C53).val);
         exec_list *const f0C52_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C52->then_instructions;

            body.emit(assign(r0C2A, body.constant(int(0)), 0x01));


         body.instructions = f0C52_parent_instructions;
         body.emit(f0C52);

         /* END IF */

         ir_expression *const r0C54 = lshift(r0C11, body.constant(int(31)));
         ir_expression *const r0C55 = expr(ir_unop_i2u, r0C2A);
         ir_expression *const r0C56 = lshift(r0C55, body.constant(int(23)));
         ir_expression *const r0C57 = add(r0C54, r0C56);
         ir_expression *const r0C58 = add(r0C57, r0C2B);
         body.emit(assign(r0C2D, expr(ir_unop_bitcast_u2f, r0C58), 0x01));

         body.emit(assign(r0C2C, body.constant(false), 0x01));


      body.instructions = f0C4B_parent_instructions;
      body.emit(f0C4B);

      /* END IF */

      body.emit(assign(r0C0B, r0C2D, 0x01));


   body.instructions = f0C12_parent_instructions;
   body.emit(f0C12);

   /* END IF */

   ir_variable *const r0C59 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C59, body.constant(true), 0x01));

   ir_variable *const r0C5A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C5B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C5B);
   ir_variable *const r0C5C = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C5C);
   ir_variable *const r0C5D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C5D);
   ir_variable *const r0C5E = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C5F = expr(ir_unop_sqrt, r0C0B);
   body.emit(assign(r0C5E, expr(ir_unop_bitcast_f2u, r0C5F), 0x01));

   ir_variable *const r0C60 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C60, bit_and(r0C5E, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C5D, r0C60, 0x01));

   ir_variable *const r0C61 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C62 = rshift(r0C5E, body.constant(int(23)));
   ir_expression *const r0C63 = bit_and(r0C62, body.constant(255u));
   body.emit(assign(r0C61, expr(ir_unop_u2i, r0C63), 0x01));

   body.emit(assign(r0C5C, r0C61, 0x01));

   body.emit(assign(r0C5B, rshift(r0C5E, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C65 = equal(r0C61, body.constant(int(255)));
   ir_if *f0C64 = new(mem_ctx) ir_if(operand(r0C65).val);
   exec_list *const f0C64_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C64->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C67 = nequal(r0C60, body.constant(0u));
      ir_if *f0C66 = new(mem_ctx) ir_if(operand(r0C67).val);
      exec_list *const f0C66_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C66->then_instructions;

         ir_variable *const r0C68 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C68, lshift(r0C5E, body.constant(int(9))), 0x01));

         ir_variable *const r0C69 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C6A = lshift(r0C68, body.constant(int(20)));
         body.emit(assign(r0C69, bit_or(r0C6A, body.constant(0u)), 0x01));

         ir_expression *const r0C6B = rshift(r0C68, body.constant(int(12)));
         ir_expression *const r0C6C = lshift(r0C5B, body.constant(int(31)));
         ir_expression *const r0C6D = bit_or(r0C6C, body.constant(2146959360u));
         body.emit(assign(r0C69, bit_or(r0C6B, r0C6D), 0x02));

         body.emit(assign(r0C5A, r0C69, 0x03));

         body.emit(assign(r0C59, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C66->else_instructions;

         ir_variable *const r0C6E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C6E);
         ir_expression *const r0C6F = lshift(r0C5B, body.constant(int(31)));
         body.emit(assign(r0C6E, add(r0C6F, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C6E, body.constant(0u), 0x01));

         body.emit(assign(r0C5A, r0C6E, 0x03));

         body.emit(assign(r0C59, body.constant(false), 0x01));


      body.instructions = f0C66_parent_instructions;
      body.emit(f0C66);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C64->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C71 = equal(r0C61, body.constant(int(0)));
      ir_if *f0C70 = new(mem_ctx) ir_if(operand(r0C71).val);
      exec_list *const f0C70_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C70->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C73 = equal(r0C60, body.constant(0u));
         ir_if *f0C72 = new(mem_ctx) ir_if(operand(r0C73).val);
         exec_list *const f0C72_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C72->then_instructions;

            ir_variable *const r0C74 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C74);
            body.emit(assign(r0C74, lshift(r0C5B, body.constant(int(31))), 0x02));

            body.emit(assign(r0C74, body.constant(0u), 0x01));

            body.emit(assign(r0C5A, r0C74, 0x03));

            body.emit(assign(r0C59, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C72->else_instructions;

            ir_variable *const r0C75 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0C75, r0C60, 0x01));

            ir_variable *const r0C76 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0C77 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0C77);
            /* IF CONDITION */
            ir_expression *const r0C79 = equal(r0C60, body.constant(0u));
            ir_if *f0C78 = new(mem_ctx) ir_if(operand(r0C79).val);
            exec_list *const f0C78_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C78->then_instructions;

               body.emit(assign(r0C76, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0C78->else_instructions;

               body.emit(assign(r0C77, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C7B = bit_and(r0C60, body.constant(4294901760u));
               ir_expression *const r0C7C = equal(r0C7B, body.constant(0u));
               ir_if *f0C7A = new(mem_ctx) ir_if(operand(r0C7C).val);
               exec_list *const f0C7A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C7A->then_instructions;

                  body.emit(assign(r0C77, body.constant(int(16)), 0x01));

                  body.emit(assign(r0C75, lshift(r0C60, body.constant(int(16))), 0x01));


               body.instructions = f0C7A_parent_instructions;
               body.emit(f0C7A);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C7E = bit_and(r0C75, body.constant(4278190080u));
               ir_expression *const r0C7F = equal(r0C7E, body.constant(0u));
               ir_if *f0C7D = new(mem_ctx) ir_if(operand(r0C7F).val);
               exec_list *const f0C7D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C7D->then_instructions;

                  body.emit(assign(r0C77, add(r0C77, body.constant(int(8))), 0x01));

                  body.emit(assign(r0C75, lshift(r0C75, body.constant(int(8))), 0x01));


               body.instructions = f0C7D_parent_instructions;
               body.emit(f0C7D);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C81 = bit_and(r0C75, body.constant(4026531840u));
               ir_expression *const r0C82 = equal(r0C81, body.constant(0u));
               ir_if *f0C80 = new(mem_ctx) ir_if(operand(r0C82).val);
               exec_list *const f0C80_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C80->then_instructions;

                  body.emit(assign(r0C77, add(r0C77, body.constant(int(4))), 0x01));

                  body.emit(assign(r0C75, lshift(r0C75, body.constant(int(4))), 0x01));


               body.instructions = f0C80_parent_instructions;
               body.emit(f0C80);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C84 = bit_and(r0C75, body.constant(3221225472u));
               ir_expression *const r0C85 = equal(r0C84, body.constant(0u));
               ir_if *f0C83 = new(mem_ctx) ir_if(operand(r0C85).val);
               exec_list *const f0C83_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C83->then_instructions;

                  body.emit(assign(r0C77, add(r0C77, body.constant(int(2))), 0x01));

                  body.emit(assign(r0C75, lshift(r0C75, body.constant(int(2))), 0x01));


               body.instructions = f0C83_parent_instructions;
               body.emit(f0C83);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C87 = bit_and(r0C75, body.constant(2147483648u));
               ir_expression *const r0C88 = equal(r0C87, body.constant(0u));
               ir_if *f0C86 = new(mem_ctx) ir_if(operand(r0C88).val);
               exec_list *const f0C86_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C86->then_instructions;

                  body.emit(assign(r0C77, add(r0C77, body.constant(int(1))), 0x01));


               body.instructions = f0C86_parent_instructions;
               body.emit(f0C86);

               /* END IF */

               body.emit(assign(r0C76, r0C77, 0x01));


            body.instructions = f0C78_parent_instructions;
            body.emit(f0C78);

            /* END IF */

            ir_variable *const r0C89 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0C89, add(r0C76, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C5D, lshift(r0C60, r0C89), 0x01));

            body.emit(assign(r0C5C, sub(body.constant(int(1)), r0C89), 0x01));

            body.emit(assign(r0C5C, add(r0C5C, body.constant(int(-1))), 0x01));


         body.instructions = f0C72_parent_instructions;
         body.emit(f0C72);

         /* END IF */


      body.instructions = f0C70_parent_instructions;
      body.emit(f0C70);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C8A = new(mem_ctx) ir_if(operand(r0C59).val);
      exec_list *const f0C8A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C8A->then_instructions;

         ir_variable *const r0C8B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C8B);
         ir_expression *const r0C8C = lshift(r0C5B, body.constant(int(31)));
         ir_expression *const r0C8D = add(r0C5C, body.constant(int(896)));
         ir_expression *const r0C8E = expr(ir_unop_i2u, r0C8D);
         ir_expression *const r0C8F = lshift(r0C8E, body.constant(int(20)));
         ir_expression *const r0C90 = add(r0C8C, r0C8F);
         ir_expression *const r0C91 = rshift(r0C5D, body.constant(int(3)));
         body.emit(assign(r0C8B, add(r0C90, r0C91), 0x02));

         ir_expression *const r0C92 = lshift(r0C5D, body.constant(int(29)));
         body.emit(assign(r0C8B, bit_or(r0C92, body.constant(0u)), 0x01));

         body.emit(assign(r0C5A, r0C8B, 0x03));

         body.emit(assign(r0C59, body.constant(false), 0x01));


      body.instructions = f0C8A_parent_instructions;
      body.emit(f0C8A);

      /* END IF */


   body.instructions = f0C64_parent_instructions;
   body.emit(f0C64);

   /* END IF */

   body.emit(ret(r0C5A));

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

   ir_variable *const r0C93 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C93);
   ir_variable *const r0C94 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C95 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C96 = rshift(swizzle_y(r0C93), body.constant(int(20)));
   ir_expression *const r0C97 = bit_and(r0C96, body.constant(2047u));
   ir_expression *const r0C98 = expr(ir_unop_u2i, r0C97);
   body.emit(assign(r0C95, add(r0C98, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C9A = less(r0C95, body.constant(int(0)));
   ir_if *f0C99 = new(mem_ctx) ir_if(operand(r0C9A).val);
   exec_list *const f0C99_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C99->then_instructions;

      body.emit(assign(r0C94, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C99->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C9C = less(body.constant(int(52)), r0C95);
      ir_if *f0C9B = new(mem_ctx) ir_if(operand(r0C9C).val);
      exec_list *const f0C9B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C9B->then_instructions;

         body.emit(assign(r0C94, r0C93, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C9B->else_instructions;

         ir_variable *const r0C9D = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0C9D, sub(body.constant(int(52)), r0C95), 0x01));

         ir_variable *const r0C9E = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0CA0 = gequal(r0C9D, body.constant(int(32)));
         ir_if *f0C9F = new(mem_ctx) ir_if(operand(r0CA0).val);
         exec_list *const f0C9F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C9F->then_instructions;

            body.emit(assign(r0C9E, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C9F->else_instructions;

            body.emit(assign(r0C9E, lshift(body.constant(4294967295u), r0C9D), 0x01));


         body.instructions = f0C9F_parent_instructions;
         body.emit(f0C9F);

         /* END IF */

         ir_variable *const r0CA1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0CA3 = less(r0C9D, body.constant(int(33)));
         ir_if *f0CA2 = new(mem_ctx) ir_if(operand(r0CA3).val);
         exec_list *const f0CA2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CA2->then_instructions;

            body.emit(assign(r0CA1, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CA2->else_instructions;

            ir_expression *const r0CA4 = add(r0C9D, body.constant(int(-32)));
            body.emit(assign(r0CA1, lshift(body.constant(4294967295u), r0CA4), 0x01));


         body.instructions = f0CA2_parent_instructions;
         body.emit(f0CA2);

         /* END IF */

         ir_variable *const r0CA5 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0CA5, bit_and(r0C9E, swizzle_x(r0C93)), 0x01));

         body.emit(assign(r0CA5, bit_and(r0CA1, swizzle_y(r0C93)), 0x02));

         body.emit(assign(r0C94, r0CA5, 0x03));


      body.instructions = f0C9B_parent_instructions;
      body.emit(f0C9B);

      /* END IF */


   body.instructions = f0C99_parent_instructions;
   body.emit(f0C99);

   /* END IF */

   body.emit(ret(r0C94));

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

   ir_variable *const r0CA6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CA6);
   ir_variable *const r0CA7 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0CA7, body.constant(true), 0x01));

   ir_variable *const r0CA8 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CA9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0CA9);
   ir_variable *const r0CAA = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0CAA);
   ir_variable *const r0CAB = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0CAC = rshift(swizzle_y(r0CA6), body.constant(int(20)));
   ir_expression *const r0CAD = bit_and(r0CAC, body.constant(2047u));
   ir_expression *const r0CAE = expr(ir_unop_u2i, r0CAD);
   body.emit(assign(r0CAB, add(r0CAE, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0CAA, swizzle_y(r0CA6), 0x01));

   body.emit(assign(r0CA9, swizzle_x(r0CA6), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CB0 = less(r0CAB, body.constant(int(20)));
   ir_if *f0CAF = new(mem_ctx) ir_if(operand(r0CB0).val);
   exec_list *const f0CAF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CAF->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CB2 = less(r0CAB, body.constant(int(0)));
      ir_if *f0CB1 = new(mem_ctx) ir_if(operand(r0CB2).val);
      exec_list *const f0CB1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CB1->then_instructions;

         body.emit(assign(r0CAA, bit_and(swizzle_y(r0CA6), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CB4 = equal(r0CAB, body.constant(int(-1)));
         ir_expression *const r0CB5 = nequal(swizzle_x(r0CA6), body.constant(0u));
         ir_expression *const r0CB6 = logic_and(r0CB4, r0CB5);
         ir_if *f0CB3 = new(mem_ctx) ir_if(operand(r0CB6).val);
         exec_list *const f0CB3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CB3->then_instructions;

            body.emit(assign(r0CAA, bit_or(r0CAA, body.constant(1072693248u)), 0x01));


         body.instructions = f0CB3_parent_instructions;
         body.emit(f0CB3);

         /* END IF */

         body.emit(assign(r0CA9, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CB1->else_instructions;

         ir_variable *const r0CB7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0CB7, rshift(body.constant(1048575u), r0CAB), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CB9 = bit_and(r0CAA, r0CB7);
         ir_expression *const r0CBA = equal(r0CB9, body.constant(0u));
         ir_expression *const r0CBB = equal(r0CA9, body.constant(0u));
         ir_expression *const r0CBC = logic_and(r0CBA, r0CBB);
         ir_if *f0CB8 = new(mem_ctx) ir_if(operand(r0CBC).val);
         exec_list *const f0CB8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CB8->then_instructions;

            body.emit(assign(r0CA8, r0CA6, 0x03));

            body.emit(assign(r0CA7, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CB8->else_instructions;

            ir_expression *const r0CBD = rshift(body.constant(524288u), r0CAB);
            body.emit(assign(r0CAA, add(r0CAA, r0CBD), 0x01));

            ir_expression *const r0CBE = expr(ir_unop_bit_not, r0CB7);
            body.emit(assign(r0CAA, bit_and(r0CAA, r0CBE), 0x01));

            body.emit(assign(r0CA9, body.constant(0u), 0x01));


         body.instructions = f0CB8_parent_instructions;
         body.emit(f0CB8);

         /* END IF */


      body.instructions = f0CB1_parent_instructions;
      body.emit(f0CB1);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CAF->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CC0 = less(body.constant(int(51)), r0CAB);
      ir_expression *const r0CC1 = equal(r0CAB, body.constant(int(1024)));
      ir_expression *const r0CC2 = logic_or(r0CC0, r0CC1);
      ir_if *f0CBF = new(mem_ctx) ir_if(operand(r0CC2).val);
      exec_list *const f0CBF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CBF->then_instructions;

         body.emit(assign(r0CA8, r0CA6, 0x03));

         body.emit(assign(r0CA7, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CBF->else_instructions;

         ir_variable *const r0CC3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0CC4 = add(r0CAB, body.constant(int(-20)));
         body.emit(assign(r0CC3, rshift(body.constant(4294967295u), r0CC4), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CC6 = bit_and(r0CA9, r0CC3);
         ir_expression *const r0CC7 = equal(r0CC6, body.constant(0u));
         ir_if *f0CC5 = new(mem_ctx) ir_if(operand(r0CC7).val);
         exec_list *const f0CC5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CC5->then_instructions;

            body.emit(assign(r0CA8, r0CA6, 0x03));

            body.emit(assign(r0CA7, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CC5->else_instructions;

            ir_variable *const r0CC8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0CC9 = sub(body.constant(int(51)), r0CAB);
            ir_expression *const r0CCA = lshift(body.constant(1u), r0CC9);
            body.emit(assign(r0CC8, add(r0CA9, r0CCA), 0x01));

            /* IF CONDITION */
            ir_expression *const r0CCC = less(r0CC8, r0CA9);
            ir_if *f0CCB = new(mem_ctx) ir_if(operand(r0CCC).val);
            exec_list *const f0CCB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0CCB->then_instructions;

               body.emit(assign(r0CAA, add(r0CAA, body.constant(1u)), 0x01));


            body.instructions = f0CCB_parent_instructions;
            body.emit(f0CCB);

            /* END IF */

            ir_expression *const r0CCD = expr(ir_unop_bit_not, r0CC3);
            body.emit(assign(r0CA9, bit_and(r0CC8, r0CCD), 0x01));


         body.instructions = f0CC5_parent_instructions;
         body.emit(f0CC5);

         /* END IF */


      body.instructions = f0CBF_parent_instructions;
      body.emit(f0CBF);

      /* END IF */


   body.instructions = f0CAF_parent_instructions;
   body.emit(f0CAF);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0CCE = new(mem_ctx) ir_if(operand(r0CA7).val);
   exec_list *const f0CCE_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CCE->then_instructions;

      body.emit(assign(r0CA6, r0CA9, 0x01));

      body.emit(assign(r0CA6, r0CAA, 0x02));

      body.emit(assign(r0CA8, r0CA6, 0x03));

      body.emit(assign(r0CA7, body.constant(false), 0x01));


   body.instructions = f0CCE_parent_instructions;
   body.emit(f0CCE);

   /* END IF */

   body.emit(ret(r0CA8));

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

   ir_variable *const r0CCF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CCF);
   ir_variable *const r0CD0 = body.make_temp(glsl_type::uvec2_type, "a");
   body.emit(assign(r0CD0, r0CCF, 0x03));

   ir_variable *const r0CD1 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0CD2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0CD2);
   body.emit(assign(r0CD2, body.constant(0u), 0x01));

   ir_variable *const r0CD3 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0CD3, bit_and(swizzle_y(r0CCF), body.constant(1048575u)), 0x01));

   ir_variable *const r0CD4 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0CD5 = rshift(swizzle_y(r0CCF), body.constant(int(20)));
   ir_expression *const r0CD6 = bit_and(r0CD5, body.constant(2047u));
   body.emit(assign(r0CD4, expr(ir_unop_u2i, r0CD6), 0x01));

   ir_variable *const r0CD7 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0CD7, rshift(swizzle_y(r0CCF), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CD9 = equal(r0CD4, body.constant(int(2047)));
   ir_if *f0CD8 = new(mem_ctx) ir_if(operand(r0CD9).val);
   exec_list *const f0CD8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CD8->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CDB = bit_or(r0CD3, swizzle_x(r0CCF));
      ir_expression *const r0CDC = nequal(r0CDB, body.constant(0u));
      ir_if *f0CDA = new(mem_ctx) ir_if(operand(r0CDC).val);
      exec_list *const f0CDA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CDA->then_instructions;

         ir_expression *const r0CDD = lshift(swizzle_y(r0CCF), body.constant(int(12)));
         ir_expression *const r0CDE = rshift(swizzle_x(r0CCF), body.constant(int(20)));
         body.emit(assign(r0CD0, bit_or(r0CDD, r0CDE), 0x02));

         body.emit(assign(r0CD0, lshift(swizzle_x(r0CCF), body.constant(int(12))), 0x01));

         ir_expression *const r0CDF = lshift(r0CD7, body.constant(int(31)));
         ir_expression *const r0CE0 = bit_or(r0CDF, body.constant(2143289344u));
         ir_expression *const r0CE1 = rshift(swizzle_y(r0CD0), body.constant(int(9)));
         ir_expression *const r0CE2 = bit_or(r0CE0, r0CE1);
         body.emit(assign(r0CD1, expr(ir_unop_bitcast_u2f, r0CE2), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CDA->else_instructions;

         ir_expression *const r0CE3 = lshift(r0CD7, body.constant(int(31)));
         ir_expression *const r0CE4 = add(r0CE3, body.constant(2139095040u));
         body.emit(assign(r0CD1, expr(ir_unop_bitcast_u2f, r0CE4), 0x01));


      body.instructions = f0CDA_parent_instructions;
      body.emit(f0CDA);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CD8->else_instructions;

      ir_variable *const r0CE5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0CE5);
      ir_variable *const r0CE6 = body.make_temp(glsl_type::uint_type, "mix_retval");
      body.emit(assign(r0CE6, rshift(r0CD3, body.constant(int(22))), 0x01));

      ir_expression *const r0CE7 = lshift(r0CD3, body.constant(int(10)));
      ir_expression *const r0CE8 = rshift(swizzle_x(r0CCF), body.constant(int(22)));
      ir_expression *const r0CE9 = bit_or(r0CE7, r0CE8);
      ir_expression *const r0CEA = lshift(swizzle_x(r0CCF), body.constant(int(10)));
      ir_expression *const r0CEB = nequal(r0CEA, body.constant(0u));
      ir_expression *const r0CEC = expr(ir_unop_b2i, r0CEB);
      ir_expression *const r0CED = expr(ir_unop_i2u, r0CEC);
      body.emit(assign(r0CE5, bit_or(r0CE9, r0CED), 0x01));

      body.emit(assign(r0CD2, r0CE5, 0x01));

      /* IF CONDITION */
      ir_expression *const r0CEF = nequal(r0CD4, body.constant(int(0)));
      ir_if *f0CEE = new(mem_ctx) ir_if(operand(r0CEF).val);
      exec_list *const f0CEE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CEE->then_instructions;

         body.emit(assign(r0CD2, bit_or(r0CE5, body.constant(1073741824u)), 0x01));


      body.instructions = f0CEE_parent_instructions;
      body.emit(f0CEE);

      /* END IF */

      ir_variable *const r0CF0 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0CF0, add(r0CD4, body.constant(int(-897))), 0x01));

      ir_variable *const r0CF1 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0CF1, r0CD2, 0x01));

      ir_variable *const r0CF2 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0CF2, body.constant(true), 0x01));

      ir_variable *const r0CF3 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0CF4 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0CF4);
      ir_expression *const r0CF5 = bit_and(r0CD2, body.constant(127u));
      body.emit(assign(r0CF4, expr(ir_unop_u2i, r0CF5), 0x01));

      /* IF CONDITION */
      ir_expression *const r0CF7 = expr(ir_unop_i2u, r0CF0);
      ir_expression *const r0CF8 = gequal(r0CF7, body.constant(253u));
      ir_if *f0CF6 = new(mem_ctx) ir_if(operand(r0CF8).val);
      exec_list *const f0CF6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CF6->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0CFA = less(body.constant(int(253)), r0CF0);
         ir_expression *const r0CFB = equal(r0CF0, body.constant(int(253)));
         ir_expression *const r0CFC = expr(ir_unop_u2i, r0CD2);
         ir_expression *const r0CFD = less(r0CFC, body.constant(int(-64)));
         ir_expression *const r0CFE = logic_and(r0CFB, r0CFD);
         ir_expression *const r0CFF = logic_or(r0CFA, r0CFE);
         ir_if *f0CF9 = new(mem_ctx) ir_if(operand(r0CFF).val);
         exec_list *const f0CF9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CF9->then_instructions;

            ir_expression *const r0D00 = lshift(r0CD7, body.constant(int(31)));
            ir_expression *const r0D01 = add(r0D00, body.constant(2139095040u));
            body.emit(assign(r0CF3, expr(ir_unop_bitcast_u2f, r0D01), 0x01));

            body.emit(assign(r0CF2, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CF9->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0D03 = less(r0CF0, body.constant(int(0)));
            ir_if *f0D02 = new(mem_ctx) ir_if(operand(r0D03).val);
            exec_list *const f0D02_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D02->then_instructions;

               ir_variable *const r0D04 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0D04, neg(r0CF0), 0x01));

               /* IF CONDITION */
               ir_expression *const r0D06 = less(r0D04, body.constant(int(32)));
               ir_if *f0D05 = new(mem_ctx) ir_if(operand(r0D06).val);
               exec_list *const f0D05_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D05->then_instructions;

                  ir_expression *const r0D07 = rshift(r0CD2, r0D04);
                  ir_expression *const r0D08 = neg(r0D04);
                  ir_expression *const r0D09 = bit_and(r0D08, body.constant(int(31)));
                  ir_expression *const r0D0A = lshift(r0CD2, r0D09);
                  ir_expression *const r0D0B = nequal(r0D0A, body.constant(0u));
                  ir_expression *const r0D0C = expr(ir_unop_b2i, r0D0B);
                  ir_expression *const r0D0D = expr(ir_unop_i2u, r0D0C);
                  body.emit(assign(r0CF1, bit_or(r0D07, r0D0D), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0D05->else_instructions;

                  ir_expression *const r0D0E = nequal(r0CF1, body.constant(0u));
                  ir_expression *const r0D0F = expr(ir_unop_b2i, r0D0E);
                  body.emit(assign(r0CF1, expr(ir_unop_i2u, r0D0F), 0x01));


               body.instructions = f0D05_parent_instructions;
               body.emit(f0D05);

               /* END IF */

               body.emit(assign(r0CF0, body.constant(int(0)), 0x01));

               ir_expression *const r0D10 = expr(ir_unop_u2i, r0CF1);
               body.emit(assign(r0CF4, bit_and(r0D10, body.constant(int(127))), 0x01));


            body.instructions = f0D02_parent_instructions;
            body.emit(f0D02);

            /* END IF */


         body.instructions = f0CF9_parent_instructions;
         body.emit(f0CF9);

         /* END IF */


      body.instructions = f0CF6_parent_instructions;
      body.emit(f0CF6);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0D11 = new(mem_ctx) ir_if(operand(r0CF2).val);
      exec_list *const f0D11_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D11->then_instructions;

         ir_expression *const r0D12 = add(r0CF1, body.constant(64u));
         body.emit(assign(r0CF1, rshift(r0D12, body.constant(int(7))), 0x01));

         ir_expression *const r0D13 = bit_xor(r0CF4, body.constant(int(64)));
         ir_expression *const r0D14 = equal(r0D13, body.constant(int(0)));
         ir_expression *const r0D15 = expr(ir_unop_b2i, r0D14);
         ir_expression *const r0D16 = expr(ir_unop_i2u, r0D15);
         ir_expression *const r0D17 = expr(ir_unop_bit_not, r0D16);
         body.emit(assign(r0CF1, bit_and(r0CF1, r0D17), 0x01));

         /* IF CONDITION */
         ir_expression *const r0D19 = equal(r0CF1, body.constant(0u));
         ir_if *f0D18 = new(mem_ctx) ir_if(operand(r0D19).val);
         exec_list *const f0D18_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D18->then_instructions;

            body.emit(assign(r0CF0, body.constant(int(0)), 0x01));


         body.instructions = f0D18_parent_instructions;
         body.emit(f0D18);

         /* END IF */

         ir_expression *const r0D1A = lshift(r0CD7, body.constant(int(31)));
         ir_expression *const r0D1B = expr(ir_unop_i2u, r0CF0);
         ir_expression *const r0D1C = lshift(r0D1B, body.constant(int(23)));
         ir_expression *const r0D1D = add(r0D1A, r0D1C);
         ir_expression *const r0D1E = add(r0D1D, r0CF1);
         body.emit(assign(r0CF3, expr(ir_unop_bitcast_u2f, r0D1E), 0x01));

         body.emit(assign(r0CF2, body.constant(false), 0x01));


      body.instructions = f0D11_parent_instructions;
      body.emit(f0D11);

      /* END IF */

      body.emit(assign(r0CD1, r0CF3, 0x01));


   body.instructions = f0CD8_parent_instructions;
   body.emit(f0CD8);

   /* END IF */

   ir_variable *const r0D1F = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0D1F, body.constant(true), 0x01));

   ir_variable *const r0D20 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0D21 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0D21);
   ir_variable *const r0D22 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0D22);
   ir_variable *const r0D23 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0D23);
   ir_variable *const r0D24 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0D25 = expr(ir_unop_rcp, r0CD1);
   body.emit(assign(r0D24, expr(ir_unop_bitcast_f2u, r0D25), 0x01));

   ir_variable *const r0D26 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0D26, bit_and(r0D24, body.constant(8388607u)), 0x01));

   body.emit(assign(r0D23, r0D26, 0x01));

   ir_variable *const r0D27 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0D28 = rshift(r0D24, body.constant(int(23)));
   ir_expression *const r0D29 = bit_and(r0D28, body.constant(255u));
   body.emit(assign(r0D27, expr(ir_unop_u2i, r0D29), 0x01));

   body.emit(assign(r0D22, r0D27, 0x01));

   body.emit(assign(r0D21, rshift(r0D24, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0D2B = equal(r0D27, body.constant(int(255)));
   ir_if *f0D2A = new(mem_ctx) ir_if(operand(r0D2B).val);
   exec_list *const f0D2A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D2A->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0D2D = nequal(r0D26, body.constant(0u));
      ir_if *f0D2C = new(mem_ctx) ir_if(operand(r0D2D).val);
      exec_list *const f0D2C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D2C->then_instructions;

         ir_variable *const r0D2E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0D2E, lshift(r0D24, body.constant(int(9))), 0x01));

         ir_variable *const r0D2F = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0D30 = lshift(r0D2E, body.constant(int(20)));
         body.emit(assign(r0D2F, bit_or(r0D30, body.constant(0u)), 0x01));

         ir_expression *const r0D31 = rshift(r0D2E, body.constant(int(12)));
         ir_expression *const r0D32 = lshift(r0D21, body.constant(int(31)));
         ir_expression *const r0D33 = bit_or(r0D32, body.constant(2146959360u));
         body.emit(assign(r0D2F, bit_or(r0D31, r0D33), 0x02));

         body.emit(assign(r0D20, r0D2F, 0x03));

         body.emit(assign(r0D1F, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D2C->else_instructions;

         ir_variable *const r0D34 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D34);
         ir_expression *const r0D35 = lshift(r0D21, body.constant(int(31)));
         body.emit(assign(r0D34, add(r0D35, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0D34, body.constant(0u), 0x01));

         body.emit(assign(r0D20, r0D34, 0x03));

         body.emit(assign(r0D1F, body.constant(false), 0x01));


      body.instructions = f0D2C_parent_instructions;
      body.emit(f0D2C);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0D2A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0D37 = equal(r0D27, body.constant(int(0)));
      ir_if *f0D36 = new(mem_ctx) ir_if(operand(r0D37).val);
      exec_list *const f0D36_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D36->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0D39 = equal(r0D26, body.constant(0u));
         ir_if *f0D38 = new(mem_ctx) ir_if(operand(r0D39).val);
         exec_list *const f0D38_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D38->then_instructions;

            ir_variable *const r0D3A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0D3A);
            body.emit(assign(r0D3A, lshift(r0D21, body.constant(int(31))), 0x02));

            body.emit(assign(r0D3A, body.constant(0u), 0x01));

            body.emit(assign(r0D20, r0D3A, 0x03));

            body.emit(assign(r0D1F, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D38->else_instructions;

            ir_variable *const r0D3B = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0D3B, r0D26, 0x01));

            ir_variable *const r0D3C = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0D3D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0D3D);
            /* IF CONDITION */
            ir_expression *const r0D3F = equal(r0D26, body.constant(0u));
            ir_if *f0D3E = new(mem_ctx) ir_if(operand(r0D3F).val);
            exec_list *const f0D3E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D3E->then_instructions;

               body.emit(assign(r0D3C, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0D3E->else_instructions;

               body.emit(assign(r0D3D, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0D41 = bit_and(r0D26, body.constant(4294901760u));
               ir_expression *const r0D42 = equal(r0D41, body.constant(0u));
               ir_if *f0D40 = new(mem_ctx) ir_if(operand(r0D42).val);
               exec_list *const f0D40_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D40->then_instructions;

                  body.emit(assign(r0D3D, body.constant(int(16)), 0x01));

                  body.emit(assign(r0D3B, lshift(r0D26, body.constant(int(16))), 0x01));


               body.instructions = f0D40_parent_instructions;
               body.emit(f0D40);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D44 = bit_and(r0D3B, body.constant(4278190080u));
               ir_expression *const r0D45 = equal(r0D44, body.constant(0u));
               ir_if *f0D43 = new(mem_ctx) ir_if(operand(r0D45).val);
               exec_list *const f0D43_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D43->then_instructions;

                  body.emit(assign(r0D3D, add(r0D3D, body.constant(int(8))), 0x01));

                  body.emit(assign(r0D3B, lshift(r0D3B, body.constant(int(8))), 0x01));


               body.instructions = f0D43_parent_instructions;
               body.emit(f0D43);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D47 = bit_and(r0D3B, body.constant(4026531840u));
               ir_expression *const r0D48 = equal(r0D47, body.constant(0u));
               ir_if *f0D46 = new(mem_ctx) ir_if(operand(r0D48).val);
               exec_list *const f0D46_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D46->then_instructions;

                  body.emit(assign(r0D3D, add(r0D3D, body.constant(int(4))), 0x01));

                  body.emit(assign(r0D3B, lshift(r0D3B, body.constant(int(4))), 0x01));


               body.instructions = f0D46_parent_instructions;
               body.emit(f0D46);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D4A = bit_and(r0D3B, body.constant(3221225472u));
               ir_expression *const r0D4B = equal(r0D4A, body.constant(0u));
               ir_if *f0D49 = new(mem_ctx) ir_if(operand(r0D4B).val);
               exec_list *const f0D49_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D49->then_instructions;

                  body.emit(assign(r0D3D, add(r0D3D, body.constant(int(2))), 0x01));

                  body.emit(assign(r0D3B, lshift(r0D3B, body.constant(int(2))), 0x01));


               body.instructions = f0D49_parent_instructions;
               body.emit(f0D49);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D4D = bit_and(r0D3B, body.constant(2147483648u));
               ir_expression *const r0D4E = equal(r0D4D, body.constant(0u));
               ir_if *f0D4C = new(mem_ctx) ir_if(operand(r0D4E).val);
               exec_list *const f0D4C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D4C->then_instructions;

                  body.emit(assign(r0D3D, add(r0D3D, body.constant(int(1))), 0x01));


               body.instructions = f0D4C_parent_instructions;
               body.emit(f0D4C);

               /* END IF */

               body.emit(assign(r0D3C, r0D3D, 0x01));


            body.instructions = f0D3E_parent_instructions;
            body.emit(f0D3E);

            /* END IF */

            ir_variable *const r0D4F = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0D4F, add(r0D3C, body.constant(int(-8))), 0x01));

            body.emit(assign(r0D23, lshift(r0D26, r0D4F), 0x01));

            body.emit(assign(r0D22, sub(body.constant(int(1)), r0D4F), 0x01));

            body.emit(assign(r0D22, add(r0D22, body.constant(int(-1))), 0x01));


         body.instructions = f0D38_parent_instructions;
         body.emit(f0D38);

         /* END IF */


      body.instructions = f0D36_parent_instructions;
      body.emit(f0D36);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0D50 = new(mem_ctx) ir_if(operand(r0D1F).val);
      exec_list *const f0D50_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D50->then_instructions;

         ir_variable *const r0D51 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D51);
         ir_expression *const r0D52 = lshift(r0D21, body.constant(int(31)));
         ir_expression *const r0D53 = add(r0D22, body.constant(int(896)));
         ir_expression *const r0D54 = expr(ir_unop_i2u, r0D53);
         ir_expression *const r0D55 = lshift(r0D54, body.constant(int(20)));
         ir_expression *const r0D56 = add(r0D52, r0D55);
         ir_expression *const r0D57 = rshift(r0D23, body.constant(int(3)));
         body.emit(assign(r0D51, add(r0D56, r0D57), 0x02));

         ir_expression *const r0D58 = lshift(r0D23, body.constant(int(29)));
         body.emit(assign(r0D51, bit_or(r0D58, body.constant(0u)), 0x01));

         body.emit(assign(r0D20, r0D51, 0x03));

         body.emit(assign(r0D1F, body.constant(false), 0x01));


      body.instructions = f0D50_parent_instructions;
      body.emit(f0D50);

      /* END IF */


   body.instructions = f0D2A_parent_instructions;
   body.emit(f0D2A);

   /* END IF */

   body.emit(ret(r0D20));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
