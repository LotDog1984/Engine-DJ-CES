// FUN_140ddbba0 @ 140ddbba0
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140ddbba0(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  bool bVar6;
  longlong *plVar7;
  char cVar8;
  int iVar9;
  undefined8 uVar10;
  uint *puVar11;
  void *_Memory;
  undefined8 *puVar12;
  bool bVar13;
  undefined1 local_res18 [16];
  void *local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  ulonglong uStack_190;
  longlong local_188;
  longlong *plStack_180;
  
  bVar6 = false;
  if (*(char *)(param_1 + 0x98) != '\0') {
    return 1;
  }
  uVar10 = 0;
  local_188 = 0;
  plStack_180 = (longlong *)0x0;
  lVar4 = *(longlong *)(param_1 + 0xa8);
  if (lVar4 != 0) {
    iVar3 = *(int *)(lVar4 + 8);
    do {
      if (iVar3 == 0) goto LAB_140ddbc18;
      LOCK();
      iVar9 = *(int *)(lVar4 + 8);
      bVar13 = iVar3 == iVar9;
      if (bVar13) {
        *(int *)(lVar4 + 8) = iVar3 + 1;
        iVar9 = iVar3;
      }
      UNLOCK();
      iVar3 = iVar9;
    } while (!bVar13);
    local_188 = *(longlong *)(param_1 + 0xa0);
    plStack_180 = *(longlong **)(param_1 + 0xa8);
  }
LAB_140ddbc18:
  if (local_188 == 0) goto LAB_140ddbd0e;
  puVar12 = (undefined8 *)(param_1 + 0x78);
  cVar8 = FUN_140dc6ce0(puVar12);
  if (cVar8 == '\0') {
    uStack_1a0 = 0;
    local_198 = _DAT_141cb0070;
    uStack_190 = _UNK_141cb0078;
    local_1a8 = (void *)0x0;
    lVar4 = *(longlong *)(param_1 + 0x88);
    if (lVar4 != 0) {
      puVar5 = puVar12;
      if (0xf < *(ulonglong *)(param_1 + 0x90)) {
        puVar5 = (undefined8 *)*puVar12;
        puVar12 = (undefined8 *)*puVar12;
      }
      uVar10 = FUN_14196e970();
      FUN_141971270(puVar12,(longlong)puVar5 + lVar4,&local_1a8,uVar10);
    }
    bVar6 = true;
    puVar11 = (uint *)FUN_141974de0(local_res18,&local_1a8,0);
    if (1 < *puVar11) goto LAB_140ddbcb1;
    uVar10 = 0;
  }
  else {
LAB_140ddbcb1:
    uVar10 = 1;
  }
  if ((bVar6) && (7 < uStack_190)) {
    _Memory = local_1a8;
    if ((0xfff < uStack_190 * 2 + 2) &&
       (_Memory = *(void **)((longlong)local_1a8 + -8),
       0x1f < (ulonglong)((longlong)local_1a8 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
LAB_140ddbd0e:
  plVar7 = plStack_180;
  if (plStack_180 != (longlong *)0x0) {
    LOCK();
    plVar1 = plStack_180 + 1;
    lVar4 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar4 == 1) {
      (**(code **)*plStack_180)(plStack_180);
      LOCK();
      piVar2 = (int *)((longlong)plVar7 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*plStack_180 + 8))();
      }
    }
  }
  return uVar10;
}


