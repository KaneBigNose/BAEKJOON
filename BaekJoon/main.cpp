#include <iostream>
#include <vector>
using namespace std;

void searchBC(vector<bool>* check, vector<int>* arr, int a, int b, int m, int n)
{
	arr[a][b] = 0;
	check[a][b] = true;
	if (a - 1 >= 0 && arr[a - 1][b] == 1 && check[a - 1][b] == false) // 북
	{
		searchBC(check, arr, a - 1, b, m, n);
	}
	if (b + 1 < m && arr[a][b + 1] == 1 && check[a][b + 1] == false) // 동
	{
		searchBC(check, arr, a, b + 1, m, n);
	}
	if (a + 1 < n && arr[a + 1][b] == 1 && check[a + 1][b] == false) // 남
	{
		searchBC(check, arr, a + 1, b, m, n);
	}
	if (b - 1 >= 0 && arr[a][b - 1] == 1 && check[a][b - 1] == false) // 서
	{
		searchBC(check, arr, a, b - 1, m, n);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int m, n, k; // 가로, 세로, 개수
		cin >> m >> n >> k;
		vector<bool>* check = new vector<bool>[n];
		vector<int>* arr = new vector<int>[n];
		int bugcount = 0;
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				check[a].push_back(false);
			}
		}
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				arr[a].push_back(0);
			}
		}
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				if (arr[a][b] == 1 && check[a][b] == false)
				{
					searchBC(check, arr, a, b, m, n);
					bugcount++;
				}
			}
		}
		cout << bugcount << "\n";
	}
}