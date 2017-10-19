#pragma once
#include <string>
#include <memory>
#include "../Library/RenderingObject.h"
#include "../Library/Transform.h"
namespace ktb
{
	class GameObject;
	typedef std::shared_ptr<GameObject> SpGameObject;
	typedef std::weak_ptr<GameObject> WpGameObject;

	class GameObject
	{
	public:
		float Timer;
		WpGameObject Wp_this;
		std::string ObjectName;
		Transform transform;
		GameObject();
		virtual ~GameObject();
		
		virtual void Delete() = 0;
		virtual void Update() = 0;
		void AddLogicList();
		void AddLogicMap(const std::string & _name);
		void SetTransform(SpGameObject _SpGameObject, SpRenderingObject _SpRenderingObject);
		inline void SetLifeTime(const float & _LifeTime) { LifeTime = _LifeTime; }
		SpGameObject GetLogicMap(const std::string & _name);
		inline float GetLifeTime() { return LifeTime; }
		void Conduct();
		void DelObj();
		D3DXVECTOR3 GetForwardVec(const D3DXVECTOR3 & Rot, const D3DXVECTOR3 & DefaltForward = (D3DXVECTOR3(0, 0, 1)));
	private:
		float LifeTime;
	};

}