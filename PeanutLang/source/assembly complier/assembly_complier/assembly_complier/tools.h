#pragma once
#include "definition.h"

////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
// *>EFFECT:定义了一些有用的函数
//------------------------------------------------------------------
// *>DATE:2018/08/01 - 21:04:59 - Wednesday
//------------------------------------------------------------------
// *>AUTHOR:Peng(鹏程)
//------------------------------------------------------------------
////////////////////////////////////////////////////////////////////

//************************************
// Method:    AppendBin
// FullName:  AppendBin
// Access:    public 
// Returns:   void
// Qualifier: Append a HEX to ByteCodes;
// Parameter: byte hex
// Parameter: std::vector<byte> & Place
//************************************
inline void AppendBin(byte hex, std::vector<byte> &Place) {
	Place.push_back(hex);
}
//************************************
// Method:    AppendBin
// FullName:  AppendBin
// Access:    public 
// Returns:   void
// Qualifier: Append a string to ByteCodes;
// Parameter: std::string text
// Parameter: std::vector<byte> & Place
//************************************
inline void AppendBin(std::string text, std::vector<byte> &Place) {
	for (char i : text)
	{
		Place.push_back(i);
	}
}
//************************************
// Method:    AppendBin
// FullName:  AppendBin
// Access:    public 
// Returns:   void
// Qualifier: Connect two vectors
// Parameter: std::vector<byte> hexes
// Parameter: std::vector<byte> & Place
//************************************
inline void AppendBin(std::vector<byte> hexes, std::vector<byte> &Place) {
	Place.insert(Place.cend(), hexes.begin(), hexes.end());
}
//************************************
// Method:    AppendBinInt
// FullName:  AppendBinInt
// Access:    public 
// Returns:   void
// Qualifier: Append a int(32bit/64bit) to ByteCodes;
// Parameter: PeanutInt n
// Parameter: std::vector<byte> & Place
//************************************
inline void AppendBinInt(PeanutInt n, std::vector<byte> &Place) {
#ifdef PEANUT_64
	PeanutInt temp = 0xff00000000000000;
	constexpr int bytes = 8;
#else
	PeanutInt temp = 0xff000000;
	constexpr int bytes = 4;
#endif
	for (int i = bytes - 1; i >= 0; i--, temp >>= 8) {
		Place.insert(Place.end(), static_cast<byte>((n & temp) >> i * 8));
	}
}
//************************************
// Method:    GetParameter
// FullName:  GetParameter
// Access:    public 
// Returns:   std::string
// Qualifier: Get command parameters("_off = 1" means the first parameter.Can't be 0)
// Parameter: std::string code
// Parameter: PeanutInt _off
//************************************
inline std::string GetParameter(std::string code, PeanutInt _off) {
	std::string parameters = code.substr(code.find(':', 0) + 1, code.size() - 1);
	PeanutInt last = 0;
	PeanutInt next = 0;
	for (PeanutInt i = 0; i < _off; i++)
	{
		next = parameters.find(',', last);
		if (_off - i != 1) {
			last = next + 1;
		}
		if (next == SIZE_MAX) {
			next = parameters.size();
		}
	}
	return parameters.substr(last, next - last);
}
//************************************
// Method:    GetOnlyString
// FullName:  GetOnlyString
// Access:    public 
// Returns:   std::string
// Qualifier: Get the string without head('#') and tail(';')
// Parameter: std::string str
//************************************
inline std::string GetOnlyString(std::string str) {
	return str.substr(1, str.size() - 2);
}
//************************************
// Method:    GetPos_DS
// FullName:  GetPos_DS
// Access:    public 
// Returns:   std::string
// Qualifier: Get the size of DS
//************************************
inline PeanutInt GetPos_DS() {
	if (DS.empty()) {
		return 0;
	}
	else {
		return DS.size();
	}
}
//************************************
// Method:    GetPos_CS
// FullName:  GetPos_CS
// Access:    public 
// Returns:   PeanutInt
// Qualifier: Get the size of CS
//************************************
inline PeanutInt GetPos_CS() {
	if (CS.empty()) {
		return 0;
	}
	else {
		return CS.size();
	}
}
//************************************
// Method:    GetPos_ES
// FullName:  GetPos_ES
// Access:    public 
// Returns:   PeanutInt
// Qualifier: Get the size of ES
//************************************
inline PeanutInt GetPos_ES() {
	if (ES.empty()) {
		return 0;
	}
	else {
		return ES.size();
	}
}
//************************************
// Method:    GetPos_FUNC
// FullName:  GetPos_FUNC
// Access:    public 
// Returns:   PeanutInt
// Qualifier: Get Function Pos
// Parameter: std::string funcname
//************************************
inline PeanutInt GetPos_FUNC(std::string funcname) {
	for (PeanutInt i = 0; i < FuncName.size(); i++)
	{
		if (FuncName[i] == funcname) {
			return FuncPos[i];
		}
	}
	return PI_MAX;
}

