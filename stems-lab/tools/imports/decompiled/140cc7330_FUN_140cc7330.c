// FUN_140cc7330 @ 140cc7330
// calls: [ReadFile, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_140cc7330(int *param_1,undefined8 param_2,uint *param_3,undefined8 *param_4,
                   undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  longlong *plVar1;
  undefined8 *puVar2;
  void *pvVar3;
  void *pvVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined1 local_res18;
  undefined4 uVar9;
  void *local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  ulonglong uStack_c0;
  longlong *local_b8;
  longlong *local_b0;
  longlong local_a8;
  uint local_98;
  uint uStack_94;
  uint uStack_90;
  uint uStack_8c;
  undefined8 local_88;
  ulonglong local_80;
  int local_70 [2];
  void *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_98 = *param_3;
  uStack_94 = param_3[1];
  uStack_90 = param_3[2];
  uStack_8c = param_3[3];
  FUN_140ccc130(&local_b8,&local_98);
  plVar1 = local_b0;
  uVar7 = _DAT_141ac9b00;
  uVar8 = _UNK_141ac9b08;
  for (plVar5 = local_b8; _DAT_141ac9b00 = uVar7, _UNK_141ac9b08 = uVar8, plVar5 != plVar1;
      plVar5 = plVar5 + 4) {
    if (0x7fffffffffffffffU - plVar5[2] < (ulonglong)param_4[2]) {
                    /* WARNING: Subroutine does not return */
      FUN_14029da10();
    }
    plVar6 = plVar5;
    if (0xf < (ulonglong)plVar5[3]) {
      plVar6 = (longlong *)*plVar5;
    }
    puVar2 = param_4;
    if (0xf < (ulonglong)param_4[3]) {
      puVar2 = (undefined8 *)*param_4;
    }
    FUN_14029f6d0(&local_d8,local_res18,plVar5,plVar6,plVar5[2],puVar2,param_4[2]);
    uVar9 = (undefined4)((ulonglong)puVar2 >> 0x20);
    FUN_140cc9520(&local_98,&local_d8,300);
    FUN_140cc6760(local_70,param_2,&local_98,param_4,param_5,CONCAT44(uVar9,param_6),param_7,param_8
                 );
    if (local_70[0] != 3) {
      *param_1 = local_70[0];
      *(void **)(param_1 + 2) = local_68;
      *(undefined8 *)(param_1 + 4) = uStack_60;
      *(undefined8 *)(param_1 + 6) = local_58;
      *(ulonglong *)(param_1 + 8) = uStack_50;
      *(undefined8 *)(param_1 + 10) = local_48;
      *(undefined8 *)(param_1 + 0xc) = local_40;
      if (0xf < local_80) {
        pvVar4 = (void *)CONCAT44(uStack_94,local_98);
        pvVar3 = pvVar4;
        if ((0xfff < local_80 + 1) &&
           (pvVar3 = *(void **)((longlong)pvVar4 + -8),
           0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar3)))) goto LAB_140cc7602;
        free(pvVar3);
      }
      local_88 = 0;
      local_80 = 0xf;
      local_98 = local_98 & 0xffffff00;
      if (0xf < uStack_c0) {
        pvVar3 = local_d8;
        if ((0xfff < uStack_c0 + 1) &&
           (pvVar3 = *(void **)((longlong)local_d8 + -8),
           0x1f < (ulonglong)((longlong)local_d8 + (-8 - (longlong)pvVar3)))) goto LAB_140cc7652;
        free(pvVar3);
      }
      local_c8 = 0;
      uStack_c0 = 0xf;
      local_d8 = (void *)((ulonglong)local_d8 & 0xffffffffffffff00);
      plVar5 = local_b8;
      if (local_b8 == (longlong *)0x0) {
        return param_1;
      }
      goto joined_r0x000140cc7685;
    }
    if (0xf < uStack_50) {
      pvVar3 = local_68;
      if ((0xfff < uStack_50 + 1) &&
         (pvVar3 = *(void **)((longlong)local_68 + -8),
         0x1f < (ulonglong)((longlong)local_68 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar3);
    }
    if (0xf < local_80) {
      pvVar4 = (void *)CONCAT44(uStack_94,local_98);
      pvVar3 = pvVar4;
      if ((0xfff < local_80 + 1) &&
         (pvVar3 = *(void **)((longlong)pvVar4 + -8),
         0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar3)))) {
LAB_140cc7602:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar3);
    }
    local_88 = 0;
    local_80 = 0xf;
    local_98 = local_98 & 0xffffff00;
    if (0xf < uStack_c0) {
      pvVar3 = local_d8;
      if ((0xfff < uStack_c0 + 1) &&
         (pvVar3 = *(void **)((longlong)local_d8 + -8),
         0x1f < (ulonglong)((longlong)local_d8 + (-8 - (longlong)pvVar3)))) {
LAB_140cc7652:
        local_80 = 0xf;
        local_88 = 0;
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar3);
    }
    uVar7 = _DAT_141ac9b00;
    uVar8 = _UNK_141ac9b08;
  }
  uStack_d0 = 0;
  local_d8 = (void *)0x0;
  local_c8 = uVar7;
  uStack_c0 = uVar8;
  FUN_140cc6760(param_1,param_2,&local_d8,param_4,param_5,param_6,param_7,param_8);
  if (0xf < uStack_c0) {
    pvVar3 = local_d8;
    if ((0xfff < uStack_c0 + 1) &&
       (pvVar3 = *(void **)((longlong)local_d8 + -8),
       0x1f < (ulonglong)((longlong)local_d8 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar3);
    uVar7 = _DAT_141ac9b00;
    uVar8 = _UNK_141ac9b08;
  }
  local_d8 = (void *)((ulonglong)local_d8 & 0xffffffffffffff00);
  if (local_b8 == (longlong *)0x0) {
    return param_1;
  }
  local_c8 = uVar7;
  uStack_c0 = uVar8;
  FUN_14029c160(local_b8,local_b0,&local_b8);
  plVar5 = local_b8;
  if ((0xfff < (local_a8 - (longlong)local_b8 & 0xffffffffffffffe0U)) &&
     (plVar5 = (longlong *)local_b8[-1],
     0x1f < (ulonglong)((longlong)local_b8 + (-8 - local_b8[-1])))) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  goto LAB_140cc7718;
joined_r0x000140cc7685:
  if (plVar5 == local_b0) goto LAB_140cc76e2;
  if (0xf < (ulonglong)plVar5[3]) {
    pvVar3 = (void *)*plVar5;
    pvVar4 = pvVar3;
    if ((0xfff < plVar5[3] + 1U) &&
       (pvVar4 = *(void **)((longlong)pvVar3 + -8),
       0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar4)))) goto LAB_140cc770e;
    free(pvVar4);
  }
  plVar5[2] = 0;
  plVar5[3] = 0xf;
  *(undefined1 *)plVar5 = 0;
  plVar5 = plVar5 + 4;
  goto joined_r0x000140cc7685;
LAB_140cc76e2:
  plVar5 = local_b8;
  if ((0xfff < (local_a8 - (longlong)local_b8 & 0xffffffffffffffe0U)) &&
     (plVar5 = (longlong *)local_b8[-1],
     0x1f < (ulonglong)((longlong)local_b8 + (-8 - (longlong)plVar5)))) {
LAB_140cc770e:
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
LAB_140cc7718:
  free(plVar5);
  return param_1;
}


