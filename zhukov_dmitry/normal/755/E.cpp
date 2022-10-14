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
const ld EPS = 1e-9;


int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	int n, k;
	scanf("%d%d", &n, &k);
	if (n < 4) puts("-1");
	else if (n == 4)
	{
		if (k != 3) puts("-1");
		else puts("3\n1 2\n2 3\n3 4");
	}
	else if (k == 2)
	{
		printf("%d\n", n - 1);
		forn(i, n - 1)
		{
			printf("%d %d\n", i + 1, i + 2);
		}
	}
	else if (k == 3)
	{
		printf("%d\n", 3 + (n - 4) * 2);
		puts("1 2\n2 3\n3 4");
		For(i, 5, n)
		{
			printf("%d %d\n", 2, i);
			printf("%d %d\n", 3, i);
		}
	}
	else puts("-1");

	return 0;
}