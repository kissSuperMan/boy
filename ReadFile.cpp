#include "ReadFile.h"
#include<fstream>

vector<int> ReadFile::fileKey;

map<int, map<int, int> > ReadFile::fileMap;
ReadFile::ReadFile()
{
}


ReadFile::~ReadFile()
{
}



//��ͼԪ������ 0��ͨ�� 1��ש 2���� 3�ǹ��� 4����

void ReadFile::readoutFile()
{
	
	//string path = "./unitLib/MapRandOne.csv";
	
	//string path = "./unitLib/Map48x48.csv";
	string path = "./unitLib/mapOne.csv";
	ifstream infile(path);
	string oneLine = "";
	if (infile.is_open()){  }
	else{cout << "�ļ�" << path << "��ʧ" << endl;}
	
	getline(infile, oneLine);
	string oneVal = "";
	int length = 1;
	do 
	{
		length = oneLine.find(',');
		oneVal = oneLine.substr(0, length);
		//cout << oneVal<<"   ";
		fileKey.push_back(atoi(oneVal.c_str()));
		oneLine = oneLine.substr(length + 1);
	} while (length != oneLine.npos);
	int ypos = 0;
	while (getline(infile, oneLine))
	{
		int xpos = 0;
		do
		{
			length = oneLine.find(',');
			oneVal = oneLine.substr(0, length);
			fileMap[ypos][(fileKey[xpos])] = atoi(oneVal.c_str());
			//cout << oneVal << "   ";
			oneLine = oneLine.substr(length + 1);
			xpos++;
		} while (length != oneLine.npos);
		ypos++;
		///cout << endl;
	}
	infile.close();
}





