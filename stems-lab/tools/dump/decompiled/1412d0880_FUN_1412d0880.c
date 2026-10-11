// FUN_1412d0880 @ 1412d0880
// strings: [air.planck.stems.render]

undefined * FUN_1412d0880(void)

{
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
              0x160) < DAT_142b28e40) {
    FUN_141982544(&DAT_142b28e40);
    if (DAT_142b28e40 == -1) {
      QLoggingCategory::QLoggingCategory
                ((QLoggingCategory *)&DAT_142b28e28,"air.planck.stems.render",1);
      atexit((_func_5014 *)&LAB_141ab35c0);
      _Init_thread_footer(&DAT_142b28e40);
      return &DAT_142b28e28;
    }
  }
  return &DAT_142b28e28;
}


