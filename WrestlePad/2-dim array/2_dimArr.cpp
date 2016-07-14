#include <iostream>
#include <string>
using namespace std;

int askForSize(string size)
{
	int sizeVal;
	while (1)
	{
		cout << "Please enter an " << size << " value (1-100): ";
		cin >> sizeVal;
		if (sizeVal > 0 || sizeVal < 100)
		{
			break;
		}
		else
		{
			cout << "Wrong input, try again!" << endl;
		}
	}
	return sizeVal;
}

int **makeArr(int x, int y)
{
	int **p_p_arr = new int*[y];
	for (int i = 0; i < y; i++)
	{
		p_p_arr[i] = new int[x];
	}
	return p_p_arr;
}

void displayArrAdress(int **pArr, int x, int y)
{
	cout << "\nDisplay array's adresses" << endl;
	cout << "pArr = " << pArr << endl;
	for (int i = 0; i < y; i++)
	{
		cout << "pArr[i] = " << pArr[i] << endl;
		cout << "&pArr[i][j] = ";
		for (int j = 0; j < x; j++)
		{
			cout << &pArr[i][j] << ", ";
		}
		cout << endl;
	}
}

bool askForExit(void)
{
	string exit;
	cout << "Would you like to try again (Y) or quit (N): ";
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

void displayArrValues(int **pArr, int x, int y)
{
	cout << "\nDisplay array's values" << endl;
	cout << "**pArr = " << **pArr << endl;
	for (int i = 0; i < y; i++)
	{
		cout << "*pArr[i] = " << *pArr[i] << endl;
		for (int j = 0; j < x; j++)
		{
			cout << "pArr[i][j] = " << pArr[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

void fillArr(int **pArr, int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			pArr[i][j] = i*j;
		}
	}
}

void freeArr(int **pArr, int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		delete[] pArr[i];
	}
	delete[] pArr;
}

int main()
{
	int x_size, y_size;
	int **pArr;

	while (1)
	{
		x_size = askForSize("X");
		y_size = askForSize("Y");
		pArr = makeArr(x_size, y_size);

		displayArrValues(pArr, x_size, y_size);
		displayArrAdress(pArr, x_size, y_size);
		fillArr(pArr, x_size, y_size);
		displayArrValues(pArr, x_size, y_size);
		displayArrAdress(pArr, x_size, y_size);
		freeArr(pArr, x_size, y_size);
		if (askForExit())
		{
			break;
		}
	}

	cout << "Press enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}