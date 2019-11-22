#include "BrickWall.h"
#include "Director.h"
#include "HeroPlayer.h"
BrickWall::BrickWall(int x,int y)
{
	this->objectName = OBNAME_BRWALL;
	this->posBase.xLeft = x;
	this->posBase.yUp = y;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0; j < 5; j++)
		{
			this->uinitMap[i][j].shape = SHAPE_RECT_EM;
			this->uinitMap[i][j].color = SCTX_WHITE;
		}
	}
}
int BrickWall::collisionTriger()
{
	return 0;
}

BrickWall::~BrickWall()
{
}

int BrickWall::destoryMe()
{
	HeroPlayer::monney++;
	Director::scoreFinnal.killBrick++;
	this->mapUnit_erase(this);
	MapUnit::buildCoList->deleteNode(this);
	delete this;
	return 0;
	
}



