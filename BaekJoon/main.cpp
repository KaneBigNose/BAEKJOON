#include <iostream>
using namespace std;

int main()
{
	string x, y;
	cin >> x >> y;
	if (x.size() == y.size())
	{
		int count = 0;
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] != y[i])
			{
				count++;
			}
		}
		cout << count;
		return 0;
	}
	string final = x;
	for (int i = 0; i <= y.size() - x.size(); i++)
	{
		final += " ";
	}
	for (int i = 0; i <= y.size() - x.size(); i++)
	{
		string temp;
		int countFinal = 0, countTemp = 0;
		for (int j = 0; j < i; j++)
		{
			temp += " ";
		}
		temp += x;
		for (int j = 0; j < y.size() - x.size() - i; j++)
		{
			temp += " ";
		}
		for (int i = 0; i < y.size(); i++)
		{
			if (temp[i] == y[i])
			{
				countTemp++;
			}
		}
		for (int i = 0; i < y.size(); i++)
		{
			if (final[i] == y[i])
			{
				countFinal++;
			}
		}
		if (countFinal < countTemp)
		{
			final = temp;
		}
	}
	int count = 0;
	for (int i = 0; i < final.size(); i++)
	{
		if (final[i] == ' ')
		{
			final[i] = y[i];
		}
		if (final[i] != y[i])
		{
			count++;
		}
	}
	cout << count;
}