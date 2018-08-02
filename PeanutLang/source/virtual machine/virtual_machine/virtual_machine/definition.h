#pragma once
#include <string>
#include <vector>

using byte = unsigned char;

#ifdef X64
using PeanutInt = size_t;
#define PI_MAX ULLONG_MAX
#else
using PeanutInt = size_t;
#define PI_MAX UINT32_MAX
#endif // _W64

#pragma region MachineDefiniton
struct Core
{
	//ͨ�üĴ���
	PeanutInt AX;
	PeanutInt BX;
	PeanutInt CX;
	//����Ĵ���
	PeanutInt SP;
	PeanutInt IP;
	//��־�Ĵ���
	PeanutInt JF;
	//�μĴ���
	PeanutInt CS;
	PeanutInt DS;
	PeanutInt ES;
};

#pragma endregion


extern std::vector<byte> ByteCodes;

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