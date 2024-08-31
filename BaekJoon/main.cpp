#include <iostream>
using namespace std;

int main()
{
	unsigned long long x, y;
	int w, s;
	cin >> x >> y >> w >> s;
	bool cross;
	unsigned long long time = 0;
	if (w * 2 >= s)
	{
		cross = true;
	}
	else
	{
		cross = false;
	}
	if (x > y)
	{
		if (cross == true)
		{
			time += s * y;
		}
		else
		{
			time += w * 2 * y;
		}
		if ((x - y) % 2 == 0)
		{
			if ((x - y) * s < (x - y) * w)
			{
				time += (x - y) * s;
			}
			else
			{
				time += (x - y) * w;
			}
		}
		else
		{
			if ((x - y - 1) * s + w < (x - y) * w)
			{
				time += (x - y - 1) * s + w;
			}
			else
			{
				time += (x - y) * w;
			}
		}
	}
	else
	{
		if (cross == true)
		{
			time += s * x;
		}
		else
		{
			time += w * 2 * x;
		}
		if ((y - x) % 2 == 0)
		{
			if ((y - x) * s < (y - x) * w)
			{
				time += (y - x) * s;
			}
			else
			{
				time += (y - x) * w;
			}
		}
		else
		{
			if ((y - x - 1) * s + w < (y - x) * w)
			{
				time += (y - x - 1) * s + w;
			}
			else
			{
				time += (y - x) * w;
			}
		}
	}
	cout << time;
}