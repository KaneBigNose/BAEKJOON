#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int senario = 1;
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		vector<string> name;
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			string temp;
			getline(cin, temp);
			name.push_back(temp);
		}
		vector<char>* AB = new vector<char>[n];
		for (int i = 0; i < 2 * n - 1; i++)
		{
			int num;
			char temp;
			cin >> num >> temp;
			AB[num - 1].push_back(temp);
		}
		for (int i = 0; i < n; i++)
		{
			if (AB[i].size() == 1)
			{
				cout << senario << " " << name[i] << "\n";
			}
		}
		senario++;
	}
}