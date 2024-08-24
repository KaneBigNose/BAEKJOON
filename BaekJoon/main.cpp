#include <iostream>
using namespace std;

int callzero[41] = { 0, };
int callone[41] = { 0, };

void fibonacci(int now, int original)
{
	if (callzero[now] != 0 || callone[now] != 0)
	{
		return;
	}
	if (now == 0)
	{
		callzero[original]++;
	}
	else if (now == 1)
	{
		callone[original]++;
	}
	else
	{
		if (now - 2 == 0)
		{
			callzero[original]++;
		}
		else if (now - 2 == 1)
		{
			callone[original]++;
		}
		else
		{
			if (callzero[now - 2] == 0 && callone[now - 2] == 0)
			{
				fibonacci(now - 2, original);
			}
			else
			{
				callzero[original] += callzero[now - 2];
				callone[original] += callone[now - 2];
			}
		}
		if (now - 1 == 0)
		{
			callzero[original]++;
		}
		else if (now - 1 == 1)
		{
			callone[original]++;
		}
		else
		{
			if (callzero[now - 1] == 0 && callone[now - 1] == 0)
			{
				fibonacci(now - 1, original);
			}
			else
			{
				callzero[original] += callzero[now - 1];
				callone[original] += callone[now - 1];
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int temp;
		cin >> temp;
		fibonacci(temp, temp);
		cout << callzero[temp] << " " << callone[temp] << "\n";
	}
}