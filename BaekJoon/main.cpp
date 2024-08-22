#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m; // ���� ����
	cin >> n >> m;
	vector<string>* castle = new vector<string>[n]; // �迭�� �°� �ð�������� 90�� ȸ������ ����
	for (int i = 0; i < n; i++)
	{
		castle[i].resize(m);
	}
	string toward = "south"; // ���� ���� ����
	int now[2] = { 0,0 }; // ���� ��ǥ, ���� ��ǥ
	while (true)
	{
		castle[now[0]][now[1]] = "visited"; // �湮 ��� �����
		if (toward == "south") // ���� ���� ����
		{
			if (now[0] + 1 >= n || castle[now[0] + 1][now[1]] == "visited") // �����ڸ��� ������ ���
			{
				if (now[1] + 1 >= m || castle[now[0]][now[1] + 1] == "visited") // ����Ǿ��� ����(����)�� ���� ���
				{
					break;
				}
				toward = "east";
				now[1]++;
			}
			else // �׳� ������ ���
			{
				now[0]++;
			}
		}
		else if (toward == "east") // ���� ���� ����
		{
			if (now[1] + 1 >= m || castle[now[0]][now[1] + 1] == "visited") // �����ڸ��� ������ ���
			{
				if (now[0] - 1 < 0 || castle[now[0] - 1][now[1]] == "visited") // ����Ǿ��� ����(����)�� ���� ���
				{
					break;
				}
				toward = "north";
				now[0]--;
			}
			else // �׳� ������ ���
			{
				now[1]++;
			}
		}
		else if (toward == "north") // ���� ���� ����
		{
			if (now[0] - 1 < 0 || castle[now[0] - 1][now[1]] == "visited") // �����ڸ��� ������ ���
			{
				if (now[1] - 1 < 0 || castle[now[0]][now[1] - 1] == "visited") // ����Ǿ��� ����(����)�� ���� ���
				{
					break;
				}
				toward = "west";
				now[1]--;
			}
			else // �׳� ������ ���
			{
				now[0]--;
			}
		}
		else if (toward == "west") // ���� ���� ����
		{
			if (now[1] - 1 < 0 || castle[now[0]][now[1] - 1] == "visited") // �����ڸ��� ������ ���
			{
				if (now[0] + 1 >= n || castle[now[0] + 1][now[1]] == "visited") // ����Ǿ��� ����(����)�� ���� ���
				{
					break;
				}
				toward = "south";
				now[0]++;
			}
			else // �׳� ������ ���
			{
				now[1]--;
			}
		}
	}
	cout << now[0] << " " << now[1];
}