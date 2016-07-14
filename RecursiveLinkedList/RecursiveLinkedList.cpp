#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

struct Task
{
	string title;
	int time;
	Task *pNext;
};

Task *pList = NULL;

enum menuItems {QUIT, ADD, REMOVE, LIST, ADDREC};

void incorrectInput()
{
	cout << "Incorrect input. Please try again." << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Task *addTask(Task *pList)
{
	Task *pNew = new Task;
	cout << "Test pNew = " << pNew << endl; // test line
	cout << "Enter a title: ";
	cin >> pNew->title;
	while (1)
	{
		cout << "Enter a task time: ";
		cin >> pNew->time;
		if (pNew->time >= 0 && pNew->time <= 24) break;
		else incorrectInput();
	}
	pNew->pNext = pList;
	cout << "Test pNew->pNext = " << pNew->pNext << endl; // test line
	return pNew;
}

string findTask(Task *pList)
{
	string item;
	cout << "Enter the name of list item or 0 to exit: ";
	cin >> item;
	return item;
}

void removeTask(Task *pList, string item)
{
	cout << "Test pList in top = " << pList << endl; // test line
	Task *pPrev = NULL;
	pPrev = pList;
		if (item != pList->title && pList->pNext != NULL)
		{
			removeTask(pList->pNext, item);
		}
		if (item == pList->title)
		{
			if (pPrev == NULL) // for first item
			{
				pList = pList->pNext;
			}
			else // for others
			{
				pPrev->pNext = pList->pNext;
			}
			cout << "Task was removed!" << endl;
		}
		else
		{
			cout << "No match items!" << endl;
		}
}

Task *addTaskRecursive(Task *pList)
{
	if (pList != NULL && pList->pNext != NULL)
	{
		cout << "Test pList in if = " << pList << endl; // test line
		addTaskRecursive(pList->pNext);
	}
	else if (pList == NULL || pList->pNext == NULL)
	{
		Task *pNew = new Task;
		cout << "Enter a title: ";
		cin >> pNew->title;
		while (1)
		{
			cout << "Enter a task time: ";
			cin >> pNew->time;
			if (pNew->time >= 0 && pNew->time <= 24) break;
			else incorrectInput();
		}
		if (pList != NULL && pList->pNext == NULL)
		{
			pList->pNext = pNew;
			pNew->pNext = NULL;
			return pList;
		}
		else
		{
			pList = pNew;
			pList->pNext = NULL;
			return pList;
		}
		
	}
}

void listItems(Task *pList)
{
	Task *pCurr = pList;
	cout << "\nList of all tasks: " << endl;
	cout << "---------------------" << endl;
	while (pCurr != NULL)
	{
		cout << "Task: " << pCurr->title << ", time: " << pCurr->time << endl;
		pCurr = pCurr->pNext;
	}
	cout << "---------------------" << endl;
	cout << "End of the list.\n" << endl;
}

int menu(void)
{
	int choice;
	while (1)
	{
		cout << "Choose from menu: ADD (1), REMOVE (2), LIST (3), ADDRECURSIVE (4), QUIT (0)";
		cin >> choice;
		if (choice >= 0 && choice <= 4)
		{
			return choice;
		}
		else
		{
			incorrectInput();
		}
	}
}

int main()
{
	bool exit = true;
	string note;

	while (exit)
	{
		switch (menu())
		{
		case ADD: pList = addTask(pList); 	cout << "Test pList = " << pList << endl; break;
		case REMOVE: note = findTask(pList); removeTask(pList, note); break;
		case LIST: listItems(pList); break;
		case ADDREC: pList = addTaskRecursive(pList); break;
		case QUIT: exit = false; break;
		}		 
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
 }