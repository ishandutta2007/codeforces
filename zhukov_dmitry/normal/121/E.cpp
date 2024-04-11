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

const int Z = 1440;

int n, m, w;
int b[102];
int a[102400];
int c[102400];
char s[10240];
int cnt[102400 / Z + 1][10002];
bool u[10240];

void update(int ll)
{
	int s = ll * Z;
	clr(cnt[ll]);
	forn(i, Z)
	{
		++cnt[ll][a[s + i] += c[ll]];
	}
	c[ll] = 0;
}

void add(int l, int r, int z)
{
	int ll = l / Z;
	int rr = r / Z;
	if (ll == rr)
	{
		For(i, l, r)
		{
			a[i] += z;
		}
		update(ll);
	}
	else
	{
		For(i, ll+1, rr-1)
		{
			c[i] += z;
		}
		int l1 = ll * Z + Z - 1;
		For(i, l, l1)
		{
			a[i] += z;
		}
		int r1 = rr * Z;
		For(i, r1, r)
		{
			a[i] += z;
		}
		update(ll);
		update(rr);
	}
}

int calc(int l, int r)
{
	int ans = 0;
	int ll = l / Z;
	int rr = r / Z;
	if (ll == rr)
	{
		For(i, l, r)
		{
			ans += u[a[i] + c[ll]];
		}
	}
	else
	{
		For(i, ll+1, rr-1)
		{
			forn(j, w)
			{
				if (b[j] - c[i] >= 0) ans += cnt[i][b[j] - c[i]];
			}
		}
		int l1 = ll * Z + Z - 1;
		For(i, l, l1)
		{
			ans += u[a[i] + c[ll]];
		}
		int r1 = rr * Z;
		For(i, r1, r)
		{
			ans += u[a[i] + c[rr]];
		}
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
	
	w = 0;
	For(i, 1, 4)
	{
		forn(j, 1 << i)
		{
			int t = 0;
			forn(k, i)
			{
				t = t * 10 + ((j & (1 << k)) ? 4 : 7);
			}
			b[w++] = t;
		}
	}
	sort(b, b+w);
	clr(u);
	forn(i, w)
	{
		u[b[i]] = true;
	}
	scanf("%d%d", &n, &m);
	clr(a);
	clr(c);
	forn(i, n)
	{
		scanf("%d", &a[i]);
	}
	n = (n + Z - 1) / Z * Z;
	int nz = n / Z;
	forn(i, nz)
	{
		update(i);
	}
	forn(i, m)
	{
		scanf("%s", s);
		if (*s == 'c')
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			printf("%d\n", calc(x, y));
		}
		else
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			x--;
			y--;
			add(x, y, z);
		}
	}
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}