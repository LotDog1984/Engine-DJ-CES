// FUN_140de2930 @ 140de2930
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_140de2930(longlong param_1,longlong *param_2,ulonglong param_3,undefined4 param_4)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  code *pcVar5;
  void *pvVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  undefined8 uVar10;
  uint *puVar11;
  undefined8 uVar12;
  void *pvVar13;
  longlong lVar14;
  bool bVar15;
  undefined1 local_res8 [8];
  longlong local_150;
  longlong *plStack_148;
  longlong local_140;
  longlong *local_138;
  longlong local_130;
  longlong *plStack_128;
  longlong local_120;
  longlong *plStack_118;
  undefined1 local_110;
  undefined7 uStack_10f;
  undefined8 local_100;
  ulonglong uStack_f8;
  longlong local_f0;
  longlong *local_e8;
  void *local_e0 [3];
  ulonglong local_c8;
  longlong local_c0;
  longlong *local_b8;
  void *local_b0 [3];
  ulonglong local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined1 local_78 [32];
  undefined1 local_58 [48];
  
  lVar14 = DAT_142029460;
  AcquireSRWLockShared((PSRWLOCK)(param_1 + 0xf8));
  if (param_3 < (ulonglong)(*(longlong *)(param_1 + 0x38) - *(longlong *)(param_1 + 0x30) >> 3)) {
    lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x30) + param_3 * 8);
  }
  ReleaseSRWLockShared((PSRWLOCK)(param_1 + 0xf8));
  if (lVar14 == DAT_142029460) {
    *param_2 = 0;
    param_2[1] = 0;
    *param_2 = 0;
    param_2[1] = 0;
    return param_2;
  }
  FUN_140dc4fc0(*(undefined8 *)(param_1 + 0x18),&local_140,lVar14,param_4);
  if ((local_140 == 0) || ((*(uint *)(param_1 + 0x28) >> 4 & 1) == 0)) {
LAB_140de2fc5:
    param_2[1] = 0;
    *param_2 = local_140;
    param_2[1] = (longlong)local_138;
  }
  else {
    local_150 = 0;
    plStack_148 = (longlong *)0x0;
    lVar14 = *(longlong *)(param_1 + 0x138);
    if (lVar14 != 0) {
      iVar3 = *(int *)(lVar14 + 8);
      do {
        if (iVar3 == 0) goto LAB_140de2a21;
        LOCK();
        iVar9 = *(int *)(lVar14 + 8);
        bVar15 = iVar3 == iVar9;
        if (bVar15) {
          *(int *)(lVar14 + 8) = iVar3 + 1;
          iVar9 = iVar3;
        }
        UNLOCK();
        iVar3 = iVar9;
      } while (!bVar15);
      local_150 = *(longlong *)(param_1 + 0x130);
      plStack_148 = *(longlong **)(param_1 + 0x138);
    }
LAB_140de2a21:
    bVar8 = false;
    bVar15 = false;
    if (local_150 == 0) {
LAB_140de2dd3:
      if (plStack_148 != (longlong *)0x0) {
        LOCK();
        plVar4 = plStack_148 + 1;
        lVar14 = *plVar4;
        *(int *)plVar4 = (int)*plVar4 + -1;
        UNLOCK();
        if ((int)lVar14 == 1) {
          (**(code **)*plStack_148)(plStack_148);
          LOCK();
          piVar1 = (int *)((longlong)plStack_148 + 0xc);
          iVar3 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plStack_148 + 8))();
          }
        }
      }
      uVar10 = *(undefined8 *)(param_1 + 0x18);
      uVar12 = FUN_140d94970(local_140,local_58);
      FUN_140dbdf10(uVar10,&local_120,uVar12,1);
      if (local_120 == 0) {
        if (plStack_118 != (longlong *)0x0) {
          LOCK();
          plVar4 = plStack_118 + 1;
          lVar14 = *plVar4;
          *(int *)plVar4 = (int)*plVar4 + -1;
          UNLOCK();
          if ((int)lVar14 == 1) {
            (**(code **)*plStack_118)(plStack_118);
            LOCK();
            piVar1 = (int *)((longlong)plStack_118 + 0xc);
            iVar3 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar3 == 1) {
              (**(code **)(*plStack_118 + 8))(plStack_118);
            }
          }
        }
        goto LAB_140de2fc5;
      }
      plVar4 = *(longlong **)(param_1 + 0x18);
      pcVar5 = *(code **)(*plVar4 + 0x18);
      uVar10 = FUN_140d8e200(local_120,local_e0);
      FUN_14036d170(local_b0,uVar10,0);
      uVar10 = (*pcVar5)(plVar4,local_78,local_b0);
      uVar10 = FUN_14041f360(uVar10,&local_110);
      FUN_1404ae8e0(local_120 + 0x6a0,uVar10);
      if (0xf < uStack_f8) {
        pvVar6 = (void *)CONCAT71(uStack_10f,local_110);
        pvVar13 = pvVar6;
        if ((0xfff < uStack_f8 + 1) &&
           (pvVar13 = *(void **)((longlong)pvVar6 + -8),
           0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar13);
      }
      local_100 = _DAT_141ac9b00;
      uStack_f8 = _UNK_141ac9b08;
      local_110 = 0;
      FUN_1402a29e0(local_78);
      FUN_1402a29e0(local_b0);
      if (0xf < local_c8) {
        pvVar13 = local_e0[0];
        if ((0xfff < local_c8 + 1) &&
           (pvVar13 = *(void **)((longlong)local_e0[0] + -8),
           0x1f < (ulonglong)((longlong)local_e0[0] + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar13);
      }
      param_2[1] = 0;
      *param_2 = local_120;
      param_2[1] = (longlong)plStack_118;
      local_120 = 0;
      plStack_118 = (longlong *)0x0;
    }
    else {
      FUN_140ddacc0(local_150,&local_c0,1);
      if (local_c0 == 0) {
LAB_140de2da0:
        if (local_b8 != (longlong *)0x0) {
          LOCK();
          plVar4 = local_b8 + 1;
          lVar14 = *plVar4;
          *(int *)plVar4 = (int)*plVar4 + -1;
          UNLOCK();
          if ((int)lVar14 == 1) {
            (**(code **)*local_b8)(local_b8);
            LOCK();
            piVar1 = (int *)((longlong)local_b8 + 0xc);
            iVar3 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar3 == 1) {
              (**(code **)(*local_b8 + 8))(local_b8);
            }
          }
        }
        goto LAB_140de2dd3;
      }
      FUN_140dd2630(local_c0,&local_f0);
      if (local_f0 == 0) {
LAB_140de2d6d:
        if (local_e8 != (longlong *)0x0) {
          LOCK();
          plVar4 = local_e8 + 1;
          lVar14 = *plVar4;
          *(int *)plVar4 = (int)*plVar4 + -1;
          UNLOCK();
          if ((int)lVar14 == 1) {
            (**(code **)*local_e8)(local_e8);
            LOCK();
            piVar1 = (int *)((longlong)local_e8 + 0xc);
            iVar3 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar3 == 1) {
              (**(code **)(*local_e8 + 8))(local_e8);
            }
          }
        }
        goto LAB_140de2da0;
      }
      local_90 = 0;
      uStack_88 = 0;
      local_80 = 0;
      uVar10 = FUN_140d94970(local_140,local_58);
      FUN_140d8c020(&local_130,uVar10,&local_f0,1);
      if (local_130 == 0) {
LAB_140de2afc:
        bVar7 = false;
      }
      else {
        if (*(longlong *)(local_140 + 0x618) < 1) {
          uVar10 = FUN_140d8e200(local_130,local_e0);
          FUN_14036d170(&local_110,uVar10,0);
          bVar8 = true;
          bVar15 = true;
          puVar11 = (uint *)FUN_141974de0(local_res8,&local_110,&local_90);
          if (*puVar11 < 2) goto LAB_140de2afc;
        }
        bVar7 = true;
      }
      if (bVar8) {
        FUN_1402a29e0(&local_110);
      }
      if ((bVar15) && (0xf < local_c8)) {
        pvVar13 = local_e0[0];
        if ((0xfff < local_c8 + 1) &&
           (pvVar13 = *(void **)((longlong)local_e0[0] + -8),
           0x1f < (ulonglong)((longlong)local_e0[0] + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar13);
      }
      plVar4 = plStack_128;
      if (!bVar7) {
        if (plStack_128 != (longlong *)0x0) {
          LOCK();
          plVar2 = plStack_128 + 1;
          lVar14 = *plVar2;
          *(int *)plVar2 = (int)*plVar2 + -1;
          UNLOCK();
          if ((int)lVar14 == 1) {
            (**(code **)*plStack_128)(plStack_128);
            LOCK();
            piVar1 = (int *)((longlong)plVar4 + 0xc);
            iVar3 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar3 == 1) {
              (**(code **)(*plVar4 + 8))(plVar4);
            }
          }
        }
        goto LAB_140de2d6d;
      }
      plVar4 = *(longlong **)(param_1 + 0x18);
      pcVar5 = *(code **)(*plVar4 + 0x18);
      uVar10 = FUN_140d8e200(local_130,local_b0);
      FUN_14036d170(local_e0,uVar10,0);
      uVar10 = (*pcVar5)(plVar4,local_78,local_e0);
      uVar10 = FUN_14041f360(uVar10,&local_110);
      FUN_1404ae8e0(local_130 + 0x6a0,uVar10);
      if (0xf < uStack_f8) {
        pvVar6 = (void *)CONCAT71(uStack_10f,local_110);
        pvVar13 = pvVar6;
        if ((0xfff < uStack_f8 + 1) &&
           (pvVar13 = *(void **)((longlong)pvVar6 + -8),
           0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar13);
      }
      local_100 = _DAT_141ac9b00;
      uStack_f8 = _UNK_141ac9b08;
      local_110 = 0;
      FUN_1402a29e0(local_78);
      FUN_1402a29e0(local_e0);
      if (0xf < local_98) {
        pvVar13 = local_b0[0];
        if ((0xfff < local_98 + 1) &&
           (pvVar13 = *(void **)((longlong)local_b0[0] + -8),
           0x1f < (ulonglong)((longlong)local_b0[0] + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar13);
      }
      param_2[1] = 0;
      *param_2 = local_130;
      param_2[1] = (longlong)plStack_128;
      local_130 = 0;
      plStack_128 = (longlong *)0x0;
      if (local_e8 != (longlong *)0x0) {
        LOCK();
        plVar4 = local_e8 + 1;
        lVar14 = *plVar4;
        *(int *)plVar4 = (int)*plVar4 + -1;
        UNLOCK();
        if ((int)lVar14 == 1) {
          (**(code **)*local_e8)(local_e8);
          LOCK();
          piVar1 = (int *)((longlong)local_e8 + 0xc);
          iVar3 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*local_e8 + 8))(local_e8);
          }
        }
      }
      if (local_b8 != (longlong *)0x0) {
        LOCK();
        plVar4 = local_b8 + 1;
        lVar14 = *plVar4;
        *(int *)plVar4 = (int)*plVar4 + -1;
        UNLOCK();
        if ((int)lVar14 == 1) {
          (**(code **)*local_b8)(local_b8);
          LOCK();
          piVar1 = (int *)((longlong)local_b8 + 0xc);
          iVar3 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*local_b8 + 8))(local_b8);
          }
        }
      }
      if (plStack_148 != (longlong *)0x0) {
        LOCK();
        plVar4 = plStack_148 + 1;
        lVar14 = *plVar4;
        *(int *)plVar4 = (int)*plVar4 + -1;
        UNLOCK();
        if ((int)lVar14 == 1) {
          (**(code **)*plStack_148)(plStack_148);
          LOCK();
          piVar1 = (int *)((longlong)plStack_148 + 0xc);
          iVar3 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plStack_148 + 8))();
          }
        }
      }
    }
    if (local_138 != (longlong *)0x0) {
      LOCK();
      plVar4 = local_138 + 1;
      lVar14 = *plVar4;
      *(int *)plVar4 = (int)*plVar4 + -1;
      UNLOCK();
      if ((int)lVar14 == 1) {
        (**(code **)*local_138)(local_138);
        LOCK();
        piVar1 = (int *)((longlong)local_138 + 0xc);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          (**(code **)(*local_138 + 8))(local_138);
        }
      }
    }
  }
  return param_2;
}


