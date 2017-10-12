#include "DXUT.h"
#include "DirectXMass.h"


DirectXMass::DirectXMass()
{
}


DirectXMass::~DirectXMass()
{
}

D3DXVECTOR3 DirectXMass::GetFoward(D3DXVECTOR3* Pos, D3DXVECTOR3* Rot)
{
	// ワールドマトリクス設定
	/*D3DXMATRIX SclMtx, RotMtx, PosMtx, WldMtx;
	D3DXMatrixScaling(&SclMtx, _Ptransform->Scl.x, _Ptransform->Scl.y, _Ptransform->Scl.z);

	D3DXMatrixRotationYawPitchRoll(&RotMtx, _Ptransform->Rot.y, _Ptransform->Rot.x, _Ptransform->Rot.z);
	D3DXMatrixTranslation(&PosMtx, _Ptransform->Pos.x, _Ptransform->Pos.y, _Ptransform->Pos.z);
	WldMtx = SclMtx * RotMtx * PosMtx;
*/

	return D3DXVECTOR3();
}
