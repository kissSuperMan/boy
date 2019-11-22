#include "StartSence.h"
#include "PicUnit.h"
#include "TimeCon.h"
#include "Director.h"
#include <string>
#include <list>
#include "MyDouList.h"
StartSence::StartSence()
{
}


StartSence::~StartSence()
{
}

void StartSence::runThisSence()
{
	system("cls");
	PicUnit::startCharInter();
	
	string c_one = "开始游戏";
	string c_two = "详细介绍";
	string c_three = "退出游戏";
	string c_four = "更新地图";
	Button *kaiShi = new Button(42, 25, c_one);
	Button *readBmp = new Button(42, 27, c_four);
	Button *jieShao = new Button(42, 29, c_two);
	Button *tuichu = new Button(42, 31, c_three);
	readBmp->objectName = OBNAME_BT_ST_BMP;
	kaiShi->objectName = OBNAME_BT_ST_KAI;
	jieShao->objectName = OBNAME_BT_ST_JIE;
	tuichu->objectName = OBNAME_BT_ST_EXIT;

	TimeCon::createOneTimer(50);
	kaiShi->isMe = true;
	kaiShi->show();
	jieShao->show();
	tuichu->show();
	readBmp->show();

	MyDouList<Button*> butList;

	butList.add(kaiShi);
	butList.add(readBmp);
	butList.add(jieShao);
	butList.add(tuichu);
	

	int dirThis = DIR_KB_NULL;
	MyDouNode<Button*> *one = new MyDouNode<Button*>(nullptr);
	while (Director::senceMess.curSen == SENCE_START)
	{
		dirThis = Director::dir_getKeyboard();
		if (dirThis == DIR_DOWN || dirThis ==DIR_RIGHT)
		{
			one = butList.first;
			do 
			{
				if (one->node->isMe == true)
				{
					one->nextPtr->node->isMe = true;
					one->node->isMe = false;
					one->node->show();
					one->nextPtr->node->show();
					break;
				}
				one = one->nextPtr;
			} while (one != butList.first);
			//delete one;																		//是否有内存泄露的风险
		}
		else if (dirThis == DIR_UP || dirThis == DIR_LEFT)
		{
			one = butList.first;
			do
			{
				if (one->node->isMe == true)
				{
					one->prePtr->node->isMe = true;
					one->node->isMe = false;
					one->node->show();
					one->prePtr->node->show();
					break;
				}
				one = one->prePtr;
			} while (one != butList.first);
		}
		else if (dirThis == DIR_SPACE)
		{
			one = butList.first;
			do
			{
				if (one->node->isMe == true)
				{
					if (one->node->objectName == OBNAME_BT_ST_KAI)
					{
						Director::senceMess.curSen = SENCE_RAND_ONE;
					}
					else if (one->node->objectName == OBNAME_BT_ST_JIE)
					{
						Director::senceMess.curSen = SENCE_INTRO;
					}
					else if (one->node->objectName == OBNAME_BT_ST_BMP)
					{
						Director::senceMess.curSen = SENCE_READM;			//	
					}
					else if (one->node->objectName == OBNAME_BT_ST_EXIT)
					{
						Director::senceMess.curSen = SENCE_EXIT;
					}
					
					break;
				}
				one = one->prePtr;
			} while (one != butList.first);
		}
	}
}

