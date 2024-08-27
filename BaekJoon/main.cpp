#include <iostream>
#include <string>
using namespace std;

int changetoint(char word)
{
	switch (word)
	{
	case 'A':
		return 1;
	case 'B':
		return 2;
	case 'C':
		return 3;
	case 'D':
		return 4;
	case 'E':
		return 5;
	case 'F':
		return 6;
	case 'G':
		return 7;
	case 'H':
		return 8;
	}
}

char changetochar(int num)
{
	switch (num)
	{
	case 1:
		return 'A';
	case 2:
		return 'B';
	case 3:
		return 'C';
	case 4:
		return 'D';
	case 5:
		return 'E';
	case 6:
		return 'F';
	case 7:
		return 'G';
	case 8:
		return 'H';
	}
}

void move(string& king, string& stone, int up, int right)
{
	string temp1, temp2;
	int king1, stone1;
	temp1 = king[1];
	temp2 = stone[1];
	king1 = stoi(temp1);
	stone1 = stoi(temp2);
	if (king1 + up > 8 || king1 + up < 1 || changetoint(king[0]) + right > 8 || changetoint(king[0]) + right < 1)
	{
		return;
	}
	if (changetoint(king[0]) + right == changetoint(stone[0]) && king1 + up == stone1)
	{
		if (stone1 + up > 8 || stone1 + up < 1 || changetoint(stone[0]) + right > 8 || changetoint(stone[0]) + right < 1)
		{
			return;
		}
		stone[0] = changetochar(changetoint(stone[0]) + right);
		stone[1] = stone[1] + up;
	}
	king[0] = changetochar(changetoint(king[0]) + right);
	king[1] = king[1] + up;
}

int main()
{
	string king, stone;
	int n;
	cin >> king >> stone >> n;
	for (int i = 0; i < n; i++)
	{
		string act;
		cin >> act;
		if (act == "R")
		{
			move(king, stone, 0, 1);
		}
		else if (act == "L")
		{
			move(king, stone, 0, -1);
		}
		else if (act == "T")
		{
			move(king, stone, 1, 0);
		}
		else if (act == "B")
		{
			move(king, stone, -1, 0);
		}
		else if (act == "RT")
		{
			move(king, stone, 1, 1);
		}
		else if (act == "LT")
		{
			move(king, stone, 1, -1);
		}
		else if (act == "RB")
		{
			move(king, stone, -1, 1);
		}
		else if (act == "LB")
		{
			move(king, stone, -1, -1);
		}
	}
	cout << king << "\n" << stone;
}