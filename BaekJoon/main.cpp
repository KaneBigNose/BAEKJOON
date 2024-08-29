#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	string word;
	cin >> word;
	sort(word.begin(), word.end(), less<>());
	bool nomore = false;
	if (word.size() % 2 == 0)
	{
		nomore = true;
	}
	for (int i = 0; i < word.size(); i++)
	{
		if (count(word.begin(), word.end(), word[i]) % 2 == 1 && nomore == false)
		{
			nomore = true;
			i += count(word.begin(), word.end(), word[i]) - 1;
		}
		else if (count(word.begin(), word.end(), word[i]) % 2 == 1 && nomore == true)
		{
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}
	vector<char> half;
	if (word.size() % 2 == 0)
	{
		for (int i = 0; i < word.size(); i++)
		{
			if (find(half.begin(), half.end(), word[i]) == half.end())
			{
				if (count(word.begin(), word.end(), word[i]) > 1)
				{
					for (int j = 0; j < count(word.begin(), word.end(), word[i]) / 2; j++)
					{
						half.push_back(word[i]);
					}
				}
				else
				{
					half.push_back(word[i]);
				}
			}
		}
	}
	else
	{
		char rem;
		for (int i = 0; i <= word.size(); i++)
		{
			if (find(half.begin(), half.end(), word[i]) == half.end())
			{
				int num = count(word.begin(), word.end(), word[i]);
				if (num > 1)
				{
					if (num % 2 == 1)
					{
						for (int j = 0; j < num / 2; j++)
						{
							half.push_back(word[i]);
						}
						rem = word[i];
					}
					else
					{
						for (int j = 0; j < num / 2; j++)
						{
							half.push_back(word[i]);
						}
					}
				}
				else if (num == 1)
				{
					rem = word[i];
				}
			}
		}
		half.push_back(rem);
	}
	if (word.size() % 2 == 0)
	{
		for (int i = 0; i < half.size(); i++)
		{
			cout << half[i];
		}
		for (int i = 0; i < half.size(); i++)
		{
			cout << half[half.size() - i - 1];
		}
	}
	else
	{
		for (int i = 0; i < half.size(); i++)
		{
			cout << half[i];
		}
		for (int i = word.size() / 2 - 1; i >= 0; i--)
		{
			cout << half[i];
		}
	}
}