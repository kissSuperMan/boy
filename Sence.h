#pragma once
#include "ScreenCache.h"
#include "Button.h"
class Sence
{
public:
	virtual void runThisSence()=0;
	virtual void overThisSence();						//���������������Բ�ʵ����
	Sence();
	virtual ~Sence();
};

