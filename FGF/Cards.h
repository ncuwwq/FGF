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
	string getValue();//��ֵ
	void setCard(int v, char c)
	{
		value = v;
		color = c;
	}
};


class Cards
{
public:
	Cards();//��ʼ��52���˿���
	void Deal();//ϴ�ƣ�����
	void sort(Card * cards);//������
	Card cards[52], player1[3], player2[3], player3[3], player4[3];
};

