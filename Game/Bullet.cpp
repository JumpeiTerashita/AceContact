#include "DXUT.h"
#include "Bullet.h"
#include "..\Library\GraphicsManager.h"

Bullet::Bullet()
{
	ObjectName = "Bullet";
	RenderObj = RenderingObject::Create();

	RenderObj->Pos = D3DXVECTOR3(0, 0, 0);
	RenderObj->Rot = D3DXVECTOR3(0, 0, 0);
	RenderObj->Scl = D3DXVECTOR3(1, 1, 1);

	SetData();
}


Bullet::~Bullet()
{
	RenderObj->Tex->Release();
	RenderObj->Mesh->Release();
}

void Bullet::SetData()
{

	auto Graphic = GraphicsManager::GetInstance();

	if (Graphic->IsInRenderingTexMap("SpaceShip_One.bmp"))
	{
		RenderObj->Tex = *(Graphic->GetTexture("SpaceShip_One.bmp"));
	}
	else
	{
		D3DXCreateTextureFromFile(GraphicsManager::GetInstance()->GetDevice(), L"SpaceShip_One.bmp", &RenderObj->Tex);
		Graphic->AddTexture("SpaceShip_One.bmp", &RenderObj->Tex);
	}

	if (Graphic->IsInRenderingModelMap("SpaceShip_One.x"))
	{
		RenderObj->Mesh = *(Graphic->GetModel("SpaceShip_One.x"));
	}
	else
	{
		D3DXLoadMeshFromX(L"SpaceShip_One.x", D3DXMESH_MANAGED, Graphic->GetDevice(), NULL, NULL, NULL, NULL, &RenderObj->Mesh);
		Graphic->AddModel("SpaceShip_One.x", &RenderObj->Mesh);
	}


	AddLogicList();
	AddLogicMap(ObjectName);

}

SpBullet Bullet::Create()
{
	SpBullet SpB = SpBullet(new Bullet);
	SpB->Wp_this = SpB;


	SpB->RenderObj->AddRenderList();

	return SpB;
}



void Bullet::Update()
{
	RenderObj->Pos.z += 1.0f;

	// TODO ’eÁ‚»‚¤‚Æ‚·‚é‚ÆŽ€‚Ê
	if (RenderObj->Pos.z >= 40)
	{
		RenderObj->SetLifeTime(0);
		SetLifeTime(0);
	
	}
}
