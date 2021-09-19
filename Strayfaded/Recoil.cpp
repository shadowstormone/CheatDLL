#include "include.h"

DWORD WINAPI RecoilControlThread(HMODULE hMod)
{
	LocalPlayer LOL;
	DWORD localPlayer = LOL.Get();
	Vector3 OldPunch{ 0,0,0 };

	while (!GetAsyncKeyState(UNINJECT_KB))
	{
		if (UserSettings.EnableRCS)
		{
			if (localPlayer)
			{
				int* ShotsFired = (int*)(localPlayer + m_iShotsFired);
				Vector3* RecoilPunch = (Vector3*)(localPlayer + m_aimPunchAngle);
				Vector3 PunchAngle = *RecoilPunch * (UserSettings.RCSAmount * 2);

				if (*ShotsFired > 1 && GetAsyncKeyState(VK_LBUTTON))
				{
					Vector3 Angle = LOL.GetViewAngles() + OldPunch - PunchAngle;
					LOL.SetViewAngles(Angle);
				}
				OldPunch = PunchAngle;
			}
			else
			{
				localPlayer = LOL.Get();
			}
		}
	}
	FreeLibraryAndExitThread(hMod, 0);
}