#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string n;
	cin >> n;
	int sum = 0;
	if (n.size() == 1)
	{
		sum += stoi(n);
	}
	if (n.size() >= 2)
	{
		sum += 9;
		for (int i = 2; i <= n.size(); i++)
		{
			if (n.size() > i)
			{
				sum += i * (pow(10, i) - 1 - pow(10, i - 1) + 1);
			}
			else if (n.size() == i)
			{
				sum += i * (stoi(n) - pow(10, i - 1) + 1);
			}
		}
	}
	cout << sum;
}