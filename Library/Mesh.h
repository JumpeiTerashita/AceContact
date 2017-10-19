#pragma once
#include "RenderingObject.h"

namespace ktb
{

	class Mesh : public RenderingObject
	{
	public:
		Mesh();
		Mesh(const std::string& _FileName);
		Mesh(const std::string& _MeshName, const std::string& _TextureName);
		~Mesh();
		static Mesh* CreateMesh(const std::string& _MeshName);
		LPDIRECT3DTEXTURE9		Texture;
		LPD3DXMESH				XMesh;
		void Render(Transform* _Ptransform);
		void SetMesh(const std::string& _FileName);
		void SetTexture(const std::string& _FileName = "");
		void Del();
	};

}