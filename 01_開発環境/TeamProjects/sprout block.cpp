//=============================================================================
//
// 芽ブロック [sprout block.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "sprout block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// 静的メンバ変数初期化
//=============================================================================
CModel::MODELDATA CSproutBlock::m_modeldata = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CSproutBlock::CSproutBlock()
{
}
//=============================================================================
// デストラクタ
//=============================================================================
CSproutBlock::~CSproutBlock()
{
}

//=============================================================================
// モデル読み込み関数
//=============================================================================
HRESULT CSproutBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Stage/BudsBlock/BudsBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CSproutBlock::Unload(void)
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
CSproutBlock * CSproutBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//メモリ確保
	CSproutBlock* pSproutBlock = NULL;
	pSproutBlock = new CSproutBlock;

	//NULLチェック
	if (pSproutBlock != NULL)
	{
		//位置設定
		pSproutBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y - BLOCK_HEIGHT, pos.z));
		//向き設定
		pSproutBlock->SetRotation(rot);
		//カラー設定
		pSproutBlock->SetScale(size);
		//モデル設定
		pSproutBlock->SetModelData(m_modeldata);
		//初期化処理
		pSproutBlock->Init();
	}

	return pSproutBlock;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CSproutBlock::Init(void)
{
	CTileBlockBase::Init();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CSproutBlock::Uninit(void)
{
	CTileBlockBase::Uninit();
}

//=============================================================================
// 更新関数
//=============================================================================
void CSproutBlock::Update(void)
{
	CTileBlockBase::Update();
}

//=============================================================================
// 描画関数
//=============================================================================
void CSproutBlock::Draw(void)
{
	CTileBlockBase::Draw();

}

