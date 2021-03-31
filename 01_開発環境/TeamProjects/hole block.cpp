//=============================================================================
//
// 砂ブロック [sand block.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "hole block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
#include "fade.h"
#include "sprout block.h"
//=============================================================================
// 静的メンバ変数初期化
//=============================================================================
CModel::MODELDATA CHoleBlock::m_modeldata = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CHoleBlock::CHoleBlock()
{
}
//=============================================================================
// デストラクタ
//=============================================================================
CHoleBlock::~CHoleBlock()
{
}

//=============================================================================
// モデル読み込み関数
//=============================================================================
HRESULT CHoleBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Goal/HoleBlock/HoleBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

	if (m_modeldata.pBuffMat != NULL)
	{
		pMat = (D3DXMATERIAL *)m_modeldata.pBuffMat->GetBufferPointer();

		for (int nCountMat = 0; nCountMat < (int)m_modeldata.nNumMat; nCountMat++)
		{
			D3DXCreateTextureFromFile(pDevice, pMat[nCountMat].pTextureFilename, &m_modeldata.pTexture[nCountMat]);
		}

	}
	return S_OK;
}

//=============================================================================
// モデル破棄関数
//=============================================================================
void CHoleBlock::Unload(void)
{
	if (m_modeldata.pBuffMat != NULL)
	{
		m_modeldata.pBuffMat->Release();
	}

	if (m_modeldata.pMesh != NULL)
	{
		m_modeldata.pMesh->Release();
	}

	for (int nCountTex = 0; nCountTex < MAX_MATERIAL; nCountTex++)
	{
		if (m_modeldata.pTexture[nCountTex] != NULL)
		{
			m_modeldata.pTexture[nCountTex]->Release();
		}
	}
}

//=============================================================================
// 生成関数
//=============================================================================
CHoleBlock * CHoleBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size, CGame::MAP_TYPE MapType)
{
	//メモリ確保
	CHoleBlock* pHoleBlock = NULL;
	pHoleBlock = new CHoleBlock;

	//NULLチェック
	if (pHoleBlock != NULL)
	{
		//位置設定
		pHoleBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y - BLOCK_HEIGHT, pos.z));
		//向き設定
		pHoleBlock->SetRotation(rot);
		//カラー設定
		pHoleBlock->SetScale(size);
		//マップ設定
		pHoleBlock->SetMapType(MapType);
		//モデル設定
		pHoleBlock->SetModelData(m_modeldata);
		//初期化処理
		pHoleBlock->Init();
	}

	return pHoleBlock;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CHoleBlock::Init(void)
{
	CGoalBlockBase::Init();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CHoleBlock::Uninit(void)
{
	CGoalBlockBase::Uninit();
}

//=============================================================================
// 更新関数
//=============================================================================
void CHoleBlock::Update(void)
{
	CGoalBlockBase::Update();
	GoalCollision();
}

//=============================================================================
// 描画関数
//=============================================================================
void CHoleBlock::Draw(void)
{
	CGoalBlockBase::Draw();
}

//=============================================================================
// ゴール処理関数
//=============================================================================
void CHoleBlock::Goal(void)
{
	//フェード取得
	CFade*	pFade = CManager::GetFadeout();
	//位置取得
	D3DXVECTOR3 pos = GetPosition();

	//パーティクル生成
	
	//終了処理
	CHoleBlock::Uninit();

	//芽ブロック生成
	CSproutBlock::Create(D3DXVECTOR3(pos.x, 0, pos.z), GetRotation(), GetScale());

	//アイテムがないか
	if (ItemSearch())
	{
		//ステージのフェード
		if (GetMapType() < CGame::MAP_TYPE_3)
		{
			//次のステージにフェード
			pFade->SetWhiteout(CGame::MAP_TYPE(GetMapType() + 1));

		}
	}

}

