#include "compiler.h"
#include "definition.h"
#include "tools.h"
void StartComply() {
	AppendBin("This a peanut file.",ByteCodes);
	for (auto & AssemblyCode : AssemblyCodes)
	{
		std::string command = AssemblyCode.substr(0, AssemblyCode.find(':', 0));
		if (command == "DS:")
		{
			//��ΪDS����λ������ɶҲ����
		}
		else if (command == "DB") {
			std::string name = GetParameter(AssemblyCode, 1);
			std::string value = GetParameter(AssemblyCode, 2);
			if (value[0] == '\'') {
				ConstName.push_back(name);
				AppendBin(GetOnlyString(value), DS);
				//ConstPos.push_back();
			}
		}
	}
}