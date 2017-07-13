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



