#include <iostream>
using namespace std;

int main()
{
	int n, m; // ���� ����
	cin >> n >> m;
	int north = -1, south = n, west = -1, east = m; // �� ������ ��
	int nowX = 0, nowY = 0; // �� ��ġ
	while (true)
	{
		nowY = south - 1;
		west++;
		if (nowX + 1 == east)
		{
			break;
		}
		nowX = east - 1;
		south--;
		if (nowY - 1 == north)
		{
			break;
		}
		nowY = north + 1;
		east--;
		if (nowX - 1 == west)
		{
			break;
		}
		nowX = west + 1;
		north++;
		if (nowY + 1 == south)
		{
			break;
		}
	}
	cout << nowY << " " << nowX;
}