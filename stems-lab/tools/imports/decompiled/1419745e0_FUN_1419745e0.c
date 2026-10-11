// FUN_1419745e0 @ 1419745e0
// calls: [CreateFileW]

ulonglong FUN_1419745e0(LPCWSTR param_1,ulonglong param_2,DWORD *param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  BOOL BVar4;
  DWORD DVar5;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar6;
  undefined4 extraout_var_01;
  undefined8 uVar7;
  LPCWSTR pWVar8;
  uint dwFileAttributes;
  bool bVar9;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  undefined4 extraout_XMM0_Da_01;
  undefined4 extraout_XMM0_Da_02;
  undefined4 uVar10;
  DWORD local_78 [4];
  ulonglong local_68;
  undefined1 local_58 [64];
  
  dwFileAttributes = (uint)param_2;
  if (dwFileAttributes == 0xffffffff) {
    local_78[0] = GetLastError();
    if (DAT_1428e1960 + 0x4d54ee85da812030U < 2) {
      bVar1 = local_78[0] != 0;
    }
    else {
      bVar1 = (**(code **)(PTR_vftable_1428e1958 + 0x30))(&PTR_vftable_1428e1958,local_78[0]);
    }
    local_68 = (ulonglong)bVar1 + 2;
    if ((local_78[0] < 0x36) &&
       (uVar6 = local_68, (0x2000000020800cU >> ((longlong)(int)local_78[0] & 0x3fU) & 1) != 0))
    goto LAB_1419747fa;
    uVar3 = local_78[0] - 0x43;
    uVar6 = (ulonglong)uVar3;
    if (((uVar3 < 0x39) && ((0x100000000100001U >> (uVar6 & 0x3f) & 1) != 0)) ||
       (local_78[0] == 0xa1)) goto LAB_1419747fa;
    if (local_78[0] != 0x20) {
      if (param_3 != (DWORD *)0x0) {
        *param_3 = local_78[0];
        param_3[1] = 0;
        param_3[2] = 0x428e1958;
        param_3[3] = 1;
        *(ulonglong *)(param_3 + 4) = local_68;
        return (ulonglong)(uint3)(uVar3 >> 8) << 8;
      }
      local_78[1] = 0;
      local_78[2] = 0x428e1958;
      local_78[3] = 1;
      FUN_1419785a0(local_58,"boost::filesystem::remove",param_1,local_78);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_58,(ThrowInfo *)&DAT_142890460);
    }
LAB_141974767:
    if ((param_2 & 1) != 0) {
      pWVar8 = param_1;
      if (7 < *(ulonglong *)(param_1 + 0xc)) {
        pWVar8 = *(LPCWSTR *)param_1;
      }
      BVar4 = SetFileAttributesW(pWVar8,dwFileAttributes & 0xfffffffe);
      if (BVar4 == 0) {
        DVar5 = GetLastError();
        uVar6 = FUN_141973bb0(DVar5);
        uVar10 = extraout_XMM0_Da_00;
        if ((char)uVar6 != '\0') goto LAB_1419747fa;
        goto LAB_1419747e8;
      }
    }
    pWVar8 = param_1;
    if (7 < *(ulonglong *)(param_1 + 0xc)) {
      pWVar8 = *(LPCWSTR *)param_1;
    }
    BVar4 = DeleteFileW(pWVar8);
    uVar7 = CONCAT44(extraout_var_01,BVar4);
    if (BVar4 != 0) {
LAB_1419747fe:
      return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
    }
    DVar5 = GetLastError();
    uVar6 = FUN_141973bb0(DVar5);
    if ((char)uVar6 != '\0') goto LAB_1419747fa;
    uVar10 = extraout_XMM0_Da_01;
    if ((param_2 & 1) != 0) {
      pWVar8 = param_1;
      if (7 < *(ulonglong *)(param_1 + 0xc)) {
        pWVar8 = *(LPCWSTR *)param_1;
      }
      SetFileAttributesW(pWVar8,dwFileAttributes);
      uVar10 = extraout_XMM0_Da_02;
    }
  }
  else {
    if ((dwFileAttributes >> 10 & 1) == 0) {
      bVar9 = (param_2 >> 4 & 1) == 0;
    }
    else {
      if ((param_2 & 0x10) == 0) goto LAB_141974767;
      cVar2 = FUN_1419735e0();
      bVar9 = cVar2 == '\0';
    }
    if (bVar9) goto LAB_141974767;
    pWVar8 = param_1;
    if (7 < *(ulonglong *)(param_1 + 0xc)) {
      pWVar8 = *(LPCWSTR *)param_1;
    }
    BVar4 = RemoveDirectoryW(pWVar8);
    uVar7 = CONCAT44(extraout_var,BVar4);
    if (BVar4 != 0) goto LAB_1419747fe;
    DVar5 = GetLastError();
    uVar6 = CONCAT44(extraout_var_00,DVar5);
    if ((((DVar5 < 0x36) && ((0x2000000020800cU >> ((longlong)(int)DVar5 & 0x3fU) & 1) != 0)) ||
        ((uVar6 = (ulonglong)(DVar5 - 0x43), DVar5 - 0x43 < 0x39 &&
         ((0x100000000100001U >> (uVar6 & 0x3f) & 1) != 0)))) ||
       (uVar10 = extraout_XMM0_Da, DVar5 == 0xa1)) goto LAB_1419747fa;
  }
LAB_1419747e8:
  uVar6 = FUN_141978c40(uVar10,param_1,param_3,"boost::filesystem::remove");
LAB_1419747fa:
  return uVar6 & 0xffffffffffffff00;
}


