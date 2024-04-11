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

int n, m;
bool a[512][512];
int u[512];
int pa[512];
VI c;

bool dfs(int v, bool cc)
{
	u[v] = 1;
	forn(i, n)
	{
		if (!a[v][i]) continue;
		if (u[i] == 2) continue;
		if (u[i] == 1)
		{
			if (cc)
			{
				int x = v;
				while (x != i)
				{
					c.pb(x);
					x = pa[x];
				}
				c.pb(x);
				reverse(all(c));
			}
			return true;
		}
		pa[i] = v;
		if (dfs(i, cc)) return true;
	}
	u[v] = 2;
	return false;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	clr(a);
	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x][y] = true;
	}
	clr(u);
	forn(i, n)
	{
		if (u[i]) continue;
		if (dfs(i, true))
		{
			forn(j, c.sz)
			{
				int x = c[j];
				int y = c[(j + 1) % c.sz];
				a[x][y] = false;
				clr(u);
				bool ok = true;
				forn(t, n)
				{
					if (u[t]) continue;
					if (dfs(t, false))
					{
						ok = false;
						break;
					}
				}
				if (ok)
				{
					puts("YES");
					return 0;
				}
				a[x][y] = true;
			}
			puts("NO");
			return 0;
		}
	}	
	puts("YES");
	return 0;
}