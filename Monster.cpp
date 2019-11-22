#include "Monster.h"
#include "Director.h"
#include "HeroPlayer.h"
int Monster::monsterNum = 0;

Monster::Monster(int _x,int _y)
{
	monsterNum++;
	this->objectName = OBNAME_ENEMY;
	this->posBase.yUp = _y;
	this->posBase.xLeft = _x;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	this->curPic = 0;
	this->rememDir = DIR_RIGHT;

	this->movePicArr[0] = monsterStateA;
	this->movePicArr[1] = monsterStateB;
	this->movePicArr[2] = monsterStateC;

	this->movePicArr[3] = monsterStateE;
	this->movePicArr[4] = monsterStateF;
	this->movePicArr[5] = monsterStateG;

	this->picLoadInUnit(this);
}


Monster::~Monster()
{
}

int Monster::collisionTriger()
{
	return 0;
}

void dirBackTurn(int *dir);
void dirChange(int *dir);
int Monster::move(int getDir)
{
	bool boardFlag = false;
	int hitName = 0;																										//碰撞到的人是否有
	mapUnit_erase(this);
	this->mapUnitBaseMove(this->rememDir);
	
	if (posBase.xLeft < 0){ posBase.xLeft = 0; boardFlag = true; }																//内存边界
	if (posBase.yUp  < 0){ posBase.yUp = 0; boardFlag = true; }
	if (posBase.xLeft >= GAMEMAP_WIDE - SC_X_PIX){ posBase.xLeft = GAMEMAP_WIDE - SC_X_PIX; boardFlag = true; }					// GAMEMAP_WIDE
	if (posBase.yUp >= GAMEMAP_HIGH - SC_Y_PIX){ posBase.yUp = GAMEMAP_HIGH - SC_Y_PIX; boardFlag = true; }
	
	MapUnit *other = nullptr;
	hitName = MapUnit::collisionCheckSingal(this,&other);
	
	if (hitName || boardFlag)
	{
		if (hitName == OBNAME_HERO)
		{
			for (MyNode* one = MapUnit::peopleCoList->firstNode->nextPtr; one != MapUnit::peopleCoList->LastNode; one = one->nextPtr)
			{
				if (one->node->objectName == OBNAME_HERO)																		//队列里面找到 HERO 
				{
					one->node->destoryMe();
					break;				
				}
			}
		}

		this->moveBack(this->rememDir);
		dirBackTurn(&this->rememDir);
		tryMove++;
		if (tryMove>5)
		{
			dirChange(&this->rememDir);
			tryMove = 0;
		}
	}
	else 
	{
		tryMove = 0;
	}
//	this->writeInCache();																		//这里不渲染，由渲染函数来调用
	return 0;
}

void dirBackTurn(int *dir)
{
	if (*dir == DIR_UP){ *dir = DIR_DOWN; }
	else if (*dir == DIR_DOWN){ *dir = DIR_UP; }
	else if (*dir == DIR_LEFT){ *dir = DIR_RIGHT; }
	else if (*dir == DIR_RIGHT){ *dir = DIR_LEFT; }
}
void dirChange(int *dir)
{
	if (*dir == DIR_UP){ *dir = DIR_LEFT; }
	else if (*dir == DIR_DOWN){ *dir = DIR_LEFT; }
	else if (*dir == DIR_LEFT){ *dir = DIR_UP; }
	else if (*dir == DIR_RIGHT){ *dir = DIR_UP; }
}


//destory
int Monster::destoryMe()
{
	HeroPlayer::monney += 8;
	Director::scoreFinnal.killEnemy++;
	monsterNum--;
	this->mapUnit_erase(this);
	MapUnit::peopleCoList->deleteNode(this);
	delete this;
	return 0;
}

//加载表情
void Monster::trigerTime()
{
	static int thisTime = 0;
	static int arrLe[6] = { 3, 4,4, 5, 5, 3 };
	static int arrUp[6] = { 0, 1,1, 2, 2, 0 };
	static unsigned int index = 0;		//0--5

	
}











