//=============================================================================
//
// スイカブロック [watermelon block.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _WATERMELON_BLOCK_H_
#define _WATERMELON_BLOCK_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "model.h"
#include "item block base.h"
//=============================================================================
// マクロ定義
//=============================================================================

//=============================================================================
// 前方宣言
//=============================================================================
class CModel;
//=============================================================================
// クラス定義
//=============================================================================
class CWatermelonBlock : public CItemBlockBase
{
public:
	CWatermelonBlock();
	~CWatermelonBlock();
	static HRESULT				Load(void);
	static void					Unload(void);
	static CWatermelonBlock*	Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size);
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
private:
	static CModel::MODELDATA	m_modeldata;	//モデルデータ
};
#endif