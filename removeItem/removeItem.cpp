#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

enum menuItems {QUIT, ADD, DELETE, LIST};

struct FamilyMember
{
	string name;
	int age;
	FamilyMember* pNext;
};

FamilyMember* family = NULL;

void incorrectInput(void)
{
	cout << "Wrong input. Please try again!" << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

FamilyMember* addMember(FamilyMember* family)
{
	FamilyMember* member = new FamilyMember;
	cout << "Enter member's name: ";
	cin >> member->name;
	while (true)
	{
		cout << "Enter member's age: ";
		cin >> member->age;
		if (member->age > 0 && member->age < 120)
		{
			break;
		}
		else
		{
			incorrectInput();
		}
	}
	member->pNext = family;
	return member;
}

int menu(void)
{
	int choice;
	while (true)
	{
		cout << "Choose from menu: ADD (1), DELETE (2), LIST (3), QUIT (0): ";
		cin >> choice;
		if (choice >= 0 && choice <= 3)
		{
			return choice;
			break;
		}
		else
		{
			incorrectInput();
		}
	}
}

FamilyMember* deleteMember(FamilyMember* family)
{
	string name;
	FamilyMember *pCurrent = family;
	FamilyMember *pPrevious = NULL;
	cout << "Please enter a name: ";
	cin >> name;
	while(pCurrent != NULL)
	{
		if (name != pCurrent->name)
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}			
		else if (name == pCurrent->name)
		{
			if (pPrevious == NULL) // if we need to delete first item
			{
				family = pCurrent->pNext;
			}
			else // for all next items
			{
				pPrevious->pNext = pCurrent->pNext;
			}
			cout << "Member was deleted" << endl;
			delete pCurrent;
			break;
		}
		else if (pCurrent == NULL)
		{
			cout << "There is no match item!" << endl;
		}
	}
	return family;
}

void listFamily(FamilyMember *family)
{
	FamilyMember *pCurrent = family;
	cout << "All family members: " << endl;
	while (pCurrent != NULL)
	{
		cout << "Name: " << pCurrent->name << " age: " << pCurrent->age << endl;
		pCurrent = pCurrent->pNext;
	}
	cout << endl;
}

int main()
{
	bool exit = true;

	while (exit)
	{
		switch (menu())
		{
		case ADD: family = addMember(family); break;
		case DELETE: family = deleteMember(family); break;
		case LIST: listFamily(family); break;
		case QUIT: exit = false; break;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}