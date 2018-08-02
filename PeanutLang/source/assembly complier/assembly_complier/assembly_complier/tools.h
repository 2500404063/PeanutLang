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

inline std::string GetOnlyString(std::string str) {
	return str.substr(1, str.size() - 2);
}