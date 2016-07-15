#include <iostream>
#include <string>
using namespace std;

int exit(void)
{
	int input;
	//cin.clear();
	//cin.ignore();
	while (1)
	{
		cout << "Do you want to stop (0) or continue (1)?" << endl;
		cin >> input;
		if (input == 0 || input == 1)
		{
			cout << "Test line: input = " << input << endl;
			return input;
		}
		else
		{
			cout << "Incorrect input.Please try again" << endl;
			cin.clear();
			cin.ignore();
		}
	}
}

void changeInput(string &input)
{
	int start, end;
	start = input.find("<body>", 0);
	end = input.find("</body>", 0);
	input = input.substr(start + 6, end - start - 6);
	cout << "Test input after <body> removing: " << '"' << input << '"' << '\n' << endl;
  // <b></b> = * <a href=linkurl> link text </a>  <i></i> = _
	if (input.length() != 0)
	{
		for (int i = input.find("<b>", 0); i != string::npos; i = input.find("<b>", i)) // changes for <b>
		{
			end = input.find("</b>", i);
			input = input.substr(0, i) + '*' + input.substr(i + 3, end - i - 3) + '*' + input.substr(end + 4, input.length() - end - 4);
			i++;
		}
		cout << "Test input after <b> removing: " << '"' << input << '"' << '\n' << endl;
		for (int i = input.find("<i>", 0); i != string::npos; i = input.find("<i>", i))
		{
			end = input.find("</i>", i);
			input = input.substr(0, i) + '_' + input.substr(i + 3, end - i - 3) + '_' + input.substr(end + 4, input.length() - end - 4);
			i++;
		}
		cout << "Test input after <i> removing: " << input << '"' << '\n' << endl;
		for (int i = input.find("<a", 0); i != string::npos; i = input.find("<a", i))
		{
			start = input.find(">", i);
			end = input.find("</a>", i);
			input = input.substr(0, i) + input.substr(start + 1, end - start - 1) + " (" + input.substr(input.find("=", i) + 1, start - input.find("=", i) - 1) + ") " + input.substr(end + 4, input.length() - end - 4);
			i++;
		}
		cout << "Test input after <a> removing: " << '"' << '\n' << input << endl;
	}
	else
	{
		cout << "Input string is empty!" << endl;
	}
	//return input;
}

int main()
{

	while (1)
	{
		string input = " ";
		cout << "Enter an HTML page: ";
		cin.clear();
		cin.ignore();
		getline(cin, input, '\n');
		changeInput(input);
		cout << "--- Start text ---" << endl;
		cout << input << endl;
		cout << "--- End text ---" << endl;
		if (exit() == 0)
		{
			break;
		}
	}

	cout << "Again I tell you..." << endl;
	cin.ignore();
	cin.get();
	return 0;
}