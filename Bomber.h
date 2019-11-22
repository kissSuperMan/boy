#pragma once
#include "MapUnit.h"
#define BOM_FRAMETIME 5
class Bomber :
	public MapUnit
{
public:

	static int timeUp;
	static int boomPower;							//爆炸的威力
	int bomClock = 0;								//时间定时
	int showTime = 0;								//显示的时间
	static int bomberNum;
	virtual void writeInCache();  //不渲染
	Bomber(int _x, int _y);
	virtual ~Bomber();

	virtual int destoryMe();	
	int move(int dir);
};

