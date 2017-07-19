#pragma once
class RenderingObject
{
public:
	RenderingObject();
	~RenderingObject();
	LPDIRECT3DTEXTURE9		Tex;
	LPD3DXMESH				Mesh;
	D3DXVECTOR3				Rot;
	D3DXVECTOR3				Pos;
	D3DXVECTOR3				Scl;
	bool isEnable;
	void Render(IDirect3DDevice9* pd3dDevice);
	void AddRenderList();
	//	TODO LifeTime ... GameObject�������Ă�@�Q��LifeTime����̂ǂ��Ȃ́H
	inline void SetLifeTime(float _LifeTime) { LifeTime = _LifeTime; }
	inline float GetLifeTime() { return LifeTime; }
private:
	float LifeTime;
};

