#include "TipBoard.h"
#include "Bomber.h"
#include "HeroPlayer.h"

#define TIP_INT_Y	18				

#define TIP_STP_X	(SCGA_WIDE)*2+6		//��ʼд���Ե�λ�� Ҫ����2
#define TIP_STP_Y	3	
#define TIP_P_STEP  2				//�ָ���
TipBoard::TipBoard()
{
}

//property ����
//bullet �ӵ�
//dialogue �Ի�
TipBoard::~TipBoard()
{
}
//HeroPlayer::blood, Bomber::bomberNum, Bomber::boomPower, 1
void TipBoard::showPro()
{
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y);
	cout << "Ѫ��:" <<  HeroPlayer::blood << "  ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y + TIP_P_STEP);
	cout << "ը��ʣ��:" << HeroPlayer::boomberMax << "  ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y + TIP_P_STEP*2);
	cout << "����:" << Bomber::boomPower << "  ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y + TIP_P_STEP*3);
	cout << "��ɱ:" << HeroPlayer::killNum << "  ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_STP_Y + TIP_P_STEP * 4);
	cout << "���:" << HeroPlayer::monney << "  ";
	
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_INT_Y);
	
	cout << "��ϷĿ�꣺ ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_INT_Y);
	cout << "�ҵ�Կ�׿��ţ��ӳ����� ";
	//ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_INT_Y+TIP_P_STEP * 2);
	//cout << "�ҵ�Կ�׿��ţ��ӳ����� ";
	ScreenCache::sc_paintGotoXY(TIP_STP_X, TIP_INT_Y+TIP_P_STEP * 2);
	cout << "�ú����üƻ����ϵĽ��";
}

