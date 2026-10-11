// FUN_14103a290 @ 14103a290
// calls: [CreateFileMappingW]

undefined8 FUN_14103a290(longlong param_1,ulonglong param_2)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint local_res8 [2];
  undefined8 in_stack_ffffffffffffffe8;
  undefined8 uVar5;
  undefined4 uVar7;
  ulonglong uVar6;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  if (*(int *)(param_1 + 0x3c) < 1) {
    if ((longlong)param_2 < 0) {
      iVar1 = (*(code *)PTR_GetFileSize_142935060)(*(undefined8 *)(param_1 + 0x10),local_res8);
      param_2 = CONCAT44(local_res8[0],iVar1);
      if (iVar1 == -1) {
        iVar1 = (*(code *)PTR_GetLastError_1429350a8)();
        if (iVar1 != 0) {
          *(int *)(param_1 + 0x20) = iVar1;
          uVar5 = CONCAT44(uVar7,0xc113);
          iVar1 = FUN_14103a1b0(0x70a,iVar1,"winFileSize",*(undefined8 *)(param_1 + 0x30),uVar5);
          uVar7 = (undefined4)((ulonglong)uVar5 >> 0x20);
          if (iVar1 != 0) {
            return 0x70a;
          }
        }
      }
    }
    uVar4 = *(ulonglong *)(param_1 + 0x58);
    if ((longlong)param_2 <= (longlong)*(ulonglong *)(param_1 + 0x58)) {
      uVar4 = param_2;
    }
    uVar4 = uVar4 & ~(ulonglong)(DAT_142b24fac - 1);
    if ((uVar4 == 0) && (0 < *(longlong *)(param_1 + 0x50))) {
      FUN_14103ad00(param_1);
    }
    if (uVar4 != *(ulonglong *)(param_1 + 0x50)) {
      FUN_14103ad00(param_1);
      uVar5 = CONCAT44(uVar7,(int)uVar4);
      lVar3 = (*(code *)PTR_CreateFileMappingW_142934ee0)
                        (*(undefined8 *)(param_1 + 0x10),0,2,(longlong)uVar4 >> 0x20,uVar5,0);
      uVar7 = (undefined4)((ulonglong)uVar5 >> 0x20);
      *(longlong *)(param_1 + 0x40) = lVar3;
      if (lVar3 == 0) {
        uVar2 = (*(code *)PTR_GetLastError_1429350a8)();
        *(undefined4 *)(param_1 + 0x20) = uVar2;
        FUN_14103a1b0(0x180a,uVar2,"winMapfile1",*(undefined8 *)(param_1 + 0x30),
                      CONCAT44(uVar7,0xc65a));
        return 0;
      }
      uVar6 = uVar4;
      lVar3 = (*(code *)PTR_MapViewOfFile_1429352d0)(lVar3,4,0,0,uVar4);
      uVar7 = (undefined4)(uVar6 >> 0x20);
      if (lVar3 == 0) {
        (*(code *)PTR_CloseHandle_142934e80)(*(undefined8 *)(param_1 + 0x40));
        *(undefined8 *)(param_1 + 0x40) = 0;
        uVar2 = (*(code *)PTR_GetLastError_1429350a8)();
        *(undefined4 *)(param_1 + 0x20) = uVar2;
        FUN_14103a1b0(0x180a,uVar2,"winMapfile2",*(undefined8 *)(param_1 + 0x30),
                      CONCAT44(uVar7,0xc66c));
        return 0;
      }
      *(longlong *)(param_1 + 0x48) = lVar3;
      *(ulonglong *)(param_1 + 0x50) = uVar4;
    }
  }
  return 0;
}


