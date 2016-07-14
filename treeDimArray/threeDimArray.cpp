#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int askForSize(string size)
{
	int sizeValue;
	while(1)
	{
		cout << "Please enter a " << size << " value (1-100): ";
		cin >> sizeValue;
		if (sizeValue > 0 || sizeValue < 100)
		{
			break;
		}
		else
		{
			cout << "Wrong input, try again!" << endl;
		}
	}
	return sizeValue;
}

int ***newTableArr(int length, int width, int height)
{
	int ***p_table = new int**[length];
	for (int i = 0; i < length; i++)
	{
		p_table[i] = new int*[width];
		for (int j = 0; j < width; j++)
		{
			p_table[i][j] = new int[height];
		}
	}
	return p_table;
}

void fillArr(int ***p_table, int length, int width, int height)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int k = 0; k < height; k++)
			{
				p_table[i][j][k] = i*j*k;
			}
		}
	}
}

void space(int val)
{
	if (val < 10)
	{
		cout << "|   " << val << "   |";
	}
	else if (val < 100)
	{
		cout << "|  " << val << "   |";
	}
	else if (val < 1000)
	{
		cout << "| " << val << "   |";
	}
	else
	{
		cout << "|" << val << "   |";
	}
}

void displayArr(int ***p_table, int length, int width, int height)
{
	for (int k = 0; k < height; k++) // all tables
	{
		cout << "\nTable " << k << endl;
		// start first line
		space(1);
		for (int i = 0; i < width; i++)
		{
			space(i);
		}
		cout << endl; // end first line

		for (int i = 0; i < length; i++) // start of main table
		{
			space(i); // first value in row
			for (int j = 0; j < width; j++)
			{
				space(p_table[i][j][k]);
			}
			cout << endl; // end of row
		} // end of main table
		cout << endl;
	} // end of all tables
}

void freeArr(int ***p_table, int length, int width, int height)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			delete[] p_table[i][j];
		}
		delete[] p_table[i];
	}
	delete[] p_table;
}

bool askForExit(void)
{
	string exit;
	cout << "Do you want to build another table (Y) or quit (N)? ";
	cin >> exit;
	if (exit == "y" || exit == "Y")
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	int length, width, height;

	while(1)
	{
		length = askForSize("length");
		width = askForSize("width");
		height = askForSize("height");
		int ***p_tableArr = newTableArr(length, width, height);

		fillArr(p_tableArr, length, width, height);
		displayArr(p_tableArr, length, width, height);
		freeArr(p_tableArr, length, width, height);
		if (askForExit())
		{
			break;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}