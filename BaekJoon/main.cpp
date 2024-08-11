#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>* student = new vector<int>[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int temp;
			cin >> temp;
			student[i].push_back(temp);
		}
	}
	vector<int> score;
	for (int i = 0; i < n; i++)
	{
		score.push_back(0);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (student[i][k] == student[j][k])
				{
					score[i]++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (score[i] == *max_element(score.begin(), score.end()))
		{
			cout << i + 1;
			break;
		}
	}
}