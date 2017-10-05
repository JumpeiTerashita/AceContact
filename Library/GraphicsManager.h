#pragma once
#include "Singleton.h"
#include <list>
#include <map>
#include "RenderingObject.h"

class GraphicsManager : public Singleton<GraphicsManager>
{
public:
	GraphicsManager();
	~GraphicsManager();
	inline void AddList(SpRenderingObject _SpObject) { RenderingList.push_back(_SpObject); }

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
	void Destroy();
	std::list<SpRenderingObject> RenderingList;
private:
	
	std::map<std::string, LPDIRECT3DTEXTURE9*> RenderingTexMap;
	std::map<std::string, LPD3DXMESH*> RenderingModelMap;
};

