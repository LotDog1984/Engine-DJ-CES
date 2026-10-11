// FUN_140cd41a0 @ 140cd41a0
// calls: [WriteFile, ReadFile, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_140cd41a0(undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined1 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  undefined8 uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong ******pppppplVar7;
  void *pvVar8;
  void *pvVar9;
  longlong *******ppppppplVar10;
  longlong *******ppppppplVar11;
  longlong *_Src;
  ulonglong uVar12;
  undefined1 local_res8;
  undefined8 local_res18;
  undefined1 local_res20 [8];
  longlong ******local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  ulonglong uStack_d0;
  undefined1 local_c8;
  undefined7 uStack_c7;
  undefined8 local_b8;
  ulonglong uStack_b0;
  undefined8 *local_a0;
  undefined8 *puStack_98;
  undefined1 *local_90;
  longlong ******pppppplStack_88;
  undefined **local_80;
  undefined8 *local_78;
  undefined8 *puStack_70;
  undefined1 *local_68;
  longlong ******pppppplStack_60;
  undefined ***local_48;
  
  ppppppplVar11 = (longlong *******)0x0;
  if (param_1[0x15] == 0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0xf;
    *(undefined1 *)param_2 = 0;
    return param_2;
  }
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0xf;
  local_e8 = (longlong ******)0x0;
  local_res18 = param_3;
  local_res20[0] = param_4;
  uVar4 = FUN_140cc9330(&local_c8);
  cVar3 = FUN_140cc8fb0(uVar4);
  if (0xf < uStack_b0) {
    pvVar8 = (void *)CONCAT71(uStack_c7,local_c8);
    pvVar9 = pvVar8;
    if ((0xfff < uStack_b0 + 1) &&
       (pvVar9 = *(void **)((longlong)pvVar8 + -8),
       0x1f < (ulonglong)((longlong)pvVar8 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar9);
  }
  if (cVar3 != '\0') {
    puStack_98 = &local_res18;
    local_90 = local_res20;
    pppppplStack_88 = (longlong ******)&local_e8;
    local_80 = std::
               _Func_impl_no_alloc<`private:_class_std::basic_string<char,std::char_traits<char>,std::allocator<char>_>___cdecl_inmusic::software_unlock::internal::WebApiImplTokenProvider::refreshAccessTokenIfNeeded(inmusic::software_unlock::internal::otel::Span*___ptr64,bool)___ptr64'::`2'::<lambda_1>,std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>,std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>_const&___ptr64>
               ::vftable;
    local_48 = &local_80;
    local_a0 = param_1;
    local_78 = param_1;
    puStack_70 = puStack_98;
    local_68 = local_90;
    pppppplStack_60 = pppppplStack_88;
    uVar4 = FUN_140ce2730(&local_c8,*param_1);
    FUN_140ccaeb0(uVar4,&local_80,300);
    if (0xf < uStack_b0) {
      pvVar8 = (void *)CONCAT71(uStack_c7,local_c8);
      pvVar9 = pvVar8;
      if ((0xfff < uStack_b0 + 1) &&
         (pvVar9 = *(void **)((longlong)pvVar8 + -8),
         0x1f < (ulonglong)((longlong)pvVar8 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar9);
    }
    local_b8 = _DAT_141ac9b00;
    uStack_b0 = _UNK_141ac9b08;
    local_c8 = 0;
    if (local_48 != (undefined ***)0x0) {
      (*(code *)(*local_48)[4])
                (local_48,CONCAT71((int7)((ulonglong)&local_80 >> 8),local_48 != &local_80));
    }
    LOCK();
    *(bool *)(param_1 + 0x16) = param_1[0x15] != 0;
    UNLOCK();
    ppppppplVar11 = (longlong *******)local_e8;
    goto LAB_140cd45e3;
  }
  plVar5 = (longlong *)FUN_140cc9330(&local_c8);
  lVar1 = plVar5[2];
  if ((ulonglong)(plVar5[3] - lVar1) < 0x1a) {
    plVar5 = (longlong *)FUN_1402bb550(plVar5,0x1a,local_res8,0,"Error creating directory: ",0x1a);
  }
  else {
    plVar5[2] = lVar1 + 0x1a;
    _Src = plVar5;
    if (0xf < (ulonglong)plVar5[3]) {
      _Src = (longlong *)*plVar5;
    }
    if (((longlong *)0x141fce779 < _Src) ||
       ((char *)((longlong)_Src + lVar1) < "Error creating directory: ")) {
      ppppppplVar10 = (longlong *******)0x1a;
    }
    else {
      ppppppplVar10 = ppppppplVar11;
      if ("Error creating directory: " < _Src) {
        ppppppplVar10 = (longlong *******)(_Src + -0x283f9cec);
      }
    }
    memmove((undefined1 *)((longlong)_Src + 0x1a),_Src,lVar1 + 1);
    memcpy(_Src,"Error creating directory: ",(size_t)ppppppplVar10);
    memcpy((undefined1 *)((longlong)_Src + (longlong)ppppppplVar10),
           (undefined1 *)((longlong)ppppppplVar10 + 0x141fce77a),0x1a - (longlong)ppppppplVar10);
  }
  pvVar9 = (void *)*plVar5;
  uVar2 = plVar5[3];
  plVar5[2] = 0;
  plVar5[3] = 0xf;
  *(undefined1 *)plVar5 = 0;
  if (0xf < uVar2) {
    pvVar8 = pvVar9;
    if ((0xfff < uVar2 + 1) &&
       (pvVar8 = *(void **)((longlong)pvVar9 + -8),
       0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar8)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar8);
  }
  if (0xf < uStack_b0) {
    pvVar8 = (void *)CONCAT71(uStack_c7,local_c8);
    pvVar9 = pvVar8;
    if ((0xfff < uStack_b0 + 1) &&
       (pvVar9 = *(void **)((longlong)pvVar8 + -8),
       0x1f < (ulonglong)((longlong)pvVar8 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar9);
  }
  uVar2 = uStack_d0;
  if (0x1b < uStack_d0) {
    ppppppplVar11 = &local_e8;
    if (0xf < uStack_d0) {
      ppppppplVar11 = (longlong *******)local_e8;
    }
    local_d8 = 0x1c;
    memmove(ppppppplVar11,"Internal error: e012ab53fe0a",0x1c);
    *(undefined1 *)((longlong)ppppppplVar11 + 0x1c) = 0;
    ppppppplVar11 = (longlong *******)local_e8;
    goto LAB_140cd45e3;
  }
  uVar12 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff - (uStack_d0 >> 1) < uStack_d0) {
    uVar6 = 0x8000000000000027;
LAB_140cd4437:
    pppppplVar7 = (longlong ******)FUN_141981f80(uVar6);
    if (pppppplVar7 == (longlong ******)0x0) goto LAB_140cd44f4;
    ppppppplVar11 = (longlong *******)((longlong)pppppplVar7 + 0x27U & 0xffffffffffffffe0);
    ppppppplVar11[-1] = pppppplVar7;
  }
  else {
    uVar6 = (uStack_d0 >> 1) + uStack_d0;
    uVar12 = 0x1f;
    if (0x1f < uVar6) {
      uVar12 = uVar6;
    }
    if (uVar12 != 0xffffffffffffffff) {
      if (0xfff < uVar12 + 1) {
        uVar6 = uVar12 + 0x28;
        if (uVar6 <= uVar12 + 1) {
                    /* WARNING: Subroutine does not return */
          FUN_14029d880();
        }
        goto LAB_140cd4437;
      }
      ppppppplVar11 = (longlong *******)FUN_141981f80();
    }
  }
  uVar4 = s_Internal_error__e012ab53fe0a_141fced08._8_8_;
  local_d8 = 0x1c;
  *ppppppplVar11 = (longlong ******)s_Internal_error__e012ab53fe0a_141fced08._0_8_;
  ppppppplVar11[1] = (longlong ******)uVar4;
  ppppppplVar11[2] = (longlong ******)s_Internal_error__e012ab53fe0a_141fced08._16_8_;
  *(undefined4 *)(ppppppplVar11 + 3) = s_Internal_error__e012ab53fe0a_141fced08._24_4_;
  *(undefined1 *)((longlong)ppppppplVar11 + 0x1c) = 0;
  uStack_d0 = uVar12;
  if (0xf < uVar2) {
    ppppppplVar10 = (longlong *******)local_e8;
    if ((0xfff < uVar2 + 1) &&
       (ppppppplVar10 = (longlong *******)local_e8[-1],
       (undefined1 *)0x1f < (undefined1 *)((longlong)local_e8 + (-8 - (longlong)ppppppplVar10)))) {
LAB_140cd44f4:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppppplVar10);
  }
LAB_140cd45e3:
  local_e8 = (longlong ******)ppppppplVar11;
  *param_2 = local_e8;
  param_2[1] = uStack_e0;
  param_2[2] = local_d8;
  param_2[3] = uStack_d0;
  return param_2;
}


