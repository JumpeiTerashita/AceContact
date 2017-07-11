#pragma once
class GameObject
{
public:
	GameObject();
	
	virtual ~GameObject();


	//---------------------------------------------------------------------
	//
	// X ƒtƒ@ƒCƒ‹
	//
	LPDIRECT3DTEXTURE9		g_pTex;
	LPD3DXMESH				g_pMesh;
	D3DXVECTOR3				g_rot;
	D3DXVECTOR3				g_pos;
	D3DXVECTOR3				g_scl;

	virtual void Update() = 0;

	void Render(IDirect3DDevice9* pd3dDevice);
};

