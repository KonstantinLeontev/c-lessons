#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

struct Friends
{
	string name;
	int age;
	Friends* pNext;
};

Friends* friendList = NULL;

enum menuItems{QUIT, ADD, LISTNAME, FIND, SORT};

void incorrectInput(void)
{
	cout << "Incorrect input. Please try again." << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int menu(void)
{
	int choice;
	while (true)
	{
		cout << "Choose menu item: ADD (1), LIST BY NAME (2), FIND (3), SORT (4), QUIT (0): ";
		cin >> choice;
		if (choice >= 0 && choice <= 4)
		{
			break;
		}
		else
		{
			incorrectInput();
		}
	}
	return choice;
}

Friends* addFriend(Friends* friendList)
{
	Friends *pNew = new Friends;
	cout << "Please enter friend's name: ";
	cin >> pNew->name;
	while (true)
	{
		cout << "Please enter friend's age: ";
		cin >> pNew->age;
		if (pNew->age > 0 && pNew->age < 120)
		{
			break;
		}
		else
		{
			incorrectInput();
		}
	}
	pNew->pNext = friendList;
	return pNew;
}

void sortList(Friends *friendList)
{
	Friends *pCurr = friendList;
	Friends *pTemp = NULL;
	string tempName;
	int tempAge, count = 0;
	while (pCurr != NULL) // define the number of list items
	{
		pCurr = pCurr->pNext;
		count += 1;
	}
	pTemp = friendList; // drop pCurr to start
	for (int i = 0; i < count-1; i++)
	{
		pCurr = pTemp->pNext; // temp to point next item
		//cout << i << "# pCurr = " << pCurr << endl; // test line
		while (pCurr != NULL)
		{
			if (pCurr->name < pTemp->name)
			{
				tempName = pCurr->name;
				pCurr->name = pTemp->name;
				pTemp->name = tempName;
				tempAge = pCurr->age;
				pCurr->age = pTemp->age;
				pTemp->age = tempAge;
			}
			pCurr = pCurr->pNext;
		}
		pTemp = pTemp->pNext; // after NULL pCurr return to next position
	}
}

void showList(Friends* friendList)
{
	cout << "Friend list:" << endl;
	cout << "------------" << endl;
	Friends* pCurrent = friendList;
	while (pCurrent != NULL)
	{
		cout << "Name: " << pCurrent->name << ", age: " << pCurrent->age << endl;
		pCurrent = pCurrent->pNext;
	}
	cout << "------------" << endl;
	cout << endl;
}

void findByName(Friends *friendList)
{
	string someName;
	int count = 0;
	cout << "Enter the name you are looking for: ";
	cin >> someName;
	Friends *pCurr = friendList;
	while (pCurr != NULL)
	{
		if (pCurr->name == someName)
		{
			count += 1;
			cout << count << " was found: " << pCurr->name << ", " << pCurr->age << endl;
		}
		pCurr = pCurr->pNext;
	}
	if (count == 0)
	{
		cout << "No match items was found!" << endl;
	}
}


int main()
{
	bool exit = true;

	while (exit)
	{
		switch (menu())
		{
		case ADD: friendList = addFriend(friendList); break;
		case LISTNAME: showList(friendList); break;
		case FIND: findByName(friendList); break;
		case SORT: sortList(friendList); break;
		case QUIT: exit = false; break;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}