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
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

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
template <typename T> void my_random_shuffle(T b, T e) { for(ssize_t i = 1; i < (e - b); i++) { swap(b[i], b[rand() % (i + 1)]); } }
#define random_shuffle my_random_shuffle
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

const int MOD = 1000000007;

int n, m;

#define MAXP 2000008
int a[MAXP * 2];
int b[((MAXP+1) >> 5) + 10];
int c[MAXP + 8];
int f[MAXP + 8];
int pk[MAXP + 8];

void gen_primes()
{
	memset(b, 0, sizeof(b));
	int sq = (int)(sqrt(MAXP) + 2);
	for(int j = 4; j <= MAXP; j += 2)
	{
		b[j >> 5] |= 1 << j;
		c[j] = 2;
	}
	for(int i=3; i<=sq; i+=2)
	{
		if (b[i >> 5] & (1 << i)) continue;
		int j = i * i;
		while (j <= MAXP)
		{
			b[j >> 5] |= 1 << j;
			c[j] = i;
			j += i * 2;
		}
	}
	b[1 >> 5] |= 1 << 1;
	for(int i=2; i<=MAXP; i++)
	{
		if (!(b[i >> 5] & (1 << i))) c[i] = i;
	}
}

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

inline void sub(int &a, int b)
{
	a -= b;
	if (a < 0) a += MOD;
}

int modpow(int a, int k)
{
	if (!k) return 1;
	int ans = modpow(a, k / 2);
	ans = ans * (u64)ans % MOD;
	if (k & 1) ans = ans * (u64)a % MOD;
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	gen_primes();
	clr(a);
	scanf("%d%d", &m, &n);
	pk[0] = 1;
	For(i, 1, n)
	{
		pk[i] = modpow(i, m);
	}
	int ans = 0;
	f[1] = 1;
	For(i, 2, n)
	{
		int x = c[i];
		int t = i / x;
		if (t % x == 0) f[i] = 0;
		else f[i] = -f[t];
	}
	For(i, 1, n)
	{
		if (!f[i]) continue;
		int t = 0;
		For(j, 1, n)
		{
			t += i;
			if (t > n) break;
			int cur = f[i] * pk[j];
			if (cur < 0) cur += MOD;
			add(a[t], cur);
			sub(a[t + i], cur);
		}
	}
	For(i, 1, n)
	{
		add(a[i], a[i - 1]);
		add(ans, (a[i] ^ i));
	}
	printf("%d\n", ans);
	
	return 0;
}