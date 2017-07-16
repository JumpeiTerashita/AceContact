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

	inline void AddTexture(std::string _name, LPDIRECT3DTEXTURE9* _tex) {
		RenderingTexMap.insert(std::make_pair(_name, _tex));
	}
	inline void AddModel(std::string _name, LPD3DXMESH* _xmodel) {
		RenderingModelMap.insert(std::make_pair(_name, _xmodel));
	}

	inline LPDIRECT3DTEXTURE9* GetTexture(std::string _name)
	{
		return RenderingTexMap[_name];
	}

	inline LPD3DXMESH* GetModel(std::string _name)
	{
		return RenderingModelMap[_name];
	}

	bool IsInRenderingTexMap(std::string _name);
	bool IsInRenderingModelMap(std::string _name);
	void Render();
private:
	std::list<RenderingObject*> RenderingList;
	std::map<std::string, LPDIRECT3DTEXTURE9*> RenderingTexMap;
	std::map<std::string, LPD3DXMESH*> RenderingModelMap;
	IDirect3DDevice9* Pd3dDevice;
};

