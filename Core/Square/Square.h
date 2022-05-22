#pragma once
#include"../Lib/lib.h"
enum {right,left,bottom,up};

struct square {
	int number;
	int x;
	int y;
	bool moovable=false;
	bool MoveSide[4]{ false,false,false,false };
	string tile[5][5];
	
	
};

square fillSquares(square** arr, int** arrN, int size);
void randNumber(int**& arrNumbers, int amountN, int size);
void ShowNum(square** arr, int size);
void CreateTile(square& Tile);
void CheckMovable(square**& arr, int size);