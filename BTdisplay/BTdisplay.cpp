#include <iostream>
using namespace std;

struct node
{
	int value;
	node *pLeft;
	node *pRight;
};

enum menuItems {QUIT, ADD, LIST, LISTSORT, LISTREVERSE, TEST, ADDTESTARR, COUNTNODES, CHECKBALANCE, CHECKNODE};

void incorrectInput(void)
{
	cout << "INcorrect input. Please try again." << endl;
	cin.clear();
	cin.ignore();
}

int menu(void)
{
	int choice;
	while (1)
	{
		cout << "Choose from menu: ADD (1), LIST (2), LISTSORT (3), LISTREVERSE (4), TEST (5), ADDTESTARR (6), COUNTNODES (7), CHECKBALANCE (8), CHECKNODE (9) or QUIT (0): ";
		cin >> choice;
		if (choice >= 0 && choice <= 9)
		{
			return choice;
		}
		else
		{
			incorrectInput();
		}
	}
}

void test(int x)
{
	int y = 0;
	
	if (x < 10)
	{
		cout << "x = " << x << ", y = " << y << endl;
		test(x + 1);
		y += 1;

	}
	if (x == 10)
	{
		cout << "2nd line: x = " << x << ", y = " << y << endl;
	}
}

int askVal()
{
	int input;
	while (1)
	{
		cout << "Enter a number (0 - 10000): ";
		cin >> input;
		if (input >= 0 && input <= 10000)
		{
			return input;
		}
		else
		{
			incorrectInput();
		}
	}
}

node *addNode(node *pTree, int key)
{
	if (pTree == NULL)
	{
		node *pNew = new node;
		pNew->pLeft = NULL;
		pNew->pRight = NULL;
		pNew->value = key;
		return pNew;
	}
	if (key < pTree->value)
	{
		pTree->pLeft = addNode(pTree->pLeft, key);
	}
	else
	{
		pTree->pRight = addNode(pTree->pRight, key);
	}
	return pTree;
}

void listTree(node *pTree)
{
	if (pTree == NULL)
	{
		cout << "List is empty" << endl;
	}
	cout << "Node value: " << pTree->value << endl;
	if (pTree->pLeft != NULL)
	{
		listTree(pTree->pLeft);		
	}
	if (pTree->pRight != NULL)
	{	
		listTree(pTree->pRight);		
	}
}



void listTreeSort(node *pTree)
{
	if (pTree == NULL)
	{
		cout << "List is empty" << endl;
	}
	
	if (pTree->pLeft != NULL)
	{
		listTreeSort(pTree->pLeft);
	}
	cout << "Node = " << pTree->value << endl;
	if (pTree->pRight != NULL)
	{
		listTreeSort(pTree->pRight);
	}
}

void listTreeReverse(node *pTree)
{
	if (pTree == NULL)
	{
		cout << "List is empty" << endl;
	}
	if (pTree->pRight != NULL)
	{
		//cout << "Node Right = " << pTree->value << endl;
		listTreeReverse(pTree->pRight);
	}
	cout << "Node = " << pTree->value << endl;
	if (pTree->pLeft != NULL)
	{
		listTreeReverse(pTree->pLeft);
		//cout << "Node Left = " << pTree->value << endl;
	}
}


node *addTestArr(node *pTree, int testArr[])
{
	int i = 0;
	while (i<13)
	{
		pTree = addNode(pTree, testArr[i]);
		i++;
	}
	cout << "Test array was created!" << endl;
	return pTree;
}

int countNodes(node *pTree, int counter)
{
	if (pTree == NULL)
	{
		return 0;
	}
	if (pTree->pLeft != NULL)
	{
		counter = countNodes(pTree->pLeft, counter + 1);
	}
	if (pTree->pRight != NULL)
	{
		counter = countNodes(pTree->pRight, counter + 1);
	}
	return counter;
}

