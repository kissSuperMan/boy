#pragma once
#include "MapUnit.h"
class BuffFood :
	public MapUnit
{
public:
	BuffFood(int _x, int _y, int obName);
	virtual ~BuffFood();
	virtual int destoryMe();
	virtual int collisionTriger();
};


