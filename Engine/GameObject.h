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
};

