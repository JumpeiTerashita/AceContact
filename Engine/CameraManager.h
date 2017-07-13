#pragma once
#include "../Library/Singleton.h"
class CameraManager : public Singleton<CameraManager>
{
public:
	D3DXVECTOR3		vEyePt;
	D3DXVECTOR3		vLookatPt;
	D3DXVECTOR3		vUpVec;
	D3DXMATRIX		gView, gProj;

	CameraManager();
	~CameraManager();

private:
};

