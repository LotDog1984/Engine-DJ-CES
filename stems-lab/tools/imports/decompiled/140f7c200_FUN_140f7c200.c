// FUN_140f7c200 @ 140f7c200
// calls: [CreateFileMappingW]

ulonglong FUN_140f7c200(longlong param_1,int param_2,int param_3,int param_4,ulonglong *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  int iVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  longlong in_stack_ffffffffffffffb8;
  undefined8 uVar14;
  
  plVar7 = *(longlong **)(param_1 + 0x28);
  uVar12 = 0;
  uVar9 = uVar12;
  if (plVar7 == (longlong *)0x0) {
    uVar5 = FUN_14103a440();
    uVar9 = uVar5 & 0xffffffff;
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    plVar7 = *(longlong **)(param_1 + 0x28);
  }
  plVar7 = (longlong *)*plVar7;
  if (*plVar7 != 0) {
    (*DAT_1429345c0)();
  }
  if (*(char *)((longlong)plVar7 + 0x79) == '\0') {
LAB_140f7c26e:
    if (*(int *)((longlong)plVar7 + 0x74) <= param_2) {
      *(int *)(plVar7 + 0xe) = param_3;
      iVar11 = (param_2 + 1) * param_3;
      iVar2 = (*(code *)PTR_GetFileSize_142935060)(plVar7[4],local_res8);
      lVar8 = CONCAT44(local_res8[0],iVar2);
      uVar9 = uVar12;
      if ((iVar2 == -1) && (iVar2 = (*(code *)PTR_GetLastError_1429350a8)(), uVar9 = 0, iVar2 != 0))
      {
        *(int *)(plVar7 + 6) = iVar2;
        in_stack_ffffffffffffffb8 =
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20),0xc113);
        uVar1 = FUN_14103a1b0(0x70a,iVar2,"winFileSize",plVar7[8],in_stack_ffffffffffffffb8);
        uVar9 = (ulonglong)uVar1;
      }
      uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
      if ((int)uVar9 == 0) {
        if (lVar8 < iVar11) {
          if (param_4 != 0) {
            uVar1 = FUN_140f74600(plVar7 + 2);
            uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
            uVar9 = (ulonglong)uVar1;
            if (uVar1 == 0) goto LAB_140f7c362;
            uVar3 = (*(code *)PTR_GetLastError_1429350a8)();
            uVar1 = FUN_14103a1b0(0x130a,uVar3,"winShmMap2",*(undefined8 *)(param_1 + 0x30),
                                  CONCAT44(uVar4,0xc596));
            uVar9 = (ulonglong)uVar1;
          }
        }
        else {
LAB_140f7c362:
          lVar8 = FUN_140f8c8d0(plVar7[0x10]);
          if (lVar8 == 0) {
            uVar9 = 0xc0a;
          }
          else {
            plVar7[0x10] = lVar8;
            local_res8[0] = 4;
            bVar13 = (char)plVar7[0xf] == '\0';
            if (bVar13) {
              local_res8[0] = 6;
            }
            uVar4 = 2;
            if (bVar13) {
              uVar4 = 4;
            }
            iVar2 = *(int *)((longlong)plVar7 + 0x74);
            while (iVar2 <= param_2) {
              uVar14 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20),iVar11);
              lVar8 = (*(code *)PTR_CreateFileMappingW_142934ee0)(plVar7[4],0,uVar4,0,uVar14,0);
              uVar3 = (undefined4)((ulonglong)uVar14 >> 0x20);
              if (lVar8 == 0) {
LAB_140f7c453:
                uVar4 = (*(code *)PTR_GetLastError_1429350a8)();
                *(undefined4 *)(plVar7 + 0x11) = uVar4;
                uVar1 = FUN_14103a1b0(0x150a,uVar4,"winShmMap3",*(undefined8 *)(param_1 + 0x30),
                                      CONCAT44(uVar3,0xc5d1));
                uVar9 = (ulonglong)uVar1;
                if (lVar8 != 0) {
                  (*(code *)PTR_CloseHandle_142934e80)(lVar8);
                }
                break;
              }
              uVar10 = param_3 * *(int *)((longlong)plVar7 + 0x74);
              uVar1 = uVar10 % DAT_142b24fd0;
              in_stack_ffffffffffffffb8 = (longlong)(int)(param_3 + uVar1);
              lVar6 = (*(code *)PTR_MapViewOfFile_1429352d0)
                                (lVar8,local_res8[0],0,uVar10 - uVar1,in_stack_ffffffffffffffb8);
              uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
              if (lVar6 == 0) goto LAB_140f7c453;
              *(longlong *)(plVar7[0x10] + 8 + (longlong)*(int *)((longlong)plVar7 + 0x74) * 0x10) =
                   lVar6;
              *(longlong *)(plVar7[0x10] + (longlong)*(int *)((longlong)plVar7 + 0x74) * 0x10) =
                   lVar8;
              *(int *)((longlong)plVar7 + 0x74) = *(int *)((longlong)plVar7 + 0x74) + 1;
              iVar2 = *(int *)((longlong)plVar7 + 0x74);
            }
          }
        }
      }
      else {
        uVar3 = (*(code *)PTR_GetLastError_1429350a8)();
        uVar1 = FUN_14103a1b0(0x130a,uVar3,"winShmMap1",*(undefined8 *)(param_1 + 0x30),
                              CONCAT44(uVar4,0xc587));
        uVar9 = (ulonglong)uVar1;
      }
      goto LAB_140f7c49f;
    }
  }
  else {
    uVar1 = FUN_14103a000(plVar7);
    uVar9 = (ulonglong)uVar1;
    if (uVar1 == 0) {
      *(undefined1 *)((longlong)plVar7 + 0x79) = 0;
      goto LAB_140f7c26e;
    }
LAB_140f7c49f:
    if (*(int *)((longlong)plVar7 + 0x74) <= param_2) goto LAB_140f7c4c6;
  }
  uVar12 = (longlong)(int)((uint)(param_2 * param_3) % DAT_142b24fd0) +
           *(longlong *)(plVar7[0x10] + 8 + (longlong)param_2 * 0x10);
LAB_140f7c4c6:
  *param_5 = uVar12;
  if (((char)plVar7[0xf] != '\0') && ((int)uVar9 == 0)) {
    uVar9 = 8;
  }
  if (*plVar7 != 0) {
    (*DAT_1429345d0)();
  }
  return uVar9;
}


