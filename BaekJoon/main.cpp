#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	int num[2] = { 1,1 };
	int current = 1;
	bool right = true;
	for (int i = 0; i < x - 1; i++)
	{
		if (right == true) // ������ ����
		{
			if (num[0] == 1) // ���� ���
			{
				num[1] += 1;
				right = false;
			}
			else // �߰��� ���
			{
				num[1] += 1;
				num[0] -= 1;
			}
		}
		else // ���� ����
		{
			if (num[1] == 1) // ���� ���
			{
				num[0] += 1;
				right = true;
			}
			else // �߰��� ���
			{
				num[0] += 1;
				num[1] -= 1;
			}
		}
	}
	cout << num[0] << "/" << num[1];
}