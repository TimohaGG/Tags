#pragma once
#include"../../Core/Square/Square.h"
void PrintRules();
void CreateFiled(int& , int**& , int , square**& );
void BeginGame(square**, int);
struct Menu {
	Menu() {
		while (true) {
			cout << "����� ���������� � Tiles!!" << endl;
			cout << "1. ������ ����" << endl;
			cout << "2. ������� ����" << endl;
			cout << "0. �����" << endl;
			int choise;
			cin >> choise;
			CLEAR;
			switch (choise) {
			case 1: {
				int size = 0;
				int choise;
				do {
					cout << "1. 3 x 3" << endl;
					cout << "2. 4 x 4" << endl;
					cout << "0. �����" << endl;
					cin >> choise;
					if (choise == 1)size = 3;
					else if (choise == 2)size = 4;
					else break;
					CLEAR;
				} while (choise != 1 && choise != 2 && choise != 0);
				if (size != 0) {
					int numbersAmount=0;
					int** arrN;
					square** arrS;
					CreateFiled(size, arrN, numbersAmount,arrS);
					BeginGame(arrS, size);
				}
				
			}break;
			case 2: {
				PrintRules();
			}break;
			default:exit(0);
			}
			PAUSE;
			CLEAR;
		}
		
	}
};

void PrintRules() {
	cout << "1. ����������� ������ �� ��� ��� ���� ��� ����� �� ����� ���� �� �������" << endl;
	cout << "2. ��� �� ������� ����� ������ ����������� ������� �����, ������� ������� �� ������ ������" << endl;
	cout << "3. ��� �� ���������� ������ ����������� ���������"<<endl;
}

void CreateFiled(int& size, int**& arrN,int numbersAmount,square**& arrS) {
	 numbersAmount = size*size-1;
	 arrN = new int* [size];
	for (size_t i = 0; i < size; i++)
	{
		arrN[i] = new int[size];
	}
	
	 arrS = new square * [size];
	for (size_t i = 0; i < size; i++)
	{
		arrS[i] = new square[size];
	}
	//--------------------------------------
	randNumber(arrN, ++numbersAmount, size);
	fillSquares(arrS, arrN, size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			CreateTile(arrS[i][j]);
		}
	}
	ShowNum(arrS, size);
	cout << endl;
	CheckMovable(arrS, size);
}


	bool GameOver(square** arrS, int size) {
	int number = arrS[0][0].number;
	for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = 0; j < size-1; j++)
		{
			if (arrS[i][j].number != arrS[i][j+1].number + 1)
				return false;
			number = arrS[i][2].number;
		}
		
	}
	return true;
}

square GetIndex(square** arrS, int size, int tileToMove) {
	
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (arrS[i][j].number == tileToMove)
				return arrS[i][j];
		}
	}
	
}

square FindIndex(square** arrS, int size, int TileToFind) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (arrS[i][j].number == TileToFind) {
				return arrS[i][j];
			}
		}
	}
}



square MoveTile(square**& arrS, square Tile, int directionChosen, int size) {
	int x = Tile.x;
	int y = Tile.y;
	switch (directionChosen) {
	case 72: {
		arrS[x][y].number = arrS[x-1][y].number;
		arrS[x-1][y].number = Tile.number;
		CreateTile(arrS[x][y]);
		CreateTile(arrS[x - 1][y]);
	}break;
	case 77: {
		
		arrS[x][y].number = arrS[x][y+1].number;
		arrS[x][y + 1].number = Tile.number;
		CreateTile(arrS[x][y]);
		CreateTile(arrS[x][y+1]);
		
	}break;
	case 80: {
		arrS[x][y].number = arrS[x + 1][y].number;
		arrS[x + 1][y].number = Tile.number;
		CreateTile(arrS[x][y]);
		CreateTile(arrS[x + 1][y]);
	}break;
	case 75: {
		arrS[x][y].number = arrS[x][y - 1].number;
		arrS[x][y - 1].number = Tile.number;
		CreateTile(arrS[x][y]);
		CreateTile(arrS[x][y-1]);
		
	}break;
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			for (size_t k = 0; k < 4; k++)
			{
				arrS[i][j].MoveSide[k] = false;
				
			}
			arrS[i][j].moovable = false;
		}
	}
	return** arrS;
}

void BeginGame(square** arrS, int size) {
	square TileToMove;
	while (!GameOver(arrS,size)) {
		
			char tileToMoveChar;
			int tileToMove;
			do
			{
				cout << endl<<"����� ������ �� ������ �������?" << endl;
				if (size == 3) {
					tileToMoveChar = _getch();
					tileToMove = tileToMoveChar - '0';
				}
				else {
					cin >> tileToMove;
				}
				 
			} while (tileToMove<1|| tileToMove>size*size-1);
			
			square Tile=FindIndex(arrS,size, tileToMove);
			if (Tile.moovable) {
				cout << "���������� ������� � ������� ���������" << endl;
				char key = 0;
				bool tileMoved = false;
				do
				{

					key = _getch();
					switch ((int)key) {
					case 72: {
						if (Tile.MoveSide[up]) {
							cout << "Moving up"<<endl;
							tileMoved = true;
						}
						else {
							continue;
						}
					}break;
					case 77: {
						if (Tile.MoveSide[right]) {
							cout << "Moving right" << endl;
							tileMoved = true;
						}
						else {
							continue;
						}}break;
					case 80: {
						if (Tile.MoveSide[bottom]) {
							cout << "Moving bottom" << endl;
							tileMoved = true;
						}
						else {
							continue;
						}}break;
					case 75: {
						if (Tile.MoveSide[left]) {
							cout << "Moving left" << endl;
							tileMoved = true;
						}
						else {
							continue;
						}
					}break;
					}
					
				} while (!tileMoved);
				
				MoveTile(arrS, Tile, key, size);
				CheckMovable(arrS, size);
				CLEAR;
				ShowNum(arrS, size);
			}
			else {
				cout << "��� ������ ������ �������!!!"<<endl;
			}
			
		

	}


	//CheckMovable(arrS, size);
}