// FUN_140ce4380 @ 140ce4380
// calls: [ReadFile, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140ce4380(undefined8 param_1)

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
  undefined1 local_res10;
  undefined1 local_80;
  undefined7 uStack_7f;
  undefined8 local_70;
  ulonglong uStack_68;
  void *local_60 [2];
  longlong local_50;
  ulonglong local_48;
  void *local_40 [3];
  ulonglong local_28;
  
  uVar4 = FUN_140cc9330(&local_80);
  cVar3 = FUN_140cc8fb0(uVar4);
  if (0xf < uStack_68) {
    pvVar6 = (void *)CONCAT71(uStack_7f,local_80);
    pvVar7 = pvVar6;
    if ((0xfff < uStack_68 + 1) &&
       (pvVar7 = *(void **)((longlong)pvVar6 + -8),
       0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar7);
  }
  if (cVar3 == '\0') {
    plVar5 = (longlong *)FUN_140cc9330();
    lVar1 = plVar5[2];
    if ((ulonglong)(plVar5[3] - lVar1) < 0x1a) {
      plVar5 = (longlong *)
               FUN_1402bb550(plVar5,0x1a,local_res10,0,"Error creating directory: ",0x1a);
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
    if (0xf < uStack_68) {
      pvVar6 = (void *)CONCAT71(uStack_7f,local_80);
      pvVar7 = pvVar6;
      if ((0xfff < uStack_68 + 1) &&
         (pvVar7 = *(void **)((longlong)pvVar6 + -8),
         0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar7);
    }
    FUN_140302ee0(param_1,0);
  }
  else {
    uVar4 = FUN_140ce48b0(&local_80);
    FUN_140cc9520(local_60,uVar4,300);
    if (0xf < uStack_68) {
      pvVar6 = (void *)CONCAT71(uStack_7f,local_80);
      pvVar7 = pvVar6;
      if ((0xfff < uStack_68 + 1) &&
         (pvVar7 = *(void **)((longlong)pvVar6 + -8),
         0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar7);
    }
    local_70 = _DAT_141ac9b00;
    uStack_68 = _UNK_141ac9b08;
    local_80 = 0;
    if (local_50 == 0) {
      FUN_140302ee0(param_1,0);
    }
    else {
      uVar4 = FUN_140ce5940(local_40,local_60,1);
      FUN_140cc4a00(param_1,uVar4);
      if (0xf < local_28) {
        pvVar7 = local_40[0];
        if ((0xfff < local_28 + 1) &&
           (pvVar7 = *(void **)((longlong)local_40[0] + -8),
           0x1f < (ulonglong)((longlong)local_40[0] + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar7);
      }
    }
    if (0xf < local_48) {
      pvVar7 = local_60[0];
      if ((0xfff < local_48 + 1) &&
         (pvVar7 = *(void **)((longlong)local_60[0] + -8),
         0x1f < (ulonglong)((longlong)local_60[0] + (-8 - (longlong)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar7);
    }
  }
  return param_1;
}


