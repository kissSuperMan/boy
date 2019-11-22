#include "Bomber.h"
#include "Fire.h"
int Bomber::timeUp = 3*BOM_FRAMETIME;		//5s
int Bomber::bomberNum = 0;
int Bomber::boomPower = 1;					//��ը������
Bomber::Bomber(int _x,int _y)
{
	this->objectName = OBNAME_BOMER;
	this->posBase.xLeft = _x;
	this->posBase.yUp = _y;
	this->posBase.wide = 5;
	this->posBase.high = 5;
	this->movePicArr[0] = bomberState;
	this->curPic = 0;
	this->picLoadInUnit(this);			//����ӡ���ը���������� ����player���浼��
}



Bomber::~Bomber()
{
}

void Bomber::writeInCache()					//ը������Ⱦ
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
			if(uinitMap[oneY][oneX].shape!=SHAPE_NULL)				//ͼƬ��Ϊ��
			{
				ScreenCache::gameMap[startY + oneY][startX + oneX] = this->uinitMap[oneY][oneX];
			}
			
		}
	}
}

//��ʱ�䣬����ը����ը
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
		return 0;											//ʱ��δ��������
	}
	//ʱ�䵽�˱�ը��
	if (Bomber::bomberNum)
	{
		Bomber::bomberNum--;
		this->destoryMe();
	}
	else{ 
		cout << "�����ļ� Bomber" << endl;
	}
	return 1;																			//���� 1  ��֪����				
}




//�÷����Ƿ���û���
bool canIputTheFire(int getX, int getY, int* getDir)
{
	int triger = 0;
	if (getX < 0 || getY < 0)
	{
		*getDir = 0;																	//�÷����ܷ��û�����
		return false;
	}
	else if (getX> GAMEMAP_WIDE - SC_X_PIX || getY>GAMEMAP_HIGH - SC_Y_PIX)
	{
		*getDir = 0;																	
		return false;
	}
	MapUnit tempFire = Fire(getX, getY);												//ջ����
	MyNode* preNode = nullptr;
	for (MyNode* one = MapUnit::peopleCoList->firstNode->nextPtr; one != MapUnit::peopleCoList->LastNode; one = one->nextPtr)
	{
		preNode = one->prePtr;
		if (MapUnit::collisionCheck(&tempFire, one->node))
		{
			if (one->node->destoryMe() == 1){}																		//����ע�⣬����1 �������û����Ļ�����������one�����
			else{ one = preNode; }
			triger = 1;																//���津��
		}
	}
	if (triger)																			//���������ﵲ��������ᴥ�����浫�ǲ��������ǽ
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
			}												//����ǽ������
			else{																		
				if (one->node->destoryMe() == 1){}																		//����ע�⣬����1 �������û����Ļ�����������one�����
				else{ one = preNode; }									//�������ʱ��ע��
			}
		}
	}
	return true;
	

}
																					//���� true ��ʾ������ʾ

//��ȡ���ܵķ���û�б߽��ж� 0123 ��������
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
	else if (getDir == 2)			//���
	{
		*getX -= SC_X_PIX*power;
	}
	else if (getDir == 3)			//�ұ�
	{
		*getX += SC_X_PIX*power;
	}
}
//ը�������Լ������������ܽ�������
int Bomber::destoryMe()
{
	Director::scoreFinnal.boomTotal++;
	int rememRound[4] = { 1,1,1,1 };													//��¼�÷����Ƿ��ܷ�ֹ����
	
	this->mapUnit_erase(this);
	
	MapUnit::peopleCoList->deleteNode(this);
	
	canIputTheFire(this->posBase.xLeft, this->posBase.yUp, &rememRound[0]);				//rememRound[0]��㴫��
	Fire *one = new Fire(this->posBase.xLeft, this->posBase.yUp);						//�Լ���λ��Ҫ�� ����
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



