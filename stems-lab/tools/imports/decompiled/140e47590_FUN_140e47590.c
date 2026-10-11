// FUN_140e47590 @ 140e47590
// calls: [CreateFileW]

/* WARNING: Type propagation algorithm not settling */

undefined8 * FUN_140e47590(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  basic_ostream<char,std::char_traits<char>_> *this;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar5;
  char *pcVar6;
  char *******pppppppcVar7;
  uint *puVar8;
  undefined8 *******pppppppuVar9;
  longlong lVar10;
  int iVar11;
  undefined1 local_res20 [8];
  char *******local_330;
  longlong lStack_328;
  undefined8 local_320;
  ulonglong local_318;
  undefined8 *******local_310;
  undefined8 uStack_308;
  longlong local_300;
  ulonglong local_2f8;
  longlong local_2f0;
  undefined1 local_2e8;
  int iStack_2dc;
  undefined *local_2d8 [3];
  undefined **local_2c0;
  basic_iostream<char,std::char_traits<char>_> local_2b8 [96];
  char *local_258;
  uint local_250;
  basic_ios<char,std::char_traits<char>_> local_240 [112];
  undefined1 local_1d0 [32];
  undefined1 local_1b0 [376];
  
  iVar11 = 0;
  local_2f0 = param_1 + 0x68;
  local_2e8 = 0;
  iVar2 = _Mtx_lock(local_2f0);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    std::_Throw_Cpp_error(5);
  }
  if (*(int *)(param_1 + 0xb4) != 0x7fffffff) {
    local_2e8 = 1;
    FUN_1419750e0(local_1d0,0);
    while( true ) {
      if (0x7ffffffe < iVar11) {
        *param_2 = 0;
        param_2[1] = 0;
        param_2[2] = 0;
        param_2[3] = 0xf;
        *(undefined1 *)param_2 = 0;
        FUN_1402a29e0(local_1d0);
        _Mtx_unlock(local_2f0);
        return param_2;
      }
      local_2d8[0] = &DAT_141d2ac58;
      local_2d8[2] = &DAT_141d2ac60;
      std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
                (local_240);
      std::basic_iostream<char,std::char_traits<char>_>::
      basic_iostream<char,std::char_traits<char>_>
                ((basic_iostream<char,std::char_traits<char>_> *)local_2d8,
                 (basic_streambuf<char,std::char_traits<char>_> *)&local_2c0);
      *(undefined ***)((longlong)local_2d8 + (longlong)*(int *)(local_2d8[0] + 4)) =
           std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
      *(int *)((longlong)&iStack_2dc + (longlong)*(int *)(local_2d8[0] + 4)) =
           *(int *)(local_2d8[0] + 4) + -0x98;
      std::basic_streambuf<char,std::char_traits<char>_>::
      basic_streambuf<char,std::char_traits<char>_>
                ((basic_streambuf<char,std::char_traits<char>_> *)&local_2c0);
      local_2c0 = std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vftable;
      local_258 = (char *)0x0;
      local_250 = 0;
      puVar3 = (undefined8 *)FUN_14196fa80(local_1d0,local_1b0);
      lStack_328 = 0;
      local_320 = 0;
      local_318 = 0xf;
      local_330 = (char *******)0x0;
      lVar10 = puVar3[2];
      if (lVar10 != 0) {
        if (7 < (ulonglong)puVar3[3]) {
          puVar3 = (undefined8 *)*puVar3;
        }
        uVar4 = FUN_14196e970();
        FUN_141971350(puVar3,(longlong)puVar3 + lVar10 * 2,&local_330,uVar4);
      }
      FUN_1402a29e0(local_1b0);
      pppppppcVar7 = (char *******)&local_330;
      if (0xf < local_318) {
        pppppppcVar7 = local_330;
      }
      this = (basic_ostream<char,std::char_traits<char>_> *)
             FUN_1402b8440(local_2d8 + 2,pppppppcVar7,local_320);
      pbVar5 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(this,iVar11);
      FUN_1402b8060(pbVar5,&DAT_142034bf0);
      if (0xf < local_318) {
        pppppppcVar7 = local_330;
        if ((0xfff < local_318 + 1) &&
           (pppppppcVar7 = (char *******)local_330[-1],
           0x1f < (ulonglong)((longlong)local_330 + (-8 - (longlong)pppppppcVar7)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pppppppcVar7);
      }
      uStack_308 = 0;
      local_300 = 0;
      local_2f8 = 0xf;
      local_310 = (undefined8 *******)0x0;
      local_330 = (char *******)0x0;
      lStack_328 = 0;
      local_320 = 0;
      if ((((byte)local_250 & 0x22) == 2) ||
         (pcVar6 = std::basic_streambuf<char,std::char_traits<char>_>::pptr
                             ((basic_streambuf<char,std::char_traits<char>_> *)&local_2c0),
         pcVar6 == (char *)0x0)) {
        pppppppcVar7 = local_330;
        lVar10 = lStack_328;
        if (((local_250 & 4) == 0) &&
           (pcVar6 = std::basic_streambuf<char,std::char_traits<char>_>::gptr
                               ((basic_streambuf<char,std::char_traits<char>_> *)&local_2c0),
           pppppppcVar7 = local_330, lVar10 = lStack_328, pcVar6 != (char *)0x0)) {
          pppppppcVar7 = (char *******)
                         std::basic_streambuf<char,std::char_traits<char>_>::eback
                                   ((basic_streambuf<char,std::char_traits<char>_> *)&local_2c0);
          pcVar6 = std::basic_streambuf<char,std::char_traits<char>_>::egptr
                             ((basic_streambuf<char,std::char_traits<char>_> *)&local_2c0);
          lVar10 = (longlong)pcVar6 - (longlong)pppppppcVar7;
        }
      }
      else {
        pppppppcVar7 = (char *******)
                       std::basic_streambuf<char,std::char_traits<char>_>::pbase
                                 ((basic_streambuf<char,std::char_traits<char>_> *)&local_2c0);
        pcVar6 = std::basic_streambuf<char,std::char_traits<char>_>::pptr
                           ((basic_streambuf<char,std::char_traits<char>_> *)&local_2c0);
        if (pcVar6 < local_258) {
          pcVar6 = local_258;
        }
        std::basic_streambuf<char,std::char_traits<char>_>::epptr
                  ((basic_streambuf<char,std::char_traits<char>_> *)&local_2c0);
        lVar10 = (longlong)pcVar6 - (longlong)pppppppcVar7;
      }
      if (pppppppcVar7 != (char *******)0x0) {
        FUN_1402af360(&local_310,pppppppcVar7,lVar10);
      }
      lStack_328 = 0;
      local_320 = 0;
      local_318 = 7;
      local_330 = (char *******)0x0;
      if (local_300 != 0) {
        pppppppuVar9 = &local_310;
        if (0xf < local_2f8) {
          pppppppuVar9 = local_310;
        }
        lVar10 = (longlong)pppppppuVar9 + local_300;
        pppppppuVar9 = &local_310;
        if (0xf < local_2f8) {
          pppppppuVar9 = local_310;
        }
        uVar4 = FUN_14196e970();
        FUN_141971270(pppppppuVar9,lVar10,&local_330,uVar4);
      }
      puVar8 = (uint *)FUN_141974de0(local_res20,&local_330,0);
      uVar1 = *puVar8;
      if (7 < local_318) {
        pppppppcVar7 = local_330;
        if ((0xfff < local_318 * 2 + 2) &&
           (pppppppcVar7 = (char *******)local_330[-1],
           0x1f < (ulonglong)((longlong)local_330 + (-8 - (longlong)pppppppcVar7)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pppppppcVar7);
      }
      if (uVar1 < 2) break;
      iVar11 = iVar11 + 1;
      if (0xf < local_2f8) {
        pppppppuVar9 = local_310;
        if ((0xfff < local_2f8 + 1) &&
           (pppppppuVar9 = (undefined8 *******)local_310[-1],
           0x1f < (ulonglong)((longlong)local_310 + (-8 - (longlong)pppppppuVar9)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pppppppuVar9);
      }
      local_300 = 0;
      local_2f8 = 0xf;
      local_310 = (undefined8 *******)((ulonglong)local_310 & 0xffffffffffffff00);
      *(undefined ***)((longlong)local_2d8 + (longlong)*(int *)(local_2d8[0] + 4)) =
           std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
      *(int *)((longlong)&iStack_2dc + (longlong)*(int *)(local_2d8[0] + 4)) =
           *(int *)(local_2d8[0] + 4) + -0x98;
      FUN_1402b8850(&local_2c0);
      std::basic_iostream<char,std::char_traits<char>_>::
      ~basic_iostream<char,std::char_traits<char>_>(local_2b8);
      std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                (local_240);
    }
    FUN_1402aa5d0(param_2,&local_310);
    if (0xf < local_2f8) {
      pppppppuVar9 = local_310;
      if ((0xfff < local_2f8 + 1) &&
         (pppppppuVar9 = (undefined8 *******)local_310[-1],
         0x1f < (ulonglong)((longlong)local_310 + (-8 - (longlong)pppppppuVar9)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppuVar9);
    }
    local_300 = 0;
    local_2f8 = 0xf;
    local_310 = (undefined8 *******)((ulonglong)local_310 & 0xffffffffffffff00);
    *(undefined ***)((longlong)local_2d8 + (longlong)*(int *)(local_2d8[0] + 4)) =
         std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
    *(int *)((longlong)&iStack_2dc + (longlong)*(int *)(local_2d8[0] + 4)) =
         *(int *)(local_2d8[0] + 4) + -0x98;
    FUN_1402b8850(&local_2c0);
    std::basic_iostream<char,std::char_traits<char>_>::~basic_iostream<char,std::char_traits<char>_>
              (local_2b8);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
              (local_240);
    FUN_1402a29e0(local_1d0);
    _Mtx_unlock(local_2f0);
    return param_2;
  }
  *(undefined4 *)(param_1 + 0xb4) = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
  std::_Throw_Cpp_error(6);
}


