#include "DXUT.h"
#include "Player.h"
#include "../Library/GraphicsManager.h"
#include "../Library/RenderingObject.h"

Player::Player()
{
	PlayerRender.Pos = D3DXVECTOR3(0, 0, 0);
	PlayerRender.Rot = D3DXVECTOR3(0, 0, 0);
	PlayerRender.Scl = D3DXVECTOR3(1, 1, 1);
	
	SetData();
}


Player::~Player()
{
}

void Player::SetData()
{
	GraphicsManager* Graphic = GraphicsManager::GetInstance();

	if (Graphic->IsInRenderingTexMap("spaceship_fighter_CLR.bmp"))
	{
		PlayerRender.Tex = *(Graphic->GetTexture("spaceship_fighter_CLR.bmp"));
	}
	else 
	{
		D3DXCreateTextureFromFile(GraphicsManager::GetInstance()->GetDevice(), L"spaceship_fighter_CLR.bmp", &PlayerRender.Tex);
		Graphic->AddTexture("spaceship_fighter_CLR.bmp",&PlayerRender.Tex);
	}

	if (Graphic->IsInRenderingModelMap("SpaceShip_Duo.x"))
	{
		PlayerRender.Mesh = *(Graphic->GetModel("SpaceShip_Duo.x"));
	}
	else
	{
		D3DXLoadMeshFromX(L"SpaceShip_Duo.x", D3DXMESH_MANAGED, GraphicsManager::GetInstance()->GetDevice(), NULL, NULL, NULL, NULL, &PlayerRender.Mesh);
		Graphic->AddModel("SpaceShip_Duo.x", &PlayerRender.Mesh);
	}

	PlayerRender.AddRenderList();
	AddLogicList();
	
}

void Player::Update()
{
	Move();
}

void Player::Move()
{
	

	if (DXUTIsKeyDown(VK_LEFT)) {
		PlayerRender.Pos.x += -1.0f;
		PlayerRender.Rot.z += D3DXToRadian(10.0f);
	}

	if (DXUTIsKeyDown(VK_RIGHT)) {
		PlayerRender.Pos.x += 1.0f;
		PlayerRender.Rot.z += D3DXToRadian(-10.0f);
	}

	if (DXUTIsKeyDown(VK_UP)) {
		PlayerRender.Pos.z += 1.0f;
	}

	if (DXUTIsKeyDown(VK_DOWN)) {
		PlayerRender.Pos.z += -1.0f;
	}
}
