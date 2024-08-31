#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), less<>());
	int countT = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] + l - 0.5 < arr[j] + 0.5)
			{
				countT++;
				if (i != j)
				{
					i = j - 1;
				}
				else
				{
					i = j;
				}
				break;
			}
			if (j == n - 1)
			{
				cout << ++countT;
				return 0;
			}
		}
	}
	cout << countT;
}