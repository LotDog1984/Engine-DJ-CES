// FUN_1412f8ed0 @ 1412f8ed0
// calls: [CreateFileW]

bool FUN_1412f8ed0(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 local_118 [272];
  
  if (*(longlong *)(param_1 + 0x10) != -1) {
    lVar2 = FUN_1412fa530(local_118,
                          "bool __cdecl crashpad::FileReader::Open(const class base::FilePath &)",
                          "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\util\\file\\file_reader.cc"
                          ,0x57,4);
    uVar1 = FUN_1402b8060(lVar2 + 8,"Check failed: !file_.is_valid()");
    FUN_1402b8060(uVar1,&DAT_1423b9148);
    FUN_1412fa7a0(local_118);
  }
  lVar2 = FUN_1412f5ca0(param_2);
  if (*(longlong *)(param_1 + 0x10) != -1) {
    if (*(longlong *)(param_1 + 0x10) == lVar2) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    thunk_FUN_1412f5560();
  }
  *(longlong *)(param_1 + 0x10) = lVar2;
  if (lVar2 != -1) {
    *(longlong *)(param_1 + 0x28) = lVar2;
  }
  return lVar2 != -1;
}


