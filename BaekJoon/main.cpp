#include <iostream>
#include <vector>
using namespace std;

void ChangeSwitch(vector<int>& switchNum, int num)
{
	if (switchNum[num] == 0)
	{
		switchNum[num] = 1;
	}
	else
	{
		switchNum[num] = 0;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> switchNum;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		switchNum.push_back(temp);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int gender, num;
		cin >> gender >> num;
		if (gender == 1) // 남성
		{
			int j = 1;
			while (true)
			{
				if (num * j <= switchNum.size())
				{
					ChangeSwitch(switchNum, num * j - 1);
					j++;
				}
				else
				{
					break;
				}
			}
		}
		else // 여성
		{
			ChangeSwitch(switchNum, num - 1);
			int j = 1;
			while (true)
			{
				if (num - j - 1 >= 0 && num + j - 1 < switchNum.size())
				{
					if (switchNum[num - j - 1] == switchNum[num + j - 1])
					{
						ChangeSwitch(switchNum, num - j - 1);
						ChangeSwitch(switchNum, num + j - 1);
					}
				}
				else
				{
					break;
				}
				j++;
			}
		}
	}
	if (switchNum.size() <= 20)
	{
		for (int i = 0; i < switchNum.size(); i++)
		{
			cout << switchNum[i] << " ";
		}
	}
	else
	{
		int j = 0;
		int k = 1;
		while (true)
		{
			if (k * 20 > switchNum.size())
			{
				for (int i = j; i < switchNum.size(); i++)
				{
					cout << switchNum[i] << " ";
				}
				break;
			}
			for (int i = j; i < k * 20; i++)
			{
				cout << switchNum[i] << " ";
			}
			j = k * 20;
			k++;
			cout << "\n";
		}
	}
}