#include "DXUT.h"
#include "Enemy_01.h"
#include "../Library/GraphicsManager.h"
#include "../Library/RenderingObject.h"

Enemy_01::Enemy_01()
{
	ObjectName = "EnemyOne";
	
	RenderObj = RenderingObject::Create();
	RenderObj->Pos = D3DXVECTOR3(0, 0, 30);
	RenderObj->Rot = D3DXVECTOR3(0, 3.14, 0);
	RenderObj->Scl = D3DXVECTOR3(0.5, 0.5, 0.5);
	
}


Enemy_01::~Enemy_01()
{


	RenderObj->Tex->Release();
	RenderObj->Mesh->Release();
}

void Enemy_01::SetData()
{
	auto Graphic = GraphicsManager::GetInstance();

	if (Graphic->IsInRenderingTexMap("Fighter.bmp"))
	{
		RenderObj->Tex = *(Graphic->GetTexture("Fighter.bmp"));
	}
	else
	{
		D3DXCreateTextureFromFile(GraphicsManager::GetInstance()->GetDevice(), L"Fighter.bmp", &RenderObj->Tex);
		Graphic->AddTexture("Fighter.bmp", &RenderObj->Tex);
	}

	if (Graphic->IsInRenderingModelMap("Fighter.x"))
	{
		RenderObj->Mesh = *(Graphic->GetModel("Fighter.x"));
	}
	else
	{
		D3DXLoadMeshFromX(L"Fighter.x", D3DXMESH_MANAGED, GraphicsManager::GetInstance()->GetDevice(), NULL, NULL, NULL, NULL, &RenderObj->Mesh);
		Graphic->AddModel("Fighter.x", &RenderObj->Mesh);
	}

	
}

SpEnemy_01 Enemy_01::Create()
{
	SpEnemy_01 SpE = SpEnemy_01(new Enemy_01);
	SpE->Wp_this = SpE;
	SpE->SetData();
	SpE->RenderObj->AddRenderList();
	SpE->SetRenderObj(SpE->RenderObj);
	SpE->AddLogicList();
	SpE->AddLogicMap(SpE->ObjectName);
	return SpE;
}

void Enemy_01::Update()
{
	Move();
}

void Enemy_01::Move()
{


	if (DXUTIsKeyDown(VK_LEFT)) {
	
		RenderObj->Rot.z += D3DXToRadian(10.0f);
	}

	if (DXUTIsKeyDown(VK_RIGHT)) {
		
		RenderObj->Rot.z += D3DXToRadian(-10.0f);
	}

	
}
