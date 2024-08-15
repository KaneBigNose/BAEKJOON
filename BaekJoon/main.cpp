#include <iostream>
using namespace std;

int main()
{
	int n, kim, lim;
	cin >> n >> kim >> lim;
	int round = 1;
	while (true)
	{
		if (kim == n && n % 2 == 1)
		{
			goto A;
		}
		else if (lim == n && n % 2 == 1)
		{
			goto A;
		}
		if (kim % 2 == 1 && kim + 1 == lim)
		{
			break;
		}
		else if (kim % 2 == 0 && kim - 1 == lim)
		{
			break;
		}
	A:
		if (kim % 2 == 1)
		{
			kim = kim / 2 + 1;
		}
		else
		{
			kim = kim / 2;
		}
		if (lim % 2 == 1)
		{
			lim = lim / 2 + 1;
		}
		else
		{
			lim = lim / 2;
		}
		if (n % 2 == 1)
		{
			n = n / 2 + 1;
		}
		else
		{
			n = n / 2;
		}
		round++;
	}
	cout << round;
}