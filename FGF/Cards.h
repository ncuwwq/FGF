#pragma once
#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class  Card
{
public:
	int value;
	char color;
	string getValue();//牌值
	void setCard(int v, char c)
	{
		value = v;
		color = c;
	}
};


class Cards
{
public:
	Cards();//初始化52张扑克牌
	void Deal();//洗牌，发牌
	void sort(Card * cards);//整理牌
	Card cards[52], player1[3], player2[3], player3[3], player4[3];
};

