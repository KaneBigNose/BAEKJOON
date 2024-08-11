#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> words;
	string word;
	cin >> word;
	for (int i = 0; i < word.size() - 1; i++)
	{
		for (int j = i + 1; j < word.size() - 1; j++)
		{
			int current = 0;
			string temp;
			string temp1, temp2, temp3;
			for (int k = current; k <= i; k++)
			{
				temp1 += word[k];
			}
			current = i + 1;
			for (int k = current; k <= j; k++)
			{
				temp2 += word[k];
			}
			current = j + 1;
			for (int k = current; k <= word.size() - 1; k++)
			{
				temp3 += word[k];
			}
			for (int k = 0; k < temp1.size(); k++)
			{
				temp += temp1[temp1.size() - k - 1];
			}
			for (int k = 0; k < temp2.size(); k++)
			{
				temp += temp2[temp2.size() - k - 1];
			}
			for (int k = 0; k < temp3.size(); k++)
			{
				temp += temp3[temp3.size() - k - 1];
			}
			words.push_back(temp);
		}
	}
	sort(words.begin(), words.end());
	cout << words[0];
}