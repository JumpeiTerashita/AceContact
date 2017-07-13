#pragma once
class RenderingObject
{
public:
	RenderingObject();
	~RenderingObject();
	LPDIRECT3DTEXTURE9		Tex;
	LPD3DXMESH				Mesh;
	D3DXVECTOR3				Rot;
	D3DXVECTOR3				Pos;
	D3DXVECTOR3				Scl;
	bool isEnable;
	void Render(IDirect3DDevice9* pd3dDevice);
	void AddRenderList();
};

