#include "DXUT.h"
#include "GameObjectManager.h"

GameObjectManager* GameObjectManager::Instance = nullptr;

GameObjectManager::GameObjectManager()
{
}


GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::Setpd3dDevice(IDirect3DDevice9* pd3dDevice)
{
	Pd3dDevice = pd3dDevice;
	return;
}

GameObjectManager* GameObjectManager::GetInstance()
{
	if (nullptr == GameObjectManager::Instance)
	{
		GameObjectManager::Instance = new GameObjectManager();
	}
	return GameObjectManager::Instance;
}

void GameObjectManager::Update()
{
	std::list< GameObject* >::iterator it = GetInstance()->GameObjects.begin();

	while (it != GameObjects.end()) {
		(*it)->Update();

		it++;
	}
}

void GameObjectManager::Render()
{
	std::list< GameObject* >::iterator it = GetInstance()->GameObjects.begin();

	while (it != GameObjects.end()) {
		(*it)->Render(Pd3dDevice);

		it++;
	}
}
