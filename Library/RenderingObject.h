#pragma once
#include <memory>

class RenderingObject;
typedef std::shared_ptr<RenderingObject> SpRenderingObject;
typedef std::weak_ptr<RenderingObject> WpRenderingObject;

class RenderingObject
{
public:
	WpRenderingObject Wp_this;
	LPDIRECT3DTEXTURE9		Tex;
	LPD3DXMESH				Mesh;
	D3DXVECTOR3				Rot;
	D3DXVECTOR3				Pos;
	D3DXVECTOR3				Scl;
	bool isEnable;
	void Render(IDirect3DDevice9* pd3dDevice);
	void AddRenderList();
	//	TODO LifeTime ... GameObject‚ª‚Á‚Ä‚é@‚Q‚ÂLifeTime‚ ‚ñ‚Ì‚Ç‚¤‚È‚ÌH
	inline void SetLifeTime(float _LifeTime) { LifeTime = _LifeTime; }
	inline float GetLifeTime() { return LifeTime; }
	static SpRenderingObject Create();
	~RenderingObject();
private:
	RenderingObject();
	
	float LifeTime;
};

