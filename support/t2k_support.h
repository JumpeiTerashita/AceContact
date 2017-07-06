#ifndef T2k_SUPPORT_H
#define T2k_SUPPORT_H

#include <Windows.h>
#include <string>
#include <map>
#include <vector>
#include "DXUT.h"
#include "SDKmisc.h"

namespace t2k {
	class Se ;
	class Support {
	private:
		Support() {} ;

		static CDXUTTextHelper* pTxtHelper ;
		static ID3DXFont*       pFont9 ;
		static ID3DXSprite*     pSprite9 ;
		static CSoundManager*   pSoundManager ;

		static bool				is_play_bgm ;
		static CSound*          p_bgm ;
		static std::map< std::string, Se* > sounds ;

	public:
		static void updata() ;
		static void createDeviece() ;
		static void lostDevice() ;
		static void resetDevice() ;
		static void destroyDevice() ;

		static HRESULT toWideChar( WCHAR* wstrDest, const char* strSrc, int size ) ;

		static void debugTrace( char *_str, ... ) ;

		static void renderString( int x, int y, char *_str, ... ) ;

		static void playSoundBgm( const std::string &file_name ) ;
		static void stopSoundBgm() ;

		static void playSoundSe( const std::string &file_name ) ;

	};

}

#endif

