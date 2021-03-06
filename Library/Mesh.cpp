#include "DXUT.h"
#include "Mesh.h"
#include "GraphicsManager.h"
#include "..\support\t2k_support.h"
#include "Transform.h"

//	HACK	設計を楽しもう
//	ライブラリ

using namespace ktb;

Mesh::Mesh()
{

}

Mesh::Mesh(const std::string& _FileName)
{
	SetMesh(_FileName);
	SetTexture(_FileName);
}

Mesh::Mesh(const std::string& _MeshName, const std::string& _TextureName)
{
	SetMesh(_MeshName);
	SetTexture(_TextureName);
}

Mesh::~Mesh()
{
	//Texture->Release();
	//XMesh->Release();
}

Mesh * Mesh::CreateMesh(const std::string& _MeshName)
{
	//	メッシュだけつくりたいとき用
	Mesh* tmp = new Mesh();
	tmp->SetMesh(_MeshName);
	tmp->SetTexture();

	return tmp;
}

void Mesh::SetMesh(const std::string& _FileName)
{
	auto Graphic = GraphicsManager::GetInstance();
	if (Graphic->IsInRenderingModelMap(_FileName + ".x"))	XMesh = *(Graphic->GetModel(_FileName + ".x"));
	else
	{
		wchar_t xbuf[64];
		t2k::Support::toWideChar(xbuf, (_FileName + ".x").c_str(), sizeof(xbuf));
		D3DXLoadMeshFromX(xbuf, D3DXMESH_MANAGED, DXUTGetD3D9Device(), NULL, NULL, NULL, NULL, &XMesh);
		Graphic->AddModel((_FileName + ".x"), &XMesh);
	}
}

void Mesh::SetTexture(const std::string& _FileName)
{
	auto Graphic = GraphicsManager::GetInstance();

	if (_FileName == "")
	{
		Texture = NULL;
		if (!Graphic->IsInRenderingTexMap("Undefined")) Graphic->AddTexture(("Undefined"), &Texture);
		return;
	}

	if (Graphic->IsInRenderingTexMap(_FileName + ".bmp")) Texture = *(Graphic->GetTexture(_FileName + ".bmp")); 
	else
	{
		wchar_t buf[64];
		t2k::Support::toWideChar(buf, (_FileName + ".bmp").c_str(), sizeof(buf));
		D3DXCreateTextureFromFile(DXUTGetD3D9Device(), buf, &Texture);
		Graphic->AddTexture((_FileName + ".bmp"), &Texture);
	}
}

void Mesh::Render(Transform* _Ptransform)
{
	if (!isEnable||GetLifeTime()==0) return;

	HRESULT hr;

	// ワールドマトリクス設定
	D3DXMATRIX SclMtx, RotMtx, PosMtx, WldMtx;
	D3DXMatrixScaling(&SclMtx, _Ptransform->Scl.x, _Ptransform->Scl.y, _Ptransform->Scl.z);

	D3DXMatrixRotationYawPitchRoll(&RotMtx, _Ptransform->Rot.y, _Ptransform->Rot.x, _Ptransform->Rot.z);
	D3DXMatrixTranslation(&PosMtx, _Ptransform->Pos.x, _Ptransform->Pos.y, _Ptransform->Pos.z);
	WldMtx = SclMtx * RotMtx * PosMtx;

	auto pd3dDevice = DXUTGetD3D9Device();

	// テクスチャ適用
	if(Texture != NULL) pd3dDevice->SetTexture( 0, Texture ) ;
	else pd3dDevice->SetTexture(0, 0);

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
			XMesh->DrawSubset( 0 ) ;
	       V( pd3dDevice->EndScene() );
	   }
}

void Mesh::Del()
{
	Texture->Release();
	XMesh->Release();
}
