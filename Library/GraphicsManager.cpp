#include "DXUT.h"
#include "GraphicsManager.h"
#include "RenderingObject.h"

GraphicsManager* GraphicsManager::Instance = nullptr;

GraphicsManager::GraphicsManager()
{
}


GraphicsManager::~GraphicsManager()
{
	//TODO Mapのリリース　どうやって？
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




