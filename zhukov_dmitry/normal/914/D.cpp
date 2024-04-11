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

const int MAXN = 502400;

int n, m;
int a[MAXN];
const int z = 1 << 19;
int t[1 << 20];

void tinsert(int x, int y)
{
	x += z;
	t[x] = y;
	x >>= 1;
	while (x)
	{
		t[x] = __gcd(t[x * 2], t[x * 2 + 1]);
		x >>= 1;
	}
}

int upl(int l, int y)
{
	int v = l;
	v += z;
	if (t[v] % y != 0) return 0;
	for(;;)
	{
		if (v & 1)
		{
			if (t[v + 1] % y == 0) v++;
			else
			{
				if (v < z) v = v * 2 + 1;
				else return v - (l + z) + 1;
			}
		}
		else
		{
			if (t[v + 1] % y == 0) v >>= 1;
			else
			{
				if (v < z) v = v * 2 + 1;
				else return v - (l + z) + 1;
			}
		}
	}
	assert(false);
	return 0;
}

int upr(int r, int y)
{
	int v = r;
	v += z;
	if (t[v] % y != 0) return 0;
	for(;;)
	{
		if (v & 1)
		{
			if (t[v - 1] % y == 0) v >>= 1;
			else
			{
				if (v < z) v = v * 2;
				else return (r + z) - v + 1;
			}
		}
		else
		{
			if (t[v - 1] % y == 0) v--;
			else
			{
				if (v < z) v = v * 2;
				else return (r + z) - v + 1;
			}
		}
	}
	assert(false);
	return 0;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	clr(t);
	t[z + 0] = 1;
	forn(i, n)
	{
		scanf("%d", &a[i]);
		t[z + i + 1] = a[i];
	}
	t[z + n + 1] = 1;
	Ford(i, z - 1, 1)
	{
		t[i] = __gcd(t[i * 2], t[i * 2 + 1]);
	}
	scanf("%d", &m);
	forn(i, m)
	{
		int q;
		scanf("%d", &q);
		if (q == 1)
		{
			int l, r, y;
			scanf("%d%d%d", &l, &r, &y);
			if (y == 1)
			{
				puts("YES");
				continue;
			}
			int kl = upl(l, y);
			int kr = upr(r, y);
			puts((kl + kr >= r - l + 1 - 1) ? "YES" : "NO");
		}
		else
		{
			int x, y;
			scanf("%d%d", &x, &y);
			tinsert(x, y);
		}
	}
	
	return 0;
}