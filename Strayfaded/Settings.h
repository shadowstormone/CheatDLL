#pragma once
#include "include.h"

class USettings
{
public:
	//Misk
	bool EnableBhop = false;

	// TreegerBot (Main Modules)
	bool EnableTreegerbot = false;
	int TreegerbotDelay = 0;

	//RCS
	bool EnableRCS = false;
	float RCSAmount = 1.0f;
};