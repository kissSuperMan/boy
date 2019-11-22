
/*
ҳ��ļܹ� ---
Ԫ���б�����������������������������������뀣������ܦ�ߣ��D���
��          ��Ϊһ�� 
5*5�ķ������ Ϊһ����ͼ��Ԫ

��ͼ ��ʾ���� 50��
		 �߶� 30��
*/
#pragma once
#include "publicDef.h"
#include "MapUnit.h"
#include <map>
#define SC_X_BASE 2				//������xy��λ��
#define SC_Y_BASE 1

//#define SC_X_PIX 5*2			//һ����Ԫ��X����
//#define SC_Y_PIX 5				
#define MAP_SIZE_HIGH 47
#define MAP_SIZE_WIDE 48
#define SCGA_WIDE		12*SC_X_PIX		//��ȾMAP�Ŀ��
#define SCGA_HIGH		7*SC_Y_PIX		//��ȾMAP�ĸ߶�

#define GAMEMAP_WIDE   MAP_SIZE_WIDE*SC_X_PIX		//ʵ�ʵĵ�ͼ��С
#define GAMEMAP_HIGH   MAP_SIZE_HIGH*SC_Y_PIX

#define SCGAFRAME_WIDE	(SCGA_WIDE*2+4)	//��Ϸ�ı߿�ָ�
#define SCGAFRAME_HIGH  (SCGA_HIGH+2)




//��ɫ �б�
#define SCTX_BACK 0
#define SCTX_BLUE 1
#define SCTX_GREEN 2
#define SCTX_DEEPBLUE 3		//����ɫ
#define SCTX_RED 4
#define SCTX_PURPLE 5
#define SCTX_YELLOW 6
//#define SCTX_WHITE 7
#define SCTX_GERY 8
#define SCTX_THINBLUE 9		//ǳ��ɫ
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

/*************************�����ȫ�ֺ���**********/

class MapUnit;

void sc_paintOnePix(PainterInfo* getInfo);
void sc_UnitToScCache(MapUnit*);
void sc_fileMapToCache();

class ScreenCache
{
public:	
	static int cacheStX;								//�ڴ濪ʼ��Ⱦ��λ�� ��  0 - 
	static int cacheStY;								//
	static SC_Pix gameMap[GAMEMAP_HIGH][GAMEMAP_WIDE];
	ScreenCache();
	~ScreenCache();
	static map<int, string> shapeMap;
	
	//�ڴ��д������Ļ��д��	
	static void sc_paintOnePix(PainterInfo* getInfo);						//�Զ����ˢ��һ��ͼ��
	static void sc_paintGotoXY(int _x, int _y, int _col=7);					//�ƶ�ָ��λ�õ��̶���λ��
	static void sc_fileMapToCache();
	void static sc_writeUnitInCacheMap(MapUnit* giveUnit);					//��Ԫ���͵���
	void static sc_writeUnitMix(MapUnit* first, MapUnit *secUnit);			//��ϵ�Ԫ���� �� ը��
	void static sc_clearUnitInCacheMap(MapUnit* giveUnit);					//��Ԫ�������
	void static clearHistoryMap();											//�����ʷ����
	static void sc_showMapCache();											//ȫ�建�浼��
	
};








