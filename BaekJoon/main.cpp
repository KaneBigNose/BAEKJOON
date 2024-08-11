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
		if (right == true) // 오른쪽 방향
		{
			if (num[0] == 1) // 끝인 경우
			{
				num[1] += 1;
				right = false;
			}
			else // 중간인 경우
			{
				num[1] += 1;
				num[0] -= 1;
			}
		}
		else // 왼쪽 방향
		{
			if (num[1] == 1) // 끝인 경우
			{
				num[0] += 1;
				right = true;
			}
			else // 중간인 경우
			{
				num[0] += 1;
				num[1] -= 1;
			}
		}
	}
	cout << num[0] << "/" << num[1];
}