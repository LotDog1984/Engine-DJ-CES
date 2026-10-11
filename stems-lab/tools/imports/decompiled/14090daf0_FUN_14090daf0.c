// FUN_14090daf0 @ 14090daf0
// calls: [CreateFileW]

undefined8 * FUN_14090daf0(longlong param_1,undefined8 *param_2)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  uint *puVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  void *pvVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  char *pcVar11;
  uint uVar12;
  undefined1 *puVar13;
  undefined8 *puVar14;
  undefined4 *puVar15;
  undefined1 *puVar16;
  undefined1 local_res8 [8];
  undefined8 *local_res10;
  uint local_res18;
  ulonglong local_res20;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 *local_198;
  undefined4 local_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 local_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined1 local_170;
  undefined7 uStack_16f;
  longlong local_160;
  ulonglong local_158;
  void *local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  ulonglong local_138;
  void *local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  ulonglong local_118;
  void *local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  ulonglong local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  ulonglong local_d8;
  undefined1 local_d0 [8];
  void *local_c8 [3];
  ulonglong local_b0;
  void *local_a8 [3];
  ulonglong local_90;
  void *local_88 [3];
  ulonglong local_70;
  undefined1 local_68 [40];
  
  uVar12 = 1;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 7;
  *(undefined2 *)param_2 = 0;
  local_res18 = 1;
  if (*(char *)(param_1 + 0x51) != '\0') {
    local_res20 = 1;
    puVar3 = (undefined8 *)(param_1 + 0x58);
    local_res10 = param_2;
    local_198 = puVar3;
    do {
      uVar7 = local_res20;
      FUN_14196f1d0(puVar3,&local_190);
      uStack_128 = 0;
      local_120 = 0;
      local_118 = 0xf;
      local_130 = (void *)0x0;
      local_res18 = uVar12 | 6;
      lVar4 = CONCAT44(uStack_17c,local_180);
      if (lVar4 != 0) {
        puVar6 = &local_190;
        if (7 < CONCAT44(uStack_174,uStack_178)) {
          puVar6 = (undefined4 *)CONCAT44(uStack_18c,local_190);
        }
        puVar15 = &local_190;
        if (7 < CONCAT44(uStack_174,uStack_178)) {
          puVar15 = (undefined4 *)CONCAT44(uStack_18c,local_190);
        }
        uVar2 = FUN_14196e970();
        FUN_141971350(puVar15,(longlong)puVar6 + lVar4 * 2,&local_130,uVar2);
        uVar7 = local_res20;
        puVar3 = local_198;
      }
      puVar14 = local_res10;
      local_res20 = uVar7 + 1;
      pcVar11 = (char *)((longlong)&local_1a8 + 5);
      uVar7 = local_res20;
      do {
        pcVar11 = pcVar11 + -1;
        uVar9 = uVar7 / 10;
        *pcVar11 = (char)uVar7 + (char)uVar9 * -10 + '0';
        uVar7 = uVar9;
      } while (uVar9 != 0);
      FUN_1402bae50(local_88,pcVar11,(longlong)&local_1a8 + 5,local_res8);
      local_res18 = uVar12 | 0x1e;
      uStack_e8 = 0;
      local_e0 = 5;
      local_d8 = 0xf;
      local_f0 = (void *)(ulonglong)CONCAT14(s__part_141f2027c[4],s__part_141f2027c._0_4_);
      FUN_14196f3f0(puVar3,local_68);
      local_res18 = uVar12 | 0x3e;
      uStack_108 = 0;
      local_100 = 0;
      local_f8 = 7;
      local_110 = (void *)0x0;
      puVar3 = (undefined8 *)FUN_141970e10(local_68,&local_110);
      uStack_148 = 0;
      local_140 = 0;
      local_138 = 0xf;
      local_150 = (void *)0x0;
      local_res18 = uVar12 | 0x7e;
      lVar4 = puVar3[2];
      if (lVar4 != 0) {
        if (7 < (ulonglong)puVar3[3]) {
          puVar3 = (undefined8 *)*puVar3;
        }
        uVar2 = FUN_14196e970();
        FUN_141971350(puVar3,(longlong)puVar3 + lVar4 * 2,&local_150,uVar2);
      }
      FUN_14029f4d0(local_a8,(ulonglong)param_2 & 0xff,&local_150,&local_f0);
      local_res18 = uVar12 | 0xfe;
      FUN_14029f4d0(local_c8,(ulonglong)param_2 & 0xff,local_a8,local_88);
      local_res18 = uVar12 | 0x1fe;
      FUN_14029f4d0(&local_170,(ulonglong)puVar14 & 0xff,local_c8,&local_130);
      local_res18 = uVar12 | 0x3fe;
      param_2[2] = 0;
      puVar3 = param_2;
      if (7 < (ulonglong)param_2[3]) {
        puVar3 = (undefined8 *)*param_2;
      }
      *(undefined2 *)puVar3 = 0;
      if (local_160 != 0) {
        puVar13 = &local_170;
        if (0xf < local_158) {
          puVar13 = (undefined1 *)CONCAT71(uStack_16f,local_170);
        }
        puVar13 = puVar13 + local_160;
        puVar16 = &local_170;
        if (0xf < local_158) {
          puVar16 = (undefined1 *)CONCAT71(uStack_16f,local_170);
        }
        uVar2 = FUN_14196e970();
        FUN_141971270(puVar16,puVar13,param_2,uVar2);
      }
      if (0xf < local_158) {
        pvVar1 = (void *)CONCAT71(uStack_16f,local_170);
        pvVar8 = pvVar1;
        if ((0xfff < local_158 + 1) &&
           (pvVar8 = *(void **)((longlong)pvVar1 + -8),
           0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      local_160 = 0;
      local_158 = 0xf;
      local_170 = 0;
      if (0xf < local_b0) {
        pvVar8 = local_c8[0];
        if ((0xfff < local_b0 + 1) &&
           (pvVar8 = *(void **)((longlong)local_c8[0] + -8),
           0x1f < (ulonglong)((longlong)local_c8[0] + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      if (0xf < local_90) {
        pvVar8 = local_a8[0];
        if ((0xfff < local_90 + 1) &&
           (pvVar8 = *(void **)((longlong)local_a8[0] + -8),
           0x1f < (ulonglong)((longlong)local_a8[0] + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      if (0xf < local_138) {
        pvVar8 = local_150;
        if ((0xfff < local_138 + 1) &&
           (pvVar8 = *(void **)((longlong)local_150 + -8),
           0x1f < (ulonglong)((longlong)local_150 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      local_140 = 0;
      local_138 = 0xf;
      local_150 = (void *)((ulonglong)local_150 & 0xffffffffffffff00);
      if (7 < local_f8) {
        pvVar8 = local_110;
        if ((0xfff < local_f8 * 2 + 2) &&
           (pvVar8 = *(void **)((longlong)local_110 + -8),
           0x1f < (ulonglong)((longlong)local_110 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      local_100 = 0;
      local_f8 = 7;
      local_110 = (void *)((ulonglong)local_110 & 0xffffffffffff0000);
      FUN_1402a29e0(local_68);
      if (0xf < local_d8) {
        pvVar8 = local_f0;
        if ((0xfff < local_d8 + 1) &&
           (pvVar8 = *(void **)((longlong)local_f0 + -8),
           0x1f < (ulonglong)((longlong)local_f0 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      if (0xf < local_70) {
        pvVar8 = local_88[0];
        if ((0xfff < local_70 + 1) &&
           (pvVar8 = *(void **)((longlong)local_88[0] + -8),
           0x1f < (ulonglong)((longlong)local_88[0] + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      local_res18 = uVar12 | 0x3ba;
      if (0xf < local_118) {
        pvVar8 = local_130;
        if ((0xfff < local_118 + 1) &&
           (pvVar8 = *(void **)((longlong)local_130 + -8),
           0x1f < (ulonglong)((longlong)local_130 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      local_120 = 0;
      local_118 = 0xf;
      local_130 = (void *)((ulonglong)local_130 & 0xffffffffffffff00);
      FUN_1402a29e0(&local_190);
      puVar3 = local_198;
      puVar14 = local_198;
      if (7 < (ulonglong)local_198[3]) {
        puVar14 = (undefined8 *)*local_198;
      }
      lVar4 = FUN_14196f640(local_198);
      puVar14 = (undefined8 *)((longlong)puVar14 + lVar4 * 2);
      puVar10 = puVar3;
      if (7 < (ulonglong)puVar3[3]) {
        puVar10 = (undefined8 *)*puVar3;
      }
      local_1b8 = (void *)0x0;
      uStack_1b0 = 0;
      local_1a8 = 0;
      uStack_1a0 = 0;
      if (puVar10 == puVar14) {
        local_1a8 = 0;
        uStack_1a0 = 7;
        local_1b8 = (void *)0x0;
      }
      else {
        FUN_1402a7200(&local_1b8,puVar10,(longlong)puVar14 - (longlong)puVar10 >> 1);
      }
      local_res18 = uVar12 | 0x7ba;
      FUN_14196e520(&local_1b8,param_2);
      local_190 = (undefined4)local_1b8;
      uStack_18c = local_1b8._4_4_;
      uStack_188 = (undefined4)uStack_1b0;
      uStack_184 = uStack_1b0._4_4_;
      local_180 = (undefined4)local_1a8;
      uStack_17c = local_1a8._4_4_;
      uStack_178 = (undefined4)uStack_1a0;
      uStack_174 = uStack_1a0._4_4_;
      local_1a8 = 0;
      uStack_1a0 = 7;
      local_1b8 = (void *)((ulonglong)local_1b8 & 0xffffffffffff0000);
      uVar12 = uVar12 | 0xfba;
      local_res18 = uVar12;
      FUN_1402ac5a0(param_2,&local_190);
      if (7 < CONCAT44(uStack_174,uStack_178)) {
        pvVar1 = (void *)CONCAT44(uStack_18c,local_190);
        pvVar8 = pvVar1;
        if ((0xfff < CONCAT44(uStack_174,uStack_178) * 2 + 2) &&
           (pvVar8 = *(void **)((longlong)pvVar1 + -8),
           0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      if (7 < uStack_1a0) {
        pvVar8 = local_1b8;
        if ((0xfff < uStack_1a0 * 2 + 2) &&
           (pvVar8 = *(void **)((longlong)local_1b8 + -8),
           0x1f < (ulonglong)((longlong)local_1b8 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
      puVar5 = (uint *)FUN_141974de0(local_d0,param_2,0);
    } while (1 < *puVar5);
  }
  return param_2;
}


