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
   ir_variable *const r01CD = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01CE = lshift(swizzle_y(r01CB), body.constant(int(1)));
   ir_expression *const r01CF = gequal(r01CE, body.constant(4292870144u));
   ir_expression *const r01D0 = nequal(swizzle_x(r01CB), body.constant(0u));
   ir_expression *const r01D1 = bit_and(swizzle_y(r01CB), body.constant(1048575u));
   ir_expression *const r01D2 = nequal(r01D1, body.constant(0u));
   ir_expression *const r01D3 = logic_or(r01D0, r01D2);
   body.emit(assign(r01CD, logic_and(r01CF, r01D3), 0x01));

   ir_variable *const r01D4 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01D5 = lshift(swizzle_y(r01CC), body.constant(int(1)));
   ir_expression *const r01D6 = gequal(r01D5, body.constant(4292870144u));
   ir_expression *const r01D7 = nequal(swizzle_x(r01CC), body.constant(0u));
   ir_expression *const r01D8 = bit_and(swizzle_y(r01CC), body.constant(1048575u));
   ir_expression *const r01D9 = nequal(r01D8, body.constant(0u));
   ir_expression *const r01DA = logic_or(r01D7, r01D9);
   body.emit(assign(r01D4, logic_and(r01D6, r01DA), 0x01));

   body.emit(assign(r01CB, bit_or(swizzle_y(r01CB), body.constant(524288u)), 0x02));

   body.emit(assign(r01CC, bit_or(swizzle_y(r01CC), body.constant(524288u)), 0x02));

   ir_variable *const r01DB = body.make_temp(glsl_type::uvec2_type, "mix_retval");
   ir_swizzle *const r01DC = swizzle(r01CD, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_swizzle *const r01DD = swizzle(r01D4, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
   ir_expression *const r01DE = expr(ir_triop_csel, r01DD, r01CC, r01CB);
   body.emit(assign(r01DB, expr(ir_triop_csel, r01DC, r01DE, r01CC), 0x03));

   body.emit(ret(r01DB));

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

               body.emit(assign(r0202, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

               body.emit(assign(r0203, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

               ir_expression *const r0204 = lshift(swizzle_y(r01DF), body.constant(int(1)));
               ir_expression *const r0205 = gequal(r0204, body.constant(4292870144u));
               ir_expression *const r0206 = nequal(swizzle_x(r01DF), body.constant(0u));
               ir_expression *const r0207 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
               ir_expression *const r0208 = nequal(r0207, body.constant(0u));
               ir_expression *const r0209 = logic_or(r0206, r0208);
               ir_expression *const r020A = logic_and(r0205, r0209);
               ir_swizzle *const r020B = swizzle(r020A, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r020C = lshift(swizzle_y(r01E0), body.constant(int(1)));
               ir_expression *const r020D = gequal(r020C, body.constant(4292870144u));
               ir_expression *const r020E = nequal(swizzle_x(r01E0), body.constant(0u));
               ir_expression *const r020F = bit_and(swizzle_y(r01E0), body.constant(1048575u));
               ir_expression *const r0210 = nequal(r020F, body.constant(0u));
               ir_expression *const r0211 = logic_or(r020E, r0210);
               ir_expression *const r0212 = logic_and(r020D, r0211);
               ir_swizzle *const r0213 = swizzle(r0212, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r0214 = expr(ir_triop_csel, r0213, r0203, r0202);
               body.emit(assign(r01E2, expr(ir_triop_csel, r020B, r0214, r0203), 0x03));

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
            ir_expression *const r0216 = equal(r01F7, body.constant(int(0)));
            ir_if *f0215 = new(mem_ctx) ir_if(operand(r0216).val);
            exec_list *const f0215_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0215->then_instructions;

               body.emit(assign(r01E8, add(r01FA, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0215->else_instructions;

               body.emit(assign(r01E9, bit_or(r01F3, body.constant(1048576u)), 0x01));


            body.instructions = f0215_parent_instructions;
            body.emit(f0215);

            /* END IF */

            ir_variable *const r0217 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0217, body.constant(0u), 0x01));

            ir_variable *const r0218 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0218);
            ir_variable *const r0219 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0219);
            ir_variable *const r021A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r021A);
            ir_variable *const r021B = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r021C = neg(r01E8);
            body.emit(assign(r021B, bit_and(r021C, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r021E = equal(r01E8, body.constant(int(0)));
            ir_if *f021D = new(mem_ctx) ir_if(operand(r021E).val);
            exec_list *const f021D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f021D->then_instructions;

               body.emit(assign(r0218, r0217, 0x01));

               body.emit(assign(r0219, r01F2, 0x01));

               body.emit(assign(r021A, r01E9, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f021D->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0220 = less(r01E8, body.constant(int(32)));
               ir_if *f021F = new(mem_ctx) ir_if(operand(r0220).val);
               exec_list *const f021F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f021F->then_instructions;

                  body.emit(assign(r0218, lshift(swizzle_x(r01E0), r021B), 0x01));

                  ir_expression *const r0221 = lshift(r01E9, r021B);
                  ir_expression *const r0222 = rshift(swizzle_x(r01E0), r01E8);
                  body.emit(assign(r0219, bit_or(r0221, r0222), 0x01));

                  body.emit(assign(r021A, rshift(r01E9, r01E8), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f021F->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0224 = equal(r01E8, body.constant(int(32)));
                  ir_if *f0223 = new(mem_ctx) ir_if(operand(r0224).val);
                  exec_list *const f0223_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0223->then_instructions;

                     body.emit(assign(r0218, r01F2, 0x01));

                     body.emit(assign(r0219, r01E9, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0223->else_instructions;

                     body.emit(assign(r0217, bit_or(body.constant(0u), swizzle_x(r01E0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0226 = less(r01E8, body.constant(int(64)));
                     ir_if *f0225 = new(mem_ctx) ir_if(operand(r0226).val);
                     exec_list *const f0225_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0225->then_instructions;

                        body.emit(assign(r0218, lshift(r01E9, r021B), 0x01));

                        ir_expression *const r0227 = bit_and(r01E8, body.constant(int(31)));
                        body.emit(assign(r0219, rshift(r01E9, r0227), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0225->else_instructions;

                        ir_variable *const r0228 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r022A = equal(r01E8, body.constant(int(64)));
                        ir_if *f0229 = new(mem_ctx) ir_if(operand(r022A).val);
                        exec_list *const f0229_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0229->then_instructions;

                           body.emit(assign(r0228, r01E9, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0229->else_instructions;

                           ir_expression *const r022B = nequal(r01E9, body.constant(0u));
                           ir_expression *const r022C = expr(ir_unop_b2i, r022B);
                           body.emit(assign(r0228, expr(ir_unop_i2u, r022C), 0x01));


                        body.instructions = f0229_parent_instructions;
                        body.emit(f0229);

                        /* END IF */

                        body.emit(assign(r0218, r0228, 0x01));

                        body.emit(assign(r0219, body.constant(0u), 0x01));


                     body.instructions = f0225_parent_instructions;
                     body.emit(f0225);

                     /* END IF */


                  body.instructions = f0223_parent_instructions;
                  body.emit(f0223);

                  /* END IF */

                  body.emit(assign(r021A, body.constant(0u), 0x01));


               body.instructions = f021F_parent_instructions;
               body.emit(f021F);

               /* END IF */

               ir_expression *const r022D = nequal(r0217, body.constant(0u));
               ir_expression *const r022E = expr(ir_unop_b2i, r022D);
               ir_expression *const r022F = expr(ir_unop_i2u, r022E);
               body.emit(assign(r0218, bit_or(r0218, r022F), 0x01));


            body.instructions = f021D_parent_instructions;
            body.emit(f021D);

            /* END IF */

            body.emit(assign(r01E9, r021A, 0x01));

            body.emit(assign(r01EA, r0219, 0x01));

            body.emit(assign(r01EE, r0218, 0x01));

            body.emit(assign(r01ED, r01F4, 0x01));


         body.instructions = f01FD_parent_instructions;
         body.emit(f01FD);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01FB->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0231 = less(r01E8, body.constant(int(0)));
         ir_if *f0230 = new(mem_ctx) ir_if(operand(r0231).val);
         exec_list *const f0230_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0230->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0233 = equal(r01F7, body.constant(int(2047)));
            ir_if *f0232 = new(mem_ctx) ir_if(operand(r0233).val);
            exec_list *const f0232_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0232->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0235 = bit_or(r01E9, r01EA);
               ir_expression *const r0236 = nequal(r0235, body.constant(0u));
               ir_if *f0234 = new(mem_ctx) ir_if(operand(r0236).val);
               exec_list *const f0234_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0234->then_instructions;

                  ir_variable *const r0237 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0237, swizzle_x(r01DF), 0x01));

                  ir_variable *const r0238 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0238, swizzle_x(r01E0), 0x01));

                  body.emit(assign(r0237, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

                  body.emit(assign(r0238, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

                  ir_expression *const r0239 = lshift(swizzle_y(r01DF), body.constant(int(1)));
                  ir_expression *const r023A = gequal(r0239, body.constant(4292870144u));
                  ir_expression *const r023B = nequal(swizzle_x(r01DF), body.constant(0u));
                  ir_expression *const r023C = bit_and(swizzle_y(r01DF), body.constant(1048575u));
                  ir_expression *const r023D = nequal(r023C, body.constant(0u));
                  ir_expression *const r023E = logic_or(r023B, r023D);
                  ir_expression *const r023F = logic_and(r023A, r023E);
                  ir_swizzle *const r0240 = swizzle(r023F, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0241 = lshift(swizzle_y(r01E0), body.constant(int(1)));
                  ir_expression *const r0242 = gequal(r0241, body.constant(4292870144u));
                  ir_expression *const r0243 = nequal(swizzle_x(r01E0), body.constant(0u));
                  ir_expression *const r0244 = bit_and(swizzle_y(r01E0), body.constant(1048575u));
                  ir_expression *const r0245 = nequal(r0244, body.constant(0u));
                  ir_expression *const r0246 = logic_or(r0243, r0245);
                  ir_expression *const r0247 = logic_and(r0242, r0246);
                  ir_swizzle *const r0248 = swizzle(r0247, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0249 = expr(ir_triop_csel, r0248, r0238, r0237);
                  body.emit(assign(r01E2, expr(ir_triop_csel, r0240, r0249, r0238), 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0234->else_instructions;

                  ir_variable *const r024A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r024A);
                  ir_expression *const r024B = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r024A, add(r024B, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r024A, body.constant(0u), 0x01));

                  body.emit(assign(r01E2, r024A, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f0234_parent_instructions;
               body.emit(f0234);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0232->else_instructions;

               /* IF CONDITION */
               ir_expression *const r024D = equal(r01F4, body.constant(int(0)));
               ir_if *f024C = new(mem_ctx) ir_if(operand(r024D).val);
               exec_list *const f024C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f024C->then_instructions;

                  body.emit(assign(r01E8, add(r01E8, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f024C->else_instructions;

                  body.emit(assign(r01EB, bit_or(r01F1, body.constant(1048576u)), 0x01));


               body.instructions = f024C_parent_instructions;
               body.emit(f024C);

               /* END IF */

               ir_variable *const r024E = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r024E, body.constant(0u), 0x01));

               ir_variable *const r024F = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r024F, neg(r01E8), 0x01));

               ir_variable *const r0250 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0250);
               ir_variable *const r0251 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0251);
               ir_variable *const r0252 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0252);
               ir_variable *const r0253 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0254 = neg(r024F);
               body.emit(assign(r0253, bit_and(r0254, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0256 = equal(r024F, body.constant(int(0)));
               ir_if *f0255 = new(mem_ctx) ir_if(operand(r0256).val);
               exec_list *const f0255_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0255->then_instructions;

                  body.emit(assign(r0250, r024E, 0x01));

                  body.emit(assign(r0251, r01F0, 0x01));

                  body.emit(assign(r0252, r01EB, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0255->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0258 = less(r024F, body.constant(int(32)));
                  ir_if *f0257 = new(mem_ctx) ir_if(operand(r0258).val);
                  exec_list *const f0257_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0257->then_instructions;

                     body.emit(assign(r0250, lshift(swizzle_x(r01DF), r0253), 0x01));

                     ir_expression *const r0259 = lshift(r01EB, r0253);
                     ir_expression *const r025A = rshift(swizzle_x(r01DF), r024F);
                     body.emit(assign(r0251, bit_or(r0259, r025A), 0x01));

                     body.emit(assign(r0252, rshift(r01EB, r024F), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0257->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r025C = equal(r024F, body.constant(int(32)));
                     ir_if *f025B = new(mem_ctx) ir_if(operand(r025C).val);
                     exec_list *const f025B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f025B->then_instructions;

                        body.emit(assign(r0250, r01F0, 0x01));

                        body.emit(assign(r0251, r01EB, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f025B->else_instructions;

                        body.emit(assign(r024E, bit_or(body.constant(0u), swizzle_x(r01DF)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r025E = less(r024F, body.constant(int(64)));
                        ir_if *f025D = new(mem_ctx) ir_if(operand(r025E).val);
                        exec_list *const f025D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f025D->then_instructions;

                           body.emit(assign(r0250, lshift(r01EB, r0253), 0x01));

                           ir_expression *const r025F = bit_and(r024F, body.constant(int(31)));
                           body.emit(assign(r0251, rshift(r01EB, r025F), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f025D->else_instructions;

                           ir_variable *const r0260 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0262 = equal(r024F, body.constant(int(64)));
                           ir_if *f0261 = new(mem_ctx) ir_if(operand(r0262).val);
                           exec_list *const f0261_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0261->then_instructions;

                              body.emit(assign(r0260, r01EB, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0261->else_instructions;

                              ir_expression *const r0263 = nequal(r01EB, body.constant(0u));
                              ir_expression *const r0264 = expr(ir_unop_b2i, r0263);
                              body.emit(assign(r0260, expr(ir_unop_i2u, r0264), 0x01));


                           body.instructions = f0261_parent_instructions;
                           body.emit(f0261);

                           /* END IF */

                           body.emit(assign(r0250, r0260, 0x01));

                           body.emit(assign(r0251, body.constant(0u), 0x01));


                        body.instructions = f025D_parent_instructions;
                        body.emit(f025D);

                        /* END IF */


                     body.instructions = f025B_parent_instructions;
                     body.emit(f025B);

                     /* END IF */

                     body.emit(assign(r0252, body.constant(0u), 0x01));


                  body.instructions = f0257_parent_instructions;
                  body.emit(f0257);

                  /* END IF */

                  ir_expression *const r0265 = nequal(r024E, body.constant(0u));
                  ir_expression *const r0266 = expr(ir_unop_b2i, r0265);
                  ir_expression *const r0267 = expr(ir_unop_i2u, r0266);
                  body.emit(assign(r0250, bit_or(r0250, r0267), 0x01));


               body.instructions = f0255_parent_instructions;
               body.emit(f0255);

               /* END IF */

               body.emit(assign(r01EB, r0252, 0x01));

               body.emit(assign(r01EC, r0251, 0x01));

               body.emit(assign(r01EE, r0250, 0x01));

               body.emit(assign(r01ED, r01F7, 0x01));


            body.instructions = f0232_parent_instructions;
            body.emit(f0232);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0230->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0269 = equal(r01F4, body.constant(int(2047)));
            ir_if *f0268 = new(mem_ctx) ir_if(operand(r0269).val);
            exec_list *const f0268_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0268->then_instructions;

               /* IF CONDITION */
               ir_expression *const r026B = bit_or(r01EB, r01EC);
               ir_expression *const r026C = bit_or(r01E9, r01EA);
               ir_expression *const r026D = bit_or(r026B, r026C);
               ir_expression *const r026E = nequal(r026D, body.constant(0u));
               ir_if *f026A = new(mem_ctx) ir_if(operand(r026E).val);
               exec_list *const f026A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f026A->then_instructions;

                  ir_variable *const r026F = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r026F, swizzle_x(r01DF), 0x01));

                  ir_variable *const r0270 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0270, swizzle_x(r01E0), 0x01));

                  body.emit(assign(r026F, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

                  body.emit(assign(r0270, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

                  ir_expression *const r0271 = lshift(swizzle_y(r01DF), body.constant(int(1)));
                  ir_expression *const r0272 = gequal(r0271, body.constant(4292870144u));
                  ir_expression *const r0273 = nequal(swizzle_x(r01DF), body.constant(0u));
                  ir_expression *const r0274 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
                  ir_expression *const r0275 = nequal(r0274, body.constant(0u));
                  ir_expression *const r0276 = logic_or(r0273, r0275);
                  ir_expression *const r0277 = logic_and(r0272, r0276);
                  ir_swizzle *const r0278 = swizzle(r0277, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0279 = lshift(swizzle_y(r01E0), body.constant(int(1)));
                  ir_expression *const r027A = gequal(r0279, body.constant(4292870144u));
                  ir_expression *const r027B = nequal(swizzle_x(r01E0), body.constant(0u));
                  ir_expression *const r027C = bit_and(swizzle_y(r01E0), body.constant(1048575u));
                  ir_expression *const r027D = nequal(r027C, body.constant(0u));
                  ir_expression *const r027E = logic_or(r027B, r027D);
                  ir_expression *const r027F = logic_and(r027A, r027E);
                  ir_swizzle *const r0280 = swizzle(r027F, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0281 = expr(ir_triop_csel, r0280, r0270, r026F);
                  body.emit(assign(r01E2, expr(ir_triop_csel, r0278, r0281, r0270), 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f026A->else_instructions;

                  body.emit(assign(r01E2, r01DF, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f026A_parent_instructions;
               body.emit(f026A);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0268->else_instructions;

               ir_variable *const r0282 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0283 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0283, add(r01EC, r01EA), 0x01));

               ir_expression *const r0284 = add(r01EB, r01E9);
               ir_expression *const r0285 = less(r0283, r01EC);
               ir_expression *const r0286 = expr(ir_unop_b2i, r0285);
               ir_expression *const r0287 = expr(ir_unop_i2u, r0286);
               body.emit(assign(r0282, add(r0284, r0287), 0x01));

               body.emit(assign(r01EF, r0282, 0x01));

               /* IF CONDITION */
               ir_expression *const r0289 = equal(r01F4, body.constant(int(0)));
               ir_if *f0288 = new(mem_ctx) ir_if(operand(r0289).val);
               exec_list *const f0288_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0288->then_instructions;

                  ir_variable *const r028A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r028A);
                  ir_expression *const r028B = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r028A, add(r028B, r0282), 0x02));

                  body.emit(assign(r028A, r0283, 0x01));

                  body.emit(assign(r01E2, r028A, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0288->else_instructions;

                  body.emit(assign(r01EF, bit_or(r0282, body.constant(2097152u)), 0x01));

                  body.emit(assign(r01ED, r01F4, 0x01));

                  ir_variable *const r028C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r028C);
                  ir_variable *const r028D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r028D);
                  ir_variable *const r028E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r028E);
                  body.emit(assign(r028C, lshift(r0283, body.constant(int(31))), 0x01));

                  ir_expression *const r028F = lshift(r01EF, body.constant(int(31)));
                  ir_expression *const r0290 = rshift(r0283, body.constant(int(1)));
                  body.emit(assign(r028D, bit_or(r028F, r0290), 0x01));

                  body.emit(assign(r028E, rshift(r01EF, body.constant(int(1))), 0x01));

                  body.emit(assign(r028C, bit_or(r028C, body.constant(0u)), 0x01));

                  body.emit(assign(r01EF, r028E, 0x01));

                  body.emit(assign(r01EE, r028C, 0x01));

                  ir_variable *const r0291 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0291, r01F4, 0x01));

                  ir_variable *const r0292 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0292, r028E, 0x01));

                  ir_variable *const r0293 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0293, r028D, 0x01));

                  ir_variable *const r0294 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0294, r028C, 0x01));

                  ir_variable *const r0295 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0295, body.constant(true), 0x01));

                  ir_variable *const r0296 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0297 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r0297);
                  ir_expression *const r0298 = expr(ir_unop_u2i, r028C);
                  body.emit(assign(r0297, less(r0298, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r029A = gequal(r01F4, body.constant(int(2045)));
                  ir_if *f0299 = new(mem_ctx) ir_if(operand(r029A).val);
                  exec_list *const f0299_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0299->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r029C = less(body.constant(int(2045)), r01F4);
                     ir_expression *const r029D = equal(r01F4, body.constant(int(2045)));
                     ir_expression *const r029E = equal(body.constant(2097151u), r028E);
                     ir_expression *const r029F = equal(body.constant(4294967295u), r028D);
                     ir_expression *const r02A0 = logic_and(r029E, r029F);
                     ir_expression *const r02A1 = logic_and(r029D, r02A0);
                     ir_expression *const r02A2 = logic_and(r02A1, r0297);
                     ir_expression *const r02A3 = logic_or(r029C, r02A2);
                     ir_if *f029B = new(mem_ctx) ir_if(operand(r02A3).val);
                     exec_list *const f029B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f029B->then_instructions;

                        ir_variable *const r02A4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r02A4);
                        ir_expression *const r02A5 = lshift(r01E4, body.constant(int(31)));
                        body.emit(assign(r02A4, add(r02A5, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r02A4, body.constant(0u), 0x01));

                        body.emit(assign(r0296, r02A4, 0x03));

                        body.emit(assign(r0295, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f029B->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02A7 = less(r01F4, body.constant(int(0)));
                        ir_if *f02A6 = new(mem_ctx) ir_if(operand(r02A7).val);
                        exec_list *const f02A6_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02A6->then_instructions;

                           ir_variable *const r02A8 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r02A8, r028C, 0x01));

                           ir_variable *const r02A9 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r02A9, neg(r01F4), 0x01));

                           ir_variable *const r02AA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r02AA);
                           ir_variable *const r02AB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r02AB);
                           ir_variable *const r02AC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r02AC);
                           ir_variable *const r02AD = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02AE = neg(r02A9);
                           body.emit(assign(r02AD, bit_and(r02AE, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02B0 = equal(r02A9, body.constant(int(0)));
                           ir_if *f02AF = new(mem_ctx) ir_if(operand(r02B0).val);
                           exec_list *const f02AF_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02AF->then_instructions;

                              body.emit(assign(r02AA, r028C, 0x01));

                              body.emit(assign(r02AB, r028D, 0x01));

                              body.emit(assign(r02AC, r028E, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02AF->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02B2 = less(r02A9, body.constant(int(32)));
                              ir_if *f02B1 = new(mem_ctx) ir_if(operand(r02B2).val);
                              exec_list *const f02B1_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02B1->then_instructions;

                                 body.emit(assign(r02AA, lshift(r028D, r02AD), 0x01));

                                 ir_expression *const r02B3 = lshift(r028E, r02AD);
                                 ir_expression *const r02B4 = rshift(r028D, r02A9);
                                 body.emit(assign(r02AB, bit_or(r02B3, r02B4), 0x01));

                                 body.emit(assign(r02AC, rshift(r028E, r02A9), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02B1->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02B6 = equal(r02A9, body.constant(int(32)));
                                 ir_if *f02B5 = new(mem_ctx) ir_if(operand(r02B6).val);
                                 exec_list *const f02B5_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02B5->then_instructions;

                                    body.emit(assign(r02AA, r028D, 0x01));

                                    body.emit(assign(r02AB, r028E, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02B5->else_instructions;

                                    body.emit(assign(r02A8, bit_or(r028C, r028D), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r02B8 = less(r02A9, body.constant(int(64)));
                                    ir_if *f02B7 = new(mem_ctx) ir_if(operand(r02B8).val);
                                    exec_list *const f02B7_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f02B7->then_instructions;

                                       body.emit(assign(r02AA, lshift(r028E, r02AD), 0x01));

                                       ir_expression *const r02B9 = bit_and(r02A9, body.constant(int(31)));
                                       body.emit(assign(r02AB, rshift(r028E, r02B9), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f02B7->else_instructions;

                                       ir_variable *const r02BA = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r02BC = equal(r02A9, body.constant(int(64)));
                                       ir_if *f02BB = new(mem_ctx) ir_if(operand(r02BC).val);
                                       exec_list *const f02BB_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f02BB->then_instructions;

                                          body.emit(assign(r02BA, r028E, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f02BB->else_instructions;

                                          ir_expression *const r02BD = nequal(r028E, body.constant(0u));
                                          ir_expression *const r02BE = expr(ir_unop_b2i, r02BD);
                                          body.emit(assign(r02BA, expr(ir_unop_i2u, r02BE), 0x01));


                                       body.instructions = f02BB_parent_instructions;
                                       body.emit(f02BB);

                                       /* END IF */

                                       body.emit(assign(r02AA, r02BA, 0x01));

                                       body.emit(assign(r02AB, body.constant(0u), 0x01));


                                    body.instructions = f02B7_parent_instructions;
                                    body.emit(f02B7);

                                    /* END IF */


                                 body.instructions = f02B5_parent_instructions;
                                 body.emit(f02B5);

                                 /* END IF */

                                 body.emit(assign(r02AC, body.constant(0u), 0x01));


                              body.instructions = f02B1_parent_instructions;
                              body.emit(f02B1);

                              /* END IF */

                              ir_expression *const r02BF = nequal(r02A8, body.constant(0u));
                              ir_expression *const r02C0 = expr(ir_unop_b2i, r02BF);
                              ir_expression *const r02C1 = expr(ir_unop_i2u, r02C0);
                              body.emit(assign(r02AA, bit_or(r02AA, r02C1), 0x01));


                           body.instructions = f02AF_parent_instructions;
                           body.emit(f02AF);

                           /* END IF */

                           body.emit(assign(r0292, r02AC, 0x01));

                           body.emit(assign(r0293, r02AB, 0x01));

                           body.emit(assign(r0294, r02AA, 0x01));

                           body.emit(assign(r0291, body.constant(int(0)), 0x01));

                           body.emit(assign(r0297, less(r02AA, body.constant(0u)), 0x01));


                        body.instructions = f02A6_parent_instructions;
                        body.emit(f02A6);

                        /* END IF */


                     body.instructions = f029B_parent_instructions;
                     body.emit(f029B);

                     /* END IF */


                  body.instructions = f0299_parent_instructions;
                  body.emit(f0299);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02C2 = new(mem_ctx) ir_if(operand(r0295).val);
                  exec_list *const f02C2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02C2->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02C3 = new(mem_ctx) ir_if(operand(r0297).val);
                     exec_list *const f02C3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02C3->then_instructions;

                        ir_variable *const r02C4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02C4, add(r0293, body.constant(1u)), 0x01));

                        ir_expression *const r02C5 = less(r02C4, r0293);
                        ir_expression *const r02C6 = expr(ir_unop_b2i, r02C5);
                        ir_expression *const r02C7 = expr(ir_unop_i2u, r02C6);
                        body.emit(assign(r0292, add(r0292, r02C7), 0x01));

                        ir_expression *const r02C8 = equal(r0294, body.constant(0u));
                        ir_expression *const r02C9 = expr(ir_unop_b2i, r02C8);
                        ir_expression *const r02CA = expr(ir_unop_i2u, r02C9);
                        ir_expression *const r02CB = add(r0294, r02CA);
                        ir_expression *const r02CC = bit_and(r02CB, body.constant(1u));
                        ir_expression *const r02CD = expr(ir_unop_bit_not, r02CC);
                        body.emit(assign(r0293, bit_and(r02C4, r02CD), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02C3->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02CF = bit_or(r0292, r0293);
                        ir_expression *const r02D0 = equal(r02CF, body.constant(0u));
                        ir_if *f02CE = new(mem_ctx) ir_if(operand(r02D0).val);
                        exec_list *const f02CE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02CE->then_instructions;

                           body.emit(assign(r0291, body.constant(int(0)), 0x01));


                        body.instructions = f02CE_parent_instructions;
                        body.emit(f02CE);

                        /* END IF */


                     body.instructions = f02C3_parent_instructions;
                     body.emit(f02C3);

                     /* END IF */

                     ir_variable *const r02D1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r02D1);
                     ir_expression *const r02D2 = lshift(r01E4, body.constant(int(31)));
                     ir_expression *const r02D3 = expr(ir_unop_i2u, r0291);
                     ir_expression *const r02D4 = lshift(r02D3, body.constant(int(20)));
                     ir_expression *const r02D5 = add(r02D2, r02D4);
                     body.emit(assign(r02D1, add(r02D5, r0292), 0x02));

                     body.emit(assign(r02D1, r0293, 0x01));

                     body.emit(assign(r0296, r02D1, 0x03));

                     body.emit(assign(r0295, body.constant(false), 0x01));


                  body.instructions = f02C2_parent_instructions;
                  body.emit(f02C2);

                  /* END IF */

                  body.emit(assign(r01E2, r0296, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f0288_parent_instructions;
               body.emit(f0288);

               /* END IF */


            body.instructions = f0268_parent_instructions;
            body.emit(f0268);

            /* END IF */


         body.instructions = f0230_parent_instructions;
         body.emit(f0230);

         /* END IF */


      body.instructions = f01FB_parent_instructions;
      body.emit(f01FB);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02D6 = new(mem_ctx) ir_if(operand(r01E1).val);
      exec_list *const f02D6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02D6->then_instructions;

         body.emit(assign(r01EB, bit_or(r01EB, body.constant(1048576u)), 0x01));

         ir_variable *const r02D7 = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r02D8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r02D8, add(r01EC, r01EA), 0x01));

         ir_expression *const r02D9 = add(r01EB, r01E9);
         ir_expression *const r02DA = less(r02D8, r01EC);
         ir_expression *const r02DB = expr(ir_unop_b2i, r02DA);
         ir_expression *const r02DC = expr(ir_unop_i2u, r02DB);
         body.emit(assign(r02D7, add(r02D9, r02DC), 0x01));

         body.emit(assign(r01EF, r02D7, 0x01));

         body.emit(assign(r01ED, add(r01ED, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r02DE = less(r02D7, body.constant(2097152u));
         ir_if *f02DD = new(mem_ctx) ir_if(operand(r02DE).val);
         exec_list *const f02DD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02DD->then_instructions;

            ir_variable *const r02DF = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r02DF, r01ED, 0x01));

            ir_variable *const r02E0 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r02E0, r02D7, 0x01));

            ir_variable *const r02E1 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r02E1, r02D8, 0x01));

            ir_variable *const r02E2 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r02E2, r01EE, 0x01));

            ir_variable *const r02E3 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r02E3, body.constant(true), 0x01));

            ir_variable *const r02E4 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r02E5 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r02E5);
            ir_expression *const r02E6 = expr(ir_unop_u2i, r01EE);
            body.emit(assign(r02E5, less(r02E6, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02E8 = gequal(r01ED, body.constant(int(2045)));
            ir_if *f02E7 = new(mem_ctx) ir_if(operand(r02E8).val);
            exec_list *const f02E7_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02E7->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02EA = less(body.constant(int(2045)), r01ED);
               ir_expression *const r02EB = equal(r01ED, body.constant(int(2045)));
               ir_expression *const r02EC = equal(body.constant(2097151u), r02D7);
               ir_expression *const r02ED = equal(body.constant(4294967295u), r02D8);
               ir_expression *const r02EE = logic_and(r02EC, r02ED);
               ir_expression *const r02EF = logic_and(r02EB, r02EE);
               ir_expression *const r02F0 = logic_and(r02EF, r02E5);
               ir_expression *const r02F1 = logic_or(r02EA, r02F0);
               ir_if *f02E9 = new(mem_ctx) ir_if(operand(r02F1).val);
               exec_list *const f02E9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02E9->then_instructions;

                  ir_variable *const r02F2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02F2);
                  ir_expression *const r02F3 = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r02F2, add(r02F3, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r02F2, body.constant(0u), 0x01));

                  body.emit(assign(r02E4, r02F2, 0x03));

                  body.emit(assign(r02E3, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02E9->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r02F5 = less(r01ED, body.constant(int(0)));
                  ir_if *f02F4 = new(mem_ctx) ir_if(operand(r02F5).val);
                  exec_list *const f02F4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02F4->then_instructions;

                     ir_variable *const r02F6 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r02F6, r01EE, 0x01));

                     ir_variable *const r02F7 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r02F7, neg(r01ED), 0x01));

                     ir_variable *const r02F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r02F8);
                     ir_variable *const r02F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r02F9);
                     ir_variable *const r02FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r02FA);
                     ir_variable *const r02FB = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r02FC = neg(r02F7);
                     body.emit(assign(r02FB, bit_and(r02FC, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r02FE = equal(r02F7, body.constant(int(0)));
                     ir_if *f02FD = new(mem_ctx) ir_if(operand(r02FE).val);
                     exec_list *const f02FD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02FD->then_instructions;

                        body.emit(assign(r02F8, r01EE, 0x01));

                        body.emit(assign(r02F9, r02D8, 0x01));

                        body.emit(assign(r02FA, r02D7, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02FD->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0300 = less(r02F7, body.constant(int(32)));
                        ir_if *f02FF = new(mem_ctx) ir_if(operand(r0300).val);
                        exec_list *const f02FF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02FF->then_instructions;

                           body.emit(assign(r02F8, lshift(r02D8, r02FB), 0x01));

                           ir_expression *const r0301 = lshift(r02D7, r02FB);
                           ir_expression *const r0302 = rshift(r02D8, r02F7);
                           body.emit(assign(r02F9, bit_or(r0301, r0302), 0x01));

                           body.emit(assign(r02FA, rshift(r02D7, r02F7), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f02FF->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0304 = equal(r02F7, body.constant(int(32)));
                           ir_if *f0303 = new(mem_ctx) ir_if(operand(r0304).val);
                           exec_list *const f0303_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0303->then_instructions;

                              body.emit(assign(r02F8, r02D8, 0x01));

                              body.emit(assign(r02F9, r02D7, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0303->else_instructions;

                              body.emit(assign(r02F6, bit_or(r01EE, r02D8), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0306 = less(r02F7, body.constant(int(64)));
                              ir_if *f0305 = new(mem_ctx) ir_if(operand(r0306).val);
                              exec_list *const f0305_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0305->then_instructions;

                                 body.emit(assign(r02F8, lshift(r02D7, r02FB), 0x01));

                                 ir_expression *const r0307 = bit_and(r02F7, body.constant(int(31)));
                                 body.emit(assign(r02F9, rshift(r02D7, r0307), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0305->else_instructions;

                                 ir_variable *const r0308 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r030A = equal(r02F7, body.constant(int(64)));
                                 ir_if *f0309 = new(mem_ctx) ir_if(operand(r030A).val);
                                 exec_list *const f0309_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0309->then_instructions;

                                    body.emit(assign(r0308, r02D7, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0309->else_instructions;

                                    ir_expression *const r030B = nequal(r02D7, body.constant(0u));
                                    ir_expression *const r030C = expr(ir_unop_b2i, r030B);
                                    body.emit(assign(r0308, expr(ir_unop_i2u, r030C), 0x01));


                                 body.instructions = f0309_parent_instructions;
                                 body.emit(f0309);

                                 /* END IF */

                                 body.emit(assign(r02F8, r0308, 0x01));

                                 body.emit(assign(r02F9, body.constant(0u), 0x01));


                              body.instructions = f0305_parent_instructions;
                              body.emit(f0305);

                              /* END IF */


                           body.instructions = f0303_parent_instructions;
                           body.emit(f0303);

                           /* END IF */

                           body.emit(assign(r02FA, body.constant(0u), 0x01));


                        body.instructions = f02FF_parent_instructions;
                        body.emit(f02FF);

                        /* END IF */

                        ir_expression *const r030D = nequal(r02F6, body.constant(0u));
                        ir_expression *const r030E = expr(ir_unop_b2i, r030D);
                        ir_expression *const r030F = expr(ir_unop_i2u, r030E);
                        body.emit(assign(r02F8, bit_or(r02F8, r030F), 0x01));


                     body.instructions = f02FD_parent_instructions;
                     body.emit(f02FD);

                     /* END IF */

                     body.emit(assign(r02E0, r02FA, 0x01));

                     body.emit(assign(r02E1, r02F9, 0x01));

                     body.emit(assign(r02E2, r02F8, 0x01));

                     body.emit(assign(r02DF, body.constant(int(0)), 0x01));

                     body.emit(assign(r02E5, less(r02F8, body.constant(0u)), 0x01));


                  body.instructions = f02F4_parent_instructions;
                  body.emit(f02F4);

                  /* END IF */


               body.instructions = f02E9_parent_instructions;
               body.emit(f02E9);

               /* END IF */


            body.instructions = f02E7_parent_instructions;
            body.emit(f02E7);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0310 = new(mem_ctx) ir_if(operand(r02E3).val);
            exec_list *const f0310_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0310->then_instructions;

               /* IF CONDITION */
               ir_if *f0311 = new(mem_ctx) ir_if(operand(r02E5).val);
               exec_list *const f0311_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0311->then_instructions;

                  ir_variable *const r0312 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0312, add(r02E1, body.constant(1u)), 0x01));

                  ir_expression *const r0313 = less(r0312, r02E1);
                  ir_expression *const r0314 = expr(ir_unop_b2i, r0313);
                  ir_expression *const r0315 = expr(ir_unop_i2u, r0314);
                  body.emit(assign(r02E0, add(r02E0, r0315), 0x01));

                  ir_expression *const r0316 = equal(r02E2, body.constant(0u));
                  ir_expression *const r0317 = expr(ir_unop_b2i, r0316);
                  ir_expression *const r0318 = expr(ir_unop_i2u, r0317);
                  ir_expression *const r0319 = add(r02E2, r0318);
                  ir_expression *const r031A = bit_and(r0319, body.constant(1u));
                  ir_expression *const r031B = expr(ir_unop_bit_not, r031A);
                  body.emit(assign(r02E1, bit_and(r0312, r031B), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0311->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r031D = bit_or(r02E0, r02E1);
                  ir_expression *const r031E = equal(r031D, body.constant(0u));
                  ir_if *f031C = new(mem_ctx) ir_if(operand(r031E).val);
                  exec_list *const f031C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f031C->then_instructions;

                     body.emit(assign(r02DF, body.constant(int(0)), 0x01));


                  body.instructions = f031C_parent_instructions;
                  body.emit(f031C);

                  /* END IF */


               body.instructions = f0311_parent_instructions;
               body.emit(f0311);

               /* END IF */

               ir_variable *const r031F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r031F);
               ir_expression *const r0320 = lshift(r01E4, body.constant(int(31)));
               ir_expression *const r0321 = expr(ir_unop_i2u, r02DF);
               ir_expression *const r0322 = lshift(r0321, body.constant(int(20)));
               ir_expression *const r0323 = add(r0320, r0322);
               body.emit(assign(r031F, add(r0323, r02E0), 0x02));

               body.emit(assign(r031F, r02E1, 0x01));

               body.emit(assign(r02E4, r031F, 0x03));

               body.emit(assign(r02E3, body.constant(false), 0x01));


            body.instructions = f0310_parent_instructions;
            body.emit(f0310);

            /* END IF */

            body.emit(assign(r01E2, r02E4, 0x03));

            body.emit(assign(r01E1, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02DD->else_instructions;

            body.emit(assign(r01ED, add(r01ED, body.constant(int(1))), 0x01));

            ir_variable *const r0324 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0324);
            ir_variable *const r0325 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0325);
            ir_variable *const r0326 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0326);
            body.emit(assign(r0324, lshift(r02D8, body.constant(int(31))), 0x01));

            ir_expression *const r0327 = lshift(r02D7, body.constant(int(31)));
            ir_expression *const r0328 = rshift(r02D8, body.constant(int(1)));
            body.emit(assign(r0325, bit_or(r0327, r0328), 0x01));

            body.emit(assign(r0326, rshift(r02D7, body.constant(int(1))), 0x01));

            ir_expression *const r0329 = nequal(r01EE, body.constant(0u));
            ir_expression *const r032A = expr(ir_unop_b2i, r0329);
            ir_expression *const r032B = expr(ir_unop_i2u, r032A);
            body.emit(assign(r0324, bit_or(r0324, r032B), 0x01));

            body.emit(assign(r01EF, r0326, 0x01));

            body.emit(assign(r01EE, r0324, 0x01));

            ir_variable *const r032C = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r032C, r01ED, 0x01));

            ir_variable *const r032D = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r032D, r0326, 0x01));

            ir_variable *const r032E = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r032E, r0325, 0x01));

            ir_variable *const r032F = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r032F, r0324, 0x01));

            ir_variable *const r0330 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0330, body.constant(true), 0x01));

            ir_variable *const r0331 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0332 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0332);
            ir_expression *const r0333 = expr(ir_unop_u2i, r0324);
            body.emit(assign(r0332, less(r0333, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0335 = gequal(r01ED, body.constant(int(2045)));
            ir_if *f0334 = new(mem_ctx) ir_if(operand(r0335).val);
            exec_list *const f0334_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0334->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0337 = less(body.constant(int(2045)), r01ED);
               ir_expression *const r0338 = equal(r01ED, body.constant(int(2045)));
               ir_expression *const r0339 = equal(body.constant(2097151u), r0326);
               ir_expression *const r033A = equal(body.constant(4294967295u), r0325);
               ir_expression *const r033B = logic_and(r0339, r033A);
               ir_expression *const r033C = logic_and(r0338, r033B);
               ir_expression *const r033D = logic_and(r033C, r0332);
               ir_expression *const r033E = logic_or(r0337, r033D);
               ir_if *f0336 = new(mem_ctx) ir_if(operand(r033E).val);
               exec_list *const f0336_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0336->then_instructions;

                  ir_variable *const r033F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r033F);
                  ir_expression *const r0340 = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r033F, add(r0340, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r033F, body.constant(0u), 0x01));

                  body.emit(assign(r0331, r033F, 0x03));

                  body.emit(assign(r0330, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0336->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0342 = less(r01ED, body.constant(int(0)));
                  ir_if *f0341 = new(mem_ctx) ir_if(operand(r0342).val);
                  exec_list *const f0341_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0341->then_instructions;

                     ir_variable *const r0343 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0343, r0324, 0x01));

                     ir_variable *const r0344 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0344, neg(r01ED), 0x01));

                     ir_variable *const r0345 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0345);
                     ir_variable *const r0346 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0346);
                     ir_variable *const r0347 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0347);
                     ir_variable *const r0348 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0349 = neg(r0344);
                     body.emit(assign(r0348, bit_and(r0349, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r034B = equal(r0344, body.constant(int(0)));
                     ir_if *f034A = new(mem_ctx) ir_if(operand(r034B).val);
                     exec_list *const f034A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f034A->then_instructions;

                        body.emit(assign(r0345, r0324, 0x01));

                        body.emit(assign(r0346, r0325, 0x01));

                        body.emit(assign(r0347, r0326, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f034A->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r034D = less(r0344, body.constant(int(32)));
                        ir_if *f034C = new(mem_ctx) ir_if(operand(r034D).val);
                        exec_list *const f034C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f034C->then_instructions;

                           body.emit(assign(r0345, lshift(r0325, r0348), 0x01));

                           ir_expression *const r034E = lshift(r0326, r0348);
                           ir_expression *const r034F = rshift(r0325, r0344);
                           body.emit(assign(r0346, bit_or(r034E, r034F), 0x01));

                           body.emit(assign(r0347, rshift(r0326, r0344), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f034C->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0351 = equal(r0344, body.constant(int(32)));
                           ir_if *f0350 = new(mem_ctx) ir_if(operand(r0351).val);
                           exec_list *const f0350_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0350->then_instructions;

                              body.emit(assign(r0345, r0325, 0x01));

                              body.emit(assign(r0346, r0326, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0350->else_instructions;

                              body.emit(assign(r0343, bit_or(r0324, r0325), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0353 = less(r0344, body.constant(int(64)));
                              ir_if *f0352 = new(mem_ctx) ir_if(operand(r0353).val);
                              exec_list *const f0352_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0352->then_instructions;

                                 body.emit(assign(r0345, lshift(r0326, r0348), 0x01));

                                 ir_expression *const r0354 = bit_and(r0344, body.constant(int(31)));
                                 body.emit(assign(r0346, rshift(r0326, r0354), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0352->else_instructions;

                                 ir_variable *const r0355 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0357 = equal(r0344, body.constant(int(64)));
                                 ir_if *f0356 = new(mem_ctx) ir_if(operand(r0357).val);
                                 exec_list *const f0356_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0356->then_instructions;

                                    body.emit(assign(r0355, r0326, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0356->else_instructions;

                                    ir_expression *const r0358 = nequal(r0326, body.constant(0u));
                                    ir_expression *const r0359 = expr(ir_unop_b2i, r0358);
                                    body.emit(assign(r0355, expr(ir_unop_i2u, r0359), 0x01));


                                 body.instructions = f0356_parent_instructions;
                                 body.emit(f0356);

                                 /* END IF */

                                 body.emit(assign(r0345, r0355, 0x01));

                                 body.emit(assign(r0346, body.constant(0u), 0x01));


                              body.instructions = f0352_parent_instructions;
                              body.emit(f0352);

                              /* END IF */


                           body.instructions = f0350_parent_instructions;
                           body.emit(f0350);

                           /* END IF */

                           body.emit(assign(r0347, body.constant(0u), 0x01));


                        body.instructions = f034C_parent_instructions;
                        body.emit(f034C);

                        /* END IF */

                        ir_expression *const r035A = nequal(r0343, body.constant(0u));
                        ir_expression *const r035B = expr(ir_unop_b2i, r035A);
                        ir_expression *const r035C = expr(ir_unop_i2u, r035B);
                        body.emit(assign(r0345, bit_or(r0345, r035C), 0x01));


                     body.instructions = f034A_parent_instructions;
                     body.emit(f034A);

                     /* END IF */

                     body.emit(assign(r032D, r0347, 0x01));

                     body.emit(assign(r032E, r0346, 0x01));

                     body.emit(assign(r032F, r0345, 0x01));

                     body.emit(assign(r032C, body.constant(int(0)), 0x01));

                     body.emit(assign(r0332, less(r0345, body.constant(0u)), 0x01));


                  body.instructions = f0341_parent_instructions;
                  body.emit(f0341);

                  /* END IF */


               body.instructions = f0336_parent_instructions;
               body.emit(f0336);

               /* END IF */


            body.instructions = f0334_parent_instructions;
            body.emit(f0334);

            /* END IF */

            /* IF CONDITION */
            ir_if *f035D = new(mem_ctx) ir_if(operand(r0330).val);
            exec_list *const f035D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f035D->then_instructions;

               /* IF CONDITION */
               ir_if *f035E = new(mem_ctx) ir_if(operand(r0332).val);
               exec_list *const f035E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f035E->then_instructions;

                  ir_variable *const r035F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r035F, add(r032E, body.constant(1u)), 0x01));

                  ir_expression *const r0360 = less(r035F, r032E);
                  ir_expression *const r0361 = expr(ir_unop_b2i, r0360);
                  ir_expression *const r0362 = expr(ir_unop_i2u, r0361);
                  body.emit(assign(r032D, add(r032D, r0362), 0x01));

                  ir_expression *const r0363 = equal(r032F, body.constant(0u));
                  ir_expression *const r0364 = expr(ir_unop_b2i, r0363);
                  ir_expression *const r0365 = expr(ir_unop_i2u, r0364);
                  ir_expression *const r0366 = add(r032F, r0365);
                  ir_expression *const r0367 = bit_and(r0366, body.constant(1u));
                  ir_expression *const r0368 = expr(ir_unop_bit_not, r0367);
                  body.emit(assign(r032E, bit_and(r035F, r0368), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f035E->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r036A = bit_or(r032D, r032E);
                  ir_expression *const r036B = equal(r036A, body.constant(0u));
                  ir_if *f0369 = new(mem_ctx) ir_if(operand(r036B).val);
                  exec_list *const f0369_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0369->then_instructions;

                     body.emit(assign(r032C, body.constant(int(0)), 0x01));


                  body.instructions = f0369_parent_instructions;
                  body.emit(f0369);

                  /* END IF */


               body.instructions = f035E_parent_instructions;
               body.emit(f035E);

               /* END IF */

               ir_variable *const r036C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r036C);
               ir_expression *const r036D = lshift(r01E4, body.constant(int(31)));
               ir_expression *const r036E = expr(ir_unop_i2u, r032C);
               ir_expression *const r036F = lshift(r036E, body.constant(int(20)));
               ir_expression *const r0370 = add(r036D, r036F);
               body.emit(assign(r036C, add(r0370, r032D), 0x02));

               body.emit(assign(r036C, r032E, 0x01));

               body.emit(assign(r0331, r036C, 0x03));

               body.emit(assign(r0330, body.constant(false), 0x01));


            body.instructions = f035D_parent_instructions;
            body.emit(f035D);

            /* END IF */

            body.emit(assign(r01E2, r0331, 0x03));

            body.emit(assign(r01E1, body.constant(false), 0x01));


         body.instructions = f02DD_parent_instructions;
         body.emit(f02DD);

         /* END IF */


      body.instructions = f02D6_parent_instructions;
      body.emit(f02D6);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01E6->else_instructions;

      ir_variable *const r0371 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r0371);
      ir_variable *const r0372 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
      body.emit(r0372);
      ir_variable *const r0373 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
      body.emit(r0373);
      ir_variable *const r0374 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r0374);
      ir_variable *const r0375 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r0375);
      ir_variable *const r0376 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r0376);
      ir_variable *const r0377 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r0377);
      ir_variable *const r0378 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r0378);
      ir_variable *const r0379 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r037A = rshift(swizzle_y(r01DF), body.constant(int(20)));
      ir_expression *const r037B = bit_and(r037A, body.constant(2047u));
      body.emit(assign(r0379, expr(ir_unop_u2i, r037B), 0x01));

      body.emit(assign(r0373, r0379, 0x01));

      ir_variable *const r037C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r037D = rshift(swizzle_y(r01E0), body.constant(int(20)));
      ir_expression *const r037E = bit_and(r037D, body.constant(2047u));
      body.emit(assign(r037C, expr(ir_unop_u2i, r037E), 0x01));

      body.emit(assign(r0372, r037C, 0x01));

      body.emit(assign(r0371, sub(r0379, r037C), 0x01));

      ir_variable *const r037F = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r037F, lshift(swizzle_x(r01DF), body.constant(int(10))), 0x01));

      ir_variable *const r0380 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r0381 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
      ir_expression *const r0382 = lshift(r0381, body.constant(int(10)));
      ir_expression *const r0383 = rshift(swizzle_x(r01DF), body.constant(int(22)));
      body.emit(assign(r0380, bit_or(r0382, r0383), 0x01));

      body.emit(assign(r0376, r0380, 0x01));

      body.emit(assign(r0377, r037F, 0x01));

      ir_variable *const r0384 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0384, lshift(swizzle_x(r01E0), body.constant(int(10))), 0x01));

      ir_variable *const r0385 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r0386 = bit_and(swizzle_y(r01E0), body.constant(1048575u));
      ir_expression *const r0387 = lshift(r0386, body.constant(int(10)));
      ir_expression *const r0388 = rshift(swizzle_x(r01E0), body.constant(int(22)));
      body.emit(assign(r0385, bit_or(r0387, r0388), 0x01));

      body.emit(assign(r0374, r0385, 0x01));

      body.emit(assign(r0375, r0384, 0x01));

      /* IF CONDITION */
      ir_expression *const r038A = less(body.constant(int(0)), r0371);
      ir_if *f0389 = new(mem_ctx) ir_if(operand(r038A).val);
      exec_list *const f0389_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0389->then_instructions;

         /* IF CONDITION */
         ir_expression *const r038C = equal(r0379, body.constant(int(2047)));
         ir_if *f038B = new(mem_ctx) ir_if(operand(r038C).val);
         exec_list *const f038B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f038B->then_instructions;

            /* IF CONDITION */
            ir_expression *const r038E = bit_or(r0380, r037F);
            ir_expression *const r038F = nequal(r038E, body.constant(0u));
            ir_if *f038D = new(mem_ctx) ir_if(operand(r038F).val);
            exec_list *const f038D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f038D->then_instructions;

               ir_variable *const r0390 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0390, swizzle_x(r01DF), 0x01));

               ir_variable *const r0391 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0391, swizzle_x(r01E0), 0x01));

               body.emit(assign(r0390, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

               body.emit(assign(r0391, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

               ir_expression *const r0392 = lshift(swizzle_y(r01DF), body.constant(int(1)));
               ir_expression *const r0393 = gequal(r0392, body.constant(4292870144u));
               ir_expression *const r0394 = nequal(swizzle_x(r01DF), body.constant(0u));
               ir_expression *const r0395 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
               ir_expression *const r0396 = nequal(r0395, body.constant(0u));
               ir_expression *const r0397 = logic_or(r0394, r0396);
               ir_expression *const r0398 = logic_and(r0393, r0397);
               ir_swizzle *const r0399 = swizzle(r0398, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r039A = lshift(swizzle_y(r01E0), body.constant(int(1)));
               ir_expression *const r039B = gequal(r039A, body.constant(4292870144u));
               ir_expression *const r039C = nequal(swizzle_x(r01E0), body.constant(0u));
               ir_expression *const r039D = bit_and(swizzle_y(r01E0), body.constant(1048575u));
               ir_expression *const r039E = nequal(r039D, body.constant(0u));
               ir_expression *const r039F = logic_or(r039C, r039E);
               ir_expression *const r03A0 = logic_and(r039B, r039F);
               ir_swizzle *const r03A1 = swizzle(r03A0, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
               ir_expression *const r03A2 = expr(ir_triop_csel, r03A1, r0391, r0390);
               body.emit(assign(r01E2, expr(ir_triop_csel, r0399, r03A2, r0391), 0x03));

               body.emit(assign(r01E1, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f038D->else_instructions;

               body.emit(assign(r01E2, r01DF, 0x03));

               body.emit(assign(r01E1, body.constant(false), 0x01));


            body.instructions = f038D_parent_instructions;
            body.emit(f038D);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f038B->else_instructions;

            /* IF CONDITION */
            ir_expression *const r03A4 = equal(r037C, body.constant(int(0)));
            ir_if *f03A3 = new(mem_ctx) ir_if(operand(r03A4).val);
            exec_list *const f03A3_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03A3->then_instructions;

               body.emit(assign(r0371, add(r0371, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03A3->else_instructions;

               body.emit(assign(r0374, bit_or(r0385, body.constant(1073741824u)), 0x01));


            body.instructions = f03A3_parent_instructions;
            body.emit(f03A3);

            /* END IF */

            ir_variable *const r03A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r03A5);
            ir_variable *const r03A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r03A6);
            ir_variable *const r03A7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r03A8 = neg(r0371);
            body.emit(assign(r03A7, bit_and(r03A8, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03AA = equal(r0371, body.constant(int(0)));
            ir_if *f03A9 = new(mem_ctx) ir_if(operand(r03AA).val);
            exec_list *const f03A9_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03A9->then_instructions;

               body.emit(assign(r03A5, r0384, 0x01));

               body.emit(assign(r03A6, r0374, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03A9->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03AC = less(r0371, body.constant(int(32)));
               ir_if *f03AB = new(mem_ctx) ir_if(operand(r03AC).val);
               exec_list *const f03AB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03AB->then_instructions;

                  ir_expression *const r03AD = lshift(r0374, r03A7);
                  ir_expression *const r03AE = rshift(r0384, r0371);
                  ir_expression *const r03AF = bit_or(r03AD, r03AE);
                  ir_expression *const r03B0 = lshift(r0384, r03A7);
                  ir_expression *const r03B1 = nequal(r03B0, body.constant(0u));
                  ir_expression *const r03B2 = expr(ir_unop_b2i, r03B1);
                  ir_expression *const r03B3 = expr(ir_unop_i2u, r03B2);
                  body.emit(assign(r03A5, bit_or(r03AF, r03B3), 0x01));

                  body.emit(assign(r03A6, rshift(r0374, r0371), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03AB->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03B5 = equal(r0371, body.constant(int(32)));
                  ir_if *f03B4 = new(mem_ctx) ir_if(operand(r03B5).val);
                  exec_list *const f03B4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03B4->then_instructions;

                     ir_expression *const r03B6 = nequal(r0384, body.constant(0u));
                     ir_expression *const r03B7 = expr(ir_unop_b2i, r03B6);
                     ir_expression *const r03B8 = expr(ir_unop_i2u, r03B7);
                     body.emit(assign(r03A5, bit_or(r0374, r03B8), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03B4->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03BA = less(r0371, body.constant(int(64)));
                     ir_if *f03B9 = new(mem_ctx) ir_if(operand(r03BA).val);
                     exec_list *const f03B9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03B9->then_instructions;

                        ir_expression *const r03BB = bit_and(r0371, body.constant(int(31)));
                        ir_expression *const r03BC = rshift(r0374, r03BB);
                        ir_expression *const r03BD = lshift(r0374, r03A7);
                        ir_expression *const r03BE = bit_or(r03BD, r0384);
                        ir_expression *const r03BF = nequal(r03BE, body.constant(0u));
                        ir_expression *const r03C0 = expr(ir_unop_b2i, r03BF);
                        ir_expression *const r03C1 = expr(ir_unop_i2u, r03C0);
                        body.emit(assign(r03A5, bit_or(r03BC, r03C1), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03B9->else_instructions;

                        ir_expression *const r03C2 = bit_or(r0374, r0384);
                        ir_expression *const r03C3 = nequal(r03C2, body.constant(0u));
                        ir_expression *const r03C4 = expr(ir_unop_b2i, r03C3);
                        body.emit(assign(r03A5, expr(ir_unop_i2u, r03C4), 0x01));


                     body.instructions = f03B9_parent_instructions;
                     body.emit(f03B9);

                     /* END IF */


                  body.instructions = f03B4_parent_instructions;
                  body.emit(f03B4);

                  /* END IF */

                  body.emit(assign(r03A6, body.constant(0u), 0x01));


               body.instructions = f03AB_parent_instructions;
               body.emit(f03AB);

               /* END IF */


            body.instructions = f03A9_parent_instructions;
            body.emit(f03A9);

            /* END IF */

            body.emit(assign(r0374, r03A6, 0x01));

            body.emit(assign(r0375, r03A5, 0x01));

            body.emit(assign(r0376, bit_or(r0380, body.constant(1073741824u)), 0x01));

            ir_variable *const r03C5 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r03C6 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r03C6, sub(r037F, r03A5), 0x01));

            ir_expression *const r03C7 = sub(r0376, r03A6);
            ir_expression *const r03C8 = less(r037F, r03A5);
            ir_expression *const r03C9 = expr(ir_unop_b2i, r03C8);
            ir_expression *const r03CA = expr(ir_unop_i2u, r03C9);
            body.emit(assign(r03C5, sub(r03C7, r03CA), 0x01));

            body.emit(assign(r0378, add(r0379, body.constant(int(-1))), 0x01));

            ir_variable *const r03CB = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03CB, add(r0378, body.constant(int(-10))), 0x01));

            ir_variable *const r03CC = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03CC, r03C5, 0x01));

            ir_variable *const r03CD = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03CD, r03C6, 0x01));

            ir_variable *const r03CE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03CE);
            ir_variable *const r03CF = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03CF);
            /* IF CONDITION */
            ir_expression *const r03D1 = equal(r03C5, body.constant(0u));
            ir_if *f03D0 = new(mem_ctx) ir_if(operand(r03D1).val);
            exec_list *const f03D0_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03D0->then_instructions;

               body.emit(assign(r03CC, r03C6, 0x01));

               body.emit(assign(r03CD, body.constant(0u), 0x01));

               body.emit(assign(r03CB, add(r03CB, body.constant(int(-32))), 0x01));


            body.instructions = f03D0_parent_instructions;
            body.emit(f03D0);

            /* END IF */

            ir_variable *const r03D2 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r03D2, r03CC, 0x01));

            ir_variable *const r03D3 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r03D4 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03D4);
            /* IF CONDITION */
            ir_expression *const r03D6 = equal(r03CC, body.constant(0u));
            ir_if *f03D5 = new(mem_ctx) ir_if(operand(r03D6).val);
            exec_list *const f03D5_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03D5->then_instructions;

               body.emit(assign(r03D3, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03D5->else_instructions;

               body.emit(assign(r03D4, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r03D8 = bit_and(r03CC, body.constant(4294901760u));
               ir_expression *const r03D9 = equal(r03D8, body.constant(0u));
               ir_if *f03D7 = new(mem_ctx) ir_if(operand(r03D9).val);
               exec_list *const f03D7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03D7->then_instructions;

                  body.emit(assign(r03D4, body.constant(int(16)), 0x01));

                  body.emit(assign(r03D2, lshift(r03CC, body.constant(int(16))), 0x01));


               body.instructions = f03D7_parent_instructions;
               body.emit(f03D7);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03DB = bit_and(r03D2, body.constant(4278190080u));
               ir_expression *const r03DC = equal(r03DB, body.constant(0u));
               ir_if *f03DA = new(mem_ctx) ir_if(operand(r03DC).val);
               exec_list *const f03DA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03DA->then_instructions;

                  body.emit(assign(r03D4, add(r03D4, body.constant(int(8))), 0x01));

                  body.emit(assign(r03D2, lshift(r03D2, body.constant(int(8))), 0x01));


               body.instructions = f03DA_parent_instructions;
               body.emit(f03DA);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03DE = bit_and(r03D2, body.constant(4026531840u));
               ir_expression *const r03DF = equal(r03DE, body.constant(0u));
               ir_if *f03DD = new(mem_ctx) ir_if(operand(r03DF).val);
               exec_list *const f03DD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03DD->then_instructions;

                  body.emit(assign(r03D4, add(r03D4, body.constant(int(4))), 0x01));

                  body.emit(assign(r03D2, lshift(r03D2, body.constant(int(4))), 0x01));


               body.instructions = f03DD_parent_instructions;
               body.emit(f03DD);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03E1 = bit_and(r03D2, body.constant(3221225472u));
               ir_expression *const r03E2 = equal(r03E1, body.constant(0u));
               ir_if *f03E0 = new(mem_ctx) ir_if(operand(r03E2).val);
               exec_list *const f03E0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E0->then_instructions;

                  body.emit(assign(r03D4, add(r03D4, body.constant(int(2))), 0x01));

                  body.emit(assign(r03D2, lshift(r03D2, body.constant(int(2))), 0x01));


               body.instructions = f03E0_parent_instructions;
               body.emit(f03E0);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03E4 = bit_and(r03D2, body.constant(2147483648u));
               ir_expression *const r03E5 = equal(r03E4, body.constant(0u));
               ir_if *f03E3 = new(mem_ctx) ir_if(operand(r03E5).val);
               exec_list *const f03E3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E3->then_instructions;

                  body.emit(assign(r03D4, add(r03D4, body.constant(int(1))), 0x01));


               body.instructions = f03E3_parent_instructions;
               body.emit(f03E3);

               /* END IF */

               body.emit(assign(r03D3, r03D4, 0x01));


            body.instructions = f03D5_parent_instructions;
            body.emit(f03D5);

            /* END IF */

            body.emit(assign(r03CF, add(r03D3, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03E7 = gequal(r03CF, body.constant(int(0)));
            ir_if *f03E6 = new(mem_ctx) ir_if(operand(r03E7).val);
            exec_list *const f03E6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03E6->then_instructions;

               body.emit(assign(r03CE, body.constant(0u), 0x01));

               ir_variable *const r03E8 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r03E8, lshift(r03CD, r03CF), 0x01));

               ir_variable *const r03E9 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r03EB = equal(r03CF, body.constant(int(0)));
               ir_if *f03EA = new(mem_ctx) ir_if(operand(r03EB).val);
               exec_list *const f03EA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03EA->then_instructions;

                  body.emit(assign(r03E9, r03CC, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03EA->else_instructions;

                  ir_expression *const r03EC = lshift(r03CC, r03CF);
                  ir_expression *const r03ED = neg(r03CF);
                  ir_expression *const r03EE = bit_and(r03ED, body.constant(int(31)));
                  ir_expression *const r03EF = rshift(r03CD, r03EE);
                  body.emit(assign(r03E9, bit_or(r03EC, r03EF), 0x01));


               body.instructions = f03EA_parent_instructions;
               body.emit(f03EA);

               /* END IF */

               body.emit(assign(r03CC, r03E9, 0x01));

               body.emit(assign(r03CD, r03E8, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03E6->else_instructions;

               ir_variable *const r03F0 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r03F0, body.constant(0u), 0x01));

               ir_variable *const r03F1 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r03F1, neg(r03CF), 0x01));

               ir_variable *const r03F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r03F2);
               ir_variable *const r03F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r03F3);
               ir_variable *const r03F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r03F4);
               ir_variable *const r03F5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r03F6 = neg(r03F1);
               body.emit(assign(r03F5, bit_and(r03F6, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r03F8 = equal(r03F1, body.constant(int(0)));
               ir_if *f03F7 = new(mem_ctx) ir_if(operand(r03F8).val);
               exec_list *const f03F7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F7->then_instructions;

                  body.emit(assign(r03F2, r03F0, 0x01));

                  body.emit(assign(r03F3, r03CD, 0x01));

                  body.emit(assign(r03F4, r03CC, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03F7->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03FA = less(r03F1, body.constant(int(32)));
                  ir_if *f03F9 = new(mem_ctx) ir_if(operand(r03FA).val);
                  exec_list *const f03F9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03F9->then_instructions;

                     body.emit(assign(r03F2, lshift(r03CD, r03F5), 0x01));

                     ir_expression *const r03FB = lshift(r03CC, r03F5);
                     ir_expression *const r03FC = rshift(r03CD, r03F1);
                     body.emit(assign(r03F3, bit_or(r03FB, r03FC), 0x01));

                     body.emit(assign(r03F4, rshift(r03CC, r03F1), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03F9->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03FE = equal(r03F1, body.constant(int(32)));
                     ir_if *f03FD = new(mem_ctx) ir_if(operand(r03FE).val);
                     exec_list *const f03FD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03FD->then_instructions;

                        body.emit(assign(r03F2, r03CD, 0x01));

                        body.emit(assign(r03F3, r03CC, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03FD->else_instructions;

                        body.emit(assign(r03F0, bit_or(body.constant(0u), r03CD), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0400 = less(r03F1, body.constant(int(64)));
                        ir_if *f03FF = new(mem_ctx) ir_if(operand(r0400).val);
                        exec_list *const f03FF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f03FF->then_instructions;

                           body.emit(assign(r03F2, lshift(r03CC, r03F5), 0x01));

                           ir_expression *const r0401 = bit_and(r03F1, body.constant(int(31)));
                           body.emit(assign(r03F3, rshift(r03CC, r0401), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f03FF->else_instructions;

                           ir_variable *const r0402 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0404 = equal(r03F1, body.constant(int(64)));
                           ir_if *f0403 = new(mem_ctx) ir_if(operand(r0404).val);
                           exec_list *const f0403_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0403->then_instructions;

                              body.emit(assign(r0402, r03CC, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0403->else_instructions;

                              ir_expression *const r0405 = nequal(r03CC, body.constant(0u));
                              ir_expression *const r0406 = expr(ir_unop_b2i, r0405);
                              body.emit(assign(r0402, expr(ir_unop_i2u, r0406), 0x01));


                           body.instructions = f0403_parent_instructions;
                           body.emit(f0403);

                           /* END IF */

                           body.emit(assign(r03F2, r0402, 0x01));

                           body.emit(assign(r03F3, body.constant(0u), 0x01));


                        body.instructions = f03FF_parent_instructions;
                        body.emit(f03FF);

                        /* END IF */


                     body.instructions = f03FD_parent_instructions;
                     body.emit(f03FD);

                     /* END IF */

                     body.emit(assign(r03F4, body.constant(0u), 0x01));


                  body.instructions = f03F9_parent_instructions;
                  body.emit(f03F9);

                  /* END IF */

                  ir_expression *const r0407 = nequal(r03F0, body.constant(0u));
                  ir_expression *const r0408 = expr(ir_unop_b2i, r0407);
                  ir_expression *const r0409 = expr(ir_unop_i2u, r0408);
                  body.emit(assign(r03F2, bit_or(r03F2, r0409), 0x01));


               body.instructions = f03F7_parent_instructions;
               body.emit(f03F7);

               /* END IF */

               body.emit(assign(r03CC, r03F4, 0x01));

               body.emit(assign(r03CD, r03F3, 0x01));

               body.emit(assign(r03CE, r03F2, 0x01));


            body.instructions = f03E6_parent_instructions;
            body.emit(f03E6);

            /* END IF */

            body.emit(assign(r03CB, sub(r03CB, r03CF), 0x01));

            ir_variable *const r040A = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r040A, r03CB, 0x01));

            ir_variable *const r040B = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r040B, r03CC, 0x01));

            ir_variable *const r040C = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r040C, r03CD, 0x01));

            ir_variable *const r040D = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r040D, r03CE, 0x01));

            ir_variable *const r040E = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r040E, body.constant(true), 0x01));

            ir_variable *const r040F = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0410 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0410);
            ir_expression *const r0411 = expr(ir_unop_u2i, r03CE);
            body.emit(assign(r0410, less(r0411, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0413 = gequal(r03CB, body.constant(int(2045)));
            ir_if *f0412 = new(mem_ctx) ir_if(operand(r0413).val);
            exec_list *const f0412_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0412->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0415 = less(body.constant(int(2045)), r03CB);
               ir_expression *const r0416 = equal(r03CB, body.constant(int(2045)));
               ir_expression *const r0417 = equal(body.constant(2097151u), r03CC);
               ir_expression *const r0418 = equal(body.constant(4294967295u), r03CD);
               ir_expression *const r0419 = logic_and(r0417, r0418);
               ir_expression *const r041A = logic_and(r0416, r0419);
               ir_expression *const r041B = logic_and(r041A, r0410);
               ir_expression *const r041C = logic_or(r0415, r041B);
               ir_if *f0414 = new(mem_ctx) ir_if(operand(r041C).val);
               exec_list *const f0414_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0414->then_instructions;

                  ir_variable *const r041D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r041D);
                  ir_expression *const r041E = lshift(r01E4, body.constant(int(31)));
                  body.emit(assign(r041D, add(r041E, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r041D, body.constant(0u), 0x01));

                  body.emit(assign(r040F, r041D, 0x03));

                  body.emit(assign(r040E, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0414->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0420 = less(r03CB, body.constant(int(0)));
                  ir_if *f041F = new(mem_ctx) ir_if(operand(r0420).val);
                  exec_list *const f041F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f041F->then_instructions;

                     ir_variable *const r0421 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0421, r03CE, 0x01));

                     ir_variable *const r0422 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0422, neg(r03CB), 0x01));

                     ir_variable *const r0423 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0423);
                     ir_variable *const r0424 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0424);
                     ir_variable *const r0425 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0425);
                     ir_variable *const r0426 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0427 = neg(r0422);
                     body.emit(assign(r0426, bit_and(r0427, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0429 = equal(r0422, body.constant(int(0)));
                     ir_if *f0428 = new(mem_ctx) ir_if(operand(r0429).val);
                     exec_list *const f0428_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0428->then_instructions;

                        body.emit(assign(r0423, r03CE, 0x01));

                        body.emit(assign(r0424, r03CD, 0x01));

                        body.emit(assign(r0425, r03CC, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0428->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r042B = less(r0422, body.constant(int(32)));
                        ir_if *f042A = new(mem_ctx) ir_if(operand(r042B).val);
                        exec_list *const f042A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f042A->then_instructions;

                           body.emit(assign(r0423, lshift(r03CD, r0426), 0x01));

                           ir_expression *const r042C = lshift(r03CC, r0426);
                           ir_expression *const r042D = rshift(r03CD, r0422);
                           body.emit(assign(r0424, bit_or(r042C, r042D), 0x01));

                           body.emit(assign(r0425, rshift(r03CC, r0422), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f042A->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r042F = equal(r0422, body.constant(int(32)));
                           ir_if *f042E = new(mem_ctx) ir_if(operand(r042F).val);
                           exec_list *const f042E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f042E->then_instructions;

                              body.emit(assign(r0423, r03CD, 0x01));

                              body.emit(assign(r0424, r03CC, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f042E->else_instructions;

                              body.emit(assign(r0421, bit_or(r03CE, r03CD), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0431 = less(r0422, body.constant(int(64)));
                              ir_if *f0430 = new(mem_ctx) ir_if(operand(r0431).val);
                              exec_list *const f0430_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0430->then_instructions;

                                 body.emit(assign(r0423, lshift(r03CC, r0426), 0x01));

                                 ir_expression *const r0432 = bit_and(r0422, body.constant(int(31)));
                                 body.emit(assign(r0424, rshift(r03CC, r0432), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0430->else_instructions;

                                 ir_variable *const r0433 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0435 = equal(r0422, body.constant(int(64)));
                                 ir_if *f0434 = new(mem_ctx) ir_if(operand(r0435).val);
                                 exec_list *const f0434_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0434->then_instructions;

                                    body.emit(assign(r0433, r03CC, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0434->else_instructions;

                                    ir_expression *const r0436 = nequal(r03CC, body.constant(0u));
                                    ir_expression *const r0437 = expr(ir_unop_b2i, r0436);
                                    body.emit(assign(r0433, expr(ir_unop_i2u, r0437), 0x01));


                                 body.instructions = f0434_parent_instructions;
                                 body.emit(f0434);

                                 /* END IF */

                                 body.emit(assign(r0423, r0433, 0x01));

                                 body.emit(assign(r0424, body.constant(0u), 0x01));


                              body.instructions = f0430_parent_instructions;
                              body.emit(f0430);

                              /* END IF */


                           body.instructions = f042E_parent_instructions;
                           body.emit(f042E);

                           /* END IF */

                           body.emit(assign(r0425, body.constant(0u), 0x01));


                        body.instructions = f042A_parent_instructions;
                        body.emit(f042A);

                        /* END IF */

                        ir_expression *const r0438 = nequal(r0421, body.constant(0u));
                        ir_expression *const r0439 = expr(ir_unop_b2i, r0438);
                        ir_expression *const r043A = expr(ir_unop_i2u, r0439);
                        body.emit(assign(r0423, bit_or(r0423, r043A), 0x01));


                     body.instructions = f0428_parent_instructions;
                     body.emit(f0428);

                     /* END IF */

                     body.emit(assign(r040B, r0425, 0x01));

                     body.emit(assign(r040C, r0424, 0x01));

                     body.emit(assign(r040D, r0423, 0x01));

                     body.emit(assign(r040A, body.constant(int(0)), 0x01));

                     body.emit(assign(r0410, less(r0423, body.constant(0u)), 0x01));


                  body.instructions = f041F_parent_instructions;
                  body.emit(f041F);

                  /* END IF */


               body.instructions = f0414_parent_instructions;
               body.emit(f0414);

               /* END IF */


            body.instructions = f0412_parent_instructions;
            body.emit(f0412);

            /* END IF */

            /* IF CONDITION */
            ir_if *f043B = new(mem_ctx) ir_if(operand(r040E).val);
            exec_list *const f043B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f043B->then_instructions;

               /* IF CONDITION */
               ir_if *f043C = new(mem_ctx) ir_if(operand(r0410).val);
               exec_list *const f043C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f043C->then_instructions;

                  ir_variable *const r043D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r043D, add(r040C, body.constant(1u)), 0x01));

                  ir_expression *const r043E = less(r043D, r040C);
                  ir_expression *const r043F = expr(ir_unop_b2i, r043E);
                  ir_expression *const r0440 = expr(ir_unop_i2u, r043F);
                  body.emit(assign(r040B, add(r040B, r0440), 0x01));

                  ir_expression *const r0441 = equal(r040D, body.constant(0u));
                  ir_expression *const r0442 = expr(ir_unop_b2i, r0441);
                  ir_expression *const r0443 = expr(ir_unop_i2u, r0442);
                  ir_expression *const r0444 = add(r040D, r0443);
                  ir_expression *const r0445 = bit_and(r0444, body.constant(1u));
                  ir_expression *const r0446 = expr(ir_unop_bit_not, r0445);
                  body.emit(assign(r040C, bit_and(r043D, r0446), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f043C->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0448 = bit_or(r040B, r040C);
                  ir_expression *const r0449 = equal(r0448, body.constant(0u));
                  ir_if *f0447 = new(mem_ctx) ir_if(operand(r0449).val);
                  exec_list *const f0447_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0447->then_instructions;

                     body.emit(assign(r040A, body.constant(int(0)), 0x01));


                  body.instructions = f0447_parent_instructions;
                  body.emit(f0447);

                  /* END IF */


               body.instructions = f043C_parent_instructions;
               body.emit(f043C);

               /* END IF */

               ir_variable *const r044A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r044A);
               ir_expression *const r044B = lshift(r01E4, body.constant(int(31)));
               ir_expression *const r044C = expr(ir_unop_i2u, r040A);
               ir_expression *const r044D = lshift(r044C, body.constant(int(20)));
               ir_expression *const r044E = add(r044B, r044D);
               body.emit(assign(r044A, add(r044E, r040B), 0x02));

               body.emit(assign(r044A, r040C, 0x01));

               body.emit(assign(r040F, r044A, 0x03));

               body.emit(assign(r040E, body.constant(false), 0x01));


            body.instructions = f043B_parent_instructions;
            body.emit(f043B);

            /* END IF */

            body.emit(assign(r01E2, r040F, 0x03));

            body.emit(assign(r01E1, body.constant(false), 0x01));


         body.instructions = f038B_parent_instructions;
         body.emit(f038B);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0389->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0450 = less(r0371, body.constant(int(0)));
         ir_if *f044F = new(mem_ctx) ir_if(operand(r0450).val);
         exec_list *const f044F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f044F->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0452 = equal(r037C, body.constant(int(2047)));
            ir_if *f0451 = new(mem_ctx) ir_if(operand(r0452).val);
            exec_list *const f0451_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0451->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0454 = bit_or(r0374, r0375);
               ir_expression *const r0455 = nequal(r0454, body.constant(0u));
               ir_if *f0453 = new(mem_ctx) ir_if(operand(r0455).val);
               exec_list *const f0453_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0453->then_instructions;

                  ir_variable *const r0456 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0456, swizzle_x(r01DF), 0x01));

                  ir_variable *const r0457 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0457, swizzle_x(r01E0), 0x01));

                  body.emit(assign(r0456, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

                  body.emit(assign(r0457, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

                  ir_expression *const r0458 = lshift(swizzle_y(r01DF), body.constant(int(1)));
                  ir_expression *const r0459 = gequal(r0458, body.constant(4292870144u));
                  ir_expression *const r045A = nequal(swizzle_x(r01DF), body.constant(0u));
                  ir_expression *const r045B = bit_and(swizzle_y(r01DF), body.constant(1048575u));
                  ir_expression *const r045C = nequal(r045B, body.constant(0u));
                  ir_expression *const r045D = logic_or(r045A, r045C);
                  ir_expression *const r045E = logic_and(r0459, r045D);
                  ir_swizzle *const r045F = swizzle(r045E, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0460 = lshift(swizzle_y(r01E0), body.constant(int(1)));
                  ir_expression *const r0461 = gequal(r0460, body.constant(4292870144u));
                  ir_expression *const r0462 = nequal(swizzle_x(r01E0), body.constant(0u));
                  ir_expression *const r0463 = bit_and(swizzle_y(r01E0), body.constant(1048575u));
                  ir_expression *const r0464 = nequal(r0463, body.constant(0u));
                  ir_expression *const r0465 = logic_or(r0462, r0464);
                  ir_expression *const r0466 = logic_and(r0461, r0465);
                  ir_swizzle *const r0467 = swizzle(r0466, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0468 = expr(ir_triop_csel, r0467, r0457, r0456);
                  body.emit(assign(r01E2, expr(ir_triop_csel, r045F, r0468, r0457), 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0453->else_instructions;

                  ir_variable *const r0469 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0469);
                  ir_expression *const r046A = bit_xor(r01E4, body.constant(1u));
                  ir_expression *const r046B = lshift(r046A, body.constant(int(31)));
                  body.emit(assign(r0469, add(r046B, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0469, body.constant(0u), 0x01));

                  body.emit(assign(r01E2, r0469, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f0453_parent_instructions;
               body.emit(f0453);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0451->else_instructions;

               /* IF CONDITION */
               ir_expression *const r046D = equal(r0379, body.constant(int(0)));
               ir_if *f046C = new(mem_ctx) ir_if(operand(r046D).val);
               exec_list *const f046C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f046C->then_instructions;

                  body.emit(assign(r0371, add(r0371, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f046C->else_instructions;

                  body.emit(assign(r0376, bit_or(r0376, body.constant(1073741824u)), 0x01));


               body.instructions = f046C_parent_instructions;
               body.emit(f046C);

               /* END IF */

               ir_variable *const r046E = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r046E, neg(r0371), 0x01));

               ir_variable *const r046F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r046F);
               ir_variable *const r0470 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0470);
               ir_variable *const r0471 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0472 = neg(r046E);
               body.emit(assign(r0471, bit_and(r0472, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0474 = equal(r046E, body.constant(int(0)));
               ir_if *f0473 = new(mem_ctx) ir_if(operand(r0474).val);
               exec_list *const f0473_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0473->then_instructions;

                  body.emit(assign(r046F, r037F, 0x01));

                  body.emit(assign(r0470, r0376, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0473->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0476 = less(r046E, body.constant(int(32)));
                  ir_if *f0475 = new(mem_ctx) ir_if(operand(r0476).val);
                  exec_list *const f0475_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0475->then_instructions;

                     ir_expression *const r0477 = lshift(r0376, r0471);
                     ir_expression *const r0478 = rshift(r037F, r046E);
                     ir_expression *const r0479 = bit_or(r0477, r0478);
                     ir_expression *const r047A = lshift(r037F, r0471);
                     ir_expression *const r047B = nequal(r047A, body.constant(0u));
                     ir_expression *const r047C = expr(ir_unop_b2i, r047B);
                     ir_expression *const r047D = expr(ir_unop_i2u, r047C);
                     body.emit(assign(r046F, bit_or(r0479, r047D), 0x01));

                     body.emit(assign(r0470, rshift(r0376, r046E), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0475->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r047F = equal(r046E, body.constant(int(32)));
                     ir_if *f047E = new(mem_ctx) ir_if(operand(r047F).val);
                     exec_list *const f047E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f047E->then_instructions;

                        ir_expression *const r0480 = nequal(r037F, body.constant(0u));
                        ir_expression *const r0481 = expr(ir_unop_b2i, r0480);
                        ir_expression *const r0482 = expr(ir_unop_i2u, r0481);
                        body.emit(assign(r046F, bit_or(r0376, r0482), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f047E->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0484 = less(r046E, body.constant(int(64)));
                        ir_if *f0483 = new(mem_ctx) ir_if(operand(r0484).val);
                        exec_list *const f0483_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0483->then_instructions;

                           ir_expression *const r0485 = bit_and(r046E, body.constant(int(31)));
                           ir_expression *const r0486 = rshift(r0376, r0485);
                           ir_expression *const r0487 = lshift(r0376, r0471);
                           ir_expression *const r0488 = bit_or(r0487, r037F);
                           ir_expression *const r0489 = nequal(r0488, body.constant(0u));
                           ir_expression *const r048A = expr(ir_unop_b2i, r0489);
                           ir_expression *const r048B = expr(ir_unop_i2u, r048A);
                           body.emit(assign(r046F, bit_or(r0486, r048B), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0483->else_instructions;

                           ir_expression *const r048C = bit_or(r0376, r037F);
                           ir_expression *const r048D = nequal(r048C, body.constant(0u));
                           ir_expression *const r048E = expr(ir_unop_b2i, r048D);
                           body.emit(assign(r046F, expr(ir_unop_i2u, r048E), 0x01));


                        body.instructions = f0483_parent_instructions;
                        body.emit(f0483);

                        /* END IF */


                     body.instructions = f047E_parent_instructions;
                     body.emit(f047E);

                     /* END IF */

                     body.emit(assign(r0470, body.constant(0u), 0x01));


                  body.instructions = f0475_parent_instructions;
                  body.emit(f0475);

                  /* END IF */


               body.instructions = f0473_parent_instructions;
               body.emit(f0473);

               /* END IF */

               body.emit(assign(r0376, r0470, 0x01));

               body.emit(assign(r0377, r046F, 0x01));

               body.emit(assign(r0374, bit_or(r0374, body.constant(1073741824u)), 0x01));

               ir_variable *const r048F = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0490 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0490, sub(r0375, r046F), 0x01));

               ir_expression *const r0491 = sub(r0374, r0470);
               ir_expression *const r0492 = less(r0375, r046F);
               ir_expression *const r0493 = expr(ir_unop_b2i, r0492);
               ir_expression *const r0494 = expr(ir_unop_i2u, r0493);
               body.emit(assign(r048F, sub(r0491, r0494), 0x01));

               body.emit(assign(r01E3, bit_xor(r01E4, body.constant(1u)), 0x01));

               body.emit(assign(r0378, add(r037C, body.constant(int(-1))), 0x01));

               ir_variable *const r0495 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0495, add(r0378, body.constant(int(-10))), 0x01));

               ir_variable *const r0496 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r0496, r048F, 0x01));

               ir_variable *const r0497 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0497, r0490, 0x01));

               ir_variable *const r0498 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r0498);
               ir_variable *const r0499 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0499);
               /* IF CONDITION */
               ir_expression *const r049B = equal(r048F, body.constant(0u));
               ir_if *f049A = new(mem_ctx) ir_if(operand(r049B).val);
               exec_list *const f049A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f049A->then_instructions;

                  body.emit(assign(r0496, r0490, 0x01));

                  body.emit(assign(r0497, body.constant(0u), 0x01));

                  body.emit(assign(r0495, add(r0495, body.constant(int(-32))), 0x01));


               body.instructions = f049A_parent_instructions;
               body.emit(f049A);

               /* END IF */

               ir_variable *const r049C = body.make_temp(glsl_type::uint_type, "a");
               body.emit(assign(r049C, r0496, 0x01));

               ir_variable *const r049D = body.make_temp(glsl_type::int_type, "return_value");
               ir_variable *const r049E = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r049E);
               /* IF CONDITION */
               ir_expression *const r04A0 = equal(r0496, body.constant(0u));
               ir_if *f049F = new(mem_ctx) ir_if(operand(r04A0).val);
               exec_list *const f049F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f049F->then_instructions;

                  body.emit(assign(r049D, body.constant(int(32)), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f049F->else_instructions;

                  body.emit(assign(r049E, body.constant(int(0)), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04A2 = bit_and(r0496, body.constant(4294901760u));
                  ir_expression *const r04A3 = equal(r04A2, body.constant(0u));
                  ir_if *f04A1 = new(mem_ctx) ir_if(operand(r04A3).val);
                  exec_list *const f04A1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A1->then_instructions;

                     body.emit(assign(r049E, body.constant(int(16)), 0x01));

                     body.emit(assign(r049C, lshift(r0496, body.constant(int(16))), 0x01));


                  body.instructions = f04A1_parent_instructions;
                  body.emit(f04A1);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04A5 = bit_and(r049C, body.constant(4278190080u));
                  ir_expression *const r04A6 = equal(r04A5, body.constant(0u));
                  ir_if *f04A4 = new(mem_ctx) ir_if(operand(r04A6).val);
                  exec_list *const f04A4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A4->then_instructions;

                     body.emit(assign(r049E, add(r049E, body.constant(int(8))), 0x01));

                     body.emit(assign(r049C, lshift(r049C, body.constant(int(8))), 0x01));


                  body.instructions = f04A4_parent_instructions;
                  body.emit(f04A4);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04A8 = bit_and(r049C, body.constant(4026531840u));
                  ir_expression *const r04A9 = equal(r04A8, body.constant(0u));
                  ir_if *f04A7 = new(mem_ctx) ir_if(operand(r04A9).val);
                  exec_list *const f04A7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A7->then_instructions;

                     body.emit(assign(r049E, add(r049E, body.constant(int(4))), 0x01));

                     body.emit(assign(r049C, lshift(r049C, body.constant(int(4))), 0x01));


                  body.instructions = f04A7_parent_instructions;
                  body.emit(f04A7);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04AB = bit_and(r049C, body.constant(3221225472u));
                  ir_expression *const r04AC = equal(r04AB, body.constant(0u));
                  ir_if *f04AA = new(mem_ctx) ir_if(operand(r04AC).val);
                  exec_list *const f04AA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04AA->then_instructions;

                     body.emit(assign(r049E, add(r049E, body.constant(int(2))), 0x01));

                     body.emit(assign(r049C, lshift(r049C, body.constant(int(2))), 0x01));


                  body.instructions = f04AA_parent_instructions;
                  body.emit(f04AA);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04AE = bit_and(r049C, body.constant(2147483648u));
                  ir_expression *const r04AF = equal(r04AE, body.constant(0u));
                  ir_if *f04AD = new(mem_ctx) ir_if(operand(r04AF).val);
                  exec_list *const f04AD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04AD->then_instructions;

                     body.emit(assign(r049E, add(r049E, body.constant(int(1))), 0x01));


                  body.instructions = f04AD_parent_instructions;
                  body.emit(f04AD);

                  /* END IF */

                  body.emit(assign(r049D, r049E, 0x01));


               body.instructions = f049F_parent_instructions;
               body.emit(f049F);

               /* END IF */

               body.emit(assign(r0499, add(r049D, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04B1 = gequal(r0499, body.constant(int(0)));
               ir_if *f04B0 = new(mem_ctx) ir_if(operand(r04B1).val);
               exec_list *const f04B0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04B0->then_instructions;

                  body.emit(assign(r0498, body.constant(0u), 0x01));

                  ir_variable *const r04B2 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r04B2, lshift(r0497, r0499), 0x01));

                  ir_variable *const r04B3 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r04B5 = equal(r0499, body.constant(int(0)));
                  ir_if *f04B4 = new(mem_ctx) ir_if(operand(r04B5).val);
                  exec_list *const f04B4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04B4->then_instructions;

                     body.emit(assign(r04B3, r0496, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04B4->else_instructions;

                     ir_expression *const r04B6 = lshift(r0496, r0499);
                     ir_expression *const r04B7 = neg(r0499);
                     ir_expression *const r04B8 = bit_and(r04B7, body.constant(int(31)));
                     ir_expression *const r04B9 = rshift(r0497, r04B8);
                     body.emit(assign(r04B3, bit_or(r04B6, r04B9), 0x01));


                  body.instructions = f04B4_parent_instructions;
                  body.emit(f04B4);

                  /* END IF */

                  body.emit(assign(r0496, r04B3, 0x01));

                  body.emit(assign(r0497, r04B2, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04B0->else_instructions;

                  ir_variable *const r04BA = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r04BA, body.constant(0u), 0x01));

                  ir_variable *const r04BB = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r04BB, neg(r0499), 0x01));

                  ir_variable *const r04BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04BC);
                  ir_variable *const r04BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r04BD);
                  ir_variable *const r04BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04BE);
                  ir_variable *const r04BF = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04C0 = neg(r04BB);
                  body.emit(assign(r04BF, bit_and(r04C0, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04C2 = equal(r04BB, body.constant(int(0)));
                  ir_if *f04C1 = new(mem_ctx) ir_if(operand(r04C2).val);
                  exec_list *const f04C1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C1->then_instructions;

                     body.emit(assign(r04BC, r04BA, 0x01));

                     body.emit(assign(r04BD, r0497, 0x01));

                     body.emit(assign(r04BE, r0496, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04C1->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04C4 = less(r04BB, body.constant(int(32)));
                     ir_if *f04C3 = new(mem_ctx) ir_if(operand(r04C4).val);
                     exec_list *const f04C3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04C3->then_instructions;

                        body.emit(assign(r04BC, lshift(r0497, r04BF), 0x01));

                        ir_expression *const r04C5 = lshift(r0496, r04BF);
                        ir_expression *const r04C6 = rshift(r0497, r04BB);
                        body.emit(assign(r04BD, bit_or(r04C5, r04C6), 0x01));

                        body.emit(assign(r04BE, rshift(r0496, r04BB), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04C3->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04C8 = equal(r04BB, body.constant(int(32)));
                        ir_if *f04C7 = new(mem_ctx) ir_if(operand(r04C8).val);
                        exec_list *const f04C7_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04C7->then_instructions;

                           body.emit(assign(r04BC, r0497, 0x01));

                           body.emit(assign(r04BD, r0496, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04C7->else_instructions;

                           body.emit(assign(r04BA, bit_or(body.constant(0u), r0497), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r04CA = less(r04BB, body.constant(int(64)));
                           ir_if *f04C9 = new(mem_ctx) ir_if(operand(r04CA).val);
                           exec_list *const f04C9_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04C9->then_instructions;

                              body.emit(assign(r04BC, lshift(r0496, r04BF), 0x01));

                              ir_expression *const r04CB = bit_and(r04BB, body.constant(int(31)));
                              body.emit(assign(r04BD, rshift(r0496, r04CB), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04C9->else_instructions;

                              ir_variable *const r04CC = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r04CE = equal(r04BB, body.constant(int(64)));
                              ir_if *f04CD = new(mem_ctx) ir_if(operand(r04CE).val);
                              exec_list *const f04CD_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04CD->then_instructions;

                                 body.emit(assign(r04CC, r0496, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04CD->else_instructions;

                                 ir_expression *const r04CF = nequal(r0496, body.constant(0u));
                                 ir_expression *const r04D0 = expr(ir_unop_b2i, r04CF);
                                 body.emit(assign(r04CC, expr(ir_unop_i2u, r04D0), 0x01));


                              body.instructions = f04CD_parent_instructions;
                              body.emit(f04CD);

                              /* END IF */

                              body.emit(assign(r04BC, r04CC, 0x01));

                              body.emit(assign(r04BD, body.constant(0u), 0x01));


                           body.instructions = f04C9_parent_instructions;
                           body.emit(f04C9);

                           /* END IF */


                        body.instructions = f04C7_parent_instructions;
                        body.emit(f04C7);

                        /* END IF */

                        body.emit(assign(r04BE, body.constant(0u), 0x01));


                     body.instructions = f04C3_parent_instructions;
                     body.emit(f04C3);

                     /* END IF */

                     ir_expression *const r04D1 = nequal(r04BA, body.constant(0u));
                     ir_expression *const r04D2 = expr(ir_unop_b2i, r04D1);
                     ir_expression *const r04D3 = expr(ir_unop_i2u, r04D2);
                     body.emit(assign(r04BC, bit_or(r04BC, r04D3), 0x01));


                  body.instructions = f04C1_parent_instructions;
                  body.emit(f04C1);

                  /* END IF */

                  body.emit(assign(r0496, r04BE, 0x01));

                  body.emit(assign(r0497, r04BD, 0x01));

                  body.emit(assign(r0498, r04BC, 0x01));


               body.instructions = f04B0_parent_instructions;
               body.emit(f04B0);

               /* END IF */

               body.emit(assign(r0495, sub(r0495, r0499), 0x01));

               ir_variable *const r04D4 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04D4, r0495, 0x01));

               ir_variable *const r04D5 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04D5, r0496, 0x01));

               ir_variable *const r04D6 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04D6, r0497, 0x01));

               ir_variable *const r04D7 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r04D7, r0498, 0x01));

               ir_variable *const r04D8 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r04D8, body.constant(true), 0x01));

               ir_variable *const r04D9 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04DA = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r04DA);
               ir_expression *const r04DB = expr(ir_unop_u2i, r0498);
               body.emit(assign(r04DA, less(r04DB, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04DD = gequal(r0495, body.constant(int(2045)));
               ir_if *f04DC = new(mem_ctx) ir_if(operand(r04DD).val);
               exec_list *const f04DC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04DC->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04DF = less(body.constant(int(2045)), r0495);
                  ir_expression *const r04E0 = equal(r0495, body.constant(int(2045)));
                  ir_expression *const r04E1 = equal(body.constant(2097151u), r0496);
                  ir_expression *const r04E2 = equal(body.constant(4294967295u), r0497);
                  ir_expression *const r04E3 = logic_and(r04E1, r04E2);
                  ir_expression *const r04E4 = logic_and(r04E0, r04E3);
                  ir_expression *const r04E5 = logic_and(r04E4, r04DA);
                  ir_expression *const r04E6 = logic_or(r04DF, r04E5);
                  ir_if *f04DE = new(mem_ctx) ir_if(operand(r04E6).val);
                  exec_list *const f04DE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04DE->then_instructions;

                     ir_variable *const r04E7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r04E7);
                     ir_expression *const r04E8 = lshift(r01E3, body.constant(int(31)));
                     body.emit(assign(r04E7, add(r04E8, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r04E7, body.constant(0u), 0x01));

                     body.emit(assign(r04D9, r04E7, 0x03));

                     body.emit(assign(r04D8, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04DE->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04EA = less(r0495, body.constant(int(0)));
                     ir_if *f04E9 = new(mem_ctx) ir_if(operand(r04EA).val);
                     exec_list *const f04E9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04E9->then_instructions;

                        ir_variable *const r04EB = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r04EB, r0498, 0x01));

                        ir_variable *const r04EC = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r04EC, neg(r0495), 0x01));

                        ir_variable *const r04ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r04ED);
                        ir_variable *const r04EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r04EE);
                        ir_variable *const r04EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r04EF);
                        ir_variable *const r04F0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r04F1 = neg(r04EC);
                        body.emit(assign(r04F0, bit_and(r04F1, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r04F3 = equal(r04EC, body.constant(int(0)));
                        ir_if *f04F2 = new(mem_ctx) ir_if(operand(r04F3).val);
                        exec_list *const f04F2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04F2->then_instructions;

                           body.emit(assign(r04ED, r0498, 0x01));

                           body.emit(assign(r04EE, r0497, 0x01));

                           body.emit(assign(r04EF, r0496, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04F2->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r04F5 = less(r04EC, body.constant(int(32)));
                           ir_if *f04F4 = new(mem_ctx) ir_if(operand(r04F5).val);
                           exec_list *const f04F4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04F4->then_instructions;

                              body.emit(assign(r04ED, lshift(r0497, r04F0), 0x01));

                              ir_expression *const r04F6 = lshift(r0496, r04F0);
                              ir_expression *const r04F7 = rshift(r0497, r04EC);
                              body.emit(assign(r04EE, bit_or(r04F6, r04F7), 0x01));

                              body.emit(assign(r04EF, rshift(r0496, r04EC), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04F4->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r04F9 = equal(r04EC, body.constant(int(32)));
                              ir_if *f04F8 = new(mem_ctx) ir_if(operand(r04F9).val);
                              exec_list *const f04F8_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04F8->then_instructions;

                                 body.emit(assign(r04ED, r0497, 0x01));

                                 body.emit(assign(r04EE, r0496, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04F8->else_instructions;

                                 body.emit(assign(r04EB, bit_or(r0498, r0497), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r04FB = less(r04EC, body.constant(int(64)));
                                 ir_if *f04FA = new(mem_ctx) ir_if(operand(r04FB).val);
                                 exec_list *const f04FA_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f04FA->then_instructions;

                                    body.emit(assign(r04ED, lshift(r0496, r04F0), 0x01));

                                    ir_expression *const r04FC = bit_and(r04EC, body.constant(int(31)));
                                    body.emit(assign(r04EE, rshift(r0496, r04FC), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f04FA->else_instructions;

                                    ir_variable *const r04FD = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r04FF = equal(r04EC, body.constant(int(64)));
                                    ir_if *f04FE = new(mem_ctx) ir_if(operand(r04FF).val);
                                    exec_list *const f04FE_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f04FE->then_instructions;

                                       body.emit(assign(r04FD, r0496, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f04FE->else_instructions;

                                       ir_expression *const r0500 = nequal(r0496, body.constant(0u));
                                       ir_expression *const r0501 = expr(ir_unop_b2i, r0500);
                                       body.emit(assign(r04FD, expr(ir_unop_i2u, r0501), 0x01));


                                    body.instructions = f04FE_parent_instructions;
                                    body.emit(f04FE);

                                    /* END IF */

                                    body.emit(assign(r04ED, r04FD, 0x01));

                                    body.emit(assign(r04EE, body.constant(0u), 0x01));


                                 body.instructions = f04FA_parent_instructions;
                                 body.emit(f04FA);

                                 /* END IF */


                              body.instructions = f04F8_parent_instructions;
                              body.emit(f04F8);

                              /* END IF */

                              body.emit(assign(r04EF, body.constant(0u), 0x01));


                           body.instructions = f04F4_parent_instructions;
                           body.emit(f04F4);

                           /* END IF */

                           ir_expression *const r0502 = nequal(r04EB, body.constant(0u));
                           ir_expression *const r0503 = expr(ir_unop_b2i, r0502);
                           ir_expression *const r0504 = expr(ir_unop_i2u, r0503);
                           body.emit(assign(r04ED, bit_or(r04ED, r0504), 0x01));


                        body.instructions = f04F2_parent_instructions;
                        body.emit(f04F2);

                        /* END IF */

                        body.emit(assign(r04D5, r04EF, 0x01));

                        body.emit(assign(r04D6, r04EE, 0x01));

                        body.emit(assign(r04D7, r04ED, 0x01));

                        body.emit(assign(r04D4, body.constant(int(0)), 0x01));

                        body.emit(assign(r04DA, less(r04ED, body.constant(0u)), 0x01));


                     body.instructions = f04E9_parent_instructions;
                     body.emit(f04E9);

                     /* END IF */


                  body.instructions = f04DE_parent_instructions;
                  body.emit(f04DE);

                  /* END IF */


               body.instructions = f04DC_parent_instructions;
               body.emit(f04DC);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0505 = new(mem_ctx) ir_if(operand(r04D8).val);
               exec_list *const f0505_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0505->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0506 = new(mem_ctx) ir_if(operand(r04DA).val);
                  exec_list *const f0506_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0506->then_instructions;

                     ir_variable *const r0507 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0507, add(r04D6, body.constant(1u)), 0x01));

                     ir_expression *const r0508 = less(r0507, r04D6);
                     ir_expression *const r0509 = expr(ir_unop_b2i, r0508);
                     ir_expression *const r050A = expr(ir_unop_i2u, r0509);
                     body.emit(assign(r04D5, add(r04D5, r050A), 0x01));

                     ir_expression *const r050B = equal(r04D7, body.constant(0u));
                     ir_expression *const r050C = expr(ir_unop_b2i, r050B);
                     ir_expression *const r050D = expr(ir_unop_i2u, r050C);
                     ir_expression *const r050E = add(r04D7, r050D);
                     ir_expression *const r050F = bit_and(r050E, body.constant(1u));
                     ir_expression *const r0510 = expr(ir_unop_bit_not, r050F);
                     body.emit(assign(r04D6, bit_and(r0507, r0510), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0506->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0512 = bit_or(r04D5, r04D6);
                     ir_expression *const r0513 = equal(r0512, body.constant(0u));
                     ir_if *f0511 = new(mem_ctx) ir_if(operand(r0513).val);
                     exec_list *const f0511_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0511->then_instructions;

                        body.emit(assign(r04D4, body.constant(int(0)), 0x01));


                     body.instructions = f0511_parent_instructions;
                     body.emit(f0511);

                     /* END IF */


                  body.instructions = f0506_parent_instructions;
                  body.emit(f0506);

                  /* END IF */

                  ir_variable *const r0514 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0514);
                  ir_expression *const r0515 = lshift(r01E3, body.constant(int(31)));
                  ir_expression *const r0516 = expr(ir_unop_i2u, r04D4);
                  ir_expression *const r0517 = lshift(r0516, body.constant(int(20)));
                  ir_expression *const r0518 = add(r0515, r0517);
                  body.emit(assign(r0514, add(r0518, r04D5), 0x02));

                  body.emit(assign(r0514, r04D6, 0x01));

                  body.emit(assign(r04D9, r0514, 0x03));

                  body.emit(assign(r04D8, body.constant(false), 0x01));


               body.instructions = f0505_parent_instructions;
               body.emit(f0505);

               /* END IF */

               body.emit(assign(r01E2, r04D9, 0x03));

               body.emit(assign(r01E1, body.constant(false), 0x01));


            body.instructions = f0451_parent_instructions;
            body.emit(f0451);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f044F->else_instructions;

            /* IF CONDITION */
            ir_expression *const r051A = equal(r0379, body.constant(int(2047)));
            ir_if *f0519 = new(mem_ctx) ir_if(operand(r051A).val);
            exec_list *const f0519_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0519->then_instructions;

               /* IF CONDITION */
               ir_expression *const r051C = bit_or(r0376, r0377);
               ir_expression *const r051D = bit_or(r0374, r0375);
               ir_expression *const r051E = bit_or(r051C, r051D);
               ir_expression *const r051F = nequal(r051E, body.constant(0u));
               ir_if *f051B = new(mem_ctx) ir_if(operand(r051F).val);
               exec_list *const f051B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f051B->then_instructions;

                  ir_variable *const r0520 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0520, swizzle_x(r01DF), 0x01));

                  ir_variable *const r0521 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0521, swizzle_x(r01E0), 0x01));

                  body.emit(assign(r0520, bit_or(swizzle_y(r01DF), body.constant(524288u)), 0x02));

                  body.emit(assign(r0521, bit_or(swizzle_y(r01E0), body.constant(524288u)), 0x02));

                  ir_expression *const r0522 = lshift(swizzle_y(r01DF), body.constant(int(1)));
                  ir_expression *const r0523 = gequal(r0522, body.constant(4292870144u));
                  ir_expression *const r0524 = nequal(swizzle_x(r01DF), body.constant(0u));
                  ir_expression *const r0525 = bit_and(swizzle_y(r01DF), body.constant(1048575u));
                  ir_expression *const r0526 = nequal(r0525, body.constant(0u));
                  ir_expression *const r0527 = logic_or(r0524, r0526);
                  ir_expression *const r0528 = logic_and(r0523, r0527);
                  ir_swizzle *const r0529 = swizzle(r0528, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r052A = lshift(swizzle_y(r01E0), body.constant(int(1)));
                  ir_expression *const r052B = gequal(r052A, body.constant(4292870144u));
                  ir_expression *const r052C = nequal(swizzle_x(r01E0), body.constant(0u));
                  ir_expression *const r052D = bit_and(swizzle_y(r01E0), body.constant(1048575u));
                  ir_expression *const r052E = nequal(r052D, body.constant(0u));
                  ir_expression *const r052F = logic_or(r052C, r052E);
                  ir_expression *const r0530 = logic_and(r052B, r052F);
                  ir_swizzle *const r0531 = swizzle(r0530, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
                  ir_expression *const r0532 = expr(ir_triop_csel, r0531, r0521, r0520);
                  body.emit(assign(r01E2, expr(ir_triop_csel, r0529, r0532, r0521), 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f051B->else_instructions;

                  ir_constant_data r0533_data;
                  memset(&r0533_data, 0, sizeof(ir_constant_data));
                  r0533_data.u[0] = 4294967295;
                  r0533_data.u[1] = 4294967295;
                  ir_constant *const r0533 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0533_data);
                  body.emit(assign(r01E2, r0533, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


               body.instructions = f051B_parent_instructions;
               body.emit(f051B);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0519->else_instructions;

               ir_expression *const r0534 = equal(r0379, body.constant(int(0)));
               body.emit(assign(r0372, expr(ir_triop_csel, r0534, body.constant(int(1)), r037C), 0x01));

               ir_expression *const r0535 = equal(r0379, body.constant(int(0)));
               body.emit(assign(r0373, expr(ir_triop_csel, r0535, body.constant(int(1)), r0379), 0x01));

               /* IF CONDITION */
               ir_expression *const r0537 = less(r0374, r0376);
               ir_if *f0536 = new(mem_ctx) ir_if(operand(r0537).val);
               exec_list *const f0536_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0536->then_instructions;

                  ir_variable *const r0538 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_variable *const r0539 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r0539, sub(r0377, r0375), 0x01));

                  ir_expression *const r053A = sub(r0376, r0374);
                  ir_expression *const r053B = less(r0377, r0375);
                  ir_expression *const r053C = expr(ir_unop_b2i, r053B);
                  ir_expression *const r053D = expr(ir_unop_i2u, r053C);
                  body.emit(assign(r0538, sub(r053A, r053D), 0x01));

                  body.emit(assign(r0378, add(r0373, body.constant(int(-1))), 0x01));

                  ir_variable *const r053E = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r053E, add(r0378, body.constant(int(-10))), 0x01));

                  ir_variable *const r053F = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r053F, r0538, 0x01));

                  ir_variable *const r0540 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0540, r0539, 0x01));

                  ir_variable *const r0541 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r0541);
                  ir_variable *const r0542 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0542);
                  /* IF CONDITION */
                  ir_expression *const r0544 = equal(r0538, body.constant(0u));
                  ir_if *f0543 = new(mem_ctx) ir_if(operand(r0544).val);
                  exec_list *const f0543_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0543->then_instructions;

                     body.emit(assign(r053F, r0539, 0x01));

                     body.emit(assign(r0540, body.constant(0u), 0x01));

                     body.emit(assign(r053E, add(r053E, body.constant(int(-32))), 0x01));


                  body.instructions = f0543_parent_instructions;
                  body.emit(f0543);

                  /* END IF */

                  ir_variable *const r0545 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r0545, r053F, 0x01));

                  ir_variable *const r0546 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r0547 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0547);
                  /* IF CONDITION */
                  ir_expression *const r0549 = equal(r053F, body.constant(0u));
                  ir_if *f0548 = new(mem_ctx) ir_if(operand(r0549).val);
                  exec_list *const f0548_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0548->then_instructions;

                     body.emit(assign(r0546, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0548->else_instructions;

                     body.emit(assign(r0547, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r054B = bit_and(r053F, body.constant(4294901760u));
                     ir_expression *const r054C = equal(r054B, body.constant(0u));
                     ir_if *f054A = new(mem_ctx) ir_if(operand(r054C).val);
                     exec_list *const f054A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f054A->then_instructions;

                        body.emit(assign(r0547, body.constant(int(16)), 0x01));

                        body.emit(assign(r0545, lshift(r053F, body.constant(int(16))), 0x01));


                     body.instructions = f054A_parent_instructions;
                     body.emit(f054A);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r054E = bit_and(r0545, body.constant(4278190080u));
                     ir_expression *const r054F = equal(r054E, body.constant(0u));
                     ir_if *f054D = new(mem_ctx) ir_if(operand(r054F).val);
                     exec_list *const f054D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f054D->then_instructions;

                        body.emit(assign(r0547, add(r0547, body.constant(int(8))), 0x01));

                        body.emit(assign(r0545, lshift(r0545, body.constant(int(8))), 0x01));


                     body.instructions = f054D_parent_instructions;
                     body.emit(f054D);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0551 = bit_and(r0545, body.constant(4026531840u));
                     ir_expression *const r0552 = equal(r0551, body.constant(0u));
                     ir_if *f0550 = new(mem_ctx) ir_if(operand(r0552).val);
                     exec_list *const f0550_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0550->then_instructions;

                        body.emit(assign(r0547, add(r0547, body.constant(int(4))), 0x01));

                        body.emit(assign(r0545, lshift(r0545, body.constant(int(4))), 0x01));


                     body.instructions = f0550_parent_instructions;
                     body.emit(f0550);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0554 = bit_and(r0545, body.constant(3221225472u));
                     ir_expression *const r0555 = equal(r0554, body.constant(0u));
                     ir_if *f0553 = new(mem_ctx) ir_if(operand(r0555).val);
                     exec_list *const f0553_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0553->then_instructions;

                        body.emit(assign(r0547, add(r0547, body.constant(int(2))), 0x01));

                        body.emit(assign(r0545, lshift(r0545, body.constant(int(2))), 0x01));


                     body.instructions = f0553_parent_instructions;
                     body.emit(f0553);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0557 = bit_and(r0545, body.constant(2147483648u));
                     ir_expression *const r0558 = equal(r0557, body.constant(0u));
                     ir_if *f0556 = new(mem_ctx) ir_if(operand(r0558).val);
                     exec_list *const f0556_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0556->then_instructions;

                        body.emit(assign(r0547, add(r0547, body.constant(int(1))), 0x01));


                     body.instructions = f0556_parent_instructions;
                     body.emit(f0556);

                     /* END IF */

                     body.emit(assign(r0546, r0547, 0x01));


                  body.instructions = f0548_parent_instructions;
                  body.emit(f0548);

                  /* END IF */

                  body.emit(assign(r0542, add(r0546, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r055A = gequal(r0542, body.constant(int(0)));
                  ir_if *f0559 = new(mem_ctx) ir_if(operand(r055A).val);
                  exec_list *const f0559_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0559->then_instructions;

                     body.emit(assign(r0541, body.constant(0u), 0x01));

                     ir_variable *const r055B = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r055B, lshift(r0540, r0542), 0x01));

                     ir_variable *const r055C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r055E = equal(r0542, body.constant(int(0)));
                     ir_if *f055D = new(mem_ctx) ir_if(operand(r055E).val);
                     exec_list *const f055D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f055D->then_instructions;

                        body.emit(assign(r055C, r053F, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f055D->else_instructions;

                        ir_expression *const r055F = lshift(r053F, r0542);
                        ir_expression *const r0560 = neg(r0542);
                        ir_expression *const r0561 = bit_and(r0560, body.constant(int(31)));
                        ir_expression *const r0562 = rshift(r0540, r0561);
                        body.emit(assign(r055C, bit_or(r055F, r0562), 0x01));


                     body.instructions = f055D_parent_instructions;
                     body.emit(f055D);

                     /* END IF */

                     body.emit(assign(r053F, r055C, 0x01));

                     body.emit(assign(r0540, r055B, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0559->else_instructions;

                     ir_variable *const r0563 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0563, body.constant(0u), 0x01));

                     ir_variable *const r0564 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0564, neg(r0542), 0x01));

                     ir_variable *const r0565 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0565);
                     ir_variable *const r0566 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0566);
                     ir_variable *const r0567 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0567);
                     ir_variable *const r0568 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0569 = neg(r0564);
                     body.emit(assign(r0568, bit_and(r0569, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r056B = equal(r0564, body.constant(int(0)));
                     ir_if *f056A = new(mem_ctx) ir_if(operand(r056B).val);
                     exec_list *const f056A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f056A->then_instructions;

                        body.emit(assign(r0565, r0563, 0x01));

                        body.emit(assign(r0566, r0540, 0x01));

                        body.emit(assign(r0567, r053F, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f056A->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r056D = less(r0564, body.constant(int(32)));
                        ir_if *f056C = new(mem_ctx) ir_if(operand(r056D).val);
                        exec_list *const f056C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f056C->then_instructions;

                           body.emit(assign(r0565, lshift(r0540, r0568), 0x01));

                           ir_expression *const r056E = lshift(r053F, r0568);
                           ir_expression *const r056F = rshift(r0540, r0564);
                           body.emit(assign(r0566, bit_or(r056E, r056F), 0x01));

                           body.emit(assign(r0567, rshift(r053F, r0564), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f056C->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0571 = equal(r0564, body.constant(int(32)));
                           ir_if *f0570 = new(mem_ctx) ir_if(operand(r0571).val);
                           exec_list *const f0570_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0570->then_instructions;

                              body.emit(assign(r0565, r0540, 0x01));

                              body.emit(assign(r0566, r053F, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0570->else_instructions;

                              body.emit(assign(r0563, bit_or(body.constant(0u), r0540), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0573 = less(r0564, body.constant(int(64)));
                              ir_if *f0572 = new(mem_ctx) ir_if(operand(r0573).val);
                              exec_list *const f0572_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0572->then_instructions;

                                 body.emit(assign(r0565, lshift(r053F, r0568), 0x01));

                                 ir_expression *const r0574 = bit_and(r0564, body.constant(int(31)));
                                 body.emit(assign(r0566, rshift(r053F, r0574), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0572->else_instructions;

                                 ir_variable *const r0575 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0577 = equal(r0564, body.constant(int(64)));
                                 ir_if *f0576 = new(mem_ctx) ir_if(operand(r0577).val);
                                 exec_list *const f0576_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0576->then_instructions;

                                    body.emit(assign(r0575, r053F, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0576->else_instructions;

                                    ir_expression *const r0578 = nequal(r053F, body.constant(0u));
                                    ir_expression *const r0579 = expr(ir_unop_b2i, r0578);
                                    body.emit(assign(r0575, expr(ir_unop_i2u, r0579), 0x01));


                                 body.instructions = f0576_parent_instructions;
                                 body.emit(f0576);

                                 /* END IF */

                                 body.emit(assign(r0565, r0575, 0x01));

                                 body.emit(assign(r0566, body.constant(0u), 0x01));


                              body.instructions = f0572_parent_instructions;
                              body.emit(f0572);

                              /* END IF */


                           body.instructions = f0570_parent_instructions;
                           body.emit(f0570);

                           /* END IF */

                           body.emit(assign(r0567, body.constant(0u), 0x01));


                        body.instructions = f056C_parent_instructions;
                        body.emit(f056C);

                        /* END IF */

                        ir_expression *const r057A = nequal(r0563, body.constant(0u));
                        ir_expression *const r057B = expr(ir_unop_b2i, r057A);
                        ir_expression *const r057C = expr(ir_unop_i2u, r057B);
                        body.emit(assign(r0565, bit_or(r0565, r057C), 0x01));


                     body.instructions = f056A_parent_instructions;
                     body.emit(f056A);

                     /* END IF */

                     body.emit(assign(r053F, r0567, 0x01));

                     body.emit(assign(r0540, r0566, 0x01));

                     body.emit(assign(r0541, r0565, 0x01));


                  body.instructions = f0559_parent_instructions;
                  body.emit(f0559);

                  /* END IF */

                  body.emit(assign(r053E, sub(r053E, r0542), 0x01));

                  ir_variable *const r057D = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r057D, r053E, 0x01));

                  ir_variable *const r057E = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r057E, r053F, 0x01));

                  ir_variable *const r057F = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r057F, r0540, 0x01));

                  ir_variable *const r0580 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0580, r0541, 0x01));

                  ir_variable *const r0581 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0581, body.constant(true), 0x01));

                  ir_variable *const r0582 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0583 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r0583);
                  ir_expression *const r0584 = expr(ir_unop_u2i, r0541);
                  body.emit(assign(r0583, less(r0584, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0586 = gequal(r053E, body.constant(int(2045)));
                  ir_if *f0585 = new(mem_ctx) ir_if(operand(r0586).val);
                  exec_list *const f0585_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0585->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0588 = less(body.constant(int(2045)), r053E);
                     ir_expression *const r0589 = equal(r053E, body.constant(int(2045)));
                     ir_expression *const r058A = equal(body.constant(2097151u), r053F);
                     ir_expression *const r058B = equal(body.constant(4294967295u), r0540);
                     ir_expression *const r058C = logic_and(r058A, r058B);
                     ir_expression *const r058D = logic_and(r0589, r058C);
                     ir_expression *const r058E = logic_and(r058D, r0583);
                     ir_expression *const r058F = logic_or(r0588, r058E);
                     ir_if *f0587 = new(mem_ctx) ir_if(operand(r058F).val);
                     exec_list *const f0587_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0587->then_instructions;

                        ir_variable *const r0590 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0590);
                        ir_expression *const r0591 = lshift(r01E3, body.constant(int(31)));
                        body.emit(assign(r0590, add(r0591, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0590, body.constant(0u), 0x01));

                        body.emit(assign(r0582, r0590, 0x03));

                        body.emit(assign(r0581, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0587->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0593 = less(r053E, body.constant(int(0)));
                        ir_if *f0592 = new(mem_ctx) ir_if(operand(r0593).val);
                        exec_list *const f0592_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0592->then_instructions;

                           ir_variable *const r0594 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0594, r0541, 0x01));

                           ir_variable *const r0595 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0595, neg(r053E), 0x01));

                           ir_variable *const r0596 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0596);
                           ir_variable *const r0597 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0597);
                           ir_variable *const r0598 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0598);
                           ir_variable *const r0599 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r059A = neg(r0595);
                           body.emit(assign(r0599, bit_and(r059A, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r059C = equal(r0595, body.constant(int(0)));
                           ir_if *f059B = new(mem_ctx) ir_if(operand(r059C).val);
                           exec_list *const f059B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f059B->then_instructions;

                              body.emit(assign(r0596, r0541, 0x01));

                              body.emit(assign(r0597, r0540, 0x01));

                              body.emit(assign(r0598, r053F, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f059B->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r059E = less(r0595, body.constant(int(32)));
                              ir_if *f059D = new(mem_ctx) ir_if(operand(r059E).val);
                              exec_list *const f059D_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f059D->then_instructions;

                                 body.emit(assign(r0596, lshift(r0540, r0599), 0x01));

                                 ir_expression *const r059F = lshift(r053F, r0599);
                                 ir_expression *const r05A0 = rshift(r0540, r0595);
                                 body.emit(assign(r0597, bit_or(r059F, r05A0), 0x01));

                                 body.emit(assign(r0598, rshift(r053F, r0595), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f059D->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05A2 = equal(r0595, body.constant(int(32)));
                                 ir_if *f05A1 = new(mem_ctx) ir_if(operand(r05A2).val);
                                 exec_list *const f05A1_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05A1->then_instructions;

                                    body.emit(assign(r0596, r0540, 0x01));

                                    body.emit(assign(r0597, r053F, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05A1->else_instructions;

                                    body.emit(assign(r0594, bit_or(r0541, r0540), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r05A4 = less(r0595, body.constant(int(64)));
                                    ir_if *f05A3 = new(mem_ctx) ir_if(operand(r05A4).val);
                                    exec_list *const f05A3_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f05A3->then_instructions;

                                       body.emit(assign(r0596, lshift(r053F, r0599), 0x01));

                                       ir_expression *const r05A5 = bit_and(r0595, body.constant(int(31)));
                                       body.emit(assign(r0597, rshift(r053F, r05A5), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f05A3->else_instructions;

                                       ir_variable *const r05A6 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r05A8 = equal(r0595, body.constant(int(64)));
                                       ir_if *f05A7 = new(mem_ctx) ir_if(operand(r05A8).val);
                                       exec_list *const f05A7_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f05A7->then_instructions;

                                          body.emit(assign(r05A6, r053F, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f05A7->else_instructions;

                                          ir_expression *const r05A9 = nequal(r053F, body.constant(0u));
                                          ir_expression *const r05AA = expr(ir_unop_b2i, r05A9);
                                          body.emit(assign(r05A6, expr(ir_unop_i2u, r05AA), 0x01));


                                       body.instructions = f05A7_parent_instructions;
                                       body.emit(f05A7);

                                       /* END IF */

                                       body.emit(assign(r0596, r05A6, 0x01));

                                       body.emit(assign(r0597, body.constant(0u), 0x01));


                                    body.instructions = f05A3_parent_instructions;
                                    body.emit(f05A3);

                                    /* END IF */


                                 body.instructions = f05A1_parent_instructions;
                                 body.emit(f05A1);

                                 /* END IF */

                                 body.emit(assign(r0598, body.constant(0u), 0x01));


                              body.instructions = f059D_parent_instructions;
                              body.emit(f059D);

                              /* END IF */

                              ir_expression *const r05AB = nequal(r0594, body.constant(0u));
                              ir_expression *const r05AC = expr(ir_unop_b2i, r05AB);
                              ir_expression *const r05AD = expr(ir_unop_i2u, r05AC);
                              body.emit(assign(r0596, bit_or(r0596, r05AD), 0x01));


                           body.instructions = f059B_parent_instructions;
                           body.emit(f059B);

                           /* END IF */

                           body.emit(assign(r057E, r0598, 0x01));

                           body.emit(assign(r057F, r0597, 0x01));

                           body.emit(assign(r0580, r0596, 0x01));

                           body.emit(assign(r057D, body.constant(int(0)), 0x01));

                           body.emit(assign(r0583, less(r0596, body.constant(0u)), 0x01));


                        body.instructions = f0592_parent_instructions;
                        body.emit(f0592);

                        /* END IF */


                     body.instructions = f0587_parent_instructions;
                     body.emit(f0587);

                     /* END IF */


                  body.instructions = f0585_parent_instructions;
                  body.emit(f0585);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f05AE = new(mem_ctx) ir_if(operand(r0581).val);
                  exec_list *const f05AE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05AE->then_instructions;

                     /* IF CONDITION */
                     ir_if *f05AF = new(mem_ctx) ir_if(operand(r0583).val);
                     exec_list *const f05AF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05AF->then_instructions;

                        ir_variable *const r05B0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r05B0, add(r057F, body.constant(1u)), 0x01));

                        ir_expression *const r05B1 = less(r05B0, r057F);
                        ir_expression *const r05B2 = expr(ir_unop_b2i, r05B1);
                        ir_expression *const r05B3 = expr(ir_unop_i2u, r05B2);
                        body.emit(assign(r057E, add(r057E, r05B3), 0x01));

                        ir_expression *const r05B4 = equal(r0580, body.constant(0u));
                        ir_expression *const r05B5 = expr(ir_unop_b2i, r05B4);
                        ir_expression *const r05B6 = expr(ir_unop_i2u, r05B5);
                        ir_expression *const r05B7 = add(r0580, r05B6);
                        ir_expression *const r05B8 = bit_and(r05B7, body.constant(1u));
                        ir_expression *const r05B9 = expr(ir_unop_bit_not, r05B8);
                        body.emit(assign(r057F, bit_and(r05B0, r05B9), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05AF->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05BB = bit_or(r057E, r057F);
                        ir_expression *const r05BC = equal(r05BB, body.constant(0u));
                        ir_if *f05BA = new(mem_ctx) ir_if(operand(r05BC).val);
                        exec_list *const f05BA_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05BA->then_instructions;

                           body.emit(assign(r057D, body.constant(int(0)), 0x01));


                        body.instructions = f05BA_parent_instructions;
                        body.emit(f05BA);

                        /* END IF */


                     body.instructions = f05AF_parent_instructions;
                     body.emit(f05AF);

                     /* END IF */

                     ir_variable *const r05BD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r05BD);
                     ir_expression *const r05BE = lshift(r01E3, body.constant(int(31)));
                     ir_expression *const r05BF = expr(ir_unop_i2u, r057D);
                     ir_expression *const r05C0 = lshift(r05BF, body.constant(int(20)));
                     ir_expression *const r05C1 = add(r05BE, r05C0);
                     body.emit(assign(r05BD, add(r05C1, r057E), 0x02));

                     body.emit(assign(r05BD, r057F, 0x01));

                     body.emit(assign(r0582, r05BD, 0x03));

                     body.emit(assign(r0581, body.constant(false), 0x01));


                  body.instructions = f05AE_parent_instructions;
                  body.emit(f05AE);

                  /* END IF */

                  body.emit(assign(r01E2, r0582, 0x03));

                  body.emit(assign(r01E1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0536->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05C3 = less(r0376, r0374);
                  ir_if *f05C2 = new(mem_ctx) ir_if(operand(r05C3).val);
                  exec_list *const f05C2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05C2->then_instructions;

                     ir_variable *const r05C4 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_variable *const r05C5 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r05C5, sub(r0375, r0377), 0x01));

                     ir_expression *const r05C6 = sub(r0374, r0376);
                     ir_expression *const r05C7 = less(r0375, r0377);
                     ir_expression *const r05C8 = expr(ir_unop_b2i, r05C7);
                     ir_expression *const r05C9 = expr(ir_unop_i2u, r05C8);
                     body.emit(assign(r05C4, sub(r05C6, r05C9), 0x01));

                     body.emit(assign(r01E3, bit_xor(r01E3, body.constant(1u)), 0x01));

                     body.emit(assign(r0378, add(r0372, body.constant(int(-1))), 0x01));

                     ir_variable *const r05CA = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05CA, add(r0378, body.constant(int(-10))), 0x01));

                     ir_variable *const r05CB = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r05CB, r05C4, 0x01));

                     ir_variable *const r05CC = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r05CC, r05C5, 0x01));

                     ir_variable *const r05CD = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r05CD);
                     ir_variable *const r05CE = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05CE);
                     /* IF CONDITION */
                     ir_expression *const r05D0 = equal(r05C4, body.constant(0u));
                     ir_if *f05CF = new(mem_ctx) ir_if(operand(r05D0).val);
                     exec_list *const f05CF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05CF->then_instructions;

                        body.emit(assign(r05CB, r05C5, 0x01));

                        body.emit(assign(r05CC, body.constant(0u), 0x01));

                        body.emit(assign(r05CA, add(r05CA, body.constant(int(-32))), 0x01));


                     body.instructions = f05CF_parent_instructions;
                     body.emit(f05CF);

                     /* END IF */

                     ir_variable *const r05D1 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r05D1, r05CB, 0x01));

                     ir_variable *const r05D2 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r05D3 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05D3);
                     /* IF CONDITION */
                     ir_expression *const r05D5 = equal(r05CB, body.constant(0u));
                     ir_if *f05D4 = new(mem_ctx) ir_if(operand(r05D5).val);
                     exec_list *const f05D4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05D4->then_instructions;

                        body.emit(assign(r05D2, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05D4->else_instructions;

                        body.emit(assign(r05D3, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05D7 = bit_and(r05CB, body.constant(4294901760u));
                        ir_expression *const r05D8 = equal(r05D7, body.constant(0u));
                        ir_if *f05D6 = new(mem_ctx) ir_if(operand(r05D8).val);
                        exec_list *const f05D6_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05D6->then_instructions;

                           body.emit(assign(r05D3, body.constant(int(16)), 0x01));

                           body.emit(assign(r05D1, lshift(r05CB, body.constant(int(16))), 0x01));


                        body.instructions = f05D6_parent_instructions;
                        body.emit(f05D6);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05DA = bit_and(r05D1, body.constant(4278190080u));
                        ir_expression *const r05DB = equal(r05DA, body.constant(0u));
                        ir_if *f05D9 = new(mem_ctx) ir_if(operand(r05DB).val);
                        exec_list *const f05D9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05D9->then_instructions;

                           body.emit(assign(r05D3, add(r05D3, body.constant(int(8))), 0x01));

                           body.emit(assign(r05D1, lshift(r05D1, body.constant(int(8))), 0x01));


                        body.instructions = f05D9_parent_instructions;
                        body.emit(f05D9);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05DD = bit_and(r05D1, body.constant(4026531840u));
                        ir_expression *const r05DE = equal(r05DD, body.constant(0u));
                        ir_if *f05DC = new(mem_ctx) ir_if(operand(r05DE).val);
                        exec_list *const f05DC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05DC->then_instructions;

                           body.emit(assign(r05D3, add(r05D3, body.constant(int(4))), 0x01));

                           body.emit(assign(r05D1, lshift(r05D1, body.constant(int(4))), 0x01));


                        body.instructions = f05DC_parent_instructions;
                        body.emit(f05DC);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05E0 = bit_and(r05D1, body.constant(3221225472u));
                        ir_expression *const r05E1 = equal(r05E0, body.constant(0u));
                        ir_if *f05DF = new(mem_ctx) ir_if(operand(r05E1).val);
                        exec_list *const f05DF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05DF->then_instructions;

                           body.emit(assign(r05D3, add(r05D3, body.constant(int(2))), 0x01));

                           body.emit(assign(r05D1, lshift(r05D1, body.constant(int(2))), 0x01));


                        body.instructions = f05DF_parent_instructions;
                        body.emit(f05DF);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05E3 = bit_and(r05D1, body.constant(2147483648u));
                        ir_expression *const r05E4 = equal(r05E3, body.constant(0u));
                        ir_if *f05E2 = new(mem_ctx) ir_if(operand(r05E4).val);
                        exec_list *const f05E2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E2->then_instructions;

                           body.emit(assign(r05D3, add(r05D3, body.constant(int(1))), 0x01));


                        body.instructions = f05E2_parent_instructions;
                        body.emit(f05E2);

                        /* END IF */

                        body.emit(assign(r05D2, r05D3, 0x01));


                     body.instructions = f05D4_parent_instructions;
                     body.emit(f05D4);

                     /* END IF */

                     body.emit(assign(r05CE, add(r05D2, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05E6 = gequal(r05CE, body.constant(int(0)));
                     ir_if *f05E5 = new(mem_ctx) ir_if(operand(r05E6).val);
                     exec_list *const f05E5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05E5->then_instructions;

                        body.emit(assign(r05CD, body.constant(0u), 0x01));

                        ir_variable *const r05E7 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r05E7, lshift(r05CC, r05CE), 0x01));

                        ir_variable *const r05E8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r05EA = equal(r05CE, body.constant(int(0)));
                        ir_if *f05E9 = new(mem_ctx) ir_if(operand(r05EA).val);
                        exec_list *const f05E9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E9->then_instructions;

                           body.emit(assign(r05E8, r05CB, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05E9->else_instructions;

                           ir_expression *const r05EB = lshift(r05CB, r05CE);
                           ir_expression *const r05EC = neg(r05CE);
                           ir_expression *const r05ED = bit_and(r05EC, body.constant(int(31)));
                           ir_expression *const r05EE = rshift(r05CC, r05ED);
                           body.emit(assign(r05E8, bit_or(r05EB, r05EE), 0x01));


                        body.instructions = f05E9_parent_instructions;
                        body.emit(f05E9);

                        /* END IF */

                        body.emit(assign(r05CB, r05E8, 0x01));

                        body.emit(assign(r05CC, r05E7, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05E5->else_instructions;

                        ir_variable *const r05EF = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r05EF, body.constant(0u), 0x01));

                        ir_variable *const r05F0 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r05F0, neg(r05CE), 0x01));

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

                           body.emit(assign(r05F1, r05EF, 0x01));

                           body.emit(assign(r05F2, r05CC, 0x01));

                           body.emit(assign(r05F3, r05CB, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05F6->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05F9 = less(r05F0, body.constant(int(32)));
                           ir_if *f05F8 = new(mem_ctx) ir_if(operand(r05F9).val);
                           exec_list *const f05F8_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05F8->then_instructions;

                              body.emit(assign(r05F1, lshift(r05CC, r05F4), 0x01));

                              ir_expression *const r05FA = lshift(r05CB, r05F4);
                              ir_expression *const r05FB = rshift(r05CC, r05F0);
                              body.emit(assign(r05F2, bit_or(r05FA, r05FB), 0x01));

                              body.emit(assign(r05F3, rshift(r05CB, r05F0), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05F8->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05FD = equal(r05F0, body.constant(int(32)));
                              ir_if *f05FC = new(mem_ctx) ir_if(operand(r05FD).val);
                              exec_list *const f05FC_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05FC->then_instructions;

                                 body.emit(assign(r05F1, r05CC, 0x01));

                                 body.emit(assign(r05F2, r05CB, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05FC->else_instructions;

                                 body.emit(assign(r05EF, bit_or(body.constant(0u), r05CC), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r05FF = less(r05F0, body.constant(int(64)));
                                 ir_if *f05FE = new(mem_ctx) ir_if(operand(r05FF).val);
                                 exec_list *const f05FE_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05FE->then_instructions;

                                    body.emit(assign(r05F1, lshift(r05CB, r05F4), 0x01));

                                    ir_expression *const r0600 = bit_and(r05F0, body.constant(int(31)));
                                    body.emit(assign(r05F2, rshift(r05CB, r0600), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05FE->else_instructions;

                                    ir_variable *const r0601 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r0603 = equal(r05F0, body.constant(int(64)));
                                    ir_if *f0602 = new(mem_ctx) ir_if(operand(r0603).val);
                                    exec_list *const f0602_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0602->then_instructions;

                                       body.emit(assign(r0601, r05CB, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0602->else_instructions;

                                       ir_expression *const r0604 = nequal(r05CB, body.constant(0u));
                                       ir_expression *const r0605 = expr(ir_unop_b2i, r0604);
                                       body.emit(assign(r0601, expr(ir_unop_i2u, r0605), 0x01));


                                    body.instructions = f0602_parent_instructions;
                                    body.emit(f0602);

                                    /* END IF */

                                    body.emit(assign(r05F1, r0601, 0x01));

                                    body.emit(assign(r05F2, body.constant(0u), 0x01));


                                 body.instructions = f05FE_parent_instructions;
                                 body.emit(f05FE);

                                 /* END IF */


                              body.instructions = f05FC_parent_instructions;
                              body.emit(f05FC);

                              /* END IF */

                              body.emit(assign(r05F3, body.constant(0u), 0x01));


                           body.instructions = f05F8_parent_instructions;
                           body.emit(f05F8);

                           /* END IF */

                           ir_expression *const r0606 = nequal(r05EF, body.constant(0u));
                           ir_expression *const r0607 = expr(ir_unop_b2i, r0606);
                           ir_expression *const r0608 = expr(ir_unop_i2u, r0607);
                           body.emit(assign(r05F1, bit_or(r05F1, r0608), 0x01));


                        body.instructions = f05F6_parent_instructions;
                        body.emit(f05F6);

                        /* END IF */

                        body.emit(assign(r05CB, r05F3, 0x01));

                        body.emit(assign(r05CC, r05F2, 0x01));

                        body.emit(assign(r05CD, r05F1, 0x01));


                     body.instructions = f05E5_parent_instructions;
                     body.emit(f05E5);

                     /* END IF */

                     body.emit(assign(r05CA, sub(r05CA, r05CE), 0x01));

                     ir_variable *const r0609 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r0609, r05CA, 0x01));

                     ir_variable *const r060A = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r060A, r05CB, 0x01));

                     ir_variable *const r060B = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r060B, r05CC, 0x01));

                     ir_variable *const r060C = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r060C, r05CD, 0x01));

                     ir_variable *const r060D = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r060D, body.constant(true), 0x01));

                     ir_variable *const r060E = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r060F = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r060F);
                     ir_expression *const r0610 = expr(ir_unop_u2i, r05CD);
                     body.emit(assign(r060F, less(r0610, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0612 = gequal(r05CA, body.constant(int(2045)));
                     ir_if *f0611 = new(mem_ctx) ir_if(operand(r0612).val);
                     exec_list *const f0611_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0611->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0614 = less(body.constant(int(2045)), r05CA);
                        ir_expression *const r0615 = equal(r05CA, body.constant(int(2045)));
                        ir_expression *const r0616 = equal(body.constant(2097151u), r05CB);
                        ir_expression *const r0617 = equal(body.constant(4294967295u), r05CC);
                        ir_expression *const r0618 = logic_and(r0616, r0617);
                        ir_expression *const r0619 = logic_and(r0615, r0618);
                        ir_expression *const r061A = logic_and(r0619, r060F);
                        ir_expression *const r061B = logic_or(r0614, r061A);
                        ir_if *f0613 = new(mem_ctx) ir_if(operand(r061B).val);
                        exec_list *const f0613_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0613->then_instructions;

                           ir_variable *const r061C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r061C);
                           ir_expression *const r061D = lshift(r01E3, body.constant(int(31)));
                           body.emit(assign(r061C, add(r061D, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r061C, body.constant(0u), 0x01));

                           body.emit(assign(r060E, r061C, 0x03));

                           body.emit(assign(r060D, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0613->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r061F = less(r05CA, body.constant(int(0)));
                           ir_if *f061E = new(mem_ctx) ir_if(operand(r061F).val);
                           exec_list *const f061E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f061E->then_instructions;

                              ir_variable *const r0620 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r0620, r05CD, 0x01));

                              ir_variable *const r0621 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0621, neg(r05CA), 0x01));

                              ir_variable *const r0622 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0622);
                              ir_variable *const r0623 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0623);
                              ir_variable *const r0624 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0624);
                              ir_variable *const r0625 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0626 = neg(r0621);
                              body.emit(assign(r0625, bit_and(r0626, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0628 = equal(r0621, body.constant(int(0)));
                              ir_if *f0627 = new(mem_ctx) ir_if(operand(r0628).val);
                              exec_list *const f0627_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0627->then_instructions;

                                 body.emit(assign(r0622, r05CD, 0x01));

                                 body.emit(assign(r0623, r05CC, 0x01));

                                 body.emit(assign(r0624, r05CB, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0627->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r062A = less(r0621, body.constant(int(32)));
                                 ir_if *f0629 = new(mem_ctx) ir_if(operand(r062A).val);
                                 exec_list *const f0629_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0629->then_instructions;

                                    body.emit(assign(r0622, lshift(r05CC, r0625), 0x01));

                                    ir_expression *const r062B = lshift(r05CB, r0625);
                                    ir_expression *const r062C = rshift(r05CC, r0621);
                                    body.emit(assign(r0623, bit_or(r062B, r062C), 0x01));

                                    body.emit(assign(r0624, rshift(r05CB, r0621), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0629->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r062E = equal(r0621, body.constant(int(32)));
                                    ir_if *f062D = new(mem_ctx) ir_if(operand(r062E).val);
                                    exec_list *const f062D_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f062D->then_instructions;

                                       body.emit(assign(r0622, r05CC, 0x01));

                                       body.emit(assign(r0623, r05CB, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f062D->else_instructions;

                                       body.emit(assign(r0620, bit_or(r05CD, r05CC), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r0630 = less(r0621, body.constant(int(64)));
                                       ir_if *f062F = new(mem_ctx) ir_if(operand(r0630).val);
                                       exec_list *const f062F_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f062F->then_instructions;

                                          body.emit(assign(r0622, lshift(r05CB, r0625), 0x01));

                                          ir_expression *const r0631 = bit_and(r0621, body.constant(int(31)));
                                          body.emit(assign(r0623, rshift(r05CB, r0631), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f062F->else_instructions;

                                          ir_variable *const r0632 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r0634 = equal(r0621, body.constant(int(64)));
                                          ir_if *f0633 = new(mem_ctx) ir_if(operand(r0634).val);
                                          exec_list *const f0633_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0633->then_instructions;

                                             body.emit(assign(r0632, r05CB, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0633->else_instructions;

                                             ir_expression *const r0635 = nequal(r05CB, body.constant(0u));
                                             ir_expression *const r0636 = expr(ir_unop_b2i, r0635);
                                             body.emit(assign(r0632, expr(ir_unop_i2u, r0636), 0x01));


                                          body.instructions = f0633_parent_instructions;
                                          body.emit(f0633);

                                          /* END IF */

                                          body.emit(assign(r0622, r0632, 0x01));

                                          body.emit(assign(r0623, body.constant(0u), 0x01));


                                       body.instructions = f062F_parent_instructions;
                                       body.emit(f062F);

                                       /* END IF */


                                    body.instructions = f062D_parent_instructions;
                                    body.emit(f062D);

                                    /* END IF */

                                    body.emit(assign(r0624, body.constant(0u), 0x01));


                                 body.instructions = f0629_parent_instructions;
                                 body.emit(f0629);

                                 /* END IF */

                                 ir_expression *const r0637 = nequal(r0620, body.constant(0u));
                                 ir_expression *const r0638 = expr(ir_unop_b2i, r0637);
                                 ir_expression *const r0639 = expr(ir_unop_i2u, r0638);
                                 body.emit(assign(r0622, bit_or(r0622, r0639), 0x01));


                              body.instructions = f0627_parent_instructions;
                              body.emit(f0627);

                              /* END IF */

                              body.emit(assign(r060A, r0624, 0x01));

                              body.emit(assign(r060B, r0623, 0x01));

                              body.emit(assign(r060C, r0622, 0x01));

                              body.emit(assign(r0609, body.constant(int(0)), 0x01));

                              body.emit(assign(r060F, less(r0622, body.constant(0u)), 0x01));


                           body.instructions = f061E_parent_instructions;
                           body.emit(f061E);

                           /* END IF */


                        body.instructions = f0613_parent_instructions;
                        body.emit(f0613);

                        /* END IF */


                     body.instructions = f0611_parent_instructions;
                     body.emit(f0611);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f063A = new(mem_ctx) ir_if(operand(r060D).val);
                     exec_list *const f063A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f063A->then_instructions;

                        /* IF CONDITION */
                        ir_if *f063B = new(mem_ctx) ir_if(operand(r060F).val);
                        exec_list *const f063B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f063B->then_instructions;

                           ir_variable *const r063C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r063C, add(r060B, body.constant(1u)), 0x01));

                           ir_expression *const r063D = less(r063C, r060B);
                           ir_expression *const r063E = expr(ir_unop_b2i, r063D);
                           ir_expression *const r063F = expr(ir_unop_i2u, r063E);
                           body.emit(assign(r060A, add(r060A, r063F), 0x01));

                           ir_expression *const r0640 = equal(r060C, body.constant(0u));
                           ir_expression *const r0641 = expr(ir_unop_b2i, r0640);
                           ir_expression *const r0642 = expr(ir_unop_i2u, r0641);
                           ir_expression *const r0643 = add(r060C, r0642);
                           ir_expression *const r0644 = bit_and(r0643, body.constant(1u));
                           ir_expression *const r0645 = expr(ir_unop_bit_not, r0644);
                           body.emit(assign(r060B, bit_and(r063C, r0645), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f063B->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0647 = bit_or(r060A, r060B);
                           ir_expression *const r0648 = equal(r0647, body.constant(0u));
                           ir_if *f0646 = new(mem_ctx) ir_if(operand(r0648).val);
                           exec_list *const f0646_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0646->then_instructions;

                              body.emit(assign(r0609, body.constant(int(0)), 0x01));


                           body.instructions = f0646_parent_instructions;
                           body.emit(f0646);

                           /* END IF */


                        body.instructions = f063B_parent_instructions;
                        body.emit(f063B);

                        /* END IF */

                        ir_variable *const r0649 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0649);
                        ir_expression *const r064A = lshift(r01E3, body.constant(int(31)));
                        ir_expression *const r064B = expr(ir_unop_i2u, r0609);
                        ir_expression *const r064C = lshift(r064B, body.constant(int(20)));
                        ir_expression *const r064D = add(r064A, r064C);
                        body.emit(assign(r0649, add(r064D, r060A), 0x02));

                        body.emit(assign(r0649, r060B, 0x01));

                        body.emit(assign(r060E, r0649, 0x03));

                        body.emit(assign(r060D, body.constant(false), 0x01));


                     body.instructions = f063A_parent_instructions;
                     body.emit(f063A);

                     /* END IF */

                     body.emit(assign(r01E2, r060E, 0x03));

                     body.emit(assign(r01E1, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05C2->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r064F = less(r0375, r0377);
                     ir_if *f064E = new(mem_ctx) ir_if(operand(r064F).val);
                     exec_list *const f064E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f064E->then_instructions;

                        ir_variable *const r0650 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_variable *const r0651 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r0651, sub(r0377, r0375), 0x01));

                        ir_expression *const r0652 = sub(r0376, r0374);
                        ir_expression *const r0653 = less(r0377, r0375);
                        ir_expression *const r0654 = expr(ir_unop_b2i, r0653);
                        ir_expression *const r0655 = expr(ir_unop_i2u, r0654);
                        body.emit(assign(r0650, sub(r0652, r0655), 0x01));

                        body.emit(assign(r0378, add(r0373, body.constant(int(-1))), 0x01));

                        ir_variable *const r0656 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0656, add(r0378, body.constant(int(-10))), 0x01));

                        ir_variable *const r0657 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r0657, r0650, 0x01));

                        ir_variable *const r0658 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0658, r0651, 0x01));

                        ir_variable *const r0659 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0659);
                        ir_variable *const r065A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r065A);
                        /* IF CONDITION */
                        ir_expression *const r065C = equal(r0650, body.constant(0u));
                        ir_if *f065B = new(mem_ctx) ir_if(operand(r065C).val);
                        exec_list *const f065B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f065B->then_instructions;

                           body.emit(assign(r0657, r0651, 0x01));

                           body.emit(assign(r0658, body.constant(0u), 0x01));

                           body.emit(assign(r0656, add(r0656, body.constant(int(-32))), 0x01));


                        body.instructions = f065B_parent_instructions;
                        body.emit(f065B);

                        /* END IF */

                        ir_variable *const r065D = body.make_temp(glsl_type::uint_type, "a");
                        body.emit(assign(r065D, r0657, 0x01));

                        ir_variable *const r065E = body.make_temp(glsl_type::int_type, "return_value");
                        ir_variable *const r065F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r065F);
                        /* IF CONDITION */
                        ir_expression *const r0661 = equal(r0657, body.constant(0u));
                        ir_if *f0660 = new(mem_ctx) ir_if(operand(r0661).val);
                        exec_list *const f0660_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0660->then_instructions;

                           body.emit(assign(r065E, body.constant(int(32)), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0660->else_instructions;

                           body.emit(assign(r065F, body.constant(int(0)), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0663 = bit_and(r0657, body.constant(4294901760u));
                           ir_expression *const r0664 = equal(r0663, body.constant(0u));
                           ir_if *f0662 = new(mem_ctx) ir_if(operand(r0664).val);
                           exec_list *const f0662_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0662->then_instructions;

                              body.emit(assign(r065F, body.constant(int(16)), 0x01));

                              body.emit(assign(r065D, lshift(r0657, body.constant(int(16))), 0x01));


                           body.instructions = f0662_parent_instructions;
                           body.emit(f0662);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0666 = bit_and(r065D, body.constant(4278190080u));
                           ir_expression *const r0667 = equal(r0666, body.constant(0u));
                           ir_if *f0665 = new(mem_ctx) ir_if(operand(r0667).val);
                           exec_list *const f0665_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0665->then_instructions;

                              body.emit(assign(r065F, add(r065F, body.constant(int(8))), 0x01));

                              body.emit(assign(r065D, lshift(r065D, body.constant(int(8))), 0x01));


                           body.instructions = f0665_parent_instructions;
                           body.emit(f0665);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0669 = bit_and(r065D, body.constant(4026531840u));
                           ir_expression *const r066A = equal(r0669, body.constant(0u));
                           ir_if *f0668 = new(mem_ctx) ir_if(operand(r066A).val);
                           exec_list *const f0668_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0668->then_instructions;

                              body.emit(assign(r065F, add(r065F, body.constant(int(4))), 0x01));

                              body.emit(assign(r065D, lshift(r065D, body.constant(int(4))), 0x01));


                           body.instructions = f0668_parent_instructions;
                           body.emit(f0668);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r066C = bit_and(r065D, body.constant(3221225472u));
                           ir_expression *const r066D = equal(r066C, body.constant(0u));
                           ir_if *f066B = new(mem_ctx) ir_if(operand(r066D).val);
                           exec_list *const f066B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f066B->then_instructions;

                              body.emit(assign(r065F, add(r065F, body.constant(int(2))), 0x01));

                              body.emit(assign(r065D, lshift(r065D, body.constant(int(2))), 0x01));


                           body.instructions = f066B_parent_instructions;
                           body.emit(f066B);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r066F = bit_and(r065D, body.constant(2147483648u));
                           ir_expression *const r0670 = equal(r066F, body.constant(0u));
                           ir_if *f066E = new(mem_ctx) ir_if(operand(r0670).val);
                           exec_list *const f066E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f066E->then_instructions;

                              body.emit(assign(r065F, add(r065F, body.constant(int(1))), 0x01));


                           body.instructions = f066E_parent_instructions;
                           body.emit(f066E);

                           /* END IF */

                           body.emit(assign(r065E, r065F, 0x01));


                        body.instructions = f0660_parent_instructions;
                        body.emit(f0660);

                        /* END IF */

                        body.emit(assign(r065A, add(r065E, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0672 = gequal(r065A, body.constant(int(0)));
                        ir_if *f0671 = new(mem_ctx) ir_if(operand(r0672).val);
                        exec_list *const f0671_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0671->then_instructions;

                           body.emit(assign(r0659, body.constant(0u), 0x01));

                           ir_variable *const r0673 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r0673, lshift(r0658, r065A), 0x01));

                           ir_variable *const r0674 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0676 = equal(r065A, body.constant(int(0)));
                           ir_if *f0675 = new(mem_ctx) ir_if(operand(r0676).val);
                           exec_list *const f0675_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0675->then_instructions;

                              body.emit(assign(r0674, r0657, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0675->else_instructions;

                              ir_expression *const r0677 = lshift(r0657, r065A);
                              ir_expression *const r0678 = neg(r065A);
                              ir_expression *const r0679 = bit_and(r0678, body.constant(int(31)));
                              ir_expression *const r067A = rshift(r0658, r0679);
                              body.emit(assign(r0674, bit_or(r0677, r067A), 0x01));


                           body.instructions = f0675_parent_instructions;
                           body.emit(f0675);

                           /* END IF */

                           body.emit(assign(r0657, r0674, 0x01));

                           body.emit(assign(r0658, r0673, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0671->else_instructions;

                           ir_variable *const r067B = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r067B, body.constant(0u), 0x01));

                           ir_variable *const r067C = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r067C, neg(r065A), 0x01));

                           ir_variable *const r067D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r067D);
                           ir_variable *const r067E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r067E);
                           ir_variable *const r067F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r067F);
                           ir_variable *const r0680 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0681 = neg(r067C);
                           body.emit(assign(r0680, bit_and(r0681, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0683 = equal(r067C, body.constant(int(0)));
                           ir_if *f0682 = new(mem_ctx) ir_if(operand(r0683).val);
                           exec_list *const f0682_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0682->then_instructions;

                              body.emit(assign(r067D, r067B, 0x01));

                              body.emit(assign(r067E, r0658, 0x01));

                              body.emit(assign(r067F, r0657, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0682->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0685 = less(r067C, body.constant(int(32)));
                              ir_if *f0684 = new(mem_ctx) ir_if(operand(r0685).val);
                              exec_list *const f0684_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0684->then_instructions;

                                 body.emit(assign(r067D, lshift(r0658, r0680), 0x01));

                                 ir_expression *const r0686 = lshift(r0657, r0680);
                                 ir_expression *const r0687 = rshift(r0658, r067C);
                                 body.emit(assign(r067E, bit_or(r0686, r0687), 0x01));

                                 body.emit(assign(r067F, rshift(r0657, r067C), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0684->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0689 = equal(r067C, body.constant(int(32)));
                                 ir_if *f0688 = new(mem_ctx) ir_if(operand(r0689).val);
                                 exec_list *const f0688_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0688->then_instructions;

                                    body.emit(assign(r067D, r0658, 0x01));

                                    body.emit(assign(r067E, r0657, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0688->else_instructions;

                                    body.emit(assign(r067B, bit_or(body.constant(0u), r0658), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r068B = less(r067C, body.constant(int(64)));
                                    ir_if *f068A = new(mem_ctx) ir_if(operand(r068B).val);
                                    exec_list *const f068A_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f068A->then_instructions;

                                       body.emit(assign(r067D, lshift(r0657, r0680), 0x01));

                                       ir_expression *const r068C = bit_and(r067C, body.constant(int(31)));
                                       body.emit(assign(r067E, rshift(r0657, r068C), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f068A->else_instructions;

                                       ir_variable *const r068D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r068F = equal(r067C, body.constant(int(64)));
                                       ir_if *f068E = new(mem_ctx) ir_if(operand(r068F).val);
                                       exec_list *const f068E_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f068E->then_instructions;

                                          body.emit(assign(r068D, r0657, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f068E->else_instructions;

                                          ir_expression *const r0690 = nequal(r0657, body.constant(0u));
                                          ir_expression *const r0691 = expr(ir_unop_b2i, r0690);
                                          body.emit(assign(r068D, expr(ir_unop_i2u, r0691), 0x01));


                                       body.instructions = f068E_parent_instructions;
                                       body.emit(f068E);

                                       /* END IF */

                                       body.emit(assign(r067D, r068D, 0x01));

                                       body.emit(assign(r067E, body.constant(0u), 0x01));


                                    body.instructions = f068A_parent_instructions;
                                    body.emit(f068A);

                                    /* END IF */


                                 body.instructions = f0688_parent_instructions;
                                 body.emit(f0688);

                                 /* END IF */

                                 body.emit(assign(r067F, body.constant(0u), 0x01));


                              body.instructions = f0684_parent_instructions;
                              body.emit(f0684);

                              /* END IF */

                              ir_expression *const r0692 = nequal(r067B, body.constant(0u));
                              ir_expression *const r0693 = expr(ir_unop_b2i, r0692);
                              ir_expression *const r0694 = expr(ir_unop_i2u, r0693);
                              body.emit(assign(r067D, bit_or(r067D, r0694), 0x01));


                           body.instructions = f0682_parent_instructions;
                           body.emit(f0682);

                           /* END IF */

                           body.emit(assign(r0657, r067F, 0x01));

                           body.emit(assign(r0658, r067E, 0x01));

                           body.emit(assign(r0659, r067D, 0x01));


                        body.instructions = f0671_parent_instructions;
                        body.emit(f0671);

                        /* END IF */

                        body.emit(assign(r0656, sub(r0656, r065A), 0x01));

                        ir_variable *const r0695 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0695, r0656, 0x01));

                        ir_variable *const r0696 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r0696, r0657, 0x01));

                        ir_variable *const r0697 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0697, r0658, 0x01));

                        ir_variable *const r0698 = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r0698, r0659, 0x01));

                        ir_variable *const r0699 = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r0699, body.constant(true), 0x01));

                        ir_variable *const r069A = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r069B = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r069B);
                        ir_expression *const r069C = expr(ir_unop_u2i, r0659);
                        body.emit(assign(r069B, less(r069C, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r069E = gequal(r0656, body.constant(int(2045)));
                        ir_if *f069D = new(mem_ctx) ir_if(operand(r069E).val);
                        exec_list *const f069D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f069D->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r06A0 = less(body.constant(int(2045)), r0656);
                           ir_expression *const r06A1 = equal(r0656, body.constant(int(2045)));
                           ir_expression *const r06A2 = equal(body.constant(2097151u), r0657);
                           ir_expression *const r06A3 = equal(body.constant(4294967295u), r0658);
                           ir_expression *const r06A4 = logic_and(r06A2, r06A3);
                           ir_expression *const r06A5 = logic_and(r06A1, r06A4);
                           ir_expression *const r06A6 = logic_and(r06A5, r069B);
                           ir_expression *const r06A7 = logic_or(r06A0, r06A6);
                           ir_if *f069F = new(mem_ctx) ir_if(operand(r06A7).val);
                           exec_list *const f069F_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f069F->then_instructions;

                              ir_variable *const r06A8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r06A8);
                              ir_expression *const r06A9 = lshift(r01E3, body.constant(int(31)));
                              body.emit(assign(r06A8, add(r06A9, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r06A8, body.constant(0u), 0x01));

                              body.emit(assign(r069A, r06A8, 0x03));

                              body.emit(assign(r0699, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f069F->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06AB = less(r0656, body.constant(int(0)));
                              ir_if *f06AA = new(mem_ctx) ir_if(operand(r06AB).val);
                              exec_list *const f06AA_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06AA->then_instructions;

                                 ir_variable *const r06AC = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r06AC, r0659, 0x01));

                                 ir_variable *const r06AD = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r06AD, neg(r0656), 0x01));

                                 ir_variable *const r06AE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r06AE);
                                 ir_variable *const r06AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r06AF);
                                 ir_variable *const r06B0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r06B0);
                                 ir_variable *const r06B1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r06B2 = neg(r06AD);
                                 body.emit(assign(r06B1, bit_and(r06B2, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r06B4 = equal(r06AD, body.constant(int(0)));
                                 ir_if *f06B3 = new(mem_ctx) ir_if(operand(r06B4).val);
                                 exec_list *const f06B3_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06B3->then_instructions;

                                    body.emit(assign(r06AE, r0659, 0x01));

                                    body.emit(assign(r06AF, r0658, 0x01));

                                    body.emit(assign(r06B0, r0657, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06B3->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06B6 = less(r06AD, body.constant(int(32)));
                                    ir_if *f06B5 = new(mem_ctx) ir_if(operand(r06B6).val);
                                    exec_list *const f06B5_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06B5->then_instructions;

                                       body.emit(assign(r06AE, lshift(r0658, r06B1), 0x01));

                                       ir_expression *const r06B7 = lshift(r0657, r06B1);
                                       ir_expression *const r06B8 = rshift(r0658, r06AD);
                                       body.emit(assign(r06AF, bit_or(r06B7, r06B8), 0x01));

                                       body.emit(assign(r06B0, rshift(r0657, r06AD), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06B5->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r06BA = equal(r06AD, body.constant(int(32)));
                                       ir_if *f06B9 = new(mem_ctx) ir_if(operand(r06BA).val);
                                       exec_list *const f06B9_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06B9->then_instructions;

                                          body.emit(assign(r06AE, r0658, 0x01));

                                          body.emit(assign(r06AF, r0657, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06B9->else_instructions;

                                          body.emit(assign(r06AC, bit_or(r0659, r0658), 0x01));

                                          /* IF CONDITION */
                                          ir_expression *const r06BC = less(r06AD, body.constant(int(64)));
                                          ir_if *f06BB = new(mem_ctx) ir_if(operand(r06BC).val);
                                          exec_list *const f06BB_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f06BB->then_instructions;

                                             body.emit(assign(r06AE, lshift(r0657, r06B1), 0x01));

                                             ir_expression *const r06BD = bit_and(r06AD, body.constant(int(31)));
                                             body.emit(assign(r06AF, rshift(r0657, r06BD), 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f06BB->else_instructions;

                                             ir_variable *const r06BE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                             /* IF CONDITION */
                                             ir_expression *const r06C0 = equal(r06AD, body.constant(int(64)));
                                             ir_if *f06BF = new(mem_ctx) ir_if(operand(r06C0).val);
                                             exec_list *const f06BF_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f06BF->then_instructions;

                                                body.emit(assign(r06BE, r0657, 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f06BF->else_instructions;

                                                ir_expression *const r06C1 = nequal(r0657, body.constant(0u));
                                                ir_expression *const r06C2 = expr(ir_unop_b2i, r06C1);
                                                body.emit(assign(r06BE, expr(ir_unop_i2u, r06C2), 0x01));


                                             body.instructions = f06BF_parent_instructions;
                                             body.emit(f06BF);

                                             /* END IF */

                                             body.emit(assign(r06AE, r06BE, 0x01));

                                             body.emit(assign(r06AF, body.constant(0u), 0x01));


                                          body.instructions = f06BB_parent_instructions;
                                          body.emit(f06BB);

                                          /* END IF */


                                       body.instructions = f06B9_parent_instructions;
                                       body.emit(f06B9);

                                       /* END IF */

                                       body.emit(assign(r06B0, body.constant(0u), 0x01));


                                    body.instructions = f06B5_parent_instructions;
                                    body.emit(f06B5);

                                    /* END IF */

                                    ir_expression *const r06C3 = nequal(r06AC, body.constant(0u));
                                    ir_expression *const r06C4 = expr(ir_unop_b2i, r06C3);
                                    ir_expression *const r06C5 = expr(ir_unop_i2u, r06C4);
                                    body.emit(assign(r06AE, bit_or(r06AE, r06C5), 0x01));


                                 body.instructions = f06B3_parent_instructions;
                                 body.emit(f06B3);

                                 /* END IF */

                                 body.emit(assign(r0696, r06B0, 0x01));

                                 body.emit(assign(r0697, r06AF, 0x01));

                                 body.emit(assign(r0698, r06AE, 0x01));

                                 body.emit(assign(r0695, body.constant(int(0)), 0x01));

                                 body.emit(assign(r069B, less(r06AE, body.constant(0u)), 0x01));


                              body.instructions = f06AA_parent_instructions;
                              body.emit(f06AA);

                              /* END IF */


                           body.instructions = f069F_parent_instructions;
                           body.emit(f069F);

                           /* END IF */


                        body.instructions = f069D_parent_instructions;
                        body.emit(f069D);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f06C6 = new(mem_ctx) ir_if(operand(r0699).val);
                        exec_list *const f06C6_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06C6->then_instructions;

                           /* IF CONDITION */
                           ir_if *f06C7 = new(mem_ctx) ir_if(operand(r069B).val);
                           exec_list *const f06C7_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06C7->then_instructions;

                              ir_variable *const r06C8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r06C8, add(r0697, body.constant(1u)), 0x01));

                              ir_expression *const r06C9 = less(r06C8, r0697);
                              ir_expression *const r06CA = expr(ir_unop_b2i, r06C9);
                              ir_expression *const r06CB = expr(ir_unop_i2u, r06CA);
                              body.emit(assign(r0696, add(r0696, r06CB), 0x01));

                              ir_expression *const r06CC = equal(r0698, body.constant(0u));
                              ir_expression *const r06CD = expr(ir_unop_b2i, r06CC);
                              ir_expression *const r06CE = expr(ir_unop_i2u, r06CD);
                              ir_expression *const r06CF = add(r0698, r06CE);
                              ir_expression *const r06D0 = bit_and(r06CF, body.constant(1u));
                              ir_expression *const r06D1 = expr(ir_unop_bit_not, r06D0);
                              body.emit(assign(r0697, bit_and(r06C8, r06D1), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06C7->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06D3 = bit_or(r0696, r0697);
                              ir_expression *const r06D4 = equal(r06D3, body.constant(0u));
                              ir_if *f06D2 = new(mem_ctx) ir_if(operand(r06D4).val);
                              exec_list *const f06D2_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06D2->then_instructions;

                                 body.emit(assign(r0695, body.constant(int(0)), 0x01));


                              body.instructions = f06D2_parent_instructions;
                              body.emit(f06D2);

                              /* END IF */


                           body.instructions = f06C7_parent_instructions;
                           body.emit(f06C7);

                           /* END IF */

                           ir_variable *const r06D5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r06D5);
                           ir_expression *const r06D6 = lshift(r01E3, body.constant(int(31)));
                           ir_expression *const r06D7 = expr(ir_unop_i2u, r0695);
                           ir_expression *const r06D8 = lshift(r06D7, body.constant(int(20)));
                           ir_expression *const r06D9 = add(r06D6, r06D8);
                           body.emit(assign(r06D5, add(r06D9, r0696), 0x02));

                           body.emit(assign(r06D5, r0697, 0x01));

                           body.emit(assign(r069A, r06D5, 0x03));

                           body.emit(assign(r0699, body.constant(false), 0x01));


                        body.instructions = f06C6_parent_instructions;
                        body.emit(f06C6);

                        /* END IF */

                        body.emit(assign(r01E2, r069A, 0x03));

                        body.emit(assign(r01E1, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f064E->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r06DB = less(r0377, r0375);
                        ir_if *f06DA = new(mem_ctx) ir_if(operand(r06DB).val);
                        exec_list *const f06DA_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06DA->then_instructions;

                           ir_variable *const r06DC = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_variable *const r06DD = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r06DD, sub(r0375, r0377), 0x01));

                           ir_expression *const r06DE = sub(r0374, r0376);
                           ir_expression *const r06DF = less(r0375, r0377);
                           ir_expression *const r06E0 = expr(ir_unop_b2i, r06DF);
                           ir_expression *const r06E1 = expr(ir_unop_i2u, r06E0);
                           body.emit(assign(r06DC, sub(r06DE, r06E1), 0x01));

                           body.emit(assign(r01E3, bit_xor(r01E3, body.constant(1u)), 0x01));

                           body.emit(assign(r0378, add(r0372, body.constant(int(-1))), 0x01));

                           ir_variable *const r06E2 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06E2, add(r0378, body.constant(int(-10))), 0x01));

                           ir_variable *const r06E3 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r06E3, r06DC, 0x01));

                           ir_variable *const r06E4 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r06E4, r06DD, 0x01));

                           ir_variable *const r06E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r06E5);
                           ir_variable *const r06E6 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06E6);
                           /* IF CONDITION */
                           ir_expression *const r06E8 = equal(r06DC, body.constant(0u));
                           ir_if *f06E7 = new(mem_ctx) ir_if(operand(r06E8).val);
                           exec_list *const f06E7_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06E7->then_instructions;

                              body.emit(assign(r06E3, r06DD, 0x01));

                              body.emit(assign(r06E4, body.constant(0u), 0x01));

                              body.emit(assign(r06E2, add(r06E2, body.constant(int(-32))), 0x01));


                           body.instructions = f06E7_parent_instructions;
                           body.emit(f06E7);

                           /* END IF */

                           ir_variable *const r06E9 = body.make_temp(glsl_type::uint_type, "a");
                           body.emit(assign(r06E9, r06E3, 0x01));

                           ir_variable *const r06EA = body.make_temp(glsl_type::int_type, "return_value");
                           ir_variable *const r06EB = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06EB);
                           /* IF CONDITION */
                           ir_expression *const r06ED = equal(r06E3, body.constant(0u));
                           ir_if *f06EC = new(mem_ctx) ir_if(operand(r06ED).val);
                           exec_list *const f06EC_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06EC->then_instructions;

                              body.emit(assign(r06EA, body.constant(int(32)), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06EC->else_instructions;

                              body.emit(assign(r06EB, body.constant(int(0)), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r06EF = bit_and(r06E3, body.constant(4294901760u));
                              ir_expression *const r06F0 = equal(r06EF, body.constant(0u));
                              ir_if *f06EE = new(mem_ctx) ir_if(operand(r06F0).val);
                              exec_list *const f06EE_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06EE->then_instructions;

                                 body.emit(assign(r06EB, body.constant(int(16)), 0x01));

                                 body.emit(assign(r06E9, lshift(r06E3, body.constant(int(16))), 0x01));


                              body.instructions = f06EE_parent_instructions;
                              body.emit(f06EE);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r06F2 = bit_and(r06E9, body.constant(4278190080u));
                              ir_expression *const r06F3 = equal(r06F2, body.constant(0u));
                              ir_if *f06F1 = new(mem_ctx) ir_if(operand(r06F3).val);
                              exec_list *const f06F1_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06F1->then_instructions;

                                 body.emit(assign(r06EB, add(r06EB, body.constant(int(8))), 0x01));

                                 body.emit(assign(r06E9, lshift(r06E9, body.constant(int(8))), 0x01));


                              body.instructions = f06F1_parent_instructions;
                              body.emit(f06F1);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r06F5 = bit_and(r06E9, body.constant(4026531840u));
                              ir_expression *const r06F6 = equal(r06F5, body.constant(0u));
                              ir_if *f06F4 = new(mem_ctx) ir_if(operand(r06F6).val);
                              exec_list *const f06F4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06F4->then_instructions;

                                 body.emit(assign(r06EB, add(r06EB, body.constant(int(4))), 0x01));

                                 body.emit(assign(r06E9, lshift(r06E9, body.constant(int(4))), 0x01));


                              body.instructions = f06F4_parent_instructions;
                              body.emit(f06F4);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r06F8 = bit_and(r06E9, body.constant(3221225472u));
                              ir_expression *const r06F9 = equal(r06F8, body.constant(0u));
                              ir_if *f06F7 = new(mem_ctx) ir_if(operand(r06F9).val);
                              exec_list *const f06F7_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06F7->then_instructions;

                                 body.emit(assign(r06EB, add(r06EB, body.constant(int(2))), 0x01));

                                 body.emit(assign(r06E9, lshift(r06E9, body.constant(int(2))), 0x01));


                              body.instructions = f06F7_parent_instructions;
                              body.emit(f06F7);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r06FB = bit_and(r06E9, body.constant(2147483648u));
                              ir_expression *const r06FC = equal(r06FB, body.constant(0u));
                              ir_if *f06FA = new(mem_ctx) ir_if(operand(r06FC).val);
                              exec_list *const f06FA_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06FA->then_instructions;

                                 body.emit(assign(r06EB, add(r06EB, body.constant(int(1))), 0x01));


                              body.instructions = f06FA_parent_instructions;
                              body.emit(f06FA);

                              /* END IF */

                              body.emit(assign(r06EA, r06EB, 0x01));


                           body.instructions = f06EC_parent_instructions;
                           body.emit(f06EC);

                           /* END IF */

                           body.emit(assign(r06E6, add(r06EA, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06FE = gequal(r06E6, body.constant(int(0)));
                           ir_if *f06FD = new(mem_ctx) ir_if(operand(r06FE).val);
                           exec_list *const f06FD_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06FD->then_instructions;

                              body.emit(assign(r06E5, body.constant(0u), 0x01));

                              ir_variable *const r06FF = body.make_temp(glsl_type::uint_type, "z1Ptr");
                              body.emit(assign(r06FF, lshift(r06E4, r06E6), 0x01));

                              ir_variable *const r0700 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r0702 = equal(r06E6, body.constant(int(0)));
                              ir_if *f0701 = new(mem_ctx) ir_if(operand(r0702).val);
                              exec_list *const f0701_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0701->then_instructions;

                                 body.emit(assign(r0700, r06E3, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0701->else_instructions;

                                 ir_expression *const r0703 = lshift(r06E3, r06E6);
                                 ir_expression *const r0704 = neg(r06E6);
                                 ir_expression *const r0705 = bit_and(r0704, body.constant(int(31)));
                                 ir_expression *const r0706 = rshift(r06E4, r0705);
                                 body.emit(assign(r0700, bit_or(r0703, r0706), 0x01));


                              body.instructions = f0701_parent_instructions;
                              body.emit(f0701);

                              /* END IF */

                              body.emit(assign(r06E3, r0700, 0x01));

                              body.emit(assign(r06E4, r06FF, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06FD->else_instructions;

                              ir_variable *const r0707 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r0707, body.constant(0u), 0x01));

                              ir_variable *const r0708 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0708, neg(r06E6), 0x01));

                              ir_variable *const r0709 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0709);
                              ir_variable *const r070A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r070A);
                              ir_variable *const r070B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r070B);
                              ir_variable *const r070C = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r070D = neg(r0708);
                              body.emit(assign(r070C, bit_and(r070D, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r070F = equal(r0708, body.constant(int(0)));
                              ir_if *f070E = new(mem_ctx) ir_if(operand(r070F).val);
                              exec_list *const f070E_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f070E->then_instructions;

                                 body.emit(assign(r0709, r0707, 0x01));

                                 body.emit(assign(r070A, r06E4, 0x01));

                                 body.emit(assign(r070B, r06E3, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f070E->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0711 = less(r0708, body.constant(int(32)));
                                 ir_if *f0710 = new(mem_ctx) ir_if(operand(r0711).val);
                                 exec_list *const f0710_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0710->then_instructions;

                                    body.emit(assign(r0709, lshift(r06E4, r070C), 0x01));

                                    ir_expression *const r0712 = lshift(r06E3, r070C);
                                    ir_expression *const r0713 = rshift(r06E4, r0708);
                                    body.emit(assign(r070A, bit_or(r0712, r0713), 0x01));

                                    body.emit(assign(r070B, rshift(r06E3, r0708), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0710->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0715 = equal(r0708, body.constant(int(32)));
                                    ir_if *f0714 = new(mem_ctx) ir_if(operand(r0715).val);
                                    exec_list *const f0714_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0714->then_instructions;

                                       body.emit(assign(r0709, r06E4, 0x01));

                                       body.emit(assign(r070A, r06E3, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0714->else_instructions;

                                       body.emit(assign(r0707, bit_or(body.constant(0u), r06E4), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r0717 = less(r0708, body.constant(int(64)));
                                       ir_if *f0716 = new(mem_ctx) ir_if(operand(r0717).val);
                                       exec_list *const f0716_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0716->then_instructions;

                                          body.emit(assign(r0709, lshift(r06E3, r070C), 0x01));

                                          ir_expression *const r0718 = bit_and(r0708, body.constant(int(31)));
                                          body.emit(assign(r070A, rshift(r06E3, r0718), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0716->else_instructions;

                                          ir_variable *const r0719 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r071B = equal(r0708, body.constant(int(64)));
                                          ir_if *f071A = new(mem_ctx) ir_if(operand(r071B).val);
                                          exec_list *const f071A_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f071A->then_instructions;

                                             body.emit(assign(r0719, r06E3, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f071A->else_instructions;

                                             ir_expression *const r071C = nequal(r06E3, body.constant(0u));
                                             ir_expression *const r071D = expr(ir_unop_b2i, r071C);
                                             body.emit(assign(r0719, expr(ir_unop_i2u, r071D), 0x01));


                                          body.instructions = f071A_parent_instructions;
                                          body.emit(f071A);

                                          /* END IF */

                                          body.emit(assign(r0709, r0719, 0x01));

                                          body.emit(assign(r070A, body.constant(0u), 0x01));


                                       body.instructions = f0716_parent_instructions;
                                       body.emit(f0716);

                                       /* END IF */


                                    body.instructions = f0714_parent_instructions;
                                    body.emit(f0714);

                                    /* END IF */

                                    body.emit(assign(r070B, body.constant(0u), 0x01));


                                 body.instructions = f0710_parent_instructions;
                                 body.emit(f0710);

                                 /* END IF */

                                 ir_expression *const r071E = nequal(r0707, body.constant(0u));
                                 ir_expression *const r071F = expr(ir_unop_b2i, r071E);
                                 ir_expression *const r0720 = expr(ir_unop_i2u, r071F);
                                 body.emit(assign(r0709, bit_or(r0709, r0720), 0x01));


                              body.instructions = f070E_parent_instructions;
                              body.emit(f070E);

                              /* END IF */

                              body.emit(assign(r06E3, r070B, 0x01));

                              body.emit(assign(r06E4, r070A, 0x01));

                              body.emit(assign(r06E5, r0709, 0x01));


                           body.instructions = f06FD_parent_instructions;
                           body.emit(f06FD);

                           /* END IF */

                           body.emit(assign(r06E2, sub(r06E2, r06E6), 0x01));

                           ir_variable *const r0721 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r0721, r06E2, 0x01));

                           ir_variable *const r0722 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r0722, r06E3, 0x01));

                           ir_variable *const r0723 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r0723, r06E4, 0x01));

                           ir_variable *const r0724 = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r0724, r06E5, 0x01));

                           ir_variable *const r0725 = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r0725, body.constant(true), 0x01));

                           ir_variable *const r0726 = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r0727 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r0727);
                           ir_expression *const r0728 = expr(ir_unop_u2i, r06E5);
                           body.emit(assign(r0727, less(r0728, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r072A = gequal(r06E2, body.constant(int(2045)));
                           ir_if *f0729 = new(mem_ctx) ir_if(operand(r072A).val);
                           exec_list *const f0729_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0729->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r072C = less(body.constant(int(2045)), r06E2);
                              ir_expression *const r072D = equal(r06E2, body.constant(int(2045)));
                              ir_expression *const r072E = equal(body.constant(2097151u), r06E3);
                              ir_expression *const r072F = equal(body.constant(4294967295u), r06E4);
                              ir_expression *const r0730 = logic_and(r072E, r072F);
                              ir_expression *const r0731 = logic_and(r072D, r0730);
                              ir_expression *const r0732 = logic_and(r0731, r0727);
                              ir_expression *const r0733 = logic_or(r072C, r0732);
                              ir_if *f072B = new(mem_ctx) ir_if(operand(r0733).val);
                              exec_list *const f072B_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f072B->then_instructions;

                                 ir_variable *const r0734 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r0734);
                                 ir_expression *const r0735 = lshift(r01E3, body.constant(int(31)));
                                 body.emit(assign(r0734, add(r0735, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r0734, body.constant(0u), 0x01));

                                 body.emit(assign(r0726, r0734, 0x03));

                                 body.emit(assign(r0725, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f072B->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0737 = less(r06E2, body.constant(int(0)));
                                 ir_if *f0736 = new(mem_ctx) ir_if(operand(r0737).val);
                                 exec_list *const f0736_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0736->then_instructions;

                                    ir_variable *const r0738 = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r0738, r06E5, 0x01));

                                    ir_variable *const r0739 = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r0739, neg(r06E2), 0x01));

                                    ir_variable *const r073A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r073A);
                                    ir_variable *const r073B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r073B);
                                    ir_variable *const r073C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r073C);
                                    ir_variable *const r073D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r073E = neg(r0739);
                                    body.emit(assign(r073D, bit_and(r073E, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0740 = equal(r0739, body.constant(int(0)));
                                    ir_if *f073F = new(mem_ctx) ir_if(operand(r0740).val);
                                    exec_list *const f073F_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f073F->then_instructions;

                                       body.emit(assign(r073A, r06E5, 0x01));

                                       body.emit(assign(r073B, r06E4, 0x01));

                                       body.emit(assign(r073C, r06E3, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f073F->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r0742 = less(r0739, body.constant(int(32)));
                                       ir_if *f0741 = new(mem_ctx) ir_if(operand(r0742).val);
                                       exec_list *const f0741_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0741->then_instructions;

                                          body.emit(assign(r073A, lshift(r06E4, r073D), 0x01));

                                          ir_expression *const r0743 = lshift(r06E3, r073D);
                                          ir_expression *const r0744 = rshift(r06E4, r0739);
                                          body.emit(assign(r073B, bit_or(r0743, r0744), 0x01));

                                          body.emit(assign(r073C, rshift(r06E3, r0739), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0741->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r0746 = equal(r0739, body.constant(int(32)));
                                          ir_if *f0745 = new(mem_ctx) ir_if(operand(r0746).val);
                                          exec_list *const f0745_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0745->then_instructions;

                                             body.emit(assign(r073A, r06E4, 0x01));

                                             body.emit(assign(r073B, r06E3, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0745->else_instructions;

                                             body.emit(assign(r0738, bit_or(r06E5, r06E4), 0x01));

                                             /* IF CONDITION */
                                             ir_expression *const r0748 = less(r0739, body.constant(int(64)));
                                             ir_if *f0747 = new(mem_ctx) ir_if(operand(r0748).val);
                                             exec_list *const f0747_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f0747->then_instructions;

                                                body.emit(assign(r073A, lshift(r06E3, r073D), 0x01));

                                                ir_expression *const r0749 = bit_and(r0739, body.constant(int(31)));
                                                body.emit(assign(r073B, rshift(r06E3, r0749), 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f0747->else_instructions;

                                                ir_variable *const r074A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                                /* IF CONDITION */
                                                ir_expression *const r074C = equal(r0739, body.constant(int(64)));
                                                ir_if *f074B = new(mem_ctx) ir_if(operand(r074C).val);
                                                exec_list *const f074B_parent_instructions = body.instructions;

                                                   /* THEN INSTRUCTIONS */
                                                   body.instructions = &f074B->then_instructions;

                                                   body.emit(assign(r074A, r06E3, 0x01));


                                                   /* ELSE INSTRUCTIONS */
                                                   body.instructions = &f074B->else_instructions;

                                                   ir_expression *const r074D = nequal(r06E3, body.constant(0u));
                                                   ir_expression *const r074E = expr(ir_unop_b2i, r074D);
                                                   body.emit(assign(r074A, expr(ir_unop_i2u, r074E), 0x01));


                                                body.instructions = f074B_parent_instructions;
                                                body.emit(f074B);

                                                /* END IF */

                                                body.emit(assign(r073A, r074A, 0x01));

                                                body.emit(assign(r073B, body.constant(0u), 0x01));


                                             body.instructions = f0747_parent_instructions;
                                             body.emit(f0747);

                                             /* END IF */


                                          body.instructions = f0745_parent_instructions;
                                          body.emit(f0745);

                                          /* END IF */

                                          body.emit(assign(r073C, body.constant(0u), 0x01));


                                       body.instructions = f0741_parent_instructions;
                                       body.emit(f0741);

                                       /* END IF */

                                       ir_expression *const r074F = nequal(r0738, body.constant(0u));
                                       ir_expression *const r0750 = expr(ir_unop_b2i, r074F);
                                       ir_expression *const r0751 = expr(ir_unop_i2u, r0750);
                                       body.emit(assign(r073A, bit_or(r073A, r0751), 0x01));


                                    body.instructions = f073F_parent_instructions;
                                    body.emit(f073F);

                                    /* END IF */

                                    body.emit(assign(r0722, r073C, 0x01));

                                    body.emit(assign(r0723, r073B, 0x01));

                                    body.emit(assign(r0724, r073A, 0x01));

                                    body.emit(assign(r0721, body.constant(int(0)), 0x01));

                                    body.emit(assign(r0727, less(r073A, body.constant(0u)), 0x01));


                                 body.instructions = f0736_parent_instructions;
                                 body.emit(f0736);

                                 /* END IF */


                              body.instructions = f072B_parent_instructions;
                              body.emit(f072B);

                              /* END IF */


                           body.instructions = f0729_parent_instructions;
                           body.emit(f0729);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f0752 = new(mem_ctx) ir_if(operand(r0725).val);
                           exec_list *const f0752_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0752->then_instructions;

                              /* IF CONDITION */
                              ir_if *f0753 = new(mem_ctx) ir_if(operand(r0727).val);
                              exec_list *const f0753_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0753->then_instructions;

                                 ir_variable *const r0754 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r0754, add(r0723, body.constant(1u)), 0x01));

                                 ir_expression *const r0755 = less(r0754, r0723);
                                 ir_expression *const r0756 = expr(ir_unop_b2i, r0755);
                                 ir_expression *const r0757 = expr(ir_unop_i2u, r0756);
                                 body.emit(assign(r0722, add(r0722, r0757), 0x01));

                                 ir_expression *const r0758 = equal(r0724, body.constant(0u));
                                 ir_expression *const r0759 = expr(ir_unop_b2i, r0758);
                                 ir_expression *const r075A = expr(ir_unop_i2u, r0759);
                                 ir_expression *const r075B = add(r0724, r075A);
                                 ir_expression *const r075C = bit_and(r075B, body.constant(1u));
                                 ir_expression *const r075D = expr(ir_unop_bit_not, r075C);
                                 body.emit(assign(r0723, bit_and(r0754, r075D), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0753->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r075F = bit_or(r0722, r0723);
                                 ir_expression *const r0760 = equal(r075F, body.constant(0u));
                                 ir_if *f075E = new(mem_ctx) ir_if(operand(r0760).val);
                                 exec_list *const f075E_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f075E->then_instructions;

                                    body.emit(assign(r0721, body.constant(int(0)), 0x01));


                                 body.instructions = f075E_parent_instructions;
                                 body.emit(f075E);

                                 /* END IF */


                              body.instructions = f0753_parent_instructions;
                              body.emit(f0753);

                              /* END IF */

                              ir_variable *const r0761 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0761);
                              ir_expression *const r0762 = lshift(r01E3, body.constant(int(31)));
                              ir_expression *const r0763 = expr(ir_unop_i2u, r0721);
                              ir_expression *const r0764 = lshift(r0763, body.constant(int(20)));
                              ir_expression *const r0765 = add(r0762, r0764);
                              body.emit(assign(r0761, add(r0765, r0722), 0x02));

                              body.emit(assign(r0761, r0723, 0x01));

                              body.emit(assign(r0726, r0761, 0x03));

                              body.emit(assign(r0725, body.constant(false), 0x01));


                           body.instructions = f0752_parent_instructions;
                           body.emit(f0752);

                           /* END IF */

                           body.emit(assign(r01E2, r0726, 0x03));

                           body.emit(assign(r01E1, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06DA->else_instructions;

                           ir_variable *const r0766 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0766);
                           body.emit(assign(r0766, body.constant(0u), 0x02));

                           body.emit(assign(r0766, body.constant(0u), 0x01));

                           body.emit(assign(r01E2, r0766, 0x03));

                           body.emit(assign(r01E1, body.constant(false), 0x01));


                        body.instructions = f06DA_parent_instructions;
                        body.emit(f06DA);

                        /* END IF */


                     body.instructions = f064E_parent_instructions;
                     body.emit(f064E);

                     /* END IF */


                  body.instructions = f05C2_parent_instructions;
                  body.emit(f05C2);

                  /* END IF */


               body.instructions = f0536_parent_instructions;
               body.emit(f0536);

               /* END IF */


            body.instructions = f0519_parent_instructions;
            body.emit(f0519);

            /* END IF */


         body.instructions = f044F_parent_instructions;
         body.emit(f044F);

         /* END IF */


      body.instructions = f0389_parent_instructions;
      body.emit(f0389);

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

   ir_variable *const r0767 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0767);
   ir_variable *const r0768 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0768);
   ir_variable *const r0769 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0769);
   ir_variable *const r076A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r076A);
   ir_variable *const r076B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r076B);
   ir_variable *const r076C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r076C);
   ir_variable *const r076D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r076D);
   ir_variable *const r076E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076E, bit_and(r0767, body.constant(65535u)), 0x01));

   ir_variable *const r076F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r076F, rshift(r0767, body.constant(int(16))), 0x01));

   ir_variable *const r0770 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0770, bit_and(r0768, body.constant(65535u)), 0x01));

   ir_variable *const r0771 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0771, rshift(r0768, body.constant(int(16))), 0x01));

   ir_variable *const r0772 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0772, mul(r076F, r0770), 0x01));

   ir_expression *const r0773 = mul(r076E, r0771);
   body.emit(assign(r076C, add(r0773, r0772), 0x01));

   ir_expression *const r0774 = mul(r076F, r0771);
   ir_expression *const r0775 = less(r076C, r0772);
   ir_expression *const r0776 = expr(ir_unop_b2i, r0775);
   ir_expression *const r0777 = expr(ir_unop_i2u, r0776);
   ir_expression *const r0778 = lshift(r0777, body.constant(int(16)));
   ir_expression *const r0779 = rshift(r076C, body.constant(int(16)));
   ir_expression *const r077A = add(r0778, r0779);
   body.emit(assign(r076B, add(r0774, r077A), 0x01));

   body.emit(assign(r076C, lshift(r076C, body.constant(int(16))), 0x01));

   ir_expression *const r077B = mul(r076E, r0770);
   body.emit(assign(r076D, add(r077B, r076C), 0x01));

   ir_expression *const r077C = less(r076D, r076C);
   ir_expression *const r077D = expr(ir_unop_b2i, r077C);
   ir_expression *const r077E = expr(ir_unop_i2u, r077D);
   body.emit(assign(r076B, add(r076B, r077E), 0x01));

   body.emit(assign(r076A, r076D, 0x01));

   body.emit(assign(r0769, r076B, 0x01));

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

   ir_variable *const r077F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r077F);
   ir_variable *const r0780 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0780);
   ir_variable *const r0781 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0781);
   ir_variable *const r0782 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0782);
   ir_variable *const r0783 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0783);
   ir_variable *const r0784 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0784);
   ir_variable *const r0785 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0785);
   ir_variable *const r0786 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0786);
   ir_variable *const r0787 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0787);
   ir_variable *const r0788 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0788);
   ir_variable *const r0789 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0789);
   ir_variable *const r078A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078A, bit_and(r0780, body.constant(65535u)), 0x01));

   ir_variable *const r078B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078B, rshift(r0780, body.constant(int(16))), 0x01));

   ir_variable *const r078C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078C, bit_and(r0782, body.constant(65535u)), 0x01));

   ir_variable *const r078D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078D, rshift(r0782, body.constant(int(16))), 0x01));

   ir_variable *const r078E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r078E, mul(r078B, r078C), 0x01));

   ir_expression *const r078F = mul(r078A, r078D);
   body.emit(assign(r0788, add(r078F, r078E), 0x01));

   ir_expression *const r0790 = mul(r078B, r078D);
   ir_expression *const r0791 = less(r0788, r078E);
   ir_expression *const r0792 = expr(ir_unop_b2i, r0791);
   ir_expression *const r0793 = expr(ir_unop_i2u, r0792);
   ir_expression *const r0794 = lshift(r0793, body.constant(int(16)));
   ir_expression *const r0795 = rshift(r0788, body.constant(int(16)));
   ir_expression *const r0796 = add(r0794, r0795);
   body.emit(assign(r0787, add(r0790, r0796), 0x01));

   body.emit(assign(r0788, lshift(r0788, body.constant(int(16))), 0x01));

   ir_expression *const r0797 = mul(r078A, r078C);
   body.emit(assign(r0789, add(r0797, r0788), 0x01));

   ir_expression *const r0798 = less(r0789, r0788);
   ir_expression *const r0799 = expr(ir_unop_b2i, r0798);
   ir_expression *const r079A = expr(ir_unop_i2u, r0799);
   body.emit(assign(r0787, add(r0787, r079A), 0x01));

   ir_variable *const r079B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r079B);
   ir_variable *const r079C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r079C);
   ir_variable *const r079D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r079D);
   ir_variable *const r079E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r079E, bit_and(r0780, body.constant(65535u)), 0x01));

   ir_variable *const r079F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r079F, rshift(r0780, body.constant(int(16))), 0x01));

   ir_variable *const r07A0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A0, bit_and(r0781, body.constant(65535u)), 0x01));

   ir_variable *const r07A1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A1, rshift(r0781, body.constant(int(16))), 0x01));

   ir_variable *const r07A2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A2, mul(r079F, r07A0), 0x01));

   ir_expression *const r07A3 = mul(r079E, r07A1);
   body.emit(assign(r079C, add(r07A3, r07A2), 0x01));

   ir_expression *const r07A4 = mul(r079F, r07A1);
   ir_expression *const r07A5 = less(r079C, r07A2);
   ir_expression *const r07A6 = expr(ir_unop_b2i, r07A5);
   ir_expression *const r07A7 = expr(ir_unop_i2u, r07A6);
   ir_expression *const r07A8 = lshift(r07A7, body.constant(int(16)));
   ir_expression *const r07A9 = rshift(r079C, body.constant(int(16)));
   ir_expression *const r07AA = add(r07A8, r07A9);
   body.emit(assign(r079B, add(r07A4, r07AA), 0x01));

   body.emit(assign(r079C, lshift(r079C, body.constant(int(16))), 0x01));

   ir_expression *const r07AB = mul(r079E, r07A0);
   body.emit(assign(r079D, add(r07AB, r079C), 0x01));

   ir_expression *const r07AC = less(r079D, r079C);
   ir_expression *const r07AD = expr(ir_unop_b2i, r07AC);
   ir_expression *const r07AE = expr(ir_unop_i2u, r07AD);
   body.emit(assign(r079B, add(r079B, r07AE), 0x01));

   ir_variable *const r07AF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07AF, add(r079D, r0787), 0x01));

   ir_variable *const r07B0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07B0);
   ir_variable *const r07B1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07B1);
   ir_variable *const r07B2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07B2);
   ir_variable *const r07B3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B3, bit_and(r077F, body.constant(65535u)), 0x01));

   ir_variable *const r07B4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B4, rshift(r077F, body.constant(int(16))), 0x01));

   ir_variable *const r07B5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B5, bit_and(r0781, body.constant(65535u)), 0x01));

   ir_variable *const r07B6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B6, rshift(r0781, body.constant(int(16))), 0x01));

   ir_variable *const r07B7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B7, mul(r07B4, r07B5), 0x01));

   ir_expression *const r07B8 = mul(r07B3, r07B6);
   body.emit(assign(r07B1, add(r07B8, r07B7), 0x01));

   ir_expression *const r07B9 = mul(r07B4, r07B6);
   ir_expression *const r07BA = less(r07B1, r07B7);
   ir_expression *const r07BB = expr(ir_unop_b2i, r07BA);
   ir_expression *const r07BC = expr(ir_unop_i2u, r07BB);
   ir_expression *const r07BD = lshift(r07BC, body.constant(int(16)));
   ir_expression *const r07BE = rshift(r07B1, body.constant(int(16)));
   ir_expression *const r07BF = add(r07BD, r07BE);
   body.emit(assign(r07B0, add(r07B9, r07BF), 0x01));

   body.emit(assign(r07B1, lshift(r07B1, body.constant(int(16))), 0x01));

   ir_expression *const r07C0 = mul(r07B3, r07B5);
   body.emit(assign(r07B2, add(r07C0, r07B1), 0x01));

   ir_expression *const r07C1 = less(r07B2, r07B1);
   ir_expression *const r07C2 = expr(ir_unop_b2i, r07C1);
   ir_expression *const r07C3 = expr(ir_unop_i2u, r07C2);
   body.emit(assign(r07B0, add(r07B0, r07C3), 0x01));

   ir_variable *const r07C4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r07C5 = less(r07AF, r079D);
   ir_expression *const r07C6 = expr(ir_unop_b2i, r07C5);
   ir_expression *const r07C7 = expr(ir_unop_i2u, r07C6);
   ir_expression *const r07C8 = add(r079B, r07C7);
   body.emit(assign(r07C4, add(r07B2, r07C8), 0x01));

   ir_variable *const r07C9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07C9);
   ir_variable *const r07CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07CA);
   ir_variable *const r07CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07CB);
   ir_variable *const r07CC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07CC, bit_and(r077F, body.constant(65535u)), 0x01));

   ir_variable *const r07CD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07CD, rshift(r077F, body.constant(int(16))), 0x01));

   ir_variable *const r07CE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07CE, bit_and(r0782, body.constant(65535u)), 0x01));

   ir_variable *const r07CF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07CF, rshift(r0782, body.constant(int(16))), 0x01));

   ir_variable *const r07D0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D0, mul(r07CD, r07CE), 0x01));

   ir_expression *const r07D1 = mul(r07CC, r07CF);
   body.emit(assign(r07CA, add(r07D1, r07D0), 0x01));

   ir_expression *const r07D2 = mul(r07CD, r07CF);
   ir_expression *const r07D3 = less(r07CA, r07D0);
   ir_expression *const r07D4 = expr(ir_unop_b2i, r07D3);
   ir_expression *const r07D5 = expr(ir_unop_i2u, r07D4);
   ir_expression *const r07D6 = lshift(r07D5, body.constant(int(16)));
   ir_expression *const r07D7 = rshift(r07CA, body.constant(int(16)));
   ir_expression *const r07D8 = add(r07D6, r07D7);
   body.emit(assign(r07C9, add(r07D2, r07D8), 0x01));

   body.emit(assign(r07CA, lshift(r07CA, body.constant(int(16))), 0x01));

   ir_expression *const r07D9 = mul(r07CC, r07CE);
   body.emit(assign(r07CB, add(r07D9, r07CA), 0x01));

   ir_expression *const r07DA = less(r07CB, r07CA);
   ir_expression *const r07DB = expr(ir_unop_b2i, r07DA);
   ir_expression *const r07DC = expr(ir_unop_i2u, r07DB);
   body.emit(assign(r07C9, add(r07C9, r07DC), 0x01));

   ir_variable *const r07DD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DD, add(r07CB, r07AF), 0x01));

   ir_variable *const r07DE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r07DF = less(r07DD, r07CB);
   ir_expression *const r07E0 = expr(ir_unop_b2i, r07DF);
   ir_expression *const r07E1 = expr(ir_unop_i2u, r07E0);
   ir_expression *const r07E2 = add(r07C9, r07E1);
   body.emit(assign(r07DE, add(r07C4, r07E2), 0x01));

   body.emit(assign(r0786, r0789, 0x01));

   body.emit(assign(r0785, r07DD, 0x01));

   body.emit(assign(r0784, r07DE, 0x01));

   ir_expression *const r07E3 = less(r07C4, r07B2);
   ir_expression *const r07E4 = expr(ir_unop_b2i, r07E3);
   ir_expression *const r07E5 = expr(ir_unop_i2u, r07E4);
   ir_expression *const r07E6 = add(r07B0, r07E5);
   ir_expression *const r07E7 = less(r07DE, r07C4);
   ir_expression *const r07E8 = expr(ir_unop_b2i, r07E7);
   ir_expression *const r07E9 = expr(ir_unop_i2u, r07E8);
   body.emit(assign(r0783, add(r07E6, r07E9), 0x01));

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

   ir_variable *const r07EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r07EA);
   ir_variable *const r07EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r07EB);
   ir_variable *const r07EC = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r07EC);
   ir_variable *const r07ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07ED);
   ir_variable *const r07EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07EE);
   ir_variable *const r07EF = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r07EF);
   /* IF CONDITION */
   ir_expression *const r07F1 = equal(r07EA, body.constant(0u));
   ir_if *f07F0 = new(mem_ctx) ir_if(operand(r07F1).val);
   exec_list *const f07F0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07F0->then_instructions;

      ir_variable *const r07F2 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r07F2, r07EB, 0x01));

      ir_variable *const r07F3 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r07F4 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r07F4);
      /* IF CONDITION */
      ir_expression *const r07F6 = equal(r07EB, body.constant(0u));
      ir_if *f07F5 = new(mem_ctx) ir_if(operand(r07F6).val);
      exec_list *const f07F5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07F5->then_instructions;

         body.emit(assign(r07F3, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07F5->else_instructions;

         body.emit(assign(r07F4, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r07F8 = bit_and(r07EB, body.constant(4294901760u));
         ir_expression *const r07F9 = equal(r07F8, body.constant(0u));
         ir_if *f07F7 = new(mem_ctx) ir_if(operand(r07F9).val);
         exec_list *const f07F7_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07F7->then_instructions;

            body.emit(assign(r07F4, body.constant(int(16)), 0x01));

            body.emit(assign(r07F2, lshift(r07EB, body.constant(int(16))), 0x01));


         body.instructions = f07F7_parent_instructions;
         body.emit(f07F7);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r07FB = bit_and(r07F2, body.constant(4278190080u));
         ir_expression *const r07FC = equal(r07FB, body.constant(0u));
         ir_if *f07FA = new(mem_ctx) ir_if(operand(r07FC).val);
         exec_list *const f07FA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07FA->then_instructions;

            body.emit(assign(r07F4, add(r07F4, body.constant(int(8))), 0x01));

            body.emit(assign(r07F2, lshift(r07F2, body.constant(int(8))), 0x01));


         body.instructions = f07FA_parent_instructions;
         body.emit(f07FA);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r07FE = bit_and(r07F2, body.constant(4026531840u));
         ir_expression *const r07FF = equal(r07FE, body.constant(0u));
         ir_if *f07FD = new(mem_ctx) ir_if(operand(r07FF).val);
         exec_list *const f07FD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07FD->then_instructions;

            body.emit(assign(r07F4, add(r07F4, body.constant(int(4))), 0x01));

            body.emit(assign(r07F2, lshift(r07F2, body.constant(int(4))), 0x01));


         body.instructions = f07FD_parent_instructions;
         body.emit(f07FD);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0801 = bit_and(r07F2, body.constant(3221225472u));
         ir_expression *const r0802 = equal(r0801, body.constant(0u));
         ir_if *f0800 = new(mem_ctx) ir_if(operand(r0802).val);
         exec_list *const f0800_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0800->then_instructions;

            body.emit(assign(r07F4, add(r07F4, body.constant(int(2))), 0x01));

            body.emit(assign(r07F2, lshift(r07F2, body.constant(int(2))), 0x01));


         body.instructions = f0800_parent_instructions;
         body.emit(f0800);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0804 = bit_and(r07F2, body.constant(2147483648u));
         ir_expression *const r0805 = equal(r0804, body.constant(0u));
         ir_if *f0803 = new(mem_ctx) ir_if(operand(r0805).val);
         exec_list *const f0803_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0803->then_instructions;

            body.emit(assign(r07F4, add(r07F4, body.constant(int(1))), 0x01));


         body.instructions = f0803_parent_instructions;
         body.emit(f0803);

         /* END IF */

         body.emit(assign(r07F3, r07F4, 0x01));


      body.instructions = f07F5_parent_instructions;
      body.emit(f07F5);

      /* END IF */

      body.emit(assign(r07EF, add(r07F3, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0807 = less(r07EF, body.constant(int(0)));
      ir_if *f0806 = new(mem_ctx) ir_if(operand(r0807).val);
      exec_list *const f0806_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0806->then_instructions;

         ir_expression *const r0808 = neg(r07EF);
         body.emit(assign(r07ED, rshift(r07EB, r0808), 0x01));

         ir_expression *const r0809 = bit_and(r07EF, body.constant(int(31)));
         body.emit(assign(r07EE, lshift(r07EB, r0809), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0806->else_instructions;

         body.emit(assign(r07ED, lshift(r07EB, r07EF), 0x01));

         body.emit(assign(r07EE, body.constant(0u), 0x01));


      body.instructions = f0806_parent_instructions;
      body.emit(f0806);

      /* END IF */

      body.emit(assign(r07EC, sub(body.constant(int(-31)), r07EF), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07F0->else_instructions;

      ir_variable *const r080A = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r080A, r07EA, 0x01));

      ir_variable *const r080B = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r080C = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r080C);
      /* IF CONDITION */
      ir_expression *const r080E = equal(r07EA, body.constant(0u));
      ir_if *f080D = new(mem_ctx) ir_if(operand(r080E).val);
      exec_list *const f080D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f080D->then_instructions;

         body.emit(assign(r080B, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f080D->else_instructions;

         body.emit(assign(r080C, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0810 = bit_and(r07EA, body.constant(4294901760u));
         ir_expression *const r0811 = equal(r0810, body.constant(0u));
         ir_if *f080F = new(mem_ctx) ir_if(operand(r0811).val);
         exec_list *const f080F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f080F->then_instructions;

            body.emit(assign(r080C, body.constant(int(16)), 0x01));

            body.emit(assign(r080A, lshift(r07EA, body.constant(int(16))), 0x01));


         body.instructions = f080F_parent_instructions;
         body.emit(f080F);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0813 = bit_and(r080A, body.constant(4278190080u));
         ir_expression *const r0814 = equal(r0813, body.constant(0u));
         ir_if *f0812 = new(mem_ctx) ir_if(operand(r0814).val);
         exec_list *const f0812_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0812->then_instructions;

            body.emit(assign(r080C, add(r080C, body.constant(int(8))), 0x01));

            body.emit(assign(r080A, lshift(r080A, body.constant(int(8))), 0x01));


         body.instructions = f0812_parent_instructions;
         body.emit(f0812);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0816 = bit_and(r080A, body.constant(4026531840u));
         ir_expression *const r0817 = equal(r0816, body.constant(0u));
         ir_if *f0815 = new(mem_ctx) ir_if(operand(r0817).val);
         exec_list *const f0815_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0815->then_instructions;

            body.emit(assign(r080C, add(r080C, body.constant(int(4))), 0x01));

            body.emit(assign(r080A, lshift(r080A, body.constant(int(4))), 0x01));


         body.instructions = f0815_parent_instructions;
         body.emit(f0815);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0819 = bit_and(r080A, body.constant(3221225472u));
         ir_expression *const r081A = equal(r0819, body.constant(0u));
         ir_if *f0818 = new(mem_ctx) ir_if(operand(r081A).val);
         exec_list *const f0818_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0818->then_instructions;

            body.emit(assign(r080C, add(r080C, body.constant(int(2))), 0x01));

            body.emit(assign(r080A, lshift(r080A, body.constant(int(2))), 0x01));


         body.instructions = f0818_parent_instructions;
         body.emit(f0818);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r081C = bit_and(r080A, body.constant(2147483648u));
         ir_expression *const r081D = equal(r081C, body.constant(0u));
         ir_if *f081B = new(mem_ctx) ir_if(operand(r081D).val);
         exec_list *const f081B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f081B->then_instructions;

            body.emit(assign(r080C, add(r080C, body.constant(int(1))), 0x01));


         body.instructions = f081B_parent_instructions;
         body.emit(f081B);

         /* END IF */

         body.emit(assign(r080B, r080C, 0x01));


      body.instructions = f080D_parent_instructions;
      body.emit(f080D);

      /* END IF */

      body.emit(assign(r07EF, add(r080B, body.constant(int(-11))), 0x01));

      ir_variable *const r081E = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r081E, lshift(r07EB, r07EF), 0x01));

      ir_variable *const r081F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0821 = equal(r07EF, body.constant(int(0)));
      ir_if *f0820 = new(mem_ctx) ir_if(operand(r0821).val);
      exec_list *const f0820_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0820->then_instructions;

         body.emit(assign(r081F, r07EA, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0820->else_instructions;

         ir_expression *const r0822 = lshift(r07EA, r07EF);
         ir_expression *const r0823 = neg(r07EF);
         ir_expression *const r0824 = bit_and(r0823, body.constant(int(31)));
         ir_expression *const r0825 = rshift(r07EB, r0824);
         body.emit(assign(r081F, bit_or(r0822, r0825), 0x01));


      body.instructions = f0820_parent_instructions;
      body.emit(f0820);

      /* END IF */

      body.emit(assign(r07ED, r081F, 0x01));

      body.emit(assign(r07EE, r081E, 0x01));

      body.emit(assign(r07EC, sub(body.constant(int(1)), r07EF), 0x01));


   body.instructions = f07F0_parent_instructions;
   body.emit(f07F0);

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

   ir_variable *const r0826 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0826);
   ir_variable *const r0827 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0827);
   ir_variable *const r0828 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0828, body.constant(true), 0x01));

   ir_variable *const r0829 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r082A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r082A);
   ir_variable *const r082B = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r082B);
   ir_variable *const r082C = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r082C);
   ir_variable *const r082D = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r082D);
   ir_variable *const r082E = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r082E);
   ir_variable *const r082F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r082F);
   ir_variable *const r0830 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0830);
   ir_variable *const r0831 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r0831);
   ir_variable *const r0832 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0832);
   ir_variable *const r0833 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0833);
   ir_variable *const r0834 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0834);
   body.emit(assign(r0834, body.constant(0u), 0x01));

   body.emit(assign(r0833, body.constant(0u), 0x01));

   body.emit(assign(r0832, body.constant(0u), 0x01));

   ir_variable *const r0835 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0835, swizzle_x(r0826), 0x01));

   body.emit(assign(r0830, r0835, 0x01));

   ir_variable *const r0836 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0836, bit_and(swizzle_y(r0826), body.constant(1048575u)), 0x01));

   body.emit(assign(r082F, r0836, 0x01));

   ir_variable *const r0837 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0837, swizzle_x(r0827), 0x01));

   body.emit(assign(r082E, r0837, 0x01));

   ir_variable *const r0838 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0838, bit_and(swizzle_y(r0827), body.constant(1048575u)), 0x01));

   body.emit(assign(r082D, r0838, 0x01));

   ir_variable *const r0839 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r083A = rshift(swizzle_y(r0826), body.constant(int(20)));
   ir_expression *const r083B = bit_and(r083A, body.constant(2047u));
   body.emit(assign(r0839, expr(ir_unop_u2i, r083B), 0x01));

   body.emit(assign(r082C, r0839, 0x01));

   ir_variable *const r083C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r083D = rshift(swizzle_y(r0827), body.constant(int(20)));
   ir_expression *const r083E = bit_and(r083D, body.constant(2047u));
   body.emit(assign(r083C, expr(ir_unop_u2i, r083E), 0x01));

   body.emit(assign(r082B, r083C, 0x01));

   ir_expression *const r083F = rshift(swizzle_y(r0826), body.constant(int(31)));
   ir_expression *const r0840 = rshift(swizzle_y(r0827), body.constant(int(31)));
   body.emit(assign(r082A, bit_xor(r083F, r0840), 0x01));

   /* IF CONDITION */
   ir_expression *const r0842 = equal(r0839, body.constant(int(2047)));
   ir_if *f0841 = new(mem_ctx) ir_if(operand(r0842).val);
   exec_list *const f0841_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0841->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0844 = bit_or(r0836, swizzle_x(r0826));
      ir_expression *const r0845 = nequal(r0844, body.constant(0u));
      ir_expression *const r0846 = equal(r083C, body.constant(int(2047)));
      ir_expression *const r0847 = bit_or(r0838, swizzle_x(r0827));
      ir_expression *const r0848 = nequal(r0847, body.constant(0u));
      ir_expression *const r0849 = logic_and(r0846, r0848);
      ir_expression *const r084A = logic_or(r0845, r0849);
      ir_if *f0843 = new(mem_ctx) ir_if(operand(r084A).val);
      exec_list *const f0843_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0843->then_instructions;

         ir_variable *const r084B = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r084B, swizzle_x(r0826), 0x01));

         ir_variable *const r084C = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r084C, swizzle_x(r0827), 0x01));

         body.emit(assign(r084B, bit_or(swizzle_y(r0826), body.constant(524288u)), 0x02));

         body.emit(assign(r084C, bit_or(swizzle_y(r0827), body.constant(524288u)), 0x02));

         ir_expression *const r084D = lshift(swizzle_y(r0826), body.constant(int(1)));
         ir_expression *const r084E = gequal(r084D, body.constant(4292870144u));
         ir_expression *const r084F = nequal(swizzle_x(r0826), body.constant(0u));
         ir_expression *const r0850 = bit_and(swizzle_y(r0826), body.constant(1048575u));
         ir_expression *const r0851 = nequal(r0850, body.constant(0u));
         ir_expression *const r0852 = logic_or(r084F, r0851);
         ir_expression *const r0853 = logic_and(r084E, r0852);
         ir_swizzle *const r0854 = swizzle(r0853, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r0855 = lshift(swizzle_y(r0827), body.constant(int(1)));
         ir_expression *const r0856 = gequal(r0855, body.constant(4292870144u));
         ir_expression *const r0857 = nequal(swizzle_x(r0827), body.constant(0u));
         ir_expression *const r0858 = bit_and(swizzle_y(r0827), body.constant(1048575u));
         ir_expression *const r0859 = nequal(r0858, body.constant(0u));
         ir_expression *const r085A = logic_or(r0857, r0859);
         ir_expression *const r085B = logic_and(r0856, r085A);
         ir_swizzle *const r085C = swizzle(r085B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
         ir_expression *const r085D = expr(ir_triop_csel, r085C, r084C, r084B);
         body.emit(assign(r0829, expr(ir_triop_csel, r0854, r085D, r084C), 0x03));

         body.emit(assign(r0828, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0843->else_instructions;

         /* IF CONDITION */
         ir_expression *const r085F = expr(ir_unop_i2u, r083C);
         ir_expression *const r0860 = bit_or(r085F, r0838);
         ir_expression *const r0861 = bit_or(r0860, swizzle_x(r0827));
         ir_expression *const r0862 = equal(r0861, body.constant(0u));
         ir_if *f085E = new(mem_ctx) ir_if(operand(r0862).val);
         exec_list *const f085E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f085E->then_instructions;

            ir_constant_data r0863_data;
            memset(&r0863_data, 0, sizeof(ir_constant_data));
            r0863_data.u[0] = 4294967295;
            r0863_data.u[1] = 4294967295;
            ir_constant *const r0863 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0863_data);
            body.emit(assign(r0829, r0863, 0x03));

            body.emit(assign(r0828, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f085E->else_instructions;

            ir_variable *const r0864 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0864);
            ir_expression *const r0865 = lshift(r082A, body.constant(int(31)));
            body.emit(assign(r0864, add(r0865, body.constant(2146435072u)), 0x02));

            body.emit(assign(r0864, body.constant(0u), 0x01));

            body.emit(assign(r0829, r0864, 0x03));

            body.emit(assign(r0828, body.constant(false), 0x01));


         body.instructions = f085E_parent_instructions;
         body.emit(f085E);

         /* END IF */


      body.instructions = f0843_parent_instructions;
      body.emit(f0843);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0841->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0867 = equal(r083C, body.constant(int(2047)));
      ir_if *f0866 = new(mem_ctx) ir_if(operand(r0867).val);
      exec_list *const f0866_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0866->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0869 = bit_or(r0838, swizzle_x(r0827));
         ir_expression *const r086A = nequal(r0869, body.constant(0u));
         ir_if *f0868 = new(mem_ctx) ir_if(operand(r086A).val);
         exec_list *const f0868_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0868->then_instructions;

            ir_variable *const r086B = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r086B, swizzle_x(r0826), 0x01));

            ir_variable *const r086C = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r086C, swizzle_x(r0827), 0x01));

            body.emit(assign(r086B, bit_or(swizzle_y(r0826), body.constant(524288u)), 0x02));

            body.emit(assign(r086C, bit_or(swizzle_y(r0827), body.constant(524288u)), 0x02));

            ir_expression *const r086D = lshift(swizzle_y(r0826), body.constant(int(1)));
            ir_expression *const r086E = gequal(r086D, body.constant(4292870144u));
            ir_expression *const r086F = nequal(swizzle_x(r0826), body.constant(0u));
            ir_expression *const r0870 = bit_and(swizzle_y(r0826), body.constant(1048575u));
            ir_expression *const r0871 = nequal(r0870, body.constant(0u));
            ir_expression *const r0872 = logic_or(r086F, r0871);
            ir_expression *const r0873 = logic_and(r086E, r0872);
            ir_swizzle *const r0874 = swizzle(r0873, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r0875 = lshift(swizzle_y(r0827), body.constant(int(1)));
            ir_expression *const r0876 = gequal(r0875, body.constant(4292870144u));
            ir_expression *const r0877 = nequal(swizzle_x(r0827), body.constant(0u));
            ir_expression *const r0878 = bit_and(swizzle_y(r0827), body.constant(1048575u));
            ir_expression *const r0879 = nequal(r0878, body.constant(0u));
            ir_expression *const r087A = logic_or(r0877, r0879);
            ir_expression *const r087B = logic_and(r0876, r087A);
            ir_swizzle *const r087C = swizzle(r087B, MAKE_SWIZZLE4(SWIZZLE_X, SWIZZLE_X, SWIZZLE_X, SWIZZLE_X), 2);
            ir_expression *const r087D = expr(ir_triop_csel, r087C, r086C, r086B);
            body.emit(assign(r0829, expr(ir_triop_csel, r0874, r087D, r086C), 0x03));

            body.emit(assign(r0828, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0868->else_instructions;

            /* IF CONDITION */
            ir_expression *const r087F = expr(ir_unop_i2u, r0839);
            ir_expression *const r0880 = bit_or(r087F, r0836);
            ir_expression *const r0881 = bit_or(r0880, swizzle_x(r0826));
            ir_expression *const r0882 = equal(r0881, body.constant(0u));
            ir_if *f087E = new(mem_ctx) ir_if(operand(r0882).val);
            exec_list *const f087E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f087E->then_instructions;

               ir_constant_data r0883_data;
               memset(&r0883_data, 0, sizeof(ir_constant_data));
               r0883_data.u[0] = 4294967295;
               r0883_data.u[1] = 4294967295;
               ir_constant *const r0883 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0883_data);
               body.emit(assign(r0829, r0883, 0x03));

               body.emit(assign(r0828, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f087E->else_instructions;

               ir_variable *const r0884 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0884);
               ir_expression *const r0885 = lshift(r082A, body.constant(int(31)));
               body.emit(assign(r0884, add(r0885, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0884, body.constant(0u), 0x01));

               body.emit(assign(r0829, r0884, 0x03));

               body.emit(assign(r0828, body.constant(false), 0x01));


            body.instructions = f087E_parent_instructions;
            body.emit(f087E);

            /* END IF */


         body.instructions = f0868_parent_instructions;
         body.emit(f0868);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0866->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0887 = equal(r0839, body.constant(int(0)));
         ir_if *f0886 = new(mem_ctx) ir_if(operand(r0887).val);
         exec_list *const f0886_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0886->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0889 = bit_or(r0836, swizzle_x(r0826));
            ir_expression *const r088A = equal(r0889, body.constant(0u));
            ir_if *f0888 = new(mem_ctx) ir_if(operand(r088A).val);
            exec_list *const f0888_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0888->then_instructions;

               ir_variable *const r088B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r088B);
               body.emit(assign(r088B, lshift(r082A, body.constant(int(31))), 0x02));

               body.emit(assign(r088B, body.constant(0u), 0x01));

               body.emit(assign(r0829, r088B, 0x03));

               body.emit(assign(r0828, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0888->else_instructions;

               ir_variable *const r088C = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r088C, r0839, 0x01));

               ir_variable *const r088D = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r088D, r0836, 0x01));

               ir_variable *const r088E = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r088E, r0835, 0x01));

               ir_variable *const r088F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r088F);
               /* IF CONDITION */
               ir_expression *const r0891 = equal(r0836, body.constant(0u));
               ir_if *f0890 = new(mem_ctx) ir_if(operand(r0891).val);
               exec_list *const f0890_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0890->then_instructions;

                  ir_variable *const r0892 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r0892, r0835, 0x01));

                  ir_variable *const r0893 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r0894 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0894);
                  /* IF CONDITION */
                  ir_expression *const r0896 = equal(swizzle_x(r0826), body.constant(0u));
                  ir_if *f0895 = new(mem_ctx) ir_if(operand(r0896).val);
                  exec_list *const f0895_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0895->then_instructions;

                     body.emit(assign(r0893, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0895->else_instructions;

                     body.emit(assign(r0894, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0898 = bit_and(swizzle_x(r0826), body.constant(4294901760u));
                     ir_expression *const r0899 = equal(r0898, body.constant(0u));
                     ir_if *f0897 = new(mem_ctx) ir_if(operand(r0899).val);
                     exec_list *const f0897_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0897->then_instructions;

                        body.emit(assign(r0894, body.constant(int(16)), 0x01));

                        body.emit(assign(r0892, lshift(swizzle_x(r0826), body.constant(int(16))), 0x01));


                     body.instructions = f0897_parent_instructions;
                     body.emit(f0897);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r089B = bit_and(r0892, body.constant(4278190080u));
                     ir_expression *const r089C = equal(r089B, body.constant(0u));
                     ir_if *f089A = new(mem_ctx) ir_if(operand(r089C).val);
                     exec_list *const f089A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f089A->then_instructions;

                        body.emit(assign(r0894, add(r0894, body.constant(int(8))), 0x01));

                        body.emit(assign(r0892, lshift(r0892, body.constant(int(8))), 0x01));


                     body.instructions = f089A_parent_instructions;
                     body.emit(f089A);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r089E = bit_and(r0892, body.constant(4026531840u));
                     ir_expression *const r089F = equal(r089E, body.constant(0u));
                     ir_if *f089D = new(mem_ctx) ir_if(operand(r089F).val);
                     exec_list *const f089D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f089D->then_instructions;

                        body.emit(assign(r0894, add(r0894, body.constant(int(4))), 0x01));

                        body.emit(assign(r0892, lshift(r0892, body.constant(int(4))), 0x01));


                     body.instructions = f089D_parent_instructions;
                     body.emit(f089D);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08A1 = bit_and(r0892, body.constant(3221225472u));
                     ir_expression *const r08A2 = equal(r08A1, body.constant(0u));
                     ir_if *f08A0 = new(mem_ctx) ir_if(operand(r08A2).val);
                     exec_list *const f08A0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08A0->then_instructions;

                        body.emit(assign(r0894, add(r0894, body.constant(int(2))), 0x01));

                        body.emit(assign(r0892, lshift(r0892, body.constant(int(2))), 0x01));


                     body.instructions = f08A0_parent_instructions;
                     body.emit(f08A0);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08A4 = bit_and(r0892, body.constant(2147483648u));
                     ir_expression *const r08A5 = equal(r08A4, body.constant(0u));
                     ir_if *f08A3 = new(mem_ctx) ir_if(operand(r08A5).val);
                     exec_list *const f08A3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08A3->then_instructions;

                        body.emit(assign(r0894, add(r0894, body.constant(int(1))), 0x01));


                     body.instructions = f08A3_parent_instructions;
                     body.emit(f08A3);

                     /* END IF */

                     body.emit(assign(r0893, r0894, 0x01));


                  body.instructions = f0895_parent_instructions;
                  body.emit(f0895);

                  /* END IF */

                  body.emit(assign(r088F, add(r0893, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r08A7 = less(r088F, body.constant(int(0)));
                  ir_if *f08A6 = new(mem_ctx) ir_if(operand(r08A7).val);
                  exec_list *const f08A6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08A6->then_instructions;

                     ir_expression *const r08A8 = neg(r088F);
                     body.emit(assign(r088D, rshift(swizzle_x(r0826), r08A8), 0x01));

                     ir_expression *const r08A9 = bit_and(r088F, body.constant(int(31)));
                     body.emit(assign(r088E, lshift(swizzle_x(r0826), r08A9), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08A6->else_instructions;

                     body.emit(assign(r088D, lshift(swizzle_x(r0826), r088F), 0x01));

                     body.emit(assign(r088E, body.constant(0u), 0x01));


                  body.instructions = f08A6_parent_instructions;
                  body.emit(f08A6);

                  /* END IF */

                  body.emit(assign(r088C, sub(body.constant(int(-31)), r088F), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0890->else_instructions;

                  ir_variable *const r08AA = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r08AA, r0836, 0x01));

                  ir_variable *const r08AB = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r08AC = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08AC);
                  /* IF CONDITION */
                  ir_expression *const r08AE = equal(r0836, body.constant(0u));
                  ir_if *f08AD = new(mem_ctx) ir_if(operand(r08AE).val);
                  exec_list *const f08AD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08AD->then_instructions;

                     body.emit(assign(r08AB, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08AD->else_instructions;

                     body.emit(assign(r08AC, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08B0 = bit_and(r0836, body.constant(4294901760u));
                     ir_expression *const r08B1 = equal(r08B0, body.constant(0u));
                     ir_if *f08AF = new(mem_ctx) ir_if(operand(r08B1).val);
                     exec_list *const f08AF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08AF->then_instructions;

                        body.emit(assign(r08AC, body.constant(int(16)), 0x01));

                        body.emit(assign(r08AA, lshift(r0836, body.constant(int(16))), 0x01));


                     body.instructions = f08AF_parent_instructions;
                     body.emit(f08AF);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08B3 = bit_and(r08AA, body.constant(4278190080u));
                     ir_expression *const r08B4 = equal(r08B3, body.constant(0u));
                     ir_if *f08B2 = new(mem_ctx) ir_if(operand(r08B4).val);
                     exec_list *const f08B2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08B2->then_instructions;

                        body.emit(assign(r08AC, add(r08AC, body.constant(int(8))), 0x01));

                        body.emit(assign(r08AA, lshift(r08AA, body.constant(int(8))), 0x01));


                     body.instructions = f08B2_parent_instructions;
                     body.emit(f08B2);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08B6 = bit_and(r08AA, body.constant(4026531840u));
                     ir_expression *const r08B7 = equal(r08B6, body.constant(0u));
                     ir_if *f08B5 = new(mem_ctx) ir_if(operand(r08B7).val);
                     exec_list *const f08B5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08B5->then_instructions;

                        body.emit(assign(r08AC, add(r08AC, body.constant(int(4))), 0x01));

                        body.emit(assign(r08AA, lshift(r08AA, body.constant(int(4))), 0x01));


                     body.instructions = f08B5_parent_instructions;
                     body.emit(f08B5);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08B9 = bit_and(r08AA, body.constant(3221225472u));
                     ir_expression *const r08BA = equal(r08B9, body.constant(0u));
                     ir_if *f08B8 = new(mem_ctx) ir_if(operand(r08BA).val);
                     exec_list *const f08B8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08B8->then_instructions;

                        body.emit(assign(r08AC, add(r08AC, body.constant(int(2))), 0x01));

                        body.emit(assign(r08AA, lshift(r08AA, body.constant(int(2))), 0x01));


                     body.instructions = f08B8_parent_instructions;
                     body.emit(f08B8);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08BC = bit_and(r08AA, body.constant(2147483648u));
                     ir_expression *const r08BD = equal(r08BC, body.constant(0u));
                     ir_if *f08BB = new(mem_ctx) ir_if(operand(r08BD).val);
                     exec_list *const f08BB_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08BB->then_instructions;

                        body.emit(assign(r08AC, add(r08AC, body.constant(int(1))), 0x01));


                     body.instructions = f08BB_parent_instructions;
                     body.emit(f08BB);

                     /* END IF */

                     body.emit(assign(r08AB, r08AC, 0x01));


                  body.instructions = f08AD_parent_instructions;
                  body.emit(f08AD);

                  /* END IF */

                  body.emit(assign(r088F, add(r08AB, body.constant(int(-11))), 0x01));

                  ir_variable *const r08BE = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r08BE, lshift(swizzle_x(r0826), r088F), 0x01));

                  ir_variable *const r08BF = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r08C1 = equal(r088F, body.constant(int(0)));
                  ir_if *f08C0 = new(mem_ctx) ir_if(operand(r08C1).val);
                  exec_list *const f08C0_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08C0->then_instructions;

                     body.emit(assign(r08BF, r0836, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08C0->else_instructions;

                     ir_expression *const r08C2 = lshift(r0836, r088F);
                     ir_expression *const r08C3 = neg(r088F);
                     ir_expression *const r08C4 = bit_and(r08C3, body.constant(int(31)));
                     ir_expression *const r08C5 = rshift(swizzle_x(r0826), r08C4);
                     body.emit(assign(r08BF, bit_or(r08C2, r08C5), 0x01));


                  body.instructions = f08C0_parent_instructions;
                  body.emit(f08C0);

                  /* END IF */

                  body.emit(assign(r088D, r08BF, 0x01));

                  body.emit(assign(r088E, r08BE, 0x01));

                  body.emit(assign(r088C, sub(body.constant(int(1)), r088F), 0x01));


               body.instructions = f0890_parent_instructions;
               body.emit(f0890);

               /* END IF */

               body.emit(assign(r082C, r088C, 0x01));

               body.emit(assign(r082F, r088D, 0x01));

               body.emit(assign(r0830, r088E, 0x01));


            body.instructions = f0888_parent_instructions;
            body.emit(f0888);

            /* END IF */


         body.instructions = f0886_parent_instructions;
         body.emit(f0886);

         /* END IF */

         /* IF CONDITION */
         ir_if *f08C6 = new(mem_ctx) ir_if(operand(r0828).val);
         exec_list *const f08C6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08C6->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08C8 = equal(r083C, body.constant(int(0)));
            ir_if *f08C7 = new(mem_ctx) ir_if(operand(r08C8).val);
            exec_list *const f08C7_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08C7->then_instructions;

               /* IF CONDITION */
               ir_expression *const r08CA = bit_or(r0838, swizzle_x(r0827));
               ir_expression *const r08CB = equal(r08CA, body.constant(0u));
               ir_if *f08C9 = new(mem_ctx) ir_if(operand(r08CB).val);
               exec_list *const f08C9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08C9->then_instructions;

                  ir_variable *const r08CC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r08CC);
                  body.emit(assign(r08CC, lshift(r082A, body.constant(int(31))), 0x02));

                  body.emit(assign(r08CC, body.constant(0u), 0x01));

                  body.emit(assign(r0829, r08CC, 0x03));

                  body.emit(assign(r0828, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08C9->else_instructions;

                  ir_variable *const r08CD = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r08CD, r083C, 0x01));

                  ir_variable *const r08CE = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r08CE, r0838, 0x01));

                  ir_variable *const r08CF = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r08CF, r0837, 0x01));

                  ir_variable *const r08D0 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08D0);
                  /* IF CONDITION */
                  ir_expression *const r08D2 = equal(r0838, body.constant(0u));
                  ir_if *f08D1 = new(mem_ctx) ir_if(operand(r08D2).val);
                  exec_list *const f08D1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08D1->then_instructions;

                     ir_variable *const r08D3 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r08D3, r0837, 0x01));

                     ir_variable *const r08D4 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r08D5 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r08D5);
                     /* IF CONDITION */
                     ir_expression *const r08D7 = equal(swizzle_x(r0827), body.constant(0u));
                     ir_if *f08D6 = new(mem_ctx) ir_if(operand(r08D7).val);
                     exec_list *const f08D6_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08D6->then_instructions;

                        body.emit(assign(r08D4, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08D6->else_instructions;

                        body.emit(assign(r08D5, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08D9 = bit_and(swizzle_x(r0827), body.constant(4294901760u));
                        ir_expression *const r08DA = equal(r08D9, body.constant(0u));
                        ir_if *f08D8 = new(mem_ctx) ir_if(operand(r08DA).val);
                        exec_list *const f08D8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08D8->then_instructions;

                           body.emit(assign(r08D5, body.constant(int(16)), 0x01));

                           body.emit(assign(r08D3, lshift(swizzle_x(r0827), body.constant(int(16))), 0x01));


                        body.instructions = f08D8_parent_instructions;
                        body.emit(f08D8);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08DC = bit_and(r08D3, body.constant(4278190080u));
                        ir_expression *const r08DD = equal(r08DC, body.constant(0u));
                        ir_if *f08DB = new(mem_ctx) ir_if(operand(r08DD).val);
                        exec_list *const f08DB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08DB->then_instructions;

                           body.emit(assign(r08D5, add(r08D5, body.constant(int(8))), 0x01));

                           body.emit(assign(r08D3, lshift(r08D3, body.constant(int(8))), 0x01));


                        body.instructions = f08DB_parent_instructions;
                        body.emit(f08DB);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08DF = bit_and(r08D3, body.constant(4026531840u));
                        ir_expression *const r08E0 = equal(r08DF, body.constant(0u));
                        ir_if *f08DE = new(mem_ctx) ir_if(operand(r08E0).val);
                        exec_list *const f08DE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08DE->then_instructions;

                           body.emit(assign(r08D5, add(r08D5, body.constant(int(4))), 0x01));

                           body.emit(assign(r08D3, lshift(r08D3, body.constant(int(4))), 0x01));


                        body.instructions = f08DE_parent_instructions;
                        body.emit(f08DE);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08E2 = bit_and(r08D3, body.constant(3221225472u));
                        ir_expression *const r08E3 = equal(r08E2, body.constant(0u));
                        ir_if *f08E1 = new(mem_ctx) ir_if(operand(r08E3).val);
                        exec_list *const f08E1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08E1->then_instructions;

                           body.emit(assign(r08D5, add(r08D5, body.constant(int(2))), 0x01));

                           body.emit(assign(r08D3, lshift(r08D3, body.constant(int(2))), 0x01));


                        body.instructions = f08E1_parent_instructions;
                        body.emit(f08E1);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08E5 = bit_and(r08D3, body.constant(2147483648u));
                        ir_expression *const r08E6 = equal(r08E5, body.constant(0u));
                        ir_if *f08E4 = new(mem_ctx) ir_if(operand(r08E6).val);
                        exec_list *const f08E4_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08E4->then_instructions;

                           body.emit(assign(r08D5, add(r08D5, body.constant(int(1))), 0x01));


                        body.instructions = f08E4_parent_instructions;
                        body.emit(f08E4);

                        /* END IF */

                        body.emit(assign(r08D4, r08D5, 0x01));


                     body.instructions = f08D6_parent_instructions;
                     body.emit(f08D6);

                     /* END IF */

                     body.emit(assign(r08D0, add(r08D4, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08E8 = less(r08D0, body.constant(int(0)));
                     ir_if *f08E7 = new(mem_ctx) ir_if(operand(r08E8).val);
                     exec_list *const f08E7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08E7->then_instructions;

                        ir_expression *const r08E9 = neg(r08D0);
                        body.emit(assign(r08CE, rshift(swizzle_x(r0827), r08E9), 0x01));

                        ir_expression *const r08EA = bit_and(r08D0, body.constant(int(31)));
                        body.emit(assign(r08CF, lshift(swizzle_x(r0827), r08EA), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08E7->else_instructions;

                        body.emit(assign(r08CE, lshift(swizzle_x(r0827), r08D0), 0x01));

                        body.emit(assign(r08CF, body.constant(0u), 0x01));


                     body.instructions = f08E7_parent_instructions;
                     body.emit(f08E7);

                     /* END IF */

                     body.emit(assign(r08CD, sub(body.constant(int(-31)), r08D0), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08D1->else_instructions;

                     ir_variable *const r08EB = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r08EB, r0838, 0x01));

                     ir_variable *const r08EC = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r08ED = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r08ED);
                     /* IF CONDITION */
                     ir_expression *const r08EF = equal(r0838, body.constant(0u));
                     ir_if *f08EE = new(mem_ctx) ir_if(operand(r08EF).val);
                     exec_list *const f08EE_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08EE->then_instructions;

                        body.emit(assign(r08EC, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08EE->else_instructions;

                        body.emit(assign(r08ED, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08F1 = bit_and(r0838, body.constant(4294901760u));
                        ir_expression *const r08F2 = equal(r08F1, body.constant(0u));
                        ir_if *f08F0 = new(mem_ctx) ir_if(operand(r08F2).val);
                        exec_list *const f08F0_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08F0->then_instructions;

                           body.emit(assign(r08ED, body.constant(int(16)), 0x01));

                           body.emit(assign(r08EB, lshift(r0838, body.constant(int(16))), 0x01));


                        body.instructions = f08F0_parent_instructions;
                        body.emit(f08F0);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08F4 = bit_and(r08EB, body.constant(4278190080u));
                        ir_expression *const r08F5 = equal(r08F4, body.constant(0u));
                        ir_if *f08F3 = new(mem_ctx) ir_if(operand(r08F5).val);
                        exec_list *const f08F3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08F3->then_instructions;

                           body.emit(assign(r08ED, add(r08ED, body.constant(int(8))), 0x01));

                           body.emit(assign(r08EB, lshift(r08EB, body.constant(int(8))), 0x01));


                        body.instructions = f08F3_parent_instructions;
                        body.emit(f08F3);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08F7 = bit_and(r08EB, body.constant(4026531840u));
                        ir_expression *const r08F8 = equal(r08F7, body.constant(0u));
                        ir_if *f08F6 = new(mem_ctx) ir_if(operand(r08F8).val);
                        exec_list *const f08F6_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08F6->then_instructions;

                           body.emit(assign(r08ED, add(r08ED, body.constant(int(4))), 0x01));

                           body.emit(assign(r08EB, lshift(r08EB, body.constant(int(4))), 0x01));


                        body.instructions = f08F6_parent_instructions;
                        body.emit(f08F6);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08FA = bit_and(r08EB, body.constant(3221225472u));
                        ir_expression *const r08FB = equal(r08FA, body.constant(0u));
                        ir_if *f08F9 = new(mem_ctx) ir_if(operand(r08FB).val);
                        exec_list *const f08F9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08F9->then_instructions;

                           body.emit(assign(r08ED, add(r08ED, body.constant(int(2))), 0x01));

                           body.emit(assign(r08EB, lshift(r08EB, body.constant(int(2))), 0x01));


                        body.instructions = f08F9_parent_instructions;
                        body.emit(f08F9);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08FD = bit_and(r08EB, body.constant(2147483648u));
                        ir_expression *const r08FE = equal(r08FD, body.constant(0u));
                        ir_if *f08FC = new(mem_ctx) ir_if(operand(r08FE).val);
                        exec_list *const f08FC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08FC->then_instructions;

                           body.emit(assign(r08ED, add(r08ED, body.constant(int(1))), 0x01));


                        body.instructions = f08FC_parent_instructions;
                        body.emit(f08FC);

                        /* END IF */

                        body.emit(assign(r08EC, r08ED, 0x01));


                     body.instructions = f08EE_parent_instructions;
                     body.emit(f08EE);

                     /* END IF */

                     body.emit(assign(r08D0, add(r08EC, body.constant(int(-11))), 0x01));

                     ir_variable *const r08FF = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r08FF, lshift(swizzle_x(r0827), r08D0), 0x01));

                     ir_variable *const r0900 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0902 = equal(r08D0, body.constant(int(0)));
                     ir_if *f0901 = new(mem_ctx) ir_if(operand(r0902).val);
                     exec_list *const f0901_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0901->then_instructions;

                        body.emit(assign(r0900, r0838, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0901->else_instructions;

                        ir_expression *const r0903 = lshift(r0838, r08D0);
                        ir_expression *const r0904 = neg(r08D0);
                        ir_expression *const r0905 = bit_and(r0904, body.constant(int(31)));
                        ir_expression *const r0906 = rshift(swizzle_x(r0827), r0905);
                        body.emit(assign(r0900, bit_or(r0903, r0906), 0x01));


                     body.instructions = f0901_parent_instructions;
                     body.emit(f0901);

                     /* END IF */

                     body.emit(assign(r08CE, r0900, 0x01));

                     body.emit(assign(r08CF, r08FF, 0x01));

                     body.emit(assign(r08CD, sub(body.constant(int(1)), r08D0), 0x01));


                  body.instructions = f08D1_parent_instructions;
                  body.emit(f08D1);

                  /* END IF */

                  body.emit(assign(r082B, r08CD, 0x01));

                  body.emit(assign(r082D, r08CE, 0x01));

                  body.emit(assign(r082E, r08CF, 0x01));


               body.instructions = f08C9_parent_instructions;
               body.emit(f08C9);

               /* END IF */


            body.instructions = f08C7_parent_instructions;
            body.emit(f08C7);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0907 = new(mem_ctx) ir_if(operand(r0828).val);
            exec_list *const f0907_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0907->then_instructions;

               ir_expression *const r0908 = add(r082C, r082B);
               body.emit(assign(r0831, add(r0908, body.constant(int(-1024))), 0x01));

               body.emit(assign(r082F, bit_or(r082F, body.constant(1048576u)), 0x01));

               ir_variable *const r0909 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0909, lshift(r082E, body.constant(int(12))), 0x01));

               ir_variable *const r090A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               ir_expression *const r090B = lshift(r082D, body.constant(int(12)));
               ir_expression *const r090C = rshift(r082E, body.constant(int(20)));
               body.emit(assign(r090A, bit_or(r090B, r090C), 0x01));

               body.emit(assign(r082D, r090A, 0x01));

               body.emit(assign(r082E, r0909, 0x01));

               ir_variable *const r090D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r090D);
               ir_variable *const r090E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r090E);
               ir_variable *const r090F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r090F);
               ir_variable *const r0910 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0910, bit_and(r0830, body.constant(65535u)), 0x01));

               ir_variable *const r0911 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0911, rshift(r0830, body.constant(int(16))), 0x01));

               ir_variable *const r0912 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0912, bit_and(r0909, body.constant(65535u)), 0x01));

               ir_variable *const r0913 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0913, rshift(r0909, body.constant(int(16))), 0x01));

               ir_variable *const r0914 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0914, mul(r0911, r0912), 0x01));

               ir_expression *const r0915 = mul(r0910, r0913);
               body.emit(assign(r090E, add(r0915, r0914), 0x01));

               ir_expression *const r0916 = mul(r0911, r0913);
               ir_expression *const r0917 = less(r090E, r0914);
               ir_expression *const r0918 = expr(ir_unop_b2i, r0917);
               ir_expression *const r0919 = expr(ir_unop_i2u, r0918);
               ir_expression *const r091A = lshift(r0919, body.constant(int(16)));
               ir_expression *const r091B = rshift(r090E, body.constant(int(16)));
               ir_expression *const r091C = add(r091A, r091B);
               body.emit(assign(r090D, add(r0916, r091C), 0x01));

               body.emit(assign(r090E, lshift(r090E, body.constant(int(16))), 0x01));

               ir_expression *const r091D = mul(r0910, r0912);
               body.emit(assign(r090F, add(r091D, r090E), 0x01));

               ir_expression *const r091E = less(r090F, r090E);
               ir_expression *const r091F = expr(ir_unop_b2i, r091E);
               ir_expression *const r0920 = expr(ir_unop_i2u, r091F);
               body.emit(assign(r090D, add(r090D, r0920), 0x01));

               ir_variable *const r0921 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0921);
               ir_variable *const r0922 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0922);
               ir_variable *const r0923 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0923);
               ir_variable *const r0924 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0924, bit_and(r0830, body.constant(65535u)), 0x01));

               ir_variable *const r0925 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0925, rshift(r0830, body.constant(int(16))), 0x01));

               ir_variable *const r0926 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0926, bit_and(r090A, body.constant(65535u)), 0x01));

               ir_variable *const r0927 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0927, rshift(r090A, body.constant(int(16))), 0x01));

               ir_variable *const r0928 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0928, mul(r0925, r0926), 0x01));

               ir_expression *const r0929 = mul(r0924, r0927);
               body.emit(assign(r0922, add(r0929, r0928), 0x01));

               ir_expression *const r092A = mul(r0925, r0927);
               ir_expression *const r092B = less(r0922, r0928);
               ir_expression *const r092C = expr(ir_unop_b2i, r092B);
               ir_expression *const r092D = expr(ir_unop_i2u, r092C);
               ir_expression *const r092E = lshift(r092D, body.constant(int(16)));
               ir_expression *const r092F = rshift(r0922, body.constant(int(16)));
               ir_expression *const r0930 = add(r092E, r092F);
               body.emit(assign(r0921, add(r092A, r0930), 0x01));

               body.emit(assign(r0922, lshift(r0922, body.constant(int(16))), 0x01));

               ir_expression *const r0931 = mul(r0924, r0926);
               body.emit(assign(r0923, add(r0931, r0922), 0x01));

               ir_expression *const r0932 = less(r0923, r0922);
               ir_expression *const r0933 = expr(ir_unop_b2i, r0932);
               ir_expression *const r0934 = expr(ir_unop_i2u, r0933);
               body.emit(assign(r0921, add(r0921, r0934), 0x01));

               ir_variable *const r0935 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0935, add(r0923, r090D), 0x01));

               ir_variable *const r0936 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0936);
               ir_variable *const r0937 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0937);
               ir_variable *const r0938 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0938);
               ir_variable *const r0939 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0939, bit_and(r082F, body.constant(65535u)), 0x01));

               ir_variable *const r093A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r093A, rshift(r082F, body.constant(int(16))), 0x01));

               ir_variable *const r093B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r093B, bit_and(r090A, body.constant(65535u)), 0x01));

               ir_variable *const r093C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r093C, rshift(r090A, body.constant(int(16))), 0x01));

               ir_variable *const r093D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r093D, mul(r093A, r093B), 0x01));

               ir_expression *const r093E = mul(r0939, r093C);
               body.emit(assign(r0937, add(r093E, r093D), 0x01));

               ir_expression *const r093F = mul(r093A, r093C);
               ir_expression *const r0940 = less(r0937, r093D);
               ir_expression *const r0941 = expr(ir_unop_b2i, r0940);
               ir_expression *const r0942 = expr(ir_unop_i2u, r0941);
               ir_expression *const r0943 = lshift(r0942, body.constant(int(16)));
               ir_expression *const r0944 = rshift(r0937, body.constant(int(16)));
               ir_expression *const r0945 = add(r0943, r0944);
               body.emit(assign(r0936, add(r093F, r0945), 0x01));

               body.emit(assign(r0937, lshift(r0937, body.constant(int(16))), 0x01));

               ir_expression *const r0946 = mul(r0939, r093B);
               body.emit(assign(r0938, add(r0946, r0937), 0x01));

               ir_expression *const r0947 = less(r0938, r0937);
               ir_expression *const r0948 = expr(ir_unop_b2i, r0947);
               ir_expression *const r0949 = expr(ir_unop_i2u, r0948);
               body.emit(assign(r0936, add(r0936, r0949), 0x01));

               ir_variable *const r094A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r094B = less(r0935, r0923);
               ir_expression *const r094C = expr(ir_unop_b2i, r094B);
               ir_expression *const r094D = expr(ir_unop_i2u, r094C);
               ir_expression *const r094E = add(r0921, r094D);
               body.emit(assign(r094A, add(r0938, r094E), 0x01));

               ir_variable *const r094F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r094F);
               ir_variable *const r0950 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0950);
               ir_variable *const r0951 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0951);
               ir_variable *const r0952 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0952, bit_and(r082F, body.constant(65535u)), 0x01));

               ir_variable *const r0953 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0953, rshift(r082F, body.constant(int(16))), 0x01));

               ir_variable *const r0954 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0954, bit_and(r0909, body.constant(65535u)), 0x01));

               ir_variable *const r0955 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0955, rshift(r0909, body.constant(int(16))), 0x01));

               ir_variable *const r0956 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0956, mul(r0953, r0954), 0x01));

               ir_expression *const r0957 = mul(r0952, r0955);
               body.emit(assign(r0950, add(r0957, r0956), 0x01));

               ir_expression *const r0958 = mul(r0953, r0955);
               ir_expression *const r0959 = less(r0950, r0956);
               ir_expression *const r095A = expr(ir_unop_b2i, r0959);
               ir_expression *const r095B = expr(ir_unop_i2u, r095A);
               ir_expression *const r095C = lshift(r095B, body.constant(int(16)));
               ir_expression *const r095D = rshift(r0950, body.constant(int(16)));
               ir_expression *const r095E = add(r095C, r095D);
               body.emit(assign(r094F, add(r0958, r095E), 0x01));

               body.emit(assign(r0950, lshift(r0950, body.constant(int(16))), 0x01));

               ir_expression *const r095F = mul(r0952, r0954);
               body.emit(assign(r0951, add(r095F, r0950), 0x01));

               ir_expression *const r0960 = less(r0951, r0950);
               ir_expression *const r0961 = expr(ir_unop_b2i, r0960);
               ir_expression *const r0962 = expr(ir_unop_i2u, r0961);
               body.emit(assign(r094F, add(r094F, r0962), 0x01));

               ir_variable *const r0963 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0963, add(r0951, r0935), 0x01));

               ir_variable *const r0964 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0965 = less(r0963, r0951);
               ir_expression *const r0966 = expr(ir_unop_b2i, r0965);
               ir_expression *const r0967 = expr(ir_unop_i2u, r0966);
               ir_expression *const r0968 = add(r094F, r0967);
               body.emit(assign(r0964, add(r094A, r0968), 0x01));

               ir_variable *const r0969 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r096A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r096A, add(r0964, r0830), 0x01));

               ir_expression *const r096B = less(r094A, r0938);
               ir_expression *const r096C = expr(ir_unop_b2i, r096B);
               ir_expression *const r096D = expr(ir_unop_i2u, r096C);
               ir_expression *const r096E = add(r0936, r096D);
               ir_expression *const r096F = less(r0964, r094A);
               ir_expression *const r0970 = expr(ir_unop_b2i, r096F);
               ir_expression *const r0971 = expr(ir_unop_i2u, r0970);
               ir_expression *const r0972 = add(r096E, r0971);
               ir_expression *const r0973 = add(r0972, r082F);
               ir_expression *const r0974 = less(r096A, r0964);
               ir_expression *const r0975 = expr(ir_unop_b2i, r0974);
               ir_expression *const r0976 = expr(ir_unop_i2u, r0975);
               body.emit(assign(r0969, add(r0973, r0976), 0x01));

               body.emit(assign(r0834, r0969, 0x01));

               body.emit(assign(r0833, r096A, 0x01));

               ir_expression *const r0977 = nequal(r090F, body.constant(0u));
               ir_expression *const r0978 = expr(ir_unop_b2i, r0977);
               ir_expression *const r0979 = expr(ir_unop_i2u, r0978);
               body.emit(assign(r0832, bit_or(r0963, r0979), 0x01));

               /* IF CONDITION */
               ir_expression *const r097B = gequal(r0969, body.constant(2097152u));
               ir_if *f097A = new(mem_ctx) ir_if(operand(r097B).val);
               exec_list *const f097A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f097A->then_instructions;

                  ir_variable *const r097C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r097C);
                  body.emit(assign(r097C, lshift(r096A, body.constant(int(31))), 0x01));

                  ir_expression *const r097D = nequal(r0832, body.constant(0u));
                  ir_expression *const r097E = expr(ir_unop_b2i, r097D);
                  ir_expression *const r097F = expr(ir_unop_i2u, r097E);
                  body.emit(assign(r097C, bit_or(r097C, r097F), 0x01));

                  body.emit(assign(r0834, rshift(r0969, body.constant(int(1))), 0x01));

                  ir_expression *const r0980 = lshift(r0969, body.constant(int(31)));
                  ir_expression *const r0981 = rshift(r096A, body.constant(int(1)));
                  body.emit(assign(r0833, bit_or(r0980, r0981), 0x01));

                  body.emit(assign(r0832, r097C, 0x01));

                  body.emit(assign(r0831, add(r0831, body.constant(int(1))), 0x01));


               body.instructions = f097A_parent_instructions;
               body.emit(f097A);

               /* END IF */

               ir_variable *const r0982 = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0982, r0831, 0x01));

               ir_variable *const r0983 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r0983, r0834, 0x01));

               ir_variable *const r0984 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0984, r0833, 0x01));

               ir_variable *const r0985 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r0985, r0832, 0x01));

               ir_variable *const r0986 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0986, body.constant(true), 0x01));

               ir_variable *const r0987 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0988 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0988);
               ir_expression *const r0989 = expr(ir_unop_u2i, r0832);
               body.emit(assign(r0988, less(r0989, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r098B = gequal(r0831, body.constant(int(2045)));
               ir_if *f098A = new(mem_ctx) ir_if(operand(r098B).val);
               exec_list *const f098A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f098A->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r098D = less(body.constant(int(2045)), r0831);
                  ir_expression *const r098E = equal(r0831, body.constant(int(2045)));
                  ir_expression *const r098F = equal(body.constant(2097151u), r0834);
                  ir_expression *const r0990 = equal(body.constant(4294967295u), r0833);
                  ir_expression *const r0991 = logic_and(r098F, r0990);
                  ir_expression *const r0992 = logic_and(r098E, r0991);
                  ir_expression *const r0993 = logic_and(r0992, r0988);
                  ir_expression *const r0994 = logic_or(r098D, r0993);
                  ir_if *f098C = new(mem_ctx) ir_if(operand(r0994).val);
                  exec_list *const f098C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f098C->then_instructions;

                     ir_variable *const r0995 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0995);
                     ir_expression *const r0996 = lshift(r082A, body.constant(int(31)));
                     body.emit(assign(r0995, add(r0996, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r0995, body.constant(0u), 0x01));

                     body.emit(assign(r0987, r0995, 0x03));

                     body.emit(assign(r0986, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f098C->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0998 = less(r0831, body.constant(int(0)));
                     ir_if *f0997 = new(mem_ctx) ir_if(operand(r0998).val);
                     exec_list *const f0997_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0997->then_instructions;

                        ir_variable *const r0999 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0999, r0832, 0x01));

                        ir_variable *const r099A = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r099A, neg(r0831), 0x01));

                        ir_variable *const r099B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r099B);
                        ir_variable *const r099C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r099C);
                        ir_variable *const r099D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r099D);
                        ir_variable *const r099E = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r099F = neg(r099A);
                        body.emit(assign(r099E, bit_and(r099F, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r09A1 = equal(r099A, body.constant(int(0)));
                        ir_if *f09A0 = new(mem_ctx) ir_if(operand(r09A1).val);
                        exec_list *const f09A0_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f09A0->then_instructions;

                           body.emit(assign(r099B, r0832, 0x01));

                           body.emit(assign(r099C, r0833, 0x01));

                           body.emit(assign(r099D, r0834, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f09A0->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r09A3 = less(r099A, body.constant(int(32)));
                           ir_if *f09A2 = new(mem_ctx) ir_if(operand(r09A3).val);
                           exec_list *const f09A2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f09A2->then_instructions;

                              body.emit(assign(r099B, lshift(r0833, r099E), 0x01));

                              ir_expression *const r09A4 = lshift(r0834, r099E);
                              ir_expression *const r09A5 = rshift(r0833, r099A);
                              body.emit(assign(r099C, bit_or(r09A4, r09A5), 0x01));

                              body.emit(assign(r099D, rshift(r0834, r099A), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f09A2->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r09A7 = equal(r099A, body.constant(int(32)));
                              ir_if *f09A6 = new(mem_ctx) ir_if(operand(r09A7).val);
                              exec_list *const f09A6_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f09A6->then_instructions;

                                 body.emit(assign(r099B, r0833, 0x01));

                                 body.emit(assign(r099C, r0834, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f09A6->else_instructions;

                                 body.emit(assign(r0999, bit_or(r0832, r0833), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r09A9 = less(r099A, body.constant(int(64)));
                                 ir_if *f09A8 = new(mem_ctx) ir_if(operand(r09A9).val);
                                 exec_list *const f09A8_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f09A8->then_instructions;

                                    body.emit(assign(r099B, lshift(r0834, r099E), 0x01));

                                    ir_expression *const r09AA = bit_and(r099A, body.constant(int(31)));
                                    body.emit(assign(r099C, rshift(r0834, r09AA), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f09A8->else_instructions;

                                    ir_variable *const r09AB = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r09AD = equal(r099A, body.constant(int(64)));
                                    ir_if *f09AC = new(mem_ctx) ir_if(operand(r09AD).val);
                                    exec_list *const f09AC_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f09AC->then_instructions;

                                       body.emit(assign(r09AB, r0834, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f09AC->else_instructions;

                                       ir_expression *const r09AE = nequal(r0834, body.constant(0u));
                                       ir_expression *const r09AF = expr(ir_unop_b2i, r09AE);
                                       body.emit(assign(r09AB, expr(ir_unop_i2u, r09AF), 0x01));


                                    body.instructions = f09AC_parent_instructions;
                                    body.emit(f09AC);

                                    /* END IF */

                                    body.emit(assign(r099B, r09AB, 0x01));

                                    body.emit(assign(r099C, body.constant(0u), 0x01));


                                 body.instructions = f09A8_parent_instructions;
                                 body.emit(f09A8);

                                 /* END IF */


                              body.instructions = f09A6_parent_instructions;
                              body.emit(f09A6);

                              /* END IF */

                              body.emit(assign(r099D, body.constant(0u), 0x01));


                           body.instructions = f09A2_parent_instructions;
                           body.emit(f09A2);

                           /* END IF */

                           ir_expression *const r09B0 = nequal(r0999, body.constant(0u));
                           ir_expression *const r09B1 = expr(ir_unop_b2i, r09B0);
                           ir_expression *const r09B2 = expr(ir_unop_i2u, r09B1);
                           body.emit(assign(r099B, bit_or(r099B, r09B2), 0x01));


                        body.instructions = f09A0_parent_instructions;
                        body.emit(f09A0);

                        /* END IF */

                        body.emit(assign(r0983, r099D, 0x01));

                        body.emit(assign(r0984, r099C, 0x01));

                        body.emit(assign(r0985, r099B, 0x01));

                        body.emit(assign(r0982, body.constant(int(0)), 0x01));

                        body.emit(assign(r0988, less(r099B, body.constant(0u)), 0x01));


                     body.instructions = f0997_parent_instructions;
                     body.emit(f0997);

                     /* END IF */


                  body.instructions = f098C_parent_instructions;
                  body.emit(f098C);

                  /* END IF */


               body.instructions = f098A_parent_instructions;
               body.emit(f098A);

               /* END IF */

               /* IF CONDITION */
               ir_if *f09B3 = new(mem_ctx) ir_if(operand(r0986).val);
               exec_list *const f09B3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09B3->then_instructions;

                  /* IF CONDITION */
                  ir_if *f09B4 = new(mem_ctx) ir_if(operand(r0988).val);
                  exec_list *const f09B4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09B4->then_instructions;

                     ir_variable *const r09B5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r09B5, add(r0984, body.constant(1u)), 0x01));

                     ir_expression *const r09B6 = less(r09B5, r0984);
                     ir_expression *const r09B7 = expr(ir_unop_b2i, r09B6);
                     ir_expression *const r09B8 = expr(ir_unop_i2u, r09B7);
                     body.emit(assign(r0983, add(r0983, r09B8), 0x01));

                     ir_expression *const r09B9 = equal(r0985, body.constant(0u));
                     ir_expression *const r09BA = expr(ir_unop_b2i, r09B9);
                     ir_expression *const r09BB = expr(ir_unop_i2u, r09BA);
                     ir_expression *const r09BC = add(r0985, r09BB);
                     ir_expression *const r09BD = bit_and(r09BC, body.constant(1u));
                     ir_expression *const r09BE = expr(ir_unop_bit_not, r09BD);
                     body.emit(assign(r0984, bit_and(r09B5, r09BE), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09B4->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09C0 = bit_or(r0983, r0984);
                     ir_expression *const r09C1 = equal(r09C0, body.constant(0u));
                     ir_if *f09BF = new(mem_ctx) ir_if(operand(r09C1).val);
                     exec_list *const f09BF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09BF->then_instructions;

                        body.emit(assign(r0982, body.constant(int(0)), 0x01));


                     body.instructions = f09BF_parent_instructions;
                     body.emit(f09BF);

                     /* END IF */


                  body.instructions = f09B4_parent_instructions;
                  body.emit(f09B4);

                  /* END IF */

                  ir_variable *const r09C2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r09C2);
                  ir_expression *const r09C3 = lshift(r082A, body.constant(int(31)));
                  ir_expression *const r09C4 = expr(ir_unop_i2u, r0982);
                  ir_expression *const r09C5 = lshift(r09C4, body.constant(int(20)));
                  ir_expression *const r09C6 = add(r09C3, r09C5);
                  body.emit(assign(r09C2, add(r09C6, r0983), 0x02));

                  body.emit(assign(r09C2, r0984, 0x01));

                  body.emit(assign(r0987, r09C2, 0x03));

                  body.emit(assign(r0986, body.constant(false), 0x01));


               body.instructions = f09B3_parent_instructions;
               body.emit(f09B3);

               /* END IF */

               body.emit(assign(r0829, r0987, 0x03));

               body.emit(assign(r0828, body.constant(false), 0x01));


            body.instructions = f0907_parent_instructions;
            body.emit(f0907);

            /* END IF */


         body.instructions = f08C6_parent_instructions;
         body.emit(f08C6);

         /* END IF */


      body.instructions = f0866_parent_instructions;
      body.emit(f0866);

      /* END IF */


   body.instructions = f0841_parent_instructions;
   body.emit(f0841);

   /* END IF */

   body.emit(ret(r0829));

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

   ir_variable *const r09C7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09C7);
   ir_variable *const r09C8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09C8);
   ir_variable *const r09C9 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r09C9);
   ir_variable *const r09CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09CA);
   ir_variable *const r09CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09CB);
   ir_expression *const r09CC = equal(r09C9, body.constant(int(0)));
   ir_expression *const r09CD = less(r09C9, body.constant(int(32)));
   ir_expression *const r09CE = neg(r09C9);
   ir_expression *const r09CF = bit_and(r09CE, body.constant(int(31)));
   ir_expression *const r09D0 = lshift(r09C7, r09CF);
   ir_expression *const r09D1 = rshift(r09C8, r09C9);
   ir_expression *const r09D2 = bit_or(r09D0, r09D1);
   ir_expression *const r09D3 = less(r09C9, body.constant(int(64)));
   ir_expression *const r09D4 = bit_and(r09C9, body.constant(int(31)));
   ir_expression *const r09D5 = rshift(r09C7, r09D4);
   ir_expression *const r09D6 = expr(ir_triop_csel, r09D3, r09D5, body.constant(0u));
   ir_expression *const r09D7 = expr(ir_triop_csel, r09CD, r09D2, r09D6);
   body.emit(assign(r09CB, expr(ir_triop_csel, r09CC, r09C7, r09D7), 0x01));

   ir_expression *const r09D8 = equal(r09C9, body.constant(int(0)));
   ir_expression *const r09D9 = less(r09C9, body.constant(int(32)));
   ir_expression *const r09DA = rshift(r09C7, r09C9);
   ir_expression *const r09DB = expr(ir_triop_csel, r09D9, r09DA, body.constant(0u));
   body.emit(assign(r09CA, expr(ir_triop_csel, r09D8, r09C7, r09DB), 0x01));

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

   ir_variable *const r09DC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r09DC);
   ir_variable *const r09DD = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r09DE = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r09DE);
   ir_variable *const r09DF = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r09DF);
   ir_variable *const r09E0 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r09E0, swizzle_x(r09DC), 0x01));

   body.emit(assign(r09DF, r09E0, 0x01));

   ir_variable *const r09E1 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r09E1, bit_and(swizzle_y(r09DC), body.constant(1048575u)), 0x01));

   body.emit(assign(r09DE, r09E1, 0x01));

   ir_variable *const r09E2 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r09E3 = rshift(swizzle_y(r09DC), body.constant(int(20)));
   ir_expression *const r09E4 = bit_and(r09E3, body.constant(2047u));
   body.emit(assign(r09E2, expr(ir_unop_u2i, r09E4), 0x01));

   ir_variable *const r09E5 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r09E5, rshift(swizzle_y(r09DC), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r09E7 = nequal(r09E5, body.constant(0u));
   ir_if *f09E6 = new(mem_ctx) ir_if(operand(r09E7).val);
   exec_list *const f09E6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09E6->then_instructions;

      body.emit(assign(r09DD, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09E6->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09E9 = equal(r09E2, body.constant(int(2047)));
      ir_expression *const r09EA = bit_or(r09E1, swizzle_x(r09DC));
      ir_expression *const r09EB = nequal(r09EA, body.constant(0u));
      ir_expression *const r09EC = logic_and(r09E9, r09EB);
      ir_if *f09E8 = new(mem_ctx) ir_if(operand(r09EC).val);
      exec_list *const f09E8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09E8->then_instructions;

         body.emit(assign(r09DD, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09E8->else_instructions;

         /* IF CONDITION */
         ir_expression *const r09EE = nequal(r09E2, body.constant(int(0)));
         ir_if *f09ED = new(mem_ctx) ir_if(operand(r09EE).val);
         exec_list *const f09ED_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09ED->then_instructions;

            body.emit(assign(r09DE, bit_or(r09E1, body.constant(1048576u)), 0x01));


         body.instructions = f09ED_parent_instructions;
         body.emit(f09ED);

         /* END IF */

         ir_variable *const r09EF = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r09EF, sub(body.constant(int(1063)), r09E2), 0x01));

         /* IF CONDITION */
         ir_expression *const r09F1 = less(body.constant(int(0)), r09EF);
         ir_if *f09F0 = new(mem_ctx) ir_if(operand(r09F1).val);
         exec_list *const f09F0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09F0->then_instructions;

            ir_variable *const r09F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r09F2);
            ir_variable *const r09F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r09F3);
            ir_variable *const r09F4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r09F5 = neg(r09EF);
            body.emit(assign(r09F4, bit_and(r09F5, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r09F7 = equal(r09EF, body.constant(int(0)));
            ir_if *f09F6 = new(mem_ctx) ir_if(operand(r09F7).val);
            exec_list *const f09F6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f09F6->then_instructions;

               body.emit(assign(r09F2, r09E0, 0x01));

               body.emit(assign(r09F3, r09DE, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f09F6->else_instructions;

               /* IF CONDITION */
               ir_expression *const r09F9 = less(r09EF, body.constant(int(32)));
               ir_if *f09F8 = new(mem_ctx) ir_if(operand(r09F9).val);
               exec_list *const f09F8_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09F8->then_instructions;

                  ir_expression *const r09FA = lshift(r09DE, r09F4);
                  ir_expression *const r09FB = rshift(swizzle_x(r09DC), r09EF);
                  ir_expression *const r09FC = bit_or(r09FA, r09FB);
                  ir_expression *const r09FD = lshift(swizzle_x(r09DC), r09F4);
                  ir_expression *const r09FE = nequal(r09FD, body.constant(0u));
                  ir_expression *const r09FF = expr(ir_unop_b2i, r09FE);
                  ir_expression *const r0A00 = expr(ir_unop_i2u, r09FF);
                  body.emit(assign(r09F2, bit_or(r09FC, r0A00), 0x01));

                  body.emit(assign(r09F3, rshift(r09DE, r09EF), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f09F8->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A02 = equal(r09EF, body.constant(int(32)));
                  ir_if *f0A01 = new(mem_ctx) ir_if(operand(r0A02).val);
                  exec_list *const f0A01_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A01->then_instructions;

                     ir_expression *const r0A03 = nequal(swizzle_x(r09DC), body.constant(0u));
                     ir_expression *const r0A04 = expr(ir_unop_b2i, r0A03);
                     ir_expression *const r0A05 = expr(ir_unop_i2u, r0A04);
                     body.emit(assign(r09F2, bit_or(r09DE, r0A05), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A01->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0A07 = less(r09EF, body.constant(int(64)));
                     ir_if *f0A06 = new(mem_ctx) ir_if(operand(r0A07).val);
                     exec_list *const f0A06_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0A06->then_instructions;

                        ir_expression *const r0A08 = bit_and(r09EF, body.constant(int(31)));
                        ir_expression *const r0A09 = rshift(r09DE, r0A08);
                        ir_expression *const r0A0A = lshift(r09DE, r09F4);
                        ir_expression *const r0A0B = bit_or(r0A0A, swizzle_x(r09DC));
                        ir_expression *const r0A0C = nequal(r0A0B, body.constant(0u));
                        ir_expression *const r0A0D = expr(ir_unop_b2i, r0A0C);
                        ir_expression *const r0A0E = expr(ir_unop_i2u, r0A0D);
                        body.emit(assign(r09F2, bit_or(r0A09, r0A0E), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0A06->else_instructions;

                        ir_expression *const r0A0F = bit_or(r09DE, swizzle_x(r09DC));
                        ir_expression *const r0A10 = nequal(r0A0F, body.constant(0u));
                        ir_expression *const r0A11 = expr(ir_unop_b2i, r0A10);
                        body.emit(assign(r09F2, expr(ir_unop_i2u, r0A11), 0x01));


                     body.instructions = f0A06_parent_instructions;
                     body.emit(f0A06);

                     /* END IF */


                  body.instructions = f0A01_parent_instructions;
                  body.emit(f0A01);

                  /* END IF */

                  body.emit(assign(r09F3, body.constant(0u), 0x01));


               body.instructions = f09F8_parent_instructions;
               body.emit(f09F8);

               /* END IF */


            body.instructions = f09F6_parent_instructions;
            body.emit(f09F6);

            /* END IF */

            body.emit(assign(r09DE, r09F3, 0x01));

            body.emit(assign(r09DF, r09F2, 0x01));


         body.instructions = f09F0_parent_instructions;
         body.emit(f09F0);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A13 = bit_and(r09DE, body.constant(4294963200u));
         ir_expression *const r0A14 = nequal(r0A13, body.constant(0u));
         ir_if *f0A12 = new(mem_ctx) ir_if(operand(r0A14).val);
         exec_list *const f0A12_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A12->then_instructions;

            ir_variable *const r0A15 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A17 = nequal(r09E5, body.constant(0u));
            ir_if *f0A16 = new(mem_ctx) ir_if(operand(r0A17).val);
            exec_list *const f0A16_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A16->then_instructions;

               body.emit(assign(r0A15, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A16->else_instructions;

               body.emit(assign(r0A15, body.constant(4294967295u), 0x01));


            body.instructions = f0A16_parent_instructions;
            body.emit(f0A16);

            /* END IF */

            body.emit(assign(r09DD, r0A15, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A12->else_instructions;

            ir_variable *const r0A18 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            ir_expression *const r0A19 = lshift(r09DE, body.constant(int(20)));
            ir_expression *const r0A1A = rshift(r09DF, body.constant(int(12)));
            body.emit(assign(r0A18, bit_or(r0A19, r0A1A), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A1C = nequal(r09E5, body.constant(0u));
            ir_expression *const r0A1D = nequal(r0A18, body.constant(0u));
            ir_expression *const r0A1E = logic_and(r0A1C, r0A1D);
            ir_if *f0A1B = new(mem_ctx) ir_if(operand(r0A1E).val);
            exec_list *const f0A1B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A1B->then_instructions;

               ir_variable *const r0A1F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0A21 = nequal(r09E5, body.constant(0u));
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

               body.emit(assign(r09DD, r0A1F, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A1B->else_instructions;

               body.emit(assign(r09DD, r0A18, 0x01));


            body.instructions = f0A1B_parent_instructions;
            body.emit(f0A1B);

            /* END IF */


         body.instructions = f0A12_parent_instructions;
         body.emit(f0A12);

         /* END IF */


      body.instructions = f09E8_parent_instructions;
      body.emit(f09E8);

      /* END IF */


   body.instructions = f09E6_parent_instructions;
   body.emit(f09E6);

   /* END IF */

   body.emit(ret(r09DD));

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

   ir_variable *const r0A22 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A22);
   ir_variable *const r0A23 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A24 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0A24);
   ir_variable *const r0A25 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0A25);
   /* IF CONDITION */
   ir_expression *const r0A27 = equal(r0A22, body.constant(0u));
   ir_if *f0A26 = new(mem_ctx) ir_if(operand(r0A27).val);
   exec_list *const f0A26_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A26->then_instructions;

      body.emit(assign(r0A23, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A26->else_instructions;

      ir_variable *const r0A28 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0A28, r0A22, 0x01));

      ir_variable *const r0A29 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0A2A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0A2A);
      /* IF CONDITION */
      ir_expression *const r0A2C = equal(r0A22, body.constant(0u));
      ir_if *f0A2B = new(mem_ctx) ir_if(operand(r0A2C).val);
      exec_list *const f0A2B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A2B->then_instructions;

         body.emit(assign(r0A29, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A2B->else_instructions;

         body.emit(assign(r0A2A, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A2E = bit_and(r0A22, body.constant(4294901760u));
         ir_expression *const r0A2F = equal(r0A2E, body.constant(0u));
         ir_if *f0A2D = new(mem_ctx) ir_if(operand(r0A2F).val);
         exec_list *const f0A2D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A2D->then_instructions;

            body.emit(assign(r0A2A, body.constant(int(16)), 0x01));

            body.emit(assign(r0A28, lshift(r0A22, body.constant(int(16))), 0x01));


         body.instructions = f0A2D_parent_instructions;
         body.emit(f0A2D);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A31 = bit_and(r0A28, body.constant(4278190080u));
         ir_expression *const r0A32 = equal(r0A31, body.constant(0u));
         ir_if *f0A30 = new(mem_ctx) ir_if(operand(r0A32).val);
         exec_list *const f0A30_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A30->then_instructions;

            body.emit(assign(r0A2A, add(r0A2A, body.constant(int(8))), 0x01));

            body.emit(assign(r0A28, lshift(r0A28, body.constant(int(8))), 0x01));


         body.instructions = f0A30_parent_instructions;
         body.emit(f0A30);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A34 = bit_and(r0A28, body.constant(4026531840u));
         ir_expression *const r0A35 = equal(r0A34, body.constant(0u));
         ir_if *f0A33 = new(mem_ctx) ir_if(operand(r0A35).val);
         exec_list *const f0A33_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A33->then_instructions;

            body.emit(assign(r0A2A, add(r0A2A, body.constant(int(4))), 0x01));

            body.emit(assign(r0A28, lshift(r0A28, body.constant(int(4))), 0x01));


         body.instructions = f0A33_parent_instructions;
         body.emit(f0A33);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A37 = bit_and(r0A28, body.constant(3221225472u));
         ir_expression *const r0A38 = equal(r0A37, body.constant(0u));
         ir_if *f0A36 = new(mem_ctx) ir_if(operand(r0A38).val);
         exec_list *const f0A36_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A36->then_instructions;

            body.emit(assign(r0A2A, add(r0A2A, body.constant(int(2))), 0x01));

            body.emit(assign(r0A28, lshift(r0A28, body.constant(int(2))), 0x01));


         body.instructions = f0A36_parent_instructions;
         body.emit(f0A36);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A3A = bit_and(r0A28, body.constant(2147483648u));
         ir_expression *const r0A3B = equal(r0A3A, body.constant(0u));
         ir_if *f0A39 = new(mem_ctx) ir_if(operand(r0A3B).val);
         exec_list *const f0A39_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A39->then_instructions;

            body.emit(assign(r0A2A, add(r0A2A, body.constant(int(1))), 0x01));


         body.instructions = f0A39_parent_instructions;
         body.emit(f0A39);

         /* END IF */

         body.emit(assign(r0A29, r0A2A, 0x01));


      body.instructions = f0A2B_parent_instructions;
      body.emit(f0A2B);

      /* END IF */

      ir_variable *const r0A3C = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0A3C, add(r0A29, body.constant(int(21))), 0x01));

      body.emit(assign(r0A25, body.constant(0u), 0x01));

      body.emit(assign(r0A24, body.constant(0u), 0x01));

      ir_variable *const r0A3D = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0A3E = neg(r0A3C);
      body.emit(assign(r0A3D, bit_and(r0A3E, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A40 = equal(r0A3C, body.constant(int(0)));
      ir_if *f0A3F = new(mem_ctx) ir_if(operand(r0A40).val);
      exec_list *const f0A3F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A3F->then_instructions;

         body.emit(assign(r0A25, body.constant(0u), 0x01));

         body.emit(assign(r0A24, r0A22, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A3F->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A42 = less(r0A3C, body.constant(int(32)));
         ir_if *f0A41 = new(mem_ctx) ir_if(operand(r0A42).val);
         exec_list *const f0A41_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A41->then_instructions;

            body.emit(assign(r0A25, rshift(r0A22, r0A3D), 0x01));

            body.emit(assign(r0A24, lshift(r0A22, r0A3C), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A41->else_instructions;

            ir_variable *const r0A43 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A45 = less(r0A3C, body.constant(int(64)));
            ir_if *f0A44 = new(mem_ctx) ir_if(operand(r0A45).val);
            exec_list *const f0A44_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A44->then_instructions;

               ir_expression *const r0A46 = add(r0A3C, body.constant(int(-32)));
               body.emit(assign(r0A43, lshift(r0A22, r0A46), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A44->else_instructions;

               body.emit(assign(r0A43, body.constant(0u), 0x01));


            body.instructions = f0A44_parent_instructions;
            body.emit(f0A44);

            /* END IF */

            body.emit(assign(r0A25, r0A43, 0x01));

            body.emit(assign(r0A24, body.constant(0u), 0x01));


         body.instructions = f0A41_parent_instructions;
         body.emit(f0A41);

         /* END IF */


      body.instructions = f0A3F_parent_instructions;
      body.emit(f0A3F);

      /* END IF */

      ir_variable *const r0A47 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A47);
      ir_expression *const r0A48 = sub(body.constant(int(1074)), r0A3C);
      ir_expression *const r0A49 = expr(ir_unop_i2u, r0A48);
      ir_expression *const r0A4A = lshift(r0A49, body.constant(int(20)));
      body.emit(assign(r0A47, add(r0A4A, r0A25), 0x02));

      body.emit(assign(r0A47, r0A24, 0x01));

      body.emit(assign(r0A23, r0A47, 0x03));


   body.instructions = f0A26_parent_instructions;
   body.emit(f0A26);

   /* END IF */

   body.emit(ret(r0A23));

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

   ir_variable *const r0A4B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A4B);
   ir_variable *const r0A4C = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A4C, body.constant(true), 0x01));

   ir_variable *const r0A4D = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0A4E = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0A4E);
   ir_variable *const r0A4F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A4F);
   ir_variable *const r0A50 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A50);
   ir_variable *const r0A51 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A51, bit_and(swizzle_y(r0A4B), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A50, r0A51, 0x01));

   ir_variable *const r0A52 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A53 = rshift(swizzle_y(r0A4B), body.constant(int(20)));
   ir_expression *const r0A54 = bit_and(r0A53, body.constant(2047u));
   body.emit(assign(r0A52, expr(ir_unop_u2i, r0A54), 0x01));

   body.emit(assign(r0A4F, rshift(swizzle_y(r0A4B), body.constant(int(31))), 0x01));

   body.emit(assign(r0A4E, body.constant(0u), 0x01));

   ir_variable *const r0A55 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0A55, add(r0A52, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A57 = gequal(r0A55, body.constant(int(0)));
   ir_if *f0A56 = new(mem_ctx) ir_if(operand(r0A57).val);
   exec_list *const f0A56_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A56->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A59 = less(body.constant(int(1054)), r0A52);
      ir_if *f0A58 = new(mem_ctx) ir_if(operand(r0A59).val);
      exec_list *const f0A58_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A58->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A5B = equal(r0A52, body.constant(int(2047)));
         ir_expression *const r0A5C = bit_or(r0A51, swizzle_x(r0A4B));
         ir_expression *const r0A5D = expr(ir_unop_u2i, r0A5C);
         ir_expression *const r0A5E = expr(ir_unop_i2b, r0A5D);
         ir_expression *const r0A5F = logic_and(r0A5B, r0A5E);
         ir_if *f0A5A = new(mem_ctx) ir_if(operand(r0A5F).val);
         exec_list *const f0A5A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A5A->then_instructions;

            body.emit(assign(r0A4F, body.constant(0u), 0x01));


         body.instructions = f0A5A_parent_instructions;
         body.emit(f0A5A);

         /* END IF */

         ir_variable *const r0A60 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A62 = expr(ir_unop_u2i, r0A4F);
         ir_expression *const r0A63 = expr(ir_unop_i2b, r0A62);
         ir_if *f0A61 = new(mem_ctx) ir_if(operand(r0A63).val);
         exec_list *const f0A61_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A61->then_instructions;

            body.emit(assign(r0A60, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A61->else_instructions;

            body.emit(assign(r0A60, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A61_parent_instructions;
         body.emit(f0A61);

         /* END IF */

         body.emit(assign(r0A4D, r0A60, 0x01));

         body.emit(assign(r0A4C, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A58->else_instructions;

         ir_variable *const r0A64 = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r0A64, bit_or(r0A51, body.constant(1048576u)), 0x01));

         ir_variable *const r0A65 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0A65, lshift(swizzle_x(r0A4B), r0A55), 0x01));

         ir_variable *const r0A66 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A68 = equal(r0A55, body.constant(int(0)));
         ir_if *f0A67 = new(mem_ctx) ir_if(operand(r0A68).val);
         exec_list *const f0A67_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A67->then_instructions;

            body.emit(assign(r0A66, r0A64, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A67->else_instructions;

            ir_expression *const r0A69 = lshift(r0A64, r0A55);
            ir_expression *const r0A6A = neg(r0A55);
            ir_expression *const r0A6B = bit_and(r0A6A, body.constant(int(31)));
            ir_expression *const r0A6C = rshift(swizzle_x(r0A4B), r0A6B);
            body.emit(assign(r0A66, bit_or(r0A69, r0A6C), 0x01));


         body.instructions = f0A67_parent_instructions;
         body.emit(f0A67);

         /* END IF */

         body.emit(assign(r0A4E, r0A66, 0x01));


      body.instructions = f0A58_parent_instructions;
      body.emit(f0A58);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A56->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A6E = less(r0A52, body.constant(int(1023)));
      ir_if *f0A6D = new(mem_ctx) ir_if(operand(r0A6E).val);
      exec_list *const f0A6D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A6D->then_instructions;

         body.emit(assign(r0A4D, body.constant(int(0)), 0x01));

         body.emit(assign(r0A4C, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A6D->else_instructions;

         body.emit(assign(r0A50, bit_or(r0A51, body.constant(1048576u)), 0x01));

         ir_expression *const r0A6F = neg(r0A55);
         body.emit(assign(r0A4E, rshift(r0A50, r0A6F), 0x01));


      body.instructions = f0A6D_parent_instructions;
      body.emit(f0A6D);

      /* END IF */


   body.instructions = f0A56_parent_instructions;
   body.emit(f0A56);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0A70 = new(mem_ctx) ir_if(operand(r0A4C).val);
   exec_list *const f0A70_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A70->then_instructions;

      ir_variable *const r0A71 = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A73 = nequal(r0A4F, body.constant(0u));
      ir_if *f0A72 = new(mem_ctx) ir_if(operand(r0A73).val);
      exec_list *const f0A72_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A72->then_instructions;

         ir_expression *const r0A74 = expr(ir_unop_u2i, r0A4E);
         body.emit(assign(r0A71, neg(r0A74), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A72->else_instructions;

         body.emit(assign(r0A71, expr(ir_unop_u2i, r0A4E), 0x01));


      body.instructions = f0A72_parent_instructions;
      body.emit(f0A72);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0A76 = less(r0A71, body.constant(int(0)));
      ir_expression *const r0A77 = expr(ir_unop_b2i, r0A76);
      ir_expression *const r0A78 = expr(ir_unop_i2u, r0A77);
      ir_expression *const r0A79 = bit_xor(r0A4F, r0A78);
      ir_expression *const r0A7A = expr(ir_unop_u2i, r0A79);
      ir_expression *const r0A7B = expr(ir_unop_i2b, r0A7A);
      ir_expression *const r0A7C = expr(ir_unop_i2b, r0A71);
      ir_expression *const r0A7D = logic_and(r0A7B, r0A7C);
      ir_if *f0A75 = new(mem_ctx) ir_if(operand(r0A7D).val);
      exec_list *const f0A75_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A75->then_instructions;

         ir_variable *const r0A7E = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A80 = expr(ir_unop_u2i, r0A4F);
         ir_expression *const r0A81 = expr(ir_unop_i2b, r0A80);
         ir_if *f0A7F = new(mem_ctx) ir_if(operand(r0A81).val);
         exec_list *const f0A7F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A7F->then_instructions;

            body.emit(assign(r0A7E, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A7F->else_instructions;

            body.emit(assign(r0A7E, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A7F_parent_instructions;
         body.emit(f0A7F);

         /* END IF */

         body.emit(assign(r0A4D, r0A7E, 0x01));

         body.emit(assign(r0A4C, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A75->else_instructions;

         body.emit(assign(r0A4D, r0A71, 0x01));

         body.emit(assign(r0A4C, body.constant(false), 0x01));


      body.instructions = f0A75_parent_instructions;
      body.emit(f0A75);

      /* END IF */


   body.instructions = f0A70_parent_instructions;
   body.emit(f0A70);

   /* END IF */

   body.emit(ret(r0A4D));

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

   ir_variable *const r0A82 = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A82);
   ir_variable *const r0A83 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A84 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0A84);
   ir_variable *const r0A85 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0A85);
   ir_variable *const r0A86 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0A86);
   body.emit(assign(r0A86, body.constant(0u), 0x01));

   body.emit(assign(r0A85, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A88 = equal(r0A82, body.constant(int(0)));
   ir_if *f0A87 = new(mem_ctx) ir_if(operand(r0A88).val);
   exec_list *const f0A87_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A87->then_instructions;

      ir_variable *const r0A89 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A89);
      body.emit(assign(r0A89, body.constant(0u), 0x02));

      body.emit(assign(r0A89, body.constant(0u), 0x01));

      body.emit(assign(r0A83, r0A89, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A87->else_instructions;

      ir_expression *const r0A8A = less(r0A82, body.constant(int(0)));
      ir_expression *const r0A8B = expr(ir_unop_b2i, r0A8A);
      body.emit(assign(r0A84, expr(ir_unop_i2u, r0A8B), 0x01));

      ir_variable *const r0A8C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A8E = less(r0A82, body.constant(int(0)));
      ir_if *f0A8D = new(mem_ctx) ir_if(operand(r0A8E).val);
      exec_list *const f0A8D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A8D->then_instructions;

         ir_expression *const r0A8F = neg(r0A82);
         body.emit(assign(r0A8C, expr(ir_unop_i2u, r0A8F), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A8D->else_instructions;

         body.emit(assign(r0A8C, expr(ir_unop_i2u, r0A82), 0x01));


      body.instructions = f0A8D_parent_instructions;
      body.emit(f0A8D);

      /* END IF */

      ir_variable *const r0A90 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0A90, r0A8C, 0x01));

      ir_variable *const r0A91 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0A92 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0A92);
      /* IF CONDITION */
      ir_expression *const r0A94 = equal(r0A8C, body.constant(0u));
      ir_if *f0A93 = new(mem_ctx) ir_if(operand(r0A94).val);
      exec_list *const f0A93_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A93->then_instructions;

         body.emit(assign(r0A91, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A93->else_instructions;

         body.emit(assign(r0A92, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A96 = bit_and(r0A8C, body.constant(4294901760u));
         ir_expression *const r0A97 = equal(r0A96, body.constant(0u));
         ir_if *f0A95 = new(mem_ctx) ir_if(operand(r0A97).val);
         exec_list *const f0A95_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A95->then_instructions;

            body.emit(assign(r0A92, body.constant(int(16)), 0x01));

            body.emit(assign(r0A90, lshift(r0A8C, body.constant(int(16))), 0x01));


         body.instructions = f0A95_parent_instructions;
         body.emit(f0A95);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A99 = bit_and(r0A90, body.constant(4278190080u));
         ir_expression *const r0A9A = equal(r0A99, body.constant(0u));
         ir_if *f0A98 = new(mem_ctx) ir_if(operand(r0A9A).val);
         exec_list *const f0A98_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A98->then_instructions;

            body.emit(assign(r0A92, add(r0A92, body.constant(int(8))), 0x01));

            body.emit(assign(r0A90, lshift(r0A90, body.constant(int(8))), 0x01));


         body.instructions = f0A98_parent_instructions;
         body.emit(f0A98);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A9C = bit_and(r0A90, body.constant(4026531840u));
         ir_expression *const r0A9D = equal(r0A9C, body.constant(0u));
         ir_if *f0A9B = new(mem_ctx) ir_if(operand(r0A9D).val);
         exec_list *const f0A9B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A9B->then_instructions;

            body.emit(assign(r0A92, add(r0A92, body.constant(int(4))), 0x01));

            body.emit(assign(r0A90, lshift(r0A90, body.constant(int(4))), 0x01));


         body.instructions = f0A9B_parent_instructions;
         body.emit(f0A9B);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A9F = bit_and(r0A90, body.constant(3221225472u));
         ir_expression *const r0AA0 = equal(r0A9F, body.constant(0u));
         ir_if *f0A9E = new(mem_ctx) ir_if(operand(r0AA0).val);
         exec_list *const f0A9E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A9E->then_instructions;

            body.emit(assign(r0A92, add(r0A92, body.constant(int(2))), 0x01));

            body.emit(assign(r0A90, lshift(r0A90, body.constant(int(2))), 0x01));


         body.instructions = f0A9E_parent_instructions;
         body.emit(f0A9E);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AA2 = bit_and(r0A90, body.constant(2147483648u));
         ir_expression *const r0AA3 = equal(r0AA2, body.constant(0u));
         ir_if *f0AA1 = new(mem_ctx) ir_if(operand(r0AA3).val);
         exec_list *const f0AA1_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA1->then_instructions;

            body.emit(assign(r0A92, add(r0A92, body.constant(int(1))), 0x01));


         body.instructions = f0AA1_parent_instructions;
         body.emit(f0AA1);

         /* END IF */

         body.emit(assign(r0A91, r0A92, 0x01));


      body.instructions = f0A93_parent_instructions;
      body.emit(f0A93);

      /* END IF */

      ir_variable *const r0AA4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0AA4, add(r0A91, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0AA6 = gequal(r0AA4, body.constant(int(0)));
      ir_if *f0AA5 = new(mem_ctx) ir_if(operand(r0AA6).val);
      exec_list *const f0AA5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AA5->then_instructions;

         body.emit(assign(r0A86, lshift(r0A8C, r0AA4), 0x01));

         body.emit(assign(r0A85, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AA5->else_instructions;

         ir_variable *const r0AA7 = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r0AA7, neg(r0AA4), 0x01));

         ir_expression *const r0AA8 = equal(r0AA7, body.constant(int(0)));
         ir_expression *const r0AA9 = less(r0AA7, body.constant(int(32)));
         ir_expression *const r0AAA = rshift(r0A8C, r0AA7);
         ir_expression *const r0AAB = expr(ir_triop_csel, r0AA9, r0AAA, body.constant(0u));
         body.emit(assign(r0A86, expr(ir_triop_csel, r0AA8, r0A8C, r0AAB), 0x01));

         ir_expression *const r0AAC = equal(r0AA7, body.constant(int(0)));
         ir_expression *const r0AAD = less(r0AA7, body.constant(int(32)));
         ir_expression *const r0AAE = neg(r0AA7);
         ir_expression *const r0AAF = bit_and(r0AAE, body.constant(int(31)));
         ir_expression *const r0AB0 = lshift(r0A8C, r0AAF);
         ir_expression *const r0AB1 = bit_or(r0AB0, body.constant(0u));
         ir_expression *const r0AB2 = less(r0AA7, body.constant(int(64)));
         ir_expression *const r0AB3 = bit_and(r0AA7, body.constant(int(31)));
         ir_expression *const r0AB4 = rshift(r0A8C, r0AB3);
         ir_expression *const r0AB5 = expr(ir_triop_csel, r0AB2, r0AB4, body.constant(0u));
         ir_expression *const r0AB6 = expr(ir_triop_csel, r0AAD, r0AB1, r0AB5);
         body.emit(assign(r0A85, expr(ir_triop_csel, r0AAC, r0A8C, r0AB6), 0x01));


      body.instructions = f0AA5_parent_instructions;
      body.emit(f0AA5);

      /* END IF */

      ir_variable *const r0AB7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0AB7);
      ir_expression *const r0AB8 = lshift(r0A84, body.constant(int(31)));
      ir_expression *const r0AB9 = sub(body.constant(int(1042)), r0AA4);
      ir_expression *const r0ABA = expr(ir_unop_i2u, r0AB9);
      ir_expression *const r0ABB = lshift(r0ABA, body.constant(int(20)));
      ir_expression *const r0ABC = add(r0AB8, r0ABB);
      body.emit(assign(r0AB7, add(r0ABC, r0A86), 0x02));

      body.emit(assign(r0AB7, r0A85, 0x01));

      body.emit(assign(r0A83, r0AB7, 0x03));


   body.instructions = f0A87_parent_instructions;
   body.emit(f0A87);

   /* END IF */

   body.emit(ret(r0A83));

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

   ir_variable *const r0ABD = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0ABD);
   ir_variable *const r0ABE = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0ABE);
   ir_variable *const r0ABF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0ABF);
   ir_variable *const r0AC0 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r0AC1 = lshift(r0ABD, body.constant(int(31)));
   ir_expression *const r0AC2 = expr(ir_unop_i2u, r0ABE);
   ir_expression *const r0AC3 = lshift(r0AC2, body.constant(int(23)));
   ir_expression *const r0AC4 = add(r0AC1, r0AC3);
   ir_expression *const r0AC5 = add(r0AC4, r0ABF);
   body.emit(assign(r0AC0, expr(ir_unop_bitcast_u2f, r0AC5), 0x01));

   body.emit(ret(r0AC0));

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

   ir_variable *const r0AC6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AC6);
   ir_variable *const r0AC7 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AC7);
   ir_variable *const r0AC8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AC8);
   ir_variable *const r0AC9 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0AC9, body.constant(true), 0x01));

   ir_variable *const r0ACA = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0ACB = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0ACB);
   ir_expression *const r0ACC = bit_and(r0AC8, body.constant(127u));
   body.emit(assign(r0ACB, expr(ir_unop_u2i, r0ACC), 0x01));

   /* IF CONDITION */
   ir_expression *const r0ACE = expr(ir_unop_i2u, r0AC7);
   ir_expression *const r0ACF = gequal(r0ACE, body.constant(253u));
   ir_if *f0ACD = new(mem_ctx) ir_if(operand(r0ACF).val);
   exec_list *const f0ACD_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0ACD->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0AD1 = less(body.constant(int(253)), r0AC7);
      ir_expression *const r0AD2 = equal(r0AC7, body.constant(int(253)));
      ir_expression *const r0AD3 = expr(ir_unop_u2i, r0AC8);
      ir_expression *const r0AD4 = less(r0AD3, body.constant(int(-64)));
      ir_expression *const r0AD5 = logic_and(r0AD2, r0AD4);
      ir_expression *const r0AD6 = logic_or(r0AD1, r0AD5);
      ir_if *f0AD0 = new(mem_ctx) ir_if(operand(r0AD6).val);
      exec_list *const f0AD0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AD0->then_instructions;

         ir_expression *const r0AD7 = lshift(r0AC6, body.constant(int(31)));
         ir_expression *const r0AD8 = add(r0AD7, body.constant(2139095040u));
         body.emit(assign(r0ACA, expr(ir_unop_bitcast_u2f, r0AD8), 0x01));

         body.emit(assign(r0AC9, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AD0->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0ADA = less(r0AC7, body.constant(int(0)));
         ir_if *f0AD9 = new(mem_ctx) ir_if(operand(r0ADA).val);
         exec_list *const f0AD9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AD9->then_instructions;

            ir_variable *const r0ADB = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0ADB, neg(r0AC7), 0x01));

            /* IF CONDITION */
            ir_expression *const r0ADD = less(r0ADB, body.constant(int(32)));
            ir_if *f0ADC = new(mem_ctx) ir_if(operand(r0ADD).val);
            exec_list *const f0ADC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0ADC->then_instructions;

               ir_expression *const r0ADE = rshift(r0AC8, r0ADB);
               ir_expression *const r0ADF = neg(r0ADB);
               ir_expression *const r0AE0 = bit_and(r0ADF, body.constant(int(31)));
               ir_expression *const r0AE1 = lshift(r0AC8, r0AE0);
               ir_expression *const r0AE2 = nequal(r0AE1, body.constant(0u));
               ir_expression *const r0AE3 = expr(ir_unop_b2i, r0AE2);
               ir_expression *const r0AE4 = expr(ir_unop_i2u, r0AE3);
               body.emit(assign(r0AC8, bit_or(r0ADE, r0AE4), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0ADC->else_instructions;

               ir_expression *const r0AE5 = nequal(r0AC8, body.constant(0u));
               ir_expression *const r0AE6 = expr(ir_unop_b2i, r0AE5);
               body.emit(assign(r0AC8, expr(ir_unop_i2u, r0AE6), 0x01));


            body.instructions = f0ADC_parent_instructions;
            body.emit(f0ADC);

            /* END IF */

            body.emit(assign(r0AC7, body.constant(int(0)), 0x01));

            ir_expression *const r0AE7 = expr(ir_unop_u2i, r0AC8);
            body.emit(assign(r0ACB, bit_and(r0AE7, body.constant(int(127))), 0x01));


         body.instructions = f0AD9_parent_instructions;
         body.emit(f0AD9);

         /* END IF */


      body.instructions = f0AD0_parent_instructions;
      body.emit(f0AD0);

      /* END IF */


   body.instructions = f0ACD_parent_instructions;
   body.emit(f0ACD);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0AE8 = new(mem_ctx) ir_if(operand(r0AC9).val);
   exec_list *const f0AE8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AE8->then_instructions;

      ir_expression *const r0AE9 = add(r0AC8, body.constant(64u));
      body.emit(assign(r0AC8, rshift(r0AE9, body.constant(int(7))), 0x01));

      ir_expression *const r0AEA = bit_xor(r0ACB, body.constant(int(64)));
      ir_expression *const r0AEB = equal(r0AEA, body.constant(int(0)));
      ir_expression *const r0AEC = expr(ir_unop_b2i, r0AEB);
      ir_expression *const r0AED = expr(ir_unop_i2u, r0AEC);
      ir_expression *const r0AEE = expr(ir_unop_bit_not, r0AED);
      body.emit(assign(r0AC8, bit_and(r0AC8, r0AEE), 0x01));

      /* IF CONDITION */
      ir_expression *const r0AF0 = equal(r0AC8, body.constant(0u));
      ir_if *f0AEF = new(mem_ctx) ir_if(operand(r0AF0).val);
      exec_list *const f0AEF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AEF->then_instructions;

         body.emit(assign(r0AC7, body.constant(int(0)), 0x01));


      body.instructions = f0AEF_parent_instructions;
      body.emit(f0AEF);

      /* END IF */

      ir_expression *const r0AF1 = lshift(r0AC6, body.constant(int(31)));
      ir_expression *const r0AF2 = expr(ir_unop_i2u, r0AC7);
      ir_expression *const r0AF3 = lshift(r0AF2, body.constant(int(23)));
      ir_expression *const r0AF4 = add(r0AF1, r0AF3);
      ir_expression *const r0AF5 = add(r0AF4, r0AC8);
      body.emit(assign(r0ACA, expr(ir_unop_bitcast_u2f, r0AF5), 0x01));

      body.emit(assign(r0AC9, body.constant(false), 0x01));


   body.instructions = f0AE8_parent_instructions;
   body.emit(f0AE8);

   /* END IF */

   body.emit(ret(r0ACA));

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

   ir_variable *const r0AF6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AF6);
   ir_variable *const r0AF7 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0AF8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0AF8);
   body.emit(assign(r0AF8, body.constant(0u), 0x01));

   ir_variable *const r0AF9 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0AF9, swizzle_x(r0AF6), 0x01));

   ir_variable *const r0AFA = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0AFA, bit_and(swizzle_y(r0AF6), body.constant(1048575u)), 0x01));

   ir_variable *const r0AFB = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0AFC = rshift(swizzle_y(r0AF6), body.constant(int(20)));
   ir_expression *const r0AFD = bit_and(r0AFC, body.constant(2047u));
   body.emit(assign(r0AFB, expr(ir_unop_u2i, r0AFD), 0x01));

   ir_variable *const r0AFE = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0AFE, rshift(swizzle_y(r0AF6), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B00 = equal(r0AFB, body.constant(int(2047)));
   ir_if *f0AFF = new(mem_ctx) ir_if(operand(r0B00).val);
   exec_list *const f0AFF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AFF->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B02 = bit_or(r0AFA, swizzle_x(r0AF6));
      ir_expression *const r0B03 = nequal(r0B02, body.constant(0u));
      ir_if *f0B01 = new(mem_ctx) ir_if(operand(r0B03).val);
      exec_list *const f0B01_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B01->then_instructions;

         ir_variable *const r0B04 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0B04, lshift(swizzle_x(r0AF6), body.constant(int(12))), 0x01));

         ir_variable *const r0B05 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         ir_expression *const r0B06 = lshift(swizzle_y(r0AF6), body.constant(int(12)));
         ir_expression *const r0B07 = rshift(swizzle_x(r0AF6), body.constant(int(20)));
         body.emit(assign(r0B05, bit_or(r0B06, r0B07), 0x01));

         body.emit(assign(r0AF6, r0B05, 0x02));

         body.emit(assign(r0AF6, r0B04, 0x01));

         ir_expression *const r0B08 = lshift(r0AFE, body.constant(int(31)));
         ir_expression *const r0B09 = bit_or(r0B08, body.constant(2143289344u));
         ir_expression *const r0B0A = rshift(r0B05, body.constant(int(9)));
         ir_expression *const r0B0B = bit_or(r0B09, r0B0A);
         body.emit(assign(r0AF7, expr(ir_unop_bitcast_u2f, r0B0B), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B01->else_instructions;

         ir_expression *const r0B0C = lshift(r0AFE, body.constant(int(31)));
         ir_expression *const r0B0D = add(r0B0C, body.constant(2139095040u));
         body.emit(assign(r0AF7, expr(ir_unop_bitcast_u2f, r0B0D), 0x01));


      body.instructions = f0B01_parent_instructions;
      body.emit(f0B01);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AFF->else_instructions;

      ir_variable *const r0B0E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B0E);
      ir_variable *const r0B0F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0B0F);
      ir_expression *const r0B10 = lshift(r0AFA, body.constant(int(10)));
      ir_expression *const r0B11 = rshift(r0AF9, body.constant(int(22)));
      ir_expression *const r0B12 = bit_or(r0B10, r0B11);
      ir_expression *const r0B13 = lshift(r0AF9, body.constant(int(10)));
      ir_expression *const r0B14 = nequal(r0B13, body.constant(0u));
      ir_expression *const r0B15 = expr(ir_unop_b2i, r0B14);
      ir_expression *const r0B16 = expr(ir_unop_i2u, r0B15);
      body.emit(assign(r0B0E, bit_or(r0B12, r0B16), 0x01));

      body.emit(assign(r0B0F, rshift(r0AFA, body.constant(int(22))), 0x01));

      body.emit(assign(r0AF8, r0B0E, 0x01));

      /* IF CONDITION */
      ir_expression *const r0B18 = nequal(r0AFB, body.constant(int(0)));
      ir_if *f0B17 = new(mem_ctx) ir_if(operand(r0B18).val);
      exec_list *const f0B17_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B17->then_instructions;

         body.emit(assign(r0AF8, bit_or(r0B0E, body.constant(1073741824u)), 0x01));


      body.instructions = f0B17_parent_instructions;
      body.emit(f0B17);

      /* END IF */

      ir_variable *const r0B19 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B19, add(r0AFB, body.constant(int(-897))), 0x01));

      ir_variable *const r0B1A = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B1A, r0AF8, 0x01));

      ir_variable *const r0B1B = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B1B, body.constant(true), 0x01));

      ir_variable *const r0B1C = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B1D = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B1D);
      ir_expression *const r0B1E = bit_and(r0AF8, body.constant(127u));
      body.emit(assign(r0B1D, expr(ir_unop_u2i, r0B1E), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B20 = expr(ir_unop_i2u, r0B19);
      ir_expression *const r0B21 = gequal(r0B20, body.constant(253u));
      ir_if *f0B1F = new(mem_ctx) ir_if(operand(r0B21).val);
      exec_list *const f0B1F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B1F->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B23 = less(body.constant(int(253)), r0B19);
         ir_expression *const r0B24 = equal(r0B19, body.constant(int(253)));
         ir_expression *const r0B25 = expr(ir_unop_u2i, r0AF8);
         ir_expression *const r0B26 = less(r0B25, body.constant(int(-64)));
         ir_expression *const r0B27 = logic_and(r0B24, r0B26);
         ir_expression *const r0B28 = logic_or(r0B23, r0B27);
         ir_if *f0B22 = new(mem_ctx) ir_if(operand(r0B28).val);
         exec_list *const f0B22_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B22->then_instructions;

            ir_expression *const r0B29 = lshift(r0AFE, body.constant(int(31)));
            ir_expression *const r0B2A = add(r0B29, body.constant(2139095040u));
            body.emit(assign(r0B1C, expr(ir_unop_bitcast_u2f, r0B2A), 0x01));

            body.emit(assign(r0B1B, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B22->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0B2C = less(r0B19, body.constant(int(0)));
            ir_if *f0B2B = new(mem_ctx) ir_if(operand(r0B2C).val);
            exec_list *const f0B2B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B2B->then_instructions;

               ir_variable *const r0B2D = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0B2D, neg(r0B19), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B2F = less(r0B2D, body.constant(int(32)));
               ir_if *f0B2E = new(mem_ctx) ir_if(operand(r0B2F).val);
               exec_list *const f0B2E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B2E->then_instructions;

                  ir_expression *const r0B30 = rshift(r0AF8, r0B2D);
                  ir_expression *const r0B31 = neg(r0B2D);
                  ir_expression *const r0B32 = bit_and(r0B31, body.constant(int(31)));
                  ir_expression *const r0B33 = lshift(r0AF8, r0B32);
                  ir_expression *const r0B34 = nequal(r0B33, body.constant(0u));
                  ir_expression *const r0B35 = expr(ir_unop_b2i, r0B34);
                  ir_expression *const r0B36 = expr(ir_unop_i2u, r0B35);
                  body.emit(assign(r0B1A, bit_or(r0B30, r0B36), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0B2E->else_instructions;

                  ir_expression *const r0B37 = nequal(r0B1A, body.constant(0u));
                  ir_expression *const r0B38 = expr(ir_unop_b2i, r0B37);
                  body.emit(assign(r0B1A, expr(ir_unop_i2u, r0B38), 0x01));


               body.instructions = f0B2E_parent_instructions;
               body.emit(f0B2E);

               /* END IF */

               body.emit(assign(r0B19, body.constant(int(0)), 0x01));

               ir_expression *const r0B39 = expr(ir_unop_u2i, r0B1A);
               body.emit(assign(r0B1D, bit_and(r0B39, body.constant(int(127))), 0x01));


            body.instructions = f0B2B_parent_instructions;
            body.emit(f0B2B);

            /* END IF */


         body.instructions = f0B22_parent_instructions;
         body.emit(f0B22);

         /* END IF */


      body.instructions = f0B1F_parent_instructions;
      body.emit(f0B1F);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B3A = new(mem_ctx) ir_if(operand(r0B1B).val);
      exec_list *const f0B3A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B3A->then_instructions;

         ir_expression *const r0B3B = add(r0B1A, body.constant(64u));
         body.emit(assign(r0B1A, rshift(r0B3B, body.constant(int(7))), 0x01));

         ir_expression *const r0B3C = bit_xor(r0B1D, body.constant(int(64)));
         ir_expression *const r0B3D = equal(r0B3C, body.constant(int(0)));
         ir_expression *const r0B3E = expr(ir_unop_b2i, r0B3D);
         ir_expression *const r0B3F = expr(ir_unop_i2u, r0B3E);
         ir_expression *const r0B40 = expr(ir_unop_bit_not, r0B3F);
         body.emit(assign(r0B1A, bit_and(r0B1A, r0B40), 0x01));

         /* IF CONDITION */
         ir_expression *const r0B42 = equal(r0B1A, body.constant(0u));
         ir_if *f0B41 = new(mem_ctx) ir_if(operand(r0B42).val);
         exec_list *const f0B41_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B41->then_instructions;

            body.emit(assign(r0B19, body.constant(int(0)), 0x01));


         body.instructions = f0B41_parent_instructions;
         body.emit(f0B41);

         /* END IF */

         ir_expression *const r0B43 = lshift(r0AFE, body.constant(int(31)));
         ir_expression *const r0B44 = expr(ir_unop_i2u, r0B19);
         ir_expression *const r0B45 = lshift(r0B44, body.constant(int(23)));
         ir_expression *const r0B46 = add(r0B43, r0B45);
         ir_expression *const r0B47 = add(r0B46, r0B1A);
         body.emit(assign(r0B1C, expr(ir_unop_bitcast_u2f, r0B47), 0x01));

         body.emit(assign(r0B1B, body.constant(false), 0x01));


      body.instructions = f0B3A_parent_instructions;
      body.emit(f0B3A);

      /* END IF */

      body.emit(assign(r0AF7, r0B1C, 0x01));


   body.instructions = f0AFF_parent_instructions;
   body.emit(f0AFF);

   /* END IF */

   body.emit(ret(r0AF7));

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

   ir_variable *const r0B48 = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0B48);
   ir_variable *const r0B49 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B49, body.constant(true), 0x01));

   ir_variable *const r0B4A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B4B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B4B);
   ir_variable *const r0B4C = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B4C);
   ir_variable *const r0B4D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B4D);
   ir_variable *const r0B4E = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0B4E, expr(ir_unop_bitcast_f2u, r0B48), 0x01));

   ir_variable *const r0B4F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B4F, bit_and(r0B4E, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B4D, r0B4F, 0x01));

   ir_variable *const r0B50 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B51 = rshift(r0B4E, body.constant(int(23)));
   ir_expression *const r0B52 = bit_and(r0B51, body.constant(255u));
   body.emit(assign(r0B50, expr(ir_unop_u2i, r0B52), 0x01));

   body.emit(assign(r0B4C, r0B50, 0x01));

   body.emit(assign(r0B4B, rshift(r0B4E, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B54 = equal(r0B50, body.constant(int(255)));
   ir_if *f0B53 = new(mem_ctx) ir_if(operand(r0B54).val);
   exec_list *const f0B53_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B53->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B56 = nequal(r0B4F, body.constant(0u));
      ir_if *f0B55 = new(mem_ctx) ir_if(operand(r0B56).val);
      exec_list *const f0B55_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B55->then_instructions;

         ir_variable *const r0B57 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B57, lshift(r0B4E, body.constant(int(9))), 0x01));

         ir_variable *const r0B58 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B59 = lshift(r0B57, body.constant(int(20)));
         body.emit(assign(r0B58, bit_or(r0B59, body.constant(0u)), 0x01));

         ir_expression *const r0B5A = rshift(r0B57, body.constant(int(12)));
         ir_expression *const r0B5B = lshift(r0B4B, body.constant(int(31)));
         ir_expression *const r0B5C = bit_or(r0B5B, body.constant(2146959360u));
         body.emit(assign(r0B58, bit_or(r0B5A, r0B5C), 0x02));

         body.emit(assign(r0B4A, r0B58, 0x03));

         body.emit(assign(r0B49, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B55->else_instructions;

         ir_variable *const r0B5D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B5D);
         ir_expression *const r0B5E = lshift(r0B4B, body.constant(int(31)));
         body.emit(assign(r0B5D, add(r0B5E, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B5D, body.constant(0u), 0x01));

         body.emit(assign(r0B4A, r0B5D, 0x03));

         body.emit(assign(r0B49, body.constant(false), 0x01));


      body.instructions = f0B55_parent_instructions;
      body.emit(f0B55);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B53->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B60 = equal(r0B50, body.constant(int(0)));
      ir_if *f0B5F = new(mem_ctx) ir_if(operand(r0B60).val);
      exec_list *const f0B5F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B5F->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B62 = equal(r0B4F, body.constant(0u));
         ir_if *f0B61 = new(mem_ctx) ir_if(operand(r0B62).val);
         exec_list *const f0B61_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B61->then_instructions;

            ir_variable *const r0B63 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B63);
            body.emit(assign(r0B63, lshift(r0B4B, body.constant(int(31))), 0x02));

            body.emit(assign(r0B63, body.constant(0u), 0x01));

            body.emit(assign(r0B4A, r0B63, 0x03));

            body.emit(assign(r0B49, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B61->else_instructions;

            ir_variable *const r0B64 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0B64, r0B4F, 0x01));

            ir_variable *const r0B65 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0B66 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0B66);
            /* IF CONDITION */
            ir_expression *const r0B68 = equal(r0B4F, body.constant(0u));
            ir_if *f0B67 = new(mem_ctx) ir_if(operand(r0B68).val);
            exec_list *const f0B67_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B67->then_instructions;

               body.emit(assign(r0B65, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0B67->else_instructions;

               body.emit(assign(r0B66, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B6A = bit_and(r0B4F, body.constant(4294901760u));
               ir_expression *const r0B6B = equal(r0B6A, body.constant(0u));
               ir_if *f0B69 = new(mem_ctx) ir_if(operand(r0B6B).val);
               exec_list *const f0B69_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B69->then_instructions;

                  body.emit(assign(r0B66, body.constant(int(16)), 0x01));

                  body.emit(assign(r0B64, lshift(r0B4F, body.constant(int(16))), 0x01));


               body.instructions = f0B69_parent_instructions;
               body.emit(f0B69);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B6D = bit_and(r0B64, body.constant(4278190080u));
               ir_expression *const r0B6E = equal(r0B6D, body.constant(0u));
               ir_if *f0B6C = new(mem_ctx) ir_if(operand(r0B6E).val);
               exec_list *const f0B6C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B6C->then_instructions;

                  body.emit(assign(r0B66, add(r0B66, body.constant(int(8))), 0x01));

                  body.emit(assign(r0B64, lshift(r0B64, body.constant(int(8))), 0x01));


               body.instructions = f0B6C_parent_instructions;
               body.emit(f0B6C);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B70 = bit_and(r0B64, body.constant(4026531840u));
               ir_expression *const r0B71 = equal(r0B70, body.constant(0u));
               ir_if *f0B6F = new(mem_ctx) ir_if(operand(r0B71).val);
               exec_list *const f0B6F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B6F->then_instructions;

                  body.emit(assign(r0B66, add(r0B66, body.constant(int(4))), 0x01));

                  body.emit(assign(r0B64, lshift(r0B64, body.constant(int(4))), 0x01));


               body.instructions = f0B6F_parent_instructions;
               body.emit(f0B6F);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B73 = bit_and(r0B64, body.constant(3221225472u));
               ir_expression *const r0B74 = equal(r0B73, body.constant(0u));
               ir_if *f0B72 = new(mem_ctx) ir_if(operand(r0B74).val);
               exec_list *const f0B72_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B72->then_instructions;

                  body.emit(assign(r0B66, add(r0B66, body.constant(int(2))), 0x01));

                  body.emit(assign(r0B64, lshift(r0B64, body.constant(int(2))), 0x01));


               body.instructions = f0B72_parent_instructions;
               body.emit(f0B72);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B76 = bit_and(r0B64, body.constant(2147483648u));
               ir_expression *const r0B77 = equal(r0B76, body.constant(0u));
               ir_if *f0B75 = new(mem_ctx) ir_if(operand(r0B77).val);
               exec_list *const f0B75_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B75->then_instructions;

                  body.emit(assign(r0B66, add(r0B66, body.constant(int(1))), 0x01));


               body.instructions = f0B75_parent_instructions;
               body.emit(f0B75);

               /* END IF */

               body.emit(assign(r0B65, r0B66, 0x01));


            body.instructions = f0B67_parent_instructions;
            body.emit(f0B67);

            /* END IF */

            ir_variable *const r0B78 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B78, add(r0B65, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B4D, lshift(r0B4F, r0B78), 0x01));

            body.emit(assign(r0B4C, sub(body.constant(int(1)), r0B78), 0x01));

            body.emit(assign(r0B4C, add(r0B4C, body.constant(int(-1))), 0x01));


         body.instructions = f0B61_parent_instructions;
         body.emit(f0B61);

         /* END IF */


      body.instructions = f0B5F_parent_instructions;
      body.emit(f0B5F);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B79 = new(mem_ctx) ir_if(operand(r0B49).val);
      exec_list *const f0B79_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B79->then_instructions;

         ir_variable *const r0B7A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B7A);
         ir_expression *const r0B7B = lshift(r0B4B, body.constant(int(31)));
         ir_expression *const r0B7C = add(r0B4C, body.constant(int(896)));
         ir_expression *const r0B7D = expr(ir_unop_i2u, r0B7C);
         ir_expression *const r0B7E = lshift(r0B7D, body.constant(int(20)));
         ir_expression *const r0B7F = add(r0B7B, r0B7E);
         ir_expression *const r0B80 = rshift(r0B4D, body.constant(int(3)));
         body.emit(assign(r0B7A, add(r0B7F, r0B80), 0x02));

         ir_expression *const r0B81 = lshift(r0B4D, body.constant(int(29)));
         body.emit(assign(r0B7A, bit_or(r0B81, body.constant(0u)), 0x01));

         body.emit(assign(r0B4A, r0B7A, 0x03));

         body.emit(assign(r0B49, body.constant(false), 0x01));


      body.instructions = f0B79_parent_instructions;
      body.emit(f0B79);

      /* END IF */


   body.instructions = f0B53_parent_instructions;
   body.emit(f0B53);

   /* END IF */

   body.emit(ret(r0B4A));

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

   ir_variable *const r0B82 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0B82);
   ir_variable *const r0B83 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0B83);
   ir_variable *const r0B84 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0B84);
   ir_variable *const r0B85 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0B85);
   ir_variable *const r0B86 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0B86);
   ir_variable *const r0B87 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0B87);
   ir_variable *const r0B88 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B88);
   ir_variable *const r0B89 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B89);
   ir_variable *const r0B8A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B8A);
   ir_variable *const r0B8B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0B8B);
   ir_variable *const r0B8C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0B8C);
   ir_variable *const r0B8D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B8D, add(r0B84, r0B87), 0x01));

   ir_variable *const r0B8E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0B8F = less(r0B8D, r0B84);
   ir_expression *const r0B90 = expr(ir_unop_b2i, r0B8F);
   body.emit(assign(r0B8E, expr(ir_unop_i2u, r0B90), 0x01));

   ir_variable *const r0B91 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B91, add(r0B83, r0B86), 0x01));

   body.emit(assign(r0B8C, add(r0B91, r0B8E), 0x01));

   ir_expression *const r0B92 = add(r0B82, r0B85);
   ir_expression *const r0B93 = less(r0B8C, r0B8E);
   ir_expression *const r0B94 = expr(ir_unop_b2i, r0B93);
   ir_expression *const r0B95 = expr(ir_unop_i2u, r0B94);
   body.emit(assign(r0B8B, add(r0B92, r0B95), 0x01));

   ir_expression *const r0B96 = less(r0B91, r0B83);
   ir_expression *const r0B97 = expr(ir_unop_b2i, r0B96);
   ir_expression *const r0B98 = expr(ir_unop_i2u, r0B97);
   body.emit(assign(r0B8B, add(r0B8B, r0B98), 0x01));

   body.emit(assign(r0B8A, r0B8D, 0x01));

   body.emit(assign(r0B89, r0B8C, 0x01));

   body.emit(assign(r0B88, r0B8B, 0x01));

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

   ir_variable *const r0B99 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0B99);
   ir_variable *const r0B9A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0B9A);
   ir_variable *const r0B9B = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0B9B);
   ir_variable *const r0B9C = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0B9C);
   ir_variable *const r0B9D = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0B9D);
   ir_variable *const r0B9E = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0B9E);
   ir_variable *const r0B9F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B9F);
   ir_variable *const r0BA0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BA0);
   ir_variable *const r0BA1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BA1);
   ir_variable *const r0BA2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0BA2);
   ir_variable *const r0BA3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0BA4 = less(r0B9B, r0B9E);
   ir_expression *const r0BA5 = expr(ir_unop_b2i, r0BA4);
   body.emit(assign(r0BA3, expr(ir_unop_i2u, r0BA5), 0x01));

   ir_variable *const r0BA6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BA6, sub(r0B9A, r0B9D), 0x01));

   ir_expression *const r0BA7 = sub(r0B99, r0B9C);
   ir_expression *const r0BA8 = less(r0BA6, r0BA3);
   ir_expression *const r0BA9 = expr(ir_unop_b2i, r0BA8);
   ir_expression *const r0BAA = expr(ir_unop_i2u, r0BA9);
   body.emit(assign(r0BA2, sub(r0BA7, r0BAA), 0x01));

   ir_expression *const r0BAB = less(r0B9A, r0B9D);
   ir_expression *const r0BAC = expr(ir_unop_b2i, r0BAB);
   ir_expression *const r0BAD = expr(ir_unop_i2u, r0BAC);
   body.emit(assign(r0BA2, sub(r0BA2, r0BAD), 0x01));

   body.emit(assign(r0BA1, sub(r0B9B, r0B9E), 0x01));

   body.emit(assign(r0BA0, sub(r0BA6, r0BA3), 0x01));

   body.emit(assign(r0B9F, r0BA2, 0x01));

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

   ir_variable *const r0BAE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BAE);
   ir_variable *const r0BAF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BAF);
   ir_variable *const r0BB0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0BB0);
   ir_variable *const r0BB1 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0BB2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0BB2);
   ir_variable *const r0BB3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0BB3);
   ir_variable *const r0BB4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0BB4);
   ir_variable *const r0BB5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0BB5);
   body.emit(assign(r0BB4, body.constant(0u), 0x01));

   body.emit(assign(r0BB3, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BB7 = gequal(r0BAE, r0BB0);
   ir_if *f0BB6 = new(mem_ctx) ir_if(operand(r0BB7).val);
   exec_list *const f0BB6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BB6->then_instructions;

      body.emit(assign(r0BB1, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BB6->else_instructions;

      body.emit(assign(r0BB5, rshift(r0BB0, body.constant(int(16))), 0x01));

      ir_variable *const r0BB8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BBA = lshift(r0BB5, body.constant(int(16)));
      ir_expression *const r0BBB = gequal(r0BAE, r0BBA);
      ir_if *f0BB9 = new(mem_ctx) ir_if(operand(r0BBB).val);
      exec_list *const f0BB9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BB9->then_instructions;

         body.emit(assign(r0BB8, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BB9->else_instructions;

         ir_expression *const r0BBC = expr(ir_binop_div, r0BAE, r0BB5);
         body.emit(assign(r0BB8, lshift(r0BBC, body.constant(int(16))), 0x01));


      body.instructions = f0BB9_parent_instructions;
      body.emit(f0BB9);

      /* END IF */

      body.emit(assign(r0BB2, r0BB8, 0x01));

      ir_variable *const r0BBD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0BBD);
      ir_variable *const r0BBE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0BBE);
      ir_variable *const r0BBF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BBF);
      ir_variable *const r0BC0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC0, bit_and(r0BB0, body.constant(65535u)), 0x01));

      ir_variable *const r0BC1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC1, rshift(r0BB0, body.constant(int(16))), 0x01));

      ir_variable *const r0BC2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC2, bit_and(r0BB8, body.constant(65535u)), 0x01));

      ir_variable *const r0BC3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC3, rshift(r0BB8, body.constant(int(16))), 0x01));

      ir_variable *const r0BC4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC4, mul(r0BC1, r0BC2), 0x01));

      ir_expression *const r0BC5 = mul(r0BC0, r0BC3);
      body.emit(assign(r0BBE, add(r0BC5, r0BC4), 0x01));

      ir_expression *const r0BC6 = mul(r0BC1, r0BC3);
      ir_expression *const r0BC7 = less(r0BBE, r0BC4);
      ir_expression *const r0BC8 = expr(ir_unop_b2i, r0BC7);
      ir_expression *const r0BC9 = expr(ir_unop_i2u, r0BC8);
      ir_expression *const r0BCA = lshift(r0BC9, body.constant(int(16)));
      ir_expression *const r0BCB = rshift(r0BBE, body.constant(int(16)));
      ir_expression *const r0BCC = add(r0BCA, r0BCB);
      body.emit(assign(r0BBD, add(r0BC6, r0BCC), 0x01));

      body.emit(assign(r0BBE, lshift(r0BBE, body.constant(int(16))), 0x01));

      ir_expression *const r0BCD = mul(r0BC0, r0BC2);
      body.emit(assign(r0BBF, add(r0BCD, r0BBE), 0x01));

      ir_expression *const r0BCE = less(r0BBF, r0BBE);
      ir_expression *const r0BCF = expr(ir_unop_b2i, r0BCE);
      ir_expression *const r0BD0 = expr(ir_unop_i2u, r0BCF);
      body.emit(assign(r0BBD, add(r0BBD, r0BD0), 0x01));

      ir_expression *const r0BD1 = sub(r0BAE, r0BBD);
      ir_expression *const r0BD2 = less(r0BAF, r0BBF);
      ir_expression *const r0BD3 = expr(ir_unop_b2i, r0BD2);
      ir_expression *const r0BD4 = expr(ir_unop_i2u, r0BD3);
      body.emit(assign(r0BB4, sub(r0BD1, r0BD4), 0x01));

      body.emit(assign(r0BB3, sub(r0BAF, r0BBF), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0BD5 = new(mem_ctx) ir_loop();
      exec_list *const f0BD5_parent_instructions = body.instructions;

         body.instructions = &f0BD5->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0BD7 = expr(ir_unop_u2i, r0BB4);
         ir_expression *const r0BD8 = gequal(r0BD7, body.constant(int(0)));
         ir_if *f0BD6 = new(mem_ctx) ir_if(operand(r0BD8).val);
         exec_list *const f0BD6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BD6->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0BD6_parent_instructions;
         body.emit(f0BD6);

         /* END IF */

         body.emit(assign(r0BB2, add(r0BB2, body.constant(4294901760u)), 0x01));

         ir_variable *const r0BD9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0BDA = lshift(r0BB0, body.constant(int(16)));
         body.emit(assign(r0BD9, add(r0BB3, r0BDA), 0x01));

         ir_expression *const r0BDB = add(r0BB4, r0BB5);
         ir_expression *const r0BDC = less(r0BD9, r0BB3);
         ir_expression *const r0BDD = expr(ir_unop_b2i, r0BDC);
         ir_expression *const r0BDE = expr(ir_unop_i2u, r0BDD);
         body.emit(assign(r0BB4, add(r0BDB, r0BDE), 0x01));

         body.emit(assign(r0BB3, r0BD9, 0x01));

      /* LOOP END */

      body.instructions = f0BD5_parent_instructions;
      body.emit(f0BD5);

      ir_expression *const r0BDF = lshift(r0BB4, body.constant(int(16)));
      ir_expression *const r0BE0 = rshift(r0BB3, body.constant(int(16)));
      body.emit(assign(r0BB4, bit_or(r0BDF, r0BE0), 0x01));

      ir_variable *const r0BE1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BE3 = lshift(r0BB5, body.constant(int(16)));
      ir_expression *const r0BE4 = gequal(r0BB4, r0BE3);
      ir_if *f0BE2 = new(mem_ctx) ir_if(operand(r0BE4).val);
      exec_list *const f0BE2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BE2->then_instructions;

         body.emit(assign(r0BE1, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BE2->else_instructions;

         body.emit(assign(r0BE1, expr(ir_binop_div, r0BB4, r0BB5), 0x01));


      body.instructions = f0BE2_parent_instructions;
      body.emit(f0BE2);

      /* END IF */

      body.emit(assign(r0BB2, bit_or(r0BB2, r0BE1), 0x01));

      body.emit(assign(r0BB1, r0BB2, 0x01));


   body.instructions = f0BB6_parent_instructions;
   body.emit(f0BB6);

   /* END IF */

   body.emit(ret(r0BB1));

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

   ir_variable *const r0BE5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BE5);
   ir_variable *const r0BE6 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0BE7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0BE7);
   body.emit(assign(r0BE7, body.constant(0u), 0x01));

   ir_variable *const r0BE8 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0BE8, bit_and(swizzle_y(r0BE5), body.constant(1048575u)), 0x01));

   ir_variable *const r0BE9 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0BEA = rshift(swizzle_y(r0BE5), body.constant(int(20)));
   ir_expression *const r0BEB = bit_and(r0BEA, body.constant(2047u));
   body.emit(assign(r0BE9, expr(ir_unop_u2i, r0BEB), 0x01));

   ir_variable *const r0BEC = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0BEC, rshift(swizzle_y(r0BE5), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BEE = equal(r0BE9, body.constant(int(2047)));
   ir_if *f0BED = new(mem_ctx) ir_if(operand(r0BEE).val);
   exec_list *const f0BED_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BED->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0BF0 = bit_or(r0BE8, swizzle_x(r0BE5));
      ir_expression *const r0BF1 = nequal(r0BF0, body.constant(0u));
      ir_if *f0BEF = new(mem_ctx) ir_if(operand(r0BF1).val);
      exec_list *const f0BEF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BEF->then_instructions;

         ir_variable *const r0BF2 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0BF2, lshift(swizzle_x(r0BE5), body.constant(int(12))), 0x01));

         ir_expression *const r0BF3 = lshift(r0BEC, body.constant(int(31)));
         ir_expression *const r0BF4 = bit_or(r0BF3, body.constant(2143289344u));
         ir_expression *const r0BF5 = lshift(swizzle_y(r0BE5), body.constant(int(12)));
         ir_expression *const r0BF6 = rshift(swizzle_x(r0BE5), body.constant(int(20)));
         ir_expression *const r0BF7 = bit_or(r0BF5, r0BF6);
         ir_expression *const r0BF8 = rshift(r0BF7, body.constant(int(9)));
         ir_expression *const r0BF9 = bit_or(r0BF4, r0BF8);
         body.emit(assign(r0BE6, expr(ir_unop_bitcast_u2f, r0BF9), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BEF->else_instructions;

         ir_expression *const r0BFA = lshift(r0BEC, body.constant(int(31)));
         ir_expression *const r0BFB = add(r0BFA, body.constant(2139095040u));
         body.emit(assign(r0BE6, expr(ir_unop_bitcast_u2f, r0BFB), 0x01));


      body.instructions = f0BEF_parent_instructions;
      body.emit(f0BEF);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BED->else_instructions;

      ir_variable *const r0BFC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BFC);
      ir_variable *const r0BFD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0BFD);
      ir_expression *const r0BFE = lshift(r0BE8, body.constant(int(10)));
      ir_expression *const r0BFF = rshift(swizzle_x(r0BE5), body.constant(int(22)));
      ir_expression *const r0C00 = bit_or(r0BFE, r0BFF);
      ir_expression *const r0C01 = lshift(swizzle_x(r0BE5), body.constant(int(10)));
      ir_expression *const r0C02 = nequal(r0C01, body.constant(0u));
      ir_expression *const r0C03 = expr(ir_unop_b2i, r0C02);
      ir_expression *const r0C04 = expr(ir_unop_i2u, r0C03);
      body.emit(assign(r0BFC, bit_or(r0C00, r0C04), 0x01));

      body.emit(assign(r0BFD, rshift(r0BE8, body.constant(int(22))), 0x01));

      body.emit(assign(r0BE7, r0BFC, 0x01));

      /* IF CONDITION */
      ir_expression *const r0C06 = nequal(r0BE9, body.constant(int(0)));
      ir_if *f0C05 = new(mem_ctx) ir_if(operand(r0C06).val);
      exec_list *const f0C05_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C05->then_instructions;

         body.emit(assign(r0BE7, bit_or(r0BFC, body.constant(1073741824u)), 0x01));


      body.instructions = f0C05_parent_instructions;
      body.emit(f0C05);

      /* END IF */

      ir_variable *const r0C07 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0C07, add(r0BE9, body.constant(int(-897))), 0x01));

      ir_variable *const r0C08 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0C08, r0BE7, 0x01));

      ir_variable *const r0C09 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0C09, body.constant(true), 0x01));

      ir_variable *const r0C0A = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0C0B = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0C0B);
      ir_expression *const r0C0C = bit_and(r0BE7, body.constant(127u));
      body.emit(assign(r0C0B, expr(ir_unop_u2i, r0C0C), 0x01));

      /* IF CONDITION */
      ir_expression *const r0C0E = expr(ir_unop_i2u, r0C07);
      ir_expression *const r0C0F = gequal(r0C0E, body.constant(253u));
      ir_if *f0C0D = new(mem_ctx) ir_if(operand(r0C0F).val);
      exec_list *const f0C0D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C0D->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C11 = less(body.constant(int(253)), r0C07);
         ir_expression *const r0C12 = equal(r0C07, body.constant(int(253)));
         ir_expression *const r0C13 = expr(ir_unop_u2i, r0BE7);
         ir_expression *const r0C14 = less(r0C13, body.constant(int(-64)));
         ir_expression *const r0C15 = logic_and(r0C12, r0C14);
         ir_expression *const r0C16 = logic_or(r0C11, r0C15);
         ir_if *f0C10 = new(mem_ctx) ir_if(operand(r0C16).val);
         exec_list *const f0C10_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C10->then_instructions;

            ir_expression *const r0C17 = lshift(r0BEC, body.constant(int(31)));
            ir_expression *const r0C18 = add(r0C17, body.constant(2139095040u));
            body.emit(assign(r0C0A, expr(ir_unop_bitcast_u2f, r0C18), 0x01));

            body.emit(assign(r0C09, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C10->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0C1A = less(r0C07, body.constant(int(0)));
            ir_if *f0C19 = new(mem_ctx) ir_if(operand(r0C1A).val);
            exec_list *const f0C19_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C19->then_instructions;

               ir_variable *const r0C1B = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0C1B, neg(r0C07), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C1D = less(r0C1B, body.constant(int(32)));
               ir_if *f0C1C = new(mem_ctx) ir_if(operand(r0C1D).val);
               exec_list *const f0C1C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C1C->then_instructions;

                  ir_expression *const r0C1E = rshift(r0BE7, r0C1B);
                  ir_expression *const r0C1F = neg(r0C1B);
                  ir_expression *const r0C20 = bit_and(r0C1F, body.constant(int(31)));
                  ir_expression *const r0C21 = lshift(r0BE7, r0C20);
                  ir_expression *const r0C22 = nequal(r0C21, body.constant(0u));
                  ir_expression *const r0C23 = expr(ir_unop_b2i, r0C22);
                  ir_expression *const r0C24 = expr(ir_unop_i2u, r0C23);
                  body.emit(assign(r0C08, bit_or(r0C1E, r0C24), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0C1C->else_instructions;

                  ir_expression *const r0C25 = nequal(r0C08, body.constant(0u));
                  ir_expression *const r0C26 = expr(ir_unop_b2i, r0C25);
                  body.emit(assign(r0C08, expr(ir_unop_i2u, r0C26), 0x01));


               body.instructions = f0C1C_parent_instructions;
               body.emit(f0C1C);

               /* END IF */

               body.emit(assign(r0C07, body.constant(int(0)), 0x01));

               ir_expression *const r0C27 = expr(ir_unop_u2i, r0C08);
               body.emit(assign(r0C0B, bit_and(r0C27, body.constant(int(127))), 0x01));


            body.instructions = f0C19_parent_instructions;
            body.emit(f0C19);

            /* END IF */


         body.instructions = f0C10_parent_instructions;
         body.emit(f0C10);

         /* END IF */


      body.instructions = f0C0D_parent_instructions;
      body.emit(f0C0D);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C28 = new(mem_ctx) ir_if(operand(r0C09).val);
      exec_list *const f0C28_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C28->then_instructions;

         ir_expression *const r0C29 = add(r0C08, body.constant(64u));
         body.emit(assign(r0C08, rshift(r0C29, body.constant(int(7))), 0x01));

         ir_expression *const r0C2A = bit_xor(r0C0B, body.constant(int(64)));
         ir_expression *const r0C2B = equal(r0C2A, body.constant(int(0)));
         ir_expression *const r0C2C = expr(ir_unop_b2i, r0C2B);
         ir_expression *const r0C2D = expr(ir_unop_i2u, r0C2C);
         ir_expression *const r0C2E = expr(ir_unop_bit_not, r0C2D);
         body.emit(assign(r0C08, bit_and(r0C08, r0C2E), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C30 = equal(r0C08, body.constant(0u));
         ir_if *f0C2F = new(mem_ctx) ir_if(operand(r0C30).val);
         exec_list *const f0C2F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C2F->then_instructions;

            body.emit(assign(r0C07, body.constant(int(0)), 0x01));


         body.instructions = f0C2F_parent_instructions;
         body.emit(f0C2F);

         /* END IF */

         ir_expression *const r0C31 = lshift(r0BEC, body.constant(int(31)));
         ir_expression *const r0C32 = expr(ir_unop_i2u, r0C07);
         ir_expression *const r0C33 = lshift(r0C32, body.constant(int(23)));
         ir_expression *const r0C34 = add(r0C31, r0C33);
         ir_expression *const r0C35 = add(r0C34, r0C08);
         body.emit(assign(r0C0A, expr(ir_unop_bitcast_u2f, r0C35), 0x01));

         body.emit(assign(r0C09, body.constant(false), 0x01));


      body.instructions = f0C28_parent_instructions;
      body.emit(f0C28);

      /* END IF */

      body.emit(assign(r0BE6, r0C0A, 0x01));


   body.instructions = f0BED_parent_instructions;
   body.emit(f0BED);

   /* END IF */

   ir_variable *const r0C36 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C36, body.constant(true), 0x01));

   ir_variable *const r0C37 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C38 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C38);
   ir_variable *const r0C39 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C39);
   ir_variable *const r0C3A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C3A);
   ir_variable *const r0C3B = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C3C = expr(ir_unop_sqrt, r0BE6);
   body.emit(assign(r0C3B, expr(ir_unop_bitcast_f2u, r0C3C), 0x01));

   ir_variable *const r0C3D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C3D, bit_and(r0C3B, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C3A, r0C3D, 0x01));

   ir_variable *const r0C3E = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C3F = rshift(r0C3B, body.constant(int(23)));
   ir_expression *const r0C40 = bit_and(r0C3F, body.constant(255u));
   body.emit(assign(r0C3E, expr(ir_unop_u2i, r0C40), 0x01));

   body.emit(assign(r0C39, r0C3E, 0x01));

   body.emit(assign(r0C38, rshift(r0C3B, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C42 = equal(r0C3E, body.constant(int(255)));
   ir_if *f0C41 = new(mem_ctx) ir_if(operand(r0C42).val);
   exec_list *const f0C41_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C41->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C44 = nequal(r0C3D, body.constant(0u));
      ir_if *f0C43 = new(mem_ctx) ir_if(operand(r0C44).val);
      exec_list *const f0C43_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C43->then_instructions;

         ir_variable *const r0C45 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C45, lshift(r0C3B, body.constant(int(9))), 0x01));

         ir_variable *const r0C46 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C47 = lshift(r0C45, body.constant(int(20)));
         body.emit(assign(r0C46, bit_or(r0C47, body.constant(0u)), 0x01));

         ir_expression *const r0C48 = rshift(r0C45, body.constant(int(12)));
         ir_expression *const r0C49 = lshift(r0C38, body.constant(int(31)));
         ir_expression *const r0C4A = bit_or(r0C49, body.constant(2146959360u));
         body.emit(assign(r0C46, bit_or(r0C48, r0C4A), 0x02));

         body.emit(assign(r0C37, r0C46, 0x03));

         body.emit(assign(r0C36, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C43->else_instructions;

         ir_variable *const r0C4B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C4B);
         ir_expression *const r0C4C = lshift(r0C38, body.constant(int(31)));
         body.emit(assign(r0C4B, add(r0C4C, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C4B, body.constant(0u), 0x01));

         body.emit(assign(r0C37, r0C4B, 0x03));

         body.emit(assign(r0C36, body.constant(false), 0x01));


      body.instructions = f0C43_parent_instructions;
      body.emit(f0C43);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C41->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C4E = equal(r0C3E, body.constant(int(0)));
      ir_if *f0C4D = new(mem_ctx) ir_if(operand(r0C4E).val);
      exec_list *const f0C4D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C4D->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C50 = equal(r0C3D, body.constant(0u));
         ir_if *f0C4F = new(mem_ctx) ir_if(operand(r0C50).val);
         exec_list *const f0C4F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C4F->then_instructions;

            ir_variable *const r0C51 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C51);
            body.emit(assign(r0C51, lshift(r0C38, body.constant(int(31))), 0x02));

            body.emit(assign(r0C51, body.constant(0u), 0x01));

            body.emit(assign(r0C37, r0C51, 0x03));

            body.emit(assign(r0C36, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C4F->else_instructions;

            ir_variable *const r0C52 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0C52, r0C3D, 0x01));

            ir_variable *const r0C53 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0C54 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0C54);
            /* IF CONDITION */
            ir_expression *const r0C56 = equal(r0C3D, body.constant(0u));
            ir_if *f0C55 = new(mem_ctx) ir_if(operand(r0C56).val);
            exec_list *const f0C55_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C55->then_instructions;

               body.emit(assign(r0C53, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0C55->else_instructions;

               body.emit(assign(r0C54, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C58 = bit_and(r0C3D, body.constant(4294901760u));
               ir_expression *const r0C59 = equal(r0C58, body.constant(0u));
               ir_if *f0C57 = new(mem_ctx) ir_if(operand(r0C59).val);
               exec_list *const f0C57_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C57->then_instructions;

                  body.emit(assign(r0C54, body.constant(int(16)), 0x01));

                  body.emit(assign(r0C52, lshift(r0C3D, body.constant(int(16))), 0x01));


               body.instructions = f0C57_parent_instructions;
               body.emit(f0C57);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C5B = bit_and(r0C52, body.constant(4278190080u));
               ir_expression *const r0C5C = equal(r0C5B, body.constant(0u));
               ir_if *f0C5A = new(mem_ctx) ir_if(operand(r0C5C).val);
               exec_list *const f0C5A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C5A->then_instructions;

                  body.emit(assign(r0C54, add(r0C54, body.constant(int(8))), 0x01));

                  body.emit(assign(r0C52, lshift(r0C52, body.constant(int(8))), 0x01));


               body.instructions = f0C5A_parent_instructions;
               body.emit(f0C5A);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C5E = bit_and(r0C52, body.constant(4026531840u));
               ir_expression *const r0C5F = equal(r0C5E, body.constant(0u));
               ir_if *f0C5D = new(mem_ctx) ir_if(operand(r0C5F).val);
               exec_list *const f0C5D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C5D->then_instructions;

                  body.emit(assign(r0C54, add(r0C54, body.constant(int(4))), 0x01));

                  body.emit(assign(r0C52, lshift(r0C52, body.constant(int(4))), 0x01));


               body.instructions = f0C5D_parent_instructions;
               body.emit(f0C5D);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C61 = bit_and(r0C52, body.constant(3221225472u));
               ir_expression *const r0C62 = equal(r0C61, body.constant(0u));
               ir_if *f0C60 = new(mem_ctx) ir_if(operand(r0C62).val);
               exec_list *const f0C60_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C60->then_instructions;

                  body.emit(assign(r0C54, add(r0C54, body.constant(int(2))), 0x01));

                  body.emit(assign(r0C52, lshift(r0C52, body.constant(int(2))), 0x01));


               body.instructions = f0C60_parent_instructions;
               body.emit(f0C60);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C64 = bit_and(r0C52, body.constant(2147483648u));
               ir_expression *const r0C65 = equal(r0C64, body.constant(0u));
               ir_if *f0C63 = new(mem_ctx) ir_if(operand(r0C65).val);
               exec_list *const f0C63_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C63->then_instructions;

                  body.emit(assign(r0C54, add(r0C54, body.constant(int(1))), 0x01));


               body.instructions = f0C63_parent_instructions;
               body.emit(f0C63);

               /* END IF */

               body.emit(assign(r0C53, r0C54, 0x01));


            body.instructions = f0C55_parent_instructions;
            body.emit(f0C55);

            /* END IF */

            ir_variable *const r0C66 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0C66, add(r0C53, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C3A, lshift(r0C3D, r0C66), 0x01));

            body.emit(assign(r0C39, sub(body.constant(int(1)), r0C66), 0x01));

            body.emit(assign(r0C39, add(r0C39, body.constant(int(-1))), 0x01));


         body.instructions = f0C4F_parent_instructions;
         body.emit(f0C4F);

         /* END IF */


      body.instructions = f0C4D_parent_instructions;
      body.emit(f0C4D);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C67 = new(mem_ctx) ir_if(operand(r0C36).val);
      exec_list *const f0C67_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C67->then_instructions;

         ir_variable *const r0C68 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C68);
         ir_expression *const r0C69 = lshift(r0C38, body.constant(int(31)));
         ir_expression *const r0C6A = add(r0C39, body.constant(int(896)));
         ir_expression *const r0C6B = expr(ir_unop_i2u, r0C6A);
         ir_expression *const r0C6C = lshift(r0C6B, body.constant(int(20)));
         ir_expression *const r0C6D = add(r0C69, r0C6C);
         ir_expression *const r0C6E = rshift(r0C3A, body.constant(int(3)));
         body.emit(assign(r0C68, add(r0C6D, r0C6E), 0x02));

         ir_expression *const r0C6F = lshift(r0C3A, body.constant(int(29)));
         body.emit(assign(r0C68, bit_or(r0C6F, body.constant(0u)), 0x01));

         body.emit(assign(r0C37, r0C68, 0x03));

         body.emit(assign(r0C36, body.constant(false), 0x01));


      body.instructions = f0C67_parent_instructions;
      body.emit(f0C67);

      /* END IF */


   body.instructions = f0C41_parent_instructions;
   body.emit(f0C41);

   /* END IF */

   body.emit(ret(r0C37));

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

   ir_variable *const r0C70 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C70);
   ir_variable *const r0C71 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C72 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C73 = rshift(swizzle_y(r0C70), body.constant(int(20)));
   ir_expression *const r0C74 = bit_and(r0C73, body.constant(2047u));
   ir_expression *const r0C75 = expr(ir_unop_u2i, r0C74);
   body.emit(assign(r0C72, add(r0C75, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C77 = less(r0C72, body.constant(int(0)));
   ir_if *f0C76 = new(mem_ctx) ir_if(operand(r0C77).val);
   exec_list *const f0C76_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C76->then_instructions;

      body.emit(assign(r0C71, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C76->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C79 = less(body.constant(int(52)), r0C72);
      ir_if *f0C78 = new(mem_ctx) ir_if(operand(r0C79).val);
      exec_list *const f0C78_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C78->then_instructions;

         body.emit(assign(r0C71, r0C70, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C78->else_instructions;

         ir_variable *const r0C7A = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0C7A, sub(body.constant(int(52)), r0C72), 0x01));

         ir_variable *const r0C7B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0C7D = gequal(r0C7A, body.constant(int(32)));
         ir_if *f0C7C = new(mem_ctx) ir_if(operand(r0C7D).val);
         exec_list *const f0C7C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C7C->then_instructions;

            body.emit(assign(r0C7B, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C7C->else_instructions;

            body.emit(assign(r0C7B, lshift(body.constant(4294967295u), r0C7A), 0x01));


         body.instructions = f0C7C_parent_instructions;
         body.emit(f0C7C);

         /* END IF */

         ir_variable *const r0C7E = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0C80 = less(r0C7A, body.constant(int(33)));
         ir_if *f0C7F = new(mem_ctx) ir_if(operand(r0C80).val);
         exec_list *const f0C7F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C7F->then_instructions;

            body.emit(assign(r0C7E, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C7F->else_instructions;

            ir_expression *const r0C81 = add(r0C7A, body.constant(int(-32)));
            body.emit(assign(r0C7E, lshift(body.constant(4294967295u), r0C81), 0x01));


         body.instructions = f0C7F_parent_instructions;
         body.emit(f0C7F);

         /* END IF */

         ir_variable *const r0C82 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0C82, bit_and(r0C7B, swizzle_x(r0C70)), 0x01));

         body.emit(assign(r0C82, bit_and(r0C7E, swizzle_y(r0C70)), 0x02));

         body.emit(assign(r0C71, r0C82, 0x03));


      body.instructions = f0C78_parent_instructions;
      body.emit(f0C78);

      /* END IF */


   body.instructions = f0C76_parent_instructions;
   body.emit(f0C76);

   /* END IF */

   body.emit(ret(r0C71));

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

   ir_variable *const r0C83 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C83);
   ir_variable *const r0C84 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C84, body.constant(true), 0x01));

   ir_variable *const r0C85 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C86 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0C86);
   ir_variable *const r0C87 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0C87);
   ir_variable *const r0C88 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C89 = rshift(swizzle_y(r0C83), body.constant(int(20)));
   ir_expression *const r0C8A = bit_and(r0C89, body.constant(2047u));
   ir_expression *const r0C8B = expr(ir_unop_u2i, r0C8A);
   body.emit(assign(r0C88, add(r0C8B, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0C87, swizzle_y(r0C83), 0x01));

   body.emit(assign(r0C86, swizzle_x(r0C83), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C8D = less(r0C88, body.constant(int(20)));
   ir_if *f0C8C = new(mem_ctx) ir_if(operand(r0C8D).val);
   exec_list *const f0C8C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C8C->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C8F = less(r0C88, body.constant(int(0)));
      ir_if *f0C8E = new(mem_ctx) ir_if(operand(r0C8F).val);
      exec_list *const f0C8E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C8E->then_instructions;

         body.emit(assign(r0C87, bit_and(swizzle_y(r0C83), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C91 = equal(r0C88, body.constant(int(-1)));
         ir_expression *const r0C92 = nequal(swizzle_x(r0C83), body.constant(0u));
         ir_expression *const r0C93 = logic_and(r0C91, r0C92);
         ir_if *f0C90 = new(mem_ctx) ir_if(operand(r0C93).val);
         exec_list *const f0C90_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C90->then_instructions;

            body.emit(assign(r0C87, bit_or(r0C87, body.constant(1072693248u)), 0x01));


         body.instructions = f0C90_parent_instructions;
         body.emit(f0C90);

         /* END IF */

         body.emit(assign(r0C86, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C8E->else_instructions;

         ir_variable *const r0C94 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C94, rshift(body.constant(1048575u), r0C88), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C96 = bit_and(r0C87, r0C94);
         ir_expression *const r0C97 = equal(r0C96, body.constant(0u));
         ir_expression *const r0C98 = equal(r0C86, body.constant(0u));
         ir_expression *const r0C99 = logic_and(r0C97, r0C98);
         ir_if *f0C95 = new(mem_ctx) ir_if(operand(r0C99).val);
         exec_list *const f0C95_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C95->then_instructions;

            body.emit(assign(r0C85, r0C83, 0x03));

            body.emit(assign(r0C84, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C95->else_instructions;

            ir_expression *const r0C9A = rshift(body.constant(524288u), r0C88);
            body.emit(assign(r0C87, add(r0C87, r0C9A), 0x01));

            ir_expression *const r0C9B = expr(ir_unop_bit_not, r0C94);
            body.emit(assign(r0C87, bit_and(r0C87, r0C9B), 0x01));

            body.emit(assign(r0C86, body.constant(0u), 0x01));


         body.instructions = f0C95_parent_instructions;
         body.emit(f0C95);

         /* END IF */


      body.instructions = f0C8E_parent_instructions;
      body.emit(f0C8E);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C8C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C9D = less(body.constant(int(51)), r0C88);
      ir_expression *const r0C9E = equal(r0C88, body.constant(int(1024)));
      ir_expression *const r0C9F = logic_or(r0C9D, r0C9E);
      ir_if *f0C9C = new(mem_ctx) ir_if(operand(r0C9F).val);
      exec_list *const f0C9C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C9C->then_instructions;

         body.emit(assign(r0C85, r0C83, 0x03));

         body.emit(assign(r0C84, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C9C->else_instructions;

         ir_variable *const r0CA0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0CA1 = add(r0C88, body.constant(int(-20)));
         body.emit(assign(r0CA0, rshift(body.constant(4294967295u), r0CA1), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CA3 = bit_and(r0C86, r0CA0);
         ir_expression *const r0CA4 = equal(r0CA3, body.constant(0u));
         ir_if *f0CA2 = new(mem_ctx) ir_if(operand(r0CA4).val);
         exec_list *const f0CA2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CA2->then_instructions;

            body.emit(assign(r0C85, r0C83, 0x03));

            body.emit(assign(r0C84, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CA2->else_instructions;

            ir_variable *const r0CA5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0CA6 = sub(body.constant(int(51)), r0C88);
            ir_expression *const r0CA7 = lshift(body.constant(1u), r0CA6);
            body.emit(assign(r0CA5, add(r0C86, r0CA7), 0x01));

            /* IF CONDITION */
            ir_expression *const r0CA9 = less(r0CA5, r0C86);
            ir_if *f0CA8 = new(mem_ctx) ir_if(operand(r0CA9).val);
            exec_list *const f0CA8_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0CA8->then_instructions;

               body.emit(assign(r0C87, add(r0C87, body.constant(1u)), 0x01));


            body.instructions = f0CA8_parent_instructions;
            body.emit(f0CA8);

            /* END IF */

            ir_expression *const r0CAA = expr(ir_unop_bit_not, r0CA0);
            body.emit(assign(r0C86, bit_and(r0CA5, r0CAA), 0x01));


         body.instructions = f0CA2_parent_instructions;
         body.emit(f0CA2);

         /* END IF */


      body.instructions = f0C9C_parent_instructions;
      body.emit(f0C9C);

      /* END IF */


   body.instructions = f0C8C_parent_instructions;
   body.emit(f0C8C);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0CAB = new(mem_ctx) ir_if(operand(r0C84).val);
   exec_list *const f0CAB_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CAB->then_instructions;

      body.emit(assign(r0C83, r0C86, 0x01));

      body.emit(assign(r0C83, r0C87, 0x02));

      body.emit(assign(r0C85, r0C83, 0x03));

      body.emit(assign(r0C84, body.constant(false), 0x01));


   body.instructions = f0CAB_parent_instructions;
   body.emit(f0CAB);

   /* END IF */

   body.emit(ret(r0C85));

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

   ir_variable *const r0CAC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CAC);
   ir_variable *const r0CAD = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0CAE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0CAE);
   body.emit(assign(r0CAE, body.constant(0u), 0x01));

   ir_variable *const r0CAF = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0CAF, bit_and(swizzle_y(r0CAC), body.constant(1048575u)), 0x01));

   ir_variable *const r0CB0 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0CB1 = rshift(swizzle_y(r0CAC), body.constant(int(20)));
   ir_expression *const r0CB2 = bit_and(r0CB1, body.constant(2047u));
   body.emit(assign(r0CB0, expr(ir_unop_u2i, r0CB2), 0x01));

   ir_variable *const r0CB3 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0CB3, rshift(swizzle_y(r0CAC), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CB5 = equal(r0CB0, body.constant(int(2047)));
   ir_if *f0CB4 = new(mem_ctx) ir_if(operand(r0CB5).val);
   exec_list *const f0CB4_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CB4->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CB7 = bit_or(r0CAF, swizzle_x(r0CAC));
      ir_expression *const r0CB8 = nequal(r0CB7, body.constant(0u));
      ir_if *f0CB6 = new(mem_ctx) ir_if(operand(r0CB8).val);
      exec_list *const f0CB6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CB6->then_instructions;

         ir_variable *const r0CB9 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0CB9, lshift(swizzle_x(r0CAC), body.constant(int(12))), 0x01));

         ir_expression *const r0CBA = lshift(r0CB3, body.constant(int(31)));
         ir_expression *const r0CBB = bit_or(r0CBA, body.constant(2143289344u));
         ir_expression *const r0CBC = lshift(swizzle_y(r0CAC), body.constant(int(12)));
         ir_expression *const r0CBD = rshift(swizzle_x(r0CAC), body.constant(int(20)));
         ir_expression *const r0CBE = bit_or(r0CBC, r0CBD);
         ir_expression *const r0CBF = rshift(r0CBE, body.constant(int(9)));
         ir_expression *const r0CC0 = bit_or(r0CBB, r0CBF);
         body.emit(assign(r0CAD, expr(ir_unop_bitcast_u2f, r0CC0), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CB6->else_instructions;

         ir_expression *const r0CC1 = lshift(r0CB3, body.constant(int(31)));
         ir_expression *const r0CC2 = add(r0CC1, body.constant(2139095040u));
         body.emit(assign(r0CAD, expr(ir_unop_bitcast_u2f, r0CC2), 0x01));


      body.instructions = f0CB6_parent_instructions;
      body.emit(f0CB6);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CB4->else_instructions;

      ir_variable *const r0CC3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0CC3);
      ir_variable *const r0CC4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0CC4);
      ir_expression *const r0CC5 = lshift(r0CAF, body.constant(int(10)));
      ir_expression *const r0CC6 = rshift(swizzle_x(r0CAC), body.constant(int(22)));
      ir_expression *const r0CC7 = bit_or(r0CC5, r0CC6);
      ir_expression *const r0CC8 = lshift(swizzle_x(r0CAC), body.constant(int(10)));
      ir_expression *const r0CC9 = nequal(r0CC8, body.constant(0u));
      ir_expression *const r0CCA = expr(ir_unop_b2i, r0CC9);
      ir_expression *const r0CCB = expr(ir_unop_i2u, r0CCA);
      body.emit(assign(r0CC3, bit_or(r0CC7, r0CCB), 0x01));

      body.emit(assign(r0CC4, rshift(r0CAF, body.constant(int(22))), 0x01));

      body.emit(assign(r0CAE, r0CC3, 0x01));

      /* IF CONDITION */
      ir_expression *const r0CCD = nequal(r0CB0, body.constant(int(0)));
      ir_if *f0CCC = new(mem_ctx) ir_if(operand(r0CCD).val);
      exec_list *const f0CCC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CCC->then_instructions;

         body.emit(assign(r0CAE, bit_or(r0CC3, body.constant(1073741824u)), 0x01));


      body.instructions = f0CCC_parent_instructions;
      body.emit(f0CCC);

      /* END IF */

      ir_variable *const r0CCE = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0CCE, add(r0CB0, body.constant(int(-897))), 0x01));

      ir_variable *const r0CCF = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0CCF, r0CAE, 0x01));

      ir_variable *const r0CD0 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0CD0, body.constant(true), 0x01));

      ir_variable *const r0CD1 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0CD2 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0CD2);
      ir_expression *const r0CD3 = bit_and(r0CAE, body.constant(127u));
      body.emit(assign(r0CD2, expr(ir_unop_u2i, r0CD3), 0x01));

      /* IF CONDITION */
      ir_expression *const r0CD5 = expr(ir_unop_i2u, r0CCE);
      ir_expression *const r0CD6 = gequal(r0CD5, body.constant(253u));
      ir_if *f0CD4 = new(mem_ctx) ir_if(operand(r0CD6).val);
      exec_list *const f0CD4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CD4->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0CD8 = less(body.constant(int(253)), r0CCE);
         ir_expression *const r0CD9 = equal(r0CCE, body.constant(int(253)));
         ir_expression *const r0CDA = expr(ir_unop_u2i, r0CAE);
         ir_expression *const r0CDB = less(r0CDA, body.constant(int(-64)));
         ir_expression *const r0CDC = logic_and(r0CD9, r0CDB);
         ir_expression *const r0CDD = logic_or(r0CD8, r0CDC);
         ir_if *f0CD7 = new(mem_ctx) ir_if(operand(r0CDD).val);
         exec_list *const f0CD7_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CD7->then_instructions;

            ir_expression *const r0CDE = lshift(r0CB3, body.constant(int(31)));
            ir_expression *const r0CDF = add(r0CDE, body.constant(2139095040u));
            body.emit(assign(r0CD1, expr(ir_unop_bitcast_u2f, r0CDF), 0x01));

            body.emit(assign(r0CD0, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CD7->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0CE1 = less(r0CCE, body.constant(int(0)));
            ir_if *f0CE0 = new(mem_ctx) ir_if(operand(r0CE1).val);
            exec_list *const f0CE0_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0CE0->then_instructions;

               ir_variable *const r0CE2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0CE2, neg(r0CCE), 0x01));

               /* IF CONDITION */
               ir_expression *const r0CE4 = less(r0CE2, body.constant(int(32)));
               ir_if *f0CE3 = new(mem_ctx) ir_if(operand(r0CE4).val);
               exec_list *const f0CE3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0CE3->then_instructions;

                  ir_expression *const r0CE5 = rshift(r0CAE, r0CE2);
                  ir_expression *const r0CE6 = neg(r0CE2);
                  ir_expression *const r0CE7 = bit_and(r0CE6, body.constant(int(31)));
                  ir_expression *const r0CE8 = lshift(r0CAE, r0CE7);
                  ir_expression *const r0CE9 = nequal(r0CE8, body.constant(0u));
                  ir_expression *const r0CEA = expr(ir_unop_b2i, r0CE9);
                  ir_expression *const r0CEB = expr(ir_unop_i2u, r0CEA);
                  body.emit(assign(r0CCF, bit_or(r0CE5, r0CEB), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0CE3->else_instructions;

                  ir_expression *const r0CEC = nequal(r0CCF, body.constant(0u));
                  ir_expression *const r0CED = expr(ir_unop_b2i, r0CEC);
                  body.emit(assign(r0CCF, expr(ir_unop_i2u, r0CED), 0x01));


               body.instructions = f0CE3_parent_instructions;
               body.emit(f0CE3);

               /* END IF */

               body.emit(assign(r0CCE, body.constant(int(0)), 0x01));

               ir_expression *const r0CEE = expr(ir_unop_u2i, r0CCF);
               body.emit(assign(r0CD2, bit_and(r0CEE, body.constant(int(127))), 0x01));


            body.instructions = f0CE0_parent_instructions;
            body.emit(f0CE0);

            /* END IF */


         body.instructions = f0CD7_parent_instructions;
         body.emit(f0CD7);

         /* END IF */


      body.instructions = f0CD4_parent_instructions;
      body.emit(f0CD4);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0CEF = new(mem_ctx) ir_if(operand(r0CD0).val);
      exec_list *const f0CEF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CEF->then_instructions;

         ir_expression *const r0CF0 = add(r0CCF, body.constant(64u));
         body.emit(assign(r0CCF, rshift(r0CF0, body.constant(int(7))), 0x01));

         ir_expression *const r0CF1 = bit_xor(r0CD2, body.constant(int(64)));
         ir_expression *const r0CF2 = equal(r0CF1, body.constant(int(0)));
         ir_expression *const r0CF3 = expr(ir_unop_b2i, r0CF2);
         ir_expression *const r0CF4 = expr(ir_unop_i2u, r0CF3);
         ir_expression *const r0CF5 = expr(ir_unop_bit_not, r0CF4);
         body.emit(assign(r0CCF, bit_and(r0CCF, r0CF5), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CF7 = equal(r0CCF, body.constant(0u));
         ir_if *f0CF6 = new(mem_ctx) ir_if(operand(r0CF7).val);
         exec_list *const f0CF6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CF6->then_instructions;

            body.emit(assign(r0CCE, body.constant(int(0)), 0x01));


         body.instructions = f0CF6_parent_instructions;
         body.emit(f0CF6);

         /* END IF */

         ir_expression *const r0CF8 = lshift(r0CB3, body.constant(int(31)));
         ir_expression *const r0CF9 = expr(ir_unop_i2u, r0CCE);
         ir_expression *const r0CFA = lshift(r0CF9, body.constant(int(23)));
         ir_expression *const r0CFB = add(r0CF8, r0CFA);
         ir_expression *const r0CFC = add(r0CFB, r0CCF);
         body.emit(assign(r0CD1, expr(ir_unop_bitcast_u2f, r0CFC), 0x01));

         body.emit(assign(r0CD0, body.constant(false), 0x01));


      body.instructions = f0CEF_parent_instructions;
      body.emit(f0CEF);

      /* END IF */

      body.emit(assign(r0CAD, r0CD1, 0x01));


   body.instructions = f0CB4_parent_instructions;
   body.emit(f0CB4);

   /* END IF */

   ir_variable *const r0CFD = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0CFD, body.constant(true), 0x01));

   ir_variable *const r0CFE = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CFF = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0CFF);
   ir_variable *const r0D00 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0D00);
   ir_variable *const r0D01 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0D01);
   ir_variable *const r0D02 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0D03 = expr(ir_unop_rcp, r0CAD);
   body.emit(assign(r0D02, expr(ir_unop_bitcast_f2u, r0D03), 0x01));

   ir_variable *const r0D04 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0D04, bit_and(r0D02, body.constant(8388607u)), 0x01));

   body.emit(assign(r0D01, r0D04, 0x01));

   ir_variable *const r0D05 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0D06 = rshift(r0D02, body.constant(int(23)));
   ir_expression *const r0D07 = bit_and(r0D06, body.constant(255u));
   body.emit(assign(r0D05, expr(ir_unop_u2i, r0D07), 0x01));

   body.emit(assign(r0D00, r0D05, 0x01));

   body.emit(assign(r0CFF, rshift(r0D02, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0D09 = equal(r0D05, body.constant(int(255)));
   ir_if *f0D08 = new(mem_ctx) ir_if(operand(r0D09).val);
   exec_list *const f0D08_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D08->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0D0B = nequal(r0D04, body.constant(0u));
      ir_if *f0D0A = new(mem_ctx) ir_if(operand(r0D0B).val);
      exec_list *const f0D0A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D0A->then_instructions;

         ir_variable *const r0D0C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0D0C, lshift(r0D02, body.constant(int(9))), 0x01));

         ir_variable *const r0D0D = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0D0E = lshift(r0D0C, body.constant(int(20)));
         body.emit(assign(r0D0D, bit_or(r0D0E, body.constant(0u)), 0x01));

         ir_expression *const r0D0F = rshift(r0D0C, body.constant(int(12)));
         ir_expression *const r0D10 = lshift(r0CFF, body.constant(int(31)));
         ir_expression *const r0D11 = bit_or(r0D10, body.constant(2146959360u));
         body.emit(assign(r0D0D, bit_or(r0D0F, r0D11), 0x02));

         body.emit(assign(r0CFE, r0D0D, 0x03));

         body.emit(assign(r0CFD, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D0A->else_instructions;

         ir_variable *const r0D12 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D12);
         ir_expression *const r0D13 = lshift(r0CFF, body.constant(int(31)));
         body.emit(assign(r0D12, add(r0D13, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0D12, body.constant(0u), 0x01));

         body.emit(assign(r0CFE, r0D12, 0x03));

         body.emit(assign(r0CFD, body.constant(false), 0x01));


      body.instructions = f0D0A_parent_instructions;
      body.emit(f0D0A);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0D08->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0D15 = equal(r0D05, body.constant(int(0)));
      ir_if *f0D14 = new(mem_ctx) ir_if(operand(r0D15).val);
      exec_list *const f0D14_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D14->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0D17 = equal(r0D04, body.constant(0u));
         ir_if *f0D16 = new(mem_ctx) ir_if(operand(r0D17).val);
         exec_list *const f0D16_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D16->then_instructions;

            ir_variable *const r0D18 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0D18);
            body.emit(assign(r0D18, lshift(r0CFF, body.constant(int(31))), 0x02));

            body.emit(assign(r0D18, body.constant(0u), 0x01));

            body.emit(assign(r0CFE, r0D18, 0x03));

            body.emit(assign(r0CFD, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D16->else_instructions;

            ir_variable *const r0D19 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0D19, r0D04, 0x01));

            ir_variable *const r0D1A = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0D1B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0D1B);
            /* IF CONDITION */
            ir_expression *const r0D1D = equal(r0D04, body.constant(0u));
            ir_if *f0D1C = new(mem_ctx) ir_if(operand(r0D1D).val);
            exec_list *const f0D1C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D1C->then_instructions;

               body.emit(assign(r0D1A, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0D1C->else_instructions;

               body.emit(assign(r0D1B, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0D1F = bit_and(r0D04, body.constant(4294901760u));
               ir_expression *const r0D20 = equal(r0D1F, body.constant(0u));
               ir_if *f0D1E = new(mem_ctx) ir_if(operand(r0D20).val);
               exec_list *const f0D1E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D1E->then_instructions;

                  body.emit(assign(r0D1B, body.constant(int(16)), 0x01));

                  body.emit(assign(r0D19, lshift(r0D04, body.constant(int(16))), 0x01));


               body.instructions = f0D1E_parent_instructions;
               body.emit(f0D1E);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D22 = bit_and(r0D19, body.constant(4278190080u));
               ir_expression *const r0D23 = equal(r0D22, body.constant(0u));
               ir_if *f0D21 = new(mem_ctx) ir_if(operand(r0D23).val);
               exec_list *const f0D21_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D21->then_instructions;

                  body.emit(assign(r0D1B, add(r0D1B, body.constant(int(8))), 0x01));

                  body.emit(assign(r0D19, lshift(r0D19, body.constant(int(8))), 0x01));


               body.instructions = f0D21_parent_instructions;
               body.emit(f0D21);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D25 = bit_and(r0D19, body.constant(4026531840u));
               ir_expression *const r0D26 = equal(r0D25, body.constant(0u));
               ir_if *f0D24 = new(mem_ctx) ir_if(operand(r0D26).val);
               exec_list *const f0D24_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D24->then_instructions;

                  body.emit(assign(r0D1B, add(r0D1B, body.constant(int(4))), 0x01));

                  body.emit(assign(r0D19, lshift(r0D19, body.constant(int(4))), 0x01));


               body.instructions = f0D24_parent_instructions;
               body.emit(f0D24);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D28 = bit_and(r0D19, body.constant(3221225472u));
               ir_expression *const r0D29 = equal(r0D28, body.constant(0u));
               ir_if *f0D27 = new(mem_ctx) ir_if(operand(r0D29).val);
               exec_list *const f0D27_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D27->then_instructions;

                  body.emit(assign(r0D1B, add(r0D1B, body.constant(int(2))), 0x01));

                  body.emit(assign(r0D19, lshift(r0D19, body.constant(int(2))), 0x01));


               body.instructions = f0D27_parent_instructions;
               body.emit(f0D27);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D2B = bit_and(r0D19, body.constant(2147483648u));
               ir_expression *const r0D2C = equal(r0D2B, body.constant(0u));
               ir_if *f0D2A = new(mem_ctx) ir_if(operand(r0D2C).val);
               exec_list *const f0D2A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D2A->then_instructions;

                  body.emit(assign(r0D1B, add(r0D1B, body.constant(int(1))), 0x01));


               body.instructions = f0D2A_parent_instructions;
               body.emit(f0D2A);

               /* END IF */

               body.emit(assign(r0D1A, r0D1B, 0x01));


            body.instructions = f0D1C_parent_instructions;
            body.emit(f0D1C);

            /* END IF */

            ir_variable *const r0D2D = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0D2D, add(r0D1A, body.constant(int(-8))), 0x01));

            body.emit(assign(r0D01, lshift(r0D04, r0D2D), 0x01));

            body.emit(assign(r0D00, sub(body.constant(int(1)), r0D2D), 0x01));

            body.emit(assign(r0D00, add(r0D00, body.constant(int(-1))), 0x01));


         body.instructions = f0D16_parent_instructions;
         body.emit(f0D16);

         /* END IF */


      body.instructions = f0D14_parent_instructions;
      body.emit(f0D14);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0D2E = new(mem_ctx) ir_if(operand(r0CFD).val);
      exec_list *const f0D2E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D2E->then_instructions;

         ir_variable *const r0D2F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D2F);
         ir_expression *const r0D30 = lshift(r0CFF, body.constant(int(31)));
         ir_expression *const r0D31 = add(r0D00, body.constant(int(896)));
         ir_expression *const r0D32 = expr(ir_unop_i2u, r0D31);
         ir_expression *const r0D33 = lshift(r0D32, body.constant(int(20)));
         ir_expression *const r0D34 = add(r0D30, r0D33);
         ir_expression *const r0D35 = rshift(r0D01, body.constant(int(3)));
         body.emit(assign(r0D2F, add(r0D34, r0D35), 0x02));

         ir_expression *const r0D36 = lshift(r0D01, body.constant(int(29)));
         body.emit(assign(r0D2F, bit_or(r0D36, body.constant(0u)), 0x01));

         body.emit(assign(r0CFE, r0D2F, 0x03));

         body.emit(assign(r0CFD, body.constant(false), 0x01));


      body.instructions = f0D2E_parent_instructions;
      body.emit(f0D2E);

      /* END IF */


   body.instructions = f0D08_parent_instructions;
   body.emit(f0D08);

   /* END IF */

   body.emit(ret(r0CFE));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
