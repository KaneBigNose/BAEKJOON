#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> word;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		word.push_back(temp);
	}
	for (int i = 0; i < word.size(); i++)
	{
		vector<char> check;
		bool ok = true;
		for (int j = 0; j < word[i].size(); j++)
		{
			if (find(check.begin(), check.end(), word[i][j]) != check.end()) // 체크에 해당 단어가 있을 경우
			{
				if (j > 1)
				{
					if (check[j - 1] != word[i][j])
					{
						ok = false;
					}
				}
			}
			check.push_back(word[i][j]);
		}
		if (ok == true)
		{
			count++;
		}
	}
	cout << count;
}