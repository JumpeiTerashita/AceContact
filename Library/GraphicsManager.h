#pragma once
#include "Singleton.h"
#include <list>
#include <map>

class RenderingObject;

class GraphicsManager : public Singleton<GraphicsManager>
{
public:
	GraphicsManager();
	~GraphicsManager();
	inline void AddList(RenderingObject* _pObject) { RenderingList.push_back(_pObject); }
	inline void SetDevice(IDirect3DDevice9* pd3dDevice) { Pd3dDevice = pd3dDevice; }
	inline IDirect3DDevice9* GetDevice() { return Pd3dDevice; }
	void Render();
private:
	std::list<RenderingObject*> RenderingList;
	IDirect3DDevice9* Pd3dDevice;
};

