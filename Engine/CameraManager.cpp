#include "DXUT.h"
#include "CameraManager.h"

CameraManager* CameraManager::Instance = nullptr;

CameraManager::CameraManager()
{
	vEyePt		= D3DXVECTOR3(0.0f, 3.0f, -20.0f);
	vLookatPt	= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vUpVec		= D3DXVECTOR3(0.0f, 1.0f, 0.0f);

}

CameraManager::~CameraManager()
{
}
