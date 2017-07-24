#pragma once
#include "..\Library\Singleton.h"
#include <list>
#include <map>
#include "..\Engine\GameObject.h"

class GameObjectManager : public Singleton<GameObjectManager>
{
public:
	GameObjectManager();
	~GameObjectManager();
	void Update();
	std::list<SpGameObject> LogicList;
	inline void AddList(SpGameObject _SpObject) { 
		LogicList.push_back(_SpObject); 
	}
	inline void AddMap(std::string _name, SpGameObject _SpObject) { LogicMap.insert(std::make_pair(_name, _SpObject)); };
	inline SpGameObject GetMap(std::string _name) { return LogicMap[_name]; }
	bool IsInLogicMap(std::string _name);
private:
	std::map<std::string, SpGameObject> LogicMap;
};

