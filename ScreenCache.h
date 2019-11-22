
/*
页面的架构 ---
元素列表：§№☆★○●◎◇◆□■△▲※→←↑↓〓¤°℃‰�＃＆＠＼︿＿￣―♂♀
■          作为一块 
5*5的方块矩阵 为一个地图单元

地图 显示长度 50块
		 高度 30块
*/
#pragma once
#include "publicDef.h"
#include "MapUnit.h"
#include <map>
#define SC_X_BASE 2				//基础的xy的位置
#define SC_Y_BASE 1

//#define SC_X_PIX 5*2			//一个单元的X的量
//#define SC_Y_PIX 5				
#define MAP_SIZE_HIGH 47
#define MAP_SIZE_WIDE 48
#define SCGA_WIDE		12*SC_X_PIX		//渲染MAP的宽度
#define SCGA_HIGH		7*SC_Y_PIX		//渲染MAP的高度

#define GAMEMAP_WIDE   MAP_SIZE_WIDE*SC_X_PIX		//实际的地图大小
#define GAMEMAP_HIGH   MAP_SIZE_HIGH*SC_Y_PIX

#define SCGAFRAME_WIDE	(SCGA_WIDE*2+4)	//游戏的边框分割
#define SCGAFRAME_HIGH  (SCGA_HIGH+2)




//颜色 列表
#define SCTX_BACK 0
#define SCTX_BLUE 1
#define SCTX_GREEN 2
#define SCTX_DEEPBLUE 3		//深蓝色
#define SCTX_RED 4
#define SCTX_PURPLE 5
#define SCTX_YELLOW 6
//#define SCTX_WHITE 7
#define SCTX_GERY 8
#define SCTX_THINBLUE 9		//浅蓝色
#define SCTX_THINGREEN 10		
#define SCTX_WATERGREEN 11		
#define SCTX_THINRED    12		
#define SCTX_THINPURPLE 13		
#define SCTX_THINYELLOW 14		
#define SCTX_LIGHTWHITE 15		



#define SHAPE_NULL			0
#define SHAPE_LINXIN_FU		1
#define SHAPE_LINXIN_EM		2
#define SHAPE_RECT_FU		3
#define SHAPE_RECT_EM		4
#define SHAPE_TRIAN_FU		5
#define SHAPE_TRIAN_EM		6
#define SHAPE_ROUND_FU		7
#define SHAPE_ROUND_EM		8
#define SHAPE_STAR_FU		9
#define SHAPE_STAR_EM		10
#define SHAPE_BOM			11

/*************************对外的全局函数**********/

class MapUnit;

void sc_paintOnePix(PainterInfo* getInfo);
void sc_UnitToScCache(MapUnit*);
void sc_fileMapToCache();

class ScreenCache
{
public:	
	static int cacheStX;								//内存开始渲染的位置 ，  0 - 
	static int cacheStY;								//
	static SC_Pix gameMap[GAMEMAP_HIGH][GAMEMAP_WIDE];
	ScreenCache();
	~ScreenCache();
	static map<int, string> shapeMap;
	
	//内存的写入与屏幕的写入	
	static void sc_paintOnePix(PainterInfo* getInfo);						//自定义笔刷画一块图形
	static void sc_paintGotoXY(int _x, int _y, int _col=7);					//移动指针位置到固定的位置
	static void sc_fileMapToCache();
	void static sc_writeUnitInCacheMap(MapUnit* giveUnit);					//单元类型导入
	void static sc_writeUnitMix(MapUnit* first, MapUnit *secUnit);			//混合单元人物 与 炸弹
	void static sc_clearUnitInCacheMap(MapUnit* giveUnit);					//单元缓存清除
	void static clearHistoryMap();											//清空历史缓存
	static void sc_showMapCache();											//全体缓存导入
	
};








