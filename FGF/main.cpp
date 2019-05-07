#include <iostream>
#include <Windows.h>
#include "Cards.h"
#include "Rules.h"
using namespace std;


void main()
{
	int now_g, grade = 500;
	void PrintRules();
	void Playing(Card * players, bool game, int n, int * grade, int * now_g);
	int Identity();
	printf("**********************************************************************\n");
	printf("***  *        *   *                 *             *     *          ***\n");
	printf("***   *      *   *                *   *       ***************      ***\n");
	printf("***    *    *   * * * * *        *     *          *     *          ***\n");
	printf("***     *  *   *    *          *  *****  *          *   *          ***\n");
	printf("***      *          * * *   *       *       *      *    *   *      ***\n");
	printf("***     * *         * * *        *******         * *    *  *   *   ***\n");
	printf("***    *   *        *               *          *   *  * *       *  ***\n");
	printf("***   *     *       *            *******           *    * * * * *  ***\n");
	printf("**********************************************************************\n");
	bool game = true;
	while (game)
	{
		int select;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		cout << "1.游戏开始(底分：5)   2.游戏规则    3.游戏结束" << endl;
		cout << "你的积分：" << grade << endl;
		cout << "请输入你的选项:" << endl;
		cin >> select;
		if (select == 1) {
			int n = Identity();
			cout << "这局你是" << n + 1 << "号玩家，积分：" << grade << endl;
			cout << "发牌阶段：" << endl;
			Cards cards;
			cards.Deal();
			cards.sort(cards.player1);
			cards.sort(cards.player2);
			cards.sort(cards.player3);
			cards.sort(cards.player4);
			Card * players[4] = { cards.player1, cards.player2, cards.player3, cards.player4 };
			now_g = 5 * 4;
			cout << "发牌结束，目前分数：" << now_g << endl;
			cout << "游戏阶段：目前分数：" << now_g << endl;
			Playing(*players, game, n, &grade, &now_g);
		}
		else if (select == 2) {
			PrintRules();
		}
		else if (select == 3) {
			game = false;
		}
		else {
			cout << "请输入正确的数字选项" << endl;
		}
	}
}

void PrintRules()
{
	printf("1、豹子（AAA最大，222最小）\n \
			2、同花顺（AKQ最大，A23最小）\n \
			3、同花（AKJ最大，352最小）\n \
			4、顺子（AKQ最大，234最小）\n \
			5、对子（AAK最大，223最小）\n \
			6、单张（AKJ最大，352最小）\n \
			玩“诈金花”可能牌小诈走牌大，是实力、勇气和智谋的较量，是冒险家的游戏。\n \
			（大小相同时先开为小）\n \
		");
}

int Identity()
{
	int i;
	srand((int)time(0));
	i = rand() % 4;
	return i;
}

void Playing(Card * players, bool game, int n, int * grade, int * now_g)
{
	int i, l = 0;
	void Over(Card * players, int q, int n, int * grade, int * now_g);
	void Open(Card * player);
	int select, is_quit[4] = { 0 }, is_look[4] = { 0 };
	while (game)
	{
		l++;
		for (i = 0; i < 4; i++)
		{
			if (i == n && is_quit[n] == 0)
			{
				bool start = true;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << "轮到你说话(积分：" << *grade << "):" << endl;
				while (start) {
					if (l > 1) {
						cout << "1.看牌   2.跟注   3.弃牌   4.开牌" << endl;
						cout << "你的积分：" << *grade << endl;
					}
					else {
						cout << "1.看牌   2.跟注   3.弃牌" << endl;
						cout << "你的积分：" << *grade << endl;
					}
					cin >> select;
					if (select == 1) {
						Open(&players[n]);
						is_look[n] = 1;
					}
					else if (select == 2) {
						if (is_look[n] == 1)
						{
							*now_g += 5;
							*grade -= 5;
							cout << "目前底分：" << *now_g << endl;
							cout << "你的积分：" << *grade << endl;
						}
						else if (is_look[n] == 0)
						{
							*now_g += 10;
							*grade -= 10;
							cout << "目前底分：" << *now_g << endl;
							cout << "你的积分：" << *grade << endl;
						}
						start = false;
					}
					else if (select == 3) {
						is_quit[n] = 1;
						start = false;
						Over(players, is_quit[n], n, grade, now_g);
						game = false;
					}
					else if (select == 4 && l > 1) {
						*now_g += 10;
						*grade -= 10;
						Over(players, is_quit[n], n, grade, now_g);
						start = false;
						game = false;
					}
					else {
						cout << "请输入正确的数字选项" << endl;
					}
				}
			}
			else if (is_quit[i] == 0 && game == true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				cout << "准备中：3" << endl;
				Sleep(1 * 1000);
				cout << "准备中：2" << endl;
				Sleep(1 * 1000);
				cout << "准备中：1" << endl;
				Sleep(1 * 1000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "玩家" << i + 1 << "说话:" << endl;
				if (is_look[i] == 1) {
					cout << "他选择了跟注" << endl;
					*now_g += 10;
					cout << "目前底分：" << *now_g << endl;
				}
				else if (is_look[i] == 0) {
					int i = Identity();
					if (i == 2) {
						cout << "他选择了看牌，然后跟注" << endl;
						is_look[i] = 1;
						*now_g += 5;
						cout << "目前底分：" << *now_g << endl;
					}
					else {
						cout << "他选择了直接跟注" << endl;
						*now_g += 10;
						cout << "目前底分：" << *now_g << endl;
					}
				}

			}
		}
	}
}

void Open(Card * player)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	printf(" ＿＿        ＿＿         ＿＿\n");
	printf("│ %-2c│       │ %-2c│        │ %-2c│\n", player[0].color, player[1].color, player[2].color);
	printf("│   │       │   │        │   │\n");
	printf("│ %-2s│       │ %-2s│        │ %-2s│\n", player[0].getValue().c_str(), player[1].getValue().c_str(), player[2].getValue().c_str());
	printf(" ▔▔        ▔▔         ▔▔\n");
};

