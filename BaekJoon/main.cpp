#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> wantprice;
	vector<int> sellprice;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		wantprice.push_back(temp);
	}
	sort(wantprice.begin(), wantprice.end(), less<>());
	for (int i = 0; i < wantprice.size(); i++)
	{
		if (n >= m) // �ް��� ������ ������� ���ų� ���� ���
		{
			sellprice.push_back((wantprice.size() - i) * wantprice[i]);
		}
		else // �ް��� ������ ������� ���� ���
		{
			if (m - i < n)
			{
				sellprice.push_back((m - i) * wantprice[i]);
			}
			else
			{
				sellprice.push_back(n * wantprice[i]);
			}
		}
	}
	for (int i = 0; i < sellprice.size(); i++)
	{
		if (sellprice[i] == *max_element(sellprice.begin(), sellprice.end()))
		{
			cout << wantprice[i] << " " << sellprice[i];
			break;
		}
	}
}