inline PeanutInt GetPos_Const(std::string const_name) {
	for (PeanutInt i = 0; i < ConstName.size(); i++)
	{
		if (ConstName[i] == const_name) {
			return ConstPos[i];
		}
	}
	return PI_MAX;
}
//************************************
// Method:    SetNumber32
// FullName:  SetNumber32
// Access:    public
// Returns:   std::string
// Qualifier: Set the number to 32 Bit
// Parameter: std::string hex
//************************************
inline std::string SetNumber32(std::string hex) {
	if (hex.size() == 8) {
		return hex;
	}
	else if (hex.size() > 8) {
		return hex.substr(0, 8);
	}
	else {
		while (hex.size() < 8) {
			hex.insert(hex.begin(), '0');
		}
		return hex;
	}
}
//************************************
// Method:    SetNumber64
// FullName:  SetNumber64
// Access:    public
// Returns:   std::string
// Qualifier: Set the number to 64 Bit
// Parameter: std::string hex
//************************************
inline std::string SetNumber64(std::string hex) {
	if (hex.size() == 16) {
		return hex;
	}
	else if (hex.size() > 16) {
		return hex.substr(0, 16);
	}
	else {
		while (hex.size() < 16) {
			hex.insert(hex.begin(), '0');
		}
		return hex;
	}
}

#ifdef PEANUT_64
#define SetNumberAuto SetNumber64
#else
#define SetNumberAuto SetNumber32
#endif

//************************************
// Method:    IsNumberDec
// FullName:  IsNumberDec
// Access:    public
// Returns:   bool
// Qualifier: Check if argument is a number in tens
// Parameter: std::string dec
//************************************
inline bool IsNumberDec(std::string dec) {
	for (const auto &c : dec) {
		if (c < '0' || c > '9') {
			return false;
		}
	}
	return true;
}
//************************************
// Method:    IsNumberHex
// FullName:  IsNumberHex
// Access:    public
// Returns:   bool
// Qualifier: Check if argument is a number(HEX)
// Parameter: std::string dec
//************************************
inline bool IsNumberHex(std::string hex) {
	for (const auto &c : hex) {
		if (!((c >= '0'&&c <= '9') || (c >= 'a'&&c <= 'f') || (c >= 'A'&&c <= 'F'))) {
			return false;
		}
	}
	return true;
}
//************************************
// Method:    ToNumberFromHex
// FullName:  ToNumberFromHex
// Access:    public
// Returns:   PeanutInt
// Qualifier: Change string(hex number) to int(32/64 bit)
// Parameter: std::string str
//************************************
inline PeanutInt ToNumberFromHex(std::string str) {
	PeanutInt ret = 0x00;
	long bitWeight = 1;
	for (auto it = str.rbegin(); it != str.rend(); it++, bitWeight *= 16) {
		if (*it >= '0' && *it <= '9') {
			ret += (*it - 48) * bitWeight;
		}
		else if (*it >= 'a' && *it <= 'f') {
			ret += (*it - 87) * bitWeight;
		}
		else if (*it >= 'A' && *it <= 'F') {
			ret += (*it - 55) * bitWeight;
		}
		else {
			break;
		}
	}
	return ret;
}

