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
		int distance2 = pow(x1 - x2, 2) + pow(y1 - y2, 2); // �߽� ���� �Ÿ��� ����
		if (x1 == x2 && y1 == y2 && r1 == r2) // ���� �߽��� �����ϰ� �������� ������ ���
		{
			cout << "-1\n";
		}
		else if (x1 == x2 && y1 == y2 && r1 != r2) // ���� �߽��� �����ϰ� �������� �ٸ� ���
		{
			cout << "0\n";
		}
		else if (distance2 > pow(bigR, 2)) // �ܺ��� ���
		{
			if (distance2 > pow(r1 + r2, 2)) // ������ 0���� ���
			{
				cout << "0\n";
			}
			else if (distance2 == pow(r1 + r2, 2)) // ������ 1���� ���
			{
				cout << "1\n";
			}
			else if (distance2 < pow(r1 + r2, 2)) // ������ 2���� ���
			{
				cout << "2\n";
			}
		}
		else if (distance2 == pow(bigR, 2)) // ��輱�� ���
		{
			cout << "2\n";
		}
		else if (distance2 < pow(bigR, 2)) // ������ ���
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