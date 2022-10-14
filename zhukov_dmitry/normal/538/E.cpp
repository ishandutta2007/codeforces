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

#ifdef ROOM_311
time_t et_0;

__attribute__((constructor)) void init_main()
{
	et_0 = clock();
}

__attribute__((destructor)) void fini_main()
{
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
}
#endif

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
VI a[202400];

int dfs1(int v, int h)
{
	if (!a[v].sz) return 1;
	int z = (h & 1) ? 0 : 1e9;
	forn(i, a[v].sz)
	{
		int tmp = dfs1(a[v][i], h + 1);
		if (h & 1) z += tmp;
		else z = min(z, tmp);
	}
	return z;
}

int dfs2(int v, int h)
{
	if (!a[v].sz) return 1;
	int z = (h & 1) ? 1e9 : 0;
	forn(i, a[v].sz)
	{
		int tmp = dfs2(a[v][i], h + 1);
		if (!(h & 1)) z += tmp;
		else z = min(z, tmp);
	}
	return z;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	int m = 0;
	forn(i, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].pb(y);
	}
	forn(i, n)
	{
		if (!a[i].sz) m++;
	}
	int ans = dfs1(0, 0);
	printf("%d ", m - ans + 1);

	ans = dfs2(0, 0);

	printf("%d\n", ans);

	return 0;
}