// FUN_1419750e0 @ 1419750e0
// calls: [CreateFileW]

undefined8 * FUN_1419750e0(undefined8 *param_1,undefined8 *param_2)

{
  LPCWSTR lpName;
  size_t _Size;
  DWORD DVar1;
  UINT UVar2;
  undefined8 uVar3;
  LPWSTR pWVar4;
  uint *puVar5;
  int *piVar6;
  undefined8 ****ppppuVar7;
  ulonglong uVar8;
  undefined8 ****_Dst;
  longlong lVar9;
  longlong lVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined8 ***local_c8;
  undefined8 uStack_c0;
  ulonglong local_b8;
  ulonglong uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  ulonglong local_98;
  undefined8 ***local_90;
  undefined8 uStack_88;
  ulonglong local_80;
  ulonglong local_78;
  wchar_t *local_68 [6];
  
  uVar8 = 0;
  if (param_2 != (undefined8 *)0x0) {
    local_98 = 0;
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
  }
  local_68[0] = L"TMP";
  local_68[1] = L"TEMP";
  local_68[2] = L"LOCALAPPDATA";
  local_68[3] = L"USERPROFILE";
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 7;
  local_c8 = (undefined8 ****)0x0;
  lVar10 = -1;
  do {
    lpName = local_68[uVar8];
    DVar1 = GetEnvironmentVariableW(lpName,(LPWSTR)0x0,0);
    if (DVar1 == 0) {
LAB_141975205:
      uStack_88 = 0;
      local_80 = 0;
      local_78 = 7;
      local_90 = (undefined8 ****)0x0;
    }
    else {
      uVar3 = SUB168(ZEXT816(2) * ZEXT416(DVar1),0);
      if (SUB168(ZEXT816(2) * ZEXT416(DVar1),8) != 0) {
        uVar3 = 0xffffffffffffffff;
      }
      pWVar4 = (LPWSTR)thunk_FUN_141981f80(uVar3);
      DVar1 = GetEnvironmentVariableW(lpName,pWVar4,DVar1);
      if (DVar1 == 0) {
        free(pWVar4);
        goto LAB_141975205;
      }
      local_90 = (undefined8 ****)0x0;
      uStack_88 = 0;
      local_80 = 0;
      local_78 = 0;
      lVar9 = -1;
      do {
        lVar9 = lVar9 + 1;
      } while (pWVar4[lVar9] != L'\0');
      FUN_1402a7200(&local_90,pWVar4);
      free(pWVar4);
    }
    uVar11 = local_78;
    if (local_80 != 0) {
      ppppuVar7 = &local_90;
      if (7 < local_78) {
        ppppuVar7 = (undefined8 ****)local_90;
      }
      if (uStack_b0 < local_80) {
        FUN_1402a55b0(&local_c8,local_80,(ulonglong)param_2 & 0xff);
        uVar11 = local_78;
      }
      else {
        _Dst = &local_c8;
        if (7 < uStack_b0) {
          _Dst = (undefined8 ****)local_c8;
        }
        _Size = local_80 * 2;
        local_b8 = local_80;
        memmove(_Dst,ppppuVar7,_Size);
        *(undefined2 *)(_Size + (longlong)_Dst) = 0;
      }
      if (1 < (uint)uVar8) {
        FUN_14196e5c0(&local_c8,L"Temp",L"");
      }
      local_a8 = 0;
      uStack_a0 = 0;
      local_98 = 0;
      puVar5 = (uint *)FUN_141974de0();
      if ((1 < *puVar5) && (((local_98 & 1) == 0 || ((local_98 == 1 && ((int)local_a8 == 0)))))) {
        piVar6 = (int *)FUN_141974de0();
        if ((*piVar6 == 3) && (((local_98 & 1) == 0 || ((local_98 == 1 && ((int)local_a8 == 0))))))
        {
          if (7 < uVar11) {
            ppppuVar7 = (undefined8 ****)local_90;
            if ((0xfff < uVar11 * 2 + 2) &&
               (ppppuVar7 = (undefined8 ****)local_90[-1],
               0x1f < (ulonglong)((longlong)local_90 + (-8 - (longlong)ppppuVar7))))
            goto LAB_141975430;
            free(ppppuVar7);
          }
          break;
        }
      }
      local_b8 = 0;
      ppppuVar7 = &local_c8;
      if (7 < uStack_b0) {
        ppppuVar7 = (undefined8 ****)local_c8;
      }
      *(undefined2 *)ppppuVar7 = 0;
    }
    if (7 < uVar11) {
      ppppuVar7 = (undefined8 ****)local_90;
      if ((0xfff < uVar11 * 2 + 2) &&
         (ppppuVar7 = (undefined8 ****)local_90[-1],
         0x1f < (ulonglong)((longlong)local_90 + (-8 - (longlong)ppppuVar7)))) {
LAB_141975430:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppuVar7);
    }
    uVar12 = (uint)uVar8 + 1;
    uVar8 = (ulonglong)uVar12;
  } while (uVar12 < 4);
  if (local_b8 == 0) {
    UVar2 = GetWindowsDirectoryW((LPWSTR)0x0,0);
    if (UVar2 != 0) {
      uVar3 = SUB168(ZEXT816(2) * ZEXT416(UVar2),0);
      if (SUB168(ZEXT816(2) * ZEXT416(UVar2),8) != 0) {
        uVar3 = 0xffffffffffffffff;
      }
      pWVar4 = (LPWSTR)thunk_FUN_141981f80(uVar3);
      UVar2 = GetWindowsDirectoryW(pWVar4,UVar2);
      if (UVar2 != 0) {
        do {
          lVar10 = lVar10 + 1;
        } while (pWVar4[lVar10] != L'\0');
        FUN_1402a6570(&local_c8,pWVar4,lVar10);
        FUN_14196e5c0(&local_c8,L"Temp",L"");
        free(pWVar4);
        goto LAB_14197547a;
      }
      free(pWVar4);
    }
    DVar1 = GetLastError();
    if (DVar1 == 0) {
      if (param_2 != (undefined8 *)0x0) {
        local_98 = 0;
        *param_2 = 0;
        param_2[1] = 0;
        param_2[2] = 0;
      }
    }
    else {
      FUN_141978d40(DVar1,param_2,"boost::filesystem::temp_directory_path");
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 7;
    *(undefined2 *)param_1 = 0;
    if (7 < uStack_b0) {
      ppppuVar7 = (undefined8 ****)local_c8;
      if ((0xfff < uStack_b0 * 2 + 2) &&
         (ppppuVar7 = (undefined8 ****)local_c8[-1],
         0x1f < (ulonglong)((longlong)local_c8 + (-8 - (longlong)ppppuVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppuVar7);
    }
  }
  else {
LAB_14197547a:
    *param_1 = local_c8;
    param_1[1] = uStack_c0;
    param_1[2] = local_b8;
    param_1[3] = uStack_b0;
  }
  return param_1;
}


