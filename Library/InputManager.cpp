#include <windows.h>
#include "DXUT.h"
#include "InputManager.h"


InputManager* InputManager::Instance = nullptr;


InputManager::InputManager()
{
	XInputEnable(true);
	SecureZeroMemory(&State, sizeof(XINPUT_STATE));
}

InputManager::InputManager(int playerNum)
{
	XInputEnable(true);
	SecureZeroMemory(&State, sizeof(XINPUT_STATE));
	ControllerNum = playerNum - 1;
}


InputManager::~InputManager()
{
}

XINPUT_STATE InputManager::GetState() {
	XInputGetState(ControllerNum, &State);
	return State;
}
