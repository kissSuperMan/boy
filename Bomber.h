#pragma once
#include "MapUnit.h"
#define BOM_FRAMETIME 5
class Bomber :
	public MapUnit
{
public:

	static int timeUp;
	static int boomPower;							//��ը������
	int bomClock = 0;								//ʱ�䶨ʱ
	int showTime = 0;								//��ʾ��ʱ��
	static int bomberNum;
	virtual void writeInCache();  //����Ⱦ
	Bomber(int _x, int _y);
	virtual ~Bomber();

	virtual int destoryMe();	
	int move(int dir);
};

