// FUN_1402876b0 @ 1402876b0
// strings: [air.planck.stems.download]

void FUN_1402876b0(void)

{
  bool bVar1;
  QMessageLogger *this;
  QDebug *pQVar2;
  QDebug local_res8 [32];
  QMessageLogger local_28 [40];
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
              0x160) < DAT_142b28e60) {
    FUN_141982544(&DAT_142b28e60);
    if (DAT_142b28e60 == -1) {
      QLoggingCategory::QLoggingCategory
                ((QLoggingCategory *)&DAT_142b28e48,"air.planck.stems.download",1);
      atexit((_func_5014 *)&LAB_141ab35b0);
      _Init_thread_footer(&DAT_142b28e60);
    }
  }
  bVar1 = QLoggingCategory::isDebugEnabled((QLoggingCategory *)&DAT_142b28e48);
  if (bVar1) {
    this = (QMessageLogger *)
           QMessageLogger::QMessageLogger(local_28,(char *)0x0,0,(char *)0x0,DAT_142b28e50);
    pQVar2 = (QDebug *)QMessageLogger::debug(this);
    pQVar2 = QDebug::operator<<(pQVar2,"init");
    QDebug::operator<<(pQVar2,"air.planck.stems.download");
    QDebug::~QDebug(local_res8);
  }
  return;
}


