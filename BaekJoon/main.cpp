#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int bigR = r1 > r2 ? r1 : r2;
		int smallR = r1 <= r2 ? r1 : r2;
		int distance2 = pow(x1 - x2, 2) + pow(y1 - y2, 2); // 중심 사이 거리의 제곱
		if (x1 == x2 && y1 == y2 && r1 == r2) // 원의 중심이 동일하고 반지름도 동일한 경우
		{
			cout << "-1\n";
		}
		else if (x1 == x2 && y1 == y2 && r1 != r2) // 원의 중심이 동일하고 반지름이 다른 경우
		{
			cout << "0\n";
		}
		else if (distance2 > pow(bigR, 2)) // 외부인 경우
		{
			if (distance2 > pow(r1 + r2, 2)) // 접점이 0개인 경우
			{
				cout << "0\n";
			}
			else if (distance2 == pow(r1 + r2, 2)) // 접점이 1개인 경우
			{
				cout << "1\n";
			}
			else if (distance2 < pow(r1 + r2, 2)) // 접점이 2개인 경우
			{
				cout << "2\n";
			}
		}
		else if (distance2 == pow(bigR, 2)) // 경계선인 경우
		{
			cout << "2\n";
		}
		else if (distance2 < pow(bigR, 2)) // 내부인 경우
		{
			if (sqrt(distance2) + smallR > bigR)
			{
				cout << "2\n";
			}
			if (sqrt(distance2) + smallR == bigR)
			{
				cout << "1\n";
			}
			if (sqrt(distance2) + smallR < bigR)
			{
				cout << "0\n";
			}
		}
	}
}