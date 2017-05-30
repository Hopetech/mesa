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
   ir_expression *const r000E = lequal(body.constant(4292870144u), r000D);
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
   ir_variable *const r0015 = body.make_temp(glsl_type::uvec2_type, "return_value");
   /* IF CONDITION */
   ir_expression *const r0017 = lshift(swizzle_y(r0014), body.constant(int(1)));
   ir_expression *const r0018 = lequal(body.constant(4292870144u), r0017);
   ir_expression *const r0019 = nequal(swizzle_x(r0014), body.constant(0u));
   ir_expression *const r001A = bit_and(swizzle_y(r0014), body.constant(1048575u));
   ir_expression *const r001B = nequal(r001A, body.constant(0u));
   ir_expression *const r001C = logic_or(r0019, r001B);
   ir_expression *const r001D = logic_and(r0018, r001C);
   ir_if *f0016 = new(mem_ctx) ir_if(operand(r001D).val);
   exec_list *const f0016_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0016->then_instructions;

      body.emit(assign(r0015, r0014, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0016->else_instructions;

      body.emit(assign(r0014, bit_xor(swizzle_y(r0014), body.constant(2147483648u)), 0x02));

      body.emit(assign(r0015, r0014, 0x03));


   body.instructions = f0016_parent_instructions;
   body.emit(f0016);

   /* END IF */

   body.emit(ret(r0015));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
extractFloat64Frac(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r001E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r001E);
   ir_variable *const r001F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r001F);
   body.emit(assign(r001F, bit_and(swizzle_y(r001E), body.constant(1048575u)), 0x02));

   body.emit(assign(r001F, swizzle_x(r001E), 0x01));

   body.emit(ret(r001F));

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

   ir_variable *const r0020 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0020);
   ir_expression *const r0021 = rshift(swizzle_y(r0020), body.constant(int(20)));
   ir_expression *const r0022 = bit_and(r0021, body.constant(2047u));
   ir_expression *const r0023 = expr(ir_unop_u2i, r0022);
   body.emit(ret(r0023));

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

   ir_variable *const r0024 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0024);
   ir_variable *const r0025 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0025);
   ir_variable *const r0026 = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r0027 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r0027);
   ir_variable *const r0028 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0028);
   ir_variable *const r0029 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r0029);
   body.emit(assign(r0029, bit_and(swizzle_y(r0024), body.constant(1048575u)), 0x02));

   body.emit(assign(r0029, swizzle_x(r0024), 0x01));

   ir_variable *const r002A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r002A);
   body.emit(assign(r002A, bit_and(swizzle_y(r0025), body.constant(1048575u)), 0x02));

   body.emit(assign(r002A, swizzle_x(r0025), 0x01));

   ir_expression *const r002B = rshift(swizzle_y(r0024), body.constant(int(20)));
   ir_expression *const r002C = bit_and(r002B, body.constant(2047u));
   ir_expression *const r002D = expr(ir_unop_u2i, r002C);
   ir_expression *const r002E = equal(r002D, body.constant(int(2047)));
   ir_expression *const r002F = bit_or(swizzle_y(r0029), swizzle_x(r0024));
   ir_expression *const r0030 = nequal(r002F, body.constant(0u));
   body.emit(assign(r0028, logic_and(r002E, r0030), 0x01));

   ir_expression *const r0031 = rshift(swizzle_y(r0025), body.constant(int(20)));
   ir_expression *const r0032 = bit_and(r0031, body.constant(2047u));
   ir_expression *const r0033 = expr(ir_unop_u2i, r0032);
   ir_expression *const r0034 = equal(r0033, body.constant(int(2047)));
   ir_expression *const r0035 = bit_or(swizzle_y(r002A), swizzle_x(r0025));
   ir_expression *const r0036 = nequal(r0035, body.constant(0u));
   body.emit(assign(r0027, logic_and(r0034, r0036), 0x01));

   /* IF CONDITION */
   ir_expression *const r0038 = logic_or(r0028, r0027);
   ir_if *f0037 = new(mem_ctx) ir_if(operand(r0038).val);
   exec_list *const f0037_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0037->then_instructions;

      body.emit(assign(r0026, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0037->else_instructions;

      ir_expression *const r0039 = equal(swizzle_x(r0024), swizzle_x(r0025));
      ir_expression *const r003A = equal(swizzle_y(r0024), swizzle_y(r0025));
      ir_expression *const r003B = equal(swizzle_x(r0024), body.constant(0u));
      ir_expression *const r003C = bit_or(swizzle_y(r0024), swizzle_y(r0025));
      ir_expression *const r003D = lshift(r003C, body.constant(int(1)));
      ir_expression *const r003E = equal(r003D, body.constant(0u));
      ir_expression *const r003F = logic_and(r003B, r003E);
      ir_expression *const r0040 = logic_or(r003A, r003F);
      body.emit(assign(r0026, logic_and(r0039, r0040), 0x01));


   body.instructions = f0037_parent_instructions;
   body.emit(f0037);

   /* END IF */

   body.emit(ret(r0026));

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

   ir_variable *const r0041 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0041);
   ir_expression *const r0042 = rshift(swizzle_y(r0041), body.constant(int(31)));
   body.emit(ret(r0042));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
le64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::bool_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0043 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0043);
   ir_variable *const r0044 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0044);
   ir_variable *const r0045 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0045);
   ir_variable *const r0046 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0046);
   ir_expression *const r0047 = less(r0043, r0045);
   ir_expression *const r0048 = equal(r0043, r0045);
   ir_expression *const r0049 = lequal(r0044, r0046);
   ir_expression *const r004A = logic_and(r0048, r0049);
   ir_expression *const r004B = logic_or(r0047, r004A);
   body.emit(ret(r004B));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
