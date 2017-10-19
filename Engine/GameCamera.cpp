#include "DXUT.h"
#include "GameCamera.h"
#include "GameObjectManager.h"

using namespace ktb;

GameCamera::GameCamera()
{
	ObjectName = "GameCamera";
	CameraMode = 1;
	CameraStatus = *(new Camera());
	transform.Pos = D3DXVECTOR3(CameraStatus.EyePt);
}

SpGameCamera GameCamera::Create()
{
	SpGameCamera SpGC = SpGameCamera(new GameCamera);
	SpGC->Wp_this = SpGC;
	SpGC->AddLogicList();
	SpGC->AddLogicMap(SpGC->ObjectName);
	return SpGC;
}

void GameCamera::Delete()
{
	
	SetLifeTime(0);
}

void GameCamera::Update()
{
	
	Move();

	CameraStatus.SetCamera();
}

void GameCamera::Move()
{
	auto GOMng = GameObjectManager::GetInstance();
	
	transform.Pos=GOMng->GetMap("Player")->transform.Pos + D3DXVECTOR3(0.0f, 3.0f, -15.0f);
	CameraStatus.EyePt = transform.Pos;
	CameraStatus.LookatPt = GOMng->GetMap("Player")->transform.Pos;
	/*if (CameraMode == 1) return;

	if (CameraMode == 0)
	{
		if (DXUTIsKeyDown(VK_LEFT)) {
			CameraStatus.EyePt.x += -1.0f;
			CameraStatus.LookatPt.x += -1.0f;
		}

		if (DXUTIsKeyDown(VK_RIGHT)) {
			CameraStatus.EyePt.x += 1.0f;
			CameraStatus.LookatPt.x += 1.0f;
		}

		if (DXUTIsKeyDown(VK_UP)) {

			CameraStatus.EyePt.z += 1.0f;
			CameraStatus.LookatPt.z += 1.0f;
		}

		if (DXUTIsKeyDown(VK_DOWN)) {

			CameraStatus.EyePt.z += -1.0f;
			CameraStatus.LookatPt.z += -1.0f;
		}
	}
	*/
}
