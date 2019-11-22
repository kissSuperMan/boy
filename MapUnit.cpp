///地图的一个单位
#include "MapUnit.h"
#include <ctime>

MyList* MapUnit::buildCoList = new MyList();					//建筑碰撞表 ，碰撞表同时也是渲染依据
MyList* MapUnit::peopleCoList = new MyList();

vector<MapUnit* > MapUnit::allGameVector = {nullptr};

MapUnit::MapUnit()
{
}


MapUnit::~MapUnit()
{

}

void MapUnit::picLoadInUnit(MapUnit *getIns)
{
	int picX = 0;
	int picY = 0;
	for (picY = 0; picY < 5; picY++)
	{
		for (picX = 0; picX < 5; picX++)
		{
			getIns->uinitMap[picY][picX].shape = (getIns->movePicArr[getIns->curPic])[picY * 10 + picX * 2];
			getIns->uinitMap[picY][picX].color = (getIns->movePicArr[getIns->curPic])[picY * 10 + picX * 2 + 1];
		}
	}
}

//内存写入
void MapUnit::writeInCache()
{
	ScreenCache::sc_writeUnitInCacheMap(this);
}
//内存擦除
void MapUnit::mapUnit_erase(MapUnit* getUnit)
{
	ScreenCache::sc_clearUnitInCacheMap(getUnit);
}
//退出表,删除 getUnit 在表中的存在
vector<MapUnit *>::iterator MapUnit::unitMapEraseMe(MapUnit* getUnit)
{
	vector<MapUnit *> ::iterator unitItor = MapUnit::allGameVector.begin() + 1;
	while (unitItor != MapUnit::allGameVector.end())
	{
		if (*unitItor == getUnit)
		{
			return MapUnit::allGameVector.erase(unitItor);
		}
		unitItor++;
	}
	cout << "删除的时候出问题了。文件MapUnit" << endl;
	
	return unitItor;
}

int MapUnit::move(int getDir)
{
	return 0;				//0 不发生任何事情
}

//基础移动，对xy处理
void MapUnit::mapUnitBaseMove(int getDir)
{
	switch (getDir)
	{
	case DIR_UP:
		this->posBase.yUp -= 1;
		break;
	case DIR_DOWN:
		this->posBase.yUp += 1;
		break;
	case DIR_LEFT:
		this->posBase.xLeft -= 1;
		break;
	case DIR_RIGHT:
		this->posBase.xLeft += 1;
		break;
	}
}

//单独检测碰撞
//返回值是碰到的物体的名字， 在建筑和人物的结算上优先结算人物，这个逻辑没有写好，真应该返回一个结构体
int MapUnit::collisionCheckSingal(MapUnit* actiUnit, MapUnit** other)
{
	bool boomHit = false;				//撞到炸弹
	for (MyNode* one = MapUnit::peopleCoList->firstNode->nextPtr; one != MapUnit::peopleCoList->LastNode; one = one->nextPtr)
	{
		if (collisionCheck(actiUnit, one->node))
		{
			if (one->node == actiUnit){ 
				continue; }
			*other = one->node;
			if (one->node->objectName == OBNAME_BOMER)									//11-6 碰到炸弹不要立即返回，接着便利，最后返回
			{
				boomHit = true;
			}
			else
			{
				return one->node->objectName;
			}
		}
	}
	for (MyNode* one = MapUnit::buildCoList->firstNode->nextPtr; one != MapUnit::buildCoList->LastNode; one = one->nextPtr)
	{
		if (collisionCheck(actiUnit, one->node))
		{
			if (actiUnit == one->node)
			{
				continue;
			}
			*other = one->node;
			return one->node->objectName;
		}
	}
	if (boomHit)
	{
		return OBNAME_BOMER;
	}
	return OBNAME_NONAME;
}


//做反向操作
void MapUnit::moveBack(int getDir)
{
	//mapUnit_erase(this);				因为是移动后没有写入内存的所以不要擦除
	switch (getDir)
	{
	case DIR_UP:
		this->posBase.yUp += 1;
		break;
	case DIR_DOWN:
		this->posBase.yUp -= 1;
		break;
	case DIR_LEFT:
		this->posBase.xLeft += 1;
		break;
	case DIR_RIGHT:
		this->posBase.xLeft -= 1;
		break;
	}
}

bool map_pixInBox(int x, int y, ObjectInfo* passPos)
{
	if (x >= passPos->xLeft && x < (passPos->xLeft + passPos->wide))
	{
		if (y >= passPos->yUp&&y < (passPos->yUp + passPos->high))
		{
			return true;
		}
	}
	return false;
}
bool MapUnit::collisionCheck(MapUnit* actiUnit, MapUnit* passUnit)
{
	int aX = 0;
	int aY = 0; 
	for (aY = 0; aY < actiUnit->posBase.high;aY++)
	{
		for (aX = 0; aX < actiUnit->posBase.wide; aX++)
		{
			if (map_pixInBox(aX+actiUnit->posBase.xLeft,aY+actiUnit->posBase.yUp,&(passUnit->posBase) ) )
			{
				return true;
			}
		}
	}
	return false;
}

int MapUnit::collisionTriger()
{
	return 0;						//等待子类实现
}
int  MapUnit::destoryMe()
{
	cout << "父类调用触发，报错了" << endl;

	this->mapUnit_erase(this);

	MapUnit::peopleCoList->deleteNode(this);

	delete this;
	return 0;
}



void MapUnit::trigerTime()
{
	
}



