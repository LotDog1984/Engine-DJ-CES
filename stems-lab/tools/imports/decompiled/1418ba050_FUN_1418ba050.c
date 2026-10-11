// FUN_1418ba050 @ 1418ba050
// calls: [CreateFileW]

longlong * FUN_1418ba050(longlong *param_1)

{
  bool bVar1;
  char cVar2;
  uint *puVar3;
  QLoggingCategory *pQVar4;
  QMessageLogger *pQVar5;
  QDebug *pQVar6;
  undefined8 uVar7;
  char ****ppppcVar8;
  longlong *plVar9;
  longlong lVar10;
  QDebug local_res10 [8];
  char ***local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong local_58;
  QMessageLogger local_50 [40];
  
  FUN_1418b9d90();
  puVar3 = (uint *)FUN_141974de0(local_res10);
  if (*puVar3 < 2) {
    pQVar4 = (QLoggingCategory *)FUN_1418ba320();
    bVar1 = QLoggingCategory::isInfoEnabled(pQVar4);
    if (bVar1) {
      pQVar5 = (QMessageLogger *)
               QMessageLogger::QMessageLogger
                         (local_50,(char *)0x0,0,(char *)0x0,*(char **)(pQVar4 + 8));
      pQVar6 = (QDebug *)QMessageLogger::info(pQVar5);
      pQVar6 = QDebug::operator<<(pQVar6,"Creating temp folder for temp files:");
      uStack_68 = 0;
      local_60 = 0;
      local_58 = 0xf;
      local_70 = (char ***)0x0;
      lVar10 = param_1[2];
      if (lVar10 != 0) {
        if ((ulonglong)param_1[3] < 8) {
          lVar10 = (longlong)param_1 + lVar10 * 2;
          plVar9 = param_1;
        }
        else {
          lVar10 = *param_1 + lVar10 * 2;
          plVar9 = (longlong *)*param_1;
        }
        FUN_14196e970();
        FUN_141971350(plVar9,lVar10);
      }
      ppppcVar8 = &local_70;
      if (0xf < local_58) {
        ppppcVar8 = (char ****)local_70;
      }
      QDebug::operator<<(pQVar6,(char *)ppppcVar8);
      if (0xf < local_58) {
        ppppcVar8 = (char ****)local_70;
        if ((0xfff < local_58 + 1) &&
           (ppppcVar8 = (char ****)local_70[-1],
           (char *)0x1f < (char *)((longlong)local_70 + (-8 - (longlong)ppppcVar8)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(ppppcVar8);
      }
      local_60 = 0;
      local_58 = 0xf;
      local_70 = (char ***)((ulonglong)local_70 & 0xffffffffffffff00);
      QDebug::~QDebug(local_res10);
    }
    cVar2 = FUN_141973350(param_1);
    if (cVar2 == '\0') {
      pQVar4 = (QLoggingCategory *)FUN_1418ba320();
      bVar1 = QLoggingCategory::isCriticalEnabled(pQVar4);
      if (bVar1) {
        pQVar5 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger
                           (local_50,(char *)0x0,0,(char *)0x0,*(char **)(pQVar4 + 8));
        pQVar6 = (QDebug *)QMessageLogger::critical(pQVar5);
        pQVar6 = QDebug::operator<<(pQVar6,"Failed to create temp files folder:");
        uStack_68 = 0;
        local_60 = 0;
        local_58 = 0xf;
        local_70 = (char ***)0x0;
        lVar10 = param_1[2];
        if (lVar10 != 0) {
          if ((ulonglong)param_1[3] < 8) {
            lVar10 = (longlong)param_1 + lVar10 * 2;
            plVar9 = param_1;
          }
          else {
            lVar10 = *param_1 + lVar10 * 2;
            plVar9 = (longlong *)*param_1;
          }
          uVar7 = FUN_14196e970();
          FUN_141971350(plVar9,lVar10,&local_70,uVar7);
        }
        ppppcVar8 = &local_70;
        if (0xf < local_58) {
          ppppcVar8 = (char ****)local_70;
        }
        QDebug::operator<<(pQVar6,(char *)ppppcVar8);
        if (0xf < local_58) {
          ppppcVar8 = (char ****)local_70;
          if ((0xfff < local_58 + 1) &&
             (ppppcVar8 = (char ****)local_70[-1],
             (char *)0x1f < (char *)((longlong)local_70 + (-8 - (longlong)ppppcVar8)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(ppppcVar8);
        }
        local_60 = 0;
        local_58 = 0xf;
        local_70 = (char ***)((ulonglong)local_70 & 0xffffffffffffff00);
        QDebug::~QDebug(local_res10);
      }
    }
  }
  return param_1;
}


