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
	//通用寄存器
	PeanutInt AX;
	PeanutInt BX;
	PeanutInt CX;
	//特殊寄存器
	PeanutInt SP;
	PeanutInt IP;
	//标志寄存器
	PeanutInt JF;
	//段寄存器
	PeanutInt CS;
	PeanutInt DS;
	PeanutInt ES;
};

#pragma endregion


extern std::vector<byte> ByteCodes;

//后面注释跟着的是参数,空白表示无参数,参数风格：类型+名称
#define NUL 00//
#define PUSH_AX 01//
#define PUSH_BX 02//
#define PUSH_CX 03//
#define PUSH_ANY 04//PeanutInt address
#define POP_AX 01//
#define POP_BX 02//
#define POP_CX 03//
#define POP_ANY 04//PeanutInt address
