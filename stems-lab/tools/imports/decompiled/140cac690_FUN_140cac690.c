// FUN_140cac690 @ 140cac690
// calls: [WriteFile, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140cac690(undefined8 *param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 ****ppppuVar5;
  void *pvVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  ulonglong local_res8;
  void *local_res10;
  undefined8 local_188;
  undefined8 uStack_180;
  void *local_178;
  ulonglong uStack_170;
  undefined8 local_168;
  ulonglong uStack_160;
  void *local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  ulonglong uStack_140;
  undefined8 ***local_138 [2];
  ulonglong local_128;
  ulonglong local_120;
  undefined1 local_118 [112];
  undefined1 local_a8 [128];
  
  FUN_140caf720(&local_res8);
  uVar4 = local_res8;
  FUN_140cb2d90(local_res8,param_1 + 0xd);
  FUN_140cc3c80(local_138,param_2 + 0x48);
  if (((*(longlong *)(param_2 + 0x30) == 0) && (*(int *)(param_2 + 0x68) - 100U < 300)) &&
     (local_128 != 0)) {
    plVar2 = param_1 + 0x28;
    if (0x7fffffffffffffff - param_1[0x2a] < local_128) {
                    /* WARNING: Subroutine does not return */
      FUN_14029da10();
    }
    plVar8 = plVar2;
    if (0xf < (ulonglong)param_1[0x2b]) {
      plVar8 = (longlong *)*plVar2;
    }
    ppppuVar5 = local_138;
    if (0xf < local_120) {
      ppppuVar5 = (undefined8 ****)local_138[0];
    }
    FUN_14029f6d0(&local_158,local_res8 & 0xff,plVar2,plVar8,param_1[0x2a],ppppuVar5,local_128);
    FUN_1402ac4f0(uVar4 + 0xa8,&local_158);
    if (0xf < uStack_140) {
      pvVar6 = local_158;
      if ((0xfff < uStack_140 + 1) &&
         (pvVar6 = *(void **)((longlong)local_158 + -8),
         0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    *(undefined8 *)(uVar4 + 200) = *(undefined8 *)(uVar4 + 0xa0);
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
    FUN_140cca360(uVar4 + 0xa8,param_2,300);
    FUN_140cd8360(*param_1,uVar4);
    uVar4 = _UNK_141ac9b08;
    uVar3 = _DAT_141ac9b00;
    local_168 = _DAT_141d2ff30;
    uStack_160 = _UNK_141d2ff38;
    local_178 = (void *)s_text_plain_141fc9868._0_8_;
    uStack_170 = (ulonglong)(ushort)s_text_plain_141fc9868._8_2_;
    uStack_150 = 0;
    local_148 = _DAT_141ac9b00;
    uStack_140 = _UNK_141ac9b08;
    local_158 = (void *)0x0;
    FUN_140cc3e20(local_118,&local_158,0,200,&local_178);
    if (0xf < uStack_140) {
      pvVar6 = local_158;
      if ((0xfff < uStack_140 + 1) &&
         (pvVar6 = *(void **)((longlong)local_158 + -8),
         0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    local_148 = uVar3;
    uStack_140 = uVar4;
    local_158 = (void *)((ulonglong)local_158 & 0xffffffffffffff00);
    if (0xf < uStack_160) {
      pvVar6 = local_178;
      if ((0xfff < uStack_160 + 1) &&
         (pvVar6 = *(void **)((longlong)local_178 + -8),
         0x1f < (ulonglong)((longlong)local_178 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    local_168 = uVar3;
    uStack_160 = uVar4;
    local_178 = (void *)((ulonglong)local_178 & 0xffffffffffffff00);
    if (param_1[2] != 0) {
      LOCK();
      piVar1 = (int *)(param_1[2] + 8);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    local_188 = param_1[1];
    uStack_180 = param_1[2];
    FUN_140cb5be0(&local_188,local_118);
    local_res8 = 0;
    FUN_140cabf40(param_1 + 3,local_118,&local_res10);
    puVar7 = local_118;
  }
  else {
    FUN_140cd8360(*param_1,uVar4);
    uVar4 = _UNK_141ac9b08;
    uVar3 = _DAT_141ac9b00;
    local_168 = _DAT_141d2ff30;
    uStack_160 = _UNK_141d2ff38;
    local_178 = (void *)s_text_plain_141fc9868._0_8_;
    uStack_170 = (ulonglong)(ushort)s_text_plain_141fc9868._8_2_;
    uStack_150 = 0;
    local_148 = _DAT_141ac9b00;
    uStack_140 = _UNK_141ac9b08;
    local_158 = (void *)0x0;
    FUN_140cc3e20(local_a8,&local_158,0,200,&local_178);
    if (0xf < uStack_140) {
      pvVar6 = local_158;
      if ((0xfff < uStack_140 + 1) &&
         (pvVar6 = *(void **)((longlong)local_158 + -8),
         0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    local_148 = uVar3;
    uStack_140 = uVar4;
    local_158 = (void *)((ulonglong)local_158 & 0xffffffffffffff00);
    if (0xf < uStack_160) {
      pvVar6 = local_178;
      if ((0xfff < uStack_160 + 1) &&
         (pvVar6 = *(void **)((longlong)local_178 + -8),
         0x1f < (ulonglong)((longlong)local_178 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    local_168 = uVar3;
    uStack_160 = uVar4;
    local_178 = (void *)((ulonglong)local_178 & 0xffffffffffffff00);
    if (param_1[2] != 0) {
      LOCK();
      piVar1 = (int *)(param_1[2] + 8);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    local_188 = param_1[1];
    uStack_180 = param_1[2];
    FUN_140cb5be0(&local_188,local_a8);
    local_res8 = 0;
    FUN_140cabf40(param_1 + 3,local_a8,&local_res10);
    puVar7 = local_a8;
  }
  FUN_140cb2c00(puVar7);
  if (0xf < local_120) {
    ppppuVar5 = (undefined8 ****)local_138[0];
    if ((0xfff < local_120 + 1) &&
       (ppppuVar5 = (undefined8 ****)local_138[0][-1],
       0x1f < (ulonglong)((longlong)local_138[0] + (-8 - (longlong)ppppuVar5)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppuVar5);
  }
  return;
}


