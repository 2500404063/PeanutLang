#pragma once
#include <string>
#include <vector>

#pragma region CommoneDefinition
typedef unsigned char byte;
#ifdef X64
typedef unsigned long long PeanutInt;
#else
typedef unsigned int PeanutInt;
#endif // _W64
#pragma endregion

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
#define NUL 00//
#define PUSH_AX 01//
#define PUSH_BX 02//
#define PUSH_CX 03//
#define PUSH_ANY 04//PeanutInt address
#define POP_AX 01//
#define POP_BX 02//
#define POP_CX 03//
#define POP_ANY 04//PeanutInt address
