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

int n, m, st, en;
VI a[1024];
int e[1024][3];
int t[1024];
int c[1024];
i64 d[1024];
i64 dist[1024][1024];
i64 cost[1024][1024];
bool u[1024];

inline int getv(int i, int v)
{
	return e[i][0] == v ? e[i][1] : e[i][0];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	scanf("%d%d", &st, &en);
	st--;
	en--;
	forn(i, m)
	{
		forn(j, 3)
		{
			scanf("%d", &e[i][j]);
		}
		e[i][0]--;
		e[i][1]--;
		a[e[i][0]].pb(i);
		a[e[i][1]].pb(i);
	}
	forn(i, n)
	{
		scanf("%d%d", &t[i], &c[i]);
	}
	forn(i, n)
	{
		memset(d, 0x3f, sizeof(d));
		d[i] = 0;
		priority_queue < pair < i64, int >, vector < pair < i64, int > >, greater < pair < i64, int > > > q;
		clr(u);
		q.push(mp(0, i));
		while (!q.empty())
		{
			pair < i64, int > tmp = q.top();
			q.pop();
			int v = tmp.second;
			i64 dd = tmp.first;
			if (u[v]) continue;
			u[v] = true;
			forn(j1, a[v].sz)
			{
				int j = a[v][j1];
				int vn = getv(j, v);
				if (d[vn] > dd + e[j][2])
				{
					d[vn] = dd + e[j][2];
					q.push(mp(d[vn], vn));
				}
			}
		}
		forn(j, n)
		{
			dist[i][j] = d[j];
		}
	}
	
	memset(cost, 0x3f, sizeof(cost));
	forn(i, n)
	{
		cost[i][i] = 0;
		forn(j, n)
		{
			if (i == j)
			{
//				cerr << "0" << " ";
				continue;
			}
			if (dist[i][j] <= t[i])
			{
				cost[i][j] = c[i];
			}
//			cerr << cost[i][j] << " ";
		}
//		cerr << endl;
	}

	memset(d, 0x3f, sizeof(d));
	d[st] = 0;
	clr(u);
	forn(i2, n)
	{
		i64 mi = (i64)1e+18;
		int mj = -1;
		forn(j, n)
		{
			if (!u[j] && d[j] < mi)
			{
				mi = d[j];
				mj = j;
			}
		}
		if (mj == -1) break;
		u[mj] = true;
		forn(j, n)
		{
			if (d[j] > mi + cost[mj][j])
			{
				d[j] = mi + cost[mj][j];
			}
		}
	}
	if (d[en] > (i64)1e+17)
	{
		d[en] = -1;
	}
	cout << d[en] << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}