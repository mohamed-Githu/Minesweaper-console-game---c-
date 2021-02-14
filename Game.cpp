#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include "Header.h"

char bombs[20][20];
char panel[20][20];
int d = 0;
int w = 0, l = 0;

using namespace std;

int main()
{
	bool play = true;

	for (; play;)
	{
		ChoiceAndSetup();

		for (;;)
		{
			int x, y;

			wAndl();

			draw(d, true);

			cout << "\n\nEnter the dimensions of the spot to play :\n";

			cout << "Row : ";
			cin >> x;
			x--;

			cout << "Colone : ";
			cin >> y;
			y--;

			panel[x][y] = bombs[x][y];

			if (bombs[x][y] == ' ')
			{
				expand_1(x, y);
				expand_2(x, y);
			}

			if (panel[x][y] == 'x' || win(d))
			{
				system("cls");
				wAndl();
				draw(d, false);
				if (win(d))
				{
					cout << "\n\nYOU WON !!\n\n";
					w++;
				}
				else
				{
					cout << "\n\nTHe mine was in Row : " << x + 1 << " Colone : " << y + 1;
					cout << "\n\nYou have lost !!\n\n";
					l++;
				}
				break;
			}

			system("cls");
		}

		cout << "Want to play agin ?\nYES [1] NO [0]\n";
		cin >> play;

		system("cls");

		wAndl();
	}

	system("pause");
}