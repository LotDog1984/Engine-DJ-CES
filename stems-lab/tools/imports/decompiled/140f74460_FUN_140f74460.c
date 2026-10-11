// FUN_140f74460 @ 140f74460
// calls: [WriteFile]

undefined8 FUN_140f74460(longlong param_1,longlong param_2,uint param_3,longlong param_4)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  uint local_res18 [2];
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  uint local_24;
  undefined8 local_20;
  
  iVar3 = 0;
  local_28 = (undefined4)param_4;
  local_38 = 0;
  local_30 = 0;
  local_20 = 0;
  local_24 = (uint)((ulonglong)param_4 >> 0x20) & 0x7fffffff;
  if (0 < (int)param_3) {
    do {
      puVar4 = &local_38;
      iVar1 = (*(code *)PTR_WriteFile_1429353f0)
                        (*(undefined8 *)(param_1 + 0x10),param_2,param_3,local_res18,puVar4);
      uVar5 = (undefined4)((ulonglong)puVar4 >> 0x20);
      if (iVar1 == 0) {
        iVar1 = (*(code *)PTR_GetLastError_1429350a8)();
        if ((DAT_1429348e8 <= iVar3) ||
           ((((0x3b < iVar1 - 5U ||
              ((0x804000018000001U >> ((ulonglong)(iVar1 - 5U) & 0x3f) & 1) == 0)) &&
             (iVar1 != 0x79)) && (iVar1 != 0x4cf)))) {
LAB_140f745b4:
          *(int *)(param_1 + 0x20) = iVar1;
          if ((iVar1 != 0x27) && (iVar1 != 0x70)) {
            uVar2 = FUN_14103a1b0(0x30a,iVar1,"winWrite2",*(undefined8 *)(param_1 + 0x30),
                                  CONCAT44(uVar5,0xc038));
            return uVar2;
          }
          uVar2 = FUN_14103a1b0(0xd,iVar1,"winWrite1",*(undefined8 *)(param_1 + 0x30),
                                CONCAT44(uVar5,0xc033));
          return uVar2;
        }
        iVar3 = iVar3 + 1;
        (*(code *)PTR_Sleep_142935360)(iVar3 * DAT_1429348ec);
      }
      else {
        if ((local_res18[0] == 0) || (param_3 < local_res18[0])) {
          iVar1 = (*(code *)PTR_GetLastError_1429350a8)();
          goto LAB_140f745b4;
        }
        param_4 = param_4 + (ulonglong)local_res18[0];
        param_2 = param_2 + (ulonglong)local_res18[0];
        local_28 = (undefined4)param_4;
        local_24 = (uint)((ulonglong)param_4 >> 0x20) & 0x7fffffff;
        param_3 = param_3 - local_res18[0];
      }
    } while (0 < (int)param_3);
    if (iVar3 != 0) {
      FUN_140f7a5e0(0x1b,"delayed %dms for lock/sharing conflict at line %d",
                    ((iVar3 + 1) * iVar3 * DAT_1429348ec) / 2,0xc03a);
    }
  }
  return 0;
}


