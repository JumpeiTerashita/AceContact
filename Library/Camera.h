#pragma once
class Camera
{
public:
	Camera();
	~Camera();
	void SetCamera(IDirect3DDevice9* pd3dDevice);
	IDirect3DDevice9* Pd3dDevice;
	D3DXVECTOR3		EyePt;
	D3DXVECTOR3		LookatPt;
	D3DXVECTOR3		UpVec;
private:
	D3DXMATRIX		View, Proj;

};

