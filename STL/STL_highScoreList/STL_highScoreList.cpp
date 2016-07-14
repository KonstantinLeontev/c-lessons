#include <vector>
#include <iostream>
#include <algorithm>
//#include <string>
using namespace std;

enum menuItems {QUIT, ADD, LIST};

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
		cout << "Choose from menu: ADD (1), LIST (2) or QUIT (0): ";
		cin >> choice;
		if (choice >= 0 && choice <= 2)
		{
			return choice;
		}
		else
		{
			incorrectInput();
		}
	}
}

void addScore(vector<int> &scoreList)
{
	int score;

	while (1)
	{
		cout << "Enter new score to the list (0 - 10000): ";
		cin >> score;
		if (score >= 0 && score <= 10000)
		{
			scoreList.push_back(score);
			cout << "Score " << score << " was added" << endl;
			sort(scoreList.begin(), scoreList.end());
			break;
		}
		else
		{
			incorrectInput();
		}
	}
}

void listScore(vector<int> scoreList)
{
	int counter = 1;
	cout << "--- Start list ---" << endl;
	for (vector<int>::iterator itr = scoreList.begin(); itr != scoreList.end(); ++itr)
	{
		if (*itr == 0)
		{
			continue;
		}
		else
		{
			cout << counter << ": " << *itr << endl;
			counter++;
		}
	}
	cout << "--- End list ---" << endl;
}

int main()
{
	vector<int> scoreList(10);
	bool start = true;
	
	while (start)
	{
		switch (menu())
		{
		case ADD: addScore(scoreList); break;
		case LIST: listScore(scoreList); break;
		case QUIT: start = false; break;
		}
	}
		
	cout << "Good buy!" << endl;
	cin.ignore();
	cin.get();
	return 0;
}