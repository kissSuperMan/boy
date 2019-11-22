#include "BuffFood.h"
#include "HeroPlayer.h"
//给 钥匙 ，金币，显式的血包

BuffFood::BuffFood(int _x,int _y,int obName)
{
	this->objectName = obName;
	if (this->objectName == OBNAME_FDMONY)
	{
		this->movePicArr[0] = moneyState;		
	}
	else if (this->objectName == OBNAME_FDKEY)
	{
		this->movePicArr[0] = keyState;
	}
	else if (this->objectName == OBNAME_FDBLOOD)
	{
		this->movePicArr[0] = heartState;
	}
	else if (this->objectName == OBNAME_FDBOM)
	{
		this->movePicArr[0] = giveBomberState;
	}
	else
	{
		this->movePicArr[0] = linxinState;		//异常 ， 用菱形代替
	}
	this->posBase.xLeft = _x;
	this->posBase.yUp = _y;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	this->curPic = 0;
	this->picLoadInUnit(this);
}


BuffFood::~BuffFood()
{
}
int BuffFood::collisionTriger()
{
	if (this->objectName == OBNAME_FDMONY)
	{
		HeroPlayer::monney += 5;
	}
	else if (this->objectName == OBNAME_FDKEY)
	{
		HeroPlayer::keyNum++;
	}
	else if (this->objectName == OBNAME_FDBLOOD)
	{
		HeroPlayer::blood++;
	}
	else if (this->objectName == OBNAME_FDBOM)
	{
		HeroPlayer::boomberMax += 5;
	}
	this->mapUnit_erase(this);
	MapUnit::buildCoList->deleteNode(this);
	delete this;
	return 0;
}
int BuffFood::destoryMe()
{
	return 1;
}





