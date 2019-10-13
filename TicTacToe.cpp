#include "TicTacToe.h"
#include <iostream>

using namespace std;

void TicTacToe::playgame(){
	clearboard();
	char player1 = 'X';
	char player2 = 'O';
	char currentplayer = 'X';
	bool gamedone = false;
	int x, y;
	int turns = 0;

	while(gamedone==false){
		printboard();
		x = xcord();
		y = ycord();
		if (placemarker(x, y, currentplayer)== false){
			cout << "Spot Occupied" << endl;
		}

		else {
			turns++;
			if(checkforvictory(currentplayer)==true){
				cout << "The game is over! Player" << currentplayer << " won" << endl;
				gamedone = true;
			}else if(turns==9){
				cout << "It is a tie game!" << endl;
				gamedone = true;
			}
			//switches players//
			if (currentplayer == player1) {
				currentplayer = player2;
			}
			else {
				currentplayer = player1;;
			}
		}
	}
	
}
int TicTacToe::xcord() {
	int x;
	bool isInputBad = true;
	while (isInputBad == true) {
		cout << "Enter x cordinate" << endl;
		cin >> x;
		if(x<1 || x>3){
			cout << "bad x cordinate input" << endl;
		}else {
			isInputBad = false;
		}
	}
	return x-1;
}
int TicTacToe::ycord(){
	int y;
	bool isInputBad = true;
	while (isInputBad == true) {
		cout << "Enter y cordinate" << endl;
		cin >> y;
		if(y<1||y>3){
			cout << "Bad y cordinate input" << endl;
		}else {
			isInputBad = false;
		}
	}
	return y-1;
}
bool TicTacToe::placemarker(int x,int y,char currentplayer){
	if(board[y][x] != ' '){
		return false;
	}
	board[y][x] = currentplayer;
	return true;
}
bool TicTacToe::checkforvictory(char currentplayer) {
	
		for (int i = 0;i < 3;i++) {
			//checking rows//
			if ((board[i][0]==currentplayer) && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
				return true;
			}
		}
		for (int i = 0;i < 3;i++) {
			//checking colums
			if ((board[0][i] == currentplayer) && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
				return true;
			}
		}
		//checking top left diagonal//
		if ((board[0][0] == currentplayer) && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			return true;
		}
		if ((board[0][2] == currentplayer) && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			return true;
		}
		return false;
	
}




TicTacToe::TicTacToe()
{
	
}
void TicTacToe::clearboard(){
	for(int y=0;y<3;y++){
		for(int x=0;x<3;x++){
			board[y][x] = ' ';
		}
	
	}
}
void TicTacToe::printboard(){
	cout << endl;
	cout << " |1 2 3|\n";
	for(int y=0;y<3;y++){
		cout << "  -----\n";
		cout<<y+1 << "|" << board[y][0] << "|" << board[y][1] << "|" << board[y][2] <<"|"<< endl;
	}
	cout << "  -----\n";
}