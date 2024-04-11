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

int n, m, k, nn;
int a[1024000];
int c[1024000];
VI g[1024000];
bool u[1024000];
int q[1024000];
int qb, qe;

int dfs(int k)
{
	qb = qe = 0;
	q[qe++] = k;
	u[k] = true;
	while (qb != qe)
	{
		int v = q[qb++];
		forn(i1, g[v].sz)
		{
			int i = g[v][i1];
			if (!u[i])
			{
				q[qe++] = i;
				u[i] = true;
			}
		}
	}
	return qe;
}

bool check(int r)
{
	qb = qe = 0;
	int j = 0;
	forn(i, r)
	{
		int k1, k2;
		if (qb >= qe || (j < n && a[j] < q[qb])) k1 = a[j++];
		else k1 = q[qb++];
		if (qb >= qe || (j < n && a[j] < q[qb])) k2 = a[j++];
		else k2 = q[qb++];
		q[qe++] = k1 + k2;
	}
	int w = 0;
	forn(i, n - r)
	{
		int k1;
		if (qb >= qe || (j < n && a[j] < q[qb])) k1 = a[j++];
		else k1 = q[qb++];
		c[w++] = min(k1, k);
	}
/*	cerr << r << endl;
	forn(i, w)
	{
		cerr << c[i] << " ";
	}
	cerr << endl;
*/
	if (w <= 2) return true;
	if (c[0] > 1) return true;
	int t = w - 1;
	j = 0;
	while (t > 0 && j < w && c[j] == 1)
	{
		if (c[t] > 2) c[t]--, j++;
		else t--;
	}
	int cnt = 0;
	For(i, j, w-1)
	{
		cnt += c[i] == 1;
	}
	return cnt <= 2;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d%d", &n, &m, &k);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	clr(u);
	nn = 0;
	forn(i, n)
	{
		if (!u[i])
		{
			a[nn++] = dfs(i);
		}
	}
	n = nn;
	sort(a, a+n);
/*	cerr << n << endl;
	forn(i, n)
	{
		cerr << a[i] << " ";
	}
	cerr << endl << endl;
*/
	int mi = 0;
	int ma = n - 1;
	while (mi < ma)
	{
		int q = (mi + ma) / 2;
		if (check(q))
		{
			ma = q;
		}
		else
		{
			mi = q + 1;
		}
	}

	printf("%d\n", mi);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}