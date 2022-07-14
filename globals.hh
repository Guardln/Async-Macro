#pragma once
#include <unordered_map>
#include <Windows.h>
#include "H/xorstr.h"
#include "H/skStr.h"
#include <thread>
#include "Macro/keys.h"

struct Vector2
{
	float x;
	float y;
};

class c_globals {
public:
	bool active = true;
	bool login = true;
	bool mainPage = false;

	int loginPage = 0;
	int macroPage = 0;

	char username[255] = "";
	char password[255] = "";
	char key[255] = "";
};

class Macro_Settings
{
public:
	bool enabled = false;
	bool aimCheck = false;

	bool isPrimary = true;

	Vector2 primary{ 0,0 };
	Vector2 secondary{0,0};

	int sleep1 = 28;
	int sleep2 = 28;

	char config[255] = "";
};

inline c_globals globals;
inline Macro_Settings settings;


namespace macro
{
	void moveMouse(float x, float y, int s);
	void macroThread();
	void keysThread();
	void save();
	void load();
}