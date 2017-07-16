#include "DXUT.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include <list>

GameObjectManager* GameObjectManager::Instance = nullptr;

GameObjectManager::GameObjectManager()
{
}


GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::Update()
{
	std::list< GameObject* >::iterator it = LogicList.begin();
	while (it != LogicList.end()) {
		(*it)->Update();
		/*if (0 == (*it)->getLifeTime())
		{
		delete (*it);
		it = objects.erase(it);
		continue;
		}*/
		it++;
	}
	
}

bool GameObjectManager::IsInLogicMap(std::string _name)
{
	auto itr = LogicMap.find(_name);
	if (itr != LogicMap.end()) return true;
	else return false;
}