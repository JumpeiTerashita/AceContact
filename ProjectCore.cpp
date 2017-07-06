//--------------------------------------------------------------------------------------
// File: EmptyProject.cpp
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include "DXUT.h"
#include "SDKsound.h"
#include "resource.h"
#include "support\t2k_support.h"

//---------------------------------------------------------------------
//
// X �t�@�C��
//
LPDIRECT3DTEXTURE9		g_pTex ;
LPD3DXMESH				g_pMesh ;
D3DXVECTOR3				g_rot ;
D3DXVECTOR3				g_pos ;
D3DXVECTOR3				g_scl(1,1,1);

//---------------------------------------------------------------------
//
// �J�����p
//
D3DXVECTOR3		vEyePt( 0.0f, 3.0f, -15.0f );
D3DXVECTOR3		vLookatPt( 0.0f, 0.0f, 0.0f );
D3DXVECTOR3		vUpVec( 0.0f, 1.0f, 0.0f );
D3DXMATRIX		gView, gProj ;




//--------------------------------------------------------------------------------------
// Rejects any D3D9 devices that aren't acceptable to the app by returning false
//--------------------------------------------------------------------------------------
bool CALLBACK IsD3D9DeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat,
                                      bool bWindowed, void* pUserContext )
{
    // Typically want to skip back buffer formats that don't support alpha blending
    IDirect3D9* pD3D = DXUTGetD3D9Object();
    if( FAILED( pD3D->CheckDeviceFormat( pCaps->AdapterOrdinal, pCaps->DeviceType,
                                         AdapterFormat, D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING,
                                         D3DRTYPE_TEXTURE, BackBufferFormat ) ) )
        return false;

    return true;
}


//--------------------------------------------------------------------------------------
// Before a device is created, modify the device settings as needed
//--------------------------------------------------------------------------------------
bool CALLBACK ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext )
{
    return true;
}


//--------------------------------------------------------------------------------------
// Create any D3D9 resources that will live through a device reset (D3DPOOL_MANAGED)
// and aren't tied to the back buffer size
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D9CreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
                                     void* pUserContext )
{
	// ����͏����Ȃ�
	t2k::Support::createDeviece() ;


	//-------------------------------------------------------------------------
	// �J�����ݒ�
	D3DXMatrixLookAtLH( &gView, &vEyePt, &vLookatPt, &vUpVec );
	pd3dDevice->SetTransform( D3DTS_VIEW, &gView );
   	D3DXMatrixPerspectiveFovLH( &gProj, D3DX_PI / 4.0f, 1.0f, 1.0f, 10000.0f );
	pd3dDevice->SetTransform( D3DTS_PROJECTION, &gProj ) ;


	//-------------------------------------------------------------------------
	// X �t�@�C�� �ƃe�N�X�`���̃��[�h
	D3DXCreateTextureFromFile( pd3dDevice, L"spaceship_fighter_CLR.bmp", &g_pTex ) ;
	D3DXLoadMeshFromX( L"SpaceShip_Duo.x", D3DXMESH_MANAGED, pd3dDevice, NULL, NULL, NULL, NULL, &g_pMesh ) ;


    return S_OK;
}


//--------------------------------------------------------------------------------------
// Create any D3D9 resources that won't live through a device reset (D3DPOOL_DEFAULT) 
// or that are tied to the back buffer size 
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D9ResetDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
                                    void* pUserContext )
{
	// ����͏����Ȃ�
	t2k::Support::resetDevice() ;

    return S_OK;
}


//--------------------------------------------------------------------------------------
// Handle updates to the scene.  This is called regardless of which D3D API is used
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext )
{
	//g_rot.x += D3DXToRadian(1.0f) ;
	//g_rot.y += D3DXToRadian(1.0f) ;
	//g_rot.z += D3DXToRadian(1.0f) ;

	

	if (DXUTIsKeyDown(VK_LEFT)) {
		t2k::Support::debugTrace("�� �J�[�\����������");
		g_rot.z += D3DXToRadian(1.0f);
	}

	if (DXUTIsKeyDown(VK_RIGHT)) {
		t2k::Support::debugTrace("�� �J�[�\����������");
		g_rot.z += D3DXToRadian(-1.0f);
	}



	/*if( DXUTWasKeyPressed('A') ) {
		t2k::Support::debugTrace("A ��������") ;
		t2k::Support::playSoundBgm("bgm1.wav") ;
	}*/

	//if( DXUTWasKeyPressed( VK_LEFT ) ) {
	//	t2k::Support::debugTrace("�� �J�[�\����������") ;
	//	t2k::Support::playSoundSe("se1.wav") ;
	//}

	if( DXUTIsKeyDown('B') ) {
		t2k::Support::debugTrace("B �������Ă���") ;
	}


	// ����͏����Ȃ�
	t2k::Support::updata() ;

}


