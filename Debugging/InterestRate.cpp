#include <iostream>
using namespace std;

double computeInterest(double baseVal, double rate, int years)
{
	double finalMultiplier;
	for (int i = 0; i < years; i++)
	{
		finalMultiplier *= (1 + rate);
	}
	return baseVal*finalMultiplier;
}

int main()
{
	double rate, baseVal;
	int years;

	cout << "Please enter base value: ";
	cin >> baseVal;
	cout << "Enter an interest rate: ";
	cin >> rate;
	cout << "Enter the number of years to compound: ";
	cin >> years;

	cout << "After " << years << " you will have " << computeInterest(baseVal, rate, years) << " money" << endl;

	cout << "Press Enter to continue..." << endl;
	cin.ignore();
	return 0;
}