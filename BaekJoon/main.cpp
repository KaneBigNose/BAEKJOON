#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		string temp = to_string(i + 1);
		if (temp.size() == 1 || temp.size() == 2)
		{
			count++;
		}
		else
		{
			string a, b;
			a = temp[0];
			b = temp[1];
			int sub = stoi(a) - stoi(b);
			bool same = true;
			for (int j = 1; j < temp.size() - 1; j++)
			{
				a = temp[j];
				b = temp[j + 1];
				if (sub != stoi(a) - stoi(b))
				{
					same = false;
				}
				sub = stoi(a) - stoi(b);
			}
			if (same == true)
			{
				count++;
			}
		}
	}
	cout << count;
}