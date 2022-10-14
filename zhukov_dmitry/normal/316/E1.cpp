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

const int MOD = 1000000000;

int n, m;
int a[102400];
int f[102400];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	f[0] = f[1] = 1;
	For(i, 2, 100000)
	{
		f[i] = f[i - 1] + f[i - 2];
		f[i] -= (f[i] >= MOD) * MOD;
	}
	forn(i, n)
	{
		scanf("%d", &a[i]);
		a[i] %= MOD;
	}
	forn(i, m)
	{
		int k;
		scanf("%d", &k);
		if (k == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			a[x] = y;
		}
		else if (k == 2)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			r--;
			int ans = 0;
			For(i, l, r)
			{
				ans = (ans + a[i] * (i64)f[i - l]) % MOD;
			}
			printf("%d\n", ans);
		}
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}