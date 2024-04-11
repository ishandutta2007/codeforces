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

FILE *g_f_;
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))

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

int n, m, st;
VI a[102400];
int e[102400][3];
int d[102400];
bool u[102400];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d%d%d", &n, &m, &st);
	st--;
	forn(i, m)
	{
		scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
		e[i][0]--;
		e[i][1]--;
		a[e[i][0]].pb(i);
		a[e[i][1]].pb(i);
		e[i][0] ^= e[i][1];
	}
	int l;
	scanf("%d", &l);
	clr(u);
	priority_queue < PII, vector < PII >, greater < PII > > q;
	memset(d, 0x3f, sizeof(d));
	d[st] = 0;
	q.push(mp(d[st], st));
	while (!q.empty())
	{
		PII tmp = q.top();
		q.pop();
		int v1 = tmp.second;
		int dd = tmp.first;
		if (u[v1]) continue;
		u[v1] = true;
		forn(i1, a[v1].sz)
		{
			int i = a[v1][i1];
			int v2 = v1 ^ e[i][0];
			if (d[v2] > dd + e[i][2])
			{
				d[v2] = dd + e[i][2];
				q.push(mp(d[v2], v2));
			}
		}
	}
	
	int ans = 0;
	forn(i, n)
	{
		if (d[i] == l) ans++;
	}
	forn(i, m)
	{
		e[i][0] ^= e[i][1];
		int v1 = e[i][0];
		int v2 = e[i][1];
		
		if (d[v1] < l && d[v1] + e[i][2] > l)
		{
			if (d[v2] + (e[i][2] - (l - d[v1])) >= l) ans++;
		}
		if (d[v2] < l && d[v2] + e[i][2] > l)
		{
			if (d[v1] + (e[i][2] - (l - d[v2])) > l) ans++;
		}
	}
	
	printf("%d\n", ans);
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}