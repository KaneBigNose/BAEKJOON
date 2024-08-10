#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	int count = 1;
	int num = 1;
	while (true)
	{
		if (x - num == 0)
		{
			break;
		}
		if (x - num < 0)
		{
			x -= num / 2;
			num = 1;
			count++;
		}
		else
		{
			num *= 2;
		}
	}
	cout << count;
}