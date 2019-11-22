#include "OutDoor.h"
#include "HeroPlayer.h"

OutDoor::OutDoor(int _x,int _y)
{
	this->objectName = OBNAME_BR_DOOR;
	this->posBase.xLeft = _x;
	this->posBase.yUp = _y;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	this->movePicArr[0] = outDoor;
	this->curPic = 0;
	this->picLoadInUnit(this);
}


OutDoor::~OutDoor()
{
}

int OutDoor::collisionTriger()
{
	if (HeroPlayer::keyNum > 0)
	{

		Director::senceMess.curSen = SENCE_OVER;
		Director::senceMess.OverMess = MESS_SUCC_OVER;

		this->mapUnit_erase(this);
		MapUnit::buildCoList->deleteNode(this);
		delete this;
	}
	
	return 0;
}

int OutDoor::destoryMe()
{
	return 1;
}



