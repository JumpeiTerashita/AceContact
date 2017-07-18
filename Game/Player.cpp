#include "DXUT.h"
#include "Player.h"
#include "../Library/GraphicsManager.h"
#include "../Library/RenderingObject.h"
#include "../support/t2k_support.h"
#include "Bullet.h"

Player::Player()
{
	ObjectName = "Player";
	PlayerRender.Pos = D3DXVECTOR3(0, 0, 0);
	PlayerRender.Rot = D3DXVECTOR3(0, 0, 0);
	PlayerRender.Scl = D3DXVECTOR3(1, 1, 1);
	
	SetData();
}


Player::~Player()
{
	PlayerRender.Tex->Release();
	PlayerRender.Mesh->Release();
}

void Player::SetData()
{
	GraphicsManager* Graphic = GraphicsManager::GetInstance();

	if (Graphic->IsInRenderingTexMap("SpaceShip_One.bmp"))
	{
		PlayerRender.Tex = *(Graphic->GetTexture("SpaceShip_One.bmp"));
	}
	else 
	{
		D3DXCreateTextureFromFile(GraphicsManager::GetInstance()->GetDevice(), L"SpaceShip_One.bmp", &PlayerRender.Tex);
		Graphic->AddTexture("SpaceShip_One.bmp",&PlayerRender.Tex);
	}

	if (Graphic->IsInRenderingModelMap("SpaceShip_One.x"))
	{
		PlayerRender.Mesh = *(Graphic->GetModel("SpaceShip_One.x"));
	}
	else
	{
		D3DXLoadMeshFromX(L"SpaceShip_One.x", D3DXMESH_MANAGED, GraphicsManager::GetInstance()->GetDevice(), NULL, NULL, NULL, NULL, &PlayerRender.Mesh);
		Graphic->AddModel("SpaceShip_One.x", &PlayerRender.Mesh);
	}

	PlayerRender.AddRenderList();
	AddLogicList();
	AddLogicMap(ObjectName);
}

void Player::Update()
{
	Move();
}

void Player::Move()
{
	if (DXUTWasKeyPressed('K')) {
		//	LogicMap Test
		t2k::Support::debugTrace("’eŒ‚‚Á‚½‚Ë");
		Bullet * bullet = new Bullet();
	}

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
