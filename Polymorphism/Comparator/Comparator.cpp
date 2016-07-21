#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum menuItems {QUIT, ADD, PRINT, SORT, REVERSE};

class Comparator
{
public:
	int compareCase(const string &lhs,const string &rhs);
	int compareCaseSens(const string &lhs, const string &rhs);
	string name;
	int score;
	void swap(Comparator *other);

private:
	string stringToLower(const string str);
};

void Comparator::swap(Comparator *other)
{
	Comparator *pTemp = new Comparator;
	pTemp->name = this->name;
	pTemp->score = this->score;
	this->name = other->name;
	this->score = other->score;
	other->name = pTemp->name;
	other->score = pTemp->score;
	delete pTemp;
}

void sort(vector<Comparator*> &list)
{
	for (int i = 0; i < list.size() - 1; i++)
	{
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list[i]->compareCase(list[i]->name, list[j]->name) == 1)
			{
				list[i]->swap(list[j]);
			}
		}
	}
	cout << "List was sorted!" << endl;
}

void sortReverse(vector<Comparator*> &list)
{
	for (int i = 0; i < list.size() - 1; i++)
	{
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list[i]->compareCaseSens(list[i]->name, list[j]->name) == -1)
			{
				list[i]->swap(list[j]);
			}
		}
	}
	cout << "List was sorted!" << endl;
}

int Comparator::compareCase(const string &lhs, const string &rhs)
{
	string left = stringToLower(lhs);
	string right = stringToLower(rhs);
	if (left == right)
	{
		return 0;
	}
	else if (left > right)
	{
		return 1;
	}
	else if (left < right)
	{
		return -1;
	}
}

int Comparator::compareCaseSens(const string &lhs, const string &rhs)
{
	if (lhs == rhs)
	{
		return 0;
	}
	else if (lhs > rhs)
	{
		return 1;
	}
	else if (lhs < rhs)
	{
		return -1;
	}
}

string Comparator::stringToLower(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
	}
	return str;
}

void wrongInput(void)
{
	cout << "Incorrect input. Please try again." << endl;
	cin.clear();
	cin.ignore();
}

void addPerson(vector<Comparator*> &list)
{
	Comparator *pNew = new Comparator;
	cout << "Enter a name: ";
	cin >> pNew->name;
	cout << "Enter a score: ";
	cin >> pNew->score;
	cout << "Person with name: " << pNew->name << ", score: " << pNew->score << " was added!" << endl;
	list.push_back(pNew);
}

void print(vector<Comparator*> &list)
{
	cout << "--- Start list ---" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << "Name: " << list[i]->name << " | score: " << list[i]->score << endl;
	}
	cout << "--- End list ---" << endl;
}

int menu(void)
{
	int choice;
	while (1)
	{
		cout << "Choose from menu: ADD (1), PRINT (2), SORT (3), REVERSE (4), QUIT (0): ";
		cin >> choice;
		{
			if (choice >= 0 && choice <= 4)
			{
				return choice;
			}
			else
			{
				wrongInput();
			}
		}
	}
}

int main()
{
	vector<Comparator*> list;
	bool start = true;

	while (start)
	{
		switch (menu())
		{
		case ADD: addPerson(list); break;
		case PRINT: print(list); break;
		case SORT: sort(list); break;
		case REVERSE: sortReverse(list); break;
		case QUIT: start = false; break;
		}
	}

	cout << "Again I tell you..." << endl;
	cin.ignore();
	cin.get();
	return 0;
}