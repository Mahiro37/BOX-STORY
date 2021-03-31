//=============================================================================
//
// 荷物ブロック [luggage block.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "luggage block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// マクロ定義
//=============================================================================
#define LUGGAGE_HEIGHT (-25.0f)	//高さ調整

//=============================================================================
// 静的メンバ変数初期化
//=============================================================================
CModel::MODELDATA CLuggageBlock::m_modeldata = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CLuggageBlock::CLuggageBlock()
{
	bGoal = false;
}
//=============================================================================
// デストラクタ
//=============================================================================
CLuggageBlock::~CLuggageBlock()
{
}

//=============================================================================
// モデル読み込み関数
//=============================================================================
HRESULT CLuggageBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Goal/BoxBlock/BoxBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CLuggageBlock::Unload(void)
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
CLuggageBlock * CLuggageBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size, CGame::MAP_TYPE MapType, bool Goal)
{
	//メモリ確保
	CLuggageBlock* pLuggageBlock = NULL;
	pLuggageBlock = new CLuggageBlock;

	//NULLチェック
	if (pLuggageBlock != NULL)
	{
		//位置設定
		pLuggageBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + LUGGAGE_HEIGHT, pos.z));
		//向き設定
		pLuggageBlock->SetRotation(rot);
		//カラー設定
		pLuggageBlock->SetScale(size);
		//マップ設定
		pLuggageBlock->SetMapType(MapType);
		//モデル設定
		pLuggageBlock->SetModelData(m_modeldata);
		//ゴール機能設定
		pLuggageBlock->SetGoal(Goal);
		//初期化処理
		pLuggageBlock->Init();
	}

	return pLuggageBlock;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CLuggageBlock::Init(void)
{
	CGoalBlockBase::Init();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CLuggageBlock::Uninit(void)
{
	CGoalBlockBase::Uninit();
}

//=============================================================================
// 更新関数
//=============================================================================
void CLuggageBlock::Update(void)
{
	CGoalBlockBase::Update();
}

//=============================================================================
// 描画関数
//=============================================================================
void CLuggageBlock::Draw(void)
{
	CGoalBlockBase::Draw();

}
