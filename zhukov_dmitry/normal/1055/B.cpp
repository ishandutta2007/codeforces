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

int n, m, k;
i64 a[102400];
int pa[102400];

int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
	if (rand() & 1) swap(x, y);
	pa[x] = y;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d%d", &n, &m, &k);
	int ans = 0;
	forn(i, n)
	{
		int aa;
		scanf("%d", &aa);
		a[i] = aa;
		pa[i] = i;
		if (a[i] > k) ans++;
	}
	forn(i, n - 1)
	{
		if (a[i] > k && a[i + 1] > k)
		{
			int x = find(i);
			int y = find(i + 1);
			if (x != y)
			{
				unite(x, y);
				ans--;
			}
		}
	}
	forn(i, m)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)
		{
			printf("%d\n", ans);
		}
		else
		{
			int y, z;
			scanf("%d%d", &y, &z);
			y--;
			a[y] += z;
			if (a[y] > k && a[y] - z <= k)
			{
				ans++;
				for (int dy = -1; dy <= 1; dy += 2)
				{
					int t = y + dy;
					if (t < 0 || t >= n) continue;
					if (a[t] <= k) continue;
					int aa = find(y);
					int bb = find(t);
					if (aa != bb)
					{
						unite(aa, bb);
						ans--;
					}
				}
			}
		}
	}
	
	return 0;
}