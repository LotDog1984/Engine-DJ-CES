// FUN_1412f69e0 @ 1412f69e0
// calls: [CreateFileW]

bool FUN_1412f69e0(longlong param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 local_128 [272];
  
  if (*(longlong *)(param_1 + 0x10) != -1) {
    lVar2 = FUN_1412fa530(local_128,
                          "bool __cdecl crashpad::FileWriter::Open(const class base::FilePath &,enum crashpad::FileWriteMode,enum crashpad::FilePermissions)"
                          ,
                          "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\util\\file\\file_writer.cc"
                          ,0xa5,4);
    uVar1 = FUN_1402b8060(lVar2 + 8,"Check failed: !file_.is_valid()");
    FUN_1402b8060(uVar1,&DAT_1423b9148);
    FUN_1412fa7a0(local_128);
  }
  lVar2 = FUN_1412f5ff0(param_2,param_3,param_4);
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


