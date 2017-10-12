#include "DXUT.h"
#include "Camera.h"


Camera::Camera()
{
	EyePt		= D3DXVECTOR3(0.0f, 3.0f, -15.0f);
	LookatPt	= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	UpVec		= D3DXVECTOR3(0.0f, 1.0f, 0.0f);
}


Camera::~Camera()
{
}

void Camera::SetCamera()
{
	auto pd3dDevice = DXUTGetD3D9Device();
	//-------------------------------------------------------------------------
	// ƒJƒƒ‰Ý’è
	D3DXMatrixLookAtLH(&View, &EyePt, &LookatPt, &UpVec);
	pd3dDevice->SetTransform(D3DTS_VIEW, &View);
	D3DXMatrixPerspectiveFovLH(&Proj, D3DX_PI / 4.0f, 1.0f, 1.0f, 10000.0f);
	pd3dDevice->SetTransform(D3DTS_PROJECTION, &Proj);
}


