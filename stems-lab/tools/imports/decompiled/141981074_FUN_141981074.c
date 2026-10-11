// FUN_141981074 @ 141981074
// calls: [CreateFileW]

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_141981074(undefined8 param_1)

{
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  undefined1 auStack_78 [32];
  uint local_58;
  DWORD DStack_54;
  HANDLE local_50;
  undefined4 local_48 [2];
  undefined1 local_40 [32];
  uint local_20;
  ulonglong local_18;
  
  local_18 = DAT_142955700 ^ (ulonglong)auStack_78;
  bVar1 = false;
  DStack_54 = __std_fs_open_handle(&local_50,param_1,0x10180,0x2200000);
  if (DStack_54 == 0) {
    bVar1 = true;
LAB_1419810c2:
    local_48[0] = 0x13;
    BVar2 = SetFileInformationByHandle(local_50,0x15,local_48,4);
    if (BVar2 == 0) {
      DStack_54 = GetLastError();
      if (((DStack_54 == 1) || (DStack_54 == 0x32)) || (DStack_54 == 0x57)) {
        DStack_54 = FUN_1419808a0(local_50);
        if (DStack_54 == 0) goto LAB_1419810e8;
        if ((DStack_54 != 5) || (!bVar1)) goto LAB_14198117b;
        BVar2 = GetFileInformationByHandleEx(local_50,FileBasicInfo,local_40,0x28);
        if (BVar2 == 0) {
LAB_1419811ba:
          local_58 = local_58 & 0xffffff00;
LAB_1419811be:
          DStack_54 = GetLastError();
        }
        else {
          if ((local_20 & 1) != 0) {
            local_20 = local_20 ^ 1;
            BVar2 = SetFileInformationByHandle(local_50,FileBasicInfo,local_40,0x28);
            if (BVar2 == 0) goto LAB_1419811ba;
            iVar3 = FUN_1419808a0(local_50);
            if (iVar3 == 0) {
              local_58 = CONCAT31(local_58._1_3_,1);
              DStack_54 = 0;
              goto LAB_1419811c7;
            }
            if (iVar3 != 5) {
              local_58 = (uint)local_58._1_3_ << 8;
              DStack_54 = GetLastError();
              goto joined_r0x00014198112e;
            }
            local_20 = local_20 | 1;
            BVar2 = SetFileInformationByHandle(local_50,FileBasicInfo,local_40,0x28);
            local_58 = local_58 & 0xffffff00;
            if (BVar2 != 0) goto LAB_141981248;
            goto LAB_1419811be;
          }
          local_58 = local_58 & 0xffffff00;
LAB_141981248:
          DStack_54 = 5;
        }
LAB_1419811c7:
        if ((local_50 != (HANDLE)0xffffffffffffffff) && (BVar2 = CloseHandle(local_50), BVar2 == 0))
        {
                    /* WARNING: Subroutine does not return */
          abort();
        }
        goto LAB_14198113e;
      }
LAB_14198117b:
      local_58 = local_58 & 0xffffff00;
    }
    else {
LAB_1419810e8:
      local_58 = CONCAT31(local_58._1_3_,1);
      DStack_54 = 0;
    }
  }
  else {
    if (DStack_54 == 5) {
      DStack_54 = __std_fs_open_handle(&local_50,param_1,0x10000,0x2200000);
      if (DStack_54 == 0) goto LAB_1419810c2;
    }
    else if ((((DStack_54 == 2) || (DStack_54 == 3)) || (DStack_54 == 0x35)) || (DStack_54 == 0x7b))
    {
      DStack_54 = 0;
    }
    local_58 = local_58 & 0xffffff00;
  }
joined_r0x00014198112e:
  if ((local_50 != (HANDLE)0xffffffffffffffff) && (BVar2 = CloseHandle(local_50), BVar2 == 0)) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
LAB_14198113e:
  return CONCAT44(DStack_54,local_58);
}


