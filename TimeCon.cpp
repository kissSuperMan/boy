#include "TimeCon.h"

map<int, TimeCon*> TimeCon::timeMap;

TimeCon::TimeCon(int time)
{
	this->interruptTime = time;
	this->curTime = clock();
}
void TimeCon::createOneTimer(int time)
{
	timeMap.insert( pair<int, TimeCon*>(time, new TimeCon(time) ) );
}
void TimeCon::clearTime()
{
	timeMap.clear();
}

bool TimeCon::isTimeControlTriger(int timeNum)
{
	map<int, TimeCon*>::iterator itM = timeMap.find(timeNum);
	if (itM == timeMap.end()){	return false;}

	if (clock() - itM->second->curTime >= itM->second->interruptTime)
	{
		itM->second->curTime = clock();
		return true;
	}
	return false;
}

void TimeCon::deletOne(int timeNum)
{
	map<int, TimeCon*>::iterator itM = timeMap.find(timeNum);
	if (itM == timeMap.end()){ return ; }
	else
	{
		timeMap.erase(itM);				//É¾³ýÕâ¸ö
	}
}

//TimeCon::
TimeCon::~TimeCon()
{
	
}
