// FUN_140e56020 @ 140e56020
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140e56020(undefined8 *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  void *pvVar8;
  void *pvVar9;
  undefined8 *puVar10;
  int *local_res8;
  int *local_res10;
  undefined8 local_res18;
  void **local_res20;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  ulonglong local_100;
  void *local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  ulonglong uStack_e0;
  void *local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  ulonglong local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  ulonglong local_a8;
  undefined1 local_a0 [32];
  undefined1 local_80 [40];
  undefined1 local_58 [64];
  
  cVar2 = FUN_140e55c30(param_1,param_1);
  if (cVar2 == '\0') {
    local_b8 = 0;
    uStack_b0 = 0;
    local_a8 = 0;
    puVar10 = param_1;
    if (7 < (ulonglong)param_1[3]) {
      puVar10 = (undefined8 *)*param_1;
    }
    lVar4 = FUN_14196f640(param_1);
    puVar10 = (undefined8 *)((longlong)puVar10 + lVar4 * 2);
    if (7 < (ulonglong)param_1[3]) {
      param_1 = (undefined8 *)*param_1;
    }
    local_f8 = (void *)0x0;
    uStack_f0 = 0;
    local_e8 = 0;
    uStack_e0 = 0;
    if (param_1 == puVar10) {
      local_e8 = _DAT_141cb0070;
      uStack_e0 = _UNK_141cb0078;
      local_f8 = (void *)0x0;
    }
    else {
      FUN_1402a7200(&local_f8,param_1,(longlong)puVar10 - (longlong)param_1 >> 1);
    }
    local_res20 = &local_f8;
    puVar5 = (uint *)FUN_141974de0(&local_res8,&local_f8,&local_b8);
    if (1 < *puVar5) {
      local_res10 = (int *)0x0;
      FUN_141975f70(&local_res10,&local_f8,0,&local_b8);
      if (((local_a8 & 1) != 0) && ((local_a8 != 1 || ((int)local_b8 != 0)))) {
        uVar6 = FUN_141956400(local_80,&local_f8);
        uVar7 = FUN_1405abe00(&local_b8,local_a0);
        uVar7 = FUN_14029e990(&local_d8,uVar7,"\nwhile getting info on ");
        uVar6 = FUN_14029e960(&local_118,uVar7,uVar6);
        FUN_1406e9ad0(local_58,0x4f,uVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_58,(ThrowInfo *)&DAT_14288da78);
      }
      local_res8 = local_res10;
      if (local_res10 != (int *)0x0) {
        LOCK();
        *local_res10 = *local_res10 + 1;
        UNLOCK();
      }
      local_res18 = 0;
      do {
        piVar1 = local_res8;
        if ((local_res8 == (int *)0x0) || (*(longlong *)(local_res8 + 0xe) == 0)) {
          if (local_res8 != (int *)0x0) {
            LOCK();
            iVar3 = *local_res8;
            *local_res8 = *local_res8 + -1;
            UNLOCK();
            if ((iVar3 == 1) && (local_res8 != (int *)0x0)) {
              FUN_141975a80(&local_118,local_res8 + 0xe);
              FUN_1402a29e0(piVar1 + 2);
              free(piVar1);
            }
          }
          piVar1 = local_res10;
          if (local_res10 != (int *)0x0) {
            LOCK();
            iVar3 = *local_res10;
            *local_res10 = *local_res10 + -1;
            UNLOCK();
            if ((iVar3 == 1) && (local_res10 != (int *)0x0)) {
              FUN_141975a80(&local_118,local_res10 + 0xe);
              FUN_1402a29e0(piVar1 + 2);
              free(piVar1);
            }
          }
          FUN_1402a29e0(&local_f8);
          return 1;
        }
        FUN_14196ffa0(local_res8 + 2,&local_d8);
        FUN_14196fa80(&local_d8,local_a0);
        FUN_1402a29e0(&local_d8);
        uStack_d0 = 0;
        local_c8 = 0;
        local_c0 = 7;
        local_d8 = (void *)0x0;
        uStack_110 = 0;
        local_108 = 3;
        local_100 = 0xf;
        local_118 = (void *)(ulonglong)(uint3)DAT_142036238;
        uVar6 = FUN_14196e970();
        FUN_141971270(&local_118,(longlong)&local_118 + 3,&local_d8,uVar6);
        if (0xf < local_100) {
          pvVar9 = local_118;
          if ((0xfff < local_100 + 1) &&
             (pvVar9 = *(void **)((longlong)local_118 + -8),
             0x1f < (ulonglong)((longlong)local_118 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(pvVar9);
        }
        FUN_14196f1d0(local_a0,local_80);
        iVar3 = FUN_14196ead0(local_80,&local_d8);
        FUN_1402a29e0(local_80);
        if (7 < local_c0) {
          pvVar9 = local_d8;
          if ((0xfff < local_c0 * 2 + 2) &&
             (pvVar9 = *(void **)((longlong)local_d8 + -8),
             0x1f < (ulonglong)((longlong)local_d8 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(pvVar9);
        }
        if (iVar3 == 0) {
          iVar3 = FUN_140dd0d80(local_a0);
          if (iVar3 != 0) {
            FUN_1402a29e0(local_a0);
            piVar1 = local_res8;
            if (local_res8 != (int *)0x0) {
              LOCK();
              iVar3 = *local_res8;
              *local_res8 = *local_res8 + -1;
              UNLOCK();
              if ((iVar3 == 1) && (local_res8 != (int *)0x0)) {
                FUN_141975a80(&local_118,local_res8 + 0xe);
                FUN_1402a29e0(piVar1 + 2);
                free(piVar1);
              }
            }
            piVar1 = local_res10;
            if (local_res10 != (int *)0x0) {
              LOCK();
              iVar3 = *local_res10;
              *local_res10 = *local_res10 + -1;
              UNLOCK();
              if ((iVar3 == 1) && (local_res10 != (int *)0x0)) {
                FUN_141975a80(&local_118,local_res10 + 0xe);
                if (7 < *(ulonglong *)(piVar1 + 8)) {
                  pvVar9 = *(void **)(piVar1 + 2);
                  pvVar8 = pvVar9;
                  if ((0xfff < *(ulonglong *)(piVar1 + 8) * 2 + 2) &&
                     (pvVar8 = *(void **)((longlong)pvVar9 + -8),
                     0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar8)))) {
LAB_140e5651f:
                    /* WARNING: Subroutine does not return */
                    _invalid_parameter_noinfo_noreturn();
                  }
                  free(pvVar8);
                }
                piVar1[6] = 0;
                piVar1[7] = 0;
                piVar1[8] = 7;
                piVar1[9] = 0;
                *(undefined2 *)(piVar1 + 2) = 0;
                free(piVar1);
              }
            }
            if (7 < uStack_e0) {
              pvVar9 = local_f8;
              if ((0xfff < uStack_e0 * 2 + 2) &&
                 (pvVar9 = *(void **)((longlong)local_f8 + -8),
                 0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)pvVar9)))) {
LAB_140e56518:
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
              free(pvVar9);
            }
            return 0;
          }
          iVar3 = FUN_140dd0ed0(local_a0);
          if (iVar3 != 0) {
            FUN_1402a29e0(local_a0);
            FUN_1407c26e0(&local_res8);
            piVar1 = local_res10;
            if (local_res10 != (int *)0x0) {
              LOCK();
              iVar3 = *local_res10;
              *local_res10 = *local_res10 + -1;
              UNLOCK();
              if ((iVar3 == 1) && (local_res10 != (int *)0x0)) {
                FUN_141975a80(&local_118,local_res10 + 0xe);
                if (7 < *(ulonglong *)(piVar1 + 8)) {
                  pvVar9 = *(void **)(piVar1 + 2);
                  pvVar8 = pvVar9;
                  if ((0xfff < *(ulonglong *)(piVar1 + 8) * 2 + 2) &&
                     (pvVar8 = *(void **)((longlong)pvVar9 + -8),
                     0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar8))))
                  goto LAB_140e5651f;
                  free(pvVar8);
                }
                piVar1[6] = 0;
                piVar1[7] = 0;
                piVar1[8] = 7;
                piVar1[9] = 0;
                *(undefined2 *)(piVar1 + 2) = 0;
                free(piVar1);
              }
            }
            if (7 < uStack_e0) {
              pvVar9 = local_f8;
              if ((0xfff < uStack_e0 * 2 + 2) &&
                 (pvVar9 = *(void **)((longlong)local_f8 + -8),
                 0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)pvVar9))))
              goto LAB_140e56518;
              free(pvVar9);
            }
            return 0;
          }
        }
        FUN_1402a29e0(local_a0);
        FUN_1419765c0(&local_res8,0);
      } while( true );
    }
    if (7 < uStack_e0) {
      pvVar9 = local_f8;
      if ((0xfff < uStack_e0 * 2 + 2) &&
         (pvVar9 = *(void **)((longlong)local_f8 + -8),
         0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar9);
    }
  }
  return 1;
}


