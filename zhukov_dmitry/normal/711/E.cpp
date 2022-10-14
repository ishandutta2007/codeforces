#include "bits/stdc++.h"

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
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }

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
const ld EPS = 1e-11;

const int MOD = 1000003;

i64 n, k;

int mypow(int a, i64 k)
{
	if (!k) return 1;
	int ans = mypow(a, k / 2);
	ans = ans * (i64)ans % MOD;
	if (k & 1) ans = ans * (i64)a % MOD;
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%lld%lld", &n, &k);
	if (n < 63 && (1LL << n) < k)
	{
		puts("1 1");
		return 0;
	}
	i64 k2 = (k - 1) >> 1;
	i64 c2 = n;
	while (k2) c2 += k2, k2 >>= 1;
	const int MOD1 = MOD - 1;
	i64 e2 = (n % MOD1 * (k % MOD1) % MOD1 - c2) % MOD1;
	if (e2 < 0) e2 += MOD1;
	i64 p = 1, q = mypow(2, e2);
	i64 p2 = mypow(2, n);
	for (i64 i = 0; i < k; i++)
		if (!((p *= p2--) %= MOD)) break;
	(p *= mypow(2, MOD - 1 - c2 % MOD1)) %= MOD;
	p = (q - p) % MOD;
	if (p < 0) p += MOD;

	printf("%lld %lld\n", p, q);

	return 0;
}