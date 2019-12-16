#include <stdio.h>
#include <conio.h>
#include <iostream>
#define ENTER 13
#pragma warning(disable: 4996)

void input(int & S) {
	char* ins;
	int error;
	char ch;
	char inputS[2];
	int lengthS;
	do {
		ins = inputS;
		error = 0;
		lengthS = 0;
		do
		{
			ch = getch();
			if (ch >= '0' && ch <= '9') printf("%c", ch);
			switch ((ch >= '0') && (ch <= '9') && (ins != &inputS[2]))
			{
			case(true):
				*ins = ch;
				ins++;
				++lengthS;
				break;
			case(false):
				if (ch == ENTER && ins != inputS) { error = 3; }
				else error = 1;
				break;
			}
		} while (error != 1 && error != 3);
		if (error == 1)
		{
			system("cls");
			printf("ќшибка. ¬ведите снова. „исло должно быть меньше 20 и больше 3\n");
		}

		if (error == 3) {
			for (int i = 0; i < lengthS; i++)
			{
				S *= 10;
				S += (inputS[i] - (int)'0');
			}
			if (S <3 || S>20) {
				system("cls");
				printf("„исло должно быть меньше 20 и больше 3\n");
				S = 0;
				error = 1;
			}
		}

	} while (error != 3);

	printf("\n");
}