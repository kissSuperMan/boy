#pragma once
#include "MapUnit.h"
class Award :
	public MapUnit
{
public:
	//int recode = 1;										//��¼��ǰ״̬ Ϊ1ʱ���������� Brickname
	Award(int x, int y);
	virtual ~Award();

	virtual int destoryMe();
};

