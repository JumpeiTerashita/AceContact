#include "DXUT.h"
#include "GameCamera.h"

GameCamera::GameCamera()
{
	ObjectName = "GameCamera";
	CameraMode = 1;
	CameraStatus = *(new Camera());

}

SpGameCamera GameCamera::Create()
{
	SpGameCamera SpGC = SpGameCamera(new GameCamera);
	SpGC->Wp_this = SpGC;
	SpGC->AddLogicList();
	SpGC->AddLogicMap(SpGC->ObjectName);
	return SpGC;
}

void GameCamera::Update()
{
	Move();
	CameraStatus.SetCamera();
}

void GameCamera::Move()
{
	if (CameraMode == 1) return;

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
	
}
