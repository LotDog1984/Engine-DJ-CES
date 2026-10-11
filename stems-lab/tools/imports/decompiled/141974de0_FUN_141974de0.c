// FUN_141974de0 @ 141974de0
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_141974de0(int *param_1,LPCWSTR param_2,undefined8 *param_3)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  BOOL BVar4;
  int iVar5;
  LPCWSTR pWVar6;
  LPCWSTR ******pppppppWVar7;
  uint uVar8;
  longlong lVar9;
  HANDLE local_res10;
  LPCWSTR *****local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  _BY_HANDLE_FILE_INFORMATION local_68;
  
  if (param_3 != (undefined8 *)0x0) {
    local_78 = 0;
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
  }
  pWVar6 = param_2;
  if (7 < *(ulonglong *)(param_2 + 0xc)) {
    pWVar6 = *(LPCWSTR *)param_2;
  }
  DVar2 = GetFileAttributesW(pWVar6);
  if (DVar2 == 0xffffffff) {
    FUN_141973d50(param_1,param_2,param_3);
    return param_1;
  }
  iVar3 = FUN_141973a90(param_2,DVar2);
  if ((DVar2 >> 10 & 1) != 0) {
    cVar1 = FUN_1419735e0(param_2);
    if (cVar1 == '\0') {
      *param_1 = 9;
      local_res10._0_4_ = iVar3;
      goto LAB_141974fcd;
    }
    pWVar6 = param_2;
    if (7 < *(ulonglong *)(param_2 + 0xc)) {
      pWVar6 = *(LPCWSTR *)param_2;
    }
    local_88 = (LPCWSTR *****)0x0;
    uStack_80 = 0;
    local_78 = 0;
    uStack_70 = 0;
    lVar9 = -1;
    do {
      lVar9 = lVar9 + 1;
    } while (pWVar6[lVar9] != L'\0');
    FUN_1402a7200(&local_88);
    pppppppWVar7 = &local_88;
    if (7 < uStack_70) {
      pppppppWVar7 = (LPCWSTR ******)local_88;
    }
    local_res10 = CreateFileW((LPCWSTR)pppppppWVar7,0,7,(LPSECURITY_ATTRIBUTES)0x0,3,0x2000000,
                              (HANDLE)0x0);
    if (7 < uStack_70) {
      pppppppWVar7 = (LPCWSTR ******)local_88;
      if ((0xfff < uStack_70 * 2 + 2) &&
         (pppppppWVar7 = (LPCWSTR ******)local_88[-1],
         0x1f < (ulonglong)((longlong)local_88 + (-8 - (longlong)pppppppWVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppWVar7);
    }
    local_78 = _DAT_141cb0070;
    uStack_70 = _UNK_141cb0078;
    local_88 = (LPCWSTR *****)((ulonglong)local_88 & 0xffffffffffff0000);
    if (local_res10 == (HANDLE)0xffffffffffffffff) {
      FUN_141973d50(param_1,param_2,param_3);
      return param_1;
    }
    BVar4 = GetFileInformationByHandle(local_res10,&local_68);
    if (BVar4 == 0) {
      FUN_141973d50(param_1,param_2,param_3);
      CloseHandle(local_res10);
      return param_1;
    }
    CloseHandle(local_res10);
    DVar2 = local_68.dwFileAttributes;
  }
  uVar8 = DVar2 & 0x10;
  iVar5 = iVar3;
  if (uVar8 != 0) {
    iVar5 = (int)local_res10;
    local_res10._0_4_ = iVar3;
  }
  *param_1 = (uVar8 != 0) + 2;
  if (uVar8 == 0) {
    local_res10._0_4_ = iVar5;
  }
LAB_141974fcd:
  param_1[1] = (int)local_res10;
  return param_1;
}


