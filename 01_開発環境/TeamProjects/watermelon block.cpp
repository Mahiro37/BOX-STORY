//=============================================================================
//
// スイカブロック [watermelon block.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "watermelon block.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// 静的メンバ変数初期化
//=============================================================================
CModel::MODELDATA CWatermelonBlock::m_modeldata = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CWatermelonBlock::CWatermelonBlock()
{
}
//=============================================================================
// デストラクタ
//=============================================================================
CWatermelonBlock::~CWatermelonBlock()
{
}

//=============================================================================
// モデル読み込み関数
//=============================================================================
HRESULT CWatermelonBlock::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Item/WaterMelonBlock/WaterMelonBlock.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CWatermelonBlock::Unload(void)
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
CWatermelonBlock * CWatermelonBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//メモリ確保
	CWatermelonBlock* pWatermelonBlock = NULL;
	pWatermelonBlock = new CWatermelonBlock;

	//NULLチェック
	if (pWatermelonBlock != NULL)
	{
		//位置設定
		pWatermelonBlock->SetPosition(D3DXVECTOR3(pos.x, pos.y + ITEM_HEIGHT+20, pos.z));
		//向き設定
		pWatermelonBlock->SetRotation(rot);
		//カラー設定
		pWatermelonBlock->SetScale(size);
		//モデル設定
		pWatermelonBlock->SetModelData(m_modeldata);
		//初期化処理
		pWatermelonBlock->Init();
	}

	return pWatermelonBlock;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CWatermelonBlock::Init(void)
{
	CItemBlockBase::Init();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CWatermelonBlock::Uninit(void)
{
	CItemBlockBase::Uninit();
}

//=============================================================================
// 更新関数
//=============================================================================
void CWatermelonBlock::Update(void)
{
	CItemBlockBase::Update();

}

//=============================================================================
// 描画関数
//=============================================================================
void CWatermelonBlock::Draw(void)
{
	CItemBlockBase::Draw();
}
