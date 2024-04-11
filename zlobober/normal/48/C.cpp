#include <iostream>
using namespace std;

#define double long double

struct seg
{
	double l, r;
	seg(double _l, double _r)
	{
		l = _l, r = _r;
	}
	friend seg operator /(const seg& a, double k)
	{
		return seg(a.l / k, a.r / k);
	}
	friend seg operator +(const seg& a, const seg& b)
	{
		return seg(max(a.l, b.l), min(a.r, b.r));
	}
};

const int N = 1010;
int A[N];
int n;

int _div(double a, double b)
{ 
	int l = 0, r = (min(a + b, (double)1000000.0)) + 2;
	while (l < r - 1)
		if (((l + r) / 2) * b <= a)
			l = (l + r) / 2;
		else
			r = (l + r) / 2;
	return l;
}

double _mod(double a, double b)
{
	return a - b * _div(a, b);
}

pair<int, double> go(double a)
{
	int cur = 0;
	double bak = a;

	for (int i = 1; i <= n + 1; i++)
	{
		cur += _div(bak, 10.0);
		bak = _mod(bak, 10.0) + a;
	}
	return make_pair(cur, bak);
}

const double EPS = 1e-10;

int main()
{
	//freopen("cin", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	seg ans(0, 1e20);

	for (int i = 2; i <= n; i++)
	{
		seg cur(10 * A[i], 10 * A[i] + 10);
		cur = cur / i;
		ans = ans + cur;
	}
	pair<int, double> anssl = go(ans.l);
	pair<int, double> anssr = go(ans.r - EPS);
	
	if (anssl.first != anssr.first)
		cout << "not unique";
	else
		cout << "unique" << endl << anssl.first;
}