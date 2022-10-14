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

typedef double ld;

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

int n, k, m;
int nn;
VI g[32];
int c[32][32];
ld a[256][256];
ld b[256][256];
ld z[256][256];
int xy[256][2];
double p[256];
double ans[256];

void mult(ld a[][256])
{
	int n = nn;
	forn(i, n)
	{
		forn(j, n)
		{
			b[i][j] = a[j][i];
		}
	}
	forn(i, n)
	{
		forn(j, n)
		{
			z[i][j] = 0.0;
//			double *p1 = a[i];
//			double *p2 = b[j];
			forn(k, n)
			{
//				z[i][j] += *p1++ * *p2++;
				z[i][j] += a[i][k] * b[j][k];
			}
			if (z[i][j] < 1e-30) z[i][j] = 0.0;
		}
	}
	memcpy(a, z, sizeof(z));
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	k = 0;
	int x1, x2;
	scanf("%d%d%d%d", &n, &m, &x1, &x2);
	x1--;
	x2--;
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	forn(i, n)
	{
		scanf("%lf", &p[i]);
	}
	forn(i, n)
	{
		forn(j, i + 1)
		{
			c[i][j] = c[j][i] = k;
			xy[k][0] = i;
			xy[k][1] = j;
			k++;
		}
	}
	clr(a);
	forn(i, k)
	{
		int x = xy[i][0];
		int y = xy[i][1];
		if (x == y)
		{
			a[i][i] = 1.0;
			continue;
		}
		ld px = p[x];
		ld py = p[y];
		ld qx = (1.0 - px) / g[x].sz;
		ld qy = (1.0 - py) / g[y].sz;
		forn(jx, g[x].sz + 1)
		{
			int xn = (jx == (int)g[x].sz) ? x : g[x][jx];
			ld vx = (jx == (int)g[x].sz) ? px : qx;
			forn(jy, g[y].sz + 1)
			{
				int yn = (jy == (int)g[y].sz) ? y : g[y][jy];
				ld vy = (jy == (int)g[y].sz) ? py : qy;
				int j = c[xn][yn];
				a[i][j] += vx * vy;
			}
		}
	}
	nn = k;
	forn(i, 50)
	{
		mult(a);
	}

	clr(p);
	p[c[x1][x2]] = 1.0;
	clr(ans);
	forn(i, k)
	{
		forn(j, k)
		{
			ans[i] += p[j] * a[j][i];
		}
	}
	forn(i, n)
	{
		if (i) putchar(' ');
		printf("%0.9lf", ans[c[i][i]]);
	}
	puts("");
	
/*      forn(i, 22)
	{
		cout << i + 1 << " " << i + 2 << endl;
	}*/
/*      forn(i, 22)
	{
		puts("0.99");
	}
*/
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}