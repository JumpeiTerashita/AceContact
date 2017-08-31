#include "DXUT.h"
#include "Bullet.h"
#include "..\Engine\GameObjectManager.h"
#include "..\Library\GraphicsManager.h"
#include "..\support\t2k_support.h"

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
	//RenderObj->Tex->Release();
	//RenderObj->Mesh->Release();
}

void Bullet::SetData()
{
	wchar_t buf[64];
	t2k::Support::toWideChar(buf, "SpaceShip_One.bmp",sizeof(buf));
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


	
}

SpBullet Bullet::Create()
{
	SpBullet SpB = SpBullet(new Bullet);
	SpB->Wp_this = SpB;
	//SpB->SetData();
	SpB->AddLogicList();
	SpB->SetRenderObj(SpB->RenderObj);
	SpB->AddLogicMap(SpB->ObjectName);
	
	SpB->RenderObj->AddRenderList();

	return SpB;
}



void Bullet::Update()
{
	RenderObj->Pos.z += 1.0f;

	CollisionJudge();

	// TODO ’eÁ‚»‚¤‚Æ‚·‚é‚ÆŽ€‚Ê
	if (RenderObj->Pos.z >= 40)
	{
		RenderObj->SetLifeTime(0);
		SetLifeTime(0);
	}
}

void Bullet::CollisionJudge()
{
	if (!GameObjectManager::GetInstance()->IsInLogicMap("EnemyOne")) return;
	
	
	SpRenderingObject EnemyRenObj = GameObjectManager::GetInstance()->GetMap("EnemyOne")->RenderObjP;



	auto BulletPos = RenderObj->Pos;
	auto EnemyPos = EnemyRenObj->Pos;
	auto Dist = BulletPos - EnemyPos;

	float DistX2 = Dist.x*Dist.x;
	float DistY2 = Dist.y*Dist.y;
	float DistZ2 = Dist.z*Dist.z;
	float DistR = 1 + 1;
	float DistR2 = DistR*DistR;

	if (DistX2 + DistY2 + DistZ2 <= DistR2)
	{
		// Hit
		GameObjectManager::GetInstance()->GetMap("EnemyOne")->DelObj();

		DelObj();
		
	}
	

}
