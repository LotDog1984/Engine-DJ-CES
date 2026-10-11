// FUN_140cad0b0 @ 140cad0b0
// calls: [WriteFile, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140cad0b0(undefined8 *param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 ****ppppuVar5;
  void *pvVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  void *pvVar9;
  void *local_res8;
  void *local_res10;
  void **local_res18;
  undefined8 local_198;
  undefined8 uStack_190;
  void *local_188;
  ulonglong uStack_180;
  undefined8 local_178;
  ulonglong uStack_170;
  void *local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  ulonglong uStack_150;
  undefined8 ***local_148 [2];
  ulonglong local_138;
  ulonglong local_130;
  undefined1 local_128 [112];
  undefined1 local_b8 [128];
  
  FUN_140caf720(&local_res8);
  pvVar9 = local_res8;
  FUN_140cb2d90(local_res8,param_1 + 0xb);
  FUN_140cc3c80(local_148,param_2 + 0x48);
  if (((*(longlong *)(param_2 + 0x30) == 0) && (*(int *)(param_2 + 0x68) - 100U < 300)) &&
     (local_138 != 0)) {
    plVar2 = param_1 + 0x26;
    if (0x7fffffffffffffff - param_1[0x28] < local_138) {
                    /* WARNING: Subroutine does not return */
      FUN_14029da10();
    }
    plVar8 = plVar2;
    if (0xf < (ulonglong)param_1[0x29]) {
      plVar8 = (longlong *)*plVar2;
    }
    ppppuVar5 = local_148;
    if (0xf < local_130) {
      ppppuVar5 = (undefined8 ****)local_148[0];
    }
    FUN_14029f6d0(&local_168,(ulonglong)local_res8 & 0xff,plVar2,plVar8,param_1[0x28],ppppuVar5,
                  local_138);
    FUN_1402ac4f0((longlong)pvVar9 + 0xa8,&local_168);
    if (0xf < uStack_150) {
      pvVar6 = local_168;
      if ((0xfff < uStack_150 + 1) &&
         (pvVar6 = *(void **)((longlong)local_168 + -8),
         0x1f < (ulonglong)((longlong)local_168 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    *(undefined8 *)((longlong)pvVar9 + 200) = *(undefined8 *)((longlong)pvVar9 + 0xa0);
    FUN_140cd82f0(&local_res10,*param_1);
    pvVar6 = local_res10;
    if ((local_res10 != (void *)0x0) && (*(longlong *)((longlong)local_res10 + 0xb8) != 0)) {
      FUN_140cca0e0((longlong)local_res10 + 0xa8);
      pvVar6 = local_res10;
    }
    if (pvVar6 != (void *)0x0) {
      FUN_140438620(pvVar6);
      free(pvVar6);
    }
    FUN_140cca360((longlong)pvVar9 + 0xa8,param_2,300);
    FUN_140cd8360(*param_1,pvVar9);
    uVar4 = _UNK_141ac9b08;
    uVar3 = _DAT_141ac9b00;
    local_178 = _DAT_141d2ff30;
    uStack_170 = _UNK_141d2ff38;
    local_188 = (void *)s_text_plain_141fc9868._0_8_;
    uStack_180 = (ulonglong)(ushort)s_text_plain_141fc9868._8_2_;
    uStack_160 = 0;
    local_158 = _DAT_141ac9b00;
    uStack_150 = _UNK_141ac9b08;
    local_168 = (void *)0x0;
    FUN_140cc3e20(local_128,&local_168,0,200,&local_188);
    if (0xf < uStack_150) {
      pvVar6 = local_168;
      if ((0xfff < uStack_150 + 1) &&
         (pvVar6 = *(void **)((longlong)local_168 + -8),
         0x1f < (ulonglong)((longlong)local_168 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    local_158 = uVar3;
    uStack_150 = uVar4;
    local_168 = (void *)((ulonglong)local_168 & 0xffffffffffffff00);
    if (0xf < uStack_170) {
      pvVar6 = local_188;
      if ((0xfff < uStack_170 + 1) &&
         (pvVar6 = *(void **)((longlong)local_188 + -8),
         0x1f < (ulonglong)((longlong)local_188 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    local_178 = uVar3;
    uStack_170 = uVar4;
    local_188 = (void *)((ulonglong)local_188 & 0xffffffffffffff00);
    if (param_1[2] != 0) {
      LOCK();
      piVar1 = (int *)(param_1[2] + 8);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      pvVar9 = local_res8;
    }
    local_198 = param_1[1];
    uStack_190 = param_1[2];
    FUN_140cb5be0(&local_198,local_128);
    local_res8 = (void *)0x0;
    local_res18 = &local_res10;
    plVar2 = (longlong *)param_1[10];
    if (plVar2 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::_Xbad_function_call();
    }
    local_res10 = pvVar9;
    (**(code **)(*plVar2 + 0x10))(plVar2,local_128,&local_res10);
    if (local_res10 != (void *)0x0) {
      FUN_140438620(local_res10);
      free(local_res10);
    }
    puVar7 = local_128;
  }
  else {
    FUN_140cd8360(*param_1,pvVar9);
    uVar4 = _UNK_141ac9b08;
    uVar3 = _DAT_141ac9b00;
    local_178 = _DAT_141d2ff30;
    uStack_170 = _UNK_141d2ff38;
    local_188 = (void *)s_text_plain_141fc9868._0_8_;
    uStack_180 = (ulonglong)(ushort)s_text_plain_141fc9868._8_2_;
    uStack_160 = 0;
    local_158 = _DAT_141ac9b00;
    uStack_150 = _UNK_141ac9b08;
    local_168 = (void *)0x0;
    FUN_140cc3e20(local_b8,&local_168,0,200,&local_188);
    if (0xf < uStack_150) {
      pvVar6 = local_168;
      if ((0xfff < uStack_150 + 1) &&
         (pvVar6 = *(void **)((longlong)local_168 + -8),
         0x1f < (ulonglong)((longlong)local_168 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    local_158 = uVar3;
    uStack_150 = uVar4;
    local_168 = (void *)((ulonglong)local_168 & 0xffffffffffffff00);
    if (0xf < uStack_170) {
      pvVar6 = local_188;
      if ((0xfff < uStack_170 + 1) &&
         (pvVar6 = *(void **)((longlong)local_188 + -8),
         0x1f < (ulonglong)((longlong)local_188 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    local_178 = uVar3;
    uStack_170 = uVar4;
    local_188 = (void *)((ulonglong)local_188 & 0xffffffffffffff00);
    if (param_1[2] != 0) {
      LOCK();
      piVar1 = (int *)(param_1[2] + 8);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      pvVar9 = local_res8;
    }
    local_198 = param_1[1];
    uStack_190 = param_1[2];
    FUN_140cb5be0(&local_198,local_b8);
    local_res8 = (void *)0x0;
    local_res18 = &local_res10;
    plVar2 = (longlong *)param_1[10];
    if (plVar2 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::_Xbad_function_call();
    }
    local_res10 = pvVar9;
    (**(code **)(*plVar2 + 0x10))(plVar2,local_b8,&local_res10);
    if (local_res10 != (void *)0x0) {
      FUN_140438620(local_res10);
      free(local_res10);
    }
    puVar7 = local_b8;
  }
  FUN_140cb2c00(puVar7);
  if (0xf < local_130) {
    ppppuVar5 = (undefined8 ****)local_148[0];
    if ((0xfff < local_130 + 1) &&
       (ppppuVar5 = (undefined8 ****)local_148[0][-1],
       0x1f < (ulonglong)((longlong)local_148[0] + (-8 - (longlong)ppppuVar5)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppuVar5);
  }
  return;
}


