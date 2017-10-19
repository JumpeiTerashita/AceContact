#pragma once
#include <memory>
#include "..\Engine\GameObject.h"
#include "..\Library\RenderingObject.h"

namespace ktb
{
	class Plane;
	typedef std::shared_ptr<Plane> SpPlane;
	class Plane :public GameObject
	{
	public:
		static SpPlane Create();
		SpRenderingObject RenderObj;
		void Update();
		Plane();
		~Plane();
	private:
		void Delete();
	};
}


