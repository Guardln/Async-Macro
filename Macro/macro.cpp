#include "../globals.hh"
#include "../H/skStr.h"
#include "../H/xorstr.h"

void macro::macroThread()
{
	while (1)
	{
		if (settings.enabled && !settings.aimCheck)
		{
			if (settings.isPrimary)
			{
				if (GetAsyncKeyState(VK_LBUTTON)) macro::moveMouse(settings.primary.x,settings.primary.y, settings.sleep1);
			}
			else
			{
				if (GetAsyncKeyState(VK_LBUTTON)) macro::moveMouse(settings.secondary.x, settings.secondary.y, settings.sleep2);
			}
		}
		if (settings.enabled && settings.aimCheck)
		{
			if (settings.isPrimary)
			{
				if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_RBUTTON)) macro::moveMouse(settings.primary.x, settings.primary.y, settings.sleep1);
			}
			else
			{
				if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_RBUTTON)) macro::moveMouse(settings.secondary.x, settings.secondary.y, settings.sleep2);
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}

void macro::moveMouse(float x, float y , int s)
{
	mouse_event(0x0001, x, y, 0, 0);
	Sleep(s - 5);
}