// FUN_1419776f0 @ 1419776f0
// calls: [CreateFileW]

undefined8 FUN_1419776f0(longlong param_1,ulonglong *param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  void *pvVar5;
  char cVar6;
  byte bVar7;
  undefined4 *puVar8;
  void *pvVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  uint uStackX_c;
  int *local_res18;
  ulonglong local_48;
  undefined **ppuStack_40;
  undefined8 local_38;
  
  iVar11 = 0;
  uVar1 = *(uint *)(param_1 + 0x20);
  if ((uVar1 & 0x10) != 0) {
    *(uint *)(param_1 + 0x20) = uVar1 & 0xffffffef;
    return 0;
  }
  if (((byte)uVar1 & 6) != 2) {
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + -8);
    if ((*(int *)(lVar3 + 0x30) == 0) || (*(int *)(lVar3 + 0x34) == 0xffff)) {
      puVar8 = (undefined4 *)FUN_141974ff0(&local_res18,lVar3 + 8,param_2);
      *(undefined4 *)(lVar3 + 0x30) = *puVar8;
      *(undefined4 *)(lVar3 + 0x34) = puVar8[1];
    }
    else if (param_2 != (ulonglong *)0x0) {
      local_48 = 0;
      ppuStack_40 = (undefined **)0x0;
      local_38 = 0;
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
    }
    iVar11 = *(int *)(lVar3 + 0x30);
    if (((param_2[2] & 1) != 0) && ((param_2[2] != 1 || ((int)*param_2 != 0)))) {
      return 0;
    }
  }
  if (((*(byte *)(param_1 + 0x20) & 2) == 0) && (iVar11 == 4)) {
    return 0;
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + -8);
  if ((*(int *)(lVar3 + 0x28) == 0) || (*(int *)(lVar3 + 0x2c) == 0xffff)) {
    iVar2 = *(int *)(lVar3 + 0x30);
    if ((iVar2 != 0) && ((*(int *)(lVar3 + 0x34) != 0xffff && (iVar2 != 4)))) {
      *(int *)(lVar3 + 0x28) = iVar2;
      *(undefined4 *)(lVar3 + 0x2c) = *(undefined4 *)(lVar3 + 0x34);
      goto LAB_1419777f5;
    }
    puVar8 = (undefined4 *)FUN_141974de0(&local_res18,lVar3 + 8,param_2);
    *(undefined4 *)(lVar3 + 0x28) = *puVar8;
    *(undefined4 *)(lVar3 + 0x2c) = puVar8[1];
  }
  else {
LAB_1419777f5:
    if (param_2 != (ulonglong *)0x0) {
      local_48 = 0;
      ppuStack_40 = (undefined **)0x0;
      local_38 = 0;
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
    }
  }
  if (((param_2[2] & 1) != 0) && ((param_2[2] != 1 || ((int)*param_2 != 0)))) {
    local_48 = CONCAT44(local_48._4_4_,2);
    ppuStack_40 = &PTR_vftable_1428e4500;
    cVar6 = FUN_141975870(param_2,&local_48);
    if ((cVar6 != '\0') && ((iVar11 == 4 && (((byte)*(undefined4 *)(param_1 + 0x20) & 6) == 6)))) {
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
    }
    return 0;
  }
  if (*(int *)(lVar3 + 0x28) != 3) {
    return 0;
  }
  if (0x7ffffffe < (*(longlong *)(param_1 + 0x10) - *(longlong *)(param_1 + 8) >> 3) - 1U) {
    local_48 = local_48 & 0xffffffff;
    if (DAT_1428e4508 + 0x4d54ee85da812030U < 2) {
      bVar7 = 1;
    }
    else {
      bVar7 = (**(code **)(PTR_vftable_1428e4500 + 0x30))(&PTR_vftable_1428e4500,0x84);
    }
    local_48 = CONCAT44(local_48._4_4_,0x84);
    *param_2 = local_48;
    param_2[1] = (ulonglong)&PTR_vftable_1428e4500;
    param_2[2] = (ulonglong)bVar7 + 2;
    return 2;
  }
  local_res18 = (int *)0x0;
  FUN_141975f70(&local_res18,*(longlong *)(*(longlong *)(param_1 + 0x10) + -8) + 8,
                *(undefined4 *)(param_1 + 0x20),param_2);
  if (((param_2[2] & 1) == 0) || ((param_2[2] == 1 && ((int)*param_2 == 0)))) {
    piVar12 = (int *)0x1;
    piVar10 = (int *)0x0;
    if ((local_res18 != (int *)0x0) && (piVar10 = (int *)0x0, *(longlong *)(local_res18 + 0xe) != 0)
       ) {
      puVar4 = *(undefined8 **)(param_1 + 0x10);
      if (puVar4 == *(undefined8 **)(param_1 + 0x18)) {
        FUN_141975600(param_1 + 8,puVar4,&local_res18);
      }
      else {
        *puVar4 = local_res18;
        local_res18 = (int *)0x0;
        *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 8;
      }
      piVar10 = local_res18;
      if (local_res18 != (int *)0x0) {
        LOCK();
        iVar11 = *local_res18;
        *local_res18 = *local_res18 + -1;
        UNLOCK();
        if (iVar11 != 1) {
          return 1;
        }
        if (*(HANDLE *)(local_res18 + 0xe) != (HANDLE)0x0) {
          FindClose(*(HANDLE *)(local_res18 + 0xe));
          piVar10[0xe] = 0;
          piVar10[0xf] = 0;
        }
        if (7 < *(ulonglong *)(piVar10 + 8)) {
          pvVar5 = *(void **)(piVar10 + 2);
          pvVar9 = pvVar5;
          if ((0xfff < *(ulonglong *)(piVar10 + 8) * 2 + 2) &&
             (pvVar9 = *(void **)((longlong)pvVar5 + -8),
             0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar9)))) goto LAB_141977bad;
          free(pvVar9);
        }
        piVar10[6] = 0;
        piVar10[7] = 0;
        piVar10[8] = 7;
        piVar10[9] = 0;
        *(undefined2 *)(piVar10 + 2) = 0;
        free(piVar10);
      }
      return 1;
    }
  }
  else {
    piVar10 = (int *)((ulonglong)uStackX_c << 0x20);
    piVar12 = (int *)0x0;
  }
  if ((piVar12 != (int *)0x0) && (piVar10 != (int *)0x0)) {
    LOCK();
    iVar11 = *piVar10;
    *piVar10 = *piVar10 + -1;
    UNLOCK();
    if (iVar11 == 1) {
      if (*(HANDLE *)(piVar10 + 0xe) != (HANDLE)0x0) {
        FindClose(*(HANDLE *)(piVar10 + 0xe));
        piVar10[0xe] = 0;
        piVar10[0xf] = 0;
      }
      if (7 < *(ulonglong *)(piVar10 + 8)) {
        pvVar5 = *(void **)(piVar10 + 2);
        pvVar9 = pvVar5;
        if ((0xfff < *(ulonglong *)(piVar10 + 8) * 2 + 2) &&
           (pvVar9 = *(void **)((longlong)pvVar5 + -8),
           0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar9);
      }
      piVar10[6] = 0;
      piVar10[7] = 0;
      piVar10[8] = 7;
      piVar10[9] = 0;
      *(undefined2 *)(piVar10 + 2) = 0;
      free(piVar10);
    }
  }
  piVar10 = local_res18;
  if (local_res18 != (int *)0x0) {
    LOCK();
    iVar11 = *local_res18;
    *local_res18 = *local_res18 + -1;
    UNLOCK();
    if (iVar11 == 1) {
      if (*(HANDLE *)(local_res18 + 0xe) != (HANDLE)0x0) {
        FindClose(*(HANDLE *)(local_res18 + 0xe));
        piVar10[0xe] = 0;
        piVar10[0xf] = 0;
      }
      if (7 < *(ulonglong *)(piVar10 + 8)) {
        pvVar5 = *(void **)(piVar10 + 2);
        pvVar9 = pvVar5;
        if ((0xfff < *(ulonglong *)(piVar10 + 8) * 2 + 2) &&
           (pvVar9 = *(void **)((longlong)pvVar5 + -8),
           0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar9)))) {
LAB_141977bad:
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar9);
      }
      piVar10[6] = 0;
      piVar10[7] = 0;
      piVar10[8] = 7;
      piVar10[9] = 0;
      *(undefined2 *)(piVar10 + 2) = 0;
      free(piVar10);
    }
  }
  return 0;
}


