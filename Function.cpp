#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include "Header.h"

extern char bombs[20][20];
extern char panel[20][20];
extern int d, l, w;

using namespace std;

void draw(int dimension, bool alive)
{
	for (int x = 0; x < dimension; x++)
	{
		for (int y = 0; y < dimension; y++)
		{
			if (!alive)
			{
				if (bombs[x][y] == 'x')
					cout << " | " << bombs[x][y];
				else
					cout << " | " << panel[x][y];
			}
			else
				cout << " | " << panel[x][y];
		}
		cout << " |  " << x + 1 << "\n";
	}
	cout << "\n";
	for (int x = 0; x < dimension; x++)
		cout << " |" << setw(2) << x + 1;
	cout << " | ";
}

void setup(int dimension) {
	for (int x = 0; x < dimension; x++)
	{
		for (int y = 0; y < dimension; y++)
		{
			panel[x][y] = '-';
			bombs[x][y] = '-';
		}
	}
	switch (dimension)
	{
	case 10: setup2(10, dimension); break;
	case 15: setup2(40, dimension); break;
	case 20: setup2(100, dimension); break;
	}
}

void setup2(int bomb, int d)
{
	srand(time(0));
	for (; bomb != 0; )
	{
		int a = rand() % d;
		int b = rand() % d;

		if (bombs[a][b] != 'x')
		{
			bombs[a][b] = 'x';
			bomb--;
		}
	}

	static char nums[9] = { ' ', '1','2','3','4','5','6','7','8' };

	for (int x = 0; x < d; x++)
	{
		for (int y = 0; y < d; y++)
			bombs[x][y] = bombs[x][y] != 'x' ? nums[num(x, y)] : 'x';
	}
}

bool win(int dimension)
{
	bool winner = true;
	for (int x = 0; x < dimension; x++)
	{
		for (int y = 0; y < dimension; y++)
		{
			if (panel[x][y] == '-' && bombs[x][y] != 'x')
			{
				winner = false;
				break;
			}
		}
	}

	return winner;
}

int num(int x, int y)
{
	int count = 0;
	if (bombs[x + 1][y] == 'x')
		count++;
	if (bombs[x + 1][y + 1] == 'x')
		count++;
	if (bombs[x + 1][y - 1] == 'x')
		count++;
	if (bombs[x - 1][y] == 'x')
		count++;
	if (bombs[x - 1][y + 1] == 'x')
		count++;
	if (bombs[x - 1][y - 1] == 'x')
		count++;
	if (bombs[x][y + 1] == 'x')
		count++;
	if (bombs[x][y - 1] == 'x')
		count++;

	return count;
}

void ChoiceAndSetup()
{
	char livello;
	livel();
	cin >> livello;

	system("cls");

	while (livello != '1' && livello != '2' && livello != '3')
	{
		cout << "INVALID CHIOCE !!!\n\n";
		livel();
		cin >> livello;

		system("cls");
	}

	switch (livello)
	{
	case '1': d = 10; setup(d); break;
	case '2': d = 15; setup(d); break;
	case '3': d = 20; setup(d); break;
	}
}

void livel()
{
	if (l == 0 && w == 0)
	{
		cout << "\t\t\t###############################\n";
		cout << "\t\t\t#  MADE BY : MOHAMED HUSSEIN  #\n";
		cout << "\t\t\t###############################\n\n";
	}
	cout << "What lelvel of difficulty do you want to play ?\n\n";
	cout << "LOW [1]\n10 mines , 100 tile grid\n\nMEDIUM [2]\n40 mines , 225 tile grid\n\n";
	cout << "HIGH [3]\n100 mines , 400 tile grid\n\n\nSelect your level : ";
}

void expand_1(int x, int y)
{
	if (bombs[x - 1][y] == ' ' && panel[x - 1][y] != ' ')
	{
		panel[x - 1][y] = ' ';
		expand_1(x - 1, y);
		expand_2(x - 1, y);
	}
	if (bombs[x][y + 1] == ' ' && panel[x][y + 1] != ' ')
	{
		panel[x][y + 1] = ' ';
		expand_1(x, y + 1);
		expand_2(x, y + 1);
	}
}

void expand_2(int x, int y)
{
	if (bombs[x + 1][y] == ' ' && panel[x + 1][y] != ' ')
	{
		panel[x + 1][y] = ' ';
		expand_1(x + 1, y);
		expand_2(x + 1, y);
	}
	if (bombs[x][y - 1] == ' ' && panel[x][y - 1] != ' ')
	{
		panel[x][y - 1] = ' ';
		expand_1(x, y - 1);
		expand_2(x, y - 1);
	}
}

void wAndl()
{
	cout << "\t\t\t###############################\n";
	cout << "\t\t\t#  MADE BY : MOHAMED HUSSEIN  #\n";
	cout << "\t\t\t###############################\n\n";
	cout << " Wins = " << w;
	cout << "\nLosts = " << l << "\n\n";
}