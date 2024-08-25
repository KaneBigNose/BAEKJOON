#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int t; // 테스트 케이스
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x1, y1, x2, y2; // 시작 좌표, 도착 좌표
		cin >> x1 >> y1 >> x2 >> y2;
		int n; // 행성의 개수
		cin >> n;
		vector<int> x, y, r; // 행성의 x, y 좌표 및 반지름
		for (int j = 0; j < n; j++)
		{
			int temp1, temp2, temp3;
			cin >> temp1 >> temp2 >> temp3;
			x.push_back(temp1);
			y.push_back(temp2);
			r.push_back(temp3);
		}
		// 시작 좌표나 도착 좌표가 어떤 행성 내에 있으면 반드시 통과해야함
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			int distance1 = pow(x1 - x[j], 2) + pow(y1 - y[j], 2); // 거리의 제곱
			int distance2 = pow(x2 - x[j], 2) + pow(y2 - y[j], 2); // 거리의 제곱
			if (distance1 < pow(r[j], 2) && distance2 > pow(r[j], 2))
			{
				count++;
			}
			else if (distance1 > pow(r[j], 2) && distance2 < pow(r[j], 2))
			{
				count++;
			}
		}
		cout << count << "\n";
	}
}