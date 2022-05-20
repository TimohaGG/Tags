#include"Square.h"
square fillSquares(square** arr, int** arrN, int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			arr[i][j].number = arrN[i][j];
		}
	}
	return**arr;
}

bool noRepeat(int**& arr, int number, int amountN) {
	for (size_t i = 0; i < amountN; i++)
	{
		for (size_t j = 0; j < amountN; j++)
		{
			if (arr[i][j] == number)
				return false;
		}

	}
	return true;
}


void randNumber(int**& arrNumbers, int amountN, int size) {
	//int buf = gamesAvailable;
	arrNumbers[0][0] = rand() % amountN;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == 0 && j == 0) {
				continue;
			}
			else {
				int number;
				do {
					number = rand() % amountN;
					//cout << number << endl;
				} while (!noRepeat(arrNumbers, number, size));
				arrNumbers[i][j] = number;
				
			}
		}
	}
}

void ShowNum(square** arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << arr[i][j].number << " ";
		}
		cout << endl;
	}
}