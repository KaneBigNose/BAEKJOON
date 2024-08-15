#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int l, n;
	cin >> l;
	vector<int> s;
	for (int i = 0; i < l; i++)
	{
		int temp;
		cin >> temp;
		s.push_back(temp);
	}
	cin >> n;
	sort(s.begin(), s.end());
	int first, last, count = 0;
	for (int i = 0; i < l; i++)
	{
		if (n == s[i])
		{
			cout << "0";
			return 0;
		}
		else if (n < s[i])
		{
			if (n < s[0]) // n이 집합의 원소들보다 작을 경우
			{
				first = 1;
			}
			else if (i - 1 <= 0)
			{
				first = s[0] + 1;
			}
			else
			{
				first = s[i - 1] + 1;
			}
			last = s[i] - 1;
			break;
		}
	}
	for (int i = first; i <= n; i++)
	{
		for (int j = n; j <= last; j++)
		{
			count++;
		}
	}
	if (l != 1) // [n, n] 구간이 발생하여 이를 제외
	{
		count--;
	}
	cout << count;
}