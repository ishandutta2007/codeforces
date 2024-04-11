#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int n, k, m;
int a[202400];
int e[202400];
int b[202400][2];
int z = 1 << 18;
int xs[202400];
int l[202400];
int r[202400];
int c[202400];
int t[1 << 19];
int ans[202400];
int ind[202400];
int up[202400];
int tp[202400];

bool cmp1(int p1, int p2)
{
	return a[p1] < a[p2];
}

bool cmp2(int p1, int p2)
{
	return up[p1] > up[p2];
}

void tadd(int x, int k)
{
	x += z;
	while (x)
	{
		t[x] += k;
		x >>= 1;
	}
}

int tsum(int l, int r)
{
	l += z;
	r += z;
	int ans = 0;
	while (l <= r)
	{
		if (l & 1) ans += t[l];
		if (!(r & 1)) ans += t[r];
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return ans;
}

void tinsert(int x, int k)
{
	x += z;
	while (x)
	{
		t[x] = max(t[x], k);
		x >>= 1;
	}
}

int tmax(int l, int r)
{
	l += z;
	r += z;
	int ans = -1;
	while (l <= r)
	{
		if (l & 1) ans = max(ans, t[l]);
		if (!(r & 1)) ans = max(ans, t[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &k);
	forn(i, n)
	{
		scanf("%d", &a[i]);
	}
	forn(i, n)
	{
		scanf("%d", &e[i]);
		xs[i] = e[i];
	}
	sort(xs, xs + n);
	int nn = unique(xs, xs + n) - xs;

	forn(i, n)
	{
		l[i] = lower_bound(xs, xs + nn, e[i] - k) - xs;
		r[i] = upper_bound(xs, xs + nn, e[i] + k) - xs - 1;
		e[i] = lower_bound(xs, xs + nn, e[i]) - xs;
	}
	scanf("%d", &m);
	forn(i, m)
	{
		forn(j, 2)
		{
			scanf("%d", &b[i][j]);
			b[i][j]--;
		}
	}

	forn(i, n)
	{
		ind[i] = i;
	}
	sort(ind, ind + n, cmp1);

	clr(t);
	forn(i1, n)
	{
		int i = ind[i1];
		int j1 = i1;

		while (j1 + 1 < n && a[ind[j1 + 1]] == a[i]) j1++;
		For(l1, i1, j1)
		{
			int l = ind[l1];
			tadd(e[l], 1);
		}
		For(l1, i1, j1)
		{
			int ll = ind[l1];
			c[ll] = tsum(l[ll], r[ll]);
		}

		i1 = j1;
	}

	forn(i, m)
	{
		up[i] = max(a[b[i][0]], a[b[i][1]]);
		tp[i] = -i - 1;
	}
	forn(i, n)
	{
		up[i + m] = a[i];
		tp[i + m] = i;
	}

	forn(i, m + n)
	{
		ind[i] = i;
	}
	sort(ind, ind + n + m, cmp2);

	memset(t, 0xff, sizeof(t));
	forn(i1, n + m)
	{
		int i = ind[i1];
		int j1 = i1;

		while (j1 + 1 < n + m && up[ind[j1 + 1]] == up[i]) j1++;

		For(l1, i1, j1)
		{
			int l = ind[l1];
			if (tp[l] >= 0)
			{
				l = tp[l];
				tinsert(e[l], c[l]);
			}
		}
		For(l1, i1, j1)
		{
			int ll = ind[l1];
			if (tp[ll] < 0)
			{
				ll = -tp[ll] - 1;
				int k1 = b[ll][0];
				int k2 = b[ll][1];
				int le = max(l[k1], l[k2]);
				int ri = min(r[k1], r[k2]);
				if (le <= ri)
				{
					ans[ll] = tmax(le, ri);
				}
				else
				{
					ans[ll] = -1;
				}
			}
		}

		i1 = j1;
	}

	forn(i, m)
	{
		printf("%d\n", ans[i]);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}