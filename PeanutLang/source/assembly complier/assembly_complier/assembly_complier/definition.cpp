#include "definition.h"

std::vector<std::string> AssemblyCodes;
std::vector<byte> ByteCodes;
std::vector<byte> DS;
std::vector<byte> CS;
std::vector<byte> ES;
std::vector<std::string> ConstName;
std::vector<PeanutInt> ConstPos;
std::vector<std::string> FuncName;
std::vector<PeanutInt> FuncPos;
PeanutInt DS_Deep_Pos;//常量区
PeanutInt CS_Deep_Pos;//可执行代码区
PeanutInt ES_Deep_Pos;//函数附加段
std::string MainName;//主函数的函数名，在最后的时候替换成地址.