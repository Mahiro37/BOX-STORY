//=============================================================================
//
// ステージ [stage base.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _STAGE_BASE_H_
#define _STAGE_BASE_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "model.h"
//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_STAGE_SIZE_X	(50)	//最大ブロック数
#define MAX_STAGE_SIZE_Y	(50)	//最大ステージサイズ
#define MAX_STAGE_COUNT		(3)		//最大ステージ数

//=============================================================================
//  前方宣言
//=============================================================================
class CPlayer;

typedef struct //一行のブロック情報
{
	int			nBlockType[MAX_STAGE_SIZE_X];	//ブロックデータ
	int			nStageSizeX;					//その行のブロック数
}BLOCK_DATA;

typedef struct	//ステージ情報
{
	BLOCK_DATA	BlockData[MAX_STAGE_SIZE_Y];	//ブロック
	int			nStageSizeY;					//ブロックの列
}MAP_DATA;

//=============================================================================
// クラス定義
//=============================================================================
class CStageBase
{
public:

	CStageBase();
	virtual ~CStageBase();
	virtual HRESULT Init(void) = 0;
	virtual void	Uninit(void) = 0;
	virtual void	Draw(void) = 0;
	virtual void	Update(void) = 0;
	
	virtual void	MapCreate(void) = 0;	//マップの生成
private:
};
#endif
