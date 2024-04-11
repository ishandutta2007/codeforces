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

const int INF = 0x3f3f3f3f;

int n;
VI a[256];
bool b[256][256];
int d[256][256];
bool u[256];
int col[256];

void dfs(int k, int s, int cc, int *d)
{
	u[k] = true;
	col[k] = cc;
	d[k] = s;
	forn(i1, a[k].sz)
	{
		int i = a[k][i1];
		if (u[i] || !b[k][i]) continue;
		dfs(i, s+1, cc, d);
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
	clr(b);
	forn(i, n-1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
		b[x][y] = b[y][x] = true;
	}

	int ans = 0;

	forn(i, n)
	{
		forn(j1, a[i].sz)
		{
			int j = a[i][j1];
			b[i][j] = b[j][i] = false;
			memset(d, 0x3f, sizeof(d));
			clr(u);
			dfs(i, 0, 0, d[i]);
			clr(u);
			dfs(j, 0, 1, d[j]);
			forn(k, n)
			{
				if (k == i || k == j) continue;
				clr(u);
				dfs(k, 0, col[k], d[k]);
			}

			int m1 = 0;
			forn(v1, n)
			{
				if (col[v1] != 0) continue;
				forn(v2, n)
				{
					if (col[v2] != 0) continue;
					m1 = max(m1, d[v1][v2]);
				}
			}
			int m2 = 0;
			forn(v1, n)
			{
				if (col[v1] != 1) continue;
				forn(v2, n)
				{
					if (col[v2] != 1) continue;
					m2 = max(m2, d[v1][v2]);
				}
			}
			ans = max(ans, m1 * m2);

			b[i][j] = b[j][i] = true;
		}
	}

	printf("%d\n", ans);

	return 0;
}