#include <iostream>
#include <string>
using namespace std;

class Drawable
{
public:
	virtual void draw() = 0;
	virtual ~Drawable();
};

Drawable::~Drawable()
{

}

class MyDrawable : public Drawable
{
public:
	virtual void draw();
	MyDrawable();
	virtual ~MyDrawable();

private:
	int *myData;
	void test(string name);
};

void MyDrawable::test(string name)
{
	cout << "Test from " << name << endl;
}

void MyDrawable::draw()
{
	test("draw()");
}

MyDrawable::MyDrawable()
{
	myData = new int;
	test("MyDrawable()");
}

MyDrawable::~MyDrawable()
{
	delete myData;
	test("~MyDrawable");
}

void deleteDrawable(Drawable *drawable)
{
	delete drawable;
	cout << "DeleteDrawable" << endl;
}

int main()
{
	deleteDrawable(new MyDrawable());

	//cin.ignore();
	//cin.get();
	return 0;
}