#pragma once
#include "ObjectBase.h"
#include "publicDef.h"
#include <string>
class Button :
	public ObjectBase
{
public:
	bool isMe = false;								//是否我被选中？
	string buttonValue="按键键值";
	
	Button(int x,int y,string &stVal);
	virtual ~Button();
	void show();
	void clearMe();									//清除屏幕上的数据
};

