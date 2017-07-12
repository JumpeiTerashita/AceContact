#pragma once
#pragma comment(lib,"XInput.lib")
#include <Xinput.h>
#include "Singleton.h"

class InputManager : public Singleton<InputManager>
{
public:

	InputManager();
	InputManager(int playerNum);
	~InputManager();
	XINPUT_STATE GetState();

private:
	int ControllerNum;
	XINPUT_STATE State;
};

