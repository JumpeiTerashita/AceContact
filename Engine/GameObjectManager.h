#pragma once
#include "..\Library\Singleton.h"
#include <list>
#include <map>
#include "..\Engine\GameObject.h"

namespace ktb
{
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
		inline void AddMap(const std::string & _name, SpGameObject _SpObject) { LogicMap.insert(std::make_pair(_name, _SpObject)); };
		inline void DelMap(const std::string & _name) { LogicMap.erase(_name); };
		inline SpGameObject GetMap(const std::string & _name) { return LogicMap[_name]; }
		bool IsInLogicMap(const std::string & _name);
	private:
		std::map<std::string, SpGameObject> LogicMap;
	};
}