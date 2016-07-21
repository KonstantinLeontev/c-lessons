#include <iostream>
#include "linkedlist.h"



Node *addNode(Node *pList, int num)
{
	Node *pNew = new Node;
	pNew->val = num;
	pNew->pNext = pList;
	return pNew;
}

void printList(Node *pList)
{
	Node *pCur = pList;
	while (pCur->pNext != NULL)
	{
		std::cout << pCur->val << std::endl;
		pCur = pCur->pNext;
	}
}
