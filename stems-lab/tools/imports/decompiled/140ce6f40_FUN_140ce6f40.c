// FUN_140ce6f40 @ 140ce6f40
// calls: [WriteFile, ReadFile, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ce6f40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
  undefined1 local_c8;
  undefined7 uStack_c7;
  undefined8 local_b8;
  ulonglong uStack_b0;
  undefined1 local_a8;
  undefined7 uStack_a7;
  undefined8 local_98;
  ulonglong uStack_90;
  undefined1 local_88 [8];
  undefined1 local_80 [8];
  undefined1 local_78;
  undefined7 uStack_77;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined1 local_58;
  undefined7 uStack_57;
  undefined8 local_48;
  ulonglong uStack_40;
  undefined1 local_38;
  undefined7 uStack_37;
  undefined8 local_28;
  ulonglong uStack_20;
  
  uVar4 = FUN_140ce49d0(&local_c8);
  cVar3 = FUN_140cc8fb0(uVar4);
  if (0xf < uStack_b0) {
    pvVar7 = (void *)CONCAT71(uStack_c7,local_c8);
    pvVar8 = pvVar7;
    if ((0xfff < uStack_b0 + 1) &&
       (pvVar8 = *(void **)((longlong)pvVar7 + -8),
       0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar8);
  }
  if (cVar3 == '\0') {
    plVar5 = (longlong *)FUN_140ce49d0(&local_c8);
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
    if (0xf < uStack_b0) {
      pvVar7 = (void *)CONCAT71(uStack_c7,local_c8);
      pvVar8 = pvVar7;
      if ((0xfff < uStack_b0 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
  }
  else {
    FUN_140302ee0(local_88,0);
    uVar4 = FUN_140ce46d0(&local_38,param_1,param_3);
    uVar6 = FUN_140ce49d0(&local_58);
    FUN_14029f4d0(&local_a8,local_res20,uVar6,uVar4);
    if (0xf < uStack_40) {
      pvVar7 = (void *)CONCAT71(uStack_57,local_58);
      pvVar8 = pvVar7;
      if ((0xfff < uStack_40 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
    local_48 = _DAT_141ac9b00;
    uStack_40 = _UNK_141ac9b08;
    local_58 = 0;
    if (0xf < uStack_20) {
      pvVar7 = (void *)CONCAT71(uStack_37,local_38);
      pvVar8 = pvVar7;
      if ((0xfff < uStack_20 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
    local_28 = _DAT_141ac9b00;
    uStack_20 = _UNK_141ac9b08;
    local_38 = 0;
    uVar4 = FUN_140cc9520(&local_c8,&local_a8,300);
    FUN_140ce5170(&local_78,param_1,param_2,param_3,uVar4);
    if (0xf < uStack_b0) {
      pvVar7 = (void *)CONCAT71(uStack_c7,local_c8);
      pvVar8 = pvVar7;
      if ((0xfff < uStack_b0 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
    local_b8 = _DAT_141ac9b00;
    uStack_b0 = _UNK_141ac9b08;
    local_c8 = 0;
    FUN_140cca360(&local_a8,&local_78,300);
    if (0xf < uStack_60) {
      pvVar7 = (void *)CONCAT71(uStack_77,local_78);
      pvVar8 = pvVar7;
      if ((0xfff < uStack_60 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
    local_68 = _DAT_141ac9b00;
    uStack_60 = _UNK_141ac9b08;
    local_78 = 0;
    if (0xf < uStack_90) {
      pvVar7 = (void *)CONCAT71(uStack_a7,local_a8);
      pvVar8 = pvVar7;
      if ((0xfff < uStack_90 + 1) &&
         (pvVar8 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar8);
    }
    local_98 = _DAT_141ac9b00;
    uStack_90 = _UNK_141ac9b08;
    local_a8 = 0;
    FUN_140315ba0(local_80,local_88[0]);
  }
  return;
}


