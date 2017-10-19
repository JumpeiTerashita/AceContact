#pragma once
#include "..\Engine\GameObject.h"
#include "..\Library\RenderingObject.h"
#include "..\Library\Transform.h"

namespace ktb
{

	class Bullet;
	typedef std::shared_ptr<Bullet> SpBullet;
	class Bullet :public GameObject
	{
	public:
		bool isEnemys;
		Bullet();
		~Bullet();
		SpRenderingObject RenderObj;
		static SpBullet Create(const Transform & _Transform);
		void Update();
		void CollisionJudge();
	private:
		void Delete();
	};
}
