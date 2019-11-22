#include "Fire.h"

int Fire::timeUp = 8;

Fire::Fire(int _x, int _y)
{
	this->objectName = OBNAME_FIRE;
	this->posBase.xLeft = _x;
	this->posBase.yUp = _y;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			this->uinitMap[i][j].shape = SHAPE_BOM;					
			this->uinitMap[i][j].color = SCTX_RED;
		}
	}

}


Fire::~Fire()
{
}

int Fire::move(int getDir)
{
	this->existTime++;
	if (this->existTime >= this->timeUp)
	{
		destoryMe();
		return 1;
	}
	return 0;
}

//»ðÑæÏú»Ù×Ô¼º
int Fire::destoryMe()
{
	this->mapUnit_erase(this);

	MapUnit::peopleCoList->deleteNode(this);

	delete this;
	return 0;
}


