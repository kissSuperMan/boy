#pragma once
#include "MapUnit.h"
#include "DialogueC.h"
class Market :
	public MapUnit, DialogueC
{
public:
	Market::Market(int _x, int _y);
	virtual ~Market();
	int virtual destoryMe();
	virtual int collisionTriger();								
};

