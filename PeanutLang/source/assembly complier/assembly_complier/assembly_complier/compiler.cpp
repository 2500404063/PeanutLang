#include "compiler.h"
#include "definition.h"
#include "tools.h"

#include <algorithm>

void StartComply() {
	AppendBin("This a peanut file.", ByteCodes);
	for (auto & AssemblyCode : AssemblyCodes) {
		std::string command = AssemblyCode.substr(0, AssemblyCode.find(':', 0));
		if (command == "DS:") {
			//因为DS是首位，所以啥也不做
		}
		else if (command == "DB") {
			std::string name = GetParameter(AssemblyCode, 1);
			std::string value = GetParameter(AssemblyCode, 2);
			ConstName.push_back(name);
			ConstPos.push_back(GetPos_DS());
			AppendBin(value, DS);
			AppendBin(0x00, DS);
		}
		else if (command == "PUSH") {
			std::string arg = GetParameter(AssemblyCode, 1);
			//#PUSH:AX
			if (arg == "AX") {
				AppendBin(PUSH_AX, ByteCodes);
			}
			//#PUSH:BX
			else if (arg == "BX") {
				AppendBin(PUSH_BX, ByteCodes);
			}
			//PUSH:CX
			else if (arg == "CX") {
				AppendBin(PUSH_CX, ByteCodes);
			}
			//#PUSH:%ADDR32%	[32bit]
			//#PUSH:%ADDR64%	[64bit]
			else {
				AppendBin(PUSH_ANY, ByteCodes);
				if (IsNumberHex(arg)) {
					arg = SetNumberAuto(arg);
					AppendBinInt(ToNumberFromHex(arg), ByteCodes);
				}
				else {
					auto it = std::find(ConstName.begin(), ConstName.end(), arg);
					if (it != ConstName.end()) {
						PeanutInt pos = std::distance(ConstName.begin(), it);
						AppendBinInt(pos, ByteCodes);
					}
				}
			}
		}
	}
}