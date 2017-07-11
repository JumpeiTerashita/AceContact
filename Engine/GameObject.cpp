#include "DXUT.h"
#include "GameObject.h"
#include "../Library/GraphicsManager.h"

GameObject::GameObject()
{
	g_rot = D3DXVECTOR3(0, 0, 0);
	g_pos = D3DXVECTOR3(0, 0, 0);
	g_scl = D3DXVECTOR3(1,1,1);
}


GameObject::~GameObject()
{
}

void GameObject::Render(IDirect3DDevice9* pd3dDevice)
{
	HRESULT hr;
	// ワールドマトリクス設定
	D3DXMATRIX SclMtx, RotMtx, PosMtx, WldMtx;
	D3DXMatrixScaling(&SclMtx, g_scl.x, g_scl.y, g_scl.z);

	D3DXMatrixRotationYawPitchRoll(&RotMtx, g_rot.y, g_rot.x, g_rot.z);
	D3DXMatrixTranslation(&PosMtx, g_pos.x, g_pos.y, g_pos.z);
	WldMtx = SclMtx * RotMtx * PosMtx;

	// テクスチャ適用
	pd3dDevice->SetTexture(0, g_pTex);

	// 通常合成
	pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//ライティングOFF
	pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	pd3dDevice->LightEnable(0, FALSE);

	pd3dDevice->SetTransform(D3DTS_WORLD, &WldMtx);

	// Render the scene
	if (SUCCEEDED(pd3dDevice->BeginScene()))
	{
		g_pMesh->DrawSubset(0);
		V(pd3dDevice->EndScene());
	}
}
