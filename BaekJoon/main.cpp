#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int GroupNum = 1;
	while (true)
	{
		bool everybody = true;
		int n;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		vector<string> name;
		vector<char>* PN = new vector<char>[n];
		for (int i = 0; i < n; i++)
		{
			string temp;
			cin >> temp;
			name.push_back(temp);
			for (int j = 0; j < n - 1; j++)
			{
				char message;
				cin >> message;
				PN[i].push_back(message);
			}
		}
		cout << "Group " << GroupNum << "\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (PN[i][j] == 'N')
				{
					if (i - (j + 1) < 0)
					{
						cout << name[i - (j + 1) + n] << " was nasty about ";
					}
					else
					{
						cout << name[i - (j + 1)] << " was nasty about ";
					}
					cout << name[i] << "\n";
					everybody = false;
				}
			}
		}
		if (everybody == true)
		{
			cout << "Nobody was nasty\n";
		}
		cout << "\n";
		GroupNum++;
	}
}