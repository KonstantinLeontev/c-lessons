#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

void wrongInput(void)
{
	cout << "Incorrect input. Please try again." << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool start(void)
{
	string start;
	while (true)
	{
		cout << "Do you want to build maze (Y) or quit (N)?";
		cin >> start;
		if (start == "y" || start == "Y")
		{
			return true;
			break;
		}
		else if (start == "n" || start == "N")
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

int askForSize(string size)
{
	int sizeInput;
	while (true)
	{
		cout << "Please enter a " << size << " size (5-1000): ";
		cin >> sizeInput;
		if (sizeInput >= 5 && sizeInput <= 1000)
		{
			return sizeInput;
			break;
		}
		else
		{
			wrongInput();
		}
	}
}

int **buildMaze(int width, int height)
{
	int **pMaze = new int*[height];
	for (int i = 0; i < height; i++)
	{
		pMaze[i] = new int[width];
	}
	return pMaze;
}


void fillMaze(int **pMaze, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height-1) // first and last row
			{
				if (i == rand() % height || j == rand() % width)
				{
					pMaze[i][j] = 0;
				}
				else
				{
					pMaze[i][j] = 1;
				}
			}
			else if (j == 0 || j == width-1 ) // first and last column
			{
				if (i == rand() % height || j == rand() % width)
				{
					pMaze[i][j] = 0;
				}
				else
				{
					pMaze[i][j] = 1;
				}
			}
			else if (i % 2 == 1 && ((j >= i && j <= width - i) || (i>height/2 && (j >= height-i && j <= width - (height - i))))) // even rows
			{
				if (i == rand() % height || j == rand() % width)
				{
					pMaze[i][j] = 1;
				}
				else
				{
					pMaze[i][j] = 0;
				}
			}
			else if (j%2 == 1 && ((i >= j && i <= height - j) || (j>width/2 && (i >= width-j && i <= height - (width -j))))) // even columns
			{
				if (i == rand() % height || j == rand() % width)
				{
					pMaze[i][j] = 1;
				}
				else
				{
					pMaze[i][j] = 0;
				}
			}
			else // all others
			{
				if (i == rand() % height || j == rand() % width)
				{
					pMaze[i][j] = 0;
				}
				else
				{
					pMaze[i][j] = 1;
				}
			}
			//pMaze[i][j] = rand() % 2;
		}
	}
}

void displayMaze(int **pMaze, int width, int height)
{
	cout << "--------- MAZE ----------" << endl;
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			switch (pMaze[i][j])
			{
			case 0: cout << " "; break;
			case 1: cout << "#"; break;
			default: cout << "x";
			}
		}
		cout << endl;
	}
	cout << "------- MAZE END --------" << endl;
	cout << endl;
}

void checkHoles(int **pMaze, int width, int height)
{
	int currentJ = 0;
	for (int i = 0; i < height; i++)
	{
		//int holesInRow = 0;
		for (int j = currentJ; j < width; j++)
		{	
			if ((i < height - 1) && (pMaze[i][j] == 0 && pMaze[i+1][j] == 0))
			{
				currentJ = j; // jump to the same j from previous line
				break;
			}
			else if (j == width - 1)
			{
				j = rand() % width;
				pMaze[i][j] = 0;
				currentJ = j;
				cout << "Hole in row " << i << " column " << j << " has been maked!" << endl;
				break;
			}
		}
	}
}

int main()
{
	int width, height;
	int **pMaze;
	srand(time(NULL));

	while (start())
	{
		width = askForSize("width");
		height = askForSize("height");
		pMaze = buildMaze(width, height);
		fillMaze(pMaze, width, height);
		displayMaze(pMaze, width, height);
		checkHoles(pMaze, width, height);
		displayMaze(pMaze, width, height);
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}