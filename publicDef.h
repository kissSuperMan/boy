#pragma once
#include <iostream>
#include <windows.h>
#include <Windows.h>
#include <string>

using namespace std;

#define SENCE_START    5    //开始场景
#define SENCE_RAND_ONE 6	//关卡一
#define SENCE_OVER	   7		//结束界面
#define SENCE_INTRO	   8		//介绍
#define SENCE_READM	   9		//生成地图

#define SENCE_EXIT	   -1		//退出
#define MESS_SUCC_OVER      1		//成功
#define MESS_FAIL_OVER      0		//失败


#define SCTX_WHITE 7
#define SC_X_PIX 5			//一个单元的X的量
#define SC_Y_PIX 5		
#define SC_FOLL_WIDE  SC_X_PIX*3	//相机跟随的距离
#define SC_FOLL_HIGH  SC_Y_PIX*2


//注意以下定义生成地图那边用的不一样
#define OBNAME_NONAME 0
#define OBNAME_BRWALL 10				//砖体墙				//前面写BR标志的 说明 10 砖  11 门 12奖励
#define OBNAME_BR_DOOR	11			//门
#define OBNAME_BR_AWARD  12			//奖励		//这个是砖后面的隐藏奖励

#define OBNAME_RIWALL 90			//刚体墙
#define OBNAME_ENEMY  50			

#define OBNAME_FIRE	  30			//火焰
#define OBNAME_HERO   40			
#define OBNAME_BOMER  60			//炸弹

#define OBNAME_MARKET   80			//商店

#define OBNAME_FOOD   70				//食物类或者说奖励类
#define OBNAME_FDMONY 71				//	
#define OBNAME_FDKEY  72				//	
#define OBNAME_FDBLOOD  73				//	
#define OBNAME_FDBOM  74				//zadan 	



#define OBNAME_BT_ST_KAI 101
#define OBNAME_BT_ST_BMP 102
#define OBNAME_BT_ST_JIE 103
#define OBNAME_BT_ST_EXIT 104
#define OBNAME_BT_OV_AGAIN 105
#define OBNAME_BT_OV_EXIT 106
#define OBNAME_BT_MK_EXIT   107
#define OBNAME_BT_MK_BOOM   108
#define OBNAME_BT_MK_POWER   109
#define OBNAME_BT_MK_BLOOD   110


#define DIR_KB_NULL 0
#define DIR_UP		1 
#define DIR_DOWN	2 
#define DIR_LEFT	3 
#define DIR_RIGHT	4 
#define DIR_SPACE	5 
#define DIR_ENTER   6
#define DIR_TEST	106 
typedef unsigned char unchar;

//Game map的数据结构
struct SC_Pix
{
	SC_Pix(){}
	SC_Pix(int _s, int _c){ shape = _s; color = _c; }
	int shape = 0;
	int color = SCTX_WHITE;
};
//画笔内的数据
struct PainterInfo
{
	int x;
	int y;
	int fontCol=SCTX_WHITE;
	int useCharIndex = 0;
	string useChar;
};
//物体的基本信息，可以直接用于碰撞检测
struct ObjectInfo		
{
	int yUp = 0;	
	int xLeft = 0;
	int wide = 1;			//这里注意！！  所以这里的wide不要除以2
	int high = 1;
};

using namespace std;








