#include <iostream>
using namespace std;

void reversDisplay(int arr[], int i)
{

	if (arr[i] < 9)
	{
		reversDisplay(arr, i+1);
	}
	cout << arr[i] << ", ";
}

int main()
{
	int i = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9 };

	reversDisplay(arr, i);
	//cout << reversDisplay(arr) << endl;

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}