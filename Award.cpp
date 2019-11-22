#include "Award.h"
#include "Bomber.h"
#include "HeroPlayer.h"
Award::Award(int x,int y)
{
	HeroPlayer::monney += 20;
	this->objectName = OBNAME_BRWALL;				//伪装成墙壁
	this->posBase.xLeft = x;
	this->posBase.yUp = y;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	this->movePicArr[0] = powerAdd;					   
	this->curPic = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			this->uinitMap[i][j].shape = SHAPE_RECT_EM;
			this->uinitMap[i][j].color = SCTX_WHITE;
		}
	}
}


Award::~Award()
{
}
int Award::destoryMe()
{ 
	if (this->objectName == OBNAME_BRWALL)
	{
		this->objectName = OBNAME_BR_AWARD;					//变成奖励
		this->picLoadInUnit(this);
		return 0;
	}
	else
	{
		Director::scoreFinnal.getAward++;
		
		if (Bomber::boomPower < 4)
		{
			Bomber::boomPower++;
		}
		
		this->mapUnit_erase(this);
		MapUnit::buildCoList->deleteNode(this);
		delete this;
		return 0;
	}
}
