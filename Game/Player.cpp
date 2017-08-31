#include "DXUT.h"
#include "Player.h"
#include "../Library/GraphicsManager.h"
#include "../Library/RenderingObject.h"
#include "../support/t2k_support.h"
#include "Bullet.h"

Player::Player()
{
	RenderObj = RenderingObject::Create();
	ObjectName = "Player";
	RenderObj->Pos = D3DXVECTOR3(0, 0, 0);
	RenderObj->Rot = D3DXVECTOR3(0, 0, 0);
	RenderObj->Scl = D3DXVECTOR3(1, 1, 1);
}


Player::~Player()
{	
	RenderObj->Tex->Release();
	RenderObj->Mesh->Release();
}



SpPlayer Player::Create()
{
	SpPlayer SpP = SpPlayer(new Player);
	SpP->Wp_this = SpP;
	SpP->RenderObj->SetData("SpaceShip_One");
	SpP->AddLogicList();
	SpP->SetRenderObj(SpP->RenderObj);
	SpP->AddLogicMap("Player");
	
	SpP->RenderObj->AddRenderList();
	
	return SpP;
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
		SpBullet bullet =  Bullet::Create();
		bullet->RenderObj->Pos = RenderObj->Pos;
	}

	if (DXUTIsKeyDown(VK_LEFT)) {
		RenderObj->Pos.x += -1.0f;
		RenderObj->Rot.z += D3DXToRadian(10.0f);
	}

	if (DXUTIsKeyDown(VK_RIGHT)) {
		RenderObj->Pos.x += 1.0f;
		RenderObj->Rot.z += D3DXToRadian(-10.0f);
	}

	if (DXUTIsKeyDown(VK_UP)) {
		RenderObj->Pos.z += 1.0f;
	}

	if (DXUTIsKeyDown(VK_DOWN)) {
		RenderObj->Pos.z += -1.0f;
	}
}
