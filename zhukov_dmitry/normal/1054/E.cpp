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
deque<int> a[320][320];
int c0[320][320];
deque<int> b[320][320];
char s[102400];
int ans[102400 * 4][4];

inline void pa()
{
	return;
	forn(i, n)
	{
		forn(j, m)
		{
			forn(t, a[i][j].sz)
			{
				cerr << a[i][j][t];
			}
			cerr << " ";
		}
		cerr << endl;
	}
	cerr << endl;
}

void mv(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2) return;
	ans[k][0] = x1;
	ans[k][1] = y1;
	ans[k][2] = x2;
	ans[k][3] = y2;
	k++;
	assert(!a[x1][y1].empty());
	int c = a[x1][y1].back();
	a[x1][y1].pop_back();
	a[x2][y2].push_front(c);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	k = 0;
	scanf("%d%d", &n, &m);
	forn(i, n)
	{
		forn(j, m)
		{
			scanf("%s", s);
			int l = strlen(s);
			c0[i][j] = l;
			forn(t, l)
			{
				a[i][j].pb(s[t] - '0');
			}
		}
	}
	forn(i, n)
	{
		forn(j, m)
		{
			scanf("%s", s);
			int l = strlen(s);
			forn(t, l)
			{
				b[i][j].pb(s[t] - '0');
			}
		}
	}
	pa();

	forn(i, n)
	{
		forn(j, m)
		{
			forn(t, c0[i][j])
			{
				int c = a[i][j].back();
				if (c == 0)
				{
					if (i == 0)
					{
						mv(i, j, i, (j + 1) % m);
					}
					else
					{
						mv(i, j, 0, j);
					}
				}
				else // if (c == 1)
				{
					if (i == 1)
					{
						mv(i, j, i, (j + 1) % m);
					}
					else
					{
						mv(i, j, 1, j);
					}
				}
			}
		}
	}
	pa();

	forn(j, m)
	{
		if (j == 0) continue;
		while (!a[0][j].empty())
		{
			mv(0, j, 0, 0);
		}
	}
	forn(j, m)
	{
		if (j == 1) continue;
		while (!a[1][j].empty())
		{
			mv(1, j, 1, 1);
		}
	}
	pa();

	Ford(i, n - 1, 2)
	{
		ford(j, m)
		{
//			if (!i && !j) continue;
//			if (i == 1 && j == 1) continue;
			ford(t, b[i][j].sz)
			{
				int c = b[i][j][t];
				if (c == 0)
				{
					mv(0, 0, 0, j);
					mv(0, j, i, j);
				}
				else // if (c == 1)
				{
					mv(1, 1, 1, j);
					mv(1, j, i, j);
				}
			}
		}
	}
	ford(i, 2)
	{
		Ford(j, m - 1, 2)
		{
//			if (!i && !j) continue;
//			if (i == 1 && j == 1) continue;
			ford(t, b[i][j].sz)
			{
				int c = b[i][j][t];
				if (c == 0)
				{
					mv(0, 0, i, 0);
					mv(i, 0, i, j);
				}
				else // if (c == 1)
				{
					mv(1, 1, i, 1);
					mv(i, 1, i, j);
				}
			}
		}
	}
	pa();

	int need101 = 0;
	forn(t, b[0][0].sz)
	{
		need101 += b[0][0][t] == 1;
	}
	forn(t, b[1][1].sz)
	{
		need101 += b[1][1][t] == 1;
	}
	int need010 = 0;
	forn(t, b[0][0].sz)
	{
		need010 += b[0][0][t] == 0;
	}
	forn(t, b[1][1].sz)
	{
		need010 += b[1][1][t] == 0;
	}
	forn(t, need101)
	{
		mv(1, 1, 1, 0);
	}
	forn(t, need010)
	{
		mv(0, 0, 0, 1);
	}
	pa();

	forn(i, 2)
	{
		forn(j, 2)
		{
			ford(t, b[i][j].sz)
			{
				int c = b[i][j][t];
				if (c == 0)
				{
					int x = i, y = j;
					if (x) x = 0;
					else y ^= 1;
					mv(x, y, i, j);
				}
				else
				{
					int x = i, y = j;
					if (!x) x = 1;
					else y ^= 1;
					mv(x, y, i, j);
				}
				pa();
			}
		}
	}

	forn(i, n)
	{
		forn(j, m)
		{
			assert(a[i][j] == b[i][j]);
		}
	}

	printf("%d\n", k);
	forn(i, k)
	{
		forn(j, 4)
		{
			printf("%d%c", ans[i][j] + 1, " \n"[j == 3]);
		}
	}
	
	return 0;
}