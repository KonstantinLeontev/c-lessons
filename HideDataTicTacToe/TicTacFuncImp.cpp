#include <iostream>
//#include <string>
#include "tictacfunc.h"

using namespace std;

void incorrectInput(void)
{
	cout << "Incorrect input/ Please try again" << endl;
	cin.clear();
	cin.ignore();
}

bool startMenu(void)
{
	string choice;
	while (1)
	{
		cout << "Would you like to play perfect TicTacToe game (Y or N)? ";
		cin >> choice;
		if (choice == "y" || choice == "Y")
		{
			return true;
		}
		else if (choice == "n" || choice == "N")
		{
			return false;
		}
		else
		{
			incorrectInput();
		}
	}
}

void Board::win(void)
{
	cout << player << " has won!" << endl;
}

void Board::notEmptyMessage(void)
{
	cout << "This square is not empty. Try to choose another one!" << endl;
}

bool Board::checkWin(void)
{
	for (int i = 0; i < 3; i++) // check for horiz and vert
	{
		if ((board[0][i] == player && board[1][i] == player && board[2][i] == player) || (board[i][0] == player && board[i][1] == player && board[i][2] == player))
		{
			return true;
		}
	}
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[2][0] == player && board[1][1] == player && board[0][2] == player))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::checkEmpty(void)
{
	if (board[y][x] == EMPTY)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Board::getMove(void)
{
	board[y][x] = player;
}

int Board::chooseSquare(string name)
{
	int num;
	while (1)
	{
		cout << "Enter number of " << name << "(1-3) or 0 to quit: ";
		cin >> num;
		if (num >= 0 && num <= 3)
		{
			return num;
		}
		else
		{
			incorrectInput();
		}
	}
}

bool Board::move(void)
{
	while (1)
	{
		y = chooseSquare("row") - 1; // correct customer's input because array's members count starts from 0;
		if (y == -1)
		{
			return false;
		}
		x = chooseSquare("column") - 1;
		if (x == -1)
		{
			return false;
		}
		if (checkEmpty())
		{
			getMove();
			return true;
		}
		else
		{
			notEmptyMessage();
		}
	}
}

void Board::drawBoard(void)
{
	cout << "--- TicTacToe ---" << endl;
	cout << "-----------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (board[i][j])
			{
			case EMPTY: cout << "| _ |"; break;
			case PLAYER_1: cout << "| x |"; break;
			case PLAYER_2: cout << "| o |"; break;
			}
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
}

void Board::reset(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = EMPTY;
		}
	}
}