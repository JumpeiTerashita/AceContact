#include "DXUT.h"
#include "RenderingObject.h"
#include "GraphicsManager.h"
#include "..\support\t2k_support.h"

using namespace ktb;

RenderingObject::RenderingObject()
{
	isEnable = true;
	LifeTime = -1;
}


RenderingObject::~RenderingObject()
{
	t2k::Support::debugTrace("Rendering Destruct\n");
}

SpRenderingObject RenderingObject::Create(RenderingObject* _p)
{
	SpRenderingObject SpP = SpRenderingObject(_p);
	SpP->Wp_this = SpP;
	return SpP;
}




void RenderingObject::AddRenderList()
{
	SpRenderingObject SpR = Wp_this.lock();
	if (SpR)
	{
		GraphicsManager::GetInstance()->AddList(SpR);
	}
	
}

