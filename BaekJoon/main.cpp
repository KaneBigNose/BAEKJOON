#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	int current = k;
	int count = 0;
	arr.push_back(k);
	while (true)
	{
		if (arr.size() == n)
		{
			break;
		}
		if (current + 1 > n)
		{
			current = 1;
		}
		else
		{
			current++;
		}
		if (find(arr.begin(), arr.end(), current) == arr.end())
		{
			count++;
		}
		if (count >= k)
		{
			if (find(arr.begin(), arr.end(), current) == arr.end())
			{
				arr.push_back(current);
				count = 0;
			}
		}
	}
	cout << "<";
	for (int i = 0; i < n - 1; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << *(arr.end() - 1) << ">";
}