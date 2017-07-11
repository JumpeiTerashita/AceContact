#pragma once
class CameraManager
{
public:
	D3DXVECTOR3		vEyePt;
	D3DXVECTOR3		vLookatPt;
	D3DXVECTOR3		vUpVec;
	D3DXMATRIX		gView, gProj;

	CameraManager();
	~CameraManager();
	static CameraManager* GetInstance();
private:
	static CameraManager* Instance;
};

