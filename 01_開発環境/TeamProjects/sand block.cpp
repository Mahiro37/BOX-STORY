//=============================================================================
//
// 砂ブロック [sand block.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "sand block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// 静的メンバ変数初期化
//=============================================================================
CModel::MODELDATA CSandBlock::m_modeldata = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CSandBlock::CSandBlock()
{
}
//=============================================================================
// デストラクタ
//=============================================================================
CSandBlock::~CSandBlock()
{
}

//=============================================================================
// モデル読み込み関数
//=============================================================================
HRESULT CSandBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Stage/SandBlock/SandBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CSandBlock::Unload(void)
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
CSandBlock * CSandBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//メモリ確保
	CSandBlock* pSandBlock = NULL;
	pSandBlock = new CSandBlock;

	//NULLチェック
	if (pSandBlock != NULL)
	{
		//位置設定
		pSandBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y - BLOCK_HEIGHT, pos.z));
		//向き設定
		pSandBlock->SetRotation(rot);
		//カラー設定
		pSandBlock->SetScale(size);
		//モデル設定
		pSandBlock->SetModelData(m_modeldata);
		//初期化処理
		pSandBlock->Init();
	}

	return pSandBlock;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CSandBlock::Init(void)
{
	CTileBlockBase::Init();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CSandBlock::Uninit(void)
{
	CTileBlockBase::Uninit();
}

//=============================================================================
// 更新関数
//=============================================================================
void CSandBlock::Update(void)
{
	CTileBlockBase::Update();

}

//=============================================================================
// 描画関数
//=============================================================================
void CSandBlock::Draw(void)
{
	CTileBlockBase::Draw();

}
