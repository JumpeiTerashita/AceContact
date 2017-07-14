#include "DXUT.h"
#include "GameObject.h"
#include "GameObjectManager.h"

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::AddLogicList()
{
	GameObjectManager::GetInstance()->AddList(this);
}
