#include "include.h"

DWORD WINAPI TreegerbotThread(HMODULE hMod) 
{
	LocalPlayer L;
	Entity E;

	while (!GetAsyncKeyState(UNINJECT_KB)) 
	{
		int CrosshairID = L.CrosshairID();
		int LocalTeram = L.GetTeam();
		int LocalHealth = L.GetHealth();

		if (CrosshairID > 0 && CrosshairID < 64) 
		{
			DWORD Entity = E.Get(CrosshairID - 1);
			int EntityTeam = E.GetTeam(Entity);
			int EntityHealth = E.GetHealth(Entity);

			if (EntityTeam != LocalTeram && UserSettings.EnableTreegerbot)
			{
				if (EntityHealth > 0 && EntityHealth < 101) 
				{
					if (LocalHealth > 0) 
					{
						Sleep(UserSettings.TreegerbotDelay);
						L.ForceAttack();
						Sleep(20);
						L.StopAttack();
					}
				}
			}
		}
		Sleep(3);
	}
	FreeLibraryAndExitThread(hMod, 0);
}