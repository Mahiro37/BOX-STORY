//=============================================================================
//
// リソースマネージャー [reource manager.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
//インクルードファイル
//=============================================================================
#include "renderer.h"
#include "resource manager.h"
#include <stdio.h>

#include "player.h"
#include "button.h"
#include "grass block.h"
#include "end button.h"
#include "restart button.h"
#include "start button.h"
#include "child.h"
#include "stagenumber.h"
#include "talk_base.h"
#include "red sand block.h"
#include "hole block.h"
#include "garbage block.h"
#include "building block.h"
#include "building break block.h"
#include "sand block.h"
#include "sprout block.h"
#include "seeds block.h"
#include "tutorial.h"
#include "press button ui.h"
#include "grass block.h"
#include "small tree.h"
#include "big tree.h"
#include "apple block.h"
#include "oranges block.h"
#include "grapes block.h"
#include "watermelon block.h"
#include "luggage block.h"
#include "sand block.h"
#include "watermelon block.h"
#include "title logo.h"
#include "particle.h"

#include "stage1.h"
#include "stage2.h"
#include "stage3.h"

#include "sea.h"
//=============================================================================
// マクロ定義
//=============================================================================
#define TEXTURE_DATA ("Data/Text/TextureData.csv")

//=============================================================================
// コンストラクタ
//=============================================================================
CResource::CResource()
{
}
//=============================================================================
// デストラクタ
//=============================================================================
CResource::~CResource()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CResource::Init(void)
{
	CGrassBlock::Load();
	CPlayer::Load();
	CEndButton::Load();
	CRestartButton::Load();
	CStartButton::Load();
	CTalkbase::Load();
	CTutorial::Load();
	CPressUi::Load();
	CTitleLoge::Load();
	CParticle::Load();


	CRedSandBlock::Load();
	CBuildingBlock::Load();
	CBuildingBreakBlock::Load();
	CGarbageBlock::Load();
	CSandBlock::Load();
	CSproutBlock::Load();
	CSeedsBlock::Load();
	CHoleBlock::Load();
	CAppleBlock::Load();
	COrangesBlock::Load();
	CGrapesBlock::Load();
	CWatermelonBlock::Load();
	CBigTree::Load();
	CSmallTree::Load();
	CStageNumber::Load();
	CLuggageBlock::Load();
	CSea::Load();

	//マップ読み込み
	CStage1::Load();
	CStage2::Load();
	CStage3::Load();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CResource::Uninit(void)
{
	CGrassBlock::Unload();
	CPlayer::Unload();
	CRestartButton::Unload();
	CStartButton::Unload();
	CRedSandBlock::Unload();
	CBuildingBlock::Unload();
	CBuildingBreakBlock::Unload();
	CGarbageBlock::Unload();
	CSandBlock::Unload();
	CSproutBlock::Unload();
	CSeedsBlock::Unload();
	CLuggageBlock::Unload();
	CAppleBlock::Unload();
	COrangesBlock::Unload();
	CGrapesBlock::Unload();
	CWatermelonBlock::Unload();
	CBigTree::Unload();
	CSmallTree::Unload();
	CHoleBlock::Unload();
	CStageNumber::Unload();
	CTalkbase::Unload();
	CTutorial::Unload();
	CPressUi::Unload();
	CSea::Unload();
	CTitleLoge::Unload();
	CParticle::Unload();

}

////=============================================================================
//// テクスチャロード
////=============================================================================
//void CResource::TextureLoad(void)
//{
//	for (int nTexture = 0; nTexture < m_nMaxTexture; nTexture++)
//	{
//		//デバイス取得
//		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
//		//テクスチャの読み込み
//		D3DXCreateTextureFromFile(pDevice,
//			m_pcTextureName[m_npTexture[nTexture]],
//			&m_pTexture[m_npTexture[nTexture]]);
//	}
//}
//
////=============================================================================
//// テクスチャデータ読み込み
////=============================================================================
//void CResource::TextureFail(void)
//{
//	//ファイルポインタ
//	FILE*	pFile;
//	//読み込み用データ
//	char cFileString[258];
//	//文字認識
//	int nFileText;
//	//列、行
//	int nCol, nRow;
//	//初期化
//	memset(cFileString, 0, sizeof(cFileString));
//	nCol = 1;
//	nRow = 0;
//
//	//ファイル読み込み
//	fopen_s(&pFile, TEXTURE_DATA, "r");
//
//	if (pFile != NULL)
//	{
//		//総数読み込み
//		//while ()
//		//{
//
//		//}
//		//ヘッダー読み飛ばし
//		while (fgetc(pFile) != '\n');
//
//		while (1)
//		{
//			while (1)
//			{
//				nFileText = fgetc(pFile);
//				//末尾ならループを抜ける。
//				if (nFileText == EOF)
//				{
//					goto out;
//				}
//				//カンマか改行でなければ、文字としてつなげる
//				if (nFileText != ',' && nFileText != '\n')
//				{
//					strcat_s(cFileString, (const char*)&nFileText);
//				}
//				//カンマか改行ならループ抜ける。
//				else
//				{
//					break;
//				}
//			}
//
//			//読み込み
//			if (nCol == 1)
//			{
//				//テクスチャ番号読み込み
//				m_npTexture = new int;
//				m_npTexture[nRow] = atoi(cFileString);
//			}
//			if (nCol == 2)
//			{
//				//テクスチャパス読み込み
//				m_pcTextureName = new char*();
//				m_pcTextureName[m_npTexture[nRow]] = cFileString;
//			}
//
//			//バッファの初期化
//			memset(cFileString, 0, sizeof(cFileString));
//
//			//列数を足す
//			nCol++;
//
//			//もし読み込んだ文字が改行だったら列数を初期化して行数を増やす
//			if (nFileText == '\n')
//			{
//				//行数初期化
//				nCol = 1;
//				//列の進行
//				nRow++;
//
//			}
//
//		}
//	out:							//末尾ならここに跳ぶ
//		m_nMaxTexture = nRow;		//最大数取得
//		fclose(pFile);				//ファイルを閉じる
//	}
//
//}
//
//
////=============================================================================
//// Xファイル読み込みファイル
////=============================================================================
//void CResource::XFail(void)
//{
//}
//
