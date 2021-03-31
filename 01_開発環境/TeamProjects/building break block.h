//=============================================================================
//
// ビル（半壊）ブロック [building break block.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _BUILDING_BREAK_BLOCK_H_
#define _BUILDING_BREAK_BLOCK_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "model.h"
#include "hindrance block base.h"
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
class CBuildingBreakBlock : public CHindranceBlockBase
{
public:
	CBuildingBreakBlock();
	~CBuildingBreakBlock();
	static HRESULT				Load(void);
	static void					Unload(void);
	static CBuildingBreakBlock*	Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size);
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
private:
	static CModel::MODELDATA	m_modeldata;	//モデルデータ
};
#endif