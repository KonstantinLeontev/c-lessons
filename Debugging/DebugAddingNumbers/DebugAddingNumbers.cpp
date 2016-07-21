#include <iostream>
using namespace std;

int sumValues(int *values, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += values[i];
	}
	return sum;
}

int main()
{
	int size;
	cout << "Enter a size: ";
	cin >> size;
	int *values = new int[size];
	int i = 0;
	while (i < size)
	{
		cout << "Enter value to add: ";
		cin >> values[i++];
		//i++;
	}
	cout << values[0] << endl;
	cout << values[1] << endl;
	cout << values[2] << endl;
	cout << values[3] << endl;
	cout << "Total sum is: " << sumValues(values, size) << endl;

	cin.ignore();
	cin.get();
	return 0;
}