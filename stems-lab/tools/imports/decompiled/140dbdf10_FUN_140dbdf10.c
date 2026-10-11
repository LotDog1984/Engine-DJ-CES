// FUN_140dbdf10 @ 140dbdf10
// calls: [CreateFileW]

longlong * FUN_140dbdf10(longlong param_1,longlong *param_2,undefined8 *param_3,undefined1 param_4)

{
  longlong *plVar1;
  PSRWLOCK SRWLock;
  int iVar2;
  longlong *plVar3;
  bool bVar4;
  bool bVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint *puVar9;
  int *piVar10;
  int *piVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined8 *local_f0;
  undefined8 *puStack_e8;
  longlong local_e0;
  PSRWLOCK local_d8;
  undefined1 local_d0;
  undefined7 uStack_cf;
  undefined8 local_c8 [2];
  ulonglong local_b8;
  ulonglong local_b0;
  longlong local_a8;
  longlong *plStack_a0;
  longlong local_98;
  longlong *local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 local_60 [8];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  bVar5 = false;
  local_f0 = (undefined8 *)0x0;
  puStack_e8 = (undefined8 *)0x0;
  local_e0 = 0;
  SRWLock = (PSRWLOCK)(param_1 + 0x3c8);
  local_d0 = 1;
  local_d8 = SRWLock;
  AcquireSRWLockShared(SRWLock);
  if (&local_f0 != (undefined8 **)(param_1 + 0x170)) {
    puVar12 = *(undefined8 **)(param_1 + 0x170);
    FUN_1406c13b0(&local_f0,puVar12,*(longlong *)(param_1 + 0x178) - (longlong)puVar12 >> 4);
  }
  ReleaseSRWLockShared(SRWLock);
  puVar12 = local_f0;
  if (local_f0 == puStack_e8) {
LAB_140dbe228:
    puVar6 = local_f0;
    *param_2 = 0;
    param_2[1] = 0;
    *param_2 = 0;
    param_2[1] = 0;
    if (local_f0 == (undefined8 *)0x0) goto LAB_140dbe428;
    FUN_1402a7870(local_f0,puStack_e8,&local_f0);
    puVar12 = puVar6;
    if ((0xfff < (local_e0 - (longlong)puVar6 & 0xfffffffffffffff0U)) &&
       (puVar12 = (undefined8 *)puVar6[-1],
       0x1f < (ulonglong)((longlong)puVar6 + (-8 - (longlong)puVar12)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
LAB_140dbe422:
    free(puVar12);
LAB_140dbe428:
    FUN_14029d460(param_3);
    return param_2;
  }
LAB_140dbdfb0:
  FUN_140ddacc0(*puVar12,&local_d8,1);
  if (local_d8 == (PSRWLOCK)0x0) goto LAB_140dbe1dc;
  FUN_140dd2630(local_d8,&local_98);
  if (local_98 != 0) {
    local_88 = *param_3;
    FUN_1402aa5d0(&uStack_80,param_3 + 1);
    FUN_140d8c020(&local_a8,&local_88,&local_98,param_4);
    if (local_a8 != 0) {
      lVar13 = *(longlong *)(local_a8 + 0x618);
      local_58 = 0;
      uStack_50 = 0;
      local_48 = 0;
      FUN_140d8e200(local_a8,local_c8);
      if (lVar13 < 1) {
        piVar10 = (int *)CONCAT71(local_c8[0]._1_7_,(undefined1)local_c8[0]);
        piVar11 = (int *)local_c8;
        if (0xf < local_b0) {
          piVar11 = piVar10;
        }
        uVar7 = 6;
        if (local_b8 < 6) {
          uVar7 = local_b8;
        }
        if (((uVar7 == 6) && (*piVar11 == *(int *)PTR_DAT_142029520)) &&
           ((short)piVar11[1] == *(short *)(PTR_DAT_142029520 + 4))) {
          bVar4 = true;
        }
        else {
          bVar4 = false;
        }
        if (bVar4) goto LAB_140dbe10f;
        uStack_80 = 0;
        local_78 = 0;
        local_70 = 7;
        local_88 = 0;
        if (local_b8 != 0) {
          piVar11 = (int *)local_c8;
          if (0xf < local_b0) {
            piVar11 = piVar10;
          }
          lVar13 = (longlong)piVar11 + local_b8;
          piVar11 = (int *)local_c8;
          if (0xf < local_b0) {
            piVar11 = piVar10;
          }
          uVar8 = FUN_14196e970();
          FUN_141971270(piVar11,lVar13,&local_88,uVar8);
        }
        bVar5 = true;
        puVar9 = (uint *)FUN_141974de0(local_60,&local_88,&local_58);
        if (1 < *puVar9) goto LAB_140dbe107;
        bVar4 = false;
        piVar10 = (int *)CONCAT71(local_c8[0]._1_7_,(undefined1)local_c8[0]);
      }
      else {
LAB_140dbe107:
        piVar10 = (int *)CONCAT71(local_c8[0]._1_7_,(undefined1)local_c8[0]);
LAB_140dbe10f:
        bVar4 = true;
      }
      if (bVar5) {
        bVar5 = false;
        FUN_1402a29e0(&local_88);
        piVar10 = (int *)CONCAT71(local_c8[0]._1_7_,(undefined1)local_c8[0]);
      }
      if (bVar4) {
        *param_2 = local_a8;
        param_2[1] = (longlong)plStack_a0;
        local_a8 = 0;
        plStack_a0 = (longlong *)0x0;
        if (0xf < local_b0) {
          piVar11 = piVar10;
          if ((0xfff < local_b0 + 1) &&
             (piVar11 = *(int **)(piVar10 + -2),
             0x1f < (ulonglong)((longlong)piVar10 + (-8 - (longlong)piVar11)))) goto LAB_140dbe2ce;
          free(piVar11);
        }
        plVar3 = plStack_a0;
        local_b8 = 0;
        local_b0 = 0xf;
        local_c8[0]._0_1_ = 0;
        if (plStack_a0 != (longlong *)0x0) {
          LOCK();
          plVar1 = plStack_a0 + 1;
          lVar13 = *plVar1;
          *(int *)plVar1 = (int)*plVar1 + -1;
          UNLOCK();
          if ((int)lVar13 == 1) {
            (**(code **)*plStack_a0)(plStack_a0);
            LOCK();
            piVar10 = (int *)((longlong)plVar3 + 0xc);
            iVar2 = *piVar10;
            *piVar10 = *piVar10 + -1;
            UNLOCK();
            if (iVar2 == 1) {
              (**(code **)(*plVar3 + 8))(plVar3);
            }
          }
        }
        if (local_90 != (longlong *)0x0) {
          LOCK();
          plVar3 = local_90 + 1;
          lVar13 = *plVar3;
          *(int *)plVar3 = (int)*plVar3 + -1;
          UNLOCK();
          if ((int)lVar13 == 1) {
            (**(code **)*local_90)(local_90);
            LOCK();
            piVar10 = (int *)((longlong)local_90 + 0xc);
            iVar2 = *piVar10;
            *piVar10 = *piVar10 + -1;
            UNLOCK();
            if (iVar2 == 1) {
              (**(code **)(*local_90 + 8))(local_90);
            }
          }
        }
        plVar3 = (longlong *)CONCAT71(uStack_cf,local_d0);
        if (plVar3 != (longlong *)0x0) {
          LOCK();
          plVar1 = plVar3 + 1;
          lVar13 = *plVar1;
          *(int *)plVar1 = (int)*plVar1 + -1;
          UNLOCK();
          if ((int)lVar13 == 1) {
            (**(code **)*plVar3)(plVar3);
            LOCK();
            piVar10 = (int *)((longlong)plVar3 + 0xc);
            iVar2 = *piVar10;
            *piVar10 = *piVar10 + -1;
            UNLOCK();
            if (iVar2 == 1) {
              (**(code **)(*plVar3 + 8))(plVar3);
            }
          }
        }
        puVar12 = local_f0;
        if (local_f0 == (undefined8 *)0x0) goto LAB_140dbe428;
        do {
          plVar3 = (longlong *)puVar12[1];
          if (plVar3 != (longlong *)0x0) {
            LOCK();
            plVar1 = plVar3 + 1;
            lVar13 = *plVar1;
            *(int *)plVar1 = (int)*plVar1 + -1;
            UNLOCK();
            if ((int)lVar13 == 1) {
              (**(code **)*plVar3)(plVar3);
              LOCK();
              piVar10 = (int *)((longlong)plVar3 + 0xc);
              iVar2 = *piVar10;
              *piVar10 = *piVar10 + -1;
              UNLOCK();
              if (iVar2 == 1) {
                (**(code **)(*plVar3 + 8))(plVar3);
              }
            }
          }
          puVar12 = puVar12 + 2;
        } while (puVar12 != puStack_e8);
        puVar12 = local_f0;
        if ((0xfff < (local_e0 - (longlong)local_f0 & 0xfffffffffffffff0U)) &&
           (puVar12 = (undefined8 *)local_f0[-1],
           0x1f < (ulonglong)((longlong)local_f0 + (-8 - (longlong)local_f0[-1])))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        goto LAB_140dbe422;
      }
      if (0xf < local_b0) {
        piVar11 = piVar10;
        if ((0xfff < local_b0 + 1) &&
           (piVar11 = *(int **)(piVar10 + -2),
           0x1f < (ulonglong)((longlong)piVar10 + (-8 - (longlong)piVar11)))) {
LAB_140dbe2ce:
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(piVar11);
      }
    }
    plVar3 = plStack_a0;
    if (plStack_a0 != (longlong *)0x0) {
      LOCK();
      plVar1 = plStack_a0 + 1;
      lVar13 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if ((int)lVar13 == 1) {
        (**(code **)*plStack_a0)(plStack_a0);
        LOCK();
        piVar10 = (int *)((longlong)plVar3 + 0xc);
        iVar2 = *piVar10;
        *piVar10 = *piVar10 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (**(code **)(*plVar3 + 8))(plVar3);
        }
      }
    }
  }
  plVar3 = local_90;
  if (local_90 != (longlong *)0x0) {
    LOCK();
    plVar1 = local_90 + 1;
    lVar13 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar13 == 1) {
      (**(code **)*local_90)(local_90);
      LOCK();
      piVar10 = (int *)((longlong)plVar3 + 0xc);
      iVar2 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(*plVar3 + 8))(plVar3);
      }
    }
  }
LAB_140dbe1dc:
  plVar3 = (longlong *)CONCAT71(uStack_cf,local_d0);
  if (plVar3 != (longlong *)0x0) {
    LOCK();
    plVar1 = plVar3 + 1;
    lVar13 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar13 == 1) {
      (**(code **)*plVar3)(plVar3);
      LOCK();
      piVar10 = (int *)((longlong)plVar3 + 0xc);
      iVar2 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(*plVar3 + 8))(plVar3);
      }
    }
  }
  puVar12 = puVar12 + 2;
  if (puVar12 == puStack_e8) goto LAB_140dbe228;
  goto LAB_140dbdfb0;
}


