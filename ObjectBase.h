#pragma once
#include "publicDef.h"
class ObjectBase
{
public:
	int objectName = OBNAME_NONAME;					//物体的名字
	ObjectInfo posBase;
	ObjectBase();
	virtual ~ObjectBase();
	
};




