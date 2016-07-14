#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void incorrectInput(void)
{
	cout << "Incorrect input. Please try again!" << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool startMenu(void)
{
	string choice;
	while (true)
	{
		cout << "Would you like to play perfect Tic-Tac-Toe game (Y or N)?";
		cin >> choice;
		if (choice == "y" || choice == "Y") return true;
		else if (choice == "n" || choice == "N") return false;
		else incorrectInput();
	}
}

void fillBoard(int board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = 0;
		}
	}
}

void drawBoard(int board[3][3])
{
	cout << "-----------------" << endl;
	cout << "-- Tic-Tac-Toe --\n" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (board[i][j])
			{
			case 1: cout << " x |"; break;
			case 2: cout << " o |"; break;
			case 0: cout << "   |"; break;
			}
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
}

int moveNum(string pos)
{
	int num;
	while (true)
	{
		cout << "Enter a " << pos << " number (1-3) or 0 to exit:";
		cin >> num;
		if (num >= 0 && num <= 3) return num;
		else incorrectInput();
	}
}

bool move(int board[][3], int player)
{
	int row, column;
	cout << "Player: " << player << endl;
	while (true)
	{
		row = moveNum("row");
		if (row == 0) return false;
		column = moveNum("column");
		if (column == 0) return false;
		else if (board[row - 1][column - 1] == 0)
		{
			board[row - 1][column - 1] = player;
			break;
		}
		else
		{
			cout << "This square already marked. Choose free one!" << endl;
		}
	}
	return true;
}

void winMessage(void)
{
	cout << "---------------" << endl;
	cout << "You are winner!" << endl;
	cout << "---------------" << endl;
}

bool checkWin(int board[][3], int player)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) { winMessage(); return true; }
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) { winMessage(); return true; }
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) { winMessage(); return true; }
	if (board[2][0] == player && board[1][1] == player && board[0][2] == player) { winMessage(); return true; }
	return false;
}

int main()
{
	int player, moveCount;
	int board[3][3];

	while (startMenu())
	{
		player = 1;
		moveCount = 0;
		fillBoard(board);
		drawBoard(board);
		while (move(board, player))
		{
			moveCount += 1;
			drawBoard(board);
			if (checkWin(board, player) == true) break;
			if (moveCount == 9)
			{
				cout << "This is a draw!" << endl;
				break;
			}
			if (player == 1) player = 2;
			else player = 1;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}