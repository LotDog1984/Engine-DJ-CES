// FUN_140e55c30 @ 140e55c30
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140e55c30(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  bool bVar2;
  int *_Memory;
  undefined8 uVar3;
  uint *puVar4;
  undefined8 uVar5;
  void *_Memory_00;
  void *pvVar6;
  ulonglong uVar7;
  bool bVar8;
  int *local_res20;
  undefined8 local_e8;
  undefined8 uStack_e0;
  ulonglong local_d8;
  void *local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  ulonglong local_b8;
  void *local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  ulonglong uStack_98;
  undefined1 local_90 [32];
  ulonglong local_70;
  undefined1 local_68 [32];
  undefined1 local_48 [32];
  
  bVar2 = false;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  FUN_141974de0(&local_70,param_2,&local_e8);
  if ((uint)local_70 < 2) {
    return local_70 & 0xffffffffffffff00;
  }
  if (((local_d8 & 1) != 0) && ((local_d8 != 1 || ((int)local_e8 != 0)))) {
    uVar3 = FUN_141956400(local_48,param_2);
    uVar5 = FUN_1405abe00(&local_e8,local_68);
    uVar5 = FUN_14029e990(&local_b0,uVar5,"\nwhile getting status of ");
    uVar3 = FUN_14029e960(&local_d0,uVar5,uVar3);
    FUN_1406e9ad0(local_90,0x4f,uVar3);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_90,(ThrowInfo *)&DAT_14288da78);
  }
  if ((uint)local_70 != 3) {
    uVar3 = FUN_141956400(local_48,param_2);
    uVar3 = FUN_14029e990(local_68,uVar3," is not a directory");
    FUN_1406e9ad0(local_90,0x4f,uVar3);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_90,(ThrowInfo *)&DAT_14288da78);
  }
  local_res20 = (int *)0x0;
  FUN_141975f70(&local_res20,param_2,0,&local_e8);
  _Memory = local_res20;
  if ((local_res20 == (int *)0x0) || (*(longlong *)(local_res20 + 0xe) == 0)) {
    bVar8 = true;
  }
  else {
    bVar8 = false;
  }
  if (local_res20 != (int *)0x0) {
    LOCK();
    iVar1 = *local_res20;
    *local_res20 = *local_res20 + -1;
    UNLOCK();
    if ((iVar1 == 1) && (local_res20 != (int *)0x0)) {
      FUN_141975a80(&local_d0,local_res20 + 0xe);
      if (7 < *(ulonglong *)(_Memory + 8)) {
        pvVar6 = *(void **)(_Memory + 2);
        _Memory_00 = pvVar6;
        if ((0xfff < *(ulonglong *)(_Memory + 8) * 2 + 2) &&
           (_Memory_00 = *(void **)((longlong)pvVar6 + -8),
           0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)_Memory_00)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(_Memory_00);
      }
      _Memory[6] = 0;
      _Memory[7] = 0;
      _Memory[8] = 7;
      _Memory[9] = 0;
      *(undefined2 *)(_Memory + 2) = 0;
      free(_Memory);
    }
  }
  if (((local_d8 & 1) != 0) && ((local_d8 != 1 || ((int)local_e8 != 0)))) {
    uVar3 = FUN_141956400(local_48,param_2);
    uVar5 = FUN_1405abe00(&local_e8,local_68);
    uVar5 = FUN_14029e990(&local_b0,uVar5,"\nwhile iterating over ");
    uVar3 = FUN_14029e960(&local_d0,uVar5,uVar3);
    FUN_1406e9ad0(local_90,0x4f,uVar3);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_90,(ThrowInfo *)&DAT_14288da78);
  }
  if (!bVar8) {
    uStack_a8 = 0;
    local_a0 = _DAT_141cb0070;
    uStack_98 = _UNK_141cb0078;
    local_b0 = (void *)0x0;
    local_c0 = 10;
    local_b8 = 0xf;
    local_d0 = (void *)s__migration_142036240._0_8_;
    uStack_c8 = (ulonglong)(ushort)s__migration_142036240._8_2_;
    uVar3 = FUN_14196e970();
    FUN_141971270(&local_d0,(longlong)&uStack_c8 + 2,&local_b0,uVar3);
    if (0xf < local_b8) {
      pvVar6 = local_d0;
      if ((0xfff < local_b8 + 1) &&
         (pvVar6 = *(void **)((longlong)local_d0 + -8),
         0x1f < (ulonglong)((longlong)local_d0 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    FUN_1402a5d70(local_68,param_1);
    FUN_14196e520(local_68,&local_b0);
    FUN_14196ffa0(local_68,local_48);
    FUN_14196fa80(local_48,local_90);
    FUN_1402a29e0(local_48);
    FUN_1402a29e0(local_68);
    if (7 < uStack_98) {
      pvVar6 = local_b0;
      if ((0xfff < uStack_98 * 2 + 2) &&
         (pvVar6 = *(void **)((longlong)local_b0 + -8),
         0x1f < (ulonglong)((longlong)local_b0 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    bVar2 = true;
    puVar4 = (uint *)FUN_141974de0(&local_res20,local_90,&local_e8);
    if (*puVar4 < 2) {
      uVar7 = 1;
      goto LAB_140e55ede;
    }
  }
  uVar7 = 0;
LAB_140e55ede:
  if (bVar2) {
    FUN_1402a29e0(local_90);
  }
  return uVar7;
}


