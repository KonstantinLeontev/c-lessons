#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	vector<int> someVector(10);

	for (int i = 0; i < 10; i++)
	{
		someVector[i] = i*i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "someVector[" << i << "] = " << someVector[i] << endl;
	}

	cout << "someVector.size() = " << someVector.size() << endl;
	someVector.push_back(22);
	cout << "Now someVector.size = " << someVector.size() << endl;
	cout << "someVector[10] = " << someVector[10] << endl;

	map<string, string> email;

	email["Konstantin"] = "leokon@bk.ru";
	email["Nastya"] = "aleo.gmail.com";

	cout << "Size of map before erase: " << email.size() << endl;
	email.erase("Konstantin");
	cout << "Size of map after erase: " << email.size() << endl;

	cout << "Adress Konstantin: " << email["Konstantin"] << endl;
	cout << "Adress Nastya: " << email["Nastya"] << endl;

	map<string, string>::iterator itrNew = email.find("Nastya");
	if (itrNew != email.end())
	{
		cout << "How nice to see Nastya again! Her email is: " << itrNew->second << endl;
	}

	/*email.erase("Nastya");
	cout << "Size of map after erase Nastya: " << email.size() << endl;
	email.clear();
	cout << "Size of map after clear: " << email.size() << endl;*/

	vector<int>::iterator itr = someVector.begin();
	cout << "*itr = " << *itr << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "i = " << i << ", *itr = " << *itr << endl;
		itr++;
	}

	for (vector<int>::iterator itr = someVector.begin(); itr != someVector.end(); itr++)
	{
		cout << " *itr = " << *itr << endl;
	}



	if (email.empty())
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		cout << "List is not empty" << endl;
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}