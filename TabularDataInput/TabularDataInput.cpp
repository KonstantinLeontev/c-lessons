#include <iostream>
#include <string>
#include <map>
using namespace std;

void incorrectInput(void)
{
	cout << "Incorrect input. Please try again." << endl;
	cin.clear();
	cin.ignore();
}

int main()
{
	char sepChar;
	map <string, string> contact;
	string name, email;
	int choice;

	while (1)
	{
		cout << "Enter the separator character (!@#$%^&*,;): ";
		cin >> sepChar;
		if (sepChar == '!' || sepChar == '@' || sepChar == '#' || sepChar == '$' || sepChar == '%' || sepChar == '^' || sepChar == '&' || sepChar == '*' || sepChar == ',' || sepChar == ';')
		{
			break;
		}
		else
		{
			incorrectInput();
		}
	}

	while (1)
	{
		cout << "Enter a name and email divided by choosen character: ";
		getline(cin, name, sepChar);
		getline(cin, email, '\n');
		contact[name] = email;
		cout << "Would you like to stop input (0) or continue (1)? ";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		else if (choice != 1)
		{
			incorrectInput();
		}
	}

	for (map <string, string>::iterator itr = contact.begin(); itr != contact.end(); ++itr)
	{
		cout << "Name: " << itr->first << ", email: " << itr->second << endl;
	}

	cout << "Good buy!" << endl;
	cin.ignore();
	cin.get();
}