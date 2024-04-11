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
typedef long long i64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

struct tp{int x,y;};
struct tz{int p,r,m; i64 d;};

int n;
tp p[252400];
tz z[252400];
int q[252400];
int qb, qe;
int zz;
PII t[1 << 19];

void tupdate(int x, int k)
{
	x += zz;
	t[x] = mp(k, x - zz);
	x >>= 1;
	while (x)
	{
		t[x] = min(t[x * 2], t[x * 2 + 1]);
		x >>= 1;
	}
}

PII tmin(int l, int r)
{
	PII ans = mp(0x7f7f7f7f, -1);
	l += zz;
	r += zz;
	while (l <= r)
	{
		if (l & 1) ans = min(ans, t[l]);
		if (!(r & 1)) ans = min(ans, t[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return ans;
}

bool operator < (tz z1, tz z2)
{
	return z1.d < z2.d;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	tp p0;
	tz z0;
	scanf("%d%d%d%d%d", &p0.x, &p0.y, &z0.p, &z0.r, &n);
	forn(i, n)
	{
		scanf("%d%d%d%d%d", &p[i].x, &p[i].y, &z[i].m, &z[i].p, &z[i].r);
		p[i].x -= p0.x;
		p[i].y -= p0.y;
		z[i].d = sqr((i64)p[i].x) + sqr((i64)p[i].y);
	}
	z[n].p = z0.p;
	z[n].r = z0.r;
	zz = 1 << 18;
	memset(t, 0x7f, sizeof(t));
	sort(z, z + n);
	forn(i, n)
	{
		t[zz + i] = mp(z[i].m, i);
	}
	Ford(i, zz - 1, 1)
	{
		t[i] = min(t[i * 2], t[i * 2 + 1]);
	}
	qb = qe = 0;
	q[qe++] = n;
	while (qb != qe)
	{
		int i = q[qb++], j;
		int mi = 0, ma = n;
		i64 rr = sqr((i64)z[i].r);
		PII tmp;
		while (mi < ma)
		{
			int q = (mi + ma) / 2;
			if (z[q].d > rr) ma = q;
			else mi = q + 1;
		}
		while ((j = (tmp = tmin(0, ma - 1)).second) != -1 && tmp.first <= z[i].p) tupdate((q[qe++] = j), 0x7f7f7f7f);
	}
	printf("%d\n", qe - 1);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}