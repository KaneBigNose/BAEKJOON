#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> num;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		num.push_back(temp);
		reverse(num[i].begin(), num[i].end());
	}
	int current = 0;
	int size = num[0].size();
	while (true)
	{
		if (num[0].size() == 0)
		{
			cout << "1";
			break;
		}
		for (int i = 0; i < n; i++)
		{
			if (count(num.begin(), num.end(), num[i]) > 1)
			{
				cout << size - current + 1;
				return 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			num[i].pop_back();
		}
		current++;
	}
}