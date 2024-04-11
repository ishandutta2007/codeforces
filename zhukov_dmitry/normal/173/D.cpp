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

int n, m;
VI a[102400];
bool c[102400];
bool u[102400];
bool u2[102400];
int ans[102400];
int cl;

void dfs(int v, bool cc)
{
	c[v] = cc;
	u[v] = true;
	forn(i, a[v].sz)
	{
		if (!u[a[v][i]])
		{
			dfs(a[v][i], !cc);
		}
	}
}

bool solve12()
{
//	int k1 = cl;
	int k2 = n - cl;
	int mi = 10000000;
	int mj = -1;
	forn(i, n)
	{
		if (c[i])
		{
			if ((int)a[i].sz < mi)
			{
				mi = a[i].sz;
				mj = i;
			}
		}
	}

	if (mi <= k2 - 2)
	{
		clr(u);
		u[mj] = true;
		clr(u2);
		ans[mj] = 0;
		forn(i, a[mj].sz)
		{
			u2[a[mj][i]] = true;
		}
		int cnt = 0;
		forn(i, n)
		{
			if (!c[i] && !u2[i])
			{
				cnt++;
				u[i] = true;
				ans[i] = 0;
				if (cnt == 2) break;
			}
		}

		int c0 = 0, c1 = 0;
		int k = 1;
		int cur0 = 0, cur1 = 0;
		forn(i, n)
		{
			if (u[i]) continue;
			if (c[i])
			{
				if (c0 == 0) cur0 = k++;
				if (++c0 == 3) c0 = 0;
				ans[i] = cur0;
			}
			else
			{
				if (c1 == 0) cur1 = k++;
				if (++c1 == 3) c1 = 0;
				ans[i] = cur1;
			}
		}
		return true;
	}

	return false;
}

bool solve2211() // 1122
{
	forn(i, n)
	{
		c[i] = !c[i];
	}
	cl = n - cl;
//	int k1 = cl;
	int k2 = n - cl;
	int mi = 10000000;
	int mj1 = -1;
	int mj2 = -1;
	forn(i, n)
	{
		if (c[i])
		{
			if ((int)a[i].sz < mi)
			{
				mi = a[i].sz;
				mj1 = i;
			}
		}
	}
	mi = 10000000;
	forn(i, n)
	{
		if (i == mj1) continue;
		if (c[i])
		{
			if ((int)a[i].sz < mi)
			{
				mi = a[i].sz;
				mj2 = i;
			}
		}
	}

	if (mi <= k2 - 2)
	{
		clr(u);
		u[mj1] = true;
		u[mj2] = true;
		ans[mj1] = 0;
		ans[mj2] = 1;
		clr(u2);
		forn(i, a[mj1].sz)
		{
			u2[a[mj1][i]] = true;
		}
		int cnt = 0;
		forn(i, n)
		{
			if (!c[i] && !u2[i])
			{
				cnt++;
				u[i] = true;
				ans[i] = 0;
				if (cnt == 2) break;
			}
		}
		clr(u2);
		forn(i, a[mj2].sz)
		{
			u2[a[mj2][i]] = true;
		}
		cnt = 0;
		forn(i, n)
		{
			if (!c[i] && !u2[i])
			{
				cnt++;
				u[i] = true;
				ans[i] = 1;
				if (cnt == 2) break;
			}
		}

		int c0 = 0, c1 = 0;
		int k = 2;
		int cur0 = 0, cur1 = 0;
		forn(i, n)
		{
			if (u[i]) continue;
			if (c[i])
			{
				if (c0 == 0) cur0 = k++;
				if (++c0 == 3) c0 = 0;
				ans[i] = cur0;
			}
			else
			{
				if (c1 == 0) cur1 = k++;
				if (++c1 == 3) c1 = 0;
				ans[i] = cur1;
			}
		}
		return true;
	}

	return false;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	clr(u);
	forn(i, n)
	{
		if (!u[i])
		{
			dfs(i, true);
		}
	}

	cl = 0;
	forn(i, n)
	{
		cl += c[i];
	}
	if (cl % 3 == 0)
	{
		int c0 = 0, c1 = 0;
		int k = 0;
		int cur0 = 0, cur1 = 0;
		forn(i, n)
		{
			if (c[i])
			{
				if (c0 == 0) cur0 = k++;
				if (++c0 == 3) c0 = 0;
				ans[i] = cur0;
			}
			else
			{
				if (c1 == 0) cur1 = k++;
				if (++c1 == 3) c1 = 0;
				ans[i] = cur1;
			}
		}
	}
	else
	{
		if (cl % 3 == 2)
		{
			forn(i, n)
			{
				c[i] = !c[i];
			}
			cl = n - cl;
		}
		if (!solve12() && !solve2211())
		{
			puts("NO");
			return 0;
		}
	}

	puts("YES");
	forn(i, n)
	{
		printf("%d%c", ans[i] + 1, " \n"[i == n-1]);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}