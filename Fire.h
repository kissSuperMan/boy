#pragma once
#include "MapUnit.h"
#define BOM_FRAMETIME 5
class Fire :
	public MapUnit
{
public:
	static int timeUp;
	int existTime = 0;
	int move(int getDir);
	Fire(int x,int y);
	virtual ~Fire();
	virtual int destoryMe();
};

