#pragma once
#include"../../Core/Square/Square.h"
void PrintRules();
void GameBegin();
struct Menu {
	Menu() {
		while (true) {
			cout << "Добро пожаловать в Tiles!!" << endl;
			cout << "1. Начать игру" << endl;
			cout << "2. Правила игры" << endl;
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
	cout << "1. Перемещайте плитки до тех пор пока все числа не будут идти по порядку" << endl;
	cout << "2. Что бы выбрать какую плитку переместить введите цифру, которая указана на данной плитке" << endl;
	cout << "3. Что бы перемесить плитку используйте стрелочки"<<endl;
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