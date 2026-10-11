// FUN_1412d06d0 @ 1412d06d0
// strings: [air.planck.stems]

undefined * FUN_1412d06d0(void)

{
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
              0x160) < DAT_142b28e00) {
    FUN_141982544(&DAT_142b28e00);
    if (DAT_142b28e00 == -1) {
      QLoggingCategory::QLoggingCategory((QLoggingCategory *)&DAT_142b28de8,"air.planck.stems",1);
      atexit((_func_5014 *)&LAB_141ab3590);
      _Init_thread_footer(&DAT_142b28e00);
      return &DAT_142b28de8;
    }
  }
  return &DAT_142b28de8;
}


