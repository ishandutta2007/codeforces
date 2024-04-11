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

const int MOD = 1000000007;

int n, m, k;
int a[102400][2];
int xs[202400];
int d[202400];
VI b[202400];
int t[1 << 20];
const int z = 1 << 19;

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

void tadd(int x, int k)
{
	x += z;
	while (x)
	{
		add(t[x], k);
		x >>= 1;
	}
}

int tsum(int l, int r)
{
	l += z;
	r += z;
	int ans = 0;
	while (l <= r)
	{
		if (l & 1) add(ans, t[l]);
		if (!(r & 1)) add(ans, t[r]);
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
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

	clr(t);
	scanf("%d%d", &m, &k);
	int tt = 0;
	xs[tt++] = 0;
	xs[tt++] = m;
	forn(i, k)
	{
		scanf("%d%d", &a[i][0], &a[i][1]);
		xs[tt++] = a[i][0];
		xs[tt++] = a[i][1];
	}
	sort(xs, xs+tt);
	tt = unique(xs, xs+tt) - xs;
	n = lower_bound(xs, xs+tt, m) - xs;
	forn(i, k)
	{
		forn(j, 2)
		{
			a[i][j] = lower_bound(xs, xs+tt, a[i][j]) - xs;
		}
		b[a[i][1]].pb(i);
	}
	clr(d);
	d[0] = 1;
	forn(i, n+1)
	{
		forn(j, b[i].sz)
		{
			int q = a[b[i][j]][0];
			add(d[i], tsum(q, i-1));
		}
		tadd(i, d[i]);
	}
	printf("%d\n", d[n] % MOD);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}