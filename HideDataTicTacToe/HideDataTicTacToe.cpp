#include <iostream>
//#include <string>
#include "tictacfunc.h"

using namespace std;


int main()
{
	Board *pBoard = new Board;

	while (startMenu())
	{
		pBoard->player = PLAYER_1;
		pBoard->reset();
		pBoard->drawBoard();
		while (pBoard->move())
		{
			pBoard->drawBoard();
			if (pBoard->checkWin())
			{
				pBoard->win();
				break;
			}
			if (pBoard->player == PLAYER_1)
			{
				pBoard->player = PLAYER_2;
			}
			else
			{
				pBoard->player = PLAYER_1;
			}
		}
	}

	cout << "Again I tell you..." << endl;
	cin.ignore();
	cin.get();
	return 0;
}