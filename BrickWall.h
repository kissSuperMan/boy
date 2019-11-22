//×©Ç½
#pragma once
#include "MapUnit.h"
class BrickWall :
	public MapUnit
{
public:
	BrickWall(int x,int y);
	virtual ~BrickWall();
	virtual int collisionTriger();				//´¥·¢Åö×²
	virtual int destoryMe();
};

