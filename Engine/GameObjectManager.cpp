#include "DXUT.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "GameCamera.h"
#include <list>

std::shared_ptr<GameObjectManager> GameObjectManager::Instance = nullptr;

GameObjectManager::GameObjectManager()
{
}


GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::Update()
{
	/*if (0 == ->CameraMode)
	{
		GameCamera::GetInstance()->Update();
		return;
	}*/

	std::list< SpGameObject >::iterator it = LogicList.begin();
	while (it != LogicList.end()) {
		(*it)->Update();
		if (0 == (*it)->GetLifeTime())
		{
		//delete (*it);
		it = LogicList.erase(it);
		continue;
		}
		it++;
	}
	
}

bool GameObjectManager::IsInLogicMap(std::string _name)
{
	auto itr = LogicMap.find(_name);
	if (itr != LogicMap.end()) return true;
	else return false;
}