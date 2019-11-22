//游戏类，后期作为关卡类的基类

#include "GameSence.h"
#include "HeroPlayer.h"
#include "TimeCon.h"
#include "Director.h"
#include "ReadFile.h"
#include "ScreenCache.h"
#include "Monster.h"
#include "Bomber.h"
#include "TipBoard.h"

GameSence::GameSence()
{
}

void GameSence::runThisSence()
{
	system("cls");
	int dirThis = DIR_KB_NULL;

	TimeCon::createOneTimer(200);														//开栈 定时器
	TimeCon::createOneTimer(150);
	TimeCon::createOneTimer(TIME_TIP_RAD);
	
	MapUnit* heroThis = new HeroPlayer(0, 0);
	MapUnit::peopleCoList->add(heroThis);
//	Director::debugRulerDraw();															//调试的刻度
	ReadFile::readoutFile();															//读出map
	ScreenCache::sc_fileMapToCache();																//map的元素实例化成人物
	sc_frameShow();																		//显示边框
	
	while (Director::senceMess.curSen == SENCE_RAND_ONE)
	{
	

		dirThis = Director::dir_getKeyboard();
		
		
		if (dirThis)																	//给英雄判断
		{
			heroThis->move(dirThis);
			dirThis = 0;
			TimeCon::createOneTimer(250);
			while (1)
			{
				Director::dir_getKeyboard();
				if (TimeCon::isTimeControlTriger(250))
				{
					TimeCon::deletOne(250);
					break;
				}
			}
		}
		if (TimeCon::isTimeControlTriger(150))
		{
			for (MyNode* one = MapUnit::peopleCoList->firstNode->nextPtr; one != MapUnit::peopleCoList->LastNode; one = one->nextPtr)
			{
				one->node->trigerTime();
				one->node->writeInCache();
			}
		}
		if (TimeCon::isTimeControlTriger(TIME_TIP_RAD))
		{
			TipBoard::showPro();														//积分版
		}
		if (TimeCon::isTimeControlTriger(TIME_HERO_UNSTOP))
		{
			HeroPlayer::isUnstop = false;
			heroThis->curPic = 0;
			heroThis->picLoadInUnit(heroThis);//
			TimeCon::deletOne(TIME_HERO_UNSTOP);
		}
		if (TimeCon::isTimeControlTriger(200) || Director::senceMess.curSen != SENCE_RAND_ONE)				//后面的不是本关卡的时候也要刷新
		{
			MyNode* preNode = nullptr;
			//移动遍历//（碰撞遍历）嵌套在move中
			for (MyNode* one = MapUnit::peopleCoList->firstNode->nextPtr; one != MapUnit::peopleCoList->LastNode; one = one->nextPtr)
			{	
				preNode = one->prePtr;
				int name = one->node->objectName;
				if (one->node->objectName == OBNAME_HERO)
				{
					continue;																	//英雄的移动不是放在这里
				}
				if (one->node->move(0))
				{
					one = preNode;
					if (name == OBNAME_FIRE)											//火焰消灭是自我消灭，不用break
					{
					}
					else{
						break;
					}																//在发生destory的情况下，可能多个人物被消灭，指向pre不安全
					
				}
			}
			//渲染遍历
			for (MyNode* one = MapUnit::peopleCoList->firstNode->nextPtr; one != MapUnit::peopleCoList->LastNode; one = one->nextPtr)
			{
				one->node->writeInCache();
			}
			for (MyNode* one = MapUnit::buildCoList->firstNode->nextPtr; one != MapUnit::buildCoList->LastNode; one = one->nextPtr)
			{
				one->node->writeInCache();
			}
			ScreenCache::sc_showMapCache();

		}
		if (Monster::monsterNum == 0)
		{
			Director::senceMess.OverMess = MESS_SUCC_OVER;
			Director::senceMess.curSen = SENCE_OVER;
		}
		else if (HeroPlayer::blood == 0)												//没血就是死了
		{
			Director::senceMess.OverMess = MESS_FAIL_OVER;
			Director::senceMess.curSen = SENCE_OVER;
		}
	}
}

void GameSence::overThisSence()
{
	TimeCon::createOneTimer(400);
	while (true)
	{
		if (TimeCon::isTimeControlTriger(400))					//400毫秒延迟
		{
			break;
		}
	}
	TimeCon::clearTime();
	MapUnit::peopleCoList->clear();
	MapUnit::buildCoList->clear();
	ScreenCache::clearHistoryMap();
	Bomber::bomberNum = 0;
}


//显示边框
void GameSence::sc_frameShow()
{
	PainterInfo giveInfo;
	
	giveInfo.useCharIndex = 1;									//边框的shapeIndex
	for (int i = 0; i < SCGAFRAME_WIDE; i += 2)
	{
		giveInfo.x = i + SC_X_BASE;
		giveInfo.y = SC_Y_BASE;
		ScreenCache::sc_paintOnePix(&giveInfo);
		giveInfo.y = SC_Y_BASE + SCGAFRAME_HIGH-1;
		ScreenCache::sc_paintOnePix(&giveInfo);
	}
	for (int i = 0; i < SCGAFRAME_HIGH; i++)
	{
		giveInfo.y = i + SC_Y_BASE;
		giveInfo.x = SC_X_BASE;
		ScreenCache::sc_paintOnePix(&giveInfo);
		giveInfo.x = SC_X_BASE + SCGAFRAME_WIDE-2;
		ScreenCache::sc_paintOnePix(&giveInfo);
	}
}

GameSence::~GameSence()
{

}



