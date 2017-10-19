#include "Transform.h"

#pragma once

namespace ktb
{
	class Camera
	{
	public:
		// TODO 処理順　最後じゃね！？
		Camera();
		~Camera();
		void SetCamera();
		D3DXVECTOR3		EyePt;
		D3DXVECTOR3		LookatPt;
		D3DXVECTOR3		UpVec;
	private:
		D3DXMATRIX		View, Proj;
	};
}



