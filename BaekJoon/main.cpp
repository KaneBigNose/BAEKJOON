#include <iostream>
#include <vector>
using namespace std;

int needWood = 0;

void CheckRow(vector<string>& arr, int column, int row)
{
	if (arr[column][row] == '-') // 현재 값이 "-"인 경우
	{
		arr[column][row] = 'X';
		if (row + 1 < arr[0].size() && arr[column][row + 1] == '-') // 다음 값이 "-"인 경우
		{
			CheckRow(arr, column, row + 1);
		}
		else // 다음 값이 "|"이거나 "X"이거나 값이 없는 경우
		{
			needWood++;
		}
	}
}

void CheckColumn(vector<string>& arr, int column, int row)
{
	if (arr[column][row] == '|') // 현재 값이 "-"인 경우
	{
		arr[column][row] = 'X';
		if (column + 1 < arr.size() && arr[column + 1][row] == '|') // 다음 값이 "|"인 경우
		{
			CheckRow(arr, column, row + 1);
		}
		else // 다음 값이 "-"이거나 "X"이거나 값이 없는 경우
		{
			needWood++;
		}
	}
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
			CheckRow(arr, i, j);
			CheckColumn(arr, i, j);
		}
	}
	cout << needWood;
}