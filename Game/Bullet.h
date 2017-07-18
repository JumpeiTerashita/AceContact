#pragma once
#include "..\Engine\GameObject.h"
#include "..\Library\RenderingObject.h"

class Bullet:public GameObject
{
public:
	Bullet();
	~Bullet();
	RenderingObject BulletRender;
	void Update();
	void SetData();
};

