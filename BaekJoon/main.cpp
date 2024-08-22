#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m; // 세로 가로
	cin >> n >> m;
	vector<string>* castle = new vector<string>[n]; // 배열에 맞게 시계방향으로 90도 회전으로 시작
	for (int i = 0; i < n; i++)
	{
		castle[i].resize(m);
	}
	string toward = "south"; // 시작 방향 남쪽
	int now[2] = { 0,0 }; // 가로 좌표, 세로 좌표
	while (true)
	{
		castle[now[0]][now[1]] = "visited"; // 방문 기록 남기기
		if (toward == "south") // 진행 방향 남쪽
		{
			if (now[0] + 1 >= n || castle[now[0] + 1][now[1]] == "visited") // 가장자리에 도달한 경우
			{
				if (now[1] + 1 >= m || castle[now[0]][now[1] + 1] == "visited") // 진행되야할 방향(동쪽)도 막힌 경우
				{
					break;
				}
				toward = "east";
				now[1]++;
			}
			else // 그냥 직진인 경우
			{
				now[0]++;
			}
		}
		else if (toward == "east") // 진행 방향 동쪽
		{
			if (now[1] + 1 >= m || castle[now[0]][now[1] + 1] == "visited") // 가장자리에 도달한 경우
			{
				if (now[0] - 1 < 0 || castle[now[0] - 1][now[1]] == "visited") // 진행되야할 방향(북쪽)도 막힌 경우
				{
					break;
				}
				toward = "north";
				now[0]--;
			}
			else // 그냥 직진인 경우
			{
				now[1]++;
			}
		}
		else if (toward == "north") // 진행 방향 북쪽
		{
			if (now[0] - 1 < 0 || castle[now[0] - 1][now[1]] == "visited") // 가장자리에 도달한 경우
			{
				if (now[1] - 1 < 0 || castle[now[0]][now[1] - 1] == "visited") // 진행되야할 방향(서쪽)도 막힌 경우
				{
					break;
				}
				toward = "west";
				now[1]--;
			}
			else // 그냥 직진인 경우
			{
				now[0]--;
			}
		}
		else if (toward == "west") // 진행 방향 서쪽
		{
			if (now[1] - 1 < 0 || castle[now[0]][now[1] - 1] == "visited") // 가장자리에 도달한 경우
			{
				if (now[0] + 1 >= n || castle[now[0] + 1][now[1]] == "visited") // 진행되야할 방향(남쪽)도 막힌 경우
				{
					break;
				}
				toward = "south";
				now[0]++;
			}
			else // 그냥 직진인 경우
			{
				now[1]--;
			}
		}
	}
	cout << now[0] << " " << now[1];
}