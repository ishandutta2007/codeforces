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

const int INF = 0x3f3f3f3f;

struct ts{int l,v,r; int idx;};

int n;
ts a[102400];
int b[1 << 20];
int tma[1 << 20];
int tpa[1 << 20];
const int z = 1 << 19;
int ind[102400];

bool operator < (ts s1, ts s2)
{
	return s1.l < s2.l;
}

void tadd(int v, int l, int r, int ll, int rr, int k)
{
	if (r < ll || l > rr) return;
	if (l <= ll && r >= rr)
	{
		b[v] += k;
		tma[v] += k;
		return;
	}
	b[v * 2] += b[v];
	b[v * 2 + 1] += b[v];
	tma[v * 2] += b[v];
	tma[v * 2 + 1] += b[v];
	b[v] = 0;
	tadd(v * 2, l, r, ll, (ll + rr) >> 1, k);
	tadd(v * 2 + 1, l, r, ((ll + rr) >> 1) + 1, rr, k);
	tma[v] = tma[v * 2];
	tpa[v] = tpa[v * 2];
	if (tma[v] < tma[v * 2 + 1])
	{
		tma[v] = tma[v * 2 + 1];
		tpa[v] = tpa[v * 2 + 1];
	}
}

PII tmax(int v, int l, int r, int ll, int rr)
{
	if (r < ll || l > rr) return mp(-INF, -1);
	if (l <= ll && r >= rr)
	{
		return mp(tma[v], tpa[v]);
	}
	PII p1 = tmax(v * 2, l, r, ll, (ll + rr) >> 1);
	PII p2 = tmax(v * 2 + 1, l, r, ((ll + rr) >> 1) + 1, rr);
	if (p1 < p2) p1 = p2;
	p1.first += b[v];
	return p1;
}

bool cmp(int p1, int p2)
{
	return a[p1].v < a[p2].v;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d%d%d", &a[i].l, &a[i].v, &a[i].r);
		a[i].idx = i;
		ind[i] = i;
	}
	clr(b);
	clr(tma);
	clr(tpa);
	forn(i, z)
	{
		tpa[z + i] = i;
	}
	Ford(i, z - 1, 1)
	{
		tpa[i] = tpa[i * 2];
	}
	sort(a, a + n);
	int ans = -INF;
	int al = -1;
	int ar = -1;
	sort(ind, ind + n, cmp);
	int k = 0;
	forn(i, n)
	{
		int j = i;
		while (j + 1 < n && a[j + 1].l == a[i].l) j++;
		For(l, i, j)
		{
			tadd(1, a[l].v, a[l].r, 0, z - 1, 1);
		}
		while (k < n && a[ind[k]].v < a[i].l)
		{
			int l = ind[k];
			tadd(1, a[l].v, a[l].r, 0, z - 1, -1);
			k++;
		}
		PII p = tmax(1, a[i].l, z - 1, 0, z - 1);
		if (ans < p.first)
		{
			ans = p.first;
			al = a[i].l;
			ar = p.second;
		}
		i = j;
	}
	printf("%d\n", ans);
	bool ff = true;
	forn(i, n)
	{
		if (a[i].l <= al && a[i].r >= ar && a[i].v >= al && a[i].v <= ar)
		{
			if (ff) ff = false;
			else putchar(' ');
			printf("%d", a[i].idx + 1);
		}
	}
	puts("");
	
	return 0;
}