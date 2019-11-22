#include "PicUnit.h"



PicUnit::PicUnit(unchar* pic,int _x,int _y ,int _wide, int _high)
{
	this->picArrPoint = pic;
	posBase.wide = _wide;
	posBase.high = _high;
	posBase.xLeft = _x;
	posBase.yUp = _y;			
}

PicUnit::~PicUnit()
{
}

void PicUnit::showPic(int shape,int color)
{
	PainterInfo giveInfo;
	int oneLine = posBase.wide / 8;					//一行里面的 unchar 的数目
	for (int i = 0; i<posBase.high; i++)
	{
		for (int j=0; j < oneLine; j++)
		{
			unchar getOne = this->picArrPoint[i*oneLine+j];
			unchar tempBit=0x00;
			for (int oneBit = 0;oneBit<8;oneBit++)
			{
				tempBit = 0x80 >> oneBit;
				if (getOne & tempBit)
				{
					giveInfo.x = posBase.xLeft+(j * 8 + oneBit) * 2;
					giveInfo.y = posBase.yUp + i;
					giveInfo.useCharIndex = shape;
					giveInfo.fontCol = color;
					ScreenCache::sc_paintOnePix(&giveInfo);
				}
			}
		}
	}
}
#define CHARNUM 4							//字的数量

void PicUnit::startCharInter()
{
	int charNum = 3;
	int charWide = 16;
	unchar* chOverArr[3] = { ch_za, ch_dan, ch_ren};
	vector<PicUnit*> chVect;
	for (int i = 0; i<charNum; i++)
	{
		PicUnit *one = new PicUnit(chOverArr[i], 4 + charWide*i * 2 + 5, 2);		//位置
		chVect.push_back(one);
	}
	for (size_t i = 0; i<chVect.size(); i++)
	{
		chVect[i]->showPic();
	}
	chVect.clear();																	//清空内存
}
void PicUnit::overYXJSCharInter()
{
	int charNum = 4;
	int charWide = 16;
	unchar* chOverArr[4] = { ch_you, ch_xi, ch_jie, ch_su };
	vector<PicUnit*> chVect;
	for (int i = 0; i<charNum; i++)
	{
		PicUnit *one = new PicUnit(chOverArr[i], 10 + charWide*i * 2, 2);		//位置  //42 20
		chVect.push_back(one);
	}
	for (size_t i = 0; i<chVect.size(); i++)
	{
		chVect[i]->showPic();
	}
	chVect.clear();				//清空内存
}
void PicUnit::overGXTGCharInter()
{
	int charNum = 4;
	int charWide = 16;
	unchar* chOverArr[4] = { ch_gong, ch_xi2, ch_tong, ch_guan };
	vector<PicUnit*> chVect;
	for (int i = 0; i<charNum; i++)
	{
		PicUnit *one = new PicUnit(chOverArr[i], 10 + charWide*i * 2, 2);		//位置
		chVect.push_back(one);
	}
	for (size_t i = 0; i<chVect.size(); i++)
	{
		chVect[i]->showPic();
	}
	chVect.clear();				//清空内存

}


