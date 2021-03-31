//=============================================================================
//
//	セリフ親クラス[talk_bass.h]
//	Author:筒井　俊稀
//
//=============================================================================

// 二重インクルード防止
#ifndef _TALK_BASS_H_
#define _TALK_BASS_H_

//=============================================================================
//インクルードファイル
//=============================================================================
#include "main.h"
#include "ui.h"

//=============================================================================
// クラス定義
//=============================================================================
class CTalkbase :public CUi
{
public:

	// 会話UIの種類
	typedef enum
	{
		TALK_NONE = -1,
		TALK_1,
		TALK_2,
		TALK_3,
		TALK_4,
		TALK_5,
		TALK_6,
		TALK_7,
		TALK_8,
		TALK_9,
		TALK_10,
		TALK_11,
		TALK_12,
		TALK_MAX
	}TALK;

	typedef enum
	{
		FADE_NONE = 0,
		FADE_IN,
		FADE_OUT,
		FADE_MAX
	}TALK_FADE;

	CTalkbase(int nPriorit = PRIORITY_UI_0);	// コンストラクタ
	~CTalkbase();								// デストラクタ
	static HRESULT	Load(void);
	static void		Unload(void);

	HRESULT		Init(void);				// 初期化処理
	void		Uninit(void);			// 終了処理
	void		Update(void);			// 更新処理

	virtual void Talk(void);			// トークを次に進める関数
	void		Blackout(void);			// フェードイン・アウトの処理

	void		SetAppear(int nAppear);		// 出現時間セッター
	int			GetAppear(void);			// 出現時間ゲッター
	void		SetFade(TALK_FADE FadeStatus);	// フェード状態セッター
	TALK_FADE	GetFade(void);					// フェード状態ゲッター
	bool		GetTalkEnd(void);				// 終了しているか

	void		SetTalk(TALK talk);			// テキストセッター
	static TALK GetTalk(void);				// テキストゲッター
	void		BindTalkTexture(TALK talk);	// テキスト画像セット
	
	
	void SetFlagTex(TALK talk);
	void SetColTex(void) { m_col.a = 0.0f; }


private:
	D3DXCOLOR		m_col;			// カラー
	bool			m_bTalkEnd;		// 終了しているか
	int				m_nAppear;		// 出現時間

protected:
	TALK_FADE					m_Fade;					// 文字の透過状況
	int							m_nTalkCount;			// 処理までのカウント

	static TALK					m_Talk;					// テキストタイプ
	static LPDIRECT3DTEXTURE9	m_apTexture[TALK_MAX];	// テクスチャデータ

};
#endif
