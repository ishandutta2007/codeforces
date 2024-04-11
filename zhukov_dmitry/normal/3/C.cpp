#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int u[20240];

int f(int a[][3])
{
	int x = 0;
	forn(i, 3)
	{
		forn(j, 3)
		{
			x = x * 3 + a[i][j];
		}
	}
	return x;
}

bool win(int a[][3], int s)
{
	forn(i, 3)
	{
		bool w = true;
		forn(j, 3)
		{
			if (a[i][j] != s) w = false;
		}
		if (w) return true;
	}
	forn(j, 3)
	{
		bool w = true;
		forn(i, 3)
		{
			if (a[i][j] != s) w = false;
		}
		if (w) return true;
	}
	bool w = true;
	forn(i, 3)
	{
		if (a[i][i] != s) w = false;
	}
	if (w) return true;
	w = true;
	forn(i, 3)
	{
		if (a[i][2-i] != s) w = false;
	}
	if (w) return true;
	return false;
}

void dfs(int x, int s)
{
	u[x] = s;
	int a[3][3];
	int y = x;
	bool bb = false;
	ford(i, 3)
	{
		ford(j, 3)
		{
			a[i][j] = y % 3;
			y /= 3;
		}
	}

	forn(i, 3)
	{
		forn(j, 3)
		{
			if (a[i][j]) continue;

			bb = true;
			a[i][j] = s;

			int t = f(a);
			if (!win(a, s))
			{
				if (!u[t]) dfs(t, 3-s);
			}
			else
			{
				u[t] = 10 + s;
			}

			a[i][j] = 0;
		}
	}

	if (!bb)
	{
		u[x] = 13;
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	int x = 0;
	int c1, c2;
	forn(i, 3)
	{
		char s[10];
		scanf("%s", s);
		forn(j, 3)
		{
			int y = 0;
			if (s[j] == 'X') y = 1, c1++;
			if (s[j] == '0') y = 2, c2++;
			x = x * 3 + y;
		}
	}

	clr(u);
	dfs(0, 1);

//	if (c1 < c2 || c1 > c2 + 1)
	if (!u[x])
	{
		puts("illegal");
	}
	if (u[x] == 1)
	{
		puts("first");
	}
	if (u[x] == 2)
	{
		puts("second");
	}
	if (u[x] == 11)
	{
		puts("the first player won");
	}
	if (u[x] == 12)
	{
		puts("the second player won");
	}
	if (u[x] == 13)
	{
		puts("draw");
	}

	return 0;
}