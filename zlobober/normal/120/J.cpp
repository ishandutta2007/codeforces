#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long llong;



struct vt
{
	llong x, y;
	llong abs()
	{
		return x * x + y * y;
	}
	vt(llong  _x, llong _y)
	{
		x = _x, y = _y;
	}
	friend vt operator -(vt a, vt b)
	{
		return vt(a.x - b.x, a.y - b.y);
	}
	vt(){}
};

const llong INF = 1e8;

struct cmp
{
	vt O;
	cmp (vt _O)
	{
		O = _O;
	}
	bool operator ()(pair<vt, int> a, pair<vt, int> b)
	{
		return (a.first - O).abs() < (b.first - O).abs();
	}
};

const int N = 100000;
pair<vt, int> V[N];

int msk[N];

llong myrand()
{
	llong r = rand() * (RAND_MAX + 1) + rand();
	if (r < 0)
		r *= -1;
	return r;
}

int get(int m)
{
	return m + 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> V[i].first.x >> V[i].first.y;
		V[i].second = i;
		if (V[i].first.x < 0)
			V[i].first.x *= -1, msk[i] ^= 1;
		if (V[i].first.y < 0)
			V[i].first.y *= -1, msk[i] ^= 2;
	}
	sort(V, V + n, cmp(vt(myrand() % ((llong)2e9) - 1e9, myrand() % ((llong)2e9) - 1e9)));
	#define mp make_pair
	pair<llong, pair<int, int> > P(1e18, mp(-1, -1));
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < min(n, i + 800); j++)
		{
			P = min(P, mp((V[i].first - V[j].first).abs(), mp(V[i].second, V[j].second)));
		}
	}
	cout << P.second.first + 1 << ' ' << get(msk[P.second.first]) << ' ' << P.second.second + 1 << ' ' << get(3 ^ msk[P.second.second]);
}