//ը���ٵ�ǽ ��
#pragma once
#include "MapUnit.h"
class RigidWall :
	public MapUnit
{
public:
	RigidWall(int _x, int _y);
	virtual ~RigidWall();
	int virtual collisionTriger();
};

