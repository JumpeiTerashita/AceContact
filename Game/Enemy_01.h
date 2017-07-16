#pragma once
#include "..\Engine\GameObject.h"
#include "..\Library\RenderingObject.h"
class Enemy_01 : public GameObject
{
public:
	Enemy_01();
	~Enemy_01();
	RenderingObject EnemyOneRender;
	void Update();
private:
	void Move();
	void SetData();
};
