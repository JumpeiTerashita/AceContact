#pragma once
#include "RenderingObject.h"

class Mesh : public RenderingObject
{
public:
	Mesh();
	~Mesh();
	LPDIRECT3DTEXTURE9		Texture;
	LPD3DXMESH				XMesh;
	
};

