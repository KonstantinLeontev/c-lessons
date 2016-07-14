#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

struct Square
{
	int row;
	int column;
	int mark;
	Square *pNext;
};

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
		cout << "Would you like to play perfect tic-tac-toe game (Y or N)?";
		cin >> choice;
		if (choice == "y" || choice == "Y") { return true; break; }
		else if (choice == "n" || choice == "N") { return false; break; }
		else incorrectInput();
	}
}

Square *buildBoard(Square *pBoard)
{
	for (int i = 3; i >=1; i--)
	{
		for (int j = 3; j >=1; j--)
		{
			Square *pNew = new Square;
			cout << "j = " << j << " Test pNew = " << pNew << endl; // test line
			pNew->row = i;
			pNew->column = j;
			pNew->mark = 0;
			pNew->pNext = pBoard;
			pBoard = pNew;
			cout << "j = " << j << " Test pBoard = " << pBoard << endl; // test line
		}
	}
	return pBoard;
}


void drawBoard(Square *pBoard)
{
	Square *pCurr = pBoard;
	cout << "------ Tic-Tac-Toe ------" << endl;
	for (int i = 0; i < 3; i++)
	{	
		for (int j = 0; j < 3; j++)
		{
			switch (pCurr->mark)
			{
			case 1: cout << " x |"; break;
			case 2: cout << " o |"; break;
			case 0: cout << "   |"; break;
			}
			pCurr = pCurr->pNext;
		}
		cout << endl;
	}
	cout << "------  End Board  ------" << endl;
}

int moveNumbers(string pos)
{
	int num;
	while (true)
	{
		cout << "Enter a " << pos << " number (1-3) or 0 to exit:";
		cin >> num;
		if (num >= 0 && num <= 3)
		{
			return num;
			break;
		}
		else
		{
			incorrectInput();
		}
	}
}

bool move(Square *pBoard, int player)
{
	int tempRow, tempColumn;
	Square *pCurr = pBoard;
	cout << "\nPlayer " << player << ":" << endl;
	tempRow = moveNumbers("row");
	if (tempRow == 0) return false;
	else tempColumn = moveNumbers("column");
	if (tempColumn == 0) return false;
	else
	{
		while (pCurr != NULL)
		{
			if (pCurr->row == tempRow && pCurr->column == tempColumn)
			{
				pCurr->mark = player;
				return true;
				break;
			}
			pCurr = pCurr->pNext;
		}
	}
}

void winMessage(void)
{
	cout << "You are winner!" << endl;
	cout << endl;
}

bool checkWin(Square *pBoard, int player)
{
	Square *pCurr = pBoard;

	//for (int i=0; i<3; i++) // check for horizontal rows wins with loop
	//{
	//	int count = 0;
	//	for (int j = 0; j < 3; j++)
	//	{
	//		if (pCurr->mark == player) count += 1;
	//		pCurr = pCurr->pNext;
	//	}
	//	if (count == 3)
	//	{
	//		winMessage();
	//		cout << "First win message" << endl; // test line
	//		return true;
	//		//break;
	//	}
	//}

	//	for (int i = 0; i < 3; i++)
	//	{
	//		int count = 0;
	//		pCurr = pBoard; // check for each column start from beginning
	//		for (int j = 0; j < 3; j++)
	//		{
	//			for (int k = 0; k < 3; k++)
	//			{
	//				if (k == i && pCurr->mark == player) count += 1;
	//				pCurr = pCurr->pNext;
	//			}
	//		}
	//		if (count == 3)
	//		{
	//			winMessage();
	//			cout << "Second win message" << endl; // test line
	//			return true;
	//			//break;
	//		}
	//	}

		int countRightRise = 0;
		int countLeftRise = 0;
		int countHor = 0;
		int countVert1 = 0;
		int countVert2 = 0;
		int countVert3 = 0;
		pCurr = pBoard;
		for (int i = 1; i <= 9; i++)
		{
			if ((i == 1 || i == 5 || i == 9) && pCurr->mark == player) countLeftRise += 1; // check left diagonal
			if ((i == 3 || i == 5 || i == 7) && pCurr->mark == player) countRightRise += 1; // check right diagonal
			if ((i == 1 || i == 4 || i == 7) && pCurr->mark == player) countVert1 += 1;
			if ((i == 2 || i == 5 || i == 8) && pCurr->mark == player) countVert2 += 1;
			if ((i == 3 || i == 6 || i == 9) && pCurr->mark == player) countVert3 += 1;
			if (pCurr->mark == player) countHor += 1; //
			if ((i == 3 || i == 6 || i == 9) && countHor < 3) countHor = 0;
			pCurr = pCurr->pNext;
		}
		if (countRightRise == 3 || countLeftRise == 3 || countHor == 3 || countVert1 == 3 || countVert2 == 3 || countVert3 == 3)
		{
			winMessage();
			cout << "Third win message" << endl; // test line
			return true;
		}
		return false;
}


int main()
{
	int player;
	Square *pBoard = NULL;

	while (startMenu())
	{
		player = 1;
		cout << "Test Player = " << player << endl; // test line
		pBoard = buildBoard(pBoard);
		cout << "Test pBoardr = " << pBoard << endl; // test line
		drawBoard(pBoard);
		while (move(pBoard, player))
		{
			drawBoard(pBoard);
			if (checkWin(pBoard, player) == true) break;
			if (player == 1) player = 2;
			else player = 1;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
}