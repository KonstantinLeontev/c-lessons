#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

float absolute(float x)
{
	if (x < 0)
	{
		x = -x;
	}
	return x;
}

float newtonMethod(int num)
{
	int count = 0;
	float guess = 1;
	float difference = 0.5;
	while (absolute(guess*guess - num) >= difference)
	{
		guess = (num / guess + guess) / 2;
		count += 1;
		cout << "Newton Iteration " << count << ": guess = " << guess << endl;
	}
	return round(guess);
}

float binarySearch(int num)
{
	float low = 0;
	float high = num + 1;
	cout << "in beginning high = " << high << endl;
	float mid;
	int iter = 0;
	while ((high - low) > 0.1)
	{
		mid = (high + low) / 2;
		if (mid*mid < num)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
		iter += 1;
		cout << "Iteration " << iter << ": low = " << low << endl;
	}
	return round(low);
}

bool sqrtIntCheck(int num)
{
	float sqrNum = sqrt(num);
	cout << "sqrt(num) = " << sqrNum << endl;
	float binarySqr = binarySearch(num);
	cout << "binarySearch(num) = " << binarySqr << endl;
	cout << "newtonMethod = " << newtonMethod(num) << endl;
	int check = sqrNum;
	return check == sqrNum;
}

int main()
{
	int low, high, answer, T;
	cout << "Enter T value: ";
	cin >> T;
	for (int i = 0; i<T; i++)
	{
		answer = 0;
		cout << "Enter low value: ";
		cin >> low;
		cout << "Enter high value: ";
		cin >> high;
		for (int i = low; i <= high; i++)
		{
			if (sqrtIntCheck(i) == true)
			{
				answer += 1;
			}
		}
		cout << "Answer for " << low << " and " << high << " = " << answer << endl;
	}

	cin.ignore(10, '\n');
	cin.get();
    return 0;
}

