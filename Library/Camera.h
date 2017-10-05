#include "Transform.h"

#pragma once
class Camera
{
public:
	Camera();
	~Camera();
	void SetCamera();
	D3DXVECTOR3		EyePt;
	D3DXVECTOR3		LookatPt;
	D3DXVECTOR3		UpVec;
private:
	D3DXMATRIX		View, Proj;
};

