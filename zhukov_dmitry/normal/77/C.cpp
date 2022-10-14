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
typedef pair < i64, int > PII;

int n;
VI a[102400];
int k[102400];
int c[102400];
i64 d[102400];
bool u[102400];
int s;

void dfs(int v)
{
	u[v] = true;
	vector < i64 > z;
	i64 sum = 0;
	forn(i1, a[v].sz)
	{
		int i = a[v][i1];
		if (!u[i])
		{
			dfs(i);
			z.pb(d[i]);
			sum += c[i];
		}
	}
	int t = k[v] - (v != s);
	c[v] = t;
	int r = 0;
	if (t > (int)z.sz) r = t - z.sz, t = z.sz;
	d[v] = s != v;
	nth_element(z.begin(), z.begin() + t, z.end(), greater < i64 > () );
	forn(i, t)
	{
		d[v] += z[i];
		c[v]--;
	}
	int w = min((i64)r, sum);
	d[v] += w;
	c[v] -= w;
//      cerr << v << " " << r << " " << sum << " " << c[v] << " " << d[v] << endl;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d", &k[i]);
	}
	forn(i, n-1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	clr(u);
	clr(d);
	clr(c);
	scanf("%d", &s);
	s--;

	dfs(s);

	cout << d[s] * 2 << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}