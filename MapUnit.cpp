///��ͼ��һ����λ
#include "MapUnit.h"
#include <ctime>

MyList* MapUnit::buildCoList = new MyList();					//������ײ�� ����ײ��ͬʱҲ����Ⱦ����
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

//�ڴ�д��
void MapUnit::writeInCache()
{
	ScreenCache::sc_writeUnitInCacheMap(this);
}
//�ڴ����
void MapUnit::mapUnit_erase(MapUnit* getUnit)
{
	ScreenCache::sc_clearUnitInCacheMap(getUnit);
}
//�˳���,ɾ�� getUnit �ڱ��еĴ���
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
	cout << "ɾ����ʱ��������ˡ��ļ�MapUnit" << endl;
	
	return unitItor;
}

int MapUnit::move(int getDir)
{
	return 0;				//0 �������κ�����
}

//�����ƶ�����xy����
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

//���������ײ
//����ֵ����������������֣� �ڽ���������Ľ��������Ƚ����������߼�û��д�ã���Ӧ�÷���һ���ṹ��
int MapUnit::collisionCheckSingal(MapUnit* actiUnit, MapUnit** other)
{
	bool boomHit = false;				//ײ��ը��
	for (MyNode* one = MapUnit::peopleCoList->firstNode->nextPtr; one != MapUnit::peopleCoList->LastNode; one = one->nextPtr)
	{
		if (collisionCheck(actiUnit, one->node))
		{
			if (one->node == actiUnit){ 
				continue; }
			*other = one->node;
			if (one->node->objectName == OBNAME_BOMER)									//11-6 ����ը����Ҫ�������أ����ű�������󷵻�
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


//���������
void MapUnit::moveBack(int getDir)
{
	//mapUnit_erase(this);				��Ϊ���ƶ���û��д���ڴ�����Բ�Ҫ����
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
	return 0;						//�ȴ�����ʵ��
}
int  MapUnit::destoryMe()
{
	cout << "������ô�����������" << endl;

	this->mapUnit_erase(this);

	MapUnit::peopleCoList->deleteNode(this);

	delete this;
	return 0;
}



void MapUnit::trigerTime()
{
	
}



