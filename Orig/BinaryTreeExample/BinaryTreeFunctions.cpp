#include <iostream>
#include "bt_func.h"

using namespace std;

void incorrectInput(void)
{
	cout << "Incorrect input. Please try again." << endl;
	cin.clear();
	cin.ignore();
}

int menu(void)
{
	int num;
	while (1)
	{
		cout << "Choose from menu: ADD (1), FIND (2), LIST (3), DELETE (4) or QUIT (0): ";
		cin >> num;
		if (num >= 0 && num <= 4)
		{
			return num;
		}
		else
		{
			incorrectInput();
		}
	}
}

int askVal(void)
{
	int val;
	while (1)
	{
		cout << "Enter a value (0 - 1000): ";
		cin >> val;
		if (val >= 0 && val <= 1000)
		{
			return val;
		}
		else
		{
			incorrectInput();
		}
	}
}

Node * addNode(Node * pTree, int num)
{
	if (pTree == NULL)
	{
		Node *pNew = new Node;
		pNew->val = num;
		pNew->pLeft = NULL;
		pNew->pRight = NULL;
		return pNew;
	}
	if (pTree->val < num)
	{
		pTree->pRight = addNode(pTree->pRight, num);
	}
	else
	{
		pTree->pLeft = addNode(pTree->pLeft, num);
	}
	return pTree;
}

Node *findNode(Node * pTree, int num)
{
	if (pTree == NULL)
	{
		cout << "You node " << num << " wasn't found!" << endl;
		return NULL;
	}
	else if (pTree->val == num)
	{
		cout << "You node " << num << " was found!" << endl;
		return pTree;
	}
	else if (pTree->val < num)
	{
		return findNode(pTree->pRight, num);
	}
	else
	{
		return findNode(pTree->pLeft, num);
	}		
}

void list(Node * pTree)
{
	if (pTree != NULL)
	{
		cout << pTree->val << endl;
	}
	if (pTree->pLeft != NULL)
	{
		//cout << pTree->pLeft << endl;
		list(pTree->pLeft);
	}
	if (pTree->pRight != NULL)
	{
		//cout << pTree->pRight << endl;
		list(pTree->pRight);
	}
}

Node *findMax(Node *pTree)
{
	if (pTree == NULL)
	{
		return NULL;
	}
	if (pTree->pRight == NULL)
	{
		return pTree;
	}
	return findMax(pTree->pRight);
}

Node *removeMax(Node *pTree, Node *pMax)
{
	if (pTree == NULL)
	{
		return NULL;
	}
	if (pTree == pMax)
	{
		return pMax->pLeft;
	}
	else
	{
		pTree->pRight = removeMax(pTree->pRight, pMax);
		return pTree;
	}
}

Node *deleteNode(Node * pTree, int num)
{
	if (pTree == NULL)
	{
		return NULL;
	}
	if (pTree->val == num)
	{
		if (pTree->pLeft == NULL)
		{
			Node *pTreeNew = pTree->pRight;
			delete pTree;
			return pTreeNew;
		}
		if (pTree->pRight == NULL)
		{
			Node *pTreeNew = pTree->pLeft;
			delete pTree;
			return pTreeNew;
		}
		Node *pMax = findMax(pTree->pLeft);
		pMax->pLeft = removeMax(pTree->pLeft, pMax);
		pMax->pRight = pTree->pRight;
		delete pTree;
		return pMax;
		
	}
	else if (pTree->val < num)
	{
		pTree->pRight = deleteNode(pTree->pRight, num);
	}
	else
	{
		pTree->pLeft = deleteNode(pTree->pLeft, num);
	}
	return pTree;
}
