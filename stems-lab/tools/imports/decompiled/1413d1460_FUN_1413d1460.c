// FUN_1413d1460 @ 1413d1460
// calls: [CreateFileW]

bool FUN_1413d1460(undefined8 param_1,QString *param_2)

{
  UINT UVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  LPCWSTR lpRootPathName;
  char local_res18 [8];
  int local_res20 [2];
  undefined4 local_448 [2];
  undefined1 local_440 [4];
  int local_43c;
  undefined2 local_428 [264];
  WCHAR local_218 [264];
  
  lpRootPathName = (LPCWSTR)QString::utf16(param_2);
  FUN_1413d0a40(param_1,local_440,param_2,local_res18);
  if ((local_res18[0] != '\0') && (local_43c != -1)) {
    UVar1 = GetDriveTypeW(lpRootPathName);
    DVar2 = QueryDosDeviceW(lpRootPathName,local_218,0x104);
    if ((DVar2 != 0) && (iVar3 = FUN_1413cfb60(local_43c,UVar1,local_218), iVar3 != 0)) {
      local_448[0] = 0;
      CM_Get_Parent(local_448,iVar3,0);
      local_res20[0] = 0;
      local_428[0] = 0;
      iVar4 = CM_Request_Device_EjectW(local_448[0],local_res20,local_428,0x104,0);
      if (iVar4 == 0x17) {
        if (local_res20[0] != 8) {
          return false;
        }
        local_428[0] = 0;
        iVar4 = CM_Request_Device_EjectW(iVar3,local_res20,local_428,0x104,0);
      }
      if (iVar4 == 0) {
        return local_res20[0] == 0;
      }
    }
  }
  return false;
}


