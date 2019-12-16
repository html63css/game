#include <iostream>
#include <conio.h>
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
#pragma warning(disable: 4996)

int POS[400][2] = { 9,9 };
char ARR[22][22] = { 0 };
int food[4][2] = { 0 };

void FOOD(int A, int B, int length, int j)
{
	bool fl;
	bool flage;
	do{
		int rA = rand() % A + 1;
		int rB = rand() % B + 1;
		flage = 1;
		fl = 0;
		for (int e = 0; e < length; ++e)
		{
			if (POS[e][0] == rB && POS[e][1] == rA) 
			{ 
			flage = 0;
			fl = 1;
			}
		}
		for (int e = 0; e < 4; ++e)
		{
			if (food[e][0] == rB && food[e][1] == rA)
			{
				flage = 0;
				fl = 1;
			}
		}
		if (flage)
		{
			food[j][0] = food[j][0] == 0 ? rB : food[j][0];
			food[j][1] = food[j][1] == 0 ? rA : food[j][1];
		}
	}while (fl);
}

void motion (int length)
{
	for (int i = length - 1; i >= 1; --i)
	{
		POS[i][0] = POS[i - 1][0];
		POS[i][1] = POS[i - 1][1];
	}
}

bool win(int A, int B, int length)
{
	if (length == A*B) 
	{
		printf("\tВЫ ПОБЕДИЛИ!!!");
		return 1;
	}
	else return 0;
}

bool defeat()
{
	for (int i = 2; i <= 49; ++i)
	{
		if (POS[0][0] == POS[i][0] && POS[0][1] == POS[i][1])
		{
			printf("\tвы проиграли...");
			return 0;
		}
	}
		if (ARR[POS[0][0]][POS[0][1]] == '#')
		{
			printf("\tвы проиграли...");
			return 0;
		}
	return 1;
}

void game(int A, int B)
{	
	bool next = 0;
	int length = 1;
	bool flage = 0;
	POS[0][0] = 1;
	POS[0][1] = 1;
	for (int i = 0; i < A + 2; ++i)
	{
		ARR[0][i] = '#';
		ARR[B + 1][i] = '#';
	}
	for (int i = 0; i < B + 2; ++i)
	{
		ARR[i][0] = '#';
		ARR[i][A + 1] = '#';
	}
	FOOD(A, B, length, 0);
	FOOD(A, B, length, 1);
	FOOD(A, B, length, 2);
	FOOD(A, B, length, 3);
	do
	{
		for (int i = 0; i < B + 2; ++i)
		{
			for (int j = 0; j < A + 2; ++j)
			{
				flage = 0;
				for (int e = 0; e < length; e++)
				{
					if (POS[e][0] == i && POS[e][1] == j)
					{
						printf("O");
						flage = 1;
						break;
					}
				}
				for (int e = 0; e < 4; e++)
				{
					if (food[e][0] == i && food[e][1] == j && flage != 1)
					{
						printf("E");
						flage = 1;
						break;
					}
				}
				if (flage != 1)
				{
					printf("%c", ARR[i][j]);
				}
			}
			printf("\n");
		}
		char ch =  getch();
		switch (ch)
		{
		case LEFT:
			if (POS[0][1] - 1 != POS[1][1] || POS[1][1] == 0)
			{
			motion(length);
			--POS[0][1];
			}
			break;
		case RIGHT:
			if (POS[0][1] + 1 != POS[1][1] || POS[1][1] == 0)
			{
				motion(length);
				++POS[0][1];
			}
			break;
		case UP:
			if (POS[0][0] - 1 != POS[1][0] || POS[1][0] == 0)
			{
				motion(length);
				--POS[0][0];
			}
			break;
		case DOWN:
			if (POS[0][0] + 1 != POS[1][0] || POS[1][0] == 0)
			{
				motion(length);
				++POS[0][0];
			}
			break;
		}

		for (int e = 0; e < 4; ++e)
		{
			if (POS[0][0] == food[e][0] && POS[0][1] == food[e][1])
			{
			food[e][0] = 0;
			food[e][1] = 0;
			if (A * B - length >= 4)
			{
				FOOD(A, B, length, e);
			}
			else
			{
				food[e][0] = -1;
				food[e][1] = -1;
			}
			++length;
			next = 1;
			POS[length - 1][0] = 99;
			POS[length - 1][1] = 99;
			break;
			}
		}
		system("cls");
	} while (defeat() && !win(A,B,length));

}