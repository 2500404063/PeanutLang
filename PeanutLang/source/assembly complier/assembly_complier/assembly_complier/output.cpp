#include "output.h"
#include "definition.h"
#include "tools.h"
#include <fstream>

void OutPut() {
	PeanutInt main_pos = GetPos_FUNC(MainName);
	AppendBin("This a peanut file.", ByteCodes);//Ìí¼Ó±êÊ¶·û
#ifdef X64
	AppendBin(0x64, ByteCodes);
#else
	AppendBin(0x32, ByteCodes);
#endif // X64
	AppendBinInt(main_pos, ByteCodes);
	AppendBinInt(DS.size(), ByteCodes);
	AppendBinInt(CS.size(), ByteCodes);
	AppendBinInt(ES.size(), ByteCodes);
	AppendBin(DS, ByteCodes);
	AppendBin(CS, ByteCodes);
	AppendBin(ES, ByteCodes);
	std::ofstream out;
	out.open("output.out", std::ios::binary);
	if (out.is_open())
	{
		out.write((char*)&ByteCodes[0], ByteCodes.size());
	}
	out.close();
}