// FUN_14105d310 @ 14105d310
// calls: [WriteFile]

void FUN_14105d310(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (*(char *)(param_1 + lVar2) != '\0');
  while ((lVar2 != 0 && (lVar1 = FUN_14108b440(2,param_1,lVar2), 0 < lVar1))) {
    param_1 = param_1 + lVar1;
    lVar2 = lVar2 - lVar1;
  }
  return;
}


