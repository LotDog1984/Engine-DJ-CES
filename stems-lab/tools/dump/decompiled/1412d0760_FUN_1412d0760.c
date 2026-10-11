// FUN_1412d0760 @ 1412d0760
// strings: [air.planck.stems.controller]

undefined * FUN_1412d0760(void)

{
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
              0x160) < DAT_142b28e20) {
    FUN_141982544(&DAT_142b28e20);
    if (DAT_142b28e20 == -1) {
      QLoggingCategory::QLoggingCategory
                ((QLoggingCategory *)&DAT_142b28e08,"air.planck.stems.controller",1);
      atexit((_func_5014 *)&LAB_141ab35a0);
      _Init_thread_footer(&DAT_142b28e20);
      return &DAT_142b28e08;
    }
  }
  return &DAT_142b28e08;
}


