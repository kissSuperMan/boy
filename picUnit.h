#pragma once
#include "publicDef.h"
#include "ScreenCache.h"
class PicUnit:
	public ObjectBase
{
public:
	unchar* picArrPoint;
	//int wide=0;
	//int high=0;
	static void startCharInter();
	static void overYXJSCharInter();
	static void overGXTGCharInter();
	void showPic(int shape = SHAPE_RECT_FU, int color=SCTX_WHITE);
	PicUnit(unchar* pic, int _x, int _y,int _wide = 16, int _high = 18);
	virtual ~PicUnit();
};

