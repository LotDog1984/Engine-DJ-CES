// FUN_140ce6b80 @ 140ce6b80
// calls: [WriteFile, ReadFile, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140ce6b80(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  undefined8 uVar4;
  longlong *plVar5;
  void *pvVar6;
  void *pvVar7;
  longlong *_Src;
  longlong *_Size;
  undefined1 local_res20;
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
  void *local_38 [3];
  ulonglong local_20;
  
  uVar4 = FUN_140cc9330(&local_a8);
  cVar3 = FUN_140cc8fb0(uVar4);
  if (0xf < uStack_90) {
    pvVar6 = (void *)CONCAT71(uStack_a7,local_a8);
    pvVar7 = pvVar6;
    if ((0xfff < uStack_90 + 1) &&
       (pvVar7 = *(void **)((longlong)pvVar6 + -8),
       0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar7);
  }
  if (cVar3 == '\0') {
    plVar5 = (longlong *)FUN_140cc9330(&local_a8);
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
    pvVar7 = (void *)*plVar5;
    uVar2 = plVar5[3];
    plVar5[2] = 0;
    plVar5[3] = 0xf;
    *(undefined1 *)plVar5 = 0;
    if (0xf < uVar2) {
      pvVar6 = pvVar7;
      if ((0xfff < uVar2 + 1) &&
         (pvVar6 = *(void **)((longlong)pvVar7 + -8),
         0x1f < (ulonglong)((longlong)pvVar7 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    if (0xf < uStack_90) {
      pvVar6 = (void *)CONCAT71(uStack_a7,local_a8);
      pvVar7 = pvVar6;
      if ((0xfff < uStack_90 + 1) &&
         (pvVar7 = *(void **)((longlong)pvVar6 + -8),
         0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar7);
    }
  }
  else {
    FUN_140302ee0(local_88,0);
    uVar4 = FUN_140ce48b0(&local_a8);
    uVar4 = FUN_140cc9520(&local_58,uVar4,300);
    FUN_140ce5550(&local_78,param_1,param_2,param_3,uVar4);
    if (0xf < uStack_40) {
      pvVar6 = (void *)CONCAT71(uStack_57,local_58);
      pvVar7 = pvVar6;
      if ((0xfff < uStack_40 + 1) &&
         (pvVar7 = *(void **)((longlong)pvVar6 + -8),
         0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar7);
    }
    local_48 = _DAT_141ac9b00;
    uStack_40 = _UNK_141ac9b08;
    local_58 = 0;
    if (0xf < uStack_90) {
      pvVar6 = (void *)CONCAT71(uStack_a7,local_a8);
      pvVar7 = pvVar6;
      if ((0xfff < uStack_90 + 1) &&
         (pvVar7 = *(void **)((longlong)pvVar6 + -8),
         0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar7);
    }
    local_98 = _DAT_141ac9b00;
    uStack_90 = _UNK_141ac9b08;
    local_a8 = 0;
    uVar4 = FUN_140ce48b0(local_38);
    FUN_140cca360(uVar4,&local_78,300);
    if (0xf < local_20) {
      pvVar7 = local_38[0];
      if ((0xfff < local_20 + 1) &&
         (pvVar7 = *(void **)((longlong)local_38[0] + -8),
         0x1f < (ulonglong)((longlong)local_38[0] + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar7);
    }
    if (0xf < uStack_60) {
      pvVar6 = (void *)CONCAT71(uStack_77,local_78);
      pvVar7 = pvVar6;
      if ((0xfff < uStack_60 + 1) &&
         (pvVar7 = *(void **)((longlong)pvVar6 + -8),
         0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar7);
    }
    local_68 = _DAT_141ac9b00;
    uStack_60 = _UNK_141ac9b08;
    local_78 = 0;
    FUN_140315ba0(local_80,local_88[0]);
  }
  return;
}


