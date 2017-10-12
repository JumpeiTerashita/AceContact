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
	t2k::Support::debugTrace("GameObject Destruct : %s", ObjectName.c_str());
	
}

void GameObject::SetTransform(SpGameObject _SpGameObject, SpRenderingObject _SpRenderingObject)
{
	_SpRenderingObject->Ptransform = &(_SpGameObject->transform);
}

void GameObject::DelObj()
{
	GameObjectManager::GetInstance()->DelMap(ObjectName);
}

D3DXVECTOR3 GameObject::GetForwardVec(D3DXVECTOR3 * Rot, D3DXVECTOR3 * DefaltForward)
{
	D3DXVECTOR3 FVec;
	D3DXMATRIX RM;
	D3DXMatrixRotationYawPitchRoll(&RM, transform.Rot.y, transform.Rot.x, transform.Rot.z);
	D3DXVec3TransformCoord(&FVec,DefaltForward, &RM);
	ForwardVec = FVec;
	return FVec;
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


