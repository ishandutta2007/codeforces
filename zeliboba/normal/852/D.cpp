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
template <typename T> void my_random_shuffle(T b, T e) { for(ssize_t i = 1; i < (e - b); i++) { swap(b[i], b[rand() % (i + 1)]); } }
#define random_shuffle my_random_shuffle
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

const int MAXN = 1024;

int n, m, k, t;
bool a[MAXN][MAXN];
int d[MAXN][MAXN];
int c[MAXN];
bool u[MAXN];
int pa[MAXN];

bool find(int k)
{
	u[k] = true;
	forn(i, n)
	{
		if (a[k][i] && (pa[i] == -1 || (!u[pa[i]] && find(pa[i]))))
		{
			pa[i] = k;
			return true;
		}
	}
	return false;
}

int calc()
{
	memset(pa, 0xff, sizeof(pa));
	int ans = 0;
	clr(u);
	forn(i, n)
	{
		forn(j, c[i])
		{
			if (find(i))
			{
				ans++;
				clr(u);
			}
			else break;
		}
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	memset(d, 0x3f, sizeof(d));
	clr(c);
	scanf("%d%d%d%d", &n, &m, &t, &k);
	forn(i, t)
	{
		int x;
		scanf("%d", &x);
		x--;
		c[x]++;
	}
	forn(i, n)
	{
		d[i][i] = 0;
	}
	forn(i, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		d[x][y] = d[y][x] = min(d[x][y], z);
	}
	forn(k, n)
	{
		forn(i, n)
		{
			forn(j, n)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int mi = 0;
	int ma = 1731312;
	while (mi < ma)
	{
		int q = (mi + ma) / 2;
		forn(i, n)
		{
			forn(j, n)
			{
				a[i][j] = d[i][j] <= q;
			}
		}
		if (calc() >= k) ma = q;
		else mi = q + 1;
	}
	if (mi >= 1731312) puts("-1");
	else printf("%d\n", mi);
	
	return 0;
}