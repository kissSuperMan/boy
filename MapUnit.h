//地图单元 <- 角色 墙体都继承于此

#pragma once
#include "ObjectBase.h"
#include "ScreenCache.h"
#include "animationLib.h"		//动图的库文件
#include "MyList.h"				//自定义链表类
#include "Director.h"
#include <vector>
#include <Ctime>
class MyList;
class MapUnit :
	public ObjectBase
{
public:
	/*************************对vector的相关操作***************************/
	static vector<MapUnit* > allGameVector;				//所有的物体								//作废的 vec，后期删除
	static MyList *buildCoList;					//建筑碰撞表 ，碰撞表同时也是渲染依据
	static MyList *peopleCoList;				//人物碰撞表
	SC_Pix  uinitMap[SC_Y_PIX][SC_X_PIX];				//地图单位的缓存
	int* movePicArr[6];			// [5] = { nullptr };	//内部存储6张动画
	int curPic = 0;
	clock_t curTime;


public:
	static vector<MapUnit *>::iterator unitMapEraseMe(MapUnit* getUnit);						//从vector表中删除存在
	void picLoadInUnit(MapUnit *getIns);				//图像数据载入对象
	void mapUnit_erase(MapUnit* getUnit);				//内存擦出
	
	virtual void mapUnitBaseMove(int getDir);						//基础移动，对xy处理

	virtual int move(int getDir);						//物体的移动,
	virtual void moveBack(int getDir);
	virtual void writeInCache();								//物体数据导入内存
	
	virtual int collisionTriger();								//触发碰撞 的回调函数
	virtual int destoryMe();									//消灭自己的存在
	
	static bool collisionCheck(MapUnit* actiUnit,MapUnit* passUnit);
	static int collisionCheckSingal(MapUnit* actiUnit,MapUnit** otherUnit);								//返回值是碰撞到了谁
	
//	void createTime(int timeDelay);							//创建自身的时间
	virtual void trigerTime();								//gamesence 调用，固定时间触发，该物体到了一定的时间就要处理的一些事情，子类实例
	
	/******************************************************/
	MapUnit();
	virtual ~MapUnit();
};






