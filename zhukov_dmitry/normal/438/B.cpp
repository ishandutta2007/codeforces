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
int a[102400];
VI g[102400];
int pa[102400];
int c[102400];
int ind[102400];
int u[102400];
int t[102400];

int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
	if (rand() & 1) swap(x, y);

	pa[x] = y;
	c[y] += c[x];
}

bool cmp(int p1, int p2)
{
	return a[p1] > a[p2];
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	srand(1345214);
	scanf("%d%d", &n, &m);
	forn(i, n)
	{
		scanf("%d", &a[i]);
		pa[i] = i;
		ind[i] = i;
		c[i] = 1;
	}
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	memset(u, 0xff, sizeof(u));
	sort(ind, ind + n, cmp);
	i64 ans = 0;
	forn(i1, n)
	{
		int i = ind[i1];
		u[i] = i1;
		int tt = 0;
		forn(j1, g[i].sz)
		{
			int j = g[i][j1];
			if (u[j] < 0) continue;
			if (find(i) != find(j))
			{
//				if (u[pa[j]] < i1)
//				{
					u[pa[j]] = i1;
					t[tt++] = c[pa[j]];
//				}
				unite(pa[i], pa[j]);
			}
		}
/*		forn(j1, g[i].sz)
		{
			int j = g[i][j1];
			if (u[j] < 0) continue;
			if (find(i) != find(j))
			{
			}
		}*/
		i64 s2 = 0, s1 = 0;
//		cerr << "tt = " << tt << endl;
		forn(j, tt)
		{
//			cerr << t[j] << " ";
			s2 += t[j] * (i64)t[j];
			s1 += t[j];
		}
//		cerr << endl;
//		cerr << s1 << " " << s2 << endl;
		ans += (s1 * (i64)s1 - s2 + s1 * 2) * (i64)a[i];
	}
	printf("%0.9lf\n", ans * 1.0 / n / (n - 1));

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}