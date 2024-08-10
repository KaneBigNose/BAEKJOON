#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<int> num1, num2;
		int n, m;
		cin >> n >> m;
		unsigned long long result1 = 1, result2 = 1;
		for (int j = 0; j < n; j++)
		{
			num1.push_back(m - j);
		}
		for (int j = 0; j < n; j++)
		{
			num2.push_back(n - j);
		}
		for (int j = 0; j < n; j++)
		{
			if (find(num1.begin(), num1.end(), n - j) != num1.end())
			{
				*find(num1.begin(), num1.end(), n - j) = 1;
				*find(num2.begin(), num2.end(), n - j) = 1;
			}
		}
		for (int j = 0; j < n; j++)
		{
			result1 *= num1[j];
			result2 *= num2[j];
		}
		cout << result1 / result2 << "\n";
	}
}