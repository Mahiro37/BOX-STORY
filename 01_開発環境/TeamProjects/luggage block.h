//=============================================================================
//
// 荷物ブロック [luggage block.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _LUGGSGE_BLOCK_H_
#define _LUGGSGE_BLOCK_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "model.h"
#include "goal block base.h"
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
class CLuggageBlock : public CGoalBlockBase
{
public:
	CLuggageBlock();
	~CLuggageBlock();
	static HRESULT			Load(void);
	static void				Unload(void);
	static CLuggageBlock*	Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 size, CGame::MAP_TYPE MapType ,bool Goal = true);
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
private:
	bool						bGoal;			//ゴールとして機能するか
	static CModel::MODELDATA	m_modeldata;	//モデルデータ
};
#endif