fle64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::bool_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r004C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r004C);
   ir_variable *const r004D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r004D);
   ir_variable *const r004E = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r004F = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r004F);
   ir_variable *const r0050 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0050);
   ir_variable *const r0051 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r0051);
   body.emit(assign(r0051, bit_and(swizzle_y(r004C), body.constant(1048575u)), 0x02));

   body.emit(assign(r0051, swizzle_x(r004C), 0x01));

   ir_variable *const r0052 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r0052);
   body.emit(assign(r0052, bit_and(swizzle_y(r004D), body.constant(1048575u)), 0x02));

   body.emit(assign(r0052, swizzle_x(r004D), 0x01));

   ir_expression *const r0053 = rshift(swizzle_y(r004C), body.constant(int(20)));
   ir_expression *const r0054 = bit_and(r0053, body.constant(2047u));
   ir_expression *const r0055 = expr(ir_unop_u2i, r0054);
   ir_expression *const r0056 = equal(r0055, body.constant(int(2047)));
   ir_expression *const r0057 = bit_or(swizzle_y(r0051), swizzle_x(r004C));
   ir_expression *const r0058 = nequal(r0057, body.constant(0u));
   body.emit(assign(r0050, logic_and(r0056, r0058), 0x01));

   ir_expression *const r0059 = rshift(swizzle_y(r004D), body.constant(int(20)));
   ir_expression *const r005A = bit_and(r0059, body.constant(2047u));
   ir_expression *const r005B = expr(ir_unop_u2i, r005A);
   ir_expression *const r005C = equal(r005B, body.constant(int(2047)));
   ir_expression *const r005D = bit_or(swizzle_y(r0052), swizzle_x(r004D));
   ir_expression *const r005E = nequal(r005D, body.constant(0u));
   body.emit(assign(r004F, logic_and(r005C, r005E), 0x01));

   /* IF CONDITION */
   ir_expression *const r0060 = logic_or(r0050, r004F);
   ir_if *f005F = new(mem_ctx) ir_if(operand(r0060).val);
   exec_list *const f005F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f005F->then_instructions;

      body.emit(assign(r004E, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f005F->else_instructions;

      ir_variable *const r0061 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r0061, rshift(swizzle_y(r004C), body.constant(int(31))), 0x01));

      ir_variable *const r0062 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r0062, rshift(swizzle_y(r004D), body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0064 = nequal(r0061, r0062);
      ir_if *f0063 = new(mem_ctx) ir_if(operand(r0064).val);
      exec_list *const f0063_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0063->then_instructions;

         ir_expression *const r0065 = nequal(r0061, body.constant(0u));
         ir_expression *const r0066 = bit_or(swizzle_y(r004C), swizzle_y(r004D));
         ir_expression *const r0067 = lshift(r0066, body.constant(int(1)));
         ir_expression *const r0068 = bit_or(r0067, swizzle_x(r004C));
         ir_expression *const r0069 = bit_or(r0068, swizzle_x(r004D));
         ir_expression *const r006A = equal(r0069, body.constant(0u));
         body.emit(assign(r004E, logic_or(r0065, r006A), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0063->else_instructions;

         ir_variable *const r006B = body.make_temp(glsl_type::bool_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r006D = nequal(r0061, body.constant(0u));
         ir_if *f006C = new(mem_ctx) ir_if(operand(r006D).val);
         exec_list *const f006C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f006C->then_instructions;

            ir_expression *const r006E = less(swizzle_y(r004D), swizzle_y(r004C));
            ir_expression *const r006F = equal(swizzle_y(r004D), swizzle_y(r004C));
            ir_expression *const r0070 = lequal(swizzle_x(r004D), swizzle_x(r004C));
            ir_expression *const r0071 = logic_and(r006F, r0070);
            body.emit(assign(r006B, logic_or(r006E, r0071), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f006C->else_instructions;

            ir_expression *const r0072 = less(swizzle_y(r004C), swizzle_y(r004D));
            ir_expression *const r0073 = equal(swizzle_y(r004C), swizzle_y(r004D));
            ir_expression *const r0074 = lequal(swizzle_x(r004C), swizzle_x(r004D));
            ir_expression *const r0075 = logic_and(r0073, r0074);
            body.emit(assign(r006B, logic_or(r0072, r0075), 0x01));


         body.instructions = f006C_parent_instructions;
         body.emit(f006C);

         /* END IF */

         body.emit(assign(r004E, r006B, 0x01));


      body.instructions = f0063_parent_instructions;
      body.emit(f0063);

      /* END IF */


   body.instructions = f005F_parent_instructions;
   body.emit(f005F);

   /* END IF */

   body.emit(ret(r004E));

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

   ir_variable *const r0076 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0076);
   ir_variable *const r0077 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0077);
   ir_variable *const r0078 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0078);
   ir_variable *const r0079 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0079);
   ir_expression *const r007A = less(r0076, r0078);
   ir_expression *const r007B = equal(r0076, r0078);
   ir_expression *const r007C = less(r0077, r0079);
   ir_expression *const r007D = logic_and(r007B, r007C);
   ir_expression *const r007E = logic_or(r007A, r007D);
   body.emit(ret(r007E));

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

   ir_variable *const r007F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r007F);
   ir_variable *const r0080 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0080);
   ir_variable *const r0081 = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r0082 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r0082);
   ir_variable *const r0083 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0083);
   ir_variable *const r0084 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r0084);
   body.emit(assign(r0084, bit_and(swizzle_y(r007F), body.constant(1048575u)), 0x02));

   body.emit(assign(r0084, swizzle_x(r007F), 0x01));

   ir_variable *const r0085 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "frac", ir_var_auto);
   body.emit(r0085);
   body.emit(assign(r0085, bit_and(swizzle_y(r0080), body.constant(1048575u)), 0x02));

   body.emit(assign(r0085, swizzle_x(r0080), 0x01));

   ir_expression *const r0086 = rshift(swizzle_y(r007F), body.constant(int(20)));
   ir_expression *const r0087 = bit_and(r0086, body.constant(2047u));
   ir_expression *const r0088 = expr(ir_unop_u2i, r0087);
   ir_expression *const r0089 = equal(r0088, body.constant(int(2047)));
   ir_expression *const r008A = bit_or(swizzle_y(r0084), swizzle_x(r007F));
   ir_expression *const r008B = nequal(r008A, body.constant(0u));
   body.emit(assign(r0083, logic_and(r0089, r008B), 0x01));

   ir_expression *const r008C = rshift(swizzle_y(r0080), body.constant(int(20)));
   ir_expression *const r008D = bit_and(r008C, body.constant(2047u));
   ir_expression *const r008E = expr(ir_unop_u2i, r008D);
   ir_expression *const r008F = equal(r008E, body.constant(int(2047)));
   ir_expression *const r0090 = bit_or(swizzle_y(r0085), swizzle_x(r0080));
   ir_expression *const r0091 = nequal(r0090, body.constant(0u));
   body.emit(assign(r0082, logic_and(r008F, r0091), 0x01));

   /* IF CONDITION */
   ir_expression *const r0093 = logic_or(r0083, r0082);
   ir_if *f0092 = new(mem_ctx) ir_if(operand(r0093).val);
   exec_list *const f0092_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0092->then_instructions;

      body.emit(assign(r0081, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0092->else_instructions;

      ir_variable *const r0094 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r0094, rshift(swizzle_y(r007F), body.constant(int(31))), 0x01));

      ir_variable *const r0095 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r0095, rshift(swizzle_y(r0080), body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0097 = nequal(r0094, r0095);
      ir_if *f0096 = new(mem_ctx) ir_if(operand(r0097).val);
      exec_list *const f0096_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0096->then_instructions;

         ir_expression *const r0098 = nequal(r0094, body.constant(0u));
         ir_expression *const r0099 = bit_or(swizzle_y(r007F), swizzle_y(r0080));
         ir_expression *const r009A = lshift(r0099, body.constant(int(1)));
         ir_expression *const r009B = bit_or(r009A, swizzle_x(r007F));
         ir_expression *const r009C = bit_or(r009B, swizzle_x(r0080));
         ir_expression *const r009D = nequal(r009C, body.constant(0u));
         body.emit(assign(r0081, logic_and(r0098, r009D), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0096->else_instructions;

         ir_variable *const r009E = body.make_temp(glsl_type::bool_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r00A0 = nequal(r0094, body.constant(0u));
         ir_if *f009F = new(mem_ctx) ir_if(operand(r00A0).val);
         exec_list *const f009F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f009F->then_instructions;

            ir_expression *const r00A1 = less(swizzle_y(r0080), swizzle_y(r007F));
            ir_expression *const r00A2 = equal(swizzle_y(r0080), swizzle_y(r007F));
            ir_expression *const r00A3 = less(swizzle_x(r0080), swizzle_x(r007F));
            ir_expression *const r00A4 = logic_and(r00A2, r00A3);
            body.emit(assign(r009E, logic_or(r00A1, r00A4), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f009F->else_instructions;

            ir_expression *const r00A5 = less(swizzle_y(r007F), swizzle_y(r0080));
            ir_expression *const r00A6 = equal(swizzle_y(r007F), swizzle_y(r0080));
            ir_expression *const r00A7 = less(swizzle_x(r007F), swizzle_x(r0080));
            ir_expression *const r00A8 = logic_and(r00A6, r00A7);
            body.emit(assign(r009E, logic_or(r00A5, r00A8), 0x01));


         body.instructions = f009F_parent_instructions;
         body.emit(f009F);

         /* END IF */

         body.emit(assign(r0081, r009E, 0x01));


      body.instructions = f0096_parent_instructions;
      body.emit(f0096);

      /* END IF */


   body.instructions = f0092_parent_instructions;
   body.emit(f0092);

   /* END IF */

   body.emit(ret(r0081));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
