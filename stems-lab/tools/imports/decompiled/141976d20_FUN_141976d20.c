// FUN_141976d20 @ 141976d20
// calls: [CreateFileW]

undefined4 * FUN_141976d20(longlong param_1,undefined4 *param_2,undefined8 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_res8 [8];
  
  if ((*(int *)(param_1 + 0x20) == 0) || (*(int *)(param_1 + 0x24) == 0xffff)) {
    iVar1 = *(int *)(param_1 + 0x28);
    if ((iVar1 == 0) || ((*(int *)(param_1 + 0x2c) == 0xffff || (iVar1 == 4)))) {
      puVar2 = (undefined4 *)FUN_141974de0(local_res8,param_1);
      *(undefined4 *)(param_1 + 0x20) = *puVar2;
      *(undefined4 *)(param_1 + 0x24) = puVar2[1];
      goto LAB_141976d98;
    }
    *(int *)(param_1 + 0x20) = iVar1;
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x2c);
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
  }
LAB_141976d98:
  *param_2 = *(undefined4 *)(param_1 + 0x20);
  param_2[1] = *(undefined4 *)(param_1 + 0x24);
  return param_2;
}


