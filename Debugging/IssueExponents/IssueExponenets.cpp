#include <iostream>
using namespace std;

int exponent(int base, int exp)
{
	int running_value = base;
	for (int i = 0; i < exp; i++)
	{
		running_value *= base;
	}
	return running_value;
}

int main()
{
	int base;
	int exp;

	cout << "Enter a base value: ";
	cin >> base;
	cout << "Enter an exponent: ";
	cin >> exp;
	cout << base << " exp " << exp << " = " << exponent(exp, base);

	cin.ignore();
	cin.get();
	return 0;
}