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
ld a[20][20];
ld d[1 << 20];

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
		forn(j, n)
		{
			double x;
			scanf("%lf", &x);
			a[i][j] = x;
		}
	}

	forn(i, 1 << n)
	{
		d[i] = 0.0;
	}

	d[(1 << n) - 1] = 1.0;
	ford(mask, 1 << n)
	{
		int cnt = 0;
		ld dd = d[mask];
		forn(i, n)
		{
			if (!(mask & (1 << i))) continue;
			forn(j, i)
			{
				if (!(mask & (1 << j))) continue;
				cnt++;
			}
		}
		forn(i, n)
		{
			if (!(mask & (1 << i))) continue;
			forn(j, i)
			{
				if (!(mask & (1 << j))) continue;
				int m1 = mask ^ (1 << i);
				d[m1] += dd * a[j][i] / cnt;
				int m2 = mask ^ (1 << j);
				d[m2] += dd * a[i][j] / cnt;
			}
		}
	}

	forn(i, n)
	{
		if (i) putchar(' ');
		printf("%0.10lf", (double)d[1 << i]);
	}
	puts("");

	return 0;
}