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

int n, m;
char a[10][10];
bool u[1024][10][10];

void dfs(int k, int x, int y)
{
	if (k > 1020) return;
	u[k][x][y] = true;
	For(i, -1, 1)
	{
		For(j, -1, 1)
		{
			int xn = x + i;
			int yn = y + j;
			if (xn < 0 || xn >= n || yn < 0 || yn >= m || (xn - k >= 0 && a[xn - k][yn] == 'S') || (xn - k - 1 >= 0 && a[xn - k - 1][yn] == 'S') || u[k+1][xn][yn]) continue;
			dfs(k+1, xn, yn);
		}
	}
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	n = 8, m = 8;
	memset(a, '.', sizeof(a));
	forn(i, n)
	{
		scanf("%s", a[i]);
	}
	clr(u);

	dfs(0, n-1, 0);
	forn(i, 1024)
	{
		if (u[i][0][m-1])
		{
			puts("WIN");
			return 0;
		}
	}
	puts("LOSE");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}