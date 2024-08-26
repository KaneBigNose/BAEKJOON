#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> arr;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}
	int maxsize = n > m ? m : n;
	maxsize--;
	while (true)
	{
		if (maxsize <= 0)
		{
			cout << "1";
			break;
		}
		for (int i = 0; i < n - maxsize; i++)
		{
			for (int j = 0; j < m - maxsize; j++)
			{
				if (arr[i][j] == arr[i][j + maxsize] && arr[i][j + maxsize] == arr[i + maxsize][j] && arr[i + maxsize][j] == arr[i + maxsize][j + maxsize])
				{
					cout << pow(maxsize + 1, 2);
					return 0;
				}
			}
		}
		maxsize--;
	}
}