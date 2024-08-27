#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string word;
	cin >> word;
	bool nomore = false;
	if (word.size() % 2 == 0)
	{
		nomore = true;
	}
	sort(word.begin(), word.end(), less<>());
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

}