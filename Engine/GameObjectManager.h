#pragma once
#include "GameObject.h"
#include <list>

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	IDirect3DDevice9* Pd3dDevice;

	void Setpd3dDevice(IDirect3DDevice9* pd3dDevice);
	static GameObjectManager* GetInstance();
	void Update();
	void Render();
	inline void AddObject(GameObject* object) { GameObjects.push_back(object); }
private:
	
	static GameObjectManager* Instance;
	std::list<GameObject*> GameObjects;
};

