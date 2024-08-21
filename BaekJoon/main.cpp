#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int W, H, X, Y, P;
	cin >> W >> H >> X >> Y >> P;
	vector<int> px, py;
	for (int i = 0; i < P; i++)
	{
		int x, y;
		cin >> x >> y;
		px.push_back(x);
		py.push_back(y);
	}
	int countP = 0;
	for (int i = 0; i < P; i++)
	{
		if (px[i] >= X && px[i] <= X + W && py[i] >= Y && py[i] <= Y + H) // ���簢�� ���� �ִ� ���
		{
			countP++;
		}
		else if (pow(X - px[i], 2) + pow((Y + H / 2) - py[i], 2) <= pow(H / 2, 2)) // ���� �ݿ��� �ִ� ���
		{
			countP++;
		}
		else if (pow((X + W) - px[i], 2) + pow((Y + H / 2) - py[i], 2) <= pow(H / 2, 2)) // ������ �ݿ��� �ִ� ���
		{
			countP++;
		}
	}
	cout << countP;
}