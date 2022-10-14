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
#	define _lld "%ll""d"
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

const i64 INF = 0x3f3f3f3f3f3f3f3fLL;

int n;
char buf[202400];
int bs = 0;
char *a[102400];
int c[102400];
i64 d[102400][2];
char s[102400];

bool check(char *a, bool ra, char *b, bool rb)
{
	if (ra) reverse(a, a + strlen(a));
	if (rb) reverse(b, b + strlen(b));
	bool res = strcmp(a, b) <= 0;
	if (ra) reverse(a, a + strlen(a));
	if (rb) reverse(b, b + strlen(b));
	return res;
}

inline void upd(i64 &a, i64 b)
{
	if (a > b) a = b;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d", &c[i]);
	}
	forn(i, n)
	{
		scanf("%s", s);
		int len = strlen(s);
		a[i] = buf + bs;
		bs += len + 1;
		strcpy(a[i], s);
	}
	memset(d, 0x3f, sizeof(d));
	d[0][0] = 0;
	d[0][1] = c[0];
	For(i, 1, n - 1)
	{
		forn(j, 2)
		{
			forn(k, 2)
			{
				if (check(a[i - 1], j, a[i], k))
				{
					upd(d[i][k], d[i - 1][j] + k * c[i]);
				}
			}
		}
	}
	i64 ans = INF;
	forn(i, 2)
	{
		upd(ans, d[n - 1][i]);
	}
	if (ans >= INF) puts("-1");
	else printf(_lld"\n", ans);
	
	return 0;
}