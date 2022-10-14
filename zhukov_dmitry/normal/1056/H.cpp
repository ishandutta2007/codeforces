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

const int LIM = 60;

int n, m, qq;
VI a[302400];
int u[302400];
int tt;
int pos[302400];

unordered_map<int, i64> w[302400];
//map<int, i64> w[302400];

inline bool check1(int l, int r)
{
	int mi = n + 1;
	int prev = n + 1;
	for (int i : a[r])
	{
		if (u[i] < tt)
		{
			prev = n + 1;
		}
		else
		{
			int p = pos[i];
			if (p < mi)
			{
				mi = p;
				prev = mi;
			}
			else
			{
				prev++;
				if (prev != p) return true;
			}
		}
	}
	return false;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#define BIG 1
#endif
	
	clr(u);
	tt = 0;
#ifdef BIG
	qq = 1;
#else
	scanf("%d", &qq);
#endif
	while (qq--)
	{
#ifdef BIG
		n = 300000;
		m = 300000 / LIM;
#else
		scanf("%d%d", &n, &m);
#endif
		forn(i, m)
		{
			int k;
#ifdef BIG
			k = LIM + 1;
#else
			scanf("%d", &k);
#endif
			forn(j, k)
			{
				int x;
#ifdef BIG
				x = rand() % n + 1;
//				x = 1 + j;
#else
				scanf("%d", &x);
#endif
				x--;
				a[i].pb(x);
			}
		}
		
		forn(i, m)
		{
			if ((int)a[i].sz > LIM)
			{
				tt++;
				forn(j, a[i].sz)
				{
					pos[a[i][j]] = j;
					u[a[i][j]] = tt;
				}
				forn(j, m)
				{
					if (i == j) continue;
					if (j < i && (int)a[j].sz > LIM) continue;
					if (check1(i, j))
					{
						puts("Human");
#ifndef BIG
						goto l1;
#endif
					}
				}
			}
		}

		forn(i, m)
		{
			if ((int)a[i].sz <= LIM)
			{
				forn(l, a[i].sz - 1)
				{
					int ll = a[i][l];
					i64 h = 1;
					For(r, l + 1, a[i].sz - 1)
					{
						int rr = a[i][r];
						h = h * 17239311LL + rr;
						auto res = w[ll].emplace(rr, h);
						if (!res.second)
						{
							if (res.first->second != h)
							{
								puts("Human");
#ifndef BIG
								goto l1;
#endif
							}
						}
					}
				}
			}
		}

		puts("Robot");
l1:;
		forn(i, m)
		{
			a[i].clear();
		}
		forn(i, n)
		{
			w[i].clear();
		}
	}
	return 0;
}