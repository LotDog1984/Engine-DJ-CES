// FUN_1412f3c90 @ 1412f3c90
// calls: [CreateFileW]

/* WARNING: Removing unreachable block (ram,0x0001412f3dcf) */

longlong * FUN_1412f3c90(longlong param_1,longlong *param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  
  uVar6 = 0;
  bVar5 = true;
  if (*(char *)(param_1 + 0x20) == '\x02') {
    lVar3 = -1;
    uVar4 = 0;
  }
  else {
    lVar3 = FUN_1412f6500(param_1,0,0);
    if ((lVar3 != -1) && (iVar2 = FUN_1412f5bc0(lVar3,1,0), iVar2 != 0)) {
      thunk_FUN_1412f5560(lVar3);
      lVar3 = -1;
    }
    uVar6 = 4;
    bVar5 = true;
    if (lVar3 != -1) goto LAB_1412f3e54;
    lVar3 = FUN_1412f6500(param_1,3,0);
    if ((lVar3 != -1) && (iVar2 = FUN_1412f5bc0(lVar3,1,0), iVar2 != 0)) {
      thunk_FUN_1412f5560(lVar3);
      lVar3 = -1;
    }
    uVar4 = 0x404;
    uVar6 = 0x404;
    bVar5 = lVar3 == -1;
  }
  if (lVar3 == -1) {
    lVar3 = FUN_1412f5e30(param_1,1,0);
    if ((lVar3 != -1) && (iVar2 = FUN_1412f5bc0(lVar3,1,0), iVar2 != 0)) {
      thunk_FUN_1412f5560(lVar3);
      lVar3 = -1;
    }
    uVar6 = uVar4 | 0x40;
    if (lVar3 == -1) {
      *param_2 = -1;
      return param_2;
    }
  }
LAB_1412f3e54:
  cVar1 = FUN_1412f3ec0(param_1,lVar3,param_3,bVar5,uVar6);
  if ((cVar1 == '\0') && (cVar1 = FUN_1412f3ff0(param_1,lVar3,param_3), cVar1 == '\0')) {
    *param_2 = -1;
    if (lVar3 != -1) {
      FUN_1412f6380(lVar3);
      FUN_1412f5560(lVar3);
    }
  }
  else {
    *param_2 = lVar3;
  }
  return param_2;
}


