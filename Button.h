#pragma once
#include "ObjectBase.h"
#include "publicDef.h"
#include <string>
class Button :
	public ObjectBase
{
public:
	bool isMe = false;								//�Ƿ��ұ�ѡ�У�
	string buttonValue="������ֵ";
	
	Button(int x,int y,string &stVal);
	virtual ~Button();
	void show();
	void clearMe();									//�����Ļ�ϵ�����
};

