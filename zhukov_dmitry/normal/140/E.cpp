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

int n, m, p;
int l[1024000];
int cc[5024];
int c[5024][5024];
int f[5024][5024];
int t[1 << 21];
int e[1 << 20];
int z = 1 << 20;
int d[2][5024];
int fa[5024];

int mypow(int a, int k)
{
	if (!k) return 1;
	if (k == 1) return a;
	int ans = mypow(a, k/2);
	ans = (i64)ans * ans % p;
	if (k & 1) ans = (i64)ans * a % p;
	return ans;
}

void tadd(int x, int k)
{
	e[x] += k;
	t[x + z] = mypow(x, e[x]);
	x += z;
	x >>= 1;
	while (x)
	{
		t[x] = (i64)t[x * 2] * t[x * 2 + 1] % p;
		x >>= 1;
	}
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d%d%d", &n, &m, &p);
	clr(c);
	fa[0] = 1;
	For(i, 1, 5000)
	{
		fa[i] = (i64)fa[i-1] * i % p;
	}
	forn(i, 5010)
	{
		c[i][i] = c[i][0] = 1;
		For(j, 1, i-1)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
			if (c[i][j] >= p) c[i][j] -= p;
		}
	}
	clr(f);
	f[1][1] = 1;
	For(j, 2, 5010)
	{
		For(i, j, 5010)
		{
			f[j][i] = ((i64)f[j][i-1] * (j-1) + (i64)f[j-1][i-1]) % p;
		}
	}
	For(j, 2, 5010)
	{
		For(i, j, 5010)
		{
			f[j][i] = (i64)f[j][i] * fa[j] % p;
		}
	}
	forn(i, n)
	{
		scanf("%d", &l[i]);
	}
	clr(cc);
	forn(i, z * 2)
	{
		t[i] = 1;
	}
	forn(i, 5010)
	{
		cc[i] = t[1];
		if (i + 1 > m) break;
		int x = m - i;
		For(j, 2, x)
		{
			if (j * j > x) break;
			if (x % j == 0)
			{
				x /= j;
				int cnt = 1;
				while (x % j == 0) x /= j, cnt++;
				tadd(j, cnt);
			}
		}
		if (x > 1)
		{
			tadd(x, 1);
		}
		x = i + 1;
		For(j, 2, x)
		{
			if (j * j > x) break;
			if (x % j == 0)
			{
				x /= j;
				int cnt = 1;
				while (x % j == 0) x /= j, cnt++;
				tadd(j, -cnt);
			}
		}
		if (x > 1)
		{
			tadd(x, -1);
		}
	}
	
	clr(d);
	int sum = 0;
	For(j, 1, min(l[0], m))
	{
		sum += (d[0][j] = (i64)f[j][l[0]] * cc[j] % p);
		if (sum >= p) sum -= p;
	}
	For(i, 1, n-1)
	{
		int *d0 = d[(i - 1) % 2];
		int *d1 = d[i % 2];
		int ma = min(min(l[i-1], l[i]), m);
		int new_sum = 0;
		For(j, 1, ma)
		{
			d1[j] = (i64)sum * f[j][l[i]] % p * cc[j] % p;
			d1[j] = (d1[j] - (i64)d0[j] * f[j][l[i]]) % p;
			if (d1[j] < 0) d1[j] += p;
			new_sum += d1[j];
			if (new_sum >= p) new_sum -= p;
		}
		int m2 = min(m, l[i]);
		For(j, ma+1, m2)
		{
			d1[j] = (i64)sum * f[j][l[i]] % p * cc[j] % p;
			if (d1[j] < 0) d1[j] += p;
			new_sum += d1[j];
			if (new_sum >= p) new_sum -= p;
		}
		sum = new_sum;
	}
	printf("%d\n", sum);
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}