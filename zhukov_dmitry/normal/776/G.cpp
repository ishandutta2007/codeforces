#pragma GCC optimize("Ofast")
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

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

i64 d[16][16][2][16];
int t[16][16];
int dma[1 << 16];

void precalc()
{
	clr(t);
	forn(i, 1 << 16)
	{
		int x = i;
		int ma = 0;
		forn(j, 4)
		{
			int z = x & 15;
			ma = max(ma, z);
			x >>= 4;
		}
		dma[i] = ma;
		forn(j, 16)
		{
			if (i & (1 << j)) t[ma][j]++;
		}
	}
}

inline i64 *rec(int s, int lim, int cur_ma, int b, i64 n)
{
	int ds = s >> 2;
	i64 *ans = d[ds][cur_ma][b];
	if (ans[0] >= 0) return ans;

	forn(i, 16)
	{
		ans[i] = 0;
	}
	if (s < lim)
	{
		if (b) ans[cur_ma] = 1;
		return ans;
	}

	int ma = b ? 15 : ((n >> s) & 15);
	int mm = min(ma, cur_ma);
//	For(i, 0, mm - 1)
	if (mm > 0)
	{
		i64 *add = rec(s - 4, lim, cur_ma, 1, n);
		forn(j, 16)
		{
			ans[j] += add[j] * mm;
		}
	}
	For(i, mm, mm)
	{
		i64 *add = rec(s - 4, lim, cur_ma, b || i < ma, n);
		forn(j, 16)
		{
			ans[j] += add[j];
		}
	}
	For(i, mm + 1, ma)
	{
		i64 *add = rec(s - 4, lim, i, b || i < ma, n);
		forn(j, 16)
		{
			ans[j] += add[j];
		}
	}

	return ans;
}

void calc_d(i64 n)
{
	clr(d);
	{
		int s = 12;
		int ds = s >> 2;
		forn(cur_ma, 16)
		{
			forn(b, 2)
			{
				i64 *ans = d[ds][cur_ma][b];
				if (b) ans[cur_ma] = 1;
			}
		}
	}
	for (int s = 16; s <= 60; s += 4)
	{
		int ds = s >> 2;
		forn(cur_ma, 16)
		{
			forn(b, 2)
			{
				i64 *ans = d[ds][cur_ma][b];
				int ma = b ? 15 : ((n >> s) & 15);
				For(i, 0, ma)
				{
					i64 *add = d[(s - 4) >> 2][max(cur_ma, i)][b || i < ma];
					forn(j, 16)
					{
						ans[j] += add[j];
					}
				}
			}
		}
	}
}

i64 solve(i64 n)
{
	if (n <= 0) return 0;
	i64 ans = 0;

	int r = n & 0xffff;
	if (r >= 0x8000) n += 0x10000;
	memset(d, 0xff, sizeof(d));
//	calc_d(n);
	i64 *cma = rec(60, 16, 0, 0, n);
//	i64 *cma = d[60 >> 2][0][0];
	i64 sum = 0;
	forn(i, 16)
	{
		sum += cma[i];
		ans += t[i][i] * sum;
	}
	forn(i, 16)
	{
		i64 sum = 0;
		forn(j, i)
		{
			sum += t[j][i];
		}
		ans += cma[i] * sum;
	}

	if (r >= 0x8000) n -= 0x10000;
	int lma = 0;
	For(i, 4, 14)
	{
		int z = (n >> (i * 4)) & 15;
		lma = max(lma, z);
	}
	if (r >= 0x8000)
	{
		For(i, r + 1, 0xffff)
		{
			int z = max(dma[i], lma);
			ans -= (i >> z) & 1;
		}
	}
	else
	{
		For(i, 0, r)
		{
			int z = max(dma[i], lma);
			ans += (i >> z) & 1;
		}
	}

	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	precalc();
	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		i64 l, r;
		scanf("%llx%llx", &l, &r);
		i64 ans = solve(r) - solve(l - 1);
		printf("%lld\n", ans);
	}
	
	return 0;
}