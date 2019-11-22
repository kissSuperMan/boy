#pragma once
#include "Sence.h"
class GameSence :
	public Sence
{
public:
	virtual void runThisSence();
	virtual void overThisSence();
	GameSence();
	virtual ~GameSence();
	void sc_frameShow();										//œ‘ æ±ﬂøÚ
};

