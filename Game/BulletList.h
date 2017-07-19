#pragma once

#include <list>
#include "..\Engine\GameObject.h"
#include "..\Library\RenderingObject.h"
#include "..\Library\Singleton.h"

enum POTENCY
{
	POTENCY_ALLY,
	POTENCY_ENEMY
};

class BulletList:public GameObject,public RenderingObject,public Singleton<BulletList>
{
public:
	BulletList();
	~BulletList();

	std::list<GameObject*> AllyBulletLogicList;
	std::list<GameObject*> EnemyBulletLogicList;
	std::list<RenderingObject*> AllyBulletRenderList;
	std::list<RenderingObject*> EnemyBulletRenderList;
	void AddLogicList(GameObject* _pBullet, POTENCY _Potency);
	void AddRenderList(RenderingObject* _pBulletRender, POTENCY _Potency);
	void SetData();
	void Update();
	void Render(IDirect3DDevice9* pd3dDevice);
	void RunLogicIterator(std::list<GameObject*> _List);
	void RunRenderIterator(std::list<RenderingObject*> _List,IDirect3DDevice9* pd3dDevice);
};

