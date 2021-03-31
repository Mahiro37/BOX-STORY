//=============================================================================
//
//	リスタートボタン[restart button.cpp]
//	Author:吉田　悠人
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "restart button.h"
#include "renderer.h"
#include "manager.h"
#include "sound.h"
#include "inputcontroller.h"
#include "inputkeyboard.h"
#include "fade.h"

//=============================================================================
// 静的メンバー変数
//=============================================================================
TEXTURE_DATA CRestartButton::m_TextureData = { NULL,	"Data/Texture/button/restart.png", };

//=============================================================================
// コンストラクタ
//=============================================================================
CRestartButton::CRestartButton()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CRestartButton::~CRestartButton()
{
}

//=============================================================================
// テクスチャ読み込み
//=============================================================================
HRESULT CRestartButton::Load(void)
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		m_TextureData.m_cFileName,
		&m_TextureData.m_pTexture);

	return S_OK;
}

//=============================================================================
// テクスチャの破棄
//=============================================================================
void CRestartButton::Unload(void)
{
	//テクスチャの破棄
	if (m_TextureData.m_pTexture != NULL)
	{
		m_TextureData.m_pTexture->Release();
		m_TextureData.m_pTexture = NULL;
	}
}

//=============================================================================
// 生成処理
//=============================================================================
CRestartButton * CRestartButton::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	//メモリ確保
	CRestartButton *pRestartButton = NULL;
	pRestartButton = new CRestartButton;

	//NULLチェック
	if (pRestartButton != NULL)
	{
		//位置設定
		pRestartButton->SetPos(D3DXVECTOR3(pos.x, pos.y, pos.z));
		//サイズ設定
		pRestartButton->SetSize(D3DXVECTOR3(size.x, size.y, size.z));
		//テクスチャ設定
		pRestartButton->BindTexture(m_TextureData.m_pTexture);
		//初期化処理
		pRestartButton->Init();
	}
	return pRestartButton;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CRestartButton::Init(void)
{

	CButton::Init();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CRestartButton::Uninit(void)
{
	CButton::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CRestartButton::Update(void)
{
	CButton::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CRestartButton::Draw(void)
{
	CButton::Draw();
}


//=============================================================================
// プッシュ判定処理
//=============================================================================
void CRestartButton::Push()
{
	//フェイド取得
	CFade*	pBlackout = CManager::GetFadeout();
	//キー入力取得
	CInputKeyboard* pInputKey = (CInputKeyboard*)CManager::GetInputKey();
	// コントローラー入力の取得
	CInputJoyStick* pJoyInput = (CInputJoyStick*)CManager::GetInputController();
	bool bpush = false;

	if (pJoyInput != NULL)
	{
		if (pJoyInput->GetJoyStickTrigger(CInputJoyStick::JOY_BUTTON_A))bpush = true;
	}

	//スティック入力
	if (bpush || pInputKey->GetKeyTrigger(DIK_RETURN))
	{
		//ステージロード
		pBlackout->SetWhiteout(CGame::GetMapMode());

		//BGMの再生
		CManager::GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_DECISION);
	}
}

