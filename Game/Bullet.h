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
	SpRenderingObject RenderObj;
	static SpBullet Create();
	void Update();
	void CollisionJudge();
private:
	void Delete();
};

