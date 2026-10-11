// FUN_1412f5620 @ 1412f5620
// calls: [WriteFile]

ulonglong FUN_1412f5620(undefined8 param_1,longlong param_2,longlong param_3)

{
  bool bVar1;
  DWORD DVar2;
  undefined **ppuVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined **local_128;
  undefined8 local_120;
  undefined1 local_118 [272];
  
  ppuVar3 = crashpad::_anon_B27302F9::FileIOWriteAll::vftable;
  local_128 = crashpad::_anon_B27302F9::FileIOWriteAll::vftable;
  local_120 = param_1;
  do {
    if (param_3 == 0) {
      uVar5 = CONCAT71((int7)((ulonglong)ppuVar3 >> 8),1);
      bVar1 = true;
LAB_1412f569b:
      if (bVar1) {
        uVar5 = CONCAT71((int7)(uVar5 >> 8),1);
      }
      else {
        DVar2 = GetLastError();
        lVar4 = FUN_1412fa700(local_118,
                              "bool __cdecl crashpad::LoggingWriteFile(void *,const void *,unsigned __int64)"
                              ,
                              "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\util\\file\\file_io.cc"
                              ,0x8c,2,DVar2);
        FUN_1402b8060(lVar4 + 8,"WriteFile");
        uVar5 = FUN_1412fa820(local_118);
        uVar5 = uVar5 & 0xffffffffffffff00;
      }
      return uVar5;
    }
    if ((code *)*local_128 == FUN_1412f5980) {
      ppuVar3 = (undefined **)FUN_1412f6430(local_120);
    }
    else {
      ppuVar3 = (undefined **)(*(code *)*local_128)(&local_128,param_2,param_3);
    }
    if ((longlong)ppuVar3 < 0) {
      uVar5 = (ulonglong)ppuVar3 & 0xffffffffffffff00;
      bVar1 = false;
      goto LAB_1412f569b;
    }
    param_2 = param_2 + (longlong)ppuVar3;
    param_3 = param_3 - (longlong)ppuVar3;
  } while( true );
}


