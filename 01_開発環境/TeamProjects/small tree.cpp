//=============================================================================
//
// 針葉樹(小さい) [small tree.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "small tree.h"
#include "manager.h"
#include "renderer.h"
#include "object.h"
#include "model.h"
#include "model object.h"
//=============================================================================
// 静的メンバ変数初期化
//=============================================================================
CModel::MODELDATA CSmallTree::m_modeldata = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CSmallTree::CSmallTree()
{
}
//=============================================================================
// デストラクタ
//=============================================================================
CSmallTree::~CSmallTree()
{
}

//=============================================================================
// モデル読み込み関数
//=============================================================================
HRESULT CSmallTree::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;

	D3DXLoadMeshFromX("Data/Model/Hindrance/WoodSmallBlock/WoodSmall.x", D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_modeldata.pBuffMat, NULL, &m_modeldata.nNumMat, &m_modeldata.pMesh);

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
void CSmallTree::Unload(void)
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
CSmallTree * CSmallTree::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size)
{
	//メモリ確保
	CSmallTree* pSmallTree = NULL;
	pSmallTree = new CSmallTree;

	//NULLチェック
	if (pSmallTree != NULL)
	{
		//位置設定
		pSmallTree->SetPosition(D3DXVECTOR3(pos.x, pos.y + HINDRANCE_HEIGHT, pos.z));
		//向き設定
		pSmallTree->SetRotation(rot);
		//カラー設定
		pSmallTree->SetScale(size);
		//モデル設定
		pSmallTree->SetModelData(m_modeldata);
		//初期化処理
		pSmallTree->Init();
	}

	return pSmallTree;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CSmallTree::Init(void)
{
	CHindranceBlockBase::Init();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CSmallTree::Uninit(void)
{
	CHindranceBlockBase::Uninit();
}

//=============================================================================
// 更新関数
//=============================================================================
void CSmallTree::Update(void)
{
	CHindranceBlockBase::Update();

}

//=============================================================================
// 描画関数
//=============================================================================
void CSmallTree::Draw(void)
{
	CHindranceBlockBase::Draw();

}
