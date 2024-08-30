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
	int now = 0;
	while(true)
	{
		for (int i = now + 1; i < n; i++)
		{
			if (arr[i] - arr[now] + 1 > l)
			{
				countT++;
				now = i;
				break;
			}
			if (arr[now + 1] - arr[now] + 1 <= l && i == n - 1)
			{
				cout << ++countT;
				return 0;
			}
		}
		if (now >= n - 1)
		{
			break;
		}
	}
	cout << countT;
}