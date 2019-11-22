#pragma once
#include "publicDef.h"
#include "Sence.h"
#include <vector>
struct SenceMassage
{
	int curSen;			//当前场景
	int OverMess;		//游戏结束的信息
};
struct ScoreBoard
{
	int boomTotal;
	int killEnemy;
	int getAward;
	int killBrick;
	int scoreVal;
};
class Director
{
public:
	static ScoreBoard scoreFinnal;			//最终得分
//	vector<Sence*> senceVec;
	static SenceMassage senceMess;
	static int dir_getKeyboard();		//	 获取按键
	static void debugRulerDraw();
	Director();
	~Director();
	void loadDirSence();					//  初始化加载场景
	void runSence();					//  运行场景
	static void scoreClear();
	void readyCmd();
};

