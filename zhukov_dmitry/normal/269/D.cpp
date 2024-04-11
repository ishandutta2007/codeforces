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
typedef pair < int, int > PII;

int n, k;
int a[102400][3];
VI g[102400];
VI b[102400];
int st, en;
int e[202400][4];
int ind[202400];
set < PII > cand;
set < PII > w;
set < PII > s;
int d[202400];

void add(int x, int y)
{
	if (x > y) swap(x, y);
	cand.insert(mp(x, y));
}

void del(int x, int y)
{
	if (x > y) swap(x, y);
	w.insert(mp(x, y));
}

bool cmp(int p1, int p2)
{
	if (e[p1][0] != e[p2][0]) return e[p1][0] < e[p2][0];
	if (e[p1][1] != e[p2][1]) return e[p1][1] > e[p2][1];
	return e[p1][2] < e[p2][2];
}

int dfs(int v)
{
	int &ans = d[v];
	if (ans >= 0) return ans;
	ans = 0;
	if (v == en) ans = 2000000001;
	forn(i, g[v].sz)
	{
		ans = max(ans, min(dfs(g[v][i]), b[v][i]));
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d%*d", &n);
	forn(i, n)
	{
		forn(j, 3)
		{
			scanf("%d", &a[i][j]);
		}
		a[i][2]--;
	}
	st = n;
	en = n + 1;
	a[st][0] = 1000000001;
	a[st][1] = -1000000000;
	a[st][2] = 1000000000 - 1;
	a[en][0] = 0;
	a[en][1] = -1000000000;
	a[en][2] = 1000000000 - 1;
	n += 2;

	k = 0;

	forn(i, n)
	{
		e[k][0] = a[i][1];
		e[k][1] = 1;
		e[k][2] = i;
		k++;
		e[k][0] = a[i][2];
		e[k][1] = -1;
		e[k][2] = i;
		k++;
	}

	forn(i, k)
	{
		ind[i] = i;
	}
	sort(ind, ind + k, cmp);

	s.clear();
	__typeof(s.begin()) it0, it1, it2;
	forn(i1, k)
	{
		int i = ind[i1];
		int v = e[i][2];
		int y = a[v][0];
		if (e[i][1] > 0)
		{
			it2 = s.lower_bound(mp(y, v));
			if (it2 != s.end() && it2 != s.begin())
			{
				it1 = it2;
				it1--;
				del(it1->second, it2->second);
			}
			s.insert(mp(y, v));
			it0 = s.find(mp(y, v));
			it1 = it0;
			it2 = it0;
			if (it1 != s.begin())
			{
				it1--;
				add(it0->second, it1->second);
			}
			it2++;
			if (it2 != s.end())
			{
				add(it0->second, it2->second);
			}
		}
		else
		{
			it0 = s.find(mp(y, v));
			it1 = it0;
			it2 = it0;
			if (it1 != s.begin())
			{
				it1--;
				add(it0->second, it1->second);
			}
			it2++;
			if (it2 != s.end())
			{
				add(it0->second, it2->second);
			}
			s.erase(mp(y, v));

			it2 = s.lower_bound(mp(y, v));
			if (it2 != s.end() && it2 != s.begin())
			{
				it1 = it2;
				it1--;
				del(it1->second, it2->second);
			}
		}
	}
	fori(it, w)
	{
		cand.erase(*it);
	}

	fori(it, cand)
	{
		int x = it->first;
		int y = it->second;
		if (a[x][0] < a[y][0]) swap(x, y);
		int l = min(a[x][2], a[y][2]) - max(a[x][1], a[y][1]) + 1;
		g[x].pb(y);
		b[x].pb(l);
	}
	
	memset(d, 0xff, sizeof(d));
	int ans = dfs(st);
	printf("%d\n", ans);

	return 0;
}