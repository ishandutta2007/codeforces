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

int n, m;
int a[102400];
int a0[102400];
int d[102400];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	d[0] = 1;
	d[m + 1] = n;
	forn(i, m + 2)
	{
		a[i] = 0x3f3f3f3f;
	}
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i + 1] = y;
		a0[i + 1] = y;
		d[i + 1] = x;
	}
	forn(i, m + 1)
	{
		a[i + 1] = min(a[i + 1], a[i] + (d[i + 1] - d[i]));
	}
	ford(i, m + 1)
	{
		a[i] = min(a[i], a[i + 1] + (d[i + 1] - d[i]));
	}
	int ans = 0;
	For(i, 1, m)
	{
		if (a[i] != a0[i])
		{
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	forn(i, m + 2)
	{
		ans = max(ans, a[i]);
		if (i < m + 1)
		{
			int z = d[i + 1] - d[i];
			int y = abs(a[i + 1] - a[i]);
			int x = max(a[i], a[i + 1]) + (z - y) / 2;
			ans = max(ans, x);
		}
	}
	printf("%d\n", ans);

	return 0;
}