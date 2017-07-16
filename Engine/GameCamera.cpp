#include "DXUT.h"
#include "GameCamera.h"


GameCamera* GameCamera::Instance = nullptr;

GameCamera::GameCamera()
{
	ObjectName = "GameCamera";
	CameraMode = 1;
	CameraStatus = *(new Camera());
	AddLogicList();
	AddLogicMap(ObjectName);
}


GameCamera::~GameCamera()
{
}

void GameCamera::Update()
{
	Move();
	CameraStatus.SetCamera(CameraStatus.Pd3dDevice);
}

void GameCamera::Move()
{
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
