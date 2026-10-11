// FUN_140e16a20 @ 140e16a20
// strings: [.stems]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_140e16a20(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 ****ppppuVar5;
  undefined8 ***pppuVar6;
  void *pvVar7;
  undefined1 local_res20;
  undefined8 ***local_e0;
  undefined8 uStack_d8;
  ulonglong local_d0;
  ulonglong uStack_c8;
  undefined8 ***local_c0;
  undefined8 uStack_b8;
  ulonglong local_b0;
  ulonglong uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  ulonglong local_88;
  undefined8 **local_80;
  undefined8 **ppuStack_78;
  undefined8 **local_70;
  undefined8 **ppuStack_68;
  void *local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong uStack_48;
  undefined1 local_40 [40];
  
  uStack_58 = 0;
  local_50 = _DAT_141cb0070;
  uStack_48 = _UNK_141cb0078;
  local_60 = (void *)0x0;
  uStack_98 = 0;
  local_90 = 5;
  local_88 = 0xf;
  local_a0 = (void *)(ulonglong)CONCAT14(s_Stems_141d329c8[4],s_Stems_141d329c8._0_4_);
  uVar3 = FUN_14196e970();
  FUN_141971270(&local_a0,(longlong)&local_a0 + 5,&local_60,uVar3);
  if (0xf < local_88) {
    pvVar7 = local_a0;
    if ((0xfff < local_88 + 1) &&
       (pvVar7 = *(void **)((longlong)local_a0 + -8),
       0x1f < (ulonglong)((longlong)local_a0 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar7);
  }
  uVar3 = FUN_1403a32e0(local_40,param_3,&local_60);
  puVar4 = (undefined8 *)FUN_14196fa80(uVar3,&local_a0);
  uStack_b8 = 0;
  local_b0 = _DAT_141ac9b00;
  uStack_a8 = _UNK_141ac9b08;
  local_c0 = (undefined8 ****)0x0;
  lVar1 = puVar4[2];
  if (lVar1 != 0) {
    if (7 < (ulonglong)puVar4[3]) {
      puVar4 = (undefined8 *)*puVar4;
    }
    uVar3 = FUN_14196e970();
    FUN_141971350(puVar4,(longlong)puVar4 + lVar1 * 2,&local_c0,uVar3);
  }
  FUN_1402a29e0(&local_a0);
  FUN_1402a29e0(local_40);
  if (7 < uStack_48) {
    pvVar7 = local_60;
    if ((0xfff < uStack_48 * 2 + 2) &&
       (pvVar7 = *(void **)((longlong)local_60 + -8),
       0x1f < (ulonglong)((longlong)local_60 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar7);
  }
  uVar2 = local_b0;
  if (uStack_a8 == local_b0) {
    ppppuVar5 = (undefined8 ****)FUN_14029eeb0(&local_c0,1,local_res20,0x141d310a8,1);
  }
  else {
    local_b0 = local_b0 + 1;
    ppppuVar5 = &local_c0;
    if (0xf < uStack_a8) {
      ppppuVar5 = (undefined8 ****)local_c0;
    }
    *(undefined2 *)((longlong)ppppuVar5 + uVar2) = 0x2f;
    ppppuVar5 = &local_c0;
  }
  local_80 = (undefined8 **)0x0;
  ppuStack_78 = (undefined8 **)0x0;
  local_70 = (undefined8 **)0x0;
  ppuStack_68 = (undefined8 **)0x0;
  local_80 = *ppppuVar5;
  ppuStack_78 = ppppuVar5[1];
  local_70 = ppppuVar5[2];
  ppuStack_68 = ppppuVar5[3];
  ppppuVar5[2] = (undefined8 ***)0x0;
  ppppuVar5[3] = (undefined8 ***)0xf;
  *(undefined1 *)ppppuVar5 = 0;
  puVar4 = param_2 + 2;
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  puVar4 = (undefined8 *)FUN_1402a2ae0(&local_80,param_2,*puVar4);
  local_e0 = (undefined8 ***)*puVar4;
  uStack_d8 = puVar4[1];
  local_d0 = puVar4[2];
  uStack_c8 = puVar4[3];
  puVar4[2] = 0;
  puVar4[3] = 0xf;
  *(undefined1 *)puVar4 = 0;
  if (uStack_c8 - local_d0 < 6) {
    ppppuVar5 = (undefined8 ****)FUN_14029eeb0(&local_e0,6,local_res20,".stems",6);
  }
  else {
    ppppuVar5 = &local_e0;
    if (0xf < uStack_c8) {
      ppppuVar5 = (undefined8 ****)local_e0;
    }
    pvVar7 = (void *)((longlong)ppppuVar5 + local_d0);
    local_d0 = local_d0 + 6;
    memmove(pvVar7,".stems",6);
    *(undefined1 *)((longlong)pvVar7 + 6) = 0;
    ppppuVar5 = &local_e0;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  pppuVar6 = ppppuVar5[1];
  *param_1 = *ppppuVar5;
  param_1[1] = pppuVar6;
  pppuVar6 = ppppuVar5[3];
  param_1[2] = ppppuVar5[2];
  param_1[3] = pppuVar6;
  ppppuVar5[2] = (undefined8 ***)0x0;
  ppppuVar5[3] = (undefined8 ***)0xf;
  *(undefined1 *)ppppuVar5 = 0;
  if (0xf < uStack_c8) {
    ppppuVar5 = (undefined8 ****)local_e0;
    if ((0xfff < uStack_c8 + 1) &&
       (ppppuVar5 = (undefined8 ****)local_e0[-1],
       0x1f < (ulonglong)((longlong)local_e0 + (-8 - (longlong)ppppuVar5)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppuVar5);
  }
  local_d0 = _DAT_141ac9b00;
  uStack_c8 = _UNK_141ac9b08;
  local_e0 = (undefined8 ***)((ulonglong)local_e0 & 0xffffffffffffff00);
  if ((undefined8 ***)0xf < ppuStack_68) {
    pppuVar6 = (undefined8 ***)local_80;
    if ((0xfff < (longlong)ppuStack_68 + 1U) &&
       (pppuVar6 = (undefined8 ***)local_80[-1],
       0x1f < (ulonglong)((longlong)local_80 + (-8 - (longlong)pppuVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pppuVar6);
  }
  local_70 = (undefined8 **)_DAT_141ac9b00;
  ppuStack_68 = (undefined8 **)_UNK_141ac9b08;
  local_80 = (undefined8 **)((ulonglong)local_80 & 0xffffffffffffff00);
  if (0xf < uStack_a8) {
    ppppuVar5 = (undefined8 ****)local_c0;
    if ((0xfff < uStack_a8 + 1) &&
       (ppppuVar5 = (undefined8 ****)local_c0[-1],
       0x1f < (ulonglong)((longlong)local_c0 + (-8 - (longlong)ppppuVar5)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppuVar5);
  }
  return param_1;
}


