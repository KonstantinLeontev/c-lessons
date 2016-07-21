#include <iostream>

using namespace std;

int fibonacci(int n)
{
	if (n < 0)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main()
{
	int n, exit;
	while (1)
	{
		cout << "Enter the number to compute fibonacci for: " << endl;
		cin >> n;
		cout << fibonacci(n) << endl;
		cout << "Exit? (1) or (0)";
		cin >> exit;
		if (exit == 1)
		{
			break;
		}
	}

	cin.ignore();
	cin.get();
	return 0;
}