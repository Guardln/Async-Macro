#include "../globals.hh"
#include "../H/skStr.h"
#include "../H/xorstr.h"
#include <filesystem>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <xmemory>
#include <istream>

namespace fs = std::filesystem;

void macro::keysThread()
{
	while (1)
	{
		if (GetAsyncKeyState(0x31) & 1 && !settings.isPrimary)
		{
			settings.isPrimary = true;
		}
		if (GetAsyncKeyState(0x32) & 1 && settings.isPrimary)
		{
			settings.isPrimary = false;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}