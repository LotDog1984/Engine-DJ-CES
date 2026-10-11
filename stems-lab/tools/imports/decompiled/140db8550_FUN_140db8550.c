// FUN_140db8550 @ 140db8550
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_140db8550(longlong *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 param_4)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  uint *puVar7;
  undefined8 *puVar8;
  void *pvVar9;
  longlong lVar10;
  undefined1 local_res8 [8];
  undefined8 *local_res10;
  undefined4 uVar11;
  void *local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  ulonglong uStack_b8;
  void *local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  ulonglong uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined1 local_70 [32];
  undefined1 local_50 [40];
  
  *param_2 = 0;
  param_2[1] = 0;
  uStack_a8 = 0;
  local_a0 = _DAT_141cb0070;
  uStack_98 = _UNK_141cb0078;
  local_b0 = (void *)0x0;
  lVar10 = param_3[2];
  local_res10 = param_2;
  if (lVar10 != 0) {
    puVar8 = param_3;
    if (0xf < (ulonglong)param_3[3]) {
      puVar8 = (undefined8 *)*param_3;
    }
    uVar6 = FUN_14196e970(lVar10,_DAT_141cb0070,param_3,param_4,1);
    FUN_141971270(puVar8,lVar10 + (longlong)puVar8,&local_b0,uVar6);
  }
  (**(code **)(*param_1 + 0x18))(param_1,local_70,&local_b0);
  FUN_1403a32e0(local_50,local_70,&DAT_1428fed00);
  puVar8 = param_3;
  if (0xf < (ulonglong)param_3[3]) {
    puVar8 = (undefined8 *)*param_3;
  }
  lVar10 = 6;
  if ((ulonglong)param_3[2] < 6) {
    lVar10 = param_3[2];
  }
  if ((lVar10 == 6) && (iVar5 = memcmp(puVar8,PTR_DAT_142029520,6), iVar5 == 0)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if ((bVar4) || (puVar7 = (uint *)FUN_141974de0(local_res8,local_50,0), 1 < *puVar7)) {
    puVar8 = (undefined8 *)FUN_14196fa80(local_70,&local_90);
    uStack_c8 = 0;
    local_c0 = _DAT_141ac9b00;
    uStack_b8 = _UNK_141ac9b08;
    local_d0 = (void *)0x0;
    uVar11 = 9;
    lVar10 = puVar8[2];
    if (lVar10 != 0) {
      if (7 < (ulonglong)puVar8[3]) {
        puVar8 = (undefined8 *)*puVar8;
      }
      uVar6 = FUN_14196e970();
      FUN_141971350(puVar8,(longlong)puVar8 + lVar10 * 2,&local_d0,uVar6,uVar11);
    }
    uVar11 = 5;
    FUN_1402a29e0(&local_90);
    FUN_140db7b40(param_1,&local_90,&local_d0,0,uVar11);
    *param_2 = local_90;
    plVar3 = (longlong *)param_2[1];
    param_2[1] = local_88;
    if (plVar3 != (longlong *)0x0) {
      LOCK();
      plVar1 = plVar3 + 1;
      lVar10 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if ((int)lVar10 == 1) {
        (**(code **)*plVar3)(plVar3);
        LOCK();
        piVar2 = (int *)((longlong)plVar3 + 0xc);
        iVar5 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar5 == 1) {
          (**(code **)(*plVar3 + 8))(plVar3);
        }
      }
    }
    if (0xf < uStack_b8) {
      pvVar9 = local_d0;
      if ((0xfff < uStack_b8 + 1) &&
         (pvVar9 = *(void **)((longlong)local_d0 + -8),
         0x1f < (ulonglong)((longlong)local_d0 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar9);
    }
  }
  FUN_1402a29e0(local_50);
  FUN_1402a29e0(local_70);
  if (7 < uStack_98) {
    pvVar9 = local_b0;
    if ((0xfff < uStack_98 * 2 + 2) &&
       (pvVar9 = *(void **)((longlong)local_b0 + -8),
       0x1f < (ulonglong)((longlong)local_b0 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar9);
  }
  return param_2;
}


