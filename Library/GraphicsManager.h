#pragma once

#include <map> 
#include "../Library/Singleton.h"

class GraphicsManager : public Singleton<GraphicsManager>
{
public:
	GraphicsManager();
	~GraphicsManager();


	void AddTexture(std::string _name, LPDIRECT3DTEXTURE9* _tex);
	void AddModel(std::string _name, LPD3DXMESH* _xmodel);

	LPDIRECT3DTEXTURE9* GetTexture(std::string _name);
	LPD3DXMESH*	GetModel(std::string _name);

private:
	
	std::map<std::string, LPDIRECT3DTEXTURE9> Map_g_pTex;
	std::map<std::string, LPD3DXMESH> Map_g_pMesh;
};

