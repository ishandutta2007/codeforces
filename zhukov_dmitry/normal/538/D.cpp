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
char a[128][128];
bool ans[128][128];
bool g[128][128];

bool check(int dx, int dy)
{
	forn(i, n)
	{
		forn(j, n)
		{
			if (a[i][j] == 'o')
			{
				int x = i + dx;
				int y = j + dy;
				if (x < 0 || x >= n || y < 0 || y >= n) continue;
				if (a[x][y] == '.') return false;
			}
		}
	}
	return true;
}

void fill(int dx, int dy)
{
	forn(i, n)
	{
		forn(j, n)
		{
			if (a[i][j] == 'o')
			{
				int x = i + dx;
				int y = j + dy;
				if (x < 0 || x >= n || y < 0 || y >= n) continue;
				g[x][y] = true;
			}
		}
	}
}

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
		scanf("%s", a[i]);
	}
	clr(g);
	clr(ans);
	For(dx, -n + 1, n - 1)
	{
		For(dy, -n + 1, n - 1)
		{
			if (check(dx, dy))
			{
				ans[dx + n - 1][dy + n - 1] = true;
				fill(dx, dy);
			}
		}
	}
	forn(i, n)
	{
		forn(j, n)
		{
			if (a[i][j] == 'x' && !g[i][j])
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	forn(i, n * 2 - 1)
	{
		forn(j, n * 2 - 1)
		{
			putchar(i == n - 1 && j == n - 1 ? 'o' : ans[i][j] ? 'x' : '.');
		}
		puts("");
	}

	return 0;
}