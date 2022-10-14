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

const int MAXN = 1 << 17;

int n, k;
int a[MAXN];
bool g[MAXN];
int d[MAXN * 2][2][2];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &k);
	clr(g);
	forn(i, k)
	{
		scanf("%d", &a[i]);
		g[a[i] - 1] = true;
	}
	memset(d, 0x80, sizeof(d));
	int z = 1 << (n - 1);

	forn(i, z)
	{
		int x = i << 1;
		int y = x + 1;
		d[z + i][g[x]][g[y]] = g[x] || g[y];
		d[z + i][g[y]][g[x]] = g[x] || g[y];
	}
	Ford(i, z - 1, 1)
	{
		int x = i * 2;
		int y = x + 1;
		forn(xw, 2)
		{
			forn(xl, 2)
			{
				if (d[x][xw][xl] < 0) continue;
				forn(yw, 2)
				{
					forn(yl, 2)
					{
						if (d[y][yw][yl] < 0) continue;

						int gw[2] = {xw, yw};
						bool ggl = xl || yl;
						forn(t, 2)
						{
							int cur = (xw || yw) + ggl;
							int nw = gw[t];
							int nl0 = gw[t ^ 1];
							int nl = nl0 || ggl;
							cur += nl;
							uax(d[i][nw][nl], d[x][xw][xl] + d[y][yw][yl] + cur);
						}
					}
				}
			}
		}
	}

	int ans = 0;
	forn(i, 2)
	{
		forn(j, 2)
		{
			int add = (i || j);
			uax(ans, d[1][i][j] + add);
		}
	}

	printf("%d\n", ans);
	
	return 0;
}