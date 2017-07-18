#include "DXUT.h"
#include "Bullet.h"
#include "..\Library\GraphicsManager.h"

Bullet::Bullet()
{
	ObjectName = "Bullet";
	BulletRender.Pos = D3DXVECTOR3(0, 0, 0);
	BulletRender.Rot = D3DXVECTOR3(0, 0, 0);
	BulletRender.Scl = D3DXVECTOR3(1, 1, 1);

	SetData();
}


Bullet::~Bullet()
{
}

void Bullet::SetData()
{

	GraphicsManager* Graphic = GraphicsManager::GetInstance();

	if (Graphic->IsInRenderingTexMap("SpaceShip_One.bmp"))
	{
		BulletRender.Tex = *(Graphic->GetTexture("SpaceShip_One.bmp"));
	}
	else
	{
		D3DXCreateTextureFromFile(GraphicsManager::GetInstance()->GetDevice(), L"SpaceShip_One.bmp", &BulletRender.Tex);
		Graphic->AddTexture("SpaceShip_One.bmp", &BulletRender.Tex);
	}

	if (Graphic->IsInRenderingModelMap("SpaceShip_One.x"))
	{
		BulletRender.Mesh = *(Graphic->GetModel("SpaceShip_One.x"));
	}
	else
	{
		D3DXLoadMeshFromX(L"SpaceShip_One.x", D3DXMESH_MANAGED, Graphic->GetDevice(), NULL, NULL, NULL, NULL, &BulletRender.Mesh);
		Graphic->AddModel("SpaceShip_One.x", &BulletRender.Mesh);
	}

	BulletRender.AddRenderList();
	AddLogicList();
	AddLogicMap(ObjectName);

}

void Bullet::Update()
{
	BulletRender.Pos.z += 1.0f;
}
