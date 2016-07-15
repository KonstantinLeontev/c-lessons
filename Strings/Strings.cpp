#include <iostream>
#include <string>
using namespace std;

int needleCounter(const string &needle, const string &haystack)
{
	int i = 0;
	int appearances = 0;

	for (i = haystack.find(needle, 0); i != string::npos; i = haystack.find(needle, i))
	{
		cout << "i = " << i << endl;
		cout << "appearances = " << appearances << endl;
		appearances++;
		i++;
	}
	return appearances;
}

int main()
{
	const string needle = "needle";
	const string haystack = "Through the eye of a needle, through the eye of a needle. Again I tell you, \
		it is easier for a camel to pass trough the eye of a needle than for a rich man to enter the kingdom of God.";
	
	cout << "Needle appearances " << needleCounter(needle, haystack) << " times in the " << '"' << haystack << '"' << endl;


	cout << "Good buy!" << endl;
	cin.ignore();
	return 0;
}