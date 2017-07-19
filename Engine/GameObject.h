#pragma once
#include <string>

class GameObject
{
public:
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

