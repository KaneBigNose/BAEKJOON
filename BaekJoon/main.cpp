#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), greater<>());
	int big = 0;
	while (true)
	{
		for (int i = big + 1; i < n - 1; i++)
		{
			if (arr[big] < arr[i] + arr[i + 1])
			{
				cout << arr[big] + arr[i] + arr[i + 1];
				return 0;
			}
		}
		if (big == n - 3)
		{
			cout << "-1";
			break;
		}
		big++;
	}
}