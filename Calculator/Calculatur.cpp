#include <iostream>
#include "calcFunDef.h"
using namespace std;

int main()
{
	double first, second, result, exit;
	string calcOperator;

	while (1)
	{
		first = enterValue("first");
		while (1)
		{
			cout << "Enter an operator ('+', '-', '*', '/'): ";
			cin >> calcOperator;
			if (calcOperator == "+" || calcOperator == "-" || calcOperator == "*" || calcOperator == "/")
			{
				break;
			}
			else
			{
				incorrectInput();
			}
		}	
		second = enterValue("second");
		if (calcOperator == "+")
		{
			result = calcSum(first, second);
		}
		else if (calcOperator == "-")
		{
			result = calcSub(first, second);
		}
		else if (calcOperator == "*")
		{
			result = calcMult(first, second);
		}
		else
		{
			result = calcDiv(first, second);
		}
		cout << first << " " << calcOperator << " " << second << " = " << result << endl;
		cout << "Do you want to exit (0) or continue (1)? ";
		cin >> exit;
		if (exit == 0)
		{
			break;
		}
		else if (exit == 1)
		{
			continue;
		}
		else
		{
			incorrectInput();
		}
	}

	cout << "Again I tell you..." << endl;
	cin.ignore();
	cin.get();
	return 0;
}