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
   ir_variable *const r0099 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0099);
   ir_variable *const r009A = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r009B = neg(r0095);
   body.emit(assign(r009A, bit_and(r009B, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r009D = equal(r0095, body.constant(int(0)));
   ir_if *f009C = new(mem_ctx) ir_if(operand(r009D).val);
   exec_list *const f009C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f009C->then_instructions;

      body.emit(assign(r0098, r0094, 0x01));

      body.emit(assign(r0099, r0093, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f009C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r009F = less(r0095, body.constant(int(32)));
      ir_if *f009E = new(mem_ctx) ir_if(operand(r009F).val);
      exec_list *const f009E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f009E->then_instructions;

         ir_expression *const r00A0 = lshift(r0093, r009A);
         ir_expression *const r00A1 = rshift(r0094, r0095);
         ir_expression *const r00A2 = bit_or(r00A0, r00A1);
         ir_expression *const r00A3 = lshift(r0094, r009A);
         ir_expression *const r00A4 = nequal(r00A3, body.constant(0u));
         ir_expression *const r00A5 = expr(ir_unop_b2i, r00A4);
         ir_expression *const r00A6 = expr(ir_unop_i2u, r00A5);
         body.emit(assign(r0098, bit_or(r00A2, r00A6), 0x01));

         body.emit(assign(r0099, rshift(r0093, r0095), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f009E->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00A8 = equal(r0095, body.constant(int(32)));
         ir_if *f00A7 = new(mem_ctx) ir_if(operand(r00A8).val);
         exec_list *const f00A7_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00A7->then_instructions;

            ir_expression *const r00A9 = nequal(r0094, body.constant(0u));
            ir_expression *const r00AA = expr(ir_unop_b2i, r00A9);
            ir_expression *const r00AB = expr(ir_unop_i2u, r00AA);
            body.emit(assign(r0098, bit_or(r0093, r00AB), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00A7->else_instructions;

            /* IF CONDITION */
            ir_expression *const r00AD = less(r0095, body.constant(int(64)));
            ir_if *f00AC = new(mem_ctx) ir_if(operand(r00AD).val);
            exec_list *const f00AC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f00AC->then_instructions;

               ir_expression *const r00AE = bit_and(r0095, body.constant(int(31)));
               ir_expression *const r00AF = rshift(r0093, r00AE);
               ir_expression *const r00B0 = lshift(r0093, r009A);
               ir_expression *const r00B1 = bit_or(r00B0, r0094);
               ir_expression *const r00B2 = nequal(r00B1, body.constant(0u));
               ir_expression *const r00B3 = expr(ir_unop_b2i, r00B2);
               ir_expression *const r00B4 = expr(ir_unop_i2u, r00B3);
               body.emit(assign(r0098, bit_or(r00AF, r00B4), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f00AC->else_instructions;

               ir_expression *const r00B5 = bit_or(r0093, r0094);
               ir_expression *const r00B6 = nequal(r00B5, body.constant(0u));
               ir_expression *const r00B7 = expr(ir_unop_b2i, r00B6);
               body.emit(assign(r0098, expr(ir_unop_i2u, r00B7), 0x01));


            body.instructions = f00AC_parent_instructions;
            body.emit(f00AC);

            /* END IF */


         body.instructions = f00A7_parent_instructions;
         body.emit(f00A7);

         /* END IF */

         body.emit(assign(r0099, body.constant(0u), 0x01));


      body.instructions = f009E_parent_instructions;
      body.emit(f009E);

      /* END IF */


   body.instructions = f009C_parent_instructions;
   body.emit(f009C);

   /* END IF */

   body.emit(assign(r0097, r0098, 0x01));

   body.emit(assign(r0096, r0099, 0x01));

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

   ir_variable *const r00B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00B8);
   ir_variable *const r00B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00B9);
   ir_variable *const r00BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r00BA);
   ir_variable *const r00BB = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00BB);
   ir_variable *const r00BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00BC);
   ir_variable *const r00BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00BD);
   ir_variable *const r00BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00BE);
   ir_variable *const r00BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
   body.emit(r00BF);
   ir_variable *const r00C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r00C0);
   ir_variable *const r00C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r00C1);
   ir_variable *const r00C2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r00C3 = neg(r00BB);
   body.emit(assign(r00C2, bit_and(r00C3, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00C5 = equal(r00BB, body.constant(int(0)));
   ir_if *f00C4 = new(mem_ctx) ir_if(operand(r00C5).val);
   exec_list *const f00C4_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00C4->then_instructions;

      body.emit(assign(r00BF, r00BA, 0x01));

      body.emit(assign(r00C0, r00B9, 0x01));

      body.emit(assign(r00C1, r00B8, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00C4->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00C7 = less(r00BB, body.constant(int(32)));
      ir_if *f00C6 = new(mem_ctx) ir_if(operand(r00C7).val);
      exec_list *const f00C6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00C6->then_instructions;

         body.emit(assign(r00BF, lshift(r00B9, r00C2), 0x01));

         ir_expression *const r00C8 = lshift(r00B8, r00C2);
         ir_expression *const r00C9 = rshift(r00B9, r00BB);
         body.emit(assign(r00C0, bit_or(r00C8, r00C9), 0x01));

         body.emit(assign(r00C1, rshift(r00B8, r00BB), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00C6->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00CB = equal(r00BB, body.constant(int(32)));
         ir_if *f00CA = new(mem_ctx) ir_if(operand(r00CB).val);
         exec_list *const f00CA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00CA->then_instructions;

            body.emit(assign(r00BF, r00B9, 0x01));

            body.emit(assign(r00C0, r00B8, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00CA->else_instructions;

            body.emit(assign(r00BA, bit_or(r00BA, r00B9), 0x01));

            /* IF CONDITION */
            ir_expression *const r00CD = less(r00BB, body.constant(int(64)));
            ir_if *f00CC = new(mem_ctx) ir_if(operand(r00CD).val);
            exec_list *const f00CC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f00CC->then_instructions;

               body.emit(assign(r00BF, lshift(r00B8, r00C2), 0x01));

               ir_expression *const r00CE = bit_and(r00BB, body.constant(int(31)));
               body.emit(assign(r00C0, rshift(r00B8, r00CE), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f00CC->else_instructions;

               ir_variable *const r00CF = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r00D1 = equal(r00BB, body.constant(int(64)));
               ir_if *f00D0 = new(mem_ctx) ir_if(operand(r00D1).val);
               exec_list *const f00D0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f00D0->then_instructions;

                  body.emit(assign(r00CF, r00B8, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f00D0->else_instructions;

                  ir_expression *const r00D2 = nequal(r00B8, body.constant(0u));
                  ir_expression *const r00D3 = expr(ir_unop_b2i, r00D2);
                  body.emit(assign(r00CF, expr(ir_unop_i2u, r00D3), 0x01));


               body.instructions = f00D0_parent_instructions;
               body.emit(f00D0);

               /* END IF */

               body.emit(assign(r00BF, r00CF, 0x01));

               body.emit(assign(r00C0, body.constant(0u), 0x01));


            body.instructions = f00CC_parent_instructions;
            body.emit(f00CC);

            /* END IF */


         body.instructions = f00CA_parent_instructions;
         body.emit(f00CA);

         /* END IF */

         body.emit(assign(r00C1, body.constant(0u), 0x01));


      body.instructions = f00C6_parent_instructions;
      body.emit(f00C6);

      /* END IF */

      ir_expression *const r00D4 = nequal(r00BA, body.constant(0u));
      ir_expression *const r00D5 = expr(ir_unop_b2i, r00D4);
      ir_expression *const r00D6 = expr(ir_unop_i2u, r00D5);
      body.emit(assign(r00BF, bit_or(r00BF, r00D6), 0x01));


   body.instructions = f00C4_parent_instructions;
   body.emit(f00C4);

   /* END IF */

   body.emit(assign(r00BE, r00BF, 0x01));

   body.emit(assign(r00BD, r00C0, 0x01));

   body.emit(assign(r00BC, r00C1, 0x01));

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

   ir_variable *const r00D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00D7);
   ir_variable *const r00D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00D8);
   ir_variable *const r00D9 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00D9);
   ir_variable *const r00DA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00DA);
   ir_variable *const r00DB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00DB);
   body.emit(assign(r00DB, lshift(r00D8, r00D9), 0x01));

   ir_variable *const r00DC = body.make_temp(glsl_type::uint_type, "conditional_tmp");
   /* IF CONDITION */
   ir_expression *const r00DE = equal(r00D9, body.constant(int(0)));
   ir_if *f00DD = new(mem_ctx) ir_if(operand(r00DE).val);
   exec_list *const f00DD_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00DD->then_instructions;

      body.emit(assign(r00DC, r00D7, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00DD->else_instructions;

      ir_expression *const r00DF = lshift(r00D7, r00D9);
      ir_expression *const r00E0 = neg(r00D9);
      ir_expression *const r00E1 = bit_and(r00E0, body.constant(int(31)));
      ir_expression *const r00E2 = rshift(r00D8, r00E1);
      body.emit(assign(r00DC, bit_or(r00DF, r00E2), 0x01));


   body.instructions = f00DD_parent_instructions;
   body.emit(f00DD);

   /* END IF */

   body.emit(assign(r00DA, r00DC, 0x01));

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

   ir_variable *const r00E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00E3);
   ir_variable *const r00E4 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00E4);
   ir_variable *const r00E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00E5);
   ir_variable *const r00E6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00E6);
   ir_variable *const r00E7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
   body.emit(r00E7);
   ir_expression *const r00E8 = lshift(r00E3, body.constant(int(31)));
   ir_expression *const r00E9 = expr(ir_unop_i2u, r00E4);
   ir_expression *const r00EA = lshift(r00E9, body.constant(int(20)));
   ir_expression *const r00EB = add(r00E8, r00EA);
   body.emit(assign(r00E7, add(r00EB, r00E5), 0x02));

   body.emit(assign(r00E7, r00E6, 0x01));

   body.emit(ret(r00E7));

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

   ir_variable *const r00EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00EC);
   ir_variable *const r00ED = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00ED);
   ir_variable *const r00EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00EE);
   ir_variable *const r00EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00EF);
   ir_variable *const r00F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_function_in);
   sig_parameters.push_tail(r00F0);
   ir_variable *const r00F1 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r00F1, body.constant(true), 0x01));

   ir_variable *const r00F2 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r00F3 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r00F3);
   ir_expression *const r00F4 = expr(ir_unop_u2i, r00F0);
   body.emit(assign(r00F3, less(r00F4, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00F6 = gequal(r00ED, body.constant(int(2045)));
   ir_if *f00F5 = new(mem_ctx) ir_if(operand(r00F6).val);
   exec_list *const f00F5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00F5->then_instructions;

      /* IF CONDITION */
      ir_expression *const r00F8 = less(body.constant(int(2045)), r00ED);
      ir_expression *const r00F9 = equal(r00ED, body.constant(int(2045)));
      ir_expression *const r00FA = equal(body.constant(2097151u), r00EE);
      ir_expression *const r00FB = equal(body.constant(4294967295u), r00EF);
      ir_expression *const r00FC = logic_and(r00FA, r00FB);
      ir_expression *const r00FD = logic_and(r00F9, r00FC);
      ir_expression *const r00FE = logic_and(r00FD, r00F3);
      ir_expression *const r00FF = logic_or(r00F8, r00FE);
      ir_if *f00F7 = new(mem_ctx) ir_if(operand(r00FF).val);
      exec_list *const f00F7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00F7->then_instructions;

         ir_variable *const r0100 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0100);
         ir_expression *const r0101 = lshift(r00EC, body.constant(int(31)));
         body.emit(assign(r0100, add(r0101, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0100, body.constant(0u), 0x01));

         body.emit(assign(r00F2, r0100, 0x03));

         body.emit(assign(r00F1, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00F7->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0103 = less(r00ED, body.constant(int(0)));
         ir_if *f0102 = new(mem_ctx) ir_if(operand(r0103).val);
         exec_list *const f0102_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0102->then_instructions;

            ir_variable *const r0104 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0104, r00F0, 0x01));

            ir_variable *const r0105 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r0105, neg(r00ED), 0x01));

            ir_variable *const r0106 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0106);
            ir_variable *const r0107 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0107);
            ir_variable *const r0108 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0108);
            ir_variable *const r0109 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r010A = neg(r0105);
            body.emit(assign(r0109, bit_and(r010A, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r010C = equal(r0105, body.constant(int(0)));
            ir_if *f010B = new(mem_ctx) ir_if(operand(r010C).val);
            exec_list *const f010B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f010B->then_instructions;

               body.emit(assign(r0106, r00F0, 0x01));

               body.emit(assign(r0107, r00EF, 0x01));

               body.emit(assign(r0108, r00EE, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f010B->else_instructions;

               /* IF CONDITION */
               ir_expression *const r010E = less(r0105, body.constant(int(32)));
               ir_if *f010D = new(mem_ctx) ir_if(operand(r010E).val);
               exec_list *const f010D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f010D->then_instructions;

                  body.emit(assign(r0106, lshift(r00EF, r0109), 0x01));

                  ir_expression *const r010F = lshift(r00EE, r0109);
                  ir_expression *const r0110 = rshift(r00EF, r0105);
                  body.emit(assign(r0107, bit_or(r010F, r0110), 0x01));

                  body.emit(assign(r0108, rshift(r00EE, r0105), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f010D->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0112 = equal(r0105, body.constant(int(32)));
                  ir_if *f0111 = new(mem_ctx) ir_if(operand(r0112).val);
                  exec_list *const f0111_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0111->then_instructions;

                     body.emit(assign(r0106, r00EF, 0x01));

                     body.emit(assign(r0107, r00EE, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0111->else_instructions;

                     body.emit(assign(r0104, bit_or(r00F0, r00EF), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0114 = less(r0105, body.constant(int(64)));
                     ir_if *f0113 = new(mem_ctx) ir_if(operand(r0114).val);
                     exec_list *const f0113_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0113->then_instructions;

                        body.emit(assign(r0106, lshift(r00EE, r0109), 0x01));

                        ir_expression *const r0115 = bit_and(r0105, body.constant(int(31)));
                        body.emit(assign(r0107, rshift(r00EE, r0115), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0113->else_instructions;

                        ir_variable *const r0116 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0118 = equal(r0105, body.constant(int(64)));
                        ir_if *f0117 = new(mem_ctx) ir_if(operand(r0118).val);
                        exec_list *const f0117_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0117->then_instructions;

                           body.emit(assign(r0116, r00EE, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0117->else_instructions;

                           ir_expression *const r0119 = nequal(r00EE, body.constant(0u));
                           ir_expression *const r011A = expr(ir_unop_b2i, r0119);
                           body.emit(assign(r0116, expr(ir_unop_i2u, r011A), 0x01));


                        body.instructions = f0117_parent_instructions;
                        body.emit(f0117);

                        /* END IF */

                        body.emit(assign(r0106, r0116, 0x01));

                        body.emit(assign(r0107, body.constant(0u), 0x01));


                     body.instructions = f0113_parent_instructions;
                     body.emit(f0113);

                     /* END IF */


                  body.instructions = f0111_parent_instructions;
                  body.emit(f0111);

                  /* END IF */

                  body.emit(assign(r0108, body.constant(0u), 0x01));


               body.instructions = f010D_parent_instructions;
               body.emit(f010D);

               /* END IF */

               ir_expression *const r011B = nequal(r0104, body.constant(0u));
               ir_expression *const r011C = expr(ir_unop_b2i, r011B);
               ir_expression *const r011D = expr(ir_unop_i2u, r011C);
               body.emit(assign(r0106, bit_or(r0106, r011D), 0x01));


            body.instructions = f010B_parent_instructions;
            body.emit(f010B);

            /* END IF */

            body.emit(assign(r00EE, r0108, 0x01));

            body.emit(assign(r00EF, r0107, 0x01));

            body.emit(assign(r00F0, r0106, 0x01));

            body.emit(assign(r00ED, body.constant(int(0)), 0x01));

            body.emit(assign(r00F3, less(r0106, body.constant(0u)), 0x01));


         body.instructions = f0102_parent_instructions;
         body.emit(f0102);

         /* END IF */


      body.instructions = f00F7_parent_instructions;
      body.emit(f00F7);

      /* END IF */


   body.instructions = f00F5_parent_instructions;
   body.emit(f00F5);

   /* END IF */

   /* IF CONDITION */
   ir_if *f011E = new(mem_ctx) ir_if(operand(r00F1).val);
   exec_list *const f011E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f011E->then_instructions;

      /* IF CONDITION */
      ir_if *f011F = new(mem_ctx) ir_if(operand(r00F3).val);
      exec_list *const f011F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f011F->then_instructions;

         ir_variable *const r0120 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0120, add(r00EF, body.constant(1u)), 0x01));

         ir_expression *const r0121 = less(r0120, r00EF);
         ir_expression *const r0122 = expr(ir_unop_b2i, r0121);
         ir_expression *const r0123 = expr(ir_unop_i2u, r0122);
         body.emit(assign(r00EE, add(r00EE, r0123), 0x01));

         ir_expression *const r0124 = equal(r00F0, body.constant(0u));
         ir_expression *const r0125 = expr(ir_unop_b2i, r0124);
         ir_expression *const r0126 = expr(ir_unop_i2u, r0125);
         ir_expression *const r0127 = add(r00F0, r0126);
         ir_expression *const r0128 = bit_and(r0127, body.constant(1u));
         ir_expression *const r0129 = expr(ir_unop_bit_not, r0128);
         body.emit(assign(r00EF, bit_and(r0120, r0129), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f011F->else_instructions;

         /* IF CONDITION */
         ir_expression *const r012B = bit_or(r00EE, r00EF);
         ir_expression *const r012C = equal(r012B, body.constant(0u));
         ir_if *f012A = new(mem_ctx) ir_if(operand(r012C).val);
         exec_list *const f012A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f012A->then_instructions;

            body.emit(assign(r00ED, body.constant(int(0)), 0x01));


         body.instructions = f012A_parent_instructions;
         body.emit(f012A);

         /* END IF */


      body.instructions = f011F_parent_instructions;
      body.emit(f011F);

      /* END IF */

      ir_variable *const r012D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r012D);
      ir_expression *const r012E = lshift(r00EC, body.constant(int(31)));
      ir_expression *const r012F = expr(ir_unop_i2u, r00ED);
      ir_expression *const r0130 = lshift(r012F, body.constant(int(20)));
      ir_expression *const r0131 = add(r012E, r0130);
      body.emit(assign(r012D, add(r0131, r00EE), 0x02));

      body.emit(assign(r012D, r00EF, 0x01));

      body.emit(assign(r00F2, r012D, 0x03));

      body.emit(assign(r00F1, body.constant(false), 0x01));


   body.instructions = f011E_parent_instructions;
   body.emit(f011E);

   /* END IF */

   body.emit(ret(r00F2));

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

   ir_variable *const r0132 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0132);
   ir_variable *const r0133 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0134 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0134);
   /* IF CONDITION */
   ir_expression *const r0136 = equal(r0132, body.constant(0u));
   ir_if *f0135 = new(mem_ctx) ir_if(operand(r0136).val);
   exec_list *const f0135_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0135->then_instructions;

      body.emit(assign(r0133, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0135->else_instructions;

      body.emit(assign(r0134, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r0138 = bit_and(r0132, body.constant(4294901760u));
      ir_expression *const r0139 = equal(r0138, body.constant(0u));
      ir_if *f0137 = new(mem_ctx) ir_if(operand(r0139).val);
      exec_list *const f0137_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0137->then_instructions;

         body.emit(assign(r0134, body.constant(int(16)), 0x01));

         body.emit(assign(r0132, lshift(r0132, body.constant(int(16))), 0x01));


      body.instructions = f0137_parent_instructions;
      body.emit(f0137);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r013B = bit_and(r0132, body.constant(4278190080u));
      ir_expression *const r013C = equal(r013B, body.constant(0u));
      ir_if *f013A = new(mem_ctx) ir_if(operand(r013C).val);
      exec_list *const f013A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f013A->then_instructions;

         body.emit(assign(r0134, add(r0134, body.constant(int(8))), 0x01));

         body.emit(assign(r0132, lshift(r0132, body.constant(int(8))), 0x01));


      body.instructions = f013A_parent_instructions;
      body.emit(f013A);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r013E = bit_and(r0132, body.constant(4026531840u));
      ir_expression *const r013F = equal(r013E, body.constant(0u));
      ir_if *f013D = new(mem_ctx) ir_if(operand(r013F).val);
      exec_list *const f013D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f013D->then_instructions;

         body.emit(assign(r0134, add(r0134, body.constant(int(4))), 0x01));

         body.emit(assign(r0132, lshift(r0132, body.constant(int(4))), 0x01));


      body.instructions = f013D_parent_instructions;
      body.emit(f013D);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0141 = bit_and(r0132, body.constant(3221225472u));
      ir_expression *const r0142 = equal(r0141, body.constant(0u));
      ir_if *f0140 = new(mem_ctx) ir_if(operand(r0142).val);
      exec_list *const f0140_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0140->then_instructions;

         body.emit(assign(r0134, add(r0134, body.constant(int(2))), 0x01));

         body.emit(assign(r0132, lshift(r0132, body.constant(int(2))), 0x01));


      body.instructions = f0140_parent_instructions;
      body.emit(f0140);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0144 = bit_and(r0132, body.constant(2147483648u));
      ir_expression *const r0145 = equal(r0144, body.constant(0u));
      ir_if *f0143 = new(mem_ctx) ir_if(operand(r0145).val);
      exec_list *const f0143_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0143->then_instructions;

         body.emit(assign(r0134, add(r0134, body.constant(int(1))), 0x01));


      body.instructions = f0143_parent_instructions;
      body.emit(f0143);

      /* END IF */

      body.emit(assign(r0133, r0134, 0x01));


   body.instructions = f0135_parent_instructions;
   body.emit(f0135);

   /* END IF */

   body.emit(ret(r0133));

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

   ir_variable *const r0146 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0146);
   ir_variable *const r0147 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0147);
   ir_variable *const r0148 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0148);
   ir_variable *const r0149 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0149);
   ir_variable *const r014A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r014A);
   ir_variable *const r014B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r014B);
   /* IF CONDITION */
   ir_expression *const r014D = equal(r0148, body.constant(0u));
   ir_if *f014C = new(mem_ctx) ir_if(operand(r014D).val);
   exec_list *const f014C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f014C->then_instructions;

      body.emit(assign(r0148, r0149, 0x01));

      body.emit(assign(r0149, body.constant(0u), 0x01));

      body.emit(assign(r0147, add(r0147, body.constant(int(-32))), 0x01));


   body.instructions = f014C_parent_instructions;
   body.emit(f014C);

   /* END IF */

   ir_variable *const r014E = body.make_temp(glsl_type::uint_type, "a");
   body.emit(assign(r014E, r0148, 0x01));

   ir_variable *const r014F = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0150 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0150);
   /* IF CONDITION */
   ir_expression *const r0152 = equal(r0148, body.constant(0u));
   ir_if *f0151 = new(mem_ctx) ir_if(operand(r0152).val);
   exec_list *const f0151_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0151->then_instructions;

      body.emit(assign(r014F, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0151->else_instructions;

      body.emit(assign(r0150, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r0154 = bit_and(r0148, body.constant(4294901760u));
      ir_expression *const r0155 = equal(r0154, body.constant(0u));
      ir_if *f0153 = new(mem_ctx) ir_if(operand(r0155).val);
      exec_list *const f0153_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0153->then_instructions;

         body.emit(assign(r0150, body.constant(int(16)), 0x01));

         body.emit(assign(r014E, lshift(r0148, body.constant(int(16))), 0x01));


      body.instructions = f0153_parent_instructions;
      body.emit(f0153);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0157 = bit_and(r014E, body.constant(4278190080u));
      ir_expression *const r0158 = equal(r0157, body.constant(0u));
      ir_if *f0156 = new(mem_ctx) ir_if(operand(r0158).val);
      exec_list *const f0156_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0156->then_instructions;

         body.emit(assign(r0150, add(r0150, body.constant(int(8))), 0x01));

         body.emit(assign(r014E, lshift(r014E, body.constant(int(8))), 0x01));


      body.instructions = f0156_parent_instructions;
      body.emit(f0156);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r015A = bit_and(r014E, body.constant(4026531840u));
      ir_expression *const r015B = equal(r015A, body.constant(0u));
      ir_if *f0159 = new(mem_ctx) ir_if(operand(r015B).val);
      exec_list *const f0159_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0159->then_instructions;

         body.emit(assign(r0150, add(r0150, body.constant(int(4))), 0x01));

         body.emit(assign(r014E, lshift(r014E, body.constant(int(4))), 0x01));


      body.instructions = f0159_parent_instructions;
      body.emit(f0159);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r015D = bit_and(r014E, body.constant(3221225472u));
      ir_expression *const r015E = equal(r015D, body.constant(0u));
      ir_if *f015C = new(mem_ctx) ir_if(operand(r015E).val);
      exec_list *const f015C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f015C->then_instructions;

         body.emit(assign(r0150, add(r0150, body.constant(int(2))), 0x01));

         body.emit(assign(r014E, lshift(r014E, body.constant(int(2))), 0x01));


      body.instructions = f015C_parent_instructions;
      body.emit(f015C);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0160 = bit_and(r014E, body.constant(2147483648u));
      ir_expression *const r0161 = equal(r0160, body.constant(0u));
      ir_if *f015F = new(mem_ctx) ir_if(operand(r0161).val);
      exec_list *const f015F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f015F->then_instructions;

         body.emit(assign(r0150, add(r0150, body.constant(int(1))), 0x01));


      body.instructions = f015F_parent_instructions;
      body.emit(f015F);

      /* END IF */

      body.emit(assign(r014F, r0150, 0x01));


   body.instructions = f0151_parent_instructions;
   body.emit(f0151);

   /* END IF */

   body.emit(assign(r014B, add(r014F, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0163 = gequal(r014B, body.constant(int(0)));
   ir_if *f0162 = new(mem_ctx) ir_if(operand(r0163).val);
   exec_list *const f0162_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0162->then_instructions;

      body.emit(assign(r014A, body.constant(0u), 0x01));

      ir_variable *const r0164 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0164, lshift(r0149, r014B), 0x01));

      ir_variable *const r0165 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0167 = equal(r014B, body.constant(int(0)));
      ir_if *f0166 = new(mem_ctx) ir_if(operand(r0167).val);
      exec_list *const f0166_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0166->then_instructions;

         body.emit(assign(r0165, r0148, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0166->else_instructions;

         ir_expression *const r0168 = lshift(r0148, r014B);
         ir_expression *const r0169 = neg(r014B);
         ir_expression *const r016A = bit_and(r0169, body.constant(int(31)));
         ir_expression *const r016B = rshift(r0149, r016A);
         body.emit(assign(r0165, bit_or(r0168, r016B), 0x01));


      body.instructions = f0166_parent_instructions;
      body.emit(f0166);

      /* END IF */

      body.emit(assign(r0148, r0165, 0x01));

      body.emit(assign(r0149, r0164, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0162->else_instructions;

      ir_variable *const r016C = body.make_temp(glsl_type::uint_type, "a2");
      body.emit(assign(r016C, body.constant(0u), 0x01));

      ir_variable *const r016D = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r016D, neg(r014B), 0x01));

      ir_variable *const r016E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
      body.emit(r016E);
      ir_variable *const r016F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r016F);
      ir_variable *const r0170 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0170);
      ir_variable *const r0171 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0172 = neg(r016D);
      body.emit(assign(r0171, bit_and(r0172, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0174 = equal(r016D, body.constant(int(0)));
      ir_if *f0173 = new(mem_ctx) ir_if(operand(r0174).val);
      exec_list *const f0173_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0173->then_instructions;

         body.emit(assign(r016E, r016C, 0x01));

         body.emit(assign(r016F, r0149, 0x01));

         body.emit(assign(r0170, r0148, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0173->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0176 = less(r016D, body.constant(int(32)));
         ir_if *f0175 = new(mem_ctx) ir_if(operand(r0176).val);
         exec_list *const f0175_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0175->then_instructions;

            body.emit(assign(r016E, lshift(r0149, r0171), 0x01));

            ir_expression *const r0177 = lshift(r0148, r0171);
            ir_expression *const r0178 = rshift(r0149, r016D);
            body.emit(assign(r016F, bit_or(r0177, r0178), 0x01));

            body.emit(assign(r0170, rshift(r0148, r016D), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0175->else_instructions;

            /* IF CONDITION */
            ir_expression *const r017A = equal(r016D, body.constant(int(32)));
            ir_if *f0179 = new(mem_ctx) ir_if(operand(r017A).val);
            exec_list *const f0179_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0179->then_instructions;

               body.emit(assign(r016E, r0149, 0x01));

               body.emit(assign(r016F, r0148, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0179->else_instructions;

               body.emit(assign(r016C, bit_or(body.constant(0u), r0149), 0x01));

               /* IF CONDITION */
               ir_expression *const r017C = less(r016D, body.constant(int(64)));
               ir_if *f017B = new(mem_ctx) ir_if(operand(r017C).val);
               exec_list *const f017B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f017B->then_instructions;

                  body.emit(assign(r016E, lshift(r0148, r0171), 0x01));

                  ir_expression *const r017D = bit_and(r016D, body.constant(int(31)));
                  body.emit(assign(r016F, rshift(r0148, r017D), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f017B->else_instructions;

                  ir_variable *const r017E = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r0180 = equal(r016D, body.constant(int(64)));
                  ir_if *f017F = new(mem_ctx) ir_if(operand(r0180).val);
                  exec_list *const f017F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f017F->then_instructions;

                     body.emit(assign(r017E, r0148, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f017F->else_instructions;

                     ir_expression *const r0181 = nequal(r0148, body.constant(0u));
                     ir_expression *const r0182 = expr(ir_unop_b2i, r0181);
                     body.emit(assign(r017E, expr(ir_unop_i2u, r0182), 0x01));


                  body.instructions = f017F_parent_instructions;
                  body.emit(f017F);

                  /* END IF */

                  body.emit(assign(r016E, r017E, 0x01));

                  body.emit(assign(r016F, body.constant(0u), 0x01));


               body.instructions = f017B_parent_instructions;
               body.emit(f017B);

               /* END IF */


            body.instructions = f0179_parent_instructions;
            body.emit(f0179);

            /* END IF */

            body.emit(assign(r0170, body.constant(0u), 0x01));


         body.instructions = f0175_parent_instructions;
         body.emit(f0175);

         /* END IF */

         ir_expression *const r0183 = nequal(r016C, body.constant(0u));
         ir_expression *const r0184 = expr(ir_unop_b2i, r0183);
         ir_expression *const r0185 = expr(ir_unop_i2u, r0184);
         body.emit(assign(r016E, bit_or(r016E, r0185), 0x01));


      body.instructions = f0173_parent_instructions;
      body.emit(f0173);

      /* END IF */

      body.emit(assign(r0148, r0170, 0x01));

      body.emit(assign(r0149, r016F, 0x01));

      body.emit(assign(r014A, r016E, 0x01));


   body.instructions = f0162_parent_instructions;
   body.emit(f0162);

   /* END IF */

   body.emit(assign(r0147, sub(r0147, r014B), 0x01));

   ir_variable *const r0186 = body.make_temp(glsl_type::int_type, "zExp");
   body.emit(assign(r0186, r0147, 0x01));

   ir_variable *const r0187 = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r0187, r0148, 0x01));

   ir_variable *const r0188 = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r0188, r0149, 0x01));

   ir_variable *const r0189 = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r0189, r014A, 0x01));

   ir_variable *const r018A = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r018A, body.constant(true), 0x01));

   ir_variable *const r018B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r018C = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r018C);
   ir_expression *const r018D = expr(ir_unop_u2i, r014A);
   body.emit(assign(r018C, less(r018D, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r018F = gequal(r0147, body.constant(int(2045)));
   ir_if *f018E = new(mem_ctx) ir_if(operand(r018F).val);
   exec_list *const f018E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f018E->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0191 = less(body.constant(int(2045)), r0147);
      ir_expression *const r0192 = equal(r0147, body.constant(int(2045)));
      ir_expression *const r0193 = equal(body.constant(2097151u), r0148);
      ir_expression *const r0194 = equal(body.constant(4294967295u), r0149);
      ir_expression *const r0195 = logic_and(r0193, r0194);
      ir_expression *const r0196 = logic_and(r0192, r0195);
      ir_expression *const r0197 = logic_and(r0196, r018C);
      ir_expression *const r0198 = logic_or(r0191, r0197);
      ir_if *f0190 = new(mem_ctx) ir_if(operand(r0198).val);
      exec_list *const f0190_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0190->then_instructions;

         ir_variable *const r0199 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0199);
         ir_expression *const r019A = lshift(r0146, body.constant(int(31)));
         body.emit(assign(r0199, add(r019A, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0199, body.constant(0u), 0x01));

         body.emit(assign(r018B, r0199, 0x03));

         body.emit(assign(r018A, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0190->else_instructions;

         /* IF CONDITION */
         ir_expression *const r019C = less(r0147, body.constant(int(0)));
         ir_if *f019B = new(mem_ctx) ir_if(operand(r019C).val);
         exec_list *const f019B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f019B->then_instructions;

            ir_variable *const r019D = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r019D, r014A, 0x01));

            ir_variable *const r019E = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r019E, neg(r0147), 0x01));

            ir_variable *const r019F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r019F);
            ir_variable *const r01A0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r01A0);
            ir_variable *const r01A1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r01A1);
            ir_variable *const r01A2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r01A3 = neg(r019E);
            body.emit(assign(r01A2, bit_and(r01A3, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r01A5 = equal(r019E, body.constant(int(0)));
            ir_if *f01A4 = new(mem_ctx) ir_if(operand(r01A5).val);
            exec_list *const f01A4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01A4->then_instructions;

               body.emit(assign(r019F, r014A, 0x01));

               body.emit(assign(r01A0, r0149, 0x01));

               body.emit(assign(r01A1, r0148, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01A4->else_instructions;

               /* IF CONDITION */
               ir_expression *const r01A7 = less(r019E, body.constant(int(32)));
               ir_if *f01A6 = new(mem_ctx) ir_if(operand(r01A7).val);
               exec_list *const f01A6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f01A6->then_instructions;

                  body.emit(assign(r019F, lshift(r0149, r01A2), 0x01));

                  ir_expression *const r01A8 = lshift(r0148, r01A2);
                  ir_expression *const r01A9 = rshift(r0149, r019E);
                  body.emit(assign(r01A0, bit_or(r01A8, r01A9), 0x01));

                  body.emit(assign(r01A1, rshift(r0148, r019E), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f01A6->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r01AB = equal(r019E, body.constant(int(32)));
                  ir_if *f01AA = new(mem_ctx) ir_if(operand(r01AB).val);
                  exec_list *const f01AA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f01AA->then_instructions;

                     body.emit(assign(r019F, r0149, 0x01));

                     body.emit(assign(r01A0, r0148, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f01AA->else_instructions;

                     body.emit(assign(r019D, bit_or(r014A, r0149), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r01AD = less(r019E, body.constant(int(64)));
                     ir_if *f01AC = new(mem_ctx) ir_if(operand(r01AD).val);
                     exec_list *const f01AC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f01AC->then_instructions;

                        body.emit(assign(r019F, lshift(r0148, r01A2), 0x01));

                        ir_expression *const r01AE = bit_and(r019E, body.constant(int(31)));
                        body.emit(assign(r01A0, rshift(r0148, r01AE), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f01AC->else_instructions;

                        ir_variable *const r01AF = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r01B1 = equal(r019E, body.constant(int(64)));
                        ir_if *f01B0 = new(mem_ctx) ir_if(operand(r01B1).val);
                        exec_list *const f01B0_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f01B0->then_instructions;

                           body.emit(assign(r01AF, r0148, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f01B0->else_instructions;

                           ir_expression *const r01B2 = nequal(r0148, body.constant(0u));
                           ir_expression *const r01B3 = expr(ir_unop_b2i, r01B2);
                           body.emit(assign(r01AF, expr(ir_unop_i2u, r01B3), 0x01));


                        body.instructions = f01B0_parent_instructions;
                        body.emit(f01B0);

                        /* END IF */

                        body.emit(assign(r019F, r01AF, 0x01));

                        body.emit(assign(r01A0, body.constant(0u), 0x01));


                     body.instructions = f01AC_parent_instructions;
                     body.emit(f01AC);

                     /* END IF */


                  body.instructions = f01AA_parent_instructions;
                  body.emit(f01AA);

                  /* END IF */

                  body.emit(assign(r01A1, body.constant(0u), 0x01));


               body.instructions = f01A6_parent_instructions;
               body.emit(f01A6);

               /* END IF */

               ir_expression *const r01B4 = nequal(r019D, body.constant(0u));
               ir_expression *const r01B5 = expr(ir_unop_b2i, r01B4);
               ir_expression *const r01B6 = expr(ir_unop_i2u, r01B5);
               body.emit(assign(r019F, bit_or(r019F, r01B6), 0x01));


            body.instructions = f01A4_parent_instructions;
            body.emit(f01A4);

            /* END IF */

            body.emit(assign(r0187, r01A1, 0x01));

            body.emit(assign(r0188, r01A0, 0x01));

            body.emit(assign(r0189, r019F, 0x01));

            body.emit(assign(r0186, body.constant(int(0)), 0x01));

            body.emit(assign(r018C, less(r019F, body.constant(0u)), 0x01));


         body.instructions = f019B_parent_instructions;
         body.emit(f019B);

         /* END IF */


      body.instructions = f0190_parent_instructions;
      body.emit(f0190);

      /* END IF */


   body.instructions = f018E_parent_instructions;
   body.emit(f018E);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01B7 = new(mem_ctx) ir_if(operand(r018A).val);
   exec_list *const f01B7_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01B7->then_instructions;

      /* IF CONDITION */
      ir_if *f01B8 = new(mem_ctx) ir_if(operand(r018C).val);
      exec_list *const f01B8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01B8->then_instructions;

         ir_variable *const r01B9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01B9, add(r0188, body.constant(1u)), 0x01));

         ir_expression *const r01BA = less(r01B9, r0188);
         ir_expression *const r01BB = expr(ir_unop_b2i, r01BA);
         ir_expression *const r01BC = expr(ir_unop_i2u, r01BB);
         body.emit(assign(r0187, add(r0187, r01BC), 0x01));

         ir_expression *const r01BD = equal(r0189, body.constant(0u));
         ir_expression *const r01BE = expr(ir_unop_b2i, r01BD);
         ir_expression *const r01BF = expr(ir_unop_i2u, r01BE);
         ir_expression *const r01C0 = add(r0189, r01BF);
         ir_expression *const r01C1 = bit_and(r01C0, body.constant(1u));
         ir_expression *const r01C2 = expr(ir_unop_bit_not, r01C1);
         body.emit(assign(r0188, bit_and(r01B9, r01C2), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01B8->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01C4 = bit_or(r0187, r0188);
         ir_expression *const r01C5 = equal(r01C4, body.constant(0u));
         ir_if *f01C3 = new(mem_ctx) ir_if(operand(r01C5).val);
         exec_list *const f01C3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01C3->then_instructions;

            body.emit(assign(r0186, body.constant(int(0)), 0x01));


         body.instructions = f01C3_parent_instructions;
         body.emit(f01C3);

         /* END IF */


      body.instructions = f01B8_parent_instructions;
      body.emit(f01B8);

      /* END IF */

      ir_variable *const r01C6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r01C6);
      ir_expression *const r01C7 = lshift(r0146, body.constant(int(31)));
      ir_expression *const r01C8 = expr(ir_unop_i2u, r0186);
      ir_expression *const r01C9 = lshift(r01C8, body.constant(int(20)));
      ir_expression *const r01CA = add(r01C7, r01C9);
      body.emit(assign(r01C6, add(r01CA, r0187), 0x02));

      body.emit(assign(r01C6, r0188, 0x01));

      body.emit(assign(r018B, r01C6, 0x03));

      body.emit(assign(r018A, body.constant(false), 0x01));


   body.instructions = f01B7_parent_instructions;
   body.emit(f01B7);

   /* END IF */

   body.emit(ret(r018B));

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

   ir_variable *const r01CB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01CB);
   ir_variable *const r01CC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01CC);
   ir_variable *const r01CD = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01CE = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01CF = lshift(swizzle_y(r01CB), body.constant(int(1)));
   ir_expression *const r01D0 = gequal(r01CF, body.constant(4292870144u));
   ir_expression *const r01D1 = nequal(swizzle_x(r01CB), body.constant(0u));
   ir_expression *const r01D2 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
   ir_expression *const r01D3 = nequal(r01D2, body.constant(0u));
   ir_expression *const r01D4 = logic_or(r01D1, r01D3);
   body.emit(assign(r01CE, logic_and(r01D0, r01D4), 0x01));

   ir_variable *const r01D5 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01D6 = lshift(swizzle_y(r01CC), body.constant(int(1)));
   ir_expression *const r01D7 = gequal(r01D6, body.constant(4292870144u));
   ir_expression *const r01D8 = nequal(swizzle_x(r01CC), body.constant(0u));
   ir_expression *const r01D9 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
   ir_expression *const r01DA = nequal(r01D9, body.constant(0u));
   ir_expression *const r01DB = logic_or(r01D8, r01DA);
   body.emit(assign(r01D5, logic_and(r01D7, r01DB), 0x01));

   body.emit(assign(r01CB, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

   body.emit(assign(r01CC, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

   /* IF CONDITION */
   ir_if *f01DC = new(mem_ctx) ir_if(operand(r01CE).val);
   exec_list *const f01DC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01DC->then_instructions;

      ir_variable *const r01DD = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
      /* IF CONDITION */
      ir_if *f01DE = new(mem_ctx) ir_if(operand(r01D5).val);
      exec_list *const f01DE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01DE->then_instructions;

         body.emit(assign(r01DD, r01CC, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01DE->else_instructions;

         body.emit(assign(r01DD, r01CB, 0x03));


      body.instructions = f01DE_parent_instructions;
      body.emit(f01DE);

      /* END IF */

      body.emit(assign(r01CD, r01DD, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01DC->else_instructions;

      body.emit(assign(r01CD, r01CC, 0x03));


   body.instructions = f01DC_parent_instructions;
   body.emit(f01DC);

   /* END IF */

   body.emit(ret(r01CD));

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

   ir_variable *const r01DF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01DF);
   ir_variable *const r01E0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01E0);
   ir_variable *const r01E1 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01E1, body.constant(true), 0x01));

   ir_variable *const r01E2 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r01E3);
   ir_variable *const r01E4 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01E4, rshift(swizzle_y(r01DF), body.constant(int(31))), 0x01));

   body.emit(assign(r01E3, r01E4, 0x01));

   ir_variable *const r01E5 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01E5, rshift(swizzle_y(r01E0), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r01E7 = equal(r01E4, r01E5);
   ir_if *f01E6 = new(mem_ctx) ir_if(operand(r01E7).val);
   exec_list *const f01E6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01E6->then_instructions;

      ir_variable *const r01E8 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r01E8);
      ir_variable *const r01E9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r01E9);
      ir_variable *const r01EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r01EA);
      ir_variable *const r01EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r01EB);
      ir_variable *const r01EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r01EC);
      ir_variable *const r01ED = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r01ED);
      ir_variable *const r01EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r01EE);
      ir_variable *const r01EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
      body.emit(r01EF);
      body.emit(assign(r01EF, body.constant(0u), 0x01));

      body.emit(assign(r01EE, body.constant(0u), 0x01));

      ir_variable *const r01F0 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01F0, swizzle_x(r01DF), 0x01));

      body.emit(assign(r01EC, r01F0, 0x01));

      ir_variable *const r01F1 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01F1, bit_and(swizzle_y(r01DF), body.constant(1048575u)), 0x01));

      body.emit(assign(r01EB, r01F1, 0x01));

      ir_variable *const r01F2 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01F2, swizzle_x(r01E0), 0x01));

      body.emit(assign(r01EA, r01F2, 0x01));

      ir_variable *const r01F3 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01F3, bit_and(swizzle_y(r01E0), body.constant(1048575u)), 0x01));

      body.emit(assign(r01E9, r01F3, 0x01));

      ir_variable *const r01F4 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r01F5 = rshift(swizzle_y(r01DF), body.constant(int(20)));
      ir_expression *const r01F6 = bit_and(r01F5, body.constant(2047u));
      body.emit(assign(r01F4, expr(ir_unop_u2i, r01F6), 0x01));

      ir_variable *const r01F7 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r01F8 = rshift(swizzle_y(r01E0), body.constant(int(20)));
      ir_expression *const r01F9 = bit_and(r01F8, body.constant(2047u));
      body.emit(assign(r01F7, expr(ir_unop_u2i, r01F9), 0x01));

      ir_variable *const r01FA = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r01FA, sub(r01F4, r01F7), 0x01));

      body.emit(assign(r01E8, r01FA, 0x01));

      /* IF CONDITION */
      ir_expression *const r01FC = less(body.constant(int(0)), r01FA);
      ir_if *f01FB = new(mem_ctx) ir_if(operand(r01FC).val);
      exec_list *const f01FB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01FB->then_instructions;

         /* IF CONDITION */
         ir_expression *const r01FE = equal(r01F4, body.constant(int(2047)));
         ir_if *f01FD = new(mem_ctx) ir_if(operand(r01FE).val);
         exec_list *const f01FD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01FD->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0200 = bit_or(r01F1, swizzle_x(r01DF));
            ir_expression *const r0201 = nequal(r0200, body.constant(0u));
            ir_if *f01FF = new(mem_ctx) ir_if(operand(r0201).val);
            exec_list *const f01FF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01FF->then_instructions;

               ir_variable *const r0202 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0202, swizzle_x(r01DF), 0x01));

               ir_variable *const r0203 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0203, swizzle_x(r01E0), 0x01));

               ir_variable *const r0204 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0205 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r0206 = lshift(swizzle_y(r01E0), body.constant(int(1)));
               ir_expression *const r0207 = gequal(r0206, body.constant(4292870144u));
               ir_expression *const r0208 = nequal(swizzle_x(r01E0), body.constant(0u));
               ir_expression *const r0209 = bit_and(swizzle_y(r01E0), body.constant(1048575u));
               ir_expression *const r020A = nequal(r0209, body.constant(0u));
               ir_expression *const r020B = logic_or(r0208, r020A);
               body.emit(assign(r0205, logic_and(r0207, r020B), 0x01));

               body.emit(assign(r0202, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

               body.emit(assign(r0203, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r020D = lshift(swizzle_y(r01DF), body.constant(int(1)));
               ir_expression *const r020E = gequal(r020D, body.constant(4292870144u));
               ir_expression *const r020F = nequal(swizzle_x(r01DF), body.constant(0u));
               ir_expression *const r0210 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
               ir_expression *const r0211 = nequal(r0210, body.constant(0u));
               ir_expression *const r0212 = logic_or(r020F, r0211);
               ir_expression *const r0213 = logic_and(r020E, r0212);
               ir_if *f020C = new(mem_ctx) ir_if(operand(r0213).val);
               exec_list *const f020C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f020C->then_instructions;

                  ir_variable *const r0214 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_if *f0215 = new(mem_ctx) ir_if(operand(r0205).val);
                  exec_list *const f0215_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0215->then_instructions;

                     body.emit(assign(r0214, r0203, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0215->else_instructions;

                     body.emit(assign(r0214, r0202, 0x03));


                  body.instructions = f0215_parent_instructions;
                  body.emit(f0215);

                  /* END IF */

                  body.emit(assign(r0204, r0214, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f020C->else_instructions;

                  body.emit(assign(r0204, r0203, 0x03));


               body.instructions = f020C_parent_instructions;
               body.emit(f020C);

               /* END IF */

               body.emit(assign(r01E2, r0204, 0x03));

               body.emit(assign(r01E1, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01FF->else_instructions;

               body.emit(assign(r01E2, r01DF, 0x03));

               body.emit(assign(r01E1, body.constant(false), 0x01));


            body.instructions = f01FF_parent_instructions;
            body.emit(f01FF);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f01FD->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0217 = equal(r01F7, body.constant(int(0)));
            ir_if *f0216 = new(mem_ctx) ir_if(operand(r0217).val);
            exec_list *const f0216_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0216->then_instructions;

               body.emit(assign(r01E8, add(r01FA, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0216->else_instructions;

               body.emit(assign(r01E9, bit_or(r01F3, body.constant(1048576u)), 0x01));


            body.instructions = f0216_parent_instructions;
            body.emit(f0216);

            /* END IF */

            ir_variable *const r0218 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0218, body.constant(0u), 0x01));

            ir_variable *const r0219 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0219);
            ir_variable *const r021A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r021A);
            ir_variable *const r021B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r021B);
            ir_variable *const r021C = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r021D = neg(r01E8);
            body.emit(assign(r021C, bit_and(r021D, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r021F = equal(r01E8, body.constant(int(0)));
            ir_if *f021E = new(mem_ctx) ir_if(operand(r021F).val);
            exec_list *const f021E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f021E->then_instructions;

               body.emit(assign(r0219, r0218, 0x01));

               body.emit(assign(r021A, r01F2, 0x01));

               body.emit(assign(r021B, r01E9, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f021E->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0221 = less(r01E8, body.constant(int(32)));
               ir_if *f0220 = new(mem_ctx) ir_if(operand(r0221).val);
               exec_list *const f0220_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0220->then_instructions;

                  body.emit(assign(r0219, lshift(swizzle_x(r01E0), r021C), 0x01));

                  ir_expression *const r0222 = lshift(r01E9, r021C);
                  ir_expression *const r0223 = rshift(swizzle_x(r01E0), r01E8);
                  body.emit(assign(r021A, bit_or(r0222, r0223), 0x01));

                  body.emit(assign(r021B, rshift(r01E9, r01E8), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0220->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0225 = equal(r01E8, body.constant(int(32)));
                  ir_if *f0224 = new(mem_ctx) ir_if(operand(r0225).val);
                  exec_list *const f0224_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0224->then_instructions;

                     body.emit(assign(r0219, r01F2, 0x01));

                     body.emit(assign(r021A, r01E9, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0224->else_instructions;

                     body.emit(assign(r0218, bit_or(body.constant(0u), swizzle_x(r01E0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0227 = less(r01E8, body.constant(int(64)));
                     ir_if *f0226 = new(mem_ctx) ir_if(operand(r0227).val);
                     exec_list *const f0226_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0226->then_instructions;

                        body.emit(assign(r0219, lshift(r01E9, r021C), 0x01));

                        ir_expression *const r0228 = bit_and(r01E8, body.constant(int(31)));
                        body.emit(assign(r021A, rshift(r01E9, r0228), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0226->else_instructions;

                        ir_variable *const r0229 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r022B = equal(r01E8, body.constant(int(64)));
                        ir_if *f022A = new(mem_ctx) ir_if(operand(r022B).val);
                        exec_list *const f022A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f022A->then_instructions;

                           body.emit(assign(r0229, r01E9, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f022A->else_instructions;

                           ir_expression *const r022C = nequal(r01E9, body.constant(0u));
                           ir_expression *const r022D = expr(ir_unop_b2i, r022C);
                           body.emit(assign(r0229, expr(ir_unop_i2u, r022D), 0x01));


                        body.instructions = f022A_parent_instructions;
                        body.emit(f022A);

                        /* END IF */

                        body.emit(assign(r0219, r0229, 0x01));

                        body.emit(assign(r021A, body.constant(0u), 0x01));


                     body.instructions = f0226_parent_instructions;
                     body.emit(f0226);

                     /* END IF */


                  body.instructions = f0224_parent_instructions;
                  body.emit(f0224);

                  /* END IF */

                  body.emit(assign(r021B, body.constant(0u), 0x01));


               body.instructions = f0220_parent_instructions;
               body.emit(f0220);

               /* END IF */

               ir_expression *const r022E = nequal(r0218, body.constant(0u));
               ir_expression *const r022F = expr(ir_unop_b2i, r022E);
               ir_expression *const r0230 = expr(ir_unop_i2u, r022F);
               body.emit(assign(r0219, bit_or(r0219, r0230), 0x01));


            body.instructions = f021E_parent_instructions;
            body.emit(f021E);

            /* END IF */

            body.emit(assign(r01E9, r021B, 0x01));

            body.emit(assign(r01EA, r021A, 0x01));

            body.emit(assign(r01EE, r0219, 0x01));

            body.emit(assign(r01ED, r01F4, 0x01));


         body.instructions = f01FD_parent_instructions;
         body.emit(f01FD);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01FB->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0232 = less(r01E8, body.constant(int(0)));
         ir_if *f0231 = new(mem_ctx) ir_if(operand(r0232).val);
         exec_list *const f0231_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0231->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0234 = equal(r01F7, body.constant(int(2047)));
            ir_if *f0233 = new(mem_ctx) ir_if(operand(r0234).val);
            exec_list *const f0233_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0233->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0236 = bit_or(r01E9, r01EA);
               ir_expression *const r0237 = nequal(r0236, body.constant(0u));
               ir_if *f0235 = new(mem_ctx) ir_if(operand(r0237).val);
               exec_list *const f0235_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0235->then_instructions;

                  ir_variable *const r0238 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0238, swizzle_x(r01DF), 0x01));

                  ir_variable *const r0239 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0239, swizzle_x(r01E0), 0x01));

                  ir_variable *const r023A = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r023B = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r023C = lshift(swizzle_y(r01E0), body.constant(int(1)));
                  ir_expression *const r023D = gequal(r023C, body.constant(4292870144u));
                  ir_expression *const r023E = nequal(swizzle_x(r01E0), body.constant(0u));
                  ir_expression *const r023F = bit_and(swizzle_y(r01E0), body.constant(1048575u));
                  ir_expression *const r0240 = nequal(r023F, body.constant(0u));
                  ir_expression *const r0241 = logic_or(r023E, r0240);
                  body.emit(assign(r023B, logic_and(r023D, r0241), 0x01));

                  body.emit(assign(r0238, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

                  body.emit(assign(r0239, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0243 = lshift(swizzle_y(r01DF), body.constant(int(1)));
                  ir_expression *const r0244 = gequal(r0243, body.constant(4292870144u));
                  ir_expression *const r0245 = nequal(swizzle_x(r01DF), body.constant(0u));
                  ir_expression *const r0246 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
                  ir_expression *const r0247 = nequal(r0246, body.constant(0u));
                  ir_expression *const r0248 = logic_or(r0245, r0247);
                  ir_expression *const r0249 = logic_and(r0244, r0248);
                  ir_if *f0242 = new(mem_ctx) ir_if(operand(r0249).val);
                  exec_list *const f0242_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0242->then_instructions;

                     ir_variable *const r024A = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f024B = new(mem_ctx) ir_if(operand(r023B).val);
                     exec_list *const f024B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f024B->then_instructions;

                        body.emit(assign(r024A, r0239, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f024B->else_instructions;

                        body.emit(assign(r024A, r0238, 0x03));


                     body.instructions = f024B_parent_instructions;
                     body.emit(f024B);

                     /* END IF */

                     body.emit(assign(r023A, r024A, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0242->else_instructions;

                     body.emit(assign(r023A, r0239, 0x03));


                  body.instructions = f0242_parent_instructions;
                  body.emit(f0242);

                  /* END IF */

                  body.emit(assign(r01E2, r023A, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0235->else_instructions;

                  ir_variable *const r024C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r024C);
                  ir_expression *const r024D = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r024C, add(r024D, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r024C, body.constant(0u), 0x01));

                  body.emit(assign(r01E2, r024C, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f0235_parent_instructions;
               body.emit(f0235);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0233->else_instructions;

               /* IF CONDITION */
               ir_expression *const r024F = equal(r01F4, body.constant(int(0)));
               ir_if *f024E = new(mem_ctx) ir_if(operand(r024F).val);
               exec_list *const f024E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f024E->then_instructions;

                  body.emit(assign(r01E8, add(r01E8, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f024E->else_instructions;

                  body.emit(assign(r01EB, bit_or(r01F1, body.constant(1048576u)), 0x01));


               body.instructions = f024E_parent_instructions;
               body.emit(f024E);

               /* END IF */

               ir_variable *const r0250 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0250, body.constant(0u), 0x01));

               ir_variable *const r0251 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0251, neg(r01E8), 0x01));

               ir_variable *const r0252 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0252);
               ir_variable *const r0253 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0253);
               ir_variable *const r0254 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0254);
               ir_variable *const r0255 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0256 = neg(r0251);
               body.emit(assign(r0255, bit_and(r0256, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0258 = equal(r0251, body.constant(int(0)));
               ir_if *f0257 = new(mem_ctx) ir_if(operand(r0258).val);
               exec_list *const f0257_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0257->then_instructions;

                  body.emit(assign(r0252, r0250, 0x01));

                  body.emit(assign(r0253, r01F0, 0x01));

                  body.emit(assign(r0254, r01EB, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0257->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r025A = less(r0251, body.constant(int(32)));
                  ir_if *f0259 = new(mem_ctx) ir_if(operand(r025A).val);
                  exec_list *const f0259_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0259->then_instructions;

                     body.emit(assign(r0252, lshift(swizzle_x(r01DF), r0255), 0x01));

                     ir_expression *const r025B = lshift(r01EB, r0255);
                     ir_expression *const r025C = rshift(swizzle_x(r01DF), r0251);
                     body.emit(assign(r0253, bit_or(r025B, r025C), 0x01));

                     body.emit(assign(r0254, rshift(r01EB, r0251), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0259->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r025E = equal(r0251, body.constant(int(32)));
                     ir_if *f025D = new(mem_ctx) ir_if(operand(r025E).val);
                     exec_list *const f025D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f025D->then_instructions;

                        body.emit(assign(r0252, r01F0, 0x01));

                        body.emit(assign(r0253, r01EB, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f025D->else_instructions;

                        body.emit(assign(r0250, bit_or(body.constant(0u), swizzle_x(r01DF)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0260 = less(r0251, body.constant(int(64)));
                        ir_if *f025F = new(mem_ctx) ir_if(operand(r0260).val);
                        exec_list *const f025F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f025F->then_instructions;

                           body.emit(assign(r0252, lshift(r01EB, r0255), 0x01));

                           ir_expression *const r0261 = bit_and(r0251, body.constant(int(31)));
                           body.emit(assign(r0253, rshift(r01EB, r0261), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f025F->else_instructions;

                           ir_variable *const r0262 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0264 = equal(r0251, body.constant(int(64)));
                           ir_if *f0263 = new(mem_ctx) ir_if(operand(r0264).val);
                           exec_list *const f0263_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0263->then_instructions;

                              body.emit(assign(r0262, r01EB, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0263->else_instructions;

                              ir_expression *const r0265 = nequal(r01EB, body.constant(0u));
                              ir_expression *const r0266 = expr(ir_unop_b2i, r0265);
                              body.emit(assign(r0262, expr(ir_unop_i2u, r0266), 0x01));


                           body.instructions = f0263_parent_instructions;
                           body.emit(f0263);

                           /* END IF */

                           body.emit(assign(r0252, r0262, 0x01));

                           body.emit(assign(r0253, body.constant(0u), 0x01));


                        body.instructions = f025F_parent_instructions;
                        body.emit(f025F);

                        /* END IF */


                     body.instructions = f025D_parent_instructions;
                     body.emit(f025D);

                     /* END IF */

                     body.emit(assign(r0254, body.constant(0u), 0x01));


                  body.instructions = f0259_parent_instructions;
                  body.emit(f0259);

                  /* END IF */

                  ir_expression *const r0267 = nequal(r0250, body.constant(0u));
                  ir_expression *const r0268 = expr(ir_unop_b2i, r0267);
                  ir_expression *const r0269 = expr(ir_unop_i2u, r0268);
                  body.emit(assign(r0252, bit_or(r0252, r0269), 0x01));


               body.instructions = f0257_parent_instructions;
               body.emit(f0257);

               /* END IF */

               body.emit(assign(r01EB, r0254, 0x01));

               body.emit(assign(r01EC, r0253, 0x01));

               body.emit(assign(r01EE, r0252, 0x01));

               body.emit(assign(r01ED, r01F7, 0x01));


            body.instructions = f0233_parent_instructions;
            body.emit(f0233);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0231->else_instructions;

            /* IF CONDITION */
            ir_expression *const r026B = equal(r01F4, body.constant(int(2047)));
            ir_if *f026A = new(mem_ctx) ir_if(operand(r026B).val);
            exec_list *const f026A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f026A->then_instructions;

               /* IF CONDITION */
               ir_expression *const r026D = bit_or(r01EB, r01EC);
               ir_expression *const r026E = bit_or(r01E9, r01EA);
               ir_expression *const r026F = bit_or(r026D, r026E);
               ir_expression *const r0270 = nequal(r026F, body.constant(0u));
               ir_if *f026C = new(mem_ctx) ir_if(operand(r0270).val);
               exec_list *const f026C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f026C->then_instructions;

                  ir_variable *const r0271 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0271, swizzle_x(r01DF), 0x01));

                  ir_variable *const r0272 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0272, swizzle_x(r01E0), 0x01));

                  ir_variable *const r0273 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0274 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r0275 = lshift(swizzle_y(r01E0), body.constant(int(1)));
                  ir_expression *const r0276 = gequal(r0275, body.constant(4292870144u));
                  ir_expression *const r0277 = nequal(swizzle_x(r01E0), body.constant(0u));
                  ir_expression *const r0278 = bit_and(swizzle_y(r01E0), body.constant(1048575u));
                  ir_expression *const r0279 = nequal(r0278, body.constant(0u));
                  ir_expression *const r027A = logic_or(r0277, r0279);
                  body.emit(assign(r0274, logic_and(r0276, r027A), 0x01));

                  body.emit(assign(r0271, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

                  body.emit(assign(r0272, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r027C = lshift(swizzle_y(r01DF), body.constant(int(1)));
                  ir_expression *const r027D = gequal(r027C, body.constant(4292870144u));
                  ir_expression *const r027E = nequal(swizzle_x(r01DF), body.constant(0u));
                  ir_expression *const r027F = bit_and(swizzle_y(r01DF), body.constant(1048575u));
                  ir_expression *const r0280 = nequal(r027F, body.constant(0u));
                  ir_expression *const r0281 = logic_or(r027E, r0280);
                  ir_expression *const r0282 = logic_and(r027D, r0281);
                  ir_if *f027B = new(mem_ctx) ir_if(operand(r0282).val);
                  exec_list *const f027B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f027B->then_instructions;

                     ir_variable *const r0283 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f0284 = new(mem_ctx) ir_if(operand(r0274).val);
                     exec_list *const f0284_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0284->then_instructions;

                        body.emit(assign(r0283, r0272, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0284->else_instructions;

                        body.emit(assign(r0283, r0271, 0x03));


                     body.instructions = f0284_parent_instructions;
                     body.emit(f0284);

                     /* END IF */

                     body.emit(assign(r0273, r0283, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f027B->else_instructions;

                     body.emit(assign(r0273, r0272, 0x03));


                  body.instructions = f027B_parent_instructions;
                  body.emit(f027B);

                  /* END IF */

                  body.emit(assign(r01E2, r0273, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f026C->else_instructions;

                  body.emit(assign(r01E2, r01DF, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f026C_parent_instructions;
               body.emit(f026C);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f026A->else_instructions;

               ir_variable *const r0285 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0286 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0286, add(r01EC, r01EA), 0x01));

               ir_expression *const r0287 = add(r01EB, r01E9);
               ir_expression *const r0288 = less(r0286, r01EC);
               ir_expression *const r0289 = expr(ir_unop_b2i, r0288);
               ir_expression *const r028A = expr(ir_unop_i2u, r0289);
               body.emit(assign(r0285, add(r0287, r028A), 0x01));

               body.emit(assign(r01EF, r0285, 0x01));

               /* IF CONDITION */
               ir_expression *const r028C = equal(r01F4, body.constant(int(0)));
               ir_if *f028B = new(mem_ctx) ir_if(operand(r028C).val);
               exec_list *const f028B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f028B->then_instructions;

                  ir_variable *const r028D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r028D);
                  ir_expression *const r028E = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r028D, add(r028E, r0285), 0x02));

                  body.emit(assign(r028D, r0286, 0x01));

                  body.emit(assign(r01E2, r028D, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f028B->else_instructions;

                  body.emit(assign(r01EF, bit_or(r0285, body.constant(2097152u)), 0x01));

                  body.emit(assign(r01ED, r01F4, 0x01));

                  ir_variable *const r028F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r028F);
                  ir_variable *const r0290 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r0290);
                  ir_variable *const r0291 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r0291);
                  body.emit(assign(r028F, lshift(r0286, body.constant(int(31))), 0x01));

                  ir_expression *const r0292 = lshift(r01EF, body.constant(int(31)));
                  ir_expression *const r0293 = rshift(r0286, body.constant(int(1)));
                  body.emit(assign(r0290, bit_or(r0292, r0293), 0x01));

                  body.emit(assign(r0291, rshift(r01EF, body.constant(int(1))), 0x01));

                  body.emit(assign(r028F, bit_or(r028F, body.constant(0u)), 0x01));

                  body.emit(assign(r01EF, r0291, 0x01));

                  body.emit(assign(r01EE, r028F, 0x01));

                  ir_variable *const r0294 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0294, r01F4, 0x01));

                  ir_variable *const r0295 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0295, r0291, 0x01));

                  ir_variable *const r0296 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0296, r0290, 0x01));

                  ir_variable *const r0297 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0297, r028F, 0x01));

                  ir_variable *const r0298 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0298, body.constant(true), 0x01));

                  ir_variable *const r0299 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r029A = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r029A);
                  ir_expression *const r029B = expr(ir_unop_u2i, r028F);
                  body.emit(assign(r029A, less(r029B, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r029D = gequal(r01F4, body.constant(int(2045)));
                  ir_if *f029C = new(mem_ctx) ir_if(operand(r029D).val);
                  exec_list *const f029C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f029C->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r029F = less(body.constant(int(2045)), r01F4);
                     ir_expression *const r02A0 = equal(r01F4, body.constant(int(2045)));
                     ir_expression *const r02A1 = equal(body.constant(2097151u), r0291);
                     ir_expression *const r02A2 = equal(body.constant(4294967295u), r0290);
                     ir_expression *const r02A3 = logic_and(r02A1, r02A2);
                     ir_expression *const r02A4 = logic_and(r02A0, r02A3);
                     ir_expression *const r02A5 = logic_and(r02A4, r029A);
                     ir_expression *const r02A6 = logic_or(r029F, r02A5);
                     ir_if *f029E = new(mem_ctx) ir_if(operand(r02A6).val);
                     exec_list *const f029E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f029E->then_instructions;

                        ir_variable *const r02A7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r02A7);
                        ir_expression *const r02A8 = lshift(r01E4, body.constant(int(31)));
                        body.emit(assign(r02A7, add(r02A8, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r02A7, body.constant(0u), 0x01));

                        body.emit(assign(r0299, r02A7, 0x03));

                        body.emit(assign(r0298, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f029E->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02AA = less(r01F4, body.constant(int(0)));
                        ir_if *f02A9 = new(mem_ctx) ir_if(operand(r02AA).val);
                        exec_list *const f02A9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02A9->then_instructions;

                           ir_variable *const r02AB = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r02AB, r028F, 0x01));

                           ir_variable *const r02AC = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r02AC, neg(r01F4), 0x01));

                           ir_variable *const r02AD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r02AD);
                           ir_variable *const r02AE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r02AE);
                           ir_variable *const r02AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r02AF);
                           ir_variable *const r02B0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02B1 = neg(r02AC);
                           body.emit(assign(r02B0, bit_and(r02B1, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02B3 = equal(r02AC, body.constant(int(0)));
                           ir_if *f02B2 = new(mem_ctx) ir_if(operand(r02B3).val);
                           exec_list *const f02B2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02B2->then_instructions;

                              body.emit(assign(r02AD, r028F, 0x01));

                              body.emit(assign(r02AE, r0290, 0x01));

                              body.emit(assign(r02AF, r0291, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02B2->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02B5 = less(r02AC, body.constant(int(32)));
                              ir_if *f02B4 = new(mem_ctx) ir_if(operand(r02B5).val);
                              exec_list *const f02B4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02B4->then_instructions;

                                 body.emit(assign(r02AD, lshift(r0290, r02B0), 0x01));

                                 ir_expression *const r02B6 = lshift(r0291, r02B0);
                                 ir_expression *const r02B7 = rshift(r0290, r02AC);
                                 body.emit(assign(r02AE, bit_or(r02B6, r02B7), 0x01));

                                 body.emit(assign(r02AF, rshift(r0291, r02AC), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02B4->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02B9 = equal(r02AC, body.constant(int(32)));
                                 ir_if *f02B8 = new(mem_ctx) ir_if(operand(r02B9).val);
                                 exec_list *const f02B8_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02B8->then_instructions;

                                    body.emit(assign(r02AD, r0290, 0x01));

                                    body.emit(assign(r02AE, r0291, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02B8->else_instructions;

                                    body.emit(assign(r02AB, bit_or(r028F, r0290), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r02BB = less(r02AC, body.constant(int(64)));
                                    ir_if *f02BA = new(mem_ctx) ir_if(operand(r02BB).val);
                                    exec_list *const f02BA_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f02BA->then_instructions;

                                       body.emit(assign(r02AD, lshift(r0291, r02B0), 0x01));

                                       ir_expression *const r02BC = bit_and(r02AC, body.constant(int(31)));
                                       body.emit(assign(r02AE, rshift(r0291, r02BC), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f02BA->else_instructions;

                                       ir_variable *const r02BD = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r02BF = equal(r02AC, body.constant(int(64)));
                                       ir_if *f02BE = new(mem_ctx) ir_if(operand(r02BF).val);
                                       exec_list *const f02BE_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f02BE->then_instructions;

                                          body.emit(assign(r02BD, r0291, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f02BE->else_instructions;

                                          ir_expression *const r02C0 = nequal(r0291, body.constant(0u));
                                          ir_expression *const r02C1 = expr(ir_unop_b2i, r02C0);
                                          body.emit(assign(r02BD, expr(ir_unop_i2u, r02C1), 0x01));


                                       body.instructions = f02BE_parent_instructions;
                                       body.emit(f02BE);

                                       /* END IF */

                                       body.emit(assign(r02AD, r02BD, 0x01));

                                       body.emit(assign(r02AE, body.constant(0u), 0x01));


                                    body.instructions = f02BA_parent_instructions;
                                    body.emit(f02BA);

                                    /* END IF */


                                 body.instructions = f02B8_parent_instructions;
                                 body.emit(f02B8);

                                 /* END IF */

                                 body.emit(assign(r02AF, body.constant(0u), 0x01));


                              body.instructions = f02B4_parent_instructions;
                              body.emit(f02B4);

                              /* END IF */

                              ir_expression *const r02C2 = nequal(r02AB, body.constant(0u));
                              ir_expression *const r02C3 = expr(ir_unop_b2i, r02C2);
                              ir_expression *const r02C4 = expr(ir_unop_i2u, r02C3);
                              body.emit(assign(r02AD, bit_or(r02AD, r02C4), 0x01));


                           body.instructions = f02B2_parent_instructions;
                           body.emit(f02B2);

                           /* END IF */

                           body.emit(assign(r0295, r02AF, 0x01));

                           body.emit(assign(r0296, r02AE, 0x01));

                           body.emit(assign(r0297, r02AD, 0x01));

                           body.emit(assign(r0294, body.constant(int(0)), 0x01));

                           body.emit(assign(r029A, less(r02AD, body.constant(0u)), 0x01));


                        body.instructions = f02A9_parent_instructions;
                        body.emit(f02A9);

                        /* END IF */


                     body.instructions = f029E_parent_instructions;
                     body.emit(f029E);

                     /* END IF */


                  body.instructions = f029C_parent_instructions;
                  body.emit(f029C);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02C5 = new(mem_ctx) ir_if(operand(r0298).val);
                  exec_list *const f02C5_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02C5->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02C6 = new(mem_ctx) ir_if(operand(r029A).val);
                     exec_list *const f02C6_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02C6->then_instructions;

                        ir_variable *const r02C7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02C7, add(r0296, body.constant(1u)), 0x01));

                        ir_expression *const r02C8 = less(r02C7, r0296);
                        ir_expression *const r02C9 = expr(ir_unop_b2i, r02C8);
                        ir_expression *const r02CA = expr(ir_unop_i2u, r02C9);
                        body.emit(assign(r0295, add(r0295, r02CA), 0x01));

                        ir_expression *const r02CB = equal(r0297, body.constant(0u));
                        ir_expression *const r02CC = expr(ir_unop_b2i, r02CB);
                        ir_expression *const r02CD = expr(ir_unop_i2u, r02CC);
                        ir_expression *const r02CE = add(r0297, r02CD);
                        ir_expression *const r02CF = bit_and(r02CE, body.constant(1u));
                        ir_expression *const r02D0 = expr(ir_unop_bit_not, r02CF);
                        body.emit(assign(r0296, bit_and(r02C7, r02D0), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02C6->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02D2 = bit_or(r0295, r0296);
                        ir_expression *const r02D3 = equal(r02D2, body.constant(0u));
                        ir_if *f02D1 = new(mem_ctx) ir_if(operand(r02D3).val);
                        exec_list *const f02D1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02D1->then_instructions;

                           body.emit(assign(r0294, body.constant(int(0)), 0x01));


                        body.instructions = f02D1_parent_instructions;
                        body.emit(f02D1);

                        /* END IF */


                     body.instructions = f02C6_parent_instructions;
                     body.emit(f02C6);

                     /* END IF */

                     ir_variable *const r02D4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r02D4);
                     ir_expression *const r02D5 = lshift(r01E4, body.constant(int(31)));
                     ir_expression *const r02D6 = expr(ir_unop_i2u, r0294);
                     ir_expression *const r02D7 = lshift(r02D6, body.constant(int(20)));
                     ir_expression *const r02D8 = add(r02D5, r02D7);
                     body.emit(assign(r02D4, add(r02D8, r0295), 0x02));

                     body.emit(assign(r02D4, r0296, 0x01));

                     body.emit(assign(r0299, r02D4, 0x03));

                     body.emit(assign(r0298, body.constant(false), 0x01));


                  body.instructions = f02C5_parent_instructions;
                  body.emit(f02C5);

                  /* END IF */

                  body.emit(assign(r01E2, r0299, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f028B_parent_instructions;
               body.emit(f028B);

               /* END IF */


            body.instructions = f026A_parent_instructions;
            body.emit(f026A);

            /* END IF */


         body.instructions = f0231_parent_instructions;
         body.emit(f0231);

         /* END IF */


      body.instructions = f01FB_parent_instructions;
      body.emit(f01FB);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02D9 = new(mem_ctx) ir_if(operand(r01E1).val);
      exec_list *const f02D9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02D9->then_instructions;

         body.emit(assign(r01EB, bit_or(r01EB, body.constant(1048576u)), 0x01));

         ir_variable *const r02DA = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r02DB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r02DB, add(r01EC, r01EA), 0x01));

         ir_expression *const r02DC = add(r01EB, r01E9);
         ir_expression *const r02DD = less(r02DB, r01EC);
         ir_expression *const r02DE = expr(ir_unop_b2i, r02DD);
         ir_expression *const r02DF = expr(ir_unop_i2u, r02DE);
         body.emit(assign(r02DA, add(r02DC, r02DF), 0x01));

         body.emit(assign(r01EF, r02DA, 0x01));

         body.emit(assign(r01ED, add(r01ED, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r02E1 = less(r02DA, body.constant(2097152u));
         ir_if *f02E0 = new(mem_ctx) ir_if(operand(r02E1).val);
         exec_list *const f02E0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02E0->then_instructions;

            ir_variable *const r02E2 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r02E2, r01ED, 0x01));

            ir_variable *const r02E3 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r02E3, r02DA, 0x01));

            ir_variable *const r02E4 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r02E4, r02DB, 0x01));

            ir_variable *const r02E5 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r02E5, r01EE, 0x01));

            ir_variable *const r02E6 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r02E6, body.constant(true), 0x01));

            ir_variable *const r02E7 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r02E8 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r02E8);
            ir_expression *const r02E9 = expr(ir_unop_u2i, r01EE);
            body.emit(assign(r02E8, less(r02E9, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02EB = gequal(r01ED, body.constant(int(2045)));
            ir_if *f02EA = new(mem_ctx) ir_if(operand(r02EB).val);
            exec_list *const f02EA_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02EA->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02ED = less(body.constant(int(2045)), r01ED);
               ir_expression *const r02EE = equal(r01ED, body.constant(int(2045)));
               ir_expression *const r02EF = equal(body.constant(2097151u), r02DA);
               ir_expression *const r02F0 = equal(body.constant(4294967295u), r02DB);
               ir_expression *const r02F1 = logic_and(r02EF, r02F0);
               ir_expression *const r02F2 = logic_and(r02EE, r02F1);
               ir_expression *const r02F3 = logic_and(r02F2, r02E8);
               ir_expression *const r02F4 = logic_or(r02ED, r02F3);
               ir_if *f02EC = new(mem_ctx) ir_if(operand(r02F4).val);
               exec_list *const f02EC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02EC->then_instructions;

                  ir_variable *const r02F5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02F5);
                  ir_expression *const r02F6 = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r02F5, add(r02F6, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r02F5, body.constant(0u), 0x01));

                  body.emit(assign(r02E7, r02F5, 0x03));

                  body.emit(assign(r02E6, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02EC->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r02F8 = less(r01ED, body.constant(int(0)));
                  ir_if *f02F7 = new(mem_ctx) ir_if(operand(r02F8).val);
                  exec_list *const f02F7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02F7->then_instructions;

                     ir_variable *const r02F9 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r02F9, r01EE, 0x01));

                     ir_variable *const r02FA = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r02FA, neg(r01ED), 0x01));

                     ir_variable *const r02FB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r02FB);
                     ir_variable *const r02FC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r02FC);
                     ir_variable *const r02FD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r02FD);
                     ir_variable *const r02FE = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r02FF = neg(r02FA);
                     body.emit(assign(r02FE, bit_and(r02FF, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0301 = equal(r02FA, body.constant(int(0)));
                     ir_if *f0300 = new(mem_ctx) ir_if(operand(r0301).val);
                     exec_list *const f0300_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0300->then_instructions;

                        body.emit(assign(r02FB, r01EE, 0x01));

                        body.emit(assign(r02FC, r02DB, 0x01));

                        body.emit(assign(r02FD, r02DA, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0300->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0303 = less(r02FA, body.constant(int(32)));
                        ir_if *f0302 = new(mem_ctx) ir_if(operand(r0303).val);
                        exec_list *const f0302_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0302->then_instructions;

                           body.emit(assign(r02FB, lshift(r02DB, r02FE), 0x01));

                           ir_expression *const r0304 = lshift(r02DA, r02FE);
                           ir_expression *const r0305 = rshift(r02DB, r02FA);
                           body.emit(assign(r02FC, bit_or(r0304, r0305), 0x01));

                           body.emit(assign(r02FD, rshift(r02DA, r02FA), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0302->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0307 = equal(r02FA, body.constant(int(32)));
                           ir_if *f0306 = new(mem_ctx) ir_if(operand(r0307).val);
                           exec_list *const f0306_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0306->then_instructions;

                              body.emit(assign(r02FB, r02DB, 0x01));

                              body.emit(assign(r02FC, r02DA, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0306->else_instructions;

                              body.emit(assign(r02F9, bit_or(r01EE, r02DB), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0309 = less(r02FA, body.constant(int(64)));
                              ir_if *f0308 = new(mem_ctx) ir_if(operand(r0309).val);
                              exec_list *const f0308_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0308->then_instructions;

                                 body.emit(assign(r02FB, lshift(r02DA, r02FE), 0x01));

                                 ir_expression *const r030A = bit_and(r02FA, body.constant(int(31)));
                                 body.emit(assign(r02FC, rshift(r02DA, r030A), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0308->else_instructions;

                                 ir_variable *const r030B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r030D = equal(r02FA, body.constant(int(64)));
                                 ir_if *f030C = new(mem_ctx) ir_if(operand(r030D).val);
                                 exec_list *const f030C_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f030C->then_instructions;

                                    body.emit(assign(r030B, r02DA, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f030C->else_instructions;

                                    ir_expression *const r030E = nequal(r02DA, body.constant(0u));
                                    ir_expression *const r030F = expr(ir_unop_b2i, r030E);
                                    body.emit(assign(r030B, expr(ir_unop_i2u, r030F), 0x01));


                                 body.instructions = f030C_parent_instructions;
                                 body.emit(f030C);

                                 /* END IF */

                                 body.emit(assign(r02FB, r030B, 0x01));

                                 body.emit(assign(r02FC, body.constant(0u), 0x01));


                              body.instructions = f0308_parent_instructions;
                              body.emit(f0308);

                              /* END IF */


                           body.instructions = f0306_parent_instructions;
                           body.emit(f0306);

                           /* END IF */

                           body.emit(assign(r02FD, body.constant(0u), 0x01));


                        body.instructions = f0302_parent_instructions;
                        body.emit(f0302);

                        /* END IF */

                        ir_expression *const r0310 = nequal(r02F9, body.constant(0u));
                        ir_expression *const r0311 = expr(ir_unop_b2i, r0310);
                        ir_expression *const r0312 = expr(ir_unop_i2u, r0311);
                        body.emit(assign(r02FB, bit_or(r02FB, r0312), 0x01));


                     body.instructions = f0300_parent_instructions;
                     body.emit(f0300);

                     /* END IF */

                     body.emit(assign(r02E3, r02FD, 0x01));

                     body.emit(assign(r02E4, r02FC, 0x01));

                     body.emit(assign(r02E5, r02FB, 0x01));

                     body.emit(assign(r02E2, body.constant(int(0)), 0x01));

                     body.emit(assign(r02E8, less(r02FB, body.constant(0u)), 0x01));


                  body.instructions = f02F7_parent_instructions;
                  body.emit(f02F7);

                  /* END IF */


               body.instructions = f02EC_parent_instructions;
               body.emit(f02EC);

               /* END IF */


            body.instructions = f02EA_parent_instructions;
            body.emit(f02EA);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0313 = new(mem_ctx) ir_if(operand(r02E6).val);
            exec_list *const f0313_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0313->then_instructions;

               /* IF CONDITION */
               ir_if *f0314 = new(mem_ctx) ir_if(operand(r02E8).val);
               exec_list *const f0314_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0314->then_instructions;

                  ir_variable *const r0315 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0315, add(r02E4, body.constant(1u)), 0x01));

                  ir_expression *const r0316 = less(r0315, r02E4);
                  ir_expression *const r0317 = expr(ir_unop_b2i, r0316);
                  ir_expression *const r0318 = expr(ir_unop_i2u, r0317);
                  body.emit(assign(r02E3, add(r02E3, r0318), 0x01));

                  ir_expression *const r0319 = equal(r02E5, body.constant(0u));
                  ir_expression *const r031A = expr(ir_unop_b2i, r0319);
                  ir_expression *const r031B = expr(ir_unop_i2u, r031A);
                  ir_expression *const r031C = add(r02E5, r031B);
                  ir_expression *const r031D = bit_and(r031C, body.constant(1u));
                  ir_expression *const r031E = expr(ir_unop_bit_not, r031D);
                  body.emit(assign(r02E4, bit_and(r0315, r031E), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0314->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0320 = bit_or(r02E3, r02E4);
                  ir_expression *const r0321 = equal(r0320, body.constant(0u));
                  ir_if *f031F = new(mem_ctx) ir_if(operand(r0321).val);
                  exec_list *const f031F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f031F->then_instructions;

                     body.emit(assign(r02E2, body.constant(int(0)), 0x01));


                  body.instructions = f031F_parent_instructions;
                  body.emit(f031F);

                  /* END IF */


               body.instructions = f0314_parent_instructions;
               body.emit(f0314);

               /* END IF */

               ir_variable *const r0322 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0322);
               ir_expression *const r0323 = lshift(r01E4, body.constant(int(31)));
               ir_expression *const r0324 = expr(ir_unop_i2u, r02E2);
               ir_expression *const r0325 = lshift(r0324, body.constant(int(20)));
               ir_expression *const r0326 = add(r0323, r0325);
               body.emit(assign(r0322, add(r0326, r02E3), 0x02));

               body.emit(assign(r0322, r02E4, 0x01));

               body.emit(assign(r02E7, r0322, 0x03));

               body.emit(assign(r02E6, body.constant(false), 0x01));


            body.instructions = f0313_parent_instructions;
            body.emit(f0313);

            /* END IF */

            body.emit(assign(r01E2, r02E7, 0x03));

            body.emit(assign(r01E1, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02E0->else_instructions;

            body.emit(assign(r01ED, add(r01ED, body.constant(int(1))), 0x01));

            ir_variable *const r0327 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0327);
            ir_variable *const r0328 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0328);
            ir_variable *const r0329 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0329);
            body.emit(assign(r0327, lshift(r02DB, body.constant(int(31))), 0x01));

            ir_expression *const r032A = lshift(r02DA, body.constant(int(31)));
            ir_expression *const r032B = rshift(r02DB, body.constant(int(1)));
            body.emit(assign(r0328, bit_or(r032A, r032B), 0x01));

            body.emit(assign(r0329, rshift(r02DA, body.constant(int(1))), 0x01));

            ir_expression *const r032C = nequal(r01EE, body.constant(0u));
            ir_expression *const r032D = expr(ir_unop_b2i, r032C);
            ir_expression *const r032E = expr(ir_unop_i2u, r032D);
            body.emit(assign(r0327, bit_or(r0327, r032E), 0x01));

            body.emit(assign(r01EF, r0329, 0x01));

            body.emit(assign(r01EE, r0327, 0x01));

            ir_variable *const r032F = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r032F, r01ED, 0x01));

            ir_variable *const r0330 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0330, r0329, 0x01));

            ir_variable *const r0331 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0331, r0328, 0x01));

            ir_variable *const r0332 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0332, r0327, 0x01));

            ir_variable *const r0333 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0333, body.constant(true), 0x01));

            ir_variable *const r0334 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0335 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0335);
            ir_expression *const r0336 = expr(ir_unop_u2i, r0327);
            body.emit(assign(r0335, less(r0336, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0338 = gequal(r01ED, body.constant(int(2045)));
            ir_if *f0337 = new(mem_ctx) ir_if(operand(r0338).val);
            exec_list *const f0337_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0337->then_instructions;

               /* IF CONDITION */
               ir_expression *const r033A = less(body.constant(int(2045)), r01ED);
               ir_expression *const r033B = equal(r01ED, body.constant(int(2045)));
               ir_expression *const r033C = equal(body.constant(2097151u), r0329);
               ir_expression *const r033D = equal(body.constant(4294967295u), r0328);
               ir_expression *const r033E = logic_and(r033C, r033D);
               ir_expression *const r033F = logic_and(r033B, r033E);
               ir_expression *const r0340 = logic_and(r033F, r0335);
               ir_expression *const r0341 = logic_or(r033A, r0340);
               ir_if *f0339 = new(mem_ctx) ir_if(operand(r0341).val);
               exec_list *const f0339_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0339->then_instructions;

                  ir_variable *const r0342 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0342);
                  ir_expression *const r0343 = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r0342, add(r0343, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0342, body.constant(0u), 0x01));

                  body.emit(assign(r0334, r0342, 0x03));

                  body.emit(assign(r0333, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0339->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0345 = less(r01ED, body.constant(int(0)));
                  ir_if *f0344 = new(mem_ctx) ir_if(operand(r0345).val);
                  exec_list *const f0344_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0344->then_instructions;

                     ir_variable *const r0346 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0346, r0327, 0x01));

                     ir_variable *const r0347 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0347, neg(r01ED), 0x01));

                     ir_variable *const r0348 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0348);
                     ir_variable *const r0349 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0349);
                     ir_variable *const r034A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r034A);
                     ir_variable *const r034B = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r034C = neg(r0347);
                     body.emit(assign(r034B, bit_and(r034C, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r034E = equal(r0347, body.constant(int(0)));
                     ir_if *f034D = new(mem_ctx) ir_if(operand(r034E).val);
                     exec_list *const f034D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f034D->then_instructions;

                        body.emit(assign(r0348, r0327, 0x01));

                        body.emit(assign(r0349, r0328, 0x01));

                        body.emit(assign(r034A, r0329, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f034D->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0350 = less(r0347, body.constant(int(32)));
                        ir_if *f034F = new(mem_ctx) ir_if(operand(r0350).val);
                        exec_list *const f034F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f034F->then_instructions;

                           body.emit(assign(r0348, lshift(r0328, r034B), 0x01));

                           ir_expression *const r0351 = lshift(r0329, r034B);
                           ir_expression *const r0352 = rshift(r0328, r0347);
                           body.emit(assign(r0349, bit_or(r0351, r0352), 0x01));

                           body.emit(assign(r034A, rshift(r0329, r0347), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f034F->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0354 = equal(r0347, body.constant(int(32)));
                           ir_if *f0353 = new(mem_ctx) ir_if(operand(r0354).val);
                           exec_list *const f0353_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0353->then_instructions;

                              body.emit(assign(r0348, r0328, 0x01));

                              body.emit(assign(r0349, r0329, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0353->else_instructions;

                              body.emit(assign(r0346, bit_or(r0327, r0328), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0356 = less(r0347, body.constant(int(64)));
                              ir_if *f0355 = new(mem_ctx) ir_if(operand(r0356).val);
                              exec_list *const f0355_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0355->then_instructions;

                                 body.emit(assign(r0348, lshift(r0329, r034B), 0x01));

                                 ir_expression *const r0357 = bit_and(r0347, body.constant(int(31)));
                                 body.emit(assign(r0349, rshift(r0329, r0357), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0355->else_instructions;

                                 ir_variable *const r0358 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r035A = equal(r0347, body.constant(int(64)));
                                 ir_if *f0359 = new(mem_ctx) ir_if(operand(r035A).val);
                                 exec_list *const f0359_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0359->then_instructions;

                                    body.emit(assign(r0358, r0329, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0359->else_instructions;

                                    ir_expression *const r035B = nequal(r0329, body.constant(0u));
                                    ir_expression *const r035C = expr(ir_unop_b2i, r035B);
                                    body.emit(assign(r0358, expr(ir_unop_i2u, r035C), 0x01));


                                 body.instructions = f0359_parent_instructions;
                                 body.emit(f0359);

                                 /* END IF */

                                 body.emit(assign(r0348, r0358, 0x01));

                                 body.emit(assign(r0349, body.constant(0u), 0x01));


                              body.instructions = f0355_parent_instructions;
                              body.emit(f0355);

                              /* END IF */


                           body.instructions = f0353_parent_instructions;
                           body.emit(f0353);

                           /* END IF */

                           body.emit(assign(r034A, body.constant(0u), 0x01));


                        body.instructions = f034F_parent_instructions;
                        body.emit(f034F);

                        /* END IF */

                        ir_expression *const r035D = nequal(r0346, body.constant(0u));
                        ir_expression *const r035E = expr(ir_unop_b2i, r035D);
                        ir_expression *const r035F = expr(ir_unop_i2u, r035E);
                        body.emit(assign(r0348, bit_or(r0348, r035F), 0x01));


                     body.instructions = f034D_parent_instructions;
                     body.emit(f034D);

                     /* END IF */

                     body.emit(assign(r0330, r034A, 0x01));

                     body.emit(assign(r0331, r0349, 0x01));

                     body.emit(assign(r0332, r0348, 0x01));

                     body.emit(assign(r032F, body.constant(int(0)), 0x01));

                     body.emit(assign(r0335, less(r0348, body.constant(0u)), 0x01));


                  body.instructions = f0344_parent_instructions;
                  body.emit(f0344);

                  /* END IF */


               body.instructions = f0339_parent_instructions;
               body.emit(f0339);

               /* END IF */


            body.instructions = f0337_parent_instructions;
            body.emit(f0337);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0360 = new(mem_ctx) ir_if(operand(r0333).val);
            exec_list *const f0360_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0360->then_instructions;

               /* IF CONDITION */
               ir_if *f0361 = new(mem_ctx) ir_if(operand(r0335).val);
               exec_list *const f0361_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0361->then_instructions;

                  ir_variable *const r0362 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0362, add(r0331, body.constant(1u)), 0x01));

                  ir_expression *const r0363 = less(r0362, r0331);
                  ir_expression *const r0364 = expr(ir_unop_b2i, r0363);
                  ir_expression *const r0365 = expr(ir_unop_i2u, r0364);
                  body.emit(assign(r0330, add(r0330, r0365), 0x01));

                  ir_expression *const r0366 = equal(r0332, body.constant(0u));
                  ir_expression *const r0367 = expr(ir_unop_b2i, r0366);
                  ir_expression *const r0368 = expr(ir_unop_i2u, r0367);
                  ir_expression *const r0369 = add(r0332, r0368);
                  ir_expression *const r036A = bit_and(r0369, body.constant(1u));
                  ir_expression *const r036B = expr(ir_unop_bit_not, r036A);
                  body.emit(assign(r0331, bit_and(r0362, r036B), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0361->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r036D = bit_or(r0330, r0331);
                  ir_expression *const r036E = equal(r036D, body.constant(0u));
                  ir_if *f036C = new(mem_ctx) ir_if(operand(r036E).val);
                  exec_list *const f036C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f036C->then_instructions;

                     body.emit(assign(r032F, body.constant(int(0)), 0x01));


                  body.instructions = f036C_parent_instructions;
                  body.emit(f036C);

                  /* END IF */


               body.instructions = f0361_parent_instructions;
               body.emit(f0361);

               /* END IF */

               ir_variable *const r036F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r036F);
               ir_expression *const r0370 = lshift(r01E4, body.constant(int(31)));
               ir_expression *const r0371 = expr(ir_unop_i2u, r032F);
               ir_expression *const r0372 = lshift(r0371, body.constant(int(20)));
               ir_expression *const r0373 = add(r0370, r0372);
               body.emit(assign(r036F, add(r0373, r0330), 0x02));

               body.emit(assign(r036F, r0331, 0x01));

               body.emit(assign(r0334, r036F, 0x03));

               body.emit(assign(r0333, body.constant(false), 0x01));


            body.instructions = f0360_parent_instructions;
            body.emit(f0360);

            /* END IF */

            body.emit(assign(r01E2, r0334, 0x03));

            body.emit(assign(r01E1, body.constant(false), 0x01));


         body.instructions = f02E0_parent_instructions;
         body.emit(f02E0);

         /* END IF */


      body.instructions = f02D9_parent_instructions;
      body.emit(f02D9);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01E6->else_instructions;

      ir_variable *const r0374 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r0374);
      ir_variable *const r0375 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
      body.emit(r0375);
      ir_variable *const r0376 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
      body.emit(r0376);
      ir_variable *const r0377 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r0377);
      ir_variable *const r0378 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r0378);
      ir_variable *const r0379 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r0379);
      ir_variable *const r037A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r037A);
      ir_variable *const r037B = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r037B);
      ir_variable *const r037C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r037D = rshift(swizzle_y(r01DF), body.constant(int(20)));
      ir_expression *const r037E = bit_and(r037D, body.constant(2047u));
      body.emit(assign(r037C, expr(ir_unop_u2i, r037E), 0x01));

      body.emit(assign(r0376, r037C, 0x01));

      ir_variable *const r037F = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r0380 = rshift(swizzle_y(r01E0), body.constant(int(20)));
      ir_expression *const r0381 = bit_and(r0380, body.constant(2047u));
      body.emit(assign(r037F, expr(ir_unop_u2i, r0381), 0x01));

      body.emit(assign(r0375, r037F, 0x01));

      body.emit(assign(r0374, sub(r037C, r037F), 0x01));

      ir_variable *const r0382 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0382, lshift(swizzle_x(r01DF), body.constant(int(10))), 0x01));

      ir_variable *const r0383 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r0384 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
      ir_expression *const r0385 = lshift(r0384, body.constant(int(10)));
      ir_expression *const r0386 = rshift(swizzle_x(r01DF), body.constant(int(22)));
      body.emit(assign(r0383, bit_or(r0385, r0386), 0x01));

      body.emit(assign(r0379, r0383, 0x01));

      body.emit(assign(r037A, r0382, 0x01));

      ir_variable *const r0387 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0387, lshift(swizzle_x(r01E0), body.constant(int(10))), 0x01));

      ir_variable *const r0388 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r0389 = bit_and(swizzle_y(r01E0), body.constant(1048575u));
      ir_expression *const r038A = lshift(r0389, body.constant(int(10)));
      ir_expression *const r038B = rshift(swizzle_x(r01E0), body.constant(int(22)));
      body.emit(assign(r0388, bit_or(r038A, r038B), 0x01));

      body.emit(assign(r0377, r0388, 0x01));

      body.emit(assign(r0378, r0387, 0x01));

      /* IF CONDITION */
      ir_expression *const r038D = less(body.constant(int(0)), r0374);
      ir_if *f038C = new(mem_ctx) ir_if(operand(r038D).val);
      exec_list *const f038C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f038C->then_instructions;

         /* IF CONDITION */
         ir_expression *const r038F = equal(r037C, body.constant(int(2047)));
         ir_if *f038E = new(mem_ctx) ir_if(operand(r038F).val);
         exec_list *const f038E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f038E->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0391 = bit_or(r0383, r0382);
            ir_expression *const r0392 = nequal(r0391, body.constant(0u));
            ir_if *f0390 = new(mem_ctx) ir_if(operand(r0392).val);
            exec_list *const f0390_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0390->then_instructions;

               ir_variable *const r0393 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0393, swizzle_x(r01DF), 0x01));

               ir_variable *const r0394 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0394, swizzle_x(r01E0), 0x01));

               ir_variable *const r0395 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0396 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r0397 = lshift(swizzle_y(r01E0), body.constant(int(1)));
               ir_expression *const r0398 = gequal(r0397, body.constant(4292870144u));
               ir_expression *const r0399 = nequal(swizzle_x(r01E0), body.constant(0u));
               ir_expression *const r039A = bit_and(swizzle_y(r01E0), body.constant(1048575u));
               ir_expression *const r039B = nequal(r039A, body.constant(0u));
               ir_expression *const r039C = logic_or(r0399, r039B);
               body.emit(assign(r0396, logic_and(r0398, r039C), 0x01));

               body.emit(assign(r0393, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

               body.emit(assign(r0394, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r039E = lshift(swizzle_y(r01DF), body.constant(int(1)));
               ir_expression *const r039F = gequal(r039E, body.constant(4292870144u));
               ir_expression *const r03A0 = nequal(swizzle_x(r01DF), body.constant(0u));
               ir_expression *const r03A1 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
               ir_expression *const r03A2 = nequal(r03A1, body.constant(0u));
               ir_expression *const r03A3 = logic_or(r03A0, r03A2);
               ir_expression *const r03A4 = logic_and(r039F, r03A3);
               ir_if *f039D = new(mem_ctx) ir_if(operand(r03A4).val);
               exec_list *const f039D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f039D->then_instructions;

                  ir_variable *const r03A5 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_if *f03A6 = new(mem_ctx) ir_if(operand(r0396).val);
                  exec_list *const f03A6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03A6->then_instructions;

                     body.emit(assign(r03A5, r0394, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03A6->else_instructions;

                     body.emit(assign(r03A5, r0393, 0x03));


                  body.instructions = f03A6_parent_instructions;
                  body.emit(f03A6);

                  /* END IF */

                  body.emit(assign(r0395, r03A5, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f039D->else_instructions;

                  body.emit(assign(r0395, r0394, 0x03));


               body.instructions = f039D_parent_instructions;
               body.emit(f039D);

               /* END IF */

               body.emit(assign(r01E2, r0395, 0x03));

               body.emit(assign(r01E1, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0390->else_instructions;

               body.emit(assign(r01E2, r01DF, 0x03));

               body.emit(assign(r01E1, body.constant(false), 0x01));


            body.instructions = f0390_parent_instructions;
            body.emit(f0390);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f038E->else_instructions;

            /* IF CONDITION */
            ir_expression *const r03A8 = equal(r037F, body.constant(int(0)));
            ir_if *f03A7 = new(mem_ctx) ir_if(operand(r03A8).val);
            exec_list *const f03A7_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03A7->then_instructions;

               body.emit(assign(r0374, add(r0374, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03A7->else_instructions;

               body.emit(assign(r0377, bit_or(r0388, body.constant(1073741824u)), 0x01));


            body.instructions = f03A7_parent_instructions;
            body.emit(f03A7);

            /* END IF */

            ir_variable *const r03A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r03A9);
            ir_variable *const r03AA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r03AA);
            ir_variable *const r03AB = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r03AC = neg(r0374);
            body.emit(assign(r03AB, bit_and(r03AC, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03AE = equal(r0374, body.constant(int(0)));
            ir_if *f03AD = new(mem_ctx) ir_if(operand(r03AE).val);
            exec_list *const f03AD_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03AD->then_instructions;

               body.emit(assign(r03A9, r0387, 0x01));

               body.emit(assign(r03AA, r0377, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03AD->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03B0 = less(r0374, body.constant(int(32)));
               ir_if *f03AF = new(mem_ctx) ir_if(operand(r03B0).val);
               exec_list *const f03AF_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03AF->then_instructions;

                  ir_expression *const r03B1 = lshift(r0377, r03AB);
                  ir_expression *const r03B2 = rshift(r0387, r0374);
                  ir_expression *const r03B3 = bit_or(r03B1, r03B2);
                  ir_expression *const r03B4 = lshift(r0387, r03AB);
                  ir_expression *const r03B5 = nequal(r03B4, body.constant(0u));
                  ir_expression *const r03B6 = expr(ir_unop_b2i, r03B5);
                  ir_expression *const r03B7 = expr(ir_unop_i2u, r03B6);
                  body.emit(assign(r03A9, bit_or(r03B3, r03B7), 0x01));

                  body.emit(assign(r03AA, rshift(r0377, r0374), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03AF->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03B9 = equal(r0374, body.constant(int(32)));
                  ir_if *f03B8 = new(mem_ctx) ir_if(operand(r03B9).val);
                  exec_list *const f03B8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03B8->then_instructions;

                     ir_expression *const r03BA = nequal(r0387, body.constant(0u));
                     ir_expression *const r03BB = expr(ir_unop_b2i, r03BA);
                     ir_expression *const r03BC = expr(ir_unop_i2u, r03BB);
                     body.emit(assign(r03A9, bit_or(r0377, r03BC), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03B8->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03BE = less(r0374, body.constant(int(64)));
                     ir_if *f03BD = new(mem_ctx) ir_if(operand(r03BE).val);
                     exec_list *const f03BD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03BD->then_instructions;

                        ir_expression *const r03BF = bit_and(r0374, body.constant(int(31)));
                        ir_expression *const r03C0 = rshift(r0377, r03BF);
                        ir_expression *const r03C1 = lshift(r0377, r03AB);
                        ir_expression *const r03C2 = bit_or(r03C1, r0387);
                        ir_expression *const r03C3 = nequal(r03C2, body.constant(0u));
                        ir_expression *const r03C4 = expr(ir_unop_b2i, r03C3);
                        ir_expression *const r03C5 = expr(ir_unop_i2u, r03C4);
                        body.emit(assign(r03A9, bit_or(r03C0, r03C5), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03BD->else_instructions;

                        ir_expression *const r03C6 = bit_or(r0377, r0387);
                        ir_expression *const r03C7 = nequal(r03C6, body.constant(0u));
                        ir_expression *const r03C8 = expr(ir_unop_b2i, r03C7);
                        body.emit(assign(r03A9, expr(ir_unop_i2u, r03C8), 0x01));


                     body.instructions = f03BD_parent_instructions;
                     body.emit(f03BD);

                     /* END IF */


                  body.instructions = f03B8_parent_instructions;
                  body.emit(f03B8);

                  /* END IF */

                  body.emit(assign(r03AA, body.constant(0u), 0x01));


               body.instructions = f03AF_parent_instructions;
               body.emit(f03AF);

               /* END IF */


            body.instructions = f03AD_parent_instructions;
            body.emit(f03AD);

            /* END IF */

            body.emit(assign(r0377, r03AA, 0x01));

            body.emit(assign(r0378, r03A9, 0x01));

            body.emit(assign(r0379, bit_or(r0383, body.constant(1073741824u)), 0x01));

            ir_variable *const r03C9 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r03CA = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r03CA, sub(r0382, r03A9), 0x01));

            ir_expression *const r03CB = sub(r0379, r03AA);
            ir_expression *const r03CC = less(r0382, r03A9);
            ir_expression *const r03CD = expr(ir_unop_b2i, r03CC);
            ir_expression *const r03CE = expr(ir_unop_i2u, r03CD);
            body.emit(assign(r03C9, sub(r03CB, r03CE), 0x01));

            body.emit(assign(r037B, add(r037C, body.constant(int(-1))), 0x01));

            ir_variable *const r03CF = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03CF, add(r037B, body.constant(int(-10))), 0x01));

            ir_variable *const r03D0 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03D0, r03C9, 0x01));

            ir_variable *const r03D1 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03D1, r03CA, 0x01));

            ir_variable *const r03D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03D2);
            ir_variable *const r03D3 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03D3);
            /* IF CONDITION */
            ir_expression *const r03D5 = equal(r03C9, body.constant(0u));
            ir_if *f03D4 = new(mem_ctx) ir_if(operand(r03D5).val);
            exec_list *const f03D4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03D4->then_instructions;

               body.emit(assign(r03D0, r03CA, 0x01));

               body.emit(assign(r03D1, body.constant(0u), 0x01));

               body.emit(assign(r03CF, add(r03CF, body.constant(int(-32))), 0x01));


            body.instructions = f03D4_parent_instructions;
            body.emit(f03D4);

            /* END IF */

            ir_variable *const r03D6 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r03D6, r03D0, 0x01));

            ir_variable *const r03D7 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r03D8 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03D8);
            /* IF CONDITION */
            ir_expression *const r03DA = equal(r03D0, body.constant(0u));
            ir_if *f03D9 = new(mem_ctx) ir_if(operand(r03DA).val);
            exec_list *const f03D9_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03D9->then_instructions;

               body.emit(assign(r03D7, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03D9->else_instructions;

               body.emit(assign(r03D8, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r03DC = bit_and(r03D0, body.constant(4294901760u));
               ir_expression *const r03DD = equal(r03DC, body.constant(0u));
               ir_if *f03DB = new(mem_ctx) ir_if(operand(r03DD).val);
               exec_list *const f03DB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03DB->then_instructions;

                  body.emit(assign(r03D8, body.constant(int(16)), 0x01));

                  body.emit(assign(r03D6, lshift(r03D0, body.constant(int(16))), 0x01));


               body.instructions = f03DB_parent_instructions;
               body.emit(f03DB);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03DF = bit_and(r03D6, body.constant(4278190080u));
               ir_expression *const r03E0 = equal(r03DF, body.constant(0u));
               ir_if *f03DE = new(mem_ctx) ir_if(operand(r03E0).val);
               exec_list *const f03DE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03DE->then_instructions;

                  body.emit(assign(r03D8, add(r03D8, body.constant(int(8))), 0x01));

                  body.emit(assign(r03D6, lshift(r03D6, body.constant(int(8))), 0x01));


               body.instructions = f03DE_parent_instructions;
               body.emit(f03DE);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03E2 = bit_and(r03D6, body.constant(4026531840u));
               ir_expression *const r03E3 = equal(r03E2, body.constant(0u));
               ir_if *f03E1 = new(mem_ctx) ir_if(operand(r03E3).val);
               exec_list *const f03E1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E1->then_instructions;

                  body.emit(assign(r03D8, add(r03D8, body.constant(int(4))), 0x01));

                  body.emit(assign(r03D6, lshift(r03D6, body.constant(int(4))), 0x01));


               body.instructions = f03E1_parent_instructions;
               body.emit(f03E1);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03E5 = bit_and(r03D6, body.constant(3221225472u));
               ir_expression *const r03E6 = equal(r03E5, body.constant(0u));
               ir_if *f03E4 = new(mem_ctx) ir_if(operand(r03E6).val);
               exec_list *const f03E4_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E4->then_instructions;

                  body.emit(assign(r03D8, add(r03D8, body.constant(int(2))), 0x01));

                  body.emit(assign(r03D6, lshift(r03D6, body.constant(int(2))), 0x01));


               body.instructions = f03E4_parent_instructions;
               body.emit(f03E4);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03E8 = bit_and(r03D6, body.constant(2147483648u));
               ir_expression *const r03E9 = equal(r03E8, body.constant(0u));
               ir_if *f03E7 = new(mem_ctx) ir_if(operand(r03E9).val);
               exec_list *const f03E7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E7->then_instructions;

                  body.emit(assign(r03D8, add(r03D8, body.constant(int(1))), 0x01));


               body.instructions = f03E7_parent_instructions;
               body.emit(f03E7);

               /* END IF */

               body.emit(assign(r03D7, r03D8, 0x01));


            body.instructions = f03D9_parent_instructions;
            body.emit(f03D9);

            /* END IF */

            body.emit(assign(r03D3, add(r03D7, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03EB = gequal(r03D3, body.constant(int(0)));
            ir_if *f03EA = new(mem_ctx) ir_if(operand(r03EB).val);
            exec_list *const f03EA_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03EA->then_instructions;

               body.emit(assign(r03D2, body.constant(0u), 0x01));

               ir_variable *const r03EC = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r03EC, lshift(r03D1, r03D3), 0x01));

               ir_variable *const r03ED = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r03EF = equal(r03D3, body.constant(int(0)));
               ir_if *f03EE = new(mem_ctx) ir_if(operand(r03EF).val);
               exec_list *const f03EE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03EE->then_instructions;

                  body.emit(assign(r03ED, r03D0, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03EE->else_instructions;

                  ir_expression *const r03F0 = lshift(r03D0, r03D3);
                  ir_expression *const r03F1 = neg(r03D3);
                  ir_expression *const r03F2 = bit_and(r03F1, body.constant(int(31)));
                  ir_expression *const r03F3 = rshift(r03D1, r03F2);
                  body.emit(assign(r03ED, bit_or(r03F0, r03F3), 0x01));


               body.instructions = f03EE_parent_instructions;
               body.emit(f03EE);

               /* END IF */

               body.emit(assign(r03D0, r03ED, 0x01));

               body.emit(assign(r03D1, r03EC, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03EA->else_instructions;

               ir_variable *const r03F4 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r03F4, body.constant(0u), 0x01));

               ir_variable *const r03F5 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r03F5, neg(r03D3), 0x01));

               ir_variable *const r03F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r03F6);
               ir_variable *const r03F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r03F7);
               ir_variable *const r03F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r03F8);
               ir_variable *const r03F9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r03FA = neg(r03F5);
               body.emit(assign(r03F9, bit_and(r03FA, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r03FC = equal(r03F5, body.constant(int(0)));
               ir_if *f03FB = new(mem_ctx) ir_if(operand(r03FC).val);
               exec_list *const f03FB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03FB->then_instructions;

                  body.emit(assign(r03F6, r03F4, 0x01));

                  body.emit(assign(r03F7, r03D1, 0x01));

                  body.emit(assign(r03F8, r03D0, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03FB->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03FE = less(r03F5, body.constant(int(32)));
                  ir_if *f03FD = new(mem_ctx) ir_if(operand(r03FE).val);
                  exec_list *const f03FD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03FD->then_instructions;

                     body.emit(assign(r03F6, lshift(r03D1, r03F9), 0x01));

                     ir_expression *const r03FF = lshift(r03D0, r03F9);
                     ir_expression *const r0400 = rshift(r03D1, r03F5);
                     body.emit(assign(r03F7, bit_or(r03FF, r0400), 0x01));

                     body.emit(assign(r03F8, rshift(r03D0, r03F5), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03FD->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0402 = equal(r03F5, body.constant(int(32)));
                     ir_if *f0401 = new(mem_ctx) ir_if(operand(r0402).val);
                     exec_list *const f0401_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0401->then_instructions;

                        body.emit(assign(r03F6, r03D1, 0x01));

                        body.emit(assign(r03F7, r03D0, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0401->else_instructions;

                        body.emit(assign(r03F4, bit_or(body.constant(0u), r03D1), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0404 = less(r03F5, body.constant(int(64)));
                        ir_if *f0403 = new(mem_ctx) ir_if(operand(r0404).val);
                        exec_list *const f0403_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0403->then_instructions;

                           body.emit(assign(r03F6, lshift(r03D0, r03F9), 0x01));

                           ir_expression *const r0405 = bit_and(r03F5, body.constant(int(31)));
                           body.emit(assign(r03F7, rshift(r03D0, r0405), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0403->else_instructions;

                           ir_variable *const r0406 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0408 = equal(r03F5, body.constant(int(64)));
                           ir_if *f0407 = new(mem_ctx) ir_if(operand(r0408).val);
                           exec_list *const f0407_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0407->then_instructions;

                              body.emit(assign(r0406, r03D0, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0407->else_instructions;

                              ir_expression *const r0409 = nequal(r03D0, body.constant(0u));
                              ir_expression *const r040A = expr(ir_unop_b2i, r0409);
                              body.emit(assign(r0406, expr(ir_unop_i2u, r040A), 0x01));


                           body.instructions = f0407_parent_instructions;
                           body.emit(f0407);

                           /* END IF */

                           body.emit(assign(r03F6, r0406, 0x01));

                           body.emit(assign(r03F7, body.constant(0u), 0x01));


                        body.instructions = f0403_parent_instructions;
                        body.emit(f0403);

                        /* END IF */


                     body.instructions = f0401_parent_instructions;
                     body.emit(f0401);

                     /* END IF */

                     body.emit(assign(r03F8, body.constant(0u), 0x01));


                  body.instructions = f03FD_parent_instructions;
                  body.emit(f03FD);

                  /* END IF */

                  ir_expression *const r040B = nequal(r03F4, body.constant(0u));
                  ir_expression *const r040C = expr(ir_unop_b2i, r040B);
                  ir_expression *const r040D = expr(ir_unop_i2u, r040C);
                  body.emit(assign(r03F6, bit_or(r03F6, r040D), 0x01));


               body.instructions = f03FB_parent_instructions;
               body.emit(f03FB);

               /* END IF */

               body.emit(assign(r03D0, r03F8, 0x01));

               body.emit(assign(r03D1, r03F7, 0x01));

               body.emit(assign(r03D2, r03F6, 0x01));


            body.instructions = f03EA_parent_instructions;
            body.emit(f03EA);

            /* END IF */

            body.emit(assign(r03CF, sub(r03CF, r03D3), 0x01));

            ir_variable *const r040E = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r040E, r03CF, 0x01));

            ir_variable *const r040F = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r040F, r03D0, 0x01));

            ir_variable *const r0410 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0410, r03D1, 0x01));

            ir_variable *const r0411 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0411, r03D2, 0x01));

            ir_variable *const r0412 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0412, body.constant(true), 0x01));

            ir_variable *const r0413 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0414 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0414);
            ir_expression *const r0415 = expr(ir_unop_u2i, r03D2);
            body.emit(assign(r0414, less(r0415, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0417 = gequal(r03CF, body.constant(int(2045)));
            ir_if *f0416 = new(mem_ctx) ir_if(operand(r0417).val);
            exec_list *const f0416_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0416->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0419 = less(body.constant(int(2045)), r03CF);
               ir_expression *const r041A = equal(r03CF, body.constant(int(2045)));
               ir_expression *const r041B = equal(body.constant(2097151u), r03D0);
               ir_expression *const r041C = equal(body.constant(4294967295u), r03D1);
               ir_expression *const r041D = logic_and(r041B, r041C);
               ir_expression *const r041E = logic_and(r041A, r041D);
               ir_expression *const r041F = logic_and(r041E, r0414);
               ir_expression *const r0420 = logic_or(r0419, r041F);
               ir_if *f0418 = new(mem_ctx) ir_if(operand(r0420).val);
               exec_list *const f0418_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0418->then_instructions;

                  ir_variable *const r0421 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0421);
                  ir_expression *const r0422 = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r0421, add(r0422, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0421, body.constant(0u), 0x01));

                  body.emit(assign(r0413, r0421, 0x03));

                  body.emit(assign(r0412, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0418->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0424 = less(r03CF, body.constant(int(0)));
                  ir_if *f0423 = new(mem_ctx) ir_if(operand(r0424).val);
                  exec_list *const f0423_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0423->then_instructions;

                     ir_variable *const r0425 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0425, r03D2, 0x01));

                     ir_variable *const r0426 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0426, neg(r03CF), 0x01));

                     ir_variable *const r0427 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0427);
                     ir_variable *const r0428 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0428);
                     ir_variable *const r0429 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0429);
                     ir_variable *const r042A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r042B = neg(r0426);
                     body.emit(assign(r042A, bit_and(r042B, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r042D = equal(r0426, body.constant(int(0)));
                     ir_if *f042C = new(mem_ctx) ir_if(operand(r042D).val);
                     exec_list *const f042C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f042C->then_instructions;

                        body.emit(assign(r0427, r03D2, 0x01));

                        body.emit(assign(r0428, r03D1, 0x01));

                        body.emit(assign(r0429, r03D0, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f042C->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r042F = less(r0426, body.constant(int(32)));
                        ir_if *f042E = new(mem_ctx) ir_if(operand(r042F).val);
                        exec_list *const f042E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f042E->then_instructions;

                           body.emit(assign(r0427, lshift(r03D1, r042A), 0x01));

                           ir_expression *const r0430 = lshift(r03D0, r042A);
                           ir_expression *const r0431 = rshift(r03D1, r0426);
                           body.emit(assign(r0428, bit_or(r0430, r0431), 0x01));

                           body.emit(assign(r0429, rshift(r03D0, r0426), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f042E->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0433 = equal(r0426, body.constant(int(32)));
                           ir_if *f0432 = new(mem_ctx) ir_if(operand(r0433).val);
                           exec_list *const f0432_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0432->then_instructions;

                              body.emit(assign(r0427, r03D1, 0x01));

                              body.emit(assign(r0428, r03D0, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0432->else_instructions;

                              body.emit(assign(r0425, bit_or(r03D2, r03D1), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0435 = less(r0426, body.constant(int(64)));
                              ir_if *f0434 = new(mem_ctx) ir_if(operand(r0435).val);
                              exec_list *const f0434_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0434->then_instructions;

                                 body.emit(assign(r0427, lshift(r03D0, r042A), 0x01));

                                 ir_expression *const r0436 = bit_and(r0426, body.constant(int(31)));
                                 body.emit(assign(r0428, rshift(r03D0, r0436), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0434->else_instructions;

                                 ir_variable *const r0437 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0439 = equal(r0426, body.constant(int(64)));
                                 ir_if *f0438 = new(mem_ctx) ir_if(operand(r0439).val);
                                 exec_list *const f0438_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0438->then_instructions;

                                    body.emit(assign(r0437, r03D0, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0438->else_instructions;

                                    ir_expression *const r043A = nequal(r03D0, body.constant(0u));
                                    ir_expression *const r043B = expr(ir_unop_b2i, r043A);
                                    body.emit(assign(r0437, expr(ir_unop_i2u, r043B), 0x01));


                                 body.instructions = f0438_parent_instructions;
                                 body.emit(f0438);

                                 /* END IF */

                                 body.emit(assign(r0427, r0437, 0x01));

                                 body.emit(assign(r0428, body.constant(0u), 0x01));


                              body.instructions = f0434_parent_instructions;
                              body.emit(f0434);

                              /* END IF */


                           body.instructions = f0432_parent_instructions;
                           body.emit(f0432);

                           /* END IF */

                           body.emit(assign(r0429, body.constant(0u), 0x01));


                        body.instructions = f042E_parent_instructions;
                        body.emit(f042E);

                        /* END IF */

                        ir_expression *const r043C = nequal(r0425, body.constant(0u));
                        ir_expression *const r043D = expr(ir_unop_b2i, r043C);
                        ir_expression *const r043E = expr(ir_unop_i2u, r043D);
                        body.emit(assign(r0427, bit_or(r0427, r043E), 0x01));


                     body.instructions = f042C_parent_instructions;
                     body.emit(f042C);

                     /* END IF */

                     body.emit(assign(r040F, r0429, 0x01));

                     body.emit(assign(r0410, r0428, 0x01));

                     body.emit(assign(r0411, r0427, 0x01));

                     body.emit(assign(r040E, body.constant(int(0)), 0x01));

                     body.emit(assign(r0414, less(r0427, body.constant(0u)), 0x01));


                  body.instructions = f0423_parent_instructions;
                  body.emit(f0423);

                  /* END IF */


               body.instructions = f0418_parent_instructions;
               body.emit(f0418);

               /* END IF */


            body.instructions = f0416_parent_instructions;
            body.emit(f0416);

            /* END IF */

            /* IF CONDITION */
            ir_if *f043F = new(mem_ctx) ir_if(operand(r0412).val);
            exec_list *const f043F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f043F->then_instructions;

               /* IF CONDITION */
               ir_if *f0440 = new(mem_ctx) ir_if(operand(r0414).val);
               exec_list *const f0440_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0440->then_instructions;

                  ir_variable *const r0441 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0441, add(r0410, body.constant(1u)), 0x01));

                  ir_expression *const r0442 = less(r0441, r0410);
                  ir_expression *const r0443 = expr(ir_unop_b2i, r0442);
                  ir_expression *const r0444 = expr(ir_unop_i2u, r0443);
                  body.emit(assign(r040F, add(r040F, r0444), 0x01));

                  ir_expression *const r0445 = equal(r0411, body.constant(0u));
                  ir_expression *const r0446 = expr(ir_unop_b2i, r0445);
                  ir_expression *const r0447 = expr(ir_unop_i2u, r0446);
                  ir_expression *const r0448 = add(r0411, r0447);
                  ir_expression *const r0449 = bit_and(r0448, body.constant(1u));
                  ir_expression *const r044A = expr(ir_unop_bit_not, r0449);
                  body.emit(assign(r0410, bit_and(r0441, r044A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0440->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r044C = bit_or(r040F, r0410);
                  ir_expression *const r044D = equal(r044C, body.constant(0u));
                  ir_if *f044B = new(mem_ctx) ir_if(operand(r044D).val);
                  exec_list *const f044B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f044B->then_instructions;

                     body.emit(assign(r040E, body.constant(int(0)), 0x01));


                  body.instructions = f044B_parent_instructions;
                  body.emit(f044B);

                  /* END IF */


               body.instructions = f0440_parent_instructions;
               body.emit(f0440);

               /* END IF */

               ir_variable *const r044E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r044E);
               ir_expression *const r044F = lshift(r01E4, body.constant(int(31)));
               ir_expression *const r0450 = expr(ir_unop_i2u, r040E);
               ir_expression *const r0451 = lshift(r0450, body.constant(int(20)));
               ir_expression *const r0452 = add(r044F, r0451);
               body.emit(assign(r044E, add(r0452, r040F), 0x02));

               body.emit(assign(r044E, r0410, 0x01));

               body.emit(assign(r0413, r044E, 0x03));

               body.emit(assign(r0412, body.constant(false), 0x01));


            body.instructions = f043F_parent_instructions;
            body.emit(f043F);

            /* END IF */

            body.emit(assign(r01E2, r0413, 0x03));

            body.emit(assign(r01E1, body.constant(false), 0x01));


         body.instructions = f038E_parent_instructions;
         body.emit(f038E);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f038C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0454 = less(r0374, body.constant(int(0)));
         ir_if *f0453 = new(mem_ctx) ir_if(operand(r0454).val);
         exec_list *const f0453_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0453->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0456 = equal(r037F, body.constant(int(2047)));
            ir_if *f0455 = new(mem_ctx) ir_if(operand(r0456).val);
            exec_list *const f0455_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0455->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0458 = bit_or(r0377, r0378);
               ir_expression *const r0459 = nequal(r0458, body.constant(0u));
               ir_if *f0457 = new(mem_ctx) ir_if(operand(r0459).val);
               exec_list *const f0457_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0457->then_instructions;

                  ir_variable *const r045A = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r045A, swizzle_x(r01DF), 0x01));

                  ir_variable *const r045B = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r045B, swizzle_x(r01E0), 0x01));

                  ir_variable *const r045C = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r045D = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r045E = lshift(swizzle_y(r01E0), body.constant(int(1)));
                  ir_expression *const r045F = gequal(r045E, body.constant(4292870144u));
                  ir_expression *const r0460 = nequal(swizzle_x(r01E0), body.constant(0u));
                  ir_expression *const r0461 = bit_and(swizzle_y(r01E0), body.constant(1048575u));
                  ir_expression *const r0462 = nequal(r0461, body.constant(0u));
                  ir_expression *const r0463 = logic_or(r0460, r0462);
                  body.emit(assign(r045D, logic_and(r045F, r0463), 0x01));

                  body.emit(assign(r045A, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

                  body.emit(assign(r045B, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0465 = lshift(swizzle_y(r01DF), body.constant(int(1)));
                  ir_expression *const r0466 = gequal(r0465, body.constant(4292870144u));
                  ir_expression *const r0467 = nequal(swizzle_x(r01DF), body.constant(0u));
                  ir_expression *const r0468 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
                  ir_expression *const r0469 = nequal(r0468, body.constant(0u));
                  ir_expression *const r046A = logic_or(r0467, r0469);
                  ir_expression *const r046B = logic_and(r0466, r046A);
                  ir_if *f0464 = new(mem_ctx) ir_if(operand(r046B).val);
                  exec_list *const f0464_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0464->then_instructions;

                     ir_variable *const r046C = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f046D = new(mem_ctx) ir_if(operand(r045D).val);
                     exec_list *const f046D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f046D->then_instructions;

                        body.emit(assign(r046C, r045B, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f046D->else_instructions;

                        body.emit(assign(r046C, r045A, 0x03));


                     body.instructions = f046D_parent_instructions;
                     body.emit(f046D);

                     /* END IF */

                     body.emit(assign(r045C, r046C, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0464->else_instructions;

                     body.emit(assign(r045C, r045B, 0x03));


                  body.instructions = f0464_parent_instructions;
                  body.emit(f0464);

                  /* END IF */

                  body.emit(assign(r01E2, r045C, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0457->else_instructions;

                  ir_variable *const r046E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r046E);
                  ir_expression *const r046F = bit_xor(r01E4, body.constant(1u));
                  ir_expression *const r0470 = lshift(r046F, body.constant(int(31)));
                  body.emit(assign(r046E, add(r0470, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r046E, body.constant(0u), 0x01));

                  body.emit(assign(r01E2, r046E, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f0457_parent_instructions;
               body.emit(f0457);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0455->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0472 = equal(r037C, body.constant(int(0)));
               ir_if *f0471 = new(mem_ctx) ir_if(operand(r0472).val);
               exec_list *const f0471_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0471->then_instructions;

                  body.emit(assign(r0374, add(r0374, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0471->else_instructions;

                  body.emit(assign(r0379, bit_or(r0379, body.constant(1073741824u)), 0x01));


               body.instructions = f0471_parent_instructions;
               body.emit(f0471);

               /* END IF */

               ir_variable *const r0473 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0473, neg(r0374), 0x01));

               ir_variable *const r0474 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0474);
               ir_variable *const r0475 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0475);
               ir_variable *const r0476 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0477 = neg(r0473);
               body.emit(assign(r0476, bit_and(r0477, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0479 = equal(r0473, body.constant(int(0)));
               ir_if *f0478 = new(mem_ctx) ir_if(operand(r0479).val);
               exec_list *const f0478_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0478->then_instructions;

                  body.emit(assign(r0474, r0382, 0x01));

                  body.emit(assign(r0475, r0379, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0478->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r047B = less(r0473, body.constant(int(32)));
                  ir_if *f047A = new(mem_ctx) ir_if(operand(r047B).val);
                  exec_list *const f047A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f047A->then_instructions;

                     ir_expression *const r047C = lshift(r0379, r0476);
                     ir_expression *const r047D = rshift(r0382, r0473);
                     ir_expression *const r047E = bit_or(r047C, r047D);
                     ir_expression *const r047F = lshift(r0382, r0476);
                     ir_expression *const r0480 = nequal(r047F, body.constant(0u));
                     ir_expression *const r0481 = expr(ir_unop_b2i, r0480);
                     ir_expression *const r0482 = expr(ir_unop_i2u, r0481);
                     body.emit(assign(r0474, bit_or(r047E, r0482), 0x01));

                     body.emit(assign(r0475, rshift(r0379, r0473), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f047A->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0484 = equal(r0473, body.constant(int(32)));
                     ir_if *f0483 = new(mem_ctx) ir_if(operand(r0484).val);
                     exec_list *const f0483_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0483->then_instructions;

                        ir_expression *const r0485 = nequal(r0382, body.constant(0u));
                        ir_expression *const r0486 = expr(ir_unop_b2i, r0485);
                        ir_expression *const r0487 = expr(ir_unop_i2u, r0486);
                        body.emit(assign(r0474, bit_or(r0379, r0487), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0483->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0489 = less(r0473, body.constant(int(64)));
                        ir_if *f0488 = new(mem_ctx) ir_if(operand(r0489).val);
                        exec_list *const f0488_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0488->then_instructions;

                           ir_expression *const r048A = bit_and(r0473, body.constant(int(31)));
                           ir_expression *const r048B = rshift(r0379, r048A);
                           ir_expression *const r048C = lshift(r0379, r0476);
                           ir_expression *const r048D = bit_or(r048C, r0382);
                           ir_expression *const r048E = nequal(r048D, body.constant(0u));
                           ir_expression *const r048F = expr(ir_unop_b2i, r048E);
                           ir_expression *const r0490 = expr(ir_unop_i2u, r048F);
                           body.emit(assign(r0474, bit_or(r048B, r0490), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0488->else_instructions;

                           ir_expression *const r0491 = bit_or(r0379, r0382);
                           ir_expression *const r0492 = nequal(r0491, body.constant(0u));
                           ir_expression *const r0493 = expr(ir_unop_b2i, r0492);
                           body.emit(assign(r0474, expr(ir_unop_i2u, r0493), 0x01));


                        body.instructions = f0488_parent_instructions;
                        body.emit(f0488);

                        /* END IF */


                     body.instructions = f0483_parent_instructions;
                     body.emit(f0483);

                     /* END IF */

                     body.emit(assign(r0475, body.constant(0u), 0x01));


                  body.instructions = f047A_parent_instructions;
                  body.emit(f047A);

                  /* END IF */


               body.instructions = f0478_parent_instructions;
               body.emit(f0478);

               /* END IF */

               body.emit(assign(r0379, r0475, 0x01));

               body.emit(assign(r037A, r0474, 0x01));

               body.emit(assign(r0377, bit_or(r0377, body.constant(1073741824u)), 0x01));

               ir_variable *const r0494 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0495 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0495, sub(r0378, r0474), 0x01));

               ir_expression *const r0496 = sub(r0377, r0475);
               ir_expression *const r0497 = less(r0378, r0474);
               ir_expression *const r0498 = expr(ir_unop_b2i, r0497);
               ir_expression *const r0499 = expr(ir_unop_i2u, r0498);
               body.emit(assign(r0494, sub(r0496, r0499), 0x01));

               body.emit(assign(r01E3, bit_xor(r01E4, body.constant(1u)), 0x01));

               body.emit(assign(r037B, add(r037F, body.constant(int(-1))), 0x01));

               ir_variable *const r049A = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r049A, add(r037B, body.constant(int(-10))), 0x01));

               ir_variable *const r049B = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r049B, r0494, 0x01));

               ir_variable *const r049C = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r049C, r0495, 0x01));

               ir_variable *const r049D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r049D);
               ir_variable *const r049E = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r049E);
               /* IF CONDITION */
               ir_expression *const r04A0 = equal(r0494, body.constant(0u));
               ir_if *f049F = new(mem_ctx) ir_if(operand(r04A0).val);
               exec_list *const f049F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f049F->then_instructions;

                  body.emit(assign(r049B, r0495, 0x01));

                  body.emit(assign(r049C, body.constant(0u), 0x01));

                  body.emit(assign(r049A, add(r049A, body.constant(int(-32))), 0x01));


               body.instructions = f049F_parent_instructions;
               body.emit(f049F);

               /* END IF */

               ir_variable *const r04A1 = body.make_temp(glsl_type::uint_type, "a");
               body.emit(assign(r04A1, r049B, 0x01));

               ir_variable *const r04A2 = body.make_temp(glsl_type::int_type, "return_value");
               ir_variable *const r04A3 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04A3);
               /* IF CONDITION */
               ir_expression *const r04A5 = equal(r049B, body.constant(0u));
               ir_if *f04A4 = new(mem_ctx) ir_if(operand(r04A5).val);
               exec_list *const f04A4_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04A4->then_instructions;

                  body.emit(assign(r04A2, body.constant(int(32)), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04A4->else_instructions;

                  body.emit(assign(r04A3, body.constant(int(0)), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04A7 = bit_and(r049B, body.constant(4294901760u));
                  ir_expression *const r04A8 = equal(r04A7, body.constant(0u));
                  ir_if *f04A6 = new(mem_ctx) ir_if(operand(r04A8).val);
                  exec_list *const f04A6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A6->then_instructions;

                     body.emit(assign(r04A3, body.constant(int(16)), 0x01));

                     body.emit(assign(r04A1, lshift(r049B, body.constant(int(16))), 0x01));


                  body.instructions = f04A6_parent_instructions;
                  body.emit(f04A6);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04AA = bit_and(r04A1, body.constant(4278190080u));
                  ir_expression *const r04AB = equal(r04AA, body.constant(0u));
                  ir_if *f04A9 = new(mem_ctx) ir_if(operand(r04AB).val);
                  exec_list *const f04A9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A9->then_instructions;

                     body.emit(assign(r04A3, add(r04A3, body.constant(int(8))), 0x01));

                     body.emit(assign(r04A1, lshift(r04A1, body.constant(int(8))), 0x01));


                  body.instructions = f04A9_parent_instructions;
                  body.emit(f04A9);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04AD = bit_and(r04A1, body.constant(4026531840u));
                  ir_expression *const r04AE = equal(r04AD, body.constant(0u));
                  ir_if *f04AC = new(mem_ctx) ir_if(operand(r04AE).val);
                  exec_list *const f04AC_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04AC->then_instructions;

                     body.emit(assign(r04A3, add(r04A3, body.constant(int(4))), 0x01));

                     body.emit(assign(r04A1, lshift(r04A1, body.constant(int(4))), 0x01));


                  body.instructions = f04AC_parent_instructions;
                  body.emit(f04AC);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04B0 = bit_and(r04A1, body.constant(3221225472u));
                  ir_expression *const r04B1 = equal(r04B0, body.constant(0u));
                  ir_if *f04AF = new(mem_ctx) ir_if(operand(r04B1).val);
                  exec_list *const f04AF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04AF->then_instructions;

                     body.emit(assign(r04A3, add(r04A3, body.constant(int(2))), 0x01));

                     body.emit(assign(r04A1, lshift(r04A1, body.constant(int(2))), 0x01));


                  body.instructions = f04AF_parent_instructions;
                  body.emit(f04AF);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04B3 = bit_and(r04A1, body.constant(2147483648u));
                  ir_expression *const r04B4 = equal(r04B3, body.constant(0u));
                  ir_if *f04B2 = new(mem_ctx) ir_if(operand(r04B4).val);
                  exec_list *const f04B2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04B2->then_instructions;

                     body.emit(assign(r04A3, add(r04A3, body.constant(int(1))), 0x01));


                  body.instructions = f04B2_parent_instructions;
                  body.emit(f04B2);

                  /* END IF */

                  body.emit(assign(r04A2, r04A3, 0x01));


               body.instructions = f04A4_parent_instructions;
               body.emit(f04A4);

               /* END IF */

               body.emit(assign(r049E, add(r04A2, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04B6 = gequal(r049E, body.constant(int(0)));
               ir_if *f04B5 = new(mem_ctx) ir_if(operand(r04B6).val);
               exec_list *const f04B5_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04B5->then_instructions;

                  body.emit(assign(r049D, body.constant(0u), 0x01));

                  ir_variable *const r04B7 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r04B7, lshift(r049C, r049E), 0x01));

                  ir_variable *const r04B8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r04BA = equal(r049E, body.constant(int(0)));
                  ir_if *f04B9 = new(mem_ctx) ir_if(operand(r04BA).val);
                  exec_list *const f04B9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04B9->then_instructions;

                     body.emit(assign(r04B8, r049B, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04B9->else_instructions;

                     ir_expression *const r04BB = lshift(r049B, r049E);
                     ir_expression *const r04BC = neg(r049E);
                     ir_expression *const r04BD = bit_and(r04BC, body.constant(int(31)));
                     ir_expression *const r04BE = rshift(r049C, r04BD);
                     body.emit(assign(r04B8, bit_or(r04BB, r04BE), 0x01));


                  body.instructions = f04B9_parent_instructions;
                  body.emit(f04B9);

                  /* END IF */

                  body.emit(assign(r049B, r04B8, 0x01));

                  body.emit(assign(r049C, r04B7, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04B5->else_instructions;

                  ir_variable *const r04BF = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r04BF, body.constant(0u), 0x01));

                  ir_variable *const r04C0 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r04C0, neg(r049E), 0x01));

                  ir_variable *const r04C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04C1);
                  ir_variable *const r04C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r04C2);
                  ir_variable *const r04C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04C3);
                  ir_variable *const r04C4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04C5 = neg(r04C0);
                  body.emit(assign(r04C4, bit_and(r04C5, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04C7 = equal(r04C0, body.constant(int(0)));
                  ir_if *f04C6 = new(mem_ctx) ir_if(operand(r04C7).val);
                  exec_list *const f04C6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C6->then_instructions;

                     body.emit(assign(r04C1, r04BF, 0x01));

                     body.emit(assign(r04C2, r049C, 0x01));

                     body.emit(assign(r04C3, r049B, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04C6->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04C9 = less(r04C0, body.constant(int(32)));
                     ir_if *f04C8 = new(mem_ctx) ir_if(operand(r04C9).val);
                     exec_list *const f04C8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04C8->then_instructions;

                        body.emit(assign(r04C1, lshift(r049C, r04C4), 0x01));

                        ir_expression *const r04CA = lshift(r049B, r04C4);
                        ir_expression *const r04CB = rshift(r049C, r04C0);
                        body.emit(assign(r04C2, bit_or(r04CA, r04CB), 0x01));

                        body.emit(assign(r04C3, rshift(r049B, r04C0), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04C8->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04CD = equal(r04C0, body.constant(int(32)));
                        ir_if *f04CC = new(mem_ctx) ir_if(operand(r04CD).val);
                        exec_list *const f04CC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04CC->then_instructions;

                           body.emit(assign(r04C1, r049C, 0x01));

                           body.emit(assign(r04C2, r049B, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04CC->else_instructions;

                           body.emit(assign(r04BF, bit_or(body.constant(0u), r049C), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r04CF = less(r04C0, body.constant(int(64)));
                           ir_if *f04CE = new(mem_ctx) ir_if(operand(r04CF).val);
                           exec_list *const f04CE_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04CE->then_instructions;

                              body.emit(assign(r04C1, lshift(r049B, r04C4), 0x01));

                              ir_expression *const r04D0 = bit_and(r04C0, body.constant(int(31)));
                              body.emit(assign(r04C2, rshift(r049B, r04D0), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04CE->else_instructions;

                              ir_variable *const r04D1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r04D3 = equal(r04C0, body.constant(int(64)));
                              ir_if *f04D2 = new(mem_ctx) ir_if(operand(r04D3).val);
                              exec_list *const f04D2_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04D2->then_instructions;

                                 body.emit(assign(r04D1, r049B, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04D2->else_instructions;

                                 ir_expression *const r04D4 = nequal(r049B, body.constant(0u));
                                 ir_expression *const r04D5 = expr(ir_unop_b2i, r04D4);
                                 body.emit(assign(r04D1, expr(ir_unop_i2u, r04D5), 0x01));


                              body.instructions = f04D2_parent_instructions;
                              body.emit(f04D2);

                              /* END IF */

                              body.emit(assign(r04C1, r04D1, 0x01));

                              body.emit(assign(r04C2, body.constant(0u), 0x01));


                           body.instructions = f04CE_parent_instructions;
                           body.emit(f04CE);

                           /* END IF */


                        body.instructions = f04CC_parent_instructions;
                        body.emit(f04CC);

                        /* END IF */

                        body.emit(assign(r04C3, body.constant(0u), 0x01));


                     body.instructions = f04C8_parent_instructions;
                     body.emit(f04C8);

                     /* END IF */

                     ir_expression *const r04D6 = nequal(r04BF, body.constant(0u));
                     ir_expression *const r04D7 = expr(ir_unop_b2i, r04D6);
                     ir_expression *const r04D8 = expr(ir_unop_i2u, r04D7);
                     body.emit(assign(r04C1, bit_or(r04C1, r04D8), 0x01));


                  body.instructions = f04C6_parent_instructions;
                  body.emit(f04C6);

                  /* END IF */

                  body.emit(assign(r049B, r04C3, 0x01));

                  body.emit(assign(r049C, r04C2, 0x01));

                  body.emit(assign(r049D, r04C1, 0x01));


               body.instructions = f04B5_parent_instructions;
               body.emit(f04B5);

               /* END IF */

               body.emit(assign(r049A, sub(r049A, r049E), 0x01));

               ir_variable *const r04D9 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04D9, r049A, 0x01));

               ir_variable *const r04DA = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04DA, r049B, 0x01));

               ir_variable *const r04DB = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04DB, r049C, 0x01));

               ir_variable *const r04DC = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r04DC, r049D, 0x01));

               ir_variable *const r04DD = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r04DD, body.constant(true), 0x01));

               ir_variable *const r04DE = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04DF = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r04DF);
               ir_expression *const r04E0 = expr(ir_unop_u2i, r049D);
               body.emit(assign(r04DF, less(r04E0, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04E2 = gequal(r049A, body.constant(int(2045)));
               ir_if *f04E1 = new(mem_ctx) ir_if(operand(r04E2).val);
               exec_list *const f04E1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04E1->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04E4 = less(body.constant(int(2045)), r049A);
                  ir_expression *const r04E5 = equal(r049A, body.constant(int(2045)));
                  ir_expression *const r04E6 = equal(body.constant(2097151u), r049B);
                  ir_expression *const r04E7 = equal(body.constant(4294967295u), r049C);
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
                     ir_expression *const r04ED = lshift(r01E3, body.constant(int(31)));
                     body.emit(assign(r04EC, add(r04ED, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r04EC, body.constant(0u), 0x01));

                     body.emit(assign(r04DE, r04EC, 0x03));

                     body.emit(assign(r04DD, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04E3->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04EF = less(r049A, body.constant(int(0)));
                     ir_if *f04EE = new(mem_ctx) ir_if(operand(r04EF).val);
                     exec_list *const f04EE_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04EE->then_instructions;

                        ir_variable *const r04F0 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r04F0, r049D, 0x01));

                        ir_variable *const r04F1 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r04F1, neg(r049A), 0x01));

                        ir_variable *const r04F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r04F2);
                        ir_variable *const r04F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r04F3);
                        ir_variable *const r04F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r04F4);
                        ir_variable *const r04F5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r04F6 = neg(r04F1);
                        body.emit(assign(r04F5, bit_and(r04F6, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r04F8 = equal(r04F1, body.constant(int(0)));
                        ir_if *f04F7 = new(mem_ctx) ir_if(operand(r04F8).val);
                        exec_list *const f04F7_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04F7->then_instructions;

                           body.emit(assign(r04F2, r049D, 0x01));

                           body.emit(assign(r04F3, r049C, 0x01));

                           body.emit(assign(r04F4, r049B, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04F7->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r04FA = less(r04F1, body.constant(int(32)));
                           ir_if *f04F9 = new(mem_ctx) ir_if(operand(r04FA).val);
                           exec_list *const f04F9_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04F9->then_instructions;

                              body.emit(assign(r04F2, lshift(r049C, r04F5), 0x01));

                              ir_expression *const r04FB = lshift(r049B, r04F5);
                              ir_expression *const r04FC = rshift(r049C, r04F1);
                              body.emit(assign(r04F3, bit_or(r04FB, r04FC), 0x01));

                              body.emit(assign(r04F4, rshift(r049B, r04F1), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04F9->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r04FE = equal(r04F1, body.constant(int(32)));
                              ir_if *f04FD = new(mem_ctx) ir_if(operand(r04FE).val);
                              exec_list *const f04FD_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04FD->then_instructions;

                                 body.emit(assign(r04F2, r049C, 0x01));

                                 body.emit(assign(r04F3, r049B, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04FD->else_instructions;

                                 body.emit(assign(r04F0, bit_or(r049D, r049C), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0500 = less(r04F1, body.constant(int(64)));
                                 ir_if *f04FF = new(mem_ctx) ir_if(operand(r0500).val);
                                 exec_list *const f04FF_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f04FF->then_instructions;

                                    body.emit(assign(r04F2, lshift(r049B, r04F5), 0x01));

                                    ir_expression *const r0501 = bit_and(r04F1, body.constant(int(31)));
                                    body.emit(assign(r04F3, rshift(r049B, r0501), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f04FF->else_instructions;

                                    ir_variable *const r0502 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r0504 = equal(r04F1, body.constant(int(64)));
                                    ir_if *f0503 = new(mem_ctx) ir_if(operand(r0504).val);
                                    exec_list *const f0503_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0503->then_instructions;

                                       body.emit(assign(r0502, r049B, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0503->else_instructions;

                                       ir_expression *const r0505 = nequal(r049B, body.constant(0u));
                                       ir_expression *const r0506 = expr(ir_unop_b2i, r0505);
                                       body.emit(assign(r0502, expr(ir_unop_i2u, r0506), 0x01));


                                    body.instructions = f0503_parent_instructions;
                                    body.emit(f0503);

                                    /* END IF */

                                    body.emit(assign(r04F2, r0502, 0x01));

                                    body.emit(assign(r04F3, body.constant(0u), 0x01));


                                 body.instructions = f04FF_parent_instructions;
                                 body.emit(f04FF);

                                 /* END IF */


                              body.instructions = f04FD_parent_instructions;
                              body.emit(f04FD);

                              /* END IF */

                              body.emit(assign(r04F4, body.constant(0u), 0x01));


                           body.instructions = f04F9_parent_instructions;
                           body.emit(f04F9);

                           /* END IF */

                           ir_expression *const r0507 = nequal(r04F0, body.constant(0u));
                           ir_expression *const r0508 = expr(ir_unop_b2i, r0507);
                           ir_expression *const r0509 = expr(ir_unop_i2u, r0508);
                           body.emit(assign(r04F2, bit_or(r04F2, r0509), 0x01));


                        body.instructions = f04F7_parent_instructions;
                        body.emit(f04F7);

                        /* END IF */

                        body.emit(assign(r04DA, r04F4, 0x01));

                        body.emit(assign(r04DB, r04F3, 0x01));

                        body.emit(assign(r04DC, r04F2, 0x01));

                        body.emit(assign(r04D9, body.constant(int(0)), 0x01));

                        body.emit(assign(r04DF, less(r04F2, body.constant(0u)), 0x01));


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
               ir_if *f050A = new(mem_ctx) ir_if(operand(r04DD).val);
               exec_list *const f050A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f050A->then_instructions;

                  /* IF CONDITION */
                  ir_if *f050B = new(mem_ctx) ir_if(operand(r04DF).val);
                  exec_list *const f050B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f050B->then_instructions;

                     ir_variable *const r050C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r050C, add(r04DB, body.constant(1u)), 0x01));

                     ir_expression *const r050D = less(r050C, r04DB);
                     ir_expression *const r050E = expr(ir_unop_b2i, r050D);
                     ir_expression *const r050F = expr(ir_unop_i2u, r050E);
                     body.emit(assign(r04DA, add(r04DA, r050F), 0x01));

                     ir_expression *const r0510 = equal(r04DC, body.constant(0u));
                     ir_expression *const r0511 = expr(ir_unop_b2i, r0510);
                     ir_expression *const r0512 = expr(ir_unop_i2u, r0511);
                     ir_expression *const r0513 = add(r04DC, r0512);
                     ir_expression *const r0514 = bit_and(r0513, body.constant(1u));
                     ir_expression *const r0515 = expr(ir_unop_bit_not, r0514);
                     body.emit(assign(r04DB, bit_and(r050C, r0515), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f050B->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0517 = bit_or(r04DA, r04DB);
                     ir_expression *const r0518 = equal(r0517, body.constant(0u));
                     ir_if *f0516 = new(mem_ctx) ir_if(operand(r0518).val);
                     exec_list *const f0516_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0516->then_instructions;

                        body.emit(assign(r04D9, body.constant(int(0)), 0x01));


                     body.instructions = f0516_parent_instructions;
                     body.emit(f0516);

                     /* END IF */


                  body.instructions = f050B_parent_instructions;
                  body.emit(f050B);

                  /* END IF */

                  ir_variable *const r0519 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0519);
                  ir_expression *const r051A = lshift(r01E3, body.constant(int(31)));
                  ir_expression *const r051B = expr(ir_unop_i2u, r04D9);
                  ir_expression *const r051C = lshift(r051B, body.constant(int(20)));
                  ir_expression *const r051D = add(r051A, r051C);
                  body.emit(assign(r0519, add(r051D, r04DA), 0x02));

                  body.emit(assign(r0519, r04DB, 0x01));

                  body.emit(assign(r04DE, r0519, 0x03));

                  body.emit(assign(r04DD, body.constant(false), 0x01));


               body.instructions = f050A_parent_instructions;
               body.emit(f050A);

               /* END IF */

               body.emit(assign(r01E2, r04DE, 0x03));

               body.emit(assign(r01E1, body.constant(false), 0x01));


            body.instructions = f0455_parent_instructions;
            body.emit(f0455);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0453->else_instructions;

            /* IF CONDITION */
            ir_expression *const r051F = equal(r037C, body.constant(int(2047)));
            ir_if *f051E = new(mem_ctx) ir_if(operand(r051F).val);
            exec_list *const f051E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f051E->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0521 = bit_or(r0379, r037A);
               ir_expression *const r0522 = bit_or(r0377, r0378);
               ir_expression *const r0523 = bit_or(r0521, r0522);
               ir_expression *const r0524 = nequal(r0523, body.constant(0u));
               ir_if *f0520 = new(mem_ctx) ir_if(operand(r0524).val);
               exec_list *const f0520_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0520->then_instructions;

                  ir_variable *const r0525 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0525, swizzle_x(r01DF), 0x01));

                  ir_variable *const r0526 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0526, swizzle_x(r01E0), 0x01));

                  ir_variable *const r0527 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0528 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r0529 = lshift(swizzle_y(r01E0), body.constant(int(1)));
                  ir_expression *const r052A = gequal(r0529, body.constant(4292870144u));
                  ir_expression *const r052B = nequal(swizzle_x(r01E0), body.constant(0u));
                  ir_expression *const r052C = bit_and(swizzle_y(r01E0), body.constant(1048575u));
                  ir_expression *const r052D = nequal(r052C, body.constant(0u));
                  ir_expression *const r052E = logic_or(r052B, r052D);
                  body.emit(assign(r0528, logic_and(r052A, r052E), 0x01));

                  body.emit(assign(r0525, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

                  body.emit(assign(r0526, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0530 = lshift(swizzle_y(r01DF), body.constant(int(1)));
                  ir_expression *const r0531 = gequal(r0530, body.constant(4292870144u));
                  ir_expression *const r0532 = nequal(swizzle_x(r01DF), body.constant(0u));
                  ir_expression *const r0533 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
                  ir_expression *const r0534 = nequal(r0533, body.constant(0u));
                  ir_expression *const r0535 = logic_or(r0532, r0534);
                  ir_expression *const r0536 = logic_and(r0531, r0535);
                  ir_if *f052F = new(mem_ctx) ir_if(operand(r0536).val);
                  exec_list *const f052F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f052F->then_instructions;

                     ir_variable *const r0537 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f0538 = new(mem_ctx) ir_if(operand(r0528).val);
                     exec_list *const f0538_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0538->then_instructions;

                        body.emit(assign(r0537, r0526, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0538->else_instructions;

                        body.emit(assign(r0537, r0525, 0x03));


                     body.instructions = f0538_parent_instructions;
                     body.emit(f0538);

                     /* END IF */

                     body.emit(assign(r0527, r0537, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f052F->else_instructions;

                     body.emit(assign(r0527, r0526, 0x03));


                  body.instructions = f052F_parent_instructions;
                  body.emit(f052F);

                  /* END IF */

                  body.emit(assign(r01E2, r0527, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0520->else_instructions;

                  ir_constant_data r0539_data;
                  memset(&r0539_data, 0, sizeof(ir_constant_data));
                  r0539_data.u[0] = 4294967295;
                  r0539_data.u[1] = 4294967295;
                  ir_constant *const r0539 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0539_data);
                  body.emit(assign(r01E2, r0539, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f0520_parent_instructions;
               body.emit(f0520);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f051E->else_instructions;

               ir_expression *const r053A = equal(r037C, body.constant(int(0)));
               body.emit(assign(r0375, expr(ir_triop_csel, r053A, body.constant(int(1)), r037F), 0x01));

               ir_expression *const r053B = equal(r037C, body.constant(int(0)));
               body.emit(assign(r0376, expr(ir_triop_csel, r053B, body.constant(int(1)), r037C), 0x01));

               /* IF CONDITION */
               ir_expression *const r053D = less(r0377, r0379);
               ir_if *f053C = new(mem_ctx) ir_if(operand(r053D).val);
               exec_list *const f053C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f053C->then_instructions;

                  ir_variable *const r053E = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_variable *const r053F = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r053F, sub(r037A, r0378), 0x01));

                  ir_expression *const r0540 = sub(r0379, r0377);
                  ir_expression *const r0541 = less(r037A, r0378);
                  ir_expression *const r0542 = expr(ir_unop_b2i, r0541);
                  ir_expression *const r0543 = expr(ir_unop_i2u, r0542);
                  body.emit(assign(r053E, sub(r0540, r0543), 0x01));

                  body.emit(assign(r037B, add(r0376, body.constant(int(-1))), 0x01));

                  ir_variable *const r0544 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0544, add(r037B, body.constant(int(-10))), 0x01));

                  ir_variable *const r0545 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0545, r053E, 0x01));

                  ir_variable *const r0546 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0546, r053F, 0x01));

                  ir_variable *const r0547 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r0547);
                  ir_variable *const r0548 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0548);
                  /* IF CONDITION */
                  ir_expression *const r054A = equal(r053E, body.constant(0u));
                  ir_if *f0549 = new(mem_ctx) ir_if(operand(r054A).val);
                  exec_list *const f0549_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0549->then_instructions;

                     body.emit(assign(r0545, r053F, 0x01));

                     body.emit(assign(r0546, body.constant(0u), 0x01));

                     body.emit(assign(r0544, add(r0544, body.constant(int(-32))), 0x01));


                  body.instructions = f0549_parent_instructions;
                  body.emit(f0549);

                  /* END IF */

                  ir_variable *const r054B = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r054B, r0545, 0x01));

                  ir_variable *const r054C = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r054D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r054D);
                  /* IF CONDITION */
                  ir_expression *const r054F = equal(r0545, body.constant(0u));
                  ir_if *f054E = new(mem_ctx) ir_if(operand(r054F).val);
                  exec_list *const f054E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f054E->then_instructions;

                     body.emit(assign(r054C, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f054E->else_instructions;

                     body.emit(assign(r054D, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0551 = bit_and(r0545, body.constant(4294901760u));
                     ir_expression *const r0552 = equal(r0551, body.constant(0u));
                     ir_if *f0550 = new(mem_ctx) ir_if(operand(r0552).val);
                     exec_list *const f0550_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0550->then_instructions;

                        body.emit(assign(r054D, body.constant(int(16)), 0x01));

                        body.emit(assign(r054B, lshift(r0545, body.constant(int(16))), 0x01));


                     body.instructions = f0550_parent_instructions;
                     body.emit(f0550);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0554 = bit_and(r054B, body.constant(4278190080u));
                     ir_expression *const r0555 = equal(r0554, body.constant(0u));
                     ir_if *f0553 = new(mem_ctx) ir_if(operand(r0555).val);
                     exec_list *const f0553_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0553->then_instructions;

                        body.emit(assign(r054D, add(r054D, body.constant(int(8))), 0x01));

                        body.emit(assign(r054B, lshift(r054B, body.constant(int(8))), 0x01));


                     body.instructions = f0553_parent_instructions;
                     body.emit(f0553);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0557 = bit_and(r054B, body.constant(4026531840u));
                     ir_expression *const r0558 = equal(r0557, body.constant(0u));
                     ir_if *f0556 = new(mem_ctx) ir_if(operand(r0558).val);
                     exec_list *const f0556_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0556->then_instructions;

                        body.emit(assign(r054D, add(r054D, body.constant(int(4))), 0x01));

                        body.emit(assign(r054B, lshift(r054B, body.constant(int(4))), 0x01));


                     body.instructions = f0556_parent_instructions;
                     body.emit(f0556);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r055A = bit_and(r054B, body.constant(3221225472u));
                     ir_expression *const r055B = equal(r055A, body.constant(0u));
                     ir_if *f0559 = new(mem_ctx) ir_if(operand(r055B).val);
                     exec_list *const f0559_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0559->then_instructions;

                        body.emit(assign(r054D, add(r054D, body.constant(int(2))), 0x01));

                        body.emit(assign(r054B, lshift(r054B, body.constant(int(2))), 0x01));


                     body.instructions = f0559_parent_instructions;
                     body.emit(f0559);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r055D = bit_and(r054B, body.constant(2147483648u));
                     ir_expression *const r055E = equal(r055D, body.constant(0u));
                     ir_if *f055C = new(mem_ctx) ir_if(operand(r055E).val);
                     exec_list *const f055C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f055C->then_instructions;

                        body.emit(assign(r054D, add(r054D, body.constant(int(1))), 0x01));


                     body.instructions = f055C_parent_instructions;
                     body.emit(f055C);

                     /* END IF */

                     body.emit(assign(r054C, r054D, 0x01));


                  body.instructions = f054E_parent_instructions;
                  body.emit(f054E);

                  /* END IF */

                  body.emit(assign(r0548, add(r054C, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0560 = gequal(r0548, body.constant(int(0)));
                  ir_if *f055F = new(mem_ctx) ir_if(operand(r0560).val);
                  exec_list *const f055F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f055F->then_instructions;

                     body.emit(assign(r0547, body.constant(0u), 0x01));

                     ir_variable *const r0561 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r0561, lshift(r0546, r0548), 0x01));

                     ir_variable *const r0562 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0564 = equal(r0548, body.constant(int(0)));
                     ir_if *f0563 = new(mem_ctx) ir_if(operand(r0564).val);
                     exec_list *const f0563_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0563->then_instructions;

                        body.emit(assign(r0562, r0545, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0563->else_instructions;

                        ir_expression *const r0565 = lshift(r0545, r0548);
                        ir_expression *const r0566 = neg(r0548);
                        ir_expression *const r0567 = bit_and(r0566, body.constant(int(31)));
                        ir_expression *const r0568 = rshift(r0546, r0567);
                        body.emit(assign(r0562, bit_or(r0565, r0568), 0x01));


                     body.instructions = f0563_parent_instructions;
                     body.emit(f0563);

                     /* END IF */

                     body.emit(assign(r0545, r0562, 0x01));

                     body.emit(assign(r0546, r0561, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f055F->else_instructions;

                     ir_variable *const r0569 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0569, body.constant(0u), 0x01));

                     ir_variable *const r056A = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r056A, neg(r0548), 0x01));

                     ir_variable *const r056B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r056B);
                     ir_variable *const r056C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r056C);
                     ir_variable *const r056D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r056D);
                     ir_variable *const r056E = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r056F = neg(r056A);
                     body.emit(assign(r056E, bit_and(r056F, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0571 = equal(r056A, body.constant(int(0)));
                     ir_if *f0570 = new(mem_ctx) ir_if(operand(r0571).val);
                     exec_list *const f0570_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0570->then_instructions;

                        body.emit(assign(r056B, r0569, 0x01));

                        body.emit(assign(r056C, r0546, 0x01));

                        body.emit(assign(r056D, r0545, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0570->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0573 = less(r056A, body.constant(int(32)));
                        ir_if *f0572 = new(mem_ctx) ir_if(operand(r0573).val);
                        exec_list *const f0572_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0572->then_instructions;

                           body.emit(assign(r056B, lshift(r0546, r056E), 0x01));

                           ir_expression *const r0574 = lshift(r0545, r056E);
                           ir_expression *const r0575 = rshift(r0546, r056A);
                           body.emit(assign(r056C, bit_or(r0574, r0575), 0x01));

                           body.emit(assign(r056D, rshift(r0545, r056A), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0572->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0577 = equal(r056A, body.constant(int(32)));
                           ir_if *f0576 = new(mem_ctx) ir_if(operand(r0577).val);
                           exec_list *const f0576_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0576->then_instructions;

                              body.emit(assign(r056B, r0546, 0x01));

                              body.emit(assign(r056C, r0545, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0576->else_instructions;

                              body.emit(assign(r0569, bit_or(body.constant(0u), r0546), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0579 = less(r056A, body.constant(int(64)));
                              ir_if *f0578 = new(mem_ctx) ir_if(operand(r0579).val);
                              exec_list *const f0578_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0578->then_instructions;

                                 body.emit(assign(r056B, lshift(r0545, r056E), 0x01));

                                 ir_expression *const r057A = bit_and(r056A, body.constant(int(31)));
                                 body.emit(assign(r056C, rshift(r0545, r057A), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0578->else_instructions;

                                 ir_variable *const r057B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r057D = equal(r056A, body.constant(int(64)));
                                 ir_if *f057C = new(mem_ctx) ir_if(operand(r057D).val);
                                 exec_list *const f057C_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f057C->then_instructions;

                                    body.emit(assign(r057B, r0545, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f057C->else_instructions;

                                    ir_expression *const r057E = nequal(r0545, body.constant(0u));
                                    ir_expression *const r057F = expr(ir_unop_b2i, r057E);
                                    body.emit(assign(r057B, expr(ir_unop_i2u, r057F), 0x01));


                                 body.instructions = f057C_parent_instructions;
                                 body.emit(f057C);

                                 /* END IF */

                                 body.emit(assign(r056B, r057B, 0x01));

                                 body.emit(assign(r056C, body.constant(0u), 0x01));


                              body.instructions = f0578_parent_instructions;
                              body.emit(f0578);

                              /* END IF */


                           body.instructions = f0576_parent_instructions;
                           body.emit(f0576);

                           /* END IF */

                           body.emit(assign(r056D, body.constant(0u), 0x01));


                        body.instructions = f0572_parent_instructions;
                        body.emit(f0572);

                        /* END IF */

                        ir_expression *const r0580 = nequal(r0569, body.constant(0u));
                        ir_expression *const r0581 = expr(ir_unop_b2i, r0580);
                        ir_expression *const r0582 = expr(ir_unop_i2u, r0581);
                        body.emit(assign(r056B, bit_or(r056B, r0582), 0x01));


                     body.instructions = f0570_parent_instructions;
                     body.emit(f0570);

                     /* END IF */

                     body.emit(assign(r0545, r056D, 0x01));

                     body.emit(assign(r0546, r056C, 0x01));

                     body.emit(assign(r0547, r056B, 0x01));


                  body.instructions = f055F_parent_instructions;
                  body.emit(f055F);

                  /* END IF */

                  body.emit(assign(r0544, sub(r0544, r0548), 0x01));

                  ir_variable *const r0583 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0583, r0544, 0x01));

                  ir_variable *const r0584 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0584, r0545, 0x01));

                  ir_variable *const r0585 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0585, r0546, 0x01));

                  ir_variable *const r0586 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0586, r0547, 0x01));

                  ir_variable *const r0587 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0587, body.constant(true), 0x01));

                  ir_variable *const r0588 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0589 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r0589);
                  ir_expression *const r058A = expr(ir_unop_u2i, r0547);
                  body.emit(assign(r0589, less(r058A, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r058C = gequal(r0544, body.constant(int(2045)));
                  ir_if *f058B = new(mem_ctx) ir_if(operand(r058C).val);
                  exec_list *const f058B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f058B->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r058E = less(body.constant(int(2045)), r0544);
                     ir_expression *const r058F = equal(r0544, body.constant(int(2045)));
                     ir_expression *const r0590 = equal(body.constant(2097151u), r0545);
                     ir_expression *const r0591 = equal(body.constant(4294967295u), r0546);
                     ir_expression *const r0592 = logic_and(r0590, r0591);
                     ir_expression *const r0593 = logic_and(r058F, r0592);
                     ir_expression *const r0594 = logic_and(r0593, r0589);
                     ir_expression *const r0595 = logic_or(r058E, r0594);
                     ir_if *f058D = new(mem_ctx) ir_if(operand(r0595).val);
                     exec_list *const f058D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f058D->then_instructions;

                        ir_variable *const r0596 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0596);
                        ir_expression *const r0597 = lshift(r01E3, body.constant(int(31)));
                        body.emit(assign(r0596, add(r0597, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0596, body.constant(0u), 0x01));

                        body.emit(assign(r0588, r0596, 0x03));

                        body.emit(assign(r0587, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f058D->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0599 = less(r0544, body.constant(int(0)));
                        ir_if *f0598 = new(mem_ctx) ir_if(operand(r0599).val);
                        exec_list *const f0598_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0598->then_instructions;

                           ir_variable *const r059A = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r059A, r0547, 0x01));

                           ir_variable *const r059B = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r059B, neg(r0544), 0x01));

                           ir_variable *const r059C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r059C);
                           ir_variable *const r059D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r059D);
                           ir_variable *const r059E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r059E);
                           ir_variable *const r059F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r05A0 = neg(r059B);
                           body.emit(assign(r059F, bit_and(r05A0, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r05A2 = equal(r059B, body.constant(int(0)));
                           ir_if *f05A1 = new(mem_ctx) ir_if(operand(r05A2).val);
                           exec_list *const f05A1_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05A1->then_instructions;

                              body.emit(assign(r059C, r0547, 0x01));

                              body.emit(assign(r059D, r0546, 0x01));

                              body.emit(assign(r059E, r0545, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05A1->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05A4 = less(r059B, body.constant(int(32)));
                              ir_if *f05A3 = new(mem_ctx) ir_if(operand(r05A4).val);
                              exec_list *const f05A3_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05A3->then_instructions;

                                 body.emit(assign(r059C, lshift(r0546, r059F), 0x01));

                                 ir_expression *const r05A5 = lshift(r0545, r059F);
                                 ir_expression *const r05A6 = rshift(r0546, r059B);
                                 body.emit(assign(r059D, bit_or(r05A5, r05A6), 0x01));

                                 body.emit(assign(r059E, rshift(r0545, r059B), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05A3->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05A8 = equal(r059B, body.constant(int(32)));
                                 ir_if *f05A7 = new(mem_ctx) ir_if(operand(r05A8).val);
                                 exec_list *const f05A7_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05A7->then_instructions;

                                    body.emit(assign(r059C, r0546, 0x01));

                                    body.emit(assign(r059D, r0545, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05A7->else_instructions;

                                    body.emit(assign(r059A, bit_or(r0547, r0546), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r05AA = less(r059B, body.constant(int(64)));
                                    ir_if *f05A9 = new(mem_ctx) ir_if(operand(r05AA).val);
                                    exec_list *const f05A9_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f05A9->then_instructions;

                                       body.emit(assign(r059C, lshift(r0545, r059F), 0x01));

                                       ir_expression *const r05AB = bit_and(r059B, body.constant(int(31)));
                                       body.emit(assign(r059D, rshift(r0545, r05AB), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f05A9->else_instructions;

                                       ir_variable *const r05AC = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r05AE = equal(r059B, body.constant(int(64)));
                                       ir_if *f05AD = new(mem_ctx) ir_if(operand(r05AE).val);
                                       exec_list *const f05AD_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f05AD->then_instructions;

                                          body.emit(assign(r05AC, r0545, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f05AD->else_instructions;

                                          ir_expression *const r05AF = nequal(r0545, body.constant(0u));
                                          ir_expression *const r05B0 = expr(ir_unop_b2i, r05AF);
                                          body.emit(assign(r05AC, expr(ir_unop_i2u, r05B0), 0x01));


                                       body.instructions = f05AD_parent_instructions;
                                       body.emit(f05AD);

                                       /* END IF */

                                       body.emit(assign(r059C, r05AC, 0x01));

                                       body.emit(assign(r059D, body.constant(0u), 0x01));


                                    body.instructions = f05A9_parent_instructions;
                                    body.emit(f05A9);

                                    /* END IF */


                                 body.instructions = f05A7_parent_instructions;
                                 body.emit(f05A7);

                                 /* END IF */

                                 body.emit(assign(r059E, body.constant(0u), 0x01));


                              body.instructions = f05A3_parent_instructions;
                              body.emit(f05A3);

                              /* END IF */

                              ir_expression *const r05B1 = nequal(r059A, body.constant(0u));
                              ir_expression *const r05B2 = expr(ir_unop_b2i, r05B1);
                              ir_expression *const r05B3 = expr(ir_unop_i2u, r05B2);
                              body.emit(assign(r059C, bit_or(r059C, r05B3), 0x01));


                           body.instructions = f05A1_parent_instructions;
                           body.emit(f05A1);

                           /* END IF */

                           body.emit(assign(r0584, r059E, 0x01));

                           body.emit(assign(r0585, r059D, 0x01));

                           body.emit(assign(r0586, r059C, 0x01));

                           body.emit(assign(r0583, body.constant(int(0)), 0x01));

                           body.emit(assign(r0589, less(r059C, body.constant(0u)), 0x01));


                        body.instructions = f0598_parent_instructions;
                        body.emit(f0598);

                        /* END IF */


                     body.instructions = f058D_parent_instructions;
                     body.emit(f058D);

                     /* END IF */


                  body.instructions = f058B_parent_instructions;
                  body.emit(f058B);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f05B4 = new(mem_ctx) ir_if(operand(r0587).val);
                  exec_list *const f05B4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05B4->then_instructions;

                     /* IF CONDITION */
                     ir_if *f05B5 = new(mem_ctx) ir_if(operand(r0589).val);
                     exec_list *const f05B5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05B5->then_instructions;

                        ir_variable *const r05B6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r05B6, add(r0585, body.constant(1u)), 0x01));

                        ir_expression *const r05B7 = less(r05B6, r0585);
                        ir_expression *const r05B8 = expr(ir_unop_b2i, r05B7);
                        ir_expression *const r05B9 = expr(ir_unop_i2u, r05B8);
                        body.emit(assign(r0584, add(r0584, r05B9), 0x01));

                        ir_expression *const r05BA = equal(r0586, body.constant(0u));
                        ir_expression *const r05BB = expr(ir_unop_b2i, r05BA);
                        ir_expression *const r05BC = expr(ir_unop_i2u, r05BB);
                        ir_expression *const r05BD = add(r0586, r05BC);
                        ir_expression *const r05BE = bit_and(r05BD, body.constant(1u));
                        ir_expression *const r05BF = expr(ir_unop_bit_not, r05BE);
                        body.emit(assign(r0585, bit_and(r05B6, r05BF), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05B5->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05C1 = bit_or(r0584, r0585);
                        ir_expression *const r05C2 = equal(r05C1, body.constant(0u));
                        ir_if *f05C0 = new(mem_ctx) ir_if(operand(r05C2).val);
                        exec_list *const f05C0_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05C0->then_instructions;

                           body.emit(assign(r0583, body.constant(int(0)), 0x01));


                        body.instructions = f05C0_parent_instructions;
                        body.emit(f05C0);

                        /* END IF */


                     body.instructions = f05B5_parent_instructions;
                     body.emit(f05B5);

                     /* END IF */

                     ir_variable *const r05C3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r05C3);
                     ir_expression *const r05C4 = lshift(r01E3, body.constant(int(31)));
                     ir_expression *const r05C5 = expr(ir_unop_i2u, r0583);
                     ir_expression *const r05C6 = lshift(r05C5, body.constant(int(20)));
                     ir_expression *const r05C7 = add(r05C4, r05C6);
                     body.emit(assign(r05C3, add(r05C7, r0584), 0x02));

                     body.emit(assign(r05C3, r0585, 0x01));

                     body.emit(assign(r0588, r05C3, 0x03));

                     body.emit(assign(r0587, body.constant(false), 0x01));


                  body.instructions = f05B4_parent_instructions;
                  body.emit(f05B4);

                  /* END IF */

                  body.emit(assign(r01E2, r0588, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f053C->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05C9 = less(r0379, r0377);
                  ir_if *f05C8 = new(mem_ctx) ir_if(operand(r05C9).val);
                  exec_list *const f05C8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05C8->then_instructions;

                     ir_variable *const r05CA = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_variable *const r05CB = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r05CB, sub(r0378, r037A), 0x01));

                     ir_expression *const r05CC = sub(r0377, r0379);
                     ir_expression *const r05CD = less(r0378, r037A);
                     ir_expression *const r05CE = expr(ir_unop_b2i, r05CD);
                     ir_expression *const r05CF = expr(ir_unop_i2u, r05CE);
                     body.emit(assign(r05CA, sub(r05CC, r05CF), 0x01));

                     body.emit(assign(r01E3, bit_xor(r01E3, body.constant(1u)), 0x01));

                     body.emit(assign(r037B, add(r0375, body.constant(int(-1))), 0x01));

                     ir_variable *const r05D0 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05D0, add(r037B, body.constant(int(-10))), 0x01));

                     ir_variable *const r05D1 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r05D1, r05CA, 0x01));

                     ir_variable *const r05D2 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r05D2, r05CB, 0x01));

                     ir_variable *const r05D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r05D3);
                     ir_variable *const r05D4 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05D4);
                     /* IF CONDITION */
                     ir_expression *const r05D6 = equal(r05CA, body.constant(0u));
                     ir_if *f05D5 = new(mem_ctx) ir_if(operand(r05D6).val);
                     exec_list *const f05D5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05D5->then_instructions;

                        body.emit(assign(r05D1, r05CB, 0x01));

                        body.emit(assign(r05D2, body.constant(0u), 0x01));

                        body.emit(assign(r05D0, add(r05D0, body.constant(int(-32))), 0x01));


                     body.instructions = f05D5_parent_instructions;
                     body.emit(f05D5);

                     /* END IF */

                     ir_variable *const r05D7 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r05D7, r05D1, 0x01));

                     ir_variable *const r05D8 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r05D9 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05D9);
                     /* IF CONDITION */
                     ir_expression *const r05DB = equal(r05D1, body.constant(0u));
                     ir_if *f05DA = new(mem_ctx) ir_if(operand(r05DB).val);
                     exec_list *const f05DA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05DA->then_instructions;

                        body.emit(assign(r05D8, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05DA->else_instructions;

                        body.emit(assign(r05D9, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05DD = bit_and(r05D1, body.constant(4294901760u));
                        ir_expression *const r05DE = equal(r05DD, body.constant(0u));
                        ir_if *f05DC = new(mem_ctx) ir_if(operand(r05DE).val);
                        exec_list *const f05DC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05DC->then_instructions;

                           body.emit(assign(r05D9, body.constant(int(16)), 0x01));

                           body.emit(assign(r05D7, lshift(r05D1, body.constant(int(16))), 0x01));


                        body.instructions = f05DC_parent_instructions;
                        body.emit(f05DC);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05E0 = bit_and(r05D7, body.constant(4278190080u));
                        ir_expression *const r05E1 = equal(r05E0, body.constant(0u));
                        ir_if *f05DF = new(mem_ctx) ir_if(operand(r05E1).val);
                        exec_list *const f05DF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05DF->then_instructions;

                           body.emit(assign(r05D9, add(r05D9, body.constant(int(8))), 0x01));

                           body.emit(assign(r05D7, lshift(r05D7, body.constant(int(8))), 0x01));


                        body.instructions = f05DF_parent_instructions;
                        body.emit(f05DF);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05E3 = bit_and(r05D7, body.constant(4026531840u));
                        ir_expression *const r05E4 = equal(r05E3, body.constant(0u));
                        ir_if *f05E2 = new(mem_ctx) ir_if(operand(r05E4).val);
                        exec_list *const f05E2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E2->then_instructions;

                           body.emit(assign(r05D9, add(r05D9, body.constant(int(4))), 0x01));

                           body.emit(assign(r05D7, lshift(r05D7, body.constant(int(4))), 0x01));


                        body.instructions = f05E2_parent_instructions;
                        body.emit(f05E2);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05E6 = bit_and(r05D7, body.constant(3221225472u));
                        ir_expression *const r05E7 = equal(r05E6, body.constant(0u));
                        ir_if *f05E5 = new(mem_ctx) ir_if(operand(r05E7).val);
                        exec_list *const f05E5_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E5->then_instructions;

                           body.emit(assign(r05D9, add(r05D9, body.constant(int(2))), 0x01));

                           body.emit(assign(r05D7, lshift(r05D7, body.constant(int(2))), 0x01));


                        body.instructions = f05E5_parent_instructions;
                        body.emit(f05E5);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05E9 = bit_and(r05D7, body.constant(2147483648u));
                        ir_expression *const r05EA = equal(r05E9, body.constant(0u));
                        ir_if *f05E8 = new(mem_ctx) ir_if(operand(r05EA).val);
                        exec_list *const f05E8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E8->then_instructions;

                           body.emit(assign(r05D9, add(r05D9, body.constant(int(1))), 0x01));


                        body.instructions = f05E8_parent_instructions;
                        body.emit(f05E8);

                        /* END IF */

                        body.emit(assign(r05D8, r05D9, 0x01));


                     body.instructions = f05DA_parent_instructions;
                     body.emit(f05DA);

                     /* END IF */

                     body.emit(assign(r05D4, add(r05D8, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05EC = gequal(r05D4, body.constant(int(0)));
                     ir_if *f05EB = new(mem_ctx) ir_if(operand(r05EC).val);
                     exec_list *const f05EB_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05EB->then_instructions;

                        body.emit(assign(r05D3, body.constant(0u), 0x01));

                        ir_variable *const r05ED = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r05ED, lshift(r05D2, r05D4), 0x01));

                        ir_variable *const r05EE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r05F0 = equal(r05D4, body.constant(int(0)));
                        ir_if *f05EF = new(mem_ctx) ir_if(operand(r05F0).val);
                        exec_list *const f05EF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05EF->then_instructions;

                           body.emit(assign(r05EE, r05D1, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05EF->else_instructions;

                           ir_expression *const r05F1 = lshift(r05D1, r05D4);
                           ir_expression *const r05F2 = neg(r05D4);
                           ir_expression *const r05F3 = bit_and(r05F2, body.constant(int(31)));
                           ir_expression *const r05F4 = rshift(r05D2, r05F3);
                           body.emit(assign(r05EE, bit_or(r05F1, r05F4), 0x01));


                        body.instructions = f05EF_parent_instructions;
                        body.emit(f05EF);

                        /* END IF */

                        body.emit(assign(r05D1, r05EE, 0x01));

                        body.emit(assign(r05D2, r05ED, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05EB->else_instructions;

                        ir_variable *const r05F5 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r05F5, body.constant(0u), 0x01));

                        ir_variable *const r05F6 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r05F6, neg(r05D4), 0x01));

                        ir_variable *const r05F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r05F7);
                        ir_variable *const r05F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r05F8);
                        ir_variable *const r05F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r05F9);
                        ir_variable *const r05FA = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r05FB = neg(r05F6);
                        body.emit(assign(r05FA, bit_and(r05FB, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05FD = equal(r05F6, body.constant(int(0)));
                        ir_if *f05FC = new(mem_ctx) ir_if(operand(r05FD).val);
                        exec_list *const f05FC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05FC->then_instructions;

                           body.emit(assign(r05F7, r05F5, 0x01));

                           body.emit(assign(r05F8, r05D2, 0x01));

                           body.emit(assign(r05F9, r05D1, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05FC->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05FF = less(r05F6, body.constant(int(32)));
                           ir_if *f05FE = new(mem_ctx) ir_if(operand(r05FF).val);
                           exec_list *const f05FE_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05FE->then_instructions;

                              body.emit(assign(r05F7, lshift(r05D2, r05FA), 0x01));

                              ir_expression *const r0600 = lshift(r05D1, r05FA);
                              ir_expression *const r0601 = rshift(r05D2, r05F6);
                              body.emit(assign(r05F8, bit_or(r0600, r0601), 0x01));

                              body.emit(assign(r05F9, rshift(r05D1, r05F6), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05FE->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0603 = equal(r05F6, body.constant(int(32)));
                              ir_if *f0602 = new(mem_ctx) ir_if(operand(r0603).val);
                              exec_list *const f0602_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0602->then_instructions;

                                 body.emit(assign(r05F7, r05D2, 0x01));

                                 body.emit(assign(r05F8, r05D1, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0602->else_instructions;

                                 body.emit(assign(r05F5, bit_or(body.constant(0u), r05D2), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0605 = less(r05F6, body.constant(int(64)));
                                 ir_if *f0604 = new(mem_ctx) ir_if(operand(r0605).val);
                                 exec_list *const f0604_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0604->then_instructions;

                                    body.emit(assign(r05F7, lshift(r05D1, r05FA), 0x01));

                                    ir_expression *const r0606 = bit_and(r05F6, body.constant(int(31)));
                                    body.emit(assign(r05F8, rshift(r05D1, r0606), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0604->else_instructions;

                                    ir_variable *const r0607 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r0609 = equal(r05F6, body.constant(int(64)));
                                    ir_if *f0608 = new(mem_ctx) ir_if(operand(r0609).val);
                                    exec_list *const f0608_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0608->then_instructions;

                                       body.emit(assign(r0607, r05D1, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0608->else_instructions;

                                       ir_expression *const r060A = nequal(r05D1, body.constant(0u));
                                       ir_expression *const r060B = expr(ir_unop_b2i, r060A);
                                       body.emit(assign(r0607, expr(ir_unop_i2u, r060B), 0x01));


                                    body.instructions = f0608_parent_instructions;
                                    body.emit(f0608);

                                    /* END IF */

                                    body.emit(assign(r05F7, r0607, 0x01));

                                    body.emit(assign(r05F8, body.constant(0u), 0x01));


                                 body.instructions = f0604_parent_instructions;
                                 body.emit(f0604);

                                 /* END IF */


                              body.instructions = f0602_parent_instructions;
                              body.emit(f0602);

                              /* END IF */

                              body.emit(assign(r05F9, body.constant(0u), 0x01));


                           body.instructions = f05FE_parent_instructions;
                           body.emit(f05FE);

                           /* END IF */

                           ir_expression *const r060C = nequal(r05F5, body.constant(0u));
                           ir_expression *const r060D = expr(ir_unop_b2i, r060C);
                           ir_expression *const r060E = expr(ir_unop_i2u, r060D);
                           body.emit(assign(r05F7, bit_or(r05F7, r060E), 0x01));


                        body.instructions = f05FC_parent_instructions;
                        body.emit(f05FC);

                        /* END IF */

                        body.emit(assign(r05D1, r05F9, 0x01));

                        body.emit(assign(r05D2, r05F8, 0x01));

                        body.emit(assign(r05D3, r05F7, 0x01));


                     body.instructions = f05EB_parent_instructions;
                     body.emit(f05EB);

                     /* END IF */

                     body.emit(assign(r05D0, sub(r05D0, r05D4), 0x01));

                     ir_variable *const r060F = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r060F, r05D0, 0x01));

                     ir_variable *const r0610 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0610, r05D1, 0x01));

                     ir_variable *const r0611 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r0611, r05D2, 0x01));

                     ir_variable *const r0612 = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r0612, r05D3, 0x01));

                     ir_variable *const r0613 = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r0613, body.constant(true), 0x01));

                     ir_variable *const r0614 = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r0615 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r0615);
                     ir_expression *const r0616 = expr(ir_unop_u2i, r05D3);
                     body.emit(assign(r0615, less(r0616, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0618 = gequal(r05D0, body.constant(int(2045)));
                     ir_if *f0617 = new(mem_ctx) ir_if(operand(r0618).val);
                     exec_list *const f0617_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0617->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r061A = less(body.constant(int(2045)), r05D0);
                        ir_expression *const r061B = equal(r05D0, body.constant(int(2045)));
                        ir_expression *const r061C = equal(body.constant(2097151u), r05D1);
                        ir_expression *const r061D = equal(body.constant(4294967295u), r05D2);
                        ir_expression *const r061E = logic_and(r061C, r061D);
                        ir_expression *const r061F = logic_and(r061B, r061E);
                        ir_expression *const r0620 = logic_and(r061F, r0615);
                        ir_expression *const r0621 = logic_or(r061A, r0620);
                        ir_if *f0619 = new(mem_ctx) ir_if(operand(r0621).val);
                        exec_list *const f0619_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0619->then_instructions;

                           ir_variable *const r0622 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0622);
                           ir_expression *const r0623 = lshift(r01E3, body.constant(int(31)));
                           body.emit(assign(r0622, add(r0623, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r0622, body.constant(0u), 0x01));

                           body.emit(assign(r0614, r0622, 0x03));

                           body.emit(assign(r0613, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0619->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0625 = less(r05D0, body.constant(int(0)));
                           ir_if *f0624 = new(mem_ctx) ir_if(operand(r0625).val);
                           exec_list *const f0624_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0624->then_instructions;

                              ir_variable *const r0626 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r0626, r05D3, 0x01));

                              ir_variable *const r0627 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0627, neg(r05D0), 0x01));

                              ir_variable *const r0628 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0628);
                              ir_variable *const r0629 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0629);
                              ir_variable *const r062A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r062A);
                              ir_variable *const r062B = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r062C = neg(r0627);
                              body.emit(assign(r062B, bit_and(r062C, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r062E = equal(r0627, body.constant(int(0)));
                              ir_if *f062D = new(mem_ctx) ir_if(operand(r062E).val);
                              exec_list *const f062D_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f062D->then_instructions;

                                 body.emit(assign(r0628, r05D3, 0x01));

                                 body.emit(assign(r0629, r05D2, 0x01));

                                 body.emit(assign(r062A, r05D1, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f062D->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0630 = less(r0627, body.constant(int(32)));
                                 ir_if *f062F = new(mem_ctx) ir_if(operand(r0630).val);
                                 exec_list *const f062F_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f062F->then_instructions;

                                    body.emit(assign(r0628, lshift(r05D2, r062B), 0x01));

                                    ir_expression *const r0631 = lshift(r05D1, r062B);
                                    ir_expression *const r0632 = rshift(r05D2, r0627);
                                    body.emit(assign(r0629, bit_or(r0631, r0632), 0x01));

                                    body.emit(assign(r062A, rshift(r05D1, r0627), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f062F->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0634 = equal(r0627, body.constant(int(32)));
                                    ir_if *f0633 = new(mem_ctx) ir_if(operand(r0634).val);
                                    exec_list *const f0633_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0633->then_instructions;

                                       body.emit(assign(r0628, r05D2, 0x01));

                                       body.emit(assign(r0629, r05D1, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0633->else_instructions;

                                       body.emit(assign(r0626, bit_or(r05D3, r05D2), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r0636 = less(r0627, body.constant(int(64)));
                                       ir_if *f0635 = new(mem_ctx) ir_if(operand(r0636).val);
                                       exec_list *const f0635_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0635->then_instructions;

                                          body.emit(assign(r0628, lshift(r05D1, r062B), 0x01));

                                          ir_expression *const r0637 = bit_and(r0627, body.constant(int(31)));
                                          body.emit(assign(r0629, rshift(r05D1, r0637), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0635->else_instructions;

                                          ir_variable *const r0638 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r063A = equal(r0627, body.constant(int(64)));
                                          ir_if *f0639 = new(mem_ctx) ir_if(operand(r063A).val);
                                          exec_list *const f0639_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0639->then_instructions;

                                             body.emit(assign(r0638, r05D1, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0639->else_instructions;

                                             ir_expression *const r063B = nequal(r05D1, body.constant(0u));
                                             ir_expression *const r063C = expr(ir_unop_b2i, r063B);
                                             body.emit(assign(r0638, expr(ir_unop_i2u, r063C), 0x01));


                                          body.instructions = f0639_parent_instructions;
                                          body.emit(f0639);

                                          /* END IF */

                                          body.emit(assign(r0628, r0638, 0x01));

                                          body.emit(assign(r0629, body.constant(0u), 0x01));


                                       body.instructions = f0635_parent_instructions;
                                       body.emit(f0635);

                                       /* END IF */


                                    body.instructions = f0633_parent_instructions;
                                    body.emit(f0633);

                                    /* END IF */

                                    body.emit(assign(r062A, body.constant(0u), 0x01));


                                 body.instructions = f062F_parent_instructions;
                                 body.emit(f062F);

                                 /* END IF */

                                 ir_expression *const r063D = nequal(r0626, body.constant(0u));
                                 ir_expression *const r063E = expr(ir_unop_b2i, r063D);
                                 ir_expression *const r063F = expr(ir_unop_i2u, r063E);
                                 body.emit(assign(r0628, bit_or(r0628, r063F), 0x01));


                              body.instructions = f062D_parent_instructions;
                              body.emit(f062D);

                              /* END IF */

                              body.emit(assign(r0610, r062A, 0x01));

                              body.emit(assign(r0611, r0629, 0x01));

                              body.emit(assign(r0612, r0628, 0x01));

                              body.emit(assign(r060F, body.constant(int(0)), 0x01));

                              body.emit(assign(r0615, less(r0628, body.constant(0u)), 0x01));


                           body.instructions = f0624_parent_instructions;
                           body.emit(f0624);

                           /* END IF */


                        body.instructions = f0619_parent_instructions;
                        body.emit(f0619);

                        /* END IF */


                     body.instructions = f0617_parent_instructions;
                     body.emit(f0617);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0640 = new(mem_ctx) ir_if(operand(r0613).val);
                     exec_list *const f0640_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0640->then_instructions;

                        /* IF CONDITION */
                        ir_if *f0641 = new(mem_ctx) ir_if(operand(r0615).val);
                        exec_list *const f0641_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0641->then_instructions;

                           ir_variable *const r0642 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r0642, add(r0611, body.constant(1u)), 0x01));

                           ir_expression *const r0643 = less(r0642, r0611);
                           ir_expression *const r0644 = expr(ir_unop_b2i, r0643);
                           ir_expression *const r0645 = expr(ir_unop_i2u, r0644);
                           body.emit(assign(r0610, add(r0610, r0645), 0x01));

                           ir_expression *const r0646 = equal(r0612, body.constant(0u));
                           ir_expression *const r0647 = expr(ir_unop_b2i, r0646);
                           ir_expression *const r0648 = expr(ir_unop_i2u, r0647);
                           ir_expression *const r0649 = add(r0612, r0648);
                           ir_expression *const r064A = bit_and(r0649, body.constant(1u));
                           ir_expression *const r064B = expr(ir_unop_bit_not, r064A);
                           body.emit(assign(r0611, bit_and(r0642, r064B), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0641->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r064D = bit_or(r0610, r0611);
                           ir_expression *const r064E = equal(r064D, body.constant(0u));
                           ir_if *f064C = new(mem_ctx) ir_if(operand(r064E).val);
                           exec_list *const f064C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f064C->then_instructions;

                              body.emit(assign(r060F, body.constant(int(0)), 0x01));


                           body.instructions = f064C_parent_instructions;
                           body.emit(f064C);

                           /* END IF */


                        body.instructions = f0641_parent_instructions;
                        body.emit(f0641);

                        /* END IF */

                        ir_variable *const r064F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r064F);
                        ir_expression *const r0650 = lshift(r01E3, body.constant(int(31)));
                        ir_expression *const r0651 = expr(ir_unop_i2u, r060F);
                        ir_expression *const r0652 = lshift(r0651, body.constant(int(20)));
                        ir_expression *const r0653 = add(r0650, r0652);
                        body.emit(assign(r064F, add(r0653, r0610), 0x02));

                        body.emit(assign(r064F, r0611, 0x01));

                        body.emit(assign(r0614, r064F, 0x03));

                        body.emit(assign(r0613, body.constant(false), 0x01));


                     body.instructions = f0640_parent_instructions;
                     body.emit(f0640);

                     /* END IF */

                     body.emit(assign(r01E2, r0614, 0x03));

                     body.emit(assign(r01E1, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05C8->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0655 = less(r0378, r037A);
                     ir_if *f0654 = new(mem_ctx) ir_if(operand(r0655).val);
                     exec_list *const f0654_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0654->then_instructions;

                        ir_variable *const r0656 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_variable *const r0657 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r0657, sub(r037A, r0378), 0x01));

                        ir_expression *const r0658 = sub(r0379, r0377);
                        ir_expression *const r0659 = less(r037A, r0378);
                        ir_expression *const r065A = expr(ir_unop_b2i, r0659);
                        ir_expression *const r065B = expr(ir_unop_i2u, r065A);
                        body.emit(assign(r0656, sub(r0658, r065B), 0x01));

                        body.emit(assign(r037B, add(r0376, body.constant(int(-1))), 0x01));

                        ir_variable *const r065C = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r065C, add(r037B, body.constant(int(-10))), 0x01));

                        ir_variable *const r065D = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r065D, r0656, 0x01));

                        ir_variable *const r065E = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r065E, r0657, 0x01));

                        ir_variable *const r065F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r065F);
                        ir_variable *const r0660 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0660);
                        /* IF CONDITION */
                        ir_expression *const r0662 = equal(r0656, body.constant(0u));
                        ir_if *f0661 = new(mem_ctx) ir_if(operand(r0662).val);
                        exec_list *const f0661_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0661->then_instructions;

                           body.emit(assign(r065D, r0657, 0x01));

                           body.emit(assign(r065E, body.constant(0u), 0x01));

                           body.emit(assign(r065C, add(r065C, body.constant(int(-32))), 0x01));


                        body.instructions = f0661_parent_instructions;
                        body.emit(f0661);

                        /* END IF */

                        ir_variable *const r0663 = body.make_temp(glsl_type::uint_type, "a");
                        body.emit(assign(r0663, r065D, 0x01));

                        ir_variable *const r0664 = body.make_temp(glsl_type::int_type, "return_value");
                        ir_variable *const r0665 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0665);
                        /* IF CONDITION */
                        ir_expression *const r0667 = equal(r065D, body.constant(0u));
                        ir_if *f0666 = new(mem_ctx) ir_if(operand(r0667).val);
                        exec_list *const f0666_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0666->then_instructions;

                           body.emit(assign(r0664, body.constant(int(32)), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0666->else_instructions;

                           body.emit(assign(r0665, body.constant(int(0)), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0669 = bit_and(r065D, body.constant(4294901760u));
                           ir_expression *const r066A = equal(r0669, body.constant(0u));
                           ir_if *f0668 = new(mem_ctx) ir_if(operand(r066A).val);
                           exec_list *const f0668_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0668->then_instructions;

                              body.emit(assign(r0665, body.constant(int(16)), 0x01));

                              body.emit(assign(r0663, lshift(r065D, body.constant(int(16))), 0x01));


                           body.instructions = f0668_parent_instructions;
                           body.emit(f0668);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r066C = bit_and(r0663, body.constant(4278190080u));
                           ir_expression *const r066D = equal(r066C, body.constant(0u));
                           ir_if *f066B = new(mem_ctx) ir_if(operand(r066D).val);
                           exec_list *const f066B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f066B->then_instructions;

                              body.emit(assign(r0665, add(r0665, body.constant(int(8))), 0x01));

                              body.emit(assign(r0663, lshift(r0663, body.constant(int(8))), 0x01));


                           body.instructions = f066B_parent_instructions;
                           body.emit(f066B);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r066F = bit_and(r0663, body.constant(4026531840u));
                           ir_expression *const r0670 = equal(r066F, body.constant(0u));
                           ir_if *f066E = new(mem_ctx) ir_if(operand(r0670).val);
                           exec_list *const f066E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f066E->then_instructions;

                              body.emit(assign(r0665, add(r0665, body.constant(int(4))), 0x01));

                              body.emit(assign(r0663, lshift(r0663, body.constant(int(4))), 0x01));


                           body.instructions = f066E_parent_instructions;
                           body.emit(f066E);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0672 = bit_and(r0663, body.constant(3221225472u));
                           ir_expression *const r0673 = equal(r0672, body.constant(0u));
                           ir_if *f0671 = new(mem_ctx) ir_if(operand(r0673).val);
                           exec_list *const f0671_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0671->then_instructions;

                              body.emit(assign(r0665, add(r0665, body.constant(int(2))), 0x01));

                              body.emit(assign(r0663, lshift(r0663, body.constant(int(2))), 0x01));


                           body.instructions = f0671_parent_instructions;
                           body.emit(f0671);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0675 = bit_and(r0663, body.constant(2147483648u));
                           ir_expression *const r0676 = equal(r0675, body.constant(0u));
                           ir_if *f0674 = new(mem_ctx) ir_if(operand(r0676).val);
                           exec_list *const f0674_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0674->then_instructions;

                              body.emit(assign(r0665, add(r0665, body.constant(int(1))), 0x01));


                           body.instructions = f0674_parent_instructions;
                           body.emit(f0674);

                           /* END IF */

                           body.emit(assign(r0664, r0665, 0x01));


                        body.instructions = f0666_parent_instructions;
                        body.emit(f0666);

                        /* END IF */

                        body.emit(assign(r0660, add(r0664, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0678 = gequal(r0660, body.constant(int(0)));
                        ir_if *f0677 = new(mem_ctx) ir_if(operand(r0678).val);
                        exec_list *const f0677_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0677->then_instructions;

                           body.emit(assign(r065F, body.constant(0u), 0x01));

                           ir_variable *const r0679 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r0679, lshift(r065E, r0660), 0x01));

                           ir_variable *const r067A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r067C = equal(r0660, body.constant(int(0)));
                           ir_if *f067B = new(mem_ctx) ir_if(operand(r067C).val);
                           exec_list *const f067B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f067B->then_instructions;

                              body.emit(assign(r067A, r065D, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f067B->else_instructions;

                              ir_expression *const r067D = lshift(r065D, r0660);
                              ir_expression *const r067E = neg(r0660);
                              ir_expression *const r067F = bit_and(r067E, body.constant(int(31)));
                              ir_expression *const r0680 = rshift(r065E, r067F);
                              body.emit(assign(r067A, bit_or(r067D, r0680), 0x01));


                           body.instructions = f067B_parent_instructions;
                           body.emit(f067B);

                           /* END IF */

                           body.emit(assign(r065D, r067A, 0x01));

                           body.emit(assign(r065E, r0679, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0677->else_instructions;

                           ir_variable *const r0681 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0681, body.constant(0u), 0x01));

                           ir_variable *const r0682 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0682, neg(r0660), 0x01));

                           ir_variable *const r0683 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0683);
                           ir_variable *const r0684 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0684);
                           ir_variable *const r0685 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0685);
                           ir_variable *const r0686 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0687 = neg(r0682);
                           body.emit(assign(r0686, bit_and(r0687, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0689 = equal(r0682, body.constant(int(0)));
                           ir_if *f0688 = new(mem_ctx) ir_if(operand(r0689).val);
                           exec_list *const f0688_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0688->then_instructions;

                              body.emit(assign(r0683, r0681, 0x01));

                              body.emit(assign(r0684, r065E, 0x01));

                              body.emit(assign(r0685, r065D, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0688->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r068B = less(r0682, body.constant(int(32)));
                              ir_if *f068A = new(mem_ctx) ir_if(operand(r068B).val);
                              exec_list *const f068A_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f068A->then_instructions;

                                 body.emit(assign(r0683, lshift(r065E, r0686), 0x01));

                                 ir_expression *const r068C = lshift(r065D, r0686);
                                 ir_expression *const r068D = rshift(r065E, r0682);
                                 body.emit(assign(r0684, bit_or(r068C, r068D), 0x01));

                                 body.emit(assign(r0685, rshift(r065D, r0682), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f068A->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r068F = equal(r0682, body.constant(int(32)));
                                 ir_if *f068E = new(mem_ctx) ir_if(operand(r068F).val);
                                 exec_list *const f068E_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f068E->then_instructions;

                                    body.emit(assign(r0683, r065E, 0x01));

                                    body.emit(assign(r0684, r065D, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f068E->else_instructions;

                                    body.emit(assign(r0681, bit_or(body.constant(0u), r065E), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0691 = less(r0682, body.constant(int(64)));
                                    ir_if *f0690 = new(mem_ctx) ir_if(operand(r0691).val);
                                    exec_list *const f0690_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0690->then_instructions;

                                       body.emit(assign(r0683, lshift(r065D, r0686), 0x01));

                                       ir_expression *const r0692 = bit_and(r0682, body.constant(int(31)));
                                       body.emit(assign(r0684, rshift(r065D, r0692), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0690->else_instructions;

                                       ir_variable *const r0693 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r0695 = equal(r0682, body.constant(int(64)));
                                       ir_if *f0694 = new(mem_ctx) ir_if(operand(r0695).val);
                                       exec_list *const f0694_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0694->then_instructions;

                                          body.emit(assign(r0693, r065D, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0694->else_instructions;

                                          ir_expression *const r0696 = nequal(r065D, body.constant(0u));
                                          ir_expression *const r0697 = expr(ir_unop_b2i, r0696);
                                          body.emit(assign(r0693, expr(ir_unop_i2u, r0697), 0x01));


                                       body.instructions = f0694_parent_instructions;
                                       body.emit(f0694);

                                       /* END IF */

                                       body.emit(assign(r0683, r0693, 0x01));

                                       body.emit(assign(r0684, body.constant(0u), 0x01));


                                    body.instructions = f0690_parent_instructions;
                                    body.emit(f0690);

                                    /* END IF */


                                 body.instructions = f068E_parent_instructions;
                                 body.emit(f068E);

                                 /* END IF */

                                 body.emit(assign(r0685, body.constant(0u), 0x01));


                              body.instructions = f068A_parent_instructions;
                              body.emit(f068A);

                              /* END IF */

                              ir_expression *const r0698 = nequal(r0681, body.constant(0u));
                              ir_expression *const r0699 = expr(ir_unop_b2i, r0698);
                              ir_expression *const r069A = expr(ir_unop_i2u, r0699);
                              body.emit(assign(r0683, bit_or(r0683, r069A), 0x01));


                           body.instructions = f0688_parent_instructions;
                           body.emit(f0688);

                           /* END IF */

                           body.emit(assign(r065D, r0685, 0x01));

                           body.emit(assign(r065E, r0684, 0x01));

                           body.emit(assign(r065F, r0683, 0x01));


                        body.instructions = f0677_parent_instructions;
                        body.emit(f0677);

                        /* END IF */

                        body.emit(assign(r065C, sub(r065C, r0660), 0x01));

                        ir_variable *const r069B = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r069B, r065C, 0x01));

                        ir_variable *const r069C = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r069C, r065D, 0x01));

                        ir_variable *const r069D = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r069D, r065E, 0x01));

                        ir_variable *const r069E = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r069E, r065F, 0x01));

                        ir_variable *const r069F = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r069F, body.constant(true), 0x01));

                        ir_variable *const r06A0 = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r06A1 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r06A1);
                        ir_expression *const r06A2 = expr(ir_unop_u2i, r065F);
                        body.emit(assign(r06A1, less(r06A2, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r06A4 = gequal(r065C, body.constant(int(2045)));
                        ir_if *f06A3 = new(mem_ctx) ir_if(operand(r06A4).val);
                        exec_list *const f06A3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06A3->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r06A6 = less(body.constant(int(2045)), r065C);
                           ir_expression *const r06A7 = equal(r065C, body.constant(int(2045)));
                           ir_expression *const r06A8 = equal(body.constant(2097151u), r065D);
                           ir_expression *const r06A9 = equal(body.constant(4294967295u), r065E);
                           ir_expression *const r06AA = logic_and(r06A8, r06A9);
                           ir_expression *const r06AB = logic_and(r06A7, r06AA);
                           ir_expression *const r06AC = logic_and(r06AB, r06A1);
                           ir_expression *const r06AD = logic_or(r06A6, r06AC);
                           ir_if *f06A5 = new(mem_ctx) ir_if(operand(r06AD).val);
                           exec_list *const f06A5_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06A5->then_instructions;

                              ir_variable *const r06AE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r06AE);
                              ir_expression *const r06AF = lshift(r01E3, body.constant(int(31)));
                              body.emit(assign(r06AE, add(r06AF, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r06AE, body.constant(0u), 0x01));

                              body.emit(assign(r06A0, r06AE, 0x03));

                              body.emit(assign(r069F, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06A5->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06B1 = less(r065C, body.constant(int(0)));
                              ir_if *f06B0 = new(mem_ctx) ir_if(operand(r06B1).val);
                              exec_list *const f06B0_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06B0->then_instructions;

                                 ir_variable *const r06B2 = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r06B2, r065F, 0x01));

                                 ir_variable *const r06B3 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r06B3, neg(r065C), 0x01));

                                 ir_variable *const r06B4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r06B4);
                                 ir_variable *const r06B5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r06B5);
                                 ir_variable *const r06B6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r06B6);
                                 ir_variable *const r06B7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r06B8 = neg(r06B3);
                                 body.emit(assign(r06B7, bit_and(r06B8, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r06BA = equal(r06B3, body.constant(int(0)));
                                 ir_if *f06B9 = new(mem_ctx) ir_if(operand(r06BA).val);
                                 exec_list *const f06B9_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06B9->then_instructions;

                                    body.emit(assign(r06B4, r065F, 0x01));

                                    body.emit(assign(r06B5, r065E, 0x01));

                                    body.emit(assign(r06B6, r065D, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06B9->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06BC = less(r06B3, body.constant(int(32)));
                                    ir_if *f06BB = new(mem_ctx) ir_if(operand(r06BC).val);
                                    exec_list *const f06BB_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06BB->then_instructions;

                                       body.emit(assign(r06B4, lshift(r065E, r06B7), 0x01));

                                       ir_expression *const r06BD = lshift(r065D, r06B7);
                                       ir_expression *const r06BE = rshift(r065E, r06B3);
                                       body.emit(assign(r06B5, bit_or(r06BD, r06BE), 0x01));

                                       body.emit(assign(r06B6, rshift(r065D, r06B3), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06BB->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r06C0 = equal(r06B3, body.constant(int(32)));
                                       ir_if *f06BF = new(mem_ctx) ir_if(operand(r06C0).val);
                                       exec_list *const f06BF_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06BF->then_instructions;

                                          body.emit(assign(r06B4, r065E, 0x01));

                                          body.emit(assign(r06B5, r065D, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06BF->else_instructions;

                                          body.emit(assign(r06B2, bit_or(r065F, r065E), 0x01));

                                          /* IF CONDITION */
                                          ir_expression *const r06C2 = less(r06B3, body.constant(int(64)));
                                          ir_if *f06C1 = new(mem_ctx) ir_if(operand(r06C2).val);
                                          exec_list *const f06C1_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f06C1->then_instructions;

                                             body.emit(assign(r06B4, lshift(r065D, r06B7), 0x01));

                                             ir_expression *const r06C3 = bit_and(r06B3, body.constant(int(31)));
                                             body.emit(assign(r06B5, rshift(r065D, r06C3), 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f06C1->else_instructions;

                                             ir_variable *const r06C4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                             /* IF CONDITION */
                                             ir_expression *const r06C6 = equal(r06B3, body.constant(int(64)));
                                             ir_if *f06C5 = new(mem_ctx) ir_if(operand(r06C6).val);
                                             exec_list *const f06C5_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f06C5->then_instructions;

                                                body.emit(assign(r06C4, r065D, 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f06C5->else_instructions;

                                                ir_expression *const r06C7 = nequal(r065D, body.constant(0u));
                                                ir_expression *const r06C8 = expr(ir_unop_b2i, r06C7);
                                                body.emit(assign(r06C4, expr(ir_unop_i2u, r06C8), 0x01));


                                             body.instructions = f06C5_parent_instructions;
                                             body.emit(f06C5);

                                             /* END IF */

                                             body.emit(assign(r06B4, r06C4, 0x01));

                                             body.emit(assign(r06B5, body.constant(0u), 0x01));


                                          body.instructions = f06C1_parent_instructions;
                                          body.emit(f06C1);

                                          /* END IF */


                                       body.instructions = f06BF_parent_instructions;
                                       body.emit(f06BF);

                                       /* END IF */

                                       body.emit(assign(r06B6, body.constant(0u), 0x01));


                                    body.instructions = f06BB_parent_instructions;
                                    body.emit(f06BB);

                                    /* END IF */

                                    ir_expression *const r06C9 = nequal(r06B2, body.constant(0u));
                                    ir_expression *const r06CA = expr(ir_unop_b2i, r06C9);
                                    ir_expression *const r06CB = expr(ir_unop_i2u, r06CA);
                                    body.emit(assign(r06B4, bit_or(r06B4, r06CB), 0x01));


                                 body.instructions = f06B9_parent_instructions;
                                 body.emit(f06B9);

                                 /* END IF */

                                 body.emit(assign(r069C, r06B6, 0x01));

                                 body.emit(assign(r069D, r06B5, 0x01));

                                 body.emit(assign(r069E, r06B4, 0x01));

                                 body.emit(assign(r069B, body.constant(int(0)), 0x01));

                                 body.emit(assign(r06A1, less(r06B4, body.constant(0u)), 0x01));


                              body.instructions = f06B0_parent_instructions;
                              body.emit(f06B0);

                              /* END IF */


                           body.instructions = f06A5_parent_instructions;
                           body.emit(f06A5);

                           /* END IF */


                        body.instructions = f06A3_parent_instructions;
                        body.emit(f06A3);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f06CC = new(mem_ctx) ir_if(operand(r069F).val);
                        exec_list *const f06CC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06CC->then_instructions;

                           /* IF CONDITION */
                           ir_if *f06CD = new(mem_ctx) ir_if(operand(r06A1).val);
                           exec_list *const f06CD_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06CD->then_instructions;

                              ir_variable *const r06CE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r06CE, add(r069D, body.constant(1u)), 0x01));

                              ir_expression *const r06CF = less(r06CE, r069D);
                              ir_expression *const r06D0 = expr(ir_unop_b2i, r06CF);
                              ir_expression *const r06D1 = expr(ir_unop_i2u, r06D0);
                              body.emit(assign(r069C, add(r069C, r06D1), 0x01));

                              ir_expression *const r06D2 = equal(r069E, body.constant(0u));
                              ir_expression *const r06D3 = expr(ir_unop_b2i, r06D2);
                              ir_expression *const r06D4 = expr(ir_unop_i2u, r06D3);
                              ir_expression *const r06D5 = add(r069E, r06D4);
                              ir_expression *const r06D6 = bit_and(r06D5, body.constant(1u));
                              ir_expression *const r06D7 = expr(ir_unop_bit_not, r06D6);
                              body.emit(assign(r069D, bit_and(r06CE, r06D7), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06CD->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06D9 = bit_or(r069C, r069D);
                              ir_expression *const r06DA = equal(r06D9, body.constant(0u));
                              ir_if *f06D8 = new(mem_ctx) ir_if(operand(r06DA).val);
                              exec_list *const f06D8_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06D8->then_instructions;

                                 body.emit(assign(r069B, body.constant(int(0)), 0x01));


                              body.instructions = f06D8_parent_instructions;
                              body.emit(f06D8);

                              /* END IF */


                           body.instructions = f06CD_parent_instructions;
                           body.emit(f06CD);

                           /* END IF */

                           ir_variable *const r06DB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r06DB);
                           ir_expression *const r06DC = lshift(r01E3, body.constant(int(31)));
                           ir_expression *const r06DD = expr(ir_unop_i2u, r069B);
                           ir_expression *const r06DE = lshift(r06DD, body.constant(int(20)));
                           ir_expression *const r06DF = add(r06DC, r06DE);
                           body.emit(assign(r06DB, add(r06DF, r069C), 0x02));

                           body.emit(assign(r06DB, r069D, 0x01));

                           body.emit(assign(r06A0, r06DB, 0x03));

                           body.emit(assign(r069F, body.constant(false), 0x01));


                        body.instructions = f06CC_parent_instructions;
                        body.emit(f06CC);

                        /* END IF */

                        body.emit(assign(r01E2, r06A0, 0x03));

                        body.emit(assign(r01E1, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0654->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r06E1 = less(r037A, r0378);
                        ir_if *f06E0 = new(mem_ctx) ir_if(operand(r06E1).val);
                        exec_list *const f06E0_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06E0->then_instructions;

                           ir_variable *const r06E2 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_variable *const r06E3 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r06E3, sub(r0378, r037A), 0x01));

                           ir_expression *const r06E4 = sub(r0377, r0379);
                           ir_expression *const r06E5 = less(r0378, r037A);
                           ir_expression *const r06E6 = expr(ir_unop_b2i, r06E5);
                           ir_expression *const r06E7 = expr(ir_unop_i2u, r06E6);
                           body.emit(assign(r06E2, sub(r06E4, r06E7), 0x01));

                           body.emit(assign(r01E3, bit_xor(r01E3, body.constant(1u)), 0x01));

                           body.emit(assign(r037B, add(r0375, body.constant(int(-1))), 0x01));

                           ir_variable *const r06E8 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06E8, add(r037B, body.constant(int(-10))), 0x01));

                           ir_variable *const r06E9 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r06E9, r06E2, 0x01));

                           ir_variable *const r06EA = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r06EA, r06E3, 0x01));

                           ir_variable *const r06EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r06EB);
                           ir_variable *const r06EC = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06EC);
                           /* IF CONDITION */
                           ir_expression *const r06EE = equal(r06E2, body.constant(0u));
                           ir_if *f06ED = new(mem_ctx) ir_if(operand(r06EE).val);
                           exec_list *const f06ED_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06ED->then_instructions;

                              body.emit(assign(r06E9, r06E3, 0x01));

                              body.emit(assign(r06EA, body.constant(0u), 0x01));

                              body.emit(assign(r06E8, add(r06E8, body.constant(int(-32))), 0x01));


                           body.instructions = f06ED_parent_instructions;
                           body.emit(f06ED);

                           /* END IF */

                           ir_variable *const r06EF = body.make_temp(glsl_type::uint_type, "a");
                           body.emit(assign(r06EF, r06E9, 0x01));

                           ir_variable *const r06F0 = body.make_temp(glsl_type::int_type, "return_value");
                           ir_variable *const r06F1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06F1);
                           /* IF CONDITION */
                           ir_expression *const r06F3 = equal(r06E9, body.constant(0u));
                           ir_if *f06F2 = new(mem_ctx) ir_if(operand(r06F3).val);
                           exec_list *const f06F2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06F2->then_instructions;

                              body.emit(assign(r06F0, body.constant(int(32)), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06F2->else_instructions;

                              body.emit(assign(r06F1, body.constant(int(0)), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r06F5 = bit_and(r06E9, body.constant(4294901760u));
                              ir_expression *const r06F6 = equal(r06F5, body.constant(0u));
                              ir_if *f06F4 = new(mem_ctx) ir_if(operand(r06F6).val);
                              exec_list *const f06F4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06F4->then_instructions;

                                 body.emit(assign(r06F1, body.constant(int(16)), 0x01));

                                 body.emit(assign(r06EF, lshift(r06E9, body.constant(int(16))), 0x01));


                              body.instructions = f06F4_parent_instructions;
                              body.emit(f06F4);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r06F8 = bit_and(r06EF, body.constant(4278190080u));
                              ir_expression *const r06F9 = equal(r06F8, body.constant(0u));
                              ir_if *f06F7 = new(mem_ctx) ir_if(operand(r06F9).val);
                              exec_list *const f06F7_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06F7->then_instructions;

                                 body.emit(assign(r06F1, add(r06F1, body.constant(int(8))), 0x01));

                                 body.emit(assign(r06EF, lshift(r06EF, body.constant(int(8))), 0x01));


                              body.instructions = f06F7_parent_instructions;
                              body.emit(f06F7);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r06FB = bit_and(r06EF, body.constant(4026531840u));
                              ir_expression *const r06FC = equal(r06FB, body.constant(0u));
                              ir_if *f06FA = new(mem_ctx) ir_if(operand(r06FC).val);
                              exec_list *const f06FA_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06FA->then_instructions;

                                 body.emit(assign(r06F1, add(r06F1, body.constant(int(4))), 0x01));

                                 body.emit(assign(r06EF, lshift(r06EF, body.constant(int(4))), 0x01));


                              body.instructions = f06FA_parent_instructions;
                              body.emit(f06FA);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r06FE = bit_and(r06EF, body.constant(3221225472u));
                              ir_expression *const r06FF = equal(r06FE, body.constant(0u));
                              ir_if *f06FD = new(mem_ctx) ir_if(operand(r06FF).val);
                              exec_list *const f06FD_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06FD->then_instructions;

                                 body.emit(assign(r06F1, add(r06F1, body.constant(int(2))), 0x01));

                                 body.emit(assign(r06EF, lshift(r06EF, body.constant(int(2))), 0x01));


                              body.instructions = f06FD_parent_instructions;
                              body.emit(f06FD);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0701 = bit_and(r06EF, body.constant(2147483648u));
                              ir_expression *const r0702 = equal(r0701, body.constant(0u));
                              ir_if *f0700 = new(mem_ctx) ir_if(operand(r0702).val);
                              exec_list *const f0700_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0700->then_instructions;

                                 body.emit(assign(r06F1, add(r06F1, body.constant(int(1))), 0x01));


                              body.instructions = f0700_parent_instructions;
                              body.emit(f0700);

                              /* END IF */

                              body.emit(assign(r06F0, r06F1, 0x01));


                           body.instructions = f06F2_parent_instructions;
                           body.emit(f06F2);

                           /* END IF */

                           body.emit(assign(r06EC, add(r06F0, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0704 = gequal(r06EC, body.constant(int(0)));
                           ir_if *f0703 = new(mem_ctx) ir_if(operand(r0704).val);
                           exec_list *const f0703_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0703->then_instructions;

                              body.emit(assign(r06EB, body.constant(0u), 0x01));

                              ir_variable *const r0705 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                              body.emit(assign(r0705, lshift(r06EA, r06EC), 0x01));

                              ir_variable *const r0706 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r0708 = equal(r06EC, body.constant(int(0)));
                              ir_if *f0707 = new(mem_ctx) ir_if(operand(r0708).val);
                              exec_list *const f0707_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0707->then_instructions;

                                 body.emit(assign(r0706, r06E9, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0707->else_instructions;

                                 ir_expression *const r0709 = lshift(r06E9, r06EC);
                                 ir_expression *const r070A = neg(r06EC);
                                 ir_expression *const r070B = bit_and(r070A, body.constant(int(31)));
                                 ir_expression *const r070C = rshift(r06EA, r070B);
                                 body.emit(assign(r0706, bit_or(r0709, r070C), 0x01));


                              body.instructions = f0707_parent_instructions;
                              body.emit(f0707);

                              /* END IF */

                              body.emit(assign(r06E9, r0706, 0x01));

                              body.emit(assign(r06EA, r0705, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0703->else_instructions;

                              ir_variable *const r070D = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r070D, body.constant(0u), 0x01));

                              ir_variable *const r070E = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r070E, neg(r06EC), 0x01));

                              ir_variable *const r070F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r070F);
                              ir_variable *const r0710 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0710);
                              ir_variable *const r0711 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0711);
                              ir_variable *const r0712 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0713 = neg(r070E);
                              body.emit(assign(r0712, bit_and(r0713, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0715 = equal(r070E, body.constant(int(0)));
                              ir_if *f0714 = new(mem_ctx) ir_if(operand(r0715).val);
                              exec_list *const f0714_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0714->then_instructions;

                                 body.emit(assign(r070F, r070D, 0x01));

                                 body.emit(assign(r0710, r06EA, 0x01));

                                 body.emit(assign(r0711, r06E9, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0714->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0717 = less(r070E, body.constant(int(32)));
                                 ir_if *f0716 = new(mem_ctx) ir_if(operand(r0717).val);
                                 exec_list *const f0716_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0716->then_instructions;

                                    body.emit(assign(r070F, lshift(r06EA, r0712), 0x01));

                                    ir_expression *const r0718 = lshift(r06E9, r0712);
                                    ir_expression *const r0719 = rshift(r06EA, r070E);
                                    body.emit(assign(r0710, bit_or(r0718, r0719), 0x01));

                                    body.emit(assign(r0711, rshift(r06E9, r070E), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0716->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r071B = equal(r070E, body.constant(int(32)));
                                    ir_if *f071A = new(mem_ctx) ir_if(operand(r071B).val);
                                    exec_list *const f071A_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f071A->then_instructions;

                                       body.emit(assign(r070F, r06EA, 0x01));

                                       body.emit(assign(r0710, r06E9, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f071A->else_instructions;

                                       body.emit(assign(r070D, bit_or(body.constant(0u), r06EA), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r071D = less(r070E, body.constant(int(64)));
                                       ir_if *f071C = new(mem_ctx) ir_if(operand(r071D).val);
                                       exec_list *const f071C_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f071C->then_instructions;

                                          body.emit(assign(r070F, lshift(r06E9, r0712), 0x01));

                                          ir_expression *const r071E = bit_and(r070E, body.constant(int(31)));
                                          body.emit(assign(r0710, rshift(r06E9, r071E), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f071C->else_instructions;

                                          ir_variable *const r071F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r0721 = equal(r070E, body.constant(int(64)));
                                          ir_if *f0720 = new(mem_ctx) ir_if(operand(r0721).val);
                                          exec_list *const f0720_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0720->then_instructions;

                                             body.emit(assign(r071F, r06E9, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0720->else_instructions;

                                             ir_expression *const r0722 = nequal(r06E9, body.constant(0u));
                                             ir_expression *const r0723 = expr(ir_unop_b2i, r0722);
                                             body.emit(assign(r071F, expr(ir_unop_i2u, r0723), 0x01));


                                          body.instructions = f0720_parent_instructions;
                                          body.emit(f0720);

                                          /* END IF */

                                          body.emit(assign(r070F, r071F, 0x01));

                                          body.emit(assign(r0710, body.constant(0u), 0x01));


                                       body.instructions = f071C_parent_instructions;
                                       body.emit(f071C);

                                       /* END IF */


                                    body.instructions = f071A_parent_instructions;
                                    body.emit(f071A);

                                    /* END IF */

                                    body.emit(assign(r0711, body.constant(0u), 0x01));


                                 body.instructions = f0716_parent_instructions;
                                 body.emit(f0716);

                                 /* END IF */

                                 ir_expression *const r0724 = nequal(r070D, body.constant(0u));
                                 ir_expression *const r0725 = expr(ir_unop_b2i, r0724);
                                 ir_expression *const r0726 = expr(ir_unop_i2u, r0725);
                                 body.emit(assign(r070F, bit_or(r070F, r0726), 0x01));


                              body.instructions = f0714_parent_instructions;
                              body.emit(f0714);

                              /* END IF */

                              body.emit(assign(r06E9, r0711, 0x01));

                              body.emit(assign(r06EA, r0710, 0x01));

                              body.emit(assign(r06EB, r070F, 0x01));


                           body.instructions = f0703_parent_instructions;
                           body.emit(f0703);

                           /* END IF */

                           body.emit(assign(r06E8, sub(r06E8, r06EC), 0x01));

                           ir_variable *const r0727 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r0727, r06E8, 0x01));

                           ir_variable *const r0728 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r0728, r06E9, 0x01));

                           ir_variable *const r0729 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r0729, r06EA, 0x01));

                           ir_variable *const r072A = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r072A, r06EB, 0x01));

                           ir_variable *const r072B = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r072B, body.constant(true), 0x01));

                           ir_variable *const r072C = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r072D = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r072D);
                           ir_expression *const r072E = expr(ir_unop_u2i, r06EB);
                           body.emit(assign(r072D, less(r072E, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0730 = gequal(r06E8, body.constant(int(2045)));
                           ir_if *f072F = new(mem_ctx) ir_if(operand(r0730).val);
                           exec_list *const f072F_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f072F->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0732 = less(body.constant(int(2045)), r06E8);
                              ir_expression *const r0733 = equal(r06E8, body.constant(int(2045)));
                              ir_expression *const r0734 = equal(body.constant(2097151u), r06E9);
                              ir_expression *const r0735 = equal(body.constant(4294967295u), r06EA);
                              ir_expression *const r0736 = logic_and(r0734, r0735);
                              ir_expression *const r0737 = logic_and(r0733, r0736);
                              ir_expression *const r0738 = logic_and(r0737, r072D);
                              ir_expression *const r0739 = logic_or(r0732, r0738);
                              ir_if *f0731 = new(mem_ctx) ir_if(operand(r0739).val);
                              exec_list *const f0731_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0731->then_instructions;

                                 ir_variable *const r073A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r073A);
                                 ir_expression *const r073B = lshift(r01E3, body.constant(int(31)));
                                 body.emit(assign(r073A, add(r073B, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r073A, body.constant(0u), 0x01));

                                 body.emit(assign(r072C, r073A, 0x03));

                                 body.emit(assign(r072B, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0731->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r073D = less(r06E8, body.constant(int(0)));
                                 ir_if *f073C = new(mem_ctx) ir_if(operand(r073D).val);
                                 exec_list *const f073C_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f073C->then_instructions;

                                    ir_variable *const r073E = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r073E, r06EB, 0x01));

                                    ir_variable *const r073F = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r073F, neg(r06E8), 0x01));

                                    ir_variable *const r0740 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r0740);
                                    ir_variable *const r0741 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r0741);
                                    ir_variable *const r0742 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r0742);
                                    ir_variable *const r0743 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r0744 = neg(r073F);
                                    body.emit(assign(r0743, bit_and(r0744, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0746 = equal(r073F, body.constant(int(0)));
                                    ir_if *f0745 = new(mem_ctx) ir_if(operand(r0746).val);
                                    exec_list *const f0745_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0745->then_instructions;

                                       body.emit(assign(r0740, r06EB, 0x01));

                                       body.emit(assign(r0741, r06EA, 0x01));

                                       body.emit(assign(r0742, r06E9, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0745->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r0748 = less(r073F, body.constant(int(32)));
                                       ir_if *f0747 = new(mem_ctx) ir_if(operand(r0748).val);
                                       exec_list *const f0747_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0747->then_instructions;

                                          body.emit(assign(r0740, lshift(r06EA, r0743), 0x01));

                                          ir_expression *const r0749 = lshift(r06E9, r0743);
                                          ir_expression *const r074A = rshift(r06EA, r073F);
                                          body.emit(assign(r0741, bit_or(r0749, r074A), 0x01));

                                          body.emit(assign(r0742, rshift(r06E9, r073F), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0747->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r074C = equal(r073F, body.constant(int(32)));
                                          ir_if *f074B = new(mem_ctx) ir_if(operand(r074C).val);
                                          exec_list *const f074B_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f074B->then_instructions;

                                             body.emit(assign(r0740, r06EA, 0x01));

                                             body.emit(assign(r0741, r06E9, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f074B->else_instructions;

                                             body.emit(assign(r073E, bit_or(r06EB, r06EA), 0x01));

                                             /* IF CONDITION */
                                             ir_expression *const r074E = less(r073F, body.constant(int(64)));
                                             ir_if *f074D = new(mem_ctx) ir_if(operand(r074E).val);
                                             exec_list *const f074D_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f074D->then_instructions;

                                                body.emit(assign(r0740, lshift(r06E9, r0743), 0x01));

                                                ir_expression *const r074F = bit_and(r073F, body.constant(int(31)));
                                                body.emit(assign(r0741, rshift(r06E9, r074F), 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f074D->else_instructions;

                                                ir_variable *const r0750 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                                /* IF CONDITION */
                                                ir_expression *const r0752 = equal(r073F, body.constant(int(64)));
                                                ir_if *f0751 = new(mem_ctx) ir_if(operand(r0752).val);
                                                exec_list *const f0751_parent_instructions = body.instructions;

                                                   /* THEN INSTRUCTIONS */
                                                   body.instructions = &f0751->then_instructions;

                                                   body.emit(assign(r0750, r06E9, 0x01));


                                                   /* ELSE INSTRUCTIONS */
                                                   body.instructions = &f0751->else_instructions;

                                                   ir_expression *const r0753 = nequal(r06E9, body.constant(0u));
                                                   ir_expression *const r0754 = expr(ir_unop_b2i, r0753);
                                                   body.emit(assign(r0750, expr(ir_unop_i2u, r0754), 0x01));


                                                body.instructions = f0751_parent_instructions;
                                                body.emit(f0751);

                                                /* END IF */

                                                body.emit(assign(r0740, r0750, 0x01));

                                                body.emit(assign(r0741, body.constant(0u), 0x01));


                                             body.instructions = f074D_parent_instructions;
                                             body.emit(f074D);

                                             /* END IF */


                                          body.instructions = f074B_parent_instructions;
                                          body.emit(f074B);

                                          /* END IF */

                                          body.emit(assign(r0742, body.constant(0u), 0x01));


                                       body.instructions = f0747_parent_instructions;
                                       body.emit(f0747);

                                       /* END IF */

                                       ir_expression *const r0755 = nequal(r073E, body.constant(0u));
                                       ir_expression *const r0756 = expr(ir_unop_b2i, r0755);
                                       ir_expression *const r0757 = expr(ir_unop_i2u, r0756);
                                       body.emit(assign(r0740, bit_or(r0740, r0757), 0x01));


                                    body.instructions = f0745_parent_instructions;
                                    body.emit(f0745);

                                    /* END IF */

                                    body.emit(assign(r0728, r0742, 0x01));

                                    body.emit(assign(r0729, r0741, 0x01));

                                    body.emit(assign(r072A, r0740, 0x01));

                                    body.emit(assign(r0727, body.constant(int(0)), 0x01));

                                    body.emit(assign(r072D, less(r0740, body.constant(0u)), 0x01));


                                 body.instructions = f073C_parent_instructions;
                                 body.emit(f073C);

                                 /* END IF */


                              body.instructions = f0731_parent_instructions;
                              body.emit(f0731);

                              /* END IF */


                           body.instructions = f072F_parent_instructions;
                           body.emit(f072F);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f0758 = new(mem_ctx) ir_if(operand(r072B).val);
                           exec_list *const f0758_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0758->then_instructions;

                              /* IF CONDITION */
                              ir_if *f0759 = new(mem_ctx) ir_if(operand(r072D).val);
                              exec_list *const f0759_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0759->then_instructions;

                                 ir_variable *const r075A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r075A, add(r0729, body.constant(1u)), 0x01));

                                 ir_expression *const r075B = less(r075A, r0729);
                                 ir_expression *const r075C = expr(ir_unop_b2i, r075B);
                                 ir_expression *const r075D = expr(ir_unop_i2u, r075C);
                                 body.emit(assign(r0728, add(r0728, r075D), 0x01));

                                 ir_expression *const r075E = equal(r072A, body.constant(0u));
                                 ir_expression *const r075F = expr(ir_unop_b2i, r075E);
                                 ir_expression *const r0760 = expr(ir_unop_i2u, r075F);
                                 ir_expression *const r0761 = add(r072A, r0760);
                                 ir_expression *const r0762 = bit_and(r0761, body.constant(1u));
                                 ir_expression *const r0763 = expr(ir_unop_bit_not, r0762);
                                 body.emit(assign(r0729, bit_and(r075A, r0763), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0759->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0765 = bit_or(r0728, r0729);
                                 ir_expression *const r0766 = equal(r0765, body.constant(0u));
                                 ir_if *f0764 = new(mem_ctx) ir_if(operand(r0766).val);
                                 exec_list *const f0764_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0764->then_instructions;

                                    body.emit(assign(r0727, body.constant(int(0)), 0x01));


                                 body.instructions = f0764_parent_instructions;
                                 body.emit(f0764);

                                 /* END IF */


                              body.instructions = f0759_parent_instructions;
                              body.emit(f0759);

                              /* END IF */

                              ir_variable *const r0767 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0767);
                              ir_expression *const r0768 = lshift(r01E3, body.constant(int(31)));
                              ir_expression *const r0769 = expr(ir_unop_i2u, r0727);
                              ir_expression *const r076A = lshift(r0769, body.constant(int(20)));
                              ir_expression *const r076B = add(r0768, r076A);
                              body.emit(assign(r0767, add(r076B, r0728), 0x02));

                              body.emit(assign(r0767, r0729, 0x01));

                              body.emit(assign(r072C, r0767, 0x03));

                              body.emit(assign(r072B, body.constant(false), 0x01));


                           body.instructions = f0758_parent_instructions;
                           body.emit(f0758);

                           /* END IF */

                           body.emit(assign(r01E2, r072C, 0x03));

                           body.emit(assign(r01E1, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06E0->else_instructions;

                           ir_variable *const r076C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r076C);
                           body.emit(assign(r076C, body.constant(0u), 0x02));

                           body.emit(assign(r076C, body.constant(0u), 0x01));

                           body.emit(assign(r01E2, r076C, 0x03));

                           body.emit(assign(r01E1, body.constant(false), 0x01));


                        body.instructions = f06E0_parent_instructions;
                        body.emit(f06E0);

                        /* END IF */


                     body.instructions = f0654_parent_instructions;
                     body.emit(f0654);

                     /* END IF */


                  body.instructions = f05C8_parent_instructions;
                  body.emit(f05C8);

                  /* END IF */


               body.instructions = f053C_parent_instructions;
               body.emit(f053C);

               /* END IF */


            body.instructions = f051E_parent_instructions;
            body.emit(f051E);

            /* END IF */


         body.instructions = f0453_parent_instructions;
         body.emit(f0453);

         /* END IF */


      body.instructions = f038C_parent_instructions;
      body.emit(f038C);

      /* END IF */


   body.instructions = f01E6_parent_instructions;
   body.emit(f01E6);

   /* END IF */

   body.emit(ret(r01E2));

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

   ir_variable *const r076D = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r076D);
   ir_variable *const r076E = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r076E);
   ir_variable *const r076F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r076F);
   ir_variable *const r0770 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0770);
   ir_variable *const r0771 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0771);
   ir_variable *const r0772 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0772);
   ir_variable *const r0773 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0773);
   ir_variable *const r0774 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0774, bit_and(r076D, body.constant(65535u)), 0x01));

   ir_variable *const r0775 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0775, rshift(r076D, body.constant(int(16))), 0x01));

   ir_variable *const r0776 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0776, bit_and(r076E, body.constant(65535u)), 0x01));

   ir_variable *const r0777 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0777, rshift(r076E, body.constant(int(16))), 0x01));

   ir_variable *const r0778 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0778, mul(r0775, r0776), 0x01));

   ir_expression *const r0779 = mul(r0774, r0777);
   body.emit(assign(r0772, add(r0779, r0778), 0x01));

   ir_expression *const r077A = mul(r0775, r0777);
   ir_expression *const r077B = less(r0772, r0778);
   ir_expression *const r077C = expr(ir_unop_b2i, r077B);
   ir_expression *const r077D = expr(ir_unop_i2u, r077C);
   ir_expression *const r077E = lshift(r077D, body.constant(int(16)));
   ir_expression *const r077F = rshift(r0772, body.constant(int(16)));
   ir_expression *const r0780 = add(r077E, r077F);
   body.emit(assign(r0771, add(r077A, r0780), 0x01));

   body.emit(assign(r0772, lshift(r0772, body.constant(int(16))), 0x01));

   ir_expression *const r0781 = mul(r0774, r0776);
   body.emit(assign(r0773, add(r0781, r0772), 0x01));

   ir_expression *const r0782 = less(r0773, r0772);
   ir_expression *const r0783 = expr(ir_unop_b2i, r0782);
   ir_expression *const r0784 = expr(ir_unop_i2u, r0783);
   body.emit(assign(r0771, add(r0771, r0784), 0x01));

   body.emit(assign(r0770, r0773, 0x01));

   body.emit(assign(r076F, r0771, 0x01));

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

   ir_variable *const r0785 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0785);
   ir_variable *const r0786 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0786);
   ir_variable *const r0787 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0787);
   ir_variable *const r0788 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0788);
   ir_variable *const r0789 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0789);
   ir_variable *const r078A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r078A);
   ir_variable *const r078B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r078B);
   ir_variable *const r078C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r078C);
   ir_variable *const r078D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r078D);
   ir_variable *const r078E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r078E);
   ir_variable *const r078F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r078F);
   ir_variable *const r0790 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0790, bit_and(r0786, body.constant(65535u)), 0x01));

   ir_variable *const r0791 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0791, rshift(r0786, body.constant(int(16))), 0x01));

   ir_variable *const r0792 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0792, bit_and(r0788, body.constant(65535u)), 0x01));

   ir_variable *const r0793 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0793, rshift(r0788, body.constant(int(16))), 0x01));

   ir_variable *const r0794 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0794, mul(r0791, r0792), 0x01));

   ir_expression *const r0795 = mul(r0790, r0793);
   body.emit(assign(r078E, add(r0795, r0794), 0x01));

   ir_expression *const r0796 = mul(r0791, r0793);
   ir_expression *const r0797 = less(r078E, r0794);
   ir_expression *const r0798 = expr(ir_unop_b2i, r0797);
   ir_expression *const r0799 = expr(ir_unop_i2u, r0798);
   ir_expression *const r079A = lshift(r0799, body.constant(int(16)));
   ir_expression *const r079B = rshift(r078E, body.constant(int(16)));
   ir_expression *const r079C = add(r079A, r079B);
   body.emit(assign(r078D, add(r0796, r079C), 0x01));

   body.emit(assign(r078E, lshift(r078E, body.constant(int(16))), 0x01));

   ir_expression *const r079D = mul(r0790, r0792);
   body.emit(assign(r078F, add(r079D, r078E), 0x01));

   ir_expression *const r079E = less(r078F, r078E);
   ir_expression *const r079F = expr(ir_unop_b2i, r079E);
   ir_expression *const r07A0 = expr(ir_unop_i2u, r079F);
   body.emit(assign(r078D, add(r078D, r07A0), 0x01));

   ir_variable *const r07A1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07A1);
   ir_variable *const r07A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07A2);
   ir_variable *const r07A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07A3);
   ir_variable *const r07A4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A4, bit_and(r0786, body.constant(65535u)), 0x01));

   ir_variable *const r07A5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A5, rshift(r0786, body.constant(int(16))), 0x01));

   ir_variable *const r07A6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A6, bit_and(r0787, body.constant(65535u)), 0x01));

   ir_variable *const r07A7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A7, rshift(r0787, body.constant(int(16))), 0x01));

   ir_variable *const r07A8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A8, mul(r07A5, r07A6), 0x01));

   ir_expression *const r07A9 = mul(r07A4, r07A7);
   body.emit(assign(r07A2, add(r07A9, r07A8), 0x01));

   ir_expression *const r07AA = mul(r07A5, r07A7);
   ir_expression *const r07AB = less(r07A2, r07A8);
   ir_expression *const r07AC = expr(ir_unop_b2i, r07AB);
   ir_expression *const r07AD = expr(ir_unop_i2u, r07AC);
   ir_expression *const r07AE = lshift(r07AD, body.constant(int(16)));
   ir_expression *const r07AF = rshift(r07A2, body.constant(int(16)));
   ir_expression *const r07B0 = add(r07AE, r07AF);
   body.emit(assign(r07A1, add(r07AA, r07B0), 0x01));

   body.emit(assign(r07A2, lshift(r07A2, body.constant(int(16))), 0x01));

   ir_expression *const r07B1 = mul(r07A4, r07A6);
   body.emit(assign(r07A3, add(r07B1, r07A2), 0x01));

   ir_expression *const r07B2 = less(r07A3, r07A2);
   ir_expression *const r07B3 = expr(ir_unop_b2i, r07B2);
   ir_expression *const r07B4 = expr(ir_unop_i2u, r07B3);
   body.emit(assign(r07A1, add(r07A1, r07B4), 0x01));

   ir_variable *const r07B5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B5, add(r07A3, r078D), 0x01));

   ir_variable *const r07B6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07B6);
   ir_variable *const r07B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07B7);
   ir_variable *const r07B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07B8);
   ir_variable *const r07B9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B9, bit_and(r0785, body.constant(65535u)), 0x01));

   ir_variable *const r07BA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07BA, rshift(r0785, body.constant(int(16))), 0x01));

   ir_variable *const r07BB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07BB, bit_and(r0787, body.constant(65535u)), 0x01));

   ir_variable *const r07BC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07BC, rshift(r0787, body.constant(int(16))), 0x01));

   ir_variable *const r07BD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07BD, mul(r07BA, r07BB), 0x01));

   ir_expression *const r07BE = mul(r07B9, r07BC);
   body.emit(assign(r07B7, add(r07BE, r07BD), 0x01));

   ir_expression *const r07BF = mul(r07BA, r07BC);
   ir_expression *const r07C0 = less(r07B7, r07BD);
   ir_expression *const r07C1 = expr(ir_unop_b2i, r07C0);
   ir_expression *const r07C2 = expr(ir_unop_i2u, r07C1);
   ir_expression *const r07C3 = lshift(r07C2, body.constant(int(16)));
   ir_expression *const r07C4 = rshift(r07B7, body.constant(int(16)));
   ir_expression *const r07C5 = add(r07C3, r07C4);
   body.emit(assign(r07B6, add(r07BF, r07C5), 0x01));

   body.emit(assign(r07B7, lshift(r07B7, body.constant(int(16))), 0x01));

   ir_expression *const r07C6 = mul(r07B9, r07BB);
   body.emit(assign(r07B8, add(r07C6, r07B7), 0x01));

   ir_expression *const r07C7 = less(r07B8, r07B7);
   ir_expression *const r07C8 = expr(ir_unop_b2i, r07C7);
   ir_expression *const r07C9 = expr(ir_unop_i2u, r07C8);
   body.emit(assign(r07B6, add(r07B6, r07C9), 0x01));

   ir_variable *const r07CA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r07CB = less(r07B5, r07A3);
   ir_expression *const r07CC = expr(ir_unop_b2i, r07CB);
   ir_expression *const r07CD = expr(ir_unop_i2u, r07CC);
   ir_expression *const r07CE = add(r07A1, r07CD);
   body.emit(assign(r07CA, add(r07B8, r07CE), 0x01));

   ir_variable *const r07CF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07CF);
   ir_variable *const r07D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07D0);
   ir_variable *const r07D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07D1);
   ir_variable *const r07D2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D2, bit_and(r0785, body.constant(65535u)), 0x01));

   ir_variable *const r07D3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D3, rshift(r0785, body.constant(int(16))), 0x01));

   ir_variable *const r07D4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D4, bit_and(r0788, body.constant(65535u)), 0x01));

   ir_variable *const r07D5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D5, rshift(r0788, body.constant(int(16))), 0x01));

   ir_variable *const r07D6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D6, mul(r07D3, r07D4), 0x01));

   ir_expression *const r07D7 = mul(r07D2, r07D5);
   body.emit(assign(r07D0, add(r07D7, r07D6), 0x01));

   ir_expression *const r07D8 = mul(r07D3, r07D5);
   ir_expression *const r07D9 = less(r07D0, r07D6);
   ir_expression *const r07DA = expr(ir_unop_b2i, r07D9);
   ir_expression *const r07DB = expr(ir_unop_i2u, r07DA);
   ir_expression *const r07DC = lshift(r07DB, body.constant(int(16)));
   ir_expression *const r07DD = rshift(r07D0, body.constant(int(16)));
   ir_expression *const r07DE = add(r07DC, r07DD);
   body.emit(assign(r07CF, add(r07D8, r07DE), 0x01));

   body.emit(assign(r07D0, lshift(r07D0, body.constant(int(16))), 0x01));

   ir_expression *const r07DF = mul(r07D2, r07D4);
   body.emit(assign(r07D1, add(r07DF, r07D0), 0x01));

   ir_expression *const r07E0 = less(r07D1, r07D0);
   ir_expression *const r07E1 = expr(ir_unop_b2i, r07E0);
   ir_expression *const r07E2 = expr(ir_unop_i2u, r07E1);
   body.emit(assign(r07CF, add(r07CF, r07E2), 0x01));

   ir_variable *const r07E3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07E3, add(r07D1, r07B5), 0x01));

   ir_variable *const r07E4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r07E5 = less(r07E3, r07D1);
   ir_expression *const r07E6 = expr(ir_unop_b2i, r07E5);
   ir_expression *const r07E7 = expr(ir_unop_i2u, r07E6);
   ir_expression *const r07E8 = add(r07CF, r07E7);
   body.emit(assign(r07E4, add(r07CA, r07E8), 0x01));

   body.emit(assign(r078C, r078F, 0x01));

   body.emit(assign(r078B, r07E3, 0x01));

   body.emit(assign(r078A, r07E4, 0x01));

   ir_expression *const r07E9 = less(r07CA, r07B8);
   ir_expression *const r07EA = expr(ir_unop_b2i, r07E9);
   ir_expression *const r07EB = expr(ir_unop_i2u, r07EA);
   ir_expression *const r07EC = add(r07B6, r07EB);
   ir_expression *const r07ED = less(r07E4, r07CA);
   ir_expression *const r07EE = expr(ir_unop_b2i, r07ED);
   ir_expression *const r07EF = expr(ir_unop_i2u, r07EE);
   body.emit(assign(r0789, add(r07EC, r07EF), 0x01));

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

   ir_variable *const r07F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r07F0);
   ir_variable *const r07F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r07F1);
   ir_variable *const r07F2 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r07F2);
   ir_variable *const r07F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07F3);
   ir_variable *const r07F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07F4);
   ir_variable *const r07F5 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r07F5);
   /* IF CONDITION */
   ir_expression *const r07F7 = equal(r07F0, body.constant(0u));
   ir_if *f07F6 = new(mem_ctx) ir_if(operand(r07F7).val);
   exec_list *const f07F6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07F6->then_instructions;

      ir_variable *const r07F8 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r07F8, r07F1, 0x01));

      ir_variable *const r07F9 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r07FA = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r07FA);
      /* IF CONDITION */
      ir_expression *const r07FC = equal(r07F1, body.constant(0u));
      ir_if *f07FB = new(mem_ctx) ir_if(operand(r07FC).val);
      exec_list *const f07FB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07FB->then_instructions;

         body.emit(assign(r07F9, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07FB->else_instructions;

         body.emit(assign(r07FA, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r07FE = bit_and(r07F1, body.constant(4294901760u));
         ir_expression *const r07FF = equal(r07FE, body.constant(0u));
         ir_if *f07FD = new(mem_ctx) ir_if(operand(r07FF).val);
         exec_list *const f07FD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07FD->then_instructions;

            body.emit(assign(r07FA, body.constant(int(16)), 0x01));

            body.emit(assign(r07F8, lshift(r07F1, body.constant(int(16))), 0x01));


         body.instructions = f07FD_parent_instructions;
         body.emit(f07FD);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0801 = bit_and(r07F8, body.constant(4278190080u));
         ir_expression *const r0802 = equal(r0801, body.constant(0u));
         ir_if *f0800 = new(mem_ctx) ir_if(operand(r0802).val);
         exec_list *const f0800_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0800->then_instructions;

            body.emit(assign(r07FA, add(r07FA, body.constant(int(8))), 0x01));

            body.emit(assign(r07F8, lshift(r07F8, body.constant(int(8))), 0x01));


         body.instructions = f0800_parent_instructions;
         body.emit(f0800);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0804 = bit_and(r07F8, body.constant(4026531840u));
         ir_expression *const r0805 = equal(r0804, body.constant(0u));
         ir_if *f0803 = new(mem_ctx) ir_if(operand(r0805).val);
         exec_list *const f0803_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0803->then_instructions;

            body.emit(assign(r07FA, add(r07FA, body.constant(int(4))), 0x01));

            body.emit(assign(r07F8, lshift(r07F8, body.constant(int(4))), 0x01));


         body.instructions = f0803_parent_instructions;
         body.emit(f0803);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0807 = bit_and(r07F8, body.constant(3221225472u));
         ir_expression *const r0808 = equal(r0807, body.constant(0u));
         ir_if *f0806 = new(mem_ctx) ir_if(operand(r0808).val);
         exec_list *const f0806_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0806->then_instructions;

            body.emit(assign(r07FA, add(r07FA, body.constant(int(2))), 0x01));

            body.emit(assign(r07F8, lshift(r07F8, body.constant(int(2))), 0x01));


         body.instructions = f0806_parent_instructions;
         body.emit(f0806);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r080A = bit_and(r07F8, body.constant(2147483648u));
         ir_expression *const r080B = equal(r080A, body.constant(0u));
         ir_if *f0809 = new(mem_ctx) ir_if(operand(r080B).val);
         exec_list *const f0809_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0809->then_instructions;

            body.emit(assign(r07FA, add(r07FA, body.constant(int(1))), 0x01));


         body.instructions = f0809_parent_instructions;
         body.emit(f0809);

         /* END IF */

         body.emit(assign(r07F9, r07FA, 0x01));


      body.instructions = f07FB_parent_instructions;
      body.emit(f07FB);

      /* END IF */

      body.emit(assign(r07F5, add(r07F9, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r080D = less(r07F5, body.constant(int(0)));
      ir_if *f080C = new(mem_ctx) ir_if(operand(r080D).val);
      exec_list *const f080C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f080C->then_instructions;

         ir_expression *const r080E = neg(r07F5);
         body.emit(assign(r07F3, rshift(r07F1, r080E), 0x01));

         ir_expression *const r080F = bit_and(r07F5, body.constant(int(31)));
         body.emit(assign(r07F4, lshift(r07F1, r080F), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f080C->else_instructions;

         body.emit(assign(r07F3, lshift(r07F1, r07F5), 0x01));

         body.emit(assign(r07F4, body.constant(0u), 0x01));


      body.instructions = f080C_parent_instructions;
      body.emit(f080C);

      /* END IF */

      body.emit(assign(r07F2, sub(body.constant(int(-31)), r07F5), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07F6->else_instructions;

      ir_variable *const r0810 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0810, r07F0, 0x01));

      ir_variable *const r0811 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0812 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0812);
      /* IF CONDITION */
      ir_expression *const r0814 = equal(r07F0, body.constant(0u));
      ir_if *f0813 = new(mem_ctx) ir_if(operand(r0814).val);
      exec_list *const f0813_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0813->then_instructions;

         body.emit(assign(r0811, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0813->else_instructions;

         body.emit(assign(r0812, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0816 = bit_and(r07F0, body.constant(4294901760u));
         ir_expression *const r0817 = equal(r0816, body.constant(0u));
         ir_if *f0815 = new(mem_ctx) ir_if(operand(r0817).val);
         exec_list *const f0815_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0815->then_instructions;

            body.emit(assign(r0812, body.constant(int(16)), 0x01));

            body.emit(assign(r0810, lshift(r07F0, body.constant(int(16))), 0x01));


         body.instructions = f0815_parent_instructions;
         body.emit(f0815);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0819 = bit_and(r0810, body.constant(4278190080u));
         ir_expression *const r081A = equal(r0819, body.constant(0u));
         ir_if *f0818 = new(mem_ctx) ir_if(operand(r081A).val);
         exec_list *const f0818_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0818->then_instructions;

            body.emit(assign(r0812, add(r0812, body.constant(int(8))), 0x01));

            body.emit(assign(r0810, lshift(r0810, body.constant(int(8))), 0x01));


         body.instructions = f0818_parent_instructions;
         body.emit(f0818);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r081C = bit_and(r0810, body.constant(4026531840u));
         ir_expression *const r081D = equal(r081C, body.constant(0u));
         ir_if *f081B = new(mem_ctx) ir_if(operand(r081D).val);
         exec_list *const f081B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f081B->then_instructions;

            body.emit(assign(r0812, add(r0812, body.constant(int(4))), 0x01));

            body.emit(assign(r0810, lshift(r0810, body.constant(int(4))), 0x01));


         body.instructions = f081B_parent_instructions;
         body.emit(f081B);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r081F = bit_and(r0810, body.constant(3221225472u));
         ir_expression *const r0820 = equal(r081F, body.constant(0u));
         ir_if *f081E = new(mem_ctx) ir_if(operand(r0820).val);
         exec_list *const f081E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f081E->then_instructions;

            body.emit(assign(r0812, add(r0812, body.constant(int(2))), 0x01));

            body.emit(assign(r0810, lshift(r0810, body.constant(int(2))), 0x01));


         body.instructions = f081E_parent_instructions;
         body.emit(f081E);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0822 = bit_and(r0810, body.constant(2147483648u));
         ir_expression *const r0823 = equal(r0822, body.constant(0u));
         ir_if *f0821 = new(mem_ctx) ir_if(operand(r0823).val);
         exec_list *const f0821_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0821->then_instructions;

            body.emit(assign(r0812, add(r0812, body.constant(int(1))), 0x01));


         body.instructions = f0821_parent_instructions;
         body.emit(f0821);

         /* END IF */

         body.emit(assign(r0811, r0812, 0x01));


      body.instructions = f0813_parent_instructions;
      body.emit(f0813);

      /* END IF */

      body.emit(assign(r07F5, add(r0811, body.constant(int(-11))), 0x01));

      ir_variable *const r0824 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0824, lshift(r07F1, r07F5), 0x01));

      ir_variable *const r0825 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0827 = equal(r07F5, body.constant(int(0)));
      ir_if *f0826 = new(mem_ctx) ir_if(operand(r0827).val);
      exec_list *const f0826_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0826->then_instructions;

         body.emit(assign(r0825, r07F0, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0826->else_instructions;

         ir_expression *const r0828 = lshift(r07F0, r07F5);
         ir_expression *const r0829 = neg(r07F5);
         ir_expression *const r082A = bit_and(r0829, body.constant(int(31)));
         ir_expression *const r082B = rshift(r07F1, r082A);
         body.emit(assign(r0825, bit_or(r0828, r082B), 0x01));


      body.instructions = f0826_parent_instructions;
      body.emit(f0826);

      /* END IF */

      body.emit(assign(r07F3, r0825, 0x01));

      body.emit(assign(r07F4, r0824, 0x01));

      body.emit(assign(r07F2, sub(body.constant(int(1)), r07F5), 0x01));


   body.instructions = f07F6_parent_instructions;
   body.emit(f07F6);

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

   ir_variable *const r082C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r082C);
   ir_variable *const r082D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r082D);
   ir_variable *const r082E = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r082E, body.constant(true), 0x01));

   ir_variable *const r082F = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0830 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0830);
   ir_variable *const r0831 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r0831);
   ir_variable *const r0832 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0832);
   ir_variable *const r0833 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r0833);
   ir_variable *const r0834 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r0834);
   ir_variable *const r0835 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0835);
   ir_variable *const r0836 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0836);
   ir_variable *const r0837 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r0837);
   ir_variable *const r0838 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0838);
   ir_variable *const r0839 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0839);
   ir_variable *const r083A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r083A);
   body.emit(assign(r083A, body.constant(0u), 0x01));

   body.emit(assign(r0839, body.constant(0u), 0x01));

   body.emit(assign(r0838, body.constant(0u), 0x01));

   ir_variable *const r083B = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r083B, swizzle_x(r082C), 0x01));

   body.emit(assign(r0836, r083B, 0x01));

   ir_variable *const r083C = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r083C, bit_and(swizzle_y(r082C), body.constant(1048575u)), 0x01));

   body.emit(assign(r0835, r083C, 0x01));

   ir_variable *const r083D = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r083D, swizzle_x(r082D), 0x01));

   body.emit(assign(r0834, r083D, 0x01));

   ir_variable *const r083E = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r083E, bit_and(swizzle_y(r082D), body.constant(1048575u)), 0x01));

   body.emit(assign(r0833, r083E, 0x01));

   ir_variable *const r083F = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0840 = rshift(swizzle_y(r082C), body.constant(int(20)));
   ir_expression *const r0841 = bit_and(r0840, body.constant(2047u));
   body.emit(assign(r083F, expr(ir_unop_u2i, r0841), 0x01));

   body.emit(assign(r0832, r083F, 0x01));

   ir_variable *const r0842 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0843 = rshift(swizzle_y(r082D), body.constant(int(20)));
   ir_expression *const r0844 = bit_and(r0843, body.constant(2047u));
   body.emit(assign(r0842, expr(ir_unop_u2i, r0844), 0x01));

   body.emit(assign(r0831, r0842, 0x01));

   ir_expression *const r0845 = rshift(swizzle_y(r082C), body.constant(int(31)));
   ir_expression *const r0846 = rshift(swizzle_y(r082D), body.constant(int(31)));
   body.emit(assign(r0830, bit_xor(r0845, r0846), 0x01));

   /* IF CONDITION */
   ir_expression *const r0848 = equal(r083F, body.constant(int(2047)));
   ir_if *f0847 = new(mem_ctx) ir_if(operand(r0848).val);
   exec_list *const f0847_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0847->then_instructions;

      /* IF CONDITION */
      ir_expression *const r084A = bit_or(r083C, swizzle_x(r082C));
      ir_expression *const r084B = nequal(r084A, body.constant(0u));
      ir_expression *const r084C = equal(r0842, body.constant(int(2047)));
      ir_expression *const r084D = bit_or(r083E, swizzle_x(r082D));
      ir_expression *const r084E = nequal(r084D, body.constant(0u));
      ir_expression *const r084F = logic_and(r084C, r084E);
      ir_expression *const r0850 = logic_or(r084B, r084F);
      ir_if *f0849 = new(mem_ctx) ir_if(operand(r0850).val);
      exec_list *const f0849_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0849->then_instructions;

         ir_variable *const r0851 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r0851, swizzle_x(r082C), 0x01));

         ir_variable *const r0852 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r0852, swizzle_x(r082D), 0x01));

         ir_variable *const r0853 = body.make_temp(glsl_type::uvec2_type, "return_value");
         ir_variable *const r0854 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
         ir_expression *const r0855 = lshift(swizzle_y(r082D), body.constant(int(1)));
         ir_expression *const r0856 = gequal(r0855, body.constant(4292870144u));
         ir_expression *const r0857 = nequal(swizzle_x(r082D), body.constant(0u));
         ir_expression *const r0858 = bit_and(swizzle_y(r082D), body.constant(1048575u));
         ir_expression *const r0859 = nequal(r0858, body.constant(0u));
         ir_expression *const r085A = logic_or(r0857, r0859);
         body.emit(assign(r0854, logic_and(r0856, r085A), 0x01));

         body.emit(assign(r0851, bit_or(swizzle_y(r082C), body.constant(524288u)), 0x02));

         body.emit(assign(r0852, bit_or(swizzle_y(r082D), body.constant(524288u)), 0x02));

         /* IF CONDITION */
         ir_expression *const r085C = lshift(swizzle_y(r082C), body.constant(int(1)));
         ir_expression *const r085D = gequal(r085C, body.constant(4292870144u));
         ir_expression *const r085E = nequal(swizzle_x(r082C), body.constant(0u));
         ir_expression *const r085F = bit_and(swizzle_y(r082C), body.constant(1048575u));
         ir_expression *const r0860 = nequal(r085F, body.constant(0u));
         ir_expression *const r0861 = logic_or(r085E, r0860);
         ir_expression *const r0862 = logic_and(r085D, r0861);
         ir_if *f085B = new(mem_ctx) ir_if(operand(r0862).val);
         exec_list *const f085B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f085B->then_instructions;

            ir_variable *const r0863 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
            /* IF CONDITION */
            ir_if *f0864 = new(mem_ctx) ir_if(operand(r0854).val);
            exec_list *const f0864_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0864->then_instructions;

               body.emit(assign(r0863, r0852, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0864->else_instructions;

               body.emit(assign(r0863, r0851, 0x03));


            body.instructions = f0864_parent_instructions;
            body.emit(f0864);

            /* END IF */

            body.emit(assign(r0853, r0863, 0x03));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f085B->else_instructions;

            body.emit(assign(r0853, r0852, 0x03));


         body.instructions = f085B_parent_instructions;
         body.emit(f085B);

         /* END IF */

         body.emit(assign(r082F, r0853, 0x03));

         body.emit(assign(r082E, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0849->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0866 = expr(ir_unop_i2u, r0842);
         ir_expression *const r0867 = bit_or(r0866, r083E);
         ir_expression *const r0868 = bit_or(r0867, swizzle_x(r082D));
         ir_expression *const r0869 = equal(r0868, body.constant(0u));
         ir_if *f0865 = new(mem_ctx) ir_if(operand(r0869).val);
         exec_list *const f0865_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0865->then_instructions;

            ir_constant_data r086A_data;
            memset(&r086A_data, 0, sizeof(ir_constant_data));
            r086A_data.u[0] = 4294967295;
            r086A_data.u[1] = 4294967295;
            ir_constant *const r086A = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r086A_data);
            body.emit(assign(r082F, r086A, 0x03));

            body.emit(assign(r082E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0865->else_instructions;

            ir_variable *const r086B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r086B);
            ir_expression *const r086C = lshift(r0830, body.constant(int(31)));
            body.emit(assign(r086B, add(r086C, body.constant(2146435072u)), 0x02));

            body.emit(assign(r086B, body.constant(0u), 0x01));

            body.emit(assign(r082F, r086B, 0x03));

            body.emit(assign(r082E, body.constant(false), 0x01));


         body.instructions = f0865_parent_instructions;
         body.emit(f0865);

         /* END IF */


      body.instructions = f0849_parent_instructions;
      body.emit(f0849);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0847->else_instructions;

      /* IF CONDITION */
      ir_expression *const r086E = equal(r0842, body.constant(int(2047)));
      ir_if *f086D = new(mem_ctx) ir_if(operand(r086E).val);
      exec_list *const f086D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f086D->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0870 = bit_or(r083E, swizzle_x(r082D));
         ir_expression *const r0871 = nequal(r0870, body.constant(0u));
         ir_if *f086F = new(mem_ctx) ir_if(operand(r0871).val);
         exec_list *const f086F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f086F->then_instructions;

            ir_variable *const r0872 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0872, swizzle_x(r082C), 0x01));

            ir_variable *const r0873 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0873, swizzle_x(r082D), 0x01));

            ir_variable *const r0874 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0875 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
            ir_expression *const r0876 = lshift(swizzle_y(r082D), body.constant(int(1)));
            ir_expression *const r0877 = gequal(r0876, body.constant(4292870144u));
            ir_expression *const r0878 = nequal(swizzle_x(r082D), body.constant(0u));
            ir_expression *const r0879 = bit_and(swizzle_y(r082D), body.constant(1048575u));
            ir_expression *const r087A = nequal(r0879, body.constant(0u));
            ir_expression *const r087B = logic_or(r0878, r087A);
            body.emit(assign(r0875, logic_and(r0877, r087B), 0x01));

            body.emit(assign(r0872, bit_or(swizzle_y(r082C), body.constant(524288u)), 0x02));

            body.emit(assign(r0873, bit_or(swizzle_y(r082D), body.constant(524288u)), 0x02));

            /* IF CONDITION */
            ir_expression *const r087D = lshift(swizzle_y(r082C), body.constant(int(1)));
            ir_expression *const r087E = gequal(r087D, body.constant(4292870144u));
            ir_expression *const r087F = nequal(swizzle_x(r082C), body.constant(0u));
            ir_expression *const r0880 = bit_and(swizzle_y(r082C), body.constant(1048575u));
            ir_expression *const r0881 = nequal(r0880, body.constant(0u));
            ir_expression *const r0882 = logic_or(r087F, r0881);
            ir_expression *const r0883 = logic_and(r087E, r0882);
            ir_if *f087C = new(mem_ctx) ir_if(operand(r0883).val);
            exec_list *const f087C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f087C->then_instructions;

               ir_variable *const r0884 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
               /* IF CONDITION */
               ir_if *f0885 = new(mem_ctx) ir_if(operand(r0875).val);
               exec_list *const f0885_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0885->then_instructions;

                  body.emit(assign(r0884, r0873, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0885->else_instructions;

                  body.emit(assign(r0884, r0872, 0x03));


               body.instructions = f0885_parent_instructions;
               body.emit(f0885);

               /* END IF */

               body.emit(assign(r0874, r0884, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f087C->else_instructions;

               body.emit(assign(r0874, r0873, 0x03));


            body.instructions = f087C_parent_instructions;
            body.emit(f087C);

            /* END IF */

            body.emit(assign(r082F, r0874, 0x03));

            body.emit(assign(r082E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f086F->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0887 = expr(ir_unop_i2u, r083F);
            ir_expression *const r0888 = bit_or(r0887, r083C);
            ir_expression *const r0889 = bit_or(r0888, swizzle_x(r082C));
            ir_expression *const r088A = equal(r0889, body.constant(0u));
            ir_if *f0886 = new(mem_ctx) ir_if(operand(r088A).val);
            exec_list *const f0886_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0886->then_instructions;

               ir_constant_data r088B_data;
               memset(&r088B_data, 0, sizeof(ir_constant_data));
               r088B_data.u[0] = 4294967295;
               r088B_data.u[1] = 4294967295;
               ir_constant *const r088B = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r088B_data);
               body.emit(assign(r082F, r088B, 0x03));

               body.emit(assign(r082E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0886->else_instructions;

               ir_variable *const r088C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r088C);
               ir_expression *const r088D = lshift(r0830, body.constant(int(31)));
               body.emit(assign(r088C, add(r088D, body.constant(2146435072u)), 0x02));

               body.emit(assign(r088C, body.constant(0u), 0x01));

               body.emit(assign(r082F, r088C, 0x03));

               body.emit(assign(r082E, body.constant(false), 0x01));


            body.instructions = f0886_parent_instructions;
            body.emit(f0886);

            /* END IF */


         body.instructions = f086F_parent_instructions;
         body.emit(f086F);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f086D->else_instructions;

         /* IF CONDITION */
         ir_expression *const r088F = equal(r083F, body.constant(int(0)));
         ir_if *f088E = new(mem_ctx) ir_if(operand(r088F).val);
         exec_list *const f088E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f088E->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0891 = bit_or(r083C, swizzle_x(r082C));
            ir_expression *const r0892 = equal(r0891, body.constant(0u));
            ir_if *f0890 = new(mem_ctx) ir_if(operand(r0892).val);
            exec_list *const f0890_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0890->then_instructions;

               ir_variable *const r0893 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0893);
               body.emit(assign(r0893, lshift(r0830, body.constant(int(31))), 0x02));

               body.emit(assign(r0893, body.constant(0u), 0x01));

               body.emit(assign(r082F, r0893, 0x03));

               body.emit(assign(r082E, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0890->else_instructions;

               ir_variable *const r0894 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r0894, r083F, 0x01));

               ir_variable *const r0895 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r0895, r083C, 0x01));

               ir_variable *const r0896 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r0896, r083B, 0x01));

               ir_variable *const r0897 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0897);
               /* IF CONDITION */
               ir_expression *const r0899 = equal(r083C, body.constant(0u));
               ir_if *f0898 = new(mem_ctx) ir_if(operand(r0899).val);
               exec_list *const f0898_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0898->then_instructions;

                  ir_variable *const r089A = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r089A, r083B, 0x01));

                  ir_variable *const r089B = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r089C = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r089C);
                  /* IF CONDITION */
                  ir_expression *const r089E = equal(swizzle_x(r082C), body.constant(0u));
                  ir_if *f089D = new(mem_ctx) ir_if(operand(r089E).val);
                  exec_list *const f089D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f089D->then_instructions;

                     body.emit(assign(r089B, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f089D->else_instructions;

                     body.emit(assign(r089C, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08A0 = bit_and(swizzle_x(r082C), body.constant(4294901760u));
                     ir_expression *const r08A1 = equal(r08A0, body.constant(0u));
                     ir_if *f089F = new(mem_ctx) ir_if(operand(r08A1).val);
                     exec_list *const f089F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f089F->then_instructions;

                        body.emit(assign(r089C, body.constant(int(16)), 0x01));

                        body.emit(assign(r089A, lshift(swizzle_x(r082C), body.constant(int(16))), 0x01));


                     body.instructions = f089F_parent_instructions;
                     body.emit(f089F);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08A3 = bit_and(r089A, body.constant(4278190080u));
                     ir_expression *const r08A4 = equal(r08A3, body.constant(0u));
                     ir_if *f08A2 = new(mem_ctx) ir_if(operand(r08A4).val);
                     exec_list *const f08A2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08A2->then_instructions;

                        body.emit(assign(r089C, add(r089C, body.constant(int(8))), 0x01));

                        body.emit(assign(r089A, lshift(r089A, body.constant(int(8))), 0x01));


                     body.instructions = f08A2_parent_instructions;
                     body.emit(f08A2);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08A6 = bit_and(r089A, body.constant(4026531840u));
                     ir_expression *const r08A7 = equal(r08A6, body.constant(0u));
                     ir_if *f08A5 = new(mem_ctx) ir_if(operand(r08A7).val);
                     exec_list *const f08A5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08A5->then_instructions;

                        body.emit(assign(r089C, add(r089C, body.constant(int(4))), 0x01));

                        body.emit(assign(r089A, lshift(r089A, body.constant(int(4))), 0x01));


                     body.instructions = f08A5_parent_instructions;
                     body.emit(f08A5);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08A9 = bit_and(r089A, body.constant(3221225472u));
                     ir_expression *const r08AA = equal(r08A9, body.constant(0u));
                     ir_if *f08A8 = new(mem_ctx) ir_if(operand(r08AA).val);
                     exec_list *const f08A8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08A8->then_instructions;

                        body.emit(assign(r089C, add(r089C, body.constant(int(2))), 0x01));

                        body.emit(assign(r089A, lshift(r089A, body.constant(int(2))), 0x01));


                     body.instructions = f08A8_parent_instructions;
                     body.emit(f08A8);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08AC = bit_and(r089A, body.constant(2147483648u));
                     ir_expression *const r08AD = equal(r08AC, body.constant(0u));
                     ir_if *f08AB = new(mem_ctx) ir_if(operand(r08AD).val);
                     exec_list *const f08AB_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08AB->then_instructions;

                        body.emit(assign(r089C, add(r089C, body.constant(int(1))), 0x01));


                     body.instructions = f08AB_parent_instructions;
                     body.emit(f08AB);

                     /* END IF */

                     body.emit(assign(r089B, r089C, 0x01));


                  body.instructions = f089D_parent_instructions;
                  body.emit(f089D);

                  /* END IF */

                  body.emit(assign(r0897, add(r089B, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r08AF = less(r0897, body.constant(int(0)));
                  ir_if *f08AE = new(mem_ctx) ir_if(operand(r08AF).val);
                  exec_list *const f08AE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08AE->then_instructions;

                     ir_expression *const r08B0 = neg(r0897);
                     body.emit(assign(r0895, rshift(swizzle_x(r082C), r08B0), 0x01));

                     ir_expression *const r08B1 = bit_and(r0897, body.constant(int(31)));
                     body.emit(assign(r0896, lshift(swizzle_x(r082C), r08B1), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08AE->else_instructions;

                     body.emit(assign(r0895, lshift(swizzle_x(r082C), r0897), 0x01));

                     body.emit(assign(r0896, body.constant(0u), 0x01));


                  body.instructions = f08AE_parent_instructions;
                  body.emit(f08AE);

                  /* END IF */

                  body.emit(assign(r0894, sub(body.constant(int(-31)), r0897), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0898->else_instructions;

                  ir_variable *const r08B2 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r08B2, r083C, 0x01));

                  ir_variable *const r08B3 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r08B4 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08B4);
                  /* IF CONDITION */
                  ir_expression *const r08B6 = equal(r083C, body.constant(0u));
                  ir_if *f08B5 = new(mem_ctx) ir_if(operand(r08B6).val);
                  exec_list *const f08B5_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08B5->then_instructions;

                     body.emit(assign(r08B3, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08B5->else_instructions;

                     body.emit(assign(r08B4, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08B8 = bit_and(r083C, body.constant(4294901760u));
                     ir_expression *const r08B9 = equal(r08B8, body.constant(0u));
                     ir_if *f08B7 = new(mem_ctx) ir_if(operand(r08B9).val);
                     exec_list *const f08B7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08B7->then_instructions;

                        body.emit(assign(r08B4, body.constant(int(16)), 0x01));

                        body.emit(assign(r08B2, lshift(r083C, body.constant(int(16))), 0x01));


                     body.instructions = f08B7_parent_instructions;
                     body.emit(f08B7);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08BB = bit_and(r08B2, body.constant(4278190080u));
                     ir_expression *const r08BC = equal(r08BB, body.constant(0u));
                     ir_if *f08BA = new(mem_ctx) ir_if(operand(r08BC).val);
                     exec_list *const f08BA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08BA->then_instructions;

                        body.emit(assign(r08B4, add(r08B4, body.constant(int(8))), 0x01));

                        body.emit(assign(r08B2, lshift(r08B2, body.constant(int(8))), 0x01));


                     body.instructions = f08BA_parent_instructions;
                     body.emit(f08BA);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08BE = bit_and(r08B2, body.constant(4026531840u));
                     ir_expression *const r08BF = equal(r08BE, body.constant(0u));
                     ir_if *f08BD = new(mem_ctx) ir_if(operand(r08BF).val);
                     exec_list *const f08BD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08BD->then_instructions;

                        body.emit(assign(r08B4, add(r08B4, body.constant(int(4))), 0x01));

                        body.emit(assign(r08B2, lshift(r08B2, body.constant(int(4))), 0x01));


                     body.instructions = f08BD_parent_instructions;
                     body.emit(f08BD);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08C1 = bit_and(r08B2, body.constant(3221225472u));
                     ir_expression *const r08C2 = equal(r08C1, body.constant(0u));
                     ir_if *f08C0 = new(mem_ctx) ir_if(operand(r08C2).val);
                     exec_list *const f08C0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08C0->then_instructions;

                        body.emit(assign(r08B4, add(r08B4, body.constant(int(2))), 0x01));

                        body.emit(assign(r08B2, lshift(r08B2, body.constant(int(2))), 0x01));


                     body.instructions = f08C0_parent_instructions;
                     body.emit(f08C0);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08C4 = bit_and(r08B2, body.constant(2147483648u));
                     ir_expression *const r08C5 = equal(r08C4, body.constant(0u));
                     ir_if *f08C3 = new(mem_ctx) ir_if(operand(r08C5).val);
                     exec_list *const f08C3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08C3->then_instructions;

                        body.emit(assign(r08B4, add(r08B4, body.constant(int(1))), 0x01));


                     body.instructions = f08C3_parent_instructions;
                     body.emit(f08C3);

                     /* END IF */

                     body.emit(assign(r08B3, r08B4, 0x01));


                  body.instructions = f08B5_parent_instructions;
                  body.emit(f08B5);

                  /* END IF */

                  body.emit(assign(r0897, add(r08B3, body.constant(int(-11))), 0x01));

                  ir_variable *const r08C6 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r08C6, lshift(swizzle_x(r082C), r0897), 0x01));

                  ir_variable *const r08C7 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r08C9 = equal(r0897, body.constant(int(0)));
                  ir_if *f08C8 = new(mem_ctx) ir_if(operand(r08C9).val);
                  exec_list *const f08C8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08C8->then_instructions;

                     body.emit(assign(r08C7, r083C, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08C8->else_instructions;

                     ir_expression *const r08CA = lshift(r083C, r0897);
                     ir_expression *const r08CB = neg(r0897);
                     ir_expression *const r08CC = bit_and(r08CB, body.constant(int(31)));
                     ir_expression *const r08CD = rshift(swizzle_x(r082C), r08CC);
                     body.emit(assign(r08C7, bit_or(r08CA, r08CD), 0x01));


                  body.instructions = f08C8_parent_instructions;
                  body.emit(f08C8);

                  /* END IF */

                  body.emit(assign(r0895, r08C7, 0x01));

                  body.emit(assign(r0896, r08C6, 0x01));

                  body.emit(assign(r0894, sub(body.constant(int(1)), r0897), 0x01));


               body.instructions = f0898_parent_instructions;
               body.emit(f0898);

               /* END IF */

               body.emit(assign(r0832, r0894, 0x01));

               body.emit(assign(r0835, r0895, 0x01));

               body.emit(assign(r0836, r0896, 0x01));


            body.instructions = f0890_parent_instructions;
            body.emit(f0890);

            /* END IF */


         body.instructions = f088E_parent_instructions;
         body.emit(f088E);

         /* END IF */

         /* IF CONDITION */
         ir_if *f08CE = new(mem_ctx) ir_if(operand(r082E).val);
         exec_list *const f08CE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08CE->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08D0 = equal(r0842, body.constant(int(0)));
            ir_if *f08CF = new(mem_ctx) ir_if(operand(r08D0).val);
            exec_list *const f08CF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08CF->then_instructions;

               /* IF CONDITION */
               ir_expression *const r08D2 = bit_or(r083E, swizzle_x(r082D));
               ir_expression *const r08D3 = equal(r08D2, body.constant(0u));
               ir_if *f08D1 = new(mem_ctx) ir_if(operand(r08D3).val);
               exec_list *const f08D1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08D1->then_instructions;

                  ir_variable *const r08D4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r08D4);
                  body.emit(assign(r08D4, lshift(r0830, body.constant(int(31))), 0x02));

                  body.emit(assign(r08D4, body.constant(0u), 0x01));

                  body.emit(assign(r082F, r08D4, 0x03));

                  body.emit(assign(r082E, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08D1->else_instructions;

                  ir_variable *const r08D5 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r08D5, r0842, 0x01));

                  ir_variable *const r08D6 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r08D6, r083E, 0x01));

                  ir_variable *const r08D7 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r08D7, r083D, 0x01));

                  ir_variable *const r08D8 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08D8);
                  /* IF CONDITION */
                  ir_expression *const r08DA = equal(r083E, body.constant(0u));
                  ir_if *f08D9 = new(mem_ctx) ir_if(operand(r08DA).val);
                  exec_list *const f08D9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08D9->then_instructions;

                     ir_variable *const r08DB = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r08DB, r083D, 0x01));

                     ir_variable *const r08DC = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r08DD = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r08DD);
                     /* IF CONDITION */
                     ir_expression *const r08DF = equal(swizzle_x(r082D), body.constant(0u));
                     ir_if *f08DE = new(mem_ctx) ir_if(operand(r08DF).val);
                     exec_list *const f08DE_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08DE->then_instructions;

                        body.emit(assign(r08DC, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08DE->else_instructions;

                        body.emit(assign(r08DD, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08E1 = bit_and(swizzle_x(r082D), body.constant(4294901760u));
                        ir_expression *const r08E2 = equal(r08E1, body.constant(0u));
                        ir_if *f08E0 = new(mem_ctx) ir_if(operand(r08E2).val);
                        exec_list *const f08E0_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08E0->then_instructions;

                           body.emit(assign(r08DD, body.constant(int(16)), 0x01));

                           body.emit(assign(r08DB, lshift(swizzle_x(r082D), body.constant(int(16))), 0x01));


                        body.instructions = f08E0_parent_instructions;
                        body.emit(f08E0);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08E4 = bit_and(r08DB, body.constant(4278190080u));
                        ir_expression *const r08E5 = equal(r08E4, body.constant(0u));
                        ir_if *f08E3 = new(mem_ctx) ir_if(operand(r08E5).val);
                        exec_list *const f08E3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08E3->then_instructions;

                           body.emit(assign(r08DD, add(r08DD, body.constant(int(8))), 0x01));

                           body.emit(assign(r08DB, lshift(r08DB, body.constant(int(8))), 0x01));


                        body.instructions = f08E3_parent_instructions;
                        body.emit(f08E3);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08E7 = bit_and(r08DB, body.constant(4026531840u));
                        ir_expression *const r08E8 = equal(r08E7, body.constant(0u));
                        ir_if *f08E6 = new(mem_ctx) ir_if(operand(r08E8).val);
                        exec_list *const f08E6_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08E6->then_instructions;

                           body.emit(assign(r08DD, add(r08DD, body.constant(int(4))), 0x01));

                           body.emit(assign(r08DB, lshift(r08DB, body.constant(int(4))), 0x01));


                        body.instructions = f08E6_parent_instructions;
                        body.emit(f08E6);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08EA = bit_and(r08DB, body.constant(3221225472u));
                        ir_expression *const r08EB = equal(r08EA, body.constant(0u));
                        ir_if *f08E9 = new(mem_ctx) ir_if(operand(r08EB).val);
                        exec_list *const f08E9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08E9->then_instructions;

                           body.emit(assign(r08DD, add(r08DD, body.constant(int(2))), 0x01));

                           body.emit(assign(r08DB, lshift(r08DB, body.constant(int(2))), 0x01));


                        body.instructions = f08E9_parent_instructions;
                        body.emit(f08E9);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08ED = bit_and(r08DB, body.constant(2147483648u));
                        ir_expression *const r08EE = equal(r08ED, body.constant(0u));
                        ir_if *f08EC = new(mem_ctx) ir_if(operand(r08EE).val);
                        exec_list *const f08EC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08EC->then_instructions;

                           body.emit(assign(r08DD, add(r08DD, body.constant(int(1))), 0x01));


                        body.instructions = f08EC_parent_instructions;
                        body.emit(f08EC);

                        /* END IF */

                        body.emit(assign(r08DC, r08DD, 0x01));


                     body.instructions = f08DE_parent_instructions;
                     body.emit(f08DE);

                     /* END IF */

                     body.emit(assign(r08D8, add(r08DC, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08F0 = less(r08D8, body.constant(int(0)));
                     ir_if *f08EF = new(mem_ctx) ir_if(operand(r08F0).val);
                     exec_list *const f08EF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08EF->then_instructions;

                        ir_expression *const r08F1 = neg(r08D8);
                        body.emit(assign(r08D6, rshift(swizzle_x(r082D), r08F1), 0x01));

                        ir_expression *const r08F2 = bit_and(r08D8, body.constant(int(31)));
                        body.emit(assign(r08D7, lshift(swizzle_x(r082D), r08F2), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08EF->else_instructions;

                        body.emit(assign(r08D6, lshift(swizzle_x(r082D), r08D8), 0x01));

                        body.emit(assign(r08D7, body.constant(0u), 0x01));


                     body.instructions = f08EF_parent_instructions;
                     body.emit(f08EF);

                     /* END IF */

                     body.emit(assign(r08D5, sub(body.constant(int(-31)), r08D8), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08D9->else_instructions;

                     ir_variable *const r08F3 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r08F3, r083E, 0x01));

                     ir_variable *const r08F4 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r08F5 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r08F5);
                     /* IF CONDITION */
                     ir_expression *const r08F7 = equal(r083E, body.constant(0u));
                     ir_if *f08F6 = new(mem_ctx) ir_if(operand(r08F7).val);
                     exec_list *const f08F6_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F6->then_instructions;

                        body.emit(assign(r08F4, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08F6->else_instructions;

                        body.emit(assign(r08F5, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08F9 = bit_and(r083E, body.constant(4294901760u));
                        ir_expression *const r08FA = equal(r08F9, body.constant(0u));
                        ir_if *f08F8 = new(mem_ctx) ir_if(operand(r08FA).val);
                        exec_list *const f08F8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08F8->then_instructions;

                           body.emit(assign(r08F5, body.constant(int(16)), 0x01));

                           body.emit(assign(r08F3, lshift(r083E, body.constant(int(16))), 0x01));


                        body.instructions = f08F8_parent_instructions;
                        body.emit(f08F8);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08FC = bit_and(r08F3, body.constant(4278190080u));
                        ir_expression *const r08FD = equal(r08FC, body.constant(0u));
                        ir_if *f08FB = new(mem_ctx) ir_if(operand(r08FD).val);
                        exec_list *const f08FB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08FB->then_instructions;

                           body.emit(assign(r08F5, add(r08F5, body.constant(int(8))), 0x01));

                           body.emit(assign(r08F3, lshift(r08F3, body.constant(int(8))), 0x01));


                        body.instructions = f08FB_parent_instructions;
                        body.emit(f08FB);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08FF = bit_and(r08F3, body.constant(4026531840u));
                        ir_expression *const r0900 = equal(r08FF, body.constant(0u));
                        ir_if *f08FE = new(mem_ctx) ir_if(operand(r0900).val);
                        exec_list *const f08FE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08FE->then_instructions;

                           body.emit(assign(r08F5, add(r08F5, body.constant(int(4))), 0x01));

                           body.emit(assign(r08F3, lshift(r08F3, body.constant(int(4))), 0x01));


                        body.instructions = f08FE_parent_instructions;
                        body.emit(f08FE);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0902 = bit_and(r08F3, body.constant(3221225472u));
                        ir_expression *const r0903 = equal(r0902, body.constant(0u));
                        ir_if *f0901 = new(mem_ctx) ir_if(operand(r0903).val);
                        exec_list *const f0901_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0901->then_instructions;

                           body.emit(assign(r08F5, add(r08F5, body.constant(int(2))), 0x01));

                           body.emit(assign(r08F3, lshift(r08F3, body.constant(int(2))), 0x01));


                        body.instructions = f0901_parent_instructions;
                        body.emit(f0901);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0905 = bit_and(r08F3, body.constant(2147483648u));
                        ir_expression *const r0906 = equal(r0905, body.constant(0u));
                        ir_if *f0904 = new(mem_ctx) ir_if(operand(r0906).val);
                        exec_list *const f0904_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0904->then_instructions;

                           body.emit(assign(r08F5, add(r08F5, body.constant(int(1))), 0x01));


                        body.instructions = f0904_parent_instructions;
                        body.emit(f0904);

                        /* END IF */

                        body.emit(assign(r08F4, r08F5, 0x01));


                     body.instructions = f08F6_parent_instructions;
                     body.emit(f08F6);

                     /* END IF */

                     body.emit(assign(r08D8, add(r08F4, body.constant(int(-11))), 0x01));

                     ir_variable *const r0907 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r0907, lshift(swizzle_x(r082D), r08D8), 0x01));

                     ir_variable *const r0908 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r090A = equal(r08D8, body.constant(int(0)));
                     ir_if *f0909 = new(mem_ctx) ir_if(operand(r090A).val);
                     exec_list *const f0909_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0909->then_instructions;

                        body.emit(assign(r0908, r083E, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0909->else_instructions;

                        ir_expression *const r090B = lshift(r083E, r08D8);
                        ir_expression *const r090C = neg(r08D8);
                        ir_expression *const r090D = bit_and(r090C, body.constant(int(31)));
                        ir_expression *const r090E = rshift(swizzle_x(r082D), r090D);
                        body.emit(assign(r0908, bit_or(r090B, r090E), 0x01));


                     body.instructions = f0909_parent_instructions;
                     body.emit(f0909);

                     /* END IF */

                     body.emit(assign(r08D6, r0908, 0x01));

                     body.emit(assign(r08D7, r0907, 0x01));

                     body.emit(assign(r08D5, sub(body.constant(int(1)), r08D8), 0x01));


                  body.instructions = f08D9_parent_instructions;
                  body.emit(f08D9);

                  /* END IF */

                  body.emit(assign(r0831, r08D5, 0x01));

                  body.emit(assign(r0833, r08D6, 0x01));

                  body.emit(assign(r0834, r08D7, 0x01));


               body.instructions = f08D1_parent_instructions;
               body.emit(f08D1);

               /* END IF */


            body.instructions = f08CF_parent_instructions;
            body.emit(f08CF);

            /* END IF */

            /* IF CONDITION */
            ir_if *f090F = new(mem_ctx) ir_if(operand(r082E).val);
            exec_list *const f090F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f090F->then_instructions;

               ir_expression *const r0910 = add(r0832, r0831);
               body.emit(assign(r0837, add(r0910, body.constant(int(-1024))), 0x01));

               body.emit(assign(r0835, bit_or(r0835, body.constant(1048576u)), 0x01));

               ir_variable *const r0911 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0911, lshift(r0834, body.constant(int(12))), 0x01));

               ir_variable *const r0912 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               ir_expression *const r0913 = lshift(r0833, body.constant(int(12)));
               ir_expression *const r0914 = rshift(r0834, body.constant(int(20)));
               body.emit(assign(r0912, bit_or(r0913, r0914), 0x01));

               body.emit(assign(r0833, r0912, 0x01));

               body.emit(assign(r0834, r0911, 0x01));

               ir_variable *const r0915 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0915);
               ir_variable *const r0916 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0916);
               ir_variable *const r0917 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0917);
               ir_variable *const r0918 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0918, bit_and(r0836, body.constant(65535u)), 0x01));

               ir_variable *const r0919 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0919, rshift(r0836, body.constant(int(16))), 0x01));

               ir_variable *const r091A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r091A, bit_and(r0911, body.constant(65535u)), 0x01));

               ir_variable *const r091B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r091B, rshift(r0911, body.constant(int(16))), 0x01));

               ir_variable *const r091C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r091C, mul(r0919, r091A), 0x01));

               ir_expression *const r091D = mul(r0918, r091B);
               body.emit(assign(r0916, add(r091D, r091C), 0x01));

               ir_expression *const r091E = mul(r0919, r091B);
               ir_expression *const r091F = less(r0916, r091C);
               ir_expression *const r0920 = expr(ir_unop_b2i, r091F);
               ir_expression *const r0921 = expr(ir_unop_i2u, r0920);
               ir_expression *const r0922 = lshift(r0921, body.constant(int(16)));
               ir_expression *const r0923 = rshift(r0916, body.constant(int(16)));
               ir_expression *const r0924 = add(r0922, r0923);
               body.emit(assign(r0915, add(r091E, r0924), 0x01));

               body.emit(assign(r0916, lshift(r0916, body.constant(int(16))), 0x01));

               ir_expression *const r0925 = mul(r0918, r091A);
               body.emit(assign(r0917, add(r0925, r0916), 0x01));

               ir_expression *const r0926 = less(r0917, r0916);
               ir_expression *const r0927 = expr(ir_unop_b2i, r0926);
               ir_expression *const r0928 = expr(ir_unop_i2u, r0927);
               body.emit(assign(r0915, add(r0915, r0928), 0x01));

               ir_variable *const r0929 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0929);
               ir_variable *const r092A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r092A);
               ir_variable *const r092B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r092B);
               ir_variable *const r092C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r092C, bit_and(r0836, body.constant(65535u)), 0x01));

               ir_variable *const r092D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r092D, rshift(r0836, body.constant(int(16))), 0x01));

               ir_variable *const r092E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r092E, bit_and(r0912, body.constant(65535u)), 0x01));

               ir_variable *const r092F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r092F, rshift(r0912, body.constant(int(16))), 0x01));

               ir_variable *const r0930 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0930, mul(r092D, r092E), 0x01));

               ir_expression *const r0931 = mul(r092C, r092F);
               body.emit(assign(r092A, add(r0931, r0930), 0x01));

               ir_expression *const r0932 = mul(r092D, r092F);
               ir_expression *const r0933 = less(r092A, r0930);
               ir_expression *const r0934 = expr(ir_unop_b2i, r0933);
               ir_expression *const r0935 = expr(ir_unop_i2u, r0934);
               ir_expression *const r0936 = lshift(r0935, body.constant(int(16)));
               ir_expression *const r0937 = rshift(r092A, body.constant(int(16)));
               ir_expression *const r0938 = add(r0936, r0937);
               body.emit(assign(r0929, add(r0932, r0938), 0x01));

               body.emit(assign(r092A, lshift(r092A, body.constant(int(16))), 0x01));

               ir_expression *const r0939 = mul(r092C, r092E);
               body.emit(assign(r092B, add(r0939, r092A), 0x01));

               ir_expression *const r093A = less(r092B, r092A);
               ir_expression *const r093B = expr(ir_unop_b2i, r093A);
               ir_expression *const r093C = expr(ir_unop_i2u, r093B);
               body.emit(assign(r0929, add(r0929, r093C), 0x01));

               ir_variable *const r093D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r093D, add(r092B, r0915), 0x01));

               ir_variable *const r093E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r093E);
               ir_variable *const r093F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r093F);
               ir_variable *const r0940 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0940);
               ir_variable *const r0941 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0941, bit_and(r0835, body.constant(65535u)), 0x01));

               ir_variable *const r0942 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0942, rshift(r0835, body.constant(int(16))), 0x01));

               ir_variable *const r0943 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0943, bit_and(r0912, body.constant(65535u)), 0x01));

               ir_variable *const r0944 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0944, rshift(r0912, body.constant(int(16))), 0x01));

               ir_variable *const r0945 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0945, mul(r0942, r0943), 0x01));

               ir_expression *const r0946 = mul(r0941, r0944);
               body.emit(assign(r093F, add(r0946, r0945), 0x01));

               ir_expression *const r0947 = mul(r0942, r0944);
               ir_expression *const r0948 = less(r093F, r0945);
               ir_expression *const r0949 = expr(ir_unop_b2i, r0948);
               ir_expression *const r094A = expr(ir_unop_i2u, r0949);
               ir_expression *const r094B = lshift(r094A, body.constant(int(16)));
               ir_expression *const r094C = rshift(r093F, body.constant(int(16)));
               ir_expression *const r094D = add(r094B, r094C);
               body.emit(assign(r093E, add(r0947, r094D), 0x01));

               body.emit(assign(r093F, lshift(r093F, body.constant(int(16))), 0x01));

               ir_expression *const r094E = mul(r0941, r0943);
               body.emit(assign(r0940, add(r094E, r093F), 0x01));

               ir_expression *const r094F = less(r0940, r093F);
               ir_expression *const r0950 = expr(ir_unop_b2i, r094F);
               ir_expression *const r0951 = expr(ir_unop_i2u, r0950);
               body.emit(assign(r093E, add(r093E, r0951), 0x01));

               ir_variable *const r0952 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0953 = less(r093D, r092B);
               ir_expression *const r0954 = expr(ir_unop_b2i, r0953);
               ir_expression *const r0955 = expr(ir_unop_i2u, r0954);
               ir_expression *const r0956 = add(r0929, r0955);
               body.emit(assign(r0952, add(r0940, r0956), 0x01));

               ir_variable *const r0957 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0957);
               ir_variable *const r0958 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0958);
               ir_variable *const r0959 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0959);
               ir_variable *const r095A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095A, bit_and(r0835, body.constant(65535u)), 0x01));

               ir_variable *const r095B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095B, rshift(r0835, body.constant(int(16))), 0x01));

               ir_variable *const r095C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095C, bit_and(r0911, body.constant(65535u)), 0x01));

               ir_variable *const r095D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095D, rshift(r0911, body.constant(int(16))), 0x01));

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
               body.emit(assign(r096B, add(r0959, r093D), 0x01));

               ir_variable *const r096C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r096D = less(r096B, r0959);
               ir_expression *const r096E = expr(ir_unop_b2i, r096D);
               ir_expression *const r096F = expr(ir_unop_i2u, r096E);
               ir_expression *const r0970 = add(r0957, r096F);
               body.emit(assign(r096C, add(r0952, r0970), 0x01));

               ir_variable *const r0971 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0972 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0972, add(r096C, r0836), 0x01));

               ir_expression *const r0973 = less(r0952, r0940);
               ir_expression *const r0974 = expr(ir_unop_b2i, r0973);
               ir_expression *const r0975 = expr(ir_unop_i2u, r0974);
               ir_expression *const r0976 = add(r093E, r0975);
               ir_expression *const r0977 = less(r096C, r0952);
               ir_expression *const r0978 = expr(ir_unop_b2i, r0977);
               ir_expression *const r0979 = expr(ir_unop_i2u, r0978);
               ir_expression *const r097A = add(r0976, r0979);
               ir_expression *const r097B = add(r097A, r0835);
               ir_expression *const r097C = less(r0972, r096C);
               ir_expression *const r097D = expr(ir_unop_b2i, r097C);
               ir_expression *const r097E = expr(ir_unop_i2u, r097D);
               body.emit(assign(r0971, add(r097B, r097E), 0x01));

               body.emit(assign(r083A, r0971, 0x01));

               body.emit(assign(r0839, r0972, 0x01));

               ir_expression *const r097F = nequal(r0917, body.constant(0u));
               ir_expression *const r0980 = expr(ir_unop_b2i, r097F);
               ir_expression *const r0981 = expr(ir_unop_i2u, r0980);
               body.emit(assign(r0838, bit_or(r096B, r0981), 0x01));

               /* IF CONDITION */
               ir_expression *const r0983 = gequal(r0971, body.constant(2097152u));
               ir_if *f0982 = new(mem_ctx) ir_if(operand(r0983).val);
               exec_list *const f0982_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0982->then_instructions;

                  ir_variable *const r0984 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0984);
                  body.emit(assign(r0984, lshift(r0972, body.constant(int(31))), 0x01));

                  ir_expression *const r0985 = nequal(r0838, body.constant(0u));
                  ir_expression *const r0986 = expr(ir_unop_b2i, r0985);
                  ir_expression *const r0987 = expr(ir_unop_i2u, r0986);
                  body.emit(assign(r0984, bit_or(r0984, r0987), 0x01));

                  body.emit(assign(r083A, rshift(r0971, body.constant(int(1))), 0x01));

                  ir_expression *const r0988 = lshift(r0971, body.constant(int(31)));
                  ir_expression *const r0989 = rshift(r0972, body.constant(int(1)));
                  body.emit(assign(r0839, bit_or(r0988, r0989), 0x01));

                  body.emit(assign(r0838, r0984, 0x01));

                  body.emit(assign(r0837, add(r0837, body.constant(int(1))), 0x01));


               body.instructions = f0982_parent_instructions;
               body.emit(f0982);

               /* END IF */

               ir_variable *const r098A = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r098A, r0837, 0x01));

               ir_variable *const r098B = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r098B, r083A, 0x01));

               ir_variable *const r098C = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r098C, r0839, 0x01));

               ir_variable *const r098D = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r098D, r0838, 0x01));

               ir_variable *const r098E = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r098E, body.constant(true), 0x01));

               ir_variable *const r098F = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0990 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0990);
               ir_expression *const r0991 = expr(ir_unop_u2i, r0838);
               body.emit(assign(r0990, less(r0991, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0993 = gequal(r0837, body.constant(int(2045)));
               ir_if *f0992 = new(mem_ctx) ir_if(operand(r0993).val);
               exec_list *const f0992_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0992->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0995 = less(body.constant(int(2045)), r0837);
                  ir_expression *const r0996 = equal(r0837, body.constant(int(2045)));
                  ir_expression *const r0997 = equal(body.constant(2097151u), r083A);
                  ir_expression *const r0998 = equal(body.constant(4294967295u), r0839);
                  ir_expression *const r0999 = logic_and(r0997, r0998);
                  ir_expression *const r099A = logic_and(r0996, r0999);
                  ir_expression *const r099B = logic_and(r099A, r0990);
                  ir_expression *const r099C = logic_or(r0995, r099B);
                  ir_if *f0994 = new(mem_ctx) ir_if(operand(r099C).val);
                  exec_list *const f0994_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0994->then_instructions;

                     ir_variable *const r099D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r099D);
                     ir_expression *const r099E = lshift(r0830, body.constant(int(31)));
                     body.emit(assign(r099D, add(r099E, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r099D, body.constant(0u), 0x01));

                     body.emit(assign(r098F, r099D, 0x03));

                     body.emit(assign(r098E, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0994->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09A0 = less(r0837, body.constant(int(0)));
                     ir_if *f099F = new(mem_ctx) ir_if(operand(r09A0).val);
                     exec_list *const f099F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f099F->then_instructions;

                        ir_variable *const r09A1 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r09A1, r0838, 0x01));

                        ir_variable *const r09A2 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r09A2, neg(r0837), 0x01));

                        ir_variable *const r09A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r09A3);
                        ir_variable *const r09A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r09A4);
                        ir_variable *const r09A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r09A5);
                        ir_variable *const r09A6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r09A7 = neg(r09A2);
                        body.emit(assign(r09A6, bit_and(r09A7, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r09A9 = equal(r09A2, body.constant(int(0)));
                        ir_if *f09A8 = new(mem_ctx) ir_if(operand(r09A9).val);
                        exec_list *const f09A8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f09A8->then_instructions;

                           body.emit(assign(r09A3, r0838, 0x01));

                           body.emit(assign(r09A4, r0839, 0x01));

                           body.emit(assign(r09A5, r083A, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f09A8->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r09AB = less(r09A2, body.constant(int(32)));
                           ir_if *f09AA = new(mem_ctx) ir_if(operand(r09AB).val);
                           exec_list *const f09AA_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f09AA->then_instructions;

                              body.emit(assign(r09A3, lshift(r0839, r09A6), 0x01));

                              ir_expression *const r09AC = lshift(r083A, r09A6);
                              ir_expression *const r09AD = rshift(r0839, r09A2);
                              body.emit(assign(r09A4, bit_or(r09AC, r09AD), 0x01));

                              body.emit(assign(r09A5, rshift(r083A, r09A2), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f09AA->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r09AF = equal(r09A2, body.constant(int(32)));
                              ir_if *f09AE = new(mem_ctx) ir_if(operand(r09AF).val);
                              exec_list *const f09AE_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f09AE->then_instructions;

                                 body.emit(assign(r09A3, r0839, 0x01));

                                 body.emit(assign(r09A4, r083A, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f09AE->else_instructions;

                                 body.emit(assign(r09A1, bit_or(r0838, r0839), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r09B1 = less(r09A2, body.constant(int(64)));
                                 ir_if *f09B0 = new(mem_ctx) ir_if(operand(r09B1).val);
                                 exec_list *const f09B0_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f09B0->then_instructions;

                                    body.emit(assign(r09A3, lshift(r083A, r09A6), 0x01));

                                    ir_expression *const r09B2 = bit_and(r09A2, body.constant(int(31)));
                                    body.emit(assign(r09A4, rshift(r083A, r09B2), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f09B0->else_instructions;

                                    ir_variable *const r09B3 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r09B5 = equal(r09A2, body.constant(int(64)));
                                    ir_if *f09B4 = new(mem_ctx) ir_if(operand(r09B5).val);
                                    exec_list *const f09B4_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f09B4->then_instructions;

                                       body.emit(assign(r09B3, r083A, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f09B4->else_instructions;

                                       ir_expression *const r09B6 = nequal(r083A, body.constant(0u));
                                       ir_expression *const r09B7 = expr(ir_unop_b2i, r09B6);
                                       body.emit(assign(r09B3, expr(ir_unop_i2u, r09B7), 0x01));


                                    body.instructions = f09B4_parent_instructions;
                                    body.emit(f09B4);

                                    /* END IF */

                                    body.emit(assign(r09A3, r09B3, 0x01));

                                    body.emit(assign(r09A4, body.constant(0u), 0x01));


                                 body.instructions = f09B0_parent_instructions;
                                 body.emit(f09B0);

                                 /* END IF */


                              body.instructions = f09AE_parent_instructions;
                              body.emit(f09AE);

                              /* END IF */

                              body.emit(assign(r09A5, body.constant(0u), 0x01));


                           body.instructions = f09AA_parent_instructions;
                           body.emit(f09AA);

                           /* END IF */

                           ir_expression *const r09B8 = nequal(r09A1, body.constant(0u));
                           ir_expression *const r09B9 = expr(ir_unop_b2i, r09B8);
                           ir_expression *const r09BA = expr(ir_unop_i2u, r09B9);
                           body.emit(assign(r09A3, bit_or(r09A3, r09BA), 0x01));


                        body.instructions = f09A8_parent_instructions;
                        body.emit(f09A8);

                        /* END IF */

                        body.emit(assign(r098B, r09A5, 0x01));

                        body.emit(assign(r098C, r09A4, 0x01));

                        body.emit(assign(r098D, r09A3, 0x01));

                        body.emit(assign(r098A, body.constant(int(0)), 0x01));

                        body.emit(assign(r0990, less(r09A3, body.constant(0u)), 0x01));


                     body.instructions = f099F_parent_instructions;
                     body.emit(f099F);

                     /* END IF */


                  body.instructions = f0994_parent_instructions;
                  body.emit(f0994);

                  /* END IF */


               body.instructions = f0992_parent_instructions;
               body.emit(f0992);

               /* END IF */

               /* IF CONDITION */
               ir_if *f09BB = new(mem_ctx) ir_if(operand(r098E).val);
               exec_list *const f09BB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09BB->then_instructions;

                  /* IF CONDITION */
                  ir_if *f09BC = new(mem_ctx) ir_if(operand(r0990).val);
                  exec_list *const f09BC_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09BC->then_instructions;

                     ir_variable *const r09BD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r09BD, add(r098C, body.constant(1u)), 0x01));

                     ir_expression *const r09BE = less(r09BD, r098C);
                     ir_expression *const r09BF = expr(ir_unop_b2i, r09BE);
                     ir_expression *const r09C0 = expr(ir_unop_i2u, r09BF);
                     body.emit(assign(r098B, add(r098B, r09C0), 0x01));

                     ir_expression *const r09C1 = equal(r098D, body.constant(0u));
                     ir_expression *const r09C2 = expr(ir_unop_b2i, r09C1);
                     ir_expression *const r09C3 = expr(ir_unop_i2u, r09C2);
                     ir_expression *const r09C4 = add(r098D, r09C3);
                     ir_expression *const r09C5 = bit_and(r09C4, body.constant(1u));
                     ir_expression *const r09C6 = expr(ir_unop_bit_not, r09C5);
                     body.emit(assign(r098C, bit_and(r09BD, r09C6), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09BC->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09C8 = bit_or(r098B, r098C);
                     ir_expression *const r09C9 = equal(r09C8, body.constant(0u));
                     ir_if *f09C7 = new(mem_ctx) ir_if(operand(r09C9).val);
                     exec_list *const f09C7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09C7->then_instructions;

                        body.emit(assign(r098A, body.constant(int(0)), 0x01));


                     body.instructions = f09C7_parent_instructions;
                     body.emit(f09C7);

                     /* END IF */


                  body.instructions = f09BC_parent_instructions;
                  body.emit(f09BC);

                  /* END IF */

                  ir_variable *const r09CA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r09CA);
                  ir_expression *const r09CB = lshift(r0830, body.constant(int(31)));
                  ir_expression *const r09CC = expr(ir_unop_i2u, r098A);
                  ir_expression *const r09CD = lshift(r09CC, body.constant(int(20)));
                  ir_expression *const r09CE = add(r09CB, r09CD);
                  body.emit(assign(r09CA, add(r09CE, r098B), 0x02));

                  body.emit(assign(r09CA, r098C, 0x01));

                  body.emit(assign(r098F, r09CA, 0x03));

                  body.emit(assign(r098E, body.constant(false), 0x01));


               body.instructions = f09BB_parent_instructions;
               body.emit(f09BB);

               /* END IF */

               body.emit(assign(r082F, r098F, 0x03));

               body.emit(assign(r082E, body.constant(false), 0x01));


            body.instructions = f090F_parent_instructions;
            body.emit(f090F);

            /* END IF */


         body.instructions = f08CE_parent_instructions;
         body.emit(f08CE);

         /* END IF */


      body.instructions = f086D_parent_instructions;
      body.emit(f086D);

      /* END IF */


   body.instructions = f0847_parent_instructions;
   body.emit(f0847);

   /* END IF */

   body.emit(ret(r082F));

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

   ir_variable *const r09CF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09CF);
   ir_variable *const r09D0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09D0);
   ir_variable *const r09D1 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r09D1);
   ir_variable *const r09D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09D2);
   ir_variable *const r09D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09D3);
   ir_variable *const r09D4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r09D4);
   ir_variable *const r09D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r09D5);
   ir_variable *const r09D6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r09D7 = neg(r09D1);
   body.emit(assign(r09D6, bit_and(r09D7, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r09D9 = equal(r09D1, body.constant(int(0)));
   ir_if *f09D8 = new(mem_ctx) ir_if(operand(r09D9).val);
   exec_list *const f09D8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09D8->then_instructions;

      body.emit(assign(r09D4, r09D0, 0x01));

      body.emit(assign(r09D5, r09CF, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09D8->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09DB = less(r09D1, body.constant(int(32)));
      ir_if *f09DA = new(mem_ctx) ir_if(operand(r09DB).val);
      exec_list *const f09DA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09DA->then_instructions;

         ir_expression *const r09DC = lshift(r09CF, r09D6);
         ir_expression *const r09DD = rshift(r09D0, r09D1);
         body.emit(assign(r09D4, bit_or(r09DC, r09DD), 0x01));

         body.emit(assign(r09D5, rshift(r09CF, r09D1), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09DA->else_instructions;

         ir_variable *const r09DE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09E0 = less(r09D1, body.constant(int(64)));
         ir_if *f09DF = new(mem_ctx) ir_if(operand(r09E0).val);
         exec_list *const f09DF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09DF->then_instructions;

            ir_expression *const r09E1 = bit_and(r09D1, body.constant(int(31)));
            body.emit(assign(r09DE, rshift(r09CF, r09E1), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09DF->else_instructions;

            body.emit(assign(r09DE, body.constant(0u), 0x01));


         body.instructions = f09DF_parent_instructions;
         body.emit(f09DF);

         /* END IF */

         body.emit(assign(r09D4, r09DE, 0x01));

         body.emit(assign(r09D5, body.constant(0u), 0x01));


      body.instructions = f09DA_parent_instructions;
      body.emit(f09DA);

      /* END IF */


   body.instructions = f09D8_parent_instructions;
   body.emit(f09D8);

   /* END IF */

   body.emit(assign(r09D3, r09D4, 0x01));

   body.emit(assign(r09D2, r09D5, 0x01));

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

   ir_variable *const r09E2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r09E2);
   ir_variable *const r09E3 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r09E4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r09E4);
   ir_variable *const r09E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r09E5);
   ir_variable *const r09E6 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r09E6, swizzle_x(r09E2), 0x01));

   body.emit(assign(r09E5, r09E6, 0x01));

   ir_variable *const r09E7 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r09E7, bit_and(swizzle_y(r09E2), body.constant(1048575u)), 0x01));

   body.emit(assign(r09E4, r09E7, 0x01));

   ir_variable *const r09E8 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r09E9 = rshift(swizzle_y(r09E2), body.constant(int(20)));
   ir_expression *const r09EA = bit_and(r09E9, body.constant(2047u));
   body.emit(assign(r09E8, expr(ir_unop_u2i, r09EA), 0x01));

   ir_variable *const r09EB = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r09EB, rshift(swizzle_y(r09E2), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r09ED = nequal(r09EB, body.constant(0u));
   ir_if *f09EC = new(mem_ctx) ir_if(operand(r09ED).val);
   exec_list *const f09EC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09EC->then_instructions;

      body.emit(assign(r09E3, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09EC->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09EF = equal(r09E8, body.constant(int(2047)));
      ir_expression *const r09F0 = bit_or(r09E7, swizzle_x(r09E2));
      ir_expression *const r09F1 = nequal(r09F0, body.constant(0u));
      ir_expression *const r09F2 = logic_and(r09EF, r09F1);
      ir_if *f09EE = new(mem_ctx) ir_if(operand(r09F2).val);
      exec_list *const f09EE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09EE->then_instructions;

         body.emit(assign(r09E3, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09EE->else_instructions;

         /* IF CONDITION */
         ir_expression *const r09F4 = nequal(r09E8, body.constant(int(0)));
         ir_if *f09F3 = new(mem_ctx) ir_if(operand(r09F4).val);
         exec_list *const f09F3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09F3->then_instructions;

            body.emit(assign(r09E4, bit_or(r09E7, body.constant(1048576u)), 0x01));


         body.instructions = f09F3_parent_instructions;
         body.emit(f09F3);

         /* END IF */

         ir_variable *const r09F5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r09F5, sub(body.constant(int(1063)), r09E8), 0x01));

         /* IF CONDITION */
         ir_expression *const r09F7 = less(body.constant(int(0)), r09F5);
         ir_if *f09F6 = new(mem_ctx) ir_if(operand(r09F7).val);
         exec_list *const f09F6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09F6->then_instructions;

            ir_variable *const r09F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r09F8);
            ir_variable *const r09F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r09F9);
            ir_variable *const r09FA = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r09FB = neg(r09F5);
            body.emit(assign(r09FA, bit_and(r09FB, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r09FD = equal(r09F5, body.constant(int(0)));
            ir_if *f09FC = new(mem_ctx) ir_if(operand(r09FD).val);
            exec_list *const f09FC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f09FC->then_instructions;

               body.emit(assign(r09F8, r09E6, 0x01));

               body.emit(assign(r09F9, r09E4, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f09FC->else_instructions;

               /* IF CONDITION */
               ir_expression *const r09FF = less(r09F5, body.constant(int(32)));
               ir_if *f09FE = new(mem_ctx) ir_if(operand(r09FF).val);
               exec_list *const f09FE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09FE->then_instructions;

                  ir_expression *const r0A00 = lshift(r09E4, r09FA);
                  ir_expression *const r0A01 = rshift(swizzle_x(r09E2), r09F5);
                  ir_expression *const r0A02 = bit_or(r0A00, r0A01);
                  ir_expression *const r0A03 = lshift(swizzle_x(r09E2), r09FA);
                  ir_expression *const r0A04 = nequal(r0A03, body.constant(0u));
                  ir_expression *const r0A05 = expr(ir_unop_b2i, r0A04);
                  ir_expression *const r0A06 = expr(ir_unop_i2u, r0A05);
                  body.emit(assign(r09F8, bit_or(r0A02, r0A06), 0x01));

                  body.emit(assign(r09F9, rshift(r09E4, r09F5), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f09FE->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A08 = equal(r09F5, body.constant(int(32)));
                  ir_if *f0A07 = new(mem_ctx) ir_if(operand(r0A08).val);
                  exec_list *const f0A07_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A07->then_instructions;

                     ir_expression *const r0A09 = nequal(swizzle_x(r09E2), body.constant(0u));
                     ir_expression *const r0A0A = expr(ir_unop_b2i, r0A09);
                     ir_expression *const r0A0B = expr(ir_unop_i2u, r0A0A);
                     body.emit(assign(r09F8, bit_or(r09E4, r0A0B), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A07->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0A0D = less(r09F5, body.constant(int(64)));
                     ir_if *f0A0C = new(mem_ctx) ir_if(operand(r0A0D).val);
                     exec_list *const f0A0C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0A0C->then_instructions;

                        ir_expression *const r0A0E = bit_and(r09F5, body.constant(int(31)));
                        ir_expression *const r0A0F = rshift(r09E4, r0A0E);
                        ir_expression *const r0A10 = lshift(r09E4, r09FA);
                        ir_expression *const r0A11 = bit_or(r0A10, swizzle_x(r09E2));
                        ir_expression *const r0A12 = nequal(r0A11, body.constant(0u));
                        ir_expression *const r0A13 = expr(ir_unop_b2i, r0A12);
                        ir_expression *const r0A14 = expr(ir_unop_i2u, r0A13);
                        body.emit(assign(r09F8, bit_or(r0A0F, r0A14), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0A0C->else_instructions;

                        ir_expression *const r0A15 = bit_or(r09E4, swizzle_x(r09E2));
                        ir_expression *const r0A16 = nequal(r0A15, body.constant(0u));
                        ir_expression *const r0A17 = expr(ir_unop_b2i, r0A16);
                        body.emit(assign(r09F8, expr(ir_unop_i2u, r0A17), 0x01));


                     body.instructions = f0A0C_parent_instructions;
                     body.emit(f0A0C);

                     /* END IF */


                  body.instructions = f0A07_parent_instructions;
                  body.emit(f0A07);

                  /* END IF */

                  body.emit(assign(r09F9, body.constant(0u), 0x01));


               body.instructions = f09FE_parent_instructions;
               body.emit(f09FE);

               /* END IF */


            body.instructions = f09FC_parent_instructions;
            body.emit(f09FC);

            /* END IF */

            body.emit(assign(r09E4, r09F9, 0x01));

            body.emit(assign(r09E5, r09F8, 0x01));


         body.instructions = f09F6_parent_instructions;
         body.emit(f09F6);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A19 = bit_and(r09E4, body.constant(4294963200u));
         ir_expression *const r0A1A = nequal(r0A19, body.constant(0u));
         ir_if *f0A18 = new(mem_ctx) ir_if(operand(r0A1A).val);
         exec_list *const f0A18_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A18->then_instructions;

            ir_variable *const r0A1B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A1D = nequal(r09EB, body.constant(0u));
            ir_if *f0A1C = new(mem_ctx) ir_if(operand(r0A1D).val);
            exec_list *const f0A1C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A1C->then_instructions;

               body.emit(assign(r0A1B, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A1C->else_instructions;

               body.emit(assign(r0A1B, body.constant(4294967295u), 0x01));


            body.instructions = f0A1C_parent_instructions;
            body.emit(f0A1C);

            /* END IF */

            body.emit(assign(r09E3, r0A1B, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A18->else_instructions;

            ir_variable *const r0A1E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0A1E);
            ir_variable *const r0A1F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0A1F);
            ir_expression *const r0A20 = lshift(r09E4, body.constant(int(20)));
            ir_expression *const r0A21 = rshift(r09E5, body.constant(int(12)));
            body.emit(assign(r0A1E, bit_or(r0A20, r0A21), 0x01));

            body.emit(assign(r0A1F, rshift(r09E4, body.constant(int(12))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A23 = nequal(r09EB, body.constant(0u));
            ir_expression *const r0A24 = nequal(r0A1E, body.constant(0u));
            ir_expression *const r0A25 = logic_and(r0A23, r0A24);
            ir_if *f0A22 = new(mem_ctx) ir_if(operand(r0A25).val);
            exec_list *const f0A22_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A22->then_instructions;

               ir_variable *const r0A26 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0A28 = nequal(r09EB, body.constant(0u));
               ir_if *f0A27 = new(mem_ctx) ir_if(operand(r0A28).val);
               exec_list *const f0A27_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A27->then_instructions;

                  body.emit(assign(r0A26, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A27->else_instructions;

                  body.emit(assign(r0A26, body.constant(4294967295u), 0x01));


               body.instructions = f0A27_parent_instructions;
               body.emit(f0A27);

               /* END IF */

               body.emit(assign(r09E3, r0A26, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A22->else_instructions;

               body.emit(assign(r09E3, r0A1E, 0x01));


            body.instructions = f0A22_parent_instructions;
            body.emit(f0A22);

            /* END IF */


         body.instructions = f0A18_parent_instructions;
         body.emit(f0A18);

         /* END IF */


      body.instructions = f09EE_parent_instructions;
      body.emit(f09EE);

      /* END IF */


   body.instructions = f09EC_parent_instructions;
   body.emit(f09EC);

   /* END IF */

   body.emit(ret(r09E3));

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

   ir_variable *const r0A29 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A29);
   ir_variable *const r0A2A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A2B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0A2B);
   ir_variable *const r0A2C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0A2C);
   /* IF CONDITION */
   ir_expression *const r0A2E = equal(r0A29, body.constant(0u));
   ir_if *f0A2D = new(mem_ctx) ir_if(operand(r0A2E).val);
   exec_list *const f0A2D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A2D->then_instructions;

      body.emit(assign(r0A2A, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A2D->else_instructions;

      ir_variable *const r0A2F = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0A2F, r0A29, 0x01));

      ir_variable *const r0A30 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0A31 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0A31);
      /* IF CONDITION */
      ir_expression *const r0A33 = equal(r0A29, body.constant(0u));
      ir_if *f0A32 = new(mem_ctx) ir_if(operand(r0A33).val);
      exec_list *const f0A32_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A32->then_instructions;

         body.emit(assign(r0A30, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A32->else_instructions;

         body.emit(assign(r0A31, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A35 = bit_and(r0A29, body.constant(4294901760u));
         ir_expression *const r0A36 = equal(r0A35, body.constant(0u));
         ir_if *f0A34 = new(mem_ctx) ir_if(operand(r0A36).val);
         exec_list *const f0A34_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A34->then_instructions;

            body.emit(assign(r0A31, body.constant(int(16)), 0x01));

            body.emit(assign(r0A2F, lshift(r0A29, body.constant(int(16))), 0x01));


         body.instructions = f0A34_parent_instructions;
         body.emit(f0A34);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A38 = bit_and(r0A2F, body.constant(4278190080u));
         ir_expression *const r0A39 = equal(r0A38, body.constant(0u));
         ir_if *f0A37 = new(mem_ctx) ir_if(operand(r0A39).val);
         exec_list *const f0A37_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A37->then_instructions;

            body.emit(assign(r0A31, add(r0A31, body.constant(int(8))), 0x01));

            body.emit(assign(r0A2F, lshift(r0A2F, body.constant(int(8))), 0x01));


         body.instructions = f0A37_parent_instructions;
         body.emit(f0A37);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A3B = bit_and(r0A2F, body.constant(4026531840u));
         ir_expression *const r0A3C = equal(r0A3B, body.constant(0u));
         ir_if *f0A3A = new(mem_ctx) ir_if(operand(r0A3C).val);
         exec_list *const f0A3A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A3A->then_instructions;

            body.emit(assign(r0A31, add(r0A31, body.constant(int(4))), 0x01));

            body.emit(assign(r0A2F, lshift(r0A2F, body.constant(int(4))), 0x01));


         body.instructions = f0A3A_parent_instructions;
         body.emit(f0A3A);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A3E = bit_and(r0A2F, body.constant(3221225472u));
         ir_expression *const r0A3F = equal(r0A3E, body.constant(0u));
         ir_if *f0A3D = new(mem_ctx) ir_if(operand(r0A3F).val);
         exec_list *const f0A3D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A3D->then_instructions;

            body.emit(assign(r0A31, add(r0A31, body.constant(int(2))), 0x01));

            body.emit(assign(r0A2F, lshift(r0A2F, body.constant(int(2))), 0x01));


         body.instructions = f0A3D_parent_instructions;
         body.emit(f0A3D);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A41 = bit_and(r0A2F, body.constant(2147483648u));
         ir_expression *const r0A42 = equal(r0A41, body.constant(0u));
         ir_if *f0A40 = new(mem_ctx) ir_if(operand(r0A42).val);
         exec_list *const f0A40_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A40->then_instructions;

            body.emit(assign(r0A31, add(r0A31, body.constant(int(1))), 0x01));


         body.instructions = f0A40_parent_instructions;
         body.emit(f0A40);

         /* END IF */

         body.emit(assign(r0A30, r0A31, 0x01));


      body.instructions = f0A32_parent_instructions;
      body.emit(f0A32);

      /* END IF */

      ir_variable *const r0A43 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0A43, add(r0A30, body.constant(int(21))), 0x01));

      body.emit(assign(r0A2C, body.constant(0u), 0x01));

      body.emit(assign(r0A2B, body.constant(0u), 0x01));

      ir_variable *const r0A44 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0A45 = neg(r0A43);
      body.emit(assign(r0A44, bit_and(r0A45, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A47 = equal(r0A43, body.constant(int(0)));
      ir_if *f0A46 = new(mem_ctx) ir_if(operand(r0A47).val);
      exec_list *const f0A46_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A46->then_instructions;

         body.emit(assign(r0A2C, body.constant(0u), 0x01));

         body.emit(assign(r0A2B, r0A29, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A46->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A49 = less(r0A43, body.constant(int(32)));
         ir_if *f0A48 = new(mem_ctx) ir_if(operand(r0A49).val);
         exec_list *const f0A48_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A48->then_instructions;

            body.emit(assign(r0A2C, rshift(r0A29, r0A44), 0x01));

            body.emit(assign(r0A2B, lshift(r0A29, r0A43), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A48->else_instructions;

            ir_variable *const r0A4A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A4C = less(r0A43, body.constant(int(64)));
            ir_if *f0A4B = new(mem_ctx) ir_if(operand(r0A4C).val);
            exec_list *const f0A4B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A4B->then_instructions;

               ir_expression *const r0A4D = add(r0A43, body.constant(int(-32)));
               body.emit(assign(r0A4A, lshift(r0A29, r0A4D), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A4B->else_instructions;

               body.emit(assign(r0A4A, body.constant(0u), 0x01));


            body.instructions = f0A4B_parent_instructions;
            body.emit(f0A4B);

            /* END IF */

            body.emit(assign(r0A2C, r0A4A, 0x01));

            body.emit(assign(r0A2B, body.constant(0u), 0x01));


         body.instructions = f0A48_parent_instructions;
         body.emit(f0A48);

         /* END IF */


      body.instructions = f0A46_parent_instructions;
      body.emit(f0A46);

      /* END IF */

      ir_variable *const r0A4E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A4E);
      ir_expression *const r0A4F = sub(body.constant(int(1074)), r0A43);
      ir_expression *const r0A50 = expr(ir_unop_i2u, r0A4F);
      ir_expression *const r0A51 = lshift(r0A50, body.constant(int(20)));
      body.emit(assign(r0A4E, add(r0A51, r0A2C), 0x02));

      body.emit(assign(r0A4E, r0A2B, 0x01));

      body.emit(assign(r0A2A, r0A4E, 0x03));


   body.instructions = f0A2D_parent_instructions;
   body.emit(f0A2D);

   /* END IF */

   body.emit(ret(r0A2A));

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

   ir_variable *const r0A52 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A52);
   ir_variable *const r0A53 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A53, body.constant(true), 0x01));

   ir_variable *const r0A54 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0A55 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0A55);
   ir_variable *const r0A56 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A56);
   ir_variable *const r0A57 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A57);
   ir_variable *const r0A58 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A58, bit_and(swizzle_y(r0A52), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A57, r0A58, 0x01));

   ir_variable *const r0A59 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A5A = rshift(swizzle_y(r0A52), body.constant(int(20)));
   ir_expression *const r0A5B = bit_and(r0A5A, body.constant(2047u));
   body.emit(assign(r0A59, expr(ir_unop_u2i, r0A5B), 0x01));

   body.emit(assign(r0A56, rshift(swizzle_y(r0A52), body.constant(int(31))), 0x01));

   body.emit(assign(r0A55, body.constant(0u), 0x01));

   ir_variable *const r0A5C = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0A5C, add(r0A59, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A5E = gequal(r0A5C, body.constant(int(0)));
   ir_if *f0A5D = new(mem_ctx) ir_if(operand(r0A5E).val);
   exec_list *const f0A5D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A5D->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A60 = less(body.constant(int(1054)), r0A59);
      ir_if *f0A5F = new(mem_ctx) ir_if(operand(r0A60).val);
      exec_list *const f0A5F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A5F->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A62 = equal(r0A59, body.constant(int(2047)));
         ir_expression *const r0A63 = bit_or(r0A58, swizzle_x(r0A52));
         ir_expression *const r0A64 = expr(ir_unop_u2i, r0A63);
         ir_expression *const r0A65 = expr(ir_unop_i2b, r0A64);
         ir_expression *const r0A66 = logic_and(r0A62, r0A65);
         ir_if *f0A61 = new(mem_ctx) ir_if(operand(r0A66).val);
         exec_list *const f0A61_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A61->then_instructions;

            body.emit(assign(r0A56, body.constant(0u), 0x01));


         body.instructions = f0A61_parent_instructions;
         body.emit(f0A61);

         /* END IF */

         ir_variable *const r0A67 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A69 = expr(ir_unop_u2i, r0A56);
         ir_expression *const r0A6A = expr(ir_unop_i2b, r0A69);
         ir_if *f0A68 = new(mem_ctx) ir_if(operand(r0A6A).val);
         exec_list *const f0A68_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A68->then_instructions;

            body.emit(assign(r0A67, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A68->else_instructions;

            body.emit(assign(r0A67, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A68_parent_instructions;
         body.emit(f0A68);

         /* END IF */

         body.emit(assign(r0A54, r0A67, 0x01));

         body.emit(assign(r0A53, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A5F->else_instructions;

         ir_variable *const r0A6B = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r0A6B, bit_or(r0A58, body.constant(1048576u)), 0x01));

         ir_variable *const r0A6C = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0A6C, lshift(swizzle_x(r0A52), r0A5C), 0x01));

         ir_variable *const r0A6D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A6F = equal(r0A5C, body.constant(int(0)));
         ir_if *f0A6E = new(mem_ctx) ir_if(operand(r0A6F).val);
         exec_list *const f0A6E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A6E->then_instructions;

            body.emit(assign(r0A6D, r0A6B, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A6E->else_instructions;

            ir_expression *const r0A70 = lshift(r0A6B, r0A5C);
            ir_expression *const r0A71 = neg(r0A5C);
            ir_expression *const r0A72 = bit_and(r0A71, body.constant(int(31)));
            ir_expression *const r0A73 = rshift(swizzle_x(r0A52), r0A72);
            body.emit(assign(r0A6D, bit_or(r0A70, r0A73), 0x01));


         body.instructions = f0A6E_parent_instructions;
         body.emit(f0A6E);

         /* END IF */

         body.emit(assign(r0A55, r0A6D, 0x01));


      body.instructions = f0A5F_parent_instructions;
      body.emit(f0A5F);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A5D->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A75 = less(r0A59, body.constant(int(1023)));
      ir_if *f0A74 = new(mem_ctx) ir_if(operand(r0A75).val);
      exec_list *const f0A74_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A74->then_instructions;

         body.emit(assign(r0A54, body.constant(int(0)), 0x01));

         body.emit(assign(r0A53, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A74->else_instructions;

         body.emit(assign(r0A57, bit_or(r0A58, body.constant(1048576u)), 0x01));

         ir_expression *const r0A76 = neg(r0A5C);
         body.emit(assign(r0A55, rshift(r0A57, r0A76), 0x01));


      body.instructions = f0A74_parent_instructions;
      body.emit(f0A74);

      /* END IF */


   body.instructions = f0A5D_parent_instructions;
   body.emit(f0A5D);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0A77 = new(mem_ctx) ir_if(operand(r0A53).val);
   exec_list *const f0A77_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A77->then_instructions;

      ir_variable *const r0A78 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A7A = nequal(r0A56, body.constant(0u));
      ir_if *f0A79 = new(mem_ctx) ir_if(operand(r0A7A).val);
      exec_list *const f0A79_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A79->then_instructions;

         ir_expression *const r0A7B = expr(ir_unop_u2i, r0A55);
         body.emit(assign(r0A78, neg(r0A7B), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A79->else_instructions;

         body.emit(assign(r0A78, expr(ir_unop_u2i, r0A55), 0x01));


      body.instructions = f0A79_parent_instructions;
      body.emit(f0A79);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0A7D = less(r0A78, body.constant(int(0)));
      ir_expression *const r0A7E = expr(ir_unop_b2i, r0A7D);
      ir_expression *const r0A7F = expr(ir_unop_i2u, r0A7E);
      ir_expression *const r0A80 = bit_xor(r0A56, r0A7F);
      ir_expression *const r0A81 = expr(ir_unop_u2i, r0A80);
      ir_expression *const r0A82 = expr(ir_unop_i2b, r0A81);
      ir_expression *const r0A83 = expr(ir_unop_i2b, r0A78);
      ir_expression *const r0A84 = logic_and(r0A82, r0A83);
      ir_if *f0A7C = new(mem_ctx) ir_if(operand(r0A84).val);
      exec_list *const f0A7C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A7C->then_instructions;

         ir_variable *const r0A85 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A87 = expr(ir_unop_u2i, r0A56);
         ir_expression *const r0A88 = expr(ir_unop_i2b, r0A87);
         ir_if *f0A86 = new(mem_ctx) ir_if(operand(r0A88).val);
         exec_list *const f0A86_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A86->then_instructions;

            body.emit(assign(r0A85, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A86->else_instructions;

            body.emit(assign(r0A85, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A86_parent_instructions;
         body.emit(f0A86);

         /* END IF */

         body.emit(assign(r0A54, r0A85, 0x01));

         body.emit(assign(r0A53, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A7C->else_instructions;

         body.emit(assign(r0A54, r0A78, 0x01));

         body.emit(assign(r0A53, body.constant(false), 0x01));


      body.instructions = f0A7C_parent_instructions;
      body.emit(f0A7C);

      /* END IF */


   body.instructions = f0A77_parent_instructions;
   body.emit(f0A77);

   /* END IF */

   body.emit(ret(r0A54));

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

   ir_variable *const r0A89 = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A89);
   ir_variable *const r0A8A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A8B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0A8B);
   ir_variable *const r0A8C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0A8C);
   ir_variable *const r0A8D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0A8D);
   body.emit(assign(r0A8D, body.constant(0u), 0x01));

   body.emit(assign(r0A8C, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A8F = equal(r0A89, body.constant(int(0)));
   ir_if *f0A8E = new(mem_ctx) ir_if(operand(r0A8F).val);
   exec_list *const f0A8E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A8E->then_instructions;

      ir_variable *const r0A90 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A90);
      body.emit(assign(r0A90, body.constant(0u), 0x02));

      body.emit(assign(r0A90, body.constant(0u), 0x01));

      body.emit(assign(r0A8A, r0A90, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A8E->else_instructions;

      ir_expression *const r0A91 = less(r0A89, body.constant(int(0)));
      ir_expression *const r0A92 = expr(ir_unop_b2i, r0A91);
      body.emit(assign(r0A8B, expr(ir_unop_i2u, r0A92), 0x01));

      ir_variable *const r0A93 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A95 = less(r0A89, body.constant(int(0)));
      ir_if *f0A94 = new(mem_ctx) ir_if(operand(r0A95).val);
      exec_list *const f0A94_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A94->then_instructions;

         ir_expression *const r0A96 = neg(r0A89);
         body.emit(assign(r0A93, expr(ir_unop_i2u, r0A96), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A94->else_instructions;

         body.emit(assign(r0A93, expr(ir_unop_i2u, r0A89), 0x01));


      body.instructions = f0A94_parent_instructions;
      body.emit(f0A94);

      /* END IF */

      ir_variable *const r0A97 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0A97, r0A93, 0x01));

      ir_variable *const r0A98 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0A99 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0A99);
      /* IF CONDITION */
      ir_expression *const r0A9B = equal(r0A93, body.constant(0u));
      ir_if *f0A9A = new(mem_ctx) ir_if(operand(r0A9B).val);
      exec_list *const f0A9A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A9A->then_instructions;

         body.emit(assign(r0A98, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A9A->else_instructions;

         body.emit(assign(r0A99, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A9D = bit_and(r0A93, body.constant(4294901760u));
         ir_expression *const r0A9E = equal(r0A9D, body.constant(0u));
         ir_if *f0A9C = new(mem_ctx) ir_if(operand(r0A9E).val);
         exec_list *const f0A9C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A9C->then_instructions;

            body.emit(assign(r0A99, body.constant(int(16)), 0x01));

            body.emit(assign(r0A97, lshift(r0A93, body.constant(int(16))), 0x01));


         body.instructions = f0A9C_parent_instructions;
         body.emit(f0A9C);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AA0 = bit_and(r0A97, body.constant(4278190080u));
         ir_expression *const r0AA1 = equal(r0AA0, body.constant(0u));
         ir_if *f0A9F = new(mem_ctx) ir_if(operand(r0AA1).val);
         exec_list *const f0A9F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A9F->then_instructions;

            body.emit(assign(r0A99, add(r0A99, body.constant(int(8))), 0x01));

            body.emit(assign(r0A97, lshift(r0A97, body.constant(int(8))), 0x01));


         body.instructions = f0A9F_parent_instructions;
         body.emit(f0A9F);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AA3 = bit_and(r0A97, body.constant(4026531840u));
         ir_expression *const r0AA4 = equal(r0AA3, body.constant(0u));
         ir_if *f0AA2 = new(mem_ctx) ir_if(operand(r0AA4).val);
         exec_list *const f0AA2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA2->then_instructions;

            body.emit(assign(r0A99, add(r0A99, body.constant(int(4))), 0x01));

            body.emit(assign(r0A97, lshift(r0A97, body.constant(int(4))), 0x01));


         body.instructions = f0AA2_parent_instructions;
         body.emit(f0AA2);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AA6 = bit_and(r0A97, body.constant(3221225472u));
         ir_expression *const r0AA7 = equal(r0AA6, body.constant(0u));
         ir_if *f0AA5 = new(mem_ctx) ir_if(operand(r0AA7).val);
         exec_list *const f0AA5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA5->then_instructions;

            body.emit(assign(r0A99, add(r0A99, body.constant(int(2))), 0x01));

            body.emit(assign(r0A97, lshift(r0A97, body.constant(int(2))), 0x01));


         body.instructions = f0AA5_parent_instructions;
         body.emit(f0AA5);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AA9 = bit_and(r0A97, body.constant(2147483648u));
         ir_expression *const r0AAA = equal(r0AA9, body.constant(0u));
         ir_if *f0AA8 = new(mem_ctx) ir_if(operand(r0AAA).val);
         exec_list *const f0AA8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA8->then_instructions;

            body.emit(assign(r0A99, add(r0A99, body.constant(int(1))), 0x01));


         body.instructions = f0AA8_parent_instructions;
         body.emit(f0AA8);

         /* END IF */

         body.emit(assign(r0A98, r0A99, 0x01));


      body.instructions = f0A9A_parent_instructions;
      body.emit(f0A9A);

      /* END IF */

      ir_variable *const r0AAB = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0AAB, add(r0A98, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0AAD = gequal(r0AAB, body.constant(int(0)));
      ir_if *f0AAC = new(mem_ctx) ir_if(operand(r0AAD).val);
      exec_list *const f0AAC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AAC->then_instructions;

         body.emit(assign(r0A8D, lshift(r0A93, r0AAB), 0x01));

         body.emit(assign(r0A8C, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AAC->else_instructions;

         ir_variable *const r0AAE = body.make_temp(glsl_type::uint_type, "a1");
         body.emit(assign(r0AAE, body.constant(0u), 0x01));

         ir_variable *const r0AAF = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r0AAF, neg(r0AAB), 0x01));

         ir_variable *const r0AB0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
         body.emit(r0AB0);
         ir_variable *const r0AB1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
         body.emit(r0AB1);
         ir_variable *const r0AB2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         ir_expression *const r0AB3 = neg(r0AAF);
         body.emit(assign(r0AB2, bit_and(r0AB3, body.constant(int(31))), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AB5 = equal(r0AAF, body.constant(int(0)));
         ir_if *f0AB4 = new(mem_ctx) ir_if(operand(r0AB5).val);
         exec_list *const f0AB4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AB4->then_instructions;

            body.emit(assign(r0AB0, body.constant(0u), 0x01));

            body.emit(assign(r0AB1, r0A93, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AB4->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0AB7 = less(r0AAF, body.constant(int(32)));
            ir_if *f0AB6 = new(mem_ctx) ir_if(operand(r0AB7).val);
            exec_list *const f0AB6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AB6->then_instructions;

               ir_expression *const r0AB8 = lshift(r0A93, r0AB2);
               body.emit(assign(r0AB0, bit_or(r0AB8, body.constant(0u)), 0x01));

               body.emit(assign(r0AB1, rshift(r0A93, r0AAF), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0AB6->else_instructions;

               ir_variable *const r0AB9 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0ABB = less(r0AAF, body.constant(int(64)));
               ir_if *f0ABA = new(mem_ctx) ir_if(operand(r0ABB).val);
               exec_list *const f0ABA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0ABA->then_instructions;

                  ir_expression *const r0ABC = bit_and(r0AAF, body.constant(int(31)));
                  body.emit(assign(r0AB9, rshift(r0A93, r0ABC), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0ABA->else_instructions;

                  body.emit(assign(r0AB9, body.constant(0u), 0x01));


               body.instructions = f0ABA_parent_instructions;
               body.emit(f0ABA);

               /* END IF */

               body.emit(assign(r0AB0, r0AB9, 0x01));

               body.emit(assign(r0AB1, body.constant(0u), 0x01));


            body.instructions = f0AB6_parent_instructions;
            body.emit(f0AB6);

            /* END IF */


         body.instructions = f0AB4_parent_instructions;
         body.emit(f0AB4);

         /* END IF */

         body.emit(assign(r0A8D, r0AB1, 0x01));

         body.emit(assign(r0A8C, r0AB0, 0x01));


      body.instructions = f0AAC_parent_instructions;
      body.emit(f0AAC);

      /* END IF */

      ir_variable *const r0ABD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0ABD);
      ir_expression *const r0ABE = lshift(r0A8B, body.constant(int(31)));
      ir_expression *const r0ABF = sub(body.constant(int(1042)), r0AAB);
      ir_expression *const r0AC0 = expr(ir_unop_i2u, r0ABF);
      ir_expression *const r0AC1 = lshift(r0AC0, body.constant(int(20)));
      ir_expression *const r0AC2 = add(r0ABE, r0AC1);
      body.emit(assign(r0ABD, add(r0AC2, r0A8D), 0x02));

      body.emit(assign(r0ABD, r0A8C, 0x01));

      body.emit(assign(r0A8A, r0ABD, 0x03));


   body.instructions = f0A8E_parent_instructions;
   body.emit(f0A8E);

   /* END IF */

   body.emit(ret(r0A8A));

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

   ir_variable *const r0AC3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AC3);
   ir_variable *const r0AC4 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AC4);
   ir_variable *const r0AC5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AC5);
   ir_variable *const r0AC6 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r0AC7 = lshift(r0AC3, body.constant(int(31)));
   ir_expression *const r0AC8 = expr(ir_unop_i2u, r0AC4);
   ir_expression *const r0AC9 = lshift(r0AC8, body.constant(int(23)));
   ir_expression *const r0ACA = add(r0AC7, r0AC9);
   ir_expression *const r0ACB = add(r0ACA, r0AC5);
   body.emit(assign(r0AC6, expr(ir_unop_bitcast_u2f, r0ACB), 0x01));

   body.emit(ret(r0AC6));

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

   ir_variable *const r0ACC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0ACC);
   ir_variable *const r0ACD = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0ACD);
   ir_variable *const r0ACE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0ACE);
   ir_variable *const r0ACF = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0ACF, body.constant(true), 0x01));

   ir_variable *const r0AD0 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0AD1 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0AD1);
   ir_expression *const r0AD2 = bit_and(r0ACE, body.constant(127u));
   body.emit(assign(r0AD1, expr(ir_unop_u2i, r0AD2), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AD4 = expr(ir_unop_i2u, r0ACD);
   ir_expression *const r0AD5 = gequal(r0AD4, body.constant(253u));
   ir_if *f0AD3 = new(mem_ctx) ir_if(operand(r0AD5).val);
   exec_list *const f0AD3_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AD3->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0AD7 = less(body.constant(int(253)), r0ACD);
      ir_expression *const r0AD8 = equal(r0ACD, body.constant(int(253)));
      ir_expression *const r0AD9 = expr(ir_unop_u2i, r0ACE);
      ir_expression *const r0ADA = less(r0AD9, body.constant(int(-64)));
      ir_expression *const r0ADB = logic_and(r0AD8, r0ADA);
      ir_expression *const r0ADC = logic_or(r0AD7, r0ADB);
      ir_if *f0AD6 = new(mem_ctx) ir_if(operand(r0ADC).val);
      exec_list *const f0AD6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AD6->then_instructions;

         ir_expression *const r0ADD = lshift(r0ACC, body.constant(int(31)));
         ir_expression *const r0ADE = add(r0ADD, body.constant(2139095040u));
         body.emit(assign(r0AD0, expr(ir_unop_bitcast_u2f, r0ADE), 0x01));

         body.emit(assign(r0ACF, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AD6->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0AE0 = less(r0ACD, body.constant(int(0)));
         ir_if *f0ADF = new(mem_ctx) ir_if(operand(r0AE0).val);
         exec_list *const f0ADF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ADF->then_instructions;

            ir_variable *const r0AE1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0AE1, neg(r0ACD), 0x01));

            /* IF CONDITION */
            ir_expression *const r0AE3 = less(r0AE1, body.constant(int(32)));
            ir_if *f0AE2 = new(mem_ctx) ir_if(operand(r0AE3).val);
            exec_list *const f0AE2_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AE2->then_instructions;

               ir_expression *const r0AE4 = rshift(r0ACE, r0AE1);
               ir_expression *const r0AE5 = neg(r0AE1);
               ir_expression *const r0AE6 = bit_and(r0AE5, body.constant(int(31)));
               ir_expression *const r0AE7 = lshift(r0ACE, r0AE6);
               ir_expression *const r0AE8 = nequal(r0AE7, body.constant(0u));
               ir_expression *const r0AE9 = expr(ir_unop_b2i, r0AE8);
               ir_expression *const r0AEA = expr(ir_unop_i2u, r0AE9);
               body.emit(assign(r0ACE, bit_or(r0AE4, r0AEA), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0AE2->else_instructions;

               ir_expression *const r0AEB = nequal(r0ACE, body.constant(0u));
               ir_expression *const r0AEC = expr(ir_unop_b2i, r0AEB);
               body.emit(assign(r0ACE, expr(ir_unop_i2u, r0AEC), 0x01));


            body.instructions = f0AE2_parent_instructions;
            body.emit(f0AE2);

            /* END IF */

            body.emit(assign(r0ACD, body.constant(int(0)), 0x01));

            ir_expression *const r0AED = expr(ir_unop_u2i, r0ACE);
            body.emit(assign(r0AD1, bit_and(r0AED, body.constant(int(127))), 0x01));


         body.instructions = f0ADF_parent_instructions;
         body.emit(f0ADF);

         /* END IF */


      body.instructions = f0AD6_parent_instructions;
      body.emit(f0AD6);

      /* END IF */


   body.instructions = f0AD3_parent_instructions;
   body.emit(f0AD3);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0AEE = new(mem_ctx) ir_if(operand(r0ACF).val);
   exec_list *const f0AEE_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AEE->then_instructions;

      ir_expression *const r0AEF = add(r0ACE, body.constant(64u));
      body.emit(assign(r0ACE, rshift(r0AEF, body.constant(int(7))), 0x01));

      ir_expression *const r0AF0 = bit_xor(r0AD1, body.constant(int(64)));
      ir_expression *const r0AF1 = equal(r0AF0, body.constant(int(0)));
      ir_expression *const r0AF2 = expr(ir_unop_b2i, r0AF1);
      ir_expression *const r0AF3 = expr(ir_unop_i2u, r0AF2);
      ir_expression *const r0AF4 = expr(ir_unop_bit_not, r0AF3);
      body.emit(assign(r0ACE, bit_and(r0ACE, r0AF4), 0x01));

      /* IF CONDITION */
      ir_expression *const r0AF6 = equal(r0ACE, body.constant(0u));
      ir_if *f0AF5 = new(mem_ctx) ir_if(operand(r0AF6).val);
      exec_list *const f0AF5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AF5->then_instructions;

         body.emit(assign(r0ACD, body.constant(int(0)), 0x01));


      body.instructions = f0AF5_parent_instructions;
      body.emit(f0AF5);

      /* END IF */

      ir_expression *const r0AF7 = lshift(r0ACC, body.constant(int(31)));
      ir_expression *const r0AF8 = expr(ir_unop_i2u, r0ACD);
      ir_expression *const r0AF9 = lshift(r0AF8, body.constant(int(23)));
      ir_expression *const r0AFA = add(r0AF7, r0AF9);
      ir_expression *const r0AFB = add(r0AFA, r0ACE);
      body.emit(assign(r0AD0, expr(ir_unop_bitcast_u2f, r0AFB), 0x01));

      body.emit(assign(r0ACF, body.constant(false), 0x01));


   body.instructions = f0AEE_parent_instructions;
   body.emit(f0AEE);

   /* END IF */

   body.emit(ret(r0AD0));

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

   ir_variable *const r0AFC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AFC);
   ir_variable *const r0AFD = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0AFE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0AFE);
   body.emit(assign(r0AFE, body.constant(0u), 0x01));

   ir_variable *const r0AFF = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0AFF, swizzle_x(r0AFC), 0x01));

   ir_variable *const r0B00 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B00, bit_and(swizzle_y(r0AFC), body.constant(1048575u)), 0x01));

   ir_variable *const r0B01 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B02 = rshift(swizzle_y(r0AFC), body.constant(int(20)));
   ir_expression *const r0B03 = bit_and(r0B02, body.constant(2047u));
   body.emit(assign(r0B01, expr(ir_unop_u2i, r0B03), 0x01));

   ir_variable *const r0B04 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B04, rshift(swizzle_y(r0AFC), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B06 = equal(r0B01, body.constant(int(2047)));
   ir_if *f0B05 = new(mem_ctx) ir_if(operand(r0B06).val);
   exec_list *const f0B05_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B05->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B08 = bit_or(r0B00, swizzle_x(r0AFC));
      ir_expression *const r0B09 = nequal(r0B08, body.constant(0u));
      ir_if *f0B07 = new(mem_ctx) ir_if(operand(r0B09).val);
      exec_list *const f0B07_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B07->then_instructions;

         ir_variable *const r0B0A = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0B0A, lshift(swizzle_x(r0AFC), body.constant(int(12))), 0x01));

         ir_variable *const r0B0B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         ir_expression *const r0B0C = lshift(swizzle_y(r0AFC), body.constant(int(12)));
         ir_expression *const r0B0D = rshift(swizzle_x(r0AFC), body.constant(int(20)));
         body.emit(assign(r0B0B, bit_or(r0B0C, r0B0D), 0x01));

         body.emit(assign(r0AFC, r0B0B, 0x02));

         body.emit(assign(r0AFC, r0B0A, 0x01));

         ir_expression *const r0B0E = lshift(r0B04, body.constant(int(31)));
         ir_expression *const r0B0F = bit_or(r0B0E, body.constant(2143289344u));
         ir_expression *const r0B10 = rshift(r0B0B, body.constant(int(9)));
         ir_expression *const r0B11 = bit_or(r0B0F, r0B10);
         body.emit(assign(r0AFD, expr(ir_unop_bitcast_u2f, r0B11), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B07->else_instructions;

         ir_expression *const r0B12 = lshift(r0B04, body.constant(int(31)));
         ir_expression *const r0B13 = add(r0B12, body.constant(2139095040u));
         body.emit(assign(r0AFD, expr(ir_unop_bitcast_u2f, r0B13), 0x01));


      body.instructions = f0B07_parent_instructions;
      body.emit(f0B07);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B05->else_instructions;

      ir_variable *const r0B14 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B14);
      ir_variable *const r0B15 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0B15);
      ir_expression *const r0B16 = lshift(r0B00, body.constant(int(10)));
      ir_expression *const r0B17 = rshift(r0AFF, body.constant(int(22)));
      ir_expression *const r0B18 = bit_or(r0B16, r0B17);
      ir_expression *const r0B19 = lshift(r0AFF, body.constant(int(10)));
      ir_expression *const r0B1A = nequal(r0B19, body.constant(0u));
      ir_expression *const r0B1B = expr(ir_unop_b2i, r0B1A);
      ir_expression *const r0B1C = expr(ir_unop_i2u, r0B1B);
      body.emit(assign(r0B14, bit_or(r0B18, r0B1C), 0x01));

      body.emit(assign(r0B15, rshift(r0B00, body.constant(int(22))), 0x01));

      body.emit(assign(r0AFE, r0B14, 0x01));

      /* IF CONDITION */
      ir_expression *const r0B1E = nequal(r0B01, body.constant(int(0)));
      ir_if *f0B1D = new(mem_ctx) ir_if(operand(r0B1E).val);
      exec_list *const f0B1D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B1D->then_instructions;

         body.emit(assign(r0AFE, bit_or(r0B14, body.constant(1073741824u)), 0x01));


      body.instructions = f0B1D_parent_instructions;
      body.emit(f0B1D);

      /* END IF */

      ir_variable *const r0B1F = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B1F, add(r0B01, body.constant(int(-897))), 0x01));

      ir_variable *const r0B20 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B20, r0AFE, 0x01));

      ir_variable *const r0B21 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B21, body.constant(true), 0x01));

      ir_variable *const r0B22 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B23 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B23);
      ir_expression *const r0B24 = bit_and(r0AFE, body.constant(127u));
      body.emit(assign(r0B23, expr(ir_unop_u2i, r0B24), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B26 = expr(ir_unop_i2u, r0B1F);
      ir_expression *const r0B27 = gequal(r0B26, body.constant(253u));
      ir_if *f0B25 = new(mem_ctx) ir_if(operand(r0B27).val);
      exec_list *const f0B25_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B25->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B29 = less(body.constant(int(253)), r0B1F);
         ir_expression *const r0B2A = equal(r0B1F, body.constant(int(253)));
         ir_expression *const r0B2B = expr(ir_unop_u2i, r0AFE);
         ir_expression *const r0B2C = less(r0B2B, body.constant(int(-64)));
         ir_expression *const r0B2D = logic_and(r0B2A, r0B2C);
         ir_expression *const r0B2E = logic_or(r0B29, r0B2D);
         ir_if *f0B28 = new(mem_ctx) ir_if(operand(r0B2E).val);
         exec_list *const f0B28_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B28->then_instructions;

            ir_expression *const r0B2F = lshift(r0B04, body.constant(int(31)));
            ir_expression *const r0B30 = add(r0B2F, body.constant(2139095040u));
            body.emit(assign(r0B22, expr(ir_unop_bitcast_u2f, r0B30), 0x01));

            body.emit(assign(r0B21, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B28->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0B32 = less(r0B1F, body.constant(int(0)));
            ir_if *f0B31 = new(mem_ctx) ir_if(operand(r0B32).val);
            exec_list *const f0B31_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B31->then_instructions;

               ir_variable *const r0B33 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0B33, neg(r0B1F), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B35 = less(r0B33, body.constant(int(32)));
               ir_if *f0B34 = new(mem_ctx) ir_if(operand(r0B35).val);
               exec_list *const f0B34_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B34->then_instructions;

                  ir_expression *const r0B36 = rshift(r0AFE, r0B33);
                  ir_expression *const r0B37 = neg(r0B33);
                  ir_expression *const r0B38 = bit_and(r0B37, body.constant(int(31)));
                  ir_expression *const r0B39 = lshift(r0AFE, r0B38);
                  ir_expression *const r0B3A = nequal(r0B39, body.constant(0u));
                  ir_expression *const r0B3B = expr(ir_unop_b2i, r0B3A);
                  ir_expression *const r0B3C = expr(ir_unop_i2u, r0B3B);
                  body.emit(assign(r0B20, bit_or(r0B36, r0B3C), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0B34->else_instructions;

                  ir_expression *const r0B3D = nequal(r0B20, body.constant(0u));
                  ir_expression *const r0B3E = expr(ir_unop_b2i, r0B3D);
                  body.emit(assign(r0B20, expr(ir_unop_i2u, r0B3E), 0x01));


               body.instructions = f0B34_parent_instructions;
               body.emit(f0B34);

               /* END IF */

               body.emit(assign(r0B1F, body.constant(int(0)), 0x01));

               ir_expression *const r0B3F = expr(ir_unop_u2i, r0B20);
               body.emit(assign(r0B23, bit_and(r0B3F, body.constant(int(127))), 0x01));


            body.instructions = f0B31_parent_instructions;
            body.emit(f0B31);

            /* END IF */


         body.instructions = f0B28_parent_instructions;
         body.emit(f0B28);

         /* END IF */


      body.instructions = f0B25_parent_instructions;
      body.emit(f0B25);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B40 = new(mem_ctx) ir_if(operand(r0B21).val);
      exec_list *const f0B40_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B40->then_instructions;

         ir_expression *const r0B41 = add(r0B20, body.constant(64u));
         body.emit(assign(r0B20, rshift(r0B41, body.constant(int(7))), 0x01));

         ir_expression *const r0B42 = bit_xor(r0B23, body.constant(int(64)));
         ir_expression *const r0B43 = equal(r0B42, body.constant(int(0)));
         ir_expression *const r0B44 = expr(ir_unop_b2i, r0B43);
         ir_expression *const r0B45 = expr(ir_unop_i2u, r0B44);
         ir_expression *const r0B46 = expr(ir_unop_bit_not, r0B45);
         body.emit(assign(r0B20, bit_and(r0B20, r0B46), 0x01));

         /* IF CONDITION */
         ir_expression *const r0B48 = equal(r0B20, body.constant(0u));
         ir_if *f0B47 = new(mem_ctx) ir_if(operand(r0B48).val);
         exec_list *const f0B47_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B47->then_instructions;

            body.emit(assign(r0B1F, body.constant(int(0)), 0x01));


         body.instructions = f0B47_parent_instructions;
         body.emit(f0B47);

         /* END IF */

         ir_expression *const r0B49 = lshift(r0B04, body.constant(int(31)));
         ir_expression *const r0B4A = expr(ir_unop_i2u, r0B1F);
         ir_expression *const r0B4B = lshift(r0B4A, body.constant(int(23)));
         ir_expression *const r0B4C = add(r0B49, r0B4B);
         ir_expression *const r0B4D = add(r0B4C, r0B20);
         body.emit(assign(r0B22, expr(ir_unop_bitcast_u2f, r0B4D), 0x01));

         body.emit(assign(r0B21, body.constant(false), 0x01));


      body.instructions = f0B40_parent_instructions;
      body.emit(f0B40);

      /* END IF */

      body.emit(assign(r0AFD, r0B22, 0x01));


   body.instructions = f0B05_parent_instructions;
   body.emit(f0B05);

   /* END IF */

   body.emit(ret(r0AFD));

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

   ir_variable *const r0B4E = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0B4E);
   ir_variable *const r0B4F = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B4F, body.constant(true), 0x01));

   ir_variable *const r0B50 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B51 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B51);
   ir_variable *const r0B52 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B52);
   ir_variable *const r0B53 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B53);
   ir_variable *const r0B54 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0B54, expr(ir_unop_bitcast_f2u, r0B4E), 0x01));

   ir_variable *const r0B55 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B55, bit_and(r0B54, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B53, r0B55, 0x01));

   ir_variable *const r0B56 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B57 = rshift(r0B54, body.constant(int(23)));
   ir_expression *const r0B58 = bit_and(r0B57, body.constant(255u));
   body.emit(assign(r0B56, expr(ir_unop_u2i, r0B58), 0x01));

   body.emit(assign(r0B52, r0B56, 0x01));

   body.emit(assign(r0B51, rshift(r0B54, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B5A = equal(r0B56, body.constant(int(255)));
   ir_if *f0B59 = new(mem_ctx) ir_if(operand(r0B5A).val);
   exec_list *const f0B59_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B59->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B5C = nequal(r0B55, body.constant(0u));
      ir_if *f0B5B = new(mem_ctx) ir_if(operand(r0B5C).val);
      exec_list *const f0B5B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B5B->then_instructions;

         ir_variable *const r0B5D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B5D, lshift(r0B54, body.constant(int(9))), 0x01));

         ir_variable *const r0B5E = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B5F = lshift(r0B5D, body.constant(int(20)));
         body.emit(assign(r0B5E, bit_or(r0B5F, body.constant(0u)), 0x01));

         ir_expression *const r0B60 = rshift(r0B5D, body.constant(int(12)));
         ir_expression *const r0B61 = lshift(r0B51, body.constant(int(31)));
         ir_expression *const r0B62 = bit_or(r0B61, body.constant(2146959360u));
         body.emit(assign(r0B5E, bit_or(r0B60, r0B62), 0x02));

         body.emit(assign(r0B50, r0B5E, 0x03));

         body.emit(assign(r0B4F, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B5B->else_instructions;

         ir_variable *const r0B63 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B63);
         ir_expression *const r0B64 = lshift(r0B51, body.constant(int(31)));
         body.emit(assign(r0B63, add(r0B64, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B63, body.constant(0u), 0x01));

         body.emit(assign(r0B50, r0B63, 0x03));

         body.emit(assign(r0B4F, body.constant(false), 0x01));


      body.instructions = f0B5B_parent_instructions;
      body.emit(f0B5B);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B59->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B66 = equal(r0B56, body.constant(int(0)));
      ir_if *f0B65 = new(mem_ctx) ir_if(operand(r0B66).val);
      exec_list *const f0B65_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B65->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B68 = equal(r0B55, body.constant(0u));
         ir_if *f0B67 = new(mem_ctx) ir_if(operand(r0B68).val);
         exec_list *const f0B67_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B67->then_instructions;

            ir_variable *const r0B69 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B69);
            body.emit(assign(r0B69, lshift(r0B51, body.constant(int(31))), 0x02));

            body.emit(assign(r0B69, body.constant(0u), 0x01));

            body.emit(assign(r0B50, r0B69, 0x03));

            body.emit(assign(r0B4F, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B67->else_instructions;

            ir_variable *const r0B6A = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0B6A, r0B55, 0x01));

            ir_variable *const r0B6B = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0B6C = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0B6C);
            /* IF CONDITION */
            ir_expression *const r0B6E = equal(r0B55, body.constant(0u));
            ir_if *f0B6D = new(mem_ctx) ir_if(operand(r0B6E).val);
            exec_list *const f0B6D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B6D->then_instructions;

               body.emit(assign(r0B6B, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0B6D->else_instructions;

               body.emit(assign(r0B6C, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B70 = bit_and(r0B55, body.constant(4294901760u));
               ir_expression *const r0B71 = equal(r0B70, body.constant(0u));
               ir_if *f0B6F = new(mem_ctx) ir_if(operand(r0B71).val);
               exec_list *const f0B6F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B6F->then_instructions;

                  body.emit(assign(r0B6C, body.constant(int(16)), 0x01));

                  body.emit(assign(r0B6A, lshift(r0B55, body.constant(int(16))), 0x01));


               body.instructions = f0B6F_parent_instructions;
               body.emit(f0B6F);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B73 = bit_and(r0B6A, body.constant(4278190080u));
               ir_expression *const r0B74 = equal(r0B73, body.constant(0u));
               ir_if *f0B72 = new(mem_ctx) ir_if(operand(r0B74).val);
               exec_list *const f0B72_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B72->then_instructions;

                  body.emit(assign(r0B6C, add(r0B6C, body.constant(int(8))), 0x01));

                  body.emit(assign(r0B6A, lshift(r0B6A, body.constant(int(8))), 0x01));


               body.instructions = f0B72_parent_instructions;
               body.emit(f0B72);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B76 = bit_and(r0B6A, body.constant(4026531840u));
               ir_expression *const r0B77 = equal(r0B76, body.constant(0u));
               ir_if *f0B75 = new(mem_ctx) ir_if(operand(r0B77).val);
               exec_list *const f0B75_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B75->then_instructions;

                  body.emit(assign(r0B6C, add(r0B6C, body.constant(int(4))), 0x01));

                  body.emit(assign(r0B6A, lshift(r0B6A, body.constant(int(4))), 0x01));


               body.instructions = f0B75_parent_instructions;
               body.emit(f0B75);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B79 = bit_and(r0B6A, body.constant(3221225472u));
               ir_expression *const r0B7A = equal(r0B79, body.constant(0u));
               ir_if *f0B78 = new(mem_ctx) ir_if(operand(r0B7A).val);
               exec_list *const f0B78_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B78->then_instructions;

                  body.emit(assign(r0B6C, add(r0B6C, body.constant(int(2))), 0x01));

                  body.emit(assign(r0B6A, lshift(r0B6A, body.constant(int(2))), 0x01));


               body.instructions = f0B78_parent_instructions;
               body.emit(f0B78);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B7C = bit_and(r0B6A, body.constant(2147483648u));
               ir_expression *const r0B7D = equal(r0B7C, body.constant(0u));
               ir_if *f0B7B = new(mem_ctx) ir_if(operand(r0B7D).val);
               exec_list *const f0B7B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B7B->then_instructions;

                  body.emit(assign(r0B6C, add(r0B6C, body.constant(int(1))), 0x01));


               body.instructions = f0B7B_parent_instructions;
               body.emit(f0B7B);

               /* END IF */

               body.emit(assign(r0B6B, r0B6C, 0x01));


            body.instructions = f0B6D_parent_instructions;
            body.emit(f0B6D);

            /* END IF */

            ir_variable *const r0B7E = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B7E, add(r0B6B, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B53, lshift(r0B55, r0B7E), 0x01));

            body.emit(assign(r0B52, sub(body.constant(int(1)), r0B7E), 0x01));

            body.emit(assign(r0B52, add(r0B52, body.constant(int(-1))), 0x01));


         body.instructions = f0B67_parent_instructions;
         body.emit(f0B67);

         /* END IF */


      body.instructions = f0B65_parent_instructions;
      body.emit(f0B65);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B7F = new(mem_ctx) ir_if(operand(r0B4F).val);
      exec_list *const f0B7F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B7F->then_instructions;

         ir_variable *const r0B80 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B80);
         ir_expression *const r0B81 = lshift(r0B51, body.constant(int(31)));
         ir_expression *const r0B82 = add(r0B52, body.constant(int(896)));
         ir_expression *const r0B83 = expr(ir_unop_i2u, r0B82);
         ir_expression *const r0B84 = lshift(r0B83, body.constant(int(20)));
         ir_expression *const r0B85 = add(r0B81, r0B84);
         ir_expression *const r0B86 = rshift(r0B53, body.constant(int(3)));
         body.emit(assign(r0B80, add(r0B85, r0B86), 0x02));

         ir_expression *const r0B87 = lshift(r0B53, body.constant(int(29)));
         body.emit(assign(r0B80, bit_or(r0B87, body.constant(0u)), 0x01));

         body.emit(assign(r0B50, r0B80, 0x03));

         body.emit(assign(r0B4F, body.constant(false), 0x01));


      body.instructions = f0B7F_parent_instructions;
      body.emit(f0B7F);

      /* END IF */


   body.instructions = f0B59_parent_instructions;
   body.emit(f0B59);

   /* END IF */

   body.emit(ret(r0B50));

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

   ir_variable *const r0B88 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0B88);
   ir_variable *const r0B89 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0B89);
   ir_variable *const r0B8A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0B8A);
   ir_variable *const r0B8B = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0B8B);
   ir_variable *const r0B8C = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0B8C);
   ir_variable *const r0B8D = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0B8D);
   ir_variable *const r0B8E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B8E);
   ir_variable *const r0B8F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B8F);
   ir_variable *const r0B90 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B90);
   ir_variable *const r0B91 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0B91);
   ir_variable *const r0B92 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0B92);
   ir_variable *const r0B93 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B93, add(r0B8A, r0B8D), 0x01));

   ir_variable *const r0B94 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0B95 = less(r0B93, r0B8A);
   ir_expression *const r0B96 = expr(ir_unop_b2i, r0B95);
   body.emit(assign(r0B94, expr(ir_unop_i2u, r0B96), 0x01));

   ir_variable *const r0B97 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B97, add(r0B89, r0B8C), 0x01));

   body.emit(assign(r0B92, add(r0B97, r0B94), 0x01));

   ir_expression *const r0B98 = add(r0B88, r0B8B);
   ir_expression *const r0B99 = less(r0B92, r0B94);
   ir_expression *const r0B9A = expr(ir_unop_b2i, r0B99);
   ir_expression *const r0B9B = expr(ir_unop_i2u, r0B9A);
   body.emit(assign(r0B91, add(r0B98, r0B9B), 0x01));

   ir_expression *const r0B9C = less(r0B97, r0B89);
   ir_expression *const r0B9D = expr(ir_unop_b2i, r0B9C);
   ir_expression *const r0B9E = expr(ir_unop_i2u, r0B9D);
   body.emit(assign(r0B91, add(r0B91, r0B9E), 0x01));

   body.emit(assign(r0B90, r0B93, 0x01));

   body.emit(assign(r0B8F, r0B92, 0x01));

   body.emit(assign(r0B8E, r0B91, 0x01));

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

   ir_variable *const r0B9F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0B9F);
   ir_variable *const r0BA0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BA0);
   ir_variable *const r0BA1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0BA1);
   ir_variable *const r0BA2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0BA2);
   ir_variable *const r0BA3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0BA3);
   ir_variable *const r0BA4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0BA4);
   ir_variable *const r0BA5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BA5);
   ir_variable *const r0BA6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BA6);
   ir_variable *const r0BA7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BA7);
   ir_variable *const r0BA8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0BA8);
   ir_variable *const r0BA9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0BAA = less(r0BA1, r0BA4);
   ir_expression *const r0BAB = expr(ir_unop_b2i, r0BAA);
   body.emit(assign(r0BA9, expr(ir_unop_i2u, r0BAB), 0x01));

   ir_variable *const r0BAC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BAC, sub(r0BA0, r0BA3), 0x01));

   ir_expression *const r0BAD = sub(r0B9F, r0BA2);
   ir_expression *const r0BAE = less(r0BAC, r0BA9);
   ir_expression *const r0BAF = expr(ir_unop_b2i, r0BAE);
   ir_expression *const r0BB0 = expr(ir_unop_i2u, r0BAF);
   body.emit(assign(r0BA8, sub(r0BAD, r0BB0), 0x01));

   ir_expression *const r0BB1 = less(r0BA0, r0BA3);
   ir_expression *const r0BB2 = expr(ir_unop_b2i, r0BB1);
   ir_expression *const r0BB3 = expr(ir_unop_i2u, r0BB2);
   body.emit(assign(r0BA8, sub(r0BA8, r0BB3), 0x01));

   body.emit(assign(r0BA7, sub(r0BA1, r0BA4), 0x01));

   body.emit(assign(r0BA6, sub(r0BAC, r0BA9), 0x01));

   body.emit(assign(r0BA5, r0BA8, 0x01));

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

   ir_variable *const r0BB4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BB4);
   ir_variable *const r0BB5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BB5);
   ir_variable *const r0BB6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0BB6);
   ir_variable *const r0BB7 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0BB8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0BB8);
   ir_variable *const r0BB9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0BB9);
   ir_variable *const r0BBA = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0BBA);
   ir_variable *const r0BBB = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0BBB);
   body.emit(assign(r0BBA, body.constant(0u), 0x01));

   body.emit(assign(r0BB9, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BBD = gequal(r0BB4, r0BB6);
   ir_if *f0BBC = new(mem_ctx) ir_if(operand(r0BBD).val);
   exec_list *const f0BBC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BBC->then_instructions;

      body.emit(assign(r0BB7, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BBC->else_instructions;

      body.emit(assign(r0BBB, rshift(r0BB6, body.constant(int(16))), 0x01));

      ir_variable *const r0BBE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BC0 = lshift(r0BBB, body.constant(int(16)));
      ir_expression *const r0BC1 = gequal(r0BB4, r0BC0);
      ir_if *f0BBF = new(mem_ctx) ir_if(operand(r0BC1).val);
      exec_list *const f0BBF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BBF->then_instructions;

         body.emit(assign(r0BBE, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BBF->else_instructions;

         ir_expression *const r0BC2 = expr(ir_binop_div, r0BB4, r0BBB);
         body.emit(assign(r0BBE, lshift(r0BC2, body.constant(int(16))), 0x01));


      body.instructions = f0BBF_parent_instructions;
      body.emit(f0BBF);

      /* END IF */

      body.emit(assign(r0BB8, r0BBE, 0x01));

      ir_variable *const r0BC3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0BC3);
      ir_variable *const r0BC4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0BC4);
      ir_variable *const r0BC5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BC5);
      ir_variable *const r0BC6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC6, bit_and(r0BB6, body.constant(65535u)), 0x01));

      ir_variable *const r0BC7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC7, rshift(r0BB6, body.constant(int(16))), 0x01));

      ir_variable *const r0BC8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC8, bit_and(r0BBE, body.constant(65535u)), 0x01));

      ir_variable *const r0BC9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC9, rshift(r0BBE, body.constant(int(16))), 0x01));

      ir_variable *const r0BCA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BCA, mul(r0BC7, r0BC8), 0x01));

      ir_expression *const r0BCB = mul(r0BC6, r0BC9);
      body.emit(assign(r0BC4, add(r0BCB, r0BCA), 0x01));

      ir_expression *const r0BCC = mul(r0BC7, r0BC9);
      ir_expression *const r0BCD = less(r0BC4, r0BCA);
      ir_expression *const r0BCE = expr(ir_unop_b2i, r0BCD);
      ir_expression *const r0BCF = expr(ir_unop_i2u, r0BCE);
      ir_expression *const r0BD0 = lshift(r0BCF, body.constant(int(16)));
      ir_expression *const r0BD1 = rshift(r0BC4, body.constant(int(16)));
      ir_expression *const r0BD2 = add(r0BD0, r0BD1);
      body.emit(assign(r0BC3, add(r0BCC, r0BD2), 0x01));

      body.emit(assign(r0BC4, lshift(r0BC4, body.constant(int(16))), 0x01));

      ir_expression *const r0BD3 = mul(r0BC6, r0BC8);
      body.emit(assign(r0BC5, add(r0BD3, r0BC4), 0x01));

      ir_expression *const r0BD4 = less(r0BC5, r0BC4);
      ir_expression *const r0BD5 = expr(ir_unop_b2i, r0BD4);
      ir_expression *const r0BD6 = expr(ir_unop_i2u, r0BD5);
      body.emit(assign(r0BC3, add(r0BC3, r0BD6), 0x01));

      ir_expression *const r0BD7 = sub(r0BB4, r0BC3);
      ir_expression *const r0BD8 = less(r0BB5, r0BC5);
      ir_expression *const r0BD9 = expr(ir_unop_b2i, r0BD8);
      ir_expression *const r0BDA = expr(ir_unop_i2u, r0BD9);
      body.emit(assign(r0BBA, sub(r0BD7, r0BDA), 0x01));

      body.emit(assign(r0BB9, sub(r0BB5, r0BC5), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0BDB = new(mem_ctx) ir_loop();
      exec_list *const f0BDB_parent_instructions = body.instructions;

         body.instructions = &f0BDB->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0BDD = expr(ir_unop_u2i, r0BBA);
         ir_expression *const r0BDE = gequal(r0BDD, body.constant(int(0)));
         ir_if *f0BDC = new(mem_ctx) ir_if(operand(r0BDE).val);
         exec_list *const f0BDC_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BDC->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0BDC_parent_instructions;
         body.emit(f0BDC);

         /* END IF */

         body.emit(assign(r0BB8, add(r0BB8, body.constant(4294901760u)), 0x01));

         ir_variable *const r0BDF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0BE0 = lshift(r0BB6, body.constant(int(16)));
         body.emit(assign(r0BDF, add(r0BB9, r0BE0), 0x01));

         ir_expression *const r0BE1 = add(r0BBA, r0BBB);
         ir_expression *const r0BE2 = less(r0BDF, r0BB9);
         ir_expression *const r0BE3 = expr(ir_unop_b2i, r0BE2);
         ir_expression *const r0BE4 = expr(ir_unop_i2u, r0BE3);
         body.emit(assign(r0BBA, add(r0BE1, r0BE4), 0x01));

         body.emit(assign(r0BB9, r0BDF, 0x01));

      /* LOOP END */

      body.instructions = f0BDB_parent_instructions;
      body.emit(f0BDB);

      ir_expression *const r0BE5 = lshift(r0BBA, body.constant(int(16)));
      ir_expression *const r0BE6 = rshift(r0BB9, body.constant(int(16)));
      body.emit(assign(r0BBA, bit_or(r0BE5, r0BE6), 0x01));

      ir_variable *const r0BE7 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BE9 = lshift(r0BBB, body.constant(int(16)));
      ir_expression *const r0BEA = gequal(r0BBA, r0BE9);
      ir_if *f0BE8 = new(mem_ctx) ir_if(operand(r0BEA).val);
      exec_list *const f0BE8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BE8->then_instructions;

         body.emit(assign(r0BE7, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BE8->else_instructions;

         body.emit(assign(r0BE7, expr(ir_binop_div, r0BBA, r0BBB), 0x01));


      body.instructions = f0BE8_parent_instructions;
      body.emit(f0BE8);

      /* END IF */

      body.emit(assign(r0BB8, bit_or(r0BB8, r0BE7), 0x01));

      body.emit(assign(r0BB7, r0BB8, 0x01));


   body.instructions = f0BBC_parent_instructions;
   body.emit(f0BBC);

   /* END IF */

   body.emit(ret(r0BB7));

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

   ir_variable *const r0BEB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BEB);
   ir_variable *const r0BEC = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0BED = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0BED);
   body.emit(assign(r0BED, body.constant(0u), 0x01));

   ir_variable *const r0BEE = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0BEE, bit_and(swizzle_y(r0BEB), body.constant(1048575u)), 0x01));

   ir_variable *const r0BEF = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0BF0 = rshift(swizzle_y(r0BEB), body.constant(int(20)));
   ir_expression *const r0BF1 = bit_and(r0BF0, body.constant(2047u));
   body.emit(assign(r0BEF, expr(ir_unop_u2i, r0BF1), 0x01));

   ir_variable *const r0BF2 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0BF2, rshift(swizzle_y(r0BEB), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BF4 = equal(r0BEF, body.constant(int(2047)));
   ir_if *f0BF3 = new(mem_ctx) ir_if(operand(r0BF4).val);
   exec_list *const f0BF3_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BF3->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0BF6 = bit_or(r0BEE, swizzle_x(r0BEB));
      ir_expression *const r0BF7 = nequal(r0BF6, body.constant(0u));
      ir_if *f0BF5 = new(mem_ctx) ir_if(operand(r0BF7).val);
      exec_list *const f0BF5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BF5->then_instructions;

         ir_variable *const r0BF8 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0BF8, lshift(swizzle_x(r0BEB), body.constant(int(12))), 0x01));

         ir_expression *const r0BF9 = lshift(r0BF2, body.constant(int(31)));
         ir_expression *const r0BFA = bit_or(r0BF9, body.constant(2143289344u));
         ir_expression *const r0BFB = lshift(swizzle_y(r0BEB), body.constant(int(12)));
         ir_expression *const r0BFC = rshift(swizzle_x(r0BEB), body.constant(int(20)));
         ir_expression *const r0BFD = bit_or(r0BFB, r0BFC);
         ir_expression *const r0BFE = rshift(r0BFD, body.constant(int(9)));
         ir_expression *const r0BFF = bit_or(r0BFA, r0BFE);
         body.emit(assign(r0BEC, expr(ir_unop_bitcast_u2f, r0BFF), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BF5->else_instructions;

         ir_expression *const r0C00 = lshift(r0BF2, body.constant(int(31)));
         ir_expression *const r0C01 = add(r0C00, body.constant(2139095040u));
         body.emit(assign(r0BEC, expr(ir_unop_bitcast_u2f, r0C01), 0x01));


      body.instructions = f0BF5_parent_instructions;
      body.emit(f0BF5);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BF3->else_instructions;

      ir_variable *const r0C02 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0C02);
      ir_variable *const r0C03 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0C03);
      ir_expression *const r0C04 = lshift(r0BEE, body.constant(int(10)));
      ir_expression *const r0C05 = rshift(swizzle_x(r0BEB), body.constant(int(22)));
      ir_expression *const r0C06 = bit_or(r0C04, r0C05);
      ir_expression *const r0C07 = lshift(swizzle_x(r0BEB), body.constant(int(10)));
      ir_expression *const r0C08 = nequal(r0C07, body.constant(0u));
      ir_expression *const r0C09 = expr(ir_unop_b2i, r0C08);
      ir_expression *const r0C0A = expr(ir_unop_i2u, r0C09);
      body.emit(assign(r0C02, bit_or(r0C06, r0C0A), 0x01));

      body.emit(assign(r0C03, rshift(r0BEE, body.constant(int(22))), 0x01));

      body.emit(assign(r0BED, r0C02, 0x01));

      /* IF CONDITION */
      ir_expression *const r0C0C = nequal(r0BEF, body.constant(int(0)));
      ir_if *f0C0B = new(mem_ctx) ir_if(operand(r0C0C).val);
      exec_list *const f0C0B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C0B->then_instructions;

         body.emit(assign(r0BED, bit_or(r0C02, body.constant(1073741824u)), 0x01));


      body.instructions = f0C0B_parent_instructions;
      body.emit(f0C0B);

      /* END IF */

      ir_variable *const r0C0D = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0C0D, add(r0BEF, body.constant(int(-897))), 0x01));

      ir_variable *const r0C0E = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0C0E, r0BED, 0x01));

      ir_variable *const r0C0F = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0C0F, body.constant(true), 0x01));

      ir_variable *const r0C10 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0C11 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0C11);
      ir_expression *const r0C12 = bit_and(r0BED, body.constant(127u));
      body.emit(assign(r0C11, expr(ir_unop_u2i, r0C12), 0x01));

      /* IF CONDITION */
      ir_expression *const r0C14 = expr(ir_unop_i2u, r0C0D);
      ir_expression *const r0C15 = gequal(r0C14, body.constant(253u));
      ir_if *f0C13 = new(mem_ctx) ir_if(operand(r0C15).val);
      exec_list *const f0C13_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C13->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C17 = less(body.constant(int(253)), r0C0D);
         ir_expression *const r0C18 = equal(r0C0D, body.constant(int(253)));
         ir_expression *const r0C19 = expr(ir_unop_u2i, r0BED);
         ir_expression *const r0C1A = less(r0C19, body.constant(int(-64)));
         ir_expression *const r0C1B = logic_and(r0C18, r0C1A);
         ir_expression *const r0C1C = logic_or(r0C17, r0C1B);
         ir_if *f0C16 = new(mem_ctx) ir_if(operand(r0C1C).val);
         exec_list *const f0C16_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C16->then_instructions;

            ir_expression *const r0C1D = lshift(r0BF2, body.constant(int(31)));
            ir_expression *const r0C1E = add(r0C1D, body.constant(2139095040u));
            body.emit(assign(r0C10, expr(ir_unop_bitcast_u2f, r0C1E), 0x01));

            body.emit(assign(r0C0F, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C16->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0C20 = less(r0C0D, body.constant(int(0)));
            ir_if *f0C1F = new(mem_ctx) ir_if(operand(r0C20).val);
            exec_list *const f0C1F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C1F->then_instructions;

               ir_variable *const r0C21 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0C21, neg(r0C0D), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C23 = less(r0C21, body.constant(int(32)));
               ir_if *f0C22 = new(mem_ctx) ir_if(operand(r0C23).val);
               exec_list *const f0C22_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C22->then_instructions;

                  ir_expression *const r0C24 = rshift(r0BED, r0C21);
                  ir_expression *const r0C25 = neg(r0C21);
                  ir_expression *const r0C26 = bit_and(r0C25, body.constant(int(31)));
                  ir_expression *const r0C27 = lshift(r0BED, r0C26);
                  ir_expression *const r0C28 = nequal(r0C27, body.constant(0u));
                  ir_expression *const r0C29 = expr(ir_unop_b2i, r0C28);
                  ir_expression *const r0C2A = expr(ir_unop_i2u, r0C29);
                  body.emit(assign(r0C0E, bit_or(r0C24, r0C2A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0C22->else_instructions;

                  ir_expression *const r0C2B = nequal(r0C0E, body.constant(0u));
                  ir_expression *const r0C2C = expr(ir_unop_b2i, r0C2B);
                  body.emit(assign(r0C0E, expr(ir_unop_i2u, r0C2C), 0x01));


               body.instructions = f0C22_parent_instructions;
               body.emit(f0C22);

               /* END IF */

               body.emit(assign(r0C0D, body.constant(int(0)), 0x01));

               ir_expression *const r0C2D = expr(ir_unop_u2i, r0C0E);
               body.emit(assign(r0C11, bit_and(r0C2D, body.constant(int(127))), 0x01));


            body.instructions = f0C1F_parent_instructions;
            body.emit(f0C1F);

            /* END IF */


         body.instructions = f0C16_parent_instructions;
         body.emit(f0C16);

         /* END IF */


      body.instructions = f0C13_parent_instructions;
      body.emit(f0C13);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C2E = new(mem_ctx) ir_if(operand(r0C0F).val);
      exec_list *const f0C2E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C2E->then_instructions;

         ir_expression *const r0C2F = add(r0C0E, body.constant(64u));
         body.emit(assign(r0C0E, rshift(r0C2F, body.constant(int(7))), 0x01));

         ir_expression *const r0C30 = bit_xor(r0C11, body.constant(int(64)));
         ir_expression *const r0C31 = equal(r0C30, body.constant(int(0)));
         ir_expression *const r0C32 = expr(ir_unop_b2i, r0C31);
         ir_expression *const r0C33 = expr(ir_unop_i2u, r0C32);
         ir_expression *const r0C34 = expr(ir_unop_bit_not, r0C33);
         body.emit(assign(r0C0E, bit_and(r0C0E, r0C34), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C36 = equal(r0C0E, body.constant(0u));
         ir_if *f0C35 = new(mem_ctx) ir_if(operand(r0C36).val);
         exec_list *const f0C35_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C35->then_instructions;

            body.emit(assign(r0C0D, body.constant(int(0)), 0x01));


         body.instructions = f0C35_parent_instructions;
         body.emit(f0C35);

         /* END IF */

         ir_expression *const r0C37 = lshift(r0BF2, body.constant(int(31)));
         ir_expression *const r0C38 = expr(ir_unop_i2u, r0C0D);
         ir_expression *const r0C39 = lshift(r0C38, body.constant(int(23)));
         ir_expression *const r0C3A = add(r0C37, r0C39);
         ir_expression *const r0C3B = add(r0C3A, r0C0E);
         body.emit(assign(r0C10, expr(ir_unop_bitcast_u2f, r0C3B), 0x01));

         body.emit(assign(r0C0F, body.constant(false), 0x01));


      body.instructions = f0C2E_parent_instructions;
      body.emit(f0C2E);

      /* END IF */

      body.emit(assign(r0BEC, r0C10, 0x01));


   body.instructions = f0BF3_parent_instructions;
   body.emit(f0BF3);

   /* END IF */

   ir_variable *const r0C3C = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C3C, body.constant(true), 0x01));

   ir_variable *const r0C3D = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C3E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C3E);
   ir_variable *const r0C3F = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C3F);
   ir_variable *const r0C40 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C40);
   ir_variable *const r0C41 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C42 = expr(ir_unop_sqrt, r0BEC);
   body.emit(assign(r0C41, expr(ir_unop_bitcast_f2u, r0C42), 0x01));

   ir_variable *const r0C43 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C43, bit_and(r0C41, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C40, r0C43, 0x01));

   ir_variable *const r0C44 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C45 = rshift(r0C41, body.constant(int(23)));
   ir_expression *const r0C46 = bit_and(r0C45, body.constant(255u));
   body.emit(assign(r0C44, expr(ir_unop_u2i, r0C46), 0x01));

   body.emit(assign(r0C3F, r0C44, 0x01));

   body.emit(assign(r0C3E, rshift(r0C41, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C48 = equal(r0C44, body.constant(int(255)));
   ir_if *f0C47 = new(mem_ctx) ir_if(operand(r0C48).val);
   exec_list *const f0C47_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C47->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C4A = nequal(r0C43, body.constant(0u));
      ir_if *f0C49 = new(mem_ctx) ir_if(operand(r0C4A).val);
      exec_list *const f0C49_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C49->then_instructions;

         ir_variable *const r0C4B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C4B, lshift(r0C41, body.constant(int(9))), 0x01));

         ir_variable *const r0C4C = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C4D = lshift(r0C4B, body.constant(int(20)));
         body.emit(assign(r0C4C, bit_or(r0C4D, body.constant(0u)), 0x01));

         ir_expression *const r0C4E = rshift(r0C4B, body.constant(int(12)));
         ir_expression *const r0C4F = lshift(r0C3E, body.constant(int(31)));
         ir_expression *const r0C50 = bit_or(r0C4F, body.constant(2146959360u));
         body.emit(assign(r0C4C, bit_or(r0C4E, r0C50), 0x02));

         body.emit(assign(r0C3D, r0C4C, 0x03));

         body.emit(assign(r0C3C, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C49->else_instructions;

         ir_variable *const r0C51 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C51);
         ir_expression *const r0C52 = lshift(r0C3E, body.constant(int(31)));
         body.emit(assign(r0C51, add(r0C52, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C51, body.constant(0u), 0x01));

         body.emit(assign(r0C3D, r0C51, 0x03));

         body.emit(assign(r0C3C, body.constant(false), 0x01));


      body.instructions = f0C49_parent_instructions;
      body.emit(f0C49);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C47->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C54 = equal(r0C44, body.constant(int(0)));
      ir_if *f0C53 = new(mem_ctx) ir_if(operand(r0C54).val);
      exec_list *const f0C53_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C53->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C56 = equal(r0C43, body.constant(0u));
         ir_if *f0C55 = new(mem_ctx) ir_if(operand(r0C56).val);
         exec_list *const f0C55_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C55->then_instructions;

            ir_variable *const r0C57 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C57);
            body.emit(assign(r0C57, lshift(r0C3E, body.constant(int(31))), 0x02));

            body.emit(assign(r0C57, body.constant(0u), 0x01));

            body.emit(assign(r0C3D, r0C57, 0x03));

            body.emit(assign(r0C3C, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C55->else_instructions;

            ir_variable *const r0C58 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0C58, r0C43, 0x01));

            ir_variable *const r0C59 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0C5A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0C5A);
            /* IF CONDITION */
            ir_expression *const r0C5C = equal(r0C43, body.constant(0u));
            ir_if *f0C5B = new(mem_ctx) ir_if(operand(r0C5C).val);
            exec_list *const f0C5B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C5B->then_instructions;

               body.emit(assign(r0C59, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0C5B->else_instructions;

               body.emit(assign(r0C5A, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C5E = bit_and(r0C43, body.constant(4294901760u));
               ir_expression *const r0C5F = equal(r0C5E, body.constant(0u));
               ir_if *f0C5D = new(mem_ctx) ir_if(operand(r0C5F).val);
               exec_list *const f0C5D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C5D->then_instructions;

                  body.emit(assign(r0C5A, body.constant(int(16)), 0x01));

                  body.emit(assign(r0C58, lshift(r0C43, body.constant(int(16))), 0x01));


               body.instructions = f0C5D_parent_instructions;
               body.emit(f0C5D);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C61 = bit_and(r0C58, body.constant(4278190080u));
               ir_expression *const r0C62 = equal(r0C61, body.constant(0u));
               ir_if *f0C60 = new(mem_ctx) ir_if(operand(r0C62).val);
               exec_list *const f0C60_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C60->then_instructions;

                  body.emit(assign(r0C5A, add(r0C5A, body.constant(int(8))), 0x01));

                  body.emit(assign(r0C58, lshift(r0C58, body.constant(int(8))), 0x01));


               body.instructions = f0C60_parent_instructions;
               body.emit(f0C60);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C64 = bit_and(r0C58, body.constant(4026531840u));
               ir_expression *const r0C65 = equal(r0C64, body.constant(0u));
               ir_if *f0C63 = new(mem_ctx) ir_if(operand(r0C65).val);
               exec_list *const f0C63_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C63->then_instructions;

                  body.emit(assign(r0C5A, add(r0C5A, body.constant(int(4))), 0x01));

                  body.emit(assign(r0C58, lshift(r0C58, body.constant(int(4))), 0x01));


               body.instructions = f0C63_parent_instructions;
               body.emit(f0C63);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C67 = bit_and(r0C58, body.constant(3221225472u));
               ir_expression *const r0C68 = equal(r0C67, body.constant(0u));
               ir_if *f0C66 = new(mem_ctx) ir_if(operand(r0C68).val);
               exec_list *const f0C66_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C66->then_instructions;

                  body.emit(assign(r0C5A, add(r0C5A, body.constant(int(2))), 0x01));

                  body.emit(assign(r0C58, lshift(r0C58, body.constant(int(2))), 0x01));


               body.instructions = f0C66_parent_instructions;
               body.emit(f0C66);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C6A = bit_and(r0C58, body.constant(2147483648u));
               ir_expression *const r0C6B = equal(r0C6A, body.constant(0u));
               ir_if *f0C69 = new(mem_ctx) ir_if(operand(r0C6B).val);
               exec_list *const f0C69_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C69->then_instructions;

                  body.emit(assign(r0C5A, add(r0C5A, body.constant(int(1))), 0x01));


               body.instructions = f0C69_parent_instructions;
               body.emit(f0C69);

               /* END IF */

               body.emit(assign(r0C59, r0C5A, 0x01));


            body.instructions = f0C5B_parent_instructions;
            body.emit(f0C5B);

            /* END IF */

            ir_variable *const r0C6C = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0C6C, add(r0C59, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C40, lshift(r0C43, r0C6C), 0x01));

            body.emit(assign(r0C3F, sub(body.constant(int(1)), r0C6C), 0x01));

            body.emit(assign(r0C3F, add(r0C3F, body.constant(int(-1))), 0x01));


         body.instructions = f0C55_parent_instructions;
         body.emit(f0C55);

         /* END IF */


      body.instructions = f0C53_parent_instructions;
      body.emit(f0C53);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C6D = new(mem_ctx) ir_if(operand(r0C3C).val);
      exec_list *const f0C6D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C6D->then_instructions;

         ir_variable *const r0C6E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C6E);
         ir_expression *const r0C6F = lshift(r0C3E, body.constant(int(31)));
         ir_expression *const r0C70 = add(r0C3F, body.constant(int(896)));
         ir_expression *const r0C71 = expr(ir_unop_i2u, r0C70);
         ir_expression *const r0C72 = lshift(r0C71, body.constant(int(20)));
         ir_expression *const r0C73 = add(r0C6F, r0C72);
         ir_expression *const r0C74 = rshift(r0C40, body.constant(int(3)));
         body.emit(assign(r0C6E, add(r0C73, r0C74), 0x02));

         ir_expression *const r0C75 = lshift(r0C40, body.constant(int(29)));
         body.emit(assign(r0C6E, bit_or(r0C75, body.constant(0u)), 0x01));

         body.emit(assign(r0C3D, r0C6E, 0x03));

         body.emit(assign(r0C3C, body.constant(false), 0x01));


      body.instructions = f0C6D_parent_instructions;
      body.emit(f0C6D);

      /* END IF */


   body.instructions = f0C47_parent_instructions;
   body.emit(f0C47);

   /* END IF */

   body.emit(ret(r0C3D));

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

   ir_variable *const r0C76 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C76);
   ir_variable *const r0C77 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C78 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C79 = rshift(swizzle_y(r0C76), body.constant(int(20)));
   ir_expression *const r0C7A = bit_and(r0C79, body.constant(2047u));
   ir_expression *const r0C7B = expr(ir_unop_u2i, r0C7A);
   body.emit(assign(r0C78, add(r0C7B, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C7D = less(r0C78, body.constant(int(0)));
   ir_if *f0C7C = new(mem_ctx) ir_if(operand(r0C7D).val);
   exec_list *const f0C7C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C7C->then_instructions;

      body.emit(assign(r0C77, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C7C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C7F = less(body.constant(int(52)), r0C78);
      ir_if *f0C7E = new(mem_ctx) ir_if(operand(r0C7F).val);
      exec_list *const f0C7E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C7E->then_instructions;

         body.emit(assign(r0C77, r0C76, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C7E->else_instructions;

         ir_variable *const r0C80 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0C80, sub(body.constant(int(52)), r0C78), 0x01));

         ir_variable *const r0C81 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0C83 = gequal(r0C80, body.constant(int(32)));
         ir_if *f0C82 = new(mem_ctx) ir_if(operand(r0C83).val);
         exec_list *const f0C82_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C82->then_instructions;

            body.emit(assign(r0C81, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C82->else_instructions;

            body.emit(assign(r0C81, lshift(body.constant(4294967295u), r0C80), 0x01));


         body.instructions = f0C82_parent_instructions;
         body.emit(f0C82);

         /* END IF */

         ir_variable *const r0C84 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0C86 = less(r0C80, body.constant(int(33)));
         ir_if *f0C85 = new(mem_ctx) ir_if(operand(r0C86).val);
         exec_list *const f0C85_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C85->then_instructions;

            body.emit(assign(r0C84, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C85->else_instructions;

            ir_expression *const r0C87 = add(r0C80, body.constant(int(-32)));
            body.emit(assign(r0C84, lshift(body.constant(4294967295u), r0C87), 0x01));


         body.instructions = f0C85_parent_instructions;
         body.emit(f0C85);

         /* END IF */

         ir_variable *const r0C88 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0C88, bit_and(r0C81, swizzle_x(r0C76)), 0x01));

         body.emit(assign(r0C88, bit_and(r0C84, swizzle_y(r0C76)), 0x02));

         body.emit(assign(r0C77, r0C88, 0x03));


      body.instructions = f0C7E_parent_instructions;
      body.emit(f0C7E);

      /* END IF */


   body.instructions = f0C7C_parent_instructions;
   body.emit(f0C7C);

   /* END IF */

   body.emit(ret(r0C77));

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

   ir_variable *const r0C89 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C89);
   ir_variable *const r0C8A = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C8A, body.constant(true), 0x01));

   ir_variable *const r0C8B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C8C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0C8C);
   ir_variable *const r0C8D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0C8D);
   ir_variable *const r0C8E = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C8F = rshift(swizzle_y(r0C89), body.constant(int(20)));
   ir_expression *const r0C90 = bit_and(r0C8F, body.constant(2047u));
   ir_expression *const r0C91 = expr(ir_unop_u2i, r0C90);
   body.emit(assign(r0C8E, add(r0C91, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0C8D, swizzle_y(r0C89), 0x01));

   body.emit(assign(r0C8C, swizzle_x(r0C89), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C93 = less(r0C8E, body.constant(int(20)));
   ir_if *f0C92 = new(mem_ctx) ir_if(operand(r0C93).val);
   exec_list *const f0C92_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C92->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C95 = less(r0C8E, body.constant(int(0)));
      ir_if *f0C94 = new(mem_ctx) ir_if(operand(r0C95).val);
      exec_list *const f0C94_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C94->then_instructions;

         body.emit(assign(r0C8D, bit_and(swizzle_y(r0C89), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C97 = equal(r0C8E, body.constant(int(-1)));
         ir_expression *const r0C98 = nequal(swizzle_x(r0C89), body.constant(0u));
         ir_expression *const r0C99 = logic_and(r0C97, r0C98);
         ir_if *f0C96 = new(mem_ctx) ir_if(operand(r0C99).val);
         exec_list *const f0C96_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C96->then_instructions;

            body.emit(assign(r0C8D, bit_or(r0C8D, body.constant(1072693248u)), 0x01));


         body.instructions = f0C96_parent_instructions;
         body.emit(f0C96);

         /* END IF */

         body.emit(assign(r0C8C, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C94->else_instructions;

         ir_variable *const r0C9A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C9A, rshift(body.constant(1048575u), r0C8E), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C9C = bit_and(r0C8D, r0C9A);
         ir_expression *const r0C9D = equal(r0C9C, body.constant(0u));
         ir_expression *const r0C9E = equal(r0C8C, body.constant(0u));
         ir_expression *const r0C9F = logic_and(r0C9D, r0C9E);
         ir_if *f0C9B = new(mem_ctx) ir_if(operand(r0C9F).val);
         exec_list *const f0C9B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C9B->then_instructions;

            body.emit(assign(r0C8B, r0C89, 0x03));

            body.emit(assign(r0C8A, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C9B->else_instructions;

            ir_expression *const r0CA0 = rshift(body.constant(524288u), r0C8E);
            body.emit(assign(r0C8D, add(r0C8D, r0CA0), 0x01));

            ir_expression *const r0CA1 = expr(ir_unop_bit_not, r0C9A);
            body.emit(assign(r0C8D, bit_and(r0C8D, r0CA1), 0x01));

            body.emit(assign(r0C8C, body.constant(0u), 0x01));


         body.instructions = f0C9B_parent_instructions;
         body.emit(f0C9B);

         /* END IF */


      body.instructions = f0C94_parent_instructions;
      body.emit(f0C94);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C92->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CA3 = less(body.constant(int(51)), r0C8E);
      ir_expression *const r0CA4 = equal(r0C8E, body.constant(int(1024)));
      ir_expression *const r0CA5 = logic_or(r0CA3, r0CA4);
      ir_if *f0CA2 = new(mem_ctx) ir_if(operand(r0CA5).val);
      exec_list *const f0CA2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CA2->then_instructions;

         body.emit(assign(r0C8B, r0C89, 0x03));

         body.emit(assign(r0C8A, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CA2->else_instructions;

         ir_variable *const r0CA6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0CA7 = add(r0C8E, body.constant(int(-20)));
         body.emit(assign(r0CA6, rshift(body.constant(4294967295u), r0CA7), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CA9 = bit_and(r0C8C, r0CA6);
         ir_expression *const r0CAA = equal(r0CA9, body.constant(0u));
         ir_if *f0CA8 = new(mem_ctx) ir_if(operand(r0CAA).val);
         exec_list *const f0CA8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CA8->then_instructions;

            body.emit(assign(r0C8B, r0C89, 0x03));

            body.emit(assign(r0C8A, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CA8->else_instructions;

            ir_variable *const r0CAB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0CAC = sub(body.constant(int(51)), r0C8E);
            ir_expression *const r0CAD = lshift(body.constant(1u), r0CAC);
            body.emit(assign(r0CAB, add(r0C8C, r0CAD), 0x01));

            /* IF CONDITION */
            ir_expression *const r0CAF = less(r0CAB, r0C8C);
            ir_if *f0CAE = new(mem_ctx) ir_if(operand(r0CAF).val);
            exec_list *const f0CAE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0CAE->then_instructions;

               body.emit(assign(r0C8D, add(r0C8D, body.constant(1u)), 0x01));


            body.instructions = f0CAE_parent_instructions;
            body.emit(f0CAE);

            /* END IF */

            ir_expression *const r0CB0 = expr(ir_unop_bit_not, r0CA6);
            body.emit(assign(r0C8C, bit_and(r0CAB, r0CB0), 0x01));


         body.instructions = f0CA8_parent_instructions;
         body.emit(f0CA8);

         /* END IF */


      body.instructions = f0CA2_parent_instructions;
      body.emit(f0CA2);

      /* END IF */


   body.instructions = f0C92_parent_instructions;
   body.emit(f0C92);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0CB1 = new(mem_ctx) ir_if(operand(r0C8A).val);
   exec_list *const f0CB1_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CB1->then_instructions;

      body.emit(assign(r0C89, r0C8C, 0x01));

      body.emit(assign(r0C89, r0C8D, 0x02));

      body.emit(assign(r0C8B, r0C89, 0x03));

      body.emit(assign(r0C8A, body.constant(false), 0x01));


   body.instructions = f0CB1_parent_instructions;
   body.emit(f0CB1);

   /* END IF */

   body.emit(ret(r0C8B));

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

   ir_variable *const r0CB2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CB2);
   ir_variable *const r0CB3 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0CB4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0CB4);
   body.emit(assign(r0CB4, body.constant(0u), 0x01));

   ir_variable *const r0CB5 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0CB5, bit_and(swizzle_y(r0CB2), body.constant(1048575u)), 0x01));

   ir_variable *const r0CB6 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0CB7 = rshift(swizzle_y(r0CB2), body.constant(int(20)));
   ir_expression *const r0CB8 = bit_and(r0CB7, body.constant(2047u));
   body.emit(assign(r0CB6, expr(ir_unop_u2i, r0CB8), 0x01));

   ir_variable *const r0CB9 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0CB9, rshift(swizzle_y(r0CB2), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CBB = equal(r0CB6, body.constant(int(2047)));
   ir_if *f0CBA = new(mem_ctx) ir_if(operand(r0CBB).val);
   exec_list *const f0CBA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CBA->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CBD = bit_or(r0CB5, swizzle_x(r0CB2));
      ir_expression *const r0CBE = nequal(r0CBD, body.constant(0u));
      ir_if *f0CBC = new(mem_ctx) ir_if(operand(r0CBE).val);
      exec_list *const f0CBC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CBC->then_instructions;

         ir_variable *const r0CBF = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0CBF, lshift(swizzle_x(r0CB2), body.constant(int(12))), 0x01));

         ir_expression *const r0CC0 = lshift(r0CB9, body.constant(int(31)));
         ir_expression *const r0CC1 = bit_or(r0CC0, body.constant(2143289344u));
         ir_expression *const r0CC2 = lshift(swizzle_y(r0CB2), body.constant(int(12)));
         ir_expression *const r0CC3 = rshift(swizzle_x(r0CB2), body.constant(int(20)));
         ir_expression *const r0CC4 = bit_or(r0CC2, r0CC3);
         ir_expression *const r0CC5 = rshift(r0CC4, body.constant(int(9)));
         ir_expression *const r0CC6 = bit_or(r0CC1, r0CC5);
         body.emit(assign(r0CB3, expr(ir_unop_bitcast_u2f, r0CC6), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CBC->else_instructions;

         ir_expression *const r0CC7 = lshift(r0CB9, body.constant(int(31)));
         ir_expression *const r0CC8 = add(r0CC7, body.constant(2139095040u));
         body.emit(assign(r0CB3, expr(ir_unop_bitcast_u2f, r0CC8), 0x01));


      body.instructions = f0CBC_parent_instructions;
      body.emit(f0CBC);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CBA->else_instructions;

      ir_variable *const r0CC9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0CC9);
      ir_variable *const r0CCA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0CCA);
      ir_expression *const r0CCB = lshift(r0CB5, body.constant(int(10)));
      ir_expression *const r0CCC = rshift(swizzle_x(r0CB2), body.constant(int(22)));
      ir_expression *const r0CCD = bit_or(r0CCB, r0CCC);
      ir_expression *const r0CCE = lshift(swizzle_x(r0CB2), body.constant(int(10)));
      ir_expression *const r0CCF = nequal(r0CCE, body.constant(0u));
      ir_expression *const r0CD0 = expr(ir_unop_b2i, r0CCF);
      ir_expression *const r0CD1 = expr(ir_unop_i2u, r0CD0);
      body.emit(assign(r0CC9, bit_or(r0CCD, r0CD1), 0x01));

      body.emit(assign(r0CCA, rshift(r0CB5, body.constant(int(22))), 0x01));

      body.emit(assign(r0CB4, r0CC9, 0x01));

      /* IF CONDITION */
      ir_expression *const r0CD3 = nequal(r0CB6, body.constant(int(0)));
      ir_if *f0CD2 = new(mem_ctx) ir_if(operand(r0CD3).val);
      exec_list *const f0CD2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CD2->then_instructions;

         body.emit(assign(r0CB4, bit_or(r0CC9, body.constant(1073741824u)), 0x01));


      body.instructions = f0CD2_parent_instructions;
      body.emit(f0CD2);

      /* END IF */

      ir_variable *const r0CD4 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0CD4, add(r0CB6, body.constant(int(-897))), 0x01));

      ir_variable *const r0CD5 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0CD5, r0CB4, 0x01));

      ir_variable *const r0CD6 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0CD6, body.constant(true), 0x01));

      ir_variable *const r0CD7 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0CD8 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0CD8);
      ir_expression *const r0CD9 = bit_and(r0CB4, body.constant(127u));
      body.emit(assign(r0CD8, expr(ir_unop_u2i, r0CD9), 0x01));

      /* IF CONDITION */
      ir_expression *const r0CDB = expr(ir_unop_i2u, r0CD4);
      ir_expression *const r0CDC = gequal(r0CDB, body.constant(253u));
      ir_if *f0CDA = new(mem_ctx) ir_if(operand(r0CDC).val);
      exec_list *const f0CDA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CDA->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0CDE = less(body.constant(int(253)), r0CD4);
         ir_expression *const r0CDF = equal(r0CD4, body.constant(int(253)));
         ir_expression *const r0CE0 = expr(ir_unop_u2i, r0CB4);
         ir_expression *const r0CE1 = less(r0CE0, body.constant(int(-64)));
         ir_expression *const r0CE2 = logic_and(r0CDF, r0CE1);
         ir_expression *const r0CE3 = logic_or(r0CDE, r0CE2);
         ir_if *f0CDD = new(mem_ctx) ir_if(operand(r0CE3).val);
         exec_list *const f0CDD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CDD->then_instructions;

            ir_expression *const r0CE4 = lshift(r0CB9, body.constant(int(31)));
            ir_expression *const r0CE5 = add(r0CE4, body.constant(2139095040u));
            body.emit(assign(r0CD7, expr(ir_unop_bitcast_u2f, r0CE5), 0x01));

            body.emit(assign(r0CD6, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CDD->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0CE7 = less(r0CD4, body.constant(int(0)));
            ir_if *f0CE6 = new(mem_ctx) ir_if(operand(r0CE7).val);
            exec_list *const f0CE6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0CE6->then_instructions;

               ir_variable *const r0CE8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0CE8, neg(r0CD4), 0x01));

               /* IF CONDITION */
               ir_expression *const r0CEA = less(r0CE8, body.constant(int(32)));
               ir_if *f0CE9 = new(mem_ctx) ir_if(operand(r0CEA).val);
               exec_list *const f0CE9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0CE9->then_instructions;

                  ir_expression *const r0CEB = rshift(r0CB4, r0CE8);
                  ir_expression *const r0CEC = neg(r0CE8);
                  ir_expression *const r0CED = bit_and(r0CEC, body.constant(int(31)));
                  ir_expression *const r0CEE = lshift(r0CB4, r0CED);
                  ir_expression *const r0CEF = nequal(r0CEE, body.constant(0u));
                  ir_expression *const r0CF0 = expr(ir_unop_b2i, r0CEF);
                  ir_expression *const r0CF1 = expr(ir_unop_i2u, r0CF0);
                  body.emit(assign(r0CD5, bit_or(r0CEB, r0CF1), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0CE9->else_instructions;

                  ir_expression *const r0CF2 = nequal(r0CD5, body.constant(0u));
                  ir_expression *const r0CF3 = expr(ir_unop_b2i, r0CF2);
                  body.emit(assign(r0CD5, expr(ir_unop_i2u, r0CF3), 0x01));


               body.instructions = f0CE9_parent_instructions;
               body.emit(f0CE9);

               /* END IF */

               body.emit(assign(r0CD4, body.constant(int(0)), 0x01));

               ir_expression *const r0CF4 = expr(ir_unop_u2i, r0CD5);
               body.emit(assign(r0CD8, bit_and(r0CF4, body.constant(int(127))), 0x01));


            body.instructions = f0CE6_parent_instructions;
            body.emit(f0CE6);

            /* END IF */


         body.instructions = f0CDD_parent_instructions;
         body.emit(f0CDD);

         /* END IF */


      body.instructions = f0CDA_parent_instructions;
      body.emit(f0CDA);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0CF5 = new(mem_ctx) ir_if(operand(r0CD6).val);
      exec_list *const f0CF5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CF5->then_instructions;

         ir_expression *const r0CF6 = add(r0CD5, body.constant(64u));
         body.emit(assign(r0CD5, rshift(r0CF6, body.constant(int(7))), 0x01));

         ir_expression *const r0CF7 = bit_xor(r0CD8, body.constant(int(64)));
         ir_expression *const r0CF8 = equal(r0CF7, body.constant(int(0)));
         ir_expression *const r0CF9 = expr(ir_unop_b2i, r0CF8);
         ir_expression *const r0CFA = expr(ir_unop_i2u, r0CF9);
         ir_expression *const r0CFB = expr(ir_unop_bit_not, r0CFA);
         body.emit(assign(r0CD5, bit_and(r0CD5, r0CFB), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CFD = equal(r0CD5, body.constant(0u));
         ir_if *f0CFC = new(mem_ctx) ir_if(operand(r0CFD).val);
         exec_list *const f0CFC_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CFC->then_instructions;

            body.emit(assign(r0CD4, body.constant(int(0)), 0x01));


         body.instructions = f0CFC_parent_instructions;
         body.emit(f0CFC);

         /* END IF */

         ir_expression *const r0CFE = lshift(r0CB9, body.constant(int(31)));
         ir_expression *const r0CFF = expr(ir_unop_i2u, r0CD4);
         ir_expression *const r0D00 = lshift(r0CFF, body.constant(int(23)));
         ir_expression *const r0D01 = add(r0CFE, r0D00);
         ir_expression *const r0D02 = add(r0D01, r0CD5);
         body.emit(assign(r0CD7, expr(ir_unop_bitcast_u2f, r0D02), 0x01));

         body.emit(assign(r0CD6, body.constant(false), 0x01));


      body.instructions = f0CF5_parent_instructions;
      body.emit(f0CF5);

      /* END IF */

      body.emit(assign(r0CB3, r0CD7, 0x01));


   body.instructions = f0CBA_parent_instructions;
   body.emit(f0CBA);

   /* END IF */

   ir_variable *const r0D03 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0D03, body.constant(true), 0x01));

   ir_variable *const r0D04 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0D05 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0D05);
   ir_variable *const r0D06 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0D06);
   ir_variable *const r0D07 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0D07);
   ir_variable *const r0D08 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0D09 = expr(ir_unop_rcp, r0CB3);
   body.emit(assign(r0D08, expr(ir_unop_bitcast_f2u, r0D09), 0x01));

   ir_variable *const r0D0A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0D0A, bit_and(r0D08, body.constant(8388607u)), 0x01));

   body.emit(assign(r0D07, r0D0A, 0x01));

   ir_variable *const r0D0B = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0D0C = rshift(r0D08, body.constant(int(23)));
   ir_expression *const r0D0D = bit_and(r0D0C, body.constant(255u));
   body.emit(assign(r0D0B, expr(ir_unop_u2i, r0D0D), 0x01));

   body.emit(assign(r0D06, r0D0B, 0x01));

   body.emit(assign(r0D05, rshift(r0D08, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0D0F = equal(r0D0B, body.constant(int(255)));
   ir_if *f0D0E = new(mem_ctx) ir_if(operand(r0D0F).val);
   exec_list *const f0D0E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D0E->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0D11 = nequal(r0D0A, body.constant(0u));
      ir_if *f0D10 = new(mem_ctx) ir_if(operand(r0D11).val);
      exec_list *const f0D10_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D10->then_instructions;

         ir_variable *const r0D12 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0D12, lshift(r0D08, body.constant(int(9))), 0x01));

         ir_variable *const r0D13 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0D14 = lshift(r0D12, body.constant(int(20)));
         body.emit(assign(r0D13, bit_or(r0D14, body.constant(0u)), 0x01));

         ir_expression *const r0D15 = rshift(r0D12, body.constant(int(12)));
         ir_expression *const r0D16 = lshift(r0D05, body.constant(int(31)));
         ir_expression *const r0D17 = bit_or(r0D16, body.constant(2146959360u));
         body.emit(assign(r0D13, bit_or(r0D15, r0D17), 0x02));

         body.emit(assign(r0D04, r0D13, 0x03));

         body.emit(assign(r0D03, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D10->else_instructions;

         ir_variable *const r0D18 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D18);
         ir_expression *const r0D19 = lshift(r0D05, body.constant(int(31)));
         body.emit(assign(r0D18, add(r0D19, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0D18, body.constant(0u), 0x01));

         body.emit(assign(r0D04, r0D18, 0x03));

         body.emit(assign(r0D03, body.constant(false), 0x01));


      body.instructions = f0D10_parent_instructions;
      body.emit(f0D10);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0D0E->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0D1B = equal(r0D0B, body.constant(int(0)));
      ir_if *f0D1A = new(mem_ctx) ir_if(operand(r0D1B).val);
      exec_list *const f0D1A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D1A->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0D1D = equal(r0D0A, body.constant(0u));
         ir_if *f0D1C = new(mem_ctx) ir_if(operand(r0D1D).val);
         exec_list *const f0D1C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D1C->then_instructions;

            ir_variable *const r0D1E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0D1E);
            body.emit(assign(r0D1E, lshift(r0D05, body.constant(int(31))), 0x02));

            body.emit(assign(r0D1E, body.constant(0u), 0x01));

            body.emit(assign(r0D04, r0D1E, 0x03));

            body.emit(assign(r0D03, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D1C->else_instructions;

            ir_variable *const r0D1F = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0D1F, r0D0A, 0x01));

            ir_variable *const r0D20 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0D21 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0D21);
            /* IF CONDITION */
            ir_expression *const r0D23 = equal(r0D0A, body.constant(0u));
            ir_if *f0D22 = new(mem_ctx) ir_if(operand(r0D23).val);
            exec_list *const f0D22_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D22->then_instructions;

               body.emit(assign(r0D20, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0D22->else_instructions;

               body.emit(assign(r0D21, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0D25 = bit_and(r0D0A, body.constant(4294901760u));
               ir_expression *const r0D26 = equal(r0D25, body.constant(0u));
               ir_if *f0D24 = new(mem_ctx) ir_if(operand(r0D26).val);
               exec_list *const f0D24_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D24->then_instructions;

                  body.emit(assign(r0D21, body.constant(int(16)), 0x01));

                  body.emit(assign(r0D1F, lshift(r0D0A, body.constant(int(16))), 0x01));


               body.instructions = f0D24_parent_instructions;
               body.emit(f0D24);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D28 = bit_and(r0D1F, body.constant(4278190080u));
               ir_expression *const r0D29 = equal(r0D28, body.constant(0u));
               ir_if *f0D27 = new(mem_ctx) ir_if(operand(r0D29).val);
               exec_list *const f0D27_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D27->then_instructions;

                  body.emit(assign(r0D21, add(r0D21, body.constant(int(8))), 0x01));

                  body.emit(assign(r0D1F, lshift(r0D1F, body.constant(int(8))), 0x01));


               body.instructions = f0D27_parent_instructions;
               body.emit(f0D27);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D2B = bit_and(r0D1F, body.constant(4026531840u));
               ir_expression *const r0D2C = equal(r0D2B, body.constant(0u));
               ir_if *f0D2A = new(mem_ctx) ir_if(operand(r0D2C).val);
               exec_list *const f0D2A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D2A->then_instructions;

                  body.emit(assign(r0D21, add(r0D21, body.constant(int(4))), 0x01));

                  body.emit(assign(r0D1F, lshift(r0D1F, body.constant(int(4))), 0x01));


               body.instructions = f0D2A_parent_instructions;
               body.emit(f0D2A);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D2E = bit_and(r0D1F, body.constant(3221225472u));
               ir_expression *const r0D2F = equal(r0D2E, body.constant(0u));
               ir_if *f0D2D = new(mem_ctx) ir_if(operand(r0D2F).val);
               exec_list *const f0D2D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D2D->then_instructions;

                  body.emit(assign(r0D21, add(r0D21, body.constant(int(2))), 0x01));

                  body.emit(assign(r0D1F, lshift(r0D1F, body.constant(int(2))), 0x01));


               body.instructions = f0D2D_parent_instructions;
               body.emit(f0D2D);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D31 = bit_and(r0D1F, body.constant(2147483648u));
               ir_expression *const r0D32 = equal(r0D31, body.constant(0u));
               ir_if *f0D30 = new(mem_ctx) ir_if(operand(r0D32).val);
               exec_list *const f0D30_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D30->then_instructions;

                  body.emit(assign(r0D21, add(r0D21, body.constant(int(1))), 0x01));


               body.instructions = f0D30_parent_instructions;
               body.emit(f0D30);

               /* END IF */

               body.emit(assign(r0D20, r0D21, 0x01));


            body.instructions = f0D22_parent_instructions;
            body.emit(f0D22);

            /* END IF */

            ir_variable *const r0D33 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0D33, add(r0D20, body.constant(int(-8))), 0x01));

            body.emit(assign(r0D07, lshift(r0D0A, r0D33), 0x01));

            body.emit(assign(r0D06, sub(body.constant(int(1)), r0D33), 0x01));

            body.emit(assign(r0D06, add(r0D06, body.constant(int(-1))), 0x01));


         body.instructions = f0D1C_parent_instructions;
         body.emit(f0D1C);

         /* END IF */


      body.instructions = f0D1A_parent_instructions;
      body.emit(f0D1A);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0D34 = new(mem_ctx) ir_if(operand(r0D03).val);
      exec_list *const f0D34_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D34->then_instructions;

         ir_variable *const r0D35 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D35);
         ir_expression *const r0D36 = lshift(r0D05, body.constant(int(31)));
         ir_expression *const r0D37 = add(r0D06, body.constant(int(896)));
         ir_expression *const r0D38 = expr(ir_unop_i2u, r0D37);
         ir_expression *const r0D39 = lshift(r0D38, body.constant(int(20)));
         ir_expression *const r0D3A = add(r0D36, r0D39);
         ir_expression *const r0D3B = rshift(r0D07, body.constant(int(3)));
         body.emit(assign(r0D35, add(r0D3A, r0D3B), 0x02));

         ir_expression *const r0D3C = lshift(r0D07, body.constant(int(29)));
         body.emit(assign(r0D35, bit_or(r0D3C, body.constant(0u)), 0x01));

         body.emit(assign(r0D04, r0D35, 0x03));

         body.emit(assign(r0D03, body.constant(false), 0x01));


      body.instructions = f0D34_parent_instructions;
      body.emit(f0D34);

      /* END IF */


   body.instructions = f0D0E_parent_instructions;
   body.emit(f0D0E);

   /* END IF */

   body.emit(ret(r0D04));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
