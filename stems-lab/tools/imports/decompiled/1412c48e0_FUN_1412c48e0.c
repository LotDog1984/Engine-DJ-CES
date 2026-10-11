// FUN_1412c48e0 @ 1412c48e0
// calls: [WriteFile]

void FUN_1412c48e0(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  *(undefined ***)param_1 = boost::process::basic_pipebuf<char,std::char_traits<char>_>::vftable;
  if ((*(longlong *)(param_1 + 0x68) != -1) || (*(longlong *)(param_1 + 0x70) != -1)) {
    FUN_1412c5cf0();
  }
  pvVar1 = *(void **)(param_1 + 0x90);
  if (pvVar1 != (void *)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0xa0) - (longlong)pvVar1)) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) goto LAB_1412c49e0;
    free(pvVar2);
    *(undefined8 *)(param_1 + 0x90) = 0;
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  pvVar1 = *(void **)(param_1 + 0x78);
  if (pvVar1 != (void *)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (ulonglong)(*(longlong *)(param_1 + 0x88) - (longlong)pvVar1)) &&
       (pvVar2 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar2)))) {
LAB_1412c49e0:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar2);
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x88) = 0;
  }
  if (*(HANDLE *)(param_1 + 0x70) != (HANDLE)0xffffffffffffffff) {
    CloseHandle(*(HANDLE *)(param_1 + 0x70));
  }
  if (*(HANDLE *)(param_1 + 0x68) != (HANDLE)0xffffffffffffffff) {
    CloseHandle(*(HANDLE *)(param_1 + 0x68));
  }
                    /* WARNING: Could not recover jumptable at 0x0001412c49d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            (param_1);
  return;
}


