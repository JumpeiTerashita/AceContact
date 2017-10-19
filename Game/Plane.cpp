#include "DXUT.h"
#include "Plane.h"
#include "..\Library\Mesh.h"

using namespace ktb;

Plane::Plane()
{
	ObjectName = "Plane";
	RenderObj = RenderingObject::Create(Mesh::CreateMesh("box1"));
	SetLifeTime(1);
	transform.Pos = D3DXVECTOR3(0, -5, 0);
	transform.Rot = D3DXVECTOR3(0, 0, 0);
	transform.Scl = D3DXVECTOR3(10, 1, 10);
}


Plane::~Plane()
{
}

void Plane::Delete()
{
	RenderObj->SetLifeTime(0);
	SetLifeTime(0);
}

SpPlane Plane::Create()
{
	SpPlane SpPl = SpPlane(new Plane);
	SpPl->Wp_this = SpPl;
	SpPl->SetTransform(SpPl, SpPl->RenderObj);
	SpPl->AddLogicList();
	SpPl->AddLogicMap("Plane");

	SpPl->RenderObj->AddRenderList();

	return SpPl;
}

void Plane::Update()
{
}
