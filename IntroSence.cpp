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
	int color = 0x07;						//��ɫ
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
	cout << "   С���������¼�����wasdΪ�ƶ���" << endl;
	ScreenCache::sc_paintGotoXY(42, 22);
	cout << "   �س����߿ո����ը��" << endl << endl;
	ScreenCache::sc_paintGotoXY(42, 28,4);
	cout << "   ��ҳ�水�ո���߻س��˳�" << endl;
	
	while (Director::senceMess.curSen == SENCE_INTRO)
	{
		dirThis = Director::dir_getKeyboard();
		if (dirThis == DIR_SPACE)
		{
			Director::senceMess.curSen = SENCE_START;
		}
	}
}

