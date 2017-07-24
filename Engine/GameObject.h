#pragma once
#include <string>
#include <memory>

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
	inline void SetLifeTime(float _LifeTime) { LifeTime = _LifeTime; }
	inline float GetLifeTime() { return LifeTime; }
private:
	float LifeTime;
};

