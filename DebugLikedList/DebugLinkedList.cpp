#include <iostream>
using namespace std;

struct LinkedList
{
	int value;
	LinkedList *pNext = NULL;
};

void printList(const LinkedList *lst)
{
	if (lst != NULL)
	{
		cout << lst->value;
		cout << "\n";
		printList(lst->pNext);
	}
}

int main()
{
		LinkedList *lst = new LinkedList;
		lst->value = 10;
		lst->pNext = new LinkedList;
		lst->pNext->value = 11;
		printList(lst);

		cin.ignore();
		return 0;
}