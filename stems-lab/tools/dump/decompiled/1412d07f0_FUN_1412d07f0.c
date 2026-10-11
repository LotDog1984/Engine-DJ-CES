// FUN_1412d07f0 @ 1412d07f0
// strings: [air.planck.stems.download]

undefined * FUN_1412d07f0(void)

{
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
              0x160) < DAT_142b28e60) {
    FUN_141982544(&DAT_142b28e60);
    if (DAT_142b28e60 == -1) {
      QLoggingCategory::QLoggingCategory
                ((QLoggingCategory *)&DAT_142b28e48,"air.planck.stems.download",1);
      atexit((_func_5014 *)&LAB_141ab35b0);
      _Init_thread_footer(&DAT_142b28e60);
      return &DAT_142b28e48;
    }
  }
  return &DAT_142b28e48;
}


