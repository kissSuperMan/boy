#include "Bomber.h"
#include "Fire.h"
int Bomber::timeUp = 3*BOM_FRAMETIME;		//5s
int Bomber::bomberNum = 0;
int Bomber::boomPower = 1;					//爆炸的威力
Bomber::Bomber(int _x,int _y)
{
	this->objectName = OBNAME_BOMER;
	this->posBase.xLeft = _x;
	this->posBase.yUp = _y;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	this->movePicArr[0] = bomberState;
	this->curPic = 0;
	this->picLoadInUnit(this);			//不打印这个炸弹，缓存在 他在player里面导入
}



Bomber::~Bomber()
{
}

void Bomber::writeInCache()					//炸弹的渲染
{
	int oneX = 0;
	int oneY = 0;
	int startY = this->posBase.yUp;
	int startX = this->posBase.xLeft;
	int wide = this->posBase.wide;
	int high = this->posBase.high;
	for (oneY = 0; oneY < wide; oneY++)
	{
		for (oneX = 0; oneX<high; oneX++)
		{
			if(uinitMap[oneY][oneX].shape!=SHAPE_NULL)				//图片不为空
			{
				ScreenCache::gameMap[startY + oneY][startX + oneX] = this->uinitMap[oneY][oneX];
			}
			
		}
	}
}

//计时间，出发炸弹爆炸
int Bomber::move(int dir)
{
	//static int timeShow = 0;
	this->bomClock++;

	if (bomClock <= Bomber::timeUp)																
	{
		if (this->bomClock % 3 == 0)
		{
			showTime++;
			//this->uinitMap[2][2].shape = showTime % 10 + 100;
		}
		return 0;											//时间未到不处理
	}
	//时间到了爆炸了
	if (Bomber::bomberNum)
	{
		Bomber::bomberNum--;
		this->destoryMe();
	}
	else{ 
		cout << "报错，文件 Bomber" << endl;
	}
	return 1;																			//返回 1  告知消灭				
}




//该方向是否放置火焰
bool canIputTheFire(int getX, int getY, int* getDir)
{
	int triger = 0;
	if (getX < 0 || getY < 0)
	{
		*getDir = 0;																	//该方向不能放置火焰了
		return false;
	}
	else if (getX> GAMEMAP_WIDE - SC_X_PIX || getY>GAMEMAP_HIGH - SC_Y_PIX)
	{
		*getDir = 0;																	
		return false;
	}
	MapUnit tempFire = Fire(getX, getY);												//栈变量
	MyNode* preNode = nullptr;
	for (MyNode* one = MapUnit::peopleCoList->firstNode->nextPtr; one != MapUnit::peopleCoList->LastNode; one = one->nextPtr)
	{
		preNode = one->prePtr;
		if (MapUnit::collisionCheck(&tempFire, one->node))
		{
			if (one->node->destoryMe() == 1){}																		//这里注意，返回1 的情况是没有真的毁灭他，所以one向后走
			else{ one = preNode; }
			triger = 1;																//火焰触发
		}
	}
	if (triger)																			//这样有人物挡在他后面会触发火焰但是不会消灭刚墙
	{
		return true;
	}
	preNode = nullptr;
	for (MyNode* one = MapUnit::buildCoList->firstNode->nextPtr; one != MapUnit::buildCoList->LastNode; one = one->nextPtr)
	{
		preNode = one->prePtr;
		if (MapUnit::collisionCheck(&tempFire, one->node))
		{
			if (one->node->objectName == OBNAME_RIWALL || one->node->objectName == OBNAME_BR_AWARD){
				*getDir = 0;
				return false;								
			}												//刚体墙不消灭
			else{																		
				if (one->node->destoryMe() == 1){}																		//这里注意，返回1 的情况是没有真的毁灭他，所以one向后走
				else{ one = preNode; }									//被消灭的时候注意
			}
		}
	}
	return true;
	

}
																					//返回 true 表示可以显示

//获取四周的方向，没有边界判定 0123 上下左右
void bom_getXandY(int *getX,int* getY,int getDir,int power)
{
	power += 1;
	if (getDir == 0)
	{
		*getY += SC_Y_PIX*power;
	}
	else if (getDir == 1)
	{
		*getY -= SC_Y_PIX*power;
	}
	else if (getDir == 2)			//左边
	{
		*getX -= SC_X_PIX*power;
	}
	else if (getDir == 3)			//右边
	{
		*getX += SC_X_PIX*power;
	}
}
//炸弹毁灭自己，并且在四周建立火焰
int Bomber::destoryMe()
{
	Director::scoreFinnal.boomTotal++;
	int rememRound[4] = { 1,1,1,1 };													//记录该方向是否还能防止火焰
	
	this->mapUnit_erase(this);
	
	MapUnit::peopleCoList->deleteNode(this);
	
	canIputTheFire(this->posBase.xLeft, this->posBase.yUp, &rememRound[0]);				//rememRound[0]随便传的
	Fire *one = new Fire(this->posBase.xLeft, this->posBase.yUp);						//自己的位置要有 火焰
	MapUnit::peopleCoList->add(one);													

	for (int onePower = 0; onePower < Bomber::boomPower; onePower++)
	{
		for (int oneRound = 0; oneRound < 4; oneRound++)
		{
			int fireX = this->posBase.xLeft;
			int fireY = this->posBase.yUp;
			bom_getXandY(&fireX, &fireY, oneRound, onePower);
			if (rememRound[oneRound])
			{
				if (canIputTheFire(fireX, fireY, &rememRound[oneRound]))
				{
					Fire *one = new Fire(fireX, fireY);
					MapUnit::peopleCoList->add(one);
				}
			}
		}
	}	
	delete this;												//
	return 0;
}



