#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

bool checkSize(int size)
{
	if (size > 1 && size < 100)
	{
		return true;
	}
	else
	{
		cout << "Wrong input, try again!" << endl;
		return false;
	}
}

void fillTable(int **p_arr, int x_size, int y_size)
{
	for (int i = 0; i < y_size; i++)
	{
		for (int j = 0; j < x_size; j++)
		{
			p_arr[i][j] = i*j;
		}
	}
}

void space(int val)
{
	if (val < 10)
	{
		cout << "|   " << val << "   |";
		//cout << "   |   ";
	}
	else if (val < 100)
	{
		cout << "|  " << val << "   |";
		//cout << "  |  ";
	}
	else if (val < 1000)
	{
		cout << "| " << val << "   |";
		//cout << " | ";
	}
	else
	{
		cout << "|" << val << "   |";
		//cout << "|";
	}
}

void displayTable(int **p_arr, int x_size, int y_size)
{
	//space(1);
	//cout << "X";
	space(0);
	for (int i = 0; i < x_size; i++)
	{
		//cout << i;
		space(i);
	}
	cout << endl;

	for (int i = 0; i < y_size; i++)
	{
		//space(i);
		//cout << i;
		space(i);
		for (int j = 0; j < x_size; j++)
		{
			//cout << p_arr[i][j];
			space(p_arr[i][j]);
		}
		cout << endl;
	}

	cout << "\np_arr = " << p_arr << endl;
}

int main()
{
	int x_size, y_size;
	string exit;

	while (1) // start of table loop
	{
		// start input size
		do
		{
			cout << "Enter X size of table (2-100): ";
			cin >> x_size;
		} while (!checkSize(x_size));
		do
		{
			cout << "Enter Y size of table(2-100): ";
			cin >> y_size;
		} while (!checkSize(y_size));
		// end input size

		int **p_table = new int*[y_size]; // allocate memory for new rows
		for (int i = 0; i < y_size; i++) // allocate memory width for each row by x_size
		{
			p_table[i] = new int[x_size];
		}

		fillTable(p_table, x_size, y_size);
		displayTable(p_table, x_size, y_size);

		cout << "Do you want to build new table (Y) or quit (N)?";
		cin >> exit;
		if (exit != "y" && exit != "Y")
		{
			break;
		}
		else
		{
			for (int i = 0; i < y_size; i++)
			{
				delete [ ] p_table[i];
			}
			delete [ ] p_table;
		}
	}
	// end of table loop


	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}