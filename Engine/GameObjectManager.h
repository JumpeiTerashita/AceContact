#pragma once
#include <list>
#include "GameObject.h"
#include "../Library/Singleton.h"

class GameObjectManager : public Singleton<GameObjectManager> 
{
public:
	GameObjectManager();
	~GameObjectManager();

	IDirect3DDevice9* Pd3dDevice;

	void Setpd3dDevice(IDirect3DDevice9* pd3dDevice);
	
	void Update();
	void Render();
	inline void AddObject(GameObject* object) { GameObjects.push_back(object); }
private:
	std::list<GameObject*> GameObjects;
};

