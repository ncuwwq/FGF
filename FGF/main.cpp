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
		cout << "1.��Ϸ��ʼ(�׷֣�5)   2.��Ϸ����    3.��Ϸ����" << endl;
		cout << "��Ļ��֣�" << grade << endl;
		cout << "���������ѡ��:" << endl;
		cin >> select;
		if (select == 1) {
			int n = Identity();
			cout << "�������" << n + 1 << "����ң����֣�" << grade << endl;
			cout << "���ƽ׶Σ�" << endl;
			Cards cards;
			cards.Deal();
			cards.sort(cards.player1);
			cards.sort(cards.player2);
			cards.sort(cards.player3);
			cards.sort(cards.player4);
			Card * players[4] = { cards.player1, cards.player2, cards.player3, cards.player4 };
			now_g = 5 * 4;
			cout << "���ƽ�����Ŀǰ������" << now_g << endl;
			cout << "��Ϸ�׶Σ�Ŀǰ������" << now_g << endl;
			Playing(*players, game, n, &grade, &now_g);
		}
		else if (select == 2) {
			PrintRules();
		}
		else if (select == 3) {
			game = false;
		}
		else {
			cout << "��������ȷ������ѡ��" << endl;
		}
	}
}

void PrintRules()
{
	printf("1�����ӣ�AAA���222��С��\n \
			2��ͬ��˳��AKQ���A23��С��\n \
			3��ͬ����AKJ���352��С��\n \
			4��˳�ӣ�AKQ���234��С��\n \
			5�����ӣ�AAK���223��С��\n \
			6�����ţ�AKJ���352��С��\n \
			�桰թ�𻨡�������Сթ���ƴ���ʵ������������ı�Ľ�������ð�ռҵ���Ϸ��\n \
			����С��ͬʱ�ȿ�ΪС��\n \
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
				cout << "�ֵ���˵��(���֣�" << *grade << "):" << endl;
				while (start) {
					if (l > 1) {
						cout << "1.����   2.��ע   3.����   4.����" << endl;
						cout << "��Ļ��֣�" << *grade << endl;
					}
					else {
						cout << "1.����   2.��ע   3.����" << endl;
						cout << "��Ļ��֣�" << *grade << endl;
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
							cout << "Ŀǰ�׷֣�" << *now_g << endl;
							cout << "��Ļ��֣�" << *grade << endl;
						}
						else if (is_look[n] == 0)
						{
							*now_g += 10;
							*grade -= 10;
							cout << "Ŀǰ�׷֣�" << *now_g << endl;
							cout << "��Ļ��֣�" << *grade << endl;
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
						cout << "��������ȷ������ѡ��" << endl;
					}
				}
			}
			else if (is_quit[i] == 0 && game == true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				cout << "׼���У�3" << endl;
				Sleep(1 * 1000);
				cout << "׼���У�2" << endl;
				Sleep(1 * 1000);
				cout << "׼���У�1" << endl;
				Sleep(1 * 1000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "���" << i + 1 << "˵��:" << endl;
				if (is_look[i] == 1) {
					cout << "��ѡ���˸�ע" << endl;
					*now_g += 10;
					cout << "Ŀǰ�׷֣�" << *now_g << endl;
				}
				else if (is_look[i] == 0) {
					int i = Identity();
					if (i == 2) {
						cout << "��ѡ���˿��ƣ�Ȼ���ע" << endl;
						is_look[i] = 1;
						*now_g += 5;
						cout << "Ŀǰ�׷֣�" << *now_g << endl;
					}
					else {
						cout << "��ѡ����ֱ�Ӹ�ע" << endl;
						*now_g += 10;
						cout << "Ŀǰ�׷֣�" << *now_g << endl;
					}
				}

			}
		}
	}
}

void Open(Card * player)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	printf(" �ߣ�        �ߣ�         �ߣ�\n");
	printf("�� %-2c��       �� %-2c��        �� %-2c��\n", player[0].color, player[1].color, player[2].color);
	printf("��   ��       ��   ��        ��   ��\n");
	printf("�� %-2s��       �� %-2s��        �� %-2s��\n", player[0].getValue().c_str(), player[1].getValue().c_str(), player[2].getValue().c_str());
	printf(" ����        ����         ����\n");
};

void Over(Card * players, int q, int n, int * grade, int * now_g)
{
	int k;
	if (q == 0) {
		for (k = 0; k < 4; k++)
		{
			if (k == n) {
				cout << "�����:" << endl;
				Open(&players[k]);
			}
			else {
				cout << "���" << k + 1 << "���ƣ�" << endl;
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
						cout << "��ϲ���ʤ" << endl;
						*grade += *now_g;
						cout << "��Ļ��֣�" << *grade << endl;
					}
					else {
						cout << "��ϲ���" << p_0.identity << "��ʤ" << endl;
					}
				}
				else {
					if (n == 3) {
						cout << "��ϲ���ʤ" << endl;
						*grade += *now_g;
						cout << "��Ļ��֣�" << *grade << endl;
					}
					else {
						cout << "��ϲ���" << p_3.identity << "��ʤ" << endl;
					}
				}
			}
			else {
				if (p_2.Compare(&p_3) == 1) {
					if (n == 2) {
						cout << "��ϲ���ʤ" << endl;
						*grade += *now_g;
						cout << "��Ļ��֣�" << *grade << endl;
					}
					else {
						cout << "��ϲ���" << p_2.identity << "��ʤ" << endl;
					}
				}
				else {
					if (n == 3) {
						cout << "��ϲ���ʤ" << endl;
						*grade += *now_g;
						cout << "��Ļ��֣�" << *grade << endl;
					}
					else {
						cout << "��ϲ���" << p_3.identity << "��ʤ" << endl;
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
						cout << "��ϲ���ʤ" << endl;
						*grade += *now_g;
						cout << "��Ļ��֣�" << *grade << endl;
					}
					else {
						cout << "��ϲ���" << p_1.identity << "��ʤ" << endl;
					}
				}
				else {
					if (n == 3) {
						cout << "��ϲ���ʤ" << endl;
						*grade += *now_g;
						cout << "��Ļ��֣�" << *grade << endl;
					}
					else {
						cout << "��ϲ���" << p_3.identity << "��ʤ" << endl;
					}
				}
			}
			else {
				if (p_2.Compare(&p_3) == 1) {
					if (n == 2) {
						cout << "��ϲ���ʤ" << endl;
						*grade += *now_g;
						cout << "��Ļ��֣�" << *grade << endl;
					}
					else {
						cout << "��ϲ���" << p_2.identity << "��ʤ" << endl;
					}
				}
				else {
					if (n == 3) {
						cout << "��ϲ���ʤ" << endl;
						*grade += *now_g;
						cout << "��Ļ��֣�" << *grade << endl;
					}
					else {
						cout << "��ϲ���" << p_3.identity << "ʤ" << endl;
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
				cout << "���" << k + 1 << "���ƣ�" << endl;
				Open(&players[k]);
				Judge p(&players[k], k + 1);
				ps[s] = &p;
				s++;
			}
		}
		if (ps[0]->Compare(ps[1]) == 1)
		{
			if (ps[0]->Compare(ps[2]) == 1) {
				cout << "��ϲ���" << ps[0]->identity << "ʤ" << endl;
			}
			else {
				cout << "��ϲ���" << ps[2]->identity << "ʤ" << endl;
			}
		}
		else if (ps[1]->Compare(ps[2]) == 1)
		{
			cout << "��ϲ���" << ps[1]->identity << "ʤ" << endl;
		}
		else {
			cout << "��ϲ���" << ps[2]->identity << "ʤ" << endl;
		}
	}
}