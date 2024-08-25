#include <iostream>
#include <vector>
using namespace std;

void MoveLeft(vector<int>& arr)
{
	int temp = arr[0];
	for (int i = 0; i < arr.size() - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	*(arr.end() - 1) = temp;
}

void MoveRight(vector<int>& arr)
{
	int temp = *(arr.end() - 1);
	for (int i = arr.size() - 1; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;
}

void PopFront(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr.pop_back();
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}
	vector<int> want;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		want.push_back(temp);
	}
	int countFinal = 0;
	for (int i = 0; i < m; i++)
	{
		vector<int> tempArrL = arr;
		vector<int> tempArrR = arr;
		int countL = 0;
		int countR = 0;
		while (true)
		{
			if (tempArrL[0] == want[i])
			{
				break;
			}
			MoveLeft(tempArrL);
			countL++;
		}
		while (true)
		{
			if (tempArrR[0] == want[i])
			{
				break;
			}
			MoveRight(tempArrR);
			countR++;
		}
		countFinal += countL > countR ? countR : countL;
		arr = tempArrL;
		PopFront(arr);
	}
	cout << countFinal;
}