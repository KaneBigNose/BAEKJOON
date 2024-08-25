#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int t; // �׽�Ʈ ���̽�
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x1, y1, x2, y2; // ���� ��ǥ, ���� ��ǥ
		cin >> x1 >> y1 >> x2 >> y2;
		int n; // �༺�� ����
		cin >> n;
		vector<int> x, y, r; // �༺�� x, y ��ǥ �� ������
		for (int j = 0; j < n; j++)
		{
			int temp1, temp2, temp3;
			cin >> temp1 >> temp2 >> temp3;
			x.push_back(temp1);
			y.push_back(temp2);
			r.push_back(temp3);
		}
		// ���� ��ǥ�� ���� ��ǥ�� � �༺ ���� ������ �ݵ�� ����ؾ���
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			int distance1 = pow(x1 - x[j], 2) + pow(y1 - y[j], 2); // �Ÿ��� ����
			int distance2 = pow(x2 - x[j], 2) + pow(y2 - y[j], 2); // �Ÿ��� ����
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