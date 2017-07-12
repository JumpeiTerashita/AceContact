#include <map> 
#include "DXUT.h"
#include "GraphicsManager.h"

GraphicsManager* GraphicsManager::Instance = nullptr;

GraphicsManager::GraphicsManager()
{
}


GraphicsManager::~GraphicsManager()
{
}


void GraphicsManager::AddTexture(std::string _name, LPDIRECT3DTEXTURE9* _tex)
{
	Map_g_pTex.insert(std::make_pair(_name,*_tex));
}

void GraphicsManager::AddModel(std::string _name, LPD3DXMESH* _xmodel)
{
	Map_g_pMesh.insert(std::make_pair(_name, *_xmodel));
}

LPDIRECT3DTEXTURE9* GraphicsManager::GetTexture(std::string _name)
{
	return &Map_g_pTex[_name];
}

LPD3DXMESH*	GraphicsManager::GetModel(std::string _name)
{
	return &Map_g_pMesh[_name];
}


