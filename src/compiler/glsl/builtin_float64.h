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
ir_function_signature *
add64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
   ir_factory body(&sig->body, mem_ctx);
   sig->is_defined = true;

   exec_list sig_parameters;

   ir_variable *const r00B3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00B3);
   ir_variable *const r00B4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00B4);
   ir_variable *const r00B5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r00B5);
   ir_variable *const r00B6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r00B6);
   ir_variable *const r00B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00B7);
   ir_variable *const r00B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00B8);
   ir_variable *const r00B9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r00B9, add(r00B4, r00B6), 0x01));

   body.emit(assign(r00B8, r00B9, 0x01));

   ir_expression *const r00BA = add(r00B3, r00B5);
   ir_expression *const r00BB = less(r00B9, r00B4);
   ir_expression *const r00BC = expr(ir_unop_b2i, r00BB);
   ir_expression *const r00BD = expr(ir_unop_i2u, r00BC);
   body.emit(assign(r00B7, add(r00BA, r00BD), 0x01));

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

   ir_variable *const r00BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00BE);
   ir_variable *const r00BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00BF);
   ir_variable *const r00C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r00C0);
   ir_variable *const r00C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r00C1);
   ir_variable *const r00C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C2);
   ir_variable *const r00C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C3);
   body.emit(assign(r00C3, sub(r00BF, r00C1), 0x01));

   ir_expression *const r00C4 = sub(r00BE, r00C0);
   ir_expression *const r00C5 = less(r00BF, r00C1);
   ir_expression *const r00C6 = expr(ir_unop_b2i, r00C5);
   ir_expression *const r00C7 = expr(ir_unop_i2u, r00C6);
   body.emit(assign(r00C2, sub(r00C4, r00C7), 0x01));

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

   ir_variable *const r00C8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00C8);
   ir_variable *const r00C9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00C9);
   ir_variable *const r00CA = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00CA);
   ir_variable *const r00CB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00CB);
   ir_variable *const r00CC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00CC);
   ir_variable *const r00CD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r00CD);
   ir_variable *const r00CE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r00CE);
   ir_variable *const r00CF = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r00D0 = neg(r00CA);
   body.emit(assign(r00CF, bit_and(r00D0, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00D2 = equal(r00CA, body.constant(int(0)));
   ir_if *f00D1 = new(mem_ctx) ir_if(operand(r00D2).val);
   exec_list *const f00D1_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00D1->then_instructions;

      body.emit(assign(r00CD, r00C9, 0x01));

      body.emit(assign(r00CE, r00C8, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00D1->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00D4 = less(r00CA, body.constant(int(32)));
      ir_if *f00D3 = new(mem_ctx) ir_if(operand(r00D4).val);
      exec_list *const f00D3_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00D3->then_instructions;

         ir_expression *const r00D5 = lshift(r00C8, r00CF);
         ir_expression *const r00D6 = rshift(r00C9, r00CA);
         ir_expression *const r00D7 = bit_or(r00D5, r00D6);
         ir_expression *const r00D8 = lshift(r00C9, r00CF);
         ir_expression *const r00D9 = nequal(r00D8, body.constant(0u));
         ir_expression *const r00DA = expr(ir_unop_b2i, r00D9);
         ir_expression *const r00DB = expr(ir_unop_i2u, r00DA);
         body.emit(assign(r00CD, bit_or(r00D7, r00DB), 0x01));

         body.emit(assign(r00CE, rshift(r00C8, r00CA), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00D3->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00DD = equal(r00CA, body.constant(int(32)));
         ir_if *f00DC = new(mem_ctx) ir_if(operand(r00DD).val);
         exec_list *const f00DC_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00DC->then_instructions;

            ir_expression *const r00DE = nequal(r00C9, body.constant(0u));
            ir_expression *const r00DF = expr(ir_unop_b2i, r00DE);
            ir_expression *const r00E0 = expr(ir_unop_i2u, r00DF);
            body.emit(assign(r00CD, bit_or(r00C8, r00E0), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00DC->else_instructions;

            /* IF CONDITION */
            ir_expression *const r00E2 = less(r00CA, body.constant(int(64)));
            ir_if *f00E1 = new(mem_ctx) ir_if(operand(r00E2).val);
            exec_list *const f00E1_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f00E1->then_instructions;

               ir_expression *const r00E3 = bit_and(r00CA, body.constant(int(31)));
               ir_expression *const r00E4 = rshift(r00C8, r00E3);
               ir_expression *const r00E5 = lshift(r00C8, r00CF);
               ir_expression *const r00E6 = bit_or(r00E5, r00C9);
               ir_expression *const r00E7 = nequal(r00E6, body.constant(0u));
               ir_expression *const r00E8 = expr(ir_unop_b2i, r00E7);
               ir_expression *const r00E9 = expr(ir_unop_i2u, r00E8);
               body.emit(assign(r00CD, bit_or(r00E4, r00E9), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f00E1->else_instructions;

               ir_expression *const r00EA = bit_or(r00C8, r00C9);
               ir_expression *const r00EB = nequal(r00EA, body.constant(0u));
               ir_expression *const r00EC = expr(ir_unop_b2i, r00EB);
               body.emit(assign(r00CD, expr(ir_unop_i2u, r00EC), 0x01));


            body.instructions = f00E1_parent_instructions;
            body.emit(f00E1);

            /* END IF */


         body.instructions = f00DC_parent_instructions;
         body.emit(f00DC);

         /* END IF */

         body.emit(assign(r00CE, body.constant(0u), 0x01));


      body.instructions = f00D3_parent_instructions;
      body.emit(f00D3);

      /* END IF */


   body.instructions = f00D1_parent_instructions;
   body.emit(f00D1);

   /* END IF */

   body.emit(assign(r00CC, r00CD, 0x01));

   body.emit(assign(r00CB, r00CE, 0x01));

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

   ir_variable *const r00ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00ED);
   ir_variable *const r00EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00EE);
   ir_variable *const r00EF = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r00EF);
   ir_variable *const r00F0 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00F0);
   ir_variable *const r00F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00F1);
   ir_variable *const r00F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00F2);
   ir_variable *const r00F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00F3);
   ir_variable *const r00F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
   body.emit(r00F4);
   ir_variable *const r00F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r00F5);
   ir_variable *const r00F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r00F6);
   ir_variable *const r00F7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r00F8 = neg(r00F0);
   body.emit(assign(r00F7, bit_and(r00F8, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00FA = equal(r00F0, body.constant(int(0)));
   ir_if *f00F9 = new(mem_ctx) ir_if(operand(r00FA).val);
   exec_list *const f00F9_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00F9->then_instructions;

      body.emit(assign(r00F4, r00EF, 0x01));

      body.emit(assign(r00F5, r00EE, 0x01));

      body.emit(assign(r00F6, r00ED, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00F9->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00FC = less(r00F0, body.constant(int(32)));
      ir_if *f00FB = new(mem_ctx) ir_if(operand(r00FC).val);
      exec_list *const f00FB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00FB->then_instructions;

         body.emit(assign(r00F4, lshift(r00EE, r00F7), 0x01));

         ir_expression *const r00FD = lshift(r00ED, r00F7);
         ir_expression *const r00FE = rshift(r00EE, r00F0);
         body.emit(assign(r00F5, bit_or(r00FD, r00FE), 0x01));

         body.emit(assign(r00F6, rshift(r00ED, r00F0), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00FB->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0100 = equal(r00F0, body.constant(int(32)));
         ir_if *f00FF = new(mem_ctx) ir_if(operand(r0100).val);
         exec_list *const f00FF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00FF->then_instructions;

            body.emit(assign(r00F4, r00EE, 0x01));

            body.emit(assign(r00F5, r00ED, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00FF->else_instructions;

            body.emit(assign(r00EF, bit_or(r00EF, r00EE), 0x01));

            /* IF CONDITION */
            ir_expression *const r0102 = less(r00F0, body.constant(int(64)));
            ir_if *f0101 = new(mem_ctx) ir_if(operand(r0102).val);
            exec_list *const f0101_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0101->then_instructions;

               body.emit(assign(r00F4, lshift(r00ED, r00F7), 0x01));

               ir_expression *const r0103 = bit_and(r00F0, body.constant(int(31)));
               body.emit(assign(r00F5, rshift(r00ED, r0103), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0101->else_instructions;

               ir_variable *const r0104 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0106 = equal(r00F0, body.constant(int(64)));
               ir_if *f0105 = new(mem_ctx) ir_if(operand(r0106).val);
               exec_list *const f0105_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0105->then_instructions;

                  body.emit(assign(r0104, r00ED, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0105->else_instructions;

                  ir_expression *const r0107 = nequal(r00ED, body.constant(0u));
                  ir_expression *const r0108 = expr(ir_unop_b2i, r0107);
                  body.emit(assign(r0104, expr(ir_unop_i2u, r0108), 0x01));


               body.instructions = f0105_parent_instructions;
               body.emit(f0105);

               /* END IF */

               body.emit(assign(r00F4, r0104, 0x01));

               body.emit(assign(r00F5, body.constant(0u), 0x01));


            body.instructions = f0101_parent_instructions;
            body.emit(f0101);

            /* END IF */


         body.instructions = f00FF_parent_instructions;
         body.emit(f00FF);

         /* END IF */

         body.emit(assign(r00F6, body.constant(0u), 0x01));


      body.instructions = f00FB_parent_instructions;
      body.emit(f00FB);

      /* END IF */

      ir_expression *const r0109 = nequal(r00EF, body.constant(0u));
      ir_expression *const r010A = expr(ir_unop_b2i, r0109);
      ir_expression *const r010B = expr(ir_unop_i2u, r010A);
      body.emit(assign(r00F4, bit_or(r00F4, r010B), 0x01));


   body.instructions = f00F9_parent_instructions;
   body.emit(f00F9);

   /* END IF */

   body.emit(assign(r00F3, r00F4, 0x01));

   body.emit(assign(r00F2, r00F5, 0x01));

   body.emit(assign(r00F1, r00F6, 0x01));

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

   ir_variable *const r010C = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r010C);
   ir_variable *const r010D = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r010D);
   ir_variable *const r010E = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r010E);
   ir_variable *const r010F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r010F);
   ir_variable *const r0110 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0110);
   body.emit(assign(r0110, lshift(r010D, r010E), 0x01));

   ir_variable *const r0111 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
   /* IF CONDITION */
   ir_expression *const r0113 = equal(r010E, body.constant(int(0)));
   ir_if *f0112 = new(mem_ctx) ir_if(operand(r0113).val);
   exec_list *const f0112_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0112->then_instructions;

      body.emit(assign(r0111, r010C, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0112->else_instructions;

      ir_expression *const r0114 = lshift(r010C, r010E);
      ir_expression *const r0115 = neg(r010E);
      ir_expression *const r0116 = bit_and(r0115, body.constant(int(31)));
      ir_expression *const r0117 = rshift(r010D, r0116);
      body.emit(assign(r0111, bit_or(r0114, r0117), 0x01));


   body.instructions = f0112_parent_instructions;
   body.emit(f0112);

   /* END IF */

   body.emit(assign(r010F, r0111, 0x01));

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

   ir_variable *const r0118 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0118);
   ir_variable *const r0119 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0119);
   ir_variable *const r011A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r011A);
   ir_variable *const r011B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r011B);
   ir_variable *const r011C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
   body.emit(r011C);
   ir_expression *const r011D = lshift(r0118, body.constant(int(31)));
   ir_expression *const r011E = expr(ir_unop_i2u, r0119);
   ir_expression *const r011F = lshift(r011E, body.constant(int(20)));
   ir_expression *const r0120 = add(r011D, r011F);
   body.emit(assign(r011C, add(r0120, r011A), 0x02));

   body.emit(assign(r011C, r011B, 0x01));

   body.emit(ret(r011C));

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

   ir_variable *const r0121 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0121);
   ir_variable *const r0122 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0122);
   ir_variable *const r0123 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0123);
   ir_variable *const r0124 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0124);
   ir_variable *const r0125 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_function_in);
   sig_parameters.push_tail(r0125);
   ir_variable *const r0126 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0126, body.constant(true), 0x01));

   ir_variable *const r0127 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0128 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r0128);
   ir_expression *const r0129 = expr(ir_unop_u2i, r0125);
   body.emit(assign(r0128, less(r0129, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r012B = lequal(body.constant(int(2045)), r0122);
   ir_if *f012A = new(mem_ctx) ir_if(operand(r012B).val);
   exec_list *const f012A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f012A->then_instructions;

      /* IF CONDITION */
      ir_expression *const r012D = less(body.constant(int(2045)), r0122);
      ir_expression *const r012E = equal(r0122, body.constant(int(2045)));
      ir_expression *const r012F = equal(body.constant(2097151u), r0123);
      ir_expression *const r0130 = equal(body.constant(4294967295u), r0124);
      ir_expression *const r0131 = logic_and(r012F, r0130);
      ir_expression *const r0132 = logic_and(r012E, r0131);
      ir_expression *const r0133 = logic_and(r0132, r0128);
      ir_expression *const r0134 = logic_or(r012D, r0133);
      ir_if *f012C = new(mem_ctx) ir_if(operand(r0134).val);
      exec_list *const f012C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f012C->then_instructions;

         ir_variable *const r0135 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0135);
         ir_expression *const r0136 = lshift(r0121, body.constant(int(31)));
         body.emit(assign(r0135, add(r0136, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0135, body.constant(0u), 0x01));

         body.emit(assign(r0127, r0135, 0x03));

         body.emit(assign(r0126, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f012C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0138 = less(r0122, body.constant(int(0)));
         ir_if *f0137 = new(mem_ctx) ir_if(operand(r0138).val);
         exec_list *const f0137_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0137->then_instructions;

            ir_variable *const r0139 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0139, r0125, 0x01));

            ir_variable *const r013A = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r013A, neg(r0122), 0x01));

            ir_variable *const r013B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r013B);
            ir_variable *const r013C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r013C);
            ir_variable *const r013D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r013D);
            ir_variable *const r013E = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r013F = neg(r013A);
            body.emit(assign(r013E, bit_and(r013F, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0141 = equal(r013A, body.constant(int(0)));
            ir_if *f0140 = new(mem_ctx) ir_if(operand(r0141).val);
            exec_list *const f0140_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0140->then_instructions;

               body.emit(assign(r013B, r0125, 0x01));

               body.emit(assign(r013C, r0124, 0x01));

               body.emit(assign(r013D, r0123, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0140->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0143 = less(r013A, body.constant(int(32)));
               ir_if *f0142 = new(mem_ctx) ir_if(operand(r0143).val);
               exec_list *const f0142_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0142->then_instructions;

                  body.emit(assign(r013B, lshift(r0124, r013E), 0x01));

                  ir_expression *const r0144 = lshift(r0123, r013E);
                  ir_expression *const r0145 = rshift(r0124, r013A);
                  body.emit(assign(r013C, bit_or(r0144, r0145), 0x01));

                  body.emit(assign(r013D, rshift(r0123, r013A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0142->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0147 = equal(r013A, body.constant(int(32)));
                  ir_if *f0146 = new(mem_ctx) ir_if(operand(r0147).val);
                  exec_list *const f0146_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0146->then_instructions;

                     body.emit(assign(r013B, r0124, 0x01));

                     body.emit(assign(r013C, r0123, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0146->else_instructions;

                     body.emit(assign(r0139, bit_or(r0125, r0124), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0149 = less(r013A, body.constant(int(64)));
                     ir_if *f0148 = new(mem_ctx) ir_if(operand(r0149).val);
                     exec_list *const f0148_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0148->then_instructions;

                        body.emit(assign(r013B, lshift(r0123, r013E), 0x01));

                        ir_expression *const r014A = bit_and(r013A, body.constant(int(31)));
                        body.emit(assign(r013C, rshift(r0123, r014A), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0148->else_instructions;

                        ir_variable *const r014B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r014D = equal(r013A, body.constant(int(64)));
                        ir_if *f014C = new(mem_ctx) ir_if(operand(r014D).val);
                        exec_list *const f014C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f014C->then_instructions;

                           body.emit(assign(r014B, r0123, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f014C->else_instructions;

                           ir_expression *const r014E = nequal(r0123, body.constant(0u));
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

               ir_expression *const r0150 = nequal(r0139, body.constant(0u));
               ir_expression *const r0151 = expr(ir_unop_b2i, r0150);
               ir_expression *const r0152 = expr(ir_unop_i2u, r0151);
               body.emit(assign(r013B, bit_or(r013B, r0152), 0x01));


            body.instructions = f0140_parent_instructions;
            body.emit(f0140);

            /* END IF */

            body.emit(assign(r0123, r013D, 0x01));

            body.emit(assign(r0124, r013C, 0x01));

            body.emit(assign(r0125, r013B, 0x01));

            body.emit(assign(r0122, body.constant(int(0)), 0x01));

            body.emit(assign(r0128, less(r013B, body.constant(0u)), 0x01));


         body.instructions = f0137_parent_instructions;
         body.emit(f0137);

         /* END IF */


      body.instructions = f012C_parent_instructions;
      body.emit(f012C);

      /* END IF */


   body.instructions = f012A_parent_instructions;
   body.emit(f012A);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0153 = new(mem_ctx) ir_if(operand(r0126).val);
   exec_list *const f0153_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0153->then_instructions;

      /* IF CONDITION */
      ir_if *f0154 = new(mem_ctx) ir_if(operand(r0128).val);
      exec_list *const f0154_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0154->then_instructions;

         ir_variable *const r0155 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0155, add(r0124, body.constant(1u)), 0x01));

         ir_expression *const r0156 = less(r0155, r0124);
         ir_expression *const r0157 = expr(ir_unop_b2i, r0156);
         ir_expression *const r0158 = expr(ir_unop_i2u, r0157);
         body.emit(assign(r0123, add(r0123, r0158), 0x01));

         ir_expression *const r0159 = equal(r0125, body.constant(0u));
         ir_expression *const r015A = expr(ir_unop_b2i, r0159);
         ir_expression *const r015B = expr(ir_unop_i2u, r015A);
         ir_expression *const r015C = add(r0125, r015B);
         ir_expression *const r015D = bit_and(r015C, body.constant(1u));
         ir_expression *const r015E = expr(ir_unop_bit_not, r015D);
         body.emit(assign(r0124, bit_and(r0155, r015E), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0154->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0160 = bit_or(r0123, r0124);
         ir_expression *const r0161 = equal(r0160, body.constant(0u));
         ir_if *f015F = new(mem_ctx) ir_if(operand(r0161).val);
         exec_list *const f015F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f015F->then_instructions;

            body.emit(assign(r0122, body.constant(int(0)), 0x01));


         body.instructions = f015F_parent_instructions;
         body.emit(f015F);

         /* END IF */


      body.instructions = f0154_parent_instructions;
      body.emit(f0154);

      /* END IF */

      ir_variable *const r0162 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0162);
      ir_expression *const r0163 = lshift(r0121, body.constant(int(31)));
      ir_expression *const r0164 = expr(ir_unop_i2u, r0122);
      ir_expression *const r0165 = lshift(r0164, body.constant(int(20)));
      ir_expression *const r0166 = add(r0163, r0165);
      body.emit(assign(r0162, add(r0166, r0123), 0x02));

      body.emit(assign(r0162, r0124, 0x01));

      body.emit(assign(r0127, r0162, 0x03));

      body.emit(assign(r0126, body.constant(false), 0x01));


   body.instructions = f0153_parent_instructions;
   body.emit(f0153);

   /* END IF */

   body.emit(ret(r0127));

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

   ir_variable *const r0167 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0167);
   ir_variable *const r0168 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0169 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0169);
   /* IF CONDITION */
   ir_expression *const r016B = equal(r0167, body.constant(0u));
   ir_if *f016A = new(mem_ctx) ir_if(operand(r016B).val);
   exec_list *const f016A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f016A->then_instructions;

      body.emit(assign(r0168, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f016A->else_instructions;

      body.emit(assign(r0169, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r016D = bit_and(r0167, body.constant(4294901760u));
      ir_expression *const r016E = equal(r016D, body.constant(0u));
      ir_if *f016C = new(mem_ctx) ir_if(operand(r016E).val);
      exec_list *const f016C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f016C->then_instructions;

         body.emit(assign(r0169, body.constant(int(16)), 0x01));

         body.emit(assign(r0167, lshift(r0167, body.constant(int(16))), 0x01));


      body.instructions = f016C_parent_instructions;
      body.emit(f016C);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0170 = bit_and(r0167, body.constant(4278190080u));
      ir_expression *const r0171 = equal(r0170, body.constant(0u));
      ir_if *f016F = new(mem_ctx) ir_if(operand(r0171).val);
      exec_list *const f016F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f016F->then_instructions;

         body.emit(assign(r0169, add(r0169, body.constant(int(8))), 0x01));

         body.emit(assign(r0167, lshift(r0167, body.constant(int(8))), 0x01));


      body.instructions = f016F_parent_instructions;
      body.emit(f016F);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0173 = bit_and(r0167, body.constant(4026531840u));
      ir_expression *const r0174 = equal(r0173, body.constant(0u));
      ir_if *f0172 = new(mem_ctx) ir_if(operand(r0174).val);
      exec_list *const f0172_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0172->then_instructions;

         body.emit(assign(r0169, add(r0169, body.constant(int(4))), 0x01));

         body.emit(assign(r0167, lshift(r0167, body.constant(int(4))), 0x01));


      body.instructions = f0172_parent_instructions;
      body.emit(f0172);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0176 = bit_and(r0167, body.constant(3221225472u));
      ir_expression *const r0177 = equal(r0176, body.constant(0u));
      ir_if *f0175 = new(mem_ctx) ir_if(operand(r0177).val);
      exec_list *const f0175_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0175->then_instructions;

         body.emit(assign(r0169, add(r0169, body.constant(int(2))), 0x01));

         body.emit(assign(r0167, lshift(r0167, body.constant(int(2))), 0x01));


      body.instructions = f0175_parent_instructions;
      body.emit(f0175);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0179 = bit_and(r0167, body.constant(2147483648u));
      ir_expression *const r017A = equal(r0179, body.constant(0u));
      ir_if *f0178 = new(mem_ctx) ir_if(operand(r017A).val);
      exec_list *const f0178_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0178->then_instructions;

         body.emit(assign(r0169, add(r0169, body.constant(int(1))), 0x01));


      body.instructions = f0178_parent_instructions;
      body.emit(f0178);

      /* END IF */

      body.emit(assign(r0168, r0169, 0x01));


   body.instructions = f016A_parent_instructions;
   body.emit(f016A);

   /* END IF */

   body.emit(ret(r0168));

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

   ir_variable *const r017B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r017B);
   ir_variable *const r017C = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r017C);
   ir_variable *const r017D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r017D);
   ir_variable *const r017E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r017E);
   ir_variable *const r017F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r017F);
   ir_variable *const r0180 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0180);
   /* IF CONDITION */
   ir_expression *const r0182 = equal(r017D, body.constant(0u));
   ir_if *f0181 = new(mem_ctx) ir_if(operand(r0182).val);
   exec_list *const f0181_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0181->then_instructions;

      body.emit(assign(r017D, r017E, 0x01));

      body.emit(assign(r017E, body.constant(0u), 0x01));

      body.emit(assign(r017C, add(r017C, body.constant(int(-32))), 0x01));


   body.instructions = f0181_parent_instructions;
   body.emit(f0181);

   /* END IF */

   ir_variable *const r0183 = body.make_temp(glsl_type::uint_type, "a");
   body.emit(assign(r0183, r017D, 0x01));

   ir_variable *const r0184 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0185 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0185);
   /* IF CONDITION */
   ir_expression *const r0187 = equal(r017D, body.constant(0u));
   ir_if *f0186 = new(mem_ctx) ir_if(operand(r0187).val);
   exec_list *const f0186_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0186->then_instructions;

      body.emit(assign(r0184, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0186->else_instructions;

      body.emit(assign(r0185, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r0189 = bit_and(r017D, body.constant(4294901760u));
      ir_expression *const r018A = equal(r0189, body.constant(0u));
      ir_if *f0188 = new(mem_ctx) ir_if(operand(r018A).val);
      exec_list *const f0188_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0188->then_instructions;

         body.emit(assign(r0185, body.constant(int(16)), 0x01));

         body.emit(assign(r0183, lshift(r017D, body.constant(int(16))), 0x01));


      body.instructions = f0188_parent_instructions;
      body.emit(f0188);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r018C = bit_and(r0183, body.constant(4278190080u));
      ir_expression *const r018D = equal(r018C, body.constant(0u));
      ir_if *f018B = new(mem_ctx) ir_if(operand(r018D).val);
      exec_list *const f018B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f018B->then_instructions;

         body.emit(assign(r0185, add(r0185, body.constant(int(8))), 0x01));

         body.emit(assign(r0183, lshift(r0183, body.constant(int(8))), 0x01));


      body.instructions = f018B_parent_instructions;
      body.emit(f018B);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r018F = bit_and(r0183, body.constant(4026531840u));
      ir_expression *const r0190 = equal(r018F, body.constant(0u));
      ir_if *f018E = new(mem_ctx) ir_if(operand(r0190).val);
      exec_list *const f018E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f018E->then_instructions;

         body.emit(assign(r0185, add(r0185, body.constant(int(4))), 0x01));

         body.emit(assign(r0183, lshift(r0183, body.constant(int(4))), 0x01));


      body.instructions = f018E_parent_instructions;
      body.emit(f018E);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0192 = bit_and(r0183, body.constant(3221225472u));
      ir_expression *const r0193 = equal(r0192, body.constant(0u));
      ir_if *f0191 = new(mem_ctx) ir_if(operand(r0193).val);
      exec_list *const f0191_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0191->then_instructions;

         body.emit(assign(r0185, add(r0185, body.constant(int(2))), 0x01));

         body.emit(assign(r0183, lshift(r0183, body.constant(int(2))), 0x01));


      body.instructions = f0191_parent_instructions;
      body.emit(f0191);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0195 = bit_and(r0183, body.constant(2147483648u));
      ir_expression *const r0196 = equal(r0195, body.constant(0u));
      ir_if *f0194 = new(mem_ctx) ir_if(operand(r0196).val);
      exec_list *const f0194_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0194->then_instructions;

         body.emit(assign(r0185, add(r0185, body.constant(int(1))), 0x01));


      body.instructions = f0194_parent_instructions;
      body.emit(f0194);

      /* END IF */

      body.emit(assign(r0184, r0185, 0x01));


   body.instructions = f0186_parent_instructions;
   body.emit(f0186);

   /* END IF */

   body.emit(assign(r0180, add(r0184, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0198 = lequal(body.constant(int(0)), r0180);
   ir_if *f0197 = new(mem_ctx) ir_if(operand(r0198).val);
   exec_list *const f0197_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0197->then_instructions;

      body.emit(assign(r017F, body.constant(0u), 0x01));

      ir_variable *const r0199 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0199, lshift(r017E, r0180), 0x01));

      ir_variable *const r019A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r019C = equal(r0180, body.constant(int(0)));
      ir_if *f019B = new(mem_ctx) ir_if(operand(r019C).val);
      exec_list *const f019B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f019B->then_instructions;

         body.emit(assign(r019A, r017D, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f019B->else_instructions;

         ir_expression *const r019D = lshift(r017D, r0180);
         ir_expression *const r019E = neg(r0180);
         ir_expression *const r019F = bit_and(r019E, body.constant(int(31)));
         ir_expression *const r01A0 = rshift(r017E, r019F);
         body.emit(assign(r019A, bit_or(r019D, r01A0), 0x01));


      body.instructions = f019B_parent_instructions;
      body.emit(f019B);

      /* END IF */

      body.emit(assign(r017D, r019A, 0x01));

      body.emit(assign(r017E, r0199, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0197->else_instructions;

      ir_variable *const r01A1 = body.make_temp(glsl_type::uint_type, "a2");
      body.emit(assign(r01A1, body.constant(0u), 0x01));

      ir_variable *const r01A2 = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r01A2, neg(r0180), 0x01));

      ir_variable *const r01A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
      body.emit(r01A3);
      ir_variable *const r01A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r01A4);
      ir_variable *const r01A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r01A5);
      ir_variable *const r01A6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r01A7 = neg(r01A2);
      body.emit(assign(r01A6, bit_and(r01A7, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r01A9 = equal(r01A2, body.constant(int(0)));
      ir_if *f01A8 = new(mem_ctx) ir_if(operand(r01A9).val);
      exec_list *const f01A8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01A8->then_instructions;

         body.emit(assign(r01A3, r01A1, 0x01));

         body.emit(assign(r01A4, r017E, 0x01));

         body.emit(assign(r01A5, r017D, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01A8->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01AB = less(r01A2, body.constant(int(32)));
         ir_if *f01AA = new(mem_ctx) ir_if(operand(r01AB).val);
         exec_list *const f01AA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01AA->then_instructions;

            body.emit(assign(r01A3, lshift(r017E, r01A6), 0x01));

            ir_expression *const r01AC = lshift(r017D, r01A6);
            ir_expression *const r01AD = rshift(r017E, r01A2);
            body.emit(assign(r01A4, bit_or(r01AC, r01AD), 0x01));

            body.emit(assign(r01A5, rshift(r017D, r01A2), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f01AA->else_instructions;

            /* IF CONDITION */
            ir_expression *const r01AF = equal(r01A2, body.constant(int(32)));
            ir_if *f01AE = new(mem_ctx) ir_if(operand(r01AF).val);
            exec_list *const f01AE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01AE->then_instructions;

               body.emit(assign(r01A3, r017E, 0x01));

               body.emit(assign(r01A4, r017D, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01AE->else_instructions;

               body.emit(assign(r01A1, bit_or(body.constant(0u), r017E), 0x01));

               /* IF CONDITION */
               ir_expression *const r01B1 = less(r01A2, body.constant(int(64)));
               ir_if *f01B0 = new(mem_ctx) ir_if(operand(r01B1).val);
               exec_list *const f01B0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f01B0->then_instructions;

                  body.emit(assign(r01A3, lshift(r017D, r01A6), 0x01));

                  ir_expression *const r01B2 = bit_and(r01A2, body.constant(int(31)));
                  body.emit(assign(r01A4, rshift(r017D, r01B2), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f01B0->else_instructions;

                  ir_variable *const r01B3 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r01B5 = equal(r01A2, body.constant(int(64)));
                  ir_if *f01B4 = new(mem_ctx) ir_if(operand(r01B5).val);
                  exec_list *const f01B4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f01B4->then_instructions;

                     body.emit(assign(r01B3, r017D, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f01B4->else_instructions;

                     ir_expression *const r01B6 = nequal(r017D, body.constant(0u));
                     ir_expression *const r01B7 = expr(ir_unop_b2i, r01B6);
                     body.emit(assign(r01B3, expr(ir_unop_i2u, r01B7), 0x01));


                  body.instructions = f01B4_parent_instructions;
                  body.emit(f01B4);

                  /* END IF */

                  body.emit(assign(r01A3, r01B3, 0x01));

                  body.emit(assign(r01A4, body.constant(0u), 0x01));


               body.instructions = f01B0_parent_instructions;
               body.emit(f01B0);

               /* END IF */


            body.instructions = f01AE_parent_instructions;
            body.emit(f01AE);

            /* END IF */

            body.emit(assign(r01A5, body.constant(0u), 0x01));


         body.instructions = f01AA_parent_instructions;
         body.emit(f01AA);

         /* END IF */

         ir_expression *const r01B8 = nequal(r01A1, body.constant(0u));
         ir_expression *const r01B9 = expr(ir_unop_b2i, r01B8);
         ir_expression *const r01BA = expr(ir_unop_i2u, r01B9);
         body.emit(assign(r01A3, bit_or(r01A3, r01BA), 0x01));


      body.instructions = f01A8_parent_instructions;
      body.emit(f01A8);

      /* END IF */

      body.emit(assign(r017D, r01A5, 0x01));

      body.emit(assign(r017E, r01A4, 0x01));

      body.emit(assign(r017F, r01A3, 0x01));


   body.instructions = f0197_parent_instructions;
   body.emit(f0197);

   /* END IF */

   body.emit(assign(r017C, sub(r017C, r0180), 0x01));

   ir_variable *const r01BB = body.make_temp(glsl_type::int_type, "zExp");
   body.emit(assign(r01BB, r017C, 0x01));

   ir_variable *const r01BC = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r01BC, r017D, 0x01));

   ir_variable *const r01BD = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r01BD, r017E, 0x01));

   ir_variable *const r01BE = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r01BE, r017F, 0x01));

   ir_variable *const r01BF = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01BF, body.constant(true), 0x01));

   ir_variable *const r01C0 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01C1 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r01C1);
   ir_expression *const r01C2 = expr(ir_unop_u2i, r017F);
   body.emit(assign(r01C1, less(r01C2, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r01C4 = lequal(body.constant(int(2045)), r017C);
   ir_if *f01C3 = new(mem_ctx) ir_if(operand(r01C4).val);
   exec_list *const f01C3_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01C3->then_instructions;

      /* IF CONDITION */
      ir_expression *const r01C6 = less(body.constant(int(2045)), r017C);
      ir_expression *const r01C7 = equal(r017C, body.constant(int(2045)));
      ir_expression *const r01C8 = equal(body.constant(2097151u), r017D);
      ir_expression *const r01C9 = equal(body.constant(4294967295u), r017E);
      ir_expression *const r01CA = logic_and(r01C8, r01C9);
      ir_expression *const r01CB = logic_and(r01C7, r01CA);
      ir_expression *const r01CC = logic_and(r01CB, r01C1);
      ir_expression *const r01CD = logic_or(r01C6, r01CC);
      ir_if *f01C5 = new(mem_ctx) ir_if(operand(r01CD).val);
      exec_list *const f01C5_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01C5->then_instructions;

         ir_variable *const r01CE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r01CE);
         ir_expression *const r01CF = lshift(r017B, body.constant(int(31)));
         body.emit(assign(r01CE, add(r01CF, body.constant(2146435072u)), 0x02));

         body.emit(assign(r01CE, body.constant(0u), 0x01));

         body.emit(assign(r01C0, r01CE, 0x03));

         body.emit(assign(r01BF, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01C5->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01D1 = less(r017C, body.constant(int(0)));
         ir_if *f01D0 = new(mem_ctx) ir_if(operand(r01D1).val);
         exec_list *const f01D0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01D0->then_instructions;

            ir_variable *const r01D2 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r01D2, r017F, 0x01));

            ir_variable *const r01D3 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r01D3, neg(r017C), 0x01));

            ir_variable *const r01D4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r01D4);
            ir_variable *const r01D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r01D5);
            ir_variable *const r01D6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r01D6);
            ir_variable *const r01D7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r01D8 = neg(r01D3);
            body.emit(assign(r01D7, bit_and(r01D8, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r01DA = equal(r01D3, body.constant(int(0)));
            ir_if *f01D9 = new(mem_ctx) ir_if(operand(r01DA).val);
            exec_list *const f01D9_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01D9->then_instructions;

               body.emit(assign(r01D4, r017F, 0x01));

               body.emit(assign(r01D5, r017E, 0x01));

               body.emit(assign(r01D6, r017D, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01D9->else_instructions;

               /* IF CONDITION */
               ir_expression *const r01DC = less(r01D3, body.constant(int(32)));
               ir_if *f01DB = new(mem_ctx) ir_if(operand(r01DC).val);
               exec_list *const f01DB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f01DB->then_instructions;

                  body.emit(assign(r01D4, lshift(r017E, r01D7), 0x01));

                  ir_expression *const r01DD = lshift(r017D, r01D7);
                  ir_expression *const r01DE = rshift(r017E, r01D3);
                  body.emit(assign(r01D5, bit_or(r01DD, r01DE), 0x01));

                  body.emit(assign(r01D6, rshift(r017D, r01D3), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f01DB->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r01E0 = equal(r01D3, body.constant(int(32)));
                  ir_if *f01DF = new(mem_ctx) ir_if(operand(r01E0).val);
                  exec_list *const f01DF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f01DF->then_instructions;

                     body.emit(assign(r01D4, r017E, 0x01));

                     body.emit(assign(r01D5, r017D, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f01DF->else_instructions;

                     body.emit(assign(r01D2, bit_or(r017F, r017E), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r01E2 = less(r01D3, body.constant(int(64)));
                     ir_if *f01E1 = new(mem_ctx) ir_if(operand(r01E2).val);
                     exec_list *const f01E1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f01E1->then_instructions;

                        body.emit(assign(r01D4, lshift(r017D, r01D7), 0x01));

                        ir_expression *const r01E3 = bit_and(r01D3, body.constant(int(31)));
                        body.emit(assign(r01D5, rshift(r017D, r01E3), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f01E1->else_instructions;

                        ir_variable *const r01E4 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r01E6 = equal(r01D3, body.constant(int(64)));
                        ir_if *f01E5 = new(mem_ctx) ir_if(operand(r01E6).val);
                        exec_list *const f01E5_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f01E5->then_instructions;

                           body.emit(assign(r01E4, r017D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f01E5->else_instructions;

                           ir_expression *const r01E7 = nequal(r017D, body.constant(0u));
                           ir_expression *const r01E8 = expr(ir_unop_b2i, r01E7);
                           body.emit(assign(r01E4, expr(ir_unop_i2u, r01E8), 0x01));


                        body.instructions = f01E5_parent_instructions;
                        body.emit(f01E5);

                        /* END IF */

                        body.emit(assign(r01D4, r01E4, 0x01));

                        body.emit(assign(r01D5, body.constant(0u), 0x01));


                     body.instructions = f01E1_parent_instructions;
                     body.emit(f01E1);

                     /* END IF */


                  body.instructions = f01DF_parent_instructions;
                  body.emit(f01DF);

                  /* END IF */

                  body.emit(assign(r01D6, body.constant(0u), 0x01));


               body.instructions = f01DB_parent_instructions;
               body.emit(f01DB);

               /* END IF */

               ir_expression *const r01E9 = nequal(r01D2, body.constant(0u));
               ir_expression *const r01EA = expr(ir_unop_b2i, r01E9);
               ir_expression *const r01EB = expr(ir_unop_i2u, r01EA);
               body.emit(assign(r01D4, bit_or(r01D4, r01EB), 0x01));


            body.instructions = f01D9_parent_instructions;
            body.emit(f01D9);

            /* END IF */

            body.emit(assign(r01BC, r01D6, 0x01));

            body.emit(assign(r01BD, r01D5, 0x01));

            body.emit(assign(r01BE, r01D4, 0x01));

            body.emit(assign(r01BB, body.constant(int(0)), 0x01));

            body.emit(assign(r01C1, less(r01D4, body.constant(0u)), 0x01));


         body.instructions = f01D0_parent_instructions;
         body.emit(f01D0);

         /* END IF */


      body.instructions = f01C5_parent_instructions;
      body.emit(f01C5);

      /* END IF */


   body.instructions = f01C3_parent_instructions;
   body.emit(f01C3);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01EC = new(mem_ctx) ir_if(operand(r01BF).val);
   exec_list *const f01EC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01EC->then_instructions;

      /* IF CONDITION */
      ir_if *f01ED = new(mem_ctx) ir_if(operand(r01C1).val);
      exec_list *const f01ED_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01ED->then_instructions;

         ir_variable *const r01EE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01EE, add(r01BD, body.constant(1u)), 0x01));

         ir_expression *const r01EF = less(r01EE, r01BD);
         ir_expression *const r01F0 = expr(ir_unop_b2i, r01EF);
         ir_expression *const r01F1 = expr(ir_unop_i2u, r01F0);
         body.emit(assign(r01BC, add(r01BC, r01F1), 0x01));

         ir_expression *const r01F2 = equal(r01BE, body.constant(0u));
         ir_expression *const r01F3 = expr(ir_unop_b2i, r01F2);
         ir_expression *const r01F4 = expr(ir_unop_i2u, r01F3);
         ir_expression *const r01F5 = add(r01BE, r01F4);
         ir_expression *const r01F6 = bit_and(r01F5, body.constant(1u));
         ir_expression *const r01F7 = expr(ir_unop_bit_not, r01F6);
         body.emit(assign(r01BD, bit_and(r01EE, r01F7), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01ED->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01F9 = bit_or(r01BC, r01BD);
         ir_expression *const r01FA = equal(r01F9, body.constant(0u));
         ir_if *f01F8 = new(mem_ctx) ir_if(operand(r01FA).val);
         exec_list *const f01F8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01F8->then_instructions;

            body.emit(assign(r01BB, body.constant(int(0)), 0x01));


         body.instructions = f01F8_parent_instructions;
         body.emit(f01F8);

         /* END IF */


      body.instructions = f01ED_parent_instructions;
      body.emit(f01ED);

      /* END IF */

      ir_variable *const r01FB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r01FB);
      ir_expression *const r01FC = lshift(r017B, body.constant(int(31)));
      ir_expression *const r01FD = expr(ir_unop_i2u, r01BB);
      ir_expression *const r01FE = lshift(r01FD, body.constant(int(20)));
      ir_expression *const r01FF = add(r01FC, r01FE);
      body.emit(assign(r01FB, add(r01FF, r01BC), 0x02));

      body.emit(assign(r01FB, r01BD, 0x01));

      body.emit(assign(r01C0, r01FB, 0x03));

      body.emit(assign(r01BF, body.constant(false), 0x01));


   body.instructions = f01EC_parent_instructions;
   body.emit(f01EC);

   /* END IF */

   body.emit(ret(r01C0));

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

   ir_variable *const r0200 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0200);
   ir_variable *const r0201 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0201);
   ir_variable *const r0202 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0203 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r0204 = lshift(swizzle_y(r0200), body.constant(int(1)));
   ir_expression *const r0205 = lequal(body.constant(4292870144u), r0204);
   ir_expression *const r0206 = nequal(swizzle_x(r0200), body.constant(0u));
   ir_expression *const r0207 = bit_and(swizzle_y(r0200), body.constant(1048575u));
   ir_expression *const r0208 = nequal(r0207, body.constant(0u));
   ir_expression *const r0209 = logic_or(r0206, r0208);
   body.emit(assign(r0203, logic_and(r0205, r0209), 0x01));

   ir_variable *const r020A = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r020B = lshift(swizzle_y(r0201), body.constant(int(1)));
   ir_expression *const r020C = lequal(body.constant(4292870144u), r020B);
   ir_expression *const r020D = nequal(swizzle_x(r0201), body.constant(0u));
   ir_expression *const r020E = bit_and(swizzle_y(r0201), body.constant(1048575u));
   ir_expression *const r020F = nequal(r020E, body.constant(0u));
   ir_expression *const r0210 = logic_or(r020D, r020F);
   body.emit(assign(r020A, logic_and(r020C, r0210), 0x01));

   body.emit(assign(r0200, bit_or(swizzle_y(r0200), body.constant(524288u)), 0x02));

   body.emit(assign(r0201, bit_or(swizzle_y(r0201), body.constant(524288u)), 0x02));

   /* IF CONDITION */
   ir_if *f0211 = new(mem_ctx) ir_if(operand(r0203).val);
   exec_list *const f0211_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0211->then_instructions;

      ir_variable *const r0212 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
      /* IF CONDITION */
      ir_if *f0213 = new(mem_ctx) ir_if(operand(r020A).val);
      exec_list *const f0213_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0213->then_instructions;

         body.emit(assign(r0212, r0201, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0213->else_instructions;

         body.emit(assign(r0212, r0200, 0x03));


      body.instructions = f0213_parent_instructions;
      body.emit(f0213);

      /* END IF */

      body.emit(assign(r0202, r0212, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0211->else_instructions;

      body.emit(assign(r0202, r0201, 0x03));


   body.instructions = f0211_parent_instructions;
   body.emit(f0211);

   /* END IF */

   body.emit(ret(r0202));

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

   ir_variable *const r0214 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0214);
   ir_variable *const r0215 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0215);
   ir_variable *const r0216 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0216, body.constant(true), 0x01));

   ir_variable *const r0217 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0218 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0218);
   ir_variable *const r0219 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0219, rshift(swizzle_y(r0214), body.constant(int(31))), 0x01));

   body.emit(assign(r0218, r0219, 0x01));

   ir_variable *const r021A = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r021A, rshift(swizzle_y(r0215), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r021C = equal(r0219, r021A);
   ir_if *f021B = new(mem_ctx) ir_if(operand(r021C).val);
   exec_list *const f021B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f021B->then_instructions;

      ir_variable *const r021D = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r021D);
      ir_variable *const r021E = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r021E);
      ir_variable *const r021F = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r021F);
      ir_variable *const r0220 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r0220);
      ir_variable *const r0221 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r0221);
      ir_variable *const r0222 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r0222);
      ir_variable *const r0223 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r0223);
      ir_variable *const r0224 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
      body.emit(r0224);
      body.emit(assign(r0224, body.constant(0u), 0x01));

      body.emit(assign(r0223, body.constant(0u), 0x01));

      ir_variable *const r0225 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r0225, swizzle_x(r0214), 0x01));

      body.emit(assign(r0221, r0225, 0x01));

      ir_variable *const r0226 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r0226, bit_and(swizzle_y(r0214), body.constant(1048575u)), 0x01));

      body.emit(assign(r0220, r0226, 0x01));

      ir_variable *const r0227 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r0227, swizzle_x(r0215), 0x01));

      body.emit(assign(r021F, r0227, 0x01));

      ir_variable *const r0228 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r0228, bit_and(swizzle_y(r0215), body.constant(1048575u)), 0x01));

      body.emit(assign(r021E, r0228, 0x01));

      ir_variable *const r0229 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r022A = rshift(swizzle_y(r0214), body.constant(int(20)));
      ir_expression *const r022B = bit_and(r022A, body.constant(2047u));
      body.emit(assign(r0229, expr(ir_unop_u2i, r022B), 0x01));

      ir_variable *const r022C = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r022D = rshift(swizzle_y(r0215), body.constant(int(20)));
      ir_expression *const r022E = bit_and(r022D, body.constant(2047u));
      body.emit(assign(r022C, expr(ir_unop_u2i, r022E), 0x01));

      ir_variable *const r022F = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r022F, sub(r0229, r022C), 0x01));

      body.emit(assign(r021D, r022F, 0x01));

      /* IF CONDITION */
      ir_expression *const r0231 = less(body.constant(int(0)), r022F);
      ir_if *f0230 = new(mem_ctx) ir_if(operand(r0231).val);
      exec_list *const f0230_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0230->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0233 = equal(r0229, body.constant(int(2047)));
         ir_if *f0232 = new(mem_ctx) ir_if(operand(r0233).val);
         exec_list *const f0232_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0232->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0235 = bit_or(r0226, swizzle_x(r0214));
            ir_expression *const r0236 = nequal(r0235, body.constant(0u));
            ir_if *f0234 = new(mem_ctx) ir_if(operand(r0236).val);
            exec_list *const f0234_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0234->then_instructions;

               ir_variable *const r0237 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0237, swizzle_x(r0214), 0x01));

               ir_variable *const r0238 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0238, swizzle_x(r0215), 0x01));

               ir_variable *const r0239 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r023A = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r023B = lshift(swizzle_y(r0215), body.constant(int(1)));
               ir_expression *const r023C = lequal(body.constant(4292870144u), r023B);
               ir_expression *const r023D = nequal(swizzle_x(r0215), body.constant(0u));
               ir_expression *const r023E = bit_and(swizzle_y(r0215), body.constant(1048575u));
               ir_expression *const r023F = nequal(r023E, body.constant(0u));
               ir_expression *const r0240 = logic_or(r023D, r023F);
               body.emit(assign(r023A, logic_and(r023C, r0240), 0x01));

               body.emit(assign(r0237, bit_or(swizzle_y(r0214), body.constant(524288u)), 0x02));

               body.emit(assign(r0238, bit_or(swizzle_y(r0215), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r0242 = lshift(swizzle_y(r0214), body.constant(int(1)));
               ir_expression *const r0243 = lequal(body.constant(4292870144u), r0242);
               ir_expression *const r0244 = nequal(swizzle_x(r0214), body.constant(0u));
               ir_expression *const r0245 = bit_and(swizzle_y(r0214), body.constant(1048575u));
               ir_expression *const r0246 = nequal(r0245, body.constant(0u));
               ir_expression *const r0247 = logic_or(r0244, r0246);
               ir_expression *const r0248 = logic_and(r0243, r0247);
               ir_if *f0241 = new(mem_ctx) ir_if(operand(r0248).val);
               exec_list *const f0241_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0241->then_instructions;

                  ir_variable *const r0249 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_if *f024A = new(mem_ctx) ir_if(operand(r023A).val);
                  exec_list *const f024A_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f024A->then_instructions;

                     body.emit(assign(r0249, r0238, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f024A->else_instructions;

                     body.emit(assign(r0249, r0237, 0x03));


                  body.instructions = f024A_parent_instructions;
                  body.emit(f024A);

                  /* END IF */

                  body.emit(assign(r0239, r0249, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0241->else_instructions;

                  body.emit(assign(r0239, r0238, 0x03));


               body.instructions = f0241_parent_instructions;
               body.emit(f0241);

               /* END IF */

               body.emit(assign(r0217, r0239, 0x03));

               body.emit(assign(r0216, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0234->else_instructions;

               body.emit(assign(r0217, r0214, 0x03));

               body.emit(assign(r0216, body.constant(false), 0x01));


            body.instructions = f0234_parent_instructions;
            body.emit(f0234);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0232->else_instructions;

            /* IF CONDITION */
            ir_expression *const r024C = equal(r022C, body.constant(int(0)));
            ir_if *f024B = new(mem_ctx) ir_if(operand(r024C).val);
            exec_list *const f024B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f024B->then_instructions;

               body.emit(assign(r021D, add(r022F, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f024B->else_instructions;

               body.emit(assign(r021E, bit_or(r0228, body.constant(1048576u)), 0x01));


            body.instructions = f024B_parent_instructions;
            body.emit(f024B);

            /* END IF */

            ir_variable *const r024D = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r024D, body.constant(0u), 0x01));

            ir_variable *const r024E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r024E);
            ir_variable *const r024F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r024F);
            ir_variable *const r0250 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0250);
            ir_variable *const r0251 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0252 = neg(r021D);
            body.emit(assign(r0251, bit_and(r0252, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0254 = equal(r021D, body.constant(int(0)));
            ir_if *f0253 = new(mem_ctx) ir_if(operand(r0254).val);
            exec_list *const f0253_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0253->then_instructions;

               body.emit(assign(r024E, r024D, 0x01));

               body.emit(assign(r024F, r0227, 0x01));

               body.emit(assign(r0250, r021E, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0253->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0256 = less(r021D, body.constant(int(32)));
               ir_if *f0255 = new(mem_ctx) ir_if(operand(r0256).val);
               exec_list *const f0255_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0255->then_instructions;

                  body.emit(assign(r024E, lshift(swizzle_x(r0215), r0251), 0x01));

                  ir_expression *const r0257 = lshift(r021E, r0251);
                  ir_expression *const r0258 = rshift(swizzle_x(r0215), r021D);
                  body.emit(assign(r024F, bit_or(r0257, r0258), 0x01));

                  body.emit(assign(r0250, rshift(r021E, r021D), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0255->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r025A = equal(r021D, body.constant(int(32)));
                  ir_if *f0259 = new(mem_ctx) ir_if(operand(r025A).val);
                  exec_list *const f0259_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0259->then_instructions;

                     body.emit(assign(r024E, r0227, 0x01));

                     body.emit(assign(r024F, r021E, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0259->else_instructions;

                     body.emit(assign(r024D, bit_or(body.constant(0u), swizzle_x(r0215)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r025C = less(r021D, body.constant(int(64)));
                     ir_if *f025B = new(mem_ctx) ir_if(operand(r025C).val);
                     exec_list *const f025B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f025B->then_instructions;

                        body.emit(assign(r024E, lshift(r021E, r0251), 0x01));

                        ir_expression *const r025D = bit_and(r021D, body.constant(int(31)));
                        body.emit(assign(r024F, rshift(r021E, r025D), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f025B->else_instructions;

                        ir_variable *const r025E = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0260 = equal(r021D, body.constant(int(64)));
                        ir_if *f025F = new(mem_ctx) ir_if(operand(r0260).val);
                        exec_list *const f025F_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f025F->then_instructions;

                           body.emit(assign(r025E, r021E, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f025F->else_instructions;

                           ir_expression *const r0261 = nequal(r021E, body.constant(0u));
                           ir_expression *const r0262 = expr(ir_unop_b2i, r0261);
                           body.emit(assign(r025E, expr(ir_unop_i2u, r0262), 0x01));


                        body.instructions = f025F_parent_instructions;
                        body.emit(f025F);

                        /* END IF */

                        body.emit(assign(r024E, r025E, 0x01));

                        body.emit(assign(r024F, body.constant(0u), 0x01));


                     body.instructions = f025B_parent_instructions;
                     body.emit(f025B);

                     /* END IF */


                  body.instructions = f0259_parent_instructions;
                  body.emit(f0259);

                  /* END IF */

                  body.emit(assign(r0250, body.constant(0u), 0x01));


               body.instructions = f0255_parent_instructions;
               body.emit(f0255);

               /* END IF */

               ir_expression *const r0263 = nequal(r024D, body.constant(0u));
               ir_expression *const r0264 = expr(ir_unop_b2i, r0263);
               ir_expression *const r0265 = expr(ir_unop_i2u, r0264);
               body.emit(assign(r024E, bit_or(r024E, r0265), 0x01));


            body.instructions = f0253_parent_instructions;
            body.emit(f0253);

            /* END IF */

            body.emit(assign(r021E, r0250, 0x01));

            body.emit(assign(r021F, r024F, 0x01));

            body.emit(assign(r0223, r024E, 0x01));

            body.emit(assign(r0222, r0229, 0x01));


         body.instructions = f0232_parent_instructions;
         body.emit(f0232);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0230->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0267 = less(r021D, body.constant(int(0)));
         ir_if *f0266 = new(mem_ctx) ir_if(operand(r0267).val);
         exec_list *const f0266_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0266->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0269 = equal(r022C, body.constant(int(2047)));
            ir_if *f0268 = new(mem_ctx) ir_if(operand(r0269).val);
            exec_list *const f0268_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0268->then_instructions;

               /* IF CONDITION */
               ir_expression *const r026B = bit_or(r021E, r021F);
               ir_expression *const r026C = nequal(r026B, body.constant(0u));
               ir_if *f026A = new(mem_ctx) ir_if(operand(r026C).val);
               exec_list *const f026A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f026A->then_instructions;

                  ir_variable *const r026D = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r026D, swizzle_x(r0214), 0x01));

                  ir_variable *const r026E = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r026E, swizzle_x(r0215), 0x01));

                  ir_variable *const r026F = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0270 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r0271 = lshift(swizzle_y(r0215), body.constant(int(1)));
                  ir_expression *const r0272 = lequal(body.constant(4292870144u), r0271);
                  ir_expression *const r0273 = nequal(swizzle_x(r0215), body.constant(0u));
                  ir_expression *const r0274 = bit_and(swizzle_y(r0215), body.constant(1048575u));
                  ir_expression *const r0275 = nequal(r0274, body.constant(0u));
                  ir_expression *const r0276 = logic_or(r0273, r0275);
                  body.emit(assign(r0270, logic_and(r0272, r0276), 0x01));

                  body.emit(assign(r026D, bit_or(swizzle_y(r0214), body.constant(524288u)), 0x02));

                  body.emit(assign(r026E, bit_or(swizzle_y(r0215), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0278 = lshift(swizzle_y(r0214), body.constant(int(1)));
                  ir_expression *const r0279 = lequal(body.constant(4292870144u), r0278);
                  ir_expression *const r027A = nequal(swizzle_x(r0214), body.constant(0u));
                  ir_expression *const r027B = bit_and(swizzle_y(r0214), body.constant(1048575u));
                  ir_expression *const r027C = nequal(r027B, body.constant(0u));
                  ir_expression *const r027D = logic_or(r027A, r027C);
                  ir_expression *const r027E = logic_and(r0279, r027D);
                  ir_if *f0277 = new(mem_ctx) ir_if(operand(r027E).val);
                  exec_list *const f0277_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0277->then_instructions;

                     ir_variable *const r027F = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f0280 = new(mem_ctx) ir_if(operand(r0270).val);
                     exec_list *const f0280_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0280->then_instructions;

                        body.emit(assign(r027F, r026E, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0280->else_instructions;

                        body.emit(assign(r027F, r026D, 0x03));


                     body.instructions = f0280_parent_instructions;
                     body.emit(f0280);

                     /* END IF */

                     body.emit(assign(r026F, r027F, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0277->else_instructions;

                     body.emit(assign(r026F, r026E, 0x03));


                  body.instructions = f0277_parent_instructions;
                  body.emit(f0277);

                  /* END IF */

                  body.emit(assign(r0217, r026F, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f026A->else_instructions;

                  ir_variable *const r0281 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0281);
                  ir_expression *const r0282 = lshift(r0219, body.constant(int(31)));
                  body.emit(assign(r0281, add(r0282, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0281, body.constant(0u), 0x01));

                  body.emit(assign(r0217, r0281, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


               body.instructions = f026A_parent_instructions;
               body.emit(f026A);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0268->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0284 = equal(r0229, body.constant(int(0)));
               ir_if *f0283 = new(mem_ctx) ir_if(operand(r0284).val);
               exec_list *const f0283_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0283->then_instructions;

                  body.emit(assign(r021D, add(r021D, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0283->else_instructions;

                  body.emit(assign(r0220, bit_or(r0226, body.constant(1048576u)), 0x01));


               body.instructions = f0283_parent_instructions;
               body.emit(f0283);

               /* END IF */

               ir_variable *const r0285 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0285, body.constant(0u), 0x01));

               ir_variable *const r0286 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0286, neg(r021D), 0x01));

               ir_variable *const r0287 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0287);
               ir_variable *const r0288 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0288);
               ir_variable *const r0289 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0289);
               ir_variable *const r028A = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r028B = neg(r0286);
               body.emit(assign(r028A, bit_and(r028B, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r028D = equal(r0286, body.constant(int(0)));
               ir_if *f028C = new(mem_ctx) ir_if(operand(r028D).val);
               exec_list *const f028C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f028C->then_instructions;

                  body.emit(assign(r0287, r0285, 0x01));

                  body.emit(assign(r0288, r0225, 0x01));

                  body.emit(assign(r0289, r0220, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f028C->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r028F = less(r0286, body.constant(int(32)));
                  ir_if *f028E = new(mem_ctx) ir_if(operand(r028F).val);
                  exec_list *const f028E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f028E->then_instructions;

                     body.emit(assign(r0287, lshift(swizzle_x(r0214), r028A), 0x01));

                     ir_expression *const r0290 = lshift(r0220, r028A);
                     ir_expression *const r0291 = rshift(swizzle_x(r0214), r0286);
                     body.emit(assign(r0288, bit_or(r0290, r0291), 0x01));

                     body.emit(assign(r0289, rshift(r0220, r0286), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f028E->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0293 = equal(r0286, body.constant(int(32)));
                     ir_if *f0292 = new(mem_ctx) ir_if(operand(r0293).val);
                     exec_list *const f0292_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0292->then_instructions;

                        body.emit(assign(r0287, r0225, 0x01));

                        body.emit(assign(r0288, r0220, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0292->else_instructions;

                        body.emit(assign(r0285, bit_or(body.constant(0u), swizzle_x(r0214)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0295 = less(r0286, body.constant(int(64)));
                        ir_if *f0294 = new(mem_ctx) ir_if(operand(r0295).val);
                        exec_list *const f0294_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0294->then_instructions;

                           body.emit(assign(r0287, lshift(r0220, r028A), 0x01));

                           ir_expression *const r0296 = bit_and(r0286, body.constant(int(31)));
                           body.emit(assign(r0288, rshift(r0220, r0296), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0294->else_instructions;

                           ir_variable *const r0297 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0299 = equal(r0286, body.constant(int(64)));
                           ir_if *f0298 = new(mem_ctx) ir_if(operand(r0299).val);
                           exec_list *const f0298_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0298->then_instructions;

                              body.emit(assign(r0297, r0220, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0298->else_instructions;

                              ir_expression *const r029A = nequal(r0220, body.constant(0u));
                              ir_expression *const r029B = expr(ir_unop_b2i, r029A);
                              body.emit(assign(r0297, expr(ir_unop_i2u, r029B), 0x01));


                           body.instructions = f0298_parent_instructions;
                           body.emit(f0298);

                           /* END IF */

                           body.emit(assign(r0287, r0297, 0x01));

                           body.emit(assign(r0288, body.constant(0u), 0x01));


                        body.instructions = f0294_parent_instructions;
                        body.emit(f0294);

                        /* END IF */


                     body.instructions = f0292_parent_instructions;
                     body.emit(f0292);

                     /* END IF */

                     body.emit(assign(r0289, body.constant(0u), 0x01));


                  body.instructions = f028E_parent_instructions;
                  body.emit(f028E);

                  /* END IF */

                  ir_expression *const r029C = nequal(r0285, body.constant(0u));
                  ir_expression *const r029D = expr(ir_unop_b2i, r029C);
                  ir_expression *const r029E = expr(ir_unop_i2u, r029D);
                  body.emit(assign(r0287, bit_or(r0287, r029E), 0x01));


               body.instructions = f028C_parent_instructions;
               body.emit(f028C);

               /* END IF */

               body.emit(assign(r0220, r0289, 0x01));

               body.emit(assign(r0221, r0288, 0x01));

               body.emit(assign(r0223, r0287, 0x01));

               body.emit(assign(r0222, r022C, 0x01));


            body.instructions = f0268_parent_instructions;
            body.emit(f0268);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0266->else_instructions;

            /* IF CONDITION */
            ir_expression *const r02A0 = equal(r0229, body.constant(int(2047)));
            ir_if *f029F = new(mem_ctx) ir_if(operand(r02A0).val);
            exec_list *const f029F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f029F->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02A2 = bit_or(r0220, r0221);
               ir_expression *const r02A3 = bit_or(r021E, r021F);
               ir_expression *const r02A4 = bit_or(r02A2, r02A3);
               ir_expression *const r02A5 = nequal(r02A4, body.constant(0u));
               ir_if *f02A1 = new(mem_ctx) ir_if(operand(r02A5).val);
               exec_list *const f02A1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02A1->then_instructions;

                  ir_variable *const r02A6 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r02A6, swizzle_x(r0214), 0x01));

                  ir_variable *const r02A7 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r02A7, swizzle_x(r0215), 0x01));

                  ir_variable *const r02A8 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r02A9 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r02AA = lshift(swizzle_y(r0215), body.constant(int(1)));
                  ir_expression *const r02AB = lequal(body.constant(4292870144u), r02AA);
                  ir_expression *const r02AC = nequal(swizzle_x(r0215), body.constant(0u));
                  ir_expression *const r02AD = bit_and(swizzle_y(r0215), body.constant(1048575u));
                  ir_expression *const r02AE = nequal(r02AD, body.constant(0u));
                  ir_expression *const r02AF = logic_or(r02AC, r02AE);
                  body.emit(assign(r02A9, logic_and(r02AB, r02AF), 0x01));

                  body.emit(assign(r02A6, bit_or(swizzle_y(r0214), body.constant(524288u)), 0x02));

                  body.emit(assign(r02A7, bit_or(swizzle_y(r0215), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r02B1 = lshift(swizzle_y(r0214), body.constant(int(1)));
                  ir_expression *const r02B2 = lequal(body.constant(4292870144u), r02B1);
                  ir_expression *const r02B3 = nequal(swizzle_x(r0214), body.constant(0u));
                  ir_expression *const r02B4 = bit_and(swizzle_y(r0214), body.constant(1048575u));
                  ir_expression *const r02B5 = nequal(r02B4, body.constant(0u));
                  ir_expression *const r02B6 = logic_or(r02B3, r02B5);
                  ir_expression *const r02B7 = logic_and(r02B2, r02B6);
                  ir_if *f02B0 = new(mem_ctx) ir_if(operand(r02B7).val);
                  exec_list *const f02B0_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02B0->then_instructions;

                     ir_variable *const r02B8 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f02B9 = new(mem_ctx) ir_if(operand(r02A9).val);
                     exec_list *const f02B9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02B9->then_instructions;

                        body.emit(assign(r02B8, r02A7, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02B9->else_instructions;

                        body.emit(assign(r02B8, r02A6, 0x03));


                     body.instructions = f02B9_parent_instructions;
                     body.emit(f02B9);

                     /* END IF */

                     body.emit(assign(r02A8, r02B8, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f02B0->else_instructions;

                     body.emit(assign(r02A8, r02A7, 0x03));


                  body.instructions = f02B0_parent_instructions;
                  body.emit(f02B0);

                  /* END IF */

                  body.emit(assign(r0217, r02A8, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02A1->else_instructions;

                  body.emit(assign(r0217, r0214, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


               body.instructions = f02A1_parent_instructions;
               body.emit(f02A1);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f029F->else_instructions;

               ir_variable *const r02BA = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r02BB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r02BB, add(r0221, r021F), 0x01));

               ir_expression *const r02BC = add(r0220, r021E);
               ir_expression *const r02BD = less(r02BB, r0221);
               ir_expression *const r02BE = expr(ir_unop_b2i, r02BD);
               ir_expression *const r02BF = expr(ir_unop_i2u, r02BE);
               body.emit(assign(r02BA, add(r02BC, r02BF), 0x01));

               body.emit(assign(r0224, r02BA, 0x01));

               /* IF CONDITION */
               ir_expression *const r02C1 = equal(r0229, body.constant(int(0)));
               ir_if *f02C0 = new(mem_ctx) ir_if(operand(r02C1).val);
               exec_list *const f02C0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02C0->then_instructions;

                  ir_variable *const r02C2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02C2);
                  ir_expression *const r02C3 = lshift(r0219, body.constant(int(31)));
                  body.emit(assign(r02C2, add(r02C3, r02BA), 0x02));

                  body.emit(assign(r02C2, r02BB, 0x01));

                  body.emit(assign(r0217, r02C2, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02C0->else_instructions;

                  body.emit(assign(r0224, bit_or(r02BA, body.constant(2097152u)), 0x01));

                  body.emit(assign(r0222, r0229, 0x01));

                  ir_variable *const r02C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r02C4);
                  ir_variable *const r02C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r02C5);
                  ir_variable *const r02C6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r02C6);
                  body.emit(assign(r02C4, lshift(r02BB, body.constant(int(31))), 0x01));

                  ir_expression *const r02C7 = lshift(r0224, body.constant(int(31)));
                  ir_expression *const r02C8 = rshift(r02BB, body.constant(int(1)));
                  body.emit(assign(r02C5, bit_or(r02C7, r02C8), 0x01));

                  body.emit(assign(r02C6, rshift(r0224, body.constant(int(1))), 0x01));

                  body.emit(assign(r02C4, bit_or(r02C4, body.constant(0u)), 0x01));

                  body.emit(assign(r0224, r02C6, 0x01));

                  body.emit(assign(r0223, r02C4, 0x01));

                  ir_variable *const r02C9 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r02C9, r0229, 0x01));

                  ir_variable *const r02CA = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r02CA, r02C6, 0x01));

                  ir_variable *const r02CB = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r02CB, r02C5, 0x01));

                  ir_variable *const r02CC = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r02CC, r02C4, 0x01));

                  ir_variable *const r02CD = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r02CD, body.constant(true), 0x01));

                  ir_variable *const r02CE = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r02CF = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r02CF);
                  ir_expression *const r02D0 = expr(ir_unop_u2i, r02C4);
                  body.emit(assign(r02CF, less(r02D0, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r02D2 = lequal(body.constant(int(2045)), r0229);
                  ir_if *f02D1 = new(mem_ctx) ir_if(operand(r02D2).val);
                  exec_list *const f02D1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02D1->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r02D4 = less(body.constant(int(2045)), r0229);
                     ir_expression *const r02D5 = equal(r0229, body.constant(int(2045)));
                     ir_expression *const r02D6 = equal(body.constant(2097151u), r02C6);
                     ir_expression *const r02D7 = equal(body.constant(4294967295u), r02C5);
                     ir_expression *const r02D8 = logic_and(r02D6, r02D7);
                     ir_expression *const r02D9 = logic_and(r02D5, r02D8);
                     ir_expression *const r02DA = logic_and(r02D9, r02CF);
                     ir_expression *const r02DB = logic_or(r02D4, r02DA);
                     ir_if *f02D3 = new(mem_ctx) ir_if(operand(r02DB).val);
                     exec_list *const f02D3_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02D3->then_instructions;

                        ir_variable *const r02DC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r02DC);
                        ir_expression *const r02DD = lshift(r0219, body.constant(int(31)));
                        body.emit(assign(r02DC, add(r02DD, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r02DC, body.constant(0u), 0x01));

                        body.emit(assign(r02CE, r02DC, 0x03));

                        body.emit(assign(r02CD, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02D3->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02DF = less(r0229, body.constant(int(0)));
                        ir_if *f02DE = new(mem_ctx) ir_if(operand(r02DF).val);
                        exec_list *const f02DE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02DE->then_instructions;

                           ir_variable *const r02E0 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r02E0, r02C4, 0x01));

                           ir_variable *const r02E1 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r02E1, neg(r0229), 0x01));

                           ir_variable *const r02E2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r02E2);
                           ir_variable *const r02E3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r02E3);
                           ir_variable *const r02E4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r02E4);
                           ir_variable *const r02E5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02E6 = neg(r02E1);
                           body.emit(assign(r02E5, bit_and(r02E6, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02E8 = equal(r02E1, body.constant(int(0)));
                           ir_if *f02E7 = new(mem_ctx) ir_if(operand(r02E8).val);
                           exec_list *const f02E7_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02E7->then_instructions;

                              body.emit(assign(r02E2, r02C4, 0x01));

                              body.emit(assign(r02E3, r02C5, 0x01));

                              body.emit(assign(r02E4, r02C6, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02E7->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02EA = less(r02E1, body.constant(int(32)));
                              ir_if *f02E9 = new(mem_ctx) ir_if(operand(r02EA).val);
                              exec_list *const f02E9_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02E9->then_instructions;

                                 body.emit(assign(r02E2, lshift(r02C5, r02E5), 0x01));

                                 ir_expression *const r02EB = lshift(r02C6, r02E5);
                                 ir_expression *const r02EC = rshift(r02C5, r02E1);
                                 body.emit(assign(r02E3, bit_or(r02EB, r02EC), 0x01));

                                 body.emit(assign(r02E4, rshift(r02C6, r02E1), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02E9->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02EE = equal(r02E1, body.constant(int(32)));
                                 ir_if *f02ED = new(mem_ctx) ir_if(operand(r02EE).val);
                                 exec_list *const f02ED_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02ED->then_instructions;

                                    body.emit(assign(r02E2, r02C5, 0x01));

                                    body.emit(assign(r02E3, r02C6, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02ED->else_instructions;

                                    body.emit(assign(r02E0, bit_or(r02C4, r02C5), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r02F0 = less(r02E1, body.constant(int(64)));
                                    ir_if *f02EF = new(mem_ctx) ir_if(operand(r02F0).val);
                                    exec_list *const f02EF_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f02EF->then_instructions;

                                       body.emit(assign(r02E2, lshift(r02C6, r02E5), 0x01));

                                       ir_expression *const r02F1 = bit_and(r02E1, body.constant(int(31)));
                                       body.emit(assign(r02E3, rshift(r02C6, r02F1), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f02EF->else_instructions;

                                       ir_variable *const r02F2 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r02F4 = equal(r02E1, body.constant(int(64)));
                                       ir_if *f02F3 = new(mem_ctx) ir_if(operand(r02F4).val);
                                       exec_list *const f02F3_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f02F3->then_instructions;

                                          body.emit(assign(r02F2, r02C6, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f02F3->else_instructions;

                                          ir_expression *const r02F5 = nequal(r02C6, body.constant(0u));
                                          ir_expression *const r02F6 = expr(ir_unop_b2i, r02F5);
                                          body.emit(assign(r02F2, expr(ir_unop_i2u, r02F6), 0x01));


                                       body.instructions = f02F3_parent_instructions;
                                       body.emit(f02F3);

                                       /* END IF */

                                       body.emit(assign(r02E2, r02F2, 0x01));

                                       body.emit(assign(r02E3, body.constant(0u), 0x01));


                                    body.instructions = f02EF_parent_instructions;
                                    body.emit(f02EF);

                                    /* END IF */


                                 body.instructions = f02ED_parent_instructions;
                                 body.emit(f02ED);

                                 /* END IF */

                                 body.emit(assign(r02E4, body.constant(0u), 0x01));


                              body.instructions = f02E9_parent_instructions;
                              body.emit(f02E9);

                              /* END IF */

                              ir_expression *const r02F7 = nequal(r02E0, body.constant(0u));
                              ir_expression *const r02F8 = expr(ir_unop_b2i, r02F7);
                              ir_expression *const r02F9 = expr(ir_unop_i2u, r02F8);
                              body.emit(assign(r02E2, bit_or(r02E2, r02F9), 0x01));


                           body.instructions = f02E7_parent_instructions;
                           body.emit(f02E7);

                           /* END IF */

                           body.emit(assign(r02CA, r02E4, 0x01));

                           body.emit(assign(r02CB, r02E3, 0x01));

                           body.emit(assign(r02CC, r02E2, 0x01));

                           body.emit(assign(r02C9, body.constant(int(0)), 0x01));

                           body.emit(assign(r02CF, less(r02E2, body.constant(0u)), 0x01));


                        body.instructions = f02DE_parent_instructions;
                        body.emit(f02DE);

                        /* END IF */


                     body.instructions = f02D3_parent_instructions;
                     body.emit(f02D3);

                     /* END IF */


                  body.instructions = f02D1_parent_instructions;
                  body.emit(f02D1);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02FA = new(mem_ctx) ir_if(operand(r02CD).val);
                  exec_list *const f02FA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02FA->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02FB = new(mem_ctx) ir_if(operand(r02CF).val);
                     exec_list *const f02FB_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02FB->then_instructions;

                        ir_variable *const r02FC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02FC, add(r02CB, body.constant(1u)), 0x01));

                        ir_expression *const r02FD = less(r02FC, r02CB);
                        ir_expression *const r02FE = expr(ir_unop_b2i, r02FD);
                        ir_expression *const r02FF = expr(ir_unop_i2u, r02FE);
                        body.emit(assign(r02CA, add(r02CA, r02FF), 0x01));

                        ir_expression *const r0300 = equal(r02CC, body.constant(0u));
                        ir_expression *const r0301 = expr(ir_unop_b2i, r0300);
                        ir_expression *const r0302 = expr(ir_unop_i2u, r0301);
                        ir_expression *const r0303 = add(r02CC, r0302);
                        ir_expression *const r0304 = bit_and(r0303, body.constant(1u));
                        ir_expression *const r0305 = expr(ir_unop_bit_not, r0304);
                        body.emit(assign(r02CB, bit_and(r02FC, r0305), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02FB->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0307 = bit_or(r02CA, r02CB);
                        ir_expression *const r0308 = equal(r0307, body.constant(0u));
                        ir_if *f0306 = new(mem_ctx) ir_if(operand(r0308).val);
                        exec_list *const f0306_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0306->then_instructions;

                           body.emit(assign(r02C9, body.constant(int(0)), 0x01));


                        body.instructions = f0306_parent_instructions;
                        body.emit(f0306);

                        /* END IF */


                     body.instructions = f02FB_parent_instructions;
                     body.emit(f02FB);

                     /* END IF */

                     ir_variable *const r0309 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0309);
                     ir_expression *const r030A = lshift(r0219, body.constant(int(31)));
                     ir_expression *const r030B = expr(ir_unop_i2u, r02C9);
                     ir_expression *const r030C = lshift(r030B, body.constant(int(20)));
                     ir_expression *const r030D = add(r030A, r030C);
                     body.emit(assign(r0309, add(r030D, r02CA), 0x02));

                     body.emit(assign(r0309, r02CB, 0x01));

                     body.emit(assign(r02CE, r0309, 0x03));

                     body.emit(assign(r02CD, body.constant(false), 0x01));


                  body.instructions = f02FA_parent_instructions;
                  body.emit(f02FA);

                  /* END IF */

                  body.emit(assign(r0217, r02CE, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


               body.instructions = f02C0_parent_instructions;
               body.emit(f02C0);

               /* END IF */


            body.instructions = f029F_parent_instructions;
            body.emit(f029F);

            /* END IF */


         body.instructions = f0266_parent_instructions;
         body.emit(f0266);

         /* END IF */


      body.instructions = f0230_parent_instructions;
      body.emit(f0230);

      /* END IF */

      /* IF CONDITION */
      ir_if *f030E = new(mem_ctx) ir_if(operand(r0216).val);
      exec_list *const f030E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f030E->then_instructions;

         body.emit(assign(r0220, bit_or(r0220, body.constant(1048576u)), 0x01));

         ir_variable *const r030F = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r0310 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0310, add(r0221, r021F), 0x01));

         ir_expression *const r0311 = add(r0220, r021E);
         ir_expression *const r0312 = less(r0310, r0221);
         ir_expression *const r0313 = expr(ir_unop_b2i, r0312);
         ir_expression *const r0314 = expr(ir_unop_i2u, r0313);
         body.emit(assign(r030F, add(r0311, r0314), 0x01));

         body.emit(assign(r0224, r030F, 0x01));

         body.emit(assign(r0222, add(r0222, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r0316 = less(r030F, body.constant(2097152u));
         ir_if *f0315 = new(mem_ctx) ir_if(operand(r0316).val);
         exec_list *const f0315_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0315->then_instructions;

            ir_variable *const r0317 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0317, r0222, 0x01));

            ir_variable *const r0318 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0318, r030F, 0x01));

            ir_variable *const r0319 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0319, r0310, 0x01));

            ir_variable *const r031A = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r031A, r0223, 0x01));

            ir_variable *const r031B = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r031B, body.constant(true), 0x01));

            ir_variable *const r031C = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r031D = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r031D);
            ir_expression *const r031E = expr(ir_unop_u2i, r0223);
            body.emit(assign(r031D, less(r031E, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0320 = lequal(body.constant(int(2045)), r0222);
            ir_if *f031F = new(mem_ctx) ir_if(operand(r0320).val);
            exec_list *const f031F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f031F->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0322 = less(body.constant(int(2045)), r0222);
               ir_expression *const r0323 = equal(r0222, body.constant(int(2045)));
               ir_expression *const r0324 = equal(body.constant(2097151u), r030F);
               ir_expression *const r0325 = equal(body.constant(4294967295u), r0310);
               ir_expression *const r0326 = logic_and(r0324, r0325);
               ir_expression *const r0327 = logic_and(r0323, r0326);
               ir_expression *const r0328 = logic_and(r0327, r031D);
               ir_expression *const r0329 = logic_or(r0322, r0328);
               ir_if *f0321 = new(mem_ctx) ir_if(operand(r0329).val);
               exec_list *const f0321_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0321->then_instructions;

                  ir_variable *const r032A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r032A);
                  ir_expression *const r032B = lshift(r0219, body.constant(int(31)));
                  body.emit(assign(r032A, add(r032B, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r032A, body.constant(0u), 0x01));

                  body.emit(assign(r031C, r032A, 0x03));

                  body.emit(assign(r031B, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0321->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r032D = less(r0222, body.constant(int(0)));
                  ir_if *f032C = new(mem_ctx) ir_if(operand(r032D).val);
                  exec_list *const f032C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f032C->then_instructions;

                     ir_variable *const r032E = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r032E, r0223, 0x01));

                     ir_variable *const r032F = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r032F, neg(r0222), 0x01));

                     ir_variable *const r0330 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0330);
                     ir_variable *const r0331 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r0331);
                     ir_variable *const r0332 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r0332);
                     ir_variable *const r0333 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0334 = neg(r032F);
                     body.emit(assign(r0333, bit_and(r0334, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0336 = equal(r032F, body.constant(int(0)));
                     ir_if *f0335 = new(mem_ctx) ir_if(operand(r0336).val);
                     exec_list *const f0335_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0335->then_instructions;

                        body.emit(assign(r0330, r0223, 0x01));

                        body.emit(assign(r0331, r0310, 0x01));

                        body.emit(assign(r0332, r030F, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0335->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0338 = less(r032F, body.constant(int(32)));
                        ir_if *f0337 = new(mem_ctx) ir_if(operand(r0338).val);
                        exec_list *const f0337_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0337->then_instructions;

                           body.emit(assign(r0330, lshift(r0310, r0333), 0x01));

                           ir_expression *const r0339 = lshift(r030F, r0333);
                           ir_expression *const r033A = rshift(r0310, r032F);
                           body.emit(assign(r0331, bit_or(r0339, r033A), 0x01));

                           body.emit(assign(r0332, rshift(r030F, r032F), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0337->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r033C = equal(r032F, body.constant(int(32)));
                           ir_if *f033B = new(mem_ctx) ir_if(operand(r033C).val);
                           exec_list *const f033B_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f033B->then_instructions;

                              body.emit(assign(r0330, r0310, 0x01));

                              body.emit(assign(r0331, r030F, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f033B->else_instructions;

                              body.emit(assign(r032E, bit_or(r0223, r0310), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r033E = less(r032F, body.constant(int(64)));
                              ir_if *f033D = new(mem_ctx) ir_if(operand(r033E).val);
                              exec_list *const f033D_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f033D->then_instructions;

                                 body.emit(assign(r0330, lshift(r030F, r0333), 0x01));

                                 ir_expression *const r033F = bit_and(r032F, body.constant(int(31)));
                                 body.emit(assign(r0331, rshift(r030F, r033F), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f033D->else_instructions;

                                 ir_variable *const r0340 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r0342 = equal(r032F, body.constant(int(64)));
                                 ir_if *f0341 = new(mem_ctx) ir_if(operand(r0342).val);
                                 exec_list *const f0341_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0341->then_instructions;

                                    body.emit(assign(r0340, r030F, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0341->else_instructions;

                                    ir_expression *const r0343 = nequal(r030F, body.constant(0u));
                                    ir_expression *const r0344 = expr(ir_unop_b2i, r0343);
                                    body.emit(assign(r0340, expr(ir_unop_i2u, r0344), 0x01));


                                 body.instructions = f0341_parent_instructions;
                                 body.emit(f0341);

                                 /* END IF */

                                 body.emit(assign(r0330, r0340, 0x01));

                                 body.emit(assign(r0331, body.constant(0u), 0x01));


                              body.instructions = f033D_parent_instructions;
                              body.emit(f033D);

                              /* END IF */


                           body.instructions = f033B_parent_instructions;
                           body.emit(f033B);

                           /* END IF */

                           body.emit(assign(r0332, body.constant(0u), 0x01));


                        body.instructions = f0337_parent_instructions;
                        body.emit(f0337);

                        /* END IF */

                        ir_expression *const r0345 = nequal(r032E, body.constant(0u));
                        ir_expression *const r0346 = expr(ir_unop_b2i, r0345);
                        ir_expression *const r0347 = expr(ir_unop_i2u, r0346);
                        body.emit(assign(r0330, bit_or(r0330, r0347), 0x01));


                     body.instructions = f0335_parent_instructions;
                     body.emit(f0335);

                     /* END IF */

                     body.emit(assign(r0318, r0332, 0x01));

                     body.emit(assign(r0319, r0331, 0x01));

                     body.emit(assign(r031A, r0330, 0x01));

                     body.emit(assign(r0317, body.constant(int(0)), 0x01));

                     body.emit(assign(r031D, less(r0330, body.constant(0u)), 0x01));


                  body.instructions = f032C_parent_instructions;
                  body.emit(f032C);

                  /* END IF */


               body.instructions = f0321_parent_instructions;
               body.emit(f0321);

               /* END IF */


            body.instructions = f031F_parent_instructions;
            body.emit(f031F);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0348 = new(mem_ctx) ir_if(operand(r031B).val);
            exec_list *const f0348_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0348->then_instructions;

               /* IF CONDITION */
               ir_if *f0349 = new(mem_ctx) ir_if(operand(r031D).val);
               exec_list *const f0349_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0349->then_instructions;

                  ir_variable *const r034A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r034A, add(r0319, body.constant(1u)), 0x01));

                  ir_expression *const r034B = less(r034A, r0319);
                  ir_expression *const r034C = expr(ir_unop_b2i, r034B);
                  ir_expression *const r034D = expr(ir_unop_i2u, r034C);
                  body.emit(assign(r0318, add(r0318, r034D), 0x01));

                  ir_expression *const r034E = equal(r031A, body.constant(0u));
                  ir_expression *const r034F = expr(ir_unop_b2i, r034E);
                  ir_expression *const r0350 = expr(ir_unop_i2u, r034F);
                  ir_expression *const r0351 = add(r031A, r0350);
                  ir_expression *const r0352 = bit_and(r0351, body.constant(1u));
                  ir_expression *const r0353 = expr(ir_unop_bit_not, r0352);
                  body.emit(assign(r0319, bit_and(r034A, r0353), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0349->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0355 = bit_or(r0318, r0319);
                  ir_expression *const r0356 = equal(r0355, body.constant(0u));
                  ir_if *f0354 = new(mem_ctx) ir_if(operand(r0356).val);
                  exec_list *const f0354_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0354->then_instructions;

                     body.emit(assign(r0317, body.constant(int(0)), 0x01));


                  body.instructions = f0354_parent_instructions;
                  body.emit(f0354);

                  /* END IF */


               body.instructions = f0349_parent_instructions;
               body.emit(f0349);

               /* END IF */

               ir_variable *const r0357 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0357);
               ir_expression *const r0358 = lshift(r0219, body.constant(int(31)));
               ir_expression *const r0359 = expr(ir_unop_i2u, r0317);
               ir_expression *const r035A = lshift(r0359, body.constant(int(20)));
               ir_expression *const r035B = add(r0358, r035A);
               body.emit(assign(r0357, add(r035B, r0318), 0x02));

               body.emit(assign(r0357, r0319, 0x01));

               body.emit(assign(r031C, r0357, 0x03));

               body.emit(assign(r031B, body.constant(false), 0x01));


            body.instructions = f0348_parent_instructions;
            body.emit(f0348);

            /* END IF */

            body.emit(assign(r0217, r031C, 0x03));

            body.emit(assign(r0216, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0315->else_instructions;

            body.emit(assign(r0222, add(r0222, body.constant(int(1))), 0x01));

            ir_variable *const r035C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r035C);
            ir_variable *const r035D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r035D);
            ir_variable *const r035E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r035E);
            body.emit(assign(r035C, lshift(r0310, body.constant(int(31))), 0x01));

            ir_expression *const r035F = lshift(r030F, body.constant(int(31)));
            ir_expression *const r0360 = rshift(r0310, body.constant(int(1)));
            body.emit(assign(r035D, bit_or(r035F, r0360), 0x01));

            body.emit(assign(r035E, rshift(r030F, body.constant(int(1))), 0x01));

            ir_expression *const r0361 = nequal(r0223, body.constant(0u));
            ir_expression *const r0362 = expr(ir_unop_b2i, r0361);
            ir_expression *const r0363 = expr(ir_unop_i2u, r0362);
            body.emit(assign(r035C, bit_or(r035C, r0363), 0x01));

            body.emit(assign(r0224, r035E, 0x01));

            body.emit(assign(r0223, r035C, 0x01));

            ir_variable *const r0364 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0364, r0222, 0x01));

            ir_variable *const r0365 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0365, r035E, 0x01));

            ir_variable *const r0366 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0366, r035D, 0x01));

            ir_variable *const r0367 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0367, r035C, 0x01));

            ir_variable *const r0368 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0368, body.constant(true), 0x01));

            ir_variable *const r0369 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r036A = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r036A);
            ir_expression *const r036B = expr(ir_unop_u2i, r035C);
            body.emit(assign(r036A, less(r036B, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r036D = lequal(body.constant(int(2045)), r0222);
            ir_if *f036C = new(mem_ctx) ir_if(operand(r036D).val);
            exec_list *const f036C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f036C->then_instructions;

               /* IF CONDITION */
               ir_expression *const r036F = less(body.constant(int(2045)), r0222);
               ir_expression *const r0370 = equal(r0222, body.constant(int(2045)));
               ir_expression *const r0371 = equal(body.constant(2097151u), r035E);
               ir_expression *const r0372 = equal(body.constant(4294967295u), r035D);
               ir_expression *const r0373 = logic_and(r0371, r0372);
               ir_expression *const r0374 = logic_and(r0370, r0373);
               ir_expression *const r0375 = logic_and(r0374, r036A);
               ir_expression *const r0376 = logic_or(r036F, r0375);
               ir_if *f036E = new(mem_ctx) ir_if(operand(r0376).val);
               exec_list *const f036E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f036E->then_instructions;

                  ir_variable *const r0377 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0377);
                  ir_expression *const r0378 = lshift(r0219, body.constant(int(31)));
                  body.emit(assign(r0377, add(r0378, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0377, body.constant(0u), 0x01));

                  body.emit(assign(r0369, r0377, 0x03));

                  body.emit(assign(r0368, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f036E->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r037A = less(r0222, body.constant(int(0)));
                  ir_if *f0379 = new(mem_ctx) ir_if(operand(r037A).val);
                  exec_list *const f0379_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0379->then_instructions;

                     ir_variable *const r037B = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r037B, r035C, 0x01));

                     ir_variable *const r037C = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r037C, neg(r0222), 0x01));

                     ir_variable *const r037D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r037D);
                     ir_variable *const r037E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r037E);
                     ir_variable *const r037F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r037F);
                     ir_variable *const r0380 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0381 = neg(r037C);
                     body.emit(assign(r0380, bit_and(r0381, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0383 = equal(r037C, body.constant(int(0)));
                     ir_if *f0382 = new(mem_ctx) ir_if(operand(r0383).val);
                     exec_list *const f0382_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0382->then_instructions;

                        body.emit(assign(r037D, r035C, 0x01));

                        body.emit(assign(r037E, r035D, 0x01));

                        body.emit(assign(r037F, r035E, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0382->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0385 = less(r037C, body.constant(int(32)));
                        ir_if *f0384 = new(mem_ctx) ir_if(operand(r0385).val);
                        exec_list *const f0384_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0384->then_instructions;

                           body.emit(assign(r037D, lshift(r035D, r0380), 0x01));

                           ir_expression *const r0386 = lshift(r035E, r0380);
                           ir_expression *const r0387 = rshift(r035D, r037C);
                           body.emit(assign(r037E, bit_or(r0386, r0387), 0x01));

                           body.emit(assign(r037F, rshift(r035E, r037C), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0384->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0389 = equal(r037C, body.constant(int(32)));
                           ir_if *f0388 = new(mem_ctx) ir_if(operand(r0389).val);
                           exec_list *const f0388_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0388->then_instructions;

                              body.emit(assign(r037D, r035D, 0x01));

                              body.emit(assign(r037E, r035E, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0388->else_instructions;

                              body.emit(assign(r037B, bit_or(r035C, r035D), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r038B = less(r037C, body.constant(int(64)));
                              ir_if *f038A = new(mem_ctx) ir_if(operand(r038B).val);
                              exec_list *const f038A_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f038A->then_instructions;

                                 body.emit(assign(r037D, lshift(r035E, r0380), 0x01));

                                 ir_expression *const r038C = bit_and(r037C, body.constant(int(31)));
                                 body.emit(assign(r037E, rshift(r035E, r038C), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f038A->else_instructions;

                                 ir_variable *const r038D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r038F = equal(r037C, body.constant(int(64)));
                                 ir_if *f038E = new(mem_ctx) ir_if(operand(r038F).val);
                                 exec_list *const f038E_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f038E->then_instructions;

                                    body.emit(assign(r038D, r035E, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f038E->else_instructions;

                                    ir_expression *const r0390 = nequal(r035E, body.constant(0u));
                                    ir_expression *const r0391 = expr(ir_unop_b2i, r0390);
                                    body.emit(assign(r038D, expr(ir_unop_i2u, r0391), 0x01));


                                 body.instructions = f038E_parent_instructions;
                                 body.emit(f038E);

                                 /* END IF */

                                 body.emit(assign(r037D, r038D, 0x01));

                                 body.emit(assign(r037E, body.constant(0u), 0x01));


                              body.instructions = f038A_parent_instructions;
                              body.emit(f038A);

                              /* END IF */


                           body.instructions = f0388_parent_instructions;
                           body.emit(f0388);

                           /* END IF */

                           body.emit(assign(r037F, body.constant(0u), 0x01));


                        body.instructions = f0384_parent_instructions;
                        body.emit(f0384);

                        /* END IF */

                        ir_expression *const r0392 = nequal(r037B, body.constant(0u));
                        ir_expression *const r0393 = expr(ir_unop_b2i, r0392);
                        ir_expression *const r0394 = expr(ir_unop_i2u, r0393);
                        body.emit(assign(r037D, bit_or(r037D, r0394), 0x01));


                     body.instructions = f0382_parent_instructions;
                     body.emit(f0382);

                     /* END IF */

                     body.emit(assign(r0365, r037F, 0x01));

                     body.emit(assign(r0366, r037E, 0x01));

                     body.emit(assign(r0367, r037D, 0x01));

                     body.emit(assign(r0364, body.constant(int(0)), 0x01));

                     body.emit(assign(r036A, less(r037D, body.constant(0u)), 0x01));


                  body.instructions = f0379_parent_instructions;
                  body.emit(f0379);

                  /* END IF */


               body.instructions = f036E_parent_instructions;
               body.emit(f036E);

               /* END IF */


            body.instructions = f036C_parent_instructions;
            body.emit(f036C);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0395 = new(mem_ctx) ir_if(operand(r0368).val);
            exec_list *const f0395_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0395->then_instructions;

               /* IF CONDITION */
               ir_if *f0396 = new(mem_ctx) ir_if(operand(r036A).val);
               exec_list *const f0396_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0396->then_instructions;

                  ir_variable *const r0397 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0397, add(r0366, body.constant(1u)), 0x01));

                  ir_expression *const r0398 = less(r0397, r0366);
                  ir_expression *const r0399 = expr(ir_unop_b2i, r0398);
                  ir_expression *const r039A = expr(ir_unop_i2u, r0399);
                  body.emit(assign(r0365, add(r0365, r039A), 0x01));

                  ir_expression *const r039B = equal(r0367, body.constant(0u));
                  ir_expression *const r039C = expr(ir_unop_b2i, r039B);
                  ir_expression *const r039D = expr(ir_unop_i2u, r039C);
                  ir_expression *const r039E = add(r0367, r039D);
                  ir_expression *const r039F = bit_and(r039E, body.constant(1u));
                  ir_expression *const r03A0 = expr(ir_unop_bit_not, r039F);
                  body.emit(assign(r0366, bit_and(r0397, r03A0), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0396->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03A2 = bit_or(r0365, r0366);
                  ir_expression *const r03A3 = equal(r03A2, body.constant(0u));
                  ir_if *f03A1 = new(mem_ctx) ir_if(operand(r03A3).val);
                  exec_list *const f03A1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03A1->then_instructions;

                     body.emit(assign(r0364, body.constant(int(0)), 0x01));


                  body.instructions = f03A1_parent_instructions;
                  body.emit(f03A1);

                  /* END IF */


               body.instructions = f0396_parent_instructions;
               body.emit(f0396);

               /* END IF */

               ir_variable *const r03A4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r03A4);
               ir_expression *const r03A5 = lshift(r0219, body.constant(int(31)));
               ir_expression *const r03A6 = expr(ir_unop_i2u, r0364);
               ir_expression *const r03A7 = lshift(r03A6, body.constant(int(20)));
               ir_expression *const r03A8 = add(r03A5, r03A7);
               body.emit(assign(r03A4, add(r03A8, r0365), 0x02));

               body.emit(assign(r03A4, r0366, 0x01));

               body.emit(assign(r0369, r03A4, 0x03));

               body.emit(assign(r0368, body.constant(false), 0x01));


            body.instructions = f0395_parent_instructions;
            body.emit(f0395);

            /* END IF */

            body.emit(assign(r0217, r0369, 0x03));

            body.emit(assign(r0216, body.constant(false), 0x01));


         body.instructions = f0315_parent_instructions;
         body.emit(f0315);

         /* END IF */


      body.instructions = f030E_parent_instructions;
      body.emit(f030E);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f021B->else_instructions;

      ir_variable *const r03A9 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r03A9);
      ir_variable *const r03AA = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
      body.emit(r03AA);
      ir_variable *const r03AB = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
      body.emit(r03AB);
      ir_variable *const r03AC = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r03AC);
      ir_variable *const r03AD = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r03AD);
      ir_variable *const r03AE = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r03AE);
      ir_variable *const r03AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r03AF);
      ir_variable *const r03B0 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r03B0);
      ir_variable *const r03B1 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r03B2 = rshift(swizzle_y(r0214), body.constant(int(20)));
      ir_expression *const r03B3 = bit_and(r03B2, body.constant(2047u));
      body.emit(assign(r03B1, expr(ir_unop_u2i, r03B3), 0x01));

      body.emit(assign(r03AB, r03B1, 0x01));

      ir_variable *const r03B4 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r03B5 = rshift(swizzle_y(r0215), body.constant(int(20)));
      ir_expression *const r03B6 = bit_and(r03B5, body.constant(2047u));
      body.emit(assign(r03B4, expr(ir_unop_u2i, r03B6), 0x01));

      body.emit(assign(r03AA, r03B4, 0x01));

      body.emit(assign(r03A9, sub(r03B1, r03B4), 0x01));

      ir_variable *const r03B7 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r03B7, lshift(swizzle_x(r0214), body.constant(int(10))), 0x01));

      ir_variable *const r03B8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r03B9 = bit_and(swizzle_y(r0214), body.constant(1048575u));
      ir_expression *const r03BA = lshift(r03B9, body.constant(int(10)));
      ir_expression *const r03BB = rshift(swizzle_x(r0214), body.constant(int(22)));
      body.emit(assign(r03B8, bit_or(r03BA, r03BB), 0x01));

      body.emit(assign(r03AE, r03B8, 0x01));

      body.emit(assign(r03AF, r03B7, 0x01));

      ir_variable *const r03BC = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r03BC, lshift(swizzle_x(r0215), body.constant(int(10))), 0x01));

      ir_variable *const r03BD = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r03BE = bit_and(swizzle_y(r0215), body.constant(1048575u));
      ir_expression *const r03BF = lshift(r03BE, body.constant(int(10)));
      ir_expression *const r03C0 = rshift(swizzle_x(r0215), body.constant(int(22)));
      body.emit(assign(r03BD, bit_or(r03BF, r03C0), 0x01));

      body.emit(assign(r03AC, r03BD, 0x01));

      body.emit(assign(r03AD, r03BC, 0x01));

      /* IF CONDITION */
      ir_expression *const r03C2 = less(body.constant(int(0)), r03A9);
      ir_if *f03C1 = new(mem_ctx) ir_if(operand(r03C2).val);
      exec_list *const f03C1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f03C1->then_instructions;

         /* IF CONDITION */
         ir_expression *const r03C4 = equal(r03B1, body.constant(int(2047)));
         ir_if *f03C3 = new(mem_ctx) ir_if(operand(r03C4).val);
         exec_list *const f03C3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f03C3->then_instructions;

            /* IF CONDITION */
            ir_expression *const r03C6 = bit_or(r03B8, r03B7);
            ir_expression *const r03C7 = nequal(r03C6, body.constant(0u));
            ir_if *f03C5 = new(mem_ctx) ir_if(operand(r03C7).val);
            exec_list *const f03C5_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03C5->then_instructions;

               ir_variable *const r03C8 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r03C8, swizzle_x(r0214), 0x01));

               ir_variable *const r03C9 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r03C9, swizzle_x(r0215), 0x01));

               ir_variable *const r03CA = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r03CB = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r03CC = lshift(swizzle_y(r0215), body.constant(int(1)));
               ir_expression *const r03CD = lequal(body.constant(4292870144u), r03CC);
               ir_expression *const r03CE = nequal(swizzle_x(r0215), body.constant(0u));
               ir_expression *const r03CF = bit_and(swizzle_y(r0215), body.constant(1048575u));
               ir_expression *const r03D0 = nequal(r03CF, body.constant(0u));
               ir_expression *const r03D1 = logic_or(r03CE, r03D0);
               body.emit(assign(r03CB, logic_and(r03CD, r03D1), 0x01));

               body.emit(assign(r03C8, bit_or(swizzle_y(r0214), body.constant(524288u)), 0x02));

               body.emit(assign(r03C9, bit_or(swizzle_y(r0215), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r03D3 = lshift(swizzle_y(r0214), body.constant(int(1)));
               ir_expression *const r03D4 = lequal(body.constant(4292870144u), r03D3);
               ir_expression *const r03D5 = nequal(swizzle_x(r0214), body.constant(0u));
               ir_expression *const r03D6 = bit_and(swizzle_y(r0214), body.constant(1048575u));
               ir_expression *const r03D7 = nequal(r03D6, body.constant(0u));
               ir_expression *const r03D8 = logic_or(r03D5, r03D7);
               ir_expression *const r03D9 = logic_and(r03D4, r03D8);
               ir_if *f03D2 = new(mem_ctx) ir_if(operand(r03D9).val);
               exec_list *const f03D2_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03D2->then_instructions;

                  ir_variable *const r03DA = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_if *f03DB = new(mem_ctx) ir_if(operand(r03CB).val);
                  exec_list *const f03DB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03DB->then_instructions;

                     body.emit(assign(r03DA, r03C9, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03DB->else_instructions;

                     body.emit(assign(r03DA, r03C8, 0x03));


                  body.instructions = f03DB_parent_instructions;
                  body.emit(f03DB);

                  /* END IF */

                  body.emit(assign(r03CA, r03DA, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03D2->else_instructions;

                  body.emit(assign(r03CA, r03C9, 0x03));


               body.instructions = f03D2_parent_instructions;
               body.emit(f03D2);

               /* END IF */

               body.emit(assign(r0217, r03CA, 0x03));

               body.emit(assign(r0216, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03C5->else_instructions;

               body.emit(assign(r0217, r0214, 0x03));

               body.emit(assign(r0216, body.constant(false), 0x01));


            body.instructions = f03C5_parent_instructions;
            body.emit(f03C5);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f03C3->else_instructions;

            /* IF CONDITION */
            ir_expression *const r03DD = equal(r03B4, body.constant(int(0)));
            ir_if *f03DC = new(mem_ctx) ir_if(operand(r03DD).val);
            exec_list *const f03DC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03DC->then_instructions;

               body.emit(assign(r03A9, add(r03A9, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03DC->else_instructions;

               body.emit(assign(r03AC, bit_or(r03BD, body.constant(1073741824u)), 0x01));


            body.instructions = f03DC_parent_instructions;
            body.emit(f03DC);

            /* END IF */

            ir_variable *const r03DE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r03DE);
            ir_variable *const r03DF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r03DF);
            ir_variable *const r03E0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r03E1 = neg(r03A9);
            body.emit(assign(r03E0, bit_and(r03E1, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03E3 = equal(r03A9, body.constant(int(0)));
            ir_if *f03E2 = new(mem_ctx) ir_if(operand(r03E3).val);
            exec_list *const f03E2_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03E2->then_instructions;

               body.emit(assign(r03DE, r03BC, 0x01));

               body.emit(assign(r03DF, r03AC, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03E2->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03E5 = less(r03A9, body.constant(int(32)));
               ir_if *f03E4 = new(mem_ctx) ir_if(operand(r03E5).val);
               exec_list *const f03E4_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E4->then_instructions;

                  ir_expression *const r03E6 = lshift(r03AC, r03E0);
                  ir_expression *const r03E7 = rshift(r03BC, r03A9);
                  ir_expression *const r03E8 = bit_or(r03E6, r03E7);
                  ir_expression *const r03E9 = lshift(r03BC, r03E0);
                  ir_expression *const r03EA = nequal(r03E9, body.constant(0u));
                  ir_expression *const r03EB = expr(ir_unop_b2i, r03EA);
                  ir_expression *const r03EC = expr(ir_unop_i2u, r03EB);
                  body.emit(assign(r03DE, bit_or(r03E8, r03EC), 0x01));

                  body.emit(assign(r03DF, rshift(r03AC, r03A9), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03E4->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03EE = equal(r03A9, body.constant(int(32)));
                  ir_if *f03ED = new(mem_ctx) ir_if(operand(r03EE).val);
                  exec_list *const f03ED_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03ED->then_instructions;

                     ir_expression *const r03EF = nequal(r03BC, body.constant(0u));
                     ir_expression *const r03F0 = expr(ir_unop_b2i, r03EF);
                     ir_expression *const r03F1 = expr(ir_unop_i2u, r03F0);
                     body.emit(assign(r03DE, bit_or(r03AC, r03F1), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03ED->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03F3 = less(r03A9, body.constant(int(64)));
                     ir_if *f03F2 = new(mem_ctx) ir_if(operand(r03F3).val);
                     exec_list *const f03F2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03F2->then_instructions;

                        ir_expression *const r03F4 = bit_and(r03A9, body.constant(int(31)));
                        ir_expression *const r03F5 = rshift(r03AC, r03F4);
                        ir_expression *const r03F6 = lshift(r03AC, r03E0);
                        ir_expression *const r03F7 = bit_or(r03F6, r03BC);
                        ir_expression *const r03F8 = nequal(r03F7, body.constant(0u));
                        ir_expression *const r03F9 = expr(ir_unop_b2i, r03F8);
                        ir_expression *const r03FA = expr(ir_unop_i2u, r03F9);
                        body.emit(assign(r03DE, bit_or(r03F5, r03FA), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03F2->else_instructions;

                        ir_expression *const r03FB = bit_or(r03AC, r03BC);
                        ir_expression *const r03FC = nequal(r03FB, body.constant(0u));
                        ir_expression *const r03FD = expr(ir_unop_b2i, r03FC);
                        body.emit(assign(r03DE, expr(ir_unop_i2u, r03FD), 0x01));


                     body.instructions = f03F2_parent_instructions;
                     body.emit(f03F2);

                     /* END IF */


                  body.instructions = f03ED_parent_instructions;
                  body.emit(f03ED);

                  /* END IF */

                  body.emit(assign(r03DF, body.constant(0u), 0x01));


               body.instructions = f03E4_parent_instructions;
               body.emit(f03E4);

               /* END IF */


            body.instructions = f03E2_parent_instructions;
            body.emit(f03E2);

            /* END IF */

            body.emit(assign(r03AC, r03DF, 0x01));

            body.emit(assign(r03AD, r03DE, 0x01));

            body.emit(assign(r03AE, bit_or(r03B8, body.constant(1073741824u)), 0x01));

            ir_variable *const r03FE = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r03FF = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r03FF, sub(r03B7, r03DE), 0x01));

            ir_expression *const r0400 = sub(r03AE, r03DF);
            ir_expression *const r0401 = less(r03B7, r03DE);
            ir_expression *const r0402 = expr(ir_unop_b2i, r0401);
            ir_expression *const r0403 = expr(ir_unop_i2u, r0402);
            body.emit(assign(r03FE, sub(r0400, r0403), 0x01));

            body.emit(assign(r03B0, add(r03B1, body.constant(int(-1))), 0x01));

            ir_variable *const r0404 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0404, add(r03B0, body.constant(int(-10))), 0x01));

            ir_variable *const r0405 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0405, r03FE, 0x01));

            ir_variable *const r0406 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0406, r03FF, 0x01));

            ir_variable *const r0407 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r0407);
            ir_variable *const r0408 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0408);
            /* IF CONDITION */
            ir_expression *const r040A = equal(r03FE, body.constant(0u));
            ir_if *f0409 = new(mem_ctx) ir_if(operand(r040A).val);
            exec_list *const f0409_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0409->then_instructions;

               body.emit(assign(r0405, r03FF, 0x01));

               body.emit(assign(r0406, body.constant(0u), 0x01));

               body.emit(assign(r0404, add(r0404, body.constant(int(-32))), 0x01));


            body.instructions = f0409_parent_instructions;
            body.emit(f0409);

            /* END IF */

            ir_variable *const r040B = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r040B, r0405, 0x01));

            ir_variable *const r040C = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r040D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r040D);
            /* IF CONDITION */
            ir_expression *const r040F = equal(r0405, body.constant(0u));
            ir_if *f040E = new(mem_ctx) ir_if(operand(r040F).val);
            exec_list *const f040E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f040E->then_instructions;

               body.emit(assign(r040C, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f040E->else_instructions;

               body.emit(assign(r040D, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0411 = bit_and(r0405, body.constant(4294901760u));
               ir_expression *const r0412 = equal(r0411, body.constant(0u));
               ir_if *f0410 = new(mem_ctx) ir_if(operand(r0412).val);
               exec_list *const f0410_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0410->then_instructions;

                  body.emit(assign(r040D, body.constant(int(16)), 0x01));

                  body.emit(assign(r040B, lshift(r0405, body.constant(int(16))), 0x01));


               body.instructions = f0410_parent_instructions;
               body.emit(f0410);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0414 = bit_and(r040B, body.constant(4278190080u));
               ir_expression *const r0415 = equal(r0414, body.constant(0u));
               ir_if *f0413 = new(mem_ctx) ir_if(operand(r0415).val);
               exec_list *const f0413_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0413->then_instructions;

                  body.emit(assign(r040D, add(r040D, body.constant(int(8))), 0x01));

                  body.emit(assign(r040B, lshift(r040B, body.constant(int(8))), 0x01));


               body.instructions = f0413_parent_instructions;
               body.emit(f0413);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0417 = bit_and(r040B, body.constant(4026531840u));
               ir_expression *const r0418 = equal(r0417, body.constant(0u));
               ir_if *f0416 = new(mem_ctx) ir_if(operand(r0418).val);
               exec_list *const f0416_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0416->then_instructions;

                  body.emit(assign(r040D, add(r040D, body.constant(int(4))), 0x01));

                  body.emit(assign(r040B, lshift(r040B, body.constant(int(4))), 0x01));


               body.instructions = f0416_parent_instructions;
               body.emit(f0416);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r041A = bit_and(r040B, body.constant(3221225472u));
               ir_expression *const r041B = equal(r041A, body.constant(0u));
               ir_if *f0419 = new(mem_ctx) ir_if(operand(r041B).val);
               exec_list *const f0419_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0419->then_instructions;

                  body.emit(assign(r040D, add(r040D, body.constant(int(2))), 0x01));

                  body.emit(assign(r040B, lshift(r040B, body.constant(int(2))), 0x01));


               body.instructions = f0419_parent_instructions;
               body.emit(f0419);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r041D = bit_and(r040B, body.constant(2147483648u));
               ir_expression *const r041E = equal(r041D, body.constant(0u));
               ir_if *f041C = new(mem_ctx) ir_if(operand(r041E).val);
               exec_list *const f041C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f041C->then_instructions;

                  body.emit(assign(r040D, add(r040D, body.constant(int(1))), 0x01));


               body.instructions = f041C_parent_instructions;
               body.emit(f041C);

               /* END IF */

               body.emit(assign(r040C, r040D, 0x01));


            body.instructions = f040E_parent_instructions;
            body.emit(f040E);

            /* END IF */

            body.emit(assign(r0408, add(r040C, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0420 = lequal(body.constant(int(0)), r0408);
            ir_if *f041F = new(mem_ctx) ir_if(operand(r0420).val);
            exec_list *const f041F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f041F->then_instructions;

               body.emit(assign(r0407, body.constant(0u), 0x01));

               ir_variable *const r0421 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0421, lshift(r0406, r0408), 0x01));

               ir_variable *const r0422 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0424 = equal(r0408, body.constant(int(0)));
               ir_if *f0423 = new(mem_ctx) ir_if(operand(r0424).val);
               exec_list *const f0423_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0423->then_instructions;

                  body.emit(assign(r0422, r0405, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0423->else_instructions;

                  ir_expression *const r0425 = lshift(r0405, r0408);
                  ir_expression *const r0426 = neg(r0408);
                  ir_expression *const r0427 = bit_and(r0426, body.constant(int(31)));
                  ir_expression *const r0428 = rshift(r0406, r0427);
                  body.emit(assign(r0422, bit_or(r0425, r0428), 0x01));


               body.instructions = f0423_parent_instructions;
               body.emit(f0423);

               /* END IF */

               body.emit(assign(r0405, r0422, 0x01));

               body.emit(assign(r0406, r0421, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f041F->else_instructions;

               ir_variable *const r0429 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0429, body.constant(0u), 0x01));

               ir_variable *const r042A = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r042A, neg(r0408), 0x01));

               ir_variable *const r042B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r042B);
               ir_variable *const r042C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r042C);
               ir_variable *const r042D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r042D);
               ir_variable *const r042E = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r042F = neg(r042A);
               body.emit(assign(r042E, bit_and(r042F, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0431 = equal(r042A, body.constant(int(0)));
               ir_if *f0430 = new(mem_ctx) ir_if(operand(r0431).val);
               exec_list *const f0430_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0430->then_instructions;

                  body.emit(assign(r042B, r0429, 0x01));

                  body.emit(assign(r042C, r0406, 0x01));

                  body.emit(assign(r042D, r0405, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0430->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0433 = less(r042A, body.constant(int(32)));
                  ir_if *f0432 = new(mem_ctx) ir_if(operand(r0433).val);
                  exec_list *const f0432_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0432->then_instructions;

                     body.emit(assign(r042B, lshift(r0406, r042E), 0x01));

                     ir_expression *const r0434 = lshift(r0405, r042E);
                     ir_expression *const r0435 = rshift(r0406, r042A);
                     body.emit(assign(r042C, bit_or(r0434, r0435), 0x01));

                     body.emit(assign(r042D, rshift(r0405, r042A), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0432->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0437 = equal(r042A, body.constant(int(32)));
                     ir_if *f0436 = new(mem_ctx) ir_if(operand(r0437).val);
                     exec_list *const f0436_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0436->then_instructions;

                        body.emit(assign(r042B, r0406, 0x01));

                        body.emit(assign(r042C, r0405, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0436->else_instructions;

                        body.emit(assign(r0429, bit_or(body.constant(0u), r0406), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0439 = less(r042A, body.constant(int(64)));
                        ir_if *f0438 = new(mem_ctx) ir_if(operand(r0439).val);
                        exec_list *const f0438_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0438->then_instructions;

                           body.emit(assign(r042B, lshift(r0405, r042E), 0x01));

                           ir_expression *const r043A = bit_and(r042A, body.constant(int(31)));
                           body.emit(assign(r042C, rshift(r0405, r043A), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0438->else_instructions;

                           ir_variable *const r043B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r043D = equal(r042A, body.constant(int(64)));
                           ir_if *f043C = new(mem_ctx) ir_if(operand(r043D).val);
                           exec_list *const f043C_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f043C->then_instructions;

                              body.emit(assign(r043B, r0405, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f043C->else_instructions;

                              ir_expression *const r043E = nequal(r0405, body.constant(0u));
                              ir_expression *const r043F = expr(ir_unop_b2i, r043E);
                              body.emit(assign(r043B, expr(ir_unop_i2u, r043F), 0x01));


                           body.instructions = f043C_parent_instructions;
                           body.emit(f043C);

                           /* END IF */

                           body.emit(assign(r042B, r043B, 0x01));

                           body.emit(assign(r042C, body.constant(0u), 0x01));


                        body.instructions = f0438_parent_instructions;
                        body.emit(f0438);

                        /* END IF */


                     body.instructions = f0436_parent_instructions;
                     body.emit(f0436);

                     /* END IF */

                     body.emit(assign(r042D, body.constant(0u), 0x01));


                  body.instructions = f0432_parent_instructions;
                  body.emit(f0432);

                  /* END IF */

                  ir_expression *const r0440 = nequal(r0429, body.constant(0u));
                  ir_expression *const r0441 = expr(ir_unop_b2i, r0440);
                  ir_expression *const r0442 = expr(ir_unop_i2u, r0441);
                  body.emit(assign(r042B, bit_or(r042B, r0442), 0x01));


               body.instructions = f0430_parent_instructions;
               body.emit(f0430);

               /* END IF */

               body.emit(assign(r0405, r042D, 0x01));

               body.emit(assign(r0406, r042C, 0x01));

               body.emit(assign(r0407, r042B, 0x01));


            body.instructions = f041F_parent_instructions;
            body.emit(f041F);

            /* END IF */

            body.emit(assign(r0404, sub(r0404, r0408), 0x01));

            ir_variable *const r0443 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0443, r0404, 0x01));

            ir_variable *const r0444 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0444, r0405, 0x01));

            ir_variable *const r0445 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0445, r0406, 0x01));

            ir_variable *const r0446 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0446, r0407, 0x01));

            ir_variable *const r0447 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0447, body.constant(true), 0x01));

            ir_variable *const r0448 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0449 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0449);
            ir_expression *const r044A = expr(ir_unop_u2i, r0407);
            body.emit(assign(r0449, less(r044A, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r044C = lequal(body.constant(int(2045)), r0404);
            ir_if *f044B = new(mem_ctx) ir_if(operand(r044C).val);
            exec_list *const f044B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f044B->then_instructions;

               /* IF CONDITION */
               ir_expression *const r044E = less(body.constant(int(2045)), r0404);
               ir_expression *const r044F = equal(r0404, body.constant(int(2045)));
               ir_expression *const r0450 = equal(body.constant(2097151u), r0405);
               ir_expression *const r0451 = equal(body.constant(4294967295u), r0406);
               ir_expression *const r0452 = logic_and(r0450, r0451);
               ir_expression *const r0453 = logic_and(r044F, r0452);
               ir_expression *const r0454 = logic_and(r0453, r0449);
               ir_expression *const r0455 = logic_or(r044E, r0454);
               ir_if *f044D = new(mem_ctx) ir_if(operand(r0455).val);
               exec_list *const f044D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f044D->then_instructions;

                  ir_variable *const r0456 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0456);
                  ir_expression *const r0457 = lshift(r0219, body.constant(int(31)));
                  body.emit(assign(r0456, add(r0457, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0456, body.constant(0u), 0x01));

                  body.emit(assign(r0448, r0456, 0x03));

                  body.emit(assign(r0447, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f044D->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0459 = less(r0404, body.constant(int(0)));
                  ir_if *f0458 = new(mem_ctx) ir_if(operand(r0459).val);
                  exec_list *const f0458_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0458->then_instructions;

                     ir_variable *const r045A = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r045A, r0407, 0x01));

                     ir_variable *const r045B = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r045B, neg(r0404), 0x01));

                     ir_variable *const r045C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r045C);
                     ir_variable *const r045D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r045D);
                     ir_variable *const r045E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r045E);
                     ir_variable *const r045F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0460 = neg(r045B);
                     body.emit(assign(r045F, bit_and(r0460, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0462 = equal(r045B, body.constant(int(0)));
                     ir_if *f0461 = new(mem_ctx) ir_if(operand(r0462).val);
                     exec_list *const f0461_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0461->then_instructions;

                        body.emit(assign(r045C, r0407, 0x01));

                        body.emit(assign(r045D, r0406, 0x01));

                        body.emit(assign(r045E, r0405, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0461->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0464 = less(r045B, body.constant(int(32)));
                        ir_if *f0463 = new(mem_ctx) ir_if(operand(r0464).val);
                        exec_list *const f0463_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0463->then_instructions;

                           body.emit(assign(r045C, lshift(r0406, r045F), 0x01));

                           ir_expression *const r0465 = lshift(r0405, r045F);
                           ir_expression *const r0466 = rshift(r0406, r045B);
                           body.emit(assign(r045D, bit_or(r0465, r0466), 0x01));

                           body.emit(assign(r045E, rshift(r0405, r045B), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0463->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0468 = equal(r045B, body.constant(int(32)));
                           ir_if *f0467 = new(mem_ctx) ir_if(operand(r0468).val);
                           exec_list *const f0467_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0467->then_instructions;

                              body.emit(assign(r045C, r0406, 0x01));

                              body.emit(assign(r045D, r0405, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0467->else_instructions;

                              body.emit(assign(r045A, bit_or(r0407, r0406), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r046A = less(r045B, body.constant(int(64)));
                              ir_if *f0469 = new(mem_ctx) ir_if(operand(r046A).val);
                              exec_list *const f0469_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0469->then_instructions;

                                 body.emit(assign(r045C, lshift(r0405, r045F), 0x01));

                                 ir_expression *const r046B = bit_and(r045B, body.constant(int(31)));
                                 body.emit(assign(r045D, rshift(r0405, r046B), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0469->else_instructions;

                                 ir_variable *const r046C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r046E = equal(r045B, body.constant(int(64)));
                                 ir_if *f046D = new(mem_ctx) ir_if(operand(r046E).val);
                                 exec_list *const f046D_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f046D->then_instructions;

                                    body.emit(assign(r046C, r0405, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f046D->else_instructions;

                                    ir_expression *const r046F = nequal(r0405, body.constant(0u));
                                    ir_expression *const r0470 = expr(ir_unop_b2i, r046F);
                                    body.emit(assign(r046C, expr(ir_unop_i2u, r0470), 0x01));


                                 body.instructions = f046D_parent_instructions;
                                 body.emit(f046D);

                                 /* END IF */

                                 body.emit(assign(r045C, r046C, 0x01));

                                 body.emit(assign(r045D, body.constant(0u), 0x01));


                              body.instructions = f0469_parent_instructions;
                              body.emit(f0469);

                              /* END IF */


                           body.instructions = f0467_parent_instructions;
                           body.emit(f0467);

                           /* END IF */

                           body.emit(assign(r045E, body.constant(0u), 0x01));


                        body.instructions = f0463_parent_instructions;
                        body.emit(f0463);

                        /* END IF */

                        ir_expression *const r0471 = nequal(r045A, body.constant(0u));
                        ir_expression *const r0472 = expr(ir_unop_b2i, r0471);
                        ir_expression *const r0473 = expr(ir_unop_i2u, r0472);
                        body.emit(assign(r045C, bit_or(r045C, r0473), 0x01));


                     body.instructions = f0461_parent_instructions;
                     body.emit(f0461);

                     /* END IF */

                     body.emit(assign(r0444, r045E, 0x01));

                     body.emit(assign(r0445, r045D, 0x01));

                     body.emit(assign(r0446, r045C, 0x01));

                     body.emit(assign(r0443, body.constant(int(0)), 0x01));

                     body.emit(assign(r0449, less(r045C, body.constant(0u)), 0x01));


                  body.instructions = f0458_parent_instructions;
                  body.emit(f0458);

                  /* END IF */


               body.instructions = f044D_parent_instructions;
               body.emit(f044D);

               /* END IF */


            body.instructions = f044B_parent_instructions;
            body.emit(f044B);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0474 = new(mem_ctx) ir_if(operand(r0447).val);
            exec_list *const f0474_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0474->then_instructions;

               /* IF CONDITION */
               ir_if *f0475 = new(mem_ctx) ir_if(operand(r0449).val);
               exec_list *const f0475_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0475->then_instructions;

                  ir_variable *const r0476 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0476, add(r0445, body.constant(1u)), 0x01));

                  ir_expression *const r0477 = less(r0476, r0445);
                  ir_expression *const r0478 = expr(ir_unop_b2i, r0477);
                  ir_expression *const r0479 = expr(ir_unop_i2u, r0478);
                  body.emit(assign(r0444, add(r0444, r0479), 0x01));

                  ir_expression *const r047A = equal(r0446, body.constant(0u));
                  ir_expression *const r047B = expr(ir_unop_b2i, r047A);
                  ir_expression *const r047C = expr(ir_unop_i2u, r047B);
                  ir_expression *const r047D = add(r0446, r047C);
                  ir_expression *const r047E = bit_and(r047D, body.constant(1u));
                  ir_expression *const r047F = expr(ir_unop_bit_not, r047E);
                  body.emit(assign(r0445, bit_and(r0476, r047F), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0475->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0481 = bit_or(r0444, r0445);
                  ir_expression *const r0482 = equal(r0481, body.constant(0u));
                  ir_if *f0480 = new(mem_ctx) ir_if(operand(r0482).val);
                  exec_list *const f0480_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0480->then_instructions;

                     body.emit(assign(r0443, body.constant(int(0)), 0x01));


                  body.instructions = f0480_parent_instructions;
                  body.emit(f0480);

                  /* END IF */


               body.instructions = f0475_parent_instructions;
               body.emit(f0475);

               /* END IF */

               ir_variable *const r0483 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0483);
               ir_expression *const r0484 = lshift(r0219, body.constant(int(31)));
               ir_expression *const r0485 = expr(ir_unop_i2u, r0443);
               ir_expression *const r0486 = lshift(r0485, body.constant(int(20)));
               ir_expression *const r0487 = add(r0484, r0486);
               body.emit(assign(r0483, add(r0487, r0444), 0x02));

               body.emit(assign(r0483, r0445, 0x01));

               body.emit(assign(r0448, r0483, 0x03));

               body.emit(assign(r0447, body.constant(false), 0x01));


            body.instructions = f0474_parent_instructions;
            body.emit(f0474);

            /* END IF */

            body.emit(assign(r0217, r0448, 0x03));

            body.emit(assign(r0216, body.constant(false), 0x01));


         body.instructions = f03C3_parent_instructions;
         body.emit(f03C3);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f03C1->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0489 = less(r03A9, body.constant(int(0)));
         ir_if *f0488 = new(mem_ctx) ir_if(operand(r0489).val);
         exec_list *const f0488_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0488->then_instructions;

            /* IF CONDITION */
            ir_expression *const r048B = equal(r03B4, body.constant(int(2047)));
            ir_if *f048A = new(mem_ctx) ir_if(operand(r048B).val);
            exec_list *const f048A_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f048A->then_instructions;

               /* IF CONDITION */
               ir_expression *const r048D = bit_or(r03AC, r03AD);
               ir_expression *const r048E = nequal(r048D, body.constant(0u));
               ir_if *f048C = new(mem_ctx) ir_if(operand(r048E).val);
               exec_list *const f048C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f048C->then_instructions;

                  ir_variable *const r048F = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r048F, swizzle_x(r0214), 0x01));

                  ir_variable *const r0490 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0490, swizzle_x(r0215), 0x01));

                  ir_variable *const r0491 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0492 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r0493 = lshift(swizzle_y(r0215), body.constant(int(1)));
                  ir_expression *const r0494 = lequal(body.constant(4292870144u), r0493);
                  ir_expression *const r0495 = nequal(swizzle_x(r0215), body.constant(0u));
                  ir_expression *const r0496 = bit_and(swizzle_y(r0215), body.constant(1048575u));
                  ir_expression *const r0497 = nequal(r0496, body.constant(0u));
                  ir_expression *const r0498 = logic_or(r0495, r0497);
                  body.emit(assign(r0492, logic_and(r0494, r0498), 0x01));

                  body.emit(assign(r048F, bit_or(swizzle_y(r0214), body.constant(524288u)), 0x02));

                  body.emit(assign(r0490, bit_or(swizzle_y(r0215), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r049A = lshift(swizzle_y(r0214), body.constant(int(1)));
                  ir_expression *const r049B = lequal(body.constant(4292870144u), r049A);
                  ir_expression *const r049C = nequal(swizzle_x(r0214), body.constant(0u));
                  ir_expression *const r049D = bit_and(swizzle_y(r0214), body.constant(1048575u));
                  ir_expression *const r049E = nequal(r049D, body.constant(0u));
                  ir_expression *const r049F = logic_or(r049C, r049E);
                  ir_expression *const r04A0 = logic_and(r049B, r049F);
                  ir_if *f0499 = new(mem_ctx) ir_if(operand(r04A0).val);
                  exec_list *const f0499_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0499->then_instructions;

                     ir_variable *const r04A1 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f04A2 = new(mem_ctx) ir_if(operand(r0492).val);
                     exec_list *const f04A2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04A2->then_instructions;

                        body.emit(assign(r04A1, r0490, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04A2->else_instructions;

                        body.emit(assign(r04A1, r048F, 0x03));


                     body.instructions = f04A2_parent_instructions;
                     body.emit(f04A2);

                     /* END IF */

                     body.emit(assign(r0491, r04A1, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0499->else_instructions;

                     body.emit(assign(r0491, r0490, 0x03));


                  body.instructions = f0499_parent_instructions;
                  body.emit(f0499);

                  /* END IF */

                  body.emit(assign(r0217, r0491, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f048C->else_instructions;

                  ir_variable *const r04A3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r04A3);
                  ir_expression *const r04A4 = bit_xor(r0219, body.constant(1u));
                  ir_expression *const r04A5 = lshift(r04A4, body.constant(int(31)));
                  body.emit(assign(r04A3, add(r04A5, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r04A3, body.constant(0u), 0x01));

                  body.emit(assign(r0217, r04A3, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


               body.instructions = f048C_parent_instructions;
               body.emit(f048C);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f048A->else_instructions;

               /* IF CONDITION */
               ir_expression *const r04A7 = equal(r03B1, body.constant(int(0)));
               ir_if *f04A6 = new(mem_ctx) ir_if(operand(r04A7).val);
               exec_list *const f04A6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04A6->then_instructions;

                  body.emit(assign(r03A9, add(r03A9, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04A6->else_instructions;

                  body.emit(assign(r03AE, bit_or(r03AE, body.constant(1073741824u)), 0x01));


               body.instructions = f04A6_parent_instructions;
               body.emit(f04A6);

               /* END IF */

               ir_variable *const r04A8 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r04A8, neg(r03A9), 0x01));

               ir_variable *const r04A9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r04A9);
               ir_variable *const r04AA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r04AA);
               ir_variable *const r04AB = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r04AC = neg(r04A8);
               body.emit(assign(r04AB, bit_and(r04AC, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04AE = equal(r04A8, body.constant(int(0)));
               ir_if *f04AD = new(mem_ctx) ir_if(operand(r04AE).val);
               exec_list *const f04AD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04AD->then_instructions;

                  body.emit(assign(r04A9, r03B7, 0x01));

                  body.emit(assign(r04AA, r03AE, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04AD->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04B0 = less(r04A8, body.constant(int(32)));
                  ir_if *f04AF = new(mem_ctx) ir_if(operand(r04B0).val);
                  exec_list *const f04AF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04AF->then_instructions;

                     ir_expression *const r04B1 = lshift(r03AE, r04AB);
                     ir_expression *const r04B2 = rshift(r03B7, r04A8);
                     ir_expression *const r04B3 = bit_or(r04B1, r04B2);
                     ir_expression *const r04B4 = lshift(r03B7, r04AB);
                     ir_expression *const r04B5 = nequal(r04B4, body.constant(0u));
                     ir_expression *const r04B6 = expr(ir_unop_b2i, r04B5);
                     ir_expression *const r04B7 = expr(ir_unop_i2u, r04B6);
                     body.emit(assign(r04A9, bit_or(r04B3, r04B7), 0x01));

                     body.emit(assign(r04AA, rshift(r03AE, r04A8), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04AF->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04B9 = equal(r04A8, body.constant(int(32)));
                     ir_if *f04B8 = new(mem_ctx) ir_if(operand(r04B9).val);
                     exec_list *const f04B8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04B8->then_instructions;

                        ir_expression *const r04BA = nequal(r03B7, body.constant(0u));
                        ir_expression *const r04BB = expr(ir_unop_b2i, r04BA);
                        ir_expression *const r04BC = expr(ir_unop_i2u, r04BB);
                        body.emit(assign(r04A9, bit_or(r03AE, r04BC), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04B8->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04BE = less(r04A8, body.constant(int(64)));
                        ir_if *f04BD = new(mem_ctx) ir_if(operand(r04BE).val);
                        exec_list *const f04BD_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04BD->then_instructions;

                           ir_expression *const r04BF = bit_and(r04A8, body.constant(int(31)));
                           ir_expression *const r04C0 = rshift(r03AE, r04BF);
                           ir_expression *const r04C1 = lshift(r03AE, r04AB);
                           ir_expression *const r04C2 = bit_or(r04C1, r03B7);
                           ir_expression *const r04C3 = nequal(r04C2, body.constant(0u));
                           ir_expression *const r04C4 = expr(ir_unop_b2i, r04C3);
                           ir_expression *const r04C5 = expr(ir_unop_i2u, r04C4);
                           body.emit(assign(r04A9, bit_or(r04C0, r04C5), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04BD->else_instructions;

                           ir_expression *const r04C6 = bit_or(r03AE, r03B7);
                           ir_expression *const r04C7 = nequal(r04C6, body.constant(0u));
                           ir_expression *const r04C8 = expr(ir_unop_b2i, r04C7);
                           body.emit(assign(r04A9, expr(ir_unop_i2u, r04C8), 0x01));


                        body.instructions = f04BD_parent_instructions;
                        body.emit(f04BD);

                        /* END IF */


                     body.instructions = f04B8_parent_instructions;
                     body.emit(f04B8);

                     /* END IF */

                     body.emit(assign(r04AA, body.constant(0u), 0x01));


                  body.instructions = f04AF_parent_instructions;
                  body.emit(f04AF);

                  /* END IF */


               body.instructions = f04AD_parent_instructions;
               body.emit(f04AD);

               /* END IF */

               body.emit(assign(r03AE, r04AA, 0x01));

               body.emit(assign(r03AF, r04A9, 0x01));

               body.emit(assign(r03AC, bit_or(r03AC, body.constant(1073741824u)), 0x01));

               ir_variable *const r04C9 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r04CA = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r04CA, sub(r03AD, r04A9), 0x01));

               ir_expression *const r04CB = sub(r03AC, r04AA);
               ir_expression *const r04CC = less(r03AD, r04A9);
               ir_expression *const r04CD = expr(ir_unop_b2i, r04CC);
               ir_expression *const r04CE = expr(ir_unop_i2u, r04CD);
               body.emit(assign(r04C9, sub(r04CB, r04CE), 0x01));

               body.emit(assign(r0218, bit_xor(r0219, body.constant(1u)), 0x01));

               body.emit(assign(r03B0, add(r03B4, body.constant(int(-1))), 0x01));

               ir_variable *const r04CF = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04CF, add(r03B0, body.constant(int(-10))), 0x01));

               ir_variable *const r04D0 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04D0, r04C9, 0x01));

               ir_variable *const r04D1 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04D1, r04CA, 0x01));

               ir_variable *const r04D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r04D2);
               ir_variable *const r04D3 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04D3);
               /* IF CONDITION */
               ir_expression *const r04D5 = equal(r04C9, body.constant(0u));
               ir_if *f04D4 = new(mem_ctx) ir_if(operand(r04D5).val);
               exec_list *const f04D4_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04D4->then_instructions;

                  body.emit(assign(r04D0, r04CA, 0x01));

                  body.emit(assign(r04D1, body.constant(0u), 0x01));

                  body.emit(assign(r04CF, add(r04CF, body.constant(int(-32))), 0x01));


               body.instructions = f04D4_parent_instructions;
               body.emit(f04D4);

               /* END IF */

               ir_variable *const r04D6 = body.make_temp(glsl_type::uint_type, "a");
               body.emit(assign(r04D6, r04D0, 0x01));

               ir_variable *const r04D7 = body.make_temp(glsl_type::int_type, "return_value");
               ir_variable *const r04D8 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04D8);
               /* IF CONDITION */
               ir_expression *const r04DA = equal(r04D0, body.constant(0u));
               ir_if *f04D9 = new(mem_ctx) ir_if(operand(r04DA).val);
               exec_list *const f04D9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04D9->then_instructions;

                  body.emit(assign(r04D7, body.constant(int(32)), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04D9->else_instructions;

                  body.emit(assign(r04D8, body.constant(int(0)), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04DC = bit_and(r04D0, body.constant(4294901760u));
                  ir_expression *const r04DD = equal(r04DC, body.constant(0u));
                  ir_if *f04DB = new(mem_ctx) ir_if(operand(r04DD).val);
                  exec_list *const f04DB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04DB->then_instructions;

                     body.emit(assign(r04D8, body.constant(int(16)), 0x01));

                     body.emit(assign(r04D6, lshift(r04D0, body.constant(int(16))), 0x01));


                  body.instructions = f04DB_parent_instructions;
                  body.emit(f04DB);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04DF = bit_and(r04D6, body.constant(4278190080u));
                  ir_expression *const r04E0 = equal(r04DF, body.constant(0u));
                  ir_if *f04DE = new(mem_ctx) ir_if(operand(r04E0).val);
                  exec_list *const f04DE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04DE->then_instructions;

                     body.emit(assign(r04D8, add(r04D8, body.constant(int(8))), 0x01));

                     body.emit(assign(r04D6, lshift(r04D6, body.constant(int(8))), 0x01));


                  body.instructions = f04DE_parent_instructions;
                  body.emit(f04DE);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04E2 = bit_and(r04D6, body.constant(4026531840u));
                  ir_expression *const r04E3 = equal(r04E2, body.constant(0u));
                  ir_if *f04E1 = new(mem_ctx) ir_if(operand(r04E3).val);
                  exec_list *const f04E1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04E1->then_instructions;

                     body.emit(assign(r04D8, add(r04D8, body.constant(int(4))), 0x01));

                     body.emit(assign(r04D6, lshift(r04D6, body.constant(int(4))), 0x01));


                  body.instructions = f04E1_parent_instructions;
                  body.emit(f04E1);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04E5 = bit_and(r04D6, body.constant(3221225472u));
                  ir_expression *const r04E6 = equal(r04E5, body.constant(0u));
                  ir_if *f04E4 = new(mem_ctx) ir_if(operand(r04E6).val);
                  exec_list *const f04E4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04E4->then_instructions;

                     body.emit(assign(r04D8, add(r04D8, body.constant(int(2))), 0x01));

                     body.emit(assign(r04D6, lshift(r04D6, body.constant(int(2))), 0x01));


                  body.instructions = f04E4_parent_instructions;
                  body.emit(f04E4);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04E8 = bit_and(r04D6, body.constant(2147483648u));
                  ir_expression *const r04E9 = equal(r04E8, body.constant(0u));
                  ir_if *f04E7 = new(mem_ctx) ir_if(operand(r04E9).val);
                  exec_list *const f04E7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04E7->then_instructions;

                     body.emit(assign(r04D8, add(r04D8, body.constant(int(1))), 0x01));


                  body.instructions = f04E7_parent_instructions;
                  body.emit(f04E7);

                  /* END IF */

                  body.emit(assign(r04D7, r04D8, 0x01));


               body.instructions = f04D9_parent_instructions;
               body.emit(f04D9);

               /* END IF */

               body.emit(assign(r04D3, add(r04D7, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04EB = lequal(body.constant(int(0)), r04D3);
               ir_if *f04EA = new(mem_ctx) ir_if(operand(r04EB).val);
               exec_list *const f04EA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04EA->then_instructions;

                  body.emit(assign(r04D2, body.constant(0u), 0x01));

                  ir_variable *const r04EC = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r04EC, lshift(r04D1, r04D3), 0x01));

                  ir_variable *const r04ED = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r04EF = equal(r04D3, body.constant(int(0)));
                  ir_if *f04EE = new(mem_ctx) ir_if(operand(r04EF).val);
                  exec_list *const f04EE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04EE->then_instructions;

                     body.emit(assign(r04ED, r04D0, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04EE->else_instructions;

                     ir_expression *const r04F0 = lshift(r04D0, r04D3);
                     ir_expression *const r04F1 = neg(r04D3);
                     ir_expression *const r04F2 = bit_and(r04F1, body.constant(int(31)));
                     ir_expression *const r04F3 = rshift(r04D1, r04F2);
                     body.emit(assign(r04ED, bit_or(r04F0, r04F3), 0x01));


                  body.instructions = f04EE_parent_instructions;
                  body.emit(f04EE);

                  /* END IF */

                  body.emit(assign(r04D0, r04ED, 0x01));

                  body.emit(assign(r04D1, r04EC, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04EA->else_instructions;

                  ir_variable *const r04F4 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r04F4, body.constant(0u), 0x01));

                  ir_variable *const r04F5 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r04F5, neg(r04D3), 0x01));

                  ir_variable *const r04F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04F6);
                  ir_variable *const r04F7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r04F7);
                  ir_variable *const r04F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04F8);
                  ir_variable *const r04F9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04FA = neg(r04F5);
                  body.emit(assign(r04F9, bit_and(r04FA, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04FC = equal(r04F5, body.constant(int(0)));
                  ir_if *f04FB = new(mem_ctx) ir_if(operand(r04FC).val);
                  exec_list *const f04FB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04FB->then_instructions;

                     body.emit(assign(r04F6, r04F4, 0x01));

                     body.emit(assign(r04F7, r04D1, 0x01));

                     body.emit(assign(r04F8, r04D0, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04FB->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04FE = less(r04F5, body.constant(int(32)));
                     ir_if *f04FD = new(mem_ctx) ir_if(operand(r04FE).val);
                     exec_list *const f04FD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04FD->then_instructions;

                        body.emit(assign(r04F6, lshift(r04D1, r04F9), 0x01));

                        ir_expression *const r04FF = lshift(r04D0, r04F9);
                        ir_expression *const r0500 = rshift(r04D1, r04F5);
                        body.emit(assign(r04F7, bit_or(r04FF, r0500), 0x01));

                        body.emit(assign(r04F8, rshift(r04D0, r04F5), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04FD->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0502 = equal(r04F5, body.constant(int(32)));
                        ir_if *f0501 = new(mem_ctx) ir_if(operand(r0502).val);
                        exec_list *const f0501_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0501->then_instructions;

                           body.emit(assign(r04F6, r04D1, 0x01));

                           body.emit(assign(r04F7, r04D0, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0501->else_instructions;

                           body.emit(assign(r04F4, bit_or(body.constant(0u), r04D1), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0504 = less(r04F5, body.constant(int(64)));
                           ir_if *f0503 = new(mem_ctx) ir_if(operand(r0504).val);
                           exec_list *const f0503_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0503->then_instructions;

                              body.emit(assign(r04F6, lshift(r04D0, r04F9), 0x01));

                              ir_expression *const r0505 = bit_and(r04F5, body.constant(int(31)));
                              body.emit(assign(r04F7, rshift(r04D0, r0505), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0503->else_instructions;

                              ir_variable *const r0506 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r0508 = equal(r04F5, body.constant(int(64)));
                              ir_if *f0507 = new(mem_ctx) ir_if(operand(r0508).val);
                              exec_list *const f0507_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0507->then_instructions;

                                 body.emit(assign(r0506, r04D0, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0507->else_instructions;

                                 ir_expression *const r0509 = nequal(r04D0, body.constant(0u));
                                 ir_expression *const r050A = expr(ir_unop_b2i, r0509);
                                 body.emit(assign(r0506, expr(ir_unop_i2u, r050A), 0x01));


                              body.instructions = f0507_parent_instructions;
                              body.emit(f0507);

                              /* END IF */

                              body.emit(assign(r04F6, r0506, 0x01));

                              body.emit(assign(r04F7, body.constant(0u), 0x01));


                           body.instructions = f0503_parent_instructions;
                           body.emit(f0503);

                           /* END IF */


                        body.instructions = f0501_parent_instructions;
                        body.emit(f0501);

                        /* END IF */

                        body.emit(assign(r04F8, body.constant(0u), 0x01));


                     body.instructions = f04FD_parent_instructions;
                     body.emit(f04FD);

                     /* END IF */

                     ir_expression *const r050B = nequal(r04F4, body.constant(0u));
                     ir_expression *const r050C = expr(ir_unop_b2i, r050B);
                     ir_expression *const r050D = expr(ir_unop_i2u, r050C);
                     body.emit(assign(r04F6, bit_or(r04F6, r050D), 0x01));


                  body.instructions = f04FB_parent_instructions;
                  body.emit(f04FB);

                  /* END IF */

                  body.emit(assign(r04D0, r04F8, 0x01));

                  body.emit(assign(r04D1, r04F7, 0x01));

                  body.emit(assign(r04D2, r04F6, 0x01));


               body.instructions = f04EA_parent_instructions;
               body.emit(f04EA);

               /* END IF */

               body.emit(assign(r04CF, sub(r04CF, r04D3), 0x01));

               ir_variable *const r050E = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r050E, r04CF, 0x01));

               ir_variable *const r050F = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r050F, r04D0, 0x01));

               ir_variable *const r0510 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0510, r04D1, 0x01));

               ir_variable *const r0511 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r0511, r04D2, 0x01));

               ir_variable *const r0512 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0512, body.constant(true), 0x01));

               ir_variable *const r0513 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0514 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0514);
               ir_expression *const r0515 = expr(ir_unop_u2i, r04D2);
               body.emit(assign(r0514, less(r0515, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0517 = lequal(body.constant(int(2045)), r04CF);
               ir_if *f0516 = new(mem_ctx) ir_if(operand(r0517).val);
               exec_list *const f0516_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0516->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0519 = less(body.constant(int(2045)), r04CF);
                  ir_expression *const r051A = equal(r04CF, body.constant(int(2045)));
                  ir_expression *const r051B = equal(body.constant(2097151u), r04D0);
                  ir_expression *const r051C = equal(body.constant(4294967295u), r04D1);
                  ir_expression *const r051D = logic_and(r051B, r051C);
                  ir_expression *const r051E = logic_and(r051A, r051D);
                  ir_expression *const r051F = logic_and(r051E, r0514);
                  ir_expression *const r0520 = logic_or(r0519, r051F);
                  ir_if *f0518 = new(mem_ctx) ir_if(operand(r0520).val);
                  exec_list *const f0518_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0518->then_instructions;

                     ir_variable *const r0521 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0521);
                     ir_expression *const r0522 = lshift(r0218, body.constant(int(31)));
                     body.emit(assign(r0521, add(r0522, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r0521, body.constant(0u), 0x01));

                     body.emit(assign(r0513, r0521, 0x03));

                     body.emit(assign(r0512, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0518->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0524 = less(r04CF, body.constant(int(0)));
                     ir_if *f0523 = new(mem_ctx) ir_if(operand(r0524).val);
                     exec_list *const f0523_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0523->then_instructions;

                        ir_variable *const r0525 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0525, r04D2, 0x01));

                        ir_variable *const r0526 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0526, neg(r04CF), 0x01));

                        ir_variable *const r0527 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0527);
                        ir_variable *const r0528 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r0528);
                        ir_variable *const r0529 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0529);
                        ir_variable *const r052A = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r052B = neg(r0526);
                        body.emit(assign(r052A, bit_and(r052B, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r052D = equal(r0526, body.constant(int(0)));
                        ir_if *f052C = new(mem_ctx) ir_if(operand(r052D).val);
                        exec_list *const f052C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f052C->then_instructions;

                           body.emit(assign(r0527, r04D2, 0x01));

                           body.emit(assign(r0528, r04D1, 0x01));

                           body.emit(assign(r0529, r04D0, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f052C->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r052F = less(r0526, body.constant(int(32)));
                           ir_if *f052E = new(mem_ctx) ir_if(operand(r052F).val);
                           exec_list *const f052E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f052E->then_instructions;

                              body.emit(assign(r0527, lshift(r04D1, r052A), 0x01));

                              ir_expression *const r0530 = lshift(r04D0, r052A);
                              ir_expression *const r0531 = rshift(r04D1, r0526);
                              body.emit(assign(r0528, bit_or(r0530, r0531), 0x01));

                              body.emit(assign(r0529, rshift(r04D0, r0526), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f052E->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0533 = equal(r0526, body.constant(int(32)));
                              ir_if *f0532 = new(mem_ctx) ir_if(operand(r0533).val);
                              exec_list *const f0532_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0532->then_instructions;

                                 body.emit(assign(r0527, r04D1, 0x01));

                                 body.emit(assign(r0528, r04D0, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0532->else_instructions;

                                 body.emit(assign(r0525, bit_or(r04D2, r04D1), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0535 = less(r0526, body.constant(int(64)));
                                 ir_if *f0534 = new(mem_ctx) ir_if(operand(r0535).val);
                                 exec_list *const f0534_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0534->then_instructions;

                                    body.emit(assign(r0527, lshift(r04D0, r052A), 0x01));

                                    ir_expression *const r0536 = bit_and(r0526, body.constant(int(31)));
                                    body.emit(assign(r0528, rshift(r04D0, r0536), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0534->else_instructions;

                                    ir_variable *const r0537 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r0539 = equal(r0526, body.constant(int(64)));
                                    ir_if *f0538 = new(mem_ctx) ir_if(operand(r0539).val);
                                    exec_list *const f0538_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0538->then_instructions;

                                       body.emit(assign(r0537, r04D0, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0538->else_instructions;

                                       ir_expression *const r053A = nequal(r04D0, body.constant(0u));
                                       ir_expression *const r053B = expr(ir_unop_b2i, r053A);
                                       body.emit(assign(r0537, expr(ir_unop_i2u, r053B), 0x01));


                                    body.instructions = f0538_parent_instructions;
                                    body.emit(f0538);

                                    /* END IF */

                                    body.emit(assign(r0527, r0537, 0x01));

                                    body.emit(assign(r0528, body.constant(0u), 0x01));


                                 body.instructions = f0534_parent_instructions;
                                 body.emit(f0534);

                                 /* END IF */


                              body.instructions = f0532_parent_instructions;
                              body.emit(f0532);

                              /* END IF */

                              body.emit(assign(r0529, body.constant(0u), 0x01));


                           body.instructions = f052E_parent_instructions;
                           body.emit(f052E);

                           /* END IF */

                           ir_expression *const r053C = nequal(r0525, body.constant(0u));
                           ir_expression *const r053D = expr(ir_unop_b2i, r053C);
                           ir_expression *const r053E = expr(ir_unop_i2u, r053D);
                           body.emit(assign(r0527, bit_or(r0527, r053E), 0x01));


                        body.instructions = f052C_parent_instructions;
                        body.emit(f052C);

                        /* END IF */

                        body.emit(assign(r050F, r0529, 0x01));

                        body.emit(assign(r0510, r0528, 0x01));

                        body.emit(assign(r0511, r0527, 0x01));

                        body.emit(assign(r050E, body.constant(int(0)), 0x01));

                        body.emit(assign(r0514, less(r0527, body.constant(0u)), 0x01));


                     body.instructions = f0523_parent_instructions;
                     body.emit(f0523);

                     /* END IF */


                  body.instructions = f0518_parent_instructions;
                  body.emit(f0518);

                  /* END IF */


               body.instructions = f0516_parent_instructions;
               body.emit(f0516);

               /* END IF */

               /* IF CONDITION */
               ir_if *f053F = new(mem_ctx) ir_if(operand(r0512).val);
               exec_list *const f053F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f053F->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0540 = new(mem_ctx) ir_if(operand(r0514).val);
                  exec_list *const f0540_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0540->then_instructions;

                     ir_variable *const r0541 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0541, add(r0510, body.constant(1u)), 0x01));

                     ir_expression *const r0542 = less(r0541, r0510);
                     ir_expression *const r0543 = expr(ir_unop_b2i, r0542);
                     ir_expression *const r0544 = expr(ir_unop_i2u, r0543);
                     body.emit(assign(r050F, add(r050F, r0544), 0x01));

                     ir_expression *const r0545 = equal(r0511, body.constant(0u));
                     ir_expression *const r0546 = expr(ir_unop_b2i, r0545);
                     ir_expression *const r0547 = expr(ir_unop_i2u, r0546);
                     ir_expression *const r0548 = add(r0511, r0547);
                     ir_expression *const r0549 = bit_and(r0548, body.constant(1u));
                     ir_expression *const r054A = expr(ir_unop_bit_not, r0549);
                     body.emit(assign(r0510, bit_and(r0541, r054A), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0540->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r054C = bit_or(r050F, r0510);
                     ir_expression *const r054D = equal(r054C, body.constant(0u));
                     ir_if *f054B = new(mem_ctx) ir_if(operand(r054D).val);
                     exec_list *const f054B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f054B->then_instructions;

                        body.emit(assign(r050E, body.constant(int(0)), 0x01));


                     body.instructions = f054B_parent_instructions;
                     body.emit(f054B);

                     /* END IF */


                  body.instructions = f0540_parent_instructions;
                  body.emit(f0540);

                  /* END IF */

                  ir_variable *const r054E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r054E);
                  ir_expression *const r054F = lshift(r0218, body.constant(int(31)));
                  ir_expression *const r0550 = expr(ir_unop_i2u, r050E);
                  ir_expression *const r0551 = lshift(r0550, body.constant(int(20)));
                  ir_expression *const r0552 = add(r054F, r0551);
                  body.emit(assign(r054E, add(r0552, r050F), 0x02));

                  body.emit(assign(r054E, r0510, 0x01));

                  body.emit(assign(r0513, r054E, 0x03));

                  body.emit(assign(r0512, body.constant(false), 0x01));


               body.instructions = f053F_parent_instructions;
               body.emit(f053F);

               /* END IF */

               body.emit(assign(r0217, r0513, 0x03));

               body.emit(assign(r0216, body.constant(false), 0x01));


            body.instructions = f048A_parent_instructions;
            body.emit(f048A);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0488->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0554 = equal(r03B1, body.constant(int(2047)));
            ir_if *f0553 = new(mem_ctx) ir_if(operand(r0554).val);
            exec_list *const f0553_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0553->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0556 = bit_or(r03AE, r03AF);
               ir_expression *const r0557 = bit_or(r03AC, r03AD);
               ir_expression *const r0558 = bit_or(r0556, r0557);
               ir_expression *const r0559 = nequal(r0558, body.constant(0u));
               ir_if *f0555 = new(mem_ctx) ir_if(operand(r0559).val);
               exec_list *const f0555_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0555->then_instructions;

                  ir_variable *const r055A = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r055A, swizzle_x(r0214), 0x01));

                  ir_variable *const r055B = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r055B, swizzle_x(r0215), 0x01));

                  ir_variable *const r055C = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r055D = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r055E = lshift(swizzle_y(r0215), body.constant(int(1)));
                  ir_expression *const r055F = lequal(body.constant(4292870144u), r055E);
                  ir_expression *const r0560 = nequal(swizzle_x(r0215), body.constant(0u));
                  ir_expression *const r0561 = bit_and(swizzle_y(r0215), body.constant(1048575u));
                  ir_expression *const r0562 = nequal(r0561, body.constant(0u));
                  ir_expression *const r0563 = logic_or(r0560, r0562);
                  body.emit(assign(r055D, logic_and(r055F, r0563), 0x01));

                  body.emit(assign(r055A, bit_or(swizzle_y(r0214), body.constant(524288u)), 0x02));

                  body.emit(assign(r055B, bit_or(swizzle_y(r0215), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0565 = lshift(swizzle_y(r0214), body.constant(int(1)));
                  ir_expression *const r0566 = lequal(body.constant(4292870144u), r0565);
                  ir_expression *const r0567 = nequal(swizzle_x(r0214), body.constant(0u));
                  ir_expression *const r0568 = bit_and(swizzle_y(r0214), body.constant(1048575u));
                  ir_expression *const r0569 = nequal(r0568, body.constant(0u));
                  ir_expression *const r056A = logic_or(r0567, r0569);
                  ir_expression *const r056B = logic_and(r0566, r056A);
                  ir_if *f0564 = new(mem_ctx) ir_if(operand(r056B).val);
                  exec_list *const f0564_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0564->then_instructions;

                     ir_variable *const r056C = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f056D = new(mem_ctx) ir_if(operand(r055D).val);
                     exec_list *const f056D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f056D->then_instructions;

                        body.emit(assign(r056C, r055B, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f056D->else_instructions;

                        body.emit(assign(r056C, r055A, 0x03));


                     body.instructions = f056D_parent_instructions;
                     body.emit(f056D);

                     /* END IF */

                     body.emit(assign(r055C, r056C, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0564->else_instructions;

                     body.emit(assign(r055C, r055B, 0x03));


                  body.instructions = f0564_parent_instructions;
                  body.emit(f0564);

                  /* END IF */

                  body.emit(assign(r0217, r055C, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0555->else_instructions;

                  ir_constant_data r056E_data;
                  memset(&r056E_data, 0, sizeof(ir_constant_data));
                  r056E_data.u[0] = 4294967295;
                  r056E_data.u[1] = 4294967295;
                  ir_constant *const r056E = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r056E_data);
                  body.emit(assign(r0217, r056E, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


               body.instructions = f0555_parent_instructions;
               body.emit(f0555);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0553->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0570 = equal(r03B1, body.constant(int(0)));
               ir_if *f056F = new(mem_ctx) ir_if(operand(r0570).val);
               exec_list *const f056F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f056F->then_instructions;

                  body.emit(assign(r03AB, body.constant(int(1)), 0x01));

                  body.emit(assign(r03AA, body.constant(int(1)), 0x01));


               body.instructions = f056F_parent_instructions;
               body.emit(f056F);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0572 = less(r03AC, r03AE);
               ir_if *f0571 = new(mem_ctx) ir_if(operand(r0572).val);
               exec_list *const f0571_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0571->then_instructions;

                  ir_variable *const r0573 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_variable *const r0574 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r0574, sub(r03AF, r03AD), 0x01));

                  ir_expression *const r0575 = sub(r03AE, r03AC);
                  ir_expression *const r0576 = less(r03AF, r03AD);
                  ir_expression *const r0577 = expr(ir_unop_b2i, r0576);
                  ir_expression *const r0578 = expr(ir_unop_i2u, r0577);
                  body.emit(assign(r0573, sub(r0575, r0578), 0x01));

                  body.emit(assign(r03B0, add(r03AB, body.constant(int(-1))), 0x01));

                  ir_variable *const r0579 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0579, add(r03B0, body.constant(int(-10))), 0x01));

                  ir_variable *const r057A = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r057A, r0573, 0x01));

                  ir_variable *const r057B = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r057B, r0574, 0x01));

                  ir_variable *const r057C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r057C);
                  ir_variable *const r057D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r057D);
                  /* IF CONDITION */
                  ir_expression *const r057F = equal(r0573, body.constant(0u));
                  ir_if *f057E = new(mem_ctx) ir_if(operand(r057F).val);
                  exec_list *const f057E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f057E->then_instructions;

                     body.emit(assign(r057A, r0574, 0x01));

                     body.emit(assign(r057B, body.constant(0u), 0x01));

                     body.emit(assign(r0579, add(r0579, body.constant(int(-32))), 0x01));


                  body.instructions = f057E_parent_instructions;
                  body.emit(f057E);

                  /* END IF */

                  ir_variable *const r0580 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r0580, r057A, 0x01));

                  ir_variable *const r0581 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r0582 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0582);
                  /* IF CONDITION */
                  ir_expression *const r0584 = equal(r057A, body.constant(0u));
                  ir_if *f0583 = new(mem_ctx) ir_if(operand(r0584).val);
                  exec_list *const f0583_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0583->then_instructions;

                     body.emit(assign(r0581, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0583->else_instructions;

                     body.emit(assign(r0582, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0586 = bit_and(r057A, body.constant(4294901760u));
                     ir_expression *const r0587 = equal(r0586, body.constant(0u));
                     ir_if *f0585 = new(mem_ctx) ir_if(operand(r0587).val);
                     exec_list *const f0585_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0585->then_instructions;

                        body.emit(assign(r0582, body.constant(int(16)), 0x01));

                        body.emit(assign(r0580, lshift(r057A, body.constant(int(16))), 0x01));


                     body.instructions = f0585_parent_instructions;
                     body.emit(f0585);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0589 = bit_and(r0580, body.constant(4278190080u));
                     ir_expression *const r058A = equal(r0589, body.constant(0u));
                     ir_if *f0588 = new(mem_ctx) ir_if(operand(r058A).val);
                     exec_list *const f0588_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0588->then_instructions;

                        body.emit(assign(r0582, add(r0582, body.constant(int(8))), 0x01));

                        body.emit(assign(r0580, lshift(r0580, body.constant(int(8))), 0x01));


                     body.instructions = f0588_parent_instructions;
                     body.emit(f0588);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r058C = bit_and(r0580, body.constant(4026531840u));
                     ir_expression *const r058D = equal(r058C, body.constant(0u));
                     ir_if *f058B = new(mem_ctx) ir_if(operand(r058D).val);
                     exec_list *const f058B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f058B->then_instructions;

                        body.emit(assign(r0582, add(r0582, body.constant(int(4))), 0x01));

                        body.emit(assign(r0580, lshift(r0580, body.constant(int(4))), 0x01));


                     body.instructions = f058B_parent_instructions;
                     body.emit(f058B);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r058F = bit_and(r0580, body.constant(3221225472u));
                     ir_expression *const r0590 = equal(r058F, body.constant(0u));
                     ir_if *f058E = new(mem_ctx) ir_if(operand(r0590).val);
                     exec_list *const f058E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f058E->then_instructions;

                        body.emit(assign(r0582, add(r0582, body.constant(int(2))), 0x01));

                        body.emit(assign(r0580, lshift(r0580, body.constant(int(2))), 0x01));


                     body.instructions = f058E_parent_instructions;
                     body.emit(f058E);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0592 = bit_and(r0580, body.constant(2147483648u));
                     ir_expression *const r0593 = equal(r0592, body.constant(0u));
                     ir_if *f0591 = new(mem_ctx) ir_if(operand(r0593).val);
                     exec_list *const f0591_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0591->then_instructions;

                        body.emit(assign(r0582, add(r0582, body.constant(int(1))), 0x01));


                     body.instructions = f0591_parent_instructions;
                     body.emit(f0591);

                     /* END IF */

                     body.emit(assign(r0581, r0582, 0x01));


                  body.instructions = f0583_parent_instructions;
                  body.emit(f0583);

                  /* END IF */

                  body.emit(assign(r057D, add(r0581, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0595 = lequal(body.constant(int(0)), r057D);
                  ir_if *f0594 = new(mem_ctx) ir_if(operand(r0595).val);
                  exec_list *const f0594_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0594->then_instructions;

                     body.emit(assign(r057C, body.constant(0u), 0x01));

                     ir_variable *const r0596 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r0596, lshift(r057B, r057D), 0x01));

                     ir_variable *const r0597 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0599 = equal(r057D, body.constant(int(0)));
                     ir_if *f0598 = new(mem_ctx) ir_if(operand(r0599).val);
                     exec_list *const f0598_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0598->then_instructions;

                        body.emit(assign(r0597, r057A, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0598->else_instructions;

                        ir_expression *const r059A = lshift(r057A, r057D);
                        ir_expression *const r059B = neg(r057D);
                        ir_expression *const r059C = bit_and(r059B, body.constant(int(31)));
                        ir_expression *const r059D = rshift(r057B, r059C);
                        body.emit(assign(r0597, bit_or(r059A, r059D), 0x01));


                     body.instructions = f0598_parent_instructions;
                     body.emit(f0598);

                     /* END IF */

                     body.emit(assign(r057A, r0597, 0x01));

                     body.emit(assign(r057B, r0596, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0594->else_instructions;

                     ir_variable *const r059E = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r059E, body.constant(0u), 0x01));

                     ir_variable *const r059F = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r059F, neg(r057D), 0x01));

                     ir_variable *const r05A0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r05A0);
                     ir_variable *const r05A1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r05A1);
                     ir_variable *const r05A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r05A2);
                     ir_variable *const r05A3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r05A4 = neg(r059F);
                     body.emit(assign(r05A3, bit_and(r05A4, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05A6 = equal(r059F, body.constant(int(0)));
                     ir_if *f05A5 = new(mem_ctx) ir_if(operand(r05A6).val);
                     exec_list *const f05A5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05A5->then_instructions;

                        body.emit(assign(r05A0, r059E, 0x01));

                        body.emit(assign(r05A1, r057B, 0x01));

                        body.emit(assign(r05A2, r057A, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05A5->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05A8 = less(r059F, body.constant(int(32)));
                        ir_if *f05A7 = new(mem_ctx) ir_if(operand(r05A8).val);
                        exec_list *const f05A7_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05A7->then_instructions;

                           body.emit(assign(r05A0, lshift(r057B, r05A3), 0x01));

                           ir_expression *const r05A9 = lshift(r057A, r05A3);
                           ir_expression *const r05AA = rshift(r057B, r059F);
                           body.emit(assign(r05A1, bit_or(r05A9, r05AA), 0x01));

                           body.emit(assign(r05A2, rshift(r057A, r059F), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05A7->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r05AC = equal(r059F, body.constant(int(32)));
                           ir_if *f05AB = new(mem_ctx) ir_if(operand(r05AC).val);
                           exec_list *const f05AB_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05AB->then_instructions;

                              body.emit(assign(r05A0, r057B, 0x01));

                              body.emit(assign(r05A1, r057A, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05AB->else_instructions;

                              body.emit(assign(r059E, bit_or(body.constant(0u), r057B), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r05AE = less(r059F, body.constant(int(64)));
                              ir_if *f05AD = new(mem_ctx) ir_if(operand(r05AE).val);
                              exec_list *const f05AD_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05AD->then_instructions;

                                 body.emit(assign(r05A0, lshift(r057A, r05A3), 0x01));

                                 ir_expression *const r05AF = bit_and(r059F, body.constant(int(31)));
                                 body.emit(assign(r05A1, rshift(r057A, r05AF), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05AD->else_instructions;

                                 ir_variable *const r05B0 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r05B2 = equal(r059F, body.constant(int(64)));
                                 ir_if *f05B1 = new(mem_ctx) ir_if(operand(r05B2).val);
                                 exec_list *const f05B1_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05B1->then_instructions;

                                    body.emit(assign(r05B0, r057A, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05B1->else_instructions;

                                    ir_expression *const r05B3 = nequal(r057A, body.constant(0u));
                                    ir_expression *const r05B4 = expr(ir_unop_b2i, r05B3);
                                    body.emit(assign(r05B0, expr(ir_unop_i2u, r05B4), 0x01));


                                 body.instructions = f05B1_parent_instructions;
                                 body.emit(f05B1);

                                 /* END IF */

                                 body.emit(assign(r05A0, r05B0, 0x01));

                                 body.emit(assign(r05A1, body.constant(0u), 0x01));


                              body.instructions = f05AD_parent_instructions;
                              body.emit(f05AD);

                              /* END IF */


                           body.instructions = f05AB_parent_instructions;
                           body.emit(f05AB);

                           /* END IF */

                           body.emit(assign(r05A2, body.constant(0u), 0x01));


                        body.instructions = f05A7_parent_instructions;
                        body.emit(f05A7);

                        /* END IF */

                        ir_expression *const r05B5 = nequal(r059E, body.constant(0u));
                        ir_expression *const r05B6 = expr(ir_unop_b2i, r05B5);
                        ir_expression *const r05B7 = expr(ir_unop_i2u, r05B6);
                        body.emit(assign(r05A0, bit_or(r05A0, r05B7), 0x01));


                     body.instructions = f05A5_parent_instructions;
                     body.emit(f05A5);

                     /* END IF */

                     body.emit(assign(r057A, r05A2, 0x01));

                     body.emit(assign(r057B, r05A1, 0x01));

                     body.emit(assign(r057C, r05A0, 0x01));


                  body.instructions = f0594_parent_instructions;
                  body.emit(f0594);

                  /* END IF */

                  body.emit(assign(r0579, sub(r0579, r057D), 0x01));

                  ir_variable *const r05B8 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r05B8, r0579, 0x01));

                  ir_variable *const r05B9 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r05B9, r057A, 0x01));

                  ir_variable *const r05BA = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r05BA, r057B, 0x01));

                  ir_variable *const r05BB = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r05BB, r057C, 0x01));

                  ir_variable *const r05BC = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r05BC, body.constant(true), 0x01));

                  ir_variable *const r05BD = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r05BE = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r05BE);
                  ir_expression *const r05BF = expr(ir_unop_u2i, r057C);
                  body.emit(assign(r05BE, less(r05BF, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r05C1 = lequal(body.constant(int(2045)), r0579);
                  ir_if *f05C0 = new(mem_ctx) ir_if(operand(r05C1).val);
                  exec_list *const f05C0_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05C0->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r05C3 = less(body.constant(int(2045)), r0579);
                     ir_expression *const r05C4 = equal(r0579, body.constant(int(2045)));
                     ir_expression *const r05C5 = equal(body.constant(2097151u), r057A);
                     ir_expression *const r05C6 = equal(body.constant(4294967295u), r057B);
                     ir_expression *const r05C7 = logic_and(r05C5, r05C6);
                     ir_expression *const r05C8 = logic_and(r05C4, r05C7);
                     ir_expression *const r05C9 = logic_and(r05C8, r05BE);
                     ir_expression *const r05CA = logic_or(r05C3, r05C9);
                     ir_if *f05C2 = new(mem_ctx) ir_if(operand(r05CA).val);
                     exec_list *const f05C2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05C2->then_instructions;

                        ir_variable *const r05CB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r05CB);
                        ir_expression *const r05CC = lshift(r0218, body.constant(int(31)));
                        body.emit(assign(r05CB, add(r05CC, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r05CB, body.constant(0u), 0x01));

                        body.emit(assign(r05BD, r05CB, 0x03));

                        body.emit(assign(r05BC, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05C2->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05CE = less(r0579, body.constant(int(0)));
                        ir_if *f05CD = new(mem_ctx) ir_if(operand(r05CE).val);
                        exec_list *const f05CD_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05CD->then_instructions;

                           ir_variable *const r05CF = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r05CF, r057C, 0x01));

                           ir_variable *const r05D0 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r05D0, neg(r0579), 0x01));

                           ir_variable *const r05D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r05D1);
                           ir_variable *const r05D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r05D2);
                           ir_variable *const r05D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r05D3);
                           ir_variable *const r05D4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r05D5 = neg(r05D0);
                           body.emit(assign(r05D4, bit_and(r05D5, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r05D7 = equal(r05D0, body.constant(int(0)));
                           ir_if *f05D6 = new(mem_ctx) ir_if(operand(r05D7).val);
                           exec_list *const f05D6_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05D6->then_instructions;

                              body.emit(assign(r05D1, r057C, 0x01));

                              body.emit(assign(r05D2, r057B, 0x01));

                              body.emit(assign(r05D3, r057A, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05D6->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05D9 = less(r05D0, body.constant(int(32)));
                              ir_if *f05D8 = new(mem_ctx) ir_if(operand(r05D9).val);
                              exec_list *const f05D8_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05D8->then_instructions;

                                 body.emit(assign(r05D1, lshift(r057B, r05D4), 0x01));

                                 ir_expression *const r05DA = lshift(r057A, r05D4);
                                 ir_expression *const r05DB = rshift(r057B, r05D0);
                                 body.emit(assign(r05D2, bit_or(r05DA, r05DB), 0x01));

                                 body.emit(assign(r05D3, rshift(r057A, r05D0), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05D8->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05DD = equal(r05D0, body.constant(int(32)));
                                 ir_if *f05DC = new(mem_ctx) ir_if(operand(r05DD).val);
                                 exec_list *const f05DC_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05DC->then_instructions;

                                    body.emit(assign(r05D1, r057B, 0x01));

                                    body.emit(assign(r05D2, r057A, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05DC->else_instructions;

                                    body.emit(assign(r05CF, bit_or(r057C, r057B), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r05DF = less(r05D0, body.constant(int(64)));
                                    ir_if *f05DE = new(mem_ctx) ir_if(operand(r05DF).val);
                                    exec_list *const f05DE_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f05DE->then_instructions;

                                       body.emit(assign(r05D1, lshift(r057A, r05D4), 0x01));

                                       ir_expression *const r05E0 = bit_and(r05D0, body.constant(int(31)));
                                       body.emit(assign(r05D2, rshift(r057A, r05E0), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f05DE->else_instructions;

                                       ir_variable *const r05E1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r05E3 = equal(r05D0, body.constant(int(64)));
                                       ir_if *f05E2 = new(mem_ctx) ir_if(operand(r05E3).val);
                                       exec_list *const f05E2_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f05E2->then_instructions;

                                          body.emit(assign(r05E1, r057A, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f05E2->else_instructions;

                                          ir_expression *const r05E4 = nequal(r057A, body.constant(0u));
                                          ir_expression *const r05E5 = expr(ir_unop_b2i, r05E4);
                                          body.emit(assign(r05E1, expr(ir_unop_i2u, r05E5), 0x01));


                                       body.instructions = f05E2_parent_instructions;
                                       body.emit(f05E2);

                                       /* END IF */

                                       body.emit(assign(r05D1, r05E1, 0x01));

                                       body.emit(assign(r05D2, body.constant(0u), 0x01));


                                    body.instructions = f05DE_parent_instructions;
                                    body.emit(f05DE);

                                    /* END IF */


                                 body.instructions = f05DC_parent_instructions;
                                 body.emit(f05DC);

                                 /* END IF */

                                 body.emit(assign(r05D3, body.constant(0u), 0x01));


                              body.instructions = f05D8_parent_instructions;
                              body.emit(f05D8);

                              /* END IF */

                              ir_expression *const r05E6 = nequal(r05CF, body.constant(0u));
                              ir_expression *const r05E7 = expr(ir_unop_b2i, r05E6);
                              ir_expression *const r05E8 = expr(ir_unop_i2u, r05E7);
                              body.emit(assign(r05D1, bit_or(r05D1, r05E8), 0x01));


                           body.instructions = f05D6_parent_instructions;
                           body.emit(f05D6);

                           /* END IF */

                           body.emit(assign(r05B9, r05D3, 0x01));

                           body.emit(assign(r05BA, r05D2, 0x01));

                           body.emit(assign(r05BB, r05D1, 0x01));

                           body.emit(assign(r05B8, body.constant(int(0)), 0x01));

                           body.emit(assign(r05BE, less(r05D1, body.constant(0u)), 0x01));


                        body.instructions = f05CD_parent_instructions;
                        body.emit(f05CD);

                        /* END IF */


                     body.instructions = f05C2_parent_instructions;
                     body.emit(f05C2);

                     /* END IF */


                  body.instructions = f05C0_parent_instructions;
                  body.emit(f05C0);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f05E9 = new(mem_ctx) ir_if(operand(r05BC).val);
                  exec_list *const f05E9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05E9->then_instructions;

                     /* IF CONDITION */
                     ir_if *f05EA = new(mem_ctx) ir_if(operand(r05BE).val);
                     exec_list *const f05EA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05EA->then_instructions;

                        ir_variable *const r05EB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r05EB, add(r05BA, body.constant(1u)), 0x01));

                        ir_expression *const r05EC = less(r05EB, r05BA);
                        ir_expression *const r05ED = expr(ir_unop_b2i, r05EC);
                        ir_expression *const r05EE = expr(ir_unop_i2u, r05ED);
                        body.emit(assign(r05B9, add(r05B9, r05EE), 0x01));

                        ir_expression *const r05EF = equal(r05BB, body.constant(0u));
                        ir_expression *const r05F0 = expr(ir_unop_b2i, r05EF);
                        ir_expression *const r05F1 = expr(ir_unop_i2u, r05F0);
                        ir_expression *const r05F2 = add(r05BB, r05F1);
                        ir_expression *const r05F3 = bit_and(r05F2, body.constant(1u));
                        ir_expression *const r05F4 = expr(ir_unop_bit_not, r05F3);
                        body.emit(assign(r05BA, bit_and(r05EB, r05F4), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05EA->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05F6 = bit_or(r05B9, r05BA);
                        ir_expression *const r05F7 = equal(r05F6, body.constant(0u));
                        ir_if *f05F5 = new(mem_ctx) ir_if(operand(r05F7).val);
                        exec_list *const f05F5_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05F5->then_instructions;

                           body.emit(assign(r05B8, body.constant(int(0)), 0x01));


                        body.instructions = f05F5_parent_instructions;
                        body.emit(f05F5);

                        /* END IF */


                     body.instructions = f05EA_parent_instructions;
                     body.emit(f05EA);

                     /* END IF */

                     ir_variable *const r05F8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r05F8);
                     ir_expression *const r05F9 = lshift(r0218, body.constant(int(31)));
                     ir_expression *const r05FA = expr(ir_unop_i2u, r05B8);
                     ir_expression *const r05FB = lshift(r05FA, body.constant(int(20)));
                     ir_expression *const r05FC = add(r05F9, r05FB);
                     body.emit(assign(r05F8, add(r05FC, r05B9), 0x02));

                     body.emit(assign(r05F8, r05BA, 0x01));

                     body.emit(assign(r05BD, r05F8, 0x03));

                     body.emit(assign(r05BC, body.constant(false), 0x01));


                  body.instructions = f05E9_parent_instructions;
                  body.emit(f05E9);

                  /* END IF */

                  body.emit(assign(r0217, r05BD, 0x03));

                  body.emit(assign(r0216, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0571->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05FE = less(r03AE, r03AC);
                  ir_if *f05FD = new(mem_ctx) ir_if(operand(r05FE).val);
                  exec_list *const f05FD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05FD->then_instructions;

                     ir_variable *const r05FF = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_variable *const r0600 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r0600, sub(r03AD, r03AF), 0x01));

                     ir_expression *const r0601 = sub(r03AC, r03AE);
                     ir_expression *const r0602 = less(r03AD, r03AF);
                     ir_expression *const r0603 = expr(ir_unop_b2i, r0602);
                     ir_expression *const r0604 = expr(ir_unop_i2u, r0603);
                     body.emit(assign(r05FF, sub(r0601, r0604), 0x01));

                     body.emit(assign(r0218, bit_xor(r0218, body.constant(1u)), 0x01));

                     body.emit(assign(r03B0, add(r03AA, body.constant(int(-1))), 0x01));

                     ir_variable *const r0605 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r0605, add(r03B0, body.constant(int(-10))), 0x01));

                     ir_variable *const r0606 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0606, r05FF, 0x01));

                     ir_variable *const r0607 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r0607, r0600, 0x01));

                     ir_variable *const r0608 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r0608);
                     ir_variable *const r0609 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0609);
                     /* IF CONDITION */
                     ir_expression *const r060B = equal(r05FF, body.constant(0u));
                     ir_if *f060A = new(mem_ctx) ir_if(operand(r060B).val);
                     exec_list *const f060A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f060A->then_instructions;

                        body.emit(assign(r0606, r0600, 0x01));

                        body.emit(assign(r0607, body.constant(0u), 0x01));

                        body.emit(assign(r0605, add(r0605, body.constant(int(-32))), 0x01));


                     body.instructions = f060A_parent_instructions;
                     body.emit(f060A);

                     /* END IF */

                     ir_variable *const r060C = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r060C, r0606, 0x01));

                     ir_variable *const r060D = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r060E = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r060E);
                     /* IF CONDITION */
                     ir_expression *const r0610 = equal(r0606, body.constant(0u));
                     ir_if *f060F = new(mem_ctx) ir_if(operand(r0610).val);
                     exec_list *const f060F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f060F->then_instructions;

                        body.emit(assign(r060D, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f060F->else_instructions;

                        body.emit(assign(r060E, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0612 = bit_and(r0606, body.constant(4294901760u));
                        ir_expression *const r0613 = equal(r0612, body.constant(0u));
                        ir_if *f0611 = new(mem_ctx) ir_if(operand(r0613).val);
                        exec_list *const f0611_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0611->then_instructions;

                           body.emit(assign(r060E, body.constant(int(16)), 0x01));

                           body.emit(assign(r060C, lshift(r0606, body.constant(int(16))), 0x01));


                        body.instructions = f0611_parent_instructions;
                        body.emit(f0611);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0615 = bit_and(r060C, body.constant(4278190080u));
                        ir_expression *const r0616 = equal(r0615, body.constant(0u));
                        ir_if *f0614 = new(mem_ctx) ir_if(operand(r0616).val);
                        exec_list *const f0614_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0614->then_instructions;

                           body.emit(assign(r060E, add(r060E, body.constant(int(8))), 0x01));

                           body.emit(assign(r060C, lshift(r060C, body.constant(int(8))), 0x01));


                        body.instructions = f0614_parent_instructions;
                        body.emit(f0614);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0618 = bit_and(r060C, body.constant(4026531840u));
                        ir_expression *const r0619 = equal(r0618, body.constant(0u));
                        ir_if *f0617 = new(mem_ctx) ir_if(operand(r0619).val);
                        exec_list *const f0617_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0617->then_instructions;

                           body.emit(assign(r060E, add(r060E, body.constant(int(4))), 0x01));

                           body.emit(assign(r060C, lshift(r060C, body.constant(int(4))), 0x01));


                        body.instructions = f0617_parent_instructions;
                        body.emit(f0617);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r061B = bit_and(r060C, body.constant(3221225472u));
                        ir_expression *const r061C = equal(r061B, body.constant(0u));
                        ir_if *f061A = new(mem_ctx) ir_if(operand(r061C).val);
                        exec_list *const f061A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f061A->then_instructions;

                           body.emit(assign(r060E, add(r060E, body.constant(int(2))), 0x01));

                           body.emit(assign(r060C, lshift(r060C, body.constant(int(2))), 0x01));


                        body.instructions = f061A_parent_instructions;
                        body.emit(f061A);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r061E = bit_and(r060C, body.constant(2147483648u));
                        ir_expression *const r061F = equal(r061E, body.constant(0u));
                        ir_if *f061D = new(mem_ctx) ir_if(operand(r061F).val);
                        exec_list *const f061D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f061D->then_instructions;

                           body.emit(assign(r060E, add(r060E, body.constant(int(1))), 0x01));


                        body.instructions = f061D_parent_instructions;
                        body.emit(f061D);

                        /* END IF */

                        body.emit(assign(r060D, r060E, 0x01));


                     body.instructions = f060F_parent_instructions;
                     body.emit(f060F);

                     /* END IF */

                     body.emit(assign(r0609, add(r060D, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0621 = lequal(body.constant(int(0)), r0609);
                     ir_if *f0620 = new(mem_ctx) ir_if(operand(r0621).val);
                     exec_list *const f0620_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0620->then_instructions;

                        body.emit(assign(r0608, body.constant(0u), 0x01));

                        ir_variable *const r0622 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r0622, lshift(r0607, r0609), 0x01));

                        ir_variable *const r0623 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r0625 = equal(r0609, body.constant(int(0)));
                        ir_if *f0624 = new(mem_ctx) ir_if(operand(r0625).val);
                        exec_list *const f0624_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0624->then_instructions;

                           body.emit(assign(r0623, r0606, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0624->else_instructions;

                           ir_expression *const r0626 = lshift(r0606, r0609);
                           ir_expression *const r0627 = neg(r0609);
                           ir_expression *const r0628 = bit_and(r0627, body.constant(int(31)));
                           ir_expression *const r0629 = rshift(r0607, r0628);
                           body.emit(assign(r0623, bit_or(r0626, r0629), 0x01));


                        body.instructions = f0624_parent_instructions;
                        body.emit(f0624);

                        /* END IF */

                        body.emit(assign(r0606, r0623, 0x01));

                        body.emit(assign(r0607, r0622, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0620->else_instructions;

                        ir_variable *const r062A = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r062A, body.constant(0u), 0x01));

                        ir_variable *const r062B = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r062B, neg(r0609), 0x01));

                        ir_variable *const r062C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r062C);
                        ir_variable *const r062D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r062D);
                        ir_variable *const r062E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r062E);
                        ir_variable *const r062F = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0630 = neg(r062B);
                        body.emit(assign(r062F, bit_and(r0630, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0632 = equal(r062B, body.constant(int(0)));
                        ir_if *f0631 = new(mem_ctx) ir_if(operand(r0632).val);
                        exec_list *const f0631_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0631->then_instructions;

                           body.emit(assign(r062C, r062A, 0x01));

                           body.emit(assign(r062D, r0607, 0x01));

                           body.emit(assign(r062E, r0606, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0631->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0634 = less(r062B, body.constant(int(32)));
                           ir_if *f0633 = new(mem_ctx) ir_if(operand(r0634).val);
                           exec_list *const f0633_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0633->then_instructions;

                              body.emit(assign(r062C, lshift(r0607, r062F), 0x01));

                              ir_expression *const r0635 = lshift(r0606, r062F);
                              ir_expression *const r0636 = rshift(r0607, r062B);
                              body.emit(assign(r062D, bit_or(r0635, r0636), 0x01));

                              body.emit(assign(r062E, rshift(r0606, r062B), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0633->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0638 = equal(r062B, body.constant(int(32)));
                              ir_if *f0637 = new(mem_ctx) ir_if(operand(r0638).val);
                              exec_list *const f0637_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0637->then_instructions;

                                 body.emit(assign(r062C, r0607, 0x01));

                                 body.emit(assign(r062D, r0606, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0637->else_instructions;

                                 body.emit(assign(r062A, bit_or(body.constant(0u), r0607), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r063A = less(r062B, body.constant(int(64)));
                                 ir_if *f0639 = new(mem_ctx) ir_if(operand(r063A).val);
                                 exec_list *const f0639_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0639->then_instructions;

                                    body.emit(assign(r062C, lshift(r0606, r062F), 0x01));

                                    ir_expression *const r063B = bit_and(r062B, body.constant(int(31)));
                                    body.emit(assign(r062D, rshift(r0606, r063B), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0639->else_instructions;

                                    ir_variable *const r063C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r063E = equal(r062B, body.constant(int(64)));
                                    ir_if *f063D = new(mem_ctx) ir_if(operand(r063E).val);
                                    exec_list *const f063D_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f063D->then_instructions;

                                       body.emit(assign(r063C, r0606, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f063D->else_instructions;

                                       ir_expression *const r063F = nequal(r0606, body.constant(0u));
                                       ir_expression *const r0640 = expr(ir_unop_b2i, r063F);
                                       body.emit(assign(r063C, expr(ir_unop_i2u, r0640), 0x01));


                                    body.instructions = f063D_parent_instructions;
                                    body.emit(f063D);

                                    /* END IF */

                                    body.emit(assign(r062C, r063C, 0x01));

                                    body.emit(assign(r062D, body.constant(0u), 0x01));


                                 body.instructions = f0639_parent_instructions;
                                 body.emit(f0639);

                                 /* END IF */


                              body.instructions = f0637_parent_instructions;
                              body.emit(f0637);

                              /* END IF */

                              body.emit(assign(r062E, body.constant(0u), 0x01));


                           body.instructions = f0633_parent_instructions;
                           body.emit(f0633);

                           /* END IF */

                           ir_expression *const r0641 = nequal(r062A, body.constant(0u));
                           ir_expression *const r0642 = expr(ir_unop_b2i, r0641);
                           ir_expression *const r0643 = expr(ir_unop_i2u, r0642);
                           body.emit(assign(r062C, bit_or(r062C, r0643), 0x01));


                        body.instructions = f0631_parent_instructions;
                        body.emit(f0631);

                        /* END IF */

                        body.emit(assign(r0606, r062E, 0x01));

                        body.emit(assign(r0607, r062D, 0x01));

                        body.emit(assign(r0608, r062C, 0x01));


                     body.instructions = f0620_parent_instructions;
                     body.emit(f0620);

                     /* END IF */

                     body.emit(assign(r0605, sub(r0605, r0609), 0x01));

                     ir_variable *const r0644 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r0644, r0605, 0x01));

                     ir_variable *const r0645 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0645, r0606, 0x01));

                     ir_variable *const r0646 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r0646, r0607, 0x01));

                     ir_variable *const r0647 = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r0647, r0608, 0x01));

                     ir_variable *const r0648 = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r0648, body.constant(true), 0x01));

                     ir_variable *const r0649 = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r064A = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r064A);
                     ir_expression *const r064B = expr(ir_unop_u2i, r0608);
                     body.emit(assign(r064A, less(r064B, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r064D = lequal(body.constant(int(2045)), r0605);
                     ir_if *f064C = new(mem_ctx) ir_if(operand(r064D).val);
                     exec_list *const f064C_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f064C->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r064F = less(body.constant(int(2045)), r0605);
                        ir_expression *const r0650 = equal(r0605, body.constant(int(2045)));
                        ir_expression *const r0651 = equal(body.constant(2097151u), r0606);
                        ir_expression *const r0652 = equal(body.constant(4294967295u), r0607);
                        ir_expression *const r0653 = logic_and(r0651, r0652);
                        ir_expression *const r0654 = logic_and(r0650, r0653);
                        ir_expression *const r0655 = logic_and(r0654, r064A);
                        ir_expression *const r0656 = logic_or(r064F, r0655);
                        ir_if *f064E = new(mem_ctx) ir_if(operand(r0656).val);
                        exec_list *const f064E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f064E->then_instructions;

                           ir_variable *const r0657 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0657);
                           ir_expression *const r0658 = lshift(r0218, body.constant(int(31)));
                           body.emit(assign(r0657, add(r0658, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r0657, body.constant(0u), 0x01));

                           body.emit(assign(r0649, r0657, 0x03));

                           body.emit(assign(r0648, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f064E->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r065A = less(r0605, body.constant(int(0)));
                           ir_if *f0659 = new(mem_ctx) ir_if(operand(r065A).val);
                           exec_list *const f0659_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0659->then_instructions;

                              ir_variable *const r065B = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r065B, r0608, 0x01));

                              ir_variable *const r065C = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r065C, neg(r0605), 0x01));

                              ir_variable *const r065D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r065D);
                              ir_variable *const r065E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r065E);
                              ir_variable *const r065F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r065F);
                              ir_variable *const r0660 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0661 = neg(r065C);
                              body.emit(assign(r0660, bit_and(r0661, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0663 = equal(r065C, body.constant(int(0)));
                              ir_if *f0662 = new(mem_ctx) ir_if(operand(r0663).val);
                              exec_list *const f0662_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0662->then_instructions;

                                 body.emit(assign(r065D, r0608, 0x01));

                                 body.emit(assign(r065E, r0607, 0x01));

                                 body.emit(assign(r065F, r0606, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0662->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0665 = less(r065C, body.constant(int(32)));
                                 ir_if *f0664 = new(mem_ctx) ir_if(operand(r0665).val);
                                 exec_list *const f0664_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0664->then_instructions;

                                    body.emit(assign(r065D, lshift(r0607, r0660), 0x01));

                                    ir_expression *const r0666 = lshift(r0606, r0660);
                                    ir_expression *const r0667 = rshift(r0607, r065C);
                                    body.emit(assign(r065E, bit_or(r0666, r0667), 0x01));

                                    body.emit(assign(r065F, rshift(r0606, r065C), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0664->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0669 = equal(r065C, body.constant(int(32)));
                                    ir_if *f0668 = new(mem_ctx) ir_if(operand(r0669).val);
                                    exec_list *const f0668_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0668->then_instructions;

                                       body.emit(assign(r065D, r0607, 0x01));

                                       body.emit(assign(r065E, r0606, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0668->else_instructions;

                                       body.emit(assign(r065B, bit_or(r0608, r0607), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r066B = less(r065C, body.constant(int(64)));
                                       ir_if *f066A = new(mem_ctx) ir_if(operand(r066B).val);
                                       exec_list *const f066A_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f066A->then_instructions;

                                          body.emit(assign(r065D, lshift(r0606, r0660), 0x01));

                                          ir_expression *const r066C = bit_and(r065C, body.constant(int(31)));
                                          body.emit(assign(r065E, rshift(r0606, r066C), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f066A->else_instructions;

                                          ir_variable *const r066D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r066F = equal(r065C, body.constant(int(64)));
                                          ir_if *f066E = new(mem_ctx) ir_if(operand(r066F).val);
                                          exec_list *const f066E_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f066E->then_instructions;

                                             body.emit(assign(r066D, r0606, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f066E->else_instructions;

                                             ir_expression *const r0670 = nequal(r0606, body.constant(0u));
                                             ir_expression *const r0671 = expr(ir_unop_b2i, r0670);
                                             body.emit(assign(r066D, expr(ir_unop_i2u, r0671), 0x01));


                                          body.instructions = f066E_parent_instructions;
                                          body.emit(f066E);

                                          /* END IF */

                                          body.emit(assign(r065D, r066D, 0x01));

                                          body.emit(assign(r065E, body.constant(0u), 0x01));


                                       body.instructions = f066A_parent_instructions;
                                       body.emit(f066A);

                                       /* END IF */


                                    body.instructions = f0668_parent_instructions;
                                    body.emit(f0668);

                                    /* END IF */

                                    body.emit(assign(r065F, body.constant(0u), 0x01));


                                 body.instructions = f0664_parent_instructions;
                                 body.emit(f0664);

                                 /* END IF */

                                 ir_expression *const r0672 = nequal(r065B, body.constant(0u));
                                 ir_expression *const r0673 = expr(ir_unop_b2i, r0672);
                                 ir_expression *const r0674 = expr(ir_unop_i2u, r0673);
                                 body.emit(assign(r065D, bit_or(r065D, r0674), 0x01));


                              body.instructions = f0662_parent_instructions;
                              body.emit(f0662);

                              /* END IF */

                              body.emit(assign(r0645, r065F, 0x01));

                              body.emit(assign(r0646, r065E, 0x01));

                              body.emit(assign(r0647, r065D, 0x01));

                              body.emit(assign(r0644, body.constant(int(0)), 0x01));

                              body.emit(assign(r064A, less(r065D, body.constant(0u)), 0x01));


                           body.instructions = f0659_parent_instructions;
                           body.emit(f0659);

                           /* END IF */


                        body.instructions = f064E_parent_instructions;
                        body.emit(f064E);

                        /* END IF */


                     body.instructions = f064C_parent_instructions;
                     body.emit(f064C);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0675 = new(mem_ctx) ir_if(operand(r0648).val);
                     exec_list *const f0675_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0675->then_instructions;

                        /* IF CONDITION */
                        ir_if *f0676 = new(mem_ctx) ir_if(operand(r064A).val);
                        exec_list *const f0676_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0676->then_instructions;

                           ir_variable *const r0677 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r0677, add(r0646, body.constant(1u)), 0x01));

                           ir_expression *const r0678 = less(r0677, r0646);
                           ir_expression *const r0679 = expr(ir_unop_b2i, r0678);
                           ir_expression *const r067A = expr(ir_unop_i2u, r0679);
                           body.emit(assign(r0645, add(r0645, r067A), 0x01));

                           ir_expression *const r067B = equal(r0647, body.constant(0u));
                           ir_expression *const r067C = expr(ir_unop_b2i, r067B);
                           ir_expression *const r067D = expr(ir_unop_i2u, r067C);
                           ir_expression *const r067E = add(r0647, r067D);
                           ir_expression *const r067F = bit_and(r067E, body.constant(1u));
                           ir_expression *const r0680 = expr(ir_unop_bit_not, r067F);
                           body.emit(assign(r0646, bit_and(r0677, r0680), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0676->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0682 = bit_or(r0645, r0646);
                           ir_expression *const r0683 = equal(r0682, body.constant(0u));
                           ir_if *f0681 = new(mem_ctx) ir_if(operand(r0683).val);
                           exec_list *const f0681_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0681->then_instructions;

                              body.emit(assign(r0644, body.constant(int(0)), 0x01));


                           body.instructions = f0681_parent_instructions;
                           body.emit(f0681);

                           /* END IF */


                        body.instructions = f0676_parent_instructions;
                        body.emit(f0676);

                        /* END IF */

                        ir_variable *const r0684 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0684);
                        ir_expression *const r0685 = lshift(r0218, body.constant(int(31)));
                        ir_expression *const r0686 = expr(ir_unop_i2u, r0644);
                        ir_expression *const r0687 = lshift(r0686, body.constant(int(20)));
                        ir_expression *const r0688 = add(r0685, r0687);
                        body.emit(assign(r0684, add(r0688, r0645), 0x02));

                        body.emit(assign(r0684, r0646, 0x01));

                        body.emit(assign(r0649, r0684, 0x03));

                        body.emit(assign(r0648, body.constant(false), 0x01));


                     body.instructions = f0675_parent_instructions;
                     body.emit(f0675);

                     /* END IF */

                     body.emit(assign(r0217, r0649, 0x03));

                     body.emit(assign(r0216, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05FD->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r068A = less(r03AD, r03AF);
                     ir_if *f0689 = new(mem_ctx) ir_if(operand(r068A).val);
                     exec_list *const f0689_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0689->then_instructions;

                        ir_variable *const r068B = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_variable *const r068C = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r068C, sub(r03AF, r03AD), 0x01));

                        ir_expression *const r068D = sub(r03AE, r03AC);
                        ir_expression *const r068E = less(r03AF, r03AD);
                        ir_expression *const r068F = expr(ir_unop_b2i, r068E);
                        ir_expression *const r0690 = expr(ir_unop_i2u, r068F);
                        body.emit(assign(r068B, sub(r068D, r0690), 0x01));

                        body.emit(assign(r03B0, add(r03AB, body.constant(int(-1))), 0x01));

                        ir_variable *const r0691 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r0691, add(r03B0, body.constant(int(-10))), 0x01));

                        ir_variable *const r0692 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r0692, r068B, 0x01));

                        ir_variable *const r0693 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0693, r068C, 0x01));

                        ir_variable *const r0694 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0694);
                        ir_variable *const r0695 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0695);
                        /* IF CONDITION */
                        ir_expression *const r0697 = equal(r068B, body.constant(0u));
                        ir_if *f0696 = new(mem_ctx) ir_if(operand(r0697).val);
                        exec_list *const f0696_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0696->then_instructions;

                           body.emit(assign(r0692, r068C, 0x01));

                           body.emit(assign(r0693, body.constant(0u), 0x01));

                           body.emit(assign(r0691, add(r0691, body.constant(int(-32))), 0x01));


                        body.instructions = f0696_parent_instructions;
                        body.emit(f0696);

                        /* END IF */

                        ir_variable *const r0698 = body.make_temp(glsl_type::uint_type, "a");
                        body.emit(assign(r0698, r0692, 0x01));

                        ir_variable *const r0699 = body.make_temp(glsl_type::int_type, "return_value");
                        ir_variable *const r069A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r069A);
                        /* IF CONDITION */
                        ir_expression *const r069C = equal(r0692, body.constant(0u));
                        ir_if *f069B = new(mem_ctx) ir_if(operand(r069C).val);
                        exec_list *const f069B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f069B->then_instructions;

                           body.emit(assign(r0699, body.constant(int(32)), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f069B->else_instructions;

                           body.emit(assign(r069A, body.constant(int(0)), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r069E = bit_and(r0692, body.constant(4294901760u));
                           ir_expression *const r069F = equal(r069E, body.constant(0u));
                           ir_if *f069D = new(mem_ctx) ir_if(operand(r069F).val);
                           exec_list *const f069D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f069D->then_instructions;

                              body.emit(assign(r069A, body.constant(int(16)), 0x01));

                              body.emit(assign(r0698, lshift(r0692, body.constant(int(16))), 0x01));


                           body.instructions = f069D_parent_instructions;
                           body.emit(f069D);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r06A1 = bit_and(r0698, body.constant(4278190080u));
                           ir_expression *const r06A2 = equal(r06A1, body.constant(0u));
                           ir_if *f06A0 = new(mem_ctx) ir_if(operand(r06A2).val);
                           exec_list *const f06A0_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06A0->then_instructions;

                              body.emit(assign(r069A, add(r069A, body.constant(int(8))), 0x01));

                              body.emit(assign(r0698, lshift(r0698, body.constant(int(8))), 0x01));


                           body.instructions = f06A0_parent_instructions;
                           body.emit(f06A0);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r06A4 = bit_and(r0698, body.constant(4026531840u));
                           ir_expression *const r06A5 = equal(r06A4, body.constant(0u));
                           ir_if *f06A3 = new(mem_ctx) ir_if(operand(r06A5).val);
                           exec_list *const f06A3_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06A3->then_instructions;

                              body.emit(assign(r069A, add(r069A, body.constant(int(4))), 0x01));

                              body.emit(assign(r0698, lshift(r0698, body.constant(int(4))), 0x01));


                           body.instructions = f06A3_parent_instructions;
                           body.emit(f06A3);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r06A7 = bit_and(r0698, body.constant(3221225472u));
                           ir_expression *const r06A8 = equal(r06A7, body.constant(0u));
                           ir_if *f06A6 = new(mem_ctx) ir_if(operand(r06A8).val);
                           exec_list *const f06A6_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06A6->then_instructions;

                              body.emit(assign(r069A, add(r069A, body.constant(int(2))), 0x01));

                              body.emit(assign(r0698, lshift(r0698, body.constant(int(2))), 0x01));


                           body.instructions = f06A6_parent_instructions;
                           body.emit(f06A6);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r06AA = bit_and(r0698, body.constant(2147483648u));
                           ir_expression *const r06AB = equal(r06AA, body.constant(0u));
                           ir_if *f06A9 = new(mem_ctx) ir_if(operand(r06AB).val);
                           exec_list *const f06A9_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06A9->then_instructions;

                              body.emit(assign(r069A, add(r069A, body.constant(int(1))), 0x01));


                           body.instructions = f06A9_parent_instructions;
                           body.emit(f06A9);

                           /* END IF */

                           body.emit(assign(r0699, r069A, 0x01));


                        body.instructions = f069B_parent_instructions;
                        body.emit(f069B);

                        /* END IF */

                        body.emit(assign(r0695, add(r0699, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r06AD = lequal(body.constant(int(0)), r0695);
                        ir_if *f06AC = new(mem_ctx) ir_if(operand(r06AD).val);
                        exec_list *const f06AC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06AC->then_instructions;

                           body.emit(assign(r0694, body.constant(0u), 0x01));

                           ir_variable *const r06AE = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r06AE, lshift(r0693, r0695), 0x01));

                           ir_variable *const r06AF = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r06B1 = equal(r0695, body.constant(int(0)));
                           ir_if *f06B0 = new(mem_ctx) ir_if(operand(r06B1).val);
                           exec_list *const f06B0_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06B0->then_instructions;

                              body.emit(assign(r06AF, r0692, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06B0->else_instructions;

                              ir_expression *const r06B2 = lshift(r0692, r0695);
                              ir_expression *const r06B3 = neg(r0695);
                              ir_expression *const r06B4 = bit_and(r06B3, body.constant(int(31)));
                              ir_expression *const r06B5 = rshift(r0693, r06B4);
                              body.emit(assign(r06AF, bit_or(r06B2, r06B5), 0x01));


                           body.instructions = f06B0_parent_instructions;
                           body.emit(f06B0);

                           /* END IF */

                           body.emit(assign(r0692, r06AF, 0x01));

                           body.emit(assign(r0693, r06AE, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06AC->else_instructions;

                           ir_variable *const r06B6 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r06B6, body.constant(0u), 0x01));

                           ir_variable *const r06B7 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r06B7, neg(r0695), 0x01));

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

                              body.emit(assign(r06B9, r0693, 0x01));

                              body.emit(assign(r06BA, r0692, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06BD->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06C0 = less(r06B7, body.constant(int(32)));
                              ir_if *f06BF = new(mem_ctx) ir_if(operand(r06C0).val);
                              exec_list *const f06BF_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06BF->then_instructions;

                                 body.emit(assign(r06B8, lshift(r0693, r06BB), 0x01));

                                 ir_expression *const r06C1 = lshift(r0692, r06BB);
                                 ir_expression *const r06C2 = rshift(r0693, r06B7);
                                 body.emit(assign(r06B9, bit_or(r06C1, r06C2), 0x01));

                                 body.emit(assign(r06BA, rshift(r0692, r06B7), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f06BF->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r06C4 = equal(r06B7, body.constant(int(32)));
                                 ir_if *f06C3 = new(mem_ctx) ir_if(operand(r06C4).val);
                                 exec_list *const f06C3_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06C3->then_instructions;

                                    body.emit(assign(r06B8, r0693, 0x01));

                                    body.emit(assign(r06B9, r0692, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06C3->else_instructions;

                                    body.emit(assign(r06B6, bit_or(body.constant(0u), r0693), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r06C6 = less(r06B7, body.constant(int(64)));
                                    ir_if *f06C5 = new(mem_ctx) ir_if(operand(r06C6).val);
                                    exec_list *const f06C5_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06C5->then_instructions;

                                       body.emit(assign(r06B8, lshift(r0692, r06BB), 0x01));

                                       ir_expression *const r06C7 = bit_and(r06B7, body.constant(int(31)));
                                       body.emit(assign(r06B9, rshift(r0692, r06C7), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06C5->else_instructions;

                                       ir_variable *const r06C8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r06CA = equal(r06B7, body.constant(int(64)));
                                       ir_if *f06C9 = new(mem_ctx) ir_if(operand(r06CA).val);
                                       exec_list *const f06C9_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06C9->then_instructions;

                                          body.emit(assign(r06C8, r0692, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06C9->else_instructions;

                                          ir_expression *const r06CB = nequal(r0692, body.constant(0u));
                                          ir_expression *const r06CC = expr(ir_unop_b2i, r06CB);
                                          body.emit(assign(r06C8, expr(ir_unop_i2u, r06CC), 0x01));


                                       body.instructions = f06C9_parent_instructions;
                                       body.emit(f06C9);

                                       /* END IF */

                                       body.emit(assign(r06B8, r06C8, 0x01));

                                       body.emit(assign(r06B9, body.constant(0u), 0x01));


                                    body.instructions = f06C5_parent_instructions;
                                    body.emit(f06C5);

                                    /* END IF */


                                 body.instructions = f06C3_parent_instructions;
                                 body.emit(f06C3);

                                 /* END IF */

                                 body.emit(assign(r06BA, body.constant(0u), 0x01));


                              body.instructions = f06BF_parent_instructions;
                              body.emit(f06BF);

                              /* END IF */

                              ir_expression *const r06CD = nequal(r06B6, body.constant(0u));
                              ir_expression *const r06CE = expr(ir_unop_b2i, r06CD);
                              ir_expression *const r06CF = expr(ir_unop_i2u, r06CE);
                              body.emit(assign(r06B8, bit_or(r06B8, r06CF), 0x01));


                           body.instructions = f06BD_parent_instructions;
                           body.emit(f06BD);

                           /* END IF */

                           body.emit(assign(r0692, r06BA, 0x01));

                           body.emit(assign(r0693, r06B9, 0x01));

                           body.emit(assign(r0694, r06B8, 0x01));


                        body.instructions = f06AC_parent_instructions;
                        body.emit(f06AC);

                        /* END IF */

                        body.emit(assign(r0691, sub(r0691, r0695), 0x01));

                        ir_variable *const r06D0 = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r06D0, r0691, 0x01));

                        ir_variable *const r06D1 = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r06D1, r0692, 0x01));

                        ir_variable *const r06D2 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r06D2, r0693, 0x01));

                        ir_variable *const r06D3 = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r06D3, r0694, 0x01));

                        ir_variable *const r06D4 = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r06D4, body.constant(true), 0x01));

                        ir_variable *const r06D5 = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r06D6 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r06D6);
                        ir_expression *const r06D7 = expr(ir_unop_u2i, r0694);
                        body.emit(assign(r06D6, less(r06D7, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r06D9 = lequal(body.constant(int(2045)), r0691);
                        ir_if *f06D8 = new(mem_ctx) ir_if(operand(r06D9).val);
                        exec_list *const f06D8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06D8->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r06DB = less(body.constant(int(2045)), r0691);
                           ir_expression *const r06DC = equal(r0691, body.constant(int(2045)));
                           ir_expression *const r06DD = equal(body.constant(2097151u), r0692);
                           ir_expression *const r06DE = equal(body.constant(4294967295u), r0693);
                           ir_expression *const r06DF = logic_and(r06DD, r06DE);
                           ir_expression *const r06E0 = logic_and(r06DC, r06DF);
                           ir_expression *const r06E1 = logic_and(r06E0, r06D6);
                           ir_expression *const r06E2 = logic_or(r06DB, r06E1);
                           ir_if *f06DA = new(mem_ctx) ir_if(operand(r06E2).val);
                           exec_list *const f06DA_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06DA->then_instructions;

                              ir_variable *const r06E3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r06E3);
                              ir_expression *const r06E4 = lshift(r0218, body.constant(int(31)));
                              body.emit(assign(r06E3, add(r06E4, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r06E3, body.constant(0u), 0x01));

                              body.emit(assign(r06D5, r06E3, 0x03));

                              body.emit(assign(r06D4, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06DA->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06E6 = less(r0691, body.constant(int(0)));
                              ir_if *f06E5 = new(mem_ctx) ir_if(operand(r06E6).val);
                              exec_list *const f06E5_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06E5->then_instructions;

                                 ir_variable *const r06E7 = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r06E7, r0694, 0x01));

                                 ir_variable *const r06E8 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r06E8, neg(r0691), 0x01));

                                 ir_variable *const r06E9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r06E9);
                                 ir_variable *const r06EA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r06EA);
                                 ir_variable *const r06EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r06EB);
                                 ir_variable *const r06EC = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r06ED = neg(r06E8);
                                 body.emit(assign(r06EC, bit_and(r06ED, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r06EF = equal(r06E8, body.constant(int(0)));
                                 ir_if *f06EE = new(mem_ctx) ir_if(operand(r06EF).val);
                                 exec_list *const f06EE_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06EE->then_instructions;

                                    body.emit(assign(r06E9, r0694, 0x01));

                                    body.emit(assign(r06EA, r0693, 0x01));

                                    body.emit(assign(r06EB, r0692, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06EE->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06F1 = less(r06E8, body.constant(int(32)));
                                    ir_if *f06F0 = new(mem_ctx) ir_if(operand(r06F1).val);
                                    exec_list *const f06F0_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06F0->then_instructions;

                                       body.emit(assign(r06E9, lshift(r0693, r06EC), 0x01));

                                       ir_expression *const r06F2 = lshift(r0692, r06EC);
                                       ir_expression *const r06F3 = rshift(r0693, r06E8);
                                       body.emit(assign(r06EA, bit_or(r06F2, r06F3), 0x01));

                                       body.emit(assign(r06EB, rshift(r0692, r06E8), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06F0->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r06F5 = equal(r06E8, body.constant(int(32)));
                                       ir_if *f06F4 = new(mem_ctx) ir_if(operand(r06F5).val);
                                       exec_list *const f06F4_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06F4->then_instructions;

                                          body.emit(assign(r06E9, r0693, 0x01));

                                          body.emit(assign(r06EA, r0692, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06F4->else_instructions;

                                          body.emit(assign(r06E7, bit_or(r0694, r0693), 0x01));

                                          /* IF CONDITION */
                                          ir_expression *const r06F7 = less(r06E8, body.constant(int(64)));
                                          ir_if *f06F6 = new(mem_ctx) ir_if(operand(r06F7).val);
                                          exec_list *const f06F6_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f06F6->then_instructions;

                                             body.emit(assign(r06E9, lshift(r0692, r06EC), 0x01));

                                             ir_expression *const r06F8 = bit_and(r06E8, body.constant(int(31)));
                                             body.emit(assign(r06EA, rshift(r0692, r06F8), 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f06F6->else_instructions;

                                             ir_variable *const r06F9 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                             /* IF CONDITION */
                                             ir_expression *const r06FB = equal(r06E8, body.constant(int(64)));
                                             ir_if *f06FA = new(mem_ctx) ir_if(operand(r06FB).val);
                                             exec_list *const f06FA_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f06FA->then_instructions;

                                                body.emit(assign(r06F9, r0692, 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f06FA->else_instructions;

                                                ir_expression *const r06FC = nequal(r0692, body.constant(0u));
                                                ir_expression *const r06FD = expr(ir_unop_b2i, r06FC);
                                                body.emit(assign(r06F9, expr(ir_unop_i2u, r06FD), 0x01));


                                             body.instructions = f06FA_parent_instructions;
                                             body.emit(f06FA);

                                             /* END IF */

                                             body.emit(assign(r06E9, r06F9, 0x01));

                                             body.emit(assign(r06EA, body.constant(0u), 0x01));


                                          body.instructions = f06F6_parent_instructions;
                                          body.emit(f06F6);

                                          /* END IF */


                                       body.instructions = f06F4_parent_instructions;
                                       body.emit(f06F4);

                                       /* END IF */

                                       body.emit(assign(r06EB, body.constant(0u), 0x01));


                                    body.instructions = f06F0_parent_instructions;
                                    body.emit(f06F0);

                                    /* END IF */

                                    ir_expression *const r06FE = nequal(r06E7, body.constant(0u));
                                    ir_expression *const r06FF = expr(ir_unop_b2i, r06FE);
                                    ir_expression *const r0700 = expr(ir_unop_i2u, r06FF);
                                    body.emit(assign(r06E9, bit_or(r06E9, r0700), 0x01));


                                 body.instructions = f06EE_parent_instructions;
                                 body.emit(f06EE);

                                 /* END IF */

                                 body.emit(assign(r06D1, r06EB, 0x01));

                                 body.emit(assign(r06D2, r06EA, 0x01));

                                 body.emit(assign(r06D3, r06E9, 0x01));

                                 body.emit(assign(r06D0, body.constant(int(0)), 0x01));

                                 body.emit(assign(r06D6, less(r06E9, body.constant(0u)), 0x01));


                              body.instructions = f06E5_parent_instructions;
                              body.emit(f06E5);

                              /* END IF */


                           body.instructions = f06DA_parent_instructions;
                           body.emit(f06DA);

                           /* END IF */


                        body.instructions = f06D8_parent_instructions;
                        body.emit(f06D8);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f0701 = new(mem_ctx) ir_if(operand(r06D4).val);
                        exec_list *const f0701_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0701->then_instructions;

                           /* IF CONDITION */
                           ir_if *f0702 = new(mem_ctx) ir_if(operand(r06D6).val);
                           exec_list *const f0702_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0702->then_instructions;

                              ir_variable *const r0703 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r0703, add(r06D2, body.constant(1u)), 0x01));

                              ir_expression *const r0704 = less(r0703, r06D2);
                              ir_expression *const r0705 = expr(ir_unop_b2i, r0704);
                              ir_expression *const r0706 = expr(ir_unop_i2u, r0705);
                              body.emit(assign(r06D1, add(r06D1, r0706), 0x01));

                              ir_expression *const r0707 = equal(r06D3, body.constant(0u));
                              ir_expression *const r0708 = expr(ir_unop_b2i, r0707);
                              ir_expression *const r0709 = expr(ir_unop_i2u, r0708);
                              ir_expression *const r070A = add(r06D3, r0709);
                              ir_expression *const r070B = bit_and(r070A, body.constant(1u));
                              ir_expression *const r070C = expr(ir_unop_bit_not, r070B);
                              body.emit(assign(r06D2, bit_and(r0703, r070C), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0702->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r070E = bit_or(r06D1, r06D2);
                              ir_expression *const r070F = equal(r070E, body.constant(0u));
                              ir_if *f070D = new(mem_ctx) ir_if(operand(r070F).val);
                              exec_list *const f070D_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f070D->then_instructions;

                                 body.emit(assign(r06D0, body.constant(int(0)), 0x01));


                              body.instructions = f070D_parent_instructions;
                              body.emit(f070D);

                              /* END IF */


                           body.instructions = f0702_parent_instructions;
                           body.emit(f0702);

                           /* END IF */

                           ir_variable *const r0710 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0710);
                           ir_expression *const r0711 = lshift(r0218, body.constant(int(31)));
                           ir_expression *const r0712 = expr(ir_unop_i2u, r06D0);
                           ir_expression *const r0713 = lshift(r0712, body.constant(int(20)));
                           ir_expression *const r0714 = add(r0711, r0713);
                           body.emit(assign(r0710, add(r0714, r06D1), 0x02));

                           body.emit(assign(r0710, r06D2, 0x01));

                           body.emit(assign(r06D5, r0710, 0x03));

                           body.emit(assign(r06D4, body.constant(false), 0x01));


                        body.instructions = f0701_parent_instructions;
                        body.emit(f0701);

                        /* END IF */

                        body.emit(assign(r0217, r06D5, 0x03));

                        body.emit(assign(r0216, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0689->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0716 = less(r03AF, r03AD);
                        ir_if *f0715 = new(mem_ctx) ir_if(operand(r0716).val);
                        exec_list *const f0715_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0715->then_instructions;

                           ir_variable *const r0717 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_variable *const r0718 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r0718, sub(r03AD, r03AF), 0x01));

                           ir_expression *const r0719 = sub(r03AC, r03AE);
                           ir_expression *const r071A = less(r03AD, r03AF);
                           ir_expression *const r071B = expr(ir_unop_b2i, r071A);
                           ir_expression *const r071C = expr(ir_unop_i2u, r071B);
                           body.emit(assign(r0717, sub(r0719, r071C), 0x01));

                           body.emit(assign(r0218, bit_xor(r0218, body.constant(1u)), 0x01));

                           body.emit(assign(r03B0, add(r03AA, body.constant(int(-1))), 0x01));

                           ir_variable *const r071D = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r071D, add(r03B0, body.constant(int(-10))), 0x01));

                           ir_variable *const r071E = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r071E, r0717, 0x01));

                           ir_variable *const r071F = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r071F, r0718, 0x01));

                           ir_variable *const r0720 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r0720);
                           ir_variable *const r0721 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r0721);
                           /* IF CONDITION */
                           ir_expression *const r0723 = equal(r0717, body.constant(0u));
                           ir_if *f0722 = new(mem_ctx) ir_if(operand(r0723).val);
                           exec_list *const f0722_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0722->then_instructions;

                              body.emit(assign(r071E, r0718, 0x01));

                              body.emit(assign(r071F, body.constant(0u), 0x01));

                              body.emit(assign(r071D, add(r071D, body.constant(int(-32))), 0x01));


                           body.instructions = f0722_parent_instructions;
                           body.emit(f0722);

                           /* END IF */

                           ir_variable *const r0724 = body.make_temp(glsl_type::uint_type, "a");
                           body.emit(assign(r0724, r071E, 0x01));

                           ir_variable *const r0725 = body.make_temp(glsl_type::int_type, "return_value");
                           ir_variable *const r0726 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r0726);
                           /* IF CONDITION */
                           ir_expression *const r0728 = equal(r071E, body.constant(0u));
                           ir_if *f0727 = new(mem_ctx) ir_if(operand(r0728).val);
                           exec_list *const f0727_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0727->then_instructions;

                              body.emit(assign(r0725, body.constant(int(32)), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0727->else_instructions;

                              body.emit(assign(r0726, body.constant(int(0)), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r072A = bit_and(r071E, body.constant(4294901760u));
                              ir_expression *const r072B = equal(r072A, body.constant(0u));
                              ir_if *f0729 = new(mem_ctx) ir_if(operand(r072B).val);
                              exec_list *const f0729_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0729->then_instructions;

                                 body.emit(assign(r0726, body.constant(int(16)), 0x01));

                                 body.emit(assign(r0724, lshift(r071E, body.constant(int(16))), 0x01));


                              body.instructions = f0729_parent_instructions;
                              body.emit(f0729);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r072D = bit_and(r0724, body.constant(4278190080u));
                              ir_expression *const r072E = equal(r072D, body.constant(0u));
                              ir_if *f072C = new(mem_ctx) ir_if(operand(r072E).val);
                              exec_list *const f072C_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f072C->then_instructions;

                                 body.emit(assign(r0726, add(r0726, body.constant(int(8))), 0x01));

                                 body.emit(assign(r0724, lshift(r0724, body.constant(int(8))), 0x01));


                              body.instructions = f072C_parent_instructions;
                              body.emit(f072C);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0730 = bit_and(r0724, body.constant(4026531840u));
                              ir_expression *const r0731 = equal(r0730, body.constant(0u));
                              ir_if *f072F = new(mem_ctx) ir_if(operand(r0731).val);
                              exec_list *const f072F_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f072F->then_instructions;

                                 body.emit(assign(r0726, add(r0726, body.constant(int(4))), 0x01));

                                 body.emit(assign(r0724, lshift(r0724, body.constant(int(4))), 0x01));


                              body.instructions = f072F_parent_instructions;
                              body.emit(f072F);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0733 = bit_and(r0724, body.constant(3221225472u));
                              ir_expression *const r0734 = equal(r0733, body.constant(0u));
                              ir_if *f0732 = new(mem_ctx) ir_if(operand(r0734).val);
                              exec_list *const f0732_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0732->then_instructions;

                                 body.emit(assign(r0726, add(r0726, body.constant(int(2))), 0x01));

                                 body.emit(assign(r0724, lshift(r0724, body.constant(int(2))), 0x01));


                              body.instructions = f0732_parent_instructions;
                              body.emit(f0732);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0736 = bit_and(r0724, body.constant(2147483648u));
                              ir_expression *const r0737 = equal(r0736, body.constant(0u));
                              ir_if *f0735 = new(mem_ctx) ir_if(operand(r0737).val);
                              exec_list *const f0735_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0735->then_instructions;

                                 body.emit(assign(r0726, add(r0726, body.constant(int(1))), 0x01));


                              body.instructions = f0735_parent_instructions;
                              body.emit(f0735);

                              /* END IF */

                              body.emit(assign(r0725, r0726, 0x01));


                           body.instructions = f0727_parent_instructions;
                           body.emit(f0727);

                           /* END IF */

                           body.emit(assign(r0721, add(r0725, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0739 = lequal(body.constant(int(0)), r0721);
                           ir_if *f0738 = new(mem_ctx) ir_if(operand(r0739).val);
                           exec_list *const f0738_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0738->then_instructions;

                              body.emit(assign(r0720, body.constant(0u), 0x01));

                              ir_variable *const r073A = body.make_temp(glsl_type::uint_type, "z1Ptr");
                              body.emit(assign(r073A, lshift(r071F, r0721), 0x01));

                              ir_variable *const r073B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r073D = equal(r0721, body.constant(int(0)));
                              ir_if *f073C = new(mem_ctx) ir_if(operand(r073D).val);
                              exec_list *const f073C_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f073C->then_instructions;

                                 body.emit(assign(r073B, r071E, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f073C->else_instructions;

                                 ir_expression *const r073E = lshift(r071E, r0721);
                                 ir_expression *const r073F = neg(r0721);
                                 ir_expression *const r0740 = bit_and(r073F, body.constant(int(31)));
                                 ir_expression *const r0741 = rshift(r071F, r0740);
                                 body.emit(assign(r073B, bit_or(r073E, r0741), 0x01));


                              body.instructions = f073C_parent_instructions;
                              body.emit(f073C);

                              /* END IF */

                              body.emit(assign(r071E, r073B, 0x01));

                              body.emit(assign(r071F, r073A, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0738->else_instructions;

                              ir_variable *const r0742 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r0742, body.constant(0u), 0x01));

                              ir_variable *const r0743 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0743, neg(r0721), 0x01));

                              ir_variable *const r0744 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0744);
                              ir_variable *const r0745 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0745);
                              ir_variable *const r0746 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0746);
                              ir_variable *const r0747 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0748 = neg(r0743);
                              body.emit(assign(r0747, bit_and(r0748, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r074A = equal(r0743, body.constant(int(0)));
                              ir_if *f0749 = new(mem_ctx) ir_if(operand(r074A).val);
                              exec_list *const f0749_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0749->then_instructions;

                                 body.emit(assign(r0744, r0742, 0x01));

                                 body.emit(assign(r0745, r071F, 0x01));

                                 body.emit(assign(r0746, r071E, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0749->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r074C = less(r0743, body.constant(int(32)));
                                 ir_if *f074B = new(mem_ctx) ir_if(operand(r074C).val);
                                 exec_list *const f074B_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f074B->then_instructions;

                                    body.emit(assign(r0744, lshift(r071F, r0747), 0x01));

                                    ir_expression *const r074D = lshift(r071E, r0747);
                                    ir_expression *const r074E = rshift(r071F, r0743);
                                    body.emit(assign(r0745, bit_or(r074D, r074E), 0x01));

                                    body.emit(assign(r0746, rshift(r071E, r0743), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f074B->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0750 = equal(r0743, body.constant(int(32)));
                                    ir_if *f074F = new(mem_ctx) ir_if(operand(r0750).val);
                                    exec_list *const f074F_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f074F->then_instructions;

                                       body.emit(assign(r0744, r071F, 0x01));

                                       body.emit(assign(r0745, r071E, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f074F->else_instructions;

                                       body.emit(assign(r0742, bit_or(body.constant(0u), r071F), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r0752 = less(r0743, body.constant(int(64)));
                                       ir_if *f0751 = new(mem_ctx) ir_if(operand(r0752).val);
                                       exec_list *const f0751_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0751->then_instructions;

                                          body.emit(assign(r0744, lshift(r071E, r0747), 0x01));

                                          ir_expression *const r0753 = bit_and(r0743, body.constant(int(31)));
                                          body.emit(assign(r0745, rshift(r071E, r0753), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0751->else_instructions;

                                          ir_variable *const r0754 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r0756 = equal(r0743, body.constant(int(64)));
                                          ir_if *f0755 = new(mem_ctx) ir_if(operand(r0756).val);
                                          exec_list *const f0755_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0755->then_instructions;

                                             body.emit(assign(r0754, r071E, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0755->else_instructions;

                                             ir_expression *const r0757 = nequal(r071E, body.constant(0u));
                                             ir_expression *const r0758 = expr(ir_unop_b2i, r0757);
                                             body.emit(assign(r0754, expr(ir_unop_i2u, r0758), 0x01));


                                          body.instructions = f0755_parent_instructions;
                                          body.emit(f0755);

                                          /* END IF */

                                          body.emit(assign(r0744, r0754, 0x01));

                                          body.emit(assign(r0745, body.constant(0u), 0x01));


                                       body.instructions = f0751_parent_instructions;
                                       body.emit(f0751);

                                       /* END IF */


                                    body.instructions = f074F_parent_instructions;
                                    body.emit(f074F);

                                    /* END IF */

                                    body.emit(assign(r0746, body.constant(0u), 0x01));


                                 body.instructions = f074B_parent_instructions;
                                 body.emit(f074B);

                                 /* END IF */

                                 ir_expression *const r0759 = nequal(r0742, body.constant(0u));
                                 ir_expression *const r075A = expr(ir_unop_b2i, r0759);
                                 ir_expression *const r075B = expr(ir_unop_i2u, r075A);
                                 body.emit(assign(r0744, bit_or(r0744, r075B), 0x01));


                              body.instructions = f0749_parent_instructions;
                              body.emit(f0749);

                              /* END IF */

                              body.emit(assign(r071E, r0746, 0x01));

                              body.emit(assign(r071F, r0745, 0x01));

                              body.emit(assign(r0720, r0744, 0x01));


                           body.instructions = f0738_parent_instructions;
                           body.emit(f0738);

                           /* END IF */

                           body.emit(assign(r071D, sub(r071D, r0721), 0x01));

                           ir_variable *const r075C = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r075C, r071D, 0x01));

                           ir_variable *const r075D = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r075D, r071E, 0x01));

                           ir_variable *const r075E = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r075E, r071F, 0x01));

                           ir_variable *const r075F = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r075F, r0720, 0x01));

                           ir_variable *const r0760 = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r0760, body.constant(true), 0x01));

                           ir_variable *const r0761 = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r0762 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r0762);
                           ir_expression *const r0763 = expr(ir_unop_u2i, r0720);
                           body.emit(assign(r0762, less(r0763, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0765 = lequal(body.constant(int(2045)), r071D);
                           ir_if *f0764 = new(mem_ctx) ir_if(operand(r0765).val);
                           exec_list *const f0764_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0764->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0767 = less(body.constant(int(2045)), r071D);
                              ir_expression *const r0768 = equal(r071D, body.constant(int(2045)));
                              ir_expression *const r0769 = equal(body.constant(2097151u), r071E);
                              ir_expression *const r076A = equal(body.constant(4294967295u), r071F);
                              ir_expression *const r076B = logic_and(r0769, r076A);
                              ir_expression *const r076C = logic_and(r0768, r076B);
                              ir_expression *const r076D = logic_and(r076C, r0762);
                              ir_expression *const r076E = logic_or(r0767, r076D);
                              ir_if *f0766 = new(mem_ctx) ir_if(operand(r076E).val);
                              exec_list *const f0766_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0766->then_instructions;

                                 ir_variable *const r076F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r076F);
                                 ir_expression *const r0770 = lshift(r0218, body.constant(int(31)));
                                 body.emit(assign(r076F, add(r0770, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r076F, body.constant(0u), 0x01));

                                 body.emit(assign(r0761, r076F, 0x03));

                                 body.emit(assign(r0760, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0766->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0772 = less(r071D, body.constant(int(0)));
                                 ir_if *f0771 = new(mem_ctx) ir_if(operand(r0772).val);
                                 exec_list *const f0771_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0771->then_instructions;

                                    ir_variable *const r0773 = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r0773, r0720, 0x01));

                                    ir_variable *const r0774 = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r0774, neg(r071D), 0x01));

                                    ir_variable *const r0775 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r0775);
                                    ir_variable *const r0776 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r0776);
                                    ir_variable *const r0777 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r0777);
                                    ir_variable *const r0778 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r0779 = neg(r0774);
                                    body.emit(assign(r0778, bit_and(r0779, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r077B = equal(r0774, body.constant(int(0)));
                                    ir_if *f077A = new(mem_ctx) ir_if(operand(r077B).val);
                                    exec_list *const f077A_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f077A->then_instructions;

                                       body.emit(assign(r0775, r0720, 0x01));

                                       body.emit(assign(r0776, r071F, 0x01));

                                       body.emit(assign(r0777, r071E, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f077A->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r077D = less(r0774, body.constant(int(32)));
                                       ir_if *f077C = new(mem_ctx) ir_if(operand(r077D).val);
                                       exec_list *const f077C_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f077C->then_instructions;

                                          body.emit(assign(r0775, lshift(r071F, r0778), 0x01));

                                          ir_expression *const r077E = lshift(r071E, r0778);
                                          ir_expression *const r077F = rshift(r071F, r0774);
                                          body.emit(assign(r0776, bit_or(r077E, r077F), 0x01));

                                          body.emit(assign(r0777, rshift(r071E, r0774), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f077C->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r0781 = equal(r0774, body.constant(int(32)));
                                          ir_if *f0780 = new(mem_ctx) ir_if(operand(r0781).val);
                                          exec_list *const f0780_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0780->then_instructions;

                                             body.emit(assign(r0775, r071F, 0x01));

                                             body.emit(assign(r0776, r071E, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0780->else_instructions;

                                             body.emit(assign(r0773, bit_or(r0720, r071F), 0x01));

                                             /* IF CONDITION */
                                             ir_expression *const r0783 = less(r0774, body.constant(int(64)));
                                             ir_if *f0782 = new(mem_ctx) ir_if(operand(r0783).val);
                                             exec_list *const f0782_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f0782->then_instructions;

                                                body.emit(assign(r0775, lshift(r071E, r0778), 0x01));

                                                ir_expression *const r0784 = bit_and(r0774, body.constant(int(31)));
                                                body.emit(assign(r0776, rshift(r071E, r0784), 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f0782->else_instructions;

                                                ir_variable *const r0785 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                                /* IF CONDITION */
                                                ir_expression *const r0787 = equal(r0774, body.constant(int(64)));
                                                ir_if *f0786 = new(mem_ctx) ir_if(operand(r0787).val);
                                                exec_list *const f0786_parent_instructions = body.instructions;

                                                   /* THEN INSTRUCTIONS */
                                                   body.instructions = &f0786->then_instructions;

                                                   body.emit(assign(r0785, r071E, 0x01));


                                                   /* ELSE INSTRUCTIONS */
                                                   body.instructions = &f0786->else_instructions;

                                                   ir_expression *const r0788 = nequal(r071E, body.constant(0u));
                                                   ir_expression *const r0789 = expr(ir_unop_b2i, r0788);
                                                   body.emit(assign(r0785, expr(ir_unop_i2u, r0789), 0x01));


                                                body.instructions = f0786_parent_instructions;
                                                body.emit(f0786);

                                                /* END IF */

                                                body.emit(assign(r0775, r0785, 0x01));

                                                body.emit(assign(r0776, body.constant(0u), 0x01));


                                             body.instructions = f0782_parent_instructions;
                                             body.emit(f0782);

                                             /* END IF */


                                          body.instructions = f0780_parent_instructions;
                                          body.emit(f0780);

                                          /* END IF */

                                          body.emit(assign(r0777, body.constant(0u), 0x01));


                                       body.instructions = f077C_parent_instructions;
                                       body.emit(f077C);

                                       /* END IF */

                                       ir_expression *const r078A = nequal(r0773, body.constant(0u));
                                       ir_expression *const r078B = expr(ir_unop_b2i, r078A);
                                       ir_expression *const r078C = expr(ir_unop_i2u, r078B);
                                       body.emit(assign(r0775, bit_or(r0775, r078C), 0x01));


                                    body.instructions = f077A_parent_instructions;
                                    body.emit(f077A);

                                    /* END IF */

                                    body.emit(assign(r075D, r0777, 0x01));

                                    body.emit(assign(r075E, r0776, 0x01));

                                    body.emit(assign(r075F, r0775, 0x01));

                                    body.emit(assign(r075C, body.constant(int(0)), 0x01));

                                    body.emit(assign(r0762, less(r0775, body.constant(0u)), 0x01));


                                 body.instructions = f0771_parent_instructions;
                                 body.emit(f0771);

                                 /* END IF */


                              body.instructions = f0766_parent_instructions;
                              body.emit(f0766);

                              /* END IF */


                           body.instructions = f0764_parent_instructions;
                           body.emit(f0764);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f078D = new(mem_ctx) ir_if(operand(r0760).val);
                           exec_list *const f078D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f078D->then_instructions;

                              /* IF CONDITION */
                              ir_if *f078E = new(mem_ctx) ir_if(operand(r0762).val);
                              exec_list *const f078E_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f078E->then_instructions;

                                 ir_variable *const r078F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r078F, add(r075E, body.constant(1u)), 0x01));

                                 ir_expression *const r0790 = less(r078F, r075E);
                                 ir_expression *const r0791 = expr(ir_unop_b2i, r0790);
                                 ir_expression *const r0792 = expr(ir_unop_i2u, r0791);
                                 body.emit(assign(r075D, add(r075D, r0792), 0x01));

                                 ir_expression *const r0793 = equal(r075F, body.constant(0u));
                                 ir_expression *const r0794 = expr(ir_unop_b2i, r0793);
                                 ir_expression *const r0795 = expr(ir_unop_i2u, r0794);
                                 ir_expression *const r0796 = add(r075F, r0795);
                                 ir_expression *const r0797 = bit_and(r0796, body.constant(1u));
                                 ir_expression *const r0798 = expr(ir_unop_bit_not, r0797);
                                 body.emit(assign(r075E, bit_and(r078F, r0798), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f078E->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r079A = bit_or(r075D, r075E);
                                 ir_expression *const r079B = equal(r079A, body.constant(0u));
                                 ir_if *f0799 = new(mem_ctx) ir_if(operand(r079B).val);
                                 exec_list *const f0799_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0799->then_instructions;

                                    body.emit(assign(r075C, body.constant(int(0)), 0x01));


                                 body.instructions = f0799_parent_instructions;
                                 body.emit(f0799);

                                 /* END IF */


                              body.instructions = f078E_parent_instructions;
                              body.emit(f078E);

                              /* END IF */

                              ir_variable *const r079C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r079C);
                              ir_expression *const r079D = lshift(r0218, body.constant(int(31)));
                              ir_expression *const r079E = expr(ir_unop_i2u, r075C);
                              ir_expression *const r079F = lshift(r079E, body.constant(int(20)));
                              ir_expression *const r07A0 = add(r079D, r079F);
                              body.emit(assign(r079C, add(r07A0, r075D), 0x02));

                              body.emit(assign(r079C, r075E, 0x01));

                              body.emit(assign(r0761, r079C, 0x03));

                              body.emit(assign(r0760, body.constant(false), 0x01));


                           body.instructions = f078D_parent_instructions;
                           body.emit(f078D);

                           /* END IF */

                           body.emit(assign(r0217, r0761, 0x03));

                           body.emit(assign(r0216, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0715->else_instructions;

                           ir_variable *const r07A1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r07A1);
                           body.emit(assign(r07A1, body.constant(0u), 0x02));

                           body.emit(assign(r07A1, body.constant(0u), 0x01));

                           body.emit(assign(r0217, r07A1, 0x03));

                           body.emit(assign(r0216, body.constant(false), 0x01));


                        body.instructions = f0715_parent_instructions;
                        body.emit(f0715);

                        /* END IF */


                     body.instructions = f0689_parent_instructions;
                     body.emit(f0689);

                     /* END IF */


                  body.instructions = f05FD_parent_instructions;
                  body.emit(f05FD);

                  /* END IF */


               body.instructions = f0571_parent_instructions;
               body.emit(f0571);

               /* END IF */


            body.instructions = f0553_parent_instructions;
            body.emit(f0553);

            /* END IF */


         body.instructions = f0488_parent_instructions;
         body.emit(f0488);

         /* END IF */


      body.instructions = f03C1_parent_instructions;
      body.emit(f03C1);

      /* END IF */


   body.instructions = f021B_parent_instructions;
   body.emit(f021B);

   /* END IF */

   body.emit(ret(r0217));

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

   ir_variable *const r07A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r07A2);
   ir_variable *const r07A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r07A3);
   ir_variable *const r07A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07A4);
   ir_variable *const r07A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07A5);
   ir_variable *const r07A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07A6);
   ir_variable *const r07A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07A7);
   ir_variable *const r07A8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07A8);
   ir_variable *const r07A9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A9, bit_and(r07A2, body.constant(65535u)), 0x01));

   ir_variable *const r07AA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07AA, rshift(r07A2, body.constant(int(16))), 0x01));

   ir_variable *const r07AB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07AB, bit_and(r07A3, body.constant(65535u)), 0x01));

   ir_variable *const r07AC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07AC, rshift(r07A3, body.constant(int(16))), 0x01));

   ir_variable *const r07AD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07AD, mul(r07AA, r07AB), 0x01));

   ir_expression *const r07AE = mul(r07A9, r07AC);
   body.emit(assign(r07A7, add(r07AE, r07AD), 0x01));

   ir_expression *const r07AF = mul(r07AA, r07AC);
   ir_expression *const r07B0 = less(r07A7, r07AD);
   ir_expression *const r07B1 = expr(ir_unop_b2i, r07B0);
   ir_expression *const r07B2 = expr(ir_unop_i2u, r07B1);
   ir_expression *const r07B3 = lshift(r07B2, body.constant(int(16)));
   ir_expression *const r07B4 = rshift(r07A7, body.constant(int(16)));
   ir_expression *const r07B5 = add(r07B3, r07B4);
   body.emit(assign(r07A6, add(r07AF, r07B5), 0x01));

   body.emit(assign(r07A7, lshift(r07A7, body.constant(int(16))), 0x01));

   ir_expression *const r07B6 = mul(r07A9, r07AB);
   body.emit(assign(r07A8, add(r07B6, r07A7), 0x01));

   ir_expression *const r07B7 = less(r07A8, r07A7);
   ir_expression *const r07B8 = expr(ir_unop_b2i, r07B7);
   ir_expression *const r07B9 = expr(ir_unop_i2u, r07B8);
   body.emit(assign(r07A6, add(r07A6, r07B9), 0x01));

   body.emit(assign(r07A5, r07A8, 0x01));

   body.emit(assign(r07A4, r07A6, 0x01));

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

   ir_variable *const r07BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r07BA);
   ir_variable *const r07BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r07BB);
   ir_variable *const r07BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r07BC);
   ir_variable *const r07BD = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r07BD);
   ir_variable *const r07BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07BE);
   ir_variable *const r07BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07BF);
   ir_variable *const r07C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07C0);
   ir_variable *const r07C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07C1);
   ir_variable *const r07C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07C2);
   ir_variable *const r07C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07C3);
   ir_variable *const r07C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07C4);
   ir_variable *const r07C5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C5, bit_and(r07BB, body.constant(65535u)), 0x01));

   ir_variable *const r07C6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C6, rshift(r07BB, body.constant(int(16))), 0x01));

   ir_variable *const r07C7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C7, bit_and(r07BD, body.constant(65535u)), 0x01));

   ir_variable *const r07C8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07C8, rshift(r07BD, body.constant(int(16))), 0x01));

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

   ir_variable *const r07D6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07D6);
   ir_variable *const r07D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07D7);
   ir_variable *const r07D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07D8);
   ir_variable *const r07D9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D9, bit_and(r07BB, body.constant(65535u)), 0x01));

   ir_variable *const r07DA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DA, rshift(r07BB, body.constant(int(16))), 0x01));

   ir_variable *const r07DB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DB, bit_and(r07BC, body.constant(65535u)), 0x01));

   ir_variable *const r07DC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DC, rshift(r07BC, body.constant(int(16))), 0x01));

   ir_variable *const r07DD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07DD, mul(r07DA, r07DB), 0x01));

   ir_expression *const r07DE = mul(r07D9, r07DC);
   body.emit(assign(r07D7, add(r07DE, r07DD), 0x01));

   ir_expression *const r07DF = mul(r07DA, r07DC);
   ir_expression *const r07E0 = less(r07D7, r07DD);
   ir_expression *const r07E1 = expr(ir_unop_b2i, r07E0);
   ir_expression *const r07E2 = expr(ir_unop_i2u, r07E1);
   ir_expression *const r07E3 = lshift(r07E2, body.constant(int(16)));
   ir_expression *const r07E4 = rshift(r07D7, body.constant(int(16)));
   ir_expression *const r07E5 = add(r07E3, r07E4);
   body.emit(assign(r07D6, add(r07DF, r07E5), 0x01));

   body.emit(assign(r07D7, lshift(r07D7, body.constant(int(16))), 0x01));

   ir_expression *const r07E6 = mul(r07D9, r07DB);
   body.emit(assign(r07D8, add(r07E6, r07D7), 0x01));

   ir_expression *const r07E7 = less(r07D8, r07D7);
   ir_expression *const r07E8 = expr(ir_unop_b2i, r07E7);
   ir_expression *const r07E9 = expr(ir_unop_i2u, r07E8);
   body.emit(assign(r07D6, add(r07D6, r07E9), 0x01));

   ir_variable *const r07EA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EA, add(r07D8, r07C2), 0x01));

   ir_variable *const r07EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07EB);
   ir_variable *const r07EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07EC);
   ir_variable *const r07ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07ED);
   ir_variable *const r07EE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EE, bit_and(r07BA, body.constant(65535u)), 0x01));

   ir_variable *const r07EF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07EF, rshift(r07BA, body.constant(int(16))), 0x01));

   ir_variable *const r07F0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07F0, bit_and(r07BC, body.constant(65535u)), 0x01));

   ir_variable *const r07F1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07F1, rshift(r07BC, body.constant(int(16))), 0x01));

   ir_variable *const r07F2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07F2, mul(r07EF, r07F0), 0x01));

   ir_expression *const r07F3 = mul(r07EE, r07F1);
   body.emit(assign(r07EC, add(r07F3, r07F2), 0x01));

   ir_expression *const r07F4 = mul(r07EF, r07F1);
   ir_expression *const r07F5 = less(r07EC, r07F2);
   ir_expression *const r07F6 = expr(ir_unop_b2i, r07F5);
   ir_expression *const r07F7 = expr(ir_unop_i2u, r07F6);
   ir_expression *const r07F8 = lshift(r07F7, body.constant(int(16)));
   ir_expression *const r07F9 = rshift(r07EC, body.constant(int(16)));
   ir_expression *const r07FA = add(r07F8, r07F9);
   body.emit(assign(r07EB, add(r07F4, r07FA), 0x01));

   body.emit(assign(r07EC, lshift(r07EC, body.constant(int(16))), 0x01));

   ir_expression *const r07FB = mul(r07EE, r07F0);
   body.emit(assign(r07ED, add(r07FB, r07EC), 0x01));

   ir_expression *const r07FC = less(r07ED, r07EC);
   ir_expression *const r07FD = expr(ir_unop_b2i, r07FC);
   ir_expression *const r07FE = expr(ir_unop_i2u, r07FD);
   body.emit(assign(r07EB, add(r07EB, r07FE), 0x01));

   ir_variable *const r07FF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0800 = less(r07EA, r07D8);
   ir_expression *const r0801 = expr(ir_unop_b2i, r0800);
   ir_expression *const r0802 = expr(ir_unop_i2u, r0801);
   ir_expression *const r0803 = add(r07D6, r0802);
   body.emit(assign(r07FF, add(r07ED, r0803), 0x01));

   ir_variable *const r0804 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0804);
   ir_variable *const r0805 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0805);
   ir_variable *const r0806 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0806);
   ir_variable *const r0807 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0807, bit_and(r07BA, body.constant(65535u)), 0x01));

   ir_variable *const r0808 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0808, rshift(r07BA, body.constant(int(16))), 0x01));

   ir_variable *const r0809 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0809, bit_and(r07BD, body.constant(65535u)), 0x01));

   ir_variable *const r080A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r080A, rshift(r07BD, body.constant(int(16))), 0x01));

   ir_variable *const r080B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r080B, mul(r0808, r0809), 0x01));

   ir_expression *const r080C = mul(r0807, r080A);
   body.emit(assign(r0805, add(r080C, r080B), 0x01));

   ir_expression *const r080D = mul(r0808, r080A);
   ir_expression *const r080E = less(r0805, r080B);
   ir_expression *const r080F = expr(ir_unop_b2i, r080E);
   ir_expression *const r0810 = expr(ir_unop_i2u, r080F);
   ir_expression *const r0811 = lshift(r0810, body.constant(int(16)));
   ir_expression *const r0812 = rshift(r0805, body.constant(int(16)));
   ir_expression *const r0813 = add(r0811, r0812);
   body.emit(assign(r0804, add(r080D, r0813), 0x01));

   body.emit(assign(r0805, lshift(r0805, body.constant(int(16))), 0x01));

   ir_expression *const r0814 = mul(r0807, r0809);
   body.emit(assign(r0806, add(r0814, r0805), 0x01));

   ir_expression *const r0815 = less(r0806, r0805);
   ir_expression *const r0816 = expr(ir_unop_b2i, r0815);
   ir_expression *const r0817 = expr(ir_unop_i2u, r0816);
   body.emit(assign(r0804, add(r0804, r0817), 0x01));

   ir_variable *const r0818 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0818, add(r0806, r07EA), 0x01));

   ir_variable *const r0819 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r081A = less(r0818, r0806);
   ir_expression *const r081B = expr(ir_unop_b2i, r081A);
   ir_expression *const r081C = expr(ir_unop_i2u, r081B);
   ir_expression *const r081D = add(r0804, r081C);
   body.emit(assign(r0819, add(r07FF, r081D), 0x01));

   body.emit(assign(r07C1, r07C4, 0x01));

   body.emit(assign(r07C0, r0818, 0x01));

   body.emit(assign(r07BF, r0819, 0x01));

   ir_expression *const r081E = less(r07FF, r07ED);
   ir_expression *const r081F = expr(ir_unop_b2i, r081E);
   ir_expression *const r0820 = expr(ir_unop_i2u, r081F);
   ir_expression *const r0821 = add(r07EB, r0820);
   ir_expression *const r0822 = less(r0819, r07FF);
   ir_expression *const r0823 = expr(ir_unop_b2i, r0822);
   ir_expression *const r0824 = expr(ir_unop_i2u, r0823);
   body.emit(assign(r07BE, add(r0821, r0824), 0x01));

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

   ir_variable *const r0825 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r0825);
   ir_variable *const r0826 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r0826);
   ir_variable *const r0827 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r0827);
   ir_variable *const r0828 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0828);
   ir_variable *const r0829 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0829);
   ir_variable *const r082A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r082A);
   /* IF CONDITION */
   ir_expression *const r082C = equal(r0825, body.constant(0u));
   ir_if *f082B = new(mem_ctx) ir_if(operand(r082C).val);
   exec_list *const f082B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f082B->then_instructions;

      ir_variable *const r082D = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r082D, r0826, 0x01));

      ir_variable *const r082E = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r082F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r082F);
      /* IF CONDITION */
      ir_expression *const r0831 = equal(r0826, body.constant(0u));
      ir_if *f0830 = new(mem_ctx) ir_if(operand(r0831).val);
      exec_list *const f0830_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0830->then_instructions;

         body.emit(assign(r082E, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0830->else_instructions;

         body.emit(assign(r082F, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0833 = bit_and(r0826, body.constant(4294901760u));
         ir_expression *const r0834 = equal(r0833, body.constant(0u));
         ir_if *f0832 = new(mem_ctx) ir_if(operand(r0834).val);
         exec_list *const f0832_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0832->then_instructions;

            body.emit(assign(r082F, body.constant(int(16)), 0x01));

            body.emit(assign(r082D, lshift(r0826, body.constant(int(16))), 0x01));


         body.instructions = f0832_parent_instructions;
         body.emit(f0832);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0836 = bit_and(r082D, body.constant(4278190080u));
         ir_expression *const r0837 = equal(r0836, body.constant(0u));
         ir_if *f0835 = new(mem_ctx) ir_if(operand(r0837).val);
         exec_list *const f0835_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0835->then_instructions;

            body.emit(assign(r082F, add(r082F, body.constant(int(8))), 0x01));

            body.emit(assign(r082D, lshift(r082D, body.constant(int(8))), 0x01));


         body.instructions = f0835_parent_instructions;
         body.emit(f0835);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0839 = bit_and(r082D, body.constant(4026531840u));
         ir_expression *const r083A = equal(r0839, body.constant(0u));
         ir_if *f0838 = new(mem_ctx) ir_if(operand(r083A).val);
         exec_list *const f0838_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0838->then_instructions;

            body.emit(assign(r082F, add(r082F, body.constant(int(4))), 0x01));

            body.emit(assign(r082D, lshift(r082D, body.constant(int(4))), 0x01));


         body.instructions = f0838_parent_instructions;
         body.emit(f0838);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r083C = bit_and(r082D, body.constant(3221225472u));
         ir_expression *const r083D = equal(r083C, body.constant(0u));
         ir_if *f083B = new(mem_ctx) ir_if(operand(r083D).val);
         exec_list *const f083B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f083B->then_instructions;

            body.emit(assign(r082F, add(r082F, body.constant(int(2))), 0x01));

            body.emit(assign(r082D, lshift(r082D, body.constant(int(2))), 0x01));


         body.instructions = f083B_parent_instructions;
         body.emit(f083B);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r083F = bit_and(r082D, body.constant(2147483648u));
         ir_expression *const r0840 = equal(r083F, body.constant(0u));
         ir_if *f083E = new(mem_ctx) ir_if(operand(r0840).val);
         exec_list *const f083E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f083E->then_instructions;

            body.emit(assign(r082F, add(r082F, body.constant(int(1))), 0x01));


         body.instructions = f083E_parent_instructions;
         body.emit(f083E);

         /* END IF */

         body.emit(assign(r082E, r082F, 0x01));


      body.instructions = f0830_parent_instructions;
      body.emit(f0830);

      /* END IF */

      body.emit(assign(r082A, add(r082E, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0842 = less(r082A, body.constant(int(0)));
      ir_if *f0841 = new(mem_ctx) ir_if(operand(r0842).val);
      exec_list *const f0841_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0841->then_instructions;

         ir_expression *const r0843 = neg(r082A);
         body.emit(assign(r0828, rshift(r0826, r0843), 0x01));

         ir_expression *const r0844 = bit_and(r082A, body.constant(int(31)));
         body.emit(assign(r0829, lshift(r0826, r0844), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0841->else_instructions;

         body.emit(assign(r0828, lshift(r0826, r082A), 0x01));

         body.emit(assign(r0829, body.constant(0u), 0x01));


      body.instructions = f0841_parent_instructions;
      body.emit(f0841);

      /* END IF */

      body.emit(assign(r0827, sub(body.constant(int(-31)), r082A), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f082B->else_instructions;

      ir_variable *const r0845 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0845, r0825, 0x01));

      ir_variable *const r0846 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0847 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0847);
      /* IF CONDITION */
      ir_expression *const r0849 = equal(r0825, body.constant(0u));
      ir_if *f0848 = new(mem_ctx) ir_if(operand(r0849).val);
      exec_list *const f0848_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0848->then_instructions;

         body.emit(assign(r0846, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0848->else_instructions;

         body.emit(assign(r0847, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r084B = bit_and(r0825, body.constant(4294901760u));
         ir_expression *const r084C = equal(r084B, body.constant(0u));
         ir_if *f084A = new(mem_ctx) ir_if(operand(r084C).val);
         exec_list *const f084A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f084A->then_instructions;

            body.emit(assign(r0847, body.constant(int(16)), 0x01));

            body.emit(assign(r0845, lshift(r0825, body.constant(int(16))), 0x01));


         body.instructions = f084A_parent_instructions;
         body.emit(f084A);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r084E = bit_and(r0845, body.constant(4278190080u));
         ir_expression *const r084F = equal(r084E, body.constant(0u));
         ir_if *f084D = new(mem_ctx) ir_if(operand(r084F).val);
         exec_list *const f084D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f084D->then_instructions;

            body.emit(assign(r0847, add(r0847, body.constant(int(8))), 0x01));

            body.emit(assign(r0845, lshift(r0845, body.constant(int(8))), 0x01));


         body.instructions = f084D_parent_instructions;
         body.emit(f084D);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0851 = bit_and(r0845, body.constant(4026531840u));
         ir_expression *const r0852 = equal(r0851, body.constant(0u));
         ir_if *f0850 = new(mem_ctx) ir_if(operand(r0852).val);
         exec_list *const f0850_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0850->then_instructions;

            body.emit(assign(r0847, add(r0847, body.constant(int(4))), 0x01));

            body.emit(assign(r0845, lshift(r0845, body.constant(int(4))), 0x01));


         body.instructions = f0850_parent_instructions;
         body.emit(f0850);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0854 = bit_and(r0845, body.constant(3221225472u));
         ir_expression *const r0855 = equal(r0854, body.constant(0u));
         ir_if *f0853 = new(mem_ctx) ir_if(operand(r0855).val);
         exec_list *const f0853_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0853->then_instructions;

            body.emit(assign(r0847, add(r0847, body.constant(int(2))), 0x01));

            body.emit(assign(r0845, lshift(r0845, body.constant(int(2))), 0x01));


         body.instructions = f0853_parent_instructions;
         body.emit(f0853);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0857 = bit_and(r0845, body.constant(2147483648u));
         ir_expression *const r0858 = equal(r0857, body.constant(0u));
         ir_if *f0856 = new(mem_ctx) ir_if(operand(r0858).val);
         exec_list *const f0856_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0856->then_instructions;

            body.emit(assign(r0847, add(r0847, body.constant(int(1))), 0x01));


         body.instructions = f0856_parent_instructions;
         body.emit(f0856);

         /* END IF */

         body.emit(assign(r0846, r0847, 0x01));


      body.instructions = f0848_parent_instructions;
      body.emit(f0848);

      /* END IF */

      body.emit(assign(r082A, add(r0846, body.constant(int(-11))), 0x01));

      ir_variable *const r0859 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0859, lshift(r0826, r082A), 0x01));

      ir_variable *const r085A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r085C = equal(r082A, body.constant(int(0)));
      ir_if *f085B = new(mem_ctx) ir_if(operand(r085C).val);
      exec_list *const f085B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f085B->then_instructions;

         body.emit(assign(r085A, r0825, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f085B->else_instructions;

         ir_expression *const r085D = lshift(r0825, r082A);
         ir_expression *const r085E = neg(r082A);
         ir_expression *const r085F = bit_and(r085E, body.constant(int(31)));
         ir_expression *const r0860 = rshift(r0826, r085F);
         body.emit(assign(r085A, bit_or(r085D, r0860), 0x01));


      body.instructions = f085B_parent_instructions;
      body.emit(f085B);

      /* END IF */

      body.emit(assign(r0828, r085A, 0x01));

      body.emit(assign(r0829, r0859, 0x01));

      body.emit(assign(r0827, sub(body.constant(int(1)), r082A), 0x01));


   body.instructions = f082B_parent_instructions;
   body.emit(f082B);

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

   ir_variable *const r0861 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0861);
   ir_variable *const r0862 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0862);
   ir_variable *const r0863 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0863, body.constant(true), 0x01));

   ir_variable *const r0864 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0865 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0865);
   ir_variable *const r0866 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r0866);
   ir_variable *const r0867 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0867);
   ir_variable *const r0868 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r0868);
   ir_variable *const r0869 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r0869);
   ir_variable *const r086A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r086A);
   ir_variable *const r086B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r086B);
   ir_variable *const r086C = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r086C);
   ir_variable *const r086D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r086D);
   ir_variable *const r086E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r086E);
   ir_variable *const r086F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r086F);
   body.emit(assign(r086F, body.constant(0u), 0x01));

   body.emit(assign(r086E, body.constant(0u), 0x01));

   body.emit(assign(r086D, body.constant(0u), 0x01));

   ir_variable *const r0870 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0870, swizzle_x(r0861), 0x01));

   body.emit(assign(r086B, r0870, 0x01));

   ir_variable *const r0871 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0871, bit_and(swizzle_y(r0861), body.constant(1048575u)), 0x01));

   body.emit(assign(r086A, r0871, 0x01));

   ir_variable *const r0872 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0872, swizzle_x(r0862), 0x01));

   body.emit(assign(r0869, r0872, 0x01));

   ir_variable *const r0873 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0873, bit_and(swizzle_y(r0862), body.constant(1048575u)), 0x01));

   body.emit(assign(r0868, r0873, 0x01));

   ir_variable *const r0874 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0875 = rshift(swizzle_y(r0861), body.constant(int(20)));
   ir_expression *const r0876 = bit_and(r0875, body.constant(2047u));
   body.emit(assign(r0874, expr(ir_unop_u2i, r0876), 0x01));

   body.emit(assign(r0867, r0874, 0x01));

   ir_variable *const r0877 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0878 = rshift(swizzle_y(r0862), body.constant(int(20)));
   ir_expression *const r0879 = bit_and(r0878, body.constant(2047u));
   body.emit(assign(r0877, expr(ir_unop_u2i, r0879), 0x01));

   body.emit(assign(r0866, r0877, 0x01));

   ir_expression *const r087A = rshift(swizzle_y(r0861), body.constant(int(31)));
   ir_expression *const r087B = rshift(swizzle_y(r0862), body.constant(int(31)));
   body.emit(assign(r0865, bit_xor(r087A, r087B), 0x01));

   /* IF CONDITION */
   ir_expression *const r087D = equal(r0874, body.constant(int(2047)));
   ir_if *f087C = new(mem_ctx) ir_if(operand(r087D).val);
   exec_list *const f087C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f087C->then_instructions;

      /* IF CONDITION */
      ir_expression *const r087F = bit_or(r0871, swizzle_x(r0861));
      ir_expression *const r0880 = nequal(r087F, body.constant(0u));
      ir_expression *const r0881 = equal(r0877, body.constant(int(2047)));
      ir_expression *const r0882 = bit_or(r0873, swizzle_x(r0862));
      ir_expression *const r0883 = nequal(r0882, body.constant(0u));
      ir_expression *const r0884 = logic_and(r0881, r0883);
      ir_expression *const r0885 = logic_or(r0880, r0884);
      ir_if *f087E = new(mem_ctx) ir_if(operand(r0885).val);
      exec_list *const f087E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f087E->then_instructions;

         ir_variable *const r0886 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r0886, swizzle_x(r0861), 0x01));

         ir_variable *const r0887 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r0887, swizzle_x(r0862), 0x01));

         ir_variable *const r0888 = body.make_temp(glsl_type::uvec2_type, "return_value");
         ir_variable *const r0889 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
         ir_expression *const r088A = lshift(swizzle_y(r0862), body.constant(int(1)));
         ir_expression *const r088B = lequal(body.constant(4292870144u), r088A);
         ir_expression *const r088C = nequal(swizzle_x(r0862), body.constant(0u));
         ir_expression *const r088D = bit_and(swizzle_y(r0862), body.constant(1048575u));
         ir_expression *const r088E = nequal(r088D, body.constant(0u));
         ir_expression *const r088F = logic_or(r088C, r088E);
         body.emit(assign(r0889, logic_and(r088B, r088F), 0x01));

         body.emit(assign(r0886, bit_or(swizzle_y(r0861), body.constant(524288u)), 0x02));

         body.emit(assign(r0887, bit_or(swizzle_y(r0862), body.constant(524288u)), 0x02));

         /* IF CONDITION */
         ir_expression *const r0891 = lshift(swizzle_y(r0861), body.constant(int(1)));
         ir_expression *const r0892 = lequal(body.constant(4292870144u), r0891);
         ir_expression *const r0893 = nequal(swizzle_x(r0861), body.constant(0u));
         ir_expression *const r0894 = bit_and(swizzle_y(r0861), body.constant(1048575u));
         ir_expression *const r0895 = nequal(r0894, body.constant(0u));
         ir_expression *const r0896 = logic_or(r0893, r0895);
         ir_expression *const r0897 = logic_and(r0892, r0896);
         ir_if *f0890 = new(mem_ctx) ir_if(operand(r0897).val);
         exec_list *const f0890_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0890->then_instructions;

            ir_variable *const r0898 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
            /* IF CONDITION */
            ir_if *f0899 = new(mem_ctx) ir_if(operand(r0889).val);
            exec_list *const f0899_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0899->then_instructions;

               body.emit(assign(r0898, r0887, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0899->else_instructions;

               body.emit(assign(r0898, r0886, 0x03));


            body.instructions = f0899_parent_instructions;
            body.emit(f0899);

            /* END IF */

            body.emit(assign(r0888, r0898, 0x03));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0890->else_instructions;

            body.emit(assign(r0888, r0887, 0x03));


         body.instructions = f0890_parent_instructions;
         body.emit(f0890);

         /* END IF */

         body.emit(assign(r0864, r0888, 0x03));

         body.emit(assign(r0863, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f087E->else_instructions;

         /* IF CONDITION */
         ir_expression *const r089B = expr(ir_unop_i2u, r0877);
         ir_expression *const r089C = bit_or(r089B, r0873);
         ir_expression *const r089D = bit_or(r089C, swizzle_x(r0862));
         ir_expression *const r089E = equal(r089D, body.constant(0u));
         ir_if *f089A = new(mem_ctx) ir_if(operand(r089E).val);
         exec_list *const f089A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f089A->then_instructions;

            ir_constant_data r089F_data;
            memset(&r089F_data, 0, sizeof(ir_constant_data));
            r089F_data.u[0] = 4294967295;
            r089F_data.u[1] = 4294967295;
            ir_constant *const r089F = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r089F_data);
            body.emit(assign(r0864, r089F, 0x03));

            body.emit(assign(r0863, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f089A->else_instructions;

            ir_variable *const r08A0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r08A0);
            ir_expression *const r08A1 = lshift(r0865, body.constant(int(31)));
            body.emit(assign(r08A0, add(r08A1, body.constant(2146435072u)), 0x02));

            body.emit(assign(r08A0, body.constant(0u), 0x01));

            body.emit(assign(r0864, r08A0, 0x03));

            body.emit(assign(r0863, body.constant(false), 0x01));


         body.instructions = f089A_parent_instructions;
         body.emit(f089A);

         /* END IF */


      body.instructions = f087E_parent_instructions;
      body.emit(f087E);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f087C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r08A3 = equal(r0877, body.constant(int(2047)));
      ir_if *f08A2 = new(mem_ctx) ir_if(operand(r08A3).val);
      exec_list *const f08A2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f08A2->then_instructions;

         /* IF CONDITION */
         ir_expression *const r08A5 = bit_or(r0873, swizzle_x(r0862));
         ir_expression *const r08A6 = nequal(r08A5, body.constant(0u));
         ir_if *f08A4 = new(mem_ctx) ir_if(operand(r08A6).val);
         exec_list *const f08A4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08A4->then_instructions;

            ir_variable *const r08A7 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r08A7, swizzle_x(r0861), 0x01));

            ir_variable *const r08A8 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r08A8, swizzle_x(r0862), 0x01));

            ir_variable *const r08A9 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r08AA = body.make_temp(glsl_type::bool_type, "is_nan_retval");
            ir_expression *const r08AB = lshift(swizzle_y(r0862), body.constant(int(1)));
            ir_expression *const r08AC = lequal(body.constant(4292870144u), r08AB);
            ir_expression *const r08AD = nequal(swizzle_x(r0862), body.constant(0u));
            ir_expression *const r08AE = bit_and(swizzle_y(r0862), body.constant(1048575u));
            ir_expression *const r08AF = nequal(r08AE, body.constant(0u));
            ir_expression *const r08B0 = logic_or(r08AD, r08AF);
            body.emit(assign(r08AA, logic_and(r08AC, r08B0), 0x01));

            body.emit(assign(r08A7, bit_or(swizzle_y(r0861), body.constant(524288u)), 0x02));

            body.emit(assign(r08A8, bit_or(swizzle_y(r0862), body.constant(524288u)), 0x02));

            /* IF CONDITION */
            ir_expression *const r08B2 = lshift(swizzle_y(r0861), body.constant(int(1)));
            ir_expression *const r08B3 = lequal(body.constant(4292870144u), r08B2);
            ir_expression *const r08B4 = nequal(swizzle_x(r0861), body.constant(0u));
            ir_expression *const r08B5 = bit_and(swizzle_y(r0861), body.constant(1048575u));
            ir_expression *const r08B6 = nequal(r08B5, body.constant(0u));
            ir_expression *const r08B7 = logic_or(r08B4, r08B6);
            ir_expression *const r08B8 = logic_and(r08B3, r08B7);
            ir_if *f08B1 = new(mem_ctx) ir_if(operand(r08B8).val);
            exec_list *const f08B1_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08B1->then_instructions;

               ir_variable *const r08B9 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
               /* IF CONDITION */
               ir_if *f08BA = new(mem_ctx) ir_if(operand(r08AA).val);
               exec_list *const f08BA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08BA->then_instructions;

                  body.emit(assign(r08B9, r08A8, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08BA->else_instructions;

                  body.emit(assign(r08B9, r08A7, 0x03));


               body.instructions = f08BA_parent_instructions;
               body.emit(f08BA);

               /* END IF */

               body.emit(assign(r08A9, r08B9, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08B1->else_instructions;

               body.emit(assign(r08A9, r08A8, 0x03));


            body.instructions = f08B1_parent_instructions;
            body.emit(f08B1);

            /* END IF */

            body.emit(assign(r0864, r08A9, 0x03));

            body.emit(assign(r0863, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f08A4->else_instructions;

            /* IF CONDITION */
            ir_expression *const r08BC = expr(ir_unop_i2u, r0874);
            ir_expression *const r08BD = bit_or(r08BC, r0871);
            ir_expression *const r08BE = bit_or(r08BD, swizzle_x(r0861));
            ir_expression *const r08BF = equal(r08BE, body.constant(0u));
            ir_if *f08BB = new(mem_ctx) ir_if(operand(r08BF).val);
            exec_list *const f08BB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08BB->then_instructions;

               ir_constant_data r08C0_data;
               memset(&r08C0_data, 0, sizeof(ir_constant_data));
               r08C0_data.u[0] = 4294967295;
               r08C0_data.u[1] = 4294967295;
               ir_constant *const r08C0 = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r08C0_data);
               body.emit(assign(r0864, r08C0, 0x03));

               body.emit(assign(r0863, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08BB->else_instructions;

               ir_variable *const r08C1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r08C1);
               ir_expression *const r08C2 = lshift(r0865, body.constant(int(31)));
               body.emit(assign(r08C1, add(r08C2, body.constant(2146435072u)), 0x02));

               body.emit(assign(r08C1, body.constant(0u), 0x01));

               body.emit(assign(r0864, r08C1, 0x03));

               body.emit(assign(r0863, body.constant(false), 0x01));


            body.instructions = f08BB_parent_instructions;
            body.emit(f08BB);

            /* END IF */


         body.instructions = f08A4_parent_instructions;
         body.emit(f08A4);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f08A2->else_instructions;

         /* IF CONDITION */
         ir_expression *const r08C4 = equal(r0874, body.constant(int(0)));
         ir_if *f08C3 = new(mem_ctx) ir_if(operand(r08C4).val);
         exec_list *const f08C3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08C3->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08C6 = bit_or(r0871, swizzle_x(r0861));
            ir_expression *const r08C7 = equal(r08C6, body.constant(0u));
            ir_if *f08C5 = new(mem_ctx) ir_if(operand(r08C7).val);
            exec_list *const f08C5_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08C5->then_instructions;

               ir_variable *const r08C8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r08C8);
               body.emit(assign(r08C8, lshift(r0865, body.constant(int(31))), 0x02));

               body.emit(assign(r08C8, body.constant(0u), 0x01));

               body.emit(assign(r0864, r08C8, 0x03));

               body.emit(assign(r0863, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f08C5->else_instructions;

               ir_variable *const r08C9 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r08C9, r0874, 0x01));

               ir_variable *const r08CA = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r08CA, r0871, 0x01));

               ir_variable *const r08CB = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r08CB, r0870, 0x01));

               ir_variable *const r08CC = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r08CC);
               /* IF CONDITION */
               ir_expression *const r08CE = equal(r0871, body.constant(0u));
               ir_if *f08CD = new(mem_ctx) ir_if(operand(r08CE).val);
               exec_list *const f08CD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08CD->then_instructions;

                  ir_variable *const r08CF = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r08CF, r0870, 0x01));

                  ir_variable *const r08D0 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r08D1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08D1);
                  /* IF CONDITION */
                  ir_expression *const r08D3 = equal(swizzle_x(r0861), body.constant(0u));
                  ir_if *f08D2 = new(mem_ctx) ir_if(operand(r08D3).val);
                  exec_list *const f08D2_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08D2->then_instructions;

                     body.emit(assign(r08D0, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08D2->else_instructions;

                     body.emit(assign(r08D1, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08D5 = bit_and(swizzle_x(r0861), body.constant(4294901760u));
                     ir_expression *const r08D6 = equal(r08D5, body.constant(0u));
                     ir_if *f08D4 = new(mem_ctx) ir_if(operand(r08D6).val);
                     exec_list *const f08D4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08D4->then_instructions;

                        body.emit(assign(r08D1, body.constant(int(16)), 0x01));

                        body.emit(assign(r08CF, lshift(swizzle_x(r0861), body.constant(int(16))), 0x01));


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

                  body.emit(assign(r08CC, add(r08D0, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r08E4 = less(r08CC, body.constant(int(0)));
                  ir_if *f08E3 = new(mem_ctx) ir_if(operand(r08E4).val);
                  exec_list *const f08E3_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08E3->then_instructions;

                     ir_expression *const r08E5 = neg(r08CC);
                     body.emit(assign(r08CA, rshift(swizzle_x(r0861), r08E5), 0x01));

                     ir_expression *const r08E6 = bit_and(r08CC, body.constant(int(31)));
                     body.emit(assign(r08CB, lshift(swizzle_x(r0861), r08E6), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08E3->else_instructions;

                     body.emit(assign(r08CA, lshift(swizzle_x(r0861), r08CC), 0x01));

                     body.emit(assign(r08CB, body.constant(0u), 0x01));


                  body.instructions = f08E3_parent_instructions;
                  body.emit(f08E3);

                  /* END IF */

                  body.emit(assign(r08C9, sub(body.constant(int(-31)), r08CC), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08CD->else_instructions;

                  ir_variable *const r08E7 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r08E7, r0871, 0x01));

                  ir_variable *const r08E8 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r08E9 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08E9);
                  /* IF CONDITION */
                  ir_expression *const r08EB = equal(r0871, body.constant(0u));
                  ir_if *f08EA = new(mem_ctx) ir_if(operand(r08EB).val);
                  exec_list *const f08EA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08EA->then_instructions;

                     body.emit(assign(r08E8, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08EA->else_instructions;

                     body.emit(assign(r08E9, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08ED = bit_and(r0871, body.constant(4294901760u));
                     ir_expression *const r08EE = equal(r08ED, body.constant(0u));
                     ir_if *f08EC = new(mem_ctx) ir_if(operand(r08EE).val);
                     exec_list *const f08EC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08EC->then_instructions;

                        body.emit(assign(r08E9, body.constant(int(16)), 0x01));

                        body.emit(assign(r08E7, lshift(r0871, body.constant(int(16))), 0x01));


                     body.instructions = f08EC_parent_instructions;
                     body.emit(f08EC);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08F0 = bit_and(r08E7, body.constant(4278190080u));
                     ir_expression *const r08F1 = equal(r08F0, body.constant(0u));
                     ir_if *f08EF = new(mem_ctx) ir_if(operand(r08F1).val);
                     exec_list *const f08EF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08EF->then_instructions;

                        body.emit(assign(r08E9, add(r08E9, body.constant(int(8))), 0x01));

                        body.emit(assign(r08E7, lshift(r08E7, body.constant(int(8))), 0x01));


                     body.instructions = f08EF_parent_instructions;
                     body.emit(f08EF);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08F3 = bit_and(r08E7, body.constant(4026531840u));
                     ir_expression *const r08F4 = equal(r08F3, body.constant(0u));
                     ir_if *f08F2 = new(mem_ctx) ir_if(operand(r08F4).val);
                     exec_list *const f08F2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F2->then_instructions;

                        body.emit(assign(r08E9, add(r08E9, body.constant(int(4))), 0x01));

                        body.emit(assign(r08E7, lshift(r08E7, body.constant(int(4))), 0x01));


                     body.instructions = f08F2_parent_instructions;
                     body.emit(f08F2);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08F6 = bit_and(r08E7, body.constant(3221225472u));
                     ir_expression *const r08F7 = equal(r08F6, body.constant(0u));
                     ir_if *f08F5 = new(mem_ctx) ir_if(operand(r08F7).val);
                     exec_list *const f08F5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F5->then_instructions;

                        body.emit(assign(r08E9, add(r08E9, body.constant(int(2))), 0x01));

                        body.emit(assign(r08E7, lshift(r08E7, body.constant(int(2))), 0x01));


                     body.instructions = f08F5_parent_instructions;
                     body.emit(f08F5);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08F9 = bit_and(r08E7, body.constant(2147483648u));
                     ir_expression *const r08FA = equal(r08F9, body.constant(0u));
                     ir_if *f08F8 = new(mem_ctx) ir_if(operand(r08FA).val);
                     exec_list *const f08F8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F8->then_instructions;

                        body.emit(assign(r08E9, add(r08E9, body.constant(int(1))), 0x01));


                     body.instructions = f08F8_parent_instructions;
                     body.emit(f08F8);

                     /* END IF */

                     body.emit(assign(r08E8, r08E9, 0x01));


                  body.instructions = f08EA_parent_instructions;
                  body.emit(f08EA);

                  /* END IF */

                  body.emit(assign(r08CC, add(r08E8, body.constant(int(-11))), 0x01));

                  ir_variable *const r08FB = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r08FB, lshift(swizzle_x(r0861), r08CC), 0x01));

                  ir_variable *const r08FC = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r08FE = equal(r08CC, body.constant(int(0)));
                  ir_if *f08FD = new(mem_ctx) ir_if(operand(r08FE).val);
                  exec_list *const f08FD_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08FD->then_instructions;

                     body.emit(assign(r08FC, r0871, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08FD->else_instructions;

                     ir_expression *const r08FF = lshift(r0871, r08CC);
                     ir_expression *const r0900 = neg(r08CC);
                     ir_expression *const r0901 = bit_and(r0900, body.constant(int(31)));
                     ir_expression *const r0902 = rshift(swizzle_x(r0861), r0901);
                     body.emit(assign(r08FC, bit_or(r08FF, r0902), 0x01));


                  body.instructions = f08FD_parent_instructions;
                  body.emit(f08FD);

                  /* END IF */

                  body.emit(assign(r08CA, r08FC, 0x01));

                  body.emit(assign(r08CB, r08FB, 0x01));

                  body.emit(assign(r08C9, sub(body.constant(int(1)), r08CC), 0x01));


               body.instructions = f08CD_parent_instructions;
               body.emit(f08CD);

               /* END IF */

               body.emit(assign(r0867, r08C9, 0x01));

               body.emit(assign(r086A, r08CA, 0x01));

               body.emit(assign(r086B, r08CB, 0x01));


            body.instructions = f08C5_parent_instructions;
            body.emit(f08C5);

            /* END IF */


         body.instructions = f08C3_parent_instructions;
         body.emit(f08C3);

         /* END IF */

         /* IF CONDITION */
         ir_if *f0903 = new(mem_ctx) ir_if(operand(r0863).val);
         exec_list *const f0903_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0903->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0905 = equal(r0877, body.constant(int(0)));
            ir_if *f0904 = new(mem_ctx) ir_if(operand(r0905).val);
            exec_list *const f0904_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0904->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0907 = bit_or(r0873, swizzle_x(r0862));
               ir_expression *const r0908 = equal(r0907, body.constant(0u));
               ir_if *f0906 = new(mem_ctx) ir_if(operand(r0908).val);
               exec_list *const f0906_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0906->then_instructions;

                  ir_variable *const r0909 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0909);
                  body.emit(assign(r0909, lshift(r0865, body.constant(int(31))), 0x02));

                  body.emit(assign(r0909, body.constant(0u), 0x01));

                  body.emit(assign(r0864, r0909, 0x03));

                  body.emit(assign(r0863, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0906->else_instructions;

                  ir_variable *const r090A = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r090A, r0877, 0x01));

                  ir_variable *const r090B = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r090B, r0873, 0x01));

                  ir_variable *const r090C = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r090C, r0872, 0x01));

                  ir_variable *const r090D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r090D);
                  /* IF CONDITION */
                  ir_expression *const r090F = equal(r0873, body.constant(0u));
                  ir_if *f090E = new(mem_ctx) ir_if(operand(r090F).val);
                  exec_list *const f090E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f090E->then_instructions;

                     ir_variable *const r0910 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r0910, r0872, 0x01));

                     ir_variable *const r0911 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r0912 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0912);
                     /* IF CONDITION */
                     ir_expression *const r0914 = equal(swizzle_x(r0862), body.constant(0u));
                     ir_if *f0913 = new(mem_ctx) ir_if(operand(r0914).val);
                     exec_list *const f0913_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0913->then_instructions;

                        body.emit(assign(r0911, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0913->else_instructions;

                        body.emit(assign(r0912, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0916 = bit_and(swizzle_x(r0862), body.constant(4294901760u));
                        ir_expression *const r0917 = equal(r0916, body.constant(0u));
                        ir_if *f0915 = new(mem_ctx) ir_if(operand(r0917).val);
                        exec_list *const f0915_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0915->then_instructions;

                           body.emit(assign(r0912, body.constant(int(16)), 0x01));

                           body.emit(assign(r0910, lshift(swizzle_x(r0862), body.constant(int(16))), 0x01));


                        body.instructions = f0915_parent_instructions;
                        body.emit(f0915);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0919 = bit_and(r0910, body.constant(4278190080u));
                        ir_expression *const r091A = equal(r0919, body.constant(0u));
                        ir_if *f0918 = new(mem_ctx) ir_if(operand(r091A).val);
                        exec_list *const f0918_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0918->then_instructions;

                           body.emit(assign(r0912, add(r0912, body.constant(int(8))), 0x01));

                           body.emit(assign(r0910, lshift(r0910, body.constant(int(8))), 0x01));


                        body.instructions = f0918_parent_instructions;
                        body.emit(f0918);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r091C = bit_and(r0910, body.constant(4026531840u));
                        ir_expression *const r091D = equal(r091C, body.constant(0u));
                        ir_if *f091B = new(mem_ctx) ir_if(operand(r091D).val);
                        exec_list *const f091B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f091B->then_instructions;

                           body.emit(assign(r0912, add(r0912, body.constant(int(4))), 0x01));

                           body.emit(assign(r0910, lshift(r0910, body.constant(int(4))), 0x01));


                        body.instructions = f091B_parent_instructions;
                        body.emit(f091B);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r091F = bit_and(r0910, body.constant(3221225472u));
                        ir_expression *const r0920 = equal(r091F, body.constant(0u));
                        ir_if *f091E = new(mem_ctx) ir_if(operand(r0920).val);
                        exec_list *const f091E_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f091E->then_instructions;

                           body.emit(assign(r0912, add(r0912, body.constant(int(2))), 0x01));

                           body.emit(assign(r0910, lshift(r0910, body.constant(int(2))), 0x01));


                        body.instructions = f091E_parent_instructions;
                        body.emit(f091E);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0922 = bit_and(r0910, body.constant(2147483648u));
                        ir_expression *const r0923 = equal(r0922, body.constant(0u));
                        ir_if *f0921 = new(mem_ctx) ir_if(operand(r0923).val);
                        exec_list *const f0921_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0921->then_instructions;

                           body.emit(assign(r0912, add(r0912, body.constant(int(1))), 0x01));


                        body.instructions = f0921_parent_instructions;
                        body.emit(f0921);

                        /* END IF */

                        body.emit(assign(r0911, r0912, 0x01));


                     body.instructions = f0913_parent_instructions;
                     body.emit(f0913);

                     /* END IF */

                     body.emit(assign(r090D, add(r0911, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0925 = less(r090D, body.constant(int(0)));
                     ir_if *f0924 = new(mem_ctx) ir_if(operand(r0925).val);
                     exec_list *const f0924_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0924->then_instructions;

                        ir_expression *const r0926 = neg(r090D);
                        body.emit(assign(r090B, rshift(swizzle_x(r0862), r0926), 0x01));

                        ir_expression *const r0927 = bit_and(r090D, body.constant(int(31)));
                        body.emit(assign(r090C, lshift(swizzle_x(r0862), r0927), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0924->else_instructions;

                        body.emit(assign(r090B, lshift(swizzle_x(r0862), r090D), 0x01));

                        body.emit(assign(r090C, body.constant(0u), 0x01));


                     body.instructions = f0924_parent_instructions;
                     body.emit(f0924);

                     /* END IF */

                     body.emit(assign(r090A, sub(body.constant(int(-31)), r090D), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f090E->else_instructions;

                     ir_variable *const r0928 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r0928, r0873, 0x01));

                     ir_variable *const r0929 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r092A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r092A);
                     /* IF CONDITION */
                     ir_expression *const r092C = equal(r0873, body.constant(0u));
                     ir_if *f092B = new(mem_ctx) ir_if(operand(r092C).val);
                     exec_list *const f092B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f092B->then_instructions;

                        body.emit(assign(r0929, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f092B->else_instructions;

                        body.emit(assign(r092A, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r092E = bit_and(r0873, body.constant(4294901760u));
                        ir_expression *const r092F = equal(r092E, body.constant(0u));
                        ir_if *f092D = new(mem_ctx) ir_if(operand(r092F).val);
                        exec_list *const f092D_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f092D->then_instructions;

                           body.emit(assign(r092A, body.constant(int(16)), 0x01));

                           body.emit(assign(r0928, lshift(r0873, body.constant(int(16))), 0x01));


                        body.instructions = f092D_parent_instructions;
                        body.emit(f092D);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0931 = bit_and(r0928, body.constant(4278190080u));
                        ir_expression *const r0932 = equal(r0931, body.constant(0u));
                        ir_if *f0930 = new(mem_ctx) ir_if(operand(r0932).val);
                        exec_list *const f0930_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0930->then_instructions;

                           body.emit(assign(r092A, add(r092A, body.constant(int(8))), 0x01));

                           body.emit(assign(r0928, lshift(r0928, body.constant(int(8))), 0x01));


                        body.instructions = f0930_parent_instructions;
                        body.emit(f0930);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0934 = bit_and(r0928, body.constant(4026531840u));
                        ir_expression *const r0935 = equal(r0934, body.constant(0u));
                        ir_if *f0933 = new(mem_ctx) ir_if(operand(r0935).val);
                        exec_list *const f0933_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0933->then_instructions;

                           body.emit(assign(r092A, add(r092A, body.constant(int(4))), 0x01));

                           body.emit(assign(r0928, lshift(r0928, body.constant(int(4))), 0x01));


                        body.instructions = f0933_parent_instructions;
                        body.emit(f0933);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0937 = bit_and(r0928, body.constant(3221225472u));
                        ir_expression *const r0938 = equal(r0937, body.constant(0u));
                        ir_if *f0936 = new(mem_ctx) ir_if(operand(r0938).val);
                        exec_list *const f0936_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0936->then_instructions;

                           body.emit(assign(r092A, add(r092A, body.constant(int(2))), 0x01));

                           body.emit(assign(r0928, lshift(r0928, body.constant(int(2))), 0x01));


                        body.instructions = f0936_parent_instructions;
                        body.emit(f0936);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r093A = bit_and(r0928, body.constant(2147483648u));
                        ir_expression *const r093B = equal(r093A, body.constant(0u));
                        ir_if *f0939 = new(mem_ctx) ir_if(operand(r093B).val);
                        exec_list *const f0939_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0939->then_instructions;

                           body.emit(assign(r092A, add(r092A, body.constant(int(1))), 0x01));


                        body.instructions = f0939_parent_instructions;
                        body.emit(f0939);

                        /* END IF */

                        body.emit(assign(r0929, r092A, 0x01));


                     body.instructions = f092B_parent_instructions;
                     body.emit(f092B);

                     /* END IF */

                     body.emit(assign(r090D, add(r0929, body.constant(int(-11))), 0x01));

                     ir_variable *const r093C = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r093C, lshift(swizzle_x(r0862), r090D), 0x01));

                     ir_variable *const r093D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r093F = equal(r090D, body.constant(int(0)));
                     ir_if *f093E = new(mem_ctx) ir_if(operand(r093F).val);
                     exec_list *const f093E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f093E->then_instructions;

                        body.emit(assign(r093D, r0873, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f093E->else_instructions;

                        ir_expression *const r0940 = lshift(r0873, r090D);
                        ir_expression *const r0941 = neg(r090D);
                        ir_expression *const r0942 = bit_and(r0941, body.constant(int(31)));
                        ir_expression *const r0943 = rshift(swizzle_x(r0862), r0942);
                        body.emit(assign(r093D, bit_or(r0940, r0943), 0x01));


                     body.instructions = f093E_parent_instructions;
                     body.emit(f093E);

                     /* END IF */

                     body.emit(assign(r090B, r093D, 0x01));

                     body.emit(assign(r090C, r093C, 0x01));

                     body.emit(assign(r090A, sub(body.constant(int(1)), r090D), 0x01));


                  body.instructions = f090E_parent_instructions;
                  body.emit(f090E);

                  /* END IF */

                  body.emit(assign(r0866, r090A, 0x01));

                  body.emit(assign(r0868, r090B, 0x01));

                  body.emit(assign(r0869, r090C, 0x01));


               body.instructions = f0906_parent_instructions;
               body.emit(f0906);

               /* END IF */


            body.instructions = f0904_parent_instructions;
            body.emit(f0904);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0944 = new(mem_ctx) ir_if(operand(r0863).val);
            exec_list *const f0944_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0944->then_instructions;

               ir_expression *const r0945 = add(r0867, r0866);
               body.emit(assign(r086C, add(r0945, body.constant(int(-1024))), 0x01));

               body.emit(assign(r086A, bit_or(r086A, body.constant(1048576u)), 0x01));

               ir_variable *const r0946 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0946, lshift(r0869, body.constant(int(12))), 0x01));

               ir_variable *const r0947 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               ir_expression *const r0948 = lshift(r0868, body.constant(int(12)));
               ir_expression *const r0949 = rshift(r0869, body.constant(int(20)));
               body.emit(assign(r0947, bit_or(r0948, r0949), 0x01));

               body.emit(assign(r0868, r0947, 0x01));

               body.emit(assign(r0869, r0946, 0x01));

               ir_variable *const r094A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r094A);
               ir_variable *const r094B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r094B);
               ir_variable *const r094C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r094C);
               ir_variable *const r094D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r094D, bit_and(r086B, body.constant(65535u)), 0x01));

               ir_variable *const r094E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r094E, rshift(r086B, body.constant(int(16))), 0x01));

               ir_variable *const r094F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r094F, bit_and(r0946, body.constant(65535u)), 0x01));

               ir_variable *const r0950 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0950, rshift(r0946, body.constant(int(16))), 0x01));

               ir_variable *const r0951 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0951, mul(r094E, r094F), 0x01));

               ir_expression *const r0952 = mul(r094D, r0950);
               body.emit(assign(r094B, add(r0952, r0951), 0x01));

               ir_expression *const r0953 = mul(r094E, r0950);
               ir_expression *const r0954 = less(r094B, r0951);
               ir_expression *const r0955 = expr(ir_unop_b2i, r0954);
               ir_expression *const r0956 = expr(ir_unop_i2u, r0955);
               ir_expression *const r0957 = lshift(r0956, body.constant(int(16)));
               ir_expression *const r0958 = rshift(r094B, body.constant(int(16)));
               ir_expression *const r0959 = add(r0957, r0958);
               body.emit(assign(r094A, add(r0953, r0959), 0x01));

               body.emit(assign(r094B, lshift(r094B, body.constant(int(16))), 0x01));

               ir_expression *const r095A = mul(r094D, r094F);
               body.emit(assign(r094C, add(r095A, r094B), 0x01));

               ir_expression *const r095B = less(r094C, r094B);
               ir_expression *const r095C = expr(ir_unop_b2i, r095B);
               ir_expression *const r095D = expr(ir_unop_i2u, r095C);
               body.emit(assign(r094A, add(r094A, r095D), 0x01));

               ir_variable *const r095E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r095E);
               ir_variable *const r095F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r095F);
               ir_variable *const r0960 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0960);
               ir_variable *const r0961 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0961, bit_and(r086B, body.constant(65535u)), 0x01));

               ir_variable *const r0962 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0962, rshift(r086B, body.constant(int(16))), 0x01));

               ir_variable *const r0963 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0963, bit_and(r0947, body.constant(65535u)), 0x01));

               ir_variable *const r0964 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0964, rshift(r0947, body.constant(int(16))), 0x01));

               ir_variable *const r0965 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0965, mul(r0962, r0963), 0x01));

               ir_expression *const r0966 = mul(r0961, r0964);
               body.emit(assign(r095F, add(r0966, r0965), 0x01));

               ir_expression *const r0967 = mul(r0962, r0964);
               ir_expression *const r0968 = less(r095F, r0965);
               ir_expression *const r0969 = expr(ir_unop_b2i, r0968);
               ir_expression *const r096A = expr(ir_unop_i2u, r0969);
               ir_expression *const r096B = lshift(r096A, body.constant(int(16)));
               ir_expression *const r096C = rshift(r095F, body.constant(int(16)));
               ir_expression *const r096D = add(r096B, r096C);
               body.emit(assign(r095E, add(r0967, r096D), 0x01));

               body.emit(assign(r095F, lshift(r095F, body.constant(int(16))), 0x01));

               ir_expression *const r096E = mul(r0961, r0963);
               body.emit(assign(r0960, add(r096E, r095F), 0x01));

               ir_expression *const r096F = less(r0960, r095F);
               ir_expression *const r0970 = expr(ir_unop_b2i, r096F);
               ir_expression *const r0971 = expr(ir_unop_i2u, r0970);
               body.emit(assign(r095E, add(r095E, r0971), 0x01));

               ir_variable *const r0972 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0972, add(r0960, r094A), 0x01));

               ir_variable *const r0973 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0973);
               ir_variable *const r0974 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0974);
               ir_variable *const r0975 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0975);
               ir_variable *const r0976 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0976, bit_and(r086A, body.constant(65535u)), 0x01));

               ir_variable *const r0977 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0977, rshift(r086A, body.constant(int(16))), 0x01));

               ir_variable *const r0978 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0978, bit_and(r0947, body.constant(65535u)), 0x01));

               ir_variable *const r0979 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0979, rshift(r0947, body.constant(int(16))), 0x01));

               ir_variable *const r097A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r097A, mul(r0977, r0978), 0x01));

               ir_expression *const r097B = mul(r0976, r0979);
               body.emit(assign(r0974, add(r097B, r097A), 0x01));

               ir_expression *const r097C = mul(r0977, r0979);
               ir_expression *const r097D = less(r0974, r097A);
               ir_expression *const r097E = expr(ir_unop_b2i, r097D);
               ir_expression *const r097F = expr(ir_unop_i2u, r097E);
               ir_expression *const r0980 = lshift(r097F, body.constant(int(16)));
               ir_expression *const r0981 = rshift(r0974, body.constant(int(16)));
               ir_expression *const r0982 = add(r0980, r0981);
               body.emit(assign(r0973, add(r097C, r0982), 0x01));

               body.emit(assign(r0974, lshift(r0974, body.constant(int(16))), 0x01));

               ir_expression *const r0983 = mul(r0976, r0978);
               body.emit(assign(r0975, add(r0983, r0974), 0x01));

               ir_expression *const r0984 = less(r0975, r0974);
               ir_expression *const r0985 = expr(ir_unop_b2i, r0984);
               ir_expression *const r0986 = expr(ir_unop_i2u, r0985);
               body.emit(assign(r0973, add(r0973, r0986), 0x01));

               ir_variable *const r0987 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0988 = less(r0972, r0960);
               ir_expression *const r0989 = expr(ir_unop_b2i, r0988);
               ir_expression *const r098A = expr(ir_unop_i2u, r0989);
               ir_expression *const r098B = add(r095E, r098A);
               body.emit(assign(r0987, add(r0975, r098B), 0x01));

               ir_variable *const r098C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r098C);
               ir_variable *const r098D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r098D);
               ir_variable *const r098E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r098E);
               ir_variable *const r098F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r098F, bit_and(r086A, body.constant(65535u)), 0x01));

               ir_variable *const r0990 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0990, rshift(r086A, body.constant(int(16))), 0x01));

               ir_variable *const r0991 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0991, bit_and(r0946, body.constant(65535u)), 0x01));

               ir_variable *const r0992 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0992, rshift(r0946, body.constant(int(16))), 0x01));

               ir_variable *const r0993 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0993, mul(r0990, r0991), 0x01));

               ir_expression *const r0994 = mul(r098F, r0992);
               body.emit(assign(r098D, add(r0994, r0993), 0x01));

               ir_expression *const r0995 = mul(r0990, r0992);
               ir_expression *const r0996 = less(r098D, r0993);
               ir_expression *const r0997 = expr(ir_unop_b2i, r0996);
               ir_expression *const r0998 = expr(ir_unop_i2u, r0997);
               ir_expression *const r0999 = lshift(r0998, body.constant(int(16)));
               ir_expression *const r099A = rshift(r098D, body.constant(int(16)));
               ir_expression *const r099B = add(r0999, r099A);
               body.emit(assign(r098C, add(r0995, r099B), 0x01));

               body.emit(assign(r098D, lshift(r098D, body.constant(int(16))), 0x01));

               ir_expression *const r099C = mul(r098F, r0991);
               body.emit(assign(r098E, add(r099C, r098D), 0x01));

               ir_expression *const r099D = less(r098E, r098D);
               ir_expression *const r099E = expr(ir_unop_b2i, r099D);
               ir_expression *const r099F = expr(ir_unop_i2u, r099E);
               body.emit(assign(r098C, add(r098C, r099F), 0x01));

               ir_variable *const r09A0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09A0, add(r098E, r0972), 0x01));

               ir_variable *const r09A1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r09A2 = less(r09A0, r098E);
               ir_expression *const r09A3 = expr(ir_unop_b2i, r09A2);
               ir_expression *const r09A4 = expr(ir_unop_i2u, r09A3);
               ir_expression *const r09A5 = add(r098C, r09A4);
               body.emit(assign(r09A1, add(r0987, r09A5), 0x01));

               ir_variable *const r09A6 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r09A7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r09A7, add(r09A1, r086B), 0x01));

               ir_expression *const r09A8 = less(r0987, r0975);
               ir_expression *const r09A9 = expr(ir_unop_b2i, r09A8);
               ir_expression *const r09AA = expr(ir_unop_i2u, r09A9);
               ir_expression *const r09AB = add(r0973, r09AA);
               ir_expression *const r09AC = less(r09A1, r0987);
               ir_expression *const r09AD = expr(ir_unop_b2i, r09AC);
               ir_expression *const r09AE = expr(ir_unop_i2u, r09AD);
               ir_expression *const r09AF = add(r09AB, r09AE);
               ir_expression *const r09B0 = add(r09AF, r086A);
               ir_expression *const r09B1 = less(r09A7, r09A1);
               ir_expression *const r09B2 = expr(ir_unop_b2i, r09B1);
               ir_expression *const r09B3 = expr(ir_unop_i2u, r09B2);
               body.emit(assign(r09A6, add(r09B0, r09B3), 0x01));

               body.emit(assign(r086F, r09A6, 0x01));

               body.emit(assign(r086E, r09A7, 0x01));

               ir_expression *const r09B4 = nequal(r094C, body.constant(0u));
               ir_expression *const r09B5 = expr(ir_unop_b2i, r09B4);
               ir_expression *const r09B6 = expr(ir_unop_i2u, r09B5);
               body.emit(assign(r086D, bit_or(r09A0, r09B6), 0x01));

               /* IF CONDITION */
               ir_expression *const r09B8 = lequal(body.constant(2097152u), r09A6);
               ir_if *f09B7 = new(mem_ctx) ir_if(operand(r09B8).val);
               exec_list *const f09B7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09B7->then_instructions;

                  ir_variable *const r09B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r09B9);
                  body.emit(assign(r09B9, lshift(r09A7, body.constant(int(31))), 0x01));

                  ir_expression *const r09BA = nequal(r086D, body.constant(0u));
                  ir_expression *const r09BB = expr(ir_unop_b2i, r09BA);
                  ir_expression *const r09BC = expr(ir_unop_i2u, r09BB);
                  body.emit(assign(r09B9, bit_or(r09B9, r09BC), 0x01));

                  body.emit(assign(r086F, rshift(r09A6, body.constant(int(1))), 0x01));

                  ir_expression *const r09BD = lshift(r09A6, body.constant(int(31)));
                  ir_expression *const r09BE = rshift(r09A7, body.constant(int(1)));
                  body.emit(assign(r086E, bit_or(r09BD, r09BE), 0x01));

                  body.emit(assign(r086D, r09B9, 0x01));

                  body.emit(assign(r086C, add(r086C, body.constant(int(1))), 0x01));


               body.instructions = f09B7_parent_instructions;
               body.emit(f09B7);

               /* END IF */

               ir_variable *const r09BF = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r09BF, r086C, 0x01));

               ir_variable *const r09C0 = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r09C0, r086F, 0x01));

               ir_variable *const r09C1 = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r09C1, r086E, 0x01));

               ir_variable *const r09C2 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r09C2, r086D, 0x01));

               ir_variable *const r09C3 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r09C3, body.constant(true), 0x01));

               ir_variable *const r09C4 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r09C5 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r09C5);
               ir_expression *const r09C6 = expr(ir_unop_u2i, r086D);
               body.emit(assign(r09C5, less(r09C6, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r09C8 = lequal(body.constant(int(2045)), r086C);
               ir_if *f09C7 = new(mem_ctx) ir_if(operand(r09C8).val);
               exec_list *const f09C7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09C7->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r09CA = less(body.constant(int(2045)), r086C);
                  ir_expression *const r09CB = equal(r086C, body.constant(int(2045)));
                  ir_expression *const r09CC = equal(body.constant(2097151u), r086F);
                  ir_expression *const r09CD = equal(body.constant(4294967295u), r086E);
                  ir_expression *const r09CE = logic_and(r09CC, r09CD);
                  ir_expression *const r09CF = logic_and(r09CB, r09CE);
                  ir_expression *const r09D0 = logic_and(r09CF, r09C5);
                  ir_expression *const r09D1 = logic_or(r09CA, r09D0);
                  ir_if *f09C9 = new(mem_ctx) ir_if(operand(r09D1).val);
                  exec_list *const f09C9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09C9->then_instructions;

                     ir_variable *const r09D2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r09D2);
                     ir_expression *const r09D3 = lshift(r0865, body.constant(int(31)));
                     body.emit(assign(r09D2, add(r09D3, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r09D2, body.constant(0u), 0x01));

                     body.emit(assign(r09C4, r09D2, 0x03));

                     body.emit(assign(r09C3, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09C9->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09D5 = less(r086C, body.constant(int(0)));
                     ir_if *f09D4 = new(mem_ctx) ir_if(operand(r09D5).val);
                     exec_list *const f09D4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09D4->then_instructions;

                        ir_variable *const r09D6 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r09D6, r086D, 0x01));

                        ir_variable *const r09D7 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r09D7, neg(r086C), 0x01));

                        ir_variable *const r09D8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r09D8);
                        ir_variable *const r09D9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r09D9);
                        ir_variable *const r09DA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r09DA);
                        ir_variable *const r09DB = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r09DC = neg(r09D7);
                        body.emit(assign(r09DB, bit_and(r09DC, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r09DE = equal(r09D7, body.constant(int(0)));
                        ir_if *f09DD = new(mem_ctx) ir_if(operand(r09DE).val);
                        exec_list *const f09DD_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f09DD->then_instructions;

                           body.emit(assign(r09D8, r086D, 0x01));

                           body.emit(assign(r09D9, r086E, 0x01));

                           body.emit(assign(r09DA, r086F, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f09DD->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r09E0 = less(r09D7, body.constant(int(32)));
                           ir_if *f09DF = new(mem_ctx) ir_if(operand(r09E0).val);
                           exec_list *const f09DF_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f09DF->then_instructions;

                              body.emit(assign(r09D8, lshift(r086E, r09DB), 0x01));

                              ir_expression *const r09E1 = lshift(r086F, r09DB);
                              ir_expression *const r09E2 = rshift(r086E, r09D7);
                              body.emit(assign(r09D9, bit_or(r09E1, r09E2), 0x01));

                              body.emit(assign(r09DA, rshift(r086F, r09D7), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f09DF->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r09E4 = equal(r09D7, body.constant(int(32)));
                              ir_if *f09E3 = new(mem_ctx) ir_if(operand(r09E4).val);
                              exec_list *const f09E3_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f09E3->then_instructions;

                                 body.emit(assign(r09D8, r086E, 0x01));

                                 body.emit(assign(r09D9, r086F, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f09E3->else_instructions;

                                 body.emit(assign(r09D6, bit_or(r086D, r086E), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r09E6 = less(r09D7, body.constant(int(64)));
                                 ir_if *f09E5 = new(mem_ctx) ir_if(operand(r09E6).val);
                                 exec_list *const f09E5_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f09E5->then_instructions;

                                    body.emit(assign(r09D8, lshift(r086F, r09DB), 0x01));

                                    ir_expression *const r09E7 = bit_and(r09D7, body.constant(int(31)));
                                    body.emit(assign(r09D9, rshift(r086F, r09E7), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f09E5->else_instructions;

                                    ir_variable *const r09E8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r09EA = equal(r09D7, body.constant(int(64)));
                                    ir_if *f09E9 = new(mem_ctx) ir_if(operand(r09EA).val);
                                    exec_list *const f09E9_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f09E9->then_instructions;

                                       body.emit(assign(r09E8, r086F, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f09E9->else_instructions;

                                       ir_expression *const r09EB = nequal(r086F, body.constant(0u));
                                       ir_expression *const r09EC = expr(ir_unop_b2i, r09EB);
                                       body.emit(assign(r09E8, expr(ir_unop_i2u, r09EC), 0x01));


                                    body.instructions = f09E9_parent_instructions;
                                    body.emit(f09E9);

                                    /* END IF */

                                    body.emit(assign(r09D8, r09E8, 0x01));

                                    body.emit(assign(r09D9, body.constant(0u), 0x01));


                                 body.instructions = f09E5_parent_instructions;
                                 body.emit(f09E5);

                                 /* END IF */


                              body.instructions = f09E3_parent_instructions;
                              body.emit(f09E3);

                              /* END IF */

                              body.emit(assign(r09DA, body.constant(0u), 0x01));


                           body.instructions = f09DF_parent_instructions;
                           body.emit(f09DF);

                           /* END IF */

                           ir_expression *const r09ED = nequal(r09D6, body.constant(0u));
                           ir_expression *const r09EE = expr(ir_unop_b2i, r09ED);
                           ir_expression *const r09EF = expr(ir_unop_i2u, r09EE);
                           body.emit(assign(r09D8, bit_or(r09D8, r09EF), 0x01));


                        body.instructions = f09DD_parent_instructions;
                        body.emit(f09DD);

                        /* END IF */

                        body.emit(assign(r09C0, r09DA, 0x01));

                        body.emit(assign(r09C1, r09D9, 0x01));

                        body.emit(assign(r09C2, r09D8, 0x01));

                        body.emit(assign(r09BF, body.constant(int(0)), 0x01));

                        body.emit(assign(r09C5, less(r09D8, body.constant(0u)), 0x01));


                     body.instructions = f09D4_parent_instructions;
                     body.emit(f09D4);

                     /* END IF */


                  body.instructions = f09C9_parent_instructions;
                  body.emit(f09C9);

                  /* END IF */


               body.instructions = f09C7_parent_instructions;
               body.emit(f09C7);

               /* END IF */

               /* IF CONDITION */
               ir_if *f09F0 = new(mem_ctx) ir_if(operand(r09C3).val);
               exec_list *const f09F0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09F0->then_instructions;

                  /* IF CONDITION */
                  ir_if *f09F1 = new(mem_ctx) ir_if(operand(r09C5).val);
                  exec_list *const f09F1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09F1->then_instructions;

                     ir_variable *const r09F2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r09F2, add(r09C1, body.constant(1u)), 0x01));

                     ir_expression *const r09F3 = less(r09F2, r09C1);
                     ir_expression *const r09F4 = expr(ir_unop_b2i, r09F3);
                     ir_expression *const r09F5 = expr(ir_unop_i2u, r09F4);
                     body.emit(assign(r09C0, add(r09C0, r09F5), 0x01));

                     ir_expression *const r09F6 = equal(r09C2, body.constant(0u));
                     ir_expression *const r09F7 = expr(ir_unop_b2i, r09F6);
                     ir_expression *const r09F8 = expr(ir_unop_i2u, r09F7);
                     ir_expression *const r09F9 = add(r09C2, r09F8);
                     ir_expression *const r09FA = bit_and(r09F9, body.constant(1u));
                     ir_expression *const r09FB = expr(ir_unop_bit_not, r09FA);
                     body.emit(assign(r09C1, bit_and(r09F2, r09FB), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09F1->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09FD = bit_or(r09C0, r09C1);
                     ir_expression *const r09FE = equal(r09FD, body.constant(0u));
                     ir_if *f09FC = new(mem_ctx) ir_if(operand(r09FE).val);
                     exec_list *const f09FC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09FC->then_instructions;

                        body.emit(assign(r09BF, body.constant(int(0)), 0x01));


                     body.instructions = f09FC_parent_instructions;
                     body.emit(f09FC);

                     /* END IF */


                  body.instructions = f09F1_parent_instructions;
                  body.emit(f09F1);

                  /* END IF */

                  ir_variable *const r09FF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r09FF);
                  ir_expression *const r0A00 = lshift(r0865, body.constant(int(31)));
                  ir_expression *const r0A01 = expr(ir_unop_i2u, r09BF);
                  ir_expression *const r0A02 = lshift(r0A01, body.constant(int(20)));
                  ir_expression *const r0A03 = add(r0A00, r0A02);
                  body.emit(assign(r09FF, add(r0A03, r09C0), 0x02));

                  body.emit(assign(r09FF, r09C1, 0x01));

                  body.emit(assign(r09C4, r09FF, 0x03));

                  body.emit(assign(r09C3, body.constant(false), 0x01));


               body.instructions = f09F0_parent_instructions;
               body.emit(f09F0);

               /* END IF */

               body.emit(assign(r0864, r09C4, 0x03));

               body.emit(assign(r0863, body.constant(false), 0x01));


            body.instructions = f0944_parent_instructions;
            body.emit(f0944);

            /* END IF */


         body.instructions = f0903_parent_instructions;
         body.emit(f0903);

         /* END IF */


      body.instructions = f08A2_parent_instructions;
      body.emit(f08A2);

      /* END IF */


   body.instructions = f087C_parent_instructions;
   body.emit(f087C);

   /* END IF */

   body.emit(ret(r0864));

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

   ir_variable *const r0A04 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0A04);
   ir_variable *const r0A05 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0A05);
   ir_variable *const r0A06 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r0A06);
   ir_variable *const r0A07 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0A07);
   ir_variable *const r0A08 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0A08);
   ir_variable *const r0A09 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0A09);
   ir_variable *const r0A0A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0A0A);
   ir_variable *const r0A0B = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0A0C = neg(r0A06);
   body.emit(assign(r0A0B, bit_and(r0A0C, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A0E = equal(r0A06, body.constant(int(0)));
   ir_if *f0A0D = new(mem_ctx) ir_if(operand(r0A0E).val);
   exec_list *const f0A0D_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A0D->then_instructions;

      body.emit(assign(r0A09, r0A05, 0x01));

      body.emit(assign(r0A0A, r0A04, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A0D->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A10 = less(r0A06, body.constant(int(32)));
      ir_if *f0A0F = new(mem_ctx) ir_if(operand(r0A10).val);
      exec_list *const f0A0F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A0F->then_instructions;

         ir_expression *const r0A11 = lshift(r0A04, r0A0B);
         ir_expression *const r0A12 = rshift(r0A05, r0A06);
         body.emit(assign(r0A09, bit_or(r0A11, r0A12), 0x01));

         body.emit(assign(r0A0A, rshift(r0A04, r0A06), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A0F->else_instructions;

         ir_variable *const r0A13 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A15 = less(r0A06, body.constant(int(64)));
         ir_if *f0A14 = new(mem_ctx) ir_if(operand(r0A15).val);
         exec_list *const f0A14_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A14->then_instructions;

            ir_expression *const r0A16 = bit_and(r0A06, body.constant(int(31)));
            body.emit(assign(r0A13, rshift(r0A04, r0A16), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A14->else_instructions;

            body.emit(assign(r0A13, body.constant(0u), 0x01));


         body.instructions = f0A14_parent_instructions;
         body.emit(f0A14);

         /* END IF */

         body.emit(assign(r0A09, r0A13, 0x01));

         body.emit(assign(r0A0A, body.constant(0u), 0x01));


      body.instructions = f0A0F_parent_instructions;
      body.emit(f0A0F);

      /* END IF */


   body.instructions = f0A0D_parent_instructions;
   body.emit(f0A0D);

   /* END IF */

   body.emit(assign(r0A08, r0A09, 0x01));

   body.emit(assign(r0A07, r0A0A, 0x01));

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

   ir_variable *const r0A17 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A17);
   ir_variable *const r0A18 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0A19 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A19);
   ir_variable *const r0A1A = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0A1A);
   ir_variable *const r0A1B = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0A1B, swizzle_x(r0A17), 0x01));

   body.emit(assign(r0A1A, r0A1B, 0x01));

   ir_variable *const r0A1C = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A1C, bit_and(swizzle_y(r0A17), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A19, r0A1C, 0x01));

   ir_variable *const r0A1D = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A1E = rshift(swizzle_y(r0A17), body.constant(int(20)));
   ir_expression *const r0A1F = bit_and(r0A1E, body.constant(2047u));
   body.emit(assign(r0A1D, expr(ir_unop_u2i, r0A1F), 0x01));

   ir_variable *const r0A20 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0A20, rshift(swizzle_y(r0A17), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A22 = nequal(r0A20, body.constant(0u));
   ir_if *f0A21 = new(mem_ctx) ir_if(operand(r0A22).val);
   exec_list *const f0A21_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A21->then_instructions;

      body.emit(assign(r0A18, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A21->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A24 = equal(r0A1D, body.constant(int(2047)));
      ir_expression *const r0A25 = bit_or(r0A1C, swizzle_x(r0A17));
      ir_expression *const r0A26 = nequal(r0A25, body.constant(0u));
      ir_expression *const r0A27 = logic_and(r0A24, r0A26);
      ir_if *f0A23 = new(mem_ctx) ir_if(operand(r0A27).val);
      exec_list *const f0A23_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A23->then_instructions;

         body.emit(assign(r0A18, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A23->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A29 = nequal(r0A1D, body.constant(int(0)));
         ir_if *f0A28 = new(mem_ctx) ir_if(operand(r0A29).val);
         exec_list *const f0A28_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A28->then_instructions;

            body.emit(assign(r0A19, bit_or(r0A1C, body.constant(1048576u)), 0x01));


         body.instructions = f0A28_parent_instructions;
         body.emit(f0A28);

         /* END IF */

         ir_variable *const r0A2A = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0A2A, sub(body.constant(int(1063)), r0A1D), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A2C = less(body.constant(int(0)), r0A2A);
         ir_if *f0A2B = new(mem_ctx) ir_if(operand(r0A2C).val);
         exec_list *const f0A2B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A2B->then_instructions;

            ir_variable *const r0A2D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0A2D);
            ir_variable *const r0A2E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0A2E);
            ir_variable *const r0A2F = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r0A30 = neg(r0A2A);
            body.emit(assign(r0A2F, bit_and(r0A30, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A32 = equal(r0A2A, body.constant(int(0)));
            ir_if *f0A31 = new(mem_ctx) ir_if(operand(r0A32).val);
            exec_list *const f0A31_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A31->then_instructions;

               body.emit(assign(r0A2D, r0A1B, 0x01));

               body.emit(assign(r0A2E, r0A19, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A31->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0A34 = less(r0A2A, body.constant(int(32)));
               ir_if *f0A33 = new(mem_ctx) ir_if(operand(r0A34).val);
               exec_list *const f0A33_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A33->then_instructions;

                  ir_expression *const r0A35 = lshift(r0A19, r0A2F);
                  ir_expression *const r0A36 = rshift(swizzle_x(r0A17), r0A2A);
                  ir_expression *const r0A37 = bit_or(r0A35, r0A36);
                  ir_expression *const r0A38 = lshift(swizzle_x(r0A17), r0A2F);
                  ir_expression *const r0A39 = nequal(r0A38, body.constant(0u));
                  ir_expression *const r0A3A = expr(ir_unop_b2i, r0A39);
                  ir_expression *const r0A3B = expr(ir_unop_i2u, r0A3A);
                  body.emit(assign(r0A2D, bit_or(r0A37, r0A3B), 0x01));

                  body.emit(assign(r0A2E, rshift(r0A19, r0A2A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A33->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A3D = equal(r0A2A, body.constant(int(32)));
                  ir_if *f0A3C = new(mem_ctx) ir_if(operand(r0A3D).val);
                  exec_list *const f0A3C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A3C->then_instructions;

                     ir_expression *const r0A3E = nequal(swizzle_x(r0A17), body.constant(0u));
                     ir_expression *const r0A3F = expr(ir_unop_b2i, r0A3E);
                     ir_expression *const r0A40 = expr(ir_unop_i2u, r0A3F);
                     body.emit(assign(r0A2D, bit_or(r0A19, r0A40), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A3C->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0A42 = less(r0A2A, body.constant(int(64)));
                     ir_if *f0A41 = new(mem_ctx) ir_if(operand(r0A42).val);
                     exec_list *const f0A41_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0A41->then_instructions;

                        ir_expression *const r0A43 = bit_and(r0A2A, body.constant(int(31)));
                        ir_expression *const r0A44 = rshift(r0A19, r0A43);
                        ir_expression *const r0A45 = lshift(r0A19, r0A2F);
                        ir_expression *const r0A46 = bit_or(r0A45, swizzle_x(r0A17));
                        ir_expression *const r0A47 = nequal(r0A46, body.constant(0u));
                        ir_expression *const r0A48 = expr(ir_unop_b2i, r0A47);
                        ir_expression *const r0A49 = expr(ir_unop_i2u, r0A48);
                        body.emit(assign(r0A2D, bit_or(r0A44, r0A49), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0A41->else_instructions;

                        ir_expression *const r0A4A = bit_or(r0A19, swizzle_x(r0A17));
                        ir_expression *const r0A4B = nequal(r0A4A, body.constant(0u));
                        ir_expression *const r0A4C = expr(ir_unop_b2i, r0A4B);
                        body.emit(assign(r0A2D, expr(ir_unop_i2u, r0A4C), 0x01));


                     body.instructions = f0A41_parent_instructions;
                     body.emit(f0A41);

                     /* END IF */


                  body.instructions = f0A3C_parent_instructions;
                  body.emit(f0A3C);

                  /* END IF */

                  body.emit(assign(r0A2E, body.constant(0u), 0x01));


               body.instructions = f0A33_parent_instructions;
               body.emit(f0A33);

               /* END IF */


            body.instructions = f0A31_parent_instructions;
            body.emit(f0A31);

            /* END IF */

            body.emit(assign(r0A19, r0A2E, 0x01));

            body.emit(assign(r0A1A, r0A2D, 0x01));


         body.instructions = f0A2B_parent_instructions;
         body.emit(f0A2B);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A4E = bit_and(r0A19, body.constant(4294963200u));
         ir_expression *const r0A4F = nequal(r0A4E, body.constant(0u));
         ir_if *f0A4D = new(mem_ctx) ir_if(operand(r0A4F).val);
         exec_list *const f0A4D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A4D->then_instructions;

            ir_variable *const r0A50 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A52 = nequal(r0A20, body.constant(0u));
            ir_if *f0A51 = new(mem_ctx) ir_if(operand(r0A52).val);
            exec_list *const f0A51_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A51->then_instructions;

               body.emit(assign(r0A50, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A51->else_instructions;

               body.emit(assign(r0A50, body.constant(4294967295u), 0x01));


            body.instructions = f0A51_parent_instructions;
            body.emit(f0A51);

            /* END IF */

            body.emit(assign(r0A18, r0A50, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A4D->else_instructions;

            ir_variable *const r0A53 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0A53);
            ir_variable *const r0A54 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0A54);
            ir_expression *const r0A55 = lshift(r0A19, body.constant(int(20)));
            ir_expression *const r0A56 = rshift(r0A1A, body.constant(int(12)));
            body.emit(assign(r0A53, bit_or(r0A55, r0A56), 0x01));

            body.emit(assign(r0A54, rshift(r0A19, body.constant(int(12))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A58 = nequal(r0A20, body.constant(0u));
            ir_expression *const r0A59 = nequal(r0A53, body.constant(0u));
            ir_expression *const r0A5A = logic_and(r0A58, r0A59);
            ir_if *f0A57 = new(mem_ctx) ir_if(operand(r0A5A).val);
            exec_list *const f0A57_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A57->then_instructions;

               ir_variable *const r0A5B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0A5D = nequal(r0A20, body.constant(0u));
               ir_if *f0A5C = new(mem_ctx) ir_if(operand(r0A5D).val);
               exec_list *const f0A5C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A5C->then_instructions;

                  body.emit(assign(r0A5B, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A5C->else_instructions;

                  body.emit(assign(r0A5B, body.constant(4294967295u), 0x01));


               body.instructions = f0A5C_parent_instructions;
               body.emit(f0A5C);

               /* END IF */

               body.emit(assign(r0A18, r0A5B, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A57->else_instructions;

               body.emit(assign(r0A18, r0A53, 0x01));


            body.instructions = f0A57_parent_instructions;
            body.emit(f0A57);

            /* END IF */


         body.instructions = f0A4D_parent_instructions;
         body.emit(f0A4D);

         /* END IF */


      body.instructions = f0A23_parent_instructions;
      body.emit(f0A23);

      /* END IF */


   body.instructions = f0A21_parent_instructions;
   body.emit(f0A21);

   /* END IF */

   body.emit(ret(r0A18));

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

   ir_variable *const r0A5E = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A5E);
   ir_variable *const r0A5F = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A60 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0A60);
   ir_variable *const r0A61 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0A61);
   /* IF CONDITION */
   ir_expression *const r0A63 = equal(r0A5E, body.constant(0u));
   ir_if *f0A62 = new(mem_ctx) ir_if(operand(r0A63).val);
   exec_list *const f0A62_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A62->then_instructions;

      body.emit(assign(r0A5F, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A62->else_instructions;

      ir_variable *const r0A64 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0A64, r0A5E, 0x01));

      ir_variable *const r0A65 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0A66 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0A66);
      /* IF CONDITION */
      ir_expression *const r0A68 = equal(r0A5E, body.constant(0u));
      ir_if *f0A67 = new(mem_ctx) ir_if(operand(r0A68).val);
      exec_list *const f0A67_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A67->then_instructions;

         body.emit(assign(r0A65, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A67->else_instructions;

         body.emit(assign(r0A66, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A6A = bit_and(r0A5E, body.constant(4294901760u));
         ir_expression *const r0A6B = equal(r0A6A, body.constant(0u));
         ir_if *f0A69 = new(mem_ctx) ir_if(operand(r0A6B).val);
         exec_list *const f0A69_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A69->then_instructions;

            body.emit(assign(r0A66, body.constant(int(16)), 0x01));

            body.emit(assign(r0A64, lshift(r0A5E, body.constant(int(16))), 0x01));


         body.instructions = f0A69_parent_instructions;
         body.emit(f0A69);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A6D = bit_and(r0A64, body.constant(4278190080u));
         ir_expression *const r0A6E = equal(r0A6D, body.constant(0u));
         ir_if *f0A6C = new(mem_ctx) ir_if(operand(r0A6E).val);
         exec_list *const f0A6C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A6C->then_instructions;

            body.emit(assign(r0A66, add(r0A66, body.constant(int(8))), 0x01));

            body.emit(assign(r0A64, lshift(r0A64, body.constant(int(8))), 0x01));


         body.instructions = f0A6C_parent_instructions;
         body.emit(f0A6C);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A70 = bit_and(r0A64, body.constant(4026531840u));
         ir_expression *const r0A71 = equal(r0A70, body.constant(0u));
         ir_if *f0A6F = new(mem_ctx) ir_if(operand(r0A71).val);
         exec_list *const f0A6F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A6F->then_instructions;

            body.emit(assign(r0A66, add(r0A66, body.constant(int(4))), 0x01));

            body.emit(assign(r0A64, lshift(r0A64, body.constant(int(4))), 0x01));


         body.instructions = f0A6F_parent_instructions;
         body.emit(f0A6F);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A73 = bit_and(r0A64, body.constant(3221225472u));
         ir_expression *const r0A74 = equal(r0A73, body.constant(0u));
         ir_if *f0A72 = new(mem_ctx) ir_if(operand(r0A74).val);
         exec_list *const f0A72_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A72->then_instructions;

            body.emit(assign(r0A66, add(r0A66, body.constant(int(2))), 0x01));

            body.emit(assign(r0A64, lshift(r0A64, body.constant(int(2))), 0x01));


         body.instructions = f0A72_parent_instructions;
         body.emit(f0A72);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A76 = bit_and(r0A64, body.constant(2147483648u));
         ir_expression *const r0A77 = equal(r0A76, body.constant(0u));
         ir_if *f0A75 = new(mem_ctx) ir_if(operand(r0A77).val);
         exec_list *const f0A75_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A75->then_instructions;

            body.emit(assign(r0A66, add(r0A66, body.constant(int(1))), 0x01));


         body.instructions = f0A75_parent_instructions;
         body.emit(f0A75);

         /* END IF */

         body.emit(assign(r0A65, r0A66, 0x01));


      body.instructions = f0A67_parent_instructions;
      body.emit(f0A67);

      /* END IF */

      ir_variable *const r0A78 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0A78, add(r0A65, body.constant(int(21))), 0x01));

      body.emit(assign(r0A61, body.constant(0u), 0x01));

      body.emit(assign(r0A60, body.constant(0u), 0x01));

      ir_variable *const r0A79 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0A7A = neg(r0A78);
      body.emit(assign(r0A79, bit_and(r0A7A, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A7C = equal(r0A78, body.constant(int(0)));
      ir_if *f0A7B = new(mem_ctx) ir_if(operand(r0A7C).val);
      exec_list *const f0A7B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A7B->then_instructions;

         body.emit(assign(r0A61, body.constant(0u), 0x01));

         body.emit(assign(r0A60, r0A5E, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A7B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A7E = less(r0A78, body.constant(int(32)));
         ir_if *f0A7D = new(mem_ctx) ir_if(operand(r0A7E).val);
         exec_list *const f0A7D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A7D->then_instructions;

            body.emit(assign(r0A61, rshift(r0A5E, r0A79), 0x01));

            body.emit(assign(r0A60, lshift(r0A5E, r0A78), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A7D->else_instructions;

            ir_variable *const r0A7F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A81 = less(r0A78, body.constant(int(64)));
            ir_if *f0A80 = new(mem_ctx) ir_if(operand(r0A81).val);
            exec_list *const f0A80_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A80->then_instructions;

               ir_expression *const r0A82 = add(r0A78, body.constant(int(-32)));
               body.emit(assign(r0A7F, lshift(r0A5E, r0A82), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A80->else_instructions;

               body.emit(assign(r0A7F, body.constant(0u), 0x01));


            body.instructions = f0A80_parent_instructions;
            body.emit(f0A80);

            /* END IF */

            body.emit(assign(r0A61, r0A7F, 0x01));

            body.emit(assign(r0A60, body.constant(0u), 0x01));


         body.instructions = f0A7D_parent_instructions;
         body.emit(f0A7D);

         /* END IF */


      body.instructions = f0A7B_parent_instructions;
      body.emit(f0A7B);

      /* END IF */

      ir_variable *const r0A83 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A83);
      ir_expression *const r0A84 = sub(body.constant(int(1074)), r0A78);
      ir_expression *const r0A85 = expr(ir_unop_i2u, r0A84);
      ir_expression *const r0A86 = lshift(r0A85, body.constant(int(20)));
      body.emit(assign(r0A83, add(r0A86, r0A61), 0x02));

      body.emit(assign(r0A83, r0A60, 0x01));

      body.emit(assign(r0A5F, r0A83, 0x03));


   body.instructions = f0A62_parent_instructions;
   body.emit(f0A62);

   /* END IF */

   body.emit(ret(r0A5F));

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

   ir_variable *const r0A87 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A87);
   ir_variable *const r0A88 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A88, body.constant(true), 0x01));

   ir_variable *const r0A89 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0A8A = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0A8A);
   ir_variable *const r0A8B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A8B);
   ir_variable *const r0A8C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A8C);
   ir_variable *const r0A8D = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A8D, bit_and(swizzle_y(r0A87), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A8C, r0A8D, 0x01));

   ir_variable *const r0A8E = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A8F = rshift(swizzle_y(r0A87), body.constant(int(20)));
   ir_expression *const r0A90 = bit_and(r0A8F, body.constant(2047u));
   body.emit(assign(r0A8E, expr(ir_unop_u2i, r0A90), 0x01));

   body.emit(assign(r0A8B, rshift(swizzle_y(r0A87), body.constant(int(31))), 0x01));

   body.emit(assign(r0A8A, body.constant(0u), 0x01));

   ir_variable *const r0A91 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0A91, add(r0A8E, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A93 = lequal(body.constant(int(0)), r0A91);
   ir_if *f0A92 = new(mem_ctx) ir_if(operand(r0A93).val);
   exec_list *const f0A92_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A92->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A95 = less(body.constant(int(1054)), r0A8E);
      ir_if *f0A94 = new(mem_ctx) ir_if(operand(r0A95).val);
      exec_list *const f0A94_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A94->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A97 = equal(r0A8E, body.constant(int(2047)));
         ir_expression *const r0A98 = bit_or(r0A8D, swizzle_x(r0A87));
         ir_expression *const r0A99 = expr(ir_unop_u2i, r0A98);
         ir_expression *const r0A9A = expr(ir_unop_i2b, r0A99);
         ir_expression *const r0A9B = logic_and(r0A97, r0A9A);
         ir_if *f0A96 = new(mem_ctx) ir_if(operand(r0A9B).val);
         exec_list *const f0A96_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A96->then_instructions;

            body.emit(assign(r0A8B, body.constant(0u), 0x01));


         body.instructions = f0A96_parent_instructions;
         body.emit(f0A96);

         /* END IF */

         ir_variable *const r0A9C = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A9E = expr(ir_unop_u2i, r0A8B);
         ir_expression *const r0A9F = expr(ir_unop_i2b, r0A9E);
         ir_if *f0A9D = new(mem_ctx) ir_if(operand(r0A9F).val);
         exec_list *const f0A9D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A9D->then_instructions;

            body.emit(assign(r0A9C, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A9D->else_instructions;

            body.emit(assign(r0A9C, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A9D_parent_instructions;
         body.emit(f0A9D);

         /* END IF */

         body.emit(assign(r0A89, r0A9C, 0x01));

         body.emit(assign(r0A88, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A94->else_instructions;

         ir_variable *const r0AA0 = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r0AA0, bit_or(r0A8D, body.constant(1048576u)), 0x01));

         ir_variable *const r0AA1 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0AA1, lshift(swizzle_x(r0A87), r0A91), 0x01));

         ir_variable *const r0AA2 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0AA4 = equal(r0A91, body.constant(int(0)));
         ir_if *f0AA3 = new(mem_ctx) ir_if(operand(r0AA4).val);
         exec_list *const f0AA3_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA3->then_instructions;

            body.emit(assign(r0AA2, r0AA0, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AA3->else_instructions;

            ir_expression *const r0AA5 = lshift(r0AA0, r0A91);
            ir_expression *const r0AA6 = neg(r0A91);
            ir_expression *const r0AA7 = bit_and(r0AA6, body.constant(int(31)));
            ir_expression *const r0AA8 = rshift(swizzle_x(r0A87), r0AA7);
            body.emit(assign(r0AA2, bit_or(r0AA5, r0AA8), 0x01));


         body.instructions = f0AA3_parent_instructions;
         body.emit(f0AA3);

         /* END IF */

         body.emit(assign(r0A8A, r0AA2, 0x01));


      body.instructions = f0A94_parent_instructions;
      body.emit(f0A94);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A92->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0AAA = less(r0A8E, body.constant(int(1023)));
      ir_if *f0AA9 = new(mem_ctx) ir_if(operand(r0AAA).val);
      exec_list *const f0AA9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AA9->then_instructions;

         body.emit(assign(r0A89, body.constant(int(0)), 0x01));

         body.emit(assign(r0A88, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AA9->else_instructions;

         body.emit(assign(r0A8C, bit_or(r0A8D, body.constant(1048576u)), 0x01));

         ir_expression *const r0AAB = neg(r0A91);
         body.emit(assign(r0A8A, rshift(r0A8C, r0AAB), 0x01));


      body.instructions = f0AA9_parent_instructions;
      body.emit(f0AA9);

      /* END IF */


   body.instructions = f0A92_parent_instructions;
   body.emit(f0A92);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0AAC = new(mem_ctx) ir_if(operand(r0A88).val);
   exec_list *const f0AAC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AAC->then_instructions;

      ir_variable *const r0AAD = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0AAF = nequal(r0A8B, body.constant(0u));
      ir_if *f0AAE = new(mem_ctx) ir_if(operand(r0AAF).val);
      exec_list *const f0AAE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AAE->then_instructions;

         ir_expression *const r0AB0 = expr(ir_unop_u2i, r0A8A);
         body.emit(assign(r0AAD, neg(r0AB0), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AAE->else_instructions;

         body.emit(assign(r0AAD, expr(ir_unop_u2i, r0A8A), 0x01));


      body.instructions = f0AAE_parent_instructions;
      body.emit(f0AAE);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0AB2 = less(r0AAD, body.constant(int(0)));
      ir_expression *const r0AB3 = expr(ir_unop_b2i, r0AB2);
      ir_expression *const r0AB4 = expr(ir_unop_i2u, r0AB3);
      ir_expression *const r0AB5 = bit_xor(r0A8B, r0AB4);
      ir_expression *const r0AB6 = expr(ir_unop_u2i, r0AB5);
      ir_expression *const r0AB7 = expr(ir_unop_i2b, r0AB6);
      ir_expression *const r0AB8 = expr(ir_unop_i2b, r0AAD);
      ir_expression *const r0AB9 = logic_and(r0AB7, r0AB8);
      ir_if *f0AB1 = new(mem_ctx) ir_if(operand(r0AB9).val);
      exec_list *const f0AB1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AB1->then_instructions;

         ir_variable *const r0ABA = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0ABC = expr(ir_unop_u2i, r0A8B);
         ir_expression *const r0ABD = expr(ir_unop_i2b, r0ABC);
         ir_if *f0ABB = new(mem_ctx) ir_if(operand(r0ABD).val);
         exec_list *const f0ABB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ABB->then_instructions;

            body.emit(assign(r0ABA, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0ABB->else_instructions;

            body.emit(assign(r0ABA, body.constant(int(2147483647)), 0x01));


         body.instructions = f0ABB_parent_instructions;
         body.emit(f0ABB);

         /* END IF */

         body.emit(assign(r0A89, r0ABA, 0x01));

         body.emit(assign(r0A88, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AB1->else_instructions;

         body.emit(assign(r0A89, r0AAD, 0x01));

         body.emit(assign(r0A88, body.constant(false), 0x01));


      body.instructions = f0AB1_parent_instructions;
      body.emit(f0AB1);

      /* END IF */


   body.instructions = f0AAC_parent_instructions;
   body.emit(f0AAC);

   /* END IF */

   body.emit(ret(r0A89));

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

   ir_variable *const r0ABE = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0ABE);
   ir_variable *const r0ABF = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0AC0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0AC0);
   ir_variable *const r0AC1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0AC1);
   ir_variable *const r0AC2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0AC2);
   body.emit(assign(r0AC2, body.constant(0u), 0x01));

   body.emit(assign(r0AC1, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AC4 = equal(r0ABE, body.constant(int(0)));
   ir_if *f0AC3 = new(mem_ctx) ir_if(operand(r0AC4).val);
   exec_list *const f0AC3_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AC3->then_instructions;

      ir_variable *const r0AC5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0AC5);
      body.emit(assign(r0AC5, body.constant(0u), 0x02));

      body.emit(assign(r0AC5, body.constant(0u), 0x01));

      body.emit(assign(r0ABF, r0AC5, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0AC3->else_instructions;

      ir_expression *const r0AC6 = less(r0ABE, body.constant(int(0)));
      ir_expression *const r0AC7 = expr(ir_unop_b2i, r0AC6);
      body.emit(assign(r0AC0, expr(ir_unop_i2u, r0AC7), 0x01));

      ir_variable *const r0AC8 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0ACA = less(r0ABE, body.constant(int(0)));
      ir_if *f0AC9 = new(mem_ctx) ir_if(operand(r0ACA).val);
      exec_list *const f0AC9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AC9->then_instructions;

         ir_expression *const r0ACB = neg(r0ABE);
         body.emit(assign(r0AC8, expr(ir_unop_i2u, r0ACB), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AC9->else_instructions;

         body.emit(assign(r0AC8, expr(ir_unop_i2u, r0ABE), 0x01));


      body.instructions = f0AC9_parent_instructions;
      body.emit(f0AC9);

      /* END IF */

      ir_variable *const r0ACC = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0ACC, r0AC8, 0x01));

      ir_variable *const r0ACD = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0ACE = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0ACE);
      /* IF CONDITION */
      ir_expression *const r0AD0 = equal(r0AC8, body.constant(0u));
      ir_if *f0ACF = new(mem_ctx) ir_if(operand(r0AD0).val);
      exec_list *const f0ACF_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0ACF->then_instructions;

         body.emit(assign(r0ACD, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0ACF->else_instructions;

         body.emit(assign(r0ACE, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AD2 = bit_and(r0AC8, body.constant(4294901760u));
         ir_expression *const r0AD3 = equal(r0AD2, body.constant(0u));
         ir_if *f0AD1 = new(mem_ctx) ir_if(operand(r0AD3).val);
         exec_list *const f0AD1_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AD1->then_instructions;

            body.emit(assign(r0ACE, body.constant(int(16)), 0x01));

            body.emit(assign(r0ACC, lshift(r0AC8, body.constant(int(16))), 0x01));


         body.instructions = f0AD1_parent_instructions;
         body.emit(f0AD1);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AD5 = bit_and(r0ACC, body.constant(4278190080u));
         ir_expression *const r0AD6 = equal(r0AD5, body.constant(0u));
         ir_if *f0AD4 = new(mem_ctx) ir_if(operand(r0AD6).val);
         exec_list *const f0AD4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AD4->then_instructions;

            body.emit(assign(r0ACE, add(r0ACE, body.constant(int(8))), 0x01));

            body.emit(assign(r0ACC, lshift(r0ACC, body.constant(int(8))), 0x01));


         body.instructions = f0AD4_parent_instructions;
         body.emit(f0AD4);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AD8 = bit_and(r0ACC, body.constant(4026531840u));
         ir_expression *const r0AD9 = equal(r0AD8, body.constant(0u));
         ir_if *f0AD7 = new(mem_ctx) ir_if(operand(r0AD9).val);
         exec_list *const f0AD7_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AD7->then_instructions;

            body.emit(assign(r0ACE, add(r0ACE, body.constant(int(4))), 0x01));

            body.emit(assign(r0ACC, lshift(r0ACC, body.constant(int(4))), 0x01));


         body.instructions = f0AD7_parent_instructions;
         body.emit(f0AD7);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0ADB = bit_and(r0ACC, body.constant(3221225472u));
         ir_expression *const r0ADC = equal(r0ADB, body.constant(0u));
         ir_if *f0ADA = new(mem_ctx) ir_if(operand(r0ADC).val);
         exec_list *const f0ADA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ADA->then_instructions;

            body.emit(assign(r0ACE, add(r0ACE, body.constant(int(2))), 0x01));

            body.emit(assign(r0ACC, lshift(r0ACC, body.constant(int(2))), 0x01));


         body.instructions = f0ADA_parent_instructions;
         body.emit(f0ADA);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0ADE = bit_and(r0ACC, body.constant(2147483648u));
         ir_expression *const r0ADF = equal(r0ADE, body.constant(0u));
         ir_if *f0ADD = new(mem_ctx) ir_if(operand(r0ADF).val);
         exec_list *const f0ADD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0ADD->then_instructions;

            body.emit(assign(r0ACE, add(r0ACE, body.constant(int(1))), 0x01));


         body.instructions = f0ADD_parent_instructions;
         body.emit(f0ADD);

         /* END IF */

         body.emit(assign(r0ACD, r0ACE, 0x01));


      body.instructions = f0ACF_parent_instructions;
      body.emit(f0ACF);

      /* END IF */

      ir_variable *const r0AE0 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0AE0, add(r0ACD, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0AE2 = lequal(body.constant(int(0)), r0AE0);
      ir_if *f0AE1 = new(mem_ctx) ir_if(operand(r0AE2).val);
      exec_list *const f0AE1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AE1->then_instructions;

         body.emit(assign(r0AC2, lshift(r0AC8, r0AE0), 0x01));

         body.emit(assign(r0AC1, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AE1->else_instructions;

         ir_variable *const r0AE3 = body.make_temp(glsl_type::uint_type, "a1");
         body.emit(assign(r0AE3, body.constant(0u), 0x01));

         ir_variable *const r0AE4 = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r0AE4, neg(r0AE0), 0x01));

         ir_variable *const r0AE5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
         body.emit(r0AE5);
         ir_variable *const r0AE6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
         body.emit(r0AE6);
         ir_variable *const r0AE7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         ir_expression *const r0AE8 = neg(r0AE4);
         body.emit(assign(r0AE7, bit_and(r0AE8, body.constant(int(31))), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AEA = equal(r0AE4, body.constant(int(0)));
         ir_if *f0AE9 = new(mem_ctx) ir_if(operand(r0AEA).val);
         exec_list *const f0AE9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AE9->then_instructions;

            body.emit(assign(r0AE5, body.constant(0u), 0x01));

            body.emit(assign(r0AE6, r0AC8, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AE9->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0AEC = less(r0AE4, body.constant(int(32)));
            ir_if *f0AEB = new(mem_ctx) ir_if(operand(r0AEC).val);
            exec_list *const f0AEB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AEB->then_instructions;

               ir_expression *const r0AED = lshift(r0AC8, r0AE7);
               body.emit(assign(r0AE5, bit_or(r0AED, body.constant(0u)), 0x01));

               body.emit(assign(r0AE6, rshift(r0AC8, r0AE4), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0AEB->else_instructions;

               ir_variable *const r0AEE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0AF0 = less(r0AE4, body.constant(int(64)));
               ir_if *f0AEF = new(mem_ctx) ir_if(operand(r0AF0).val);
               exec_list *const f0AEF_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0AEF->then_instructions;

                  ir_expression *const r0AF1 = bit_and(r0AE4, body.constant(int(31)));
                  body.emit(assign(r0AEE, rshift(r0AC8, r0AF1), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0AEF->else_instructions;

                  body.emit(assign(r0AEE, body.constant(0u), 0x01));


               body.instructions = f0AEF_parent_instructions;
               body.emit(f0AEF);

               /* END IF */

               body.emit(assign(r0AE5, r0AEE, 0x01));

               body.emit(assign(r0AE6, body.constant(0u), 0x01));


            body.instructions = f0AEB_parent_instructions;
            body.emit(f0AEB);

            /* END IF */


         body.instructions = f0AE9_parent_instructions;
         body.emit(f0AE9);

         /* END IF */

         body.emit(assign(r0AC2, r0AE6, 0x01));

         body.emit(assign(r0AC1, r0AE5, 0x01));


      body.instructions = f0AE1_parent_instructions;
      body.emit(f0AE1);

      /* END IF */

      ir_variable *const r0AF2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0AF2);
      ir_expression *const r0AF3 = lshift(r0AC0, body.constant(int(31)));
      ir_expression *const r0AF4 = sub(body.constant(int(1042)), r0AE0);
      ir_expression *const r0AF5 = expr(ir_unop_i2u, r0AF4);
      ir_expression *const r0AF6 = lshift(r0AF5, body.constant(int(20)));
      ir_expression *const r0AF7 = add(r0AF3, r0AF6);
      body.emit(assign(r0AF2, add(r0AF7, r0AC2), 0x02));

      body.emit(assign(r0AF2, r0AC1, 0x01));

      body.emit(assign(r0ABF, r0AF2, 0x03));


   body.instructions = f0AC3_parent_instructions;
   body.emit(f0AC3);

   /* END IF */

   body.emit(ret(r0ABF));

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

   ir_variable *const r0AF8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AF8);
   ir_variable *const r0AF9 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AF9);
   ir_variable *const r0AFA = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AFA);
   ir_variable *const r0AFB = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r0AFC = lshift(r0AF8, body.constant(int(31)));
   ir_expression *const r0AFD = expr(ir_unop_i2u, r0AF9);
   ir_expression *const r0AFE = lshift(r0AFD, body.constant(int(23)));
   ir_expression *const r0AFF = add(r0AFC, r0AFE);
   ir_expression *const r0B00 = add(r0AFF, r0AFA);
   body.emit(assign(r0AFB, expr(ir_unop_bitcast_u2f, r0B00), 0x01));

   body.emit(ret(r0AFB));

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

   ir_variable *const r0B01 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0B01);
   ir_variable *const r0B02 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0B02);
   ir_variable *const r0B03 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0B03);
   ir_variable *const r0B04 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B04, body.constant(true), 0x01));

   ir_variable *const r0B05 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B06 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0B06);
   ir_expression *const r0B07 = bit_and(r0B03, body.constant(127u));
   body.emit(assign(r0B06, expr(ir_unop_u2i, r0B07), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B09 = expr(ir_unop_i2u, r0B02);
   ir_expression *const r0B0A = lequal(body.constant(253u), r0B09);
   ir_if *f0B08 = new(mem_ctx) ir_if(operand(r0B0A).val);
   exec_list *const f0B08_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B08->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B0C = less(body.constant(int(253)), r0B02);
      ir_expression *const r0B0D = equal(r0B02, body.constant(int(253)));
      ir_expression *const r0B0E = expr(ir_unop_u2i, r0B03);
      ir_expression *const r0B0F = less(r0B0E, body.constant(int(-64)));
      ir_expression *const r0B10 = logic_and(r0B0D, r0B0F);
      ir_expression *const r0B11 = logic_or(r0B0C, r0B10);
      ir_if *f0B0B = new(mem_ctx) ir_if(operand(r0B11).val);
      exec_list *const f0B0B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B0B->then_instructions;

         ir_expression *const r0B12 = lshift(r0B01, body.constant(int(31)));
         ir_expression *const r0B13 = add(r0B12, body.constant(2139095040u));
         body.emit(assign(r0B05, expr(ir_unop_bitcast_u2f, r0B13), 0x01));

         body.emit(assign(r0B04, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B0B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0B15 = less(r0B02, body.constant(int(0)));
         ir_if *f0B14 = new(mem_ctx) ir_if(operand(r0B15).val);
         exec_list *const f0B14_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B14->then_instructions;

            ir_variable *const r0B16 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B16, neg(r0B02), 0x01));

            /* IF CONDITION */
            ir_expression *const r0B18 = less(r0B16, body.constant(int(32)));
            ir_if *f0B17 = new(mem_ctx) ir_if(operand(r0B18).val);
            exec_list *const f0B17_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B17->then_instructions;

               ir_expression *const r0B19 = rshift(r0B03, r0B16);
               ir_expression *const r0B1A = neg(r0B16);
               ir_expression *const r0B1B = bit_and(r0B1A, body.constant(int(31)));
               ir_expression *const r0B1C = lshift(r0B03, r0B1B);
               ir_expression *const r0B1D = nequal(r0B1C, body.constant(0u));
               ir_expression *const r0B1E = expr(ir_unop_b2i, r0B1D);
               ir_expression *const r0B1F = expr(ir_unop_i2u, r0B1E);
               body.emit(assign(r0B03, bit_or(r0B19, r0B1F), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0B17->else_instructions;

               ir_expression *const r0B20 = nequal(r0B03, body.constant(0u));
               ir_expression *const r0B21 = expr(ir_unop_b2i, r0B20);
               body.emit(assign(r0B03, expr(ir_unop_i2u, r0B21), 0x01));


            body.instructions = f0B17_parent_instructions;
            body.emit(f0B17);

            /* END IF */

            body.emit(assign(r0B02, body.constant(int(0)), 0x01));

            ir_expression *const r0B22 = expr(ir_unop_u2i, r0B03);
            body.emit(assign(r0B06, bit_and(r0B22, body.constant(int(127))), 0x01));


         body.instructions = f0B14_parent_instructions;
         body.emit(f0B14);

         /* END IF */


      body.instructions = f0B0B_parent_instructions;
      body.emit(f0B0B);

      /* END IF */


   body.instructions = f0B08_parent_instructions;
   body.emit(f0B08);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0B23 = new(mem_ctx) ir_if(operand(r0B04).val);
   exec_list *const f0B23_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B23->then_instructions;

      ir_expression *const r0B24 = add(r0B03, body.constant(64u));
      body.emit(assign(r0B03, rshift(r0B24, body.constant(int(7))), 0x01));

      ir_expression *const r0B25 = bit_xor(r0B06, body.constant(int(64)));
      ir_expression *const r0B26 = equal(r0B25, body.constant(int(0)));
      ir_expression *const r0B27 = expr(ir_unop_b2i, r0B26);
      ir_expression *const r0B28 = expr(ir_unop_i2u, r0B27);
      ir_expression *const r0B29 = expr(ir_unop_bit_not, r0B28);
      body.emit(assign(r0B03, bit_and(r0B03, r0B29), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B2B = equal(r0B03, body.constant(0u));
      ir_if *f0B2A = new(mem_ctx) ir_if(operand(r0B2B).val);
      exec_list *const f0B2A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B2A->then_instructions;

         body.emit(assign(r0B02, body.constant(int(0)), 0x01));


      body.instructions = f0B2A_parent_instructions;
      body.emit(f0B2A);

      /* END IF */

      ir_expression *const r0B2C = lshift(r0B01, body.constant(int(31)));
      ir_expression *const r0B2D = expr(ir_unop_i2u, r0B02);
      ir_expression *const r0B2E = lshift(r0B2D, body.constant(int(23)));
      ir_expression *const r0B2F = add(r0B2C, r0B2E);
      ir_expression *const r0B30 = add(r0B2F, r0B03);
      body.emit(assign(r0B05, expr(ir_unop_bitcast_u2f, r0B30), 0x01));

      body.emit(assign(r0B04, body.constant(false), 0x01));


   body.instructions = f0B23_parent_instructions;
   body.emit(f0B23);

   /* END IF */

   body.emit(ret(r0B05));

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

   ir_variable *const r0B31 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0B31);
   ir_variable *const r0B32 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B33 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0B33);
   body.emit(assign(r0B33, body.constant(0u), 0x01));

   ir_variable *const r0B34 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0B34, swizzle_x(r0B31), 0x01));

   ir_variable *const r0B35 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B35, bit_and(swizzle_y(r0B31), body.constant(1048575u)), 0x01));

   ir_variable *const r0B36 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B37 = rshift(swizzle_y(r0B31), body.constant(int(20)));
   ir_expression *const r0B38 = bit_and(r0B37, body.constant(2047u));
   body.emit(assign(r0B36, expr(ir_unop_u2i, r0B38), 0x01));

   ir_variable *const r0B39 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B39, rshift(swizzle_y(r0B31), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B3B = equal(r0B36, body.constant(int(2047)));
   ir_if *f0B3A = new(mem_ctx) ir_if(operand(r0B3B).val);
   exec_list *const f0B3A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B3A->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B3D = bit_or(r0B35, swizzle_x(r0B31));
      ir_expression *const r0B3E = nequal(r0B3D, body.constant(0u));
      ir_if *f0B3C = new(mem_ctx) ir_if(operand(r0B3E).val);
      exec_list *const f0B3C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B3C->then_instructions;

         ir_variable *const r0B3F = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0B3F, lshift(swizzle_x(r0B31), body.constant(int(12))), 0x01));

         ir_variable *const r0B40 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         ir_expression *const r0B41 = lshift(swizzle_y(r0B31), body.constant(int(12)));
         ir_expression *const r0B42 = rshift(swizzle_x(r0B31), body.constant(int(20)));
         body.emit(assign(r0B40, bit_or(r0B41, r0B42), 0x01));

         body.emit(assign(r0B31, r0B40, 0x02));

         body.emit(assign(r0B31, r0B3F, 0x01));

         ir_expression *const r0B43 = lshift(r0B39, body.constant(int(31)));
         ir_expression *const r0B44 = bit_or(r0B43, body.constant(2143289344u));
         ir_expression *const r0B45 = rshift(r0B40, body.constant(int(9)));
         ir_expression *const r0B46 = bit_or(r0B44, r0B45);
         body.emit(assign(r0B32, expr(ir_unop_bitcast_u2f, r0B46), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B3C->else_instructions;

         ir_expression *const r0B47 = lshift(r0B39, body.constant(int(31)));
         ir_expression *const r0B48 = add(r0B47, body.constant(2139095040u));
         body.emit(assign(r0B32, expr(ir_unop_bitcast_u2f, r0B48), 0x01));


      body.instructions = f0B3C_parent_instructions;
      body.emit(f0B3C);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B3A->else_instructions;

      ir_variable *const r0B49 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B49);
      ir_variable *const r0B4A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0B4A);
      ir_expression *const r0B4B = lshift(r0B35, body.constant(int(10)));
      ir_expression *const r0B4C = rshift(r0B34, body.constant(int(22)));
      ir_expression *const r0B4D = bit_or(r0B4B, r0B4C);
      ir_expression *const r0B4E = lshift(r0B34, body.constant(int(10)));
      ir_expression *const r0B4F = nequal(r0B4E, body.constant(0u));
      ir_expression *const r0B50 = expr(ir_unop_b2i, r0B4F);
      ir_expression *const r0B51 = expr(ir_unop_i2u, r0B50);
      body.emit(assign(r0B49, bit_or(r0B4D, r0B51), 0x01));

      body.emit(assign(r0B4A, rshift(r0B35, body.constant(int(22))), 0x01));

      body.emit(assign(r0B33, r0B49, 0x01));

      /* IF CONDITION */
      ir_expression *const r0B53 = nequal(r0B36, body.constant(int(0)));
      ir_if *f0B52 = new(mem_ctx) ir_if(operand(r0B53).val);
      exec_list *const f0B52_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B52->then_instructions;

         body.emit(assign(r0B33, bit_or(r0B49, body.constant(1073741824u)), 0x01));


      body.instructions = f0B52_parent_instructions;
      body.emit(f0B52);

      /* END IF */

      ir_variable *const r0B54 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B54, add(r0B36, body.constant(int(-897))), 0x01));

      ir_variable *const r0B55 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B55, r0B33, 0x01));

      ir_variable *const r0B56 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B56, body.constant(true), 0x01));

      ir_variable *const r0B57 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B58 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B58);
      ir_expression *const r0B59 = bit_and(r0B33, body.constant(127u));
      body.emit(assign(r0B58, expr(ir_unop_u2i, r0B59), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B5B = expr(ir_unop_i2u, r0B54);
      ir_expression *const r0B5C = lequal(body.constant(253u), r0B5B);
      ir_if *f0B5A = new(mem_ctx) ir_if(operand(r0B5C).val);
      exec_list *const f0B5A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B5A->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B5E = less(body.constant(int(253)), r0B54);
         ir_expression *const r0B5F = equal(r0B54, body.constant(int(253)));
         ir_expression *const r0B60 = expr(ir_unop_u2i, r0B33);
         ir_expression *const r0B61 = less(r0B60, body.constant(int(-64)));
         ir_expression *const r0B62 = logic_and(r0B5F, r0B61);
         ir_expression *const r0B63 = logic_or(r0B5E, r0B62);
         ir_if *f0B5D = new(mem_ctx) ir_if(operand(r0B63).val);
         exec_list *const f0B5D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B5D->then_instructions;

            ir_expression *const r0B64 = lshift(r0B39, body.constant(int(31)));
            ir_expression *const r0B65 = add(r0B64, body.constant(2139095040u));
            body.emit(assign(r0B57, expr(ir_unop_bitcast_u2f, r0B65), 0x01));

            body.emit(assign(r0B56, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B5D->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0B67 = less(r0B54, body.constant(int(0)));
            ir_if *f0B66 = new(mem_ctx) ir_if(operand(r0B67).val);
            exec_list *const f0B66_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B66->then_instructions;

               ir_variable *const r0B68 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0B68, neg(r0B54), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B6A = less(r0B68, body.constant(int(32)));
               ir_if *f0B69 = new(mem_ctx) ir_if(operand(r0B6A).val);
               exec_list *const f0B69_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B69->then_instructions;

                  ir_expression *const r0B6B = rshift(r0B33, r0B68);
                  ir_expression *const r0B6C = neg(r0B68);
                  ir_expression *const r0B6D = bit_and(r0B6C, body.constant(int(31)));
                  ir_expression *const r0B6E = lshift(r0B33, r0B6D);
                  ir_expression *const r0B6F = nequal(r0B6E, body.constant(0u));
                  ir_expression *const r0B70 = expr(ir_unop_b2i, r0B6F);
                  ir_expression *const r0B71 = expr(ir_unop_i2u, r0B70);
                  body.emit(assign(r0B55, bit_or(r0B6B, r0B71), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0B69->else_instructions;

                  ir_expression *const r0B72 = nequal(r0B55, body.constant(0u));
                  ir_expression *const r0B73 = expr(ir_unop_b2i, r0B72);
                  body.emit(assign(r0B55, expr(ir_unop_i2u, r0B73), 0x01));


               body.instructions = f0B69_parent_instructions;
               body.emit(f0B69);

               /* END IF */

               body.emit(assign(r0B54, body.constant(int(0)), 0x01));

               ir_expression *const r0B74 = expr(ir_unop_u2i, r0B55);
               body.emit(assign(r0B58, bit_and(r0B74, body.constant(int(127))), 0x01));


            body.instructions = f0B66_parent_instructions;
            body.emit(f0B66);

            /* END IF */


         body.instructions = f0B5D_parent_instructions;
         body.emit(f0B5D);

         /* END IF */


      body.instructions = f0B5A_parent_instructions;
      body.emit(f0B5A);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B75 = new(mem_ctx) ir_if(operand(r0B56).val);
      exec_list *const f0B75_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B75->then_instructions;

         ir_expression *const r0B76 = add(r0B55, body.constant(64u));
         body.emit(assign(r0B55, rshift(r0B76, body.constant(int(7))), 0x01));

         ir_expression *const r0B77 = bit_xor(r0B58, body.constant(int(64)));
         ir_expression *const r0B78 = equal(r0B77, body.constant(int(0)));
         ir_expression *const r0B79 = expr(ir_unop_b2i, r0B78);
         ir_expression *const r0B7A = expr(ir_unop_i2u, r0B79);
         ir_expression *const r0B7B = expr(ir_unop_bit_not, r0B7A);
         body.emit(assign(r0B55, bit_and(r0B55, r0B7B), 0x01));

         /* IF CONDITION */
         ir_expression *const r0B7D = equal(r0B55, body.constant(0u));
         ir_if *f0B7C = new(mem_ctx) ir_if(operand(r0B7D).val);
         exec_list *const f0B7C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B7C->then_instructions;

            body.emit(assign(r0B54, body.constant(int(0)), 0x01));


         body.instructions = f0B7C_parent_instructions;
         body.emit(f0B7C);

         /* END IF */

         ir_expression *const r0B7E = lshift(r0B39, body.constant(int(31)));
         ir_expression *const r0B7F = expr(ir_unop_i2u, r0B54);
         ir_expression *const r0B80 = lshift(r0B7F, body.constant(int(23)));
         ir_expression *const r0B81 = add(r0B7E, r0B80);
         ir_expression *const r0B82 = add(r0B81, r0B55);
         body.emit(assign(r0B57, expr(ir_unop_bitcast_u2f, r0B82), 0x01));

         body.emit(assign(r0B56, body.constant(false), 0x01));


      body.instructions = f0B75_parent_instructions;
      body.emit(f0B75);

      /* END IF */

      body.emit(assign(r0B32, r0B57, 0x01));


   body.instructions = f0B3A_parent_instructions;
   body.emit(f0B3A);

   /* END IF */

   body.emit(ret(r0B32));

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

   ir_variable *const r0B83 = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0B83);
   ir_variable *const r0B84 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B84, body.constant(true), 0x01));

   ir_variable *const r0B85 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B86 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B86);
   ir_variable *const r0B87 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B87);
   ir_variable *const r0B88 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B88);
   ir_variable *const r0B89 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0B89, expr(ir_unop_bitcast_f2u, r0B83), 0x01));

   ir_variable *const r0B8A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B8A, bit_and(r0B89, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B88, r0B8A, 0x01));

   ir_variable *const r0B8B = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B8C = rshift(r0B89, body.constant(int(23)));
   ir_expression *const r0B8D = bit_and(r0B8C, body.constant(255u));
   body.emit(assign(r0B8B, expr(ir_unop_u2i, r0B8D), 0x01));

   body.emit(assign(r0B87, r0B8B, 0x01));

   body.emit(assign(r0B86, rshift(r0B89, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B8F = equal(r0B8B, body.constant(int(255)));
   ir_if *f0B8E = new(mem_ctx) ir_if(operand(r0B8F).val);
   exec_list *const f0B8E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B8E->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B91 = nequal(r0B8A, body.constant(0u));
      ir_if *f0B90 = new(mem_ctx) ir_if(operand(r0B91).val);
      exec_list *const f0B90_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B90->then_instructions;

         ir_variable *const r0B92 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B92, lshift(r0B89, body.constant(int(9))), 0x01));

         ir_variable *const r0B93 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B94 = lshift(r0B92, body.constant(int(20)));
         body.emit(assign(r0B93, bit_or(r0B94, body.constant(0u)), 0x01));

         ir_expression *const r0B95 = rshift(r0B92, body.constant(int(12)));
         ir_expression *const r0B96 = lshift(r0B86, body.constant(int(31)));
         ir_expression *const r0B97 = bit_or(r0B96, body.constant(2146959360u));
         body.emit(assign(r0B93, bit_or(r0B95, r0B97), 0x02));

         body.emit(assign(r0B85, r0B93, 0x03));

         body.emit(assign(r0B84, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B90->else_instructions;

         ir_variable *const r0B98 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B98);
         ir_expression *const r0B99 = lshift(r0B86, body.constant(int(31)));
         body.emit(assign(r0B98, add(r0B99, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B98, body.constant(0u), 0x01));

         body.emit(assign(r0B85, r0B98, 0x03));

         body.emit(assign(r0B84, body.constant(false), 0x01));


      body.instructions = f0B90_parent_instructions;
      body.emit(f0B90);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B8E->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B9B = equal(r0B8B, body.constant(int(0)));
      ir_if *f0B9A = new(mem_ctx) ir_if(operand(r0B9B).val);
      exec_list *const f0B9A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B9A->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B9D = equal(r0B8A, body.constant(0u));
         ir_if *f0B9C = new(mem_ctx) ir_if(operand(r0B9D).val);
         exec_list *const f0B9C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B9C->then_instructions;

            ir_variable *const r0B9E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B9E);
            body.emit(assign(r0B9E, lshift(r0B86, body.constant(int(31))), 0x02));

            body.emit(assign(r0B9E, body.constant(0u), 0x01));

            body.emit(assign(r0B85, r0B9E, 0x03));

            body.emit(assign(r0B84, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B9C->else_instructions;

            ir_variable *const r0B9F = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0B9F, r0B8A, 0x01));

            ir_variable *const r0BA0 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0BA1 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0BA1);
            /* IF CONDITION */
            ir_expression *const r0BA3 = equal(r0B8A, body.constant(0u));
            ir_if *f0BA2 = new(mem_ctx) ir_if(operand(r0BA3).val);
            exec_list *const f0BA2_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0BA2->then_instructions;

               body.emit(assign(r0BA0, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0BA2->else_instructions;

               body.emit(assign(r0BA1, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0BA5 = bit_and(r0B8A, body.constant(4294901760u));
               ir_expression *const r0BA6 = equal(r0BA5, body.constant(0u));
               ir_if *f0BA4 = new(mem_ctx) ir_if(operand(r0BA6).val);
               exec_list *const f0BA4_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BA4->then_instructions;

                  body.emit(assign(r0BA1, body.constant(int(16)), 0x01));

                  body.emit(assign(r0B9F, lshift(r0B8A, body.constant(int(16))), 0x01));


               body.instructions = f0BA4_parent_instructions;
               body.emit(f0BA4);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0BA8 = bit_and(r0B9F, body.constant(4278190080u));
               ir_expression *const r0BA9 = equal(r0BA8, body.constant(0u));
               ir_if *f0BA7 = new(mem_ctx) ir_if(operand(r0BA9).val);
               exec_list *const f0BA7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BA7->then_instructions;

                  body.emit(assign(r0BA1, add(r0BA1, body.constant(int(8))), 0x01));

                  body.emit(assign(r0B9F, lshift(r0B9F, body.constant(int(8))), 0x01));


               body.instructions = f0BA7_parent_instructions;
               body.emit(f0BA7);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0BAB = bit_and(r0B9F, body.constant(4026531840u));
               ir_expression *const r0BAC = equal(r0BAB, body.constant(0u));
               ir_if *f0BAA = new(mem_ctx) ir_if(operand(r0BAC).val);
               exec_list *const f0BAA_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BAA->then_instructions;

                  body.emit(assign(r0BA1, add(r0BA1, body.constant(int(4))), 0x01));

                  body.emit(assign(r0B9F, lshift(r0B9F, body.constant(int(4))), 0x01));


               body.instructions = f0BAA_parent_instructions;
               body.emit(f0BAA);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0BAE = bit_and(r0B9F, body.constant(3221225472u));
               ir_expression *const r0BAF = equal(r0BAE, body.constant(0u));
               ir_if *f0BAD = new(mem_ctx) ir_if(operand(r0BAF).val);
               exec_list *const f0BAD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BAD->then_instructions;

                  body.emit(assign(r0BA1, add(r0BA1, body.constant(int(2))), 0x01));

                  body.emit(assign(r0B9F, lshift(r0B9F, body.constant(int(2))), 0x01));


               body.instructions = f0BAD_parent_instructions;
               body.emit(f0BAD);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0BB1 = bit_and(r0B9F, body.constant(2147483648u));
               ir_expression *const r0BB2 = equal(r0BB1, body.constant(0u));
               ir_if *f0BB0 = new(mem_ctx) ir_if(operand(r0BB2).val);
               exec_list *const f0BB0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0BB0->then_instructions;

                  body.emit(assign(r0BA1, add(r0BA1, body.constant(int(1))), 0x01));


               body.instructions = f0BB0_parent_instructions;
               body.emit(f0BB0);

               /* END IF */

               body.emit(assign(r0BA0, r0BA1, 0x01));


            body.instructions = f0BA2_parent_instructions;
            body.emit(f0BA2);

            /* END IF */

            ir_variable *const r0BB3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0BB3, add(r0BA0, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B88, lshift(r0B8A, r0BB3), 0x01));

            body.emit(assign(r0B87, sub(body.constant(int(1)), r0BB3), 0x01));

            body.emit(assign(r0B87, add(r0B87, body.constant(int(-1))), 0x01));


         body.instructions = f0B9C_parent_instructions;
         body.emit(f0B9C);

         /* END IF */


      body.instructions = f0B9A_parent_instructions;
      body.emit(f0B9A);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0BB4 = new(mem_ctx) ir_if(operand(r0B84).val);
      exec_list *const f0BB4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BB4->then_instructions;

         ir_variable *const r0BB5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0BB5);
         ir_expression *const r0BB6 = lshift(r0B86, body.constant(int(31)));
         ir_expression *const r0BB7 = add(r0B87, body.constant(int(896)));
         ir_expression *const r0BB8 = expr(ir_unop_i2u, r0BB7);
         ir_expression *const r0BB9 = lshift(r0BB8, body.constant(int(20)));
         ir_expression *const r0BBA = add(r0BB6, r0BB9);
         ir_expression *const r0BBB = rshift(r0B88, body.constant(int(3)));
         body.emit(assign(r0BB5, add(r0BBA, r0BBB), 0x02));

         ir_expression *const r0BBC = lshift(r0B88, body.constant(int(29)));
         body.emit(assign(r0BB5, bit_or(r0BBC, body.constant(0u)), 0x01));

         body.emit(assign(r0B85, r0BB5, 0x03));

         body.emit(assign(r0B84, body.constant(false), 0x01));


      body.instructions = f0BB4_parent_instructions;
      body.emit(f0BB4);

      /* END IF */


   body.instructions = f0B8E_parent_instructions;
   body.emit(f0B8E);

   /* END IF */

   body.emit(ret(r0B85));

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
   ir_variable *const r0BC7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0BC7);
   ir_variable *const r0BC8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BC8, add(r0BBF, r0BC2), 0x01));

   ir_variable *const r0BC9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0BCA = less(r0BC8, r0BBF);
   ir_expression *const r0BCB = expr(ir_unop_b2i, r0BCA);
   body.emit(assign(r0BC9, expr(ir_unop_i2u, r0BCB), 0x01));

   ir_variable *const r0BCC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BCC, add(r0BBE, r0BC1), 0x01));

   body.emit(assign(r0BC7, add(r0BCC, r0BC9), 0x01));

   ir_expression *const r0BCD = add(r0BBD, r0BC0);
   ir_expression *const r0BCE = less(r0BC7, r0BC9);
   ir_expression *const r0BCF = expr(ir_unop_b2i, r0BCE);
   ir_expression *const r0BD0 = expr(ir_unop_i2u, r0BCF);
   body.emit(assign(r0BC6, add(r0BCD, r0BD0), 0x01));

   ir_expression *const r0BD1 = less(r0BCC, r0BBE);
   ir_expression *const r0BD2 = expr(ir_unop_b2i, r0BD1);
   ir_expression *const r0BD3 = expr(ir_unop_i2u, r0BD2);
   body.emit(assign(r0BC6, add(r0BC6, r0BD3), 0x01));

   body.emit(assign(r0BC5, r0BC8, 0x01));

   body.emit(assign(r0BC4, r0BC7, 0x01));

   body.emit(assign(r0BC3, r0BC6, 0x01));

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

   ir_variable *const r0BD4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BD4);
   ir_variable *const r0BD5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BD5);
   ir_variable *const r0BD6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0BD6);
   ir_variable *const r0BD7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0BD7);
   ir_variable *const r0BD8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0BD8);
   ir_variable *const r0BD9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0BD9);
   ir_variable *const r0BDA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BDA);
   ir_variable *const r0BDB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BDB);
   ir_variable *const r0BDC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BDC);
   ir_variable *const r0BDD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0BDD);
   ir_variable *const r0BDE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0BDF = less(r0BD6, r0BD9);
   ir_expression *const r0BE0 = expr(ir_unop_b2i, r0BDF);
   body.emit(assign(r0BDE, expr(ir_unop_i2u, r0BE0), 0x01));

   ir_variable *const r0BE1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BE1, sub(r0BD5, r0BD8), 0x01));

   ir_expression *const r0BE2 = sub(r0BD4, r0BD7);
   ir_expression *const r0BE3 = less(r0BE1, r0BDE);
   ir_expression *const r0BE4 = expr(ir_unop_b2i, r0BE3);
   ir_expression *const r0BE5 = expr(ir_unop_i2u, r0BE4);
   body.emit(assign(r0BDD, sub(r0BE2, r0BE5), 0x01));

   ir_expression *const r0BE6 = less(r0BD5, r0BD8);
   ir_expression *const r0BE7 = expr(ir_unop_b2i, r0BE6);
   ir_expression *const r0BE8 = expr(ir_unop_i2u, r0BE7);
   body.emit(assign(r0BDD, sub(r0BDD, r0BE8), 0x01));

   body.emit(assign(r0BDC, sub(r0BD6, r0BD9), 0x01));

   body.emit(assign(r0BDB, sub(r0BE1, r0BDE), 0x01));

   body.emit(assign(r0BDA, r0BDD, 0x01));

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

   ir_variable *const r0BE9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BE9);
   ir_variable *const r0BEA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BEA);
   ir_variable *const r0BEB = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0BEB);
   ir_variable *const r0BEC = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0BED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0BED);
   ir_variable *const r0BEE = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0BEE);
   ir_variable *const r0BEF = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0BEF);
   ir_variable *const r0BF0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0BF0);
   body.emit(assign(r0BEF, body.constant(0u), 0x01));

   body.emit(assign(r0BEE, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BF2 = lequal(r0BEB, r0BE9);
   ir_if *f0BF1 = new(mem_ctx) ir_if(operand(r0BF2).val);
   exec_list *const f0BF1_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BF1->then_instructions;

      body.emit(assign(r0BEC, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BF1->else_instructions;

      body.emit(assign(r0BF0, rshift(r0BEB, body.constant(int(16))), 0x01));

      ir_variable *const r0BF3 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BF5 = lshift(r0BF0, body.constant(int(16)));
      ir_expression *const r0BF6 = lequal(r0BF5, r0BE9);
      ir_if *f0BF4 = new(mem_ctx) ir_if(operand(r0BF6).val);
      exec_list *const f0BF4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BF4->then_instructions;

         body.emit(assign(r0BF3, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BF4->else_instructions;

         ir_expression *const r0BF7 = expr(ir_binop_div, r0BE9, r0BF0);
         body.emit(assign(r0BF3, lshift(r0BF7, body.constant(int(16))), 0x01));


      body.instructions = f0BF4_parent_instructions;
      body.emit(f0BF4);

      /* END IF */

      body.emit(assign(r0BED, r0BF3, 0x01));

      ir_variable *const r0BF8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0BF8);
      ir_variable *const r0BF9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0BF9);
      ir_variable *const r0BFA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BFA);
      ir_variable *const r0BFB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BFB, bit_and(r0BEB, body.constant(65535u)), 0x01));

      ir_variable *const r0BFC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BFC, rshift(r0BEB, body.constant(int(16))), 0x01));

      ir_variable *const r0BFD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BFD, bit_and(r0BF3, body.constant(65535u)), 0x01));

      ir_variable *const r0BFE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BFE, rshift(r0BF3, body.constant(int(16))), 0x01));

      ir_variable *const r0BFF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BFF, mul(r0BFC, r0BFD), 0x01));

      ir_expression *const r0C00 = mul(r0BFB, r0BFE);
      body.emit(assign(r0BF9, add(r0C00, r0BFF), 0x01));

      ir_expression *const r0C01 = mul(r0BFC, r0BFE);
      ir_expression *const r0C02 = less(r0BF9, r0BFF);
      ir_expression *const r0C03 = expr(ir_unop_b2i, r0C02);
      ir_expression *const r0C04 = expr(ir_unop_i2u, r0C03);
      ir_expression *const r0C05 = lshift(r0C04, body.constant(int(16)));
      ir_expression *const r0C06 = rshift(r0BF9, body.constant(int(16)));
      ir_expression *const r0C07 = add(r0C05, r0C06);
      body.emit(assign(r0BF8, add(r0C01, r0C07), 0x01));

      body.emit(assign(r0BF9, lshift(r0BF9, body.constant(int(16))), 0x01));

      ir_expression *const r0C08 = mul(r0BFB, r0BFD);
      body.emit(assign(r0BFA, add(r0C08, r0BF9), 0x01));

      ir_expression *const r0C09 = less(r0BFA, r0BF9);
      ir_expression *const r0C0A = expr(ir_unop_b2i, r0C09);
      ir_expression *const r0C0B = expr(ir_unop_i2u, r0C0A);
      body.emit(assign(r0BF8, add(r0BF8, r0C0B), 0x01));

      ir_expression *const r0C0C = sub(r0BE9, r0BF8);
      ir_expression *const r0C0D = less(r0BEA, r0BFA);
      ir_expression *const r0C0E = expr(ir_unop_b2i, r0C0D);
      ir_expression *const r0C0F = expr(ir_unop_i2u, r0C0E);
      body.emit(assign(r0BEF, sub(r0C0C, r0C0F), 0x01));

      body.emit(assign(r0BEE, sub(r0BEA, r0BFA), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0C10 = new(mem_ctx) ir_loop();
      exec_list *const f0C10_parent_instructions = body.instructions;

         body.instructions = &f0C10->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0C12 = expr(ir_unop_u2i, r0BEF);
         ir_expression *const r0C13 = gequal(r0C12, body.constant(int(0)));
         ir_if *f0C11 = new(mem_ctx) ir_if(operand(r0C13).val);
         exec_list *const f0C11_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C11->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0C11_parent_instructions;
         body.emit(f0C11);

         /* END IF */

         body.emit(assign(r0BED, add(r0BED, body.constant(4294901760u)), 0x01));

         ir_variable *const r0C14 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0C15 = lshift(r0BEB, body.constant(int(16)));
         body.emit(assign(r0C14, add(r0BEE, r0C15), 0x01));

         ir_expression *const r0C16 = add(r0BEF, r0BF0);
         ir_expression *const r0C17 = less(r0C14, r0BEE);
         ir_expression *const r0C18 = expr(ir_unop_b2i, r0C17);
         ir_expression *const r0C19 = expr(ir_unop_i2u, r0C18);
         body.emit(assign(r0BEF, add(r0C16, r0C19), 0x01));

         body.emit(assign(r0BEE, r0C14, 0x01));

      /* LOOP END */

      body.instructions = f0C10_parent_instructions;
      body.emit(f0C10);

      ir_expression *const r0C1A = lshift(r0BEF, body.constant(int(16)));
      ir_expression *const r0C1B = rshift(r0BEE, body.constant(int(16)));
      body.emit(assign(r0BEF, bit_or(r0C1A, r0C1B), 0x01));

      ir_variable *const r0C1C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0C1E = lshift(r0BF0, body.constant(int(16)));
      ir_expression *const r0C1F = lequal(r0C1E, r0BEF);
      ir_if *f0C1D = new(mem_ctx) ir_if(operand(r0C1F).val);
      exec_list *const f0C1D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C1D->then_instructions;

         body.emit(assign(r0C1C, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C1D->else_instructions;

         body.emit(assign(r0C1C, expr(ir_binop_div, r0BEF, r0BF0), 0x01));


      body.instructions = f0C1D_parent_instructions;
      body.emit(f0C1D);

      /* END IF */

      body.emit(assign(r0BED, bit_or(r0BED, r0C1C), 0x01));

      body.emit(assign(r0BEC, r0BED, 0x01));


   body.instructions = f0BF1_parent_instructions;
   body.emit(f0BF1);

   /* END IF */

   body.emit(ret(r0BEC));

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

   ir_variable *const r0C20 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C20);
   ir_variable *const r0C21 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0C22 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0C22);
   body.emit(assign(r0C22, body.constant(0u), 0x01));

   ir_variable *const r0C23 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0C23, bit_and(swizzle_y(r0C20), body.constant(1048575u)), 0x01));

   ir_variable *const r0C24 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0C25 = rshift(swizzle_y(r0C20), body.constant(int(20)));
   ir_expression *const r0C26 = bit_and(r0C25, body.constant(2047u));
   body.emit(assign(r0C24, expr(ir_unop_u2i, r0C26), 0x01));

   ir_variable *const r0C27 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0C27, rshift(swizzle_y(r0C20), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C29 = equal(r0C24, body.constant(int(2047)));
   ir_if *f0C28 = new(mem_ctx) ir_if(operand(r0C29).val);
   exec_list *const f0C28_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C28->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C2B = bit_or(r0C23, swizzle_x(r0C20));
      ir_expression *const r0C2C = nequal(r0C2B, body.constant(0u));
      ir_if *f0C2A = new(mem_ctx) ir_if(operand(r0C2C).val);
      exec_list *const f0C2A_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C2A->then_instructions;

         ir_variable *const r0C2D = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0C2D, lshift(swizzle_x(r0C20), body.constant(int(12))), 0x01));

         ir_expression *const r0C2E = lshift(r0C27, body.constant(int(31)));
         ir_expression *const r0C2F = bit_or(r0C2E, body.constant(2143289344u));
         ir_expression *const r0C30 = lshift(swizzle_y(r0C20), body.constant(int(12)));
         ir_expression *const r0C31 = rshift(swizzle_x(r0C20), body.constant(int(20)));
         ir_expression *const r0C32 = bit_or(r0C30, r0C31);
         ir_expression *const r0C33 = rshift(r0C32, body.constant(int(9)));
         ir_expression *const r0C34 = bit_or(r0C2F, r0C33);
         body.emit(assign(r0C21, expr(ir_unop_bitcast_u2f, r0C34), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C2A->else_instructions;

         ir_expression *const r0C35 = lshift(r0C27, body.constant(int(31)));
         ir_expression *const r0C36 = add(r0C35, body.constant(2139095040u));
         body.emit(assign(r0C21, expr(ir_unop_bitcast_u2f, r0C36), 0x01));


      body.instructions = f0C2A_parent_instructions;
      body.emit(f0C2A);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C28->else_instructions;

      ir_variable *const r0C37 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0C37);
      ir_variable *const r0C38 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0C38);
      ir_expression *const r0C39 = lshift(r0C23, body.constant(int(10)));
      ir_expression *const r0C3A = rshift(swizzle_x(r0C20), body.constant(int(22)));
      ir_expression *const r0C3B = bit_or(r0C39, r0C3A);
      ir_expression *const r0C3C = lshift(swizzle_x(r0C20), body.constant(int(10)));
      ir_expression *const r0C3D = nequal(r0C3C, body.constant(0u));
      ir_expression *const r0C3E = expr(ir_unop_b2i, r0C3D);
      ir_expression *const r0C3F = expr(ir_unop_i2u, r0C3E);
      body.emit(assign(r0C37, bit_or(r0C3B, r0C3F), 0x01));

      body.emit(assign(r0C38, rshift(r0C23, body.constant(int(22))), 0x01));

      body.emit(assign(r0C22, r0C37, 0x01));

      /* IF CONDITION */
      ir_expression *const r0C41 = nequal(r0C24, body.constant(int(0)));
      ir_if *f0C40 = new(mem_ctx) ir_if(operand(r0C41).val);
      exec_list *const f0C40_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C40->then_instructions;

         body.emit(assign(r0C22, bit_or(r0C37, body.constant(1073741824u)), 0x01));


      body.instructions = f0C40_parent_instructions;
      body.emit(f0C40);

      /* END IF */

      ir_variable *const r0C42 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0C42, add(r0C24, body.constant(int(-897))), 0x01));

      ir_variable *const r0C43 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0C43, r0C22, 0x01));

      ir_variable *const r0C44 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0C44, body.constant(true), 0x01));

      ir_variable *const r0C45 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0C46 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0C46);
      ir_expression *const r0C47 = bit_and(r0C22, body.constant(127u));
      body.emit(assign(r0C46, expr(ir_unop_u2i, r0C47), 0x01));

      /* IF CONDITION */
      ir_expression *const r0C49 = expr(ir_unop_i2u, r0C42);
      ir_expression *const r0C4A = lequal(body.constant(253u), r0C49);
      ir_if *f0C48 = new(mem_ctx) ir_if(operand(r0C4A).val);
      exec_list *const f0C48_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C48->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C4C = less(body.constant(int(253)), r0C42);
         ir_expression *const r0C4D = equal(r0C42, body.constant(int(253)));
         ir_expression *const r0C4E = expr(ir_unop_u2i, r0C22);
         ir_expression *const r0C4F = less(r0C4E, body.constant(int(-64)));
         ir_expression *const r0C50 = logic_and(r0C4D, r0C4F);
         ir_expression *const r0C51 = logic_or(r0C4C, r0C50);
         ir_if *f0C4B = new(mem_ctx) ir_if(operand(r0C51).val);
         exec_list *const f0C4B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C4B->then_instructions;

            ir_expression *const r0C52 = lshift(r0C27, body.constant(int(31)));
            ir_expression *const r0C53 = add(r0C52, body.constant(2139095040u));
            body.emit(assign(r0C45, expr(ir_unop_bitcast_u2f, r0C53), 0x01));

            body.emit(assign(r0C44, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C4B->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0C55 = less(r0C42, body.constant(int(0)));
            ir_if *f0C54 = new(mem_ctx) ir_if(operand(r0C55).val);
            exec_list *const f0C54_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C54->then_instructions;

               ir_variable *const r0C56 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0C56, neg(r0C42), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C58 = less(r0C56, body.constant(int(32)));
               ir_if *f0C57 = new(mem_ctx) ir_if(operand(r0C58).val);
               exec_list *const f0C57_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C57->then_instructions;

                  ir_expression *const r0C59 = rshift(r0C22, r0C56);
                  ir_expression *const r0C5A = neg(r0C56);
                  ir_expression *const r0C5B = bit_and(r0C5A, body.constant(int(31)));
                  ir_expression *const r0C5C = lshift(r0C22, r0C5B);
                  ir_expression *const r0C5D = nequal(r0C5C, body.constant(0u));
                  ir_expression *const r0C5E = expr(ir_unop_b2i, r0C5D);
                  ir_expression *const r0C5F = expr(ir_unop_i2u, r0C5E);
                  body.emit(assign(r0C43, bit_or(r0C59, r0C5F), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0C57->else_instructions;

                  ir_expression *const r0C60 = nequal(r0C43, body.constant(0u));
                  ir_expression *const r0C61 = expr(ir_unop_b2i, r0C60);
                  body.emit(assign(r0C43, expr(ir_unop_i2u, r0C61), 0x01));


               body.instructions = f0C57_parent_instructions;
               body.emit(f0C57);

               /* END IF */

               body.emit(assign(r0C42, body.constant(int(0)), 0x01));

               ir_expression *const r0C62 = expr(ir_unop_u2i, r0C43);
               body.emit(assign(r0C46, bit_and(r0C62, body.constant(int(127))), 0x01));


            body.instructions = f0C54_parent_instructions;
            body.emit(f0C54);

            /* END IF */


         body.instructions = f0C4B_parent_instructions;
         body.emit(f0C4B);

         /* END IF */


      body.instructions = f0C48_parent_instructions;
      body.emit(f0C48);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C63 = new(mem_ctx) ir_if(operand(r0C44).val);
      exec_list *const f0C63_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C63->then_instructions;

         ir_expression *const r0C64 = add(r0C43, body.constant(64u));
         body.emit(assign(r0C43, rshift(r0C64, body.constant(int(7))), 0x01));

         ir_expression *const r0C65 = bit_xor(r0C46, body.constant(int(64)));
         ir_expression *const r0C66 = equal(r0C65, body.constant(int(0)));
         ir_expression *const r0C67 = expr(ir_unop_b2i, r0C66);
         ir_expression *const r0C68 = expr(ir_unop_i2u, r0C67);
         ir_expression *const r0C69 = expr(ir_unop_bit_not, r0C68);
         body.emit(assign(r0C43, bit_and(r0C43, r0C69), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C6B = equal(r0C43, body.constant(0u));
         ir_if *f0C6A = new(mem_ctx) ir_if(operand(r0C6B).val);
         exec_list *const f0C6A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C6A->then_instructions;

            body.emit(assign(r0C42, body.constant(int(0)), 0x01));


         body.instructions = f0C6A_parent_instructions;
         body.emit(f0C6A);

         /* END IF */

         ir_expression *const r0C6C = lshift(r0C27, body.constant(int(31)));
         ir_expression *const r0C6D = expr(ir_unop_i2u, r0C42);
         ir_expression *const r0C6E = lshift(r0C6D, body.constant(int(23)));
         ir_expression *const r0C6F = add(r0C6C, r0C6E);
         ir_expression *const r0C70 = add(r0C6F, r0C43);
         body.emit(assign(r0C45, expr(ir_unop_bitcast_u2f, r0C70), 0x01));

         body.emit(assign(r0C44, body.constant(false), 0x01));


      body.instructions = f0C63_parent_instructions;
      body.emit(f0C63);

      /* END IF */

      body.emit(assign(r0C21, r0C45, 0x01));


   body.instructions = f0C28_parent_instructions;
   body.emit(f0C28);

   /* END IF */

   ir_variable *const r0C71 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C71, body.constant(true), 0x01));

   ir_variable *const r0C72 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C73 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C73);
   ir_variable *const r0C74 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C74);
   ir_variable *const r0C75 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C75);
   ir_variable *const r0C76 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C77 = expr(ir_unop_sqrt, r0C21);
   body.emit(assign(r0C76, expr(ir_unop_bitcast_f2u, r0C77), 0x01));

   ir_variable *const r0C78 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C78, bit_and(r0C76, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C75, r0C78, 0x01));

   ir_variable *const r0C79 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C7A = rshift(r0C76, body.constant(int(23)));
   ir_expression *const r0C7B = bit_and(r0C7A, body.constant(255u));
   body.emit(assign(r0C79, expr(ir_unop_u2i, r0C7B), 0x01));

   body.emit(assign(r0C74, r0C79, 0x01));

   body.emit(assign(r0C73, rshift(r0C76, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C7D = equal(r0C79, body.constant(int(255)));
   ir_if *f0C7C = new(mem_ctx) ir_if(operand(r0C7D).val);
   exec_list *const f0C7C_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C7C->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C7F = nequal(r0C78, body.constant(0u));
      ir_if *f0C7E = new(mem_ctx) ir_if(operand(r0C7F).val);
      exec_list *const f0C7E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C7E->then_instructions;

         ir_variable *const r0C80 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C80, lshift(r0C76, body.constant(int(9))), 0x01));

         ir_variable *const r0C81 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C82 = lshift(r0C80, body.constant(int(20)));
         body.emit(assign(r0C81, bit_or(r0C82, body.constant(0u)), 0x01));

         ir_expression *const r0C83 = rshift(r0C80, body.constant(int(12)));
         ir_expression *const r0C84 = lshift(r0C73, body.constant(int(31)));
         ir_expression *const r0C85 = bit_or(r0C84, body.constant(2146959360u));
         body.emit(assign(r0C81, bit_or(r0C83, r0C85), 0x02));

         body.emit(assign(r0C72, r0C81, 0x03));

         body.emit(assign(r0C71, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C7E->else_instructions;

         ir_variable *const r0C86 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C86);
         ir_expression *const r0C87 = lshift(r0C73, body.constant(int(31)));
         body.emit(assign(r0C86, add(r0C87, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C86, body.constant(0u), 0x01));

         body.emit(assign(r0C72, r0C86, 0x03));

         body.emit(assign(r0C71, body.constant(false), 0x01));


      body.instructions = f0C7E_parent_instructions;
      body.emit(f0C7E);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C7C->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C89 = equal(r0C79, body.constant(int(0)));
      ir_if *f0C88 = new(mem_ctx) ir_if(operand(r0C89).val);
      exec_list *const f0C88_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C88->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C8B = equal(r0C78, body.constant(0u));
         ir_if *f0C8A = new(mem_ctx) ir_if(operand(r0C8B).val);
         exec_list *const f0C8A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C8A->then_instructions;

            ir_variable *const r0C8C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C8C);
            body.emit(assign(r0C8C, lshift(r0C73, body.constant(int(31))), 0x02));

            body.emit(assign(r0C8C, body.constant(0u), 0x01));

            body.emit(assign(r0C72, r0C8C, 0x03));

            body.emit(assign(r0C71, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C8A->else_instructions;

            ir_variable *const r0C8D = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0C8D, r0C78, 0x01));

            ir_variable *const r0C8E = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0C8F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0C8F);
            /* IF CONDITION */
            ir_expression *const r0C91 = equal(r0C78, body.constant(0u));
            ir_if *f0C90 = new(mem_ctx) ir_if(operand(r0C91).val);
            exec_list *const f0C90_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C90->then_instructions;

               body.emit(assign(r0C8E, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0C90->else_instructions;

               body.emit(assign(r0C8F, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C93 = bit_and(r0C78, body.constant(4294901760u));
               ir_expression *const r0C94 = equal(r0C93, body.constant(0u));
               ir_if *f0C92 = new(mem_ctx) ir_if(operand(r0C94).val);
               exec_list *const f0C92_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C92->then_instructions;

                  body.emit(assign(r0C8F, body.constant(int(16)), 0x01));

                  body.emit(assign(r0C8D, lshift(r0C78, body.constant(int(16))), 0x01));


               body.instructions = f0C92_parent_instructions;
               body.emit(f0C92);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C96 = bit_and(r0C8D, body.constant(4278190080u));
               ir_expression *const r0C97 = equal(r0C96, body.constant(0u));
               ir_if *f0C95 = new(mem_ctx) ir_if(operand(r0C97).val);
               exec_list *const f0C95_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C95->then_instructions;

                  body.emit(assign(r0C8F, add(r0C8F, body.constant(int(8))), 0x01));

                  body.emit(assign(r0C8D, lshift(r0C8D, body.constant(int(8))), 0x01));


               body.instructions = f0C95_parent_instructions;
               body.emit(f0C95);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C99 = bit_and(r0C8D, body.constant(4026531840u));
               ir_expression *const r0C9A = equal(r0C99, body.constant(0u));
               ir_if *f0C98 = new(mem_ctx) ir_if(operand(r0C9A).val);
               exec_list *const f0C98_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C98->then_instructions;

                  body.emit(assign(r0C8F, add(r0C8F, body.constant(int(4))), 0x01));

                  body.emit(assign(r0C8D, lshift(r0C8D, body.constant(int(4))), 0x01));


               body.instructions = f0C98_parent_instructions;
               body.emit(f0C98);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C9C = bit_and(r0C8D, body.constant(3221225472u));
               ir_expression *const r0C9D = equal(r0C9C, body.constant(0u));
               ir_if *f0C9B = new(mem_ctx) ir_if(operand(r0C9D).val);
               exec_list *const f0C9B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C9B->then_instructions;

                  body.emit(assign(r0C8F, add(r0C8F, body.constant(int(2))), 0x01));

                  body.emit(assign(r0C8D, lshift(r0C8D, body.constant(int(2))), 0x01));


               body.instructions = f0C9B_parent_instructions;
               body.emit(f0C9B);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C9F = bit_and(r0C8D, body.constant(2147483648u));
               ir_expression *const r0CA0 = equal(r0C9F, body.constant(0u));
               ir_if *f0C9E = new(mem_ctx) ir_if(operand(r0CA0).val);
               exec_list *const f0C9E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C9E->then_instructions;

                  body.emit(assign(r0C8F, add(r0C8F, body.constant(int(1))), 0x01));


               body.instructions = f0C9E_parent_instructions;
               body.emit(f0C9E);

               /* END IF */

               body.emit(assign(r0C8E, r0C8F, 0x01));


            body.instructions = f0C90_parent_instructions;
            body.emit(f0C90);

            /* END IF */

            ir_variable *const r0CA1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0CA1, add(r0C8E, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C75, lshift(r0C78, r0CA1), 0x01));

            body.emit(assign(r0C74, sub(body.constant(int(1)), r0CA1), 0x01));

            body.emit(assign(r0C74, add(r0C74, body.constant(int(-1))), 0x01));


         body.instructions = f0C8A_parent_instructions;
         body.emit(f0C8A);

         /* END IF */


      body.instructions = f0C88_parent_instructions;
      body.emit(f0C88);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0CA2 = new(mem_ctx) ir_if(operand(r0C71).val);
      exec_list *const f0CA2_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CA2->then_instructions;

         ir_variable *const r0CA3 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0CA3);
         ir_expression *const r0CA4 = lshift(r0C73, body.constant(int(31)));
         ir_expression *const r0CA5 = add(r0C74, body.constant(int(896)));
         ir_expression *const r0CA6 = expr(ir_unop_i2u, r0CA5);
         ir_expression *const r0CA7 = lshift(r0CA6, body.constant(int(20)));
         ir_expression *const r0CA8 = add(r0CA4, r0CA7);
         ir_expression *const r0CA9 = rshift(r0C75, body.constant(int(3)));
         body.emit(assign(r0CA3, add(r0CA8, r0CA9), 0x02));

         ir_expression *const r0CAA = lshift(r0C75, body.constant(int(29)));
         body.emit(assign(r0CA3, bit_or(r0CAA, body.constant(0u)), 0x01));

         body.emit(assign(r0C72, r0CA3, 0x03));

         body.emit(assign(r0C71, body.constant(false), 0x01));


      body.instructions = f0CA2_parent_instructions;
      body.emit(f0CA2);

      /* END IF */


   body.instructions = f0C7C_parent_instructions;
   body.emit(f0C7C);

   /* END IF */

   body.emit(ret(r0C72));

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

   ir_variable *const r0CAB = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CAB);
   ir_variable *const r0CAC = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CAD = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0CAE = rshift(swizzle_y(r0CAB), body.constant(int(20)));
   ir_expression *const r0CAF = bit_and(r0CAE, body.constant(2047u));
   ir_expression *const r0CB0 = expr(ir_unop_u2i, r0CAF);
   body.emit(assign(r0CAD, add(r0CB0, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CB2 = less(r0CAD, body.constant(int(0)));
   ir_if *f0CB1 = new(mem_ctx) ir_if(operand(r0CB2).val);
   exec_list *const f0CB1_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CB1->then_instructions;

      body.emit(assign(r0CAC, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CB1->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CB4 = greater(r0CAD, body.constant(int(52)));
      ir_if *f0CB3 = new(mem_ctx) ir_if(operand(r0CB4).val);
      exec_list *const f0CB3_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CB3->then_instructions;

         body.emit(assign(r0CAC, r0CAB, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CB3->else_instructions;

         ir_variable *const r0CB5 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0CB5, sub(body.constant(int(52)), r0CAD), 0x01));

         ir_variable *const r0CB6 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0CB8 = gequal(r0CB5, body.constant(int(32)));
         ir_if *f0CB7 = new(mem_ctx) ir_if(operand(r0CB8).val);
         exec_list *const f0CB7_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CB7->then_instructions;

            body.emit(assign(r0CB6, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CB7->else_instructions;

            body.emit(assign(r0CB6, lshift(body.constant(4294967295u), r0CB5), 0x01));


         body.instructions = f0CB7_parent_instructions;
         body.emit(f0CB7);

         /* END IF */

         ir_variable *const r0CB9 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0CBB = less(r0CB5, body.constant(int(33)));
         ir_if *f0CBA = new(mem_ctx) ir_if(operand(r0CBB).val);
         exec_list *const f0CBA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CBA->then_instructions;

            body.emit(assign(r0CB9, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CBA->else_instructions;

            ir_expression *const r0CBC = add(r0CB5, body.constant(int(-32)));
            body.emit(assign(r0CB9, lshift(body.constant(4294967295u), r0CBC), 0x01));


         body.instructions = f0CBA_parent_instructions;
         body.emit(f0CBA);

         /* END IF */

         ir_variable *const r0CBD = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0CBD, bit_and(r0CB6, swizzle_x(r0CAB)), 0x01));

         body.emit(assign(r0CBD, bit_and(r0CB9, swizzle_y(r0CAB)), 0x02));

         body.emit(assign(r0CAC, r0CBD, 0x03));


      body.instructions = f0CB3_parent_instructions;
      body.emit(f0CB3);

      /* END IF */


   body.instructions = f0CB1_parent_instructions;
   body.emit(f0CB1);

   /* END IF */

   body.emit(ret(r0CAC));

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

   ir_variable *const r0CBE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CBE);
   ir_variable *const r0CBF = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0CBF, body.constant(true), 0x01));

   ir_variable *const r0CC0 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CC1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0CC1);
   ir_variable *const r0CC2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0CC2);
   ir_variable *const r0CC3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0CC4 = rshift(swizzle_y(r0CBE), body.constant(int(20)));
   ir_expression *const r0CC5 = bit_and(r0CC4, body.constant(2047u));
   ir_expression *const r0CC6 = expr(ir_unop_u2i, r0CC5);
   body.emit(assign(r0CC3, add(r0CC6, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0CC2, swizzle_y(r0CBE), 0x01));

   body.emit(assign(r0CC1, swizzle_x(r0CBE), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CC8 = less(r0CC3, body.constant(int(20)));
   ir_if *f0CC7 = new(mem_ctx) ir_if(operand(r0CC8).val);
   exec_list *const f0CC7_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CC7->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CCA = less(r0CC3, body.constant(int(0)));
      ir_if *f0CC9 = new(mem_ctx) ir_if(operand(r0CCA).val);
      exec_list *const f0CC9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CC9->then_instructions;

         body.emit(assign(r0CC2, bit_and(swizzle_y(r0CBE), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CCC = equal(r0CC3, body.constant(int(-1)));
         ir_expression *const r0CCD = nequal(swizzle_x(r0CBE), body.constant(0u));
         ir_expression *const r0CCE = logic_and(r0CCC, r0CCD);
         ir_if *f0CCB = new(mem_ctx) ir_if(operand(r0CCE).val);
         exec_list *const f0CCB_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CCB->then_instructions;

            body.emit(assign(r0CC2, bit_or(r0CC2, body.constant(1072693248u)), 0x01));


         body.instructions = f0CCB_parent_instructions;
         body.emit(f0CCB);

         /* END IF */

         body.emit(assign(r0CC1, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CC9->else_instructions;

         ir_variable *const r0CCF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0CCF, rshift(body.constant(1048575u), r0CC3), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CD1 = bit_and(r0CC2, r0CCF);
         ir_expression *const r0CD2 = equal(r0CD1, body.constant(0u));
         ir_expression *const r0CD3 = equal(r0CC1, body.constant(0u));
         ir_expression *const r0CD4 = logic_and(r0CD2, r0CD3);
         ir_if *f0CD0 = new(mem_ctx) ir_if(operand(r0CD4).val);
         exec_list *const f0CD0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CD0->then_instructions;

            body.emit(assign(r0CC0, r0CBE, 0x03));

            body.emit(assign(r0CBF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CD0->else_instructions;

            ir_expression *const r0CD5 = rshift(body.constant(524288u), r0CC3);
            body.emit(assign(r0CC2, add(r0CC2, r0CD5), 0x01));

            ir_expression *const r0CD6 = expr(ir_unop_bit_not, r0CCF);
            body.emit(assign(r0CC2, bit_and(r0CC2, r0CD6), 0x01));

            body.emit(assign(r0CC1, body.constant(0u), 0x01));


         body.instructions = f0CD0_parent_instructions;
         body.emit(f0CD0);

         /* END IF */


      body.instructions = f0CC9_parent_instructions;
      body.emit(f0CC9);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CC7->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CD8 = greater(r0CC3, body.constant(int(51)));
      ir_expression *const r0CD9 = equal(r0CC3, body.constant(int(1024)));
      ir_expression *const r0CDA = logic_or(r0CD8, r0CD9);
      ir_if *f0CD7 = new(mem_ctx) ir_if(operand(r0CDA).val);
      exec_list *const f0CD7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CD7->then_instructions;

         body.emit(assign(r0CC0, r0CBE, 0x03));

         body.emit(assign(r0CBF, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CD7->else_instructions;

         ir_variable *const r0CDB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0CDC = add(r0CC3, body.constant(int(-20)));
         body.emit(assign(r0CDB, rshift(body.constant(4294967295u), r0CDC), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CDE = bit_and(r0CC1, r0CDB);
         ir_expression *const r0CDF = equal(r0CDE, body.constant(0u));
         ir_if *f0CDD = new(mem_ctx) ir_if(operand(r0CDF).val);
         exec_list *const f0CDD_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CDD->then_instructions;

            body.emit(assign(r0CC0, r0CBE, 0x03));

            body.emit(assign(r0CBF, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CDD->else_instructions;

            ir_variable *const r0CE0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0CE1 = sub(body.constant(int(51)), r0CC3);
            ir_expression *const r0CE2 = lshift(body.constant(1u), r0CE1);
            body.emit(assign(r0CE0, add(r0CC1, r0CE2), 0x01));

            /* IF CONDITION */
            ir_expression *const r0CE4 = less(r0CE0, r0CC1);
            ir_if *f0CE3 = new(mem_ctx) ir_if(operand(r0CE4).val);
            exec_list *const f0CE3_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0CE3->then_instructions;

               body.emit(assign(r0CC2, add(r0CC2, body.constant(1u)), 0x01));


            body.instructions = f0CE3_parent_instructions;
            body.emit(f0CE3);

            /* END IF */

            ir_expression *const r0CE5 = expr(ir_unop_bit_not, r0CDB);
            body.emit(assign(r0CC1, bit_and(r0CE0, r0CE5), 0x01));


         body.instructions = f0CDD_parent_instructions;
         body.emit(f0CDD);

         /* END IF */


      body.instructions = f0CD7_parent_instructions;
      body.emit(f0CD7);

      /* END IF */


   body.instructions = f0CC7_parent_instructions;
   body.emit(f0CC7);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0CE6 = new(mem_ctx) ir_if(operand(r0CBF).val);
   exec_list *const f0CE6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CE6->then_instructions;

      body.emit(assign(r0CBE, r0CC1, 0x01));

      body.emit(assign(r0CBE, r0CC2, 0x02));

      body.emit(assign(r0CC0, r0CBE, 0x03));

      body.emit(assign(r0CBF, body.constant(false), 0x01));


   body.instructions = f0CE6_parent_instructions;
   body.emit(f0CE6);

   /* END IF */

   body.emit(ret(r0CC0));

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

   ir_variable *const r0CE7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CE7);
   ir_variable *const r0CE8 = body.make_temp(glsl_type::uint_type, "z1Ptr");
   body.emit(assign(r0CE8, sub(body.constant(2406117202u), swizzle_x(r0CE7)), 0x01));

   ir_expression *const r0CE9 = sub(body.constant(3217938081u), swizzle_y(r0CE7));
   ir_expression *const r0CEA = less(body.constant(2406117202u), swizzle_x(r0CE7));
   ir_expression *const r0CEB = expr(ir_unop_b2i, r0CEA);
   ir_expression *const r0CEC = expr(ir_unop_i2u, r0CEB);
   body.emit(assign(r0CE7, sub(r0CE9, r0CEC), 0x02));

   body.emit(assign(r0CE7, r0CE8, 0x01));

   ir_variable *const r0CED = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0CED);
   ir_variable *const r0CEE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0CEE);
   ir_expression *const r0CEF = lshift(swizzle_y(r0CE7), body.constant(int(31)));
   ir_expression *const r0CF0 = rshift(r0CE8, body.constant(int(1)));
   body.emit(assign(r0CED, bit_or(r0CEF, r0CF0), 0x01));

   body.emit(assign(r0CEE, rshift(swizzle_y(r0CE7), body.constant(int(1))), 0x01));

   body.emit(assign(r0CE7, r0CEE, 0x02));

   body.emit(assign(r0CE7, r0CED, 0x01));

   ir_variable *const r0CF1 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0CF1, body.constant(true), 0x01));

   ir_variable *const r0CF2 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0CF3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0CF3);
   ir_variable *const r0CF4 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r0CF4);
   ir_variable *const r0CF5 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0CF5);
   ir_variable *const r0CF6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r0CF6);
   ir_variable *const r0CF7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r0CF7);
   ir_variable *const r0CF8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0CF8);
   ir_variable *const r0CF9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0CF9);
   ir_variable *const r0CFA = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r0CFA);
   ir_variable *const r0CFB = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r0CFB);
   ir_variable *const r0CFC = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0CFC);
   ir_variable *const r0CFD = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0CFD);
   body.emit(assign(r0CFD, body.constant(0u), 0x01));

   body.emit(assign(r0CFC, body.constant(0u), 0x01));

   body.emit(assign(r0CFB, body.constant(0u), 0x01));

   ir_variable *const r0CFE = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0CFE, swizzle_x(r0CE7), 0x01));

   body.emit(assign(r0CF9, r0CFE, 0x01));

   ir_variable *const r0CFF = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0CFF, bit_and(r0CEE, body.constant(1048575u)), 0x01));

   body.emit(assign(r0CF8, r0CFF, 0x01));

   ir_variable *const r0D00 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0D00, swizzle_x(r0CE7), 0x01));

   body.emit(assign(r0CF7, r0D00, 0x01));

   ir_variable *const r0D01 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0D01, bit_and(r0CEE, body.constant(1048575u)), 0x01));

   body.emit(assign(r0CF6, r0D01, 0x01));

   ir_variable *const r0D02 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0D03 = rshift(r0CEE, body.constant(int(20)));
   ir_expression *const r0D04 = bit_and(r0D03, body.constant(2047u));
   body.emit(assign(r0D02, expr(ir_unop_u2i, r0D04), 0x01));

   body.emit(assign(r0CF5, r0D02, 0x01));

   ir_variable *const r0D05 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0D06 = rshift(r0CEE, body.constant(int(20)));
   ir_expression *const r0D07 = bit_and(r0D06, body.constant(2047u));
   body.emit(assign(r0D05, expr(ir_unop_u2i, r0D07), 0x01));

   body.emit(assign(r0CF4, r0D05, 0x01));

   ir_expression *const r0D08 = rshift(r0CEE, body.constant(int(31)));
   ir_expression *const r0D09 = rshift(r0CEE, body.constant(int(31)));
   body.emit(assign(r0CF3, bit_xor(r0D08, r0D09), 0x01));

   /* IF CONDITION */
   ir_expression *const r0D0B = equal(r0D02, body.constant(int(2047)));
   ir_if *f0D0A = new(mem_ctx) ir_if(operand(r0D0B).val);
   exec_list *const f0D0A_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D0A->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0D0D = bit_or(r0CFF, r0CED);
      ir_expression *const r0D0E = nequal(r0D0D, body.constant(0u));
      ir_expression *const r0D0F = equal(r0D05, body.constant(int(2047)));
      ir_expression *const r0D10 = bit_or(r0D01, r0CED);
      ir_expression *const r0D11 = nequal(r0D10, body.constant(0u));
      ir_expression *const r0D12 = logic_and(r0D0F, r0D11);
      ir_expression *const r0D13 = logic_or(r0D0E, r0D12);
      ir_if *f0D0C = new(mem_ctx) ir_if(operand(r0D13).val);
      exec_list *const f0D0C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D0C->then_instructions;

         ir_variable *const r0D14 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r0D14, swizzle_x(r0CE7), 0x01));

         ir_variable *const r0D15 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r0D15, swizzle_x(r0CE7), 0x01));

         ir_variable *const r0D16 = body.make_temp(glsl_type::uvec2_type, "return_value");
         ir_variable *const r0D17 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
         ir_expression *const r0D18 = lshift(r0CEE, body.constant(int(1)));
         ir_expression *const r0D19 = lequal(body.constant(4292870144u), r0D18);
         ir_expression *const r0D1A = nequal(r0CED, body.constant(0u));
         ir_expression *const r0D1B = bit_and(r0CEE, body.constant(1048575u));
         ir_expression *const r0D1C = nequal(r0D1B, body.constant(0u));
         ir_expression *const r0D1D = logic_or(r0D1A, r0D1C);
         body.emit(assign(r0D17, logic_and(r0D19, r0D1D), 0x01));

         body.emit(assign(r0D14, bit_or(r0CEE, body.constant(524288u)), 0x02));

         body.emit(assign(r0D15, bit_or(r0CEE, body.constant(524288u)), 0x02));

         /* IF CONDITION */
         ir_expression *const r0D1F = lshift(r0CEE, body.constant(int(1)));
         ir_expression *const r0D20 = lequal(body.constant(4292870144u), r0D1F);
         ir_expression *const r0D21 = nequal(r0CED, body.constant(0u));
         ir_expression *const r0D22 = bit_and(r0CEE, body.constant(1048575u));
         ir_expression *const r0D23 = nequal(r0D22, body.constant(0u));
         ir_expression *const r0D24 = logic_or(r0D21, r0D23);
         ir_expression *const r0D25 = logic_and(r0D20, r0D24);
         ir_if *f0D1E = new(mem_ctx) ir_if(operand(r0D25).val);
         exec_list *const f0D1E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D1E->then_instructions;

            ir_variable *const r0D26 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
            /* IF CONDITION */
            ir_if *f0D27 = new(mem_ctx) ir_if(operand(r0D17).val);
            exec_list *const f0D27_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D27->then_instructions;

               body.emit(assign(r0D26, r0D15, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0D27->else_instructions;

               body.emit(assign(r0D26, r0D14, 0x03));


            body.instructions = f0D27_parent_instructions;
            body.emit(f0D27);

            /* END IF */

            body.emit(assign(r0D16, r0D26, 0x03));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D1E->else_instructions;

            body.emit(assign(r0D16, r0D15, 0x03));


         body.instructions = f0D1E_parent_instructions;
         body.emit(f0D1E);

         /* END IF */

         body.emit(assign(r0CF2, r0D16, 0x03));

         body.emit(assign(r0CF1, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D0C->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0D29 = expr(ir_unop_i2u, r0D05);
         ir_expression *const r0D2A = bit_or(r0D29, r0D01);
         ir_expression *const r0D2B = bit_or(r0D2A, r0CED);
         ir_expression *const r0D2C = equal(r0D2B, body.constant(0u));
         ir_if *f0D28 = new(mem_ctx) ir_if(operand(r0D2C).val);
         exec_list *const f0D28_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D28->then_instructions;

            ir_constant_data r0D2D_data;
            memset(&r0D2D_data, 0, sizeof(ir_constant_data));
            r0D2D_data.u[0] = 4294967295;
            r0D2D_data.u[1] = 4294967295;
            ir_constant *const r0D2D = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0D2D_data);
            body.emit(assign(r0CF2, r0D2D, 0x03));

            body.emit(assign(r0CF1, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D28->else_instructions;

            ir_variable *const r0D2E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0D2E);
            ir_expression *const r0D2F = lshift(r0CF3, body.constant(int(31)));
            body.emit(assign(r0D2E, add(r0D2F, body.constant(2146435072u)), 0x02));

            body.emit(assign(r0D2E, body.constant(0u), 0x01));

            body.emit(assign(r0CF2, r0D2E, 0x03));

            body.emit(assign(r0CF1, body.constant(false), 0x01));


         body.instructions = f0D28_parent_instructions;
         body.emit(f0D28);

         /* END IF */


      body.instructions = f0D0C_parent_instructions;
      body.emit(f0D0C);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0D0A->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0D31 = equal(r0D05, body.constant(int(2047)));
      ir_if *f0D30 = new(mem_ctx) ir_if(operand(r0D31).val);
      exec_list *const f0D30_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D30->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0D33 = bit_or(r0D01, r0CED);
         ir_expression *const r0D34 = nequal(r0D33, body.constant(0u));
         ir_if *f0D32 = new(mem_ctx) ir_if(operand(r0D34).val);
         exec_list *const f0D32_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D32->then_instructions;

            ir_variable *const r0D35 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0D35, swizzle_x(r0CE7), 0x01));

            ir_variable *const r0D36 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0D36, swizzle_x(r0CE7), 0x01));

            ir_variable *const r0D37 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0D38 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
            ir_expression *const r0D39 = lshift(r0CEE, body.constant(int(1)));
            ir_expression *const r0D3A = lequal(body.constant(4292870144u), r0D39);
            ir_expression *const r0D3B = nequal(r0CED, body.constant(0u));
            ir_expression *const r0D3C = bit_and(r0CEE, body.constant(1048575u));
            ir_expression *const r0D3D = nequal(r0D3C, body.constant(0u));
            ir_expression *const r0D3E = logic_or(r0D3B, r0D3D);
            body.emit(assign(r0D38, logic_and(r0D3A, r0D3E), 0x01));

            body.emit(assign(r0D35, bit_or(r0CEE, body.constant(524288u)), 0x02));

            body.emit(assign(r0D36, bit_or(r0CEE, body.constant(524288u)), 0x02));

            /* IF CONDITION */
            ir_expression *const r0D40 = lshift(r0CEE, body.constant(int(1)));
            ir_expression *const r0D41 = lequal(body.constant(4292870144u), r0D40);
            ir_expression *const r0D42 = nequal(r0CED, body.constant(0u));
            ir_expression *const r0D43 = bit_and(r0CEE, body.constant(1048575u));
            ir_expression *const r0D44 = nequal(r0D43, body.constant(0u));
            ir_expression *const r0D45 = logic_or(r0D42, r0D44);
            ir_expression *const r0D46 = logic_and(r0D41, r0D45);
            ir_if *f0D3F = new(mem_ctx) ir_if(operand(r0D46).val);
            exec_list *const f0D3F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D3F->then_instructions;

               ir_variable *const r0D47 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
               /* IF CONDITION */
               ir_if *f0D48 = new(mem_ctx) ir_if(operand(r0D38).val);
               exec_list *const f0D48_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D48->then_instructions;

                  body.emit(assign(r0D47, r0D36, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0D48->else_instructions;

                  body.emit(assign(r0D47, r0D35, 0x03));


               body.instructions = f0D48_parent_instructions;
               body.emit(f0D48);

               /* END IF */

               body.emit(assign(r0D37, r0D47, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0D3F->else_instructions;

               body.emit(assign(r0D37, r0D36, 0x03));


            body.instructions = f0D3F_parent_instructions;
            body.emit(f0D3F);

            /* END IF */

            body.emit(assign(r0CF2, r0D37, 0x03));

            body.emit(assign(r0CF1, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D32->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0D4A = expr(ir_unop_i2u, r0D02);
            ir_expression *const r0D4B = bit_or(r0D4A, r0CFF);
            ir_expression *const r0D4C = bit_or(r0D4B, r0CED);
            ir_expression *const r0D4D = equal(r0D4C, body.constant(0u));
            ir_if *f0D49 = new(mem_ctx) ir_if(operand(r0D4D).val);
            exec_list *const f0D49_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D49->then_instructions;

               ir_constant_data r0D4E_data;
               memset(&r0D4E_data, 0, sizeof(ir_constant_data));
               r0D4E_data.u[0] = 4294967295;
               r0D4E_data.u[1] = 4294967295;
               ir_constant *const r0D4E = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r0D4E_data);
               body.emit(assign(r0CF2, r0D4E, 0x03));

               body.emit(assign(r0CF1, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0D49->else_instructions;

               ir_variable *const r0D4F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0D4F);
               ir_expression *const r0D50 = lshift(r0CF3, body.constant(int(31)));
               body.emit(assign(r0D4F, add(r0D50, body.constant(2146435072u)), 0x02));

               body.emit(assign(r0D4F, body.constant(0u), 0x01));

               body.emit(assign(r0CF2, r0D4F, 0x03));

               body.emit(assign(r0CF1, body.constant(false), 0x01));


            body.instructions = f0D49_parent_instructions;
            body.emit(f0D49);

            /* END IF */


         body.instructions = f0D32_parent_instructions;
         body.emit(f0D32);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D30->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0D52 = equal(r0D02, body.constant(int(0)));
         ir_if *f0D51 = new(mem_ctx) ir_if(operand(r0D52).val);
         exec_list *const f0D51_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D51->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0D54 = bit_or(r0CFF, r0CED);
            ir_expression *const r0D55 = equal(r0D54, body.constant(0u));
            ir_if *f0D53 = new(mem_ctx) ir_if(operand(r0D55).val);
            exec_list *const f0D53_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D53->then_instructions;

               ir_variable *const r0D56 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0D56);
               body.emit(assign(r0D56, lshift(r0CF3, body.constant(int(31))), 0x02));

               body.emit(assign(r0D56, body.constant(0u), 0x01));

               body.emit(assign(r0CF2, r0D56, 0x03));

               body.emit(assign(r0CF1, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0D53->else_instructions;

               ir_variable *const r0D57 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r0D57, r0D02, 0x01));

               ir_variable *const r0D58 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r0D58, r0CFF, 0x01));

               ir_variable *const r0D59 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r0D59, r0CFE, 0x01));

               ir_variable *const r0D5A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0D5A);
               /* IF CONDITION */
               ir_expression *const r0D5C = equal(r0CFF, body.constant(0u));
               ir_if *f0D5B = new(mem_ctx) ir_if(operand(r0D5C).val);
               exec_list *const f0D5B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D5B->then_instructions;

                  ir_variable *const r0D5D = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r0D5D, r0CFE, 0x01));

                  ir_variable *const r0D5E = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r0D5F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0D5F);
                  /* IF CONDITION */
                  ir_expression *const r0D61 = equal(r0CED, body.constant(0u));
                  ir_if *f0D60 = new(mem_ctx) ir_if(operand(r0D61).val);
                  exec_list *const f0D60_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0D60->then_instructions;

                     body.emit(assign(r0D5E, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0D60->else_instructions;

                     body.emit(assign(r0D5F, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0D63 = bit_and(r0CED, body.constant(4294901760u));
                     ir_expression *const r0D64 = equal(r0D63, body.constant(0u));
                     ir_if *f0D62 = new(mem_ctx) ir_if(operand(r0D64).val);
                     exec_list *const f0D62_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D62->then_instructions;

                        body.emit(assign(r0D5F, body.constant(int(16)), 0x01));

                        body.emit(assign(r0D5D, lshift(r0CED, body.constant(int(16))), 0x01));


                     body.instructions = f0D62_parent_instructions;
                     body.emit(f0D62);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0D66 = bit_and(r0D5D, body.constant(4278190080u));
                     ir_expression *const r0D67 = equal(r0D66, body.constant(0u));
                     ir_if *f0D65 = new(mem_ctx) ir_if(operand(r0D67).val);
                     exec_list *const f0D65_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D65->then_instructions;

                        body.emit(assign(r0D5F, add(r0D5F, body.constant(int(8))), 0x01));

                        body.emit(assign(r0D5D, lshift(r0D5D, body.constant(int(8))), 0x01));


                     body.instructions = f0D65_parent_instructions;
                     body.emit(f0D65);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0D69 = bit_and(r0D5D, body.constant(4026531840u));
                     ir_expression *const r0D6A = equal(r0D69, body.constant(0u));
                     ir_if *f0D68 = new(mem_ctx) ir_if(operand(r0D6A).val);
                     exec_list *const f0D68_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D68->then_instructions;

                        body.emit(assign(r0D5F, add(r0D5F, body.constant(int(4))), 0x01));

                        body.emit(assign(r0D5D, lshift(r0D5D, body.constant(int(4))), 0x01));


                     body.instructions = f0D68_parent_instructions;
                     body.emit(f0D68);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0D6C = bit_and(r0D5D, body.constant(3221225472u));
                     ir_expression *const r0D6D = equal(r0D6C, body.constant(0u));
                     ir_if *f0D6B = new(mem_ctx) ir_if(operand(r0D6D).val);
                     exec_list *const f0D6B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D6B->then_instructions;

                        body.emit(assign(r0D5F, add(r0D5F, body.constant(int(2))), 0x01));

                        body.emit(assign(r0D5D, lshift(r0D5D, body.constant(int(2))), 0x01));


                     body.instructions = f0D6B_parent_instructions;
                     body.emit(f0D6B);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0D6F = bit_and(r0D5D, body.constant(2147483648u));
                     ir_expression *const r0D70 = equal(r0D6F, body.constant(0u));
                     ir_if *f0D6E = new(mem_ctx) ir_if(operand(r0D70).val);
                     exec_list *const f0D6E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D6E->then_instructions;

                        body.emit(assign(r0D5F, add(r0D5F, body.constant(int(1))), 0x01));


                     body.instructions = f0D6E_parent_instructions;
                     body.emit(f0D6E);

                     /* END IF */

                     body.emit(assign(r0D5E, r0D5F, 0x01));


                  body.instructions = f0D60_parent_instructions;
                  body.emit(f0D60);

                  /* END IF */

                  body.emit(assign(r0D5A, add(r0D5E, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0D72 = less(r0D5A, body.constant(int(0)));
                  ir_if *f0D71 = new(mem_ctx) ir_if(operand(r0D72).val);
                  exec_list *const f0D71_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0D71->then_instructions;

                     ir_expression *const r0D73 = neg(r0D5A);
                     body.emit(assign(r0D58, rshift(r0CED, r0D73), 0x01));

                     ir_expression *const r0D74 = bit_and(r0D5A, body.constant(int(31)));
                     body.emit(assign(r0D59, lshift(r0CED, r0D74), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0D71->else_instructions;

                     body.emit(assign(r0D58, lshift(r0CED, r0D5A), 0x01));

                     body.emit(assign(r0D59, body.constant(0u), 0x01));


                  body.instructions = f0D71_parent_instructions;
                  body.emit(f0D71);

                  /* END IF */

                  body.emit(assign(r0D57, sub(body.constant(int(-31)), r0D5A), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0D5B->else_instructions;

                  ir_variable *const r0D75 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r0D75, r0CFF, 0x01));

                  ir_variable *const r0D76 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r0D77 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0D77);
                  /* IF CONDITION */
                  ir_expression *const r0D79 = equal(r0CFF, body.constant(0u));
                  ir_if *f0D78 = new(mem_ctx) ir_if(operand(r0D79).val);
                  exec_list *const f0D78_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0D78->then_instructions;

                     body.emit(assign(r0D76, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0D78->else_instructions;

                     body.emit(assign(r0D77, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0D7B = bit_and(r0CFF, body.constant(4294901760u));
                     ir_expression *const r0D7C = equal(r0D7B, body.constant(0u));
                     ir_if *f0D7A = new(mem_ctx) ir_if(operand(r0D7C).val);
                     exec_list *const f0D7A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D7A->then_instructions;

                        body.emit(assign(r0D77, body.constant(int(16)), 0x01));

                        body.emit(assign(r0D75, lshift(r0CFF, body.constant(int(16))), 0x01));


                     body.instructions = f0D7A_parent_instructions;
                     body.emit(f0D7A);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0D7E = bit_and(r0D75, body.constant(4278190080u));
                     ir_expression *const r0D7F = equal(r0D7E, body.constant(0u));
                     ir_if *f0D7D = new(mem_ctx) ir_if(operand(r0D7F).val);
                     exec_list *const f0D7D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D7D->then_instructions;

                        body.emit(assign(r0D77, add(r0D77, body.constant(int(8))), 0x01));

                        body.emit(assign(r0D75, lshift(r0D75, body.constant(int(8))), 0x01));


                     body.instructions = f0D7D_parent_instructions;
                     body.emit(f0D7D);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0D81 = bit_and(r0D75, body.constant(4026531840u));
                     ir_expression *const r0D82 = equal(r0D81, body.constant(0u));
                     ir_if *f0D80 = new(mem_ctx) ir_if(operand(r0D82).val);
                     exec_list *const f0D80_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D80->then_instructions;

                        body.emit(assign(r0D77, add(r0D77, body.constant(int(4))), 0x01));

                        body.emit(assign(r0D75, lshift(r0D75, body.constant(int(4))), 0x01));


                     body.instructions = f0D80_parent_instructions;
                     body.emit(f0D80);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0D84 = bit_and(r0D75, body.constant(3221225472u));
                     ir_expression *const r0D85 = equal(r0D84, body.constant(0u));
                     ir_if *f0D83 = new(mem_ctx) ir_if(operand(r0D85).val);
                     exec_list *const f0D83_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D83->then_instructions;

                        body.emit(assign(r0D77, add(r0D77, body.constant(int(2))), 0x01));

                        body.emit(assign(r0D75, lshift(r0D75, body.constant(int(2))), 0x01));


                     body.instructions = f0D83_parent_instructions;
                     body.emit(f0D83);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0D87 = bit_and(r0D75, body.constant(2147483648u));
                     ir_expression *const r0D88 = equal(r0D87, body.constant(0u));
                     ir_if *f0D86 = new(mem_ctx) ir_if(operand(r0D88).val);
                     exec_list *const f0D86_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0D86->then_instructions;

                        body.emit(assign(r0D77, add(r0D77, body.constant(int(1))), 0x01));


                     body.instructions = f0D86_parent_instructions;
                     body.emit(f0D86);

                     /* END IF */

                     body.emit(assign(r0D76, r0D77, 0x01));


                  body.instructions = f0D78_parent_instructions;
                  body.emit(f0D78);

                  /* END IF */

                  body.emit(assign(r0D5A, add(r0D76, body.constant(int(-11))), 0x01));

                  ir_variable *const r0D89 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r0D89, lshift(r0CED, r0D5A), 0x01));

                  ir_variable *const r0D8A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r0D8C = equal(r0D5A, body.constant(int(0)));
                  ir_if *f0D8B = new(mem_ctx) ir_if(operand(r0D8C).val);
                  exec_list *const f0D8B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0D8B->then_instructions;

                     body.emit(assign(r0D8A, r0CFF, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0D8B->else_instructions;

                     ir_expression *const r0D8D = lshift(r0CFF, r0D5A);
                     ir_expression *const r0D8E = neg(r0D5A);
                     ir_expression *const r0D8F = bit_and(r0D8E, body.constant(int(31)));
                     ir_expression *const r0D90 = rshift(r0CED, r0D8F);
                     body.emit(assign(r0D8A, bit_or(r0D8D, r0D90), 0x01));


                  body.instructions = f0D8B_parent_instructions;
                  body.emit(f0D8B);

                  /* END IF */

                  body.emit(assign(r0D58, r0D8A, 0x01));

                  body.emit(assign(r0D59, r0D89, 0x01));

                  body.emit(assign(r0D57, sub(body.constant(int(1)), r0D5A), 0x01));


               body.instructions = f0D5B_parent_instructions;
               body.emit(f0D5B);

               /* END IF */

               body.emit(assign(r0CF5, r0D57, 0x01));

               body.emit(assign(r0CF8, r0D58, 0x01));

               body.emit(assign(r0CF9, r0D59, 0x01));


            body.instructions = f0D53_parent_instructions;
            body.emit(f0D53);

            /* END IF */


         body.instructions = f0D51_parent_instructions;
         body.emit(f0D51);

         /* END IF */

         /* IF CONDITION */
         ir_if *f0D91 = new(mem_ctx) ir_if(operand(r0CF1).val);
         exec_list *const f0D91_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D91->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0D93 = equal(r0D05, body.constant(int(0)));
            ir_if *f0D92 = new(mem_ctx) ir_if(operand(r0D93).val);
            exec_list *const f0D92_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D92->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0D95 = bit_or(r0D01, r0CED);
               ir_expression *const r0D96 = equal(r0D95, body.constant(0u));
               ir_if *f0D94 = new(mem_ctx) ir_if(operand(r0D96).val);
               exec_list *const f0D94_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D94->then_instructions;

                  ir_variable *const r0D97 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0D97);
                  body.emit(assign(r0D97, lshift(r0CF3, body.constant(int(31))), 0x02));

                  body.emit(assign(r0D97, body.constant(0u), 0x01));

                  body.emit(assign(r0CF2, r0D97, 0x03));

                  body.emit(assign(r0CF1, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0D94->else_instructions;

                  ir_variable *const r0D98 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r0D98, r0D05, 0x01));

                  ir_variable *const r0D99 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r0D99, r0D01, 0x01));

                  ir_variable *const r0D9A = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r0D9A, r0D00, 0x01));

                  ir_variable *const r0D9B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r0D9B);
                  /* IF CONDITION */
                  ir_expression *const r0D9D = equal(r0D01, body.constant(0u));
                  ir_if *f0D9C = new(mem_ctx) ir_if(operand(r0D9D).val);
                  exec_list *const f0D9C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0D9C->then_instructions;

                     ir_variable *const r0D9E = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r0D9E, r0D00, 0x01));

                     ir_variable *const r0D9F = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r0DA0 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0DA0);
                     /* IF CONDITION */
                     ir_expression *const r0DA2 = equal(r0CED, body.constant(0u));
                     ir_if *f0DA1 = new(mem_ctx) ir_if(operand(r0DA2).val);
                     exec_list *const f0DA1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0DA1->then_instructions;

                        body.emit(assign(r0D9F, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0DA1->else_instructions;

                        body.emit(assign(r0DA0, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0DA4 = bit_and(r0CED, body.constant(4294901760u));
                        ir_expression *const r0DA5 = equal(r0DA4, body.constant(0u));
                        ir_if *f0DA3 = new(mem_ctx) ir_if(operand(r0DA5).val);
                        exec_list *const f0DA3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DA3->then_instructions;

                           body.emit(assign(r0DA0, body.constant(int(16)), 0x01));

                           body.emit(assign(r0D9E, lshift(r0CED, body.constant(int(16))), 0x01));


                        body.instructions = f0DA3_parent_instructions;
                        body.emit(f0DA3);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0DA7 = bit_and(r0D9E, body.constant(4278190080u));
                        ir_expression *const r0DA8 = equal(r0DA7, body.constant(0u));
                        ir_if *f0DA6 = new(mem_ctx) ir_if(operand(r0DA8).val);
                        exec_list *const f0DA6_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DA6->then_instructions;

                           body.emit(assign(r0DA0, add(r0DA0, body.constant(int(8))), 0x01));

                           body.emit(assign(r0D9E, lshift(r0D9E, body.constant(int(8))), 0x01));


                        body.instructions = f0DA6_parent_instructions;
                        body.emit(f0DA6);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0DAA = bit_and(r0D9E, body.constant(4026531840u));
                        ir_expression *const r0DAB = equal(r0DAA, body.constant(0u));
                        ir_if *f0DA9 = new(mem_ctx) ir_if(operand(r0DAB).val);
                        exec_list *const f0DA9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DA9->then_instructions;

                           body.emit(assign(r0DA0, add(r0DA0, body.constant(int(4))), 0x01));

                           body.emit(assign(r0D9E, lshift(r0D9E, body.constant(int(4))), 0x01));


                        body.instructions = f0DA9_parent_instructions;
                        body.emit(f0DA9);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0DAD = bit_and(r0D9E, body.constant(3221225472u));
                        ir_expression *const r0DAE = equal(r0DAD, body.constant(0u));
                        ir_if *f0DAC = new(mem_ctx) ir_if(operand(r0DAE).val);
                        exec_list *const f0DAC_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DAC->then_instructions;

                           body.emit(assign(r0DA0, add(r0DA0, body.constant(int(2))), 0x01));

                           body.emit(assign(r0D9E, lshift(r0D9E, body.constant(int(2))), 0x01));


                        body.instructions = f0DAC_parent_instructions;
                        body.emit(f0DAC);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0DB0 = bit_and(r0D9E, body.constant(2147483648u));
                        ir_expression *const r0DB1 = equal(r0DB0, body.constant(0u));
                        ir_if *f0DAF = new(mem_ctx) ir_if(operand(r0DB1).val);
                        exec_list *const f0DAF_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DAF->then_instructions;

                           body.emit(assign(r0DA0, add(r0DA0, body.constant(int(1))), 0x01));


                        body.instructions = f0DAF_parent_instructions;
                        body.emit(f0DAF);

                        /* END IF */

                        body.emit(assign(r0D9F, r0DA0, 0x01));


                     body.instructions = f0DA1_parent_instructions;
                     body.emit(f0DA1);

                     /* END IF */

                     body.emit(assign(r0D9B, add(r0D9F, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0DB3 = less(r0D9B, body.constant(int(0)));
                     ir_if *f0DB2 = new(mem_ctx) ir_if(operand(r0DB3).val);
                     exec_list *const f0DB2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0DB2->then_instructions;

                        ir_expression *const r0DB4 = neg(r0D9B);
                        body.emit(assign(r0D99, rshift(r0CED, r0DB4), 0x01));

                        ir_expression *const r0DB5 = bit_and(r0D9B, body.constant(int(31)));
                        body.emit(assign(r0D9A, lshift(r0CED, r0DB5), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0DB2->else_instructions;

                        body.emit(assign(r0D99, lshift(r0CED, r0D9B), 0x01));

                        body.emit(assign(r0D9A, body.constant(0u), 0x01));


                     body.instructions = f0DB2_parent_instructions;
                     body.emit(f0DB2);

                     /* END IF */

                     body.emit(assign(r0D98, sub(body.constant(int(-31)), r0D9B), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0D9C->else_instructions;

                     ir_variable *const r0DB6 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r0DB6, r0D01, 0x01));

                     ir_variable *const r0DB7 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r0DB8 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r0DB8);
                     /* IF CONDITION */
                     ir_expression *const r0DBA = equal(r0D01, body.constant(0u));
                     ir_if *f0DB9 = new(mem_ctx) ir_if(operand(r0DBA).val);
                     exec_list *const f0DB9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0DB9->then_instructions;

                        body.emit(assign(r0DB7, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0DB9->else_instructions;

                        body.emit(assign(r0DB8, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0DBC = bit_and(r0D01, body.constant(4294901760u));
                        ir_expression *const r0DBD = equal(r0DBC, body.constant(0u));
                        ir_if *f0DBB = new(mem_ctx) ir_if(operand(r0DBD).val);
                        exec_list *const f0DBB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DBB->then_instructions;

                           body.emit(assign(r0DB8, body.constant(int(16)), 0x01));

                           body.emit(assign(r0DB6, lshift(r0D01, body.constant(int(16))), 0x01));


                        body.instructions = f0DBB_parent_instructions;
                        body.emit(f0DBB);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0DBF = bit_and(r0DB6, body.constant(4278190080u));
                        ir_expression *const r0DC0 = equal(r0DBF, body.constant(0u));
                        ir_if *f0DBE = new(mem_ctx) ir_if(operand(r0DC0).val);
                        exec_list *const f0DBE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DBE->then_instructions;

                           body.emit(assign(r0DB8, add(r0DB8, body.constant(int(8))), 0x01));

                           body.emit(assign(r0DB6, lshift(r0DB6, body.constant(int(8))), 0x01));


                        body.instructions = f0DBE_parent_instructions;
                        body.emit(f0DBE);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0DC2 = bit_and(r0DB6, body.constant(4026531840u));
                        ir_expression *const r0DC3 = equal(r0DC2, body.constant(0u));
                        ir_if *f0DC1 = new(mem_ctx) ir_if(operand(r0DC3).val);
                        exec_list *const f0DC1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DC1->then_instructions;

                           body.emit(assign(r0DB8, add(r0DB8, body.constant(int(4))), 0x01));

                           body.emit(assign(r0DB6, lshift(r0DB6, body.constant(int(4))), 0x01));


                        body.instructions = f0DC1_parent_instructions;
                        body.emit(f0DC1);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0DC5 = bit_and(r0DB6, body.constant(3221225472u));
                        ir_expression *const r0DC6 = equal(r0DC5, body.constant(0u));
                        ir_if *f0DC4 = new(mem_ctx) ir_if(operand(r0DC6).val);
                        exec_list *const f0DC4_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DC4->then_instructions;

                           body.emit(assign(r0DB8, add(r0DB8, body.constant(int(2))), 0x01));

                           body.emit(assign(r0DB6, lshift(r0DB6, body.constant(int(2))), 0x01));


                        body.instructions = f0DC4_parent_instructions;
                        body.emit(f0DC4);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0DC8 = bit_and(r0DB6, body.constant(2147483648u));
                        ir_expression *const r0DC9 = equal(r0DC8, body.constant(0u));
                        ir_if *f0DC7 = new(mem_ctx) ir_if(operand(r0DC9).val);
                        exec_list *const f0DC7_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0DC7->then_instructions;

                           body.emit(assign(r0DB8, add(r0DB8, body.constant(int(1))), 0x01));


                        body.instructions = f0DC7_parent_instructions;
                        body.emit(f0DC7);

                        /* END IF */

                        body.emit(assign(r0DB7, r0DB8, 0x01));


                     body.instructions = f0DB9_parent_instructions;
                     body.emit(f0DB9);

                     /* END IF */

                     body.emit(assign(r0D9B, add(r0DB7, body.constant(int(-11))), 0x01));

                     ir_variable *const r0DCA = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r0DCA, lshift(r0CED, r0D9B), 0x01));

                     ir_variable *const r0DCB = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0DCD = equal(r0D9B, body.constant(int(0)));
                     ir_if *f0DCC = new(mem_ctx) ir_if(operand(r0DCD).val);
                     exec_list *const f0DCC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0DCC->then_instructions;

                        body.emit(assign(r0DCB, r0D01, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0DCC->else_instructions;

                        ir_expression *const r0DCE = lshift(r0D01, r0D9B);
                        ir_expression *const r0DCF = neg(r0D9B);
                        ir_expression *const r0DD0 = bit_and(r0DCF, body.constant(int(31)));
                        ir_expression *const r0DD1 = rshift(r0CED, r0DD0);
                        body.emit(assign(r0DCB, bit_or(r0DCE, r0DD1), 0x01));


                     body.instructions = f0DCC_parent_instructions;
                     body.emit(f0DCC);

                     /* END IF */

                     body.emit(assign(r0D99, r0DCB, 0x01));

                     body.emit(assign(r0D9A, r0DCA, 0x01));

                     body.emit(assign(r0D98, sub(body.constant(int(1)), r0D9B), 0x01));


                  body.instructions = f0D9C_parent_instructions;
                  body.emit(f0D9C);

                  /* END IF */

                  body.emit(assign(r0CF4, r0D98, 0x01));

                  body.emit(assign(r0CF6, r0D99, 0x01));

                  body.emit(assign(r0CF7, r0D9A, 0x01));


               body.instructions = f0D94_parent_instructions;
               body.emit(f0D94);

               /* END IF */


            body.instructions = f0D92_parent_instructions;
            body.emit(f0D92);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0DD2 = new(mem_ctx) ir_if(operand(r0CF1).val);
            exec_list *const f0DD2_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0DD2->then_instructions;

               ir_expression *const r0DD3 = add(r0CF5, r0CF4);
               body.emit(assign(r0CFA, add(r0DD3, body.constant(int(-1024))), 0x01));

               body.emit(assign(r0CF8, bit_or(r0CF8, body.constant(1048576u)), 0x01));

               ir_variable *const r0DD4 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0DD4, lshift(r0CF7, body.constant(int(12))), 0x01));

               ir_variable *const r0DD5 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               ir_expression *const r0DD6 = lshift(r0CF6, body.constant(int(12)));
               ir_expression *const r0DD7 = rshift(r0CF7, body.constant(int(20)));
               body.emit(assign(r0DD5, bit_or(r0DD6, r0DD7), 0x01));

               body.emit(assign(r0CF6, r0DD5, 0x01));

               body.emit(assign(r0CF7, r0DD4, 0x01));

               ir_variable *const r0DD8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0DD8);
               ir_variable *const r0DD9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0DD9);
               ir_variable *const r0DDA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0DDA);
               ir_variable *const r0DDB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DDB, bit_and(r0CF9, body.constant(65535u)), 0x01));

               ir_variable *const r0DDC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DDC, rshift(r0CF9, body.constant(int(16))), 0x01));

               ir_variable *const r0DDD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DDD, bit_and(r0DD4, body.constant(65535u)), 0x01));

               ir_variable *const r0DDE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DDE, rshift(r0DD4, body.constant(int(16))), 0x01));

               ir_variable *const r0DDF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DDF, mul(r0DDC, r0DDD), 0x01));

               ir_expression *const r0DE0 = mul(r0DDB, r0DDE);
               body.emit(assign(r0DD9, add(r0DE0, r0DDF), 0x01));

               ir_expression *const r0DE1 = mul(r0DDC, r0DDE);
               ir_expression *const r0DE2 = less(r0DD9, r0DDF);
               ir_expression *const r0DE3 = expr(ir_unop_b2i, r0DE2);
               ir_expression *const r0DE4 = expr(ir_unop_i2u, r0DE3);
               ir_expression *const r0DE5 = lshift(r0DE4, body.constant(int(16)));
               ir_expression *const r0DE6 = rshift(r0DD9, body.constant(int(16)));
               ir_expression *const r0DE7 = add(r0DE5, r0DE6);
               body.emit(assign(r0DD8, add(r0DE1, r0DE7), 0x01));

               body.emit(assign(r0DD9, lshift(r0DD9, body.constant(int(16))), 0x01));

               ir_expression *const r0DE8 = mul(r0DDB, r0DDD);
               body.emit(assign(r0DDA, add(r0DE8, r0DD9), 0x01));

               ir_expression *const r0DE9 = less(r0DDA, r0DD9);
               ir_expression *const r0DEA = expr(ir_unop_b2i, r0DE9);
               ir_expression *const r0DEB = expr(ir_unop_i2u, r0DEA);
               body.emit(assign(r0DD8, add(r0DD8, r0DEB), 0x01));

               ir_variable *const r0DEC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0DEC);
               ir_variable *const r0DED = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0DED);
               ir_variable *const r0DEE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0DEE);
               ir_variable *const r0DEF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DEF, bit_and(r0CF9, body.constant(65535u)), 0x01));

               ir_variable *const r0DF0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DF0, rshift(r0CF9, body.constant(int(16))), 0x01));

               ir_variable *const r0DF1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DF1, bit_and(r0DD5, body.constant(65535u)), 0x01));

               ir_variable *const r0DF2 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DF2, rshift(r0DD5, body.constant(int(16))), 0x01));

               ir_variable *const r0DF3 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0DF3, mul(r0DF0, r0DF1), 0x01));

               ir_expression *const r0DF4 = mul(r0DEF, r0DF2);
               body.emit(assign(r0DED, add(r0DF4, r0DF3), 0x01));

               ir_expression *const r0DF5 = mul(r0DF0, r0DF2);
               ir_expression *const r0DF6 = less(r0DED, r0DF3);
               ir_expression *const r0DF7 = expr(ir_unop_b2i, r0DF6);
               ir_expression *const r0DF8 = expr(ir_unop_i2u, r0DF7);
               ir_expression *const r0DF9 = lshift(r0DF8, body.constant(int(16)));
               ir_expression *const r0DFA = rshift(r0DED, body.constant(int(16)));
               ir_expression *const r0DFB = add(r0DF9, r0DFA);
               body.emit(assign(r0DEC, add(r0DF5, r0DFB), 0x01));

               body.emit(assign(r0DED, lshift(r0DED, body.constant(int(16))), 0x01));

               ir_expression *const r0DFC = mul(r0DEF, r0DF1);
               body.emit(assign(r0DEE, add(r0DFC, r0DED), 0x01));

               ir_expression *const r0DFD = less(r0DEE, r0DED);
               ir_expression *const r0DFE = expr(ir_unop_b2i, r0DFD);
               ir_expression *const r0DFF = expr(ir_unop_i2u, r0DFE);
               body.emit(assign(r0DEC, add(r0DEC, r0DFF), 0x01));

               ir_variable *const r0E00 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E00, add(r0DEE, r0DD8), 0x01));

               ir_variable *const r0E01 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0E01);
               ir_variable *const r0E02 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0E02);
               ir_variable *const r0E03 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0E03);
               ir_variable *const r0E04 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E04, bit_and(r0CF8, body.constant(65535u)), 0x01));

               ir_variable *const r0E05 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E05, rshift(r0CF8, body.constant(int(16))), 0x01));

               ir_variable *const r0E06 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E06, bit_and(r0DD5, body.constant(65535u)), 0x01));

               ir_variable *const r0E07 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E07, rshift(r0DD5, body.constant(int(16))), 0x01));

               ir_variable *const r0E08 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E08, mul(r0E05, r0E06), 0x01));

               ir_expression *const r0E09 = mul(r0E04, r0E07);
               body.emit(assign(r0E02, add(r0E09, r0E08), 0x01));

               ir_expression *const r0E0A = mul(r0E05, r0E07);
               ir_expression *const r0E0B = less(r0E02, r0E08);
               ir_expression *const r0E0C = expr(ir_unop_b2i, r0E0B);
               ir_expression *const r0E0D = expr(ir_unop_i2u, r0E0C);
               ir_expression *const r0E0E = lshift(r0E0D, body.constant(int(16)));
               ir_expression *const r0E0F = rshift(r0E02, body.constant(int(16)));
               ir_expression *const r0E10 = add(r0E0E, r0E0F);
               body.emit(assign(r0E01, add(r0E0A, r0E10), 0x01));

               body.emit(assign(r0E02, lshift(r0E02, body.constant(int(16))), 0x01));

               ir_expression *const r0E11 = mul(r0E04, r0E06);
               body.emit(assign(r0E03, add(r0E11, r0E02), 0x01));

               ir_expression *const r0E12 = less(r0E03, r0E02);
               ir_expression *const r0E13 = expr(ir_unop_b2i, r0E12);
               ir_expression *const r0E14 = expr(ir_unop_i2u, r0E13);
               body.emit(assign(r0E01, add(r0E01, r0E14), 0x01));

               ir_variable *const r0E15 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0E16 = less(r0E00, r0DEE);
               ir_expression *const r0E17 = expr(ir_unop_b2i, r0E16);
               ir_expression *const r0E18 = expr(ir_unop_i2u, r0E17);
               ir_expression *const r0E19 = add(r0DEC, r0E18);
               body.emit(assign(r0E15, add(r0E03, r0E19), 0x01));

               ir_variable *const r0E1A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0E1A);
               ir_variable *const r0E1B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0E1B);
               ir_variable *const r0E1C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0E1C);
               ir_variable *const r0E1D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E1D, bit_and(r0CF8, body.constant(65535u)), 0x01));

               ir_variable *const r0E1E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E1E, rshift(r0CF8, body.constant(int(16))), 0x01));

               ir_variable *const r0E1F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E1F, bit_and(r0DD4, body.constant(65535u)), 0x01));

               ir_variable *const r0E20 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E20, rshift(r0DD4, body.constant(int(16))), 0x01));

               ir_variable *const r0E21 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E21, mul(r0E1E, r0E1F), 0x01));

               ir_expression *const r0E22 = mul(r0E1D, r0E20);
               body.emit(assign(r0E1B, add(r0E22, r0E21), 0x01));

               ir_expression *const r0E23 = mul(r0E1E, r0E20);
               ir_expression *const r0E24 = less(r0E1B, r0E21);
               ir_expression *const r0E25 = expr(ir_unop_b2i, r0E24);
               ir_expression *const r0E26 = expr(ir_unop_i2u, r0E25);
               ir_expression *const r0E27 = lshift(r0E26, body.constant(int(16)));
               ir_expression *const r0E28 = rshift(r0E1B, body.constant(int(16)));
               ir_expression *const r0E29 = add(r0E27, r0E28);
               body.emit(assign(r0E1A, add(r0E23, r0E29), 0x01));

               body.emit(assign(r0E1B, lshift(r0E1B, body.constant(int(16))), 0x01));

               ir_expression *const r0E2A = mul(r0E1D, r0E1F);
               body.emit(assign(r0E1C, add(r0E2A, r0E1B), 0x01));

               ir_expression *const r0E2B = less(r0E1C, r0E1B);
               ir_expression *const r0E2C = expr(ir_unop_b2i, r0E2B);
               ir_expression *const r0E2D = expr(ir_unop_i2u, r0E2C);
               body.emit(assign(r0E1A, add(r0E1A, r0E2D), 0x01));

               ir_variable *const r0E2E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E2E, add(r0E1C, r0E00), 0x01));

               ir_variable *const r0E2F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0E30 = less(r0E2E, r0E1C);
               ir_expression *const r0E31 = expr(ir_unop_b2i, r0E30);
               ir_expression *const r0E32 = expr(ir_unop_i2u, r0E31);
               ir_expression *const r0E33 = add(r0E1A, r0E32);
               body.emit(assign(r0E2F, add(r0E15, r0E33), 0x01));

               ir_variable *const r0E34 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0E35 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0E35, add(r0E2F, r0CF9), 0x01));

               ir_expression *const r0E36 = less(r0E15, r0E03);
               ir_expression *const r0E37 = expr(ir_unop_b2i, r0E36);
               ir_expression *const r0E38 = expr(ir_unop_i2u, r0E37);
               ir_expression *const r0E39 = add(r0E01, r0E38);
               ir_expression *const r0E3A = less(r0E2F, r0E15);
               ir_expression *const r0E3B = expr(ir_unop_b2i, r0E3A);
               ir_expression *const r0E3C = expr(ir_unop_i2u, r0E3B);
               ir_expression *const r0E3D = add(r0E39, r0E3C);
               ir_expression *const r0E3E = add(r0E3D, r0CF8);
               ir_expression *const r0E3F = less(r0E35, r0E2F);
               ir_expression *const r0E40 = expr(ir_unop_b2i, r0E3F);
               ir_expression *const r0E41 = expr(ir_unop_i2u, r0E40);
               body.emit(assign(r0E34, add(r0E3E, r0E41), 0x01));

               body.emit(assign(r0CFD, r0E34, 0x01));

               body.emit(assign(r0CFC, r0E35, 0x01));

               ir_expression *const r0E42 = nequal(r0DDA, body.constant(0u));
               ir_expression *const r0E43 = expr(ir_unop_b2i, r0E42);
               ir_expression *const r0E44 = expr(ir_unop_i2u, r0E43);
               body.emit(assign(r0CFB, bit_or(r0E2E, r0E44), 0x01));

               /* IF CONDITION */
               ir_expression *const r0E46 = lequal(body.constant(2097152u), r0E34);
               ir_if *f0E45 = new(mem_ctx) ir_if(operand(r0E46).val);
               exec_list *const f0E45_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0E45->then_instructions;

                  ir_variable *const r0E47 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0E47);
                  body.emit(assign(r0E47, lshift(r0E35, body.constant(int(31))), 0x01));

                  ir_expression *const r0E48 = nequal(r0CFB, body.constant(0u));
                  ir_expression *const r0E49 = expr(ir_unop_b2i, r0E48);
                  ir_expression *const r0E4A = expr(ir_unop_i2u, r0E49);
                  body.emit(assign(r0E47, bit_or(r0E47, r0E4A), 0x01));

                  body.emit(assign(r0CFD, rshift(r0E34, body.constant(int(1))), 0x01));

                  ir_expression *const r0E4B = lshift(r0E34, body.constant(int(31)));
                  ir_expression *const r0E4C = rshift(r0E35, body.constant(int(1)));
                  body.emit(assign(r0CFC, bit_or(r0E4B, r0E4C), 0x01));

                  body.emit(assign(r0CFB, r0E47, 0x01));

                  body.emit(assign(r0CFA, add(r0CFA, body.constant(int(1))), 0x01));


               body.instructions = f0E45_parent_instructions;
               body.emit(f0E45);

               /* END IF */

               ir_variable *const r0E4D = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r0E4D, r0CFA, 0x01));

               ir_variable *const r0E4E = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r0E4E, r0CFD, 0x01));

               ir_variable *const r0E4F = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r0E4F, r0CFC, 0x01));

               ir_variable *const r0E50 = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r0E50, r0CFB, 0x01));

               ir_variable *const r0E51 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0E51, body.constant(true), 0x01));

               ir_variable *const r0E52 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0E53 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0E53);
               ir_expression *const r0E54 = expr(ir_unop_u2i, r0CFB);
               body.emit(assign(r0E53, less(r0E54, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0E56 = lequal(body.constant(int(2045)), r0CFA);
               ir_if *f0E55 = new(mem_ctx) ir_if(operand(r0E56).val);
               exec_list *const f0E55_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0E55->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0E58 = less(body.constant(int(2045)), r0CFA);
                  ir_expression *const r0E59 = equal(r0CFA, body.constant(int(2045)));
                  ir_expression *const r0E5A = equal(body.constant(2097151u), r0CFD);
                  ir_expression *const r0E5B = equal(body.constant(4294967295u), r0CFC);
                  ir_expression *const r0E5C = logic_and(r0E5A, r0E5B);
                  ir_expression *const r0E5D = logic_and(r0E59, r0E5C);
                  ir_expression *const r0E5E = logic_and(r0E5D, r0E53);
                  ir_expression *const r0E5F = logic_or(r0E58, r0E5E);
                  ir_if *f0E57 = new(mem_ctx) ir_if(operand(r0E5F).val);
                  exec_list *const f0E57_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0E57->then_instructions;

                     ir_variable *const r0E60 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r0E60);
                     ir_expression *const r0E61 = lshift(r0CF3, body.constant(int(31)));
                     body.emit(assign(r0E60, add(r0E61, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r0E60, body.constant(0u), 0x01));

                     body.emit(assign(r0E52, r0E60, 0x03));

                     body.emit(assign(r0E51, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0E57->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0E63 = less(r0CFA, body.constant(int(0)));
                     ir_if *f0E62 = new(mem_ctx) ir_if(operand(r0E63).val);
                     exec_list *const f0E62_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0E62->then_instructions;

                        ir_variable *const r0E64 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r0E64, r0CFB, 0x01));

                        ir_variable *const r0E65 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r0E65, neg(r0CFA), 0x01));

                        ir_variable *const r0E66 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r0E66);
                        ir_variable *const r0E67 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r0E67);
                        ir_variable *const r0E68 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r0E68);
                        ir_variable *const r0E69 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r0E6A = neg(r0E65);
                        body.emit(assign(r0E69, bit_and(r0E6A, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0E6C = equal(r0E65, body.constant(int(0)));
                        ir_if *f0E6B = new(mem_ctx) ir_if(operand(r0E6C).val);
                        exec_list *const f0E6B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0E6B->then_instructions;

                           body.emit(assign(r0E66, r0CFB, 0x01));

                           body.emit(assign(r0E67, r0CFC, 0x01));

                           body.emit(assign(r0E68, r0CFD, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0E6B->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0E6E = less(r0E65, body.constant(int(32)));
                           ir_if *f0E6D = new(mem_ctx) ir_if(operand(r0E6E).val);
                           exec_list *const f0E6D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0E6D->then_instructions;

                              body.emit(assign(r0E66, lshift(r0CFC, r0E69), 0x01));

                              ir_expression *const r0E6F = lshift(r0CFD, r0E69);
                              ir_expression *const r0E70 = rshift(r0CFC, r0E65);
                              body.emit(assign(r0E67, bit_or(r0E6F, r0E70), 0x01));

                              body.emit(assign(r0E68, rshift(r0CFD, r0E65), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0E6D->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0E72 = equal(r0E65, body.constant(int(32)));
                              ir_if *f0E71 = new(mem_ctx) ir_if(operand(r0E72).val);
                              exec_list *const f0E71_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0E71->then_instructions;

                                 body.emit(assign(r0E66, r0CFC, 0x01));

                                 body.emit(assign(r0E67, r0CFD, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0E71->else_instructions;

                                 body.emit(assign(r0E64, bit_or(r0CFB, r0CFC), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0E74 = less(r0E65, body.constant(int(64)));
                                 ir_if *f0E73 = new(mem_ctx) ir_if(operand(r0E74).val);
                                 exec_list *const f0E73_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0E73->then_instructions;

                                    body.emit(assign(r0E66, lshift(r0CFD, r0E69), 0x01));

                                    ir_expression *const r0E75 = bit_and(r0E65, body.constant(int(31)));
                                    body.emit(assign(r0E67, rshift(r0CFD, r0E75), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0E73->else_instructions;

                                    ir_variable *const r0E76 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r0E78 = equal(r0E65, body.constant(int(64)));
                                    ir_if *f0E77 = new(mem_ctx) ir_if(operand(r0E78).val);
                                    exec_list *const f0E77_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0E77->then_instructions;

                                       body.emit(assign(r0E76, r0CFD, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0E77->else_instructions;

                                       ir_expression *const r0E79 = nequal(r0CFD, body.constant(0u));
                                       ir_expression *const r0E7A = expr(ir_unop_b2i, r0E79);
                                       body.emit(assign(r0E76, expr(ir_unop_i2u, r0E7A), 0x01));


                                    body.instructions = f0E77_parent_instructions;
                                    body.emit(f0E77);

                                    /* END IF */

                                    body.emit(assign(r0E66, r0E76, 0x01));

                                    body.emit(assign(r0E67, body.constant(0u), 0x01));


                                 body.instructions = f0E73_parent_instructions;
                                 body.emit(f0E73);

                                 /* END IF */


                              body.instructions = f0E71_parent_instructions;
                              body.emit(f0E71);

                              /* END IF */

                              body.emit(assign(r0E68, body.constant(0u), 0x01));


                           body.instructions = f0E6D_parent_instructions;
                           body.emit(f0E6D);

                           /* END IF */

                           ir_expression *const r0E7B = nequal(r0E64, body.constant(0u));
                           ir_expression *const r0E7C = expr(ir_unop_b2i, r0E7B);
                           ir_expression *const r0E7D = expr(ir_unop_i2u, r0E7C);
                           body.emit(assign(r0E66, bit_or(r0E66, r0E7D), 0x01));


                        body.instructions = f0E6B_parent_instructions;
                        body.emit(f0E6B);

                        /* END IF */

                        body.emit(assign(r0E4E, r0E68, 0x01));

                        body.emit(assign(r0E4F, r0E67, 0x01));

                        body.emit(assign(r0E50, r0E66, 0x01));

                        body.emit(assign(r0E4D, body.constant(int(0)), 0x01));

                        body.emit(assign(r0E53, less(r0E66, body.constant(0u)), 0x01));


                     body.instructions = f0E62_parent_instructions;
                     body.emit(f0E62);

                     /* END IF */


                  body.instructions = f0E57_parent_instructions;
                  body.emit(f0E57);

                  /* END IF */


               body.instructions = f0E55_parent_instructions;
               body.emit(f0E55);

               /* END IF */

               /* IF CONDITION */
               ir_if *f0E7E = new(mem_ctx) ir_if(operand(r0E51).val);
               exec_list *const f0E7E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0E7E->then_instructions;

                  /* IF CONDITION */
                  ir_if *f0E7F = new(mem_ctx) ir_if(operand(r0E53).val);
                  exec_list *const f0E7F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0E7F->then_instructions;

                     ir_variable *const r0E80 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r0E80, add(r0E4F, body.constant(1u)), 0x01));

                     ir_expression *const r0E81 = less(r0E80, r0E4F);
                     ir_expression *const r0E82 = expr(ir_unop_b2i, r0E81);
                     ir_expression *const r0E83 = expr(ir_unop_i2u, r0E82);
                     body.emit(assign(r0E4E, add(r0E4E, r0E83), 0x01));

                     ir_expression *const r0E84 = equal(r0E50, body.constant(0u));
                     ir_expression *const r0E85 = expr(ir_unop_b2i, r0E84);
                     ir_expression *const r0E86 = expr(ir_unop_i2u, r0E85);
                     ir_expression *const r0E87 = add(r0E50, r0E86);
                     ir_expression *const r0E88 = bit_and(r0E87, body.constant(1u));
                     ir_expression *const r0E89 = expr(ir_unop_bit_not, r0E88);
                     body.emit(assign(r0E4F, bit_and(r0E80, r0E89), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0E7F->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0E8B = bit_or(r0E4E, r0E4F);
                     ir_expression *const r0E8C = equal(r0E8B, body.constant(0u));
                     ir_if *f0E8A = new(mem_ctx) ir_if(operand(r0E8C).val);
                     exec_list *const f0E8A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0E8A->then_instructions;

                        body.emit(assign(r0E4D, body.constant(int(0)), 0x01));


                     body.instructions = f0E8A_parent_instructions;
                     body.emit(f0E8A);

                     /* END IF */


                  body.instructions = f0E7F_parent_instructions;
                  body.emit(f0E7F);

                  /* END IF */

                  ir_variable *const r0E8D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0E8D);
                  ir_expression *const r0E8E = lshift(r0CF3, body.constant(int(31)));
                  ir_expression *const r0E8F = expr(ir_unop_i2u, r0E4D);
                  ir_expression *const r0E90 = lshift(r0E8F, body.constant(int(20)));
                  ir_expression *const r0E91 = add(r0E8E, r0E90);
                  body.emit(assign(r0E8D, add(r0E91, r0E4E), 0x02));

                  body.emit(assign(r0E8D, r0E4F, 0x01));

                  body.emit(assign(r0E52, r0E8D, 0x03));

                  body.emit(assign(r0E51, body.constant(false), 0x01));


               body.instructions = f0E7E_parent_instructions;
               body.emit(f0E7E);

               /* END IF */

               body.emit(assign(r0CF2, r0E52, 0x03));

               body.emit(assign(r0CF1, body.constant(false), 0x01));


            body.instructions = f0DD2_parent_instructions;
            body.emit(f0DD2);

            /* END IF */


         body.instructions = f0D91_parent_instructions;
         body.emit(f0D91);

         /* END IF */


      body.instructions = f0D30_parent_instructions;
      body.emit(f0D30);

      /* END IF */


   body.instructions = f0D0A_parent_instructions;
   body.emit(f0D0A);

   /* END IF */

   body.emit(ret(r0CF2));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
