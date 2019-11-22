#include "TipBoard.h"
#include "Bomber.h"
#include "HeroPlayer.h"

#define TIP_INT_Y	18				

#define TIP_STP_X	(SCGA_WIDE)*2+6		//开始写属性的位置 要乘以2
#define TIP_STP_Y	3	
#define TIP_P_STEP  2				//分隔符
TipBoard::TipBoard()
{
}

//property 属性
//bullet 子弹
//dialogue 对话
TipBoard::~TipBoard()
{
}
//HeroPlayer::blood, Bomber::bomberNum, Bomber::boomPower, 1
void TipBoard::showPro()
{
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y);
	cout << "血量:" <<  HeroPlayer::blood << "  ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y + TIP_P_STEP);
	cout << "炸弹剩余:" << HeroPlayer::boomberMax << "  ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y + TIP_P_STEP*2);
	cout << "威力:" << Bomber::boomPower << "  ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y + TIP_P_STEP*3);
	cout << "击杀:" << HeroPlayer::killNum << "  ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y + TIP_P_STEP * 4);
	cout << "金币:" << HeroPlayer::monney << "  ";
	
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_INT_Y);
	
	cout << "游戏目标： ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_INT_Y);
	cout << "找到钥匙开门，逃出房间 ";
	//ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_INT_Y+TIP_P_STEP * 2);
	//cout << "找到钥匙开门，逃出房间 ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_INT_Y+TIP_P_STEP * 2);
	cout << "好好利用计划手上的金币";
}

