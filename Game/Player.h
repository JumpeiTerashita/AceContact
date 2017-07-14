#pragma once
#include "..\Engine\GameObject.h"
#include "..\Library\RenderingObject.h"
class Player : public GameObject
{
public:
	Player();
	~Player();
	RenderingObject PlayerRender;
	void Update();
};

