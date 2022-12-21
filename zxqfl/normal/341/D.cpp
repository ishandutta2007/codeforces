#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

#define TSIZE 1010

struct BIT
{
	ll arr[TSIZE][TSIZE];

	ll read(int x, int y)
	{
		ll ans = 0;
		for (int i = x; i > 0; i -= i & -i)
			for (int j = y; j > 0; j -= j & -j)
				ans ^= arr[i][j];
		return ans;
	}

	void update(int x, int y, ll v)
	{
		for (int i = x; i < TSIZE; i += i & -i)
			for (int j = y; j < TSIZE; j += j & -j)
				arr[i][j] ^= v;
	}
};

BIT t00, t01, t10, t11;

ll fullRead(int x, int y)
{
	if (x % 2 == 0)
	{
		if (y % 2 == 0)
			return t00.read(x, y);
		else
			return t01.read(x, y);
	}
	else
	{
		if (y % 2 == 0)
			return t10.read(x, y);
		else
			return t11.read(x, y);
	}
}

ll fullRead(int x1, int y1, int x2, int y2)
{
		int a[2], b[2];
		a[0] = x1 - 1;
		a[1] = x2;
		b[0] = y1 - 1;
		b[1] = y2;
		ll ans = 0;
		jij(2, 2) ans ^= fullRead(a[i], b[j]);
		return ans;
}

void fullUpdate(int x, int y, ll v)
{
	if (x % 2 == 0)
	{
		if (y % 2 == 0)
			t00.update(x, y, v);
		else
			t01.update(x, y, v);
	}
	else
	{
		if (y % 2 == 0)
			t10.update(x, y, v);
		else
			t11.update(x, y, v);
	}
}

void fullUpdate(int x1, int y1, int x2, int y2, ll v)
{
	fullUpdate(x1, y1, v);
	fullUpdate(x1, y2 + 1, v);
	fullUpdate(x2 + 1, y1, v);
	fullUpdate(x2 + 1, y2 + 1, v);
}

int main()
{
	nrint(N); nrint(M);
	jk(M)
	{
		nrint(typ);
		nrint(x1); x1 += 2;
		nrint(y1); y1 += 2;
		nrint(x2); x2 += 2;
		nrint(y2); y2 += 2;
		if (typ == 1)
			printf("%lld\n", fullRead(x1, y1, x2, y2));
		else
		{
			nrlong(v);
			fullUpdate(x1, y1, x2, y2, v);
		}
	}
}