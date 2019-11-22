#include "Director.h"
#include <conio.h>
#include "GameSence.h"
#include "OverSence.h"
#include "StartSence.h"
#include "IntroSence.h"
#include "ReadBmpSence.h"

ScoreBoard Director::scoreFinnal = {};
SenceMassage Director::senceMess = {SENCE_START,0};										//使用结构体代替
void Director::scoreClear()
{
	scoreFinnal.boomTotal = 0;
	scoreFinnal.killEnemy = 0;
	scoreFinnal.getAward = 0;
	scoreFinnal.killBrick = 0;
	scoreFinnal.scoreVal = 0;
}




void Director::readyCmd()
{
	system("mode con cols=150 lines=48");
	system("color 07");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

}

//Director::
int Director::dir_getKeyboard()
{
	if (_kbhit())
	{
		int getBoard = 0;
		getBoard = _getch();
		if (getBoard == 'w' || getBoard == 'W' || getBoard==72)				//上
		{
			return DIR_UP;
		}
		else if (getBoard == 's' || getBoard == 'S' || getBoard == 80)		//下
		{
			return DIR_DOWN;
		}
		else if (getBoard == 'a' || getBoard == 'A' || getBoard == 75)		//左
		{
			return DIR_LEFT;
		}
		else if (getBoard == 'd' || getBoard == 'D' || getBoard == 77)		//右
		{
			return DIR_RIGHT;
		}
		else if (getBoard == ' ' ||getBoard == '\r')						//空格和回车
		{
			return DIR_SPACE;
		}
		else if (getBoard == 'p')
		{
			return DIR_TEST;
		}
	}
	return DIR_KB_NULL;		//无按键
}


Director::Director()
{
}


Director::~Director()
{
}
void Director::loadDirSence()
{
	
	 
}
void Director::debugRulerDraw()
{
	HANDLE getH;
	getH = GetStdHandle(STD_OUTPUT_HANDLE);
	ScreenCache::sc_paintGotoXY(0, 0);
	cout << "  ";
	for (int i = 0; i < 56; i++)
	{
		if (i < 10)
		{
			cout << " ";
		}
		if (i % 2)	{ SetConsoleTextAttribute(getH, 4); }
		else{ SetConsoleTextAttribute(getH, 7); }
		cout << i;
	}
	cout << endl;
	for (int i = 0; i < 35; i++)
	{
		cout << i;
		cout << endl;
	}
}
void Director::runSence()
{
	ScreenCache oneTemp;						//临时对消，用于调用Screen的初始化
	Sence *ovSen = new OverSence();
	Sence *gaSen = new GameSence();
	Sence *stSen = new StartSence();
	Sence *inSen = new IntroSence();
	Sence *bmSen = new ReadBmpSence();
	Sence *curSen = nullptr;
	while (true)
	{
		if (Director::senceMess.curSen == SENCE_START)
		{
			curSen = stSen;
		}
		else if (Director::senceMess.curSen == SENCE_RAND_ONE)
		{
			curSen = gaSen;
		}
		else if (Director::senceMess.curSen == SENCE_OVER)
		{
			curSen = ovSen;
		}
		else if (Director::senceMess.curSen == SENCE_INTRO)
		{
			curSen = inSen;
		}
		else if (Director::senceMess.curSen == SENCE_READM)
		{
			curSen = bmSen;
		}
		else if (Director::senceMess.curSen == SENCE_EXIT)
		{
			break;													//退出游戏
		}
		else
		{
			cout << "场景切换，出错了..." << endl;
			curSen = stSen;
			system("pause");
		}
		curSen->runThisSence();
		curSen->overThisSence();
	}
}






