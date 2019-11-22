#pragma once
#include "MapUnit.h"
class Monster :
	public MapUnit
{
public:
	static int monsterNum;
	int rememDir;									    //对象本身记录方向
	int tryMove = 0;									//一个方向失败的话会调转变成左右或者上下

	Monster(int _x,int _y);
	virtual ~Monster();
	virtual  int collisionTriger();
	virtual int move(int getDir);
	virtual int destoryMe();
	virtual void trigerTime();
};

