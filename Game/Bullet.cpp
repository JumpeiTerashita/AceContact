#include "DXUT.h"
#include "Bullet.h"
#include "..\Engine\GameObjectManager.h"
#include "..\Library\GraphicsManager.h"
#include "..\Library\Mesh.h"
#include "..\support\t2k_support.h"

Bullet::Bullet()
{
	ObjectName = "Bullet";
	RenderObj = RenderingObject::Create(Mesh::CreateMesh("SpaceShip_One"));


	transform.Pos = D3DXVECTOR3(0, 0, 0);

	transform.Rot = D3DXVECTOR3(0, 0, 0);
	transform.Scl = D3DXVECTOR3(1, 1, 1);

	SetLifeTime(100);
}


Bullet::~Bullet()
{
	//RenderObj->Tex->Release();
	//RenderObj->Mesh->Release();
}

SpBullet Bullet::Create()
{
	SpBullet SpB = SpBullet(new Bullet);
	SpB->Wp_this = SpB;
	SpB->SetTransform(SpB, SpB->RenderObj);
	SpB->AddLogicList();
	SpB->AddLogicMap(SpB->ObjectName);
	
	SpB->RenderObj->AddRenderList();

	return SpB;
}



void Bullet::Update()
{


	transform.Pos += GetForwardVec(&transform.Rot);

	CollisionJudge();

	SetLifeTime(GetLifeTime()-1);

	
	if (GetLifeTime() <= 0)
	{
		Delete();
	}

	
}

void Bullet::CollisionJudge()
{
	if (!GameObjectManager::GetInstance()->IsInLogicMap("EnemyOne")) return;
	
	
	auto EnemyTransform = GameObjectManager::GetInstance()->GetMap("EnemyOne")->transform;



	auto BulletPos = transform.Pos;
	auto EnemyPos = EnemyTransform.Pos;
	auto Dist = BulletPos - EnemyPos;

	float DistX2 = Dist.x*Dist.x;
	float DistY2 = Dist.y*Dist.y;
	float DistZ2 = Dist.z*Dist.z;
	float DistR = 1 + 1;
	float DistR2 = DistR*DistR;

	if (DistX2 + DistY2 + DistZ2 <= DistR2)
	{
		// Hit
		GameObjectManager::GetInstance()->GetMap("EnemyOne")->Delete();

		Delete();
		
	}
	

}

void Bullet::Delete()
{
	RenderObj->SetLifeTime(0);
	SetLifeTime(0);
}
