#pragma once
#include "publicDef.h"
#include "Sence.h"
#include <vector>
struct SenceMassage
{
	int curSen;			//��ǰ����
	int OverMess;		//��Ϸ��������Ϣ
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
	static ScoreBoard scoreFinnal;			//���յ÷�
//	vector<Sence*> senceVec;
	static SenceMassage senceMess;
	static int dir_getKeyboard();		//	 ��ȡ����
	static void debugRulerDraw();
	Director();
	~Director();
	void loadDirSence();					//  ��ʼ�����س���
	void runSence();					//  ���г���
	static void scoreClear();
	void readyCmd();
};

