#include "DXUT.h"
#include "BulletList.h"
#include "Bullet.h"
#include "..\Library\GraphicsManager.h"

BulletList* BulletList::Instance = nullptr;

BulletList::BulletList()
{
	isEnable = false;
	GameObject::AddLogicList();
	SetData();
	
}


BulletList::~BulletList()
{
}

void BulletList::SetData()
{
	GraphicsManager* Graphic = GraphicsManager::GetInstance();

	if (Graphic->IsInRenderingTexMap("SpaceShip_One.bmp"))
	{
		Tex = *(Graphic->GetTexture("SpaceShip_One.bmp"));
	}
	else
	{
		D3DXCreateTextureFromFile(GraphicsManager::GetInstance()->GetDevice(), L"SpaceShip_One.bmp", &Tex);
		Graphic->AddTexture("SpaceShip_One.bmp", &Tex);
	}

	if (Graphic->IsInRenderingModelMap("SpaceShip_One.x"))
	{
		Mesh = *(Graphic->GetModel("SpaceShip_One.x"));
	}
	else
	{
		D3DXLoadMeshFromX(L"SpaceShip_One.x", D3DXMESH_MANAGED, Graphic->GetDevice(), NULL, NULL, NULL, NULL, &Mesh);
		Graphic->AddModel("SpaceShip_One.x", &Mesh);
	}
}

void BulletList::AddLogicList(GameObject* _pBullet, POTENCY _Potency)
{
	if (_Potency == POTENCY_ALLY)  AllyBulletLogicList.push_back(_pBullet);
	else EnemyBulletLogicList.push_back(_pBullet);
}

void BulletList::AddRenderList(RenderingObject* _pBulletRender, POTENCY _Potency)
{
	if (_Potency == POTENCY_ALLY)  AllyBulletRenderList.push_back(_pBulletRender);
	else EnemyBulletRenderList.push_back(_pBulletRender);
}

void BulletList::Update()
{
	RunLogicIterator(AllyBulletLogicList);
	RunLogicIterator(EnemyBulletLogicList);
}



void BulletList::Render(IDirect3DDevice9* pd3dDevice)
{
	RunRenderIterator(AllyBulletRenderList, pd3dDevice);
	RunRenderIterator(EnemyBulletRenderList, pd3dDevice);
}

void BulletList::RunLogicIterator(std::list<GameObject*> _List)
{
	std::list< GameObject* >::iterator it = _List.begin();
	while (it != _List.end()) {
		(*it)->Update();
		if (0 == (*it)->GetLifeTime())
		{
			delete (*it);
			it = _List.erase(it);
			continue;
		}
		it++;
	}
}

void BulletList::RunRenderIterator(std::list<RenderingObject*> _List, IDirect3DDevice9* pd3dDevice)
{
	std::list< RenderingObject* >::iterator it = _List.begin();
	while (it != _List.end()) {
		(*it)->Render(pd3dDevice);
		if (0 == (*it)->GetLifeTime())
		{
			delete (*it);
			it = _List.erase(it);
			continue;
		}
		it++;
	}
}
