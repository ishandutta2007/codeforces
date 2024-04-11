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
template <class _T> inline string tostr(const _T &a) { ostringstream os(""); os << a; return os.str(); }

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

const int MAXQ = 10240000;

int n, c0, c1;
int q[MAXQ];

void solve2()
{
	int cc = c0 + c1;
	i64 ans = 0;
	clr(q);
	int k = 0;
	for (n--; n; k++)
	{
		while (k < c1 && k % c0) ++k;
		int add;
		if (k < c1)
		{
			add = 1;
		}
		else
		{
			while (!q[k - c1]) ++k;
			add = min(n, q[k - c1]);
		}
		ans += (k + cc) * (i64)add;
		int k1 = k + c0;
		int k2 = k + c1;
		if (k1 >= c1 && k1 - c1 < MAXQ) q[k1 - c1] += add;
		if (k2 >= c1 && k2 - c1 < MAXQ) q[k2 - c1] += add;
		n -= add;
	}
	printf("%lld\n", ans);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d%d%d", &n, &c0, &c1);
	if (c0 > c1) swap(c0, c1);
	if (!c0)
	{
		printf("%lld\n", c1 * (i64)(n - 1));
		return 0;
	}
	if (c1 / c0 > 1000000)
	{
		solve2();
		return 0;
	}
	map < i64, i64 > q;
	int cc = c0 + c1;
	n--;
	q[0] = 1;
	i64 ans = 0;
	while (n)
	{
		__typeof(q.begin()) it = q.begin();
		i64 k = it->first;
		int add = min((i64)n, it->second);
		q.erase(it);
		ans += (k + cc) * (i64)add;
		i64 k1 = k + c0;
		i64 k2 = k + c1;
		q[k1] += add;
		q[k2] += add;
		n -= add;
	}
	printf("%lld\n", ans);
	
	return 0;
}