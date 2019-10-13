#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main (){
	char ans;
	TicTacToe game;
	do {
		game.playgame();
		cout << "Do you want a rematch ? \n Enter (Y/N)..";
		cin >> ans;
		system("cls");
	} while (ans == 'y' || ans == 'Y');
	
	system("pause");
	return 0;
}