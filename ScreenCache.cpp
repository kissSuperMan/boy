#include "ScreenCache.h"
#include <string>
#include <map>
#include "ReadFile.h"
#include "BrickWall.h"
#include "RigidWall.h"
#include "Monster.h"
#include "Award.h"
#include "Market.h"
#include "BuffFood.h"
#include "OutDoor.h"
#define SHAPE_ZERO 0
#define SHAPE_BOARD 1
#define SHAPE_BRICK 2
#define SHAPE_RIGID 3
#define SHAPE_FIRE  4
//SC_Pix some = {0,0};
//元素列表：§№☆★○●◎◇◆□■△▲※→←↑↓〓¤°℃‰�＃＆＠＼︿＿￣―♂♀
SC_Pix ScreenCache::gameMap[GAMEMAP_HIGH][GAMEMAP_WIDE];		//10*5  *15*10 
int ScreenCache::cacheStX=0;									//内存开始渲染的位置 ，  0 - 
int ScreenCache::cacheStY=0;
static SC_Pix historyMap[GAMEMAP_HIGH][GAMEMAP_WIDE] = {};		//历史缓存文件


//"□",2
map<int, string> ScreenCache::shapeMap;

string sc_charFind(int giveShape);

void ScreenCache::clearHistoryMap()
{
	for (int i = 0; i < GAMEMAP_HIGH;i++)
	{
		for (int j = 0; j < GAMEMAP_WIDE;j++)
		{
			historyMap[i][j].color = 0;
			historyMap[i][j].shape = SHAPE_NULL;
			ScreenCache::gameMap[i][j].color = 0;
			ScreenCache::gameMap[i][j].shape = SHAPE_NULL;
		}
	}
	ScreenCache::cacheStX = 0;
	ScreenCache::cacheStY = 0;													//结束后定位屏幕位置
}
/*************************对外的全局函数**********/
void ScreenCache::sc_paintOnePix(PainterInfo* getInfo)
{
	COORD pos;
	HANDLE getH;
	getH = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = (short)getInfo->x;
	pos.Y = (short)getInfo->y;
	getInfo->useChar = sc_charFind(getInfo->useCharIndex);
	SetConsoleTextAttribute(getH,getInfo->fontCol);
	SetConsoleCursorPosition(getH, pos);
	cout << getInfo->useChar;
	//cout << "□";
}
void ScreenCache::sc_paintGotoXY(int _x,int _y,int _col)
{
	COORD pos;
	HANDLE getH;
	getH = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = _x;
	pos.Y = _y;
	SetConsoleTextAttribute(getH, _col);
	SetConsoleCursorPosition(getH, pos);				
}
//10-21  暂时用的一个缓存，后期建立一个历史缓存
//10-24  建立历史缓存
//10-25  设置相机跟随
void ScreenCache::sc_showMapCache()
{

	PainterInfo giveInfo;
	if (cacheStX > GAMEMAP_WIDE - SCGA_WIDE){ cacheStX = GAMEMAP_WIDE - SCGA_WIDE; }
	else if (cacheStX < 0){ cacheStX = 0; }
	if (cacheStY>GAMEMAP_HIGH - SCGA_HIGH){ cacheStY = GAMEMAP_HIGH - SCGA_HIGH; }
	else if (cacheStY < 0){ cacheStY = 0; }
	
	int mapOneY = 0;
	int mapOneX = 0;
	int hisOneX = 0;
	int hisOneY = 0;
	for (mapOneY = 0, hisOneY = 0; mapOneY < SCGA_HIGH; mapOneY++, hisOneY++)
	{
		for (mapOneX = 0, hisOneX = 0; mapOneX < SCGA_WIDE; mapOneX += 1,hisOneX++)
		{
			if (historyMap[hisOneY][hisOneX].shape != ScreenCache::gameMap[mapOneY + cacheStY][mapOneX + cacheStX].shape ||
				historyMap[hisOneY][hisOneX].color != ScreenCache::gameMap[mapOneY + cacheStY][mapOneX + cacheStX].color)
			{
				historyMap[hisOneY][hisOneX] = ScreenCache::gameMap[mapOneY + cacheStY][mapOneX + cacheStX];
				
				giveInfo.x = hisOneX * 2 + SC_X_BASE + 2;// +cacheStX * 2;								//+2是避开Frame的边界
				giveInfo.y = hisOneY + SC_Y_BASE + 1;// +cacheStY;
				giveInfo.useCharIndex = historyMap[hisOneY][hisOneX].shape;
				giveInfo.fontCol = historyMap[hisOneY][hisOneX].color;
				sc_paintOnePix(&giveInfo);
			}
		} 
	}
}
//地图解析与创建
void ScreenCache::sc_fileMapToCache()
{
	int scX = 0;
	int scY = 0;
	int mapX = 0;
	int mapY = 0;
	for (mapY = 0; mapY < MAP_SIZE_HIGH; mapY++)
	{
		for (mapX = 0; mapX < MAP_SIZE_WIDE; mapX++)
		{
			scY = mapY * 5;
			scX = mapX * 5;
			if (ReadFile::fileMap[mapY][mapX]/10 == OBNAME_BRWALL/10)
			{
				if (ReadFile::fileMap[mapY][mapX]  == OBNAME_BR_AWARD)			//墙体的内置奖励
				{
					Award *one = new Award(scX, scY);
					MapUnit::buildCoList->add(one);
				}
				else if (ReadFile::fileMap[mapY][mapX]  == OBNAME_BR_DOOR )
				{
					OutDoor *one = new OutDoor(scX, scY);
					MapUnit::buildCoList->add(one);
				}
				else
				{
					BrickWall *one = new BrickWall(scX, scY);
					MapUnit::buildCoList->add(one);							//放入建筑碰撞表
				}
			}
			else if (ReadFile::fileMap[mapY][mapX]/10 == OBNAME_RIWALL/10)
			{
				RigidWall *one = new RigidWall(scX, scY);
				MapUnit::buildCoList->add(one);	
			}
			else if (ReadFile::fileMap[mapY][mapX]/10 == OBNAME_ENEMY/10)
			{
				Monster *one = new Monster(scX, scY);
				MapUnit::peopleCoList->add(one);							
			}
			else if (ReadFile::fileMap[mapY][mapX] / 10 == OBNAME_FOOD/10)
			{
				if (ReadFile::fileMap[mapY][mapX] % 10 != 0)
				{
					BuffFood *one = new BuffFood(scX, scY, ReadFile::fileMap[mapY][mapX]);
					MapUnit::buildCoList->add(one);
				}
				else
				{
					Award *one = new Award(scX, scY);								//奖励
					MapUnit::buildCoList->add(one);
				}
			}
			else if (ReadFile::fileMap[mapY][mapX] / 10 == OBNAME_MARKET/10)
			{
				Market *one = new Market(scX, scY);									//商店
				MapUnit::buildCoList->add(one);
			}
		}
	}
}