void Over(Card * players, int q, int n, int * grade, int * now_g)
{
	int k;
	if (q == 0) {
		for (k = 0; k < 4; k++)
		{
			if (k == n) {
				cout << "你的牌:" << endl;
				Open(&players[k]);
			}
			else {
				cout << "玩家" << k + 1 << "的牌：" << endl;
				Open(&players[k]);
			}
		}
		Judge p_0(&players[0], 1);
		Judge p_1(&players[1], 2);
		Judge p_2(&players[2], 3);
		Judge p_3(&players[3], 4);
		if (p_0.Compare(&p_1) == 1) {
			if (p_0.Compare(&p_2) == 1)
			{
				if (p_0.Compare(&p_3) == 1)
				{
					if (n == 0) {
						cout << "恭喜你获胜" << endl;
						*grade += *now_g;
						cout << "你的积分：" << *grade << endl;
					}
					else {
						cout << "恭喜玩家" << p_0.identity << "获胜" << endl;
					}
				}
				else {
					if (n == 3) {
						cout << "恭喜你获胜" << endl;
						*grade += *now_g;
						cout << "你的积分：" << *grade << endl;
					}
					else {
						cout << "恭喜玩家" << p_3.identity << "获胜" << endl;
					}
				}
			}
			else {
				if (p_2.Compare(&p_3) == 1) {
					if (n == 2) {
						cout << "恭喜你获胜" << endl;
						*grade += *now_g;
						cout << "你的积分：" << *grade << endl;
					}
					else {
						cout << "恭喜玩家" << p_2.identity << "获胜" << endl;
					}
				}
				else {
					if (n == 3) {
						cout << "恭喜你获胜" << endl;
						*grade += *now_g;
						cout << "你的积分：" << *grade << endl;
					}
					else {
						cout << "恭喜玩家" << p_3.identity << "获胜" << endl;
					}
				}
			}
		}
		else {
			if (p_1.Compare(&p_2) == 1)
			{
				if (p_1.Compare(&p_3) == 1)
				{
					if (n == 1) {
						cout << "恭喜你获胜" << endl;
						*grade += *now_g;
						cout << "你的积分：" << *grade << endl;
					}
					else {
						cout << "恭喜玩家" << p_1.identity << "获胜" << endl;
					}
				}
				else {
					if (n == 3) {
						cout << "恭喜你获胜" << endl;
						*grade += *now_g;
						cout << "你的积分：" << *grade << endl;
					}
					else {
						cout << "恭喜玩家" << p_3.identity << "获胜" << endl;
					}
				}
			}
			else {
				if (p_2.Compare(&p_3) == 1) {
					if (n == 2) {
						cout << "恭喜你获胜" << endl;
						*grade += *now_g;
						cout << "你的积分：" << *grade << endl;
					}
					else {
						cout << "恭喜玩家" << p_2.identity << "获胜" << endl;
					}
				}
				else {
					if (n == 3) {
						cout << "恭喜你获胜" << endl;
						*grade += *now_g;
						cout << "你的积分：" << *grade << endl;
					}
					else {
						cout << "恭喜玩家" << p_3.identity << "胜" << endl;
					}
				}
			}
		}
	}
	else {
		Judge * ps[3];
		int s = 0;
		for (k = 0; k < 4; k++)
		{
			if (k != n) {
				cout << "玩家" << k + 1 << "的牌：" << endl;
				Open(&players[k]);
				Judge p(&players[k], k + 1);
				ps[s] = &p;
				s++;
			}
		}
		if (ps[0]->Compare(ps[1]) == 1)
		{
			if (ps[0]->Compare(ps[2]) == 1) {
				cout << "恭喜玩家" << ps[0]->identity << "胜" << endl;
			}
			else {
				cout << "恭喜玩家" << ps[2]->identity << "胜" << endl;
			}
		}
		else if (ps[1]->Compare(ps[2]) == 1)
		{
			cout << "恭喜玩家" << ps[1]->identity << "胜" << endl;
		}
		else {
			cout << "恭喜玩家" << ps[2]->identity << "胜" << endl;
		}
	}
}