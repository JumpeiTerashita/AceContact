#include "DXUT.h"
#include "Player.h"
#include "../Library/GraphicsManager.h"
#include "../Library/RenderingObject.h"
#include "../support/t2k_support.h"
#include "Bullet.h"
#include "../Library/Mesh.h"

Player::Player()
{
	RenderObj = RenderingObject::Create(new Mesh("SpaceShip_One"));
	ObjectName = "Player";
	SetLifeTime(1);
	transform.Pos = D3DXVECTOR3(0, 0, 0);
	transform.Rot = D3DXVECTOR3(0, 0, 0);
	transform.Scl = D3DXVECTOR3(1, 1, 1);
}


Player::~Player()
{

}



SpPlayer Player::Create()
{
	SpPlayer SpP = SpPlayer(new Player);
	SpP->Wp_this = SpP;
	SpP->SetTransform(SpP, SpP->RenderObj);
	SpP->AddLogicList();
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
		Shoot();
	}
	

	if (DXUTIsKeyDown(VK_LEFT)) {
		
		//transform.Pos.x += -1.0f;
		transform.Rot.y += D3DXToRadian(10.0f);
	}

	if (DXUTIsKeyDown(VK_RIGHT)) {
		//transform.Pos.x += 1.0f;
		transform.Rot.y += D3DXToRadian(-10.0f);
	}

	GetForwardVec(&transform.Rot);

	if (DXUTIsKeyDown(VK_UP)) {
		transform.Pos += ForwardVec;
	}

	if (DXUTIsKeyDown(VK_DOWN)) {
		transform.Pos -= ForwardVec;
	}
}

void Player::Shoot()
{
	t2k::Support::debugTrace("’eŒ‚‚Á‚½‚Ë");
	SpBullet bullet = Bullet::Create();
	bullet->transform.Pos = transform.Pos;
	bullet->transform.Rot = transform.Rot;
	bullet->ForwardVec = ForwardVec;
}

void Player::Delete()
{
	RenderObj->SetLifeTime(0);
	SetLifeTime(0);
}


