//=============================================================================
//
// 種ブロック [seeds block.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "seeds block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// 静的メンバ変数初期化
//=============================================================================
CModel::MODELDATA CSeedsBlock::m_modeldata = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CSeedsBlock::CSeedsBlock()
{
}
//=============================================================================
// デストラクタ
//=============================================================================
CSeedsBlock::~CSeedsBlock()
{
}

//=============================================================================
// モデル読み込み関数
//=============================================================================
HRESULT CSeedsBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Item/SeedBlock/SeedBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CSeedsBlock::Unload(void)
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
CSeedsBlock * CSeedsBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//メモリ確保
	CSeedsBlock* pSeedsBlock = NULL;
	pSeedsBlock = new CSeedsBlock;

	//NULLチェック
	if (pSeedsBlock != NULL)
	{
		//位置設定
		pSeedsBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + ITEM_HEIGHT, pos.z));
		//向き設定
		pSeedsBlock->SetRotation(rot);
		//カラー設定
		pSeedsBlock->SetScale(size);
		//モデル設定
		pSeedsBlock->SetModelData(m_modeldata);
		//初期化処理
		pSeedsBlock->Init();
	}

	return pSeedsBlock;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CSeedsBlock::Init(void)
{
	CItemBlockBase::Init();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CSeedsBlock::Uninit(void)
{
	CItemBlockBase::Uninit();
}

//=============================================================================
// 更新関数
//=============================================================================
void CSeedsBlock::Update(void)
{
	CItemBlockBase::Update();

}

//=============================================================================
// 描画関数
//=============================================================================
void CSeedsBlock::Draw(void)
{
	CItemBlockBase::Draw();
}
