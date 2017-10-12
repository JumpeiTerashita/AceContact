#include "DXUT.h"
#include "GraphicsManager.h"
#include "RenderingObject.h"
#include <memory>


std::shared_ptr<GraphicsManager> GraphicsManager::Instance = nullptr;

GraphicsManager::GraphicsManager()
{
}


GraphicsManager::~GraphicsManager()
{
}

void GraphicsManager::Destroy()
{
	std::list< SpRenderingObject >::iterator it = RenderingList.begin();
	while (it != RenderingList.end()) {
		(*it)->Del();
		it++;
	}
}

void GraphicsManager::Render()
{
	std::list< SpRenderingObject >::iterator it = RenderingList.begin();
	while (it != RenderingList.end()) {
		(*it)->Render((*it)->Ptransform);
		if (0 == (*it)->GetLifeTime())
		{
			//delete (*it);
			it = RenderingList.erase(it);
			continue;
		}
		it++;
	}
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




