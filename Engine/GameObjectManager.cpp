#include "DXUT.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "GameCamera.h"
#include <list>
#include "..\support\t2k_support.h"

using namespace ktb;

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
		(*it)->Conduct();
		(*it)->Update();
		if (0 == (*it)->GetLifeTime())
		{
		t2k::Support::debugTrace("%s ‚ª Žõ–½ƒ[ƒ", (*it)->ObjectName.c_str());
		(*it)->DelObj();
		//delete (*it);
		it = LogicList.erase(it);
		continue;
		}
		it++;
	}
	
}

bool GameObjectManager::IsInLogicMap(const std::string & _name)
{
	auto itr = LogicMap.find(_name);
	if (itr != LogicMap.end()) return true;
	else return false;
}