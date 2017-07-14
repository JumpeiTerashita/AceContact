#pragma once
#include "..\Library\Singleton.h"
#include <list>
#include <map>

class GameObject;

class GameObjectManager : public Singleton<GameObjectManager>
{
public:
	GameObjectManager();
	~GameObjectManager();
	void Update();
	std::list<GameObject*> LogicList;
	inline void AddList(GameObject* _pObject) { LogicList.push_back(_pObject); }
	std::map<std::string, GameObject*> LogicMap;
};

