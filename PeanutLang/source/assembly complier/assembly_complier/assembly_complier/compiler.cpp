#include "compiler.h"
#include "definition.h"
#include "tools.h"

void StartComply() {
	AppendBin("This a peanut file.", ByteCodes);
	for (auto & AssemblyCode : AssemblyCodes)
	{
		std::string command = AssemblyCode.substr(0, AssemblyCode.find(':', 0));
		if (command == "DS:")
		{
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

		}
	}
}