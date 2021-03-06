//=============================================================================
//
// ゴールブロックベース [goal block base.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _GOAL_BLOCK_BASE_H_
#define _GOAL_BLOCK_BASE_H_

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "model.h"
#include "block base.h"
#include "game.h"
//=============================================================================
// マクロ定義
//=============================================================================
#define GOAL_HEIGHT (25.0f)	//ゴールブロックの高さ
#define GOAL_RANGE	(25.0f)	//ゴール判定の大きさ
//=============================================================================
// 前方宣言
//=============================================================================
class CModel;
class CParticle;
//=============================================================================
// クラス定義
//=============================================================================
class CGoalBlockBase : public CBlockBase
{
public:
	CGoalBlockBase();
	~CGoalBlockBase();
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);

	void	GoalCollision(void);	// ゴールの当たり判定処理
	bool	ItemSearch(void);		// アイテムサーチ関数
	virtual void Goal(void);		// ゴール処理

	void			SetMapType(CGame::MAP_TYPE MapType);	// マップセッター
	CGame::MAP_TYPE	GetMapType(void);						// マップゲット
	void			SetGoal(bool bGoal);					// ゴール機能セッター
	bool			GetGoal(void);							// ゴール機能ゲッター
private:

	bool			m_bGoal;		//ゴール機能が動いているか
	CGame::MAP_TYPE	m_MapType;		//現在のマップ取得

};
#endif