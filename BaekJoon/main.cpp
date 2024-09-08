#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<char>* arr = new vector<char>[n]; // 模备 府胶飘
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			if (i != j && temp[j] == 'Y')
			{
				if (find(arr[i].begin(), arr[i].end(), (char)('A' + j)) == arr[i].end())
				{
					arr[i].push_back((char)('A' + j));
				}
				if (find(arr[j].begin(), arr[j].end(), (char)('A' + i)) == arr[j].end())
				{
					arr[j].push_back((char)('A' + i));
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			for (int k = 0; k < arr[j].size(); k++)
			{
				if (find(arr[i].begin(), arr[i].end(), arr[j][k]) == arr[i].end())
				{
					arr[i].push_back(arr[j][k]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
	int* num = new int[n]; // 模备 牢盔 钎
	for (int i = 0; i < n; i++)
	{
		num[i] = arr[i].size();
	}
	cout << *max_element(num, num + n);
}