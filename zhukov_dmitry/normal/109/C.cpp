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

int n;
VI a[102400];
VI b[102400];
i64 ans;
int c[102400];
int d[102400];
bool u[102400];

void dfs0(int v)
{
	u[v] = true;
	d[v] = 1;
	c[v] = 0;
	forn(i, a[v].sz)
	{
		if (u[a[v][i]]) continue;
		dfs0(a[v][i]);
		d[v] += d[a[v][i]];
		c[v] += b[v][i] ? d[a[v][i]] : c[a[v][i]];
	}
}

void dfs(int v, int s)
{
	u[v] = true;
	int x = s;
	forn(i, a[v].sz)
	{
		if (u[a[v][i]]) continue;
		x += b[v][i] ? d[a[v][i]] : c[a[v][i]];
	}
//	cerr << v + 1 << " " << s << " " << x << endl;
//	cerr << v + 1 << " " << (i64)x * (x-1) << endl;
	ans += (i64)x * (x-1);
	forn(i, a[v].sz)
	{
		if (u[a[v][i]]) continue;
		if (b[v][i]) dfs(a[v][i], n - d[a[v][i]]);
		else dfs(a[v][i], s + c[v] - c[a[v][i]]);
	}
}

int g[128][128];

void dfsd(int v, int v0, int s)
{
	u[v] = true;
	g[v][v0] = s;
	forn(i, a[v].sz)
	{
		if (u[a[v][i]]) continue;
		dfsd(a[v][i], v0, s || b[v][i]);
	}
}

int dull()
{
	clr(g);
	forn(i, n)
	{
		clr(u);
		dfsd(i, i, 0);
	}
	
	int ans = 0;
	forn(i, n)
	{
		int tt = 0;
		forn(j, n)
		{
//			cerr << g[i][j];
			forn(k, n)
			{
				if (i == j || i == k || j == k) continue;
				tt += g[i][j] && g[i][k];
			}
		}
		ans += tt;
//		cerr << i + 1 << " " << tt << endl;
	}
//	cerr << endl;
	return ans;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, n - 1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		bool bb = true;
		while (z)
		{
			bb = bb && (z % 10 == 4 || z % 10 == 7);
			z /= 10;
		}
		a[x].pb(y);
		b[x].pb(bb);
		a[y].pb(x);
		b[y].pb(bb);
	}
	ans = 0;

	clr(u);
	dfs0(0);
/*	forn(i, n)
	{
		cerr << c[i] << " ";
	}
	cerr << endl;
	forn(i, n)
	{
		cerr << d[i] << " ";
	}
	cerr << endl;*/
//	cerr << "dull = " << dull() << endl;
	clr(u);
	dfs(0, 0);
	
	cout << ans << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}