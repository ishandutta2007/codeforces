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

const int INF = 0x7f7f7f7f;

int n, m;
VI a[202400];
int u[202400];
int tin[202400];
PII tup[202400][2];
int tt;
int pa[202400];
int ans[3][202400];
int ca[3];

inline void upd(int v, PII up)
{
	if (up < tup[v][0])
	{
		tup[v][1] = tup[v][0];
		tup[v][0] = up;
	}
	else if (up < tup[v][1])
		tup[v][1] = up;
}

int go_up(int v1, int v2, int *p)
{
	int cnt = 0;
	while (v1 != v2)
	{
		p[cnt++] = v1;
		v1 = pa[v1];
	}
	p[cnt++] = v2;
	return cnt;
}

void dfs(int v, int prev)
{
	u[v] = 1;
	tin[v] = tt++;
	for(int i : a[v])
	{
		if (i == prev) continue;
		if (!u[i])
		{
			pa[i] = v;
			dfs(i, v);
			upd(v, tup[i][0]);
			upd(v, tup[i][1]);
		}
		else if (u[i] == 1)
		{
			upd(v, mp(tin[i], v));
		}
	}
	if (tup[v][1].first < tin[v])
	{
		puts("YES");
		int st = v;
		int e0 = -1;
		int e1 = -1;
		forn(i, n)
		{
			if (tin[i] == tup[v][0].first) e0 = i;
			if (tin[i] == tup[v][1].first) e1 = i;
		}
		ca[2] = go_up(st, e1, ans[2]);

		ca[0] = go_up(e1, e0, ans[0]);
		ca[0] += go_up(tup[v][0].second, st, ans[0] + ca[0]);
		reverse(ans[0], ans[0] + ca[0]);

		ca[1] = go_up(e1, e1, ans[1] + ca[1]);
		ca[1] += go_up(tup[v][1].second, st, ans[1] + ca[1]);
		reverse(ans[1], ans[1] + ca[1]);

		forn(i, 3)
		{
			printf("%d", ca[i]);
			forn(j, ca[i])
			{
				printf(" %d", ans[i][j] + 1);
			}
			puts("");
		}
		exit(0);
	}
	u[v] = 2;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

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
	memset(tin, 0x7f, sizeof(tin));
	memset(tup, 0x7f, sizeof(tup));
	tt = 0;
	forn(i, n)
	{
		if (!u[i])
		{
			dfs(i, -1);
		}
	}
	puts("NO");

	return 0;
}