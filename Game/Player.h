#pragma once
#include <memory>
#include "..\Engine\GameObject.h"
#include "..\Library\RenderingObject.h"

class Player;
typedef std::shared_ptr<Player> SpPlayer;
class Player : public GameObject
{
public:
 
	SpRenderingObject RenderObj;
	void Update();
	static SpPlayer Create();
	~Player();
private:
	Player();
	void Move();
	void Shoot();
	void Delete();
};


