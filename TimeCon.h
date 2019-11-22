#pragma once
#include "publicDef.h"
#include <ctime>
#include <map>
#define TIME_HERO_UNSTOP 5000		//无敌时间
#define TIME_TIP_RAD 600			//tip的刷新时间



class TimeCon
{
private:
	TimeCon(int time);
	virtual ~TimeCon();
public:
	static bool isTimeControlTriger(int interTime);	//中断是否被触发
	static void createOneTimer(int interTime);
	static void clearTime();
	static void deletOne(int interTime);			//单独删除
private:
	static map<int, TimeCon*> timeMap;				//一个多点中断的容器
	long interruptTime;								//中断时间
	clock_t curTime;								//记录当前时间
};

