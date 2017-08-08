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
fsign64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::uvec2_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r001E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r001E);
   ir_variable *const r001F = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0020 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "retval", ir_var_auto);
   body.emit(r0020);
   /* IF CONDITION */
   ir_expression *const r0022 = lshift(swizzle_y(r001E), body.constant(int(1)));
   ir_expression *const r0023 = bit_or(r0022, swizzle_x(r001E));
   ir_expression *const r0024 = equal(r0023, body.constant(0u));
   ir_if *f0021 = new(mem_ctx) ir_if(operand(r0024).val);
   exec_list *const f0021_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0021->then_instructions;

      body.emit(assign(r001F, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0021->else_instructions;

      body.emit(assign(r0020, body.constant(0u), 0x01));

      ir_expression *const r0025 = bit_and(swizzle_y(r001E), body.constant(2147483648u));
      body.emit(assign(r0020, bit_or(r0025, body.constant(1072693248u)), 0x02));

      body.emit(assign(r001F, r0020, 0x03));


   body.instructions = f0021_parent_instructions;
   body.emit(f0021);

   /* END IF */

   body.emit(ret(r001F));

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

   ir_variable *const r0026 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0026);
   ir_swizzle *const r0027 = swizzle_x(r0026);
   body.emit(ret(r0027));

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

   ir_variable *const r0028 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0028);
   ir_expression *const r0029 = bit_and(swizzle_y(r0028), body.constant(1048575u));
   body.emit(ret(r0029));

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

   ir_variable *const r002A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r002A);
   ir_expression *const r002B = rshift(swizzle_y(r002A), body.constant(int(20)));
   ir_expression *const r002C = bit_and(r002B, body.constant(2047u));
   ir_expression *const r002D = expr(ir_unop_u2i, r002C);
   body.emit(ret(r002D));

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

   ir_variable *const r002E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r002E);
   ir_variable *const r002F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r002F);
   ir_variable *const r0030 = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r0031 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r0031);
   ir_variable *const r0032 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r0032);
   ir_expression *const r0033 = rshift(swizzle_y(r002E), body.constant(int(20)));
   ir_expression *const r0034 = bit_and(r0033, body.constant(2047u));
   ir_expression *const r0035 = expr(ir_unop_u2i, r0034);
   ir_expression *const r0036 = equal(r0035, body.constant(int(2047)));
   ir_expression *const r0037 = bit_and(swizzle_y(r002E), body.constant(1048575u));
   ir_expression *const r0038 = bit_or(r0037, swizzle_x(r002E));
   ir_expression *const r0039 = nequal(r0038, body.constant(0u));
   body.emit(assign(r0032, logic_and(r0036, r0039), 0x01));

   ir_expression *const r003A = rshift(swizzle_y(r002F), body.constant(int(20)));
   ir_expression *const r003B = bit_and(r003A, body.constant(2047u));
   ir_expression *const r003C = expr(ir_unop_u2i, r003B);
   ir_expression *const r003D = equal(r003C, body.constant(int(2047)));
   ir_expression *const r003E = bit_and(swizzle_y(r002F), body.constant(1048575u));
   ir_expression *const r003F = bit_or(r003E, swizzle_x(r002F));
   ir_expression *const r0040 = nequal(r003F, body.constant(0u));
   body.emit(assign(r0031, logic_and(r003D, r0040), 0x01));

   /* IF CONDITION */
   ir_expression *const r0042 = logic_or(r0032, r0031);
   ir_if *f0041 = new(mem_ctx) ir_if(operand(r0042).val);
   exec_list *const f0041_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0041->then_instructions;

      body.emit(assign(r0030, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0041->else_instructions;

      ir_expression *const r0043 = equal(swizzle_x(r002E), swizzle_x(r002F));
      ir_expression *const r0044 = equal(swizzle_y(r002E), swizzle_y(r002F));
      ir_expression *const r0045 = equal(swizzle_x(r002E), body.constant(0u));
      ir_expression *const r0046 = bit_or(swizzle_y(r002E), swizzle_y(r002F));
      ir_expression *const r0047 = lshift(r0046, body.constant(int(1)));
      ir_expression *const r0048 = equal(r0047, body.constant(0u));
      ir_expression *const r0049 = logic_and(r0045, r0048);
      ir_expression *const r004A = logic_or(r0044, r0049);
      body.emit(assign(r0030, logic_and(r0043, r004A), 0x01));


   body.instructions = f0041_parent_instructions;
   body.emit(f0041);

   /* END IF */

   body.emit(ret(r0030));

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

   ir_variable *const r004B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r004B);
   ir_expression *const r004C = rshift(swizzle_y(r004B), body.constant(int(31)));
   body.emit(ret(r004C));

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

   ir_variable *const r004D = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r004D);
   ir_variable *const r004E = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r004E);
   ir_variable *const r004F = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r004F);
   ir_variable *const r0050 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0050);
   ir_expression *const r0051 = less(r004D, r004F);
   ir_expression *const r0052 = equal(r004D, r004F);
   ir_expression *const r0053 = lequal(r004E, r0050);
   ir_expression *const r0054 = logic_and(r0052, r0053);
   ir_expression *const r0055 = logic_or(r0051, r0054);
   body.emit(ret(r0055));

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

   ir_variable *const r0056 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0056);
   ir_variable *const r0057 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0057);
   ir_variable *const r0058 = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r0059 = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r0059);
   ir_variable *const r005A = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r005A);
   ir_expression *const r005B = rshift(swizzle_y(r0056), body.constant(int(20)));
   ir_expression *const r005C = bit_and(r005B, body.constant(2047u));
   ir_expression *const r005D = expr(ir_unop_u2i, r005C);
   ir_expression *const r005E = equal(r005D, body.constant(int(2047)));
   ir_expression *const r005F = bit_and(swizzle_y(r0056), body.constant(1048575u));
   ir_expression *const r0060 = bit_or(r005F, swizzle_x(r0056));
   ir_expression *const r0061 = nequal(r0060, body.constant(0u));
   body.emit(assign(r005A, logic_and(r005E, r0061), 0x01));

   ir_expression *const r0062 = rshift(swizzle_y(r0057), body.constant(int(20)));
   ir_expression *const r0063 = bit_and(r0062, body.constant(2047u));
   ir_expression *const r0064 = expr(ir_unop_u2i, r0063);
   ir_expression *const r0065 = equal(r0064, body.constant(int(2047)));
   ir_expression *const r0066 = bit_and(swizzle_y(r0057), body.constant(1048575u));
   ir_expression *const r0067 = bit_or(r0066, swizzle_x(r0057));
   ir_expression *const r0068 = nequal(r0067, body.constant(0u));
   body.emit(assign(r0059, logic_and(r0065, r0068), 0x01));

   /* IF CONDITION */
   ir_expression *const r006A = logic_or(r005A, r0059);
   ir_if *f0069 = new(mem_ctx) ir_if(operand(r006A).val);
   exec_list *const f0069_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0069->then_instructions;

      body.emit(assign(r0058, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0069->else_instructions;

      ir_variable *const r006B = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r006B, rshift(swizzle_y(r0056), body.constant(int(31))), 0x01));

      ir_variable *const r006C = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r006C, rshift(swizzle_y(r0057), body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r006E = nequal(r006B, r006C);
      ir_if *f006D = new(mem_ctx) ir_if(operand(r006E).val);
      exec_list *const f006D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f006D->then_instructions;

         ir_expression *const r006F = nequal(r006B, body.constant(0u));
         ir_expression *const r0070 = bit_or(swizzle_y(r0056), swizzle_y(r0057));
         ir_expression *const r0071 = lshift(r0070, body.constant(int(1)));
         ir_expression *const r0072 = bit_or(r0071, swizzle_x(r0056));
         ir_expression *const r0073 = bit_or(r0072, swizzle_x(r0057));
         ir_expression *const r0074 = equal(r0073, body.constant(0u));
         body.emit(assign(r0058, logic_or(r006F, r0074), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f006D->else_instructions;

         ir_variable *const r0075 = body.make_temp(glsl_type::bool_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0077 = nequal(r006B, body.constant(0u));
         ir_if *f0076 = new(mem_ctx) ir_if(operand(r0077).val);
         exec_list *const f0076_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0076->then_instructions;

            ir_expression *const r0078 = less(swizzle_y(r0057), swizzle_y(r0056));
            ir_expression *const r0079 = equal(swizzle_y(r0057), swizzle_y(r0056));
            ir_expression *const r007A = lequal(swizzle_x(r0057), swizzle_x(r0056));
            ir_expression *const r007B = logic_and(r0079, r007A);
            body.emit(assign(r0075, logic_or(r0078, r007B), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0076->else_instructions;

            ir_expression *const r007C = less(swizzle_y(r0056), swizzle_y(r0057));
            ir_expression *const r007D = equal(swizzle_y(r0056), swizzle_y(r0057));
            ir_expression *const r007E = lequal(swizzle_x(r0056), swizzle_x(r0057));
            ir_expression *const r007F = logic_and(r007D, r007E);
            body.emit(assign(r0075, logic_or(r007C, r007F), 0x01));


         body.instructions = f0076_parent_instructions;
         body.emit(f0076);

         /* END IF */

         body.emit(assign(r0058, r0075, 0x01));


      body.instructions = f006D_parent_instructions;
      body.emit(f006D);

      /* END IF */


   body.instructions = f0069_parent_instructions;
   body.emit(f0069);

   /* END IF */

   body.emit(ret(r0058));

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

   ir_variable *const r0080 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0080);
   ir_variable *const r0081 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0081);
   ir_variable *const r0082 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0082);
   ir_variable *const r0083 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0083);
   ir_expression *const r0084 = less(r0080, r0082);
   ir_expression *const r0085 = equal(r0080, r0082);
   ir_expression *const r0086 = less(r0081, r0083);
   ir_expression *const r0087 = logic_and(r0085, r0086);
   ir_expression *const r0088 = logic_or(r0084, r0087);
   body.emit(ret(r0088));

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

   ir_variable *const r0089 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0089);
   ir_variable *const r008A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r008A);
   ir_variable *const r008B = body.make_temp(glsl_type::bool_type, "return_value");
   ir_variable *const r008C = new(mem_ctx) ir_variable(glsl_type::bool_type, "isbNaN", ir_var_auto);
   body.emit(r008C);
   ir_variable *const r008D = new(mem_ctx) ir_variable(glsl_type::bool_type, "isaNaN", ir_var_auto);
   body.emit(r008D);
   ir_expression *const r008E = rshift(swizzle_y(r0089), body.constant(int(20)));
   ir_expression *const r008F = bit_and(r008E, body.constant(2047u));
   ir_expression *const r0090 = expr(ir_unop_u2i, r008F);
   ir_expression *const r0091 = equal(r0090, body.constant(int(2047)));
   ir_expression *const r0092 = bit_and(swizzle_y(r0089), body.constant(1048575u));
   ir_expression *const r0093 = bit_or(r0092, swizzle_x(r0089));
   ir_expression *const r0094 = nequal(r0093, body.constant(0u));
   body.emit(assign(r008D, logic_and(r0091, r0094), 0x01));

   ir_expression *const r0095 = rshift(swizzle_y(r008A), body.constant(int(20)));
   ir_expression *const r0096 = bit_and(r0095, body.constant(2047u));
   ir_expression *const r0097 = expr(ir_unop_u2i, r0096);
   ir_expression *const r0098 = equal(r0097, body.constant(int(2047)));
   ir_expression *const r0099 = bit_and(swizzle_y(r008A), body.constant(1048575u));
   ir_expression *const r009A = bit_or(r0099, swizzle_x(r008A));
   ir_expression *const r009B = nequal(r009A, body.constant(0u));
   body.emit(assign(r008C, logic_and(r0098, r009B), 0x01));

   /* IF CONDITION */
   ir_expression *const r009D = logic_or(r008D, r008C);
   ir_if *f009C = new(mem_ctx) ir_if(operand(r009D).val);
   exec_list *const f009C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f009C->then_instructions;

      body.emit(assign(r008B, body.constant(false), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f009C->else_instructions;

      ir_variable *const r009E = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r009E, rshift(swizzle_y(r0089), body.constant(int(31))), 0x01));

      ir_variable *const r009F = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
      body.emit(assign(r009F, rshift(swizzle_y(r008A), body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r00A1 = nequal(r009E, r009F);
      ir_if *f00A0 = new(mem_ctx) ir_if(operand(r00A1).val);
      exec_list *const f00A0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00A0->then_instructions;

         ir_expression *const r00A2 = nequal(r009E, body.constant(0u));
         ir_expression *const r00A3 = bit_or(swizzle_y(r0089), swizzle_y(r008A));
         ir_expression *const r00A4 = lshift(r00A3, body.constant(int(1)));
         ir_expression *const r00A5 = bit_or(r00A4, swizzle_x(r0089));
         ir_expression *const r00A6 = bit_or(r00A5, swizzle_x(r008A));
         ir_expression *const r00A7 = nequal(r00A6, body.constant(0u));
         body.emit(assign(r008B, logic_and(r00A2, r00A7), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00A0->else_instructions;

         ir_variable *const r00A8 = body.make_temp(glsl_type::bool_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r00AA = nequal(r009E, body.constant(0u));
         ir_if *f00A9 = new(mem_ctx) ir_if(operand(r00AA).val);
         exec_list *const f00A9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00A9->then_instructions;

            ir_expression *const r00AB = less(swizzle_y(r008A), swizzle_y(r0089));
            ir_expression *const r00AC = equal(swizzle_y(r008A), swizzle_y(r0089));
            ir_expression *const r00AD = less(swizzle_x(r008A), swizzle_x(r0089));
            ir_expression *const r00AE = logic_and(r00AC, r00AD);
            body.emit(assign(r00A8, logic_or(r00AB, r00AE), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00A9->else_instructions;

            ir_expression *const r00AF = less(swizzle_y(r0089), swizzle_y(r008A));
            ir_expression *const r00B0 = equal(swizzle_y(r0089), swizzle_y(r008A));
            ir_expression *const r00B1 = less(swizzle_x(r0089), swizzle_x(r008A));
            ir_expression *const r00B2 = logic_and(r00B0, r00B1);
            body.emit(assign(r00A8, logic_or(r00AF, r00B2), 0x01));


         body.instructions = f00A9_parent_instructions;
         body.emit(f00A9);

         /* END IF */

         body.emit(assign(r008B, r00A8, 0x01));


      body.instructions = f00A0_parent_instructions;
      body.emit(f00A0);

      /* END IF */


   body.instructions = f009C_parent_instructions;
   body.emit(f009C);

   /* END IF */

   body.emit(ret(r008B));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
