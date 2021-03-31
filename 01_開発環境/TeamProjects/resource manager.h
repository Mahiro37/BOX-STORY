//=============================================================================
//
// リソースマネージャー [reource manager.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "main.h"
#include "manager.h"
//=============================================================================
// クラス定義
//=============================================================================
class CResource
{
public:

	CResource();
	~CResource();

	HRESULT Init(void);
	void	Uninit(void);
	//void	TextureLoad(void);	// テクスチャロード
	//void	XFail(void);		// Xファイル読み込みファイル
	//void	TextureFail(void);	// テクスチャ読み込みファイル

private:
	char**				m_pcTextureName;	// ファイルの名前
	int*				m_npTexture;		// テクスチャ番号
	int					m_nMaxTexture;		// テクスチャの総数
	LPDIRECT3DTEXTURE9*	m_pTexture;			// テクスチャへのポインタ

};
#endif
