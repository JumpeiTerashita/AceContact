#include "DXUT.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "..\support\t2k_support.h"

GameObject::GameObject()
{
	ObjectName = "None";
	LifeTime = -1;

}


GameObject::~GameObject()
{
	t2k::Support::debugTrace("GameObject Destruct :%s", ObjectName);
	GameObjectManager::GetInstance()->DelMap(ObjectName);
}

void GameObject::AddLogicList()
{
	SpGameObject SpG = Wp_this.lock();
	if (SpG)
	{
		GameObjectManager::GetInstance()->AddList(SpG);
	}

}

void GameObject::AddLogicMap(std::string _name)
{
	SpGameObject SpG = Wp_this.lock();
	if (SpG)
	{
		GameObjectManager::GetInstance()->AddMap(_name, SpG);
	}
}

SpGameObject GameObject::GetLogicMap(std::string _name)
{
	auto GameObjMng = GameObjectManager::GetInstance();
	if (GameObjMng->IsInLogicMap(_name))
	{
		return GameObjMng->GetMap(_name);
	}

	return nullptr;
}

void GameObject::SetRenderObj(SpRenderingObject _RenderObjP)
{
	RenderObjP = _RenderObjP;
}

