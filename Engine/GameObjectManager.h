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
	inline void AddMap(std::string _name, GameObject* _pObject) { LogicMap.insert(std::make_pair(_name, _pObject)); };
	inline GameObject* GetMap(std::string _name) { return LogicMap[_name]; }
	bool IsInLogicMap(std::string _name);
private:
	std::map<std::string, GameObject*> LogicMap;
};

