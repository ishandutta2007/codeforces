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

const i64 INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m, k;
i64 d[128][128][128];
int c[128];
int p[128][128];

inline void upd_min(i64 &a, i64 b)
{
	if (a > b) a = b;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d%d", &n, &m, &k);
	memset(d, 0x3f, sizeof(d));
	forn(i, n)
	{
		scanf("%d", &c[i]);
	}
	forn(i, n)
	{
		forn(j, m)
		{
			scanf("%d", &p[i][j]);
		}
	}
	d[0][0][0] = 0;
	forn(i, n)
	{
		forn(j, k + 1)
		{
			forn(l, m + 1)
			{
				if (i && !l) continue;
				if (d[i][j][l] >= INF) continue;
				For(z, 1, m)
				{
					if (c[i] && z != c[i]) continue;
					int nj = j + (z != l);
					upd_min(d[i + 1][nj][z], d[i][j][l] + (c[i] == z ? 0 : p[i][z - 1]));
				}
			}
		}
	}
	i64 ans = INF;
	forn(i, m)
	{
		upd_min(ans, d[n][k][i + 1]);
	}
	if (ans >= INF) puts("-1");
	else printf("%lld\n", ans);
	
	return 0;
}