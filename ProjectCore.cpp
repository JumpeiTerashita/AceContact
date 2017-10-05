//--------------------------------------------------------------------------------------
// File: EmptyProject.cpp
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include "DXUT.h"
#include "SDKsound.h"
#include "resource.h"
#include "support\t2k_support.h"
#include "Library\GraphicsManager.h"
#include "Engine\GameObjectManager.h"
#include "Engine\GameCamera.h"
#include "Game\Player.h"
#include "Game\Enemy_01.h"
#include <memory>

//LPDIRECT3DTEXTURE9		g_pTex;
//LPD3DXMESH				g_pMesh;

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
	// これは消さない
	t2k::Support::createDeviece() ;

	
	SpGameCamera CameraTest = GameCamera::Create();
	
	
	SpEnemy_01 EnemyTest = Enemy_01::Create();

	SpPlayer PlayerTest = Player::Create();
	
	


	//Player* PlayerTest2 = new Player();

	////-------------------------------------------------------------------------
	//// カメラ設定
	//D3DXMatrixLookAtLH( &gView, &vEyePt, &vLookatPt, &vUpVec );
	//pd3dDevice->SetTransform( D3DTS_VIEW, &gView );
 //  	D3DXMatrixPerspectiveFovLH( &gProj, D3DX_PI / 4.0f, 1.0f, 1.0f, 10000.0f );
	//pd3dDevice->SetTransform( D3DTS_PROJECTION, &gProj ) ;


	//-------------------------------------------------------------------------
	// X ファイル とテクスチャのロード
	/*D3DXCreateTextureFromFile( pd3dDevice, L"spaceship_fighter_CLR.bmp", &g_pTex ) ;
	D3DXLoadMeshFromX( L"SpaceShip_Duo.x", D3DXMESH_MANAGED, pd3dDevice, NULL, NULL, NULL, NULL, &g_pMesh ) ;*/
	

	/*D3DXCreateTextureFromFile(pd3dDevice, L"spaceship_fighter_CLR.bmp",(&player->g_pTex));
	D3DXLoadMeshFromX(L"SpaceShip_Duo.x", D3DXMESH_MANAGED, pd3dDevice, NULL, NULL, NULL, NULL, (&player->g_pMesh));
*/
	//D3DXCreateTextureFromFile(pd3dDevice, L"spaceship_fighter_CLR.bmp", &Test2->g_pTex);
	//D3DXLoadMeshFromX(L"SpaceShip_Duo.x", D3DXMESH_MANAGED, pd3dDevice, NULL,NULL, NULL, NULL, &Test2->g_pMesh);


	

    return S_OK;
}


//--------------------------------------------------------------------------------------
// Create any D3D9 resources that won't live through a device reset (D3DPOOL_DEFAULT) 
// or that are tied to the back buffer size 
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D9ResetDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
                                    void* pUserContext )
{
	// これは消さない
	t2k::Support::resetDevice() ;

    return S_OK;
}


//--------------------------------------------------------------------------------------
// Handle updates to the scene.  This is called regardless of which D3D API is used
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext )
{
	GameObjectManager::GetInstance()->Update();
	
	if( DXUTWasKeyPressed('A') ) {

	t2k::Support::debugTrace("カメラモード変更") ;
	
	auto Camera = GameObjectManager::GetInstance()->GetMap("GameCamera");
	
	/*
	if (GameCamera::GetInstance()->CameraMode == 0) GameCamera::GetInstance()->CameraMode = 1;
	else GameCamera::GetInstance()->CameraMode = 0;
	*/
	
	}

	if (DXUTIsKeyDown(VK_LEFT)) {
		t2k::Support::debugTrace("← カーソルを押した");
	}

	if (DXUTIsKeyDown(VK_RIGHT)) {
		t2k::Support::debugTrace("→ カーソルを押した");
		//player->g_rot.z += D3DXToRadian(-1.0f);
	}

	if( DXUTWasKeyPressed('X') ) {
		//	LogicMap Test
		if (GameObjectManager::GetInstance()->IsInLogicMap("Player"))
		{
			t2k::Support::debugTrace("Playerは　ある！");
		}
	}

	//if( DXUTWasKeyPressed( VK_LEFT ) ) {
	//	t2k::Support::debugTrace("← カーソルを押した") ;
	//	t2k::Support::playSoundSe("se1.wav") ;
	//}

	if( DXUTIsKeyDown('B') ) {
		t2k::Support::debugTrace("B を押している") ;
	}


	// これは消さない
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


	GraphicsManager::GetInstance()->Render();
	
	
	static int a = 0 ; 
	a++ ;
	t2k::Support::renderString(5, 5, "TEST COUNT : %d", a );
	auto PlayerMap = GameObjectManager::GetInstance()->GetMap("Player");
	if (PlayerMap)
	{
		t2k::Support::renderString(5, 20, "PlayerPos : X = %f , Y = %f , Z = %f", PlayerMap->transform.Pos.x, PlayerMap->transform.Pos.y, PlayerMap->transform.Pos.z);
	}
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

	/*g_pTex->Release() ;
	g_pMesh->Release();*/
	GraphicsManager::GetInstance()->Destroy();
	// これは消さない
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
    DXUTCreateWindow( L"AceContact" );
    DXUTCreateDevice( true, 640, 480 );

    // Start the render loop
    DXUTMainLoop();

    // TODO: Perform any application-level cleanup here

    return DXUTGetExitCode();
}


