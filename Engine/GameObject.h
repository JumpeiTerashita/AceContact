#pragma once
#include <string>
#include <memory>
#include "../Library/RenderingObject.h"
#include "../Library/Transform.h"

class GameObject;
typedef std::shared_ptr<GameObject> SpGameObject;
typedef std::weak_ptr<GameObject> WpGameObject;

class GameObject
{
public:
	D3DXVECTOR3 ForwardVec;
	WpGameObject Wp_this;
	std::string ObjectName;
	Transform transform;
	GameObject();
	virtual ~GameObject();
	virtual void Delete() = 0;
	virtual void Update() = 0;
	void AddLogicList();
	void AddLogicMap(std::string _name);
	void SetTransform(SpGameObject _SpGameObject,SpRenderingObject _SpRenderingObject);
	inline void SetLifeTime(float _LifeTime) { LifeTime = _LifeTime; }
	SpGameObject GetLogicMap(std::string _name);
	inline float GetLifeTime() { return LifeTime; }
	void DelObj();
protected:
	D3DXVECTOR3 GetForwardVec(D3DXVECTOR3* Rot, D3DXVECTOR3* DefaltForward = &(D3DXVECTOR3(0, 0, 1)));
private:
	float LifeTime;
};

