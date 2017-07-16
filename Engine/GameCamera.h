#pragma once
#include "GameObject.h"
#include "../Library/Camera.h"
#include "../Library/Singleton.h"

class GameCamera :public GameObject,public Singleton<GameCamera>
{
public:
	Camera CameraStatus;
	GameCamera();
	~GameCamera();
	void Update();
	void Move();
};

