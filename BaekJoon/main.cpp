#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> A, B;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		B.push_back(temp);
	}
	sort(A.begin(), A.end(), less<>());
	sort(B.begin(), B.end(), greater<>());
	for (int i = 0; i < n; i++)
	{
		sum += A[i] * B[i];
	}
	cout << sum;
}