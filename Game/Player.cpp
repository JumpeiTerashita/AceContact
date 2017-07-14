#include "DXUT.h"
#include "Player.h"
#include "../Library/GraphicsManager.h"
#include "../Library/RenderingObject.h"

Player::Player()
{
	PlayerRender.Pos = D3DXVECTOR3(0, 0, 0);
	PlayerRender.Rot = D3DXVECTOR3(0, 0, 0);
	PlayerRender.Scl = D3DXVECTOR3(1, 1, 1);
	D3DXCreateTextureFromFile(GraphicsManager::GetInstance()->GetDevice(), L"spaceship_fighter_CLR.bmp", &PlayerRender.Tex);
	D3DXLoadMeshFromX(L"SpaceShip_Duo.x", D3DXMESH_MANAGED,GraphicsManager::GetInstance()->GetDevice(), NULL, NULL, NULL, NULL, &PlayerRender.Mesh);
	PlayerRender.AddRenderList();
	AddLogicList();
}


Player::~Player()
{
}

void Player::Update()
{

}
