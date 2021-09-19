#pragma once
#include "include.h"

class LocalPlayer 
{
public:
	DWORD Get();

	bool Exists();

	//TriggerBot
	void ForceJump();
	void ForceAttack();
	void StopAttack();

	int GetHealth();
	int GetTeam();
	int CrosshairID();

	void SetViewAngles(Vector3 Input);
	Vector3 GetViewAngles();

};