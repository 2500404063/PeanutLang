#include "compiler.h"
#include "definition.h"
#include "tools.h"

#include <algorithm>

void StartComply() {
	//-1 = Unknown,0 = DS,1 = CS,2 = ES
	PeanutInt CurrentArea = 0;
	DS.clear();
	CS.clear();
	ES.clear();
	ConstName.clear();
	ConstPos.clear();
	AppendBin("This a peanut file.", ByteCodes);
	for (auto & AssemblyCode : AssemblyCodes) {
		std::string command = AssemblyCode.substr(0, AssemblyCode.find(':', 0));
		if (command == "REM") {
			continue;
		}
		else if (command == "DS") {
			CurrentArea = 0;
		}
		else if (command == "CS") {
			CurrentArea = 1;
		}
		else if (command == "ES") {
			CurrentArea = 2;
		}
		else if (CurrentArea == 0) {//DS�ռ䣺 
			if (command == "DB") {
				std::string name = GetParameter(AssemblyCode, 1);
				std::string value = GetParameter(AssemblyCode, 2);
				ConstName.push_back(name);
				ConstPos.push_back(GetPos_DS());
				AppendBin(value, DS);
				AppendBin(0x00, DS);
			}
		}
		else if (CurrentArea == 1) {//CS�ռ䣺
			if (command == "PUSH") {
				std::string arg = GetParameter(AssemblyCode, 1);
				//#PUSH:AX;
				if (arg == "AX") {
					AppendBin(PUSH_AX, CS);
				}
				//#PUSH:BX;
				else if (arg == "BX") {
					AppendBin(PUSH_BX, CS);
				}
				//PUSH:CX;
				else if (arg == "CX") {
					AppendBin(PUSH_CX, CS);
				}
				//#PUSH:%OFFSET 32%	[32bit]
				//#PUSH:%OFFSET 64%	[64bit]
				else {
					AppendBin(PUSH_ANY, CS);
					if (IsNumberHex(arg)) {
						AppendBinInt(ToNumberFromHex(arg), CS);
					}
					else {
						auto it = std::find(ConstName.begin(), ConstName.end(), arg);
						if (it != ConstName.end()) {
							PeanutInt index = std::distance(ConstName.begin(), it);
							AppendBinInt(ConstPos[index], CS);
						}
					}
				}
			}
			else if (command == "POP") {
				std::string arg = GetParameter(AssemblyCode, 1);
				//#POP:AX;
				if (arg == "AX") {
					AppendBin(POP_AX, CS);
				}
				//#POP:BX;
				else if (arg == "BX") {
					AppendBin(POP_BX, CS);
				}
				//POP:CX;
				else if (arg == "CX") {
					AppendBin(POP_CX, CS);
				}
				//#POP:%OFFSET 32%	[32bit]
				//#POP:%OFFSET 64%	[64bit]
				else {
					AppendBin(POP_ANY, CS);
					if (IsNumberHex(arg)) {
						AppendBinInt(ToNumberFromHex(arg), CS);
					}
					else {
						auto it = std::find(ConstName.begin(), ConstName.end(), arg);
						if (it != ConstName.end()) {
							PeanutInt index = std::distance(ConstName.begin(), it);
							AppendBinInt(ConstPos[index], CS);
						}
					}
				}
			}
			else if (command == "NOP") {
				AppendBin(NOP, CS);
			}
		}
	}
}