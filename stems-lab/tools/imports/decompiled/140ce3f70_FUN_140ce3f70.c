// FUN_140ce3f70 @ 140ce3f70
// calls: [ReadFile, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140ce3f70(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  undefined8 uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  void *pvVar7;
  void *pvVar8;
  longlong *_Src;
  longlong *_Size;
  undefined1 local_res20;
  undefined1 local_b8;
  undefined7 uStack_b7;
  undefined8 local_a8;
  ulonglong uStack_a0;
  undefined1 local_90;
  undefined7 uStack_8f;
  longlong local_80;
  ulonglong local_78;
  undefined1 local_70;
  undefined7 uStack_6f;
  undefined8 local_60;
  ulonglong uStack_58;
  void *local_50 [3];
  ulonglong local_38;
  
  uVar4 = FUN_140ce49d0(&local_b8);
  cVar3 = FUN_140cc8fb0(uVar4);
  if (0xf < uStack_a0) {
    pvVar7 = (void *)CONCAT71(uStack_b7,local_b8);
    pvVar8 = pvVar7;
    if ((0xfff < uStack_a0 + 1) &&
       (pvVar8 = *(void **)((longlong)pvVar7 + -8),
       0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar8);
  }
  if (cVar3 == '\0') {
    plVar5 = (longlong *)FUN_140ce49d0();
    lVar1 = plVar5[2];
    if ((ulonglong)(plVar5[3] - lVar1) < 0x1a) {
      plVar5 = (longlong *)
               FUN_1402bb550(plVar5,0x1a,local_res20,0,"Error creating directory: ",0x1a);
    }
    else {
      plVar5[2] = lVar1 + 0x1a;
      _Src = plVar5;
      if (0xf < (ulonglong)plVar5[3]) {
        _Src = (longlong *)*plVar5;
      }
      if (((longlong *)0x141fce779 < _Src) ||
         ((char *)((longlong)_Src + lVar1) < "Error creating directory: ")) {
        _Size = (longlong *)0x1a;
      }
      else if ("Error creating directory: " < _Src) {
        _Size = _Src + -0x283f9cec;
      }
      else {
        _Size = (longlong *)0x0;
      }
      memmove((undefined1 *)((longlong)_Src + 0x1a),_Src,lVar1 + 1);
      memcpy(_Src,"Error creating directory: ",(size_t)_Size);
      memcpy((undefined1 *)((longlong)_Src + (longlong)_Size),
             (undefined1 *)((longlong)_Size + 0x141fce77a),0x1a - (longlong)_Size);
    }
    pvVar8 = (void *)*plVar5;
    uVar2 = plVar5[3];
    plVar5[2] = 0;
    plVar5[3] = 0xf;
    *(undefined1 *)plVar5 = 0;
    if (0xf < uVar2) {
      pvVar7 = pvVar8;
      if ((0xfff < uVar2 + 1) &&
         (pvVar7 = *(void **)((longlong)pvVar8 + -8),
         0x1f < (ulonglong)((longlong)pvVar8 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar7);
    }
    if (0xf < uStack_a0) {
      pvVar7 = (void *)CONCAT71(uStack_b7,local_b8);
      pvVar8 = pvVar7;
      if ((0xfff < uStack_a0 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
    FUN_140302ee0(param_1,0);
  }
  else {
    uVar4 = FUN_140ce46d0(&local_b8,param_2,param_3);
    uVar6 = FUN_140ce49d0(&local_70);
    FUN_14029f4d0(local_50,local_res20,uVar6,uVar4);
    if (0xf < uStack_58) {
      pvVar7 = (void *)CONCAT71(uStack_6f,local_70);
      pvVar8 = pvVar7;
      if ((0xfff < uStack_58 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
    local_60 = _DAT_141ac9b00;
    uStack_58 = _UNK_141ac9b08;
    local_70 = 0;
    if (0xf < uStack_a0) {
      pvVar7 = (void *)CONCAT71(uStack_b7,local_b8);
      pvVar8 = pvVar7;
      if ((0xfff < uStack_a0 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
    local_a8 = _DAT_141ac9b00;
    uStack_a0 = _UNK_141ac9b08;
    local_b8 = 0;
    FUN_140cc9520(&local_90,local_50,300);
    if (local_80 == 0) {
      FUN_140302ee0(param_1,0);
    }
    else {
      uVar4 = FUN_140ce5940(&local_b8,&local_90,1);
      FUN_140cc4a00(param_1,uVar4);
      if (0xf < uStack_a0) {
        pvVar7 = (void *)CONCAT71(uStack_b7,local_b8);
        pvVar8 = pvVar7;
        if ((0xfff < uStack_a0 + 1) &&
           (pvVar8 = *(void **)((longlong)pvVar7 + -8),
           0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar8);
      }
    }
    if (0xf < local_78) {
      pvVar7 = (void *)CONCAT71(uStack_8f,local_90);
      pvVar8 = pvVar7;
      if ((0xfff < local_78 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
    local_80 = 0;
    local_78 = 0xf;
    local_90 = 0;
    if (0xf < local_38) {
      pvVar8 = local_50[0];
      if ((0xfff < local_38 + 1) &&
         (pvVar8 = *(void **)((longlong)local_50[0] + -8),
         0x1f < (ulonglong)((longlong)local_50[0] + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
  }
  return param_1;
}


