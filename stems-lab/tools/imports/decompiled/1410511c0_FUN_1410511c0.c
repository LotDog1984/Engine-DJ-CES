// FUN_1410511c0 @ 1410511c0
// calls: [ReadFile]

longlong FUN_1410511c0(undefined8 param_1,undefined4 *param_2,undefined8 *param_3)

{
  longlong lVar1;
  int *piVar2;
  char *pcVar3;
  
  *param_3 = *(undefined8 *)(param_2 + 4);
  do {
    lVar1 = FUN_14108ae00(*param_2,*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2));
    if (-1 < lVar1) {
      return lVar1;
    }
    piVar2 = _errno();
  } while (*piVar2 == 4);
  if (param_2[7] != 0) {
    if (param_2[7] == 1) {
      piVar2 = _errno();
      pcVar3 = "Error reading \'%s\'";
    }
    else {
      piVar2 = _errno();
      pcVar3 = "Error reading \'%S\'";
    }
    FUN_1410557b0(param_1,*piVar2,pcVar3,param_2 + 8);
    return lVar1;
  }
  piVar2 = _errno();
  FUN_1410557b0(param_1,*piVar2,"Error reading stdin");
  return lVar1;
}


