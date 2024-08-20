#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> bestseller;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		bestseller.push_back(temp);
	}
	sort(bestseller.begin(), bestseller.end(), less<>());
	vector<int> selling;
	for (int i = 0; i < n; i++)
	{
		selling.push_back(count(bestseller.begin(), bestseller.end(), bestseller[i]));
	}
	for (int i = 0; i < n; i++)
	{
		if (selling[i] == *max_element(selling.begin(), selling.end()))
		{
			cout << bestseller[i];
			break;
		}
	}
}