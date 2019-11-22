#include "Market.h"
#include "MyDouList.h"
#include "HeroPlayer.h"
#include "TimeCon.h"
#include "TipBoard.h"
#include "Bomber.h"
#define DIA_ST_X 5
#define DIA_ST_Y SCGA_HIGH+4				//显示对话的位置

#define BLOOD_PRI  6
#define BOOM_PRI  1
#define POWER_PRI 10

Market::Market(int _x,int _y)
{
	this->objectName = OBNAME_MARKET;
	this->posBase.xLeft = _x;
	this->posBase.yUp = _y;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	this->movePicArr[0] = marketState;
	this->curPic = 0;
	this->picLoadInUnit(this);
}


Market::~Market()
{
	
}

int Market::destoryMe()
{
	return 1;				//不可销毁
}


int Market::collisionTriger()
{
	string c_maism = "你想买什么？";
	string c_buxuyao = "走出商店";
	string c_jiaxue = "加血（6金币）";
	string c_weili = "加炸弹威力（10金币）";
	string c_zadan = "购买炸弹数量（1金币）";
	
	Button maismLa(5, DIA_ST_Y, c_maism);
	Button buxuyaoBt(5, DIA_ST_Y + 2, c_buxuyao);
	Button jiaxueBt(5, DIA_ST_Y + 3, c_jiaxue);
	Button weiliBt(5, DIA_ST_Y + 4, c_weili);
	Button zadanBt(5, DIA_ST_Y + 5, c_zadan);
	bool thisOutFlag = false;
	buxuyaoBt.objectName = OBNAME_BT_MK_EXIT;
	jiaxueBt.objectName = OBNAME_BT_MK_BLOOD;
	weiliBt.objectName = OBNAME_BT_MK_POWER;
	zadanBt.objectName = OBNAME_BT_MK_BOOM;
	buxuyaoBt.isMe = true;
	MyDouList<Button*> butList;
	butList.add(&buxuyaoBt);
	butList.add(&jiaxueBt);
	butList.add(&weiliBt);
	butList.add(&zadanBt);

	maismLa.show();
	buxuyaoBt.show();
	jiaxueBt.show();
	weiliBt.show();
	zadanBt.show();
	int dirThis = DIR_KB_NULL;

	ScreenCache::sc_paintGotoXY(DIA_ST_X, DIA_ST_Y);
	
	MyDouNode<Button*> *one = new MyDouNode<Button*>(nullptr);
	
	while (thisOutFlag == false)
	{
		if (TimeCon::isTimeControlTriger(TIME_TIP_RAD))
		{
			TipBoard::showPro();														//积分版
		}
		dirThis = Director::dir_getKeyboard();
		if (dirThis == DIR_DOWN || dirThis == DIR_RIGHT)
		{
			one = butList.first;
			do
			{
				if (one->node->isMe == true)
				{
					one->nextPtr->node->isMe = true;
					one->node->isMe = false;
					one->node->show();
					one->nextPtr->node->show();
					break;
				}
				one = one->nextPtr;
			} while (one != butList.first);
		}
		else if (dirThis == DIR_UP || dirThis == DIR_LEFT)
		{
			one = butList.first;
			do
			{
				if (one->node->isMe == true)
				{
					one->prePtr->node->isMe = true;
					one->node->isMe = false;
					one->node->show();
					one->prePtr->node->show();
					break;
				}
				one = one->prePtr;
			} while (one != butList.first);
		}
		else if (dirThis == DIR_SPACE)
		{
			one = butList.first;
			do
			{
				if (one->node->isMe == true)
				{
					if (one->node->objectName == OBNAME_BT_MK_EXIT)
					{
						thisOutFlag = true;
					}
					else if (one->node->objectName == OBNAME_BT_MK_BLOOD)
					{
						if (HeroPlayer::monney >= BLOOD_PRI)
						{
							HeroPlayer::monney -= BLOOD_PRI;
							HeroPlayer::blood++;					
						}
						else
						{

						}
					}
					else if (one->node->objectName == OBNAME_BT_MK_BOOM)
					{
						if (HeroPlayer::monney >= BOOM_PRI)
						{
							HeroPlayer::monney -= BOOM_PRI;
							HeroPlayer::boomberMax += 5;
						}
					}
					else if (one->node->objectName == OBNAME_BT_MK_POWER)
					{
						//if ()
						if (HeroPlayer::monney >= POWER_PRI)
						{
							HeroPlayer::monney -= POWER_PRI;
							Bomber::boomPower++;
						}
					}
					break;
				}
				one = one->prePtr;
			} while (one != butList.first);
		}
	}
	//清除
	one = butList.first;
	do
	{
	
		one->node->clearMe();
		one = one->nextPtr;
	} while (one != butList.first);
	maismLa.clearMe();
		
	

	return 0;
}




