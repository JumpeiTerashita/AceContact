#pragma once
#include "../Engine/GameObject.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	void Update();
	void TestSpin();
};

