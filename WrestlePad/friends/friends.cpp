#include <iostream>
#include <string>
//#include <cstdlib>
using namespace std;

struct Friend
{
	string name;
	int numDaysAgo;
};

enum choice { ADD = 1, EDIT = 2, LISTUSER = 3, LISTDAYS = 4, QUIT = 5 };

int showMenu(void)
{
	int choice;
	while (true)
	{
		cout << "Choose from menu:" << endl;
		cout << "Add (1), Edit (2), List by user (3), List by days (4), Quit (5)" << endl;
		if ((cin >> choice) && (choice >= 1) && (choice <= 5))
		{
			//cout << "choice = " << choice << endl;
			break;
		}
		else
		{
			cout << "Wrong input, try again!" << endl;
			cin.clear();
			cin.ignore(1,'\n');
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return choice;
}

Friend *growArr(Friend *pArr, int size)
{
	Friend *newArr = new Friend[size * 2];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = pArr[i];
	}
	delete [] pArr;
	return newArr;
}

int checkNum(void)
{
	int days;
	while (1)
	{
		cout << "Enter number of days ago (1-1000): ";
		cin >> days;
		if (days > 0 && days < 1000)
		{
			break;
		}
		else
		{
			cout << "Wrong input, try again!" << endl;
		}
	}
	return days;
}

void addItem(Friend *pArr, int &size, int &itemCount)
{
	cout << "Enter friend's name: ";
	cin >> pArr[itemCount].name;
	pArr[itemCount].numDaysAgo = checkNum();
	itemCount += 1;
}

void displayOne(Friend *pArr, int iter)
{
	cout << iter << "# Name: " << pArr[iter].name << " | Days: " << pArr[iter].numDaysAgo << endl;
}

void editItem(Friend *pArr, int itemCount)
{
	string name;
	cout << "Enter friend's name: ";
	cin >> name;
	for (int i = 0; i < itemCount; i++)
	{
		if (name == pArr[i].name)
		{
			displayOne(pArr, i);
			cout << "Enter new name: ";
			cin >> pArr[i].name;
			pArr[i].numDaysAgo = checkNum();
			displayOne(pArr, i);
			break;
		}
		else if (i == itemCount - 1)
		{
			cout << "No match items!";
		}
	}
}

void list(Friend *pArr, int itemCount)
{
	for (int i = 0; i < itemCount; i++)
	{
		cout << i << " # Name: " << pArr[i].name << " | Days: " << pArr[i].numDaysAgo << endl;
	}
}

void listUser(Friend *pArr, int itemCount)
{
	for (int i = 0; i < itemCount; i++)
	{
		for (int j = i+1; j < itemCount; j++)
		{
			if (pArr[i].name > pArr[j].name)
			{
				Friend temp = pArr[i];
				pArr[i] = pArr[j];
				pArr[j] = temp;
			}
		}
	}
	cout << "\n User list sort by name" << endl;
	cout << "-------------------------" << endl;
	list(pArr, itemCount);
}

void listDays(Friend *pArr, int itemCount)
{
	for (int i = 0; i < itemCount; i++) // start sort
	{
		for (int j = i + 1; j < itemCount; j++)
		{
			if (pArr[i].numDaysAgo > pArr[j].numDaysAgo)
			{
				Friend temp = pArr[i];
				pArr[i] = pArr[j];
				pArr[j] = temp;
			}
		}
	} // end sort
	cout << "\n User list sort by day" << endl;
	cout << "------------------------" << endl;
	list(pArr, itemCount);
}

int main()
{
	int size = 2, itemCount = 0;
	bool exit = true;
	Friend *pArr = new Friend[size];

	do
	{
		switch (showMenu())
		{
		case ADD: 	if (itemCount == size - 1) {pArr = growArr(pArr, size); size *= 2;} addItem(pArr, size, itemCount); break;
		case EDIT: editItem(pArr, itemCount); break;
		case LISTUSER: listUser(pArr, itemCount); break;
		case LISTDAYS: listDays(pArr, itemCount); break;
		case QUIT: exit = false; break;
		}
	} while (exit);

	delete[] pArr;
	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}