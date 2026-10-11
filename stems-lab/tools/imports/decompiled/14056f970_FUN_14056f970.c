// FUN_14056f970 @ 14056f970
// calls: [MoveFileExW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14056f970(undefined8 *param_1,undefined8 *param_2)

{
  longlong *plVar1;
  int *piVar2;
  void *pvVar3;
  longlong lVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  void *pvVar11;
  undefined8 ****ppppuVar12;
  undefined8 local_158;
  undefined **ppuStack_150;
  undefined8 local_148;
  ulonglong uStack_140;
  undefined1 local_138;
  undefined7 uStack_137;
  undefined8 local_128;
  ulonglong uStack_120;
  undefined8 ***local_118 [2];
  ulonglong local_108;
  ulonglong local_100;
  char local_f8;
  undefined8 ***local_f0 [3];
  ulonglong local_d8;
  undefined1 local_d0;
  undefined7 uStack_cf;
  undefined8 local_c0;
  ulonglong uStack_b8;
  undefined1 local_b0 [32];
  undefined1 local_90 [8];
  longlong *local_88;
  undefined1 local_78;
  undefined7 uStack_77;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined1 local_50 [8];
  longlong *local_48;
  undefined1 local_40 [8];
  undefined1 local_38;
  undefined7 uStack_37;
  undefined8 local_28;
  ulonglong uStack_20;
  
  FUN_140e17380(local_118,*param_1,0);
  if (local_f8 != '\0') {
    puVar7 = (undefined8 *)FUN_140d8ffc0(*param_2,local_50);
    uVar8 = FUN_140dd39f0(*puVar7);
    uVar9 = FUN_140d94970(*param_2,local_40);
    uVar9 = FUN_1404c6d10(uVar9,&local_78);
    FUN_140e16a20(&local_d0,uVar9,uVar8);
    if (0xf < uStack_60) {
      pvVar3 = (void *)CONCAT71(uStack_77,local_78);
      pvVar11 = pvVar3;
      if ((0xfff < uStack_60 + 1) &&
         (pvVar11 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar11);
    }
    local_68 = _DAT_141ac9b00;
    uStack_60 = _UNK_141ac9b08;
    local_78 = 0;
    if (0xf < uStack_20) {
      pvVar3 = (void *)CONCAT71(uStack_37,local_38);
      pvVar11 = pvVar3;
      if ((0xfff < uStack_20 + 1) &&
         (pvVar11 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar11);
    }
    local_28 = _DAT_141ac9b00;
    uStack_20 = _UNK_141ac9b08;
    local_38 = 0;
    if (local_48 != (longlong *)0x0) {
      LOCK();
      plVar1 = local_48 + 1;
      lVar4 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if ((int)lVar4 == 1) {
        (**(code **)*local_48)(local_48);
        LOCK();
        piVar2 = (int *)((longlong)local_48 + 0xc);
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar6 == 1) {
          (**(code **)(*local_48 + 8))(local_48);
        }
      }
    }
    puVar7 = (undefined8 *)FUN_140d8ffc0(*param_2,local_90);
    uVar8 = FUN_140dd39f0(*puVar7);
    uVar8 = FUN_140e16e30(&local_138,uVar8);
    FUN_14029e800(local_b0,uVar8,0);
    if (0xf < uStack_120) {
      pvVar3 = (void *)CONCAT71(uStack_137,local_138);
      pvVar11 = pvVar3;
      if ((0xfff < uStack_120 + 1) &&
         (pvVar11 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar11);
    }
    local_128 = _DAT_141ac9b00;
    uStack_120 = _UNK_141ac9b08;
    local_138 = 0;
    if (local_88 != (longlong *)0x0) {
      LOCK();
      plVar1 = local_88 + 1;
      lVar4 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if ((int)lVar4 == 1) {
        (**(code **)*local_88)(local_88);
        LOCK();
        piVar2 = (int *)((longlong)local_88 + 0xc);
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar6 == 1) {
          (**(code **)(*local_88 + 8))(local_88);
        }
      }
    }
    local_158 = (undefined8 *)((ulonglong)local_158._4_4_ << 0x20);
    ppuStack_150 = &PTR_vftable_1428c0710;
    FUN_14056e7e0(local_b0,&local_158);
    if ((int)local_158 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_14056e700("create_directories",&local_158,local_b0);
    }
    FUN_14029e800(local_f0,&local_d0,0);
    ppppuVar12 = local_118;
    if (0xf < local_100) {
      ppppuVar12 = (undefined8 ****)local_118[0];
    }
    uVar5 = FUN_141980938();
    ppuStack_150 = (undefined **)0x0;
    local_148 = 0;
    uStack_140 = 7;
    local_158 = (undefined8 *)0x0;
    if (local_108 != 0) {
      if (0x7fffffff < local_108) {
                    /* WARNING: Subroutine does not return */
        FUN_1402a28d0(0x16);
      }
      uVar10 = __std_fs_convert_narrow_to_wide(uVar5,ppppuVar12,local_108 & 0xffffffff,0,0);
      if ((int)(uVar10 >> 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_1402a2910(uVar10 >> 0x20);
      }
      FUN_1402a4790(&local_158,(longlong)(int)uVar10,0);
      puVar7 = &local_158;
      if (7 < uStack_140) {
        puVar7 = local_158;
      }
      uVar10 = __std_fs_convert_narrow_to_wide
                         (uVar5,ppppuVar12,local_108 & 0xffffffff,puVar7,(int)uVar10);
      if ((int)(uVar10 >> 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_1402a2910(uVar10 >> 0x20);
      }
    }
    ppppuVar12 = local_f0;
    if (7 < local_d8) {
      ppppuVar12 = (undefined8 ****)local_f0[0];
    }
    puVar7 = &local_158;
    if (7 < uStack_140) {
      puVar7 = local_158;
    }
    iVar6 = FUN_141981294(puVar7,ppppuVar12);
    if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_14056e760("rename",iVar6,&local_158,local_f0);
    }
    if (7 < uStack_140) {
      puVar7 = local_158;
      if ((0xfff < uStack_140 * 2 + 2) &&
         (puVar7 = (undefined8 *)local_158[-1],
         0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)puVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(puVar7);
    }
    local_148 = _DAT_141cb0070;
    uStack_140 = _UNK_141cb0078;
    local_158 = (undefined8 *)((ulonglong)local_158 & 0xffffffffffff0000);
    FUN_1402a29e0(local_f0);
    FUN_1402a29e0(local_b0);
    if (0xf < uStack_b8) {
      pvVar3 = (void *)CONCAT71(uStack_cf,local_d0);
      pvVar11 = pvVar3;
      if ((0xfff < uStack_b8 + 1) &&
         (pvVar11 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar11);
    }
    local_c0 = _DAT_141ac9b00;
    uStack_b8 = _UNK_141ac9b08;
    local_d0 = 0;
    if ((local_f8 != '\0') && (0xf < local_100)) {
      ppppuVar12 = (undefined8 ****)local_118[0];
      if ((0xfff < local_100 + 1) &&
         (ppppuVar12 = (undefined8 ****)local_118[0][-1],
         0x1f < (ulonglong)((longlong)local_118[0] + (-8 - (longlong)ppppuVar12)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppuVar12);
    }
  }
  return;
}


