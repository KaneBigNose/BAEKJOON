#include <iostream>
#include <vector>
using namespace std;

int needWood = 0;

void CheckRow(vector<string>& arr, int column, int row)
{
	if (arr[column][row] == '-') // ���� ���� "-"�� ���
	{
		arr[column][row] = 'X';
		if (row + 1 < arr[0].size() && arr[column][row + 1] == '-') // ���� ���� "-"�� ���
		{
			CheckRow(arr, column, row + 1);
		}
		else // ���� ���� "|"�̰ų� "X"�̰ų� ���� ���� ���
		{
			needWood++;
		}
	}
}

void CheckColumn(vector<string>& arr, int column, int row)
{
	if (arr[column][row] == '|') // ���� ���� "-"�� ���
	{
		arr[column][row] = 'X';
		if (column + 1 < arr.size() && arr[column + 1][row] == '|') // ���� ���� "|"�� ���
		{
			CheckRow(arr, column, row + 1);
		}
		else // ���� ���� "-"�̰ų� "X"�̰ų� ���� ���� ���
		{
			needWood++;
		}
	}
}

int main()
{
	int n, m; // ���� ����
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