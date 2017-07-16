#include "DXUT.h"
#include "GraphicsManager.h"
#include "RenderingObject.h"

GraphicsManager* GraphicsManager::Instance = nullptr;

GraphicsManager::GraphicsManager()
{
}


GraphicsManager::~GraphicsManager()
{
}

void GraphicsManager::Render()
{
	std::list< RenderingObject* >::iterator it = RenderingList.begin();
	while (it != RenderingList.end()) {
		(*it)->Render(Pd3dDevice);
		/*if (0 == (*it)->getLifeTime())
		{
			delete (*it);
			it = objects.erase(it);
			continue;
		}*/
		it++;
	}
}

void GraphicsManager::AddTexture(std::string _name, LPDIRECT3DTEXTURE9* _tex)
{
	RenderingTexMap.insert(std::make_pair(_name, _tex));
}

void GraphicsManager::AddModel(std::string _name, LPD3DXMESH* _xmodel)
{
	RenderingModelMap.insert(std::make_pair(_name, _xmodel));
}

LPDIRECT3DTEXTURE9* GraphicsManager::GetTexture(std::string _name)
{
	return RenderingTexMap[_name];
}

LPD3DXMESH*	GraphicsManager::GetModel(std::string _name)
{
	return RenderingModelMap[_name];
}

bool GraphicsManager::IsInRenderingTexMap(std::string _name)
{
	auto itr = RenderingTexMap.find(_name);
	if (itr != RenderingTexMap.end()) return true;
	else return false;
}

bool GraphicsManager::IsInRenderingModelMap(std::string _name)
{
	auto itr = RenderingModelMap.find(_name);
	if (itr != RenderingModelMap.end()) return true;
	else return false;
}




