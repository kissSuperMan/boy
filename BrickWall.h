//שǽ
#pragma once
#include "MapUnit.h"
class BrickWall :
	public MapUnit
{
public:
	BrickWall(int x,int y);
	virtual ~BrickWall();
	virtual int collisionTriger();				//������ײ
	virtual int destoryMe();
};

