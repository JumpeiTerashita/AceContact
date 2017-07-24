#pragma once
#include "..\Engine\GameObject.h"
#include "..\Library\RenderingObject.h"

class Bullet;
typedef std::shared_ptr<Bullet> SpBullet;
class Bullet:public GameObject
{
public:
	Bullet();
	~Bullet();
	static SpBullet Create();
	SpRenderingObject RenderObj;
	void Update();
	void SetData();
};

