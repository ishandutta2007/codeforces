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
typedef long long i64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int n, m, k;
VI a[102400];
int c[102400];
bool u[102400];
int e[1024];
int d[102400];
int dn[102400];
int t[102400];
int ok[102400 / 32];

int dfs(int v)
{
	u[v] = true;
	int ans = 1;
	
	forn(i, a[v].sz)
	{
		if (!u[a[v][i]])
		{
			ans += dfs(a[v][i]);
		}
	}
	
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	time_t t0 = clock();

	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	clr(u);
	clr(ok);
	k = 0;
	forn(i, n)
	{
		if (!u[i]) c[k++] = dfs(i);
	}
	sort(c, c+k, greater < int > () );

	int z = 0;
	For(i, 1, 5)
	{
		forn(j, 1 << i)
		{
			int t = 0;
			forn(l, i)
			{
				t = t * 10 + ((j & (1 << l)) ? 4 : 7);
			}
			e[z++] = t;
		}
	}
	forn(i, z)
	{
		ok[e[i] >> 5] |= 1 << e[i];
	}

	memset(d, 0x3f, sizeof(d));
	memset(dn, 0x3f, sizeof(dn));
	d[0] = 0;
	dn[0] = 0;
	int tt = 0;
	t[tt++] = 0;
	int ans = 10000000;
	forn(i, k)
	{
		int tn = tt;
		forn(j, tt)
		{
			int x = t[j] + c[i];
			if (dn[x] > d[t[j]] + 1)
			{
				if (dn[x] > n) t[tn++] = x;
				dn[x] = d[t[j]] + 1;
			}
		}
		tt = tn;
		forn(i, tn)
		{
			d[t[i]] = dn[t[i]];
			if ((ok[t[i] >> 5] & (1 << t[i])) && d[t[i]] - 1 < ans) ans = d[t[i]] - 1;
		}
		time_t t1 = clock();
		if (t1 - t0 > 0.6 * CLOCKS_PER_SEC) break;
	}
	forn(i, k)
	{
		if (ok[c[i] >> 5] & (1 << c[i])) ans = 0;
	}
	if (ans > 200000) ans = -1;
	printf("%d\n", ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}