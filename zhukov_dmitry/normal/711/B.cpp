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

int n;
i64 a[512][510];

int main()
{
#ifdef ROOM_311
	freopen("input2.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	forn(i, n)
	{
		forn(j, n)
		{
			scanf("%lld", &a[i][j]);
		}
	}
	if (n == 1)
	{
		puts("1");
		return 0;
	}
	int x = 0, y = 0;
	forn(i, n)
	{
		forn(j, n)
		{
			if (!a[i][j])
			{
				x = i;
				y = j;
			}
		}
	}
	forn(i, n)
	{
		if (i == x) continue;
		i64 sum = 0;
		forn(j, n)
		{
			sum += a[i][j];
			sum -= a[x][j];
		}
		if (sum <= 0)
		{
			puts("-1");
			return 0;
		}
		a[x][y] = sum;
		break;
	}
	i64 sum = 0;
	forn(i, n)
	{
		sum += a[0][i];
	}
	forn(i, n)
	{
		i64 cur = 0;
		forn(j, n)
		{
			cur += a[i][j];
		}
		if (cur != sum)
		{
			puts("-1");
			return 0;
		}
	}
	forn(i, n)
	{
		i64 cur = 0;
		forn(j, n)
		{
			cur += a[j][i];
		}
		if (cur != sum)
		{
			puts("-1");
			return 0;
		}
	}
	{
		i64 cur = 0;
		forn(j, n)
		{
			cur += a[j][j];
		}
		if (cur != sum)
		{
			puts("-1");
			return 0;
		}
	}
	{
		i64 cur = 0;
		forn(j, n)
		{
			cur += a[n - j - 1][j];
		}
		if (cur != sum)
		{
			puts("-1");
			return 0;
		}
	}
	printf("%lld\n", a[x][y]);
	
	return 0;
}