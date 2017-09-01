#include "DXUT.h"
#include "RenderingObject.h"
#include "GraphicsManager.h"
#include "..\support\t2k_support.h"

RenderingObject::RenderingObject()
{
	isEnable = true;
	LifeTime = -1;
	SetDeviceP(GraphicsManager::GetInstance()->GetDevice());
}


RenderingObject::~RenderingObject()
{
	t2k::Support::debugTrace("Rendering Destruct");
}

SpRenderingObject RenderingObject::Create(RenderingObject* _p)
{
	SpRenderingObject SpP = SpRenderingObject(_p);
	SpP->Wp_this = SpP;
	return SpP;
}

//void RenderingObject::SetData(std::string _FileName)
//{
//	auto Graphic = GraphicsManager::GetInstance();
//
//
//	if (Graphic->IsInRenderingTexMap(_FileName + ".bmp"))
//	{
//		Tex = *(Graphic->GetTexture(_FileName + ".bmp"));
//	}
//	else
//	{
//		wchar_t buf[64];
//		t2k::Support::toWideChar(buf, (_FileName + ".bmp").c_str(), sizeof(buf));
//		D3DXCreateTextureFromFile(GraphicsManager::GetInstance()->GetDevice(), buf, &Tex);
//		Graphic->AddTexture((_FileName + ".bmp"), &Tex);
//	}
//
//	if (Graphic->IsInRenderingModelMap(_FileName + ".x"))
//	{
//		Mesh = *(Graphic->GetModel(_FileName + ".x"));
//	}
//	else
//	{
//		wchar_t xbuf[64];
//		t2k::Support::toWideChar(xbuf, (_FileName + ".x").c_str(), sizeof(xbuf));
//		D3DXLoadMeshFromX(xbuf, D3DXMESH_MANAGED, Graphic->GetDevice(), NULL, NULL, NULL, NULL,&Mesh);
//		Graphic->AddModel((_FileName + ".x"), &Mesh);
//	}
//} 



void RenderingObject::AddRenderList()
{
	SpRenderingObject SpR = Wp_this.lock();
	if (SpR)
	{
		GraphicsManager::GetInstance()->AddList(SpR);
	}
	
}

