#include "definition.h"
#include "machine.h"
#include <fstream>
#include <thread>
#include <iostream>

int main(int argc, char* argv[]) {
	std::ifstream in;
	in.open(argv[argc - 1], std::ios::binary);
	unsigned char temp = 0;
	while (true)
	{
		in.read((char*)&temp, 1);
		if (!in.eof()) {
			ByteCodes.push_back(temp);
		}
		else {
			break;
		}
	}
	std::thread start(StartExecute);
	start.join();
	//cout << "Address:" << "00" << setiosflags(ios::uppercase) << hex << (int)&temp << endl;
	return 0;
}