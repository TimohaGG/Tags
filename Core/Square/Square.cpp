#include"Square.h"
square fillSquares(square** arr, int** arrN, int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			arr[i][j].number = arrN[i][j];
			arr[i][j].x = i;
			arr[i][j].y = j;
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
	arrNumbers[2][2] = 0;
	for (int i = size-1; i >=0; i--)
	{
		for (int j = size-1; j>=0; j--)
		{
			if (i == 2 && j == 2) {
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


void ShowTile(string tile[5][5], int& x, int& y) {
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			cout << tile[i][j];
		}
		y++;
		COORD position = { x,y }; //позиция x и y
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, position);
	}
}

void ShowNum(square** arr, int size) {
	int x = 0;
	int y = 0;
	int yTmp = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			COORD position = { x,y }; //позиция x и y
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hConsole, position);
			ShowTile(arr[i][j].tile, x, y);
			x += 10;
			y = yTmp;
		}
		x = 0;
		y += 5;
		yTmp += 5;
	}
}



void CreateTile(square& Tile){
	for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (Tile.number == 0)
					Tile.tile[i][j] = "  ";
				else {
					if (i == 0 || i == 4)
						Tile.tile[i][j] = " *";
					else if (j == 0 || j == 4)
						Tile.tile[i][j] = " *";
					else if (j == 2 && i == 2)
						Tile.tile[i][j] = " " + to_string(Tile.number);
					else
						Tile.tile[i][j] = "  ";
				}
				
			}
		}
}

void CheckMovable(square**& arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i + 1 < 3){
				if (arr[i + 1][j].number == 0) {
					arr[i][j].moovable = true;
					arr[i][j].MoveSide[bottom] = true;
				}	
			}
			 if (i - 1 >-1) {
				 if (arr[i - 1][j].number == 0) {
					arr[i][j].moovable = true;
					arr[i][j].MoveSide[up] = true;
				}
					
			}
			 if (j + 1 < 3) {
				 if (arr[i][j + 1].number == 0)
				 {
					 arr[i][j].moovable = true;
					 arr[i][j].MoveSide[right] = true;
				}
					
			}
			 if (j - 1 >-1) {
				 if (arr[i][j - 1].number == 0) {
					 arr[i][j].moovable = true;
					 arr[i][j].MoveSide[left] = true;
				}
					
			}
			
		}
	}
}
