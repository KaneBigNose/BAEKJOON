#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string* line = new string[n];
	vector<int> count;
	for (int i = 0; i < n; i++)
	{
		cin >> line[i];
	}
	for (int i = 0; i < 2 * (n - 7) * (m - 7); i++)
	{
		count.push_back(0);
	}
	bool black;
	int up = 0;
	for (int a = 0; a < n - 7; a++)
	{
		for (int b = 0; b < m - 7; b++)
		{
			black = true;
			for (int i = a; i < a + 8; i++)
			{
				for (int j = b; j < b + 8; j++)
				{
					if (black == true && line[i][j] == 'W')
					{
						count[up]++;
					}
					else if (black == false && line[i][j] == 'B')
					{
						count[up]++;
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
				if (black == true)
				{
					black = false;
				}
				else
				{
					black = true;
				}
			}
			up++;
			black = false;
			for (int i = a; i < a + 8; i++)
			{
				for (int j = b; j < b + 8; j++)
				{
					if (black == true && line[i][j] == 'W')
					{
						count[up]++;
					}
					else if (black == false && line[i][j] == 'B')
					{
						count[up]++;
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
				if (black == true)
				{
					black = false;
				}
				else
				{
					black = true;
				}
			}
			up++;
		}
	}
	cout << *min_element(count.begin(), count.end());
}