#include "DXUT.h"
#include "Enemy_01.h"
#include "../Library/GraphicsManager.h"
#include "../Library/RenderingObject.h"

Enemy_01::Enemy_01()
{
	ObjectName = "EnemyOneRender";
	EnemyOneRender.Pos = D3DXVECTOR3(0, 0, 30);
	EnemyOneRender.Rot = D3DXVECTOR3(0, 3.14, 0);
	EnemyOneRender.Scl = D3DXVECTOR3(0.5, 0.5, 0.5);
	
	SetData();
}


Enemy_01::~Enemy_01()
{
	EnemyOneRender.Tex->Release();
	EnemyOneRender.Mesh->Release();
}

void Enemy_01::SetData()
{
	GraphicsManager* Graphic = GraphicsManager::GetInstance();

	if (Graphic->IsInRenderingTexMap("Fighter.bmp"))
	{
		EnemyOneRender.Tex = *(Graphic->GetTexture("Fighter.bmp"));
	}
	else
	{
		D3DXCreateTextureFromFile(GraphicsManager::GetInstance()->GetDevice(), L"Fighter.bmp", &EnemyOneRender.Tex);
		Graphic->AddTexture("Fighter.bmp", &EnemyOneRender.Tex);
	}

	if (Graphic->IsInRenderingModelMap("Fighter.x"))
	{
		EnemyOneRender.Mesh = *(Graphic->GetModel("Fighter.x"));
	}
	else
	{
		D3DXLoadMeshFromX(L"Fighter.x", D3DXMESH_MANAGED, GraphicsManager::GetInstance()->GetDevice(), NULL, NULL, NULL, NULL, &EnemyOneRender.Mesh);
		Graphic->AddModel("Fighter.x", &EnemyOneRender.Mesh);
	}

	EnemyOneRender.AddRenderList();
	AddLogicList();
	AddLogicMap(ObjectName);
}

void Enemy_01::Update()
{
	Move();
}

void Enemy_01::Move()
{


	if (DXUTIsKeyDown(VK_LEFT)) {
	
		EnemyOneRender.Rot.z += D3DXToRadian(10.0f);
	}

	if (DXUTIsKeyDown(VK_RIGHT)) {
		
		EnemyOneRender.Rot.z += D3DXToRadian(-10.0f);
	}

	
}
