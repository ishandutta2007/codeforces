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
template <typename T> void my_random_shuffle(T *b, T *e) { For(i, 1, (int)(e - b) - 1) { swap(b[i], b[rand() % (i + 1)]); } }
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

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

const int MOD = 1000000007;

#define next my_next

int n;
char s[10240];
int a[10240];
int d[5024][5024];
int f[5024][5024];
//int sf[5024][5024];
int next[5024][26];

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

inline void sub(int &a, int b)
{
	a -= b;
	if (a < 0) a += MOD;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	scanf("%s", s);
/*	n = 5000;
	forn(i, n)
	{
		s[i] = 'a' + i % 26;
	}*/
	forn(i, n + 1)
	{
		forn(j, 26)
		{
			next[i][j] = n;
		}
	}
	forn(i, n)
	{
		a[i] = s[i] - 'a';
	}
	ford(i, n)
	{
		forn(j, 26)
		{
			if (a[i] == j) next[i][j] = i;
			else next[i][j] = next[i + 1][j];
		}
	}
	clr(f);
#define sf d
	clr(sf);
	For(i, 0, n)
	{
		f[i][i] = 1;
		if (i > 0)
		{
			For(j, i + 1, n)
			{
				f[i][j] = sf[i - 1][j];
			}
		}
		sf[i][0] = 0;
		For(j, 1, n)
		{
			sf[i][j] = sf[i][j - 1];
			add(sf[i][j], f[i][j - 1]);
		}
	}
	clr(d);
	For(i, 1, n)
	{
		if (i == 1)
		{
			int u = 0;
			forn(j, n)
			{
				if (u & (1 << a[j])) continue;
				u |= 1 << a[j];
				d[i][j] = 1;
			}
		}
		else
		{
			forn(j, n)
			{
				if (!d[i - 1][j]) continue;
				int x = d[i - 1][j];
				forn(t, 26)
				{
					if (t == a[j]) continue;
					int pos = next[j + 1][t];
					if (pos >= n) continue;
					add(d[i][pos], x);
				}
			}
		}
	}
/*	cerr << f[1][1] << endl;
	cerr << f[1][2] << endl;
	cerr << sf[1][1] << endl;
	cerr << sf[1][2] << endl;
	cerr << f[2][3] << endl;
	cerr << f[2][4] << endl;
	cerr << f[3][5] << endl;*/
	int ans = 0;
	For(i, 1, n)
	{
		forn(j, n)
		{
			if (d[i][j]) add(ans, d[i][j] * (i64)f[i][n] % MOD);
		}
	}
	printf("%d\n", ans);
	
	return 0;
}