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
   body.emit(assign(r000B, bit_and(swizzle_x(r000B), body.constant(2147483647u)), 0x01));

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

      body.emit(assign(r0014, bit_xor(swizzle_x(r0014), body.constant(2147483648u)), 0x01));

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
   ir_variable *const r001F = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r001F, bit_and(swizzle_x(r001E), body.constant(1048575u)), 0x01));

   body.emit(assign(r001F, swizzle_y(r001E), 0x02));

   body.emit(ret(r001F));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
extractFloat64Exp(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uint_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0020 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0020);
   ir_expression *const r0021 = rshift(swizzle_x(r0020), body.constant(int(20)));
   ir_expression *const r0022 = bit_and(r0021, body.constant(2047u));
   body.emit(ret(r0022));

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

   ir_variable *const r0023 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0023);
   ir_variable *const r0024 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0024);
   ir_variable *const r0025 = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r0026 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r0026);
   ir_variable *const r0027 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0027);
   ir_variable *const r0028 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r0028, bit_and(swizzle_x(r0023), body.constant(1048575u)), 0x01));

   body.emit(assign(r0028, swizzle_y(r0023), 0x02));

   ir_variable *const r0029 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r0029, bit_and(swizzle_x(r0024), body.constant(1048575u)), 0x01));

   body.emit(assign(r0029, swizzle_y(r0024), 0x02));

   ir_expression *const r002A = rshift(swizzle_x(r0023), body.constant(int(20)));
   ir_expression *const r002B = bit_and(r002A, body.constant(2047u));
   ir_expression *const r002C = equal(r002B, body.constant(2047u));
   ir_expression *const r002D = bit_or(swizzle_x(r0028), swizzle_y(r0023));
   ir_expression *const r002E = nequal(r002D, body.constant(0u));
   body.emit(assign(r0027, logic_and(r002C, r002E), 0x01));

   ir_expression *const r002F = rshift(swizzle_x(r0024), body.constant(int(20)));
   ir_expression *const r0030 = bit_and(r002F, body.constant(2047u));
   ir_expression *const r0031 = equal(r0030, body.constant(2047u));
   ir_expression *const r0032 = bit_or(swizzle_x(r0029), swizzle_y(r0024));
   ir_expression *const r0033 = nequal(r0032, body.constant(0u));
   body.emit(assign(r0026, logic_and(r0031, r0033), 0x01));

   /* IF CONDITION */
   ir_expression *const r0035 = logic_or(r0027, r0026);
   ir_if *f0034 = new(mem_ctx) ir_if(operand(r0035).val);
   exec_list *const f0034_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0034->then_instructions;

      body.emit(assign(r0025, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0034->else_instructions;

      ir_expression *const r0036 = equal(swizzle_y(r0023), swizzle_y(r0024));
      ir_expression *const r0037 = equal(swizzle_x(r0023), swizzle_x(r0024));
      ir_expression *const r0038 = equal(swizzle_y(r0023), body.constant(0u));
      ir_expression *const r0039 = bit_or(swizzle_x(r0023), swizzle_x(r0024));
      ir_expression *const r003A = lshift(r0039, body.constant(int(1)));
      ir_expression *const r003B = equal(r003A, body.constant(0u));
      ir_expression *const r003C = logic_and(r0038, r003B);
      ir_expression *const r003D = logic_or(r0037, r003C);
      body.emit(assign(r0025, logic_and(r0036, r003D), 0x01));


   body.instructions = f0034_parent_instructions;
   body.emit(f0034);

   /* END IF */

   body.emit(ret(r0025));

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

   ir_variable *const r003E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r003E);
   ir_expression *const r003F = rshift(swizzle_x(r003E), body.constant(int(31)));
   body.emit(ret(r003F));

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

   ir_variable *const r0040 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0040);
   ir_variable *const r0041 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0041);
   ir_variable *const r0042 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0042);
   ir_variable *const r0043 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0043);
   ir_expression *const r0044 = less(r0040, r0042);
   ir_expression *const r0045 = equal(r0040, r0042);
   ir_expression *const r0046 = lequal(r0041, r0043);
   ir_expression *const r0047 = logic_and(r0045, r0046);
   ir_expression *const r0048 = logic_or(r0044, r0047);
   body.emit(ret(r0048));

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

   ir_variable *const r0049 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0049);
   ir_variable *const r004A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r004A);
   ir_variable *const r004B = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r004C = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r004C);
   ir_variable *const r004D = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r004D);
   ir_variable *const r004E = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r004E, bit_and(swizzle_x(r0049), body.constant(1048575u)), 0x01));

   body.emit(assign(r004E, swizzle_y(r0049), 0x02));

   ir_variable *const r004F = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r004F, bit_and(swizzle_x(r004A), body.constant(1048575u)), 0x01));

   body.emit(assign(r004F, swizzle_y(r004A), 0x02));

   ir_expression *const r0050 = rshift(swizzle_x(r0049), body.constant(int(20)));
   ir_expression *const r0051 = bit_and(r0050, body.constant(2047u));
   ir_expression *const r0052 = equal(r0051, body.constant(2047u));
   ir_expression *const r0053 = bit_or(swizzle_x(r004E), swizzle_y(r0049));
   ir_expression *const r0054 = nequal(r0053, body.constant(0u));
   body.emit(assign(r004D, logic_and(r0052, r0054), 0x01));

   ir_expression *const r0055 = rshift(swizzle_x(r004A), body.constant(int(20)));
   ir_expression *const r0056 = bit_and(r0055, body.constant(2047u));
   ir_expression *const r0057 = equal(r0056, body.constant(2047u));
   ir_expression *const r0058 = bit_or(swizzle_x(r004F), swizzle_y(r004A));
   ir_expression *const r0059 = nequal(r0058, body.constant(0u));
   body.emit(assign(r004C, logic_and(r0057, r0059), 0x01));

   /* IF CONDITION */
   ir_expression *const r005B = logic_or(r004D, r004C);
   ir_if *f005A = new(mem_ctx) ir_if(operand(r005B).val);
   exec_list *const f005A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f005A->then_instructions;

      body.emit(assign(r004B, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f005A->else_instructions;

      ir_variable *const r005C = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r005C, rshift(swizzle_x(r0049), body.constant(int(31))), 0x01));

      ir_variable *const r005D = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r005D, rshift(swizzle_x(r004A), body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r005F = nequal(r005C, r005D);
      ir_if *f005E = new(mem_ctx) ir_if(operand(r005F).val);
      exec_list *const f005E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f005E->then_instructions;

         ir_expression *const r0060 = nequal(r005C, body.constant(0u));
         ir_expression *const r0061 = bit_or(swizzle_x(r0049), swizzle_x(r004A));
         ir_expression *const r0062 = lshift(r0061, body.constant(int(1)));
         ir_expression *const r0063 = bit_or(r0062, swizzle_y(r0049));
         ir_expression *const r0064 = bit_or(r0063, swizzle_y(r004A));
         ir_expression *const r0065 = equal(r0064, body.constant(0u));
         body.emit(assign(r004B, logic_or(r0060, r0065), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f005E->else_instructions;

         ir_variable *const r0066 = body.make_temp(glsl_type::bool_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0068 = nequal(r005C, body.constant(0u));
         ir_if *f0067 = new(mem_ctx) ir_if(operand(r0068).val);
         exec_list *const f0067_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0067->then_instructions;

            ir_expression *const r0069 = less(swizzle_x(r004A), swizzle_x(r0049));
            ir_expression *const r006A = equal(swizzle_x(r004A), swizzle_x(r0049));
            ir_expression *const r006B = lequal(swizzle_y(r004A), swizzle_y(r0049));
            ir_expression *const r006C = logic_and(r006A, r006B);
            body.emit(assign(r0066, logic_or(r0069, r006C), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0067->else_instructions;

            ir_expression *const r006D = less(swizzle_x(r0049), swizzle_x(r004A));
            ir_expression *const r006E = equal(swizzle_x(r0049), swizzle_x(r004A));
            ir_expression *const r006F = lequal(swizzle_y(r0049), swizzle_y(r004A));
            ir_expression *const r0070 = logic_and(r006E, r006F);
            body.emit(assign(r0066, logic_or(r006D, r0070), 0x01));


         body.instructions = f0067_parent_instructions;
         body.emit(f0067);

         /* END IF */

         body.emit(assign(r004B, r0066, 0x01));


      body.instructions = f005E_parent_instructions;
      body.emit(f005E);

      /* END IF */


   body.instructions = f005A_parent_instructions;
   body.emit(f005A);

   /* END IF */

   body.emit(ret(r004B));

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

   ir_variable *const r0071 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0071);
   ir_variable *const r0072 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0072);
   ir_variable *const r0073 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0073);
   ir_variable *const r0074 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0074);
   ir_expression *const r0075 = less(r0071, r0073);
   ir_expression *const r0076 = equal(r0071, r0073);
   ir_expression *const r0077 = less(r0072, r0074);
   ir_expression *const r0078 = logic_and(r0076, r0077);
   ir_expression *const r0079 = logic_or(r0075, r0078);
   body.emit(ret(r0079));

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

   ir_variable *const r007A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r007A);
   ir_variable *const r007B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r007B);
   ir_variable *const r007C = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r007D = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r007D);
   ir_variable *const r007E = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r007E);
   ir_variable *const r007F = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r007F, bit_and(swizzle_x(r007A), body.constant(1048575u)), 0x01));

   body.emit(assign(r007F, swizzle_y(r007A), 0x02));

   ir_variable *const r0080 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r0080, bit_and(swizzle_x(r007B), body.constant(1048575u)), 0x01));

   body.emit(assign(r0080, swizzle_y(r007B), 0x02));

   ir_expression *const r0081 = rshift(swizzle_x(r007A), body.constant(int(20)));
   ir_expression *const r0082 = bit_and(r0081, body.constant(2047u));
   ir_expression *const r0083 = equal(r0082, body.constant(2047u));
   ir_expression *const r0084 = bit_or(swizzle_x(r007F), swizzle_y(r007A));
   ir_expression *const r0085 = nequal(r0084, body.constant(0u));
   body.emit(assign(r007E, logic_and(r0083, r0085), 0x01));

   ir_expression *const r0086 = rshift(swizzle_x(r007B), body.constant(int(20)));
   ir_expression *const r0087 = bit_and(r0086, body.constant(2047u));
   ir_expression *const r0088 = equal(r0087, body.constant(2047u));
   ir_expression *const r0089 = bit_or(swizzle_x(r0080), swizzle_y(r007B));
   ir_expression *const r008A = nequal(r0089, body.constant(0u));
   body.emit(assign(r007D, logic_and(r0088, r008A), 0x01));

   /* IF CONDITION */
   ir_expression *const r008C = logic_or(r007E, r007D);
   ir_if *f008B = new(mem_ctx) ir_if(operand(r008C).val);
   exec_list *const f008B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f008B->then_instructions;

      body.emit(assign(r007C, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f008B->else_instructions;

      ir_variable *const r008D = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r008D, rshift(swizzle_x(r007A), body.constant(int(31))), 0x01));

      ir_variable *const r008E = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r008E, rshift(swizzle_x(r007B), body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0090 = nequal(r008D, r008E);
      ir_if *f008F = new(mem_ctx) ir_if(operand(r0090).val);
      exec_list *const f008F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f008F->then_instructions;

         ir_expression *const r0091 = nequal(r008D, body.constant(0u));
         ir_expression *const r0092 = bit_or(swizzle_x(r007A), swizzle_x(r007B));
         ir_expression *const r0093 = lshift(r0092, body.constant(int(1)));
         ir_expression *const r0094 = bit_or(r0093, swizzle_y(r007A));
         ir_expression *const r0095 = bit_or(r0094, swizzle_y(r007B));
         ir_expression *const r0096 = nequal(r0095, body.constant(0u));
         body.emit(assign(r007C, logic_and(r0091, r0096), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f008F->else_instructions;

         ir_variable *const r0097 = body.make_temp(glsl_type::bool_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0099 = nequal(r008D, body.constant(0u));
         ir_if *f0098 = new(mem_ctx) ir_if(operand(r0099).val);
         exec_list *const f0098_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0098->then_instructions;

            ir_expression *const r009A = less(swizzle_x(r007B), swizzle_x(r007A));
            ir_expression *const r009B = equal(swizzle_x(r007B), swizzle_x(r007A));
            ir_expression *const r009C = less(swizzle_y(r007B), swizzle_y(r007A));
            ir_expression *const r009D = logic_and(r009B, r009C);
            body.emit(assign(r0097, logic_or(r009A, r009D), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0098->else_instructions;

            ir_expression *const r009E = less(swizzle_x(r007A), swizzle_x(r007B));
            ir_expression *const r009F = equal(swizzle_x(r007A), swizzle_x(r007B));
            ir_expression *const r00A0 = less(swizzle_y(r007A), swizzle_y(r007B));
            ir_expression *const r00A1 = logic_and(r009F, r00A0);
            body.emit(assign(r0097, logic_or(r009E, r00A1), 0x01));


         body.instructions = f0098_parent_instructions;
         body.emit(f0098);

         /* END IF */

         body.emit(assign(r007C, r0097, 0x01));


      body.instructions = f008F_parent_instructions;
      body.emit(f008F);

      /* END IF */


   body.instructions = f008B_parent_instructions;
   body.emit(f008B);

   /* END IF */

   body.emit(ret(r007C));

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

   ir_variable *const r00A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00A2);
   ir_variable *const r00A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00A3);
   ir_variable *const r00A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r00A4);
   ir_variable *const r00A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r00A5);
   ir_variable *const r00A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00A6);
   ir_variable *const r00A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00A7);
   ir_variable *const r00A8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r00A8, add(r00A3, r00A5), 0x01));

   body.emit(assign(r00A7, r00A8, 0x01));

   ir_expression *const r00A9 = add(r00A2, r00A4);
   ir_expression *const r00AA = less(r00A8, r00A3);
   ir_expression *const r00AB = expr(ir_unop_b2i, r00AA);
   ir_expression *const r00AC = expr(ir_unop_i2u, r00AB);
   body.emit(assign(r00A6, add(r00A9, r00AC), 0x01));

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

   ir_variable *const r00AD = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00AD);
   ir_variable *const r00AE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00AE);
   ir_variable *const r00AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r00AF);
   ir_variable *const r00B0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r00B0);
   ir_variable *const r00B1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00B1);
   ir_variable *const r00B2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00B2);
   body.emit(assign(r00B2, sub(r00AE, r00B0), 0x01));

   ir_expression *const r00B3 = sub(r00AD, r00AF);
   ir_expression *const r00B4 = less(r00AE, r00B0);
   ir_expression *const r00B5 = expr(ir_unop_b2i, r00B4);
   ir_expression *const r00B6 = expr(ir_unop_i2u, r00B5);
   body.emit(assign(r00B1, sub(r00B3, r00B6), 0x01));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
eq64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::bool_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r00B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00B7);
   ir_variable *const r00B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00B8);
   ir_variable *const r00B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r00B9);
   ir_variable *const r00BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r00BA);
   ir_expression *const r00BB = equal(r00B7, r00B9);
   ir_expression *const r00BC = equal(r00B8, r00BA);
   ir_expression *const r00BD = logic_and(r00BB, r00BC);
   body.emit(ret(r00BD));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
float64_is_signaling_nan(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::bool_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r00BE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r00BE);
   ir_expression *const r00BF = rshift(swizzle_y(r00BE), body.constant(int(19)));
   ir_expression *const r00C0 = bit_and(r00BF, body.constant(4095u));
   ir_expression *const r00C1 = equal(r00C0, body.constant(4094u));
   ir_expression *const r00C2 = nequal(swizzle_x(r00BE), body.constant(0u));
   ir_expression *const r00C3 = bit_and(swizzle_y(r00BE), body.constant(524287u));
   ir_expression *const r00C4 = nequal(r00C3, body.constant(0u));
   ir_expression *const r00C5 = logic_or(r00C2, r00C4);
   ir_expression *const r00C6 = logic_and(r00C1, r00C5);
   body.emit(ret(r00C6));

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

   ir_variable *const r00C7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r00C7);
   ir_variable *const r00C8 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00C8);
   ir_variable *const r00C9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C9);
   ir_variable *const r00CA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00CA);
   ir_variable *const r00CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r00CB);
   ir_variable *const r00CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r00CC);
   ir_variable *const r00CD = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r00CE = neg(r00C8);
   body.emit(assign(r00CD, bit_and(r00CE, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00D0 = equal(r00C8, body.constant(int(0)));
   ir_if *f00CF = new(mem_ctx) ir_if(operand(r00D0).val);
   exec_list *const f00CF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00CF->then_instructions;

      body.emit(assign(r00CB, swizzle_y(r00C7), 0x01));

      body.emit(assign(r00CC, swizzle_x(r00C7), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00CF->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00D2 = less(r00C8, body.constant(int(32)));
      ir_if *f00D1 = new(mem_ctx) ir_if(operand(r00D2).val);
      exec_list *const f00D1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00D1->then_instructions;

         ir_expression *const r00D3 = lshift(swizzle_x(r00C7), r00CD);
         ir_expression *const r00D4 = rshift(swizzle_y(r00C7), r00C8);
         ir_expression *const r00D5 = bit_or(r00D3, r00D4);
         ir_expression *const r00D6 = lshift(swizzle_y(r00C7), r00CD);
         ir_expression *const r00D7 = nequal(r00D6, body.constant(0u));
         ir_expression *const r00D8 = expr(ir_unop_b2i, r00D7);
         ir_expression *const r00D9 = expr(ir_unop_i2u, r00D8);
         body.emit(assign(r00CB, bit_or(r00D5, r00D9), 0x01));

         body.emit(assign(r00CC, rshift(swizzle_x(r00C7), r00C8), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00D1->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00DB = equal(r00C8, body.constant(int(32)));
         ir_if *f00DA = new(mem_ctx) ir_if(operand(r00DB).val);
         exec_list *const f00DA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00DA->then_instructions;

            ir_expression *const r00DC = nequal(swizzle_y(r00C7), body.constant(0u));
            ir_expression *const r00DD = expr(ir_unop_b2i, r00DC);
            ir_expression *const r00DE = expr(ir_unop_i2u, r00DD);
            body.emit(assign(r00CB, bit_or(swizzle_x(r00C7), r00DE), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00DA->else_instructions;

            /* IF CONDITION */
            ir_expression *const r00E0 = less(r00C8, body.constant(int(64)));
            ir_if *f00DF = new(mem_ctx) ir_if(operand(r00E0).val);
            exec_list *const f00DF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f00DF->then_instructions;

               ir_expression *const r00E1 = bit_and(r00C8, body.constant(int(31)));
               ir_expression *const r00E2 = rshift(swizzle_x(r00C7), r00E1);
               ir_expression *const r00E3 = lshift(swizzle_x(r00C7), r00CD);
               ir_expression *const r00E4 = bit_or(r00E3, swizzle_y(r00C7));
               ir_expression *const r00E5 = nequal(r00E4, body.constant(0u));
               ir_expression *const r00E6 = expr(ir_unop_b2i, r00E5);
               ir_expression *const r00E7 = expr(ir_unop_i2u, r00E6);
               body.emit(assign(r00CB, bit_or(r00E2, r00E7), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f00DF->else_instructions;

               ir_expression *const r00E8 = bit_or(swizzle_x(r00C7), swizzle_y(r00C7));
               ir_expression *const r00E9 = nequal(r00E8, body.constant(0u));
               ir_expression *const r00EA = expr(ir_unop_b2i, r00E9);
               body.emit(assign(r00CB, expr(ir_unop_i2u, r00EA), 0x01));


            body.instructions = f00DF_parent_instructions;
            body.emit(f00DF);

            /* END IF */


         body.instructions = f00DA_parent_instructions;
         body.emit(f00DA);

         /* END IF */

         body.emit(assign(r00CC, body.constant(0u), 0x01));


      body.instructions = f00D1_parent_instructions;
      body.emit(f00D1);

      /* END IF */


   body.instructions = f00CF_parent_instructions;
   body.emit(f00CF);

   /* END IF */

   body.emit(assign(r00CA, r00CB, 0x01));

   body.emit(assign(r00C9, r00CC, 0x01));

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

   ir_variable *const r00EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00EB);
   ir_variable *const r00EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00EC);
   ir_variable *const r00ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r00ED);
   ir_variable *const r00EE = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00EE);
   ir_variable *const r00EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00EF);
   ir_variable *const r00F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00F0);
   ir_variable *const r00F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00F1);
   ir_variable *const r00F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
   body.emit(r00F2);
   ir_variable *const r00F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r00F3);
   ir_variable *const r00F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r00F4);
   ir_variable *const r00F5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r00F6 = neg(r00EE);
   body.emit(assign(r00F5, bit_and(r00F6, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00F8 = equal(r00EE, body.constant(int(0)));
   ir_if *f00F7 = new(mem_ctx) ir_if(operand(r00F8).val);
   exec_list *const f00F7_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00F7->then_instructions;

      body.emit(assign(r00F2, r00ED, 0x01));

      body.emit(assign(r00F3, r00EC, 0x01));

      body.emit(assign(r00F4, r00EB, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00F7->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00FA = less(r00EE, body.constant(int(32)));
      ir_if *f00F9 = new(mem_ctx) ir_if(operand(r00FA).val);
      exec_list *const f00F9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00F9->then_instructions;

         body.emit(assign(r00F2, lshift(r00EC, r00F5), 0x01));

         ir_expression *const r00FB = lshift(r00EB, r00F5);
         ir_expression *const r00FC = rshift(r00EC, r00EE);
         body.emit(assign(r00F3, bit_or(r00FB, r00FC), 0x01));

         body.emit(assign(r00F4, rshift(r00EB, r00EE), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00F9->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00FE = equal(r00EE, body.constant(int(32)));
         ir_if *f00FD = new(mem_ctx) ir_if(operand(r00FE).val);
         exec_list *const f00FD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00FD->then_instructions;

            body.emit(assign(r00F2, r00EC, 0x01));

            body.emit(assign(r00F3, r00EB, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00FD->else_instructions;

            body.emit(assign(r00ED, bit_or(r00ED, r00EC), 0x01));

            /* IF CONDITION */
            ir_expression *const r0100 = less(r00EE, body.constant(int(64)));
            ir_if *f00FF = new(mem_ctx) ir_if(operand(r0100).val);
            exec_list *const f00FF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f00FF->then_instructions;

               body.emit(assign(r00F2, lshift(r00EB, r00F5), 0x01));

               ir_expression *const r0101 = bit_and(r00EE, body.constant(int(31)));
               body.emit(assign(r00F3, rshift(r00EB, r0101), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f00FF->else_instructions;

               ir_variable *const r0102 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0104 = equal(r00EE, body.constant(int(64)));
               ir_if *f0103 = new(mem_ctx) ir_if(operand(r0104).val);
               exec_list *const f0103_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0103->then_instructions;

                  body.emit(assign(r0102, r00EB, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0103->else_instructions;

                  ir_expression *const r0105 = nequal(r00EB, body.constant(0u));
                  ir_expression *const r0106 = expr(ir_unop_b2i, r0105);
                  body.emit(assign(r0102, expr(ir_unop_i2u, r0106), 0x01));


               body.instructions = f0103_parent_instructions;
               body.emit(f0103);

               /* END IF */

               body.emit(assign(r00F2, r0102, 0x01));

               body.emit(assign(r00F3, body.constant(0u), 0x01));


            body.instructions = f00FF_parent_instructions;
            body.emit(f00FF);

            /* END IF */


         body.instructions = f00FD_parent_instructions;
         body.emit(f00FD);

         /* END IF */

         body.emit(assign(r00F4, body.constant(0u), 0x01));


      body.instructions = f00F9_parent_instructions;
      body.emit(f00F9);

      /* END IF */

      ir_expression *const r0107 = nequal(r00ED, body.constant(0u));
      ir_expression *const r0108 = expr(ir_unop_b2i, r0107);
      ir_expression *const r0109 = expr(ir_unop_i2u, r0108);
      body.emit(assign(r00F2, bit_or(r00F2, r0109), 0x01));


   body.instructions = f00F7_parent_instructions;
   body.emit(f00F7);

   /* END IF */

   body.emit(assign(r00F1, r00F2, 0x01));

   body.emit(assign(r00F0, r00F3, 0x01));

   body.emit(assign(r00EF, r00F4, 0x01));

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

   ir_variable *const r010A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r010A);
   ir_variable *const r010B = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r010B);
   ir_variable *const r010C = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r010C);
   ir_variable *const r010D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r010D);
   ir_variable *const r010E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r010E);
   body.emit(assign(r010E, lshift(r010B, r010C), 0x01));

   ir_variable *const r010F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
   /* IF CONDITION */
   ir_expression *const r0111 = equal(r010C, body.constant(int(0)));
   ir_if *f0110 = new(mem_ctx) ir_if(operand(r0111).val);
   exec_list *const f0110_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0110->then_instructions;

      body.emit(assign(r010F, r010A, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0110->else_instructions;

      ir_expression *const r0112 = lshift(r010A, r010C);
      ir_expression *const r0113 = neg(r010C);
      ir_expression *const r0114 = bit_and(r0113, body.constant(int(31)));
      ir_expression *const r0115 = rshift(r010B, r0114);
      body.emit(assign(r010F, bit_or(r0112, r0115), 0x01));


   body.instructions = f0110_parent_instructions;
   body.emit(f0110);

   /* END IF */

   body.emit(assign(r010D, r010F, 0x01));

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

   ir_variable *const r0116 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0116);
   ir_variable *const r0117 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0117);
   ir_variable *const r0118 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0118);
   ir_variable *const r0119 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0119);
   ir_variable *const r011A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
   body.emit(r011A);
   ir_expression *const r011B = lshift(r0116, body.constant(int(31)));
   ir_expression *const r011C = lshift(r0117, body.constant(int(20)));
   ir_expression *const r011D = add(r011B, r011C);
   body.emit(assign(r011A, add(r011D, r0118), 0x01));

   body.emit(assign(r011A, r0119, 0x02));

   body.emit(ret(r011A));

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

   ir_variable *const r011E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r011E);
   ir_variable *const r011F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r011F);
   ir_variable *const r0120 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0120);
   ir_variable *const r0121 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0121);
   ir_variable *const r0122 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_function_in);
   sig_parameters.push_tail(r0122);
   ir_variable *const r0123 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0123, body.constant(true), 0x01));

   ir_variable *const r0124 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0125 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
   body.emit(r0125);
   ir_expression *const r0126 = less(r0122, body.constant(0u));
   ir_expression *const r0127 = expr(ir_unop_b2i, r0126);
   body.emit(assign(r0125, expr(ir_unop_i2u, r0127), 0x01));

   /* IF CONDITION */
   ir_expression *const r0129 = lequal(body.constant(2045u), r011F);
   ir_if *f0128 = new(mem_ctx) ir_if(operand(r0129).val);
   exec_list *const f0128_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0128->then_instructions;

      ir_variable *const r012A = body.make_temp(glsl_type::bool_type, "or_tmp");
      /* IF CONDITION */
      ir_expression *const r012C = less(body.constant(2045u), r011F);
      ir_if *f012B = new(mem_ctx) ir_if(operand(r012C).val);
      exec_list *const f012B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f012B->then_instructions;

         body.emit(assign(r012A, body.constant(true), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f012B->else_instructions;

         ir_variable *const r012D = body.make_temp(glsl_type::bool_type, "and_tmp");
         /* IF CONDITION */
         ir_expression *const r012F = equal(r011F, body.constant(2045u));
         ir_if *f012E = new(mem_ctx) ir_if(operand(r012F).val);
         exec_list *const f012E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f012E->then_instructions;

            ir_expression *const r0130 = equal(body.constant(2097151u), r0120);
            ir_expression *const r0131 = equal(body.constant(4294967295u), r0121);
            body.emit(assign(r012D, logic_and(r0130, r0131), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f012E->else_instructions;

            body.emit(assign(r012D, body.constant(false), 0x01));


         body.instructions = f012E_parent_instructions;
         body.emit(f012E);

         /* END IF */

         ir_expression *const r0132 = nequal(r0125, body.constant(0u));
         body.emit(assign(r012A, logic_and(r012D, r0132), 0x01));


      body.instructions = f012B_parent_instructions;
      body.emit(f012B);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0133 = new(mem_ctx) ir_if(operand(r012A).val);
      exec_list *const f0133_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0133->then_instructions;

         ir_variable *const r0134 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0134);
         ir_expression *const r0135 = lshift(r011E, body.constant(int(31)));
         body.emit(assign(r0134, add(r0135, body.constant(2146435072u)), 0x01));

         body.emit(assign(r0134, body.constant(0u), 0x02));

         body.emit(assign(r0124, r0134, 0x03));

         body.emit(assign(r0123, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0133->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0137 = less(r011F, body.constant(0u));
         ir_if *f0136 = new(mem_ctx) ir_if(operand(r0137).val);
         exec_list *const f0136_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0136->then_instructions;

            ir_variable *const r0138 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0138, r0122, 0x01));

            ir_variable *const r0139 = body.make_temp(glsl_type::int_type, "count");
            ir_expression *const r013A = neg(r011F);
            body.emit(assign(r0139, expr(ir_unop_u2i, r013A), 0x01));

            ir_variable *const r013B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r013B);
            ir_variable *const r013C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r013C);
            ir_variable *const r013D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r013D);
            ir_variable *const r013E = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r013F = neg(r0139);
            body.emit(assign(r013E, bit_and(r013F, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0141 = equal(r0139, body.constant(int(0)));
            ir_if *f0140 = new(mem_ctx) ir_if(operand(r0141).val);
            exec_list *const f0140_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0140->then_instructions;

               body.emit(assign(r013B, r0122, 0x01));

               body.emit(assign(r013C, r0121, 0x01));

               body.emit(assign(r013D, r0120, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0140->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0143 = less(r0139, body.constant(int(32)));
               ir_if *f0142 = new(mem_ctx) ir_if(operand(r0143).val);
               exec_list *const f0142_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0142->then_instructions;

                  body.emit(assign(r013B, lshift(r0121, r013E), 0x01));

                  ir_expression *const r0144 = lshift(r0120, r013E);
                  ir_expression *const r0145 = rshift(r0121, r0139);
                  body.emit(assign(r013C, bit_or(r0144, r0145), 0x01));

                  body.emit(assign(r013D, rshift(r0120, r0139), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0142->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0147 = equal(r0139, body.constant(int(32)));
                  ir_if *f0146 = new(mem_ctx) ir_if(operand(r0147).val);
                  exec_list *const f0146_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0146->then_instructions;

                     body.emit(assign(r013B, r0121, 0x01));

                     body.emit(assign(r013C, r0120, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0146->else_instructions;

                     body.emit(assign(r0138, bit_or(r0122, r0121), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0149 = less(r0139, body.constant(int(64)));
                     ir_if *f0148 = new(mem_ctx) ir_if(operand(r0149).val);
                     exec_list *const f0148_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0148->then_instructions;

                        body.emit(assign(r013B, lshift(r0120, r013E), 0x01));

                        ir_expression *const r014A = bit_and(r0139, body.constant(int(31)));
                        body.emit(assign(r013C, rshift(r0120, r014A), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0148->else_instructions;

                        ir_variable *const r014B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r014D = equal(r0139, body.constant(int(64)));
                        ir_if *f014C = new(mem_ctx) ir_if(operand(r014D).val);
                        exec_list *const f014C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f014C->then_instructions;

                           body.emit(assign(r014B, r0120, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f014C->else_instructions;

                           ir_expression *const r014E = nequal(r0120, body.constant(0u));
                           ir_expression *const r014F = expr(ir_unop_b2i, r014E);
                           body.emit(assign(r014B, expr(ir_unop_i2u, r014F), 0x01));


                        body.instructions = f014C_parent_instructions;
                        body.emit(f014C);

                        /* END IF */

                        body.emit(assign(r013B, r014B, 0x01));

                        body.emit(assign(r013C, body.constant(0u), 0x01));


                     body.instructions = f0148_parent_instructions;
                     body.emit(f0148);

                     /* END IF */


                  body.instructions = f0146_parent_instructions;
                  body.emit(f0146);

                  /* END IF */

                  body.emit(assign(r013D, body.constant(0u), 0x01));


               body.instructions = f0142_parent_instructions;
               body.emit(f0142);

               /* END IF */

               ir_expression *const r0150 = nequal(r0138, body.constant(0u));
               ir_expression *const r0151 = expr(ir_unop_b2i, r0150);
               ir_expression *const r0152 = expr(ir_unop_i2u, r0151);
               body.emit(assign(r013B, bit_or(r013B, r0152), 0x01));


            body.instructions = f0140_parent_instructions;
            body.emit(f0140);

            /* END IF */

            body.emit(assign(r0120, r013D, 0x01));

            body.emit(assign(r0121, r013C, 0x01));

            body.emit(assign(r0122, r013B, 0x01));

            body.emit(assign(r011F, body.constant(0u), 0x01));

            ir_expression *const r0153 = less(r013B, body.constant(0u));
            ir_expression *const r0154 = expr(ir_unop_b2i, r0153);
            body.emit(assign(r0125, expr(ir_unop_i2u, r0154), 0x01));


         body.instructions = f0136_parent_instructions;
         body.emit(f0136);

         /* END IF */


      body.instructions = f0133_parent_instructions;
      body.emit(f0133);

      /* END IF */


   body.instructions = f0128_parent_instructions;
   body.emit(f0128);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0155 = new(mem_ctx) ir_if(operand(r0123).val);
   exec_list *const f0155_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0155->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0157 = nequal(r0125, body.constant(0u));
      ir_if *f0156 = new(mem_ctx) ir_if(operand(r0157).val);
      exec_list *const f0156_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0156->then_instructions;

         ir_variable *const r0158 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0158, add(r0121, body.constant(1u)), 0x01));

         ir_expression *const r0159 = less(r0158, r0121);
         ir_expression *const r015A = expr(ir_unop_b2i, r0159);
         ir_expression *const r015B = expr(ir_unop_i2u, r015A);
         body.emit(assign(r0120, add(r0120, r015B), 0x01));

         ir_expression *const r015C = neg(r0122);
         ir_expression *const r015D = equal(r0122, r015C);
         ir_expression *const r015E = expr(ir_unop_b2i, r015D);
         ir_expression *const r015F = expr(ir_unop_i2u, r015E);
         ir_expression *const r0160 = bit_and(r015F, body.constant(1u));
         ir_expression *const r0161 = expr(ir_unop_bit_not, r0160);
         body.emit(assign(r0121, bit_and(r0158, r0161), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0156->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0163 = bit_or(r0120, r0121);
         ir_expression *const r0164 = equal(r0163, body.constant(0u));
         ir_if *f0162 = new(mem_ctx) ir_if(operand(r0164).val);
         exec_list *const f0162_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0162->then_instructions;

            body.emit(assign(r011F, body.constant(0u), 0x01));


         body.instructions = f0162_parent_instructions;
         body.emit(f0162);

         /* END IF */


      body.instructions = f0156_parent_instructions;
      body.emit(f0156);

      /* END IF */

      ir_variable *const r0165 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0165);
      ir_expression *const r0166 = lshift(r011E, body.constant(int(31)));
      ir_expression *const r0167 = lshift(r011F, body.constant(int(20)));
      ir_expression *const r0168 = add(r0166, r0167);
      body.emit(assign(r0165, add(r0168, r0120), 0x01));

      body.emit(assign(r0165, r0121, 0x02));

      body.emit(assign(r0124, r0165, 0x03));

      body.emit(assign(r0123, body.constant(false), 0x01));


   body.instructions = f0155_parent_instructions;
   body.emit(f0155);

   /* END IF */

   body.emit(ret(r0124));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
countLeadingZeros32(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uint_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0169 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0169);
   ir_variable *const r016A = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r016B = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
   body.emit(r016B);
   /* IF CONDITION */
   ir_expression *const r016D = equal(r0169, body.constant(0u));
   ir_if *f016C = new(mem_ctx) ir_if(operand(r016D).val);
   exec_list *const f016C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f016C->then_instructions;

      body.emit(assign(r016A, body.constant(32u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f016C->else_instructions;

      body.emit(assign(r016B, body.constant(0u), 0x01));

      /* IF CONDITION */
      ir_expression *const r016F = bit_and(r0169, body.constant(4294901760u));
      ir_expression *const r0170 = equal(r016F, body.constant(0u));
      ir_if *f016E = new(mem_ctx) ir_if(operand(r0170).val);
      exec_list *const f016E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f016E->then_instructions;

         body.emit(assign(r016B, body.constant(16u), 0x01));

         body.emit(assign(r0169, lshift(r0169, body.constant(int(16))), 0x01));


      body.instructions = f016E_parent_instructions;
      body.emit(f016E);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0172 = bit_and(r0169, body.constant(4278190080u));
      ir_expression *const r0173 = equal(r0172, body.constant(0u));
      ir_if *f0171 = new(mem_ctx) ir_if(operand(r0173).val);
      exec_list *const f0171_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0171->then_instructions;

         body.emit(assign(r016B, add(r016B, body.constant(8u)), 0x01));

         body.emit(assign(r0169, lshift(r0169, body.constant(int(8))), 0x01));


      body.instructions = f0171_parent_instructions;
      body.emit(f0171);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0175 = bit_and(r0169, body.constant(4026531840u));
      ir_expression *const r0176 = equal(r0175, body.constant(0u));
      ir_if *f0174 = new(mem_ctx) ir_if(operand(r0176).val);
      exec_list *const f0174_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0174->then_instructions;

         body.emit(assign(r016B, add(r016B, body.constant(4u)), 0x01));

         body.emit(assign(r0169, lshift(r0169, body.constant(int(4))), 0x01));


      body.instructions = f0174_parent_instructions;
      body.emit(f0174);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0178 = bit_and(r0169, body.constant(3221225472u));
      ir_expression *const r0179 = equal(r0178, body.constant(0u));
      ir_if *f0177 = new(mem_ctx) ir_if(operand(r0179).val);
      exec_list *const f0177_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0177->then_instructions;

         body.emit(assign(r016B, add(r016B, body.constant(2u)), 0x01));

         body.emit(assign(r0169, lshift(r0169, body.constant(int(2))), 0x01));


      body.instructions = f0177_parent_instructions;
      body.emit(f0177);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r017B = bit_and(r0169, body.constant(2147483648u));
      ir_expression *const r017C = equal(r017B, body.constant(0u));
      ir_if *f017A = new(mem_ctx) ir_if(operand(r017C).val);
      exec_list *const f017A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f017A->then_instructions;

         body.emit(assign(r016B, add(r016B, body.constant(1u)), 0x01));


      body.instructions = f017A_parent_instructions;
      body.emit(f017A);

      /* END IF */

      body.emit(assign(r016A, r016B, 0x01));


   body.instructions = f016C_parent_instructions;
   body.emit(f016C);

   /* END IF */

   body.emit(ret(r016A));

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

   ir_variable *const r017D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r017D);
   ir_variable *const r017E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r017E);
   ir_variable *const r017F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r017F);
   ir_variable *const r0180 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0180);
   ir_variable *const r0181 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0181);
   ir_variable *const r0182 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0182);
   /* IF CONDITION */
   ir_expression *const r0184 = equal(r017F, body.constant(0u));
   ir_if *f0183 = new(mem_ctx) ir_if(operand(r0184).val);
   exec_list *const f0183_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0183->then_instructions;

      body.emit(assign(r017F, r0180, 0x01));

      body.emit(assign(r0180, body.constant(0u), 0x01));

      body.emit(assign(r017E, add(r017E, body.constant(4294967264u)), 0x01));


   body.instructions = f0183_parent_instructions;
   body.emit(f0183);

   /* END IF */

   ir_variable *const r0185 = body.make_temp(glsl_type::uint_type, "a");
   body.emit(assign(r0185, r017F, 0x01));

   ir_variable *const r0186 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0187 = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
   body.emit(r0187);
   /* IF CONDITION */
   ir_expression *const r0189 = equal(r017F, body.constant(0u));
   ir_if *f0188 = new(mem_ctx) ir_if(operand(r0189).val);
   exec_list *const f0188_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0188->then_instructions;

      body.emit(assign(r0186, body.constant(32u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0188->else_instructions;

      body.emit(assign(r0187, body.constant(0u), 0x01));

      /* IF CONDITION */
      ir_expression *const r018B = bit_and(r017F, body.constant(4294901760u));
      ir_expression *const r018C = equal(r018B, body.constant(0u));
      ir_if *f018A = new(mem_ctx) ir_if(operand(r018C).val);
      exec_list *const f018A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f018A->then_instructions;

         body.emit(assign(r0187, body.constant(16u), 0x01));

         body.emit(assign(r0185, lshift(r017F, body.constant(int(16))), 0x01));


      body.instructions = f018A_parent_instructions;
      body.emit(f018A);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r018E = bit_and(r0185, body.constant(4278190080u));
      ir_expression *const r018F = equal(r018E, body.constant(0u));
      ir_if *f018D = new(mem_ctx) ir_if(operand(r018F).val);
      exec_list *const f018D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f018D->then_instructions;

         body.emit(assign(r0187, add(r0187, body.constant(8u)), 0x01));

         body.emit(assign(r0185, lshift(r0185, body.constant(int(8))), 0x01));


      body.instructions = f018D_parent_instructions;
      body.emit(f018D);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0191 = bit_and(r0185, body.constant(4026531840u));
      ir_expression *const r0192 = equal(r0191, body.constant(0u));
      ir_if *f0190 = new(mem_ctx) ir_if(operand(r0192).val);
      exec_list *const f0190_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0190->then_instructions;

         body.emit(assign(r0187, add(r0187, body.constant(4u)), 0x01));

         body.emit(assign(r0185, lshift(r0185, body.constant(int(4))), 0x01));


      body.instructions = f0190_parent_instructions;
      body.emit(f0190);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0194 = bit_and(r0185, body.constant(3221225472u));
      ir_expression *const r0195 = equal(r0194, body.constant(0u));
      ir_if *f0193 = new(mem_ctx) ir_if(operand(r0195).val);
      exec_list *const f0193_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0193->then_instructions;

         body.emit(assign(r0187, add(r0187, body.constant(2u)), 0x01));

         body.emit(assign(r0185, lshift(r0185, body.constant(int(2))), 0x01));


      body.instructions = f0193_parent_instructions;
      body.emit(f0193);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0197 = bit_and(r0185, body.constant(2147483648u));
      ir_expression *const r0198 = equal(r0197, body.constant(0u));
      ir_if *f0196 = new(mem_ctx) ir_if(operand(r0198).val);
      exec_list *const f0196_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0196->then_instructions;

         body.emit(assign(r0187, add(r0187, body.constant(1u)), 0x01));


      body.instructions = f0196_parent_instructions;
      body.emit(f0196);

      /* END IF */

      body.emit(assign(r0186, r0187, 0x01));


   body.instructions = f0188_parent_instructions;
   body.emit(f0188);

   /* END IF */

   ir_expression *const r0199 = expr(ir_unop_u2i, r0186);
   body.emit(assign(r0182, add(r0199, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r019B = lequal(body.constant(int(0)), r0182);
   ir_if *f019A = new(mem_ctx) ir_if(operand(r019B).val);
   exec_list *const f019A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f019A->then_instructions;

      body.emit(assign(r0181, body.constant(0u), 0x01));

      ir_variable *const r019C = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r019C, lshift(r0180, r0182), 0x01));

      ir_variable *const r019D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r019F = equal(r0182, body.constant(int(0)));
      ir_if *f019E = new(mem_ctx) ir_if(operand(r019F).val);
      exec_list *const f019E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f019E->then_instructions;

         body.emit(assign(r019D, r017F, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f019E->else_instructions;

         ir_expression *const r01A0 = lshift(r017F, r0182);
         ir_expression *const r01A1 = neg(r0182);
         ir_expression *const r01A2 = bit_and(r01A1, body.constant(int(31)));
         ir_expression *const r01A3 = rshift(r0180, r01A2);
         body.emit(assign(r019D, bit_or(r01A0, r01A3), 0x01));


      body.instructions = f019E_parent_instructions;
      body.emit(f019E);

      /* END IF */

      body.emit(assign(r017F, r019D, 0x01));

      body.emit(assign(r0180, r019C, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f019A->else_instructions;

      ir_variable *const r01A4 = body.make_temp(glsl_type::uint_type, "a2");
      body.emit(assign(r01A4, body.constant(0u), 0x01));

      ir_variable *const r01A5 = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r01A5, neg(r0182), 0x01));

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

         body.emit(assign(r01A6, r01A4, 0x01));

         body.emit(assign(r01A7, r0180, 0x01));

         body.emit(assign(r01A8, r017F, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01AB->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01AE = less(r01A5, body.constant(int(32)));
         ir_if *f01AD = new(mem_ctx) ir_if(operand(r01AE).val);
         exec_list *const f01AD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01AD->then_instructions;

            body.emit(assign(r01A6, lshift(r0180, r01A9), 0x01));

            ir_expression *const r01AF = lshift(r017F, r01A9);
            ir_expression *const r01B0 = rshift(r0180, r01A5);
            body.emit(assign(r01A7, bit_or(r01AF, r01B0), 0x01));

            body.emit(assign(r01A8, rshift(r017F, r01A5), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f01AD->else_instructions;

            /* IF CONDITION */
            ir_expression *const r01B2 = equal(r01A5, body.constant(int(32)));
            ir_if *f01B1 = new(mem_ctx) ir_if(operand(r01B2).val);
            exec_list *const f01B1_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01B1->then_instructions;

               body.emit(assign(r01A6, r0180, 0x01));

               body.emit(assign(r01A7, r017F, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01B1->else_instructions;

               body.emit(assign(r01A4, bit_or(body.constant(0u), r0180), 0x01));

               /* IF CONDITION */
               ir_expression *const r01B4 = less(r01A5, body.constant(int(64)));
               ir_if *f01B3 = new(mem_ctx) ir_if(operand(r01B4).val);
               exec_list *const f01B3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f01B3->then_instructions;

                  body.emit(assign(r01A6, lshift(r017F, r01A9), 0x01));

                  ir_expression *const r01B5 = bit_and(r01A5, body.constant(int(31)));
                  body.emit(assign(r01A7, rshift(r017F, r01B5), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f01B3->else_instructions;

                  ir_variable *const r01B6 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r01B8 = equal(r01A5, body.constant(int(64)));
                  ir_if *f01B7 = new(mem_ctx) ir_if(operand(r01B8).val);
                  exec_list *const f01B7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f01B7->then_instructions;

                     body.emit(assign(r01B6, r017F, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f01B7->else_instructions;

                     ir_expression *const r01B9 = nequal(r017F, body.constant(0u));
                     ir_expression *const r01BA = expr(ir_unop_b2i, r01B9);
                     body.emit(assign(r01B6, expr(ir_unop_i2u, r01BA), 0x01));


                  body.instructions = f01B7_parent_instructions;
                  body.emit(f01B7);

                  /* END IF */

                  body.emit(assign(r01A6, r01B6, 0x01));

                  body.emit(assign(r01A7, body.constant(0u), 0x01));


               body.instructions = f01B3_parent_instructions;
               body.emit(f01B3);

               /* END IF */


            body.instructions = f01B1_parent_instructions;
            body.emit(f01B1);

            /* END IF */

            body.emit(assign(r01A8, body.constant(0u), 0x01));


         body.instructions = f01AD_parent_instructions;
         body.emit(f01AD);

         /* END IF */

         ir_expression *const r01BB = nequal(r01A4, body.constant(0u));
         ir_expression *const r01BC = expr(ir_unop_b2i, r01BB);
         ir_expression *const r01BD = expr(ir_unop_i2u, r01BC);
         body.emit(assign(r01A6, bit_or(r01A6, r01BD), 0x01));


      body.instructions = f01AB_parent_instructions;
      body.emit(f01AB);

      /* END IF */

      body.emit(assign(r017F, r01A8, 0x01));

      body.emit(assign(r0180, r01A7, 0x01));

      body.emit(assign(r0181, r01A6, 0x01));


   body.instructions = f019A_parent_instructions;
   body.emit(f019A);

   /* END IF */

   ir_expression *const r01BE = expr(ir_unop_i2u, r0182);
   body.emit(assign(r017E, sub(r017E, r01BE), 0x01));

   ir_variable *const r01BF = body.make_temp(glsl_type::uint_type, "zExp");
   body.emit(assign(r01BF, r017E, 0x01));

   ir_variable *const r01C0 = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r01C0, r017F, 0x01));

   ir_variable *const r01C1 = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r01C1, r0180, 0x01));

   ir_variable *const r01C2 = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r01C2, r0181, 0x01));

   ir_variable *const r01C3 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01C3, body.constant(true), 0x01));

   ir_variable *const r01C4 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
   body.emit(r01C5);
   ir_expression *const r01C6 = less(r0181, body.constant(0u));
   ir_expression *const r01C7 = expr(ir_unop_b2i, r01C6);
   body.emit(assign(r01C5, expr(ir_unop_i2u, r01C7), 0x01));

   /* IF CONDITION */
   ir_expression *const r01C9 = lequal(body.constant(2045u), r017E);
   ir_if *f01C8 = new(mem_ctx) ir_if(operand(r01C9).val);
   exec_list *const f01C8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01C8->then_instructions;

      ir_variable *const r01CA = body.make_temp(glsl_type::bool_type, "or_tmp");
      /* IF CONDITION */
      ir_expression *const r01CC = less(body.constant(2045u), r017E);
      ir_if *f01CB = new(mem_ctx) ir_if(operand(r01CC).val);
      exec_list *const f01CB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01CB->then_instructions;

         body.emit(assign(r01CA, body.constant(true), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01CB->else_instructions;

         ir_variable *const r01CD = body.make_temp(glsl_type::bool_type, "and_tmp");
         /* IF CONDITION */
         ir_expression *const r01CF = equal(r017E, body.constant(2045u));
         ir_if *f01CE = new(mem_ctx) ir_if(operand(r01CF).val);
         exec_list *const f01CE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01CE->then_instructions;

            ir_expression *const r01D0 = equal(body.constant(2097151u), r017F);
            ir_expression *const r01D1 = equal(body.constant(4294967295u), r0180);
            body.emit(assign(r01CD, logic_and(r01D0, r01D1), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f01CE->else_instructions;

            body.emit(assign(r01CD, body.constant(false), 0x01));


         body.instructions = f01CE_parent_instructions;
         body.emit(f01CE);

         /* END IF */

         ir_expression *const r01D2 = nequal(r01C5, body.constant(0u));
         body.emit(assign(r01CA, logic_and(r01CD, r01D2), 0x01));


      body.instructions = f01CB_parent_instructions;
      body.emit(f01CB);

      /* END IF */

      /* IF CONDITION */
      ir_if *f01D3 = new(mem_ctx) ir_if(operand(r01CA).val);
      exec_list *const f01D3_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01D3->then_instructions;

         ir_variable *const r01D4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r01D4);
         ir_expression *const r01D5 = lshift(r017D, body.constant(int(31)));
         body.emit(assign(r01D4, add(r01D5, body.constant(2146435072u)), 0x01));

         body.emit(assign(r01D4, body.constant(0u), 0x02));

         body.emit(assign(r01C4, r01D4, 0x03));

         body.emit(assign(r01C3, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01D3->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01D7 = less(r017E, body.constant(0u));
         ir_if *f01D6 = new(mem_ctx) ir_if(operand(r01D7).val);
         exec_list *const f01D6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01D6->then_instructions;

            ir_variable *const r01D8 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r01D8, r0181, 0x01));

            ir_variable *const r01D9 = body.make_temp(glsl_type::int_type, "count");
            ir_expression *const r01DA = neg(r017E);
            body.emit(assign(r01D9, expr(ir_unop_u2i, r01DA), 0x01));

            ir_variable *const r01DB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r01DB);
            ir_variable *const r01DC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r01DC);
            ir_variable *const r01DD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r01DD);
            ir_variable *const r01DE = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r01DF = neg(r01D9);
            body.emit(assign(r01DE, bit_and(r01DF, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r01E1 = equal(r01D9, body.constant(int(0)));
            ir_if *f01E0 = new(mem_ctx) ir_if(operand(r01E1).val);
            exec_list *const f01E0_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01E0->then_instructions;

               body.emit(assign(r01DB, r0181, 0x01));

               body.emit(assign(r01DC, r0180, 0x01));

               body.emit(assign(r01DD, r017F, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01E0->else_instructions;

               /* IF CONDITION */
               ir_expression *const r01E3 = less(r01D9, body.constant(int(32)));
               ir_if *f01E2 = new(mem_ctx) ir_if(operand(r01E3).val);
               exec_list *const f01E2_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f01E2->then_instructions;

                  body.emit(assign(r01DB, lshift(r0180, r01DE), 0x01));

                  ir_expression *const r01E4 = lshift(r017F, r01DE);
                  ir_expression *const r01E5 = rshift(r0180, r01D9);
                  body.emit(assign(r01DC, bit_or(r01E4, r01E5), 0x01));

                  body.emit(assign(r01DD, rshift(r017F, r01D9), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f01E2->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r01E7 = equal(r01D9, body.constant(int(32)));
                  ir_if *f01E6 = new(mem_ctx) ir_if(operand(r01E7).val);
                  exec_list *const f01E6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f01E6->then_instructions;

                     body.emit(assign(r01DB, r0180, 0x01));

                     body.emit(assign(r01DC, r017F, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f01E6->else_instructions;

                     body.emit(assign(r01D8, bit_or(r0181, r0180), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r01E9 = less(r01D9, body.constant(int(64)));
                     ir_if *f01E8 = new(mem_ctx) ir_if(operand(r01E9).val);
                     exec_list *const f01E8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f01E8->then_instructions;

                        body.emit(assign(r01DB, lshift(r017F, r01DE), 0x01));

                        ir_expression *const r01EA = bit_and(r01D9, body.constant(int(31)));
                        body.emit(assign(r01DC, rshift(r017F, r01EA), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f01E8->else_instructions;

                        ir_variable *const r01EB = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r01ED = equal(r01D9, body.constant(int(64)));
                        ir_if *f01EC = new(mem_ctx) ir_if(operand(r01ED).val);
                        exec_list *const f01EC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f01EC->then_instructions;

                           body.emit(assign(r01EB, r017F, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f01EC->else_instructions;

                           ir_expression *const r01EE = nequal(r017F, body.constant(0u));
                           ir_expression *const r01EF = expr(ir_unop_b2i, r01EE);
                           body.emit(assign(r01EB, expr(ir_unop_i2u, r01EF), 0x01));


                        body.instructions = f01EC_parent_instructions;
                        body.emit(f01EC);

                        /* END IF */

                        body.emit(assign(r01DB, r01EB, 0x01));

                        body.emit(assign(r01DC, body.constant(0u), 0x01));


                     body.instructions = f01E8_parent_instructions;
                     body.emit(f01E8);

                     /* END IF */


                  body.instructions = f01E6_parent_instructions;
                  body.emit(f01E6);

                  /* END IF */

                  body.emit(assign(r01DD, body.constant(0u), 0x01));


               body.instructions = f01E2_parent_instructions;
               body.emit(f01E2);

               /* END IF */

               ir_expression *const r01F0 = nequal(r01D8, body.constant(0u));
               ir_expression *const r01F1 = expr(ir_unop_b2i, r01F0);
               ir_expression *const r01F2 = expr(ir_unop_i2u, r01F1);
               body.emit(assign(r01DB, bit_or(r01DB, r01F2), 0x01));


            body.instructions = f01E0_parent_instructions;
            body.emit(f01E0);

            /* END IF */

            body.emit(assign(r01C0, r01DD, 0x01));

            body.emit(assign(r01C1, r01DC, 0x01));

            body.emit(assign(r01C2, r01DB, 0x01));

            body.emit(assign(r01BF, body.constant(0u), 0x01));

            ir_expression *const r01F3 = less(r01DB, body.constant(0u));
            ir_expression *const r01F4 = expr(ir_unop_b2i, r01F3);
            body.emit(assign(r01C5, expr(ir_unop_i2u, r01F4), 0x01));


         body.instructions = f01D6_parent_instructions;
         body.emit(f01D6);

         /* END IF */


      body.instructions = f01D3_parent_instructions;
      body.emit(f01D3);

      /* END IF */


   body.instructions = f01C8_parent_instructions;
   body.emit(f01C8);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01F5 = new(mem_ctx) ir_if(operand(r01C3).val);
   exec_list *const f01F5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01F5->then_instructions;

      /* IF CONDITION */
      ir_expression *const r01F7 = nequal(r01C5, body.constant(0u));
      ir_if *f01F6 = new(mem_ctx) ir_if(operand(r01F7).val);
      exec_list *const f01F6_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01F6->then_instructions;

         ir_variable *const r01F8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01F8, add(r01C1, body.constant(1u)), 0x01));

         ir_expression *const r01F9 = less(r01F8, r01C1);
         ir_expression *const r01FA = expr(ir_unop_b2i, r01F9);
         ir_expression *const r01FB = expr(ir_unop_i2u, r01FA);
         body.emit(assign(r01C0, add(r01C0, r01FB), 0x01));

         ir_expression *const r01FC = neg(r01C2);
         ir_expression *const r01FD = equal(r01C2, r01FC);
         ir_expression *const r01FE = expr(ir_unop_b2i, r01FD);
         ir_expression *const r01FF = expr(ir_unop_i2u, r01FE);
         ir_expression *const r0200 = bit_and(r01FF, body.constant(1u));
         ir_expression *const r0201 = expr(ir_unop_bit_not, r0200);
         body.emit(assign(r01C1, bit_and(r01F8, r0201), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01F6->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0203 = bit_or(r01C0, r01C1);
         ir_expression *const r0204 = equal(r0203, body.constant(0u));
         ir_if *f0202 = new(mem_ctx) ir_if(operand(r0204).val);
         exec_list *const f0202_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0202->then_instructions;

            body.emit(assign(r01BF, body.constant(0u), 0x01));


         body.instructions = f0202_parent_instructions;
         body.emit(f0202);

         /* END IF */


      body.instructions = f01F6_parent_instructions;
      body.emit(f01F6);

      /* END IF */

      ir_variable *const r0205 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0205);
      ir_expression *const r0206 = lshift(r017D, body.constant(int(31)));
      ir_expression *const r0207 = lshift(r01BF, body.constant(int(20)));
      ir_expression *const r0208 = add(r0206, r0207);
      body.emit(assign(r0205, add(r0208, r01C0), 0x01));

      body.emit(assign(r0205, r01C1, 0x02));

      body.emit(assign(r01C4, r0205, 0x03));

      body.emit(assign(r01C3, body.constant(false), 0x01));


   body.instructions = f01F5_parent_instructions;
   body.emit(f01F5);

   /* END IF */

   body.emit(ret(r01C4));

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

   ir_variable *const r0209 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0209);
   ir_variable *const r020A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r020A);
   ir_variable *const r020B = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r020C = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r020D = lshift(swizzle_y(r0209), body.constant(int(1)));
   ir_expression *const r020E = lequal(body.constant(4292870144u), r020D);
   ir_expression *const r020F = nequal(swizzle_x(r0209), body.constant(0u));
   ir_expression *const r0210 = bit_and(swizzle_y(r0209), body.constant(1048575u));
   ir_expression *const r0211 = nequal(r0210, body.constant(0u));
   ir_expression *const r0212 = logic_or(r020F, r0211);
   body.emit(assign(r020C, logic_and(r020E, r0212), 0x01));

   ir_variable *const r0213 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
   ir_expression *const r0214 = rshift(swizzle_y(r0209), body.constant(int(19)));
   ir_expression *const r0215 = bit_and(r0214, body.constant(4095u));
   ir_expression *const r0216 = equal(r0215, body.constant(4094u));
   ir_expression *const r0217 = nequal(swizzle_x(r0209), body.constant(0u));
   ir_expression *const r0218 = bit_and(swizzle_y(r0209), body.constant(524287u));
   ir_expression *const r0219 = nequal(r0218, body.constant(0u));
   ir_expression *const r021A = logic_or(r0217, r0219);
   body.emit(assign(r0213, logic_and(r0216, r021A), 0x01));

   ir_variable *const r021B = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r021C = lshift(swizzle_y(r020A), body.constant(int(1)));
   ir_expression *const r021D = lequal(body.constant(4292870144u), r021C);
   ir_expression *const r021E = nequal(swizzle_x(r020A), body.constant(0u));
   ir_expression *const r021F = bit_and(swizzle_y(r020A), body.constant(1048575u));
   ir_expression *const r0220 = nequal(r021F, body.constant(0u));
   ir_expression *const r0221 = logic_or(r021E, r0220);
   body.emit(assign(r021B, logic_and(r021D, r0221), 0x01));

   body.emit(assign(r0209, bit_or(swizzle_y(r0209), body.constant(524288u)), 0x02));

   body.emit(assign(r020A, bit_or(swizzle_y(r020A), body.constant(524288u)), 0x02));

   /* IF CONDITION */
   ir_if *f0222 = new(mem_ctx) ir_if(operand(r020C).val);
   exec_list *const f0222_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0222->then_instructions;

      ir_variable *const r0223 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0225 = logic_and(r0213, r021B);
      ir_if *f0224 = new(mem_ctx) ir_if(operand(r0225).val);
      exec_list *const f0224_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0224->then_instructions;

         body.emit(assign(r0223, r020A, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0224->else_instructions;

         body.emit(assign(r0223, r0209, 0x03));


      body.instructions = f0224_parent_instructions;
      body.emit(f0224);

      /* END IF */

      body.emit(assign(r020B, r0223, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0222->else_instructions;

      body.emit(assign(r020B, r020A, 0x03));


   body.instructions = f0222_parent_instructions;
   body.emit(f0222);

   /* END IF */

   body.emit(ret(r020B));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
addFloat64Fracs(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r0226 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0226);
   ir_variable *const r0227 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0227);
   ir_variable *const r0228 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0228);
   ir_variable *const r0229 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0229, body.constant(true), 0x01));

   ir_variable *const r022A = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r022B = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
   body.emit(r022B);
   ir_variable *const r022C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "bFrac", ir_var_auto);
   body.emit(r022C);
   ir_variable *const r022D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "aFrac", ir_var_auto);
   body.emit(r022D);
   ir_variable *const r022E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zExp", ir_var_auto);
   body.emit(r022E);
   ir_variable *const r022F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r022F);
   ir_variable *const r0230 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0230);
   body.emit(assign(r0230, body.constant(0u), 0x01));

   body.emit(assign(r022F, body.constant(0u), 0x01));

   ir_variable *const r0231 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r0231, bit_and(swizzle_x(r0226), body.constant(1048575u)), 0x01));

   body.emit(assign(r0231, swizzle_y(r0226), 0x02));

   body.emit(assign(r022D, r0231, 0x03));

   ir_variable *const r0232 = body.make_temp(glsl_type::uint_type, "extractFloat64Exp_retval");
   ir_expression *const r0233 = rshift(swizzle_x(r0226), body.constant(int(20)));
   body.emit(assign(r0232, bit_and(r0233, body.constant(2047u)), 0x01));

   ir_variable *const r0234 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r0234, bit_and(swizzle_x(r0227), body.constant(1048575u)), 0x01));

   body.emit(assign(r0234, swizzle_y(r0227), 0x02));

   body.emit(assign(r022C, r0234, 0x03));

   ir_variable *const r0235 = body.make_temp(glsl_type::uint_type, "extractFloat64Exp_retval");
   ir_expression *const r0236 = rshift(swizzle_x(r0227), body.constant(int(20)));
   body.emit(assign(r0235, bit_and(r0236, body.constant(2047u)), 0x01));

   ir_variable *const r0237 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0238 = expr(ir_unop_u2i, r0232);
   ir_expression *const r0239 = expr(ir_unop_u2i, r0235);
   body.emit(assign(r0237, sub(r0238, r0239), 0x01));

   body.emit(assign(r022B, r0237, 0x01));

   /* IF CONDITION */
   ir_expression *const r023B = less(body.constant(int(0)), r0237);
   ir_if *f023A = new(mem_ctx) ir_if(operand(r023B).val);
   exec_list *const f023A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f023A->then_instructions;

      /* IF CONDITION */
      ir_expression *const r023D = equal(r0232, body.constant(2047u));
      ir_if *f023C = new(mem_ctx) ir_if(operand(r023D).val);
      exec_list *const f023C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f023C->then_instructions;

         /* IF CONDITION */
         ir_expression *const r023F = bit_or(swizzle_x(r0231), swizzle_y(r0226));
         ir_expression *const r0240 = nequal(r023F, body.constant(0u));
         ir_if *f023E = new(mem_ctx) ir_if(operand(r0240).val);
         exec_list *const f023E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f023E->then_instructions;

            ir_variable *const r0241 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0241, swizzle_x(r0226), 0x01));

            ir_variable *const r0242 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0242, swizzle_x(r0227), 0x01));

            ir_variable *const r0243 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0244 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
            ir_expression *const r0245 = rshift(swizzle_y(r0226), body.constant(int(19)));
            ir_expression *const r0246 = bit_and(r0245, body.constant(4095u));
            ir_expression *const r0247 = equal(r0246, body.constant(4094u));
            ir_expression *const r0248 = nequal(swizzle_x(r0226), body.constant(0u));
            ir_expression *const r0249 = bit_and(swizzle_y(r0226), body.constant(524287u));
            ir_expression *const r024A = nequal(r0249, body.constant(0u));
            ir_expression *const r024B = logic_or(r0248, r024A);
            body.emit(assign(r0244, logic_and(r0247, r024B), 0x01));

            ir_variable *const r024C = body.make_temp(glsl_type::bool_type, "is_nan_retval");
            ir_expression *const r024D = lshift(swizzle_y(r0227), body.constant(int(1)));
            ir_expression *const r024E = lequal(body.constant(4292870144u), r024D);
            ir_expression *const r024F = nequal(swizzle_x(r0227), body.constant(0u));
            ir_expression *const r0250 = bit_and(swizzle_y(r0227), body.constant(1048575u));
            ir_expression *const r0251 = nequal(r0250, body.constant(0u));
            ir_expression *const r0252 = logic_or(r024F, r0251);
            body.emit(assign(r024C, logic_and(r024E, r0252), 0x01));

            body.emit(assign(r0241, bit_or(swizzle_y(r0226), body.constant(524288u)), 0x02));

            body.emit(assign(r0242, bit_or(swizzle_y(r0227), body.constant(524288u)), 0x02));

            /* IF CONDITION */
            ir_expression *const r0254 = lshift(swizzle_y(r0226), body.constant(int(1)));
            ir_expression *const r0255 = lequal(body.constant(4292870144u), r0254);
            ir_expression *const r0256 = nequal(swizzle_x(r0226), body.constant(0u));
            ir_expression *const r0257 = bit_and(swizzle_y(r0226), body.constant(1048575u));
            ir_expression *const r0258 = nequal(r0257, body.constant(0u));
            ir_expression *const r0259 = logic_or(r0256, r0258);
            ir_expression *const r025A = logic_and(r0255, r0259);
            ir_if *f0253 = new(mem_ctx) ir_if(operand(r025A).val);
            exec_list *const f0253_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0253->then_instructions;

               ir_variable *const r025B = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r025D = logic_and(r0244, r024C);
               ir_if *f025C = new(mem_ctx) ir_if(operand(r025D).val);
               exec_list *const f025C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f025C->then_instructions;

                  body.emit(assign(r025B, r0242, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f025C->else_instructions;

                  body.emit(assign(r025B, r0241, 0x03));


               body.instructions = f025C_parent_instructions;
               body.emit(f025C);

               /* END IF */

               body.emit(assign(r0243, r025B, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0253->else_instructions;

               body.emit(assign(r0243, r0242, 0x03));


            body.instructions = f0253_parent_instructions;
            body.emit(f0253);

            /* END IF */

            body.emit(assign(r022A, r0243, 0x03));

            body.emit(assign(r0229, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f023E->else_instructions;

            body.emit(assign(r022A, r0226, 0x03));

            body.emit(assign(r0229, body.constant(false), 0x01));


         body.instructions = f023E_parent_instructions;
         body.emit(f023E);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f023C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r025F = equal(r0235, body.constant(0u));
         ir_if *f025E = new(mem_ctx) ir_if(operand(r025F).val);
         exec_list *const f025E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f025E->then_instructions;

            body.emit(assign(r022B, add(r0237, body.constant(int(-1))), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f025E->else_instructions;

            body.emit(assign(r022C, bit_or(swizzle_x(r0234), body.constant(1048576u)), 0x01));


         body.instructions = f025E_parent_instructions;
         body.emit(f025E);

         /* END IF */

         ir_variable *const r0260 = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r0260, swizzle_x(r022C), 0x01));

         ir_variable *const r0261 = body.make_temp(glsl_type::uint_type, "a1");
         body.emit(assign(r0261, swizzle_y(r022C), 0x01));

         ir_variable *const r0262 = body.make_temp(glsl_type::uint_type, "a2");
         body.emit(assign(r0262, body.constant(0u), 0x01));

         ir_variable *const r0263 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
         body.emit(r0263);
         ir_variable *const r0264 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
         body.emit(r0264);
         ir_variable *const r0265 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
         body.emit(r0265);
         ir_variable *const r0266 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         ir_expression *const r0267 = neg(r022B);
         body.emit(assign(r0266, bit_and(r0267, body.constant(int(31))), 0x01));

         /* IF CONDITION */
         ir_expression *const r0269 = equal(r022B, body.constant(int(0)));
         ir_if *f0268 = new(mem_ctx) ir_if(operand(r0269).val);
         exec_list *const f0268_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0268->then_instructions;

            body.emit(assign(r0263, r0262, 0x01));

            body.emit(assign(r0264, r0261, 0x01));

            body.emit(assign(r0265, r0260, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0268->else_instructions;

            /* IF CONDITION */
            ir_expression *const r026B = less(r022B, body.constant(int(32)));
            ir_if *f026A = new(mem_ctx) ir_if(operand(r026B).val);
            exec_list *const f026A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f026A->then_instructions;

               body.emit(assign(r0263, lshift(swizzle_y(r0234), r0266), 0x01));

               ir_expression *const r026C = lshift(swizzle_x(r022C), r0266);
               ir_expression *const r026D = rshift(swizzle_y(r0234), r022B);
               body.emit(assign(r0264, bit_or(r026C, r026D), 0x01));

               body.emit(assign(r0265, rshift(swizzle_x(r022C), r022B), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f026A->else_instructions;

               /* IF CONDITION */
               ir_expression *const r026F = equal(r022B, body.constant(int(32)));
               ir_if *f026E = new(mem_ctx) ir_if(operand(r026F).val);
               exec_list *const f026E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f026E->then_instructions;

                  body.emit(assign(r0263, r0261, 0x01));

                  body.emit(assign(r0264, r0260, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f026E->else_instructions;

                  body.emit(assign(r0262, bit_or(body.constant(0u), swizzle_y(r0234)), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0271 = less(r022B, body.constant(int(64)));
                  ir_if *f0270 = new(mem_ctx) ir_if(operand(r0271).val);
                  exec_list *const f0270_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0270->then_instructions;

                     body.emit(assign(r0263, lshift(swizzle_x(r022C), r0266), 0x01));

                     ir_expression *const r0272 = bit_and(r022B, body.constant(int(31)));
                     body.emit(assign(r0264, rshift(swizzle_x(r022C), r0272), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0270->else_instructions;

                     ir_variable *const r0273 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0275 = equal(r022B, body.constant(int(64)));
                     ir_if *f0274 = new(mem_ctx) ir_if(operand(r0275).val);
                     exec_list *const f0274_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0274->then_instructions;

                        body.emit(assign(r0273, r0260, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0274->else_instructions;

                        ir_expression *const r0276 = nequal(swizzle_x(r022C), body.constant(0u));
                        ir_expression *const r0277 = expr(ir_unop_b2i, r0276);
                        body.emit(assign(r0273, expr(ir_unop_i2u, r0277), 0x01));


                     body.instructions = f0274_parent_instructions;
                     body.emit(f0274);

                     /* END IF */

                     body.emit(assign(r0263, r0273, 0x01));

                     body.emit(assign(r0264, body.constant(0u), 0x01));


                  body.instructions = f0270_parent_instructions;
                  body.emit(f0270);

                  /* END IF */


               body.instructions = f026E_parent_instructions;
               body.emit(f026E);

               /* END IF */

               body.emit(assign(r0265, body.constant(0u), 0x01));


            body.instructions = f026A_parent_instructions;
            body.emit(f026A);

            /* END IF */

            ir_expression *const r0278 = nequal(r0262, body.constant(0u));
            ir_expression *const r0279 = expr(ir_unop_b2i, r0278);
            ir_expression *const r027A = expr(ir_unop_i2u, r0279);
            body.emit(assign(r0263, bit_or(r0263, r027A), 0x01));


         body.instructions = f0268_parent_instructions;
         body.emit(f0268);

         /* END IF */

         body.emit(assign(r022C, r0265, 0x01));

         body.emit(assign(r022C, r0264, 0x02));

         body.emit(assign(r022F, r0263, 0x01));

         body.emit(assign(r022E, r0232, 0x01));


      body.instructions = f023C_parent_instructions;
      body.emit(f023C);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f023A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r027C = less(r022B, body.constant(int(0)));
      ir_if *f027B = new(mem_ctx) ir_if(operand(r027C).val);
      exec_list *const f027B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f027B->then_instructions;

         /* IF CONDITION */
         ir_expression *const r027E = equal(r0235, body.constant(2047u));
         ir_if *f027D = new(mem_ctx) ir_if(operand(r027E).val);
         exec_list *const f027D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f027D->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0280 = bit_or(swizzle_x(r022C), swizzle_y(r022C));
            ir_expression *const r0281 = nequal(r0280, body.constant(0u));
            ir_if *f027F = new(mem_ctx) ir_if(operand(r0281).val);
            exec_list *const f027F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f027F->then_instructions;

               ir_variable *const r0282 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0282, swizzle_x(r0226), 0x01));

               ir_variable *const r0283 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0283, swizzle_x(r0227), 0x01));

               ir_variable *const r0284 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0285 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
               ir_expression *const r0286 = rshift(swizzle_y(r0226), body.constant(int(19)));
               ir_expression *const r0287 = bit_and(r0286, body.constant(4095u));
               ir_expression *const r0288 = equal(r0287, body.constant(4094u));
               ir_expression *const r0289 = nequal(swizzle_x(r0226), body.constant(0u));
               ir_expression *const r028A = bit_and(swizzle_y(r0226), body.constant(524287u));
               ir_expression *const r028B = nequal(r028A, body.constant(0u));
               ir_expression *const r028C = logic_or(r0289, r028B);
               body.emit(assign(r0285, logic_and(r0288, r028C), 0x01));

               ir_variable *const r028D = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r028E = lshift(swizzle_y(r0227), body.constant(int(1)));
               ir_expression *const r028F = lequal(body.constant(4292870144u), r028E);
               ir_expression *const r0290 = nequal(swizzle_x(r0227), body.constant(0u));
               ir_expression *const r0291 = bit_and(swizzle_y(r0227), body.constant(1048575u));
               ir_expression *const r0292 = nequal(r0291, body.constant(0u));
               ir_expression *const r0293 = logic_or(r0290, r0292);
               body.emit(assign(r028D, logic_and(r028F, r0293), 0x01));

               body.emit(assign(r0282, bit_or(swizzle_y(r0226), body.constant(524288u)), 0x02));

               body.emit(assign(r0283, bit_or(swizzle_y(r0227), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r0295 = lshift(swizzle_y(r0226), body.constant(int(1)));
               ir_expression *const r0296 = lequal(body.constant(4292870144u), r0295);
               ir_expression *const r0297 = nequal(swizzle_x(r0226), body.constant(0u));
               ir_expression *const r0298 = bit_and(swizzle_y(r0226), body.constant(1048575u));
               ir_expression *const r0299 = nequal(r0298, body.constant(0u));
               ir_expression *const r029A = logic_or(r0297, r0299);
               ir_expression *const r029B = logic_and(r0296, r029A);
               ir_if *f0294 = new(mem_ctx) ir_if(operand(r029B).val);
               exec_list *const f0294_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0294->then_instructions;

                  ir_variable *const r029C = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r029E = logic_and(r0285, r028D);
                  ir_if *f029D = new(mem_ctx) ir_if(operand(r029E).val);
                  exec_list *const f029D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f029D->then_instructions;

                     body.emit(assign(r029C, r0283, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f029D->else_instructions;

                     body.emit(assign(r029C, r0282, 0x03));


                  body.instructions = f029D_parent_instructions;
                  body.emit(f029D);

                  /* END IF */

                  body.emit(assign(r0284, r029C, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0294->else_instructions;

                  body.emit(assign(r0284, r0283, 0x03));


               body.instructions = f0294_parent_instructions;
               body.emit(f0294);

               /* END IF */

               body.emit(assign(r022A, r0284, 0x03));

               body.emit(assign(r0229, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f027F->else_instructions;

               ir_variable *const r029F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r029F);
               ir_expression *const r02A0 = lshift(r0228, body.constant(int(31)));
               body.emit(assign(r029F, add(r02A0, body.constant(2146435072u)), 0x01));

               body.emit(assign(r029F, body.constant(0u), 0x02));

               body.emit(assign(r022A, r029F, 0x03));

               body.emit(assign(r0229, body.constant(false), 0x01));


            body.instructions = f027F_parent_instructions;
            body.emit(f027F);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f027D->else_instructions;

            /* IF CONDITION */
            ir_expression *const r02A2 = equal(r0232, body.constant(0u));
            ir_if *f02A1 = new(mem_ctx) ir_if(operand(r02A2).val);
            exec_list *const f02A1_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02A1->then_instructions;

               body.emit(assign(r022B, add(r022B, body.constant(int(1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f02A1->else_instructions;

               body.emit(assign(r022D, bit_or(swizzle_x(r0231), body.constant(1048576u)), 0x01));


            body.instructions = f02A1_parent_instructions;
            body.emit(f02A1);

            /* END IF */

            ir_variable *const r02A3 = body.make_temp(glsl_type::uint_type, "a0");
            body.emit(assign(r02A3, swizzle_x(r022D), 0x01));

            ir_variable *const r02A4 = body.make_temp(glsl_type::uint_type, "a1");
            body.emit(assign(r02A4, swizzle_y(r022D), 0x01));

            ir_variable *const r02A5 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r02A5, body.constant(0u), 0x01));

            ir_variable *const r02A6 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r02A6, neg(r022B), 0x01));

            ir_variable *const r02A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r02A7);
            ir_variable *const r02A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r02A8);
            ir_variable *const r02A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r02A9);
            ir_variable *const r02AA = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r02AB = neg(r02A6);
            body.emit(assign(r02AA, bit_and(r02AB, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02AD = equal(r02A6, body.constant(int(0)));
            ir_if *f02AC = new(mem_ctx) ir_if(operand(r02AD).val);
            exec_list *const f02AC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02AC->then_instructions;

               body.emit(assign(r02A7, r02A5, 0x01));

               body.emit(assign(r02A8, r02A4, 0x01));

               body.emit(assign(r02A9, r02A3, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f02AC->else_instructions;

               /* IF CONDITION */
               ir_expression *const r02AF = less(r02A6, body.constant(int(32)));
               ir_if *f02AE = new(mem_ctx) ir_if(operand(r02AF).val);
               exec_list *const f02AE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02AE->then_instructions;

                  body.emit(assign(r02A7, lshift(swizzle_y(r0231), r02AA), 0x01));

                  ir_expression *const r02B0 = lshift(swizzle_x(r022D), r02AA);
                  ir_expression *const r02B1 = rshift(swizzle_y(r0231), r02A6);
                  body.emit(assign(r02A8, bit_or(r02B0, r02B1), 0x01));

                  body.emit(assign(r02A9, rshift(swizzle_x(r022D), r02A6), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02AE->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r02B3 = equal(r02A6, body.constant(int(32)));
                  ir_if *f02B2 = new(mem_ctx) ir_if(operand(r02B3).val);
                  exec_list *const f02B2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02B2->then_instructions;

                     body.emit(assign(r02A7, r02A4, 0x01));

                     body.emit(assign(r02A8, r02A3, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f02B2->else_instructions;

                     body.emit(assign(r02A5, bit_or(body.constant(0u), swizzle_y(r0231)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r02B5 = less(r02A6, body.constant(int(64)));
                     ir_if *f02B4 = new(mem_ctx) ir_if(operand(r02B5).val);
                     exec_list *const f02B4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02B4->then_instructions;

                        body.emit(assign(r02A7, lshift(swizzle_x(r022D), r02AA), 0x01));

                        ir_expression *const r02B6 = bit_and(r02A6, body.constant(int(31)));
                        body.emit(assign(r02A8, rshift(swizzle_x(r022D), r02B6), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02B4->else_instructions;

                        ir_variable *const r02B7 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r02B9 = equal(r02A6, body.constant(int(64)));
                        ir_if *f02B8 = new(mem_ctx) ir_if(operand(r02B9).val);
                        exec_list *const f02B8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02B8->then_instructions;

                           body.emit(assign(r02B7, r02A3, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f02B8->else_instructions;

                           ir_expression *const r02BA = nequal(swizzle_x(r022D), body.constant(0u));
                           ir_expression *const r02BB = expr(ir_unop_b2i, r02BA);
                           body.emit(assign(r02B7, expr(ir_unop_i2u, r02BB), 0x01));


                        body.instructions = f02B8_parent_instructions;
                        body.emit(f02B8);

                        /* END IF */

                        body.emit(assign(r02A7, r02B7, 0x01));

                        body.emit(assign(r02A8, body.constant(0u), 0x01));


                     body.instructions = f02B4_parent_instructions;
                     body.emit(f02B4);

                     /* END IF */


                  body.instructions = f02B2_parent_instructions;
                  body.emit(f02B2);

                  /* END IF */

                  body.emit(assign(r02A9, body.constant(0u), 0x01));


               body.instructions = f02AE_parent_instructions;
               body.emit(f02AE);

               /* END IF */

               ir_expression *const r02BC = nequal(r02A5, body.constant(0u));
               ir_expression *const r02BD = expr(ir_unop_b2i, r02BC);
               ir_expression *const r02BE = expr(ir_unop_i2u, r02BD);
               body.emit(assign(r02A7, bit_or(r02A7, r02BE), 0x01));


            body.instructions = f02AC_parent_instructions;
            body.emit(f02AC);

            /* END IF */

            body.emit(assign(r022D, r02A9, 0x01));

            body.emit(assign(r022D, r02A8, 0x02));

            body.emit(assign(r022F, r02A7, 0x01));

            body.emit(assign(r022E, r0235, 0x01));


         body.instructions = f027D_parent_instructions;
         body.emit(f027D);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f027B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r02C0 = equal(r0232, body.constant(2047u));
         ir_if *f02BF = new(mem_ctx) ir_if(operand(r02C0).val);
         exec_list *const f02BF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02BF->then_instructions;

            /* IF CONDITION */
            ir_expression *const r02C2 = bit_or(swizzle_x(r022D), swizzle_y(r022D));
            ir_expression *const r02C3 = bit_or(swizzle_x(r022C), swizzle_y(r022C));
            ir_expression *const r02C4 = bit_or(r02C2, r02C3);
            ir_expression *const r02C5 = nequal(r02C4, body.constant(0u));
            ir_if *f02C1 = new(mem_ctx) ir_if(operand(r02C5).val);
            exec_list *const f02C1_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02C1->then_instructions;

               ir_variable *const r02C6 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r02C6, swizzle_x(r0226), 0x01));

               ir_variable *const r02C7 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r02C7, swizzle_x(r0227), 0x01));

               ir_variable *const r02C8 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r02C9 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
               ir_expression *const r02CA = rshift(swizzle_y(r0226), body.constant(int(19)));
               ir_expression *const r02CB = bit_and(r02CA, body.constant(4095u));
               ir_expression *const r02CC = equal(r02CB, body.constant(4094u));
               ir_expression *const r02CD = nequal(swizzle_x(r0226), body.constant(0u));
               ir_expression *const r02CE = bit_and(swizzle_y(r0226), body.constant(524287u));
               ir_expression *const r02CF = nequal(r02CE, body.constant(0u));
               ir_expression *const r02D0 = logic_or(r02CD, r02CF);
               body.emit(assign(r02C9, logic_and(r02CC, r02D0), 0x01));

               ir_variable *const r02D1 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r02D2 = lshift(swizzle_y(r0227), body.constant(int(1)));
               ir_expression *const r02D3 = lequal(body.constant(4292870144u), r02D2);
               ir_expression *const r02D4 = nequal(swizzle_x(r0227), body.constant(0u));
               ir_expression *const r02D5 = bit_and(swizzle_y(r0227), body.constant(1048575u));
               ir_expression *const r02D6 = nequal(r02D5, body.constant(0u));
               ir_expression *const r02D7 = logic_or(r02D4, r02D6);
               body.emit(assign(r02D1, logic_and(r02D3, r02D7), 0x01));

               body.emit(assign(r02C6, bit_or(swizzle_y(r0226), body.constant(524288u)), 0x02));

               body.emit(assign(r02C7, bit_or(swizzle_y(r0227), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r02D9 = lshift(swizzle_y(r0226), body.constant(int(1)));
               ir_expression *const r02DA = lequal(body.constant(4292870144u), r02D9);
               ir_expression *const r02DB = nequal(swizzle_x(r0226), body.constant(0u));
               ir_expression *const r02DC = bit_and(swizzle_y(r0226), body.constant(1048575u));
               ir_expression *const r02DD = nequal(r02DC, body.constant(0u));
               ir_expression *const r02DE = logic_or(r02DB, r02DD);
               ir_expression *const r02DF = logic_and(r02DA, r02DE);
               ir_if *f02D8 = new(mem_ctx) ir_if(operand(r02DF).val);
               exec_list *const f02D8_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02D8->then_instructions;

                  ir_variable *const r02E0 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r02E2 = logic_and(r02C9, r02D1);
                  ir_if *f02E1 = new(mem_ctx) ir_if(operand(r02E2).val);
                  exec_list *const f02E1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02E1->then_instructions;

                     body.emit(assign(r02E0, r02C7, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f02E1->else_instructions;

                     body.emit(assign(r02E0, r02C6, 0x03));


                  body.instructions = f02E1_parent_instructions;
                  body.emit(f02E1);

                  /* END IF */

                  body.emit(assign(r02C8, r02E0, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02D8->else_instructions;

                  body.emit(assign(r02C8, r02C7, 0x03));


               body.instructions = f02D8_parent_instructions;
               body.emit(f02D8);

               /* END IF */

               body.emit(assign(r022A, r02C8, 0x03));

               body.emit(assign(r0229, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f02C1->else_instructions;

               body.emit(assign(r022A, r0226, 0x03));

               body.emit(assign(r0229, body.constant(false), 0x01));


            body.instructions = f02C1_parent_instructions;
            body.emit(f02C1);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02BF->else_instructions;

            ir_variable *const r02E3 = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r02E4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            body.emit(assign(r02E4, add(swizzle_y(r022D), swizzle_y(r022C)), 0x01));

            ir_expression *const r02E5 = add(swizzle_x(r022D), swizzle_x(r022C));
            ir_expression *const r02E6 = less(r02E4, swizzle_y(r022D));
            ir_expression *const r02E7 = expr(ir_unop_b2i, r02E6);
            ir_expression *const r02E8 = expr(ir_unop_i2u, r02E7);
            body.emit(assign(r02E3, add(r02E5, r02E8), 0x01));

            body.emit(assign(r0230, r02E3, 0x01));

            /* IF CONDITION */
            ir_expression *const r02EA = equal(r0232, body.constant(0u));
            ir_if *f02E9 = new(mem_ctx) ir_if(operand(r02EA).val);
            exec_list *const f02E9_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02E9->then_instructions;

               ir_variable *const r02EB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r02EB);
               ir_expression *const r02EC = lshift(r0228, body.constant(int(31)));
               body.emit(assign(r02EB, add(r02EC, r02E3), 0x01));

               body.emit(assign(r02EB, r02E4, 0x02));

               body.emit(assign(r022A, r02EB, 0x03));

               body.emit(assign(r0229, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f02E9->else_instructions;

               body.emit(assign(r0230, bit_or(r02E3, body.constant(2097152u)), 0x01));

               body.emit(assign(r022E, r0232, 0x01));

               ir_variable *const r02ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r02ED);
               ir_variable *const r02EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r02EE);
               ir_variable *const r02EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r02EF);
               body.emit(assign(r02ED, lshift(r02E4, body.constant(int(31))), 0x01));

               ir_expression *const r02F0 = lshift(r0230, body.constant(int(31)));
               ir_expression *const r02F1 = rshift(r02E4, body.constant(int(1)));
               body.emit(assign(r02EE, bit_or(r02F0, r02F1), 0x01));

               body.emit(assign(r02EF, rshift(r0230, body.constant(int(1))), 0x01));

               body.emit(assign(r02ED, bit_or(r02ED, body.constant(0u)), 0x01));

               body.emit(assign(r0230, r02EF, 0x01));

               body.emit(assign(r022F, r02ED, 0x01));

               ir_variable *const r02F2 = body.make_temp(glsl_type::uint_type, "zExp");
               body.emit(assign(r02F2, r0232, 0x01));

               ir_variable *const r02F3 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r02F3, r02EF, 0x01));

               ir_variable *const r02F4 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r02F4, r02EE, 0x01));

               ir_variable *const r02F5 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r02F5, r02ED, 0x01));

               ir_variable *const r02F6 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r02F6, body.constant(true), 0x01));

               ir_variable *const r02F7 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r02F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
               body.emit(r02F8);
               ir_expression *const r02F9 = less(r02ED, body.constant(0u));
               ir_expression *const r02FA = expr(ir_unop_b2i, r02F9);
               body.emit(assign(r02F8, expr(ir_unop_i2u, r02FA), 0x01));

               /* IF CONDITION */
               ir_expression *const r02FC = lequal(body.constant(2045u), r0232);
               ir_if *f02FB = new(mem_ctx) ir_if(operand(r02FC).val);
               exec_list *const f02FB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02FB->then_instructions;

                  ir_variable *const r02FD = body.make_temp(glsl_type::bool_type, "or_tmp");
                  /* IF CONDITION */
                  ir_expression *const r02FF = less(body.constant(2045u), r0232);
                  ir_if *f02FE = new(mem_ctx) ir_if(operand(r02FF).val);
                  exec_list *const f02FE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02FE->then_instructions;

                     body.emit(assign(r02FD, body.constant(true), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f02FE->else_instructions;

                     ir_variable *const r0300 = body.make_temp(glsl_type::bool_type, "and_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0302 = equal(r0232, body.constant(2045u));
                     ir_if *f0301 = new(mem_ctx) ir_if(operand(r0302).val);
                     exec_list *const f0301_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0301->then_instructions;

                        ir_expression *const r0303 = equal(body.constant(2097151u), r02EF);
                        ir_expression *const r0304 = equal(body.constant(4294967295u), r02EE);
                        body.emit(assign(r0300, logic_and(r0303, r0304), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0301->else_instructions;

                        body.emit(assign(r0300, body.constant(false), 0x01));


                     body.instructions = f0301_parent_instructions;
                     body.emit(f0301);

                     /* END IF */

                     ir_expression *const r0305 = nequal(r02F8, body.constant(0u));
                     body.emit(assign(r02FD, logic_and(r0300, r0305), 0x01));


                  body.instructions = f02FE_parent_instructions;
                  body.emit(f02FE);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0306 = new(mem_ctx) ir_if(operand(r02FD).val);
                  exec_list *const f0306_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0306->then_instructions;

                     ir_variable *const r0307 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0307);
                     ir_expression *const r0308 = lshift(r0228, body.constant(int(31)));
                     body.emit(assign(r0307, add(r0308, body.constant(2146435072u)), 0x01));

                     body.emit(assign(r0307, body.constant(0u), 0x02));

                     body.emit(assign(r02F7, r0307, 0x03));

                     body.emit(assign(r02F6, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0306->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r030A = less(r0232, body.constant(0u));
                     ir_if *f0309 = new(mem_ctx) ir_if(operand(r030A).val);
                     exec_list *const f0309_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0309->then_instructions;

                        ir_variable *const r030B = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r030B, r02ED, 0x01));

                        ir_variable *const r030C = body.make_temp(glsl_type::int_type, "count");
                        ir_expression *const r030D = neg(r0232);
                        body.emit(assign(r030C, expr(ir_unop_u2i, r030D), 0x01));

                        ir_variable *const r030E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r030E);
                        ir_variable *const r030F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r030F);
                        ir_variable *const r0310 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0310);
                        ir_variable *const r0311 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0312 = neg(r030C);
                        body.emit(assign(r0311, bit_and(r0312, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0314 = equal(r030C, body.constant(int(0)));
                        ir_if *f0313 = new(mem_ctx) ir_if(operand(r0314).val);
                        exec_list *const f0313_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0313->then_instructions;

                           body.emit(assign(r030E, r02ED, 0x01));

                           body.emit(assign(r030F, r02EE, 0x01));

                           body.emit(assign(r0310, r02EF, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0313->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0316 = less(r030C, body.constant(int(32)));
                           ir_if *f0315 = new(mem_ctx) ir_if(operand(r0316).val);
                           exec_list *const f0315_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0315->then_instructions;

                              body.emit(assign(r030E, lshift(r02EE, r0311), 0x01));

                              ir_expression *const r0317 = lshift(r02EF, r0311);
                              ir_expression *const r0318 = rshift(r02EE, r030C);
                              body.emit(assign(r030F, bit_or(r0317, r0318), 0x01));

                              body.emit(assign(r0310, rshift(r02EF, r030C), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0315->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r031A = equal(r030C, body.constant(int(32)));
                              ir_if *f0319 = new(mem_ctx) ir_if(operand(r031A).val);
                              exec_list *const f0319_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0319->then_instructions;

                                 body.emit(assign(r030E, r02EE, 0x01));

                                 body.emit(assign(r030F, r02EF, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0319->else_instructions;

                                 body.emit(assign(r030B, bit_or(r02ED, r02EE), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r031C = less(r030C, body.constant(int(64)));
                                 ir_if *f031B = new(mem_ctx) ir_if(operand(r031C).val);
                                 exec_list *const f031B_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f031B->then_instructions;

                                    body.emit(assign(r030E, lshift(r02EF, r0311), 0x01));

                                    ir_expression *const r031D = bit_and(r030C, body.constant(int(31)));
                                    body.emit(assign(r030F, rshift(r02EF, r031D), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f031B->else_instructions;

                                    ir_variable *const r031E = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r0320 = equal(r030C, body.constant(int(64)));
                                    ir_if *f031F = new(mem_ctx) ir_if(operand(r0320).val);
                                    exec_list *const f031F_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f031F->then_instructions;

                                       body.emit(assign(r031E, r02EF, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f031F->else_instructions;

                                       ir_expression *const r0321 = nequal(r02EF, body.constant(0u));
                                       ir_expression *const r0322 = expr(ir_unop_b2i, r0321);
                                       body.emit(assign(r031E, expr(ir_unop_i2u, r0322), 0x01));


                                    body.instructions = f031F_parent_instructions;
                                    body.emit(f031F);

                                    /* END IF */

                                    body.emit(assign(r030E, r031E, 0x01));

                                    body.emit(assign(r030F, body.constant(0u), 0x01));


                                 body.instructions = f031B_parent_instructions;
                                 body.emit(f031B);

                                 /* END IF */


                              body.instructions = f0319_parent_instructions;
                              body.emit(f0319);

                              /* END IF */

                              body.emit(assign(r0310, body.constant(0u), 0x01));


                           body.instructions = f0315_parent_instructions;
                           body.emit(f0315);

                           /* END IF */

                           ir_expression *const r0323 = nequal(r030B, body.constant(0u));
                           ir_expression *const r0324 = expr(ir_unop_b2i, r0323);
                           ir_expression *const r0325 = expr(ir_unop_i2u, r0324);
                           body.emit(assign(r030E, bit_or(r030E, r0325), 0x01));


                        body.instructions = f0313_parent_instructions;
                        body.emit(f0313);

                        /* END IF */

                        body.emit(assign(r02F3, r0310, 0x01));

                        body.emit(assign(r02F4, r030F, 0x01));

                        body.emit(assign(r02F5, r030E, 0x01));

                        body.emit(assign(r02F2, body.constant(0u), 0x01));

                        ir_expression *const r0326 = less(r030E, body.constant(0u));
                        ir_expression *const r0327 = expr(ir_unop_b2i, r0326);
                        body.emit(assign(r02F8, expr(ir_unop_i2u, r0327), 0x01));


                     body.instructions = f0309_parent_instructions;
                     body.emit(f0309);

                     /* END IF */


                  body.instructions = f0306_parent_instructions;
                  body.emit(f0306);

                  /* END IF */


               body.instructions = f02FB_parent_instructions;
               body.emit(f02FB);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0328 = new(mem_ctx) ir_if(operand(r02F6).val);
               exec_list *const f0328_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0328->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r032A = nequal(r02F8, body.constant(0u));
                  ir_if *f0329 = new(mem_ctx) ir_if(operand(r032A).val);
                  exec_list *const f0329_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0329->then_instructions;

                     ir_variable *const r032B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r032B, add(r02F4, body.constant(1u)), 0x01));

                     ir_expression *const r032C = less(r032B, r02F4);
                     ir_expression *const r032D = expr(ir_unop_b2i, r032C);
                     ir_expression *const r032E = expr(ir_unop_i2u, r032D);
                     body.emit(assign(r02F3, add(r02F3, r032E), 0x01));

                     ir_expression *const r032F = neg(r02F5);
                     ir_expression *const r0330 = equal(r02F5, r032F);
                     ir_expression *const r0331 = expr(ir_unop_b2i, r0330);
                     ir_expression *const r0332 = expr(ir_unop_i2u, r0331);
                     ir_expression *const r0333 = bit_and(r0332, body.constant(1u));
                     ir_expression *const r0334 = expr(ir_unop_bit_not, r0333);
                     body.emit(assign(r02F4, bit_and(r032B, r0334), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0329->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0336 = bit_or(r02F3, r02F4);
                     ir_expression *const r0337 = equal(r0336, body.constant(0u));
                     ir_if *f0335 = new(mem_ctx) ir_if(operand(r0337).val);
                     exec_list *const f0335_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0335->then_instructions;

                        body.emit(assign(r02F2, body.constant(0u), 0x01));


                     body.instructions = f0335_parent_instructions;
                     body.emit(f0335);

                     /* END IF */


                  body.instructions = f0329_parent_instructions;
                  body.emit(f0329);

                  /* END IF */

                  ir_variable *const r0338 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0338);
                  ir_expression *const r0339 = lshift(r0228, body.constant(int(31)));
                  ir_expression *const r033A = lshift(r02F2, body.constant(int(20)));
                  ir_expression *const r033B = add(r0339, r033A);
                  body.emit(assign(r0338, add(r033B, r02F3), 0x01));

                  body.emit(assign(r0338, r02F4, 0x02));

                  body.emit(assign(r02F7, r0338, 0x03));

                  body.emit(assign(r02F6, body.constant(false), 0x01));


               body.instructions = f0328_parent_instructions;
               body.emit(f0328);

               /* END IF */

               body.emit(assign(r022A, r02F7, 0x03));

               body.emit(assign(r0229, body.constant(false), 0x01));


            body.instructions = f02E9_parent_instructions;
            body.emit(f02E9);

            /* END IF */


         body.instructions = f02BF_parent_instructions;
         body.emit(f02BF);

         /* END IF */


      body.instructions = f027B_parent_instructions;
      body.emit(f027B);

      /* END IF */


   body.instructions = f023A_parent_instructions;
   body.emit(f023A);

   /* END IF */

   /* IF CONDITION */
   ir_if *f033C = new(mem_ctx) ir_if(operand(r0229).val);
   exec_list *const f033C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f033C->then_instructions;

      body.emit(assign(r022D, bit_or(swizzle_x(r022D), body.constant(1048576u)), 0x01));

      ir_variable *const r033D = body.make_temp(glsl_type::uint_type, "z0Ptr");
      ir_variable *const r033E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r033E, add(swizzle_y(r022D), swizzle_y(r022C)), 0x01));

      ir_expression *const r033F = add(swizzle_x(r022D), swizzle_x(r022C));
      ir_expression *const r0340 = less(r033E, swizzle_y(r022D));
      ir_expression *const r0341 = expr(ir_unop_b2i, r0340);
      ir_expression *const r0342 = expr(ir_unop_i2u, r0341);
      body.emit(assign(r033D, add(r033F, r0342), 0x01));

      body.emit(assign(r0230, r033D, 0x01));

      body.emit(assign(r022E, add(r022E, body.constant(4294967295u)), 0x01));

      /* IF CONDITION */
      ir_expression *const r0344 = less(r033D, body.constant(2097152u));
      ir_if *f0343 = new(mem_ctx) ir_if(operand(r0344).val);
      exec_list *const f0343_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0343->then_instructions;

         ir_variable *const r0345 = body.make_temp(glsl_type::uint_type, "zExp");
         body.emit(assign(r0345, r022E, 0x01));

         ir_variable *const r0346 = body.make_temp(glsl_type::uint_type, "zFrac0");
         body.emit(assign(r0346, r033D, 0x01));

         ir_variable *const r0347 = body.make_temp(glsl_type::uint_type, "zFrac1");
         body.emit(assign(r0347, r033E, 0x01));

         ir_variable *const r0348 = body.make_temp(glsl_type::uint_type, "zFrac2");
         body.emit(assign(r0348, r022F, 0x01));

         ir_variable *const r0349 = body.make_temp(glsl_type::bool_type, "execute_flag");
         body.emit(assign(r0349, body.constant(true), 0x01));

         ir_variable *const r034A = body.make_temp(glsl_type::uvec2_type, "return_value");
         ir_variable *const r034B = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
         body.emit(r034B);
         ir_expression *const r034C = less(r022F, body.constant(0u));
         ir_expression *const r034D = expr(ir_unop_b2i, r034C);
         body.emit(assign(r034B, expr(ir_unop_i2u, r034D), 0x01));

         /* IF CONDITION */
         ir_expression *const r034F = lequal(body.constant(2045u), r022E);
         ir_if *f034E = new(mem_ctx) ir_if(operand(r034F).val);
         exec_list *const f034E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f034E->then_instructions;

            ir_variable *const r0350 = body.make_temp(glsl_type::bool_type, "or_tmp");
            /* IF CONDITION */
            ir_expression *const r0352 = less(body.constant(2045u), r022E);
            ir_if *f0351 = new(mem_ctx) ir_if(operand(r0352).val);
            exec_list *const f0351_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0351->then_instructions;

               body.emit(assign(r0350, body.constant(true), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0351->else_instructions;

               ir_variable *const r0353 = body.make_temp(glsl_type::bool_type, "and_tmp");
               /* IF CONDITION */
               ir_expression *const r0355 = equal(r022E, body.constant(2045u));
               ir_if *f0354 = new(mem_ctx) ir_if(operand(r0355).val);
               exec_list *const f0354_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0354->then_instructions;

                  ir_expression *const r0356 = equal(body.constant(2097151u), r033D);
                  ir_expression *const r0357 = equal(body.constant(4294967295u), r033E);
                  body.emit(assign(r0353, logic_and(r0356, r0357), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0354->else_instructions;

                  body.emit(assign(r0353, body.constant(false), 0x01));


               body.instructions = f0354_parent_instructions;
               body.emit(f0354);

               /* END IF */

               ir_expression *const r0358 = nequal(r034B, body.constant(0u));
               body.emit(assign(r0350, logic_and(r0353, r0358), 0x01));


            body.instructions = f0351_parent_instructions;
            body.emit(f0351);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0359 = new(mem_ctx) ir_if(operand(r0350).val);
            exec_list *const f0359_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0359->then_instructions;

               ir_variable *const r035A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r035A);
               ir_expression *const r035B = lshift(r0228, body.constant(int(31)));
               body.emit(assign(r035A, add(r035B, body.constant(2146435072u)), 0x01));

               body.emit(assign(r035A, body.constant(0u), 0x02));

               body.emit(assign(r034A, r035A, 0x03));

               body.emit(assign(r0349, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0359->else_instructions;

               /* IF CONDITION */
               ir_expression *const r035D = less(r022E, body.constant(0u));
               ir_if *f035C = new(mem_ctx) ir_if(operand(r035D).val);
               exec_list *const f035C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f035C->then_instructions;

                  ir_variable *const r035E = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r035E, r022F, 0x01));

                  ir_variable *const r035F = body.make_temp(glsl_type::int_type, "count");
                  ir_expression *const r0360 = neg(r022E);
                  body.emit(assign(r035F, expr(ir_unop_u2i, r0360), 0x01));

                  ir_variable *const r0361 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0361);
                  ir_variable *const r0362 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r0362);
                  ir_variable *const r0363 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r0363);
                  ir_variable *const r0364 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r0365 = neg(r035F);
                  body.emit(assign(r0364, bit_and(r0365, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0367 = equal(r035F, body.constant(int(0)));
                  ir_if *f0366 = new(mem_ctx) ir_if(operand(r0367).val);
                  exec_list *const f0366_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0366->then_instructions;

                     body.emit(assign(r0361, r022F, 0x01));

                     body.emit(assign(r0362, r033E, 0x01));

                     body.emit(assign(r0363, r033D, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0366->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0369 = less(r035F, body.constant(int(32)));
                     ir_if *f0368 = new(mem_ctx) ir_if(operand(r0369).val);
                     exec_list *const f0368_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0368->then_instructions;

                        body.emit(assign(r0361, lshift(r033E, r0364), 0x01));

                        ir_expression *const r036A = lshift(r033D, r0364);
                        ir_expression *const r036B = rshift(r033E, r035F);
                        body.emit(assign(r0362, bit_or(r036A, r036B), 0x01));

                        body.emit(assign(r0363, rshift(r033D, r035F), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0368->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r036D = equal(r035F, body.constant(int(32)));
                        ir_if *f036C = new(mem_ctx) ir_if(operand(r036D).val);
                        exec_list *const f036C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f036C->then_instructions;

                           body.emit(assign(r0361, r033E, 0x01));

                           body.emit(assign(r0362, r033D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f036C->else_instructions;

                           body.emit(assign(r035E, bit_or(r022F, r033E), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r036F = less(r035F, body.constant(int(64)));
                           ir_if *f036E = new(mem_ctx) ir_if(operand(r036F).val);
                           exec_list *const f036E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f036E->then_instructions;

                              body.emit(assign(r0361, lshift(r033D, r0364), 0x01));

                              ir_expression *const r0370 = bit_and(r035F, body.constant(int(31)));
                              body.emit(assign(r0362, rshift(r033D, r0370), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f036E->else_instructions;

                              ir_variable *const r0371 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r0373 = equal(r035F, body.constant(int(64)));
                              ir_if *f0372 = new(mem_ctx) ir_if(operand(r0373).val);
                              exec_list *const f0372_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0372->then_instructions;

                                 body.emit(assign(r0371, r033D, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0372->else_instructions;

                                 ir_expression *const r0374 = nequal(r033D, body.constant(0u));
                                 ir_expression *const r0375 = expr(ir_unop_b2i, r0374);
                                 body.emit(assign(r0371, expr(ir_unop_i2u, r0375), 0x01));


                              body.instructions = f0372_parent_instructions;
                              body.emit(f0372);

                              /* END IF */

                              body.emit(assign(r0361, r0371, 0x01));

                              body.emit(assign(r0362, body.constant(0u), 0x01));


                           body.instructions = f036E_parent_instructions;
                           body.emit(f036E);

                           /* END IF */


                        body.instructions = f036C_parent_instructions;
                        body.emit(f036C);

                        /* END IF */

                        body.emit(assign(r0363, body.constant(0u), 0x01));


                     body.instructions = f0368_parent_instructions;
                     body.emit(f0368);

                     /* END IF */

                     ir_expression *const r0376 = nequal(r035E, body.constant(0u));
                     ir_expression *const r0377 = expr(ir_unop_b2i, r0376);
                     ir_expression *const r0378 = expr(ir_unop_i2u, r0377);
                     body.emit(assign(r0361, bit_or(r0361, r0378), 0x01));


                  body.instructions = f0366_parent_instructions;
                  body.emit(f0366);

                  /* END IF */

                  body.emit(assign(r0346, r0363, 0x01));

                  body.emit(assign(r0347, r0362, 0x01));

                  body.emit(assign(r0348, r0361, 0x01));

                  body.emit(assign(r0345, body.constant(0u), 0x01));

                  ir_expression *const r0379 = less(r0361, body.constant(0u));
                  ir_expression *const r037A = expr(ir_unop_b2i, r0379);
                  body.emit(assign(r034B, expr(ir_unop_i2u, r037A), 0x01));


               body.instructions = f035C_parent_instructions;
               body.emit(f035C);

               /* END IF */


            body.instructions = f0359_parent_instructions;
            body.emit(f0359);

            /* END IF */


         body.instructions = f034E_parent_instructions;
         body.emit(f034E);

         /* END IF */

         /* IF CONDITION */
         ir_if *f037B = new(mem_ctx) ir_if(operand(r0349).val);
         exec_list *const f037B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f037B->then_instructions;

            /* IF CONDITION */
            ir_expression *const r037D = nequal(r034B, body.constant(0u));
            ir_if *f037C = new(mem_ctx) ir_if(operand(r037D).val);
            exec_list *const f037C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f037C->then_instructions;

               ir_variable *const r037E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r037E, add(r0347, body.constant(1u)), 0x01));

               ir_expression *const r037F = less(r037E, r0347);
               ir_expression *const r0380 = expr(ir_unop_b2i, r037F);
               ir_expression *const r0381 = expr(ir_unop_i2u, r0380);
               body.emit(assign(r0346, add(r0346, r0381), 0x01));

               ir_expression *const r0382 = neg(r0348);
               ir_expression *const r0383 = equal(r0348, r0382);
               ir_expression *const r0384 = expr(ir_unop_b2i, r0383);
               ir_expression *const r0385 = expr(ir_unop_i2u, r0384);
               ir_expression *const r0386 = bit_and(r0385, body.constant(1u));
               ir_expression *const r0387 = expr(ir_unop_bit_not, r0386);
               body.emit(assign(r0347, bit_and(r037E, r0387), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f037C->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0389 = bit_or(r0346, r0347);
               ir_expression *const r038A = equal(r0389, body.constant(0u));
               ir_if *f0388 = new(mem_ctx) ir_if(operand(r038A).val);
               exec_list *const f0388_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0388->then_instructions;

                  body.emit(assign(r0345, body.constant(0u), 0x01));


               body.instructions = f0388_parent_instructions;
               body.emit(f0388);

               /* END IF */


            body.instructions = f037C_parent_instructions;
            body.emit(f037C);

            /* END IF */

            ir_variable *const r038B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r038B);
            ir_expression *const r038C = lshift(r0228, body.constant(int(31)));
            ir_expression *const r038D = lshift(r0345, body.constant(int(20)));
            ir_expression *const r038E = add(r038C, r038D);
            body.emit(assign(r038B, add(r038E, r0346), 0x01));

            body.emit(assign(r038B, r0347, 0x02));

            body.emit(assign(r034A, r038B, 0x03));

            body.emit(assign(r0349, body.constant(false), 0x01));


         body.instructions = f037B_parent_instructions;
         body.emit(f037B);

         /* END IF */

         body.emit(assign(r022A, r034A, 0x03));

         body.emit(assign(r0229, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0343->else_instructions;

         body.emit(assign(r022E, add(r022E, body.constant(1u)), 0x01));

         ir_variable *const r038F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
         body.emit(r038F);
         ir_variable *const r0390 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
         body.emit(r0390);
         ir_variable *const r0391 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
         body.emit(r0391);
         body.emit(assign(r038F, lshift(r033E, body.constant(int(31))), 0x01));

         ir_expression *const r0392 = lshift(r033D, body.constant(int(31)));
         ir_expression *const r0393 = rshift(r033E, body.constant(int(1)));
         body.emit(assign(r0390, bit_or(r0392, r0393), 0x01));

         body.emit(assign(r0391, rshift(r033D, body.constant(int(1))), 0x01));

         ir_expression *const r0394 = nequal(r022F, body.constant(0u));
         ir_expression *const r0395 = expr(ir_unop_b2i, r0394);
         ir_expression *const r0396 = expr(ir_unop_i2u, r0395);
         body.emit(assign(r038F, bit_or(r038F, r0396), 0x01));

         body.emit(assign(r0230, r0391, 0x01));

         body.emit(assign(r022F, r038F, 0x01));

         ir_variable *const r0397 = body.make_temp(glsl_type::uint_type, "zExp");
         body.emit(assign(r0397, r022E, 0x01));

         ir_variable *const r0398 = body.make_temp(glsl_type::uint_type, "zFrac0");
         body.emit(assign(r0398, r0391, 0x01));

         ir_variable *const r0399 = body.make_temp(glsl_type::uint_type, "zFrac1");
         body.emit(assign(r0399, r0390, 0x01));

         ir_variable *const r039A = body.make_temp(glsl_type::uint_type, "zFrac2");
         body.emit(assign(r039A, r038F, 0x01));

         ir_variable *const r039B = body.make_temp(glsl_type::bool_type, "execute_flag");
         body.emit(assign(r039B, body.constant(true), 0x01));

         ir_variable *const r039C = body.make_temp(glsl_type::uvec2_type, "return_value");
         ir_variable *const r039D = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
         body.emit(r039D);
         ir_expression *const r039E = less(r038F, body.constant(0u));
         ir_expression *const r039F = expr(ir_unop_b2i, r039E);
         body.emit(assign(r039D, expr(ir_unop_i2u, r039F), 0x01));

         /* IF CONDITION */
         ir_expression *const r03A1 = lequal(body.constant(2045u), r022E);
         ir_if *f03A0 = new(mem_ctx) ir_if(operand(r03A1).val);
         exec_list *const f03A0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f03A0->then_instructions;

            ir_variable *const r03A2 = body.make_temp(glsl_type::bool_type, "or_tmp");
            /* IF CONDITION */
            ir_expression *const r03A4 = less(body.constant(2045u), r022E);
            ir_if *f03A3 = new(mem_ctx) ir_if(operand(r03A4).val);
            exec_list *const f03A3_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03A3->then_instructions;

               body.emit(assign(r03A2, body.constant(true), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03A3->else_instructions;

               ir_variable *const r03A5 = body.make_temp(glsl_type::bool_type, "and_tmp");
               /* IF CONDITION */
               ir_expression *const r03A7 = equal(r022E, body.constant(2045u));
               ir_if *f03A6 = new(mem_ctx) ir_if(operand(r03A7).val);
               exec_list *const f03A6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03A6->then_instructions;

                  ir_expression *const r03A8 = equal(body.constant(2097151u), r0391);
                  ir_expression *const r03A9 = equal(body.constant(4294967295u), r0390);
                  body.emit(assign(r03A5, logic_and(r03A8, r03A9), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03A6->else_instructions;

                  body.emit(assign(r03A5, body.constant(false), 0x01));


               body.instructions = f03A6_parent_instructions;
               body.emit(f03A6);

               /* END IF */

               ir_expression *const r03AA = nequal(r039D, body.constant(0u));
               body.emit(assign(r03A2, logic_and(r03A5, r03AA), 0x01));


            body.instructions = f03A3_parent_instructions;
            body.emit(f03A3);

            /* END IF */

            /* IF CONDITION */
            ir_if *f03AB = new(mem_ctx) ir_if(operand(r03A2).val);
            exec_list *const f03AB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03AB->then_instructions;

               ir_variable *const r03AC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r03AC);
               ir_expression *const r03AD = lshift(r0228, body.constant(int(31)));
               body.emit(assign(r03AC, add(r03AD, body.constant(2146435072u)), 0x01));

               body.emit(assign(r03AC, body.constant(0u), 0x02));

               body.emit(assign(r039C, r03AC, 0x03));

               body.emit(assign(r039B, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03AB->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03AF = less(r022E, body.constant(0u));
               ir_if *f03AE = new(mem_ctx) ir_if(operand(r03AF).val);
               exec_list *const f03AE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03AE->then_instructions;

                  ir_variable *const r03B0 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r03B0, r038F, 0x01));

                  ir_variable *const r03B1 = body.make_temp(glsl_type::int_type, "count");
                  ir_expression *const r03B2 = neg(r022E);
                  body.emit(assign(r03B1, expr(ir_unop_u2i, r03B2), 0x01));

                  ir_variable *const r03B3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r03B3);
                  ir_variable *const r03B4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r03B4);
                  ir_variable *const r03B5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r03B5);
                  ir_variable *const r03B6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r03B7 = neg(r03B1);
                  body.emit(assign(r03B6, bit_and(r03B7, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r03B9 = equal(r03B1, body.constant(int(0)));
                  ir_if *f03B8 = new(mem_ctx) ir_if(operand(r03B9).val);
                  exec_list *const f03B8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03B8->then_instructions;

                     body.emit(assign(r03B3, r038F, 0x01));

                     body.emit(assign(r03B4, r0390, 0x01));

                     body.emit(assign(r03B5, r0391, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03B8->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03BB = less(r03B1, body.constant(int(32)));
                     ir_if *f03BA = new(mem_ctx) ir_if(operand(r03BB).val);
                     exec_list *const f03BA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03BA->then_instructions;

                        body.emit(assign(r03B3, lshift(r0390, r03B6), 0x01));

                        ir_expression *const r03BC = lshift(r0391, r03B6);
                        ir_expression *const r03BD = rshift(r0390, r03B1);
                        body.emit(assign(r03B4, bit_or(r03BC, r03BD), 0x01));

                        body.emit(assign(r03B5, rshift(r0391, r03B1), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03BA->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r03BF = equal(r03B1, body.constant(int(32)));
                        ir_if *f03BE = new(mem_ctx) ir_if(operand(r03BF).val);
                        exec_list *const f03BE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f03BE->then_instructions;

                           body.emit(assign(r03B3, r0390, 0x01));

                           body.emit(assign(r03B4, r0391, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f03BE->else_instructions;

                           body.emit(assign(r03B0, bit_or(r038F, r0390), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r03C1 = less(r03B1, body.constant(int(64)));
                           ir_if *f03C0 = new(mem_ctx) ir_if(operand(r03C1).val);
                           exec_list *const f03C0_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f03C0->then_instructions;

                              body.emit(assign(r03B3, lshift(r0391, r03B6), 0x01));

                              ir_expression *const r03C2 = bit_and(r03B1, body.constant(int(31)));
                              body.emit(assign(r03B4, rshift(r0391, r03C2), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f03C0->else_instructions;

                              ir_variable *const r03C3 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r03C5 = equal(r03B1, body.constant(int(64)));
                              ir_if *f03C4 = new(mem_ctx) ir_if(operand(r03C5).val);
                              exec_list *const f03C4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f03C4->then_instructions;

                                 body.emit(assign(r03C3, r0391, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f03C4->else_instructions;

                                 ir_expression *const r03C6 = nequal(r0391, body.constant(0u));
                                 ir_expression *const r03C7 = expr(ir_unop_b2i, r03C6);
                                 body.emit(assign(r03C3, expr(ir_unop_i2u, r03C7), 0x01));


                              body.instructions = f03C4_parent_instructions;
                              body.emit(f03C4);

                              /* END IF */

                              body.emit(assign(r03B3, r03C3, 0x01));

                              body.emit(assign(r03B4, body.constant(0u), 0x01));


                           body.instructions = f03C0_parent_instructions;
                           body.emit(f03C0);

                           /* END IF */


                        body.instructions = f03BE_parent_instructions;
                        body.emit(f03BE);

                        /* END IF */

                        body.emit(assign(r03B5, body.constant(0u), 0x01));


                     body.instructions = f03BA_parent_instructions;
                     body.emit(f03BA);

                     /* END IF */

                     ir_expression *const r03C8 = nequal(r03B0, body.constant(0u));
                     ir_expression *const r03C9 = expr(ir_unop_b2i, r03C8);
                     ir_expression *const r03CA = expr(ir_unop_i2u, r03C9);
                     body.emit(assign(r03B3, bit_or(r03B3, r03CA), 0x01));


                  body.instructions = f03B8_parent_instructions;
                  body.emit(f03B8);

                  /* END IF */

                  body.emit(assign(r0398, r03B5, 0x01));

                  body.emit(assign(r0399, r03B4, 0x01));

                  body.emit(assign(r039A, r03B3, 0x01));

                  body.emit(assign(r0397, body.constant(0u), 0x01));

                  ir_expression *const r03CB = less(r03B3, body.constant(0u));
                  ir_expression *const r03CC = expr(ir_unop_b2i, r03CB);
                  body.emit(assign(r039D, expr(ir_unop_i2u, r03CC), 0x01));


               body.instructions = f03AE_parent_instructions;
               body.emit(f03AE);

               /* END IF */


            body.instructions = f03AB_parent_instructions;
            body.emit(f03AB);

            /* END IF */


         body.instructions = f03A0_parent_instructions;
         body.emit(f03A0);

         /* END IF */

         /* IF CONDITION */
         ir_if *f03CD = new(mem_ctx) ir_if(operand(r039B).val);
         exec_list *const f03CD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f03CD->then_instructions;

            /* IF CONDITION */
            ir_expression *const r03CF = nequal(r039D, body.constant(0u));
            ir_if *f03CE = new(mem_ctx) ir_if(operand(r03CF).val);
            exec_list *const f03CE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03CE->then_instructions;

               ir_variable *const r03D0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r03D0, add(r0399, body.constant(1u)), 0x01));

               ir_expression *const r03D1 = less(r03D0, r0399);
               ir_expression *const r03D2 = expr(ir_unop_b2i, r03D1);
               ir_expression *const r03D3 = expr(ir_unop_i2u, r03D2);
               body.emit(assign(r0398, add(r0398, r03D3), 0x01));

               ir_expression *const r03D4 = neg(r039A);
               ir_expression *const r03D5 = equal(r039A, r03D4);
               ir_expression *const r03D6 = expr(ir_unop_b2i, r03D5);
               ir_expression *const r03D7 = expr(ir_unop_i2u, r03D6);
               ir_expression *const r03D8 = bit_and(r03D7, body.constant(1u));
               ir_expression *const r03D9 = expr(ir_unop_bit_not, r03D8);
               body.emit(assign(r0399, bit_and(r03D0, r03D9), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03CE->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03DB = bit_or(r0398, r0399);
               ir_expression *const r03DC = equal(r03DB, body.constant(0u));
               ir_if *f03DA = new(mem_ctx) ir_if(operand(r03DC).val);
               exec_list *const f03DA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03DA->then_instructions;

                  body.emit(assign(r0397, body.constant(0u), 0x01));


               body.instructions = f03DA_parent_instructions;
               body.emit(f03DA);

               /* END IF */


            body.instructions = f03CE_parent_instructions;
            body.emit(f03CE);

            /* END IF */

            ir_variable *const r03DD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r03DD);
            ir_expression *const r03DE = lshift(r0228, body.constant(int(31)));
            ir_expression *const r03DF = lshift(r0397, body.constant(int(20)));
            ir_expression *const r03E0 = add(r03DE, r03DF);
            body.emit(assign(r03DD, add(r03E0, r0398), 0x01));

            body.emit(assign(r03DD, r0399, 0x02));

            body.emit(assign(r039C, r03DD, 0x03));

            body.emit(assign(r039B, body.constant(false), 0x01));


         body.instructions = f03CD_parent_instructions;
         body.emit(f03CD);

         /* END IF */

         body.emit(assign(r022A, r039C, 0x03));

         body.emit(assign(r0229, body.constant(false), 0x01));


      body.instructions = f0343_parent_instructions;
      body.emit(f0343);

      /* END IF */


   body.instructions = f033C_parent_instructions;
   body.emit(f033C);

   /* END IF */

   body.emit(ret(r022A));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
ir_function_signature *
subFloat64Fracs(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r03E1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r03E1);
   ir_variable *const r03E2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r03E2);
   ir_variable *const r03E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r03E3);
   ir_variable *const r03E4 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r03E5 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
   body.emit(r03E5);
   ir_variable *const r03E6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bExp", ir_var_auto);
   body.emit(r03E6);
   ir_variable *const r03E7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "bFrac", ir_var_auto);
   body.emit(r03E7);
   ir_variable *const r03E8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aExp", ir_var_auto);
   body.emit(r03E8);
   ir_variable *const r03E9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "aFrac", ir_var_auto);
   body.emit(r03E9);
   ir_variable *const r03EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zExp", ir_var_auto);
   body.emit(r03EA);
   ir_variable *const r03EB = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r03EB, bit_and(swizzle_x(r03E1), body.constant(1048575u)), 0x01));

   body.emit(assign(r03EB, swizzle_y(r03E1), 0x02));

   ir_variable *const r03EC = body.make_temp(glsl_type::uint_type, "extractFloat64Exp_retval");
   ir_expression *const r03ED = rshift(swizzle_x(r03E1), body.constant(int(20)));
   body.emit(assign(r03EC, bit_and(r03ED, body.constant(2047u)), 0x01));

   body.emit(assign(r03E8, r03EC, 0x01));

   ir_variable *const r03EE = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
   body.emit(assign(r03EE, bit_and(swizzle_x(r03E2), body.constant(1048575u)), 0x01));

   body.emit(assign(r03EE, swizzle_y(r03E2), 0x02));

   ir_variable *const r03EF = body.make_temp(glsl_type::uint_type, "extractFloat64Exp_retval");
   ir_expression *const r03F0 = rshift(swizzle_x(r03E2), body.constant(int(20)));
   body.emit(assign(r03EF, bit_and(r03F0, body.constant(2047u)), 0x01));

   body.emit(assign(r03E6, r03EF, 0x01));

   ir_expression *const r03F1 = expr(ir_unop_u2i, r03EC);
   ir_expression *const r03F2 = expr(ir_unop_u2i, r03EF);
   body.emit(assign(r03E5, sub(r03F1, r03F2), 0x01));

   ir_variable *const r03F3 = body.make_temp(glsl_type::uint_type, "z1Ptr");
   body.emit(assign(r03F3, lshift(swizzle_y(r03E1), body.constant(int(10))), 0x01));

   ir_variable *const r03F4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
   ir_expression *const r03F5 = lshift(swizzle_x(r03EB), body.constant(int(10)));
   ir_expression *const r03F6 = rshift(swizzle_y(r03E1), body.constant(int(22)));
   body.emit(assign(r03F4, bit_or(r03F5, r03F6), 0x01));

   body.emit(assign(r03E9, r03F4, 0x01));

   body.emit(assign(r03E9, r03F3, 0x02));

   ir_variable *const r03F7 = body.make_temp(glsl_type::uint_type, "z1Ptr");
   body.emit(assign(r03F7, lshift(swizzle_y(r03E2), body.constant(int(10))), 0x01));

   ir_variable *const r03F8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
   ir_expression *const r03F9 = lshift(swizzle_x(r03EE), body.constant(int(10)));
   ir_expression *const r03FA = rshift(swizzle_y(r03E2), body.constant(int(22)));
   body.emit(assign(r03F8, bit_or(r03F9, r03FA), 0x01));

   body.emit(assign(r03E7, r03F8, 0x01));

   body.emit(assign(r03E7, r03F7, 0x02));

   /* IF CONDITION */
   ir_expression *const r03FC = less(body.constant(int(0)), r03E5);
   ir_if *f03FB = new(mem_ctx) ir_if(operand(r03FC).val);
   exec_list *const f03FB_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f03FB->then_instructions;

      /* IF CONDITION */
      ir_expression *const r03FE = equal(r03EC, body.constant(2047u));
      ir_if *f03FD = new(mem_ctx) ir_if(operand(r03FE).val);
      exec_list *const f03FD_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f03FD->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0400 = bit_or(r03F4, r03F3);
         ir_expression *const r0401 = nequal(r0400, body.constant(0u));
         ir_if *f03FF = new(mem_ctx) ir_if(operand(r0401).val);
         exec_list *const f03FF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f03FF->then_instructions;

            ir_variable *const r0402 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0402, swizzle_x(r03E1), 0x01));

            ir_variable *const r0403 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0403, swizzle_x(r03E2), 0x01));

            ir_variable *const r0404 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0405 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
            ir_expression *const r0406 = rshift(swizzle_y(r03E1), body.constant(int(19)));
            ir_expression *const r0407 = bit_and(r0406, body.constant(4095u));
            ir_expression *const r0408 = equal(r0407, body.constant(4094u));
            ir_expression *const r0409 = nequal(swizzle_x(r03E1), body.constant(0u));
            ir_expression *const r040A = bit_and(swizzle_y(r03E1), body.constant(524287u));
            ir_expression *const r040B = nequal(r040A, body.constant(0u));
            ir_expression *const r040C = logic_or(r0409, r040B);
            body.emit(assign(r0405, logic_and(r0408, r040C), 0x01));

            ir_variable *const r040D = body.make_temp(glsl_type::bool_type, "is_nan_retval");
            ir_expression *const r040E = lshift(swizzle_y(r03E2), body.constant(int(1)));
            ir_expression *const r040F = lequal(body.constant(4292870144u), r040E);
            ir_expression *const r0410 = nequal(swizzle_x(r03E2), body.constant(0u));
            ir_expression *const r0411 = bit_and(swizzle_y(r03E2), body.constant(1048575u));
            ir_expression *const r0412 = nequal(r0411, body.constant(0u));
            ir_expression *const r0413 = logic_or(r0410, r0412);
            body.emit(assign(r040D, logic_and(r040F, r0413), 0x01));

            body.emit(assign(r0402, bit_or(swizzle_y(r03E1), body.constant(524288u)), 0x02));

            body.emit(assign(r0403, bit_or(swizzle_y(r03E2), body.constant(524288u)), 0x02));

            /* IF CONDITION */
            ir_expression *const r0415 = lshift(swizzle_y(r03E1), body.constant(int(1)));
            ir_expression *const r0416 = lequal(body.constant(4292870144u), r0415);
            ir_expression *const r0417 = nequal(swizzle_x(r03E1), body.constant(0u));
            ir_expression *const r0418 = bit_and(swizzle_y(r03E1), body.constant(1048575u));
            ir_expression *const r0419 = nequal(r0418, body.constant(0u));
            ir_expression *const r041A = logic_or(r0417, r0419);
            ir_expression *const r041B = logic_and(r0416, r041A);
            ir_if *f0414 = new(mem_ctx) ir_if(operand(r041B).val);
            exec_list *const f0414_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0414->then_instructions;

               ir_variable *const r041C = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r041E = logic_and(r0405, r040D);
               ir_if *f041D = new(mem_ctx) ir_if(operand(r041E).val);
               exec_list *const f041D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f041D->then_instructions;

                  body.emit(assign(r041C, r0403, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f041D->else_instructions;

                  body.emit(assign(r041C, r0402, 0x03));


               body.instructions = f041D_parent_instructions;
               body.emit(f041D);

               /* END IF */

               body.emit(assign(r0404, r041C, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0414->else_instructions;

               body.emit(assign(r0404, r0403, 0x03));


            body.instructions = f0414_parent_instructions;
            body.emit(f0414);

            /* END IF */

            body.emit(assign(r03E4, r0404, 0x03));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f03FF->else_instructions;

            body.emit(assign(r03E4, r03E1, 0x03));


         body.instructions = f03FF_parent_instructions;
         body.emit(f03FF);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f03FD->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0420 = equal(r03EF, body.constant(0u));
         ir_if *f041F = new(mem_ctx) ir_if(operand(r0420).val);
         exec_list *const f041F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f041F->then_instructions;

            body.emit(assign(r03E5, add(r03E5, body.constant(int(-1))), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f041F->else_instructions;

            body.emit(assign(r03E7, bit_or(r03F8, body.constant(1073741824u)), 0x01));


         body.instructions = f041F_parent_instructions;
         body.emit(f041F);

         /* END IF */

         ir_variable *const r0421 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
         body.emit(r0421);
         ir_variable *const r0422 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
         body.emit(r0422);
         ir_variable *const r0423 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         ir_expression *const r0424 = neg(r03E5);
         body.emit(assign(r0423, bit_and(r0424, body.constant(int(31))), 0x01));

         /* IF CONDITION */
         ir_expression *const r0426 = equal(r03E5, body.constant(int(0)));
         ir_if *f0425 = new(mem_ctx) ir_if(operand(r0426).val);
         exec_list *const f0425_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0425->then_instructions;

            body.emit(assign(r0421, swizzle_y(r03E7), 0x01));

            body.emit(assign(r0422, swizzle_x(r03E7), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0425->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0428 = less(r03E5, body.constant(int(32)));
            ir_if *f0427 = new(mem_ctx) ir_if(operand(r0428).val);
            exec_list *const f0427_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0427->then_instructions;

               ir_expression *const r0429 = lshift(swizzle_x(r03E7), r0423);
               ir_expression *const r042A = rshift(r03F7, r03E5);
               ir_expression *const r042B = bit_or(r0429, r042A);
               ir_expression *const r042C = lshift(r03F7, r0423);
               ir_expression *const r042D = nequal(r042C, body.constant(0u));
               ir_expression *const r042E = expr(ir_unop_b2i, r042D);
               ir_expression *const r042F = expr(ir_unop_i2u, r042E);
               body.emit(assign(r0421, bit_or(r042B, r042F), 0x01));

               body.emit(assign(r0422, rshift(swizzle_x(r03E7), r03E5), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0427->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0431 = equal(r03E5, body.constant(int(32)));
               ir_if *f0430 = new(mem_ctx) ir_if(operand(r0431).val);
               exec_list *const f0430_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0430->then_instructions;

                  ir_expression *const r0432 = nequal(r03F7, body.constant(0u));
                  ir_expression *const r0433 = expr(ir_unop_b2i, r0432);
                  ir_expression *const r0434 = expr(ir_unop_i2u, r0433);
                  body.emit(assign(r0421, bit_or(swizzle_x(r03E7), r0434), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0430->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0436 = less(r03E5, body.constant(int(64)));
                  ir_if *f0435 = new(mem_ctx) ir_if(operand(r0436).val);
                  exec_list *const f0435_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0435->then_instructions;

                     ir_expression *const r0437 = bit_and(r03E5, body.constant(int(31)));
                     ir_expression *const r0438 = rshift(swizzle_x(r03E7), r0437);
                     ir_expression *const r0439 = lshift(swizzle_x(r03E7), r0423);
                     ir_expression *const r043A = bit_or(r0439, r03F7);
                     ir_expression *const r043B = nequal(r043A, body.constant(0u));
                     ir_expression *const r043C = expr(ir_unop_b2i, r043B);
                     ir_expression *const r043D = expr(ir_unop_i2u, r043C);
                     body.emit(assign(r0421, bit_or(r0438, r043D), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0435->else_instructions;

                     ir_expression *const r043E = bit_or(swizzle_x(r03E7), r03F7);
                     ir_expression *const r043F = nequal(r043E, body.constant(0u));
                     ir_expression *const r0440 = expr(ir_unop_b2i, r043F);
                     body.emit(assign(r0421, expr(ir_unop_i2u, r0440), 0x01));


                  body.instructions = f0435_parent_instructions;
                  body.emit(f0435);

                  /* END IF */


               body.instructions = f0430_parent_instructions;
               body.emit(f0430);

               /* END IF */

               body.emit(assign(r0422, body.constant(0u), 0x01));


            body.instructions = f0427_parent_instructions;
            body.emit(f0427);

            /* END IF */


         body.instructions = f0425_parent_instructions;
         body.emit(f0425);

         /* END IF */

         body.emit(assign(r03E7, r0422, 0x01));

         body.emit(assign(r03E7, r0421, 0x02));

         body.emit(assign(r03E9, bit_or(r03F4, body.constant(1073741824u)), 0x01));

         ir_variable *const r0441 = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r0442 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0442, sub(r03F3, r0421), 0x01));

         ir_expression *const r0443 = sub(swizzle_x(r03E9), r0422);
         ir_expression *const r0444 = less(r03F3, r0421);
         ir_expression *const r0445 = expr(ir_unop_b2i, r0444);
         ir_expression *const r0446 = expr(ir_unop_i2u, r0445);
         body.emit(assign(r0441, sub(r0443, r0446), 0x01));

         body.emit(assign(r03EA, add(r03EC, body.constant(4294967295u)), 0x01));

         ir_variable *const r0447 = body.make_temp(glsl_type::uint_type, "zExp");
         body.emit(assign(r0447, add(r03EA, body.constant(4294967286u)), 0x01));

         ir_variable *const r0448 = body.make_temp(glsl_type::uint_type, "zFrac0");
         body.emit(assign(r0448, r0441, 0x01));

         ir_variable *const r0449 = body.make_temp(glsl_type::uint_type, "zFrac1");
         body.emit(assign(r0449, r0442, 0x01));

         ir_variable *const r044A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
         body.emit(r044A);
         ir_variable *const r044B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
         body.emit(r044B);
         /* IF CONDITION */
         ir_expression *const r044D = equal(r0441, body.constant(0u));
         ir_if *f044C = new(mem_ctx) ir_if(operand(r044D).val);
         exec_list *const f044C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f044C->then_instructions;

            body.emit(assign(r0448, r0442, 0x01));

            body.emit(assign(r0449, body.constant(0u), 0x01));

            body.emit(assign(r0447, add(r0447, body.constant(4294967264u)), 0x01));


         body.instructions = f044C_parent_instructions;
         body.emit(f044C);

         /* END IF */

         ir_variable *const r044E = body.make_temp(glsl_type::uint_type, "a");
         body.emit(assign(r044E, r0448, 0x01));

         ir_variable *const r044F = body.make_temp(glsl_type::uint_type, "return_value");
         ir_variable *const r0450 = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
         body.emit(r0450);
         /* IF CONDITION */
         ir_expression *const r0452 = equal(r0448, body.constant(0u));
         ir_if *f0451 = new(mem_ctx) ir_if(operand(r0452).val);
         exec_list *const f0451_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0451->then_instructions;

            body.emit(assign(r044F, body.constant(32u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0451->else_instructions;

            body.emit(assign(r0450, body.constant(0u), 0x01));

            /* IF CONDITION */
            ir_expression *const r0454 = bit_and(r0448, body.constant(4294901760u));
            ir_expression *const r0455 = equal(r0454, body.constant(0u));
            ir_if *f0453 = new(mem_ctx) ir_if(operand(r0455).val);
            exec_list *const f0453_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0453->then_instructions;

               body.emit(assign(r0450, body.constant(16u), 0x01));

               body.emit(assign(r044E, lshift(r0448, body.constant(int(16))), 0x01));


            body.instructions = f0453_parent_instructions;
            body.emit(f0453);

            /* END IF */

            /* IF CONDITION */
            ir_expression *const r0457 = bit_and(r044E, body.constant(4278190080u));
            ir_expression *const r0458 = equal(r0457, body.constant(0u));
            ir_if *f0456 = new(mem_ctx) ir_if(operand(r0458).val);
            exec_list *const f0456_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0456->then_instructions;

               body.emit(assign(r0450, add(r0450, body.constant(8u)), 0x01));

               body.emit(assign(r044E, lshift(r044E, body.constant(int(8))), 0x01));


            body.instructions = f0456_parent_instructions;
            body.emit(f0456);

            /* END IF */

            /* IF CONDITION */
            ir_expression *const r045A = bit_and(r044E, body.constant(4026531840u));
            ir_expression *const r045B = equal(r045A, body.constant(0u));
            ir_if *f0459 = new(mem_ctx) ir_if(operand(r045B).val);
            exec_list *const f0459_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0459->then_instructions;

               body.emit(assign(r0450, add(r0450, body.constant(4u)), 0x01));

               body.emit(assign(r044E, lshift(r044E, body.constant(int(4))), 0x01));


            body.instructions = f0459_parent_instructions;
            body.emit(f0459);

            /* END IF */

            /* IF CONDITION */
            ir_expression *const r045D = bit_and(r044E, body.constant(3221225472u));
            ir_expression *const r045E = equal(r045D, body.constant(0u));
            ir_if *f045C = new(mem_ctx) ir_if(operand(r045E).val);
            exec_list *const f045C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f045C->then_instructions;

               body.emit(assign(r0450, add(r0450, body.constant(2u)), 0x01));

               body.emit(assign(r044E, lshift(r044E, body.constant(int(2))), 0x01));


            body.instructions = f045C_parent_instructions;
            body.emit(f045C);

            /* END IF */

            /* IF CONDITION */
            ir_expression *const r0460 = bit_and(r044E, body.constant(2147483648u));
            ir_expression *const r0461 = equal(r0460, body.constant(0u));
            ir_if *f045F = new(mem_ctx) ir_if(operand(r0461).val);
            exec_list *const f045F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f045F->then_instructions;

               body.emit(assign(r0450, add(r0450, body.constant(1u)), 0x01));


            body.instructions = f045F_parent_instructions;
            body.emit(f045F);

            /* END IF */

            body.emit(assign(r044F, r0450, 0x01));


         body.instructions = f0451_parent_instructions;
         body.emit(f0451);

         /* END IF */

         ir_expression *const r0462 = expr(ir_unop_u2i, r044F);
         body.emit(assign(r044B, add(r0462, body.constant(int(-11))), 0x01));

         /* IF CONDITION */
         ir_expression *const r0464 = lequal(body.constant(int(0)), r044B);
         ir_if *f0463 = new(mem_ctx) ir_if(operand(r0464).val);
         exec_list *const f0463_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0463->then_instructions;

            body.emit(assign(r044A, body.constant(0u), 0x01));

            ir_variable *const r0465 = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r0465, lshift(r0449, r044B), 0x01));

            ir_variable *const r0466 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0468 = equal(r044B, body.constant(int(0)));
            ir_if *f0467 = new(mem_ctx) ir_if(operand(r0468).val);
            exec_list *const f0467_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0467->then_instructions;

               body.emit(assign(r0466, r0448, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0467->else_instructions;

               ir_expression *const r0469 = lshift(r0448, r044B);
               ir_expression *const r046A = neg(r044B);
               ir_expression *const r046B = bit_and(r046A, body.constant(int(31)));
               ir_expression *const r046C = rshift(r0449, r046B);
               body.emit(assign(r0466, bit_or(r0469, r046C), 0x01));


            body.instructions = f0467_parent_instructions;
            body.emit(f0467);

            /* END IF */

            body.emit(assign(r0448, r0466, 0x01));

            body.emit(assign(r0449, r0465, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0463->else_instructions;

            ir_variable *const r046D = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r046D, body.constant(0u), 0x01));

            ir_variable *const r046E = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r046E, neg(r044B), 0x01));

            ir_variable *const r046F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r046F);
            ir_variable *const r0470 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0470);
            ir_variable *const r0471 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0471);
            ir_variable *const r0472 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0473 = neg(r046E);
            body.emit(assign(r0472, bit_and(r0473, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0475 = equal(r046E, body.constant(int(0)));
            ir_if *f0474 = new(mem_ctx) ir_if(operand(r0475).val);
            exec_list *const f0474_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0474->then_instructions;

               body.emit(assign(r046F, r046D, 0x01));

               body.emit(assign(r0470, r0449, 0x01));

               body.emit(assign(r0471, r0448, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0474->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0477 = less(r046E, body.constant(int(32)));
               ir_if *f0476 = new(mem_ctx) ir_if(operand(r0477).val);
               exec_list *const f0476_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0476->then_instructions;

                  body.emit(assign(r046F, lshift(r0449, r0472), 0x01));

                  ir_expression *const r0478 = lshift(r0448, r0472);
                  ir_expression *const r0479 = rshift(r0449, r046E);
                  body.emit(assign(r0470, bit_or(r0478, r0479), 0x01));

                  body.emit(assign(r0471, rshift(r0448, r046E), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0476->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r047B = equal(r046E, body.constant(int(32)));
                  ir_if *f047A = new(mem_ctx) ir_if(operand(r047B).val);
                  exec_list *const f047A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f047A->then_instructions;

                     body.emit(assign(r046F, r0449, 0x01));

                     body.emit(assign(r0470, r0448, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f047A->else_instructions;

                     body.emit(assign(r046D, bit_or(body.constant(0u), r0449), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r047D = less(r046E, body.constant(int(64)));
                     ir_if *f047C = new(mem_ctx) ir_if(operand(r047D).val);
                     exec_list *const f047C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f047C->then_instructions;

                        body.emit(assign(r046F, lshift(r0448, r0472), 0x01));

                        ir_expression *const r047E = bit_and(r046E, body.constant(int(31)));
                        body.emit(assign(r0470, rshift(r0448, r047E), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f047C->else_instructions;

                        ir_variable *const r047F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0481 = equal(r046E, body.constant(int(64)));
                        ir_if *f0480 = new(mem_ctx) ir_if(operand(r0481).val);
                        exec_list *const f0480_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0480->then_instructions;

                           body.emit(assign(r047F, r0448, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0480->else_instructions;

                           ir_expression *const r0482 = nequal(r0448, body.constant(0u));
                           ir_expression *const r0483 = expr(ir_unop_b2i, r0482);
                           body.emit(assign(r047F, expr(ir_unop_i2u, r0483), 0x01));


                        body.instructions = f0480_parent_instructions;
                        body.emit(f0480);

                        /* END IF */

                        body.emit(assign(r046F, r047F, 0x01));

                        body.emit(assign(r0470, body.constant(0u), 0x01));


                     body.instructions = f047C_parent_instructions;
                     body.emit(f047C);

                     /* END IF */


                  body.instructions = f047A_parent_instructions;
                  body.emit(f047A);

                  /* END IF */

                  body.emit(assign(r0471, body.constant(0u), 0x01));


               body.instructions = f0476_parent_instructions;
               body.emit(f0476);

               /* END IF */

               ir_expression *const r0484 = nequal(r046D, body.constant(0u));
               ir_expression *const r0485 = expr(ir_unop_b2i, r0484);
               ir_expression *const r0486 = expr(ir_unop_i2u, r0485);
               body.emit(assign(r046F, bit_or(r046F, r0486), 0x01));


            body.instructions = f0474_parent_instructions;
            body.emit(f0474);

            /* END IF */

            body.emit(assign(r0448, r0471, 0x01));

            body.emit(assign(r0449, r0470, 0x01));

            body.emit(assign(r044A, r046F, 0x01));


         body.instructions = f0463_parent_instructions;
         body.emit(f0463);

         /* END IF */

         ir_expression *const r0487 = expr(ir_unop_i2u, r044B);
         body.emit(assign(r0447, sub(r0447, r0487), 0x01));

         ir_variable *const r0488 = body.make_temp(glsl_type::uint_type, "zExp");
         body.emit(assign(r0488, r0447, 0x01));

         ir_variable *const r0489 = body.make_temp(glsl_type::uint_type, "zFrac0");
         body.emit(assign(r0489, r0448, 0x01));

         ir_variable *const r048A = body.make_temp(glsl_type::uint_type, "zFrac1");
         body.emit(assign(r048A, r0449, 0x01));

         ir_variable *const r048B = body.make_temp(glsl_type::uint_type, "zFrac2");
         body.emit(assign(r048B, r044A, 0x01));

         ir_variable *const r048C = body.make_temp(glsl_type::bool_type, "execute_flag");
         body.emit(assign(r048C, body.constant(true), 0x01));

         ir_variable *const r048D = body.make_temp(glsl_type::uvec2_type, "return_value");
         ir_variable *const r048E = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
         body.emit(r048E);
         ir_expression *const r048F = less(r044A, body.constant(0u));
         ir_expression *const r0490 = expr(ir_unop_b2i, r048F);
         body.emit(assign(r048E, expr(ir_unop_i2u, r0490), 0x01));

         /* IF CONDITION */
         ir_expression *const r0492 = lequal(body.constant(2045u), r0447);
         ir_if *f0491 = new(mem_ctx) ir_if(operand(r0492).val);
         exec_list *const f0491_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0491->then_instructions;

            ir_variable *const r0493 = body.make_temp(glsl_type::bool_type, "or_tmp");
            /* IF CONDITION */
            ir_expression *const r0495 = less(body.constant(2045u), r0447);
            ir_if *f0494 = new(mem_ctx) ir_if(operand(r0495).val);
            exec_list *const f0494_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0494->then_instructions;

               body.emit(assign(r0493, body.constant(true), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0494->else_instructions;

               ir_variable *const r0496 = body.make_temp(glsl_type::bool_type, "and_tmp");
               /* IF CONDITION */
               ir_expression *const r0498 = equal(r0447, body.constant(2045u));
               ir_if *f0497 = new(mem_ctx) ir_if(operand(r0498).val);
               exec_list *const f0497_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0497->then_instructions;

                  ir_expression *const r0499 = equal(body.constant(2097151u), r0448);
                  ir_expression *const r049A = equal(body.constant(4294967295u), r0449);
                  body.emit(assign(r0496, logic_and(r0499, r049A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0497->else_instructions;

                  body.emit(assign(r0496, body.constant(false), 0x01));


               body.instructions = f0497_parent_instructions;
               body.emit(f0497);

               /* END IF */

               ir_expression *const r049B = nequal(r048E, body.constant(0u));
               body.emit(assign(r0493, logic_and(r0496, r049B), 0x01));


            body.instructions = f0494_parent_instructions;
            body.emit(f0494);

            /* END IF */

            /* IF CONDITION */
            ir_if *f049C = new(mem_ctx) ir_if(operand(r0493).val);
            exec_list *const f049C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f049C->then_instructions;

               ir_variable *const r049D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r049D);
               ir_expression *const r049E = lshift(r03E3, body.constant(int(31)));
               body.emit(assign(r049D, add(r049E, body.constant(2146435072u)), 0x01));

               body.emit(assign(r049D, body.constant(0u), 0x02));

               body.emit(assign(r048D, r049D, 0x03));

               body.emit(assign(r048C, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f049C->else_instructions;

               /* IF CONDITION */
               ir_expression *const r04A0 = less(r0447, body.constant(0u));
               ir_if *f049F = new(mem_ctx) ir_if(operand(r04A0).val);
               exec_list *const f049F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f049F->then_instructions;

                  ir_variable *const r04A1 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r04A1, r044A, 0x01));

                  ir_variable *const r04A2 = body.make_temp(glsl_type::int_type, "count");
                  ir_expression *const r04A3 = neg(r0447);
                  body.emit(assign(r04A2, expr(ir_unop_u2i, r04A3), 0x01));

                  ir_variable *const r04A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04A4);
                  ir_variable *const r04A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r04A5);
                  ir_variable *const r04A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04A6);
                  ir_variable *const r04A7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04A8 = neg(r04A2);
                  body.emit(assign(r04A7, bit_and(r04A8, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04AA = equal(r04A2, body.constant(int(0)));
                  ir_if *f04A9 = new(mem_ctx) ir_if(operand(r04AA).val);
                  exec_list *const f04A9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A9->then_instructions;

                     body.emit(assign(r04A4, r044A, 0x01));

                     body.emit(assign(r04A5, r0449, 0x01));

                     body.emit(assign(r04A6, r0448, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04A9->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04AC = less(r04A2, body.constant(int(32)));
                     ir_if *f04AB = new(mem_ctx) ir_if(operand(r04AC).val);
                     exec_list *const f04AB_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04AB->then_instructions;

                        body.emit(assign(r04A4, lshift(r0449, r04A7), 0x01));

                        ir_expression *const r04AD = lshift(r0448, r04A7);
                        ir_expression *const r04AE = rshift(r0449, r04A2);
                        body.emit(assign(r04A5, bit_or(r04AD, r04AE), 0x01));

                        body.emit(assign(r04A6, rshift(r0448, r04A2), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04AB->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04B0 = equal(r04A2, body.constant(int(32)));
                        ir_if *f04AF = new(mem_ctx) ir_if(operand(r04B0).val);
                        exec_list *const f04AF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04AF->then_instructions;

                           body.emit(assign(r04A4, r0449, 0x01));

                           body.emit(assign(r04A5, r0448, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04AF->else_instructions;

                           body.emit(assign(r04A1, bit_or(r044A, r0449), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r04B2 = less(r04A2, body.constant(int(64)));
                           ir_if *f04B1 = new(mem_ctx) ir_if(operand(r04B2).val);
                           exec_list *const f04B1_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04B1->then_instructions;

                              body.emit(assign(r04A4, lshift(r0448, r04A7), 0x01));

                              ir_expression *const r04B3 = bit_and(r04A2, body.constant(int(31)));
                              body.emit(assign(r04A5, rshift(r0448, r04B3), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04B1->else_instructions;

                              ir_variable *const r04B4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r04B6 = equal(r04A2, body.constant(int(64)));
                              ir_if *f04B5 = new(mem_ctx) ir_if(operand(r04B6).val);
                              exec_list *const f04B5_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04B5->then_instructions;

                                 body.emit(assign(r04B4, r0448, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04B5->else_instructions;

                                 ir_expression *const r04B7 = nequal(r0448, body.constant(0u));
                                 ir_expression *const r04B8 = expr(ir_unop_b2i, r04B7);
                                 body.emit(assign(r04B4, expr(ir_unop_i2u, r04B8), 0x01));


                              body.instructions = f04B5_parent_instructions;
                              body.emit(f04B5);

                              /* END IF */

                              body.emit(assign(r04A4, r04B4, 0x01));

                              body.emit(assign(r04A5, body.constant(0u), 0x01));


                           body.instructions = f04B1_parent_instructions;
                           body.emit(f04B1);

                           /* END IF */


                        body.instructions = f04AF_parent_instructions;
                        body.emit(f04AF);

                        /* END IF */

                        body.emit(assign(r04A6, body.constant(0u), 0x01));


                     body.instructions = f04AB_parent_instructions;
                     body.emit(f04AB);

                     /* END IF */

                     ir_expression *const r04B9 = nequal(r04A1, body.constant(0u));
                     ir_expression *const r04BA = expr(ir_unop_b2i, r04B9);
                     ir_expression *const r04BB = expr(ir_unop_i2u, r04BA);
                     body.emit(assign(r04A4, bit_or(r04A4, r04BB), 0x01));


                  body.instructions = f04A9_parent_instructions;
                  body.emit(f04A9);

                  /* END IF */

                  body.emit(assign(r0489, r04A6, 0x01));

                  body.emit(assign(r048A, r04A5, 0x01));

                  body.emit(assign(r048B, r04A4, 0x01));

                  body.emit(assign(r0488, body.constant(0u), 0x01));

                  ir_expression *const r04BC = less(r04A4, body.constant(0u));
                  ir_expression *const r04BD = expr(ir_unop_b2i, r04BC);
                  body.emit(assign(r048E, expr(ir_unop_i2u, r04BD), 0x01));


               body.instructions = f049F_parent_instructions;
               body.emit(f049F);

               /* END IF */


            body.instructions = f049C_parent_instructions;
            body.emit(f049C);

            /* END IF */


         body.instructions = f0491_parent_instructions;
         body.emit(f0491);

         /* END IF */

         /* IF CONDITION */
         ir_if *f04BE = new(mem_ctx) ir_if(operand(r048C).val);
         exec_list *const f04BE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f04BE->then_instructions;

            /* IF CONDITION */
            ir_expression *const r04C0 = nequal(r048E, body.constant(0u));
            ir_if *f04BF = new(mem_ctx) ir_if(operand(r04C0).val);
            exec_list *const f04BF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f04BF->then_instructions;

               ir_variable *const r04C1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r04C1, add(r048A, body.constant(1u)), 0x01));

               ir_expression *const r04C2 = less(r04C1, r048A);
               ir_expression *const r04C3 = expr(ir_unop_b2i, r04C2);
               ir_expression *const r04C4 = expr(ir_unop_i2u, r04C3);
               body.emit(assign(r0489, add(r0489, r04C4), 0x01));

               ir_expression *const r04C5 = neg(r048B);
               ir_expression *const r04C6 = equal(r048B, r04C5);
               ir_expression *const r04C7 = expr(ir_unop_b2i, r04C6);
               ir_expression *const r04C8 = expr(ir_unop_i2u, r04C7);
               ir_expression *const r04C9 = bit_and(r04C8, body.constant(1u));
               ir_expression *const r04CA = expr(ir_unop_bit_not, r04C9);
               body.emit(assign(r048A, bit_and(r04C1, r04CA), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f04BF->else_instructions;

               /* IF CONDITION */
               ir_expression *const r04CC = bit_or(r0489, r048A);
               ir_expression *const r04CD = equal(r04CC, body.constant(0u));
               ir_if *f04CB = new(mem_ctx) ir_if(operand(r04CD).val);
               exec_list *const f04CB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04CB->then_instructions;

                  body.emit(assign(r0488, body.constant(0u), 0x01));


               body.instructions = f04CB_parent_instructions;
               body.emit(f04CB);

               /* END IF */


            body.instructions = f04BF_parent_instructions;
            body.emit(f04BF);

            /* END IF */

            ir_variable *const r04CE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r04CE);
            ir_expression *const r04CF = lshift(r03E3, body.constant(int(31)));
            ir_expression *const r04D0 = lshift(r0488, body.constant(int(20)));
            ir_expression *const r04D1 = add(r04CF, r04D0);
            body.emit(assign(r04CE, add(r04D1, r0489), 0x01));

            body.emit(assign(r04CE, r048A, 0x02));

            body.emit(assign(r048D, r04CE, 0x03));

            body.emit(assign(r048C, body.constant(false), 0x01));


         body.instructions = f04BE_parent_instructions;
         body.emit(f04BE);

         /* END IF */

         body.emit(assign(r03E4, r048D, 0x03));


      body.instructions = f03FD_parent_instructions;
      body.emit(f03FD);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f03FB->else_instructions;

      /* IF CONDITION */
      ir_expression *const r04D3 = less(r03E5, body.constant(int(0)));
      ir_if *f04D2 = new(mem_ctx) ir_if(operand(r04D3).val);
      exec_list *const f04D2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f04D2->then_instructions;

         /* IF CONDITION */
         ir_expression *const r04D5 = equal(r03EF, body.constant(2047u));
         ir_if *f04D4 = new(mem_ctx) ir_if(operand(r04D5).val);
         exec_list *const f04D4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f04D4->then_instructions;

            /* IF CONDITION */
            ir_expression *const r04D7 = bit_or(swizzle_x(r03E7), swizzle_y(r03E7));
            ir_expression *const r04D8 = nequal(r04D7, body.constant(0u));
            ir_if *f04D6 = new(mem_ctx) ir_if(operand(r04D8).val);
            exec_list *const f04D6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f04D6->then_instructions;

               ir_variable *const r04D9 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r04D9, swizzle_x(r03E1), 0x01));

               ir_variable *const r04DA = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r04DA, swizzle_x(r03E2), 0x01));

               ir_variable *const r04DB = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04DC = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
               ir_expression *const r04DD = rshift(swizzle_y(r03E1), body.constant(int(19)));
               ir_expression *const r04DE = bit_and(r04DD, body.constant(4095u));
               ir_expression *const r04DF = equal(r04DE, body.constant(4094u));
               ir_expression *const r04E0 = nequal(swizzle_x(r03E1), body.constant(0u));
               ir_expression *const r04E1 = bit_and(swizzle_y(r03E1), body.constant(524287u));
               ir_expression *const r04E2 = nequal(r04E1, body.constant(0u));
               ir_expression *const r04E3 = logic_or(r04E0, r04E2);
               body.emit(assign(r04DC, logic_and(r04DF, r04E3), 0x01));

               ir_variable *const r04E4 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r04E5 = lshift(swizzle_y(r03E2), body.constant(int(1)));
               ir_expression *const r04E6 = lequal(body.constant(4292870144u), r04E5);
               ir_expression *const r04E7 = nequal(swizzle_x(r03E2), body.constant(0u));
               ir_expression *const r04E8 = bit_and(swizzle_y(r03E2), body.constant(1048575u));
               ir_expression *const r04E9 = nequal(r04E8, body.constant(0u));
               ir_expression *const r04EA = logic_or(r04E7, r04E9);
               body.emit(assign(r04E4, logic_and(r04E6, r04EA), 0x01));

               body.emit(assign(r04D9, bit_or(swizzle_y(r03E1), body.constant(524288u)), 0x02));

               body.emit(assign(r04DA, bit_or(swizzle_y(r03E2), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r04EC = lshift(swizzle_y(r03E1), body.constant(int(1)));
               ir_expression *const r04ED = lequal(body.constant(4292870144u), r04EC);
               ir_expression *const r04EE = nequal(swizzle_x(r03E1), body.constant(0u));
               ir_expression *const r04EF = bit_and(swizzle_y(r03E1), body.constant(1048575u));
               ir_expression *const r04F0 = nequal(r04EF, body.constant(0u));
               ir_expression *const r04F1 = logic_or(r04EE, r04F0);
               ir_expression *const r04F2 = logic_and(r04ED, r04F1);
               ir_if *f04EB = new(mem_ctx) ir_if(operand(r04F2).val);
               exec_list *const f04EB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04EB->then_instructions;

                  ir_variable *const r04F3 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r04F5 = logic_and(r04DC, r04E4);
                  ir_if *f04F4 = new(mem_ctx) ir_if(operand(r04F5).val);
                  exec_list *const f04F4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04F4->then_instructions;

                     body.emit(assign(r04F3, r04DA, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04F4->else_instructions;

                     body.emit(assign(r04F3, r04D9, 0x03));


                  body.instructions = f04F4_parent_instructions;
                  body.emit(f04F4);

                  /* END IF */

                  body.emit(assign(r04DB, r04F3, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04EB->else_instructions;

                  body.emit(assign(r04DB, r04DA, 0x03));


               body.instructions = f04EB_parent_instructions;
               body.emit(f04EB);

               /* END IF */

               body.emit(assign(r03E4, r04DB, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f04D6->else_instructions;

               ir_variable *const r04F6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r04F6);
               ir_expression *const r04F7 = bit_xor(r03E3, body.constant(1u));
               ir_expression *const r04F8 = lshift(r04F7, body.constant(int(31)));
               body.emit(assign(r04F6, add(r04F8, body.constant(2146435072u)), 0x01));

               body.emit(assign(r04F6, body.constant(0u), 0x02));

               body.emit(assign(r03E4, r04F6, 0x03));


            body.instructions = f04D6_parent_instructions;
            body.emit(f04D6);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f04D4->else_instructions;

            /* IF CONDITION */
            ir_expression *const r04FA = equal(r03EC, body.constant(0u));
            ir_if *f04F9 = new(mem_ctx) ir_if(operand(r04FA).val);
            exec_list *const f04F9_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f04F9->then_instructions;

               body.emit(assign(r03E5, add(r03E5, body.constant(int(1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f04F9->else_instructions;

               body.emit(assign(r03E9, bit_or(swizzle_x(r03E9), body.constant(1073741824u)), 0x01));


            body.instructions = f04F9_parent_instructions;
            body.emit(f04F9);

            /* END IF */

            ir_variable *const r04FB = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r04FB, neg(r03E5), 0x01));

            ir_variable *const r04FC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r04FC);
            ir_variable *const r04FD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r04FD);
            ir_variable *const r04FE = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r04FF = neg(r04FB);
            body.emit(assign(r04FE, bit_and(r04FF, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0501 = equal(r04FB, body.constant(int(0)));
            ir_if *f0500 = new(mem_ctx) ir_if(operand(r0501).val);
            exec_list *const f0500_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0500->then_instructions;

               body.emit(assign(r04FC, swizzle_y(r03E9), 0x01));

               body.emit(assign(r04FD, swizzle_x(r03E9), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0500->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0503 = less(r04FB, body.constant(int(32)));
               ir_if *f0502 = new(mem_ctx) ir_if(operand(r0503).val);
               exec_list *const f0502_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0502->then_instructions;

                  ir_expression *const r0504 = lshift(swizzle_x(r03E9), r04FE);
                  ir_expression *const r0505 = rshift(r03F3, r04FB);
                  ir_expression *const r0506 = bit_or(r0504, r0505);
                  ir_expression *const r0507 = lshift(r03F3, r04FE);
                  ir_expression *const r0508 = nequal(r0507, body.constant(0u));
                  ir_expression *const r0509 = expr(ir_unop_b2i, r0508);
                  ir_expression *const r050A = expr(ir_unop_i2u, r0509);
                  body.emit(assign(r04FC, bit_or(r0506, r050A), 0x01));

                  body.emit(assign(r04FD, rshift(swizzle_x(r03E9), r04FB), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0502->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r050C = equal(r04FB, body.constant(int(32)));
                  ir_if *f050B = new(mem_ctx) ir_if(operand(r050C).val);
                  exec_list *const f050B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f050B->then_instructions;

                     ir_expression *const r050D = nequal(r03F3, body.constant(0u));
                     ir_expression *const r050E = expr(ir_unop_b2i, r050D);
                     ir_expression *const r050F = expr(ir_unop_i2u, r050E);
                     body.emit(assign(r04FC, bit_or(swizzle_x(r03E9), r050F), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f050B->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0511 = less(r04FB, body.constant(int(64)));
                     ir_if *f0510 = new(mem_ctx) ir_if(operand(r0511).val);
                     exec_list *const f0510_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0510->then_instructions;

                        ir_expression *const r0512 = bit_and(r04FB, body.constant(int(31)));
                        ir_expression *const r0513 = rshift(swizzle_x(r03E9), r0512);
                        ir_expression *const r0514 = lshift(swizzle_x(r03E9), r04FE);
                        ir_expression *const r0515 = bit_or(r0514, r03F3);
                        ir_expression *const r0516 = nequal(r0515, body.constant(0u));
                        ir_expression *const r0517 = expr(ir_unop_b2i, r0516);
                        ir_expression *const r0518 = expr(ir_unop_i2u, r0517);
                        body.emit(assign(r04FC, bit_or(r0513, r0518), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0510->else_instructions;

                        ir_expression *const r0519 = bit_or(swizzle_x(r03E9), r03F3);
                        ir_expression *const r051A = nequal(r0519, body.constant(0u));
                        ir_expression *const r051B = expr(ir_unop_b2i, r051A);
                        body.emit(assign(r04FC, expr(ir_unop_i2u, r051B), 0x01));


                     body.instructions = f0510_parent_instructions;
                     body.emit(f0510);

                     /* END IF */


                  body.instructions = f050B_parent_instructions;
                  body.emit(f050B);

                  /* END IF */

                  body.emit(assign(r04FD, body.constant(0u), 0x01));


               body.instructions = f0502_parent_instructions;
               body.emit(f0502);

               /* END IF */


            body.instructions = f0500_parent_instructions;
            body.emit(f0500);

            /* END IF */

            body.emit(assign(r03E9, r04FD, 0x01));

            body.emit(assign(r03E9, r04FC, 0x02));

            body.emit(assign(r03E7, bit_or(swizzle_x(r03E7), body.constant(1073741824u)), 0x01));

            ir_variable *const r051C = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r051D = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r051D, sub(swizzle_y(r03E7), r04FC), 0x01));

            ir_expression *const r051E = sub(swizzle_x(r03E7), r04FD);
            ir_expression *const r051F = less(swizzle_y(r03E7), r04FC);
            ir_expression *const r0520 = expr(ir_unop_b2i, r051F);
            ir_expression *const r0521 = expr(ir_unop_i2u, r0520);
            body.emit(assign(r051C, sub(r051E, r0521), 0x01));

            body.emit(assign(r03E3, bit_xor(r03E3, body.constant(1u)), 0x01));

            body.emit(assign(r03EA, add(r03EF, body.constant(4294967295u)), 0x01));

            ir_variable *const r0522 = body.make_temp(glsl_type::uint_type, "zExp");
            body.emit(assign(r0522, add(r03EA, body.constant(4294967286u)), 0x01));

            ir_variable *const r0523 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0523, r051C, 0x01));

            ir_variable *const r0524 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0524, r051D, 0x01));

            ir_variable *const r0525 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r0525);
            ir_variable *const r0526 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0526);
            /* IF CONDITION */
            ir_expression *const r0528 = equal(r051C, body.constant(0u));
            ir_if *f0527 = new(mem_ctx) ir_if(operand(r0528).val);
            exec_list *const f0527_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0527->then_instructions;

               body.emit(assign(r0523, r051D, 0x01));

               body.emit(assign(r0524, body.constant(0u), 0x01));

               body.emit(assign(r0522, add(r0522, body.constant(4294967264u)), 0x01));


            body.instructions = f0527_parent_instructions;
            body.emit(f0527);

            /* END IF */

            ir_variable *const r0529 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0529, r0523, 0x01));

            ir_variable *const r052A = body.make_temp(glsl_type::uint_type, "return_value");
            ir_variable *const r052B = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
            body.emit(r052B);
            /* IF CONDITION */
            ir_expression *const r052D = equal(r0523, body.constant(0u));
            ir_if *f052C = new(mem_ctx) ir_if(operand(r052D).val);
            exec_list *const f052C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f052C->then_instructions;

               body.emit(assign(r052A, body.constant(32u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f052C->else_instructions;

               body.emit(assign(r052B, body.constant(0u), 0x01));

               /* IF CONDITION */
               ir_expression *const r052F = bit_and(r0523, body.constant(4294901760u));
               ir_expression *const r0530 = equal(r052F, body.constant(0u));
               ir_if *f052E = new(mem_ctx) ir_if(operand(r0530).val);
               exec_list *const f052E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f052E->then_instructions;

                  body.emit(assign(r052B, body.constant(16u), 0x01));

                  body.emit(assign(r0529, lshift(r0523, body.constant(int(16))), 0x01));


               body.instructions = f052E_parent_instructions;
               body.emit(f052E);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0532 = bit_and(r0529, body.constant(4278190080u));
               ir_expression *const r0533 = equal(r0532, body.constant(0u));
               ir_if *f0531 = new(mem_ctx) ir_if(operand(r0533).val);
               exec_list *const f0531_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0531->then_instructions;

                  body.emit(assign(r052B, add(r052B, body.constant(8u)), 0x01));

                  body.emit(assign(r0529, lshift(r0529, body.constant(int(8))), 0x01));


               body.instructions = f0531_parent_instructions;
               body.emit(f0531);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0535 = bit_and(r0529, body.constant(4026531840u));
               ir_expression *const r0536 = equal(r0535, body.constant(0u));
               ir_if *f0534 = new(mem_ctx) ir_if(operand(r0536).val);
               exec_list *const f0534_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0534->then_instructions;

                  body.emit(assign(r052B, add(r052B, body.constant(4u)), 0x01));

                  body.emit(assign(r0529, lshift(r0529, body.constant(int(4))), 0x01));


               body.instructions = f0534_parent_instructions;
               body.emit(f0534);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0538 = bit_and(r0529, body.constant(3221225472u));
               ir_expression *const r0539 = equal(r0538, body.constant(0u));
               ir_if *f0537 = new(mem_ctx) ir_if(operand(r0539).val);
               exec_list *const f0537_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0537->then_instructions;

                  body.emit(assign(r052B, add(r052B, body.constant(2u)), 0x01));

                  body.emit(assign(r0529, lshift(r0529, body.constant(int(2))), 0x01));


               body.instructions = f0537_parent_instructions;
               body.emit(f0537);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r053B = bit_and(r0529, body.constant(2147483648u));
               ir_expression *const r053C = equal(r053B, body.constant(0u));
               ir_if *f053A = new(mem_ctx) ir_if(operand(r053C).val);
               exec_list *const f053A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f053A->then_instructions;

                  body.emit(assign(r052B, add(r052B, body.constant(1u)), 0x01));


               body.instructions = f053A_parent_instructions;
               body.emit(f053A);

               /* END IF */

               body.emit(assign(r052A, r052B, 0x01));


            body.instructions = f052C_parent_instructions;
            body.emit(f052C);

            /* END IF */

            ir_expression *const r053D = expr(ir_unop_u2i, r052A);
            body.emit(assign(r0526, add(r053D, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r053F = lequal(body.constant(int(0)), r0526);
            ir_if *f053E = new(mem_ctx) ir_if(operand(r053F).val);
            exec_list *const f053E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f053E->then_instructions;

               body.emit(assign(r0525, body.constant(0u), 0x01));

               ir_variable *const r0540 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0540, lshift(r0524, r0526), 0x01));

               ir_variable *const r0541 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0543 = equal(r0526, body.constant(int(0)));
               ir_if *f0542 = new(mem_ctx) ir_if(operand(r0543).val);
               exec_list *const f0542_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0542->then_instructions;

                  body.emit(assign(r0541, r0523, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0542->else_instructions;

                  ir_expression *const r0544 = lshift(r0523, r0526);
                  ir_expression *const r0545 = neg(r0526);
                  ir_expression *const r0546 = bit_and(r0545, body.constant(int(31)));
                  ir_expression *const r0547 = rshift(r0524, r0546);
                  body.emit(assign(r0541, bit_or(r0544, r0547), 0x01));


               body.instructions = f0542_parent_instructions;
               body.emit(f0542);

               /* END IF */

               body.emit(assign(r0523, r0541, 0x01));

               body.emit(assign(r0524, r0540, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f053E->else_instructions;

               ir_variable *const r0548 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0548, body.constant(0u), 0x01));

               ir_variable *const r0549 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0549, neg(r0526), 0x01));

               ir_variable *const r054A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r054A);
               ir_variable *const r054B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r054B);
               ir_variable *const r054C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r054C);
               ir_variable *const r054D = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r054E = neg(r0549);
               body.emit(assign(r054D, bit_and(r054E, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0550 = equal(r0549, body.constant(int(0)));
               ir_if *f054F = new(mem_ctx) ir_if(operand(r0550).val);
               exec_list *const f054F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f054F->then_instructions;

                  body.emit(assign(r054A, r0548, 0x01));

                  body.emit(assign(r054B, r0524, 0x01));

                  body.emit(assign(r054C, r0523, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f054F->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0552 = less(r0549, body.constant(int(32)));
                  ir_if *f0551 = new(mem_ctx) ir_if(operand(r0552).val);
                  exec_list *const f0551_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0551->then_instructions;

                     body.emit(assign(r054A, lshift(r0524, r054D), 0x01));

                     ir_expression *const r0553 = lshift(r0523, r054D);
                     ir_expression *const r0554 = rshift(r0524, r0549);
                     body.emit(assign(r054B, bit_or(r0553, r0554), 0x01));

                     body.emit(assign(r054C, rshift(r0523, r0549), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0551->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0556 = equal(r0549, body.constant(int(32)));
                     ir_if *f0555 = new(mem_ctx) ir_if(operand(r0556).val);
                     exec_list *const f0555_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0555->then_instructions;

                        body.emit(assign(r054A, r0524, 0x01));

                        body.emit(assign(r054B, r0523, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0555->else_instructions;

                        body.emit(assign(r0548, bit_or(body.constant(0u), r0524), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0558 = less(r0549, body.constant(int(64)));
                        ir_if *f0557 = new(mem_ctx) ir_if(operand(r0558).val);
                        exec_list *const f0557_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0557->then_instructions;

                           body.emit(assign(r054A, lshift(r0523, r054D), 0x01));

                           ir_expression *const r0559 = bit_and(r0549, body.constant(int(31)));
                           body.emit(assign(r054B, rshift(r0523, r0559), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0557->else_instructions;

                           ir_variable *const r055A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r055C = equal(r0549, body.constant(int(64)));
                           ir_if *f055B = new(mem_ctx) ir_if(operand(r055C).val);
                           exec_list *const f055B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f055B->then_instructions;

                              body.emit(assign(r055A, r0523, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f055B->else_instructions;

                              ir_expression *const r055D = nequal(r0523, body.constant(0u));
                              ir_expression *const r055E = expr(ir_unop_b2i, r055D);
                              body.emit(assign(r055A, expr(ir_unop_i2u, r055E), 0x01));


                           body.instructions = f055B_parent_instructions;
                           body.emit(f055B);

                           /* END IF */

                           body.emit(assign(r054A, r055A, 0x01));

                           body.emit(assign(r054B, body.constant(0u), 0x01));


                        body.instructions = f0557_parent_instructions;
                        body.emit(f0557);

                        /* END IF */


                     body.instructions = f0555_parent_instructions;
                     body.emit(f0555);

                     /* END IF */

                     body.emit(assign(r054C, body.constant(0u), 0x01));


                  body.instructions = f0551_parent_instructions;
                  body.emit(f0551);

                  /* END IF */

                  ir_expression *const r055F = nequal(r0548, body.constant(0u));
                  ir_expression *const r0560 = expr(ir_unop_b2i, r055F);
                  ir_expression *const r0561 = expr(ir_unop_i2u, r0560);
                  body.emit(assign(r054A, bit_or(r054A, r0561), 0x01));


               body.instructions = f054F_parent_instructions;
               body.emit(f054F);

               /* END IF */

               body.emit(assign(r0523, r054C, 0x01));

               body.emit(assign(r0524, r054B, 0x01));

               body.emit(assign(r0525, r054A, 0x01));


            body.instructions = f053E_parent_instructions;
            body.emit(f053E);

            /* END IF */

            ir_expression *const r0562 = expr(ir_unop_i2u, r0526);
            body.emit(assign(r0522, sub(r0522, r0562), 0x01));

            ir_variable *const r0563 = body.make_temp(glsl_type::uint_type, "zExp");
            body.emit(assign(r0563, r0522, 0x01));

            ir_variable *const r0564 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0564, r0523, 0x01));

            ir_variable *const r0565 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0565, r0524, 0x01));

            ir_variable *const r0566 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0566, r0525, 0x01));

            ir_variable *const r0567 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0567, body.constant(true), 0x01));

            ir_variable *const r0568 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0569 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
            body.emit(r0569);
            ir_expression *const r056A = less(r0525, body.constant(0u));
            ir_expression *const r056B = expr(ir_unop_b2i, r056A);
            body.emit(assign(r0569, expr(ir_unop_i2u, r056B), 0x01));

            /* IF CONDITION */
            ir_expression *const r056D = lequal(body.constant(2045u), r0522);
            ir_if *f056C = new(mem_ctx) ir_if(operand(r056D).val);
            exec_list *const f056C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f056C->then_instructions;

               ir_variable *const r056E = body.make_temp(glsl_type::bool_type, "or_tmp");
               /* IF CONDITION */
               ir_expression *const r0570 = less(body.constant(2045u), r0522);
               ir_if *f056F = new(mem_ctx) ir_if(operand(r0570).val);
               exec_list *const f056F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f056F->then_instructions;

                  body.emit(assign(r056E, body.constant(true), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f056F->else_instructions;

                  ir_variable *const r0571 = body.make_temp(glsl_type::bool_type, "and_tmp");
                  /* IF CONDITION */
                  ir_expression *const r0573 = equal(r0522, body.constant(2045u));
                  ir_if *f0572 = new(mem_ctx) ir_if(operand(r0573).val);
                  exec_list *const f0572_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0572->then_instructions;

                     ir_expression *const r0574 = equal(body.constant(2097151u), r0523);
                     ir_expression *const r0575 = equal(body.constant(4294967295u), r0524);
                     body.emit(assign(r0571, logic_and(r0574, r0575), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0572->else_instructions;

                     body.emit(assign(r0571, body.constant(false), 0x01));


                  body.instructions = f0572_parent_instructions;
                  body.emit(f0572);

                  /* END IF */

                  ir_expression *const r0576 = nequal(r0569, body.constant(0u));
                  body.emit(assign(r056E, logic_and(r0571, r0576), 0x01));


               body.instructions = f056F_parent_instructions;
               body.emit(f056F);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0577 = new(mem_ctx) ir_if(operand(r056E).val);
               exec_list *const f0577_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0577->then_instructions;

                  ir_variable *const r0578 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0578);
                  ir_expression *const r0579 = lshift(r03E3, body.constant(int(31)));
                  body.emit(assign(r0578, add(r0579, body.constant(2146435072u)), 0x01));

                  body.emit(assign(r0578, body.constant(0u), 0x02));

                  body.emit(assign(r0568, r0578, 0x03));

                  body.emit(assign(r0567, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0577->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r057B = less(r0522, body.constant(0u));
                  ir_if *f057A = new(mem_ctx) ir_if(operand(r057B).val);
                  exec_list *const f057A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f057A->then_instructions;

                     ir_variable *const r057C = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r057C, r0525, 0x01));

                     ir_variable *const r057D = body.make_temp(glsl_type::int_type, "count");
                     ir_expression *const r057E = neg(r0522);
                     body.emit(assign(r057D, expr(ir_unop_u2i, r057E), 0x01));

                     ir_variable *const r057F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r057F);
                     ir_variable *const r0580 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0580);
                     ir_variable *const r0581 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0581);
                     ir_variable *const r0582 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0583 = neg(r057D);
                     body.emit(assign(r0582, bit_and(r0583, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0585 = equal(r057D, body.constant(int(0)));
                     ir_if *f0584 = new(mem_ctx) ir_if(operand(r0585).val);
                     exec_list *const f0584_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0584->then_instructions;

                        body.emit(assign(r057F, r0525, 0x01));

                        body.emit(assign(r0580, r0524, 0x01));

                        body.emit(assign(r0581, r0523, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0584->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0587 = less(r057D, body.constant(int(32)));
                        ir_if *f0586 = new(mem_ctx) ir_if(operand(r0587).val);
                        exec_list *const f0586_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0586->then_instructions;

                           body.emit(assign(r057F, lshift(r0524, r0582), 0x01));

                           ir_expression *const r0588 = lshift(r0523, r0582);
                           ir_expression *const r0589 = rshift(r0524, r057D);
                           body.emit(assign(r0580, bit_or(r0588, r0589), 0x01));

                           body.emit(assign(r0581, rshift(r0523, r057D), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0586->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r058B = equal(r057D, body.constant(int(32)));
                           ir_if *f058A = new(mem_ctx) ir_if(operand(r058B).val);
                           exec_list *const f058A_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f058A->then_instructions;

                              body.emit(assign(r057F, r0524, 0x01));

                              body.emit(assign(r0580, r0523, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f058A->else_instructions;

                              body.emit(assign(r057C, bit_or(r0525, r0524), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r058D = less(r057D, body.constant(int(64)));
                              ir_if *f058C = new(mem_ctx) ir_if(operand(r058D).val);
                              exec_list *const f058C_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f058C->then_instructions;

                                 body.emit(assign(r057F, lshift(r0523, r0582), 0x01));

                                 ir_expression *const r058E = bit_and(r057D, body.constant(int(31)));
                                 body.emit(assign(r0580, rshift(r0523, r058E), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f058C->else_instructions;

                                 ir_variable *const r058F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0591 = equal(r057D, body.constant(int(64)));
                                 ir_if *f0590 = new(mem_ctx) ir_if(operand(r0591).val);
                                 exec_list *const f0590_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0590->then_instructions;

                                    body.emit(assign(r058F, r0523, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0590->else_instructions;

                                    ir_expression *const r0592 = nequal(r0523, body.constant(0u));
                                    ir_expression *const r0593 = expr(ir_unop_b2i, r0592);
                                    body.emit(assign(r058F, expr(ir_unop_i2u, r0593), 0x01));


                                 body.instructions = f0590_parent_instructions;
                                 body.emit(f0590);

                                 /* END IF */

                                 body.emit(assign(r057F, r058F, 0x01));

                                 body.emit(assign(r0580, body.constant(0u), 0x01));


                              body.instructions = f058C_parent_instructions;
                              body.emit(f058C);

                              /* END IF */


                           body.instructions = f058A_parent_instructions;
                           body.emit(f058A);

                           /* END IF */

                           body.emit(assign(r0581, body.constant(0u), 0x01));


                        body.instructions = f0586_parent_instructions;
                        body.emit(f0586);

                        /* END IF */

                        ir_expression *const r0594 = nequal(r057C, body.constant(0u));
                        ir_expression *const r0595 = expr(ir_unop_b2i, r0594);
                        ir_expression *const r0596 = expr(ir_unop_i2u, r0595);
                        body.emit(assign(r057F, bit_or(r057F, r0596), 0x01));


                     body.instructions = f0584_parent_instructions;
                     body.emit(f0584);

                     /* END IF */

                     body.emit(assign(r0564, r0581, 0x01));

                     body.emit(assign(r0565, r0580, 0x01));

                     body.emit(assign(r0566, r057F, 0x01));

                     body.emit(assign(r0563, body.constant(0u), 0x01));

                     ir_expression *const r0597 = less(r057F, body.constant(0u));
                     ir_expression *const r0598 = expr(ir_unop_b2i, r0597);
                     body.emit(assign(r0569, expr(ir_unop_i2u, r0598), 0x01));


                  body.instructions = f057A_parent_instructions;
                  body.emit(f057A);

                  /* END IF */


               body.instructions = f0577_parent_instructions;
               body.emit(f0577);

               /* END IF */


            body.instructions = f056C_parent_instructions;
            body.emit(f056C);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0599 = new(mem_ctx) ir_if(operand(r0567).val);
            exec_list *const f0599_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0599->then_instructions;

               /* IF CONDITION */
               ir_expression *const r059B = nequal(r0569, body.constant(0u));
               ir_if *f059A = new(mem_ctx) ir_if(operand(r059B).val);
               exec_list *const f059A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f059A->then_instructions;

                  ir_variable *const r059C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r059C, add(r0565, body.constant(1u)), 0x01));

                  ir_expression *const r059D = less(r059C, r0565);
                  ir_expression *const r059E = expr(ir_unop_b2i, r059D);
                  ir_expression *const r059F = expr(ir_unop_i2u, r059E);
                  body.emit(assign(r0564, add(r0564, r059F), 0x01));

                  ir_expression *const r05A0 = neg(r0566);
                  ir_expression *const r05A1 = equal(r0566, r05A0);
                  ir_expression *const r05A2 = expr(ir_unop_b2i, r05A1);
                  ir_expression *const r05A3 = expr(ir_unop_i2u, r05A2);
                  ir_expression *const r05A4 = bit_and(r05A3, body.constant(1u));
                  ir_expression *const r05A5 = expr(ir_unop_bit_not, r05A4);
                  body.emit(assign(r0565, bit_and(r059C, r05A5), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f059A->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05A7 = bit_or(r0564, r0565);
                  ir_expression *const r05A8 = equal(r05A7, body.constant(0u));
                  ir_if *f05A6 = new(mem_ctx) ir_if(operand(r05A8).val);
                  exec_list *const f05A6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05A6->then_instructions;

                     body.emit(assign(r0563, body.constant(0u), 0x01));


                  body.instructions = f05A6_parent_instructions;
                  body.emit(f05A6);

                  /* END IF */


               body.instructions = f059A_parent_instructions;
               body.emit(f059A);

               /* END IF */

               ir_variable *const r05A9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r05A9);
               ir_expression *const r05AA = lshift(r03E3, body.constant(int(31)));
               ir_expression *const r05AB = lshift(r0563, body.constant(int(20)));
               ir_expression *const r05AC = add(r05AA, r05AB);
               body.emit(assign(r05A9, add(r05AC, r0564), 0x01));

               body.emit(assign(r05A9, r0565, 0x02));

               body.emit(assign(r0568, r05A9, 0x03));

               body.emit(assign(r0567, body.constant(false), 0x01));


            body.instructions = f0599_parent_instructions;
            body.emit(f0599);

            /* END IF */

            body.emit(assign(r03E4, r0568, 0x03));


         body.instructions = f04D4_parent_instructions;
         body.emit(f04D4);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f04D2->else_instructions;

         /* IF CONDITION */
         ir_expression *const r05AE = equal(r03EC, body.constant(2047u));
         ir_if *f05AD = new(mem_ctx) ir_if(operand(r05AE).val);
         exec_list *const f05AD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f05AD->then_instructions;

            /* IF CONDITION */
            ir_expression *const r05B0 = bit_or(swizzle_x(r03E9), swizzle_y(r03E9));
            ir_expression *const r05B1 = bit_or(swizzle_x(r03E7), swizzle_y(r03E7));
            ir_expression *const r05B2 = bit_or(r05B0, r05B1);
            ir_expression *const r05B3 = nequal(r05B2, body.constant(0u));
            ir_if *f05AF = new(mem_ctx) ir_if(operand(r05B3).val);
            exec_list *const f05AF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f05AF->then_instructions;

               ir_variable *const r05B4 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r05B4, swizzle_x(r03E1), 0x01));

               ir_variable *const r05B5 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r05B5, swizzle_x(r03E2), 0x01));

               ir_variable *const r05B6 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r05B7 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
               ir_expression *const r05B8 = rshift(swizzle_y(r03E1), body.constant(int(19)));
               ir_expression *const r05B9 = bit_and(r05B8, body.constant(4095u));
               ir_expression *const r05BA = equal(r05B9, body.constant(4094u));
               ir_expression *const r05BB = nequal(swizzle_x(r03E1), body.constant(0u));
               ir_expression *const r05BC = bit_and(swizzle_y(r03E1), body.constant(524287u));
               ir_expression *const r05BD = nequal(r05BC, body.constant(0u));
               ir_expression *const r05BE = logic_or(r05BB, r05BD);
               body.emit(assign(r05B7, logic_and(r05BA, r05BE), 0x01));

               ir_variable *const r05BF = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r05C0 = lshift(swizzle_y(r03E2), body.constant(int(1)));
               ir_expression *const r05C1 = lequal(body.constant(4292870144u), r05C0);
               ir_expression *const r05C2 = nequal(swizzle_x(r03E2), body.constant(0u));
               ir_expression *const r05C3 = bit_and(swizzle_y(r03E2), body.constant(1048575u));
               ir_expression *const r05C4 = nequal(r05C3, body.constant(0u));
               ir_expression *const r05C5 = logic_or(r05C2, r05C4);
               body.emit(assign(r05BF, logic_and(r05C1, r05C5), 0x01));

               body.emit(assign(r05B4, bit_or(swizzle_y(r03E1), body.constant(524288u)), 0x02));

               body.emit(assign(r05B5, bit_or(swizzle_y(r03E2), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r05C7 = lshift(swizzle_y(r03E1), body.constant(int(1)));
               ir_expression *const r05C8 = lequal(body.constant(4292870144u), r05C7);
               ir_expression *const r05C9 = nequal(swizzle_x(r03E1), body.constant(0u));
               ir_expression *const r05CA = bit_and(swizzle_y(r03E1), body.constant(1048575u));
               ir_expression *const r05CB = nequal(r05CA, body.constant(0u));
               ir_expression *const r05CC = logic_or(r05C9, r05CB);
               ir_expression *const r05CD = logic_and(r05C8, r05CC);
               ir_if *f05C6 = new(mem_ctx) ir_if(operand(r05CD).val);
               exec_list *const f05C6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f05C6->then_instructions;

                  ir_variable *const r05CE = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r05D0 = logic_and(r05B7, r05BF);
                  ir_if *f05CF = new(mem_ctx) ir_if(operand(r05D0).val);
                  exec_list *const f05CF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05CF->then_instructions;

                     body.emit(assign(r05CE, r05B5, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05CF->else_instructions;

                     body.emit(assign(r05CE, r05B4, 0x03));


                  body.instructions = f05CF_parent_instructions;
                  body.emit(f05CF);

                  /* END IF */

                  body.emit(assign(r05B6, r05CE, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f05C6->else_instructions;

                  body.emit(assign(r05B6, r05B5, 0x03));


               body.instructions = f05C6_parent_instructions;
               body.emit(f05C6);

               /* END IF */

               body.emit(assign(r03E4, r05B6, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f05AF->else_instructions;

               ir_constant_data r05D1_data;
               memset(&r05D1_data, 0, sizeof(ir_constant_data));
               r05D1_data.u[0] = 4294967295;
               r05D1_data.u[1] = 4294967295;
               ir_constant *const r05D1 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r05D1_data);
               body.emit(assign(r03E4, r05D1, 0x03));


            body.instructions = f05AF_parent_instructions;
            body.emit(f05AF);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f05AD->else_instructions;

            /* IF CONDITION */
            ir_expression *const r05D3 = equal(r03EC, body.constant(0u));
            ir_if *f05D2 = new(mem_ctx) ir_if(operand(r05D3).val);
            exec_list *const f05D2_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f05D2->then_instructions;

               body.emit(assign(r03E8, body.constant(1u), 0x01));

               body.emit(assign(r03E6, body.constant(1u), 0x01));


            body.instructions = f05D2_parent_instructions;
            body.emit(f05D2);

            /* END IF */

            /* IF CONDITION */
            ir_expression *const r05D5 = less(swizzle_x(r03E7), swizzle_x(r03E9));
            ir_if *f05D4 = new(mem_ctx) ir_if(operand(r05D5).val);
            exec_list *const f05D4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f05D4->then_instructions;

               ir_variable *const r05D6 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r05D7 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r05D7, sub(swizzle_y(r03E9), swizzle_y(r03E7)), 0x01));

               ir_expression *const r05D8 = sub(swizzle_x(r03E9), swizzle_x(r03E7));
               ir_expression *const r05D9 = less(swizzle_y(r03E9), swizzle_y(r03E7));
               ir_expression *const r05DA = expr(ir_unop_b2i, r05D9);
               ir_expression *const r05DB = expr(ir_unop_i2u, r05DA);
               body.emit(assign(r05D6, sub(r05D8, r05DB), 0x01));

               body.emit(assign(r03EA, add(r03E8, body.constant(4294967295u)), 0x01));

               ir_variable *const r05DC = body.make_temp(glsl_type::uint_type, "zExp");
               body.emit(assign(r05DC, add(r03EA, body.constant(4294967286u)), 0x01));

               ir_variable *const r05DD = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r05DD, r05D6, 0x01));

               ir_variable *const r05DE = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r05DE, r05D7, 0x01));

               ir_variable *const r05DF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r05DF);
               ir_variable *const r05E0 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r05E0);
               /* IF CONDITION */
               ir_expression *const r05E2 = equal(r05D6, body.constant(0u));
               ir_if *f05E1 = new(mem_ctx) ir_if(operand(r05E2).val);
               exec_list *const f05E1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f05E1->then_instructions;

                  body.emit(assign(r05DD, r05D7, 0x01));

                  body.emit(assign(r05DE, body.constant(0u), 0x01));

                  body.emit(assign(r05DC, add(r05DC, body.constant(4294967264u)), 0x01));


               body.instructions = f05E1_parent_instructions;
               body.emit(f05E1);

               /* END IF */

               ir_variable *const r05E3 = body.make_temp(glsl_type::uint_type, "a");
               body.emit(assign(r05E3, r05DD, 0x01));

               ir_variable *const r05E4 = body.make_temp(glsl_type::uint_type, "return_value");
               ir_variable *const r05E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
               body.emit(r05E5);
               /* IF CONDITION */
               ir_expression *const r05E7 = equal(r05DD, body.constant(0u));
               ir_if *f05E6 = new(mem_ctx) ir_if(operand(r05E7).val);
               exec_list *const f05E6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f05E6->then_instructions;

                  body.emit(assign(r05E4, body.constant(32u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f05E6->else_instructions;

                  body.emit(assign(r05E5, body.constant(0u), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r05E9 = bit_and(r05DD, body.constant(4294901760u));
                  ir_expression *const r05EA = equal(r05E9, body.constant(0u));
                  ir_if *f05E8 = new(mem_ctx) ir_if(operand(r05EA).val);
                  exec_list *const f05E8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05E8->then_instructions;

                     body.emit(assign(r05E5, body.constant(16u), 0x01));

                     body.emit(assign(r05E3, lshift(r05DD, body.constant(int(16))), 0x01));


                  body.instructions = f05E8_parent_instructions;
                  body.emit(f05E8);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r05EC = bit_and(r05E3, body.constant(4278190080u));
                  ir_expression *const r05ED = equal(r05EC, body.constant(0u));
                  ir_if *f05EB = new(mem_ctx) ir_if(operand(r05ED).val);
                  exec_list *const f05EB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05EB->then_instructions;

                     body.emit(assign(r05E5, add(r05E5, body.constant(8u)), 0x01));

                     body.emit(assign(r05E3, lshift(r05E3, body.constant(int(8))), 0x01));


                  body.instructions = f05EB_parent_instructions;
                  body.emit(f05EB);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r05EF = bit_and(r05E3, body.constant(4026531840u));
                  ir_expression *const r05F0 = equal(r05EF, body.constant(0u));
                  ir_if *f05EE = new(mem_ctx) ir_if(operand(r05F0).val);
                  exec_list *const f05EE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05EE->then_instructions;

                     body.emit(assign(r05E5, add(r05E5, body.constant(4u)), 0x01));

                     body.emit(assign(r05E3, lshift(r05E3, body.constant(int(4))), 0x01));


                  body.instructions = f05EE_parent_instructions;
                  body.emit(f05EE);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r05F2 = bit_and(r05E3, body.constant(3221225472u));
                  ir_expression *const r05F3 = equal(r05F2, body.constant(0u));
                  ir_if *f05F1 = new(mem_ctx) ir_if(operand(r05F3).val);
                  exec_list *const f05F1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05F1->then_instructions;

                     body.emit(assign(r05E5, add(r05E5, body.constant(2u)), 0x01));

                     body.emit(assign(r05E3, lshift(r05E3, body.constant(int(2))), 0x01));


                  body.instructions = f05F1_parent_instructions;
                  body.emit(f05F1);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r05F5 = bit_and(r05E3, body.constant(2147483648u));
                  ir_expression *const r05F6 = equal(r05F5, body.constant(0u));
                  ir_if *f05F4 = new(mem_ctx) ir_if(operand(r05F6).val);
                  exec_list *const f05F4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05F4->then_instructions;

                     body.emit(assign(r05E5, add(r05E5, body.constant(1u)), 0x01));


                  body.instructions = f05F4_parent_instructions;
                  body.emit(f05F4);

                  /* END IF */

                  body.emit(assign(r05E4, r05E5, 0x01));


               body.instructions = f05E6_parent_instructions;
               body.emit(f05E6);

               /* END IF */

               ir_expression *const r05F7 = expr(ir_unop_u2i, r05E4);
               body.emit(assign(r05E0, add(r05F7, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r05F9 = lequal(body.constant(int(0)), r05E0);
               ir_if *f05F8 = new(mem_ctx) ir_if(operand(r05F9).val);
               exec_list *const f05F8_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f05F8->then_instructions;

                  body.emit(assign(r05DF, body.constant(0u), 0x01));

                  ir_variable *const r05FA = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r05FA, lshift(r05DE, r05E0), 0x01));

                  ir_variable *const r05FB = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r05FD = equal(r05E0, body.constant(int(0)));
                  ir_if *f05FC = new(mem_ctx) ir_if(operand(r05FD).val);
                  exec_list *const f05FC_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05FC->then_instructions;

                     body.emit(assign(r05FB, r05DD, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05FC->else_instructions;

                     ir_expression *const r05FE = lshift(r05DD, r05E0);
                     ir_expression *const r05FF = neg(r05E0);
                     ir_expression *const r0600 = bit_and(r05FF, body.constant(int(31)));
                     ir_expression *const r0601 = rshift(r05DE, r0600);
                     body.emit(assign(r05FB, bit_or(r05FE, r0601), 0x01));


                  body.instructions = f05FC_parent_instructions;
                  body.emit(f05FC);

                  /* END IF */

                  body.emit(assign(r05DD, r05FB, 0x01));

                  body.emit(assign(r05DE, r05FA, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f05F8->else_instructions;

                  ir_variable *const r0602 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r0602, body.constant(0u), 0x01));

                  ir_variable *const r0603 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r0603, neg(r05E0), 0x01));

                  ir_variable *const r0604 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0604);
                  ir_variable *const r0605 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r0605);
                  ir_variable *const r0606 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r0606);
                  ir_variable *const r0607 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r0608 = neg(r0603);
                  body.emit(assign(r0607, bit_and(r0608, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r060A = equal(r0603, body.constant(int(0)));
                  ir_if *f0609 = new(mem_ctx) ir_if(operand(r060A).val);
                  exec_list *const f0609_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0609->then_instructions;

                     body.emit(assign(r0604, r0602, 0x01));

                     body.emit(assign(r0605, r05DE, 0x01));

                     body.emit(assign(r0606, r05DD, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0609->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r060C = less(r0603, body.constant(int(32)));
                     ir_if *f060B = new(mem_ctx) ir_if(operand(r060C).val);
                     exec_list *const f060B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f060B->then_instructions;

                        body.emit(assign(r0604, lshift(r05DE, r0607), 0x01));

                        ir_expression *const r060D = lshift(r05DD, r0607);
                        ir_expression *const r060E = rshift(r05DE, r0603);
                        body.emit(assign(r0605, bit_or(r060D, r060E), 0x01));

                        body.emit(assign(r0606, rshift(r05DD, r0603), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f060B->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0610 = equal(r0603, body.constant(int(32)));
                        ir_if *f060F = new(mem_ctx) ir_if(operand(r0610).val);
                        exec_list *const f060F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f060F->then_instructions;

                           body.emit(assign(r0604, r05DE, 0x01));

                           body.emit(assign(r0605, r05DD, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f060F->else_instructions;

                           body.emit(assign(r0602, bit_or(body.constant(0u), r05DE), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0612 = less(r0603, body.constant(int(64)));
                           ir_if *f0611 = new(mem_ctx) ir_if(operand(r0612).val);
                           exec_list *const f0611_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0611->then_instructions;

                              body.emit(assign(r0604, lshift(r05DD, r0607), 0x01));

                              ir_expression *const r0613 = bit_and(r0603, body.constant(int(31)));
                              body.emit(assign(r0605, rshift(r05DD, r0613), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0611->else_instructions;

                              ir_variable *const r0614 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r0616 = equal(r0603, body.constant(int(64)));
                              ir_if *f0615 = new(mem_ctx) ir_if(operand(r0616).val);
                              exec_list *const f0615_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0615->then_instructions;

                                 body.emit(assign(r0614, r05DD, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0615->else_instructions;

                                 ir_expression *const r0617 = nequal(r05DD, body.constant(0u));
                                 ir_expression *const r0618 = expr(ir_unop_b2i, r0617);
                                 body.emit(assign(r0614, expr(ir_unop_i2u, r0618), 0x01));


                              body.instructions = f0615_parent_instructions;
                              body.emit(f0615);

                              /* END IF */

                              body.emit(assign(r0604, r0614, 0x01));

                              body.emit(assign(r0605, body.constant(0u), 0x01));


                           body.instructions = f0611_parent_instructions;
                           body.emit(f0611);

                           /* END IF */


                        body.instructions = f060F_parent_instructions;
                        body.emit(f060F);

                        /* END IF */

                        body.emit(assign(r0606, body.constant(0u), 0x01));


                     body.instructions = f060B_parent_instructions;
                     body.emit(f060B);

                     /* END IF */

                     ir_expression *const r0619 = nequal(r0602, body.constant(0u));
                     ir_expression *const r061A = expr(ir_unop_b2i, r0619);
                     ir_expression *const r061B = expr(ir_unop_i2u, r061A);
                     body.emit(assign(r0604, bit_or(r0604, r061B), 0x01));


                  body.instructions = f0609_parent_instructions;
                  body.emit(f0609);

                  /* END IF */

                  body.emit(assign(r05DD, r0606, 0x01));

                  body.emit(assign(r05DE, r0605, 0x01));

                  body.emit(assign(r05DF, r0604, 0x01));


               body.instructions = f05F8_parent_instructions;
               body.emit(f05F8);

               /* END IF */

               ir_expression *const r061C = expr(ir_unop_i2u, r05E0);
               body.emit(assign(r05DC, sub(r05DC, r061C), 0x01));

               ir_variable *const r061D = body.make_temp(glsl_type::uint_type, "zExp");
               body.emit(assign(r061D, r05DC, 0x01));

               ir_variable *const r061E = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r061E, r05DD, 0x01));

               ir_variable *const r061F = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r061F, r05DE, 0x01));

               ir_variable *const r0620 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r0620, r05DF, 0x01));

               ir_variable *const r0621 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0621, body.constant(true), 0x01));

               ir_variable *const r0622 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0623 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
               body.emit(r0623);
               ir_expression *const r0624 = less(r05DF, body.constant(0u));
               ir_expression *const r0625 = expr(ir_unop_b2i, r0624);
               body.emit(assign(r0623, expr(ir_unop_i2u, r0625), 0x01));

               /* IF CONDITION */
               ir_expression *const r0627 = lequal(body.constant(2045u), r05DC);
               ir_if *f0626 = new(mem_ctx) ir_if(operand(r0627).val);
               exec_list *const f0626_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0626->then_instructions;

                  ir_variable *const r0628 = body.make_temp(glsl_type::bool_type, "or_tmp");
                  /* IF CONDITION */
                  ir_expression *const r062A = less(body.constant(2045u), r05DC);
                  ir_if *f0629 = new(mem_ctx) ir_if(operand(r062A).val);
                  exec_list *const f0629_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0629->then_instructions;

                     body.emit(assign(r0628, body.constant(true), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0629->else_instructions;

                     ir_variable *const r062B = body.make_temp(glsl_type::bool_type, "and_tmp");
                     /* IF CONDITION */
                     ir_expression *const r062D = equal(r05DC, body.constant(2045u));
                     ir_if *f062C = new(mem_ctx) ir_if(operand(r062D).val);
                     exec_list *const f062C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f062C->then_instructions;

                        ir_expression *const r062E = equal(body.constant(2097151u), r05DD);
                        ir_expression *const r062F = equal(body.constant(4294967295u), r05DE);
                        body.emit(assign(r062B, logic_and(r062E, r062F), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f062C->else_instructions;

                        body.emit(assign(r062B, body.constant(false), 0x01));


                     body.instructions = f062C_parent_instructions;
                     body.emit(f062C);

                     /* END IF */

                     ir_expression *const r0630 = nequal(r0623, body.constant(0u));
                     body.emit(assign(r0628, logic_and(r062B, r0630), 0x01));


                  body.instructions = f0629_parent_instructions;
                  body.emit(f0629);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0631 = new(mem_ctx) ir_if(operand(r0628).val);
                  exec_list *const f0631_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0631->then_instructions;

                     ir_variable *const r0632 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0632);
                     ir_expression *const r0633 = lshift(r03E3, body.constant(int(31)));
                     body.emit(assign(r0632, add(r0633, body.constant(2146435072u)), 0x01));

                     body.emit(assign(r0632, body.constant(0u), 0x02));

                     body.emit(assign(r0622, r0632, 0x03));

                     body.emit(assign(r0621, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0631->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0635 = less(r05DC, body.constant(0u));
                     ir_if *f0634 = new(mem_ctx) ir_if(operand(r0635).val);
                     exec_list *const f0634_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0634->then_instructions;

                        ir_variable *const r0636 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0636, r05DF, 0x01));

                        ir_variable *const r0637 = body.make_temp(glsl_type::int_type, "count");
                        ir_expression *const r0638 = neg(r05DC);
                        body.emit(assign(r0637, expr(ir_unop_u2i, r0638), 0x01));

                        ir_variable *const r0639 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0639);
                        ir_variable *const r063A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r063A);
                        ir_variable *const r063B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r063B);
                        ir_variable *const r063C = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r063D = neg(r0637);
                        body.emit(assign(r063C, bit_and(r063D, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r063F = equal(r0637, body.constant(int(0)));
                        ir_if *f063E = new(mem_ctx) ir_if(operand(r063F).val);
                        exec_list *const f063E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f063E->then_instructions;

                           body.emit(assign(r0639, r05DF, 0x01));

                           body.emit(assign(r063A, r05DE, 0x01));

                           body.emit(assign(r063B, r05DD, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f063E->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0641 = less(r0637, body.constant(int(32)));
                           ir_if *f0640 = new(mem_ctx) ir_if(operand(r0641).val);
                           exec_list *const f0640_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0640->then_instructions;

                              body.emit(assign(r0639, lshift(r05DE, r063C), 0x01));

                              ir_expression *const r0642 = lshift(r05DD, r063C);
                              ir_expression *const r0643 = rshift(r05DE, r0637);
                              body.emit(assign(r063A, bit_or(r0642, r0643), 0x01));

                              body.emit(assign(r063B, rshift(r05DD, r0637), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0640->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0645 = equal(r0637, body.constant(int(32)));
                              ir_if *f0644 = new(mem_ctx) ir_if(operand(r0645).val);
                              exec_list *const f0644_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0644->then_instructions;

                                 body.emit(assign(r0639, r05DE, 0x01));

                                 body.emit(assign(r063A, r05DD, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0644->else_instructions;

                                 body.emit(assign(r0636, bit_or(r05DF, r05DE), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0647 = less(r0637, body.constant(int(64)));
                                 ir_if *f0646 = new(mem_ctx) ir_if(operand(r0647).val);
                                 exec_list *const f0646_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0646->then_instructions;

                                    body.emit(assign(r0639, lshift(r05DD, r063C), 0x01));

                                    ir_expression *const r0648 = bit_and(r0637, body.constant(int(31)));
                                    body.emit(assign(r063A, rshift(r05DD, r0648), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0646->else_instructions;

                                    ir_variable *const r0649 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r064B = equal(r0637, body.constant(int(64)));
                                    ir_if *f064A = new(mem_ctx) ir_if(operand(r064B).val);
                                    exec_list *const f064A_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f064A->then_instructions;

                                       body.emit(assign(r0649, r05DD, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f064A->else_instructions;

                                       ir_expression *const r064C = nequal(r05DD, body.constant(0u));
                                       ir_expression *const r064D = expr(ir_unop_b2i, r064C);
                                       body.emit(assign(r0649, expr(ir_unop_i2u, r064D), 0x01));


                                    body.instructions = f064A_parent_instructions;
                                    body.emit(f064A);

                                    /* END IF */

                                    body.emit(assign(r0639, r0649, 0x01));

                                    body.emit(assign(r063A, body.constant(0u), 0x01));


                                 body.instructions = f0646_parent_instructions;
                                 body.emit(f0646);

                                 /* END IF */


                              body.instructions = f0644_parent_instructions;
                              body.emit(f0644);

                              /* END IF */

                              body.emit(assign(r063B, body.constant(0u), 0x01));


                           body.instructions = f0640_parent_instructions;
                           body.emit(f0640);

                           /* END IF */

                           ir_expression *const r064E = nequal(r0636, body.constant(0u));
                           ir_expression *const r064F = expr(ir_unop_b2i, r064E);
                           ir_expression *const r0650 = expr(ir_unop_i2u, r064F);
                           body.emit(assign(r0639, bit_or(r0639, r0650), 0x01));


                        body.instructions = f063E_parent_instructions;
                        body.emit(f063E);

                        /* END IF */

                        body.emit(assign(r061E, r063B, 0x01));

                        body.emit(assign(r061F, r063A, 0x01));

                        body.emit(assign(r0620, r0639, 0x01));

                        body.emit(assign(r061D, body.constant(0u), 0x01));

                        ir_expression *const r0651 = less(r0639, body.constant(0u));
                        ir_expression *const r0652 = expr(ir_unop_b2i, r0651);
                        body.emit(assign(r0623, expr(ir_unop_i2u, r0652), 0x01));


                     body.instructions = f0634_parent_instructions;
                     body.emit(f0634);

                     /* END IF */


                  body.instructions = f0631_parent_instructions;
                  body.emit(f0631);

                  /* END IF */


               body.instructions = f0626_parent_instructions;
               body.emit(f0626);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0653 = new(mem_ctx) ir_if(operand(r0621).val);
               exec_list *const f0653_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0653->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0655 = nequal(r0623, body.constant(0u));
                  ir_if *f0654 = new(mem_ctx) ir_if(operand(r0655).val);
                  exec_list *const f0654_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0654->then_instructions;

                     ir_variable *const r0656 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0656, add(r061F, body.constant(1u)), 0x01));

                     ir_expression *const r0657 = less(r0656, r061F);
                     ir_expression *const r0658 = expr(ir_unop_b2i, r0657);
                     ir_expression *const r0659 = expr(ir_unop_i2u, r0658);
                     body.emit(assign(r061E, add(r061E, r0659), 0x01));

                     ir_expression *const r065A = neg(r0620);
                     ir_expression *const r065B = equal(r0620, r065A);
                     ir_expression *const r065C = expr(ir_unop_b2i, r065B);
                     ir_expression *const r065D = expr(ir_unop_i2u, r065C);
                     ir_expression *const r065E = bit_and(r065D, body.constant(1u));
                     ir_expression *const r065F = expr(ir_unop_bit_not, r065E);
                     body.emit(assign(r061F, bit_and(r0656, r065F), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0654->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0661 = bit_or(r061E, r061F);
                     ir_expression *const r0662 = equal(r0661, body.constant(0u));
                     ir_if *f0660 = new(mem_ctx) ir_if(operand(r0662).val);
                     exec_list *const f0660_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0660->then_instructions;

                        body.emit(assign(r061D, body.constant(0u), 0x01));


                     body.instructions = f0660_parent_instructions;
                     body.emit(f0660);

                     /* END IF */


                  body.instructions = f0654_parent_instructions;
                  body.emit(f0654);

                  /* END IF */

                  ir_variable *const r0663 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0663);
                  ir_expression *const r0664 = lshift(r03E3, body.constant(int(31)));
                  ir_expression *const r0665 = lshift(r061D, body.constant(int(20)));
                  ir_expression *const r0666 = add(r0664, r0665);
                  body.emit(assign(r0663, add(r0666, r061E), 0x01));

                  body.emit(assign(r0663, r061F, 0x02));

                  body.emit(assign(r0622, r0663, 0x03));

                  body.emit(assign(r0621, body.constant(false), 0x01));


               body.instructions = f0653_parent_instructions;
               body.emit(f0653);

               /* END IF */

               body.emit(assign(r03E4, r0622, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f05D4->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0668 = less(swizzle_x(r03E9), swizzle_x(r03E7));
               ir_if *f0667 = new(mem_ctx) ir_if(operand(r0668).val);
               exec_list *const f0667_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0667->then_instructions;

                  ir_variable *const r0669 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_variable *const r066A = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r066A, sub(swizzle_y(r03E7), swizzle_y(r03E9)), 0x01));

                  ir_expression *const r066B = sub(swizzle_x(r03E7), swizzle_x(r03E9));
                  ir_expression *const r066C = less(swizzle_y(r03E7), swizzle_y(r03E9));
                  ir_expression *const r066D = expr(ir_unop_b2i, r066C);
                  ir_expression *const r066E = expr(ir_unop_i2u, r066D);
                  body.emit(assign(r0669, sub(r066B, r066E), 0x01));

                  body.emit(assign(r03E3, bit_xor(r03E3, body.constant(1u)), 0x01));

                  body.emit(assign(r03EA, add(r03E6, body.constant(4294967295u)), 0x01));

                  ir_variable *const r066F = body.make_temp(glsl_type::uint_type, "zExp");
                  body.emit(assign(r066F, add(r03EA, body.constant(4294967286u)), 0x01));

                  ir_variable *const r0670 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0670, r0669, 0x01));

                  ir_variable *const r0671 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0671, r066A, 0x01));

                  ir_variable *const r0672 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r0672);
                  ir_variable *const r0673 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0673);
                  /* IF CONDITION */
                  ir_expression *const r0675 = equal(r0669, body.constant(0u));
                  ir_if *f0674 = new(mem_ctx) ir_if(operand(r0675).val);
                  exec_list *const f0674_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0674->then_instructions;

                     body.emit(assign(r0670, r066A, 0x01));

                     body.emit(assign(r0671, body.constant(0u), 0x01));

                     body.emit(assign(r066F, add(r066F, body.constant(4294967264u)), 0x01));


                  body.instructions = f0674_parent_instructions;
                  body.emit(f0674);

                  /* END IF */

                  ir_variable *const r0676 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r0676, r0670, 0x01));

                  ir_variable *const r0677 = body.make_temp(glsl_type::uint_type, "return_value");
                  ir_variable *const r0678 = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
                  body.emit(r0678);
                  /* IF CONDITION */
                  ir_expression *const r067A = equal(r0670, body.constant(0u));
                  ir_if *f0679 = new(mem_ctx) ir_if(operand(r067A).val);
                  exec_list *const f0679_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0679->then_instructions;

                     body.emit(assign(r0677, body.constant(32u), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0679->else_instructions;

                     body.emit(assign(r0678, body.constant(0u), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r067C = bit_and(r0670, body.constant(4294901760u));
                     ir_expression *const r067D = equal(r067C, body.constant(0u));
                     ir_if *f067B = new(mem_ctx) ir_if(operand(r067D).val);
                     exec_list *const f067B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f067B->then_instructions;

                        body.emit(assign(r0678, body.constant(16u), 0x01));

                        body.emit(assign(r0676, lshift(r0670, body.constant(int(16))), 0x01));


                     body.instructions = f067B_parent_instructions;
                     body.emit(f067B);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r067F = bit_and(r0676, body.constant(4278190080u));
                     ir_expression *const r0680 = equal(r067F, body.constant(0u));
                     ir_if *f067E = new(mem_ctx) ir_if(operand(r0680).val);
                     exec_list *const f067E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f067E->then_instructions;

                        body.emit(assign(r0678, add(r0678, body.constant(8u)), 0x01));

                        body.emit(assign(r0676, lshift(r0676, body.constant(int(8))), 0x01));


                     body.instructions = f067E_parent_instructions;
                     body.emit(f067E);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0682 = bit_and(r0676, body.constant(4026531840u));
                     ir_expression *const r0683 = equal(r0682, body.constant(0u));
                     ir_if *f0681 = new(mem_ctx) ir_if(operand(r0683).val);
                     exec_list *const f0681_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0681->then_instructions;

                        body.emit(assign(r0678, add(r0678, body.constant(4u)), 0x01));

                        body.emit(assign(r0676, lshift(r0676, body.constant(int(4))), 0x01));


                     body.instructions = f0681_parent_instructions;
                     body.emit(f0681);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0685 = bit_and(r0676, body.constant(3221225472u));
                     ir_expression *const r0686 = equal(r0685, body.constant(0u));
                     ir_if *f0684 = new(mem_ctx) ir_if(operand(r0686).val);
                     exec_list *const f0684_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0684->then_instructions;

                        body.emit(assign(r0678, add(r0678, body.constant(2u)), 0x01));

                        body.emit(assign(r0676, lshift(r0676, body.constant(int(2))), 0x01));


                     body.instructions = f0684_parent_instructions;
                     body.emit(f0684);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0688 = bit_and(r0676, body.constant(2147483648u));
                     ir_expression *const r0689 = equal(r0688, body.constant(0u));
                     ir_if *f0687 = new(mem_ctx) ir_if(operand(r0689).val);
                     exec_list *const f0687_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0687->then_instructions;

                        body.emit(assign(r0678, add(r0678, body.constant(1u)), 0x01));


                     body.instructions = f0687_parent_instructions;
                     body.emit(f0687);

                     /* END IF */

                     body.emit(assign(r0677, r0678, 0x01));


                  body.instructions = f0679_parent_instructions;
                  body.emit(f0679);

                  /* END IF */

                  ir_expression *const r068A = expr(ir_unop_u2i, r0677);
                  body.emit(assign(r0673, add(r068A, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r068C = lequal(body.constant(int(0)), r0673);
                  ir_if *f068B = new(mem_ctx) ir_if(operand(r068C).val);
                  exec_list *const f068B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f068B->then_instructions;

                     body.emit(assign(r0672, body.constant(0u), 0x01));

                     ir_variable *const r068D = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r068D, lshift(r0671, r0673), 0x01));

                     ir_variable *const r068E = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0690 = equal(r0673, body.constant(int(0)));
                     ir_if *f068F = new(mem_ctx) ir_if(operand(r0690).val);
                     exec_list *const f068F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f068F->then_instructions;

                        body.emit(assign(r068E, r0670, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f068F->else_instructions;

                        ir_expression *const r0691 = lshift(r0670, r0673);
                        ir_expression *const r0692 = neg(r0673);
                        ir_expression *const r0693 = bit_and(r0692, body.constant(int(31)));
                        ir_expression *const r0694 = rshift(r0671, r0693);
                        body.emit(assign(r068E, bit_or(r0691, r0694), 0x01));


                     body.instructions = f068F_parent_instructions;
                     body.emit(f068F);

                     /* END IF */

                     body.emit(assign(r0670, r068E, 0x01));

                     body.emit(assign(r0671, r068D, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f068B->else_instructions;

                     ir_variable *const r0695 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0695, body.constant(0u), 0x01));

                     ir_variable *const r0696 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0696, neg(r0673), 0x01));

                     ir_variable *const r0697 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0697);
                     ir_variable *const r0698 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0698);
                     ir_variable *const r0699 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0699);
                     ir_variable *const r069A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r069B = neg(r0696);
                     body.emit(assign(r069A, bit_and(r069B, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r069D = equal(r0696, body.constant(int(0)));
                     ir_if *f069C = new(mem_ctx) ir_if(operand(r069D).val);
                     exec_list *const f069C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f069C->then_instructions;

                        body.emit(assign(r0697, r0695, 0x01));

                        body.emit(assign(r0698, r0671, 0x01));

                        body.emit(assign(r0699, r0670, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f069C->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r069F = less(r0696, body.constant(int(32)));
                        ir_if *f069E = new(mem_ctx) ir_if(operand(r069F).val);
                        exec_list *const f069E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f069E->then_instructions;

                           body.emit(assign(r0697, lshift(r0671, r069A), 0x01));

                           ir_expression *const r06A0 = lshift(r0670, r069A);
                           ir_expression *const r06A1 = rshift(r0671, r0696);
                           body.emit(assign(r0698, bit_or(r06A0, r06A1), 0x01));

                           body.emit(assign(r0699, rshift(r0670, r0696), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f069E->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r06A3 = equal(r0696, body.constant(int(32)));
                           ir_if *f06A2 = new(mem_ctx) ir_if(operand(r06A3).val);
                           exec_list *const f06A2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06A2->then_instructions;

                              body.emit(assign(r0697, r0671, 0x01));

                              body.emit(assign(r0698, r0670, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06A2->else_instructions;

                              body.emit(assign(r0695, bit_or(body.constant(0u), r0671), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r06A5 = less(r0696, body.constant(int(64)));
                              ir_if *f06A4 = new(mem_ctx) ir_if(operand(r06A5).val);
                              exec_list *const f06A4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06A4->then_instructions;

                                 body.emit(assign(r0697, lshift(r0670, r069A), 0x01));

                                 ir_expression *const r06A6 = bit_and(r0696, body.constant(int(31)));
                                 body.emit(assign(r0698, rshift(r0670, r06A6), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06A4->else_instructions;

                                 ir_variable *const r06A7 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r06A9 = equal(r0696, body.constant(int(64)));
                                 ir_if *f06A8 = new(mem_ctx) ir_if(operand(r06A9).val);
                                 exec_list *const f06A8_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06A8->then_instructions;

                                    body.emit(assign(r06A7, r0670, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06A8->else_instructions;

                                    ir_expression *const r06AA = nequal(r0670, body.constant(0u));
                                    ir_expression *const r06AB = expr(ir_unop_b2i, r06AA);
                                    body.emit(assign(r06A7, expr(ir_unop_i2u, r06AB), 0x01));


                                 body.instructions = f06A8_parent_instructions;
                                 body.emit(f06A8);

                                 /* END IF */

                                 body.emit(assign(r0697, r06A7, 0x01));

                                 body.emit(assign(r0698, body.constant(0u), 0x01));


                              body.instructions = f06A4_parent_instructions;
                              body.emit(f06A4);

                              /* END IF */


                           body.instructions = f06A2_parent_instructions;
                           body.emit(f06A2);

                           /* END IF */

                           body.emit(assign(r0699, body.constant(0u), 0x01));


                        body.instructions = f069E_parent_instructions;
                        body.emit(f069E);

                        /* END IF */

                        ir_expression *const r06AC = nequal(r0695, body.constant(0u));
                        ir_expression *const r06AD = expr(ir_unop_b2i, r06AC);
                        ir_expression *const r06AE = expr(ir_unop_i2u, r06AD);
                        body.emit(assign(r0697, bit_or(r0697, r06AE), 0x01));


                     body.instructions = f069C_parent_instructions;
                     body.emit(f069C);

                     /* END IF */

                     body.emit(assign(r0670, r0699, 0x01));

                     body.emit(assign(r0671, r0698, 0x01));

                     body.emit(assign(r0672, r0697, 0x01));


                  body.instructions = f068B_parent_instructions;
                  body.emit(f068B);

                  /* END IF */

                  ir_expression *const r06AF = expr(ir_unop_i2u, r0673);
                  body.emit(assign(r066F, sub(r066F, r06AF), 0x01));

                  ir_variable *const r06B0 = body.make_temp(glsl_type::uint_type, "zExp");
                  body.emit(assign(r06B0, r066F, 0x01));

                  ir_variable *const r06B1 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r06B1, r0670, 0x01));

                  ir_variable *const r06B2 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r06B2, r0671, 0x01));

                  ir_variable *const r06B3 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r06B3, r0672, 0x01));

                  ir_variable *const r06B4 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r06B4, body.constant(true), 0x01));

                  ir_variable *const r06B5 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r06B6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
                  body.emit(r06B6);
                  ir_expression *const r06B7 = less(r0672, body.constant(0u));
                  ir_expression *const r06B8 = expr(ir_unop_b2i, r06B7);
                  body.emit(assign(r06B6, expr(ir_unop_i2u, r06B8), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r06BA = lequal(body.constant(2045u), r066F);
                  ir_if *f06B9 = new(mem_ctx) ir_if(operand(r06BA).val);
                  exec_list *const f06B9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f06B9->then_instructions;

                     ir_variable *const r06BB = body.make_temp(glsl_type::bool_type, "or_tmp");
                     /* IF CONDITION */
                     ir_expression *const r06BD = less(body.constant(2045u), r066F);
                     ir_if *f06BC = new(mem_ctx) ir_if(operand(r06BD).val);
                     exec_list *const f06BC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f06BC->then_instructions;

                        body.emit(assign(r06BB, body.constant(true), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f06BC->else_instructions;

                        ir_variable *const r06BE = body.make_temp(glsl_type::bool_type, "and_tmp");
                        /* IF CONDITION */
                        ir_expression *const r06C0 = equal(r066F, body.constant(2045u));
                        ir_if *f06BF = new(mem_ctx) ir_if(operand(r06C0).val);
                        exec_list *const f06BF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06BF->then_instructions;

                           ir_expression *const r06C1 = equal(body.constant(2097151u), r0670);
                           ir_expression *const r06C2 = equal(body.constant(4294967295u), r0671);
                           body.emit(assign(r06BE, logic_and(r06C1, r06C2), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06BF->else_instructions;

                           body.emit(assign(r06BE, body.constant(false), 0x01));


                        body.instructions = f06BF_parent_instructions;
                        body.emit(f06BF);

                        /* END IF */

                        ir_expression *const r06C3 = nequal(r06B6, body.constant(0u));
                        body.emit(assign(r06BB, logic_and(r06BE, r06C3), 0x01));


                     body.instructions = f06BC_parent_instructions;
                     body.emit(f06BC);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f06C4 = new(mem_ctx) ir_if(operand(r06BB).val);
                     exec_list *const f06C4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f06C4->then_instructions;

                        ir_variable *const r06C5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r06C5);
                        ir_expression *const r06C6 = lshift(r03E3, body.constant(int(31)));
                        body.emit(assign(r06C5, add(r06C6, body.constant(2146435072u)), 0x01));

                        body.emit(assign(r06C5, body.constant(0u), 0x02));

                        body.emit(assign(r06B5, r06C5, 0x03));

                        body.emit(assign(r06B4, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f06C4->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r06C8 = less(r066F, body.constant(0u));
                        ir_if *f06C7 = new(mem_ctx) ir_if(operand(r06C8).val);
                        exec_list *const f06C7_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06C7->then_instructions;

                           ir_variable *const r06C9 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r06C9, r0672, 0x01));

                           ir_variable *const r06CA = body.make_temp(glsl_type::int_type, "count");
                           ir_expression *const r06CB = neg(r066F);
                           body.emit(assign(r06CA, expr(ir_unop_u2i, r06CB), 0x01));

                           ir_variable *const r06CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r06CC);
                           ir_variable *const r06CD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r06CD);
                           ir_variable *const r06CE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r06CE);
                           ir_variable *const r06CF = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r06D0 = neg(r06CA);
                           body.emit(assign(r06CF, bit_and(r06D0, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r06D2 = equal(r06CA, body.constant(int(0)));
                           ir_if *f06D1 = new(mem_ctx) ir_if(operand(r06D2).val);
                           exec_list *const f06D1_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06D1->then_instructions;

                              body.emit(assign(r06CC, r0672, 0x01));

                              body.emit(assign(r06CD, r0671, 0x01));

                              body.emit(assign(r06CE, r0670, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06D1->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06D4 = less(r06CA, body.constant(int(32)));
                              ir_if *f06D3 = new(mem_ctx) ir_if(operand(r06D4).val);
                              exec_list *const f06D3_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06D3->then_instructions;

                                 body.emit(assign(r06CC, lshift(r0671, r06CF), 0x01));

                                 ir_expression *const r06D5 = lshift(r0670, r06CF);
                                 ir_expression *const r06D6 = rshift(r0671, r06CA);
                                 body.emit(assign(r06CD, bit_or(r06D5, r06D6), 0x01));

                                 body.emit(assign(r06CE, rshift(r0670, r06CA), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06D3->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06D8 = equal(r06CA, body.constant(int(32)));
                                 ir_if *f06D7 = new(mem_ctx) ir_if(operand(r06D8).val);
                                 exec_list *const f06D7_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06D7->then_instructions;

                                    body.emit(assign(r06CC, r0671, 0x01));

                                    body.emit(assign(r06CD, r0670, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06D7->else_instructions;

                                    body.emit(assign(r06C9, bit_or(r0672, r0671), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r06DA = less(r06CA, body.constant(int(64)));
                                    ir_if *f06D9 = new(mem_ctx) ir_if(operand(r06DA).val);
                                    exec_list *const f06D9_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06D9->then_instructions;

                                       body.emit(assign(r06CC, lshift(r0670, r06CF), 0x01));

                                       ir_expression *const r06DB = bit_and(r06CA, body.constant(int(31)));
                                       body.emit(assign(r06CD, rshift(r0670, r06DB), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06D9->else_instructions;

                                       ir_variable *const r06DC = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r06DE = equal(r06CA, body.constant(int(64)));
                                       ir_if *f06DD = new(mem_ctx) ir_if(operand(r06DE).val);
                                       exec_list *const f06DD_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06DD->then_instructions;

                                          body.emit(assign(r06DC, r0670, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06DD->else_instructions;

                                          ir_expression *const r06DF = nequal(r0670, body.constant(0u));
                                          ir_expression *const r06E0 = expr(ir_unop_b2i, r06DF);
                                          body.emit(assign(r06DC, expr(ir_unop_i2u, r06E0), 0x01));


                                       body.instructions = f06DD_parent_instructions;
                                       body.emit(f06DD);

                                       /* END IF */

                                       body.emit(assign(r06CC, r06DC, 0x01));

                                       body.emit(assign(r06CD, body.constant(0u), 0x01));


                                    body.instructions = f06D9_parent_instructions;
                                    body.emit(f06D9);

                                    /* END IF */


                                 body.instructions = f06D7_parent_instructions;
                                 body.emit(f06D7);

                                 /* END IF */

                                 body.emit(assign(r06CE, body.constant(0u), 0x01));


                              body.instructions = f06D3_parent_instructions;
                              body.emit(f06D3);

                              /* END IF */

                              ir_expression *const r06E1 = nequal(r06C9, body.constant(0u));
                              ir_expression *const r06E2 = expr(ir_unop_b2i, r06E1);
                              ir_expression *const r06E3 = expr(ir_unop_i2u, r06E2);
                              body.emit(assign(r06CC, bit_or(r06CC, r06E3), 0x01));


                           body.instructions = f06D1_parent_instructions;
                           body.emit(f06D1);

                           /* END IF */

                           body.emit(assign(r06B1, r06CE, 0x01));

                           body.emit(assign(r06B2, r06CD, 0x01));

                           body.emit(assign(r06B3, r06CC, 0x01));

                           body.emit(assign(r06B0, body.constant(0u), 0x01));

                           ir_expression *const r06E4 = less(r06CC, body.constant(0u));
                           ir_expression *const r06E5 = expr(ir_unop_b2i, r06E4);
                           body.emit(assign(r06B6, expr(ir_unop_i2u, r06E5), 0x01));


                        body.instructions = f06C7_parent_instructions;
                        body.emit(f06C7);

                        /* END IF */


                     body.instructions = f06C4_parent_instructions;
                     body.emit(f06C4);

                     /* END IF */


                  body.instructions = f06B9_parent_instructions;
                  body.emit(f06B9);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f06E6 = new(mem_ctx) ir_if(operand(r06B4).val);
                  exec_list *const f06E6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f06E6->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r06E8 = nequal(r06B6, body.constant(0u));
                     ir_if *f06E7 = new(mem_ctx) ir_if(operand(r06E8).val);
                     exec_list *const f06E7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f06E7->then_instructions;

                        ir_variable *const r06E9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r06E9, add(r06B2, body.constant(1u)), 0x01));

                        ir_expression *const r06EA = less(r06E9, r06B2);
                        ir_expression *const r06EB = expr(ir_unop_b2i, r06EA);
                        ir_expression *const r06EC = expr(ir_unop_i2u, r06EB);
                        body.emit(assign(r06B1, add(r06B1, r06EC), 0x01));

                        ir_expression *const r06ED = neg(r06B3);
                        ir_expression *const r06EE = equal(r06B3, r06ED);
                        ir_expression *const r06EF = expr(ir_unop_b2i, r06EE);
                        ir_expression *const r06F0 = expr(ir_unop_i2u, r06EF);
                        ir_expression *const r06F1 = bit_and(r06F0, body.constant(1u));
                        ir_expression *const r06F2 = expr(ir_unop_bit_not, r06F1);
                        body.emit(assign(r06B2, bit_and(r06E9, r06F2), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f06E7->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r06F4 = bit_or(r06B1, r06B2);
                        ir_expression *const r06F5 = equal(r06F4, body.constant(0u));
                        ir_if *f06F3 = new(mem_ctx) ir_if(operand(r06F5).val);
                        exec_list *const f06F3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06F3->then_instructions;

                           body.emit(assign(r06B0, body.constant(0u), 0x01));


                        body.instructions = f06F3_parent_instructions;
                        body.emit(f06F3);

                        /* END IF */


                     body.instructions = f06E7_parent_instructions;
                     body.emit(f06E7);

                     /* END IF */

                     ir_variable *const r06F6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r06F6);
                     ir_expression *const r06F7 = lshift(r03E3, body.constant(int(31)));
                     ir_expression *const r06F8 = lshift(r06B0, body.constant(int(20)));
                     ir_expression *const r06F9 = add(r06F7, r06F8);
                     body.emit(assign(r06F6, add(r06F9, r06B1), 0x01));

                     body.emit(assign(r06F6, r06B2, 0x02));

                     body.emit(assign(r06B5, r06F6, 0x03));

                     body.emit(assign(r06B4, body.constant(false), 0x01));


                  body.instructions = f06E6_parent_instructions;
                  body.emit(f06E6);

                  /* END IF */

                  body.emit(assign(r03E4, r06B5, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0667->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r06FB = less(swizzle_y(r03E7), swizzle_y(r03E9));
                  ir_if *f06FA = new(mem_ctx) ir_if(operand(r06FB).val);
                  exec_list *const f06FA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f06FA->then_instructions;

                     ir_variable *const r06FC = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_variable *const r06FD = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r06FD, sub(swizzle_y(r03E9), swizzle_y(r03E7)), 0x01));

                     ir_expression *const r06FE = sub(swizzle_x(r03E9), swizzle_x(r03E7));
                     ir_expression *const r06FF = less(swizzle_y(r03E9), swizzle_y(r03E7));
                     ir_expression *const r0700 = expr(ir_unop_b2i, r06FF);
                     ir_expression *const r0701 = expr(ir_unop_i2u, r0700);
                     body.emit(assign(r06FC, sub(r06FE, r0701), 0x01));

                     body.emit(assign(r03EA, add(r03E8, body.constant(4294967295u)), 0x01));

                     ir_variable *const r0702 = body.make_temp(glsl_type::uint_type, "zExp");
                     body.emit(assign(r0702, add(r03EA, body.constant(4294967286u)), 0x01));

                     ir_variable *const r0703 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0703, r06FC, 0x01));

                     ir_variable *const r0704 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r0704, r06FD, 0x01));

                     ir_variable *const r0705 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r0705);
                     ir_variable *const r0706 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0706);
                     /* IF CONDITION */
                     ir_expression *const r0708 = equal(r06FC, body.constant(0u));
                     ir_if *f0707 = new(mem_ctx) ir_if(operand(r0708).val);
                     exec_list *const f0707_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0707->then_instructions;

                        body.emit(assign(r0703, r06FD, 0x01));

                        body.emit(assign(r0704, body.constant(0u), 0x01));

                        body.emit(assign(r0702, add(r0702, body.constant(4294967264u)), 0x01));


                     body.instructions = f0707_parent_instructions;
                     body.emit(f0707);

                     /* END IF */

                     ir_variable *const r0709 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r0709, r0703, 0x01));

                     ir_variable *const r070A = body.make_temp(glsl_type::uint_type, "return_value");
                     ir_variable *const r070B = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
                     body.emit(r070B);
                     /* IF CONDITION */
                     ir_expression *const r070D = equal(r0703, body.constant(0u));
                     ir_if *f070C = new(mem_ctx) ir_if(operand(r070D).val);
                     exec_list *const f070C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f070C->then_instructions;

                        body.emit(assign(r070A, body.constant(32u), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f070C->else_instructions;

                        body.emit(assign(r070B, body.constant(0u), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r070F = bit_and(r0703, body.constant(4294901760u));
                        ir_expression *const r0710 = equal(r070F, body.constant(0u));
                        ir_if *f070E = new(mem_ctx) ir_if(operand(r0710).val);
                        exec_list *const f070E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f070E->then_instructions;

                           body.emit(assign(r070B, body.constant(16u), 0x01));

                           body.emit(assign(r0709, lshift(r0703, body.constant(int(16))), 0x01));


                        body.instructions = f070E_parent_instructions;
                        body.emit(f070E);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0712 = bit_and(r0709, body.constant(4278190080u));
                        ir_expression *const r0713 = equal(r0712, body.constant(0u));
                        ir_if *f0711 = new(mem_ctx) ir_if(operand(r0713).val);
                        exec_list *const f0711_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0711->then_instructions;

                           body.emit(assign(r070B, add(r070B, body.constant(8u)), 0x01));

                           body.emit(assign(r0709, lshift(r0709, body.constant(int(8))), 0x01));


                        body.instructions = f0711_parent_instructions;
                        body.emit(f0711);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0715 = bit_and(r0709, body.constant(4026531840u));
                        ir_expression *const r0716 = equal(r0715, body.constant(0u));
                        ir_if *f0714 = new(mem_ctx) ir_if(operand(r0716).val);
                        exec_list *const f0714_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0714->then_instructions;

                           body.emit(assign(r070B, add(r070B, body.constant(4u)), 0x01));

                           body.emit(assign(r0709, lshift(r0709, body.constant(int(4))), 0x01));


                        body.instructions = f0714_parent_instructions;
                        body.emit(f0714);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0718 = bit_and(r0709, body.constant(3221225472u));
                        ir_expression *const r0719 = equal(r0718, body.constant(0u));
                        ir_if *f0717 = new(mem_ctx) ir_if(operand(r0719).val);
                        exec_list *const f0717_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0717->then_instructions;

                           body.emit(assign(r070B, add(r070B, body.constant(2u)), 0x01));

                           body.emit(assign(r0709, lshift(r0709, body.constant(int(2))), 0x01));


                        body.instructions = f0717_parent_instructions;
                        body.emit(f0717);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r071B = bit_and(r0709, body.constant(2147483648u));
                        ir_expression *const r071C = equal(r071B, body.constant(0u));
                        ir_if *f071A = new(mem_ctx) ir_if(operand(r071C).val);
                        exec_list *const f071A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f071A->then_instructions;

                           body.emit(assign(r070B, add(r070B, body.constant(1u)), 0x01));


                        body.instructions = f071A_parent_instructions;
                        body.emit(f071A);

                        /* END IF */

                        body.emit(assign(r070A, r070B, 0x01));


                     body.instructions = f070C_parent_instructions;
                     body.emit(f070C);

                     /* END IF */

                     ir_expression *const r071D = expr(ir_unop_u2i, r070A);
                     body.emit(assign(r0706, add(r071D, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r071F = lequal(body.constant(int(0)), r0706);
                     ir_if *f071E = new(mem_ctx) ir_if(operand(r071F).val);
                     exec_list *const f071E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f071E->then_instructions;

                        body.emit(assign(r0705, body.constant(0u), 0x01));

                        ir_variable *const r0720 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r0720, lshift(r0704, r0706), 0x01));

                        ir_variable *const r0721 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0723 = equal(r0706, body.constant(int(0)));
                        ir_if *f0722 = new(mem_ctx) ir_if(operand(r0723).val);
                        exec_list *const f0722_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0722->then_instructions;

                           body.emit(assign(r0721, r0703, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0722->else_instructions;

                           ir_expression *const r0724 = lshift(r0703, r0706);
                           ir_expression *const r0725 = neg(r0706);
                           ir_expression *const r0726 = bit_and(r0725, body.constant(int(31)));
                           ir_expression *const r0727 = rshift(r0704, r0726);
                           body.emit(assign(r0721, bit_or(r0724, r0727), 0x01));


                        body.instructions = f0722_parent_instructions;
                        body.emit(f0722);

                        /* END IF */

                        body.emit(assign(r0703, r0721, 0x01));

                        body.emit(assign(r0704, r0720, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f071E->else_instructions;

                        ir_variable *const r0728 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0728, body.constant(0u), 0x01));

                        ir_variable *const r0729 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0729, neg(r0706), 0x01));

                        ir_variable *const r072A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r072A);
                        ir_variable *const r072B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r072B);
                        ir_variable *const r072C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r072C);
                        ir_variable *const r072D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r072E = neg(r0729);
                        body.emit(assign(r072D, bit_and(r072E, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0730 = equal(r0729, body.constant(int(0)));
                        ir_if *f072F = new(mem_ctx) ir_if(operand(r0730).val);
                        exec_list *const f072F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f072F->then_instructions;

                           body.emit(assign(r072A, r0728, 0x01));

                           body.emit(assign(r072B, r0704, 0x01));

                           body.emit(assign(r072C, r0703, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f072F->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0732 = less(r0729, body.constant(int(32)));
                           ir_if *f0731 = new(mem_ctx) ir_if(operand(r0732).val);
                           exec_list *const f0731_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0731->then_instructions;

                              body.emit(assign(r072A, lshift(r0704, r072D), 0x01));

                              ir_expression *const r0733 = lshift(r0703, r072D);
                              ir_expression *const r0734 = rshift(r0704, r0729);
                              body.emit(assign(r072B, bit_or(r0733, r0734), 0x01));

                              body.emit(assign(r072C, rshift(r0703, r0729), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0731->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0736 = equal(r0729, body.constant(int(32)));
                              ir_if *f0735 = new(mem_ctx) ir_if(operand(r0736).val);
                              exec_list *const f0735_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0735->then_instructions;

                                 body.emit(assign(r072A, r0704, 0x01));

                                 body.emit(assign(r072B, r0703, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0735->else_instructions;

                                 body.emit(assign(r0728, bit_or(body.constant(0u), r0704), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0738 = less(r0729, body.constant(int(64)));
                                 ir_if *f0737 = new(mem_ctx) ir_if(operand(r0738).val);
                                 exec_list *const f0737_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0737->then_instructions;

                                    body.emit(assign(r072A, lshift(r0703, r072D), 0x01));

                                    ir_expression *const r0739 = bit_and(r0729, body.constant(int(31)));
                                    body.emit(assign(r072B, rshift(r0703, r0739), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0737->else_instructions;

                                    ir_variable *const r073A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r073C = equal(r0729, body.constant(int(64)));
                                    ir_if *f073B = new(mem_ctx) ir_if(operand(r073C).val);
                                    exec_list *const f073B_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f073B->then_instructions;

                                       body.emit(assign(r073A, r0703, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f073B->else_instructions;

                                       ir_expression *const r073D = nequal(r0703, body.constant(0u));
                                       ir_expression *const r073E = expr(ir_unop_b2i, r073D);
                                       body.emit(assign(r073A, expr(ir_unop_i2u, r073E), 0x01));


                                    body.instructions = f073B_parent_instructions;
                                    body.emit(f073B);

                                    /* END IF */

                                    body.emit(assign(r072A, r073A, 0x01));

                                    body.emit(assign(r072B, body.constant(0u), 0x01));


                                 body.instructions = f0737_parent_instructions;
                                 body.emit(f0737);

                                 /* END IF */


                              body.instructions = f0735_parent_instructions;
                              body.emit(f0735);

                              /* END IF */

                              body.emit(assign(r072C, body.constant(0u), 0x01));


                           body.instructions = f0731_parent_instructions;
                           body.emit(f0731);

                           /* END IF */

                           ir_expression *const r073F = nequal(r0728, body.constant(0u));
                           ir_expression *const r0740 = expr(ir_unop_b2i, r073F);
                           ir_expression *const r0741 = expr(ir_unop_i2u, r0740);
                           body.emit(assign(r072A, bit_or(r072A, r0741), 0x01));


                        body.instructions = f072F_parent_instructions;
                        body.emit(f072F);

                        /* END IF */

                        body.emit(assign(r0703, r072C, 0x01));

                        body.emit(assign(r0704, r072B, 0x01));

                        body.emit(assign(r0705, r072A, 0x01));


                     body.instructions = f071E_parent_instructions;
                     body.emit(f071E);

                     /* END IF */

                     ir_expression *const r0742 = expr(ir_unop_i2u, r0706);
                     body.emit(assign(r0702, sub(r0702, r0742), 0x01));

                     ir_variable *const r0743 = body.make_temp(glsl_type::uint_type, "zExp");
                     body.emit(assign(r0743, r0702, 0x01));

                     ir_variable *const r0744 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0744, r0703, 0x01));

                     ir_variable *const r0745 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r0745, r0704, 0x01));

                     ir_variable *const r0746 = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r0746, r0705, 0x01));

                     ir_variable *const r0747 = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r0747, body.constant(true), 0x01));

                     ir_variable *const r0748 = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r0749 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
                     body.emit(r0749);
                     ir_expression *const r074A = less(r0705, body.constant(0u));
                     ir_expression *const r074B = expr(ir_unop_b2i, r074A);
                     body.emit(assign(r0749, expr(ir_unop_i2u, r074B), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r074D = lequal(body.constant(2045u), r0702);
                     ir_if *f074C = new(mem_ctx) ir_if(operand(r074D).val);
                     exec_list *const f074C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f074C->then_instructions;

                        ir_variable *const r074E = body.make_temp(glsl_type::bool_type, "or_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0750 = less(body.constant(2045u), r0702);
                        ir_if *f074F = new(mem_ctx) ir_if(operand(r0750).val);
                        exec_list *const f074F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f074F->then_instructions;

                           body.emit(assign(r074E, body.constant(true), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f074F->else_instructions;

                           ir_variable *const r0751 = body.make_temp(glsl_type::bool_type, "and_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0753 = equal(r0702, body.constant(2045u));
                           ir_if *f0752 = new(mem_ctx) ir_if(operand(r0753).val);
                           exec_list *const f0752_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0752->then_instructions;

                              ir_expression *const r0754 = equal(body.constant(2097151u), r0703);
                              ir_expression *const r0755 = equal(body.constant(4294967295u), r0704);
                              body.emit(assign(r0751, logic_and(r0754, r0755), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0752->else_instructions;

                              body.emit(assign(r0751, body.constant(false), 0x01));


                           body.instructions = f0752_parent_instructions;
                           body.emit(f0752);

                           /* END IF */

                           ir_expression *const r0756 = nequal(r0749, body.constant(0u));
                           body.emit(assign(r074E, logic_and(r0751, r0756), 0x01));


                        body.instructions = f074F_parent_instructions;
                        body.emit(f074F);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f0757 = new(mem_ctx) ir_if(operand(r074E).val);
                        exec_list *const f0757_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0757->then_instructions;

                           ir_variable *const r0758 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0758);
                           ir_expression *const r0759 = lshift(r03E3, body.constant(int(31)));
                           body.emit(assign(r0758, add(r0759, body.constant(2146435072u)), 0x01));

                           body.emit(assign(r0758, body.constant(0u), 0x02));

                           body.emit(assign(r0748, r0758, 0x03));

                           body.emit(assign(r0747, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0757->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r075B = less(r0702, body.constant(0u));
                           ir_if *f075A = new(mem_ctx) ir_if(operand(r075B).val);
                           exec_list *const f075A_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f075A->then_instructions;

                              ir_variable *const r075C = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r075C, r0705, 0x01));

                              ir_variable *const r075D = body.make_temp(glsl_type::int_type, "count");
                              ir_expression *const r075E = neg(r0702);
                              body.emit(assign(r075D, expr(ir_unop_u2i, r075E), 0x01));

                              ir_variable *const r075F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r075F);
                              ir_variable *const r0760 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0760);
                              ir_variable *const r0761 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0761);
                              ir_variable *const r0762 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0763 = neg(r075D);
                              body.emit(assign(r0762, bit_and(r0763, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0765 = equal(r075D, body.constant(int(0)));
                              ir_if *f0764 = new(mem_ctx) ir_if(operand(r0765).val);
                              exec_list *const f0764_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0764->then_instructions;

                                 body.emit(assign(r075F, r0705, 0x01));

                                 body.emit(assign(r0760, r0704, 0x01));

                                 body.emit(assign(r0761, r0703, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0764->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0767 = less(r075D, body.constant(int(32)));
                                 ir_if *f0766 = new(mem_ctx) ir_if(operand(r0767).val);
                                 exec_list *const f0766_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0766->then_instructions;

                                    body.emit(assign(r075F, lshift(r0704, r0762), 0x01));

                                    ir_expression *const r0768 = lshift(r0703, r0762);
                                    ir_expression *const r0769 = rshift(r0704, r075D);
                                    body.emit(assign(r0760, bit_or(r0768, r0769), 0x01));

                                    body.emit(assign(r0761, rshift(r0703, r075D), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0766->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r076B = equal(r075D, body.constant(int(32)));
                                    ir_if *f076A = new(mem_ctx) ir_if(operand(r076B).val);
                                    exec_list *const f076A_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f076A->then_instructions;

                                       body.emit(assign(r075F, r0704, 0x01));

                                       body.emit(assign(r0760, r0703, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f076A->else_instructions;

                                       body.emit(assign(r075C, bit_or(r0705, r0704), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r076D = less(r075D, body.constant(int(64)));
                                       ir_if *f076C = new(mem_ctx) ir_if(operand(r076D).val);
                                       exec_list *const f076C_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f076C->then_instructions;

                                          body.emit(assign(r075F, lshift(r0703, r0762), 0x01));

                                          ir_expression *const r076E = bit_and(r075D, body.constant(int(31)));
                                          body.emit(assign(r0760, rshift(r0703, r076E), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f076C->else_instructions;

                                          ir_variable *const r076F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r0771 = equal(r075D, body.constant(int(64)));
                                          ir_if *f0770 = new(mem_ctx) ir_if(operand(r0771).val);
                                          exec_list *const f0770_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0770->then_instructions;

                                             body.emit(assign(r076F, r0703, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0770->else_instructions;

                                             ir_expression *const r0772 = nequal(r0703, body.constant(0u));
                                             ir_expression *const r0773 = expr(ir_unop_b2i, r0772);
                                             body.emit(assign(r076F, expr(ir_unop_i2u, r0773), 0x01));


                                          body.instructions = f0770_parent_instructions;
                                          body.emit(f0770);

                                          /* END IF */

                                          body.emit(assign(r075F, r076F, 0x01));

                                          body.emit(assign(r0760, body.constant(0u), 0x01));


                                       body.instructions = f076C_parent_instructions;
                                       body.emit(f076C);

                                       /* END IF */


                                    body.instructions = f076A_parent_instructions;
                                    body.emit(f076A);

                                    /* END IF */

                                    body.emit(assign(r0761, body.constant(0u), 0x01));


                                 body.instructions = f0766_parent_instructions;
                                 body.emit(f0766);

                                 /* END IF */

                                 ir_expression *const r0774 = nequal(r075C, body.constant(0u));
                                 ir_expression *const r0775 = expr(ir_unop_b2i, r0774);
                                 ir_expression *const r0776 = expr(ir_unop_i2u, r0775);
                                 body.emit(assign(r075F, bit_or(r075F, r0776), 0x01));


                              body.instructions = f0764_parent_instructions;
                              body.emit(f0764);

                              /* END IF */

                              body.emit(assign(r0744, r0761, 0x01));

                              body.emit(assign(r0745, r0760, 0x01));

                              body.emit(assign(r0746, r075F, 0x01));

                              body.emit(assign(r0743, body.constant(0u), 0x01));

                              ir_expression *const r0777 = less(r075F, body.constant(0u));
                              ir_expression *const r0778 = expr(ir_unop_b2i, r0777);
                              body.emit(assign(r0749, expr(ir_unop_i2u, r0778), 0x01));


                           body.instructions = f075A_parent_instructions;
                           body.emit(f075A);

                           /* END IF */


                        body.instructions = f0757_parent_instructions;
                        body.emit(f0757);

                        /* END IF */


                     body.instructions = f074C_parent_instructions;
                     body.emit(f074C);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0779 = new(mem_ctx) ir_if(operand(r0747).val);
                     exec_list *const f0779_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0779->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r077B = nequal(r0749, body.constant(0u));
                        ir_if *f077A = new(mem_ctx) ir_if(operand(r077B).val);
                        exec_list *const f077A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f077A->then_instructions;

                           ir_variable *const r077C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r077C, add(r0745, body.constant(1u)), 0x01));

                           ir_expression *const r077D = less(r077C, r0745);
                           ir_expression *const r077E = expr(ir_unop_b2i, r077D);
                           ir_expression *const r077F = expr(ir_unop_i2u, r077E);
                           body.emit(assign(r0744, add(r0744, r077F), 0x01));

                           ir_expression *const r0780 = neg(r0746);
                           ir_expression *const r0781 = equal(r0746, r0780);
                           ir_expression *const r0782 = expr(ir_unop_b2i, r0781);
                           ir_expression *const r0783 = expr(ir_unop_i2u, r0782);
                           ir_expression *const r0784 = bit_and(r0783, body.constant(1u));
                           ir_expression *const r0785 = expr(ir_unop_bit_not, r0784);
                           body.emit(assign(r0745, bit_and(r077C, r0785), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f077A->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0787 = bit_or(r0744, r0745);
                           ir_expression *const r0788 = equal(r0787, body.constant(0u));
                           ir_if *f0786 = new(mem_ctx) ir_if(operand(r0788).val);
                           exec_list *const f0786_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0786->then_instructions;

                              body.emit(assign(r0743, body.constant(0u), 0x01));


                           body.instructions = f0786_parent_instructions;
                           body.emit(f0786);

                           /* END IF */


                        body.instructions = f077A_parent_instructions;
                        body.emit(f077A);

                        /* END IF */

                        ir_variable *const r0789 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0789);
                        ir_expression *const r078A = lshift(r03E3, body.constant(int(31)));
                        ir_expression *const r078B = lshift(r0743, body.constant(int(20)));
                        ir_expression *const r078C = add(r078A, r078B);
                        body.emit(assign(r0789, add(r078C, r0744), 0x01));

                        body.emit(assign(r0789, r0745, 0x02));

                        body.emit(assign(r0748, r0789, 0x03));

                        body.emit(assign(r0747, body.constant(false), 0x01));


                     body.instructions = f0779_parent_instructions;
                     body.emit(f0779);

                     /* END IF */

                     body.emit(assign(r03E4, r0748, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f06FA->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r078E = less(swizzle_y(r03E9), swizzle_y(r03E7));
                     ir_if *f078D = new(mem_ctx) ir_if(operand(r078E).val);
                     exec_list *const f078D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f078D->then_instructions;

                        ir_variable *const r078F = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_variable *const r0790 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r0790, sub(swizzle_y(r03E7), swizzle_y(r03E9)), 0x01));

                        ir_expression *const r0791 = sub(swizzle_x(r03E7), swizzle_x(r03E9));
                        ir_expression *const r0792 = less(swizzle_y(r03E7), swizzle_y(r03E9));
                        ir_expression *const r0793 = expr(ir_unop_b2i, r0792);
                        ir_expression *const r0794 = expr(ir_unop_i2u, r0793);
                        body.emit(assign(r078F, sub(r0791, r0794), 0x01));

                        body.emit(assign(r03E3, bit_xor(r03E3, body.constant(1u)), 0x01));

                        body.emit(assign(r03EA, add(r03E6, body.constant(4294967295u)), 0x01));

                        ir_variable *const r0795 = body.make_temp(glsl_type::uint_type, "zExp");
                        body.emit(assign(r0795, add(r03EA, body.constant(4294967286u)), 0x01));

                        ir_variable *const r0796 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r0796, r078F, 0x01));

                        ir_variable *const r0797 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0797, r0790, 0x01));

                        ir_variable *const r0798 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0798);
                        ir_variable *const r0799 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0799);
                        /* IF CONDITION */
                        ir_expression *const r079B = equal(r078F, body.constant(0u));
                        ir_if *f079A = new(mem_ctx) ir_if(operand(r079B).val);
                        exec_list *const f079A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f079A->then_instructions;

                           body.emit(assign(r0796, r0790, 0x01));

                           body.emit(assign(r0797, body.constant(0u), 0x01));

                           body.emit(assign(r0795, add(r0795, body.constant(4294967264u)), 0x01));


                        body.instructions = f079A_parent_instructions;
                        body.emit(f079A);

                        /* END IF */

                        ir_variable *const r079C = body.make_temp(glsl_type::uint_type, "a");
                        body.emit(assign(r079C, r0796, 0x01));

                        ir_variable *const r079D = body.make_temp(glsl_type::uint_type, "return_value");
                        ir_variable *const r079E = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
                        body.emit(r079E);
                        /* IF CONDITION */
                        ir_expression *const r07A0 = equal(r0796, body.constant(0u));
                        ir_if *f079F = new(mem_ctx) ir_if(operand(r07A0).val);
                        exec_list *const f079F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f079F->then_instructions;

                           body.emit(assign(r079D, body.constant(32u), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f079F->else_instructions;

                           body.emit(assign(r079E, body.constant(0u), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r07A2 = bit_and(r0796, body.constant(4294901760u));
                           ir_expression *const r07A3 = equal(r07A2, body.constant(0u));
                           ir_if *f07A1 = new(mem_ctx) ir_if(operand(r07A3).val);
                           exec_list *const f07A1_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07A1->then_instructions;

                              body.emit(assign(r079E, body.constant(16u), 0x01));

                              body.emit(assign(r079C, lshift(r0796, body.constant(int(16))), 0x01));


                           body.instructions = f07A1_parent_instructions;
                           body.emit(f07A1);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r07A5 = bit_and(r079C, body.constant(4278190080u));
                           ir_expression *const r07A6 = equal(r07A5, body.constant(0u));
                           ir_if *f07A4 = new(mem_ctx) ir_if(operand(r07A6).val);
                           exec_list *const f07A4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07A4->then_instructions;

                              body.emit(assign(r079E, add(r079E, body.constant(8u)), 0x01));

                              body.emit(assign(r079C, lshift(r079C, body.constant(int(8))), 0x01));


                           body.instructions = f07A4_parent_instructions;
                           body.emit(f07A4);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r07A8 = bit_and(r079C, body.constant(4026531840u));
                           ir_expression *const r07A9 = equal(r07A8, body.constant(0u));
                           ir_if *f07A7 = new(mem_ctx) ir_if(operand(r07A9).val);
                           exec_list *const f07A7_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07A7->then_instructions;

                              body.emit(assign(r079E, add(r079E, body.constant(4u)), 0x01));

                              body.emit(assign(r079C, lshift(r079C, body.constant(int(4))), 0x01));


                           body.instructions = f07A7_parent_instructions;
                           body.emit(f07A7);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r07AB = bit_and(r079C, body.constant(3221225472u));
                           ir_expression *const r07AC = equal(r07AB, body.constant(0u));
                           ir_if *f07AA = new(mem_ctx) ir_if(operand(r07AC).val);
                           exec_list *const f07AA_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07AA->then_instructions;

                              body.emit(assign(r079E, add(r079E, body.constant(2u)), 0x01));

                              body.emit(assign(r079C, lshift(r079C, body.constant(int(2))), 0x01));


                           body.instructions = f07AA_parent_instructions;
                           body.emit(f07AA);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r07AE = bit_and(r079C, body.constant(2147483648u));
                           ir_expression *const r07AF = equal(r07AE, body.constant(0u));
                           ir_if *f07AD = new(mem_ctx) ir_if(operand(r07AF).val);
                           exec_list *const f07AD_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07AD->then_instructions;

                              body.emit(assign(r079E, add(r079E, body.constant(1u)), 0x01));


                           body.instructions = f07AD_parent_instructions;
                           body.emit(f07AD);

                           /* END IF */

                           body.emit(assign(r079D, r079E, 0x01));


                        body.instructions = f079F_parent_instructions;
                        body.emit(f079F);

                        /* END IF */

                        ir_expression *const r07B0 = expr(ir_unop_u2i, r079D);
                        body.emit(assign(r0799, add(r07B0, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r07B2 = lequal(body.constant(int(0)), r0799);
                        ir_if *f07B1 = new(mem_ctx) ir_if(operand(r07B2).val);
                        exec_list *const f07B1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f07B1->then_instructions;

                           body.emit(assign(r0798, body.constant(0u), 0x01));

                           ir_variable *const r07B3 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r07B3, lshift(r0797, r0799), 0x01));

                           ir_variable *const r07B4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r07B6 = equal(r0799, body.constant(int(0)));
                           ir_if *f07B5 = new(mem_ctx) ir_if(operand(r07B6).val);
                           exec_list *const f07B5_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07B5->then_instructions;

                              body.emit(assign(r07B4, r0796, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f07B5->else_instructions;

                              ir_expression *const r07B7 = lshift(r0796, r0799);
                              ir_expression *const r07B8 = neg(r0799);
                              ir_expression *const r07B9 = bit_and(r07B8, body.constant(int(31)));
                              ir_expression *const r07BA = rshift(r0797, r07B9);
                              body.emit(assign(r07B4, bit_or(r07B7, r07BA), 0x01));


                           body.instructions = f07B5_parent_instructions;
                           body.emit(f07B5);

                           /* END IF */

                           body.emit(assign(r0796, r07B4, 0x01));

                           body.emit(assign(r0797, r07B3, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f07B1->else_instructions;

                           ir_variable *const r07BB = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r07BB, body.constant(0u), 0x01));

                           ir_variable *const r07BC = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r07BC, neg(r0799), 0x01));

                           ir_variable *const r07BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r07BD);
                           ir_variable *const r07BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r07BE);
                           ir_variable *const r07BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r07BF);
                           ir_variable *const r07C0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r07C1 = neg(r07BC);
                           body.emit(assign(r07C0, bit_and(r07C1, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r07C3 = equal(r07BC, body.constant(int(0)));
                           ir_if *f07C2 = new(mem_ctx) ir_if(operand(r07C3).val);
                           exec_list *const f07C2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07C2->then_instructions;

                              body.emit(assign(r07BD, r07BB, 0x01));

                              body.emit(assign(r07BE, r0797, 0x01));

                              body.emit(assign(r07BF, r0796, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f07C2->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r07C5 = less(r07BC, body.constant(int(32)));
                              ir_if *f07C4 = new(mem_ctx) ir_if(operand(r07C5).val);
                              exec_list *const f07C4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f07C4->then_instructions;

                                 body.emit(assign(r07BD, lshift(r0797, r07C0), 0x01));

                                 ir_expression *const r07C6 = lshift(r0796, r07C0);
                                 ir_expression *const r07C7 = rshift(r0797, r07BC);
                                 body.emit(assign(r07BE, bit_or(r07C6, r07C7), 0x01));

                                 body.emit(assign(r07BF, rshift(r0796, r07BC), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f07C4->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r07C9 = equal(r07BC, body.constant(int(32)));
                                 ir_if *f07C8 = new(mem_ctx) ir_if(operand(r07C9).val);
                                 exec_list *const f07C8_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f07C8->then_instructions;

                                    body.emit(assign(r07BD, r0797, 0x01));

                                    body.emit(assign(r07BE, r0796, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f07C8->else_instructions;

                                    body.emit(assign(r07BB, bit_or(body.constant(0u), r0797), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r07CB = less(r07BC, body.constant(int(64)));
                                    ir_if *f07CA = new(mem_ctx) ir_if(operand(r07CB).val);
                                    exec_list *const f07CA_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f07CA->then_instructions;

                                       body.emit(assign(r07BD, lshift(r0796, r07C0), 0x01));

                                       ir_expression *const r07CC = bit_and(r07BC, body.constant(int(31)));
                                       body.emit(assign(r07BE, rshift(r0796, r07CC), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f07CA->else_instructions;

                                       ir_variable *const r07CD = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r07CF = equal(r07BC, body.constant(int(64)));
                                       ir_if *f07CE = new(mem_ctx) ir_if(operand(r07CF).val);
                                       exec_list *const f07CE_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f07CE->then_instructions;

                                          body.emit(assign(r07CD, r0796, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f07CE->else_instructions;

                                          ir_expression *const r07D0 = nequal(r0796, body.constant(0u));
                                          ir_expression *const r07D1 = expr(ir_unop_b2i, r07D0);
                                          body.emit(assign(r07CD, expr(ir_unop_i2u, r07D1), 0x01));


                                       body.instructions = f07CE_parent_instructions;
                                       body.emit(f07CE);

                                       /* END IF */

                                       body.emit(assign(r07BD, r07CD, 0x01));

                                       body.emit(assign(r07BE, body.constant(0u), 0x01));


                                    body.instructions = f07CA_parent_instructions;
                                    body.emit(f07CA);

                                    /* END IF */


                                 body.instructions = f07C8_parent_instructions;
                                 body.emit(f07C8);

                                 /* END IF */

                                 body.emit(assign(r07BF, body.constant(0u), 0x01));


                              body.instructions = f07C4_parent_instructions;
                              body.emit(f07C4);

                              /* END IF */

                              ir_expression *const r07D2 = nequal(r07BB, body.constant(0u));
                              ir_expression *const r07D3 = expr(ir_unop_b2i, r07D2);
                              ir_expression *const r07D4 = expr(ir_unop_i2u, r07D3);
                              body.emit(assign(r07BD, bit_or(r07BD, r07D4), 0x01));


                           body.instructions = f07C2_parent_instructions;
                           body.emit(f07C2);

                           /* END IF */

                           body.emit(assign(r0796, r07BF, 0x01));

                           body.emit(assign(r0797, r07BE, 0x01));

                           body.emit(assign(r0798, r07BD, 0x01));


                        body.instructions = f07B1_parent_instructions;
                        body.emit(f07B1);

                        /* END IF */

                        ir_expression *const r07D5 = expr(ir_unop_i2u, r0799);
                        body.emit(assign(r0795, sub(r0795, r07D5), 0x01));

                        ir_variable *const r07D6 = body.make_temp(glsl_type::uint_type, "zExp");
                        body.emit(assign(r07D6, r0795, 0x01));

                        ir_variable *const r07D7 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r07D7, r0796, 0x01));

                        ir_variable *const r07D8 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r07D8, r0797, 0x01));

                        ir_variable *const r07D9 = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r07D9, r0798, 0x01));

                        ir_variable *const r07DA = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r07DA, body.constant(true), 0x01));

                        ir_variable *const r07DB = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r07DC = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
                        body.emit(r07DC);
                        ir_expression *const r07DD = less(r0798, body.constant(0u));
                        ir_expression *const r07DE = expr(ir_unop_b2i, r07DD);
                        body.emit(assign(r07DC, expr(ir_unop_i2u, r07DE), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r07E0 = lequal(body.constant(2045u), r0795);
                        ir_if *f07DF = new(mem_ctx) ir_if(operand(r07E0).val);
                        exec_list *const f07DF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f07DF->then_instructions;

                           ir_variable *const r07E1 = body.make_temp(glsl_type::bool_type, "or_tmp");
                           /* IF CONDITION */
                           ir_expression *const r07E3 = less(body.constant(2045u), r0795);
                           ir_if *f07E2 = new(mem_ctx) ir_if(operand(r07E3).val);
                           exec_list *const f07E2_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07E2->then_instructions;

                              body.emit(assign(r07E1, body.constant(true), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f07E2->else_instructions;

                              ir_variable *const r07E4 = body.make_temp(glsl_type::bool_type, "and_tmp");
                              /* IF CONDITION */
                              ir_expression *const r07E6 = equal(r0795, body.constant(2045u));
                              ir_if *f07E5 = new(mem_ctx) ir_if(operand(r07E6).val);
                              exec_list *const f07E5_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f07E5->then_instructions;

                                 ir_expression *const r07E7 = equal(body.constant(2097151u), r0796);
                                 ir_expression *const r07E8 = equal(body.constant(4294967295u), r0797);
                                 body.emit(assign(r07E4, logic_and(r07E7, r07E8), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f07E5->else_instructions;

                                 body.emit(assign(r07E4, body.constant(false), 0x01));


                              body.instructions = f07E5_parent_instructions;
                              body.emit(f07E5);

                              /* END IF */

                              ir_expression *const r07E9 = nequal(r07DC, body.constant(0u));
                              body.emit(assign(r07E1, logic_and(r07E4, r07E9), 0x01));


                           body.instructions = f07E2_parent_instructions;
                           body.emit(f07E2);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f07EA = new(mem_ctx) ir_if(operand(r07E1).val);
                           exec_list *const f07EA_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f07EA->then_instructions;

                              ir_variable *const r07EB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r07EB);
                              ir_expression *const r07EC = lshift(r03E3, body.constant(int(31)));
                              body.emit(assign(r07EB, add(r07EC, body.constant(2146435072u)), 0x01));

                              body.emit(assign(r07EB, body.constant(0u), 0x02));

                              body.emit(assign(r07DB, r07EB, 0x03));

                              body.emit(assign(r07DA, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f07EA->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r07EE = less(r0795, body.constant(0u));
                              ir_if *f07ED = new(mem_ctx) ir_if(operand(r07EE).val);
                              exec_list *const f07ED_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f07ED->then_instructions;

                                 ir_variable *const r07EF = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r07EF, r0798, 0x01));

                                 ir_variable *const r07F0 = body.make_temp(glsl_type::int_type, "count");
                                 ir_expression *const r07F1 = neg(r0795);
                                 body.emit(assign(r07F0, expr(ir_unop_u2i, r07F1), 0x01));

                                 ir_variable *const r07F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r07F2);
                                 ir_variable *const r07F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r07F3);
                                 ir_variable *const r07F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r07F4);
                                 ir_variable *const r07F5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r07F6 = neg(r07F0);
                                 body.emit(assign(r07F5, bit_and(r07F6, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r07F8 = equal(r07F0, body.constant(int(0)));
                                 ir_if *f07F7 = new(mem_ctx) ir_if(operand(r07F8).val);
                                 exec_list *const f07F7_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f07F7->then_instructions;

                                    body.emit(assign(r07F2, r0798, 0x01));

                                    body.emit(assign(r07F3, r0797, 0x01));

                                    body.emit(assign(r07F4, r0796, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f07F7->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r07FA = less(r07F0, body.constant(int(32)));
                                    ir_if *f07F9 = new(mem_ctx) ir_if(operand(r07FA).val);
                                    exec_list *const f07F9_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f07F9->then_instructions;

                                       body.emit(assign(r07F2, lshift(r0797, r07F5), 0x01));

                                       ir_expression *const r07FB = lshift(r0796, r07F5);
                                       ir_expression *const r07FC = rshift(r0797, r07F0);
                                       body.emit(assign(r07F3, bit_or(r07FB, r07FC), 0x01));

                                       body.emit(assign(r07F4, rshift(r0796, r07F0), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f07F9->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r07FE = equal(r07F0, body.constant(int(32)));
                                       ir_if *f07FD = new(mem_ctx) ir_if(operand(r07FE).val);
                                       exec_list *const f07FD_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f07FD->then_instructions;

                                          body.emit(assign(r07F2, r0797, 0x01));

                                          body.emit(assign(r07F3, r0796, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f07FD->else_instructions;

                                          body.emit(assign(r07EF, bit_or(r0798, r0797), 0x01));

                                          /* IF CONDITION */
                                          ir_expression *const r0800 = less(r07F0, body.constant(int(64)));
                                          ir_if *f07FF = new(mem_ctx) ir_if(operand(r0800).val);
                                          exec_list *const f07FF_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f07FF->then_instructions;

                                             body.emit(assign(r07F2, lshift(r0796, r07F5), 0x01));

                                             ir_expression *const r0801 = bit_and(r07F0, body.constant(int(31)));
                                             body.emit(assign(r07F3, rshift(r0796, r0801), 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f07FF->else_instructions;

                                             ir_variable *const r0802 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                             /* IF CONDITION */
                                             ir_expression *const r0804 = equal(r07F0, body.constant(int(64)));
                                             ir_if *f0803 = new(mem_ctx) ir_if(operand(r0804).val);
                                             exec_list *const f0803_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f0803->then_instructions;

                                                body.emit(assign(r0802, r0796, 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f0803->else_instructions;

                                                ir_expression *const r0805 = nequal(r0796, body.constant(0u));
                                                ir_expression *const r0806 = expr(ir_unop_b2i, r0805);
                                                body.emit(assign(r0802, expr(ir_unop_i2u, r0806), 0x01));


                                             body.instructions = f0803_parent_instructions;
                                             body.emit(f0803);

                                             /* END IF */

                                             body.emit(assign(r07F2, r0802, 0x01));

                                             body.emit(assign(r07F3, body.constant(0u), 0x01));


                                          body.instructions = f07FF_parent_instructions;
                                          body.emit(f07FF);

                                          /* END IF */


                                       body.instructions = f07FD_parent_instructions;
                                       body.emit(f07FD);

                                       /* END IF */

                                       body.emit(assign(r07F4, body.constant(0u), 0x01));


                                    body.instructions = f07F9_parent_instructions;
                                    body.emit(f07F9);

                                    /* END IF */

                                    ir_expression *const r0807 = nequal(r07EF, body.constant(0u));
                                    ir_expression *const r0808 = expr(ir_unop_b2i, r0807);
                                    ir_expression *const r0809 = expr(ir_unop_i2u, r0808);
                                    body.emit(assign(r07F2, bit_or(r07F2, r0809), 0x01));


                                 body.instructions = f07F7_parent_instructions;
                                 body.emit(f07F7);

                                 /* END IF */

                                 body.emit(assign(r07D7, r07F4, 0x01));

                                 body.emit(assign(r07D8, r07F3, 0x01));

                                 body.emit(assign(r07D9, r07F2, 0x01));

                                 body.emit(assign(r07D6, body.constant(0u), 0x01));

                                 ir_expression *const r080A = less(r07F2, body.constant(0u));
                                 ir_expression *const r080B = expr(ir_unop_b2i, r080A);
                                 body.emit(assign(r07DC, expr(ir_unop_i2u, r080B), 0x01));


                              body.instructions = f07ED_parent_instructions;
                              body.emit(f07ED);

                              /* END IF */


                           body.instructions = f07EA_parent_instructions;
                           body.emit(f07EA);

                           /* END IF */


                        body.instructions = f07DF_parent_instructions;
                        body.emit(f07DF);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f080C = new(mem_ctx) ir_if(operand(r07DA).val);
                        exec_list *const f080C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f080C->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r080E = nequal(r07DC, body.constant(0u));
                           ir_if *f080D = new(mem_ctx) ir_if(operand(r080E).val);
                           exec_list *const f080D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f080D->then_instructions;

                              ir_variable *const r080F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r080F, add(r07D8, body.constant(1u)), 0x01));

                              ir_expression *const r0810 = less(r080F, r07D8);
                              ir_expression *const r0811 = expr(ir_unop_b2i, r0810);
                              ir_expression *const r0812 = expr(ir_unop_i2u, r0811);
                              body.emit(assign(r07D7, add(r07D7, r0812), 0x01));

                              ir_expression *const r0813 = neg(r07D9);
                              ir_expression *const r0814 = equal(r07D9, r0813);
                              ir_expression *const r0815 = expr(ir_unop_b2i, r0814);
                              ir_expression *const r0816 = expr(ir_unop_i2u, r0815);
                              ir_expression *const r0817 = bit_and(r0816, body.constant(1u));
                              ir_expression *const r0818 = expr(ir_unop_bit_not, r0817);
                              body.emit(assign(r07D8, bit_and(r080F, r0818), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f080D->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r081A = bit_or(r07D7, r07D8);
                              ir_expression *const r081B = equal(r081A, body.constant(0u));
                              ir_if *f0819 = new(mem_ctx) ir_if(operand(r081B).val);
                              exec_list *const f0819_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0819->then_instructions;

                                 body.emit(assign(r07D6, body.constant(0u), 0x01));


                              body.instructions = f0819_parent_instructions;
                              body.emit(f0819);

                              /* END IF */


                           body.instructions = f080D_parent_instructions;
                           body.emit(f080D);

                           /* END IF */

                           ir_variable *const r081C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r081C);
                           ir_expression *const r081D = lshift(r03E3, body.constant(int(31)));
                           ir_expression *const r081E = lshift(r07D6, body.constant(int(20)));
                           ir_expression *const r081F = add(r081D, r081E);
                           body.emit(assign(r081C, add(r081F, r07D7), 0x01));

                           body.emit(assign(r081C, r07D8, 0x02));

                           body.emit(assign(r07DB, r081C, 0x03));

                           body.emit(assign(r07DA, body.constant(false), 0x01));


                        body.instructions = f080C_parent_instructions;
                        body.emit(f080C);

                        /* END IF */

                        body.emit(assign(r03E4, r07DB, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f078D->else_instructions;

                        ir_variable *const r0820 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0820);
                        body.emit(assign(r0820, body.constant(0u), 0x01));

                        body.emit(assign(r0820, body.constant(0u), 0x02));

                        body.emit(assign(r03E4, r0820, 0x03));


                     body.instructions = f078D_parent_instructions;
                     body.emit(f078D);

                     /* END IF */


                  body.instructions = f06FA_parent_instructions;
                  body.emit(f06FA);

                  /* END IF */


               body.instructions = f0667_parent_instructions;
               body.emit(f0667);

               /* END IF */


            body.instructions = f05D4_parent_instructions;
            body.emit(f05D4);

            /* END IF */


         body.instructions = f05AD_parent_instructions;
         body.emit(f05AD);

         /* END IF */


      body.instructions = f04D2_parent_instructions;
      body.emit(f04D2);

      /* END IF */


   body.instructions = f03FB_parent_instructions;
   body.emit(f03FB);

   /* END IF */

   body.emit(ret(r03E4));

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

   ir_variable *const r0821 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0821);
   ir_variable *const r0822 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0822);
   ir_variable *const r0823 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0824 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0824, rshift(swizzle_x(r0821), body.constant(int(31))), 0x01));

   ir_variable *const r0825 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0825, rshift(swizzle_x(r0822), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0827 = equal(r0824, r0825);
   ir_if *f0826 = new(mem_ctx) ir_if(operand(r0827).val);
   exec_list *const f0826_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0826->then_instructions;

      ir_variable *const r0828 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0828, body.constant(true), 0x01));

      ir_variable *const r0829 = body.make_temp(glsl_type::uvec2_type, "return_value");
      ir_variable *const r082A = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r082A);
      ir_variable *const r082B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "bFrac", ir_var_auto);
      body.emit(r082B);
      ir_variable *const r082C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "aFrac", ir_var_auto);
      body.emit(r082C);
      ir_variable *const r082D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zExp", ir_var_auto);
      body.emit(r082D);
      ir_variable *const r082E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r082E);
      ir_variable *const r082F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
      body.emit(r082F);
      body.emit(assign(r082F, body.constant(0u), 0x01));

      body.emit(assign(r082E, body.constant(0u), 0x01));

      ir_variable *const r0830 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
      body.emit(assign(r0830, bit_and(swizzle_x(r0821), body.constant(1048575u)), 0x01));

      body.emit(assign(r0830, swizzle_y(r0821), 0x02));

      body.emit(assign(r082C, r0830, 0x03));

      ir_variable *const r0831 = body.make_temp(glsl_type::uint_type, "extractFloat64Exp_retval");
      ir_expression *const r0832 = rshift(swizzle_x(r0821), body.constant(int(20)));
      body.emit(assign(r0831, bit_and(r0832, body.constant(2047u)), 0x01));

      ir_variable *const r0833 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
      body.emit(assign(r0833, bit_and(swizzle_x(r0822), body.constant(1048575u)), 0x01));

      body.emit(assign(r0833, swizzle_y(r0822), 0x02));

      body.emit(assign(r082B, r0833, 0x03));

      ir_variable *const r0834 = body.make_temp(glsl_type::uint_type, "extractFloat64Exp_retval");
      ir_expression *const r0835 = rshift(swizzle_x(r0822), body.constant(int(20)));
      body.emit(assign(r0834, bit_and(r0835, body.constant(2047u)), 0x01));

      ir_variable *const r0836 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0837 = expr(ir_unop_u2i, r0831);
      ir_expression *const r0838 = expr(ir_unop_u2i, r0834);
      body.emit(assign(r0836, sub(r0837, r0838), 0x01));

      body.emit(assign(r082A, r0836, 0x01));

      /* IF CONDITION */
      ir_expression *const r083A = less(body.constant(int(0)), r0836);
      ir_if *f0839 = new(mem_ctx) ir_if(operand(r083A).val);
      exec_list *const f0839_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0839->then_instructions;

         /* IF CONDITION */
         ir_expression *const r083C = equal(r0831, body.constant(2047u));
         ir_if *f083B = new(mem_ctx) ir_if(operand(r083C).val);
         exec_list *const f083B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f083B->then_instructions;

            /* IF CONDITION */
            ir_expression *const r083E = bit_or(swizzle_x(r0830), swizzle_y(r0821));
            ir_expression *const r083F = nequal(r083E, body.constant(0u));
            ir_if *f083D = new(mem_ctx) ir_if(operand(r083F).val);
            exec_list *const f083D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f083D->then_instructions;

               ir_variable *const r0840 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0840, swizzle_x(r0821), 0x01));

               ir_variable *const r0841 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0841, swizzle_x(r0822), 0x01));

               ir_variable *const r0842 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0843 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
               ir_expression *const r0844 = rshift(swizzle_y(r0821), body.constant(int(19)));
               ir_expression *const r0845 = bit_and(r0844, body.constant(4095u));
               ir_expression *const r0846 = equal(r0845, body.constant(4094u));
               ir_expression *const r0847 = nequal(swizzle_x(r0821), body.constant(0u));
               ir_expression *const r0848 = bit_and(swizzle_y(r0821), body.constant(524287u));
               ir_expression *const r0849 = nequal(r0848, body.constant(0u));
               ir_expression *const r084A = logic_or(r0847, r0849);
               body.emit(assign(r0843, logic_and(r0846, r084A), 0x01));

               ir_variable *const r084B = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r084C = lshift(swizzle_y(r0822), body.constant(int(1)));
               ir_expression *const r084D = lequal(body.constant(4292870144u), r084C);
               ir_expression *const r084E = nequal(swizzle_x(r0822), body.constant(0u));
               ir_expression *const r084F = bit_and(swizzle_y(r0822), body.constant(1048575u));
               ir_expression *const r0850 = nequal(r084F, body.constant(0u));
               ir_expression *const r0851 = logic_or(r084E, r0850);
               body.emit(assign(r084B, logic_and(r084D, r0851), 0x01));

               body.emit(assign(r0840, bit_or(swizzle_y(r0821), body.constant(524288u)), 0x02));

               body.emit(assign(r0841, bit_or(swizzle_y(r0822), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r0853 = lshift(swizzle_y(r0821), body.constant(int(1)));
               ir_expression *const r0854 = lequal(body.constant(4292870144u), r0853);
               ir_expression *const r0855 = nequal(swizzle_x(r0821), body.constant(0u));
               ir_expression *const r0856 = bit_and(swizzle_y(r0821), body.constant(1048575u));
               ir_expression *const r0857 = nequal(r0856, body.constant(0u));
               ir_expression *const r0858 = logic_or(r0855, r0857);
               ir_expression *const r0859 = logic_and(r0854, r0858);
               ir_if *f0852 = new(mem_ctx) ir_if(operand(r0859).val);
               exec_list *const f0852_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0852->then_instructions;

                  ir_variable *const r085A = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r085C = logic_and(r0843, r084B);
                  ir_if *f085B = new(mem_ctx) ir_if(operand(r085C).val);
                  exec_list *const f085B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f085B->then_instructions;

                     body.emit(assign(r085A, r0841, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f085B->else_instructions;

                     body.emit(assign(r085A, r0840, 0x03));


                  body.instructions = f085B_parent_instructions;
                  body.emit(f085B);

                  /* END IF */

                  body.emit(assign(r0842, r085A, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0852->else_instructions;

                  body.emit(assign(r0842, r0841, 0x03));


               body.instructions = f0852_parent_instructions;
               body.emit(f0852);

               /* END IF */

               body.emit(assign(r0829, r0842, 0x03));

               body.emit(assign(r0828, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f083D->else_instructions;

               body.emit(assign(r0829, r0821, 0x03));

               body.emit(assign(r0828, body.constant(false), 0x01));


            body.instructions = f083D_parent_instructions;
            body.emit(f083D);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f083B->else_instructions;

            /* IF CONDITION */
            ir_expression *const r085E = equal(r0834, body.constant(0u));
            ir_if *f085D = new(mem_ctx) ir_if(operand(r085E).val);
            exec_list *const f085D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f085D->then_instructions;

               body.emit(assign(r082A, add(r0836, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f085D->else_instructions;

               body.emit(assign(r082B, bit_or(swizzle_x(r0833), body.constant(1048576u)), 0x01));


            body.instructions = f085D_parent_instructions;
            body.emit(f085D);

            /* END IF */

            ir_variable *const r085F = body.make_temp(glsl_type::uint_type, "a0");
            body.emit(assign(r085F, swizzle_x(r082B), 0x01));

            ir_variable *const r0860 = body.make_temp(glsl_type::uint_type, "a1");
            body.emit(assign(r0860, swizzle_y(r082B), 0x01));

            ir_variable *const r0861 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0861, body.constant(0u), 0x01));

            ir_variable *const r0862 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0862);
            ir_variable *const r0863 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0863);
            ir_variable *const r0864 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0864);
            ir_variable *const r0865 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0866 = neg(r082A);
            body.emit(assign(r0865, bit_and(r0866, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0868 = equal(r082A, body.constant(int(0)));
            ir_if *f0867 = new(mem_ctx) ir_if(operand(r0868).val);
            exec_list *const f0867_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0867->then_instructions;

               body.emit(assign(r0862, r0861, 0x01));

               body.emit(assign(r0863, r0860, 0x01));

               body.emit(assign(r0864, r085F, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0867->else_instructions;

               /* IF CONDITION */
               ir_expression *const r086A = less(r082A, body.constant(int(32)));
               ir_if *f0869 = new(mem_ctx) ir_if(operand(r086A).val);
               exec_list *const f0869_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0869->then_instructions;

                  body.emit(assign(r0862, lshift(swizzle_y(r0833), r0865), 0x01));

                  ir_expression *const r086B = lshift(swizzle_x(r082B), r0865);
                  ir_expression *const r086C = rshift(swizzle_y(r0833), r082A);
                  body.emit(assign(r0863, bit_or(r086B, r086C), 0x01));

                  body.emit(assign(r0864, rshift(swizzle_x(r082B), r082A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0869->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r086E = equal(r082A, body.constant(int(32)));
                  ir_if *f086D = new(mem_ctx) ir_if(operand(r086E).val);
                  exec_list *const f086D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f086D->then_instructions;

                     body.emit(assign(r0862, r0860, 0x01));

                     body.emit(assign(r0863, r085F, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f086D->else_instructions;

                     body.emit(assign(r0861, bit_or(body.constant(0u), swizzle_y(r0833)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0870 = less(r082A, body.constant(int(64)));
                     ir_if *f086F = new(mem_ctx) ir_if(operand(r0870).val);
                     exec_list *const f086F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f086F->then_instructions;

                        body.emit(assign(r0862, lshift(swizzle_x(r082B), r0865), 0x01));

                        ir_expression *const r0871 = bit_and(r082A, body.constant(int(31)));
                        body.emit(assign(r0863, rshift(swizzle_x(r082B), r0871), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f086F->else_instructions;

                        ir_variable *const r0872 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0874 = equal(r082A, body.constant(int(64)));
                        ir_if *f0873 = new(mem_ctx) ir_if(operand(r0874).val);
                        exec_list *const f0873_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0873->then_instructions;

                           body.emit(assign(r0872, r085F, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0873->else_instructions;

                           ir_expression *const r0875 = nequal(swizzle_x(r082B), body.constant(0u));
                           ir_expression *const r0876 = expr(ir_unop_b2i, r0875);
                           body.emit(assign(r0872, expr(ir_unop_i2u, r0876), 0x01));


                        body.instructions = f0873_parent_instructions;
                        body.emit(f0873);

                        /* END IF */

                        body.emit(assign(r0862, r0872, 0x01));

                        body.emit(assign(r0863, body.constant(0u), 0x01));


                     body.instructions = f086F_parent_instructions;
                     body.emit(f086F);

                     /* END IF */


                  body.instructions = f086D_parent_instructions;
                  body.emit(f086D);

                  /* END IF */

                  body.emit(assign(r0864, body.constant(0u), 0x01));


               body.instructions = f0869_parent_instructions;
               body.emit(f0869);

               /* END IF */

               ir_expression *const r0877 = nequal(r0861, body.constant(0u));
               ir_expression *const r0878 = expr(ir_unop_b2i, r0877);
               ir_expression *const r0879 = expr(ir_unop_i2u, r0878);
               body.emit(assign(r0862, bit_or(r0862, r0879), 0x01));


            body.instructions = f0867_parent_instructions;
            body.emit(f0867);

            /* END IF */

            body.emit(assign(r082B, r0864, 0x01));

            body.emit(assign(r082B, r0863, 0x02));

            body.emit(assign(r082E, r0862, 0x01));

            body.emit(assign(r082D, r0831, 0x01));


         body.instructions = f083B_parent_instructions;
         body.emit(f083B);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0839->else_instructions;

         /* IF CONDITION */
         ir_expression *const r087B = less(r082A, body.constant(int(0)));
         ir_if *f087A = new(mem_ctx) ir_if(operand(r087B).val);
         exec_list *const f087A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f087A->then_instructions;

            /* IF CONDITION */
            ir_expression *const r087D = equal(r0834, body.constant(2047u));
            ir_if *f087C = new(mem_ctx) ir_if(operand(r087D).val);
            exec_list *const f087C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f087C->then_instructions;

               /* IF CONDITION */
               ir_expression *const r087F = bit_or(swizzle_x(r082B), swizzle_y(r082B));
               ir_expression *const r0880 = nequal(r087F, body.constant(0u));
               ir_if *f087E = new(mem_ctx) ir_if(operand(r0880).val);
               exec_list *const f087E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f087E->then_instructions;

                  ir_variable *const r0881 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0881, swizzle_x(r0821), 0x01));

                  ir_variable *const r0882 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0882, swizzle_x(r0822), 0x01));

                  ir_variable *const r0883 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0884 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
                  ir_expression *const r0885 = rshift(swizzle_y(r0821), body.constant(int(19)));
                  ir_expression *const r0886 = bit_and(r0885, body.constant(4095u));
                  ir_expression *const r0887 = equal(r0886, body.constant(4094u));
                  ir_expression *const r0888 = nequal(swizzle_x(r0821), body.constant(0u));
                  ir_expression *const r0889 = bit_and(swizzle_y(r0821), body.constant(524287u));
                  ir_expression *const r088A = nequal(r0889, body.constant(0u));
                  ir_expression *const r088B = logic_or(r0888, r088A);
                  body.emit(assign(r0884, logic_and(r0887, r088B), 0x01));

                  ir_variable *const r088C = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r088D = lshift(swizzle_y(r0822), body.constant(int(1)));
                  ir_expression *const r088E = lequal(body.constant(4292870144u), r088D);
                  ir_expression *const r088F = nequal(swizzle_x(r0822), body.constant(0u));
                  ir_expression *const r0890 = bit_and(swizzle_y(r0822), body.constant(1048575u));
                  ir_expression *const r0891 = nequal(r0890, body.constant(0u));
                  ir_expression *const r0892 = logic_or(r088F, r0891);
                  body.emit(assign(r088C, logic_and(r088E, r0892), 0x01));

                  body.emit(assign(r0881, bit_or(swizzle_y(r0821), body.constant(524288u)), 0x02));

                  body.emit(assign(r0882, bit_or(swizzle_y(r0822), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0894 = lshift(swizzle_y(r0821), body.constant(int(1)));
                  ir_expression *const r0895 = lequal(body.constant(4292870144u), r0894);
                  ir_expression *const r0896 = nequal(swizzle_x(r0821), body.constant(0u));
                  ir_expression *const r0897 = bit_and(swizzle_y(r0821), body.constant(1048575u));
                  ir_expression *const r0898 = nequal(r0897, body.constant(0u));
                  ir_expression *const r0899 = logic_or(r0896, r0898);
                  ir_expression *const r089A = logic_and(r0895, r0899);
                  ir_if *f0893 = new(mem_ctx) ir_if(operand(r089A).val);
                  exec_list *const f0893_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0893->then_instructions;

                     ir_variable *const r089B = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r089D = logic_and(r0884, r088C);
                     ir_if *f089C = new(mem_ctx) ir_if(operand(r089D).val);
                     exec_list *const f089C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f089C->then_instructions;

                        body.emit(assign(r089B, r0882, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f089C->else_instructions;

                        body.emit(assign(r089B, r0881, 0x03));


                     body.instructions = f089C_parent_instructions;
                     body.emit(f089C);

                     /* END IF */

                     body.emit(assign(r0883, r089B, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0893->else_instructions;

                     body.emit(assign(r0883, r0882, 0x03));


                  body.instructions = f0893_parent_instructions;
                  body.emit(f0893);

                  /* END IF */

                  body.emit(assign(r0829, r0883, 0x03));

                  body.emit(assign(r0828, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f087E->else_instructions;

                  ir_variable *const r089E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r089E);
                  ir_expression *const r089F = lshift(r0824, body.constant(int(31)));
                  body.emit(assign(r089E, add(r089F, body.constant(2146435072u)), 0x01));

                  body.emit(assign(r089E, body.constant(0u), 0x02));

                  body.emit(assign(r0829, r089E, 0x03));

                  body.emit(assign(r0828, body.constant(false), 0x01));


               body.instructions = f087E_parent_instructions;
               body.emit(f087E);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f087C->else_instructions;

               /* IF CONDITION */
               ir_expression *const r08A1 = equal(r0831, body.constant(0u));
               ir_if *f08A0 = new(mem_ctx) ir_if(operand(r08A1).val);
               exec_list *const f08A0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08A0->then_instructions;

                  body.emit(assign(r082A, add(r082A, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08A0->else_instructions;

                  body.emit(assign(r082C, bit_or(swizzle_x(r0830), body.constant(1048576u)), 0x01));


               body.instructions = f08A0_parent_instructions;
               body.emit(f08A0);

               /* END IF */

               ir_variable *const r08A2 = body.make_temp(glsl_type::uint_type, "a0");
               body.emit(assign(r08A2, swizzle_x(r082C), 0x01));

               ir_variable *const r08A3 = body.make_temp(glsl_type::uint_type, "a1");
               body.emit(assign(r08A3, swizzle_y(r082C), 0x01));

               ir_variable *const r08A4 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r08A4, body.constant(0u), 0x01));

               ir_variable *const r08A5 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r08A5, neg(r082A), 0x01));

               ir_variable *const r08A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r08A6);
               ir_variable *const r08A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r08A7);
               ir_variable *const r08A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r08A8);
               ir_variable *const r08A9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r08AA = neg(r08A5);
               body.emit(assign(r08A9, bit_and(r08AA, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r08AC = equal(r08A5, body.constant(int(0)));
               ir_if *f08AB = new(mem_ctx) ir_if(operand(r08AC).val);
               exec_list *const f08AB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08AB->then_instructions;

                  body.emit(assign(r08A6, r08A4, 0x01));

                  body.emit(assign(r08A7, r08A3, 0x01));

                  body.emit(assign(r08A8, r08A2, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08AB->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r08AE = less(r08A5, body.constant(int(32)));
                  ir_if *f08AD = new(mem_ctx) ir_if(operand(r08AE).val);
                  exec_list *const f08AD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08AD->then_instructions;

                     body.emit(assign(r08A6, lshift(swizzle_y(r0830), r08A9), 0x01));

                     ir_expression *const r08AF = lshift(swizzle_x(r082C), r08A9);
                     ir_expression *const r08B0 = rshift(swizzle_y(r0830), r08A5);
                     body.emit(assign(r08A7, bit_or(r08AF, r08B0), 0x01));

                     body.emit(assign(r08A8, rshift(swizzle_x(r082C), r08A5), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08AD->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r08B2 = equal(r08A5, body.constant(int(32)));
                     ir_if *f08B1 = new(mem_ctx) ir_if(operand(r08B2).val);
                     exec_list *const f08B1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08B1->then_instructions;

                        body.emit(assign(r08A6, r08A3, 0x01));

                        body.emit(assign(r08A7, r08A2, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08B1->else_instructions;

                        body.emit(assign(r08A4, bit_or(body.constant(0u), swizzle_y(r0830)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08B4 = less(r08A5, body.constant(int(64)));
                        ir_if *f08B3 = new(mem_ctx) ir_if(operand(r08B4).val);
                        exec_list *const f08B3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08B3->then_instructions;

                           body.emit(assign(r08A6, lshift(swizzle_x(r082C), r08A9), 0x01));

                           ir_expression *const r08B5 = bit_and(r08A5, body.constant(int(31)));
                           body.emit(assign(r08A7, rshift(swizzle_x(r082C), r08B5), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f08B3->else_instructions;

                           ir_variable *const r08B6 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r08B8 = equal(r08A5, body.constant(int(64)));
                           ir_if *f08B7 = new(mem_ctx) ir_if(operand(r08B8).val);
                           exec_list *const f08B7_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f08B7->then_instructions;

                              body.emit(assign(r08B6, r08A2, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f08B7->else_instructions;

                              ir_expression *const r08B9 = nequal(swizzle_x(r082C), body.constant(0u));
                              ir_expression *const r08BA = expr(ir_unop_b2i, r08B9);
                              body.emit(assign(r08B6, expr(ir_unop_i2u, r08BA), 0x01));


                           body.instructions = f08B7_parent_instructions;
                           body.emit(f08B7);

                           /* END IF */

                           body.emit(assign(r08A6, r08B6, 0x01));

                           body.emit(assign(r08A7, body.constant(0u), 0x01));


                        body.instructions = f08B3_parent_instructions;
                        body.emit(f08B3);

                        /* END IF */


                     body.instructions = f08B1_parent_instructions;
                     body.emit(f08B1);

                     /* END IF */

                     body.emit(assign(r08A8, body.constant(0u), 0x01));


                  body.instructions = f08AD_parent_instructions;
                  body.emit(f08AD);

                  /* END IF */

                  ir_expression *const r08BB = nequal(r08A4, body.constant(0u));
                  ir_expression *const r08BC = expr(ir_unop_b2i, r08BB);
                  ir_expression *const r08BD = expr(ir_unop_i2u, r08BC);
                  body.emit(assign(r08A6, bit_or(r08A6, r08BD), 0x01));


               body.instructions = f08AB_parent_instructions;
               body.emit(f08AB);

               /* END IF */

               body.emit(assign(r082C, r08A8, 0x01));

               body.emit(assign(r082C, r08A7, 0x02));

               body.emit(assign(r082E, r08A6, 0x01));

               body.emit(assign(r082D, r0834, 0x01));


            body.instructions = f087C_parent_instructions;
            body.emit(f087C);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f087A->else_instructions;

            /* IF CONDITION */
            ir_expression *const r08BF = equal(r0831, body.constant(2047u));
            ir_if *f08BE = new(mem_ctx) ir_if(operand(r08BF).val);
            exec_list *const f08BE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08BE->then_instructions;

               /* IF CONDITION */
               ir_expression *const r08C1 = bit_or(swizzle_x(r082C), swizzle_y(r082C));
               ir_expression *const r08C2 = bit_or(swizzle_x(r082B), swizzle_y(r082B));
               ir_expression *const r08C3 = bit_or(r08C1, r08C2);
               ir_expression *const r08C4 = nequal(r08C3, body.constant(0u));
               ir_if *f08C0 = new(mem_ctx) ir_if(operand(r08C4).val);
               exec_list *const f08C0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08C0->then_instructions;

                  ir_variable *const r08C5 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r08C5, swizzle_x(r0821), 0x01));

                  ir_variable *const r08C6 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r08C6, swizzle_x(r0822), 0x01));

                  ir_variable *const r08C7 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r08C8 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
                  ir_expression *const r08C9 = rshift(swizzle_y(r0821), body.constant(int(19)));
                  ir_expression *const r08CA = bit_and(r08C9, body.constant(4095u));
                  ir_expression *const r08CB = equal(r08CA, body.constant(4094u));
                  ir_expression *const r08CC = nequal(swizzle_x(r0821), body.constant(0u));
                  ir_expression *const r08CD = bit_and(swizzle_y(r0821), body.constant(524287u));
                  ir_expression *const r08CE = nequal(r08CD, body.constant(0u));
                  ir_expression *const r08CF = logic_or(r08CC, r08CE);
                  body.emit(assign(r08C8, logic_and(r08CB, r08CF), 0x01));

                  ir_variable *const r08D0 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r08D1 = lshift(swizzle_y(r0822), body.constant(int(1)));
                  ir_expression *const r08D2 = lequal(body.constant(4292870144u), r08D1);
                  ir_expression *const r08D3 = nequal(swizzle_x(r0822), body.constant(0u));
                  ir_expression *const r08D4 = bit_and(swizzle_y(r0822), body.constant(1048575u));
                  ir_expression *const r08D5 = nequal(r08D4, body.constant(0u));
                  ir_expression *const r08D6 = logic_or(r08D3, r08D5);
                  body.emit(assign(r08D0, logic_and(r08D2, r08D6), 0x01));

                  body.emit(assign(r08C5, bit_or(swizzle_y(r0821), body.constant(524288u)), 0x02));

                  body.emit(assign(r08C6, bit_or(swizzle_y(r0822), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r08D8 = lshift(swizzle_y(r0821), body.constant(int(1)));
                  ir_expression *const r08D9 = lequal(body.constant(4292870144u), r08D8);
                  ir_expression *const r08DA = nequal(swizzle_x(r0821), body.constant(0u));
                  ir_expression *const r08DB = bit_and(swizzle_y(r0821), body.constant(1048575u));
                  ir_expression *const r08DC = nequal(r08DB, body.constant(0u));
                  ir_expression *const r08DD = logic_or(r08DA, r08DC);
                  ir_expression *const r08DE = logic_and(r08D9, r08DD);
                  ir_if *f08D7 = new(mem_ctx) ir_if(operand(r08DE).val);
                  exec_list *const f08D7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08D7->then_instructions;

                     ir_variable *const r08DF = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r08E1 = logic_and(r08C8, r08D0);
                     ir_if *f08E0 = new(mem_ctx) ir_if(operand(r08E1).val);
                     exec_list *const f08E0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08E0->then_instructions;

                        body.emit(assign(r08DF, r08C6, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08E0->else_instructions;

                        body.emit(assign(r08DF, r08C5, 0x03));


                     body.instructions = f08E0_parent_instructions;
                     body.emit(f08E0);

                     /* END IF */

                     body.emit(assign(r08C7, r08DF, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08D7->else_instructions;

                     body.emit(assign(r08C7, r08C6, 0x03));


                  body.instructions = f08D7_parent_instructions;
                  body.emit(f08D7);

                  /* END IF */

                  body.emit(assign(r0829, r08C7, 0x03));

                  body.emit(assign(r0828, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08C0->else_instructions;

                  body.emit(assign(r0829, r0821, 0x03));

                  body.emit(assign(r0828, body.constant(false), 0x01));


               body.instructions = f08C0_parent_instructions;
               body.emit(f08C0);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08BE->else_instructions;

               ir_variable *const r08E2 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r08E3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r08E3, add(swizzle_y(r082C), swizzle_y(r082B)), 0x01));

               ir_expression *const r08E4 = add(swizzle_x(r082C), swizzle_x(r082B));
               ir_expression *const r08E5 = less(r08E3, swizzle_y(r082C));
               ir_expression *const r08E6 = expr(ir_unop_b2i, r08E5);
               ir_expression *const r08E7 = expr(ir_unop_i2u, r08E6);
               body.emit(assign(r08E2, add(r08E4, r08E7), 0x01));

               body.emit(assign(r082F, r08E2, 0x01));

               /* IF CONDITION */
               ir_expression *const r08E9 = equal(r0831, body.constant(0u));
               ir_if *f08E8 = new(mem_ctx) ir_if(operand(r08E9).val);
               exec_list *const f08E8_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08E8->then_instructions;

                  ir_variable *const r08EA = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r08EA);
                  ir_expression *const r08EB = lshift(r0824, body.constant(int(31)));
                  body.emit(assign(r08EA, add(r08EB, r08E2), 0x01));

                  body.emit(assign(r08EA, r08E3, 0x02));

                  body.emit(assign(r0829, r08EA, 0x03));

                  body.emit(assign(r0828, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08E8->else_instructions;

                  body.emit(assign(r082F, bit_or(r08E2, body.constant(2097152u)), 0x01));

                  body.emit(assign(r082D, r0831, 0x01));

                  ir_variable *const r08EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r08EC);
                  ir_variable *const r08ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r08ED);
                  ir_variable *const r08EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r08EE);
                  body.emit(assign(r08EC, lshift(r08E3, body.constant(int(31))), 0x01));

                  ir_expression *const r08EF = lshift(r082F, body.constant(int(31)));
                  ir_expression *const r08F0 = rshift(r08E3, body.constant(int(1)));
                  body.emit(assign(r08ED, bit_or(r08EF, r08F0), 0x01));

                  body.emit(assign(r08EE, rshift(r082F, body.constant(int(1))), 0x01));

                  body.emit(assign(r08EC, bit_or(r08EC, body.constant(0u)), 0x01));

                  body.emit(assign(r082F, r08EE, 0x01));

                  body.emit(assign(r082E, r08EC, 0x01));

                  ir_variable *const r08F1 = body.make_temp(glsl_type::uint_type, "zExp");
                  body.emit(assign(r08F1, r0831, 0x01));

                  ir_variable *const r08F2 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r08F2, r08EE, 0x01));

                  ir_variable *const r08F3 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r08F3, r08ED, 0x01));

                  ir_variable *const r08F4 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r08F4, r08EC, 0x01));

                  ir_variable *const r08F5 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r08F5, body.constant(true), 0x01));

                  ir_variable *const r08F6 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r08F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
                  body.emit(r08F7);
                  ir_expression *const r08F8 = less(r08EC, body.constant(0u));
                  ir_expression *const r08F9 = expr(ir_unop_b2i, r08F8);
                  body.emit(assign(r08F7, expr(ir_unop_i2u, r08F9), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r08FB = lequal(body.constant(2045u), r0831);
                  ir_if *f08FA = new(mem_ctx) ir_if(operand(r08FB).val);
                  exec_list *const f08FA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08FA->then_instructions;

                     ir_variable *const r08FC = body.make_temp(glsl_type::bool_type, "or_tmp");
                     /* IF CONDITION */
                     ir_expression *const r08FE = less(body.constant(2045u), r0831);
                     ir_if *f08FD = new(mem_ctx) ir_if(operand(r08FE).val);
                     exec_list *const f08FD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08FD->then_instructions;

                        body.emit(assign(r08FC, body.constant(true), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08FD->else_instructions;

                        ir_variable *const r08FF = body.make_temp(glsl_type::bool_type, "and_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0901 = equal(r0831, body.constant(2045u));
                        ir_if *f0900 = new(mem_ctx) ir_if(operand(r0901).val);
                        exec_list *const f0900_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0900->then_instructions;

                           ir_expression *const r0902 = equal(body.constant(2097151u), r08EE);
                           ir_expression *const r0903 = equal(body.constant(4294967295u), r08ED);
                           body.emit(assign(r08FF, logic_and(r0902, r0903), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0900->else_instructions;

                           body.emit(assign(r08FF, body.constant(false), 0x01));


                        body.instructions = f0900_parent_instructions;
                        body.emit(f0900);

                        /* END IF */

                        ir_expression *const r0904 = nequal(r08F7, body.constant(0u));
                        body.emit(assign(r08FC, logic_and(r08FF, r0904), 0x01));


                     body.instructions = f08FD_parent_instructions;
                     body.emit(f08FD);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0905 = new(mem_ctx) ir_if(operand(r08FC).val);
                     exec_list *const f0905_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0905->then_instructions;

                        ir_variable *const r0906 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0906);
                        ir_expression *const r0907 = lshift(r0824, body.constant(int(31)));
                        body.emit(assign(r0906, add(r0907, body.constant(2146435072u)), 0x01));

                        body.emit(assign(r0906, body.constant(0u), 0x02));

                        body.emit(assign(r08F6, r0906, 0x03));

                        body.emit(assign(r08F5, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0905->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0909 = less(r0831, body.constant(0u));
                        ir_if *f0908 = new(mem_ctx) ir_if(operand(r0909).val);
                        exec_list *const f0908_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0908->then_instructions;

                           ir_variable *const r090A = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r090A, r08EC, 0x01));

                           ir_variable *const r090B = body.make_temp(glsl_type::int_type, "count");
                           ir_expression *const r090C = neg(r0831);
                           body.emit(assign(r090B, expr(ir_unop_u2i, r090C), 0x01));

                           ir_variable *const r090D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r090D);
                           ir_variable *const r090E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r090E);
                           ir_variable *const r090F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r090F);
                           ir_variable *const r0910 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0911 = neg(r090B);
                           body.emit(assign(r0910, bit_and(r0911, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0913 = equal(r090B, body.constant(int(0)));
                           ir_if *f0912 = new(mem_ctx) ir_if(operand(r0913).val);
                           exec_list *const f0912_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0912->then_instructions;

                              body.emit(assign(r090D, r08EC, 0x01));

                              body.emit(assign(r090E, r08ED, 0x01));

                              body.emit(assign(r090F, r08EE, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0912->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0915 = less(r090B, body.constant(int(32)));
                              ir_if *f0914 = new(mem_ctx) ir_if(operand(r0915).val);
                              exec_list *const f0914_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0914->then_instructions;

                                 body.emit(assign(r090D, lshift(r08ED, r0910), 0x01));

                                 ir_expression *const r0916 = lshift(r08EE, r0910);
                                 ir_expression *const r0917 = rshift(r08ED, r090B);
                                 body.emit(assign(r090E, bit_or(r0916, r0917), 0x01));

                                 body.emit(assign(r090F, rshift(r08EE, r090B), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0914->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0919 = equal(r090B, body.constant(int(32)));
                                 ir_if *f0918 = new(mem_ctx) ir_if(operand(r0919).val);
                                 exec_list *const f0918_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0918->then_instructions;

                                    body.emit(assign(r090D, r08ED, 0x01));

                                    body.emit(assign(r090E, r08EE, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0918->else_instructions;

                                    body.emit(assign(r090A, bit_or(r08EC, r08ED), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r091B = less(r090B, body.constant(int(64)));
                                    ir_if *f091A = new(mem_ctx) ir_if(operand(r091B).val);
                                    exec_list *const f091A_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f091A->then_instructions;

                                       body.emit(assign(r090D, lshift(r08EE, r0910), 0x01));

                                       ir_expression *const r091C = bit_and(r090B, body.constant(int(31)));
                                       body.emit(assign(r090E, rshift(r08EE, r091C), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f091A->else_instructions;

                                       ir_variable *const r091D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r091F = equal(r090B, body.constant(int(64)));
                                       ir_if *f091E = new(mem_ctx) ir_if(operand(r091F).val);
                                       exec_list *const f091E_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f091E->then_instructions;

                                          body.emit(assign(r091D, r08EE, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f091E->else_instructions;

                                          ir_expression *const r0920 = nequal(r08EE, body.constant(0u));
                                          ir_expression *const r0921 = expr(ir_unop_b2i, r0920);
                                          body.emit(assign(r091D, expr(ir_unop_i2u, r0921), 0x01));


                                       body.instructions = f091E_parent_instructions;
                                       body.emit(f091E);

                                       /* END IF */

                                       body.emit(assign(r090D, r091D, 0x01));

                                       body.emit(assign(r090E, body.constant(0u), 0x01));


                                    body.instructions = f091A_parent_instructions;
                                    body.emit(f091A);

                                    /* END IF */


                                 body.instructions = f0918_parent_instructions;
                                 body.emit(f0918);

                                 /* END IF */

                                 body.emit(assign(r090F, body.constant(0u), 0x01));


                              body.instructions = f0914_parent_instructions;
                              body.emit(f0914);

                              /* END IF */

                              ir_expression *const r0922 = nequal(r090A, body.constant(0u));
                              ir_expression *const r0923 = expr(ir_unop_b2i, r0922);
                              ir_expression *const r0924 = expr(ir_unop_i2u, r0923);
                              body.emit(assign(r090D, bit_or(r090D, r0924), 0x01));


                           body.instructions = f0912_parent_instructions;
                           body.emit(f0912);

                           /* END IF */

                           body.emit(assign(r08F2, r090F, 0x01));

                           body.emit(assign(r08F3, r090E, 0x01));

                           body.emit(assign(r08F4, r090D, 0x01));

                           body.emit(assign(r08F1, body.constant(0u), 0x01));

                           ir_expression *const r0925 = less(r090D, body.constant(0u));
                           ir_expression *const r0926 = expr(ir_unop_b2i, r0925);
                           body.emit(assign(r08F7, expr(ir_unop_i2u, r0926), 0x01));


                        body.instructions = f0908_parent_instructions;
                        body.emit(f0908);

                        /* END IF */


                     body.instructions = f0905_parent_instructions;
                     body.emit(f0905);

                     /* END IF */


                  body.instructions = f08FA_parent_instructions;
                  body.emit(f08FA);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0927 = new(mem_ctx) ir_if(operand(r08F5).val);
                  exec_list *const f0927_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0927->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0929 = nequal(r08F7, body.constant(0u));
                     ir_if *f0928 = new(mem_ctx) ir_if(operand(r0929).val);
                     exec_list *const f0928_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0928->then_instructions;

                        ir_variable *const r092A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r092A, add(r08F3, body.constant(1u)), 0x01));

                        ir_expression *const r092B = less(r092A, r08F3);
                        ir_expression *const r092C = expr(ir_unop_b2i, r092B);
                        ir_expression *const r092D = expr(ir_unop_i2u, r092C);
                        body.emit(assign(r08F2, add(r08F2, r092D), 0x01));

                        ir_expression *const r092E = neg(r08F4);
                        ir_expression *const r092F = equal(r08F4, r092E);
                        ir_expression *const r0930 = expr(ir_unop_b2i, r092F);
                        ir_expression *const r0931 = expr(ir_unop_i2u, r0930);
                        ir_expression *const r0932 = bit_and(r0931, body.constant(1u));
                        ir_expression *const r0933 = expr(ir_unop_bit_not, r0932);
                        body.emit(assign(r08F3, bit_and(r092A, r0933), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0928->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0935 = bit_or(r08F2, r08F3);
                        ir_expression *const r0936 = equal(r0935, body.constant(0u));
                        ir_if *f0934 = new(mem_ctx) ir_if(operand(r0936).val);
                        exec_list *const f0934_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0934->then_instructions;

                           body.emit(assign(r08F1, body.constant(0u), 0x01));


                        body.instructions = f0934_parent_instructions;
                        body.emit(f0934);

                        /* END IF */


                     body.instructions = f0928_parent_instructions;
                     body.emit(f0928);

                     /* END IF */

                     ir_variable *const r0937 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0937);
                     ir_expression *const r0938 = lshift(r0824, body.constant(int(31)));
                     ir_expression *const r0939 = lshift(r08F1, body.constant(int(20)));
                     ir_expression *const r093A = add(r0938, r0939);
                     body.emit(assign(r0937, add(r093A, r08F2), 0x01));

                     body.emit(assign(r0937, r08F3, 0x02));

                     body.emit(assign(r08F6, r0937, 0x03));

                     body.emit(assign(r08F5, body.constant(false), 0x01));


                  body.instructions = f0927_parent_instructions;
                  body.emit(f0927);

                  /* END IF */

                  body.emit(assign(r0829, r08F6, 0x03));

                  body.emit(assign(r0828, body.constant(false), 0x01));


               body.instructions = f08E8_parent_instructions;
               body.emit(f08E8);

               /* END IF */


            body.instructions = f08BE_parent_instructions;
            body.emit(f08BE);

            /* END IF */


         body.instructions = f087A_parent_instructions;
         body.emit(f087A);

         /* END IF */


      body.instructions = f0839_parent_instructions;
      body.emit(f0839);

      /* END IF */

      /* IF CONDITION */
      ir_if *f093B = new(mem_ctx) ir_if(operand(r0828).val);
      exec_list *const f093B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f093B->then_instructions;

         body.emit(assign(r082C, bit_or(swizzle_x(r082C), body.constant(1048576u)), 0x01));

         ir_variable *const r093C = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r093D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r093D, add(swizzle_y(r082C), swizzle_y(r082B)), 0x01));

         ir_expression *const r093E = add(swizzle_x(r082C), swizzle_x(r082B));
         ir_expression *const r093F = less(r093D, swizzle_y(r082C));
         ir_expression *const r0940 = expr(ir_unop_b2i, r093F);
         ir_expression *const r0941 = expr(ir_unop_i2u, r0940);
         body.emit(assign(r093C, add(r093E, r0941), 0x01));

         body.emit(assign(r082F, r093C, 0x01));

         body.emit(assign(r082D, add(r082D, body.constant(4294967295u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0943 = less(r093C, body.constant(2097152u));
         ir_if *f0942 = new(mem_ctx) ir_if(operand(r0943).val);
         exec_list *const f0942_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0942->then_instructions;

            ir_variable *const r0944 = body.make_temp(glsl_type::uint_type, "zExp");
            body.emit(assign(r0944, r082D, 0x01));

            ir_variable *const r0945 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0945, r093C, 0x01));

            ir_variable *const r0946 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0946, r093D, 0x01));

            ir_variable *const r0947 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0947, r082E, 0x01));

            ir_variable *const r0948 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0948, body.constant(true), 0x01));

            ir_variable *const r0949 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r094A = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
            body.emit(r094A);
            ir_expression *const r094B = less(r082E, body.constant(0u));
            ir_expression *const r094C = expr(ir_unop_b2i, r094B);
            body.emit(assign(r094A, expr(ir_unop_i2u, r094C), 0x01));

            /* IF CONDITION */
            ir_expression *const r094E = lequal(body.constant(2045u), r082D);
            ir_if *f094D = new(mem_ctx) ir_if(operand(r094E).val);
            exec_list *const f094D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f094D->then_instructions;

               ir_variable *const r094F = body.make_temp(glsl_type::bool_type, "or_tmp");
               /* IF CONDITION */
               ir_expression *const r0951 = less(body.constant(2045u), r082D);
               ir_if *f0950 = new(mem_ctx) ir_if(operand(r0951).val);
               exec_list *const f0950_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0950->then_instructions;

                  body.emit(assign(r094F, body.constant(true), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0950->else_instructions;

                  ir_variable *const r0952 = body.make_temp(glsl_type::bool_type, "and_tmp");
                  /* IF CONDITION */
                  ir_expression *const r0954 = equal(r082D, body.constant(2045u));
                  ir_if *f0953 = new(mem_ctx) ir_if(operand(r0954).val);
                  exec_list *const f0953_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0953->then_instructions;

                     ir_expression *const r0955 = equal(body.constant(2097151u), r093C);
                     ir_expression *const r0956 = equal(body.constant(4294967295u), r093D);
                     body.emit(assign(r0952, logic_and(r0955, r0956), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0953->else_instructions;

                     body.emit(assign(r0952, body.constant(false), 0x01));


                  body.instructions = f0953_parent_instructions;
                  body.emit(f0953);

                  /* END IF */

                  ir_expression *const r0957 = nequal(r094A, body.constant(0u));
                  body.emit(assign(r094F, logic_and(r0952, r0957), 0x01));


               body.instructions = f0950_parent_instructions;
               body.emit(f0950);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0958 = new(mem_ctx) ir_if(operand(r094F).val);
               exec_list *const f0958_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0958->then_instructions;

                  ir_variable *const r0959 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0959);
                  ir_expression *const r095A = lshift(r0824, body.constant(int(31)));
                  body.emit(assign(r0959, add(r095A, body.constant(2146435072u)), 0x01));

                  body.emit(assign(r0959, body.constant(0u), 0x02));

                  body.emit(assign(r0949, r0959, 0x03));

                  body.emit(assign(r0948, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0958->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r095C = less(r082D, body.constant(0u));
                  ir_if *f095B = new(mem_ctx) ir_if(operand(r095C).val);
                  exec_list *const f095B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f095B->then_instructions;

                     ir_variable *const r095D = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r095D, r082E, 0x01));

                     ir_variable *const r095E = body.make_temp(glsl_type::int_type, "count");
                     ir_expression *const r095F = neg(r082D);
                     body.emit(assign(r095E, expr(ir_unop_u2i, r095F), 0x01));

                     ir_variable *const r0960 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0960);
                     ir_variable *const r0961 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0961);
                     ir_variable *const r0962 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0962);
                     ir_variable *const r0963 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0964 = neg(r095E);
                     body.emit(assign(r0963, bit_and(r0964, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0966 = equal(r095E, body.constant(int(0)));
                     ir_if *f0965 = new(mem_ctx) ir_if(operand(r0966).val);
                     exec_list *const f0965_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0965->then_instructions;

                        body.emit(assign(r0960, r082E, 0x01));

                        body.emit(assign(r0961, r093D, 0x01));

                        body.emit(assign(r0962, r093C, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0965->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0968 = less(r095E, body.constant(int(32)));
                        ir_if *f0967 = new(mem_ctx) ir_if(operand(r0968).val);
                        exec_list *const f0967_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0967->then_instructions;

                           body.emit(assign(r0960, lshift(r093D, r0963), 0x01));

                           ir_expression *const r0969 = lshift(r093C, r0963);
                           ir_expression *const r096A = rshift(r093D, r095E);
                           body.emit(assign(r0961, bit_or(r0969, r096A), 0x01));

                           body.emit(assign(r0962, rshift(r093C, r095E), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0967->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r096C = equal(r095E, body.constant(int(32)));
                           ir_if *f096B = new(mem_ctx) ir_if(operand(r096C).val);
                           exec_list *const f096B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f096B->then_instructions;

                              body.emit(assign(r0960, r093D, 0x01));

                              body.emit(assign(r0961, r093C, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f096B->else_instructions;

                              body.emit(assign(r095D, bit_or(r082E, r093D), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r096E = less(r095E, body.constant(int(64)));
                              ir_if *f096D = new(mem_ctx) ir_if(operand(r096E).val);
                              exec_list *const f096D_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f096D->then_instructions;

                                 body.emit(assign(r0960, lshift(r093C, r0963), 0x01));

                                 ir_expression *const r096F = bit_and(r095E, body.constant(int(31)));
                                 body.emit(assign(r0961, rshift(r093C, r096F), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f096D->else_instructions;

                                 ir_variable *const r0970 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0972 = equal(r095E, body.constant(int(64)));
                                 ir_if *f0971 = new(mem_ctx) ir_if(operand(r0972).val);
                                 exec_list *const f0971_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0971->then_instructions;

                                    body.emit(assign(r0970, r093C, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0971->else_instructions;

                                    ir_expression *const r0973 = nequal(r093C, body.constant(0u));
                                    ir_expression *const r0974 = expr(ir_unop_b2i, r0973);
                                    body.emit(assign(r0970, expr(ir_unop_i2u, r0974), 0x01));


                                 body.instructions = f0971_parent_instructions;
                                 body.emit(f0971);

                                 /* END IF */

                                 body.emit(assign(r0960, r0970, 0x01));

                                 body.emit(assign(r0961, body.constant(0u), 0x01));


                              body.instructions = f096D_parent_instructions;
                              body.emit(f096D);

                              /* END IF */


                           body.instructions = f096B_parent_instructions;
                           body.emit(f096B);

                           /* END IF */

                           body.emit(assign(r0962, body.constant(0u), 0x01));


                        body.instructions = f0967_parent_instructions;
                        body.emit(f0967);

                        /* END IF */

                        ir_expression *const r0975 = nequal(r095D, body.constant(0u));
                        ir_expression *const r0976 = expr(ir_unop_b2i, r0975);
                        ir_expression *const r0977 = expr(ir_unop_i2u, r0976);
                        body.emit(assign(r0960, bit_or(r0960, r0977), 0x01));


                     body.instructions = f0965_parent_instructions;
                     body.emit(f0965);

                     /* END IF */

                     body.emit(assign(r0945, r0962, 0x01));

                     body.emit(assign(r0946, r0961, 0x01));

                     body.emit(assign(r0947, r0960, 0x01));

                     body.emit(assign(r0944, body.constant(0u), 0x01));

                     ir_expression *const r0978 = less(r0960, body.constant(0u));
                     ir_expression *const r0979 = expr(ir_unop_b2i, r0978);
                     body.emit(assign(r094A, expr(ir_unop_i2u, r0979), 0x01));


                  body.instructions = f095B_parent_instructions;
                  body.emit(f095B);

                  /* END IF */


               body.instructions = f0958_parent_instructions;
               body.emit(f0958);

               /* END IF */


            body.instructions = f094D_parent_instructions;
            body.emit(f094D);

            /* END IF */

            /* IF CONDITION */
            ir_if *f097A = new(mem_ctx) ir_if(operand(r0948).val);
            exec_list *const f097A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f097A->then_instructions;

               /* IF CONDITION */
               ir_expression *const r097C = nequal(r094A, body.constant(0u));
               ir_if *f097B = new(mem_ctx) ir_if(operand(r097C).val);
               exec_list *const f097B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f097B->then_instructions;

                  ir_variable *const r097D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r097D, add(r0946, body.constant(1u)), 0x01));

                  ir_expression *const r097E = less(r097D, r0946);
                  ir_expression *const r097F = expr(ir_unop_b2i, r097E);
                  ir_expression *const r0980 = expr(ir_unop_i2u, r097F);
                  body.emit(assign(r0945, add(r0945, r0980), 0x01));

                  ir_expression *const r0981 = neg(r0947);
                  ir_expression *const r0982 = equal(r0947, r0981);
                  ir_expression *const r0983 = expr(ir_unop_b2i, r0982);
                  ir_expression *const r0984 = expr(ir_unop_i2u, r0983);
                  ir_expression *const r0985 = bit_and(r0984, body.constant(1u));
                  ir_expression *const r0986 = expr(ir_unop_bit_not, r0985);
                  body.emit(assign(r0946, bit_and(r097D, r0986), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f097B->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0988 = bit_or(r0945, r0946);
                  ir_expression *const r0989 = equal(r0988, body.constant(0u));
                  ir_if *f0987 = new(mem_ctx) ir_if(operand(r0989).val);
                  exec_list *const f0987_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0987->then_instructions;

                     body.emit(assign(r0944, body.constant(0u), 0x01));


                  body.instructions = f0987_parent_instructions;
                  body.emit(f0987);

                  /* END IF */


               body.instructions = f097B_parent_instructions;
               body.emit(f097B);

               /* END IF */

               ir_variable *const r098A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r098A);
               ir_expression *const r098B = lshift(r0824, body.constant(int(31)));
               ir_expression *const r098C = lshift(r0944, body.constant(int(20)));
               ir_expression *const r098D = add(r098B, r098C);
               body.emit(assign(r098A, add(r098D, r0945), 0x01));

               body.emit(assign(r098A, r0946, 0x02));

               body.emit(assign(r0949, r098A, 0x03));

               body.emit(assign(r0948, body.constant(false), 0x01));


            body.instructions = f097A_parent_instructions;
            body.emit(f097A);

            /* END IF */

            body.emit(assign(r0829, r0949, 0x03));

            body.emit(assign(r0828, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0942->else_instructions;

            body.emit(assign(r082D, add(r082D, body.constant(1u)), 0x01));

            ir_variable *const r098E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r098E);
            ir_variable *const r098F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r098F);
            ir_variable *const r0990 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0990);
            body.emit(assign(r098E, lshift(r093D, body.constant(int(31))), 0x01));

            ir_expression *const r0991 = lshift(r093C, body.constant(int(31)));
            ir_expression *const r0992 = rshift(r093D, body.constant(int(1)));
            body.emit(assign(r098F, bit_or(r0991, r0992), 0x01));

            body.emit(assign(r0990, rshift(r093C, body.constant(int(1))), 0x01));

            ir_expression *const r0993 = nequal(r082E, body.constant(0u));
            ir_expression *const r0994 = expr(ir_unop_b2i, r0993);
            ir_expression *const r0995 = expr(ir_unop_i2u, r0994);
            body.emit(assign(r098E, bit_or(r098E, r0995), 0x01));

            body.emit(assign(r082F, r0990, 0x01));

            body.emit(assign(r082E, r098E, 0x01));

            ir_variable *const r0996 = body.make_temp(glsl_type::uint_type, "zExp");
            body.emit(assign(r0996, r082D, 0x01));

            ir_variable *const r0997 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0997, r0990, 0x01));

            ir_variable *const r0998 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0998, r098F, 0x01));

            ir_variable *const r0999 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0999, r098E, 0x01));

            ir_variable *const r099A = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r099A, body.constant(true), 0x01));

            ir_variable *const r099B = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r099C = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
            body.emit(r099C);
            ir_expression *const r099D = less(r098E, body.constant(0u));
            ir_expression *const r099E = expr(ir_unop_b2i, r099D);
            body.emit(assign(r099C, expr(ir_unop_i2u, r099E), 0x01));

            /* IF CONDITION */
            ir_expression *const r09A0 = lequal(body.constant(2045u), r082D);
            ir_if *f099F = new(mem_ctx) ir_if(operand(r09A0).val);
            exec_list *const f099F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f099F->then_instructions;

               ir_variable *const r09A1 = body.make_temp(glsl_type::bool_type, "or_tmp");
               /* IF CONDITION */
               ir_expression *const r09A3 = less(body.constant(2045u), r082D);
               ir_if *f09A2 = new(mem_ctx) ir_if(operand(r09A3).val);
               exec_list *const f09A2_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09A2->then_instructions;

                  body.emit(assign(r09A1, body.constant(true), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f09A2->else_instructions;

                  ir_variable *const r09A4 = body.make_temp(glsl_type::bool_type, "and_tmp");
                  /* IF CONDITION */
                  ir_expression *const r09A6 = equal(r082D, body.constant(2045u));
                  ir_if *f09A5 = new(mem_ctx) ir_if(operand(r09A6).val);
                  exec_list *const f09A5_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09A5->then_instructions;

                     ir_expression *const r09A7 = equal(body.constant(2097151u), r0990);
                     ir_expression *const r09A8 = equal(body.constant(4294967295u), r098F);
                     body.emit(assign(r09A4, logic_and(r09A7, r09A8), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09A5->else_instructions;

                     body.emit(assign(r09A4, body.constant(false), 0x01));


                  body.instructions = f09A5_parent_instructions;
                  body.emit(f09A5);

                  /* END IF */

                  ir_expression *const r09A9 = nequal(r099C, body.constant(0u));
                  body.emit(assign(r09A1, logic_and(r09A4, r09A9), 0x01));


               body.instructions = f09A2_parent_instructions;
               body.emit(f09A2);

               /* END IF */

               /* IF CONDITION */
               ir_if *f09AA = new(mem_ctx) ir_if(operand(r09A1).val);
               exec_list *const f09AA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09AA->then_instructions;

                  ir_variable *const r09AB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r09AB);
                  ir_expression *const r09AC = lshift(r0824, body.constant(int(31)));
                  body.emit(assign(r09AB, add(r09AC, body.constant(2146435072u)), 0x01));

                  body.emit(assign(r09AB, body.constant(0u), 0x02));

                  body.emit(assign(r099B, r09AB, 0x03));

                  body.emit(assign(r099A, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f09AA->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r09AE = less(r082D, body.constant(0u));
                  ir_if *f09AD = new(mem_ctx) ir_if(operand(r09AE).val);
                  exec_list *const f09AD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09AD->then_instructions;

                     ir_variable *const r09AF = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r09AF, r098E, 0x01));

                     ir_variable *const r09B0 = body.make_temp(glsl_type::int_type, "count");
                     ir_expression *const r09B1 = neg(r082D);
                     body.emit(assign(r09B0, expr(ir_unop_u2i, r09B1), 0x01));

                     ir_variable *const r09B2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r09B2);
                     ir_variable *const r09B3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r09B3);
                     ir_variable *const r09B4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r09B4);
                     ir_variable *const r09B5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r09B6 = neg(r09B0);
                     body.emit(assign(r09B5, bit_and(r09B6, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r09B8 = equal(r09B0, body.constant(int(0)));
                     ir_if *f09B7 = new(mem_ctx) ir_if(operand(r09B8).val);
                     exec_list *const f09B7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09B7->then_instructions;

                        body.emit(assign(r09B2, r098E, 0x01));

                        body.emit(assign(r09B3, r098F, 0x01));

                        body.emit(assign(r09B4, r0990, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f09B7->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r09BA = less(r09B0, body.constant(int(32)));
                        ir_if *f09B9 = new(mem_ctx) ir_if(operand(r09BA).val);
                        exec_list *const f09B9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f09B9->then_instructions;

                           body.emit(assign(r09B2, lshift(r098F, r09B5), 0x01));

                           ir_expression *const r09BB = lshift(r0990, r09B5);
                           ir_expression *const r09BC = rshift(r098F, r09B0);
                           body.emit(assign(r09B3, bit_or(r09BB, r09BC), 0x01));

                           body.emit(assign(r09B4, rshift(r0990, r09B0), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f09B9->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r09BE = equal(r09B0, body.constant(int(32)));
                           ir_if *f09BD = new(mem_ctx) ir_if(operand(r09BE).val);
                           exec_list *const f09BD_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f09BD->then_instructions;

                              body.emit(assign(r09B2, r098F, 0x01));

                              body.emit(assign(r09B3, r0990, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f09BD->else_instructions;

                              body.emit(assign(r09AF, bit_or(r098E, r098F), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r09C0 = less(r09B0, body.constant(int(64)));
                              ir_if *f09BF = new(mem_ctx) ir_if(operand(r09C0).val);
                              exec_list *const f09BF_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f09BF->then_instructions;

                                 body.emit(assign(r09B2, lshift(r0990, r09B5), 0x01));

                                 ir_expression *const r09C1 = bit_and(r09B0, body.constant(int(31)));
                                 body.emit(assign(r09B3, rshift(r0990, r09C1), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f09BF->else_instructions;

                                 ir_variable *const r09C2 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r09C4 = equal(r09B0, body.constant(int(64)));
                                 ir_if *f09C3 = new(mem_ctx) ir_if(operand(r09C4).val);
                                 exec_list *const f09C3_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f09C3->then_instructions;

                                    body.emit(assign(r09C2, r0990, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f09C3->else_instructions;

                                    ir_expression *const r09C5 = nequal(r0990, body.constant(0u));
                                    ir_expression *const r09C6 = expr(ir_unop_b2i, r09C5);
                                    body.emit(assign(r09C2, expr(ir_unop_i2u, r09C6), 0x01));


                                 body.instructions = f09C3_parent_instructions;
                                 body.emit(f09C3);

                                 /* END IF */

                                 body.emit(assign(r09B2, r09C2, 0x01));

                                 body.emit(assign(r09B3, body.constant(0u), 0x01));


                              body.instructions = f09BF_parent_instructions;
                              body.emit(f09BF);

                              /* END IF */


                           body.instructions = f09BD_parent_instructions;
                           body.emit(f09BD);

                           /* END IF */

                           body.emit(assign(r09B4, body.constant(0u), 0x01));


                        body.instructions = f09B9_parent_instructions;
                        body.emit(f09B9);

                        /* END IF */

                        ir_expression *const r09C7 = nequal(r09AF, body.constant(0u));
                        ir_expression *const r09C8 = expr(ir_unop_b2i, r09C7);
                        ir_expression *const r09C9 = expr(ir_unop_i2u, r09C8);
                        body.emit(assign(r09B2, bit_or(r09B2, r09C9), 0x01));


                     body.instructions = f09B7_parent_instructions;
                     body.emit(f09B7);

                     /* END IF */

                     body.emit(assign(r0997, r09B4, 0x01));

                     body.emit(assign(r0998, r09B3, 0x01));

                     body.emit(assign(r0999, r09B2, 0x01));

                     body.emit(assign(r0996, body.constant(0u), 0x01));

                     ir_expression *const r09CA = less(r09B2, body.constant(0u));
                     ir_expression *const r09CB = expr(ir_unop_b2i, r09CA);
                     body.emit(assign(r099C, expr(ir_unop_i2u, r09CB), 0x01));


                  body.instructions = f09AD_parent_instructions;
                  body.emit(f09AD);

                  /* END IF */


               body.instructions = f09AA_parent_instructions;
               body.emit(f09AA);

               /* END IF */


            body.instructions = f099F_parent_instructions;
            body.emit(f099F);

            /* END IF */

            /* IF CONDITION */
            ir_if *f09CC = new(mem_ctx) ir_if(operand(r099A).val);
            exec_list *const f09CC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f09CC->then_instructions;

               /* IF CONDITION */
               ir_expression *const r09CE = nequal(r099C, body.constant(0u));
               ir_if *f09CD = new(mem_ctx) ir_if(operand(r09CE).val);
               exec_list *const f09CD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09CD->then_instructions;

                  ir_variable *const r09CF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r09CF, add(r0998, body.constant(1u)), 0x01));

                  ir_expression *const r09D0 = less(r09CF, r0998);
                  ir_expression *const r09D1 = expr(ir_unop_b2i, r09D0);
                  ir_expression *const r09D2 = expr(ir_unop_i2u, r09D1);
                  body.emit(assign(r0997, add(r0997, r09D2), 0x01));

                  ir_expression *const r09D3 = neg(r0999);
                  ir_expression *const r09D4 = equal(r0999, r09D3);
                  ir_expression *const r09D5 = expr(ir_unop_b2i, r09D4);
                  ir_expression *const r09D6 = expr(ir_unop_i2u, r09D5);
                  ir_expression *const r09D7 = bit_and(r09D6, body.constant(1u));
                  ir_expression *const r09D8 = expr(ir_unop_bit_not, r09D7);
                  body.emit(assign(r0998, bit_and(r09CF, r09D8), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f09CD->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r09DA = bit_or(r0997, r0998);
                  ir_expression *const r09DB = equal(r09DA, body.constant(0u));
                  ir_if *f09D9 = new(mem_ctx) ir_if(operand(r09DB).val);
                  exec_list *const f09D9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09D9->then_instructions;

                     body.emit(assign(r0996, body.constant(0u), 0x01));


                  body.instructions = f09D9_parent_instructions;
                  body.emit(f09D9);

                  /* END IF */


               body.instructions = f09CD_parent_instructions;
               body.emit(f09CD);

               /* END IF */

               ir_variable *const r09DC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r09DC);
               ir_expression *const r09DD = lshift(r0824, body.constant(int(31)));
               ir_expression *const r09DE = lshift(r0996, body.constant(int(20)));
               ir_expression *const r09DF = add(r09DD, r09DE);
               body.emit(assign(r09DC, add(r09DF, r0997), 0x01));

               body.emit(assign(r09DC, r0998, 0x02));

               body.emit(assign(r099B, r09DC, 0x03));

               body.emit(assign(r099A, body.constant(false), 0x01));


            body.instructions = f09CC_parent_instructions;
            body.emit(f09CC);

            /* END IF */

            body.emit(assign(r0829, r099B, 0x03));

            body.emit(assign(r0828, body.constant(false), 0x01));


         body.instructions = f0942_parent_instructions;
         body.emit(f0942);

         /* END IF */


      body.instructions = f093B_parent_instructions;
      body.emit(f093B);

      /* END IF */

      body.emit(assign(r0823, r0829, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0826->else_instructions;

      ir_variable *const r09E0 = body.make_temp(glsl_type::uint_type, "zSign");
      body.emit(assign(r09E0, r0824, 0x01));

      ir_variable *const r09E1 = body.make_temp(glsl_type::uvec2_type, "return_value");
      ir_variable *const r09E2 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r09E2);
      ir_variable *const r09E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bExp", ir_var_auto);
      body.emit(r09E3);
      ir_variable *const r09E4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "bFrac", ir_var_auto);
      body.emit(r09E4);
      ir_variable *const r09E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aExp", ir_var_auto);
      body.emit(r09E5);
      ir_variable *const r09E6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "aFrac", ir_var_auto);
      body.emit(r09E6);
      ir_variable *const r09E7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zExp", ir_var_auto);
      body.emit(r09E7);
      ir_variable *const r09E8 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
      body.emit(assign(r09E8, bit_and(swizzle_x(r0821), body.constant(1048575u)), 0x01));

      body.emit(assign(r09E8, swizzle_y(r0821), 0x02));

      ir_variable *const r09E9 = body.make_temp(glsl_type::uint_type, "extractFloat64Exp_retval");
      ir_expression *const r09EA = rshift(swizzle_x(r0821), body.constant(int(20)));
      body.emit(assign(r09E9, bit_and(r09EA, body.constant(2047u)), 0x01));

      body.emit(assign(r09E5, r09E9, 0x01));

      ir_variable *const r09EB = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
      body.emit(assign(r09EB, bit_and(swizzle_x(r0822), body.constant(1048575u)), 0x01));

      body.emit(assign(r09EB, swizzle_y(r0822), 0x02));

      ir_variable *const r09EC = body.make_temp(glsl_type::uint_type, "extractFloat64Exp_retval");
      ir_expression *const r09ED = rshift(swizzle_x(r0822), body.constant(int(20)));
      body.emit(assign(r09EC, bit_and(r09ED, body.constant(2047u)), 0x01));

      body.emit(assign(r09E3, r09EC, 0x01));

      ir_expression *const r09EE = expr(ir_unop_u2i, r09E9);
      ir_expression *const r09EF = expr(ir_unop_u2i, r09EC);
      body.emit(assign(r09E2, sub(r09EE, r09EF), 0x01));

      ir_variable *const r09F0 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r09F0, lshift(swizzle_y(r0821), body.constant(int(10))), 0x01));

      ir_variable *const r09F1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r09F2 = lshift(swizzle_x(r09E8), body.constant(int(10)));
      ir_expression *const r09F3 = rshift(swizzle_y(r0821), body.constant(int(22)));
      body.emit(assign(r09F1, bit_or(r09F2, r09F3), 0x01));

      body.emit(assign(r09E6, r09F1, 0x01));

      body.emit(assign(r09E6, r09F0, 0x02));

      ir_variable *const r09F4 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r09F4, lshift(swizzle_y(r0822), body.constant(int(10))), 0x01));

      ir_variable *const r09F5 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r09F6 = lshift(swizzle_x(r09EB), body.constant(int(10)));
      ir_expression *const r09F7 = rshift(swizzle_y(r0822), body.constant(int(22)));
      body.emit(assign(r09F5, bit_or(r09F6, r09F7), 0x01));

      body.emit(assign(r09E4, r09F5, 0x01));

      body.emit(assign(r09E4, r09F4, 0x02));

      /* IF CONDITION */
      ir_expression *const r09F9 = less(body.constant(int(0)), r09E2);
      ir_if *f09F8 = new(mem_ctx) ir_if(operand(r09F9).val);
      exec_list *const f09F8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09F8->then_instructions;

         /* IF CONDITION */
         ir_expression *const r09FB = equal(r09E9, body.constant(2047u));
         ir_if *f09FA = new(mem_ctx) ir_if(operand(r09FB).val);
         exec_list *const f09FA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09FA->then_instructions;

            /* IF CONDITION */
            ir_expression *const r09FD = bit_or(r09F1, r09F0);
            ir_expression *const r09FE = nequal(r09FD, body.constant(0u));
            ir_if *f09FC = new(mem_ctx) ir_if(operand(r09FE).val);
            exec_list *const f09FC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f09FC->then_instructions;

               ir_variable *const r09FF = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r09FF, swizzle_x(r0821), 0x01));

               ir_variable *const r0A00 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0A00, swizzle_x(r0822), 0x01));

               ir_variable *const r0A01 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0A02 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
               ir_expression *const r0A03 = rshift(swizzle_y(r0821), body.constant(int(19)));
               ir_expression *const r0A04 = bit_and(r0A03, body.constant(4095u));
               ir_expression *const r0A05 = equal(r0A04, body.constant(4094u));
               ir_expression *const r0A06 = nequal(swizzle_x(r0821), body.constant(0u));
               ir_expression *const r0A07 = bit_and(swizzle_y(r0821), body.constant(524287u));
               ir_expression *const r0A08 = nequal(r0A07, body.constant(0u));
               ir_expression *const r0A09 = logic_or(r0A06, r0A08);
               body.emit(assign(r0A02, logic_and(r0A05, r0A09), 0x01));

               ir_variable *const r0A0A = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r0A0B = lshift(swizzle_y(r0822), body.constant(int(1)));
               ir_expression *const r0A0C = lequal(body.constant(4292870144u), r0A0B);
               ir_expression *const r0A0D = nequal(swizzle_x(r0822), body.constant(0u));
               ir_expression *const r0A0E = bit_and(swizzle_y(r0822), body.constant(1048575u));
               ir_expression *const r0A0F = nequal(r0A0E, body.constant(0u));
               ir_expression *const r0A10 = logic_or(r0A0D, r0A0F);
               body.emit(assign(r0A0A, logic_and(r0A0C, r0A10), 0x01));

               body.emit(assign(r09FF, bit_or(swizzle_y(r0821), body.constant(524288u)), 0x02));

               body.emit(assign(r0A00, bit_or(swizzle_y(r0822), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r0A12 = lshift(swizzle_y(r0821), body.constant(int(1)));
               ir_expression *const r0A13 = lequal(body.constant(4292870144u), r0A12);
               ir_expression *const r0A14 = nequal(swizzle_x(r0821), body.constant(0u));
               ir_expression *const r0A15 = bit_and(swizzle_y(r0821), body.constant(1048575u));
               ir_expression *const r0A16 = nequal(r0A15, body.constant(0u));
               ir_expression *const r0A17 = logic_or(r0A14, r0A16);
               ir_expression *const r0A18 = logic_and(r0A13, r0A17);
               ir_if *f0A11 = new(mem_ctx) ir_if(operand(r0A18).val);
               exec_list *const f0A11_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A11->then_instructions;

                  ir_variable *const r0A19 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r0A1B = logic_and(r0A02, r0A0A);
                  ir_if *f0A1A = new(mem_ctx) ir_if(operand(r0A1B).val);
                  exec_list *const f0A1A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A1A->then_instructions;

                     body.emit(assign(r0A19, r0A00, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A1A->else_instructions;

                     body.emit(assign(r0A19, r09FF, 0x03));


                  body.instructions = f0A1A_parent_instructions;
                  body.emit(f0A1A);

                  /* END IF */

                  body.emit(assign(r0A01, r0A19, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A11->else_instructions;

                  body.emit(assign(r0A01, r0A00, 0x03));


               body.instructions = f0A11_parent_instructions;
               body.emit(f0A11);

               /* END IF */

               body.emit(assign(r09E1, r0A01, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f09FC->else_instructions;

               body.emit(assign(r09E1, r0821, 0x03));


            body.instructions = f09FC_parent_instructions;
            body.emit(f09FC);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09FA->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0A1D = equal(r09EC, body.constant(0u));
            ir_if *f0A1C = new(mem_ctx) ir_if(operand(r0A1D).val);
            exec_list *const f0A1C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A1C->then_instructions;

               body.emit(assign(r09E2, add(r09E2, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A1C->else_instructions;

               body.emit(assign(r09E4, bit_or(r09F5, body.constant(1073741824u)), 0x01));


            body.instructions = f0A1C_parent_instructions;
            body.emit(f0A1C);

            /* END IF */

            ir_variable *const r0A1E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0A1E);
            ir_variable *const r0A1F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0A1F);
            ir_variable *const r0A20 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0A21 = neg(r09E2);
            body.emit(assign(r0A20, bit_and(r0A21, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A23 = equal(r09E2, body.constant(int(0)));
            ir_if *f0A22 = new(mem_ctx) ir_if(operand(r0A23).val);
            exec_list *const f0A22_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A22->then_instructions;

               body.emit(assign(r0A1E, swizzle_y(r09E4), 0x01));

               body.emit(assign(r0A1F, swizzle_x(r09E4), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A22->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0A25 = less(r09E2, body.constant(int(32)));
               ir_if *f0A24 = new(mem_ctx) ir_if(operand(r0A25).val);
               exec_list *const f0A24_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A24->then_instructions;

                  ir_expression *const r0A26 = lshift(swizzle_x(r09E4), r0A20);
                  ir_expression *const r0A27 = rshift(r09F4, r09E2);
                  ir_expression *const r0A28 = bit_or(r0A26, r0A27);
                  ir_expression *const r0A29 = lshift(r09F4, r0A20);
                  ir_expression *const r0A2A = nequal(r0A29, body.constant(0u));
                  ir_expression *const r0A2B = expr(ir_unop_b2i, r0A2A);
                  ir_expression *const r0A2C = expr(ir_unop_i2u, r0A2B);
                  body.emit(assign(r0A1E, bit_or(r0A28, r0A2C), 0x01));

                  body.emit(assign(r0A1F, rshift(swizzle_x(r09E4), r09E2), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A24->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A2E = equal(r09E2, body.constant(int(32)));
                  ir_if *f0A2D = new(mem_ctx) ir_if(operand(r0A2E).val);
                  exec_list *const f0A2D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A2D->then_instructions;

                     ir_expression *const r0A2F = nequal(r09F4, body.constant(0u));
                     ir_expression *const r0A30 = expr(ir_unop_b2i, r0A2F);
                     ir_expression *const r0A31 = expr(ir_unop_i2u, r0A30);
                     body.emit(assign(r0A1E, bit_or(swizzle_x(r09E4), r0A31), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A2D->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0A33 = less(r09E2, body.constant(int(64)));
                     ir_if *f0A32 = new(mem_ctx) ir_if(operand(r0A33).val);
                     exec_list *const f0A32_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0A32->then_instructions;

                        ir_expression *const r0A34 = bit_and(r09E2, body.constant(int(31)));
                        ir_expression *const r0A35 = rshift(swizzle_x(r09E4), r0A34);
                        ir_expression *const r0A36 = lshift(swizzle_x(r09E4), r0A20);
                        ir_expression *const r0A37 = bit_or(r0A36, r09F4);
                        ir_expression *const r0A38 = nequal(r0A37, body.constant(0u));
                        ir_expression *const r0A39 = expr(ir_unop_b2i, r0A38);
                        ir_expression *const r0A3A = expr(ir_unop_i2u, r0A39);
                        body.emit(assign(r0A1E, bit_or(r0A35, r0A3A), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0A32->else_instructions;

                        ir_expression *const r0A3B = bit_or(swizzle_x(r09E4), r09F4);
                        ir_expression *const r0A3C = nequal(r0A3B, body.constant(0u));
                        ir_expression *const r0A3D = expr(ir_unop_b2i, r0A3C);
                        body.emit(assign(r0A1E, expr(ir_unop_i2u, r0A3D), 0x01));


                     body.instructions = f0A32_parent_instructions;
                     body.emit(f0A32);

                     /* END IF */


                  body.instructions = f0A2D_parent_instructions;
                  body.emit(f0A2D);

                  /* END IF */

                  body.emit(assign(r0A1F, body.constant(0u), 0x01));


               body.instructions = f0A24_parent_instructions;
               body.emit(f0A24);

               /* END IF */


            body.instructions = f0A22_parent_instructions;
            body.emit(f0A22);

            /* END IF */

            body.emit(assign(r09E4, r0A1F, 0x01));

            body.emit(assign(r09E4, r0A1E, 0x02));

            body.emit(assign(r09E6, bit_or(r09F1, body.constant(1073741824u)), 0x01));

            ir_variable *const r0A3E = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r0A3F = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r0A3F, sub(r09F0, r0A1E), 0x01));

            ir_expression *const r0A40 = sub(swizzle_x(r09E6), r0A1F);
            ir_expression *const r0A41 = less(r09F0, r0A1E);
            ir_expression *const r0A42 = expr(ir_unop_b2i, r0A41);
            ir_expression *const r0A43 = expr(ir_unop_i2u, r0A42);
            body.emit(assign(r0A3E, sub(r0A40, r0A43), 0x01));

            body.emit(assign(r09E7, add(r09E9, body.constant(4294967295u)), 0x01));

            ir_variable *const r0A44 = body.make_temp(glsl_type::uint_type, "zExp");
            body.emit(assign(r0A44, add(r09E7, body.constant(4294967286u)), 0x01));

            ir_variable *const r0A45 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0A45, r0A3E, 0x01));

            ir_variable *const r0A46 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0A46, r0A3F, 0x01));

            ir_variable *const r0A47 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r0A47);
            ir_variable *const r0A48 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0A48);
            /* IF CONDITION */
            ir_expression *const r0A4A = equal(r0A3E, body.constant(0u));
            ir_if *f0A49 = new(mem_ctx) ir_if(operand(r0A4A).val);
            exec_list *const f0A49_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A49->then_instructions;

               body.emit(assign(r0A45, r0A3F, 0x01));

               body.emit(assign(r0A46, body.constant(0u), 0x01));

               body.emit(assign(r0A44, add(r0A44, body.constant(4294967264u)), 0x01));


            body.instructions = f0A49_parent_instructions;
            body.emit(f0A49);

            /* END IF */

            ir_variable *const r0A4B = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0A4B, r0A45, 0x01));

            ir_variable *const r0A4C = body.make_temp(glsl_type::uint_type, "return_value");
            ir_variable *const r0A4D = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
            body.emit(r0A4D);
            /* IF CONDITION */
            ir_expression *const r0A4F = equal(r0A45, body.constant(0u));
            ir_if *f0A4E = new(mem_ctx) ir_if(operand(r0A4F).val);
            exec_list *const f0A4E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A4E->then_instructions;

               body.emit(assign(r0A4C, body.constant(32u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A4E->else_instructions;

               body.emit(assign(r0A4D, body.constant(0u), 0x01));

               /* IF CONDITION */
               ir_expression *const r0A51 = bit_and(r0A45, body.constant(4294901760u));
               ir_expression *const r0A52 = equal(r0A51, body.constant(0u));
               ir_if *f0A50 = new(mem_ctx) ir_if(operand(r0A52).val);
               exec_list *const f0A50_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A50->then_instructions;

                  body.emit(assign(r0A4D, body.constant(16u), 0x01));

                  body.emit(assign(r0A4B, lshift(r0A45, body.constant(int(16))), 0x01));


               body.instructions = f0A50_parent_instructions;
               body.emit(f0A50);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0A54 = bit_and(r0A4B, body.constant(4278190080u));
               ir_expression *const r0A55 = equal(r0A54, body.constant(0u));
               ir_if *f0A53 = new(mem_ctx) ir_if(operand(r0A55).val);
               exec_list *const f0A53_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A53->then_instructions;

                  body.emit(assign(r0A4D, add(r0A4D, body.constant(8u)), 0x01));

                  body.emit(assign(r0A4B, lshift(r0A4B, body.constant(int(8))), 0x01));


               body.instructions = f0A53_parent_instructions;
               body.emit(f0A53);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0A57 = bit_and(r0A4B, body.constant(4026531840u));
               ir_expression *const r0A58 = equal(r0A57, body.constant(0u));
               ir_if *f0A56 = new(mem_ctx) ir_if(operand(r0A58).val);
               exec_list *const f0A56_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A56->then_instructions;

                  body.emit(assign(r0A4D, add(r0A4D, body.constant(4u)), 0x01));

                  body.emit(assign(r0A4B, lshift(r0A4B, body.constant(int(4))), 0x01));


               body.instructions = f0A56_parent_instructions;
               body.emit(f0A56);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0A5A = bit_and(r0A4B, body.constant(3221225472u));
               ir_expression *const r0A5B = equal(r0A5A, body.constant(0u));
               ir_if *f0A59 = new(mem_ctx) ir_if(operand(r0A5B).val);
               exec_list *const f0A59_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A59->then_instructions;

                  body.emit(assign(r0A4D, add(r0A4D, body.constant(2u)), 0x01));

                  body.emit(assign(r0A4B, lshift(r0A4B, body.constant(int(2))), 0x01));


               body.instructions = f0A59_parent_instructions;
               body.emit(f0A59);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0A5D = bit_and(r0A4B, body.constant(2147483648u));
               ir_expression *const r0A5E = equal(r0A5D, body.constant(0u));
               ir_if *f0A5C = new(mem_ctx) ir_if(operand(r0A5E).val);
               exec_list *const f0A5C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A5C->then_instructions;

                  body.emit(assign(r0A4D, add(r0A4D, body.constant(1u)), 0x01));


               body.instructions = f0A5C_parent_instructions;
               body.emit(f0A5C);

               /* END IF */

               body.emit(assign(r0A4C, r0A4D, 0x01));


            body.instructions = f0A4E_parent_instructions;
            body.emit(f0A4E);

            /* END IF */

            ir_expression *const r0A5F = expr(ir_unop_u2i, r0A4C);
            body.emit(assign(r0A48, add(r0A5F, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A61 = lequal(body.constant(int(0)), r0A48);
            ir_if *f0A60 = new(mem_ctx) ir_if(operand(r0A61).val);
            exec_list *const f0A60_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A60->then_instructions;

               body.emit(assign(r0A47, body.constant(0u), 0x01));

               ir_variable *const r0A62 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0A62, lshift(r0A46, r0A48), 0x01));

               ir_variable *const r0A63 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0A65 = equal(r0A48, body.constant(int(0)));
               ir_if *f0A64 = new(mem_ctx) ir_if(operand(r0A65).val);
               exec_list *const f0A64_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A64->then_instructions;

                  body.emit(assign(r0A63, r0A45, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A64->else_instructions;

                  ir_expression *const r0A66 = lshift(r0A45, r0A48);
                  ir_expression *const r0A67 = neg(r0A48);
                  ir_expression *const r0A68 = bit_and(r0A67, body.constant(int(31)));
                  ir_expression *const r0A69 = rshift(r0A46, r0A68);
                  body.emit(assign(r0A63, bit_or(r0A66, r0A69), 0x01));


               body.instructions = f0A64_parent_instructions;
               body.emit(f0A64);

               /* END IF */

               body.emit(assign(r0A45, r0A63, 0x01));

               body.emit(assign(r0A46, r0A62, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A60->else_instructions;

               ir_variable *const r0A6A = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0A6A, body.constant(0u), 0x01));

               ir_variable *const r0A6B = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0A6B, neg(r0A48), 0x01));

               ir_variable *const r0A6C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0A6C);
               ir_variable *const r0A6D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0A6D);
               ir_variable *const r0A6E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0A6E);
               ir_variable *const r0A6F = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0A70 = neg(r0A6B);
               body.emit(assign(r0A6F, bit_and(r0A70, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0A72 = equal(r0A6B, body.constant(int(0)));
               ir_if *f0A71 = new(mem_ctx) ir_if(operand(r0A72).val);
               exec_list *const f0A71_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A71->then_instructions;

                  body.emit(assign(r0A6C, r0A6A, 0x01));

                  body.emit(assign(r0A6D, r0A46, 0x01));

                  body.emit(assign(r0A6E, r0A45, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A71->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A74 = less(r0A6B, body.constant(int(32)));
                  ir_if *f0A73 = new(mem_ctx) ir_if(operand(r0A74).val);
                  exec_list *const f0A73_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A73->then_instructions;

                     body.emit(assign(r0A6C, lshift(r0A46, r0A6F), 0x01));

                     ir_expression *const r0A75 = lshift(r0A45, r0A6F);
                     ir_expression *const r0A76 = rshift(r0A46, r0A6B);
                     body.emit(assign(r0A6D, bit_or(r0A75, r0A76), 0x01));

                     body.emit(assign(r0A6E, rshift(r0A45, r0A6B), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A73->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0A78 = equal(r0A6B, body.constant(int(32)));
                     ir_if *f0A77 = new(mem_ctx) ir_if(operand(r0A78).val);
                     exec_list *const f0A77_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0A77->then_instructions;

                        body.emit(assign(r0A6C, r0A46, 0x01));

                        body.emit(assign(r0A6D, r0A45, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0A77->else_instructions;

                        body.emit(assign(r0A6A, bit_or(body.constant(0u), r0A46), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0A7A = less(r0A6B, body.constant(int(64)));
                        ir_if *f0A79 = new(mem_ctx) ir_if(operand(r0A7A).val);
                        exec_list *const f0A79_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0A79->then_instructions;

                           body.emit(assign(r0A6C, lshift(r0A45, r0A6F), 0x01));

                           ir_expression *const r0A7B = bit_and(r0A6B, body.constant(int(31)));
                           body.emit(assign(r0A6D, rshift(r0A45, r0A7B), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0A79->else_instructions;

                           ir_variable *const r0A7C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0A7E = equal(r0A6B, body.constant(int(64)));
                           ir_if *f0A7D = new(mem_ctx) ir_if(operand(r0A7E).val);
                           exec_list *const f0A7D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0A7D->then_instructions;

                              body.emit(assign(r0A7C, r0A45, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0A7D->else_instructions;

                              ir_expression *const r0A7F = nequal(r0A45, body.constant(0u));
                              ir_expression *const r0A80 = expr(ir_unop_b2i, r0A7F);
                              body.emit(assign(r0A7C, expr(ir_unop_i2u, r0A80), 0x01));


                           body.instructions = f0A7D_parent_instructions;
                           body.emit(f0A7D);

                           /* END IF */

                           body.emit(assign(r0A6C, r0A7C, 0x01));

                           body.emit(assign(r0A6D, body.constant(0u), 0x01));


                        body.instructions = f0A79_parent_instructions;
                        body.emit(f0A79);

                        /* END IF */


                     body.instructions = f0A77_parent_instructions;
                     body.emit(f0A77);

                     /* END IF */

                     body.emit(assign(r0A6E, body.constant(0u), 0x01));


                  body.instructions = f0A73_parent_instructions;
                  body.emit(f0A73);

                  /* END IF */

                  ir_expression *const r0A81 = nequal(r0A6A, body.constant(0u));
                  ir_expression *const r0A82 = expr(ir_unop_b2i, r0A81);
                  ir_expression *const r0A83 = expr(ir_unop_i2u, r0A82);
                  body.emit(assign(r0A6C, bit_or(r0A6C, r0A83), 0x01));


               body.instructions = f0A71_parent_instructions;
               body.emit(f0A71);

               /* END IF */

               body.emit(assign(r0A45, r0A6E, 0x01));

               body.emit(assign(r0A46, r0A6D, 0x01));

               body.emit(assign(r0A47, r0A6C, 0x01));


            body.instructions = f0A60_parent_instructions;
            body.emit(f0A60);

            /* END IF */

            ir_expression *const r0A84 = expr(ir_unop_i2u, r0A48);
            body.emit(assign(r0A44, sub(r0A44, r0A84), 0x01));

            ir_variable *const r0A85 = body.make_temp(glsl_type::uint_type, "zExp");
            body.emit(assign(r0A85, r0A44, 0x01));

            ir_variable *const r0A86 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0A86, r0A45, 0x01));

            ir_variable *const r0A87 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0A87, r0A46, 0x01));

            ir_variable *const r0A88 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0A88, r0A47, 0x01));

            ir_variable *const r0A89 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0A89, body.constant(true), 0x01));

            ir_variable *const r0A8A = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0A8B = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
            body.emit(r0A8B);
            ir_expression *const r0A8C = less(r0A47, body.constant(0u));
            ir_expression *const r0A8D = expr(ir_unop_b2i, r0A8C);
            body.emit(assign(r0A8B, expr(ir_unop_i2u, r0A8D), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A8F = lequal(body.constant(2045u), r0A44);
            ir_if *f0A8E = new(mem_ctx) ir_if(operand(r0A8F).val);
            exec_list *const f0A8E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A8E->then_instructions;

               ir_variable *const r0A90 = body.make_temp(glsl_type::bool_type, "or_tmp");
               /* IF CONDITION */
               ir_expression *const r0A92 = less(body.constant(2045u), r0A44);
               ir_if *f0A91 = new(mem_ctx) ir_if(operand(r0A92).val);
               exec_list *const f0A91_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A91->then_instructions;

                  body.emit(assign(r0A90, body.constant(true), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A91->else_instructions;

                  ir_variable *const r0A93 = body.make_temp(glsl_type::bool_type, "and_tmp");
                  /* IF CONDITION */
                  ir_expression *const r0A95 = equal(r0A44, body.constant(2045u));
                  ir_if *f0A94 = new(mem_ctx) ir_if(operand(r0A95).val);
                  exec_list *const f0A94_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A94->then_instructions;

                     ir_expression *const r0A96 = equal(body.constant(2097151u), r0A45);
                     ir_expression *const r0A97 = equal(body.constant(4294967295u), r0A46);
                     body.emit(assign(r0A93, logic_and(r0A96, r0A97), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A94->else_instructions;

                     body.emit(assign(r0A93, body.constant(false), 0x01));


                  body.instructions = f0A94_parent_instructions;
                  body.emit(f0A94);

                  /* END IF */

                  ir_expression *const r0A98 = nequal(r0A8B, body.constant(0u));
                  body.emit(assign(r0A90, logic_and(r0A93, r0A98), 0x01));


               body.instructions = f0A91_parent_instructions;
               body.emit(f0A91);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0A99 = new(mem_ctx) ir_if(operand(r0A90).val);
               exec_list *const f0A99_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A99->then_instructions;

                  ir_variable *const r0A9A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0A9A);
                  ir_expression *const r0A9B = lshift(r0824, body.constant(int(31)));
                  body.emit(assign(r0A9A, add(r0A9B, body.constant(2146435072u)), 0x01));

                  body.emit(assign(r0A9A, body.constant(0u), 0x02));

                  body.emit(assign(r0A8A, r0A9A, 0x03));

                  body.emit(assign(r0A89, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A99->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A9D = less(r0A44, body.constant(0u));
                  ir_if *f0A9C = new(mem_ctx) ir_if(operand(r0A9D).val);
                  exec_list *const f0A9C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A9C->then_instructions;

                     ir_variable *const r0A9E = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0A9E, r0A47, 0x01));

                     ir_variable *const r0A9F = body.make_temp(glsl_type::int_type, "count");
                     ir_expression *const r0AA0 = neg(r0A44);
                     body.emit(assign(r0A9F, expr(ir_unop_u2i, r0AA0), 0x01));

                     ir_variable *const r0AA1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0AA1);
                     ir_variable *const r0AA2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0AA2);
                     ir_variable *const r0AA3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0AA3);
                     ir_variable *const r0AA4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0AA5 = neg(r0A9F);
                     body.emit(assign(r0AA4, bit_and(r0AA5, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0AA7 = equal(r0A9F, body.constant(int(0)));
                     ir_if *f0AA6 = new(mem_ctx) ir_if(operand(r0AA7).val);
                     exec_list *const f0AA6_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0AA6->then_instructions;

                        body.emit(assign(r0AA1, r0A47, 0x01));

                        body.emit(assign(r0AA2, r0A46, 0x01));

                        body.emit(assign(r0AA3, r0A45, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0AA6->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0AA9 = less(r0A9F, body.constant(int(32)));
                        ir_if *f0AA8 = new(mem_ctx) ir_if(operand(r0AA9).val);
                        exec_list *const f0AA8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0AA8->then_instructions;

                           body.emit(assign(r0AA1, lshift(r0A46, r0AA4), 0x01));

                           ir_expression *const r0AAA = lshift(r0A45, r0AA4);
                           ir_expression *const r0AAB = rshift(r0A46, r0A9F);
                           body.emit(assign(r0AA2, bit_or(r0AAA, r0AAB), 0x01));

                           body.emit(assign(r0AA3, rshift(r0A45, r0A9F), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0AA8->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0AAD = equal(r0A9F, body.constant(int(32)));
                           ir_if *f0AAC = new(mem_ctx) ir_if(operand(r0AAD).val);
                           exec_list *const f0AAC_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0AAC->then_instructions;

                              body.emit(assign(r0AA1, r0A46, 0x01));

                              body.emit(assign(r0AA2, r0A45, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0AAC->else_instructions;

                              body.emit(assign(r0A9E, bit_or(r0A47, r0A46), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0AAF = less(r0A9F, body.constant(int(64)));
                              ir_if *f0AAE = new(mem_ctx) ir_if(operand(r0AAF).val);
                              exec_list *const f0AAE_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0AAE->then_instructions;

                                 body.emit(assign(r0AA1, lshift(r0A45, r0AA4), 0x01));

                                 ir_expression *const r0AB0 = bit_and(r0A9F, body.constant(int(31)));
                                 body.emit(assign(r0AA2, rshift(r0A45, r0AB0), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0AAE->else_instructions;

                                 ir_variable *const r0AB1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0AB3 = equal(r0A9F, body.constant(int(64)));
                                 ir_if *f0AB2 = new(mem_ctx) ir_if(operand(r0AB3).val);
                                 exec_list *const f0AB2_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0AB2->then_instructions;

                                    body.emit(assign(r0AB1, r0A45, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0AB2->else_instructions;

                                    ir_expression *const r0AB4 = nequal(r0A45, body.constant(0u));
                                    ir_expression *const r0AB5 = expr(ir_unop_b2i, r0AB4);
                                    body.emit(assign(r0AB1, expr(ir_unop_i2u, r0AB5), 0x01));


                                 body.instructions = f0AB2_parent_instructions;
                                 body.emit(f0AB2);

                                 /* END IF */

                                 body.emit(assign(r0AA1, r0AB1, 0x01));

                                 body.emit(assign(r0AA2, body.constant(0u), 0x01));


                              body.instructions = f0AAE_parent_instructions;
                              body.emit(f0AAE);

                              /* END IF */


                           body.instructions = f0AAC_parent_instructions;
                           body.emit(f0AAC);

                           /* END IF */

                           body.emit(assign(r0AA3, body.constant(0u), 0x01));


                        body.instructions = f0AA8_parent_instructions;
                        body.emit(f0AA8);

                        /* END IF */

                        ir_expression *const r0AB6 = nequal(r0A9E, body.constant(0u));
                        ir_expression *const r0AB7 = expr(ir_unop_b2i, r0AB6);
                        ir_expression *const r0AB8 = expr(ir_unop_i2u, r0AB7);
                        body.emit(assign(r0AA1, bit_or(r0AA1, r0AB8), 0x01));


                     body.instructions = f0AA6_parent_instructions;
                     body.emit(f0AA6);

                     /* END IF */

                     body.emit(assign(r0A86, r0AA3, 0x01));

                     body.emit(assign(r0A87, r0AA2, 0x01));

                     body.emit(assign(r0A88, r0AA1, 0x01));

                     body.emit(assign(r0A85, body.constant(0u), 0x01));

                     ir_expression *const r0AB9 = less(r0AA1, body.constant(0u));
                     ir_expression *const r0ABA = expr(ir_unop_b2i, r0AB9);
                     body.emit(assign(r0A8B, expr(ir_unop_i2u, r0ABA), 0x01));


                  body.instructions = f0A9C_parent_instructions;
                  body.emit(f0A9C);

                  /* END IF */


               body.instructions = f0A99_parent_instructions;
               body.emit(f0A99);

               /* END IF */


            body.instructions = f0A8E_parent_instructions;
            body.emit(f0A8E);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0ABB = new(mem_ctx) ir_if(operand(r0A89).val);
            exec_list *const f0ABB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0ABB->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0ABD = nequal(r0A8B, body.constant(0u));
               ir_if *f0ABC = new(mem_ctx) ir_if(operand(r0ABD).val);
               exec_list *const f0ABC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0ABC->then_instructions;

                  ir_variable *const r0ABE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0ABE, add(r0A87, body.constant(1u)), 0x01));

                  ir_expression *const r0ABF = less(r0ABE, r0A87);
                  ir_expression *const r0AC0 = expr(ir_unop_b2i, r0ABF);
                  ir_expression *const r0AC1 = expr(ir_unop_i2u, r0AC0);
                  body.emit(assign(r0A86, add(r0A86, r0AC1), 0x01));

                  ir_expression *const r0AC2 = neg(r0A88);
                  ir_expression *const r0AC3 = equal(r0A88, r0AC2);
                  ir_expression *const r0AC4 = expr(ir_unop_b2i, r0AC3);
                  ir_expression *const r0AC5 = expr(ir_unop_i2u, r0AC4);
                  ir_expression *const r0AC6 = bit_and(r0AC5, body.constant(1u));
                  ir_expression *const r0AC7 = expr(ir_unop_bit_not, r0AC6);
                  body.emit(assign(r0A87, bit_and(r0ABE, r0AC7), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0ABC->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0AC9 = bit_or(r0A86, r0A87);
                  ir_expression *const r0ACA = equal(r0AC9, body.constant(0u));
                  ir_if *f0AC8 = new(mem_ctx) ir_if(operand(r0ACA).val);
                  exec_list *const f0AC8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0AC8->then_instructions;

                     body.emit(assign(r0A85, body.constant(0u), 0x01));


                  body.instructions = f0AC8_parent_instructions;
                  body.emit(f0AC8);

                  /* END IF */


               body.instructions = f0ABC_parent_instructions;
               body.emit(f0ABC);

               /* END IF */

               ir_variable *const r0ACB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0ACB);
               ir_expression *const r0ACC = lshift(r0824, body.constant(int(31)));
               ir_expression *const r0ACD = lshift(r0A85, body.constant(int(20)));
               ir_expression *const r0ACE = add(r0ACC, r0ACD);
               body.emit(assign(r0ACB, add(r0ACE, r0A86), 0x01));

               body.emit(assign(r0ACB, r0A87, 0x02));

               body.emit(assign(r0A8A, r0ACB, 0x03));

               body.emit(assign(r0A89, body.constant(false), 0x01));


            body.instructions = f0ABB_parent_instructions;
            body.emit(f0ABB);

            /* END IF */

            body.emit(assign(r09E1, r0A8A, 0x03));


         body.instructions = f09FA_parent_instructions;
         body.emit(f09FA);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09F8->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0AD0 = less(r09E2, body.constant(int(0)));
         ir_if *f0ACF = new(mem_ctx) ir_if(operand(r0AD0).val);
         exec_list *const f0ACF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ACF->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0AD2 = equal(r09EC, body.constant(2047u));
            ir_if *f0AD1 = new(mem_ctx) ir_if(operand(r0AD2).val);
            exec_list *const f0AD1_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AD1->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0AD4 = bit_or(swizzle_x(r09E4), swizzle_y(r09E4));
               ir_expression *const r0AD5 = nequal(r0AD4, body.constant(0u));
               ir_if *f0AD3 = new(mem_ctx) ir_if(operand(r0AD5).val);
               exec_list *const f0AD3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0AD3->then_instructions;

                  ir_variable *const r0AD6 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0AD6, swizzle_x(r0821), 0x01));

                  ir_variable *const r0AD7 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0AD7, swizzle_x(r0822), 0x01));

                  ir_variable *const r0AD8 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0AD9 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
                  ir_expression *const r0ADA = rshift(swizzle_y(r0821), body.constant(int(19)));
                  ir_expression *const r0ADB = bit_and(r0ADA, body.constant(4095u));
                  ir_expression *const r0ADC = equal(r0ADB, body.constant(4094u));
                  ir_expression *const r0ADD = nequal(swizzle_x(r0821), body.constant(0u));
                  ir_expression *const r0ADE = bit_and(swizzle_y(r0821), body.constant(524287u));
                  ir_expression *const r0ADF = nequal(r0ADE, body.constant(0u));
                  ir_expression *const r0AE0 = logic_or(r0ADD, r0ADF);
                  body.emit(assign(r0AD9, logic_and(r0ADC, r0AE0), 0x01));

                  ir_variable *const r0AE1 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r0AE2 = lshift(swizzle_y(r0822), body.constant(int(1)));
                  ir_expression *const r0AE3 = lequal(body.constant(4292870144u), r0AE2);
                  ir_expression *const r0AE4 = nequal(swizzle_x(r0822), body.constant(0u));
                  ir_expression *const r0AE5 = bit_and(swizzle_y(r0822), body.constant(1048575u));
                  ir_expression *const r0AE6 = nequal(r0AE5, body.constant(0u));
                  ir_expression *const r0AE7 = logic_or(r0AE4, r0AE6);
                  body.emit(assign(r0AE1, logic_and(r0AE3, r0AE7), 0x01));

                  body.emit(assign(r0AD6, bit_or(swizzle_y(r0821), body.constant(524288u)), 0x02));

                  body.emit(assign(r0AD7, bit_or(swizzle_y(r0822), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0AE9 = lshift(swizzle_y(r0821), body.constant(int(1)));
                  ir_expression *const r0AEA = lequal(body.constant(4292870144u), r0AE9);
                  ir_expression *const r0AEB = nequal(swizzle_x(r0821), body.constant(0u));
                  ir_expression *const r0AEC = bit_and(swizzle_y(r0821), body.constant(1048575u));
                  ir_expression *const r0AED = nequal(r0AEC, body.constant(0u));
                  ir_expression *const r0AEE = logic_or(r0AEB, r0AED);
                  ir_expression *const r0AEF = logic_and(r0AEA, r0AEE);
                  ir_if *f0AE8 = new(mem_ctx) ir_if(operand(r0AEF).val);
                  exec_list *const f0AE8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0AE8->then_instructions;

                     ir_variable *const r0AF0 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0AF2 = logic_and(r0AD9, r0AE1);
                     ir_if *f0AF1 = new(mem_ctx) ir_if(operand(r0AF2).val);
                     exec_list *const f0AF1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0AF1->then_instructions;

                        body.emit(assign(r0AF0, r0AD7, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0AF1->else_instructions;

                        body.emit(assign(r0AF0, r0AD6, 0x03));


                     body.instructions = f0AF1_parent_instructions;
                     body.emit(f0AF1);

                     /* END IF */

                     body.emit(assign(r0AD8, r0AF0, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0AE8->else_instructions;

                     body.emit(assign(r0AD8, r0AD7, 0x03));


                  body.instructions = f0AE8_parent_instructions;
                  body.emit(f0AE8);

                  /* END IF */

                  body.emit(assign(r09E1, r0AD8, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0AD3->else_instructions;

                  ir_variable *const r0AF3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0AF3);
                  ir_expression *const r0AF4 = bit_xor(r0824, body.constant(1u));
                  ir_expression *const r0AF5 = lshift(r0AF4, body.constant(int(31)));
                  body.emit(assign(r0AF3, add(r0AF5, body.constant(2146435072u)), 0x01));

                  body.emit(assign(r0AF3, body.constant(0u), 0x02));

                  body.emit(assign(r09E1, r0AF3, 0x03));


               body.instructions = f0AD3_parent_instructions;
               body.emit(f0AD3);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0AD1->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0AF7 = equal(r09E9, body.constant(0u));
               ir_if *f0AF6 = new(mem_ctx) ir_if(operand(r0AF7).val);
               exec_list *const f0AF6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0AF6->then_instructions;

                  body.emit(assign(r09E2, add(r09E2, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0AF6->else_instructions;

                  body.emit(assign(r09E6, bit_or(swizzle_x(r09E6), body.constant(1073741824u)), 0x01));


               body.instructions = f0AF6_parent_instructions;
               body.emit(f0AF6);

               /* END IF */

               ir_variable *const r0AF8 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0AF8, neg(r09E2), 0x01));

               ir_variable *const r0AF9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0AF9);
               ir_variable *const r0AFA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0AFA);
               ir_variable *const r0AFB = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0AFC = neg(r0AF8);
               body.emit(assign(r0AFB, bit_and(r0AFC, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0AFE = equal(r0AF8, body.constant(int(0)));
               ir_if *f0AFD = new(mem_ctx) ir_if(operand(r0AFE).val);
               exec_list *const f0AFD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0AFD->then_instructions;

                  body.emit(assign(r0AF9, swizzle_y(r09E6), 0x01));

                  body.emit(assign(r0AFA, swizzle_x(r09E6), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0AFD->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0B00 = less(r0AF8, body.constant(int(32)));
                  ir_if *f0AFF = new(mem_ctx) ir_if(operand(r0B00).val);
                  exec_list *const f0AFF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0AFF->then_instructions;

                     ir_expression *const r0B01 = lshift(swizzle_x(r09E6), r0AFB);
                     ir_expression *const r0B02 = rshift(r09F0, r0AF8);
                     ir_expression *const r0B03 = bit_or(r0B01, r0B02);
                     ir_expression *const r0B04 = lshift(r09F0, r0AFB);
                     ir_expression *const r0B05 = nequal(r0B04, body.constant(0u));
                     ir_expression *const r0B06 = expr(ir_unop_b2i, r0B05);
                     ir_expression *const r0B07 = expr(ir_unop_i2u, r0B06);
                     body.emit(assign(r0AF9, bit_or(r0B03, r0B07), 0x01));

                     body.emit(assign(r0AFA, rshift(swizzle_x(r09E6), r0AF8), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0AFF->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0B09 = equal(r0AF8, body.constant(int(32)));
                     ir_if *f0B08 = new(mem_ctx) ir_if(operand(r0B09).val);
                     exec_list *const f0B08_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0B08->then_instructions;

                        ir_expression *const r0B0A = nequal(r09F0, body.constant(0u));
                        ir_expression *const r0B0B = expr(ir_unop_b2i, r0B0A);
                        ir_expression *const r0B0C = expr(ir_unop_i2u, r0B0B);
                        body.emit(assign(r0AF9, bit_or(swizzle_x(r09E6), r0B0C), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0B08->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0B0E = less(r0AF8, body.constant(int(64)));
                        ir_if *f0B0D = new(mem_ctx) ir_if(operand(r0B0E).val);
                        exec_list *const f0B0D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0B0D->then_instructions;

                           ir_expression *const r0B0F = bit_and(r0AF8, body.constant(int(31)));
                           ir_expression *const r0B10 = rshift(swizzle_x(r09E6), r0B0F);
                           ir_expression *const r0B11 = lshift(swizzle_x(r09E6), r0AFB);
                           ir_expression *const r0B12 = bit_or(r0B11, r09F0);
                           ir_expression *const r0B13 = nequal(r0B12, body.constant(0u));
                           ir_expression *const r0B14 = expr(ir_unop_b2i, r0B13);
                           ir_expression *const r0B15 = expr(ir_unop_i2u, r0B14);
                           body.emit(assign(r0AF9, bit_or(r0B10, r0B15), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0B0D->else_instructions;

                           ir_expression *const r0B16 = bit_or(swizzle_x(r09E6), r09F0);
                           ir_expression *const r0B17 = nequal(r0B16, body.constant(0u));
                           ir_expression *const r0B18 = expr(ir_unop_b2i, r0B17);
                           body.emit(assign(r0AF9, expr(ir_unop_i2u, r0B18), 0x01));


                        body.instructions = f0B0D_parent_instructions;
                        body.emit(f0B0D);

                        /* END IF */


                     body.instructions = f0B08_parent_instructions;
                     body.emit(f0B08);

                     /* END IF */

                     body.emit(assign(r0AFA, body.constant(0u), 0x01));


                  body.instructions = f0AFF_parent_instructions;
                  body.emit(f0AFF);

                  /* END IF */


               body.instructions = f0AFD_parent_instructions;
               body.emit(f0AFD);

               /* END IF */

               body.emit(assign(r09E6, r0AFA, 0x01));

               body.emit(assign(r09E6, r0AF9, 0x02));

               body.emit(assign(r09E4, bit_or(swizzle_x(r09E4), body.constant(1073741824u)), 0x01));

               ir_variable *const r0B19 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0B1A = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0B1A, sub(swizzle_y(r09E4), r0AF9), 0x01));

               ir_expression *const r0B1B = sub(swizzle_x(r09E4), r0AFA);
               ir_expression *const r0B1C = less(swizzle_y(r09E4), r0AF9);
               ir_expression *const r0B1D = expr(ir_unop_b2i, r0B1C);
               ir_expression *const r0B1E = expr(ir_unop_i2u, r0B1D);
               body.emit(assign(r0B19, sub(r0B1B, r0B1E), 0x01));

               body.emit(assign(r09E0, bit_xor(r0824, body.constant(1u)), 0x01));

               body.emit(assign(r09E7, add(r09EC, body.constant(4294967295u)), 0x01));

               ir_variable *const r0B1F = body.make_temp(glsl_type::uint_type, "zExp");
               body.emit(assign(r0B1F, add(r09E7, body.constant(4294967286u)), 0x01));

               ir_variable *const r0B20 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r0B20, r0B19, 0x01));

               ir_variable *const r0B21 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0B21, r0B1A, 0x01));

               ir_variable *const r0B22 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r0B22);
               ir_variable *const r0B23 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0B23);
               /* IF CONDITION */
               ir_expression *const r0B25 = equal(r0B19, body.constant(0u));
               ir_if *f0B24 = new(mem_ctx) ir_if(operand(r0B25).val);
               exec_list *const f0B24_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B24->then_instructions;

                  body.emit(assign(r0B20, r0B1A, 0x01));

                  body.emit(assign(r0B21, body.constant(0u), 0x01));

                  body.emit(assign(r0B1F, add(r0B1F, body.constant(4294967264u)), 0x01));


               body.instructions = f0B24_parent_instructions;
               body.emit(f0B24);

               /* END IF */

               ir_variable *const r0B26 = body.make_temp(glsl_type::uint_type, "a");
               body.emit(assign(r0B26, r0B20, 0x01));

               ir_variable *const r0B27 = body.make_temp(glsl_type::uint_type, "return_value");
               ir_variable *const r0B28 = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
               body.emit(r0B28);
               /* IF CONDITION */
               ir_expression *const r0B2A = equal(r0B20, body.constant(0u));
               ir_if *f0B29 = new(mem_ctx) ir_if(operand(r0B2A).val);
               exec_list *const f0B29_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B29->then_instructions;

                  body.emit(assign(r0B27, body.constant(32u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0B29->else_instructions;

                  body.emit(assign(r0B28, body.constant(0u), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0B2C = bit_and(r0B20, body.constant(4294901760u));
                  ir_expression *const r0B2D = equal(r0B2C, body.constant(0u));
                  ir_if *f0B2B = new(mem_ctx) ir_if(operand(r0B2D).val);
                  exec_list *const f0B2B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B2B->then_instructions;

                     body.emit(assign(r0B28, body.constant(16u), 0x01));

                     body.emit(assign(r0B26, lshift(r0B20, body.constant(int(16))), 0x01));


                  body.instructions = f0B2B_parent_instructions;
                  body.emit(f0B2B);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r0B2F = bit_and(r0B26, body.constant(4278190080u));
                  ir_expression *const r0B30 = equal(r0B2F, body.constant(0u));
                  ir_if *f0B2E = new(mem_ctx) ir_if(operand(r0B30).val);
                  exec_list *const f0B2E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B2E->then_instructions;

                     body.emit(assign(r0B28, add(r0B28, body.constant(8u)), 0x01));

                     body.emit(assign(r0B26, lshift(r0B26, body.constant(int(8))), 0x01));


                  body.instructions = f0B2E_parent_instructions;
                  body.emit(f0B2E);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r0B32 = bit_and(r0B26, body.constant(4026531840u));
                  ir_expression *const r0B33 = equal(r0B32, body.constant(0u));
                  ir_if *f0B31 = new(mem_ctx) ir_if(operand(r0B33).val);
                  exec_list *const f0B31_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B31->then_instructions;

                     body.emit(assign(r0B28, add(r0B28, body.constant(4u)), 0x01));

                     body.emit(assign(r0B26, lshift(r0B26, body.constant(int(4))), 0x01));


                  body.instructions = f0B31_parent_instructions;
                  body.emit(f0B31);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r0B35 = bit_and(r0B26, body.constant(3221225472u));
                  ir_expression *const r0B36 = equal(r0B35, body.constant(0u));
                  ir_if *f0B34 = new(mem_ctx) ir_if(operand(r0B36).val);
                  exec_list *const f0B34_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B34->then_instructions;

                     body.emit(assign(r0B28, add(r0B28, body.constant(2u)), 0x01));

                     body.emit(assign(r0B26, lshift(r0B26, body.constant(int(2))), 0x01));


                  body.instructions = f0B34_parent_instructions;
                  body.emit(f0B34);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r0B38 = bit_and(r0B26, body.constant(2147483648u));
                  ir_expression *const r0B39 = equal(r0B38, body.constant(0u));
                  ir_if *f0B37 = new(mem_ctx) ir_if(operand(r0B39).val);
                  exec_list *const f0B37_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B37->then_instructions;

                     body.emit(assign(r0B28, add(r0B28, body.constant(1u)), 0x01));


                  body.instructions = f0B37_parent_instructions;
                  body.emit(f0B37);

                  /* END IF */

                  body.emit(assign(r0B27, r0B28, 0x01));


               body.instructions = f0B29_parent_instructions;
               body.emit(f0B29);

               /* END IF */

               ir_expression *const r0B3A = expr(ir_unop_u2i, r0B27);
               body.emit(assign(r0B23, add(r0B3A, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B3C = lequal(body.constant(int(0)), r0B23);
               ir_if *f0B3B = new(mem_ctx) ir_if(operand(r0B3C).val);
               exec_list *const f0B3B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B3B->then_instructions;

                  body.emit(assign(r0B22, body.constant(0u), 0x01));

                  ir_variable *const r0B3D = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r0B3D, lshift(r0B21, r0B23), 0x01));

                  ir_variable *const r0B3E = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r0B40 = equal(r0B23, body.constant(int(0)));
                  ir_if *f0B3F = new(mem_ctx) ir_if(operand(r0B40).val);
                  exec_list *const f0B3F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B3F->then_instructions;

                     body.emit(assign(r0B3E, r0B20, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0B3F->else_instructions;

                     ir_expression *const r0B41 = lshift(r0B20, r0B23);
                     ir_expression *const r0B42 = neg(r0B23);
                     ir_expression *const r0B43 = bit_and(r0B42, body.constant(int(31)));
                     ir_expression *const r0B44 = rshift(r0B21, r0B43);
                     body.emit(assign(r0B3E, bit_or(r0B41, r0B44), 0x01));


                  body.instructions = f0B3F_parent_instructions;
                  body.emit(f0B3F);

                  /* END IF */

                  body.emit(assign(r0B20, r0B3E, 0x01));

                  body.emit(assign(r0B21, r0B3D, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0B3B->else_instructions;

                  ir_variable *const r0B45 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r0B45, body.constant(0u), 0x01));

                  ir_variable *const r0B46 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r0B46, neg(r0B23), 0x01));

                  ir_variable *const r0B47 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0B47);
                  ir_variable *const r0B48 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r0B48);
                  ir_variable *const r0B49 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r0B49);
                  ir_variable *const r0B4A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r0B4B = neg(r0B46);
                  body.emit(assign(r0B4A, bit_and(r0B4B, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0B4D = equal(r0B46, body.constant(int(0)));
                  ir_if *f0B4C = new(mem_ctx) ir_if(operand(r0B4D).val);
                  exec_list *const f0B4C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B4C->then_instructions;

                     body.emit(assign(r0B47, r0B45, 0x01));

                     body.emit(assign(r0B48, r0B21, 0x01));

                     body.emit(assign(r0B49, r0B20, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0B4C->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0B4F = less(r0B46, body.constant(int(32)));
                     ir_if *f0B4E = new(mem_ctx) ir_if(operand(r0B4F).val);
                     exec_list *const f0B4E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0B4E->then_instructions;

                        body.emit(assign(r0B47, lshift(r0B21, r0B4A), 0x01));

                        ir_expression *const r0B50 = lshift(r0B20, r0B4A);
                        ir_expression *const r0B51 = rshift(r0B21, r0B46);
                        body.emit(assign(r0B48, bit_or(r0B50, r0B51), 0x01));

                        body.emit(assign(r0B49, rshift(r0B20, r0B46), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0B4E->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0B53 = equal(r0B46, body.constant(int(32)));
                        ir_if *f0B52 = new(mem_ctx) ir_if(operand(r0B53).val);
                        exec_list *const f0B52_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0B52->then_instructions;

                           body.emit(assign(r0B47, r0B21, 0x01));

                           body.emit(assign(r0B48, r0B20, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0B52->else_instructions;

                           body.emit(assign(r0B45, bit_or(body.constant(0u), r0B21), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0B55 = less(r0B46, body.constant(int(64)));
                           ir_if *f0B54 = new(mem_ctx) ir_if(operand(r0B55).val);
                           exec_list *const f0B54_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0B54->then_instructions;

                              body.emit(assign(r0B47, lshift(r0B20, r0B4A), 0x01));

                              ir_expression *const r0B56 = bit_and(r0B46, body.constant(int(31)));
                              body.emit(assign(r0B48, rshift(r0B20, r0B56), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0B54->else_instructions;

                              ir_variable *const r0B57 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r0B59 = equal(r0B46, body.constant(int(64)));
                              ir_if *f0B58 = new(mem_ctx) ir_if(operand(r0B59).val);
                              exec_list *const f0B58_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0B58->then_instructions;

                                 body.emit(assign(r0B57, r0B20, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0B58->else_instructions;

                                 ir_expression *const r0B5A = nequal(r0B20, body.constant(0u));
                                 ir_expression *const r0B5B = expr(ir_unop_b2i, r0B5A);
                                 body.emit(assign(r0B57, expr(ir_unop_i2u, r0B5B), 0x01));


                              body.instructions = f0B58_parent_instructions;
                              body.emit(f0B58);

                              /* END IF */

                              body.emit(assign(r0B47, r0B57, 0x01));

                              body.emit(assign(r0B48, body.constant(0u), 0x01));


                           body.instructions = f0B54_parent_instructions;
                           body.emit(f0B54);

                           /* END IF */


                        body.instructions = f0B52_parent_instructions;
                        body.emit(f0B52);

                        /* END IF */

                        body.emit(assign(r0B49, body.constant(0u), 0x01));


                     body.instructions = f0B4E_parent_instructions;
                     body.emit(f0B4E);

                     /* END IF */

                     ir_expression *const r0B5C = nequal(r0B45, body.constant(0u));
                     ir_expression *const r0B5D = expr(ir_unop_b2i, r0B5C);
                     ir_expression *const r0B5E = expr(ir_unop_i2u, r0B5D);
                     body.emit(assign(r0B47, bit_or(r0B47, r0B5E), 0x01));


                  body.instructions = f0B4C_parent_instructions;
                  body.emit(f0B4C);

                  /* END IF */

                  body.emit(assign(r0B20, r0B49, 0x01));

                  body.emit(assign(r0B21, r0B48, 0x01));

                  body.emit(assign(r0B22, r0B47, 0x01));


               body.instructions = f0B3B_parent_instructions;
               body.emit(f0B3B);

               /* END IF */

               ir_expression *const r0B5F = expr(ir_unop_i2u, r0B23);
               body.emit(assign(r0B1F, sub(r0B1F, r0B5F), 0x01));

               ir_variable *const r0B60 = body.make_temp(glsl_type::uint_type, "zExp");
               body.emit(assign(r0B60, r0B1F, 0x01));

               ir_variable *const r0B61 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r0B61, r0B20, 0x01));

               ir_variable *const r0B62 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0B62, r0B21, 0x01));

               ir_variable *const r0B63 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r0B63, r0B22, 0x01));

               ir_variable *const r0B64 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0B64, body.constant(true), 0x01));

               ir_variable *const r0B65 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0B66 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
               body.emit(r0B66);
               ir_expression *const r0B67 = less(r0B22, body.constant(0u));
               ir_expression *const r0B68 = expr(ir_unop_b2i, r0B67);
               body.emit(assign(r0B66, expr(ir_unop_i2u, r0B68), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B6A = lequal(body.constant(2045u), r0B1F);
               ir_if *f0B69 = new(mem_ctx) ir_if(operand(r0B6A).val);
               exec_list *const f0B69_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B69->then_instructions;

                  ir_variable *const r0B6B = body.make_temp(glsl_type::bool_type, "or_tmp");
                  /* IF CONDITION */
                  ir_expression *const r0B6D = less(body.constant(2045u), r0B1F);
                  ir_if *f0B6C = new(mem_ctx) ir_if(operand(r0B6D).val);
                  exec_list *const f0B6C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B6C->then_instructions;

                     body.emit(assign(r0B6B, body.constant(true), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0B6C->else_instructions;

                     ir_variable *const r0B6E = body.make_temp(glsl_type::bool_type, "and_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0B70 = equal(r0B1F, body.constant(2045u));
                     ir_if *f0B6F = new(mem_ctx) ir_if(operand(r0B70).val);
                     exec_list *const f0B6F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0B6F->then_instructions;

                        ir_expression *const r0B71 = equal(body.constant(2097151u), r0B20);
                        ir_expression *const r0B72 = equal(body.constant(4294967295u), r0B21);
                        body.emit(assign(r0B6E, logic_and(r0B71, r0B72), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0B6F->else_instructions;

                        body.emit(assign(r0B6E, body.constant(false), 0x01));


                     body.instructions = f0B6F_parent_instructions;
                     body.emit(f0B6F);

                     /* END IF */

                     ir_expression *const r0B73 = nequal(r0B66, body.constant(0u));
                     body.emit(assign(r0B6B, logic_and(r0B6E, r0B73), 0x01));


                  body.instructions = f0B6C_parent_instructions;
                  body.emit(f0B6C);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0B74 = new(mem_ctx) ir_if(operand(r0B6B).val);
                  exec_list *const f0B74_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B74->then_instructions;

                     ir_variable *const r0B75 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0B75);
                     ir_expression *const r0B76 = lshift(r09E0, body.constant(int(31)));
                     body.emit(assign(r0B75, add(r0B76, body.constant(2146435072u)), 0x01));

                     body.emit(assign(r0B75, body.constant(0u), 0x02));

                     body.emit(assign(r0B65, r0B75, 0x03));

                     body.emit(assign(r0B64, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0B74->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0B78 = less(r0B1F, body.constant(0u));
                     ir_if *f0B77 = new(mem_ctx) ir_if(operand(r0B78).val);
                     exec_list *const f0B77_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0B77->then_instructions;

                        ir_variable *const r0B79 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0B79, r0B22, 0x01));

                        ir_variable *const r0B7A = body.make_temp(glsl_type::int_type, "count");
                        ir_expression *const r0B7B = neg(r0B1F);
                        body.emit(assign(r0B7A, expr(ir_unop_u2i, r0B7B), 0x01));

                        ir_variable *const r0B7C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0B7C);
                        ir_variable *const r0B7D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r0B7D);
                        ir_variable *const r0B7E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0B7E);
                        ir_variable *const r0B7F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0B80 = neg(r0B7A);
                        body.emit(assign(r0B7F, bit_and(r0B80, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0B82 = equal(r0B7A, body.constant(int(0)));
                        ir_if *f0B81 = new(mem_ctx) ir_if(operand(r0B82).val);
                        exec_list *const f0B81_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0B81->then_instructions;

                           body.emit(assign(r0B7C, r0B22, 0x01));

                           body.emit(assign(r0B7D, r0B21, 0x01));

                           body.emit(assign(r0B7E, r0B20, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0B81->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0B84 = less(r0B7A, body.constant(int(32)));
                           ir_if *f0B83 = new(mem_ctx) ir_if(operand(r0B84).val);
                           exec_list *const f0B83_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0B83->then_instructions;

                              body.emit(assign(r0B7C, lshift(r0B21, r0B7F), 0x01));

                              ir_expression *const r0B85 = lshift(r0B20, r0B7F);
                              ir_expression *const r0B86 = rshift(r0B21, r0B7A);
                              body.emit(assign(r0B7D, bit_or(r0B85, r0B86), 0x01));

                              body.emit(assign(r0B7E, rshift(r0B20, r0B7A), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0B83->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0B88 = equal(r0B7A, body.constant(int(32)));
                              ir_if *f0B87 = new(mem_ctx) ir_if(operand(r0B88).val);
                              exec_list *const f0B87_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0B87->then_instructions;

                                 body.emit(assign(r0B7C, r0B21, 0x01));

                                 body.emit(assign(r0B7D, r0B20, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0B87->else_instructions;

                                 body.emit(assign(r0B79, bit_or(r0B22, r0B21), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0B8A = less(r0B7A, body.constant(int(64)));
                                 ir_if *f0B89 = new(mem_ctx) ir_if(operand(r0B8A).val);
                                 exec_list *const f0B89_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0B89->then_instructions;

                                    body.emit(assign(r0B7C, lshift(r0B20, r0B7F), 0x01));

                                    ir_expression *const r0B8B = bit_and(r0B7A, body.constant(int(31)));
                                    body.emit(assign(r0B7D, rshift(r0B20, r0B8B), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0B89->else_instructions;

                                    ir_variable *const r0B8C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r0B8E = equal(r0B7A, body.constant(int(64)));
                                    ir_if *f0B8D = new(mem_ctx) ir_if(operand(r0B8E).val);
                                    exec_list *const f0B8D_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0B8D->then_instructions;

                                       body.emit(assign(r0B8C, r0B20, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0B8D->else_instructions;

                                       ir_expression *const r0B8F = nequal(r0B20, body.constant(0u));
                                       ir_expression *const r0B90 = expr(ir_unop_b2i, r0B8F);
                                       body.emit(assign(r0B8C, expr(ir_unop_i2u, r0B90), 0x01));


                                    body.instructions = f0B8D_parent_instructions;
                                    body.emit(f0B8D);

                                    /* END IF */

                                    body.emit(assign(r0B7C, r0B8C, 0x01));

                                    body.emit(assign(r0B7D, body.constant(0u), 0x01));


                                 body.instructions = f0B89_parent_instructions;
                                 body.emit(f0B89);

                                 /* END IF */


                              body.instructions = f0B87_parent_instructions;
                              body.emit(f0B87);

                              /* END IF */

                              body.emit(assign(r0B7E, body.constant(0u), 0x01));


                           body.instructions = f0B83_parent_instructions;
                           body.emit(f0B83);

                           /* END IF */

                           ir_expression *const r0B91 = nequal(r0B79, body.constant(0u));
                           ir_expression *const r0B92 = expr(ir_unop_b2i, r0B91);
                           ir_expression *const r0B93 = expr(ir_unop_i2u, r0B92);
                           body.emit(assign(r0B7C, bit_or(r0B7C, r0B93), 0x01));


                        body.instructions = f0B81_parent_instructions;
                        body.emit(f0B81);

                        /* END IF */

                        body.emit(assign(r0B61, r0B7E, 0x01));

                        body.emit(assign(r0B62, r0B7D, 0x01));

                        body.emit(assign(r0B63, r0B7C, 0x01));

                        body.emit(assign(r0B60, body.constant(0u), 0x01));

                        ir_expression *const r0B94 = less(r0B7C, body.constant(0u));
                        ir_expression *const r0B95 = expr(ir_unop_b2i, r0B94);
                        body.emit(assign(r0B66, expr(ir_unop_i2u, r0B95), 0x01));


                     body.instructions = f0B77_parent_instructions;
                     body.emit(f0B77);

                     /* END IF */


                  body.instructions = f0B74_parent_instructions;
                  body.emit(f0B74);

                  /* END IF */


               body.instructions = f0B69_parent_instructions;
               body.emit(f0B69);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0B96 = new(mem_ctx) ir_if(operand(r0B64).val);
               exec_list *const f0B96_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B96->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0B98 = nequal(r0B66, body.constant(0u));
                  ir_if *f0B97 = new(mem_ctx) ir_if(operand(r0B98).val);
                  exec_list *const f0B97_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0B97->then_instructions;

                     ir_variable *const r0B99 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0B99, add(r0B62, body.constant(1u)), 0x01));

                     ir_expression *const r0B9A = less(r0B99, r0B62);
                     ir_expression *const r0B9B = expr(ir_unop_b2i, r0B9A);
                     ir_expression *const r0B9C = expr(ir_unop_i2u, r0B9B);
                     body.emit(assign(r0B61, add(r0B61, r0B9C), 0x01));

                     ir_expression *const r0B9D = neg(r0B63);
                     ir_expression *const r0B9E = equal(r0B63, r0B9D);
                     ir_expression *const r0B9F = expr(ir_unop_b2i, r0B9E);
                     ir_expression *const r0BA0 = expr(ir_unop_i2u, r0B9F);
                     ir_expression *const r0BA1 = bit_and(r0BA0, body.constant(1u));
                     ir_expression *const r0BA2 = expr(ir_unop_bit_not, r0BA1);
                     body.emit(assign(r0B62, bit_and(r0B99, r0BA2), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0B97->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0BA4 = bit_or(r0B61, r0B62);
                     ir_expression *const r0BA5 = equal(r0BA4, body.constant(0u));
                     ir_if *f0BA3 = new(mem_ctx) ir_if(operand(r0BA5).val);
                     exec_list *const f0BA3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0BA3->then_instructions;

                        body.emit(assign(r0B60, body.constant(0u), 0x01));


                     body.instructions = f0BA3_parent_instructions;
                     body.emit(f0BA3);

                     /* END IF */


                  body.instructions = f0B97_parent_instructions;
                  body.emit(f0B97);

                  /* END IF */

                  ir_variable *const r0BA6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0BA6);
                  ir_expression *const r0BA7 = lshift(r09E0, body.constant(int(31)));
                  ir_expression *const r0BA8 = lshift(r0B60, body.constant(int(20)));
                  ir_expression *const r0BA9 = add(r0BA7, r0BA8);
                  body.emit(assign(r0BA6, add(r0BA9, r0B61), 0x01));

                  body.emit(assign(r0BA6, r0B62, 0x02));

                  body.emit(assign(r0B65, r0BA6, 0x03));

                  body.emit(assign(r0B64, body.constant(false), 0x01));


               body.instructions = f0B96_parent_instructions;
               body.emit(f0B96);

               /* END IF */

               body.emit(assign(r09E1, r0B65, 0x03));


            body.instructions = f0AD1_parent_instructions;
            body.emit(f0AD1);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0ACF->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0BAB = equal(r09E9, body.constant(2047u));
            ir_if *f0BAA = new(mem_ctx) ir_if(operand(r0BAB).val);
            exec_list *const f0BAA_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0BAA->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0BAD = bit_or(swizzle_x(r09E6), swizzle_y(r09E6));
               ir_expression *const r0BAE = bit_or(swizzle_x(r09E4), swizzle_y(r09E4));
               ir_expression *const r0BAF = bit_or(r0BAD, r0BAE);
               ir_expression *const r0BB0 = nequal(r0BAF, body.constant(0u));
               ir_if *f0BAC = new(mem_ctx) ir_if(operand(r0BB0).val);
               exec_list *const f0BAC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BAC->then_instructions;

                  ir_variable *const r0BB1 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0BB1, swizzle_x(r0821), 0x01));

                  ir_variable *const r0BB2 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0BB2, swizzle_x(r0822), 0x01));

                  ir_variable *const r0BB3 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0BB4 = body.make_temp(glsl_type::bool_type, "float64_is_signaling_nan_retval");
                  ir_expression *const r0BB5 = rshift(swizzle_y(r0821), body.constant(int(19)));
                  ir_expression *const r0BB6 = bit_and(r0BB5, body.constant(4095u));
                  ir_expression *const r0BB7 = equal(r0BB6, body.constant(4094u));
                  ir_expression *const r0BB8 = nequal(swizzle_x(r0821), body.constant(0u));
                  ir_expression *const r0BB9 = bit_and(swizzle_y(r0821), body.constant(524287u));
                  ir_expression *const r0BBA = nequal(r0BB9, body.constant(0u));
                  ir_expression *const r0BBB = logic_or(r0BB8, r0BBA);
                  body.emit(assign(r0BB4, logic_and(r0BB7, r0BBB), 0x01));

                  ir_variable *const r0BBC = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r0BBD = lshift(swizzle_y(r0822), body.constant(int(1)));
                  ir_expression *const r0BBE = lequal(body.constant(4292870144u), r0BBD);
                  ir_expression *const r0BBF = nequal(swizzle_x(r0822), body.constant(0u));
                  ir_expression *const r0BC0 = bit_and(swizzle_y(r0822), body.constant(1048575u));
                  ir_expression *const r0BC1 = nequal(r0BC0, body.constant(0u));
                  ir_expression *const r0BC2 = logic_or(r0BBF, r0BC1);
                  body.emit(assign(r0BBC, logic_and(r0BBE, r0BC2), 0x01));

                  body.emit(assign(r0BB1, bit_or(swizzle_y(r0821), body.constant(524288u)), 0x02));

                  body.emit(assign(r0BB2, bit_or(swizzle_y(r0822), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0BC4 = lshift(swizzle_y(r0821), body.constant(int(1)));
                  ir_expression *const r0BC5 = lequal(body.constant(4292870144u), r0BC4);
                  ir_expression *const r0BC6 = nequal(swizzle_x(r0821), body.constant(0u));
                  ir_expression *const r0BC7 = bit_and(swizzle_y(r0821), body.constant(1048575u));
                  ir_expression *const r0BC8 = nequal(r0BC7, body.constant(0u));
                  ir_expression *const r0BC9 = logic_or(r0BC6, r0BC8);
                  ir_expression *const r0BCA = logic_and(r0BC5, r0BC9);
                  ir_if *f0BC3 = new(mem_ctx) ir_if(operand(r0BCA).val);
                  exec_list *const f0BC3_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0BC3->then_instructions;

                     ir_variable *const r0BCB = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0BCD = logic_and(r0BB4, r0BBC);
                     ir_if *f0BCC = new(mem_ctx) ir_if(operand(r0BCD).val);
                     exec_list *const f0BCC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0BCC->then_instructions;

                        body.emit(assign(r0BCB, r0BB2, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0BCC->else_instructions;

                        body.emit(assign(r0BCB, r0BB1, 0x03));


                     body.instructions = f0BCC_parent_instructions;
                     body.emit(f0BCC);

                     /* END IF */

                     body.emit(assign(r0BB3, r0BCB, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0BC3->else_instructions;

                     body.emit(assign(r0BB3, r0BB2, 0x03));


                  body.instructions = f0BC3_parent_instructions;
                  body.emit(f0BC3);

                  /* END IF */

                  body.emit(assign(r09E1, r0BB3, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0BAC->else_instructions;

                  ir_constant_data r0BCE_data;
                  memset(&r0BCE_data, 0, sizeof(ir_constant_data));
                  r0BCE_data.u[0] = 4294967295;
                  r0BCE_data.u[1] = 4294967295;
                  ir_constant *const r0BCE = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0BCE_data);
                  body.emit(assign(r09E1, r0BCE, 0x03));


               body.instructions = f0BAC_parent_instructions;
               body.emit(f0BAC);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0BAA->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0BD0 = equal(r09E9, body.constant(0u));
               ir_if *f0BCF = new(mem_ctx) ir_if(operand(r0BD0).val);
               exec_list *const f0BCF_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BCF->then_instructions;

                  body.emit(assign(r09E5, body.constant(1u), 0x01));

                  body.emit(assign(r09E3, body.constant(1u), 0x01));


               body.instructions = f0BCF_parent_instructions;
               body.emit(f0BCF);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0BD2 = less(swizzle_x(r09E4), swizzle_x(r09E6));
               ir_if *f0BD1 = new(mem_ctx) ir_if(operand(r0BD2).val);
               exec_list *const f0BD1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BD1->then_instructions;

                  ir_variable *const r0BD3 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_variable *const r0BD4 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r0BD4, sub(swizzle_y(r09E6), swizzle_y(r09E4)), 0x01));

                  ir_expression *const r0BD5 = sub(swizzle_x(r09E6), swizzle_x(r09E4));
                  ir_expression *const r0BD6 = less(swizzle_y(r09E6), swizzle_y(r09E4));
                  ir_expression *const r0BD7 = expr(ir_unop_b2i, r0BD6);
                  ir_expression *const r0BD8 = expr(ir_unop_i2u, r0BD7);
                  body.emit(assign(r0BD3, sub(r0BD5, r0BD8), 0x01));

                  body.emit(assign(r09E7, add(r09E5, body.constant(4294967295u)), 0x01));

                  ir_variable *const r0BD9 = body.make_temp(glsl_type::uint_type, "zExp");
                  body.emit(assign(r0BD9, add(r09E7, body.constant(4294967286u)), 0x01));

                  ir_variable *const r0BDA = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0BDA, r0BD3, 0x01));

                  ir_variable *const r0BDB = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0BDB, r0BD4, 0x01));

                  ir_variable *const r0BDC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r0BDC);
                  ir_variable *const r0BDD = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0BDD);
                  /* IF CONDITION */
                  ir_expression *const r0BDF = equal(r0BD3, body.constant(0u));
                  ir_if *f0BDE = new(mem_ctx) ir_if(operand(r0BDF).val);
                  exec_list *const f0BDE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0BDE->then_instructions;

                     body.emit(assign(r0BDA, r0BD4, 0x01));

                     body.emit(assign(r0BDB, body.constant(0u), 0x01));

                     body.emit(assign(r0BD9, add(r0BD9, body.constant(4294967264u)), 0x01));


                  body.instructions = f0BDE_parent_instructions;
                  body.emit(f0BDE);

                  /* END IF */

                  ir_variable *const r0BE0 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r0BE0, r0BDA, 0x01));

                  ir_variable *const r0BE1 = body.make_temp(glsl_type::uint_type, "return_value");
                  ir_variable *const r0BE2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
                  body.emit(r0BE2);
                  /* IF CONDITION */
                  ir_expression *const r0BE4 = equal(r0BDA, body.constant(0u));
                  ir_if *f0BE3 = new(mem_ctx) ir_if(operand(r0BE4).val);
                  exec_list *const f0BE3_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0BE3->then_instructions;

                     body.emit(assign(r0BE1, body.constant(32u), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0BE3->else_instructions;

                     body.emit(assign(r0BE2, body.constant(0u), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0BE6 = bit_and(r0BDA, body.constant(4294901760u));
                     ir_expression *const r0BE7 = equal(r0BE6, body.constant(0u));
                     ir_if *f0BE5 = new(mem_ctx) ir_if(operand(r0BE7).val);
                     exec_list *const f0BE5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0BE5->then_instructions;

                        body.emit(assign(r0BE2, body.constant(16u), 0x01));

                        body.emit(assign(r0BE0, lshift(r0BDA, body.constant(int(16))), 0x01));


                     body.instructions = f0BE5_parent_instructions;
                     body.emit(f0BE5);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0BE9 = bit_and(r0BE0, body.constant(4278190080u));
                     ir_expression *const r0BEA = equal(r0BE9, body.constant(0u));
                     ir_if *f0BE8 = new(mem_ctx) ir_if(operand(r0BEA).val);
                     exec_list *const f0BE8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0BE8->then_instructions;

                        body.emit(assign(r0BE2, add(r0BE2, body.constant(8u)), 0x01));

                        body.emit(assign(r0BE0, lshift(r0BE0, body.constant(int(8))), 0x01));


                     body.instructions = f0BE8_parent_instructions;
                     body.emit(f0BE8);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0BEC = bit_and(r0BE0, body.constant(4026531840u));
                     ir_expression *const r0BED = equal(r0BEC, body.constant(0u));
                     ir_if *f0BEB = new(mem_ctx) ir_if(operand(r0BED).val);
                     exec_list *const f0BEB_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0BEB->then_instructions;

                        body.emit(assign(r0BE2, add(r0BE2, body.constant(4u)), 0x01));

                        body.emit(assign(r0BE0, lshift(r0BE0, body.constant(int(4))), 0x01));


                     body.instructions = f0BEB_parent_instructions;
                     body.emit(f0BEB);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0BEF = bit_and(r0BE0, body.constant(3221225472u));
                     ir_expression *const r0BF0 = equal(r0BEF, body.constant(0u));
                     ir_if *f0BEE = new(mem_ctx) ir_if(operand(r0BF0).val);
                     exec_list *const f0BEE_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0BEE->then_instructions;

                        body.emit(assign(r0BE2, add(r0BE2, body.constant(2u)), 0x01));

                        body.emit(assign(r0BE0, lshift(r0BE0, body.constant(int(2))), 0x01));


                     body.instructions = f0BEE_parent_instructions;
                     body.emit(f0BEE);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0BF2 = bit_and(r0BE0, body.constant(2147483648u));
                     ir_expression *const r0BF3 = equal(r0BF2, body.constant(0u));
                     ir_if *f0BF1 = new(mem_ctx) ir_if(operand(r0BF3).val);
                     exec_list *const f0BF1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0BF1->then_instructions;

                        body.emit(assign(r0BE2, add(r0BE2, body.constant(1u)), 0x01));


                     body.instructions = f0BF1_parent_instructions;
                     body.emit(f0BF1);

                     /* END IF */

                     body.emit(assign(r0BE1, r0BE2, 0x01));


                  body.instructions = f0BE3_parent_instructions;
                  body.emit(f0BE3);

                  /* END IF */

                  ir_expression *const r0BF4 = expr(ir_unop_u2i, r0BE1);
                  body.emit(assign(r0BDD, add(r0BF4, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0BF6 = lequal(body.constant(int(0)), r0BDD);
                  ir_if *f0BF5 = new(mem_ctx) ir_if(operand(r0BF6).val);
                  exec_list *const f0BF5_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0BF5->then_instructions;

                     body.emit(assign(r0BDC, body.constant(0u), 0x01));

                     ir_variable *const r0BF7 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r0BF7, lshift(r0BDB, r0BDD), 0x01));

                     ir_variable *const r0BF8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0BFA = equal(r0BDD, body.constant(int(0)));
                     ir_if *f0BF9 = new(mem_ctx) ir_if(operand(r0BFA).val);
                     exec_list *const f0BF9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0BF9->then_instructions;

                        body.emit(assign(r0BF8, r0BDA, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0BF9->else_instructions;

                        ir_expression *const r0BFB = lshift(r0BDA, r0BDD);
                        ir_expression *const r0BFC = neg(r0BDD);
                        ir_expression *const r0BFD = bit_and(r0BFC, body.constant(int(31)));
                        ir_expression *const r0BFE = rshift(r0BDB, r0BFD);
                        body.emit(assign(r0BF8, bit_or(r0BFB, r0BFE), 0x01));


                     body.instructions = f0BF9_parent_instructions;
                     body.emit(f0BF9);

                     /* END IF */

                     body.emit(assign(r0BDA, r0BF8, 0x01));

                     body.emit(assign(r0BDB, r0BF7, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0BF5->else_instructions;

                     ir_variable *const r0BFF = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0BFF, body.constant(0u), 0x01));

                     ir_variable *const r0C00 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0C00, neg(r0BDD), 0x01));

                     ir_variable *const r0C01 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0C01);
                     ir_variable *const r0C02 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0C02);
                     ir_variable *const r0C03 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0C03);
                     ir_variable *const r0C04 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0C05 = neg(r0C00);
                     body.emit(assign(r0C04, bit_and(r0C05, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0C07 = equal(r0C00, body.constant(int(0)));
                     ir_if *f0C06 = new(mem_ctx) ir_if(operand(r0C07).val);
                     exec_list *const f0C06_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0C06->then_instructions;

                        body.emit(assign(r0C01, r0BFF, 0x01));

                        body.emit(assign(r0C02, r0BDB, 0x01));

                        body.emit(assign(r0C03, r0BDA, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0C06->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0C09 = less(r0C00, body.constant(int(32)));
                        ir_if *f0C08 = new(mem_ctx) ir_if(operand(r0C09).val);
                        exec_list *const f0C08_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C08->then_instructions;

                           body.emit(assign(r0C01, lshift(r0BDB, r0C04), 0x01));

                           ir_expression *const r0C0A = lshift(r0BDA, r0C04);
                           ir_expression *const r0C0B = rshift(r0BDB, r0C00);
                           body.emit(assign(r0C02, bit_or(r0C0A, r0C0B), 0x01));

                           body.emit(assign(r0C03, rshift(r0BDA, r0C00), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0C08->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0C0D = equal(r0C00, body.constant(int(32)));
                           ir_if *f0C0C = new(mem_ctx) ir_if(operand(r0C0D).val);
                           exec_list *const f0C0C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0C0C->then_instructions;

                              body.emit(assign(r0C01, r0BDB, 0x01));

                              body.emit(assign(r0C02, r0BDA, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0C0C->else_instructions;

                              body.emit(assign(r0BFF, bit_or(body.constant(0u), r0BDB), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0C0F = less(r0C00, body.constant(int(64)));
                              ir_if *f0C0E = new(mem_ctx) ir_if(operand(r0C0F).val);
                              exec_list *const f0C0E_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0C0E->then_instructions;

                                 body.emit(assign(r0C01, lshift(r0BDA, r0C04), 0x01));

                                 ir_expression *const r0C10 = bit_and(r0C00, body.constant(int(31)));
                                 body.emit(assign(r0C02, rshift(r0BDA, r0C10), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0C0E->else_instructions;

                                 ir_variable *const r0C11 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0C13 = equal(r0C00, body.constant(int(64)));
                                 ir_if *f0C12 = new(mem_ctx) ir_if(operand(r0C13).val);
                                 exec_list *const f0C12_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0C12->then_instructions;

                                    body.emit(assign(r0C11, r0BDA, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0C12->else_instructions;

                                    ir_expression *const r0C14 = nequal(r0BDA, body.constant(0u));
                                    ir_expression *const r0C15 = expr(ir_unop_b2i, r0C14);
                                    body.emit(assign(r0C11, expr(ir_unop_i2u, r0C15), 0x01));


                                 body.instructions = f0C12_parent_instructions;
                                 body.emit(f0C12);

                                 /* END IF */

                                 body.emit(assign(r0C01, r0C11, 0x01));

                                 body.emit(assign(r0C02, body.constant(0u), 0x01));


                              body.instructions = f0C0E_parent_instructions;
                              body.emit(f0C0E);

                              /* END IF */


                           body.instructions = f0C0C_parent_instructions;
                           body.emit(f0C0C);

                           /* END IF */

                           body.emit(assign(r0C03, body.constant(0u), 0x01));


                        body.instructions = f0C08_parent_instructions;
                        body.emit(f0C08);

                        /* END IF */

                        ir_expression *const r0C16 = nequal(r0BFF, body.constant(0u));
                        ir_expression *const r0C17 = expr(ir_unop_b2i, r0C16);
                        ir_expression *const r0C18 = expr(ir_unop_i2u, r0C17);
                        body.emit(assign(r0C01, bit_or(r0C01, r0C18), 0x01));


                     body.instructions = f0C06_parent_instructions;
                     body.emit(f0C06);

                     /* END IF */

                     body.emit(assign(r0BDA, r0C03, 0x01));

                     body.emit(assign(r0BDB, r0C02, 0x01));

                     body.emit(assign(r0BDC, r0C01, 0x01));


                  body.instructions = f0BF5_parent_instructions;
                  body.emit(f0BF5);

                  /* END IF */

                  ir_expression *const r0C19 = expr(ir_unop_i2u, r0BDD);
                  body.emit(assign(r0BD9, sub(r0BD9, r0C19), 0x01));

                  ir_variable *const r0C1A = body.make_temp(glsl_type::uint_type, "zExp");
                  body.emit(assign(r0C1A, r0BD9, 0x01));

                  ir_variable *const r0C1B = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0C1B, r0BDA, 0x01));

                  ir_variable *const r0C1C = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0C1C, r0BDB, 0x01));

                  ir_variable *const r0C1D = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0C1D, r0BDC, 0x01));

                  ir_variable *const r0C1E = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0C1E, body.constant(true), 0x01));

                  ir_variable *const r0C1F = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0C20 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
                  body.emit(r0C20);
                  ir_expression *const r0C21 = less(r0BDC, body.constant(0u));
                  ir_expression *const r0C22 = expr(ir_unop_b2i, r0C21);
                  body.emit(assign(r0C20, expr(ir_unop_i2u, r0C22), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0C24 = lequal(body.constant(2045u), r0BD9);
                  ir_if *f0C23 = new(mem_ctx) ir_if(operand(r0C24).val);
                  exec_list *const f0C23_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0C23->then_instructions;

                     ir_variable *const r0C25 = body.make_temp(glsl_type::bool_type, "or_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0C27 = less(body.constant(2045u), r0BD9);
                     ir_if *f0C26 = new(mem_ctx) ir_if(operand(r0C27).val);
                     exec_list *const f0C26_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0C26->then_instructions;

                        body.emit(assign(r0C25, body.constant(true), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0C26->else_instructions;

                        ir_variable *const r0C28 = body.make_temp(glsl_type::bool_type, "and_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0C2A = equal(r0BD9, body.constant(2045u));
                        ir_if *f0C29 = new(mem_ctx) ir_if(operand(r0C2A).val);
                        exec_list *const f0C29_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C29->then_instructions;

                           ir_expression *const r0C2B = equal(body.constant(2097151u), r0BDA);
                           ir_expression *const r0C2C = equal(body.constant(4294967295u), r0BDB);
                           body.emit(assign(r0C28, logic_and(r0C2B, r0C2C), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0C29->else_instructions;

                           body.emit(assign(r0C28, body.constant(false), 0x01));


                        body.instructions = f0C29_parent_instructions;
                        body.emit(f0C29);

                        /* END IF */

                        ir_expression *const r0C2D = nequal(r0C20, body.constant(0u));
                        body.emit(assign(r0C25, logic_and(r0C28, r0C2D), 0x01));


                     body.instructions = f0C26_parent_instructions;
                     body.emit(f0C26);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0C2E = new(mem_ctx) ir_if(operand(r0C25).val);
                     exec_list *const f0C2E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0C2E->then_instructions;

                        ir_variable *const r0C2F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0C2F);
                        ir_expression *const r0C30 = lshift(r09E0, body.constant(int(31)));
                        body.emit(assign(r0C2F, add(r0C30, body.constant(2146435072u)), 0x01));

                        body.emit(assign(r0C2F, body.constant(0u), 0x02));

                        body.emit(assign(r0C1F, r0C2F, 0x03));

                        body.emit(assign(r0C1E, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0C2E->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0C32 = less(r0BD9, body.constant(0u));
                        ir_if *f0C31 = new(mem_ctx) ir_if(operand(r0C32).val);
                        exec_list *const f0C31_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C31->then_instructions;

                           ir_variable *const r0C33 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0C33, r0BDC, 0x01));

                           ir_variable *const r0C34 = body.make_temp(glsl_type::int_type, "count");
                           ir_expression *const r0C35 = neg(r0BD9);
                           body.emit(assign(r0C34, expr(ir_unop_u2i, r0C35), 0x01));

                           ir_variable *const r0C36 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0C36);
                           ir_variable *const r0C37 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0C37);
                           ir_variable *const r0C38 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0C38);
                           ir_variable *const r0C39 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0C3A = neg(r0C34);
                           body.emit(assign(r0C39, bit_and(r0C3A, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0C3C = equal(r0C34, body.constant(int(0)));
                           ir_if *f0C3B = new(mem_ctx) ir_if(operand(r0C3C).val);
                           exec_list *const f0C3B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0C3B->then_instructions;

                              body.emit(assign(r0C36, r0BDC, 0x01));

                              body.emit(assign(r0C37, r0BDB, 0x01));

                              body.emit(assign(r0C38, r0BDA, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0C3B->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0C3E = less(r0C34, body.constant(int(32)));
                              ir_if *f0C3D = new(mem_ctx) ir_if(operand(r0C3E).val);
                              exec_list *const f0C3D_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0C3D->then_instructions;

                                 body.emit(assign(r0C36, lshift(r0BDB, r0C39), 0x01));

                                 ir_expression *const r0C3F = lshift(r0BDA, r0C39);
                                 ir_expression *const r0C40 = rshift(r0BDB, r0C34);
                                 body.emit(assign(r0C37, bit_or(r0C3F, r0C40), 0x01));

                                 body.emit(assign(r0C38, rshift(r0BDA, r0C34), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0C3D->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0C42 = equal(r0C34, body.constant(int(32)));
                                 ir_if *f0C41 = new(mem_ctx) ir_if(operand(r0C42).val);
                                 exec_list *const f0C41_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0C41->then_instructions;

                                    body.emit(assign(r0C36, r0BDB, 0x01));

                                    body.emit(assign(r0C37, r0BDA, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0C41->else_instructions;

                                    body.emit(assign(r0C33, bit_or(r0BDC, r0BDB), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0C44 = less(r0C34, body.constant(int(64)));
                                    ir_if *f0C43 = new(mem_ctx) ir_if(operand(r0C44).val);
                                    exec_list *const f0C43_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0C43->then_instructions;

                                       body.emit(assign(r0C36, lshift(r0BDA, r0C39), 0x01));

                                       ir_expression *const r0C45 = bit_and(r0C34, body.constant(int(31)));
                                       body.emit(assign(r0C37, rshift(r0BDA, r0C45), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0C43->else_instructions;

                                       ir_variable *const r0C46 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r0C48 = equal(r0C34, body.constant(int(64)));
                                       ir_if *f0C47 = new(mem_ctx) ir_if(operand(r0C48).val);
                                       exec_list *const f0C47_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0C47->then_instructions;

                                          body.emit(assign(r0C46, r0BDA, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0C47->else_instructions;

                                          ir_expression *const r0C49 = nequal(r0BDA, body.constant(0u));
                                          ir_expression *const r0C4A = expr(ir_unop_b2i, r0C49);
                                          body.emit(assign(r0C46, expr(ir_unop_i2u, r0C4A), 0x01));


                                       body.instructions = f0C47_parent_instructions;
                                       body.emit(f0C47);

                                       /* END IF */

                                       body.emit(assign(r0C36, r0C46, 0x01));

                                       body.emit(assign(r0C37, body.constant(0u), 0x01));


                                    body.instructions = f0C43_parent_instructions;
                                    body.emit(f0C43);

                                    /* END IF */


                                 body.instructions = f0C41_parent_instructions;
                                 body.emit(f0C41);

                                 /* END IF */

                                 body.emit(assign(r0C38, body.constant(0u), 0x01));


                              body.instructions = f0C3D_parent_instructions;
                              body.emit(f0C3D);

                              /* END IF */

                              ir_expression *const r0C4B = nequal(r0C33, body.constant(0u));
                              ir_expression *const r0C4C = expr(ir_unop_b2i, r0C4B);
                              ir_expression *const r0C4D = expr(ir_unop_i2u, r0C4C);
                              body.emit(assign(r0C36, bit_or(r0C36, r0C4D), 0x01));


                           body.instructions = f0C3B_parent_instructions;
                           body.emit(f0C3B);

                           /* END IF */

                           body.emit(assign(r0C1B, r0C38, 0x01));

                           body.emit(assign(r0C1C, r0C37, 0x01));

                           body.emit(assign(r0C1D, r0C36, 0x01));

                           body.emit(assign(r0C1A, body.constant(0u), 0x01));

                           ir_expression *const r0C4E = less(r0C36, body.constant(0u));
                           ir_expression *const r0C4F = expr(ir_unop_b2i, r0C4E);
                           body.emit(assign(r0C20, expr(ir_unop_i2u, r0C4F), 0x01));


                        body.instructions = f0C31_parent_instructions;
                        body.emit(f0C31);

                        /* END IF */


                     body.instructions = f0C2E_parent_instructions;
                     body.emit(f0C2E);

                     /* END IF */


                  body.instructions = f0C23_parent_instructions;
                  body.emit(f0C23);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f0C50 = new(mem_ctx) ir_if(operand(r0C1E).val);
                  exec_list *const f0C50_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0C50->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0C52 = nequal(r0C20, body.constant(0u));
                     ir_if *f0C51 = new(mem_ctx) ir_if(operand(r0C52).val);
                     exec_list *const f0C51_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0C51->then_instructions;

                        ir_variable *const r0C53 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r0C53, add(r0C1C, body.constant(1u)), 0x01));

                        ir_expression *const r0C54 = less(r0C53, r0C1C);
                        ir_expression *const r0C55 = expr(ir_unop_b2i, r0C54);
                        ir_expression *const r0C56 = expr(ir_unop_i2u, r0C55);
                        body.emit(assign(r0C1B, add(r0C1B, r0C56), 0x01));

                        ir_expression *const r0C57 = neg(r0C1D);
                        ir_expression *const r0C58 = equal(r0C1D, r0C57);
                        ir_expression *const r0C59 = expr(ir_unop_b2i, r0C58);
                        ir_expression *const r0C5A = expr(ir_unop_i2u, r0C59);
                        ir_expression *const r0C5B = bit_and(r0C5A, body.constant(1u));
                        ir_expression *const r0C5C = expr(ir_unop_bit_not, r0C5B);
                        body.emit(assign(r0C1C, bit_and(r0C53, r0C5C), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0C51->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0C5E = bit_or(r0C1B, r0C1C);
                        ir_expression *const r0C5F = equal(r0C5E, body.constant(0u));
                        ir_if *f0C5D = new(mem_ctx) ir_if(operand(r0C5F).val);
                        exec_list *const f0C5D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C5D->then_instructions;

                           body.emit(assign(r0C1A, body.constant(0u), 0x01));


                        body.instructions = f0C5D_parent_instructions;
                        body.emit(f0C5D);

                        /* END IF */


                     body.instructions = f0C51_parent_instructions;
                     body.emit(f0C51);

                     /* END IF */

                     ir_variable *const r0C60 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0C60);
                     ir_expression *const r0C61 = lshift(r09E0, body.constant(int(31)));
                     ir_expression *const r0C62 = lshift(r0C1A, body.constant(int(20)));
                     ir_expression *const r0C63 = add(r0C61, r0C62);
                     body.emit(assign(r0C60, add(r0C63, r0C1B), 0x01));

                     body.emit(assign(r0C60, r0C1C, 0x02));

                     body.emit(assign(r0C1F, r0C60, 0x03));

                     body.emit(assign(r0C1E, body.constant(false), 0x01));


                  body.instructions = f0C50_parent_instructions;
                  body.emit(f0C50);

                  /* END IF */

                  body.emit(assign(r09E1, r0C1F, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0BD1->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0C65 = less(swizzle_x(r09E6), swizzle_x(r09E4));
                  ir_if *f0C64 = new(mem_ctx) ir_if(operand(r0C65).val);
                  exec_list *const f0C64_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0C64->then_instructions;

                     ir_variable *const r0C66 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_variable *const r0C67 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r0C67, sub(swizzle_y(r09E4), swizzle_y(r09E6)), 0x01));

                     ir_expression *const r0C68 = sub(swizzle_x(r09E4), swizzle_x(r09E6));
                     ir_expression *const r0C69 = less(swizzle_y(r09E4), swizzle_y(r09E6));
                     ir_expression *const r0C6A = expr(ir_unop_b2i, r0C69);
                     ir_expression *const r0C6B = expr(ir_unop_i2u, r0C6A);
                     body.emit(assign(r0C66, sub(r0C68, r0C6B), 0x01));

                     body.emit(assign(r09E0, bit_xor(r09E0, body.constant(1u)), 0x01));

                     body.emit(assign(r09E7, add(r09E3, body.constant(4294967295u)), 0x01));

                     ir_variable *const r0C6C = body.make_temp(glsl_type::uint_type, "zExp");
                     body.emit(assign(r0C6C, add(r09E7, body.constant(4294967286u)), 0x01));

                     ir_variable *const r0C6D = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0C6D, r0C66, 0x01));

                     ir_variable *const r0C6E = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r0C6E, r0C67, 0x01));

                     ir_variable *const r0C6F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r0C6F);
                     ir_variable *const r0C70 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0C70);
                     /* IF CONDITION */
                     ir_expression *const r0C72 = equal(r0C66, body.constant(0u));
                     ir_if *f0C71 = new(mem_ctx) ir_if(operand(r0C72).val);
                     exec_list *const f0C71_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0C71->then_instructions;

                        body.emit(assign(r0C6D, r0C67, 0x01));

                        body.emit(assign(r0C6E, body.constant(0u), 0x01));

                        body.emit(assign(r0C6C, add(r0C6C, body.constant(4294967264u)), 0x01));


                     body.instructions = f0C71_parent_instructions;
                     body.emit(f0C71);

                     /* END IF */

                     ir_variable *const r0C73 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r0C73, r0C6D, 0x01));

                     ir_variable *const r0C74 = body.make_temp(glsl_type::uint_type, "return_value");
                     ir_variable *const r0C75 = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
                     body.emit(r0C75);
                     /* IF CONDITION */
                     ir_expression *const r0C77 = equal(r0C6D, body.constant(0u));
                     ir_if *f0C76 = new(mem_ctx) ir_if(operand(r0C77).val);
                     exec_list *const f0C76_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0C76->then_instructions;

                        body.emit(assign(r0C74, body.constant(32u), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0C76->else_instructions;

                        body.emit(assign(r0C75, body.constant(0u), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0C79 = bit_and(r0C6D, body.constant(4294901760u));
                        ir_expression *const r0C7A = equal(r0C79, body.constant(0u));
                        ir_if *f0C78 = new(mem_ctx) ir_if(operand(r0C7A).val);
                        exec_list *const f0C78_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C78->then_instructions;

                           body.emit(assign(r0C75, body.constant(16u), 0x01));

                           body.emit(assign(r0C73, lshift(r0C6D, body.constant(int(16))), 0x01));


                        body.instructions = f0C78_parent_instructions;
                        body.emit(f0C78);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0C7C = bit_and(r0C73, body.constant(4278190080u));
                        ir_expression *const r0C7D = equal(r0C7C, body.constant(0u));
                        ir_if *f0C7B = new(mem_ctx) ir_if(operand(r0C7D).val);
                        exec_list *const f0C7B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C7B->then_instructions;

                           body.emit(assign(r0C75, add(r0C75, body.constant(8u)), 0x01));

                           body.emit(assign(r0C73, lshift(r0C73, body.constant(int(8))), 0x01));


                        body.instructions = f0C7B_parent_instructions;
                        body.emit(f0C7B);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0C7F = bit_and(r0C73, body.constant(4026531840u));
                        ir_expression *const r0C80 = equal(r0C7F, body.constant(0u));
                        ir_if *f0C7E = new(mem_ctx) ir_if(operand(r0C80).val);
                        exec_list *const f0C7E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C7E->then_instructions;

                           body.emit(assign(r0C75, add(r0C75, body.constant(4u)), 0x01));

                           body.emit(assign(r0C73, lshift(r0C73, body.constant(int(4))), 0x01));


                        body.instructions = f0C7E_parent_instructions;
                        body.emit(f0C7E);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0C82 = bit_and(r0C73, body.constant(3221225472u));
                        ir_expression *const r0C83 = equal(r0C82, body.constant(0u));
                        ir_if *f0C81 = new(mem_ctx) ir_if(operand(r0C83).val);
                        exec_list *const f0C81_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C81->then_instructions;

                           body.emit(assign(r0C75, add(r0C75, body.constant(2u)), 0x01));

                           body.emit(assign(r0C73, lshift(r0C73, body.constant(int(2))), 0x01));


                        body.instructions = f0C81_parent_instructions;
                        body.emit(f0C81);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0C85 = bit_and(r0C73, body.constant(2147483648u));
                        ir_expression *const r0C86 = equal(r0C85, body.constant(0u));
                        ir_if *f0C84 = new(mem_ctx) ir_if(operand(r0C86).val);
                        exec_list *const f0C84_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C84->then_instructions;

                           body.emit(assign(r0C75, add(r0C75, body.constant(1u)), 0x01));


                        body.instructions = f0C84_parent_instructions;
                        body.emit(f0C84);

                        /* END IF */

                        body.emit(assign(r0C74, r0C75, 0x01));


                     body.instructions = f0C76_parent_instructions;
                     body.emit(f0C76);

                     /* END IF */

                     ir_expression *const r0C87 = expr(ir_unop_u2i, r0C74);
                     body.emit(assign(r0C70, add(r0C87, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0C89 = lequal(body.constant(int(0)), r0C70);
                     ir_if *f0C88 = new(mem_ctx) ir_if(operand(r0C89).val);
                     exec_list *const f0C88_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0C88->then_instructions;

                        body.emit(assign(r0C6F, body.constant(0u), 0x01));

                        ir_variable *const r0C8A = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r0C8A, lshift(r0C6E, r0C70), 0x01));

                        ir_variable *const r0C8B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0C8D = equal(r0C70, body.constant(int(0)));
                        ir_if *f0C8C = new(mem_ctx) ir_if(operand(r0C8D).val);
                        exec_list *const f0C8C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C8C->then_instructions;

                           body.emit(assign(r0C8B, r0C6D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0C8C->else_instructions;

                           ir_expression *const r0C8E = lshift(r0C6D, r0C70);
                           ir_expression *const r0C8F = neg(r0C70);
                           ir_expression *const r0C90 = bit_and(r0C8F, body.constant(int(31)));
                           ir_expression *const r0C91 = rshift(r0C6E, r0C90);
                           body.emit(assign(r0C8B, bit_or(r0C8E, r0C91), 0x01));


                        body.instructions = f0C8C_parent_instructions;
                        body.emit(f0C8C);

                        /* END IF */

                        body.emit(assign(r0C6D, r0C8B, 0x01));

                        body.emit(assign(r0C6E, r0C8A, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0C88->else_instructions;

                        ir_variable *const r0C92 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0C92, body.constant(0u), 0x01));

                        ir_variable *const r0C93 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0C93, neg(r0C70), 0x01));

                        ir_variable *const r0C94 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0C94);
                        ir_variable *const r0C95 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r0C95);
                        ir_variable *const r0C96 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0C96);
                        ir_variable *const r0C97 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0C98 = neg(r0C93);
                        body.emit(assign(r0C97, bit_and(r0C98, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0C9A = equal(r0C93, body.constant(int(0)));
                        ir_if *f0C99 = new(mem_ctx) ir_if(operand(r0C9A).val);
                        exec_list *const f0C99_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0C99->then_instructions;

                           body.emit(assign(r0C94, r0C92, 0x01));

                           body.emit(assign(r0C95, r0C6E, 0x01));

                           body.emit(assign(r0C96, r0C6D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0C99->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0C9C = less(r0C93, body.constant(int(32)));
                           ir_if *f0C9B = new(mem_ctx) ir_if(operand(r0C9C).val);
                           exec_list *const f0C9B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0C9B->then_instructions;

                              body.emit(assign(r0C94, lshift(r0C6E, r0C97), 0x01));

                              ir_expression *const r0C9D = lshift(r0C6D, r0C97);
                              ir_expression *const r0C9E = rshift(r0C6E, r0C93);
                              body.emit(assign(r0C95, bit_or(r0C9D, r0C9E), 0x01));

                              body.emit(assign(r0C96, rshift(r0C6D, r0C93), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0C9B->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0CA0 = equal(r0C93, body.constant(int(32)));
                              ir_if *f0C9F = new(mem_ctx) ir_if(operand(r0CA0).val);
                              exec_list *const f0C9F_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0C9F->then_instructions;

                                 body.emit(assign(r0C94, r0C6E, 0x01));

                                 body.emit(assign(r0C95, r0C6D, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0C9F->else_instructions;

                                 body.emit(assign(r0C92, bit_or(body.constant(0u), r0C6E), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0CA2 = less(r0C93, body.constant(int(64)));
                                 ir_if *f0CA1 = new(mem_ctx) ir_if(operand(r0CA2).val);
                                 exec_list *const f0CA1_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0CA1->then_instructions;

                                    body.emit(assign(r0C94, lshift(r0C6D, r0C97), 0x01));

                                    ir_expression *const r0CA3 = bit_and(r0C93, body.constant(int(31)));
                                    body.emit(assign(r0C95, rshift(r0C6D, r0CA3), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0CA1->else_instructions;

                                    ir_variable *const r0CA4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r0CA6 = equal(r0C93, body.constant(int(64)));
                                    ir_if *f0CA5 = new(mem_ctx) ir_if(operand(r0CA6).val);
                                    exec_list *const f0CA5_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0CA5->then_instructions;

                                       body.emit(assign(r0CA4, r0C6D, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0CA5->else_instructions;

                                       ir_expression *const r0CA7 = nequal(r0C6D, body.constant(0u));
                                       ir_expression *const r0CA8 = expr(ir_unop_b2i, r0CA7);
                                       body.emit(assign(r0CA4, expr(ir_unop_i2u, r0CA8), 0x01));


                                    body.instructions = f0CA5_parent_instructions;
                                    body.emit(f0CA5);

                                    /* END IF */

                                    body.emit(assign(r0C94, r0CA4, 0x01));

                                    body.emit(assign(r0C95, body.constant(0u), 0x01));


                                 body.instructions = f0CA1_parent_instructions;
                                 body.emit(f0CA1);

                                 /* END IF */


                              body.instructions = f0C9F_parent_instructions;
                              body.emit(f0C9F);

                              /* END IF */

                              body.emit(assign(r0C96, body.constant(0u), 0x01));


                           body.instructions = f0C9B_parent_instructions;
                           body.emit(f0C9B);

                           /* END IF */

                           ir_expression *const r0CA9 = nequal(r0C92, body.constant(0u));
                           ir_expression *const r0CAA = expr(ir_unop_b2i, r0CA9);
                           ir_expression *const r0CAB = expr(ir_unop_i2u, r0CAA);
                           body.emit(assign(r0C94, bit_or(r0C94, r0CAB), 0x01));


                        body.instructions = f0C99_parent_instructions;
                        body.emit(f0C99);

                        /* END IF */

                        body.emit(assign(r0C6D, r0C96, 0x01));

                        body.emit(assign(r0C6E, r0C95, 0x01));

                        body.emit(assign(r0C6F, r0C94, 0x01));


                     body.instructions = f0C88_parent_instructions;
                     body.emit(f0C88);

                     /* END IF */

                     ir_expression *const r0CAC = expr(ir_unop_i2u, r0C70);
                     body.emit(assign(r0C6C, sub(r0C6C, r0CAC), 0x01));

                     ir_variable *const r0CAD = body.make_temp(glsl_type::uint_type, "zExp");
                     body.emit(assign(r0CAD, r0C6C, 0x01));

                     ir_variable *const r0CAE = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0CAE, r0C6D, 0x01));

                     ir_variable *const r0CAF = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r0CAF, r0C6E, 0x01));

                     ir_variable *const r0CB0 = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r0CB0, r0C6F, 0x01));

                     ir_variable *const r0CB1 = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r0CB1, body.constant(true), 0x01));

                     ir_variable *const r0CB2 = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r0CB3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
                     body.emit(r0CB3);
                     ir_expression *const r0CB4 = less(r0C6F, body.constant(0u));
                     ir_expression *const r0CB5 = expr(ir_unop_b2i, r0CB4);
                     body.emit(assign(r0CB3, expr(ir_unop_i2u, r0CB5), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0CB7 = lequal(body.constant(2045u), r0C6C);
                     ir_if *f0CB6 = new(mem_ctx) ir_if(operand(r0CB7).val);
                     exec_list *const f0CB6_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0CB6->then_instructions;

                        ir_variable *const r0CB8 = body.make_temp(glsl_type::bool_type, "or_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0CBA = less(body.constant(2045u), r0C6C);
                        ir_if *f0CB9 = new(mem_ctx) ir_if(operand(r0CBA).val);
                        exec_list *const f0CB9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0CB9->then_instructions;

                           body.emit(assign(r0CB8, body.constant(true), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0CB9->else_instructions;

                           ir_variable *const r0CBB = body.make_temp(glsl_type::bool_type, "and_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0CBD = equal(r0C6C, body.constant(2045u));
                           ir_if *f0CBC = new(mem_ctx) ir_if(operand(r0CBD).val);
                           exec_list *const f0CBC_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0CBC->then_instructions;

                              ir_expression *const r0CBE = equal(body.constant(2097151u), r0C6D);
                              ir_expression *const r0CBF = equal(body.constant(4294967295u), r0C6E);
                              body.emit(assign(r0CBB, logic_and(r0CBE, r0CBF), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0CBC->else_instructions;

                              body.emit(assign(r0CBB, body.constant(false), 0x01));


                           body.instructions = f0CBC_parent_instructions;
                           body.emit(f0CBC);

                           /* END IF */

                           ir_expression *const r0CC0 = nequal(r0CB3, body.constant(0u));
                           body.emit(assign(r0CB8, logic_and(r0CBB, r0CC0), 0x01));


                        body.instructions = f0CB9_parent_instructions;
                        body.emit(f0CB9);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f0CC1 = new(mem_ctx) ir_if(operand(r0CB8).val);
                        exec_list *const f0CC1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0CC1->then_instructions;

                           ir_variable *const r0CC2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0CC2);
                           ir_expression *const r0CC3 = lshift(r09E0, body.constant(int(31)));
                           body.emit(assign(r0CC2, add(r0CC3, body.constant(2146435072u)), 0x01));

                           body.emit(assign(r0CC2, body.constant(0u), 0x02));

                           body.emit(assign(r0CB2, r0CC2, 0x03));

                           body.emit(assign(r0CB1, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0CC1->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0CC5 = less(r0C6C, body.constant(0u));
                           ir_if *f0CC4 = new(mem_ctx) ir_if(operand(r0CC5).val);
                           exec_list *const f0CC4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0CC4->then_instructions;

                              ir_variable *const r0CC6 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r0CC6, r0C6F, 0x01));

                              ir_variable *const r0CC7 = body.make_temp(glsl_type::int_type, "count");
                              ir_expression *const r0CC8 = neg(r0C6C);
                              body.emit(assign(r0CC7, expr(ir_unop_u2i, r0CC8), 0x01));

                              ir_variable *const r0CC9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0CC9);
                              ir_variable *const r0CCA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0CCA);
                              ir_variable *const r0CCB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0CCB);
                              ir_variable *const r0CCC = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0CCD = neg(r0CC7);
                              body.emit(assign(r0CCC, bit_and(r0CCD, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0CCF = equal(r0CC7, body.constant(int(0)));
                              ir_if *f0CCE = new(mem_ctx) ir_if(operand(r0CCF).val);
                              exec_list *const f0CCE_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0CCE->then_instructions;

                                 body.emit(assign(r0CC9, r0C6F, 0x01));

                                 body.emit(assign(r0CCA, r0C6E, 0x01));

                                 body.emit(assign(r0CCB, r0C6D, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0CCE->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0CD1 = less(r0CC7, body.constant(int(32)));
                                 ir_if *f0CD0 = new(mem_ctx) ir_if(operand(r0CD1).val);
                                 exec_list *const f0CD0_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0CD0->then_instructions;

                                    body.emit(assign(r0CC9, lshift(r0C6E, r0CCC), 0x01));

                                    ir_expression *const r0CD2 = lshift(r0C6D, r0CCC);
                                    ir_expression *const r0CD3 = rshift(r0C6E, r0CC7);
                                    body.emit(assign(r0CCA, bit_or(r0CD2, r0CD3), 0x01));

                                    body.emit(assign(r0CCB, rshift(r0C6D, r0CC7), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0CD0->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0CD5 = equal(r0CC7, body.constant(int(32)));
                                    ir_if *f0CD4 = new(mem_ctx) ir_if(operand(r0CD5).val);
                                    exec_list *const f0CD4_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0CD4->then_instructions;

                                       body.emit(assign(r0CC9, r0C6E, 0x01));

                                       body.emit(assign(r0CCA, r0C6D, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0CD4->else_instructions;

                                       body.emit(assign(r0CC6, bit_or(r0C6F, r0C6E), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r0CD7 = less(r0CC7, body.constant(int(64)));
                                       ir_if *f0CD6 = new(mem_ctx) ir_if(operand(r0CD7).val);
                                       exec_list *const f0CD6_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0CD6->then_instructions;

                                          body.emit(assign(r0CC9, lshift(r0C6D, r0CCC), 0x01));

                                          ir_expression *const r0CD8 = bit_and(r0CC7, body.constant(int(31)));
                                          body.emit(assign(r0CCA, rshift(r0C6D, r0CD8), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0CD6->else_instructions;

                                          ir_variable *const r0CD9 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r0CDB = equal(r0CC7, body.constant(int(64)));
                                          ir_if *f0CDA = new(mem_ctx) ir_if(operand(r0CDB).val);
                                          exec_list *const f0CDA_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0CDA->then_instructions;

                                             body.emit(assign(r0CD9, r0C6D, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0CDA->else_instructions;

                                             ir_expression *const r0CDC = nequal(r0C6D, body.constant(0u));
                                             ir_expression *const r0CDD = expr(ir_unop_b2i, r0CDC);
                                             body.emit(assign(r0CD9, expr(ir_unop_i2u, r0CDD), 0x01));


                                          body.instructions = f0CDA_parent_instructions;
                                          body.emit(f0CDA);

                                          /* END IF */

                                          body.emit(assign(r0CC9, r0CD9, 0x01));

                                          body.emit(assign(r0CCA, body.constant(0u), 0x01));


                                       body.instructions = f0CD6_parent_instructions;
                                       body.emit(f0CD6);

                                       /* END IF */


                                    body.instructions = f0CD4_parent_instructions;
                                    body.emit(f0CD4);

                                    /* END IF */

                                    body.emit(assign(r0CCB, body.constant(0u), 0x01));


                                 body.instructions = f0CD0_parent_instructions;
                                 body.emit(f0CD0);

                                 /* END IF */

                                 ir_expression *const r0CDE = nequal(r0CC6, body.constant(0u));
                                 ir_expression *const r0CDF = expr(ir_unop_b2i, r0CDE);
                                 ir_expression *const r0CE0 = expr(ir_unop_i2u, r0CDF);
                                 body.emit(assign(r0CC9, bit_or(r0CC9, r0CE0), 0x01));


                              body.instructions = f0CCE_parent_instructions;
                              body.emit(f0CCE);

                              /* END IF */

                              body.emit(assign(r0CAE, r0CCB, 0x01));

                              body.emit(assign(r0CAF, r0CCA, 0x01));

                              body.emit(assign(r0CB0, r0CC9, 0x01));

                              body.emit(assign(r0CAD, body.constant(0u), 0x01));

                              ir_expression *const r0CE1 = less(r0CC9, body.constant(0u));
                              ir_expression *const r0CE2 = expr(ir_unop_b2i, r0CE1);
                              body.emit(assign(r0CB3, expr(ir_unop_i2u, r0CE2), 0x01));


                           body.instructions = f0CC4_parent_instructions;
                           body.emit(f0CC4);

                           /* END IF */


                        body.instructions = f0CC1_parent_instructions;
                        body.emit(f0CC1);

                        /* END IF */


                     body.instructions = f0CB6_parent_instructions;
                     body.emit(f0CB6);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0CE3 = new(mem_ctx) ir_if(operand(r0CB1).val);
                     exec_list *const f0CE3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0CE3->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0CE5 = nequal(r0CB3, body.constant(0u));
                        ir_if *f0CE4 = new(mem_ctx) ir_if(operand(r0CE5).val);
                        exec_list *const f0CE4_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0CE4->then_instructions;

                           ir_variable *const r0CE6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r0CE6, add(r0CAF, body.constant(1u)), 0x01));

                           ir_expression *const r0CE7 = less(r0CE6, r0CAF);
                           ir_expression *const r0CE8 = expr(ir_unop_b2i, r0CE7);
                           ir_expression *const r0CE9 = expr(ir_unop_i2u, r0CE8);
                           body.emit(assign(r0CAE, add(r0CAE, r0CE9), 0x01));

                           ir_expression *const r0CEA = neg(r0CB0);
                           ir_expression *const r0CEB = equal(r0CB0, r0CEA);
                           ir_expression *const r0CEC = expr(ir_unop_b2i, r0CEB);
                           ir_expression *const r0CED = expr(ir_unop_i2u, r0CEC);
                           ir_expression *const r0CEE = bit_and(r0CED, body.constant(1u));
                           ir_expression *const r0CEF = expr(ir_unop_bit_not, r0CEE);
                           body.emit(assign(r0CAF, bit_and(r0CE6, r0CEF), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0CE4->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0CF1 = bit_or(r0CAE, r0CAF);
                           ir_expression *const r0CF2 = equal(r0CF1, body.constant(0u));
                           ir_if *f0CF0 = new(mem_ctx) ir_if(operand(r0CF2).val);
                           exec_list *const f0CF0_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0CF0->then_instructions;

                              body.emit(assign(r0CAD, body.constant(0u), 0x01));


                           body.instructions = f0CF0_parent_instructions;
                           body.emit(f0CF0);

                           /* END IF */


                        body.instructions = f0CE4_parent_instructions;
                        body.emit(f0CE4);

                        /* END IF */

                        ir_variable *const r0CF3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0CF3);
                        ir_expression *const r0CF4 = lshift(r09E0, body.constant(int(31)));
                        ir_expression *const r0CF5 = lshift(r0CAD, body.constant(int(20)));
                        ir_expression *const r0CF6 = add(r0CF4, r0CF5);
                        body.emit(assign(r0CF3, add(r0CF6, r0CAE), 0x01));

                        body.emit(assign(r0CF3, r0CAF, 0x02));

                        body.emit(assign(r0CB2, r0CF3, 0x03));

                        body.emit(assign(r0CB1, body.constant(false), 0x01));


                     body.instructions = f0CE3_parent_instructions;
                     body.emit(f0CE3);

                     /* END IF */

                     body.emit(assign(r09E1, r0CB2, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0C64->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0CF8 = less(swizzle_y(r09E4), swizzle_y(r09E6));
                     ir_if *f0CF7 = new(mem_ctx) ir_if(operand(r0CF8).val);
                     exec_list *const f0CF7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0CF7->then_instructions;

                        ir_variable *const r0CF9 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_variable *const r0CFA = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r0CFA, sub(swizzle_y(r09E6), swizzle_y(r09E4)), 0x01));

                        ir_expression *const r0CFB = sub(swizzle_x(r09E6), swizzle_x(r09E4));
                        ir_expression *const r0CFC = less(swizzle_y(r09E6), swizzle_y(r09E4));
                        ir_expression *const r0CFD = expr(ir_unop_b2i, r0CFC);
                        ir_expression *const r0CFE = expr(ir_unop_i2u, r0CFD);
                        body.emit(assign(r0CF9, sub(r0CFB, r0CFE), 0x01));

                        body.emit(assign(r09E7, add(r09E5, body.constant(4294967295u)), 0x01));

                        ir_variable *const r0CFF = body.make_temp(glsl_type::uint_type, "zExp");
                        body.emit(assign(r0CFF, add(r09E7, body.constant(4294967286u)), 0x01));

                        ir_variable *const r0D00 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r0D00, r0CF9, 0x01));

                        ir_variable *const r0D01 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0D01, r0CFA, 0x01));

                        ir_variable *const r0D02 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0D02);
                        ir_variable *const r0D03 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0D03);
                        /* IF CONDITION */
                        ir_expression *const r0D05 = equal(r0CF9, body.constant(0u));
                        ir_if *f0D04 = new(mem_ctx) ir_if(operand(r0D05).val);
                        exec_list *const f0D04_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0D04->then_instructions;

                           body.emit(assign(r0D00, r0CFA, 0x01));

                           body.emit(assign(r0D01, body.constant(0u), 0x01));

                           body.emit(assign(r0CFF, add(r0CFF, body.constant(4294967264u)), 0x01));


                        body.instructions = f0D04_parent_instructions;
                        body.emit(f0D04);

                        /* END IF */

                        ir_variable *const r0D06 = body.make_temp(glsl_type::uint_type, "a");
                        body.emit(assign(r0D06, r0D00, 0x01));

                        ir_variable *const r0D07 = body.make_temp(glsl_type::uint_type, "return_value");
                        ir_variable *const r0D08 = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
                        body.emit(r0D08);
                        /* IF CONDITION */
                        ir_expression *const r0D0A = equal(r0D00, body.constant(0u));
                        ir_if *f0D09 = new(mem_ctx) ir_if(operand(r0D0A).val);
                        exec_list *const f0D09_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0D09->then_instructions;

                           body.emit(assign(r0D07, body.constant(32u), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0D09->else_instructions;

                           body.emit(assign(r0D08, body.constant(0u), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0D0C = bit_and(r0D00, body.constant(4294901760u));
                           ir_expression *const r0D0D = equal(r0D0C, body.constant(0u));
                           ir_if *f0D0B = new(mem_ctx) ir_if(operand(r0D0D).val);
                           exec_list *const f0D0B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D0B->then_instructions;

                              body.emit(assign(r0D08, body.constant(16u), 0x01));

                              body.emit(assign(r0D06, lshift(r0D00, body.constant(int(16))), 0x01));


                           body.instructions = f0D0B_parent_instructions;
                           body.emit(f0D0B);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0D0F = bit_and(r0D06, body.constant(4278190080u));
                           ir_expression *const r0D10 = equal(r0D0F, body.constant(0u));
                           ir_if *f0D0E = new(mem_ctx) ir_if(operand(r0D10).val);
                           exec_list *const f0D0E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D0E->then_instructions;

                              body.emit(assign(r0D08, add(r0D08, body.constant(8u)), 0x01));

                              body.emit(assign(r0D06, lshift(r0D06, body.constant(int(8))), 0x01));


                           body.instructions = f0D0E_parent_instructions;
                           body.emit(f0D0E);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0D12 = bit_and(r0D06, body.constant(4026531840u));
                           ir_expression *const r0D13 = equal(r0D12, body.constant(0u));
                           ir_if *f0D11 = new(mem_ctx) ir_if(operand(r0D13).val);
                           exec_list *const f0D11_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D11->then_instructions;

                              body.emit(assign(r0D08, add(r0D08, body.constant(4u)), 0x01));

                              body.emit(assign(r0D06, lshift(r0D06, body.constant(int(4))), 0x01));


                           body.instructions = f0D11_parent_instructions;
                           body.emit(f0D11);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0D15 = bit_and(r0D06, body.constant(3221225472u));
                           ir_expression *const r0D16 = equal(r0D15, body.constant(0u));
                           ir_if *f0D14 = new(mem_ctx) ir_if(operand(r0D16).val);
                           exec_list *const f0D14_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D14->then_instructions;

                              body.emit(assign(r0D08, add(r0D08, body.constant(2u)), 0x01));

                              body.emit(assign(r0D06, lshift(r0D06, body.constant(int(2))), 0x01));


                           body.instructions = f0D14_parent_instructions;
                           body.emit(f0D14);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0D18 = bit_and(r0D06, body.constant(2147483648u));
                           ir_expression *const r0D19 = equal(r0D18, body.constant(0u));
                           ir_if *f0D17 = new(mem_ctx) ir_if(operand(r0D19).val);
                           exec_list *const f0D17_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D17->then_instructions;

                              body.emit(assign(r0D08, add(r0D08, body.constant(1u)), 0x01));


                           body.instructions = f0D17_parent_instructions;
                           body.emit(f0D17);

                           /* END IF */

                           body.emit(assign(r0D07, r0D08, 0x01));


                        body.instructions = f0D09_parent_instructions;
                        body.emit(f0D09);

                        /* END IF */

                        ir_expression *const r0D1A = expr(ir_unop_u2i, r0D07);
                        body.emit(assign(r0D03, add(r0D1A, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0D1C = lequal(body.constant(int(0)), r0D03);
                        ir_if *f0D1B = new(mem_ctx) ir_if(operand(r0D1C).val);
                        exec_list *const f0D1B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0D1B->then_instructions;

                           body.emit(assign(r0D02, body.constant(0u), 0x01));

                           ir_variable *const r0D1D = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r0D1D, lshift(r0D01, r0D03), 0x01));

                           ir_variable *const r0D1E = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0D20 = equal(r0D03, body.constant(int(0)));
                           ir_if *f0D1F = new(mem_ctx) ir_if(operand(r0D20).val);
                           exec_list *const f0D1F_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D1F->then_instructions;

                              body.emit(assign(r0D1E, r0D00, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0D1F->else_instructions;

                              ir_expression *const r0D21 = lshift(r0D00, r0D03);
                              ir_expression *const r0D22 = neg(r0D03);
                              ir_expression *const r0D23 = bit_and(r0D22, body.constant(int(31)));
                              ir_expression *const r0D24 = rshift(r0D01, r0D23);
                              body.emit(assign(r0D1E, bit_or(r0D21, r0D24), 0x01));


                           body.instructions = f0D1F_parent_instructions;
                           body.emit(f0D1F);

                           /* END IF */

                           body.emit(assign(r0D00, r0D1E, 0x01));

                           body.emit(assign(r0D01, r0D1D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0D1B->else_instructions;

                           ir_variable *const r0D25 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0D25, body.constant(0u), 0x01));

                           ir_variable *const r0D26 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0D26, neg(r0D03), 0x01));

                           ir_variable *const r0D27 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0D27);
                           ir_variable *const r0D28 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0D28);
                           ir_variable *const r0D29 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0D29);
                           ir_variable *const r0D2A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0D2B = neg(r0D26);
                           body.emit(assign(r0D2A, bit_and(r0D2B, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0D2D = equal(r0D26, body.constant(int(0)));
                           ir_if *f0D2C = new(mem_ctx) ir_if(operand(r0D2D).val);
                           exec_list *const f0D2C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D2C->then_instructions;

                              body.emit(assign(r0D27, r0D25, 0x01));

                              body.emit(assign(r0D28, r0D01, 0x01));

                              body.emit(assign(r0D29, r0D00, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0D2C->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0D2F = less(r0D26, body.constant(int(32)));
                              ir_if *f0D2E = new(mem_ctx) ir_if(operand(r0D2F).val);
                              exec_list *const f0D2E_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0D2E->then_instructions;

                                 body.emit(assign(r0D27, lshift(r0D01, r0D2A), 0x01));

                                 ir_expression *const r0D30 = lshift(r0D00, r0D2A);
                                 ir_expression *const r0D31 = rshift(r0D01, r0D26);
                                 body.emit(assign(r0D28, bit_or(r0D30, r0D31), 0x01));

                                 body.emit(assign(r0D29, rshift(r0D00, r0D26), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0D2E->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0D33 = equal(r0D26, body.constant(int(32)));
                                 ir_if *f0D32 = new(mem_ctx) ir_if(operand(r0D33).val);
                                 exec_list *const f0D32_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0D32->then_instructions;

                                    body.emit(assign(r0D27, r0D01, 0x01));

                                    body.emit(assign(r0D28, r0D00, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0D32->else_instructions;

                                    body.emit(assign(r0D25, bit_or(body.constant(0u), r0D01), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0D35 = less(r0D26, body.constant(int(64)));
                                    ir_if *f0D34 = new(mem_ctx) ir_if(operand(r0D35).val);
                                    exec_list *const f0D34_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0D34->then_instructions;

                                       body.emit(assign(r0D27, lshift(r0D00, r0D2A), 0x01));

                                       ir_expression *const r0D36 = bit_and(r0D26, body.constant(int(31)));
                                       body.emit(assign(r0D28, rshift(r0D00, r0D36), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0D34->else_instructions;

                                       ir_variable *const r0D37 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r0D39 = equal(r0D26, body.constant(int(64)));
                                       ir_if *f0D38 = new(mem_ctx) ir_if(operand(r0D39).val);
                                       exec_list *const f0D38_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0D38->then_instructions;

                                          body.emit(assign(r0D37, r0D00, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0D38->else_instructions;

                                          ir_expression *const r0D3A = nequal(r0D00, body.constant(0u));
                                          ir_expression *const r0D3B = expr(ir_unop_b2i, r0D3A);
                                          body.emit(assign(r0D37, expr(ir_unop_i2u, r0D3B), 0x01));


                                       body.instructions = f0D38_parent_instructions;
                                       body.emit(f0D38);

                                       /* END IF */

                                       body.emit(assign(r0D27, r0D37, 0x01));

                                       body.emit(assign(r0D28, body.constant(0u), 0x01));


                                    body.instructions = f0D34_parent_instructions;
                                    body.emit(f0D34);

                                    /* END IF */


                                 body.instructions = f0D32_parent_instructions;
                                 body.emit(f0D32);

                                 /* END IF */

                                 body.emit(assign(r0D29, body.constant(0u), 0x01));


                              body.instructions = f0D2E_parent_instructions;
                              body.emit(f0D2E);

                              /* END IF */

                              ir_expression *const r0D3C = nequal(r0D25, body.constant(0u));
                              ir_expression *const r0D3D = expr(ir_unop_b2i, r0D3C);
                              ir_expression *const r0D3E = expr(ir_unop_i2u, r0D3D);
                              body.emit(assign(r0D27, bit_or(r0D27, r0D3E), 0x01));


                           body.instructions = f0D2C_parent_instructions;
                           body.emit(f0D2C);

                           /* END IF */

                           body.emit(assign(r0D00, r0D29, 0x01));

                           body.emit(assign(r0D01, r0D28, 0x01));

                           body.emit(assign(r0D02, r0D27, 0x01));


                        body.instructions = f0D1B_parent_instructions;
                        body.emit(f0D1B);

                        /* END IF */

                        ir_expression *const r0D3F = expr(ir_unop_i2u, r0D03);
                        body.emit(assign(r0CFF, sub(r0CFF, r0D3F), 0x01));

                        ir_variable *const r0D40 = body.make_temp(glsl_type::uint_type, "zExp");
                        body.emit(assign(r0D40, r0CFF, 0x01));

                        ir_variable *const r0D41 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r0D41, r0D00, 0x01));

                        ir_variable *const r0D42 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0D42, r0D01, 0x01));

                        ir_variable *const r0D43 = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r0D43, r0D02, 0x01));

                        ir_variable *const r0D44 = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r0D44, body.constant(true), 0x01));

                        ir_variable *const r0D45 = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r0D46 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
                        body.emit(r0D46);
                        ir_expression *const r0D47 = less(r0D02, body.constant(0u));
                        ir_expression *const r0D48 = expr(ir_unop_b2i, r0D47);
                        body.emit(assign(r0D46, expr(ir_unop_i2u, r0D48), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0D4A = lequal(body.constant(2045u), r0CFF);
                        ir_if *f0D49 = new(mem_ctx) ir_if(operand(r0D4A).val);
                        exec_list *const f0D49_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0D49->then_instructions;

                           ir_variable *const r0D4B = body.make_temp(glsl_type::bool_type, "or_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0D4D = less(body.constant(2045u), r0CFF);
                           ir_if *f0D4C = new(mem_ctx) ir_if(operand(r0D4D).val);
                           exec_list *const f0D4C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D4C->then_instructions;

                              body.emit(assign(r0D4B, body.constant(true), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0D4C->else_instructions;

                              ir_variable *const r0D4E = body.make_temp(glsl_type::bool_type, "and_tmp");
                              /* IF CONDITION */
                              ir_expression *const r0D50 = equal(r0CFF, body.constant(2045u));
                              ir_if *f0D4F = new(mem_ctx) ir_if(operand(r0D50).val);
                              exec_list *const f0D4F_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0D4F->then_instructions;

                                 ir_expression *const r0D51 = equal(body.constant(2097151u), r0D00);
                                 ir_expression *const r0D52 = equal(body.constant(4294967295u), r0D01);
                                 body.emit(assign(r0D4E, logic_and(r0D51, r0D52), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0D4F->else_instructions;

                                 body.emit(assign(r0D4E, body.constant(false), 0x01));


                              body.instructions = f0D4F_parent_instructions;
                              body.emit(f0D4F);

                              /* END IF */

                              ir_expression *const r0D53 = nequal(r0D46, body.constant(0u));
                              body.emit(assign(r0D4B, logic_and(r0D4E, r0D53), 0x01));


                           body.instructions = f0D4C_parent_instructions;
                           body.emit(f0D4C);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f0D54 = new(mem_ctx) ir_if(operand(r0D4B).val);
                           exec_list *const f0D54_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D54->then_instructions;

                              ir_variable *const r0D55 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0D55);
                              ir_expression *const r0D56 = lshift(r09E0, body.constant(int(31)));
                              body.emit(assign(r0D55, add(r0D56, body.constant(2146435072u)), 0x01));

                              body.emit(assign(r0D55, body.constant(0u), 0x02));

                              body.emit(assign(r0D45, r0D55, 0x03));

                              body.emit(assign(r0D44, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0D54->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0D58 = less(r0CFF, body.constant(0u));
                              ir_if *f0D57 = new(mem_ctx) ir_if(operand(r0D58).val);
                              exec_list *const f0D57_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0D57->then_instructions;

                                 ir_variable *const r0D59 = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r0D59, r0D02, 0x01));

                                 ir_variable *const r0D5A = body.make_temp(glsl_type::int_type, "count");
                                 ir_expression *const r0D5B = neg(r0CFF);
                                 body.emit(assign(r0D5A, expr(ir_unop_u2i, r0D5B), 0x01));

                                 ir_variable *const r0D5C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r0D5C);
                                 ir_variable *const r0D5D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r0D5D);
                                 ir_variable *const r0D5E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r0D5E);
                                 ir_variable *const r0D5F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r0D60 = neg(r0D5A);
                                 body.emit(assign(r0D5F, bit_and(r0D60, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0D62 = equal(r0D5A, body.constant(int(0)));
                                 ir_if *f0D61 = new(mem_ctx) ir_if(operand(r0D62).val);
                                 exec_list *const f0D61_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0D61->then_instructions;

                                    body.emit(assign(r0D5C, r0D02, 0x01));

                                    body.emit(assign(r0D5D, r0D01, 0x01));

                                    body.emit(assign(r0D5E, r0D00, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0D61->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0D64 = less(r0D5A, body.constant(int(32)));
                                    ir_if *f0D63 = new(mem_ctx) ir_if(operand(r0D64).val);
                                    exec_list *const f0D63_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0D63->then_instructions;

                                       body.emit(assign(r0D5C, lshift(r0D01, r0D5F), 0x01));

                                       ir_expression *const r0D65 = lshift(r0D00, r0D5F);
                                       ir_expression *const r0D66 = rshift(r0D01, r0D5A);
                                       body.emit(assign(r0D5D, bit_or(r0D65, r0D66), 0x01));

                                       body.emit(assign(r0D5E, rshift(r0D00, r0D5A), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0D63->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r0D68 = equal(r0D5A, body.constant(int(32)));
                                       ir_if *f0D67 = new(mem_ctx) ir_if(operand(r0D68).val);
                                       exec_list *const f0D67_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0D67->then_instructions;

                                          body.emit(assign(r0D5C, r0D01, 0x01));

                                          body.emit(assign(r0D5D, r0D00, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0D67->else_instructions;

                                          body.emit(assign(r0D59, bit_or(r0D02, r0D01), 0x01));

                                          /* IF CONDITION */
                                          ir_expression *const r0D6A = less(r0D5A, body.constant(int(64)));
                                          ir_if *f0D69 = new(mem_ctx) ir_if(operand(r0D6A).val);
                                          exec_list *const f0D69_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0D69->then_instructions;

                                             body.emit(assign(r0D5C, lshift(r0D00, r0D5F), 0x01));

                                             ir_expression *const r0D6B = bit_and(r0D5A, body.constant(int(31)));
                                             body.emit(assign(r0D5D, rshift(r0D00, r0D6B), 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0D69->else_instructions;

                                             ir_variable *const r0D6C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                             /* IF CONDITION */
                                             ir_expression *const r0D6E = equal(r0D5A, body.constant(int(64)));
                                             ir_if *f0D6D = new(mem_ctx) ir_if(operand(r0D6E).val);
                                             exec_list *const f0D6D_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f0D6D->then_instructions;

                                                body.emit(assign(r0D6C, r0D00, 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f0D6D->else_instructions;

                                                ir_expression *const r0D6F = nequal(r0D00, body.constant(0u));
                                                ir_expression *const r0D70 = expr(ir_unop_b2i, r0D6F);
                                                body.emit(assign(r0D6C, expr(ir_unop_i2u, r0D70), 0x01));


                                             body.instructions = f0D6D_parent_instructions;
                                             body.emit(f0D6D);

                                             /* END IF */

                                             body.emit(assign(r0D5C, r0D6C, 0x01));

                                             body.emit(assign(r0D5D, body.constant(0u), 0x01));


                                          body.instructions = f0D69_parent_instructions;
                                          body.emit(f0D69);

                                          /* END IF */


                                       body.instructions = f0D67_parent_instructions;
                                       body.emit(f0D67);

                                       /* END IF */

                                       body.emit(assign(r0D5E, body.constant(0u), 0x01));


                                    body.instructions = f0D63_parent_instructions;
                                    body.emit(f0D63);

                                    /* END IF */

                                    ir_expression *const r0D71 = nequal(r0D59, body.constant(0u));
                                    ir_expression *const r0D72 = expr(ir_unop_b2i, r0D71);
                                    ir_expression *const r0D73 = expr(ir_unop_i2u, r0D72);
                                    body.emit(assign(r0D5C, bit_or(r0D5C, r0D73), 0x01));


                                 body.instructions = f0D61_parent_instructions;
                                 body.emit(f0D61);

                                 /* END IF */

                                 body.emit(assign(r0D41, r0D5E, 0x01));

                                 body.emit(assign(r0D42, r0D5D, 0x01));

                                 body.emit(assign(r0D43, r0D5C, 0x01));

                                 body.emit(assign(r0D40, body.constant(0u), 0x01));

                                 ir_expression *const r0D74 = less(r0D5C, body.constant(0u));
                                 ir_expression *const r0D75 = expr(ir_unop_b2i, r0D74);
                                 body.emit(assign(r0D46, expr(ir_unop_i2u, r0D75), 0x01));


                              body.instructions = f0D57_parent_instructions;
                              body.emit(f0D57);

                              /* END IF */


                           body.instructions = f0D54_parent_instructions;
                           body.emit(f0D54);

                           /* END IF */


                        body.instructions = f0D49_parent_instructions;
                        body.emit(f0D49);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f0D76 = new(mem_ctx) ir_if(operand(r0D44).val);
                        exec_list *const f0D76_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0D76->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0D78 = nequal(r0D46, body.constant(0u));
                           ir_if *f0D77 = new(mem_ctx) ir_if(operand(r0D78).val);
                           exec_list *const f0D77_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D77->then_instructions;

                              ir_variable *const r0D79 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r0D79, add(r0D42, body.constant(1u)), 0x01));

                              ir_expression *const r0D7A = less(r0D79, r0D42);
                              ir_expression *const r0D7B = expr(ir_unop_b2i, r0D7A);
                              ir_expression *const r0D7C = expr(ir_unop_i2u, r0D7B);
                              body.emit(assign(r0D41, add(r0D41, r0D7C), 0x01));

                              ir_expression *const r0D7D = neg(r0D43);
                              ir_expression *const r0D7E = equal(r0D43, r0D7D);
                              ir_expression *const r0D7F = expr(ir_unop_b2i, r0D7E);
                              ir_expression *const r0D80 = expr(ir_unop_i2u, r0D7F);
                              ir_expression *const r0D81 = bit_and(r0D80, body.constant(1u));
                              ir_expression *const r0D82 = expr(ir_unop_bit_not, r0D81);
                              body.emit(assign(r0D42, bit_and(r0D79, r0D82), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0D77->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0D84 = bit_or(r0D41, r0D42);
                              ir_expression *const r0D85 = equal(r0D84, body.constant(0u));
                              ir_if *f0D83 = new(mem_ctx) ir_if(operand(r0D85).val);
                              exec_list *const f0D83_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0D83->then_instructions;

                                 body.emit(assign(r0D40, body.constant(0u), 0x01));


                              body.instructions = f0D83_parent_instructions;
                              body.emit(f0D83);

                              /* END IF */


                           body.instructions = f0D77_parent_instructions;
                           body.emit(f0D77);

                           /* END IF */

                           ir_variable *const r0D86 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0D86);
                           ir_expression *const r0D87 = lshift(r09E0, body.constant(int(31)));
                           ir_expression *const r0D88 = lshift(r0D40, body.constant(int(20)));
                           ir_expression *const r0D89 = add(r0D87, r0D88);
                           body.emit(assign(r0D86, add(r0D89, r0D41), 0x01));

                           body.emit(assign(r0D86, r0D42, 0x02));

                           body.emit(assign(r0D45, r0D86, 0x03));

                           body.emit(assign(r0D44, body.constant(false), 0x01));


                        body.instructions = f0D76_parent_instructions;
                        body.emit(f0D76);

                        /* END IF */

                        body.emit(assign(r09E1, r0D45, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0CF7->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0D8B = less(swizzle_y(r09E6), swizzle_y(r09E4));
                        ir_if *f0D8A = new(mem_ctx) ir_if(operand(r0D8B).val);
                        exec_list *const f0D8A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0D8A->then_instructions;

                           ir_variable *const r0D8C = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_variable *const r0D8D = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r0D8D, sub(swizzle_y(r09E4), swizzle_y(r09E6)), 0x01));

                           ir_expression *const r0D8E = sub(swizzle_x(r09E4), swizzle_x(r09E6));
                           ir_expression *const r0D8F = less(swizzle_y(r09E4), swizzle_y(r09E6));
                           ir_expression *const r0D90 = expr(ir_unop_b2i, r0D8F);
                           ir_expression *const r0D91 = expr(ir_unop_i2u, r0D90);
                           body.emit(assign(r0D8C, sub(r0D8E, r0D91), 0x01));

                           body.emit(assign(r09E0, bit_xor(r09E0, body.constant(1u)), 0x01));

                           body.emit(assign(r09E7, add(r09E3, body.constant(4294967295u)), 0x01));

                           ir_variable *const r0D92 = body.make_temp(glsl_type::uint_type, "zExp");
                           body.emit(assign(r0D92, add(r09E7, body.constant(4294967286u)), 0x01));

                           ir_variable *const r0D93 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r0D93, r0D8C, 0x01));

                           ir_variable *const r0D94 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r0D94, r0D8D, 0x01));

                           ir_variable *const r0D95 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r0D95);
                           ir_variable *const r0D96 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r0D96);
                           /* IF CONDITION */
                           ir_expression *const r0D98 = equal(r0D8C, body.constant(0u));
                           ir_if *f0D97 = new(mem_ctx) ir_if(operand(r0D98).val);
                           exec_list *const f0D97_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D97->then_instructions;

                              body.emit(assign(r0D93, r0D8D, 0x01));

                              body.emit(assign(r0D94, body.constant(0u), 0x01));

                              body.emit(assign(r0D92, add(r0D92, body.constant(4294967264u)), 0x01));


                           body.instructions = f0D97_parent_instructions;
                           body.emit(f0D97);

                           /* END IF */

                           ir_variable *const r0D99 = body.make_temp(glsl_type::uint_type, "a");
                           body.emit(assign(r0D99, r0D93, 0x01));

                           ir_variable *const r0D9A = body.make_temp(glsl_type::uint_type, "return_value");
                           ir_variable *const r0D9B = new(mem_ctx) ir_variable(glsl_type::uint_type, "shiftCount", ir_var_auto);
                           body.emit(r0D9B);
                           /* IF CONDITION */
                           ir_expression *const r0D9D = equal(r0D93, body.constant(0u));
                           ir_if *f0D9C = new(mem_ctx) ir_if(operand(r0D9D).val);
                           exec_list *const f0D9C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0D9C->then_instructions;

                              body.emit(assign(r0D9A, body.constant(32u), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0D9C->else_instructions;

                              body.emit(assign(r0D9B, body.constant(0u), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0D9F = bit_and(r0D93, body.constant(4294901760u));
                              ir_expression *const r0DA0 = equal(r0D9F, body.constant(0u));
                              ir_if *f0D9E = new(mem_ctx) ir_if(operand(r0DA0).val);
                              exec_list *const f0D9E_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0D9E->then_instructions;

                                 body.emit(assign(r0D9B, body.constant(16u), 0x01));

                                 body.emit(assign(r0D99, lshift(r0D93, body.constant(int(16))), 0x01));


                              body.instructions = f0D9E_parent_instructions;
                              body.emit(f0D9E);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0DA2 = bit_and(r0D99, body.constant(4278190080u));
                              ir_expression *const r0DA3 = equal(r0DA2, body.constant(0u));
                              ir_if *f0DA1 = new(mem_ctx) ir_if(operand(r0DA3).val);
                              exec_list *const f0DA1_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0DA1->then_instructions;

                                 body.emit(assign(r0D9B, add(r0D9B, body.constant(8u)), 0x01));

                                 body.emit(assign(r0D99, lshift(r0D99, body.constant(int(8))), 0x01));


                              body.instructions = f0DA1_parent_instructions;
                              body.emit(f0DA1);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0DA5 = bit_and(r0D99, body.constant(4026531840u));
                              ir_expression *const r0DA6 = equal(r0DA5, body.constant(0u));
                              ir_if *f0DA4 = new(mem_ctx) ir_if(operand(r0DA6).val);
                              exec_list *const f0DA4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0DA4->then_instructions;

                                 body.emit(assign(r0D9B, add(r0D9B, body.constant(4u)), 0x01));

                                 body.emit(assign(r0D99, lshift(r0D99, body.constant(int(4))), 0x01));


                              body.instructions = f0DA4_parent_instructions;
                              body.emit(f0DA4);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0DA8 = bit_and(r0D99, body.constant(3221225472u));
                              ir_expression *const r0DA9 = equal(r0DA8, body.constant(0u));
                              ir_if *f0DA7 = new(mem_ctx) ir_if(operand(r0DA9).val);
                              exec_list *const f0DA7_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0DA7->then_instructions;

                                 body.emit(assign(r0D9B, add(r0D9B, body.constant(2u)), 0x01));

                                 body.emit(assign(r0D99, lshift(r0D99, body.constant(int(2))), 0x01));


                              body.instructions = f0DA7_parent_instructions;
                              body.emit(f0DA7);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0DAB = bit_and(r0D99, body.constant(2147483648u));
                              ir_expression *const r0DAC = equal(r0DAB, body.constant(0u));
                              ir_if *f0DAA = new(mem_ctx) ir_if(operand(r0DAC).val);
                              exec_list *const f0DAA_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0DAA->then_instructions;

                                 body.emit(assign(r0D9B, add(r0D9B, body.constant(1u)), 0x01));


                              body.instructions = f0DAA_parent_instructions;
                              body.emit(f0DAA);

                              /* END IF */

                              body.emit(assign(r0D9A, r0D9B, 0x01));


                           body.instructions = f0D9C_parent_instructions;
                           body.emit(f0D9C);

                           /* END IF */

                           ir_expression *const r0DAD = expr(ir_unop_u2i, r0D9A);
                           body.emit(assign(r0D96, add(r0DAD, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0DAF = lequal(body.constant(int(0)), r0D96);
                           ir_if *f0DAE = new(mem_ctx) ir_if(operand(r0DAF).val);
                           exec_list *const f0DAE_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0DAE->then_instructions;

                              body.emit(assign(r0D95, body.constant(0u), 0x01));

                              ir_variable *const r0DB0 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                              body.emit(assign(r0DB0, lshift(r0D94, r0D96), 0x01));

                              ir_variable *const r0DB1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r0DB3 = equal(r0D96, body.constant(int(0)));
                              ir_if *f0DB2 = new(mem_ctx) ir_if(operand(r0DB3).val);
                              exec_list *const f0DB2_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0DB2->then_instructions;

                                 body.emit(assign(r0DB1, r0D93, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0DB2->else_instructions;

                                 ir_expression *const r0DB4 = lshift(r0D93, r0D96);
                                 ir_expression *const r0DB5 = neg(r0D96);
                                 ir_expression *const r0DB6 = bit_and(r0DB5, body.constant(int(31)));
                                 ir_expression *const r0DB7 = rshift(r0D94, r0DB6);
                                 body.emit(assign(r0DB1, bit_or(r0DB4, r0DB7), 0x01));


                              body.instructions = f0DB2_parent_instructions;
                              body.emit(f0DB2);

                              /* END IF */

                              body.emit(assign(r0D93, r0DB1, 0x01));

                              body.emit(assign(r0D94, r0DB0, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0DAE->else_instructions;

                              ir_variable *const r0DB8 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r0DB8, body.constant(0u), 0x01));

                              ir_variable *const r0DB9 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0DB9, neg(r0D96), 0x01));

                              ir_variable *const r0DBA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0DBA);
                              ir_variable *const r0DBB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0DBB);
                              ir_variable *const r0DBC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0DBC);
                              ir_variable *const r0DBD = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0DBE = neg(r0DB9);
                              body.emit(assign(r0DBD, bit_and(r0DBE, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0DC0 = equal(r0DB9, body.constant(int(0)));
                              ir_if *f0DBF = new(mem_ctx) ir_if(operand(r0DC0).val);
                              exec_list *const f0DBF_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0DBF->then_instructions;

                                 body.emit(assign(r0DBA, r0DB8, 0x01));

                                 body.emit(assign(r0DBB, r0D94, 0x01));

                                 body.emit(assign(r0DBC, r0D93, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0DBF->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0DC2 = less(r0DB9, body.constant(int(32)));
                                 ir_if *f0DC1 = new(mem_ctx) ir_if(operand(r0DC2).val);
                                 exec_list *const f0DC1_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0DC1->then_instructions;

                                    body.emit(assign(r0DBA, lshift(r0D94, r0DBD), 0x01));

                                    ir_expression *const r0DC3 = lshift(r0D93, r0DBD);
                                    ir_expression *const r0DC4 = rshift(r0D94, r0DB9);
                                    body.emit(assign(r0DBB, bit_or(r0DC3, r0DC4), 0x01));

                                    body.emit(assign(r0DBC, rshift(r0D93, r0DB9), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0DC1->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0DC6 = equal(r0DB9, body.constant(int(32)));
                                    ir_if *f0DC5 = new(mem_ctx) ir_if(operand(r0DC6).val);
                                    exec_list *const f0DC5_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0DC5->then_instructions;

                                       body.emit(assign(r0DBA, r0D94, 0x01));

                                       body.emit(assign(r0DBB, r0D93, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0DC5->else_instructions;

                                       body.emit(assign(r0DB8, bit_or(body.constant(0u), r0D94), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r0DC8 = less(r0DB9, body.constant(int(64)));
                                       ir_if *f0DC7 = new(mem_ctx) ir_if(operand(r0DC8).val);
                                       exec_list *const f0DC7_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0DC7->then_instructions;

                                          body.emit(assign(r0DBA, lshift(r0D93, r0DBD), 0x01));

                                          ir_expression *const r0DC9 = bit_and(r0DB9, body.constant(int(31)));
                                          body.emit(assign(r0DBB, rshift(r0D93, r0DC9), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0DC7->else_instructions;

                                          ir_variable *const r0DCA = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r0DCC = equal(r0DB9, body.constant(int(64)));
                                          ir_if *f0DCB = new(mem_ctx) ir_if(operand(r0DCC).val);
                                          exec_list *const f0DCB_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0DCB->then_instructions;

                                             body.emit(assign(r0DCA, r0D93, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0DCB->else_instructions;

                                             ir_expression *const r0DCD = nequal(r0D93, body.constant(0u));
                                             ir_expression *const r0DCE = expr(ir_unop_b2i, r0DCD);
                                             body.emit(assign(r0DCA, expr(ir_unop_i2u, r0DCE), 0x01));


                                          body.instructions = f0DCB_parent_instructions;
                                          body.emit(f0DCB);

                                          /* END IF */

                                          body.emit(assign(r0DBA, r0DCA, 0x01));

                                          body.emit(assign(r0DBB, body.constant(0u), 0x01));


                                       body.instructions = f0DC7_parent_instructions;
                                       body.emit(f0DC7);

                                       /* END IF */


                                    body.instructions = f0DC5_parent_instructions;
                                    body.emit(f0DC5);

                                    /* END IF */

                                    body.emit(assign(r0DBC, body.constant(0u), 0x01));


                                 body.instructions = f0DC1_parent_instructions;
                                 body.emit(f0DC1);

                                 /* END IF */

                                 ir_expression *const r0DCF = nequal(r0DB8, body.constant(0u));
                                 ir_expression *const r0DD0 = expr(ir_unop_b2i, r0DCF);
                                 ir_expression *const r0DD1 = expr(ir_unop_i2u, r0DD0);
                                 body.emit(assign(r0DBA, bit_or(r0DBA, r0DD1), 0x01));


                              body.instructions = f0DBF_parent_instructions;
                              body.emit(f0DBF);

                              /* END IF */

                              body.emit(assign(r0D93, r0DBC, 0x01));

                              body.emit(assign(r0D94, r0DBB, 0x01));

                              body.emit(assign(r0D95, r0DBA, 0x01));


                           body.instructions = f0DAE_parent_instructions;
                           body.emit(f0DAE);

                           /* END IF */

                           ir_expression *const r0DD2 = expr(ir_unop_i2u, r0D96);
                           body.emit(assign(r0D92, sub(r0D92, r0DD2), 0x01));

                           ir_variable *const r0DD3 = body.make_temp(glsl_type::uint_type, "zExp");
                           body.emit(assign(r0DD3, r0D92, 0x01));

                           ir_variable *const r0DD4 = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r0DD4, r0D93, 0x01));

                           ir_variable *const r0DD5 = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r0DD5, r0D94, 0x01));

                           ir_variable *const r0DD6 = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r0DD6, r0D95, 0x01));

                           ir_variable *const r0DD7 = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r0DD7, body.constant(true), 0x01));

                           ir_variable *const r0DD8 = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r0DD9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "increment", ir_var_auto);
                           body.emit(r0DD9);
                           ir_expression *const r0DDA = less(r0D95, body.constant(0u));
                           ir_expression *const r0DDB = expr(ir_unop_b2i, r0DDA);
                           body.emit(assign(r0DD9, expr(ir_unop_i2u, r0DDB), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0DDD = lequal(body.constant(2045u), r0D92);
                           ir_if *f0DDC = new(mem_ctx) ir_if(operand(r0DDD).val);
                           exec_list *const f0DDC_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0DDC->then_instructions;

                              ir_variable *const r0DDE = body.make_temp(glsl_type::bool_type, "or_tmp");
                              /* IF CONDITION */
                              ir_expression *const r0DE0 = less(body.constant(2045u), r0D92);
                              ir_if *f0DDF = new(mem_ctx) ir_if(operand(r0DE0).val);
                              exec_list *const f0DDF_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0DDF->then_instructions;

                                 body.emit(assign(r0DDE, body.constant(true), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0DDF->else_instructions;

                                 ir_variable *const r0DE1 = body.make_temp(glsl_type::bool_type, "and_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0DE3 = equal(r0D92, body.constant(2045u));
                                 ir_if *f0DE2 = new(mem_ctx) ir_if(operand(r0DE3).val);
                                 exec_list *const f0DE2_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0DE2->then_instructions;

                                    ir_expression *const r0DE4 = equal(body.constant(2097151u), r0D93);
                                    ir_expression *const r0DE5 = equal(body.constant(4294967295u), r0D94);
                                    body.emit(assign(r0DE1, logic_and(r0DE4, r0DE5), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0DE2->else_instructions;

                                    body.emit(assign(r0DE1, body.constant(false), 0x01));


                                 body.instructions = f0DE2_parent_instructions;
                                 body.emit(f0DE2);

                                 /* END IF */

                                 ir_expression *const r0DE6 = nequal(r0DD9, body.constant(0u));
                                 body.emit(assign(r0DDE, logic_and(r0DE1, r0DE6), 0x01));


                              body.instructions = f0DDF_parent_instructions;
                              body.emit(f0DDF);

                              /* END IF */

                              /* IF CONDITION */
                              ir_if *f0DE7 = new(mem_ctx) ir_if(operand(r0DDE).val);
                              exec_list *const f0DE7_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0DE7->then_instructions;

                                 ir_variable *const r0DE8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r0DE8);
                                 ir_expression *const r0DE9 = lshift(r09E0, body.constant(int(31)));
                                 body.emit(assign(r0DE8, add(r0DE9, body.constant(2146435072u)), 0x01));

                                 body.emit(assign(r0DE8, body.constant(0u), 0x02));

                                 body.emit(assign(r0DD8, r0DE8, 0x03));

                                 body.emit(assign(r0DD7, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0DE7->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0DEB = less(r0D92, body.constant(0u));
                                 ir_if *f0DEA = new(mem_ctx) ir_if(operand(r0DEB).val);
                                 exec_list *const f0DEA_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0DEA->then_instructions;

                                    ir_variable *const r0DEC = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r0DEC, r0D95, 0x01));

                                    ir_variable *const r0DED = body.make_temp(glsl_type::int_type, "count");
                                    ir_expression *const r0DEE = neg(r0D92);
                                    body.emit(assign(r0DED, expr(ir_unop_u2i, r0DEE), 0x01));

                                    ir_variable *const r0DEF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r0DEF);
                                    ir_variable *const r0DF0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r0DF0);
                                    ir_variable *const r0DF1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r0DF1);
                                    ir_variable *const r0DF2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r0DF3 = neg(r0DED);
                                    body.emit(assign(r0DF2, bit_and(r0DF3, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0DF5 = equal(r0DED, body.constant(int(0)));
                                    ir_if *f0DF4 = new(mem_ctx) ir_if(operand(r0DF5).val);
                                    exec_list *const f0DF4_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0DF4->then_instructions;

                                       body.emit(assign(r0DEF, r0D95, 0x01));

                                       body.emit(assign(r0DF0, r0D94, 0x01));

                                       body.emit(assign(r0DF1, r0D93, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0DF4->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r0DF7 = less(r0DED, body.constant(int(32)));
                                       ir_if *f0DF6 = new(mem_ctx) ir_if(operand(r0DF7).val);
                                       exec_list *const f0DF6_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0DF6->then_instructions;

                                          body.emit(assign(r0DEF, lshift(r0D94, r0DF2), 0x01));

                                          ir_expression *const r0DF8 = lshift(r0D93, r0DF2);
                                          ir_expression *const r0DF9 = rshift(r0D94, r0DED);
                                          body.emit(assign(r0DF0, bit_or(r0DF8, r0DF9), 0x01));

                                          body.emit(assign(r0DF1, rshift(r0D93, r0DED), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0DF6->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r0DFB = equal(r0DED, body.constant(int(32)));
                                          ir_if *f0DFA = new(mem_ctx) ir_if(operand(r0DFB).val);
                                          exec_list *const f0DFA_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0DFA->then_instructions;

                                             body.emit(assign(r0DEF, r0D94, 0x01));

                                             body.emit(assign(r0DF0, r0D93, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0DFA->else_instructions;

                                             body.emit(assign(r0DEC, bit_or(r0D95, r0D94), 0x01));

                                             /* IF CONDITION */
                                             ir_expression *const r0DFD = less(r0DED, body.constant(int(64)));
                                             ir_if *f0DFC = new(mem_ctx) ir_if(operand(r0DFD).val);
                                             exec_list *const f0DFC_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f0DFC->then_instructions;

                                                body.emit(assign(r0DEF, lshift(r0D93, r0DF2), 0x01));

                                                ir_expression *const r0DFE = bit_and(r0DED, body.constant(int(31)));
                                                body.emit(assign(r0DF0, rshift(r0D93, r0DFE), 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f0DFC->else_instructions;

                                                ir_variable *const r0DFF = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                                /* IF CONDITION */
                                                ir_expression *const r0E01 = equal(r0DED, body.constant(int(64)));
                                                ir_if *f0E00 = new(mem_ctx) ir_if(operand(r0E01).val);
                                                exec_list *const f0E00_parent_instructions = body.instructions;

                                                   /* THEN INSTRUCTIONS */
                                                   body.instructions = &f0E00->then_instructions;

                                                   body.emit(assign(r0DFF, r0D93, 0x01));


                                                   /* ELSE INSTRUCTIONS */
                                                   body.instructions = &f0E00->else_instructions;

                                                   ir_expression *const r0E02 = nequal(r0D93, body.constant(0u));
                                                   ir_expression *const r0E03 = expr(ir_unop_b2i, r0E02);
                                                   body.emit(assign(r0DFF, expr(ir_unop_i2u, r0E03), 0x01));


                                                body.instructions = f0E00_parent_instructions;
                                                body.emit(f0E00);

                                                /* END IF */

                                                body.emit(assign(r0DEF, r0DFF, 0x01));

                                                body.emit(assign(r0DF0, body.constant(0u), 0x01));


                                             body.instructions = f0DFC_parent_instructions;
                                             body.emit(f0DFC);

                                             /* END IF */


                                          body.instructions = f0DFA_parent_instructions;
                                          body.emit(f0DFA);

                                          /* END IF */

                                          body.emit(assign(r0DF1, body.constant(0u), 0x01));


                                       body.instructions = f0DF6_parent_instructions;
                                       body.emit(f0DF6);

                                       /* END IF */

                                       ir_expression *const r0E04 = nequal(r0DEC, body.constant(0u));
                                       ir_expression *const r0E05 = expr(ir_unop_b2i, r0E04);
                                       ir_expression *const r0E06 = expr(ir_unop_i2u, r0E05);
                                       body.emit(assign(r0DEF, bit_or(r0DEF, r0E06), 0x01));


                                    body.instructions = f0DF4_parent_instructions;
                                    body.emit(f0DF4);

                                    /* END IF */

                                    body.emit(assign(r0DD4, r0DF1, 0x01));

                                    body.emit(assign(r0DD5, r0DF0, 0x01));

                                    body.emit(assign(r0DD6, r0DEF, 0x01));

                                    body.emit(assign(r0DD3, body.constant(0u), 0x01));

                                    ir_expression *const r0E07 = less(r0DEF, body.constant(0u));
                                    ir_expression *const r0E08 = expr(ir_unop_b2i, r0E07);
                                    body.emit(assign(r0DD9, expr(ir_unop_i2u, r0E08), 0x01));


                                 body.instructions = f0DEA_parent_instructions;
                                 body.emit(f0DEA);

                                 /* END IF */


                              body.instructions = f0DE7_parent_instructions;
                              body.emit(f0DE7);

                              /* END IF */


                           body.instructions = f0DDC_parent_instructions;
                           body.emit(f0DDC);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f0E09 = new(mem_ctx) ir_if(operand(r0DD7).val);
                           exec_list *const f0E09_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0E09->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0E0B = nequal(r0DD9, body.constant(0u));
                              ir_if *f0E0A = new(mem_ctx) ir_if(operand(r0E0B).val);
                              exec_list *const f0E0A_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0E0A->then_instructions;

                                 ir_variable *const r0E0C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r0E0C, add(r0DD5, body.constant(1u)), 0x01));

                                 ir_expression *const r0E0D = less(r0E0C, r0DD5);
                                 ir_expression *const r0E0E = expr(ir_unop_b2i, r0E0D);
                                 ir_expression *const r0E0F = expr(ir_unop_i2u, r0E0E);
                                 body.emit(assign(r0DD4, add(r0DD4, r0E0F), 0x01));

                                 ir_expression *const r0E10 = neg(r0DD6);
                                 ir_expression *const r0E11 = equal(r0DD6, r0E10);
                                 ir_expression *const r0E12 = expr(ir_unop_b2i, r0E11);
                                 ir_expression *const r0E13 = expr(ir_unop_i2u, r0E12);
                                 ir_expression *const r0E14 = bit_and(r0E13, body.constant(1u));
                                 ir_expression *const r0E15 = expr(ir_unop_bit_not, r0E14);
                                 body.emit(assign(r0DD5, bit_and(r0E0C, r0E15), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0E0A->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0E17 = bit_or(r0DD4, r0DD5);
                                 ir_expression *const r0E18 = equal(r0E17, body.constant(0u));
                                 ir_if *f0E16 = new(mem_ctx) ir_if(operand(r0E18).val);
                                 exec_list *const f0E16_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0E16->then_instructions;

                                    body.emit(assign(r0DD3, body.constant(0u), 0x01));


                                 body.instructions = f0E16_parent_instructions;
                                 body.emit(f0E16);

                                 /* END IF */


                              body.instructions = f0E0A_parent_instructions;
                              body.emit(f0E0A);

                              /* END IF */

                              ir_variable *const r0E19 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0E19);
                              ir_expression *const r0E1A = lshift(r09E0, body.constant(int(31)));
                              ir_expression *const r0E1B = lshift(r0DD3, body.constant(int(20)));
                              ir_expression *const r0E1C = add(r0E1A, r0E1B);
                              body.emit(assign(r0E19, add(r0E1C, r0DD4), 0x01));

                              body.emit(assign(r0E19, r0DD5, 0x02));

                              body.emit(assign(r0DD8, r0E19, 0x03));

                              body.emit(assign(r0DD7, body.constant(false), 0x01));


                           body.instructions = f0E09_parent_instructions;
                           body.emit(f0E09);

                           /* END IF */

                           body.emit(assign(r09E1, r0DD8, 0x03));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0D8A->else_instructions;

                           ir_variable *const r0E1D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0E1D);
                           body.emit(assign(r0E1D, body.constant(0u), 0x01));

                           body.emit(assign(r0E1D, body.constant(0u), 0x02));

                           body.emit(assign(r09E1, r0E1D, 0x03));


                        body.instructions = f0D8A_parent_instructions;
                        body.emit(f0D8A);

                        /* END IF */


                     body.instructions = f0CF7_parent_instructions;
                     body.emit(f0CF7);

                     /* END IF */


                  body.instructions = f0C64_parent_instructions;
                  body.emit(f0C64);

                  /* END IF */


               body.instructions = f0BD1_parent_instructions;
               body.emit(f0BD1);

               /* END IF */


            body.instructions = f0BAA_parent_instructions;
            body.emit(f0BAA);

            /* END IF */


         body.instructions = f0ACF_parent_instructions;
         body.emit(f0ACF);

         /* END IF */


      body.instructions = f09F8_parent_instructions;
      body.emit(f09F8);

      /* END IF */

      body.emit(assign(r0823, r09E1, 0x03));


   body.instructions = f0826_parent_instructions;
   body.emit(f0826);

   /* END IF */

   body.emit(ret(r0823));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
