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
lt64(void *mem_ctx, builtin_available_predicate avail)
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
   ir_expression *const r0053 = less(r004E, r0050);
   ir_expression *const r0054 = logic_and(r0052, r0053);
   ir_expression *const r0055 = logic_or(r0051, r0054);
   body.emit(ret(r0055));

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
         ir_expression *const r0074 = nequal(r0073, body.constant(0u));
         body.emit(assign(r0058, logic_and(r006F, r0074), 0x01));


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
            ir_expression *const r007A = less(swizzle_x(r0057), swizzle_x(r0056));
            ir_expression *const r007B = logic_and(r0079, r007A);
            body.emit(assign(r0075, logic_or(r0078, r007B), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0076->else_instructions;

            ir_expression *const r007C = less(swizzle_y(r0056), swizzle_y(r0057));
            ir_expression *const r007D = equal(swizzle_y(r0056), swizzle_y(r0057));
            ir_expression *const r007E = less(swizzle_x(r0056), swizzle_x(r0057));
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
add64(void *mem_ctx, builtin_available_predicate avail)
{
   ir_function_signature *const sig =
      new(mem_ctx) ir_function_signature(glsl_type::void_type, avail);
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
   ir_variable *const r0084 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0084);
   ir_variable *const r0085 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0085);
   ir_variable *const r0086 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0086, add(r0081, r0083), 0x01));

   body.emit(assign(r0085, r0086, 0x01));

   ir_expression *const r0087 = add(r0080, r0082);
   ir_expression *const r0088 = less(r0086, r0081);
   ir_expression *const r0089 = expr(ir_unop_b2i, r0088);
   ir_expression *const r008A = expr(ir_unop_i2u, r0089);
   body.emit(assign(r0084, add(r0087, r008A), 0x01));

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

   ir_variable *const r008B = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r008B);
   ir_variable *const r008C = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r008C);
   ir_variable *const r008D = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r008D);
   ir_variable *const r008E = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r008E);
   ir_variable *const r008F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r008F);
   ir_variable *const r0090 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0090);
   body.emit(assign(r0090, sub(r008C, r008E), 0x01));

   ir_expression *const r0091 = sub(r008B, r008D);
   ir_expression *const r0092 = less(r008C, r008E);
   ir_expression *const r0093 = expr(ir_unop_b2i, r0092);
   ir_expression *const r0094 = expr(ir_unop_i2u, r0093);
   body.emit(assign(r008F, sub(r0091, r0094), 0x01));

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

   ir_variable *const r0095 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0095);
   ir_variable *const r0096 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0096);
   ir_variable *const r0097 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r0097);
   ir_variable *const r0098 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0098);
   ir_variable *const r0099 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0099);
   ir_variable *const r009A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r009A);
   ir_variable *const r009B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r009B);
   ir_variable *const r009C = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r009D = neg(r0097);
   body.emit(assign(r009C, bit_and(r009D, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r009F = equal(r0097, body.constant(int(0)));
   ir_if *f009E = new(mem_ctx) ir_if(operand(r009F).val);
   exec_list *const f009E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f009E->then_instructions;

      body.emit(assign(r009A, r0096, 0x01));

      body.emit(assign(r009B, r0095, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f009E->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00A1 = less(r0097, body.constant(int(32)));
      ir_if *f00A0 = new(mem_ctx) ir_if(operand(r00A1).val);
      exec_list *const f00A0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00A0->then_instructions;

         ir_expression *const r00A2 = lshift(r0095, r009C);
         ir_expression *const r00A3 = rshift(r0096, r0097);
         ir_expression *const r00A4 = bit_or(r00A2, r00A3);
         ir_expression *const r00A5 = lshift(r0096, r009C);
         ir_expression *const r00A6 = nequal(r00A5, body.constant(0u));
         ir_expression *const r00A7 = expr(ir_unop_b2i, r00A6);
         ir_expression *const r00A8 = expr(ir_unop_i2u, r00A7);
         body.emit(assign(r009A, bit_or(r00A4, r00A8), 0x01));

         body.emit(assign(r009B, rshift(r0095, r0097), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00A0->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00AA = equal(r0097, body.constant(int(32)));
         ir_if *f00A9 = new(mem_ctx) ir_if(operand(r00AA).val);
         exec_list *const f00A9_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00A9->then_instructions;

            ir_expression *const r00AB = nequal(r0096, body.constant(0u));
            ir_expression *const r00AC = expr(ir_unop_b2i, r00AB);
            ir_expression *const r00AD = expr(ir_unop_i2u, r00AC);
            body.emit(assign(r009A, bit_or(r0095, r00AD), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00A9->else_instructions;

            /* IF CONDITION */
            ir_expression *const r00AF = less(r0097, body.constant(int(64)));
            ir_if *f00AE = new(mem_ctx) ir_if(operand(r00AF).val);
            exec_list *const f00AE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f00AE->then_instructions;

               ir_expression *const r00B0 = bit_and(r0097, body.constant(int(31)));
               ir_expression *const r00B1 = rshift(r0095, r00B0);
               ir_expression *const r00B2 = lshift(r0095, r009C);
               ir_expression *const r00B3 = bit_or(r00B2, r0096);
               ir_expression *const r00B4 = nequal(r00B3, body.constant(0u));
               ir_expression *const r00B5 = expr(ir_unop_b2i, r00B4);
               ir_expression *const r00B6 = expr(ir_unop_i2u, r00B5);
               body.emit(assign(r009A, bit_or(r00B1, r00B6), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f00AE->else_instructions;

               ir_expression *const r00B7 = bit_or(r0095, r0096);
               ir_expression *const r00B8 = nequal(r00B7, body.constant(0u));
               ir_expression *const r00B9 = expr(ir_unop_b2i, r00B8);
               body.emit(assign(r009A, expr(ir_unop_i2u, r00B9), 0x01));


            body.instructions = f00AE_parent_instructions;
            body.emit(f00AE);

            /* END IF */


         body.instructions = f00A9_parent_instructions;
         body.emit(f00A9);

         /* END IF */

         body.emit(assign(r009B, body.constant(0u), 0x01));


      body.instructions = f00A0_parent_instructions;
      body.emit(f00A0);

      /* END IF */


   body.instructions = f009E_parent_instructions;
   body.emit(f009E);

   /* END IF */

   body.emit(assign(r0099, r009A, 0x01));

   body.emit(assign(r0098, r009B, 0x01));

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

   ir_variable *const r00BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00BA);
   ir_variable *const r00BB = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00BB);
   ir_variable *const r00BC = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r00BC);
   ir_variable *const r00BD = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00BD);
   ir_variable *const r00BE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00BE);
   ir_variable *const r00BF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00BF);
   ir_variable *const r00C0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00C0);
   ir_variable *const r00C1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
   body.emit(r00C1);
   ir_variable *const r00C2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r00C2);
   ir_variable *const r00C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r00C3);
   ir_variable *const r00C4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r00C5 = neg(r00BD);
   body.emit(assign(r00C4, bit_and(r00C5, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00C7 = equal(r00BD, body.constant(int(0)));
   ir_if *f00C6 = new(mem_ctx) ir_if(operand(r00C7).val);
   exec_list *const f00C6_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00C6->then_instructions;

      body.emit(assign(r00C1, r00BC, 0x01));

      body.emit(assign(r00C2, r00BB, 0x01));

      body.emit(assign(r00C3, r00BA, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00C6->else_instructions;

      /* IF CONDITION */
      ir_expression *const r00C9 = less(r00BD, body.constant(int(32)));
      ir_if *f00C8 = new(mem_ctx) ir_if(operand(r00C9).val);
      exec_list *const f00C8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00C8->then_instructions;

         body.emit(assign(r00C1, lshift(r00BB, r00C4), 0x01));

         ir_expression *const r00CA = lshift(r00BA, r00C4);
         ir_expression *const r00CB = rshift(r00BB, r00BD);
         body.emit(assign(r00C2, bit_or(r00CA, r00CB), 0x01));

         body.emit(assign(r00C3, rshift(r00BA, r00BD), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00C8->else_instructions;

         /* IF CONDITION */
         ir_expression *const r00CD = equal(r00BD, body.constant(int(32)));
         ir_if *f00CC = new(mem_ctx) ir_if(operand(r00CD).val);
         exec_list *const f00CC_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f00CC->then_instructions;

            body.emit(assign(r00C1, r00BB, 0x01));

            body.emit(assign(r00C2, r00BA, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f00CC->else_instructions;

            body.emit(assign(r00BC, bit_or(r00BC, r00BB), 0x01));

            /* IF CONDITION */
            ir_expression *const r00CF = less(r00BD, body.constant(int(64)));
            ir_if *f00CE = new(mem_ctx) ir_if(operand(r00CF).val);
            exec_list *const f00CE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f00CE->then_instructions;

               body.emit(assign(r00C1, lshift(r00BA, r00C4), 0x01));

               ir_expression *const r00D0 = bit_and(r00BD, body.constant(int(31)));
               body.emit(assign(r00C2, rshift(r00BA, r00D0), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f00CE->else_instructions;

               ir_variable *const r00D1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r00D3 = equal(r00BD, body.constant(int(64)));
               ir_if *f00D2 = new(mem_ctx) ir_if(operand(r00D3).val);
               exec_list *const f00D2_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f00D2->then_instructions;

                  body.emit(assign(r00D1, r00BA, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f00D2->else_instructions;

                  ir_expression *const r00D4 = nequal(r00BA, body.constant(0u));
                  ir_expression *const r00D5 = expr(ir_unop_b2i, r00D4);
                  body.emit(assign(r00D1, expr(ir_unop_i2u, r00D5), 0x01));


               body.instructions = f00D2_parent_instructions;
               body.emit(f00D2);

               /* END IF */

               body.emit(assign(r00C1, r00D1, 0x01));

               body.emit(assign(r00C2, body.constant(0u), 0x01));


            body.instructions = f00CE_parent_instructions;
            body.emit(f00CE);

            /* END IF */


         body.instructions = f00CC_parent_instructions;
         body.emit(f00CC);

         /* END IF */

         body.emit(assign(r00C3, body.constant(0u), 0x01));


      body.instructions = f00C8_parent_instructions;
      body.emit(f00C8);

      /* END IF */

      ir_expression *const r00D6 = nequal(r00BC, body.constant(0u));
      ir_expression *const r00D7 = expr(ir_unop_b2i, r00D6);
      ir_expression *const r00D8 = expr(ir_unop_i2u, r00D7);
      body.emit(assign(r00C1, bit_or(r00C1, r00D8), 0x01));


   body.instructions = f00C6_parent_instructions;
   body.emit(f00C6);

   /* END IF */

   body.emit(assign(r00C0, r00C1, 0x01));

   body.emit(assign(r00BF, r00C2, 0x01));

   body.emit(assign(r00BE, r00C3, 0x01));

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

   ir_variable *const r00D9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r00D9);
   ir_variable *const r00DA = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r00DA);
   ir_variable *const r00DB = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r00DB);
   ir_variable *const r00DC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00DC);
   ir_variable *const r00DD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r00DD);
   body.emit(assign(r00DD, lshift(r00DA, r00DB), 0x01));

   ir_variable *const r00DE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
   /* IF CONDITION */
   ir_expression *const r00E0 = equal(r00DB, body.constant(int(0)));
   ir_if *f00DF = new(mem_ctx) ir_if(operand(r00E0).val);
   exec_list *const f00DF_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00DF->then_instructions;

      body.emit(assign(r00DE, r00D9, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f00DF->else_instructions;

      ir_expression *const r00E1 = lshift(r00D9, r00DB);
      ir_expression *const r00E2 = neg(r00DB);
      ir_expression *const r00E3 = bit_and(r00E2, body.constant(int(31)));
      ir_expression *const r00E4 = rshift(r00DA, r00E3);
      body.emit(assign(r00DE, bit_or(r00E1, r00E4), 0x01));


   body.instructions = f00DF_parent_instructions;
   body.emit(f00DF);

   /* END IF */

   body.emit(assign(r00DC, r00DE, 0x01));

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

   ir_variable *const r00E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00E5);
   ir_variable *const r00E6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00E6);
   ir_variable *const r00E7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00E7);
   ir_variable *const r00E8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00E8);
   ir_variable *const r00E9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
   body.emit(r00E9);
   ir_expression *const r00EA = lshift(r00E5, body.constant(int(31)));
   ir_expression *const r00EB = expr(ir_unop_i2u, r00E6);
   ir_expression *const r00EC = lshift(r00EB, body.constant(int(20)));
   ir_expression *const r00ED = add(r00EA, r00EC);
   body.emit(assign(r00E9, add(r00ED, r00E7), 0x02));

   body.emit(assign(r00E9, r00E8, 0x01));

   body.emit(ret(r00E9));

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

   ir_variable *const r00EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r00EE);
   ir_variable *const r00EF = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r00EF);
   ir_variable *const r00F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r00F0);
   ir_variable *const r00F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r00F1);
   ir_variable *const r00F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_function_in);
   sig_parameters.push_tail(r00F2);
   ir_variable *const r00F3 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r00F3, body.constant(true), 0x01));

   ir_variable *const r00F4 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r00F5 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r00F5);
   ir_expression *const r00F6 = expr(ir_unop_u2i, r00F2);
   body.emit(assign(r00F5, less(r00F6, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r00F8 = lequal(body.constant(int(2045)), r00EF);
   ir_if *f00F7 = new(mem_ctx) ir_if(operand(r00F8).val);
   exec_list *const f00F7_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f00F7->then_instructions;

      /* IF CONDITION */
      ir_expression *const r00FA = less(body.constant(int(2045)), r00EF);
      ir_expression *const r00FB = equal(r00EF, body.constant(int(2045)));
      ir_expression *const r00FC = equal(body.constant(2097151u), r00F0);
      ir_expression *const r00FD = equal(body.constant(4294967295u), r00F1);
      ir_expression *const r00FE = logic_and(r00FC, r00FD);
      ir_expression *const r00FF = logic_and(r00FB, r00FE);
      ir_expression *const r0100 = logic_and(r00FF, r00F5);
      ir_expression *const r0101 = logic_or(r00FA, r0100);
      ir_if *f00F9 = new(mem_ctx) ir_if(operand(r0101).val);
      exec_list *const f00F9_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f00F9->then_instructions;

         ir_variable *const r0102 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0102);
         ir_expression *const r0103 = lshift(r00EE, body.constant(int(31)));
         body.emit(assign(r0102, add(r0103, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0102, body.constant(0u), 0x01));

         body.emit(assign(r00F4, r0102, 0x03));

         body.emit(assign(r00F3, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f00F9->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0105 = less(r00EF, body.constant(int(0)));
         ir_if *f0104 = new(mem_ctx) ir_if(operand(r0105).val);
         exec_list *const f0104_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0104->then_instructions;

            ir_variable *const r0106 = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r0106, r00F2, 0x01));

            ir_variable *const r0107 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r0107, neg(r00EF), 0x01));

            ir_variable *const r0108 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0108);
            ir_variable *const r0109 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0109);
            ir_variable *const r010A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r010A);
            ir_variable *const r010B = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r010C = neg(r0107);
            body.emit(assign(r010B, bit_and(r010C, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r010E = equal(r0107, body.constant(int(0)));
            ir_if *f010D = new(mem_ctx) ir_if(operand(r010E).val);
            exec_list *const f010D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f010D->then_instructions;

               body.emit(assign(r0108, r00F2, 0x01));

               body.emit(assign(r0109, r00F1, 0x01));

               body.emit(assign(r010A, r00F0, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f010D->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0110 = less(r0107, body.constant(int(32)));
               ir_if *f010F = new(mem_ctx) ir_if(operand(r0110).val);
               exec_list *const f010F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f010F->then_instructions;

                  body.emit(assign(r0108, lshift(r00F1, r010B), 0x01));

                  ir_expression *const r0111 = lshift(r00F0, r010B);
                  ir_expression *const r0112 = rshift(r00F1, r0107);
                  body.emit(assign(r0109, bit_or(r0111, r0112), 0x01));

                  body.emit(assign(r010A, rshift(r00F0, r0107), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f010F->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0114 = equal(r0107, body.constant(int(32)));
                  ir_if *f0113 = new(mem_ctx) ir_if(operand(r0114).val);
                  exec_list *const f0113_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0113->then_instructions;

                     body.emit(assign(r0108, r00F1, 0x01));

                     body.emit(assign(r0109, r00F0, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0113->else_instructions;

                     body.emit(assign(r0106, bit_or(r00F2, r00F1), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0116 = less(r0107, body.constant(int(64)));
                     ir_if *f0115 = new(mem_ctx) ir_if(operand(r0116).val);
                     exec_list *const f0115_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0115->then_instructions;

                        body.emit(assign(r0108, lshift(r00F0, r010B), 0x01));

                        ir_expression *const r0117 = bit_and(r0107, body.constant(int(31)));
                        body.emit(assign(r0109, rshift(r00F0, r0117), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0115->else_instructions;

                        ir_variable *const r0118 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r011A = equal(r0107, body.constant(int(64)));
                        ir_if *f0119 = new(mem_ctx) ir_if(operand(r011A).val);
                        exec_list *const f0119_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0119->then_instructions;

                           body.emit(assign(r0118, r00F0, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0119->else_instructions;

                           ir_expression *const r011B = nequal(r00F0, body.constant(0u));
                           ir_expression *const r011C = expr(ir_unop_b2i, r011B);
                           body.emit(assign(r0118, expr(ir_unop_i2u, r011C), 0x01));


                        body.instructions = f0119_parent_instructions;
                        body.emit(f0119);

                        /* END IF */

                        body.emit(assign(r0108, r0118, 0x01));

                        body.emit(assign(r0109, body.constant(0u), 0x01));


                     body.instructions = f0115_parent_instructions;
                     body.emit(f0115);

                     /* END IF */


                  body.instructions = f0113_parent_instructions;
                  body.emit(f0113);

                  /* END IF */

                  body.emit(assign(r010A, body.constant(0u), 0x01));


               body.instructions = f010F_parent_instructions;
               body.emit(f010F);

               /* END IF */

               ir_expression *const r011D = nequal(r0106, body.constant(0u));
               ir_expression *const r011E = expr(ir_unop_b2i, r011D);
               ir_expression *const r011F = expr(ir_unop_i2u, r011E);
               body.emit(assign(r0108, bit_or(r0108, r011F), 0x01));


            body.instructions = f010D_parent_instructions;
            body.emit(f010D);

            /* END IF */

            body.emit(assign(r00F0, r010A, 0x01));

            body.emit(assign(r00F1, r0109, 0x01));

            body.emit(assign(r00F2, r0108, 0x01));

            body.emit(assign(r00EF, body.constant(int(0)), 0x01));

            body.emit(assign(r00F5, less(r0108, body.constant(0u)), 0x01));


         body.instructions = f0104_parent_instructions;
         body.emit(f0104);

         /* END IF */


      body.instructions = f00F9_parent_instructions;
      body.emit(f00F9);

      /* END IF */


   body.instructions = f00F7_parent_instructions;
   body.emit(f00F7);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0120 = new(mem_ctx) ir_if(operand(r00F3).val);
   exec_list *const f0120_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0120->then_instructions;

      /* IF CONDITION */
      ir_if *f0121 = new(mem_ctx) ir_if(operand(r00F5).val);
      exec_list *const f0121_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0121->then_instructions;

         ir_variable *const r0122 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0122, add(r00F1, body.constant(1u)), 0x01));

         ir_expression *const r0123 = less(r0122, r00F1);
         ir_expression *const r0124 = expr(ir_unop_b2i, r0123);
         ir_expression *const r0125 = expr(ir_unop_i2u, r0124);
         body.emit(assign(r00F0, add(r00F0, r0125), 0x01));

         ir_expression *const r0126 = equal(r00F2, body.constant(0u));
         ir_expression *const r0127 = expr(ir_unop_b2i, r0126);
         ir_expression *const r0128 = expr(ir_unop_i2u, r0127);
         ir_expression *const r0129 = add(r00F2, r0128);
         ir_expression *const r012A = bit_and(r0129, body.constant(1u));
         ir_expression *const r012B = expr(ir_unop_bit_not, r012A);
         body.emit(assign(r00F1, bit_and(r0122, r012B), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0121->else_instructions;

         /* IF CONDITION */
         ir_expression *const r012D = bit_or(r00F0, r00F1);
         ir_expression *const r012E = equal(r012D, body.constant(0u));
         ir_if *f012C = new(mem_ctx) ir_if(operand(r012E).val);
         exec_list *const f012C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f012C->then_instructions;

            body.emit(assign(r00EF, body.constant(int(0)), 0x01));


         body.instructions = f012C_parent_instructions;
         body.emit(f012C);

         /* END IF */


      body.instructions = f0121_parent_instructions;
      body.emit(f0121);

      /* END IF */

      ir_variable *const r012F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r012F);
      ir_expression *const r0130 = lshift(r00EE, body.constant(int(31)));
      ir_expression *const r0131 = expr(ir_unop_i2u, r00EF);
      ir_expression *const r0132 = lshift(r0131, body.constant(int(20)));
      ir_expression *const r0133 = add(r0130, r0132);
      body.emit(assign(r012F, add(r0133, r00F0), 0x02));

      body.emit(assign(r012F, r00F1, 0x01));

      body.emit(assign(r00F4, r012F, 0x03));

      body.emit(assign(r00F3, body.constant(false), 0x01));


   body.instructions = f0120_parent_instructions;
   body.emit(f0120);

   /* END IF */

   body.emit(ret(r00F4));

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

   ir_variable *const r0134 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0134);
   ir_variable *const r0135 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0136 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0136);
   /* IF CONDITION */
   ir_expression *const r0138 = equal(r0134, body.constant(0u));
   ir_if *f0137 = new(mem_ctx) ir_if(operand(r0138).val);
   exec_list *const f0137_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0137->then_instructions;

      body.emit(assign(r0135, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0137->else_instructions;

      body.emit(assign(r0136, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r013A = bit_and(r0134, body.constant(4294901760u));
      ir_expression *const r013B = equal(r013A, body.constant(0u));
      ir_if *f0139 = new(mem_ctx) ir_if(operand(r013B).val);
      exec_list *const f0139_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0139->then_instructions;

         body.emit(assign(r0136, body.constant(int(16)), 0x01));

         body.emit(assign(r0134, lshift(r0134, body.constant(int(16))), 0x01));


      body.instructions = f0139_parent_instructions;
      body.emit(f0139);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r013D = bit_and(r0134, body.constant(4278190080u));
      ir_expression *const r013E = equal(r013D, body.constant(0u));
      ir_if *f013C = new(mem_ctx) ir_if(operand(r013E).val);
      exec_list *const f013C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f013C->then_instructions;

         body.emit(assign(r0136, add(r0136, body.constant(int(8))), 0x01));

         body.emit(assign(r0134, lshift(r0134, body.constant(int(8))), 0x01));


      body.instructions = f013C_parent_instructions;
      body.emit(f013C);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0140 = bit_and(r0134, body.constant(4026531840u));
      ir_expression *const r0141 = equal(r0140, body.constant(0u));
      ir_if *f013F = new(mem_ctx) ir_if(operand(r0141).val);
      exec_list *const f013F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f013F->then_instructions;

         body.emit(assign(r0136, add(r0136, body.constant(int(4))), 0x01));

         body.emit(assign(r0134, lshift(r0134, body.constant(int(4))), 0x01));


      body.instructions = f013F_parent_instructions;
      body.emit(f013F);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0143 = bit_and(r0134, body.constant(3221225472u));
      ir_expression *const r0144 = equal(r0143, body.constant(0u));
      ir_if *f0142 = new(mem_ctx) ir_if(operand(r0144).val);
      exec_list *const f0142_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0142->then_instructions;

         body.emit(assign(r0136, add(r0136, body.constant(int(2))), 0x01));

         body.emit(assign(r0134, lshift(r0134, body.constant(int(2))), 0x01));


      body.instructions = f0142_parent_instructions;
      body.emit(f0142);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0146 = bit_and(r0134, body.constant(2147483648u));
      ir_expression *const r0147 = equal(r0146, body.constant(0u));
      ir_if *f0145 = new(mem_ctx) ir_if(operand(r0147).val);
      exec_list *const f0145_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0145->then_instructions;

         body.emit(assign(r0136, add(r0136, body.constant(int(1))), 0x01));


      body.instructions = f0145_parent_instructions;
      body.emit(f0145);

      /* END IF */

      body.emit(assign(r0135, r0136, 0x01));


   body.instructions = f0137_parent_instructions;
   body.emit(f0137);

   /* END IF */

   body.emit(ret(r0135));

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

   ir_variable *const r0148 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0148);
   ir_variable *const r0149 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0149);
   ir_variable *const r014A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_function_in);
   sig_parameters.push_tail(r014A);
   ir_variable *const r014B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_function_in);
   sig_parameters.push_tail(r014B);
   ir_variable *const r014C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r014C);
   ir_variable *const r014D = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r014D);
   /* IF CONDITION */
   ir_expression *const r014F = equal(r014A, body.constant(0u));
   ir_if *f014E = new(mem_ctx) ir_if(operand(r014F).val);
   exec_list *const f014E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f014E->then_instructions;

      body.emit(assign(r014A, r014B, 0x01));

      body.emit(assign(r014B, body.constant(0u), 0x01));

      body.emit(assign(r0149, add(r0149, body.constant(int(-32))), 0x01));


   body.instructions = f014E_parent_instructions;
   body.emit(f014E);

   /* END IF */

   ir_variable *const r0150 = body.make_temp(glsl_type::uint_type, "a");
   body.emit(assign(r0150, r014A, 0x01));

   ir_variable *const r0151 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0152 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r0152);
   /* IF CONDITION */
   ir_expression *const r0154 = equal(r014A, body.constant(0u));
   ir_if *f0153 = new(mem_ctx) ir_if(operand(r0154).val);
   exec_list *const f0153_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0153->then_instructions;

      body.emit(assign(r0151, body.constant(int(32)), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0153->else_instructions;

      body.emit(assign(r0152, body.constant(int(0)), 0x01));

      /* IF CONDITION */
      ir_expression *const r0156 = bit_and(r014A, body.constant(4294901760u));
      ir_expression *const r0157 = equal(r0156, body.constant(0u));
      ir_if *f0155 = new(mem_ctx) ir_if(operand(r0157).val);
      exec_list *const f0155_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0155->then_instructions;

         body.emit(assign(r0152, body.constant(int(16)), 0x01));

         body.emit(assign(r0150, lshift(r014A, body.constant(int(16))), 0x01));


      body.instructions = f0155_parent_instructions;
      body.emit(f0155);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0159 = bit_and(r0150, body.constant(4278190080u));
      ir_expression *const r015A = equal(r0159, body.constant(0u));
      ir_if *f0158 = new(mem_ctx) ir_if(operand(r015A).val);
      exec_list *const f0158_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0158->then_instructions;

         body.emit(assign(r0152, add(r0152, body.constant(int(8))), 0x01));

         body.emit(assign(r0150, lshift(r0150, body.constant(int(8))), 0x01));


      body.instructions = f0158_parent_instructions;
      body.emit(f0158);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r015C = bit_and(r0150, body.constant(4026531840u));
      ir_expression *const r015D = equal(r015C, body.constant(0u));
      ir_if *f015B = new(mem_ctx) ir_if(operand(r015D).val);
      exec_list *const f015B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f015B->then_instructions;

         body.emit(assign(r0152, add(r0152, body.constant(int(4))), 0x01));

         body.emit(assign(r0150, lshift(r0150, body.constant(int(4))), 0x01));


      body.instructions = f015B_parent_instructions;
      body.emit(f015B);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r015F = bit_and(r0150, body.constant(3221225472u));
      ir_expression *const r0160 = equal(r015F, body.constant(0u));
      ir_if *f015E = new(mem_ctx) ir_if(operand(r0160).val);
      exec_list *const f015E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f015E->then_instructions;

         body.emit(assign(r0152, add(r0152, body.constant(int(2))), 0x01));

         body.emit(assign(r0150, lshift(r0150, body.constant(int(2))), 0x01));


      body.instructions = f015E_parent_instructions;
      body.emit(f015E);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0162 = bit_and(r0150, body.constant(2147483648u));
      ir_expression *const r0163 = equal(r0162, body.constant(0u));
      ir_if *f0161 = new(mem_ctx) ir_if(operand(r0163).val);
      exec_list *const f0161_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0161->then_instructions;

         body.emit(assign(r0152, add(r0152, body.constant(int(1))), 0x01));


      body.instructions = f0161_parent_instructions;
      body.emit(f0161);

      /* END IF */

      body.emit(assign(r0151, r0152, 0x01));


   body.instructions = f0153_parent_instructions;
   body.emit(f0153);

   /* END IF */

   body.emit(assign(r014D, add(r0151, body.constant(int(-11))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0165 = lequal(body.constant(int(0)), r014D);
   ir_if *f0164 = new(mem_ctx) ir_if(operand(r0165).val);
   exec_list *const f0164_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0164->then_instructions;

      body.emit(assign(r014C, body.constant(0u), 0x01));

      ir_variable *const r0166 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0166, lshift(r014B, r014D), 0x01));

      ir_variable *const r0167 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0169 = equal(r014D, body.constant(int(0)));
      ir_if *f0168 = new(mem_ctx) ir_if(operand(r0169).val);
      exec_list *const f0168_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0168->then_instructions;

         body.emit(assign(r0167, r014A, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0168->else_instructions;

         ir_expression *const r016A = lshift(r014A, r014D);
         ir_expression *const r016B = neg(r014D);
         ir_expression *const r016C = bit_and(r016B, body.constant(int(31)));
         ir_expression *const r016D = rshift(r014B, r016C);
         body.emit(assign(r0167, bit_or(r016A, r016D), 0x01));


      body.instructions = f0168_parent_instructions;
      body.emit(f0168);

      /* END IF */

      body.emit(assign(r014A, r0167, 0x01));

      body.emit(assign(r014B, r0166, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0164->else_instructions;

      ir_variable *const r016E = body.make_temp(glsl_type::uint_type, "a2");
      body.emit(assign(r016E, body.constant(0u), 0x01));

      ir_variable *const r016F = body.make_temp(glsl_type::int_type, "count");
      body.emit(assign(r016F, neg(r014D), 0x01));

      ir_variable *const r0170 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
      body.emit(r0170);
      ir_variable *const r0171 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0171);
      ir_variable *const r0172 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0172);
      ir_variable *const r0173 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0174 = neg(r016F);
      body.emit(assign(r0173, bit_and(r0174, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0176 = equal(r016F, body.constant(int(0)));
      ir_if *f0175 = new(mem_ctx) ir_if(operand(r0176).val);
      exec_list *const f0175_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0175->then_instructions;

         body.emit(assign(r0170, r016E, 0x01));

         body.emit(assign(r0171, r014B, 0x01));

         body.emit(assign(r0172, r014A, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0175->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0178 = less(r016F, body.constant(int(32)));
         ir_if *f0177 = new(mem_ctx) ir_if(operand(r0178).val);
         exec_list *const f0177_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0177->then_instructions;

            body.emit(assign(r0170, lshift(r014B, r0173), 0x01));

            ir_expression *const r0179 = lshift(r014A, r0173);
            ir_expression *const r017A = rshift(r014B, r016F);
            body.emit(assign(r0171, bit_or(r0179, r017A), 0x01));

            body.emit(assign(r0172, rshift(r014A, r016F), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0177->else_instructions;

            /* IF CONDITION */
            ir_expression *const r017C = equal(r016F, body.constant(int(32)));
            ir_if *f017B = new(mem_ctx) ir_if(operand(r017C).val);
            exec_list *const f017B_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f017B->then_instructions;

               body.emit(assign(r0170, r014B, 0x01));

               body.emit(assign(r0171, r014A, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f017B->else_instructions;

               body.emit(assign(r016E, bit_or(body.constant(0u), r014B), 0x01));

               /* IF CONDITION */
               ir_expression *const r017E = less(r016F, body.constant(int(64)));
               ir_if *f017D = new(mem_ctx) ir_if(operand(r017E).val);
               exec_list *const f017D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f017D->then_instructions;

                  body.emit(assign(r0170, lshift(r014A, r0173), 0x01));

                  ir_expression *const r017F = bit_and(r016F, body.constant(int(31)));
                  body.emit(assign(r0171, rshift(r014A, r017F), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f017D->else_instructions;

                  ir_variable *const r0180 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r0182 = equal(r016F, body.constant(int(64)));
                  ir_if *f0181 = new(mem_ctx) ir_if(operand(r0182).val);
                  exec_list *const f0181_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0181->then_instructions;

                     body.emit(assign(r0180, r014A, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0181->else_instructions;

                     ir_expression *const r0183 = nequal(r014A, body.constant(0u));
                     ir_expression *const r0184 = expr(ir_unop_b2i, r0183);
                     body.emit(assign(r0180, expr(ir_unop_i2u, r0184), 0x01));


                  body.instructions = f0181_parent_instructions;
                  body.emit(f0181);

                  /* END IF */

                  body.emit(assign(r0170, r0180, 0x01));

                  body.emit(assign(r0171, body.constant(0u), 0x01));


               body.instructions = f017D_parent_instructions;
               body.emit(f017D);

               /* END IF */


            body.instructions = f017B_parent_instructions;
            body.emit(f017B);

            /* END IF */

            body.emit(assign(r0172, body.constant(0u), 0x01));


         body.instructions = f0177_parent_instructions;
         body.emit(f0177);

         /* END IF */

         ir_expression *const r0185 = nequal(r016E, body.constant(0u));
         ir_expression *const r0186 = expr(ir_unop_b2i, r0185);
         ir_expression *const r0187 = expr(ir_unop_i2u, r0186);
         body.emit(assign(r0170, bit_or(r0170, r0187), 0x01));


      body.instructions = f0175_parent_instructions;
      body.emit(f0175);

      /* END IF */

      body.emit(assign(r014A, r0172, 0x01));

      body.emit(assign(r014B, r0171, 0x01));

      body.emit(assign(r014C, r0170, 0x01));


   body.instructions = f0164_parent_instructions;
   body.emit(f0164);

   /* END IF */

   body.emit(assign(r0149, sub(r0149, r014D), 0x01));

   ir_variable *const r0188 = body.make_temp(glsl_type::int_type, "zExp");
   body.emit(assign(r0188, r0149, 0x01));

   ir_variable *const r0189 = body.make_temp(glsl_type::uint_type, "zFrac0");
   body.emit(assign(r0189, r014A, 0x01));

   ir_variable *const r018A = body.make_temp(glsl_type::uint_type, "zFrac1");
   body.emit(assign(r018A, r014B, 0x01));

   ir_variable *const r018B = body.make_temp(glsl_type::uint_type, "zFrac2");
   body.emit(assign(r018B, r014C, 0x01));

   ir_variable *const r018C = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r018C, body.constant(true), 0x01));

   ir_variable *const r018D = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r018E = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
   body.emit(r018E);
   ir_expression *const r018F = expr(ir_unop_u2i, r014C);
   body.emit(assign(r018E, less(r018F, body.constant(int(0))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0191 = lequal(body.constant(int(2045)), r0149);
   ir_if *f0190 = new(mem_ctx) ir_if(operand(r0191).val);
   exec_list *const f0190_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0190->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0193 = less(body.constant(int(2045)), r0149);
      ir_expression *const r0194 = equal(r0149, body.constant(int(2045)));
      ir_expression *const r0195 = equal(body.constant(2097151u), r014A);
      ir_expression *const r0196 = equal(body.constant(4294967295u), r014B);
      ir_expression *const r0197 = logic_and(r0195, r0196);
      ir_expression *const r0198 = logic_and(r0194, r0197);
      ir_expression *const r0199 = logic_and(r0198, r018E);
      ir_expression *const r019A = logic_or(r0193, r0199);
      ir_if *f0192 = new(mem_ctx) ir_if(operand(r019A).val);
      exec_list *const f0192_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0192->then_instructions;

         ir_variable *const r019B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r019B);
         ir_expression *const r019C = lshift(r0148, body.constant(int(31)));
         body.emit(assign(r019B, add(r019C, body.constant(2146435072u)), 0x02));

         body.emit(assign(r019B, body.constant(0u), 0x01));

         body.emit(assign(r018D, r019B, 0x03));

         body.emit(assign(r018C, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0192->else_instructions;

         /* IF CONDITION */
         ir_expression *const r019E = less(r0149, body.constant(int(0)));
         ir_if *f019D = new(mem_ctx) ir_if(operand(r019E).val);
         exec_list *const f019D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f019D->then_instructions;

            ir_variable *const r019F = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r019F, r014C, 0x01));

            ir_variable *const r01A0 = body.make_temp(glsl_type::int_type, "count");
            body.emit(assign(r01A0, neg(r0149), 0x01));

            ir_variable *const r01A1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r01A1);
            ir_variable *const r01A2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r01A2);
            ir_variable *const r01A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r01A3);
            ir_variable *const r01A4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r01A5 = neg(r01A0);
            body.emit(assign(r01A4, bit_and(r01A5, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r01A7 = equal(r01A0, body.constant(int(0)));
            ir_if *f01A6 = new(mem_ctx) ir_if(operand(r01A7).val);
            exec_list *const f01A6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f01A6->then_instructions;

               body.emit(assign(r01A1, r014C, 0x01));

               body.emit(assign(r01A2, r014B, 0x01));

               body.emit(assign(r01A3, r014A, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f01A6->else_instructions;

               /* IF CONDITION */
               ir_expression *const r01A9 = less(r01A0, body.constant(int(32)));
               ir_if *f01A8 = new(mem_ctx) ir_if(operand(r01A9).val);
               exec_list *const f01A8_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f01A8->then_instructions;

                  body.emit(assign(r01A1, lshift(r014B, r01A4), 0x01));

                  ir_expression *const r01AA = lshift(r014A, r01A4);
                  ir_expression *const r01AB = rshift(r014B, r01A0);
                  body.emit(assign(r01A2, bit_or(r01AA, r01AB), 0x01));

                  body.emit(assign(r01A3, rshift(r014A, r01A0), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f01A8->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r01AD = equal(r01A0, body.constant(int(32)));
                  ir_if *f01AC = new(mem_ctx) ir_if(operand(r01AD).val);
                  exec_list *const f01AC_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f01AC->then_instructions;

                     body.emit(assign(r01A1, r014B, 0x01));

                     body.emit(assign(r01A2, r014A, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f01AC->else_instructions;

                     body.emit(assign(r019F, bit_or(r014C, r014B), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r01AF = less(r01A0, body.constant(int(64)));
                     ir_if *f01AE = new(mem_ctx) ir_if(operand(r01AF).val);
                     exec_list *const f01AE_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f01AE->then_instructions;

                        body.emit(assign(r01A1, lshift(r014A, r01A4), 0x01));

                        ir_expression *const r01B0 = bit_and(r01A0, body.constant(int(31)));
                        body.emit(assign(r01A2, rshift(r014A, r01B0), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f01AE->else_instructions;

                        ir_variable *const r01B1 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r01B3 = equal(r01A0, body.constant(int(64)));
                        ir_if *f01B2 = new(mem_ctx) ir_if(operand(r01B3).val);
                        exec_list *const f01B2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f01B2->then_instructions;

                           body.emit(assign(r01B1, r014A, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f01B2->else_instructions;

                           ir_expression *const r01B4 = nequal(r014A, body.constant(0u));
                           ir_expression *const r01B5 = expr(ir_unop_b2i, r01B4);
                           body.emit(assign(r01B1, expr(ir_unop_i2u, r01B5), 0x01));


                        body.instructions = f01B2_parent_instructions;
                        body.emit(f01B2);

                        /* END IF */

                        body.emit(assign(r01A1, r01B1, 0x01));

                        body.emit(assign(r01A2, body.constant(0u), 0x01));


                     body.instructions = f01AE_parent_instructions;
                     body.emit(f01AE);

                     /* END IF */


                  body.instructions = f01AC_parent_instructions;
                  body.emit(f01AC);

                  /* END IF */

                  body.emit(assign(r01A3, body.constant(0u), 0x01));


               body.instructions = f01A8_parent_instructions;
               body.emit(f01A8);

               /* END IF */

               ir_expression *const r01B6 = nequal(r019F, body.constant(0u));
               ir_expression *const r01B7 = expr(ir_unop_b2i, r01B6);
               ir_expression *const r01B8 = expr(ir_unop_i2u, r01B7);
               body.emit(assign(r01A1, bit_or(r01A1, r01B8), 0x01));


            body.instructions = f01A6_parent_instructions;
            body.emit(f01A6);

            /* END IF */

            body.emit(assign(r0189, r01A3, 0x01));

            body.emit(assign(r018A, r01A2, 0x01));

            body.emit(assign(r018B, r01A1, 0x01));

            body.emit(assign(r0188, body.constant(int(0)), 0x01));

            body.emit(assign(r018E, less(r01A1, body.constant(0u)), 0x01));


         body.instructions = f019D_parent_instructions;
         body.emit(f019D);

         /* END IF */


      body.instructions = f0192_parent_instructions;
      body.emit(f0192);

      /* END IF */


   body.instructions = f0190_parent_instructions;
   body.emit(f0190);

   /* END IF */

   /* IF CONDITION */
   ir_if *f01B9 = new(mem_ctx) ir_if(operand(r018C).val);
   exec_list *const f01B9_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01B9->then_instructions;

      /* IF CONDITION */
      ir_if *f01BA = new(mem_ctx) ir_if(operand(r018E).val);
      exec_list *const f01BA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01BA->then_instructions;

         ir_variable *const r01BB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r01BB, add(r018A, body.constant(1u)), 0x01));

         ir_expression *const r01BC = less(r01BB, r018A);
         ir_expression *const r01BD = expr(ir_unop_b2i, r01BC);
         ir_expression *const r01BE = expr(ir_unop_i2u, r01BD);
         body.emit(assign(r0189, add(r0189, r01BE), 0x01));

         ir_expression *const r01BF = equal(r018B, body.constant(0u));
         ir_expression *const r01C0 = expr(ir_unop_b2i, r01BF);
         ir_expression *const r01C1 = expr(ir_unop_i2u, r01C0);
         ir_expression *const r01C2 = add(r018B, r01C1);
         ir_expression *const r01C3 = bit_and(r01C2, body.constant(1u));
         ir_expression *const r01C4 = expr(ir_unop_bit_not, r01C3);
         body.emit(assign(r018A, bit_and(r01BB, r01C4), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01BA->else_instructions;

         /* IF CONDITION */
         ir_expression *const r01C6 = bit_or(r0189, r018A);
         ir_expression *const r01C7 = equal(r01C6, body.constant(0u));
         ir_if *f01C5 = new(mem_ctx) ir_if(operand(r01C7).val);
         exec_list *const f01C5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01C5->then_instructions;

            body.emit(assign(r0188, body.constant(int(0)), 0x01));


         body.instructions = f01C5_parent_instructions;
         body.emit(f01C5);

         /* END IF */


      body.instructions = f01BA_parent_instructions;
      body.emit(f01BA);

      /* END IF */

      ir_variable *const r01C8 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r01C8);
      ir_expression *const r01C9 = lshift(r0148, body.constant(int(31)));
      ir_expression *const r01CA = expr(ir_unop_i2u, r0188);
      ir_expression *const r01CB = lshift(r01CA, body.constant(int(20)));
      ir_expression *const r01CC = add(r01C9, r01CB);
      body.emit(assign(r01C8, add(r01CC, r0189), 0x02));

      body.emit(assign(r01C8, r018A, 0x01));

      body.emit(assign(r018D, r01C8, 0x03));

      body.emit(assign(r018C, body.constant(false), 0x01));


   body.instructions = f01B9_parent_instructions;
   body.emit(f01B9);

   /* END IF */

   body.emit(ret(r018D));

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

   ir_variable *const r01CD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01CD);
   ir_variable *const r01CE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01CE);
   ir_variable *const r01CF = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01D0 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01D1 = lshift(swizzle_y(r01CD), body.constant(int(1)));
   ir_expression *const r01D2 = lequal(body.constant(4292870144u), r01D1);
   ir_expression *const r01D3 = nequal(swizzle_x(r01CD), body.constant(0u));
   ir_expression *const r01D4 = bit_and(swizzle_y(r01CD), body.constant(1048575u));
   ir_expression *const r01D5 = nequal(r01D4, body.constant(0u));
   ir_expression *const r01D6 = logic_or(r01D3, r01D5);
   body.emit(assign(r01D0, logic_and(r01D2, r01D6), 0x01));

   ir_variable *const r01D7 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
   ir_expression *const r01D8 = lshift(swizzle_y(r01CE), body.constant(int(1)));
   ir_expression *const r01D9 = lequal(body.constant(4292870144u), r01D8);
   ir_expression *const r01DA = nequal(swizzle_x(r01CE), body.constant(0u));
   ir_expression *const r01DB = bit_and(swizzle_y(r01CE), body.constant(1048575u));
   ir_expression *const r01DC = nequal(r01DB, body.constant(0u));
   ir_expression *const r01DD = logic_or(r01DA, r01DC);
   body.emit(assign(r01D7, logic_and(r01D9, r01DD), 0x01));

   body.emit(assign(r01CD, bit_or(swizzle_y(r01CD), body.constant(524288u)), 0x02));

   body.emit(assign(r01CE, bit_or(swizzle_y(r01CE), body.constant(524288u)), 0x02));

   /* IF CONDITION */
   ir_if *f01DE = new(mem_ctx) ir_if(operand(r01D0).val);
   exec_list *const f01DE_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01DE->then_instructions;

      ir_variable *const r01DF = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
      /* IF CONDITION */
      ir_if *f01E0 = new(mem_ctx) ir_if(operand(r01D7).val);
      exec_list *const f01E0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01E0->then_instructions;

         body.emit(assign(r01DF, r01CE, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01E0->else_instructions;

         body.emit(assign(r01DF, r01CD, 0x03));


      body.instructions = f01E0_parent_instructions;
      body.emit(f01E0);

      /* END IF */

      body.emit(assign(r01CF, r01DF, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01DE->else_instructions;

      body.emit(assign(r01CF, r01CE, 0x03));


   body.instructions = f01DE_parent_instructions;
   body.emit(f01DE);

   /* END IF */

   body.emit(ret(r01CF));

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

   ir_variable *const r01E1 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r01E1);
   ir_variable *const r01E2 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r01E2);
   ir_variable *const r01E3 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r01E3, body.constant(true), 0x01));

   ir_variable *const r01E4 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r01E5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r01E5);
   ir_variable *const r01E6 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01E6, rshift(swizzle_y(r01E1), body.constant(int(31))), 0x01));

   body.emit(assign(r01E5, r01E6, 0x01));

   ir_variable *const r01E7 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r01E7, rshift(swizzle_y(r01E2), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r01E9 = equal(r01E6, r01E7);
   ir_if *f01E8 = new(mem_ctx) ir_if(operand(r01E9).val);
   exec_list *const f01E8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f01E8->then_instructions;

      ir_variable *const r01EA = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r01EA);
      ir_variable *const r01EB = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r01EB);
      ir_variable *const r01EC = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r01EC);
      ir_variable *const r01ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r01ED);
      ir_variable *const r01EE = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r01EE);
      ir_variable *const r01EF = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r01EF);
      ir_variable *const r01F0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
      body.emit(r01F0);
      ir_variable *const r01F1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
      body.emit(r01F1);
      body.emit(assign(r01F1, body.constant(0u), 0x01));

      body.emit(assign(r01F0, body.constant(0u), 0x01));

      ir_variable *const r01F2 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01F2, swizzle_x(r01E1), 0x01));

      body.emit(assign(r01EE, r01F2, 0x01));

      ir_variable *const r01F3 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01F3, bit_and(swizzle_y(r01E1), body.constant(1048575u)), 0x01));

      body.emit(assign(r01ED, r01F3, 0x01));

      ir_variable *const r01F4 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
      body.emit(assign(r01F4, swizzle_x(r01E2), 0x01));

      body.emit(assign(r01EC, r01F4, 0x01));

      ir_variable *const r01F5 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
      body.emit(assign(r01F5, bit_and(swizzle_y(r01E2), body.constant(1048575u)), 0x01));

      body.emit(assign(r01EB, r01F5, 0x01));

      ir_variable *const r01F6 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r01F7 = rshift(swizzle_y(r01E1), body.constant(int(20)));
      ir_expression *const r01F8 = bit_and(r01F7, body.constant(2047u));
      body.emit(assign(r01F6, expr(ir_unop_u2i, r01F8), 0x01));

      ir_variable *const r01F9 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r01FA = rshift(swizzle_y(r01E2), body.constant(int(20)));
      ir_expression *const r01FB = bit_and(r01FA, body.constant(2047u));
      body.emit(assign(r01F9, expr(ir_unop_u2i, r01FB), 0x01));

      ir_variable *const r01FC = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r01FC, sub(r01F6, r01F9), 0x01));

      body.emit(assign(r01EA, r01FC, 0x01));

      /* IF CONDITION */
      ir_expression *const r01FE = less(body.constant(int(0)), r01FC);
      ir_if *f01FD = new(mem_ctx) ir_if(operand(r01FE).val);
      exec_list *const f01FD_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f01FD->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0200 = equal(r01F6, body.constant(int(2047)));
         ir_if *f01FF = new(mem_ctx) ir_if(operand(r0200).val);
         exec_list *const f01FF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f01FF->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0202 = bit_or(r01F3, swizzle_x(r01E1));
            ir_expression *const r0203 = nequal(r0202, body.constant(0u));
            ir_if *f0201 = new(mem_ctx) ir_if(operand(r0203).val);
            exec_list *const f0201_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0201->then_instructions;

               ir_variable *const r0204 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0204, swizzle_x(r01E1), 0x01));

               ir_variable *const r0205 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0205, swizzle_x(r01E2), 0x01));

               ir_variable *const r0206 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0207 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r0208 = lshift(swizzle_y(r01E2), body.constant(int(1)));
               ir_expression *const r0209 = lequal(body.constant(4292870144u), r0208);
               ir_expression *const r020A = nequal(swizzle_x(r01E2), body.constant(0u));
               ir_expression *const r020B = bit_and(swizzle_y(r01E2), body.constant(1048575u));
               ir_expression *const r020C = nequal(r020B, body.constant(0u));
               ir_expression *const r020D = logic_or(r020A, r020C);
               body.emit(assign(r0207, logic_and(r0209, r020D), 0x01));

               body.emit(assign(r0204, bit_or(swizzle_y(r01E1), body.constant(524288u)), 0x02));

               body.emit(assign(r0205, bit_or(swizzle_y(r01E2), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r020F = lshift(swizzle_y(r01E1), body.constant(int(1)));
               ir_expression *const r0210 = lequal(body.constant(4292870144u), r020F);
               ir_expression *const r0211 = nequal(swizzle_x(r01E1), body.constant(0u));
               ir_expression *const r0212 = bit_and(swizzle_y(r01E1), body.constant(1048575u));
               ir_expression *const r0213 = nequal(r0212, body.constant(0u));
               ir_expression *const r0214 = logic_or(r0211, r0213);
               ir_expression *const r0215 = logic_and(r0210, r0214);
               ir_if *f020E = new(mem_ctx) ir_if(operand(r0215).val);
               exec_list *const f020E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f020E->then_instructions;

                  ir_variable *const r0216 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_if *f0217 = new(mem_ctx) ir_if(operand(r0207).val);
                  exec_list *const f0217_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0217->then_instructions;

                     body.emit(assign(r0216, r0205, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0217->else_instructions;

                     body.emit(assign(r0216, r0204, 0x03));


                  body.instructions = f0217_parent_instructions;
                  body.emit(f0217);

                  /* END IF */

                  body.emit(assign(r0206, r0216, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f020E->else_instructions;

                  body.emit(assign(r0206, r0205, 0x03));


               body.instructions = f020E_parent_instructions;
               body.emit(f020E);

               /* END IF */

               body.emit(assign(r01E4, r0206, 0x03));

               body.emit(assign(r01E3, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0201->else_instructions;

               body.emit(assign(r01E4, r01E1, 0x03));

               body.emit(assign(r01E3, body.constant(false), 0x01));


            body.instructions = f0201_parent_instructions;
            body.emit(f0201);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f01FF->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0219 = equal(r01F9, body.constant(int(0)));
            ir_if *f0218 = new(mem_ctx) ir_if(operand(r0219).val);
            exec_list *const f0218_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0218->then_instructions;

               body.emit(assign(r01EA, add(r01FC, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0218->else_instructions;

               body.emit(assign(r01EB, bit_or(r01F5, body.constant(1048576u)), 0x01));


            body.instructions = f0218_parent_instructions;
            body.emit(f0218);

            /* END IF */

            ir_variable *const r021A = body.make_temp(glsl_type::uint_type, "a2");
            body.emit(assign(r021A, body.constant(0u), 0x01));

            ir_variable *const r021B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r021B);
            ir_variable *const r021C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r021C);
            ir_variable *const r021D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r021D);
            ir_variable *const r021E = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r021F = neg(r01EA);
            body.emit(assign(r021E, bit_and(r021F, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0221 = equal(r01EA, body.constant(int(0)));
            ir_if *f0220 = new(mem_ctx) ir_if(operand(r0221).val);
            exec_list *const f0220_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0220->then_instructions;

               body.emit(assign(r021B, r021A, 0x01));

               body.emit(assign(r021C, r01F4, 0x01));

               body.emit(assign(r021D, r01EB, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0220->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0223 = less(r01EA, body.constant(int(32)));
               ir_if *f0222 = new(mem_ctx) ir_if(operand(r0223).val);
               exec_list *const f0222_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0222->then_instructions;

                  body.emit(assign(r021B, lshift(swizzle_x(r01E2), r021E), 0x01));

                  ir_expression *const r0224 = lshift(r01EB, r021E);
                  ir_expression *const r0225 = rshift(swizzle_x(r01E2), r01EA);
                  body.emit(assign(r021C, bit_or(r0224, r0225), 0x01));

                  body.emit(assign(r021D, rshift(r01EB, r01EA), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0222->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0227 = equal(r01EA, body.constant(int(32)));
                  ir_if *f0226 = new(mem_ctx) ir_if(operand(r0227).val);
                  exec_list *const f0226_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0226->then_instructions;

                     body.emit(assign(r021B, r01F4, 0x01));

                     body.emit(assign(r021C, r01EB, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0226->else_instructions;

                     body.emit(assign(r021A, bit_or(body.constant(0u), swizzle_x(r01E2)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0229 = less(r01EA, body.constant(int(64)));
                     ir_if *f0228 = new(mem_ctx) ir_if(operand(r0229).val);
                     exec_list *const f0228_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0228->then_instructions;

                        body.emit(assign(r021B, lshift(r01EB, r021E), 0x01));

                        ir_expression *const r022A = bit_and(r01EA, body.constant(int(31)));
                        body.emit(assign(r021C, rshift(r01EB, r022A), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0228->else_instructions;

                        ir_variable *const r022B = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r022D = equal(r01EA, body.constant(int(64)));
                        ir_if *f022C = new(mem_ctx) ir_if(operand(r022D).val);
                        exec_list *const f022C_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f022C->then_instructions;

                           body.emit(assign(r022B, r01EB, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f022C->else_instructions;

                           ir_expression *const r022E = nequal(r01EB, body.constant(0u));
                           ir_expression *const r022F = expr(ir_unop_b2i, r022E);
                           body.emit(assign(r022B, expr(ir_unop_i2u, r022F), 0x01));


                        body.instructions = f022C_parent_instructions;
                        body.emit(f022C);

                        /* END IF */

                        body.emit(assign(r021B, r022B, 0x01));

                        body.emit(assign(r021C, body.constant(0u), 0x01));


                     body.instructions = f0228_parent_instructions;
                     body.emit(f0228);

                     /* END IF */


                  body.instructions = f0226_parent_instructions;
                  body.emit(f0226);

                  /* END IF */

                  body.emit(assign(r021D, body.constant(0u), 0x01));


               body.instructions = f0222_parent_instructions;
               body.emit(f0222);

               /* END IF */

               ir_expression *const r0230 = nequal(r021A, body.constant(0u));
               ir_expression *const r0231 = expr(ir_unop_b2i, r0230);
               ir_expression *const r0232 = expr(ir_unop_i2u, r0231);
               body.emit(assign(r021B, bit_or(r021B, r0232), 0x01));


            body.instructions = f0220_parent_instructions;
            body.emit(f0220);

            /* END IF */

            body.emit(assign(r01EB, r021D, 0x01));

            body.emit(assign(r01EC, r021C, 0x01));

            body.emit(assign(r01F0, r021B, 0x01));

            body.emit(assign(r01EF, r01F6, 0x01));


         body.instructions = f01FF_parent_instructions;
         body.emit(f01FF);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f01FD->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0234 = less(r01EA, body.constant(int(0)));
         ir_if *f0233 = new(mem_ctx) ir_if(operand(r0234).val);
         exec_list *const f0233_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0233->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0236 = equal(r01F9, body.constant(int(2047)));
            ir_if *f0235 = new(mem_ctx) ir_if(operand(r0236).val);
            exec_list *const f0235_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0235->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0238 = bit_or(r01EB, r01EC);
               ir_expression *const r0239 = nequal(r0238, body.constant(0u));
               ir_if *f0237 = new(mem_ctx) ir_if(operand(r0239).val);
               exec_list *const f0237_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0237->then_instructions;

                  ir_variable *const r023A = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r023A, swizzle_x(r01E1), 0x01));

                  ir_variable *const r023B = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r023B, swizzle_x(r01E2), 0x01));

                  ir_variable *const r023C = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r023D = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r023E = lshift(swizzle_y(r01E2), body.constant(int(1)));
                  ir_expression *const r023F = lequal(body.constant(4292870144u), r023E);
                  ir_expression *const r0240 = nequal(swizzle_x(r01E2), body.constant(0u));
                  ir_expression *const r0241 = bit_and(swizzle_y(r01E2), body.constant(1048575u));
                  ir_expression *const r0242 = nequal(r0241, body.constant(0u));
                  ir_expression *const r0243 = logic_or(r0240, r0242);
                  body.emit(assign(r023D, logic_and(r023F, r0243), 0x01));

                  body.emit(assign(r023A, bit_or(swizzle_y(r01E1), body.constant(524288u)), 0x02));

                  body.emit(assign(r023B, bit_or(swizzle_y(r01E2), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0245 = lshift(swizzle_y(r01E1), body.constant(int(1)));
                  ir_expression *const r0246 = lequal(body.constant(4292870144u), r0245);
                  ir_expression *const r0247 = nequal(swizzle_x(r01E1), body.constant(0u));
                  ir_expression *const r0248 = bit_and(swizzle_y(r01E1), body.constant(1048575u));
                  ir_expression *const r0249 = nequal(r0248, body.constant(0u));
                  ir_expression *const r024A = logic_or(r0247, r0249);
                  ir_expression *const r024B = logic_and(r0246, r024A);
                  ir_if *f0244 = new(mem_ctx) ir_if(operand(r024B).val);
                  exec_list *const f0244_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0244->then_instructions;

                     ir_variable *const r024C = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f024D = new(mem_ctx) ir_if(operand(r023D).val);
                     exec_list *const f024D_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f024D->then_instructions;

                        body.emit(assign(r024C, r023B, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f024D->else_instructions;

                        body.emit(assign(r024C, r023A, 0x03));


                     body.instructions = f024D_parent_instructions;
                     body.emit(f024D);

                     /* END IF */

                     body.emit(assign(r023C, r024C, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0244->else_instructions;

                     body.emit(assign(r023C, r023B, 0x03));


                  body.instructions = f0244_parent_instructions;
                  body.emit(f0244);

                  /* END IF */

                  body.emit(assign(r01E4, r023C, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0237->else_instructions;

                  ir_variable *const r024E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r024E);
                  ir_expression *const r024F = lshift(r01E6, body.constant(int(31)));
                  body.emit(assign(r024E, add(r024F, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r024E, body.constant(0u), 0x01));

                  body.emit(assign(r01E4, r024E, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


               body.instructions = f0237_parent_instructions;
               body.emit(f0237);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0235->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0251 = equal(r01F6, body.constant(int(0)));
               ir_if *f0250 = new(mem_ctx) ir_if(operand(r0251).val);
               exec_list *const f0250_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0250->then_instructions;

                  body.emit(assign(r01EA, add(r01EA, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0250->else_instructions;

                  body.emit(assign(r01ED, bit_or(r01F3, body.constant(1048576u)), 0x01));


               body.instructions = f0250_parent_instructions;
               body.emit(f0250);

               /* END IF */

               ir_variable *const r0252 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r0252, body.constant(0u), 0x01));

               ir_variable *const r0253 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0253, neg(r01EA), 0x01));

               ir_variable *const r0254 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r0254);
               ir_variable *const r0255 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0255);
               ir_variable *const r0256 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0256);
               ir_variable *const r0257 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0258 = neg(r0253);
               body.emit(assign(r0257, bit_and(r0258, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r025A = equal(r0253, body.constant(int(0)));
               ir_if *f0259 = new(mem_ctx) ir_if(operand(r025A).val);
               exec_list *const f0259_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0259->then_instructions;

                  body.emit(assign(r0254, r0252, 0x01));

                  body.emit(assign(r0255, r01F2, 0x01));

                  body.emit(assign(r0256, r01ED, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0259->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r025C = less(r0253, body.constant(int(32)));
                  ir_if *f025B = new(mem_ctx) ir_if(operand(r025C).val);
                  exec_list *const f025B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f025B->then_instructions;

                     body.emit(assign(r0254, lshift(swizzle_x(r01E1), r0257), 0x01));

                     ir_expression *const r025D = lshift(r01ED, r0257);
                     ir_expression *const r025E = rshift(swizzle_x(r01E1), r0253);
                     body.emit(assign(r0255, bit_or(r025D, r025E), 0x01));

                     body.emit(assign(r0256, rshift(r01ED, r0253), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f025B->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0260 = equal(r0253, body.constant(int(32)));
                     ir_if *f025F = new(mem_ctx) ir_if(operand(r0260).val);
                     exec_list *const f025F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f025F->then_instructions;

                        body.emit(assign(r0254, r01F2, 0x01));

                        body.emit(assign(r0255, r01ED, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f025F->else_instructions;

                        body.emit(assign(r0252, bit_or(body.constant(0u), swizzle_x(r01E1)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0262 = less(r0253, body.constant(int(64)));
                        ir_if *f0261 = new(mem_ctx) ir_if(operand(r0262).val);
                        exec_list *const f0261_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0261->then_instructions;

                           body.emit(assign(r0254, lshift(r01ED, r0257), 0x01));

                           ir_expression *const r0263 = bit_and(r0253, body.constant(int(31)));
                           body.emit(assign(r0255, rshift(r01ED, r0263), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0261->else_instructions;

                           ir_variable *const r0264 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r0266 = equal(r0253, body.constant(int(64)));
                           ir_if *f0265 = new(mem_ctx) ir_if(operand(r0266).val);
                           exec_list *const f0265_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0265->then_instructions;

                              body.emit(assign(r0264, r01ED, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0265->else_instructions;

                              ir_expression *const r0267 = nequal(r01ED, body.constant(0u));
                              ir_expression *const r0268 = expr(ir_unop_b2i, r0267);
                              body.emit(assign(r0264, expr(ir_unop_i2u, r0268), 0x01));


                           body.instructions = f0265_parent_instructions;
                           body.emit(f0265);

                           /* END IF */

                           body.emit(assign(r0254, r0264, 0x01));

                           body.emit(assign(r0255, body.constant(0u), 0x01));


                        body.instructions = f0261_parent_instructions;
                        body.emit(f0261);

                        /* END IF */


                     body.instructions = f025F_parent_instructions;
                     body.emit(f025F);

                     /* END IF */

                     body.emit(assign(r0256, body.constant(0u), 0x01));


                  body.instructions = f025B_parent_instructions;
                  body.emit(f025B);

                  /* END IF */

                  ir_expression *const r0269 = nequal(r0252, body.constant(0u));
                  ir_expression *const r026A = expr(ir_unop_b2i, r0269);
                  ir_expression *const r026B = expr(ir_unop_i2u, r026A);
                  body.emit(assign(r0254, bit_or(r0254, r026B), 0x01));


               body.instructions = f0259_parent_instructions;
               body.emit(f0259);

               /* END IF */

               body.emit(assign(r01ED, r0256, 0x01));

               body.emit(assign(r01EE, r0255, 0x01));

               body.emit(assign(r01F0, r0254, 0x01));

               body.emit(assign(r01EF, r01F9, 0x01));


            body.instructions = f0235_parent_instructions;
            body.emit(f0235);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0233->else_instructions;

            /* IF CONDITION */
            ir_expression *const r026D = equal(r01F6, body.constant(int(2047)));
            ir_if *f026C = new(mem_ctx) ir_if(operand(r026D).val);
            exec_list *const f026C_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f026C->then_instructions;

               /* IF CONDITION */
               ir_expression *const r026F = bit_or(r01ED, r01EE);
               ir_expression *const r0270 = bit_or(r01EB, r01EC);
               ir_expression *const r0271 = bit_or(r026F, r0270);
               ir_expression *const r0272 = nequal(r0271, body.constant(0u));
               ir_if *f026E = new(mem_ctx) ir_if(operand(r0272).val);
               exec_list *const f026E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f026E->then_instructions;

                  ir_variable *const r0273 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0273, swizzle_x(r01E1), 0x01));

                  ir_variable *const r0274 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0274, swizzle_x(r01E2), 0x01));

                  ir_variable *const r0275 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r0276 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r0277 = lshift(swizzle_y(r01E2), body.constant(int(1)));
                  ir_expression *const r0278 = lequal(body.constant(4292870144u), r0277);
                  ir_expression *const r0279 = nequal(swizzle_x(r01E2), body.constant(0u));
                  ir_expression *const r027A = bit_and(swizzle_y(r01E2), body.constant(1048575u));
                  ir_expression *const r027B = nequal(r027A, body.constant(0u));
                  ir_expression *const r027C = logic_or(r0279, r027B);
                  body.emit(assign(r0276, logic_and(r0278, r027C), 0x01));

                  body.emit(assign(r0273, bit_or(swizzle_y(r01E1), body.constant(524288u)), 0x02));

                  body.emit(assign(r0274, bit_or(swizzle_y(r01E2), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r027E = lshift(swizzle_y(r01E1), body.constant(int(1)));
                  ir_expression *const r027F = lequal(body.constant(4292870144u), r027E);
                  ir_expression *const r0280 = nequal(swizzle_x(r01E1), body.constant(0u));
                  ir_expression *const r0281 = bit_and(swizzle_y(r01E1), body.constant(1048575u));
                  ir_expression *const r0282 = nequal(r0281, body.constant(0u));
                  ir_expression *const r0283 = logic_or(r0280, r0282);
                  ir_expression *const r0284 = logic_and(r027F, r0283);
                  ir_if *f027D = new(mem_ctx) ir_if(operand(r0284).val);
                  exec_list *const f027D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f027D->then_instructions;

                     ir_variable *const r0285 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f0286 = new(mem_ctx) ir_if(operand(r0276).val);
                     exec_list *const f0286_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0286->then_instructions;

                        body.emit(assign(r0285, r0274, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0286->else_instructions;

                        body.emit(assign(r0285, r0273, 0x03));


                     body.instructions = f0286_parent_instructions;
                     body.emit(f0286);

                     /* END IF */

                     body.emit(assign(r0275, r0285, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f027D->else_instructions;

                     body.emit(assign(r0275, r0274, 0x03));


                  body.instructions = f027D_parent_instructions;
                  body.emit(f027D);

                  /* END IF */

                  body.emit(assign(r01E4, r0275, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f026E->else_instructions;

                  body.emit(assign(r01E4, r01E1, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


               body.instructions = f026E_parent_instructions;
               body.emit(f026E);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f026C->else_instructions;

               ir_variable *const r0287 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0288 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0288, add(r01EE, r01EC), 0x01));

               ir_expression *const r0289 = add(r01ED, r01EB);
               ir_expression *const r028A = less(r0288, r01EE);
               ir_expression *const r028B = expr(ir_unop_b2i, r028A);
               ir_expression *const r028C = expr(ir_unop_i2u, r028B);
               body.emit(assign(r0287, add(r0289, r028C), 0x01));

               body.emit(assign(r01F1, r0287, 0x01));

               /* IF CONDITION */
               ir_expression *const r028E = equal(r01F6, body.constant(int(0)));
               ir_if *f028D = new(mem_ctx) ir_if(operand(r028E).val);
               exec_list *const f028D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f028D->then_instructions;

                  ir_variable *const r028F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r028F);
                  ir_expression *const r0290 = lshift(r01E6, body.constant(int(31)));
                  body.emit(assign(r028F, add(r0290, r0287), 0x02));

                  body.emit(assign(r028F, r0288, 0x01));

                  body.emit(assign(r01E4, r028F, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f028D->else_instructions;

                  body.emit(assign(r01F1, bit_or(r0287, body.constant(2097152u)), 0x01));

                  body.emit(assign(r01EF, r01F6, 0x01));

                  ir_variable *const r0291 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0291);
                  ir_variable *const r0292 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r0292);
                  ir_variable *const r0293 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r0293);
                  body.emit(assign(r0291, lshift(r0288, body.constant(int(31))), 0x01));

                  ir_expression *const r0294 = lshift(r01F1, body.constant(int(31)));
                  ir_expression *const r0295 = rshift(r0288, body.constant(int(1)));
                  body.emit(assign(r0292, bit_or(r0294, r0295), 0x01));

                  body.emit(assign(r0293, rshift(r01F1, body.constant(int(1))), 0x01));

                  body.emit(assign(r0291, bit_or(r0291, body.constant(0u)), 0x01));

                  body.emit(assign(r01F1, r0293, 0x01));

                  body.emit(assign(r01F0, r0291, 0x01));

                  ir_variable *const r0296 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0296, r01F6, 0x01));

                  ir_variable *const r0297 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0297, r0293, 0x01));

                  ir_variable *const r0298 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0298, r0292, 0x01));

                  ir_variable *const r0299 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0299, r0291, 0x01));

                  ir_variable *const r029A = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r029A, body.constant(true), 0x01));

                  ir_variable *const r029B = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r029C = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r029C);
                  ir_expression *const r029D = expr(ir_unop_u2i, r0291);
                  body.emit(assign(r029C, less(r029D, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r029F = lequal(body.constant(int(2045)), r01F6);
                  ir_if *f029E = new(mem_ctx) ir_if(operand(r029F).val);
                  exec_list *const f029E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f029E->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r02A1 = less(body.constant(int(2045)), r01F6);
                     ir_expression *const r02A2 = equal(r01F6, body.constant(int(2045)));
                     ir_expression *const r02A3 = equal(body.constant(2097151u), r0293);
                     ir_expression *const r02A4 = equal(body.constant(4294967295u), r0292);
                     ir_expression *const r02A5 = logic_and(r02A3, r02A4);
                     ir_expression *const r02A6 = logic_and(r02A2, r02A5);
                     ir_expression *const r02A7 = logic_and(r02A6, r029C);
                     ir_expression *const r02A8 = logic_or(r02A1, r02A7);
                     ir_if *f02A0 = new(mem_ctx) ir_if(operand(r02A8).val);
                     exec_list *const f02A0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02A0->then_instructions;

                        ir_variable *const r02A9 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r02A9);
                        ir_expression *const r02AA = lshift(r01E6, body.constant(int(31)));
                        body.emit(assign(r02A9, add(r02AA, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r02A9, body.constant(0u), 0x01));

                        body.emit(assign(r029B, r02A9, 0x03));

                        body.emit(assign(r029A, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02A0->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02AC = less(r01F6, body.constant(int(0)));
                        ir_if *f02AB = new(mem_ctx) ir_if(operand(r02AC).val);
                        exec_list *const f02AB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02AB->then_instructions;

                           ir_variable *const r02AD = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r02AD, r0291, 0x01));

                           ir_variable *const r02AE = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r02AE, neg(r01F6), 0x01));

                           ir_variable *const r02AF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r02AF);
                           ir_variable *const r02B0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r02B0);
                           ir_variable *const r02B1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r02B1);
                           ir_variable *const r02B2 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r02B3 = neg(r02AE);
                           body.emit(assign(r02B2, bit_and(r02B3, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r02B5 = equal(r02AE, body.constant(int(0)));
                           ir_if *f02B4 = new(mem_ctx) ir_if(operand(r02B5).val);
                           exec_list *const f02B4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f02B4->then_instructions;

                              body.emit(assign(r02AF, r0291, 0x01));

                              body.emit(assign(r02B0, r0292, 0x01));

                              body.emit(assign(r02B1, r0293, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f02B4->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r02B7 = less(r02AE, body.constant(int(32)));
                              ir_if *f02B6 = new(mem_ctx) ir_if(operand(r02B7).val);
                              exec_list *const f02B6_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f02B6->then_instructions;

                                 body.emit(assign(r02AF, lshift(r0292, r02B2), 0x01));

                                 ir_expression *const r02B8 = lshift(r0293, r02B2);
                                 ir_expression *const r02B9 = rshift(r0292, r02AE);
                                 body.emit(assign(r02B0, bit_or(r02B8, r02B9), 0x01));

                                 body.emit(assign(r02B1, rshift(r0293, r02AE), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f02B6->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r02BB = equal(r02AE, body.constant(int(32)));
                                 ir_if *f02BA = new(mem_ctx) ir_if(operand(r02BB).val);
                                 exec_list *const f02BA_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f02BA->then_instructions;

                                    body.emit(assign(r02AF, r0292, 0x01));

                                    body.emit(assign(r02B0, r0293, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f02BA->else_instructions;

                                    body.emit(assign(r02AD, bit_or(r0291, r0292), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r02BD = less(r02AE, body.constant(int(64)));
                                    ir_if *f02BC = new(mem_ctx) ir_if(operand(r02BD).val);
                                    exec_list *const f02BC_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f02BC->then_instructions;

                                       body.emit(assign(r02AF, lshift(r0293, r02B2), 0x01));

                                       ir_expression *const r02BE = bit_and(r02AE, body.constant(int(31)));
                                       body.emit(assign(r02B0, rshift(r0293, r02BE), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f02BC->else_instructions;

                                       ir_variable *const r02BF = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r02C1 = equal(r02AE, body.constant(int(64)));
                                       ir_if *f02C0 = new(mem_ctx) ir_if(operand(r02C1).val);
                                       exec_list *const f02C0_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f02C0->then_instructions;

                                          body.emit(assign(r02BF, r0293, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f02C0->else_instructions;

                                          ir_expression *const r02C2 = nequal(r0293, body.constant(0u));
                                          ir_expression *const r02C3 = expr(ir_unop_b2i, r02C2);
                                          body.emit(assign(r02BF, expr(ir_unop_i2u, r02C3), 0x01));


                                       body.instructions = f02C0_parent_instructions;
                                       body.emit(f02C0);

                                       /* END IF */

                                       body.emit(assign(r02AF, r02BF, 0x01));

                                       body.emit(assign(r02B0, body.constant(0u), 0x01));


                                    body.instructions = f02BC_parent_instructions;
                                    body.emit(f02BC);

                                    /* END IF */


                                 body.instructions = f02BA_parent_instructions;
                                 body.emit(f02BA);

                                 /* END IF */

                                 body.emit(assign(r02B1, body.constant(0u), 0x01));


                              body.instructions = f02B6_parent_instructions;
                              body.emit(f02B6);

                              /* END IF */

                              ir_expression *const r02C4 = nequal(r02AD, body.constant(0u));
                              ir_expression *const r02C5 = expr(ir_unop_b2i, r02C4);
                              ir_expression *const r02C6 = expr(ir_unop_i2u, r02C5);
                              body.emit(assign(r02AF, bit_or(r02AF, r02C6), 0x01));


                           body.instructions = f02B4_parent_instructions;
                           body.emit(f02B4);

                           /* END IF */

                           body.emit(assign(r0297, r02B1, 0x01));

                           body.emit(assign(r0298, r02B0, 0x01));

                           body.emit(assign(r0299, r02AF, 0x01));

                           body.emit(assign(r0296, body.constant(int(0)), 0x01));

                           body.emit(assign(r029C, less(r02AF, body.constant(0u)), 0x01));


                        body.instructions = f02AB_parent_instructions;
                        body.emit(f02AB);

                        /* END IF */


                     body.instructions = f02A0_parent_instructions;
                     body.emit(f02A0);

                     /* END IF */


                  body.instructions = f029E_parent_instructions;
                  body.emit(f029E);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f02C7 = new(mem_ctx) ir_if(operand(r029A).val);
                  exec_list *const f02C7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02C7->then_instructions;

                     /* IF CONDITION */
                     ir_if *f02C8 = new(mem_ctx) ir_if(operand(r029C).val);
                     exec_list *const f02C8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f02C8->then_instructions;

                        ir_variable *const r02C9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r02C9, add(r0298, body.constant(1u)), 0x01));

                        ir_expression *const r02CA = less(r02C9, r0298);
                        ir_expression *const r02CB = expr(ir_unop_b2i, r02CA);
                        ir_expression *const r02CC = expr(ir_unop_i2u, r02CB);
                        body.emit(assign(r0297, add(r0297, r02CC), 0x01));

                        ir_expression *const r02CD = equal(r0299, body.constant(0u));
                        ir_expression *const r02CE = expr(ir_unop_b2i, r02CD);
                        ir_expression *const r02CF = expr(ir_unop_i2u, r02CE);
                        ir_expression *const r02D0 = add(r0299, r02CF);
                        ir_expression *const r02D1 = bit_and(r02D0, body.constant(1u));
                        ir_expression *const r02D2 = expr(ir_unop_bit_not, r02D1);
                        body.emit(assign(r0298, bit_and(r02C9, r02D2), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f02C8->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r02D4 = bit_or(r0297, r0298);
                        ir_expression *const r02D5 = equal(r02D4, body.constant(0u));
                        ir_if *f02D3 = new(mem_ctx) ir_if(operand(r02D5).val);
                        exec_list *const f02D3_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f02D3->then_instructions;

                           body.emit(assign(r0296, body.constant(int(0)), 0x01));


                        body.instructions = f02D3_parent_instructions;
                        body.emit(f02D3);

                        /* END IF */


                     body.instructions = f02C8_parent_instructions;
                     body.emit(f02C8);

                     /* END IF */

                     ir_variable *const r02D6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r02D6);
                     ir_expression *const r02D7 = lshift(r01E6, body.constant(int(31)));
                     ir_expression *const r02D8 = expr(ir_unop_i2u, r0296);
                     ir_expression *const r02D9 = lshift(r02D8, body.constant(int(20)));
                     ir_expression *const r02DA = add(r02D7, r02D9);
                     body.emit(assign(r02D6, add(r02DA, r0297), 0x02));

                     body.emit(assign(r02D6, r0298, 0x01));

                     body.emit(assign(r029B, r02D6, 0x03));

                     body.emit(assign(r029A, body.constant(false), 0x01));


                  body.instructions = f02C7_parent_instructions;
                  body.emit(f02C7);

                  /* END IF */

                  body.emit(assign(r01E4, r029B, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


               body.instructions = f028D_parent_instructions;
               body.emit(f028D);

               /* END IF */


            body.instructions = f026C_parent_instructions;
            body.emit(f026C);

            /* END IF */


         body.instructions = f0233_parent_instructions;
         body.emit(f0233);

         /* END IF */


      body.instructions = f01FD_parent_instructions;
      body.emit(f01FD);

      /* END IF */

      /* IF CONDITION */
      ir_if *f02DB = new(mem_ctx) ir_if(operand(r01E3).val);
      exec_list *const f02DB_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f02DB->then_instructions;

         body.emit(assign(r01ED, bit_or(r01ED, body.constant(1048576u)), 0x01));

         ir_variable *const r02DC = body.make_temp(glsl_type::uint_type, "z0Ptr");
         ir_variable *const r02DD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r02DD, add(r01EE, r01EC), 0x01));

         ir_expression *const r02DE = add(r01ED, r01EB);
         ir_expression *const r02DF = less(r02DD, r01EE);
         ir_expression *const r02E0 = expr(ir_unop_b2i, r02DF);
         ir_expression *const r02E1 = expr(ir_unop_i2u, r02E0);
         body.emit(assign(r02DC, add(r02DE, r02E1), 0x01));

         body.emit(assign(r01F1, r02DC, 0x01));

         body.emit(assign(r01EF, add(r01EF, body.constant(int(-1))), 0x01));

         /* IF CONDITION */
         ir_expression *const r02E3 = less(r02DC, body.constant(2097152u));
         ir_if *f02E2 = new(mem_ctx) ir_if(operand(r02E3).val);
         exec_list *const f02E2_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f02E2->then_instructions;

            ir_variable *const r02E4 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r02E4, r01EF, 0x01));

            ir_variable *const r02E5 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r02E5, r02DC, 0x01));

            ir_variable *const r02E6 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r02E6, r02DD, 0x01));

            ir_variable *const r02E7 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r02E7, r01F0, 0x01));

            ir_variable *const r02E8 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r02E8, body.constant(true), 0x01));

            ir_variable *const r02E9 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r02EA = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r02EA);
            ir_expression *const r02EB = expr(ir_unop_u2i, r01F0);
            body.emit(assign(r02EA, less(r02EB, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r02ED = lequal(body.constant(int(2045)), r01EF);
            ir_if *f02EC = new(mem_ctx) ir_if(operand(r02ED).val);
            exec_list *const f02EC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f02EC->then_instructions;

               /* IF CONDITION */
               ir_expression *const r02EF = less(body.constant(int(2045)), r01EF);
               ir_expression *const r02F0 = equal(r01EF, body.constant(int(2045)));
               ir_expression *const r02F1 = equal(body.constant(2097151u), r02DC);
               ir_expression *const r02F2 = equal(body.constant(4294967295u), r02DD);
               ir_expression *const r02F3 = logic_and(r02F1, r02F2);
               ir_expression *const r02F4 = logic_and(r02F0, r02F3);
               ir_expression *const r02F5 = logic_and(r02F4, r02EA);
               ir_expression *const r02F6 = logic_or(r02EF, r02F5);
               ir_if *f02EE = new(mem_ctx) ir_if(operand(r02F6).val);
               exec_list *const f02EE_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f02EE->then_instructions;

                  ir_variable *const r02F7 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r02F7);
                  ir_expression *const r02F8 = lshift(r01E6, body.constant(int(31)));
                  body.emit(assign(r02F7, add(r02F8, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r02F7, body.constant(0u), 0x01));

                  body.emit(assign(r02E9, r02F7, 0x03));

                  body.emit(assign(r02E8, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f02EE->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r02FA = less(r01EF, body.constant(int(0)));
                  ir_if *f02F9 = new(mem_ctx) ir_if(operand(r02FA).val);
                  exec_list *const f02F9_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f02F9->then_instructions;

                     ir_variable *const r02FB = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r02FB, r01F0, 0x01));

                     ir_variable *const r02FC = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r02FC, neg(r01EF), 0x01));

                     ir_variable *const r02FD = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r02FD);
                     ir_variable *const r02FE = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r02FE);
                     ir_variable *const r02FF = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r02FF);
                     ir_variable *const r0300 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0301 = neg(r02FC);
                     body.emit(assign(r0300, bit_and(r0301, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0303 = equal(r02FC, body.constant(int(0)));
                     ir_if *f0302 = new(mem_ctx) ir_if(operand(r0303).val);
                     exec_list *const f0302_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0302->then_instructions;

                        body.emit(assign(r02FD, r01F0, 0x01));

                        body.emit(assign(r02FE, r02DD, 0x01));

                        body.emit(assign(r02FF, r02DC, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0302->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0305 = less(r02FC, body.constant(int(32)));
                        ir_if *f0304 = new(mem_ctx) ir_if(operand(r0305).val);
                        exec_list *const f0304_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0304->then_instructions;

                           body.emit(assign(r02FD, lshift(r02DD, r0300), 0x01));

                           ir_expression *const r0306 = lshift(r02DC, r0300);
                           ir_expression *const r0307 = rshift(r02DD, r02FC);
                           body.emit(assign(r02FE, bit_or(r0306, r0307), 0x01));

                           body.emit(assign(r02FF, rshift(r02DC, r02FC), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0304->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0309 = equal(r02FC, body.constant(int(32)));
                           ir_if *f0308 = new(mem_ctx) ir_if(operand(r0309).val);
                           exec_list *const f0308_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0308->then_instructions;

                              body.emit(assign(r02FD, r02DD, 0x01));

                              body.emit(assign(r02FE, r02DC, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0308->else_instructions;

                              body.emit(assign(r02FB, bit_or(r01F0, r02DD), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r030B = less(r02FC, body.constant(int(64)));
                              ir_if *f030A = new(mem_ctx) ir_if(operand(r030B).val);
                              exec_list *const f030A_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f030A->then_instructions;

                                 body.emit(assign(r02FD, lshift(r02DC, r0300), 0x01));

                                 ir_expression *const r030C = bit_and(r02FC, body.constant(int(31)));
                                 body.emit(assign(r02FE, rshift(r02DC, r030C), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f030A->else_instructions;

                                 ir_variable *const r030D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r030F = equal(r02FC, body.constant(int(64)));
                                 ir_if *f030E = new(mem_ctx) ir_if(operand(r030F).val);
                                 exec_list *const f030E_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f030E->then_instructions;

                                    body.emit(assign(r030D, r02DC, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f030E->else_instructions;

                                    ir_expression *const r0310 = nequal(r02DC, body.constant(0u));
                                    ir_expression *const r0311 = expr(ir_unop_b2i, r0310);
                                    body.emit(assign(r030D, expr(ir_unop_i2u, r0311), 0x01));


                                 body.instructions = f030E_parent_instructions;
                                 body.emit(f030E);

                                 /* END IF */

                                 body.emit(assign(r02FD, r030D, 0x01));

                                 body.emit(assign(r02FE, body.constant(0u), 0x01));


                              body.instructions = f030A_parent_instructions;
                              body.emit(f030A);

                              /* END IF */


                           body.instructions = f0308_parent_instructions;
                           body.emit(f0308);

                           /* END IF */

                           body.emit(assign(r02FF, body.constant(0u), 0x01));


                        body.instructions = f0304_parent_instructions;
                        body.emit(f0304);

                        /* END IF */

                        ir_expression *const r0312 = nequal(r02FB, body.constant(0u));
                        ir_expression *const r0313 = expr(ir_unop_b2i, r0312);
                        ir_expression *const r0314 = expr(ir_unop_i2u, r0313);
                        body.emit(assign(r02FD, bit_or(r02FD, r0314), 0x01));


                     body.instructions = f0302_parent_instructions;
                     body.emit(f0302);

                     /* END IF */

                     body.emit(assign(r02E5, r02FF, 0x01));

                     body.emit(assign(r02E6, r02FE, 0x01));

                     body.emit(assign(r02E7, r02FD, 0x01));

                     body.emit(assign(r02E4, body.constant(int(0)), 0x01));

                     body.emit(assign(r02EA, less(r02FD, body.constant(0u)), 0x01));


                  body.instructions = f02F9_parent_instructions;
                  body.emit(f02F9);

                  /* END IF */


               body.instructions = f02EE_parent_instructions;
               body.emit(f02EE);

               /* END IF */


            body.instructions = f02EC_parent_instructions;
            body.emit(f02EC);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0315 = new(mem_ctx) ir_if(operand(r02E8).val);
            exec_list *const f0315_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0315->then_instructions;

               /* IF CONDITION */
               ir_if *f0316 = new(mem_ctx) ir_if(operand(r02EA).val);
               exec_list *const f0316_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0316->then_instructions;

                  ir_variable *const r0317 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0317, add(r02E6, body.constant(1u)), 0x01));

                  ir_expression *const r0318 = less(r0317, r02E6);
                  ir_expression *const r0319 = expr(ir_unop_b2i, r0318);
                  ir_expression *const r031A = expr(ir_unop_i2u, r0319);
                  body.emit(assign(r02E5, add(r02E5, r031A), 0x01));

                  ir_expression *const r031B = equal(r02E7, body.constant(0u));
                  ir_expression *const r031C = expr(ir_unop_b2i, r031B);
                  ir_expression *const r031D = expr(ir_unop_i2u, r031C);
                  ir_expression *const r031E = add(r02E7, r031D);
                  ir_expression *const r031F = bit_and(r031E, body.constant(1u));
                  ir_expression *const r0320 = expr(ir_unop_bit_not, r031F);
                  body.emit(assign(r02E6, bit_and(r0317, r0320), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0316->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0322 = bit_or(r02E5, r02E6);
                  ir_expression *const r0323 = equal(r0322, body.constant(0u));
                  ir_if *f0321 = new(mem_ctx) ir_if(operand(r0323).val);
                  exec_list *const f0321_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0321->then_instructions;

                     body.emit(assign(r02E4, body.constant(int(0)), 0x01));


                  body.instructions = f0321_parent_instructions;
                  body.emit(f0321);

                  /* END IF */


               body.instructions = f0316_parent_instructions;
               body.emit(f0316);

               /* END IF */

               ir_variable *const r0324 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0324);
               ir_expression *const r0325 = lshift(r01E6, body.constant(int(31)));
               ir_expression *const r0326 = expr(ir_unop_i2u, r02E4);
               ir_expression *const r0327 = lshift(r0326, body.constant(int(20)));
               ir_expression *const r0328 = add(r0325, r0327);
               body.emit(assign(r0324, add(r0328, r02E5), 0x02));

               body.emit(assign(r0324, r02E6, 0x01));

               body.emit(assign(r02E9, r0324, 0x03));

               body.emit(assign(r02E8, body.constant(false), 0x01));


            body.instructions = f0315_parent_instructions;
            body.emit(f0315);

            /* END IF */

            body.emit(assign(r01E4, r02E9, 0x03));

            body.emit(assign(r01E3, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f02E2->else_instructions;

            body.emit(assign(r01EF, add(r01EF, body.constant(int(1))), 0x01));

            ir_variable *const r0329 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
            body.emit(r0329);
            ir_variable *const r032A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r032A);
            ir_variable *const r032B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r032B);
            body.emit(assign(r0329, lshift(r02DD, body.constant(int(31))), 0x01));

            ir_expression *const r032C = lshift(r02DC, body.constant(int(31)));
            ir_expression *const r032D = rshift(r02DD, body.constant(int(1)));
            body.emit(assign(r032A, bit_or(r032C, r032D), 0x01));

            body.emit(assign(r032B, rshift(r02DC, body.constant(int(1))), 0x01));

            ir_expression *const r032E = nequal(r01F0, body.constant(0u));
            ir_expression *const r032F = expr(ir_unop_b2i, r032E);
            ir_expression *const r0330 = expr(ir_unop_i2u, r032F);
            body.emit(assign(r0329, bit_or(r0329, r0330), 0x01));

            body.emit(assign(r01F1, r032B, 0x01));

            body.emit(assign(r01F0, r0329, 0x01));

            ir_variable *const r0331 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0331, r01EF, 0x01));

            ir_variable *const r0332 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0332, r032B, 0x01));

            ir_variable *const r0333 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0333, r032A, 0x01));

            ir_variable *const r0334 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0334, r0329, 0x01));

            ir_variable *const r0335 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0335, body.constant(true), 0x01));

            ir_variable *const r0336 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0337 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0337);
            ir_expression *const r0338 = expr(ir_unop_u2i, r0329);
            body.emit(assign(r0337, less(r0338, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r033A = lequal(body.constant(int(2045)), r01EF);
            ir_if *f0339 = new(mem_ctx) ir_if(operand(r033A).val);
            exec_list *const f0339_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0339->then_instructions;

               /* IF CONDITION */
               ir_expression *const r033C = less(body.constant(int(2045)), r01EF);
               ir_expression *const r033D = equal(r01EF, body.constant(int(2045)));
               ir_expression *const r033E = equal(body.constant(2097151u), r032B);
               ir_expression *const r033F = equal(body.constant(4294967295u), r032A);
               ir_expression *const r0340 = logic_and(r033E, r033F);
               ir_expression *const r0341 = logic_and(r033D, r0340);
               ir_expression *const r0342 = logic_and(r0341, r0337);
               ir_expression *const r0343 = logic_or(r033C, r0342);
               ir_if *f033B = new(mem_ctx) ir_if(operand(r0343).val);
               exec_list *const f033B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f033B->then_instructions;

                  ir_variable *const r0344 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0344);
                  ir_expression *const r0345 = lshift(r01E6, body.constant(int(31)));
                  body.emit(assign(r0344, add(r0345, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0344, body.constant(0u), 0x01));

                  body.emit(assign(r0336, r0344, 0x03));

                  body.emit(assign(r0335, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f033B->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0347 = less(r01EF, body.constant(int(0)));
                  ir_if *f0346 = new(mem_ctx) ir_if(operand(r0347).val);
                  exec_list *const f0346_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0346->then_instructions;

                     ir_variable *const r0348 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0348, r0329, 0x01));

                     ir_variable *const r0349 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0349, neg(r01EF), 0x01));

                     ir_variable *const r034A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r034A);
                     ir_variable *const r034B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r034B);
                     ir_variable *const r034C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r034C);
                     ir_variable *const r034D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r034E = neg(r0349);
                     body.emit(assign(r034D, bit_and(r034E, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0350 = equal(r0349, body.constant(int(0)));
                     ir_if *f034F = new(mem_ctx) ir_if(operand(r0350).val);
                     exec_list *const f034F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f034F->then_instructions;

                        body.emit(assign(r034A, r0329, 0x01));

                        body.emit(assign(r034B, r032A, 0x01));

                        body.emit(assign(r034C, r032B, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f034F->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0352 = less(r0349, body.constant(int(32)));
                        ir_if *f0351 = new(mem_ctx) ir_if(operand(r0352).val);
                        exec_list *const f0351_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0351->then_instructions;

                           body.emit(assign(r034A, lshift(r032A, r034D), 0x01));

                           ir_expression *const r0353 = lshift(r032B, r034D);
                           ir_expression *const r0354 = rshift(r032A, r0349);
                           body.emit(assign(r034B, bit_or(r0353, r0354), 0x01));

                           body.emit(assign(r034C, rshift(r032B, r0349), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0351->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0356 = equal(r0349, body.constant(int(32)));
                           ir_if *f0355 = new(mem_ctx) ir_if(operand(r0356).val);
                           exec_list *const f0355_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0355->then_instructions;

                              body.emit(assign(r034A, r032A, 0x01));

                              body.emit(assign(r034B, r032B, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0355->else_instructions;

                              body.emit(assign(r0348, bit_or(r0329, r032A), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0358 = less(r0349, body.constant(int(64)));
                              ir_if *f0357 = new(mem_ctx) ir_if(operand(r0358).val);
                              exec_list *const f0357_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0357->then_instructions;

                                 body.emit(assign(r034A, lshift(r032B, r034D), 0x01));

                                 ir_expression *const r0359 = bit_and(r0349, body.constant(int(31)));
                                 body.emit(assign(r034B, rshift(r032B, r0359), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0357->else_instructions;

                                 ir_variable *const r035A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r035C = equal(r0349, body.constant(int(64)));
                                 ir_if *f035B = new(mem_ctx) ir_if(operand(r035C).val);
                                 exec_list *const f035B_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f035B->then_instructions;

                                    body.emit(assign(r035A, r032B, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f035B->else_instructions;

                                    ir_expression *const r035D = nequal(r032B, body.constant(0u));
                                    ir_expression *const r035E = expr(ir_unop_b2i, r035D);
                                    body.emit(assign(r035A, expr(ir_unop_i2u, r035E), 0x01));


                                 body.instructions = f035B_parent_instructions;
                                 body.emit(f035B);

                                 /* END IF */

                                 body.emit(assign(r034A, r035A, 0x01));

                                 body.emit(assign(r034B, body.constant(0u), 0x01));


                              body.instructions = f0357_parent_instructions;
                              body.emit(f0357);

                              /* END IF */


                           body.instructions = f0355_parent_instructions;
                           body.emit(f0355);

                           /* END IF */

                           body.emit(assign(r034C, body.constant(0u), 0x01));


                        body.instructions = f0351_parent_instructions;
                        body.emit(f0351);

                        /* END IF */

                        ir_expression *const r035F = nequal(r0348, body.constant(0u));
                        ir_expression *const r0360 = expr(ir_unop_b2i, r035F);
                        ir_expression *const r0361 = expr(ir_unop_i2u, r0360);
                        body.emit(assign(r034A, bit_or(r034A, r0361), 0x01));


                     body.instructions = f034F_parent_instructions;
                     body.emit(f034F);

                     /* END IF */

                     body.emit(assign(r0332, r034C, 0x01));

                     body.emit(assign(r0333, r034B, 0x01));

                     body.emit(assign(r0334, r034A, 0x01));

                     body.emit(assign(r0331, body.constant(int(0)), 0x01));

                     body.emit(assign(r0337, less(r034A, body.constant(0u)), 0x01));


                  body.instructions = f0346_parent_instructions;
                  body.emit(f0346);

                  /* END IF */


               body.instructions = f033B_parent_instructions;
               body.emit(f033B);

               /* END IF */


            body.instructions = f0339_parent_instructions;
            body.emit(f0339);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0362 = new(mem_ctx) ir_if(operand(r0335).val);
            exec_list *const f0362_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0362->then_instructions;

               /* IF CONDITION */
               ir_if *f0363 = new(mem_ctx) ir_if(operand(r0337).val);
               exec_list *const f0363_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0363->then_instructions;

                  ir_variable *const r0364 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0364, add(r0333, body.constant(1u)), 0x01));

                  ir_expression *const r0365 = less(r0364, r0333);
                  ir_expression *const r0366 = expr(ir_unop_b2i, r0365);
                  ir_expression *const r0367 = expr(ir_unop_i2u, r0366);
                  body.emit(assign(r0332, add(r0332, r0367), 0x01));

                  ir_expression *const r0368 = equal(r0334, body.constant(0u));
                  ir_expression *const r0369 = expr(ir_unop_b2i, r0368);
                  ir_expression *const r036A = expr(ir_unop_i2u, r0369);
                  ir_expression *const r036B = add(r0334, r036A);
                  ir_expression *const r036C = bit_and(r036B, body.constant(1u));
                  ir_expression *const r036D = expr(ir_unop_bit_not, r036C);
                  body.emit(assign(r0333, bit_and(r0364, r036D), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0363->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r036F = bit_or(r0332, r0333);
                  ir_expression *const r0370 = equal(r036F, body.constant(0u));
                  ir_if *f036E = new(mem_ctx) ir_if(operand(r0370).val);
                  exec_list *const f036E_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f036E->then_instructions;

                     body.emit(assign(r0331, body.constant(int(0)), 0x01));


                  body.instructions = f036E_parent_instructions;
                  body.emit(f036E);

                  /* END IF */


               body.instructions = f0363_parent_instructions;
               body.emit(f0363);

               /* END IF */

               ir_variable *const r0371 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0371);
               ir_expression *const r0372 = lshift(r01E6, body.constant(int(31)));
               ir_expression *const r0373 = expr(ir_unop_i2u, r0331);
               ir_expression *const r0374 = lshift(r0373, body.constant(int(20)));
               ir_expression *const r0375 = add(r0372, r0374);
               body.emit(assign(r0371, add(r0375, r0332), 0x02));

               body.emit(assign(r0371, r0333, 0x01));

               body.emit(assign(r0336, r0371, 0x03));

               body.emit(assign(r0335, body.constant(false), 0x01));


            body.instructions = f0362_parent_instructions;
            body.emit(f0362);

            /* END IF */

            body.emit(assign(r01E4, r0336, 0x03));

            body.emit(assign(r01E3, body.constant(false), 0x01));


         body.instructions = f02E2_parent_instructions;
         body.emit(f02E2);

         /* END IF */


      body.instructions = f02DB_parent_instructions;
      body.emit(f02DB);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f01E8->else_instructions;

      ir_variable *const r0376 = new(mem_ctx) ir_variable(glsl_type::int_type, "expDiff", ir_var_auto);
      body.emit(r0376);
      ir_variable *const r0377 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
      body.emit(r0377);
      ir_variable *const r0378 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
      body.emit(r0378);
      ir_variable *const r0379 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
      body.emit(r0379);
      ir_variable *const r037A = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
      body.emit(r037A);
      ir_variable *const r037B = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
      body.emit(r037B);
      ir_variable *const r037C = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
      body.emit(r037C);
      ir_variable *const r037D = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
      body.emit(r037D);
      ir_variable *const r037E = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r037F = rshift(swizzle_y(r01E1), body.constant(int(20)));
      ir_expression *const r0380 = bit_and(r037F, body.constant(2047u));
      body.emit(assign(r037E, expr(ir_unop_u2i, r0380), 0x01));

      body.emit(assign(r0378, r037E, 0x01));

      ir_variable *const r0381 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
      ir_expression *const r0382 = rshift(swizzle_y(r01E2), body.constant(int(20)));
      ir_expression *const r0383 = bit_and(r0382, body.constant(2047u));
      body.emit(assign(r0381, expr(ir_unop_u2i, r0383), 0x01));

      body.emit(assign(r0377, r0381, 0x01));

      body.emit(assign(r0376, sub(r037E, r0381), 0x01));

      ir_variable *const r0384 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0384, lshift(swizzle_x(r01E1), body.constant(int(10))), 0x01));

      ir_variable *const r0385 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r0386 = bit_and(swizzle_y(r01E1), body.constant(1048575u));
      ir_expression *const r0387 = lshift(r0386, body.constant(int(10)));
      ir_expression *const r0388 = rshift(swizzle_x(r01E1), body.constant(int(22)));
      body.emit(assign(r0385, bit_or(r0387, r0388), 0x01));

      body.emit(assign(r037B, r0385, 0x01));

      body.emit(assign(r037C, r0384, 0x01));

      ir_variable *const r0389 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0389, lshift(swizzle_x(r01E2), body.constant(int(10))), 0x01));

      ir_variable *const r038A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      ir_expression *const r038B = bit_and(swizzle_y(r01E2), body.constant(1048575u));
      ir_expression *const r038C = lshift(r038B, body.constant(int(10)));
      ir_expression *const r038D = rshift(swizzle_x(r01E2), body.constant(int(22)));
      body.emit(assign(r038A, bit_or(r038C, r038D), 0x01));

      body.emit(assign(r0379, r038A, 0x01));

      body.emit(assign(r037A, r0389, 0x01));

      /* IF CONDITION */
      ir_expression *const r038F = less(body.constant(int(0)), r0376);
      ir_if *f038E = new(mem_ctx) ir_if(operand(r038F).val);
      exec_list *const f038E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f038E->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0391 = equal(r037E, body.constant(int(2047)));
         ir_if *f0390 = new(mem_ctx) ir_if(operand(r0391).val);
         exec_list *const f0390_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0390->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0393 = bit_or(r0385, r0384);
            ir_expression *const r0394 = nequal(r0393, body.constant(0u));
            ir_if *f0392 = new(mem_ctx) ir_if(operand(r0394).val);
            exec_list *const f0392_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0392->then_instructions;

               ir_variable *const r0395 = body.make_temp(glsl_type::uvec2_type, "a");
               body.emit(assign(r0395, swizzle_x(r01E1), 0x01));

               ir_variable *const r0396 = body.make_temp(glsl_type::uvec2_type, "b");
               body.emit(assign(r0396, swizzle_x(r01E2), 0x01));

               ir_variable *const r0397 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0398 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
               ir_expression *const r0399 = lshift(swizzle_y(r01E2), body.constant(int(1)));
               ir_expression *const r039A = lequal(body.constant(4292870144u), r0399);
               ir_expression *const r039B = nequal(swizzle_x(r01E2), body.constant(0u));
               ir_expression *const r039C = bit_and(swizzle_y(r01E2), body.constant(1048575u));
               ir_expression *const r039D = nequal(r039C, body.constant(0u));
               ir_expression *const r039E = logic_or(r039B, r039D);
               body.emit(assign(r0398, logic_and(r039A, r039E), 0x01));

               body.emit(assign(r0395, bit_or(swizzle_y(r01E1), body.constant(524288u)), 0x02));

               body.emit(assign(r0396, bit_or(swizzle_y(r01E2), body.constant(524288u)), 0x02));

               /* IF CONDITION */
               ir_expression *const r03A0 = lshift(swizzle_y(r01E1), body.constant(int(1)));
               ir_expression *const r03A1 = lequal(body.constant(4292870144u), r03A0);
               ir_expression *const r03A2 = nequal(swizzle_x(r01E1), body.constant(0u));
               ir_expression *const r03A3 = bit_and(swizzle_y(r01E1), body.constant(1048575u));
               ir_expression *const r03A4 = nequal(r03A3, body.constant(0u));
               ir_expression *const r03A5 = logic_or(r03A2, r03A4);
               ir_expression *const r03A6 = logic_and(r03A1, r03A5);
               ir_if *f039F = new(mem_ctx) ir_if(operand(r03A6).val);
               exec_list *const f039F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f039F->then_instructions;

                  ir_variable *const r03A7 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_if *f03A8 = new(mem_ctx) ir_if(operand(r0398).val);
                  exec_list *const f03A8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03A8->then_instructions;

                     body.emit(assign(r03A7, r0396, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03A8->else_instructions;

                     body.emit(assign(r03A7, r0395, 0x03));


                  body.instructions = f03A8_parent_instructions;
                  body.emit(f03A8);

                  /* END IF */

                  body.emit(assign(r0397, r03A7, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f039F->else_instructions;

                  body.emit(assign(r0397, r0396, 0x03));


               body.instructions = f039F_parent_instructions;
               body.emit(f039F);

               /* END IF */

               body.emit(assign(r01E4, r0397, 0x03));

               body.emit(assign(r01E3, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0392->else_instructions;

               body.emit(assign(r01E4, r01E1, 0x03));

               body.emit(assign(r01E3, body.constant(false), 0x01));


            body.instructions = f0392_parent_instructions;
            body.emit(f0392);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0390->else_instructions;

            /* IF CONDITION */
            ir_expression *const r03AA = equal(r0381, body.constant(int(0)));
            ir_if *f03A9 = new(mem_ctx) ir_if(operand(r03AA).val);
            exec_list *const f03A9_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03A9->then_instructions;

               body.emit(assign(r0376, add(r0376, body.constant(int(-1))), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03A9->else_instructions;

               body.emit(assign(r0379, bit_or(r038A, body.constant(1073741824u)), 0x01));


            body.instructions = f03A9_parent_instructions;
            body.emit(f03A9);

            /* END IF */

            ir_variable *const r03AB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r03AB);
            ir_variable *const r03AC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r03AC);
            ir_variable *const r03AD = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r03AE = neg(r0376);
            body.emit(assign(r03AD, bit_and(r03AE, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03B0 = equal(r0376, body.constant(int(0)));
            ir_if *f03AF = new(mem_ctx) ir_if(operand(r03B0).val);
            exec_list *const f03AF_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03AF->then_instructions;

               body.emit(assign(r03AB, r0389, 0x01));

               body.emit(assign(r03AC, r0379, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03AF->else_instructions;

               /* IF CONDITION */
               ir_expression *const r03B2 = less(r0376, body.constant(int(32)));
               ir_if *f03B1 = new(mem_ctx) ir_if(operand(r03B2).val);
               exec_list *const f03B1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03B1->then_instructions;

                  ir_expression *const r03B3 = lshift(r0379, r03AD);
                  ir_expression *const r03B4 = rshift(r0389, r0376);
                  ir_expression *const r03B5 = bit_or(r03B3, r03B4);
                  ir_expression *const r03B6 = lshift(r0389, r03AD);
                  ir_expression *const r03B7 = nequal(r03B6, body.constant(0u));
                  ir_expression *const r03B8 = expr(ir_unop_b2i, r03B7);
                  ir_expression *const r03B9 = expr(ir_unop_i2u, r03B8);
                  body.emit(assign(r03AB, bit_or(r03B5, r03B9), 0x01));

                  body.emit(assign(r03AC, rshift(r0379, r0376), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03B1->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r03BB = equal(r0376, body.constant(int(32)));
                  ir_if *f03BA = new(mem_ctx) ir_if(operand(r03BB).val);
                  exec_list *const f03BA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03BA->then_instructions;

                     ir_expression *const r03BC = nequal(r0389, body.constant(0u));
                     ir_expression *const r03BD = expr(ir_unop_b2i, r03BC);
                     ir_expression *const r03BE = expr(ir_unop_i2u, r03BD);
                     body.emit(assign(r03AB, bit_or(r0379, r03BE), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03BA->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r03C0 = less(r0376, body.constant(int(64)));
                     ir_if *f03BF = new(mem_ctx) ir_if(operand(r03C0).val);
                     exec_list *const f03BF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f03BF->then_instructions;

                        ir_expression *const r03C1 = bit_and(r0376, body.constant(int(31)));
                        ir_expression *const r03C2 = rshift(r0379, r03C1);
                        ir_expression *const r03C3 = lshift(r0379, r03AD);
                        ir_expression *const r03C4 = bit_or(r03C3, r0389);
                        ir_expression *const r03C5 = nequal(r03C4, body.constant(0u));
                        ir_expression *const r03C6 = expr(ir_unop_b2i, r03C5);
                        ir_expression *const r03C7 = expr(ir_unop_i2u, r03C6);
                        body.emit(assign(r03AB, bit_or(r03C2, r03C7), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f03BF->else_instructions;

                        ir_expression *const r03C8 = bit_or(r0379, r0389);
                        ir_expression *const r03C9 = nequal(r03C8, body.constant(0u));
                        ir_expression *const r03CA = expr(ir_unop_b2i, r03C9);
                        body.emit(assign(r03AB, expr(ir_unop_i2u, r03CA), 0x01));


                     body.instructions = f03BF_parent_instructions;
                     body.emit(f03BF);

                     /* END IF */


                  body.instructions = f03BA_parent_instructions;
                  body.emit(f03BA);

                  /* END IF */

                  body.emit(assign(r03AC, body.constant(0u), 0x01));


               body.instructions = f03B1_parent_instructions;
               body.emit(f03B1);

               /* END IF */


            body.instructions = f03AF_parent_instructions;
            body.emit(f03AF);

            /* END IF */

            body.emit(assign(r0379, r03AC, 0x01));

            body.emit(assign(r037A, r03AB, 0x01));

            body.emit(assign(r037B, bit_or(r0385, body.constant(1073741824u)), 0x01));

            ir_variable *const r03CB = body.make_temp(glsl_type::uint_type, "z0Ptr");
            ir_variable *const r03CC = body.make_temp(glsl_type::uint_type, "z1Ptr");
            body.emit(assign(r03CC, sub(r0384, r03AB), 0x01));

            ir_expression *const r03CD = sub(r037B, r03AC);
            ir_expression *const r03CE = less(r0384, r03AB);
            ir_expression *const r03CF = expr(ir_unop_b2i, r03CE);
            ir_expression *const r03D0 = expr(ir_unop_i2u, r03CF);
            body.emit(assign(r03CB, sub(r03CD, r03D0), 0x01));

            body.emit(assign(r037D, add(r037E, body.constant(int(-1))), 0x01));

            ir_variable *const r03D1 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r03D1, add(r037D, body.constant(int(-10))), 0x01));

            ir_variable *const r03D2 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r03D2, r03CB, 0x01));

            ir_variable *const r03D3 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r03D3, r03CC, 0x01));

            ir_variable *const r03D4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
            body.emit(r03D4);
            ir_variable *const r03D5 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03D5);
            /* IF CONDITION */
            ir_expression *const r03D7 = equal(r03CB, body.constant(0u));
            ir_if *f03D6 = new(mem_ctx) ir_if(operand(r03D7).val);
            exec_list *const f03D6_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03D6->then_instructions;

               body.emit(assign(r03D2, r03CC, 0x01));

               body.emit(assign(r03D3, body.constant(0u), 0x01));

               body.emit(assign(r03D1, add(r03D1, body.constant(int(-32))), 0x01));


            body.instructions = f03D6_parent_instructions;
            body.emit(f03D6);

            /* END IF */

            ir_variable *const r03D8 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r03D8, r03D2, 0x01));

            ir_variable *const r03D9 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r03DA = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r03DA);
            /* IF CONDITION */
            ir_expression *const r03DC = equal(r03D2, body.constant(0u));
            ir_if *f03DB = new(mem_ctx) ir_if(operand(r03DC).val);
            exec_list *const f03DB_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03DB->then_instructions;

               body.emit(assign(r03D9, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03DB->else_instructions;

               body.emit(assign(r03DA, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r03DE = bit_and(r03D2, body.constant(4294901760u));
               ir_expression *const r03DF = equal(r03DE, body.constant(0u));
               ir_if *f03DD = new(mem_ctx) ir_if(operand(r03DF).val);
               exec_list *const f03DD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03DD->then_instructions;

                  body.emit(assign(r03DA, body.constant(int(16)), 0x01));

                  body.emit(assign(r03D8, lshift(r03D2, body.constant(int(16))), 0x01));


               body.instructions = f03DD_parent_instructions;
               body.emit(f03DD);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03E1 = bit_and(r03D8, body.constant(4278190080u));
               ir_expression *const r03E2 = equal(r03E1, body.constant(0u));
               ir_if *f03E0 = new(mem_ctx) ir_if(operand(r03E2).val);
               exec_list *const f03E0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E0->then_instructions;

                  body.emit(assign(r03DA, add(r03DA, body.constant(int(8))), 0x01));

                  body.emit(assign(r03D8, lshift(r03D8, body.constant(int(8))), 0x01));


               body.instructions = f03E0_parent_instructions;
               body.emit(f03E0);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03E4 = bit_and(r03D8, body.constant(4026531840u));
               ir_expression *const r03E5 = equal(r03E4, body.constant(0u));
               ir_if *f03E3 = new(mem_ctx) ir_if(operand(r03E5).val);
               exec_list *const f03E3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E3->then_instructions;

                  body.emit(assign(r03DA, add(r03DA, body.constant(int(4))), 0x01));

                  body.emit(assign(r03D8, lshift(r03D8, body.constant(int(4))), 0x01));


               body.instructions = f03E3_parent_instructions;
               body.emit(f03E3);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03E7 = bit_and(r03D8, body.constant(3221225472u));
               ir_expression *const r03E8 = equal(r03E7, body.constant(0u));
               ir_if *f03E6 = new(mem_ctx) ir_if(operand(r03E8).val);
               exec_list *const f03E6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E6->then_instructions;

                  body.emit(assign(r03DA, add(r03DA, body.constant(int(2))), 0x01));

                  body.emit(assign(r03D8, lshift(r03D8, body.constant(int(2))), 0x01));


               body.instructions = f03E6_parent_instructions;
               body.emit(f03E6);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r03EA = bit_and(r03D8, body.constant(2147483648u));
               ir_expression *const r03EB = equal(r03EA, body.constant(0u));
               ir_if *f03E9 = new(mem_ctx) ir_if(operand(r03EB).val);
               exec_list *const f03E9_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03E9->then_instructions;

                  body.emit(assign(r03DA, add(r03DA, body.constant(int(1))), 0x01));


               body.instructions = f03E9_parent_instructions;
               body.emit(f03E9);

               /* END IF */

               body.emit(assign(r03D9, r03DA, 0x01));


            body.instructions = f03DB_parent_instructions;
            body.emit(f03DB);

            /* END IF */

            body.emit(assign(r03D5, add(r03D9, body.constant(int(-11))), 0x01));

            /* IF CONDITION */
            ir_expression *const r03ED = lequal(body.constant(int(0)), r03D5);
            ir_if *f03EC = new(mem_ctx) ir_if(operand(r03ED).val);
            exec_list *const f03EC_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f03EC->then_instructions;

               body.emit(assign(r03D4, body.constant(0u), 0x01));

               ir_variable *const r03EE = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r03EE, lshift(r03D3, r03D5), 0x01));

               ir_variable *const r03EF = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r03F1 = equal(r03D5, body.constant(int(0)));
               ir_if *f03F0 = new(mem_ctx) ir_if(operand(r03F1).val);
               exec_list *const f03F0_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03F0->then_instructions;

                  body.emit(assign(r03EF, r03D2, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03F0->else_instructions;

                  ir_expression *const r03F2 = lshift(r03D2, r03D5);
                  ir_expression *const r03F3 = neg(r03D5);
                  ir_expression *const r03F4 = bit_and(r03F3, body.constant(int(31)));
                  ir_expression *const r03F5 = rshift(r03D3, r03F4);
                  body.emit(assign(r03EF, bit_or(r03F2, r03F5), 0x01));


               body.instructions = f03F0_parent_instructions;
               body.emit(f03F0);

               /* END IF */

               body.emit(assign(r03D2, r03EF, 0x01));

               body.emit(assign(r03D3, r03EE, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f03EC->else_instructions;

               ir_variable *const r03F6 = body.make_temp(glsl_type::uint_type, "a2");
               body.emit(assign(r03F6, body.constant(0u), 0x01));

               ir_variable *const r03F7 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r03F7, neg(r03D5), 0x01));

               ir_variable *const r03F8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
               body.emit(r03F8);
               ir_variable *const r03F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r03F9);
               ir_variable *const r03FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r03FA);
               ir_variable *const r03FB = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r03FC = neg(r03F7);
               body.emit(assign(r03FB, bit_and(r03FC, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r03FE = equal(r03F7, body.constant(int(0)));
               ir_if *f03FD = new(mem_ctx) ir_if(operand(r03FE).val);
               exec_list *const f03FD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f03FD->then_instructions;

                  body.emit(assign(r03F8, r03F6, 0x01));

                  body.emit(assign(r03F9, r03D3, 0x01));

                  body.emit(assign(r03FA, r03D2, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f03FD->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0400 = less(r03F7, body.constant(int(32)));
                  ir_if *f03FF = new(mem_ctx) ir_if(operand(r0400).val);
                  exec_list *const f03FF_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f03FF->then_instructions;

                     body.emit(assign(r03F8, lshift(r03D3, r03FB), 0x01));

                     ir_expression *const r0401 = lshift(r03D2, r03FB);
                     ir_expression *const r0402 = rshift(r03D3, r03F7);
                     body.emit(assign(r03F9, bit_or(r0401, r0402), 0x01));

                     body.emit(assign(r03FA, rshift(r03D2, r03F7), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f03FF->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0404 = equal(r03F7, body.constant(int(32)));
                     ir_if *f0403 = new(mem_ctx) ir_if(operand(r0404).val);
                     exec_list *const f0403_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0403->then_instructions;

                        body.emit(assign(r03F8, r03D3, 0x01));

                        body.emit(assign(r03F9, r03D2, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0403->else_instructions;

                        body.emit(assign(r03F6, bit_or(body.constant(0u), r03D3), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r0406 = less(r03F7, body.constant(int(64)));
                        ir_if *f0405 = new(mem_ctx) ir_if(operand(r0406).val);
                        exec_list *const f0405_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0405->then_instructions;

                           body.emit(assign(r03F8, lshift(r03D2, r03FB), 0x01));

                           ir_expression *const r0407 = bit_and(r03F7, body.constant(int(31)));
                           body.emit(assign(r03F9, rshift(r03D2, r0407), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0405->else_instructions;

                           ir_variable *const r0408 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r040A = equal(r03F7, body.constant(int(64)));
                           ir_if *f0409 = new(mem_ctx) ir_if(operand(r040A).val);
                           exec_list *const f0409_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0409->then_instructions;

                              body.emit(assign(r0408, r03D2, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0409->else_instructions;

                              ir_expression *const r040B = nequal(r03D2, body.constant(0u));
                              ir_expression *const r040C = expr(ir_unop_b2i, r040B);
                              body.emit(assign(r0408, expr(ir_unop_i2u, r040C), 0x01));


                           body.instructions = f0409_parent_instructions;
                           body.emit(f0409);

                           /* END IF */

                           body.emit(assign(r03F8, r0408, 0x01));

                           body.emit(assign(r03F9, body.constant(0u), 0x01));


                        body.instructions = f0405_parent_instructions;
                        body.emit(f0405);

                        /* END IF */


                     body.instructions = f0403_parent_instructions;
                     body.emit(f0403);

                     /* END IF */

                     body.emit(assign(r03FA, body.constant(0u), 0x01));


                  body.instructions = f03FF_parent_instructions;
                  body.emit(f03FF);

                  /* END IF */

                  ir_expression *const r040D = nequal(r03F6, body.constant(0u));
                  ir_expression *const r040E = expr(ir_unop_b2i, r040D);
                  ir_expression *const r040F = expr(ir_unop_i2u, r040E);
                  body.emit(assign(r03F8, bit_or(r03F8, r040F), 0x01));


               body.instructions = f03FD_parent_instructions;
               body.emit(f03FD);

               /* END IF */

               body.emit(assign(r03D2, r03FA, 0x01));

               body.emit(assign(r03D3, r03F9, 0x01));

               body.emit(assign(r03D4, r03F8, 0x01));


            body.instructions = f03EC_parent_instructions;
            body.emit(f03EC);

            /* END IF */

            body.emit(assign(r03D1, sub(r03D1, r03D5), 0x01));

            ir_variable *const r0410 = body.make_temp(glsl_type::int_type, "zExp");
            body.emit(assign(r0410, r03D1, 0x01));

            ir_variable *const r0411 = body.make_temp(glsl_type::uint_type, "zFrac0");
            body.emit(assign(r0411, r03D2, 0x01));

            ir_variable *const r0412 = body.make_temp(glsl_type::uint_type, "zFrac1");
            body.emit(assign(r0412, r03D3, 0x01));

            ir_variable *const r0413 = body.make_temp(glsl_type::uint_type, "zFrac2");
            body.emit(assign(r0413, r03D4, 0x01));

            ir_variable *const r0414 = body.make_temp(glsl_type::bool_type, "execute_flag");
            body.emit(assign(r0414, body.constant(true), 0x01));

            ir_variable *const r0415 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0416 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
            body.emit(r0416);
            ir_expression *const r0417 = expr(ir_unop_u2i, r03D4);
            body.emit(assign(r0416, less(r0417, body.constant(int(0))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0419 = lequal(body.constant(int(2045)), r03D1);
            ir_if *f0418 = new(mem_ctx) ir_if(operand(r0419).val);
            exec_list *const f0418_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0418->then_instructions;

               /* IF CONDITION */
               ir_expression *const r041B = less(body.constant(int(2045)), r03D1);
               ir_expression *const r041C = equal(r03D1, body.constant(int(2045)));
               ir_expression *const r041D = equal(body.constant(2097151u), r03D2);
               ir_expression *const r041E = equal(body.constant(4294967295u), r03D3);
               ir_expression *const r041F = logic_and(r041D, r041E);
               ir_expression *const r0420 = logic_and(r041C, r041F);
               ir_expression *const r0421 = logic_and(r0420, r0416);
               ir_expression *const r0422 = logic_or(r041B, r0421);
               ir_if *f041A = new(mem_ctx) ir_if(operand(r0422).val);
               exec_list *const f041A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f041A->then_instructions;

                  ir_variable *const r0423 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0423);
                  ir_expression *const r0424 = lshift(r01E6, body.constant(int(31)));
                  body.emit(assign(r0423, add(r0424, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0423, body.constant(0u), 0x01));

                  body.emit(assign(r0415, r0423, 0x03));

                  body.emit(assign(r0414, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f041A->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0426 = less(r03D1, body.constant(int(0)));
                  ir_if *f0425 = new(mem_ctx) ir_if(operand(r0426).val);
                  exec_list *const f0425_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0425->then_instructions;

                     ir_variable *const r0427 = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r0427, r03D4, 0x01));

                     ir_variable *const r0428 = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r0428, neg(r03D1), 0x01));

                     ir_variable *const r0429 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r0429);
                     ir_variable *const r042A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r042A);
                     ir_variable *const r042B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r042B);
                     ir_variable *const r042C = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r042D = neg(r0428);
                     body.emit(assign(r042C, bit_and(r042D, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r042F = equal(r0428, body.constant(int(0)));
                     ir_if *f042E = new(mem_ctx) ir_if(operand(r042F).val);
                     exec_list *const f042E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f042E->then_instructions;

                        body.emit(assign(r0429, r03D4, 0x01));

                        body.emit(assign(r042A, r03D3, 0x01));

                        body.emit(assign(r042B, r03D2, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f042E->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0431 = less(r0428, body.constant(int(32)));
                        ir_if *f0430 = new(mem_ctx) ir_if(operand(r0431).val);
                        exec_list *const f0430_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0430->then_instructions;

                           body.emit(assign(r0429, lshift(r03D3, r042C), 0x01));

                           ir_expression *const r0432 = lshift(r03D2, r042C);
                           ir_expression *const r0433 = rshift(r03D3, r0428);
                           body.emit(assign(r042A, bit_or(r0432, r0433), 0x01));

                           body.emit(assign(r042B, rshift(r03D2, r0428), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0430->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0435 = equal(r0428, body.constant(int(32)));
                           ir_if *f0434 = new(mem_ctx) ir_if(operand(r0435).val);
                           exec_list *const f0434_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0434->then_instructions;

                              body.emit(assign(r0429, r03D3, 0x01));

                              body.emit(assign(r042A, r03D2, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0434->else_instructions;

                              body.emit(assign(r0427, bit_or(r03D4, r03D3), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0437 = less(r0428, body.constant(int(64)));
                              ir_if *f0436 = new(mem_ctx) ir_if(operand(r0437).val);
                              exec_list *const f0436_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0436->then_instructions;

                                 body.emit(assign(r0429, lshift(r03D2, r042C), 0x01));

                                 ir_expression *const r0438 = bit_and(r0428, body.constant(int(31)));
                                 body.emit(assign(r042A, rshift(r03D2, r0438), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0436->else_instructions;

                                 ir_variable *const r0439 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r043B = equal(r0428, body.constant(int(64)));
                                 ir_if *f043A = new(mem_ctx) ir_if(operand(r043B).val);
                                 exec_list *const f043A_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f043A->then_instructions;

                                    body.emit(assign(r0439, r03D2, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f043A->else_instructions;

                                    ir_expression *const r043C = nequal(r03D2, body.constant(0u));
                                    ir_expression *const r043D = expr(ir_unop_b2i, r043C);
                                    body.emit(assign(r0439, expr(ir_unop_i2u, r043D), 0x01));


                                 body.instructions = f043A_parent_instructions;
                                 body.emit(f043A);

                                 /* END IF */

                                 body.emit(assign(r0429, r0439, 0x01));

                                 body.emit(assign(r042A, body.constant(0u), 0x01));


                              body.instructions = f0436_parent_instructions;
                              body.emit(f0436);

                              /* END IF */


                           body.instructions = f0434_parent_instructions;
                           body.emit(f0434);

                           /* END IF */

                           body.emit(assign(r042B, body.constant(0u), 0x01));


                        body.instructions = f0430_parent_instructions;
                        body.emit(f0430);

                        /* END IF */

                        ir_expression *const r043E = nequal(r0427, body.constant(0u));
                        ir_expression *const r043F = expr(ir_unop_b2i, r043E);
                        ir_expression *const r0440 = expr(ir_unop_i2u, r043F);
                        body.emit(assign(r0429, bit_or(r0429, r0440), 0x01));


                     body.instructions = f042E_parent_instructions;
                     body.emit(f042E);

                     /* END IF */

                     body.emit(assign(r0411, r042B, 0x01));

                     body.emit(assign(r0412, r042A, 0x01));

                     body.emit(assign(r0413, r0429, 0x01));

                     body.emit(assign(r0410, body.constant(int(0)), 0x01));

                     body.emit(assign(r0416, less(r0429, body.constant(0u)), 0x01));


                  body.instructions = f0425_parent_instructions;
                  body.emit(f0425);

                  /* END IF */


               body.instructions = f041A_parent_instructions;
               body.emit(f041A);

               /* END IF */


            body.instructions = f0418_parent_instructions;
            body.emit(f0418);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0441 = new(mem_ctx) ir_if(operand(r0414).val);
            exec_list *const f0441_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0441->then_instructions;

               /* IF CONDITION */
               ir_if *f0442 = new(mem_ctx) ir_if(operand(r0416).val);
               exec_list *const f0442_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0442->then_instructions;

                  ir_variable *const r0443 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                  body.emit(assign(r0443, add(r0412, body.constant(1u)), 0x01));

                  ir_expression *const r0444 = less(r0443, r0412);
                  ir_expression *const r0445 = expr(ir_unop_b2i, r0444);
                  ir_expression *const r0446 = expr(ir_unop_i2u, r0445);
                  body.emit(assign(r0411, add(r0411, r0446), 0x01));

                  ir_expression *const r0447 = equal(r0413, body.constant(0u));
                  ir_expression *const r0448 = expr(ir_unop_b2i, r0447);
                  ir_expression *const r0449 = expr(ir_unop_i2u, r0448);
                  ir_expression *const r044A = add(r0413, r0449);
                  ir_expression *const r044B = bit_and(r044A, body.constant(1u));
                  ir_expression *const r044C = expr(ir_unop_bit_not, r044B);
                  body.emit(assign(r0412, bit_and(r0443, r044C), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0442->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r044E = bit_or(r0411, r0412);
                  ir_expression *const r044F = equal(r044E, body.constant(0u));
                  ir_if *f044D = new(mem_ctx) ir_if(operand(r044F).val);
                  exec_list *const f044D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f044D->then_instructions;

                     body.emit(assign(r0410, body.constant(int(0)), 0x01));


                  body.instructions = f044D_parent_instructions;
                  body.emit(f044D);

                  /* END IF */


               body.instructions = f0442_parent_instructions;
               body.emit(f0442);

               /* END IF */

               ir_variable *const r0450 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0450);
               ir_expression *const r0451 = lshift(r01E6, body.constant(int(31)));
               ir_expression *const r0452 = expr(ir_unop_i2u, r0410);
               ir_expression *const r0453 = lshift(r0452, body.constant(int(20)));
               ir_expression *const r0454 = add(r0451, r0453);
               body.emit(assign(r0450, add(r0454, r0411), 0x02));

               body.emit(assign(r0450, r0412, 0x01));

               body.emit(assign(r0415, r0450, 0x03));

               body.emit(assign(r0414, body.constant(false), 0x01));


            body.instructions = f0441_parent_instructions;
            body.emit(f0441);

            /* END IF */

            body.emit(assign(r01E4, r0415, 0x03));

            body.emit(assign(r01E3, body.constant(false), 0x01));


         body.instructions = f0390_parent_instructions;
         body.emit(f0390);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f038E->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0456 = less(r0376, body.constant(int(0)));
         ir_if *f0455 = new(mem_ctx) ir_if(operand(r0456).val);
         exec_list *const f0455_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0455->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0458 = equal(r0381, body.constant(int(2047)));
            ir_if *f0457 = new(mem_ctx) ir_if(operand(r0458).val);
            exec_list *const f0457_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0457->then_instructions;

               /* IF CONDITION */
               ir_expression *const r045A = bit_or(r0379, r037A);
               ir_expression *const r045B = nequal(r045A, body.constant(0u));
               ir_if *f0459 = new(mem_ctx) ir_if(operand(r045B).val);
               exec_list *const f0459_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0459->then_instructions;

                  ir_variable *const r045C = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r045C, swizzle_x(r01E1), 0x01));

                  ir_variable *const r045D = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r045D, swizzle_x(r01E2), 0x01));

                  ir_variable *const r045E = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r045F = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r0460 = lshift(swizzle_y(r01E2), body.constant(int(1)));
                  ir_expression *const r0461 = lequal(body.constant(4292870144u), r0460);
                  ir_expression *const r0462 = nequal(swizzle_x(r01E2), body.constant(0u));
                  ir_expression *const r0463 = bit_and(swizzle_y(r01E2), body.constant(1048575u));
                  ir_expression *const r0464 = nequal(r0463, body.constant(0u));
                  ir_expression *const r0465 = logic_or(r0462, r0464);
                  body.emit(assign(r045F, logic_and(r0461, r0465), 0x01));

                  body.emit(assign(r045C, bit_or(swizzle_y(r01E1), body.constant(524288u)), 0x02));

                  body.emit(assign(r045D, bit_or(swizzle_y(r01E2), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0467 = lshift(swizzle_y(r01E1), body.constant(int(1)));
                  ir_expression *const r0468 = lequal(body.constant(4292870144u), r0467);
                  ir_expression *const r0469 = nequal(swizzle_x(r01E1), body.constant(0u));
                  ir_expression *const r046A = bit_and(swizzle_y(r01E1), body.constant(1048575u));
                  ir_expression *const r046B = nequal(r046A, body.constant(0u));
                  ir_expression *const r046C = logic_or(r0469, r046B);
                  ir_expression *const r046D = logic_and(r0468, r046C);
                  ir_if *f0466 = new(mem_ctx) ir_if(operand(r046D).val);
                  exec_list *const f0466_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0466->then_instructions;

                     ir_variable *const r046E = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f046F = new(mem_ctx) ir_if(operand(r045F).val);
                     exec_list *const f046F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f046F->then_instructions;

                        body.emit(assign(r046E, r045D, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f046F->else_instructions;

                        body.emit(assign(r046E, r045C, 0x03));


                     body.instructions = f046F_parent_instructions;
                     body.emit(f046F);

                     /* END IF */

                     body.emit(assign(r045E, r046E, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0466->else_instructions;

                     body.emit(assign(r045E, r045D, 0x03));


                  body.instructions = f0466_parent_instructions;
                  body.emit(f0466);

                  /* END IF */

                  body.emit(assign(r01E4, r045E, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0459->else_instructions;

                  ir_variable *const r0470 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r0470);
                  ir_expression *const r0471 = bit_xor(r01E6, body.constant(1u));
                  ir_expression *const r0472 = lshift(r0471, body.constant(int(31)));
                  body.emit(assign(r0470, add(r0472, body.constant(2146435072u)), 0x02));

                  body.emit(assign(r0470, body.constant(0u), 0x01));

                  body.emit(assign(r01E4, r0470, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


               body.instructions = f0459_parent_instructions;
               body.emit(f0459);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0457->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0474 = equal(r037E, body.constant(int(0)));
               ir_if *f0473 = new(mem_ctx) ir_if(operand(r0474).val);
               exec_list *const f0473_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0473->then_instructions;

                  body.emit(assign(r0376, add(r0376, body.constant(int(1))), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0473->else_instructions;

                  body.emit(assign(r037B, bit_or(r037B, body.constant(1073741824u)), 0x01));


               body.instructions = f0473_parent_instructions;
               body.emit(f0473);

               /* END IF */

               ir_variable *const r0475 = body.make_temp(glsl_type::int_type, "count");
               body.emit(assign(r0475, neg(r0376), 0x01));

               ir_variable *const r0476 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0476);
               ir_variable *const r0477 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0477);
               ir_variable *const r0478 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               ir_expression *const r0479 = neg(r0475);
               body.emit(assign(r0478, bit_and(r0479, body.constant(int(31))), 0x01));

               /* IF CONDITION */
               ir_expression *const r047B = equal(r0475, body.constant(int(0)));
               ir_if *f047A = new(mem_ctx) ir_if(operand(r047B).val);
               exec_list *const f047A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f047A->then_instructions;

                  body.emit(assign(r0476, r0384, 0x01));

                  body.emit(assign(r0477, r037B, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f047A->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r047D = less(r0475, body.constant(int(32)));
                  ir_if *f047C = new(mem_ctx) ir_if(operand(r047D).val);
                  exec_list *const f047C_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f047C->then_instructions;

                     ir_expression *const r047E = lshift(r037B, r0478);
                     ir_expression *const r047F = rshift(r0384, r0475);
                     ir_expression *const r0480 = bit_or(r047E, r047F);
                     ir_expression *const r0481 = lshift(r0384, r0478);
                     ir_expression *const r0482 = nequal(r0481, body.constant(0u));
                     ir_expression *const r0483 = expr(ir_unop_b2i, r0482);
                     ir_expression *const r0484 = expr(ir_unop_i2u, r0483);
                     body.emit(assign(r0476, bit_or(r0480, r0484), 0x01));

                     body.emit(assign(r0477, rshift(r037B, r0475), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f047C->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0486 = equal(r0475, body.constant(int(32)));
                     ir_if *f0485 = new(mem_ctx) ir_if(operand(r0486).val);
                     exec_list *const f0485_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0485->then_instructions;

                        ir_expression *const r0487 = nequal(r0384, body.constant(0u));
                        ir_expression *const r0488 = expr(ir_unop_b2i, r0487);
                        ir_expression *const r0489 = expr(ir_unop_i2u, r0488);
                        body.emit(assign(r0476, bit_or(r037B, r0489), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0485->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r048B = less(r0475, body.constant(int(64)));
                        ir_if *f048A = new(mem_ctx) ir_if(operand(r048B).val);
                        exec_list *const f048A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f048A->then_instructions;

                           ir_expression *const r048C = bit_and(r0475, body.constant(int(31)));
                           ir_expression *const r048D = rshift(r037B, r048C);
                           ir_expression *const r048E = lshift(r037B, r0478);
                           ir_expression *const r048F = bit_or(r048E, r0384);
                           ir_expression *const r0490 = nequal(r048F, body.constant(0u));
                           ir_expression *const r0491 = expr(ir_unop_b2i, r0490);
                           ir_expression *const r0492 = expr(ir_unop_i2u, r0491);
                           body.emit(assign(r0476, bit_or(r048D, r0492), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f048A->else_instructions;

                           ir_expression *const r0493 = bit_or(r037B, r0384);
                           ir_expression *const r0494 = nequal(r0493, body.constant(0u));
                           ir_expression *const r0495 = expr(ir_unop_b2i, r0494);
                           body.emit(assign(r0476, expr(ir_unop_i2u, r0495), 0x01));


                        body.instructions = f048A_parent_instructions;
                        body.emit(f048A);

                        /* END IF */


                     body.instructions = f0485_parent_instructions;
                     body.emit(f0485);

                     /* END IF */

                     body.emit(assign(r0477, body.constant(0u), 0x01));


                  body.instructions = f047C_parent_instructions;
                  body.emit(f047C);

                  /* END IF */


               body.instructions = f047A_parent_instructions;
               body.emit(f047A);

               /* END IF */

               body.emit(assign(r037B, r0477, 0x01));

               body.emit(assign(r037C, r0476, 0x01));

               body.emit(assign(r0379, bit_or(r0379, body.constant(1073741824u)), 0x01));

               ir_variable *const r0496 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0497 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0497, sub(r037A, r0476), 0x01));

               ir_expression *const r0498 = sub(r0379, r0477);
               ir_expression *const r0499 = less(r037A, r0476);
               ir_expression *const r049A = expr(ir_unop_b2i, r0499);
               ir_expression *const r049B = expr(ir_unop_i2u, r049A);
               body.emit(assign(r0496, sub(r0498, r049B), 0x01));

               body.emit(assign(r01E5, bit_xor(r01E6, body.constant(1u)), 0x01));

               body.emit(assign(r037D, add(r0381, body.constant(int(-1))), 0x01));

               ir_variable *const r049C = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r049C, add(r037D, body.constant(int(-10))), 0x01));

               ir_variable *const r049D = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r049D, r0496, 0x01));

               ir_variable *const r049E = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r049E, r0497, 0x01));

               ir_variable *const r049F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
               body.emit(r049F);
               ir_variable *const r04A0 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04A0);
               /* IF CONDITION */
               ir_expression *const r04A2 = equal(r0496, body.constant(0u));
               ir_if *f04A1 = new(mem_ctx) ir_if(operand(r04A2).val);
               exec_list *const f04A1_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04A1->then_instructions;

                  body.emit(assign(r049D, r0497, 0x01));

                  body.emit(assign(r049E, body.constant(0u), 0x01));

                  body.emit(assign(r049C, add(r049C, body.constant(int(-32))), 0x01));


               body.instructions = f04A1_parent_instructions;
               body.emit(f04A1);

               /* END IF */

               ir_variable *const r04A3 = body.make_temp(glsl_type::uint_type, "a");
               body.emit(assign(r04A3, r049D, 0x01));

               ir_variable *const r04A4 = body.make_temp(glsl_type::int_type, "return_value");
               ir_variable *const r04A5 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r04A5);
               /* IF CONDITION */
               ir_expression *const r04A7 = equal(r049D, body.constant(0u));
               ir_if *f04A6 = new(mem_ctx) ir_if(operand(r04A7).val);
               exec_list *const f04A6_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04A6->then_instructions;

                  body.emit(assign(r04A4, body.constant(int(32)), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04A6->else_instructions;

                  body.emit(assign(r04A5, body.constant(int(0)), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04A9 = bit_and(r049D, body.constant(4294901760u));
                  ir_expression *const r04AA = equal(r04A9, body.constant(0u));
                  ir_if *f04A8 = new(mem_ctx) ir_if(operand(r04AA).val);
                  exec_list *const f04A8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04A8->then_instructions;

                     body.emit(assign(r04A5, body.constant(int(16)), 0x01));

                     body.emit(assign(r04A3, lshift(r049D, body.constant(int(16))), 0x01));


                  body.instructions = f04A8_parent_instructions;
                  body.emit(f04A8);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04AC = bit_and(r04A3, body.constant(4278190080u));
                  ir_expression *const r04AD = equal(r04AC, body.constant(0u));
                  ir_if *f04AB = new(mem_ctx) ir_if(operand(r04AD).val);
                  exec_list *const f04AB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04AB->then_instructions;

                     body.emit(assign(r04A5, add(r04A5, body.constant(int(8))), 0x01));

                     body.emit(assign(r04A3, lshift(r04A3, body.constant(int(8))), 0x01));


                  body.instructions = f04AB_parent_instructions;
                  body.emit(f04AB);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04AF = bit_and(r04A3, body.constant(4026531840u));
                  ir_expression *const r04B0 = equal(r04AF, body.constant(0u));
                  ir_if *f04AE = new(mem_ctx) ir_if(operand(r04B0).val);
                  exec_list *const f04AE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04AE->then_instructions;

                     body.emit(assign(r04A5, add(r04A5, body.constant(int(4))), 0x01));

                     body.emit(assign(r04A3, lshift(r04A3, body.constant(int(4))), 0x01));


                  body.instructions = f04AE_parent_instructions;
                  body.emit(f04AE);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04B2 = bit_and(r04A3, body.constant(3221225472u));
                  ir_expression *const r04B3 = equal(r04B2, body.constant(0u));
                  ir_if *f04B1 = new(mem_ctx) ir_if(operand(r04B3).val);
                  exec_list *const f04B1_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04B1->then_instructions;

                     body.emit(assign(r04A5, add(r04A5, body.constant(int(2))), 0x01));

                     body.emit(assign(r04A3, lshift(r04A3, body.constant(int(2))), 0x01));


                  body.instructions = f04B1_parent_instructions;
                  body.emit(f04B1);

                  /* END IF */

                  /* IF CONDITION */
                  ir_expression *const r04B5 = bit_and(r04A3, body.constant(2147483648u));
                  ir_expression *const r04B6 = equal(r04B5, body.constant(0u));
                  ir_if *f04B4 = new(mem_ctx) ir_if(operand(r04B6).val);
                  exec_list *const f04B4_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04B4->then_instructions;

                     body.emit(assign(r04A5, add(r04A5, body.constant(int(1))), 0x01));


                  body.instructions = f04B4_parent_instructions;
                  body.emit(f04B4);

                  /* END IF */

                  body.emit(assign(r04A4, r04A5, 0x01));


               body.instructions = f04A6_parent_instructions;
               body.emit(f04A6);

               /* END IF */

               body.emit(assign(r04A0, add(r04A4, body.constant(int(-11))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04B8 = lequal(body.constant(int(0)), r04A0);
               ir_if *f04B7 = new(mem_ctx) ir_if(operand(r04B8).val);
               exec_list *const f04B7_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04B7->then_instructions;

                  body.emit(assign(r049F, body.constant(0u), 0x01));

                  ir_variable *const r04B9 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r04B9, lshift(r049E, r04A0), 0x01));

                  ir_variable *const r04BA = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r04BC = equal(r04A0, body.constant(int(0)));
                  ir_if *f04BB = new(mem_ctx) ir_if(operand(r04BC).val);
                  exec_list *const f04BB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04BB->then_instructions;

                     body.emit(assign(r04BA, r049D, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04BB->else_instructions;

                     ir_expression *const r04BD = lshift(r049D, r04A0);
                     ir_expression *const r04BE = neg(r04A0);
                     ir_expression *const r04BF = bit_and(r04BE, body.constant(int(31)));
                     ir_expression *const r04C0 = rshift(r049E, r04BF);
                     body.emit(assign(r04BA, bit_or(r04BD, r04C0), 0x01));


                  body.instructions = f04BB_parent_instructions;
                  body.emit(f04BB);

                  /* END IF */

                  body.emit(assign(r049D, r04BA, 0x01));

                  body.emit(assign(r049E, r04B9, 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f04B7->else_instructions;

                  ir_variable *const r04C1 = body.make_temp(glsl_type::uint_type, "a2");
                  body.emit(assign(r04C1, body.constant(0u), 0x01));

                  ir_variable *const r04C2 = body.make_temp(glsl_type::int_type, "count");
                  body.emit(assign(r04C2, neg(r04A0), 0x01));

                  ir_variable *const r04C3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r04C3);
                  ir_variable *const r04C4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                  body.emit(r04C4);
                  ir_variable *const r04C5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                  body.emit(r04C5);
                  ir_variable *const r04C6 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                  ir_expression *const r04C7 = neg(r04C2);
                  body.emit(assign(r04C6, bit_and(r04C7, body.constant(int(31))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r04C9 = equal(r04C2, body.constant(int(0)));
                  ir_if *f04C8 = new(mem_ctx) ir_if(operand(r04C9).val);
                  exec_list *const f04C8_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04C8->then_instructions;

                     body.emit(assign(r04C3, r04C1, 0x01));

                     body.emit(assign(r04C4, r049E, 0x01));

                     body.emit(assign(r04C5, r049D, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04C8->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04CB = less(r04C2, body.constant(int(32)));
                     ir_if *f04CA = new(mem_ctx) ir_if(operand(r04CB).val);
                     exec_list *const f04CA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04CA->then_instructions;

                        body.emit(assign(r04C3, lshift(r049E, r04C6), 0x01));

                        ir_expression *const r04CC = lshift(r049D, r04C6);
                        ir_expression *const r04CD = rshift(r049E, r04C2);
                        body.emit(assign(r04C4, bit_or(r04CC, r04CD), 0x01));

                        body.emit(assign(r04C5, rshift(r049D, r04C2), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f04CA->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r04CF = equal(r04C2, body.constant(int(32)));
                        ir_if *f04CE = new(mem_ctx) ir_if(operand(r04CF).val);
                        exec_list *const f04CE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04CE->then_instructions;

                           body.emit(assign(r04C3, r049E, 0x01));

                           body.emit(assign(r04C4, r049D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04CE->else_instructions;

                           body.emit(assign(r04C1, bit_or(body.constant(0u), r049E), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r04D1 = less(r04C2, body.constant(int(64)));
                           ir_if *f04D0 = new(mem_ctx) ir_if(operand(r04D1).val);
                           exec_list *const f04D0_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04D0->then_instructions;

                              body.emit(assign(r04C3, lshift(r049D, r04C6), 0x01));

                              ir_expression *const r04D2 = bit_and(r04C2, body.constant(int(31)));
                              body.emit(assign(r04C4, rshift(r049D, r04D2), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04D0->else_instructions;

                              ir_variable *const r04D3 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r04D5 = equal(r04C2, body.constant(int(64)));
                              ir_if *f04D4 = new(mem_ctx) ir_if(operand(r04D5).val);
                              exec_list *const f04D4_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04D4->then_instructions;

                                 body.emit(assign(r04D3, r049D, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04D4->else_instructions;

                                 ir_expression *const r04D6 = nequal(r049D, body.constant(0u));
                                 ir_expression *const r04D7 = expr(ir_unop_b2i, r04D6);
                                 body.emit(assign(r04D3, expr(ir_unop_i2u, r04D7), 0x01));


                              body.instructions = f04D4_parent_instructions;
                              body.emit(f04D4);

                              /* END IF */

                              body.emit(assign(r04C3, r04D3, 0x01));

                              body.emit(assign(r04C4, body.constant(0u), 0x01));


                           body.instructions = f04D0_parent_instructions;
                           body.emit(f04D0);

                           /* END IF */


                        body.instructions = f04CE_parent_instructions;
                        body.emit(f04CE);

                        /* END IF */

                        body.emit(assign(r04C5, body.constant(0u), 0x01));


                     body.instructions = f04CA_parent_instructions;
                     body.emit(f04CA);

                     /* END IF */

                     ir_expression *const r04D8 = nequal(r04C1, body.constant(0u));
                     ir_expression *const r04D9 = expr(ir_unop_b2i, r04D8);
                     ir_expression *const r04DA = expr(ir_unop_i2u, r04D9);
                     body.emit(assign(r04C3, bit_or(r04C3, r04DA), 0x01));


                  body.instructions = f04C8_parent_instructions;
                  body.emit(f04C8);

                  /* END IF */

                  body.emit(assign(r049D, r04C5, 0x01));

                  body.emit(assign(r049E, r04C4, 0x01));

                  body.emit(assign(r049F, r04C3, 0x01));


               body.instructions = f04B7_parent_instructions;
               body.emit(f04B7);

               /* END IF */

               body.emit(assign(r049C, sub(r049C, r04A0), 0x01));

               ir_variable *const r04DB = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r04DB, r049C, 0x01));

               ir_variable *const r04DC = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r04DC, r049D, 0x01));

               ir_variable *const r04DD = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r04DD, r049E, 0x01));

               ir_variable *const r04DE = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r04DE, r049F, 0x01));

               ir_variable *const r04DF = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r04DF, body.constant(true), 0x01));

               ir_variable *const r04E0 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r04E1 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r04E1);
               ir_expression *const r04E2 = expr(ir_unop_u2i, r049F);
               body.emit(assign(r04E1, less(r04E2, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r04E4 = lequal(body.constant(int(2045)), r049C);
               ir_if *f04E3 = new(mem_ctx) ir_if(operand(r04E4).val);
               exec_list *const f04E3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f04E3->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r04E6 = less(body.constant(int(2045)), r049C);
                  ir_expression *const r04E7 = equal(r049C, body.constant(int(2045)));
                  ir_expression *const r04E8 = equal(body.constant(2097151u), r049D);
                  ir_expression *const r04E9 = equal(body.constant(4294967295u), r049E);
                  ir_expression *const r04EA = logic_and(r04E8, r04E9);
                  ir_expression *const r04EB = logic_and(r04E7, r04EA);
                  ir_expression *const r04EC = logic_and(r04EB, r04E1);
                  ir_expression *const r04ED = logic_or(r04E6, r04EC);
                  ir_if *f04E5 = new(mem_ctx) ir_if(operand(r04ED).val);
                  exec_list *const f04E5_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f04E5->then_instructions;

                     ir_variable *const r04EE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r04EE);
                     ir_expression *const r04EF = lshift(r01E5, body.constant(int(31)));
                     body.emit(assign(r04EE, add(r04EF, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r04EE, body.constant(0u), 0x01));

                     body.emit(assign(r04E0, r04EE, 0x03));

                     body.emit(assign(r04DF, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f04E5->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r04F1 = less(r049C, body.constant(int(0)));
                     ir_if *f04F0 = new(mem_ctx) ir_if(operand(r04F1).val);
                     exec_list *const f04F0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f04F0->then_instructions;

                        ir_variable *const r04F2 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r04F2, r049F, 0x01));

                        ir_variable *const r04F3 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r04F3, neg(r049C), 0x01));

                        ir_variable *const r04F4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r04F4);
                        ir_variable *const r04F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r04F5);
                        ir_variable *const r04F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r04F6);
                        ir_variable *const r04F7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r04F8 = neg(r04F3);
                        body.emit(assign(r04F7, bit_and(r04F8, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r04FA = equal(r04F3, body.constant(int(0)));
                        ir_if *f04F9 = new(mem_ctx) ir_if(operand(r04FA).val);
                        exec_list *const f04F9_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f04F9->then_instructions;

                           body.emit(assign(r04F4, r049F, 0x01));

                           body.emit(assign(r04F5, r049E, 0x01));

                           body.emit(assign(r04F6, r049D, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f04F9->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r04FC = less(r04F3, body.constant(int(32)));
                           ir_if *f04FB = new(mem_ctx) ir_if(operand(r04FC).val);
                           exec_list *const f04FB_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f04FB->then_instructions;

                              body.emit(assign(r04F4, lshift(r049E, r04F7), 0x01));

                              ir_expression *const r04FD = lshift(r049D, r04F7);
                              ir_expression *const r04FE = rshift(r049E, r04F3);
                              body.emit(assign(r04F5, bit_or(r04FD, r04FE), 0x01));

                              body.emit(assign(r04F6, rshift(r049D, r04F3), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f04FB->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0500 = equal(r04F3, body.constant(int(32)));
                              ir_if *f04FF = new(mem_ctx) ir_if(operand(r0500).val);
                              exec_list *const f04FF_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f04FF->then_instructions;

                                 body.emit(assign(r04F4, r049E, 0x01));

                                 body.emit(assign(r04F5, r049D, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f04FF->else_instructions;

                                 body.emit(assign(r04F2, bit_or(r049F, r049E), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0502 = less(r04F3, body.constant(int(64)));
                                 ir_if *f0501 = new(mem_ctx) ir_if(operand(r0502).val);
                                 exec_list *const f0501_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0501->then_instructions;

                                    body.emit(assign(r04F4, lshift(r049D, r04F7), 0x01));

                                    ir_expression *const r0503 = bit_and(r04F3, body.constant(int(31)));
                                    body.emit(assign(r04F5, rshift(r049D, r0503), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0501->else_instructions;

                                    ir_variable *const r0504 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r0506 = equal(r04F3, body.constant(int(64)));
                                    ir_if *f0505 = new(mem_ctx) ir_if(operand(r0506).val);
                                    exec_list *const f0505_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0505->then_instructions;

                                       body.emit(assign(r0504, r049D, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0505->else_instructions;

                                       ir_expression *const r0507 = nequal(r049D, body.constant(0u));
                                       ir_expression *const r0508 = expr(ir_unop_b2i, r0507);
                                       body.emit(assign(r0504, expr(ir_unop_i2u, r0508), 0x01));


                                    body.instructions = f0505_parent_instructions;
                                    body.emit(f0505);

                                    /* END IF */

                                    body.emit(assign(r04F4, r0504, 0x01));

                                    body.emit(assign(r04F5, body.constant(0u), 0x01));


                                 body.instructions = f0501_parent_instructions;
                                 body.emit(f0501);

                                 /* END IF */


                              body.instructions = f04FF_parent_instructions;
                              body.emit(f04FF);

                              /* END IF */

                              body.emit(assign(r04F6, body.constant(0u), 0x01));


                           body.instructions = f04FB_parent_instructions;
                           body.emit(f04FB);

                           /* END IF */

                           ir_expression *const r0509 = nequal(r04F2, body.constant(0u));
                           ir_expression *const r050A = expr(ir_unop_b2i, r0509);
                           ir_expression *const r050B = expr(ir_unop_i2u, r050A);
                           body.emit(assign(r04F4, bit_or(r04F4, r050B), 0x01));


                        body.instructions = f04F9_parent_instructions;
                        body.emit(f04F9);

                        /* END IF */

                        body.emit(assign(r04DC, r04F6, 0x01));

                        body.emit(assign(r04DD, r04F5, 0x01));

                        body.emit(assign(r04DE, r04F4, 0x01));

                        body.emit(assign(r04DB, body.constant(int(0)), 0x01));

                        body.emit(assign(r04E1, less(r04F4, body.constant(0u)), 0x01));


                     body.instructions = f04F0_parent_instructions;
                     body.emit(f04F0);

                     /* END IF */


                  body.instructions = f04E5_parent_instructions;
                  body.emit(f04E5);

                  /* END IF */


               body.instructions = f04E3_parent_instructions;
               body.emit(f04E3);

               /* END IF */

               /* IF CONDITION */
               ir_if *f050C = new(mem_ctx) ir_if(operand(r04DF).val);
               exec_list *const f050C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f050C->then_instructions;

                  /* IF CONDITION */
                  ir_if *f050D = new(mem_ctx) ir_if(operand(r04E1).val);
                  exec_list *const f050D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f050D->then_instructions;

                     ir_variable *const r050E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r050E, add(r04DD, body.constant(1u)), 0x01));

                     ir_expression *const r050F = less(r050E, r04DD);
                     ir_expression *const r0510 = expr(ir_unop_b2i, r050F);
                     ir_expression *const r0511 = expr(ir_unop_i2u, r0510);
                     body.emit(assign(r04DC, add(r04DC, r0511), 0x01));

                     ir_expression *const r0512 = equal(r04DE, body.constant(0u));
                     ir_expression *const r0513 = expr(ir_unop_b2i, r0512);
                     ir_expression *const r0514 = expr(ir_unop_i2u, r0513);
                     ir_expression *const r0515 = add(r04DE, r0514);
                     ir_expression *const r0516 = bit_and(r0515, body.constant(1u));
                     ir_expression *const r0517 = expr(ir_unop_bit_not, r0516);
                     body.emit(assign(r04DD, bit_and(r050E, r0517), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f050D->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0519 = bit_or(r04DC, r04DD);
                     ir_expression *const r051A = equal(r0519, body.constant(0u));
                     ir_if *f0518 = new(mem_ctx) ir_if(operand(r051A).val);
                     exec_list *const f0518_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0518->then_instructions;

                        body.emit(assign(r04DB, body.constant(int(0)), 0x01));


                     body.instructions = f0518_parent_instructions;
                     body.emit(f0518);

                     /* END IF */


                  body.instructions = f050D_parent_instructions;
                  body.emit(f050D);

                  /* END IF */

                  ir_variable *const r051B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r051B);
                  ir_expression *const r051C = lshift(r01E5, body.constant(int(31)));
                  ir_expression *const r051D = expr(ir_unop_i2u, r04DB);
                  ir_expression *const r051E = lshift(r051D, body.constant(int(20)));
                  ir_expression *const r051F = add(r051C, r051E);
                  body.emit(assign(r051B, add(r051F, r04DC), 0x02));

                  body.emit(assign(r051B, r04DD, 0x01));

                  body.emit(assign(r04E0, r051B, 0x03));

                  body.emit(assign(r04DF, body.constant(false), 0x01));


               body.instructions = f050C_parent_instructions;
               body.emit(f050C);

               /* END IF */

               body.emit(assign(r01E4, r04E0, 0x03));

               body.emit(assign(r01E3, body.constant(false), 0x01));


            body.instructions = f0457_parent_instructions;
            body.emit(f0457);

            /* END IF */


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0455->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0521 = equal(r037E, body.constant(int(2047)));
            ir_if *f0520 = new(mem_ctx) ir_if(operand(r0521).val);
            exec_list *const f0520_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0520->then_instructions;

               /* IF CONDITION */
               ir_expression *const r0523 = bit_or(r037B, r037C);
               ir_expression *const r0524 = bit_or(r0379, r037A);
               ir_expression *const r0525 = bit_or(r0523, r0524);
               ir_expression *const r0526 = nequal(r0525, body.constant(0u));
               ir_if *f0522 = new(mem_ctx) ir_if(operand(r0526).val);
               exec_list *const f0522_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0522->then_instructions;

                  ir_variable *const r0527 = body.make_temp(glsl_type::uvec2_type, "a");
                  body.emit(assign(r0527, swizzle_x(r01E1), 0x01));

                  ir_variable *const r0528 = body.make_temp(glsl_type::uvec2_type, "b");
                  body.emit(assign(r0528, swizzle_x(r01E2), 0x01));

                  ir_variable *const r0529 = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r052A = body.make_temp(glsl_type::bool_type, "is_nan_retval");
                  ir_expression *const r052B = lshift(swizzle_y(r01E2), body.constant(int(1)));
                  ir_expression *const r052C = lequal(body.constant(4292870144u), r052B);
                  ir_expression *const r052D = nequal(swizzle_x(r01E2), body.constant(0u));
                  ir_expression *const r052E = bit_and(swizzle_y(r01E2), body.constant(1048575u));
                  ir_expression *const r052F = nequal(r052E, body.constant(0u));
                  ir_expression *const r0530 = logic_or(r052D, r052F);
                  body.emit(assign(r052A, logic_and(r052C, r0530), 0x01));

                  body.emit(assign(r0527, bit_or(swizzle_y(r01E1), body.constant(524288u)), 0x02));

                  body.emit(assign(r0528, bit_or(swizzle_y(r01E2), body.constant(524288u)), 0x02));

                  /* IF CONDITION */
                  ir_expression *const r0532 = lshift(swizzle_y(r01E1), body.constant(int(1)));
                  ir_expression *const r0533 = lequal(body.constant(4292870144u), r0532);
                  ir_expression *const r0534 = nequal(swizzle_x(r01E1), body.constant(0u));
                  ir_expression *const r0535 = bit_and(swizzle_y(r01E1), body.constant(1048575u));
                  ir_expression *const r0536 = nequal(r0535, body.constant(0u));
                  ir_expression *const r0537 = logic_or(r0534, r0536);
                  ir_expression *const r0538 = logic_and(r0533, r0537);
                  ir_if *f0531 = new(mem_ctx) ir_if(operand(r0538).val);
                  exec_list *const f0531_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0531->then_instructions;

                     ir_variable *const r0539 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_if *f053A = new(mem_ctx) ir_if(operand(r052A).val);
                     exec_list *const f053A_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f053A->then_instructions;

                        body.emit(assign(r0539, r0528, 0x03));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f053A->else_instructions;

                        body.emit(assign(r0539, r0527, 0x03));


                     body.instructions = f053A_parent_instructions;
                     body.emit(f053A);

                     /* END IF */

                     body.emit(assign(r0529, r0539, 0x03));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0531->else_instructions;

                     body.emit(assign(r0529, r0528, 0x03));


                  body.instructions = f0531_parent_instructions;
                  body.emit(f0531);

                  /* END IF */

                  body.emit(assign(r01E4, r0529, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0522->else_instructions;

                  ir_constant_data r053B_data;
                  memset(&r053B_data, 0, sizeof(ir_constant_data));
                  r053B_data.u[0] = 4294967295;
                  r053B_data.u[1] = 4294967295;
                  ir_constant *const r053B = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r053B_data);
                  body.emit(assign(r01E4, r053B, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


               body.instructions = f0522_parent_instructions;
               body.emit(f0522);

               /* END IF */


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0520->else_instructions;

               /* IF CONDITION */
               ir_expression *const r053D = equal(r037E, body.constant(int(0)));
               ir_if *f053C = new(mem_ctx) ir_if(operand(r053D).val);
               exec_list *const f053C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f053C->then_instructions;

                  body.emit(assign(r0378, body.constant(int(1)), 0x01));

                  body.emit(assign(r0377, body.constant(int(1)), 0x01));


               body.instructions = f053C_parent_instructions;
               body.emit(f053C);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r053F = less(r0379, r037B);
               ir_if *f053E = new(mem_ctx) ir_if(operand(r053F).val);
               exec_list *const f053E_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f053E->then_instructions;

                  ir_variable *const r0540 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                  ir_variable *const r0541 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r0541, sub(r037C, r037A), 0x01));

                  ir_expression *const r0542 = sub(r037B, r0379);
                  ir_expression *const r0543 = less(r037C, r037A);
                  ir_expression *const r0544 = expr(ir_unop_b2i, r0543);
                  ir_expression *const r0545 = expr(ir_unop_i2u, r0544);
                  body.emit(assign(r0540, sub(r0542, r0545), 0x01));

                  body.emit(assign(r037D, add(r0378, body.constant(int(-1))), 0x01));

                  ir_variable *const r0546 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0546, add(r037D, body.constant(int(-10))), 0x01));

                  ir_variable *const r0547 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0547, r0540, 0x01));

                  ir_variable *const r0548 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0548, r0541, 0x01));

                  ir_variable *const r0549 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                  body.emit(r0549);
                  ir_variable *const r054A = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r054A);
                  /* IF CONDITION */
                  ir_expression *const r054C = equal(r0540, body.constant(0u));
                  ir_if *f054B = new(mem_ctx) ir_if(operand(r054C).val);
                  exec_list *const f054B_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f054B->then_instructions;

                     body.emit(assign(r0547, r0541, 0x01));

                     body.emit(assign(r0548, body.constant(0u), 0x01));

                     body.emit(assign(r0546, add(r0546, body.constant(int(-32))), 0x01));


                  body.instructions = f054B_parent_instructions;
                  body.emit(f054B);

                  /* END IF */

                  ir_variable *const r054D = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r054D, r0547, 0x01));

                  ir_variable *const r054E = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r054F = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r054F);
                  /* IF CONDITION */
                  ir_expression *const r0551 = equal(r0547, body.constant(0u));
                  ir_if *f0550 = new(mem_ctx) ir_if(operand(r0551).val);
                  exec_list *const f0550_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0550->then_instructions;

                     body.emit(assign(r054E, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0550->else_instructions;

                     body.emit(assign(r054F, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0553 = bit_and(r0547, body.constant(4294901760u));
                     ir_expression *const r0554 = equal(r0553, body.constant(0u));
                     ir_if *f0552 = new(mem_ctx) ir_if(operand(r0554).val);
                     exec_list *const f0552_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0552->then_instructions;

                        body.emit(assign(r054F, body.constant(int(16)), 0x01));

                        body.emit(assign(r054D, lshift(r0547, body.constant(int(16))), 0x01));


                     body.instructions = f0552_parent_instructions;
                     body.emit(f0552);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0556 = bit_and(r054D, body.constant(4278190080u));
                     ir_expression *const r0557 = equal(r0556, body.constant(0u));
                     ir_if *f0555 = new(mem_ctx) ir_if(operand(r0557).val);
                     exec_list *const f0555_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0555->then_instructions;

                        body.emit(assign(r054F, add(r054F, body.constant(int(8))), 0x01));

                        body.emit(assign(r054D, lshift(r054D, body.constant(int(8))), 0x01));


                     body.instructions = f0555_parent_instructions;
                     body.emit(f0555);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r0559 = bit_and(r054D, body.constant(4026531840u));
                     ir_expression *const r055A = equal(r0559, body.constant(0u));
                     ir_if *f0558 = new(mem_ctx) ir_if(operand(r055A).val);
                     exec_list *const f0558_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0558->then_instructions;

                        body.emit(assign(r054F, add(r054F, body.constant(int(4))), 0x01));

                        body.emit(assign(r054D, lshift(r054D, body.constant(int(4))), 0x01));


                     body.instructions = f0558_parent_instructions;
                     body.emit(f0558);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r055C = bit_and(r054D, body.constant(3221225472u));
                     ir_expression *const r055D = equal(r055C, body.constant(0u));
                     ir_if *f055B = new(mem_ctx) ir_if(operand(r055D).val);
                     exec_list *const f055B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f055B->then_instructions;

                        body.emit(assign(r054F, add(r054F, body.constant(int(2))), 0x01));

                        body.emit(assign(r054D, lshift(r054D, body.constant(int(2))), 0x01));


                     body.instructions = f055B_parent_instructions;
                     body.emit(f055B);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r055F = bit_and(r054D, body.constant(2147483648u));
                     ir_expression *const r0560 = equal(r055F, body.constant(0u));
                     ir_if *f055E = new(mem_ctx) ir_if(operand(r0560).val);
                     exec_list *const f055E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f055E->then_instructions;

                        body.emit(assign(r054F, add(r054F, body.constant(int(1))), 0x01));


                     body.instructions = f055E_parent_instructions;
                     body.emit(f055E);

                     /* END IF */

                     body.emit(assign(r054E, r054F, 0x01));


                  body.instructions = f0550_parent_instructions;
                  body.emit(f0550);

                  /* END IF */

                  body.emit(assign(r054A, add(r054E, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r0562 = lequal(body.constant(int(0)), r054A);
                  ir_if *f0561 = new(mem_ctx) ir_if(operand(r0562).val);
                  exec_list *const f0561_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0561->then_instructions;

                     body.emit(assign(r0549, body.constant(0u), 0x01));

                     ir_variable *const r0563 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r0563, lshift(r0548, r054A), 0x01));

                     ir_variable *const r0564 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r0566 = equal(r054A, body.constant(int(0)));
                     ir_if *f0565 = new(mem_ctx) ir_if(operand(r0566).val);
                     exec_list *const f0565_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0565->then_instructions;

                        body.emit(assign(r0564, r0547, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0565->else_instructions;

                        ir_expression *const r0567 = lshift(r0547, r054A);
                        ir_expression *const r0568 = neg(r054A);
                        ir_expression *const r0569 = bit_and(r0568, body.constant(int(31)));
                        ir_expression *const r056A = rshift(r0548, r0569);
                        body.emit(assign(r0564, bit_or(r0567, r056A), 0x01));


                     body.instructions = f0565_parent_instructions;
                     body.emit(f0565);

                     /* END IF */

                     body.emit(assign(r0547, r0564, 0x01));

                     body.emit(assign(r0548, r0563, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0561->else_instructions;

                     ir_variable *const r056B = body.make_temp(glsl_type::uint_type, "a2");
                     body.emit(assign(r056B, body.constant(0u), 0x01));

                     ir_variable *const r056C = body.make_temp(glsl_type::int_type, "count");
                     body.emit(assign(r056C, neg(r054A), 0x01));

                     ir_variable *const r056D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                     body.emit(r056D);
                     ir_variable *const r056E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                     body.emit(r056E);
                     ir_variable *const r056F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                     body.emit(r056F);
                     ir_variable *const r0570 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                     ir_expression *const r0571 = neg(r056C);
                     body.emit(assign(r0570, bit_and(r0571, body.constant(int(31))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r0573 = equal(r056C, body.constant(int(0)));
                     ir_if *f0572 = new(mem_ctx) ir_if(operand(r0573).val);
                     exec_list *const f0572_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0572->then_instructions;

                        body.emit(assign(r056D, r056B, 0x01));

                        body.emit(assign(r056E, r0548, 0x01));

                        body.emit(assign(r056F, r0547, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0572->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r0575 = less(r056C, body.constant(int(32)));
                        ir_if *f0574 = new(mem_ctx) ir_if(operand(r0575).val);
                        exec_list *const f0574_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0574->then_instructions;

                           body.emit(assign(r056D, lshift(r0548, r0570), 0x01));

                           ir_expression *const r0576 = lshift(r0547, r0570);
                           ir_expression *const r0577 = rshift(r0548, r056C);
                           body.emit(assign(r056E, bit_or(r0576, r0577), 0x01));

                           body.emit(assign(r056F, rshift(r0547, r056C), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0574->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0579 = equal(r056C, body.constant(int(32)));
                           ir_if *f0578 = new(mem_ctx) ir_if(operand(r0579).val);
                           exec_list *const f0578_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0578->then_instructions;

                              body.emit(assign(r056D, r0548, 0x01));

                              body.emit(assign(r056E, r0547, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0578->else_instructions;

                              body.emit(assign(r056B, bit_or(body.constant(0u), r0548), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r057B = less(r056C, body.constant(int(64)));
                              ir_if *f057A = new(mem_ctx) ir_if(operand(r057B).val);
                              exec_list *const f057A_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f057A->then_instructions;

                                 body.emit(assign(r056D, lshift(r0547, r0570), 0x01));

                                 ir_expression *const r057C = bit_and(r056C, body.constant(int(31)));
                                 body.emit(assign(r056E, rshift(r0547, r057C), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f057A->else_instructions;

                                 ir_variable *const r057D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                 /* IF CONDITION */
                                 ir_expression *const r057F = equal(r056C, body.constant(int(64)));
                                 ir_if *f057E = new(mem_ctx) ir_if(operand(r057F).val);
                                 exec_list *const f057E_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f057E->then_instructions;

                                    body.emit(assign(r057D, r0547, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f057E->else_instructions;

                                    ir_expression *const r0580 = nequal(r0547, body.constant(0u));
                                    ir_expression *const r0581 = expr(ir_unop_b2i, r0580);
                                    body.emit(assign(r057D, expr(ir_unop_i2u, r0581), 0x01));


                                 body.instructions = f057E_parent_instructions;
                                 body.emit(f057E);

                                 /* END IF */

                                 body.emit(assign(r056D, r057D, 0x01));

                                 body.emit(assign(r056E, body.constant(0u), 0x01));


                              body.instructions = f057A_parent_instructions;
                              body.emit(f057A);

                              /* END IF */


                           body.instructions = f0578_parent_instructions;
                           body.emit(f0578);

                           /* END IF */

                           body.emit(assign(r056F, body.constant(0u), 0x01));


                        body.instructions = f0574_parent_instructions;
                        body.emit(f0574);

                        /* END IF */

                        ir_expression *const r0582 = nequal(r056B, body.constant(0u));
                        ir_expression *const r0583 = expr(ir_unop_b2i, r0582);
                        ir_expression *const r0584 = expr(ir_unop_i2u, r0583);
                        body.emit(assign(r056D, bit_or(r056D, r0584), 0x01));


                     body.instructions = f0572_parent_instructions;
                     body.emit(f0572);

                     /* END IF */

                     body.emit(assign(r0547, r056F, 0x01));

                     body.emit(assign(r0548, r056E, 0x01));

                     body.emit(assign(r0549, r056D, 0x01));


                  body.instructions = f0561_parent_instructions;
                  body.emit(f0561);

                  /* END IF */

                  body.emit(assign(r0546, sub(r0546, r054A), 0x01));

                  ir_variable *const r0585 = body.make_temp(glsl_type::int_type, "zExp");
                  body.emit(assign(r0585, r0546, 0x01));

                  ir_variable *const r0586 = body.make_temp(glsl_type::uint_type, "zFrac0");
                  body.emit(assign(r0586, r0547, 0x01));

                  ir_variable *const r0587 = body.make_temp(glsl_type::uint_type, "zFrac1");
                  body.emit(assign(r0587, r0548, 0x01));

                  ir_variable *const r0588 = body.make_temp(glsl_type::uint_type, "zFrac2");
                  body.emit(assign(r0588, r0549, 0x01));

                  ir_variable *const r0589 = body.make_temp(glsl_type::bool_type, "execute_flag");
                  body.emit(assign(r0589, body.constant(true), 0x01));

                  ir_variable *const r058A = body.make_temp(glsl_type::uvec2_type, "return_value");
                  ir_variable *const r058B = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                  body.emit(r058B);
                  ir_expression *const r058C = expr(ir_unop_u2i, r0549);
                  body.emit(assign(r058B, less(r058C, body.constant(int(0))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r058E = lequal(body.constant(int(2045)), r0546);
                  ir_if *f058D = new(mem_ctx) ir_if(operand(r058E).val);
                  exec_list *const f058D_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f058D->then_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0590 = less(body.constant(int(2045)), r0546);
                     ir_expression *const r0591 = equal(r0546, body.constant(int(2045)));
                     ir_expression *const r0592 = equal(body.constant(2097151u), r0547);
                     ir_expression *const r0593 = equal(body.constant(4294967295u), r0548);
                     ir_expression *const r0594 = logic_and(r0592, r0593);
                     ir_expression *const r0595 = logic_and(r0591, r0594);
                     ir_expression *const r0596 = logic_and(r0595, r058B);
                     ir_expression *const r0597 = logic_or(r0590, r0596);
                     ir_if *f058F = new(mem_ctx) ir_if(operand(r0597).val);
                     exec_list *const f058F_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f058F->then_instructions;

                        ir_variable *const r0598 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0598);
                        ir_expression *const r0599 = lshift(r01E5, body.constant(int(31)));
                        body.emit(assign(r0598, add(r0599, body.constant(2146435072u)), 0x02));

                        body.emit(assign(r0598, body.constant(0u), 0x01));

                        body.emit(assign(r058A, r0598, 0x03));

                        body.emit(assign(r0589, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f058F->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r059B = less(r0546, body.constant(int(0)));
                        ir_if *f059A = new(mem_ctx) ir_if(operand(r059B).val);
                        exec_list *const f059A_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f059A->then_instructions;

                           ir_variable *const r059C = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r059C, r0549, 0x01));

                           ir_variable *const r059D = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r059D, neg(r0546), 0x01));

                           ir_variable *const r059E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r059E);
                           ir_variable *const r059F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r059F);
                           ir_variable *const r05A0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r05A0);
                           ir_variable *const r05A1 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r05A2 = neg(r059D);
                           body.emit(assign(r05A1, bit_and(r05A2, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r05A4 = equal(r059D, body.constant(int(0)));
                           ir_if *f05A3 = new(mem_ctx) ir_if(operand(r05A4).val);
                           exec_list *const f05A3_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f05A3->then_instructions;

                              body.emit(assign(r059E, r0549, 0x01));

                              body.emit(assign(r059F, r0548, 0x01));

                              body.emit(assign(r05A0, r0547, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f05A3->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r05A6 = less(r059D, body.constant(int(32)));
                              ir_if *f05A5 = new(mem_ctx) ir_if(operand(r05A6).val);
                              exec_list *const f05A5_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f05A5->then_instructions;

                                 body.emit(assign(r059E, lshift(r0548, r05A1), 0x01));

                                 ir_expression *const r05A7 = lshift(r0547, r05A1);
                                 ir_expression *const r05A8 = rshift(r0548, r059D);
                                 body.emit(assign(r059F, bit_or(r05A7, r05A8), 0x01));

                                 body.emit(assign(r05A0, rshift(r0547, r059D), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f05A5->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r05AA = equal(r059D, body.constant(int(32)));
                                 ir_if *f05A9 = new(mem_ctx) ir_if(operand(r05AA).val);
                                 exec_list *const f05A9_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f05A9->then_instructions;

                                    body.emit(assign(r059E, r0548, 0x01));

                                    body.emit(assign(r059F, r0547, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f05A9->else_instructions;

                                    body.emit(assign(r059C, bit_or(r0549, r0548), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r05AC = less(r059D, body.constant(int(64)));
                                    ir_if *f05AB = new(mem_ctx) ir_if(operand(r05AC).val);
                                    exec_list *const f05AB_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f05AB->then_instructions;

                                       body.emit(assign(r059E, lshift(r0547, r05A1), 0x01));

                                       ir_expression *const r05AD = bit_and(r059D, body.constant(int(31)));
                                       body.emit(assign(r059F, rshift(r0547, r05AD), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f05AB->else_instructions;

                                       ir_variable *const r05AE = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r05B0 = equal(r059D, body.constant(int(64)));
                                       ir_if *f05AF = new(mem_ctx) ir_if(operand(r05B0).val);
                                       exec_list *const f05AF_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f05AF->then_instructions;

                                          body.emit(assign(r05AE, r0547, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f05AF->else_instructions;

                                          ir_expression *const r05B1 = nequal(r0547, body.constant(0u));
                                          ir_expression *const r05B2 = expr(ir_unop_b2i, r05B1);
                                          body.emit(assign(r05AE, expr(ir_unop_i2u, r05B2), 0x01));


                                       body.instructions = f05AF_parent_instructions;
                                       body.emit(f05AF);

                                       /* END IF */

                                       body.emit(assign(r059E, r05AE, 0x01));

                                       body.emit(assign(r059F, body.constant(0u), 0x01));


                                    body.instructions = f05AB_parent_instructions;
                                    body.emit(f05AB);

                                    /* END IF */


                                 body.instructions = f05A9_parent_instructions;
                                 body.emit(f05A9);

                                 /* END IF */

                                 body.emit(assign(r05A0, body.constant(0u), 0x01));


                              body.instructions = f05A5_parent_instructions;
                              body.emit(f05A5);

                              /* END IF */

                              ir_expression *const r05B3 = nequal(r059C, body.constant(0u));
                              ir_expression *const r05B4 = expr(ir_unop_b2i, r05B3);
                              ir_expression *const r05B5 = expr(ir_unop_i2u, r05B4);
                              body.emit(assign(r059E, bit_or(r059E, r05B5), 0x01));


                           body.instructions = f05A3_parent_instructions;
                           body.emit(f05A3);

                           /* END IF */

                           body.emit(assign(r0586, r05A0, 0x01));

                           body.emit(assign(r0587, r059F, 0x01));

                           body.emit(assign(r0588, r059E, 0x01));

                           body.emit(assign(r0585, body.constant(int(0)), 0x01));

                           body.emit(assign(r058B, less(r059E, body.constant(0u)), 0x01));


                        body.instructions = f059A_parent_instructions;
                        body.emit(f059A);

                        /* END IF */


                     body.instructions = f058F_parent_instructions;
                     body.emit(f058F);

                     /* END IF */


                  body.instructions = f058D_parent_instructions;
                  body.emit(f058D);

                  /* END IF */

                  /* IF CONDITION */
                  ir_if *f05B6 = new(mem_ctx) ir_if(operand(r0589).val);
                  exec_list *const f05B6_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05B6->then_instructions;

                     /* IF CONDITION */
                     ir_if *f05B7 = new(mem_ctx) ir_if(operand(r058B).val);
                     exec_list *const f05B7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05B7->then_instructions;

                        ir_variable *const r05B8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                        body.emit(assign(r05B8, add(r0587, body.constant(1u)), 0x01));

                        ir_expression *const r05B9 = less(r05B8, r0587);
                        ir_expression *const r05BA = expr(ir_unop_b2i, r05B9);
                        ir_expression *const r05BB = expr(ir_unop_i2u, r05BA);
                        body.emit(assign(r0586, add(r0586, r05BB), 0x01));

                        ir_expression *const r05BC = equal(r0588, body.constant(0u));
                        ir_expression *const r05BD = expr(ir_unop_b2i, r05BC);
                        ir_expression *const r05BE = expr(ir_unop_i2u, r05BD);
                        ir_expression *const r05BF = add(r0588, r05BE);
                        ir_expression *const r05C0 = bit_and(r05BF, body.constant(1u));
                        ir_expression *const r05C1 = expr(ir_unop_bit_not, r05C0);
                        body.emit(assign(r0587, bit_and(r05B8, r05C1), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05B7->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r05C3 = bit_or(r0586, r0587);
                        ir_expression *const r05C4 = equal(r05C3, body.constant(0u));
                        ir_if *f05C2 = new(mem_ctx) ir_if(operand(r05C4).val);
                        exec_list *const f05C2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05C2->then_instructions;

                           body.emit(assign(r0585, body.constant(int(0)), 0x01));


                        body.instructions = f05C2_parent_instructions;
                        body.emit(f05C2);

                        /* END IF */


                     body.instructions = f05B7_parent_instructions;
                     body.emit(f05B7);

                     /* END IF */

                     ir_variable *const r05C5 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r05C5);
                     ir_expression *const r05C6 = lshift(r01E5, body.constant(int(31)));
                     ir_expression *const r05C7 = expr(ir_unop_i2u, r0585);
                     ir_expression *const r05C8 = lshift(r05C7, body.constant(int(20)));
                     ir_expression *const r05C9 = add(r05C6, r05C8);
                     body.emit(assign(r05C5, add(r05C9, r0586), 0x02));

                     body.emit(assign(r05C5, r0587, 0x01));

                     body.emit(assign(r058A, r05C5, 0x03));

                     body.emit(assign(r0589, body.constant(false), 0x01));


                  body.instructions = f05B6_parent_instructions;
                  body.emit(f05B6);

                  /* END IF */

                  body.emit(assign(r01E4, r058A, 0x03));

                  body.emit(assign(r01E3, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f053E->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r05CB = less(r037B, r0379);
                  ir_if *f05CA = new(mem_ctx) ir_if(operand(r05CB).val);
                  exec_list *const f05CA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f05CA->then_instructions;

                     ir_variable *const r05CC = body.make_temp(glsl_type::uint_type, "z0Ptr");
                     ir_variable *const r05CD = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r05CD, sub(r037A, r037C), 0x01));

                     ir_expression *const r05CE = sub(r0379, r037B);
                     ir_expression *const r05CF = less(r037A, r037C);
                     ir_expression *const r05D0 = expr(ir_unop_b2i, r05CF);
                     ir_expression *const r05D1 = expr(ir_unop_i2u, r05D0);
                     body.emit(assign(r05CC, sub(r05CE, r05D1), 0x01));

                     body.emit(assign(r01E5, bit_xor(r01E5, body.constant(1u)), 0x01));

                     body.emit(assign(r037D, add(r0377, body.constant(int(-1))), 0x01));

                     ir_variable *const r05D2 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r05D2, add(r037D, body.constant(int(-10))), 0x01));

                     ir_variable *const r05D3 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r05D3, r05CC, 0x01));

                     ir_variable *const r05D4 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r05D4, r05CD, 0x01));

                     ir_variable *const r05D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                     body.emit(r05D5);
                     ir_variable *const r05D6 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05D6);
                     /* IF CONDITION */
                     ir_expression *const r05D8 = equal(r05CC, body.constant(0u));
                     ir_if *f05D7 = new(mem_ctx) ir_if(operand(r05D8).val);
                     exec_list *const f05D7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05D7->then_instructions;

                        body.emit(assign(r05D3, r05CD, 0x01));

                        body.emit(assign(r05D4, body.constant(0u), 0x01));

                        body.emit(assign(r05D2, add(r05D2, body.constant(int(-32))), 0x01));


                     body.instructions = f05D7_parent_instructions;
                     body.emit(f05D7);

                     /* END IF */

                     ir_variable *const r05D9 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r05D9, r05D3, 0x01));

                     ir_variable *const r05DA = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r05DB = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r05DB);
                     /* IF CONDITION */
                     ir_expression *const r05DD = equal(r05D3, body.constant(0u));
                     ir_if *f05DC = new(mem_ctx) ir_if(operand(r05DD).val);
                     exec_list *const f05DC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05DC->then_instructions;

                        body.emit(assign(r05DA, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05DC->else_instructions;

                        body.emit(assign(r05DB, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05DF = bit_and(r05D3, body.constant(4294901760u));
                        ir_expression *const r05E0 = equal(r05DF, body.constant(0u));
                        ir_if *f05DE = new(mem_ctx) ir_if(operand(r05E0).val);
                        exec_list *const f05DE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05DE->then_instructions;

                           body.emit(assign(r05DB, body.constant(int(16)), 0x01));

                           body.emit(assign(r05D9, lshift(r05D3, body.constant(int(16))), 0x01));


                        body.instructions = f05DE_parent_instructions;
                        body.emit(f05DE);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05E2 = bit_and(r05D9, body.constant(4278190080u));
                        ir_expression *const r05E3 = equal(r05E2, body.constant(0u));
                        ir_if *f05E1 = new(mem_ctx) ir_if(operand(r05E3).val);
                        exec_list *const f05E1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E1->then_instructions;

                           body.emit(assign(r05DB, add(r05DB, body.constant(int(8))), 0x01));

                           body.emit(assign(r05D9, lshift(r05D9, body.constant(int(8))), 0x01));


                        body.instructions = f05E1_parent_instructions;
                        body.emit(f05E1);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05E5 = bit_and(r05D9, body.constant(4026531840u));
                        ir_expression *const r05E6 = equal(r05E5, body.constant(0u));
                        ir_if *f05E4 = new(mem_ctx) ir_if(operand(r05E6).val);
                        exec_list *const f05E4_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E4->then_instructions;

                           body.emit(assign(r05DB, add(r05DB, body.constant(int(4))), 0x01));

                           body.emit(assign(r05D9, lshift(r05D9, body.constant(int(4))), 0x01));


                        body.instructions = f05E4_parent_instructions;
                        body.emit(f05E4);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05E8 = bit_and(r05D9, body.constant(3221225472u));
                        ir_expression *const r05E9 = equal(r05E8, body.constant(0u));
                        ir_if *f05E7 = new(mem_ctx) ir_if(operand(r05E9).val);
                        exec_list *const f05E7_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05E7->then_instructions;

                           body.emit(assign(r05DB, add(r05DB, body.constant(int(2))), 0x01));

                           body.emit(assign(r05D9, lshift(r05D9, body.constant(int(2))), 0x01));


                        body.instructions = f05E7_parent_instructions;
                        body.emit(f05E7);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r05EB = bit_and(r05D9, body.constant(2147483648u));
                        ir_expression *const r05EC = equal(r05EB, body.constant(0u));
                        ir_if *f05EA = new(mem_ctx) ir_if(operand(r05EC).val);
                        exec_list *const f05EA_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05EA->then_instructions;

                           body.emit(assign(r05DB, add(r05DB, body.constant(int(1))), 0x01));


                        body.instructions = f05EA_parent_instructions;
                        body.emit(f05EA);

                        /* END IF */

                        body.emit(assign(r05DA, r05DB, 0x01));


                     body.instructions = f05DC_parent_instructions;
                     body.emit(f05DC);

                     /* END IF */

                     body.emit(assign(r05D6, add(r05DA, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r05EE = lequal(body.constant(int(0)), r05D6);
                     ir_if *f05ED = new(mem_ctx) ir_if(operand(r05EE).val);
                     exec_list *const f05ED_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f05ED->then_instructions;

                        body.emit(assign(r05D5, body.constant(0u), 0x01));

                        ir_variable *const r05EF = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r05EF, lshift(r05D4, r05D6), 0x01));

                        ir_variable *const r05F0 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                        /* IF CONDITION */
                        ir_expression *const r05F2 = equal(r05D6, body.constant(int(0)));
                        ir_if *f05F1 = new(mem_ctx) ir_if(operand(r05F2).val);
                        exec_list *const f05F1_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05F1->then_instructions;

                           body.emit(assign(r05F0, r05D3, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05F1->else_instructions;

                           ir_expression *const r05F3 = lshift(r05D3, r05D6);
                           ir_expression *const r05F4 = neg(r05D6);
                           ir_expression *const r05F5 = bit_and(r05F4, body.constant(int(31)));
                           ir_expression *const r05F6 = rshift(r05D4, r05F5);
                           body.emit(assign(r05F0, bit_or(r05F3, r05F6), 0x01));


                        body.instructions = f05F1_parent_instructions;
                        body.emit(f05F1);

                        /* END IF */

                        body.emit(assign(r05D3, r05F0, 0x01));

                        body.emit(assign(r05D4, r05EF, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f05ED->else_instructions;

                        ir_variable *const r05F7 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r05F7, body.constant(0u), 0x01));

                        ir_variable *const r05F8 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r05F8, neg(r05D6), 0x01));

                        ir_variable *const r05F9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r05F9);
                        ir_variable *const r05FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r05FA);
                        ir_variable *const r05FB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r05FB);
                        ir_variable *const r05FC = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r05FD = neg(r05F8);
                        body.emit(assign(r05FC, bit_and(r05FD, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r05FF = equal(r05F8, body.constant(int(0)));
                        ir_if *f05FE = new(mem_ctx) ir_if(operand(r05FF).val);
                        exec_list *const f05FE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f05FE->then_instructions;

                           body.emit(assign(r05F9, r05F7, 0x01));

                           body.emit(assign(r05FA, r05D4, 0x01));

                           body.emit(assign(r05FB, r05D3, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f05FE->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0601 = less(r05F8, body.constant(int(32)));
                           ir_if *f0600 = new(mem_ctx) ir_if(operand(r0601).val);
                           exec_list *const f0600_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0600->then_instructions;

                              body.emit(assign(r05F9, lshift(r05D4, r05FC), 0x01));

                              ir_expression *const r0602 = lshift(r05D3, r05FC);
                              ir_expression *const r0603 = rshift(r05D4, r05F8);
                              body.emit(assign(r05FA, bit_or(r0602, r0603), 0x01));

                              body.emit(assign(r05FB, rshift(r05D3, r05F8), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0600->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0605 = equal(r05F8, body.constant(int(32)));
                              ir_if *f0604 = new(mem_ctx) ir_if(operand(r0605).val);
                              exec_list *const f0604_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0604->then_instructions;

                                 body.emit(assign(r05F9, r05D4, 0x01));

                                 body.emit(assign(r05FA, r05D3, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0604->else_instructions;

                                 body.emit(assign(r05F7, bit_or(body.constant(0u), r05D4), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r0607 = less(r05F8, body.constant(int(64)));
                                 ir_if *f0606 = new(mem_ctx) ir_if(operand(r0607).val);
                                 exec_list *const f0606_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0606->then_instructions;

                                    body.emit(assign(r05F9, lshift(r05D3, r05FC), 0x01));

                                    ir_expression *const r0608 = bit_and(r05F8, body.constant(int(31)));
                                    body.emit(assign(r05FA, rshift(r05D3, r0608), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0606->else_instructions;

                                    ir_variable *const r0609 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r060B = equal(r05F8, body.constant(int(64)));
                                    ir_if *f060A = new(mem_ctx) ir_if(operand(r060B).val);
                                    exec_list *const f060A_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f060A->then_instructions;

                                       body.emit(assign(r0609, r05D3, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f060A->else_instructions;

                                       ir_expression *const r060C = nequal(r05D3, body.constant(0u));
                                       ir_expression *const r060D = expr(ir_unop_b2i, r060C);
                                       body.emit(assign(r0609, expr(ir_unop_i2u, r060D), 0x01));


                                    body.instructions = f060A_parent_instructions;
                                    body.emit(f060A);

                                    /* END IF */

                                    body.emit(assign(r05F9, r0609, 0x01));

                                    body.emit(assign(r05FA, body.constant(0u), 0x01));


                                 body.instructions = f0606_parent_instructions;
                                 body.emit(f0606);

                                 /* END IF */


                              body.instructions = f0604_parent_instructions;
                              body.emit(f0604);

                              /* END IF */

                              body.emit(assign(r05FB, body.constant(0u), 0x01));


                           body.instructions = f0600_parent_instructions;
                           body.emit(f0600);

                           /* END IF */

                           ir_expression *const r060E = nequal(r05F7, body.constant(0u));
                           ir_expression *const r060F = expr(ir_unop_b2i, r060E);
                           ir_expression *const r0610 = expr(ir_unop_i2u, r060F);
                           body.emit(assign(r05F9, bit_or(r05F9, r0610), 0x01));


                        body.instructions = f05FE_parent_instructions;
                        body.emit(f05FE);

                        /* END IF */

                        body.emit(assign(r05D3, r05FB, 0x01));

                        body.emit(assign(r05D4, r05FA, 0x01));

                        body.emit(assign(r05D5, r05F9, 0x01));


                     body.instructions = f05ED_parent_instructions;
                     body.emit(f05ED);

                     /* END IF */

                     body.emit(assign(r05D2, sub(r05D2, r05D6), 0x01));

                     ir_variable *const r0611 = body.make_temp(glsl_type::int_type, "zExp");
                     body.emit(assign(r0611, r05D2, 0x01));

                     ir_variable *const r0612 = body.make_temp(glsl_type::uint_type, "zFrac0");
                     body.emit(assign(r0612, r05D3, 0x01));

                     ir_variable *const r0613 = body.make_temp(glsl_type::uint_type, "zFrac1");
                     body.emit(assign(r0613, r05D4, 0x01));

                     ir_variable *const r0614 = body.make_temp(glsl_type::uint_type, "zFrac2");
                     body.emit(assign(r0614, r05D5, 0x01));

                     ir_variable *const r0615 = body.make_temp(glsl_type::bool_type, "execute_flag");
                     body.emit(assign(r0615, body.constant(true), 0x01));

                     ir_variable *const r0616 = body.make_temp(glsl_type::uvec2_type, "return_value");
                     ir_variable *const r0617 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                     body.emit(r0617);
                     ir_expression *const r0618 = expr(ir_unop_u2i, r05D5);
                     body.emit(assign(r0617, less(r0618, body.constant(int(0))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r061A = lequal(body.constant(int(2045)), r05D2);
                     ir_if *f0619 = new(mem_ctx) ir_if(operand(r061A).val);
                     exec_list *const f0619_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0619->then_instructions;

                        /* IF CONDITION */
                        ir_expression *const r061C = less(body.constant(int(2045)), r05D2);
                        ir_expression *const r061D = equal(r05D2, body.constant(int(2045)));
                        ir_expression *const r061E = equal(body.constant(2097151u), r05D3);
                        ir_expression *const r061F = equal(body.constant(4294967295u), r05D4);
                        ir_expression *const r0620 = logic_and(r061E, r061F);
                        ir_expression *const r0621 = logic_and(r061D, r0620);
                        ir_expression *const r0622 = logic_and(r0621, r0617);
                        ir_expression *const r0623 = logic_or(r061C, r0622);
                        ir_if *f061B = new(mem_ctx) ir_if(operand(r0623).val);
                        exec_list *const f061B_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f061B->then_instructions;

                           ir_variable *const r0624 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r0624);
                           ir_expression *const r0625 = lshift(r01E5, body.constant(int(31)));
                           body.emit(assign(r0624, add(r0625, body.constant(2146435072u)), 0x02));

                           body.emit(assign(r0624, body.constant(0u), 0x01));

                           body.emit(assign(r0616, r0624, 0x03));

                           body.emit(assign(r0615, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f061B->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r0627 = less(r05D2, body.constant(int(0)));
                           ir_if *f0626 = new(mem_ctx) ir_if(operand(r0627).val);
                           exec_list *const f0626_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0626->then_instructions;

                              ir_variable *const r0628 = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r0628, r05D5, 0x01));

                              ir_variable *const r0629 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0629, neg(r05D2), 0x01));

                              ir_variable *const r062A = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r062A);
                              ir_variable *const r062B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r062B);
                              ir_variable *const r062C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r062C);
                              ir_variable *const r062D = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r062E = neg(r0629);
                              body.emit(assign(r062D, bit_and(r062E, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0630 = equal(r0629, body.constant(int(0)));
                              ir_if *f062F = new(mem_ctx) ir_if(operand(r0630).val);
                              exec_list *const f062F_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f062F->then_instructions;

                                 body.emit(assign(r062A, r05D5, 0x01));

                                 body.emit(assign(r062B, r05D4, 0x01));

                                 body.emit(assign(r062C, r05D3, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f062F->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0632 = less(r0629, body.constant(int(32)));
                                 ir_if *f0631 = new(mem_ctx) ir_if(operand(r0632).val);
                                 exec_list *const f0631_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0631->then_instructions;

                                    body.emit(assign(r062A, lshift(r05D4, r062D), 0x01));

                                    ir_expression *const r0633 = lshift(r05D3, r062D);
                                    ir_expression *const r0634 = rshift(r05D4, r0629);
                                    body.emit(assign(r062B, bit_or(r0633, r0634), 0x01));

                                    body.emit(assign(r062C, rshift(r05D3, r0629), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0631->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r0636 = equal(r0629, body.constant(int(32)));
                                    ir_if *f0635 = new(mem_ctx) ir_if(operand(r0636).val);
                                    exec_list *const f0635_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0635->then_instructions;

                                       body.emit(assign(r062A, r05D4, 0x01));

                                       body.emit(assign(r062B, r05D3, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0635->else_instructions;

                                       body.emit(assign(r0628, bit_or(r05D5, r05D4), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r0638 = less(r0629, body.constant(int(64)));
                                       ir_if *f0637 = new(mem_ctx) ir_if(operand(r0638).val);
                                       exec_list *const f0637_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0637->then_instructions;

                                          body.emit(assign(r062A, lshift(r05D3, r062D), 0x01));

                                          ir_expression *const r0639 = bit_and(r0629, body.constant(int(31)));
                                          body.emit(assign(r062B, rshift(r05D3, r0639), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0637->else_instructions;

                                          ir_variable *const r063A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r063C = equal(r0629, body.constant(int(64)));
                                          ir_if *f063B = new(mem_ctx) ir_if(operand(r063C).val);
                                          exec_list *const f063B_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f063B->then_instructions;

                                             body.emit(assign(r063A, r05D3, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f063B->else_instructions;

                                             ir_expression *const r063D = nequal(r05D3, body.constant(0u));
                                             ir_expression *const r063E = expr(ir_unop_b2i, r063D);
                                             body.emit(assign(r063A, expr(ir_unop_i2u, r063E), 0x01));


                                          body.instructions = f063B_parent_instructions;
                                          body.emit(f063B);

                                          /* END IF */

                                          body.emit(assign(r062A, r063A, 0x01));

                                          body.emit(assign(r062B, body.constant(0u), 0x01));


                                       body.instructions = f0637_parent_instructions;
                                       body.emit(f0637);

                                       /* END IF */


                                    body.instructions = f0635_parent_instructions;
                                    body.emit(f0635);

                                    /* END IF */

                                    body.emit(assign(r062C, body.constant(0u), 0x01));


                                 body.instructions = f0631_parent_instructions;
                                 body.emit(f0631);

                                 /* END IF */

                                 ir_expression *const r063F = nequal(r0628, body.constant(0u));
                                 ir_expression *const r0640 = expr(ir_unop_b2i, r063F);
                                 ir_expression *const r0641 = expr(ir_unop_i2u, r0640);
                                 body.emit(assign(r062A, bit_or(r062A, r0641), 0x01));


                              body.instructions = f062F_parent_instructions;
                              body.emit(f062F);

                              /* END IF */

                              body.emit(assign(r0612, r062C, 0x01));

                              body.emit(assign(r0613, r062B, 0x01));

                              body.emit(assign(r0614, r062A, 0x01));

                              body.emit(assign(r0611, body.constant(int(0)), 0x01));

                              body.emit(assign(r0617, less(r062A, body.constant(0u)), 0x01));


                           body.instructions = f0626_parent_instructions;
                           body.emit(f0626);

                           /* END IF */


                        body.instructions = f061B_parent_instructions;
                        body.emit(f061B);

                        /* END IF */


                     body.instructions = f0619_parent_instructions;
                     body.emit(f0619);

                     /* END IF */

                     /* IF CONDITION */
                     ir_if *f0642 = new(mem_ctx) ir_if(operand(r0615).val);
                     exec_list *const f0642_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0642->then_instructions;

                        /* IF CONDITION */
                        ir_if *f0643 = new(mem_ctx) ir_if(operand(r0617).val);
                        exec_list *const f0643_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0643->then_instructions;

                           ir_variable *const r0644 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                           body.emit(assign(r0644, add(r0613, body.constant(1u)), 0x01));

                           ir_expression *const r0645 = less(r0644, r0613);
                           ir_expression *const r0646 = expr(ir_unop_b2i, r0645);
                           ir_expression *const r0647 = expr(ir_unop_i2u, r0646);
                           body.emit(assign(r0612, add(r0612, r0647), 0x01));

                           ir_expression *const r0648 = equal(r0614, body.constant(0u));
                           ir_expression *const r0649 = expr(ir_unop_b2i, r0648);
                           ir_expression *const r064A = expr(ir_unop_i2u, r0649);
                           ir_expression *const r064B = add(r0614, r064A);
                           ir_expression *const r064C = bit_and(r064B, body.constant(1u));
                           ir_expression *const r064D = expr(ir_unop_bit_not, r064C);
                           body.emit(assign(r0613, bit_and(r0644, r064D), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0643->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r064F = bit_or(r0612, r0613);
                           ir_expression *const r0650 = equal(r064F, body.constant(0u));
                           ir_if *f064E = new(mem_ctx) ir_if(operand(r0650).val);
                           exec_list *const f064E_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f064E->then_instructions;

                              body.emit(assign(r0611, body.constant(int(0)), 0x01));


                           body.instructions = f064E_parent_instructions;
                           body.emit(f064E);

                           /* END IF */


                        body.instructions = f0643_parent_instructions;
                        body.emit(f0643);

                        /* END IF */

                        ir_variable *const r0651 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                        body.emit(r0651);
                        ir_expression *const r0652 = lshift(r01E5, body.constant(int(31)));
                        ir_expression *const r0653 = expr(ir_unop_i2u, r0611);
                        ir_expression *const r0654 = lshift(r0653, body.constant(int(20)));
                        ir_expression *const r0655 = add(r0652, r0654);
                        body.emit(assign(r0651, add(r0655, r0612), 0x02));

                        body.emit(assign(r0651, r0613, 0x01));

                        body.emit(assign(r0616, r0651, 0x03));

                        body.emit(assign(r0615, body.constant(false), 0x01));


                     body.instructions = f0642_parent_instructions;
                     body.emit(f0642);

                     /* END IF */

                     body.emit(assign(r01E4, r0616, 0x03));

                     body.emit(assign(r01E3, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f05CA->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0657 = less(r037A, r037C);
                     ir_if *f0656 = new(mem_ctx) ir_if(operand(r0657).val);
                     exec_list *const f0656_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0656->then_instructions;

                        ir_variable *const r0658 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                        ir_variable *const r0659 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                        body.emit(assign(r0659, sub(r037C, r037A), 0x01));

                        ir_expression *const r065A = sub(r037B, r0379);
                        ir_expression *const r065B = less(r037C, r037A);
                        ir_expression *const r065C = expr(ir_unop_b2i, r065B);
                        ir_expression *const r065D = expr(ir_unop_i2u, r065C);
                        body.emit(assign(r0658, sub(r065A, r065D), 0x01));

                        body.emit(assign(r037D, add(r0378, body.constant(int(-1))), 0x01));

                        ir_variable *const r065E = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r065E, add(r037D, body.constant(int(-10))), 0x01));

                        ir_variable *const r065F = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r065F, r0658, 0x01));

                        ir_variable *const r0660 = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r0660, r0659, 0x01));

                        ir_variable *const r0661 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                        body.emit(r0661);
                        ir_variable *const r0662 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0662);
                        /* IF CONDITION */
                        ir_expression *const r0664 = equal(r0658, body.constant(0u));
                        ir_if *f0663 = new(mem_ctx) ir_if(operand(r0664).val);
                        exec_list *const f0663_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0663->then_instructions;

                           body.emit(assign(r065F, r0659, 0x01));

                           body.emit(assign(r0660, body.constant(0u), 0x01));

                           body.emit(assign(r065E, add(r065E, body.constant(int(-32))), 0x01));


                        body.instructions = f0663_parent_instructions;
                        body.emit(f0663);

                        /* END IF */

                        ir_variable *const r0665 = body.make_temp(glsl_type::uint_type, "a");
                        body.emit(assign(r0665, r065F, 0x01));

                        ir_variable *const r0666 = body.make_temp(glsl_type::int_type, "return_value");
                        ir_variable *const r0667 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                        body.emit(r0667);
                        /* IF CONDITION */
                        ir_expression *const r0669 = equal(r065F, body.constant(0u));
                        ir_if *f0668 = new(mem_ctx) ir_if(operand(r0669).val);
                        exec_list *const f0668_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0668->then_instructions;

                           body.emit(assign(r0666, body.constant(int(32)), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0668->else_instructions;

                           body.emit(assign(r0667, body.constant(int(0)), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r066B = bit_and(r065F, body.constant(4294901760u));
                           ir_expression *const r066C = equal(r066B, body.constant(0u));
                           ir_if *f066A = new(mem_ctx) ir_if(operand(r066C).val);
                           exec_list *const f066A_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f066A->then_instructions;

                              body.emit(assign(r0667, body.constant(int(16)), 0x01));

                              body.emit(assign(r0665, lshift(r065F, body.constant(int(16))), 0x01));


                           body.instructions = f066A_parent_instructions;
                           body.emit(f066A);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r066E = bit_and(r0665, body.constant(4278190080u));
                           ir_expression *const r066F = equal(r066E, body.constant(0u));
                           ir_if *f066D = new(mem_ctx) ir_if(operand(r066F).val);
                           exec_list *const f066D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f066D->then_instructions;

                              body.emit(assign(r0667, add(r0667, body.constant(int(8))), 0x01));

                              body.emit(assign(r0665, lshift(r0665, body.constant(int(8))), 0x01));


                           body.instructions = f066D_parent_instructions;
                           body.emit(f066D);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0671 = bit_and(r0665, body.constant(4026531840u));
                           ir_expression *const r0672 = equal(r0671, body.constant(0u));
                           ir_if *f0670 = new(mem_ctx) ir_if(operand(r0672).val);
                           exec_list *const f0670_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0670->then_instructions;

                              body.emit(assign(r0667, add(r0667, body.constant(int(4))), 0x01));

                              body.emit(assign(r0665, lshift(r0665, body.constant(int(4))), 0x01));


                           body.instructions = f0670_parent_instructions;
                           body.emit(f0670);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0674 = bit_and(r0665, body.constant(3221225472u));
                           ir_expression *const r0675 = equal(r0674, body.constant(0u));
                           ir_if *f0673 = new(mem_ctx) ir_if(operand(r0675).val);
                           exec_list *const f0673_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0673->then_instructions;

                              body.emit(assign(r0667, add(r0667, body.constant(int(2))), 0x01));

                              body.emit(assign(r0665, lshift(r0665, body.constant(int(2))), 0x01));


                           body.instructions = f0673_parent_instructions;
                           body.emit(f0673);

                           /* END IF */

                           /* IF CONDITION */
                           ir_expression *const r0677 = bit_and(r0665, body.constant(2147483648u));
                           ir_expression *const r0678 = equal(r0677, body.constant(0u));
                           ir_if *f0676 = new(mem_ctx) ir_if(operand(r0678).val);
                           exec_list *const f0676_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0676->then_instructions;

                              body.emit(assign(r0667, add(r0667, body.constant(int(1))), 0x01));


                           body.instructions = f0676_parent_instructions;
                           body.emit(f0676);

                           /* END IF */

                           body.emit(assign(r0666, r0667, 0x01));


                        body.instructions = f0668_parent_instructions;
                        body.emit(f0668);

                        /* END IF */

                        body.emit(assign(r0662, add(r0666, body.constant(int(-11))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r067A = lequal(body.constant(int(0)), r0662);
                        ir_if *f0679 = new(mem_ctx) ir_if(operand(r067A).val);
                        exec_list *const f0679_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0679->then_instructions;

                           body.emit(assign(r0661, body.constant(0u), 0x01));

                           ir_variable *const r067B = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r067B, lshift(r0660, r0662), 0x01));

                           ir_variable *const r067C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                           /* IF CONDITION */
                           ir_expression *const r067E = equal(r0662, body.constant(int(0)));
                           ir_if *f067D = new(mem_ctx) ir_if(operand(r067E).val);
                           exec_list *const f067D_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f067D->then_instructions;

                              body.emit(assign(r067C, r065F, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f067D->else_instructions;

                              ir_expression *const r067F = lshift(r065F, r0662);
                              ir_expression *const r0680 = neg(r0662);
                              ir_expression *const r0681 = bit_and(r0680, body.constant(int(31)));
                              ir_expression *const r0682 = rshift(r0660, r0681);
                              body.emit(assign(r067C, bit_or(r067F, r0682), 0x01));


                           body.instructions = f067D_parent_instructions;
                           body.emit(f067D);

                           /* END IF */

                           body.emit(assign(r065F, r067C, 0x01));

                           body.emit(assign(r0660, r067B, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f0679->else_instructions;

                           ir_variable *const r0683 = body.make_temp(glsl_type::uint_type, "a2");
                           body.emit(assign(r0683, body.constant(0u), 0x01));

                           ir_variable *const r0684 = body.make_temp(glsl_type::int_type, "count");
                           body.emit(assign(r0684, neg(r0662), 0x01));

                           ir_variable *const r0685 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                           body.emit(r0685);
                           ir_variable *const r0686 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                           body.emit(r0686);
                           ir_variable *const r0687 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                           body.emit(r0687);
                           ir_variable *const r0688 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                           ir_expression *const r0689 = neg(r0684);
                           body.emit(assign(r0688, bit_and(r0689, body.constant(int(31))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r068B = equal(r0684, body.constant(int(0)));
                           ir_if *f068A = new(mem_ctx) ir_if(operand(r068B).val);
                           exec_list *const f068A_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f068A->then_instructions;

                              body.emit(assign(r0685, r0683, 0x01));

                              body.emit(assign(r0686, r0660, 0x01));

                              body.emit(assign(r0687, r065F, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f068A->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r068D = less(r0684, body.constant(int(32)));
                              ir_if *f068C = new(mem_ctx) ir_if(operand(r068D).val);
                              exec_list *const f068C_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f068C->then_instructions;

                                 body.emit(assign(r0685, lshift(r0660, r0688), 0x01));

                                 ir_expression *const r068E = lshift(r065F, r0688);
                                 ir_expression *const r068F = rshift(r0660, r0684);
                                 body.emit(assign(r0686, bit_or(r068E, r068F), 0x01));

                                 body.emit(assign(r0687, rshift(r065F, r0684), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f068C->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0691 = equal(r0684, body.constant(int(32)));
                                 ir_if *f0690 = new(mem_ctx) ir_if(operand(r0691).val);
                                 exec_list *const f0690_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0690->then_instructions;

                                    body.emit(assign(r0685, r0660, 0x01));

                                    body.emit(assign(r0686, r065F, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0690->else_instructions;

                                    body.emit(assign(r0683, bit_or(body.constant(0u), r0660), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0693 = less(r0684, body.constant(int(64)));
                                    ir_if *f0692 = new(mem_ctx) ir_if(operand(r0693).val);
                                    exec_list *const f0692_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0692->then_instructions;

                                       body.emit(assign(r0685, lshift(r065F, r0688), 0x01));

                                       ir_expression *const r0694 = bit_and(r0684, body.constant(int(31)));
                                       body.emit(assign(r0686, rshift(r065F, r0694), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0692->else_instructions;

                                       ir_variable *const r0695 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                       /* IF CONDITION */
                                       ir_expression *const r0697 = equal(r0684, body.constant(int(64)));
                                       ir_if *f0696 = new(mem_ctx) ir_if(operand(r0697).val);
                                       exec_list *const f0696_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0696->then_instructions;

                                          body.emit(assign(r0695, r065F, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0696->else_instructions;

                                          ir_expression *const r0698 = nequal(r065F, body.constant(0u));
                                          ir_expression *const r0699 = expr(ir_unop_b2i, r0698);
                                          body.emit(assign(r0695, expr(ir_unop_i2u, r0699), 0x01));


                                       body.instructions = f0696_parent_instructions;
                                       body.emit(f0696);

                                       /* END IF */

                                       body.emit(assign(r0685, r0695, 0x01));

                                       body.emit(assign(r0686, body.constant(0u), 0x01));


                                    body.instructions = f0692_parent_instructions;
                                    body.emit(f0692);

                                    /* END IF */


                                 body.instructions = f0690_parent_instructions;
                                 body.emit(f0690);

                                 /* END IF */

                                 body.emit(assign(r0687, body.constant(0u), 0x01));


                              body.instructions = f068C_parent_instructions;
                              body.emit(f068C);

                              /* END IF */

                              ir_expression *const r069A = nequal(r0683, body.constant(0u));
                              ir_expression *const r069B = expr(ir_unop_b2i, r069A);
                              ir_expression *const r069C = expr(ir_unop_i2u, r069B);
                              body.emit(assign(r0685, bit_or(r0685, r069C), 0x01));


                           body.instructions = f068A_parent_instructions;
                           body.emit(f068A);

                           /* END IF */

                           body.emit(assign(r065F, r0687, 0x01));

                           body.emit(assign(r0660, r0686, 0x01));

                           body.emit(assign(r0661, r0685, 0x01));


                        body.instructions = f0679_parent_instructions;
                        body.emit(f0679);

                        /* END IF */

                        body.emit(assign(r065E, sub(r065E, r0662), 0x01));

                        ir_variable *const r069D = body.make_temp(glsl_type::int_type, "zExp");
                        body.emit(assign(r069D, r065E, 0x01));

                        ir_variable *const r069E = body.make_temp(glsl_type::uint_type, "zFrac0");
                        body.emit(assign(r069E, r065F, 0x01));

                        ir_variable *const r069F = body.make_temp(glsl_type::uint_type, "zFrac1");
                        body.emit(assign(r069F, r0660, 0x01));

                        ir_variable *const r06A0 = body.make_temp(glsl_type::uint_type, "zFrac2");
                        body.emit(assign(r06A0, r0661, 0x01));

                        ir_variable *const r06A1 = body.make_temp(glsl_type::bool_type, "execute_flag");
                        body.emit(assign(r06A1, body.constant(true), 0x01));

                        ir_variable *const r06A2 = body.make_temp(glsl_type::uvec2_type, "return_value");
                        ir_variable *const r06A3 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                        body.emit(r06A3);
                        ir_expression *const r06A4 = expr(ir_unop_u2i, r0661);
                        body.emit(assign(r06A3, less(r06A4, body.constant(int(0))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r06A6 = lequal(body.constant(int(2045)), r065E);
                        ir_if *f06A5 = new(mem_ctx) ir_if(operand(r06A6).val);
                        exec_list *const f06A5_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06A5->then_instructions;

                           /* IF CONDITION */
                           ir_expression *const r06A8 = less(body.constant(int(2045)), r065E);
                           ir_expression *const r06A9 = equal(r065E, body.constant(int(2045)));
                           ir_expression *const r06AA = equal(body.constant(2097151u), r065F);
                           ir_expression *const r06AB = equal(body.constant(4294967295u), r0660);
                           ir_expression *const r06AC = logic_and(r06AA, r06AB);
                           ir_expression *const r06AD = logic_and(r06A9, r06AC);
                           ir_expression *const r06AE = logic_and(r06AD, r06A3);
                           ir_expression *const r06AF = logic_or(r06A8, r06AE);
                           ir_if *f06A7 = new(mem_ctx) ir_if(operand(r06AF).val);
                           exec_list *const f06A7_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06A7->then_instructions;

                              ir_variable *const r06B0 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r06B0);
                              ir_expression *const r06B1 = lshift(r01E5, body.constant(int(31)));
                              body.emit(assign(r06B0, add(r06B1, body.constant(2146435072u)), 0x02));

                              body.emit(assign(r06B0, body.constant(0u), 0x01));

                              body.emit(assign(r06A2, r06B0, 0x03));

                              body.emit(assign(r06A1, body.constant(false), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06A7->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06B3 = less(r065E, body.constant(int(0)));
                              ir_if *f06B2 = new(mem_ctx) ir_if(operand(r06B3).val);
                              exec_list *const f06B2_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06B2->then_instructions;

                                 ir_variable *const r06B4 = body.make_temp(glsl_type::uint_type, "a2");
                                 body.emit(assign(r06B4, r0661, 0x01));

                                 ir_variable *const r06B5 = body.make_temp(glsl_type::int_type, "count");
                                 body.emit(assign(r06B5, neg(r065E), 0x01));

                                 ir_variable *const r06B6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                 body.emit(r06B6);
                                 ir_variable *const r06B7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                 body.emit(r06B7);
                                 ir_variable *const r06B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                 body.emit(r06B8);
                                 ir_variable *const r06B9 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                 ir_expression *const r06BA = neg(r06B5);
                                 body.emit(assign(r06B9, bit_and(r06BA, body.constant(int(31))), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r06BC = equal(r06B5, body.constant(int(0)));
                                 ir_if *f06BB = new(mem_ctx) ir_if(operand(r06BC).val);
                                 exec_list *const f06BB_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f06BB->then_instructions;

                                    body.emit(assign(r06B6, r0661, 0x01));

                                    body.emit(assign(r06B7, r0660, 0x01));

                                    body.emit(assign(r06B8, r065F, 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f06BB->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r06BE = less(r06B5, body.constant(int(32)));
                                    ir_if *f06BD = new(mem_ctx) ir_if(operand(r06BE).val);
                                    exec_list *const f06BD_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f06BD->then_instructions;

                                       body.emit(assign(r06B6, lshift(r0660, r06B9), 0x01));

                                       ir_expression *const r06BF = lshift(r065F, r06B9);
                                       ir_expression *const r06C0 = rshift(r0660, r06B5);
                                       body.emit(assign(r06B7, bit_or(r06BF, r06C0), 0x01));

                                       body.emit(assign(r06B8, rshift(r065F, r06B5), 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f06BD->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r06C2 = equal(r06B5, body.constant(int(32)));
                                       ir_if *f06C1 = new(mem_ctx) ir_if(operand(r06C2).val);
                                       exec_list *const f06C1_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f06C1->then_instructions;

                                          body.emit(assign(r06B6, r0660, 0x01));

                                          body.emit(assign(r06B7, r065F, 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f06C1->else_instructions;

                                          body.emit(assign(r06B4, bit_or(r0661, r0660), 0x01));

                                          /* IF CONDITION */
                                          ir_expression *const r06C4 = less(r06B5, body.constant(int(64)));
                                          ir_if *f06C3 = new(mem_ctx) ir_if(operand(r06C4).val);
                                          exec_list *const f06C3_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f06C3->then_instructions;

                                             body.emit(assign(r06B6, lshift(r065F, r06B9), 0x01));

                                             ir_expression *const r06C5 = bit_and(r06B5, body.constant(int(31)));
                                             body.emit(assign(r06B7, rshift(r065F, r06C5), 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f06C3->else_instructions;

                                             ir_variable *const r06C6 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                             /* IF CONDITION */
                                             ir_expression *const r06C8 = equal(r06B5, body.constant(int(64)));
                                             ir_if *f06C7 = new(mem_ctx) ir_if(operand(r06C8).val);
                                             exec_list *const f06C7_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f06C7->then_instructions;

                                                body.emit(assign(r06C6, r065F, 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f06C7->else_instructions;

                                                ir_expression *const r06C9 = nequal(r065F, body.constant(0u));
                                                ir_expression *const r06CA = expr(ir_unop_b2i, r06C9);
                                                body.emit(assign(r06C6, expr(ir_unop_i2u, r06CA), 0x01));


                                             body.instructions = f06C7_parent_instructions;
                                             body.emit(f06C7);

                                             /* END IF */

                                             body.emit(assign(r06B6, r06C6, 0x01));

                                             body.emit(assign(r06B7, body.constant(0u), 0x01));


                                          body.instructions = f06C3_parent_instructions;
                                          body.emit(f06C3);

                                          /* END IF */


                                       body.instructions = f06C1_parent_instructions;
                                       body.emit(f06C1);

                                       /* END IF */

                                       body.emit(assign(r06B8, body.constant(0u), 0x01));


                                    body.instructions = f06BD_parent_instructions;
                                    body.emit(f06BD);

                                    /* END IF */

                                    ir_expression *const r06CB = nequal(r06B4, body.constant(0u));
                                    ir_expression *const r06CC = expr(ir_unop_b2i, r06CB);
                                    ir_expression *const r06CD = expr(ir_unop_i2u, r06CC);
                                    body.emit(assign(r06B6, bit_or(r06B6, r06CD), 0x01));


                                 body.instructions = f06BB_parent_instructions;
                                 body.emit(f06BB);

                                 /* END IF */

                                 body.emit(assign(r069E, r06B8, 0x01));

                                 body.emit(assign(r069F, r06B7, 0x01));

                                 body.emit(assign(r06A0, r06B6, 0x01));

                                 body.emit(assign(r069D, body.constant(int(0)), 0x01));

                                 body.emit(assign(r06A3, less(r06B6, body.constant(0u)), 0x01));


                              body.instructions = f06B2_parent_instructions;
                              body.emit(f06B2);

                              /* END IF */


                           body.instructions = f06A7_parent_instructions;
                           body.emit(f06A7);

                           /* END IF */


                        body.instructions = f06A5_parent_instructions;
                        body.emit(f06A5);

                        /* END IF */

                        /* IF CONDITION */
                        ir_if *f06CE = new(mem_ctx) ir_if(operand(r06A1).val);
                        exec_list *const f06CE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06CE->then_instructions;

                           /* IF CONDITION */
                           ir_if *f06CF = new(mem_ctx) ir_if(operand(r06A3).val);
                           exec_list *const f06CF_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06CF->then_instructions;

                              ir_variable *const r06D0 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                              body.emit(assign(r06D0, add(r069F, body.constant(1u)), 0x01));

                              ir_expression *const r06D1 = less(r06D0, r069F);
                              ir_expression *const r06D2 = expr(ir_unop_b2i, r06D1);
                              ir_expression *const r06D3 = expr(ir_unop_i2u, r06D2);
                              body.emit(assign(r069E, add(r069E, r06D3), 0x01));

                              ir_expression *const r06D4 = equal(r06A0, body.constant(0u));
                              ir_expression *const r06D5 = expr(ir_unop_b2i, r06D4);
                              ir_expression *const r06D6 = expr(ir_unop_i2u, r06D5);
                              ir_expression *const r06D7 = add(r06A0, r06D6);
                              ir_expression *const r06D8 = bit_and(r06D7, body.constant(1u));
                              ir_expression *const r06D9 = expr(ir_unop_bit_not, r06D8);
                              body.emit(assign(r069F, bit_and(r06D0, r06D9), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06CF->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r06DB = bit_or(r069E, r069F);
                              ir_expression *const r06DC = equal(r06DB, body.constant(0u));
                              ir_if *f06DA = new(mem_ctx) ir_if(operand(r06DC).val);
                              exec_list *const f06DA_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06DA->then_instructions;

                                 body.emit(assign(r069D, body.constant(int(0)), 0x01));


                              body.instructions = f06DA_parent_instructions;
                              body.emit(f06DA);

                              /* END IF */


                           body.instructions = f06CF_parent_instructions;
                           body.emit(f06CF);

                           /* END IF */

                           ir_variable *const r06DD = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r06DD);
                           ir_expression *const r06DE = lshift(r01E5, body.constant(int(31)));
                           ir_expression *const r06DF = expr(ir_unop_i2u, r069D);
                           ir_expression *const r06E0 = lshift(r06DF, body.constant(int(20)));
                           ir_expression *const r06E1 = add(r06DE, r06E0);
                           body.emit(assign(r06DD, add(r06E1, r069E), 0x02));

                           body.emit(assign(r06DD, r069F, 0x01));

                           body.emit(assign(r06A2, r06DD, 0x03));

                           body.emit(assign(r06A1, body.constant(false), 0x01));


                        body.instructions = f06CE_parent_instructions;
                        body.emit(f06CE);

                        /* END IF */

                        body.emit(assign(r01E4, r06A2, 0x03));

                        body.emit(assign(r01E3, body.constant(false), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0656->else_instructions;

                        /* IF CONDITION */
                        ir_expression *const r06E3 = less(r037C, r037A);
                        ir_if *f06E2 = new(mem_ctx) ir_if(operand(r06E3).val);
                        exec_list *const f06E2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f06E2->then_instructions;

                           ir_variable *const r06E4 = body.make_temp(glsl_type::uint_type, "z0Ptr");
                           ir_variable *const r06E5 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                           body.emit(assign(r06E5, sub(r037A, r037C), 0x01));

                           ir_expression *const r06E6 = sub(r0379, r037B);
                           ir_expression *const r06E7 = less(r037A, r037C);
                           ir_expression *const r06E8 = expr(ir_unop_b2i, r06E7);
                           ir_expression *const r06E9 = expr(ir_unop_i2u, r06E8);
                           body.emit(assign(r06E4, sub(r06E6, r06E9), 0x01));

                           body.emit(assign(r01E5, bit_xor(r01E5, body.constant(1u)), 0x01));

                           body.emit(assign(r037D, add(r0377, body.constant(int(-1))), 0x01));

                           ir_variable *const r06EA = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r06EA, add(r037D, body.constant(int(-10))), 0x01));

                           ir_variable *const r06EB = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r06EB, r06E4, 0x01));

                           ir_variable *const r06EC = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r06EC, r06E5, 0x01));

                           ir_variable *const r06ED = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
                           body.emit(r06ED);
                           ir_variable *const r06EE = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06EE);
                           /* IF CONDITION */
                           ir_expression *const r06F0 = equal(r06E4, body.constant(0u));
                           ir_if *f06EF = new(mem_ctx) ir_if(operand(r06F0).val);
                           exec_list *const f06EF_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06EF->then_instructions;

                              body.emit(assign(r06EB, r06E5, 0x01));

                              body.emit(assign(r06EC, body.constant(0u), 0x01));

                              body.emit(assign(r06EA, add(r06EA, body.constant(int(-32))), 0x01));


                           body.instructions = f06EF_parent_instructions;
                           body.emit(f06EF);

                           /* END IF */

                           ir_variable *const r06F1 = body.make_temp(glsl_type::uint_type, "a");
                           body.emit(assign(r06F1, r06EB, 0x01));

                           ir_variable *const r06F2 = body.make_temp(glsl_type::int_type, "return_value");
                           ir_variable *const r06F3 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                           body.emit(r06F3);
                           /* IF CONDITION */
                           ir_expression *const r06F5 = equal(r06EB, body.constant(0u));
                           ir_if *f06F4 = new(mem_ctx) ir_if(operand(r06F5).val);
                           exec_list *const f06F4_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f06F4->then_instructions;

                              body.emit(assign(r06F2, body.constant(int(32)), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f06F4->else_instructions;

                              body.emit(assign(r06F3, body.constant(int(0)), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r06F7 = bit_and(r06EB, body.constant(4294901760u));
                              ir_expression *const r06F8 = equal(r06F7, body.constant(0u));
                              ir_if *f06F6 = new(mem_ctx) ir_if(operand(r06F8).val);
                              exec_list *const f06F6_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06F6->then_instructions;

                                 body.emit(assign(r06F3, body.constant(int(16)), 0x01));

                                 body.emit(assign(r06F1, lshift(r06EB, body.constant(int(16))), 0x01));


                              body.instructions = f06F6_parent_instructions;
                              body.emit(f06F6);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r06FA = bit_and(r06F1, body.constant(4278190080u));
                              ir_expression *const r06FB = equal(r06FA, body.constant(0u));
                              ir_if *f06F9 = new(mem_ctx) ir_if(operand(r06FB).val);
                              exec_list *const f06F9_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06F9->then_instructions;

                                 body.emit(assign(r06F3, add(r06F3, body.constant(int(8))), 0x01));

                                 body.emit(assign(r06F1, lshift(r06F1, body.constant(int(8))), 0x01));


                              body.instructions = f06F9_parent_instructions;
                              body.emit(f06F9);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r06FD = bit_and(r06F1, body.constant(4026531840u));
                              ir_expression *const r06FE = equal(r06FD, body.constant(0u));
                              ir_if *f06FC = new(mem_ctx) ir_if(operand(r06FE).val);
                              exec_list *const f06FC_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06FC->then_instructions;

                                 body.emit(assign(r06F3, add(r06F3, body.constant(int(4))), 0x01));

                                 body.emit(assign(r06F1, lshift(r06F1, body.constant(int(4))), 0x01));


                              body.instructions = f06FC_parent_instructions;
                              body.emit(f06FC);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0700 = bit_and(r06F1, body.constant(3221225472u));
                              ir_expression *const r0701 = equal(r0700, body.constant(0u));
                              ir_if *f06FF = new(mem_ctx) ir_if(operand(r0701).val);
                              exec_list *const f06FF_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f06FF->then_instructions;

                                 body.emit(assign(r06F3, add(r06F3, body.constant(int(2))), 0x01));

                                 body.emit(assign(r06F1, lshift(r06F1, body.constant(int(2))), 0x01));


                              body.instructions = f06FF_parent_instructions;
                              body.emit(f06FF);

                              /* END IF */

                              /* IF CONDITION */
                              ir_expression *const r0703 = bit_and(r06F1, body.constant(2147483648u));
                              ir_expression *const r0704 = equal(r0703, body.constant(0u));
                              ir_if *f0702 = new(mem_ctx) ir_if(operand(r0704).val);
                              exec_list *const f0702_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0702->then_instructions;

                                 body.emit(assign(r06F3, add(r06F3, body.constant(int(1))), 0x01));


                              body.instructions = f0702_parent_instructions;
                              body.emit(f0702);

                              /* END IF */

                              body.emit(assign(r06F2, r06F3, 0x01));


                           body.instructions = f06F4_parent_instructions;
                           body.emit(f06F4);

                           /* END IF */

                           body.emit(assign(r06EE, add(r06F2, body.constant(int(-11))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0706 = lequal(body.constant(int(0)), r06EE);
                           ir_if *f0705 = new(mem_ctx) ir_if(operand(r0706).val);
                           exec_list *const f0705_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0705->then_instructions;

                              body.emit(assign(r06ED, body.constant(0u), 0x01));

                              ir_variable *const r0707 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                              body.emit(assign(r0707, lshift(r06EC, r06EE), 0x01));

                              ir_variable *const r0708 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                              /* IF CONDITION */
                              ir_expression *const r070A = equal(r06EE, body.constant(int(0)));
                              ir_if *f0709 = new(mem_ctx) ir_if(operand(r070A).val);
                              exec_list *const f0709_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0709->then_instructions;

                                 body.emit(assign(r0708, r06EB, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0709->else_instructions;

                                 ir_expression *const r070B = lshift(r06EB, r06EE);
                                 ir_expression *const r070C = neg(r06EE);
                                 ir_expression *const r070D = bit_and(r070C, body.constant(int(31)));
                                 ir_expression *const r070E = rshift(r06EC, r070D);
                                 body.emit(assign(r0708, bit_or(r070B, r070E), 0x01));


                              body.instructions = f0709_parent_instructions;
                              body.emit(f0709);

                              /* END IF */

                              body.emit(assign(r06EB, r0708, 0x01));

                              body.emit(assign(r06EC, r0707, 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f0705->else_instructions;

                              ir_variable *const r070F = body.make_temp(glsl_type::uint_type, "a2");
                              body.emit(assign(r070F, body.constant(0u), 0x01));

                              ir_variable *const r0710 = body.make_temp(glsl_type::int_type, "count");
                              body.emit(assign(r0710, neg(r06EE), 0x01));

                              ir_variable *const r0711 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                              body.emit(r0711);
                              ir_variable *const r0712 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                              body.emit(r0712);
                              ir_variable *const r0713 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                              body.emit(r0713);
                              ir_variable *const r0714 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                              ir_expression *const r0715 = neg(r0710);
                              body.emit(assign(r0714, bit_and(r0715, body.constant(int(31))), 0x01));

                              /* IF CONDITION */
                              ir_expression *const r0717 = equal(r0710, body.constant(int(0)));
                              ir_if *f0716 = new(mem_ctx) ir_if(operand(r0717).val);
                              exec_list *const f0716_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0716->then_instructions;

                                 body.emit(assign(r0711, r070F, 0x01));

                                 body.emit(assign(r0712, r06EC, 0x01));

                                 body.emit(assign(r0713, r06EB, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0716->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0719 = less(r0710, body.constant(int(32)));
                                 ir_if *f0718 = new(mem_ctx) ir_if(operand(r0719).val);
                                 exec_list *const f0718_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0718->then_instructions;

                                    body.emit(assign(r0711, lshift(r06EC, r0714), 0x01));

                                    ir_expression *const r071A = lshift(r06EB, r0714);
                                    ir_expression *const r071B = rshift(r06EC, r0710);
                                    body.emit(assign(r0712, bit_or(r071A, r071B), 0x01));

                                    body.emit(assign(r0713, rshift(r06EB, r0710), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f0718->else_instructions;

                                    /* IF CONDITION */
                                    ir_expression *const r071D = equal(r0710, body.constant(int(32)));
                                    ir_if *f071C = new(mem_ctx) ir_if(operand(r071D).val);
                                    exec_list *const f071C_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f071C->then_instructions;

                                       body.emit(assign(r0711, r06EC, 0x01));

                                       body.emit(assign(r0712, r06EB, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f071C->else_instructions;

                                       body.emit(assign(r070F, bit_or(body.constant(0u), r06EC), 0x01));

                                       /* IF CONDITION */
                                       ir_expression *const r071F = less(r0710, body.constant(int(64)));
                                       ir_if *f071E = new(mem_ctx) ir_if(operand(r071F).val);
                                       exec_list *const f071E_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f071E->then_instructions;

                                          body.emit(assign(r0711, lshift(r06EB, r0714), 0x01));

                                          ir_expression *const r0720 = bit_and(r0710, body.constant(int(31)));
                                          body.emit(assign(r0712, rshift(r06EB, r0720), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f071E->else_instructions;

                                          ir_variable *const r0721 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                          /* IF CONDITION */
                                          ir_expression *const r0723 = equal(r0710, body.constant(int(64)));
                                          ir_if *f0722 = new(mem_ctx) ir_if(operand(r0723).val);
                                          exec_list *const f0722_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f0722->then_instructions;

                                             body.emit(assign(r0721, r06EB, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f0722->else_instructions;

                                             ir_expression *const r0724 = nequal(r06EB, body.constant(0u));
                                             ir_expression *const r0725 = expr(ir_unop_b2i, r0724);
                                             body.emit(assign(r0721, expr(ir_unop_i2u, r0725), 0x01));


                                          body.instructions = f0722_parent_instructions;
                                          body.emit(f0722);

                                          /* END IF */

                                          body.emit(assign(r0711, r0721, 0x01));

                                          body.emit(assign(r0712, body.constant(0u), 0x01));


                                       body.instructions = f071E_parent_instructions;
                                       body.emit(f071E);

                                       /* END IF */


                                    body.instructions = f071C_parent_instructions;
                                    body.emit(f071C);

                                    /* END IF */

                                    body.emit(assign(r0713, body.constant(0u), 0x01));


                                 body.instructions = f0718_parent_instructions;
                                 body.emit(f0718);

                                 /* END IF */

                                 ir_expression *const r0726 = nequal(r070F, body.constant(0u));
                                 ir_expression *const r0727 = expr(ir_unop_b2i, r0726);
                                 ir_expression *const r0728 = expr(ir_unop_i2u, r0727);
                                 body.emit(assign(r0711, bit_or(r0711, r0728), 0x01));


                              body.instructions = f0716_parent_instructions;
                              body.emit(f0716);

                              /* END IF */

                              body.emit(assign(r06EB, r0713, 0x01));

                              body.emit(assign(r06EC, r0712, 0x01));

                              body.emit(assign(r06ED, r0711, 0x01));


                           body.instructions = f0705_parent_instructions;
                           body.emit(f0705);

                           /* END IF */

                           body.emit(assign(r06EA, sub(r06EA, r06EE), 0x01));

                           ir_variable *const r0729 = body.make_temp(glsl_type::int_type, "zExp");
                           body.emit(assign(r0729, r06EA, 0x01));

                           ir_variable *const r072A = body.make_temp(glsl_type::uint_type, "zFrac0");
                           body.emit(assign(r072A, r06EB, 0x01));

                           ir_variable *const r072B = body.make_temp(glsl_type::uint_type, "zFrac1");
                           body.emit(assign(r072B, r06EC, 0x01));

                           ir_variable *const r072C = body.make_temp(glsl_type::uint_type, "zFrac2");
                           body.emit(assign(r072C, r06ED, 0x01));

                           ir_variable *const r072D = body.make_temp(glsl_type::bool_type, "execute_flag");
                           body.emit(assign(r072D, body.constant(true), 0x01));

                           ir_variable *const r072E = body.make_temp(glsl_type::uvec2_type, "return_value");
                           ir_variable *const r072F = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
                           body.emit(r072F);
                           ir_expression *const r0730 = expr(ir_unop_u2i, r06ED);
                           body.emit(assign(r072F, less(r0730, body.constant(int(0))), 0x01));

                           /* IF CONDITION */
                           ir_expression *const r0732 = lequal(body.constant(int(2045)), r06EA);
                           ir_if *f0731 = new(mem_ctx) ir_if(operand(r0732).val);
                           exec_list *const f0731_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f0731->then_instructions;

                              /* IF CONDITION */
                              ir_expression *const r0734 = less(body.constant(int(2045)), r06EA);
                              ir_expression *const r0735 = equal(r06EA, body.constant(int(2045)));
                              ir_expression *const r0736 = equal(body.constant(2097151u), r06EB);
                              ir_expression *const r0737 = equal(body.constant(4294967295u), r06EC);
                              ir_expression *const r0738 = logic_and(r0736, r0737);
                              ir_expression *const r0739 = logic_and(r0735, r0738);
                              ir_expression *const r073A = logic_and(r0739, r072F);
                              ir_expression *const r073B = logic_or(r0734, r073A);
                              ir_if *f0733 = new(mem_ctx) ir_if(operand(r073B).val);
                              exec_list *const f0733_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f0733->then_instructions;

                                 ir_variable *const r073C = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                                 body.emit(r073C);
                                 ir_expression *const r073D = lshift(r01E5, body.constant(int(31)));
                                 body.emit(assign(r073C, add(r073D, body.constant(2146435072u)), 0x02));

                                 body.emit(assign(r073C, body.constant(0u), 0x01));

                                 body.emit(assign(r072E, r073C, 0x03));

                                 body.emit(assign(r072D, body.constant(false), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f0733->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r073F = less(r06EA, body.constant(int(0)));
                                 ir_if *f073E = new(mem_ctx) ir_if(operand(r073F).val);
                                 exec_list *const f073E_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f073E->then_instructions;

                                    ir_variable *const r0740 = body.make_temp(glsl_type::uint_type, "a2");
                                    body.emit(assign(r0740, r06ED, 0x01));

                                    ir_variable *const r0741 = body.make_temp(glsl_type::int_type, "count");
                                    body.emit(assign(r0741, neg(r06EA), 0x01));

                                    ir_variable *const r0742 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                                    body.emit(r0742);
                                    ir_variable *const r0743 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                                    body.emit(r0743);
                                    ir_variable *const r0744 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                                    body.emit(r0744);
                                    ir_variable *const r0745 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                                    ir_expression *const r0746 = neg(r0741);
                                    body.emit(assign(r0745, bit_and(r0746, body.constant(int(31))), 0x01));

                                    /* IF CONDITION */
                                    ir_expression *const r0748 = equal(r0741, body.constant(int(0)));
                                    ir_if *f0747 = new(mem_ctx) ir_if(operand(r0748).val);
                                    exec_list *const f0747_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f0747->then_instructions;

                                       body.emit(assign(r0742, r06ED, 0x01));

                                       body.emit(assign(r0743, r06EC, 0x01));

                                       body.emit(assign(r0744, r06EB, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f0747->else_instructions;

                                       /* IF CONDITION */
                                       ir_expression *const r074A = less(r0741, body.constant(int(32)));
                                       ir_if *f0749 = new(mem_ctx) ir_if(operand(r074A).val);
                                       exec_list *const f0749_parent_instructions = body.instructions;

                                          /* THEN INSTRUCTIONS */
                                          body.instructions = &f0749->then_instructions;

                                          body.emit(assign(r0742, lshift(r06EC, r0745), 0x01));

                                          ir_expression *const r074B = lshift(r06EB, r0745);
                                          ir_expression *const r074C = rshift(r06EC, r0741);
                                          body.emit(assign(r0743, bit_or(r074B, r074C), 0x01));

                                          body.emit(assign(r0744, rshift(r06EB, r0741), 0x01));


                                          /* ELSE INSTRUCTIONS */
                                          body.instructions = &f0749->else_instructions;

                                          /* IF CONDITION */
                                          ir_expression *const r074E = equal(r0741, body.constant(int(32)));
                                          ir_if *f074D = new(mem_ctx) ir_if(operand(r074E).val);
                                          exec_list *const f074D_parent_instructions = body.instructions;

                                             /* THEN INSTRUCTIONS */
                                             body.instructions = &f074D->then_instructions;

                                             body.emit(assign(r0742, r06EC, 0x01));

                                             body.emit(assign(r0743, r06EB, 0x01));


                                             /* ELSE INSTRUCTIONS */
                                             body.instructions = &f074D->else_instructions;

                                             body.emit(assign(r0740, bit_or(r06ED, r06EC), 0x01));

                                             /* IF CONDITION */
                                             ir_expression *const r0750 = less(r0741, body.constant(int(64)));
                                             ir_if *f074F = new(mem_ctx) ir_if(operand(r0750).val);
                                             exec_list *const f074F_parent_instructions = body.instructions;

                                                /* THEN INSTRUCTIONS */
                                                body.instructions = &f074F->then_instructions;

                                                body.emit(assign(r0742, lshift(r06EB, r0745), 0x01));

                                                ir_expression *const r0751 = bit_and(r0741, body.constant(int(31)));
                                                body.emit(assign(r0743, rshift(r06EB, r0751), 0x01));


                                                /* ELSE INSTRUCTIONS */
                                                body.instructions = &f074F->else_instructions;

                                                ir_variable *const r0752 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                                /* IF CONDITION */
                                                ir_expression *const r0754 = equal(r0741, body.constant(int(64)));
                                                ir_if *f0753 = new(mem_ctx) ir_if(operand(r0754).val);
                                                exec_list *const f0753_parent_instructions = body.instructions;

                                                   /* THEN INSTRUCTIONS */
                                                   body.instructions = &f0753->then_instructions;

                                                   body.emit(assign(r0752, r06EB, 0x01));


                                                   /* ELSE INSTRUCTIONS */
                                                   body.instructions = &f0753->else_instructions;

                                                   ir_expression *const r0755 = nequal(r06EB, body.constant(0u));
                                                   ir_expression *const r0756 = expr(ir_unop_b2i, r0755);
                                                   body.emit(assign(r0752, expr(ir_unop_i2u, r0756), 0x01));


                                                body.instructions = f0753_parent_instructions;
                                                body.emit(f0753);

                                                /* END IF */

                                                body.emit(assign(r0742, r0752, 0x01));

                                                body.emit(assign(r0743, body.constant(0u), 0x01));


                                             body.instructions = f074F_parent_instructions;
                                             body.emit(f074F);

                                             /* END IF */


                                          body.instructions = f074D_parent_instructions;
                                          body.emit(f074D);

                                          /* END IF */

                                          body.emit(assign(r0744, body.constant(0u), 0x01));


                                       body.instructions = f0749_parent_instructions;
                                       body.emit(f0749);

                                       /* END IF */

                                       ir_expression *const r0757 = nequal(r0740, body.constant(0u));
                                       ir_expression *const r0758 = expr(ir_unop_b2i, r0757);
                                       ir_expression *const r0759 = expr(ir_unop_i2u, r0758);
                                       body.emit(assign(r0742, bit_or(r0742, r0759), 0x01));


                                    body.instructions = f0747_parent_instructions;
                                    body.emit(f0747);

                                    /* END IF */

                                    body.emit(assign(r072A, r0744, 0x01));

                                    body.emit(assign(r072B, r0743, 0x01));

                                    body.emit(assign(r072C, r0742, 0x01));

                                    body.emit(assign(r0729, body.constant(int(0)), 0x01));

                                    body.emit(assign(r072F, less(r0742, body.constant(0u)), 0x01));


                                 body.instructions = f073E_parent_instructions;
                                 body.emit(f073E);

                                 /* END IF */


                              body.instructions = f0733_parent_instructions;
                              body.emit(f0733);

                              /* END IF */


                           body.instructions = f0731_parent_instructions;
                           body.emit(f0731);

                           /* END IF */

                           /* IF CONDITION */
                           ir_if *f075A = new(mem_ctx) ir_if(operand(r072D).val);
                           exec_list *const f075A_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f075A->then_instructions;

                              /* IF CONDITION */
                              ir_if *f075B = new(mem_ctx) ir_if(operand(r072F).val);
                              exec_list *const f075B_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f075B->then_instructions;

                                 ir_variable *const r075C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                                 body.emit(assign(r075C, add(r072B, body.constant(1u)), 0x01));

                                 ir_expression *const r075D = less(r075C, r072B);
                                 ir_expression *const r075E = expr(ir_unop_b2i, r075D);
                                 ir_expression *const r075F = expr(ir_unop_i2u, r075E);
                                 body.emit(assign(r072A, add(r072A, r075F), 0x01));

                                 ir_expression *const r0760 = equal(r072C, body.constant(0u));
                                 ir_expression *const r0761 = expr(ir_unop_b2i, r0760);
                                 ir_expression *const r0762 = expr(ir_unop_i2u, r0761);
                                 ir_expression *const r0763 = add(r072C, r0762);
                                 ir_expression *const r0764 = bit_and(r0763, body.constant(1u));
                                 ir_expression *const r0765 = expr(ir_unop_bit_not, r0764);
                                 body.emit(assign(r072B, bit_and(r075C, r0765), 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f075B->else_instructions;

                                 /* IF CONDITION */
                                 ir_expression *const r0767 = bit_or(r072A, r072B);
                                 ir_expression *const r0768 = equal(r0767, body.constant(0u));
                                 ir_if *f0766 = new(mem_ctx) ir_if(operand(r0768).val);
                                 exec_list *const f0766_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f0766->then_instructions;

                                    body.emit(assign(r0729, body.constant(int(0)), 0x01));


                                 body.instructions = f0766_parent_instructions;
                                 body.emit(f0766);

                                 /* END IF */


                              body.instructions = f075B_parent_instructions;
                              body.emit(f075B);

                              /* END IF */

                              ir_variable *const r0769 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                              body.emit(r0769);
                              ir_expression *const r076A = lshift(r01E5, body.constant(int(31)));
                              ir_expression *const r076B = expr(ir_unop_i2u, r0729);
                              ir_expression *const r076C = lshift(r076B, body.constant(int(20)));
                              ir_expression *const r076D = add(r076A, r076C);
                              body.emit(assign(r0769, add(r076D, r072A), 0x02));

                              body.emit(assign(r0769, r072B, 0x01));

                              body.emit(assign(r072E, r0769, 0x03));

                              body.emit(assign(r072D, body.constant(false), 0x01));


                           body.instructions = f075A_parent_instructions;
                           body.emit(f075A);

                           /* END IF */

                           body.emit(assign(r01E4, r072E, 0x03));

                           body.emit(assign(r01E3, body.constant(false), 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f06E2->else_instructions;

                           ir_variable *const r076E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                           body.emit(r076E);
                           body.emit(assign(r076E, body.constant(0u), 0x02));

                           body.emit(assign(r076E, body.constant(0u), 0x01));

                           body.emit(assign(r01E4, r076E, 0x03));

                           body.emit(assign(r01E3, body.constant(false), 0x01));


                        body.instructions = f06E2_parent_instructions;
                        body.emit(f06E2);

                        /* END IF */


                     body.instructions = f0656_parent_instructions;
                     body.emit(f0656);

                     /* END IF */


                  body.instructions = f05CA_parent_instructions;
                  body.emit(f05CA);

                  /* END IF */


               body.instructions = f053E_parent_instructions;
               body.emit(f053E);

               /* END IF */


            body.instructions = f0520_parent_instructions;
            body.emit(f0520);

            /* END IF */


         body.instructions = f0455_parent_instructions;
         body.emit(f0455);

         /* END IF */


      body.instructions = f038E_parent_instructions;
      body.emit(f038E);

      /* END IF */


   body.instructions = f01E8_parent_instructions;
   body.emit(f01E8);

   /* END IF */

   body.emit(ret(r01E4));

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

   ir_variable *const r076F = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r076F);
   ir_variable *const r0770 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0770);
   ir_variable *const r0771 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0771);
   ir_variable *const r0772 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0772);
   ir_variable *const r0773 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0773);
   ir_variable *const r0774 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0774);
   ir_variable *const r0775 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0775);
   ir_variable *const r0776 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0776, bit_and(r076F, body.constant(65535u)), 0x01));

   ir_variable *const r0777 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0777, rshift(r076F, body.constant(int(16))), 0x01));

   ir_variable *const r0778 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0778, bit_and(r0770, body.constant(65535u)), 0x01));

   ir_variable *const r0779 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0779, rshift(r0770, body.constant(int(16))), 0x01));

   ir_variable *const r077A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r077A, mul(r0777, r0778), 0x01));

   ir_expression *const r077B = mul(r0776, r0779);
   body.emit(assign(r0774, add(r077B, r077A), 0x01));

   ir_expression *const r077C = mul(r0777, r0779);
   ir_expression *const r077D = less(r0774, r077A);
   ir_expression *const r077E = expr(ir_unop_b2i, r077D);
   ir_expression *const r077F = expr(ir_unop_i2u, r077E);
   ir_expression *const r0780 = lshift(r077F, body.constant(int(16)));
   ir_expression *const r0781 = rshift(r0774, body.constant(int(16)));
   ir_expression *const r0782 = add(r0780, r0781);
   body.emit(assign(r0773, add(r077C, r0782), 0x01));

   body.emit(assign(r0774, lshift(r0774, body.constant(int(16))), 0x01));

   ir_expression *const r0783 = mul(r0776, r0778);
   body.emit(assign(r0775, add(r0783, r0774), 0x01));

   ir_expression *const r0784 = less(r0775, r0774);
   ir_expression *const r0785 = expr(ir_unop_b2i, r0784);
   ir_expression *const r0786 = expr(ir_unop_i2u, r0785);
   body.emit(assign(r0773, add(r0773, r0786), 0x01));

   body.emit(assign(r0772, r0775, 0x01));

   body.emit(assign(r0771, r0773, 0x01));

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

   ir_variable *const r0787 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0787);
   ir_variable *const r0788 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0788);
   ir_variable *const r0789 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0789);
   ir_variable *const r078A = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r078A);
   ir_variable *const r078B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r078B);
   ir_variable *const r078C = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r078C);
   ir_variable *const r078D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r078D);
   ir_variable *const r078E = new(mem_ctx) ir_variable(glsl_type::uint_type, "z3Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r078E);
   ir_variable *const r078F = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r078F);
   ir_variable *const r0790 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r0790);
   ir_variable *const r0791 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0791);
   ir_variable *const r0792 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0792, bit_and(r0788, body.constant(65535u)), 0x01));

   ir_variable *const r0793 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0793, rshift(r0788, body.constant(int(16))), 0x01));

   ir_variable *const r0794 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0794, bit_and(r078A, body.constant(65535u)), 0x01));

   ir_variable *const r0795 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0795, rshift(r078A, body.constant(int(16))), 0x01));

   ir_variable *const r0796 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0796, mul(r0793, r0794), 0x01));

   ir_expression *const r0797 = mul(r0792, r0795);
   body.emit(assign(r0790, add(r0797, r0796), 0x01));

   ir_expression *const r0798 = mul(r0793, r0795);
   ir_expression *const r0799 = less(r0790, r0796);
   ir_expression *const r079A = expr(ir_unop_b2i, r0799);
   ir_expression *const r079B = expr(ir_unop_i2u, r079A);
   ir_expression *const r079C = lshift(r079B, body.constant(int(16)));
   ir_expression *const r079D = rshift(r0790, body.constant(int(16)));
   ir_expression *const r079E = add(r079C, r079D);
   body.emit(assign(r078F, add(r0798, r079E), 0x01));

   body.emit(assign(r0790, lshift(r0790, body.constant(int(16))), 0x01));

   ir_expression *const r079F = mul(r0792, r0794);
   body.emit(assign(r0791, add(r079F, r0790), 0x01));

   ir_expression *const r07A0 = less(r0791, r0790);
   ir_expression *const r07A1 = expr(ir_unop_b2i, r07A0);
   ir_expression *const r07A2 = expr(ir_unop_i2u, r07A1);
   body.emit(assign(r078F, add(r078F, r07A2), 0x01));

   ir_variable *const r07A3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07A3);
   ir_variable *const r07A4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07A4);
   ir_variable *const r07A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07A5);
   ir_variable *const r07A6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A6, bit_and(r0788, body.constant(65535u)), 0x01));

   ir_variable *const r07A7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A7, rshift(r0788, body.constant(int(16))), 0x01));

   ir_variable *const r07A8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A8, bit_and(r0789, body.constant(65535u)), 0x01));

   ir_variable *const r07A9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07A9, rshift(r0789, body.constant(int(16))), 0x01));

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

   ir_variable *const r07B7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07B7, add(r07A5, r078F), 0x01));

   ir_variable *const r07B8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07B8);
   ir_variable *const r07B9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07B9);
   ir_variable *const r07BA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07BA);
   ir_variable *const r07BB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07BB, bit_and(r0787, body.constant(65535u)), 0x01));

   ir_variable *const r07BC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07BC, rshift(r0787, body.constant(int(16))), 0x01));

   ir_variable *const r07BD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07BD, bit_and(r0789, body.constant(65535u)), 0x01));

   ir_variable *const r07BE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07BE, rshift(r0789, body.constant(int(16))), 0x01));

   ir_variable *const r07BF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07BF, mul(r07BC, r07BD), 0x01));

   ir_expression *const r07C0 = mul(r07BB, r07BE);
   body.emit(assign(r07B9, add(r07C0, r07BF), 0x01));

   ir_expression *const r07C1 = mul(r07BC, r07BE);
   ir_expression *const r07C2 = less(r07B9, r07BF);
   ir_expression *const r07C3 = expr(ir_unop_b2i, r07C2);
   ir_expression *const r07C4 = expr(ir_unop_i2u, r07C3);
   ir_expression *const r07C5 = lshift(r07C4, body.constant(int(16)));
   ir_expression *const r07C6 = rshift(r07B9, body.constant(int(16)));
   ir_expression *const r07C7 = add(r07C5, r07C6);
   body.emit(assign(r07B8, add(r07C1, r07C7), 0x01));

   body.emit(assign(r07B9, lshift(r07B9, body.constant(int(16))), 0x01));

   ir_expression *const r07C8 = mul(r07BB, r07BD);
   body.emit(assign(r07BA, add(r07C8, r07B9), 0x01));

   ir_expression *const r07C9 = less(r07BA, r07B9);
   ir_expression *const r07CA = expr(ir_unop_b2i, r07C9);
   ir_expression *const r07CB = expr(ir_unop_i2u, r07CA);
   body.emit(assign(r07B8, add(r07B8, r07CB), 0x01));

   ir_variable *const r07CC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r07CD = less(r07B7, r07A5);
   ir_expression *const r07CE = expr(ir_unop_b2i, r07CD);
   ir_expression *const r07CF = expr(ir_unop_i2u, r07CE);
   ir_expression *const r07D0 = add(r07A3, r07CF);
   body.emit(assign(r07CC, add(r07BA, r07D0), 0x01));

   ir_variable *const r07D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r07D1);
   ir_variable *const r07D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
   body.emit(r07D2);
   ir_variable *const r07D3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r07D3);
   ir_variable *const r07D4 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D4, bit_and(r0787, body.constant(65535u)), 0x01));

   ir_variable *const r07D5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D5, rshift(r0787, body.constant(int(16))), 0x01));

   ir_variable *const r07D6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D6, bit_and(r078A, body.constant(65535u)), 0x01));

   ir_variable *const r07D7 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D7, rshift(r078A, body.constant(int(16))), 0x01));

   ir_variable *const r07D8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07D8, mul(r07D5, r07D6), 0x01));

   ir_expression *const r07D9 = mul(r07D4, r07D7);
   body.emit(assign(r07D2, add(r07D9, r07D8), 0x01));

   ir_expression *const r07DA = mul(r07D5, r07D7);
   ir_expression *const r07DB = less(r07D2, r07D8);
   ir_expression *const r07DC = expr(ir_unop_b2i, r07DB);
   ir_expression *const r07DD = expr(ir_unop_i2u, r07DC);
   ir_expression *const r07DE = lshift(r07DD, body.constant(int(16)));
   ir_expression *const r07DF = rshift(r07D2, body.constant(int(16)));
   ir_expression *const r07E0 = add(r07DE, r07DF);
   body.emit(assign(r07D1, add(r07DA, r07E0), 0x01));

   body.emit(assign(r07D2, lshift(r07D2, body.constant(int(16))), 0x01));

   ir_expression *const r07E1 = mul(r07D4, r07D6);
   body.emit(assign(r07D3, add(r07E1, r07D2), 0x01));

   ir_expression *const r07E2 = less(r07D3, r07D2);
   ir_expression *const r07E3 = expr(ir_unop_b2i, r07E2);
   ir_expression *const r07E4 = expr(ir_unop_i2u, r07E3);
   body.emit(assign(r07D1, add(r07D1, r07E4), 0x01));

   ir_variable *const r07E5 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r07E5, add(r07D3, r07B7), 0x01));

   ir_variable *const r07E6 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r07E7 = less(r07E5, r07D3);
   ir_expression *const r07E8 = expr(ir_unop_b2i, r07E7);
   ir_expression *const r07E9 = expr(ir_unop_i2u, r07E8);
   ir_expression *const r07EA = add(r07D1, r07E9);
   body.emit(assign(r07E6, add(r07CC, r07EA), 0x01));

   body.emit(assign(r078E, r0791, 0x01));

   body.emit(assign(r078D, r07E5, 0x01));

   body.emit(assign(r078C, r07E6, 0x01));

   ir_expression *const r07EB = less(r07CC, r07BA);
   ir_expression *const r07EC = expr(ir_unop_b2i, r07EB);
   ir_expression *const r07ED = expr(ir_unop_i2u, r07EC);
   ir_expression *const r07EE = add(r07B8, r07ED);
   ir_expression *const r07EF = less(r07E6, r07CC);
   ir_expression *const r07F0 = expr(ir_unop_b2i, r07EF);
   ir_expression *const r07F1 = expr(ir_unop_i2u, r07F0);
   body.emit(assign(r078B, add(r07EE, r07F1), 0x01));

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

   ir_variable *const r07F2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac0", ir_var_function_in);
   sig_parameters.push_tail(r07F2);
   ir_variable *const r07F3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac1", ir_var_function_in);
   sig_parameters.push_tail(r07F3);
   ir_variable *const r07F4 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExpPtr", ir_var_function_inout);
   sig_parameters.push_tail(r07F4);
   ir_variable *const r07F5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07F5);
   ir_variable *const r07F6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r07F6);
   ir_variable *const r07F7 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
   body.emit(r07F7);
   /* IF CONDITION */
   ir_expression *const r07F9 = equal(r07F2, body.constant(0u));
   ir_if *f07F8 = new(mem_ctx) ir_if(operand(r07F9).val);
   exec_list *const f07F8_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f07F8->then_instructions;

      ir_variable *const r07FA = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r07FA, r07F3, 0x01));

      ir_variable *const r07FB = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r07FC = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r07FC);
      /* IF CONDITION */
      ir_expression *const r07FE = equal(r07F3, body.constant(0u));
      ir_if *f07FD = new(mem_ctx) ir_if(operand(r07FE).val);
      exec_list *const f07FD_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f07FD->then_instructions;

         body.emit(assign(r07FB, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f07FD->else_instructions;

         body.emit(assign(r07FC, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0800 = bit_and(r07F3, body.constant(4294901760u));
         ir_expression *const r0801 = equal(r0800, body.constant(0u));
         ir_if *f07FF = new(mem_ctx) ir_if(operand(r0801).val);
         exec_list *const f07FF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f07FF->then_instructions;

            body.emit(assign(r07FC, body.constant(int(16)), 0x01));

            body.emit(assign(r07FA, lshift(r07F3, body.constant(int(16))), 0x01));


         body.instructions = f07FF_parent_instructions;
         body.emit(f07FF);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0803 = bit_and(r07FA, body.constant(4278190080u));
         ir_expression *const r0804 = equal(r0803, body.constant(0u));
         ir_if *f0802 = new(mem_ctx) ir_if(operand(r0804).val);
         exec_list *const f0802_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0802->then_instructions;

            body.emit(assign(r07FC, add(r07FC, body.constant(int(8))), 0x01));

            body.emit(assign(r07FA, lshift(r07FA, body.constant(int(8))), 0x01));


         body.instructions = f0802_parent_instructions;
         body.emit(f0802);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0806 = bit_and(r07FA, body.constant(4026531840u));
         ir_expression *const r0807 = equal(r0806, body.constant(0u));
         ir_if *f0805 = new(mem_ctx) ir_if(operand(r0807).val);
         exec_list *const f0805_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0805->then_instructions;

            body.emit(assign(r07FC, add(r07FC, body.constant(int(4))), 0x01));

            body.emit(assign(r07FA, lshift(r07FA, body.constant(int(4))), 0x01));


         body.instructions = f0805_parent_instructions;
         body.emit(f0805);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0809 = bit_and(r07FA, body.constant(3221225472u));
         ir_expression *const r080A = equal(r0809, body.constant(0u));
         ir_if *f0808 = new(mem_ctx) ir_if(operand(r080A).val);
         exec_list *const f0808_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0808->then_instructions;

            body.emit(assign(r07FC, add(r07FC, body.constant(int(2))), 0x01));

            body.emit(assign(r07FA, lshift(r07FA, body.constant(int(2))), 0x01));


         body.instructions = f0808_parent_instructions;
         body.emit(f0808);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r080C = bit_and(r07FA, body.constant(2147483648u));
         ir_expression *const r080D = equal(r080C, body.constant(0u));
         ir_if *f080B = new(mem_ctx) ir_if(operand(r080D).val);
         exec_list *const f080B_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f080B->then_instructions;

            body.emit(assign(r07FC, add(r07FC, body.constant(int(1))), 0x01));


         body.instructions = f080B_parent_instructions;
         body.emit(f080B);

         /* END IF */

         body.emit(assign(r07FB, r07FC, 0x01));


      body.instructions = f07FD_parent_instructions;
      body.emit(f07FD);

      /* END IF */

      body.emit(assign(r07F7, add(r07FB, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r080F = less(r07F7, body.constant(int(0)));
      ir_if *f080E = new(mem_ctx) ir_if(operand(r080F).val);
      exec_list *const f080E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f080E->then_instructions;

         ir_expression *const r0810 = neg(r07F7);
         body.emit(assign(r07F5, rshift(r07F3, r0810), 0x01));

         ir_expression *const r0811 = bit_and(r07F7, body.constant(int(31)));
         body.emit(assign(r07F6, lshift(r07F3, r0811), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f080E->else_instructions;

         body.emit(assign(r07F5, lshift(r07F3, r07F7), 0x01));

         body.emit(assign(r07F6, body.constant(0u), 0x01));


      body.instructions = f080E_parent_instructions;
      body.emit(f080E);

      /* END IF */

      body.emit(assign(r07F4, sub(body.constant(int(-31)), r07F7), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f07F8->else_instructions;

      ir_variable *const r0812 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0812, r07F2, 0x01));

      ir_variable *const r0813 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0814 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0814);
      /* IF CONDITION */
      ir_expression *const r0816 = equal(r07F2, body.constant(0u));
      ir_if *f0815 = new(mem_ctx) ir_if(operand(r0816).val);
      exec_list *const f0815_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0815->then_instructions;

         body.emit(assign(r0813, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0815->else_instructions;

         body.emit(assign(r0814, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0818 = bit_and(r07F2, body.constant(4294901760u));
         ir_expression *const r0819 = equal(r0818, body.constant(0u));
         ir_if *f0817 = new(mem_ctx) ir_if(operand(r0819).val);
         exec_list *const f0817_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0817->then_instructions;

            body.emit(assign(r0814, body.constant(int(16)), 0x01));

            body.emit(assign(r0812, lshift(r07F2, body.constant(int(16))), 0x01));


         body.instructions = f0817_parent_instructions;
         body.emit(f0817);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r081B = bit_and(r0812, body.constant(4278190080u));
         ir_expression *const r081C = equal(r081B, body.constant(0u));
         ir_if *f081A = new(mem_ctx) ir_if(operand(r081C).val);
         exec_list *const f081A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f081A->then_instructions;

            body.emit(assign(r0814, add(r0814, body.constant(int(8))), 0x01));

            body.emit(assign(r0812, lshift(r0812, body.constant(int(8))), 0x01));


         body.instructions = f081A_parent_instructions;
         body.emit(f081A);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r081E = bit_and(r0812, body.constant(4026531840u));
         ir_expression *const r081F = equal(r081E, body.constant(0u));
         ir_if *f081D = new(mem_ctx) ir_if(operand(r081F).val);
         exec_list *const f081D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f081D->then_instructions;

            body.emit(assign(r0814, add(r0814, body.constant(int(4))), 0x01));

            body.emit(assign(r0812, lshift(r0812, body.constant(int(4))), 0x01));


         body.instructions = f081D_parent_instructions;
         body.emit(f081D);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0821 = bit_and(r0812, body.constant(3221225472u));
         ir_expression *const r0822 = equal(r0821, body.constant(0u));
         ir_if *f0820 = new(mem_ctx) ir_if(operand(r0822).val);
         exec_list *const f0820_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0820->then_instructions;

            body.emit(assign(r0814, add(r0814, body.constant(int(2))), 0x01));

            body.emit(assign(r0812, lshift(r0812, body.constant(int(2))), 0x01));


         body.instructions = f0820_parent_instructions;
         body.emit(f0820);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0824 = bit_and(r0812, body.constant(2147483648u));
         ir_expression *const r0825 = equal(r0824, body.constant(0u));
         ir_if *f0823 = new(mem_ctx) ir_if(operand(r0825).val);
         exec_list *const f0823_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0823->then_instructions;

            body.emit(assign(r0814, add(r0814, body.constant(int(1))), 0x01));


         body.instructions = f0823_parent_instructions;
         body.emit(f0823);

         /* END IF */

         body.emit(assign(r0813, r0814, 0x01));


      body.instructions = f0815_parent_instructions;
      body.emit(f0815);

      /* END IF */

      body.emit(assign(r07F7, add(r0813, body.constant(int(-11))), 0x01));

      ir_variable *const r0826 = body.make_temp(glsl_type::uint_type, "z1Ptr");
      body.emit(assign(r0826, lshift(r07F3, r07F7), 0x01));

      ir_variable *const r0827 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0829 = equal(r07F7, body.constant(int(0)));
      ir_if *f0828 = new(mem_ctx) ir_if(operand(r0829).val);
      exec_list *const f0828_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0828->then_instructions;

         body.emit(assign(r0827, r07F2, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0828->else_instructions;

         ir_expression *const r082A = lshift(r07F2, r07F7);
         ir_expression *const r082B = neg(r07F7);
         ir_expression *const r082C = bit_and(r082B, body.constant(int(31)));
         ir_expression *const r082D = rshift(r07F3, r082C);
         body.emit(assign(r0827, bit_or(r082A, r082D), 0x01));


      body.instructions = f0828_parent_instructions;
      body.emit(f0828);

      /* END IF */

      body.emit(assign(r07F5, r0827, 0x01));

      body.emit(assign(r07F6, r0826, 0x01));

      body.emit(assign(r07F4, sub(body.constant(int(1)), r07F7), 0x01));


   body.instructions = f07F8_parent_instructions;
   body.emit(f07F8);

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

   ir_variable *const r082E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r082E);
   ir_variable *const r082F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r082F);
   ir_variable *const r0830 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0830, body.constant(true), 0x01));

   ir_variable *const r0831 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0832 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0832);
   ir_variable *const r0833 = new(mem_ctx) ir_variable(glsl_type::int_type, "bExp", ir_var_auto);
   body.emit(r0833);
   ir_variable *const r0834 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0834);
   ir_variable *const r0835 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracHi", ir_var_auto);
   body.emit(r0835);
   ir_variable *const r0836 = new(mem_ctx) ir_variable(glsl_type::uint_type, "bFracLo", ir_var_auto);
   body.emit(r0836);
   ir_variable *const r0837 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0837);
   ir_variable *const r0838 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r0838);
   ir_variable *const r0839 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_auto);
   body.emit(r0839);
   ir_variable *const r083A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac2", ir_var_auto);
   body.emit(r083A);
   ir_variable *const r083B = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r083B);
   ir_variable *const r083C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r083C);
   body.emit(assign(r083C, body.constant(0u), 0x01));

   body.emit(assign(r083B, body.constant(0u), 0x01));

   body.emit(assign(r083A, body.constant(0u), 0x01));

   ir_variable *const r083D = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r083D, swizzle_x(r082E), 0x01));

   body.emit(assign(r0838, r083D, 0x01));

   ir_variable *const r083E = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r083E, bit_and(swizzle_y(r082E), body.constant(1048575u)), 0x01));

   body.emit(assign(r0837, r083E, 0x01));

   ir_variable *const r083F = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r083F, swizzle_x(r082F), 0x01));

   body.emit(assign(r0836, r083F, 0x01));

   ir_variable *const r0840 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0840, bit_and(swizzle_y(r082F), body.constant(1048575u)), 0x01));

   body.emit(assign(r0835, r0840, 0x01));

   ir_variable *const r0841 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0842 = rshift(swizzle_y(r082E), body.constant(int(20)));
   ir_expression *const r0843 = bit_and(r0842, body.constant(2047u));
   body.emit(assign(r0841, expr(ir_unop_u2i, r0843), 0x01));

   body.emit(assign(r0834, r0841, 0x01));

   ir_variable *const r0844 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0845 = rshift(swizzle_y(r082F), body.constant(int(20)));
   ir_expression *const r0846 = bit_and(r0845, body.constant(2047u));
   body.emit(assign(r0844, expr(ir_unop_u2i, r0846), 0x01));

   body.emit(assign(r0833, r0844, 0x01));

   ir_expression *const r0847 = rshift(swizzle_y(r082E), body.constant(int(31)));
   ir_expression *const r0848 = rshift(swizzle_y(r082F), body.constant(int(31)));
   body.emit(assign(r0832, bit_xor(r0847, r0848), 0x01));

   /* IF CONDITION */
   ir_expression *const r084A = equal(r0841, body.constant(int(2047)));
   ir_if *f0849 = new(mem_ctx) ir_if(operand(r084A).val);
   exec_list *const f0849_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0849->then_instructions;

      /* IF CONDITION */
      ir_expression *const r084C = bit_or(r083E, swizzle_x(r082E));
      ir_expression *const r084D = nequal(r084C, body.constant(0u));
      ir_expression *const r084E = equal(r0844, body.constant(int(2047)));
      ir_expression *const r084F = bit_or(r0840, swizzle_x(r082F));
      ir_expression *const r0850 = nequal(r084F, body.constant(0u));
      ir_expression *const r0851 = logic_and(r084E, r0850);
      ir_expression *const r0852 = logic_or(r084D, r0851);
      ir_if *f084B = new(mem_ctx) ir_if(operand(r0852).val);
      exec_list *const f084B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f084B->then_instructions;

         ir_variable *const r0853 = body.make_temp(glsl_type::uvec2_type, "a");
         body.emit(assign(r0853, swizzle_x(r082E), 0x01));

         ir_variable *const r0854 = body.make_temp(glsl_type::uvec2_type, "b");
         body.emit(assign(r0854, swizzle_x(r082F), 0x01));

         ir_variable *const r0855 = body.make_temp(glsl_type::uvec2_type, "return_value");
         ir_variable *const r0856 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
         ir_expression *const r0857 = lshift(swizzle_y(r082F), body.constant(int(1)));
         ir_expression *const r0858 = lequal(body.constant(4292870144u), r0857);
         ir_expression *const r0859 = nequal(swizzle_x(r082F), body.constant(0u));
         ir_expression *const r085A = bit_and(swizzle_y(r082F), body.constant(1048575u));
         ir_expression *const r085B = nequal(r085A, body.constant(0u));
         ir_expression *const r085C = logic_or(r0859, r085B);
         body.emit(assign(r0856, logic_and(r0858, r085C), 0x01));

         body.emit(assign(r0853, bit_or(swizzle_y(r082E), body.constant(524288u)), 0x02));

         body.emit(assign(r0854, bit_or(swizzle_y(r082F), body.constant(524288u)), 0x02));

         /* IF CONDITION */
         ir_expression *const r085E = lshift(swizzle_y(r082E), body.constant(int(1)));
         ir_expression *const r085F = lequal(body.constant(4292870144u), r085E);
         ir_expression *const r0860 = nequal(swizzle_x(r082E), body.constant(0u));
         ir_expression *const r0861 = bit_and(swizzle_y(r082E), body.constant(1048575u));
         ir_expression *const r0862 = nequal(r0861, body.constant(0u));
         ir_expression *const r0863 = logic_or(r0860, r0862);
         ir_expression *const r0864 = logic_and(r085F, r0863);
         ir_if *f085D = new(mem_ctx) ir_if(operand(r0864).val);
         exec_list *const f085D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f085D->then_instructions;

            ir_variable *const r0865 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
            /* IF CONDITION */
            ir_if *f0866 = new(mem_ctx) ir_if(operand(r0856).val);
            exec_list *const f0866_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0866->then_instructions;

               body.emit(assign(r0865, r0854, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0866->else_instructions;

               body.emit(assign(r0865, r0853, 0x03));


            body.instructions = f0866_parent_instructions;
            body.emit(f0866);

            /* END IF */

            body.emit(assign(r0855, r0865, 0x03));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f085D->else_instructions;

            body.emit(assign(r0855, r0854, 0x03));


         body.instructions = f085D_parent_instructions;
         body.emit(f085D);

         /* END IF */

         body.emit(assign(r0831, r0855, 0x03));

         body.emit(assign(r0830, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f084B->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0868 = expr(ir_unop_i2u, r0844);
         ir_expression *const r0869 = bit_or(r0868, r0840);
         ir_expression *const r086A = bit_or(r0869, swizzle_x(r082F));
         ir_expression *const r086B = equal(r086A, body.constant(0u));
         ir_if *f0867 = new(mem_ctx) ir_if(operand(r086B).val);
         exec_list *const f0867_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0867->then_instructions;

            ir_constant_data r086C_data;
            memset(&r086C_data, 0, sizeof(ir_constant_data));
            r086C_data.u[0] = 4294967295;
            r086C_data.u[1] = 4294967295;
            ir_constant *const r086C = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r086C_data);
            body.emit(assign(r0831, r086C, 0x03));

            body.emit(assign(r0830, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0867->else_instructions;

            ir_variable *const r086D = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r086D);
            ir_expression *const r086E = lshift(r0832, body.constant(int(31)));
            body.emit(assign(r086D, add(r086E, body.constant(2146435072u)), 0x02));

            body.emit(assign(r086D, body.constant(0u), 0x01));

            body.emit(assign(r0831, r086D, 0x03));

            body.emit(assign(r0830, body.constant(false), 0x01));


         body.instructions = f0867_parent_instructions;
         body.emit(f0867);

         /* END IF */


      body.instructions = f084B_parent_instructions;
      body.emit(f084B);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0849->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0870 = equal(r0844, body.constant(int(2047)));
      ir_if *f086F = new(mem_ctx) ir_if(operand(r0870).val);
      exec_list *const f086F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f086F->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0872 = bit_or(r0840, swizzle_x(r082F));
         ir_expression *const r0873 = nequal(r0872, body.constant(0u));
         ir_if *f0871 = new(mem_ctx) ir_if(operand(r0873).val);
         exec_list *const f0871_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0871->then_instructions;

            ir_variable *const r0874 = body.make_temp(glsl_type::uvec2_type, "a");
            body.emit(assign(r0874, swizzle_x(r082E), 0x01));

            ir_variable *const r0875 = body.make_temp(glsl_type::uvec2_type, "b");
            body.emit(assign(r0875, swizzle_x(r082F), 0x01));

            ir_variable *const r0876 = body.make_temp(glsl_type::uvec2_type, "return_value");
            ir_variable *const r0877 = body.make_temp(glsl_type::bool_type, "is_nan_retval");
            ir_expression *const r0878 = lshift(swizzle_y(r082F), body.constant(int(1)));
            ir_expression *const r0879 = lequal(body.constant(4292870144u), r0878);
            ir_expression *const r087A = nequal(swizzle_x(r082F), body.constant(0u));
            ir_expression *const r087B = bit_and(swizzle_y(r082F), body.constant(1048575u));
            ir_expression *const r087C = nequal(r087B, body.constant(0u));
            ir_expression *const r087D = logic_or(r087A, r087C);
            body.emit(assign(r0877, logic_and(r0879, r087D), 0x01));

            body.emit(assign(r0874, bit_or(swizzle_y(r082E), body.constant(524288u)), 0x02));

            body.emit(assign(r0875, bit_or(swizzle_y(r082F), body.constant(524288u)), 0x02));

            /* IF CONDITION */
            ir_expression *const r087F = lshift(swizzle_y(r082E), body.constant(int(1)));
            ir_expression *const r0880 = lequal(body.constant(4292870144u), r087F);
            ir_expression *const r0881 = nequal(swizzle_x(r082E), body.constant(0u));
            ir_expression *const r0882 = bit_and(swizzle_y(r082E), body.constant(1048575u));
            ir_expression *const r0883 = nequal(r0882, body.constant(0u));
            ir_expression *const r0884 = logic_or(r0881, r0883);
            ir_expression *const r0885 = logic_and(r0880, r0884);
            ir_if *f087E = new(mem_ctx) ir_if(operand(r0885).val);
            exec_list *const f087E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f087E->then_instructions;

               ir_variable *const r0886 = body.make_temp(glsl_type::uvec2_type, "conditional_tmp");
               /* IF CONDITION */
               ir_if *f0887 = new(mem_ctx) ir_if(operand(r0877).val);
               exec_list *const f0887_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0887->then_instructions;

                  body.emit(assign(r0886, r0875, 0x03));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0887->else_instructions;

                  body.emit(assign(r0886, r0874, 0x03));


               body.instructions = f0887_parent_instructions;
               body.emit(f0887);

               /* END IF */

               body.emit(assign(r0876, r0886, 0x03));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f087E->else_instructions;

               body.emit(assign(r0876, r0875, 0x03));


            body.instructions = f087E_parent_instructions;
            body.emit(f087E);

            /* END IF */

            body.emit(assign(r0831, r0876, 0x03));

            body.emit(assign(r0830, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0871->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0889 = expr(ir_unop_i2u, r0841);
            ir_expression *const r088A = bit_or(r0889, r083E);
            ir_expression *const r088B = bit_or(r088A, swizzle_x(r082E));
            ir_expression *const r088C = equal(r088B, body.constant(0u));
            ir_if *f0888 = new(mem_ctx) ir_if(operand(r088C).val);
            exec_list *const f0888_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0888->then_instructions;

               ir_constant_data r088D_data;
               memset(&r088D_data, 0, sizeof(ir_constant_data));
               r088D_data.u[0] = 4294967295;
               r088D_data.u[1] = 4294967295;
               ir_constant *const r088D = new(mem_ctx) ir_constant(glsl_type::uvec2_type, &r088D_data);
               body.emit(assign(r0831, r088D, 0x03));

               body.emit(assign(r0830, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0888->else_instructions;

               ir_variable *const r088E = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r088E);
               ir_expression *const r088F = lshift(r0832, body.constant(int(31)));
               body.emit(assign(r088E, add(r088F, body.constant(2146435072u)), 0x02));

               body.emit(assign(r088E, body.constant(0u), 0x01));

               body.emit(assign(r0831, r088E, 0x03));

               body.emit(assign(r0830, body.constant(false), 0x01));


            body.instructions = f0888_parent_instructions;
            body.emit(f0888);

            /* END IF */


         body.instructions = f0871_parent_instructions;
         body.emit(f0871);

         /* END IF */


         /* ELSE INSTRUCTIONS */
         body.instructions = &f086F->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0891 = equal(r0841, body.constant(int(0)));
         ir_if *f0890 = new(mem_ctx) ir_if(operand(r0891).val);
         exec_list *const f0890_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0890->then_instructions;

            /* IF CONDITION */
            ir_expression *const r0893 = bit_or(r083E, swizzle_x(r082E));
            ir_expression *const r0894 = equal(r0893, body.constant(0u));
            ir_if *f0892 = new(mem_ctx) ir_if(operand(r0894).val);
            exec_list *const f0892_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0892->then_instructions;

               ir_variable *const r0895 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
               body.emit(r0895);
               body.emit(assign(r0895, lshift(r0832, body.constant(int(31))), 0x02));

               body.emit(assign(r0895, body.constant(0u), 0x01));

               body.emit(assign(r0831, r0895, 0x03));

               body.emit(assign(r0830, body.constant(false), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0892->else_instructions;

               ir_variable *const r0896 = body.make_temp(glsl_type::int_type, "zExpPtr");
               body.emit(assign(r0896, r0841, 0x01));

               ir_variable *const r0897 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
               body.emit(assign(r0897, r083E, 0x01));

               ir_variable *const r0898 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
               body.emit(assign(r0898, r083D, 0x01));

               ir_variable *const r0899 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
               body.emit(r0899);
               /* IF CONDITION */
               ir_expression *const r089B = equal(r083E, body.constant(0u));
               ir_if *f089A = new(mem_ctx) ir_if(operand(r089B).val);
               exec_list *const f089A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f089A->then_instructions;

                  ir_variable *const r089C = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r089C, r083D, 0x01));

                  ir_variable *const r089D = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r089E = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r089E);
                  /* IF CONDITION */
                  ir_expression *const r08A0 = equal(swizzle_x(r082E), body.constant(0u));
                  ir_if *f089F = new(mem_ctx) ir_if(operand(r08A0).val);
                  exec_list *const f089F_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f089F->then_instructions;

                     body.emit(assign(r089D, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f089F->else_instructions;

                     body.emit(assign(r089E, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08A2 = bit_and(swizzle_x(r082E), body.constant(4294901760u));
                     ir_expression *const r08A3 = equal(r08A2, body.constant(0u));
                     ir_if *f08A1 = new(mem_ctx) ir_if(operand(r08A3).val);
                     exec_list *const f08A1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08A1->then_instructions;

                        body.emit(assign(r089E, body.constant(int(16)), 0x01));

                        body.emit(assign(r089C, lshift(swizzle_x(r082E), body.constant(int(16))), 0x01));


                     body.instructions = f08A1_parent_instructions;
                     body.emit(f08A1);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08A5 = bit_and(r089C, body.constant(4278190080u));
                     ir_expression *const r08A6 = equal(r08A5, body.constant(0u));
                     ir_if *f08A4 = new(mem_ctx) ir_if(operand(r08A6).val);
                     exec_list *const f08A4_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08A4->then_instructions;

                        body.emit(assign(r089E, add(r089E, body.constant(int(8))), 0x01));

                        body.emit(assign(r089C, lshift(r089C, body.constant(int(8))), 0x01));


                     body.instructions = f08A4_parent_instructions;
                     body.emit(f08A4);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08A8 = bit_and(r089C, body.constant(4026531840u));
                     ir_expression *const r08A9 = equal(r08A8, body.constant(0u));
                     ir_if *f08A7 = new(mem_ctx) ir_if(operand(r08A9).val);
                     exec_list *const f08A7_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08A7->then_instructions;

                        body.emit(assign(r089E, add(r089E, body.constant(int(4))), 0x01));

                        body.emit(assign(r089C, lshift(r089C, body.constant(int(4))), 0x01));


                     body.instructions = f08A7_parent_instructions;
                     body.emit(f08A7);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08AB = bit_and(r089C, body.constant(3221225472u));
                     ir_expression *const r08AC = equal(r08AB, body.constant(0u));
                     ir_if *f08AA = new(mem_ctx) ir_if(operand(r08AC).val);
                     exec_list *const f08AA_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08AA->then_instructions;

                        body.emit(assign(r089E, add(r089E, body.constant(int(2))), 0x01));

                        body.emit(assign(r089C, lshift(r089C, body.constant(int(2))), 0x01));


                     body.instructions = f08AA_parent_instructions;
                     body.emit(f08AA);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08AE = bit_and(r089C, body.constant(2147483648u));
                     ir_expression *const r08AF = equal(r08AE, body.constant(0u));
                     ir_if *f08AD = new(mem_ctx) ir_if(operand(r08AF).val);
                     exec_list *const f08AD_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08AD->then_instructions;

                        body.emit(assign(r089E, add(r089E, body.constant(int(1))), 0x01));


                     body.instructions = f08AD_parent_instructions;
                     body.emit(f08AD);

                     /* END IF */

                     body.emit(assign(r089D, r089E, 0x01));


                  body.instructions = f089F_parent_instructions;
                  body.emit(f089F);

                  /* END IF */

                  body.emit(assign(r0899, add(r089D, body.constant(int(-11))), 0x01));

                  /* IF CONDITION */
                  ir_expression *const r08B1 = less(r0899, body.constant(int(0)));
                  ir_if *f08B0 = new(mem_ctx) ir_if(operand(r08B1).val);
                  exec_list *const f08B0_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08B0->then_instructions;

                     ir_expression *const r08B2 = neg(r0899);
                     body.emit(assign(r0897, rshift(swizzle_x(r082E), r08B2), 0x01));

                     ir_expression *const r08B3 = bit_and(r0899, body.constant(int(31)));
                     body.emit(assign(r0898, lshift(swizzle_x(r082E), r08B3), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08B0->else_instructions;

                     body.emit(assign(r0897, lshift(swizzle_x(r082E), r0899), 0x01));

                     body.emit(assign(r0898, body.constant(0u), 0x01));


                  body.instructions = f08B0_parent_instructions;
                  body.emit(f08B0);

                  /* END IF */

                  body.emit(assign(r0896, sub(body.constant(int(-31)), r0899), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f089A->else_instructions;

                  ir_variable *const r08B4 = body.make_temp(glsl_type::uint_type, "a");
                  body.emit(assign(r08B4, r083E, 0x01));

                  ir_variable *const r08B5 = body.make_temp(glsl_type::int_type, "return_value");
                  ir_variable *const r08B6 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08B6);
                  /* IF CONDITION */
                  ir_expression *const r08B8 = equal(r083E, body.constant(0u));
                  ir_if *f08B7 = new(mem_ctx) ir_if(operand(r08B8).val);
                  exec_list *const f08B7_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08B7->then_instructions;

                     body.emit(assign(r08B5, body.constant(int(32)), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08B7->else_instructions;

                     body.emit(assign(r08B6, body.constant(int(0)), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08BA = bit_and(r083E, body.constant(4294901760u));
                     ir_expression *const r08BB = equal(r08BA, body.constant(0u));
                     ir_if *f08B9 = new(mem_ctx) ir_if(operand(r08BB).val);
                     exec_list *const f08B9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08B9->then_instructions;

                        body.emit(assign(r08B6, body.constant(int(16)), 0x01));

                        body.emit(assign(r08B4, lshift(r083E, body.constant(int(16))), 0x01));


                     body.instructions = f08B9_parent_instructions;
                     body.emit(f08B9);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08BD = bit_and(r08B4, body.constant(4278190080u));
                     ir_expression *const r08BE = equal(r08BD, body.constant(0u));
                     ir_if *f08BC = new(mem_ctx) ir_if(operand(r08BE).val);
                     exec_list *const f08BC_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08BC->then_instructions;

                        body.emit(assign(r08B6, add(r08B6, body.constant(int(8))), 0x01));

                        body.emit(assign(r08B4, lshift(r08B4, body.constant(int(8))), 0x01));


                     body.instructions = f08BC_parent_instructions;
                     body.emit(f08BC);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08C0 = bit_and(r08B4, body.constant(4026531840u));
                     ir_expression *const r08C1 = equal(r08C0, body.constant(0u));
                     ir_if *f08BF = new(mem_ctx) ir_if(operand(r08C1).val);
                     exec_list *const f08BF_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08BF->then_instructions;

                        body.emit(assign(r08B6, add(r08B6, body.constant(int(4))), 0x01));

                        body.emit(assign(r08B4, lshift(r08B4, body.constant(int(4))), 0x01));


                     body.instructions = f08BF_parent_instructions;
                     body.emit(f08BF);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08C3 = bit_and(r08B4, body.constant(3221225472u));
                     ir_expression *const r08C4 = equal(r08C3, body.constant(0u));
                     ir_if *f08C2 = new(mem_ctx) ir_if(operand(r08C4).val);
                     exec_list *const f08C2_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08C2->then_instructions;

                        body.emit(assign(r08B6, add(r08B6, body.constant(int(2))), 0x01));

                        body.emit(assign(r08B4, lshift(r08B4, body.constant(int(2))), 0x01));


                     body.instructions = f08C2_parent_instructions;
                     body.emit(f08C2);

                     /* END IF */

                     /* IF CONDITION */
                     ir_expression *const r08C6 = bit_and(r08B4, body.constant(2147483648u));
                     ir_expression *const r08C7 = equal(r08C6, body.constant(0u));
                     ir_if *f08C5 = new(mem_ctx) ir_if(operand(r08C7).val);
                     exec_list *const f08C5_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08C5->then_instructions;

                        body.emit(assign(r08B6, add(r08B6, body.constant(int(1))), 0x01));


                     body.instructions = f08C5_parent_instructions;
                     body.emit(f08C5);

                     /* END IF */

                     body.emit(assign(r08B5, r08B6, 0x01));


                  body.instructions = f08B7_parent_instructions;
                  body.emit(f08B7);

                  /* END IF */

                  body.emit(assign(r0899, add(r08B5, body.constant(int(-11))), 0x01));

                  ir_variable *const r08C8 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                  body.emit(assign(r08C8, lshift(swizzle_x(r082E), r0899), 0x01));

                  ir_variable *const r08C9 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                  /* IF CONDITION */
                  ir_expression *const r08CB = equal(r0899, body.constant(int(0)));
                  ir_if *f08CA = new(mem_ctx) ir_if(operand(r08CB).val);
                  exec_list *const f08CA_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08CA->then_instructions;

                     body.emit(assign(r08C9, r083E, 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08CA->else_instructions;

                     ir_expression *const r08CC = lshift(r083E, r0899);
                     ir_expression *const r08CD = neg(r0899);
                     ir_expression *const r08CE = bit_and(r08CD, body.constant(int(31)));
                     ir_expression *const r08CF = rshift(swizzle_x(r082E), r08CE);
                     body.emit(assign(r08C9, bit_or(r08CC, r08CF), 0x01));


                  body.instructions = f08CA_parent_instructions;
                  body.emit(f08CA);

                  /* END IF */

                  body.emit(assign(r0897, r08C9, 0x01));

                  body.emit(assign(r0898, r08C8, 0x01));

                  body.emit(assign(r0896, sub(body.constant(int(1)), r0899), 0x01));


               body.instructions = f089A_parent_instructions;
               body.emit(f089A);

               /* END IF */

               body.emit(assign(r0834, r0896, 0x01));

               body.emit(assign(r0837, r0897, 0x01));

               body.emit(assign(r0838, r0898, 0x01));


            body.instructions = f0892_parent_instructions;
            body.emit(f0892);

            /* END IF */


         body.instructions = f0890_parent_instructions;
         body.emit(f0890);

         /* END IF */

         /* IF CONDITION */
         ir_if *f08D0 = new(mem_ctx) ir_if(operand(r0830).val);
         exec_list *const f08D0_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f08D0->then_instructions;

            /* IF CONDITION */
            ir_expression *const r08D2 = equal(r0844, body.constant(int(0)));
            ir_if *f08D1 = new(mem_ctx) ir_if(operand(r08D2).val);
            exec_list *const f08D1_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f08D1->then_instructions;

               /* IF CONDITION */
               ir_expression *const r08D4 = bit_or(r0840, swizzle_x(r082F));
               ir_expression *const r08D5 = equal(r08D4, body.constant(0u));
               ir_if *f08D3 = new(mem_ctx) ir_if(operand(r08D5).val);
               exec_list *const f08D3_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f08D3->then_instructions;

                  ir_variable *const r08D6 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r08D6);
                  body.emit(assign(r08D6, lshift(r0832, body.constant(int(31))), 0x02));

                  body.emit(assign(r08D6, body.constant(0u), 0x01));

                  body.emit(assign(r0831, r08D6, 0x03));

                  body.emit(assign(r0830, body.constant(false), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f08D3->else_instructions;

                  ir_variable *const r08D7 = body.make_temp(glsl_type::int_type, "zExpPtr");
                  body.emit(assign(r08D7, r0844, 0x01));

                  ir_variable *const r08D8 = body.make_temp(glsl_type::uint_type, "zFrac0Ptr");
                  body.emit(assign(r08D8, r0840, 0x01));

                  ir_variable *const r08D9 = body.make_temp(glsl_type::uint_type, "zFrac1Ptr");
                  body.emit(assign(r08D9, r083F, 0x01));

                  ir_variable *const r08DA = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                  body.emit(r08DA);
                  /* IF CONDITION */
                  ir_expression *const r08DC = equal(r0840, body.constant(0u));
                  ir_if *f08DB = new(mem_ctx) ir_if(operand(r08DC).val);
                  exec_list *const f08DB_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f08DB->then_instructions;

                     ir_variable *const r08DD = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r08DD, r083F, 0x01));

                     ir_variable *const r08DE = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r08DF = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r08DF);
                     /* IF CONDITION */
                     ir_expression *const r08E1 = equal(swizzle_x(r082F), body.constant(0u));
                     ir_if *f08E0 = new(mem_ctx) ir_if(operand(r08E1).val);
                     exec_list *const f08E0_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08E0->then_instructions;

                        body.emit(assign(r08DE, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08E0->else_instructions;

                        body.emit(assign(r08DF, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08E3 = bit_and(swizzle_x(r082F), body.constant(4294901760u));
                        ir_expression *const r08E4 = equal(r08E3, body.constant(0u));
                        ir_if *f08E2 = new(mem_ctx) ir_if(operand(r08E4).val);
                        exec_list *const f08E2_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08E2->then_instructions;

                           body.emit(assign(r08DF, body.constant(int(16)), 0x01));

                           body.emit(assign(r08DD, lshift(swizzle_x(r082F), body.constant(int(16))), 0x01));


                        body.instructions = f08E2_parent_instructions;
                        body.emit(f08E2);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08E6 = bit_and(r08DD, body.constant(4278190080u));
                        ir_expression *const r08E7 = equal(r08E6, body.constant(0u));
                        ir_if *f08E5 = new(mem_ctx) ir_if(operand(r08E7).val);
                        exec_list *const f08E5_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08E5->then_instructions;

                           body.emit(assign(r08DF, add(r08DF, body.constant(int(8))), 0x01));

                           body.emit(assign(r08DD, lshift(r08DD, body.constant(int(8))), 0x01));


                        body.instructions = f08E5_parent_instructions;
                        body.emit(f08E5);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08E9 = bit_and(r08DD, body.constant(4026531840u));
                        ir_expression *const r08EA = equal(r08E9, body.constant(0u));
                        ir_if *f08E8 = new(mem_ctx) ir_if(operand(r08EA).val);
                        exec_list *const f08E8_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08E8->then_instructions;

                           body.emit(assign(r08DF, add(r08DF, body.constant(int(4))), 0x01));

                           body.emit(assign(r08DD, lshift(r08DD, body.constant(int(4))), 0x01));


                        body.instructions = f08E8_parent_instructions;
                        body.emit(f08E8);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08EC = bit_and(r08DD, body.constant(3221225472u));
                        ir_expression *const r08ED = equal(r08EC, body.constant(0u));
                        ir_if *f08EB = new(mem_ctx) ir_if(operand(r08ED).val);
                        exec_list *const f08EB_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08EB->then_instructions;

                           body.emit(assign(r08DF, add(r08DF, body.constant(int(2))), 0x01));

                           body.emit(assign(r08DD, lshift(r08DD, body.constant(int(2))), 0x01));


                        body.instructions = f08EB_parent_instructions;
                        body.emit(f08EB);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08EF = bit_and(r08DD, body.constant(2147483648u));
                        ir_expression *const r08F0 = equal(r08EF, body.constant(0u));
                        ir_if *f08EE = new(mem_ctx) ir_if(operand(r08F0).val);
                        exec_list *const f08EE_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08EE->then_instructions;

                           body.emit(assign(r08DF, add(r08DF, body.constant(int(1))), 0x01));


                        body.instructions = f08EE_parent_instructions;
                        body.emit(f08EE);

                        /* END IF */

                        body.emit(assign(r08DE, r08DF, 0x01));


                     body.instructions = f08E0_parent_instructions;
                     body.emit(f08E0);

                     /* END IF */

                     body.emit(assign(r08DA, add(r08DE, body.constant(int(-11))), 0x01));

                     /* IF CONDITION */
                     ir_expression *const r08F2 = less(r08DA, body.constant(int(0)));
                     ir_if *f08F1 = new(mem_ctx) ir_if(operand(r08F2).val);
                     exec_list *const f08F1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F1->then_instructions;

                        ir_expression *const r08F3 = neg(r08DA);
                        body.emit(assign(r08D8, rshift(swizzle_x(r082F), r08F3), 0x01));

                        ir_expression *const r08F4 = bit_and(r08DA, body.constant(int(31)));
                        body.emit(assign(r08D9, lshift(swizzle_x(r082F), r08F4), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08F1->else_instructions;

                        body.emit(assign(r08D8, lshift(swizzle_x(r082F), r08DA), 0x01));

                        body.emit(assign(r08D9, body.constant(0u), 0x01));


                     body.instructions = f08F1_parent_instructions;
                     body.emit(f08F1);

                     /* END IF */

                     body.emit(assign(r08D7, sub(body.constant(int(-31)), r08DA), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f08DB->else_instructions;

                     ir_variable *const r08F5 = body.make_temp(glsl_type::uint_type, "a");
                     body.emit(assign(r08F5, r0840, 0x01));

                     ir_variable *const r08F6 = body.make_temp(glsl_type::int_type, "return_value");
                     ir_variable *const r08F7 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
                     body.emit(r08F7);
                     /* IF CONDITION */
                     ir_expression *const r08F9 = equal(r0840, body.constant(0u));
                     ir_if *f08F8 = new(mem_ctx) ir_if(operand(r08F9).val);
                     exec_list *const f08F8_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f08F8->then_instructions;

                        body.emit(assign(r08F6, body.constant(int(32)), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f08F8->else_instructions;

                        body.emit(assign(r08F7, body.constant(int(0)), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r08FB = bit_and(r0840, body.constant(4294901760u));
                        ir_expression *const r08FC = equal(r08FB, body.constant(0u));
                        ir_if *f08FA = new(mem_ctx) ir_if(operand(r08FC).val);
                        exec_list *const f08FA_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08FA->then_instructions;

                           body.emit(assign(r08F7, body.constant(int(16)), 0x01));

                           body.emit(assign(r08F5, lshift(r0840, body.constant(int(16))), 0x01));


                        body.instructions = f08FA_parent_instructions;
                        body.emit(f08FA);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r08FE = bit_and(r08F5, body.constant(4278190080u));
                        ir_expression *const r08FF = equal(r08FE, body.constant(0u));
                        ir_if *f08FD = new(mem_ctx) ir_if(operand(r08FF).val);
                        exec_list *const f08FD_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f08FD->then_instructions;

                           body.emit(assign(r08F7, add(r08F7, body.constant(int(8))), 0x01));

                           body.emit(assign(r08F5, lshift(r08F5, body.constant(int(8))), 0x01));


                        body.instructions = f08FD_parent_instructions;
                        body.emit(f08FD);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0901 = bit_and(r08F5, body.constant(4026531840u));
                        ir_expression *const r0902 = equal(r0901, body.constant(0u));
                        ir_if *f0900 = new(mem_ctx) ir_if(operand(r0902).val);
                        exec_list *const f0900_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0900->then_instructions;

                           body.emit(assign(r08F7, add(r08F7, body.constant(int(4))), 0x01));

                           body.emit(assign(r08F5, lshift(r08F5, body.constant(int(4))), 0x01));


                        body.instructions = f0900_parent_instructions;
                        body.emit(f0900);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0904 = bit_and(r08F5, body.constant(3221225472u));
                        ir_expression *const r0905 = equal(r0904, body.constant(0u));
                        ir_if *f0903 = new(mem_ctx) ir_if(operand(r0905).val);
                        exec_list *const f0903_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0903->then_instructions;

                           body.emit(assign(r08F7, add(r08F7, body.constant(int(2))), 0x01));

                           body.emit(assign(r08F5, lshift(r08F5, body.constant(int(2))), 0x01));


                        body.instructions = f0903_parent_instructions;
                        body.emit(f0903);

                        /* END IF */

                        /* IF CONDITION */
                        ir_expression *const r0907 = bit_and(r08F5, body.constant(2147483648u));
                        ir_expression *const r0908 = equal(r0907, body.constant(0u));
                        ir_if *f0906 = new(mem_ctx) ir_if(operand(r0908).val);
                        exec_list *const f0906_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f0906->then_instructions;

                           body.emit(assign(r08F7, add(r08F7, body.constant(int(1))), 0x01));


                        body.instructions = f0906_parent_instructions;
                        body.emit(f0906);

                        /* END IF */

                        body.emit(assign(r08F6, r08F7, 0x01));


                     body.instructions = f08F8_parent_instructions;
                     body.emit(f08F8);

                     /* END IF */

                     body.emit(assign(r08DA, add(r08F6, body.constant(int(-11))), 0x01));

                     ir_variable *const r0909 = body.make_temp(glsl_type::uint_type, "z1Ptr");
                     body.emit(assign(r0909, lshift(swizzle_x(r082F), r08DA), 0x01));

                     ir_variable *const r090A = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                     /* IF CONDITION */
                     ir_expression *const r090C = equal(r08DA, body.constant(int(0)));
                     ir_if *f090B = new(mem_ctx) ir_if(operand(r090C).val);
                     exec_list *const f090B_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f090B->then_instructions;

                        body.emit(assign(r090A, r0840, 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f090B->else_instructions;

                        ir_expression *const r090D = lshift(r0840, r08DA);
                        ir_expression *const r090E = neg(r08DA);
                        ir_expression *const r090F = bit_and(r090E, body.constant(int(31)));
                        ir_expression *const r0910 = rshift(swizzle_x(r082F), r090F);
                        body.emit(assign(r090A, bit_or(r090D, r0910), 0x01));


                     body.instructions = f090B_parent_instructions;
                     body.emit(f090B);

                     /* END IF */

                     body.emit(assign(r08D8, r090A, 0x01));

                     body.emit(assign(r08D9, r0909, 0x01));

                     body.emit(assign(r08D7, sub(body.constant(int(1)), r08DA), 0x01));


                  body.instructions = f08DB_parent_instructions;
                  body.emit(f08DB);

                  /* END IF */

                  body.emit(assign(r0833, r08D7, 0x01));

                  body.emit(assign(r0835, r08D8, 0x01));

                  body.emit(assign(r0836, r08D9, 0x01));


               body.instructions = f08D3_parent_instructions;
               body.emit(f08D3);

               /* END IF */


            body.instructions = f08D1_parent_instructions;
            body.emit(f08D1);

            /* END IF */

            /* IF CONDITION */
            ir_if *f0911 = new(mem_ctx) ir_if(operand(r0830).val);
            exec_list *const f0911_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0911->then_instructions;

               ir_expression *const r0912 = add(r0834, r0833);
               body.emit(assign(r0839, add(r0912, body.constant(int(-1024))), 0x01));

               body.emit(assign(r0837, bit_or(r0837, body.constant(1048576u)), 0x01));

               ir_variable *const r0913 = body.make_temp(glsl_type::uint_type, "z1Ptr");
               body.emit(assign(r0913, lshift(r0836, body.constant(int(12))), 0x01));

               ir_variable *const r0914 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               ir_expression *const r0915 = lshift(r0835, body.constant(int(12)));
               ir_expression *const r0916 = rshift(r0836, body.constant(int(20)));
               body.emit(assign(r0914, bit_or(r0915, r0916), 0x01));

               body.emit(assign(r0835, r0914, 0x01));

               body.emit(assign(r0836, r0913, 0x01));

               ir_variable *const r0917 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0917);
               ir_variable *const r0918 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0918);
               ir_variable *const r0919 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0919);
               ir_variable *const r091A = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r091A, bit_and(r0838, body.constant(65535u)), 0x01));

               ir_variable *const r091B = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r091B, rshift(r0838, body.constant(int(16))), 0x01));

               ir_variable *const r091C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r091C, bit_and(r0913, body.constant(65535u)), 0x01));

               ir_variable *const r091D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r091D, rshift(r0913, body.constant(int(16))), 0x01));

               ir_variable *const r091E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r091E, mul(r091B, r091C), 0x01));

               ir_expression *const r091F = mul(r091A, r091D);
               body.emit(assign(r0918, add(r091F, r091E), 0x01));

               ir_expression *const r0920 = mul(r091B, r091D);
               ir_expression *const r0921 = less(r0918, r091E);
               ir_expression *const r0922 = expr(ir_unop_b2i, r0921);
               ir_expression *const r0923 = expr(ir_unop_i2u, r0922);
               ir_expression *const r0924 = lshift(r0923, body.constant(int(16)));
               ir_expression *const r0925 = rshift(r0918, body.constant(int(16)));
               ir_expression *const r0926 = add(r0924, r0925);
               body.emit(assign(r0917, add(r0920, r0926), 0x01));

               body.emit(assign(r0918, lshift(r0918, body.constant(int(16))), 0x01));

               ir_expression *const r0927 = mul(r091A, r091C);
               body.emit(assign(r0919, add(r0927, r0918), 0x01));

               ir_expression *const r0928 = less(r0919, r0918);
               ir_expression *const r0929 = expr(ir_unop_b2i, r0928);
               ir_expression *const r092A = expr(ir_unop_i2u, r0929);
               body.emit(assign(r0917, add(r0917, r092A), 0x01));

               ir_variable *const r092B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r092B);
               ir_variable *const r092C = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r092C);
               ir_variable *const r092D = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r092D);
               ir_variable *const r092E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r092E, bit_and(r0838, body.constant(65535u)), 0x01));

               ir_variable *const r092F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r092F, rshift(r0838, body.constant(int(16))), 0x01));

               ir_variable *const r0930 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0930, bit_and(r0914, body.constant(65535u)), 0x01));

               ir_variable *const r0931 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0931, rshift(r0914, body.constant(int(16))), 0x01));

               ir_variable *const r0932 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0932, mul(r092F, r0930), 0x01));

               ir_expression *const r0933 = mul(r092E, r0931);
               body.emit(assign(r092C, add(r0933, r0932), 0x01));

               ir_expression *const r0934 = mul(r092F, r0931);
               ir_expression *const r0935 = less(r092C, r0932);
               ir_expression *const r0936 = expr(ir_unop_b2i, r0935);
               ir_expression *const r0937 = expr(ir_unop_i2u, r0936);
               ir_expression *const r0938 = lshift(r0937, body.constant(int(16)));
               ir_expression *const r0939 = rshift(r092C, body.constant(int(16)));
               ir_expression *const r093A = add(r0938, r0939);
               body.emit(assign(r092B, add(r0934, r093A), 0x01));

               body.emit(assign(r092C, lshift(r092C, body.constant(int(16))), 0x01));

               ir_expression *const r093B = mul(r092E, r0930);
               body.emit(assign(r092D, add(r093B, r092C), 0x01));

               ir_expression *const r093C = less(r092D, r092C);
               ir_expression *const r093D = expr(ir_unop_b2i, r093C);
               ir_expression *const r093E = expr(ir_unop_i2u, r093D);
               body.emit(assign(r092B, add(r092B, r093E), 0x01));

               ir_variable *const r093F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r093F, add(r092D, r0917), 0x01));

               ir_variable *const r0940 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0940);
               ir_variable *const r0941 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r0941);
               ir_variable *const r0942 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r0942);
               ir_variable *const r0943 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0943, bit_and(r0837, body.constant(65535u)), 0x01));

               ir_variable *const r0944 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0944, rshift(r0837, body.constant(int(16))), 0x01));

               ir_variable *const r0945 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0945, bit_and(r0914, body.constant(65535u)), 0x01));

               ir_variable *const r0946 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0946, rshift(r0914, body.constant(int(16))), 0x01));

               ir_variable *const r0947 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0947, mul(r0944, r0945), 0x01));

               ir_expression *const r0948 = mul(r0943, r0946);
               body.emit(assign(r0941, add(r0948, r0947), 0x01));

               ir_expression *const r0949 = mul(r0944, r0946);
               ir_expression *const r094A = less(r0941, r0947);
               ir_expression *const r094B = expr(ir_unop_b2i, r094A);
               ir_expression *const r094C = expr(ir_unop_i2u, r094B);
               ir_expression *const r094D = lshift(r094C, body.constant(int(16)));
               ir_expression *const r094E = rshift(r0941, body.constant(int(16)));
               ir_expression *const r094F = add(r094D, r094E);
               body.emit(assign(r0940, add(r0949, r094F), 0x01));

               body.emit(assign(r0941, lshift(r0941, body.constant(int(16))), 0x01));

               ir_expression *const r0950 = mul(r0943, r0945);
               body.emit(assign(r0942, add(r0950, r0941), 0x01));

               ir_expression *const r0951 = less(r0942, r0941);
               ir_expression *const r0952 = expr(ir_unop_b2i, r0951);
               ir_expression *const r0953 = expr(ir_unop_i2u, r0952);
               body.emit(assign(r0940, add(r0940, r0953), 0x01));

               ir_variable *const r0954 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r0955 = less(r093F, r092D);
               ir_expression *const r0956 = expr(ir_unop_b2i, r0955);
               ir_expression *const r0957 = expr(ir_unop_i2u, r0956);
               ir_expression *const r0958 = add(r092B, r0957);
               body.emit(assign(r0954, add(r0942, r0958), 0x01));

               ir_variable *const r0959 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
               body.emit(r0959);
               ir_variable *const r095A = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
               body.emit(r095A);
               ir_variable *const r095B = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
               body.emit(r095B);
               ir_variable *const r095C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095C, bit_and(r0837, body.constant(65535u)), 0x01));

               ir_variable *const r095D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095D, rshift(r0837, body.constant(int(16))), 0x01));

               ir_variable *const r095E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095E, bit_and(r0913, body.constant(65535u)), 0x01));

               ir_variable *const r095F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r095F, rshift(r0913, body.constant(int(16))), 0x01));

               ir_variable *const r0960 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0960, mul(r095D, r095E), 0x01));

               ir_expression *const r0961 = mul(r095C, r095F);
               body.emit(assign(r095A, add(r0961, r0960), 0x01));

               ir_expression *const r0962 = mul(r095D, r095F);
               ir_expression *const r0963 = less(r095A, r0960);
               ir_expression *const r0964 = expr(ir_unop_b2i, r0963);
               ir_expression *const r0965 = expr(ir_unop_i2u, r0964);
               ir_expression *const r0966 = lshift(r0965, body.constant(int(16)));
               ir_expression *const r0967 = rshift(r095A, body.constant(int(16)));
               ir_expression *const r0968 = add(r0966, r0967);
               body.emit(assign(r0959, add(r0962, r0968), 0x01));

               body.emit(assign(r095A, lshift(r095A, body.constant(int(16))), 0x01));

               ir_expression *const r0969 = mul(r095C, r095E);
               body.emit(assign(r095B, add(r0969, r095A), 0x01));

               ir_expression *const r096A = less(r095B, r095A);
               ir_expression *const r096B = expr(ir_unop_b2i, r096A);
               ir_expression *const r096C = expr(ir_unop_i2u, r096B);
               body.emit(assign(r0959, add(r0959, r096C), 0x01));

               ir_variable *const r096D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r096D, add(r095B, r093F), 0x01));

               ir_variable *const r096E = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               ir_expression *const r096F = less(r096D, r095B);
               ir_expression *const r0970 = expr(ir_unop_b2i, r096F);
               ir_expression *const r0971 = expr(ir_unop_i2u, r0970);
               ir_expression *const r0972 = add(r0959, r0971);
               body.emit(assign(r096E, add(r0954, r0972), 0x01));

               ir_variable *const r0973 = body.make_temp(glsl_type::uint_type, "z0Ptr");
               ir_variable *const r0974 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
               body.emit(assign(r0974, add(r096E, r0838), 0x01));

               ir_expression *const r0975 = less(r0954, r0942);
               ir_expression *const r0976 = expr(ir_unop_b2i, r0975);
               ir_expression *const r0977 = expr(ir_unop_i2u, r0976);
               ir_expression *const r0978 = add(r0940, r0977);
               ir_expression *const r0979 = less(r096E, r0954);
               ir_expression *const r097A = expr(ir_unop_b2i, r0979);
               ir_expression *const r097B = expr(ir_unop_i2u, r097A);
               ir_expression *const r097C = add(r0978, r097B);
               ir_expression *const r097D = add(r097C, r0837);
               ir_expression *const r097E = less(r0974, r096E);
               ir_expression *const r097F = expr(ir_unop_b2i, r097E);
               ir_expression *const r0980 = expr(ir_unop_i2u, r097F);
               body.emit(assign(r0973, add(r097D, r0980), 0x01));

               body.emit(assign(r083C, r0973, 0x01));

               body.emit(assign(r083B, r0974, 0x01));

               ir_expression *const r0981 = nequal(r0919, body.constant(0u));
               ir_expression *const r0982 = expr(ir_unop_b2i, r0981);
               ir_expression *const r0983 = expr(ir_unop_i2u, r0982);
               body.emit(assign(r083A, bit_or(r096D, r0983), 0x01));

               /* IF CONDITION */
               ir_expression *const r0985 = lequal(body.constant(2097152u), r0973);
               ir_if *f0984 = new(mem_ctx) ir_if(operand(r0985).val);
               exec_list *const f0984_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0984->then_instructions;

                  ir_variable *const r0986 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                  body.emit(r0986);
                  body.emit(assign(r0986, lshift(r0974, body.constant(int(31))), 0x01));

                  ir_expression *const r0987 = nequal(r083A, body.constant(0u));
                  ir_expression *const r0988 = expr(ir_unop_b2i, r0987);
                  ir_expression *const r0989 = expr(ir_unop_i2u, r0988);
                  body.emit(assign(r0986, bit_or(r0986, r0989), 0x01));

                  body.emit(assign(r083C, rshift(r0973, body.constant(int(1))), 0x01));

                  ir_expression *const r098A = lshift(r0973, body.constant(int(31)));
                  ir_expression *const r098B = rshift(r0974, body.constant(int(1)));
                  body.emit(assign(r083B, bit_or(r098A, r098B), 0x01));

                  body.emit(assign(r083A, r0986, 0x01));

                  body.emit(assign(r0839, add(r0839, body.constant(int(1))), 0x01));


               body.instructions = f0984_parent_instructions;
               body.emit(f0984);

               /* END IF */

               ir_variable *const r098C = body.make_temp(glsl_type::int_type, "zExp");
               body.emit(assign(r098C, r0839, 0x01));

               ir_variable *const r098D = body.make_temp(glsl_type::uint_type, "zFrac0");
               body.emit(assign(r098D, r083C, 0x01));

               ir_variable *const r098E = body.make_temp(glsl_type::uint_type, "zFrac1");
               body.emit(assign(r098E, r083B, 0x01));

               ir_variable *const r098F = body.make_temp(glsl_type::uint_type, "zFrac2");
               body.emit(assign(r098F, r083A, 0x01));

               ir_variable *const r0990 = body.make_temp(glsl_type::bool_type, "execute_flag");
               body.emit(assign(r0990, body.constant(true), 0x01));

               ir_variable *const r0991 = body.make_temp(glsl_type::uvec2_type, "return_value");
               ir_variable *const r0992 = new(mem_ctx) ir_variable(glsl_type::bool_type, "increment", ir_var_auto);
               body.emit(r0992);
               ir_expression *const r0993 = expr(ir_unop_u2i, r083A);
               body.emit(assign(r0992, less(r0993, body.constant(int(0))), 0x01));

               /* IF CONDITION */
               ir_expression *const r0995 = lequal(body.constant(int(2045)), r0839);
               ir_if *f0994 = new(mem_ctx) ir_if(operand(r0995).val);
               exec_list *const f0994_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0994->then_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0997 = less(body.constant(int(2045)), r0839);
                  ir_expression *const r0998 = equal(r0839, body.constant(int(2045)));
                  ir_expression *const r0999 = equal(body.constant(2097151u), r083C);
                  ir_expression *const r099A = equal(body.constant(4294967295u), r083B);
                  ir_expression *const r099B = logic_and(r0999, r099A);
                  ir_expression *const r099C = logic_and(r0998, r099B);
                  ir_expression *const r099D = logic_and(r099C, r0992);
                  ir_expression *const r099E = logic_or(r0997, r099D);
                  ir_if *f0996 = new(mem_ctx) ir_if(operand(r099E).val);
                  exec_list *const f0996_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0996->then_instructions;

                     ir_variable *const r099F = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                     body.emit(r099F);
                     ir_expression *const r09A0 = lshift(r0832, body.constant(int(31)));
                     body.emit(assign(r099F, add(r09A0, body.constant(2146435072u)), 0x02));

                     body.emit(assign(r099F, body.constant(0u), 0x01));

                     body.emit(assign(r0991, r099F, 0x03));

                     body.emit(assign(r0990, body.constant(false), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0996->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09A2 = less(r0839, body.constant(int(0)));
                     ir_if *f09A1 = new(mem_ctx) ir_if(operand(r09A2).val);
                     exec_list *const f09A1_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09A1->then_instructions;

                        ir_variable *const r09A3 = body.make_temp(glsl_type::uint_type, "a2");
                        body.emit(assign(r09A3, r083A, 0x01));

                        ir_variable *const r09A4 = body.make_temp(glsl_type::int_type, "count");
                        body.emit(assign(r09A4, neg(r0839), 0x01));

                        ir_variable *const r09A5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2", ir_var_auto);
                        body.emit(r09A5);
                        ir_variable *const r09A6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
                        body.emit(r09A6);
                        ir_variable *const r09A7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
                        body.emit(r09A7);
                        ir_variable *const r09A8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
                        ir_expression *const r09A9 = neg(r09A4);
                        body.emit(assign(r09A8, bit_and(r09A9, body.constant(int(31))), 0x01));

                        /* IF CONDITION */
                        ir_expression *const r09AB = equal(r09A4, body.constant(int(0)));
                        ir_if *f09AA = new(mem_ctx) ir_if(operand(r09AB).val);
                        exec_list *const f09AA_parent_instructions = body.instructions;

                           /* THEN INSTRUCTIONS */
                           body.instructions = &f09AA->then_instructions;

                           body.emit(assign(r09A5, r083A, 0x01));

                           body.emit(assign(r09A6, r083B, 0x01));

                           body.emit(assign(r09A7, r083C, 0x01));


                           /* ELSE INSTRUCTIONS */
                           body.instructions = &f09AA->else_instructions;

                           /* IF CONDITION */
                           ir_expression *const r09AD = less(r09A4, body.constant(int(32)));
                           ir_if *f09AC = new(mem_ctx) ir_if(operand(r09AD).val);
                           exec_list *const f09AC_parent_instructions = body.instructions;

                              /* THEN INSTRUCTIONS */
                              body.instructions = &f09AC->then_instructions;

                              body.emit(assign(r09A5, lshift(r083B, r09A8), 0x01));

                              ir_expression *const r09AE = lshift(r083C, r09A8);
                              ir_expression *const r09AF = rshift(r083B, r09A4);
                              body.emit(assign(r09A6, bit_or(r09AE, r09AF), 0x01));

                              body.emit(assign(r09A7, rshift(r083C, r09A4), 0x01));


                              /* ELSE INSTRUCTIONS */
                              body.instructions = &f09AC->else_instructions;

                              /* IF CONDITION */
                              ir_expression *const r09B1 = equal(r09A4, body.constant(int(32)));
                              ir_if *f09B0 = new(mem_ctx) ir_if(operand(r09B1).val);
                              exec_list *const f09B0_parent_instructions = body.instructions;

                                 /* THEN INSTRUCTIONS */
                                 body.instructions = &f09B0->then_instructions;

                                 body.emit(assign(r09A5, r083B, 0x01));

                                 body.emit(assign(r09A6, r083C, 0x01));


                                 /* ELSE INSTRUCTIONS */
                                 body.instructions = &f09B0->else_instructions;

                                 body.emit(assign(r09A3, bit_or(r083A, r083B), 0x01));

                                 /* IF CONDITION */
                                 ir_expression *const r09B3 = less(r09A4, body.constant(int(64)));
                                 ir_if *f09B2 = new(mem_ctx) ir_if(operand(r09B3).val);
                                 exec_list *const f09B2_parent_instructions = body.instructions;

                                    /* THEN INSTRUCTIONS */
                                    body.instructions = &f09B2->then_instructions;

                                    body.emit(assign(r09A5, lshift(r083C, r09A8), 0x01));

                                    ir_expression *const r09B4 = bit_and(r09A4, body.constant(int(31)));
                                    body.emit(assign(r09A6, rshift(r083C, r09B4), 0x01));


                                    /* ELSE INSTRUCTIONS */
                                    body.instructions = &f09B2->else_instructions;

                                    ir_variable *const r09B5 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
                                    /* IF CONDITION */
                                    ir_expression *const r09B7 = equal(r09A4, body.constant(int(64)));
                                    ir_if *f09B6 = new(mem_ctx) ir_if(operand(r09B7).val);
                                    exec_list *const f09B6_parent_instructions = body.instructions;

                                       /* THEN INSTRUCTIONS */
                                       body.instructions = &f09B6->then_instructions;

                                       body.emit(assign(r09B5, r083C, 0x01));


                                       /* ELSE INSTRUCTIONS */
                                       body.instructions = &f09B6->else_instructions;

                                       ir_expression *const r09B8 = nequal(r083C, body.constant(0u));
                                       ir_expression *const r09B9 = expr(ir_unop_b2i, r09B8);
                                       body.emit(assign(r09B5, expr(ir_unop_i2u, r09B9), 0x01));


                                    body.instructions = f09B6_parent_instructions;
                                    body.emit(f09B6);

                                    /* END IF */

                                    body.emit(assign(r09A5, r09B5, 0x01));

                                    body.emit(assign(r09A6, body.constant(0u), 0x01));


                                 body.instructions = f09B2_parent_instructions;
                                 body.emit(f09B2);

                                 /* END IF */


                              body.instructions = f09B0_parent_instructions;
                              body.emit(f09B0);

                              /* END IF */

                              body.emit(assign(r09A7, body.constant(0u), 0x01));


                           body.instructions = f09AC_parent_instructions;
                           body.emit(f09AC);

                           /* END IF */

                           ir_expression *const r09BA = nequal(r09A3, body.constant(0u));
                           ir_expression *const r09BB = expr(ir_unop_b2i, r09BA);
                           ir_expression *const r09BC = expr(ir_unop_i2u, r09BB);
                           body.emit(assign(r09A5, bit_or(r09A5, r09BC), 0x01));


                        body.instructions = f09AA_parent_instructions;
                        body.emit(f09AA);

                        /* END IF */

                        body.emit(assign(r098D, r09A7, 0x01));

                        body.emit(assign(r098E, r09A6, 0x01));

                        body.emit(assign(r098F, r09A5, 0x01));

                        body.emit(assign(r098C, body.constant(int(0)), 0x01));

                        body.emit(assign(r0992, less(r09A5, body.constant(0u)), 0x01));


                     body.instructions = f09A1_parent_instructions;
                     body.emit(f09A1);

                     /* END IF */


                  body.instructions = f0996_parent_instructions;
                  body.emit(f0996);

                  /* END IF */


               body.instructions = f0994_parent_instructions;
               body.emit(f0994);

               /* END IF */

               /* IF CONDITION */
               ir_if *f09BD = new(mem_ctx) ir_if(operand(r0990).val);
               exec_list *const f09BD_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f09BD->then_instructions;

                  /* IF CONDITION */
                  ir_if *f09BE = new(mem_ctx) ir_if(operand(r0992).val);
                  exec_list *const f09BE_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f09BE->then_instructions;

                     ir_variable *const r09BF = body.make_temp(glsl_type::uint_type, "assignment_tmp");
                     body.emit(assign(r09BF, add(r098E, body.constant(1u)), 0x01));

                     ir_expression *const r09C0 = less(r09BF, r098E);
                     ir_expression *const r09C1 = expr(ir_unop_b2i, r09C0);
                     ir_expression *const r09C2 = expr(ir_unop_i2u, r09C1);
                     body.emit(assign(r098D, add(r098D, r09C2), 0x01));

                     ir_expression *const r09C3 = equal(r098F, body.constant(0u));
                     ir_expression *const r09C4 = expr(ir_unop_b2i, r09C3);
                     ir_expression *const r09C5 = expr(ir_unop_i2u, r09C4);
                     ir_expression *const r09C6 = add(r098F, r09C5);
                     ir_expression *const r09C7 = bit_and(r09C6, body.constant(1u));
                     ir_expression *const r09C8 = expr(ir_unop_bit_not, r09C7);
                     body.emit(assign(r098E, bit_and(r09BF, r09C8), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f09BE->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r09CA = bit_or(r098D, r098E);
                     ir_expression *const r09CB = equal(r09CA, body.constant(0u));
                     ir_if *f09C9 = new(mem_ctx) ir_if(operand(r09CB).val);
                     exec_list *const f09C9_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f09C9->then_instructions;

                        body.emit(assign(r098C, body.constant(int(0)), 0x01));


                     body.instructions = f09C9_parent_instructions;
                     body.emit(f09C9);

                     /* END IF */


                  body.instructions = f09BE_parent_instructions;
                  body.emit(f09BE);

                  /* END IF */

                  ir_variable *const r09CC = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
                  body.emit(r09CC);
                  ir_expression *const r09CD = lshift(r0832, body.constant(int(31)));
                  ir_expression *const r09CE = expr(ir_unop_i2u, r098C);
                  ir_expression *const r09CF = lshift(r09CE, body.constant(int(20)));
                  ir_expression *const r09D0 = add(r09CD, r09CF);
                  body.emit(assign(r09CC, add(r09D0, r098D), 0x02));

                  body.emit(assign(r09CC, r098E, 0x01));

                  body.emit(assign(r0991, r09CC, 0x03));

                  body.emit(assign(r0990, body.constant(false), 0x01));


               body.instructions = f09BD_parent_instructions;
               body.emit(f09BD);

               /* END IF */

               body.emit(assign(r0831, r0991, 0x03));

               body.emit(assign(r0830, body.constant(false), 0x01));


            body.instructions = f0911_parent_instructions;
            body.emit(f0911);

            /* END IF */


         body.instructions = f08D0_parent_instructions;
         body.emit(f08D0);

         /* END IF */


      body.instructions = f086F_parent_instructions;
      body.emit(f086F);

      /* END IF */


   body.instructions = f0849_parent_instructions;
   body.emit(f0849);

   /* END IF */

   body.emit(ret(r0831));

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

   ir_variable *const r09D1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r09D1);
   ir_variable *const r09D2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r09D2);
   ir_variable *const r09D3 = new(mem_ctx) ir_variable(glsl_type::int_type, "count", ir_var_function_in);
   sig_parameters.push_tail(r09D3);
   ir_variable *const r09D4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09D4);
   ir_variable *const r09D5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r09D5);
   ir_variable *const r09D6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r09D6);
   ir_variable *const r09D7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r09D7);
   ir_variable *const r09D8 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r09D9 = neg(r09D3);
   body.emit(assign(r09D8, bit_and(r09D9, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r09DB = equal(r09D3, body.constant(int(0)));
   ir_if *f09DA = new(mem_ctx) ir_if(operand(r09DB).val);
   exec_list *const f09DA_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09DA->then_instructions;

      body.emit(assign(r09D6, r09D2, 0x01));

      body.emit(assign(r09D7, r09D1, 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09DA->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09DD = less(r09D3, body.constant(int(32)));
      ir_if *f09DC = new(mem_ctx) ir_if(operand(r09DD).val);
      exec_list *const f09DC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09DC->then_instructions;

         ir_expression *const r09DE = lshift(r09D1, r09D8);
         ir_expression *const r09DF = rshift(r09D2, r09D3);
         body.emit(assign(r09D6, bit_or(r09DE, r09DF), 0x01));

         body.emit(assign(r09D7, rshift(r09D1, r09D3), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09DC->else_instructions;

         ir_variable *const r09E0 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r09E2 = less(r09D3, body.constant(int(64)));
         ir_if *f09E1 = new(mem_ctx) ir_if(operand(r09E2).val);
         exec_list *const f09E1_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09E1->then_instructions;

            ir_expression *const r09E3 = bit_and(r09D3, body.constant(int(31)));
            body.emit(assign(r09E0, rshift(r09D1, r09E3), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f09E1->else_instructions;

            body.emit(assign(r09E0, body.constant(0u), 0x01));


         body.instructions = f09E1_parent_instructions;
         body.emit(f09E1);

         /* END IF */

         body.emit(assign(r09D6, r09E0, 0x01));

         body.emit(assign(r09D7, body.constant(0u), 0x01));


      body.instructions = f09DC_parent_instructions;
      body.emit(f09DC);

      /* END IF */


   body.instructions = f09DA_parent_instructions;
   body.emit(f09DA);

   /* END IF */

   body.emit(assign(r09D5, r09D6, 0x01));

   body.emit(assign(r09D4, r09D7, 0x01));

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

   ir_variable *const r09E4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r09E4);
   ir_variable *const r09E5 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r09E6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r09E6);
   ir_variable *const r09E7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracLo", ir_var_auto);
   body.emit(r09E7);
   ir_variable *const r09E8 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r09E8, swizzle_x(r09E4), 0x01));

   body.emit(assign(r09E7, r09E8, 0x01));

   ir_variable *const r09E9 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r09E9, bit_and(swizzle_y(r09E4), body.constant(1048575u)), 0x01));

   body.emit(assign(r09E6, r09E9, 0x01));

   ir_variable *const r09EA = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r09EB = rshift(swizzle_y(r09E4), body.constant(int(20)));
   ir_expression *const r09EC = bit_and(r09EB, body.constant(2047u));
   body.emit(assign(r09EA, expr(ir_unop_u2i, r09EC), 0x01));

   ir_variable *const r09ED = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r09ED, rshift(swizzle_y(r09E4), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r09EF = nequal(r09ED, body.constant(0u));
   ir_if *f09EE = new(mem_ctx) ir_if(operand(r09EF).val);
   exec_list *const f09EE_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f09EE->then_instructions;

      body.emit(assign(r09E5, body.constant(0u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f09EE->else_instructions;

      /* IF CONDITION */
      ir_expression *const r09F1 = equal(r09EA, body.constant(int(2047)));
      ir_expression *const r09F2 = bit_or(r09E9, swizzle_x(r09E4));
      ir_expression *const r09F3 = nequal(r09F2, body.constant(0u));
      ir_expression *const r09F4 = logic_and(r09F1, r09F3);
      ir_if *f09F0 = new(mem_ctx) ir_if(operand(r09F4).val);
      exec_list *const f09F0_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f09F0->then_instructions;

         body.emit(assign(r09E5, body.constant(4294967295u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f09F0->else_instructions;

         /* IF CONDITION */
         ir_expression *const r09F6 = nequal(r09EA, body.constant(int(0)));
         ir_if *f09F5 = new(mem_ctx) ir_if(operand(r09F6).val);
         exec_list *const f09F5_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09F5->then_instructions;

            body.emit(assign(r09E6, bit_or(r09E9, body.constant(1048576u)), 0x01));


         body.instructions = f09F5_parent_instructions;
         body.emit(f09F5);

         /* END IF */

         ir_variable *const r09F7 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r09F7, sub(body.constant(int(1063)), r09EA), 0x01));

         /* IF CONDITION */
         ir_expression *const r09F9 = less(body.constant(int(0)), r09F7);
         ir_if *f09F8 = new(mem_ctx) ir_if(operand(r09F9).val);
         exec_list *const f09F8_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f09F8->then_instructions;

            ir_variable *const r09FA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r09FA);
            ir_variable *const r09FB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r09FB);
            ir_variable *const r09FC = body.make_temp(glsl_type::int_type, "assignment_tmp");
            ir_expression *const r09FD = neg(r09F7);
            body.emit(assign(r09FC, bit_and(r09FD, body.constant(int(31))), 0x01));

            /* IF CONDITION */
            ir_expression *const r09FF = equal(r09F7, body.constant(int(0)));
            ir_if *f09FE = new(mem_ctx) ir_if(operand(r09FF).val);
            exec_list *const f09FE_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f09FE->then_instructions;

               body.emit(assign(r09FA, r09E8, 0x01));

               body.emit(assign(r09FB, r09E6, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f09FE->else_instructions;

               /* IF CONDITION */
               ir_expression *const r0A01 = less(r09F7, body.constant(int(32)));
               ir_if *f0A00 = new(mem_ctx) ir_if(operand(r0A01).val);
               exec_list *const f0A00_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A00->then_instructions;

                  ir_expression *const r0A02 = lshift(r09E6, r09FC);
                  ir_expression *const r0A03 = rshift(swizzle_x(r09E4), r09F7);
                  ir_expression *const r0A04 = bit_or(r0A02, r0A03);
                  ir_expression *const r0A05 = lshift(swizzle_x(r09E4), r09FC);
                  ir_expression *const r0A06 = nequal(r0A05, body.constant(0u));
                  ir_expression *const r0A07 = expr(ir_unop_b2i, r0A06);
                  ir_expression *const r0A08 = expr(ir_unop_i2u, r0A07);
                  body.emit(assign(r09FA, bit_or(r0A04, r0A08), 0x01));

                  body.emit(assign(r09FB, rshift(r09E6, r09F7), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A00->else_instructions;

                  /* IF CONDITION */
                  ir_expression *const r0A0A = equal(r09F7, body.constant(int(32)));
                  ir_if *f0A09 = new(mem_ctx) ir_if(operand(r0A0A).val);
                  exec_list *const f0A09_parent_instructions = body.instructions;

                     /* THEN INSTRUCTIONS */
                     body.instructions = &f0A09->then_instructions;

                     ir_expression *const r0A0B = nequal(swizzle_x(r09E4), body.constant(0u));
                     ir_expression *const r0A0C = expr(ir_unop_b2i, r0A0B);
                     ir_expression *const r0A0D = expr(ir_unop_i2u, r0A0C);
                     body.emit(assign(r09FA, bit_or(r09E6, r0A0D), 0x01));


                     /* ELSE INSTRUCTIONS */
                     body.instructions = &f0A09->else_instructions;

                     /* IF CONDITION */
                     ir_expression *const r0A0F = less(r09F7, body.constant(int(64)));
                     ir_if *f0A0E = new(mem_ctx) ir_if(operand(r0A0F).val);
                     exec_list *const f0A0E_parent_instructions = body.instructions;

                        /* THEN INSTRUCTIONS */
                        body.instructions = &f0A0E->then_instructions;

                        ir_expression *const r0A10 = bit_and(r09F7, body.constant(int(31)));
                        ir_expression *const r0A11 = rshift(r09E6, r0A10);
                        ir_expression *const r0A12 = lshift(r09E6, r09FC);
                        ir_expression *const r0A13 = bit_or(r0A12, swizzle_x(r09E4));
                        ir_expression *const r0A14 = nequal(r0A13, body.constant(0u));
                        ir_expression *const r0A15 = expr(ir_unop_b2i, r0A14);
                        ir_expression *const r0A16 = expr(ir_unop_i2u, r0A15);
                        body.emit(assign(r09FA, bit_or(r0A11, r0A16), 0x01));


                        /* ELSE INSTRUCTIONS */
                        body.instructions = &f0A0E->else_instructions;

                        ir_expression *const r0A17 = bit_or(r09E6, swizzle_x(r09E4));
                        ir_expression *const r0A18 = nequal(r0A17, body.constant(0u));
                        ir_expression *const r0A19 = expr(ir_unop_b2i, r0A18);
                        body.emit(assign(r09FA, expr(ir_unop_i2u, r0A19), 0x01));


                     body.instructions = f0A0E_parent_instructions;
                     body.emit(f0A0E);

                     /* END IF */


                  body.instructions = f0A09_parent_instructions;
                  body.emit(f0A09);

                  /* END IF */

                  body.emit(assign(r09FB, body.constant(0u), 0x01));


               body.instructions = f0A00_parent_instructions;
               body.emit(f0A00);

               /* END IF */


            body.instructions = f09FE_parent_instructions;
            body.emit(f09FE);

            /* END IF */

            body.emit(assign(r09E6, r09FB, 0x01));

            body.emit(assign(r09E7, r09FA, 0x01));


         body.instructions = f09F8_parent_instructions;
         body.emit(f09F8);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A1B = bit_and(r09E6, body.constant(4294963200u));
         ir_expression *const r0A1C = nequal(r0A1B, body.constant(0u));
         ir_if *f0A1A = new(mem_ctx) ir_if(operand(r0A1C).val);
         exec_list *const f0A1A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A1A->then_instructions;

            ir_variable *const r0A1D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A1F = nequal(r09ED, body.constant(0u));
            ir_if *f0A1E = new(mem_ctx) ir_if(operand(r0A1F).val);
            exec_list *const f0A1E_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A1E->then_instructions;

               body.emit(assign(r0A1D, body.constant(0u), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A1E->else_instructions;

               body.emit(assign(r0A1D, body.constant(4294967295u), 0x01));


            body.instructions = f0A1E_parent_instructions;
            body.emit(f0A1E);

            /* END IF */

            body.emit(assign(r09E5, r0A1D, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A1A->else_instructions;

            ir_variable *const r0A20 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
            body.emit(r0A20);
            ir_variable *const r0A21 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
            body.emit(r0A21);
            ir_expression *const r0A22 = lshift(r09E6, body.constant(int(20)));
            ir_expression *const r0A23 = rshift(r09E7, body.constant(int(12)));
            body.emit(assign(r0A20, bit_or(r0A22, r0A23), 0x01));

            body.emit(assign(r0A21, rshift(r09E6, body.constant(int(12))), 0x01));

            /* IF CONDITION */
            ir_expression *const r0A25 = nequal(r09ED, body.constant(0u));
            ir_expression *const r0A26 = nequal(r0A20, body.constant(0u));
            ir_expression *const r0A27 = logic_and(r0A25, r0A26);
            ir_if *f0A24 = new(mem_ctx) ir_if(operand(r0A27).val);
            exec_list *const f0A24_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A24->then_instructions;

               ir_variable *const r0A28 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0A2A = nequal(r09ED, body.constant(0u));
               ir_if *f0A29 = new(mem_ctx) ir_if(operand(r0A2A).val);
               exec_list *const f0A29_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0A29->then_instructions;

                  body.emit(assign(r0A28, body.constant(0u), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0A29->else_instructions;

                  body.emit(assign(r0A28, body.constant(4294967295u), 0x01));


               body.instructions = f0A29_parent_instructions;
               body.emit(f0A29);

               /* END IF */

               body.emit(assign(r09E5, r0A28, 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A24->else_instructions;

               body.emit(assign(r09E5, r0A20, 0x01));


            body.instructions = f0A24_parent_instructions;
            body.emit(f0A24);

            /* END IF */


         body.instructions = f0A1A_parent_instructions;
         body.emit(f0A1A);

         /* END IF */


      body.instructions = f09F0_parent_instructions;
      body.emit(f09F0);

      /* END IF */


   body.instructions = f09EE_parent_instructions;
   body.emit(f09EE);

   /* END IF */

   body.emit(ret(r09E5));

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

   ir_variable *const r0A2B = new(mem_ctx) ir_variable(glsl_type::uint_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A2B);
   ir_variable *const r0A2C = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A2D = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLow", ir_var_auto);
   body.emit(r0A2D);
   ir_variable *const r0A2E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHigh", ir_var_auto);
   body.emit(r0A2E);
   /* IF CONDITION */
   ir_expression *const r0A30 = equal(r0A2B, body.constant(0u));
   ir_if *f0A2F = new(mem_ctx) ir_if(operand(r0A30).val);
   exec_list *const f0A2F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A2F->then_instructions;

      body.emit(assign(r0A2C, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A2F->else_instructions;

      ir_variable *const r0A31 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0A31, r0A2B, 0x01));

      ir_variable *const r0A32 = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0A33 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0A33);
      /* IF CONDITION */
      ir_expression *const r0A35 = equal(r0A2B, body.constant(0u));
      ir_if *f0A34 = new(mem_ctx) ir_if(operand(r0A35).val);
      exec_list *const f0A34_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A34->then_instructions;

         body.emit(assign(r0A32, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A34->else_instructions;

         body.emit(assign(r0A33, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A37 = bit_and(r0A2B, body.constant(4294901760u));
         ir_expression *const r0A38 = equal(r0A37, body.constant(0u));
         ir_if *f0A36 = new(mem_ctx) ir_if(operand(r0A38).val);
         exec_list *const f0A36_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A36->then_instructions;

            body.emit(assign(r0A33, body.constant(int(16)), 0x01));

            body.emit(assign(r0A31, lshift(r0A2B, body.constant(int(16))), 0x01));


         body.instructions = f0A36_parent_instructions;
         body.emit(f0A36);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A3A = bit_and(r0A31, body.constant(4278190080u));
         ir_expression *const r0A3B = equal(r0A3A, body.constant(0u));
         ir_if *f0A39 = new(mem_ctx) ir_if(operand(r0A3B).val);
         exec_list *const f0A39_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A39->then_instructions;

            body.emit(assign(r0A33, add(r0A33, body.constant(int(8))), 0x01));

            body.emit(assign(r0A31, lshift(r0A31, body.constant(int(8))), 0x01));


         body.instructions = f0A39_parent_instructions;
         body.emit(f0A39);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A3D = bit_and(r0A31, body.constant(4026531840u));
         ir_expression *const r0A3E = equal(r0A3D, body.constant(0u));
         ir_if *f0A3C = new(mem_ctx) ir_if(operand(r0A3E).val);
         exec_list *const f0A3C_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A3C->then_instructions;

            body.emit(assign(r0A33, add(r0A33, body.constant(int(4))), 0x01));

            body.emit(assign(r0A31, lshift(r0A31, body.constant(int(4))), 0x01));


         body.instructions = f0A3C_parent_instructions;
         body.emit(f0A3C);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A40 = bit_and(r0A31, body.constant(3221225472u));
         ir_expression *const r0A41 = equal(r0A40, body.constant(0u));
         ir_if *f0A3F = new(mem_ctx) ir_if(operand(r0A41).val);
         exec_list *const f0A3F_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A3F->then_instructions;

            body.emit(assign(r0A33, add(r0A33, body.constant(int(2))), 0x01));

            body.emit(assign(r0A31, lshift(r0A31, body.constant(int(2))), 0x01));


         body.instructions = f0A3F_parent_instructions;
         body.emit(f0A3F);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0A43 = bit_and(r0A31, body.constant(2147483648u));
         ir_expression *const r0A44 = equal(r0A43, body.constant(0u));
         ir_if *f0A42 = new(mem_ctx) ir_if(operand(r0A44).val);
         exec_list *const f0A42_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A42->then_instructions;

            body.emit(assign(r0A33, add(r0A33, body.constant(int(1))), 0x01));


         body.instructions = f0A42_parent_instructions;
         body.emit(f0A42);

         /* END IF */

         body.emit(assign(r0A32, r0A33, 0x01));


      body.instructions = f0A34_parent_instructions;
      body.emit(f0A34);

      /* END IF */

      ir_variable *const r0A45 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0A45, add(r0A32, body.constant(int(21))), 0x01));

      body.emit(assign(r0A2E, body.constant(0u), 0x01));

      body.emit(assign(r0A2D, body.constant(0u), 0x01));

      ir_variable *const r0A46 = body.make_temp(glsl_type::int_type, "assignment_tmp");
      ir_expression *const r0A47 = neg(r0A45);
      body.emit(assign(r0A46, bit_and(r0A47, body.constant(int(31))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0A49 = equal(r0A45, body.constant(int(0)));
      ir_if *f0A48 = new(mem_ctx) ir_if(operand(r0A49).val);
      exec_list *const f0A48_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A48->then_instructions;

         body.emit(assign(r0A2E, body.constant(0u), 0x01));

         body.emit(assign(r0A2D, r0A2B, 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A48->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0A4B = less(r0A45, body.constant(int(32)));
         ir_if *f0A4A = new(mem_ctx) ir_if(operand(r0A4B).val);
         exec_list *const f0A4A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A4A->then_instructions;

            body.emit(assign(r0A2E, rshift(r0A2B, r0A46), 0x01));

            body.emit(assign(r0A2D, lshift(r0A2B, r0A45), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A4A->else_instructions;

            ir_variable *const r0A4C = body.make_temp(glsl_type::uint_type, "conditional_tmp");
            /* IF CONDITION */
            ir_expression *const r0A4E = less(r0A45, body.constant(int(64)));
            ir_if *f0A4D = new(mem_ctx) ir_if(operand(r0A4E).val);
            exec_list *const f0A4D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0A4D->then_instructions;

               ir_expression *const r0A4F = add(r0A45, body.constant(int(-32)));
               body.emit(assign(r0A4C, lshift(r0A2B, r0A4F), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0A4D->else_instructions;

               body.emit(assign(r0A4C, body.constant(0u), 0x01));


            body.instructions = f0A4D_parent_instructions;
            body.emit(f0A4D);

            /* END IF */

            body.emit(assign(r0A2E, r0A4C, 0x01));

            body.emit(assign(r0A2D, body.constant(0u), 0x01));


         body.instructions = f0A4A_parent_instructions;
         body.emit(f0A4A);

         /* END IF */


      body.instructions = f0A48_parent_instructions;
      body.emit(f0A48);

      /* END IF */

      ir_variable *const r0A50 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A50);
      ir_expression *const r0A51 = sub(body.constant(int(1074)), r0A45);
      ir_expression *const r0A52 = expr(ir_unop_i2u, r0A51);
      ir_expression *const r0A53 = lshift(r0A52, body.constant(int(20)));
      body.emit(assign(r0A50, add(r0A53, r0A2E), 0x02));

      body.emit(assign(r0A50, r0A2D, 0x01));

      body.emit(assign(r0A2C, r0A50, 0x03));


   body.instructions = f0A2F_parent_instructions;
   body.emit(f0A2F);

   /* END IF */

   body.emit(ret(r0A2C));

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

   ir_variable *const r0A54 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A54);
   ir_variable *const r0A55 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0A55, body.constant(true), 0x01));

   ir_variable *const r0A56 = body.make_temp(glsl_type::int_type, "return_value");
   ir_variable *const r0A57 = new(mem_ctx) ir_variable(glsl_type::uint_type, "absZ", ir_var_auto);
   body.emit(r0A57);
   ir_variable *const r0A58 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0A58);
   ir_variable *const r0A59 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFracHi", ir_var_auto);
   body.emit(r0A59);
   ir_variable *const r0A5A = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0A5A, bit_and(swizzle_y(r0A54), body.constant(1048575u)), 0x01));

   body.emit(assign(r0A59, r0A5A, 0x01));

   ir_variable *const r0A5B = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0A5C = rshift(swizzle_y(r0A54), body.constant(int(20)));
   ir_expression *const r0A5D = bit_and(r0A5C, body.constant(2047u));
   body.emit(assign(r0A5B, expr(ir_unop_u2i, r0A5D), 0x01));

   body.emit(assign(r0A58, rshift(swizzle_y(r0A54), body.constant(int(31))), 0x01));

   body.emit(assign(r0A57, body.constant(0u), 0x01));

   ir_variable *const r0A5E = body.make_temp(glsl_type::int_type, "assignment_tmp");
   body.emit(assign(r0A5E, add(r0A5B, body.constant(int(-1043))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A60 = lequal(body.constant(int(0)), r0A5E);
   ir_if *f0A5F = new(mem_ctx) ir_if(operand(r0A60).val);
   exec_list *const f0A5F_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A5F->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0A62 = less(body.constant(int(1054)), r0A5B);
      ir_if *f0A61 = new(mem_ctx) ir_if(operand(r0A62).val);
      exec_list *const f0A61_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A61->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0A64 = equal(r0A5B, body.constant(int(2047)));
         ir_expression *const r0A65 = bit_or(r0A5A, swizzle_x(r0A54));
         ir_expression *const r0A66 = expr(ir_unop_u2i, r0A65);
         ir_expression *const r0A67 = expr(ir_unop_i2b, r0A66);
         ir_expression *const r0A68 = logic_and(r0A64, r0A67);
         ir_if *f0A63 = new(mem_ctx) ir_if(operand(r0A68).val);
         exec_list *const f0A63_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A63->then_instructions;

            body.emit(assign(r0A58, body.constant(0u), 0x01));


         body.instructions = f0A63_parent_instructions;
         body.emit(f0A63);

         /* END IF */

         ir_variable *const r0A69 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A6B = expr(ir_unop_u2i, r0A58);
         ir_expression *const r0A6C = expr(ir_unop_i2b, r0A6B);
         ir_if *f0A6A = new(mem_ctx) ir_if(operand(r0A6C).val);
         exec_list *const f0A6A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A6A->then_instructions;

            body.emit(assign(r0A69, body.constant(int(-2147483648)), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A6A->else_instructions;

            body.emit(assign(r0A69, body.constant(int(2147483647)), 0x01));


         body.instructions = f0A6A_parent_instructions;
         body.emit(f0A6A);

         /* END IF */

         body.emit(assign(r0A56, r0A69, 0x01));

         body.emit(assign(r0A55, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A61->else_instructions;

         ir_variable *const r0A6D = body.make_temp(glsl_type::uint_type, "a0");
         body.emit(assign(r0A6D, bit_or(r0A5A, body.constant(1048576u)), 0x01));

         ir_variable *const r0A6E = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0A6E, lshift(swizzle_x(r0A54), r0A5E), 0x01));

         ir_variable *const r0A6F = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A71 = equal(r0A5E, body.constant(int(0)));
         ir_if *f0A70 = new(mem_ctx) ir_if(operand(r0A71).val);
         exec_list *const f0A70_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A70->then_instructions;

            body.emit(assign(r0A6F, r0A6D, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0A70->else_instructions;

            ir_expression *const r0A72 = lshift(r0A6D, r0A5E);
            ir_expression *const r0A73 = neg(r0A5E);
            ir_expression *const r0A74 = bit_and(r0A73, body.constant(int(31)));
            ir_expression *const r0A75 = rshift(swizzle_x(r0A54), r0A74);
            body.emit(assign(r0A6F, bit_or(r0A72, r0A75), 0x01));


         body.instructions = f0A70_parent_instructions;
         body.emit(f0A70);

         /* END IF */

         body.emit(assign(r0A57, r0A6F, 0x01));


      body.instructions = f0A61_parent_instructions;
      body.emit(f0A61);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A5F->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0A77 = less(r0A5B, body.constant(int(1023)));
      ir_if *f0A76 = new(mem_ctx) ir_if(operand(r0A77).val);
      exec_list *const f0A76_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A76->then_instructions;

         body.emit(assign(r0A56, body.constant(int(0)), 0x01));

         body.emit(assign(r0A55, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A76->else_instructions;

         body.emit(assign(r0A59, bit_or(r0A5A, body.constant(1048576u)), 0x01));

         ir_expression *const r0A78 = neg(r0A5E);
         body.emit(assign(r0A57, rshift(r0A59, r0A78), 0x01));


      body.instructions = f0A76_parent_instructions;
      body.emit(f0A76);

      /* END IF */


   body.instructions = f0A5F_parent_instructions;
   body.emit(f0A5F);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0A79 = new(mem_ctx) ir_if(operand(r0A55).val);
   exec_list *const f0A79_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A79->then_instructions;

      ir_variable *const r0A7A = body.make_temp(glsl_type::int_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A7C = nequal(r0A58, body.constant(0u));
      ir_if *f0A7B = new(mem_ctx) ir_if(operand(r0A7C).val);
      exec_list *const f0A7B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A7B->then_instructions;

         ir_expression *const r0A7D = expr(ir_unop_u2i, r0A57);
         body.emit(assign(r0A7A, neg(r0A7D), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A7B->else_instructions;

         body.emit(assign(r0A7A, expr(ir_unop_u2i, r0A57), 0x01));


      body.instructions = f0A7B_parent_instructions;
      body.emit(f0A7B);

      /* END IF */

      /* IF CONDITION */
      ir_expression *const r0A7F = less(r0A7A, body.constant(int(0)));
      ir_expression *const r0A80 = expr(ir_unop_b2i, r0A7F);
      ir_expression *const r0A81 = expr(ir_unop_i2u, r0A80);
      ir_expression *const r0A82 = bit_xor(r0A58, r0A81);
      ir_expression *const r0A83 = expr(ir_unop_u2i, r0A82);
      ir_expression *const r0A84 = expr(ir_unop_i2b, r0A83);
      ir_expression *const r0A85 = expr(ir_unop_i2b, r0A7A);
      ir_expression *const r0A86 = logic_and(r0A84, r0A85);
      ir_if *f0A7E = new(mem_ctx) ir_if(operand(r0A86).val);
      exec_list *const f0A7E_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A7E->then_instructions;

         ir_variable *const r0A87 = body.make_temp(glsl_type::int_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0A89 = expr(ir_unop_u2i, r0A58);
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

         body.emit(assign(r0A56, r0A87, 0x01));

         body.emit(assign(r0A55, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A7E->else_instructions;

         body.emit(assign(r0A56, r0A7A, 0x01));

         body.emit(assign(r0A55, body.constant(false), 0x01));


      body.instructions = f0A7E_parent_instructions;
      body.emit(f0A7E);

      /* END IF */


   body.instructions = f0A79_parent_instructions;
   body.emit(f0A79);

   /* END IF */

   body.emit(ret(r0A56));

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

   ir_variable *const r0A8B = new(mem_ctx) ir_variable(glsl_type::int_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0A8B);
   ir_variable *const r0A8C = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0A8D = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_auto);
   body.emit(r0A8D);
   ir_variable *const r0A8E = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac1", ir_var_auto);
   body.emit(r0A8E);
   ir_variable *const r0A8F = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac0", ir_var_auto);
   body.emit(r0A8F);
   body.emit(assign(r0A8F, body.constant(0u), 0x01));

   body.emit(assign(r0A8E, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0A91 = equal(r0A8B, body.constant(int(0)));
   ir_if *f0A90 = new(mem_ctx) ir_if(operand(r0A91).val);
   exec_list *const f0A90_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0A90->then_instructions;

      ir_variable *const r0A92 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0A92);
      body.emit(assign(r0A92, body.constant(0u), 0x02));

      body.emit(assign(r0A92, body.constant(0u), 0x01));

      body.emit(assign(r0A8C, r0A92, 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0A90->else_instructions;

      ir_expression *const r0A93 = less(r0A8B, body.constant(int(0)));
      ir_expression *const r0A94 = expr(ir_unop_b2i, r0A93);
      body.emit(assign(r0A8D, expr(ir_unop_i2u, r0A94), 0x01));

      ir_variable *const r0A95 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0A97 = less(r0A8B, body.constant(int(0)));
      ir_if *f0A96 = new(mem_ctx) ir_if(operand(r0A97).val);
      exec_list *const f0A96_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A96->then_instructions;

         ir_expression *const r0A98 = neg(r0A8B);
         body.emit(assign(r0A95, expr(ir_unop_i2u, r0A98), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A96->else_instructions;

         body.emit(assign(r0A95, expr(ir_unop_i2u, r0A8B), 0x01));


      body.instructions = f0A96_parent_instructions;
      body.emit(f0A96);

      /* END IF */

      ir_variable *const r0A99 = body.make_temp(glsl_type::uint_type, "a");
      body.emit(assign(r0A99, r0A95, 0x01));

      ir_variable *const r0A9A = body.make_temp(glsl_type::int_type, "return_value");
      ir_variable *const r0A9B = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
      body.emit(r0A9B);
      /* IF CONDITION */
      ir_expression *const r0A9D = equal(r0A95, body.constant(0u));
      ir_if *f0A9C = new(mem_ctx) ir_if(operand(r0A9D).val);
      exec_list *const f0A9C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0A9C->then_instructions;

         body.emit(assign(r0A9A, body.constant(int(32)), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0A9C->else_instructions;

         body.emit(assign(r0A9B, body.constant(int(0)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0A9F = bit_and(r0A95, body.constant(4294901760u));
         ir_expression *const r0AA0 = equal(r0A9F, body.constant(0u));
         ir_if *f0A9E = new(mem_ctx) ir_if(operand(r0AA0).val);
         exec_list *const f0A9E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0A9E->then_instructions;

            body.emit(assign(r0A9B, body.constant(int(16)), 0x01));

            body.emit(assign(r0A99, lshift(r0A95, body.constant(int(16))), 0x01));


         body.instructions = f0A9E_parent_instructions;
         body.emit(f0A9E);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AA2 = bit_and(r0A99, body.constant(4278190080u));
         ir_expression *const r0AA3 = equal(r0AA2, body.constant(0u));
         ir_if *f0AA1 = new(mem_ctx) ir_if(operand(r0AA3).val);
         exec_list *const f0AA1_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA1->then_instructions;

            body.emit(assign(r0A9B, add(r0A9B, body.constant(int(8))), 0x01));

            body.emit(assign(r0A99, lshift(r0A99, body.constant(int(8))), 0x01));


         body.instructions = f0AA1_parent_instructions;
         body.emit(f0AA1);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AA5 = bit_and(r0A99, body.constant(4026531840u));
         ir_expression *const r0AA6 = equal(r0AA5, body.constant(0u));
         ir_if *f0AA4 = new(mem_ctx) ir_if(operand(r0AA6).val);
         exec_list *const f0AA4_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA4->then_instructions;

            body.emit(assign(r0A9B, add(r0A9B, body.constant(int(4))), 0x01));

            body.emit(assign(r0A99, lshift(r0A99, body.constant(int(4))), 0x01));


         body.instructions = f0AA4_parent_instructions;
         body.emit(f0AA4);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AA8 = bit_and(r0A99, body.constant(3221225472u));
         ir_expression *const r0AA9 = equal(r0AA8, body.constant(0u));
         ir_if *f0AA7 = new(mem_ctx) ir_if(operand(r0AA9).val);
         exec_list *const f0AA7_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AA7->then_instructions;

            body.emit(assign(r0A9B, add(r0A9B, body.constant(int(2))), 0x01));

            body.emit(assign(r0A99, lshift(r0A99, body.constant(int(2))), 0x01));


         body.instructions = f0AA7_parent_instructions;
         body.emit(f0AA7);

         /* END IF */

         /* IF CONDITION */
         ir_expression *const r0AAB = bit_and(r0A99, body.constant(2147483648u));
         ir_expression *const r0AAC = equal(r0AAB, body.constant(0u));
         ir_if *f0AAA = new(mem_ctx) ir_if(operand(r0AAC).val);
         exec_list *const f0AAA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AAA->then_instructions;

            body.emit(assign(r0A9B, add(r0A9B, body.constant(int(1))), 0x01));


         body.instructions = f0AAA_parent_instructions;
         body.emit(f0AAA);

         /* END IF */

         body.emit(assign(r0A9A, r0A9B, 0x01));


      body.instructions = f0A9C_parent_instructions;
      body.emit(f0A9C);

      /* END IF */

      ir_variable *const r0AAD = body.make_temp(glsl_type::int_type, "assignment_tmp");
      body.emit(assign(r0AAD, add(r0A9A, body.constant(int(-11))), 0x01));

      /* IF CONDITION */
      ir_expression *const r0AAF = lequal(body.constant(int(0)), r0AAD);
      ir_if *f0AAE = new(mem_ctx) ir_if(operand(r0AAF).val);
      exec_list *const f0AAE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AAE->then_instructions;

         body.emit(assign(r0A8F, lshift(r0A95, r0AAD), 0x01));

         body.emit(assign(r0A8E, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AAE->else_instructions;

         ir_variable *const r0AB0 = body.make_temp(glsl_type::uint_type, "a1");
         body.emit(assign(r0AB0, body.constant(0u), 0x01));

         ir_variable *const r0AB1 = body.make_temp(glsl_type::int_type, "count");
         body.emit(assign(r0AB1, neg(r0AAD), 0x01));

         ir_variable *const r0AB2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
         body.emit(r0AB2);
         ir_variable *const r0AB3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
         body.emit(r0AB3);
         ir_variable *const r0AB4 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         ir_expression *const r0AB5 = neg(r0AB1);
         body.emit(assign(r0AB4, bit_and(r0AB5, body.constant(int(31))), 0x01));

         /* IF CONDITION */
         ir_expression *const r0AB7 = equal(r0AB1, body.constant(int(0)));
         ir_if *f0AB6 = new(mem_ctx) ir_if(operand(r0AB7).val);
         exec_list *const f0AB6_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AB6->then_instructions;

            body.emit(assign(r0AB2, body.constant(0u), 0x01));

            body.emit(assign(r0AB3, r0A95, 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0AB6->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0AB9 = less(r0AB1, body.constant(int(32)));
            ir_if *f0AB8 = new(mem_ctx) ir_if(operand(r0AB9).val);
            exec_list *const f0AB8_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AB8->then_instructions;

               ir_expression *const r0ABA = lshift(r0A95, r0AB4);
               body.emit(assign(r0AB2, bit_or(r0ABA, body.constant(0u)), 0x01));

               body.emit(assign(r0AB3, rshift(r0A95, r0AB1), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0AB8->else_instructions;

               ir_variable *const r0ABB = body.make_temp(glsl_type::uint_type, "conditional_tmp");
               /* IF CONDITION */
               ir_expression *const r0ABD = less(r0AB1, body.constant(int(64)));
               ir_if *f0ABC = new(mem_ctx) ir_if(operand(r0ABD).val);
               exec_list *const f0ABC_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0ABC->then_instructions;

                  ir_expression *const r0ABE = bit_and(r0AB1, body.constant(int(31)));
                  body.emit(assign(r0ABB, rshift(r0A95, r0ABE), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0ABC->else_instructions;

                  body.emit(assign(r0ABB, body.constant(0u), 0x01));


               body.instructions = f0ABC_parent_instructions;
               body.emit(f0ABC);

               /* END IF */

               body.emit(assign(r0AB2, r0ABB, 0x01));

               body.emit(assign(r0AB3, body.constant(0u), 0x01));


            body.instructions = f0AB8_parent_instructions;
            body.emit(f0AB8);

            /* END IF */


         body.instructions = f0AB6_parent_instructions;
         body.emit(f0AB6);

         /* END IF */

         body.emit(assign(r0A8F, r0AB3, 0x01));

         body.emit(assign(r0A8E, r0AB2, 0x01));


      body.instructions = f0AAE_parent_instructions;
      body.emit(f0AAE);

      /* END IF */

      ir_variable *const r0ABF = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
      body.emit(r0ABF);
      ir_expression *const r0AC0 = lshift(r0A8D, body.constant(int(31)));
      ir_expression *const r0AC1 = sub(body.constant(int(1042)), r0AAD);
      ir_expression *const r0AC2 = expr(ir_unop_i2u, r0AC1);
      ir_expression *const r0AC3 = lshift(r0AC2, body.constant(int(20)));
      ir_expression *const r0AC4 = add(r0AC0, r0AC3);
      body.emit(assign(r0ABF, add(r0AC4, r0A8F), 0x02));

      body.emit(assign(r0ABF, r0A8E, 0x01));

      body.emit(assign(r0A8C, r0ABF, 0x03));


   body.instructions = f0A90_parent_instructions;
   body.emit(f0A90);

   /* END IF */

   body.emit(ret(r0A8C));

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

   ir_variable *const r0AC5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0AC5);
   ir_variable *const r0AC6 = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0AC6);
   ir_variable *const r0AC7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AC7);
   ir_variable *const r0AC8 = body.make_temp(glsl_type::float_type, "uintBitsToFloat_retval");
   ir_expression *const r0AC9 = lshift(r0AC5, body.constant(int(31)));
   ir_expression *const r0ACA = expr(ir_unop_i2u, r0AC6);
   ir_expression *const r0ACB = lshift(r0ACA, body.constant(int(23)));
   ir_expression *const r0ACC = add(r0AC9, r0ACB);
   ir_expression *const r0ACD = add(r0ACC, r0AC7);
   body.emit(assign(r0AC8, expr(ir_unop_bitcast_u2f, r0ACD), 0x01));

   body.emit(ret(r0AC8));

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

   ir_variable *const r0ACE = new(mem_ctx) ir_variable(glsl_type::uint_type, "zSign", ir_var_function_in);
   sig_parameters.push_tail(r0ACE);
   ir_variable *const r0ACF = new(mem_ctx) ir_variable(glsl_type::int_type, "zExp", ir_var_function_in);
   sig_parameters.push_tail(r0ACF);
   ir_variable *const r0AD0 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_function_in);
   sig_parameters.push_tail(r0AD0);
   ir_variable *const r0AD1 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0AD1, body.constant(true), 0x01));

   ir_variable *const r0AD2 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0AD3 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
   body.emit(r0AD3);
   ir_expression *const r0AD4 = bit_and(r0AD0, body.constant(127u));
   body.emit(assign(r0AD3, expr(ir_unop_u2i, r0AD4), 0x01));

   /* IF CONDITION */
   ir_expression *const r0AD6 = expr(ir_unop_i2u, r0ACF);
   ir_expression *const r0AD7 = lequal(body.constant(253u), r0AD6);
   ir_if *f0AD5 = new(mem_ctx) ir_if(operand(r0AD7).val);
   exec_list *const f0AD5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AD5->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0AD9 = less(body.constant(int(253)), r0ACF);
      ir_expression *const r0ADA = equal(r0ACF, body.constant(int(253)));
      ir_expression *const r0ADB = expr(ir_unop_u2i, r0AD0);
      ir_expression *const r0ADC = less(r0ADB, body.constant(int(-64)));
      ir_expression *const r0ADD = logic_and(r0ADA, r0ADC);
      ir_expression *const r0ADE = logic_or(r0AD9, r0ADD);
      ir_if *f0AD8 = new(mem_ctx) ir_if(operand(r0ADE).val);
      exec_list *const f0AD8_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AD8->then_instructions;

         ir_expression *const r0ADF = lshift(r0ACE, body.constant(int(31)));
         ir_expression *const r0AE0 = add(r0ADF, body.constant(2139095040u));
         body.emit(assign(r0AD2, expr(ir_unop_bitcast_u2f, r0AE0), 0x01));

         body.emit(assign(r0AD1, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0AD8->else_instructions;

         /* IF CONDITION */
         ir_expression *const r0AE2 = less(r0ACF, body.constant(int(0)));
         ir_if *f0AE1 = new(mem_ctx) ir_if(operand(r0AE2).val);
         exec_list *const f0AE1_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0AE1->then_instructions;

            ir_variable *const r0AE3 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0AE3, neg(r0ACF), 0x01));

            /* IF CONDITION */
            ir_expression *const r0AE5 = less(r0AE3, body.constant(int(32)));
            ir_if *f0AE4 = new(mem_ctx) ir_if(operand(r0AE5).val);
            exec_list *const f0AE4_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0AE4->then_instructions;

               ir_expression *const r0AE6 = rshift(r0AD0, r0AE3);
               ir_expression *const r0AE7 = neg(r0AE3);
               ir_expression *const r0AE8 = bit_and(r0AE7, body.constant(int(31)));
               ir_expression *const r0AE9 = lshift(r0AD0, r0AE8);
               ir_expression *const r0AEA = nequal(r0AE9, body.constant(0u));
               ir_expression *const r0AEB = expr(ir_unop_b2i, r0AEA);
               ir_expression *const r0AEC = expr(ir_unop_i2u, r0AEB);
               body.emit(assign(r0AD0, bit_or(r0AE6, r0AEC), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0AE4->else_instructions;

               ir_expression *const r0AED = nequal(r0AD0, body.constant(0u));
               ir_expression *const r0AEE = expr(ir_unop_b2i, r0AED);
               body.emit(assign(r0AD0, expr(ir_unop_i2u, r0AEE), 0x01));


            body.instructions = f0AE4_parent_instructions;
            body.emit(f0AE4);

            /* END IF */

            body.emit(assign(r0ACF, body.constant(int(0)), 0x01));

            ir_expression *const r0AEF = expr(ir_unop_u2i, r0AD0);
            body.emit(assign(r0AD3, bit_and(r0AEF, body.constant(int(127))), 0x01));


         body.instructions = f0AE1_parent_instructions;
         body.emit(f0AE1);

         /* END IF */


      body.instructions = f0AD8_parent_instructions;
      body.emit(f0AD8);

      /* END IF */


   body.instructions = f0AD5_parent_instructions;
   body.emit(f0AD5);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0AF0 = new(mem_ctx) ir_if(operand(r0AD1).val);
   exec_list *const f0AF0_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0AF0->then_instructions;

      ir_expression *const r0AF1 = add(r0AD0, body.constant(64u));
      body.emit(assign(r0AD0, rshift(r0AF1, body.constant(int(7))), 0x01));

      ir_expression *const r0AF2 = bit_xor(r0AD3, body.constant(int(64)));
      ir_expression *const r0AF3 = equal(r0AF2, body.constant(int(0)));
      ir_expression *const r0AF4 = expr(ir_unop_b2i, r0AF3);
      ir_expression *const r0AF5 = expr(ir_unop_i2u, r0AF4);
      ir_expression *const r0AF6 = expr(ir_unop_bit_not, r0AF5);
      body.emit(assign(r0AD0, bit_and(r0AD0, r0AF6), 0x01));

      /* IF CONDITION */
      ir_expression *const r0AF8 = equal(r0AD0, body.constant(0u));
      ir_if *f0AF7 = new(mem_ctx) ir_if(operand(r0AF8).val);
      exec_list *const f0AF7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0AF7->then_instructions;

         body.emit(assign(r0ACF, body.constant(int(0)), 0x01));


      body.instructions = f0AF7_parent_instructions;
      body.emit(f0AF7);

      /* END IF */

      ir_expression *const r0AF9 = lshift(r0ACE, body.constant(int(31)));
      ir_expression *const r0AFA = expr(ir_unop_i2u, r0ACF);
      ir_expression *const r0AFB = lshift(r0AFA, body.constant(int(23)));
      ir_expression *const r0AFC = add(r0AF9, r0AFB);
      ir_expression *const r0AFD = add(r0AFC, r0AD0);
      body.emit(assign(r0AD2, expr(ir_unop_bitcast_u2f, r0AFD), 0x01));

      body.emit(assign(r0AD1, body.constant(false), 0x01));


   body.instructions = f0AF0_parent_instructions;
   body.emit(f0AF0);

   /* END IF */

   body.emit(ret(r0AD2));

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

   ir_variable *const r0AFE = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0AFE);
   ir_variable *const r0AFF = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0B00 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0B00);
   body.emit(assign(r0B00, body.constant(0u), 0x01));

   ir_variable *const r0B01 = body.make_temp(glsl_type::uint_type, "extractFloat64FracLo_retval");
   body.emit(assign(r0B01, swizzle_x(r0AFE), 0x01));

   ir_variable *const r0B02 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0B02, bit_and(swizzle_y(r0AFE), body.constant(1048575u)), 0x01));

   ir_variable *const r0B03 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0B04 = rshift(swizzle_y(r0AFE), body.constant(int(20)));
   ir_expression *const r0B05 = bit_and(r0B04, body.constant(2047u));
   body.emit(assign(r0B03, expr(ir_unop_u2i, r0B05), 0x01));

   ir_variable *const r0B06 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0B06, rshift(swizzle_y(r0AFE), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B08 = equal(r0B03, body.constant(int(2047)));
   ir_if *f0B07 = new(mem_ctx) ir_if(operand(r0B08).val);
   exec_list *const f0B07_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B07->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B0A = bit_or(r0B02, swizzle_x(r0AFE));
      ir_expression *const r0B0B = nequal(r0B0A, body.constant(0u));
      ir_if *f0B09 = new(mem_ctx) ir_if(operand(r0B0B).val);
      exec_list *const f0B09_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B09->then_instructions;

         ir_variable *const r0B0C = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0B0C, lshift(swizzle_x(r0AFE), body.constant(int(12))), 0x01));

         ir_variable *const r0B0D = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         ir_expression *const r0B0E = lshift(swizzle_y(r0AFE), body.constant(int(12)));
         ir_expression *const r0B0F = rshift(swizzle_x(r0AFE), body.constant(int(20)));
         body.emit(assign(r0B0D, bit_or(r0B0E, r0B0F), 0x01));

         body.emit(assign(r0AFE, r0B0D, 0x02));

         body.emit(assign(r0AFE, r0B0C, 0x01));

         ir_expression *const r0B10 = lshift(r0B06, body.constant(int(31)));
         ir_expression *const r0B11 = bit_or(r0B10, body.constant(2143289344u));
         ir_expression *const r0B12 = rshift(r0B0D, body.constant(int(9)));
         ir_expression *const r0B13 = bit_or(r0B11, r0B12);
         body.emit(assign(r0AFF, expr(ir_unop_bitcast_u2f, r0B13), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B09->else_instructions;

         ir_expression *const r0B14 = lshift(r0B06, body.constant(int(31)));
         ir_expression *const r0B15 = add(r0B14, body.constant(2139095040u));
         body.emit(assign(r0AFF, expr(ir_unop_bitcast_u2f, r0B15), 0x01));


      body.instructions = f0B09_parent_instructions;
      body.emit(f0B09);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B07->else_instructions;

      ir_variable *const r0B16 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0B16);
      ir_variable *const r0B17 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0B17);
      ir_expression *const r0B18 = lshift(r0B02, body.constant(int(10)));
      ir_expression *const r0B19 = rshift(r0B01, body.constant(int(22)));
      ir_expression *const r0B1A = bit_or(r0B18, r0B19);
      ir_expression *const r0B1B = lshift(r0B01, body.constant(int(10)));
      ir_expression *const r0B1C = nequal(r0B1B, body.constant(0u));
      ir_expression *const r0B1D = expr(ir_unop_b2i, r0B1C);
      ir_expression *const r0B1E = expr(ir_unop_i2u, r0B1D);
      body.emit(assign(r0B16, bit_or(r0B1A, r0B1E), 0x01));

      body.emit(assign(r0B17, rshift(r0B02, body.constant(int(22))), 0x01));

      body.emit(assign(r0B00, r0B16, 0x01));

      /* IF CONDITION */
      ir_expression *const r0B20 = nequal(r0B03, body.constant(int(0)));
      ir_if *f0B1F = new(mem_ctx) ir_if(operand(r0B20).val);
      exec_list *const f0B1F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B1F->then_instructions;

         body.emit(assign(r0B00, bit_or(r0B16, body.constant(1073741824u)), 0x01));


      body.instructions = f0B1F_parent_instructions;
      body.emit(f0B1F);

      /* END IF */

      ir_variable *const r0B21 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0B21, add(r0B03, body.constant(int(-897))), 0x01));

      ir_variable *const r0B22 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0B22, r0B00, 0x01));

      ir_variable *const r0B23 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0B23, body.constant(true), 0x01));

      ir_variable *const r0B24 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0B25 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0B25);
      ir_expression *const r0B26 = bit_and(r0B00, body.constant(127u));
      body.emit(assign(r0B25, expr(ir_unop_u2i, r0B26), 0x01));

      /* IF CONDITION */
      ir_expression *const r0B28 = expr(ir_unop_i2u, r0B21);
      ir_expression *const r0B29 = lequal(body.constant(253u), r0B28);
      ir_if *f0B27 = new(mem_ctx) ir_if(operand(r0B29).val);
      exec_list *const f0B27_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B27->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B2B = less(body.constant(int(253)), r0B21);
         ir_expression *const r0B2C = equal(r0B21, body.constant(int(253)));
         ir_expression *const r0B2D = expr(ir_unop_u2i, r0B00);
         ir_expression *const r0B2E = less(r0B2D, body.constant(int(-64)));
         ir_expression *const r0B2F = logic_and(r0B2C, r0B2E);
         ir_expression *const r0B30 = logic_or(r0B2B, r0B2F);
         ir_if *f0B2A = new(mem_ctx) ir_if(operand(r0B30).val);
         exec_list *const f0B2A_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B2A->then_instructions;

            ir_expression *const r0B31 = lshift(r0B06, body.constant(int(31)));
            ir_expression *const r0B32 = add(r0B31, body.constant(2139095040u));
            body.emit(assign(r0B24, expr(ir_unop_bitcast_u2f, r0B32), 0x01));

            body.emit(assign(r0B23, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B2A->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0B34 = less(r0B21, body.constant(int(0)));
            ir_if *f0B33 = new(mem_ctx) ir_if(operand(r0B34).val);
            exec_list *const f0B33_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B33->then_instructions;

               ir_variable *const r0B35 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0B35, neg(r0B21), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B37 = less(r0B35, body.constant(int(32)));
               ir_if *f0B36 = new(mem_ctx) ir_if(operand(r0B37).val);
               exec_list *const f0B36_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B36->then_instructions;

                  ir_expression *const r0B38 = rshift(r0B00, r0B35);
                  ir_expression *const r0B39 = neg(r0B35);
                  ir_expression *const r0B3A = bit_and(r0B39, body.constant(int(31)));
                  ir_expression *const r0B3B = lshift(r0B00, r0B3A);
                  ir_expression *const r0B3C = nequal(r0B3B, body.constant(0u));
                  ir_expression *const r0B3D = expr(ir_unop_b2i, r0B3C);
                  ir_expression *const r0B3E = expr(ir_unop_i2u, r0B3D);
                  body.emit(assign(r0B22, bit_or(r0B38, r0B3E), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0B36->else_instructions;

                  ir_expression *const r0B3F = nequal(r0B22, body.constant(0u));
                  ir_expression *const r0B40 = expr(ir_unop_b2i, r0B3F);
                  body.emit(assign(r0B22, expr(ir_unop_i2u, r0B40), 0x01));


               body.instructions = f0B36_parent_instructions;
               body.emit(f0B36);

               /* END IF */

               body.emit(assign(r0B21, body.constant(int(0)), 0x01));

               ir_expression *const r0B41 = expr(ir_unop_u2i, r0B22);
               body.emit(assign(r0B25, bit_and(r0B41, body.constant(int(127))), 0x01));


            body.instructions = f0B33_parent_instructions;
            body.emit(f0B33);

            /* END IF */


         body.instructions = f0B2A_parent_instructions;
         body.emit(f0B2A);

         /* END IF */


      body.instructions = f0B27_parent_instructions;
      body.emit(f0B27);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B42 = new(mem_ctx) ir_if(operand(r0B23).val);
      exec_list *const f0B42_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B42->then_instructions;

         ir_expression *const r0B43 = add(r0B22, body.constant(64u));
         body.emit(assign(r0B22, rshift(r0B43, body.constant(int(7))), 0x01));

         ir_expression *const r0B44 = bit_xor(r0B25, body.constant(int(64)));
         ir_expression *const r0B45 = equal(r0B44, body.constant(int(0)));
         ir_expression *const r0B46 = expr(ir_unop_b2i, r0B45);
         ir_expression *const r0B47 = expr(ir_unop_i2u, r0B46);
         ir_expression *const r0B48 = expr(ir_unop_bit_not, r0B47);
         body.emit(assign(r0B22, bit_and(r0B22, r0B48), 0x01));

         /* IF CONDITION */
         ir_expression *const r0B4A = equal(r0B22, body.constant(0u));
         ir_if *f0B49 = new(mem_ctx) ir_if(operand(r0B4A).val);
         exec_list *const f0B49_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B49->then_instructions;

            body.emit(assign(r0B21, body.constant(int(0)), 0x01));


         body.instructions = f0B49_parent_instructions;
         body.emit(f0B49);

         /* END IF */

         ir_expression *const r0B4B = lshift(r0B06, body.constant(int(31)));
         ir_expression *const r0B4C = expr(ir_unop_i2u, r0B21);
         ir_expression *const r0B4D = lshift(r0B4C, body.constant(int(23)));
         ir_expression *const r0B4E = add(r0B4B, r0B4D);
         ir_expression *const r0B4F = add(r0B4E, r0B22);
         body.emit(assign(r0B24, expr(ir_unop_bitcast_u2f, r0B4F), 0x01));

         body.emit(assign(r0B23, body.constant(false), 0x01));


      body.instructions = f0B42_parent_instructions;
      body.emit(f0B42);

      /* END IF */

      body.emit(assign(r0AFF, r0B24, 0x01));


   body.instructions = f0B07_parent_instructions;
   body.emit(f0B07);

   /* END IF */

   body.emit(ret(r0AFF));

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

   ir_variable *const r0B50 = new(mem_ctx) ir_variable(glsl_type::float_type, "f", ir_var_function_in);
   sig_parameters.push_tail(r0B50);
   ir_variable *const r0B51 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0B51, body.constant(true), 0x01));

   ir_variable *const r0B52 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0B53 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0B53);
   ir_variable *const r0B54 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0B54);
   ir_variable *const r0B55 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0B55);
   ir_variable *const r0B56 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   body.emit(assign(r0B56, expr(ir_unop_bitcast_f2u, r0B50), 0x01));

   ir_variable *const r0B57 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B57, bit_and(r0B56, body.constant(8388607u)), 0x01));

   body.emit(assign(r0B55, r0B57, 0x01));

   ir_variable *const r0B58 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0B59 = rshift(r0B56, body.constant(int(23)));
   ir_expression *const r0B5A = bit_and(r0B59, body.constant(255u));
   body.emit(assign(r0B58, expr(ir_unop_u2i, r0B5A), 0x01));

   body.emit(assign(r0B54, r0B58, 0x01));

   body.emit(assign(r0B53, rshift(r0B56, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0B5C = equal(r0B58, body.constant(int(255)));
   ir_if *f0B5B = new(mem_ctx) ir_if(operand(r0B5C).val);
   exec_list *const f0B5B_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0B5B->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0B5E = nequal(r0B57, body.constant(0u));
      ir_if *f0B5D = new(mem_ctx) ir_if(operand(r0B5E).val);
      exec_list *const f0B5D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B5D->then_instructions;

         ir_variable *const r0B5F = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0B5F, lshift(r0B56, body.constant(int(9))), 0x01));

         ir_variable *const r0B60 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0B61 = lshift(r0B5F, body.constant(int(20)));
         body.emit(assign(r0B60, bit_or(r0B61, body.constant(0u)), 0x01));

         ir_expression *const r0B62 = rshift(r0B5F, body.constant(int(12)));
         ir_expression *const r0B63 = lshift(r0B53, body.constant(int(31)));
         ir_expression *const r0B64 = bit_or(r0B63, body.constant(2146959360u));
         body.emit(assign(r0B60, bit_or(r0B62, r0B64), 0x02));

         body.emit(assign(r0B52, r0B60, 0x03));

         body.emit(assign(r0B51, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0B5D->else_instructions;

         ir_variable *const r0B65 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B65);
         ir_expression *const r0B66 = lshift(r0B53, body.constant(int(31)));
         body.emit(assign(r0B65, add(r0B66, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0B65, body.constant(0u), 0x01));

         body.emit(assign(r0B52, r0B65, 0x03));

         body.emit(assign(r0B51, body.constant(false), 0x01));


      body.instructions = f0B5D_parent_instructions;
      body.emit(f0B5D);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0B5B->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0B68 = equal(r0B58, body.constant(int(0)));
      ir_if *f0B67 = new(mem_ctx) ir_if(operand(r0B68).val);
      exec_list *const f0B67_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B67->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0B6A = equal(r0B57, body.constant(0u));
         ir_if *f0B69 = new(mem_ctx) ir_if(operand(r0B6A).val);
         exec_list *const f0B69_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0B69->then_instructions;

            ir_variable *const r0B6B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0B6B);
            body.emit(assign(r0B6B, lshift(r0B53, body.constant(int(31))), 0x02));

            body.emit(assign(r0B6B, body.constant(0u), 0x01));

            body.emit(assign(r0B52, r0B6B, 0x03));

            body.emit(assign(r0B51, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0B69->else_instructions;

            ir_variable *const r0B6C = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0B6C, r0B57, 0x01));

            ir_variable *const r0B6D = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0B6E = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0B6E);
            /* IF CONDITION */
            ir_expression *const r0B70 = equal(r0B57, body.constant(0u));
            ir_if *f0B6F = new(mem_ctx) ir_if(operand(r0B70).val);
            exec_list *const f0B6F_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0B6F->then_instructions;

               body.emit(assign(r0B6D, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0B6F->else_instructions;

               body.emit(assign(r0B6E, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0B72 = bit_and(r0B57, body.constant(4294901760u));
               ir_expression *const r0B73 = equal(r0B72, body.constant(0u));
               ir_if *f0B71 = new(mem_ctx) ir_if(operand(r0B73).val);
               exec_list *const f0B71_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B71->then_instructions;

                  body.emit(assign(r0B6E, body.constant(int(16)), 0x01));

                  body.emit(assign(r0B6C, lshift(r0B57, body.constant(int(16))), 0x01));


               body.instructions = f0B71_parent_instructions;
               body.emit(f0B71);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B75 = bit_and(r0B6C, body.constant(4278190080u));
               ir_expression *const r0B76 = equal(r0B75, body.constant(0u));
               ir_if *f0B74 = new(mem_ctx) ir_if(operand(r0B76).val);
               exec_list *const f0B74_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B74->then_instructions;

                  body.emit(assign(r0B6E, add(r0B6E, body.constant(int(8))), 0x01));

                  body.emit(assign(r0B6C, lshift(r0B6C, body.constant(int(8))), 0x01));


               body.instructions = f0B74_parent_instructions;
               body.emit(f0B74);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B78 = bit_and(r0B6C, body.constant(4026531840u));
               ir_expression *const r0B79 = equal(r0B78, body.constant(0u));
               ir_if *f0B77 = new(mem_ctx) ir_if(operand(r0B79).val);
               exec_list *const f0B77_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B77->then_instructions;

                  body.emit(assign(r0B6E, add(r0B6E, body.constant(int(4))), 0x01));

                  body.emit(assign(r0B6C, lshift(r0B6C, body.constant(int(4))), 0x01));


               body.instructions = f0B77_parent_instructions;
               body.emit(f0B77);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B7B = bit_and(r0B6C, body.constant(3221225472u));
               ir_expression *const r0B7C = equal(r0B7B, body.constant(0u));
               ir_if *f0B7A = new(mem_ctx) ir_if(operand(r0B7C).val);
               exec_list *const f0B7A_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B7A->then_instructions;

                  body.emit(assign(r0B6E, add(r0B6E, body.constant(int(2))), 0x01));

                  body.emit(assign(r0B6C, lshift(r0B6C, body.constant(int(2))), 0x01));


               body.instructions = f0B7A_parent_instructions;
               body.emit(f0B7A);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0B7E = bit_and(r0B6C, body.constant(2147483648u));
               ir_expression *const r0B7F = equal(r0B7E, body.constant(0u));
               ir_if *f0B7D = new(mem_ctx) ir_if(operand(r0B7F).val);
               exec_list *const f0B7D_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0B7D->then_instructions;

                  body.emit(assign(r0B6E, add(r0B6E, body.constant(int(1))), 0x01));


               body.instructions = f0B7D_parent_instructions;
               body.emit(f0B7D);

               /* END IF */

               body.emit(assign(r0B6D, r0B6E, 0x01));


            body.instructions = f0B6F_parent_instructions;
            body.emit(f0B6F);

            /* END IF */

            ir_variable *const r0B80 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0B80, add(r0B6D, body.constant(int(-8))), 0x01));

            body.emit(assign(r0B55, lshift(r0B57, r0B80), 0x01));

            body.emit(assign(r0B54, sub(body.constant(int(1)), r0B80), 0x01));

            body.emit(assign(r0B54, add(r0B54, body.constant(int(-1))), 0x01));


         body.instructions = f0B69_parent_instructions;
         body.emit(f0B69);

         /* END IF */


      body.instructions = f0B67_parent_instructions;
      body.emit(f0B67);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0B81 = new(mem_ctx) ir_if(operand(r0B51).val);
      exec_list *const f0B81_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0B81->then_instructions;

         ir_variable *const r0B82 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0B82);
         ir_expression *const r0B83 = lshift(r0B53, body.constant(int(31)));
         ir_expression *const r0B84 = add(r0B54, body.constant(int(896)));
         ir_expression *const r0B85 = expr(ir_unop_i2u, r0B84);
         ir_expression *const r0B86 = lshift(r0B85, body.constant(int(20)));
         ir_expression *const r0B87 = add(r0B83, r0B86);
         ir_expression *const r0B88 = rshift(r0B55, body.constant(int(3)));
         body.emit(assign(r0B82, add(r0B87, r0B88), 0x02));

         ir_expression *const r0B89 = lshift(r0B55, body.constant(int(29)));
         body.emit(assign(r0B82, bit_or(r0B89, body.constant(0u)), 0x01));

         body.emit(assign(r0B52, r0B82, 0x03));

         body.emit(assign(r0B51, body.constant(false), 0x01));


      body.instructions = f0B81_parent_instructions;
      body.emit(f0B81);

      /* END IF */


   body.instructions = f0B5B_parent_instructions;
   body.emit(f0B5B);

   /* END IF */

   body.emit(ret(r0B52));

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

   ir_variable *const r0B8A = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0B8A);
   ir_variable *const r0B8B = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0B8B);
   ir_variable *const r0B8C = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0B8C);
   ir_variable *const r0B8D = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0B8D);
   ir_variable *const r0B8E = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0B8E);
   ir_variable *const r0B8F = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0B8F);
   ir_variable *const r0B90 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B90);
   ir_variable *const r0B91 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B91);
   ir_variable *const r0B92 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0B92);
   ir_variable *const r0B93 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0B93);
   ir_variable *const r0B94 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
   body.emit(r0B94);
   ir_variable *const r0B95 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B95, add(r0B8C, r0B8F), 0x01));

   ir_variable *const r0B96 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0B97 = less(r0B95, r0B8C);
   ir_expression *const r0B98 = expr(ir_unop_b2i, r0B97);
   body.emit(assign(r0B96, expr(ir_unop_i2u, r0B98), 0x01));

   ir_variable *const r0B99 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0B99, add(r0B8B, r0B8E), 0x01));

   body.emit(assign(r0B94, add(r0B99, r0B96), 0x01));

   ir_expression *const r0B9A = add(r0B8A, r0B8D);
   ir_expression *const r0B9B = less(r0B94, r0B96);
   ir_expression *const r0B9C = expr(ir_unop_b2i, r0B9B);
   ir_expression *const r0B9D = expr(ir_unop_i2u, r0B9C);
   body.emit(assign(r0B93, add(r0B9A, r0B9D), 0x01));

   ir_expression *const r0B9E = less(r0B99, r0B8B);
   ir_expression *const r0B9F = expr(ir_unop_b2i, r0B9E);
   ir_expression *const r0BA0 = expr(ir_unop_i2u, r0B9F);
   body.emit(assign(r0B93, add(r0B93, r0BA0), 0x01));

   body.emit(assign(r0B92, r0B95, 0x01));

   body.emit(assign(r0B91, r0B94, 0x01));

   body.emit(assign(r0B90, r0B93, 0x01));

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

   ir_variable *const r0BA1 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BA1);
   ir_variable *const r0BA2 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BA2);
   ir_variable *const r0BA3 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a2", ir_var_function_in);
   sig_parameters.push_tail(r0BA3);
   ir_variable *const r0BA4 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_function_in);
   sig_parameters.push_tail(r0BA4);
   ir_variable *const r0BA5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b1", ir_var_function_in);
   sig_parameters.push_tail(r0BA5);
   ir_variable *const r0BA6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b2", ir_var_function_in);
   sig_parameters.push_tail(r0BA6);
   ir_variable *const r0BA7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BA7);
   ir_variable *const r0BA8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BA8);
   ir_variable *const r0BA9 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z2Ptr", ir_var_function_inout);
   sig_parameters.push_tail(r0BA9);
   ir_variable *const r0BAA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
   body.emit(r0BAA);
   ir_variable *const r0BAB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   ir_expression *const r0BAC = less(r0BA3, r0BA6);
   ir_expression *const r0BAD = expr(ir_unop_b2i, r0BAC);
   body.emit(assign(r0BAB, expr(ir_unop_i2u, r0BAD), 0x01));

   ir_variable *const r0BAE = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0BAE, sub(r0BA2, r0BA5), 0x01));

   ir_expression *const r0BAF = sub(r0BA1, r0BA4);
   ir_expression *const r0BB0 = less(r0BAE, r0BAB);
   ir_expression *const r0BB1 = expr(ir_unop_b2i, r0BB0);
   ir_expression *const r0BB2 = expr(ir_unop_i2u, r0BB1);
   body.emit(assign(r0BAA, sub(r0BAF, r0BB2), 0x01));

   ir_expression *const r0BB3 = less(r0BA2, r0BA5);
   ir_expression *const r0BB4 = expr(ir_unop_b2i, r0BB3);
   ir_expression *const r0BB5 = expr(ir_unop_i2u, r0BB4);
   body.emit(assign(r0BAA, sub(r0BAA, r0BB5), 0x01));

   body.emit(assign(r0BA9, sub(r0BA3, r0BA6), 0x01));

   body.emit(assign(r0BA8, sub(r0BAE, r0BAB), 0x01));

   body.emit(assign(r0BA7, r0BAA, 0x01));

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

   ir_variable *const r0BB6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a0", ir_var_function_in);
   sig_parameters.push_tail(r0BB6);
   ir_variable *const r0BB7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "a1", ir_var_function_in);
   sig_parameters.push_tail(r0BB7);
   ir_variable *const r0BB8 = new(mem_ctx) ir_variable(glsl_type::uint_type, "b", ir_var_function_in);
   sig_parameters.push_tail(r0BB8);
   ir_variable *const r0BB9 = body.make_temp(glsl_type::uint_type, "return_value");
   ir_variable *const r0BBA = new(mem_ctx) ir_variable(glsl_type::uint_type, "z", ir_var_auto);
   body.emit(r0BBA);
   ir_variable *const r0BBB = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem1", ir_var_auto);
   body.emit(r0BBB);
   ir_variable *const r0BBC = new(mem_ctx) ir_variable(glsl_type::uint_type, "rem0", ir_var_auto);
   body.emit(r0BBC);
   ir_variable *const r0BBD = new(mem_ctx) ir_variable(glsl_type::uint_type, "b0", ir_var_auto);
   body.emit(r0BBD);
   body.emit(assign(r0BBC, body.constant(0u), 0x01));

   body.emit(assign(r0BBB, body.constant(0u), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BBF = lequal(r0BB8, r0BB6);
   ir_if *f0BBE = new(mem_ctx) ir_if(operand(r0BBF).val);
   exec_list *const f0BBE_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BBE->then_instructions;

      body.emit(assign(r0BB9, body.constant(4294967295u), 0x01));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BBE->else_instructions;

      body.emit(assign(r0BBD, rshift(r0BB8, body.constant(int(16))), 0x01));

      ir_variable *const r0BC0 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BC2 = lshift(r0BBD, body.constant(int(16)));
      ir_expression *const r0BC3 = lequal(r0BC2, r0BB6);
      ir_if *f0BC1 = new(mem_ctx) ir_if(operand(r0BC3).val);
      exec_list *const f0BC1_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BC1->then_instructions;

         body.emit(assign(r0BC0, body.constant(4294901760u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BC1->else_instructions;

         ir_expression *const r0BC4 = expr(ir_binop_div, r0BB6, r0BBD);
         body.emit(assign(r0BC0, lshift(r0BC4, body.constant(int(16))), 0x01));


      body.instructions = f0BC1_parent_instructions;
      body.emit(f0BC1);

      /* END IF */

      body.emit(assign(r0BBA, r0BC0, 0x01));

      ir_variable *const r0BC5 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0BC5);
      ir_variable *const r0BC6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zMiddleA", ir_var_auto);
      body.emit(r0BC6);
      ir_variable *const r0BC7 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0BC7);
      ir_variable *const r0BC8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC8, bit_and(r0BB8, body.constant(65535u)), 0x01));

      ir_variable *const r0BC9 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BC9, rshift(r0BB8, body.constant(int(16))), 0x01));

      ir_variable *const r0BCA = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BCA, bit_and(r0BC0, body.constant(65535u)), 0x01));

      ir_variable *const r0BCB = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BCB, rshift(r0BC0, body.constant(int(16))), 0x01));

      ir_variable *const r0BCC = body.make_temp(glsl_type::uint_type, "assignment_tmp");
      body.emit(assign(r0BCC, mul(r0BC9, r0BCA), 0x01));

      ir_expression *const r0BCD = mul(r0BC8, r0BCB);
      body.emit(assign(r0BC6, add(r0BCD, r0BCC), 0x01));

      ir_expression *const r0BCE = mul(r0BC9, r0BCB);
      ir_expression *const r0BCF = less(r0BC6, r0BCC);
      ir_expression *const r0BD0 = expr(ir_unop_b2i, r0BCF);
      ir_expression *const r0BD1 = expr(ir_unop_i2u, r0BD0);
      ir_expression *const r0BD2 = lshift(r0BD1, body.constant(int(16)));
      ir_expression *const r0BD3 = rshift(r0BC6, body.constant(int(16)));
      ir_expression *const r0BD4 = add(r0BD2, r0BD3);
      body.emit(assign(r0BC5, add(r0BCE, r0BD4), 0x01));

      body.emit(assign(r0BC6, lshift(r0BC6, body.constant(int(16))), 0x01));

      ir_expression *const r0BD5 = mul(r0BC8, r0BCA);
      body.emit(assign(r0BC7, add(r0BD5, r0BC6), 0x01));

      ir_expression *const r0BD6 = less(r0BC7, r0BC6);
      ir_expression *const r0BD7 = expr(ir_unop_b2i, r0BD6);
      ir_expression *const r0BD8 = expr(ir_unop_i2u, r0BD7);
      body.emit(assign(r0BC5, add(r0BC5, r0BD8), 0x01));

      ir_expression *const r0BD9 = sub(r0BB6, r0BC5);
      ir_expression *const r0BDA = less(r0BB7, r0BC7);
      ir_expression *const r0BDB = expr(ir_unop_b2i, r0BDA);
      ir_expression *const r0BDC = expr(ir_unop_i2u, r0BDB);
      body.emit(assign(r0BBC, sub(r0BD9, r0BDC), 0x01));

      body.emit(assign(r0BBB, sub(r0BB7, r0BC7), 0x01));

      /* LOOP BEGIN */
      ir_loop *f0BDD = new(mem_ctx) ir_loop();
      exec_list *const f0BDD_parent_instructions = body.instructions;

         body.instructions = &f0BDD->body_instructions;

         /* IF CONDITION */
         ir_expression *const r0BDF = expr(ir_unop_u2i, r0BBC);
         ir_expression *const r0BE0 = gequal(r0BDF, body.constant(int(0)));
         ir_if *f0BDE = new(mem_ctx) ir_if(operand(r0BE0).val);
         exec_list *const f0BDE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0BDE->then_instructions;

            body.emit(new(mem_ctx) ir_loop_jump(ir_loop_jump::jump_break));


         body.instructions = f0BDE_parent_instructions;
         body.emit(f0BDE);

         /* END IF */

         body.emit(assign(r0BBA, add(r0BBA, body.constant(4294901760u)), 0x01));

         ir_variable *const r0BE1 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0BE2 = lshift(r0BB8, body.constant(int(16)));
         body.emit(assign(r0BE1, add(r0BBB, r0BE2), 0x01));

         ir_expression *const r0BE3 = add(r0BBC, r0BBD);
         ir_expression *const r0BE4 = less(r0BE1, r0BBB);
         ir_expression *const r0BE5 = expr(ir_unop_b2i, r0BE4);
         ir_expression *const r0BE6 = expr(ir_unop_i2u, r0BE5);
         body.emit(assign(r0BBC, add(r0BE3, r0BE6), 0x01));

         body.emit(assign(r0BBB, r0BE1, 0x01));

      /* LOOP END */

      body.instructions = f0BDD_parent_instructions;
      body.emit(f0BDD);

      ir_expression *const r0BE7 = lshift(r0BBC, body.constant(int(16)));
      ir_expression *const r0BE8 = rshift(r0BBB, body.constant(int(16)));
      body.emit(assign(r0BBC, bit_or(r0BE7, r0BE8), 0x01));

      ir_variable *const r0BE9 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
      /* IF CONDITION */
      ir_expression *const r0BEB = lshift(r0BBD, body.constant(int(16)));
      ir_expression *const r0BEC = lequal(r0BEB, r0BBC);
      ir_if *f0BEA = new(mem_ctx) ir_if(operand(r0BEC).val);
      exec_list *const f0BEA_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BEA->then_instructions;

         body.emit(assign(r0BE9, body.constant(65535u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BEA->else_instructions;

         body.emit(assign(r0BE9, expr(ir_binop_div, r0BBC, r0BBD), 0x01));


      body.instructions = f0BEA_parent_instructions;
      body.emit(f0BEA);

      /* END IF */

      body.emit(assign(r0BBA, bit_or(r0BBA, r0BE9), 0x01));

      body.emit(assign(r0BB9, r0BBA, 0x01));


   body.instructions = f0BBE_parent_instructions;
   body.emit(f0BBE);

   /* END IF */

   body.emit(ret(r0BB9));

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

   ir_variable *const r0BED = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0BED);
   ir_variable *const r0BEE = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0BEF = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0BEF);
   body.emit(assign(r0BEF, body.constant(0u), 0x01));

   ir_variable *const r0BF0 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0BF0, bit_and(swizzle_y(r0BED), body.constant(1048575u)), 0x01));

   ir_variable *const r0BF1 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0BF2 = rshift(swizzle_y(r0BED), body.constant(int(20)));
   ir_expression *const r0BF3 = bit_and(r0BF2, body.constant(2047u));
   body.emit(assign(r0BF1, expr(ir_unop_u2i, r0BF3), 0x01));

   ir_variable *const r0BF4 = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0BF4, rshift(swizzle_y(r0BED), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0BF6 = equal(r0BF1, body.constant(int(2047)));
   ir_if *f0BF5 = new(mem_ctx) ir_if(operand(r0BF6).val);
   exec_list *const f0BF5_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0BF5->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0BF8 = bit_or(r0BF0, swizzle_x(r0BED));
      ir_expression *const r0BF9 = nequal(r0BF8, body.constant(0u));
      ir_if *f0BF7 = new(mem_ctx) ir_if(operand(r0BF9).val);
      exec_list *const f0BF7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0BF7->then_instructions;

         ir_variable *const r0BFA = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0BFA, lshift(swizzle_x(r0BED), body.constant(int(12))), 0x01));

         ir_expression *const r0BFB = lshift(r0BF4, body.constant(int(31)));
         ir_expression *const r0BFC = bit_or(r0BFB, body.constant(2143289344u));
         ir_expression *const r0BFD = lshift(swizzle_y(r0BED), body.constant(int(12)));
         ir_expression *const r0BFE = rshift(swizzle_x(r0BED), body.constant(int(20)));
         ir_expression *const r0BFF = bit_or(r0BFD, r0BFE);
         ir_expression *const r0C00 = rshift(r0BFF, body.constant(int(9)));
         ir_expression *const r0C01 = bit_or(r0BFC, r0C00);
         body.emit(assign(r0BEE, expr(ir_unop_bitcast_u2f, r0C01), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0BF7->else_instructions;

         ir_expression *const r0C02 = lshift(r0BF4, body.constant(int(31)));
         ir_expression *const r0C03 = add(r0C02, body.constant(2139095040u));
         body.emit(assign(r0BEE, expr(ir_unop_bitcast_u2f, r0C03), 0x01));


      body.instructions = f0BF7_parent_instructions;
      body.emit(f0BF7);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0BF5->else_instructions;

      ir_variable *const r0C04 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0C04);
      ir_variable *const r0C05 = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0C05);
      ir_expression *const r0C06 = lshift(r0BF0, body.constant(int(10)));
      ir_expression *const r0C07 = rshift(swizzle_x(r0BED), body.constant(int(22)));
      ir_expression *const r0C08 = bit_or(r0C06, r0C07);
      ir_expression *const r0C09 = lshift(swizzle_x(r0BED), body.constant(int(10)));
      ir_expression *const r0C0A = nequal(r0C09, body.constant(0u));
      ir_expression *const r0C0B = expr(ir_unop_b2i, r0C0A);
      ir_expression *const r0C0C = expr(ir_unop_i2u, r0C0B);
      body.emit(assign(r0C04, bit_or(r0C08, r0C0C), 0x01));

      body.emit(assign(r0C05, rshift(r0BF0, body.constant(int(22))), 0x01));

      body.emit(assign(r0BEF, r0C04, 0x01));

      /* IF CONDITION */
      ir_expression *const r0C0E = nequal(r0BF1, body.constant(int(0)));
      ir_if *f0C0D = new(mem_ctx) ir_if(operand(r0C0E).val);
      exec_list *const f0C0D_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C0D->then_instructions;

         body.emit(assign(r0BEF, bit_or(r0C04, body.constant(1073741824u)), 0x01));


      body.instructions = f0C0D_parent_instructions;
      body.emit(f0C0D);

      /* END IF */

      ir_variable *const r0C0F = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0C0F, add(r0BF1, body.constant(int(-897))), 0x01));

      ir_variable *const r0C10 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0C10, r0BEF, 0x01));

      ir_variable *const r0C11 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0C11, body.constant(true), 0x01));

      ir_variable *const r0C12 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0C13 = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0C13);
      ir_expression *const r0C14 = bit_and(r0BEF, body.constant(127u));
      body.emit(assign(r0C13, expr(ir_unop_u2i, r0C14), 0x01));

      /* IF CONDITION */
      ir_expression *const r0C16 = expr(ir_unop_i2u, r0C0F);
      ir_expression *const r0C17 = lequal(body.constant(253u), r0C16);
      ir_if *f0C15 = new(mem_ctx) ir_if(operand(r0C17).val);
      exec_list *const f0C15_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C15->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C19 = less(body.constant(int(253)), r0C0F);
         ir_expression *const r0C1A = equal(r0C0F, body.constant(int(253)));
         ir_expression *const r0C1B = expr(ir_unop_u2i, r0BEF);
         ir_expression *const r0C1C = less(r0C1B, body.constant(int(-64)));
         ir_expression *const r0C1D = logic_and(r0C1A, r0C1C);
         ir_expression *const r0C1E = logic_or(r0C19, r0C1D);
         ir_if *f0C18 = new(mem_ctx) ir_if(operand(r0C1E).val);
         exec_list *const f0C18_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C18->then_instructions;

            ir_expression *const r0C1F = lshift(r0BF4, body.constant(int(31)));
            ir_expression *const r0C20 = add(r0C1F, body.constant(2139095040u));
            body.emit(assign(r0C12, expr(ir_unop_bitcast_u2f, r0C20), 0x01));

            body.emit(assign(r0C11, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C18->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0C22 = less(r0C0F, body.constant(int(0)));
            ir_if *f0C21 = new(mem_ctx) ir_if(operand(r0C22).val);
            exec_list *const f0C21_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C21->then_instructions;

               ir_variable *const r0C23 = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0C23, neg(r0C0F), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C25 = less(r0C23, body.constant(int(32)));
               ir_if *f0C24 = new(mem_ctx) ir_if(operand(r0C25).val);
               exec_list *const f0C24_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C24->then_instructions;

                  ir_expression *const r0C26 = rshift(r0BEF, r0C23);
                  ir_expression *const r0C27 = neg(r0C23);
                  ir_expression *const r0C28 = bit_and(r0C27, body.constant(int(31)));
                  ir_expression *const r0C29 = lshift(r0BEF, r0C28);
                  ir_expression *const r0C2A = nequal(r0C29, body.constant(0u));
                  ir_expression *const r0C2B = expr(ir_unop_b2i, r0C2A);
                  ir_expression *const r0C2C = expr(ir_unop_i2u, r0C2B);
                  body.emit(assign(r0C10, bit_or(r0C26, r0C2C), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0C24->else_instructions;

                  ir_expression *const r0C2D = nequal(r0C10, body.constant(0u));
                  ir_expression *const r0C2E = expr(ir_unop_b2i, r0C2D);
                  body.emit(assign(r0C10, expr(ir_unop_i2u, r0C2E), 0x01));


               body.instructions = f0C24_parent_instructions;
               body.emit(f0C24);

               /* END IF */

               body.emit(assign(r0C0F, body.constant(int(0)), 0x01));

               ir_expression *const r0C2F = expr(ir_unop_u2i, r0C10);
               body.emit(assign(r0C13, bit_and(r0C2F, body.constant(int(127))), 0x01));


            body.instructions = f0C21_parent_instructions;
            body.emit(f0C21);

            /* END IF */


         body.instructions = f0C18_parent_instructions;
         body.emit(f0C18);

         /* END IF */


      body.instructions = f0C15_parent_instructions;
      body.emit(f0C15);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C30 = new(mem_ctx) ir_if(operand(r0C11).val);
      exec_list *const f0C30_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C30->then_instructions;

         ir_expression *const r0C31 = add(r0C10, body.constant(64u));
         body.emit(assign(r0C10, rshift(r0C31, body.constant(int(7))), 0x01));

         ir_expression *const r0C32 = bit_xor(r0C13, body.constant(int(64)));
         ir_expression *const r0C33 = equal(r0C32, body.constant(int(0)));
         ir_expression *const r0C34 = expr(ir_unop_b2i, r0C33);
         ir_expression *const r0C35 = expr(ir_unop_i2u, r0C34);
         ir_expression *const r0C36 = expr(ir_unop_bit_not, r0C35);
         body.emit(assign(r0C10, bit_and(r0C10, r0C36), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C38 = equal(r0C10, body.constant(0u));
         ir_if *f0C37 = new(mem_ctx) ir_if(operand(r0C38).val);
         exec_list *const f0C37_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C37->then_instructions;

            body.emit(assign(r0C0F, body.constant(int(0)), 0x01));


         body.instructions = f0C37_parent_instructions;
         body.emit(f0C37);

         /* END IF */

         ir_expression *const r0C39 = lshift(r0BF4, body.constant(int(31)));
         ir_expression *const r0C3A = expr(ir_unop_i2u, r0C0F);
         ir_expression *const r0C3B = lshift(r0C3A, body.constant(int(23)));
         ir_expression *const r0C3C = add(r0C39, r0C3B);
         ir_expression *const r0C3D = add(r0C3C, r0C10);
         body.emit(assign(r0C12, expr(ir_unop_bitcast_u2f, r0C3D), 0x01));

         body.emit(assign(r0C11, body.constant(false), 0x01));


      body.instructions = f0C30_parent_instructions;
      body.emit(f0C30);

      /* END IF */

      body.emit(assign(r0BEE, r0C12, 0x01));


   body.instructions = f0BF5_parent_instructions;
   body.emit(f0BF5);

   /* END IF */

   ir_variable *const r0C3E = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C3E, body.constant(true), 0x01));

   ir_variable *const r0C3F = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C40 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0C40);
   ir_variable *const r0C41 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0C41);
   ir_variable *const r0C42 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0C42);
   ir_variable *const r0C43 = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0C44 = expr(ir_unop_sqrt, r0BEE);
   body.emit(assign(r0C43, expr(ir_unop_bitcast_f2u, r0C44), 0x01));

   ir_variable *const r0C45 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0C45, bit_and(r0C43, body.constant(8388607u)), 0x01));

   body.emit(assign(r0C42, r0C45, 0x01));

   ir_variable *const r0C46 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C47 = rshift(r0C43, body.constant(int(23)));
   ir_expression *const r0C48 = bit_and(r0C47, body.constant(255u));
   body.emit(assign(r0C46, expr(ir_unop_u2i, r0C48), 0x01));

   body.emit(assign(r0C41, r0C46, 0x01));

   body.emit(assign(r0C40, rshift(r0C43, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C4A = equal(r0C46, body.constant(int(255)));
   ir_if *f0C49 = new(mem_ctx) ir_if(operand(r0C4A).val);
   exec_list *const f0C49_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C49->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C4C = nequal(r0C45, body.constant(0u));
      ir_if *f0C4B = new(mem_ctx) ir_if(operand(r0C4C).val);
      exec_list *const f0C4B_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C4B->then_instructions;

         ir_variable *const r0C4D = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C4D, lshift(r0C43, body.constant(int(9))), 0x01));

         ir_variable *const r0C4E = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0C4F = lshift(r0C4D, body.constant(int(20)));
         body.emit(assign(r0C4E, bit_or(r0C4F, body.constant(0u)), 0x01));

         ir_expression *const r0C50 = rshift(r0C4D, body.constant(int(12)));
         ir_expression *const r0C51 = lshift(r0C40, body.constant(int(31)));
         ir_expression *const r0C52 = bit_or(r0C51, body.constant(2146959360u));
         body.emit(assign(r0C4E, bit_or(r0C50, r0C52), 0x02));

         body.emit(assign(r0C3F, r0C4E, 0x03));

         body.emit(assign(r0C3E, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C4B->else_instructions;

         ir_variable *const r0C53 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C53);
         ir_expression *const r0C54 = lshift(r0C40, body.constant(int(31)));
         body.emit(assign(r0C53, add(r0C54, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0C53, body.constant(0u), 0x01));

         body.emit(assign(r0C3F, r0C53, 0x03));

         body.emit(assign(r0C3E, body.constant(false), 0x01));


      body.instructions = f0C4B_parent_instructions;
      body.emit(f0C4B);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C49->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C56 = equal(r0C46, body.constant(int(0)));
      ir_if *f0C55 = new(mem_ctx) ir_if(operand(r0C56).val);
      exec_list *const f0C55_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C55->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0C58 = equal(r0C45, body.constant(0u));
         ir_if *f0C57 = new(mem_ctx) ir_if(operand(r0C58).val);
         exec_list *const f0C57_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C57->then_instructions;

            ir_variable *const r0C59 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0C59);
            body.emit(assign(r0C59, lshift(r0C40, body.constant(int(31))), 0x02));

            body.emit(assign(r0C59, body.constant(0u), 0x01));

            body.emit(assign(r0C3F, r0C59, 0x03));

            body.emit(assign(r0C3E, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C57->else_instructions;

            ir_variable *const r0C5A = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0C5A, r0C45, 0x01));

            ir_variable *const r0C5B = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0C5C = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0C5C);
            /* IF CONDITION */
            ir_expression *const r0C5E = equal(r0C45, body.constant(0u));
            ir_if *f0C5D = new(mem_ctx) ir_if(operand(r0C5E).val);
            exec_list *const f0C5D_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0C5D->then_instructions;

               body.emit(assign(r0C5B, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0C5D->else_instructions;

               body.emit(assign(r0C5C, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0C60 = bit_and(r0C45, body.constant(4294901760u));
               ir_expression *const r0C61 = equal(r0C60, body.constant(0u));
               ir_if *f0C5F = new(mem_ctx) ir_if(operand(r0C61).val);
               exec_list *const f0C5F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C5F->then_instructions;

                  body.emit(assign(r0C5C, body.constant(int(16)), 0x01));

                  body.emit(assign(r0C5A, lshift(r0C45, body.constant(int(16))), 0x01));


               body.instructions = f0C5F_parent_instructions;
               body.emit(f0C5F);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C63 = bit_and(r0C5A, body.constant(4278190080u));
               ir_expression *const r0C64 = equal(r0C63, body.constant(0u));
               ir_if *f0C62 = new(mem_ctx) ir_if(operand(r0C64).val);
               exec_list *const f0C62_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C62->then_instructions;

                  body.emit(assign(r0C5C, add(r0C5C, body.constant(int(8))), 0x01));

                  body.emit(assign(r0C5A, lshift(r0C5A, body.constant(int(8))), 0x01));


               body.instructions = f0C62_parent_instructions;
               body.emit(f0C62);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C66 = bit_and(r0C5A, body.constant(4026531840u));
               ir_expression *const r0C67 = equal(r0C66, body.constant(0u));
               ir_if *f0C65 = new(mem_ctx) ir_if(operand(r0C67).val);
               exec_list *const f0C65_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C65->then_instructions;

                  body.emit(assign(r0C5C, add(r0C5C, body.constant(int(4))), 0x01));

                  body.emit(assign(r0C5A, lshift(r0C5A, body.constant(int(4))), 0x01));


               body.instructions = f0C65_parent_instructions;
               body.emit(f0C65);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C69 = bit_and(r0C5A, body.constant(3221225472u));
               ir_expression *const r0C6A = equal(r0C69, body.constant(0u));
               ir_if *f0C68 = new(mem_ctx) ir_if(operand(r0C6A).val);
               exec_list *const f0C68_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C68->then_instructions;

                  body.emit(assign(r0C5C, add(r0C5C, body.constant(int(2))), 0x01));

                  body.emit(assign(r0C5A, lshift(r0C5A, body.constant(int(2))), 0x01));


               body.instructions = f0C68_parent_instructions;
               body.emit(f0C68);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0C6C = bit_and(r0C5A, body.constant(2147483648u));
               ir_expression *const r0C6D = equal(r0C6C, body.constant(0u));
               ir_if *f0C6B = new(mem_ctx) ir_if(operand(r0C6D).val);
               exec_list *const f0C6B_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0C6B->then_instructions;

                  body.emit(assign(r0C5C, add(r0C5C, body.constant(int(1))), 0x01));


               body.instructions = f0C6B_parent_instructions;
               body.emit(f0C6B);

               /* END IF */

               body.emit(assign(r0C5B, r0C5C, 0x01));


            body.instructions = f0C5D_parent_instructions;
            body.emit(f0C5D);

            /* END IF */

            ir_variable *const r0C6E = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0C6E, add(r0C5B, body.constant(int(-8))), 0x01));

            body.emit(assign(r0C42, lshift(r0C45, r0C6E), 0x01));

            body.emit(assign(r0C41, sub(body.constant(int(1)), r0C6E), 0x01));

            body.emit(assign(r0C41, add(r0C41, body.constant(int(-1))), 0x01));


         body.instructions = f0C57_parent_instructions;
         body.emit(f0C57);

         /* END IF */


      body.instructions = f0C55_parent_instructions;
      body.emit(f0C55);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0C6F = new(mem_ctx) ir_if(operand(r0C3E).val);
      exec_list *const f0C6F_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C6F->then_instructions;

         ir_variable *const r0C70 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0C70);
         ir_expression *const r0C71 = lshift(r0C40, body.constant(int(31)));
         ir_expression *const r0C72 = add(r0C41, body.constant(int(896)));
         ir_expression *const r0C73 = expr(ir_unop_i2u, r0C72);
         ir_expression *const r0C74 = lshift(r0C73, body.constant(int(20)));
         ir_expression *const r0C75 = add(r0C71, r0C74);
         ir_expression *const r0C76 = rshift(r0C42, body.constant(int(3)));
         body.emit(assign(r0C70, add(r0C75, r0C76), 0x02));

         ir_expression *const r0C77 = lshift(r0C42, body.constant(int(29)));
         body.emit(assign(r0C70, bit_or(r0C77, body.constant(0u)), 0x01));

         body.emit(assign(r0C3F, r0C70, 0x03));

         body.emit(assign(r0C3E, body.constant(false), 0x01));


      body.instructions = f0C6F_parent_instructions;
      body.emit(f0C6F);

      /* END IF */


   body.instructions = f0C49_parent_instructions;
   body.emit(f0C49);

   /* END IF */

   body.emit(ret(r0C3F));

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

   ir_variable *const r0C78 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C78);
   ir_variable *const r0C79 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C7A = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C7B = rshift(swizzle_y(r0C78), body.constant(int(20)));
   ir_expression *const r0C7C = bit_and(r0C7B, body.constant(2047u));
   ir_expression *const r0C7D = expr(ir_unop_u2i, r0C7C);
   body.emit(assign(r0C7A, add(r0C7D, body.constant(int(-1023))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C7F = less(r0C7A, body.constant(int(0)));
   ir_if *f0C7E = new(mem_ctx) ir_if(operand(r0C7F).val);
   exec_list *const f0C7E_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C7E->then_instructions;

      body.emit(assign(r0C79, ir_constant::zero(mem_ctx, glsl_type::uvec2_type), 0x03));


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C7E->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0C81 = greater(r0C7A, body.constant(int(52)));
      ir_if *f0C80 = new(mem_ctx) ir_if(operand(r0C81).val);
      exec_list *const f0C80_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C80->then_instructions;

         body.emit(assign(r0C79, r0C78, 0x03));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C80->else_instructions;

         ir_variable *const r0C82 = body.make_temp(glsl_type::int_type, "assignment_tmp");
         body.emit(assign(r0C82, sub(body.constant(int(52)), r0C7A), 0x01));

         ir_variable *const r0C83 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0C85 = gequal(r0C82, body.constant(int(32)));
         ir_if *f0C84 = new(mem_ctx) ir_if(operand(r0C85).val);
         exec_list *const f0C84_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C84->then_instructions;

            body.emit(assign(r0C83, body.constant(0u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C84->else_instructions;

            body.emit(assign(r0C83, lshift(body.constant(4294967295u), r0C82), 0x01));


         body.instructions = f0C84_parent_instructions;
         body.emit(f0C84);

         /* END IF */

         ir_variable *const r0C86 = body.make_temp(glsl_type::uint_type, "conditional_tmp");
         /* IF CONDITION */
         ir_expression *const r0C88 = less(r0C82, body.constant(int(33)));
         ir_if *f0C87 = new(mem_ctx) ir_if(operand(r0C88).val);
         exec_list *const f0C87_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C87->then_instructions;

            body.emit(assign(r0C86, body.constant(4294967295u), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C87->else_instructions;

            ir_expression *const r0C89 = add(r0C82, body.constant(int(-32)));
            body.emit(assign(r0C86, lshift(body.constant(4294967295u), r0C89), 0x01));


         body.instructions = f0C87_parent_instructions;
         body.emit(f0C87);

         /* END IF */

         ir_variable *const r0C8A = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         body.emit(assign(r0C8A, bit_and(r0C83, swizzle_x(r0C78)), 0x01));

         body.emit(assign(r0C8A, bit_and(r0C86, swizzle_y(r0C78)), 0x02));

         body.emit(assign(r0C79, r0C8A, 0x03));


      body.instructions = f0C80_parent_instructions;
      body.emit(f0C80);

      /* END IF */


   body.instructions = f0C7E_parent_instructions;
   body.emit(f0C7E);

   /* END IF */

   body.emit(ret(r0C79));

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

   ir_variable *const r0C8B = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0C8B);
   ir_variable *const r0C8C = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0C8C, body.constant(true), 0x01));

   ir_variable *const r0C8D = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0C8E = new(mem_ctx) ir_variable(glsl_type::uint_type, "aLo", ir_var_auto);
   body.emit(r0C8E);
   ir_variable *const r0C8F = new(mem_ctx) ir_variable(glsl_type::uint_type, "aHi", ir_var_auto);
   body.emit(r0C8F);
   ir_variable *const r0C90 = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0C91 = rshift(swizzle_y(r0C8B), body.constant(int(20)));
   ir_expression *const r0C92 = bit_and(r0C91, body.constant(2047u));
   ir_expression *const r0C93 = expr(ir_unop_u2i, r0C92);
   body.emit(assign(r0C90, add(r0C93, body.constant(int(-1023))), 0x01));

   body.emit(assign(r0C8F, swizzle_y(r0C8B), 0x01));

   body.emit(assign(r0C8E, swizzle_x(r0C8B), 0x01));

   /* IF CONDITION */
   ir_expression *const r0C95 = less(r0C90, body.constant(int(20)));
   ir_if *f0C94 = new(mem_ctx) ir_if(operand(r0C95).val);
   exec_list *const f0C94_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0C94->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0C97 = less(r0C90, body.constant(int(0)));
      ir_if *f0C96 = new(mem_ctx) ir_if(operand(r0C97).val);
      exec_list *const f0C96_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0C96->then_instructions;

         body.emit(assign(r0C8F, bit_and(swizzle_y(r0C8B), body.constant(2147483648u)), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C99 = equal(r0C90, body.constant(int(-1)));
         ir_expression *const r0C9A = nequal(swizzle_x(r0C8B), body.constant(0u));
         ir_expression *const r0C9B = logic_and(r0C99, r0C9A);
         ir_if *f0C98 = new(mem_ctx) ir_if(operand(r0C9B).val);
         exec_list *const f0C98_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C98->then_instructions;

            body.emit(assign(r0C8F, bit_or(r0C8F, body.constant(1072693248u)), 0x01));


         body.instructions = f0C98_parent_instructions;
         body.emit(f0C98);

         /* END IF */

         body.emit(assign(r0C8E, body.constant(0u), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0C96->else_instructions;

         ir_variable *const r0C9C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0C9C, rshift(body.constant(1048575u), r0C90), 0x01));

         /* IF CONDITION */
         ir_expression *const r0C9E = bit_and(r0C8F, r0C9C);
         ir_expression *const r0C9F = equal(r0C9E, body.constant(0u));
         ir_expression *const r0CA0 = equal(r0C8E, body.constant(0u));
         ir_expression *const r0CA1 = logic_and(r0C9F, r0CA0);
         ir_if *f0C9D = new(mem_ctx) ir_if(operand(r0CA1).val);
         exec_list *const f0C9D_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0C9D->then_instructions;

            body.emit(assign(r0C8D, r0C8B, 0x03));

            body.emit(assign(r0C8C, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0C9D->else_instructions;

            ir_expression *const r0CA2 = rshift(body.constant(524288u), r0C90);
            body.emit(assign(r0C8F, add(r0C8F, r0CA2), 0x01));

            ir_expression *const r0CA3 = expr(ir_unop_bit_not, r0C9C);
            body.emit(assign(r0C8F, bit_and(r0C8F, r0CA3), 0x01));

            body.emit(assign(r0C8E, body.constant(0u), 0x01));


         body.instructions = f0C9D_parent_instructions;
         body.emit(f0C9D);

         /* END IF */


      body.instructions = f0C96_parent_instructions;
      body.emit(f0C96);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0C94->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0CA5 = greater(r0C90, body.constant(int(51)));
      ir_expression *const r0CA6 = equal(r0C90, body.constant(int(1024)));
      ir_expression *const r0CA7 = logic_or(r0CA5, r0CA6);
      ir_if *f0CA4 = new(mem_ctx) ir_if(operand(r0CA7).val);
      exec_list *const f0CA4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CA4->then_instructions;

         body.emit(assign(r0C8D, r0C8B, 0x03));

         body.emit(assign(r0C8C, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CA4->else_instructions;

         ir_variable *const r0CA8 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         ir_expression *const r0CA9 = add(r0C90, body.constant(int(-20)));
         body.emit(assign(r0CA8, rshift(body.constant(4294967295u), r0CA9), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CAB = bit_and(r0C8E, r0CA8);
         ir_expression *const r0CAC = equal(r0CAB, body.constant(0u));
         ir_if *f0CAA = new(mem_ctx) ir_if(operand(r0CAC).val);
         exec_list *const f0CAA_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CAA->then_instructions;

            body.emit(assign(r0C8D, r0C8B, 0x03));

            body.emit(assign(r0C8C, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CAA->else_instructions;

            ir_variable *const r0CAD = body.make_temp(glsl_type::uint_type, "assignment_tmp");
            ir_expression *const r0CAE = sub(body.constant(int(51)), r0C90);
            ir_expression *const r0CAF = lshift(body.constant(1u), r0CAE);
            body.emit(assign(r0CAD, add(r0C8E, r0CAF), 0x01));

            /* IF CONDITION */
            ir_expression *const r0CB1 = less(r0CAD, r0C8E);
            ir_if *f0CB0 = new(mem_ctx) ir_if(operand(r0CB1).val);
            exec_list *const f0CB0_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0CB0->then_instructions;

               body.emit(assign(r0C8F, add(r0C8F, body.constant(1u)), 0x01));


            body.instructions = f0CB0_parent_instructions;
            body.emit(f0CB0);

            /* END IF */

            ir_expression *const r0CB2 = expr(ir_unop_bit_not, r0CA8);
            body.emit(assign(r0C8E, bit_and(r0CAD, r0CB2), 0x01));


         body.instructions = f0CAA_parent_instructions;
         body.emit(f0CAA);

         /* END IF */


      body.instructions = f0CA4_parent_instructions;
      body.emit(f0CA4);

      /* END IF */


   body.instructions = f0C94_parent_instructions;
   body.emit(f0C94);

   /* END IF */

   /* IF CONDITION */
   ir_if *f0CB3 = new(mem_ctx) ir_if(operand(r0C8C).val);
   exec_list *const f0CB3_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CB3->then_instructions;

      body.emit(assign(r0C8B, r0C8E, 0x01));

      body.emit(assign(r0C8B, r0C8F, 0x02));

      body.emit(assign(r0C8D, r0C8B, 0x03));

      body.emit(assign(r0C8C, body.constant(false), 0x01));


   body.instructions = f0CB3_parent_instructions;
   body.emit(f0CB3);

   /* END IF */

   body.emit(ret(r0C8D));

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

   ir_variable *const r0CB4 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "a", ir_var_function_in);
   sig_parameters.push_tail(r0CB4);
   ir_variable *const r0CB5 = body.make_temp(glsl_type::float_type, "return_value");
   ir_variable *const r0CB6 = new(mem_ctx) ir_variable(glsl_type::uint_type, "zFrac", ir_var_auto);
   body.emit(r0CB6);
   body.emit(assign(r0CB6, body.constant(0u), 0x01));

   ir_variable *const r0CB7 = body.make_temp(glsl_type::uint_type, "extractFloat64FracHi_retval");
   body.emit(assign(r0CB7, bit_and(swizzle_y(r0CB4), body.constant(1048575u)), 0x01));

   ir_variable *const r0CB8 = body.make_temp(glsl_type::int_type, "extractFloat64Exp_retval");
   ir_expression *const r0CB9 = rshift(swizzle_y(r0CB4), body.constant(int(20)));
   ir_expression *const r0CBA = bit_and(r0CB9, body.constant(2047u));
   body.emit(assign(r0CB8, expr(ir_unop_u2i, r0CBA), 0x01));

   ir_variable *const r0CBB = body.make_temp(glsl_type::uint_type, "extractFloat64Sign_retval");
   body.emit(assign(r0CBB, rshift(swizzle_y(r0CB4), body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0CBD = equal(r0CB8, body.constant(int(2047)));
   ir_if *f0CBC = new(mem_ctx) ir_if(operand(r0CBD).val);
   exec_list *const f0CBC_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0CBC->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0CBF = bit_or(r0CB7, swizzle_x(r0CB4));
      ir_expression *const r0CC0 = nequal(r0CBF, body.constant(0u));
      ir_if *f0CBE = new(mem_ctx) ir_if(operand(r0CC0).val);
      exec_list *const f0CBE_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CBE->then_instructions;

         ir_variable *const r0CC1 = body.make_temp(glsl_type::uint_type, "z1Ptr");
         body.emit(assign(r0CC1, lshift(swizzle_x(r0CB4), body.constant(int(12))), 0x01));

         ir_expression *const r0CC2 = lshift(r0CBB, body.constant(int(31)));
         ir_expression *const r0CC3 = bit_or(r0CC2, body.constant(2143289344u));
         ir_expression *const r0CC4 = lshift(swizzle_y(r0CB4), body.constant(int(12)));
         ir_expression *const r0CC5 = rshift(swizzle_x(r0CB4), body.constant(int(20)));
         ir_expression *const r0CC6 = bit_or(r0CC4, r0CC5);
         ir_expression *const r0CC7 = rshift(r0CC6, body.constant(int(9)));
         ir_expression *const r0CC8 = bit_or(r0CC3, r0CC7);
         body.emit(assign(r0CB5, expr(ir_unop_bitcast_u2f, r0CC8), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0CBE->else_instructions;

         ir_expression *const r0CC9 = lshift(r0CBB, body.constant(int(31)));
         ir_expression *const r0CCA = add(r0CC9, body.constant(2139095040u));
         body.emit(assign(r0CB5, expr(ir_unop_bitcast_u2f, r0CCA), 0x01));


      body.instructions = f0CBE_parent_instructions;
      body.emit(f0CBE);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0CBC->else_instructions;

      ir_variable *const r0CCB = new(mem_ctx) ir_variable(glsl_type::uint_type, "z1", ir_var_auto);
      body.emit(r0CCB);
      ir_variable *const r0CCC = new(mem_ctx) ir_variable(glsl_type::uint_type, "z0", ir_var_auto);
      body.emit(r0CCC);
      ir_expression *const r0CCD = lshift(r0CB7, body.constant(int(10)));
      ir_expression *const r0CCE = rshift(swizzle_x(r0CB4), body.constant(int(22)));
      ir_expression *const r0CCF = bit_or(r0CCD, r0CCE);
      ir_expression *const r0CD0 = lshift(swizzle_x(r0CB4), body.constant(int(10)));
      ir_expression *const r0CD1 = nequal(r0CD0, body.constant(0u));
      ir_expression *const r0CD2 = expr(ir_unop_b2i, r0CD1);
      ir_expression *const r0CD3 = expr(ir_unop_i2u, r0CD2);
      body.emit(assign(r0CCB, bit_or(r0CCF, r0CD3), 0x01));

      body.emit(assign(r0CCC, rshift(r0CB7, body.constant(int(22))), 0x01));

      body.emit(assign(r0CB6, r0CCB, 0x01));

      /* IF CONDITION */
      ir_expression *const r0CD5 = nequal(r0CB8, body.constant(int(0)));
      ir_if *f0CD4 = new(mem_ctx) ir_if(operand(r0CD5).val);
      exec_list *const f0CD4_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CD4->then_instructions;

         body.emit(assign(r0CB6, bit_or(r0CCB, body.constant(1073741824u)), 0x01));


      body.instructions = f0CD4_parent_instructions;
      body.emit(f0CD4);

      /* END IF */

      ir_variable *const r0CD6 = body.make_temp(glsl_type::int_type, "zExp");
      body.emit(assign(r0CD6, add(r0CB8, body.constant(int(-897))), 0x01));

      ir_variable *const r0CD7 = body.make_temp(glsl_type::uint_type, "zFrac");
      body.emit(assign(r0CD7, r0CB6, 0x01));

      ir_variable *const r0CD8 = body.make_temp(glsl_type::bool_type, "execute_flag");
      body.emit(assign(r0CD8, body.constant(true), 0x01));

      ir_variable *const r0CD9 = body.make_temp(glsl_type::float_type, "return_value");
      ir_variable *const r0CDA = new(mem_ctx) ir_variable(glsl_type::int_type, "roundBits", ir_var_auto);
      body.emit(r0CDA);
      ir_expression *const r0CDB = bit_and(r0CB6, body.constant(127u));
      body.emit(assign(r0CDA, expr(ir_unop_u2i, r0CDB), 0x01));

      /* IF CONDITION */
      ir_expression *const r0CDD = expr(ir_unop_i2u, r0CD6);
      ir_expression *const r0CDE = lequal(body.constant(253u), r0CDD);
      ir_if *f0CDC = new(mem_ctx) ir_if(operand(r0CDE).val);
      exec_list *const f0CDC_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CDC->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0CE0 = less(body.constant(int(253)), r0CD6);
         ir_expression *const r0CE1 = equal(r0CD6, body.constant(int(253)));
         ir_expression *const r0CE2 = expr(ir_unop_u2i, r0CB6);
         ir_expression *const r0CE3 = less(r0CE2, body.constant(int(-64)));
         ir_expression *const r0CE4 = logic_and(r0CE1, r0CE3);
         ir_expression *const r0CE5 = logic_or(r0CE0, r0CE4);
         ir_if *f0CDF = new(mem_ctx) ir_if(operand(r0CE5).val);
         exec_list *const f0CDF_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CDF->then_instructions;

            ir_expression *const r0CE6 = lshift(r0CBB, body.constant(int(31)));
            ir_expression *const r0CE7 = add(r0CE6, body.constant(2139095040u));
            body.emit(assign(r0CD9, expr(ir_unop_bitcast_u2f, r0CE7), 0x01));

            body.emit(assign(r0CD8, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0CDF->else_instructions;

            /* IF CONDITION */
            ir_expression *const r0CE9 = less(r0CD6, body.constant(int(0)));
            ir_if *f0CE8 = new(mem_ctx) ir_if(operand(r0CE9).val);
            exec_list *const f0CE8_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0CE8->then_instructions;

               ir_variable *const r0CEA = body.make_temp(glsl_type::int_type, "assignment_tmp");
               body.emit(assign(r0CEA, neg(r0CD6), 0x01));

               /* IF CONDITION */
               ir_expression *const r0CEC = less(r0CEA, body.constant(int(32)));
               ir_if *f0CEB = new(mem_ctx) ir_if(operand(r0CEC).val);
               exec_list *const f0CEB_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0CEB->then_instructions;

                  ir_expression *const r0CED = rshift(r0CB6, r0CEA);
                  ir_expression *const r0CEE = neg(r0CEA);
                  ir_expression *const r0CEF = bit_and(r0CEE, body.constant(int(31)));
                  ir_expression *const r0CF0 = lshift(r0CB6, r0CEF);
                  ir_expression *const r0CF1 = nequal(r0CF0, body.constant(0u));
                  ir_expression *const r0CF2 = expr(ir_unop_b2i, r0CF1);
                  ir_expression *const r0CF3 = expr(ir_unop_i2u, r0CF2);
                  body.emit(assign(r0CD7, bit_or(r0CED, r0CF3), 0x01));


                  /* ELSE INSTRUCTIONS */
                  body.instructions = &f0CEB->else_instructions;

                  ir_expression *const r0CF4 = nequal(r0CD7, body.constant(0u));
                  ir_expression *const r0CF5 = expr(ir_unop_b2i, r0CF4);
                  body.emit(assign(r0CD7, expr(ir_unop_i2u, r0CF5), 0x01));


               body.instructions = f0CEB_parent_instructions;
               body.emit(f0CEB);

               /* END IF */

               body.emit(assign(r0CD6, body.constant(int(0)), 0x01));

               ir_expression *const r0CF6 = expr(ir_unop_u2i, r0CD7);
               body.emit(assign(r0CDA, bit_and(r0CF6, body.constant(int(127))), 0x01));


            body.instructions = f0CE8_parent_instructions;
            body.emit(f0CE8);

            /* END IF */


         body.instructions = f0CDF_parent_instructions;
         body.emit(f0CDF);

         /* END IF */


      body.instructions = f0CDC_parent_instructions;
      body.emit(f0CDC);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0CF7 = new(mem_ctx) ir_if(operand(r0CD8).val);
      exec_list *const f0CF7_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0CF7->then_instructions;

         ir_expression *const r0CF8 = add(r0CD7, body.constant(64u));
         body.emit(assign(r0CD7, rshift(r0CF8, body.constant(int(7))), 0x01));

         ir_expression *const r0CF9 = bit_xor(r0CDA, body.constant(int(64)));
         ir_expression *const r0CFA = equal(r0CF9, body.constant(int(0)));
         ir_expression *const r0CFB = expr(ir_unop_b2i, r0CFA);
         ir_expression *const r0CFC = expr(ir_unop_i2u, r0CFB);
         ir_expression *const r0CFD = expr(ir_unop_bit_not, r0CFC);
         body.emit(assign(r0CD7, bit_and(r0CD7, r0CFD), 0x01));

         /* IF CONDITION */
         ir_expression *const r0CFF = equal(r0CD7, body.constant(0u));
         ir_if *f0CFE = new(mem_ctx) ir_if(operand(r0CFF).val);
         exec_list *const f0CFE_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0CFE->then_instructions;

            body.emit(assign(r0CD6, body.constant(int(0)), 0x01));


         body.instructions = f0CFE_parent_instructions;
         body.emit(f0CFE);

         /* END IF */

         ir_expression *const r0D00 = lshift(r0CBB, body.constant(int(31)));
         ir_expression *const r0D01 = expr(ir_unop_i2u, r0CD6);
         ir_expression *const r0D02 = lshift(r0D01, body.constant(int(23)));
         ir_expression *const r0D03 = add(r0D00, r0D02);
         ir_expression *const r0D04 = add(r0D03, r0CD7);
         body.emit(assign(r0CD9, expr(ir_unop_bitcast_u2f, r0D04), 0x01));

         body.emit(assign(r0CD8, body.constant(false), 0x01));


      body.instructions = f0CF7_parent_instructions;
      body.emit(f0CF7);

      /* END IF */

      body.emit(assign(r0CB5, r0CD9, 0x01));


   body.instructions = f0CBC_parent_instructions;
   body.emit(f0CBC);

   /* END IF */

   ir_variable *const r0D05 = body.make_temp(glsl_type::bool_type, "execute_flag");
   body.emit(assign(r0D05, body.constant(true), 0x01));

   ir_variable *const r0D06 = body.make_temp(glsl_type::uvec2_type, "return_value");
   ir_variable *const r0D07 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aSign", ir_var_auto);
   body.emit(r0D07);
   ir_variable *const r0D08 = new(mem_ctx) ir_variable(glsl_type::int_type, "aExp", ir_var_auto);
   body.emit(r0D08);
   ir_variable *const r0D09 = new(mem_ctx) ir_variable(glsl_type::uint_type, "aFrac", ir_var_auto);
   body.emit(r0D09);
   ir_variable *const r0D0A = body.make_temp(glsl_type::uint_type, "floatBitsToUint_retval");
   ir_expression *const r0D0B = expr(ir_unop_rcp, r0CB5);
   body.emit(assign(r0D0A, expr(ir_unop_bitcast_f2u, r0D0B), 0x01));

   ir_variable *const r0D0C = body.make_temp(glsl_type::uint_type, "assignment_tmp");
   body.emit(assign(r0D0C, bit_and(r0D0A, body.constant(8388607u)), 0x01));

   body.emit(assign(r0D09, r0D0C, 0x01));

   ir_variable *const r0D0D = body.make_temp(glsl_type::int_type, "assignment_tmp");
   ir_expression *const r0D0E = rshift(r0D0A, body.constant(int(23)));
   ir_expression *const r0D0F = bit_and(r0D0E, body.constant(255u));
   body.emit(assign(r0D0D, expr(ir_unop_u2i, r0D0F), 0x01));

   body.emit(assign(r0D08, r0D0D, 0x01));

   body.emit(assign(r0D07, rshift(r0D0A, body.constant(int(31))), 0x01));

   /* IF CONDITION */
   ir_expression *const r0D11 = equal(r0D0D, body.constant(int(255)));
   ir_if *f0D10 = new(mem_ctx) ir_if(operand(r0D11).val);
   exec_list *const f0D10_parent_instructions = body.instructions;

      /* THEN INSTRUCTIONS */
      body.instructions = &f0D10->then_instructions;

      /* IF CONDITION */
      ir_expression *const r0D13 = nequal(r0D0C, body.constant(0u));
      ir_if *f0D12 = new(mem_ctx) ir_if(operand(r0D13).val);
      exec_list *const f0D12_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D12->then_instructions;

         ir_variable *const r0D14 = body.make_temp(glsl_type::uint_type, "assignment_tmp");
         body.emit(assign(r0D14, lshift(r0D0A, body.constant(int(9))), 0x01));

         ir_variable *const r0D15 = body.make_temp(glsl_type::uvec2_type, "vec_ctor");
         ir_expression *const r0D16 = lshift(r0D14, body.constant(int(20)));
         body.emit(assign(r0D15, bit_or(r0D16, body.constant(0u)), 0x01));

         ir_expression *const r0D17 = rshift(r0D14, body.constant(int(12)));
         ir_expression *const r0D18 = lshift(r0D07, body.constant(int(31)));
         ir_expression *const r0D19 = bit_or(r0D18, body.constant(2146959360u));
         body.emit(assign(r0D15, bit_or(r0D17, r0D19), 0x02));

         body.emit(assign(r0D06, r0D15, 0x03));

         body.emit(assign(r0D05, body.constant(false), 0x01));


         /* ELSE INSTRUCTIONS */
         body.instructions = &f0D12->else_instructions;

         ir_variable *const r0D1A = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D1A);
         ir_expression *const r0D1B = lshift(r0D07, body.constant(int(31)));
         body.emit(assign(r0D1A, add(r0D1B, body.constant(2146435072u)), 0x02));

         body.emit(assign(r0D1A, body.constant(0u), 0x01));

         body.emit(assign(r0D06, r0D1A, 0x03));

         body.emit(assign(r0D05, body.constant(false), 0x01));


      body.instructions = f0D12_parent_instructions;
      body.emit(f0D12);

      /* END IF */


      /* ELSE INSTRUCTIONS */
      body.instructions = &f0D10->else_instructions;

      /* IF CONDITION */
      ir_expression *const r0D1D = equal(r0D0D, body.constant(int(0)));
      ir_if *f0D1C = new(mem_ctx) ir_if(operand(r0D1D).val);
      exec_list *const f0D1C_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D1C->then_instructions;

         /* IF CONDITION */
         ir_expression *const r0D1F = equal(r0D0C, body.constant(0u));
         ir_if *f0D1E = new(mem_ctx) ir_if(operand(r0D1F).val);
         exec_list *const f0D1E_parent_instructions = body.instructions;

            /* THEN INSTRUCTIONS */
            body.instructions = &f0D1E->then_instructions;

            ir_variable *const r0D20 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
            body.emit(r0D20);
            body.emit(assign(r0D20, lshift(r0D07, body.constant(int(31))), 0x02));

            body.emit(assign(r0D20, body.constant(0u), 0x01));

            body.emit(assign(r0D06, r0D20, 0x03));

            body.emit(assign(r0D05, body.constant(false), 0x01));


            /* ELSE INSTRUCTIONS */
            body.instructions = &f0D1E->else_instructions;

            ir_variable *const r0D21 = body.make_temp(glsl_type::uint_type, "a");
            body.emit(assign(r0D21, r0D0C, 0x01));

            ir_variable *const r0D22 = body.make_temp(glsl_type::int_type, "return_value");
            ir_variable *const r0D23 = new(mem_ctx) ir_variable(glsl_type::int_type, "shiftCount", ir_var_auto);
            body.emit(r0D23);
            /* IF CONDITION */
            ir_expression *const r0D25 = equal(r0D0C, body.constant(0u));
            ir_if *f0D24 = new(mem_ctx) ir_if(operand(r0D25).val);
            exec_list *const f0D24_parent_instructions = body.instructions;

               /* THEN INSTRUCTIONS */
               body.instructions = &f0D24->then_instructions;

               body.emit(assign(r0D22, body.constant(int(32)), 0x01));


               /* ELSE INSTRUCTIONS */
               body.instructions = &f0D24->else_instructions;

               body.emit(assign(r0D23, body.constant(int(0)), 0x01));

               /* IF CONDITION */
               ir_expression *const r0D27 = bit_and(r0D0C, body.constant(4294901760u));
               ir_expression *const r0D28 = equal(r0D27, body.constant(0u));
               ir_if *f0D26 = new(mem_ctx) ir_if(operand(r0D28).val);
               exec_list *const f0D26_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D26->then_instructions;

                  body.emit(assign(r0D23, body.constant(int(16)), 0x01));

                  body.emit(assign(r0D21, lshift(r0D0C, body.constant(int(16))), 0x01));


               body.instructions = f0D26_parent_instructions;
               body.emit(f0D26);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D2A = bit_and(r0D21, body.constant(4278190080u));
               ir_expression *const r0D2B = equal(r0D2A, body.constant(0u));
               ir_if *f0D29 = new(mem_ctx) ir_if(operand(r0D2B).val);
               exec_list *const f0D29_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D29->then_instructions;

                  body.emit(assign(r0D23, add(r0D23, body.constant(int(8))), 0x01));

                  body.emit(assign(r0D21, lshift(r0D21, body.constant(int(8))), 0x01));


               body.instructions = f0D29_parent_instructions;
               body.emit(f0D29);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D2D = bit_and(r0D21, body.constant(4026531840u));
               ir_expression *const r0D2E = equal(r0D2D, body.constant(0u));
               ir_if *f0D2C = new(mem_ctx) ir_if(operand(r0D2E).val);
               exec_list *const f0D2C_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D2C->then_instructions;

                  body.emit(assign(r0D23, add(r0D23, body.constant(int(4))), 0x01));

                  body.emit(assign(r0D21, lshift(r0D21, body.constant(int(4))), 0x01));


               body.instructions = f0D2C_parent_instructions;
               body.emit(f0D2C);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D30 = bit_and(r0D21, body.constant(3221225472u));
               ir_expression *const r0D31 = equal(r0D30, body.constant(0u));
               ir_if *f0D2F = new(mem_ctx) ir_if(operand(r0D31).val);
               exec_list *const f0D2F_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D2F->then_instructions;

                  body.emit(assign(r0D23, add(r0D23, body.constant(int(2))), 0x01));

                  body.emit(assign(r0D21, lshift(r0D21, body.constant(int(2))), 0x01));


               body.instructions = f0D2F_parent_instructions;
               body.emit(f0D2F);

               /* END IF */

               /* IF CONDITION */
               ir_expression *const r0D33 = bit_and(r0D21, body.constant(2147483648u));
               ir_expression *const r0D34 = equal(r0D33, body.constant(0u));
               ir_if *f0D32 = new(mem_ctx) ir_if(operand(r0D34).val);
               exec_list *const f0D32_parent_instructions = body.instructions;

                  /* THEN INSTRUCTIONS */
                  body.instructions = &f0D32->then_instructions;

                  body.emit(assign(r0D23, add(r0D23, body.constant(int(1))), 0x01));


               body.instructions = f0D32_parent_instructions;
               body.emit(f0D32);

               /* END IF */

               body.emit(assign(r0D22, r0D23, 0x01));


            body.instructions = f0D24_parent_instructions;
            body.emit(f0D24);

            /* END IF */

            ir_variable *const r0D35 = body.make_temp(glsl_type::int_type, "assignment_tmp");
            body.emit(assign(r0D35, add(r0D22, body.constant(int(-8))), 0x01));

            body.emit(assign(r0D09, lshift(r0D0C, r0D35), 0x01));

            body.emit(assign(r0D08, sub(body.constant(int(1)), r0D35), 0x01));

            body.emit(assign(r0D08, add(r0D08, body.constant(int(-1))), 0x01));


         body.instructions = f0D1E_parent_instructions;
         body.emit(f0D1E);

         /* END IF */


      body.instructions = f0D1C_parent_instructions;
      body.emit(f0D1C);

      /* END IF */

      /* IF CONDITION */
      ir_if *f0D36 = new(mem_ctx) ir_if(operand(r0D05).val);
      exec_list *const f0D36_parent_instructions = body.instructions;

         /* THEN INSTRUCTIONS */
         body.instructions = &f0D36->then_instructions;

         ir_variable *const r0D37 = new(mem_ctx) ir_variable(glsl_type::uvec2_type, "z", ir_var_auto);
         body.emit(r0D37);
         ir_expression *const r0D38 = lshift(r0D07, body.constant(int(31)));
         ir_expression *const r0D39 = add(r0D08, body.constant(int(896)));
         ir_expression *const r0D3A = expr(ir_unop_i2u, r0D39);
         ir_expression *const r0D3B = lshift(r0D3A, body.constant(int(20)));
         ir_expression *const r0D3C = add(r0D38, r0D3B);
         ir_expression *const r0D3D = rshift(r0D09, body.constant(int(3)));
         body.emit(assign(r0D37, add(r0D3C, r0D3D), 0x02));

         ir_expression *const r0D3E = lshift(r0D09, body.constant(int(29)));
         body.emit(assign(r0D37, bit_or(r0D3E, body.constant(0u)), 0x01));

         body.emit(assign(r0D06, r0D37, 0x03));

         body.emit(assign(r0D05, body.constant(false), 0x01));


      body.instructions = f0D36_parent_instructions;
      body.emit(f0D36);

      /* END IF */


   body.instructions = f0D10_parent_instructions;
   body.emit(f0D10);

   /* END IF */

   body.emit(ret(r0D06));

   sig->replace_parameters(&sig_parameters);
   return sig;
}
