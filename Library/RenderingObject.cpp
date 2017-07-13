#include "DXUT.h"
#include "RenderingObject.h"


RenderingObject::RenderingObject()
{
	isEnable = true;
	Pos = D3DXVECTOR3(0, 0, 0);
	Rot = D3DXVECTOR3(0, 0, 0);
	Scl = D3DXVECTOR3(1, 1, 1);
}


RenderingObject::~RenderingObject()
{
}

void RenderingObject::Render(IDirect3DDevice9* pd3dDevice)
{
	if (!isEnable) return;

	HRESULT hr;

	// ワールドマトリクス設定
	D3DXMATRIX SclMtx, RotMtx, PosMtx, WldMtx ;
	D3DXMatrixScaling( &SclMtx, Scl.x, Scl.y, Scl.z );

	D3DXMatrixRotationYawPitchRoll( &RotMtx, Rot.y, Rot.x, Rot.z ) ;
	D3DXMatrixTranslation( &PosMtx, Pos.x, Pos.y, Pos.z ) ;
	WldMtx = SclMtx * RotMtx * PosMtx ;

	// テクスチャ適用
	pd3dDevice->SetTexture( 0, Tex ) ;

	// 通常合成
	pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE ) ;
	pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1 ) ;
	pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE ) ;
	pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA ) ;	
	pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA ) ;

	//ライティングOFF
	pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	pd3dDevice->LightEnable( 0, FALSE ) ;

	pd3dDevice->SetTransform( D3DTS_WORLD, &WldMtx );

	   // Render the scene
	   if( SUCCEEDED( pd3dDevice->BeginScene() ) )
	   {
		Mesh->DrawSubset( 0 ) ;
	       V( pd3dDevice->EndScene() );
	   }
}
