#pragma once
#include "publicDef.h"
#include <vector>
#include <map>
class ReadFile
{
public:
	static vector<int> fileKey;
	static map<int,map<int,int> > fileMap;		// (x,y,val)
	ReadFile();
	virtual ~ReadFile();
	static void readoutFile();
};








