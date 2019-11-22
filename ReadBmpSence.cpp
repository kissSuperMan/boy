#include "ReadBmpSence.h"
#include "publicDef.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include  <windows.h>
#define BACK_R 0
#define BACK_G 0
#define BACK_B 0
#define MAP_BRICK		OBNAME_BRWALL
#define MAP_BR_DOOR		OBNAME_BR_DOOR
#define MAP_BR_HIDAW	OBNAME_BR_AWARD

#define MAP_FOODMONY   OBNAME_FDMONY
#define MAP_FOODKEY    OBNAME_FDKEY
#define MAP_FOODBOM    OBNAME_FDBOM
#define MAP_FOODBLOOD    OBNAME_FDBLOOD

#define MAP_ENEMY      OBNAME_ENEMY
#define MAP_MARKET		OBNAME_MARKET
#define MAP_RIGWALL		OBNAME_RIWALL



using namespace std;
typedef unsigned char uvar8;
typedef unsigned int  uvar32;
typedef unsigned short int uvar16;
typedef struct { uvar8  Blue, Green, Red; } Palette;					//�����24λ��ͼ

 

ReadBmpSence::ReadBmpSence()
{

}


ReadBmpSence::~ReadBmpSence()
{

}


int packRgb(int getR, int getG, int getB);
void ReadBmpSence::runThisSence()
{
	uvar8  type[2];
	uvar32 Size, Reserved, Offset, HeaderSize, Width, Height, Compression, BitmapDataSize,
	HResolution, VResolution, Colors, ImportantColors;
	uvar16  Planes, Bibitcount;
	Palette	 RGBone;
	unsigned int i = 0, j = 0;
	ifstream fin;
	system("cls");
	ScreenCache::sc_paintGotoXY(0,0);
	cout << "*****************************someFourBmp�ļ���ȡ*******************************" << endl;
	fin.open("someFour.bmp", ios::binary);
	if (!fin)
	{
		cout << "someFour.bmp�ļ������ڻ��߱����������" << endl;
		abort();
	}
	cout << "*****************************λͼ�ļ�ͷ*******************************" << endl;
	fin.read((char*)&type, sizeof(type));
	cout << "file type:" << type[0] << type[1] << endl;
	fin.read((char*)&Size, sizeof(uvar32));  //4+2+4+4  //14
	cout << "file Size:" << Size << endl;
	fin.read((char*)&Reserved, sizeof(uvar32));
	cout << "����λ:" << Reserved << endl;
	fin.read((char*)&Offset, sizeof(uvar32));
	cout << "Offset:" << Offset << endl;
	cout << "*****************************λͼ��Ϣͷ*******************************" << endl;
	fin.read((char*)&HeaderSize, sizeof(uvar32));//40
	cout << "Header Size:" << HeaderSize << endl;
	fin.read((char*)&Width, sizeof(uvar32));
	cout << "��:" << Width << endl;
	fin.read((char*)&Height, sizeof(uvar32));
	cout << "��:" << Height << endl;
	fin.read((char*)&Planes, sizeof(uvar16));
	cout << "��ɫƽ����:" << Planes << endl;						  //һ����1		
	fin.read((char*)&Bibitcount, sizeof(uvar16));
	cout << "ÿ�����ص������:" << Bibitcount << endl;					// ��ʾÿ��������8λ��ʾ��һ����256����ɫ��
	fin.read((char*)&Compression, sizeof(uvar32));
	cout << "0�ǲ�ѹ��:" << Compression << endl;
	fin.read((char*)&BitmapDataSize, sizeof(uvar32));
	cout << "ͼ��Ĵ�С:" << BitmapDataSize << endl;
	fin.read((char*)&HResolution, sizeof(uvar32));
	cout << "ˮƽ�ֱ���:" << HResolution << endl;
	fin.read((char*)&VResolution, sizeof(uvar32));
	cout << "��ֱ�ֱ���:" << VResolution << endl;
	fin.read((char*)&Colors, sizeof(uvar32));
	cout << "0��û�е�ɫ��:" << Colors << endl;								//��ɫ��
	fin.read((char*)&ImportantColors, sizeof(uvar32));
	cout << "��Ҫ����ɫ����" << ImportantColors << endl;
	ofstream outfile("./unitLib/mapOne.csv");
	cout << "****************************��ʼ��������*******************************" << endl;
	for (i = 0; i < Width + 1; i++)
	{
		outfile << i << ",";
	}
	outfile << "\n";
	for (j = 0; j < Height; j++)
	{
		//outfile << j+1 << ",";
		for (i = 0; i < Width; i++)
		{
			fin.read((char*)&RGBone, sizeof(Palette));
			outfile << packRgb(RGBone.Red, RGBone.Green, RGBone.Blue) << ",";

		}
		outfile << "\n";
		cout << ".";
	}
	fin.close();
	outfile.close();
	cout << "****************************�µ�ͼ������ϣ������ⰴ������ ��ʼ ����*******************************" << endl;
	Director::senceMess.curSen = SENCE_START;						//���ؿ�ʼ����
	system("pause");
}


int packRgb(int getR, int getG, int getB)
{
	if (getR == 200 && getG == 255 && getB == 255)
	{
		return MAP_BRICK;					//����� 10 
	}
	else if (getR == 0 && getG == 255 && getB == 255)
	{
		return MAP_BR_DOOR;					//������
	}
	else if (getR == 255 && getG == 0 && getB == 0)
	{
		return MAP_ENEMY;
	}
	else if (getR == 0 && getG == 200 && getB == 0)
	{
		return MAP_MARKET;
	}
	else if (getR == 0 && getG == 0 && getB == 255)
	{
		return MAP_RIGWALL;
	}
	else if (getR == 0 && getG == 0 && getB == 255)
	{
		return MAP_RIGWALL;
	}
	else if (getR == 255 && getG == 0 && getB == 255)
	{
		return MAP_FOODKEY;
	}
	else if (getR == 255 && getG == 255 && getB == 0)
	{
		return MAP_FOODMONY;										//��ɫ��Ǯ
	}
	else if (getR == 100 && getG == 100 && getB == 50)
	{
		return MAP_FOODBOM;										//��ɫը��
	}
	else if (getR == 255 && getG == 100 && getB == 0)
	{
		return MAP_FOODBLOOD;										//Ѫ
	}
	//MAP_FOODBLOOD
	else
	{
		return 0;
	}

}






