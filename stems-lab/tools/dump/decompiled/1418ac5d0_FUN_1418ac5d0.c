// FUN_1418ac5d0 @ 1418ac5d0
// strings: [.stems]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1418ac5d0(longlong param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined8 *****pppppuVar6;
  void *_Memory;
  short *psVar7;
  undefined8 ****local_88;
  longlong lStack_80;
  void *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined8 ****local_58 [2];
  undefined8 local_48;
  ulonglong local_40;
  undefined8 ****local_38 [2];
  longlong local_28;
  ulonglong local_20;
  
  if (*(longlong **)(param_1 + 0x40) == (longlong *)0x0) {
    local_88 = (undefined8 ****)&DAT_141cafc56;
  }
  else {
    local_88 = (undefined8 ****)(**(code **)(**(longlong **)(param_1 + 0x40) + 8))();
  }
  lStack_80 = -1;
  do {
    lStack_80 = lStack_80 + 1;
  } while (*(char *)((longlong)local_88 + lStack_80) != '\0');
  FUN_14029eae0(local_38,&local_88,0);
  local_88 = (undefined8 ****)0x141d2eee0;
  lStack_80 = 6;
  FUN_14029eae0(local_58,&local_88,0);
  pppppuVar6 = local_38;
  if (7 < local_20) {
    pppppuVar6 = (undefined8 *****)local_38[0];
  }
  psVar5 = (short *)((longlong)pppppuVar6 + local_28 * 2);
  psVar4 = (short *)FUN_1402a62c0(pppppuVar6,psVar5);
  psVar7 = psVar5;
  if (psVar4 != psVar5) {
    do {
      psVar2 = psVar5;
      if ((*psVar4 != 0x5c) && (*psVar4 != 0x2f)) break;
      psVar4 = psVar4 + 1;
    } while (psVar4 != psVar5);
    do {
      psVar7 = psVar2;
      if (psVar4 == psVar7) break;
      sVar1 = psVar7[-1];
      if ((sVar1 == 0x5c) || (psVar2 = psVar7 + -1, sVar1 == 0x2f)) break;
    } while( true );
  }
  psVar5 = (short *)FUN_141981550(psVar7,psVar5,0x3a);
  if ((psVar7 != psVar5) && (psVar4 = psVar5 + -1, psVar7 != psVar4)) {
    if (*psVar4 == 0x2e) {
      if ((psVar7 != psVar5 + -2) || (psVar5[-2] != 0x2e)) goto LAB_1418ac722;
    }
    else {
      for (psVar4 = psVar5 + -2; psVar7 != psVar4; psVar4 = psVar4 + -1) {
        if (*psVar4 == 0x2e) goto LAB_1418ac722;
      }
    }
  }
  psVar4 = psVar5;
LAB_1418ac722:
  local_78 = (void *)0x0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  FUN_1402a7200(&local_78,psVar4,(longlong)psVar5 - (longlong)psVar4 >> 1);
  local_88 = local_58;
  if (7 < local_40) {
    local_88 = local_58[0];
  }
  lStack_80 = local_48;
  iVar3 = FUN_1404b4e10(&local_78,&local_88);
  *(bool *)(param_1 + 0x120) = iVar3 == 0;
  if (7 < uStack_60) {
    _Memory = local_78;
    if ((0xfff < uStack_60 * 2 + 2) &&
       (_Memory = *(void **)((longlong)local_78 + -8),
       0x1f < (ulonglong)((longlong)local_78 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  local_68 = _DAT_141cb0070;
  uStack_60 = _UNK_141cb0078;
  local_78 = (void *)((ulonglong)local_78 & 0xffffffffffff0000);
  FUN_1402a29e0(local_58);
  FUN_1402a29e0(local_38);
  return;
}


