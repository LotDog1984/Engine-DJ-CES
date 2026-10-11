// FUN_141980cf4 @ 141980cf4
// calls: [CreateFileW]

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD FUN_141980cf4(LPCWSTR param_1,ulonglong *param_2,uint param_3,uint param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_2c8 [32];
  undefined4 local_2a8;
  undefined4 uStack_2a4;
  uint local_2a0 [2];
  ulonglong local_298;
  undefined4 local_290;
  uint local_28c;
  DWORD DStack_288;
  DWORD local_284;
  uint local_280;
  _WIN32_FIND_DATAW local_278;
  ulonglong local_28;
  
  local_28 = DAT_142955700 ^ (ulonglong)auStack_2c8;
  uVar4 = param_3 & 0xfffffffe;
  if (((param_3 & 1) != 0) && ((param_3 >> 2 & 1) != 0)) {
    return 0x57;
  }
  if ((((param_3 >> 1 & 1) != 0) && (param_4 != 0xffffffff)) &&
     (((param_4 >> 10 & 1) == 0 || ((param_3 & 1) == 0)))) {
    uVar4 = param_3 & 0xfffffffc;
    *(uint *)(param_2 + 2) = param_4;
  }
  if (uVar4 != 0) {
    if (((uVar4 & 0x2a) != 0) &&
       (((param_4 == 0xffffffff || ((param_4 >> 10 & 1) == 0)) || ((param_3 & 1) == 0)))) {
      BVar1 = GetFileAttributesExW(param_1,GetFileExInfoStandard,local_2a0);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        if (DVar2 != 0x20) {
          return DVar2;
        }
        pvVar3 = FindFirstFileW(param_1,&local_278);
        if (pvVar3 == (HANDLE)0xffffffffffffffff) {
          DVar2 = GetLastError();
          return DVar2;
        }
        FindClose(pvVar3);
        local_28c = local_278.ftLastWriteTime.dwLowDateTime;
        DStack_288 = local_278.ftLastWriteTime.dwHighDateTime;
      }
      else {
        local_278.ftLastWriteTime.dwHighDateTime = DStack_288;
        local_278.ftLastWriteTime.dwLowDateTime = local_28c;
        local_278.dwFileAttributes = local_2a0[0];
        local_278.nFileSizeHigh = local_284;
        local_278.nFileSizeLow = local_280;
      }
      if (((param_3 & 1) == 0) || ((local_278.dwFileAttributes >> 10 & 1) == 0)) {
        *(DWORD *)(param_2 + 2) = local_278.dwFileAttributes;
        param_2[1] = CONCAT44(local_278.nFileSizeHigh,local_278.nFileSizeLow);
        *param_2 = (ulonglong)local_278.ftLastWriteTime & 0xffffffff00000000 | (ulonglong)local_28c;
        uVar4 = uVar4 & 0xffffffd5;
        if (uVar4 == 0) {
          return 0;
        }
      }
    }
    DVar2 = __std_fs_open_handle
                      (&local_2a8,param_1,0x80,(((byte)param_3 & 1 ^ 1) + 0x10) * 0x200000);
    if (DVar2 == 0) {
      pvVar3 = (HANDLE)CONCAT44(uStack_2a4,local_2a8);
      uVar5 = uVar4;
      if ((uVar4 & 0x26) != 0) {
        BVar1 = GetFileInformationByHandleEx(pvVar3,FileBasicInfo,local_2a0,0x28);
        if (BVar1 == 0) {
          DVar2 = GetLastError();
          if (pvVar3 == (HANDLE)0xffffffffffffffff) {
            return DVar2;
          }
          BVar1 = CloseHandle(pvVar3);
          if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
            abort();
          }
          return DVar2;
        }
        uVar5 = uVar4 & 0xffffffdd;
        *param_2 = CONCAT44(local_28c,local_290);
        *(uint *)(param_2 + 2) = local_280;
        if ((uVar5 >> 2 & 1) != 0) {
          if ((local_280 >> 10 & 1) == 0) {
            *(undefined4 *)((longlong)param_2 + 0x14) = 0;
          }
          else {
            BVar1 = GetFileInformationByHandleEx(pvVar3,FileAttributeTagInfo,&local_2a8,8);
            if (BVar1 == 0) {
              DVar2 = GetLastError();
              if (pvVar3 == (HANDLE)0xffffffffffffffff) {
                return DVar2;
              }
              BVar1 = CloseHandle(pvVar3);
              if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
                abort();
              }
              return DVar2;
            }
            *(undefined4 *)((longlong)param_2 + 0x14) = uStack_2a4;
          }
          uVar5 = uVar4 & 0xffffffd9;
        }
      }
      if ((uVar5 & 0x18) != 0) {
        BVar1 = GetFileInformationByHandleEx(pvVar3,FileStandardInfo,local_2a0,0x18);
        if (BVar1 == 0) {
          DVar2 = GetLastError();
          if (pvVar3 == (HANDLE)0xffffffffffffffff) {
            return DVar2;
          }
          BVar1 = CloseHandle(pvVar3);
          if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
            abort();
          }
          return DVar2;
        }
        uVar5 = uVar5 & 0xffffffe7;
        param_2[1] = local_298;
        *(undefined4 *)(param_2 + 3) = local_290;
      }
      if (uVar5 == 0) {
        if (pvVar3 == (HANDLE)0xffffffffffffffff) {
          return 0;
        }
        BVar1 = CloseHandle(pvVar3);
        if (BVar1 != 0) {
          return 0;
        }
      }
      else if ((pvVar3 == (HANDLE)0xffffffffffffffff) || (BVar1 = CloseHandle(pvVar3), BVar1 != 0))
      {
        return 0x32;
      }
    }
    else {
      if ((HANDLE)CONCAT44(uStack_2a4,local_2a8) == (HANDLE)0xffffffffffffffff) {
        return DVar2;
      }
      BVar1 = CloseHandle((HANDLE)CONCAT44(uStack_2a4,local_2a8));
      if (BVar1 != 0) {
        return DVar2;
      }
    }
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return 0;
}


