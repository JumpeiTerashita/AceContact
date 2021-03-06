#include "DXUT.h"
#include "Enemy_01.h"
#include "../Library/GraphicsManager.h"
#include "../Library/RenderingObject.h"
#include "../Library/Mesh.h"
#include "Bullet.h"

using namespace ktb;

Enemy_01::Enemy_01()
{
	ObjectName = "EnemyOne";
	
	RenderObj = RenderingObject::Create(new Mesh("Fighter"));
	SetLifeTime(1);
	transform.Pos = D3DXVECTOR3(0, 0, 30);
	transform.Rot = D3DXVECTOR3(0, 3.14, 0);
	transform.Scl = D3DXVECTOR3(0.5, 0.5, 0.5);
	
}

Enemy_01::~Enemy_01()
{


	
}

SpEnemy_01 Enemy_01::Create()
{
	SpEnemy_01 SpE = SpEnemy_01(new Enemy_01);
	SpE->Wp_this = SpE;
	SpE->SetTransform(SpE, SpE->RenderObj);
	SpE->RenderObj->AddRenderList();
	SpE->AddLogicList();
	SpE->AddLogicMap(SpE->ObjectName);
	return SpE;
}

void Enemy_01::Update()
{
	Move();
	Shoot();
}

void Enemy_01::Shoot()
{
	if (Timer>= 50)
	{
		Timer = 0;
		SpBullet bullet = Bullet::Create(transform);
		bullet->isEnemys = true;
	}

}

void Enemy_01::Move()
{


	if (DXUTIsKeyDown(VK_LEFT)) {
	
		transform.Rot.z += D3DXToRadian(10.0f);
	}

	if (DXUTIsKeyDown(VK_RIGHT)) {
		
		transform.Rot.z += D3DXToRadian(-10.0f);
	}

	
}

void Enemy_01::Delete()
{
	RenderObj->SetLifeTime(0);
	SetLifeTime(0);
}
