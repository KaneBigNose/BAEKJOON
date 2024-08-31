#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	int count = 0;
	while (true)
	{
		if (x == 1)
		{
			break;
		}
		if (x % 3 == 0)
		{
			x = x / 3;
		}
		else if (x % 2 == 0)
		{
			x = x / 2;
		}
		else
		{
			x--;
		}
		count++;
	}
	cout<<count;
}