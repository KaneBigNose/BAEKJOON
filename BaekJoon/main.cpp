#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	double a[2], b[2], c[2]; // 세 점
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
	double ab, bc, ca; // 기울기
	ab = (a[1] - b[1]) / (a[0] - b[0]);
	bc = (b[1] - c[1]) / (b[0] - c[0]);
	ca = (a[1] - c[1]) / (a[0] - c[0]);
	if (ab == bc && bc == ca)
	{
		cout << "-1";
		return 0;
	}
	vector<double> x, y;
	double sangsuAB = c[1] - ab * c[0];
	double sangsuBC = a[1] - bc * a[0];
	double sangsuCA = b[1] - ca * b[0];
	x.push_back((sangsuBC - sangsuAB) / (ab - bc)); // ab와 bc의 교집합
	x.push_back((sangsuCA - sangsuBC) / (bc - ca)); // bc와 ac의 교집합
	x.push_back((sangsuCA - sangsuAB) / (ca - ab)); // ab와 ac의 교집합
	y.push_back(ab * x[0] + sangsu1); // ab의 기울기에 c를 지남
	y.push_back(ca * x[1] + sangsu2); // ab의 기울기에 c를 지남
	y.push_back(bc * x[2] + sangsu3); // ab의 기울기에 c를 지남
	for (int i = 0; i < 3; i++)
	{
		cout << x[i] << " " << y[i] << "\n";
	}
	vector<double> length;
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		sum += sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2)); // ab의 길이
		sum += sqrt(pow(b[0] - c[0], 2) + pow(b[1] - c[1], 2)); // bc의 길이
		sum += sqrt(pow(c[0] - x[0], 2) + pow(c[1] - y[1], 2)); // cd의 길이
		sum += sqrt(pow(x[0] - a[0], 2) + pow(y[1] - a[1], 2)); // da의 길이
		length.push_back(sum);
	}
	cout << *max_element(length.begin(), length.end()) - *min_element(length.begin(), length.end());
}