#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class StringConvertable
{
public:
	void toString()
	{
		cout << "Object name: " << this->name << ", value: " << this->value << endl;
		cout << "Date: " << timeDisplay() << endl;
	}
	string name;
	int value;
private:
	string timeDisplay(void)
	{
		time_t rawtime;
		time(&rawtime);
		return ctime(&rawtime);
	}
};

int main()
{
	/*time_t rawtime;
	time(&rawtime);
	cout << "Time is: " << ctime(&rawtime) << endl;*/

	cout << "Again I tell you..." << endl;
	cin.ignore();
	cin.get();
}