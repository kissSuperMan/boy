#pragma once
#include "publicDef.h"
#include <ctime>
#include <map>
#define TIME_HERO_UNSTOP 5000		//�޵�ʱ��
#define TIME_TIP_RAD 600			//tip��ˢ��ʱ��



class TimeCon
{
private:
	TimeCon(int time);
	virtual ~TimeCon();
public:
	static bool isTimeControlTriger(int interTime);	//�ж��Ƿ񱻴���
	static void createOneTimer(int interTime);
	static void clearTime();
	static void deletOne(int interTime);			//����ɾ��
private:
	static map<int, TimeCon*> timeMap;				//һ������жϵ�����
	long interruptTime;								//�ж�ʱ��
	clock_t curTime;								//��¼��ǰʱ��
};

