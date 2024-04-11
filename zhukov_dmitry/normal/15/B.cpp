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

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		i64 n, m, x1, y2, x2, y1;
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &m, &n, &x1, &y1, &x2, &y2);
		swap(x1, y1);
		swap(x2, y2);

		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);

		i64 xx = x2 - x1;
		i64 yy = y2 - y1;

		i64 ans = xx * yy * 2;
		if (xx*2 > n || yy*2 > m)
		{
			ans = (i64)n * m - (i64)(n - xx) * (m - yy) * 2;
		}

		printf("%I64d\n", ans);
	}

	return 0;
}