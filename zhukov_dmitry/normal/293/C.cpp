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
char *g_g_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))
#define gets(s) (g_g_ = gets(s))

#ifdef ROOM_311
#	define _lld "%lld"
#else
#	define _lld "%I64d"
#endif

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

i64 n;
int k;
i64 a[1024000];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	cin >> n;
	if (n % 3 != 0)
	{
		puts("0");
		return 0;
	}
	n /= 3;
	k = 0;
	For(i, 1, 10000000)
	{
		i64 x = i;
		x *= x;
		if (x > n) break;
		if (n % i == 0)
		{
			a[k++] = i;
			if (x != n) a[k++] = n / i;
		}
	}
	sort(a, a + k);
	int cma = (int)(pow(n / 2.0, 1.0 / 3.0) + 1e-7);
	i64 ans = 0;
	a[k] = n + 1;
	For(c, 1, cma)
	{
		int bma = (int)(pow(n / 2.0 / c, 1.0 / 2.0) + 1e-7);
		i64 b = c;
		while (b <= bma)
//		For(b, c, bma)
		{
			if (n % (b + c) != 0)
			{
				int t = upper_bound(a, a + k, n / (b + c)) - a;
				if (t == 0) break;
				i64 y = a[t - 1];
				i64 nb = n / y - c;
				if (nb < b) nb = b + 1;
				b = nb;
				continue;
			}
			i64 bb = b + c;
			i64 cc = b * (i64)c - n / (b + c);
			i64 dd = bb * bb - 4LL * cc;
			i64 z = (int)(sqrt(dd) + 1e-7);
			i64 a = (-bb + z) / 2;
			if (a < b) break;
			if (z * z != dd) goto l1;
//			ans++;
//			cerr << a << " " << b << " " << c << endl;
			if (a != b && b != c) ans += 6;
			else if (a != b || b != c) ans += 3;
			else ans++;
l1:;
			b++;
		}
	}
	cout << ans << endl;
	
	return 0;
}