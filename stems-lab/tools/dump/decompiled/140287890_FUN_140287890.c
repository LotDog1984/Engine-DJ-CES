// FUN_140287890 @ 140287890
// strings: [air.planck.stems.render]

void FUN_140287890(void)

{
  bool bVar1;
  QMessageLogger *this;
  QDebug *pQVar2;
  QDebug local_res8 [32];
  QMessageLogger local_28 [40];
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
              0x160) < DAT_142b28e40) {
    FUN_141982544(&DAT_142b28e40);
    if (DAT_142b28e40 == -1) {
      QLoggingCategory::QLoggingCategory
                ((QLoggingCategory *)&DAT_142b28e28,"air.planck.stems.render",1);
      atexit((_func_5014 *)&LAB_141ab35c0);
      _Init_thread_footer(&DAT_142b28e40);
    }
  }
  bVar1 = QLoggingCategory::isDebugEnabled((QLoggingCategory *)&DAT_142b28e28);
  if (bVar1) {
    this = (QMessageLogger *)
           QMessageLogger::QMessageLogger(local_28,(char *)0x0,0,(char *)0x0,DAT_142b28e30);
    pQVar2 = (QDebug *)QMessageLogger::debug(this);
    pQVar2 = QDebug::operator<<(pQVar2,"init");
    QDebug::operator<<(pQVar2,"air.planck.stems.render");
    QDebug::~QDebug(local_res8);
  }
  return;
}


