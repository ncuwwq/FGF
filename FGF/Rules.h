#pragma once
#pragma once
#include "Cards.h"
enum Types { danzhang, duizi, shunzi, jinhua, shunjin, baozi };

class Judge
{
public:
	Judge(Card * card, int identity);//�ж������С
	int Compare(Judge * player1);//�Ƚ������С
	int identity;//������
private:
	int values[3];
	Types type;
};

