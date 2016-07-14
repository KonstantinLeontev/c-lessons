#include <iostream>
using namespace std;

struct node
{
	int value;
	node *pLeft;
	node *pRight;
};

node *insert(node *pTree, int key)
{
	if (pTree == NULL)
	{
		node *pNewTree = new node;
		pNewTree->pLeft = NULL;
		pNewTree->pLeft = NULL;
		pNewTree->value = key;
		return pNewTree;
	}
	if (key < pTree->pLeft->value)
	{
		pTree->pLeft = insert(pTree->pLeft, key);
	}
	else
	{
		pTree->pRight = insert(pTree->pRight, key);
	}
	return pTree;
}

node* search(node *pTree, int key)
{
	// if we reach the empty tree, clearly it's not here!
	if (pTree == NULL)
	{
		return NULL;
	}
	// if we find the key, we're done!
	else if (key == pTree->value)
	{
		return pTree;
	}
	// otherwise try looking in either the left or right sub-tree
	else if (key < pTree->value)
	{
		return search(pTree->pLeft, key);
	}
	else
	{
		return search(pTree->pRight, key);
	}
}

void destroyTree(node *pTree)
{
	if (pTree != NULL)
	{
		destroyTree(pTree->pLeft);
		destroyTree(pTree->pRight);
		delete pTree;
	}
}

node *findMax(node *pTree)
{
	if (pTree == NULL)
	{
		return NULL;
	}
	if (pTree->pRight == NULL)
	{
		return pTree;
	}
	else
	{
		return findMax(pTree->pRight);
	}
}

node *removeMaxNode(node *pTree, node *pMax)
{
	if (pTree == NULL)
	{
		return NULL;
	}
	if (pTree == pMax)
	{
		return pMax->pLeft;
	}
	pTree->pRight = removeMaxNode(pTree->pRight, pMax);
	return pTree;
}

node *remove(node *pTree, int key)
{
	if (pTree == NULL)
	{
		return NULL;
	}
	if (pTree->value == key)
	{
		// node has no children
		if (pTree->pLeft == NULL)
		{
			node *pRightSubtree = pTree->pRight;
			delete pTree;
			return pRightSubtree;
		}
		if (pTree->pRight == NULL)
		{
			node *pLeftSubtree = pTree->pLeft;
			delete pTree;
			return pLeftSubtree;
		}
			node *pMax = findMax(pTree->pLeft);
			pMax->pLeft = removeMaxNode(pTree->pLeft, pMax);
			pMax->pRight = pTree->pRight;
			delete pTree;
			return pMax;
	
	}
	else if (key < pTree->value)
	{
		pTree->pLeft = remove(pTree->pLeft, key);
	}
	else
	{
		pTree->pRight = remove(pTree->pRight, key);
	}
}

int main()
{
	node *pTree = NULL;



	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}