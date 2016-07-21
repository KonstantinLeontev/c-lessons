#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *pNext = NULL;
};

int main()
{
	int val;
	Node *pHead = NULL;
	while (1)
	{
		cout << "Enter a value, 0 to replay: " << endl;
		cin >> val;
		if (val == 0)
		{
			break;
		}
		if (pHead == NULL)
		{ 
			pHead = new Node;
			pHead->val = val;
		}
		else
		{
			Node *pTemp = new Node;
			pTemp->pNext = pHead;
			pTemp->val = val;
			pHead = pTemp;
		}
		
	}
	Node *pItr = pHead;
	while (pItr != NULL)
	{
		cout << pItr->val << endl;
		pItr = pItr->pNext;
		
	}
	delete pItr;

	cout << "Press Enter to continue..." << endl;
	cin.ignore();
	cin.get();
	return 0;
}