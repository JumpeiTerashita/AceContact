#include "DXUT.h"
#include "GraphicsManager.h"

GraphicsManager* GraphicsManager::Instance = nullptr;

GraphicsManager::GraphicsManager()
{
}


GraphicsManager::~GraphicsManager()
{
}

void GraphicsManager::Render(IDirect3DDevice9* pd3dDevice)
{
	std::list< RenderingObject* >::iterator it = RenderingList.begin();
	while (it != RenderingList.end()) {
		(*it)->Render(pd3dDevice);
		/*if (0 == (*it)->getLifeTime())
		{
			delete (*it);
			it = objects.erase(it);
			continue;
		}*/
		it++;
	}
}


