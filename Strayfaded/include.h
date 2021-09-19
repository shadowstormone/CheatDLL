#pragma once
#include <Windows.h>

// Extra Config
#define MENU_KB VK_TAB
#define UNINJECT_KB VK_DELETE

// DirectX
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

// Imgui
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx9.h"

// Hook/Drawing
#include "DirectX.h"
#include "Hook.h"
#include "Drawing.h"


//Classes
#include "LocalPlayer.h"
#include "Settings.h"
#include "Entity.h"
USettings UserSettings;

//Engine
#include "Engine.h"

//Offsets
#include "csgo.hpp"
using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

//Modules(Функции чита)
#include "Bhop.h"
#include "Treegerbot.h"
#include "Recoil.h"

// Global Variables
DWORD Global_GameModule;
DWORD Global_EngineModule;

#include "Vector.h"