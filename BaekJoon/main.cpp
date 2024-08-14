#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string* line = new string[n];
	int count[2] = { 0,0 };
	for (int i = 0; i < n; i++)
	{
		cin >> line[i];
	}
	bool black = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (black == true && line[i][j] == 'W')
			{
				count[0]++;
			}
			else if (black == false && line[i][j] == 'B')
			{
				count[0]++;
			}
			if (black == true)
			{
				black = false;
			}
			else
			{
				black = true;
			}
		}
		if (m % 2 == 0)
		{
			if (black == true)
			{
				black = false;
			}
			else
			{
				black = true;
			}
		}
	}
	black = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (black == true && line[i][j] == 'W')
			{
				count[1]++;
			}
			else if (black == false && line[i][j] == 'B')
			{
				count[1]++;
			}
			if (black == true)
			{
				black = false;
			}
			else
			{
				black = true;
			}
		}
		if (m % 2 == 0)
		{
			if (black == true)
			{
				black = false;
			}
			else
			{
				black = true;
			}
		}
	}
	if (count[0] <= count[1])
	{
		cout << count[0];
	}
	else
	{
		cout << count[1];
	}
}