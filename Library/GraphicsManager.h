#pragma once
#include "Singleton.h"
#include "RenderingObject.h"
#include <list>
#include <map>

class GraphicsManager : public Singleton<GraphicsManager>
{
public:
	GraphicsManager();
	~GraphicsManager();
	std::list<RenderingObject*> RenderingList;
	void Render(IDirect3DDevice9* pd3dDevice);
private:
};

