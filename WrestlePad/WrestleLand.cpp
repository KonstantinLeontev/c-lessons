#include <iostream>
#include <string>
//#include <ctime>
//#include <cstdlib>
using namespace std;

struct GamePlayer
{
	string name;
	int score[10];
};

void showMenu(void)
{
	int choice;
	cout << "\nChoose from menu: " << endl;
	cout << "Add User (1) | Get Highest User Score (2) | List All User Scores (3) | List All Scores (4) | List All Users (5) | Quit (6)" << endl;
}

int addUser(GamePlayer allUsers[], int size, int counter)
{
	if (counter < size)
	{
		string stop;
		int inputScore;
		cout << "Enter the user name: ";
		cin >> allUsers[counter].name;
		for (int i=0; i<10; i++)
		{
			cout << "Enter the user score (1 - 100000): ";
			cin >> inputScore;
			if (inputScore >= 1 && inputScore <= 100000)
			{
				allUsers[counter].score[i] = inputScore;
			}
			else
			{
				cout << "Wrong input!" << endl;
				continue;
			}
				
			cout << "Would you like to add another one? Y or N: ";
			cin >> stop;
			if (stop == "y" || stop == "Y")
			{
				continue;
			}
			else if (stop == "n" || stop == "N")
			{
				break;
			}
			else
			{
				cout << "Wrong input, try again!" << endl;
			}
		}
		counter += 1;
	}
	else
	{
		cout << "Max size of database was reached!" << endl;
	}
	return counter;
}


void getUserScores(GamePlayer allUsers[], int size, int counter, int choice)
{
	string input;
	cout << "Enter the user's name: ";
	cin >> input;
	for (int i = 0; i < counter; i++)
	{
		if (allUsers[i].name == input)
		{
			for (int j = 0; j < 10; j++) // start sort score's entries
			{
				for (int k = j + 1; k < 10; k++)
				{
					if (allUsers[i].score[j] < allUsers[i].score[k])
					{
						int temp = allUsers[i].score[j];
						allUsers[i].score[j] = allUsers[i].score[k];
						allUsers[i].score[k] = temp;
					}
				}
			} // end sort
			if (choice == 2) // display only highest
			{
				cout << allUsers[i].name << "'s highest score is: " << allUsers[i].score[0] << endl; // display highest
			}
			else if (choice == 3) // display all user scores
			{
				cout << "All " << allUsers[i].name << "'s scores: " << endl;
				for (int j = 0; j < 10; j++)
				{
					if (allUsers[i].score[j] > 0)
					{
						cout << allUsers[i].score[j] << endl;
					}
				}
			}
			break; // exit from loop
		} // end if for match result
		else if (i == counter - 1) // for incorrect names
		{
			cout << "No match results! You should input correct name." << endl;
		}
	} // end for
}

void listAllScores(GamePlayer allUsers[], int size, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		cout << i+1 << "# " << allUsers[i].name << ": " << endl;
		for (int j = 0; j < 10; j++)
		{
			if (allUsers[i].score[j] >= 1 && allUsers[i].score[j] <= 100000)
			{
				cout << allUsers[i].score[j] << endl;
			}
		}
		cout << "-----" << endl;
	}
}

void listAllUsers(GamePlayer allUsers[], int size, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		cout << i + 1 << "# " << allUsers[i].name << endl;
	}
}


int main()
{
	enum menuChoice { ADDUSER = 1, HIGHEST = 2, ALLUSERSCORES = 3, ALLSCORES = 4, USERLIST = 5, QUIT = 6 };
	int choice;
	int counter = 0;
	bool exit = false;
	const int size = 100;
	GamePlayer allUsers[size];

	do
	{
		showMenu();
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case ADDUSER: counter = addUser(allUsers, size, counter); break;
		case HIGHEST: getUserScores(allUsers, size, counter, HIGHEST); break;
		case ALLUSERSCORES: getUserScores(allUsers, size, counter, ALLUSERSCORES); break;
		case ALLSCORES: listAllScores(allUsers, size, counter); break;
		case USERLIST: listAllUsers(allUsers, size, counter); break;
		case QUIT: exit = true; break;
		default: cout << "Wrong input, try again!" << endl; break;
		}
	} while (!exit);

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}