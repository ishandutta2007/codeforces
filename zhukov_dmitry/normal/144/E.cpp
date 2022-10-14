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

struct tp{int x,y,z,l,r;};

int n, m;
tp a[102400];
bool u[102400];
int t[1 << 18];
int z = 1 << 17;

bool operator < (tp p1, tp p2)
{
	if (p1.r != p2.r) return p1.r < p2.r;
	return p1.l < p2.l;
}

inline void tadd(int x, int k)
{
	x += z;
	while (x)
	{
		t[x] += k;
		x >>= 1;
	}
}

inline int tsum(int l, int r)
{
	l += z;
	r += z;
	int ans = 0;
	while (l <= r)
	{
		if (l & 1) ans += t[l];
		if (!(r & 1)) ans += t[r];
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		scanf("%d%d", &a[i].y, &a[i].x);
		a[i].x--;
		a[i].y = n - a[i].y;
		a[i].z = i;
		a[i].l = a[i].y;
		a[i].r = a[i].x;
	}
	clr(t);
	forn(i, n)
	{
		t[z + i] = 1;
	}
	Ford(i, z-1, 1)
	{
		t[i] = t[i * 2] + t[i * 2 + 1];
	}
	sort(a, a+m);
	int ans = 0;
	clr(u);
	forn(i, m)
	{
		if (!tsum(a[i].l, a[i].r)) continue;
		int x = z + a[i].l;
		while (!t[x])
		{
			if (x & 1) x++;
			else x = x / 2;
		}
		while (x < z)
		{
			if (t[x * 2]) x = x * 2;
			else x = x * 2 + 1;
		}
		tadd(x - z, -1);
		u[a[i].z] = true;
		ans++;
	}
	
	printf("%d\n", ans);
	bool ff = true;
	forn(i, m)
	{
		if (u[i])
		{
			if (!ff) putchar(' ');
			ff = false;
			printf("%d", i + 1);
		}
	}
	puts("");
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}