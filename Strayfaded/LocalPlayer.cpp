#include "include.h"

DWORD LocalPlayer::Get() 
{
	return *(DWORD*)(Global_GameModule + dwLocalPlayer);
}

bool LocalPlayer::Exists() 
{
	if (*(DWORD*)(Global_GameModule + dwLocalPlayer))
	{
		return true;
	}
	return false;
}

void LocalPlayer::ForceJump() 
{
	*(DWORD*)(Global_GameModule + dwForceJump) = 6;
}

void LocalPlayer::ForceAttack()
{
	*(int*)(Global_GameModule + dwForceAttack) = 5;
}

void LocalPlayer::StopAttack()
{
	*(int*)(Global_GameModule + dwForceAttack) = 4;
}

int LocalPlayer::GetHealth() 
{
	DWORD Player = Get();
	if (Player) 
	{
		return *(int*)(Player + m_iHealth);
	}
	return -1;
}

int LocalPlayer::GetTeam()
{
	DWORD Player = Get();
	if (Player)
	{
		return *(int*)(Player + m_iTeamNum);
	}
	return -1;
}

int LocalPlayer::CrosshairID()
{
	DWORD Player = Get();
	if (Player)
	{
		return *(int*)(Player + m_iCrosshairId);
	}
	return -1;
}

void LocalPlayer::SetViewAngles(Vector3 Input) 
{
	Input.Normalize();
	Vector3* ViewAngles = (Vector3*)(*(DWORD*)(Global_EngineModule + dwClientState) + dwClientState_ViewAngles);
	*ViewAngles = Input;
}

Vector3 LocalPlayer::GetViewAngles()
{
	Vector3* ViewAngles = (Vector3*)(*(DWORD*)(Global_EngineModule + dwClientState) + dwClientState_ViewAngles);
	return *ViewAngles;
}