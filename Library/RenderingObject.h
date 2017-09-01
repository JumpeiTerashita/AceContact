#pragma once
#include <memory>
#include <string>
#include "Transform.h"

class RenderingObject;
typedef std::shared_ptr<RenderingObject> SpRenderingObject;
typedef std::weak_ptr<RenderingObject> WpRenderingObject;


class RenderingObject
{
public:
	WpRenderingObject Wp_this;
	Transform* Ptransform;
	bool isEnable;
	virtual void Render(Transform* _Ptransform) = 0;
	virtual void Del() = 0;
	void AddRenderList();
	//	TODO LifeTime ... GameObject‚ª‚Á‚Ä‚é@‚Q‚ÂLifeTime‚ ‚ñ‚Ì‚Ç‚¤‚È‚ÌH
	inline void SetLifeTime(float _LifeTime) { LifeTime = _LifeTime; }
	inline float GetLifeTime() { return LifeTime; }
	static SpRenderingObject Create(RenderingObject* _p);
	virtual ~RenderingObject();
	inline void SetDeviceP(IDirect3DDevice9* pd3dDevice) { Pd3dDevice = pd3dDevice; }
	inline IDirect3DDevice9* GetDeviceP() { return Pd3dDevice; }
protected:
	RenderingObject();
private:
	float LifeTime;
	IDirect3DDevice9* Pd3dDevice;
};

