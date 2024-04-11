#include<iostream>
#include<algorithm>
using namespace std;
int tim[110];
int main()
{
	int n; cin >> n; int t; cin >> t;
	for (int i = 1; i <= n; i++)
	{
		int a, b; cin >> a >> b;
		if (a >= t)tim[i] = a;
		else tim[i] = a + (t - a - 1) / b * b + b;
		//cout << tim[i] << endl;
	}
	int minn = 1e7;
	for (int i = 1; i <= n; i++)
	{
		minn = min(minn, tim[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (minn == tim[i])
		{
			cout << i << endl;
			return 0;
		}
	}
}