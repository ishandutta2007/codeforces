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

const int MOD = 1000000007;

int n;
char s[10240];
int val[102][102];
int d[76][1 << 20];

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
/*	int sum = 0;
	For(i, 1, 30)
	{
		int len = 32 - __builtin_clz(i);
		sum += len;
		fprintf(stderr, "%d %d\n", i, sum);
	}*/
	scanf("%d", &n);
	scanf("%s", s);
	forn(i, n)
	{
		For(j, i, n - 1)
		{
			int &x = val[i][j];
			x = 0;
			For(l, i, j)
			{
				x = x * 2 + s[l] - '0';
				if (x > 21) x = 21;
			}
			if (x > 20) x = 0;
		}
	}
	clr(d);
	int ans = 0;
	forn(i, n + 1)
	{
		add(d[i][0], 1);
		For(k, 1, 20)
		{
//			if (d[i][(1 << k) - 1])
//				cerr << i << " " << k << " " << d[i][(1 << k) - 1] << endl;
			add(ans, d[i][(1 << k) - 1]);
		}
		if (i == n) break;
		forn(mask, 1 << 20)
		{
			if (!d[i][mask]) continue;
			For(j, i, n - 1)
			{
				if (!val[i][j]) continue;
//				cerr << i << " " << j << " " << (val[i][j] - 1) << endl;
				add(d[j + 1][mask | (1 << (val[i][j] - 1))], d[i][mask]);
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}