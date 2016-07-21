#include <iostream>
#include "bt_func.h"

using namespace std;

int main()
{
	bool start = true;
	Node *pTree = NULL;
	int num;

	while (start)
	{
		switch (menu())
		{
		case ADD: num = askVal(); pTree = addNode(pTree, num); break;
		case FIND: num = askVal(); findNode(pTree, num); break;
		case LIST: list(pTree); break;
		case DELETE: num = askVal(); pTree = deleteNode(pTree, num); cout << "Node " << num << " was deleted!" << endl;  break;
		case QUIT: start = false; break;
		}
	}

	cout << "Again I tell you..." << endl;
	cin.ignore();
	cin.get();
}