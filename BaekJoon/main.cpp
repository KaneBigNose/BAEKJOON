#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void stringFomula(string word, int& sum)
{
	for (int i = 0; i < word.size(); i++)
	{
		if ((int)word[i] >= 48 && (int)word[i] <= 57)
		{
			sum += (int)word[i] - 48;
		}
	}
}

void comparator(vector<string>& arr, int i, int j)
{
	int sum1 = 0, sum2 = 0;
	stringFomula(arr[i], sum1);
	stringFomula(arr[j], sum2);
	if (sum1 > sum2)
	{
		swap(arr[i], arr[j]);
	}
	else if (sum1 == sum2)
	{
		if (arr[i] > arr[j])
		{
			swap(arr[i], arr[j]);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<string> arr;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[i].size() > arr[j].size())
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i].size() == arr[j].size())
			{
				comparator(arr, i, j);
			}
		}
	}
	for (int i = 0; i < arr.size() - 1; i++)
	{
		cout << arr[i] << "\n";
	}
	cout << *(arr.end() - 1);
}