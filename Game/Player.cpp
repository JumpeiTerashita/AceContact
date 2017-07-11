#include "DXUT.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::Update()
{
	TestSpin();
	return;
}

void Player::TestSpin()
{
	g_rot.x += D3DXToRadian(1.0f);
	g_rot.y += D3DXToRadian(1.0f);
	g_rot.z += D3DXToRadian(1.0f);
	return;
}
