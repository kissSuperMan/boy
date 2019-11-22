#pragma once
#include "MapUnit.h"
#define FACE_SMILE   1			//w 
#define FACE_NORMAL 2			//-

//#define 
class HeroPlayer :
	public MapUnit
{
public:
	static int heroNum;
	static int boomberMax;							//拥有的炸弹树木
	static int monney;								//金币数量
	static int blood;								//
	static bool isUnstop;
	static int killNum;
	static int keyNum;					

	int moveUnit = 5;							//移动像素点
	
	//virtual void move(int getDir);
	//void writeInCache();							//test
	void loadFace(int typeFace);				//参数表情的类型
	
	HeroPlayer(int _x, int _y);
	virtual ~HeroPlayer();
	int virtual collisionTriger();
	void virtual trigerTime();
	void virtual mapUnitBaseMove(int getDir);
	void virtual moveBack(int getDir);
	int move(int getDir);
	virtual int destoryMe();
};

