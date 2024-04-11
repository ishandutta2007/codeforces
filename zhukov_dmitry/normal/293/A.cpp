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

int n;
char s[2][2024000];
int c[2][2];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	l1:;
	if (scanf("%d", &n) != 1) return 0;
	scanf("%s", s[0]);
	scanf("%s", s[1]);
	clr(c);
	forn(i, n * 2)
	{
		c[s[0][i] - '0'][s[1][i] - '0']++;
	}
	forn(i, n)
	{
		int c0 = -1, c1 = -1;
		if (c[1][1] > 0)
		{
			c0 = 1;
			c[1][1]--;
		}
		else if (c[1][0] > 0)
		{
			c[1][0]--;
			c0 = 1;
		}
		else if (c[0][1] > 0)
		{
			c[0][1]--;
			c0 = 0;
		}
		else // if (c[0][0] > 0)
		{
			c[0][0]--;
			c0 = 0;
		}

		if (c[1][1] > 0)
		{
			c1 = 1;
			c[1][1]--;
		}
		else if (c[0][1] > 0)
		{
			c[0][1]--;
			c1 = 1;
		}
		else if (c[1][0] > 0)
		{
			c[1][0]--;
			c1 = 0;
		}
		else // if (c[0][0] > 0)
		{
			c[0][0]--;
			c1 = 0;
		}
		if (c0 != c1)
		{
			puts(c0 > c1 ? "First" : "Second");
			goto out;
		}
	}
	puts("Draw");
out:;
	goto l1;
	
	return 0;
}