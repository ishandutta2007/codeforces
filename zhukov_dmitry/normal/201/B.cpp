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
i64 a[1024][1024];
i64 x[1024];
i64 y[1024];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	clr(x);
	clr(y);
	i64 s = 0;
	forn(i, n)
	{
		forn(j, m)
		{
			int z;
			scanf("%d", &z);
			a[i][j] = z;
			s += z;
			x[i] += z;
			y[j] += z;
		}
	}
	i64 ans = 0;
	i64 xx = n * 2;
	i64 yy = m * 2;

	i64 ax = 0x3f3f3f3f3f3f3f3fLL;
	forn(i, n + 1)
	{
		i64 x0 = i * 2;
		i64 cur = 0;
		forn(j, n)
		{
			cur += x[j] * sqr(j * 2 + 1 - x0);
		}
		if (cur < ax)
		{
			ax = cur;
			xx = x0;
		}
	}
	i64 ay = 0x3f3f3f3f3f3f3f3fLL;
	forn(i, m + 1)
	{
		i64 y0 = i * 2;
		i64 cur = 0;
		forn(j, m)
		{
			cur += y[j] * sqr(j * 2 + 1 - y0);
		}
		if (cur < ay)
		{
			ay = cur;
			yy = y0;
		}
	}

	forn(i, n)
	{
		forn(j, m)
		{
			ans += a[i][j] * (sqr(i * 2 + 1 - xx) + sqr(j * 2 + 1 - yy));
		}
	}
	cout << ans * 4 << endl;
	cout << xx / 2 << " " << yy / 2 << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}