#include <iostream>
using namespace std;

void printAB(int& count)
{
	if (count == 0)
	{
		return;
	}
	if (count >= 4)
	{
		count -= 4;
		cout << "AAAA";
		printAB(count);
	}
	else
	{
		count -= 2;
		cout << "BB";
		printAB(count);
	}
}

int main()
{
	string poly;
	cin >> poly;
	int count = 0;
	int check = 0;
	for (int i = 0; i < poly.size(); i++)
	{
		if (poly[i] == 'X')
		{
			check++;
		}
		if (poly[i] == '.' || i == poly.size() - 1)
		{
			if (check % 2 == 1)
			{
				cout << "-1";
				return 0;
			}
			check = 0;
		}
	}
	for (int i = 0; i < poly.size(); i++)
	{
		if (poly[i] == 'X')
		{
			count++;
		}
		if (poly[i] == '.' || i == poly.size() - 1)
		{
			printAB(count);
			count = 0;
			if (i != poly.size() - 1)
			{
				cout << ".";
			}
		}
	}
	if (*(poly.end() - 1) == '.')
	{
		cout << ".";
	}
}