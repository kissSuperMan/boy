#include "IntroSence.h"
#include "publicDef.h"
#include "Director.h"
IntroSence::IntroSence()
{
}


IntroSence::~IntroSence()
{
}
void IntroSence::runThisSence()
{
	int color = 0x07;						//白色
	COORD pos;
	HANDLE getH;
	getH = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 10;
	pos.Y = 20;			
	SetConsoleTextAttribute(getH, color);
	SetConsoleCursorPosition(getH, pos);
		
	int dirThis = DIR_KB_NULL;
	system("cls");
	ScreenCache::sc_paintGotoXY(42,20);
	cout << "   小键盘是上下键或者wasd为移动键" << endl;
	ScreenCache::sc_paintGotoXY(42, 22);
	cout << "   回车或者空格放置炸弹" << endl << endl;
	ScreenCache::sc_paintGotoXY(42, 28,4);
	cout << "   本页面按空格或者回车退出" << endl;
	
	while (Director::senceMess.curSen == SENCE_INTRO)
	{
		dirThis = Director::dir_getKeyboard();
		if (dirThis == DIR_SPACE)
		{
			Director::senceMess.curSen = SENCE_START;
		}
	}
}

