#include <time.h>
#include "DXUT.h"
#include "SDKmisc.h"
#include "SDKsound.h"
#include "t2k_support.h"
#include "t2k_sound.h"

namespace t2k {

	CDXUTTextHelper* Support::pTxtHelper = nullptr ;
	ID3DXFont*       Support::pFont9 = nullptr ;
	ID3DXSprite*     Support::pSprite9 = nullptr ;
	CSoundManager*   Support::pSoundManager = nullptr ;
	CSound*          Support::p_bgm = nullptr ;
	bool			 Support::is_play_bgm = false ;
	std::map< std::string, Se* > Support::sounds ;


	//------------------------------------------------------------------------------------------------------------------
	void Support::updata() {

		// SE の開放管理
		std::map< std::string, Se* >::iterator it = sounds.begin() ;

		while( it != sounds.end() ) {

			Se *s = it->second ;
			if( ( (double)( clock() - s->not_play_time ) / CLOCKS_PER_SEC ) > 120 ) {
				SAFE_DELETE(s) ;
				sounds.erase(it++) ;
				continue ;
			}

			it++ ;
			continue ;
		}

		// bgm のループ再生管理
		if( is_play_bgm && p_bgm ) {
			if( !p_bgm->IsSoundPlaying() ) {
				p_bgm->Play(); 
			}
		}

	}

	//------------------------------------------------------------------------------------------------------------------
	void Support::createDeviece() {

		IDirect3DDevice9* pd3dDevice = DXUTGetD3D9Device() ;
		
		HRESULT hr;
		V(D3DXCreateFont(pd3dDevice, 15, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
			L"Arial", &pFont9));
			

		// サウンドマネージャー初期化
		HWND hwnd = DXUTGetHWND();
		pSoundManager = new CSoundManager();
		V(pSoundManager->Initialize(hwnd, DSSCL_PRIORITY));          

	}

	//------------------------------------------------------------------------------------------------------------------
	void Support::resetDevice() {

		IDirect3DDevice9* pd3dDevice = DXUTGetD3D9Device() ;

		HRESULT hr;

		if( pFont9 ) V(pFont9->OnResetDevice());
		V(D3DXCreateSprite(pd3dDevice, &pSprite9));
		pTxtHelper = new CDXUTTextHelper(pFont9, pSprite9, NULL, NULL, 15);

	}

	//------------------------------------------------------------------------------------------------------------------
	void Support::lostDevice() {

		if( pFont9 ) pFont9->OnLostDevice();
		SAFE_RELEASE(pSprite9);
		SAFE_DELETE(pTxtHelper);

	}

	//------------------------------------------------------------------------------------------------------------------
	void Support::destroyDevice() {

		// すべてのサウンドを開放
		std::map< std::string, Se* >::iterator it = sounds.begin() ;
		while( it != sounds.end() ) {
			Se* s = it->second ;
			SAFE_DELETE( s ) ;
			it++ ;
		}

		if( nullptr != p_bgm ) {
			p_bgm->Stop() ;
			SAFE_DELETE(p_bgm) ;
		}


		SAFE_RELEASE(pSprite9);
		SAFE_DELETE(pTxtHelper);
		SAFE_RELEASE(pFont9);
		SAFE_DELETE(pSoundManager) ;
	}

	//------------------------------------------------------------------------------------------------------------------
	HRESULT Support::toWideChar(WCHAR* wstrDest, const char* strSrc, int size) {
		// 引数の*がNULLの場合と、文字数が1以下の場合はエラー
		if( wstrDest == NULL || strSrc == NULL || size < 1 )
			return E_INVALIDARG;

		int nResult = MultiByteToWideChar(CP_ACP, 0, strSrc, -1, wstrDest, size);
		wstrDest[ size - 1 ] = 0;

		if( nResult == 0 )
			return E_FAIL;
		return S_OK;
	}

	//------------------------------------------------------------------------------------------------------------------
	void Support::debugTrace(char *_str, ...) {
		char buff[ 255 ] = { 0 } ;
		WCHAR w_buff[ 255 ] = { 0 } ;
		va_list argptr;

		va_start(argptr, _str) ;
		vsprintf(buff, _str, argptr) ;
		va_end(argptr) ;

		toWideChar(w_buff, buff, 255) ;

		OutputDebugString(L"\n") ;
		OutputDebugString(w_buff) ;

	}

	//------------------------------------------------------------------------------------------------------------------
	void Support::renderString(int x, int y, char *_str, ...) {

		char buff[ 255 ] = { 0 } ;
		WCHAR w_buff[ 255 ] = { 0 } ;
		va_list argptr;

		va_start(argptr, _str) ;
		vsprintf(buff, _str, argptr) ;
		va_end(argptr) ;

		toWideChar(w_buff, buff, 255) ;


		pTxtHelper->Begin();

		pTxtHelper->SetInsertionPos(x, y);
		pTxtHelper->SetForegroundColor(D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
		pTxtHelper->DrawTextLine(w_buff);

		pTxtHelper->End();

	}


	//------------------------------------------------------------------------------------------------------------------
	void Support::playSoundBgm( const std::string &file_name ) {

		if( nullptr != p_bgm ) {
			p_bgm->Stop() ;
			SAFE_DELETE( p_bgm ) ;
		}

		WCHAR w_buff[ 255 ] = {0} ;
		toWideChar( w_buff, file_name.c_str(), file_name.length()+1 ) ;

		pSoundManager->Create( &p_bgm, w_buff ) ;
		p_bgm->Play() ;

		is_play_bgm = true ;
	}

	//------------------------------------------------------------------------------------------------------------------
	void Support::stopSoundBgm() {
		is_play_bgm = false ;
		if( nullptr == p_bgm ) return ;
		p_bgm->Stop() ;
	}

	//------------------------------------------------------------------------------------------------------------------
	void Support::playSoundSe( const std::string &file_name ) {
		
		std::map< std::string, Se* >::iterator it = sounds.find( file_name ) ;

		if( it == sounds.end() ) {

			WCHAR w_buff[ 255 ] = { 0 } ;
			toWideChar(w_buff, file_name.c_str(), file_name.length() + 1) ;

			Se* se = new Se() ;
			for( int i = 0 ; i < Se::max ; ++i ) {
				pSoundManager->Create(&se->p_sound[ i ], w_buff) ;
			}
			se->play() ;

			sounds.insert( std::make_pair( file_name, se ) ) ;

			return ;
		}

		it->second->play() ;
		
	}


}

