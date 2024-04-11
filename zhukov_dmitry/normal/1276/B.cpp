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

int n, m, st, en;
VI a[202400];
int c[202400];
int b[202400];
int mask[202400];
bool u[202400];

void dfs(int v, int col)
{
	if (v == st)
	{
		mask[col] |= 1;
		return;
	}
	if (v == en)
	{
		mask[col] |= 2;
		return;
	}
	u[v] = true;
	c[v] = col;
	for (int x : a[v])
	{
		if (u[x]) continue;
		dfs(x, col);
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		scanf("%d%d%d%d", &n, &m, &st, &en);
		st--;
		en--;
		forn(i, n)
		{
			a[i].clear();
			mask[i] = 0;
			b[i] = 0;
			c[i] = -1;
			u[i] = 0;
		}
		forn(i, m)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			a[x].pb(y);
			a[y].pb(x);
		}
		int cn = 0;
		forn(i, n)
		{
			if (i == st || i == en || u[i]) continue;
			dfs(i, cn++);
		}
		forn(i, n)
		{
//			cerr << c[i] << " ";
			if (i == st || i == en) continue;
			++b[c[i]];
		}
//		cerr << endl;
		int ca = 0, cb = 0;
		forn(i, cn)
		{
//			cerr << mask[i] << " ";
			if (mask[i] == 1) ca += b[i];
			if (mask[i] == 2) cb += b[i];
		}
//		cerr << endl;
		i64 ans = ca * (i64)cb;
		char buf[20] = {};
		int len = 0;
		i64 x = ans;
		do
		{
			buf[len++] = x % 10 + '0';
			x /= 10;
		}
		while (x);
		reverse(buf, buf + len);
		buf[len] = '\0';
		puts(buf);
	}
	
	return 0;
}