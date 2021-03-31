//=============================================================================
//
//	スタートボタン[start button.cpp]
//	Author:吉田　悠人
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "start button.h"
#include "renderer.h"
#include "manager.h"
#include "pause.h"
#include "sound.h"
#include "inputcontroller.h"
#include "inputkeyboard.h"
//=============================================================================
// 静的メンバー変数
//=============================================================================
TEXTURE_DATA CStartButton::m_TextureData = { NULL,	"Data/Texture/button/saikai.png", };

//=============================================================================
// コンストラクタ
//=============================================================================
CStartButton::CStartButton()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CStartButton::~CStartButton()
{
}

//=============================================================================
// テクスチャ読み込み
//=============================================================================
HRESULT CStartButton::Load(void)
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
void CStartButton::Unload(void)
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
CStartButton * CStartButton::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	//メモリ確保
	CStartButton *pStartButton = NULL;
	pStartButton = new CStartButton;

	//NULLチェック
	if (pStartButton != NULL)
	{
		//位置設定
		pStartButton->SetPos(D3DXVECTOR3(pos.x, pos.y, pos.z));
		//サイズ設定
		pStartButton->SetSize(D3DXVECTOR3(size.x, size.y, size.z));
		//テクスチャ設定
		pStartButton->BindTexture(m_TextureData.m_pTexture);
		//初期化処理
		pStartButton->Init();
	}
	return pStartButton;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CStartButton::Init(void)
{
	CButton::Init();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CStartButton::Uninit(void)
{
	CButton::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CStartButton::Update(void)
{
	CButton::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CStartButton::Draw(void)
{
	CButton::Draw();
}


//=============================================================================
// プッシュ判定処理
//=============================================================================
void CStartButton::Push()
{
	//キー入力取得
	CInputKeyboard* pInputKey = (CInputKeyboard*)CManager::GetInputKey();
	//ポーズ取得
	CPause* pPause = CManager::GetPause();
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
		//ポーズ終了
		pPause->Delete();
		//BGMの再生
		CManager::GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_DECISION);
	}
}

