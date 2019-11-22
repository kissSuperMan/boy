#include "OverSence.h"
#include "conio.h"
#include "PicUnit.h"
#include "animationLib.h"
#include "Director.h"
#include "MyDouList.h"
#include "Bomber.h"
OverSence::OverSence() 
{

}


OverSence::~OverSence() 
{

}

//游戏屏幕的大小定位在   50*30的显示位置
void OverSence::runThisSence()
{
	system("cls");
	if (Director::senceMess.OverMess == MESS_FAIL_OVER)
	{
		PicUnit::overYXJSCharInter();
	}
	else
	{
		PicUnit::overGXTGCharInter();
	}
	string c_again = "重新开始";
	string c_tuiChu = "退出游戏";
	Button *butAgain = new Button(42, 25, c_again);
	Button *butExit = new Button(42, 28, c_tuiChu);
	butAgain->objectName = OBNAME_BT_OV_AGAIN;
	butExit->objectName = OBNAME_BT_OV_EXIT;
	
	butAgain->isMe = true;
	MyDouList<Button*> butList;
	butList.add(butAgain);
	butList.add(butExit);

	int dirThis = DIR_KB_NULL;
	MyDouNode<Button*> *one = new MyDouNode<Button*>(nullptr);
	Director::scoreFinnal.scoreVal = Director::scoreFinnal.getAward * 10 + Director::scoreFinnal.killEnemy * 7 + 
								Director::scoreFinnal.killBrick - Director::scoreFinnal.boomTotal;//最终分数
	if (Director::scoreFinnal.scoreVal < 0)
	{
		Director::scoreFinnal.scoreVal = 0;
	}

	butAgain->show();
	butExit->show();
	ScreenCache::sc_paintGotoXY(40,30,0x4);
	cout <<"你的最终得分:" << Director::scoreFinnal.scoreVal << endl;
	
	while (Director::senceMess.curSen == SENCE_OVER)
	{
		dirThis = Director::dir_getKeyboard();
		if (dirThis == DIR_DOWN || dirThis == DIR_RIGHT)
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
					if (one->node->objectName == OBNAME_BT_OV_AGAIN)
					{
						Bomber::boomPower = 1;

						Director::senceMess.curSen = SENCE_RAND_ONE;
					}
					else if (one->node->objectName == OBNAME_BT_OV_EXIT)
					{
						Director::senceMess.curSen = SENCE_EXIT;
					}
					break;
				}
				one = one->prePtr;
			} while (one != butList.first);
		}
	}
	Director::scoreClear();
}





