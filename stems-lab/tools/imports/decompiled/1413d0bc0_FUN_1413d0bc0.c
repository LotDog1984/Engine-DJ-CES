// FUN_1413d0bc0 @ 1413d0bc0
// calls: [CreateFileW]

ulonglong FUN_1413d0bc0(undefined8 param_1,QString *param_2,undefined4 *param_3)

{
  UINT UVar1;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  BOOL BVar5;
  LPCWSTR pWVar6;
  undefined4 extraout_var;
  HDEVINFO pvVar7;
  undefined4 extraout_var_00;
  wchar_t *pwVar8;
  HDEVINFO DeviceInfoSet;
  undefined4 extraout_var_01;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_W DeviceInterfaceDetailData;
  HANDLE hDevice;
  undefined4 extraout_var_02;
  GUID *ClassGuid;
  DWORD local_res20 [2];
  int local_2d8;
  DWORD local_2d4;
  DWORD local_2d0 [2];
  _SP_DEVICE_INTERFACE_DATA local_2c8;
  undefined8 local_2a8 [2];
  int local_298;
  int local_294;
  int local_288;
  int local_284;
  _SP_DEVINFO_DATA local_278;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  WCHAR local_238 [264];
  
  pWVar6 = (LPCWSTR)QString::utf16(param_2);
  UVar1 = GetDriveTypeW(pWVar6);
  if ((UVar1 == 2) && (param_3 == (undefined4 *)0x0)) {
    return CONCAT71((int7)(CONCAT44(extraout_var,UVar1) >> 8),1);
  }
  local_res20[0] = local_res20[0] & 0xffffff00;
  pvVar7 = (HDEVINFO)FUN_1413d0a40(param_1,&local_298,param_2,local_res20);
  if ((char)local_res20[0] != '\0') {
    pWVar6 = (LPCWSTR)QString::utf16(param_2);
    DVar2 = QueryDosDeviceW(pWVar6,local_238,0x104);
    pvVar7 = (HDEVINFO)CONCAT44(extraout_var_00,DVar2);
    if (DVar2 != 0) {
      pWVar6 = (LPCWSTR)QString::utf16(param_2);
      UVar1 = GetDriveTypeW(pWVar6);
      if (UVar1 == 2) {
        pwVar8 = wcsstr(local_238,L"\\Floppy");
        ClassGuid = (GUID *)&DAT_1424e62e0;
        if (pwVar8 == (wchar_t *)0x0) {
          ClassGuid = (GUID *)&DAT_1424e62c0;
        }
      }
      else {
        uVar3 = UVar1 - 3;
        if (uVar3 == 0) {
          ClassGuid = (GUID *)&DAT_1424e62c0;
        }
        else {
          pvVar7 = (HDEVINFO)(ulonglong)uVar3;
          if (uVar3 != 2) goto LAB_1413d0f41;
          ClassGuid = (GUID *)&DAT_1424e62d0;
        }
      }
      DeviceInfoSet = SetupDiGetClassDevsW(ClassGuid,(PCWSTR)0x0,(HWND)0x0,0x12);
      pvVar7 = DeviceInfoSet;
      if (DeviceInfoSet != (HDEVINFO)0xffffffffffffffff) {
        local_2c8.InterfaceClassGuid.Data2 = 0;
        local_2c8.InterfaceClassGuid.Data3 = 0;
        local_2c8.InterfaceClassGuid.Data4[0] = '\0';
        local_2c8.InterfaceClassGuid.Data4[1] = '\0';
        local_2c8.InterfaceClassGuid.Data4[2] = '\0';
        local_2c8.InterfaceClassGuid.Data4[3] = '\0';
        DVar2 = 0;
        local_2c8.cbSize = 0x20;
        local_2c8.InterfaceClassGuid.Data1 = 0;
        local_2c8.InterfaceClassGuid.Data4[4] = '\0';
        local_2c8.InterfaceClassGuid.Data4[5] = '\0';
        local_2c8.InterfaceClassGuid.Data4[6] = '\0';
        local_2c8.InterfaceClassGuid.Data4[7] = '\0';
        local_2c8.Flags = 0;
        local_2c8.Reserved = 0;
        iVar4 = SetupDiEnumDeviceInterfaces
                          (DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,ClassGuid,0,&local_2c8);
        pvVar7 = (HDEVINFO)CONCAT44(extraout_var_01,iVar4);
        while (iVar4 != 0) {
          local_res20[0] = 0;
          BVar5 = SetupDiGetDeviceInterfaceDetailW
                            (DeviceInfoSet,&local_2c8,(PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0,0,
                             local_res20,(PSP_DEVINFO_DATA)0x0);
          if ((BVar5 != 0) || (local_res20[0] != 0)) {
            DeviceInterfaceDetailData = LocalAlloc(0x40,(ulonglong)local_res20[0]);
            DeviceInterfaceDetailData->cbSize = 8;
            local_278.ClassGuid.Data2 = 0;
            local_278.ClassGuid.Data3 = 0;
            local_278.ClassGuid.Data4[0] = '\0';
            local_278.ClassGuid.Data4[1] = '\0';
            local_278.ClassGuid.Data4[2] = '\0';
            local_278.ClassGuid.Data4[3] = '\0';
            local_278.ClassGuid.Data4[4] = '\0';
            local_278.ClassGuid.Data4[5] = '\0';
            local_278.ClassGuid.Data4[6] = '\0';
            local_278.ClassGuid.Data4[7] = '\0';
            local_278.DevInst = 0;
            local_278.Reserved = 0;
            local_278.cbSize = 0x20;
            local_278.ClassGuid.Data1 = 0;
            BVar5 = SetupDiGetDeviceInterfaceDetailW
                              (DeviceInfoSet,&local_2c8,DeviceInterfaceDetailData,local_res20[0],
                               local_res20,&local_278);
            if ((BVar5 != 0) &&
               (hDevice = CreateFileW(DeviceInterfaceDetailData->DevicePath,0,3,
                                      (LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0),
               hDevice != (HANDLE)0xffffffffffffffff)) {
              if (param_3 != (undefined4 *)0x0) {
                local_2a8[0] = 1;
                local_258 = 0;
                uStack_250 = 0;
                local_248 = 0;
                uStack_240 = 0;
                DeviceIoControl(hDevice,0x2d1400,local_2a8,0xc,&local_258,0x20,&local_2d4,
                                (LPOVERLAPPED)0x0);
                if ((char)uStack_240 == '\a') {
                  *param_3 = 1;
                }
              }
              BVar5 = DeviceIoControl(hDevice,0x2d1080,(LPVOID)0x0,0,&local_288,0xc,&local_2d4,
                                      (LPOVERLAPPED)0x0);
              CloseHandle(hDevice);
              if (((BVar5 != 0) && (local_288 == local_298)) && (local_284 == local_294)) {
                local_2d0[0] = 0;
                local_2d8 = 0;
                BVar5 = SetupDiGetDeviceRegistryPropertyW
                                  (DeviceInfoSet,&local_278,0x1f,local_2d0,(PBYTE)&local_2d8,4,
                                   local_res20);
                if (BVar5 != 0) {
                  return (ulonglong)CONCAT31((int3)(local_2d8 - 2U >> 8),local_2d8 - 2U < 2);
                }
              }
            }
          }
          local_2c8.InterfaceClassGuid.Data2 = 0;
          local_2c8.InterfaceClassGuid.Data3 = 0;
          local_2c8.InterfaceClassGuid.Data4[0] = '\0';
          local_2c8.InterfaceClassGuid.Data4[1] = '\0';
          local_2c8.InterfaceClassGuid.Data4[2] = '\0';
          local_2c8.InterfaceClassGuid.Data4[3] = '\0';
          DVar2 = DVar2 + 1;
          local_2c8.cbSize = 0x20;
          local_2c8.InterfaceClassGuid.Data1 = 0;
          local_2c8.InterfaceClassGuid.Data4[4] = '\0';
          local_2c8.InterfaceClassGuid.Data4[5] = '\0';
          local_2c8.InterfaceClassGuid.Data4[6] = '\0';
          local_2c8.InterfaceClassGuid.Data4[7] = '\0';
          local_2c8.Flags = 0;
          local_2c8.Reserved = 0;
          iVar4 = SetupDiEnumDeviceInterfaces
                            (DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,ClassGuid,DVar2,&local_2c8);
          pvVar7 = (HDEVINFO)CONCAT44(extraout_var_02,iVar4);
        }
      }
    }
  }
LAB_1413d0f41:
  return (ulonglong)pvVar7 & 0xffffffffffffff00;
}


