#include "Cards.h"

string Card::getValue()
{
	switch (value)
	{
	case 1:
		return "2";
	case 2:
		return "3";
	case 3:
		return "4";
	case 4:
		return "5";
	case 5:
		return "6";
	case 6:
		return "7";
	case 7:
		return "8";
	case 8:
		return "9";
	case 9:
		return "10";
	case 10:
		return "J";
	case 11:
		return "Q";
	case 12:
		return "K";
	case 13:
		return "A";
	default:
		break;
	}
}

Cards::Cards()
{
	int n = 0, i, j, k;
	char color[4] = { '\004','\003','\005','\006' };//004:·½¿é; 003:ºìĞÄ; 005:Ã·»¨; 006:ºÚÌÒ;
	Card newCards[52];
	for (i = 0; i <= 3; i++)
	{
		for (j = 1; j <= 13; j++)
		{
			newCards[n].setCard(j, color[i]);
			n++;
		}
	}

	for (k = 0; k < 52; k++)
	{
		cards[k] = newCards[k];
	}
}


void Cards::Deal()
{
	int i, j = 0;
	srand((int)time(0));
	for (i = 0; i < 52; i++)
	{
		swap(cards[i], cards[rand() % 52]);
	}
	for (i = 0; i < 3; i++)
	{
		player1[i] = cards[j++];
		player2[i] = cards[j++];
		player3[i] = cards[j++];
		player4[i] = cards[j++];
	}
}

