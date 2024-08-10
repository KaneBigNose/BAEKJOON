#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> arr[51];
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		if (find(arr[temp.size()].begin(), arr[temp.size()].end(), temp) == arr[temp.size()].end())
		{
			arr[temp.size()].push_back(temp);
		}
	}
	for (int i = 0; i < 51; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}
	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << "\n";
		}
	}
}