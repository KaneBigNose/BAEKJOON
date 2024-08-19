#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int anum, bnum;
	cin >> anum >> bnum;
	vector<int> a, b;
	int ab = 0, ba = 0;
	for (int i = 0; i < anum; i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < bnum; i++)
	{
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end(), less<>());
	sort(b.begin(), b.end(), less<>());
	for (int i = 0; i < a.size(); i++)
	{
		if (find(b.begin(), b.end(), a[i]) == b.end())
		{
			ab++;
		}
	}
	for (int i = 0; i < b.size(); i++)
	{
		if (find(a.begin(), a.end(), b[i]) == a.end())
		{
			ba++;
		}
	}
	cout << ab + ba;
}