#include <iostream>
#include <string>
using namespace std;

struct book
{
	string name;
	string email;
	book *pLeft;
	book *pRight;
};

enum menuItems {QUIT, ADD, FIND, EDIT, REMOVE};

void incorrectInput(void)
{
	cout << "Incorrect input. Please try again." << endl;
	cin.clear();
	cin.ignore();
}

int menu(void)
{
	int choice;
	while (1)
	{
		cout << "Choose from menu: ADD (1), FIND (2), EDIT (3), REMOVE (4) or QUIT (0): ";
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

string askName(string action)
{
	string newName;
	cout << action << " contact: " << endl;
	cout << "Enter a name: ";
	cin >> newName;
	return newName;
}

book *addContact(book *pBook, string newName)
{
	
	if (pBook == NULL)
	{
		book *pNew = new book;
		pNew->pRight = NULL;
		pNew->pLeft = NULL;
		pNew->name = newName;
		cout << "Enter an email: ";
		cin >> pNew->email;
		cout << "New contact was added!" << endl;
		return pNew;
	}
	if (newName < pBook->name)
	{
		pBook->pLeft = addContact(pBook->pLeft, newName);
	}
	else if (newName > pBook->name)
	{
		pBook->pRight = addContact(pBook->pRight, newName);
	}
	return pBook;
}
book *findContact(book *pBook, string newName)
{
	if (pBook == NULL)
	{
		cout << "Book is empty!" << endl;
		return NULL;
	}
	else if (newName == pBook->name)
	{
		return pBook;
	}
	else if (newName < pBook->name)
	{
		return findContact(pBook->pLeft, newName);
	}
	else
	{
		return findContact(pBook->pRight, newName);
	}
}

void displayContact(book *pBook)
{
	cout << "--- Search result ---" << endl;
	cout << "Name: " << pBook->name << endl;
	cout << "Email: " << pBook->email << endl;
}

void editContact(book *pBook)
{
	displayContact(pBook);
	if (pBook == NULL)
	{
		cout << "Not found!" << endl;
	}
	else
	{
		cout << "Enter new email: ";
		cin >> pBook->email;
		cout << "Adress was updated!" << endl;
	}
}

book *findMax(book *pBook)
{
	if (pBook == NULL)
	{
		return NULL;
	}
	if (pBook->pRight == NULL)
	{
		return pBook;
	}
	else
	{
		return findMax(pBook->pRight);
	}
}

book *removeMax(book *pBook, book *pMax)
{
	if (pBook == NULL)
	{
		return NULL;
	}
	if (pBook == pMax)
	{
		return pMax->pLeft;
	}
	pBook->pRight = removeMax(pBook->pRight, pMax);
	return pBook;

}

book *removeContact(book *pBook, string newName)
{
	if (pBook == NULL)
	{
		cout << "Book is empty!" << endl;
		return NULL;
	}
	if (newName == pBook->name)
	{
		if (pBook->pLeft == NULL)
		{
			book *pNew = pBook->pRight;
			delete pBook;
			return pNew;
		}
		else if (pBook->pRight == NULL)
		{
			book *pNew = pBook->pLeft;
			delete pBook;
			return pNew;
		}
		book *pMax = findMax(pBook->pLeft);
		pMax->pLeft = removeMax(pBook, pMax);
		pMax->pRight = pBook->pRight;
		delete pBook;
		return pMax;
	}
	else if (newName < pBook->name)
	{
		return removeContact(pBook->pLeft, newName);
	}
	else
	{
		return removeContact(pBook->pRight, newName);
	}
}

void cleanBook(book *pBook)
{

}

int main()
{
	bool start = true;
	book *pBook = NULL;

	while (start)
	{
		switch (menu())
		{
		case ADD: pBook = addContact(pBook, askName("Add")); break;
		case FIND: displayContact(findContact(pBook, askName("Find"))); break;
		case EDIT: editContact(findContact(pBook, askName("Edit"))); break;
		case REMOVE: pBook = removeContact(pBook, askName("Remove")); break;
		case QUIT: cleanBook(pBook); start = false; break;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}