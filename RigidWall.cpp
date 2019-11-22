#include "RigidWall.h"


RigidWall::RigidWall(int _x,int _y)
{
	this->objectName = OBNAME_RIWALL;
	this->posBase.xLeft = _x;
	this->posBase.yUp = _y;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			this->uinitMap[i][j].shape = SHAPE_RECT_FU;
			this->uinitMap[i][j].color = SCTX_WHITE;
		}
	}
}


RigidWall::~RigidWall()
{
}
int RigidWall::collisionTriger()
{
	
	return 0;
}

