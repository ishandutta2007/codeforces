#include <stdio.h>
#include <bits/stdc++.h>

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
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

#ifdef ROOM_311
__attribute__((destructor)) void fini_main()
{
	fprintf(stderr, "Execution time = %0.0lf ms\n", clock() * 1000.0 / CLOCKS_PER_SEC);
}
#endif

#define MY_RAND 1
#if MY_RAND
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return (rnd_data >> 17) & 0x7FFFFFFF; }
#define rand my_rand
#define srand my_srand
template <typename T> void my_random_shuffle(T b, T e) { For(i, 1, (int)(e - b) - 1) { swap(b[i], b[rand() % (i + 1)]); } }
#define random_shuffle my_random_shuffle
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uin(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(b, a) ? a = b, true : false; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uax(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(a, b) ? a = b, true : false; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

const int MAXN = 2024;

const int m = 998244353;

int n, p, q;
int a[MAXN];
int d[MAXN][MAXN];
int g[MAXN][MAXN];
int ps[MAXN];
int qs[MAXN];

int modpow(int a, int k)
{
	if (!k) return 1 % m;
	int ans = modpow(a, k / 2);
	ans = ans * (i64)ans % m;
	if (k & 1) ans = ans * (i64)a % m;
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	int aa, bb;
	scanf("%d%d%d", &n, &aa, &bb);
	p = aa * (i64)modpow(bb, m - 2) % m;
	q = (1 - p + m) % m;
//	printf("p = %d, q = %d\n", p, q);
	ps[0] = 1;
	qs[0] = 1;
	For(i, 1, n)
	{
		ps[i] = ps[i - 1] * (i64)p % m;
		qs[i] = qs[i - 1] * (i64)q % m;
//		printf("ps[%d] = %d, qs[%d] = %d\n", i, ps[i], i, qs[i]);
	}
	clr(d);
	clr(g);
	d[1][1] = 1;
	g[1][0] = 1;
	g[1][1] = 1;
	For(i, 2, n)
	{
		g[i][0] = 1;
		For(j, 1, i)
		{
			g[i][j] = (g[i - 1][j] * (i64)ps[j] + g[i - 1][j - 1] * (i64)qs[i - j]) % m;
			if (j < i) d[i][j] = g[i][j] * (i64)d[j][j] % m;
		}
		d[i][i] = 1;
		For(j, 1, i - 1)
		{
			d[i][i] = (d[i][i] - d[i][j] + m) % m;
		}
	}
/*	For(i, 1, n)
	{
		printf("%d %d\n", i, d[i][i]);
	}*/
	a[1] = 0;
	For(i, 2, n)
	{
		a[i] = 0;
		For(j, 1, i - 1)
		{
			a[i] = (a[i] + d[i][j] * (i64)((j * (i - j) + j * (j - 1) / 2 + a[i - j] + a[j]) % m)) % m;
		}
		int z = (1 - d[i][i] + m) % m;
		int y = i * (i - 1) / 2;
		a[i] = (a[i] + y * (i64)d[i][i]) % m;
		a[i] = a[i] * (i64)modpow(z, m - 2) % m;
//		printf("a[%d] = %d\n", i, a[i]);
	}
	printf("%d\n", a[n]);
	
	return 0;
}