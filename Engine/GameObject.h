#pragma once
#include <string>
#include <memory>
#include "../Library/RenderingObject.h"

class GameObject;
typedef std::shared_ptr<GameObject> SpGameObject;
typedef std::weak_ptr<GameObject> WpGameObject;

class GameObject
{
public:
	WpGameObject Wp_this;
	std::string ObjectName;
	GameObject();
	virtual ~GameObject();
	virtual void Update() = 0;
	void AddLogicList();
	void AddLogicMap(std::string _name);
	void SetRenderObj(SpRenderingObject _RenderObjP);
	SpGameObject GetLogicMap(std::string _name);
	SpRenderingObject RenderObjP;
	inline void SetLifeTime(float _LifeTime) { LifeTime = _LifeTime; }
	inline float GetLifeTime() { return LifeTime; }
	void DelObj();
private:
	float LifeTime;
};

