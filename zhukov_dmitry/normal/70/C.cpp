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

struct tp{int x, y;};

int rev[102400];
map < PII, VI > z;
tp a[102400];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	int mx, my, n;
	scanf("%d%d%d", &mx, &my, &n);

	For(i, 1, 100000)
	{
		int x = i;
		int t[10];
		int k = 0;
		do
		{
			t[k++] = x % 10;
			x /= 10;
		}
		while (x);
		forn(j, k)
		{
			x = x * 10 + t[j];
		}
		rev[i] = x;
	}

	For(i, 1, my)
	{
		int p = i;
		int q = rev[i];
		int g = __gcd(p, q);
		p /= g;
		q /= g;
		z[mp(p, q)].pb(i);
	}

	i64 ans = 1000000000000000000LL;
	int ax = -1, ay = -1;
	multiset < int > y;

	For(i, 1, mx)
	{
		int p = i;
		int q = rev[i];
		int g = __gcd(p, q);
		p /= g;
		q /= g;
		const VI &b = z[mp(q, p)];
		forn(j, b.sz)
		{
			y.insert(b[j]);
		}
		while ((int)y.sz > n)
		{
			__typeof(y.begin()) it = y.end();
			it--;
			y.erase(it);
		}
		__typeof(y.begin()) it = y.end();
		it--;
		int cur_y = *it;
		if ((int)y.sz >= n)
		{
			if ((i64)i * cur_y < ans)
			{
				ans = (i64)i * cur_y;
				ax = i;
				ay = cur_y;
			}
		}
	}

	if (ax == -1) puts("-1");
	else printf("%d %d\n", ax, ay);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}