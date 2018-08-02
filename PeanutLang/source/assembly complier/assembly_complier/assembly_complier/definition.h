#pragma once
////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
// *>EFFECT:���ж��������
//------------------------------------------------------------------
// *>DATE:2018/08/01 - 20:56:46 - Wednesday
//------------------------------------------------------------------
// *>AUTHOR:Peng(����)
//------------------------------------------------------------------
////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>

using byte = unsigned char;

#ifdef X64
using PeanutInt = size_t;
#define PI_MAX SIZE_MAX
#else
using PeanutInt = size_t;
#define PI_MAX SIZE_MAX
#endif // X64

extern std::vector<std::string> AssemblyCodes;
extern std::vector<byte> ByteCodes;
extern std::vector<byte> DS;
extern std::vector<byte> CS;
extern std::vector<byte> ES;
extern std::vector<std::string> ConstName;
extern std::vector<PeanutInt> ConstPos;
extern PeanutInt DS_Deep_Pos;//������
extern PeanutInt CS_Deep_Pos;//��ִ�д�����
extern PeanutInt ES_Deep_Pos;//����������

//����ע�͸��ŵ��ǲ���,�հױ�ʾ�޲���,�����������+����
#define NUL 0x00//NULL
#define PUSH_AX 0x01//NULL
#define PUSH_BX 0x02//NULL
#define PUSH_CX 0x03//NULL
#define PUSH_ANY 0x04//PeanutInt address
#define POP_AX 0x05//NULL
#define POP_BX 0x06//NULL
#define POP_CX 0x07//NULL
#define POP_ANY 0x08//PeanutInt address