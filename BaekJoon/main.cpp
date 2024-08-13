#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vote;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		vote.push_back(temp);
	}
	if (n == 1)
	{
		cout << "0";
		return 0;
	}
	if (count(vote.begin(), vote.end(), *max_element(vote.begin(), vote.end())) == 1 && vote[0] == *max_element(vote.begin(), vote.end()))
	{
		cout << "0";
		return 0;
	}
	int num = 0;
	while (true)
	{
		bool bigger = true;
		for (int i = 1; i < vote.size(); i++)
		{
			if (vote[0] <= vote[i])
			{
				bigger = false;
			}
		}
		if (bigger == true)
		{
			cout << num;
			break;
		}
		num++;
		vote[0]++;
		for (int i = 1; i < vote.size(); i++)
		{
			if (vote[i] == *max_element(vote.begin(), vote.end()))
			{
				vote[i]--;
				break;
			}
		}
	}
}