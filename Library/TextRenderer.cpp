#include <Windows.h>
#include "DXUT.h"
#include "TextRenderer.h"


TextRenderer::TextRenderer()
{
}


TextRenderer::~TextRenderer()
{
}

void TextRenderer::GetTxtOutline()
{
	HWND hWnd = FindWindow(NULL, NULL);

	HDC DeviceContextHandle = GetDC(hWnd);
	
	/*GetGlyphOutline(
		HDC	hdc,
		UINT	uChar,
		UINT	uFormat,
		LPGLYPHMETRICS	lpgm,
		DWORD	cbBuffer,
		LPVOID	lpvBuffer,
		CONST MAT2*	lpmat2
	);*/
}
