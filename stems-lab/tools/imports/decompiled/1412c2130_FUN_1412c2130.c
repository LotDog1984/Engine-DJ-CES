// FUN_1412c2130 @ 1412c2130
// calls: [CreateProcessW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_1412c2130(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
             undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  void *pvVar4;
  undefined8 local_278;
  void *pvStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  ulonglong local_258;
  longlong lStack_250;
  longlong local_248;
  longlong lStack_240;
  undefined8 local_238;
  void *local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  ulonglong uStack_210;
  void *local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  ulonglong uStack_1f0;
  undefined1 local_1e8;
  void *local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  ulonglong uStack_1c0;
  void *local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  ulonglong uStack_1a0;
  undefined1 local_198;
  undefined8 local_190;
  void **local_178;
  undefined8 *local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined4 local_108 [2];
  undefined4 local_100 [2];
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined4 *local_90;
  undefined4 local_88;
  undefined **local_80;
  undefined1 local_78 [16];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  void ***local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_150 = param_5;
  local_148 = param_6;
  local_140 = param_7;
  local_138 = param_8;
  local_130 = param_9;
  local_128 = param_10;
  local_120 = param_11;
  local_118 = param_12;
  param_5 = &local_168;
  local_278 = 0;
  local_268 = 0;
  uStack_260 = 0;
  local_258 = 7;
  pvStack_270 = (void *)0x0;
  lStack_250 = 0;
  local_248 = 0;
  lStack_240 = 0;
  local_238 = 0;
  local_168 = param_2;
  local_160 = param_3;
  local_158 = param_4;
  FUN_1412c30a0(&param_5,&local_278);
  uVar3 = local_238;
  if (((char)local_278 == '\0') && (lStack_250 == local_248)) {
    if (local_278._1_1_ == '\0') {
      local_228 = pvStack_270;
      uStack_220 = local_268;
      local_218 = uStack_260;
      uStack_210 = local_258;
      uStack_260 = 0;
      local_258 = 7;
      pvStack_270 = (void *)((ulonglong)pvStack_270._2_6_ << 0x10);
      local_208 = (void *)0x0;
      uStack_200 = 0;
      local_1f8 = 0;
      uStack_1f0 = 0;
      FUN_1402a7200(&local_208,0,0);
      local_1e8 = 1;
    }
    else {
      FUN_1412c67c0(&local_228,&pvStack_270);
    }
  }
  else if (local_278._1_1_ == '\0') {
    local_228 = pvStack_270;
    uStack_220 = local_268;
    local_218 = uStack_260;
    uStack_210 = local_258;
    uStack_260 = 0;
    local_258 = 7;
    pvStack_270 = (void *)((ulonglong)pvStack_270._2_6_ << 0x10);
    FUN_1412c6050(&local_208,&local_228,&lStack_250);
    local_1e8 = 0;
  }
  else {
    FUN_1412c73f0(&local_228,&pvStack_270,&lStack_250);
  }
  local_1d8 = local_228;
  uStack_1d0 = uStack_220;
  local_1c8 = local_218;
  uStack_1c0 = uStack_210;
  local_1b8 = local_208;
  uStack_1b0 = uStack_200;
  local_1a8 = local_1f8;
  uStack_1a0 = uStack_1f0;
  local_190 = uVar3;
  local_178 = &local_1d8;
  local_170 = &local_168;
  local_108[0] = 0;
  local_100[0] = 0x68;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = _DAT_141fbee40;
  uStack_b0 = _UNK_141fbee48;
  local_a8 = DAT_141d33570;
  uStack_a0 = _UNK_141d33578;
  local_98 = 0;
  local_90 = local_100;
  local_88 = 0;
  local_80 = &PTR_vftable_14293fd70;
  local_198 = local_1e8;
  FUN_1412c3a30(local_78,&DAT_1423b3430);
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_30 = &local_178;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  FUN_1412c5490(local_108,param_1);
  FUN_1402a0280(local_78);
  if (7 < uStack_1a0) {
    pvVar4 = local_1b8;
    if ((0xfff < uStack_1a0 * 2 + 2) &&
       (pvVar4 = *(void **)((longlong)local_1b8 + -8),
       0x1f < (ulonglong)((longlong)local_1b8 + (-8 - (longlong)pvVar4)))) goto LAB_1412c24bb;
    free(pvVar4);
  }
  local_1a8 = _DAT_141cb0070;
  uStack_1a0 = _UNK_141cb0078;
  local_1b8 = (void *)((ulonglong)local_1b8 & 0xffffffffffff0000);
  if (7 < uStack_1c0) {
    pvVar4 = local_1d8;
    if ((0xfff < uStack_1c0 * 2 + 2) &&
       (pvVar4 = *(void **)((longlong)local_1d8 + -8),
       0x1f < (ulonglong)((longlong)local_1d8 + (-8 - (longlong)pvVar4)))) {
LAB_1412c24bb:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar4);
  }
  lVar2 = local_248;
  local_1c8 = _DAT_141cb0070;
  uStack_1c0 = _UNK_141cb0078;
  local_1d8 = (void *)((ulonglong)local_1d8 & 0xffffffffffff0000);
  lVar1 = lStack_250;
  if (lStack_250 != 0) {
    for (; lVar1 != lVar2; lVar1 = lVar1 + 0x20) {
      FUN_1402a29e0(lVar1);
    }
    FUN_14029db70(&lStack_250,lStack_250,lStack_240 - lStack_250 >> 5);
    lStack_250 = 0;
    local_248 = 0;
    lStack_240 = 0;
  }
  if (7 < local_258) {
    pvVar4 = pvStack_270;
    if ((0xfff < local_258 * 2 + 2) &&
       (pvVar4 = *(void **)((longlong)pvStack_270 + -8),
       0x1f < (ulonglong)((longlong)pvStack_270 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar4);
  }
  return param_1;
}


