// FUN_140f73900 @ 140f73900
// calls: [ReadFile]

undefined8 FUN_140f73900(longlong param_1,void *param_2,uint param_3,longlong param_4)

{
  void *_Src;
  longlong lVar1;
  undefined8 uVar2;
  size_t _Size;
  int iVar3;
  int iVar4;
  uint local_res8 [2];
  undefined8 *puVar5;
  undefined4 uVar6;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  uint local_34;
  undefined8 local_30;
  
  lVar1 = *(longlong *)(param_1 + 0x50);
  iVar3 = 0;
  if (param_4 < lVar1) {
    _Src = (void *)(*(longlong *)(param_1 + 0x48) + param_4);
    if (param_4 + (int)param_3 <= lVar1) {
      memcpy(param_2,_Src,(longlong)(int)param_3);
      return 0;
    }
    iVar4 = (int)lVar1 - (int)param_4;
    _Size = (size_t)iVar4;
    memcpy(param_2,_Src,_Size);
    param_2 = (void *)((longlong)param_2 + _Size);
    param_3 = param_3 - iVar4;
    param_4 = param_4 + _Size;
  }
  local_38 = (undefined4)param_4;
  local_34 = (uint)((ulonglong)param_4 >> 0x20) & 0x7fffffff;
  local_48 = 0;
  local_40 = 0;
  local_30 = 0;
  while( true ) {
    puVar5 = &local_48;
    iVar4 = (*(code *)PTR_ReadFile_142935318)
                      (*(undefined8 *)(param_1 + 0x10),param_2,param_3,local_res8,puVar5);
    uVar6 = (undefined4)((ulonglong)puVar5 >> 0x20);
    if ((iVar4 != 0) || (iVar4 = (*(code *)PTR_GetLastError_1429350a8)(), iVar4 == 0x26)) break;
    iVar4 = (*(code *)PTR_GetLastError_1429350a8)();
    if ((DAT_1429348e8 <= iVar3) ||
       ((((0x3b < iVar4 - 5U || ((0x804000018000001U >> ((ulonglong)(iVar4 - 5U) & 0x3f) & 1) == 0))
         && (iVar4 != 0x79)) && (iVar4 != 0x4cf)))) {
      *(int *)(param_1 + 0x20) = iVar4;
      uVar2 = FUN_14103a1b0(0x10a,iVar4,"winRead",*(undefined8 *)(param_1 + 0x30),
                            CONCAT44(uVar6,0xbfc3));
      return uVar2;
    }
    (*(code *)PTR_Sleep_142935360)((iVar3 + 1) * DAT_1429348ec);
    iVar3 = iVar3 + 1;
  }
  if (iVar3 != 0) {
    FUN_140f7a5e0(0x1b,"delayed %dms for lock/sharing conflict at line %d",
                  ((iVar3 + 1) * DAT_1429348ec * iVar3) / 2,0xbfc5);
  }
  if (param_3 <= local_res8[0]) {
    return 0;
  }
  memset((void *)((longlong)param_2 + (ulonglong)local_res8[0]),0,
         (ulonglong)(param_3 - local_res8[0]));
  return 0x20a;
}


