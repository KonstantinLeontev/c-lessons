#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void wrongInput(void)
{
	cout << "Incorrect input. Please try again." << endl;
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

bool startGame(void)
{
	int choice;
	while (true)
	{
		cout << "Would you like to play connect4 (1) or quit (0)?";
		cin >> choice;
		if (choice == 1)
		{
			return true;
			break;
		}
		else if (choice == 0)
		{
			return false;
			break;
		}
		else
		{
			wrongInput();
		}
	}
}

int askSize(string size)
{
	int input;
	while (true)
	{
		cout << "Please enter a " << size << " of the board (6-100): ";
		cin >> input;
		if (input >= 6 && input <= 100)
		{
			break;
		}
		else
		{
			wrongInput();
		}
	}
	return input;
}

int **setSize(int width, int height)
{
	int **pBoard = new int*[height];
	for (int i = 0; i < height; i++)
	{
		pBoard[i] = new int[width];
	}
	return pBoard;
}

void startBoard(int **pBoard, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pBoard[i][j] = 0;
		}
	}
}

void displayBoard(int **pBoard, int width, int height)
{
	cout << "------- GAME BOARD --------" << endl;
	cout << "---------------------------" << endl;

	for (int i = height-1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			switch (pBoard[i][j])
			{
			case 0: cout << " _ "; break;
			case 1: cout << " + "; break;
			case 2: cout << " x "; break;
			}
		}
		cout << endl;
	}

	/*for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			switch (pBoard[i][j])
			{
			case 0: cout << " _ "; break;
			case 1: cout << " + "; break;
			case 2: cout << " x "; break;
			}
		}
		cout << endl;
	}*/
	cout << "---------------------------" << endl;
}

int move(int **pBoard, int width, int height, int player)
{
	int i, j;

	cout << "\nPlayer " << player << endl;
	while (true)
	{
		while (true)
		{
			cout << "Enter a row number or 0 for exit: ";
			cin >> i;
			if (i >= 1 && i <= height)
			{
				break;
			}
			else if (i == 0)
			{
				return i;
				break;
			}
			else
			{
				wrongInput();
			}
		}
		while (true)
		{
			cout << "Enter a column number or 0 for exit: ";
			cin >> j;
			if ((j >= 1 && j <= width) || j == 0)
			{
				break;
			}
			else if (j == 0)
			{
				return j;
				break;
			}
			else
			{
				wrongInput();
			}
		}
		if (pBoard[i - 1][j - 1] == 0)
		{
			pBoard[i - 1][j - 1] = player;
			break;
		}
		else
		{
			cout << "Already in use! You have to choose free place." << endl;
		}
	}
	return player;
}

bool checkForWin(int **pBoard, int width, int height, int player)
{
	bool win = false;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((j < width - 3 && (pBoard[i][j] == player && pBoard[i][j + 1] == player && pBoard[i][i + 2] == player && pBoard[i][i + 3] == player)) || // horiz check
				(i < height - 3 && (pBoard[i][j] == player && pBoard[i + 1][j] == player && pBoard[i + 2][j] == player && pBoard[i + 3][j] == player)) || // vert check
				(j < width - 3 && i < height - 3 && (pBoard[i][j] == player && pBoard[i + 1][j + 1] == player && pBoard[i + 2][j + 2] == player && pBoard[i + 3][j + 3] == player)) || // right rise diagonal check
				(j < width - 3 && i > 2 && (pBoard[i][j] == player && pBoard[i - 1][j + 1] == player && pBoard[i - 2][j + 2] == player && pBoard[i - 3][j + 3] == player)))
			{
				cout << "Player " << player << " has won!" << endl;
				win = true;
				break;
			}
		}
		if (win) break;
	}
	return win;
}

int main()
{
	int player;
	int width, height;
	int **pBoard;

	while (startGame())
	{
		player = 1;
		width = askSize("width");
		height = askSize("height");
		pBoard = setSize(width, height);
		startBoard(pBoard, width, height);
		displayBoard(pBoard, width, height);
		while (move(pBoard, width, height, player))
		{
			displayBoard(pBoard, width, height);
			if (checkForWin(pBoard, width, height, player))
			{
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