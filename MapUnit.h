//��ͼ��Ԫ <- ��ɫ ǽ�嶼�̳��ڴ�

#pragma once
#include "ObjectBase.h"
#include "ScreenCache.h"
#include "animationLib.h"		//��ͼ�Ŀ��ļ�
#include "MyList.h"				//�Զ���������
#include "Director.h"
#include <vector>
#include <Ctime>
class MyList;
class MapUnit :
	public ObjectBase
{
public:
	/*************************��vector����ز���***************************/
	static vector<MapUnit* > allGameVector;				//���е�����								//���ϵ� vec������ɾ��
	static MyList *buildCoList;					//������ײ�� ����ײ��ͬʱҲ����Ⱦ����
	static MyList *peopleCoList;				//������ײ��
	SC_Pix  uinitMap[SC_Y_PIX][SC_X_PIX];				//��ͼ��λ�Ļ���
	int* movePicArr[6];			// [5] = { nullptr };	//�ڲ��洢6�Ŷ���
	int curPic = 0;
	clock_t curTime;


public:
	static vector<MapUnit *>::iterator unitMapEraseMe(MapUnit* getUnit);						//��vector����ɾ������
	void picLoadInUnit(MapUnit *getIns);				//ͼ�������������
	void mapUnit_erase(MapUnit* getUnit);				//�ڴ����
	
	virtual void mapUnitBaseMove(int getDir);						//�����ƶ�����xy����

	virtual int move(int getDir);						//������ƶ�,
	virtual void moveBack(int getDir);
	virtual void writeInCache();								//�������ݵ����ڴ�
	
	virtual int collisionTriger();								//������ײ �Ļص�����
	virtual int destoryMe();									//�����Լ��Ĵ���
	
	static bool collisionCheck(MapUnit* actiUnit,MapUnit* passUnit);
	static int collisionCheckSingal(MapUnit* actiUnit,MapUnit** otherUnit);								//����ֵ����ײ����˭
	
//	void createTime(int timeDelay);							//���������ʱ��
	virtual void trigerTime();								//gamesence ���ã��̶�ʱ�䴥���������嵽��һ����ʱ���Ҫ�����һЩ���飬����ʵ��
	
	/******************************************************/
	MapUnit();
	virtual ~MapUnit();
};






