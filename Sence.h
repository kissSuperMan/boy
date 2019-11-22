#pragma once
#include "ScreenCache.h"
#include "Button.h"
class Sence
{
public:
	virtual void runThisSence()=0;
	virtual void overThisSence();						//本场景结束，可以不实例化
	Sence();
	virtual ~Sence();
};

