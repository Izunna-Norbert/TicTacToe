#pragma once
class TicTacToe
{
public:
	TicTacToe();
	void playgame();
	
	
private:
	int xcord();
	int ycord();
	bool placemarker(int x, int y, char currentplayer);
	bool checkforvictory(char currentplayer);
	//empties the board//
	void clearboard();
	//prints the board//
	void printboard();
	char board[3][3];

};

