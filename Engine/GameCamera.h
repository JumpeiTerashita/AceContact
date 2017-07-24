#pragma once
#include "GameObject.h"
#include "../Library/Camera.h"
#include "../Library/Singleton.h"

class GameCamera :public GameObject,public Singleton<GameCamera>
{
public:
	int CameraMode;
	Camera CameraStatus;
	GameCamera();
	~GameCamera();
	void Create();
	void Update();
	void Move();
};

