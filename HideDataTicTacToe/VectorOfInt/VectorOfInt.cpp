#include <iostream>
#include <string>
using namespace std;

enum menuItems {QUIT, GET, SET, PUSHBACK, PUSHFRONT, LIST};

void incorrectInput(void)
{
	cout << "Incorrect input. Please try again" << endl;
	cin.clear();
	cin.ignore();
}

int menu(void)
{
	int choice;
	while (1)
	{
		cout << "Choose from menu: GET (1), SET (2), PUSHBACK (3), PUSHFRONT (4), LIST (5) or QUIT (0): ";
		cin >> choice;
		if (choice >= 0 && choice <= 5)
		{
			return choice;
		}
		else
		{
			incorrectInput();
		}
	}
}

int askNum(string name)
{
	int num;
	cout << "Enter a " << name << ": ";
	cin >> num;
	return num;
}

class VectorOfInt
{
public:
	VectorOfInt(); // no-argument constructor for 32 element vector
	VectorOfInt(const int inputSize); // constructor take an initial size
	~VectorOfInt(); // destructor
	VectorOfInt& operator= (const VectorOfInt &other); // assignment operator
	VectorOfInt(const VectorOfInt &other); // copy constructor
	int get(int index); // returning the value of index
	void set(int value, int index); // set a value at an index
	void pushback(int value); // add value to the end
	void pushfront(int value); // add value to the beginning of the array
	int size; // size of the array
	int *pArr;
	void list(void);

private:

	bool checkPositives(int num);
	bool checkIndex(int num);
	int inputNum(void);
	int *growArr(int value);
};

void VectorOfInt::list(void)
{
	cout << "--- Start list ---" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "index = " << i << ", value = " << pArr[i] << endl;
	}
	cout << "--- End list ---" << endl;
}

VectorOfInt::VectorOfInt(const VectorOfInt &other)
	: pArr(NULL)
{
	size = other.size;
	int *pArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		pArr[i] = other.pArr[i];
	}
}

VectorOfInt &VectorOfInt::operator= (const VectorOfInt &other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] pArr;
	pArr = NULL;

	size = other.size;
	int *pArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		pArr[i] = other.pArr[i];
	}
	return *this;
}

VectorOfInt::~VectorOfInt()
{
	delete[] pArr;
}

VectorOfInt::VectorOfInt() // no-argument constructor)
	:size(32)
{
	pArr = new int[size];
}

VectorOfInt::VectorOfInt(int inputSize)
{
	if (checkPositives(inputSize))
	{
		pArr = new int[inputSize];
	}
	else
	{
		inputSize = inputNum();
		pArr = new int[inputSize];
	}
	size = inputSize;
}

bool VectorOfInt::checkIndex(int num)
{
	if (num >= 0 && num < size)
	{
		return true;
	}
	else
	{
		cout << num << " is out of range (0 - " << size << ")!" << endl;
		return false;
	}
}

bool VectorOfInt::checkPositives(int num)
{
	if (num >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int VectorOfInt::inputNum(void)
{
	int num;
	while (1)
	{
		cout << "Enter a positive number: " << endl;
		cin >> num;
		if (checkPositives(num))
		{
			return num;
		}
		else
		{
			incorrectInput();
		}
	}
}

int VectorOfInt::get(int index)
{
	while (1)
	{
		if (checkIndex(index))
		{
			return pArr[index];
		}
		else
		{
			index = inputNum();
		}
	}
}

void VectorOfInt::set(int value, int index)
{
	while (1)
	{
		if (checkIndex(index))
		{
			pArr[index] = value;
			break;
		}
		else
		{
			index = inputNum();
		}
	}	
}

//int *VectorOfInt::growArr(int value)
//{
//	int *pNew = new int[size + 1];
//	for (int i = 0; i < size; i++)
//	{
//		pNew[i] = pArr[i]; // copy each value from old to new
//	}
//	pNew[size] = value;
//	delete[] pArr;
//	return pNew;
//}

void VectorOfInt::pushback(int value)
{
	int *pNew = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		pNew[i] = pArr[i]; // copy each value from old to new
	}
	//pNew[size] = value;
	delete[] pArr;
	pArr = pNew;
	pArr[size] = value;
	size++;
}

void VectorOfInt::pushfront(int value)
{
	int *pNew = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		pNew[i + 1] = pArr[i];
	}
	delete[] pArr;
	pArr = pNew;
	pArr[0] = value;
	size++;
}

int main()
{
	bool start = true;
	int value, index;
	VectorOfInt myVector;

	while (start)
	{
		switch (menu())
		{
		case GET: index = askNum("index"); cout << "Value in index " << index << " = " << myVector.get(index) << endl; break;
		case SET: index = askNum("index"); value = askNum("value"); myVector.set(value, index); cout << "myVector[" << index << "] = " << value << endl; break;
		case PUSHBACK: value = askNum("value"); myVector.pushback(value); cout << "Value " << value << " was added" << endl; break;
		case PUSHFRONT: value = askNum("value"); myVector.pushfront(value); cout << "Value " << value << " was added" << endl; break;
		case LIST: myVector.list(); break;
		case QUIT: start = false; break;
		}
	}

	cout << "Again I tell you..." << endl;
	cin.ignore();
	cin.get();
}