int checkSide(node *pTree, int counter, int side)
{
	if (pTree == NULL)
	{
		return 0;
	}
	if (side == 1)
	{
		if (pTree->pLeft != NULL)
		{
			pTree = pTree->pLeft;
			counter = countNodes(pTree, counter);
			/*if (pTree->pLeft != NULL)
			{
				counter = checkSide(pTree->pLeft, counter + 1, 1);
			}
			if (pTree->pRight != NULL)
			{
				counter = checkSide(pTree->pRight, counter + 1, 1);
			}*/
		}
	}
	if (side == 2)
	{
		if (pTree->pRight != NULL)
		{
			pTree = pTree->pRight;
			counter = countNodes(pTree, counter);
			/*if (pTree->pLeft != NULL)
			{
				counter = checkSide(pTree->pLeft, counter + 1, 2);
			}
			if (pTree->pRight != NULL)
			{
				counter = checkSide(pTree->pRight, counter + 1, 2);
			}*/
		}
	}
	return counter;
}

void checkBalance(node *pTree)
{
	int leftCount = checkSide(pTree, 1, 1);
	int rightCount = checkSide(pTree, 1, 2);
	cout << "Balance left : right is " << leftCount << " : " << rightCount << endl;
}

node *findNode(node *pTree, int num)
{
	if (pTree == NULL)
	{
		cout << "Tree is empty!" << endl;
		return NULL;
	}
	else if (pTree->value == num)
	{
		return pTree;
	}
	else if (pTree->value > num)
	{
		return findNode(pTree->pLeft, num);
	}
	else if (pTree->value < num)
	{
		return findNode(pTree->pRight, num);
	}

}

bool checkSort(node *pTree, int num, bool flag)
{
	if (pTree == NULL)
	{
		cout << "Tree is empty!" << endl;
		return false;
	}
	if (pTree->pLeft != NULL)
	{
		if (pTree->pLeft->value > pTree->value)
		{
			cout << "pTree->pLeft->value = " << pTree->pLeft->value << " > " << "pTree->value = " << pTree->value << endl;
			return false;
		}
			cout << "Value on the left = " << pTree->pLeft->value << endl;
			flag = checkSort(pTree->pLeft, num, flag);
	}
	if (pTree->pRight != NULL)
	{
		if (pTree->pRight->value < pTree->value)
		{
			cout << "pTree->pRight->value = " << pTree->pRight->value << " > " << "pTree->value = " << pTree->value << endl;
			return false;
		}
			cout << "Value on the right = " << pTree->pRight->value << endl;
			flag = checkSort(pTree->pRight, num, flag);
	}
	return flag;
}

void checkNode(node *pTree)
{
	int num;
	node *pTemp;
	while (1)
	{
		cout << "Enter a number of node: ";
		cin >> num;
		if (num >= 0 && num <= 10000)
		{
			break;
		}
		else
		{
			incorrectInput();
		}
	}
	pTemp = findNode(pTree, num);
	if (checkSort(pTemp, num, true) != false)
	{
		cout << "Tree is sorted" << endl;
	}
	else
	{
		cout << "Tree is not sorted!" << endl;
	}
}

int main()
{
	bool start = true;
	int key, counter;
	node *pTree = NULL;
	int testArr[] = { 10, 8, 18, 14, 20, 9, 2, 1, 5, 4, 3, 7, 6 };

	while (start)
	{
		counter = 1;
		switch (menu())
		{
		case ADD: key = askVal(); pTree = addNode(pTree, key); cout << "Number was added" << endl;  break;
		case LIST: listTree(pTree); break;
		case LISTSORT: listTreeSort(pTree); break;
		case LISTREVERSE: listTreeReverse(pTree); break;
		case TEST: test(0); break;
		case ADDTESTARR: pTree = addTestArr(pTree, testArr); break;
		case COUNTNODES: counter = countNodes(pTree, counter); cout << counter << " nodes in the tree" << endl; break;
		case CHECKBALANCE: checkBalance(pTree); break;
		case CHECKNODE: checkNode(pTree); break;
		case QUIT: start = false; break;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();
	return 0;
}