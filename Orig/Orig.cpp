#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
	Node *pList = NULL;
	int value;

	for (int i = 0; i < 10; i++)
	{
		cout << "Enter value for new node: ";
		cin >> value;
		pList = addNode(pList, value);
	}

	printList(pList);

	cout << "Again I tell you..." << endl;
	cin.ignore();
	cin.get();
	return 0;
}