#include "DXUT.h"
#include "GameObject.h"
#include "GameObjectManager.h"

GameObject::GameObject()
{
	ObjectName = "None";
	LifeTime = -1;
}


GameObject::~GameObject()
{
}

void GameObject::AddLogicList()
{
	GameObjectManager::GetInstance()->AddList(this);
}

void GameObject::AddLogicMap(std::string _name)
{
	GameObjectManager::GetInstance()->AddMap(_name,this);
}

