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
	if (abs((int)visit[0][0] - (int)visit[35][0]) == 2 && abs(stoi(first) - stoi(last)) == 1) {} // 마지막으로 방문한 지점에서 처음 지점으로 갈 수 있는지 체크
	else if(abs((int)visit[0][0] - (int)visit[35][0]) == 1 && abs(stoi(first) - stoi(last)) == 2) {}
	else // 갈 수 없는 경우
	{
		cout << "Invalid";
		return 0;
	}
	for (int i = 0; i < visit.size() - 1; i++)
	{
		beforeNum = visit[i][1];
		currentNum = visit[i + 1][1];
		if (count(visit.begin(), visit.end(), visit[i]) != 1) // 이미 갔던 지점을 재방문한 경우
		{
			cout << "Invalid";
			return 0;
		}
		if (abs(stoi(beforeNum) - stoi(currentNum)) == 2) // 위 아래 방향으로 2칸 이동 후 90도 이동
		{
			if (abs((int)visit[i][0] - (int)visit[i + 1][0]) != 1)
			{
				cout << "Invalid";
				return 0;
			}
		}
		else if (abs((int)visit[i][0] - (int)visit[i + 1][0]) == 2) // 좌 우 방향으로 2칸 이동후 90도 이동
		{
			if (abs(stoi(beforeNum) - stoi(currentNum)) != 1)
			{
				cout << "Invalid";
				return 0;
			}
		}
		else // 나이트의 이동 방식이 아닌 경우
		{
			cout << "Invalid";
			return 0;
		}
	}
	cout << "Valid";
}