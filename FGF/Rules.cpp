#include "Rules.h"

Judge::Judge(Card * cards, int id)
{
	values[0] = cards[0].value;
	values[1] = cards[1].value;
	values[2] = cards[2].value;
	identity = id;

	if (cards[0].value == cards[1].value && cards[0].value == cards[2].value)
	{
		type = baozi;
		return;
	}
	else if (cards[0].value == cards[1].value || cards[0].value == cards[2].value || cards[1].value == cards[2].value) {
		type = duizi;
		return;
	}
	if (cards[0].value == cards[1].value + 1 && cards[1].value == cards[2].value + 1)
	{
		if (cards[0].color == cards[1].color && cards[0].color == cards[2].color)
		{
			type = shunjin;
		}
		else {
			type = shunzi;
		}
		return;
	}
	else if (cards[0].color == cards[1].color && cards[0].color == cards[2].color) {
		type = jinhua;
		return;
	}
	type = danzhang;
	return;
}

int Judge::Compare(Judge * player)
{
	int i;
	if (type > player->type)
	{
		return 1;
	}
	else if (type < player->type)
	{
		return 0;
	}
	else if (type == player->type)
	{
		for (i = 0; i < 3; i++)
		{
			if (values[i] > player->values[i])
			{
				return 1;
			}
			else if (values[i] < player->values[i])
			{
				return 0;
			}
			else if (values[i] == player->values[i] && i == 2)
			{
				return 0;
			}
		}
	}
}