//--------------------------------------------------------------------------------------
// Render the scene using the D3D9 device
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9FrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{
    HRESULT hr;

    // Clear the render target and the zbuffer 
    V( pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB( 0, 45, 50, 170 ), 1.0f, 0 ) );

	// ���[���h�}�g���N�X�ݒ�
	D3DXMATRIX SclMtx, RotMtx, PosMtx, WldMtx ;
	D3DXMatrixScaling( &SclMtx, g_scl.x, g_scl.y, g_scl.z );

	D3DXMatrixRotationYawPitchRoll( &RotMtx, g_rot.y, g_rot.x, g_rot.z ) ;
	D3DXMatrixTranslation( &PosMtx, g_pos.x, g_pos.y, g_pos.z ) ;
	WldMtx = SclMtx * RotMtx * PosMtx ;

	// �e�N�X�`���K�p
	pd3dDevice->SetTexture( 0, g_pTex ) ;

	// �ʏ퍇��
	pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE ) ;
	pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1 ) ;
	pd3dDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE ) ;
	pd3dDevice->SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA ) ;	
	pd3dDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA ) ;

	//���C�e�B���OOFF
	pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	pd3dDevice->LightEnable( 0, FALSE ) ;

	pd3dDevice->SetTransform( D3DTS_WORLD, &WldMtx );

    // Render the scene
    if( SUCCEEDED( pd3dDevice->BeginScene() ) )
    {
		g_pMesh->DrawSubset( 0 ) ;
        V( pd3dDevice->EndScene() );
    }

	static int a = 0 ; 
	a++ ;
	t2k::Support::renderString(5, 5, "TEST COUNT : %d", a );

}


//--------------------------------------------------------------------------------------
// Handle messages to the application 
//--------------------------------------------------------------------------------------
LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
                          bool* pbNoFurtherProcessing, void* pUserContext )
{
    return 0;
}


//--------------------------------------------------------------------------------------
// Release D3D9 resources created in the OnD3D9ResetDevice callback 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9LostDevice( void* pUserContext )
{
	t2k::Support::lostDevice() ;
}


//--------------------------------------------------------------------------------------
// Release D3D9 resources created in the OnD3D9CreateDevice callback 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9DestroyDevice( void* pUserContext )
{

	g_pTex->Release() ;
	g_pMesh->Release() ;

	// ����͏����Ȃ�
	t2k::Support::destroyDevice() ;
}


//--------------------------------------------------------------------------------------
// Initialize everything and go into a render loop
//--------------------------------------------------------------------------------------
INT WINAPI wWinMain( HINSTANCE, HINSTANCE, LPWSTR, int )
{
    // Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

    // Set the callback functions
    DXUTSetCallbackD3D9DeviceAcceptable( IsD3D9DeviceAcceptable );
    DXUTSetCallbackD3D9DeviceCreated( OnD3D9CreateDevice );
    DXUTSetCallbackD3D9DeviceReset( OnD3D9ResetDevice );
    DXUTSetCallbackD3D9FrameRender( OnD3D9FrameRender );
    DXUTSetCallbackD3D9DeviceLost( OnD3D9LostDevice );
    DXUTSetCallbackD3D9DeviceDestroyed( OnD3D9DestroyDevice );
    DXUTSetCallbackDeviceChanging( ModifyDeviceSettings );
    DXUTSetCallbackMsgProc( MsgProc );
    DXUTSetCallbackFrameMove( OnFrameMove );

    // TODO: Perform any application-level initialization here

    // Initialize DXUT and create the desired Win32 window and Direct3D device for the application
    DXUTInit( true, true ); // Parse the command line and show msgboxes
    DXUTSetHotkeyHandling( true, true, true );  // handle the default hotkeys
    DXUTSetCursorSettings( true, true ); // Show the cursor and clip it when in full screen
    DXUTCreateWindow( L"EmptyProject" );
    DXUTCreateDevice( true, 640, 480 );

    // Start the render loop
    DXUTMainLoop();

    // TODO: Perform any application-level cleanup here

    return DXUTGetExitCode();
}

