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
	sort(arr.begin(), arr.end(), less<>());
	vector<int> smooth;
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = 1; j < 5; j++)
		{
			if (find(arr.begin(), arr.end(), arr[i] + j) != arr.end())
			{
				count++;
			}
		}
		smooth.push_back(count);
	}
	if (*max_element(smooth.begin(), smooth.end()) == 5)
	{
		cout << "0";
	}
	else
	{
		cout << 5 - *max_element(smooth.begin(), smooth.end());
	}
}