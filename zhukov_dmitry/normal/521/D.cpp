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

typedef double ld;

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

struct tfrac {
	i64 p, q;
};

bool operator < (const tfrac &l, const tfrac &r)
{
	ld diff = (l.p * (ld)r.q - r.p * (ld)l.q);
	if (diff < -1e18) return true;
	if (diff > 1e18) return false;
	return l.p * r.q - r.p * l.q < 0;
}

struct te {
	int t, num, coef;
	int idx;
	int diff;
	tfrac f;
};

int n, m, k;
int a[102400];
te e[102400];
int ma[102400];
VI g[102400];

void calc_f()
{
	forn(i, n)
	{
		if (e[i].t == 3)
		{
			e[i].f = { p : e[i].coef, q : 1 };
		}
		else
		{
			g[e[i].num].pb(i);
		}
	}
	forn(i, k)
	{
		sort(g[i].begin(), g[i].end(), [&] (const int &p1, const int &p2) { return e[p1].diff > e[p2].diff; });
		i64 sum = a[i];
		forn(j1, g[i].sz)
		{
			int j = g[i][j1];
			e[j].f = { p : sum + e[j].diff, q : sum };
			sum += e[j].diff;
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d%d", &k, &n, &m);
	forn(i, k)
	{
		scanf("%d", &a[i]);
		ma[i] = a[i] + 1;
	}
	forn(i, n)
	{
		scanf("%d%d%d", &e[i].t, &e[i].num, &e[i].coef);
		e[i].num--;
		e[i].idx = i;
		e[i].diff = e[i].coef - (e[i].t == 1 ? a[e[i].num] : 0);
		if (e[i].t == 1 && e[i].coef > ma[e[i].num])
		{
			ma[e[i].num] = e[i].coef;
		}
	}
	forn(i, n)
	{
		if (e[i].t == 1)
		{
			if (e[i].coef < ma[e[i].num])
			{
				swap(e[i], e[n - 1]);
				n--;
				i--;
			}
			else
			{
				ma[e[i].num]++;
			}
		}
	}
	m = min(m, n);

	calc_f();

	nth_element(e, e + m, e + n, [&] (const te &e1, const te &e2) { return e2.f < e1.f; });

	printf("%d\n", m);
	bool first = true;
	For(t, 1, 3)
	{
		forn(i, m)
		{
			if (e[i].t != t) continue;
			if (first) first = false;
			else putchar(' ');
			printf("%d", e[i].idx + 1);
		}
	}
	puts("");

	return 0;
}