#include "Button.h"
//按键
//图片显示作为新的类出现

Button::Button(int _x, int _y, string &stVal)
{
	this->posBase.xLeft = _x;		
	this->posBase.yUp = _y;				
	this->buttonValue = stVal;	
	this->isMe = false;
}


Button::~Button()
{
}
void Button::show()
{
	int color = 7;						//白色
	COORD pos;
	HANDLE getH;
	getH = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = this->posBase.xLeft;
	pos.Y = this->posBase.yUp;
	if (this->isMe == true)
	{
		color = 0x04;						//红色
		SetConsoleTextAttribute(getH, color);
		SetConsoleCursorPosition(getH, pos);
		cout << ">>"<<this->buttonValue;
	}
	else
	{
		color = 0x07;
		SetConsoleTextAttribute(getH, color);
		SetConsoleCursorPosition(getH, pos);
		cout << "  " << this->buttonValue;
	}
}
void Button::clearMe()
{
	int color = 7;						//白色
	COORD pos;
	HANDLE getH;
	getH = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = this->posBase.xLeft;
	pos.Y = this->posBase.yUp;
	SetConsoleTextAttribute(getH, color);
	SetConsoleCursorPosition(getH, pos);
	for (size_t i = 0; i < this->buttonValue.size() ; i++)
	{
		cout << "  ";
	}
}





