#include <iostream>
#include <string>
using namespace std;

int findInArr(string arr[], string word, int index)
{
	if (arr[index] == word)
	{
		cout << "Test index in arr[index] = " << index << endl;
		return index;
	}
	else if (arr[index] != word && index < 5)
	{
		cout << "Test index in if = " << index << endl;
		findInArr(arr, word, index + 1);
	}
	/*else if (index == 5)
	{
		cout << "Test index = " << index << endl;
		return -1;
	}*/
}

int findNumArr(int arr[], int num, int index)
{
	if (arr[index] == num)
	{
		cout << "Test index in arr[index] = " << index << endl;
		return index;
	}
	else if (index == 5)
	{
		return -1;
	}
	else if (arr[index] != num && index < 5)
	{
		cout << "Test index in if = " << index << endl;
		findNumArr(arr, num, index + 1);
	}

}

int main()
{
	int index = 0;
	string word;
	int num;
	string arr[] = { "mom", "dad", "dother", "son", "uncle", "aunt" };
	int arrNum[] = { 10, 20, 30, 40, 50, 60 };
	
	cout << "Enter a word: ";
	cin >> word;
	index = findInArr(arr, word, index);
	cout << "Word " << word << " has index = " << index << endl;

	index = 0;
	cout << "Enter a number: ";
	cin >> num;
	index = findNumArr(arrNum, num, index);
	cout << "Number " << num << " has index = " << index << endl;

	cout << "Press  Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}