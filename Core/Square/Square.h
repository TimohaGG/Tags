#pragma once
#include"../Lib/lib.h"
struct square {
	int number;
	bool moovable;

};

square fillSquares(square** arr, int** arrN, int size);
void randNumber(int**& arrNumbers, int amountN, int size);
void ShowNum(square** arr, int size);