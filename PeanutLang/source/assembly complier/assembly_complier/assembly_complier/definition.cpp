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
PeanutInt DS_Deep_Pos;//������
PeanutInt CS_Deep_Pos;//��ִ�д�����
PeanutInt ES_Deep_Pos;//�������Ӷ�
std::string MainName;//�������ĺ�������������ʱ���滻�ɵ�ַ.