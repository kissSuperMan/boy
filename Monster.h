#pragma once
#include "MapUnit.h"
class Monster :
	public MapUnit
{
public:
	static int monsterNum;
	int rememDir;									    //�������¼����
	int tryMove = 0;									//һ������ʧ�ܵĻ����ת������һ�������

	Monster(int _x,int _y);
	virtual ~Monster();
	virtual  int collisionTriger();
	virtual int move(int getDir);
	virtual int destoryMe();
	virtual void trigerTime();
};

