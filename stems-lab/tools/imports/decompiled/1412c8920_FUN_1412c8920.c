// FUN_1412c8920 @ 1412c8920
// calls: [WriteFile]

int FUN_1412c8920(basic_streambuf<char,std::char_traits<char>_> *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if ((*(longlong *)(param_1 + 0x68) == -1) && (*(longlong *)(param_1 + 0x70) == -1)) {
    if (param_2 != -1) {
      return -1;
    }
  }
  else if (param_2 != -1) {
    pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::epptr(param_1);
    pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
    if (pcVar3 != pcVar2) {
      pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
      *pcVar2 = (char)param_2;
      std::basic_streambuf<char,std::char_traits<char>_>::pbump(param_1,1);
      cVar1 = FUN_1412c5cf0(param_1);
      if (cVar1 == '\0') {
        return -1;
      }
      return param_2;
    }
    cVar1 = FUN_1412c5cf0();
    if (cVar1 == '\0') {
      return -1;
    }
    pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(param_1);
    *pcVar2 = (char)param_2;
    std::basic_streambuf<char,std::char_traits<char>_>::pbump(param_1,1);
    return param_2;
  }
  (**(code **)(*(longlong *)param_1 + 0x68))();
  return -1;
}


