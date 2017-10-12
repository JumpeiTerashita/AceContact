#pragma once
#include "DXUT.h"

class DirectXMass
{
public:
	DirectXMass();
	~DirectXMass();
	D3DXVECTOR3 GetFoward(D3DXVECTOR3* Pos,D3DXVECTOR3* Rot);
};

