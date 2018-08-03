#include "machine.h"
#include "definition.h"

void StartExecute() {
	Core core{ 0 };
	while (true)
	{
		if (ByteCodes[core.IP] == (PeanutInt)0x00) {
			core.IP = core.IP + 1;
		}
		else {
			core.IP = core.IP + 1;
		}
	}
}