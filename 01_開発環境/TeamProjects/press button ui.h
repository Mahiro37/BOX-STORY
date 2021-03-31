//=============================================================================
//
//	プレスボタンUI[press button ui.h]
//	Author:吉田　悠人
//
//=============================================================================

#ifndef _PRESS_BUTTON_H_
#define _PRESS_BUTTON_H_

//=============================================================================
//インクルードファイル
//=============================================================================
#include "main.h"
#include "inputmouse.h"
#include "ui.h"

//=============================================================================
// クラス定義
//=============================================================================
class CPressUi :public CUi
{
public:

	CPressUi(int nPriority = PRIORITY_UI_0);	// コンストラクタ
	~CPressUi();								// デストラクタ
	static HRESULT		Load(void);
	static void			Unload(void);
	static CPressUi*	Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	HRESULT		 Init(void);			// 初期化処理
	void		 Update(void);			// 更新処理

private:
	static TEXTURE_DATA	m_TextureData;	// テクスチャデータ

};
#endif
