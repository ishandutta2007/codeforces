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
typedef pair < i64, int > PII;

int n, m;
VI a[402400];
int e[402400][3];
i64 c[402400];
int ans[402400];
bool u[402400];
set < PII > w;

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d%d", &n, &m);
	clr(u);
	clr(c);
	forn(i, m)
	{
		forn(j, 3)
		{
			scanf("%d", &e[i][j]);
		}
		e[i][0]--;
		e[i][1]--;
	}
	forn(i, m)
	{
		e[i + m][0] = e[i][1];
		e[i + m][1] = e[i][0];
		e[i + m][2] = e[i][2];
	}
	forn(i, m + m)
	{
		a[e[i][0]].pb(i);
	}
	memset(ans, 0xff, sizeof(ans));
	forn(i, m)
	{
		int x = e[i][0];
		int y = e[i][1];
		if (x == 0)
		{
			ans[i] = 0;
			c[y] -= e[i][2];
		}
		else if (y == 0)
		{
			ans[i] = 1;
			c[x] -= e[i][2];
		}
		else
		{
			c[x] += e[i][2];
			c[y] += e[i][2];
		}
	}
	w.clear();
	For(i, 1, n - 2)
	{
		w.insert(mp(c[i], i));
	}
	u[0] = true;
	forn(i, n - 2)
	{
		PII tmp = *(w.begin());
		w.erase(w.begin());
		int v = tmp.second;
		if (tmp.first != 0) return 239;
		u[v] = true;
		forn(j1, a[v].sz)
		{
			int j = a[v][j1];
			int y = e[j][1];
			if (!u[y])
			{
				if (j < m) ans[j] = 0;
				else ans[j - m] = 1;
				if (y != n - 1)
				{
					w.erase(mp(c[y], y));
					c[y] -= 2 * e[j][2];
					w.insert(mp(c[y], y));
				}
			}
		}
	}

	forn(i, m)
	{
		if (ans[i] == -1) for(;;);
		printf("%d\n", ans[i]);
	}
	
	return 0;
}