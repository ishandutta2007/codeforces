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
const int MOD = 1000000007;

int n, k, l;
int a[1024];
char s[1024];
int d[1024];
int g[1024][1024][2];

void precalc()
{
	d[1] = 0;
	For(i, 2, 1023)
	{
		int z = __builtin_popcount(i);
		d[i] = d[z] + 1;
	}
}

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int rec(int pos, bool le, int sum)
{
	int &ans = g[pos][sum][le];
	if (ans >= 0) return ans;
	if (pos == l) return ans = (sum == 0);
	ans = 0;
	int ma = le ? 1 : a[pos];
	For(i, 0, ma)
	{
		if (sum - i >= 0)
			add(ans, rec(pos + 1, le || i < a[pos], sum - i));
	}
	return ans;
}

int calc(int sum)
{
	int ans = rec(0, false, sum);
	if (sum == 1) add(ans, MOD - 1);
//	cerr << sum << " " << ans << " " << l << endl;
	
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	precalc();
	scanf("%s", s);
	scanf("%d", &k);
	if (k == 0)
	{
		puts("1");
		return 0;
	}
	l = strlen(s);
	forn(i, l)
	{
		a[i] = s[i] - '0';
	}
	int ans = 0;
	memset(g, 0xff, sizeof(g));
	For(i, 1, l)
	{
		if (d[i] == k - 1)
		{
			add(ans, calc(i));
		}
	}
	printf("%d\n", ans);
	
	return 0;
}