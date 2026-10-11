// FUN_141050f10 @ 141050f10
// calls: [ReadFile]

undefined8 FUN_141050f10(undefined8 param_1,int *param_2)

{
  longlong lVar1;
  
  if (-1 < *param_2) {
    if ((((*(ushort *)(param_2 + 6) & 0xf000) + 0xe000 & 0x9fff) != 0) ||
       ((*(ushort *)(param_2 + 6) & 0xf000) == 0x4000)) {
      do {
        lVar1 = FUN_14108ae00(*param_2,*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 2));
      } while (0 < lVar1);
    }
    if (param_2[7] != 0) {
      _close(*param_2);
    }
  }
  free(*(void **)(param_2 + 4));
  param_2[4] = 0;
  param_2[5] = 0;
  *param_2 = -1;
  return 0;
}


