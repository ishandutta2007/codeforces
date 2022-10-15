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

int n;
int a[2048][2];
i64 d[2048][4048];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d%d", &a[i][0], &a[i][1]);
	}
	memset(d, 0x3f, sizeof(d));
	
	d[0][2020] = 0;

	forn(i, n)
	{
		forn(j, 4021)
		{
			if (j)
			{
				d[i+1][j-1] = min(d[i+1][j-1], d[i][j]);
			}
			int jn = j + a[i][0];
			if (jn > 4020) jn = 4020;
			d[i+1][jn] = min(d[i+1][jn], d[i][j] + a[i][1]);
		}
	}

	i64 ans = 0x3f3f3f3f3f3f3f3fLL;

	forn(i, 2001)
	{
		ans = min(ans, d[n][2020 + i]);
	}

	printf("%I64d\n", ans);

	return 0;
}