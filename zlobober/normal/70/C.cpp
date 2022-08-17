#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;

//#define TASK ""

const int N = 100500;

int gcd(int a, int b)
{
	while (b)
		a %= b, swap(a, b);
	return a;
}

struct rat
{
	int en, de;
	rat(){}
	void sokr()
	{
		int g = gcd(en, de);
		en /= g;
		de /= g;
	}
	rat(int _en, int _de) : en(_en), de(_de)
	{ sokr(); }
	friend bool operator <(rat a, rat b)
	{
		return (a.de == b.de) ? a.en < b.en : a.de < b.de;
	}
};

int rev(int x)
{
	int G[8];
	int pt = 0;
	while (x)
		G[pt++] = x % 10, x /= 10;
	x = 0;
	for (int i = 0; i < pt; i++)
		x = 10 * x + G[i];
	return x;
}
pair<rat, int> S[N];
void count()
{
	int en, de;
	for (int x = 1; x <= N; x++)
	{
		en = x;
		de = rev(x);
		S[x - 1] = (make_pair(rat(en, de), x));
	}
	sort(S, S + N);
}

int col(int x, int mx)
{
	if (x == 0)
		return 0;
	int rx = rev(x);
	rat r(rx, x);
	pair<rat, int>* it2 = upper_bound(S, S + N, make_pair(r, mx));
	pair<rat, int>* it1 = lower_bound(S, S + N, make_pair(r, 0));
	return it2 - it1;
}

typedef long long llong;

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int mxx, mxy, w;
	cin >> mxx >> mxy >> w;
	int x = mxx + 1, y = 0;
	llong cur = 0;
	pair<llong, pair<int, int> > pr(1e14, make_pair(-1, -1));
	count();
	while (x > 0)
	{
		cur -= col(x, y);
		x--;
		while (cur < w && y <= mxy)
			y++, cur += col(y, x);
		if (y > mxy)
			break;
		pr = min(pr, make_pair((llong)x * (llong)y, make_pair(x, y)));
	}
	cerr << pr.first << endl;
	if (pr.first >= 1e14)
		cout << -1;
	else
		cout << pr.second.first << ' ' << pr.second.second;
	return 0;
	return 0;
}