#include<iostream>
using namespace std;
int main()
{
	char tmp;
	int a, b, c, d; 
	while (cin >> a >> tmp >> b >> c >> tmp >> d)
	{
		int x = a * 60 + b + c * 60 + d;
		x /= 2;
		int y = x / 60;
		int z = x % 60;
		if (y <= 9)cout << "0" << y;
		else cout << y;
		cout << ":";
		if (z <= 9)cout << "0" << z << endl;
		else cout << z << endl;
	}
}