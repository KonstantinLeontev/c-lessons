#include <iostream>
#include <map>
#include <string>
using namespace std;

enum menuItems {QUIT, ADD, FIND, EDIT, REMOVE, LIST};

void incorrectInput(void)
{
	cout << "Incorrect input!. Please try again." << endl;
	cin.clear();
	cin.ignore();
}

int menu(void)
{
	int choice;
	while (1)
	{
		cout << "Choose from menu: ADD (1), FIND (2), EDIT (3), REMOVE (4), LIST (5) or QUIT (0): ";
		cin >> choice;
		if (choice >= 0 && choice <= 5)
		{
			return choice;
		}
		else
		{
			incorrectInput();
		}
	}
}

bool checkName(map<string, string> &contact, string name)
{
	map<string, string>::iterator itr = contact.find(name);
	if (itr != contact.end())
	{
		return true; // contact already in the book
	}
	else
	{
		return false; // contact not found
	}
}

 void addContact(map<string, string> &contact)
{
	 string name, adress;
	 while (1)
	 {
		 cout << "Enter a name: ";
		 cin >> name;
		 if (!checkName(contact, name))
		 {
			 cout << "Enter an adress: ";
			 cin >> adress;
			 contact[name] = adress;
			 cout << "Contact " << name << ": " << contact[name] << " was added" << endl;
			 break;
		 }
		 else
		 {
			 cout << "This name already in use!" << endl;
		 }
	 }
}

void findContact(map<string, string> &contact)
{
	string name;
	cout << "Enter a name: ";
	cin >> name;
	map<string, string>::iterator itr = contact.find(name);
	if (itr != contact.end())
	{
		cout << "Search result: " << endl;
		cout << "Name: " << itr->first << ", email: " << itr->second << endl;
	}
	else
	{
		cout << "Contact not found!" << endl;
	}
}

void editContact(map<string, string> &contact)
{
	string name, choice;
	cout << "Enter a name: " << endl;
	cin >> name;
	map<string, string>::iterator itr = contact.find(name);
	if (itr != contact.end())
	{
		while (1)
		{
			cout << "Do you want to change the name? (Y) or (N): ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				contact.erase(name);
				addContact(contact);
				break;
			}
			else if (choice == "n" || choice == "N")
			{
				cout << "Enter new email: ";
				cin >> contact[name];
				cout << "Email is changed. New email for " << name << ": " << contact[name] << endl;
				break;
			}
			else
			{
				incorrectInput();
			}
		}		
	}
	else
	{
		cout << "Contact " << name << " not found!" << endl;
	}
}

void removeContact(map<string, string> &contact)
{
	string name;
	cout << "Enter the name to remove: ";
	cin >> name;
	map<string, string>::const_iterator itr = contact.find(name);
	if (itr != contact.end())
	{
		contact.erase(name);
		cout << "Contact " << name << " was removed!" << endl;
	}
	else
	{
		cout << "Contact " << name << " not found!" << endl;
	}
}

void list(map<string, string> contact)
{
	cout << "--- PhoneBook ---" << endl;
	cout << "-----------------" << endl;
	for (map<string, string>::iterator itr = contact.begin(); itr != contact.end(); ++itr)
	{
		cout << "Name: " << itr->first << ", email: " << itr->second << endl;
	}
	cout << "---- the end ----" << endl;
}

int main()
{
	map<string, string> contact;
	bool start = true;

	while (start)
	{
		switch (menu())
		{
		case ADD: addContact(contact); break;
		case FIND: findContact(contact); break;
		case EDIT: editContact(contact); break;
		case REMOVE: removeContact(contact); break;
		case LIST: list(contact); break;
		case QUIT: start = false; break;
		}
	}


	cout << "Good buy!" << endl;
	cin.ignore();
	cin.get();
	return 0;
}