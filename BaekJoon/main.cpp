#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> package, single;
	vector<int> price;
	for (int i = 0; i < m; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		package.push_back(temp1);
		single.push_back(temp2);
	}
	sort(package.begin(), package.end(), less<>());
	sort(single.begin(), single.end(), less<>());
	int num = n;
	int sum = 0;
	while (true)
	{
		if (num <= 0)
		{
			price.push_back(sum);
			break;
		}
		sum += package[0];
		num -= 6;
	}
	num = n;
	sum = 0;
	while(true)
	{
		if (num <= 0)
		{
			price.push_back(sum);
			break;
		}
		if (num >= 6)
		{
			sum += package[0];
			num -= 6;
		}
		else if (num > 0 && num < 6)
		{
			sum += single[0];
			num -= 1;
		}
	}
	price.push_back(single[0] * n);
	cout << *min_element(price.begin(), price.end());
}