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
//---------------------------------------

	fillSquares(arrS, arrN, size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			CreateTile(arrS[i][j]);
		}
	}
	ShowNum(arrS, size);
	CheckMovable(arrS, size);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			for (size_t k = 0; k < 4; k++)
			{
				if (arrS[i][j].MoveSide[k])
					cout << arrS[i][j].number << " can be moven to the " << k << endl;
			}
		}
	}
	
}