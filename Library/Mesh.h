#pragma once
#include "RenderingObject.h"

class Mesh : public RenderingObject
{
public:
	Mesh();
	Mesh(std::string _FileName);
	Mesh(std::string _MeshName,std::string _TextureName);
	~Mesh();
	static Mesh* CreateMesh(std::string _MeshName);
	LPDIRECT3DTEXTURE9		Texture;
	LPD3DXMESH				XMesh;
	void Render(Transform* _Ptransform);
	void SetMesh(std::string _FileName);
	void SetTexture(std::string _FileName = "");
	void Del();
};

