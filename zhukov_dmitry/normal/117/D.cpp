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

i64 n, mid, mi, ma;
int m;
int p;

inline void g(i64 &l, i64 &r, i64 s, int k)
{
	i64 t = l;
	l = max(l, t + ((mi - s + (1LL << k) - 1) >> k));
	r = min(r, t + ((ma - s) >> k));
}

int f(i64 l, i64 r, i64 ll, i64 rr, i64 s, int k)
{
	if (l > rr || r < ll) return 0;
	if (l <= ll && r >= rr)
	{
//		cerr << l << " " << r << " " << ll << " " << rr << " " << s << " " << k << endl;
		l = ll;
		r = rr;
		g(l, r, s, k);
//		cerr << l << " " << r << endl;
		if (l > r) return 0;
		i64 k1 = s + ((l - ll) << k);
		i64 k2 = s + ((r - ll) << k);
		i64 kk = k1 + k2;
		i64 len = r - l + 1;
		if (kk % 2 == 0) kk /= 2;
		else len /= 2;
		return kk % p * (len % p) % p;
	}
	i64 mid = (ll + rr) / 2;
	int a1 = f(l, r, ll, mid, s, k + 1);
	int a2 = f(l, r, mid + 1, rr, s + (1LL << k), k + 1);
	return (a1 + a2) % p;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
#ifdef ROOM_311
	scanf("%lld%d%d", &n, &m, &p);
#else
	scanf("%I64d%d%d", &n, &m, &p);
#endif

	mid = (n + 1) / 2;

	forn(i, m)
	{
		i64 l, r;
#ifdef ROOM_311
		scanf("%lld%lld%lld%lld", &l, &r, &mi, &ma);
#else
		scanf("%I64d%I64d%I64d%I64d", &l, &r, &mi, &ma);
#endif
		l--;
		r--;
		int ans = f(l, r, 0, n-1, 1, 0);
//		cerr << endl;
		printf("%d\n", ans);
	}
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}