#pragma once
#include "GameObject.h"
#include "../Library/Camera.h"

namespace ktb
{
	class GameCamera;
	typedef std::shared_ptr<GameCamera> SpGameCamera;
	class GameCamera :public GameObject
	{
	public:
		int CameraMode;
		Camera CameraStatus;
		GameCamera();
		~GameCamera() {};
		void Update();
		void Move();
		static SpGameCamera Create();
	private:
		void Delete();
	};
}
