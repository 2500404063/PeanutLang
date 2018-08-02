////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
// *>EFFECT:只负责读取文件
//------------------------------------------------------------------
// *>DATE:2018/08/01 - 20:57:12 - Wednesday
//------------------------------------------------------------------
// *>AUTHOR:Peng(鹏程)
//------------------------------------------------------------------
////////////////////////////////////////////////////////////////////


#include "definition.h"
#include "compiler.h"
#include <fstream>
#include <thread>
#include <iostream>

int main(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++)
	{
		std::ifstream in;
		in.open(argv[i], std::ios::binary);
		std::string codes;
		char temp;
		while (true)
		{
			in.read(&temp, 1);
			if (!in.eof()) {
				codes.push_back(temp);
			}
			else {
				break;
			}
		}
		in.close();
		PeanutInt start = 0;
		PeanutInt end = 0;
		while (true)
		{
			start = codes.find('#', start);
			end = codes.find(';', end);
			if (start != SIZE_MAX) {
				AssemblyCodes.push_back(codes.substr(start + 1, end - start - 1));
				start++;
				end++;
			}
			else {
				break;
			}
		}
		StartComply();
	}
	std::cin.get();
	//cout << "Address:" << "00" << setiosflags(ios::uppercase) << hex << (int)&temp << endl;
	return 0;
}