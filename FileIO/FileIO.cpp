#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
	fstream file("highscore.txt", ios::in | ios::out);
	if (!file.is_open())
	{
		cout << "Could not open file!" << '\n';
		return 0;
	}

	int newHighScore;
	cout << "Enter new high score: ";
	cin >> newHighScore;
	streampos preScorePos = file.tellg();
	int curScore;
	while (file >> curScore)
	{
		if (curScore > newHighScore)
		{
			break;
		}
		preScorePos = file.tellg();
	}
	if (file.fail() && !file.eof())
	{
		cout << "Bad score/read--exiting";
		return 0;
	}
	file.clear();
	file.seekg(preScorePos);
	vector<int> scores;
	while (file >> curScore)
	{
		scores.push_back(curScore);
	}
	if (!file.eof())
	{
		cout << "Bad score/read--exiting";
		return 0;
	}
	file.clear();
	file.seekp(preScorePos);
	if (preScorePos)
	{
		file << endl;
	}
	file << newHighScore << endl;
	for (vector<int>::iterator itr = scores.begin(); itr < scores.end(); ++itr)
	{
		file << *itr << endl;
	}
	cout << "Again I tell you..." << endl;
	//cin.ignore();
	//cin.get();
	return 0;
}