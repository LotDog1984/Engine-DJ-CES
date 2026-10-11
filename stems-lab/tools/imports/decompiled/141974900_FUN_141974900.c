// FUN_141974900 @ 141974900
// calls: [CreateFileW]

ULARGE_INTEGER * FUN_141974900(ULARGE_INTEGER *param_1,LPCWSTR param_2,int *param_3)

{
  void *pvVar1;
  char cVar2;
  DWORD DVar3;
  BOOL BVar4;
  undefined8 uVar5;
  longlong lVar6;
  LPCWSTR pWVar7;
  LPCWSTR pWVar8;
  void *_Memory;
  undefined8 *******pppppppuVar9;
  undefined8 *******pppppppuVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  uint local_res8 [2];
  ULARGE_INTEGER local_res18;
  ULARGE_INTEGER local_res20;
  WCHAR local_128;
  undefined6 uStack_126;
  ulonglong local_118;
  ulonglong local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 ******local_e8 [2];
  longlong local_d8;
  ulonglong local_d0;
  ULARGE_INTEGER local_c8;
  ULARGE_INTEGER UStack_c0;
  ULARGE_INTEGER local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  ULARGE_INTEGER local_90;
  undefined8 ******local_88 [2];
  undefined8 local_78;
  ulonglong local_70;
  
  local_c8.QuadPart = 0xffffffffffffffff;
  UStack_c0.QuadPart = 0xffffffffffffffff;
  local_b8.QuadPart = 0xffffffffffffffff;
  if (param_3 != (int *)0x0) {
    param_3[0] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
  }
  local_108 = 0;
  uStack_100 = 0;
  local_f8 = 0;
  FUN_141974de0(local_res8,param_2,&local_108);
  uVar11 = local_res8[0];
  if (local_res8[0] < 2) {
    uVar16 = (undefined4)local_f8;
    uVar17 = (undefined4)((ulonglong)local_f8 >> 0x20);
LAB_141974d5d:
    if (param_3 != (int *)0x0) {
      *param_3 = (int)local_108;
      param_3[1] = local_108._4_4_;
      param_3[2] = (int)uStack_100;
      param_3[3] = uStack_100._4_4_;
      *(ulonglong *)(param_3 + 4) = CONCAT44(uVar17,uVar16);
      *param_1 = local_c8;
      param_1[1] = UStack_c0;
      param_1[2] = local_b8;
      return param_1;
    }
    local_f8 = CONCAT44(uVar17,uVar16);
    FUN_1419785a0(local_88,"boost::filesystem::space",param_2,&local_108);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_88,(ThrowInfo *)&DAT_142890460);
  }
  FUN_1402a5d70(local_e8,param_2);
  if (uVar11 != 3) {
    FUN_141973420(local_88,param_3);
    if (((param_3 != (int *)0x0) && ((*(ulonglong *)(param_3 + 4) & 1) != 0)) &&
       ((*(ulonglong *)(param_3 + 4) != 1 || (*param_3 != 0)))) {
      FUN_1402a29e0(local_88);
      FUN_1402a29e0(local_e8);
      param_1->QuadPart = 0xffffffffffffffff;
      param_1[1].QuadPart = 0xffffffffffffffff;
      param_1[2].QuadPart = 0xffffffffffffffff;
      return param_1;
    }
    iVar12 = 0;
    iVar13 = 0;
    iVar14 = 0;
    iVar15 = 0;
    local_a0 = 0;
    local_108 = 0;
    uStack_100 = 0;
    uVar16 = 0;
    uVar17 = 0;
    local_f8 = 0;
    pWVar8 = param_2;
    if (7 < *(ulonglong *)(param_2 + 0xc)) {
      pWVar8 = *(LPCWSTR *)param_2;
    }
    DVar3 = GetFileAttributesW(pWVar8);
    if (DVar3 == 0xffffffff) {
      FUN_141973d50(local_res8,param_2,&local_108);
      uVar16 = (undefined4)local_f8;
      uVar17 = (undefined4)((ulonglong)local_f8 >> 0x20);
      iVar12 = (int)local_108;
      iVar13 = local_108._4_4_;
      iVar14 = (int)uStack_100;
      iVar15 = uStack_100._4_4_;
      uVar11 = local_res8[0];
    }
    else {
      FUN_141973a90(param_2,DVar3);
      if ((DVar3 >> 10 & 1) == 0) {
        uVar11 = (DVar3 & 0x10 | 0x20) >> 4;
      }
      else {
        cVar2 = FUN_1419735e0(param_2);
        uVar11 = 4;
        if (cVar2 == '\0') {
          uVar11 = 9;
        }
      }
    }
    if (uVar11 == 0) {
      FUN_1402a29e0(local_88);
      FUN_1402a29e0(local_e8);
      local_108._0_4_ = iVar12;
      local_108._4_4_ = iVar13;
      uStack_100._0_4_ = iVar14;
      uStack_100._4_4_ = iVar15;
      goto LAB_141974d5d;
    }
    if (uVar11 == 4) {
      uVar5 = FUN_141971d50(&local_b0,param_2,local_88,param_3);
      FUN_1402ac5a0(local_e8,uVar5);
      FUN_1402a29e0(&local_b0);
      if (((param_3 != (int *)0x0) && ((*(ulonglong *)(param_3 + 4) & 1) != 0)) &&
         ((*(ulonglong *)(param_3 + 4) != 1 || (*param_3 != 0)))) {
        FUN_1402a29e0(local_88);
        goto LAB_141974ae7;
      }
    }
    pppppppuVar10 = local_e8;
    if (7 < local_d0) {
      pppppppuVar10 = (undefined8 *******)local_e8[0];
    }
    lVar6 = FUN_14196f640(local_e8);
    pppppppuVar10 = (undefined8 *******)((longlong)pppppppuVar10 + lVar6 * 2);
    pppppppuVar9 = local_e8;
    if (7 < local_d0) {
      pppppppuVar9 = (undefined8 *******)local_e8[0];
    }
    local_b0 = 0;
    uStack_a8 = 0;
    local_a0 = 0;
    uStack_98 = 0;
    if (pppppppuVar9 == pppppppuVar10) {
      uStack_98 = 7;
      local_b0 = 0;
    }
    else {
      FUN_1402a7200(&local_b0,0,(longlong)pppppppuVar10 - (longlong)pppppppuVar9 >> 1);
    }
    FUN_1402ac5a0(local_e8,&local_b0);
    FUN_1402a29e0(&local_b0);
    if (local_d8 == 0) {
      pppppppuVar10 = local_88;
      if (7 < local_70) {
        pppppppuVar10 = (undefined8 *******)local_88[0];
      }
      FUN_1402a6570(local_e8,pppppppuVar10,local_78);
    }
    FUN_1402a29e0(local_88);
  }
  FUN_1402a5d70(&local_128,local_e8);
  pWVar8 = (LPCWSTR)CONCAT62(uStack_126,local_128);
  if (1 < local_118) {
    pWVar7 = &local_128;
    if (7 < local_110) {
      pWVar7 = pWVar8;
    }
    if ((*pWVar7 == L'/') || (*pWVar7 == L'\\')) {
      pWVar7 = &local_128;
      if (7 < local_110) {
        pWVar7 = pWVar8;
      }
      if ((pWVar7[1] == L'/') || (pWVar7[1] == L'\\')) {
        pWVar7 = &local_128;
        if (7 < local_110) {
          pWVar7 = pWVar8;
        }
        if ((pWVar7[local_118 - 1] != L'/') && (pWVar7[local_118 - 1] != L'\\')) {
          if (local_118 < local_110) {
            pWVar7 = &local_128;
            if (7 < local_110) {
              pWVar7 = pWVar8;
            }
            pWVar7 = pWVar7 + local_118;
            local_118 = local_118 + 1;
            pWVar7[0] = L'\\';
            pWVar7[1] = L'\0';
          }
          else {
            FUN_1402a5a70(&local_128,1,(undefined1)local_res8[0],0x5c);
          }
          pWVar8 = (LPCWSTR)CONCAT62(uStack_126,local_128);
        }
      }
    }
  }
  pWVar7 = &local_128;
  if (7 < local_110) {
    pWVar7 = pWVar8;
  }
  BVar4 = GetDiskFreeSpaceExW(pWVar7,&local_90,&local_res18,&local_res20);
  if (BVar4 == 0) {
    FUN_141978c40(1,param_2,param_3,"boost::filesystem::space");
  }
  else {
    if (param_3 != (int *)0x0) {
      local_a0 = 0;
      param_3[0] = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      param_3[4] = 0;
      param_3[5] = 0;
    }
    local_c8 = local_res18;
    UStack_c0 = local_res20;
    local_b8 = local_90;
  }
  if (7 < local_110) {
    pvVar1 = (void *)CONCAT62(uStack_126,local_128);
    _Memory = pvVar1;
    if ((0xfff < local_110 * 2 + 2) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  local_118 = 0;
  local_110 = 7;
  local_128 = L'\0';
LAB_141974ae7:
  FUN_1402a29e0(local_e8);
  *param_1 = local_c8;
  param_1[1] = UStack_c0;
  param_1[2] = local_b8;
  return param_1;
}


