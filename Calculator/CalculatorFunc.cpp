#include <iostream>
#include "CalcFunDef.h"

using namespace std;

double calcSum(double first, double second)
{
	return first + second;
}

double calcSub(double first, double second)
{
	return first - second;
}

double calcMult(double first, double second)
{
	return first * second;
}

double calcDiv(double first, double second)
{
	return first / second;
}

void incorrectInput(void)
{
	cout << "Incorrect input. Please try again" << endl;
	cin.clear();
	cin.ignore();
}

double enterValue(string name)
{
	double num;
	while (1)
	{
		cout << "Enter " << name << " value (-1000000000 to 100000000): ";
		cin >> num;
		{
			if (num >= -1000000000 && num <= 1000000000)
			{
				return num;
			}
			else
			{
				incorrectInput();
			}
		}
	}
}