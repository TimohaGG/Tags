#pragma once
#include"../../Core/Square/Square.h"
void PrintRules();
void GameBegin();
struct Menu {
	Menu() {
		while (true) {
			cout << "����� ���������� � Tiles!!" << endl;
			cout << "1. ������ ����" << endl;
			cout << "2. ������� ����" << endl;
			int choise;
			cin >> choise;
			CLEAR;
			switch (choise) {
			case 1: {
				GameBegin();
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

void GameBegin() {
	int size = 3;
	int numbersAmount = size*size-1;
	int** arrN = new int* [size];
	for (size_t i = 0; i < size; i++)
	{
		arrN[i] = new int[size];
	}
	
	square** arrS = new square * [size];
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