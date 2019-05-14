#pragma once
#pragma once
#include "Cards.h"
enum Types { danzhang, duizi, shunzi, jinhua, shunjin, baozi };

class Judge
{
public:
	Judge(Card * card, int identity);//判断牌面大小
	int Compare(Judge * player1);//比较牌面大小
	int identity;//玩家身份
private:
	int values[3];
	Types type;
};

