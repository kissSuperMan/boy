#pragma once
#include "MapUnit.h"
class Award :
	public MapUnit
{
public:
	//int recode = 1;										//记录当前状态 为1时他的名字是 Brickname
	Award(int x, int y);
	virtual ~Award();

	virtual int destoryMe();
};

