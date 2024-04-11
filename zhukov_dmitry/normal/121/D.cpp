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

FILE *g_f_;
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))

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
i64 k;
i64 a[2000000];
i64 l[102400];
i64 r[102400];
int indl[102400];
int indr[102400];
i64 cl[1024000];
i64 cr[1024000];

bool cmpl(int p1, int p2)
{
	return l[p1] > l[p2];
}

bool cmpr(int p1, int p2)
{
	return r[p1] < r[p2];
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	m = 0;
	For(i, 1, 18)
	{
		forn(j, 1 << i)
		{
			i64 t = 0;
			forn(k, i)
			{
				t = t * 10 + ((j & (1 << k)) ? 4 : 7);
			}
			a[m++] = t;
		}
	}
	sort(a, a+m);
#ifdef ROOM_311
	scanf("%d%lld", &n, &k);
#else
	scanf("%d%I64d", &n, &k);
#endif
	i64 mi = 2e18;
	forn(i, n)
	{
#ifdef ROOM_311
		scanf("%lld%lld", &l[i], &r[i]);
#else
		scanf("%I64d%I64d", &l[i], &r[i]);
#endif
		indl[i] = i;
		indr[i] = i;
		mi = min(mi, r[i] - l[i]);
	}
	sort(indl, indl+n, cmpl);
	sort(indr, indr+n, cmpr);
	memset(cl, 0x3f, sizeof(cl));
	memset(cr, 0x3f, sizeof(cr));
	int ans = 0;
	int ll = 0;
	i64 ss = 0;
	ford(i, m)
	{
		i64 x = a[i];
		if (ll * 1.0 * (a[i+1] - x) > 2e18) break;
		ss += ll * (a[i+1] - x);
		while (ll < n && l[indl[ll]] > x)
		{
			ss += l[indl[ll]] - x;
			ll++;
			if (ss > k) break;
		}
		if (ss > k) break;
		cl[i] = ss;
	}
	int rr = 0;
	ss = 0;
	forn(i, m)
	{
		i64 x = a[i];
		if (rr * 1.0 * (i ? (x - a[i-1]) : 0) > 2e18) break;
		ss += rr * (i ? (x - a[i-1]) : 0);
		while (rr < n && r[indr[rr]] < x)
		{
			ss += x - r[indr[rr]];
			rr++;
			if (ss > k) break;
		}
		if (ss > k) break;
		cr[i] = ss;
	}
	
	int j = 0;
	forn(i, m)
	{
		if (j < i) j = i;
		while (j + 1 < m && a[j + 1] - a[i] <= mi && cl[i] + cr[j + 1] <= k)
		{
			j++;
		}
		if (cl[i] + cr[j] <= k)
		{
			ans = max(ans, j - i + 1);
		}
	}
	
	cout << ans << endl;
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}