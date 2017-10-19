#pragma once
#include "..\Engine\GameObject.h"
#include "..\Library\RenderingObject.h"
#include <memory>

namespace ktb
{
	class Enemy_01;
	typedef std::shared_ptr<Enemy_01> SpEnemy_01;
	class Enemy_01 : public GameObject
	{
	public:
		SpRenderingObject RenderObj;
		void Update();
		static SpEnemy_01 Create();
		~Enemy_01();
	private:
		Enemy_01();

		void Move();
		void Delete();
	};
}


