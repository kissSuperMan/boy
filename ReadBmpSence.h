#pragma once
#include "Sence.h"
//把BMP的图片读出来并且导出
class ReadBmpSence :
	public Sence
{
public:
	ReadBmpSence();
	virtual ~ReadBmpSence();
	virtual void runThisSence();


};

