#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum menuItems {QUIT, ADD, PRINT, SORT};

class Comparable
{
public:
	int compare(Comparable &other);
	int score;
	string name;
	void swap(vector<Comparable*> &list, Comparable *right);
};

int Comparable::compare(Comparable &other)
{
	if (this->score == other.score)
	{
		return 0;
	}
	else if (this->score > other.score)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void Comparable::swap(vector<Comparable*> &list, Comparable *right)
{
	Comparable *pTemp = new Comparable;
	pTemp->score = this->score;
	pTemp->name = this->name;
	this->score = right->score;
	this->name = right->name;
	right->score = pTemp->score;
	right->name = pTemp->name;
	delete pTemp;
}

//void swap(vector<Comparable*> &list, Comparable *left, Comparable *right)
//{
//	Comparable *pTemp = new Comparable;
//	pTemp->score = left->score;
//	pTemp->name = left->name;
//	left->score = right->score;
//	left->name = right->name;
//	right->score = pTemp->score;
//	right->name = pTemp->name;
//	delete pTemp;
//}

void sort(vector<Comparable*> &list)
{
	cout << "list[0]->name = " << list[0]->name << endl;
	for (int i = 0; i < list.size() - 1; i++)
	{
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list[i]->compare(*list[j]) == 1)
			{
				list[i]->swap(list, list[j]);
				//swap(list, list[i], list[j]);
			}
			else if (list[i]->compare(*list[j]) == 0)
			{
				if (list[i]->name > list[j]->name)
				{
					list[i]->swap(list, list[j]);
					//swap(list, list[i], list[j]);
				}
			}
		}
	}

}

void incorrectInput(void)
{
	cout << "Incorrect input. Please try again!" << endl;
	cin.clear();
	cin.ignore();
}

int menu(void)
{
	int choice;
	while (1)
	{
		cout << "Choose from menu: ADD (1), PRINT (2), SORT (3), QUIT (0): ";
		cin >> choice;
		if (choice >= 0 && choice <= 3)
		{
			return choice;
		}
		else
		{
			incorrectInput();
		}
	}
}

void addPerson(vector<Comparable*> &list)
{
	Comparable *newPerson = new Comparable;
	cout << "Enter a name: ";
	cin >> newPerson->name;
	cout << "Enter a score: ";
	cin >> newPerson->score;
	list.push_back(newPerson);
	cout << "New person was added: " << newPerson->name << ", " << newPerson->score << endl;
}

void print(vector<Comparable*> &list)
{
	cout << "--- Start list ---" << endl;
	for (vector<Comparable*>::iterator itr = list.begin(); itr != list.end(); ++itr)
	{
		cout << "Name: " << (*itr)->name << " | Score: " << (*itr)->score << endl;
	}
	cout << "--- End list ---" << endl;
}

int main()
{
	vector<Comparable*> list;
	bool start = true;

	while (start)
	{
		switch (menu())
		{
		case ADD: addPerson(list); break;
		case PRINT: print(list); break;
		case SORT: sort(list); break;
		case QUIT: start = false; break;
		}
	}

	cout << "Again I tell you..." << endl;
	cin.ignore();
	cin.get();
	return 0;
}