//单体写入
void ScreenCache::sc_writeUnitInCacheMap(MapUnit* giveUnit)
{
	int oneX = 0;
	int oneY = 0;
	int startY = giveUnit->posBase.yUp;
	int startX = giveUnit->posBase.xLeft;
	int wide = giveUnit->posBase.wide;
	int high = giveUnit->posBase.high;
	for (oneY = 0; oneY < wide; oneY++)
	{
		for (oneX = 0; oneX<high; oneX++)
		{
			ScreenCache::gameMap[startY + oneY][startX + oneX] = giveUnit->uinitMap[oneY][oneX];
		}
	}
}

bool is_inPixPos(int x,int y)
{
	if (x<0 || x>=SC_X_PIX)
	{
		return false;
	}
	if (y<0 || y>=SC_Y_PIX)
	{
		return false;
	}
	return true;
}
//同时写入，
//无论怎么调用 人物cover在炸弹后面  
//对于不移动的物体采用，
void ScreenCache::sc_writeUnitMix(MapUnit* first,MapUnit *secUnit)		//
{
	MapUnit* upUnit = first;
	MapUnit* downUnit = secUnit;
	
	SC_Pix  tempMap[SC_Y_PIX][SC_X_PIX];				//地图单位的缓存

	//tempMap  - 复制下层图片
	for (int tUnitY = 0; tUnitY < SC_Y_PIX; tUnitY++)
	{
		for (int tUnitX = 0; tUnitX < SC_X_PIX; tUnitX++)
		{
			tempMap[tUnitY][tUnitX] = upUnit->uinitMap[tUnitY][tUnitX];
		}
	}
	//上层 不涂抹 的覆盖
	for (int tUnitY = 0; tUnitY < SC_Y_PIX; tUnitY++)
	{
		for (int tUnitX = 0; tUnitX < SC_X_PIX; tUnitX++)
		{
			int posX = upUnit->posBase.xLeft + tUnitX;		//屏幕上的位置
			int posY = upUnit->posBase.yUp + tUnitY;
			int upUiy = posY - downUnit->posBase.yUp;				//上层图片相对 的位置
			int upUix = posX - downUnit->posBase.xLeft;
			if (is_inPixPos(upUix,upUiy))						//在范围内就写入。
			{
				if (upUnit->uinitMap[tUnitY][tUnitX].shape == 0){ tempMap[tUnitY][tUnitX] = downUnit->uinitMap[upUiy][upUix]; }
				else {}
			}
		}
	}
	int oneX = 0;
	int oneY = 0;
	int startY = upUnit->posBase.yUp;
	int startX = upUnit->posBase.xLeft;
	int wide = upUnit->posBase.wide;
	int high = upUnit->posBase.high;

	for (oneY = 0; oneY < high ; oneY++)
	{
		for (oneX = 0; oneX < wide; oneX++)
		{
			ScreenCache::gameMap[startY + oneY][startX + oneX] = tempMap[oneY][oneX];
		}
	}
	
}
void ScreenCache::sc_clearUnitInCacheMap(MapUnit* giveUnit)
{
	int oneX = 0;
	int oneY = 0;
	int startY = giveUnit->posBase.yUp;
	int startX = giveUnit->posBase.xLeft;
	int wide = giveUnit->posBase.wide;
	int high = giveUnit->posBase.high;
	SC_Pix zero = { 0, 7 };
	for (oneY = 0; oneY < wide; oneY++)
	{
		for (oneX = 0; oneX<high; oneX++)
		{
			ScreenCache::gameMap[startY + oneY][startX + oneX] = zero;
		}
	}
}
/*********************类成员函数*****************/
//☆★○●◎◇◆□■△▲
//§№☆★○●◎◇◆□■△▲※→←↑↓〓¤°℃‰�＃＆＠＼︿＿￣―♂♀   〈  〉
ScreenCache::ScreenCache()
{
	shapeMap[0] = "  ";
	shapeMap[1] = "◆";
	shapeMap[2] = "◇";
	shapeMap[3] = "■";
	shapeMap[4] = "□";
	shapeMap[5] = "▲";
	shapeMap[6] = "△";
	shapeMap[7] = "●";
	shapeMap[8] = "○";
	shapeMap[9] = "★";
	shapeMap[10] = "☆";
	shapeMap[11] = "¤";
	shapeMap[12] = "◎";

	shapeMap[31] = "VV";
	shapeMap[32] = "—";
	shapeMap[33] = "口";
	shapeMap[34] = "囧";
	shapeMap[35] = "〉";
	shapeMap[36] = "〈";
	shapeMap[37] = "―";
	shapeMap[38] = "―";
//	shapeMap[36] = "";
	
	shapeMap[100] = "零";
	shapeMap[101] = "一";
	shapeMap[102] = "二";
	shapeMap[103] = "三";
	shapeMap[104] = "四";
	shapeMap[105] = "五";
	shapeMap[106] = "六";
	shapeMap[107] = "七";
	shapeMap[108] = "八";
	shapeMap[109] = "九";
	shapeMap[110] = "十";
	shapeMap[120] = "商";
	shapeMap[121] = "店";
	shapeMap[122] = "出";
	shapeMap[123] = "口";
	shapeMap[124] = "￥";
	shapeMap[125] = "穷";
}


ScreenCache::~ScreenCache()
{
	memset(ScreenCache::gameMap, 0, sizeof(ScreenCache::gameMap));										//重置地图
}
string sc_charFind(int giveShape)
{
	return ScreenCache::shapeMap[giveShape];
}





