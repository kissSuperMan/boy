#pragma once
#include "MapUnit.h"
class OutDoor :
	public MapUnit
{
public:
	OutDoor(int _x, int _y);
	virtual ~OutDoor();
	virtual int destoryMe();
	virtual int collisionTriger();
};

