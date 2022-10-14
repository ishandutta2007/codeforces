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

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int n, m, k;
char a[1024][1024];
int c[1024][1024];
bool u[1024][1024];
bool u2[12];

void dfs(int x, int y, int px, int py)
{
	u[x][y] = true;
	int cnt = 0;
	forn(l, 4)
	{
		int xn = x + dx[l];
		int yn = y + dy[l];
		if (xn < 0 || xn >= n || yn < 0 || yn >= m || u[xn][yn] || a[xn][yn] == '#') continue;
		dfs(xn, yn, x, y);
		if (c[xn][yn] == -1) cnt++;
	}
	if (cnt)
	{
		forn(l, 4)
		{
			int xn = x + dx[l];
			int yn = y + dy[l];
			if (xn < 0 || xn >= n || yn < 0 || yn >= m || a[xn][yn] == '#' || c[xn][yn] != -1 || (xn == px && yn == py)) continue;
			c[xn][yn] = k;
		}
		c[x][y] = k++;
	}
}

void dfs2(int x, int y, int col)
{
	u[x][y] = true;
	forn(l, 4)
	{
		int xn = x + dx[l];
		int yn = y + dy[l];
		if (xn < 0 || xn >= n || yn < 0 || yn >= m || a[xn][yn] == '#') continue;
		if (c[xn][yn] == col)
		{
			if (!u[xn][yn]) dfs2(xn, yn, col);
		}
		else if (a[xn][yn] != '.')
		{
			u2[a[xn][yn] - '0'] = true;
		}
	}
}

void dfs3(int x, int y, int col, int nc)
{
	a[x][y] = '0' + nc;
	c[x][y] = -1;
	forn(l, 4)
	{
		int xn = x + dx[l];
		int yn = y + dy[l];
		if (xn < 0 || xn >= n || yn < 0 || yn >= m || a[xn][yn] == '#') continue;
		if (c[xn][yn] == col)
		{
			dfs3(xn, yn, col, nc);
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

	memset(c, 0xff, sizeof(c));
	scanf("%d%d", &n, &m);
	clr(a);
	forn(i, n)
	{
		scanf("%s", a[i]);
		a[i][m] = '\0';
	}
	clr(u);
	k = 0;
	forn(i, n)
	{
		forn(j, m)
		{
			if (!u[i][j] && a[i][j] != '#')
			{
				dfs(i, j, -1, -1);
				if (c[i][j] == -1)
				{
					bool bb = true;
					forn(l, 4)
					{
						int xn = i + dx[l];
						int yn = j + dy[l];
						if (xn < 0 || xn >= n || yn < 0 || yn >= m || a[xn][yn] == '#') continue;
						if (c[xn][yn] != -1)
						{
							c[i][j] = c[xn][yn];
							bb = false;
							break;
						}
					}
					if (bb)
					{
						puts("-1");
						return 0;
					}
				}
			}
		}
	}
	clr(u);
	forn(i, n)
	{
		forn(j, m)
		{
			if (a[i][j] == '.')
			{
				clr(u2);
				dfs2(i, j, c[i][j]);
				forn(t, 10)
				{
					if (!u2[t])
					{
						dfs3(i, j, c[i][j], t);
						break;
					}
				}
			}
		}
		puts(a[i]);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}