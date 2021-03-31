//=============================================================================
//
//	セリフNo5 [talk no5.cpp]
//	Author:筒井 俊稀
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "talk_base.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "renderer.h"
#include "manager.h"
#include "sound.h"
#include "talk no5.h"

//=============================================================================
// マクロ定義
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CTalkNo5::CTalkNo5(int nPriorit)
{
}

//=============================================================================
// 生成処理
//=============================================================================
CTalkNo5 * CTalkNo5::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	//メモリ確保
	CTalkNo5* pTalkNo5 = nullptr;
	pTalkNo5 = new CTalkNo5;

	//NULLチェック
	if (pTalkNo5 != nullptr)
	{
		//位置設定
		pTalkNo5->SetPos(pos);
		//サイズ設定
		pTalkNo5->SetSize(size);
		//テクスチャ設定
		pTalkNo5->BindTexture(m_apTexture[TALK_5]);
		//初期化処理
		pTalkNo5->Init();
	}
	return pTalkNo5;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTalkNo5::Init(void)
{
	//出現している時間セット
	SetAppear(0);
	//フェード状況設定
	SetFade(FADE_IN);

	//初期化処理
	CTalkbase::Init();
	return S_OK;
}

//=============================================================================
// 更新処理
//=============================================================================
void CTalkNo5::Update(void)
{
	CTalkbase::Update();
}

//=============================================================================
// トーク処理
//=============================================================================
void CTalkNo5::Talk(void)
{

}
