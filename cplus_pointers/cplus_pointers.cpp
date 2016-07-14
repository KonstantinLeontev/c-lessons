#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int **addRow(int **p_p_arr, int columns, int rows)
{
	p_p_arr[rows] = new int[columns];
	return p_p_arr;
}

void displayArr(int **p_p_arr, int columns, int rows, int count)
{
	cout << count << ": " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << p_p_arr[i][j] << " | ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "p_p_arr = " << p_p_arr << endl;
	cout << "*p_p_arr = " << *p_p_arr << endl;
	cout << "**p_p_arr = " << **p_p_arr << endl;
	cout << endl;
}

int main()
{
	int val, x_pos;
	int columns = 2, rows = 3, count = 0;
	int **p_p_arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		p_p_arr[i] = new int[columns];
	}

	cout << "Please enter a number: ";
	cin >> val;

	while (val > 0)
	{
		if (columns*rows == count + 1)
		{
			p_p_arr = addRow(p_p_arr, columns, rows);
			rows += 1;
		}

		if (count < columns)
		{
			x_pos = count;
		}
		else
		{
			x_pos = count%columns;
		}

		p_p_arr[count / columns][x_pos] = val;
		displayArr(p_p_arr, columns, rows, count);

		count += 1;
		cout << "Please enter a number or '0' to exit: ";
		cin >> val;
	}

	cin.ignore(10, '\n');
	cin.get();
	return 0;
}