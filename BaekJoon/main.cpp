#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	vector<string> visit;
	string beforeNum;
	string currentNum;
	for (int i = 0; i < 36; i++)
	{
		string temp;
		cin >> temp;
		visit.push_back(temp);
	}
	string first, last;
	first = visit[0][1];
	last = visit[35][1];
	if (abs((int)visit[0][0] - (int)visit[35][0]) == 2 && abs(stoi(first) - stoi(last)) == 1) {} // ���������� �湮�� �������� ó�� �������� �� �� �ִ��� üũ
	else if(abs((int)visit[0][0] - (int)visit[35][0]) == 1 && abs(stoi(first) - stoi(last)) == 2) {}
	else // �� �� ���� ���
	{
		cout << "Invalid";
		return 0;
	}
	for (int i = 0; i < visit.size() - 1; i++)
	{
		beforeNum = visit[i][1];
		currentNum = visit[i + 1][1];
		if (count(visit.begin(), visit.end(), visit[i]) != 1) // �̹� ���� ������ ��湮�� ���
		{
			cout << "Invalid";
			return 0;
		}
		if (abs(stoi(beforeNum) - stoi(currentNum)) == 2) // �� �Ʒ� �������� 2ĭ �̵� �� 90�� �̵�
		{
			if (abs((int)visit[i][0] - (int)visit[i + 1][0]) != 1)
			{
				cout << "Invalid";
				return 0;
			}
		}
		else if (abs((int)visit[i][0] - (int)visit[i + 1][0]) == 2) // �� �� �������� 2ĭ �̵��� 90�� �̵�
		{
			if (abs(stoi(beforeNum) - stoi(currentNum)) != 1)
			{
				cout << "Invalid";
				return 0;
			}
		}
		else // ����Ʈ�� �̵� ����� �ƴ� ���
		{
			cout << "Invalid";
			return 0;
		}
	}
	cout << "Valid";
}