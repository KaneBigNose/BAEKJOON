#include <iostream>
#include <vector>
using namespace std;

int needWood = 0;

void Check(vector<string>& arr, int column, int row)
{
	if (row + 1 < arr[0].size() && arr[column][row] == '-' && arr[column][row + 1] == '-')
	{
		if (row + 1 < arr[0].size() - 1)
		{
			Check(arr, column, row + 1);
		}
		else if (row + 1 == arr[0].size() - 1)
		{
			arr[column][row + 1] = 'X';
			needWood++;
		}
	}
	else if (column + 1 < arr.size() && arr[column][row] == '|' && arr[column + 1][row] == '|')
	{
		if (column + 1 < arr.size() - 1)
		{
			Check(arr, column + 1, row);
		}
		else if (column + 1 == arr.size() - 1)
		{
			arr[column][row + 1] = 'X';
			needWood++;
		}
	}
	arr[column][row] = 'X';
}

int main()
{
	int n, m; // 세로 가로
	cin >> n >> m;
	vector<string> arr;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Check(arr, i, j);
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << needWood;
}