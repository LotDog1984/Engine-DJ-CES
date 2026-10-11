// FUN_1402877a0 @ 1402877a0
// strings: [air.planck.stems]

void FUN_1402877a0(void)

{
  bool bVar1;
  QMessageLogger *this;
  QDebug *pQVar2;
  QDebug local_res8 [32];
  QMessageLogger local_28 [40];
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
              0x160) < DAT_142b28e00) {
    FUN_141982544(&DAT_142b28e00);
    if (DAT_142b28e00 == -1) {
      QLoggingCategory::QLoggingCategory((QLoggingCategory *)&DAT_142b28de8,"air.planck.stems",1);
      atexit((_func_5014 *)&LAB_141ab3590);
      _Init_thread_footer(&DAT_142b28e00);
    }
  }
  bVar1 = QLoggingCategory::isDebugEnabled((QLoggingCategory *)&DAT_142b28de8);
  if (bVar1) {
    this = (QMessageLogger *)
           QMessageLogger::QMessageLogger(local_28,(char *)0x0,0,(char *)0x0,DAT_142b28df0);
    pQVar2 = (QDebug *)QMessageLogger::debug(this);
    pQVar2 = QDebug::operator<<(pQVar2,"init");
    QDebug::operator<<(pQVar2,"air.planck.stems");
    QDebug::~QDebug(local_res8);
  }
  return;
}


