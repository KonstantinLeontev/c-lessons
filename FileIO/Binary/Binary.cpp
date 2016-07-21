#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct PlayerRecord
{
	int age;
	int score;
	string name;
};

int main()
{
	fstream file("test.bin", ios::trunc | ios::binary | ios::in | ios::out); // open file in binary mode

	PlayerRecord rec;
	rec.age = 20;
	rec.score = 1000;
	rec.name = "John";

	file.write(reinterpret_cast<char*>(&rec.age), sizeof(rec.age));
	file.write(reinterpret_cast<char*>(&rec.score), sizeof(rec.score));
	int len = rec.name.length();
	file.write(reinterpret_cast<char*>(&len), sizeof(len));
	file.write(rec.name.c_str(), len + 1); // + 1 for null terminator

	PlayerRecord inRec;

	file.seekg(0, ios::beg);
	if (!file.read(reinterpret_cast<char*>(&inRec.age), sizeof(inRec.age)))
	{
		cout << "Error!";
		return 1;
	}
	if (!file.read(reinterpret_cast<char*>(&inRec.score), sizeof(inRec.score)))
	{
		cout << "Error!";
	}
	int strLen;
	if (!file.read(reinterpret_cast<char*>(&strLen), sizeof(strLen)))
	{
		cout << "error";
	}
	else if (strLen > 0 && strLen < 10000)
	{
		char *pStrBuf = new char[strLen];
		if (!file.read(pStrBuf, strLen + 1))
		{
			cout << "Error";
		}
		if (pStrBuf[strLen] == 0) // validate that the string is null-terminating
		{
			inRec.name = string(pStrBuf);
		}
		delete[] pStrBuf;
	}
	cout << inRec.age << " " << inRec.score << " " << inRec.name << endl;
}