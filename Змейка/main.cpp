#include <iostream>
#include <stdio.h>
#include <conio.h>

#include "input.h"
#include "game.h"

int main()
{
	setlocale(0, "");
	int A(0), B(0);
	printf("¬ведите длину пол€\n");
	input(A);
	system("cls");
	printf("¬ведите высоту пол€\n");
	input(B);
	system("cls");
	game(A,B);
}