// FUN_14066eaa0 @ 14066eaa0
// calls: [MoveFileExW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_14066eaa0(undefined8 *param_1,undefined8 *param_2,longlong *param_3)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 ******ppppppuVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined8 ******ppppppuVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  longlong *local_88;
  longlong *local_80;
  undefined8 *****local_78;
  longlong *local_70;
  ulonglong local_60;
  undefined *local_58;
  char local_50;
  undefined8 *****local_48 [3];
  ulonglong local_30;
  
  plVar5 = (longlong *)0x0;
  local_58 = &DAT_1428e2310;
  local_50 = 0;
  iVar3 = _Mtx_lock(&DAT_1428e2310);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    std::_Throw_Cpp_error(5);
  }
  if (DAT_1428e235c == 0x7fffffff) {
    DAT_1428e235c = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
    std::_Throw_Cpp_error(6);
  }
  local_50 = '\x01';
  FUN_14066de80(&local_88,param_2);
  if (local_88 == (longlong *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    FUN_14066de80(&local_78,param_3);
    plVar7 = local_70;
    if ((undefined8 ******)local_78 == (undefined8 ******)0x0) {
      if (local_70 != (longlong *)0x0) {
        LOCK();
        plVar8 = local_70 + 1;
        lVar2 = *plVar8;
        *(int *)plVar8 = (int)*plVar8 + -1;
        UNLOCK();
        if ((int)lVar2 == 1) {
          (**(code **)*local_70)(local_70);
          LOCK();
          piVar1 = (int *)((longlong)plVar7 + 0xc);
          iVar3 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*local_70 + 8))();
          }
        }
      }
      FUN_14029e800(local_48,param_3,0);
      FUN_14029e800(&local_78,param_2,0);
      ppppppuVar9 = local_48;
      if (7 < local_30) {
        ppppppuVar9 = (undefined8 ******)local_48[0];
      }
      ppppppuVar6 = &local_78;
      if (7 < local_60) {
        ppppppuVar6 = (undefined8 ******)local_78;
      }
      iVar3 = FUN_141981294(ppppppuVar6,ppppppuVar9);
      if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_14056e760("rename",iVar3,&local_78,local_48);
      }
      FUN_1402a29e0(&local_78);
      FUN_1402a29e0(local_48);
      puVar10 = param_2;
      if (0xf < (ulonglong)param_2[3]) {
        puVar10 = (undefined8 *)*param_2;
      }
      uVar11 = 0xcbf29ce484222325;
      plVar7 = plVar5;
      if ((longlong *)param_2[2] != (longlong *)0x0) {
        do {
          uVar11 = (uVar11 ^ *(byte *)((longlong)puVar10 + (longlong)plVar7)) * 0x100000001b3;
          plVar7 = (longlong *)((longlong)plVar7 + 1);
        } while (plVar7 < (longlong *)param_2[2]);
      }
      lVar4 = FUN_1402a81c0(&DAT_142b098a0,&local_78,param_2,uVar11);
      lVar2 = DAT_142b098a8;
      plVar7 = *(longlong **)(lVar4 + 8);
      if (plVar7 != (longlong *)0x0) {
        plVar8 = (longlong *)(DAT_142b098b8 + (uVar11 & _DAT_142b098d0) * 0x10);
        if ((longlong *)plVar8[1] == plVar7) {
          if ((longlong *)*plVar8 == plVar7) {
            *plVar8 = DAT_142b098a8;
            plVar8[1] = lVar2;
          }
          else {
            plVar8[1] = plVar7[1];
          }
        }
        else if ((longlong *)*plVar8 == plVar7) {
          *plVar8 = *plVar7;
        }
        lVar2 = *plVar7;
        _DAT_142b098b0 = _DAT_142b098b0 + -1;
        *(longlong *)plVar7[1] = lVar2;
        *(longlong *)(lVar2 + 8) = plVar7[1];
        FUN_1405a6470(plVar7 + 2);
        free(plVar7);
      }
      if (local_88 + 0xb != param_3) {
        plVar7 = param_3;
        if (0xf < (ulonglong)param_3[3]) {
          plVar7 = (longlong *)*param_3;
        }
        FUN_1402af360(local_88 + 0xb,plVar7,param_3[2]);
      }
      if (local_88 + 0x80 != param_3) {
        plVar7 = param_3;
        if (0xf < (ulonglong)param_3[3]) {
          plVar7 = (longlong *)*param_3;
        }
        FUN_1402af360(local_88 + 0x80,plVar7,param_3[2]);
      }
      plVar7 = (longlong *)FUN_14066c7d0(&DAT_142b098a0,&local_78,param_3);
      lVar2 = *plVar7;
      plVar7 = plVar5;
      if (local_80 != (longlong *)0x0) {
        LOCK();
        *(int *)((longlong)local_80 + 0xc) = *(int *)((longlong)local_80 + 0xc) + 1;
        UNLOCK();
        plVar5 = local_88;
        plVar7 = local_80;
      }
      *(longlong **)(lVar2 + 0x30) = plVar5;
      plVar5 = *(longlong **)(lVar2 + 0x38);
      *(longlong **)(lVar2 + 0x38) = plVar7;
      if (plVar5 != (longlong *)0x0) {
        LOCK();
        piVar1 = (int *)((longlong)plVar5 + 0xc);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          (**(code **)(*plVar5 + 8))(plVar5);
        }
      }
      *param_1 = local_88;
      param_1[1] = local_80;
      if (local_50 == '\0') {
        return param_1;
      }
      _Mtx_unlock(local_58);
      return param_1;
    }
    *param_1 = local_78;
    param_1[1] = local_70;
  }
  plVar5 = local_80;
  if (local_80 != (longlong *)0x0) {
    LOCK();
    plVar7 = local_80 + 1;
    lVar2 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + -1;
    UNLOCK();
    if ((int)lVar2 == 1) {
      (**(code **)*local_80)(local_80);
      LOCK();
      piVar1 = (int *)((longlong)plVar5 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*local_80 + 8))();
      }
    }
  }
  _Mtx_unlock(&DAT_1428e2310);
  return param_1;
}


