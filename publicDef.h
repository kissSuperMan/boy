#pragma once
#include <iostream>
#include <windows.h>
#include <Windows.h>
#include <string>

using namespace std;

#define SENCE_START    5    //��ʼ����
#define SENCE_RAND_ONE 6	//�ؿ�һ
#define SENCE_OVER	   7		//��������
#define SENCE_INTRO	   8		//����
#define SENCE_READM	   9		//���ɵ�ͼ

#define SENCE_EXIT	   -1		//�˳�
#define MESS_SUCC_OVER      1		//�ɹ�
#define MESS_FAIL_OVER      0		//ʧ��


#define SCTX_WHITE 7
#define SC_X_PIX 5			//һ����Ԫ��X����
#define SC_Y_PIX 5		
#define SC_FOLL_WIDE  SC_X_PIX*3	//�������ľ���
#define SC_FOLL_HIGH  SC_Y_PIX*2


//ע�����¶������ɵ�ͼ�Ǳ��õĲ�һ��
#define OBNAME_NONAME 0
#define OBNAME_BRWALL 10				//ש��ǽ				//ǰ��дBR��־�� ˵�� 10 ש  11 �� 12����
#define OBNAME_BR_DOOR	11			//��
#define OBNAME_BR_AWARD  12			//����		//�����ש��������ؽ���

#define OBNAME_RIWALL 90			//����ǽ
#define OBNAME_ENEMY  50			

#define OBNAME_FIRE	  30			//����
#define OBNAME_HERO   40			
#define OBNAME_BOMER  60			//ը��

#define OBNAME_MARKET   80			//�̵�

#define OBNAME_FOOD   70				//ʳ�������˵������
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

//Game map�����ݽṹ
struct SC_Pix
{
	SC_Pix(){}
	SC_Pix(int _s, int _c){ shape = _s; color = _c; }
	int shape = 0;
	int color = SCTX_WHITE;
};
//�����ڵ�����
struct PainterInfo
{
	int x;
	int y;
	int fontCol=SCTX_WHITE;
	int useCharIndex = 0;
	string useChar;
};
//����Ļ�����Ϣ������ֱ��������ײ���
struct ObjectInfo		
{
	int yUp = 0;	
	int xLeft = 0;
	int wide = 1;			//����ע�⣡��  ���������wide��Ҫ����2
	int high = 1;
};

using namespace std;








