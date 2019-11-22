#include "HeroPlayer.h"
#include "Bomber.h"
#include "Monster.h"
#include "TimeCon.h"
int HeroPlayer::heroNum = 1;
int HeroPlayer::blood = 3;
int HeroPlayer::monney = 4;
int HeroPlayer::boomberMax = 2;
int HeroPlayer::killNum = 0;
int HeroPlayer::keyNum = 0;

bool HeroPlayer::isUnstop =false;
HeroPlayer::HeroPlayer(int _x,int _y)
{
	heroNum++;
	isUnstop = false;

	 HeroPlayer::blood = 3;
	 HeroPlayer::monney = 4;
	 HeroPlayer::boomberMax = 2;
	 HeroPlayer::killNum = 0;
	 HeroPlayer::keyNum = 0;			//Կ����

	this->objectName = OBNAME_HERO;
	this->posBase.xLeft = _x;
	this->posBase.yUp = _y;
	this->posBase.wide = 5;
	this->posBase.high = 5; 
	this->movePicArr[0] = heroState;						//heroRightMoveA
	this->movePicArr[1] = heroStateUnstop;
	this->movePicArr[2] = heroRightMoveB;
	this->movePicArr[3] = heroRightMoveC;
	this->movePicArr[4] = heroRightMoveD;
	this->movePicArr[5] = heroRightMoveD;
	this->curPic = 0;
	this->picLoadInUnit(this);
}

int HeroPlayer::move(int getDir)
{
	int collisionName = 0;
	
	//���µĲ��ǿո��Ƿ���
	if (getDir != DIR_SPACE)
	{
		mapUnit_erase(this);
		this->mapUnitBaseMove(getDir);
		if (posBase.xLeft < 0){ posBase.xLeft = 0; }																//�ڴ�߽�
		if (posBase.yUp < 0){ posBase.yUp = 0; }
		if (posBase.xLeft >= GAMEMAP_WIDE - SC_X_PIX){ posBase.xLeft = GAMEMAP_WIDE - SC_X_PIX; }							// GAMEMAP_WIDE
		if (posBase.yUp >= GAMEMAP_HIGH - SC_Y_PIX){ posBase.yUp = GAMEMAP_HIGH - SC_Y_PIX; }

		//�����λ
		if (this->posBase.xLeft-SC_FOLL_WIDE - ScreenCache::cacheStX < 0)
		{
			ScreenCache::cacheStX -= moveUnit;
		}
		if (this->posBase.yUp-SC_FOLL_HIGH - ScreenCache::cacheStY < 0){
			ScreenCache::cacheStY -= moveUnit;
		}
		if (this->posBase.xLeft + SC_FOLL_WIDE>ScreenCache::cacheStX + SCGA_WIDE - SC_X_PIX){
			ScreenCache::cacheStX += moveUnit;
		}
		if (this->posBase.yUp+SC_FOLL_HIGH>ScreenCache::cacheStY + SCGA_HIGH - SC_Y_PIX){
			ScreenCache::cacheStY += moveUnit;
		}
		MapUnit *other = nullptr;
		collisionName = MapUnit::collisionCheckSingal(this, &other);
		
		//this->curPic++;
		//if (curPic >= 5){ curPic = 1; }								//ˢ��ͼƬ  ���ڸ���ͼƬ��̫�鷳
		//this->picLoadInUnit(this);
		if (collisionName == OBNAME_NONAME)
		{
		}
		else if (collisionName == OBNAME_BOMER)						
		{

		}
		else if (collisionName == OBNAME_BR_DOOR || collisionName/10 == OBNAME_FOOD/10)
		{
			//other->destoryMe();										
			other->collisionTriger();							//������,Ѫ��Կ�ף�Ǯ,ը������
		}
		else if (collisionName == OBNAME_ENEMY)						//������ײ
		{
			this->destoryMe();
			return 0;
		}
		else if (collisionName == OBNAME_BR_AWARD)
		{
			other->destoryMe();
		}
		else if (collisionName == OBNAME_MARKET)
		{
			other->collisionTriger();								//�����̵�Ľ���
			this->moveBack(getDir);
		}
		else
		{
			this->moveBack(getDir);
		}
	}
	else if (getDir == DIR_SPACE)
	{
		if (Bomber::bomberNum == 0 && (HeroPlayer::boomberMax>0))
		{
			Bomber *one = new Bomber(this->posBase.xLeft,this->posBase.yUp);
			MapUnit::peopleCoList->add(one);													//�������ը��
			Bomber::bomberNum++;
			HeroPlayer::boomberMax--;
		}
	}
	this->writeInCache();						//�ƶ���ʵʱˢ��
	return 0;
}

//�����ƶ�����xy����
void HeroPlayer::mapUnitBaseMove(int getDir)
{
	switch (getDir)
	{
	case DIR_UP:
		this->posBase.yUp -= moveUnit;
		break;
	case DIR_DOWN:
		this->posBase.yUp += moveUnit;
		break;
	case DIR_LEFT:
		this->posBase.xLeft -= moveUnit;
		break;
	case DIR_RIGHT:
		this->posBase.xLeft += moveUnit;
		break;
	}
}
//
void HeroPlayer::moveBack(int getDir)
{
	//mapUnit_erase(this);				��Ϊ���ƶ���û��д���ڴ�����Բ�Ҫ����
	switch (getDir)
	{
	case DIR_UP:
		this->posBase.yUp += moveUnit;
		break;
	case DIR_DOWN:
		this->posBase.yUp -= moveUnit;
		break;
	case DIR_LEFT:
		this->posBase.xLeft += moveUnit;
		break;
	case DIR_RIGHT:
		this->posBase.xLeft -= moveUnit;
		break;
	}
}

HeroPlayer::~HeroPlayer()
{
}
int HeroPlayer::collisionTriger()
{

	return 0;
}
int HeroPlayer::destoryMe()
{
	if (this->blood > 0)
	{
		if (isUnstop == false)
		{
			this->blood--;
			isUnstop = true;
			this->curPic = 1;
			this->picLoadInUnit(this);
			TimeCon::createOneTimer(TIME_HERO_UNSTOP);					//�����ﴥ��������GameSence��д�ж�
		}
		return 1;														//
	}


	this->mapUnit_erase(this);
	MapUnit::peopleCoList->deleteNode(this);
	delete this;
	return 0;
}


//���ر���
void HeroPlayer::trigerTime()
{
	static int recodeEn = Monster::monsterNum;
	static int thisTime = 0;
	if (recodeEn != Monster::monsterNum)
	{
		recodeEn = Monster::monsterNum;
		thisTime = 9;												//�������ʱ��
	}
	//if(thisTime)
	//{
	//	thisTime--;
	//	this->uinitMap[1][1].shape = 35;					//����
	//	this->uinitMap[1][3].shape = 36;
	//	this->uinitMap[2][2].shape = 31;					//���
	//	return;
	//}														//����
	//this->uinitMap[1][1].shape = 37;						//����
	//this->uinitMap[1][3].shape = 37;		
	//this->uinitMap[2][2].shape = 38;						//���
}




