#include"Core/Square/Square.h"
int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int size = 3;
	int amountN = 8;
	//int arrN[size][size];
	int** arrN = new int* [size];
	for (size_t i = 0; i < size; i++)
	{
		arrN[i] = new int[size];
	}
	randNumber(arrN, ++amountN, size);


	square** arrS = new square * [size];
	for (size_t i = 0; i < size; i++)
	{
		arrS[i] = new square[size];
	}
	fillSquares(arrS, arrN, size);
	ShowNum(arrS, size);
}